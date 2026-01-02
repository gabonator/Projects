function init()
{
    headerSize = 0x0060;
    loadAddress = 0x01ed;
    endAddress = 0x1a6d;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x1fb7;
    sp = 0x0080;
    load("keen1.zip", "KEEN1.EXE", 100068);
    fixReloc(loadAddress);
}

function* start()
{
    yield* sub_1ed0();
}

function* sub_1ed0() // 01ed:0000 +entry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[dx] = 0x14f2;
    memoryASet16(cs, 0x0235, r16[dx]);
    r8[ah] = 0x30;
    interrupt(0x21);
    r16[bp] = memoryAGet16(ds, 0x0002);
    r16[bx] = memoryAGet16(ds, 0x002c);
    ds = r16[dx];
    memoryASet16(ds, 0x0090, r16[ax]);
    memoryASet16(ds, 0x008e, es);
    memoryASet16(ds, 0x008a, r16[bx]);
    memoryASet16(ds, 0x00a6, r16[bp]);
    yield* sub_2035();
    r16[di] = memoryAGet16(ds, 0x0088); es = memoryAGet16(ds, 0x008a);
    r16[ax] = r16[di];
    r16[bx] = r16[ax];
    r16[cx] = 0x7fff;
    flags.direction = 0;
  case 0x1f04:
    for (flags.zero = 0; r16[cx] != 0 && !flags.zero; --r16[cx]) scasb_inv_ESDI(r8[al]);
    if (!r16[cx])
        { pc = 0x1f69; break; }
    r16[bx]++;
    if (memoryAGet(es, r16[di]) != r8[al])
        { pc = 0x1f04; break; }
    r8[ch] |= 0x80;
    r16[cx] = -r16[cx];
    memoryASet16(ds, 0x0088, r16[cx]);
    r16[cx] = 0x0001;
    r16[bx] <<= r8[cl];
    r16[bx] += 0x0008;
    r16[bx] &= 0xfff8;
    memoryASet16(ds, 0x008c, r16[bx]);
    r16[dx] = ds;
    r16[bp] -= r16[dx];
    r16[di] = memoryAGet16(ds, 0x554c);
    if (r16[di] >= 0x0200)
        { pc = 0x1f3b; break; }
    r16[di] = 0x0200;
    memoryASet16(ds, 0x554c, r16[di]);
  case 0x1f3b:
    flags.carry = r16[di] + 0xac46 >= 0x10000;
    r16[di] += 0xac46;
    if (flags.carry)
        { pc = 0x1f69; break; }
    flags.carry = r16[di] + memoryAGet16(ds, 0x5544) >= 0x10000;
    r16[di] += memoryAGet16(ds, 0x5544);
    if (flags.carry)
        { pc = 0x1f69; break; }
    r8[cl] = 0x04;
    r16[di] >>= r8[cl];
    r16[di]++;
    if (r16[bp] < r16[di])
        { pc = 0x1f69; break; }
    if (!memoryAGet16(ds, 0x554c))
        { pc = 0x1f5e; break; }
    if (memoryAGet16(ds, 0x5544))
        { pc = 0x1f6c; break; }
  case 0x1f5e:
    r16[di] = 0x1000;
    if (r16[bp] > r16[di])
        { pc = 0x1f6c; break; }
    r16[di] = r16[bp];
    { pc = 0x1f6c; break; }
  case 0x1f69:
    { pc = 0x20f0; break; }
  case 0x1f6c:
    r16[bx] = r16[di];
    r16[bx] += r16[dx];
    memoryASet16(ds, 0x009e, r16[bx]);
    memoryASet16(ds, 0x00a2, r16[bx]);
    r16[ax] = memoryAGet16(ds, 0x008e);
    r16[bx] -= r16[ax];
    es = r16[ax];
    r8[ah] = 0x4a;
    push(r16[di]);
    interrupt(0x21);
    r16[di] = pop();
    r16[di] <<= r8[cl];
    flags.interrupts = 0;
    ss = r16[dx];
    sp = r16[di];
    flags.interrupts = 1;
    r16[ax] = 0;
    es = memoryAGet16(cs, 0x0235);
    r16[di] = 0x563e;
    r16[cx] = 0xac46;
    r16[cx] -= r16[di];
    flags.direction = 0;
    for (; r16[cx] != 0; --r16[cx]) stosb_ESDI(r8[al]);
    r8[ah] = 0x00;
    interrupt(0x1a);
    memoryASet16(ds, 0x0094, r16[dx]);
    memoryASet16(ds, 0x0096, r16[cx]);
    r16[bp] = 0;
    r16[ax] = 0x14f0;
    ds = r16[ax];
    r16[si] = 0x0000;
    r16[di] = 0x0012;
    yield* sub_20a5();
    ds = memoryAGet16(cs, 0x0235);
    push(memoryAGet16(ds, 0x0086));
    push(memoryAGet16(ds, 0x0084));
    push(memoryAGet16(ds, 0x0082));
    yield* sub_319f();
    memoryASet(cs, 0x01e7, 0x72);
    memoryASet(cs, 0x01d6, 0x00);
    push(r16[ax]);
    yield* sub_e4a7();
    r16[ax] = 0x14f1;
    ds = r16[ax];
    r16[si] = 0x0002;
    r16[di] = 0x0002;
    yield* sub_20a5();
    ds = memoryAGet16(cs, 0x0235);
    yield* indirectCall(cs, memoryAGet16(ds, 0x53d0));
    yield* indirectCall(cs, memoryAGet16(ds, 0x53d2));
    yield* indirectCall(cs, memoryAGet16(ds, 0x53d4));
    ds = memoryAGet16(cs, 0x0235);
    yield* sub_2078();
    r16[ax] = 0;
    r16[si] = r16[ax];
    r16[cx] = 0x002d;
  case 0x200d:
    flags.carry = r8[al] + memoryAGet(ds, r16[si]) >= 0x100;
    r8[al] += memoryAGet(ds, r16[si]);
    r8[ah] += (0x00 + flags.carry);
    r16[si]++;
    if (--r16[cx])
        { pc = 0x200d; break; }
    r16[ax] -= 0x0ca5;
    if (!r16[ax])
        { pc = 0x2023; break; }
    r16[cx] = 0x0019;
    r16[dx] = 0x002d;
    yield* sub_20e8();
  case 0x2023:
    r16[bp] = sp;
    r8[ah] = 0x4c;
    r8[al] = memoryAGet(ss, r16[bp] + 2);
    interrupt(0x21);
    stop("terminating");
    // gap 196 bytes
  case 0x20f0:
    r16[cx] = 0x001e;
    r16[dx] = 0x0054;
    ds = memoryAGet16(cs, 0x0235);
    yield* sub_20e8();
    r16[ax] = 0x0003;
    push(r16[ax]);
    yield* sub_1ffe();
    memoryASet(ds, r16[bx] + r16[si], memoryAGet(ds, r16[bx] + r16[si]) + r8[al]);
    memoryASet16(ds, r16[bx] + r16[si], memoryAGet16(ds, r16[bx] + r16[si]) + r16[ax]);
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0;
    memoryASet16(ds, 0x6ed8, r16[ax]);
    memoryASet16(ds, 0x6ecc, r16[ax]);
    memoryASet16(ds, 0x6ebe, r16[ax]);
    memoryASet16(ds, 0x6ec6, 0x604e);
    memoryASet16(ds, 0x6ece, 0x6c0a);
    memoryASet16(ds, 0x7fba, 0x6c64);
    memoryASet16(ds, 0x5db6, 0x5660);
  case 0x212f:
    memoryASet16(ds, 0x5135, memoryAGet16(ds, 0x5135)+1);
    r16[ax] = memoryAGet16(ds, 0x5135);
    r16[ax] -= memoryAGet16(ds, 0x563e);
    memoryASet16(ds, 0x5b14, r16[ax]);
    if (r16[ax] < 0x0006)
        { pc = 0x212f; break; }
    if (r16[ax] <= 0x000f)
        { pc = 0x2149; break; }
    memoryASet16(ds, 0x5b14, 0x000f);
  case 0x2149:
    r16[ax] = memoryAGet16(ds, 0x5137);
    r16[dx] = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, r16[dx]);
    memoryASet16(ds, 0x5640, r16[ax]);
    r16[bp] = pop();
    stop("stack_unbalanced");
    return;
  }
}
function* sub_1fdf() // 01ed:010f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[ax] = 0x14f1;
    ds = r16[ax];
    r16[si] = 0x0002;
    r16[di] = 0x0002;
    yield* sub_20a5();
    ds = memoryAGet16(cs, 0x0235);
    yield* indirectCall(cs, memoryAGet16(ds, 0x53d0));
    yield* indirectCall(cs, memoryAGet16(ds, 0x53d2));
    yield* indirectCall(cs, memoryAGet16(ds, 0x53d4));
    ds = memoryAGet16(cs, 0x0235);
    yield* sub_2078();
    r16[ax] = 0;
    r16[si] = r16[ax];
    r16[cx] = 0x002d;
  case 0x200d:
    flags.carry = r8[al] + memoryAGet(ds, r16[si]) >= 0x100;
    r8[al] += memoryAGet(ds, r16[si]);
    r8[ah] += (0x00 + flags.carry);
    r16[si]++;
    if (--r16[cx])
        { pc = 0x200d; break; }
    r16[ax] -= 0x0ca5;
    if (!r16[ax])
        { pc = 0x2023; break; }
    r16[cx] = 0x0019;
    r16[dx] = 0x002d;
    yield* sub_20e8();
  case 0x2023:
    r16[bp] = sp;
    r8[ah] = 0x4c;
    r8[al] = memoryAGet(ss, r16[bp] + 2);
    interrupt(0x21);
    stop("terminating");
    return;
  }
}
function* sub_1ffe() // 01ed:012e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    ds = memoryAGet16(cs, 0x0235);
    yield* sub_2078();
    r16[ax] = 0;
    r16[si] = r16[ax];
    r16[cx] = 0x002d;
  case 0x200d:
    flags.carry = r8[al] + memoryAGet(ds, r16[si]) >= 0x100;
    r8[al] += memoryAGet(ds, r16[si]);
    r8[ah] += (0x00 + flags.carry);
    r16[si]++;
    if (--r16[cx])
        { pc = 0x200d; break; }
    r16[ax] -= 0x0ca5;
    if (!r16[ax])
        { pc = 0x2023; break; }
    r16[cx] = 0x0019;
    r16[dx] = 0x002d;
    yield* sub_20e8();
  case 0x2023:
    r16[bp] = sp;
    r8[ah] = 0x4c;
    r8[al] = memoryAGet(ss, r16[bp] + 2);
    interrupt(0x21);
    stop("terminating");
    return;
  }
}
function* sub_202c() // 01ed:015c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[cx] = 0x000e;
    r16[dx] = 0x0046;
    { pc = 0x20f6; break; }
    // gap 193 bytes
  case 0x20f6:
    ds = memoryAGet16(cs, 0x0235);
    yield* sub_20e8();
    r16[ax] = 0x0003;
    push(r16[ax]);
    yield* sub_1ffe();
    memoryASet(ds, r16[bx] + r16[si], memoryAGet(ds, r16[bx] + r16[si]) + r8[al]);
    memoryASet16(ds, r16[bx] + r16[si], memoryAGet16(ds, r16[bx] + r16[si]) + r16[ax]);
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0;
    memoryASet16(ds, 0x6ed8, r16[ax]);
    memoryASet16(ds, 0x6ecc, r16[ax]);
    memoryASet16(ds, 0x6ebe, r16[ax]);
    memoryASet16(ds, 0x6ec6, 0x604e);
    memoryASet16(ds, 0x6ece, 0x6c0a);
    memoryASet16(ds, 0x7fba, 0x6c64);
    memoryASet16(ds, 0x5db6, 0x5660);
  case 0x212f:
    memoryASet16(ds, 0x5135, memoryAGet16(ds, 0x5135)+1);
    r16[ax] = memoryAGet16(ds, 0x5135);
    r16[ax] -= memoryAGet16(ds, 0x563e);
    memoryASet16(ds, 0x5b14, r16[ax]);
    if (r16[ax] < 0x0006)
        { pc = 0x212f; break; }
    if (r16[ax] <= 0x000f)
        { pc = 0x2149; break; }
    memoryASet16(ds, 0x5b14, 0x000f);
  case 0x2149:
    r16[ax] = memoryAGet16(ds, 0x5137);
    r16[dx] = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, r16[dx]);
    memoryASet16(ds, 0x5640, r16[ax]);
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_2035() // 01ed:0165
{
    sp -= 2;
    push(ds);
    r16[ax] = 0x3500;
    interrupt(0x21);
    memoryASet16(ds, 0x0072, r16[bx]);
    memoryASet16(ds, 0x0074, es);
    r16[ax] = 0x3504;
    interrupt(0x21);
    memoryASet16(ds, 0x0076, r16[bx]);
    memoryASet16(ds, 0x0078, es);
    r16[ax] = 0x3505;
    interrupt(0x21);
    memoryASet16(ds, 0x007a, r16[bx]);
    memoryASet16(ds, 0x007c, es);
    r16[ax] = 0x3506;
    interrupt(0x21);
    memoryASet16(ds, 0x007e, r16[bx]);
    memoryASet16(ds, 0x0080, es);
    r16[ax] = 0x2500;
    r16[dx] = cs;
    ds = r16[dx];
    r16[dx] = 0x015c;
    interrupt(0x21);
    ds = pop();
    sp += 2;
}
function* sub_2078() // 01ed:01a8
{
    sp -= 2;
    push(ds);
    r16[ax] = 0x2500;
    r16[dx] = memoryAGet16(ds, 0x0072); ds = memoryAGet16(ds, 0x0074);
    interrupt(0x21);
    ds = pop();
    push(ds);
    r16[ax] = 0x2504;
    r16[dx] = memoryAGet16(ds, 0x0076); ds = memoryAGet16(ds, 0x0078);
    interrupt(0x21);
    ds = pop();
    push(ds);
    r16[ax] = 0x2505;
    r16[dx] = memoryAGet16(ds, 0x007a); ds = memoryAGet16(ds, 0x007c);
    interrupt(0x21);
    ds = pop();
    push(ds);
    r16[ax] = 0x2506;
    r16[dx] = memoryAGet16(ds, 0x007e); ds = memoryAGet16(ds, 0x0080);
    interrupt(0x21);
    ds = pop();
    sp += 2;
}
function* sub_20a5() // 01ed:01d5
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
  case 0x20a5:
    r8[ah] = 0xff;
    r16[dx] = r16[di];
    r16[bx] = r16[si];
  case 0x20ab:
    if (r16[bx] == r16[di])
        { pc = 0x20c3; break; }
    if (memoryAGet(ds, r16[bx]) == 0xff)
        { pc = 0x20be; break; }
    if (memoryAGet(ds, r16[bx] + 1) > r8[ah])
        { pc = 0x20be; break; }
    r8[ah] = memoryAGet(ds, r16[bx] + 1);
    r16[dx] = r16[bx];
  case 0x20be:
    r16[bx] += 0x0006;
    { pc = 0x20ab; break; }
  case 0x20c3:
    if (r16[dx] == r16[di])
        { pc = 0x20e7; break; }
    r16[bx] = r16[dx];
    push(ds);
    es = pop();
    push(es);
    flags.zero = memoryAGet(ds, r16[bx]) == 0x00;
    memoryASet(ds, r16[bx], 0xff);
    ds = memoryAGet16(cs, 0x0235);
    if (flags.zero)
        { pc = 0x20e0; break; }
    push(cs); cs = memoryAGet16(es, r16[bx] + 4); indirectCall(cs, memoryAGet16(es, r16[bx] + 2)); assert(cs == 0x01ed); // 01ed:0209
    ds = pop();
    { pc = 0x20a5; break; }
  case 0x20e0:
    switch (memoryAGet16(es, r16[bx] + 2))
    {
        case 0xcbed: yield* sub_eabd(); break;
        case 0xd062: yield* sub_ef32(); break;
        case 0xe5a1: yield* sub_10471(); break;
        default:
            stop("ind 01ed:0210");
    }
    ds = pop();
    { pc = 0x20a5; break; }
  case 0x20e7:
    sp += 2; return;
    return;
  }
}
function* sub_20e8() // 01ed:0218
{
    sp -= 2;
    r8[ah] = 0x40;
    r16[bx] = 0x0002;
    interrupt(0x21);
    sp += 2;
}
function* sub_2109() // 01ed:0239
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0;
    memoryASet16(ds, 0x6ed8, r16[ax]);
    memoryASet16(ds, 0x6ecc, r16[ax]);
    memoryASet16(ds, 0x6ebe, r16[ax]);
    memoryASet16(ds, 0x6ec6, 0x604e);
    memoryASet16(ds, 0x6ece, 0x6c0a);
    memoryASet16(ds, 0x7fba, 0x6c64);
    memoryASet16(ds, 0x5db6, 0x5660);
  case 0x212f:
    memoryASet16(ds, 0x5135, memoryAGet16(ds, 0x5135)+1);
    r16[ax] = memoryAGet16(ds, 0x5135);
    r16[ax] -= memoryAGet16(ds, 0x563e);
    memoryASet16(ds, 0x5b14, r16[ax]);
    if (r16[ax] < 0x0006)
        { pc = 0x212f; break; }
    if (r16[ax] <= 0x000f)
        { pc = 0x2149; break; }
    memoryASet16(ds, 0x5b14, 0x000f);
  case 0x2149:
    r16[ax] = memoryAGet16(ds, 0x5137);
    r16[dx] = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, r16[dx]);
    memoryASet16(ds, 0x5640, r16[ax]);
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_2159() // 01ed:0289
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    yield* sub_d620();
    r16[si] = 0x5660;
    if (!memoryAGet16(ds, 0x5652))
        { pc = 0x218c; break; }
    { pc = 0x2178; break; }
  case 0x216c:
    r16[bx] = memoryAGet16(ds, r16[si]);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 23318, 0xffff);
    r16[si]++;
    r16[si]++;
  case 0x2178:
    if (r16[si] < memoryAGet16(ds, 0x5db6))
        { pc = 0x216c; break; }
    { pc = 0x2192; break; }
  case 0x2180:
    r16[bx] = memoryAGet16(ds, r16[si]);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 23992, 0xffff);
    r16[si]++;
    r16[si]++;
  case 0x218c:
    if (r16[si] < memoryAGet16(ds, 0x5db6))
        { pc = 0x2180; break; }
  case 0x2192:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_2195() // 01ed:02c5
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0012;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0;
    r16[dx] = 0x0100;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_ff73();
    push(r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x0100;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0x6ed2));
    push(memoryAGet16(ds, 0x6ed0));
    yield* sub_ff73();
    r16[ax] &= 0xfff0;
    r16[dx] = pop();
    r16[dx] -= r16[ax];
    memoryASet16(ss, r16[bp] - 10, r16[dx]);
    r16[ax] = 0;
    r16[dx] = 0x0100;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ss, r16[bp] + 10));
    push(memoryAGet16(ss, r16[bp] + 8));
    yield* sub_ff73();
    push(r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x0100;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0x6ed6));
    push(memoryAGet16(ds, 0x6ed4));
    yield* sub_ff73();
    r16[ax] &= 0xfff0;
    r16[dx] = pop();
    r16[dx] -= r16[ax];
    memoryASet16(ss, r16[bp] - 12, r16[dx]);
    if (signed16(memoryAGet16(ss, r16[bp] - 10)) < signed16(0xffe0))
        { pc = 0x220d; break; }
    if (r16s[dx] < signed16(0xffe0))
        { pc = 0x220d; break; }
    if (signed16(memoryAGet16(ss, r16[bp] - 10)) > signed16(0x0150))
        { pc = 0x220d; break; }
    if (r16s[dx] <= signed16(0x00c7))
        { pc = 0x2212; break; }
  case 0x220d:
    r16[ax] = 0;
    { pc = 0x23cb; break; }
  case 0x2212:
    r16[ax] = memoryAGet16(ss, r16[bp] + 12);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    r16[ax] &= 0x0007;
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[dx] = pop();
    r16[dx] += r16[ax];
    memoryASet16(ss, r16[bp] - 14, r16[dx]);
    r16[ax] = 0x8306;
    push(ds);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 14);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    push(r16[dx]);
    push(r16[ax]);
    r16[cx] = 0x0020;
    yield* sub_1016b();
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    r16[ax] += 0x0020;
    r16[bx] = 0x0008;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[ax] += 0xfffc;
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    if (r16s[ax] >= 0)
        { pc = 0x2276; break; }
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    { pc = 0x2281; break; }
  case 0x2276:
    if (signed16(memoryAGet16(ss, r16[bp] - 2)) <= signed16(0x0015))
        { pc = 0x2281; break; }
    r16[ax] = 0;
    { pc = 0x23cb; break; }
  case 0x2281:
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    r16[ax] += memoryAGet16(ds, 0x8306);
    r16[ax]--;
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    if (r16s[ax] <= signed16(0x0015))
        { pc = 0x229e; break; }
    memoryASet16(ss, r16[bp] - 4, 0x0015);
    { pc = 0x22a9; break; }
  case 0x229e:
    if (signed16(memoryAGet16(ss, r16[bp] - 4)) >= signed16(0x0000))
        { pc = 0x22a9; break; }
    r16[ax] = 0;
    { pc = 0x23cb; break; }
  case 0x22a9:
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    r16[bx] = 0x0010;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    if (r16s[ax] >= 0)
        { pc = 0x22c0; break; }
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    { pc = 0x22cb; break; }
  case 0x22c0:
    if (signed16(memoryAGet16(ss, r16[bp] - 6)) <= signed16(0x000e))
        { pc = 0x22cb; break; }
    r16[ax] = 0;
    { pc = 0x23cb; break; }
  case 0x22cb:
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    r16[ax] += memoryAGet16(ds, 0x8308);
    r16[ax]--;
    r16[bx] = 0x0010;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    if (r16s[ax] <= signed16(0x000d))
        { pc = 0x22e8; break; }
    memoryASet16(ss, r16[bp] - 8, 0x000d);
    { pc = 0x22f3; break; }
  case 0x22e8:
    if (signed16(memoryAGet16(ss, r16[bp] - 8)) >= signed16(0x0000))
        { pc = 0x22f3; break; }
    r16[ax] = 0;
    { pc = 0x23cb; break; }
  case 0x22f3:
    memoryASet16(ss, r16[bp] - 10, memoryAGet16(ss, r16[bp] - 10) + 0x0004);
    memoryASet16(ss, r16[bp] - 12, memoryAGet16(ss, r16[bp] - 12) + 0x0020);
    r16[di] = memoryAGet16(ss, r16[bp] - 6);
    { pc = 0x23a2; break; }
  case 0x2301:
    r16[si] = memoryAGet16(ss, r16[bp] - 2);
    { pc = 0x2399; break; }
  case 0x2307:
    r16[ax] = r16[di];
    r16[ax] += memoryAGet16(ds, 0x5b12);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = r16[si];
    r16[dx] += memoryAGet16(ds, 0x5656);
    r16[dx] += r16[ax];
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 16, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 16);
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 1390);
    memoryASet16(ss, r16[bp] - 18, r16[ax]);
    if (r16s[ax] < 0)
        { pc = 0x234d; break; }
    r16[ax] = r16[di];
    r16[dx] = 0x0015;
    imul16(r16[dx]);
    r16[ax] += r16[si];
    r16[bx] = memoryAGet16(ds, 0x5db6);
    memoryASet16(ds, r16[bx], r16[ax]);
    memoryASet16(ds, 0x5db6, memoryAGet16(ds, 0x5db6) + 0x0002);
    { pc = 0x2398; break; }
  case 0x234d:
    r16[ax] = r16[si];
    r16[ax] <<= 1;
    r16[ax] += 0x0004;
    r16[bx] = memoryAGet16(ds, 0x7fba);
    memoryASet16(ds, r16[bx], r16[ax]);
    r16[ax] = r16[di];
    r8[cl] = 0x04;
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0020;
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 16);
    memoryASet16(ds, r16[bx] + 4, r16[ax]);
    if (memoryAGet16(ss, r16[bp] - 18) != 0xfffe)
        { pc = 0x238f; break; }
    r16[ax] = memoryAGet16(ds, r16[bx] + 4);
    r16[ax] |= 0x8000;
    memoryASet16(ds, r16[bx] + 4, r16[ax]);
    r16[ax] = r16[di];
    r16[dx] = 0x0015;
    imul16(r16[dx]);
    r16[ax] += r16[si];
    r16[bx] = memoryAGet16(ds, 0x5db6);
    memoryASet16(ds, r16[bx], r16[ax]);
    memoryASet16(ds, 0x5db6, memoryAGet16(ds, 0x5db6) + 0x0002);
  case 0x238f:
    memoryASet16(ds, 0x6ed8, memoryAGet16(ds, 0x6ed8) + 1);
    memoryASet16(ds, 0x7fba, memoryAGet16(ds, 0x7fba) + 0x0006);
  case 0x2398:
    r16[si]++;
  case 0x2399:
    if (r16s[si] > signed16(memoryAGet16(ss, r16[bp] - 4)))
        { pc = 0x23a1; break; }
    { pc = 0x2307; break; }
  case 0x23a1:
    r16[di]++;
  case 0x23a2:
    if (r16s[di] > signed16(memoryAGet16(ss, r16[bp] - 8)))
        { pc = 0x23aa; break; }
    { pc = 0x2301; break; }
  case 0x23aa:
    r16[bx] = memoryAGet16(ds, 0x6ec6);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    memoryASet16(ds, r16[bx], r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 14);
    memoryASet16(ds, r16[bx] + 4, r16[ax]);
    memoryASet16(ds, 0x6ebe, memoryAGet16(ds, 0x6ebe) + 1);
    memoryASet16(ds, 0x6ec6, memoryAGet16(ds, 0x6ec6) + 0x0006);
    r16[ax] = 0x0001;
  case 0x23cb:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_23d1() // 01ed:0501
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000c;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0;
    r16[dx] = 0x0100;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_ff73();
    push(r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x0100;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0x6ed2));
    push(memoryAGet16(ds, 0x6ed0));
    yield* sub_ff73();
    r16[ax] &= 0xfff0;
    r16[dx] = pop();
    r16[dx] -= r16[ax];
    memoryASet16(ss, r16[bp] - 10, r16[dx]);
    r16[ax] = 0;
    r16[dx] = 0x0100;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ss, r16[bp] + 10));
    push(memoryAGet16(ss, r16[bp] + 8));
    yield* sub_ff73();
    push(r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x0100;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0x6ed6));
    push(memoryAGet16(ds, 0x6ed4));
    yield* sub_ff73();
    r16[ax] &= 0xfff0;
    r16[dx] = pop();
    r16[dx] -= r16[ax];
    memoryASet16(ss, r16[bp] - 12, r16[dx]);
    if (signed16(memoryAGet16(ss, r16[bp] - 10)) < signed16(0xffe0))
        { pc = 0x243c; break; }
    if (r16s[dx] >= signed16(0xffe0))
        { pc = 0x2441; break; }
  case 0x243c:
    r16[ax] = 0;
    { pc = 0x2535; break; }
  case 0x2441:
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    r16[ax] += 0x0020;
    r16[bx] = 0x0008;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[ax] += 0xfffc;
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    if (r16s[ax] >= 0)
        { pc = 0x2467; break; }
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    { pc = 0x2472; break; }
  case 0x2467:
    if (signed16(memoryAGet16(ss, r16[bp] - 2)) <= signed16(0x0015))
        { pc = 0x2472; break; }
    r16[ax] = 0;
    { pc = 0x2535; break; }
  case 0x2472:
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    r16[ax] += memoryAGet16(ds, 0x8306);
    r16[ax]--;
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    if (r16s[ax] <= signed16(0x0014))
        { pc = 0x248f; break; }
    memoryASet16(ss, r16[bp] - 4, 0x0014);
    { pc = 0x249a; break; }
  case 0x248f:
    if (signed16(memoryAGet16(ss, r16[bp] - 4)) >= signed16(0x0000))
        { pc = 0x249a; break; }
    r16[ax] = 0;
    { pc = 0x2535; break; }
  case 0x249a:
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    r16[bx] = 0x0010;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    if (r16s[ax] >= 0)
        { pc = 0x24b1; break; }
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    { pc = 0x24bb; break; }
  case 0x24b1:
    if (signed16(memoryAGet16(ss, r16[bp] - 6)) <= signed16(0x000d))
        { pc = 0x24bb; break; }
    r16[ax] = 0;
    { pc = 0x2535; break; }
  case 0x24bb:
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    r16[ax] += memoryAGet16(ds, 0x8308);
    r16[ax]--;
    r16[bx] = 0x0010;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    if (r16s[ax] <= signed16(0x000d))
        { pc = 0x24d8; break; }
    memoryASet16(ss, r16[bp] - 8, 0x000d);
    { pc = 0x24e2; break; }
  case 0x24d8:
    if (signed16(memoryAGet16(ss, r16[bp] - 8)) >= signed16(0x0000))
        { pc = 0x24e2; break; }
    r16[ax] = 0;
    { pc = 0x2535; break; }
  case 0x24e2:
    memoryASet16(ss, r16[bp] - 10, memoryAGet16(ss, r16[bp] - 10) + 0x0004);
    memoryASet16(ss, r16[bp] - 12, memoryAGet16(ss, r16[bp] - 12) + 0x0020);
    r16[di] = memoryAGet16(ss, r16[bp] - 6);
    { pc = 0x250f; break; }
  case 0x24ef:
    r16[si] = memoryAGet16(ss, r16[bp] - 2);
    { pc = 0x2509; break; }
  case 0x24f4:
    r16[ax] = r16[di];
    r16[dx] = 0x0015;
    imul16(r16[dx]);
    r16[ax] += r16[si];
    r16[bx] = memoryAGet16(ds, 0x5db6);
    memoryASet16(ds, r16[bx], r16[ax]);
    memoryASet16(ds, 0x5db6, memoryAGet16(ds, 0x5db6) + 0x0002);
    r16[si]++;
  case 0x2509:
    if (r16s[si] <= signed16(memoryAGet16(ss, r16[bp] - 4)))
        { pc = 0x24f4; break; }
    r16[di]++;
  case 0x250f:
    if (r16s[di] <= signed16(memoryAGet16(ss, r16[bp] - 8)))
        { pc = 0x24ef; break; }
    r16[bx] = memoryAGet16(ds, 0x7fba);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    memoryASet16(ds, r16[bx], r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 12);
    memoryASet16(ds, r16[bx] + 4, r16[ax]);
    memoryASet16(ds, 0x6ed8, memoryAGet16(ds, 0x6ed8) + 1);
    memoryASet16(ds, 0x7fba, memoryAGet16(ds, 0x7fba) + 0x0006);
    r16[ax] = 0x0001;
  case 0x2535:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_253b() // 01ed:066b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0016;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, 0x8304, r16[ax]);
    if (signed16(memoryAGet16(ss, r16[bp] + 4)) >= signed16(0x000a))
        { pc = 0x2565; break; }
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = r16[bp] - 10;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f25a();
    sp += 0x0006;
    r16[ax] = 0x1d4c;
    { pc = 0x2579; break; }
  case 0x2565:
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = r16[bp] - 10;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f25a();
    sp += 0x0006;
    r16[ax] = 0x1d53;
  case 0x2579:
    push(r16[ax]);
    r16[ax] = r16[bp] - 22;
    push(r16[ax]);
    yield* sub_f623();
    sp += 0x0004;
    r16[ax] = r16[bp] - 10;
    push(r16[ax]);
    r16[ax] = r16[bp] - 22;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    r16[ax] = 0x1d59;
    push(r16[ax]);
    r16[ax] = r16[bp] - 22;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = r16[bp] - 22;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    r16[ax] = 0x8000;
    push(r16[ax]);
    r16[ax] = r16[bp] - 22;
    push(r16[ax]);
    yield* sub_f36e();
    sp += 0x0004;
    r16[di] = r16[ax];
    push(r16[ax]);
    yield* sub_f02c();
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    push(r16[di]);
    yield* sub_e47b();
    sp++;
    sp++;
    r16[ax] = 0xffff;
    r16[ax] -= memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = memoryAGet16(ds, 0x6eca);
    r16[bx] = memoryAGet16(ds, 0x6ec8);
    r16[bx] += r16[ax];
    memoryASet16(ss, r16[bp] - 4, r16[bx]);
    memoryASet16(ss, r16[bp] - 2, r16[dx]);
    push(r16[dx]);
    push(memoryAGet16(ss, r16[bp] - 4));
    r16[ax] = r16[bp] - 22;
    push(r16[ax]);
    yield* sub_7b88();
    sp += 0x0006;
    push(memoryAGet16(ds, 0x6eca));
    push(memoryAGet16(ds, 0x6ec8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_9751();
    sp += 0x0008;
    r16[si] = 0;
    { pc = 0x262f; break; }
  case 0x2609:
    r16[bx] = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6eca);
    r16[ax] = memoryAGet16(es, r16[bx] + 14);
    imul16(r16[si]);
    r16[dx] = memoryAGet16(ds, 0x6eca);
    r16[bx] += r16[ax];
    r16[bx] += 0x0020;
    push(r16[dx]);
    push(r16[bx]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = pop();
    memoryASet16(ds, r16[bx] + 27720, r16[ax]);
    r16[ax] = pop();
    memoryASet16(ds, r16[bx] + 27722, r16[ax]);
    r16[si]++;
  case 0x262f:
    r16[bx] = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6eca);
    if (signed16(memoryAGet16(es, r16[bx] + 4)) > r16s[si])
        { pc = 0x2609; break; }
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ds, 0x6c08, r16[ax]);
    r16[ax] = memoryAGet16(es, r16[bx] + 2);
    memoryASet16(ds, 0x6c58, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6c08);
    r16[ax] <<= 1;
    memoryASet16(ds, 0x6c06, r16[ax]);
    r16[ax] += 0xffd6;
    memoryASet16(ds, 0x5654, r16[ax]);
    memoryASet16(ds, 0x564a, 0x2000);
    memoryASet16(ds, 0x564c, 0x0000);
    memoryASet16(ds, 0x564e, 0x2000);
    memoryASet16(ds, 0x5650, 0x0000);
    r16[ax] = memoryAGet16(es, r16[bx]);
    r16[ax] += 0xffea;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, 0x7fbe, r16[ax]);
    memoryASet16(ds, 0x7fc0, r16[dx]);
    r16[bx] = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6eca);
    r16[ax] = memoryAGet16(es, r16[bx]);
    r16[ax] += 0xfffe;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, 0x5642, r16[ax]);
    memoryASet16(ds, 0x5644, r16[dx]);
    r16[bx] = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6eca);
    r16[ax] = memoryAGet16(es, r16[bx] + 2);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, 0x5646, r16[ax]);
    memoryASet16(ds, 0x5648, r16[dx]);
    r16[bx] = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6eca);
    r16[ax] = memoryAGet16(es, r16[bx] + 2);
    r16[ax] += 0xfff1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    flags.carry = r16[ax] + 0x0800 >= 0x10000;
    r16[ax] += 0x0800;
    r16[dx] += (0x0000 + flags.carry);
    memoryASet16(ds, 0x7fc2, r16[ax]);
    memoryASet16(ds, 0x7fc4, r16[dx]);
    r16[bx] = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6eca);
    r16[ax] = memoryAGet16(es, r16[bx]);
    r16[ax] += 0xfffd;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, 0x5dac, r16[ax]);
    memoryASet16(ds, 0x5dae, r16[dx]);
    r16[bx] = memoryAGet16(ds, 0x6ec8); es = memoryAGet16(ds, 0x6eca);
    r16[ax] = memoryAGet16(es, r16[bx] + 2);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, 0x5db0, r16[ax]);
    memoryASet16(ds, 0x5db2, r16[dx]);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_26fb() // 01ed:082b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    yield* sub_7b0a();
    if (memoryAGet16(ds, 0x8304) != 0x005a)
        { pc = 0x273a; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x000c;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x1d5b;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    yield* sub_8138();
    push(r16[ax]);
    yield* sub_ec06();
    sp++;
    sp++;
    memoryASet(ds, 0xa6e2, r8[al]);
    if (r8[al] != 0x59)
        { pc = 0x2780; break; }
    r16[ax] = 0x1d67;
    push(r16[ax]);
    yield* sub_3131();
    sp++;
    sp++;
    { pc = 0x2780; break; }
  case 0x273a:
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x0014;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x1d68;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x1d7a;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    yield* sub_8138();
    push(r16[ax]);
    yield* sub_ec06();
    sp++;
    sp++;
    memoryASet(ds, 0xa6e2, r8[al]);
    if (r8[al] != 0x44)
        { pc = 0x2773; break; }
    r16[ax] = 0x1d83;
    push(r16[ax]);
    yield* sub_3131();
    sp++;
    sp++;
  case 0x2773:
    if (memoryAGet(ds, 0xa6e2) != 0x54)
        { pc = 0x2780; break; }
    memoryASet16(ds, 0x6ebc, 0x0001);
  case 0x2780:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_2853() // 01ed:0983
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000e;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ds, 0x6eca);
    r16[dx] = memoryAGet16(ds, 0x6ec8);
    r16[dx] += 0x8000;
    memoryASet16(ss, r16[bp] - 4, r16[dx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 4));
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_7b88();
    sp += 0x0006;
    push(memoryAGet16(ds, 0x6eca));
    push(memoryAGet16(ds, 0x6ec8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_e3e3();
    sp += 0x0008;
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[ax] += 0x0200;
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[ax] += 0x0200;
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    r16[ax] += 0x0200;
    memoryASet16(ss, r16[bp] - 14, r16[ax]);
    r16[di] = 0;
    r16[si] = 0x0004;
    r16[ax] = 0;
    r16[dx] = 0;
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    yield* sub_2109();
    yield* sub_2159();
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = 0x03ce;
    push(r16[ax]);
    yield* sub_f4e7();
    sp += 0x0004;
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    { pc = 0x2995; break; }
  case 0x28d8:
    r8[al] = 0x02;
    push(r16[ax]);
    r16[ax] = 0x03c4;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x01;
    push(r16[ax]);
    r16[ax] = 0x03c5;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r16[ax] = 0x0028;
    push(r16[ax]);
    push(r16[si]);
    push(memoryAGet16(ds, 0x35b4));
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] - 8));
    yield* sub_f321();
    sp += 0x000a;
    r8[al] = 0x02;
    push(r16[ax]);
    r16[ax] = 0x03c4;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x02;
    push(r16[ax]);
    r16[ax] = 0x03c5;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r16[ax] = 0x0028;
    push(r16[ax]);
    push(r16[si]);
    push(memoryAGet16(ds, 0x35b4));
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] - 10));
    yield* sub_f321();
    sp += 0x000a;
    r8[al] = 0x02;
    push(r16[ax]);
    r16[ax] = 0x03c4;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x04;
    push(r16[ax]);
    r16[ax] = 0x03c5;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r16[ax] = 0x0028;
    push(r16[ax]);
    push(r16[si]);
    push(memoryAGet16(ds, 0x35b4));
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] - 12));
    yield* sub_f321();
    sp += 0x000a;
    r8[al] = 0x02;
    push(r16[ax]);
    r16[ax] = 0x03c4;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x08;
    push(r16[ax]);
    r16[ax] = 0x03c5;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r16[ax] = 0x0028;
    push(r16[ax]);
    push(r16[si]);
    push(memoryAGet16(ds, 0x35b4));
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] - 14));
    yield* sub_f321();
    sp += 0x000a;
    r16[di] += 0x0028;
    r16[si] += 0x0030;
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + 1);
  case 0x2995:
    if (signed16(memoryAGet16(ss, r16[bp] - 6)) >= signed16(0x00c8))
        { pc = 0x299f; break; }
    { pc = 0x28d8; break; }
  case 0x299f:
    r8[al] = 0x02;
    push(r16[ax]);
    r16[ax] = 0x03c4;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x0f;
    push(r16[ax]);
    r16[ax] = 0x03c5;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    yield* sub_d606();
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_2b21() // 01ed:0c51
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    r16[si] = 0;
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    r16[ax] = 0x82ea;
    if (r16[ax])
        { pc = 0x2b3d; break; }
    { pc = 0x2c1b; break; }
  case 0x2b3d:
    r16[ax] = memoryAGet16(ds, 0x5137);
    r16[dx] = memoryAGet16(ds, 0x5135);
    memoryASet16(ss, r16[bp] - 4, r16[dx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x50ac);
    r16[ax] &= 0x007f;
    if (r16[ax] == 0x003d)
        { pc = 0x2bca; break; }
    if (r16s[ax] > signed16(0x003d))
        { pc = 0x2b6c; break; }
    if (r16[ax] != 0x0001)
        { pc = 0x2b5f; break; }
    { pc = 0x2bf1; break; }
  case 0x2b5f:
    if (r16[ax] == 0x003b)
        { pc = 0x2b79; break; }
    if (r16[ax] == 0x003c)
        { pc = 0x2b85; break; }
    { pc = 0x2bfa; break; }
  case 0x2b6c:
    if (r16[ax] == 0x003e)
        { pc = 0x2bd6; break; }
    if (r16[ax] == 0x003f)
        { pc = 0x2be8; break; }
    { pc = 0x2bfa; break; }
  case 0x2b79:
    yield* sub_de14();
    yield* sub_7b0a();
    yield* sub_bc84();
    r16[si]++;
    { pc = 0x2bfc; break; }
  case 0x2b85:
    yield* sub_de14();
    yield* sub_7b0a();
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x000d;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x1d91;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    yield* sub_8138();
    push(r16[ax]);
    yield* sub_ec06();
    sp++;
    sp++;
    memoryASet(ds, 0xa6e2, r8[al]);
    if (r8[al] != 0x4e)
        { pc = 0x2bba; break; }
    memoryASet16(ds, 0x5143, 0x0000);
    { pc = 0x2bc7; break; }
  case 0x2bba:
    if (memoryAGet(ds, 0xa6e2) != 0x59)
        { pc = 0x2bc7; break; }
    memoryASet16(ds, 0x5143, 0x0001);
  case 0x2bc7:
    r16[si]++;
    { pc = 0x2bfc; break; }
  case 0x2bca:
    yield* sub_de14();
    yield* sub_7b0a();
    yield* sub_7290();
    r16[si]++;
    { pc = 0x2bfc; break; }
  case 0x2bd6:
    yield* sub_de14();
    yield* sub_7b0a();
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_6e79();
    sp++;
    sp++;
    r16[si]++;
    { pc = 0x2bfc; break; }
  case 0x2be8:
    yield* sub_de14();
    yield* sub_b984();
    r16[si]++;
    { pc = 0x2bfc; break; }
  case 0x2bf1:
    yield* sub_de14();
    yield* sub_26fb();
    r16[si]++;
    { pc = 0x2bfc; break; }
  case 0x2bfa:
    { pc = 0x2c1b; break; }
  case 0x2bfc:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ds, 0x5135, r16[dx]);
    memoryASet16(ds, 0x5137, r16[ax]);
    if (!r16[si])
        { pc = 0x2c1b; break; }
    yield* sub_7b0a();
    yield* sub_de33();
    yield* sub_d606();
    r16[ax] = 0x0001;
    { pc = 0x2c1d; break; }
  case 0x2c1b:
    r16[ax] = 0;
  case 0x2c1d:
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_2c22() // 01ed:0d52
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xaaca) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0xaaca, memoryAGet16(ds, 0xaaca) + r16[ax]);
    memoryASet16(ds, 0xaacc, memoryAGet16(ds, 0xaacc) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0xaacc);
    r16[dx] = memoryAGet16(ds, 0xaaca);
    flags.carry = r16[dx] < memoryAGet16(ds, 0x6ec2);
    r16[dx] -= memoryAGet16(ds, 0x6ec2);
    r16[ax] -= memoryAGet16(ds, 0x6ec4) + flags.carry;
    if (r16s[ax] < 0)
        { pc = 0x2c7e; break; }
    if (r16[ax])
        { pc = 0x2c4c; break; }
    if (r16[dx] < 0x4e20)
        { pc = 0x2c7e; break; }
  case 0x2c4c:
    r16[ax] = 0x001c;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = 0;
    r16[dx] = 0x4e20;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xaacc));
    push(memoryAGet16(ds, 0xaaca));
    yield* sub_ff73();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = 0;
    r16[ax] = 0x4e20;
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_10433();
    memoryASet16(ds, 0x6ec2, r16[ax]);
    memoryASet16(ds, 0x6ec4, r16[dx]);
    memoryASet16(ds, 0xaac6, memoryAGet16(ds, 0xaac6) + 1);
  case 0x2c7e:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_2c80() // 01ed:0db0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    r16[ax] = memoryAGet16(ds, 0x5137);
    r16[dx] = memoryAGet16(ds, 0x5135);
    memoryASet16(ss, r16[bp] - 4, r16[dx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    yield* sub_7b0a();
    r16[ax] = 0x0004;
    push(r16[ax]);
    r16[ax] = 0x001a;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x1d9e;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x1db5;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x1dd1;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x1de9;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    memoryASet16(ds, 0xaa9a, 0x0001);
    memoryASet16(ds, 0xaac8, 0x0064);
    r16[si] = 0;
    { pc = 0x2ce4; break; }
  case 0x2cd9:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43678, 0x0001);
    r16[si]++;
  case 0x2ce4:
    if (r16s[si] < signed16(0x0004))
        { pc = 0x2cd9; break; }
    yield* sub_8138();
    yield* sub_d606();
    yield* sub_2159();
    yield* sub_2159();
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ds, 0x5135, r16[dx]);
    memoryASet16(ds, 0x5137, r16[ax]);
    yield* sub_7b0a();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_2d0a() // 01ed:0e3a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0006;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ds, 0x5137);
    r16[dx] = memoryAGet16(ds, 0x5135);
    memoryASet16(ss, r16[bp] - 6, r16[dx]);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    yield* sub_7b0a();
    r16[ax] = 0x000d;
    push(r16[ax]);
    r16[ax] = 0x001c;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[si] = memoryAGet16(ds, 0x8282);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = 0x1e02;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = r16[si];
    r16[ax] += 0x000c;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = 0x1e20;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x1e23;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = r16[si];
    r16[ax] += 0x000e;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = 0x1e41;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = r16[si];
    r16[ax] += 0x000e;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = 0x1e44;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = r16[si];
    r16[ax] += 0x000e;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = 0x1e47;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x1e4a;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = r16[si];
    r16[ax] += 0x0008;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = 0x1e68;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    r16[ax] = 0x1e6a;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = r16[si];
    r16[ax] += 0x0008;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = 0x1e6d;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    r16[ax] = 0x1e6f;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = r16[si];
    r16[ax] += 0x0008;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = 0x1e72;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    r16[ax] = 0x1e74;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x1e77;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    r16[ax] = 0x1e81;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = r16[si];
    r16[ax] += 0x0008;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = 0x1e84;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0006);
    r16[ax] = 0x1e86;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x1e89;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xaacc));
    push(memoryAGet16(ds, 0xaaca));
    yield* sub_f29b();
    sp += 0x0008;
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f647();
    sp++;
    sp++;
    r16[dx] = r16[si];
    r16[dx] += 0x000a;
    r16[dx] -= r16[ax];
    memoryASet16(ds, 0x8282, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax]++;
    memoryASet16(ds, 0x82f8, r16[ax]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ec4);
    r16[dx] = memoryAGet16(ds, 0x6ec2);
    flags.carry = r16[dx] + 0x4e20 >= 0x10000;
    r16[dx] += 0x4e20;
    r16[ax] += (0x0000 + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_f29b();
    sp += 0x0008;
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f647();
    sp++;
    sp++;
    r16[dx] = r16[si];
    r16[dx] += 0x001a;
    r16[dx] -= r16[ax];
    memoryASet16(ds, 0x8282, r16[dx]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[di] = 0;
    { pc = 0x2ecf; break; }
  case 0x2eae:
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] += 0x0003;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[dx] = r16[si];
    r16[dx] += r16[ax];
    r16[dx]++;
    push(r16[dx]);
    yield* sub_d9fd();
    sp += 0x0006;
    r16[di]++;
  case 0x2ecf:
    if (r16s[di] >= signed16(memoryAGet16(ds, 0xaac6)))
        { pc = 0x2eda; break; }
    if (r16s[di] < signed16(0x0006))
        { pc = 0x2eae; break; }
  case 0x2eda:
    r16[ax] = r16[si];
    r16[ax] += 0x0010;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] += 0x0003;
    memoryASet16(ds, 0x82f8, r16[ax]);
    if (!memoryAGet16(ds, 0xaa94))
        { pc = 0x2ef7; break; }
    r16[ax] = 0x01c0;
    { pc = 0x2efa; break; }
  case 0x2ef7:
    r16[ax] = 0x0141;
  case 0x2efa:
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0004;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d809();
    sp += 0x0006;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0003);
    if (!memoryAGet16(ds, 0xaa9c))
        { pc = 0x2f23; break; }
    r16[ax] = 0x01c1;
    { pc = 0x2f26; break; }
  case 0x2f23:
    r16[ax] = 0x0142;
  case 0x2f26:
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0004;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d809();
    sp += 0x0006;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0003);
    if (!memoryAGet16(ds, 0xaa96))
        { pc = 0x2f4f; break; }
    r16[ax] = 0x01c2;
    { pc = 0x2f52; break; }
  case 0x2f4f:
    r16[ax] = 0x0143;
  case 0x2f52:
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0004;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d809();
    sp += 0x0006;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 0x0003);
    if (!memoryAGet16(ds, 0xaa98))
        { pc = 0x2f7b; break; }
    r16[ax] = 0x01c3;
    { pc = 0x2f7e; break; }
  case 0x2f7b:
    r16[ax] = 0x0144;
  case 0x2f7e:
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0004;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d809();
    sp += 0x0006;
    r16[ax] = r16[si];
    r16[ax] += 0x0013;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] += 0x0007;
    memoryASet16(ds, 0x82f8, r16[ax]);
    if (!memoryAGet16(ds, 0xaa9e))
        { pc = 0x2fc9; break; }
    r16[ax] = 0x01a8;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0003;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d809();
    sp += 0x0006;
  case 0x2fc9:
    if (!memoryAGet16(ds, 0xaaa0))
        { pc = 0x2fee; break; }
    r16[ax] = 0x01a9;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0003;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    r16[ax] += 0x0004;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0x2fee:
    if (!memoryAGet16(ds, 0xaaa2))
        { pc = 0x3010; break; }
    r16[ax] = 0x01aa;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0015;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d809();
    sp += 0x0006;
  case 0x3010:
    if (!memoryAGet16(ds, 0xaaa4))
        { pc = 0x3035; break; }
    r16[ax] = 0x01ab;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0015;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    r16[ax] += 0x0004;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0x3035:
    r16[ax] = 0x019e;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] += 0x0007;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0004;
    push(r16[ax]);
    r16[ax] = r16[si];
    r16[ax] += 0x0003;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
    r16[ax] = r16[si];
    r16[ax] += 0x0003;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] += 0x000b;
    memoryASet16(ds, 0x82f8, r16[ax]);
    push(memoryAGet16(ds, 0xaac8));
    yield* sub_81fa();
    sp++;
    sp++;
    if (!memoryAGet16(ds, 0xaa9a))
        { pc = 0x3096; break; }
    r16[ax] = 0x019f;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] += 0x0008;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x0004;
    push(r16[ax]);
    r16[ax] = r16[si];
    r16[ax] += 0x000b;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0x3096:
    yield* sub_7b0a();
    r16[ax] = 0;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    yield* sub_d606();
    yield* sub_2159();
    yield* sub_2159();
    yield* sub_7b0a();
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r16[dx] = memoryAGet16(ss, r16[bp] - 6);
    memoryASet16(ds, 0x5135, r16[dx]);
    memoryASet16(ds, 0x5137, r16[ax]);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_30c0() // 01ed:11f0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    if (!memoryAGet(ds, 0x505a))
        { pc = 0x30db; break; }
    if (!memoryAGet(ds, 0x5040))
        { pc = 0x30db; break; }
    if (!memoryAGet(ds, 0x5065))
        { pc = 0x30db; break; }
    yield* sub_2c80();
  case 0x30db:
    if (!memoryAGet(ds, 0x504e))
        { pc = 0x311f; break; }
    if (!memoryAGet(ds, 0x5044))
        { pc = 0x311f; break; }
    if (!memoryAGet(ds, 0x504c))
        { pc = 0x311f; break; }
    yield* sub_7b0a();
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x0014;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    memoryASet16(ds, 0x5daa, memoryAGet16(ds, 0x5daa) ^ 0x0001);
    if (!memoryAGet16(ds, 0x5daa))
        { pc = 0x310e; break; }
    r16[ax] = 0x1ea6;
    { pc = 0x3111; break; }
  case 0x310e:
    r16[ax] = 0x1eb7;
  case 0x3111:
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    yield* sub_8138();
    yield* sub_d606();
    { pc = 0x312f; break; }
  case 0x311f:
    if (!memoryAGet(ds, 0x5065))
        { pc = 0x312f; break; }
    yield* sub_de14();
    yield* sub_2d0a();
    yield* sub_de33();
  case 0x312f:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_3131() // 01ed:1261
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = 0x0003;
    interrupt(0x10);
    r8[al] = memoryAGet(ds, r16[si]);
    cbw();
    if (r16[ax])
        { pc = 0x3149; break; }
    yield* sub_8679();
    { pc = 0x314f; break; }
  case 0x3149:
    push(r16[si]);
    yield* sub_ea7e();
    sp++;
    sp++;
  case 0x314f:
    if (!memoryAGet16(ds, 0x7fbc))
        { pc = 0x3159; break; }
    yield* sub_dc80();
  case 0x3159:
    if (!memoryAGet16(ds, 0x7fc6))
        { pc = 0x3163; break; }
    yield* sub_dd87();
  case 0x3163:
    r8[al] = memoryAGet(ds, r16[si]);
    cbw();
    if (r16[ax])
        { pc = 0x3186; break; }
    r16[ax] = 0x0fa0;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0xb800;
    push(r16[ax]);
    r16[ax] = 0x0000;
    r16[ax] += 0x0007;
    push(r16[ax]);
    r16[ax] = 0x13f5;
    push(r16[ax]);
    yield* sub_f321();
    sp += 0x000a;
  case 0x3186:
    r16[ax] = 0x0017;
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_e7b5();
    sp += 0x0004;
    r16[ax] = 0;
    push(r16[ax]);
    yield* sub_e4a7();
    sp++;
    sp++;
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_319f() // 01ed:12cf
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = 0x1ec9;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x2506));
    yield* sub_f623();
    sp += 0x0004;
    r16[ax] = 0x1ecd;
    push(r16[ax]);
    yield* sub_ea7e();
    sp++;
    sp++;
    r16[ax] = r16[bp] - 4;
    push(r16[ax]);
    r16[ax] = r16[bp] - 2;
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_76e1();
    sp += 0x0006;
    if (signed16(memoryAGet16(ss, r16[bp] - 2)) >= signed16(0x01f4))
        { pc = 0x31eb; break; }
    r16[ax] = 0x1f05;
    push(r16[ax]);
    yield* sub_ea7e();
    sp++;
    sp++;
    memoryASet16(ds, 0x5b10, 0x0001);
    { pc = 0x31fa; break; }
  case 0x31eb:
    r16[ax] = 0x1f17;
    push(r16[ax]);
    yield* sub_ea7e();
    sp++;
    sp++;
    memoryASet16(ds, 0x5b10, 0x0000);
  case 0x31fa:
    memoryASet16(ds, 0x5026, 0x0001);
    if (signed16(memoryAGet16(ss, r16[bp] + 4)) <= signed16(0x0001))
        { pc = 0x3227; break; }
    r16[bx] = memoryAGet16(ds, r16[di] + 2);
    if (memoryAGet(ds, r16[bx] + 1) == 0x4b)
        { pc = 0x3218; break; }
    r16[bx] = memoryAGet16(ds, r16[di] + 2);
    if (memoryAGet(ds, r16[bx] + 1) != 0x6b)
        { pc = 0x3227; break; }
  case 0x3218:
    memoryASet16(ds, 0x5026, 0x0000);
    r16[ax] = 0x1f2d;
    push(r16[ax]);
    yield* sub_ea7e();
    sp++;
    sp++;
  case 0x3227:
    yield* sub_e039();
    memoryASet16(ds, 0x9730, r16[ax]);
    if (r16[ax] != 0x0003)
        { pc = 0x323b; break; }
    r16[ax] = 0x1f53;
    push(r16[ax]);
    yield* sub_ea7e();
    { pc = 0x327f; break; }
  case 0x323b:
    if (memoryAGet16(ds, 0x9730) != 0x0005)
        { pc = 0x324b; break; }
    r16[ax] = 0x1f65;
    push(r16[ax]);
    yield* sub_ea7e();
    { pc = 0x327f; break; }
  case 0x324b:
    r16[ax] = 0x1f77;
    push(r16[ax]);
    yield* sub_ea7e();
    sp++;
    sp++;
    r16[ax] = 0x1fc2;
    push(r16[ax]);
    yield* sub_ea7e();
    sp++;
    sp++;
    yield* sub_7b0a();
    r16[ax] = 0;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    r16[ax] &= 0x00ff;
    push(r16[ax]);
    yield* sub_ec06();
    sp++;
    sp++;
    r16[si] = r16[ax];
    if (r16[ax] == 0x0059)
        { pc = 0x3281; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_e4a7();
  case 0x327f:
    sp++;
    sp++;
  case 0x3281:
    r16[ax] = 0x1feb;
    push(r16[ax]);
    yield* sub_ea7e();
    sp++;
    sp++;
    yield* sub_8bb6();
    r16[si] = 0;
    { pc = 0x341e; break; }
  case 0x3292:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 168);
    if (r16[ax] == 0x0001)
        { pc = 0x32af; break; }
    if (r16[ax] == 0x0002)
        { pc = 0x32d8; break; }
    if (r16[ax] != 0x0004)
        { pc = 0x32ac; break; }
    { pc = 0x3334; break; }
  case 0x32ac:
    { pc = 0x341d; break; }
  case 0x32af:
    r16[ax] = r16[si];
    r8[cl] = 0x05;
    r16[ax] <<= r8[cl];
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 19076, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 17676, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 16276, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 14876, r16[ax]);
    { pc = 0x341d; break; }
  case 0x32d8:
    r16[ax] = r16[si];
    r8[cl] = 0x05;
    r16[ax] <<= r8[cl];
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 17676, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 14876, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0020;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 19076, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 16276, r16[ax]);
    r16[si]++;
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 17676, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 14876, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0xffe0;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 19076, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 16276, r16[ax]);
    { pc = 0x341d; break; }
  case 0x3334:
    r16[ax] = r16[si];
    r8[cl] = 0x05;
    r16[ax] <<= r8[cl];
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 14876, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0020;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 16276, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0040;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 17676, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0060;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 19076, r16[ax]);
    r16[si]++;
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 14876, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0020;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 16276, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0040;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 17676, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0xffe0;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 19076, r16[ax]);
    r16[si]++;
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 14876, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0020;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 16276, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0xffc0;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 17676, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0xffe0;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 19076, r16[ax]);
    r16[si]++;
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 14876, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0xffa0;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 16276, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0xffc0;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 17676, r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= r8[cl];
    r16[ax] += 0xffe0;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 19076, r16[ax]);
  case 0x341d:
    r16[si]++;
  case 0x341e:
    if (r16s[si] >= signed16(memoryAGet16(ds, 0x8352)))
        { pc = 0x3427; break; }
    { pc = 0x3292; break; }
  case 0x3427:
    r16[ax] = 0x201e;
    push(r16[ax]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0x513f, r16[ax]);
    memoryASet16(ds, 0x5141, r16[dx]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_df7c();
    sp++;
    sp++;
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dee3();
    sp++;
    sp++;
    yield* sub_dd35();
    memoryASet16(ds, 0x7fc6, 0x0001);
    yield* sub_dc65();
    memoryASet16(ds, 0x7fbc, 0x0001);
    yield* sub_852d();
    memoryASet16(ds, 0x833e, 0x0000);
    r16[ax] = 0x0001;
    r16[dx] = 0;
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_7b28();
    sp += 0x0004;
    memoryASet16(ds, 0x6ec8, r16[ax]);
    memoryASet16(ds, 0x6eca, r16[dx]);
    memoryASet16(ds, 0x24ce, 0x0017);
    memoryASet16(ds, 0x6c62, 0x0007);
    r16[ax] = 0;
    r16[dx] = 0;
    memoryASet16(ds, 0x563e, r16[dx]);
    memoryASet16(ds, 0x5640, r16[ax]);
    memoryASet16(ds, 0x5135, r16[dx]);
    memoryASet16(ds, 0x5137, r16[ax]);
    yield* sub_97e3();
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_34bb() // 01ed:15eb
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_253b();
    sp++;
    sp++;
    r16[di] = 0;
    { pc = 0x35ca; break; }
  case 0x34cf:
    r16[si] = 0;
    { pc = 0x35c0; break; }
  case 0x34d4:
    r16[ax] = r16[di];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[si];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    if (r16[bx] == 0x0006)
        { pc = 0x355a; break; }
    if (r16s[bx] > signed16(0x0006))
        { pc = 0x3504; break; }
    r16[bx]--;
    if (r16[bx] <= 0x0004)
        { pc = 0x34fd; break; }
    { pc = 0x35bf; break; }
  case 0x34fd:
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x3526; break; }
        case 2: { pc = 0x3531; break; }
        case 4: { pc = 0x353c; break; }
        case 6: { pc = 0x3546; break; }
        case 8: { pc = 0x3550; break; }
        default:
            stop("ind 01ed:162f");
    }
    break;
  case 0x3504:
    if (r16[bx] == 0x0009)
        { pc = 0x3583; break; }
    if (r16s[bx] > signed16(0x0009))
        { pc = 0x3518; break; }
    if (r16[bx] == 0x0007)
        { pc = 0x3567; break; }
    if (r16[bx] == 0x0008)
        { pc = 0x3575; break; }
    { pc = 0x35bf; break; }
  case 0x3518:
    if (r16[bx] == 0x000a)
        { pc = 0x3591; break; }
    if (r16[bx] == 0x00ff)
        { pc = 0x359b; break; }
    { pc = 0x35bf; break; }
  case 0x3526:
    push(r16[di]);
    push(r16[si]);
    yield* sub_3750();
    sp += 0x0004;
    { pc = 0x35bf; break; }
  case 0x3531:
    push(r16[di]);
    push(r16[si]);
    yield* sub_3713();
    sp += 0x0004;
    { pc = 0x35bf; break; }
  case 0x353c:
    push(r16[di]);
    push(r16[si]);
    yield* sub_36a5();
    sp += 0x0004;
    { pc = 0x35bf; break; }
  case 0x3546:
    push(r16[di]);
    push(r16[si]);
    yield* sub_3647();
    sp += 0x0004;
    { pc = 0x35bf; break; }
  case 0x3550:
    push(r16[di]);
    push(r16[si]);
    yield* sub_35e3();
    sp += 0x0004;
    { pc = 0x35bf; break; }
  case 0x355a:
    r16[ax] = 0;
    push(r16[ax]);
    push(r16[di]);
    push(r16[si]);
    yield* sub_37f0();
    sp += 0x0006;
    { pc = 0x35bf; break; }
  case 0x3567:
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(r16[di]);
    push(r16[si]);
    yield* sub_37f0();
    sp += 0x0006;
    { pc = 0x35bf; break; }
  case 0x3575:
    r16[ax] = 0x0002;
    push(r16[ax]);
    push(r16[di]);
    push(r16[si]);
    yield* sub_37f0();
    sp += 0x0006;
    { pc = 0x35bf; break; }
  case 0x3583:
    r16[ax] = 0x0003;
    push(r16[ax]);
    push(r16[di]);
    push(r16[si]);
    yield* sub_37f0();
    sp += 0x0006;
    { pc = 0x35bf; break; }
  case 0x3591:
    push(r16[di]);
    push(r16[si]);
    yield* sub_37b3();
    sp += 0x0004;
    { pc = 0x35bf; break; }
  case 0x359b:
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, 0x6ede, r16[ax]);
    memoryASet16(ds, 0x6ee0, r16[dx]);
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    flags.carry = r16[ax] + 0x0800 >= 0x10000;
    r16[ax] += 0x0800;
    r16[dx] += (0x0000 + flags.carry);
    memoryASet16(ds, 0x6ee2, r16[ax]);
    memoryASet16(ds, 0x6ee4, r16[dx]);
  case 0x35bf:
    r16[si]++;
  case 0x35c0:
    if (r16s[si] >= signed16(memoryAGet16(ds, 0x6c08)))
        { pc = 0x35c9; break; }
    { pc = 0x34d4; break; }
  case 0x35c9:
    r16[di]++;
  case 0x35ca:
    if (r16s[di] >= signed16(memoryAGet16(ds, 0x6c58)))
        { pc = 0x35d3; break; }
    { pc = 0x34cf; break; }
  case 0x35d3:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_35e3() // 01ed:1713
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    yield* sub_4805();
    r16[si] = r16[ax];
    memoryASet16(ds, r16[si], 0x0006);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 6, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    flags.carry = r16[ax] + 0x0800 >= 0x10000;
    r16[ax] += 0x0800;
    r16[dx] += (0x0000 + flags.carry);
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si] + 10, r16[dx]);
    memoryASet16(ds, r16[si] + 32, 0x005a);
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x3635; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x362d; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x6ede))
        { pc = 0x3635; break; }
  case 0x362d:
    r16[ax] = memoryAGet16(ds, r16[si] + 32);
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si] + 32, r16[ax]);
  case 0x3635:
    memoryASet16(ds, r16[si] + 50, 0x1f75);
    memoryASet16(ds, r16[si] + 52, 0x2045);
    memoryASet16(ds, r16[si] + 40, 0x006a);
    r16[si] = pop();
    stop("stack_below");
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_3647() // 01ed:1777
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    yield* sub_4805();
    r16[si] = r16[ax];
    memoryASet16(ds, r16[si], 0x0005);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 6, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si] + 10, r16[dx]);
    memoryASet16(ds, r16[si] + 32, 0x005a);
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x3693; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x368b; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x6ede))
        { pc = 0x3693; break; }
  case 0x368b:
    r16[ax] = memoryAGet16(ds, r16[si] + 32);
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si] + 32, r16[ax]);
  case 0x3693:
    memoryASet16(ds, r16[si] + 50, 0x1dc7);
    memoryASet16(ds, r16[si] + 52, 0x1e94);
    memoryASet16(ds, r16[si] + 40, 0x0060);
    r16[si] = pop();
    stop("stack_below");
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_36a5() // 01ed:17d5
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    yield* sub_4805();
    r16[si] = r16[ax];
    memoryASet16(ds, r16[si], 0x0004);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 6, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si] + 10, r16[dx]);
    memoryASet16(ds, r16[si] + 50, 0x1c0e);
    memoryASet16(ds, r16[si] + 52, 0x1d6e);
    memoryASet16(ds, r16[si] + 36, 0x0003);
    if (memoryAGet16(ds, 0x8304) != 0x0010)
        { pc = 0x36eb; break; }
    memoryASet16(ds, r16[si] + 36, 0x0068);
  case 0x36eb:
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x3706; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x36ff; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x6ede))
        { pc = 0x3706; break; }
  case 0x36ff:
    memoryASet16(ds, r16[si] + 32, 0xffa6);
    { pc = 0x370b; break; }
  case 0x3706:
    memoryASet16(ds, r16[si] + 32, 0x005a);
  case 0x370b:
    memoryASet16(ds, r16[si] + 40, 0x004e);
    r16[si] = pop();
    stop("stack_below");
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_3713() // 01ed:1843
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    yield* sub_4805();
    r16[si] = r16[ax];
    memoryASet16(ds, r16[si], 0x0003);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 6, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si] + 10, r16[dx]);
    memoryASet16(ds, r16[si] + 50, 0x1b51);
    memoryASet16(ds, r16[si] + 52, 0x1bce);
    memoryASet16(ds, r16[si] + 40, 0x003c);
    r16[si] = pop();
    stop("stack_below");
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
}
function* sub_3750() // 01ed:1880
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    yield* sub_4805();
    r16[si] = r16[ax];
    memoryASet16(ds, r16[si], 0x0002);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 6, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    flags.carry = r16[ax] + 0x0800 >= 0x10000;
    r16[ax] += 0x0800;
    r16[dx] += (0x0000 + flags.carry);
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si] + 10, r16[dx]);
    memoryASet16(ds, r16[si] + 50, 0x194f);
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x37a1; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x379a; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x6ede))
        { pc = 0x37a1; break; }
  case 0x379a:
    memoryASet16(ds, r16[si] + 32, 0x003c);
    { pc = 0x37a6; break; }
  case 0x37a1:
    memoryASet16(ds, r16[si] + 32, 0xffc4);
  case 0x37a6:
    memoryASet16(ds, r16[si] + 52, 0x1a68);
    memoryASet16(ds, r16[si] + 40, 0x0030);
    r16[si] = pop();
    stop("stack_below");
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_37b3() // 01ed:18e3
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    yield* sub_4805();
    r16[si] = r16[ax];
    memoryASet16(ds, r16[si], 0x0008);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 6, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si] + 10, r16[dx]);
    memoryASet16(ds, r16[si] + 50, 0x3360);
    memoryASet16(ds, r16[si] + 52, 0x22bb);
    memoryASet16(ds, r16[si] + 40, 0x0072);
    r16[si] = pop();
    stop("stack_below");
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
}
function* sub_37f0() // 01ed:1920
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    yield* sub_484e();
    r16[si] = r16[ax];
    memoryASet16(ds, r16[si] + 8, 0x0003);
    memoryASet16(ds, r16[si] + 34, 0x204a);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ds, r16[si] + 10, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, r16[si], r16[ax]);
    memoryASet16(ds, r16[si] + 2, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 6, r16[dx]);
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
}
function* sub_381f() // 01ed:194f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    if (memoryAGet16(ds, 0x8242))
        { pc = 0x3858; break; }
    yield* sub_df9e();
    if (r16[ax] >= memoryAGet16(ds, 0x5b14))
        { pc = 0x3843; break; }
    r16[ax] = 0x0080;
    push(r16[ax]);
    yield* sub_df2c();
    sp++;
    sp++;
    r16[ax] = -r16[ax];
    memoryASet16(ds, 0x8242, r16[ax]);
    { pc = 0x3858; break; }
  case 0x3843:
    yield* sub_df9e();
    if (r16[ax] >= memoryAGet16(ds, 0x5b14))
        { pc = 0x3858; break; }
    memoryASet16(ds, 0x8252, 0x19d3);
    memoryASet16(ds, 0x824a, 0x0000);
  case 0x3858:
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x3867; break; }
    memoryASet16(ds, 0x8248, 0x0034);
    { pc = 0x386d; break; }
  case 0x3867:
    memoryASet16(ds, 0x8248, 0x0036);
  case 0x386d:
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[ax] &= 0x0001;
    r16[dx] = memoryAGet16(ds, 0x8248);
    r16[dx] += r16[ax];
    memoryASet16(ds, 0x8248, r16[dx]);
    yield* sub_4afa();
    yield* sub_4b3d();
    r16[si] = r16[ax];
    if (!(r16[ax] & 0x0004))
        { pc = 0x3894; break; }
    memoryASet16(ds, 0x8240, 0xffc4);
  case 0x3894:
    if (!(r16[si] & 0x0001))
        { pc = 0x38a0; break; }
    memoryASet16(ds, 0x8240, 0x003c);
  case 0x38a0:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_38a3() // 01ed:19d3
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    memoryASet16(ds, 0x8240, 0x0000);
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x05;
    r16[ax] >>= r8[cl];
    r16[ax] &= 0x0003;
    r16[ax] += 0x0030;
    memoryASet16(ds, 0x8248, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x824a);
    r16[ax] += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, r16[ax]);
    if (r16s[ax] < signed16(0x00c8))
        { pc = 0x38f4; break; }
    r16[ax] = memoryAGet16(ds, 0x8226);
    r16[dx] = memoryAGet16(ds, 0x8224);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x38e8; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x6ee0)))
        { pc = 0x38e0; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x6ede))
        { pc = 0x38e8; break; }
  case 0x38e0:
    memoryASet16(ds, 0x8240, 0x003c);
    { pc = 0x38ee; break; }
  case 0x38e8:
    memoryASet16(ds, 0x8240, 0xffc4);
  case 0x38ee:
    memoryASet16(ds, 0x8252, 0x194f);
  case 0x38f4:
    yield* sub_4afa();
    yield* sub_4b3d();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_38fc() // 01ed:1a2c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[ax] &= 0x0001;
    r16[ax] += 0x0038;
    memoryASet16(ds, 0x8248, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x824a);
    r16[ax] += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, r16[ax]);
    if (r16s[ax] < signed16(0x0320))
        { pc = 0x392a; break; }
    memoryASet16(ds, 0x824a, 0x0000);
    memoryASet16(ds, 0x8252, 0x19d3);
  case 0x392a:
    memoryASet16(ds, 0x8240, 0x0000);
    yield* sub_4afa();
    yield* sub_4b3d();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_3938() // 01ed:1a68
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    if (memoryAGet16(ds, r16[di]) == 0x000a)
        { pc = 0x394d; break; }
    if (memoryAGet16(ds, r16[di]) != 0x000b)
        { pc = 0x3974; break; }
  case 0x394d:
    memoryASet16(ds, r16[si] + 42, 0x0000);
    memoryASet16(ds, r16[si] + 44, 0x0002);
    memoryASet16(ds, r16[si] + 40, 0x003a);
    memoryASet16(ds, r16[si] + 50, 0x489d);
    memoryASet16(ds, r16[si] + 52, 0x3360);
    memoryASet16(ds, r16[si] + 34, 0xffb0);
    r16[ax] = 0x0022;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x3974:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_3a9e() // 01ed:1bce
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    if (memoryAGet16(ds, r16[di]) == 0x000a)
        { pc = 0x3ab3; break; }
    if (memoryAGet16(ds, r16[di]) != 0x000b)
        { pc = 0x3ada; break; }
  case 0x3ab3:
    memoryASet16(ds, r16[si] + 42, 0x0000);
    memoryASet16(ds, r16[si] + 44, 0x0002);
    memoryASet16(ds, r16[si] + 40, 0x0044);
    memoryASet16(ds, r16[si] + 50, 0x489d);
    memoryASet16(ds, r16[si] + 52, 0x3360);
    memoryASet16(ds, r16[si] + 34, 0xffb0);
    r16[ax] = 0x0023;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x3ada:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_3c3e() // 01ed:1d6e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    if (memoryAGet16(ds, r16[bx]) == 0x000a)
        { pc = 0x3c53; break; }
    if (memoryAGet16(ds, r16[bx]) != 0x000b)
        { pc = 0x3c93; break; }
  case 0x3c53:
    r16[ax] = memoryAGet16(ds, r16[si] + 36);
    memoryASet16(ds, r16[si] + 36, memoryAGet16(ds, r16[si] + 36) - 1);
    if (r16[ax])
        { pc = 0x3c93; break; }
    r16[ax] = 0x0027;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, r16[si] + 42, 0x0000);
    memoryASet16(ds, r16[si] + 44, 0x0006);
    memoryASet16(ds, r16[si] + 40, 0x0052);
    memoryASet16(ds, r16[si] + 52, 0x3360);
    memoryASet16(ds, r16[si] + 50, 0x489d);
    yield* sub_484e();
    r16[di] = r16[ax];
    memoryASet16(ds, r16[di] + 8, 0x0005);
    memoryASet16(ds, r16[di] + 34, 0x4a45);
    memoryASet16(ds, r16[di] + 10, 0x0000);
  case 0x3c93:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_3d64() // 01ed:1e94
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    if (memoryAGet16(ds, r16[bx]) != 0x000a)
        { pc = 0x3d77; break; }
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, r16[bx] + 42, 0x0000);
  case 0x3d77:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_418b() // 01ed:22bb
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    if (memoryAGet16(ds, r16[bx]) == 0x000a)
        { pc = 0x419e; break; }
    { pc = 0x4235; break; }
  case 0x419e:
    memoryASet16(ds, r16[si] + 50, 0x47e8);
    memoryASet16(ds, r16[si] + 42, 0x0000);
    memoryASet16(ds, r16[si] + 52, 0x3360);
    yield* sub_df9e();
    if (r16s[ax] <= signed16(0x0080))
        { pc = 0x41bc; break; }
    memoryASet16(ds, r16[si] + 40, 0x006e);
    { pc = 0x41c1; break; }
  case 0x41bc:
    memoryASet16(ds, r16[si] + 40, 0x006f);
  case 0x41c1:
    yield* sub_484e();
    r16[di] = r16[ax];
    memoryASet16(ds, r16[di] + 8, 0x0004);
    memoryASet16(ds, r16[di] + 34, 0x2369);
    r16[dx] = memoryAGet16(ds, r16[si] + 6);
    r16[ax] = memoryAGet16(ds, r16[si] + 4);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ds, r16[di], r16[ax]);
    memoryASet16(ds, r16[di] + 2, r16[dx]);
    r16[dx] = memoryAGet16(ds, r16[si] + 10);
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    r8[cl] = 0x0c;
    yield* sub_10042();
    flags.carry = r16[ax] + 0x0001 >= 0x10000;
    r16[ax]++;
    r16[dx] += (0x0000 + flags.carry);
    memoryASet16(ds, r16[di] + 4, r16[ax]);
    memoryASet16(ds, r16[di] + 6, r16[dx]);
    memoryASet16(ds, r16[di] + 10, 0x0000);
    r16[ax] = memoryAGet16(ds, 0x5db4);
    r16[dx] = 0x0036;
    imul16(r16[dx]);
    r16[ax] += 0x6eda;
    r16[si] = r16[ax];
    { pc = 0x420e; break; }
  case 0x420b:
    r16[si] -= 0x0036;
  case 0x420e:
    if (memoryAGet16(ds, r16[si]) != 0x0004)
        { pc = 0x420b; break; }
    r16[ax] = 0x0027;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, r16[si] + 42, 0x0000);
    memoryASet16(ds, r16[si] + 44, 0x0006);
    memoryASet16(ds, r16[si] + 40, 0x0052);
    memoryASet16(ds, r16[si] + 52, 0x3360);
    memoryASet16(ds, r16[si] + 50, 0x489d);
  case 0x4235:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_43c4() // 01ed:24f4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    r16[ax] = memoryAGet16(ds, 0x5137);
    r16[dx] = memoryAGet16(ds, 0x5135);
    memoryASet16(ss, r16[bp] - 4, r16[dx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = 0x0015;
    push(r16[ax]);
    yield* sub_7f1e();
    sp += 0x0004;
    r16[bx] = memoryAGet16(ds, 0x8304);
    r16[bx]--;
    r16[bx]--;
    if (r16[bx] <= 0x000d)
        { pc = 0x43f3; break; }
    { pc = 0x457b; break; }
  case 0x43f3:
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x43fa; break; }
        case 2: { pc = 0x457b; break; }
        case 4: { pc = 0x457b; break; }
        case 6: { pc = 0x457b; break; }
        case 8: { pc = 0x4436; break; }
        case 10: { pc = 0x457b; break; }
        case 12: { pc = 0x457b; break; }
        case 14: { pc = 0x4472; break; }
        case 16: { pc = 0x44ae; break; }
        case 18: { pc = 0x44ea; break; }
        case 20: { pc = 0x450a; break; }
        case 22: { pc = 0x457b; break; }
        case 24: { pc = 0x457b; break; }
        case 26: { pc = 0x4545; break; }
        default:
            stop("ind 01ed:2525");
    }
    break;
  case 0x43fa:
    r16[ax] = 0x2030;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2046;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x205c;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2072;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2088;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x209e;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x20b4;
    { pc = 0x4575; break; }
  case 0x4436:
    r16[ax] = 0x20ca;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x20e0;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x20f6;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x210c;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2122;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2138;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x214e;
    { pc = 0x4575; break; }
  case 0x4472:
    r16[ax] = 0x2164;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x217a;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2190;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x21a6;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x21bc;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x21d2;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x21e8;
    { pc = 0x4575; break; }
  case 0x44ae:
    r16[ax] = 0x21fe;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2214;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x222a;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2240;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2256;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x226c;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2282;
    { pc = 0x4575; break; }
  case 0x44ea:
    r16[ax] = 0x2298;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x22ae;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x22c4;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x22da;
    { pc = 0x4575; break; }
  case 0x450a:
    r16[ax] = 0x22f0;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2306;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x231c;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2332;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2349;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x235f;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2375;
    { pc = 0x4575; break; }
  case 0x4545:
    r16[ax] = 0x238b;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x23a1;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x23b7;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x23cd;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x23e3;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x23f9;
  case 0x4575:
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
  case 0x457b:
    r16[ax] = memoryAGet16(ds, 0x24d0);
    r16[ax] += 0x0005;
    memoryASet16(ds, 0x82f8, r16[ax]);
    r16[ax] = 0x240f;
    push(r16[ax]);
    yield* sub_8346();
    sp++;
    sp++;
    yield* sub_7b0a();
  case 0x4590:
    yield* sub_8138();
    r16[ax] &= 0x00ff;
    if (r16[ax] != 0x000d)
        { pc = 0x4590; break; }
    yield* sub_d606();
    yield* sub_7b0a();
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ds, 0x5135, r16[dx]);
    memoryASet16(ds, 0x5137, r16[ax]);
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_46c8() // 01ed:27f8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0x0021;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] + 4);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 1390);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax]--;
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] + 4);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 1390);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    if (r16[ax] != memoryAGet16(ss, r16[bp] - 2))
        { pc = 0x4723; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax]--;
    r16[di] = r16[ax];
    { pc = 0x4726; break; }
  case 0x4723:
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
  case 0x4726:
    yield* sub_484e();
    r16[si] = r16[ax];
    memoryASet16(ds, r16[si] + 8, 0x0001);
    memoryASet16(ds, r16[si] + 34, 0x273d);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si], r16[ax]);
    memoryASet16(ds, r16[si] + 2, r16[dx]);
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 6, r16[dx]);
    memoryASet16(ds, r16[si] + 10, 0x0000);
    r16[ax] = r16[di];
    r16[ax] += 0x0003;
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] + 4);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ds, r16[si] + 12, r16[ax]);
    r16[ax] = r16[di];
    r16[ax]++;
    r16[ax]++;
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] + 4);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ds, r16[si] + 14, r16[ax]);
    r16[ax] = r16[di];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] + 4);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ds, r16[si] + 16, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43674, 0x0000);
    r16[ax] = r16[di];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] + 4);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x008f);
    r16[ax] = r16[di];
    r16[ax]++;
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] + 4);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x008f);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_47f7() // 01ed:2927
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x242f;
    push(r16[ax]);
    yield* sub_3131();
    sp++;
    sp++;
    r16[bp] = pop();
    sp += 2;
}
function* sub_4805() // 01ed:2935
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[di] = 0x0001;
    r16[si] = 0x6f10;
    { pc = 0x4816; break; }
  case 0x4812:
    r16[di]++;
    r16[si] += 0x0036;
  case 0x4816:
    if (!memoryAGet16(ds, r16[si]))
        { pc = 0x4821; break; }
    if (r16s[di] < signed16(memoryAGet16(ds, 0x5db4)))
        { pc = 0x4812; break; }
  case 0x4821:
    if (r16s[di] < signed16(memoryAGet16(ds, 0x5db4)))
        { pc = 0x482b; break; }
    memoryASet16(ds, 0x5db4, memoryAGet16(ds, 0x5db4) + 1);
  case 0x482b:
    r16[ax] = 0x0036;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f309();
    sp += 0x0006;
    memoryASet16(ds, r16[si] + 50, 0x2919);
    memoryASet16(ds, r16[si] + 52, 0x2927);
    memoryASet16(ds, r16[si] + 2, 0x0001);
    r16[ax] = r16[si];
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_484e() // 01ed:297e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[di] = 0;
    r16[si] = 0x7fd6;
    { pc = 0x485e; break; }
  case 0x485a:
    r16[di]++;
    r16[si] += 0x0024;
  case 0x485e:
    if (!memoryAGet16(ds, r16[si] + 8))
        { pc = 0x486a; break; }
    if (r16s[di] < signed16(memoryAGet16(ds, 0x8216)))
        { pc = 0x485a; break; }
  case 0x486a:
    if (r16s[di] < signed16(memoryAGet16(ds, 0x8216)))
        { pc = 0x4874; break; }
    memoryASet16(ds, 0x8216, memoryAGet16(ds, 0x8216) + 1);
  case 0x4874:
    r16[ax] = 0x0024;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f309();
    sp += 0x0006;
    memoryASet16(ds, r16[si] + 34, 0x2919);
    r16[ax] = r16[si];
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_488d() // 01ed:29bd
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ds, r16[di] + 12);
    r16[ax] |= memoryAGet16(ds, r16[di] + 14);
    if (!r16[ax])
        { pc = 0x48a8; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 12);
    r16[ax] |= memoryAGet16(ds, r16[si] + 14);
    if (r16[ax])
        { pc = 0x48ac; break; }
  case 0x48a8:
    r16[ax] = 0;
    { pc = 0x4907; break; }
  case 0x48ac:
    r16[ax] = memoryAGet16(ds, r16[di] + 22);
    r16[dx] = memoryAGet16(ds, r16[di] + 20);
    if (r16s[ax] > signed16(memoryAGet16(ds, r16[si] + 14)))
        { pc = 0x48c2; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, r16[si] + 14)))
        { pc = 0x48be; break; }
    if (r16[dx] >= memoryAGet16(ds, r16[si] + 12))
        { pc = 0x48c2; break; }
  case 0x48be:
    r16[ax] = 0;
    { pc = 0x4907; break; }
  case 0x48c2:
    r16[ax] = memoryAGet16(ds, r16[di] + 26);
    r16[dx] = memoryAGet16(ds, r16[di] + 24);
    if (r16s[ax] > signed16(memoryAGet16(ds, r16[si] + 18)))
        { pc = 0x48d8; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, r16[si] + 18)))
        { pc = 0x48d4; break; }
    if (r16[dx] >= memoryAGet16(ds, r16[si] + 16))
        { pc = 0x48d8; break; }
  case 0x48d4:
    r16[ax] = 0;
    { pc = 0x4907; break; }
  case 0x48d8:
    r16[ax] = memoryAGet16(ds, r16[di] + 14);
    r16[dx] = memoryAGet16(ds, r16[di] + 12);
    if (r16s[ax] < signed16(memoryAGet16(ds, r16[si] + 22)))
        { pc = 0x48ee; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, r16[si] + 22)))
        { pc = 0x48ea; break; }
    if (r16[dx] <= memoryAGet16(ds, r16[si] + 20))
        { pc = 0x48ee; break; }
  case 0x48ea:
    r16[ax] = 0;
    { pc = 0x4907; break; }
  case 0x48ee:
    r16[ax] = memoryAGet16(ds, r16[di] + 18);
    r16[dx] = memoryAGet16(ds, r16[di] + 16);
    if (r16s[ax] < signed16(memoryAGet16(ds, r16[si] + 26)))
        { pc = 0x4904; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, r16[si] + 26)))
        { pc = 0x4900; break; }
    if (r16[dx] <= memoryAGet16(ds, r16[si] + 24))
        { pc = 0x4904; break; }
  case 0x4900:
    r16[ax] = 0;
    { pc = 0x4907; break; }
  case 0x4904:
    r16[ax] = 0x0001;
  case 0x4907:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_490b() // 01ed:2a3b
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[ax] = 0;
    r16[dx] = 0x0004;
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8226);
    r16[ax] = memoryAGet16(ds, 0x8224);
    r8[cl] = 0x09;
    yield* sub_10042();
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_ff82();
    r16[dx] = memoryAGet16(ds, 0x8248);
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] += r16[ax];
    r16[si] = r16[dx];
    r16[ax] = 0x8306;
    push(ds);
    push(r16[ax]);
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    push(r16[dx]);
    push(r16[ax]);
    r16[cx] = 0x0020;
    yield* sub_1016b();
    stop("stack_below");
    r16[ax] = memoryAGet16(ds, 0x830e);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ds, 0x8226);
    r16[cx] = memoryAGet16(ds, 0x8224);
    flags.carry = r16[cx] + r16[ax] >= 0x10000;
    r16[cx] += r16[ax];
    r16[bx] += (r16[dx] + flags.carry);
    memoryASet16(ds, 0x822c, r16[cx]);
    memoryASet16(ds, 0x822e, r16[bx]);
    r16[ax] = memoryAGet16(ds, 0x8312);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ds, 0x8226);
    r16[cx] = memoryAGet16(ds, 0x8224);
    flags.carry = r16[cx] + r16[ax] >= 0x10000;
    r16[cx] += r16[ax];
    r16[bx] += (r16[dx] + flags.carry);
    memoryASet16(ds, 0x8234, r16[cx]);
    memoryASet16(ds, 0x8236, r16[bx]);
    r16[ax] = memoryAGet16(ds, 0x8310);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ds, 0x822a);
    r16[cx] = memoryAGet16(ds, 0x8228);
    flags.carry = r16[cx] + r16[ax] >= 0x10000;
    r16[cx] += r16[ax];
    r16[bx] += (r16[dx] + flags.carry);
    memoryASet16(ds, 0x8230, r16[cx]);
    memoryASet16(ds, 0x8232, r16[bx]);
    r16[ax] = memoryAGet16(ds, 0x8314);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ds, 0x822a);
    r16[cx] = memoryAGet16(ds, 0x8228);
    flags.carry = r16[cx] + r16[ax] >= 0x10000;
    r16[cx] += r16[ax];
    r16[bx] += (r16[dx] + flags.carry);
    memoryASet16(ds, 0x8238, r16[cx]);
    memoryASet16(ds, 0x823a, r16[bx]);
    r16[si] = pop();
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
}
function* sub_49b9() // 01ed:2ae9
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = 0;
    r16[dx] = 0x0004;
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, r16[si] + 6);
    r16[ax] = memoryAGet16(ds, r16[si] + 4);
    r8[cl] = 0x09;
    yield* sub_10042();
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_ff82();
    r16[dx] = memoryAGet16(ds, r16[si] + 40);
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] += r16[ax];
    r16[di] = r16[dx];
    r16[ax] = 0x8306;
    push(ds);
    push(r16[ax]);
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    push(r16[dx]);
    push(r16[ax]);
    r16[cx] = 0x0020;
    yield* sub_1016b();
    stop("stack_below");
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x830e);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = pop();
    stop("stack_below");
    flags.carry = r16[bx] + r16[ax] >= 0x10000;
    r16[bx] += r16[ax];
    r16[ax] = pop();
    r16[ax] += (r16[dx] + flags.carry);
    memoryASet16(ds, r16[si] + 12, r16[bx]);
    memoryASet16(ds, r16[si] + 14, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8312);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = pop();
    stop("stack_below");
    flags.carry = r16[bx] + r16[ax] >= 0x10000;
    r16[bx] += r16[ax];
    r16[ax] = pop();
    r16[ax] += (r16[dx] + flags.carry);
    memoryASet16(ds, r16[si] + 20, r16[bx]);
    memoryASet16(ds, r16[si] + 22, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 10);
    r16[dx] = memoryAGet16(ds, r16[si] + 8);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8310);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = pop();
    stop("stack_below");
    flags.carry = r16[bx] + r16[ax] >= 0x10000;
    r16[bx] += r16[ax];
    r16[ax] = pop();
    r16[ax] += (r16[dx] + flags.carry);
    memoryASet16(ds, r16[si] + 16, r16[bx]);
    memoryASet16(ds, r16[si] + 18, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 10);
    r16[dx] = memoryAGet16(ds, r16[si] + 8);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8314);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = pop();
    stop("stack_below");
    flags.carry = r16[bx] + r16[ax] >= 0x10000;
    r16[bx] += r16[ax];
    r16[ax] = pop();
    r16[ax] += (r16[dx] + flags.carry);
    memoryASet16(ds, r16[si] + 24, r16[bx]);
    memoryASet16(ds, r16[si] + 26, r16[ax]);
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
}
function* sub_4a6a() // 01ed:2b9a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[si] = 0x0001;
    { pc = 0x4aa5; break; }
  case 0x4a77:
    memoryASet16(ds, 0x8240, memoryAGet16(ds, 0x8240) + r16[di]);
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0078))
        { pc = 0x4a8a; break; }
    memoryASet16(ds, 0x8240, 0x0078);
    { pc = 0x4a97; break; }
  case 0x4a8a:
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0xff88))
        { pc = 0x4a97; break; }
    memoryASet16(ds, 0x8240, 0xff88);
  case 0x4a97:
    if (r16[si] == memoryAGet16(ds, 0x5b14))
        { pc = 0x4aa4; break; }
    r16[ax] = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x823c, memoryAGet16(ds, 0x823c) + r16[ax]);
  case 0x4aa4:
    r16[si]++;
  case 0x4aa5:
    if (r16[si] <= memoryAGet16(ds, 0x5b14))
        { pc = 0x4a77; break; }
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_4aaf() // 01ed:2bdf
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[si] = 0x0001;
    { pc = 0x4af0; break; }
  case 0x4abf:
    r16[ax] = r16[dx];
    memoryASet16(ds, 0x8242, memoryAGet16(ds, 0x8242) + r16[ax]);
    if (signed16(memoryAGet16(ds, 0x8242)) <= r16s[di])
        { pc = 0x4ad1; break; }
    memoryASet16(ds, 0x8242, r16[di]);
    { pc = 0x4ae2; break; }
  case 0x4ad1:
    r16[ax] = r16[di];
    r16[ax] = -r16[ax];
    if (r16s[ax] <= signed16(memoryAGet16(ds, 0x8242)))
        { pc = 0x4ae2; break; }
    r16[ax] = r16[di];
    r16[ax] = -r16[ax];
    memoryASet16(ds, 0x8242, r16[ax]);
  case 0x4ae2:
    if (r16[si] == memoryAGet16(ds, 0x5b14))
        { pc = 0x4aef; break; }
    r16[ax] = memoryAGet16(ds, 0x8242);
    memoryASet16(ds, 0x823e, memoryAGet16(ds, 0x823e) + r16[ax]);
  case 0x4aef:
    r16[si]++;
  case 0x4af0:
    if (r16[si] <= memoryAGet16(ds, 0x5b14))
        { pc = 0x4abf; break; }
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_4afa() // 01ed:2c2a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = 0x0001;
    { pc = 0x4b34; break; }
  case 0x4b03:
    memoryASet16(ds, 0x8242, memoryAGet16(ds, 0x8242) + 0x0003);
    if (signed16(memoryAGet16(ds, 0x8242)) <= signed16(0x00c8))
        { pc = 0x4b18; break; }
    memoryASet16(ds, 0x8242, 0x00c8);
    { pc = 0x4b26; break; }
  case 0x4b18:
    if (signed16(memoryAGet16(ds, 0x8242)) >= signed16(0xfe70))
        { pc = 0x4b26; break; }
    memoryASet16(ds, 0x8242, 0xfe70);
  case 0x4b26:
    if (r16[si] == memoryAGet16(ds, 0x5b14))
        { pc = 0x4b33; break; }
    r16[ax] = memoryAGet16(ds, 0x8242);
    memoryASet16(ds, 0x823e, memoryAGet16(ds, 0x823e) + r16[ax]);
  case 0x4b33:
    r16[si]++;
  case 0x4b34:
    if (r16[si] <= memoryAGet16(ds, 0x5b14))
        { pc = 0x4b03; break; }
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_4b3d() // 01ed:2c6d
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ds, 0x8240);
    imul16(memoryAGet16(ds, 0x5b14));
    r16[dx] = memoryAGet16(ds, 0x823c);
    r16[dx] += r16[ax];
    memoryASet16(ds, 0x823c, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x8242);
    imul16(memoryAGet16(ds, 0x5b14));
    r16[dx] = memoryAGet16(ds, 0x823e);
    r16[dx] += r16[ax];
    memoryASet16(ds, 0x823e, r16[dx]);
    yield* sub_4b67();
    r16[bp] = pop();
    sp += 2;
}
function* sub_4b67() // 01ed:2c97
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000c;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ss, r16[bp] - 12, 0x0000);
    if (signed16(memoryAGet16(ds, 0x823c)) <= signed16(0x0f00))
        { pc = 0x4b84; break; }
    memoryASet16(ds, 0x823c, 0x0f00);
    { pc = 0x4b92; break; }
  case 0x4b84:
    if (signed16(memoryAGet16(ds, 0x823c)) >= signed16(0xf100))
        { pc = 0x4b92; break; }
    memoryASet16(ds, 0x823c, 0xf100);
  case 0x4b92:
    if (signed16(memoryAGet16(ds, 0x823e)) <= signed16(0x0f00))
        { pc = 0x4ba2; break; }
    memoryASet16(ds, 0x823e, 0x0f00);
    { pc = 0x4bb0; break; }
  case 0x4ba2:
    if (signed16(memoryAGet16(ds, 0x823e)) >= signed16(0xf100))
        { pc = 0x4bb0; break; }
    memoryASet16(ds, 0x823e, 0xf100);
  case 0x4bb0:
    r16[ax] = memoryAGet16(ds, 0x823e);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8238) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8238, memoryAGet16(ds, 0x8238) + r16[ax]);
    memoryASet16(ds, 0x823a, memoryAGet16(ds, 0x823a) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x823e);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8230) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8230, memoryAGet16(ds, 0x8230) + r16[ax]);
    memoryASet16(ds, 0x8232, memoryAGet16(ds, 0x8232) + (r16[dx] + flags.carry));
    r16[dx] = memoryAGet16(ds, 0x822e);
    r16[ax] = memoryAGet16(ds, 0x822c);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x8236);
    r16[ax] = memoryAGet16(ds, 0x8234);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    if (signed16(memoryAGet16(ds, 0x823e)) > signed16(0x0000))
        { pc = 0x4bf0; break; }
    { pc = 0x4ca7; break; }
  case 0x4bf0:
    r16[dx] = memoryAGet16(ds, 0x823a);
    r16[ax] = memoryAGet16(ds, 0x8238);
    r8[cl] = 0x0c;
    yield* sub_10042();
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x823e);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x823a);
    r16[ax] = memoryAGet16(ds, 0x8238);
    r16[bx] = pop();
    r16[cx] = pop();
    flags.carry = r16[ax] < r16[cx];
    r16[ax] -= r16[cx];
    r16[dx] -= (r16[bx] + flags.carry);
    r8[cl] = 0x0c;
    yield* sub_10042();
    r16[bx] = pop();
    flags.zero = r16[bx] == r16[dx];
    r16[dx] = pop();
    if (!flags.zero)
        { pc = 0x4c23; break; }
    if (r16[dx] != r16[ax])
        { pc = 0x4c23; break; }
    { pc = 0x4d64; break; }
  case 0x4c23:
    r16[dx] = memoryAGet16(ds, 0x823a);
    r16[ax] = memoryAGet16(ds, 0x8238);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    { pc = 0x4c9c; break; }
  case 0x4c3a:
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 2612))
        { pc = 0x4c99; break; }
    memoryASet16(ds, 0x8242, 0x0000);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x823a);
    r16[dx] = memoryAGet16(ds, 0x8238);
    flags.carry = r16[dx] + 0x0001 >= 0x10000;
    r16[dx]++;
    r16[ax] += (0x0000 + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_ff82();
    r16[si] = r16[ax];
    memoryASet16(ds, 0x823e, memoryAGet16(ds, 0x823e) - r16[ax]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8230) < r16[ax];
    memoryASet16(ds, 0x8230, memoryAGet16(ds, 0x8230) - r16[ax]);
    memoryASet16(ds, 0x8232, memoryAGet16(ds, 0x8232) - (r16[dx] + flags.carry));
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8238) < r16[ax];
    memoryASet16(ds, 0x8238, memoryAGet16(ds, 0x8238) - r16[ax]);
    memoryASet16(ds, 0x823a, memoryAGet16(ds, 0x823a) - (r16[dx] + flags.carry));
    memoryASet16(ss, r16[bp] - 12, 0x0002);
    { pc = 0x4d64; break; }
  case 0x4c99:
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + 1);
  case 0x4c9c:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    if (r16s[ax] <= signed16(memoryAGet16(ss, r16[bp] - 6)))
        { pc = 0x4c3a; break; }
    { pc = 0x4d64; break; }
  case 0x4ca7:
    if (signed16(memoryAGet16(ds, 0x823e)) < signed16(0x0000))
        { pc = 0x4cb1; break; }
    { pc = 0x4d64; break; }
  case 0x4cb1:
    r16[dx] = memoryAGet16(ds, 0x8232);
    r16[ax] = memoryAGet16(ds, 0x8230);
    r8[cl] = 0x0c;
    yield* sub_10042();
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x823e);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8232);
    r16[ax] = memoryAGet16(ds, 0x8230);
    r16[bx] = pop();
    r16[cx] = pop();
    flags.carry = r16[ax] < r16[cx];
    r16[ax] -= r16[cx];
    r16[dx] -= (r16[bx] + flags.carry);
    r8[cl] = 0x0c;
    yield* sub_10042();
    r16[bx] = pop();
    flags.zero = r16[bx] == r16[dx];
    r16[dx] = pop();
    if (!flags.zero)
        { pc = 0x4ce4; break; }
    if (r16[dx] != r16[ax])
        { pc = 0x4ce4; break; }
    { pc = 0x4d64; break; }
  case 0x4ce4:
    r16[dx] = memoryAGet16(ds, 0x8232);
    r16[ax] = memoryAGet16(ds, 0x8230);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    { pc = 0x4d5c; break; }
  case 0x4cfb:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 5056))
        { pc = 0x4d59; break; }
    memoryASet16(ds, 0x8242, 0x0000);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0x8232));
    push(memoryAGet16(ds, 0x8230));
    yield* sub_ff82();
    r16[dx] = 0x1000;
    r16[dx] -= r16[ax];
    r16[si] = r16[dx];
    memoryASet16(ds, 0x823e, memoryAGet16(ds, 0x823e) + r16[dx]);
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8230) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8230, memoryAGet16(ds, 0x8230) + r16[ax]);
    memoryASet16(ds, 0x8232, memoryAGet16(ds, 0x8232) + (r16[dx] + flags.carry));
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8238) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8238, memoryAGet16(ds, 0x8238) + r16[ax]);
    memoryASet16(ds, 0x823a, memoryAGet16(ds, 0x823a) + (r16[dx] + flags.carry));
    memoryASet16(ss, r16[bp] - 12, 0x0008);
    { pc = 0x4d64; break; }
  case 0x4d59:
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + 1);
  case 0x4d5c:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    if (r16s[ax] <= signed16(memoryAGet16(ss, r16[bp] - 6)))
        { pc = 0x4cfb; break; }
  case 0x4d64:
    r16[ax] = memoryAGet16(ds, 0x823c);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x822c) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x822c, memoryAGet16(ds, 0x822c) + r16[ax]);
    memoryASet16(ds, 0x822e, memoryAGet16(ds, 0x822e) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x823c);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8234) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8234, memoryAGet16(ds, 0x8234) + r16[ax]);
    memoryASet16(ds, 0x8236, memoryAGet16(ds, 0x8236) + (r16[dx] + flags.carry));
    r16[dx] = memoryAGet16(ds, 0x8232);
    r16[ax] = memoryAGet16(ds, 0x8230);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x823a);
    r16[ax] = memoryAGet16(ds, 0x8238);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    if (signed16(memoryAGet16(ds, 0x823c)) > signed16(0x0000))
        { pc = 0x4da4; break; }
    { pc = 0x4e52; break; }
  case 0x4da4:
    r16[dx] = memoryAGet16(ds, 0x8236);
    r16[ax] = memoryAGet16(ds, 0x8234);
    r8[cl] = 0x0c;
    yield* sub_10042();
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x823c);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8236);
    r16[ax] = memoryAGet16(ds, 0x8234);
    r16[bx] = pop();
    r16[cx] = pop();
    flags.carry = r16[ax] < r16[cx];
    r16[ax] -= r16[cx];
    r16[dx] -= (r16[bx] + flags.carry);
    r8[cl] = 0x0c;
    yield* sub_10042();
    r16[bx] = pop();
    flags.zero = r16[bx] == r16[dx];
    r16[dx] = pop();
    if (!flags.zero)
        { pc = 0x4dd7; break; }
    if (r16[dx] != r16[ax])
        { pc = 0x4dd7; break; }
    { pc = 0x4f03; break; }
  case 0x4dd7:
    r16[dx] = memoryAGet16(ds, 0x8236);
    r16[ax] = memoryAGet16(ds, 0x8234);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[di] = memoryAGet16(ss, r16[bp] - 8);
    { pc = 0x4e4a; break; }
  case 0x4deb:
    r16[ax] = r16[di];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 6278))
        { pc = 0x4e49; break; }
    memoryASet16(ds, 0x8240, 0x0000);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x8236);
    r16[dx] = memoryAGet16(ds, 0x8234);
    flags.carry = r16[dx] + 0x0001 >= 0x10000;
    r16[dx]++;
    r16[ax] += (0x0000 + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_ff82();
    r16[si] = r16[ax];
    memoryASet16(ds, 0x823c, memoryAGet16(ds, 0x823c) - r16[ax]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x822c) < r16[ax];
    memoryASet16(ds, 0x822c, memoryAGet16(ds, 0x822c) - r16[ax]);
    memoryASet16(ds, 0x822e, memoryAGet16(ds, 0x822e) - (r16[dx] + flags.carry));
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8234) < r16[ax];
    memoryASet16(ds, 0x8234, memoryAGet16(ds, 0x8234) - r16[ax]);
    memoryASet16(ds, 0x8236, memoryAGet16(ds, 0x8236) - (r16[dx] + flags.carry));
    memoryASet16(ss, r16[bp] - 12, memoryAGet16(ss, r16[bp] - 12) | 0x0004);
    { pc = 0x4f03; break; }
  case 0x4e49:
    r16[di]++;
  case 0x4e4a:
    if (r16s[di] <= signed16(memoryAGet16(ss, r16[bp] - 10)))
        { pc = 0x4deb; break; }
    { pc = 0x4f03; break; }
  case 0x4e52:
    if (signed16(memoryAGet16(ds, 0x823c)) < signed16(0x0000))
        { pc = 0x4e5c; break; }
    { pc = 0x4f03; break; }
  case 0x4e5c:
    r16[dx] = memoryAGet16(ds, 0x822e);
    r16[ax] = memoryAGet16(ds, 0x822c);
    r8[cl] = 0x0c;
    yield* sub_10042();
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x823c);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x822e);
    r16[ax] = memoryAGet16(ds, 0x822c);
    r16[bx] = pop();
    r16[cx] = pop();
    flags.carry = r16[ax] < r16[cx];
    r16[ax] -= r16[cx];
    r16[dx] -= (r16[bx] + flags.carry);
    r8[cl] = 0x0c;
    yield* sub_10042();
    r16[bx] = pop();
    flags.zero = r16[bx] == r16[dx];
    r16[dx] = pop();
    if (!flags.zero)
        { pc = 0x4e8c; break; }
    if (r16[dx] == r16[ax])
        { pc = 0x4f03; break; }
  case 0x4e8c:
    r16[dx] = memoryAGet16(ds, 0x822e);
    r16[ax] = memoryAGet16(ds, 0x822c);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[di] = memoryAGet16(ss, r16[bp] - 8);
    { pc = 0x4efe; break; }
  case 0x4ea0:
    r16[ax] = r16[di];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 4);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 3834))
        { pc = 0x4efd; break; }
    memoryASet16(ds, 0x8240, 0x0000);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0x822e));
    push(memoryAGet16(ds, 0x822c));
    yield* sub_ff82();
    r16[dx] = 0x1000;
    r16[dx] -= r16[ax];
    r16[si] = r16[dx];
    memoryASet16(ds, 0x823c, memoryAGet16(ds, 0x823c) + r16[dx]);
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x822c) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x822c, memoryAGet16(ds, 0x822c) + r16[ax]);
    memoryASet16(ds, 0x822e, memoryAGet16(ds, 0x822e) + (r16[dx] + flags.carry));
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8234) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8234, memoryAGet16(ds, 0x8234) + r16[ax]);
    memoryASet16(ds, 0x8236, memoryAGet16(ds, 0x8236) + (r16[dx] + flags.carry));
    memoryASet16(ss, r16[bp] - 12, memoryAGet16(ss, r16[bp] - 12) | 0x0001);
    { pc = 0x4f03; break; }
  case 0x4efd:
    r16[di]++;
  case 0x4efe:
    if (r16s[di] <= signed16(memoryAGet16(ss, r16[bp] - 10)))
        { pc = 0x4ea0; break; }
  case 0x4f03:
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_5166() // 01ed:3296
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[dx] = memoryAGet16(ds, 0x8226);
    r16[ax] = memoryAGet16(ds, 0x8224);
    r8[cl] = 0x0c;
    yield* sub_10042();
    r16[di] = r16[ax];
    r16[dx] = memoryAGet16(ds, 0x822a);
    r16[ax] = memoryAGet16(ds, 0x8228);
    r8[cl] = 0x0c;
    yield* sub_10042();
    r16[si] = r16[ax];
    if (signed16(memoryAGet16(ds, 0x822a)) > signed16(0x0000))
        { pc = 0x51a3; break; }
    if (signed16(memoryAGet16(ds, 0x822a)) < signed16(0x0000))
        { pc = 0x5197; break; }
    if (memoryAGet16(ds, 0x8228) >= 0x0000)
        { pc = 0x51a3; break; }
  case 0x5197:
    memoryASet16(ds, 0x8228, 0x0000);
    memoryASet16(ds, 0x822a, 0x0000);
  case 0x51a3:
    r16[ax] = memoryAGet16(ds, 0x8226);
    r16[dx] = memoryAGet16(ds, 0x8224);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x5644)))
        { pc = 0x51dd; break; }
    if (r16[ax] != memoryAGet16(ds, 0x5644))
        { pc = 0x51b8; break; }
    if (r16[dx] > memoryAGet16(ds, 0x5642))
        { pc = 0x51dd; break; }
  case 0x51b8:
    if (signed16(memoryAGet16(ds, 0x8226)) < signed16(0x0000))
        { pc = 0x51dd; break; }
    if (memoryAGet16(ds, 0x8226))
        { pc = 0x51c8; break; }
    if (memoryAGet16(ds, 0x8224) < 0x0000)
        { pc = 0x51dd; break; }
  case 0x51c8:
    r16[ax] = memoryAGet16(ds, 0x822a);
    r16[dx] = memoryAGet16(ds, 0x8228);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x5648)))
        { pc = 0x51e8; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x5648)))
        { pc = 0x51dd; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x5646))
        { pc = 0x51e8; break; }
  case 0x51dd:
    memoryASet16(ds, 0x8220, 0x0000);
    r16[ax] = 0x0001;
    { pc = 0x522c; break; }
  case 0x51e8:
    r16[ax] = memoryAGet16(ds, 0x5656);
    r16[ax] += 0xfff8;
    if (r16s[ax] > r16s[di])
        { pc = 0x5210; break; }
    r16[ax] = memoryAGet16(ds, 0x5b12);
    r16[ax] += 0xfff8;
    if (r16s[ax] > r16s[si])
        { pc = 0x5210; break; }
    r16[ax] = memoryAGet16(ds, 0x5656);
    r16[ax] += 0x001c;
    if (r16s[ax] < r16s[di])
        { pc = 0x5210; break; }
    r16[ax] = memoryAGet16(ds, 0x5b12);
    r16[ax] += 0x0012;
    if (r16s[ax] >= r16s[si])
        { pc = 0x522a; break; }
  case 0x5210:
    if (signed16(memoryAGet16(ds, 0x8220)) >= signed16(0x0009))
        { pc = 0x521f; break; }
    memoryASet16(ds, 0x8222, 0x0000);
    { pc = 0x5225; break; }
  case 0x521f:
    memoryASet16(ds, 0x8220, 0x0000);
  case 0x5225:
    r16[ax] = 0x0001;
    { pc = 0x522c; break; }
  case 0x522a:
    r16[ax] = 0;
  case 0x522c:
    r16[di] = pop();
    r16[si] = pop();
    stop("stack_below");
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_5230() // 01ed:3360
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[bp] = pop();
    sp += 2;
}
function* sub_5235() // 01ed:3365
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ds, 0x564c);
    r16[dx] = memoryAGet16(ds, 0x564a);
    flags.carry = r16[dx] + 0x0008 >= 0x10000;
    r16[dx] += 0x0008;
    r16[ax] += (0x0000 + flags.carry);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x8226)))
        { pc = 0x526a; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x8226)))
        { pc = 0x5253; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x8224))
        { pc = 0x526a; break; }
  case 0x5253:
    r16[ax] = 0;
    memoryASet16(ds, 0x823c, r16[ax]);
    memoryASet16(ds, 0x8240, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x564c);
    r16[dx] = memoryAGet16(ds, 0x564a);
    flags.carry = r16[dx] + 0x0008 >= 0x10000;
    r16[dx] += 0x0008;
    r16[ax] += (0x0000 + flags.carry);
    { pc = 0x528e; break; }
  case 0x526a:
    r16[ax] = memoryAGet16(ds, 0x8226);
    r16[dx] = memoryAGet16(ds, 0x8224);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x5dae)))
        { pc = 0x5295; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x5dae)))
        { pc = 0x527f; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x5dac))
        { pc = 0x5295; break; }
  case 0x527f:
    r16[ax] = 0;
    memoryASet16(ds, 0x823c, r16[ax]);
    memoryASet16(ds, 0x8240, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5dae);
    r16[dx] = memoryAGet16(ds, 0x5dac);
  case 0x528e:
    memoryASet16(ds, 0x8224, r16[dx]);
    memoryASet16(ds, 0x8226, r16[ax]);
  case 0x5295:
    r16[ax] = memoryAGet16(ds, 0x822a);
    r16[dx] = memoryAGet16(ds, 0x8228);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x5650)))
        { pc = 0x52c2; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x5650)))
        { pc = 0x52aa; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x564e))
        { pc = 0x52c2; break; }
  case 0x52aa:
    r16[ax] = 0;
    memoryASet16(ds, 0x823e, r16[ax]);
    memoryASet16(ds, 0x8242, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5650);
    r16[dx] = memoryAGet16(ds, 0x564e);
    memoryASet16(ds, 0x8228, r16[dx]);
    memoryASet16(ds, 0x822a, r16[ax]);
    { pc = 0x52e6; break; }
  case 0x52c2:
    r16[ax] = memoryAGet16(ds, 0x822a);
    r16[dx] = memoryAGet16(ds, 0x8228);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x5db2)))
        { pc = 0x52e6; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x5db2)))
        { pc = 0x52d7; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x5db0))
        { pc = 0x52e6; break; }
  case 0x52d7:
    r16[ax] = 0x001b;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    yield* sub_de4f();
    yield* sub_617c();
  case 0x52e6:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_52e8() // 01ed:3418
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0008;
    push(r16[si]);
    push(r16[di]);
    if (memoryAGet16(ds, 0x6f0c) != 0x40ef)
        { pc = 0x52fb; break; }
    { pc = 0x545c; break; }
  case 0x52fb:
    if (memoryAGet16(ds, 0x6f0c) != 0x41f8)
        { pc = 0x5306; break; }
    { pc = 0x545c; break; }
  case 0x5306:
    r16[ax] = memoryAGet16(ds, 0x6ee0);
    r16[dx] = memoryAGet16(ds, 0x6ede);
    memoryASet16(ss, r16[bp] - 4, r16[dx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ee4);
    r16[dx] = memoryAGet16(ds, 0x6ee2);
    memoryASet16(ss, r16[bp] - 8, r16[dx]);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[di] = memoryAGet16(ds, 0x6ef6);
    r16[si] = memoryAGet16(ds, 0x6ef8);
    if (r16s[di] <= 0)
        { pc = 0x5376; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    flags.carry = r16[dx] < memoryAGet16(ds, 0x6ed0);
    r16[dx] -= memoryAGet16(ds, 0x6ed0);
    r16[ax] -= memoryAGet16(ds, 0x6ed2) + flags.carry;
    if (r16s[ax] < 0)
        { pc = 0x5376; break; }
    if (r16s[ax] > 0)
        { pc = 0x5346; break; }
    if (r16[dx] <= 0xb000)
        { pc = 0x5376; break; }
  case 0x5346:
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x6ed0) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + r16[ax]);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x7fc0)))
        { pc = 0x53c2; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x7fc0)))
        { pc = 0x5366; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x7fbe))
        { pc = 0x53c2; break; }
  case 0x5366:
    r16[ax] = memoryAGet16(ds, 0x7fc0);
    r16[dx] = memoryAGet16(ds, 0x7fbe);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    { pc = 0x53c2; break; }
  case 0x5376:
    if (r16s[di] >= 0)
        { pc = 0x53c2; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    flags.carry = r16[dx] < memoryAGet16(ds, 0x6ed0);
    r16[dx] -= memoryAGet16(ds, 0x6ed0);
    r16[ax] -= memoryAGet16(ds, 0x6ed2) + flags.carry;
    if (r16s[ax] > 0)
        { pc = 0x53c2; break; }
    if (r16s[ax] < 0)
        { pc = 0x5394; break; }
    if (r16[dx] >= 0x9000)
        { pc = 0x53c2; break; }
  case 0x5394:
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x6ed0) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + r16[ax]);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x564c)))
        { pc = 0x53c2; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x564c)))
        { pc = 0x53b4; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x564a))
        { pc = 0x53c2; break; }
  case 0x53b4:
    r16[ax] = memoryAGet16(ds, 0x564c);
    r16[dx] = memoryAGet16(ds, 0x564a);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
  case 0x53c2:
    if (r16s[si] <= 0)
        { pc = 0x5410; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = memoryAGet16(ss, r16[bp] - 8);
    flags.carry = r16[dx] < memoryAGet16(ds, 0x6ed4);
    r16[dx] -= memoryAGet16(ds, 0x6ed4);
    r16[ax] -= memoryAGet16(ds, 0x6ed6) + flags.carry;
    if (r16s[ax] < 0)
        { pc = 0x5410; break; }
    if (r16s[ax] > 0)
        { pc = 0x53e0; break; }
    if (r16[dx] <= 0x7000)
        { pc = 0x5410; break; }
  case 0x53e0:
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x6ed4) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + r16[ax]);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x7fc4)))
        { pc = 0x545c; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x7fc4)))
        { pc = 0x5400; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x7fc2))
        { pc = 0x545c; break; }
  case 0x5400:
    r16[ax] = memoryAGet16(ds, 0x7fc4);
    r16[dx] = memoryAGet16(ds, 0x7fc2);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    { pc = 0x545c; break; }
  case 0x5410:
    if (r16s[si] >= 0)
        { pc = 0x545c; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = memoryAGet16(ss, r16[bp] - 8);
    flags.carry = r16[dx] < memoryAGet16(ds, 0x6ed4);
    r16[dx] -= memoryAGet16(ds, 0x6ed4);
    r16[ax] -= memoryAGet16(ds, 0x6ed6) + flags.carry;
    if (r16s[ax] > 0)
        { pc = 0x545c; break; }
    if (r16s[ax] < 0)
        { pc = 0x542e; break; }
    if (r16[dx] >= 0x3000)
        { pc = 0x545c; break; }
  case 0x542e:
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x6ed4) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + r16[ax]);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x5650)))
        { pc = 0x545c; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x5650)))
        { pc = 0x544e; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x564e))
        { pc = 0x545c; break; }
  case 0x544e:
    r16[ax] = memoryAGet16(ds, 0x5650);
    r16[dx] = memoryAGet16(ds, 0x564e);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
  case 0x545c:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_5462() // 01ed:3592
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    memoryASet16(ds, 0x821e, 0x0001);
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = ds;
    es = r16[ax];
    r16[dx] = 0x253b;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[bp] = pop();
    sp += 2;
}
function* sub_5482() // 01ed:35b2
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    memoryASet16(ds, 0x821e, 0x0000);
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = ds;
    es = r16[ax];
    r16[dx] = 0x2519;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[bp] = pop();
    sp += 2;
}
function* sub_54a2() // 01ed:35d2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0012;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0x0019;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = memoryAGet16(ds, 0x821a);
    r16[ax] += 0x0005;
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = memoryAGet16(ds, 0x8218);
    r16[dx] += r16[ax];
    r16[dx] += 0x0003;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[dx];
    if (memoryAGet16(es, r16[bx]) == 0x01df)
        { pc = 0x54d8; break; }
    { pc = 0x558c; break; }
  case 0x54d8:
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ss, r16[bp] - 14, r16[dx]);
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ss, r16[bp] - 18, r16[dx]);
    memoryASet16(ss, r16[bp] - 16, r16[ax]);
    r16[si] = 0x0001;
    { pc = 0x555e; break; }
  case 0x54f7:
    yield* sub_2109();
    r16[ax] = 0x0040;
    push(r16[ax]);
    yield* sub_df2c();
    sp++;
    sp++;
    r16[ax] += 0xffe0;
    r8[cl] = 0x08;
    r16[ax] <<= r8[cl];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ss, r16[bp] - 12);
    r16[cx] = memoryAGet16(ss, r16[bp] - 14);
    flags.carry = r16[cx] < r16[ax];
    r16[cx] -= r16[ax];
    r16[bx] -= (r16[dx] + flags.carry);
    memoryASet16(ds, 0x6ed0, r16[cx]);
    memoryASet16(ds, 0x6ed2, r16[bx]);
    r16[ax] = 0x0040;
    push(r16[ax]);
    yield* sub_df2c();
    sp++;
    sp++;
    r16[ax] += 0xffe0;
    r8[cl] = 0x08;
    r16[ax] <<= r8[cl];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ss, r16[bp] - 16);
    r16[cx] = memoryAGet16(ss, r16[bp] - 18);
    flags.carry = r16[cx] < r16[ax];
    r16[cx] -= r16[ax];
    r16[bx] -= (r16[dx] + flags.carry);
    memoryASet16(ds, 0x6ed4, r16[cx]);
    memoryASet16(ds, 0x6ed6, r16[bx]);
    push(memoryAGet16(ds, 0x8248));
    push(memoryAGet16(ds, 0x822a));
    push(memoryAGet16(ds, 0x8228));
    push(memoryAGet16(ds, 0x8226));
    push(memoryAGet16(ds, 0x8224));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[si]++;
  case 0x555e:
    if (r16s[si] < signed16(0x0050))
        { pc = 0x54f7; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x2444;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x0064;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    memoryASet16(ds, 0x6c60, 0x0003);
    { pc = 0x5731; break; }
  case 0x558c:
    r16[ax] = memoryAGet16(ds, 0x821a);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ds, 0x8218);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    if (r16[ax] == 0x010f)
        { pc = 0x55ea; break; }
    if (r16[ax] == 0x01e0)
        { pc = 0x55b6; break; }
    if (r16[ax] == 0x01ed)
        { pc = 0x55d0; break; }
    { pc = 0x55fd; break; }
  case 0x55b6:
    r16[ax] = memoryAGet16(ds, 0x821a);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ds, 0x8218);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x01ed);
    { pc = 0x55fd; break; }
  case 0x55d0:
    r16[ax] = memoryAGet16(ds, 0x821a);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ds, 0x8218);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x01e0);
    { pc = 0x55fd; break; }
  case 0x55ea:
    if (!memoryAGet16(ds, 0x821e))
        { pc = 0x55f7; break; }
    yield* sub_5482();
    { pc = 0x5731; break; }
  case 0x55f7:
    yield* sub_5462();
    { pc = 0x5731; break; }
  case 0x55fd:
    r16[ax] = memoryAGet16(ds, 0x821a);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ds, 0x8218);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r8[al] = memoryAGet(ss, r16[bp] - 2);
    r8[al] &= 0xff;
    cbw();
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8218);
    r16[ax] += memoryAGet16(ss, r16[bp] - 10);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r8[cl] = 0x08;
    r16[ax] >>= r8[cl];
    cbw();
    r16[dx] = memoryAGet16(ds, 0x821a);
    r16[dx] += r16[ax];
    memoryASet16(ss, r16[bp] - 8, r16[dx]);
    r16[si] = 0;
    { pc = 0x5680; break; }
  case 0x563d:
    r16[ax] = r16[si];
    r16[dx] = 0x0024;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    if (!memoryAGet16(ds, r16[bx] + 32734))
        { pc = 0x567f; break; }
    r16[ax] = r16[si];
    r16[dx] = 0x0024;
    imul16(r16[dx]);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = pop();
    if (memoryAGet16(ds, r16[bx] + 32728) != r16[dx])
        { pc = 0x567f; break; }
    if (memoryAGet16(ds, r16[bx] + 32726) != r16[ax])
        { pc = 0x567f; break; }
    r16[ax] = r16[si];
    r16[dx] = 0x0024;
    imul16(r16[dx]);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = pop();
    if (memoryAGet16(ds, r16[bx] + 32732) != r16[dx])
        { pc = 0x567f; break; }
    if (memoryAGet16(ds, r16[bx] + 32730) == r16[ax])
        { pc = 0x5686; break; }
  case 0x567f:
    r16[si]++;
  case 0x5680:
    if (r16s[si] < signed16(memoryAGet16(ds, 0x8216)))
        { pc = 0x563d; break; }
  case 0x5686:
    if (r16s[si] >= signed16(memoryAGet16(ds, 0x8216)))
        { pc = 0x56c0; break; }
    r16[ax] = r16[si];
    r16[dx] = 0x0024;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    if (memoryAGet16(ds, r16[bx] + 32760) != 0x4afa)
        { pc = 0x56af; break; }
    r16[ax] = r16[si];
    r16[dx] = 0x0024;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    memoryASet16(ds, r16[bx] + 32760, 0x4a8b);
    { pc = 0x5731; break; }
  case 0x56af:
    r16[ax] = r16[si];
    r16[dx] = 0x0024;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    memoryASet16(ds, r16[bx] + 32760, 0x4afa);
    { pc = 0x5731; break; }
  case 0x56c0:
    yield* sub_484e();
    r16[di] = r16[ax];
    memoryASet16(ds, r16[di] + 8, 0x0002);
    memoryASet16(ds, r16[di] + 34, 0x4a8b);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, r16[di], r16[ax]);
    memoryASet16(ds, r16[di] + 2, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, r16[di] + 4, r16[ax]);
    memoryASet16(ds, r16[di] + 6, r16[dx]);
    memoryASet16(ds, r16[di] + 10, 0x0000);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] += r16[ax];
    r16[dx]++;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[dx];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 6278))
        { pc = 0x570f; break; }
    memoryASet16(ds, r16[di] + 12, 0xffff);
    { pc = 0x5714; break; }
  case 0x570f:
    memoryASet16(ds, r16[di] + 12, 0x0001);
  case 0x5714:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ds, r16[di] + 14, r16[ax]);
    memoryASet16(ds, r16[di] + 16, 0x0000);
  case 0x5731:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_5737() // 01ed:3867
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000a;
    push(r16[si]);
    push(r16[di]);
    if (!memoryAGet16(ds, 0x8250))
        { pc = 0x574b; break; }
    r16[di] = 0x0001;
    { pc = 0x57ab; break; }
  case 0x574b:
    r16[dx] = memoryAGet16(ds, 0x822e);
    r16[ax] = memoryAGet16(ds, 0x822c);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x8236);
    r16[ax] = memoryAGet16(ds, 0x8234);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x823a);
    r16[ax] = memoryAGet16(ds, 0x8238);
    r8[cl] = 0x0c;
    yield* sub_10042();
    r16[ax]++;
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[di] = 0x0001;
    r16[si] = memoryAGet16(ss, r16[bp] - 4);
    { pc = 0x57a6; break; }
  case 0x5781:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[si];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 2612);
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    if (r16s[ax] <= signed16(0x0001))
        { pc = 0x57a5; break; }
    r16[di] = r16[ax];
  case 0x57a5:
    r16[si]++;
  case 0x57a6:
    if (r16s[si] <= signed16(memoryAGet16(ss, r16[bp] - 6)))
        { pc = 0x5781; break; }
  case 0x57ab:
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x57e5; break; }
    r16[ax] = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x824e, r16[ax]);
    memoryASet16(ds, 0x8240, 0x0000);
    memoryASet16(ds, 0x824c, 0x0000);
    memoryASet16(ds, 0x824a, 0x0000);
    if (signed16(memoryAGet16(ds, 0x604c)) < signed16(0x0000))
        { pc = 0x57d9; break; }
    memoryASet16(ds, 0x8246, 0x0008);
    { pc = 0x57df; break; }
  case 0x57d9:
    memoryASet16(ds, 0x8246, 0x000e);
  case 0x57df:
    memoryASet16(ds, 0x8252, 0x3b8b);
  case 0x57e5:
    if (r16s[di] >= signed16(0x0003))
        { pc = 0x5829; break; }
    r16[bx] = memoryAGet16(ds, 0x7fca);
    r16[bx]--;
    if (r16[bx] > 0x0006)
        { pc = 0x5829; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x57fb; break; }
        case 2: { pc = 0x57fb; break; }
        case 4: { pc = 0x57fb; break; }
        case 6: { pc = 0x5829; break; }
        case 8: { pc = 0x5813; break; }
        case 10: { pc = 0x5813; break; }
        case 12: { pc = 0x5813; break; }
        default:
            stop("ind 01ed:3926");
    }
    break;
  case 0x57fb:
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0x0000))
        { pc = 0x5829; break; }
    memoryASet16(ds, 0x7fca, 0x0008);
    { pc = 0x5829; break; }
  case 0x5813:
    r16[ax] = 0xfffe;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x5829; break; }
    memoryASet16(ds, 0x7fca, 0x0008);
  case 0x5829:
    if (r16[di] != 0x0001)
        { pc = 0x5871; break; }
    if (memoryAGet16(ds, 0x7fca) != 0x0008)
        { pc = 0x5871; break; }
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x5854; break; }
    r16[ax] = 0xfffd;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0x0000))
        { pc = 0x5871; break; }
    memoryASet16(ds, 0x8240, 0x0000);
    { pc = 0x5871; break; }
  case 0x5854:
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0x0000))
        { pc = 0x5871; break; }
    r16[ax] = 0x0003;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x5871; break; }
    memoryASet16(ds, 0x8240, 0x0000);
  case 0x5871:
    if (r16[di] != 0x0003)
        { pc = 0x5892; break; }
    if (signed16(memoryAGet16(ds, 0x604c)) <= signed16(0x0000))
        { pc = 0x5885; break; }
    memoryASet16(ds, 0x8240, 0x00b4);
    { pc = 0x5892; break; }
  case 0x5885:
    if (signed16(memoryAGet16(ds, 0x604c)) >= signed16(0x0000))
        { pc = 0x5892; break; }
    memoryASet16(ds, 0x8240, 0xff4c);
  case 0x5892:
    if (memoryAGet16(ds, 0x8240))
        { pc = 0x58b0; break; }
    if (signed16(memoryAGet16(ds, 0x604c)) < signed16(0x0000))
        { pc = 0x58a8; break; }
    memoryASet16(ds, 0x8248, 0x0000);
    { pc = 0x58ff; break; }
  case 0x58a8:
    memoryASet16(ds, 0x8248, 0x0004);
    { pc = 0x58ff; break; }
  case 0x58b0:
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x58da; break; }
    memoryASet16(ds, 0x8248, 0x0000);
    if (r16s[di] >= signed16(0x0003))
        { pc = 0x58d8; break; }
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[ax] &= 0x0003;
    r16[dx] = memoryAGet16(ds, 0x8248);
    r16[dx] += r16[ax];
    memoryASet16(ds, 0x8248, r16[dx]);
    { pc = 0x58f9; break; }
  case 0x58d8:
    { pc = 0x58f9; break; }
  case 0x58da:
    memoryASet16(ds, 0x8248, 0x0004);
    if (r16s[di] >= signed16(0x0003))
        { pc = 0x58f9; break; }
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[ax] &= 0x0003;
    r16[dx] = memoryAGet16(ds, 0x8248);
    r16[dx] += r16[ax];
    memoryASet16(ds, 0x8248, r16[dx]);
  case 0x58f9:
    r16[ax] = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x604c, r16[ax]);
  case 0x58ff:
    if (!memoryAGet16(ds, 0x8240))
        { pc = 0x5931; break; }
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    if (!(r16[ax] & 0x0001))
        { pc = 0x5931; break; }
    if (r16s[di] >= signed16(0x0003))
        { pc = 0x5931; break; }
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x05;
    r16[ax] >>= r8[cl];
    if (!(r16[ax] & 0x0001))
        { pc = 0x5928; break; }
    r16[ax] = 0x001e;
    { pc = 0x592b; break; }
  case 0x5928:
    r16[ax] = 0x0004;
  case 0x592b:
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x5931:
    yield* sub_4afa();
    yield* sub_4b3d();
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    yield* sub_5235();
    if (memoryAGet16(ss, r16[bp] - 2) & 0x0004)
        { pc = 0x594b; break; }
    if (!(memoryAGet16(ss, r16[bp] - 2) & 0x0001))
        { pc = 0x5960; break; }
  case 0x594b:
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    if (!(r16[ax] & 0x0001))
        { pc = 0x5960; break; }
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x5960:
    if (memoryAGet16(ss, r16[bp] - 2) & 0x0002)
        { pc = 0x5980; break; }
    if (memoryAGet16(ds, 0x8250))
        { pc = 0x5980; break; }
    memoryASet16(ds, 0x8252, 0x3c99);
    r16[ax] = 0x001b;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    { pc = 0x5a46; break; }
  case 0x5980:
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x59ba; break; }
    r16[ax] = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x824e, r16[ax]);
    memoryASet16(ds, 0x8240, 0x0000);
    memoryASet16(ds, 0x824c, 0x0000);
    memoryASet16(ds, 0x824a, 0x0000);
    if (signed16(memoryAGet16(ds, 0x604c)) < signed16(0x0000))
        { pc = 0x59ae; break; }
    memoryASet16(ds, 0x8246, 0x0008);
    { pc = 0x59b4; break; }
  case 0x59ae:
    memoryASet16(ds, 0x8246, 0x000e);
  case 0x59b4:
    memoryASet16(ds, 0x8252, 0x3b8b);
  case 0x59ba:
    if (!memoryAGet16(ds, 0x7fce))
        { pc = 0x59f3; break; }
    if (memoryAGet16(ds, 0x7fd4))
        { pc = 0x59f3; break; }
    if (!memoryAGet16(ds, 0x8258))
        { pc = 0x59d4; break; }
    yield* sub_54a2();
    { pc = 0x59f3; break; }
  case 0x59d4:
    memoryASet16(ds, 0x824a, 0x0000);
    r16[ax] = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x824c, r16[ax]);
    memoryASet16(ds, 0x8240, 0x0000);
    if (!memoryAGet16(ds, 0xaa9a))
        { pc = 0x59f3; break; }
    memoryASet16(ds, 0x8252, 0x4054);
  case 0x59f3:
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x5a3b; break; }
    if (!memoryAGet16(ds, 0x7fce))
        { pc = 0x5a3b; break; }
    if (memoryAGet16(ds, 0x7fd2))
        { pc = 0x5a3b; break; }
    if (memoryAGet16(ds, 0x7fd4))
        { pc = 0x5a3b; break; }
    memoryASet16(ds, 0x8252, 0x3e12);
    r16[ax] = 0;
    memoryASet16(ds, 0x823c, r16[ax]);
    memoryASet16(ds, 0x824c, r16[ax]);
    memoryASet16(ds, 0x824a, r16[ax]);
    memoryASet16(ds, 0x8252, 0x3e12);
    if (signed16(memoryAGet16(ds, 0x604c)) <= signed16(0x0000))
        { pc = 0x5a35; break; }
    memoryASet16(ds, 0x8248, 0x0014);
    { pc = 0x5a3b; break; }
  case 0x5a35:
    memoryASet16(ds, 0x8248, 0x0015);
  case 0x5a3b:
    if (!memoryAGet16(ds, 0x8250))
        { pc = 0x5a46; break; }
    memoryASet16(ds, 0x8250, memoryAGet16(ds, 0x8250) - 1);
  case 0x5a46:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_5a5b() // 01ed:3b8b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ds, 0x824a);
    r16[bx] = 0x0006;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[dx] = memoryAGet16(ds, 0x8246);
    r16[dx] += r16[ax];
    memoryASet16(ds, 0x8248, r16[dx]);
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x5a8c; break; }
    r16[ax] = memoryAGet16(ds, 0x5b14);
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x824c);
    r16[dx] += r16[ax];
    memoryASet16(ds, 0x824c, r16[dx]);
    { pc = 0x5a9d; break; }
  case 0x5a8c:
    if (signed16(memoryAGet16(ds, 0x824a)) >= signed16(0x000c))
        { pc = 0x5a9d; break; }
    r16[ax] = 0x0018;
    r16[ax] -= memoryAGet16(ds, 0x824a);
    memoryASet16(ds, 0x824a, r16[ax]);
  case 0x5a9d:
    r16[bx] = memoryAGet16(ds, 0x7fca);
    r16[bx]--;
    if (r16[bx] > 0x0006)
        { pc = 0x5ae4; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x5aae; break; }
        case 2: { pc = 0x5aae; break; }
        case 4: { pc = 0x5aae; break; }
        case 6: { pc = 0x5ae4; break; }
        case 8: { pc = 0x5aca; break; }
        case 10: { pc = 0x5aca; break; }
        case 12: { pc = 0x5aca; break; }
        default:
            stop("ind 01ed:3bd9");
    }
    break;
  case 0x5aae:
    r16[ax] = memoryAGet16(ds, 0x5b14);
    r16[ax] <<= 1;
    r16[dx] = memoryAGet16(ds, 0x824e);
    r16[dx] += r16[ax];
    memoryASet16(ds, 0x824e, r16[dx]);
    if (r16s[dx] <= signed16(0x0078))
        { pc = 0x5ae4; break; }
    memoryASet16(ds, 0x824e, 0x0078);
    { pc = 0x5ae4; break; }
  case 0x5aca:
    r16[ax] = memoryAGet16(ds, 0x5b14);
    r16[ax] <<= 1;
    r16[dx] = memoryAGet16(ds, 0x824e);
    r16[dx] -= r16[ax];
    memoryASet16(ds, 0x824e, r16[dx]);
    if (r16s[dx] >= signed16(0xff88))
        { pc = 0x5ae4; break; }
    memoryASet16(ds, 0x824e, 0xff88);
  case 0x5ae4:
    memoryASet16(ds, 0x8240, 0x0000);
    r16[ax] = memoryAGet16(ds, 0x824a);
    r16[ax] += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, r16[ax]);
    if (r16s[ax] < signed16(0x0024))
        { pc = 0x5b15; break; }
    memoryASet16(ds, 0x8252, 0x3c99);
    r16[ax] = memoryAGet16(ds, 0x824c);
    memoryASet16(ds, 0x8242, memoryAGet16(ds, 0x8242) - r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x824e);
    memoryASet16(ds, 0x8240, r16[ax]);
    r16[ax] = 0x0006;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x5b15:
    yield* sub_4afa();
    yield* sub_4b3d();
    yield* sub_5235();
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x5b58; break; }
    if (!memoryAGet16(ds, 0x7fce))
        { pc = 0x5b58; break; }
    memoryASet16(ds, 0x8252, 0x3e12);
    r16[ax] = 0;
    memoryASet16(ds, 0x823c, r16[ax]);
    memoryASet16(ds, 0x824c, r16[ax]);
    memoryASet16(ds, 0x824a, r16[ax]);
    memoryASet16(ds, 0x8252, 0x3e12);
    if (signed16(memoryAGet16(ds, 0x604c)) <= signed16(0x0000))
        { pc = 0x5b52; break; }
    memoryASet16(ds, 0x8248, 0x0014);
    { pc = 0x5b58; break; }
  case 0x5b52:
    memoryASet16(ds, 0x8248, 0x0015);
  case 0x5b58:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_5b69() // 01ed:3c99
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[bx] = memoryAGet16(ds, 0x7fca);
    r16[bx]--;
    if (r16[bx] > 0x0006)
        { pc = 0x5bac; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x5b7e; break; }
        case 2: { pc = 0x5b7e; break; }
        case 4: { pc = 0x5b7e; break; }
        case 6: { pc = 0x5bac; break; }
        case 8: { pc = 0x5b96; break; }
        case 10: { pc = 0x5b96; break; }
        case 12: { pc = 0x5b96; break; }
        default:
            stop("ind 01ed:3ca9");
    }
    break;
  case 0x5b7e:
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0x0000))
        { pc = 0x5bac; break; }
    memoryASet16(ds, 0x7fca, 0x0008);
    { pc = 0x5bac; break; }
  case 0x5b96:
    r16[ax] = 0xfffe;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x5bac; break; }
    memoryASet16(ds, 0x7fca, 0x0008);
  case 0x5bac:
    if (memoryAGet16(ds, 0x7fca) != 0x0008)
        { pc = 0x5bef; break; }
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x5bd2; break; }
    r16[ax] = 0xffff;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0x0000))
        { pc = 0x5bef; break; }
    memoryASet16(ds, 0x8240, 0x0000);
    { pc = 0x5bef; break; }
  case 0x5bd2:
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0x0000))
        { pc = 0x5bef; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x5bef; break; }
    memoryASet16(ds, 0x8240, 0x0000);
  case 0x5bef:
    if (signed16(memoryAGet16(ds, 0x604c)) <= signed16(0x0000))
        { pc = 0x5bfe; break; }
    memoryASet16(ds, 0x8248, 0x000d);
    { pc = 0x5c04; break; }
  case 0x5bfe:
    memoryASet16(ds, 0x8248, 0x0013);
  case 0x5c04:
    if (!memoryAGet16(ds, 0x8240))
        { pc = 0x5c11; break; }
    r16[ax] = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x604c, r16[ax]);
  case 0x5c11:
    yield* sub_4afa();
    yield* sub_4b3d();
    r16[si] = r16[ax];
    if (r16[ax] & 0x0004)
        { pc = 0x5c23; break; }
    if (!(r16[ax] & 0x0001))
        { pc = 0x5c38; break; }
  case 0x5c23:
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    if (!(r16[ax] & 0x0001))
        { pc = 0x5c38; break; }
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x5c38:
    if (!(r16[si] & 0x0002))
        { pc = 0x5c50; break; }
    memoryASet16(ds, 0x8252, 0x3867);
    r16[ax] = 0x0007;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    { pc = 0x5cd1; break; }
  case 0x5c50:
    if (!(r16[si] & 0x0008))
        { pc = 0x5c5f; break; }
    r16[ax] = 0x0015;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x5c5f:
    yield* sub_5235();
    if (!memoryAGet16(ds, 0x7fce))
        { pc = 0x5c89; break; }
    if (memoryAGet16(ds, 0x7fd4))
        { pc = 0x5c89; break; }
    if (!memoryAGet16(ds, 0x8258))
        { pc = 0x5c7c; break; }
    yield* sub_54a2();
    { pc = 0x5c89; break; }
  case 0x5c7c:
    if (!memoryAGet16(ds, 0xaa9a))
        { pc = 0x5c89; break; }
    memoryASet16(ds, 0x8252, 0x3ec8);
  case 0x5c89:
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x5cd1; break; }
    if (!memoryAGet16(ds, 0x7fce))
        { pc = 0x5cd1; break; }
    if (memoryAGet16(ds, 0x7fd2))
        { pc = 0x5cd1; break; }
    if (memoryAGet16(ds, 0x7fd4))
        { pc = 0x5cd1; break; }
    memoryASet16(ds, 0x8252, 0x3e12);
    r16[ax] = 0;
    memoryASet16(ds, 0x823c, r16[ax]);
    memoryASet16(ds, 0x824c, r16[ax]);
    memoryASet16(ds, 0x824a, r16[ax]);
    memoryASet16(ds, 0x8252, 0x3e12);
    if (signed16(memoryAGet16(ds, 0x604c)) <= signed16(0x0000))
        { pc = 0x5ccb; break; }
    memoryASet16(ds, 0x8248, 0x0014);
    { pc = 0x5cd1; break; }
  case 0x5ccb:
    memoryASet16(ds, 0x8248, 0x0015);
  case 0x5cd1:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_5ce2() // 01ed:3e12
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ds, 0x824a);
    r16[ax] += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, r16[ax]);
    if (memoryAGet16(ds, 0x824c))
        { pc = 0x5d36; break; }
    if (r16s[ax] <= signed16(0x0001))
        { pc = 0x5d36; break; }
    if (!memoryAGet16(ds, 0xaac8))
        { pc = 0x5d27; break; }
    r16[ax] = 0x000c;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, 0xaac8, memoryAGet16(ds, 0xaac8) - 1);
    push(memoryAGet16(ds, 0x822a));
    push(memoryAGet16(ds, 0x8228));
    push(memoryAGet16(ds, 0x8226));
    push(memoryAGet16(ds, 0x8224));
    yield* sub_658a();
    sp += 0x0008;
    { pc = 0x5d30; break; }
  case 0x5d27:
    r16[ax] = 0x0024;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x5d30:
    memoryASet16(ds, 0x824c, 0x0001);
  case 0x5d36:
    if (signed16(memoryAGet16(ds, 0x824a)) <= signed16(0x001e))
        { pc = 0x5d51; break; }
    if (memoryAGet16(ds, 0x7fcc))
        { pc = 0x5d51; break; }
    if (memoryAGet16(ds, 0x7fce))
        { pc = 0x5d51; break; }
    memoryASet16(ds, 0x8252, 0x3867);
  case 0x5d51:
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x5d70; break; }
    r16[ax] = 0xffff;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0x0000))
        { pc = 0x5d8d; break; }
    memoryASet16(ds, 0x8240, 0x0000);
    { pc = 0x5d8d; break; }
  case 0x5d70:
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0x0000))
        { pc = 0x5d8d; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x5d8d; break; }
    memoryASet16(ds, 0x8240, 0x0000);
  case 0x5d8d:
    yield* sub_4afa();
    yield* sub_4b3d();
    yield* sub_5235();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_5d98() // 01ed:3ec8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0006;
    push(r16[si]);
    r16[ax] = 0x7fca;
    push(ds);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 6;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[bx] = memoryAGet16(ds, 0x7fca);
    r16[bx]--;
    if (r16[bx] > 0x0006)
        { pc = 0x5dfd; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x5dcf; break; }
        case 2: { pc = 0x5dcf; break; }
        case 4: { pc = 0x5dcf; break; }
        case 6: { pc = 0x5dfd; break; }
        case 8: { pc = 0x5de7; break; }
        case 10: { pc = 0x5de7; break; }
        case 12: { pc = 0x5de7; break; }
        default:
            stop("ind 01ed:3efa");
    }
    break;
  case 0x5dcf:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) >= signed16(0x0000))
        { pc = 0x5dfd; break; }
    memoryASet16(ds, 0x7fca, 0x0008);
    { pc = 0x5dfd; break; }
  case 0x5de7:
    r16[ax] = 0xffff;
    push(r16[ax]);
    yield* sub_4a6a();
    sp++;
    sp++;
    if (signed16(memoryAGet16(ds, 0x8240)) <= signed16(0x0000))
        { pc = 0x5dfd; break; }
    memoryASet16(ds, 0x7fca, 0x0008);
  case 0x5dfd:
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x5e19; break; }
    if (signed16(memoryAGet16(ds, 0x8242)) >= signed16(0x0000))
        { pc = 0x5e19; break; }
    r16[ax] = 0xffff;
    push(r16[ax]);
    r16[ax] = 0x00c8;
    push(r16[ax]);
    yield* sub_4aaf();
    sp += 0x0004;
  case 0x5e19:
    if (!memoryAGet16(ds, 0x5daa))
        { pc = 0x5e2d; break; }
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x5e2d; break; }
    memoryASet16(ds, 0x8242, 0xff38);
  case 0x5e2d:
    if (!memoryAGet16(ds, 0x8240))
        { pc = 0x5e3a; break; }
    r16[ax] = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x604c, r16[ax]);
  case 0x5e3a:
    if (signed16(memoryAGet16(ds, 0x604c)) < signed16(0x0000))
        { pc = 0x5e49; break; }
    memoryASet16(ds, 0x8246, 0x0018);
    { pc = 0x5e4f; break; }
  case 0x5e49:
    memoryASet16(ds, 0x8246, 0x001a);
  case 0x5e4f:
    r16[ax] = memoryAGet16(ds, 0x8246);
    memoryASet16(ds, 0x8248, r16[ax]);
    yield* sub_4afa();
    yield* sub_4b3d();
    r16[si] = r16[ax];
    if (r16[ax] & 0x0004)
        { pc = 0x5e67; break; }
    if (!(r16[ax] & 0x0001))
        { pc = 0x5e7c; break; }
  case 0x5e67:
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    if (!(r16[ax] & 0x0001))
        { pc = 0x5e7c; break; }
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x5e7c:
    if (!(r16[si] & 0x0002))
        { pc = 0x5e9a; break; }
    memoryASet16(ds, 0x8252, 0x4054);
    memoryASet16(ds, 0x824a, 0x0000);
    r16[ax] = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x824c, r16[ax]);
    memoryASet16(ds, 0x8240, 0x0000);
  case 0x5e9a:
    if (!(r16[si] & 0x0008))
        { pc = 0x5ea9; break; }
    r16[ax] = 0x0015;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x5ea9:
    yield* sub_5235();
    if (!memoryAGet16(ds, 0x7fce))
        { pc = 0x5ecc; break; }
    if (memoryAGet16(ds, 0x7fd4))
        { pc = 0x5ecc; break; }
    if (!memoryAGet16(ds, 0x8258))
        { pc = 0x5ec6; break; }
    yield* sub_54a2();
    { pc = 0x5ecc; break; }
  case 0x5ec6:
    memoryASet16(ds, 0x8252, 0x3c99);
  case 0x5ecc:
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x5f06; break; }
    if (!memoryAGet16(ds, 0x7fce))
        { pc = 0x5f06; break; }
    memoryASet16(ds, 0x8252, 0x3e12);
    r16[ax] = 0;
    memoryASet16(ds, 0x823c, r16[ax]);
    memoryASet16(ds, 0x824c, r16[ax]);
    memoryASet16(ds, 0x824a, r16[ax]);
    memoryASet16(ds, 0x8252, 0x3e12);
    if (signed16(memoryAGet16(ds, 0x604c)) <= signed16(0x0000))
        { pc = 0x5f00; break; }
    memoryASet16(ds, 0x8248, 0x0014);
    { pc = 0x5f06; break; }
  case 0x5f00:
    memoryASet16(ds, 0x8248, 0x0015);
  case 0x5f06:
    if (!memoryAGet16(ds, 0x8250))
        { pc = 0x5f11; break; }
    memoryASet16(ds, 0x8250, memoryAGet16(ds, 0x8250) - 1);
  case 0x5f11:
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_5f24() // 01ed:4054
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0;
    memoryASet16(ds, 0x8240, r16[ax]);
    memoryASet16(ds, 0x823c, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8246);
    r16[ax]++;
    memoryASet16(ds, 0x8248, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x824a);
    r16[ax] += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, r16[ax]);
    if (r16s[ax] <= signed16(0x0016))
        { pc = 0x5f66; break; }
    memoryASet16(ds, 0x8252, 0x3ec8);
    memoryASet16(ds, 0x8250, 0x0000);
    memoryASet16(ds, 0x8242, memoryAGet16(ds, 0x8242) - 0x00c8);
    r16[ax] = memoryAGet16(ds, 0x824c);
    memoryASet16(ds, 0x8240, r16[ax]);
    r16[ax] = 0x0006;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x5f66:
    if (!memoryAGet16(ds, 0x7fce))
        { pc = 0x5f7a; break; }
    if (memoryAGet16(ds, 0x7fd4))
        { pc = 0x5f7a; break; }
    memoryASet16(ds, 0x8252, 0x3867);
  case 0x5f7a:
    if (!memoryAGet16(ds, 0x7fcc))
        { pc = 0x5fb4; break; }
    if (!memoryAGet16(ds, 0x7fce))
        { pc = 0x5fb4; break; }
    memoryASet16(ds, 0x8252, 0x3e12);
    r16[ax] = 0;
    memoryASet16(ds, 0x823c, r16[ax]);
    memoryASet16(ds, 0x824c, r16[ax]);
    memoryASet16(ds, 0x824a, r16[ax]);
    memoryASet16(ds, 0x8252, 0x3e12);
    if (signed16(memoryAGet16(ds, 0x604c)) <= signed16(0x0000))
        { pc = 0x5fae; break; }
    memoryASet16(ds, 0x8248, 0x0014);
    { pc = 0x5fb4; break; }
  case 0x5fae:
    memoryASet16(ds, 0x8248, 0x0015);
  case 0x5fb4:
    yield* sub_4b3d();
    memoryASet16(ds, 0x8250, 0x0000);
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_5fbf() // 01ed:40ef
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0008;
    r16[ax] = memoryAGet16(ds, 0x824a);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    memoryASet16(ss, r16[bp] - 2, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x824c);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    memoryASet16(ss, r16[bp] - 6, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x5b14);
    r16[dx] = 0x003c;
    imul16(r16[dx]);
    memoryASet16(ds, 0x823c, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[ax] &= 0x0003;
    memoryASet16(ds, 0x8248, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8240);
    memoryASet16(ds, 0x604c, r16[ax]);
    r16[ax] = 0x00a0;
    push(r16[ax]);
    r16[dx] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r8[cl] = 0x0c;
    yield* sub_10021();
    push(r16[dx]);
    push(r16[ax]);
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r8[cl] = 0x0c;
    yield* sub_10021();
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_23d1();
    sp += 0x000a;
    r16[ax] = 0x00a0;
    push(r16[ax]);
    r16[dx] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    flags.carry = r16[ax] + 0x0001 >= 0x10000;
    r16[ax]++;
    r16[dx] += (0x0000 + flags.carry);
    r8[cl] = 0x0c;
    yield* sub_10021();
    push(r16[dx]);
    push(r16[ax]);
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r8[cl] = 0x0c;
    yield* sub_10021();
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_23d1();
    sp += 0x000a;
    r16[ax] = 0x008f;
    push(r16[ax]);
    r16[dx] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r8[cl] = 0x0c;
    yield* sub_10021();
    push(r16[dx]);
    push(r16[ax]);
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    flags.carry = r16[ax] + 0x0001 >= 0x10000;
    r16[ax]++;
    r16[dx] += (0x0000 + flags.carry);
    r8[cl] = 0x0c;
    yield* sub_10021();
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_23d1();
    sp += 0x000a;
    stop("stack_below");
    r16[ax] = 0x008f;
    push(r16[ax]);
    r16[dx] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    flags.carry = r16[ax] + 0x0001 >= 0x10000;
    r16[ax]++;
    r16[dx] += (0x0000 + flags.carry);
    r8[cl] = 0x0c;
    yield* sub_10021();
    stop("stack_below");
    push(r16[dx]);
    push(r16[ax]);
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    flags.carry = r16[ax] + 0x0001 >= 0x10000;
    r16[ax]++;
    r16[dx] += (0x0000 + flags.carry);
    r8[cl] = 0x0c;
    yield* sub_10021();
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_23d1();
    sp += 0x000a;
    stop("stack_below");
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r8[cl] = 0x0c;
    yield* sub_10021();
    if (r16s[dx] > signed16(memoryAGet16(ds, 0x8226)))
        { pc = 0x60c4; break; }
    if (r16[dx] != memoryAGet16(ds, 0x8226))
        { pc = 0x60b8; break; }
    if (r16[ax] > memoryAGet16(ds, 0x8224))
        { pc = 0x60c4; break; }
  case 0x60b8:
    memoryASet16(ds, 0x8220, 0x0000);
    memoryASet16(ds, 0x6c60, 0x0001);
  case 0x60c4:
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_60c8() // 01ed:41f8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ds, 0x824a);
    r16[ax] += memoryAGet16(ds, 0x5b14);
    memoryASet16(ds, 0x824a, r16[ax]);
    if (r16s[ax] < signed16(0x00c8))
        { pc = 0x60ef; break; }
    memoryASet16(ds, 0x824a, 0xfc19);
    yield* sub_df9e();
    r16[ax] += 0xff80;
    memoryASet16(ds, 0x8240, r16[ax]);
    memoryASet16(ds, 0x8242, 0xfe70);
  case 0x60ef:
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[ax] &= 0x0001;
    r16[ax] += 0x0016;
    memoryASet16(ds, 0x8248, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8240);
    imul16(memoryAGet16(ds, 0x5b14));
    memoryASet16(ds, 0x823c, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8242);
    imul16(memoryAGet16(ds, 0x5b14));
    memoryASet16(ds, 0x823e, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x823a);
    r16[dx] = memoryAGet16(ds, 0x8238);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x6ed6)))
        { pc = 0x612e; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x6ed6)))
        { pc = 0x6128; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x6ed4))
        { pc = 0x612e; break; }
  case 0x6128:
    memoryASet16(ds, 0x8220, 0x0000);
  case 0x612e:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_6130() // 01ed:4260
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    if (memoryAGet16(ds, 0x5daa))
        { pc = 0x617a; break; }
    if (memoryAGet16(ds, 0x8256))
        { pc = 0x617a; break; }
    memoryASet16(ds, 0x6f0c, 0x41f8);
    memoryASet16(ds, 0x6f0e, 0x3360);
    flags.carry = memoryAGet16(ds, 0x6ee2) + 0x0800 >= 0x10000;
    memoryASet16(ds, 0x6ee2, memoryAGet16(ds, 0x6ee2) + 0x0800);
    memoryASet16(ds, 0x6ee4, memoryAGet16(ds, 0x6ee4) + (0x0000 + flags.carry));
    r16[ax] = 0;
    memoryASet16(ds, 0x6efc, r16[ax]);
    memoryASet16(ds, 0x6efa, r16[ax]);
    r16[ax] = 0;
    memoryASet16(ds, 0x6efc, r16[ax]);
    memoryASet16(ds, 0x6efa, r16[ax]);
    memoryASet16(ds, 0x6f04, r16[ax]);
    memoryASet16(ds, 0x6f02, 0x0016);
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x617a:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_617c() // 01ed:42ac
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    memoryASet16(ds, 0x8252, 0x41f8);
    memoryASet16(ds, 0x8254, 0x3360);
    flags.carry = memoryAGet16(ds, 0x8228) + 0x0800 >= 0x10000;
    memoryASet16(ds, 0x8228, memoryAGet16(ds, 0x8228) + 0x0800);
    memoryASet16(ds, 0x822a, memoryAGet16(ds, 0x822a) + (0x0000 + flags.carry));
    r16[ax] = 0;
    memoryASet16(ds, 0x6efc, r16[ax]);
    memoryASet16(ds, 0x8240, r16[ax]);
    r16[ax] = 0;
    memoryASet16(ds, 0x6efc, r16[ax]);
    memoryASet16(ds, 0x6efa, r16[ax]);
    memoryASet16(ds, 0x824a, r16[ax]);
    memoryASet16(ds, 0x8248, 0x0016);
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[bp] = pop();
    sp += 2;
}
function* sub_61ba() // 01ed:42ea
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000c;
    push(r16[si]);
    push(r16[di]);
    if (memoryAGet16(ds, 0x6f0c) != 0x41f8)
        { pc = 0x61cd; break; }
    { pc = 0x645a; break; }
  case 0x61cd:
    memoryASet16(ds, 0x8258, 0x0000);
    r16[dx] = memoryAGet16(ds, 0x6ee8);
    r16[ax] = memoryAGet16(ds, 0x6ee6);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x6ef0);
    r16[ax] = memoryAGet16(ds, 0x6eee);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x6eec);
    r16[ax] = memoryAGet16(ds, 0x6eea);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x6ef4);
    r16[ax] = memoryAGet16(ds, 0x6ef2);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[di] = memoryAGet16(ss, r16[bp] - 2);
    { pc = 0x6452; break; }
  case 0x6215:
    r16[si] = memoryAGet16(ss, r16[bp] - 4);
    { pc = 0x6449; break; }
  case 0x621b:
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 12);
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 1390);
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    if (r16[ax])
        { pc = 0x6244; break; }
    { pc = 0x6448; break; }
  case 0x6244:
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx]--;
    if (r16[bx] <= 0x0019)
        { pc = 0x6250; break; }
    { pc = 0x6448; break; }
  case 0x6250:
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x6257; break; }
        case 2: { pc = 0x625d; break; }
        case 4: { pc = 0x625d; break; }
        case 6: { pc = 0x625d; break; }
        case 8: { pc = 0x625d; break; }
        case 10: { pc = 0x62b2; break; }
        case 12: { pc = 0x62b2; break; }
        case 14: { pc = 0x62b2; break; }
        case 16: { pc = 0x62b2; break; }
        case 18: { pc = 0x62b2; break; }
        case 20: { pc = 0x6310; break; }
        case 22: { pc = 0x6310; break; }
        case 24: { pc = 0x6310; break; }
        case 26: { pc = 0x6310; break; }
        case 28: { pc = 0x636a; break; }
        case 30: { pc = 0x636a; break; }
        case 32: { pc = 0x63a2; break; }
        case 34: { pc = 0x63cf; break; }
        case 36: { pc = 0x63cf; break; }
        case 38: { pc = 0x63cf; break; }
        case 40: { pc = 0x63cf; break; }
        case 42: { pc = 0x63fa; break; }
        case 44: { pc = 0x6432; break; }
        case 46: { pc = 0x6442; break; }
        case 48: { pc = 0x6432; break; }
        case 50: { pc = 0x6432; break; }
        default:
            stop("ind 01ed:4382");
    }
    break;
  case 0x6257:
    yield* sub_6130();
    { pc = 0x6448; break; }
  case 0x625d:
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 43674))
        { pc = 0x6274; break; }
    push(r16[si]);
    push(r16[di]);
    yield* sub_46c8();
    sp += 0x0004;
    { pc = 0x6448; break; }
  case 0x6274:
    if (signed16(memoryAGet16(ds, 0x6ef6)) <= signed16(0x0000))
        { pc = 0x6293; break; }
    r16[ax] = memoryAGet16(ds, 0x6ee0);
    r16[dx] = memoryAGet16(ds, 0x6ede);
    r16[dx] &= 0xf000;
    r16[ax] &= 0xffff;
    memoryASet16(ds, 0x6ede, r16[dx]);
    memoryASet16(ds, 0x6ee0, r16[ax]);
    { pc = 0x6448; break; }
  case 0x6293:
    r16[ax] = memoryAGet16(ds, 0x6ee0);
    r16[dx] = memoryAGet16(ds, 0x6ede);
    flags.carry = r16[dx] + 0x1000 >= 0x10000;
    r16[dx] += 0x1000;
    r16[ax] += (0x0000 + flags.carry);
    r16[dx] &= 0xf000;
    r16[ax] &= 0xffff;
    memoryASet16(ds, 0x6ede, r16[dx]);
    memoryASet16(ds, 0x6ee0, r16[ax]);
    { pc = 0x6448; break; }
  case 0x62b2:
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    push(memoryAGet16(ds, r16[bx] + 8218));
    yield* sub_2c22();
    sp++;
    sp++;
    r16[ax] = 0x0009;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    if (memoryAGet16(es, r16[bx]) >= 0x0131)
        { pc = 0x62f8; break; }
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x008f);
    { pc = 0x6448; break; }
  case 0x62f8:
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x0114);
    { pc = 0x6448; break; }
  case 0x6310:
    if (memoryAGet16(ss, r16[bp] - 10) != 0x000b)
        { pc = 0x631c; break; }
    memoryASet16(ds, 0xaa94, 0x0001);
  case 0x631c:
    if (memoryAGet16(ss, r16[bp] - 10) != 0x000c)
        { pc = 0x6328; break; }
    memoryASet16(ds, 0xaa9c, 0x0001);
  case 0x6328:
    if (memoryAGet16(ss, r16[bp] - 10) != 0x000d)
        { pc = 0x6334; break; }
    memoryASet16(ds, 0xaa96, 0x0001);
  case 0x6334:
    if (memoryAGet16(ss, r16[bp] - 10) != 0x000e)
        { pc = 0x6340; break; }
    memoryASet16(ds, 0xaa98, 0x0001);
  case 0x6340:
    r16[ax] = 0x2710;
    push(r16[ax]);
    yield* sub_2c22();
    sp++;
    sp++;
    r16[ax] = 0x000b;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x008f);
    { pc = 0x6448; break; }
  case 0x636a:
    if (memoryAGet16(ss, r16[bp] - 10) != 0x000f)
        { pc = 0x6375; break; }
    memoryASet16(ds, 0xaac8, memoryAGet16(ds, 0xaac8) + 0x0005);
  case 0x6375:
    if (memoryAGet16(ss, r16[bp] - 10) != 0x0010)
        { pc = 0x6381; break; }
    memoryASet16(ds, 0xaa9a, 0x0001);
  case 0x6381:
    r16[ax] = 0x000a;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x008f);
    { pc = 0x6448; break; }
  case 0x63a2:
    if (memoryAGet16(ds, 0x6f0c) == 0x3867)
        { pc = 0x63ad; break; }
    { pc = 0x6448; break; }
  case 0x63ad:
    r16[ax] = 0x000f;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, 0x6f0c, 0x40ef);
    memoryASet16(ds, 0x6f0e, 0x3360);
    r16[ax] = r16[di];
    r16[ax]++;
    r16[ax]++;
    memoryASet16(ds, 0x6f04, r16[ax]);
    memoryASet16(ds, 0x6f06, r16[si]);
    { pc = 0x6448; break; }
  case 0x63cf:
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43642, 0x0001);
    r16[ax] = 0x0020;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x008f);
    { pc = 0x6448; break; }
  case 0x63fa:
    yield* sub_43c4();
    if (memoryAGet16(ds, 0x8304) != 0x000b)
        { pc = 0x641b; break; }
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x01b2);
    { pc = 0x6448; break; }
  case 0x641b:
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x013b);
    { pc = 0x6448; break; }
  case 0x6432:
    memoryASet16(ds, 0x8258, 0x0001);
    memoryASet16(ds, 0x8218, r16[di]);
    memoryASet16(ds, 0x821a, r16[si]);
    { pc = 0x6448; break; }
  case 0x6442:
    memoryASet16(ds, 0x6c60, 0x0002);
  case 0x6448:
    r16[si]++;
  case 0x6449:
    if (r16s[si] > signed16(memoryAGet16(ss, r16[bp] - 8)))
        { pc = 0x6451; break; }
    { pc = 0x621b; break; }
  case 0x6451:
    r16[di]++;
  case 0x6452:
    if (r16s[di] > signed16(memoryAGet16(ss, r16[bp] - 6)))
        { pc = 0x645a; break; }
    { pc = 0x6215; break; }
  case 0x645a:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_6494() // 01ed:45c4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    r16[bx] = memoryAGet16(ds, r16[di]);
    r16[bx]--;
    r16[bx]--;
    if (r16[bx] <= 0x000d)
        { pc = 0x64ab; break; }
    { pc = 0x6569; break; }
  case 0x64ab:
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x64b2; break; }
        case 2: { pc = 0x6532; break; }
        case 4: { pc = 0x6532; break; }
        case 6: { pc = 0x6516; break; }
        case 8: { pc = 0x6516; break; }
        case 10: { pc = 0x6569; break; }
        case 12: { pc = 0x6569; break; }
        case 14: { pc = 0x6569; break; }
        case 16: { pc = 0x6569; break; }
        case 18: { pc = 0x6532; break; }
        case 20: { pc = 0x6569; break; }
        case 22: { pc = 0x6569; break; }
        case 24: { pc = 0x6569; break; }
        case 26: { pc = 0x654a; break; }
        default:
            stop("ind 01ed:45dd");
    }
    break;
  case 0x64b2:
    if (memoryAGet16(ds, r16[di] + 50) != 0x1a2c)
        { pc = 0x64bc; break; }
    { pc = 0x6569; break; }
  case 0x64bc:
    if (signed16(memoryAGet16(ds, r16[si] + 34)) <= signed16(0x0000))
        { pc = 0x64db; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 10);
    r16[dx] = memoryAGet16(ds, r16[si] + 8);
    flags.carry = r16[dx] + 0x0800 >= 0x10000;
    r16[dx] += 0x0800;
    r16[ax] += (0x0000 + flags.carry);
    if (r16s[ax] < signed16(memoryAGet16(ds, r16[di] + 10)))
        { pc = 0x64f7; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, r16[di] + 10)))
        { pc = 0x64db; break; }
    if (r16[dx] <= memoryAGet16(ds, r16[di] + 8))
        { pc = 0x64f7; break; }
  case 0x64db:
    memoryASet16(ds, r16[si] + 34, 0x0000);
    if (signed16(memoryAGet16(ds, r16[di] + 32)) <= signed16(0x0000))
        { pc = 0x64ed; break; }
    memoryASet16(ds, r16[si] + 32, 0x00f0);
    { pc = 0x64f2; break; }
  case 0x64ed:
    memoryASet16(ds, r16[si] + 32, 0xff10);
  case 0x64f2:
    r16[ax] = 0x001d;
    { pc = 0x6563; break; }
  case 0x64f7:
    memoryASet16(ds, r16[di] + 50, 0x1a2c);
    memoryASet16(ds, r16[di] + 42, 0x0000);
    memoryASet16(ds, r16[si] + 34, 0x0000);
    memoryASet16(ds, r16[si] + 50, 0x3867);
    r16[ax] = 0x001f;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    { pc = 0x6569; break; }
  case 0x6516:
    memoryASet16(ds, r16[si] + 34, 0x0000);
    if (signed16(memoryAGet16(ds, r16[di] + 32)) <= signed16(0x0000))
        { pc = 0x6528; break; }
    memoryASet16(ds, r16[si] + 32, 0x00f0);
    { pc = 0x652d; break; }
  case 0x6528:
    memoryASet16(ds, r16[si] + 32, 0xff10);
  case 0x652d:
    r16[ax] = 0x001d;
    { pc = 0x6563; break; }
  case 0x6532:
    if (memoryAGet16(ds, r16[di]) != 0x000b)
        { pc = 0x6545; break; }
    if (memoryAGet16(ds, r16[si] + 50) != 0x26fe)
        { pc = 0x6545; break; }
    memoryASet16(ds, r16[si] + 42, 0x0000);
    { pc = 0x6569; break; }
  case 0x6545:
    yield* sub_6130();
    { pc = 0x6569; break; }
  case 0x654a:
    memoryASet16(ds, r16[si] + 50, 0x26fe);
    r16[ax] = memoryAGet16(ds, r16[di] + 32);
    memoryASet16(ds, r16[si] + 32, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[di] + 34);
    memoryASet16(ds, r16[si] + 34, r16[ax]);
    memoryASet16(ds, r16[si] + 42, 0x0320);
    r16[ax] = 0x0028;
  case 0x6563:
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0x6569:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_658a() // 01ed:46ba
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    yield* sub_4805();
    r16[si] = r16[ax];
    memoryASet16(ds, r16[si], 0x000a);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, r16[si] + 4, r16[dx]);
    memoryASet16(ds, r16[si] + 6, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[dx] = memoryAGet16(ss, r16[bp] + 8);
    flags.carry = r16[dx] + 0x0900 >= 0x10000;
    r16[dx] += 0x0900;
    r16[ax] += (0x0000 + flags.carry);
    memoryASet16(ds, r16[si] + 8, r16[dx]);
    memoryASet16(ds, r16[si] + 10, r16[ax]);
    memoryASet16(ds, r16[si] + 50, 0x4808);
    memoryASet16(ds, r16[si] + 34, 0x0000);
    memoryASet16(ds, r16[si] + 52, 0x4849);
    memoryASet16(ds, r16[si] + 40, 0x006c);
    if (signed16(memoryAGet16(ds, 0x604c)) < signed16(0x0000))
        { pc = 0x6646; break; }
    memoryASet16(ds, r16[si] + 32, 0x0190);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r8[cl] = 0x0c;
    yield* sub_10042();
    r16[dx] = memoryAGet16(ss, r16[bp] + 10);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r8[cl] = 0x0c;
    yield* sub_10042();
    flags.carry = r16[ax] + 0x0001 >= 0x10000;
    r16[ax]++;
    r16[dx] += (0x0000 + flags.carry);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6c08);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_10433();
    r16[dx] = pop();
    r16[dx] += r16[ax];
    r16[dx]++;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[dx];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (memoryAGet16(ds, r16[bx] + 3834))
        { pc = 0x6619; break; }
    { pc = 0x66b5; break; }
  case 0x6619:
    r16[ax] = 0x0025;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, r16[si], 0x000d);
    memoryASet16(ds, r16[si] + 50, 0x47e8);
    memoryASet16(ds, r16[si] + 42, 0x0000);
    yield* sub_df9e();
    if (r16s[ax] <= signed16(0x0080))
        { pc = 0x663f; break; }
    memoryASet16(ds, r16[si] + 40, 0x006e);
    { pc = 0x66b5; break; }
  case 0x663f:
    memoryASet16(ds, r16[si] + 40, 0x006f);
    { pc = 0x66b5; break; }
  case 0x6646:
    memoryASet16(ds, r16[si] + 32, 0xfe70);
    r16[dx] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r8[cl] = 0x0c;
    yield* sub_10042();
    flags.carry = r16[ax] + 0x0001 >= 0x10000;
    r16[ax]++;
    r16[dx] += (0x0000 + flags.carry);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6c08);
    push(r16[dx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_10433();
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r8[cl] = 0x0c;
    yield* sub_10042();
    r16[dx] = pop();
    r16[dx] += r16[ax];
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[dx];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 6278))
        { pc = 0x66b5; break; }
    r16[ax] = 0x0025;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, r16[si], 0x000d);
    memoryASet16(ds, r16[si] + 50, 0x47e8);
    memoryASet16(ds, r16[si] + 42, 0x0000);
    yield* sub_df9e();
    if (r16s[ax] <= signed16(0x0080))
        { pc = 0x66b0; break; }
    memoryASet16(ds, r16[si] + 40, 0x006e);
    { pc = 0x66b5; break; }
  case 0x66b0:
    memoryASet16(ds, r16[si] + 40, 0x006f);
  case 0x66b5:
    r16[si] = pop();
    stop("stack_below");
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_6719() // 01ed:4849
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    if (memoryAGet16(ds, r16[di]) == 0x0001)
        { pc = 0x675a; break; }
    if (memoryAGet16(ds, r16[di]) == 0x000e)
        { pc = 0x675a; break; }
    r16[ax] = 0x0025;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    memoryASet16(ds, r16[si] + 50, 0x47e8);
    memoryASet16(ds, r16[si] + 52, 0x3360);
    memoryASet16(ds, r16[si] + 42, 0x0000);
    yield* sub_df9e();
    if (r16s[ax] <= signed16(0x0080))
        { pc = 0x6755; break; }
    memoryASet16(ds, r16[si] + 40, 0x006e);
    { pc = 0x675a; break; }
  case 0x6755:
    memoryASet16(ds, r16[si] + 40, 0x006f);
  case 0x675a:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_6a39() // 01ed:4b69
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0012;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ds, 0x6eda, 0x0001);
    memoryASet16(ds, 0x6f0c, 0x3867);
    memoryASet16(ds, 0x6f0e, 0x45c4);
    r16[ax] = 0;
    memoryASet16(ds, 0x6efc, r16[ax]);
    memoryASet16(ds, 0x6efa, r16[ax]);
    memoryASet16(ds, 0x6f02, 0x0004);
    memoryASet16(ds, 0x6edc, 0x0001);
    memoryASet16(ds, 0x5db4, 0x0001);
    memoryASet16(ds, 0x8216, 0x0000);
    memoryASet16(ss, r16[bp] - 2, 0x0001);
    memoryASet16(ds, 0x604c, 0x0001);
    r16[ax] = 0;
    memoryASet16(ds, 0x5b14, r16[ax]);
    r16[dx] = 0;
    memoryASet16(ds, 0x563e, r16[ax]);
    memoryASet16(ds, 0x5640, r16[dx]);
    memoryASet16(ds, 0x5135, r16[ax]);
    memoryASet16(ds, 0x5137, r16[dx]);
    r16[ax] = 0;
    memoryASet16(ds, 0x8256, r16[ax]);
    memoryASet16(ds, 0x5daa, r16[ax]);
    memoryASet16(ds, 0x6c60, r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_34bb();
    sp++;
    sp++;
    r16[ax] = memoryAGet16(ds, 0x6ee0);
    r16[dx] = memoryAGet16(ds, 0x6ede);
    flags.carry = r16[dx] + 0x6000 >= 0x10000;
    r16[dx] += 0x6000;
    r16[ax] += (0xffff + flags.carry);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ee4);
    r16[dx] = memoryAGet16(ds, 0x6ee2);
    flags.carry = r16[dx] + 0xb000 >= 0x10000;
    r16[dx] += 0xb000;
    r16[ax] += (0xffff + flags.carry);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x564c)))
        { pc = 0x6af3; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x564c)))
        { pc = 0x6ae5; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x564a))
        { pc = 0x6af3; break; }
  case 0x6ae5:
    r16[ax] = memoryAGet16(ds, 0x564c);
    r16[dx] = memoryAGet16(ds, 0x564a);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
  case 0x6af3:
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x5650)))
        { pc = 0x6b16; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x5650)))
        { pc = 0x6b08; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x564e))
        { pc = 0x6b16; break; }
  case 0x6b08:
    r16[ax] = memoryAGet16(ds, 0x5650);
    r16[dx] = memoryAGet16(ds, 0x564e);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
  case 0x6b16:
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x7fc0)))
        { pc = 0x6b39; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x7fc0)))
        { pc = 0x6b2b; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x7fbe))
        { pc = 0x6b39; break; }
  case 0x6b2b:
    r16[ax] = memoryAGet16(ds, 0x7fc0);
    r16[dx] = memoryAGet16(ds, 0x7fbe);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
  case 0x6b39:
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x7fc4)))
        { pc = 0x6b5c; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x7fc4)))
        { pc = 0x6b4e; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x7fc2))
        { pc = 0x6b5c; break; }
  case 0x6b4e:
    r16[ax] = memoryAGet16(ds, 0x7fc4);
    r16[dx] = memoryAGet16(ds, 0x7fc2);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
  case 0x6b5c:
    yield* sub_2109();
    yield* sub_8b5d();
    memoryASet16(ds, 0x821e, 0x0001);
    yield* sub_d606();
    yield* sub_2159();
    yield* sub_2159();
    yield* sub_8b19();
    r16[dx] = memoryAGet16(ds, 0x6ed2);
    r16[ax] = memoryAGet16(ds, 0x6ed0);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ds, 0x5656, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x6ed6);
    r16[ax] = memoryAGet16(ds, 0x6ed4);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ds, 0x5b12, r16[ax]);
  case 0x6b92:
    yield* sub_2109();
    r16[ax] = 0x7fca;
    push(ds);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 18;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 18;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[si] = 0x6eda;
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    { pc = 0x6cb9; break; }
  case 0x6bbf:
    if (memoryAGet16(ds, r16[si]))
        { pc = 0x6bc7; break; }
    { pc = 0x6cb3; break; }
  case 0x6bc7:
    r16[ax] = 0x8220;
    push(ds);
    push(r16[ax]);
    push(ds);
    push(r16[si]);
    r16[cx] = 0x0036;
    yield* sub_1016b();
    if (!memoryAGet16(ds, 0x8222))
        { pc = 0x6c18; break; }
    if (!memoryAGet16(ss, r16[bp] - 8))
        { pc = 0x6beb; break; }
    yield* sub_5166();
    if (!r16[ax])
        { pc = 0x6beb; break; }
    { pc = 0x6ca6; break; }
  case 0x6beb:
    yield* sub_490b();
    r16[ax] = 0;
    memoryASet16(ds, 0x823e, r16[ax]);
    memoryASet16(ds, 0x823c, r16[ax]);
    switch (memoryAGet16(ds, 0x8252))
    {
        case 0x19d3: yield* sub_38a3(); break;
        case 0x3867: yield* sub_5737(); break;
        case 0x3b8b: yield* sub_5a5b(); break;
        case 0x3c99: yield* sub_5b69(); break;
        case 0x3e12: yield* sub_5ce2(); break;
        case 0x3ec8: yield* sub_5d98(); break;
        case 0x4054: yield* sub_5f24(); break;
        case 0x41f8: yield* sub_60c8(); break;
        case 0x194f: yield* sub_381f(); break;
        case 0x1a2c: yield* sub_38fc(); break;
        case 0x40ef: yield* sub_5fbf(); break;
        default:
            stop("ind 01ed:4d26");
    }
    r16[ax] = memoryAGet16(ds, 0x823c);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8224) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8224, memoryAGet16(ds, 0x8224) + r16[ax]);
    memoryASet16(ds, 0x8226, memoryAGet16(ds, 0x8226) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x823e);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8228) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8228, memoryAGet16(ds, 0x8228) + r16[ax]);
    memoryASet16(ds, 0x822a, memoryAGet16(ds, 0x822a) + (r16[dx] + flags.carry));
    yield* sub_490b();
    { pc = 0x6ca6; break; }
  case 0x6c18:
    r16[dx] = memoryAGet16(ds, 0x8226);
    r16[ax] = memoryAGet16(ds, 0x8224);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x822a);
    r16[ax] = memoryAGet16(ds, 0x8228);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5656);
    r16[ax] += 0xfffe;
    if (r16s[ax] >= signed16(memoryAGet16(ss, r16[bp] - 4)))
        { pc = 0x6ca6; break; }
    r16[ax] = memoryAGet16(ds, 0x5b12);
    r16[ax] += 0xfffe;
    if (r16s[ax] >= signed16(memoryAGet16(ss, r16[bp] - 6)))
        { pc = 0x6ca6; break; }
    r16[ax] = memoryAGet16(ds, 0x5656);
    r16[ax] += 0x0017;
    if (r16s[ax] <= signed16(memoryAGet16(ss, r16[bp] - 4)))
        { pc = 0x6ca6; break; }
    r16[ax] = memoryAGet16(ds, 0x5b12);
    r16[ax] += 0x000c;
    if (r16s[ax] <= signed16(memoryAGet16(ss, r16[bp] - 6)))
        { pc = 0x6ca6; break; }
    memoryASet16(ds, 0x8222, 0x0001);
    if (memoryAGet16(ds, 0x8252) != 0x1a2c)
        { pc = 0x6c7c; break; }
    memoryASet16(ds, 0x8252, 0x19d3);
    memoryASet16(ds, 0x824a, 0x0000);
  case 0x6c7c:
    yield* sub_490b();
    r16[ax] = 0;
    memoryASet16(ds, 0x823e, r16[ax]);
    memoryASet16(ds, 0x823c, r16[ax]);
    switch (memoryAGet16(ds, 0x8252))
    {
        case 0x19d3: yield* sub_38a3(); break;
        case 0x3867: yield* sub_5737(); break;
        case 0x3b8b: yield* sub_5a5b(); break;
        case 0x3c99: yield* sub_5b69(); break;
        case 0x3e12: yield* sub_5ce2(); break;
        case 0x3ec8: yield* sub_5d98(); break;
        case 0x4054: yield* sub_5f24(); break;
        case 0x41f8: yield* sub_60c8(); break;
        case 0x194f: yield* sub_381f(); break;
        case 0x1a2c: yield* sub_38fc(); break;
        case 0x40ef: yield* sub_5fbf(); break;
        default:
            stop("ind 01ed:4db7");
    }
    r16[ax] = memoryAGet16(ds, 0x823c);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8224) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8224, memoryAGet16(ds, 0x8224) + r16[ax]);
    memoryASet16(ds, 0x8226, memoryAGet16(ds, 0x8226) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x823e);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x8228) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x8228, memoryAGet16(ds, 0x8228) + r16[ax]);
    memoryASet16(ds, 0x822a, memoryAGet16(ds, 0x822a) + (r16[dx] + flags.carry));
    yield* sub_490b();
  case 0x6ca6:
    push(ds);
    push(r16[si]);
    r16[ax] = 0x8220;
    push(ds);
    push(r16[ax]);
    r16[cx] = 0x0036;
    yield* sub_1016b();
  case 0x6cb3:
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
    r16[si] += 0x0036;
  case 0x6cb9:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    if (r16s[ax] >= signed16(memoryAGet16(ds, 0x5db4)))
        { pc = 0x6cc5; break; }
    { pc = 0x6bbf; break; }
  case 0x6cc5:
    yield* sub_52e8();
    r16[si] = 0x6eda;
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    { pc = 0x6d2f; break; }
  case 0x6cd2:
    if (!memoryAGet16(ds, r16[si]))
        { pc = 0x6d29; break; }
    if (!memoryAGet16(ds, r16[si] + 2))
        { pc = 0x6d29; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] = 0x0036;
    imul16(r16[dx]);
    r16[ax] += 0x6f10;
    r16[di] = r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[ax]++;
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    { pc = 0x6d20; break; }
  case 0x6cf3:
    if (!memoryAGet16(ds, r16[di]))
        { pc = 0x6d1a; break; }
    if (!memoryAGet16(ds, r16[di] + 2))
        { pc = 0x6d1a; break; }
    push(r16[di]);
    push(r16[si]);
    yield* sub_488d();
    sp += 0x0004;
    if (!r16[ax])
        { pc = 0x6d1a; break; }
    push(r16[di]);
    push(r16[si]);
    switch (memoryAGet16(ds, r16[si] + 52))
    {
        case 0x1a68: yield* sub_3938(); break;
        case 0x1bce: yield* sub_3a9e(); break;
        case 0x1d6e: yield* sub_3c3e(); break;
        case 0x1e94: yield* sub_3d64(); break;
        case 0x22bb: yield* sub_418b(); break;
        case 0x2927: yield* sub_47f7(); break;
        case 0x4849: yield* sub_6719(); break;
        case 0x3360: yield* sub_5230(); break;
        case 0x45c4: yield* sub_6494(); break;
        default:
            stop("ind 01ed:4e3c");
    }
    sp += 0x0004;
    push(r16[si]);
    push(r16[di]);
    switch (memoryAGet16(ds, r16[di] + 52))
    {
        case 0x1a68: yield* sub_3938(); break;
        case 0x1bce: yield* sub_3a9e(); break;
        case 0x1d6e: yield* sub_3c3e(); break;
        case 0x1e94: yield* sub_3d64(); break;
        case 0x22bb: yield* sub_418b(); break;
        case 0x2927: yield* sub_47f7(); break;
        case 0x4849: yield* sub_6719(); break;
        case 0x3360: yield* sub_5230(); break;
        case 0x45c4: yield* sub_6494(); break;
        default:
            stop("ind 01ed:4e44");
    }
    sp += 0x0004;
  case 0x6d1a:
    memoryASet16(ss, r16[bp] - 10, memoryAGet16(ss, r16[bp] - 10) + 1);
    r16[di] += 0x0036;
  case 0x6d20:
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x5db4)))
        { pc = 0x6cf3; break; }
  case 0x6d29:
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
    r16[si] += 0x0036;
  case 0x6d2f:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x5db4)))
        { pc = 0x6cd2; break; }
    r16[dx] = memoryAGet16(ds, 0x6ed2);
    r16[ax] = memoryAGet16(ds, 0x6ed0);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ds, 0x5656, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x6ed6);
    r16[ax] = memoryAGet16(ds, 0x6ed4);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ds, 0x5b12, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5db4);
    r16[dx] = 0x0036;
    imul16(r16[dx]);
    r16[ax] += 0x6ea4;
    r16[si] = r16[ax];
    r16[ax] = memoryAGet16(ds, 0x5db4);
    r16[ax]--;
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    { pc = 0x6d92; break; }
  case 0x6d6c:
    if (!memoryAGet16(ds, r16[si]))
        { pc = 0x6d8c; break; }
    if (!memoryAGet16(ds, r16[si] + 2))
        { pc = 0x6d8c; break; }
    push(memoryAGet16(ds, r16[si] + 40));
    push(memoryAGet16(ds, r16[si] + 10));
    push(memoryAGet16(ds, r16[si] + 8));
    push(memoryAGet16(ds, r16[si] + 6));
    push(memoryAGet16(ds, r16[si] + 4));
    yield* sub_2195();
    sp += 0x000a;
  case 0x6d8c:
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) - 1);
    r16[si] -= 0x0036;
  case 0x6d92:
    if (signed16(memoryAGet16(ss, r16[bp] - 8)) >= signed16(0x0000))
        { pc = 0x6d6c; break; }
    yield* sub_61ba();
    memoryASet16(ss, r16[bp] - 12, 0x7fd6);
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    { pc = 0x6dbd; break; }
  case 0x6da7:
    r16[bx] = memoryAGet16(ss, r16[bp] - 12);
    if (!memoryAGet16(ds, r16[bx] + 8))
        { pc = 0x6db6; break; }
    push(r16[bx]);
    yield* indirectCall(cs, memoryAGet16(ds, r16[bx] + 34));
    sp++;
    sp++;
  case 0x6db6:
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
    memoryASet16(ss, r16[bp] - 12, memoryAGet16(ss, r16[bp] - 12) + 0x0024);
  case 0x6dbd:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x8216)))
        { pc = 0x6da7; break; }
    yield* sub_2159();
    r16[ax] = 0x7fd0;
    push(ds);
    push(r16[ax]);
    r16[ax] = 0x7fca;
    push(ds);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    yield* sub_30c0();
    yield* sub_2b21();
    if (!r16[ax])
        { pc = 0x6df1; break; }
    r16[ax] = memoryAGet16(ds, 0x5137);
    r16[dx] = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, r16[dx]);
    memoryASet16(ds, 0x5640, r16[ax]);
  case 0x6df1:
    if (!memoryAGet16(ds, 0x6ebc))
        { pc = 0x6dfc; break; }
    r16[ax] = 0;
    { pc = 0x6e73; break; }
  case 0x6dfc:
    if (memoryAGet16(ds, 0x6c60))
        { pc = 0x6e0d; break; }
    if (!memoryAGet16(ds, 0x6eda))
        { pc = 0x6e0d; break; }
    { pc = 0x6b92; break; }
  case 0x6e0d:
    yield* sub_de4f();
    yield* sub_8b5d();
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    { pc = 0x6e28; break; }
  case 0x6e1a:
    r16[bx] = memoryAGet16(ss, r16[bp] - 4);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43678, 0x0000);
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + 1);
  case 0x6e28:
    if (signed16(memoryAGet16(ss, r16[bp] - 4)) < signed16(0x0004))
        { pc = 0x6e1a; break; }
    if (memoryAGet16(ds, 0x6c60))
        { pc = 0x6e70; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    if (r16[ax] == 0x0008)
        { pc = 0x6e62; break; }
    if (r16s[ax] > signed16(0x0008))
        { pc = 0x6e4b; break; }
    if (r16[ax] == 0x0003)
        { pc = 0x6e52; break; }
    if (r16[ax] == 0x0004)
        { pc = 0x6e5a; break; }
    { pc = 0x6e70; break; }
  case 0x6e4b:
    if (r16[ax] == 0x0010)
        { pc = 0x6e6a; break; }
    { pc = 0x6e70; break; }
  case 0x6e52:
    memoryASet16(ds, 0xaa9c, 0x0000);
    { pc = 0x6e70; break; }
  case 0x6e5a:
    memoryASet16(ds, 0xaa94, 0x0000);
    { pc = 0x6e70; break; }
  case 0x6e62:
    memoryASet16(ds, 0xaa96, 0x0000);
    { pc = 0x6e70; break; }
  case 0x6e6a:
    memoryASet16(ds, 0xaa98, 0x0000);
  case 0x6e70:
    r16[ax] = memoryAGet16(ds, 0x6c60);
  case 0x6e73:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_6e79() // 01ed:4fa9
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0032;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = 0x0009;
    push(r16[ax]);
    r16[ax] = 0x001c;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    r16[ax] = r16[bp] - 8;
    push(r16[ax]);
    r16[ax] = r16[bp] - 6;
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_76e1();
    sp += 0x0006;
    if (signed16(memoryAGet16(ss, r16[bp] - 6)) >= signed16(0x01f4))
        { pc = 0x6eba; break; }
    memoryASet16(ss, r16[bp] - 2, 0x0001);
  case 0x6eba:
    r16[ax] = r16[bp] - 8;
    push(r16[ax]);
    r16[ax] = r16[bp] - 6;
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_76e1();
    sp += 0x0006;
    if (signed16(memoryAGet16(ss, r16[bp] - 6)) >= signed16(0x01f4))
        { pc = 0x6ed8; break; }
    memoryASet16(ss, r16[bp] - 2, 0x0002);
  case 0x6ed8:
    r16[ax] = 0x2559;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2574;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x258f;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x25aa;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x25b7;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[si] = 0x0009;
  case 0x6f08:
    push(r16[si]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = 0x0003;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[si]++;
    r16[ax] = r16[si];
    if (r16[ax] != 0x000c)
        { pc = 0x6f31; break; }
    r16[si] = 0x0009;
  case 0x6f31:
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    r16[ax] = r16[bp] - 14;
    push(r16[ax]);
    push(r16[di]);
    yield* sub_76e1();
    sp += 0x0006;
    r16[ax] = r16[bp] - 26;
    push(ss);
    push(r16[ax]);
    push(r16[di]);
    push(ss);
    r16[ax] = r16[bp] - 32;
    push(r16[ax]);
    yield* sub_777f();
    sp += 0x0006;
    r16[ax] = r16[bp] - 32;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (!memoryAGet(ds, 0x502d))
        { pc = 0x6f66; break; }
    { pc = 0x70c1; break; }
  case 0x6f66:
    if (memoryAGet16(ss, r16[bp] - 24) != 0x0001)
        { pc = 0x6f08; break; }
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
  case 0x6f84:
    r16[ax] = r16[bp] - 26;
    push(ss);
    push(r16[ax]);
    push(r16[di]);
    push(ss);
    r16[ax] = r16[bp] - 38;
    push(r16[ax]);
    yield* sub_777f();
    sp += 0x0006;
    r16[ax] = r16[bp] - 38;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 24))
        { pc = 0x6f84; break; }
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x25d2;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x25f0;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x25fe;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
  case 0x6fca:
    push(r16[si]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = 0x0003;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[si]++;
    r16[ax] = r16[si];
    if (r16[ax] != 0x000c)
        { pc = 0x6ff3; break; }
    r16[si] = 0x0009;
  case 0x6ff3:
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    r16[ax] = r16[bp] - 18;
    push(r16[ax]);
    push(r16[di]);
    yield* sub_76e1();
    sp += 0x0006;
    r16[ax] = r16[bp] - 26;
    push(ss);
    push(r16[ax]);
    push(r16[di]);
    push(ss);
    r16[ax] = r16[bp] - 44;
    push(r16[ax]);
    yield* sub_777f();
    sp += 0x0006;
    r16[ax] = r16[bp] - 44;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (!memoryAGet(ds, 0x502d))
        { pc = 0x7028; break; }
    { pc = 0x70c1; break; }
  case 0x7028:
    if (memoryAGet16(ss, r16[bp] - 24) != 0x0001)
        { pc = 0x6fca; break; }
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
  case 0x7046:
    r16[ax] = r16[bp] - 26;
    push(ss);
    push(r16[ax]);
    push(r16[di]);
    push(ss);
    r16[ax] = r16[bp] - 50;
    push(r16[ax]);
    yield* sub_777f();
    sp += 0x0006;
    r16[ax] = r16[bp] - 50;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 24))
        { pc = 0x7046; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 18);
    r16[ax] -= memoryAGet16(ss, r16[bp] - 14);
    r16[bx] = 0x0004;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 20);
    r16[ax] -= memoryAGet16(ss, r16[bp] - 16);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ss, r16[bp] - 14);
    r16[ax] += memoryAGet16(ss, r16[bp] - 10);
    memoryASet16(ds, r16[bx] + 33386, r16[ax]);
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ss, r16[bp] - 18);
    r16[ax] -= memoryAGet16(ss, r16[bp] - 10);
    memoryASet16(ds, r16[bx] + 33392, r16[ax]);
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ss, r16[bp] - 16);
    r16[ax] += memoryAGet16(ss, r16[bp] - 12);
    memoryASet16(ds, r16[bx] + 33398, r16[ax]);
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ss, r16[bp] - 20);
    r16[ax] -= memoryAGet16(ss, r16[bp] - 12);
    memoryASet16(ds, r16[bx] + 33404, r16[ax]);
    memoryASet16(ds, 0x833e, 0x0002);
  case 0x70c1:
    yield* sub_7b0a();
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_70ca() // 01ed:51fa
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = r16[si];
    r16[ax] &= 0x007f;
    r16[si] = r16[ax];
    if (r16[ax] != 0x0001)
        { pc = 0x70ec; break; }
    r16[ax] = 0x2619;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x70ec:
    if (r16[si] != 0x000e)
        { pc = 0x70fd; break; }
    r16[ax] = 0x261d;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x70fd:
    if (r16[si] != 0x000f)
        { pc = 0x710e; break; }
    r16[ax] = 0x2622;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x710e:
    if (r16[si] != 0x001d)
        { pc = 0x711f; break; }
    r16[ax] = 0x2626;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x711f:
    if (r16[si] != 0x002a)
        { pc = 0x7130; break; }
    r16[ax] = 0x262b;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x7130:
    if (r16[si] != 0x0039)
        { pc = 0x7141; break; }
    r16[ax] = 0x2632;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x7141:
    if (r16[si] != 0x003a)
        { pc = 0x7152; break; }
    r16[ax] = 0x2638;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x7152:
    if (r16s[si] < signed16(0x003b))
        { pc = 0x7185; break; }
    if (r16s[si] > signed16(0x0044))
        { pc = 0x7185; break; }
    r16[ax] = 0x263f;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = r16[bp] - 4;
    push(r16[ax]);
    r16[ax] = r16[si];
    r16[ax] += 0xffc6;
    push(r16[ax]);
    yield* sub_f25a();
    sp += 0x0006;
    r16[ax] = r16[bp] - 4;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x7185:
    if (r16[si] != 0x0057)
        { pc = 0x7196; break; }
    r16[ax] = 0x2641;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x7196:
    if (r16[si] != 0x0059)
        { pc = 0x71a7; break; }
    r16[ax] = 0x2645;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x71a7:
    if (r16[si] != 0x0046)
        { pc = 0x71b8; break; }
    r16[ax] = 0x2649;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x71b8:
    if (r16[si] != 0x001c)
        { pc = 0x71c9; break; }
    r16[ax] = 0x2650;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x71c9:
    if (r16[si] != 0x0036)
        { pc = 0x71da; break; }
    r16[ax] = 0x2656;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x71da:
    if (r16[si] != 0x0037)
        { pc = 0x71eb; break; }
    r16[ax] = 0x265d;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x71eb:
    if (r16[si] != 0x0038)
        { pc = 0x71fc; break; }
    r16[ax] = 0x2663;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x71fc:
    if (r16[si] != 0x0047)
        { pc = 0x720d; break; }
    r16[ax] = 0x2667;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
    // gap 1 bytes
  case 0x720d:
    if (r16[si] != 0x0049)
        { pc = 0x721d; break; }
    r16[ax] = 0x266c;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x721d:
    if (r16[si] != 0x004f)
        { pc = 0x722d; break; }
    r16[ax] = 0x2671;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x722d:
    if (r16[si] != 0x0051)
        { pc = 0x723d; break; }
    r16[ax] = 0x2675;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x723d:
    if (r16[si] != 0x0052)
        { pc = 0x724d; break; }
    r16[ax] = 0x267a;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x724d:
    if (r16[si] != 0x0053)
        { pc = 0x725d; break; }
    r16[ax] = 0x267e;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x725d:
    if (r16[si] != 0x0045)
        { pc = 0x726d; break; }
    r16[ax] = 0x2682;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    { pc = 0x728b; break; }
  case 0x726d:
    r8[al] = memoryAGet(ds, r16[si] + 9294);
    cbw();
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(r16[ax]);
    yield* sub_d7b0();
    sp += 0x0006;
  case 0x728b:
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7290() // 01ed:53c0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0008;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0x000e;
    push(r16[ax]);
    r16[ax] = 0x0016;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x2688;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x269b;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x26ad;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x26bb;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x26c9;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x26d7;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x26e5;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x26f3;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2701;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x270f;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x271d;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x272b;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2739;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = memoryAGet16(ds, 0x8282);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[di] = 0;
    { pc = 0x7345; break; }
  case 0x732b:
    memoryASet16(ds, 0x8282, 0x001a);
    r16[ax] = r16[di];
    r16[ax] += 0x0007;
    memoryASet16(ds, 0x82f8, r16[ax]);
    r8[al] = memoryAGet(ds, r16[di] + 33514);
    cbw();
    push(r16[ax]);
    yield* sub_70ca();
    sp++;
    sp++;
    r16[di]++;
  case 0x7345:
    if (r16s[di] < signed16(0x0008))
        { pc = 0x732b; break; }
    memoryASet16(ds, 0x8282, 0x001a);
    memoryASet16(ds, 0x82f8, 0x000f);
    r8[al] = memoryAGet(ds, 0x8284);
    cbw();
    push(r16[ax]);
    yield* sub_70ca();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, 0x001a);
    memoryASet16(ds, 0x82f8, 0x0010);
    r8[al] = memoryAGet(ds, 0x8285);
    cbw();
    push(r16[ax]);
    yield* sub_70ca();
    sp++;
    sp++;
  case 0x7376:
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    memoryASet16(ds, 0x82f8, r16[ax]);
    yield* sub_8138();
    r16[bx] = 0x0100;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    memoryASet(ss, r16[bp] - 1, r8[dl]);
    if (r8s[dl] >= signed8(0x30))
        { pc = 0x7396; break; }
    { pc = 0x7458; break; }
  case 0x7396:
    if (r8s[dl] <= signed8(0x39))
        { pc = 0x739e; break; }
    { pc = 0x7458; break; }
  case 0x739e:
    r8[al] = memoryAGet(ss, r16[bp] - 1);
    cbw();
    r16[ax] += 0xffd0;
    r16[si] = r16[ax];
    r8[al] = memoryAGet(ss, r16[bp] - 1);
    cbw();
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r8[al] = memoryAGet(ss, r16[bp] - 1);
    cbw();
    r16[ax] += 0xffd0;
    r16[si] = r16[ax];
    r16[ax] = 0x274f;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    yield* sub_7b0a();
    memoryASet16(ss, r16[bp] - 8, 0xffff);
    { pc = 0x73f2; break; }
  case 0x73dc:
    if (memoryAGet16(ss, r16[bp] - 8) != 0x0079)
        { pc = 0x73e9; break; }
    memoryASet16(ss, r16[bp] - 8, 0xffff);
    { pc = 0x73f2; break; }
  case 0x73e9:
    if (memoryAGet16(ss, r16[bp] - 8) != 0x0029)
        { pc = 0x73f2; break; }
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
  case 0x73f2:
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r8[al] = memoryAGet(ds, r16[bx] + 20524);
    cbw();
    if (!r16[ax])
        { pc = 0x73dc; break; }
    yield* sub_7b0a();
    r16[ax] = 0x2764;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    if (r16s[si] >= signed16(0x0008))
        { pc = 0x7419; break; }
    r8[al] = memoryAGet(ss, r16[bp] - 8);
    memoryASet(ds, r16[si] + 33514, r8[al]);
  case 0x7419:
    if (r16[si] != 0x0008)
        { pc = 0x7424; break; }
    r8[al] = memoryAGet(ss, r16[bp] - 8);
    memoryASet(ds, 0x8284, r8[al]);
  case 0x7424:
    if (r16[si] != 0x0009)
        { pc = 0x742f; break; }
    r8[al] = memoryAGet(ss, r16[bp] - 8);
    memoryASet(ds, 0x8285, r8[al]);
  case 0x742f:
    r16[ax] = r16[si];
    r16[ax] += 0x0007;
    memoryASet16(ds, 0x82f8, r16[ax]);
    memoryASet16(ds, 0x8282, 0x001a);
    r16[ax] = 0x2778;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, 0x001a);
    push(memoryAGet16(ss, r16[bp] - 8));
    yield* sub_70ca();
    sp++;
    sp++;
    memoryASet(ss, r16[bp] - 1, 0x30);
  case 0x7458:
    if (signed8(memoryAGet(ss, r16[bp] - 1)) < signed8(0x30))
        { pc = 0x7467; break; }
    if (signed8(memoryAGet(ss, r16[bp] - 1)) > signed8(0x39))
        { pc = 0x7467; break; }
    { pc = 0x7376; break; }
  case 0x7467:
    memoryASet16(ds, 0x833e, 0x0000);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7473() // 01ed:55a3
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0006;
    push(r16[si]);
    push(r16[di]);
    r16[di] = 0;
    r16[si] = 0;
    r8[al] = memoryAGet(ds, 0x82ea);
    cbw();
    r16[bx] = r16[ax];
    if (!memoryAGet(ds, r16[bx] + 20524))
        { pc = 0x748f; break; }
    r16[si] = 0xffff;
  case 0x748f:
    r8[al] = memoryAGet(ds, 0x82ec);
    cbw();
    r16[bx] = r16[ax];
    if (!memoryAGet(ds, r16[bx] + 20524))
        { pc = 0x749f; break; }
    r16[di] = 0x0001;
  case 0x749f:
    r8[al] = memoryAGet(ds, 0x82ee);
    cbw();
    r16[bx] = r16[ax];
    if (!memoryAGet(ds, r16[bx] + 20524))
        { pc = 0x74af; break; }
    r16[si] = 0x0001;
  case 0x74af:
    r8[al] = memoryAGet(ds, 0x82f0);
    cbw();
    r16[bx] = r16[ax];
    if (!memoryAGet(ds, r16[bx] + 20524))
        { pc = 0x74bf; break; }
    r16[di] = 0xffff;
  case 0x74bf:
    r8[al] = memoryAGet(ds, 0x82eb);
    cbw();
    r16[bx] = r16[ax];
    if (!memoryAGet(ds, r16[bx] + 20524))
        { pc = 0x74d2; break; }
    r16[si] = 0xffff;
    r16[di] = 0x0001;
  case 0x74d2:
    r8[al] = memoryAGet(ds, 0x82f1);
    cbw();
    r16[bx] = r16[ax];
    if (!memoryAGet(ds, r16[bx] + 20524))
        { pc = 0x74e5; break; }
    r16[si] = 0xffff;
    r16[di] = 0xffff;
  case 0x74e5:
    r8[al] = memoryAGet(ds, 0x82ed);
    cbw();
    r16[bx] = r16[ax];
    if (!memoryAGet(ds, r16[bx] + 20524))
        { pc = 0x74f8; break; }
    r16[si] = 0x0001;
    r16[di] = 0x0001;
  case 0x74f8:
    r8[al] = memoryAGet(ds, 0x82ef);
    cbw();
    r16[bx] = r16[ax];
    if (!memoryAGet(ds, r16[bx] + 20524))
        { pc = 0x750b; break; }
    r16[si] = 0x0001;
    r16[di] = 0xffff;
  case 0x750b:
    r16[ax] = r16[si];
    r16[dx] = 0x0003;
    imul16(r16[dx]);
    r16[ax] += r16[di];
    r16[ax] -= 0xfffc;
    r16[bx] = r16[ax];
    if (r16[bx] > 0x0008)
        { pc = 0x7562; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x7525; break; }
        case 2: { pc = 0x752c; break; }
        case 4: { pc = 0x7533; break; }
        case 6: { pc = 0x753a; break; }
        case 8: { pc = 0x7541; break; }
        case 10: { pc = 0x7548; break; }
        case 12: { pc = 0x754f; break; }
        case 14: { pc = 0x7556; break; }
        case 16: { pc = 0x755d; break; }
        default:
            stop("ind 01ed:5650");
    }
    break;
  case 0x7525:
    memoryASet16(ss, r16[bp] - 6, 0x0007);
    { pc = 0x7562; break; }
  case 0x752c:
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    { pc = 0x7562; break; }
  case 0x7533:
    memoryASet16(ss, r16[bp] - 6, 0x0001);
    { pc = 0x7562; break; }
  case 0x753a:
    memoryASet16(ss, r16[bp] - 6, 0x0006);
    { pc = 0x7562; break; }
  case 0x7541:
    memoryASet16(ss, r16[bp] - 6, 0x0008);
    { pc = 0x7562; break; }
  case 0x7548:
    memoryASet16(ss, r16[bp] - 6, 0x0002);
    { pc = 0x7562; break; }
  case 0x754f:
    memoryASet16(ss, r16[bp] - 6, 0x0005);
    { pc = 0x7562; break; }
  case 0x7556:
    memoryASet16(ss, r16[bp] - 6, 0x0004);
    { pc = 0x7562; break; }
  case 0x755d:
    memoryASet16(ss, r16[bp] - 6, 0x0003);
  case 0x7562:
    r8[al] = memoryAGet(ds, 0x8284);
    cbw();
    r16[bx] = r16[ax];
    r8[al] = memoryAGet(ds, r16[bx] + 20524);
    cbw();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r8[al] = memoryAGet(ds, 0x8285);
    cbw();
    r16[bx] = r16[ax];
    r8[al] = memoryAGet(ds, r16[bx] + 20524);
    cbw();
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_75ab() // 01ed:56db
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000a;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    r16[ax] = 0x0003;
    interrupt(0x33);
    r16[di] = r16[cx];
    r16[si] = r16[dx];
    r16[ax] = r16[bx];
    r16[ax] &= 0x0001;
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[ax] = r16[bx];
    r16[ax] &= 0x0002;
    r16[ax] >>= 1;
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[ax] = r16[di];
    r16[ax] += 0xfec0;
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    if (r16s[ax] <= signed16(memoryAGet16(ds, 0x836c)))
        { pc = 0x75f9; break; }
    memoryASet16(ss, r16[bp] - 2, 0x0001);
    r16[ax] = memoryAGet16(ds, 0x836c);
    r16[ax] <<= 1;
    r16[dx] = r16[di];
    r16[dx] -= r16[ax];
    { pc = 0x761c; break; }
  case 0x75f9:
    r16[ax] = r16[di];
    r16[ax] += 0xfec0;
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[dx] = memoryAGet16(ds, 0x836c);
    r16[dx] = -r16[dx];
    if (r16s[ax] >= r16s[dx])
        { pc = 0x761e; break; }
    memoryASet16(ss, r16[bp] - 2, 0xffff);
    r16[ax] = memoryAGet16(ds, 0x836c);
    r16[ax] <<= 1;
    r16[dx] = r16[di];
    r16[dx] += r16[ax];
  case 0x761c:
    r16[di] = r16[dx];
  case 0x761e:
    r16[ax] = r16[si];
    r16[ax] += 0xff9c;
    if (r16s[ax] <= signed16(memoryAGet16(ds, 0x836c)))
        { pc = 0x7636; break; }
    memoryASet16(ss, r16[bp] - 4, 0x0001);
    r16[ax] = r16[si];
    r16[ax] -= memoryAGet16(ds, 0x836c);
    { pc = 0x7650; break; }
  case 0x7636:
    r16[ax] = r16[si];
    r16[ax] += 0xff9c;
    r16[dx] = memoryAGet16(ds, 0x836c);
    r16[dx] = -r16[dx];
    if (r16s[ax] >= r16s[dx])
        { pc = 0x7652; break; }
    memoryASet16(ss, r16[bp] - 4, 0xffff);
    r16[ax] = r16[si];
    r16[ax] += memoryAGet16(ds, 0x836c);
  case 0x7650:
    r16[si] = r16[ax];
  case 0x7652:
    r16[ax] = 0x0004;
    r16[cx] = r16[di];
    r16[dx] = r16[si];
    interrupt(0x33);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r16[dx] = 0x0003;
    imul16(r16[dx]);
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] -= 0xfffc;
    r16[bx] = r16[ax];
    if (r16[bx] > 0x0008)
        { pc = 0x76b4; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x7677; break; }
        case 2: { pc = 0x767e; break; }
        case 4: { pc = 0x7685; break; }
        case 6: { pc = 0x768c; break; }
        case 8: { pc = 0x7693; break; }
        case 10: { pc = 0x769a; break; }
        case 12: { pc = 0x76a1; break; }
        case 14: { pc = 0x76a8; break; }
        case 16: { pc = 0x76af; break; }
        default:
            stop("ind 01ed:57a2");
    }
    break;
  case 0x7677:
    memoryASet16(ss, r16[bp] - 10, 0x0007);
    { pc = 0x76b4; break; }
  case 0x767e:
    memoryASet16(ss, r16[bp] - 10, 0x0000);
    { pc = 0x76b4; break; }
  case 0x7685:
    memoryASet16(ss, r16[bp] - 10, 0x0001);
    { pc = 0x76b4; break; }
  case 0x768c:
    memoryASet16(ss, r16[bp] - 10, 0x0006);
    { pc = 0x76b4; break; }
  case 0x7693:
    memoryASet16(ss, r16[bp] - 10, 0x0008);
    { pc = 0x76b4; break; }
  case 0x769a:
    memoryASet16(ss, r16[bp] - 10, 0x0002);
    { pc = 0x76b4; break; }
  case 0x76a1:
    memoryASet16(ss, r16[bp] - 10, 0x0005);
    { pc = 0x76b4; break; }
  case 0x76a8:
    memoryASet16(ss, r16[bp] - 10, 0x0004);
    { pc = 0x76b4; break; }
  case 0x76af:
    memoryASet16(ss, r16[bp] - 10, 0x0003);
  case 0x76b4:
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = r16[bp] - 10;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_76e1() // 01ed:5811
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000a;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    r16[si] = memoryAGet16(ss, r16[bp] + 8);
    if (memoryAGet16(ss, r16[bp] + 4) != 0x0001)
        { pc = 0x7701; break; }
    memoryASet16(ss, r16[bp] - 8, 0x0001);
    memoryASet16(ss, r16[bp] - 10, 0x0002);
    { pc = 0x770b; break; }
  case 0x7701:
    memoryASet16(ss, r16[bp] - 8, 0x0004);
    memoryASet16(ss, r16[bp] - 10, 0x0008);
  case 0x770b:
    memoryASet16(ds, r16[di], 0x0000);
    memoryASet16(ds, r16[si], 0x0000);
    r16[ax] = 0x0201;
    push(r16[ax]);
    yield* sub_f134();
    sp++;
    sp++;
    push(r16[ax]);
    r16[ax] = 0x0201;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    flags.interrupts = 0;
  case 0x7728:
    r16[ax] = 0x0201;
    push(r16[ax]);
    yield* sub_f134();
    sp++;
    sp++;
    r8[ah] = 0x00;
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    if (!(memoryAGet16(ss, r16[bp] - 2) & r16[ax]))
        { pc = 0x7743; break; }
    r16[ax] = 0x0001;
    { pc = 0x7745; break; }
  case 0x7743:
    r16[ax] = 0;
  case 0x7745:
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    if (!(memoryAGet16(ss, r16[bp] - 2) & r16[ax]))
        { pc = 0x7755; break; }
    r16[ax] = 0x0001;
    { pc = 0x7757; break; }
  case 0x7755:
    r16[ax] = 0;
  case 0x7757:
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ds, r16[di], memoryAGet16(ds, r16[di]) + r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) + r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r16[ax] += memoryAGet16(ss, r16[bp] - 6);
    if (!r16[ax])
        { pc = 0x7778; break; }
    if (signed16(memoryAGet16(ds, r16[di])) >= signed16(0x01f4))
        { pc = 0x7778; break; }
    if (signed16(memoryAGet16(ds, r16[si])) < signed16(0x01f4))
        { pc = 0x7728; break; }
  case 0x7778:
    flags.interrupts = 1;
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_777f() // 01ed:58af
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000e;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    r16[ax] = r16[bp] - 4;
    push(r16[ax]);
    r16[ax] = r16[bp] - 2;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_76e1();
    sp += 0x0006;
    if (signed16(memoryAGet16(ss, r16[bp] - 2)) <= signed16(0x01f4))
        { pc = 0x77b9; break; }
    r16[ax] = 0x0001;
    { pc = 0x77bb; break; }
  case 0x77b9:
    r16[ax] = 0;
  case 0x77bb:
    push(r16[ax]);
    if (signed16(memoryAGet16(ss, r16[bp] - 4)) <= signed16(0x01f4))
        { pc = 0x77c8; break; }
    r16[ax] = 0x0001;
    { pc = 0x77ca; break; }
  case 0x77c8:
    r16[ax] = 0;
  case 0x77ca:
    r16[dx] = pop();
    r16[dx] |= r16[ax];
    if (!r16[dx])
        { pc = 0x77e7; break; }
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 33386);
    r16[ax]++;
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 33398);
    r16[ax]++;
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
  case 0x77e7:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 33392);
    if (r16s[ax] >= signed16(memoryAGet16(ss, r16[bp] - 2)))
        { pc = 0x77fb; break; }
    memoryASet16(ss, r16[bp] - 6, 0x0001);
    { pc = 0x780d; break; }
  case 0x77fb:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 33386);
    if (r16s[ax] <= signed16(memoryAGet16(ss, r16[bp] - 2)))
        { pc = 0x780d; break; }
    memoryASet16(ss, r16[bp] - 6, 0xffff);
  case 0x780d:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 33404);
    if (r16s[ax] >= signed16(memoryAGet16(ss, r16[bp] - 4)))
        { pc = 0x7821; break; }
    memoryASet16(ss, r16[bp] - 8, 0x0001);
    { pc = 0x7833; break; }
  case 0x7821:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 33398);
    if (r16s[ax] <= signed16(memoryAGet16(ss, r16[bp] - 4)))
        { pc = 0x7833; break; }
    memoryASet16(ss, r16[bp] - 8, 0xffff);
  case 0x7833:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] = 0x0003;
    imul16(r16[dx]);
    r16[ax] += memoryAGet16(ss, r16[bp] - 6);
    r16[ax] -= 0xfffc;
    r16[bx] = r16[ax];
    if (r16[bx] > 0x0008)
        { pc = 0x788c; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x784f; break; }
        case 2: { pc = 0x7856; break; }
        case 4: { pc = 0x785d; break; }
        case 6: { pc = 0x7864; break; }
        case 8: { pc = 0x786b; break; }
        case 10: { pc = 0x7872; break; }
        case 12: { pc = 0x7879; break; }
        case 14: { pc = 0x7880; break; }
        case 16: { pc = 0x7887; break; }
        default:
            stop("ind 01ed:597a");
    }
    break;
  case 0x784f:
    memoryASet16(ss, r16[bp] - 14, 0x0007);
    { pc = 0x788c; break; }
  case 0x7856:
    memoryASet16(ss, r16[bp] - 14, 0x0000);
    { pc = 0x788c; break; }
  case 0x785d:
    memoryASet16(ss, r16[bp] - 14, 0x0001);
    { pc = 0x788c; break; }
  case 0x7864:
    memoryASet16(ss, r16[bp] - 14, 0x0006);
    { pc = 0x788c; break; }
  case 0x786b:
    memoryASet16(ss, r16[bp] - 14, 0x0008);
    { pc = 0x788c; break; }
  case 0x7872:
    memoryASet16(ss, r16[bp] - 14, 0x0002);
    { pc = 0x788c; break; }
  case 0x7879:
    memoryASet16(ss, r16[bp] - 14, 0x0005);
    { pc = 0x788c; break; }
  case 0x7880:
    memoryASet16(ss, r16[bp] - 14, 0x0004);
    { pc = 0x788c; break; }
  case 0x7887:
    memoryASet16(ss, r16[bp] - 14, 0x0003);
  case 0x788c:
    r16[ax] = 0x0201;
    push(r16[ax]);
    yield* sub_f134();
    sp++;
    sp++;
    r8[ah] = 0x00;
    r16[di] = r16[ax];
    if (r16[si] != 0x0001)
        { pc = 0x78bc; break; }
    if (r16[ax] & 0x0010)
        { pc = 0x78a8; break; }
    r16[ax] = 0x0001;
    { pc = 0x78aa; break; }
  case 0x78a8:
    r16[ax] = 0;
  case 0x78aa:
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    if (r16[di] & 0x0020)
        { pc = 0x78b8; break; }
    r16[ax] = 0x0001;
    { pc = 0x78d9; break; }
  case 0x78b8:
    { pc = 0x78d7; break; }
    // gap 2 bytes
  case 0x78bc:
    if (r16[di] & 0x0040)
        { pc = 0x78c7; break; }
    r16[ax] = 0x0001;
    { pc = 0x78c9; break; }
  case 0x78c7:
    r16[ax] = 0;
  case 0x78c9:
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    if (r16[di] & 0x0080)
        { pc = 0x78d7; break; }
    r16[ax] = 0x0001;
    { pc = 0x78d9; break; }
  case 0x78d7:
    r16[ax] = 0;
  case 0x78d9:
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = r16[bp] - 14;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7909() // 01ed:5a39
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0020;
    if (!memoryAGet16(ds, 0x9732))
        { pc = 0x7920; break; }
    if (memoryAGet16(ds, 0x9732) == 0x0002)
        { pc = 0x7920; break; }
    { pc = 0x79c1; break; }
  case 0x7920:
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] <<= 1;
    r16[bx] = memoryAGet16(ds, r16[bx] + 33596);
    if (r16[bx] > 0x0003)
        { pc = 0x7997; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0x7935; break; }
        case 2: { pc = 0x794a; break; }
        case 4: { pc = 0x795f; break; }
        case 6: { pc = 0x7978; break; }
        default:
            stop("ind 01ed:5a60");
    }
    break;
  case 0x7935:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 14;
    push(r16[ax]);
    yield* sub_7473();
    sp += 0x0004;
    r16[ax] = r16[bp] - 14;
    { pc = 0x798f; break; }
  case 0x794a:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    yield* sub_75ab();
    sp += 0x0004;
    r16[ax] = r16[bp] - 20;
    { pc = 0x798f; break; }
  case 0x795f:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 26;
    push(r16[ax]);
    yield* sub_777f();
    sp += 0x0006;
    r16[ax] = r16[bp] - 26;
    { pc = 0x798f; break; }
  case 0x7978:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0002;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 32;
    push(r16[ax]);
    yield* sub_777f();
    sp += 0x0006;
    r16[ax] = r16[bp] - 32;
  case 0x798f:
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
  case 0x7997:
    if (memoryAGet16(ds, 0x9732) != 0x0002)
        { pc = 0x79ed; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] <<= 1;
    r16[ax] |= r16[dx];
    r16[ax] |= memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[bx] = memoryAGet16(ds, 0x8362);
    r8[al] = memoryAGet(ss, r16[bp] - 8);
    memoryASet(ds, r16[bx], r8[al]);
    memoryASet16(ds, 0x8362, memoryAGet16(ds, 0x8362) + 1);
    { pc = 0x79ed; break; }
  case 0x79c1:
    r16[bx] = memoryAGet16(ds, 0x8362);
    r8[al] = memoryAGet(ds, r16[bx]);
    cbw();
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    memoryASet16(ds, 0x8362, memoryAGet16(ds, 0x8362) + 1);
    r16[ax] &= 0x0001;
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[ax] &= 0x0002;
    r16[ax] = sar16(r16[ax], 0x0001);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[ax] &= 0x003c;
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] = sar16(r16[ax], 0x0001);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
  case 0x79ed:
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7b0a() // 01ed:5c3a
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0;
    memoryASet16(ds, 0x50ae, r16[ax]);
    memoryASet16(ds, 0x50ac, r16[ax]);
    r16[ax] = 0x0080;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0x502c;
    push(r16[ax]);
    yield* sub_f309();
    sp += 0x0006;
    r16[bp] = pop();
    sp += 2;
}
function* sub_7b28() // 01ed:5c58
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    flags.carry = r16[dx] + 0x000f >= 0x10000;
    r16[dx] += 0x000f;
    r16[ax] += (0x0000 + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_fdb4();
    sp += 0x0004;
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    memoryASet16(ss, r16[bp] - 2, r16[dx]);
    memoryASet16(ds, 0xa6de, r16[ax]);
    memoryASet16(ds, 0xa6e0, r16[dx]);
    r16[cx] = 0;
    r16[bx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    yield* sub_1044a();
    if (!flags.zero)
        { pc = 0x7b69; break; }
    r16[ax] = 0x278f;
    push(r16[ax]);
    yield* sub_3131();
    sp++;
    sp++;
  case 0x7b69:
    r16[si] = memoryAGet16(ss, r16[bp] - 4);
    if (!r16[si])
        { pc = 0x7b7c; break; }
    r16[di] = memoryAGet16(ss, r16[bp] - 2);
    r16[di]++;
    r16[si] = 0;
    memoryASet16(ss, r16[bp] - 4, r16[si]);
    memoryASet16(ss, r16[bp] - 2, r16[di]);
  case 0x7b7c:
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7b88() // 01ed:5cb8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000e;
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    memoryASet16(ss, r16[bp] - 12, 0x0000);
    memoryASet16(ss, r16[bp] - 14, 0x0000);
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = 0x3d00;
    interrupt(0x21);
    if (flags.carry)
        { pc = 0x7c1d; break; }
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[bx] = r16[ax];
    r16[cx] = 0;
    r16[dx] = 0;
    r16[ax] = 0x4202;
    interrupt(0x21);
    if (flags.carry)
        { pc = 0x7c1d; break; }
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    memoryASet16(ss, r16[bp] - 6, r16[dx]);
    r16[cx] = memoryAGet16(ss, r16[bp] - 6);
    r16[cx]++;
  case 0x7bd2:
    push(r16[cx]);
    r16[cx] = memoryAGet16(ss, r16[bp] - 14);
    r16[dx] = memoryAGet16(ss, r16[bp] - 12);
    r16[ax] = 0x4200;
    interrupt(0x21);
    push(ds);
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r16[cx] = 0xffff;
    r16[dx] = memoryAGet16(ss, r16[bp] - 8);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    ds = r16[ax];
    r8[ah] = 0x3f;
    interrupt(0x21);
    ds = pop();
    r16[cx] = pop();
    if (flags.carry)
        { pc = 0x7c1d; break; }
    if (r16[ax] != 0xffff)
        { pc = 0x7c1d; break; }
    push(r16[cx]);
    push(ds);
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r16[cx] = 0x0001;
    r16[dx] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] += 0xffff;
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    ds = r16[ax];
    r8[ah] = 0x3f;
    interrupt(0x21);
    ds = pop();
    r16[cx] = pop();
    memoryASet16(ss, r16[bp] - 10, memoryAGet16(ss, r16[bp] - 10) + 0x1000);
    memoryASet16(ss, r16[bp] - 14, memoryAGet16(ss, r16[bp] - 14) + 1);
    if (--r16[cx])
        { pc = 0x7bd2; break; }
  case 0x7c1d:
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r8[ah] = 0x3e;
    interrupt(0x21);
    r16[dx] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] = 0;
    flags.carry = r16[ax] + memoryAGet16(ss, r16[bp] - 4) >= 0x10000;
    r16[ax] += memoryAGet16(ss, r16[bp] - 4);
    r16[dx] += (0x0000 + flags.carry);
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7c33() // 01ed:5d63
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000a;
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    memoryASet16(ss, r16[bp] - 10, 0x0000);
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = 0x3c00;
    r16[cx] = 0;
    interrupt(0x21);
    if (flags.carry)
        { pc = 0x7ca9; break; }
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    if (!memoryAGet16(ss, r16[bp] + 12))
        { pc = 0x7c93; break; }
  case 0x7c64:
    push(ds);
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r16[cx] = 0x8000;
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    ds = r16[ax];
    r8[ah] = 0x40;
    interrupt(0x21);
    ds = pop();
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + 0x0800);
    flags.carry = memoryAGet16(ss, r16[bp] + 10) < 0x8000;
    memoryASet16(ss, r16[bp] + 10, memoryAGet16(ss, r16[bp] + 10) - 0x8000);
    memoryASet16(ss, r16[bp] + 12, memoryAGet16(ss, r16[bp] + 12) - (0x0000 + flags.carry));
    if (memoryAGet16(ss, r16[bp] + 12) > 0x0000)
        { pc = 0x7c64; break; }
    if (memoryAGet16(ss, r16[bp] + 10) >= 0x8000)
        { pc = 0x7c64; break; }
  case 0x7c93:
    push(ds);
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r16[cx] = memoryAGet16(ss, r16[bp] + 10);
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    ds = r16[ax];
    r8[ah] = 0x40;
    interrupt(0x21);
    ds = pop();
    { pc = 0x7ca9; break; }
  case 0x7ca9:
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r8[ah] = 0x3e;
    interrupt(0x21);
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7cb4() // 01ed:5de4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0008;
    push(r16[si]);
    r16[ax] = 0x8000;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f36e();
    sp += 0x0004;
    r16[si] = r16[ax];
    if (r16[ax] == 0xffff)
        { pc = 0x7d08; break; }
    push(r16[ax]);
    yield* sub_f02c();
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    memoryASet16(ss, r16[bp] - 2, r16[dx]);
    push(r16[dx]);
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_7b28();
    sp += 0x0004;
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    memoryASet16(ss, r16[bp] - 6, r16[dx]);
    push(r16[si]);
    yield* sub_e47b();
    sp++;
    sp++;
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_7b88();
    sp += 0x0006;
    r16[dx] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    { pc = 0x7d0c; break; }
  case 0x7d08:
    r16[dx] = 0;
    r16[ax] = 0;
  case 0x7d0c:
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7dee() // 01ed:5f1e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, 0x8358, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    memoryASet16(ds, 0x835e, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ds, 0x835a, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    memoryASet16(ds, 0x8360, r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax]++;
    r16[si] = r16[ax];
    { pc = 0x7e40; break; }
  case 0x7e2a:
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[si]++;
  case 0x7e40:
    if (r16s[si] < signed16(memoryAGet16(ss, r16[bp] + 8)))
        { pc = 0x7e2a; break; }
    r16[ax] = 0x0003;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 8));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax]++;
    r16[di] = r16[ax];
    { pc = 0x7eb3; break; }
  case 0x7e64:
    r16[ax] = 0x0004;
    push(r16[ax]);
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax]++;
    r16[si] = r16[ax];
    { pc = 0x7e97; break; }
  case 0x7e82:
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[si]++;
  case 0x7e97:
    if (r16s[si] < signed16(memoryAGet16(ss, r16[bp] + 8)))
        { pc = 0x7e82; break; }
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 8));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[di]++;
  case 0x7eb3:
    if (r16s[di] < signed16(memoryAGet16(ss, r16[bp] + 10)))
        { pc = 0x7e64; break; }
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax]++;
    r16[si] = r16[ax];
    { pc = 0x7eed; break; }
  case 0x7ed7:
    r16[ax] = 0x0007;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[si]++;
  case 0x7eed:
    if (r16s[si] < signed16(memoryAGet16(ss, r16[bp] + 8)))
        { pc = 0x7ed7; break; }
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 8));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax]++;
    memoryASet16(ds, 0x8354, r16[ax]);
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax]++;
    memoryASet16(ds, 0x82f8, r16[ax]);
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7f1e() // 01ed:604e
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[dx] = memoryAGet16(ds, 0x24ce);
    r16[dx] -= r16[ax];
    r16[di] = r16[dx];
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[dx] = memoryAGet16(ds, 0x24d0);
    r16[dx] -= r16[ax];
    r16[si] = r16[dx];
    r16[ax] = r16[si];
    r16[ax] += memoryAGet16(ss, r16[bp] + 6);
    r16[ax]++;
    push(r16[ax]);
    r16[ax] = r16[di];
    r16[ax] += memoryAGet16(ss, r16[bp] + 4);
    r16[ax]++;
    push(r16[ax]);
    push(r16[dx]);
    push(r16[di]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
}
function* sub_7f5c() // 01ed:608c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    { pc = 0x7f85; break; }
  case 0x7f66:
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    { pc = 0x7f7f; break; }
  case 0x7f6b:
    push(memoryAGet16(ss, r16[bp] + 12));
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[si]++;
  case 0x7f7f:
    if (r16s[si] <= signed16(memoryAGet16(ss, r16[bp] + 8)))
        { pc = 0x7f6b; break; }
    r16[di]++;
  case 0x7f85:
    if (r16s[di] <= signed16(memoryAGet16(ss, r16[bp] + 10)))
        { pc = 0x7f66; break; }
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7f8e() // 01ed:60be
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    if (r16s[di] <= signed16(0x0002))
        { pc = 0x7fc3; break; }
    if (r16s[si] <= signed16(0x0002))
        { pc = 0x7fb4; break; }
    r16[ax] = r16[si];
    r16[ax] += 0xfffe;
    push(r16[ax]);
    r16[ax] = r16[di];
    r16[ax] += 0xfffe;
    push(r16[ax]);
    yield* sub_7f8e();
    { pc = 0x7fd2; break; }
  case 0x7fb4:
    push(r16[si]);
    r16[ax] = r16[di];
    r16[ax] += 0xfffe;
    push(r16[ax]);
    yield* sub_7fea();
    sp += 0x0004;
    { pc = 0x7fd5; break; }
  case 0x7fc3:
    if (r16s[si] <= signed16(0x0002))
        { pc = 0x7fd5; break; }
    r16[ax] = r16[si];
    r16[ax] += 0xfffe;
    push(r16[ax]);
    push(r16[di]);
    yield* sub_801b();
  case 0x7fd2:
    sp += 0x0004;
  case 0x7fd5:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    push(r16[si]);
    push(r16[di]);
    yield* sub_7f1e();
    sp += 0x0004;
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_7fea() // 01ed:611a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    if (r16s[si] <= signed16(0x0002))
        { pc = 0x8005; break; }
    push(memoryAGet16(ss, r16[bp] + 6));
    r16[ax] = r16[si];
    r16[ax] += 0xfffe;
    push(r16[ax]);
    yield* sub_7fea();
    sp += 0x0004;
  case 0x8005:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    push(memoryAGet16(ss, r16[bp] + 6));
    push(r16[si]);
    yield* sub_7f1e();
    sp += 0x0004;
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_801b() // 01ed:614b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    if (r16s[si] <= signed16(0x0002))
        { pc = 0x8036; break; }
    r16[ax] = r16[si];
    r16[ax] += 0xfffe;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_801b();
    sp += 0x0004;
  case 0x8036:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    push(r16[si]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_7f1e();
    sp += 0x0004;
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_8138() // 01ed:6268
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
  case 0x813d:
    r16[si] = 0x0009;
    { pc = 0x8163; break; }
  case 0x8142:
    r16[ax] = r16[si];
    r16[si]++;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
  case 0x8163:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    r16[ax] &= 0x00ff;
    r16[di] = r16[ax];
    if (r16[ax])
        { pc = 0x817a; break; }
    if (r16s[si] < signed16(0x000d))
        { pc = 0x8142; break; }
  case 0x817a:
    if (!r16[di])
        { pc = 0x813d; break; }
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = 0;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_81a2() // 01ed:62d2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    { pc = 0x81e7; break; }
  case 0x81a9:
    if (memoryAGet(ss, r16[bp] - 1) != 0x0a)
        { pc = 0x81bb; break; }
    memoryASet16(ds, 0x82f8, memoryAGet16(ds, 0x82f8) + 1);
    r16[ax] = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, r16[ax]);
    { pc = 0x81e7; break; }
  case 0x81bb:
    if (memoryAGet(ss, r16[bp] - 1) != 0x0d)
        { pc = 0x81c9; break; }
    r16[ax] = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, r16[ax]);
    { pc = 0x81e7; break; }
  case 0x81c9:
    r8[al] = memoryAGet(ss, r16[bp] - 1);
    r8[ah] = 0x00;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(r16[ax]);
    yield* sub_d7b0();
    sp += 0x0006;
  case 0x81e7:
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ss, r16[bp] + 4, memoryAGet16(ss, r16[bp] + 4) + 1);
    r8[al] = memoryAGet(ds, r16[bx]);
    memoryASet(ss, r16[bp] - 1, r8[al]);
    if (r8[al])
        { pc = 0x81a9; break; }
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_81fa() // 01ed:632a
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f25a();
    sp += 0x0006;
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[bp] = pop();
    sp += 2;
}
function* sub_823b() // 01ed:636b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    r16[ax] = 0x8000;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f36e();
    sp += 0x0004;
    r16[si] = r16[ax];
    if (r16[ax] != 0xffff)
        { pc = 0x825c; break; }
    r16[dx] = 0;
    r16[ax] = 0;
    { pc = 0x8274; break; }
  case 0x825c:
    push(r16[si]);
    yield* sub_f02c();
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    memoryASet16(ss, r16[bp] - 2, r16[dx]);
    push(r16[si]);
    yield* sub_e47b();
    sp++;
    sp++;
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
  case 0x8274:
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_8346() // 01ed:6476
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f647();
    sp++;
    sp++;
    r16[ax] >>= 1;
    r16[dx] = memoryAGet16(ds, 0x24ce);
    r16[dx]++;
    r16[dx] -= r16[ax];
    memoryASet16(ds, 0x8282, r16[dx]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_81a2();
    sp++;
    sp++;
    r16[bp] = pop();
    sp += 2;
}
function* sub_8487() // 01ed:65b7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    r16[si] = 0;
  case 0x8490:
    yield* sub_8138();
    r16[ax] &= 0x00ff;
    push(r16[ax]);
    yield* sub_ec06();
    sp++;
    sp++;
    memoryASet(ss, r16[bp] - 1, r8[al]);
    if (r8[al] == 0x7f)
        { pc = 0x84a7; break; }
    if (r8[al] != 0x08)
        { pc = 0x84c8; break; }
  case 0x84a7:
    if (r16s[si] <= 0)
        { pc = 0x84c8; break; }
    r16[si]--;
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) - 1);
  case 0x84c8:
    if (signed8(memoryAGet(ss, r16[bp] - 1)) < signed8(0x20))
        { pc = 0x84fc; break; }
    if (signed8(memoryAGet(ss, r16[bp] - 1)) > signed8(0x7a))
        { pc = 0x84fc; break; }
    if (r16s[si] >= signed16(memoryAGet16(ss, r16[bp] + 6)))
        { pc = 0x84fc; break; }
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r8[al] = memoryAGet(ss, r16[bp] - 1);
    memoryASet(ds, r16[bx] + r16[si], r8[al]);
    r16[si]++;
    cbw();
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(r16[ax]);
    yield* sub_d7b0();
    sp += 0x0006;
  case 0x84fc:
    if (memoryAGet(ss, r16[bp] - 1) == 0x1b)
        { pc = 0x850a; break; }
    if (memoryAGet(ss, r16[bp] - 1) == 0x0d)
        { pc = 0x850a; break; }
    { pc = 0x8490; break; }
  case 0x850a:
    r16[di] = r16[si];
    { pc = 0x8515; break; }
  case 0x850e:
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet(ds, r16[bx] + r16[di], 0x00);
    r16[di]++;
  case 0x8515:
    if (r16s[di] < signed16(memoryAGet16(ss, r16[bp] + 6)))
        { pc = 0x850e; break; }
    if (memoryAGet(ss, r16[bp] - 1) != 0x0d)
        { pc = 0x8525; break; }
    r16[ax] = 0x0001;
    { pc = 0x8527; break; }
  case 0x8525:
    r16[ax] = 0;
  case 0x8527:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_852d() // 01ed:665d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[ax] = 0x27c4;
    push(r16[ax]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    r16[ax] = 0x0180;
    push(r16[ax]);
    r16[ax] = 0x8001;
    push(r16[ax]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f36e();
    sp += 0x0006;
    r16[si] = r16[ax];
    if (r16[ax] == 0xffff)
        { pc = 0x8569; break; }
    { pc = 0x85da; break; }
    // gap 1 bytes
  case 0x8569:
    memoryASet16(ds, 0x5143, 0x0001);
    memoryASet16(ds, 0x833e, 0x0000);
    memoryASet16(ds, 0x8340, 0x0002);
    r16[ax] = 0x0014;
    memoryASet16(ds, 0x826e, r16[ax]);
    memoryASet16(ds, 0x826c, r16[ax]);
    r16[ax] = 0x003c;
    memoryASet16(ds, 0x8274, r16[ax]);
    memoryASet16(ds, 0x8272, r16[ax]);
    r16[ax] = 0x0014;
    memoryASet16(ds, 0x827a, r16[ax]);
    memoryASet16(ds, 0x8278, r16[ax]);
    r16[ax] = 0x003c;
    memoryASet16(ds, 0x8280, r16[ax]);
    memoryASet16(ds, 0x827e, r16[ax]);
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
    { pc = 0x8676; break; }
  case 0x85da:
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x5143;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x833c;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x826a;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x8276;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x8270;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x827c;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x836c;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = 0x82ea;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x8284;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x8285;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    push(r16[si]);
    yield* sub_e47b();
    sp++;
    sp++;
  case 0x8676:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_8679() // 01ed:67a9
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[ax] = 0x27ce;
    push(r16[ax]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    r16[ax] = 0x0180;
    push(r16[ax]);
    r16[ax] = 0x8302;
    push(r16[ax]);
    r16[ax] = 0x8290;
    push(r16[ax]);
    yield* sub_f36e();
    sp += 0x0006;
    r16[si] = r16[ax];
    if (r16[ax] != 0xffff)
        { pc = 0x86b5; break; }
    { pc = 0x8751; break; }
  case 0x86b5:
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x5143;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x833c;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x826a;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x8276;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x8270;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x827c;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x836c;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = 0x82ea;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x8284;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x8285;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_ec32();
    sp += 0x0006;
    push(r16[si]);
    yield* sub_e47b();
    sp++;
    sp++;
  case 0x8751:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_8754() // 01ed:6884
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0010;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    r16[ax] = 0x8000;
    push(r16[ax]);
    push(r16[di]);
    yield* sub_f36e();
    sp += 0x0004;
    r16[si] = r16[ax];
    r16[ax] = 0x0004;
    push(r16[ax]);
    r16[ax] = r16[bp] - 4;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x8326;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_f4ff();
    sp += 0x0006;
    push(r16[si]);
    yield* sub_e47b();
    sp++;
    sp++;
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_7b28();
    sp += 0x0004;
    memoryASet16(ds, 0x8328, r16[ax]);
    memoryASet16(ds, 0x832a, r16[dx]);
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    memoryASet16(ss, r16[bp] - 10, r16[dx]);
    r16[ax] = 0x8000;
    push(r16[ax]);
    push(r16[di]);
    yield* sub_f36e();
    sp += 0x0004;
    r16[si] = r16[ax];
    push(r16[ax]);
    yield* sub_f02c();
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    memoryASet16(ss, r16[bp] - 6, r16[dx]);
    push(r16[si]);
    yield* sub_e47b();
    sp++;
    sp++;
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    yield* sub_fdb4();
    sp += 0x0004;
    memoryASet16(ds, 0x825a, r16[ax]);
    memoryASet16(ds, 0x825c, r16[dx]);
    memoryASet16(ss, r16[bp] - 16, r16[ax]);
    memoryASet16(ss, r16[bp] - 14, r16[dx]);
    r16[cx] = 0;
    r16[bx] = 0;
    r16[dx] = memoryAGet16(ds, 0x825c);
    r16[ax] = memoryAGet16(ds, 0x825a);
    yield* sub_1044a();
    if (!flags.zero)
        { pc = 0x880e; break; }
    r16[ax] = 0x27d8;
    push(r16[ax]);
    yield* sub_3131();
    sp++;
    sp++;
  case 0x880e:
    push(memoryAGet16(ds, 0x825c));
    push(memoryAGet16(ds, 0x825a));
    push(r16[di]);
    yield* sub_7b88();
    sp += 0x0006;
    r16[ax] = memoryAGet16(ds, 0x8326);
    r16[ax] += 0xfff8;
    memoryASet16(ds, 0x835c, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8326);
    if (r16[ax] == 0x000c)
        { pc = 0x884a; break; }
    if (r16[ax] == 0x000d)
        { pc = 0x8842; break; }
    if (r16[ax] == 0x000e)
        { pc = 0x883a; break; }
    { pc = 0x8850; break; }
  case 0x883a:
    memoryASet16(ds, 0x8356, 0x4679);
    { pc = 0x8850; break; }
  case 0x8842:
    memoryASet16(ds, 0x8356, 0x2345);
    { pc = 0x8850; break; }
  case 0x884a:
    memoryASet16(ds, 0x8356, 0x139d);
  case 0x8850:
    memoryASet16(ds, 0x96fa, 0x0009);
    r16[ax] = 0x0001;
    r8[cl] = memoryAGet(ds, 0x96fa);
    r16[ax] <<= r8[cl];
    r16[ax]--;
    memoryASet16(ds, 0x8348, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8356);
    r16[ax] <<= 1;
    r16[dx] = 0;
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_fdb4();
    sp += 0x0004;
    memoryASet16(ds, 0x8266, r16[ax]);
    memoryASet16(ds, 0x8268, r16[dx]);
    r16[cx] = 0;
    r16[bx] = 0;
    r16[ax] = memoryAGet16(ds, 0x8266);
    yield* sub_1044a();
    if (!flags.zero)
        { pc = 0x888e; break; }
    r16[ax] = 0x2801;
    push(r16[ax]);
    yield* sub_3131();
    sp++;
    sp++;
  case 0x888e:
    r16[ax] = 0;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8356));
    yield* sub_fdb4();
    sp += 0x0004;
    memoryASet16(ds, 0xa6d6, r16[ax]);
    memoryASet16(ds, 0xa6d8, r16[dx]);
    r16[cx] = 0;
    r16[bx] = 0;
    r16[ax] = memoryAGet16(ds, 0xa6d6);
    yield* sub_1044a();
    if (!flags.zero)
        { pc = 0x88b7; break; }
    r16[ax] = 0x282a;
    push(r16[ax]);
    yield* sub_3131();
    sp++;
    sp++;
  case 0x88b7:
    memoryASet16(ds, 0x82f6, 0x0000);
    memoryASet16(ds, 0x82f2, 0x0000);
    memoryASet16(ds, 0x82f4, 0x0000);
    yield* sub_8900();
    push(memoryAGet16(ds, 0x8268));
    push(memoryAGet16(ds, 0x8266));
    yield* sub_fcce();
    sp += 0x0004;
    push(memoryAGet16(ds, 0xa6d8));
    push(memoryAGet16(ds, 0xa6d6));
    yield* sub_fcce();
    sp += 0x0004;
    push(memoryAGet16(ss, r16[bp] - 14));
    push(memoryAGet16(ss, r16[bp] - 16));
    yield* sub_fcce();
    sp += 0x0004;
    r16[dx] = memoryAGet16(ss, r16[bp] - 10);
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_8900() // 01ed:6a30
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0008;
    push(r16[si]);
    push(r16[di]);
    r16[di] = 0x0102;
    memoryASet16(ss, r16[bp] - 8, 0x0001);
    r16[cx] = 0;
    r16[bx] = 0x0006;
    r16[dx] = ds;
    r16[ax] = 0x825a;
    yield* sub_10083();
    { pc = 0x8a1e; break; }
  case 0x8920:
    if (!memoryAGet16(ss, r16[bp] - 8))
        { pc = 0x894e; break; }
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[bx] = memoryAGet16(ds, 0x8328); es = memoryAGet16(ds, 0x832a);
    r8[al] = memoryAGet(ss, r16[bp] - 4);
    memoryASet(es, r16[bx], r8[al]);
    r16[cx] = 0;
    r16[bx] = 0x0001;
    r16[dx] = ds;
    r16[ax] = 0x8328;
    yield* sub_10083();
    { pc = 0x8a1e; break; }
  case 0x894e:
    if (memoryAGet16(ss, r16[bp] - 2) != 0x0100)
        { pc = 0x8973; break; }
    memoryASet16(ss, r16[bp] - 8, 0x0001);
    memoryASet16(ds, 0x96fa, 0x0009);
    r16[di] = 0x0102;
    r16[ax] = 0x0001;
    r8[cl] = memoryAGet(ds, 0x96fa);
    r16[ax] <<= r8[cl];
    r16[ax]--;
    memoryASet16(ds, 0x8348, r16[ax]);
    { pc = 0x8a1e; break; }
  case 0x8973:
    if (memoryAGet16(ss, r16[bp] - 2) < r16[di])
        { pc = 0x8986; break; }
    r8[al] = memoryAGet(ss, r16[bp] - 6);
    memoryASet(ds, 0x9734, r8[al]);
    push(memoryAGet16(ss, r16[bp] - 4));
    r16[ax] = 0x9735;
    { pc = 0x898c; break; }
  case 0x8986:
    push(memoryAGet16(ss, r16[bp] - 2));
    r16[ax] = 0x9734;
  case 0x898c:
    push(r16[ax]);
    yield* sub_8a32();
    sp += 0x0004;
    r16[si] = r16[ax];
    r8[al] = memoryAGet(ds, r16[si]);
    r8[ah] = 0x00;
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    { pc = 0x89b5; break; }
  case 0x899e:
    r8[al] = memoryAGet(ds, r16[si]);
    r16[bx] = memoryAGet16(ds, 0x8328); es = memoryAGet16(ds, 0x832a);
    memoryASet(es, r16[bx], r8[al]);
    r16[si]--;
    r16[cx] = 0;
    r16[bx] = 0x0001;
    r16[dx] = ds;
    r16[ax] = 0x8328;
    yield* sub_10083();
  case 0x89b5:
    if (r16[si] >= 0x9734)
        { pc = 0x899e; break; }
    if (r16[di] > memoryAGet16(ds, 0x8348))
        { pc = 0x8a18; break; }
    r16[bx] = r16[di];
    r16[ax] = 0;
    flags.carry = !!(r16[bx] & 0x8000);
    r16[bx] <<= 1;
    r16[ax] = rcl16(r16[ax], 0x0001);
    r16[dx] = memoryAGet16(ds, 0x8268);
    push(r16[bx]);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8266);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = memoryAGet16(ss, r16[bp] - 4);
    es = r16[dx];
    r16[tx] = r16[bx]; r16[bx] = r16[ax]; r16[ax] = r16[tx];
    memoryASet16(es, r16[bx], r16[ax]);
    r16[bx] = r16[di];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ds, 0xa6d8);
    r16[ax] = memoryAGet16(ds, 0xa6d6);
    yield* sub_1010b();
    r8[bl] = memoryAGet(ss, r16[bp] - 6);
    es = r16[dx];
    r16[tx] = r16[bx]; r16[bx] = r16[ax]; r16[ax] = r16[tx];
    memoryASet(es, r16[bx], r8[al]);
    r16[di]++;
    if (r16[di] != memoryAGet16(ds, 0x8348))
        { pc = 0x8a18; break; }
    r16[ax] = memoryAGet16(ds, 0x96fa);
    if (r16s[ax] >= signed16(memoryAGet16(ds, 0x8326)))
        { pc = 0x8a18; break; }
    memoryASet16(ds, 0x96fa, memoryAGet16(ds, 0x96fa) + 1);
    r16[cx] = memoryAGet16(ds, 0x96fa);
    r16[ax] = 0x0001;
    r16[ax] <<= r8[cl];
    r16[ax]--;
    memoryASet16(ds, 0x8348, r16[ax]);
  case 0x8a18:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
  case 0x8a1e:
    yield* sub_8aa4();
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    if (r16[ax] == 0x0101)
        { pc = 0x8a2c; break; }
    { pc = 0x8920; break; }
  case 0x8a2c:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_8a32() // 01ed:6b62
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = 0;
    { pc = 0x8a92; break; }
  case 0x8a3e:
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ds, 0xa6d8);
    r16[ax] = memoryAGet16(ds, 0xa6d6);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r8[al] = memoryAGet(es, r16[bx]);
    memoryASet(ds, r16[si], r8[al]);
    r16[si]++;
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = 0;
    flags.carry = !!(r16[bx] & 0x8000);
    r16[bx] <<= 1;
    r16[ax] = rcl16(r16[ax], 0x0001);
    r16[dx] = memoryAGet16(ds, 0x8268);
    push(r16[bx]);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8266);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] + 6, r16[ax]);
    r16[ax] = r16[di];
    r16[di]++;
    if (r16s[ax] < signed16(0x0fa0))
        { pc = 0x8a92; break; }
    r16[ax] = 0x2853;
    push(r16[ax]);
    yield* sub_e805();
    sp++;
    sp++;
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_e4a7();
    sp++;
    sp++;
  case 0x8a92:
    if (memoryAGet16(ss, r16[bp] + 6) > 0x00ff)
        { pc = 0x8a3e; break; }
    r8[al] = memoryAGet(ss, r16[bp] + 6);
    memoryASet(ds, r16[si], r8[al]);
    r16[ax] = r16[si];
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_8aa4() // 01ed:6bd4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    { pc = 0x8ade; break; }
  case 0x8aab:
    r16[bx] = memoryAGet16(ds, 0x825a); es = memoryAGet16(ds, 0x825c);
    r8[al] = memoryAGet(es, r16[bx]);
    cbw();
    r16[ax] &= 0x00ff;
    r16[si] = r16[ax];
    r16[cx] = 0;
    r16[bx] = 0x0001;
    r16[dx] = ds;
    r16[ax] = 0x825a;
    yield* sub_10083();
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x18;
    r8[cl] -= memoryAGet(ds, 0x82f6);
    yield* sub_10021();
    memoryASet16(ds, 0x82f2, memoryAGet16(ds, 0x82f2) | r16[ax]);
    memoryASet16(ds, 0x82f4, memoryAGet16(ds, 0x82f4) | r16[dx]);
    memoryASet16(ds, 0x82f6, memoryAGet16(ds, 0x82f6) + 0x0008);
  case 0x8ade:
    if (signed16(memoryAGet16(ds, 0x82f6)) <= signed16(0x0018))
        { pc = 0x8aab; break; }
    r8[cl] = 0x20;
    r8[cl] -= memoryAGet(ds, 0x96fa);
    r16[dx] = memoryAGet16(ds, 0x82f4);
    r16[ax] = memoryAGet16(ds, 0x82f2);
    yield* sub_10062();
    r16[di] = r16[ax];
    r8[cl] = memoryAGet(ds, 0x96fa);
    r16[dx] = memoryAGet16(ds, 0x82f4);
    r16[ax] = memoryAGet16(ds, 0x82f2);
    yield* sub_10021();
    memoryASet16(ds, 0x82f2, r16[ax]);
    memoryASet16(ds, 0x82f4, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x96fa);
    memoryASet16(ds, 0x82f6, memoryAGet16(ds, 0x82f6) - r16[ax]);
    r16[ax] = r16[di];
    r16[di] = pop();
    r16[si] = pop();
    stop("stack_below");
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_8b19() // 01ed:6c49
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = ds;
    es = r16[ax];
    r16[dx] = 0x2508;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = ds;
    es = r16[ax];
    r16[dx] = 0x2519;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = ds;
    es = r16[ax];
    r16[dx] = 0x253b;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[bp] = pop();
    sp += 2;
}
function* sub_8b5d() // 01ed:6c8d
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = ds;
    es = r16[ax];
    r16[dx] = 0x253b;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = ds;
    es = r16[ax];
    r16[dx] = 0x252a;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = ds;
    es = r16[ax];
    r16[dx] = 0x2519;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = ds;
    es = r16[ax];
    r16[dx] = 0x2508;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[bp] = pop();
    sp += 2;
}
function* sub_8bb6() // 01ed:6ce6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0068;
    push(r16[si]);
    push(r16[di]);
    push(ss);
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x254c;
    push(r16[ax]);
    r16[cx] = 0x000d;
    yield* sub_1016b();
    r16[ax] = 0x2871;
    push(r16[ax]);
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 32, r16[ax]);
    memoryASet16(ss, r16[bp] - 30, r16[dx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 32); es = memoryAGet16(ss, r16[bp] - 30);
    r16[ax] = memoryAGet16(es, r16[bx] + 46);
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    r16[ax] = memoryAGet16(es, r16[bx] + 16);
    memoryASet16(ds, 0x836e, r16[ax]);
    r16[ax] = memoryAGet16(es, r16[bx] + 28);
    memoryASet16(ds, 0x8352, r16[ax]);
    r16[ax] = memoryAGet16(es, r16[bx] + 34);
    memoryASet16(ds, 0x8342, r16[ax]);
    r16[ax] = memoryAGet16(es, r16[bx] + 40);
    memoryASet16(ds, 0x972e, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x0010;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(es, r16[bx] + 14));
    push(memoryAGet16(es, r16[bx] + 12));
    yield* sub_ff73();
    r16[dx] = memoryAGet16(ss, r16[bp] - 30);
    r16[dx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 32);
    memoryASet16(ds, 0x834e, r16[ax]);
    memoryASet16(ds, 0x8350, r16[dx]);
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    { pc = 0x8c9a; break; }
  case 0x8c51:
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = pop();
    imul16(memoryAGet16(es, r16[bx] + 2));
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, r16[bp] - 4) + r16[ax] >= 0x10000;
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + r16[ax]);
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + (r16[dx] + flags.carry));
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + 1);
  case 0x8c9a:
    r16[bx] = memoryAGet16(ss, r16[bp] - 32); es = memoryAGet16(ss, r16[bp] - 30);
    r16[ax] = memoryAGet16(es, r16[bx] + 40);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    if (r16s[ax] > signed16(memoryAGet16(ss, r16[bp] - 6)))
        { pc = 0x8c51; break; }
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    { pc = 0x8cc9; break; }
  case 0x8cb1:
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_7b28();
    sp += 0x0004;
    r16[bx] = memoryAGet16(ss, r16[bp] - 6);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 33504, r16[dx]);
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + 1);
  case 0x8cc9:
    if (signed16(memoryAGet16(ss, r16[bp] - 6)) < signed16(0x0005))
        { pc = 0x8cb1; break; }
    r16[ax] = 0x287a;
    push(r16[ax]);
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    if (!memoryAGet16(ss, r16[bp] - 12))
        { pc = 0x8cfa; break; }
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_8754();
    { pc = 0x8d01; break; }
  case 0x8cfa:
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_7cb4();
  case 0x8d01:
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 40, r16[ax]);
    memoryASet16(ss, r16[bp] - 38, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0xa6e0);
    r16[dx] = memoryAGet16(ds, 0xa6de);
    memoryASet16(ss, r16[bp] - 48, r16[dx]);
    memoryASet16(ss, r16[bp] - 46, r16[ax]);
    r16[ax] = 0x000d;
    interrupt(0x10);
    memoryASet16(ds, 0x35b4, 0xa000);
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    { pc = 0x8d3d; break; }
  case 0x8d28:
    push(memoryAGet16(ss, r16[bp] - 6));
    yield* sub_dfd4();
    sp++;
    sp++;
    es = memoryAGet16(ds, 0x35b4);
    memoryASet(es, 0x2000, 0x00);
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + 1);
  case 0x8d3d:
    if (signed16(memoryAGet16(ss, r16[bp] - 6)) < signed16(0x0004))
        { pc = 0x8d28; break; }
    r8[al] = 0x13;
    push(r16[ax]);
    r16[ax] = 0x03d4;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x18;
    push(r16[ax]);
    r16[ax] = 0x03d5;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = 0x03ce;
    push(r16[ax]);
    yield* sub_f4e7();
    sp += 0x0004;
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    { pc = 0x8dcf; break; }
  case 0x8d72:
    r16[ax] = 0;
    r16[dx] = 0x0010;
    push(r16[ax]);
    push(r16[dx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 32); es = memoryAGet16(ss, r16[bp] - 30);
    r16[cx] = memoryAGet16(es, r16[bx] + 2);
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    yield* sub_10433();
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_ff73();
    r16[dx] = memoryAGet16(ss, r16[bp] - 38);
    r16[dx] += r16[ax];
    memoryASet16(ss, r16[bp] - 50, r16[dx]);
    r16[ax] = 0x0001;
    r8[cl] = memoryAGet(ss, r16[bp] - 6);
    r16[ax] <<= r8[cl];
    r8[cl] = 0x08;
    r16[ax] <<= r8[cl];
    r16[dx] = 0x0002;
    r16[dx] |= r16[ax];
    push(r16[dx]);
    r16[ax] = 0x03c4;
    push(r16[ax]);
    yield* sub_f4e7();
    sp += 0x0004;
    r16[bx] = memoryAGet16(ss, r16[bp] - 32); es = memoryAGet16(ss, r16[bp] - 30);
    push(memoryAGet16(es, r16[bx]));
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0xa700;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 50));
    yield* sub_f321();
    sp += 0x000a;
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + 1);
  case 0x8dcf:
    if (signed16(memoryAGet16(ss, r16[bp] - 6)) < signed16(0x0004))
        { pc = 0x8d72; break; }
    r16[ax] = 0;
    r16[dx] = 0x0010;
    push(r16[ax]);
    push(r16[dx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 32); es = memoryAGet16(ss, r16[bp] - 30);
    push(memoryAGet16(es, r16[bx] + 20));
    push(memoryAGet16(es, r16[bx] + 18));
    yield* sub_ff73();
    r16[ax] += 0xa700;
    memoryASet16(ds, 0x82fe, 0x0000);
    memoryASet16(ds, 0x8300, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x0010;
    push(r16[ax]);
    push(r16[dx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 32); es = memoryAGet16(ss, r16[bp] - 30);
    push(memoryAGet16(es, r16[bx] + 32));
    push(memoryAGet16(es, r16[bx] + 30));
    yield* sub_ff73();
    r16[ax] += 0xa700;
    memoryASet16(ds, 0x8368, 0x0000);
    memoryASet16(ds, 0x836a, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x0010;
    push(r16[ax]);
    push(r16[dx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 32); es = memoryAGet16(ss, r16[bp] - 30);
    push(memoryAGet16(es, r16[bx] + 38));
    push(memoryAGet16(es, r16[bx] + 36));
    yield* sub_ff73();
    r16[ax] += 0xa700;
    memoryASet16(ds, 0x834a, 0x0000);
    memoryASet16(ds, 0x834c, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x0010;
    push(r16[ax]);
    push(r16[dx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 32); es = memoryAGet16(ss, r16[bp] - 30);
    push(memoryAGet16(es, r16[bx] + 10));
    push(memoryAGet16(es, r16[bx] + 8));
    yield* sub_ff73();
    r16[dx] = memoryAGet16(ss, r16[bp] - 30);
    r16[dx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 32);
    memoryASet16(ds, 0x8364, r16[ax]);
    memoryASet16(ds, 0x8366, r16[dx]);
    push(memoryAGet16(ss, r16[bp] - 46));
    push(memoryAGet16(ss, r16[bp] - 48));
    yield* sub_fcce();
    sp += 0x0004;
    r8[ah] = 0x10;
    r8[al] = 0x01;
    r8[bh] = 0x03;
    interrupt(0x10);
    r16[ax] = 0x000e;
    push(r16[ax]);
    r16[ax] = 0x004c;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = 0x03ce;
    push(r16[ax]);
    yield* sub_f4e7();
    sp += 0x0004;
    r16[ax] = 0x2884;
    push(r16[ax]);
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_f623();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    if (!memoryAGet16(ss, r16[bp] - 12))
        { pc = 0x8ebb; break; }
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_8754();
    { pc = 0x8ec2; break; }
  case 0x8ebb:
    r16[ax] = r16[bp] - 64;
    push(r16[ax]);
    yield* sub_7cb4();
  case 0x8ec2:
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 36, r16[ax]);
    memoryASet16(ss, r16[bp] - 34, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0xa6e0);
    r16[dx] = memoryAGet16(ds, 0xa6de);
    memoryASet16(ss, r16[bp] - 44, r16[dx]);
    memoryASet16(ss, r16[bp] - 42, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0;
    memoryASet16(ds, 0xa6da, r16[dx]);
    memoryASet16(ds, 0xa6dc, r16[ax]);
    memoryASet16(ds, 0x825e, r16[dx]);
    memoryASet16(ds, 0x8260, r16[ax]);
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    { pc = 0x9640; break; }
  case 0x8ef1:
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = pop();
    imul16(memoryAGet16(es, r16[bx] + 2));
    memoryASet16(ss, r16[bp] - 14, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx] + 6);
    r16[dx] = memoryAGet16(es, r16[bx] + 4);
    memoryASet16(ds, 0xa6da, r16[dx]);
    memoryASet16(ds, 0xa6dc, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = memoryAGet16(ds, 0x8260);
    r16[cx] = memoryAGet16(ds, 0x825e);
    r16[si] = r16[ax];
    es = r16[dx];
    memoryASet16(es, r16[si] + 4, r16[cx]);
    memoryASet16(es, r16[si] + 6, r16[bx]);
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    { pc = 0x9040; break; }
  case 0x8fa0:
    r16[ax] = 0;
    r16[dx] = 0x0010;
    push(r16[ax]);
    push(r16[dx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 32); es = memoryAGet16(ss, r16[bp] - 30);
    r16[cx] = memoryAGet16(es, r16[bx] + 6);
    r16[bx] = memoryAGet16(es, r16[bx] + 4);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    yield* sub_10433();
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_ff73();
    r16[dx] = memoryAGet16(ds, 0xa6dc);
    r16[dx] += memoryAGet16(ss, r16[bp] - 34);
    r16[dx] += r16[ax];
    r16[ax] = memoryAGet16(ds, 0xa6da);
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[cx] = r16[bp] - 84;
    r16[bx] += r16[cx];
    memoryASet16(ds, r16[bx], r16[ax]);
    memoryASet16(ds, r16[bx] + 2, r16[dx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[si] = memoryAGet16(ss, r16[bp] - 8);
    r16[si] <<= 1;
    r16[ax] = memoryAGet16(ds, 0x8260);
    r16[ax] += memoryAGet16(ds, r16[si] + 33504);
    r16[dx] = memoryAGet16(ds, 0x825e);
    memoryASet16(ds, r16[bx], r16[dx]);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 14));
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    push(memoryAGet16(ds, r16[bx]));
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 102;
    r16[bx] += r16[ax];
    push(memoryAGet16(ds, r16[bx]));
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 84;
    r16[bx] += r16[ax];
    push(memoryAGet16(ds, r16[bx]));
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 82;
    r16[bx] += r16[ax];
    push(memoryAGet16(ds, r16[bx]));
    yield* sub_f321();
    sp += 0x000a;
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
  case 0x9040:
    if (signed16(memoryAGet16(ss, r16[bp] - 8)) >= signed16(0x0005))
        { pc = 0x9049; break; }
    { pc = 0x8fa0; break; }
  case 0x9049:
    r16[ax] = memoryAGet16(ds, 0x825e);
    r16[ax] += memoryAGet16(ss, r16[bp] - 14);
    r16[dx] = memoryAGet16(ds, 0x8260);
    memoryASet16(ds, 0x825e, r16[ax]);
    memoryASet16(ds, 0x8260, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0020;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0020;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = pop();
    imul16(memoryAGet16(es, r16[bx] + 2));
    memoryASet16(ss, r16[bp] - 14, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0020;
    yield* sub_1010b();
    r16[bx] = memoryAGet16(ds, 0x8260);
    r16[cx] = memoryAGet16(ds, 0x825e);
    r16[si] = r16[ax];
    es = r16[dx];
    memoryASet16(es, r16[si] + 4, r16[cx]);
    memoryASet16(es, r16[si] + 6, r16[bx]);
    memoryASet16(ss, r16[bp] - 10, 0x0000);
    { pc = 0x9231; break; }
  case 0x90f3:
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[si] = memoryAGet16(ss, r16[bp] - 10);
    r16[si] <<= 1;
    r16[ax] = memoryAGet16(ds, 0x8260);
    r16[ax] += memoryAGet16(ds, r16[si] + 33504);
    r16[dx] = memoryAGet16(ds, 0x825e);
    memoryASet16(ds, r16[bx], r16[dx]);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 22, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 102;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 20, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 84;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 18, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 82;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 16, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 24, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx] + 2);
    memoryASet16(ss, r16[bp] - 26, r16[ax]);
    if (memoryAGet16(ss, r16[bp] - 10) != 0x0004)
        { pc = 0x91ae; break; }
    r16[ax] = 0x0001;
    { pc = 0x91b0; break; }
  case 0x91ae:
    r16[ax] = 0;
  case 0x91b0:
    r16[dx] = 0x00ff;
    imul16(r16[dx]);
    memoryASet(ss, r16[bp] - 27, r8[al]);
    push(r16[si]);
    push(r16[di]);
    push(ds);
    r16[di] = memoryAGet16(ss, r16[bp] - 22);
    r16[si] = memoryAGet16(ss, r16[bp] - 18);
    r16[bx] = memoryAGet16(ss, r16[bp] - 24);
    r16[dx] = memoryAGet16(ss, r16[bp] - 26);
    r16[ax] = memoryAGet16(ss, r16[bp] - 20);
    es = r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 16);
    ds = r16[ax];
    flags.direction = 0;
  case 0x91d2:
    r16[cx] = r16[bx];
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r8[al] = memoryAGet(ss, r16[bp] - 27);
    stosb_ESDI(r8[al]);
    flags.carry = r16[di] < r16[bx];
    r16[di] -= r16[bx];
    r16[di]--;
    r16[cx] = r16[bx];
    r16[cx]++;
    r8[al] = memoryAGet(ss, r16[bp] - 27);
    r8[al] = rcr8(r8[al], 0x01);
  case 0x91e5:
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = rcr8(r8[al], 0x01);
    memoryASet(es, r16[di], r8[al]);
    r16[di]++;
    if (--r16[cx])
        { pc = 0x91e5; break; }
    flags.carry = r16[di] < r16[bx];
    r16[di] -= r16[bx];
    r16[di]--;
    r16[cx] = r16[bx];
    r16[cx]++;
    r8[al] = memoryAGet(ss, r16[bp] - 27);
    r8[al] = rcr8(r8[al], 0x01);
  case 0x91fb:
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = rcr8(r8[al], 0x01);
    memoryASet(es, r16[di], r8[al]);
    r16[di]++;
    if (--r16[cx])
        { pc = 0x91fb; break; }
    r16[dx]--;
    if (r16[dx])
        { pc = 0x91d2; break; }
    ds = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx] + 2);
    r16[dx] = memoryAGet16(ds, r16[bx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[cx] = r16[bp] - 84;
    r16[bx] += r16[cx];
    memoryASet16(ds, r16[bx], r16[dx]);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    memoryASet16(ss, r16[bp] - 10, memoryAGet16(ss, r16[bp] - 10) + 1);
  case 0x9231:
    if (signed16(memoryAGet16(ss, r16[bp] - 10)) >= signed16(0x0005))
        { pc = 0x923a; break; }
    { pc = 0x90f3; break; }
  case 0x923a:
    r16[ax] = memoryAGet16(ds, 0x825e);
    r16[ax] += memoryAGet16(ss, r16[bp] - 14);
    r16[dx] = memoryAGet16(ds, 0x8260);
    memoryASet16(ds, 0x825e, r16[ax]);
    memoryASet16(ds, 0x8260, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0040;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0040;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = pop();
    imul16(memoryAGet16(es, r16[bx] + 2));
    memoryASet16(ss, r16[bp] - 14, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0040;
    yield* sub_1010b();
    r16[bx] = memoryAGet16(ds, 0x8260);
    r16[cx] = memoryAGet16(ds, 0x825e);
    r16[si] = r16[ax];
    es = r16[dx];
    memoryASet16(es, r16[si] + 4, r16[cx]);
    memoryASet16(es, r16[si] + 6, r16[bx]);
    memoryASet16(ss, r16[bp] - 10, 0x0000);
    { pc = 0x942a; break; }
  case 0x92e4:
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[si] = memoryAGet16(ss, r16[bp] - 10);
    r16[si] <<= 1;
    r16[ax] = memoryAGet16(ds, 0x8260);
    r16[ax] += memoryAGet16(ds, r16[si] + 33504);
    r16[dx] = memoryAGet16(ds, 0x825e);
    memoryASet16(ds, r16[bx], r16[dx]);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 22, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 102;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 20, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 84;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 18, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 82;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 16, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0040;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 24, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0040;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx] + 2);
    memoryASet16(ss, r16[bp] - 26, r16[ax]);
    if (memoryAGet16(ss, r16[bp] - 10) != 0x0004)
        { pc = 0x93af; break; }
    r16[ax] = 0x0001;
    { pc = 0x93b1; break; }
  case 0x93af:
    r16[ax] = 0;
  case 0x93b1:
    r16[dx] = 0x00ff;
    imul16(r16[dx]);
    memoryASet(ss, r16[bp] - 27, r8[al]);
    push(r16[si]);
    push(r16[di]);
    push(ds);
    r16[di] = memoryAGet16(ss, r16[bp] - 22);
    r16[si] = memoryAGet16(ss, r16[bp] - 18);
    r16[bx] = memoryAGet16(ss, r16[bp] - 24);
    r16[dx] = memoryAGet16(ss, r16[bp] - 26);
    r16[ax] = memoryAGet16(ss, r16[bp] - 20);
    es = r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 16);
    ds = r16[ax];
    flags.direction = 0;
  case 0x93d3:
    r16[cx] = r16[bx];
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    flags.carry = r16[di] < r16[bx];
    r16[di] -= r16[bx];
    r16[cx] = r16[bx];
    r8[al] = memoryAGet(ss, r16[bp] - 27);
    r8[al] = rcr8(r8[al], 0x01);
  case 0x93e0:
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = rcr8(r8[al], 0x01);
    memoryASet(es, r16[di], r8[al]);
    r16[di]++;
    if (--r16[cx])
        { pc = 0x93e0; break; }
    flags.carry = r16[di] < r16[bx];
    r16[di] -= r16[bx];
    r16[cx] = r16[bx];
    r8[al] = memoryAGet(ss, r16[bp] - 27);
    r8[al] = rcr8(r8[al], 0x01);
  case 0x93f4:
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = rcr8(r8[al], 0x01);
    memoryASet(es, r16[di], r8[al]);
    r16[di]++;
    if (--r16[cx])
        { pc = 0x93f4; break; }
    r16[dx]--;
    if (r16[dx])
        { pc = 0x93d3; break; }
    ds = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx] + 2);
    r16[dx] = memoryAGet16(ds, r16[bx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[cx] = r16[bp] - 84;
    r16[bx] += r16[cx];
    memoryASet16(ds, r16[bx], r16[dx]);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    memoryASet16(ss, r16[bp] - 10, memoryAGet16(ss, r16[bp] - 10) + 1);
  case 0x942a:
    if (signed16(memoryAGet16(ss, r16[bp] - 10)) >= signed16(0x0005))
        { pc = 0x9433; break; }
    { pc = 0x92e4; break; }
  case 0x9433:
    r16[ax] = memoryAGet16(ds, 0x825e);
    r16[ax] += memoryAGet16(ss, r16[bp] - 14);
    r16[dx] = memoryAGet16(ds, 0x8260);
    memoryASet16(ds, 0x825e, r16[ax]);
    memoryASet16(ds, 0x8260, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0060;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0060;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = pop();
    imul16(memoryAGet16(es, r16[bx] + 2));
    memoryASet16(ss, r16[bp] - 14, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0060;
    yield* sub_1010b();
    r16[bx] = memoryAGet16(ds, 0x8260);
    r16[cx] = memoryAGet16(ds, 0x825e);
    r16[si] = r16[ax];
    es = r16[dx];
    memoryASet16(es, r16[si] + 4, r16[cx]);
    memoryASet16(es, r16[si] + 6, r16[bx]);
    memoryASet16(ss, r16[bp] - 10, 0x0000);
    { pc = 0x9623; break; }
  case 0x94dd:
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[si] = memoryAGet16(ss, r16[bp] - 10);
    r16[si] <<= 1;
    r16[ax] = memoryAGet16(ds, 0x8260);
    r16[ax] += memoryAGet16(ds, r16[si] + 33504);
    r16[dx] = memoryAGet16(ds, 0x825e);
    memoryASet16(ds, r16[bx], r16[dx]);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 22, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 102;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 20, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 84;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 18, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 82;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 16, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0060;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 24, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x05;
    yield* sub_10021();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(ds, 0x834e);
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0060;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx] + 2);
    memoryASet16(ss, r16[bp] - 26, r16[ax]);
    if (memoryAGet16(ss, r16[bp] - 10) != 0x0004)
        { pc = 0x95a8; break; }
    r16[ax] = 0x0001;
    { pc = 0x95aa; break; }
  case 0x95a8:
    r16[ax] = 0;
  case 0x95aa:
    r16[dx] = 0x00ff;
    imul16(r16[dx]);
    memoryASet(ss, r16[bp] - 27, r8[al]);
    push(r16[si]);
    push(r16[di]);
    push(ds);
    r16[di] = memoryAGet16(ss, r16[bp] - 22);
    r16[si] = memoryAGet16(ss, r16[bp] - 18);
    r16[bx] = memoryAGet16(ss, r16[bp] - 24);
    r16[dx] = memoryAGet16(ss, r16[bp] - 26);
    r16[ax] = memoryAGet16(ss, r16[bp] - 20);
    es = r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 16);
    ds = r16[ax];
    flags.direction = 0;
  case 0x95cc:
    r16[cx] = r16[bx];
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    flags.carry = r16[di] < r16[bx];
    r16[di] -= r16[bx];
    r16[cx] = r16[bx];
    r8[al] = memoryAGet(ss, r16[bp] - 27);
    r8[al] = rcr8(r8[al], 0x01);
  case 0x95d9:
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = rcr8(r8[al], 0x01);
    memoryASet(es, r16[di], r8[al]);
    r16[di]++;
    if (--r16[cx])
        { pc = 0x95d9; break; }
    flags.carry = r16[di] < r16[bx];
    r16[di] -= r16[bx];
    r16[cx] = r16[bx];
    r8[al] = memoryAGet(ss, r16[bp] - 27);
    r8[al] = rcr8(r8[al], 0x01);
  case 0x95ed:
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = rcr8(r8[al], 0x01);
    memoryASet(es, r16[di], r8[al]);
    r16[di]++;
    if (--r16[cx])
        { pc = 0x95ed; break; }
    r16[dx]--;
    if (r16[dx])
        { pc = 0x95cc; break; }
    ds = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 104;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx] + 2);
    r16[dx] = memoryAGet16(ds, r16[bx]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 10);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[cx] = r16[bp] - 84;
    r16[bx] += r16[cx];
    memoryASet16(ds, r16[bx], r16[dx]);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    memoryASet16(ss, r16[bp] - 10, memoryAGet16(ss, r16[bp] - 10) + 1);
  case 0x9623:
    if (signed16(memoryAGet16(ss, r16[bp] - 10)) >= signed16(0x0005))
        { pc = 0x962c; break; }
    { pc = 0x94dd; break; }
  case 0x962c:
    r16[ax] = memoryAGet16(ds, 0x825e);
    r16[ax] += memoryAGet16(ss, r16[bp] - 14);
    r16[dx] = memoryAGet16(ds, 0x8260);
    memoryASet16(ds, 0x825e, r16[ax]);
    memoryASet16(ds, 0x8260, r16[dx]);
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + 1);
  case 0x9640:
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    if (r16s[ax] >= signed16(memoryAGet16(ds, 0x972e)))
        { pc = 0x964c; break; }
    { pc = 0x8ef1; break; }
  case 0x964c:
    push(memoryAGet16(ss, r16[bp] - 42));
    push(memoryAGet16(ss, r16[bp] - 44));
    yield* sub_fcce();
    sp += 0x0004;
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_9751() // 01ed:7881
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000a;
    push(r16[si]);
    push(r16[di]);
    r16[bx] = memoryAGet16(ss, r16[bp] + 4); es = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(es, r16[bx] + 2);
    r16[dx] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 4, r16[dx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x0002;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_ff73();
    r16[ax] <<= 1;
    r16[dx] = memoryAGet16(ss, r16[bp] + 10);
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    memoryASet16(ss, r16[bp] - 10, r16[bx]);
    memoryASet16(ss, r16[bp] - 8, r16[dx]);
    memoryASet16(ss, r16[bp] + 4, memoryAGet16(ss, r16[bp] + 4) + 0x0004);
  case 0x978d:
    r16[bx] = memoryAGet16(ss, r16[bp] + 4); es = memoryAGet16(ss, r16[bp] + 6);
    r16[di] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] + 4, memoryAGet16(ss, r16[bp] + 4) + 0x0002);
    if (r16[di] == 0xfefe)
        { pc = 0x97a9; break; }
    r16[bx] = memoryAGet16(ss, r16[bp] + 8); es = memoryAGet16(ss, r16[bp] + 10);
    memoryASet16(es, r16[bx], r16[di]);
    memoryASet16(ss, r16[bp] + 8, memoryAGet16(ss, r16[bp] + 8) + 0x0002);
    { pc = 0x97d5; break; }
  case 0x97a9:
    r16[bx] = memoryAGet16(ss, r16[bp] + 4); es = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    memoryASet16(ss, r16[bp] + 4, memoryAGet16(ss, r16[bp] + 4) + 0x0002);
    r16[bx] = memoryAGet16(ss, r16[bp] + 4); es = memoryAGet16(ss, r16[bp] + 6);
    r16[di] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] + 4, memoryAGet16(ss, r16[bp] + 4) + 0x0002);
    r16[si] = 0x0001;
    { pc = 0x97d0; break; }
  case 0x97c5:
    r16[bx] = memoryAGet16(ss, r16[bp] + 8); es = memoryAGet16(ss, r16[bp] + 10);
    memoryASet16(es, r16[bx], r16[di]);
    memoryASet16(ss, r16[bp] + 8, memoryAGet16(ss, r16[bp] + 8) + 0x0002);
    r16[si]++;
  case 0x97d0:
    if (r16[si] <= memoryAGet16(ss, r16[bp] - 6))
        { pc = 0x97c5; break; }
  case 0x97d5:
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    if (r16[ax] < memoryAGet16(ss, r16[bp] - 10))
        { pc = 0x978d; break; }
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_97e3() // 01ed:7913
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x003c;
    push(r16[si]);
    push(ss);
    r16[ax] = r16[bp] - 14;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x28e2;
    push(r16[ax]);
    r16[cx] = 0x000d;
    yield* sub_1016b();
    push(ss);
    r16[ax] = r16[bp] - 60;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x28ef;
    push(r16[ax]);
    r16[cx] = 0x002d;
    yield* sub_1016b();
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = r16[bp] - 14;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = 0x28ae;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = 0x28c8;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = 0x28bb;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = 0x28d5;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    r16[ax] = 0x28ae;
    push(r16[ax]);
    yield* sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0xaa90, r16[ax]);
    memoryASet16(ds, 0xaa92, r16[dx]);
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_d234();
    sp += 0x0004;
    r16[ax] = 0x28c8;
    push(r16[ax]);
    yield* sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0xa70a, r16[ax]);
    memoryASet16(ds, 0xa70c, r16[dx]);
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_d234();
    sp += 0x0004;
    r16[ax] = 0x28bb;
    push(r16[ax]);
    yield* sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0xaaf0, r16[ax]);
    memoryASet16(ds, 0xaaf2, r16[dx]);
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_d234();
    sp += 0x0004;
    r16[ax] = 0x28d5;
    push(r16[ax]);
    yield* sub_7cb4();
    sp++;
    sp++;
    memoryASet16(ds, 0xa6e4, r16[ax]);
    memoryASet16(ds, 0xa6e6, r16[dx]);
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_d234();
    sp += 0x0004;
    r16[ax] = 0x7abb;
    push(r16[ax]);
    yield* sub_f0c5();
    sp++;
    sp++;
    memoryASet16(ds, 0xaafc, 0x0000);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = r16[bp] - 14;
    push(r16[ax]);
    yield* sub_e422();
    sp += 0x0004;
    if (r16[ax])
        { pc = 0x98d3; break; }
    { pc = 0x996c; break; }
  case 0x98d3:
    r16[si] = 0;
    { pc = 0x994d; break; }
    // gap 1 bytes
  case 0x98d8:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43774, 0x0064);
    memoryASet16(ds, r16[bx] + 43776, 0x0000);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43872, 0x0000);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43858, 0x0000);
    r16[ax] = r16[si];
    r16[bx] = 0x0003;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[bx] = 0x000f;
    r16[ax] = r16[dx];
    imul16(r16[bx]);
    r16[dx] = r16[bp] - 60;
    r16[ax] += r16[dx];
    push(r16[ax]);
    r16[ax] = r16[si];
    r16[dx] = 0x000d;
    imul16(r16[dx]);
    r16[ax] += 0xab6e;
    push(r16[ax]);
    yield* sub_f623();
    sp += 0x0004;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43802, 0x0000);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43816, 0x0000);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43844, 0x0000);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43830, 0x0000);
    r16[si]++;
  case 0x994d:
    if (r16s[si] >= signed16(0x0007))
        { pc = 0x9954; break; }
    { pc = 0x98d8; break; }
  case 0x9954:
    r16[ax] = 0;
    r16[dx] = 0x00cc;
    push(r16[ax]);
    push(r16[dx]);
    push(ds);
    r16[ax] = 0xaafe;
    push(r16[ax]);
    r16[ax] = r16[bp] - 14;
    push(r16[ax]);
    yield* sub_7c33();
    sp += 0x000a;
    { pc = 0x997b; break; }
  case 0x996c:
    push(ds);
    r16[ax] = 0xaafe;
    push(r16[ax]);
    r16[ax] = r16[bp] - 14;
    push(r16[ax]);
    yield* sub_7b88();
    sp += 0x0006;
  case 0x997b:
    yield* sub_8b5d();
  case 0x997e:
    yield* sub_aec0();
    yield* sub_9ad4();
    { pc = 0x997e; break; }
    return;
  }
}
function* sub_9ad4() // 01ed:7c04
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x001e;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    yield* sub_7b0a();
    yield* sub_d606();
    r16[ax] = 0x0050;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0xaa8e))
        { pc = 0x9b3b; break; }
    r16[ax] = 0xaad2;
    push(r16[ax]);
    r16[ax] = 0xaace;
    push(r16[ax]);
    yield* sub_ae60();
    sp += 0x0004;
    r16[ax] = memoryAGet16(ds, 0xaad0);
    r16[dx] = memoryAGet16(ds, 0xaace);
    flags.carry = r16[dx] + 0x7000 >= 0x10000;
    r16[dx] += 0x7000;
    r16[ax] += (0xffff + flags.carry);
    memoryASet16(ds, 0xaad6, r16[dx]);
    memoryASet16(ds, 0xaad8, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xaad4);
    r16[dx] = memoryAGet16(ds, 0xaad2);
    flags.carry = r16[dx] + 0xd000 >= 0x10000;
    r16[dx] += 0xd000;
    r16[ax] += (0xffff + flags.carry);
    memoryASet16(ds, 0xaada, r16[dx]);
    memoryASet16(ds, 0xaadc, r16[ax]);
    memoryASet16(ds, 0xaaca, 0x0000);
    memoryASet16(ds, 0xaacc, 0x0000);
  case 0x9b3b:
    r16[ax] = memoryAGet16(ds, 0xaad8);
    r16[dx] = memoryAGet16(ds, 0xaad6);
    memoryASet16(ds, 0xa702, r16[dx]);
    memoryASet16(ds, 0xa704, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xaadc);
    r16[dx] = memoryAGet16(ds, 0xaada);
    memoryASet16(ds, 0xa706, r16[dx]);
    memoryASet16(ds, 0xa708, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xaad0);
    r16[dx] = memoryAGet16(ds, 0xaace);
    memoryASet16(ds, 0xa6fa, r16[dx]);
    memoryASet16(ds, 0xa6fc, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xaad4);
    r16[dx] = memoryAGet16(ds, 0xaad2);
    memoryASet16(ds, 0xa6fe, r16[dx]);
    memoryASet16(ds, 0xa700, r16[ax]);
    memoryASet16(ds, 0xa6e8, 0x8000);
    r16[ax] = 0;
    r16[dx] = 0x4e20;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xaacc));
    push(memoryAGet16(ds, 0xaaca));
    yield* sub_ff73();
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = 0;
    r16[ax] = 0x4e20;
    r16[cx] = pop();
    r16[bx] = pop();
    yield* sub_10433();
    memoryASet16(ds, 0x6ec2, r16[ax]);
    memoryASet16(ds, 0x6ec4, r16[dx]);
    memoryASet16(ds, 0x6ebc, 0x0000);
    memoryASet16(ds, 0x5652, 0x0000);
    memoryASet16(ds, 0x6c62, 0x0003);
  case 0x9bb0:
    memoryASet16(ss, r16[bp] - 2, 0x6eda);
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ds, r16[bx] + 28, 0x0000);
    memoryASet16(ds, r16[bx] + 30, 0x0000);
    memoryASet16(ds, r16[bx] + 32, 0x0000);
    memoryASet16(ds, r16[bx] + 34, 0x0000);
    memoryASet16(ds, r16[bx] + 40, 0x0024);
    memoryASet16(ds, 0x6ec0, 0x0000);
    r16[ax] = 0x0050;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    yield* sub_9f2e();
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    { pc = 0x9d18; break; }
  case 0x9beb:
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    r16[di] = memoryAGet16(ds, r16[bx] + 42766);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    r16[si] = memoryAGet16(ds, r16[bx] + 42768);
    r16[bx] = memoryAGet16(ss, r16[bp] - 4);
    r16[bx] <<= 1;
    if (memoryAGet16(ds, r16[bx] + 43686))
        { pc = 0x9c16; break; }
    { pc = 0x9d15; break; }
  case 0x9c16:
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx] + 42770);
    if (!r16[ax])
        { pc = 0x9c30; break; }
    if (r16[ax] == 0x0001)
        { pc = 0x9c5d; break; }
    { pc = 0x9d15; break; }
  case 0x9c30:
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x0000);
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x004d);
    { pc = 0x9d15; break; }
  case 0x9c5d:
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x0000);
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = r16[di];
    r16[dx] += r16[ax];
    r16[dx]++;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c);
    r16[bx] += r16[dx];
    memoryASet16(es, r16[bx], 0x0000);
    r16[ax] = r16[si];
    r16[ax]++;
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x0000);
    r16[ax] = r16[si];
    r16[ax]++;
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = r16[di];
    r16[dx] += r16[ax];
    r16[dx]++;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c);
    r16[bx] += r16[dx];
    memoryASet16(es, r16[bx], 0x0000);
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x004e);
    r16[ax] = r16[si];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = r16[di];
    r16[dx] += r16[ax];
    r16[dx]++;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48);
    r16[bx] += r16[dx];
    memoryASet16(es, r16[bx], 0x004f);
    r16[ax] = r16[si];
    r16[ax]++;
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48);
    r16[bx] += r16[ax];
    memoryASet16(es, r16[bx], 0x0050);
    r16[ax] = r16[si];
    r16[ax]++;
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = r16[di];
    r16[dx] += r16[ax];
    r16[dx]++;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48);
    r16[bx] += r16[dx];
    memoryASet16(es, r16[bx], 0x0051);
  case 0x9d15:
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + 1);
  case 0x9d18:
    if (signed16(memoryAGet16(ss, r16[bp] - 4)) >= signed16(0x0010))
        { pc = 0x9d21; break; }
    { pc = 0x9beb; break; }
  case 0x9d21:
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ds, 0xa6fc);
    r16[dx] = memoryAGet16(ds, 0xa6fa);
    memoryASet16(ds, r16[bx] + 4, r16[dx]);
    memoryASet16(ds, r16[bx] + 6, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa700);
    r16[dx] = memoryAGet16(ds, 0xa6fe);
    memoryASet16(ds, r16[bx] + 8, r16[dx]);
    memoryASet16(ds, r16[bx] + 10, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa704);
    r16[dx] = memoryAGet16(ds, 0xa702);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa708);
    r16[dx] = memoryAGet16(ds, 0xa706);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    yield* sub_2109();
    yield* sub_2159();
    yield* sub_2159();
    if (memoryAGet16(ss, r16[bp] - 6))
        { pc = 0x9d6c; break; }
    yield* sub_adf6();
  case 0x9d6c:
    if (signed16(memoryAGet16(ss, r16[bp] - 6)) >= signed16(0x0002))
        { pc = 0x9d75; break; }
    yield* sub_8b19();
  case 0x9d75:
    if (!memoryAGet16(ss, r16[bp] - 6))
        { pc = 0x9d7e; break; }
    { pc = 0x9dfd; break; }
  case 0x9d7e:
    yield* sub_7b0a();
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    { pc = 0x9dcc; break; }
  case 0x9d88:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = r16[bp] - 12;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 18;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 18;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 10))
        { pc = 0x9dd2; break; }
    if (memoryAGet16(ss, r16[bp] - 8))
        { pc = 0x9dd2; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (r16[ax])
        { pc = 0x9dd2; break; }
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + 1);
  case 0x9dcc:
    if (signed16(memoryAGet16(ss, r16[bp] - 4)) < signed16(0x003c))
        { pc = 0x9d88; break; }
  case 0x9dd2:
    r16[ax] = r16[bp] - 12;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 24;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 24;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 10))
        { pc = 0x9dd2; break; }
    if (memoryAGet16(ss, r16[bp] - 8))
        { pc = 0x9dd2; break; }
  case 0x9dfd:
    yield* sub_7b0a();
    yield* sub_d606();
    memoryASet16(ds, 0xaafc, 0x0001);
  case 0x9e09:
    yield* sub_2109();
    push(memoryAGet16(ss, r16[bp] - 2));
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 30;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 30;
    r16[dx] = ss;
    r16[cx] = 0x0006;
    yield* sub_1018a();
    yield* sub_c965();
    sp += 0x0008;
    yield* sub_2159();
    yield* sub_30c0();
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ds, r16[bx] + 6);
    r16[dx] = memoryAGet16(ds, r16[bx] + 4);
    memoryASet16(ds, 0xa6fa, r16[dx]);
    memoryASet16(ds, 0xa6fc, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[bx] + 10);
    r16[dx] = memoryAGet16(ds, r16[bx] + 8);
    memoryASet16(ds, 0xa6fe, r16[dx]);
    memoryASet16(ds, 0xa700, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ds, 0xa702, r16[dx]);
    memoryASet16(ds, 0xa704, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ds, 0xa706, r16[dx]);
    memoryASet16(ds, 0xa708, r16[ax]);
    yield* sub_2b21();
    if (!memoryAGet(ds, 0x5065))
        { pc = 0x9e7b; break; }
    yield* sub_2d0a();
  case 0x9e7b:
    if (!memoryAGet16(ds, 0x6ebc))
        { pc = 0x9e85; break; }
    { pc = 0x9f25; break; }
  case 0x9e85:
    r16[si]++;
    if (memoryAGet16(ds, 0x6ec0))
        { pc = 0x9e90; break; }
    { pc = 0x9e09; break; }
  case 0x9e90:
    memoryASet16(ds, 0xaafc, 0x0000);
    r16[bx] = memoryAGet16(ds, 0x6ec0);
    r16[bx] <<= 1;
    if (memoryAGet16(ds, r16[bx] + 43684))
        { pc = 0x9f15; break; }
    r16[ax] = 0x0003;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = memoryAGet16(ds, 0x6ec0);
    r16[ax] &= 0x00ff;
    push(r16[ax]);
    yield* sub_6a39();
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    if (!memoryAGet16(ds, 0x6ebc))
        { pc = 0x9eca; break; }
    memoryASet16(ds, 0x6ebc, 0x0000);
    { pc = 0x9f25; break; }
  case 0x9eca:
    if (!memoryAGet16(ss, r16[bp] - 6))
        { pc = 0x9f11; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    if (r16[ax] == 0x0001)
        { pc = 0x9edf; break; }
    if (r16[ax] == 0x0002)
        { pc = 0x9eed; break; }
    { pc = 0x9ef0; break; }
  case 0x9edf:
    r16[bx] = memoryAGet16(ds, 0x6ec0);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43684, 0x0001);
    { pc = 0x9ef0; break; }
  case 0x9eed:
    yield* sub_a7e9();
  case 0x9ef0:
    if (!memoryAGet16(ds, 0xaa94))
        { pc = 0x9f15; break; }
    if (!memoryAGet16(ds, 0xaa9c))
        { pc = 0x9f15; break; }
    if (!memoryAGet16(ds, 0xaa96))
        { pc = 0x9f15; break; }
    if (!memoryAGet16(ds, 0xaa98))
        { pc = 0x9f15; break; }
    yield* sub_a05c();
    { pc = 0x9f25; break; }
  case 0x9f11:
    memoryASet16(ds, 0xaac6, memoryAGet16(ds, 0xaac6) - 1);
  case 0x9f15:
    if (signed16(memoryAGet16(ds, 0xaac6)) <= signed16(0xffff))
        { pc = 0x9f1f; break; }
    { pc = 0x9bb0; break; }
  case 0x9f1f:
    yield* sub_de4f();
    yield* sub_8b19();
  case 0x9f25:
    yield* sub_a9af();
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_9f2e() // 01ed:805e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    { pc = 0x9f4f; break; }
  case 0x9f3c:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    memoryASet16(ds, r16[bx] + 42766, 0x0000);
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + 1);
  case 0x9f4f:
    if (signed16(memoryAGet16(ss, r16[bp] - 2)) < signed16(0x0010))
        { pc = 0x9f3c; break; }
    r16[cx] = 0;
    { pc = 0x9ff1; break; }
  case 0x9f5a:
    r16[di] = 0;
    { pc = 0x9fe7; break; }
  case 0x9f5f:
    r16[ax] = r16[cx];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[di];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    r16[ax] &= 0x7fff;
    r16[si] = r16[ax];
    if (r16s[ax] <= 0)
        { pc = 0x9fe6; break; }
    if (r16s[ax] >= signed16(0x0100))
        { pc = 0x9fe6; break; }
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    if (memoryAGet16(ds, r16[bx] + 42760))
        { pc = 0x9fe6; break; }
    r16[ax] = r16[si];
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    memoryASet16(ds, r16[bx] + 42760, r16[di]);
    r16[ax] = r16[si];
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[dx] = r16[cx];
    r16[bx] = r16[ax];
    memoryASet16(ds, r16[bx] + 42762, r16[dx]);
    r16[ax] = r16[si];
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    memoryASet16(ds, r16[bx] + 42764, 0x0000);
    r16[ax] = r16[cx];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = r16[di];
    r16[dx] += r16[ax];
    r16[dx]++;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c);
    r16[bx] += r16[dx];
    r16[ax] = memoryAGet16(es, r16[bx]);
    r16[ax] &= 0x7fff;
    if (r16[ax] != r16[si])
        { pc = 0x9fe6; break; }
    r16[di]++;
    r16[ax] = r16[si];
    r16[dx] = 0x0006;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    memoryASet16(ds, r16[bx] + 42764, 0x0001);
  case 0x9fe6:
    r16[di]++;
  case 0x9fe7:
    if (r16s[di] >= signed16(memoryAGet16(ds, 0x6c08)))
        { pc = 0x9ff0; break; }
    { pc = 0x9f5f; break; }
  case 0x9ff0:
    r16[cx]++;
  case 0x9ff1:
    r16[ax] = r16[cx];
    if (r16s[ax] >= signed16(memoryAGet16(ds, 0x6c58)))
        { pc = 0x9ffc; break; }
    { pc = 0x9f5a; break; }
  case 0x9ffc:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_a002() // 01ed:8132
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8360));
    push(memoryAGet16(ds, 0x835a));
    push(memoryAGet16(ds, 0x835e));
    push(memoryAGet16(ds, 0x8358));
    yield* sub_7f5c();
    sp += 0x000a;
    r16[bp] = pop();
    sp += 2;
}
function* sub_a020() // 01ed:8150
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet(ss, r16[bp] - 1, 0x00);
    r16[si] = 0;
    { pc = 0xa04c; break; }
  case 0xa032:
    r16[bx] = r16[si];
    r8[al] = memoryAGet(ds, r16[bx] + r16[di]);
    memoryASet(ss, r16[bp] - 2, r8[al]);
    r16[ax] = r16[bp] - 2;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x0006;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[si]++;
  case 0xa04c:
    push(r16[di]);
    yield* sub_f647();
    sp++;
    sp++;
    if (r16[ax] > r16[si])
        { pc = 0xa032; break; }
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_a05c() // 01ed:818c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0198;
    push(r16[si]);
    push(ss);
    r16[ax] = r16[bp] - 76;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x292e;
    push(r16[ax]);
    r16[cx] = 0x003c;
    yield* sub_1016b();
    push(ss);
    r16[ax] = r16[bp] - 248;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x296a;
    push(r16[ax]);
    r16[cx] = 0x00ac;
    yield* sub_1016b();
    push(ss);
    r16[ax] = r16[bp] - 408;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x2a16;
    push(r16[ax]);
    r16[cx] = 0x00a0;
    yield* sub_1016b();
    yield* sub_7b0a();
    r16[ax] = 0x0050;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    memoryASet16(ds, 0x6ed0, 0x3000);
    memoryASet16(ds, 0x6ed2, 0x0000);
    memoryASet16(ds, 0x6ed4, 0x3000);
    memoryASet16(ds, 0x6ed6, 0x0002);
    yield* sub_d606();
    yield* sub_2109();
    r16[ax] = 0x0028;
    push(r16[ax]);
    r16[ax] = 0x0002;
    r16[dx] = 0x7000;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = 0;
    r16[dx] = 0xd000;
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[ax] = 0x012c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x0014;
    push(r16[ax]);
    r16[ax] = 0x002a;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    yield* sub_8b19();
    r16[ax] = 0x2bd4;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2bf9;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2c1c;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2c41;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x0051;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    r16[ax] = 0x00f0;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_8b5d();
    r16[ax] = 0;
    r16[dx] = 0;
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    yield* sub_d606();
    yield* sub_2109();
    yield* sub_2159();
    yield* sub_2159();
    yield* sub_8b19();
    r16[si] = 0;
    memoryASet16(ss, r16[bp] - 4, 0x6400);
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    memoryASet16(ss, r16[bp] - 8, 0x5000);
    memoryASet16(ss, r16[bp] - 6, 0x0000);
  case 0xa16e:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 76;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r8[cl] = 0x08;
    r16[ax] <<= r8[cl];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, r16[bp] - 4) + r16[ax] >= 0x10000;
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + r16[ax]);
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + (r16[dx] + flags.carry));
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 74;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r16[ax] <<= r8[cl];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, r16[bp] - 8) + r16[ax] >= 0x10000;
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + r16[ax]);
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + (r16[dx] + flags.carry));
    yield* sub_2109();
    r16[ax] = 0x0073;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 76;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r16[bx] = r16[si];
    r16[si]++;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[dx] = r16[bp] - 74;
    r16[bx] += r16[dx];
    r16[ax] += memoryAGet16(ds, r16[bx]);
    if (!r16[ax])
        { pc = 0xa1e0; break; }
    { pc = 0xa16e; break; }
  case 0xa1e0:
    r16[si] = 0;
  case 0xa1e2:
    flags.carry = memoryAGet16(ss, r16[bp] - 4) + 0x0300 >= 0x10000;
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + 0x0300);
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + (0x0000 + flags.carry));
    flags.carry = memoryAGet16(ss, r16[bp] - 8) + 0x0100 >= 0x10000;
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 0x0100);
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + (0x0000 + flags.carry));
    yield* sub_2109();
    r16[ax] = 0x0073;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[ax] = r16[si];
    r16[si]++;
    if (r16s[ax] < signed16(0x0014))
        { pc = 0xa1e2; break; }
    r16[si] = 0;
  case 0xa21a:
    flags.carry = memoryAGet16(ds, 0x6ed0) + 0x0300 >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + 0x0300);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (0x0000 + flags.carry));
    flags.carry = memoryAGet16(ds, 0x6ed4) + 0x0100 >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + 0x0100);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (0x0000 + flags.carry));
    flags.carry = memoryAGet16(ss, r16[bp] - 4) + 0x0300 >= 0x10000;
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + 0x0300);
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + (0x0000 + flags.carry));
    flags.carry = memoryAGet16(ss, r16[bp] - 8) + 0x0100 >= 0x10000;
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 0x0100);
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + (0x0000 + flags.carry));
    yield* sub_2109();
    r16[ax] = 0x0073;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[ax] = r16[si];
    r16[si]++;
    if (r16s[ax] < signed16(0x00c8))
        { pc = 0xa21a; break; }
    r16[si] = 0;
  case 0xa268:
    flags.carry = memoryAGet16(ss, r16[bp] - 8) + 0x0100 >= 0x10000;
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 0x0100);
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + (0x0000 + flags.carry));
    if (r16s[si] >= signed16(0x0014))
        { pc = 0xa281; break; }
    flags.carry = memoryAGet16(ds, 0x6ed4) + 0x0300 >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + 0x0300);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (0x0000 + flags.carry));
  case 0xa281:
    yield* sub_2109();
    r16[ax] = 0x0073;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[ax] = r16[si];
    r16[si]++;
    if (r16s[ax] < signed16(0x003c))
        { pc = 0xa268; break; }
    r16[ax] = 0x0014;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[si] = 0;
  case 0xa2b0:
    yield* sub_2109();
    r16[ax] = 0x0073;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    r16[ax] = 0x0076;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = memoryAGet16(ss, r16[bp] - 8);
    flags.carry = r16[dx] + 0xf200 >= 0x10000;
    r16[dx] += 0xf200;
    r16[ax] += (0xffff + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    flags.carry = r16[dx] + 0x0600 >= 0x10000;
    r16[dx] += 0x0600;
    r16[ax] += (0x0000 + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[ax] = r16[si];
    r16[si]++;
    if (r16s[ax] < signed16(0x001e))
        { pc = 0xa2b0; break; }
    r16[si] = 0;
  case 0xa2fe:
    yield* sub_2109();
    flags.carry = memoryAGet16(ss, r16[bp] - 4) < 0x0200;
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) - 0x0200);
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) - (0x0000 + flags.carry));
    r16[ax] = 0x0074;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[ax] = r16[si];
    r16[si]++;
    if (r16s[ax] < signed16(0x0032))
        { pc = 0xa2fe; break; }
    r16[si] = 0;
  case 0xa32d:
    yield* sub_2109();
    r16[ax] = 0x0074;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    r16[ax] = 0x0075;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = memoryAGet16(ss, r16[bp] - 8);
    flags.carry = r16[dx] + 0xf200 >= 0x10000;
    r16[dx] += 0xf200;
    r16[ax] += (0xffff + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    flags.carry = r16[dx] + 0x0600 >= 0x10000;
    r16[dx] += 0x0600;
    r16[ax] += (0x0000 + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[ax] = r16[si];
    r16[si]++;
    if (r16s[ax] < signed16(0x001e))
        { pc = 0xa32d; break; }
    r16[si] = 0;
  case 0xa37b:
    yield* sub_2109();
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 408;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r8[cl] = 0x08;
    r16[ax] <<= r8[cl];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, r16[bp] - 4) + r16[ax] >= 0x10000;
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + r16[ax]);
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + (r16[dx] + flags.carry));
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 406;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r16[ax] <<= r8[cl];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, r16[bp] - 8) + r16[ax] >= 0x10000;
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + r16[ax]);
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + (r16[dx] + flags.carry));
    r16[ax] = 0x0073;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 408;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r16[bx] = r16[si];
    r16[si]++;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[dx] = r16[bp] - 406;
    r16[bx] += r16[dx];
    r16[ax] += memoryAGet16(ds, r16[bx]);
    if (r16[ax])
        { pc = 0xa37b; break; }
    r16[ax] = 0x003c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_8b5d();
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ss, r16[bp] - 12, r16[dx]);
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ss, r16[bp] - 16, r16[dx]);
    memoryASet16(ss, r16[bp] - 14, r16[ax]);
    r16[ax] = 0x2c62;
    push(r16[ax]);
    yield* sub_2853();
    sp++;
    sp++;
    r16[ax] = 0x0013;
    push(r16[ax]);
    r16[ax] = 0x001b;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    yield* sub_8b19();
    r16[ax] = 0x2c6d;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2c85;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2c99;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x0078;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_a002();
    r16[ax] = 0x003c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x000c;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0x000e;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0019;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = 0x0078;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x000d;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0x000e;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0019;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = 0x012c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x0013;
    push(r16[ax]);
    r16[ax] = 0x001b;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[ax] = 0x2cab;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2cc0;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2cd5;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x00b4;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_a002();
    r16[ax] = 0x003c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x000c;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0x000e;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0019;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = 0x0014;
    push(r16[ax]);
    r16[ax] = 0x001b;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[ax] = 0x2ce0;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2cf7;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2d0e;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2d23;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x00f0;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_a002();
    r16[ax] = 0x0012;
    push(r16[ax]);
    r16[ax] = 0x001b;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[ax] = 0x2d30;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2d42;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x00b4;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_a002();
    r16[ax] = 0x0013;
    push(r16[ax]);
    r16[ax] = 0x001d;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[ax] = 0x2d4c;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2d64;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2d7a;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x00b4;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_a002();
    r16[ax] = 0x0011;
    push(r16[ax]);
    r16[ax] = 0x001b;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[ax] = 0x2d92;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x00b4;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x0011;
    push(r16[ax]);
    r16[ax] = 0x001b;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[ax] = 0x2da6;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x00b4;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_a002();
    r16[ax] = 0x003c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x000d;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0x000e;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0019;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = 0x012c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x000c;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0x000e;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0015;
    push(r16[ax]);
    r16[ax] = 0x001d;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[ax] = 0x0019;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = 0x2db7;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2dce;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2de7;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2dfc;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x2e13;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x012c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_8b5d();
    r16[ax] = 0x0051;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    r16[dx] = memoryAGet16(ss, r16[bp] - 12);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 14);
    r16[dx] = memoryAGet16(ss, r16[bp] - 16);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    yield* sub_d606();
    yield* sub_2109();
    r16[ax] = 0x0074;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    yield* sub_8b19();
    r16[ax] = 0x001e;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[si] = 0;
  case 0xa6f3:
    yield* sub_2109();
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 248;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r8[cl] = 0x08;
    r16[ax] <<= r8[cl];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, r16[bp] - 4) + r16[ax] >= 0x10000;
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + r16[ax]);
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + (r16[dx] + flags.carry));
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 246;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r16[ax] <<= r8[cl];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, r16[bp] - 8) + r16[ax] >= 0x10000;
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + r16[ax]);
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + (r16[dx] + flags.carry));
    r16[ax] = 0x0074;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 248;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r16[bx] = r16[si];
    r16[si]++;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[dx] = r16[bp] - 246;
    r16[bx] += r16[dx];
    r16[ax] += memoryAGet16(ds, r16[bx]);
    if (r16[ax])
        { pc = 0xa6f3; break; }
    yield* sub_2109();
    r16[ax] = 0x0073;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 6));
    push(memoryAGet16(ss, r16[bp] - 8));
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    r16[ax] = 0x003c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = 0x0003;
    push(r16[ax]);
    r16[ax] = 0x000c;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[ax] = 0x2e22;
    push(r16[ax]);
    yield* sub_a020();
    sp++;
    sp++;
    r16[ax] = 0x0190;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    r16[dx] &= 0xf000;
    r16[ax] &= 0xffff;
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    yield* sub_2159();
    yield* sub_2159();
    r16[ax] = 0x0029;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = 0x0016;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xaaf2));
    push(memoryAGet16(ds, 0xaaf0));
    yield* sub_be82();
    sp += 0x0008;
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_a7e9() // 01ed:8919
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0014;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0x0050;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    r16[ax] = 0x0012;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[si] = 0x6eda;
    memoryASet16(ds, r16[si] + 28, 0x0000);
    memoryASet16(ds, r16[si] + 30, 0x0000);
    memoryASet16(ds, r16[si] + 32, 0x0000);
    memoryASet16(ds, r16[si] + 34, 0x0000);
    memoryASet16(ds, r16[si] + 40, 0x0024);
    r16[ax] = memoryAGet16(ds, 0x28a4);
    r16[dx] = memoryAGet16(ds, 0x28a2);
    memoryASet16(ds, 0xa6fa, r16[dx]);
    memoryASet16(ds, 0xa6fc, r16[ax]);
    memoryASet16(ds, 0xaaf4, r16[dx]);
    memoryASet16(ds, 0xaaf6, r16[ax]);
    memoryASet16(ds, r16[si] + 4, r16[dx]);
    memoryASet16(ds, r16[si] + 6, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x28a8);
    r16[dx] = memoryAGet16(ds, 0x28a6);
    memoryASet16(ds, 0xa6fe, r16[dx]);
    memoryASet16(ds, 0xa700, r16[ax]);
    memoryASet16(ds, 0xaaf8, r16[dx]);
    memoryASet16(ds, 0xaafa, r16[ax]);
    memoryASet16(ds, r16[si] + 8, r16[dx]);
    memoryASet16(ds, r16[si] + 10, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    flags.carry = r16[dx] + 0x7000 >= 0x10000;
    r16[dx] += 0x7000;
    r16[ax] += (0xffff + flags.carry);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    memoryASet16(ds, 0xa702, r16[dx]);
    memoryASet16(ds, 0xa704, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 10);
    r16[dx] = memoryAGet16(ds, r16[si] + 8);
    flags.carry = r16[dx] + 0xd000 >= 0x10000;
    r16[dx] += 0xd000;
    r16[ax] += (0xffff + flags.carry);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    memoryASet16(ds, 0xa706, r16[dx]);
    memoryASet16(ds, 0xa708, r16[ax]);
    yield* sub_2109();
    yield* sub_d606();
    yield* sub_2159();
    yield* sub_8b19();
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, r16[si] + 6));
    push(memoryAGet16(ds, r16[si] + 4));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, r16[si] + 10));
    push(memoryAGet16(ds, r16[si] + 8));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    memoryASet16(ss, r16[bp] - 8, 0x0152);
    if (!memoryAGet16(ds, 0x28aa))
        { pc = 0xa8ce; break; }
    memoryASet16(ss, r16[bp] - 8, 0x0156);
  case 0xa8ce:
    r16[di] = 0;
    { pc = 0xa913; break; }
  case 0xa8d2:
    yield* sub_2109();
    yield* sub_d606();
    r16[ax] = r16[di];
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    if (r16[dx])
        { pc = 0xa8f4; break; }
    memoryASet16(ss, r16[bp] - 6, memoryAGet16(ss, r16[bp] - 6) + 1);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    if (r16s[ax] <= signed16(0x0003))
        { pc = 0xa8f4; break; }
    memoryASet16(ss, r16[bp] - 6, 0x0000);
  case 0xa8f4:
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] += memoryAGet16(ss, r16[bp] - 8);
    memoryASet16(es, r16[bx], r16[ax]);
    yield* sub_2159();
    r16[di]++;
  case 0xa913:
    if (r16s[di] < signed16(0x0010))
        { pc = 0xa8d2; break; }
    memoryASet16(ss, r16[bp] - 8, 0x0145);
    if (!memoryAGet16(ds, 0x28aa))
        { pc = 0xa929; break; }
    memoryASet16(ss, r16[bp] - 8, 0x0063);
  case 0xa929:
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    memoryASet16(es, r16[bx], r16[ax]);
  case 0xa941:
    yield* sub_2109();
    r16[ax] = r16[bp] - 14;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 20;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    push(memoryAGet16(ds, r16[si] + 40));
    push(memoryAGet16(ds, r16[si] + 10));
    push(memoryAGet16(ds, r16[si] + 8));
    push(memoryAGet16(ds, r16[si] + 6));
    push(memoryAGet16(ds, r16[si] + 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    yield* sub_30c0();
    yield* sub_2b21();
    if (memoryAGet16(ss, r16[bp] - 12))
        { pc = 0xa941; break; }
    if (memoryAGet16(ss, r16[bp] - 10))
        { pc = 0xa941; break; }
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ds, 0xa702, r16[dx]);
    memoryASet16(ds, 0xa704, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ds, 0xa706, r16[dx]);
    memoryASet16(ds, 0xa708, r16[ax]);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_a9af() // 01ed:8adf
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x006a;
    push(r16[si]);
    push(r16[di]);
    push(ss);
    r16[ax] = r16[bp] - 56;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x2ab6;
    push(r16[ax]);
    r16[cx] = 0x000d;
    yield* sub_1016b();
    push(ss);
    r16[ax] = r16[bp] - 106;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x2ac3;
    push(r16[ax]);
    r16[cx] = 0x0031;
    yield* sub_1016b();
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = r16[bp] - 56;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    r16[di] = 0;
    r16[si] = 0;
    { pc = 0xaa0f; break; }
  case 0xa9eb:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 43776);
    r16[dx] = memoryAGet16(ds, r16[bx] + 43774);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0xaacc)))
        { pc = 0xaa0e; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0xaacc)))
        { pc = 0xaa07; break; }
    if (r16[dx] >= memoryAGet16(ds, 0xaaca))
        { pc = 0xaa0e; break; }
  case 0xaa07:
    r16[ax] = r16[si];
    r16[ax]++;
    r16[di] = r16[ax];
    { pc = 0xaa14; break; }
  case 0xaa0e:
    r16[si]++;
  case 0xaa0f:
    if (r16s[si] < signed16(0x0007))
        { pc = 0xa9eb; break; }
  case 0xaa14:
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    r16[dx] &= 0xf000;
    r16[ax] &= 0xffff;
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    r16[dx] &= 0xf000;
    r16[ax] &= 0xffff;
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    yield* sub_d606();
    yield* sub_2109();
    yield* sub_2159();
    if (!r16[di])
        { pc = 0xaa67; break; }
    r16[ax] = 0x000d;
    push(r16[ax]);
    r16[ax] = 0x0020;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = memoryAGet16(ds, 0x8282);
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    { pc = 0xaa73; break; }
  case 0xaa67:
    memoryASet16(ds, 0x8282, 0x0007);
    memoryASet16(ds, 0x82f8, 0x000a);
  case 0xaa73:
    r16[ax] = 0x0007;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    r16[ax] += 0x0009;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0010;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[ax] = r16[di];
    r16[di]--;
    if (r16[ax])
        { pc = 0xaaa1; break; }
    { pc = 0xacf7; break; }
  case 0xaaa1:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[ax]++;
    memoryASet16(ds, 0x8354, r16[ax]);
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    r16[ax] += 0x0004;
    memoryASet16(ds, 0x82f8, r16[ax]);
    r16[ax] = 0x2e36;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = r16[bp] - 24;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xaacc));
    push(memoryAGet16(ds, 0xaaca));
    yield* sub_f29b();
    sp += 0x0008;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = memoryAGet16(ds, 0x8354);
    r16[ax] += 0x000b;
    memoryASet16(ds, 0x8282, r16[ax]);
    if (!memoryAGet16(ds, 0xaa94))
        { pc = 0xab06; break; }
    r16[ax] = 0x01c0;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax]++;
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0xfffc;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d809();
    sp += 0x0006;
  case 0xab06:
    if (!memoryAGet16(ds, 0xaa9c))
        { pc = 0xab2c; break; }
    r16[ax] = 0x01c1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax]++;
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0xfffc;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    r16[ax]++;
    r16[ax]++;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0xab2c:
    if (!memoryAGet16(ds, 0xaa96))
        { pc = 0xab53; break; }
    r16[ax] = 0x01c2;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax]++;
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0xfffc;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    r16[ax] += 0x0004;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0xab53:
    if (!memoryAGet16(ds, 0xaa98))
        { pc = 0xab7a; break; }
    r16[ax] = 0x01c3;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax]++;
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0xfffc;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    r16[ax] += 0x0006;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0xab7a:
    r16[ax] = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, r16[ax]);
    memoryASet16(ds, 0x82f8, memoryAGet16(ds, 0x82f8) + 0x0004);
    r16[ax] = 0x2e46;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2e5f;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = r16[di];
    r16[dx] = 0x0007;
    imul16(r16[dx]);
    r16[dx] = r16[bp] - 106;
    r16[ax] += r16[dx];
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2e6d;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[si] = 0x0005;
    { pc = 0xac51; break; }
  case 0xabb8:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 43776);
    r16[dx] = memoryAGet16(ds, r16[bx] + 43774);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43778, r16[dx]);
    memoryASet16(ds, r16[bx] + 43780, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 43858);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43860, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 43872);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43874, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 43802);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43804, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 43816);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43818, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 43844);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43846, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 43830);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43832, r16[ax]);
    r16[ax] = r16[si];
    r16[dx] = 0x000d;
    imul16(r16[dx]);
    r16[ax] += 0xab6e;
    push(r16[ax]);
    r16[ax] = r16[si];
    r16[dx] = 0x000d;
    imul16(r16[dx]);
    r16[ax] += 0xab7b;
    push(r16[ax]);
    yield* sub_f623();
    sp += 0x0004;
    r16[si]--;
  case 0xac51:
    if (r16s[si] < r16s[di])
        { pc = 0xac58; break; }
    { pc = 0xabb8; break; }
  case 0xac58:
    yield* sub_7b0a();
    r16[ax] = 0x000c;
    push(r16[ax]);
    r16[ax] = r16[di];
    r16[dx] = 0x000d;
    imul16(r16[dx]);
    r16[ax] += 0xab6e;
    push(r16[ax]);
    yield* sub_8487();
    sp += 0x0004;
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, 0xaacc);
    r16[dx] = memoryAGet16(ds, 0xaaca);
    memoryASet16(ds, r16[bx] + 43774, r16[dx]);
    memoryASet16(ds, r16[bx] + 43776, r16[ax]);
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, 0xaa94);
    memoryASet16(ds, r16[bx] + 43802, r16[ax]);
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, 0xaa9c);
    memoryASet16(ds, r16[bx] + 43816, r16[ax]);
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, 0xaa96);
    memoryASet16(ds, r16[bx] + 43844, r16[ax]);
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, 0xaa98);
    memoryASet16(ds, r16[bx] + 43830, r16[ax]);
    r16[ax] = 0;
    r16[si] = r16[ax];
    memoryASet16(ss, r16[bp] - 14, r16[ax]);
    { pc = 0xacc6; break; }
  case 0xacba:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 43742);
    memoryASet16(ss, r16[bp] - 14, memoryAGet16(ss, r16[bp] - 14) + r16[ax]);
    r16[si]++;
  case 0xacc6:
    if (r16s[si] < signed16(0x0008))
        { pc = 0xacba; break; }
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ss, r16[bp] - 14);
    memoryASet16(ds, r16[bx] + 43858, r16[ax]);
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, 0xaaee);
    memoryASet16(ds, r16[bx] + 43872, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x00cc;
    push(r16[ax]);
    push(r16[dx]);
    push(ds);
    r16[ax] = 0xaafe;
    push(r16[ax]);
    r16[ax] = r16[bp] - 56;
    push(r16[ax]);
    yield* sub_7c33();
    sp += 0x000a;
  case 0xacf7:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 30;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 30;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xacf7; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xacf7; break; }
    yield* sub_7b0a();
    if (r16s[di] >= 0)
        { pc = 0xad75; break; }
    r16[si] = 0;
    { pc = 0xad6f; break; }
  case 0xad2d:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 36;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 36;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xad75; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xad75; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (r16[ax])
        { pc = 0xad75; break; }
    r16[si]++;
  case 0xad6f:
    if (r16s[si] < signed16(0x0168))
        { pc = 0xad2d; break; }
  case 0xad75:
    yield* sub_8b5d();
    yield* sub_7b0a();
    r16[ax] = 0x005a;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    yield* sub_b8f4();
    yield* sub_8b19();
    memoryASet16(ss, r16[bp] - 12, 0x0960);
    memoryASet16(ds, 0xaafc, 0x0000);
  case 0xad95:
    yield* sub_2109();
    yield* sub_2159();
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 42;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 42;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    yield* sub_2b21();
    if (!r16[ax])
        { pc = 0xadc4; break; }
    yield* sub_b8f4();
  case 0xadc4:
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    r16[ax] -= memoryAGet16(ds, 0x5b14);
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xaded; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xaded; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (r16[ax])
        { pc = 0xaded; break; }
    if (signed16(memoryAGet16(ss, r16[bp] - 12)) > signed16(0x0000))
        { pc = 0xad95; break; }
  case 0xaded:
    yield* sub_8b5d();
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_adf6() // 01ed:8f26
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = memoryAGet16(ds, 0x8282);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = 0x2e88;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[di] = memoryAGet16(ds, 0xaac6);
    if (r16s[di] <= signed16(0x0006))
        { pc = 0xae26; break; }
    r16[di] = 0x0006;
  case 0xae26:
    r16[si] = 0;
    { pc = 0xae4d; break; }
  case 0xae2a:
    r16[ax] = 0x0090;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x000b;
    push(r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= 1;
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] += r16[ax];
    r16[dx]++;
    push(r16[dx]);
    yield* sub_d9fd();
    sp += 0x0006;
    r16[si]++;
  case 0xae4d:
    if (r16s[si] < r16s[di])
        { pc = 0xae2a; break; }
    r16[ax] = 0x0029;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ae60() // 01ed:8f90
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    r16[di] = 0;
    { pc = 0xaeb4; break; }
  case 0xae6b:
    r16[si] = 0;
    { pc = 0xaead; break; }
  case 0xae6f:
    r16[ax] = r16[di];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += r16[si];
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    if (r16[ax] != 0x00ff)
        { pc = 0xaeac; break; }
    r16[ax] = r16[si];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, r16[bx], r16[ax]);
    memoryASet16(ds, r16[bx] + 2, r16[dx]);
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[cl] = 0x0c;
    yield* sub_10021();
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    memoryASet16(ds, r16[bx], r16[ax]);
    memoryASet16(ds, r16[bx] + 2, r16[dx]);
    { pc = 0xaeba; break; }
  case 0xaeac:
    r16[si]++;
  case 0xaead:
    if (r16s[si] < signed16(memoryAGet16(ds, 0x6c08)))
        { pc = 0xae6f; break; }
    r16[di]++;
  case 0xaeb4:
    if (r16s[di] < signed16(memoryAGet16(ds, 0x6c58)))
        { pc = 0xae6b; break; }
  case 0xaeba:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_aec0() // 01ed:8ff0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0016;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ds, 0xaa8e, 0x0000);
    memoryASet16(ds, 0xaac6, 0x0004);
    memoryASet16(ds, 0xaac8, 0x0000);
    memoryASet16(ds, 0xaa9a, 0x0000);
    memoryASet16(ds, 0xaa94, 0x0000);
    memoryASet16(ds, 0xaa9c, 0x0000);
    memoryASet16(ds, 0xaa96, 0x0000);
    memoryASet16(ds, 0xaa98, 0x0000);
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    { pc = 0xaf0d; break; }
  case 0xaeff:
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43742, 0x0000);
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
  case 0xaf0d:
    if (signed16(memoryAGet16(ss, r16[bp] - 8)) < signed16(0x0008))
        { pc = 0xaeff; break; }
    memoryASet16(ds, 0xaa9e, 0x0000);
    memoryASet16(ds, 0xaaa0, 0x0000);
    memoryASet16(ds, 0xaaa2, 0x0000);
    memoryASet16(ds, 0xaaa4, 0x0000);
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    { pc = 0xaf40; break; }
  case 0xaf32:
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 43686, 0x0000);
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
  case 0xaf40:
    if (signed16(memoryAGet16(ss, r16[bp] - 8)) < signed16(0x0010))
        { pc = 0xaf32; break; }
  case 0xaf46:
    memoryASet16(ds, 0x5652, 0x0000);
    memoryASet16(ds, 0x6c62, 0x0003);
    yield* sub_d606();
    r16[ax] = 0x005a;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    if (!memoryAGet16(ds, 0x28ac))
        { pc = 0xafa4; break; }
    r16[ax] = 0x005a;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    memoryASet16(ds, 0x6ed0, 0x8000);
    memoryASet16(ds, 0x6ed2, 0x0006);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    yield* sub_d606();
    yield* sub_2109();
    yield* sub_2159();
    yield* sub_8b19();
    r16[di] = 0x0960;
    r16[si] = 0x0004;
    yield* sub_c132();
    yield* sub_8b5d();
    memoryASet16(ds, 0x28ac, 0x0000);
  case 0xafa4:
    r16[di] = 0x0960;
    r16[si] = 0;
    memoryASet16(ds, 0x6ed0, 0x2000);
    memoryASet16(ds, 0x6ed2, 0x0000);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    yield* sub_d606();
    yield* sub_2109();
    yield* sub_b6a3();
    yield* sub_8b19();
    yield* sub_7b0a();
  case 0xafd0:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 16;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    yield* sub_2109();
    yield* sub_2159();
    yield* sub_2b21();
    if (!r16[ax])
        { pc = 0xb022; break; }
    r16[bx] = r16[si];
    if (r16[bx] > 0x0003)
        { pc = 0xb022; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0xb00a; break; }
        case 2: { pc = 0xb00f; break; }
        case 4: { pc = 0xb014; break; }
        case 6: { pc = 0xb019; break; }
        default:
            stop("ind 01ed:9135");
    }
    break;
  case 0xb00a:
    yield* sub_b6a3();
    { pc = 0xb022; break; }
  case 0xb00f:
    yield* sub_b71c();
    { pc = 0xb022; break; }
  case 0xb014:
    yield* sub_b8f4();
    { pc = 0xb022; break; }
  case 0xb019:
    yield* sub_c436();
    yield* sub_2159();
    yield* sub_c436();
  case 0xb022:
    r16[ax] = r16[di];
    r16[ax] -= memoryAGet16(ds, 0x5b14);
    r16[di] = r16[ax];
    if (r16s[ax] <= 0)
        { pc = 0xb031; break; }
    { pc = 0xb0ff; break; }
  case 0xb031:
    yield* sub_8b5d();
    r16[ax] = r16[si];
    if (!r16[ax])
        { pc = 0xb047; break; }
    if (r16[ax] == 0x0001)
        { pc = 0xb064; break; }
    if (r16[ax] == 0x0002)
        { pc = 0xb081; break; }
    { pc = 0xb0cb; break; }
  case 0xb047:
    memoryASet16(ds, 0x6ed0, 0xf000);
    memoryASet16(ds, 0x6ed2, 0x0003);
    memoryASet16(ds, 0x6ed4, 0x1c00);
    memoryASet16(ds, 0x6ed6, 0x0000);
    yield* sub_b71c();
    { pc = 0xb0cb; break; }
  case 0xb064:
    memoryASet16(ds, 0x6ed0, 0x4000);
    memoryASet16(ds, 0x6ed2, 0x0005);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    yield* sub_b8f4();
    { pc = 0xb0cb; break; }
  case 0xb081:
    r16[si]++;
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_c20b();
    sp++;
    sp++;
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 22;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 22;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (r16[ax])
        { pc = 0xb0c3; break; }
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xb0c3; break; }
    if (!memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xb0c8; break; }
  case 0xb0c3:
    r16[di] = 0x0960;
    { pc = 0xb0ff; break; }
  case 0xb0c8:
    yield* sub_8b5d();
  case 0xb0cb:
    r16[di] = 0x0960;
    yield* sub_2109();
    yield* sub_2159();
    r16[si]++;
    r16[ax] = r16[si];
    if (r16[ax] != 0x0004)
        { pc = 0xb0fc; break; }
    r16[si] = 0;
    memoryASet16(ds, 0x6ed0, 0x2000);
    memoryASet16(ds, 0x6ed2, 0x0000);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    yield* sub_d606();
    yield* sub_b6a3();
  case 0xb0fc:
    yield* sub_8b19();
  case 0xb0ff:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (r16[ax])
        { pc = 0xb122; break; }
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xb122; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xb122; break; }
    if (memoryAGet16(ds, 0xa6f8))
        { pc = 0xb122; break; }
    { pc = 0xafd0; break; }
  case 0xb122:
    memoryASet16(ds, 0xa6f8, 0x0000);
    if (memoryAGet16(ds, 0x6ed2))
        { pc = 0xb137; break; }
    if (memoryAGet16(ds, 0x6ed0) == 0x2000)
        { pc = 0xb13a; break; }
  case 0xb137:
    yield* sub_8b5d();
  case 0xb13a:
    push(r16[si]);
    yield* sub_b15f();
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    if (r16[ax])
        { pc = 0xb14a; break; }
    { pc = 0xaf46; break; }
  case 0xb14a:
    yield* sub_7b0a();
    yield* sub_8b5d();
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_b15f() // 01ed:928f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0020;
    push(r16[si]);
    push(r16[di]);
  case 0xb167:
    if (memoryAGet16(ds, 0x6ed2))
        { pc = 0xb176; break; }
    if (memoryAGet16(ds, 0x6ed0) == 0x2000)
        { pc = 0xb17e; break; }
  case 0xb176:
    yield* sub_b580();
    yield* sub_8b19();
    { pc = 0xb181; break; }
  case 0xb17e:
    yield* sub_b580();
  case 0xb181:
    yield* sub_7b0a();
    r16[ax] = 0;
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[di] = r16[ax];
    memoryASet16(ss, r16[bp] - 8, 0x0014);
  case 0xb190:
    r16[si] = 0;
    { pc = 0xb1c3; break; }
  case 0xb194:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = r16[bp] - 14;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 20;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 14) != 0x0008)
        { pc = 0xb1c8; break; }
    r16[si]++;
  case 0xb1c3:
    if (r16s[si] < signed16(0x0006))
        { pc = 0xb194; break; }
  case 0xb1c8:
    r16[ax] = r16[di];
    r16[ax] += 0x0009;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[di]++;
    r16[ax] = r16[di];
    if (r16s[ax] <= signed16(0x0002))
        { pc = 0xb1ec; break; }
    r16[di] = 0;
  case 0xb1ec:
    r16[ax] = memoryAGet16(ss, r16[bp] - 14);
    if (!r16[ax])
        { pc = 0xb1fe; break; }
    if (r16[ax] != 0x0004)
        { pc = 0xb1fb; break; }
    { pc = 0xb2e1; break; }
  case 0xb1fb:
    { pc = 0xb3c3; break; }
  case 0xb1fe:
    if (!memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xb25c; break; }
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) - 1);
    r16[si] = 0;
    { pc = 0xb255; break; }
  case 0xb20b:
    r16[ax] = r16[di];
    r16[ax] += 0x0009;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] -= r16[si];
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] -= r16[si];
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[di]++;
    r16[ax] = r16[di];
    if (r16s[ax] <= signed16(0x0002))
        { pc = 0xb254; break; }
    r16[di] = 0;
  case 0xb254:
    r16[si]++;
  case 0xb255:
    if (r16s[si] < signed16(0x0008))
        { pc = 0xb20b; break; }
    { pc = 0xb279; break; }
  case 0xb25c:
    memoryASet16(ss, r16[bp] - 2, 0x0007);
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
  case 0xb279:
    r16[ax] = memoryAGet16(ds, 0xaaf8);
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ds, 0x82f8, r16[ax]);
    r16[ax] = r16[di];
    r16[ax] += 0x0009;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    { pc = 0xb2c6; break; }
  case 0xb29e:
    r16[ax] = r16[bp] - 14;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 26;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 26;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
  case 0xb2c6:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) - 1);
    if (!r16[ax])
        { pc = 0xb2d6; break; }
    if (memoryAGet16(ss, r16[bp] - 14) != 0x0008)
        { pc = 0xb29e; break; }
  case 0xb2d6:
    memoryASet16(ss, r16[bp] - 8, 0x0014);
    yield* sub_7b0a();
    { pc = 0xb3cc; break; }
  case 0xb2e1:
    if (signed16(memoryAGet16(ss, r16[bp] - 2)) >= signed16(0x0007))
        { pc = 0xb33f; break; }
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + 1);
    r16[si] = 0;
    { pc = 0xb338; break; }
  case 0xb2ee:
    r16[ax] = r16[di];
    r16[ax] += 0x0009;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += r16[si];
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += r16[si];
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[di]++;
    r16[ax] = r16[di];
    if (r16s[ax] <= signed16(0x0002))
        { pc = 0xb337; break; }
    r16[di] = 0;
  case 0xb337:
    r16[si]++;
  case 0xb338:
    if (r16s[si] < signed16(0x0008))
        { pc = 0xb2ee; break; }
    { pc = 0xb35c; break; }
  case 0xb33f:
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
  case 0xb35c:
    r16[ax] = memoryAGet16(ds, 0xaaf8);
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ds, 0x82f8, r16[ax]);
    r16[ax] = r16[di];
    r16[ax] += 0x0009;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    { pc = 0xb3a9; break; }
  case 0xb381:
    r16[ax] = r16[bp] - 14;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 32;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 32;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
  case 0xb3a9:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) - 1);
    if (!r16[ax])
        { pc = 0xb3b9; break; }
    if (memoryAGet16(ss, r16[bp] - 14) != 0x0008)
        { pc = 0xb381; break; }
  case 0xb3b9:
    memoryASet16(ss, r16[bp] - 8, 0x0014);
    yield* sub_7b0a();
    { pc = 0xb3cc; break; }
  case 0xb3c3:
    r16[ax] = 0x0007;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
  case 0xb3cc:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    r16[ax] &= 0x00ff;
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    if (!r16[ax])
        { pc = 0xb3eb; break; }
    if (!memoryAGet16(ds, 0x833e))
        { pc = 0xb3eb; break; }
    memoryASet16(ss, r16[bp] - 12, 0x0001);
  case 0xb3eb:
    if (memoryAGet16(ss, r16[bp] - 6) == 0x0020)
        { pc = 0xb3f7; break; }
    if (memoryAGet16(ss, r16[bp] - 6) != 0x000d)
        { pc = 0xb403; break; }
  case 0xb3f7:
    if (memoryAGet16(ds, 0x833e))
        { pc = 0xb403; break; }
    memoryASet16(ss, r16[bp] - 12, 0x0001);
  case 0xb403:
    yield* sub_2b21();
    if (!r16[ax])
        { pc = 0xb416; break; }
    yield* sub_b580();
    r16[ax] = memoryAGet16(ds, 0xaaf8);
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ds, 0x82f8, r16[ax]);
  case 0xb416:
    if (memoryAGet16(ss, r16[bp] - 12))
        { pc = 0xb425; break; }
    if (memoryAGet16(ss, r16[bp] - 10))
        { pc = 0xb425; break; }
    { pc = 0xb190; break; }
  case 0xb425:
    yield* sub_7b0a();
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    if (r16[bx] > 0x0007)
        { pc = 0xb49a; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0xb440; break; }
        case 2: { pc = 0xb447; break; }
        case 4: { pc = 0xb44f; break; }
        case 6: { pc = 0xb459; break; }
        case 8: { pc = 0xb466; break; }
        case 10: { pc = 0xb473; break; }
        case 12: { pc = 0xb485; break; }
        case 14: { pc = 0xb492; break; }
        default:
            stop("ind 01ed:956b");
    }
    break;
  case 0xb440:
    memoryASet16(ss, r16[bp] - 4, 0x0001);
    { pc = 0xb49a; break; }
  case 0xb447:
    yield* sub_bb1e();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    { pc = 0xb49a; break; }
  case 0xb44f:
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    yield* sub_bc43();
    { pc = 0xb49a; break; }
  case 0xb459:
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    yield* sub_8b5d();
    yield* sub_b602();
    { pc = 0xb497; break; }
  case 0xb466:
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    yield* sub_8b5d();
    yield* sub_b929();
    { pc = 0xb497; break; }
  case 0xb473:
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    yield* sub_8b5d();
    r16[ax] = 0;
    push(r16[ax]);
    yield* sub_c20b();
    sp++;
    sp++;
    { pc = 0xb497; break; }
  case 0xb485:
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    yield* sub_8b5d();
    yield* sub_b5b2();
    { pc = 0xb497; break; }
  case 0xb492:
    memoryASet16(ss, r16[bp] - 4, 0x0000);
  case 0xb497:
    yield* sub_8b5d();
  case 0xb49a:
    if (memoryAGet16(ss, r16[bp] - 2) == 0x0007)
        { pc = 0xb4a9; break; }
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xb4a9; break; }
    { pc = 0xb167; break; }
  case 0xb4a9:
    if (!memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xb4b4; break; }
    r16[ax] = 0x0001;
    { pc = 0xb4b6; break; }
  case 0xb4b4:
    r16[ax] = 0;
  case 0xb4b6:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_b4cd() // 01ed:95fd
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = 0x0012;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = memoryAGet16(ds, 0x8282);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, 0xaaf4, r16[ax]);
    memoryASet16(ds, 0xaaf6, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, 0xaaf8, r16[ax]);
    memoryASet16(ds, 0xaafa, r16[dx]);
    r16[ax] = 0x2e96;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2ea3;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2eb5;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2ebf;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2ecf;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2edf;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2ef1;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2eff;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x2f11;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[bx] = memoryAGet16(ds, 0x833e);
    if (r16[bx] > 0x0003)
        { pc = 0xb568; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0xb555; break; }
        case 2: { pc = 0xb55a; break; }
        case 4: { pc = 0xb55f; break; }
        case 6: { pc = 0xb55f; break; }
        default:
            stop("ind 01ed:9680");
    }
    break;
  case 0xb555:
    r16[ax] = 0x2f1a;
    { pc = 0xb562; break; }
  case 0xb55a:
    r16[ax] = 0x2f21;
    { pc = 0xb562; break; }
  case 0xb55f:
    r16[ax] = 0x2f27;
  case 0xb562:
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
  case 0xb568:
    r16[ax] = memoryAGet16(ds, 0xaaf4);
    r16[ax]++;
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xaaf8);
    memoryASet16(ds, 0x82f8, r16[ax]);
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_b580() // 01ed:96b0
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    memoryASet16(ds, 0x6ed0, 0x2000);
    memoryASet16(ds, 0x6ed2, 0x0000);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    yield* sub_d606();
    yield* sub_b6a3();
    memoryASet16(ds, 0x5658, 0x95fd);
    yield* sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    r16[bp] = pop();
    sp += 2;
}
function* sub_b5b2() // 01ed:96e2
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x3116;
    push(r16[ax]);
    yield* sub_2853();
    sp++;
    sp++;
    yield* sub_8b19();
    r16[ax] = 0x012c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_8b5d();
    r16[ax] = 0x3123;
    push(r16[ax]);
    yield* sub_2853();
    sp++;
    sp++;
    yield* sub_8b19();
    r16[ax] = 0x005a;
    push(r16[ax]);
    yield* sub_253b();
    sp++;
    sp++;
    r16[ax] = 0x012c;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = 0x0016;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xa6e6));
    push(memoryAGet16(ds, 0xa6e4));
    yield* sub_be82();
    sp += 0x0008;
    r16[bp] = pop();
    sp += 2;
}
function* sub_b602() // 01ed:9732
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000c;
    memoryASet16(ds, 0x6ed0, 0xf000);
    memoryASet16(ds, 0x6ed2, 0x0003);
    memoryASet16(ds, 0x6ed4, 0x1c00);
    memoryASet16(ds, 0x6ed6, 0x0000);
    yield* sub_d606();
    yield* sub_2109();
    yield* sub_b71c();
    yield* sub_8b19();
    yield* sub_7b0a();
  case 0xb62f:
    yield* sub_2109();
    yield* sub_2159();
    yield* sub_2b21();
    if (!r16[ax])
        { pc = 0xb63f; break; }
    yield* sub_b71c();
  case 0xb63f:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 12;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 12;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xb677; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xb677; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (!r16[ax])
        { pc = 0xb62f; break; }
  case 0xb677:
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_b67b() // 01ed:97ab
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x00b6;
    push(r16[ax]);
    r16[ax] = 0x0010;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[bp] = pop();
    sp += 2;
}
function* sub_b6a3() // 01ed:97d3
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    memoryASet16(ds, 0x5658, 0x97ab);
    yield* sub_2109();
    yield* sub_2159();
    yield* sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    yield* sub_7b0a();
    r16[bp] = pop();
    sp += 2;
}
function* sub_b6c0() // 01ed:97f0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x01b8;
    push(r16[si]);
    push(ss);
    r16[ax] = r16[bp] - 440;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x2f30;
    push(r16[ax]);
    r16[cx] = 0x01b8;
    yield* sub_1016b();
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x0017;
    push(r16[ax]);
    r16[ax] = 0x0011;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0007;
    memoryASet16(ds, 0x8354, r16[ax]);
    memoryASet16(ds, 0x8282, r16[ax]);
    memoryASet16(ds, 0x82f8, 0x0009);
    r16[si] = 0;
    { pc = 0xb712; break; }
  case 0xb6fe:
    r16[ax] = r16[si];
    r16[dx] = 0x0028;
    imul16(r16[dx]);
    r16[dx] = r16[bp] - 440;
    r16[ax] += r16[dx];
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[si]++;
  case 0xb712:
    if (r16s[si] < signed16(0x000b))
        { pc = 0xb6fe; break; }
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_b71c() // 01ed:984c
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    memoryASet16(ds, 0x5658, 0x97f0);
    yield* sub_d606();
    yield* sub_2109();
    yield* sub_2159();
    yield* sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    yield* sub_7b0a();
    r16[bp] = pop();
    sp += 2;
}
function* sub_b73c() // 01ed:986c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0010;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0x0003;
    push(r16[ax]);
    r16[ax] = 0x0007;
    push(r16[ax]);
    r16[ax] = 0x000f;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0004;
    push(r16[ax]);
    r16[ax] = 0x002c;
    push(r16[ax]);
    r16[ax] = 0x0009;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = 0x002c;
    push(r16[ax]);
    r16[ax] = 0x0017;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0006;
    push(r16[ax]);
    r16[ax] = 0x002c;
    push(r16[ax]);
    r16[ax] = 0x0021;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[si] = 0;
    { pc = 0xb8e6; break; }
  case 0xb791:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0x6ed2));
    push(memoryAGet16(ds, 0x6ed0));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0x6ed6));
    push(memoryAGet16(ds, 0x6ed4));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[ax] = r16[si];
    r16[bx] = 0x0004;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[di] = r16[dx];
    r16[ax] = r16[si];
    r16[ax] <<= 1;
    r16[ax] += 0x0008;
    memoryASet16(ds, 0x82f8, r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 43802))
        { pc = 0xb7ff; break; }
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[ax] += memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] += r16[ax];
    r16[dx] += 0x000e;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[dx];
    r16[ax] = r16[di];
    r16[ax] += 0x00dd;
    memoryASet16(es, r16[bx], r16[ax]);
  case 0xb7ff:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 43816))
        { pc = 0xb832; break; }
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[ax] += memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] += r16[ax];
    r16[dx] += 0x000f;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[dx];
    r16[ax] = r16[di];
    r16[ax] += 0x00ed;
    memoryASet16(es, r16[bx], r16[ax]);
  case 0xb832:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 43844))
        { pc = 0xb865; break; }
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[ax] += memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] += r16[ax];
    r16[dx] += 0x0010;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[dx];
    r16[ax] = r16[di];
    r16[ax] += 0x00f1;
    memoryASet16(es, r16[bx], r16[ax]);
  case 0xb865:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    if (!memoryAGet16(ds, r16[bx] + 43830))
        { pc = 0xb898; break; }
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[ax] += memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] += r16[ax];
    r16[dx] += 0x0011;
    r16[dx] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[dx];
    r16[ax] = r16[di];
    r16[ax] += 0x00f5;
    memoryASet16(es, r16[bx], r16[ax]);
  case 0xb898:
    r16[ax] = 0x000a;
    push(r16[ax]);
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    push(memoryAGet16(ds, r16[bx] + 43776));
    push(memoryAGet16(ds, r16[bx] + 43774));
    yield* sub_f29b();
    sp += 0x0008;
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    yield* sub_f647();
    sp++;
    sp++;
    r16[dx] = 0x001d;
    r16[dx] -= r16[ax];
    memoryASet16(ds, 0x8282, r16[dx]);
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, 0x0009);
    r16[ax] = r16[si];
    r16[dx] = 0x000d;
    imul16(r16[dx]);
    r16[ax] += 0xab6e;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[si]++;
  case 0xb8e6:
    if (r16s[si] >= signed16(0x0007))
        { pc = 0xb8ee; break; }
    { pc = 0xb791; break; }
  case 0xb8ee:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_b8f4() // 01ed:9a24
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    memoryASet16(ds, 0x6ed0, 0x4000);
    memoryASet16(ds, 0x6ed2, 0x0005);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    yield* sub_d606();
    yield* sub_2109();
    memoryASet16(ds, 0x5658, 0x986c);
    yield* sub_2159();
    yield* sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    r16[bp] = pop();
    sp += 2;
}
function* sub_b929() // 01ed:9a59
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000c;
    yield* sub_b8f4();
    yield* sub_8b19();
    yield* sub_7b0a();
  case 0xb938:
    yield* sub_2109();
    yield* sub_2159();
    yield* sub_2b21();
    if (!r16[ax])
        { pc = 0xb948; break; }
    yield* sub_b8f4();
  case 0xb948:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 12;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 12;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xb980; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xb980; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (!r16[ax])
        { pc = 0xb938; break; }
  case 0xb980:
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_b984() // 01ed:9ab4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0010;
    push(r16[si]);
    r16[si] = 0;
    push(ss);
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x30e8;
    push(r16[ax]);
    r16[cx] = 0x000d;
    yield* sub_1016b();
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    if (memoryAGet16(ds, 0xaafc))
        { pc = 0xb9e4; break; }
    r16[ax] = 0x0003;
    push(r16[ax]);
    r16[ax] = 0x0016;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x3130;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x3147;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x315f;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    yield* sub_7b0a();
    yield* sub_d055();
    { pc = 0xbb19; break; }
  case 0xb9e4:
    r16[ax] = 0x0003;
    push(r16[ax]);
    r16[ax] = 0x0014;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x3170;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x3185;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x319b;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
  case 0xba0d:
    yield* sub_8138();
    r8[al] &= 0xff;
    memoryASet(ss, r16[bp] - 1, r8[al]);
    if (r8[al] == 0x1b)
        { pc = 0xba21; break; }
    if (r8s[al] < signed8(0x31))
        { pc = 0xba0d; break; }
    if (r8s[al] > signed8(0x39))
        { pc = 0xba0d; break; }
  case 0xba21:
    if (memoryAGet(ss, r16[bp] - 1) != 0x1b)
        { pc = 0xba2a; break; }
    { pc = 0xbb19; break; }
  case 0xba2a:
    r8[al] = memoryAGet(ss, r16[bp] - 1);
    memoryASet(ss, r16[bp] - 11, r8[al]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    yield* sub_e422();
    sp += 0x0004;
    if (r16[ax])
        { pc = 0xba97; break; }
    r16[ax] = 0x0003;
    push(r16[ax]);
    r16[ax] = 0x0014;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x31ab;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x31bf;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x31d0;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
  case 0xba6a:
    yield* sub_8138();
    r16[ax] &= 0x00ff;
    push(r16[ax]);
    yield* sub_ec06();
    sp++;
    sp++;
    memoryASet(ss, r16[bp] - 1, r8[al]);
    if (r8[al] == 0x1b)
        { pc = 0xba85; break; }
    if (r8[al] == 0x59)
        { pc = 0xba85; break; }
    if (r8[al] != 0x4e)
        { pc = 0xba6a; break; }
  case 0xba85:
    if (memoryAGet(ss, r16[bp] - 1) != 0x1b)
        { pc = 0xba8e; break; }
    { pc = 0xbb19; break; }
  case 0xba8e:
    if (memoryAGet(ss, r16[bp] - 1) != 0x59)
        { pc = 0xba98; break; }
    r16[si]++;
    { pc = 0xba98; break; }
  case 0xba97:
    r16[si]++;
  case 0xba98:
    if (r16[si])
        { pc = 0xba9f; break; }
    { pc = 0xb9e4; break; }
  case 0xba9f:
    r16[ax] = memoryAGet16(ds, 0xa704);
    r16[dx] = memoryAGet16(ds, 0xa702);
    memoryASet16(ds, 0xaad6, r16[dx]);
    memoryASet16(ds, 0xaad8, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa708);
    r16[dx] = memoryAGet16(ds, 0xa706);
    memoryASet16(ds, 0xaada, r16[dx]);
    memoryASet16(ds, 0xaadc, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa6fc);
    r16[dx] = memoryAGet16(ds, 0xa6fa);
    memoryASet16(ds, 0xaace, r16[dx]);
    memoryASet16(ds, 0xaad0, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa700);
    r16[dx] = memoryAGet16(ds, 0xa6fe);
    memoryASet16(ds, 0xaad2, r16[dx]);
    memoryASet16(ds, 0xaad4, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x005c;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = 0xaa94;
    push(ds);
    push(r16[ax]);
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    yield* sub_7c33();
    sp += 0x000a;
    r16[ax] = 0x0003;
    push(r16[ax]);
    r16[ax] = 0x001d;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x31df;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x31fb;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x3219;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    yield* sub_8138();
  case 0xbb19:
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_bb1e() // 01ed:9c4e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0014;
    push(ss);
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x30f5;
    push(r16[ax]);
    r16[cx] = 0x000d;
    yield* sub_1016b();
    r16[ax] = 0x0020;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
  case 0xbb4c:
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x0019;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = memoryAGet16(ds, 0x8282);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, 0xaaf4, r16[ax]);
    memoryASet16(ds, 0xaaf6, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, 0xaaf8, r16[ax]);
    memoryASet16(ds, 0xaafa, r16[dx]);
    r16[ax] = 0x3230;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x3248;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
  case 0xbb82:
    yield* sub_8138();
    r8[al] &= 0xff;
    memoryASet(ss, r16[bp] - 1, r8[al]);
    if (r8s[al] < signed8(0x31))
        { pc = 0xbb92; break; }
    if (r8s[al] <= signed8(0x39))
        { pc = 0xbb98; break; }
  case 0xbb92:
    if (memoryAGet(ss, r16[bp] - 1) != 0x1b)
        { pc = 0xbb82; break; }
  case 0xbb98:
    if (memoryAGet(ss, r16[bp] - 1) != 0x1b)
        { pc = 0xbba3; break; }
    r16[ax] = 0;
    { pc = 0xbc3f; break; }
  case 0xbba3:
    r8[al] = memoryAGet(ss, r16[bp] - 1);
    memoryASet(ss, r16[bp] - 15, r8[al]);
    push(memoryAGet16(ds, 0x2506));
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    yield* sub_f5ea();
    sp += 0x0004;
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    yield* sub_823b();
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    memoryASet16(ss, r16[bp] - 4, r16[dx]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] |= r16[dx];
    if (r16[ax])
        { pc = 0xbbf3; break; }
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x0019;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x325b;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x326f;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    yield* sub_8138();
    { pc = 0xbb4c; break; }
  case 0xbbf3:
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xbc19; break; }
    if (memoryAGet16(ss, r16[bp] - 6) != 0x005c)
        { pc = 0xbc19; break; }
    push(ds);
    r16[ax] = 0xaa94;
    push(r16[ax]);
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    yield* sub_7b88();
    sp += 0x0006;
    memoryASet16(ds, 0xaa8e, 0x0001);
    r16[ax] = 0x0001;
    { pc = 0xbc3f; break; }
  case 0xbc19:
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0x0019;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x3282;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x329d;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    yield* sub_8138();
    { pc = 0xbb4c; break; }
  case 0xbc3f:
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_bc43() // 01ed:9d73
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    yield* sub_8b5d();
    memoryASet16(ds, 0x6ed0, 0xa000);
    memoryASet16(ds, 0x6ed2, 0x0002);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    yield* sub_d606();
    yield* sub_2159();
    yield* sub_8b19();
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xa70c));
    push(memoryAGet16(ds, 0xa70a));
    yield* sub_be82();
    sp += 0x0008;
    yield* sub_8b5d();
    r16[bp] = pop();
    sp += 2;
}
function* sub_bc84() // 01ed:9db4
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0008;
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    memoryASet16(ss, r16[bp] - 4, r16[dx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    memoryASet16(ss, r16[bp] - 8, r16[dx]);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    r16[dx] &= 0xf000;
    r16[ax] &= 0xffff;
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    r16[dx] &= 0xf000;
    r16[ax] &= 0xffff;
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    r16[ax] = 0x0014;
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xaa92));
    push(memoryAGet16(ds, 0xaa90));
    yield* sub_be82();
    sp += 0x0008;
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[dx] = memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[dx] = memoryAGet16(ss, r16[bp] - 8);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
}
function* sub_bd02() // 01ed:9e32
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ds, 0x8282);
    r16[si] = memoryAGet16(ds, 0x82f8);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ds, 0x82f8, r16[ax]);
    if (!memoryAGet16(ss, r16[bp] + 4))
        { pc = 0xbd29; break; }
    push(memoryAGet16(ss, r16[bp] + 10));
    yield* sub_c48c();
    { pc = 0xbd2f; break; }
  case 0xbd29:
    push(memoryAGet16(ss, r16[bp] + 10));
    yield* sub_81a2();
  case 0xbd2f:
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, r16[di]);
    memoryASet16(ds, 0x82f8, r16[si]);
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_bd3d() // 01ed:9e6d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(memoryAGet16(ds, 0xa6f6));
    r16[ax] = 0x002b;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xa6f2));
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_7dee();
    sp += 0x0008;
    r16[ax] = 0x0004;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa6f6);
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = 0x0004;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa6f6);
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = 0x002b;
    push(r16[ax]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa6f6);
    r16[ax]++;
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = 0x0004;
    push(r16[ax]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[ax] = 0x0003;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa6f6);
    r16[ax]++;
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = 0x002b;
    push(r16[ax]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[si] = 0x0005;
    { pc = 0xbdda; break; }
  case 0xbdc2:
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa6f6);
    r16[ax]++;
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(r16[si]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[si]++;
  case 0xbdda:
    if (r16s[si] < signed16(0x002b))
        { pc = 0xbdc2; break; }
    r16[ax] = 0x32b5;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa6f6);
    r16[ax]++;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_bd02();
    sp += 0x0008;
    push(memoryAGet16(ds, 0xa6f4));
    push(memoryAGet16(ds, 0xa6ea));
    push(memoryAGet16(ds, 0xa6ee));
    push(memoryAGet16(ds, 0xa6ec));
    r16[ax] = memoryAGet16(ds, 0xa6f2);
    r16[ax]++;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xa6f0));
    yield* sub_d113();
    sp += 0x000c;
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_be82() // 01ed:9fb2
{
  var pc = 0;
  var temp_cond0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0014;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax] -= memoryAGet16(ss, r16[bp] + 8);
    r16[ax]--;
    r16[di] = r16[ax];
    r16[ax] = 0x00c8;
    push(r16[ax]);
    r16[ax] = 0x0026;
    push(r16[ax]);
    r16[ax] = 0xa76e;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_d3af();
    sp += 0x000a;
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    memoryASet16(ds, 0xa6f0, 0x0005);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ds, 0xa6f2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, 0xa6ec, r16[dx]);
    memoryASet16(ds, 0xa6ee, r16[ax]);
    memoryASet16(ds, 0xa6ea, 0xa76e);
    memoryASet16(ds, 0xa6f4, r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    memoryASet16(ds, 0xa6f6, r16[ax]);
    memoryASet16(ds, 0x5658, 0x9e6d);
    yield* sub_2159();
    yield* sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    r16[si] = 0;
    r16[ax] = 0x0008;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
  case 0xbef4:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 14;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 14;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet(ds, 0x5074))
        { pc = 0xbf20; break; }
    if (memoryAGet16(ss, r16[bp] - 6))
        { pc = 0xbf6a; break; }
  case 0xbf20:
    if (r16s[si] > 0)
        { pc = 0xbf27; break; }
    { pc = 0xbfd1; break; }
  case 0xbf27:
    r16[si]--;
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax]--;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r16[ax]++;
    push(r16[ax]);
    yield* sub_d510();
    sp += 0x0006;
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0xa76e;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r16[ax]++;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_d113();
    sp += 0x000c;
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    { pc = 0xbfd1; break; }
  case 0xbf6a:
    if (memoryAGet(ds, 0x507c))
        { pc = 0xbf77; break; }
    if (memoryAGet16(ss, r16[bp] - 6) != 0x0004)
        { pc = 0xbfd1; break; }
  case 0xbf77:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[ax] -= r16[di];
    if (r16s[ax] < r16s[si])
        { pc = 0xbfd1; break; }
    r16[ax] = 0x00c8;
    r16[ax] -= r16[di];
    if (r16s[ax] < r16s[si])
        { pc = 0xbfd1; break; }
    r16[si]++;
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax]--;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r16[ax]++;
    push(r16[ax]);
    yield* sub_d510();
    sp += 0x0006;
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = r16[si];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[di];
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[ax] += r16[dx];
    r16[ax] += 0xa76a;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax]--;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_d113();
    sp += 0x000c;
    r16[ax] = 0x0002;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
  case 0xbfd1:
    if (!memoryAGet(ds, 0x5075))
        { pc = 0xc00f; break; }
    r16[ax] = r16[si];
    r16[ax] -= r16[di];
    temp_cond0 = r16s[ax] <= 0;
    r16[ax]++;
    if (temp_cond0)
        { pc = 0xbfe6; break; }
    r16[ax] = r16[di];
    r16[ax]--;
    r16[si] -= r16[ax];
    { pc = 0xbfe8; break; }
  case 0xbfe6:
    r16[si] = 0;
  case 0xbfe8:
    push(r16[di]);
    r16[ax] = r16[si];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0xa76e;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r16[ax]++;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_d113();
    sp += 0x000c;
  case 0xc008:
    yield* sync();
    if (memoryAGet(ds, 0x5075))
        { pc = 0xc008; break; }
  case 0xc00f:
    if (!memoryAGet(ds, 0x507d))
        { pc = 0xc059; break; }
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[dx] = r16[si];
    r16[dx] += r16[ax];
    if (r16s[dx] >= signed16(memoryAGet16(ss, r16[bp] - 8)))
        { pc = 0xc02a; break; }
    r16[ax] = r16[di];
    r16[ax]--;
    r16[si] += r16[ax];
    { pc = 0xc032; break; }
  case 0xc02a:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[ax] -= r16[di];
    r16[ax]++;
    r16[si] = r16[ax];
  case 0xc032:
    push(r16[di]);
    r16[ax] = r16[si];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0xa76e;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r16[ax]++;
    push(r16[ax]);
    r16[ax] = 0x0005;
    push(r16[ax]);
    yield* sub_d113();
    sp += 0x000c;
  case 0xc052:
    yield* sync();
    if (memoryAGet(ds, 0x507d))
        { pc = 0xc052; break; }
  case 0xc059:
    r8[al] = memoryAGet(ds, 0x502d);
    cbw();
    if (r16[ax])
        { pc = 0xc070; break; }
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xc070; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xc070; break; }
    { pc = 0xbef4; break; }
  case 0xc070:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 20;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xc070; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xc070; break; }
    yield* sub_7b0a();
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_c0a4() // 01ed:a1d4
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x000a;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xa6f0));
    r16[ax] = 0x0010;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[bp] = pop();
    sp += 2;
}
function* sub_c0bb() // 01ed:a1eb
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa6f0);
    r16[ax] += 0xfff6;
    push(r16[ax]);
    r16[ax] = 0x0016;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x000a;
    push(r16[ax]);
    push(memoryAGet16(ds, 0xa6f0));
    r16[ax] = 0x0010;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0009;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0xa6f0);
    r16[ax] += 0x0020;
    push(r16[ax]);
    r16[ax] = 0x0012;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x000f;
    push(r16[ax]);
    r16[ax] = 0x0063;
    push(r16[ax]);
    r16[ax] = 0x0015;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0011;
    push(r16[ax]);
    r16[ax] = 0x0072;
    push(r16[ax]);
    r16[ax] = 0x0013;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[ax] = 0x0010;
    push(r16[ax]);
    r16[ax] = 0x009f;
    push(r16[ax]);
    r16[ax] = 0x0013;
    push(r16[ax]);
    yield* sub_d986();
    sp += 0x0006;
    r16[bp] = pop();
    sp += 2;
}
function* sub_c132() // 01ed:a262
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0010;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ds, 0x6ed0, 0x8000);
    memoryASet16(ds, 0x6ed2, 0x0006);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    memoryASet16(ss, r16[bp] - 8, 0x012c);
    r16[di] = 0x00c8;
    r16[si] = 0;
    memoryASet16(ss, r16[bp] - 10, 0x0000);
    yield* sub_d606();
    yield* sub_7b0a();
    memoryASet16(ds, 0xa6f8, 0x0000);
    { pc = 0xc1f2; break; }
  case 0xc170:
    yield* sub_2109();
    memoryASet16(ds, 0xa6f0, r16[di]);
    yield* sub_2159();
    r16[ax] = r16[si];
    if (!r16[ax])
        { pc = 0xc187; break; }
    if (r16[ax] == 0x0001)
        { pc = 0xc1a0; break; }
    { pc = 0xc1af; break; }
  case 0xc187:
    memoryASet16(ss, r16[bp] - 10, memoryAGet16(ss, r16[bp] - 10) + 1);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    if (r16s[ax] <= signed16(0x001e))
        { pc = 0xc1af; break; }
    memoryASet16(ss, r16[bp] - 10, 0x0000);
    r16[si]++;
    memoryASet16(ds, 0x5658, 0xa1d4);
    { pc = 0xc1af; break; }
  case 0xc1a0:
    if (r16s[di] <= signed16(0x0037))
        { pc = 0xc1a8; break; }
    r16[di]--;
    { pc = 0xc1af; break; }
  case 0xc1a8:
    r16[si]++;
    memoryASet16(ds, 0x5658, 0xa1eb);
  case 0xc1af:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 16;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 16;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xc1e7; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xc1e7; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (!r16[ax])
        { pc = 0xc1f2; break; }
  case 0xc1e7:
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    memoryASet16(ds, 0xa6f8, 0x0001);
  case 0xc1f2:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) - 1);
    if (!r16[ax])
        { pc = 0xc1ff; break; }
    { pc = 0xc170; break; }
  case 0xc1ff:
    memoryASet16(ds, 0x5658, 0x0000);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_c20b() // 01ed:a33b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0026;
    push(r16[si]);
    push(r16[di]);
    push(ss);
    r16[ax] = r16[bp] - 10;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x3102;
    push(r16[ax]);
    r16[cx] = 0x0004;
    yield* sub_1016b();
    push(ss);
    r16[ax] = r16[bp] - 18;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x3106;
    push(r16[ax]);
    r16[cx] = 0x0008;
    yield* sub_1016b();
    push(ss);
    r16[ax] = r16[bp] - 26;
    push(r16[ax]);
    push(ds);
    r16[ax] = 0x310e;
    push(r16[ax]);
    r16[cx] = 0x0008;
    yield* sub_1016b();
    r16[di] = 0;
    memoryASet16(ss, r16[bp] - 28, 0x0000);
    r16[si] = 0;
    memoryASet16(ss, r16[bp] - 32, 0x0000);
    yield* sub_c436();
    yield* sub_8b19();
    yield* sub_7b0a();
    memoryASet16(ss, r16[bp] - 30, 0x0960);
  case 0xc25f:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 38;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 38;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    yield* sub_2109();
    r16[ax] = memoryAGet16(ss, r16[bp] - 32);
    r16[bx] = 0x0006;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    if (r16[dx])
        { pc = 0xc2bc; break; }
    r16[ax] = 0x0003;
    push(r16[ax]);
    yield* sub_df2c();
    sp++;
    sp++;
    r16[dx] = r16[di];
    r16[dx] += r16[ax];
    r16[dx] += 0xfffe;
    r16[di] = r16[dx];
    r16[ax] = r16[dx];
    if (r16s[ax] > signed16(0x0007))
        { pc = 0xc2ab; break; }
    if (r16s[dx] >= 0)
        { pc = 0xc2bc; break; }
  case 0xc2ab:
    r16[ax] = 0x0031;
    push(r16[ax]);
    yield* sub_df2c();
    sp++;
    sp++;
    r16[bx] = 0x0007;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    r16[di] = r16[ax];
  case 0xc2bc:
    memoryASet16(ss, r16[bp] - 28, memoryAGet16(ss, r16[bp] - 28) + 1);
    r16[ax] = memoryAGet16(ss, r16[bp] - 28);
    if (r16s[ax] <= signed16(0x01f4))
        { pc = 0xc2cf; break; }
    r16[si] ^= 0x0001;
    memoryASet16(ss, r16[bp] - 28, 0x0000);
  case 0xc2cf:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 10;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r16[ax] += r16[di];
    push(r16[ax]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 18;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx] + 2);
    r16[dx] = memoryAGet16(ds, r16[bx]);
    flags.carry = r16[dx] + memoryAGet16(ds, 0x6ed4) >= 0x10000;
    r16[dx] += memoryAGet16(ds, 0x6ed4);
    r16[ax] += memoryAGet16(ds, 0x6ed6) + flags.carry;
    push(r16[ax]);
    push(r16[dx]);
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = r16[bp] - 26;
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx] + 2);
    r16[dx] = memoryAGet16(ds, r16[bx]);
    flags.carry = r16[dx] + memoryAGet16(ds, 0x6ed0) >= 0x10000;
    r16[dx] += memoryAGet16(ds, 0x6ed0);
    r16[ax] += memoryAGet16(ds, 0x6ed2) + flags.carry;
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    memoryASet16(ss, r16[bp] - 32, memoryAGet16(ss, r16[bp] - 32) + 1);
    if (!memoryAGet16(ss, r16[bp] + 4))
        { pc = 0xc32d; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 30);
    r16[ax] -= memoryAGet16(ds, 0x5b14);
    memoryASet16(ss, r16[bp] - 30, r16[ax]);
  case 0xc32d:
    yield* sub_2b21();
    if (!r16[ax])
        { pc = 0xc33a; break; }
    yield* sub_7b0a();
    yield* sub_c436();
  case 0xc33a:
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xc353; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xc353; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (!r16[ax])
        { pc = 0xc358; break; }
  case 0xc353:
    memoryASet16(ss, r16[bp] - 30, 0x0000);
  case 0xc358:
    if (signed16(memoryAGet16(ss, r16[bp] - 30)) <= signed16(0x0000))
        { pc = 0xc361; break; }
    { pc = 0xc25f; break; }
  case 0xc361:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_c367() // 01ed:a497
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x000c;
    memoryASet16(ds, 0x8282, r16[ax]);
    memoryASet16(ds, 0x8354, r16[ax]);
    memoryASet16(ds, 0x82f8, 0x0004);
    r16[ax] = 0x32dc;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x32f6;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x3311;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x3329;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x3342;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x335d;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x3378;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x0005;
    memoryASet16(ds, 0x8282, r16[ax]);
    memoryASet16(ds, 0x8354, r16[ax]);
    r16[ax] = 0x3393;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) - 1);
    r16[ax] = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8354, r16[ax]);
    r16[ax] = 0x33bb;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x33e2;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x3409;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x342e;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x344e;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x3476;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x349e;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x34c6;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[ax] = 0x34f2;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    memoryASet16(ds, 0x8282, 0x0000);
    r16[ax] = 0x351c;
    push(r16[ax]);
    yield* sub_c48c();
    sp++;
    sp++;
    r16[bp] = pop();
    sp += 2;
}
function* sub_c436() // 01ed:a566
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    memoryASet16(ds, 0x6ed0, 0x6000);
    memoryASet16(ds, 0x6ed2, 0x0001);
    memoryASet16(ds, 0x6ed4, 0x2000);
    memoryASet16(ds, 0x6ed6, 0x0000);
    r16[dx] = memoryAGet16(ds, 0x6ed2);
    r16[ax] = memoryAGet16(ds, 0x6ed0);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ds, 0x5656, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x6ed6);
    r16[ax] = memoryAGet16(ds, 0x6ed4);
    r8[cl] = 0x0c;
    yield* sub_10042();
    stop("stack_below");
    memoryASet16(ds, 0x5b12, r16[ax]);
    yield* sub_d606();
    yield* sub_2109();
    memoryASet16(ds, 0x5658, 0xa497);
    yield* sub_2159();
    yield* sub_2159();
    memoryASet16(ds, 0x5658, 0x0000);
    yield* sub_7b0a();
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2;
}
function* sub_c48c() // 01ed:a5bc
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    { pc = 0xc4d3; break; }
  case 0xc493:
    if (memoryAGet(ss, r16[bp] - 1) != 0x0a)
        { pc = 0xc4a5; break; }
    memoryASet16(ds, 0x82f8, memoryAGet16(ds, 0x82f8) + 1);
    r16[ax] = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, r16[ax]);
    { pc = 0xc4d3; break; }
  case 0xc4a5:
    if (memoryAGet(ss, r16[bp] - 1) != 0x0d)
        { pc = 0xc4b3; break; }
    r16[ax] = memoryAGet16(ds, 0x8354);
    memoryASet16(ds, 0x8282, r16[ax]);
    { pc = 0xc4d3; break; }
  case 0xc4b3:
    r8[al] = memoryAGet(ss, r16[bp] - 1);
    cbw();
    r16[ax] += 0x0080;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(r16[ax]);
    yield* sub_d7b0();
    sp += 0x0006;
  case 0xc4d3:
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ss, r16[bp] + 4, memoryAGet16(ss, r16[bp] + 4) + 1);
    r8[al] = memoryAGet(ds, r16[bx]);
    memoryASet(ss, r16[bp] - 1, r8[al]);
    if (r8[al])
        { pc = 0xc493; break; }
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_c4e6() // 01ed:a616
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x000e;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    if (!memoryAGet16(ds, 0x5daa))
        { pc = 0xc4fd; break; }
    r16[ax] = 0;
    { pc = 0xc95f; break; }
  case 0xc4fd:
    r16[ax] = memoryAGet16(ds, r16[si] + 32);
    imul16(memoryAGet16(ds, 0x5b14));
    r16[dx] = memoryAGet16(ds, r16[si] + 28);
    r16[dx] += r16[ax];
    memoryASet16(ds, r16[si] + 28, r16[dx]);
    r16[ax] = memoryAGet16(ds, r16[si] + 34);
    imul16(memoryAGet16(ds, 0x5b14));
    r16[dx] = memoryAGet16(ds, r16[si] + 30);
    r16[dx] += r16[ax];
    memoryASet16(ds, r16[si] + 30, r16[dx]);
    r16[ax] = 0xabca;
    push(ds);
    push(r16[ax]);
    push(ds);
    push(r16[si]);
    r16[cx] = 0x0036;
    yield* sub_1016b();
    memoryASet16(ss, r16[bp] - 14, 0x0000);
    r16[ax] = memoryAGet16(ds, 0xabe8);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabe2) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0xabe2, memoryAGet16(ds, 0xabe2) + r16[ax]);
    memoryASet16(ds, 0xabe4, memoryAGet16(ds, 0xabe4) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0xabe8);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabda) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0xabda, memoryAGet16(ds, 0xabda) + r16[ax]);
    memoryASet16(ds, 0xabdc, memoryAGet16(ds, 0xabdc) + (r16[dx] + flags.carry));
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabd8));
    push(memoryAGet16(ds, 0xabd6));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabe0));
    push(memoryAGet16(ds, 0xabde));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    if (signed16(memoryAGet16(ds, 0xabe8)) > signed16(0x0000))
        { pc = 0xc579; break; }
    { pc = 0xc65c; break; }
  case 0xc579:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabe4));
    push(memoryAGet16(ds, 0xabe2));
    yield* sub_ff73();
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, 0xabe8);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ds, 0xabe4);
    r16[cx] = memoryAGet16(ds, 0xabe2);
    flags.carry = r16[cx] < r16[ax];
    r16[cx] -= r16[ax];
    r16[bx] -= (r16[dx] + flags.carry);
    push(r16[bx]);
    push(r16[cx]);
    yield* sub_ff73();
    r16[bx] = pop();
    flags.zero = r16[bx] == r16[dx];
    r16[dx] = pop();
    if (!flags.zero)
        { pc = 0xc5b6; break; }
    if (r16[dx] != r16[ax])
        { pc = 0xc5b6; break; }
    { pc = 0xc745; break; }
  case 0xc5b6:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabe4));
    push(memoryAGet16(ds, 0xabe2));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    { pc = 0xc64e; break; }
    // gap 1 bytes
  case 0xc5d4:
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (memoryAGet16(ds, r16[bx] + 2612))
        { pc = 0xc60c; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, 0xa6e8);
    if (!(memoryAGet16(es, r16[bx]) & r16[ax]))
        { pc = 0xc64b; break; }
  case 0xc60c:
    memoryASet16(ds, r16[si] + 34, 0x0000);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, 0xabe4);
    r16[dx] = memoryAGet16(ds, 0xabe2);
    flags.carry = r16[dx] + 0x0001 >= 0x10000;
    r16[dx]++;
    r16[ax] += (0x0000 + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_ff82();
    r16[di] = r16[ax];
    memoryASet16(ds, r16[si] + 30, memoryAGet16(ds, r16[si] + 30) - r16[ax]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabda) < r16[ax];
    memoryASet16(ds, 0xabda, memoryAGet16(ds, 0xabda) - r16[ax]);
    memoryASet16(ds, 0xabdc, memoryAGet16(ds, 0xabdc) - (r16[dx] + flags.carry));
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabe2) < r16[ax];
    memoryASet16(ds, 0xabe2, memoryAGet16(ds, 0xabe2) - r16[ax]);
    memoryASet16(ds, 0xabe4, memoryAGet16(ds, 0xabe4) - (r16[dx] + flags.carry));
    memoryASet16(ss, r16[bp] - 14, 0x0001);
    { pc = 0xc745; break; }
  case 0xc64b:
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + 1);
  case 0xc64e:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    if (r16s[ax] > signed16(memoryAGet16(ss, r16[bp] - 8)))
        { pc = 0xc659; break; }
    { pc = 0xc5d4; break; }
  case 0xc659:
    { pc = 0xc745; break; }
  case 0xc65c:
    if (signed16(memoryAGet16(ds, 0xabe8)) < signed16(0x0000))
        { pc = 0xc666; break; }
    { pc = 0xc745; break; }
  case 0xc666:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabdc));
    push(memoryAGet16(ds, 0xabda));
    yield* sub_ff73();
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, 0xabe8);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ds, 0xabdc);
    r16[cx] = memoryAGet16(ds, 0xabda);
    flags.carry = r16[cx] < r16[ax];
    r16[cx] -= r16[ax];
    r16[bx] -= (r16[dx] + flags.carry);
    push(r16[bx]);
    push(r16[cx]);
    yield* sub_ff73();
    r16[bx] = pop();
    flags.zero = r16[bx] == r16[dx];
    r16[dx] = pop();
    if (!flags.zero)
        { pc = 0xc6a3; break; }
    if (r16[dx] != r16[ax])
        { pc = 0xc6a3; break; }
    { pc = 0xc745; break; }
  case 0xc6a3:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabdc));
    push(memoryAGet16(ds, 0xabda));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    { pc = 0xc73a; break; }
    // gap 1 bytes
  case 0xc6c1:
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (memoryAGet16(ds, r16[bx] + 5056))
        { pc = 0xc6f9; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, 0xa6e8);
    if (!(memoryAGet16(es, r16[bx]) & r16[ax]))
        { pc = 0xc737; break; }
  case 0xc6f9:
    memoryASet16(ds, r16[si] + 34, 0x0000);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabdc));
    push(memoryAGet16(ds, 0xabda));
    yield* sub_ff82();
    r16[dx] = 0x1000;
    r16[dx] -= r16[ax];
    r16[di] = r16[dx];
    memoryASet16(ds, r16[si] + 30, memoryAGet16(ds, r16[si] + 30) + r16[dx]);
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabda) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0xabda, memoryAGet16(ds, 0xabda) + r16[ax]);
    memoryASet16(ds, 0xabdc, memoryAGet16(ds, 0xabdc) + (r16[dx] + flags.carry));
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabe2) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0xabe2, memoryAGet16(ds, 0xabe2) + r16[ax]);
    memoryASet16(ds, 0xabe4, memoryAGet16(ds, 0xabe4) + (r16[dx] + flags.carry));
    memoryASet16(ss, r16[bp] - 14, 0x0001);
    { pc = 0xc745; break; }
  case 0xc737:
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + 1);
  case 0xc73a:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    if (r16s[ax] > signed16(memoryAGet16(ss, r16[bp] - 8)))
        { pc = 0xc745; break; }
    { pc = 0xc6c1; break; }
  case 0xc745:
    r16[ax] = memoryAGet16(ds, 0xabe6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabd6) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0xabd6, memoryAGet16(ds, 0xabd6) + r16[ax]);
    memoryASet16(ds, 0xabd8, memoryAGet16(ds, 0xabd8) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0xabe6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabde) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0xabde, memoryAGet16(ds, 0xabde) + r16[ax]);
    memoryASet16(ds, 0xabe0, memoryAGet16(ds, 0xabe0) + (r16[dx] + flags.carry));
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabdc));
    push(memoryAGet16(ds, 0xabda));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabe4));
    push(memoryAGet16(ds, 0xabe2));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    if (signed16(memoryAGet16(ds, 0xabe6)) > signed16(0x0000))
        { pc = 0xc791; break; }
    { pc = 0xc874; break; }
  case 0xc791:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabe0));
    push(memoryAGet16(ds, 0xabde));
    yield* sub_ff73();
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, 0xabe6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ds, 0xabe0);
    r16[cx] = memoryAGet16(ds, 0xabde);
    flags.carry = r16[cx] < r16[ax];
    r16[cx] -= r16[ax];
    r16[bx] -= (r16[dx] + flags.carry);
    push(r16[bx]);
    push(r16[cx]);
    yield* sub_ff73();
    r16[bx] = pop();
    flags.zero = r16[bx] == r16[dx];
    r16[dx] = pop();
    if (!flags.zero)
        { pc = 0xc7ce; break; }
    if (r16[dx] != r16[ax])
        { pc = 0xc7ce; break; }
    { pc = 0xc95c; break; }
  case 0xc7ce:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabe0));
    push(memoryAGet16(ds, 0xabde));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    { pc = 0xc866; break; }
    // gap 1 bytes
  case 0xc7ec:
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 8);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (memoryAGet16(ds, r16[bx] + 6278))
        { pc = 0xc824; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 8);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, 0xa6e8);
    if (!(memoryAGet16(es, r16[bx]) & r16[ax]))
        { pc = 0xc863; break; }
  case 0xc824:
    memoryASet16(ds, r16[si] + 32, 0x0000);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, 0xabe0);
    r16[dx] = memoryAGet16(ds, 0xabde);
    flags.carry = r16[dx] + 0x0001 >= 0x10000;
    r16[dx]++;
    r16[ax] += (0x0000 + flags.carry);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_ff82();
    r16[di] = r16[ax];
    memoryASet16(ds, r16[si] + 28, memoryAGet16(ds, r16[si] + 28) - r16[ax]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabd6) < r16[ax];
    memoryASet16(ds, 0xabd6, memoryAGet16(ds, 0xabd6) - r16[ax]);
    memoryASet16(ds, 0xabd8, memoryAGet16(ds, 0xabd8) - (r16[dx] + flags.carry));
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabde) < r16[ax];
    memoryASet16(ds, 0xabde, memoryAGet16(ds, 0xabde) - r16[ax]);
    memoryASet16(ds, 0xabe0, memoryAGet16(ds, 0xabe0) - (r16[dx] + flags.carry));
    memoryASet16(ss, r16[bp] - 14, 0x0001);
    { pc = 0xc95c; break; }
  case 0xc863:
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + 1);
  case 0xc866:
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    if (r16s[ax] > signed16(memoryAGet16(ss, r16[bp] - 12)))
        { pc = 0xc871; break; }
    { pc = 0xc7ec; break; }
  case 0xc871:
    { pc = 0xc95c; break; }
  case 0xc874:
    if (signed16(memoryAGet16(ds, 0xabe6)) < signed16(0x0000))
        { pc = 0xc87e; break; }
    { pc = 0xc95c; break; }
  case 0xc87e:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabd8));
    push(memoryAGet16(ds, 0xabd6));
    yield* sub_ff73();
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, 0xabe6);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[bx] = memoryAGet16(ds, 0xabd8);
    r16[cx] = memoryAGet16(ds, 0xabd6);
    flags.carry = r16[cx] < r16[ax];
    r16[cx] -= r16[ax];
    r16[bx] -= (r16[dx] + flags.carry);
    push(r16[bx]);
    push(r16[cx]);
    yield* sub_ff73();
    r16[bx] = pop();
    flags.zero = r16[bx] == r16[dx];
    r16[dx] = pop();
    if (!flags.zero)
        { pc = 0xc8bb; break; }
    if (r16[dx] != r16[ax])
        { pc = 0xc8bb; break; }
    { pc = 0xc95c; break; }
  case 0xc8bb:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabd8));
    push(memoryAGet16(ds, 0xabd6));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    { pc = 0xc951; break; }
    // gap 1 bytes
  case 0xc8d9:
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    if (memoryAGet16(ds, r16[bx] + 3834))
        { pc = 0xc911; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 6);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, 0xa6e8);
    if (!(memoryAGet16(es, r16[bx]) & r16[ax]))
        { pc = 0xc94e; break; }
  case 0xc911:
    memoryASet16(ds, r16[si] + 32, 0x0000);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, 0xabd8));
    push(memoryAGet16(ds, 0xabd6));
    yield* sub_ff82();
    r16[dx] = 0x1000;
    r16[dx] -= r16[ax];
    r16[di] = r16[dx];
    memoryASet16(ds, r16[si] + 28, memoryAGet16(ds, r16[si] + 28) + r16[dx]);
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabd6) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0xabd6, memoryAGet16(ds, 0xabd6) + r16[ax]);
    memoryASet16(ds, 0xabd8, memoryAGet16(ds, 0xabd8) + (r16[dx] + flags.carry));
    r16[ax] = r16[di];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0xabde) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0xabde, memoryAGet16(ds, 0xabde) + r16[ax]);
    memoryASet16(ds, 0xabe0, memoryAGet16(ds, 0xabe0) + (r16[dx] + flags.carry));
    memoryASet16(ss, r16[bp] - 14, memoryAGet16(ss, r16[bp] - 14) | 0x0001);
    { pc = 0xc95c; break; }
  case 0xc94e:
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + 1);
  case 0xc951:
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    if (r16s[ax] > signed16(memoryAGet16(ss, r16[bp] - 12)))
        { pc = 0xc95c; break; }
    { pc = 0xc8d9; break; }
  case 0xc95c:
    r16[ax] = memoryAGet16(ss, r16[bp] - 14);
  case 0xc95f:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_c965() // 01ed:aa95
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0014;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 10);
    push(r16[si]);
    yield* sub_49b9();
    sp++;
    sp++;
    if (memoryAGet16(ss, r16[bp] + 6))
        { pc = 0xc985; break; }
    if (memoryAGet16(ss, r16[bp] + 8))
        { pc = 0xc985; break; }
    { pc = 0xca31; break; }
  case 0xc985:
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, r16[si] + 14));
    push(memoryAGet16(ds, r16[si] + 12));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, r16[si] + 22));
    push(memoryAGet16(ds, r16[si] + 20));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, r16[si] + 18));
    push(memoryAGet16(ds, r16[si] + 16));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, r16[si] + 26));
    push(memoryAGet16(ds, r16[si] + 24));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    { pc = 0xca29; break; }
  case 0xc9d9:
    r16[di] = memoryAGet16(ss, r16[bp] - 6);
    { pc = 0xca21; break; }
  case 0xc9de:
    r16[ax] = r16[di];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c); es = memoryAGet16(ds, 0x6c4e);
    r16[bx] += r16[ax];
    if (!memoryAGet16(es, r16[bx]))
        { pc = 0xca20; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ss, r16[bp] - 12, r16[ax]);
    memoryASet16(ss, r16[bp] - 14, r16[di]);
    r16[ax] = r16[di];
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c4c);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[bx]);
    memoryASet16(ds, 0x6ec0, r16[ax]);
    if (r16[ax] != 0x00ff)
        { pc = 0xca20; break; }
    memoryASet16(ds, 0x6ec0, 0x0000);
  case 0xca20:
    r16[di]++;
  case 0xca21:
    if (r16s[di] <= signed16(memoryAGet16(ss, r16[bp] - 10)))
        { pc = 0xc9de; break; }
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + 1);
  case 0xca29:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    if (r16s[ax] <= signed16(memoryAGet16(ss, r16[bp] - 8)))
        { pc = 0xc9d9; break; }
  case 0xca31:
    r16[ax] = 0;
    memoryASet16(ds, r16[si] + 30, r16[ax]);
    memoryASet16(ds, r16[si] + 28, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    if (r16[bx] > 0x0007)
        { pc = 0xcaba; break; }
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0xca59; break; }
        case 2: { pc = 0xca65; break; }
        case 4: { pc = 0xca76; break; }
        case 6: { pc = 0xca82; break; }
        case 8: { pc = 0xca93; break; }
        case 10: { pc = 0xca9f; break; }
        case 12: { pc = 0xcab0; break; }
        case 14: { pc = 0xca48; break; }
        default:
            stop("ind 01ed:ab73");
    }
    break;
  case 0xca48:
    memoryASet16(ds, r16[si] + 30, 0xfc00);
    memoryASet16(ds, r16[si] + 28, 0xfc00);
    memoryASet16(ds, r16[si] + 40, 0x002c);
    { pc = 0xcaba; break; }
  case 0xca59:
    memoryASet16(ds, r16[si] + 30, 0xfc00);
    memoryASet16(ds, r16[si] + 40, 0x002c);
    { pc = 0xcaba; break; }
  case 0xca65:
    memoryASet16(ds, r16[si] + 30, 0xfc00);
    memoryASet16(ds, r16[si] + 28, 0x0400);
    memoryASet16(ds, r16[si] + 40, 0x002c);
    { pc = 0xcaba; break; }
  case 0xca76:
    memoryASet16(ds, r16[si] + 28, 0x0400);
    memoryASet16(ds, r16[si] + 40, 0x0020);
    { pc = 0xcaba; break; }
  case 0xca82:
    memoryASet16(ds, r16[si] + 30, 0x0400);
    memoryASet16(ds, r16[si] + 28, 0x0400);
    memoryASet16(ds, r16[si] + 40, 0x0024);
    { pc = 0xcaba; break; }
  case 0xca93:
    memoryASet16(ds, r16[si] + 30, 0x0400);
    memoryASet16(ds, r16[si] + 40, 0x0024);
    { pc = 0xcaba; break; }
  case 0xca9f:
    memoryASet16(ds, r16[si] + 30, 0x0400);
    memoryASet16(ds, r16[si] + 28, 0xfc00);
    memoryASet16(ds, r16[si] + 40, 0x0024);
    { pc = 0xcaba; break; }
  case 0xcab0:
    memoryASet16(ds, r16[si] + 28, 0xfc00);
    memoryASet16(ds, r16[si] + 40, 0x0028);
  case 0xcaba:
    memoryASet16(ss, r16[bp] - 16, 0x0000);
    r16[ax] = memoryAGet16(ds, r16[si] + 28);
    r16[ax] |= memoryAGet16(ds, r16[si] + 30);
    if (!r16[ax])
        { pc = 0xcad9; break; }
    r16[ax] = memoryAGet16(ds, 0x5135);
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[ax] &= 0x0003;
    memoryASet16(ss, r16[bp] - 18, r16[ax]);
    memoryASet16(ss, r16[bp] - 16, memoryAGet16(ss, r16[bp] - 16) + 1);
    { pc = 0xcade; break; }
  case 0xcad9:
    memoryASet16(ss, r16[bp] - 18, 0x0000);
  case 0xcade:
    memoryASet16(ds, 0xa6e8, 0x8000);
    if (!memoryAGet(ds, 0x503b))
        { pc = 0xcaf8; break; }
    if (!memoryAGet(ds, 0x5056))
        { pc = 0xcaf8; break; }
    memoryASet16(ds, 0xa6e8, 0x0000);
  case 0xcaf8:
    push(r16[si]);
    yield* sub_c4e6();
    sp++;
    sp++;
    memoryASet16(ss, r16[bp] - 20, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 28);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, r16[si] + 4) + r16[ax] >= 0x10000;
    memoryASet16(ds, r16[si] + 4, memoryAGet16(ds, r16[si] + 4) + r16[ax]);
    memoryASet16(ds, r16[si] + 6, memoryAGet16(ds, r16[si] + 6) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, r16[si] + 30);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, r16[si] + 8) + r16[ax] >= 0x10000;
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + r16[ax]);
    memoryASet16(ds, r16[si] + 10, memoryAGet16(ds, r16[si] + 10) + (r16[dx] + flags.carry));
    if (!memoryAGet16(ss, r16[bp] - 16))
        { pc = 0xcb3d; break; }
    r16[ax] = memoryAGet16(ds, 0x5135);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    if (r16[ax] & 0x0003)
        { pc = 0xcb3d; break; }
    if (!memoryAGet16(ss, r16[bp] - 20))
        { pc = 0xcb34; break; }
    r16[ax] = 0x0002;
    { pc = 0xcb37; break; }
  case 0xcb34:
    r16[ax] = 0x0001;
  case 0xcb37:
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
  case 0xcb3d:
    if (signed16(memoryAGet16(ds, r16[si] + 28)) <= signed16(0x0000))
        { pc = 0xcb8e; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    flags.carry = r16[dx] < memoryAGet16(ds, 0x6ed0);
    r16[dx] -= memoryAGet16(ds, 0x6ed0);
    r16[ax] -= memoryAGet16(ds, 0x6ed2) + flags.carry;
    if (r16s[ax] < 0)
        { pc = 0xcb8e; break; }
    if (r16s[ax] > 0)
        { pc = 0xcb5d; break; }
    if (r16[dx] <= 0xb000)
        { pc = 0xcb8e; break; }
  case 0xcb5d:
    r16[ax] = memoryAGet16(ds, r16[si] + 28);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x6ed0) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + r16[ax]);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x7fc0)))
        { pc = 0xcbdd; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x7fc0)))
        { pc = 0xcb7e; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x7fbe))
        { pc = 0xcbdd; break; }
  case 0xcb7e:
    r16[ax] = memoryAGet16(ds, 0x7fc0);
    r16[dx] = memoryAGet16(ds, 0x7fbe);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    { pc = 0xcbdd; break; }
  case 0xcb8e:
    if (signed16(memoryAGet16(ds, r16[si] + 28)) >= signed16(0x0000))
        { pc = 0xcbdd; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    flags.carry = r16[dx] < memoryAGet16(ds, 0x6ed0);
    r16[dx] -= memoryAGet16(ds, 0x6ed0);
    r16[ax] -= memoryAGet16(ds, 0x6ed2) + flags.carry;
    if (r16s[ax] > 0)
        { pc = 0xcbdd; break; }
    if (r16s[ax] < 0)
        { pc = 0xcbae; break; }
    if (r16[dx] >= 0x9000)
        { pc = 0xcbdd; break; }
  case 0xcbae:
    r16[ax] = memoryAGet16(ds, r16[si] + 28);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x6ed0) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x6ed0, memoryAGet16(ds, 0x6ed0) + r16[ax]);
    memoryASet16(ds, 0x6ed2, memoryAGet16(ds, 0x6ed2) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x6ed2);
    r16[dx] = memoryAGet16(ds, 0x6ed0);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x564c)))
        { pc = 0xcbdd; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x564c)))
        { pc = 0xcbcf; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x564a))
        { pc = 0xcbdd; break; }
  case 0xcbcf:
    r16[ax] = memoryAGet16(ds, 0x564c);
    r16[dx] = memoryAGet16(ds, 0x564a);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
  case 0xcbdd:
    if (signed16(memoryAGet16(ds, r16[si] + 30)) <= signed16(0x0000))
        { pc = 0xcc2e; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 10);
    r16[dx] = memoryAGet16(ds, r16[si] + 8);
    flags.carry = r16[dx] < memoryAGet16(ds, 0x6ed4);
    r16[dx] -= memoryAGet16(ds, 0x6ed4);
    r16[ax] -= memoryAGet16(ds, 0x6ed6) + flags.carry;
    if (r16s[ax] < 0)
        { pc = 0xcc2e; break; }
    if (r16s[ax] > 0)
        { pc = 0xcbfd; break; }
    if (r16[dx] <= 0x7000)
        { pc = 0xcc2e; break; }
  case 0xcbfd:
    r16[ax] = memoryAGet16(ds, r16[si] + 30);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x6ed4) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + r16[ax]);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x7fc4)))
        { pc = 0xcc7d; break; }
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x7fc4)))
        { pc = 0xcc1e; break; }
    if (r16[dx] <= memoryAGet16(ds, 0x7fc2))
        { pc = 0xcc7d; break; }
  case 0xcc1e:
    r16[ax] = memoryAGet16(ds, 0x7fc4);
    r16[dx] = memoryAGet16(ds, 0x7fc2);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    { pc = 0xcc7d; break; }
  case 0xcc2e:
    if (signed16(memoryAGet16(ds, r16[si] + 30)) >= signed16(0x0000))
        { pc = 0xcc7d; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 10);
    r16[dx] = memoryAGet16(ds, r16[si] + 8);
    flags.carry = r16[dx] < memoryAGet16(ds, 0x6ed4);
    r16[dx] -= memoryAGet16(ds, 0x6ed4);
    r16[ax] -= memoryAGet16(ds, 0x6ed6) + flags.carry;
    if (r16s[ax] > 0)
        { pc = 0xcc7d; break; }
    if (r16s[ax] < 0)
        { pc = 0xcc4e; break; }
    if (r16[dx] >= 0x3000)
        { pc = 0xcc7d; break; }
  case 0xcc4e:
    r16[ax] = memoryAGet16(ds, r16[si] + 30);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ds, 0x6ed4) + r16[ax] >= 0x10000;
    memoryASet16(ds, 0x6ed4, memoryAGet16(ds, 0x6ed4) + r16[ax]);
    memoryASet16(ds, 0x6ed6, memoryAGet16(ds, 0x6ed6) + (r16[dx] + flags.carry));
    r16[ax] = memoryAGet16(ds, 0x6ed6);
    r16[dx] = memoryAGet16(ds, 0x6ed4);
    if (r16s[ax] > signed16(memoryAGet16(ds, 0x5650)))
        { pc = 0xcc7d; break; }
    if (r16s[ax] < signed16(memoryAGet16(ds, 0x5650)))
        { pc = 0xcc6f; break; }
    if (r16[dx] >= memoryAGet16(ds, 0x564e))
        { pc = 0xcc7d; break; }
  case 0xcc6f:
    r16[ax] = memoryAGet16(ds, 0x5650);
    r16[dx] = memoryAGet16(ds, 0x564e);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
  case 0xcc7d:
    r16[dx] = memoryAGet16(ds, 0x6ed2);
    r16[ax] = memoryAGet16(ds, 0x6ed0);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ds, 0x5656, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x6ed6);
    r16[ax] = memoryAGet16(ds, 0x6ed4);
    r8[cl] = 0x0c;
    yield* sub_10042();
    memoryASet16(ds, 0x5b12, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 40);
    r16[ax] += memoryAGet16(ss, r16[bp] - 18);
    push(r16[ax]);
    push(memoryAGet16(ds, r16[si] + 10));
    push(memoryAGet16(ds, r16[si] + 8));
    push(memoryAGet16(ds, r16[si] + 6));
    push(memoryAGet16(ds, r16[si] + 4));
    yield* sub_2195();
    sp += 0x000a;
    if (!memoryAGet16(ds, 0x6ec0))
        { pc = 0xccd6; break; }
    push(memoryAGet16(ss, r16[bp] - 14));
    push(memoryAGet16(ss, r16[bp] - 12));
    push(r16[si]);
    push(memoryAGet16(ds, 0x6ec0));
    yield* sub_ccec();
    sp += 0x0008;
    if (!r16[ax])
        { pc = 0xccd6; break; }
    memoryASet16(ds, 0x6ec0, 0x0000);
  case 0xccd6:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ccec() // 01ed:ae1c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0018;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    if (memoryAGet16(ss, r16[bp] + 4) == 0x0014)
        { pc = 0xcd00; break; }
    { pc = 0xcde9; break; }
  case 0xcd00:
    r16[ax] = 0x0008;
    push(r16[ax]);
    r16[ax] = 0x0014;
    push(r16[ax]);
    yield* sub_7f8e();
    sp += 0x0004;
    r16[ax] = 0x354b;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x3572;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = 0x3584;
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    r16[ax] = memoryAGet16(ds, 0x833e);
    if (!r16[ax])
        { pc = 0xcd32; break; }
    { pc = 0xcd37; break; }
  case 0xcd32:
    r16[ax] = 0x3590;
    { pc = 0xcd3a; break; }
  case 0xcd37:
    r16[ax] = 0x3595;
  case 0xcd3a:
    push(r16[ax]);
    yield* sub_81a2();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0xaa94))
        { pc = 0xcd65; break; }
    r16[ax] = 0x0141;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] += 0xfffc;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8354);
    r16[ax] += 0x0003;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0xcd65:
    if (memoryAGet16(ds, 0xaa9c))
        { pc = 0xcd8a; break; }
    r16[ax] = 0x0142;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] += 0xfffc;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8354);
    r16[ax] += 0x0007;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0xcd8a:
    if (memoryAGet16(ds, 0xaa96))
        { pc = 0xcdaf; break; }
    r16[ax] = 0x0143;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] += 0xfffc;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8354);
    r16[ax] += 0x000b;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0xcdaf:
    if (memoryAGet16(ds, 0xaa98))
        { pc = 0xcdd4; break; }
    r16[ax] = 0x0144;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] += 0xfffc;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8354);
    r16[ax] += 0x000f;
    push(r16[ax]);
    yield* sub_d809();
    sp += 0x0006;
  case 0xcdd4:
    r16[ax] = 0x000f;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    yield* sub_d055();
    yield* sub_d606();
    r16[ax] = 0x0001;
    { pc = 0xd04f; break; }
  case 0xcde9:
    r16[di] = 0;
    { pc = 0xd045; break; }
  case 0xcdee:
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] &= 0x0020;
    if (r16[ax] == 0x0020)
        { pc = 0xcdfc; break; }
    { pc = 0xd044; break; }
  case 0xcdfc:
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] &= 0x0003;
    r16[ax]--;
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] &= 0x0003;
    r16[ax]--;
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ss, r16[bp] - 16, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    memoryASet16(ss, r16[bp] - 18, r16[ax]);
    memoryASet16(ss, r16[bp] - 14, 0x0152);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    r16[dx] = 0x000a;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    if (!memoryAGet16(ds, r16[bx] + 10390))
        { pc = 0xce3b; break; }
    memoryASet16(ss, r16[bp] - 14, 0x0156);
  case 0xce3b:
    r16[ax] = 0x0012;
    push(r16[ax]);
    yield* sub_ddc3();
    sp++;
    sp++;
    r16[di] = 0;
    { pc = 0xce89; break; }
  case 0xce48:
    yield* sub_2109();
    yield* sub_d606();
    r16[ax] = r16[di];
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    if (r16[dx])
        { pc = 0xce6a; break; }
    memoryASet16(ss, r16[bp] - 12, memoryAGet16(ss, r16[bp] - 12) + 1);
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    if (r16s[ax] <= signed16(0x0003))
        { pc = 0xce6a; break; }
    memoryASet16(ss, r16[bp] - 12, 0x0000);
  case 0xce6a:
    r16[ax] = memoryAGet16(ss, r16[bp] - 18);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 16);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    r16[ax] += memoryAGet16(ss, r16[bp] - 14);
    memoryASet16(es, r16[bx], r16[ax]);
    yield* sub_2159();
    r16[di]++;
  case 0xce89:
    if (r16s[di] < signed16(0x0010))
        { pc = 0xce48; break; }
    memoryASet16(ss, r16[bp] - 14, 0x0145);
    r16[ax] = memoryAGet16(ss, r16[bp] - 10);
    r16[dx] = 0x000a;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    if (!memoryAGet16(ds, r16[bx] + 10390))
        { pc = 0xcea9; break; }
    memoryASet16(ss, r16[bp] - 14, 0x0063);
  case 0xcea9:
    r16[ax] = memoryAGet16(ss, r16[bp] - 18);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 16);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 14);
    memoryASet16(es, r16[bx], r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] = 0x000a;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx] + 10384);
    r16[dx] = memoryAGet16(ds, r16[bx] + 10382);
    memoryASet16(ds, 0xa6fa, r16[dx]);
    memoryASet16(ds, 0xa6fc, r16[ax]);
    memoryASet16(ds, 0xaaf4, r16[dx]);
    memoryASet16(ds, 0xaaf6, r16[ax]);
    memoryASet16(ds, r16[si] + 4, r16[dx]);
    memoryASet16(ds, r16[si] + 6, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] = 0x000a;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx] + 10388);
    r16[dx] = memoryAGet16(ds, r16[bx] + 10386);
    memoryASet16(ds, 0xa6fe, r16[dx]);
    memoryASet16(ds, 0xa700, r16[ax]);
    memoryASet16(ds, 0xaaf8, r16[dx]);
    memoryASet16(ds, 0xaafa, r16[ax]);
    memoryASet16(ds, r16[si] + 8, r16[dx]);
    memoryASet16(ds, r16[si] + 10, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    flags.carry = r16[dx] + 0x7000 >= 0x10000;
    r16[dx] += 0x7000;
    r16[ax] += (0xffff + flags.carry);
    memoryASet16(ds, 0x6ed0, r16[dx]);
    memoryASet16(ds, 0x6ed2, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 10);
    r16[dx] = memoryAGet16(ds, r16[si] + 8);
    flags.carry = r16[dx] + 0xd000 >= 0x10000;
    r16[dx] += 0xd000;
    r16[ax] += (0xffff + flags.carry);
    memoryASet16(ds, 0x6ed4, r16[dx]);
    memoryASet16(ds, 0x6ed6, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, r16[si] + 6));
    push(memoryAGet16(ds, r16[si] + 4));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 16, r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0x1000;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ds, r16[si] + 10));
    push(memoryAGet16(ds, r16[si] + 8));
    yield* sub_ff73();
    memoryASet16(ss, r16[bp] - 18, r16[ax]);
    memoryASet16(ss, r16[bp] - 14, 0x0152);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] = 0x000a;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    if (!memoryAGet16(ds, r16[bx] + 10390))
        { pc = 0xcf76; break; }
    memoryASet16(ss, r16[bp] - 14, 0x0156);
  case 0xcf76:
    r16[di] = 0;
    { pc = 0xcfbb; break; }
  case 0xcf7a:
    yield* sub_2109();
    yield* sub_d606();
    r16[ax] = r16[di];
    r16[bx] = 0x0002;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    idiv16(r16[bx]);
    if (r16[dx])
        { pc = 0xcf9c; break; }
    memoryASet16(ss, r16[bp] - 12, memoryAGet16(ss, r16[bp] - 12) + 1);
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    if (r16s[ax] <= signed16(0x0003))
        { pc = 0xcf9c; break; }
    memoryASet16(ss, r16[bp] - 12, 0x0000);
  case 0xcf9c:
    r16[ax] = memoryAGet16(ss, r16[bp] - 18);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 16);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 12);
    r16[ax] += memoryAGet16(ss, r16[bp] - 14);
    memoryASet16(es, r16[bx], r16[ax]);
    yield* sub_2159();
    r16[di]++;
  case 0xcfbb:
    if (r16s[di] < signed16(0x0010))
        { pc = 0xcf7a; break; }
    memoryASet16(ss, r16[bp] - 14, 0x0145);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[dx] = 0x000a;
    imul16(r16[dx]);
    r16[bx] = r16[ax];
    if (!memoryAGet16(ds, r16[bx] + 10390))
        { pc = 0xcfdb; break; }
    memoryASet16(ss, r16[bp] - 14, 0x0063);
  case 0xcfdb:
    r16[ax] = memoryAGet16(ss, r16[bp] - 18);
    imul16(memoryAGet16(ds, 0x6c08));
    r16[ax] += memoryAGet16(ss, r16[bp] - 16);
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ds, 0x6c48); es = memoryAGet16(ds, 0x6c4a);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 14);
    memoryASet16(es, r16[bx], r16[ax]);
  case 0xcff3:
    yield* sub_2109();
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 24;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 24;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    push(memoryAGet16(ds, r16[si] + 40));
    push(memoryAGet16(ds, r16[si] + 10));
    push(memoryAGet16(ds, r16[si] + 8));
    push(memoryAGet16(ds, r16[si] + 6));
    push(memoryAGet16(ds, r16[si] + 4));
    yield* sub_2195();
    sp += 0x000a;
    yield* sub_2159();
    yield* sub_30c0();
    yield* sub_2b21();
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xcff3; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xcff3; break; }
    r16[ax] = 0x0001;
    { pc = 0xd04f; break; }
  case 0xd044:
    r16[di]++;
  case 0xd045:
    if (r16s[di] >= signed16(0x0003))
        { pc = 0xd04d; break; }
    { pc = 0xcdee; break; }
  case 0xd04d:
    r16[ax] = 0;
  case 0xd04f:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_d055() // 01ed:b185
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0014;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ss, r16[bp] - 8, 0x0000);
    r16[di] = 0;
  case 0xd064:
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    r16[ax] += 0x0009;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x8282));
    yield* sub_d7b0();
    sp += 0x0006;
    r16[si] = 0;
    { pc = 0xd0c8; break; }
  case 0xd083:
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dfb2();
    sp++;
    sp++;
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 20;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 20;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xd0c4; break; }
    if (memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xd0c4; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_dc9e();
    sp++;
    sp++;
    if (!r16[ax])
        { pc = 0xd0c7; break; }
  case 0xd0c4:
    r16[di]++;
    { pc = 0xd0cd; break; }
  case 0xd0c7:
    r16[si]++;
  case 0xd0c8:
    if (r16s[si] < signed16(0x0006))
        { pc = 0xd083; break; }
  case 0xd0cd:
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
    if (r16s[ax] <= signed16(0x0004))
        { pc = 0xd0dd; break; }
    memoryASet16(ss, r16[bp] - 8, 0x0000);
  case 0xd0dd:
    if (r16[di])
        { pc = 0xd0e3; break; }
    { pc = 0xd064; break; }
  case 0xd0e3:
    r16[ax] = r16[bp] - 6;
    push(ss);
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(ss);
    r16[ax] = r16[bp] - 14;
    push(r16[ax]);
    yield* sub_7909();
    sp += 0x0006;
    r16[ax] = r16[bp] - 14;
    push(ss);
    push(r16[ax]);
    r16[cx] = 0x0006;
    yield* sub_1016b();
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    r16[ax] |= memoryAGet16(ss, r16[bp] - 2);
    if (r16[ax])
        { pc = 0xd0e3; break; }
    yield* sub_7b0a();
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_d113() // 01ed:b243
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0006;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, 0x8282, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    memoryASet16(ds, 0x82f8, r16[ax]);
    memoryASet16(ss, r16[bp] - 6, 0x0000);
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    { pc = 0xd223; break; }
  case 0xd134:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 12);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    if (r16[ax] != 0xffff)
        { pc = 0xd14d; break; }
    { pc = 0xd22e; break; }
  case 0xd14d:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 12);
    r16[bx] += r16[ax];
    r16[di] = memoryAGet16(ds, r16[bx] + 2);
    r16[bx] = memoryAGet16(ss, r16[bp] - 4);
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    yield* sub_1010b();
    r16[bx] = r16[di];
    r16[cx] = 0;
    yield* sub_1010b();
    r16[cx] = 0xffff;
    r16[bx] = 0xffff;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) != 0x0d)
        { pc = 0xd185; break; }
    r16[di]--;
  case 0xd185:
    r16[bx] = memoryAGet16(ss, r16[bp] - 4);
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) != 0x7e)
        { pc = 0xd1a8; break; }
    memoryASet16(ss, r16[bp] - 6, 0x0080);
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + 1);
    r16[di]--;
    { pc = 0xd1ad; break; }
  case 0xd1a8:
    memoryASet16(ss, r16[bp] - 6, 0x0000);
  case 0xd1ad:
    r16[si] = 0;
    { pc = 0xd1ee; break; }
  case 0xd1b1:
    r16[bx] = memoryAGet16(ss, r16[bp] - 4);
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 10);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    yield* sub_1010b();
    r16[bx] = r16[si];
    r16[cx] = 0;
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r8[al] = memoryAGet(es, r16[bx]);
    cbw();
    r16[ax] += memoryAGet16(ss, r16[bp] - 6);
    r16[ax] &= 0x00ff;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x82f8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x8282);
    memoryASet16(ds, 0x8282, memoryAGet16(ds, 0x8282) + 1);
    push(r16[ax]);
    yield* sub_d7b0();
    sp += 0x0006;
    r16[si]++;
  case 0xd1ee:
    if (r16[si] < r16[di])
        { pc = 0xd1b1; break; }
    if (signed16(memoryAGet16(ds, 0x8282)) >= signed16(0x002b))
        { pc = 0xd216; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] += 0x0020;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x82f8));
    r16[ax] = 0x002a;
    push(r16[ax]);
    push(memoryAGet16(ds, 0x82f8));
    push(memoryAGet16(ds, 0x8282));
    yield* sub_7f5c();
    sp += 0x000a;
  case 0xd216:
    memoryASet16(ds, 0x82f8, memoryAGet16(ds, 0x82f8) + 1);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, 0x8282, r16[ax]);
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + 1);
  case 0xd223:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    if (r16[ax] >= memoryAGet16(ss, r16[bp] + 14))
        { pc = 0xd22e; break; }
    { pc = 0xd134; break; }
  case 0xd22e:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_d234() // 01ed:b364
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    r16[cx] = 0;
    r16[bx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1044a();
    if (!flags.zero)
        { pc = 0xd253; break; }
    r16[ax] = 0x359d;
    push(r16[ax]);
    yield* sub_3131();
    sp++;
    sp++;
  case 0xd253:
    r16[di] = 0;
    { pc = 0xd258; break; }
  case 0xd257:
    r16[di]++;
  case 0xd258:
    r16[bx] = r16[di];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) != 0x1a)
        { pc = 0xd257; break; }
    r16[si] = 0;
    { pc = 0xd38f; break; }
  case 0xd274:
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    r8[al] = memoryAGet(es, r16[bx]);
    memoryASet(ss, r16[bp] - 1, r8[al]);
    if (r8[al] != 0x1f)
        { pc = 0xd2a7; break; }
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    memoryASet(es, r16[bx], 0x0d);
    { pc = 0xd38e; break; }
  case 0xd2a7:
    if (memoryAGet(ss, r16[bp] - 1) == 0x0d)
        { pc = 0xd2b0; break; }
    { pc = 0xd34d; break; }
  case 0xd2b0:
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0002;
    yield* sub_1010b();
    stop("stack_below");
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) != 0x0d)
        { pc = 0xd2d2; break; }
    { pc = 0xd34d; break; }
    // gap 1 bytes
  case 0xd2d2:
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    memoryASet(es, r16[bx], 0x20);
    r16[ax] = r16[di];
    r16[ax] -= r16[si];
    push(r16[ax]);
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0001;
    yield* sub_1010b();
    push(r16[ax]);
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0001;
    yield* sub_1010b();
    push(r16[dx]);
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0002;
    yield* sub_1010b();
    push(r16[ax]);
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0002;
    yield* sub_1010b();
    push(r16[dx]);
    yield* sub_f321();
    sp += 0x000a;
    r16[di]--;
    { pc = 0xd38e; break; }
  case 0xd34d:
    if (memoryAGet(ss, r16[bp] - 1) != 0x0d)
        { pc = 0xd38e; break; }
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[cx] = 0;
    r16[bx] = 0x0002;
    yield* sub_1010b();
    stop("stack_below");
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) != 0x0d)
        { pc = 0xd38e; break; }
    { pc = 0xd376; break; }
  case 0xd374:
    r16[si]++;
    r16[si]++;
  case 0xd376:
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) == 0x0d)
        { pc = 0xd374; break; }
    r16[si]--;
  case 0xd38e:
    r16[si]++;
  case 0xd38f:
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) == 0x1a)
        { pc = 0xd3a9; break; }
    { pc = 0xd274; break; }
  case 0xd3a9:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_d3af() // 01ed:b4df
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    r16[di] = 0;
    r16[si] = 0;
  case 0xd3c5:
    memoryASet16(ss, r16[bp] - 4, 0x0000);
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ds, r16[bx], r16[ax]);
    r16[si] = r16[ax];
    { pc = 0xd46a; break; }
  case 0xd3df:
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) != 0x1a)
        { pc = 0xd431; break; }
    memoryASet16(ss, r16[bp] - 4, 0x0002);
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    r16[ax] = r16[si];
    r16[ax] -= memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[ax] = r16[di];
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    memoryASet16(ds, r16[bx], 0xffff);
    r16[ax] = r16[di];
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    memoryASet16(ds, r16[bx] + 2, 0xffff);
    { pc = 0xd477; break; }
  case 0xd431:
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) != 0x0d)
        { pc = 0xd469; break; }
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    r16[ax] = r16[si];
    r16[ax] -= memoryAGet16(ss, r16[bp] - 2);
    r16[ax]++;
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[di]++;
    r16[ax] = r16[si];
    r16[ax]++;
    r16[ax]++;
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) + 1);
    { pc = 0xd477; break; }
  case 0xd469:
    r16[si]++;
  case 0xd46a:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] += memoryAGet16(ss, r16[bp] + 10);
    if (r16[ax] <= r16[si])
        { pc = 0xd477; break; }
    { pc = 0xd3df; break; }
  case 0xd477:
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xd4d4; break; }
    { pc = 0xd4b3; break; }
  case 0xd47f:
    r16[bx] = r16[si];
    r16[cx] = 0;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    r16[bx] = r16[ax];
    es = r16[dx];
    if (memoryAGet(es, r16[bx]) != 0x20)
        { pc = 0xd4b2; break; }
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    r16[ax] = r16[si];
    r16[ax] -= memoryAGet16(ss, r16[bp] - 2);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[di]++;
    r16[ax] = r16[si];
    r16[ax]++;
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    { pc = 0xd4b8; break; }
  case 0xd4b2:
    r16[si]--;
  case 0xd4b3:
    if (r16[si] > memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xd47f; break; }
  case 0xd4b8:
    if (r16[si] != memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xd4d4; break; }
    r16[ax] = r16[di];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    r16[di]++;
    r16[si] += r16[ax];
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + r16[ax]);
  case 0xd4d4:
    if (r16[di] != memoryAGet16(ss, r16[bp] + 12))
        { pc = 0xd4ff; break; }
    r16[ax] = r16[di];
    r16[ax]--;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    memoryASet16(ds, r16[bx], 0xffff);
    r16[ax] = r16[di];
    r16[ax]--;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] += r16[ax];
    memoryASet16(ds, r16[bx] + 2, 0xffff);
    memoryASet16(ss, r16[bp] - 4, 0x0002);
  case 0xd4ff:
    if (memoryAGet16(ss, r16[bp] - 4) >= 0x0002)
        { pc = 0xd508; break; }
    { pc = 0xd3c5; break; }
  case 0xd508:
    r16[ax] = r16[di];
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_d510() // 01ed:b640
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] -= memoryAGet16(ss, r16[bp] + 4);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = 0x0030;
    imul16(r16[dx]);
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    if (!r16[ax])
        { pc = 0xd53d; break; }
    if (r16[ax] != 0x0001)
        { pc = 0xd53a; break; }
    { pc = 0xd59d; break; }
    // gap 1 bytes
  case 0xd53a:
    { pc = 0xd5ff; break; }
  case 0xd53d:
    r8[al] = 0x05;
    push(r16[ax]);
    r16[ax] = 0x03ce;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x01;
    push(r16[ax]);
    r16[ax] = 0x03cf;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x02;
    push(r16[ax]);
    r16[ax] = 0x03c4;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x0f;
    push(r16[ax]);
    r16[ax] = 0x03c5;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r16[dx] = 0x0180;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    imul16(r16[dx]);
    memoryASet16(ss, r16[bp] + 4, r16[ax]);
    push(flagAsReg());
    push(r16[si]);
    push(r16[di]);
    push(ds);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[si] = r16[di];
    r16[si] += 0x0180;
    r16[cx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ds, 0x35b4);
    es = r16[ax];
    ds = r16[ax];
    flags.direction = 0;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    ds = pop();
    r16[di] = pop();
    r16[si] = pop();
    flagsFromReg(pop());
    { pc = 0xd5ff; break; }
    // gap 1 bytes
  case 0xd59d:
    r8[al] = 0x05;
    push(r16[ax]);
    r16[ax] = 0x03ce;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x01;
    push(r16[ax]);
    r16[ax] = 0x03cf;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x02;
    push(r16[ax]);
    r16[ax] = 0x03c4;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r8[al] = 0x0f;
    push(r16[ax]);
    r16[ax] = 0x03c5;
    push(r16[ax]);
    yield* sub_f4f3();
    sp += 0x0004;
    r16[dx] = 0x0180;
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    imul16(r16[dx]);
    memoryASet16(ss, r16[bp] + 6, r16[ax]);
    memoryASet16(ss, r16[bp] + 6, memoryAGet16(ss, r16[bp] + 6) + 0x017f);
    push(flagAsReg());
    push(r16[si]);
    push(r16[di]);
    push(ds);
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    r16[si] = r16[di];
    r16[si] -= 0x0180;
    r16[cx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ds, 0x35b4);
    es = r16[ax];
    ds = r16[ax];
    flags.direction = 1;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    ds = pop();
    r16[di] = pop();
    r16[si] = pop();
    flagsFromReg(pop());
  case 0xd5ff:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_d606() // 01ed:b736
{
    sp -= 2;
    push(r16[di]);
    r16[cx] = 0x0126;
    r16[ax] = ds;
    es = r16[ax];
    r16[di] = 0x5b16;
    r16[ax] = 0xffff;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    r16[cx] = 0x0126;
    r16[di] = 0x5db8;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    r16[di] = pop();
    sp += 2;
}
function* sub_d620() // 01ed:b750
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[si]);
    push(r16[di]);
    yield* sub_d74c();
    r16[ax] = 0x0105;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    flags.direction = 0;
    r16[di] = 0;
    memoryASet16(ds, 0x35b6, r16[di]);
    r16[ax] = memoryAGet16(ds, 0x6ed5);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[bx] = memoryAGet16(ds, 0x6c06);
    mul16(r16[bx]);
    r16[bx] = r16[ax];
    r16[ax] = memoryAGet16(ds, 0x6ed1);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] <<= 1;
    r16[bx] += r16[ax];
    r16[bx] += memoryAGet16(ds, 0x6c48);
    es = memoryAGet16(ds, 0x6c4a);
    r16[bp] = memoryAGet16(ds, 0x5135);
    r8[cl] = memoryAGet(ds, 0x6c62);
    r16[bp] >>= r8[cl];
    r16[bp] &= 0x0006;
    r16[bp] = memoryAGet16(ss, r16[bp] + 20476);
    memoryASet16(ds, 0x35be, r16[bp]);
    r16[ax] = memoryAGet16(ds, 0x5652);
    if (r16[ax])
        { pc = 0xd681; break; }
    push(cs); cs = 0x1059; yield* sub_12290(); assert(cs == 0x01ed);
    { pc = 0xd686; break; }
    // gap 1 bytes
  case 0xd681:
    push(cs); cs = 0x1059; yield* sub_105dd(); assert(cs == 0x01ed);
  case 0xd686:
    push(memoryAGet16(ds, 0x35b4));
    r16[ax] = memoryAGet16(ds, 0x35b2);
    memoryASet16(ds, 0x35b4, r16[ax]);
    r16[cx] = memoryAGet16(ds, 0x6ebe);
    if (!r16[cx])
        { pc = 0xd6b1; break; }
    r16[bp] = 0;
  case 0xd698:
    push(r16[cx]);
    push(memoryAGet16(ss, r16[bp] + 24658));
    push(memoryAGet16(ss, r16[bp] + 24656));
    push(memoryAGet16(ss, r16[bp] + 24654));
    yield* sub_d9fd();
    sp += 0x0006;
    r16[cx] = pop();
    r16[bp] += 0x0006;
    if (--r16[cx])
        { pc = 0xd698; break; }
  case 0xd6b1:
    r16[cx] = memoryAGet16(ds, 0x6ed8);
    if (!r16[cx])
        { pc = 0xd6d2; break; }
    r16[bp] = 0;
  case 0xd6b9:
    push(r16[cx]);
    push(memoryAGet16(ss, r16[bp] + 27752));
    push(memoryAGet16(ss, r16[bp] + 27750));
    push(memoryAGet16(ss, r16[bp] + 27748));
    yield* sub_d809();
    sp += 0x0006;
    r16[cx] = pop();
    r16[bp] += 0x0006;
    if (--r16[cx])
        { pc = 0xd6b9; break; }
  case 0xd6d2:
    r16[cx] = memoryAGet16(ds, 0x6ecc);
    if (!r16[cx])
        { pc = 0xd6f3; break; }
    r16[bp] = 0;
  case 0xd6da:
    push(r16[cx]);
    push(memoryAGet16(ss, r16[bp] + 27662));
    push(memoryAGet16(ss, r16[bp] + 27660));
    push(memoryAGet16(ss, r16[bp] + 27658));
    yield* sub_d986();
    sp += 0x0006;
    r16[cx] = pop();
    r16[bp] += 0x0006;
    if (--r16[cx])
        { pc = 0xd6da; break; }
  case 0xd6f3:
    memoryASet16(ds, 0x35b4, pop());
    r16[cx] = memoryAGet16(ds, 0x5658);
    if (!r16[cx])
        { pc = 0xd6ff; break; }
    switch (r16[cx])
    {
        case 0xa1d4: yield* sub_c0a4(); break;
        case 0xa1eb: yield* sub_c0bb(); break;
        case 0xa497: yield* sub_c367(); break;
        case 0x95fd: yield* sub_b4cd(); break;
        case 0x97ab: yield* sub_b67b(); break;
        case 0x97f0: yield* sub_b6c0(); break;
        case 0x986c: yield* sub_b73c(); break;
        case 0x9e6d: yield* sub_bd3d(); break;
        default:
            stop("ind 01ed:b82d");
    }
  case 0xd6ff:
    r16[cx] = memoryAGet16(ds, 0x35ba);
    r16[dx] = 0x03d4;
    r8[al] = 0x0c;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = r8[ch];
    out8(r16[dx], r8[al]);
    r16[dx]--;
    r8[al] = 0x0d;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = r8[cl];
    out8(r16[dx], r8[al]);
  case 0xd715:
    r16[dx] = 0x03da;
    r8[al] = in8(r16[dx]);
    if (r8[al] & 0x08)
        { pc = 0xd715; break; }
    r16[bx] = memoryAGet16(ds, 0x35ba);
    r16[dx] = 0x03d4;
    r8[al] = 0x0c;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = r8[bh];
    out8(r16[dx], r8[al]);
    r16[dx]--;
    r8[al] = 0x0d;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = r8[bl];
    out8(r16[dx], r8[al]);
  case 0xd733:
    r16[dx] = 0x03da;
    r8[al] = in8(r16[dx]);
    if (!(r8[al] & 0x08))
        { pc = 0xd733; break; }
    r16[dx] = 0x03da;
    r8[al] = in8(r16[dx]);
    r16[dx] = 0x03c0;
    r8[al] = 0x33;
    out8(r16[dx], r8[al]);
    r16[ax] = memoryAGet16(ds, 0x35b8);
    out8(r16[dx], r8[al]);
    r16[di] = pop();
    r16[si] = pop();
    yield* sync();
    sp += 2;
    return;
  }
}
function* sub_d74c() // 01ed:b87c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    memoryASet16(ds, 0x35ba, 0x0004);
    r16[ax] = memoryAGet16(ds, 0x6ed0);
    if (!(r16[ax] & 0x0800))
        { pc = 0xd75e; break; }
    memoryASet16(ds, 0x35ba, memoryAGet16(ds, 0x35ba) + 1);
  case 0xd75e:
    r16[ax] = memoryAGet16(ds, 0x6ed1);
    r16[ax] &= 0x0007;
    memoryASet16(ds, 0x35b8, r16[ax]);
    memoryASet16(ds, 0x5652, memoryAGet16(ds, 0x5652) ^ 0x0001);
    if (memoryAGet16(ds, 0x5652) & 0x0001)
        { pc = 0xd77a; break; }
    r16[cx] = 0xa000;
    { pc = 0xd783; break; }
    // gap 1 bytes
  case 0xd77a:
    r16[cx] = 0xa300;
    memoryASet16(ds, 0x35ba, memoryAGet16(ds, 0x35ba) + 0x3000);
  case 0xd783:
    memoryASet16(ds, 0x35b2, r16[cx]);
    r16[ax] = memoryAGet16(ds, 0x6ed5);
    r16[ax] &= 0x000f;
    r8[bl] = 0x30;
    mul8(r8[bl]);
    r16[ax] += 0x0600;
    memoryASet16(ds, 0x35ba, memoryAGet16(ds, 0x35ba) + r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x35ba);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] += 0xa000;
    memoryASet16(ds, 0x35b4, r16[ax]);
    sp += 2;
    return;
  }
}
function* sub_d7b0() // 01ed:b8e0
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    es = memoryAGet16(ds, 0x35b4);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    r16[bx] <<= 1;
    r16[di] += memoryAGet16(ds, r16[bx] + 14348);
    flags.direction = 0;
    flags.interrupts = 0;
    r16[dx] = 0x03ce;
    r16[ax] = 0x0105;
    out16(r16[dx], r16[ax]);
    r16[si] = memoryAGet16(ss, r16[bp] + 8);
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[bx] = r16[si];
    r16[cx] = r16[di];
    r16[ax] = memoryAGet16(ds, 0x8300);
    ds = r16[ax];
    movsb_ESDI_DSSI();
    r16[di] += 0x002f;
    movsb_ESDI_DSSI();
    r16[di] += 0x002f;
    movsb_ESDI_DSSI();
    r16[di] += 0x002f;
    movsb_ESDI_DSSI();
    r16[di] += 0x002f;
    movsb_ESDI_DSSI();
    r16[di] += 0x002f;
    movsb_ESDI_DSSI();
    r16[di] += 0x002f;
    movsb_ESDI_DSSI();
    r16[di] += 0x002f;
    movsb_ESDI_DSSI();
    r16[di] += 0x002f;
    flags.interrupts = 1;
    r16[ax] = ss;
    ds = r16[ax];
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
}
function* sub_d809() // 01ed:b939
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    es = memoryAGet16(ds, 0x35b4);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    r16[bx] <<= 1;
    r16[di] += memoryAGet16(ds, r16[bx] + 14348);
    r16[si] = memoryAGet16(ss, r16[bp] + 8);
    if (r16s[si] < 0)
        { pc = 0xd898; break; }
    r16[si] <<= 1;
    r16[si] += memoryAGet16(ds, 0x35be);
    r16[si] = memoryAGet16(ds, r16[si]);
    r16[ax] = memoryAGet16(ds, 0x836a);
    ds = r16[ax];
    flags.direction = 0;
    flags.interrupts = 0;
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0105;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    flags.interrupts = 1;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x002e;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[ax] = ss;
    ds = r16[ax];
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2; return;
  case 0xd898:
    r16[si] &= 0x7fff;
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[ax] = memoryAGet16(ds, 0x836a);
    ds = r16[ax];
    r16[dx] = 0x03ce;
    r16[ax] = 0x0005;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03ce;
    r16[ax] = 0x0004;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
    out16(r16[dx], r16[ax]);
    push(r16[si]);
    push(r16[di]);
    r16[cx] = 0x0010;
  case 0xd8c5:
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[bx] = memoryAGet16(ds, r16[si] + 32);
    r16[dx] = memoryAGet16(ds, r16[si]);
    r16[ax] &= r16[bx];
    r16[bx] ^= 0xffff;
    r16[dx] &= r16[bx];
    r16[ax] |= r16[dx];
    stosw_ESDI(r16[ax]);
    r16[si] += 0x0002;
    r16[di] += 0x002e;
    if (--r16[cx])
        { pc = 0xd8c5; break; }
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = 0x03ce;
    r16[ax] = 0x0104;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0202;
    out16(r16[dx], r16[ax]);
    push(r16[si]);
    push(r16[di]);
    r16[cx] = 0x0010;
  case 0xd8f4:
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[bx] = memoryAGet16(ds, r16[si] + 32);
    r16[dx] = memoryAGet16(ds, r16[si]);
    r16[ax] &= r16[bx];
    r16[bx] ^= 0xffff;
    r16[dx] &= r16[bx];
    r16[ax] |= r16[dx];
    stosw_ESDI(r16[ax]);
    r16[si] += 0x0002;
    r16[di] += 0x002e;
    if (--r16[cx])
        { pc = 0xd8f4; break; }
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = 0x03ce;
    r16[ax] = 0x0204;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0402;
    out16(r16[dx], r16[ax]);
    push(r16[si]);
    push(r16[di]);
    r16[cx] = 0x0010;
  case 0xd923:
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[bx] = memoryAGet16(ds, r16[si] + 32);
    r16[dx] = memoryAGet16(ds, r16[si]);
    r16[ax] &= r16[bx];
    r16[bx] ^= 0xffff;
    r16[dx] &= r16[bx];
    r16[ax] |= r16[dx];
    stosw_ESDI(r16[ax]);
    r16[si] += 0x0002;
    r16[di] += 0x002e;
    if (--r16[cx])
        { pc = 0xd923; break; }
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = 0x03ce;
    r16[ax] = 0x0304;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0802;
    out16(r16[dx], r16[ax]);
    push(r16[si]);
    push(r16[di]);
    r16[cx] = 0x0010;
  case 0xd952:
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[bx] = memoryAGet16(ds, r16[si] + 32);
    r16[dx] = memoryAGet16(ds, r16[si]);
    r16[ax] &= r16[bx];
    r16[bx] ^= 0xffff;
    r16[dx] &= r16[bx];
    r16[ax] |= r16[dx];
    stosw_ESDI(r16[ax]);
    r16[si] += 0x0002;
    r16[di] += 0x002e;
    if (--r16[cx])
        { pc = 0xd952; break; }
    r16[di] = pop();
    r16[si] = pop();
    r16[ax] = 0x0105;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    r8[ah] = 0x0f;
    out16(r16[dx], r16[ax]);
    flags.interrupts = 1;
    r16[ax] = ss;
    ds = r16[ax];
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_d986() // 01ed:bab6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 8);
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[si] <<= 1;
    es = memoryAGet16(ds, 0x8366);
    r16[ax] = memoryAGet16(es, r16[si]);
    memoryASet16(cs, 0xb8da, r16[ax]);
    r16[ax] = memoryAGet16(es, r16[si] + 2);
    memoryASet16(cs, 0xb8de, r16[ax]);
    r16[si] = memoryAGet16(es, r16[si] + 4);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(cs, 0xb8dc, r16[ax]);
    es = memoryAGet16(ds, 0x35b4);
    flags.direction = 0;
    flags.interrupts = 0;
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r8[al] = 0x0f;
    r16[dx]++;
    out8(r16[dx], r8[al]);
    r16[dx] = 0x03ce;
    r8[al] = 0x05;
    out8(r16[dx], r8[al]);
    r8[al] = 0x01;
    r16[dx]++;
    out8(r16[dx], r8[al]);
    flags.interrupts = 1;
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    r16[bx] <<= 1;
    r16[cx] = memoryAGet16(ds, 0x834c);
    ds = r16[cx];
  case 0xd9da:
    r16[di] = memoryAGet16(ss, r16[bx] + 14348);
    r16[bx] += 0x0002;
    r16[di] += memoryAGet16(cs, 0xb8dc);
    r16[cx] = memoryAGet16(cs, 0xb8da);
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    memoryASet16(cs, 0xb8de, memoryAGet16(cs, 0xb8de) - 1);
    if (memoryAGet16(cs, 0xb8de))
        { pc = 0xd9da; break; }
    r16[ax] = ss;
    ds = r16[ax];
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_d9fd() // 01ed:bb2d
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    r16[bx] <<= 1;
    r16[ax] += memoryAGet16(ds, r16[bx] + 14348);
    memoryASet16(ds, 0x5022, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    es = memoryAGet16(ds, 0x8350);
    r16[ax] = memoryAGet16(es, r16[bx] + 2);
    memoryASet16(ds, 0x5018, r16[ax]);
    r16[ax] = memoryAGet16(es, r16[bx] + 4);
    memoryASet16(ds, 0x501a, r16[ax]);
    r16[bx] = memoryAGet16(es, r16[bx]);
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 20484);
    memoryASet16(ds, 0x5016, r16[ax]);
    r16[ax] = 0x0003;
    memoryASet16(ds, 0x5024, r16[ax]);
    es = memoryAGet16(ds, 0x35b4);
    flags.direction = 0;
    flags.interrupts = 0;
    r16[dx] = 0x03ce;
    r16[ax] = 0x0005;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03ce;
    r16[ax] = 0x0004;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
    out16(r16[dx], r16[ax]);
    r16[di] = memoryAGet16(ds, 0x5022);
    r16[cx] = memoryAGet16(ds, 0x5018);
    r16[si] = memoryAGet16(ds, 0x501a);
    r16[bp] = memoryAGet16(ds, 0x501e);
    r16[ax] = memoryAGet16(ds, 0x82e8);
    ds = memoryAGet16(ds, 0x82e0);
    switch (r16[bx])
    {
        case 0: yield* sub_1ed0(); break;
        case 2: yield* sub_db0b(); break;
        case 4: yield* sub_db24(); break;
        case 6: yield* sub_db3f(); break;
        case 8: yield* sub_db65(); break;
        default:
            stop("ind 01ed:bba4");
    }
    r16[dx] = 0x03ce;
    r16[ax] = 0x0104;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0202;
    out16(r16[dx], r16[ax]);
    r16[di] = memoryAGet16(ds, 0x5022);
    r16[cx] = memoryAGet16(ds, 0x5018);
    r16[si] = memoryAGet16(ds, 0x501a);
    r16[bp] = memoryAGet16(ds, 0x501e);
    r16[ax] = memoryAGet16(ds, 0x82e8);
    ds = memoryAGet16(ds, 0x82e2);
    switch (r16[bx])
    {
        case 0: yield* sub_1ed0(); break;
        case 2: yield* sub_db0b(); break;
        case 4: yield* sub_db24(); break;
        case 6: yield* sub_db3f(); break;
        case 8: yield* sub_db65(); break;
        default:
            stop("ind 01ed:bbce");
    }
    r16[dx] = 0x03ce;
    r16[ax] = 0x0204;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0402;
    out16(r16[dx], r16[ax]);
    r16[di] = memoryAGet16(ds, 0x5022);
    r16[cx] = memoryAGet16(ds, 0x5018);
    r16[si] = memoryAGet16(ds, 0x501a);
    r16[bp] = memoryAGet16(ds, 0x501e);
    r16[ax] = memoryAGet16(ds, 0x82e8);
    ds = memoryAGet16(ds, 0x82e4);
    switch (r16[bx])
    {
        case 0: yield* sub_1ed0(); break;
        case 2: yield* sub_db0b(); break;
        case 4: yield* sub_db24(); break;
        case 6: yield* sub_db3f(); break;
        case 8: yield* sub_db65(); break;
        default:
            stop("ind 01ed:bbf8");
    }
    r16[dx] = 0x03ce;
    r16[ax] = 0x0304;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0802;
    out16(r16[dx], r16[ax]);
    r16[di] = memoryAGet16(ds, 0x5022);
    r16[cx] = memoryAGet16(ds, 0x5018);
    r16[si] = memoryAGet16(ds, 0x501a);
    r16[bp] = memoryAGet16(ds, 0x501e);
    r16[ax] = memoryAGet16(ds, 0x82e8);
    ds = memoryAGet16(ds, 0x82e6);
    switch (r16[bx])
    {
        case 0: yield* sub_1ed0(); break;
        case 2: yield* sub_db0b(); break;
        case 4: yield* sub_db24(); break;
        case 6: yield* sub_db3f(); break;
        case 8: yield* sub_db65(); break;
        default:
            stop("ind 01ed:bc22");
    }
    r16[ax] = 0x0105;
    r16[dx] = 0x03ce;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    r8[ah] = 0x0f;
    out16(r16[dx], r16[ax]);
    flags.interrupts = 1;
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
}
function* sub_db0b() // 01ed:bc3b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    ss = r16[ax];
  case 0xdb0d:
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] &= memoryAGet(ss, r16[si]);
    r8[al] |= memoryAGet(ds, r16[si]);
    stosb_ESDI(r8[al]);
    r16[si]++;
    r16[di] += 0x002f;
    if (--r16[cx])
        { pc = 0xdb0d; break; }
    r16[ax] = 0x14f2;
    ds = r16[ax];
    ss = r16[ax];
    sp += 2;
    return;
  }
}
function* sub_db24() // 01ed:bc54
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    ss = r16[ax];
  case 0xdb26:
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[ax] &= memoryAGet16(ss, r16[si]);
    r16[ax] |= memoryAGet16(ds, r16[si]);
    stosw_ESDI(r16[ax]);
    r16[si] += 0x0002;
    r16[di] += 0x002e;
    if (--r16[cx])
        { pc = 0xdb26; break; }
    r16[ax] = 0x14f2;
    ds = r16[ax];
    ss = r16[ax];
    sp += 2;
    return;
  }
}
function* sub_db3f() // 01ed:bc6f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    ss = r16[ax];
  case 0xdb41:
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[ax] &= memoryAGet16(ss, r16[si]);
    r16[ax] |= memoryAGet16(ds, r16[si]);
    stosw_ESDI(r16[ax]);
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] &= memoryAGet(ss, r16[si] + 2);
    r8[al] |= memoryAGet(ds, r16[si] + 2);
    stosb_ESDI(r8[al]);
    r16[si] += 0x0003;
    r16[di] += 0x002d;
    if (--r16[cx])
        { pc = 0xdb41; break; }
    r16[ax] = 0x14f2;
    ds = r16[ax];
    ss = r16[ax];
    sp += 2;
    return;
  }
}
function* sub_db65() // 01ed:bc95
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    ss = r16[ax];
  case 0xdb67:
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[ax] &= memoryAGet16(ss, r16[si]);
    r16[ax] |= memoryAGet16(ds, r16[si]);
    stosw_ESDI(r16[ax]);
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[ax] &= memoryAGet16(ss, r16[si] + 2);
    r16[ax] |= memoryAGet16(ds, r16[si] + 2);
    stosw_ESDI(r16[ax]);
    r16[si] += 0x0004;
    r16[di] += 0x002c;
    if (--r16[cx])
        { pc = 0xdb67; break; }
    r16[ax] = 0x14f2;
    ds = r16[ax];
    ss = r16[ax];
    sp += 2;
    return;
  }
}
function* sub_dc65() // 01ed:bd95
{
    sp -= 2;
    r16[ax] = 0x3509;
    interrupt(0x21);
    memoryASet16(ds, 0x5028, r16[bx]);
    r16[ax] = es;
    memoryASet16(ds, 0x502a, r16[ax]);
    push(ds);
    push(cs);
    ds = pop();
    r16[dx] = 0xbe1a;
    r16[ax] = 0x2509;
    interrupt(0x21);
    ds = pop();
    sp += 2;
}
function* sub_dc80() // 01ed:bdb0
{
    sp -= 2;
    push(ds);
    r16[dx] = memoryAGet16(ds, 0x5028);
    ds = memoryAGet16(ds, 0x502a);
    r16[ax] = 0x2509;
    interrupt(0x21);
    r16[ax] = 0x0040;
    ds = r16[ax];
    r16[ax] = memoryAGet16(ds, 0x0017);
    r16[ax] &= 0xfcf0;
    memoryASet16(ds, 0x0017, r16[ax]);
    ds = pop();
    sp += 2;
}
function* sub_dc9e() // 01ed:bdce
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r8[bh] = 0;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    if (r16[ax])
        { pc = 0xdcc8; break; }
  case 0xdcaa:
    r8[bl] = memoryAGet(ds, 0x50ac);
    if (r8s[bl] >= 0)
        { pc = 0xdcaa; break; }
    r8[bl] &= 0x7f;
    memoryASet(ds, 0x50ac, r8[bl]);
    r8[ah] = r8[bl];
    r8[al] = memoryAGet(ds, r16[bx] + 20656);
    if (!r8[al])
        { pc = 0xdcaa; break; }
    memoryASet(ds, 0x50ae, r8[al]);
    r16[bp] = pop();
    sp += 2; return;
  case 0xdcc8:
    r8[bl] = memoryAGet(ds, 0x50ac);
    if (r8[bl] & 0x80)
        { pc = 0xdcd6; break; }
    r16[ax] = 0x0000;
    r16[bp] = pop();
    sp += 2; return;
  case 0xdcd6:
    r8[bl] &= 0x7f;
    r8[ah] = r8[bl];
    r8[al] = memoryAGet(ds, r16[bx] + 20656);
    memoryASet(ds, 0x50ae, r8[al]);
    if (r8[al])
        { pc = 0xdce8; break; }
    r8[ah] = 0;
  case 0xdce8:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_dcea() // 01ed:be1a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[ax]);
    push(r16[bx]);
    push(ds);
    r16[ax] = 0x14f2;
    ds = r16[ax];
    r8[ah] = 0;
    r8[al] = in8(0x60);
    if (r8s[al] >= 0)
        { pc = 0xdd05; break; }
    r8[al] &= 0x7f;
    r16[bx] = r16[ax];
    memoryASet(ds, r16[bx] + 20524, r8[ah]);
    { pc = 0xdd15; break; }
    // gap 1 bytes
  case 0xdd05:
    memoryASet(ds, 0x50ac, r8[al]);
    memoryASet(ds, 0x50ac, memoryAGet(ds, 0x50ac) | 0x80);
    r16[bx] = r16[ax];
    r8[al] = 0x01;
    memoryASet(ds, r16[bx] + 20524, r8[al]);
  case 0xdd15:
    if (!(memoryAGet16(ds, 0x5026) & 0x0001))
        { pc = 0xdd2d; break; }
    push(flagAsReg());
    push(cs); cs = memoryAGet16(ds, 0x502a); indirectCall(cs, memoryAGet16(ds, 0x5028)); assert(cs == 0x01ed); // 01ed:be4e
    r16[ax] = 0x0040;
    ds = r16[ax];
    r16[ax] = memoryAGet16(ds, 0x001a);
    memoryASet16(ds, 0x001c, r16[ax]);
  case 0xdd2d:
    r8[al] = 0x20;
    out8(0x20, r8[al]);
    ds = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    stop("iret"); return;
    return;
  }
}
function* sub_dd35() // 01ed:be65
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        { pc = 0xdd3e; break; }
    sp += 2; return;
  case 0xdd3e:
    if (memoryAGet16(ds, 0x513d) & 0xffff)
        { pc = 0xdd80; break; }
    yield* sub_ddfa();
    r16[ax] = 0x3508;
    interrupt(0x21);
    memoryASet16(ds, 0x5145, r16[bx]);
    r16[ax] = es;
    memoryASet16(ds, 0x5147, r16[ax]);
    r16[ax] = 0x0008;
    memoryASet(ds, 0x5149, r8[al]);
    push(ds);
    push(cs);
    ds = pop();
    r16[dx] = 0xbf97;
    r16[ax] = 0x2508;
    interrupt(0x21);
    ds = pop();
    r16[bx] = 0x2000;
    flags.interrupts = 0;
    r8[al] = 0x36;
    out8(0x43, r8[al]);
    r8[al] = 0x00;
    r8[al] = r8[bl];
    out8(0x40, r8[al]);
    r8[al] = r8[bh];
    out8(0x40, r8[al]);
    flags.interrupts = 1;
    memoryASet16(ds, 0x513d, memoryAGet16(ds, 0x513d) + 1);
  case 0xdd80:
    r16[ax] = 0x0001;
    memoryASet16(ds, 0x5143, r16[ax]);
    sp += 2;
    return;
  }
}
function* sub_dd87() // 01ed:beb7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        { pc = 0xdd90; break; }
    sp += 2; return;
  case 0xdd90:
    flags.interrupts = 0;
    r8[al] = 0x36;
    out8(0x43, r8[al]);
    r8[al] = 0x00;
    out8(0x40, r8[al]);
    out8(0x40, r8[al]);
    flags.interrupts = 1;
    r16[ax] = memoryAGet16(ds, 0x513d);
    if (!r16[ax])
        { pc = 0xddc2; break; }
    push(ds);
    r16[dx] = memoryAGet16(ds, 0x5145);
    r16[ax] = memoryAGet16(ds, 0x5147);
    ds = r16[ax];
    r16[ax] = 0x2508;
    interrupt(0x21);
    ds = pop();
    memoryASet16(ds, 0x513d, 0x0000);
    flags.interrupts = 0;
    r8[al] = in8(0x61);
    r8[al] &= 0xfd;
    out8(0x61, r8[al]);
    flags.interrupts = 1;
  case 0xddc2:
    sp += 2; return;
    return;
  }
}
function* sub_ddc3() // 01ed:bef3
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        { pc = 0xddd2; break; }
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2; return;
  case 0xddd2:
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[si] = r16[ax];
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[si] <<= 1;
    r16[ax] = memoryAGet16(ds, 0x5141);
    es = r16[ax];
    r8[al] = memoryAGet(es, r16[si] + 2);
    if (r8[al] < memoryAGet(ds, 0x514c))
        { pc = 0xddf7; break; }
    memoryASet(ds, 0x514c, r8[al]);
    r16[ax] = memoryAGet16(es, r16[si]);
    memoryASet16(ds, 0x514a, r16[ax]);
  case 0xddf7:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ddfa() // 01ed:bf2a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        { pc = 0xde03; break; }
    sp += 2; return;
  case 0xde03:
    r16[ax] = 0;
    memoryASet16(ds, 0x514a, r16[ax]);
    memoryASet(ds, 0x514c, r8[al]);
    flags.interrupts = 0;
    r8[al] = in8(0x61);
    r8[al] &= 0xfd;
    out8(0x61, r8[al]);
    flags.interrupts = 1;
    sp += 2;
    return;
  }
}
function* sub_de14() // 01ed:bf44
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        { pc = 0xde1d; break; }
    sp += 2; return;
  case 0xde1d:
    r16[ax] = memoryAGet16(ds, 0x514a);
    memoryASet16(ds, 0x514d, r16[ax]);
    r8[al] = memoryAGet(ds, 0x514c);
    memoryASet(ds, 0x514f, r8[al]);
    r8[al] = memoryAGet(ds, 0x5149);
    memoryASet(ds, 0x5150, r8[al]);
    yield* sub_ddfa();
    sp += 2;
    return;
  }
}
function* sub_de33() // 01ed:bf63
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        { pc = 0xde3c; break; }
    sp += 2; return;
  case 0xde3c:
    r16[ax] = memoryAGet16(ds, 0x514d);
    memoryASet16(ds, 0x514a, r16[ax]);
    r8[al] = memoryAGet(ds, 0x514f);
    memoryASet(ds, 0x514c, r8[al]);
    r8[al] = memoryAGet(ds, 0x5150);
    memoryASet(ds, 0x5149, r8[al]);
    sp += 2;
    return;
  }
}
function* sub_de4f() // 01ed:bf7f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (!(memoryAGet16(ds, 0x5151) & 0xffff))
        { pc = 0xde58; break; }
    sp += 2; return;
  case 0xde58:
    push(flagAsReg());
    push(cs);
    yield* sub_de67();
  case 0xde5e:
    yield* sync();
    r16[ax] = memoryAGet16(ds, 0x514a);
    if (r16[ax])
        { pc = 0xde5e; break; }
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_de67() // 01ed:bf97
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp += 2;
    sp -= 2;
    sp += 2;
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[si]);
    push(ds);
    push(es);
    r16[ax] = 0x14f2;
    ds = r16[ax];
    r16[ax] = memoryAGet16(ds, 0x5141);
    es = r16[ax];
    r8[al] = 0x20;
    out8(0x20, r8[al]);
    flags.carry = memoryAGet16(ds, 0x5135) + 0x0001 >= 0x10000;
    memoryASet16(ds, 0x5135, memoryAGet16(ds, 0x5135) + 0x0001);
    memoryASet16(ds, 0x5137, memoryAGet16(ds, 0x5137) + (0x0000 + flags.carry));
    memoryASet(ds, 0x5149, memoryAGet(ds, 0x5149) - 1);
    if (memoryAGet(ds, 0x5149))
        { pc = 0xde95; break; }
    r8[al] = 0x08;
    memoryASet(ds, 0x5149, r8[al]);
    push(flagAsReg());
    push(cs); cs = memoryAGet16(ds, 0x5147); indirectCall(cs, memoryAGet16(ds, 0x5145)); assert(cs == 0x01ed); // 01ed:bfc1
  case 0xde95:
    r16[si] = memoryAGet16(ds, 0x514a);
    if (!r16[si])
        { pc = 0xdeb9; break; }
    r16[bx] = memoryAGet16(es, r16[si]);
    memoryASet16(ds, 0x514a, memoryAGet16(ds, 0x514a) + 1);
    memoryASet16(ds, 0x514a, memoryAGet16(ds, 0x514a) + 1);
    if (!r16[bx])
        { pc = 0xdeb9; break; }
    if (r16[bx] != 0xffff)
        { pc = 0xdec2; break; }
    yield* sub_ddfa();
    { pc = 0xdedc; break; }
    // gap 1 bytes
  case 0xdeb9:
    r8[al] = in8(0x61);
    r8[al] &= 0xfc;
    out8(0x61, r8[al]);
    { pc = 0xdedc; break; }
    // gap 1 bytes
  case 0xdec2:
    if (!(memoryAGet16(ds, 0x5143) & 0x00ff))
        { pc = 0xdeb9; break; }
    r8[al] = 0xb6;
    out8(0x43, r8[al]);
    r8[al] = r8[bl];
    out8(0x42, r8[al]);
    r8[al] = r8[bh];
    out8(0x42, r8[al]);
    r8[al] = in8(0x61);
    r8[al] |= 0x03;
    out8(0x61, r8[al]);
  case 0xdedc:
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_dee3() // 01ed:c013
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = ds;
    es = r16[ax];
    r16[di] = 0x525f;
    r16[si] = 0x5281;
    r16[cx] = 0x0011;
    flags.direction = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    memoryASet16(ds, 0x525d, 0x0000);
    memoryASet16(ds, 0x5259, 0x0022);
    memoryASet16(ds, 0x525b, 0x000a);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    if (!r16[ax])
        { pc = 0xdf20; break; }
    r8[ah] = 0x2c;
    interrupt(0x21);
    memoryASet16(ds, 0x527f, r16[dx]);
    r16[dx] ^= r16[cx];
    memoryASet16(ds, 0x5267, r16[dx]);
  case 0xdf20:
    r16[ax] = 0xffff;
    push(r16[ax]);
    yield* sub_df2c();
    r16[ax] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_df2c() // 01ed:c05c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    push(r16[ax]);
    r16[dx] = 0xffff;
  case 0xdf37:
    flags.carry = !!(r16[ax] & 0x8000);
    r16[ax] <<= 1;
    if (flags.carry)
        { pc = 0xdf3f; break; }
    r16[dx] >>= 1;
    { pc = 0xdf37; break; }
  case 0xdf3f:
    r16[bx] = memoryAGet16(ds, 0x5259);
    r16[si] = memoryAGet16(ds, 0x525b);
    r16[ax] = memoryAGet16(ds, r16[bx] + 21085);
    r16[ax] += memoryAGet16(ds, r16[si] + 21085) + flags.carry;
    memoryASet16(ds, r16[bx] + 21085, r16[ax]);
    r16[ax] += memoryAGet16(ds, 0x525d);
    memoryASet16(ds, 0x525d, r16[ax]);
    r16[bx]--;
    r16[bx]--;
    if (r16[bx])
        { pc = 0xdf61; break; }
    r16[bx] = 0x0022;
  case 0xdf61:
    r16[si]--;
    r16[si]--;
    if (r16[si])
        { pc = 0xdf68; break; }
    r16[si] = 0x0022;
  case 0xdf68:
    memoryASet16(ds, 0x5259, r16[bx]);
    memoryASet16(ds, 0x525b, r16[si]);
    r16[cx] = pop();
    r16[ax] &= r16[dx];
    if (r16[ax] <= r16[cx])
        { pc = 0xdf79; break; }
    r16[ax] >>= 1;
  case 0xdf79:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_df7c() // 01ed:c0ac
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    if (r16[ax])
        { pc = 0xdf8e; break; }
    r16[dx] = 0x0000;
    { pc = 0xdf96; break; }
    // gap 1 bytes
  case 0xdf8e:
    r8[ah] = 0x2c;
    interrupt(0x21);
    r16[dx] &= 0x00ff;
  case 0xdf96:
    memoryASet16(ds, 0x5157, r16[dx]);
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_df9e() // 01ed:c0ce
{
    sp -= 2;
    r16[bx] = memoryAGet16(ds, 0x5157);
    r16[bx]++;
    r16[bx] &= 0x00ff;
    memoryASet16(ds, 0x5157, r16[bx]);
    r8[al] = memoryAGet(ds, r16[bx] + 20825);
    r8[ah] = 0;
    sp += 2;
}
function* sub_dfb2() // 01ed:c0e2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[cx] = memoryAGet16(ss, r16[bp] + 4);
  case 0xdfb9:
    r16[dx] = 0x03da;
    r8[al] = in8(r16[dx]);
    if (r8[al] & 0x08)
        { pc = 0xdfb9; break; }
  case 0xdfc1:
    r16[dx] = 0x03da;
    r8[al] = in8(r16[dx]);
    if (!(r8[al] & 0x08))
        { pc = 0xdfc1; break; }
    r16[bx] = 0x0064;
  case 0xdfcc:
    r16[bx]--;
    if (r16[bx])
        { pc = 0xdfcc; break; }
    if (--r16[cx])
        { pc = 0xdfb9; break; }
    r16[si] = pop();
    r16[bp] = pop();
    yield* sync();
    sp += 2;
    return;
  }
}
function* sub_dfd4() // 01ed:c104
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    flags.interrupts = 0;
    r16[dx] = 0x03ce;
    r16[ax] = 0x0005;
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03ce;
    r8[al] = 0x04;
    r8[ah] = memoryAGet(ss, r16[bp] + 4);
    out16(r16[dx], r16[ax]);
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    r8[ah] = 0x01;
    r8[cl] = memoryAGet(ss, r16[bp] + 4);
    r8[ah] <<= r8[cl];
    out16(r16[dx], r16[ax]);
    flags.interrupts = 1;
    r16[bp] = pop();
    sp += 2;
}
function* sub_e039() // 01ed:c169
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(ds);
    push(r16[si]);
    push(r16[di]);
    push(cs);
    ds = pop();
    r16[di] = 0xc139;
    memoryASet16(ds, r16[di], 0x0000);
    memoryASet16(ds, r16[di] + 2, 0x0000);
    memoryASet(ds, 0xc163, 0x01);
    memoryASet(ds, 0xc160, 0x01);
    memoryASet(ds, 0xc166, 0x01);
    r16[cx] = 0x0004;
    r16[si] = 0xc15d;
  case 0xe062:
    r8[al] = lodsb_DSSI();
    flags.zero = r8[al] == 0;
    r16[ax] = lodsw_DSSI();
    if (flags.zero)
        { pc = 0xe06e; break; }
    push(r16[si]);
    push(r16[cx]);
    switch (r16[ax])
    {
        case 0xc1af: yield* sub_e07f(); break;
        default:
            stop("ind 01ed:c19a");
    }
    r16[cx] = pop();
    r16[si] = pop();
  case 0xe06e:
    if (--r16[cx])
        { pc = 0xe062; break; }
    yield* sub_e167();
    r8[al] = memoryAGet(ds, 0xc139);
    r8[ah] = 0x00;
    r16[di] = pop();
    r16[si] = pop();
    ds = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e07f() // 01ed:c1af
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[ax] = 0x1a00;
    interrupt(0x10);
    if (r8[al] != 0x1a)
        { pc = 0xe0ce; break; }
    r16[cx] = r16[bx];
    r8[bh] = 0;
    if (!r8[ch])
        { pc = 0xe09f; break; }
    r8[bl] = r8[ch];
    r16[bx] += r16[bx];
    r16[ax] = memoryAGet16(ds, r16[bx] + 49475);
    memoryASet16(ds, r16[di] + 2, r16[ax]);
    r8[bl] = r8[cl];
    r8[bh] = 0;
  case 0xe09f:
    r16[bx] += r16[bx];
    r16[ax] = memoryAGet16(ds, r16[bx] + 49475);
    memoryASet16(ds, r16[di], r16[ax]);
    memoryASet(ds, 0xc163, 0x00);
    memoryASet(ds, 0xc160, 0x00);
    memoryASet(ds, 0xc166, 0x00);
    r16[bx] = r16[di];
    if (memoryAGet(ds, r16[bx]) == 0x01)
        { pc = 0xe0c5; break; }
    r16[bx] = r16[di] + 2;
    if (memoryAGet(ds, r16[bx]) != 0x01)
        { pc = 0xe0ce; break; }
  case 0xe0c5:
    memoryASet16(ds, r16[bx], 0x0000);
    memoryASet(ds, 0xc166, 0x01);
  case 0xe0ce:
    sp += 2; return;
    return;
  }
}
function* sub_e167() // 01ed:c297
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (!memoryAGet16(ds, r16[di] + 2))
        { pc = 0xe197; break; }
    if (signed8(memoryAGet(ds, r16[di])) >= signed8(0x04))
        { pc = 0xe197; break; }
    if (signed8(memoryAGet(ds, r16[di] + 2)) >= signed8(0x04))
        { pc = 0xe197; break; }
    r8[ah] = 0x0f;
    interrupt(0x10);
    r8[al] &= 0x07;
    if (r8[al] == 0x07)
        { pc = 0xe18a; break; }
    if (memoryAGet(ds, r16[di] + 1) != 0x01)
        { pc = 0xe197; break; }
    { pc = 0xe190; break; }
  case 0xe18a:
    if (memoryAGet(ds, r16[di] + 1) == 0x01)
        { pc = 0xe197; break; }
  case 0xe190:
    r16[ax] = memoryAGet16(ds, r16[di]);
    r16[tx] = memoryAGet16(ds, r16[di] + 2); memoryASet16(ds, r16[di] + 2, r16[ax]); r16[ax] = r16[tx];
    memoryASet16(ds, r16[di], r16[ax]);
  case 0xe197:
    sp += 2; return;
    return;
  }
}
function* sub_e1a5() // 01ed:c2d5
{
    sp -= 2;
    memoryASet16(ds, 0x52c5, 0x0000);
    memoryASet16(ds, 0x52c8, 0x0001);
    memoryASet16(ds, 0x52c1, 0x0000);
    memoryASet16(ds, 0x52c3, 0x0000);
    r16[si] = memoryAGet16(ds, 0x52bb);
    r16[di] = memoryAGet16(ds, 0x52b9);
    sp += 2;
}
function* sub_e22f() // 01ed:c35f
{
  var pc = 0;
  var temp_cf;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    yield* sub_e1a5();
    r16[tx] = r16[di]; r16[di] = r16[si]; r16[si] = r16[tx];
    r16[dx] = 0x0001;
  case 0xe237:
    es = memoryAGet16(ds, 0x52b7);
    r8[ah] = 0;
  case 0xe23d:
    if (r16[di] < 0xfff0)
        { pc = 0xe266; break; }
    r16[ax] = r16[di];
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    memoryASet16(ds, 0x52b7, memoryAGet16(ds, 0x52b7) + r16[ax]);
    r16[di] = 0x0000;
    r16[ax] = r16[si];
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    memoryASet16(ds, 0x52b5, memoryAGet16(ds, 0x52b5) + r16[ax]);
    r16[si] &= 0x000f;
    { pc = 0xe237; break; }
  case 0xe266:
    flags.carry = memoryAGet16(ds, 0x52bd) < r16[dx];
    memoryASet16(ds, 0x52bd, memoryAGet16(ds, 0x52bd) - r16[dx]);
    temp_cf = flags.carry;
    temp_cf = memoryAGet16(ds, 0x52bf) < 0x0000 + flags.carry;
    memoryASet16(ds, 0x52bf, memoryAGet16(ds, 0x52bf) - (0x0000 + flags.carry));
    flags.carry = temp_cf;
    if (flags.carry)
        { pc = 0xe294; break; }
    r16[dx] = 0;
    push(ds);
    ds = memoryAGet16(ds, 0x52b5);
    r8[al] = lodsb_DSSI();
    if (r8[al] < 0x80)
        { pc = 0xe288; break; }
    r8[al] -= 0x7f;
    r16[cx] = r16[ax];
    r16[dx] = r16[ax];
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    ds = pop();
    { pc = 0xe23d; break; }
  case 0xe288:
    r8[al] += 0x03;
    r16[cx] = r16[ax];
    r16[dx] = r16[ax];
    r8[al] = lodsb_DSSI();
    for (; r16[cx] != 0; --r16[cx]) stosb_ESDI(r8[al]);
    ds = pop();
    { pc = 0xe23d; break; }
  case 0xe294:
    sp += 2; return;
    return;
  }
}
function* sub_e3e3() // 01ed:c513
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, 0x52b9, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    memoryASet16(ds, 0x52b5, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ds, 0x52bb, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    memoryASet16(ds, 0x52b7, r16[ax]);
    push(es);
    push(r16[si]);
    r16[ax] = memoryAGet16(ds, 0x52b5);
    es = r16[ax];
    r16[si] = memoryAGet16(ds, 0x52b9);
    r16[ax] = memoryAGet16(es, r16[si]);
    memoryASet16(ds, 0x52bd, r16[ax]);
    r16[ax] = memoryAGet16(es, r16[si] + 2);
    memoryASet16(ds, 0x52bf, r16[ax]);
    r16[si] = pop();
    es = pop();
    memoryASet16(ds, 0x52b9, memoryAGet16(ds, 0x52b9) + 0x0004);
    yield* sub_e22f();
    r16[bp] = pop();
    sp += 2;
}
function* sub_e422() // 01ed:c552
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[ax] = 0;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_ee3d();
    r16[cx] = pop();
    r16[cx] = pop();
    r16[si] = r16[ax];
    if (r16[ax] != 0xffff)
        { pc = 0xe43a; break; }
    { pc = 0xe454; break; }
  case 0xe43a:
    if (!(memoryAGet16(ss, r16[bp] + 6) & 0x0002))
        { pc = 0xe447; break; }
    if (r16[si] & 0x0001)
        { pc = 0xe44b; break; }
  case 0xe447:
    r16[ax] = 0;
    { pc = 0xe454; break; }
  case 0xe44b:
    memoryASet16(ds, 0x0092, 0x0005);
    r16[ax] = 0xffff;
  case 0xe454:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e47b() // 01ed:c5ab
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    if (r16s[si] < 0)
        { pc = 0xe48b; break; }
    if (r16s[si] < signed16(0x0014))
        { pc = 0xe494; break; }
  case 0xe48b:
    r16[ax] = 0x0006;
    push(r16[ax]);
    yield* sub_f166();
    { pc = 0xe4a3; break; }
  case 0xe494:
    r16[bx] = r16[si];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 21784, 0xffff);
    push(r16[si]);
    yield* sub_ee58();
    r16[cx] = pop();
  case 0xe4a3:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e4a7() // 01ed:c5d7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    { pc = 0xe4b6; break; }
  case 0xe4ac:
    r16[bx] = memoryAGet16(ds, 0x52cc);
    r16[bx] <<= 1;
    yield* indirectCall(cs, memoryAGet16(ds, r16[bx] + 44032));
  case 0xe4b6:
    r16[ax] = memoryAGet16(ds, 0x52cc);
    memoryASet16(ds, 0x52cc, memoryAGet16(ds, 0x52cc) - 1);
    if (r16[ax])
        { pc = 0xe4ac; break; }
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_1fdf();
    r16[cx] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e4ca() // 01ed:c5fa +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax]++;
    r16[si] = r16[ax];
    r16[si] -= memoryAGet16(ds, 0x008e);
    r16[ax] = r16[si];
    r16[ax] += 0x003f;
    r8[cl] = 0x06;
    r16[ax] >>= r8[cl];
    r16[si] = r16[ax];
    if (r16[ax] != memoryAGet16(ds, 0x53d6))
        { pc = 0xe4fc; break; }
  case 0xe4ea:
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, 0x00a0, r16[dx]);
    memoryASet16(ds, 0x00a2, r16[ax]);
    r16[ax] = 0x0001;
    { pc = 0xe542; break; }
  case 0xe4fc:
    r8[cl] = 0x06;
    r16[si] <<= r8[cl];
    r16[di] = memoryAGet16(ds, 0x00a6);
    r16[ax] = r16[si];
    r16[ax] += memoryAGet16(ds, 0x008e);
    if (r16[ax] <= r16[di])
        { pc = 0xe516; break; }
    r16[ax] = r16[di];
    r16[ax] -= memoryAGet16(ds, 0x008e);
    r16[si] = r16[ax];
  case 0xe516:
    push(r16[si]);
    push(memoryAGet16(ds, 0x008e));
    yield* sub_f5ce();
    r16[cx] = pop();
    r16[cx] = pop();
    r16[di] = r16[ax];
    if (r16[ax] != 0xffff)
        { pc = 0xe532; break; }
    r16[ax] = r16[si];
    r8[cl] = 0x06;
    r16[ax] >>= r8[cl];
    memoryASet16(ds, 0x53d6, r16[ax]);
    { pc = 0xe4ea; break; }
  case 0xe532:
    r16[ax] = memoryAGet16(ds, 0x008e);
    r16[ax] += r16[di];
    memoryASet16(ds, 0x00a4, 0x0000);
    memoryASet16(ds, 0x00a6, r16[ax]);
    r16[ax] = 0;
  case 0xe542:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 6;
    return;
  }
}
function* sub_e548() // 01ed:c678
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[cx] = memoryAGet16(ds, 0x009e);
    r16[bx] = memoryAGet16(ds, 0x009c);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1044a();
    if (flags.carry)
        { pc = 0xe57e; break; }
    r16[cx] = memoryAGet16(ds, 0x00a6);
    r16[bx] = memoryAGet16(ds, 0x00a4);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1044a();
    if (!flags.carry && !flags.zero)
        { pc = 0xe57e; break; }
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_e4ca();
    if (r16[ax])
        { pc = 0xe583; break; }
  case 0xe57e:
    r16[ax] = 0xffff;
    { pc = 0xe585; break; }
  case 0xe583:
    r16[ax] = 0;
  case 0xe585:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e587() // 01ed:c6b7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0008;
    r16[dx] = memoryAGet16(ds, 0x00a2);
    r16[ax] = memoryAGet16(ds, 0x00a0);
    r16[cx] = memoryAGet16(ss, r16[bp] + 6);
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    yield* sub_1010b();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    memoryASet16(ss, r16[bp] - 2, r16[dx]);
    r16[cx] = memoryAGet16(ds, 0x009e);
    r16[bx] = memoryAGet16(ds, 0x009c);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    yield* sub_1044a();
    if (flags.carry)
        { pc = 0xe5c6; break; }
    r16[cx] = memoryAGet16(ds, 0x00a6);
    r16[bx] = memoryAGet16(ds, 0x00a4);
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    yield* sub_1044a();
    if (flags.carry || flags.zero)
        { pc = 0xe5ce; break; }
  case 0xe5c6:
    r16[dx] = 0xffff;
    r16[ax] = 0xffff;
    { pc = 0xe5f0; break; }
  case 0xe5ce:
    r16[ax] = memoryAGet16(ds, 0x00a2);
    r16[dx] = memoryAGet16(ds, 0x00a0);
    memoryASet16(ss, r16[bp] - 8, r16[dx]);
    memoryASet16(ss, r16[bp] - 6, r16[ax]);
    push(memoryAGet16(ss, r16[bp] - 2));
    push(memoryAGet16(ss, r16[bp] - 4));
    yield* sub_e4ca();
    if (r16[ax])
        { pc = 0xe5ea; break; }
    { pc = 0xe5c6; break; }
  case 0xe5ea:
    r16[dx] = memoryAGet16(ss, r16[bp] - 6);
    r16[ax] = memoryAGet16(ss, r16[bp] - 8);
  case 0xe5f0:
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e5f4() // 01ed:c724
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    if (r16[si])
        { pc = 0xe605; break; }
    yield* sub_e676();
    { pc = 0xe670; break; }
  case 0xe605:
    if (memoryAGet16(ds, r16[si] + 14) == r16[si])
        { pc = 0xe60f; break; }
  case 0xe60a:
    r16[ax] = 0xffff;
    { pc = 0xe672; break; }
  case 0xe60f:
    if (signed16(memoryAGet16(ds, r16[si])) < signed16(0x0000))
        { pc = 0xe63d; break; }
    if (memoryAGet16(ds, r16[si] + 2) & 0x0008)
        { pc = 0xe625; break; }
    r16[ax] = r16[si];
    r16[ax] += 0x0005;
    if (memoryAGet16(ds, r16[si] + 10) != r16[ax])
        { pc = 0xe63b; break; }
  case 0xe625:
    memoryASet16(ds, r16[si], 0x0000);
    r16[ax] = r16[si];
    r16[ax] += 0x0005;
    if (memoryAGet16(ds, r16[si] + 10) != r16[ax])
        { pc = 0xe63b; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 10, r16[ax]);
    { pc = 0xe670; break; }
  case 0xe63b:
    { pc = 0xe670; break; }
  case 0xe63d:
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[ax] += memoryAGet16(ds, r16[si]);
    r16[ax]++;
    r16[di] = r16[ax];
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= r16[di];
    memoryASet16(ds, r16[si], r16[ax]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 10, r16[ax]);
    push(r16[ax]);
    r8[al] = memoryAGet(ds, r16[si] + 4);
    cbw();
    push(r16[ax]);
    yield* sub_ec32();
    sp += 0x0006;
    if (r16[ax] == r16[di])
        { pc = 0xe670; break; }
    if (memoryAGet16(ds, r16[si] + 2) & 0x0200)
        { pc = 0xe670; break; }
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) | 0x0010);
    { pc = 0xe60a; break; }
  case 0xe670:
    r16[ax] = 0;
  case 0xe672:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e676() // 01ed:c7a6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ss, r16[bp] - 2, 0x0000);
    r16[di] = 0x0014;
    r16[si] = 0x53d8;
    { pc = 0xe69c; break; }
  case 0xe68a:
    if (!(memoryAGet16(ds, r16[si] + 2) & 0x0003))
        { pc = 0xe699; break; }
    push(r16[si]);
    yield* sub_e5f4();
    r16[cx] = pop();
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) + 1);
  case 0xe699:
    r16[si] += 0x0010;
  case 0xe69c:
    r16[ax] = r16[di];
    r16[di]--;
    if (r16[ax])
        { pc = 0xe68a; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e6ac() // 01ed:c7dc +stackDrop2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    if (signed16(memoryAGet16(ds, r16[bx])) >= signed16(0x0000))
        { pc = 0xe6c1; break; }
    r16[ax] = memoryAGet16(ds, r16[bx] + 6);
    r16[ax] += memoryAGet16(ds, r16[bx]);
    r16[ax]++;
    { pc = 0xe6cb; break; }
  case 0xe6c1:
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[ax] ^= r16[dx];
    r16[ax] -= r16[dx];
  case 0xe6cb:
    r16[si] = r16[ax];
    r16[cx] = r16[ax];
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    if (!(memoryAGet16(ds, r16[bx] + 2) & 0x0040))
        { pc = 0xe6db; break; }
    { pc = 0xe70a; break; }
  case 0xe6db:
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = memoryAGet16(ds, r16[bx] + 10);
    if (signed16(memoryAGet16(ds, r16[bx])) >= signed16(0x0000))
        { pc = 0xe703; break; }
    { pc = 0xe6f1; break; }
  case 0xe6e8:
    r16[di]--;
    r16[bx] = r16[di];
    if (memoryAGet(ds, r16[bx]) != 0x0a)
        { pc = 0xe6f1; break; }
    r16[cx]++;
  case 0xe6f1:
    r16[ax] = r16[si];
    r16[si]--;
    if (r16[ax])
        { pc = 0xe6e8; break; }
    { pc = 0xe70a; break; }
  case 0xe6fa:
    r16[bx] = r16[di];
    r16[di]++;
    if (memoryAGet(ds, r16[bx]) != 0x0a)
        { pc = 0xe703; break; }
    r16[cx]++;
  case 0xe703:
    r16[ax] = r16[si];
    r16[si]--;
    if (r16[ax])
        { pc = 0xe6fa; break; }
  case 0xe70a:
    r16[ax] = r16[cx];
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 4;
    return;
  }
}
function* sub_e712() // 01ed:c842
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    push(r16[si]);
    yield* sub_e5f4();
    r16[cx] = pop();
    if (!r16[ax])
        { pc = 0xe727; break; }
    r16[ax] = 0xffff;
    { pc = 0xe771; break; }
  case 0xe727:
    if (memoryAGet16(ss, r16[bp] + 10) != 0x0001)
        { pc = 0xe73d; break; }
    if (signed16(memoryAGet16(ds, r16[si])) <= signed16(0x0000))
        { pc = 0xe73d; break; }
    push(r16[si]);
    yield* sub_e6ac();
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, r16[bp] + 6) < r16[ax];
    memoryASet16(ss, r16[bp] + 6, memoryAGet16(ss, r16[bp] + 6) - r16[ax]);
    memoryASet16(ss, r16[bp] + 8, memoryAGet16(ss, r16[bp] + 8) - (r16[dx] + flags.carry));
  case 0xe73d:
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) & 0xfe5f);
    memoryASet16(ds, r16[si], 0x0000);
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 10, r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 10));
    push(memoryAGet16(ss, r16[bp] + 8));
    push(memoryAGet16(ss, r16[bp] + 6));
    r8[al] = memoryAGet(ds, r16[si] + 4);
    cbw();
    push(r16[ax]);
    yield* sub_f1b4();
    sp += 0x0008;
    if (r16[dx] != 0xffff)
        { pc = 0xe76f; break; }
    if (r16[ax] != 0xffff)
        { pc = 0xe76f; break; }
    r16[ax] = 0xffff;
    { pc = 0xe771; break; }
  case 0xe76f:
    r16[ax] = 0;
  case 0xe771:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e7b5() // 01ed:c8e5
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    r8[al] = memoryAGet(ss, r16[bp] + 6);
    r8[al] += 0xff;
    memoryASet(ss, r16[bp] - 1, r8[al]);
    r8[al] = memoryAGet(ds, 0x554f);
    memoryASet(ss, r16[bp] - 1, memoryAGet(ss, r16[bp] - 1) + r8[al]);
    r8[al] = memoryAGet(ss, r16[bp] + 4);
    r8[al] += 0xff;
    memoryASet(ss, r16[bp] - 2, r8[al]);
    r8[al] = memoryAGet(ds, 0x554e);
    memoryASet(ss, r16[bp] - 2, memoryAGet(ss, r16[bp] - 2) + r8[al]);
    r8[al] = memoryAGet(ss, r16[bp] - 1);
    if (r8[al] < memoryAGet(ds, 0x554f))
        { pc = 0xe801; break; }
    if (r8[al] > memoryAGet(ds, 0x5551))
        { pc = 0xe801; break; }
    r8[al] = memoryAGet(ss, r16[bp] - 2);
    if (r8[al] < memoryAGet(ds, 0x554e))
        { pc = 0xe801; break; }
    if (r8[al] > memoryAGet(ds, 0x5550))
        { pc = 0xe801; break; }
    r8[dl] = memoryAGet(ss, r16[bp] - 2);
    r8[dh] = memoryAGet(ss, r16[bp] - 1);
    r8[ah] = 0x02;
    r8[bh] = 0x00;
    yield* sub_eeae();
  case 0xe801:
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e805() // 01ed:c935
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0xca7c;
    push(r16[ax]);
    r16[ax] = 0x53e8;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = r16[bp] + 6;
    push(r16[ax]);
    yield* sub_f679();
    r16[bp] = pop();
    sp += 2;
}
function* sub_e81c() // 01ed:c94c
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax]--;
    memoryASet16(ds, r16[si], r16[ax]);
    push(r16[si]);
    r8[al] = memoryAGet(ss, r16[bp] + 4);
    cbw();
    push(r16[ax]);
    yield* sub_e836();
    r16[cx] = pop();
    r16[cx] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
}
function* sub_e836() // 01ed:c966
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    r8[al] = memoryAGet(ss, r16[bp] + 4);
    memoryASet(ds, 0xac40, r8[al]);
    if (signed16(memoryAGet16(ds, r16[si])) >= signed16(0xffff))
        { pc = 0xe87f; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax]++;
    memoryASet16(ds, r16[si], r16[ax]);
    r16[bx] = memoryAGet16(ds, r16[si] + 10);
    memoryASet16(ds, r16[si] + 10, memoryAGet16(ds, r16[si] + 10) + 1);
    r8[al] = memoryAGet(ds, 0xac40);
    memoryASet(ds, r16[bx], r8[al]);
    if (!(memoryAGet16(ds, r16[si] + 2) & 0x0008))
        { pc = 0xe87c; break; }
    if (memoryAGet(ds, 0xac40) == 0x0a)
        { pc = 0xe86d; break; }
    if (memoryAGet(ds, 0xac40) != 0x0d)
        { pc = 0xe87c; break; }
  case 0xe86d:
    push(r16[si]);
    yield* sub_e5f4();
    r16[cx] = pop();
    if (!r16[ax])
        { pc = 0xe87c; break; }
  case 0xe876:
    r16[ax] = 0xffff;
    { pc = 0xe935; break; }
  case 0xe87c:
    { pc = 0xe930; break; }
  case 0xe87f:
    if (memoryAGet16(ds, r16[si] + 2) & 0x0090)
        { pc = 0xe88d; break; }
    if (memoryAGet16(ds, r16[si] + 2) & 0x0002)
        { pc = 0xe894; break; }
  case 0xe88d:
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) | 0x0010);
    { pc = 0xe876; break; }
  case 0xe894:
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) | 0x0100);
    if (!memoryAGet16(ds, r16[si] + 6))
        { pc = 0xe8e3; break; }
    if (!memoryAGet16(ds, r16[si]))
        { pc = 0xe8af; break; }
    push(r16[si]);
    yield* sub_e5f4();
    r16[cx] = pop();
    if (!r16[ax])
        { pc = 0xe8af; break; }
    { pc = 0xe876; break; }
  case 0xe8af:
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si], r16[ax]);
    r16[bx] = memoryAGet16(ds, r16[si] + 10);
    memoryASet16(ds, r16[si] + 10, memoryAGet16(ds, r16[si] + 10) + 1);
    r8[al] = memoryAGet(ds, 0xac40);
    memoryASet(ds, r16[bx], r8[al]);
    if (!(memoryAGet16(ds, r16[si] + 2) & 0x0008))
        { pc = 0xe8e1; break; }
    if (memoryAGet(ds, 0xac40) == 0x0a)
        { pc = 0xe8d6; break; }
    if (memoryAGet(ds, 0xac40) != 0x0d)
        { pc = 0xe8e1; break; }
  case 0xe8d6:
    push(r16[si]);
    yield* sub_e5f4();
    r16[cx] = pop();
    if (!r16[ax])
        { pc = 0xe8e1; break; }
    { pc = 0xe876; break; }
  case 0xe8e1:
    { pc = 0xe930; break; }
  case 0xe8e3:
    if (memoryAGet(ds, 0xac40) != 0x0a)
        { pc = 0xe909; break; }
    if (memoryAGet16(ds, r16[si] + 2) & 0x0040)
        { pc = 0xe909; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0x5546;
    push(r16[ax]);
    r8[al] = memoryAGet(ds, r16[si] + 4);
    cbw();
    push(r16[ax]);
    yield* sub_fb3d();
    sp += 0x0006;
    if (r16[ax] != 0x0001)
        { pc = 0xe921; break; }
  case 0xe909:
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0xac40;
    push(r16[ax]);
    r8[al] = memoryAGet(ds, r16[si] + 4);
    cbw();
    push(r16[ax]);
    yield* sub_fb3d();
    sp += 0x0006;
    if (r16[ax] == 0x0001)
        { pc = 0xe930; break; }
  case 0xe921:
    if (memoryAGet16(ds, r16[si] + 2) & 0x0200)
        { pc = 0xe930; break; }
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) | 0x0010);
    { pc = 0xe876; break; }
  case 0xe930:
    r8[al] = memoryAGet(ds, 0xac40);
    r8[ah] = 0x00;
  case 0xe935:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_e94c() // 01ed:ca7c +stackDrop6
{
  var pc = 0;
  var temp_cond0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    push(r16[si]);
    push(r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ss, r16[bp] - 2, r16[di]);
    if (!(memoryAGet16(ds, r16[si] + 2) & 0x0008))
        { pc = 0xe989; break; }
    { pc = 0xe97f; break; }
  case 0xe965:
    push(r16[si]);
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ss, r16[bp] + 8, memoryAGet16(ss, r16[bp] + 8) + 1);
    r8[al] = memoryAGet(ds, r16[bx]);
    cbw();
    push(r16[ax]);
    yield* sub_e836();
    r16[cx] = pop();
    r16[cx] = pop();
    if (r16[ax] != 0xffff)
        { pc = 0xe97f; break; }
  case 0xe97a:
    r16[ax] = 0;
    { pc = 0xea76; break; }
  case 0xe97f:
    r16[ax] = r16[di];
    r16[di]--;
    if (r16[ax])
        { pc = 0xe965; break; }
    { pc = 0xea73; break; }
  case 0xe989:
    if (memoryAGet16(ds, r16[si] + 2) & 0x0040)
        { pc = 0xe993; break; }
    { pc = 0xea16; break; }
  case 0xe993:
    if (!memoryAGet16(ds, r16[si] + 6))
        { pc = 0xe9fe; break; }
    if (memoryAGet16(ds, r16[si] + 6) >= r16[di])
        { pc = 0xe9c6; break; }
    if (!memoryAGet16(ds, r16[si]))
        { pc = 0xe9ae; break; }
    push(r16[si]);
    yield* sub_e5f4();
    r16[cx] = pop();
    if (!r16[ax])
        { pc = 0xe9ae; break; }
    { pc = 0xe97a; break; }
  case 0xe9ae:
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] + 8));
    r8[al] = memoryAGet(ds, r16[si] + 4);
    cbw();
    push(r16[ax]);
    yield* sub_fb3d();
    sp += 0x0006;
    if (r16[ax] >= r16[di])
        { pc = 0xe9c3; break; }
    { pc = 0xe97a; break; }
  case 0xe9c3:
    { pc = 0xea73; break; }
  case 0xe9c6:
    r16[ax] = memoryAGet16(ds, r16[si]);
    temp_cond0 = r16s[ax] < 0;
    r16[ax] += r16[di];
    if (temp_cond0)
        { pc = 0xe9e6; break; }
    if (memoryAGet16(ds, r16[si]))
        { pc = 0xe9db; break; }
    r16[ax] = 0xffff;
    r16[ax] -= memoryAGet16(ds, r16[si] + 6);
    memoryASet16(ds, r16[si], r16[ax]);
    { pc = 0xe9e6; break; }
  case 0xe9db:
    push(r16[si]);
    yield* sub_e5f4();
    r16[cx] = pop();
    if (!r16[ax])
        { pc = 0xe9e6; break; }
    { pc = 0xe97a; break; }
  case 0xe9e6:
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] + 8));
    push(memoryAGet16(ds, r16[si] + 10));
    yield* sub_f2c0();
    sp += 0x0006;
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] += r16[di];
    memoryASet16(ds, r16[si], r16[ax]);
    memoryASet16(ds, r16[si] + 10, memoryAGet16(ds, r16[si] + 10) + r16[di]);
    { pc = 0xea73; break; }
  case 0xe9fe:
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] + 8));
    r8[al] = memoryAGet(ds, r16[si] + 4);
    cbw();
    push(r16[ax]);
    yield* sub_fb3d();
    sp += 0x0006;
    if (r16[ax] >= r16[di])
        { pc = 0xea14; break; }
    { pc = 0xe97a; break; }
  case 0xea14:
    { pc = 0xea73; break; }
  case 0xea16:
    if (!memoryAGet16(ds, r16[si] + 6))
        { pc = 0xea5d; break; }
    { pc = 0xea54; break; }
  case 0xea1e:
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax]++;
    memoryASet16(ds, r16[si], r16[ax]);
    if (r16s[ax] >= 0)
        { pc = 0xea3d; break; }
    r16[bx] = memoryAGet16(ds, r16[si] + 10);
    memoryASet16(ds, r16[si] + 10, memoryAGet16(ds, r16[si] + 10) + 1);
    push(r16[bx]);
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ss, r16[bp] + 8, memoryAGet16(ss, r16[bp] + 8) + 1);
    r8[al] = memoryAGet(ds, r16[bx]);
    r16[bx] = pop();
    memoryASet(ds, r16[bx], r8[al]);
    r8[ah] = 0x00;
    { pc = 0xea4c; break; }
  case 0xea3d:
    push(r16[si]);
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ss, r16[bp] + 8, memoryAGet16(ss, r16[bp] + 8) + 1);
    r8[al] = memoryAGet(ds, r16[bx]);
    push(r16[ax]);
    yield* sub_e81c();
    r16[cx] = pop();
    r16[cx] = pop();
  case 0xea4c:
    if (r16[ax] != 0xffff)
        { pc = 0xea54; break; }
    { pc = 0xe97a; break; }
  case 0xea54:
    r16[ax] = r16[di];
    r16[di]--;
    if (r16[ax])
        { pc = 0xea1e; break; }
    { pc = 0xea73; break; }
  case 0xea5d:
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] + 8));
    r8[al] = memoryAGet(ds, r16[si] + 4);
    cbw();
    push(r16[ax]);
    yield* sub_ec32();
    sp += 0x0006;
    if (r16[ax] >= r16[di])
        { pc = 0xea73; break; }
    { pc = 0xe97a; break; }
  case 0xea73:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
  case 0xea76:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 8;
    return;
  }
}
function* sub_ea7e() // 01ed:cbae
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    push(r16[si]);
    yield* sub_f647();
    r16[cx] = pop();
    r16[di] = r16[ax];
    push(r16[si]);
    push(r16[ax]);
    r16[ax] = 0x53e8;
    push(r16[ax]);
    yield* sub_e94c();
    if (r16[ax] == r16[di])
        { pc = 0xea9f; break; }
    r16[ax] = 0xffff;
    { pc = 0xeab9; break; }
  case 0xea9f:
    r16[ax] = 0x53e8;
    push(r16[ax]);
    r16[ax] = 0x000a;
    push(r16[ax]);
    yield* sub_e836();
    r16[cx] = pop();
    r16[cx] = pop();
    if (r16[ax] == 0x000a)
        { pc = 0xeab6; break; }
    r16[ax] = 0xffff;
    { pc = 0xeab9; break; }
  case 0xeab6:
    r16[ax] = 0x000a;
  case 0xeab9:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_eabd() // 01ed:cbed
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r8[al] = memoryAGet(ds, 0x53dc);
    cbw();
    push(r16[ax]);
    yield* sub_f1a3();
    r16[cx] = pop();
    if (r16[ax])
        { pc = 0xead0; break; }
    memoryASet16(ds, 0x53da, memoryAGet16(ds, 0x53da) & 0xfdff);
  case 0xead0:
    r16[ax] = 0x0200;
    push(r16[ax]);
    if (!(memoryAGet16(ds, 0x53da) & r16[ax]))
        { pc = 0xeadf; break; }
    r16[ax] = 0x0001;
    { pc = 0xeae1; break; }
  case 0xeadf:
    r16[ax] = 0;
  case 0xeae1:
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0x53d8;
    push(r16[ax]);
    yield* sub_eb22();
    sp += 0x0008;
    r8[al] = memoryAGet(ds, 0x53ec);
    cbw();
    push(r16[ax]);
    yield* sub_f1a3();
    r16[cx] = pop();
    if (r16[ax])
        { pc = 0xeb02; break; }
    memoryASet16(ds, 0x53ea, memoryAGet16(ds, 0x53ea) & 0xfdff);
  case 0xeb02:
    r16[ax] = 0x0200;
    push(r16[ax]);
    if (!(memoryAGet16(ds, 0x53ea) & r16[ax]))
        { pc = 0xeb11; break; }
    r16[ax] = 0x0002;
    { pc = 0xeb13; break; }
  case 0xeb11:
    r16[ax] = 0;
  case 0xeb13:
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    r16[ax] = 0x53e8;
    push(r16[ax]);
    yield* sub_eb22();
    sp += 0x0008;
    sp += 2;
    return;
  }
}
function* sub_eb22() // 01ed:cc52
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = memoryAGet16(ss, r16[bp] + 10);
    if (memoryAGet16(ds, r16[si] + 14) != r16[si])
        { pc = 0xeb3e; break; }
    if (signed16(memoryAGet16(ss, r16[bp] + 8)) > signed16(0x0002))
        { pc = 0xeb3e; break; }
    if (r16[di] <= 0x7fff)
        { pc = 0xeb44; break; }
  case 0xeb3e:
    r16[ax] = 0xffff;
    { pc = 0xebea; break; }
  case 0xeb44:
    if (memoryAGet16(ds, 0x554a))
        { pc = 0xeb59; break; }
    if (r16[si] != 0x53e8)
        { pc = 0xeb59; break; }
    memoryASet16(ds, 0x554a, 0x0001);
    { pc = 0xeb6c; break; }
  case 0xeb59:
    if (memoryAGet16(ds, 0x5548))
        { pc = 0xeb6c; break; }
    if (r16[si] != 0x53d8)
        { pc = 0xeb6c; break; }
    memoryASet16(ds, 0x5548, 0x0001);
  case 0xeb6c:
    if (!memoryAGet16(ds, r16[si]))
        { pc = 0xeb82; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0;
    push(r16[ax]);
    push(r16[dx]);
    push(r16[si]);
    yield* sub_e712();
    sp += 0x0008;
  case 0xeb82:
    if (!(memoryAGet16(ds, r16[si] + 2) & 0x0004))
        { pc = 0xeb90; break; }
    push(memoryAGet16(ds, r16[si] + 8));
    yield* sub_101c0();
    r16[cx] = pop();
  case 0xeb90:
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) & 0xfff3);
    memoryASet16(ds, r16[si] + 6, 0x0000);
    r16[ax] = r16[si];
    r16[ax] += 0x0005;
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si] + 10, r16[ax]);
    if (memoryAGet16(ss, r16[bp] + 8) == 0x0002)
        { pc = 0xebe8; break; }
    if (r16[di] <= 0)
        { pc = 0xebe8; break; }
    memoryASet16(ds, 0x53d0, 0xce51);
    if (memoryAGet16(ss, r16[bp] + 6))
        { pc = 0xebd1; break; }
    push(r16[di]);
    yield* sub_1028f();
    r16[cx] = pop();
    memoryASet16(ss, r16[bp] + 6, r16[ax]);
    if (!r16[ax])
        { pc = 0xebce; break; }
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) | 0x0004);
    { pc = 0xebd1; break; }
  case 0xebce:
    { pc = 0xeb3e; break; }
  case 0xebd1:
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    memoryASet16(ds, r16[si] + 10, r16[ax]);
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si] + 6, r16[di]);
    if (memoryAGet16(ss, r16[bp] + 8) != 0x0001)
        { pc = 0xebe8; break; }
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) | 0x0008);
  case 0xebe8:
    r16[ax] = 0;
  case 0xebea:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ec06() // 01ed:cd36
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    if (r16[dx] != 0xffff)
        { pc = 0xec16; break; }
    r16[ax] = 0xffff;
    { pc = 0xec30; break; }
  case 0xec16:
    r8[al] = r8[dl];
    r8[ah] = 0x00;
    r16[bx] = r16[ax];
    if (!(memoryAGet(ds, r16[bx] + 21199) & 0x08))
        { pc = 0xec2c; break; }
    r8[al] = r8[dl];
    r8[ah] = 0x00;
    r16[ax] += 0xffe0;
    { pc = 0xec30; break; }
  case 0xec2c:
    r8[al] = r8[dl];
    r8[ah] = 0x00;
  case 0xec30:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ec32() // 01ed:cd62
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x008a;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r16[ax]++;
    if (r16[ax] >= 0x0002)
        { pc = 0xec49; break; }
    r16[ax] = 0;
    { pc = 0xed1b; break; }
  case 0xec49:
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] <<= 1;
    if (!(memoryAGet16(ds, r16[bx] + 21784) & 0x8000))
        { pc = 0xec68; break; }
    push(memoryAGet16(ss, r16[bp] + 8));
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_fb3d();
    sp += 0x0006;
    { pc = 0xed1b; break; }
  case 0xec68:
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 21784, memoryAGet16(ds, r16[bx] + 21784) & 0xfdff);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    { pc = 0xecd6; break; }
  case 0xec81:
    memoryASet16(ss, r16[bp] - 4, memoryAGet16(ss, r16[bp] - 4) - 1);
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + 1);
    r8[al] = memoryAGet(ds, r16[bx]);
    memoryASet(ss, r16[bp] - 5, r8[al]);
    if (r8[al] != 0x0a)
        { pc = 0xec97; break; }
    memoryASet(ds, r16[si], 0x0d);
    r16[si]++;
  case 0xec97:
    r8[al] = memoryAGet(ss, r16[bp] - 5);
    memoryASet(ds, r16[si], r8[al]);
    r16[si]++;
    r16[ax] = r16[bp] - 138;
    r16[dx] = r16[si];
    r16[dx] -= r16[ax];
    if (r16s[dx] < signed16(0x0080))
        { pc = 0xecdc; break; }
    r16[dx] = r16[si];
    r16[dx] -= r16[ax];
    r16[di] = r16[dx];
    push(r16[dx]);
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_fb3d();
    sp += 0x0006;
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    if (r16[ax] == r16[di])
        { pc = 0xecd6; break; }
    if (true)
        { pc = 0xeccc; break; }
  case 0xecc7:
    r16[ax] = 0xffff;
    { pc = 0xed16; break; }
  case 0xeccc:
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r16[ax] -= memoryAGet16(ss, r16[bp] - 4);
    { pc = 0xed11; break; }
    // gap 2 bytes
  case 0xecd6:
    r16[ax] = r16[bp] - 138;
    r16[si] = r16[ax];
  case 0xecdc:
    if (memoryAGet16(ss, r16[bp] - 4))
        { pc = 0xec81; break; }
    r16[ax] = r16[bp] - 138;
    r16[dx] = r16[si];
    r16[dx] -= r16[ax];
    r16[di] = r16[dx];
    r16[ax] = r16[dx];
    if (r16[ax] <= 0)
        { pc = 0xed18; break; }
    push(r16[dx]);
    r16[ax] = r16[bp] - 138;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_fb3d();
    sp += 0x0006;
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    if (r16[ax] == r16[di])
        { pc = 0xed18; break; }
    if (true)
        { pc = 0xed0e; break; }
    { pc = 0xecc7; break; }
  case 0xed0e:
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
  case 0xed11:
    r16[ax] += memoryAGet16(ss, r16[bp] - 2);
    r16[ax] -= r16[di];
  case 0xed16:
    { pc = 0xed1b; break; }
  case 0xed18:
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
  case 0xed1b:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_edce() // 01ed:cefe
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = sp;
    r16[dx] -= 0x0200;
    if (r16[ax] >= r16[dx])
        { pc = 0xede5; break; }
    memoryASet16(ds, 0x009a, r16[ax]);
    r16[ax] = 0;
    { pc = 0xedee; break; }
  case 0xede5:
    memoryASet16(ds, 0x0092, 0x0008);
    r16[ax] = 0xffff;
  case 0xedee:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_edf0() // 01ed:cf20
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    flags.carry = r16[ax] + memoryAGet16(ds, 0x009a) >= 0x10000;
    r16[ax] += memoryAGet16(ds, 0x009a);
    r16[dx] += (0x0000 + flags.carry);
    r16[cx] = r16[ax];
    if (r16[dx])
        { pc = 0xee16; break; }
    flags.carry = r16[cx] + 0x0200 >= 0x10000;
    r16[cx] += 0x0200;
    if (flags.carry)
        { pc = 0xee16; break; }
    if (r16[cx] >= sp)
        { pc = 0xee16; break; }
    r16[tx] = memoryAGet16(ds, 0x009a); memoryASet16(ds, 0x009a, r16[ax]); r16[ax] = r16[tx];
    { pc = 0xee1f; break; }
  case 0xee16:
    memoryASet16(ds, 0x0092, 0x0008);
    r16[ax] = 0xffff;
  case 0xee1f:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ee3d() // 01ed:cf6d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[cx] = memoryAGet16(ss, r16[bp] + 8);
    r8[ah] = 0x43;
    r8[al] = memoryAGet(ss, r16[bp] + 6);
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xee52; break; }
    r16[tx] = r16[cx]; r16[cx] = r16[ax]; r16[ax] = r16[tx];
    { pc = 0xee56; break; }
  case 0xee52:
    push(r16[ax]);
    yield* sub_f166();
  case 0xee56:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ee58() // 01ed:cf88
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r8[ah] = 0x3e;
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xee70; break; }
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 21784, 0xffff);
    r16[ax] = 0;
    { pc = 0xee74; break; }
  case 0xee70:
    push(r16[ax]);
    yield* sub_f166();
  case 0xee74:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ee76() // 01ed:cfa6 +stackDrop6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    { pc = 0xee93; break; }
  case 0xee7f:
    r16[bx] = memoryAGet16(ss, r16[bp] + 6); es = memoryAGet16(ss, r16[bp] + 8);
    memoryASet16(ss, r16[bp] + 6, memoryAGet16(ss, r16[bp] + 6) + 1);
    r8[al] = memoryAGet(es, r16[bx]);
    r16[bx] = r16[si];
    r16[si]++;
    if (r8[al] == memoryAGet(ds, r16[bx]))
        { pc = 0xee93; break; }
    r16[ax] = 0;
    { pc = 0xee9b; break; }
  case 0xee93:
    if (memoryAGet(ds, r16[si]))
        { pc = 0xee7f; break; }
    r16[ax] = 0x0001;
  case 0xee9b:
    r16[si] = pop();
    r16[bp] = pop();
    sp += 8;
    return;
  }
}
function* sub_eea0() // 01ed:cfd0
{
    sp -= 2;
    r8[ah] = 0x12;
    r8[bl] = 0x10;
    yield* sub_eeae();
    r8[al] = r8[bl];
    r8[al] += 0xf0;
    r8[ah] = 0x00;
    sp += 2;
}
function* sub_eeae() // 01ed:cfde
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    push(ds);
    push(r16[cx]);
    r16[cx] = 0x0040;
    ds = r16[cx];
    r16[cx] = pop();
    if (!r8[ah])
        { pc = 0xeec5; break; }
    if (r8[ah] == 0x0f)
        { pc = 0xef17; break; }
  case 0xeec1:
    interrupt(0x10);
    { pc = 0xef2f; break; }
  case 0xeec5:
    if (r8[al] != 0x03)
        { pc = 0xeee3; break; }
    r16[ax] = 0x1a00;
    interrupt(0x10);
    if (r8[al] == 0x1a)
        { pc = 0xeed7; break; }
    memoryASet(ds, 0x0087, memoryAGet(ds, 0x0087) & 0xfe);
  case 0xeed7:
    r8[ah] = 0x01;
    r16[cx] = 0x0607;
    interrupt(0x10);
    r16[ax] = 0x0003;
    { pc = 0xeec1; break; }
  case 0xeee3:
    if (r8[al] != 0x40)
        { pc = 0xeec1; break; }
    r8[bl] = 0x10;
    r8[ah] = 0x12;
    interrupt(0x10);
    if (r8[bl] == 0x10)
        { pc = 0xef2f; break; }
    r16[ax] = 0x1112;
    r8[bl] = 0;
    interrupt(0x10);
    r16[ax] = 0x1200;
    r8[bl] = 0x20;
    interrupt(0x10);
    r16[ax] = 0x1a00;
    interrupt(0x10);
    if (r8[al] == 0x1a)
        { pc = 0xef2f; break; }
    memoryASet(ds, 0x0087, memoryAGet(ds, 0x0087) | 0x01);
    r8[ah] = 0x01;
    r16[cx] = 0x0600;
    interrupt(0x10);
    { pc = 0xef2f; break; }
  case 0xef17:
    interrupt(0x10);
    if (r8[al] != 0x03)
        { pc = 0xef2f; break; }
    push(r16[ax]);
    yield* sub_eea0();
    flags.zero = r8[al] == 0;
    r16[ax] = pop();
    if (flags.zero)
        { pc = 0xef2f; break; }
    if (memoryAGet(ds, 0x0084) == 0x18)
        { pc = 0xef2f; break; }
    r8[al] = 0x40;
  case 0xef2f:
    ds = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ef32() // 01ed:d062
{
    sp -= 2;
    r8[ah] = 0x0f;
    yield* sub_eeae();
    push(r16[ax]);
    yield* sub_ef52();
    r16[cx] = pop();
    r8[ah] = 0x08;
    r8[bh] = 0x00;
    yield* sub_eeae();
    r8[al] = r8[ah];
    r8[al] &= 0x7f;
    r8[ah] = r8[al];
    memoryASet(ds, 0x5553, r8[ah]);
    memoryASet(ds, 0x5552, r8[ah]);
    sp += 2;
}
function* sub_ef52() // 01ed:d082
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r8[al] = memoryAGet(ss, r16[bp] + 4);
    memoryASet(ds, 0x5554, r8[al]);
    r8[ah] = 0x0f;
    yield* sub_eeae();
    memoryASet(ds, 0x5556, r8[ah]);
    if (r8[al] == memoryAGet(ds, 0x5554))
        { pc = 0xef97; break; }
    r8[al] = memoryAGet(ds, 0x5554);
    r8[ah] = 0x00;
    yield* sub_eeae();
    r8[ah] = 0x0f;
    yield* sub_eeae();
    memoryASet(ds, 0x5554, r8[al]);
    memoryASet(ds, 0x5556, r8[ah]);
    if (memoryAGet(ds, 0x5554) != 0x03)
        { pc = 0xef97; break; }
    r16[ax] = 0x0040;
    es = r16[ax];
    if (signed8(memoryAGet(es, 0x0084)) <= signed8(0x18))
        { pc = 0xef97; break; }
    memoryASet(ds, 0x5554, 0x40);
  case 0xef97:
    if (memoryAGet(ds, 0x5554) <= 0x03)
        { pc = 0xefb1; break; }
    if (memoryAGet(ds, 0x5554) >= 0x40)
        { pc = 0xefb1; break; }
    if (memoryAGet(ds, 0x5554) == 0x07)
        { pc = 0xefb1; break; }
    r16[ax] = 0x0001;
    { pc = 0xefb3; break; }
  case 0xefb1:
    r16[ax] = 0;
  case 0xefb3:
    memoryASet(ds, 0x5557, r8[al]);
    if (memoryAGet(ds, 0x5554) == 0x40)
        { pc = 0xefc1; break; }
    r8[al] = 0x19;
    { pc = 0xefcc; break; }
  case 0xefc1:
    r16[ax] = 0x0040;
    es = r16[ax];
    r8[al] = memoryAGet(es, 0x0084);
    r8[al]++;
  case 0xefcc:
    memoryASet(ds, 0x5555, r8[al]);
    if (memoryAGet(ds, 0x5554) == 0x07)
        { pc = 0xeff5; break; }
    r16[ax] = 0xf000;
    r16[dx] = 0xffea;
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = 0x555f;
    push(r16[ax]);
    yield* sub_ee76();
    if (r16[ax])
        { pc = 0xeff5; break; }
    yield* sub_eea0();
    if (r16[ax])
        { pc = 0xeff5; break; }
    r16[ax] = 0x0001;
    { pc = 0xeff7; break; }
  case 0xeff5:
    r16[ax] = 0;
  case 0xeff7:
    memoryASet(ds, 0x5558, r8[al]);
    if (memoryAGet(ds, 0x5554) != 0x07)
        { pc = 0xf006; break; }
    r16[ax] = 0xb000;
    { pc = 0xf009; break; }
  case 0xf006:
    r16[ax] = 0xb800;
  case 0xf009:
    memoryASet16(ds, 0x555b, r16[ax]);
    memoryASet16(ds, 0x5559, 0x0000);
    r8[al] = 0x00;
    memoryASet(ds, 0x554f, r8[al]);
    memoryASet(ds, 0x554e, r8[al]);
    r8[al] = memoryAGet(ds, 0x5556);
    r8[al] += 0xff;
    memoryASet(ds, 0x5550, r8[al]);
    r8[al] = memoryAGet(ds, 0x5555);
    r8[al] += 0xff;
    memoryASet(ds, 0x5551, r8[al]);
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f02c() // 01ed:d15c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    r16[ax] = 0x4201;
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[cx] = 0;
    r16[dx] = 0;
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xf064; break; }
    push(r16[dx]);
    push(r16[ax]);
    r16[ax] = 0x4202;
    r16[cx] = 0;
    r16[dx] = 0;
    interrupt(0x21);
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    memoryASet16(ss, r16[bp] - 2, r16[dx]);
    r16[dx] = pop();
    r16[cx] = pop();
    if (flags.carry)
        { pc = 0xf064; break; }
    r16[ax] = 0x4200;
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xf064; break; }
    r16[dx] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] = memoryAGet16(ss, r16[bp] - 4);
    { pc = 0xf069; break; }
  case 0xf064:
    push(r16[ax]);
    yield* sub_f166();
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
  case 0xf069:
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f07c() // 01ed:d1ac
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r8[ah] = 0x25;
    r8[al] = memoryAGet(ss, r16[bp] + 4);
    push(ds);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6); ds = memoryAGet16(ss, r16[bp] + 8);
    interrupt(0x21);
    ds = pop();
    r16[bp] = pop();
    sp += 2;
}
function* sub_f08d() // 01ed:d1bd
{
    sp -= 2;
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(es);
    push(ds);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    r16[bp] = 0x14f2;
    ds = r16[bp];
    r16[bp] = sp;
    memoryASet16(ds, 0xac44, sp);
    push(memoryAGet16(ss, r16[bp] + 4));
    push(memoryAGet16(ss, r16[bp]));
    push(memoryAGet16(ss, r16[bp] + 16));
    r16[ax] = memoryAGet16(ss, r16[bp] + 2);
    r16[ax] &= 0x00ff;
    push(r16[ax]);
    yield* indirectCall(cs, memoryAGet16(ds, 0xac42));
    sp += 0x0008;
    memoryASet16(ss, r16[bp] + 16, r16[ax]);
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    ds = pop();
    es = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    stop("iret"); return;
}
function* sub_f0c5() // 01ed:d1f5
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    memoryASet16(ds, 0xac42, r16[ax]);
    push(cs);
    r16[ax] = 0xd1bd;
    push(r16[ax]);
    r16[ax] = 0x0024;
    push(r16[ax]);
    yield* sub_f07c();
    sp += 0x0006;
    r16[bp] = pop();
    sp += 2;
}
function* sub_f134() // 01ed:d264
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    r8[al] = in8(r16[dx]);
    r8[ah] = 0;
    r16[bp] = pop();
    sp += 2;
}
function* sub_f13f() // 01ed:d26f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r8[ah] = 0x44;
    r8[al] = memoryAGet(ss, r16[bp] + 6);
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[cx] = memoryAGet16(ss, r16[bp] + 10);
    r16[dx] = memoryAGet16(ss, r16[bp] + 8);
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xf160; break; }
    if (memoryAGet16(ss, r16[bp] + 6))
        { pc = 0xf15e; break; }
    r16[ax] = r16[dx];
    { pc = 0xf164; break; }
  case 0xf15e:
    { pc = 0xf164; break; }
  case 0xf160:
    push(r16[ax]);
    yield* sub_f166();
  case 0xf164:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f166() // 01ed:d296 +stackDrop2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    r16[si] = memoryAGet16(ss, r16[bp] + 4);
    if (r16s[si] < 0)
        { pc = 0xf186; break; }
    if (r16s[si] <= signed16(0x0058))
        { pc = 0xf179; break; }
  case 0xf176:
    r16[si] = 0x0057;
  case 0xf179:
    memoryASet16(ds, 0x5566, r16[si]);
    r8[al] = memoryAGet(ds, r16[si] + 21864);
    cbw();
    r16[si] = r16[ax];
    { pc = 0xf197; break; }
  case 0xf186:
    r16[ax] = r16[si];
    r16[ax] = -r16[ax];
    r16[si] = r16[ax];
    if (r16s[ax] > signed16(0x0023))
        { pc = 0xf176; break; }
    memoryASet16(ds, 0x5566, 0xffff);
  case 0xf197:
    memoryASet16(ds, 0x0092, r16[si]);
    r16[ax] = 0xffff;
    r16[si] = pop();
    r16[bp] = pop();
    sp += 4;
    return;
  }
}
function* sub_f1a3() // 01ed:d2d3
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0x4400;
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    interrupt(0x21);
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r16[ax] &= 0x0080;
    r16[bp] = pop();
    sp += 2;
}
function* sub_f1b4() // 01ed:d2e4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 21784, memoryAGet16(ds, r16[bx] + 21784) & 0xfdff);
    r8[ah] = 0x42;
    r8[al] = memoryAGet(ss, r16[bp] + 10);
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[cx] = memoryAGet16(ss, r16[bp] + 8);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xf1d6; break; }
    { pc = 0xf1db; break; }
  case 0xf1d6:
    push(r16[ax]);
    yield* sub_f166();
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
  case 0xf1db:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f1dd() // 01ed:d30d +stackDrop12
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0022;
    push(r16[si]);
    push(r16[di]);
    push(es);
    r16[di] = memoryAGet16(ss, r16[bp] + 10);
    push(ds);
    es = pop();
    r16[bx] = memoryAGet16(ss, r16[bp] + 8);
    if (r16[bx] > 0x0024)
        { pc = 0xf24b; break; }
    if (r8[bl] < 0x02)
        { pc = 0xf24b; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] + 12);
    r16[cx] = memoryAGet16(ss, r16[bp] + 14);
    if (r16s[cx] >= 0)
        { pc = 0xf213; break; }
    if (!memoryAGet(ss, r16[bp] + 6))
        { pc = 0xf213; break; }
    memoryASet(ds, r16[di], 0x2d);
    r16[di]++;
    r16[cx] = -r16[cx];
    flags.carry = r16[ax] != 0;
    r16[ax] = -r16[ax];
    r16[cx] -= (0x0000 + flags.carry);
  case 0xf213:
    r16[si] = r16[bp] - 34;
    if (!r16[cx])
        { pc = 0xf227; break; }
  case 0xf218:
    r16[tx] = r16[cx]; r16[cx] = r16[ax]; r16[ax] = r16[tx];
    r16[dx] -= r16[dx];
    div16(r16[bx]);
    r16[tx] = r16[cx]; r16[cx] = r16[ax]; r16[ax] = r16[tx];
    div16(r16[bx]);
    memoryASet(ds, r16[si], r8[dl]);
    r16[si]++;
    if (!r16[cx])
        { pc = 0xf22e; break; }
    { pc = 0xf218; break; }
  case 0xf227:
    r16[dx] -= r16[dx];
    div16(r16[bx]);
    memoryASet(ds, r16[si], r8[dl]);
    r16[si]++;
  case 0xf22e:
    if (r16[ax])
        { pc = 0xf227; break; }
    r16[cx] = r16[bp] - 34;
    r16[cx] = -r16[cx];
    r16[cx] += r16[si];
    flags.direction = 0;
  case 0xf23a:
    r16[si]--;
    r8[al] = memoryAGet(ds, r16[si]);
    flags.carry = r8[al] < 0x0a;
    r8[al] -= 0x0a;
    if (!flags.carry)
        { pc = 0xf245; break; }
    r8[al] += 0x3a;
    { pc = 0xf248; break; }
  case 0xf245:
    r8[al] += memoryAGet(ss, r16[bp] + 4);
  case 0xf248:
    stosb_ESDI(r8[al]);
    if (--r16[cx])
        { pc = 0xf23a; break; }
  case 0xf24b:
    r8[al] = 0x00;
    stosb_ESDI(r8[al]);
    es = pop();
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 14;
    return;
  }
}
function* sub_f25a() // 01ed:d38a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    if (memoryAGet16(ss, r16[bp] + 8) != 0x000a)
        { pc = 0xf269; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    { pc = 0xf26e; break; }
  case 0xf269:
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[dx] = 0;
  case 0xf26e:
    push(r16[dx]);
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 8));
    r8[al] = 0x01;
    push(r16[ax]);
    r8[al] = 0x61;
    push(r16[ax]);
    yield* sub_f1dd();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f29b() // 01ed:d3cb
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    push(memoryAGet16(ss, r16[bp] + 8));
    push(memoryAGet16(ss, r16[bp] + 10));
    if (memoryAGet16(ss, r16[bp] + 10) != 0x000a)
        { pc = 0xf2b5; break; }
    r16[ax] = 0x0001;
    { pc = 0xf2b7; break; }
  case 0xf2b5:
    r16[ax] = 0;
  case 0xf2b7:
    push(r16[ax]);
    r8[al] = 0x61;
    push(r16[ax]);
    yield* sub_f1dd();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f2c0() // 01ed:d3f0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = ds;
    es = r16[ax];
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    r16[cx] = memoryAGet16(ss, r16[bp] + 8);
    flags.carry = r16[cx] & 1;
    r16[cx] >>= 1;
    flags.direction = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    if (!flags.carry)
        { pc = 0xf2da; break; }
    movsb_ESDI_DSSI();
  case 0xf2da:
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f2e1() // 01ed:d411
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[di]);
    r16[ax] = ds;
    es = r16[ax];
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[cx] = memoryAGet16(ss, r16[bp] + 6);
    r8[al] = memoryAGet(ss, r16[bp] + 8);
    r8[ah] = r8[al];
    flags.direction = 0;
    if (!(r16[di] & 0x0001))
        { pc = 0xf2ff; break; }
    if (!r16[cx])
        { pc = 0xf306; break; }
    stosb_ESDI(r8[al]);
    r16[cx]--;
  case 0xf2ff:
    flags.carry = r16[cx] & 1;
    r16[cx] >>= 1;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    if (!flags.carry)
        { pc = 0xf306; break; }
    stosb_ESDI(r8[al]);
  case 0xf306:
    r16[di] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f309() // 01ed:d439
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r8[al] = memoryAGet(ss, r16[bp] + 6);
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 8));
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f2e1();
    sp += 0x0006;
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[bp] = pop();
    sp += 2;
}
function* sub_f321() // 01ed:d451
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    flags.direction = 0;
    r16[cx] = memoryAGet16(ss, r16[bp] + 12);
    r16[di] = memoryAGet16(ss, r16[bp] + 10);
    es = memoryAGet16(ss, r16[bp] + 8);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    push(ds);
    ds = memoryAGet16(ss, r16[bp] + 4);
    flags.carry = r16[cx] & 1;
    r16[cx] >>= 1;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    if (!flags.carry)
        { pc = 0xf33e; break; }
    movsb_ESDI_DSSI();
  case 0xf33e:
    ds = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f343() // 01ed:d473 +stackDrop4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[cx] = memoryAGet16(ss, r16[bp] + 4);
    r8[ah] = 0x3c;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xf354; break; }
    { pc = 0xf358; break; }
  case 0xf354:
    push(r16[ax]);
    yield* sub_f166();
  case 0xf358:
    r16[bp] = pop();
    sp += 6;
    return;
  }
}
function* sub_f35c() // 01ed:d48c +stackDrop2
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[cx] -= r16[cx];
    r16[dx] -= r16[dx];
    r8[ah] = 0x40;
    interrupt(0x21);
    r16[bp] = pop();
    sp += 4;
}
function* sub_f36e() // 01ed:d49e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    push(r16[di]);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    if (r16[si] & 0xc000)
        { pc = 0xf38b; break; }
    r16[ax] = memoryAGet16(ds, 0x5540);
    r16[ax] &= 0xc000;
    r16[dx] = r16[si];
    r16[dx] |= r16[ax];
    r16[si] = r16[dx];
  case 0xf38b:
    if (!(r16[si] & 0x0100))
        { pc = 0xf40b; break; }
    r16[ax] = memoryAGet16(ds, 0x5542);
    memoryASet16(ss, r16[bp] + 8, memoryAGet16(ss, r16[bp] + 8) & r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    if (r16[ax] & 0x0180)
        { pc = 0xf3a6; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    yield* sub_f166();
  case 0xf3a6:
    r16[ax] = 0;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_ee3d();
    r16[cx] = pop();
    r16[cx] = pop();
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    if (r16[ax] != 0xffff)
        { pc = 0xf3e2; break; }
    if (!(memoryAGet16(ss, r16[bp] + 8) & 0x0080))
        { pc = 0xf3c4; break; }
    r16[ax] = 0;
    { pc = 0xf3c7; break; }
  case 0xf3c4:
    r16[ax] = 0x0001;
  case 0xf3c7:
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    if (!(r16[si] & 0x00f0))
        { pc = 0xf3f9; break; }
    push(memoryAGet16(ss, r16[bp] + 4));
    r16[ax] = 0;
    push(r16[ax]);
    yield* sub_f343();
    r16[di] = r16[ax];
    if (r16s[ax] >= 0)
        { pc = 0xf3f2; break; }
    { pc = 0xf493; break; }
  case 0xf3e2:
    if (!(r16[si] & 0x0400))
        { pc = 0xf40b; break; }
    r16[ax] = 0x0050;
    push(r16[ax]);
    yield* sub_f166();
    { pc = 0xf495; break; }
  case 0xf3f2:
    push(r16[di]);
    yield* sub_ee58();
    r16[cx] = pop();
    { pc = 0xf410; break; }
  case 0xf3f9:
    push(memoryAGet16(ss, r16[bp] + 4));
    push(memoryAGet16(ss, r16[bp] - 2));
    yield* sub_f343();
    r16[di] = r16[ax];
    if (r16s[ax] >= 0)
        { pc = 0xf472; break; }
    { pc = 0xf493; break; }
  case 0xf40b:
    memoryASet16(ss, r16[bp] - 2, 0x0000);
  case 0xf410:
    push(r16[si]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f49b();
    r16[cx] = pop();
    r16[cx] = pop();
    r16[di] = r16[ax];
    if (r16s[ax] < 0)
        { pc = 0xf472; break; }
    r16[ax] = 0;
    push(r16[ax]);
    push(r16[di]);
    yield* sub_f13f();
    r16[cx] = pop();
    r16[cx] = pop();
    memoryASet16(ss, r16[bp] - 4, r16[ax]);
    if (!(r16[ax] & 0x0080))
        { pc = 0xf44e; break; }
    r16[si] |= 0x2000;
    if (!(r16[si] & 0x8000))
        { pc = 0xf458; break; }
    r16[ax] &= 0x00ff;
    r16[ax] |= 0x0020;
    push(r16[ax]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(r16[di]);
    yield* sub_f13f();
    sp += 0x0006;
    { pc = 0xf458; break; }
  case 0xf44e:
    if (!(r16[si] & 0x0200))
        { pc = 0xf458; break; }
    push(r16[di]);
    yield* sub_f35c();
  case 0xf458:
    if (!memoryAGet16(ss, r16[bp] - 2))
        { pc = 0xf472; break; }
    if (!(r16[si] & 0x00f0))
        { pc = 0xf472; break; }
    r16[ax] = 0x0001;
    push(r16[ax]);
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_ee3d();
    sp += 0x0006;
  case 0xf472:
    if (r16s[di] < 0)
        { pc = 0xf493; break; }
    if (!(r16[si] & 0x0300))
        { pc = 0xf481; break; }
    r16[ax] = 0x1000;
    { pc = 0xf483; break; }
  case 0xf481:
    r16[ax] = 0;
  case 0xf483:
    r16[dx] = r16[si];
    r16[dx] &= 0xf8ff;
    r16[dx] |= r16[ax];
    r16[bx] = r16[di];
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 21784, r16[dx]);
  case 0xf493:
    r16[ax] = r16[di];
  case 0xf495:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f49b() // 01ed:d5cb
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp--;
    sp--;
    r8[al] = 0x01;
    r16[cx] = memoryAGet16(ss, r16[bp] + 6);
    if (r16[cx] & 0x0002)
        { pc = 0xf4b5; break; }
    r8[al] = 0x02;
    if (r16[cx] & 0x0004)
        { pc = 0xf4b5; break; }
    r8[al] = 0x00;
  case 0xf4b5:
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    r8[cl] = 0xf0;
    r8[cl] &= memoryAGet(ss, r16[bp] + 6);
    r8[al] |= r8[cl];
    r8[ah] = 0x3d;
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xf4df; break; }
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] - 2);
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] &= 0xf8ff;
    r16[ax] |= 0x8000;
    memoryASet16(ds, r16[bx] + 21784, r16[ax]);
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    { pc = 0xf4e3; break; }
  case 0xf4df:
    push(r16[ax]);
    yield* sub_f166();
  case 0xf4e3:
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f4e7() // 01ed:d617
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = memoryAGet16(ss, r16[bp] + 6);
    out16(r16[dx], r16[ax]);
    r16[bp] = pop();
    sp += 2;
}
function* sub_f4f3() // 01ed:d623
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[dx] = memoryAGet16(ss, r16[bp] + 4);
    r8[al] = memoryAGet(ss, r16[bp] + 6);
    out8(r16[dx], r8[al]);
    r16[bp] = pop();
    sp += 2;
}
function* sub_f4ff() // 01ed:d62f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0004;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = memoryAGet16(ss, r16[bp] + 8);
    r16[ax]++;
    if (r16[ax] < 0x0002)
        { pc = 0xf51d; break; }
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] <<= 1;
    if (!(memoryAGet16(ds, r16[bx] + 21784) & 0x0200))
        { pc = 0xf522; break; }
  case 0xf51d:
    r16[ax] = 0;
    { pc = 0xf5ae; break; }
  case 0xf522:
    push(memoryAGet16(ss, r16[bp] + 8));
    push(memoryAGet16(ss, r16[bp] + 6));
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f5b4();
    sp += 0x0006;
    memoryASet16(ss, r16[bp] - 2, r16[ax]);
    r16[ax]++;
    if (r16[ax] < 0x0002)
        { pc = 0xf547; break; }
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] <<= 1;
    if (!(memoryAGet16(ds, r16[bx] + 21784) & 0x8000))
        { pc = 0xf54c; break; }
  case 0xf547:
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    { pc = 0xf5ae; break; }
  case 0xf54c:
    r16[cx] = memoryAGet16(ss, r16[bp] - 2);
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
    push(ds);
    es = pop();
    r16[di] = r16[si];
    r16[bx] = r16[si];
    flags.direction = 0;
  case 0xf559:
    r8[al] = lodsb_DSSI();
    if (r8[al] == 0x1a)
        { pc = 0xf58b; break; }
    if (r8[al] == 0x0d)
        { pc = 0xf567; break; }
    stosb_ESDI(r8[al]);
    if (--r16[cx])
        { pc = 0xf559; break; }
    { pc = 0xf583; break; }
  case 0xf567:
    if (--r16[cx])
        { pc = 0xf559; break; }
    push(es);
    push(r16[bx]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    r16[ax] = r16[bp] - 3;
    push(r16[ax]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f5b4();
    sp += 0x0006;
    r16[bx] = pop();
    es = pop();
    flags.direction = 0;
    r8[al] = memoryAGet(ss, r16[bp] - 3);
    stosb_ESDI(r8[al]);
  case 0xf583:
    if (r16[di] != r16[bx])
        { pc = 0xf589; break; }
    { pc = 0xf522; break; }
  case 0xf589:
    { pc = 0xf5ab; break; }
  case 0xf58b:
    push(r16[bx]);
    r16[ax] = 0x0001;
    push(r16[ax]);
    flags.carry = r16[cx] != 0;
    r16[cx] = -r16[cx];
    r16[ax] = -flags.carry;
    push(r16[ax]);
    push(r16[cx]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f1b4();
    sp += 0x0008;
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 21784, memoryAGet16(ds, r16[bx] + 21784) | 0x0200);
    r16[bx] = pop();
  case 0xf5ab:
    r16[di] -= r16[bx];
    r16[tx] = r16[di]; r16[di] = r16[ax]; r16[ax] = r16[tx];
  case 0xf5ae:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f5b4() // 01ed:d6e4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r8[ah] = 0x3f;
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[cx] = memoryAGet16(ss, r16[bp] + 8);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xf5c8; break; }
    { pc = 0xf5cc; break; }
  case 0xf5c8:
    push(r16[ax]);
    yield* sub_f166();
  case 0xf5cc:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f5ce() // 01ed:d6fe
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r8[ah] = 0x4a;
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    es = memoryAGet16(ss, r16[bp] + 4);
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xf5e2; break; }
    r16[ax] = 0xffff;
    { pc = 0xf5e8; break; }
  case 0xf5e2:
    push(r16[bx]);
    push(r16[ax]);
    yield* sub_f166();
    r16[ax] = pop();
  case 0xf5e8:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f5ea() // 01ed:d71a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    flags.direction = 0;
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    push(ds);
    es = pop();
    r16[dx] = r16[di];
    r8[al] = 0;
    r16[cx] = 0xffff;
    for (flags.zero = 0; r16[cx] != 0 && !flags.zero; --r16[cx]) scasb_inv_ESDI(r8[al]);
    r16[si] = r16[di] - 1;
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    r16[cx] = 0xffff;
    for (flags.zero = 0; r16[cx] != 0 && !flags.zero; --r16[cx]) scasb_inv_ESDI(r8[al]);
    r16[cx] = ~r16[cx];
    r16[di] -= r16[cx];
    r16[tx] = r16[di]; r16[di] = r16[si]; r16[si] = r16[tx];
    if (!(r16[si] & 0x0001))
        { pc = 0xf617; break; }
    movsb_ESDI_DSSI();
    r16[cx]--;
  case 0xf617:
    flags.carry = r16[cx] & 1;
    r16[cx] >>= 1;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    if (!flags.carry)
        { pc = 0xf61e; break; }
    movsb_ESDI_DSSI();
  case 0xf61e:
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_f623() // 01ed:d753
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    r16[ax] = ds;
    es = r16[ax];
    flags.direction = 0;
    r16[di] = memoryAGet16(ss, r16[bp] + 6);
    r16[si] = r16[di];
    r8[al] = 0;
    r16[cx] = 0xffff;
    for (flags.zero = 0; r16[cx] != 0 && !flags.zero; --r16[cx]) scasb_inv_ESDI(r8[al]);
    r16[cx] = ~r16[cx];
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
}
function* sub_f647() // 01ed:d777
{
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[di]);
    r16[ax] = ds;
    es = r16[ax];
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = 0;
    flags.direction = 0;
    r16[cx] = 0xffff;
    for (flags.zero = 0; r16[cx] != 0 && !flags.zero; --r16[cx]) scasb_inv_ESDI(r8[al]);
    r16[tx] = r16[cx]; r16[cx] = r16[ax]; r16[ax] = r16[tx];
    r16[ax] = ~r16[ax];
    r16[ax]--;
    r16[di] = pop();
    r16[bp] = pop();
    sp += 2;
}
function* sub_f679() // 01ed:d7a9 +stackDrop8
{
  var pc = 0;
  var temp_cond0;
  var temp_cond1;
  var temp_cond2;
  var temp_cond3;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    sp -= 0x0096;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(ss, r16[bp] - 18, 0x0000);
    memoryASet16(ss, r16[bp] - 20, 0x0050);
    memoryASet16(ss, r16[bp] - 22, 0x0000);
    { pc = 0xf6d9; break; }
    // gap 70 bytes
  case 0xf6d9:
    push(es);
    flags.direction = 0;
    r16[di] = r16[bp] - 150;
    memoryASet16(ss, r16[bp] - 4, r16[di]);
    r16[di] = memoryAGet16(ss, r16[bp] - 4);
  case 0xf6e5:
    r16[si] = memoryAGet16(ss, r16[bp] + 6);
  case 0xf6e8:
    r8[al] = lodsb_DSSI();
    if (!r8[al])
        { pc = 0xf6ff; break; }
    if (r8[al] == 0x25)
        { pc = 0xf702; break; }
  case 0xf6f1:
    memoryASet(ss, r16[di], r8[al]);
    r16[di]++;
    temp_cond0 = signed8(memoryAGet(ss, r16[bp] - 20)) > 1;
    memoryASet(ss, r16[bp] - 20, memoryAGet(ss, r16[bp] - 20) - 1);
    if (temp_cond0)
        { pc = 0xf6e8; break; }
    yield* sub_f6a9();
    { pc = 0xf6e8; break; }
  case 0xf6ff:
    { pc = 0xfaed; break; }
  case 0xf702:
    memoryASet16(ss, r16[bp] - 16, r16[si]);
    r8[al] = lodsb_DSSI();
    if (r8[al] == 0x25)
        { pc = 0xf6f1; break; }
    memoryASet16(ss, r16[bp] - 4, r16[di]);
    r16[cx] = 0;
    memoryASet16(ss, r16[bp] - 14, r16[cx]);
    memoryASet16(ss, r16[bp] - 2, r16[cx]);
    memoryASet(ss, r16[bp] - 11, r8[cl]);
    memoryASet16(ss, r16[bp] - 8, 0xffff);
    memoryASet16(ss, r16[bp] - 10, 0xffff);
    { pc = 0xf725; break; }
  case 0xf724:
    r8[al] = lodsb_DSSI();
  case 0xf725:
    r8[ah] = 0;
    r16[dx] = r16[ax];
    r16[bx] = r16[ax];
    r8[bl] -= 0x20;
    if (r8[bl] >= 0x60)
        { pc = 0xf746; break; }
    r8[bl] = memoryAGet(ds, r16[bx] + 21961);
    if (r16[bx] <= 0x0017)
        { pc = 0xf73f; break; }
    { pc = 0xfadd; break; }
  case 0xf73f:
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: { pc = 0xf75f; break; }
        case 2: { pc = 0xf749; break; }
        case 4: { pc = 0xf794; break; }
        case 6: { pc = 0xf754; break; }
        case 8: { pc = 0xf7c2; break; }
        case 10: { pc = 0xf7cc; break; }
        case 12: { pc = 0xf80a; break; }
        case 14: { pc = 0xf811; break; }
        case 16: { pc = 0xf816; break; }
        case 18: { pc = 0xf77d; break; }
        case 20: { pc = 0xf83f; break; }
        default:
            stop("ind 01ed:d871");
    }
    break;
  case 0xf746:
    { pc = 0xfadd; break; }
  case 0xf749:
    if (r8[ch] > 0x00)
        { pc = 0xf746; break; }
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) | 0x0001);
    { pc = 0xf724; break; }
  case 0xf754:
    if (r8[ch] > 0x00)
        { pc = 0xf746; break; }
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) | 0x0002);
    { pc = 0xf724; break; }
  case 0xf75f:
    if (r8[ch] > 0x00)
        { pc = 0xf746; break; }
    if (memoryAGet(ss, r16[bp] - 11) == 0x2b)
        { pc = 0xf76d; break; }
    memoryASet(ss, r16[bp] - 11, r8[dl]);
  case 0xf76d:
    { pc = 0xf724; break; }
    // gap 10 bytes
  case 0xf779:
    r8[ch] = 0x05;
    { pc = 0xf724; break; }
  case 0xf77d:
    if (r8[ch] > 0x00)
        { pc = 0xf7cc; break; }
    if (memoryAGet16(ss, r16[bp] - 2) & 0x0002)
        { pc = 0xf7b2; break; }
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) | 0x0008);
    r8[ch] = 0x01;
    { pc = 0xf724; break; }
  case 0xf791:
    { pc = 0xfadd; break; }
  case 0xf794:
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = memoryAGet16(ss, r16[di]);
    memoryASet16(ss, r16[bp] + 4, memoryAGet16(ss, r16[bp] + 4) + 0x0002);
    if (r8[ch] >= 0x02)
        { pc = 0xf7b5; break; }
    if (r16s[ax] >= 0)
        { pc = 0xf7ad; break; }
    r16[ax] = -r16[ax];
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) | 0x0002);
  case 0xf7ad:
    memoryASet16(ss, r16[bp] - 8, r16[ax]);
    r8[ch] = 0x03;
  case 0xf7b2:
    { pc = 0xf724; break; }
  case 0xf7b5:
    if (r8[ch] != 0x04)
        { pc = 0xf791; break; }
    memoryASet16(ss, r16[bp] - 10, r16[ax]);
    r8[ch]++;
    { pc = 0xf724; break; }
  case 0xf7c2:
    if (r8[ch] >= 0x04)
        { pc = 0xf791; break; }
    r8[ch] = 0x04;
    { pc = 0xf724; break; }
  case 0xf7cc:
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r8[al] -= 0x30;
    cbw();
    if (r8[ch] > 0x02)
        { pc = 0xf7ee; break; }
    r8[ch] = 0x02;
    r16[tx] = memoryAGet16(ss, r16[bp] - 8); memoryASet16(ss, r16[bp] - 8, r16[ax]); r16[ax] = r16[tx];
    if (r16s[ax] < 0)
        { pc = 0xf7b2; break; }
    r16[ax] <<= 1;
    r16[dx] = r16[ax];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += r16[dx];
    memoryASet16(ss, r16[bp] - 8, memoryAGet16(ss, r16[bp] - 8) + r16[ax]);
    { pc = 0xf724; break; }
  case 0xf7ee:
    if (r8[ch] != 0x04)
        { pc = 0xf791; break; }
    r16[tx] = memoryAGet16(ss, r16[bp] - 10); memoryASet16(ss, r16[bp] - 10, r16[ax]); r16[ax] = r16[tx];
    if (r16s[ax] < 0)
        { pc = 0xf7b2; break; }
    r16[ax] <<= 1;
    r16[dx] = r16[ax];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += r16[dx];
    memoryASet16(ss, r16[bp] - 10, memoryAGet16(ss, r16[bp] - 10) + r16[ax]);
    { pc = 0xf724; break; }
  case 0xf80a:
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) | 0x0010);
    { pc = 0xf779; break; }
  case 0xf811:
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) | 0x0100);
  case 0xf816:
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) & 0xffef);
    { pc = 0xf779; break; }
    // gap 34 bytes
  case 0xf83f:
    r8[bh] = 0x0a;
    memoryASet(ss, r16[bp] - 6, 0x01);
    memoryASet(ss, r16[bp] - 5, r8[dl]);
    r16[di] = memoryAGet16(ss, r16[bp] + 4);
    r16[ax] = memoryAGet16(ss, r16[di]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[di]++;
    r16[di]++;
    memoryASet16(ss, r16[bp] + 6, r16[si]);
    if (!(memoryAGet16(ss, r16[bp] - 2) & 0x0010))
        { pc = 0xf860; break; }
    r16[dx] = memoryAGet16(ss, r16[di]);
    r16[di]++;
    r16[di]++;
  case 0xf860:
    memoryASet16(ss, r16[bp] + 4, r16[di]);
    r16[di] = r16[bp] - 69;
    if (r16[ax])
        { pc = 0xf899; break; }
    if (r16[dx])
        { pc = 0xf899; break; }
    if (memoryAGet16(ss, r16[bp] - 10))
        { pc = 0xf89d; break; }
    r16[di] = memoryAGet16(ss, r16[bp] - 4);
    r16[cx] = memoryAGet16(ss, r16[bp] - 8);
    if (!r16[cx])
        { pc = 0xf896; break; }
    if (r16[cx] == 0xffff)
        { pc = 0xf896; break; }
    r16[ax] = memoryAGet16(ss, r16[bp] - 2);
    r16[ax] &= 0x0008;
    if (!r16[ax])
        { pc = 0xf88d; break; }
    r8[dl] = 0x30;
    { pc = 0xf88f; break; }
  case 0xf88d:
    r8[dl] = 0x20;
  case 0xf88f:
    r8[al] = r8[dl];
    yield* sub_f6a0();
    if (--r16[cx])
        { pc = 0xf88f; break; }
  case 0xf896:
    { pc = 0xf6e5; break; }
  case 0xf899:
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) | 0x0004);
  case 0xf89d:
    push(r16[dx]);
    push(r16[ax]);
    push(r16[di]);
    r8[al] = r8[bh];
    cbw();
    push(r16[ax]);
    r8[al] = memoryAGet(ss, r16[bp] - 6);
    push(r16[ax]);
    push(r16[bx]);
    yield* sub_f1dd();
    push(ss);
    es = pop();
    r16[dx] = memoryAGet16(ss, r16[bp] - 10);
    if (r16s[dx] > 0)
        { pc = 0xf8b8; break; }
    { pc = 0xf9a9; break; }
  case 0xf8b8:
    { pc = 0xf9b7; break; }
    // gap 238 bytes
  case 0xf9a9:
    if (!(memoryAGet16(ss, r16[bp] - 2) & 0x0008))
        { pc = 0xf9c8; break; }
    r16[dx] = memoryAGet16(ss, r16[bp] - 8);
    if (r16s[dx] <= 0)
        { pc = 0xf9c8; break; }
  case 0xf9b7:
    yield* sub_f693();
    if (memoryAGet(es, r16[di]) != 0x2d)
        { pc = 0xf9c1; break; }
    r16[cx]--;
  case 0xf9c1:
    temp_cond1 = r16s[dx] <= r16s[cx];
    r16[dx] -= r16[cx];
    if (temp_cond1)
        { pc = 0xf9c8; break; }
    memoryASet16(ss, r16[bp] - 14, r16[dx]);
  case 0xf9c8:
    r8[al] = memoryAGet(ss, r16[bp] - 11);
    if (!r8[al])
        { pc = 0xf9e1; break; }
    if (memoryAGet(es, r16[di]) == 0x2d)
        { pc = 0xf9e1; break; }
    flags.carry = memoryAGet16(ss, r16[bp] - 14) < 0x0001;
    memoryASet16(ss, r16[bp] - 14, memoryAGet16(ss, r16[bp] - 14) - 0x0001);
    memoryASet16(ss, r16[bp] - 14, memoryAGet16(ss, r16[bp] - 14) + (0x0000 + flags.carry));
    r16[di]--;
    memoryASet(es, r16[di], r8[al]);
  case 0xf9e1:
    yield* sub_f693();
    r16[si] = r16[di];
    r16[di] = memoryAGet16(ss, r16[bp] - 4);
    r16[bx] = memoryAGet16(ss, r16[bp] - 8);
    r16[ax] = 0x0005;
    r16[ax] &= memoryAGet16(ss, r16[bp] - 2);
    if (r16[ax] != 0x0005)
        { pc = 0xfa0a; break; }
    r8[ah] = memoryAGet(ss, r16[bp] - 5);
    if (r8[ah] != 0x6f)
        { pc = 0xfa0c; break; }
    if (signed16(memoryAGet16(ss, r16[bp] - 14)) > signed16(0x0000))
        { pc = 0xfa0a; break; }
    memoryASet16(ss, r16[bp] - 14, 0x0001);
  case 0xfa0a:
    { pc = 0xfa27; break; }
  case 0xfa0c:
    if (r8[ah] == 0x78)
        { pc = 0xfa16; break; }
    if (r8[ah] != 0x58)
        { pc = 0xfa27; break; }
  case 0xfa16:
    memoryASet16(ss, r16[bp] - 2, memoryAGet16(ss, r16[bp] - 2) | 0x0040);
    r16[bx]--;
    r16[bx]--;
    temp_cond2 = signed16(memoryAGet16(ss, r16[bp] - 14)) >= signed16(0x0002);
    memoryASet16(ss, r16[bp] - 14, memoryAGet16(ss, r16[bp] - 14) - 0x0002);
    if (temp_cond2)
        { pc = 0xfa27; break; }
    memoryASet16(ss, r16[bp] - 14, 0x0000);
  case 0xfa27:
    r16[cx] += memoryAGet16(ss, r16[bp] - 14);
    if (memoryAGet16(ss, r16[bp] - 2) & 0x0002)
        { pc = 0xfa3d; break; }
    { pc = 0xfa39; break; }
  case 0xfa33:
    r8[al] = 0x20;
    yield* sub_f6a0();
    r16[bx]--;
  case 0xfa39:
    if (r16s[bx] > r16s[cx])
        { pc = 0xfa33; break; }
  case 0xfa3d:
    if (!(memoryAGet16(ss, r16[bp] - 2) & 0x0040))
        { pc = 0xfa4f; break; }
    r8[al] = 0x30;
    yield* sub_f6a0();
    r8[al] = memoryAGet(ss, r16[bp] - 5);
    yield* sub_f6a0();
  case 0xfa4f:
    r16[dx] = memoryAGet16(ss, r16[bp] - 14);
    if (r16s[dx] <= 0)
        { pc = 0xfa7d; break; }
    r16[cx] -= r16[dx];
    r16[bx] -= r16[dx];
    r8[al] = memoryAGet(es, r16[si]);
    if (r8[al] == 0x2d)
        { pc = 0xfa69; break; }
    if (r8[al] == 0x20)
        { pc = 0xfa69; break; }
    if (r8[al] != 0x2b)
        { pc = 0xfa70; break; }
  case 0xfa69:
    r8[al] = lodsb_ESSI();
    yield* sub_f6a0();
    r16[cx]--;
    r16[bx]--;
  case 0xfa70:
    r16[tx] = r16[dx]; r16[dx] = r16[cx]; r16[cx] = r16[tx];
    if (!r16[cx])
        { pc = 0xfa7b; break; }
  case 0xfa74:
    r8[al] = 0x30;
    yield* sub_f6a0();
    if (--r16[cx])
        { pc = 0xfa74; break; }
  case 0xfa7b:
    r16[tx] = r16[dx]; r16[dx] = r16[cx]; r16[cx] = r16[tx];
  case 0xfa7d:
    if (!r16[cx])
        { pc = 0xfa91; break; }
    r16[bx] -= r16[cx];
  case 0xfa81:
    r8[al] = lodsb_ESSI();
    memoryASet(ss, r16[di], r8[al]);
    r16[di]++;
    temp_cond3 = signed8(memoryAGet(ss, r16[bp] - 20)) > 1;
    memoryASet(ss, r16[bp] - 20, memoryAGet(ss, r16[bp] - 20) - 1);
    if (temp_cond3)
        { pc = 0xfa8f; break; }
    yield* sub_f6a9();
  case 0xfa8f:
    if (--r16[cx])
        { pc = 0xfa81; break; }
  case 0xfa91:
    if (r16s[bx] <= 0)
        { pc = 0xfa9e; break; }
    r16[cx] = r16[bx];
  case 0xfa97:
    r8[al] = 0x20;
    yield* sub_f6a0();
    if (--r16[cx])
        { pc = 0xfa97; break; }
  case 0xfa9e:
    { pc = 0xf6e5; break; }
    // gap 60 bytes
  case 0xfadd:
    r16[si] = memoryAGet16(ss, r16[bp] - 16);
    r16[di] = memoryAGet16(ss, r16[bp] - 4);
    r8[al] = 0x25;
  case 0xfae5:
    yield* sub_f6a0();
    r8[al] = lodsb_DSSI();
    if (r8[al])
        { pc = 0xfae5; break; }
  case 0xfaed:
    if (signed8(memoryAGet(ss, r16[bp] - 20)) >= signed8(0x50))
        { pc = 0xfaf6; break; }
    yield* sub_f6a9();
  case 0xfaf6:
    es = pop();
    if (!memoryAGet16(ss, r16[bp] - 22))
        { pc = 0xfb02; break; }
    r16[ax] = 0xffff;
    { pc = 0xfb05; break; }
  case 0xfb02:
    r16[ax] = memoryAGet16(ss, r16[bp] - 18);
  case 0xfb05:
    r16[di] = pop();
    r16[si] = pop();
    sp = r16[bp];
    r16[bp] = pop();
    sp += 10;
    return;
  }
}
function* sub_f693() // 01ed:d7c3
{
    sp -= 2;
    push(r16[di]);
    r16[cx] = 0xffff;
    r8[al] = 0;
    for (flags.zero = 0; r16[cx] != 0 && !flags.zero; --r16[cx]) scasb_inv_ESDI(r8[al]);
    r16[cx] = ~r16[cx];
    r16[cx]--;
    r16[di] = pop();
    sp += 2;
}
function* sub_f6a0() // 01ed:d7d0
{
  var pc = 0;
  var temp_cond0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    memoryASet(ss, r16[di], r8[al]);
    r16[di]++;
    temp_cond0 = signed8(memoryAGet(ss, r16[bp] - 20)) <= 1;
    memoryASet(ss, r16[bp] - 20, memoryAGet(ss, r16[bp] - 20) - 1);
    if (temp_cond0)
        { pc = 0xf6d8; break; }
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(es);
    r16[ax] = r16[bp] - 150;
    r16[di] -= r16[ax];
    r16[ax] = r16[bp] - 150;
    push(r16[ax]);
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] + 8));
    yield* indirectCall(cs, memoryAGet16(ss, r16[bp] + 10));
    if (r16[ax])
        { pc = 0xf6c8; break; }
    memoryASet16(ss, r16[bp] - 22, 0x0001);
  case 0xf6c8:
    memoryASet16(ss, r16[bp] - 20, 0x0050);
    memoryASet16(ss, r16[bp] - 18, memoryAGet16(ss, r16[bp] - 18) + r16[di]);
    r16[di] = r16[bp] - 150;
    es = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
  case 0xf6d8:
    sp += 2; return;
    return;
  }
}
function* sub_f6a9() // 01ed:d7d9
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(es);
    r16[ax] = r16[bp] - 150;
    r16[di] -= r16[ax];
    r16[ax] = r16[bp] - 150;
    push(r16[ax]);
    push(r16[di]);
    push(memoryAGet16(ss, r16[bp] + 8));
    yield* indirectCall(cs, memoryAGet16(ss, r16[bp] + 10));
    if (r16[ax])
        { pc = 0xf6c8; break; }
    memoryASet16(ss, r16[bp] - 22, 0x0001);
  case 0xf6c8:
    memoryASet16(ss, r16[bp] - 20, 0x0050);
    memoryASet16(ss, r16[bp] - 18, memoryAGet16(ss, r16[bp] - 18) + r16[di]);
    r16[di] = r16[bp] - 150;
    es = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    stop("stack_unbalanced");
    sp += 2;
    return;
  }
}
function* sub_fb3d() // 01ed:dc6d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] <<= 1;
    if (!(memoryAGet16(ds, r16[bx] + 21784) & 0x0800))
        { pc = 0xfb60; break; }
    r16[ax] = 0x0002;
    push(r16[ax]);
    r16[ax] = 0;
    r16[dx] = 0;
    push(r16[ax]);
    push(r16[dx]);
    push(memoryAGet16(ss, r16[bp] + 4));
    yield* sub_f1b4();
    sp += 0x0008;
  case 0xfb60:
    r8[ah] = 0x40;
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[cx] = memoryAGet16(ss, r16[bp] + 8);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    interrupt(0x21);
    if (flags.carry)
        { pc = 0xfb7e; break; }
    push(r16[ax]);
    r16[bx] = memoryAGet16(ss, r16[bp] + 4);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 21784, memoryAGet16(ds, r16[bx] + 21784) | 0x1000);
    r16[ax] = pop();
    { pc = 0xfb82; break; }
  case 0xfb7e:
    push(r16[ax]);
    yield* sub_f166();
  case 0xfb82:
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_fb9c() // 01ed:dccc
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (r16[dx] == memoryAGet16(cs, 0xdcc0))
        { pc = 0xfbda; break; }
    ds = r16[dx];
    ds = memoryAGet16(ds, 0x0002);
    if (!memoryAGet16(ds, 0x0002))
        { pc = 0xfbb7; break; }
    memoryASet16(cs, 0xdcc2, ds);
    { pc = 0xfbef; break; }
  case 0xfbb7:
    r16[ax] = ds;
    if (r16[ax] == memoryAGet16(cs, 0xdcc0))
        { pc = 0xfbd5; break; }
    r16[ax] = memoryAGet16(ds, 0x0008);
    memoryASet16(cs, 0xdcc2, r16[ax]);
    push(ds);
    r16[ax] = 0;
    push(r16[ax]);
    yield* sub_fc6f();
    ds = memoryAGet16(cs, 0xdcc6);
    { pc = 0xfbf8; break; }
  case 0xfbd5:
    r16[dx] = memoryAGet16(cs, 0xdcc0);
  case 0xfbda:
    memoryASet16(cs, 0xdcc0, 0x0000);
    memoryASet16(cs, 0xdcc2, 0x0000);
    memoryASet16(cs, 0xdcc4, 0x0000);
  case 0xfbef:
    ds = memoryAGet16(cs, 0xdcc6);
    push(r16[dx]);
    r16[ax] = 0;
    push(r16[ax]);
  case 0xfbf8:
    yield* sub_e548();
    r16[ax] = pop();
    r16[ax] = pop();
    sp += 2;
    return;
  }
}
function* sub_fbfe() // 01ed:dd2e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    ds = r16[dx];
    push(ds);
    es = memoryAGet16(ds, 0x0002);
    memoryASet16(ds, 0x0002, 0x0000);
    memoryASet16(ds, 0x0008, es);
    if (r16[dx] == memoryAGet16(cs, 0xdcc0))
        { pc = 0xfc44; break; }
    if (memoryAGet16(es, 0x0002))
        { pc = 0xfc44; break; }
    r16[ax] = memoryAGet16(ds, 0x0000);
    r16[bx] = pop();
    push(es);
    memoryASet16(es, 0x0000, memoryAGet16(es, 0x0000) + r16[ax]);
    r16[cx] = es;
    r16[dx] += r16[ax];
    es = r16[dx];
    if (memoryAGet16(es, 0x0002))
        { pc = 0xfc3d; break; }
    memoryASet16(es, 0x0008, r16[cx]);
    { pc = 0xfc47; break; }
  case 0xfc3d:
    memoryASet16(es, 0x0002, r16[cx]);
    { pc = 0xfc47; break; }
  case 0xfc44:
    yield* sub_fc98();
  case 0xfc47:
    es = pop();
    r16[ax] = es;
    r16[ax] += memoryAGet16(es, 0x0000);
    ds = r16[ax];
    if (!memoryAGet16(ds, 0x0002))
        { pc = 0xfc59; break; }
    sp += 2; return;
  case 0xfc59:
    r16[ax] = memoryAGet16(ds, 0x0000);
    memoryASet16(es, 0x0000, memoryAGet16(es, 0x0000) + r16[ax]);
    r16[ax] = es;
    r16[bx] = ds;
    r16[bx] += memoryAGet16(ds, 0x0000);
    es = r16[bx];
    memoryASet16(es, 0x0002, r16[ax]);
    r16[bx] = ds;
    if (r16[bx] == memoryAGet16(ds, 0x0006))
        { pc = 0xfc90; break; }
    es = memoryAGet16(ds, 0x0006);
    ds = memoryAGet16(ds, 0x0004);
    memoryASet16(ds, 0x0006, es);
    memoryASet16(es, 0x0004, ds);
    memoryASet16(cs, 0xdcc4, ds);
    ds = r16[bx];
    sp += 2; return;
  case 0xfc90:
    memoryASet16(cs, 0xdcc4, 0x0000);
    sp += 2;
    return;
  }
}
function* sub_fc6f() // 01ed:dd9f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[bx] = ds;
    if (r16[bx] == memoryAGet16(ds, 0x0006))
        { pc = 0xfc90; break; }
    es = memoryAGet16(ds, 0x0006);
    ds = memoryAGet16(ds, 0x0004);
    memoryASet16(ds, 0x0006, es);
    memoryASet16(es, 0x0004, ds);
    memoryASet16(cs, 0xdcc4, ds);
    ds = r16[bx];
    sp += 2; return;
  case 0xfc90:
    memoryASet16(cs, 0xdcc4, 0x0000);
    sp += 2;
    return;
  }
}
function* sub_fc98() // 01ed:ddc8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[ax] = memoryAGet16(cs, 0xdcc4);
    if (!r16[ax])
        { pc = 0xfcc0; break; }
    r16[bx] = ss;
    flags.interrupts = 0;
    ss = r16[ax];
    es = memoryAGet16(ss, 0x0006);
    memoryASet16(ss, 0x0006, ds);
    memoryASet16(ds, 0x0004, ss);
    ss = r16[bx];
    flags.interrupts = 1;
    memoryASet16(es, 0x0004, ds);
    memoryASet16(ds, 0x0006, es);
    sp += 2; return;
  case 0xfcc0:
    memoryASet16(cs, 0xdcc4, ds);
    memoryASet16(ds, 0x0004, ds);
    memoryASet16(ds, 0x0006, ds);
    sp += 2;
    return;
  }
}
function* sub_fcce() // 01ed:ddfe
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    memoryASet16(cs, 0xdcc6, ds);
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    if (!r16[dx])
        { pc = 0xfcee; break; }
    if (r16[dx] != memoryAGet16(cs, 0xdcc2))
        { pc = 0xfceb; break; }
    yield* sub_fb9c();
    { pc = 0xfcee; break; }
  case 0xfceb:
    yield* sub_fbfe();
  case 0xfcee:
    ds = memoryAGet16(cs, 0xdcc6);
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_fcf7() // 01ed:de27
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[ax]);
    ds = memoryAGet16(cs, 0xdcc6);
    r16[ax] = 0;
    push(r16[ax]);
    push(r16[ax]);
    yield* sub_e587();
    r16[bx] = pop();
    r16[bx] = pop();
    r16[ax] &= 0x000f;
    if (!r16[ax])
        { pc = 0xfd1e; break; }
    r16[dx] = 0x0010;
    r16[dx] -= r16[ax];
    r16[ax] = 0;
    ds = memoryAGet16(cs, 0xdcc6);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_e587();
    r16[bx] = pop();
    r16[bx] = pop();
  case 0xfd1e:
    r16[ax] = pop();
    push(r16[ax]);
    r16[bx] = 0;
    r8[bl] = r8[ah];
    r8[cl] = 0x04;
    r16[bx] >>= r8[cl];
    r16[ax] <<= r8[cl];
    ds = memoryAGet16(cs, 0xdcc6);
    push(r16[bx]);
    push(r16[ax]);
    yield* sub_e587();
    r16[bx] = pop();
    r16[bx] = pop();
    r16[bx] = pop();
    if (r16[ax] == 0xffff)
        { pc = 0xfd54; break; }
    memoryASet16(cs, 0xdcc0, r16[dx]);
    memoryASet16(cs, 0xdcc2, r16[dx]);
    ds = r16[dx];
    memoryASet16(ds, 0x0000, r16[bx]);
    memoryASet16(ds, 0x0002, r16[dx]);
    r16[ax] = 0x0004;
    sp += 2; return;
  case 0xfd54:
    r16[ax] = 0;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    sp += 2;
    return;
  }
}
function* sub_fd58() // 01ed:de88
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[ax]);
    r16[bx] = 0;
    r8[bl] = r8[ah];
    r8[cl] = 0x04;
    r16[bx] >>= r8[cl];
    r16[ax] <<= r8[cl];
    ds = memoryAGet16(cs, 0xdcc6);
    push(r16[bx]);
    push(r16[ax]);
    yield* sub_e587();
    r16[bx] = pop();
    r16[bx] = pop();
    r16[bx] = pop();
    if (r16[ax] == 0xffff)
        { pc = 0xfd8d; break; }
    r16[cx] = memoryAGet16(cs, 0xdcc2);
    memoryASet16(cs, 0xdcc2, r16[dx]);
    ds = r16[dx];
    memoryASet16(ds, 0x0000, r16[bx]);
    memoryASet16(ds, 0x0002, r16[cx]);
    r16[ax] = 0x0004;
    sp += 2; return;
  case 0xfd8d:
    r16[ax] = 0;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    sp += 2;
    return;
  }
}
function* sub_fd91() // 01ed:dec1
{
    sp -= 2;
    r16[bx] = r16[dx];
    memoryASet16(ds, 0x0000, memoryAGet16(ds, 0x0000) - r16[ax]);
    r16[dx] += memoryAGet16(ds, 0x0000);
    ds = r16[dx];
    memoryASet16(ds, 0x0000, r16[ax]);
    memoryASet16(ds, 0x0002, r16[bx]);
    r16[bx] = r16[dx];
    r16[bx] += memoryAGet16(ds, 0x0000);
    ds = r16[bx];
    memoryASet16(ds, 0x0002, r16[dx]);
    r16[ax] = 0x0004;
    sp += 2;
}
function* sub_fdb4() // 01ed:dee4
{
  var pc = 0;
  var temp_cf;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bp]);
    r16[bp] = sp;
    r16[dx] = memoryAGet16(ss, r16[bp] + 6);
    r16[ax] = memoryAGet16(ss, r16[bp] + 4);
    push(r16[si]);
    push(r16[di]);
    memoryASet16(cs, 0xdcc6, ds);
    r16[cx] = r16[ax];
    r16[cx] |= r16[dx];
    if (!r16[cx])
        { pc = 0xfe28; break; }
    flags.carry = r16[ax] + 0x0013 >= 0x10000;
    r16[ax] += 0x0013;
    temp_cf = flags.carry;
    temp_cf = (r16[dx] + 0x0000) + flags.carry >= 0x10000;
    r16[dx] += (0x0000 + flags.carry);
    flags.carry = temp_cf;
    if (flags.carry)
        { pc = 0xfe13; break; }
    if (r16[dx] & 0xfff0)
        { pc = 0xfe13; break; }
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[dx] <<= r8[cl];
    r8[ah] |= r8[dl];
    r16[dx] = memoryAGet16(cs, 0xdcc0);
    if (!r16[dx])
        { pc = 0xfe09; break; }
    r16[dx] = memoryAGet16(cs, 0xdcc4);
    if (!r16[dx])
        { pc = 0xfe04; break; }
    r16[bx] = r16[dx];
  case 0xfdf4:
    ds = r16[dx];
    if (memoryAGet16(ds, 0x0000) >= r16[ax])
        { pc = 0xfe18; break; }
    r16[dx] = memoryAGet16(ds, 0x0006);
    if (r16[dx] != r16[bx])
        { pc = 0xfdf4; break; }
  case 0xfe04:
    yield* sub_fd58();
    { pc = 0xfe28; break; }
  case 0xfe09:
    yield* sub_fcf7();
    { pc = 0xfe28; break; }
  case 0xfe0e:
    yield* sub_fd91();
    { pc = 0xfe28; break; }
  case 0xfe13:
    r16[ax] = 0;
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    { pc = 0xfe28; break; }
  case 0xfe18:
    if (memoryAGet16(ds, 0x0000) > r16[ax])
        { pc = 0xfe0e; break; }
    yield* sub_fc6f();
    r16[bx] = memoryAGet16(ds, 0x0008);
    memoryASet16(ds, 0x0002, r16[bx]);
    r16[ax] = 0x0004;
  case 0xfe28:
    ds = memoryAGet16(cs, 0xdcc6);
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    sp += 2;
    return;
  }
}
function* sub_ff73() // 01ed:e0a3 +stackDrop10 +nearAsFar
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[cx] = pop();
    push(cs);
    push(r16[cx]);
    r16[cx] = 0;
    { pc = 0xff90; break; }
    // gap 22 bytes
  case 0xff90:
    push(r16[bp]);
    push(r16[si]);
    push(r16[di]);
    r16[bp] = sp;
    r16[di] = r16[cx];
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[dx] = memoryAGet16(ss, r16[bp] + 12);
    r16[bx] = memoryAGet16(ss, r16[bp] + 14);
    r16[cx] = memoryAGet16(ss, r16[bp] + 16);
    if (r16[cx])
        { pc = 0xffaf; break; }
    if (!r16[dx])
        { pc = 0x10014; break; }
    if (!r16[bx])
        { pc = 0x10014; break; }
  case 0xffaf:
    if (r16[di] & 0x0001)
        { pc = 0xffd1; break; }
    if (r16s[dx] >= 0)
        { pc = 0xffc3; break; }
    r16[dx] = -r16[dx];
    flags.carry = r16[ax] != 0;
    r16[ax] = -r16[ax];
    r16[dx] -= (0x0000 + flags.carry);
    r16[di] |= 0x000c;
  case 0xffc3:
    if (r16s[cx] >= 0)
        { pc = 0xffd1; break; }
    r16[cx] = -r16[cx];
    flags.carry = r16[bx] != 0;
    r16[bx] = -r16[bx];
    r16[cx] -= (0x0000 + flags.carry);
    r16[di] ^= 0x0004;
  case 0xffd1:
    r16[bp] = r16[cx];
    r16[cx] = 0x0020;
    push(r16[di]);
    r16[di] = 0;
    r16[si] = 0;
  case 0xffdb:
    flags.carry = !!(r16[ax] & 0x8000);
    r16[ax] <<= 1;
    r16[dx] = rcl16(r16[dx], 0x0001);
    r16[si] = rcl16(r16[si], 0x0001);
    r16[di] = rcl16(r16[di], 0x0001);
    if (r16[di] < r16[bp])
        { pc = 0xfff2; break; }
    if (r16[di] > r16[bp])
        { pc = 0xffed; break; }
    if (r16[si] < r16[bx])
        { pc = 0xfff2; break; }
  case 0xffed:
    flags.carry = r16[si] < r16[bx];
    r16[si] -= r16[bx];
    r16[di] -= (r16[bp] + flags.carry);
    r16[ax]++;
  case 0xfff2:
    if (--r16[cx])
        { pc = 0xffdb; break; }
    r16[bx] = pop();
    if (!(r16[bx] & 0x0002))
        { pc = 0x10001; break; }
    r16[ax] = r16[si];
    r16[dx] = r16[di];
    r16[bx] >>= 1;
  case 0x10001:
    if (!(r16[bx] & 0x0004))
        { pc = 0x1000e; break; }
    r16[dx] = -r16[dx];
    flags.carry = r16[ax] != 0;
    r16[ax] = -r16[ax];
    r16[dx] -= (0x0000 + flags.carry);
  case 0x1000e:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    stop("stack_below_retf, 10/6");
    sp += 2; cs = pop(); sp += 8; return;
  case 0x10014:
    div16(r16[bx]);
    if (!(r16[di] & 0x0002))
        { pc = 0x1001d; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
  case 0x1001d:
    r16[dx] = 0;
    { pc = 0x1000e; break; }
    return;
  }
}
function* sub_ff82() // 01ed:e0b2 +stackDrop10 +nearAsFar
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[cx] = pop();
    push(cs);
    push(r16[cx]);
    r16[cx] = 0x0002;
    { pc = 0xff90; break; }
    // gap 6 bytes
  case 0xff90:
    push(r16[bp]);
    push(r16[si]);
    push(r16[di]);
    r16[bp] = sp;
    r16[di] = r16[cx];
    r16[ax] = memoryAGet16(ss, r16[bp] + 10);
    r16[dx] = memoryAGet16(ss, r16[bp] + 12);
    r16[bx] = memoryAGet16(ss, r16[bp] + 14);
    r16[cx] = memoryAGet16(ss, r16[bp] + 16);
    if (r16[cx])
        { pc = 0xffaf; break; }
    if (!r16[dx])
        { pc = 0x10014; break; }
    if (!r16[bx])
        { pc = 0x10014; break; }
  case 0xffaf:
    if (r16[di] & 0x0001)
        { pc = 0xffd1; break; }
    if (r16s[dx] >= 0)
        { pc = 0xffc3; break; }
    r16[dx] = -r16[dx];
    flags.carry = r16[ax] != 0;
    r16[ax] = -r16[ax];
    r16[dx] -= (0x0000 + flags.carry);
    r16[di] |= 0x000c;
  case 0xffc3:
    if (r16s[cx] >= 0)
        { pc = 0xffd1; break; }
    r16[cx] = -r16[cx];
    flags.carry = r16[bx] != 0;
    r16[bx] = -r16[bx];
    r16[cx] -= (0x0000 + flags.carry);
    r16[di] ^= 0x0004;
  case 0xffd1:
    r16[bp] = r16[cx];
    r16[cx] = 0x0020;
    push(r16[di]);
    r16[di] = 0;
    r16[si] = 0;
  case 0xffdb:
    flags.carry = !!(r16[ax] & 0x8000);
    r16[ax] <<= 1;
    r16[dx] = rcl16(r16[dx], 0x0001);
    r16[si] = rcl16(r16[si], 0x0001);
    r16[di] = rcl16(r16[di], 0x0001);
    if (r16[di] < r16[bp])
        { pc = 0xfff2; break; }
    if (r16[di] > r16[bp])
        { pc = 0xffed; break; }
    if (r16[si] < r16[bx])
        { pc = 0xfff2; break; }
  case 0xffed:
    flags.carry = r16[si] < r16[bx];
    r16[si] -= r16[bx];
    r16[di] -= (r16[bp] + flags.carry);
    r16[ax]++;
  case 0xfff2:
    if (--r16[cx])
        { pc = 0xffdb; break; }
    r16[bx] = pop();
    if (!(r16[bx] & 0x0002))
        { pc = 0x10001; break; }
    r16[ax] = r16[si];
    r16[dx] = r16[di];
    r16[bx] >>= 1;
  case 0x10001:
    if (!(r16[bx] & 0x0004))
        { pc = 0x1000e; break; }
    r16[dx] = -r16[dx];
    flags.carry = r16[ax] != 0;
    r16[ax] = -r16[ax];
    r16[dx] -= (0x0000 + flags.carry);
  case 0x1000e:
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    stop("stack_below_retf, 10/6");
    sp += 2; cs = pop(); sp += 8; return;
  case 0x10014:
    div16(r16[bx]);
    if (!(r16[di] & 0x0002))
        { pc = 0x1001d; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
  case 0x1001d:
    r16[dx] = 0;
    { pc = 0x1000e; break; }
    return;
  }
}
function* sub_10021() // 01ed:e151 +stackDrop2 +nearAsFar
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[bx] = pop();
    push(cs);
    push(r16[bx]);
    if (r8[cl] >= 0x10)
        { pc = 0x10039; break; }
    r16[bx] = r16[ax];
    r16[ax] <<= r8[cl];
    r16[dx] <<= r8[cl];
    r8[cl] = -r8[cl];
    r8[cl] += 0x10;
    r16[bx] >>= r8[cl];
    r16[dx] |= r16[bx];
    sp += 2; cs = pop(); return;
  case 0x10039:
    r8[cl] -= 0x10;
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r16[ax] = 0;
    r16[dx] <<= r8[cl];
    sp += 2; cs = pop();
    return;
  }
}
function* sub_10042() // 01ed:e172 +stackDrop2 +nearAsFar
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[bx] = pop();
    push(cs);
    push(r16[bx]);
    if (r8[cl] >= 0x10)
        { pc = 0x1005a; break; }
    r16[bx] = r16[dx];
    r16[ax] >>= r8[cl];
    r16[dx] = sar16(r16[dx], r8[cl]);
    r8[cl] = -r8[cl];
    r8[cl] += 0x10;
    r16[bx] <<= r8[cl];
    r16[ax] |= r16[bx];
    sp += 2; cs = pop(); return;
  case 0x1005a:
    r8[cl] -= 0x10;
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r16[ax] = sar16(r16[ax], r8[cl]);
    sp += 2; cs = pop();
    return;
  }
}
function* sub_10062() // 01ed:e192 +stackDrop2 +nearAsFar
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[bx] = pop();
    push(cs);
    push(r16[bx]);
    if (r8[cl] >= 0x10)
        { pc = 0x1007a; break; }
    r16[bx] = r16[dx];
    r16[ax] >>= r8[cl];
    r16[dx] >>= r8[cl];
    r8[cl] = -r8[cl];
    r8[cl] += 0x10;
    r16[bx] <<= r8[cl];
    r16[ax] |= r16[bx];
    sp += 2; cs = pop(); return;
  case 0x1007a:
    r8[cl] -= 0x10;
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r16[dx] = 0;
    r16[ax] >>= r8[cl];
    sp += 2; cs = pop();
    return;
  }
}
function* sub_10083() // 01ed:e1b3 +stackDrop2 +nearAsFar
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    es = pop();
    push(cs);
    push(es);
    es = r16[dx];
    r16[tx] = r16[bx]; r16[bx] = r16[ax]; r16[ax] = r16[tx];
    r16[dx] = memoryAGet16(es, r16[bx] + 2);
    push(r16[bx]);
    r16[bx] = memoryAGet16(es, r16[bx]);
    if (r16s[cx] >= 0)
        { pc = 0x100a1; break; }
    r16[ax] = ~r16[ax];
    r16[cx] = ~r16[cx];
    flags.carry = r16[ax] + 0x0001 >= 0x10000;
    r16[ax]++;
    r16[cx] += (0x0000 + flags.carry);
    { pc = 0x100e5; break; }
  case 0x100a1:
    flags.carry = r16[bx] + r16[ax] >= 0x10000;
    r16[bx] += r16[ax];
    if (!flags.carry)
        { pc = 0x100a9; break; }
    r16[dx] += 0x1000;
  case 0x100a9:
    r8[ah] = r8[cl];
    r8[cl] = 0x04;
    r8[ah] <<= r8[cl];
    r8[al] = 0;
    r16[dx] += r16[ax];
    r8[ch] = r8[bl];
    r16[bx] >>= r8[cl];
    r16[dx] += r16[bx];
    r8[al] = r8[ch];
    r16[ax] &= 0x000f;
    r16[bx] = pop();
    memoryASet16(es, r16[bx], r16[ax]);
    memoryASet16(es, r16[bx] + 2, r16[dx]);
    sp += 2; cs = pop(); return;
    // gap 30 bytes
  case 0x100e5:
    flags.carry = r16[bx] < r16[ax];
    r16[bx] -= r16[ax];
    if (!flags.carry)
        { pc = 0x100ed; break; }
    r16[dx] -= 0x1000;
  case 0x100ed:
    r8[ah] = r8[cl];
    r8[cl] = 0x04;
    r8[ah] <<= r8[cl];
    r8[al] = 0;
    r16[dx] -= r16[ax];
    r8[ch] = r8[bl];
    r16[bx] >>= r8[cl];
    r16[dx] += r16[bx];
    r8[al] = r8[ch];
    r16[ax] &= 0x000f;
    r16[bx] = pop();
    memoryASet16(es, r16[bx], r16[ax]);
    memoryASet16(es, r16[bx] + 2, r16[dx]);
    sp += 2; cs = pop();
    return;
  }
}
function* sub_1010b() // 01ed:e23b +stackDrop2 +nearAsFar
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    es = pop();
    push(cs);
    push(es);
    if (r16s[cx] >= 0)
        { pc = 0x1011e; break; }
    r16[bx] = ~r16[bx];
    r16[cx] = ~r16[cx];
    flags.carry = r16[bx] + 0x0001 >= 0x10000;
    r16[bx]++;
    r16[cx] += (0x0000 + flags.carry);
    { pc = 0x1014d; break; }
  case 0x1011e:
    flags.carry = r16[ax] + r16[bx] >= 0x10000;
    r16[ax] += r16[bx];
    if (!flags.carry)
        { pc = 0x10126; break; }
    r16[dx] += 0x1000;
  case 0x10126:
    r8[ch] = r8[cl];
    r8[cl] = 0x04;
    r8[ch] <<= r8[cl];
    r8[dh] += r8[ch];
    r8[ch] = r8[al];
    r16[ax] >>= r8[cl];
    r16[dx] += r16[ax];
    r8[al] = r8[ch];
    r16[ax] &= 0x000f;
    sp += 2; cs = pop(); return;
    // gap 19 bytes
  case 0x1014d:
    flags.carry = r16[ax] < r16[bx];
    r16[ax] -= r16[bx];
    if (!flags.carry)
        { pc = 0x10155; break; }
    r16[dx] -= 0x1000;
  case 0x10155:
    r8[bh] = r8[cl];
    r8[cl] = 0x04;
    r8[bh] <<= r8[cl];
    r8[bl] = 0;
    r16[dx] -= r16[bx];
    r8[ch] = r8[al];
    r16[ax] >>= r8[cl];
    r16[dx] += r16[ax];
    r8[al] = r8[ch];
    r16[ax] &= 0x000f;
    sp += 2; cs = pop();
    return;
  }
}
function* sub_1016b() // 01ed:e29b +stackDrop10 +nearAsFar
{
    sp -= 2;
    es = pop();
    push(cs);
    push(es);
    push(r16[bp]);
    r16[bp] = sp;
    push(r16[si]);
    push(r16[di]);
    push(ds);
    r16[si] = memoryAGet16(ss, r16[bp] + 6); ds = memoryAGet16(ss, r16[bp] + 8);
    r16[di] = memoryAGet16(ss, r16[bp] + 10); es = memoryAGet16(ss, r16[bp] + 12);
    flags.direction = 0;
    flags.carry = r16[cx] & 1;
    r16[cx] >>= 1;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[cx] += (r16[cx] + flags.carry);
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    ds = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[bp] = pop();
    stop("stack_below_retf, 10/6");
    sp += 2; cs = pop(); sp += 8;
}
function* sub_1018a() // 01ed:e2ba +stackDrop2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[bx] = pop();
    stop("stack_below");
    sp -= r16[cx];
    push(cs);
    { pc = 0x10195; break; }
    // gap 5 bytes
  case 0x10195:
    push(r16[bx]);
    push(r16[di]);
    push(ds);
    r16[di] = sp;
    r16[di] += 0x0008;
    r16[bx] = ss;
    es = r16[bx];
    ds = r16[dx];
    r16[tx] = r16[si]; r16[si] = r16[ax]; r16[ax] = r16[tx];
    flags.direction = 0;
    flags.carry = r16[cx] & 1;
    r16[cx] >>= 1;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[cx] += (r16[cx] + flags.carry);
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[tx] = r16[si]; r16[si] = r16[ax]; r16[ax] = r16[tx];
    ds = pop();
    r16[di] = pop();
    stop("stack_unbalanced");
    sp += 2; cs = pop();
    return;
  }
}
function* sub_101c0() // 01ed:e2f0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[si]);
    push(r16[di]);
    r16[si] = sp;
    r16[bx] = memoryAGet16(ds, r16[si] + 6);
    flags.carry = r16[bx] < 0x0004;
    r16[bx] -= 0x0004;
    if (flags.carry)
        { pc = 0x101da; break; }
    if (r16[bx] == memoryAGet16(ds, 0x562c))
        { pc = 0x101d7; break; }
    yield* sub_10217();
    { pc = 0x101da; break; }
  case 0x101d7:
    yield* sub_101dd();
  case 0x101da:
    r16[di] = pop();
    r16[si] = pop();
    sp += 2;
    return;
  }
}
function* sub_101dd() // 01ed:e30d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (memoryAGet16(ds, 0x562a) == r16[bx])
        { pc = 0x10206; break; }
    r16[si] = memoryAGet16(ds, r16[bx] + 2);
    if (!(memoryAGet(ds, r16[si]) & 0x01))
        { pc = 0x101f1; break; }
    memoryASet16(ds, 0x562c, r16[si]);
    { pc = 0x10211; break; }
  case 0x101f1:
    if (r16[si] == memoryAGet16(ds, 0x562a))
        { pc = 0x10204; break; }
    r16[bx] = r16[si];
    yield* sub_10250();
    r16[ax] = memoryAGet16(ds, r16[bx] + 2);
    memoryASet16(ds, 0x562c, r16[ax]);
    { pc = 0x10211; break; }
  case 0x10204:
    r16[bx] = r16[si];
  case 0x10206:
    r16[ax] = 0;
    memoryASet16(ds, 0x562a, r16[ax]);
    memoryASet16(ds, 0x562c, r16[ax]);
    memoryASet16(ds, 0x562e, r16[ax]);
  case 0x10211:
    push(r16[bx]);
    yield* sub_edce();
    r16[bx] = pop();
    sp += 2;
    return;
  }
}
function* sub_10217() // 01ed:e347
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    memoryASet16(ds, r16[bx], memoryAGet16(ds, r16[bx]) - 1);
    if (r16[bx] == memoryAGet16(ds, 0x562a))
        { pc = 0x10237; break; }
    r16[si] = memoryAGet16(ds, r16[bx] + 2);
    r16[ax] = memoryAGet16(ds, r16[si]);
    if (r8[al] & 0x01)
        { pc = 0x10237; break; }
    r16[ax] += memoryAGet16(ds, r16[bx]);
    memoryASet16(ds, r16[si], r16[ax]);
    r16[di] = memoryAGet16(ds, r16[bx]);
    r16[di] += r16[bx];
    memoryASet16(ds, r16[di] + 2, r16[si]);
    r16[bx] = r16[si];
    { pc = 0x1023a; break; }
  case 0x10237:
    yield* sub_1026c();
  case 0x1023a:
    r16[di] = memoryAGet16(ds, r16[bx]);
    r16[di] += r16[bx];
    r16[ax] = memoryAGet16(ds, r16[di]);
    if (!(r8[al] & 0x01))
        { pc = 0x10245; break; }
    sp += 2; return;
  case 0x10245:
    memoryASet16(ds, r16[bx], memoryAGet16(ds, r16[bx]) + r16[ax]);
    r16[si] = r16[di];
    r16[si] += r16[ax];
    memoryASet16(ds, r16[si] + 2, r16[bx]);
    r16[bx] = r16[di];
    r16[di] = memoryAGet16(ds, r16[bx] + 6);
    if (r16[bx] == r16[di])
        { pc = 0x10265; break; }
    memoryASet16(ds, 0x562e, r16[di]);
    r16[si] = memoryAGet16(ds, r16[bx] + 4);
    memoryASet16(ds, r16[di] + 4, r16[si]);
    memoryASet16(ds, r16[si] + 6, r16[di]);
    sp += 2; return;
  case 0x10265:
    memoryASet16(ds, 0x562e, 0x0000);
    sp += 2;
    return;
  }
}
function* sub_10250() // 01ed:e380
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[di] = memoryAGet16(ds, r16[bx] + 6);
    if (r16[bx] == r16[di])
        { pc = 0x10265; break; }
    memoryASet16(ds, 0x562e, r16[di]);
    r16[si] = memoryAGet16(ds, r16[bx] + 4);
    memoryASet16(ds, r16[di] + 4, r16[si]);
    memoryASet16(ds, r16[si] + 6, r16[di]);
    sp += 2; return;
  case 0x10265:
    memoryASet16(ds, 0x562e, 0x0000);
    sp += 2;
    return;
  }
}
function* sub_1026c() // 01ed:e39c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[si] = memoryAGet16(ds, 0x562e);
    if (!r16[si])
        { pc = 0x10284; break; }
    r16[di] = memoryAGet16(ds, r16[si] + 6);
    memoryASet16(ds, r16[si] + 6, r16[bx]);
    memoryASet16(ds, r16[di] + 4, r16[bx]);
    memoryASet16(ds, r16[bx] + 6, r16[di]);
    memoryASet16(ds, r16[bx] + 4, r16[si]);
    sp += 2; return;
  case 0x10284:
    memoryASet16(ds, 0x562e, r16[bx]);
    memoryASet16(ds, r16[bx] + 4, r16[bx]);
    memoryASet16(ds, r16[bx] + 6, r16[bx]);
    sp += 2;
    return;
  }
}
function* sub_1028f() // 01ed:e3bf
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[si]);
    push(r16[di]);
    r16[si] = sp;
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    if (!r16[ax])
        { pc = 0x102ec; break; }
    flags.carry = r16[ax] + 0x0005 >= 0x10000;
    r16[ax] += 0x0005;
    if (flags.carry)
        { pc = 0x102d5; break; }
    r16[ax] &= 0xfffe;
    if (r16[ax] >= 0x0008)
        { pc = 0x102aa; break; }
    r16[ax] = 0x0008;
  case 0x102aa:
    if (!memoryAGet16(ds, 0x562a))
        { pc = 0x102d0; break; }
    r16[bx] = memoryAGet16(ds, 0x562e);
    if (!r16[bx])
        { pc = 0x102c6; break; }
    r16[dx] = r16[bx];
  case 0x102bb:
    if (memoryAGet16(ds, r16[bx]) >= r16[ax])
        { pc = 0x102d9; break; }
    r16[bx] = memoryAGet16(ds, r16[bx] + 6);
    if (r16[bx] != r16[dx])
        { pc = 0x102bb; break; }
  case 0x102c6:
    yield* sub_1032f();
    { pc = 0x102ec; break; }
  case 0x102cb:
    yield* sub_10358();
    { pc = 0x102ec; break; }
  case 0x102d0:
    yield* sub_102ef();
    { pc = 0x102ec; break; }
  case 0x102d5:
    r16[ax] = 0;
    { pc = 0x102ec; break; }
  case 0x102d9:
    r16[si] = r16[ax];
    r16[si] += 0x0008;
    if (memoryAGet16(ds, r16[bx]) >= r16[si])
        { pc = 0x102cb; break; }
    yield* sub_10250();
    memoryASet16(ds, r16[bx], memoryAGet16(ds, r16[bx]) + 1);
    r16[ax] = r16[bx];
    r16[ax] += 0x0004;
  case 0x102ec:
    r16[di] = pop();
    r16[si] = pop();
    sp += 2;
    return;
  }
}
function* sub_102ef() // 01ed:e41f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[ax]);
    r16[ax] = 0;
    push(r16[ax]);
    push(r16[ax]);
    yield* sub_edf0();
    r16[bx] = pop();
    r16[bx] = pop();
    r16[ax] &= 0x0001;
    if (!r16[ax])
        { pc = 0x10307; break; }
    r16[dx] = 0;
    push(r16[dx]);
    push(r16[ax]);
    yield* sub_edf0();
    r16[bx] = pop();
    r16[bx] = pop();
  case 0x10307:
    r16[ax] = pop();
    push(r16[ax]);
    r16[bx] = 0;
    push(r16[bx]);
    push(r16[ax]);
    yield* sub_edf0();
    r16[bx] = pop();
    r16[bx] = pop();
    if (r16[ax] == 0xffff)
        { pc = 0x1032b; break; }
    r16[bx] = r16[ax];
    memoryASet16(ds, 0x562a, r16[bx]);
    memoryASet16(ds, 0x562c, r16[bx]);
    r16[ax] = pop();
    r16[ax]++;
    memoryASet16(ds, r16[bx], r16[ax]);
    r16[bx] += 0x0004;
    r16[ax] = r16[bx];
    sp += 2; return;
  case 0x1032b:
    r16[bx] = pop();
    r16[ax] = 0;
    sp += 2;
    return;
  }
}
function* sub_1032f() // 01ed:e45f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[ax]);
    r16[bx] = 0;
    push(r16[bx]);
    push(r16[ax]);
    yield* sub_edf0();
    r16[bx] = pop();
    r16[bx] = pop();
    if (r16[ax] == 0xffff)
        { pc = 0x10354; break; }
    r16[bx] = r16[ax];
    r16[ax] = memoryAGet16(ds, 0x562c);
    memoryASet16(ds, r16[bx] + 2, r16[ax]);
    memoryASet16(ds, 0x562c, r16[bx]);
    r16[ax] = pop();
    r16[ax]++;
    memoryASet16(ds, r16[bx], r16[ax]);
    r16[bx] += 0x0004;
    r16[ax] = r16[bx];
    sp += 2; return;
  case 0x10354:
    r16[ax] = pop();
    r16[ax] = 0;
    sp += 2;
    return;
  }
}
function* sub_10358() // 01ed:e488
{
    sp -= 2;
    memoryASet16(ds, r16[bx], memoryAGet16(ds, r16[bx]) - r16[ax]);
    r16[si] = r16[bx];
    r16[si] += memoryAGet16(ds, r16[bx]);
    r16[di] = r16[si];
    r16[di] += r16[ax];
    r16[ax]++;
    memoryASet16(ds, r16[si], r16[ax]);
    memoryASet16(ds, r16[si] + 2, r16[bx]);
    memoryASet16(ds, r16[di] + 2, r16[si]);
    r16[si] += 0x0004;
    r16[ax] = r16[si];
    sp += 2;
}
function* sub_10433() // 01ed:e563
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[si]);
    r16[tx] = r16[si]; r16[si] = r16[ax]; r16[ax] = r16[tx];
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    if (!r16[ax])
        { pc = 0x1043c; break; }
    mul16(r16[bx]);
  case 0x1043c:
    if (!r16[cx])
        { pc = 0x10443; break; }
    r16[tx] = r16[cx]; r16[cx] = r16[ax]; r16[ax] = r16[tx];
    mul16(r16[si]);
    r16[ax] += r16[cx];
  case 0x10443:
    r16[tx] = r16[si]; r16[si] = r16[ax]; r16[ax] = r16[tx];
    mul16(r16[bx]);
    r16[dx] += r16[si];
    r16[si] = pop();
    sp += 2;
    return;
  }
}
function* sub_1044a() // 01ed:e57a +returnCarry +returnZero
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[cx]);
    r8[ch] = r8[al];
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[dx] += r16[ax];
    r8[al] = r8[ch];
    r8[ah] = r8[bl];
    r16[bx] >>= r8[cl];
    r16[cx] = pop();
    r16[cx] += r16[bx];
    r8[bl] = r8[ah];
    r16[ax] &= 0x000f;
    r16[bx] &= 0x000f;
    flags.carry = r16[dx] < r16[cx];
    flags.zero = r16[dx] == r16[cx];
    if (!flags.zero)
        { pc = 0x1046a; break; }
    flags.carry = r16[ax] < r16[bx];
    flags.zero = r16[ax] == r16[bx];
  case 0x1046a:
    sp += 2; return;
    return;
  }
}
function* sub_10471() // 01ed:e5a1
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    { pc = 0x10471; break; }
  case 0x20f0:
    r16[cx] = 0x001e;
    stop("stack_below");
    r16[dx] = 0x0054;
    ds = memoryAGet16(cs, 0x0235);
    yield* sub_20e8();
    r16[ax] = 0x0003;
    push(r16[ax]);
    yield* sub_1ffe();
    memoryASet(ds, r16[bx] + r16[si], memoryAGet(ds, r16[bx] + r16[si]) + r8[al]);
    memoryASet16(ds, r16[bx] + r16[si], memoryAGet16(ds, r16[bx] + r16[si]) + r16[ax]);
    push(r16[bp]);
    r16[bp] = sp;
    r16[ax] = 0;
    memoryASet16(ds, 0x6ed8, r16[ax]);
    memoryASet16(ds, 0x6ecc, r16[ax]);
    memoryASet16(ds, 0x6ebe, r16[ax]);
    memoryASet16(ds, 0x6ec6, 0x604e);
    memoryASet16(ds, 0x6ece, 0x6c0a);
    memoryASet16(ds, 0x7fba, 0x6c64);
    memoryASet16(ds, 0x5db6, 0x5660);
  case 0x212f:
    memoryASet16(ds, 0x5135, memoryAGet16(ds, 0x5135)+1);
    r16[ax] = memoryAGet16(ds, 0x5135);
    r16[ax] -= memoryAGet16(ds, 0x563e);
    memoryASet16(ds, 0x5b14, r16[ax]);
    if (r16[ax] < 0x0006)
        { pc = 0x212f; break; }
    if (r16[ax] <= 0x000f)
        { pc = 0x2149; break; }
    memoryASet16(ds, 0x5b14, 0x000f);
  case 0x2149:
    r16[ax] = memoryAGet16(ds, 0x5137);
    r16[dx] = memoryAGet16(ds, 0x5135);
    memoryASet16(ds, 0x563e, r16[dx]);
    memoryASet16(ds, 0x5640, r16[ax]);
    r16[bp] = pop();
    stop("stack_unbalanced");
    sp += 2; return;
    // gap 58136 bytes
  case 0x10471:
    memoryASet16(ds, 0x5634, pop());
    stop("stack_below");
    memoryASet16(ds, 0x5636, pop());
    memoryASet16(ds, 0x5638, pop());
    memoryASet16(cs, 0xe59f, ds);
    memoryASet16(ds, 0x563a, r16[si]);
    memoryASet16(ds, 0x563c, r16[di]);
    flags.direction = 0;
    es = memoryAGet16(ds, 0x008e);
    r16[si] = 0x0080;
    r8[ah] = 0;
    r8[al] = lodsb_ESSI();
    r16[ax]++;
    r16[bp] = es;
    r16[tx] = r16[si]; r16[si] = r16[dx]; r16[dx] = r16[tx];
    r16[tx] = r16[bx]; r16[bx] = r16[ax]; r16[ax] = r16[tx];
    r16[si] = memoryAGet16(ds, 0x0088);
    r16[si]++;
    r16[si]++;
    r16[cx] = 0x0001;
    if (memoryAGet(ds, 0x0090) < 0x03)
        { pc = 0x104bd; break; }
    es = memoryAGet16(ds, 0x008a);
    r16[di] = r16[si];
    r8[cl] = 0x7f;
    r8[al] = 0;
    for (flags.zero = 0; r16[cx] != 0 && !flags.zero; --r16[cx]) scasb_inv_ESDI(r8[al]);
    if (!r16[cx])
        { pc = 0x10528; break; }
    r8[cl] ^= 0x7f;
  case 0x104bd:
    push(r16[ax]);
    r16[ax] = r16[cx];
    r16[ax] += r16[bx];
    r16[ax]++;
    r16[ax] &= 0xfffe;
    r16[di] = sp;
    flags.carry = r16[di] < r16[ax];
    r16[di] -= r16[ax];
    if (flags.carry)
        { pc = 0x10528; break; }
    sp = r16[di];
    push(es);
    ds = pop();
    push(ss);
    es = pop();
    push(r16[cx]);
    r16[cx]--;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r8[al] = 0;
    stosb_ESDI(r8[al]);
    ds = r16[bp];
    r16[tx] = r16[dx]; r16[dx] = r16[si]; r16[si] = r16[tx];
    r16[tx] = r16[cx]; r16[cx] = r16[bx]; r16[bx] = r16[tx];
    r16[ax] = r16[bx];
    r16[dx] = r16[ax];
    r16[bx]++;
  case 0x104e4:
    yield* sub_10500();
    if (!flags.carry && !flags.zero)
        { pc = 0x104f0; break; }
  case 0x104e9:
    if (flags.carry)
        { pc = 0x1052b; break; }
    yield* sub_10500();
    if (!flags.carry && !flags.zero)
        { pc = 0x104e9; break; }
  case 0x104f0:
    if (r8[al] == 0x20)
        { pc = 0x104fc; break; }
    if (r8[al] == 0x0d)
        { pc = 0x104fc; break; }
    if (r8[al] != 0x09)
        { pc = 0x104e4; break; }
  case 0x104fc:
    r8[al] = 0;
    { pc = 0x104e4; break; }
    // gap 40 bytes
  case 0x10528:
    { pc = 0x20f0; break; }
    stop("stack_below");
  case 0x1052b:
    r16[cx] = pop();
    r16[cx] += r16[dx];
    ds = memoryAGet16(cs, 0xe59f);
    memoryASet16(ds, 0x5630, r16[bx]);
    r16[bx]++;
    r16[bx] += r16[bx];
    r16[si] = sp;
    r16[bp] = sp;
    flags.carry = r16[bp] < r16[bx];
    r16[bp] -= r16[bx];
    if (flags.carry)
        { pc = 0x10528; break; }
    sp = r16[bp];
    memoryASet16(ds, 0x5632, r16[bp]);
  case 0x10548:
    if (!r16[cx])
        { pc = 0x10558; break; }
    memoryASet16(ss, r16[bp], r16[si]);
    r16[bp] += 0x0002;
  case 0x10550:
    r8[al] = lodsb_SSSI();
    if (--r16[cx] && !r8[al])
        { pc = 0x10550; break; }
    if (!r8[al])
        { pc = 0x10548; break; }
  case 0x10558:
    r16[ax] = 0;
    memoryASet16(ss, r16[bp], r16[ax]);
    ds = memoryAGet16(cs, 0xe59f);
    r16[si] = memoryAGet16(ds, 0x563a);
    r16[di] = memoryAGet16(ds, 0x563c);
    push(memoryAGet16(ds, 0x5638));
    push(memoryAGet16(ds, 0x5636));
    r16[ax] = memoryAGet16(ds, 0x5630);
    memoryASet16(ds, 0x0082, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5632);
    memoryASet16(ds, 0x0084, r16[ax]);
    return;
  }
}
function* sub_10500() // 01ed:e630 +returnCarry +returnZero
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    if (!r16[ax])
        { pc = 0x1050b; break; }
    r16[dx]++;
    stosb_ESDI(r8[al]);
    if (r8[al])
        { pc = 0x1050b; break; }
    r16[bx]++;
  case 0x1050b:
    r8[tl] = r8[al]; r8[al] = r8[ah]; r8[ah] = r8[tl];
    flags.zero = r8[al] == 0;
    r8[al] = 0;
    flags.carry = 1;
    if (!r16[cx])
        { pc = 0x10527; break; }
    r8[al] = lodsb_DSSI();
    r16[cx]--;
    flags.carry = r8[al] < 0x22;
    flags.zero = r8[al] == 0;
    r8[al] -= 0x22;
    if (flags.zero)
        { pc = 0x10527; break; }
    r8[al] += 0x22;
    if (r8[al] != 0x5c)
        { pc = 0x10525; break; }
    if (memoryAGet(ds, r16[si]) != 0x22)
        { pc = 0x10525; break; }
    r8[al] = lodsb_DSSI();
    r16[cx]--;
  case 0x10525:
    flags.carry = false;
    flags.zero = r16[si] == 0;
  case 0x10527:
    sp += 2; return;
    return;
  }
}
function* sub_10590() // 1059:0000
{
    sp -= 2;
    es = memoryAGet16(ds, 0x35b2);
    ds = memoryAGet16(ds, 0x836a);
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[dx];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[ax] = ss;
    ds = r16[ax];
    es = r16[cx];
    sp += 2;
}
function* sub_105dd() // 1059:004d +far +stackDrop2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[dx] = 0x002e;
    r16[cx] = es;
    r16[si] = memoryAGet16(es, r16[bx]);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b16))
        { pc = 0x105f9; break; }
    memoryASet16(ds, 0x5b16, r16[si]);
    r16[di] = 0x0604;
    yield* sub_10590();
  case 0x105f9:
    r16[si] = memoryAGet16(es, r16[bx] + 2);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b18))
        { pc = 0x10611; break; }
    memoryASet16(ds, 0x5b18, r16[si]);
    r16[di] = 0x0606;
    yield* sub_10590();
  case 0x10611:
    r16[si] = memoryAGet16(es, r16[bx] + 4);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b1a))
        { pc = 0x10629; break; }
    memoryASet16(ds, 0x5b1a, r16[si]);
    r16[di] = 0x0608;
    yield* sub_10590();
  case 0x10629:
    r16[si] = memoryAGet16(es, r16[bx] + 6);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b1c))
        { pc = 0x10641; break; }
    memoryASet16(ds, 0x5b1c, r16[si]);
    r16[di] = 0x060a;
    yield* sub_10590();
  case 0x10641:
    r16[si] = memoryAGet16(es, r16[bx] + 8);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b1e))
        { pc = 0x10659; break; }
    memoryASet16(ds, 0x5b1e, r16[si]);
    r16[di] = 0x060c;
    yield* sub_10590();
  case 0x10659:
    r16[si] = memoryAGet16(es, r16[bx] + 10);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b20))
        { pc = 0x10671; break; }
    memoryASet16(ds, 0x5b20, r16[si]);
    r16[di] = 0x060e;
    yield* sub_10590();
  case 0x10671:
    r16[si] = memoryAGet16(es, r16[bx] + 12);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b22))
        { pc = 0x10689; break; }
    memoryASet16(ds, 0x5b22, r16[si]);
    r16[di] = 0x0610;
    yield* sub_10590();
  case 0x10689:
    r16[si] = memoryAGet16(es, r16[bx] + 14);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b24))
        { pc = 0x106a1; break; }
    memoryASet16(ds, 0x5b24, r16[si]);
    r16[di] = 0x0612;
    yield* sub_10590();
  case 0x106a1:
    r16[si] = memoryAGet16(es, r16[bx] + 16);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b26))
        { pc = 0x106b9; break; }
    memoryASet16(ds, 0x5b26, r16[si]);
    r16[di] = 0x0614;
    yield* sub_10590();
  case 0x106b9:
    r16[si] = memoryAGet16(es, r16[bx] + 18);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b28))
        { pc = 0x106d1; break; }
    memoryASet16(ds, 0x5b28, r16[si]);
    r16[di] = 0x0616;
    yield* sub_10590();
  case 0x106d1:
    r16[si] = memoryAGet16(es, r16[bx] + 20);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b2a))
        { pc = 0x106e9; break; }
    memoryASet16(ds, 0x5b2a, r16[si]);
    r16[di] = 0x0618;
    yield* sub_10590();
  case 0x106e9:
    r16[si] = memoryAGet16(es, r16[bx] + 22);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b2c))
        { pc = 0x10701; break; }
    memoryASet16(ds, 0x5b2c, r16[si]);
    r16[di] = 0x061a;
    yield* sub_10590();
  case 0x10701:
    r16[si] = memoryAGet16(es, r16[bx] + 24);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b2e))
        { pc = 0x10719; break; }
    memoryASet16(ds, 0x5b2e, r16[si]);
    r16[di] = 0x061c;
    yield* sub_10590();
  case 0x10719:
    r16[si] = memoryAGet16(es, r16[bx] + 26);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b30))
        { pc = 0x10731; break; }
    memoryASet16(ds, 0x5b30, r16[si]);
    r16[di] = 0x061e;
    yield* sub_10590();
  case 0x10731:
    r16[si] = memoryAGet16(es, r16[bx] + 28);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b32))
        { pc = 0x10749; break; }
    memoryASet16(ds, 0x5b32, r16[si]);
    r16[di] = 0x0620;
    yield* sub_10590();
  case 0x10749:
    r16[si] = memoryAGet16(es, r16[bx] + 30);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b34))
        { pc = 0x10761; break; }
    memoryASet16(ds, 0x5b34, r16[si]);
    r16[di] = 0x0622;
    yield* sub_10590();
  case 0x10761:
    r16[si] = memoryAGet16(es, r16[bx] + 32);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b36))
        { pc = 0x10779; break; }
    memoryASet16(ds, 0x5b36, r16[si]);
    r16[di] = 0x0624;
    yield* sub_10590();
  case 0x10779:
    r16[si] = memoryAGet16(es, r16[bx] + 34);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b38))
        { pc = 0x10791; break; }
    memoryASet16(ds, 0x5b38, r16[si]);
    r16[di] = 0x0626;
    yield* sub_10590();
  case 0x10791:
    r16[si] = memoryAGet16(es, r16[bx] + 36);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b3a))
        { pc = 0x107a9; break; }
    memoryASet16(ds, 0x5b3a, r16[si]);
    r16[di] = 0x0628;
    yield* sub_10590();
  case 0x107a9:
    r16[si] = memoryAGet16(es, r16[bx] + 38);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b3c))
        { pc = 0x107c1; break; }
    memoryASet16(ds, 0x5b3c, r16[si]);
    r16[di] = 0x062a;
    yield* sub_10590();
  case 0x107c1:
    r16[si] = memoryAGet16(es, r16[bx] + 40);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b3e))
        { pc = 0x107d9; break; }
    memoryASet16(ds, 0x5b3e, r16[si]);
    r16[di] = 0x062c;
    yield* sub_10590();
  case 0x107d9:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 42);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b40))
        { pc = 0x107f5; break; }
    memoryASet16(ds, 0x5b40, r16[si]);
    r16[di] = 0x0904;
    yield* sub_10590();
  case 0x107f5:
    r16[si] = memoryAGet16(es, r16[bx] + 44);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b42))
        { pc = 0x1080d; break; }
    memoryASet16(ds, 0x5b42, r16[si]);
    r16[di] = 0x0906;
    yield* sub_10590();
  case 0x1080d:
    r16[si] = memoryAGet16(es, r16[bx] + 46);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b44))
        { pc = 0x10825; break; }
    memoryASet16(ds, 0x5b44, r16[si]);
    r16[di] = 0x0908;
    yield* sub_10590();
  case 0x10825:
    r16[si] = memoryAGet16(es, r16[bx] + 48);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b46))
        { pc = 0x1083d; break; }
    memoryASet16(ds, 0x5b46, r16[si]);
    r16[di] = 0x090a;
    yield* sub_10590();
  case 0x1083d:
    r16[si] = memoryAGet16(es, r16[bx] + 50);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b48))
        { pc = 0x10855; break; }
    memoryASet16(ds, 0x5b48, r16[si]);
    r16[di] = 0x090c;
    yield* sub_10590();
  case 0x10855:
    r16[si] = memoryAGet16(es, r16[bx] + 52);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b4a))
        { pc = 0x1086d; break; }
    memoryASet16(ds, 0x5b4a, r16[si]);
    r16[di] = 0x090e;
    yield* sub_10590();
  case 0x1086d:
    r16[si] = memoryAGet16(es, r16[bx] + 54);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b4c))
        { pc = 0x10885; break; }
    memoryASet16(ds, 0x5b4c, r16[si]);
    r16[di] = 0x0910;
    yield* sub_10590();
  case 0x10885:
    r16[si] = memoryAGet16(es, r16[bx] + 56);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b4e))
        { pc = 0x1089d; break; }
    memoryASet16(ds, 0x5b4e, r16[si]);
    r16[di] = 0x0912;
    yield* sub_10590();
  case 0x1089d:
    r16[si] = memoryAGet16(es, r16[bx] + 58);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b50))
        { pc = 0x108b5; break; }
    memoryASet16(ds, 0x5b50, r16[si]);
    r16[di] = 0x0914;
    yield* sub_10590();
  case 0x108b5:
    r16[si] = memoryAGet16(es, r16[bx] + 60);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b52))
        { pc = 0x108cd; break; }
    memoryASet16(ds, 0x5b52, r16[si]);
    r16[di] = 0x0916;
    yield* sub_10590();
  case 0x108cd:
    r16[si] = memoryAGet16(es, r16[bx] + 62);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b54))
        { pc = 0x108e5; break; }
    memoryASet16(ds, 0x5b54, r16[si]);
    r16[di] = 0x0918;
    yield* sub_10590();
  case 0x108e5:
    r16[si] = memoryAGet16(es, r16[bx] + 64);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b56))
        { pc = 0x108fd; break; }
    memoryASet16(ds, 0x5b56, r16[si]);
    r16[di] = 0x091a;
    yield* sub_10590();
  case 0x108fd:
    r16[si] = memoryAGet16(es, r16[bx] + 66);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b58))
        { pc = 0x10915; break; }
    memoryASet16(ds, 0x5b58, r16[si]);
    r16[di] = 0x091c;
    yield* sub_10590();
  case 0x10915:
    r16[si] = memoryAGet16(es, r16[bx] + 68);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b5a))
        { pc = 0x1092d; break; }
    memoryASet16(ds, 0x5b5a, r16[si]);
    r16[di] = 0x091e;
    yield* sub_10590();
  case 0x1092d:
    r16[si] = memoryAGet16(es, r16[bx] + 70);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b5c))
        { pc = 0x10945; break; }
    memoryASet16(ds, 0x5b5c, r16[si]);
    r16[di] = 0x0920;
    yield* sub_10590();
  case 0x10945:
    r16[si] = memoryAGet16(es, r16[bx] + 72);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b5e))
        { pc = 0x1095d; break; }
    memoryASet16(ds, 0x5b5e, r16[si]);
    r16[di] = 0x0922;
    yield* sub_10590();
  case 0x1095d:
    r16[si] = memoryAGet16(es, r16[bx] + 74);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b60))
        { pc = 0x10975; break; }
    memoryASet16(ds, 0x5b60, r16[si]);
    r16[di] = 0x0924;
    yield* sub_10590();
  case 0x10975:
    r16[si] = memoryAGet16(es, r16[bx] + 76);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b62))
        { pc = 0x1098d; break; }
    memoryASet16(ds, 0x5b62, r16[si]);
    r16[di] = 0x0926;
    yield* sub_10590();
  case 0x1098d:
    r16[si] = memoryAGet16(es, r16[bx] + 78);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b64))
        { pc = 0x109a5; break; }
    memoryASet16(ds, 0x5b64, r16[si]);
    r16[di] = 0x0928;
    yield* sub_10590();
  case 0x109a5:
    r16[si] = memoryAGet16(es, r16[bx] + 80);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b66))
        { pc = 0x109bd; break; }
    memoryASet16(ds, 0x5b66, r16[si]);
    r16[di] = 0x092a;
    yield* sub_10590();
  case 0x109bd:
    r16[si] = memoryAGet16(es, r16[bx] + 82);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b68))
        { pc = 0x109d5; break; }
    memoryASet16(ds, 0x5b68, r16[si]);
    r16[di] = 0x092c;
    yield* sub_10590();
  case 0x109d5:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 84);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b6a))
        { pc = 0x109f1; break; }
    memoryASet16(ds, 0x5b6a, r16[si]);
    r16[di] = 0x0c04;
    yield* sub_10590();
  case 0x109f1:
    r16[si] = memoryAGet16(es, r16[bx] + 86);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b6c))
        { pc = 0x10a09; break; }
    memoryASet16(ds, 0x5b6c, r16[si]);
    r16[di] = 0x0c06;
    yield* sub_10590();
  case 0x10a09:
    r16[si] = memoryAGet16(es, r16[bx] + 88);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b6e))
        { pc = 0x10a21; break; }
    memoryASet16(ds, 0x5b6e, r16[si]);
    r16[di] = 0x0c08;
    yield* sub_10590();
  case 0x10a21:
    r16[si] = memoryAGet16(es, r16[bx] + 90);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b70))
        { pc = 0x10a39; break; }
    memoryASet16(ds, 0x5b70, r16[si]);
    r16[di] = 0x0c0a;
    yield* sub_10590();
  case 0x10a39:
    r16[si] = memoryAGet16(es, r16[bx] + 92);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b72))
        { pc = 0x10a51; break; }
    memoryASet16(ds, 0x5b72, r16[si]);
    r16[di] = 0x0c0c;
    yield* sub_10590();
  case 0x10a51:
    r16[si] = memoryAGet16(es, r16[bx] + 94);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b74))
        { pc = 0x10a69; break; }
    memoryASet16(ds, 0x5b74, r16[si]);
    r16[di] = 0x0c0e;
    yield* sub_10590();
  case 0x10a69:
    r16[si] = memoryAGet16(es, r16[bx] + 96);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b76))
        { pc = 0x10a81; break; }
    memoryASet16(ds, 0x5b76, r16[si]);
    r16[di] = 0x0c10;
    yield* sub_10590();
  case 0x10a81:
    r16[si] = memoryAGet16(es, r16[bx] + 98);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b78))
        { pc = 0x10a99; break; }
    memoryASet16(ds, 0x5b78, r16[si]);
    r16[di] = 0x0c12;
    yield* sub_10590();
  case 0x10a99:
    r16[si] = memoryAGet16(es, r16[bx] + 100);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b7a))
        { pc = 0x10ab1; break; }
    memoryASet16(ds, 0x5b7a, r16[si]);
    r16[di] = 0x0c14;
    yield* sub_10590();
  case 0x10ab1:
    r16[si] = memoryAGet16(es, r16[bx] + 102);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b7c))
        { pc = 0x10ac9; break; }
    memoryASet16(ds, 0x5b7c, r16[si]);
    r16[di] = 0x0c16;
    yield* sub_10590();
  case 0x10ac9:
    r16[si] = memoryAGet16(es, r16[bx] + 104);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b7e))
        { pc = 0x10ae1; break; }
    memoryASet16(ds, 0x5b7e, r16[si]);
    r16[di] = 0x0c18;
    yield* sub_10590();
  case 0x10ae1:
    r16[si] = memoryAGet16(es, r16[bx] + 106);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b80))
        { pc = 0x10af9; break; }
    memoryASet16(ds, 0x5b80, r16[si]);
    r16[di] = 0x0c1a;
    yield* sub_10590();
  case 0x10af9:
    r16[si] = memoryAGet16(es, r16[bx] + 108);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b82))
        { pc = 0x10b11; break; }
    memoryASet16(ds, 0x5b82, r16[si]);
    r16[di] = 0x0c1c;
    yield* sub_10590();
  case 0x10b11:
    r16[si] = memoryAGet16(es, r16[bx] + 110);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b84))
        { pc = 0x10b29; break; }
    memoryASet16(ds, 0x5b84, r16[si]);
    r16[di] = 0x0c1e;
    yield* sub_10590();
  case 0x10b29:
    r16[si] = memoryAGet16(es, r16[bx] + 112);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b86))
        { pc = 0x10b41; break; }
    memoryASet16(ds, 0x5b86, r16[si]);
    r16[di] = 0x0c20;
    yield* sub_10590();
  case 0x10b41:
    r16[si] = memoryAGet16(es, r16[bx] + 114);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b88))
        { pc = 0x10b59; break; }
    memoryASet16(ds, 0x5b88, r16[si]);
    r16[di] = 0x0c22;
    yield* sub_10590();
  case 0x10b59:
    r16[si] = memoryAGet16(es, r16[bx] + 116);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b8a))
        { pc = 0x10b71; break; }
    memoryASet16(ds, 0x5b8a, r16[si]);
    r16[di] = 0x0c24;
    yield* sub_10590();
  case 0x10b71:
    r16[si] = memoryAGet16(es, r16[bx] + 118);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b8c))
        { pc = 0x10b89; break; }
    memoryASet16(ds, 0x5b8c, r16[si]);
    r16[di] = 0x0c26;
    yield* sub_10590();
  case 0x10b89:
    r16[si] = memoryAGet16(es, r16[bx] + 120);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b8e))
        { pc = 0x10ba1; break; }
    memoryASet16(ds, 0x5b8e, r16[si]);
    r16[di] = 0x0c28;
    yield* sub_10590();
  case 0x10ba1:
    r16[si] = memoryAGet16(es, r16[bx] + 122);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b90))
        { pc = 0x10bb9; break; }
    memoryASet16(ds, 0x5b90, r16[si]);
    r16[di] = 0x0c2a;
    yield* sub_10590();
  case 0x10bb9:
    r16[si] = memoryAGet16(es, r16[bx] + 124);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b92))
        { pc = 0x10bd1; break; }
    memoryASet16(ds, 0x5b92, r16[si]);
    r16[di] = 0x0c2c;
    yield* sub_10590();
  case 0x10bd1:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 126);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b94))
        { pc = 0x10bed; break; }
    memoryASet16(ds, 0x5b94, r16[si]);
    r16[di] = 0x0f04;
    yield* sub_10590();
  case 0x10bed:
    r16[si] = memoryAGet16(es, r16[bx] + 128);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b96))
        { pc = 0x10c06; break; }
    memoryASet16(ds, 0x5b96, r16[si]);
    r16[di] = 0x0f06;
    yield* sub_10590();
  case 0x10c06:
    r16[si] = memoryAGet16(es, r16[bx] + 130);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b98))
        { pc = 0x10c1f; break; }
    memoryASet16(ds, 0x5b98, r16[si]);
    r16[di] = 0x0f08;
    yield* sub_10590();
  case 0x10c1f:
    r16[si] = memoryAGet16(es, r16[bx] + 132);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b9a))
        { pc = 0x10c38; break; }
    memoryASet16(ds, 0x5b9a, r16[si]);
    r16[di] = 0x0f0a;
    yield* sub_10590();
  case 0x10c38:
    r16[si] = memoryAGet16(es, r16[bx] + 134);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b9c))
        { pc = 0x10c51; break; }
    memoryASet16(ds, 0x5b9c, r16[si]);
    r16[di] = 0x0f0c;
    yield* sub_10590();
  case 0x10c51:
    r16[si] = memoryAGet16(es, r16[bx] + 136);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5b9e))
        { pc = 0x10c6a; break; }
    memoryASet16(ds, 0x5b9e, r16[si]);
    r16[di] = 0x0f0e;
    yield* sub_10590();
  case 0x10c6a:
    r16[si] = memoryAGet16(es, r16[bx] + 138);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ba0))
        { pc = 0x10c83; break; }
    memoryASet16(ds, 0x5ba0, r16[si]);
    r16[di] = 0x0f10;
    yield* sub_10590();
  case 0x10c83:
    r16[si] = memoryAGet16(es, r16[bx] + 140);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ba2))
        { pc = 0x10c9c; break; }
    memoryASet16(ds, 0x5ba2, r16[si]);
    r16[di] = 0x0f12;
    yield* sub_10590();
  case 0x10c9c:
    r16[si] = memoryAGet16(es, r16[bx] + 142);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ba4))
        { pc = 0x10cb5; break; }
    memoryASet16(ds, 0x5ba4, r16[si]);
    r16[di] = 0x0f14;
    yield* sub_10590();
  case 0x10cb5:
    r16[si] = memoryAGet16(es, r16[bx] + 144);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ba6))
        { pc = 0x10cce; break; }
    memoryASet16(ds, 0x5ba6, r16[si]);
    r16[di] = 0x0f16;
    yield* sub_10590();
  case 0x10cce:
    r16[si] = memoryAGet16(es, r16[bx] + 146);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ba8))
        { pc = 0x10ce7; break; }
    memoryASet16(ds, 0x5ba8, r16[si]);
    r16[di] = 0x0f18;
    yield* sub_10590();
  case 0x10ce7:
    r16[si] = memoryAGet16(es, r16[bx] + 148);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5baa))
        { pc = 0x10d00; break; }
    memoryASet16(ds, 0x5baa, r16[si]);
    r16[di] = 0x0f1a;
    yield* sub_10590();
  case 0x10d00:
    r16[si] = memoryAGet16(es, r16[bx] + 150);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bac))
        { pc = 0x10d19; break; }
    memoryASet16(ds, 0x5bac, r16[si]);
    r16[di] = 0x0f1c;
    yield* sub_10590();
  case 0x10d19:
    r16[si] = memoryAGet16(es, r16[bx] + 152);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bae))
        { pc = 0x10d32; break; }
    memoryASet16(ds, 0x5bae, r16[si]);
    r16[di] = 0x0f1e;
    yield* sub_10590();
  case 0x10d32:
    r16[si] = memoryAGet16(es, r16[bx] + 154);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bb0))
        { pc = 0x10d4b; break; }
    memoryASet16(ds, 0x5bb0, r16[si]);
    r16[di] = 0x0f20;
    yield* sub_10590();
  case 0x10d4b:
    r16[si] = memoryAGet16(es, r16[bx] + 156);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bb2))
        { pc = 0x10d64; break; }
    memoryASet16(ds, 0x5bb2, r16[si]);
    r16[di] = 0x0f22;
    yield* sub_10590();
  case 0x10d64:
    r16[si] = memoryAGet16(es, r16[bx] + 158);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bb4))
        { pc = 0x10d7d; break; }
    memoryASet16(ds, 0x5bb4, r16[si]);
    r16[di] = 0x0f24;
    yield* sub_10590();
  case 0x10d7d:
    r16[si] = memoryAGet16(es, r16[bx] + 160);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bb6))
        { pc = 0x10d96; break; }
    memoryASet16(ds, 0x5bb6, r16[si]);
    r16[di] = 0x0f26;
    yield* sub_10590();
  case 0x10d96:
    r16[si] = memoryAGet16(es, r16[bx] + 162);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bb8))
        { pc = 0x10daf; break; }
    memoryASet16(ds, 0x5bb8, r16[si]);
    r16[di] = 0x0f28;
    yield* sub_10590();
  case 0x10daf:
    r16[si] = memoryAGet16(es, r16[bx] + 164);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bba))
        { pc = 0x10dc8; break; }
    memoryASet16(ds, 0x5bba, r16[si]);
    r16[di] = 0x0f2a;
    yield* sub_10590();
  case 0x10dc8:
    r16[si] = memoryAGet16(es, r16[bx] + 166);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bbc))
        { pc = 0x10de1; break; }
    memoryASet16(ds, 0x5bbc, r16[si]);
    r16[di] = 0x0f2c;
    yield* sub_10590();
  case 0x10de1:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 168);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bbe))
        { pc = 0x10dfe; break; }
    memoryASet16(ds, 0x5bbe, r16[si]);
    r16[di] = 0x1204;
    yield* sub_10590();
  case 0x10dfe:
    r16[si] = memoryAGet16(es, r16[bx] + 170);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bc0))
        { pc = 0x10e17; break; }
    memoryASet16(ds, 0x5bc0, r16[si]);
    r16[di] = 0x1206;
    yield* sub_10590();
  case 0x10e17:
    r16[si] = memoryAGet16(es, r16[bx] + 172);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bc2))
        { pc = 0x10e30; break; }
    memoryASet16(ds, 0x5bc2, r16[si]);
    r16[di] = 0x1208;
    yield* sub_10590();
  case 0x10e30:
    r16[si] = memoryAGet16(es, r16[bx] + 174);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bc4))
        { pc = 0x10e49; break; }
    memoryASet16(ds, 0x5bc4, r16[si]);
    r16[di] = 0x120a;
    yield* sub_10590();
  case 0x10e49:
    r16[si] = memoryAGet16(es, r16[bx] + 176);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bc6))
        { pc = 0x10e62; break; }
    memoryASet16(ds, 0x5bc6, r16[si]);
    r16[di] = 0x120c;
    yield* sub_10590();
  case 0x10e62:
    r16[si] = memoryAGet16(es, r16[bx] + 178);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bc8))
        { pc = 0x10e7b; break; }
    memoryASet16(ds, 0x5bc8, r16[si]);
    r16[di] = 0x120e;
    yield* sub_10590();
  case 0x10e7b:
    r16[si] = memoryAGet16(es, r16[bx] + 180);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bca))
        { pc = 0x10e94; break; }
    memoryASet16(ds, 0x5bca, r16[si]);
    r16[di] = 0x1210;
    yield* sub_10590();
  case 0x10e94:
    r16[si] = memoryAGet16(es, r16[bx] + 182);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bcc))
        { pc = 0x10ead; break; }
    memoryASet16(ds, 0x5bcc, r16[si]);
    r16[di] = 0x1212;
    yield* sub_10590();
  case 0x10ead:
    r16[si] = memoryAGet16(es, r16[bx] + 184);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bce))
        { pc = 0x10ec6; break; }
    memoryASet16(ds, 0x5bce, r16[si]);
    r16[di] = 0x1214;
    yield* sub_10590();
  case 0x10ec6:
    r16[si] = memoryAGet16(es, r16[bx] + 186);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bd0))
        { pc = 0x10edf; break; }
    memoryASet16(ds, 0x5bd0, r16[si]);
    r16[di] = 0x1216;
    yield* sub_10590();
  case 0x10edf:
    r16[si] = memoryAGet16(es, r16[bx] + 188);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bd2))
        { pc = 0x10ef8; break; }
    memoryASet16(ds, 0x5bd2, r16[si]);
    r16[di] = 0x1218;
    yield* sub_10590();
  case 0x10ef8:
    r16[si] = memoryAGet16(es, r16[bx] + 190);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bd4))
        { pc = 0x10f11; break; }
    memoryASet16(ds, 0x5bd4, r16[si]);
    r16[di] = 0x121a;
    yield* sub_10590();
  case 0x10f11:
    r16[si] = memoryAGet16(es, r16[bx] + 192);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bd6))
        { pc = 0x10f2a; break; }
    memoryASet16(ds, 0x5bd6, r16[si]);
    r16[di] = 0x121c;
    yield* sub_10590();
  case 0x10f2a:
    r16[si] = memoryAGet16(es, r16[bx] + 194);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bd8))
        { pc = 0x10f43; break; }
    memoryASet16(ds, 0x5bd8, r16[si]);
    r16[di] = 0x121e;
    yield* sub_10590();
  case 0x10f43:
    r16[si] = memoryAGet16(es, r16[bx] + 196);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bda))
        { pc = 0x10f5c; break; }
    memoryASet16(ds, 0x5bda, r16[si]);
    r16[di] = 0x1220;
    yield* sub_10590();
  case 0x10f5c:
    r16[si] = memoryAGet16(es, r16[bx] + 198);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bdc))
        { pc = 0x10f75; break; }
    memoryASet16(ds, 0x5bdc, r16[si]);
    r16[di] = 0x1222;
    yield* sub_10590();
  case 0x10f75:
    r16[si] = memoryAGet16(es, r16[bx] + 200);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bde))
        { pc = 0x10f8e; break; }
    memoryASet16(ds, 0x5bde, r16[si]);
    r16[di] = 0x1224;
    yield* sub_10590();
  case 0x10f8e:
    r16[si] = memoryAGet16(es, r16[bx] + 202);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5be0))
        { pc = 0x10fa7; break; }
    memoryASet16(ds, 0x5be0, r16[si]);
    r16[di] = 0x1226;
    yield* sub_10590();
  case 0x10fa7:
    r16[si] = memoryAGet16(es, r16[bx] + 204);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5be2))
        { pc = 0x10fc0; break; }
    memoryASet16(ds, 0x5be2, r16[si]);
    r16[di] = 0x1228;
    yield* sub_10590();
  case 0x10fc0:
    r16[si] = memoryAGet16(es, r16[bx] + 206);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5be4))
        { pc = 0x10fd9; break; }
    memoryASet16(ds, 0x5be4, r16[si]);
    r16[di] = 0x122a;
    yield* sub_10590();
  case 0x10fd9:
    r16[si] = memoryAGet16(es, r16[bx] + 208);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5be6))
        { pc = 0x10ff2; break; }
    memoryASet16(ds, 0x5be6, r16[si]);
    r16[di] = 0x122c;
    yield* sub_10590();
  case 0x10ff2:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 210);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5be8))
        { pc = 0x1100f; break; }
    memoryASet16(ds, 0x5be8, r16[si]);
    r16[di] = 0x1504;
    yield* sub_10590();
  case 0x1100f:
    r16[si] = memoryAGet16(es, r16[bx] + 212);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bea))
        { pc = 0x11028; break; }
    memoryASet16(ds, 0x5bea, r16[si]);
    r16[di] = 0x1506;
    yield* sub_10590();
  case 0x11028:
    r16[si] = memoryAGet16(es, r16[bx] + 214);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bec))
        { pc = 0x11041; break; }
    memoryASet16(ds, 0x5bec, r16[si]);
    r16[di] = 0x1508;
    yield* sub_10590();
  case 0x11041:
    r16[si] = memoryAGet16(es, r16[bx] + 216);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bee))
        { pc = 0x1105a; break; }
    memoryASet16(ds, 0x5bee, r16[si]);
    r16[di] = 0x150a;
    yield* sub_10590();
  case 0x1105a:
    r16[si] = memoryAGet16(es, r16[bx] + 218);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bf0))
        { pc = 0x11073; break; }
    memoryASet16(ds, 0x5bf0, r16[si]);
    r16[di] = 0x150c;
    yield* sub_10590();
  case 0x11073:
    r16[si] = memoryAGet16(es, r16[bx] + 220);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bf2))
        { pc = 0x1108c; break; }
    memoryASet16(ds, 0x5bf2, r16[si]);
    r16[di] = 0x150e;
    yield* sub_10590();
  case 0x1108c:
    r16[si] = memoryAGet16(es, r16[bx] + 222);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bf4))
        { pc = 0x110a5; break; }
    memoryASet16(ds, 0x5bf4, r16[si]);
    r16[di] = 0x1510;
    yield* sub_10590();
  case 0x110a5:
    r16[si] = memoryAGet16(es, r16[bx] + 224);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bf6))
        { pc = 0x110be; break; }
    memoryASet16(ds, 0x5bf6, r16[si]);
    r16[di] = 0x1512;
    yield* sub_10590();
  case 0x110be:
    r16[si] = memoryAGet16(es, r16[bx] + 226);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bf8))
        { pc = 0x110d7; break; }
    memoryASet16(ds, 0x5bf8, r16[si]);
    r16[di] = 0x1514;
    yield* sub_10590();
  case 0x110d7:
    r16[si] = memoryAGet16(es, r16[bx] + 228);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bfa))
        { pc = 0x110f0; break; }
    memoryASet16(ds, 0x5bfa, r16[si]);
    r16[di] = 0x1516;
    yield* sub_10590();
  case 0x110f0:
    r16[si] = memoryAGet16(es, r16[bx] + 230);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bfc))
        { pc = 0x11109; break; }
    memoryASet16(ds, 0x5bfc, r16[si]);
    r16[di] = 0x1518;
    yield* sub_10590();
  case 0x11109:
    r16[si] = memoryAGet16(es, r16[bx] + 232);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5bfe))
        { pc = 0x11122; break; }
    memoryASet16(ds, 0x5bfe, r16[si]);
    r16[di] = 0x151a;
    yield* sub_10590();
  case 0x11122:
    r16[si] = memoryAGet16(es, r16[bx] + 234);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c00))
        { pc = 0x1113b; break; }
    memoryASet16(ds, 0x5c00, r16[si]);
    r16[di] = 0x151c;
    yield* sub_10590();
  case 0x1113b:
    r16[si] = memoryAGet16(es, r16[bx] + 236);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c02))
        { pc = 0x11154; break; }
    memoryASet16(ds, 0x5c02, r16[si]);
    r16[di] = 0x151e;
    yield* sub_10590();
  case 0x11154:
    r16[si] = memoryAGet16(es, r16[bx] + 238);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c04))
        { pc = 0x1116d; break; }
    memoryASet16(ds, 0x5c04, r16[si]);
    r16[di] = 0x1520;
    yield* sub_10590();
  case 0x1116d:
    r16[si] = memoryAGet16(es, r16[bx] + 240);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c06))
        { pc = 0x11186; break; }
    memoryASet16(ds, 0x5c06, r16[si]);
    r16[di] = 0x1522;
    yield* sub_10590();
  case 0x11186:
    r16[si] = memoryAGet16(es, r16[bx] + 242);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c08))
        { pc = 0x1119f; break; }
    memoryASet16(ds, 0x5c08, r16[si]);
    r16[di] = 0x1524;
    yield* sub_10590();
  case 0x1119f:
    r16[si] = memoryAGet16(es, r16[bx] + 244);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c0a))
        { pc = 0x111b8; break; }
    memoryASet16(ds, 0x5c0a, r16[si]);
    r16[di] = 0x1526;
    yield* sub_10590();
  case 0x111b8:
    r16[si] = memoryAGet16(es, r16[bx] + 246);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c0c))
        { pc = 0x111d1; break; }
    memoryASet16(ds, 0x5c0c, r16[si]);
    r16[di] = 0x1528;
    yield* sub_10590();
  case 0x111d1:
    r16[si] = memoryAGet16(es, r16[bx] + 248);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c0e))
        { pc = 0x111ea; break; }
    memoryASet16(ds, 0x5c0e, r16[si]);
    r16[di] = 0x152a;
    yield* sub_10590();
  case 0x111ea:
    r16[si] = memoryAGet16(es, r16[bx] + 250);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c10))
        { pc = 0x11203; break; }
    memoryASet16(ds, 0x5c10, r16[si]);
    r16[di] = 0x152c;
    yield* sub_10590();
  case 0x11203:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 252);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c12))
        { pc = 0x11220; break; }
    memoryASet16(ds, 0x5c12, r16[si]);
    r16[di] = 0x1804;
    yield* sub_10590();
  case 0x11220:
    r16[si] = memoryAGet16(es, r16[bx] + 254);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c14))
        { pc = 0x11239; break; }
    memoryASet16(ds, 0x5c14, r16[si]);
    r16[di] = 0x1806;
    yield* sub_10590();
  case 0x11239:
    r16[si] = memoryAGet16(es, r16[bx] + 256);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c16))
        { pc = 0x11252; break; }
    memoryASet16(ds, 0x5c16, r16[si]);
    r16[di] = 0x1808;
    yield* sub_10590();
  case 0x11252:
    r16[si] = memoryAGet16(es, r16[bx] + 258);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c18))
        { pc = 0x1126b; break; }
    memoryASet16(ds, 0x5c18, r16[si]);
    r16[di] = 0x180a;
    yield* sub_10590();
  case 0x1126b:
    r16[si] = memoryAGet16(es, r16[bx] + 260);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c1a))
        { pc = 0x11284; break; }
    memoryASet16(ds, 0x5c1a, r16[si]);
    r16[di] = 0x180c;
    yield* sub_10590();
  case 0x11284:
    r16[si] = memoryAGet16(es, r16[bx] + 262);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c1c))
        { pc = 0x1129d; break; }
    memoryASet16(ds, 0x5c1c, r16[si]);
    r16[di] = 0x180e;
    yield* sub_10590();
  case 0x1129d:
    r16[si] = memoryAGet16(es, r16[bx] + 264);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c1e))
        { pc = 0x112b6; break; }
    memoryASet16(ds, 0x5c1e, r16[si]);
    r16[di] = 0x1810;
    yield* sub_10590();
  case 0x112b6:
    r16[si] = memoryAGet16(es, r16[bx] + 266);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c20))
        { pc = 0x112cf; break; }
    memoryASet16(ds, 0x5c20, r16[si]);
    r16[di] = 0x1812;
    yield* sub_10590();
  case 0x112cf:
    r16[si] = memoryAGet16(es, r16[bx] + 268);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c22))
        { pc = 0x112e8; break; }
    memoryASet16(ds, 0x5c22, r16[si]);
    r16[di] = 0x1814;
    yield* sub_10590();
  case 0x112e8:
    r16[si] = memoryAGet16(es, r16[bx] + 270);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c24))
        { pc = 0x11301; break; }
    memoryASet16(ds, 0x5c24, r16[si]);
    r16[di] = 0x1816;
    yield* sub_10590();
  case 0x11301:
    r16[si] = memoryAGet16(es, r16[bx] + 272);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c26))
        { pc = 0x1131a; break; }
    memoryASet16(ds, 0x5c26, r16[si]);
    r16[di] = 0x1818;
    yield* sub_10590();
  case 0x1131a:
    r16[si] = memoryAGet16(es, r16[bx] + 274);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c28))
        { pc = 0x11333; break; }
    memoryASet16(ds, 0x5c28, r16[si]);
    r16[di] = 0x181a;
    yield* sub_10590();
  case 0x11333:
    r16[si] = memoryAGet16(es, r16[bx] + 276);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c2a))
        { pc = 0x1134c; break; }
    memoryASet16(ds, 0x5c2a, r16[si]);
    r16[di] = 0x181c;
    yield* sub_10590();
  case 0x1134c:
    r16[si] = memoryAGet16(es, r16[bx] + 278);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c2c))
        { pc = 0x11365; break; }
    memoryASet16(ds, 0x5c2c, r16[si]);
    r16[di] = 0x181e;
    yield* sub_10590();
  case 0x11365:
    r16[si] = memoryAGet16(es, r16[bx] + 280);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c2e))
        { pc = 0x1137e; break; }
    memoryASet16(ds, 0x5c2e, r16[si]);
    r16[di] = 0x1820;
    yield* sub_10590();
  case 0x1137e:
    r16[si] = memoryAGet16(es, r16[bx] + 282);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c30))
        { pc = 0x11397; break; }
    memoryASet16(ds, 0x5c30, r16[si]);
    r16[di] = 0x1822;
    yield* sub_10590();
  case 0x11397:
    r16[si] = memoryAGet16(es, r16[bx] + 284);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c32))
        { pc = 0x113b0; break; }
    memoryASet16(ds, 0x5c32, r16[si]);
    r16[di] = 0x1824;
    yield* sub_10590();
  case 0x113b0:
    r16[si] = memoryAGet16(es, r16[bx] + 286);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c34))
        { pc = 0x113c9; break; }
    memoryASet16(ds, 0x5c34, r16[si]);
    r16[di] = 0x1826;
    yield* sub_10590();
  case 0x113c9:
    r16[si] = memoryAGet16(es, r16[bx] + 288);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c36))
        { pc = 0x113e2; break; }
    memoryASet16(ds, 0x5c36, r16[si]);
    r16[di] = 0x1828;
    yield* sub_10590();
  case 0x113e2:
    r16[si] = memoryAGet16(es, r16[bx] + 290);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c38))
        { pc = 0x113fb; break; }
    memoryASet16(ds, 0x5c38, r16[si]);
    r16[di] = 0x182a;
    yield* sub_10590();
  case 0x113fb:
    r16[si] = memoryAGet16(es, r16[bx] + 292);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c3a))
        { pc = 0x11414; break; }
    memoryASet16(ds, 0x5c3a, r16[si]);
    r16[di] = 0x182c;
    yield* sub_10590();
  case 0x11414:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 294);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c3c))
        { pc = 0x11431; break; }
    memoryASet16(ds, 0x5c3c, r16[si]);
    r16[di] = 0x1b04;
    yield* sub_10590();
  case 0x11431:
    r16[si] = memoryAGet16(es, r16[bx] + 296);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c3e))
        { pc = 0x1144a; break; }
    memoryASet16(ds, 0x5c3e, r16[si]);
    r16[di] = 0x1b06;
    yield* sub_10590();
  case 0x1144a:
    r16[si] = memoryAGet16(es, r16[bx] + 298);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c40))
        { pc = 0x11463; break; }
    memoryASet16(ds, 0x5c40, r16[si]);
    r16[di] = 0x1b08;
    yield* sub_10590();
  case 0x11463:
    r16[si] = memoryAGet16(es, r16[bx] + 300);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c42))
        { pc = 0x1147c; break; }
    memoryASet16(ds, 0x5c42, r16[si]);
    r16[di] = 0x1b0a;
    yield* sub_10590();
  case 0x1147c:
    r16[si] = memoryAGet16(es, r16[bx] + 302);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c44))
        { pc = 0x11495; break; }
    memoryASet16(ds, 0x5c44, r16[si]);
    r16[di] = 0x1b0c;
    yield* sub_10590();
  case 0x11495:
    r16[si] = memoryAGet16(es, r16[bx] + 304);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c46))
        { pc = 0x114ae; break; }
    memoryASet16(ds, 0x5c46, r16[si]);
    r16[di] = 0x1b0e;
    yield* sub_10590();
  case 0x114ae:
    r16[si] = memoryAGet16(es, r16[bx] + 306);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c48))
        { pc = 0x114c7; break; }
    memoryASet16(ds, 0x5c48, r16[si]);
    r16[di] = 0x1b10;
    yield* sub_10590();
  case 0x114c7:
    r16[si] = memoryAGet16(es, r16[bx] + 308);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c4a))
        { pc = 0x114e0; break; }
    memoryASet16(ds, 0x5c4a, r16[si]);
    r16[di] = 0x1b12;
    yield* sub_10590();
  case 0x114e0:
    r16[si] = memoryAGet16(es, r16[bx] + 310);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c4c))
        { pc = 0x114f9; break; }
    memoryASet16(ds, 0x5c4c, r16[si]);
    r16[di] = 0x1b14;
    yield* sub_10590();
  case 0x114f9:
    r16[si] = memoryAGet16(es, r16[bx] + 312);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c4e))
        { pc = 0x11512; break; }
    memoryASet16(ds, 0x5c4e, r16[si]);
    r16[di] = 0x1b16;
    yield* sub_10590();
  case 0x11512:
    r16[si] = memoryAGet16(es, r16[bx] + 314);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c50))
        { pc = 0x1152b; break; }
    memoryASet16(ds, 0x5c50, r16[si]);
    r16[di] = 0x1b18;
    yield* sub_10590();
  case 0x1152b:
    r16[si] = memoryAGet16(es, r16[bx] + 316);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c52))
        { pc = 0x11544; break; }
    memoryASet16(ds, 0x5c52, r16[si]);
    r16[di] = 0x1b1a;
    yield* sub_10590();
  case 0x11544:
    r16[si] = memoryAGet16(es, r16[bx] + 318);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c54))
        { pc = 0x1155d; break; }
    memoryASet16(ds, 0x5c54, r16[si]);
    r16[di] = 0x1b1c;
    yield* sub_10590();
  case 0x1155d:
    r16[si] = memoryAGet16(es, r16[bx] + 320);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c56))
        { pc = 0x11576; break; }
    memoryASet16(ds, 0x5c56, r16[si]);
    r16[di] = 0x1b1e;
    yield* sub_10590();
  case 0x11576:
    r16[si] = memoryAGet16(es, r16[bx] + 322);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c58))
        { pc = 0x1158f; break; }
    memoryASet16(ds, 0x5c58, r16[si]);
    r16[di] = 0x1b20;
    yield* sub_10590();
  case 0x1158f:
    r16[si] = memoryAGet16(es, r16[bx] + 324);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c5a))
        { pc = 0x115a8; break; }
    memoryASet16(ds, 0x5c5a, r16[si]);
    r16[di] = 0x1b22;
    yield* sub_10590();
  case 0x115a8:
    r16[si] = memoryAGet16(es, r16[bx] + 326);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c5c))
        { pc = 0x115c1; break; }
    memoryASet16(ds, 0x5c5c, r16[si]);
    r16[di] = 0x1b24;
    yield* sub_10590();
  case 0x115c1:
    r16[si] = memoryAGet16(es, r16[bx] + 328);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c5e))
        { pc = 0x115da; break; }
    memoryASet16(ds, 0x5c5e, r16[si]);
    r16[di] = 0x1b26;
    yield* sub_10590();
  case 0x115da:
    r16[si] = memoryAGet16(es, r16[bx] + 330);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c60))
        { pc = 0x115f3; break; }
    memoryASet16(ds, 0x5c60, r16[si]);
    r16[di] = 0x1b28;
    yield* sub_10590();
  case 0x115f3:
    r16[si] = memoryAGet16(es, r16[bx] + 332);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c62))
        { pc = 0x1160c; break; }
    memoryASet16(ds, 0x5c62, r16[si]);
    r16[di] = 0x1b2a;
    yield* sub_10590();
  case 0x1160c:
    r16[si] = memoryAGet16(es, r16[bx] + 334);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c64))
        { pc = 0x11625; break; }
    memoryASet16(ds, 0x5c64, r16[si]);
    r16[di] = 0x1b2c;
    yield* sub_10590();
  case 0x11625:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 336);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c66))
        { pc = 0x11642; break; }
    memoryASet16(ds, 0x5c66, r16[si]);
    r16[di] = 0x1e04;
    yield* sub_10590();
  case 0x11642:
    r16[si] = memoryAGet16(es, r16[bx] + 338);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c68))
        { pc = 0x1165b; break; }
    memoryASet16(ds, 0x5c68, r16[si]);
    r16[di] = 0x1e06;
    yield* sub_10590();
  case 0x1165b:
    r16[si] = memoryAGet16(es, r16[bx] + 340);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c6a))
        { pc = 0x11674; break; }
    memoryASet16(ds, 0x5c6a, r16[si]);
    r16[di] = 0x1e08;
    yield* sub_10590();
  case 0x11674:
    r16[si] = memoryAGet16(es, r16[bx] + 342);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c6c))
        { pc = 0x1168d; break; }
    memoryASet16(ds, 0x5c6c, r16[si]);
    r16[di] = 0x1e0a;
    yield* sub_10590();
  case 0x1168d:
    r16[si] = memoryAGet16(es, r16[bx] + 344);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c6e))
        { pc = 0x116a6; break; }
    memoryASet16(ds, 0x5c6e, r16[si]);
    r16[di] = 0x1e0c;
    yield* sub_10590();
  case 0x116a6:
    r16[si] = memoryAGet16(es, r16[bx] + 346);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c70))
        { pc = 0x116bf; break; }
    memoryASet16(ds, 0x5c70, r16[si]);
    r16[di] = 0x1e0e;
    yield* sub_10590();
  case 0x116bf:
    r16[si] = memoryAGet16(es, r16[bx] + 348);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c72))
        { pc = 0x116d8; break; }
    memoryASet16(ds, 0x5c72, r16[si]);
    r16[di] = 0x1e10;
    yield* sub_10590();
  case 0x116d8:
    r16[si] = memoryAGet16(es, r16[bx] + 350);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c74))
        { pc = 0x116f1; break; }
    memoryASet16(ds, 0x5c74, r16[si]);
    r16[di] = 0x1e12;
    yield* sub_10590();
  case 0x116f1:
    r16[si] = memoryAGet16(es, r16[bx] + 352);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c76))
        { pc = 0x1170a; break; }
    memoryASet16(ds, 0x5c76, r16[si]);
    r16[di] = 0x1e14;
    yield* sub_10590();
  case 0x1170a:
    r16[si] = memoryAGet16(es, r16[bx] + 354);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c78))
        { pc = 0x11723; break; }
    memoryASet16(ds, 0x5c78, r16[si]);
    r16[di] = 0x1e16;
    yield* sub_10590();
  case 0x11723:
    r16[si] = memoryAGet16(es, r16[bx] + 356);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c7a))
        { pc = 0x1173c; break; }
    memoryASet16(ds, 0x5c7a, r16[si]);
    r16[di] = 0x1e18;
    yield* sub_10590();
  case 0x1173c:
    r16[si] = memoryAGet16(es, r16[bx] + 358);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c7c))
        { pc = 0x11755; break; }
    memoryASet16(ds, 0x5c7c, r16[si]);
    r16[di] = 0x1e1a;
    yield* sub_10590();
  case 0x11755:
    r16[si] = memoryAGet16(es, r16[bx] + 360);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c7e))
        { pc = 0x1176e; break; }
    memoryASet16(ds, 0x5c7e, r16[si]);
    r16[di] = 0x1e1c;
    yield* sub_10590();
  case 0x1176e:
    r16[si] = memoryAGet16(es, r16[bx] + 362);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c80))
        { pc = 0x11787; break; }
    memoryASet16(ds, 0x5c80, r16[si]);
    r16[di] = 0x1e1e;
    yield* sub_10590();
  case 0x11787:
    r16[si] = memoryAGet16(es, r16[bx] + 364);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c82))
        { pc = 0x117a0; break; }
    memoryASet16(ds, 0x5c82, r16[si]);
    r16[di] = 0x1e20;
    yield* sub_10590();
  case 0x117a0:
    r16[si] = memoryAGet16(es, r16[bx] + 366);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c84))
        { pc = 0x117b9; break; }
    memoryASet16(ds, 0x5c84, r16[si]);
    r16[di] = 0x1e22;
    yield* sub_10590();
  case 0x117b9:
    r16[si] = memoryAGet16(es, r16[bx] + 368);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c86))
        { pc = 0x117d2; break; }
    memoryASet16(ds, 0x5c86, r16[si]);
    r16[di] = 0x1e24;
    yield* sub_10590();
  case 0x117d2:
    r16[si] = memoryAGet16(es, r16[bx] + 370);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c88))
        { pc = 0x117eb; break; }
    memoryASet16(ds, 0x5c88, r16[si]);
    r16[di] = 0x1e26;
    yield* sub_10590();
  case 0x117eb:
    r16[si] = memoryAGet16(es, r16[bx] + 372);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c8a))
        { pc = 0x11804; break; }
    memoryASet16(ds, 0x5c8a, r16[si]);
    r16[di] = 0x1e28;
    yield* sub_10590();
  case 0x11804:
    r16[si] = memoryAGet16(es, r16[bx] + 374);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c8c))
        { pc = 0x1181d; break; }
    memoryASet16(ds, 0x5c8c, r16[si]);
    r16[di] = 0x1e2a;
    yield* sub_10590();
  case 0x1181d:
    r16[si] = memoryAGet16(es, r16[bx] + 376);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c8e))
        { pc = 0x11836; break; }
    memoryASet16(ds, 0x5c8e, r16[si]);
    r16[di] = 0x1e2c;
    yield* sub_10590();
  case 0x11836:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 378);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c90))
        { pc = 0x11853; break; }
    memoryASet16(ds, 0x5c90, r16[si]);
    r16[di] = 0x2104;
    yield* sub_10590();
  case 0x11853:
    r16[si] = memoryAGet16(es, r16[bx] + 380);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c92))
        { pc = 0x1186c; break; }
    memoryASet16(ds, 0x5c92, r16[si]);
    r16[di] = 0x2106;
    yield* sub_10590();
  case 0x1186c:
    r16[si] = memoryAGet16(es, r16[bx] + 382);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c94))
        { pc = 0x11885; break; }
    memoryASet16(ds, 0x5c94, r16[si]);
    r16[di] = 0x2108;
    yield* sub_10590();
  case 0x11885:
    r16[si] = memoryAGet16(es, r16[bx] + 384);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c96))
        { pc = 0x1189e; break; }
    memoryASet16(ds, 0x5c96, r16[si]);
    r16[di] = 0x210a;
    yield* sub_10590();
  case 0x1189e:
    r16[si] = memoryAGet16(es, r16[bx] + 386);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c98))
        { pc = 0x118b7; break; }
    memoryASet16(ds, 0x5c98, r16[si]);
    r16[di] = 0x210c;
    yield* sub_10590();
  case 0x118b7:
    r16[si] = memoryAGet16(es, r16[bx] + 388);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c9a))
        { pc = 0x118d0; break; }
    memoryASet16(ds, 0x5c9a, r16[si]);
    r16[di] = 0x210e;
    yield* sub_10590();
  case 0x118d0:
    r16[si] = memoryAGet16(es, r16[bx] + 390);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c9c))
        { pc = 0x118e9; break; }
    memoryASet16(ds, 0x5c9c, r16[si]);
    r16[di] = 0x2110;
    yield* sub_10590();
  case 0x118e9:
    r16[si] = memoryAGet16(es, r16[bx] + 392);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5c9e))
        { pc = 0x11902; break; }
    memoryASet16(ds, 0x5c9e, r16[si]);
    r16[di] = 0x2112;
    yield* sub_10590();
  case 0x11902:
    r16[si] = memoryAGet16(es, r16[bx] + 394);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ca0))
        { pc = 0x1191b; break; }
    memoryASet16(ds, 0x5ca0, r16[si]);
    r16[di] = 0x2114;
    yield* sub_10590();
  case 0x1191b:
    r16[si] = memoryAGet16(es, r16[bx] + 396);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ca2))
        { pc = 0x11934; break; }
    memoryASet16(ds, 0x5ca2, r16[si]);
    r16[di] = 0x2116;
    yield* sub_10590();
  case 0x11934:
    r16[si] = memoryAGet16(es, r16[bx] + 398);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ca4))
        { pc = 0x1194d; break; }
    memoryASet16(ds, 0x5ca4, r16[si]);
    r16[di] = 0x2118;
    yield* sub_10590();
  case 0x1194d:
    r16[si] = memoryAGet16(es, r16[bx] + 400);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ca6))
        { pc = 0x11966; break; }
    memoryASet16(ds, 0x5ca6, r16[si]);
    r16[di] = 0x211a;
    yield* sub_10590();
  case 0x11966:
    r16[si] = memoryAGet16(es, r16[bx] + 402);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ca8))
        { pc = 0x1197f; break; }
    memoryASet16(ds, 0x5ca8, r16[si]);
    r16[di] = 0x211c;
    yield* sub_10590();
  case 0x1197f:
    r16[si] = memoryAGet16(es, r16[bx] + 404);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5caa))
        { pc = 0x11998; break; }
    memoryASet16(ds, 0x5caa, r16[si]);
    r16[di] = 0x211e;
    yield* sub_10590();
  case 0x11998:
    r16[si] = memoryAGet16(es, r16[bx] + 406);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cac))
        { pc = 0x119b1; break; }
    memoryASet16(ds, 0x5cac, r16[si]);
    r16[di] = 0x2120;
    yield* sub_10590();
  case 0x119b1:
    r16[si] = memoryAGet16(es, r16[bx] + 408);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cae))
        { pc = 0x119ca; break; }
    memoryASet16(ds, 0x5cae, r16[si]);
    r16[di] = 0x2122;
    yield* sub_10590();
  case 0x119ca:
    r16[si] = memoryAGet16(es, r16[bx] + 410);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cb0))
        { pc = 0x119e3; break; }
    memoryASet16(ds, 0x5cb0, r16[si]);
    r16[di] = 0x2124;
    yield* sub_10590();
  case 0x119e3:
    r16[si] = memoryAGet16(es, r16[bx] + 412);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cb2))
        { pc = 0x119fc; break; }
    memoryASet16(ds, 0x5cb2, r16[si]);
    r16[di] = 0x2126;
    yield* sub_10590();
  case 0x119fc:
    r16[si] = memoryAGet16(es, r16[bx] + 414);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cb4))
        { pc = 0x11a15; break; }
    memoryASet16(ds, 0x5cb4, r16[si]);
    r16[di] = 0x2128;
    yield* sub_10590();
  case 0x11a15:
    r16[si] = memoryAGet16(es, r16[bx] + 416);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cb6))
        { pc = 0x11a2e; break; }
    memoryASet16(ds, 0x5cb6, r16[si]);
    r16[di] = 0x212a;
    yield* sub_10590();
  case 0x11a2e:
    r16[si] = memoryAGet16(es, r16[bx] + 418);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cb8))
        { pc = 0x11a47; break; }
    memoryASet16(ds, 0x5cb8, r16[si]);
    r16[di] = 0x212c;
    yield* sub_10590();
  case 0x11a47:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 420);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cba))
        { pc = 0x11a64; break; }
    memoryASet16(ds, 0x5cba, r16[si]);
    r16[di] = 0x2404;
    yield* sub_10590();
  case 0x11a64:
    r16[si] = memoryAGet16(es, r16[bx] + 422);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cbc))
        { pc = 0x11a7d; break; }
    memoryASet16(ds, 0x5cbc, r16[si]);
    r16[di] = 0x2406;
    yield* sub_10590();
  case 0x11a7d:
    r16[si] = memoryAGet16(es, r16[bx] + 424);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cbe))
        { pc = 0x11a96; break; }
    memoryASet16(ds, 0x5cbe, r16[si]);
    r16[di] = 0x2408;
    yield* sub_10590();
  case 0x11a96:
    r16[si] = memoryAGet16(es, r16[bx] + 426);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cc0))
        { pc = 0x11aaf; break; }
    memoryASet16(ds, 0x5cc0, r16[si]);
    r16[di] = 0x240a;
    yield* sub_10590();
  case 0x11aaf:
    r16[si] = memoryAGet16(es, r16[bx] + 428);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cc2))
        { pc = 0x11ac8; break; }
    memoryASet16(ds, 0x5cc2, r16[si]);
    r16[di] = 0x240c;
    yield* sub_10590();
  case 0x11ac8:
    r16[si] = memoryAGet16(es, r16[bx] + 430);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cc4))
        { pc = 0x11ae1; break; }
    memoryASet16(ds, 0x5cc4, r16[si]);
    r16[di] = 0x240e;
    yield* sub_10590();
  case 0x11ae1:
    r16[si] = memoryAGet16(es, r16[bx] + 432);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cc6))
        { pc = 0x11afa; break; }
    memoryASet16(ds, 0x5cc6, r16[si]);
    r16[di] = 0x2410;
    yield* sub_10590();
  case 0x11afa:
    r16[si] = memoryAGet16(es, r16[bx] + 434);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cc8))
        { pc = 0x11b13; break; }
    memoryASet16(ds, 0x5cc8, r16[si]);
    r16[di] = 0x2412;
    yield* sub_10590();
  case 0x11b13:
    r16[si] = memoryAGet16(es, r16[bx] + 436);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cca))
        { pc = 0x11b2c; break; }
    memoryASet16(ds, 0x5cca, r16[si]);
    r16[di] = 0x2414;
    yield* sub_10590();
  case 0x11b2c:
    r16[si] = memoryAGet16(es, r16[bx] + 438);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ccc))
        { pc = 0x11b45; break; }
    memoryASet16(ds, 0x5ccc, r16[si]);
    r16[di] = 0x2416;
    yield* sub_10590();
  case 0x11b45:
    r16[si] = memoryAGet16(es, r16[bx] + 440);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cce))
        { pc = 0x11b5e; break; }
    memoryASet16(ds, 0x5cce, r16[si]);
    r16[di] = 0x2418;
    yield* sub_10590();
  case 0x11b5e:
    r16[si] = memoryAGet16(es, r16[bx] + 442);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cd0))
        { pc = 0x11b77; break; }
    memoryASet16(ds, 0x5cd0, r16[si]);
    r16[di] = 0x241a;
    yield* sub_10590();
  case 0x11b77:
    r16[si] = memoryAGet16(es, r16[bx] + 444);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cd2))
        { pc = 0x11b90; break; }
    memoryASet16(ds, 0x5cd2, r16[si]);
    r16[di] = 0x241c;
    yield* sub_10590();
  case 0x11b90:
    r16[si] = memoryAGet16(es, r16[bx] + 446);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cd4))
        { pc = 0x11ba9; break; }
    memoryASet16(ds, 0x5cd4, r16[si]);
    r16[di] = 0x241e;
    yield* sub_10590();
  case 0x11ba9:
    r16[si] = memoryAGet16(es, r16[bx] + 448);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cd6))
        { pc = 0x11bc2; break; }
    memoryASet16(ds, 0x5cd6, r16[si]);
    r16[di] = 0x2420;
    yield* sub_10590();
  case 0x11bc2:
    r16[si] = memoryAGet16(es, r16[bx] + 450);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cd8))
        { pc = 0x11bdb; break; }
    memoryASet16(ds, 0x5cd8, r16[si]);
    r16[di] = 0x2422;
    yield* sub_10590();
  case 0x11bdb:
    r16[si] = memoryAGet16(es, r16[bx] + 452);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cda))
        { pc = 0x11bf4; break; }
    memoryASet16(ds, 0x5cda, r16[si]);
    r16[di] = 0x2424;
    yield* sub_10590();
  case 0x11bf4:
    r16[si] = memoryAGet16(es, r16[bx] + 454);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cdc))
        { pc = 0x11c0d; break; }
    memoryASet16(ds, 0x5cdc, r16[si]);
    r16[di] = 0x2426;
    yield* sub_10590();
  case 0x11c0d:
    r16[si] = memoryAGet16(es, r16[bx] + 456);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cde))
        { pc = 0x11c26; break; }
    memoryASet16(ds, 0x5cde, r16[si]);
    r16[di] = 0x2428;
    yield* sub_10590();
  case 0x11c26:
    r16[si] = memoryAGet16(es, r16[bx] + 458);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ce0))
        { pc = 0x11c3f; break; }
    memoryASet16(ds, 0x5ce0, r16[si]);
    r16[di] = 0x242a;
    yield* sub_10590();
  case 0x11c3f:
    r16[si] = memoryAGet16(es, r16[bx] + 460);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ce2))
        { pc = 0x11c58; break; }
    memoryASet16(ds, 0x5ce2, r16[si]);
    r16[di] = 0x242c;
    yield* sub_10590();
  case 0x11c58:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 462);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ce4))
        { pc = 0x11c75; break; }
    memoryASet16(ds, 0x5ce4, r16[si]);
    r16[di] = 0x2704;
    yield* sub_10590();
  case 0x11c75:
    r16[si] = memoryAGet16(es, r16[bx] + 464);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ce6))
        { pc = 0x11c8e; break; }
    memoryASet16(ds, 0x5ce6, r16[si]);
    r16[di] = 0x2706;
    yield* sub_10590();
  case 0x11c8e:
    r16[si] = memoryAGet16(es, r16[bx] + 466);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ce8))
        { pc = 0x11ca7; break; }
    memoryASet16(ds, 0x5ce8, r16[si]);
    r16[di] = 0x2708;
    yield* sub_10590();
  case 0x11ca7:
    r16[si] = memoryAGet16(es, r16[bx] + 468);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cea))
        { pc = 0x11cc0; break; }
    memoryASet16(ds, 0x5cea, r16[si]);
    r16[di] = 0x270a;
    yield* sub_10590();
  case 0x11cc0:
    r16[si] = memoryAGet16(es, r16[bx] + 470);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cec))
        { pc = 0x11cd9; break; }
    memoryASet16(ds, 0x5cec, r16[si]);
    r16[di] = 0x270c;
    yield* sub_10590();
  case 0x11cd9:
    r16[si] = memoryAGet16(es, r16[bx] + 472);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cee))
        { pc = 0x11cf2; break; }
    memoryASet16(ds, 0x5cee, r16[si]);
    r16[di] = 0x270e;
    yield* sub_10590();
  case 0x11cf2:
    r16[si] = memoryAGet16(es, r16[bx] + 474);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cf0))
        { pc = 0x11d0b; break; }
    memoryASet16(ds, 0x5cf0, r16[si]);
    r16[di] = 0x2710;
    yield* sub_10590();
  case 0x11d0b:
    r16[si] = memoryAGet16(es, r16[bx] + 476);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cf2))
        { pc = 0x11d24; break; }
    memoryASet16(ds, 0x5cf2, r16[si]);
    r16[di] = 0x2712;
    yield* sub_10590();
  case 0x11d24:
    r16[si] = memoryAGet16(es, r16[bx] + 478);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cf4))
        { pc = 0x11d3d; break; }
    memoryASet16(ds, 0x5cf4, r16[si]);
    r16[di] = 0x2714;
    yield* sub_10590();
  case 0x11d3d:
    r16[si] = memoryAGet16(es, r16[bx] + 480);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cf6))
        { pc = 0x11d56; break; }
    memoryASet16(ds, 0x5cf6, r16[si]);
    r16[di] = 0x2716;
    yield* sub_10590();
  case 0x11d56:
    r16[si] = memoryAGet16(es, r16[bx] + 482);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cf8))
        { pc = 0x11d6f; break; }
    memoryASet16(ds, 0x5cf8, r16[si]);
    r16[di] = 0x2718;
    yield* sub_10590();
  case 0x11d6f:
    r16[si] = memoryAGet16(es, r16[bx] + 484);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cfa))
        { pc = 0x11d88; break; }
    memoryASet16(ds, 0x5cfa, r16[si]);
    r16[di] = 0x271a;
    yield* sub_10590();
  case 0x11d88:
    r16[si] = memoryAGet16(es, r16[bx] + 486);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cfc))
        { pc = 0x11da1; break; }
    memoryASet16(ds, 0x5cfc, r16[si]);
    r16[di] = 0x271c;
    yield* sub_10590();
  case 0x11da1:
    r16[si] = memoryAGet16(es, r16[bx] + 488);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5cfe))
        { pc = 0x11dba; break; }
    memoryASet16(ds, 0x5cfe, r16[si]);
    r16[di] = 0x271e;
    yield* sub_10590();
  case 0x11dba:
    r16[si] = memoryAGet16(es, r16[bx] + 490);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d00))
        { pc = 0x11dd3; break; }
    memoryASet16(ds, 0x5d00, r16[si]);
    r16[di] = 0x2720;
    yield* sub_10590();
  case 0x11dd3:
    r16[si] = memoryAGet16(es, r16[bx] + 492);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d02))
        { pc = 0x11dec; break; }
    memoryASet16(ds, 0x5d02, r16[si]);
    r16[di] = 0x2722;
    yield* sub_10590();
  case 0x11dec:
    r16[si] = memoryAGet16(es, r16[bx] + 494);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d04))
        { pc = 0x11e05; break; }
    memoryASet16(ds, 0x5d04, r16[si]);
    r16[di] = 0x2724;
    yield* sub_10590();
  case 0x11e05:
    r16[si] = memoryAGet16(es, r16[bx] + 496);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d06))
        { pc = 0x11e1e; break; }
    memoryASet16(ds, 0x5d06, r16[si]);
    r16[di] = 0x2726;
    yield* sub_10590();
  case 0x11e1e:
    r16[si] = memoryAGet16(es, r16[bx] + 498);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d08))
        { pc = 0x11e37; break; }
    memoryASet16(ds, 0x5d08, r16[si]);
    r16[di] = 0x2728;
    yield* sub_10590();
  case 0x11e37:
    r16[si] = memoryAGet16(es, r16[bx] + 500);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d0a))
        { pc = 0x11e50; break; }
    memoryASet16(ds, 0x5d0a, r16[si]);
    r16[di] = 0x272a;
    yield* sub_10590();
  case 0x11e50:
    r16[si] = memoryAGet16(es, r16[bx] + 502);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d0c))
        { pc = 0x11e69; break; }
    memoryASet16(ds, 0x5d0c, r16[si]);
    r16[di] = 0x272c;
    yield* sub_10590();
  case 0x11e69:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 504);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d0e))
        { pc = 0x11e86; break; }
    memoryASet16(ds, 0x5d0e, r16[si]);
    r16[di] = 0x2a04;
    yield* sub_10590();
  case 0x11e86:
    r16[si] = memoryAGet16(es, r16[bx] + 506);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d10))
        { pc = 0x11e9f; break; }
    memoryASet16(ds, 0x5d10, r16[si]);
    r16[di] = 0x2a06;
    yield* sub_10590();
  case 0x11e9f:
    r16[si] = memoryAGet16(es, r16[bx] + 508);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d12))
        { pc = 0x11eb8; break; }
    memoryASet16(ds, 0x5d12, r16[si]);
    r16[di] = 0x2a08;
    yield* sub_10590();
  case 0x11eb8:
    r16[si] = memoryAGet16(es, r16[bx] + 510);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d14))
        { pc = 0x11ed1; break; }
    memoryASet16(ds, 0x5d14, r16[si]);
    r16[di] = 0x2a0a;
    yield* sub_10590();
  case 0x11ed1:
    r16[si] = memoryAGet16(es, r16[bx] + 512);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d16))
        { pc = 0x11eea; break; }
    memoryASet16(ds, 0x5d16, r16[si]);
    r16[di] = 0x2a0c;
    yield* sub_10590();
  case 0x11eea:
    r16[si] = memoryAGet16(es, r16[bx] + 514);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d18))
        { pc = 0x11f03; break; }
    memoryASet16(ds, 0x5d18, r16[si]);
    r16[di] = 0x2a0e;
    yield* sub_10590();
  case 0x11f03:
    r16[si] = memoryAGet16(es, r16[bx] + 516);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d1a))
        { pc = 0x11f1c; break; }
    memoryASet16(ds, 0x5d1a, r16[si]);
    r16[di] = 0x2a10;
    yield* sub_10590();
  case 0x11f1c:
    r16[si] = memoryAGet16(es, r16[bx] + 518);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d1c))
        { pc = 0x11f35; break; }
    memoryASet16(ds, 0x5d1c, r16[si]);
    r16[di] = 0x2a12;
    yield* sub_10590();
  case 0x11f35:
    r16[si] = memoryAGet16(es, r16[bx] + 520);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d1e))
        { pc = 0x11f4e; break; }
    memoryASet16(ds, 0x5d1e, r16[si]);
    r16[di] = 0x2a14;
    yield* sub_10590();
  case 0x11f4e:
    r16[si] = memoryAGet16(es, r16[bx] + 522);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d20))
        { pc = 0x11f67; break; }
    memoryASet16(ds, 0x5d20, r16[si]);
    r16[di] = 0x2a16;
    yield* sub_10590();
  case 0x11f67:
    r16[si] = memoryAGet16(es, r16[bx] + 524);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d22))
        { pc = 0x11f80; break; }
    memoryASet16(ds, 0x5d22, r16[si]);
    r16[di] = 0x2a18;
    yield* sub_10590();
  case 0x11f80:
    r16[si] = memoryAGet16(es, r16[bx] + 526);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d24))
        { pc = 0x11f99; break; }
    memoryASet16(ds, 0x5d24, r16[si]);
    r16[di] = 0x2a1a;
    yield* sub_10590();
  case 0x11f99:
    r16[si] = memoryAGet16(es, r16[bx] + 528);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d26))
        { pc = 0x11fb2; break; }
    memoryASet16(ds, 0x5d26, r16[si]);
    r16[di] = 0x2a1c;
    yield* sub_10590();
  case 0x11fb2:
    r16[si] = memoryAGet16(es, r16[bx] + 530);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d28))
        { pc = 0x11fcb; break; }
    memoryASet16(ds, 0x5d28, r16[si]);
    r16[di] = 0x2a1e;
    yield* sub_10590();
  case 0x11fcb:
    r16[si] = memoryAGet16(es, r16[bx] + 532);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d2a))
        { pc = 0x11fe4; break; }
    memoryASet16(ds, 0x5d2a, r16[si]);
    r16[di] = 0x2a20;
    yield* sub_10590();
  case 0x11fe4:
    r16[si] = memoryAGet16(es, r16[bx] + 534);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d2c))
        { pc = 0x11ffd; break; }
    memoryASet16(ds, 0x5d2c, r16[si]);
    r16[di] = 0x2a22;
    yield* sub_10590();
  case 0x11ffd:
    r16[si] = memoryAGet16(es, r16[bx] + 536);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d2e))
        { pc = 0x12016; break; }
    memoryASet16(ds, 0x5d2e, r16[si]);
    r16[di] = 0x2a24;
    yield* sub_10590();
  case 0x12016:
    r16[si] = memoryAGet16(es, r16[bx] + 538);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d30))
        { pc = 0x1202f; break; }
    memoryASet16(ds, 0x5d30, r16[si]);
    r16[di] = 0x2a26;
    yield* sub_10590();
  case 0x1202f:
    r16[si] = memoryAGet16(es, r16[bx] + 540);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d32))
        { pc = 0x12048; break; }
    memoryASet16(ds, 0x5d32, r16[si]);
    r16[di] = 0x2a28;
    yield* sub_10590();
  case 0x12048:
    r16[si] = memoryAGet16(es, r16[bx] + 542);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d34))
        { pc = 0x12061; break; }
    memoryASet16(ds, 0x5d34, r16[si]);
    r16[di] = 0x2a2a;
    yield* sub_10590();
  case 0x12061:
    r16[si] = memoryAGet16(es, r16[bx] + 544);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d36))
        { pc = 0x1207a; break; }
    memoryASet16(ds, 0x5d36, r16[si]);
    r16[di] = 0x2a2c;
    yield* sub_10590();
  case 0x1207a:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 546);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d38))
        { pc = 0x12097; break; }
    memoryASet16(ds, 0x5d38, r16[si]);
    r16[di] = 0x2d04;
    yield* sub_10590();
  case 0x12097:
    r16[si] = memoryAGet16(es, r16[bx] + 548);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d3a))
        { pc = 0x120b0; break; }
    memoryASet16(ds, 0x5d3a, r16[si]);
    r16[di] = 0x2d06;
    yield* sub_10590();
  case 0x120b0:
    r16[si] = memoryAGet16(es, r16[bx] + 550);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d3c))
        { pc = 0x120c9; break; }
    memoryASet16(ds, 0x5d3c, r16[si]);
    r16[di] = 0x2d08;
    yield* sub_10590();
  case 0x120c9:
    r16[si] = memoryAGet16(es, r16[bx] + 552);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d3e))
        { pc = 0x120e2; break; }
    memoryASet16(ds, 0x5d3e, r16[si]);
    r16[di] = 0x2d0a;
    yield* sub_10590();
  case 0x120e2:
    r16[si] = memoryAGet16(es, r16[bx] + 554);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d40))
        { pc = 0x120fb; break; }
    memoryASet16(ds, 0x5d40, r16[si]);
    r16[di] = 0x2d0c;
    yield* sub_10590();
  case 0x120fb:
    r16[si] = memoryAGet16(es, r16[bx] + 556);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d42))
        { pc = 0x12114; break; }
    memoryASet16(ds, 0x5d42, r16[si]);
    r16[di] = 0x2d0e;
    yield* sub_10590();
  case 0x12114:
    r16[si] = memoryAGet16(es, r16[bx] + 558);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d44))
        { pc = 0x1212d; break; }
    memoryASet16(ds, 0x5d44, r16[si]);
    r16[di] = 0x2d10;
    yield* sub_10590();
  case 0x1212d:
    r16[si] = memoryAGet16(es, r16[bx] + 560);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d46))
        { pc = 0x12146; break; }
    memoryASet16(ds, 0x5d46, r16[si]);
    r16[di] = 0x2d12;
    yield* sub_10590();
  case 0x12146:
    r16[si] = memoryAGet16(es, r16[bx] + 562);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d48))
        { pc = 0x1215f; break; }
    memoryASet16(ds, 0x5d48, r16[si]);
    r16[di] = 0x2d14;
    yield* sub_10590();
  case 0x1215f:
    r16[si] = memoryAGet16(es, r16[bx] + 564);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d4a))
        { pc = 0x12178; break; }
    memoryASet16(ds, 0x5d4a, r16[si]);
    r16[di] = 0x2d16;
    yield* sub_10590();
  case 0x12178:
    r16[si] = memoryAGet16(es, r16[bx] + 566);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d4c))
        { pc = 0x12191; break; }
    memoryASet16(ds, 0x5d4c, r16[si]);
    r16[di] = 0x2d18;
    yield* sub_10590();
  case 0x12191:
    r16[si] = memoryAGet16(es, r16[bx] + 568);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d4e))
        { pc = 0x121aa; break; }
    memoryASet16(ds, 0x5d4e, r16[si]);
    r16[di] = 0x2d1a;
    yield* sub_10590();
  case 0x121aa:
    r16[si] = memoryAGet16(es, r16[bx] + 570);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d50))
        { pc = 0x121c3; break; }
    memoryASet16(ds, 0x5d50, r16[si]);
    r16[di] = 0x2d1c;
    yield* sub_10590();
  case 0x121c3:
    r16[si] = memoryAGet16(es, r16[bx] + 572);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d52))
        { pc = 0x121dc; break; }
    memoryASet16(ds, 0x5d52, r16[si]);
    r16[di] = 0x2d1e;
    yield* sub_10590();
  case 0x121dc:
    r16[si] = memoryAGet16(es, r16[bx] + 574);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d54))
        { pc = 0x121f5; break; }
    memoryASet16(ds, 0x5d54, r16[si]);
    r16[di] = 0x2d20;
    yield* sub_10590();
  case 0x121f5:
    r16[si] = memoryAGet16(es, r16[bx] + 576);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d56))
        { pc = 0x1220e; break; }
    memoryASet16(ds, 0x5d56, r16[si]);
    r16[di] = 0x2d22;
    yield* sub_10590();
  case 0x1220e:
    r16[si] = memoryAGet16(es, r16[bx] + 578);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d58))
        { pc = 0x12227; break; }
    memoryASet16(ds, 0x5d58, r16[si]);
    r16[di] = 0x2d24;
    yield* sub_10590();
  case 0x12227:
    r16[si] = memoryAGet16(es, r16[bx] + 580);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d5a))
        { pc = 0x12240; break; }
    memoryASet16(ds, 0x5d5a, r16[si]);
    r16[di] = 0x2d26;
    yield* sub_10590();
  case 0x12240:
    r16[si] = memoryAGet16(es, r16[bx] + 582);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d5c))
        { pc = 0x12259; break; }
    memoryASet16(ds, 0x5d5c, r16[si]);
    r16[di] = 0x2d28;
    yield* sub_10590();
  case 0x12259:
    r16[si] = memoryAGet16(es, r16[bx] + 584);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d5e))
        { pc = 0x12272; break; }
    memoryASet16(ds, 0x5d5e, r16[si]);
    r16[di] = 0x2d2a;
    yield* sub_10590();
  case 0x12272:
    r16[si] = memoryAGet16(es, r16[bx] + 586);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5d60))
        { pc = 0x1228b; break; }
    memoryASet16(ds, 0x5d60, r16[si]);
    r16[di] = 0x2d2c;
    yield* sub_10590();
  case 0x1228b:
    r16[bx] += memoryAGet16(ds, 0x5654);
    sp += 2; cs = pop();
    return;
  }
}
function* sub_12290() // 1059:1d00 +far +stackDrop2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[dx] = 0x002e;
    r16[cx] = es;
    r16[si] = memoryAGet16(es, r16[bx]);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5db8))
        { pc = 0x122ac; break; }
    memoryASet16(ds, 0x5db8, r16[si]);
    r16[di] = 0x0604;
    yield* sub_10590();
  case 0x122ac:
    r16[si] = memoryAGet16(es, r16[bx] + 2);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dba))
        { pc = 0x122c4; break; }
    memoryASet16(ds, 0x5dba, r16[si]);
    r16[di] = 0x0606;
    yield* sub_10590();
  case 0x122c4:
    r16[si] = memoryAGet16(es, r16[bx] + 4);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dbc))
        { pc = 0x122dc; break; }
    memoryASet16(ds, 0x5dbc, r16[si]);
    r16[di] = 0x0608;
    yield* sub_10590();
  case 0x122dc:
    r16[si] = memoryAGet16(es, r16[bx] + 6);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dbe))
        { pc = 0x122f4; break; }
    memoryASet16(ds, 0x5dbe, r16[si]);
    r16[di] = 0x060a;
    yield* sub_10590();
  case 0x122f4:
    r16[si] = memoryAGet16(es, r16[bx] + 8);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dc0))
        { pc = 0x1230c; break; }
    memoryASet16(ds, 0x5dc0, r16[si]);
    r16[di] = 0x060c;
    yield* sub_10590();
  case 0x1230c:
    r16[si] = memoryAGet16(es, r16[bx] + 10);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dc2))
        { pc = 0x12324; break; }
    memoryASet16(ds, 0x5dc2, r16[si]);
    r16[di] = 0x060e;
    yield* sub_10590();
  case 0x12324:
    r16[si] = memoryAGet16(es, r16[bx] + 12);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dc4))
        { pc = 0x1233c; break; }
    memoryASet16(ds, 0x5dc4, r16[si]);
    r16[di] = 0x0610;
    yield* sub_10590();
  case 0x1233c:
    r16[si] = memoryAGet16(es, r16[bx] + 14);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dc6))
        { pc = 0x12354; break; }
    memoryASet16(ds, 0x5dc6, r16[si]);
    r16[di] = 0x0612;
    yield* sub_10590();
  case 0x12354:
    r16[si] = memoryAGet16(es, r16[bx] + 16);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dc8))
        { pc = 0x1236c; break; }
    memoryASet16(ds, 0x5dc8, r16[si]);
    r16[di] = 0x0614;
    yield* sub_10590();
  case 0x1236c:
    r16[si] = memoryAGet16(es, r16[bx] + 18);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dca))
        { pc = 0x12384; break; }
    memoryASet16(ds, 0x5dca, r16[si]);
    r16[di] = 0x0616;
    yield* sub_10590();
  case 0x12384:
    r16[si] = memoryAGet16(es, r16[bx] + 20);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dcc))
        { pc = 0x1239c; break; }
    memoryASet16(ds, 0x5dcc, r16[si]);
    r16[di] = 0x0618;
    yield* sub_10590();
  case 0x1239c:
    r16[si] = memoryAGet16(es, r16[bx] + 22);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dce))
        { pc = 0x123b4; break; }
    memoryASet16(ds, 0x5dce, r16[si]);
    r16[di] = 0x061a;
    yield* sub_10590();
  case 0x123b4:
    r16[si] = memoryAGet16(es, r16[bx] + 24);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dd0))
        { pc = 0x123cc; break; }
    memoryASet16(ds, 0x5dd0, r16[si]);
    r16[di] = 0x061c;
    yield* sub_10590();
  case 0x123cc:
    r16[si] = memoryAGet16(es, r16[bx] + 26);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dd2))
        { pc = 0x123e4; break; }
    memoryASet16(ds, 0x5dd2, r16[si]);
    r16[di] = 0x061e;
    yield* sub_10590();
  case 0x123e4:
    r16[si] = memoryAGet16(es, r16[bx] + 28);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dd4))
        { pc = 0x123fc; break; }
    memoryASet16(ds, 0x5dd4, r16[si]);
    r16[di] = 0x0620;
    yield* sub_10590();
  case 0x123fc:
    r16[si] = memoryAGet16(es, r16[bx] + 30);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dd6))
        { pc = 0x12414; break; }
    memoryASet16(ds, 0x5dd6, r16[si]);
    r16[di] = 0x0622;
    yield* sub_10590();
  case 0x12414:
    r16[si] = memoryAGet16(es, r16[bx] + 32);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dd8))
        { pc = 0x1242c; break; }
    memoryASet16(ds, 0x5dd8, r16[si]);
    r16[di] = 0x0624;
    yield* sub_10590();
  case 0x1242c:
    r16[si] = memoryAGet16(es, r16[bx] + 34);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dda))
        { pc = 0x12444; break; }
    memoryASet16(ds, 0x5dda, r16[si]);
    r16[di] = 0x0626;
    yield* sub_10590();
  case 0x12444:
    r16[si] = memoryAGet16(es, r16[bx] + 36);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ddc))
        { pc = 0x1245c; break; }
    memoryASet16(ds, 0x5ddc, r16[si]);
    r16[di] = 0x0628;
    yield* sub_10590();
  case 0x1245c:
    r16[si] = memoryAGet16(es, r16[bx] + 38);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dde))
        { pc = 0x12474; break; }
    memoryASet16(ds, 0x5dde, r16[si]);
    r16[di] = 0x062a;
    yield* sub_10590();
  case 0x12474:
    r16[si] = memoryAGet16(es, r16[bx] + 40);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5de0))
        { pc = 0x1248c; break; }
    memoryASet16(ds, 0x5de0, r16[si]);
    r16[di] = 0x062c;
    yield* sub_10590();
  case 0x1248c:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 42);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5de2))
        { pc = 0x124a8; break; }
    memoryASet16(ds, 0x5de2, r16[si]);
    r16[di] = 0x0904;
    yield* sub_10590();
  case 0x124a8:
    r16[si] = memoryAGet16(es, r16[bx] + 44);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5de4))
        { pc = 0x124c0; break; }
    memoryASet16(ds, 0x5de4, r16[si]);
    r16[di] = 0x0906;
    yield* sub_10590();
  case 0x124c0:
    r16[si] = memoryAGet16(es, r16[bx] + 46);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5de6))
        { pc = 0x124d8; break; }
    memoryASet16(ds, 0x5de6, r16[si]);
    r16[di] = 0x0908;
    yield* sub_10590();
  case 0x124d8:
    r16[si] = memoryAGet16(es, r16[bx] + 48);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5de8))
        { pc = 0x124f0; break; }
    memoryASet16(ds, 0x5de8, r16[si]);
    r16[di] = 0x090a;
    yield* sub_10590();
  case 0x124f0:
    r16[si] = memoryAGet16(es, r16[bx] + 50);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dea))
        { pc = 0x12508; break; }
    memoryASet16(ds, 0x5dea, r16[si]);
    r16[di] = 0x090c;
    yield* sub_10590();
  case 0x12508:
    r16[si] = memoryAGet16(es, r16[bx] + 52);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dec))
        { pc = 0x12520; break; }
    memoryASet16(ds, 0x5dec, r16[si]);
    r16[di] = 0x090e;
    yield* sub_10590();
  case 0x12520:
    r16[si] = memoryAGet16(es, r16[bx] + 54);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dee))
        { pc = 0x12538; break; }
    memoryASet16(ds, 0x5dee, r16[si]);
    r16[di] = 0x0910;
    yield* sub_10590();
  case 0x12538:
    r16[si] = memoryAGet16(es, r16[bx] + 56);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5df0))
        { pc = 0x12550; break; }
    memoryASet16(ds, 0x5df0, r16[si]);
    r16[di] = 0x0912;
    yield* sub_10590();
  case 0x12550:
    r16[si] = memoryAGet16(es, r16[bx] + 58);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5df2))
        { pc = 0x12568; break; }
    memoryASet16(ds, 0x5df2, r16[si]);
    r16[di] = 0x0914;
    yield* sub_10590();
  case 0x12568:
    r16[si] = memoryAGet16(es, r16[bx] + 60);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5df4))
        { pc = 0x12580; break; }
    memoryASet16(ds, 0x5df4, r16[si]);
    r16[di] = 0x0916;
    yield* sub_10590();
  case 0x12580:
    r16[si] = memoryAGet16(es, r16[bx] + 62);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5df6))
        { pc = 0x12598; break; }
    memoryASet16(ds, 0x5df6, r16[si]);
    r16[di] = 0x0918;
    yield* sub_10590();
  case 0x12598:
    r16[si] = memoryAGet16(es, r16[bx] + 64);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5df8))
        { pc = 0x125b0; break; }
    memoryASet16(ds, 0x5df8, r16[si]);
    r16[di] = 0x091a;
    yield* sub_10590();
  case 0x125b0:
    r16[si] = memoryAGet16(es, r16[bx] + 66);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dfa))
        { pc = 0x125c8; break; }
    memoryASet16(ds, 0x5dfa, r16[si]);
    r16[di] = 0x091c;
    yield* sub_10590();
  case 0x125c8:
    r16[si] = memoryAGet16(es, r16[bx] + 68);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dfc))
        { pc = 0x125e0; break; }
    memoryASet16(ds, 0x5dfc, r16[si]);
    r16[di] = 0x091e;
    yield* sub_10590();
  case 0x125e0:
    r16[si] = memoryAGet16(es, r16[bx] + 70);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5dfe))
        { pc = 0x125f8; break; }
    memoryASet16(ds, 0x5dfe, r16[si]);
    r16[di] = 0x0920;
    yield* sub_10590();
  case 0x125f8:
    r16[si] = memoryAGet16(es, r16[bx] + 72);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e00))
        { pc = 0x12610; break; }
    memoryASet16(ds, 0x5e00, r16[si]);
    r16[di] = 0x0922;
    yield* sub_10590();
  case 0x12610:
    r16[si] = memoryAGet16(es, r16[bx] + 74);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e02))
        { pc = 0x12628; break; }
    memoryASet16(ds, 0x5e02, r16[si]);
    r16[di] = 0x0924;
    yield* sub_10590();
  case 0x12628:
    r16[si] = memoryAGet16(es, r16[bx] + 76);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e04))
        { pc = 0x12640; break; }
    memoryASet16(ds, 0x5e04, r16[si]);
    r16[di] = 0x0926;
    yield* sub_10590();
  case 0x12640:
    r16[si] = memoryAGet16(es, r16[bx] + 78);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e06))
        { pc = 0x12658; break; }
    memoryASet16(ds, 0x5e06, r16[si]);
    r16[di] = 0x0928;
    yield* sub_10590();
  case 0x12658:
    r16[si] = memoryAGet16(es, r16[bx] + 80);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e08))
        { pc = 0x12670; break; }
    memoryASet16(ds, 0x5e08, r16[si]);
    r16[di] = 0x092a;
    yield* sub_10590();
  case 0x12670:
    r16[si] = memoryAGet16(es, r16[bx] + 82);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e0a))
        { pc = 0x12688; break; }
    memoryASet16(ds, 0x5e0a, r16[si]);
    r16[di] = 0x092c;
    yield* sub_10590();
  case 0x12688:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 84);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e0c))
        { pc = 0x126a4; break; }
    memoryASet16(ds, 0x5e0c, r16[si]);
    r16[di] = 0x0c04;
    yield* sub_10590();
  case 0x126a4:
    r16[si] = memoryAGet16(es, r16[bx] + 86);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e0e))
        { pc = 0x126bc; break; }
    memoryASet16(ds, 0x5e0e, r16[si]);
    r16[di] = 0x0c06;
    yield* sub_10590();
  case 0x126bc:
    r16[si] = memoryAGet16(es, r16[bx] + 88);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e10))
        { pc = 0x126d4; break; }
    memoryASet16(ds, 0x5e10, r16[si]);
    r16[di] = 0x0c08;
    yield* sub_10590();
  case 0x126d4:
    r16[si] = memoryAGet16(es, r16[bx] + 90);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e12))
        { pc = 0x126ec; break; }
    memoryASet16(ds, 0x5e12, r16[si]);
    r16[di] = 0x0c0a;
    yield* sub_10590();
  case 0x126ec:
    r16[si] = memoryAGet16(es, r16[bx] + 92);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e14))
        { pc = 0x12704; break; }
    memoryASet16(ds, 0x5e14, r16[si]);
    r16[di] = 0x0c0c;
    yield* sub_10590();
  case 0x12704:
    r16[si] = memoryAGet16(es, r16[bx] + 94);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e16))
        { pc = 0x1271c; break; }
    memoryASet16(ds, 0x5e16, r16[si]);
    r16[di] = 0x0c0e;
    yield* sub_10590();
  case 0x1271c:
    r16[si] = memoryAGet16(es, r16[bx] + 96);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e18))
        { pc = 0x12734; break; }
    memoryASet16(ds, 0x5e18, r16[si]);
    r16[di] = 0x0c10;
    yield* sub_10590();
  case 0x12734:
    r16[si] = memoryAGet16(es, r16[bx] + 98);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e1a))
        { pc = 0x1274c; break; }
    memoryASet16(ds, 0x5e1a, r16[si]);
    r16[di] = 0x0c12;
    yield* sub_10590();
  case 0x1274c:
    r16[si] = memoryAGet16(es, r16[bx] + 100);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e1c))
        { pc = 0x12764; break; }
    memoryASet16(ds, 0x5e1c, r16[si]);
    r16[di] = 0x0c14;
    yield* sub_10590();
  case 0x12764:
    r16[si] = memoryAGet16(es, r16[bx] + 102);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e1e))
        { pc = 0x1277c; break; }
    memoryASet16(ds, 0x5e1e, r16[si]);
    r16[di] = 0x0c16;
    yield* sub_10590();
  case 0x1277c:
    r16[si] = memoryAGet16(es, r16[bx] + 104);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e20))
        { pc = 0x12794; break; }
    memoryASet16(ds, 0x5e20, r16[si]);
    r16[di] = 0x0c18;
    yield* sub_10590();
  case 0x12794:
    r16[si] = memoryAGet16(es, r16[bx] + 106);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e22))
        { pc = 0x127ac; break; }
    memoryASet16(ds, 0x5e22, r16[si]);
    r16[di] = 0x0c1a;
    yield* sub_10590();
  case 0x127ac:
    r16[si] = memoryAGet16(es, r16[bx] + 108);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e24))
        { pc = 0x127c4; break; }
    memoryASet16(ds, 0x5e24, r16[si]);
    r16[di] = 0x0c1c;
    yield* sub_10590();
  case 0x127c4:
    r16[si] = memoryAGet16(es, r16[bx] + 110);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e26))
        { pc = 0x127dc; break; }
    memoryASet16(ds, 0x5e26, r16[si]);
    r16[di] = 0x0c1e;
    yield* sub_10590();
  case 0x127dc:
    r16[si] = memoryAGet16(es, r16[bx] + 112);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e28))
        { pc = 0x127f4; break; }
    memoryASet16(ds, 0x5e28, r16[si]);
    r16[di] = 0x0c20;
    yield* sub_10590();
  case 0x127f4:
    r16[si] = memoryAGet16(es, r16[bx] + 114);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e2a))
        { pc = 0x1280c; break; }
    memoryASet16(ds, 0x5e2a, r16[si]);
    r16[di] = 0x0c22;
    yield* sub_10590();
  case 0x1280c:
    r16[si] = memoryAGet16(es, r16[bx] + 116);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e2c))
        { pc = 0x12824; break; }
    memoryASet16(ds, 0x5e2c, r16[si]);
    r16[di] = 0x0c24;
    yield* sub_10590();
  case 0x12824:
    r16[si] = memoryAGet16(es, r16[bx] + 118);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e2e))
        { pc = 0x1283c; break; }
    memoryASet16(ds, 0x5e2e, r16[si]);
    r16[di] = 0x0c26;
    yield* sub_10590();
  case 0x1283c:
    r16[si] = memoryAGet16(es, r16[bx] + 120);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e30))
        { pc = 0x12854; break; }
    memoryASet16(ds, 0x5e30, r16[si]);
    r16[di] = 0x0c28;
    yield* sub_10590();
  case 0x12854:
    r16[si] = memoryAGet16(es, r16[bx] + 122);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e32))
        { pc = 0x1286c; break; }
    memoryASet16(ds, 0x5e32, r16[si]);
    r16[di] = 0x0c2a;
    yield* sub_10590();
  case 0x1286c:
    r16[si] = memoryAGet16(es, r16[bx] + 124);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e34))
        { pc = 0x12884; break; }
    memoryASet16(ds, 0x5e34, r16[si]);
    r16[di] = 0x0c2c;
    yield* sub_10590();
  case 0x12884:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 126);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e36))
        { pc = 0x128a0; break; }
    memoryASet16(ds, 0x5e36, r16[si]);
    r16[di] = 0x0f04;
    yield* sub_10590();
  case 0x128a0:
    r16[si] = memoryAGet16(es, r16[bx] + 128);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e38))
        { pc = 0x128b9; break; }
    memoryASet16(ds, 0x5e38, r16[si]);
    r16[di] = 0x0f06;
    yield* sub_10590();
  case 0x128b9:
    r16[si] = memoryAGet16(es, r16[bx] + 130);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e3a))
        { pc = 0x128d2; break; }
    memoryASet16(ds, 0x5e3a, r16[si]);
    r16[di] = 0x0f08;
    yield* sub_10590();
  case 0x128d2:
    r16[si] = memoryAGet16(es, r16[bx] + 132);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e3c))
        { pc = 0x128eb; break; }
    memoryASet16(ds, 0x5e3c, r16[si]);
    r16[di] = 0x0f0a;
    yield* sub_10590();
  case 0x128eb:
    r16[si] = memoryAGet16(es, r16[bx] + 134);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e3e))
        { pc = 0x12904; break; }
    memoryASet16(ds, 0x5e3e, r16[si]);
    r16[di] = 0x0f0c;
    yield* sub_10590();
  case 0x12904:
    r16[si] = memoryAGet16(es, r16[bx] + 136);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e40))
        { pc = 0x1291d; break; }
    memoryASet16(ds, 0x5e40, r16[si]);
    r16[di] = 0x0f0e;
    yield* sub_10590();
  case 0x1291d:
    r16[si] = memoryAGet16(es, r16[bx] + 138);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e42))
        { pc = 0x12936; break; }
    memoryASet16(ds, 0x5e42, r16[si]);
    r16[di] = 0x0f10;
    yield* sub_10590();
  case 0x12936:
    r16[si] = memoryAGet16(es, r16[bx] + 140);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e44))
        { pc = 0x1294f; break; }
    memoryASet16(ds, 0x5e44, r16[si]);
    r16[di] = 0x0f12;
    yield* sub_10590();
  case 0x1294f:
    r16[si] = memoryAGet16(es, r16[bx] + 142);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e46))
        { pc = 0x12968; break; }
    memoryASet16(ds, 0x5e46, r16[si]);
    r16[di] = 0x0f14;
    yield* sub_10590();
  case 0x12968:
    r16[si] = memoryAGet16(es, r16[bx] + 144);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e48))
        { pc = 0x12981; break; }
    memoryASet16(ds, 0x5e48, r16[si]);
    r16[di] = 0x0f16;
    yield* sub_10590();
  case 0x12981:
    r16[si] = memoryAGet16(es, r16[bx] + 146);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e4a))
        { pc = 0x1299a; break; }
    memoryASet16(ds, 0x5e4a, r16[si]);
    r16[di] = 0x0f18;
    yield* sub_10590();
  case 0x1299a:
    r16[si] = memoryAGet16(es, r16[bx] + 148);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e4c))
        { pc = 0x129b3; break; }
    memoryASet16(ds, 0x5e4c, r16[si]);
    r16[di] = 0x0f1a;
    yield* sub_10590();
  case 0x129b3:
    r16[si] = memoryAGet16(es, r16[bx] + 150);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e4e))
        { pc = 0x129cc; break; }
    memoryASet16(ds, 0x5e4e, r16[si]);
    r16[di] = 0x0f1c;
    yield* sub_10590();
  case 0x129cc:
    r16[si] = memoryAGet16(es, r16[bx] + 152);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e50))
        { pc = 0x129e5; break; }
    memoryASet16(ds, 0x5e50, r16[si]);
    r16[di] = 0x0f1e;
    yield* sub_10590();
  case 0x129e5:
    r16[si] = memoryAGet16(es, r16[bx] + 154);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e52))
        { pc = 0x129fe; break; }
    memoryASet16(ds, 0x5e52, r16[si]);
    r16[di] = 0x0f20;
    yield* sub_10590();
  case 0x129fe:
    r16[si] = memoryAGet16(es, r16[bx] + 156);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e54))
        { pc = 0x12a17; break; }
    memoryASet16(ds, 0x5e54, r16[si]);
    r16[di] = 0x0f22;
    yield* sub_10590();
  case 0x12a17:
    r16[si] = memoryAGet16(es, r16[bx] + 158);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e56))
        { pc = 0x12a30; break; }
    memoryASet16(ds, 0x5e56, r16[si]);
    r16[di] = 0x0f24;
    yield* sub_10590();
  case 0x12a30:
    r16[si] = memoryAGet16(es, r16[bx] + 160);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e58))
        { pc = 0x12a49; break; }
    memoryASet16(ds, 0x5e58, r16[si]);
    r16[di] = 0x0f26;
    yield* sub_10590();
  case 0x12a49:
    r16[si] = memoryAGet16(es, r16[bx] + 162);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e5a))
        { pc = 0x12a62; break; }
    memoryASet16(ds, 0x5e5a, r16[si]);
    r16[di] = 0x0f28;
    yield* sub_10590();
  case 0x12a62:
    r16[si] = memoryAGet16(es, r16[bx] + 164);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e5c))
        { pc = 0x12a7b; break; }
    memoryASet16(ds, 0x5e5c, r16[si]);
    r16[di] = 0x0f2a;
    yield* sub_10590();
  case 0x12a7b:
    r16[si] = memoryAGet16(es, r16[bx] + 166);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e5e))
        { pc = 0x12a94; break; }
    memoryASet16(ds, 0x5e5e, r16[si]);
    r16[di] = 0x0f2c;
    yield* sub_10590();
  case 0x12a94:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 168);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e60))
        { pc = 0x12ab1; break; }
    memoryASet16(ds, 0x5e60, r16[si]);
    r16[di] = 0x1204;
    yield* sub_10590();
  case 0x12ab1:
    r16[si] = memoryAGet16(es, r16[bx] + 170);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e62))
        { pc = 0x12aca; break; }
    memoryASet16(ds, 0x5e62, r16[si]);
    r16[di] = 0x1206;
    yield* sub_10590();
  case 0x12aca:
    r16[si] = memoryAGet16(es, r16[bx] + 172);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e64))
        { pc = 0x12ae3; break; }
    memoryASet16(ds, 0x5e64, r16[si]);
    r16[di] = 0x1208;
    yield* sub_10590();
  case 0x12ae3:
    r16[si] = memoryAGet16(es, r16[bx] + 174);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e66))
        { pc = 0x12afc; break; }
    memoryASet16(ds, 0x5e66, r16[si]);
    r16[di] = 0x120a;
    yield* sub_10590();
  case 0x12afc:
    r16[si] = memoryAGet16(es, r16[bx] + 176);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e68))
        { pc = 0x12b15; break; }
    memoryASet16(ds, 0x5e68, r16[si]);
    r16[di] = 0x120c;
    yield* sub_10590();
  case 0x12b15:
    r16[si] = memoryAGet16(es, r16[bx] + 178);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e6a))
        { pc = 0x12b2e; break; }
    memoryASet16(ds, 0x5e6a, r16[si]);
    r16[di] = 0x120e;
    yield* sub_10590();
  case 0x12b2e:
    r16[si] = memoryAGet16(es, r16[bx] + 180);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e6c))
        { pc = 0x12b47; break; }
    memoryASet16(ds, 0x5e6c, r16[si]);
    r16[di] = 0x1210;
    yield* sub_10590();
  case 0x12b47:
    r16[si] = memoryAGet16(es, r16[bx] + 182);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e6e))
        { pc = 0x12b60; break; }
    memoryASet16(ds, 0x5e6e, r16[si]);
    r16[di] = 0x1212;
    yield* sub_10590();
  case 0x12b60:
    r16[si] = memoryAGet16(es, r16[bx] + 184);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e70))
        { pc = 0x12b79; break; }
    memoryASet16(ds, 0x5e70, r16[si]);
    r16[di] = 0x1214;
    yield* sub_10590();
  case 0x12b79:
    r16[si] = memoryAGet16(es, r16[bx] + 186);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e72))
        { pc = 0x12b92; break; }
    memoryASet16(ds, 0x5e72, r16[si]);
    r16[di] = 0x1216;
    yield* sub_10590();
  case 0x12b92:
    r16[si] = memoryAGet16(es, r16[bx] + 188);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e74))
        { pc = 0x12bab; break; }
    memoryASet16(ds, 0x5e74, r16[si]);
    r16[di] = 0x1218;
    yield* sub_10590();
  case 0x12bab:
    r16[si] = memoryAGet16(es, r16[bx] + 190);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e76))
        { pc = 0x12bc4; break; }
    memoryASet16(ds, 0x5e76, r16[si]);
    r16[di] = 0x121a;
    yield* sub_10590();
  case 0x12bc4:
    r16[si] = memoryAGet16(es, r16[bx] + 192);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e78))
        { pc = 0x12bdd; break; }
    memoryASet16(ds, 0x5e78, r16[si]);
    r16[di] = 0x121c;
    yield* sub_10590();
  case 0x12bdd:
    r16[si] = memoryAGet16(es, r16[bx] + 194);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e7a))
        { pc = 0x12bf6; break; }
    memoryASet16(ds, 0x5e7a, r16[si]);
    r16[di] = 0x121e;
    yield* sub_10590();
  case 0x12bf6:
    r16[si] = memoryAGet16(es, r16[bx] + 196);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e7c))
        { pc = 0x12c0f; break; }
    memoryASet16(ds, 0x5e7c, r16[si]);
    r16[di] = 0x1220;
    yield* sub_10590();
  case 0x12c0f:
    r16[si] = memoryAGet16(es, r16[bx] + 198);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e7e))
        { pc = 0x12c28; break; }
    memoryASet16(ds, 0x5e7e, r16[si]);
    r16[di] = 0x1222;
    yield* sub_10590();
  case 0x12c28:
    r16[si] = memoryAGet16(es, r16[bx] + 200);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e80))
        { pc = 0x12c41; break; }
    memoryASet16(ds, 0x5e80, r16[si]);
    r16[di] = 0x1224;
    yield* sub_10590();
  case 0x12c41:
    r16[si] = memoryAGet16(es, r16[bx] + 202);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e82))
        { pc = 0x12c5a; break; }
    memoryASet16(ds, 0x5e82, r16[si]);
    r16[di] = 0x1226;
    yield* sub_10590();
  case 0x12c5a:
    r16[si] = memoryAGet16(es, r16[bx] + 204);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e84))
        { pc = 0x12c73; break; }
    memoryASet16(ds, 0x5e84, r16[si]);
    r16[di] = 0x1228;
    yield* sub_10590();
  case 0x12c73:
    r16[si] = memoryAGet16(es, r16[bx] + 206);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e86))
        { pc = 0x12c8c; break; }
    memoryASet16(ds, 0x5e86, r16[si]);
    r16[di] = 0x122a;
    yield* sub_10590();
  case 0x12c8c:
    r16[si] = memoryAGet16(es, r16[bx] + 208);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e88))
        { pc = 0x12ca5; break; }
    memoryASet16(ds, 0x5e88, r16[si]);
    r16[di] = 0x122c;
    yield* sub_10590();
  case 0x12ca5:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 210);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e8a))
        { pc = 0x12cc2; break; }
    memoryASet16(ds, 0x5e8a, r16[si]);
    r16[di] = 0x1504;
    yield* sub_10590();
  case 0x12cc2:
    r16[si] = memoryAGet16(es, r16[bx] + 212);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e8c))
        { pc = 0x12cdb; break; }
    memoryASet16(ds, 0x5e8c, r16[si]);
    r16[di] = 0x1506;
    yield* sub_10590();
  case 0x12cdb:
    r16[si] = memoryAGet16(es, r16[bx] + 214);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e8e))
        { pc = 0x12cf4; break; }
    memoryASet16(ds, 0x5e8e, r16[si]);
    r16[di] = 0x1508;
    yield* sub_10590();
  case 0x12cf4:
    r16[si] = memoryAGet16(es, r16[bx] + 216);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e90))
        { pc = 0x12d0d; break; }
    memoryASet16(ds, 0x5e90, r16[si]);
    r16[di] = 0x150a;
    yield* sub_10590();
  case 0x12d0d:
    r16[si] = memoryAGet16(es, r16[bx] + 218);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e92))
        { pc = 0x12d26; break; }
    memoryASet16(ds, 0x5e92, r16[si]);
    r16[di] = 0x150c;
    yield* sub_10590();
  case 0x12d26:
    r16[si] = memoryAGet16(es, r16[bx] + 220);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e94))
        { pc = 0x12d3f; break; }
    memoryASet16(ds, 0x5e94, r16[si]);
    r16[di] = 0x150e;
    yield* sub_10590();
  case 0x12d3f:
    r16[si] = memoryAGet16(es, r16[bx] + 222);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e96))
        { pc = 0x12d58; break; }
    memoryASet16(ds, 0x5e96, r16[si]);
    r16[di] = 0x1510;
    yield* sub_10590();
  case 0x12d58:
    r16[si] = memoryAGet16(es, r16[bx] + 224);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e98))
        { pc = 0x12d71; break; }
    memoryASet16(ds, 0x5e98, r16[si]);
    r16[di] = 0x1512;
    yield* sub_10590();
  case 0x12d71:
    r16[si] = memoryAGet16(es, r16[bx] + 226);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e9a))
        { pc = 0x12d8a; break; }
    memoryASet16(ds, 0x5e9a, r16[si]);
    r16[di] = 0x1514;
    yield* sub_10590();
  case 0x12d8a:
    r16[si] = memoryAGet16(es, r16[bx] + 228);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e9c))
        { pc = 0x12da3; break; }
    memoryASet16(ds, 0x5e9c, r16[si]);
    r16[di] = 0x1516;
    yield* sub_10590();
  case 0x12da3:
    r16[si] = memoryAGet16(es, r16[bx] + 230);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5e9e))
        { pc = 0x12dbc; break; }
    memoryASet16(ds, 0x5e9e, r16[si]);
    r16[di] = 0x1518;
    yield* sub_10590();
  case 0x12dbc:
    r16[si] = memoryAGet16(es, r16[bx] + 232);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ea0))
        { pc = 0x12dd5; break; }
    memoryASet16(ds, 0x5ea0, r16[si]);
    r16[di] = 0x151a;
    yield* sub_10590();
  case 0x12dd5:
    r16[si] = memoryAGet16(es, r16[bx] + 234);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ea2))
        { pc = 0x12dee; break; }
    memoryASet16(ds, 0x5ea2, r16[si]);
    r16[di] = 0x151c;
    yield* sub_10590();
  case 0x12dee:
    r16[si] = memoryAGet16(es, r16[bx] + 236);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ea4))
        { pc = 0x12e07; break; }
    memoryASet16(ds, 0x5ea4, r16[si]);
    r16[di] = 0x151e;
    yield* sub_10590();
  case 0x12e07:
    r16[si] = memoryAGet16(es, r16[bx] + 238);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ea6))
        { pc = 0x12e20; break; }
    memoryASet16(ds, 0x5ea6, r16[si]);
    r16[di] = 0x1520;
    yield* sub_10590();
  case 0x12e20:
    r16[si] = memoryAGet16(es, r16[bx] + 240);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ea8))
        { pc = 0x12e39; break; }
    memoryASet16(ds, 0x5ea8, r16[si]);
    r16[di] = 0x1522;
    yield* sub_10590();
  case 0x12e39:
    r16[si] = memoryAGet16(es, r16[bx] + 242);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eaa))
        { pc = 0x12e52; break; }
    memoryASet16(ds, 0x5eaa, r16[si]);
    r16[di] = 0x1524;
    yield* sub_10590();
  case 0x12e52:
    r16[si] = memoryAGet16(es, r16[bx] + 244);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eac))
        { pc = 0x12e6b; break; }
    memoryASet16(ds, 0x5eac, r16[si]);
    r16[di] = 0x1526;
    yield* sub_10590();
  case 0x12e6b:
    r16[si] = memoryAGet16(es, r16[bx] + 246);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eae))
        { pc = 0x12e84; break; }
    memoryASet16(ds, 0x5eae, r16[si]);
    r16[di] = 0x1528;
    yield* sub_10590();
  case 0x12e84:
    r16[si] = memoryAGet16(es, r16[bx] + 248);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eb0))
        { pc = 0x12e9d; break; }
    memoryASet16(ds, 0x5eb0, r16[si]);
    r16[di] = 0x152a;
    yield* sub_10590();
  case 0x12e9d:
    r16[si] = memoryAGet16(es, r16[bx] + 250);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eb2))
        { pc = 0x12eb6; break; }
    memoryASet16(ds, 0x5eb2, r16[si]);
    r16[di] = 0x152c;
    yield* sub_10590();
  case 0x12eb6:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 252);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eb4))
        { pc = 0x12ed3; break; }
    memoryASet16(ds, 0x5eb4, r16[si]);
    r16[di] = 0x1804;
    yield* sub_10590();
  case 0x12ed3:
    r16[si] = memoryAGet16(es, r16[bx] + 254);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eb6))
        { pc = 0x12eec; break; }
    memoryASet16(ds, 0x5eb6, r16[si]);
    r16[di] = 0x1806;
    yield* sub_10590();
  case 0x12eec:
    r16[si] = memoryAGet16(es, r16[bx] + 256);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eb8))
        { pc = 0x12f05; break; }
    memoryASet16(ds, 0x5eb8, r16[si]);
    r16[di] = 0x1808;
    yield* sub_10590();
  case 0x12f05:
    r16[si] = memoryAGet16(es, r16[bx] + 258);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eba))
        { pc = 0x12f1e; break; }
    memoryASet16(ds, 0x5eba, r16[si]);
    r16[di] = 0x180a;
    yield* sub_10590();
  case 0x12f1e:
    r16[si] = memoryAGet16(es, r16[bx] + 260);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ebc))
        { pc = 0x12f37; break; }
    memoryASet16(ds, 0x5ebc, r16[si]);
    r16[di] = 0x180c;
    yield* sub_10590();
  case 0x12f37:
    r16[si] = memoryAGet16(es, r16[bx] + 262);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ebe))
        { pc = 0x12f50; break; }
    memoryASet16(ds, 0x5ebe, r16[si]);
    r16[di] = 0x180e;
    yield* sub_10590();
  case 0x12f50:
    r16[si] = memoryAGet16(es, r16[bx] + 264);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ec0))
        { pc = 0x12f69; break; }
    memoryASet16(ds, 0x5ec0, r16[si]);
    r16[di] = 0x1810;
    yield* sub_10590();
  case 0x12f69:
    r16[si] = memoryAGet16(es, r16[bx] + 266);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ec2))
        { pc = 0x12f82; break; }
    memoryASet16(ds, 0x5ec2, r16[si]);
    r16[di] = 0x1812;
    yield* sub_10590();
  case 0x12f82:
    r16[si] = memoryAGet16(es, r16[bx] + 268);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ec4))
        { pc = 0x12f9b; break; }
    memoryASet16(ds, 0x5ec4, r16[si]);
    r16[di] = 0x1814;
    yield* sub_10590();
  case 0x12f9b:
    r16[si] = memoryAGet16(es, r16[bx] + 270);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ec6))
        { pc = 0x12fb4; break; }
    memoryASet16(ds, 0x5ec6, r16[si]);
    r16[di] = 0x1816;
    yield* sub_10590();
  case 0x12fb4:
    r16[si] = memoryAGet16(es, r16[bx] + 272);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ec8))
        { pc = 0x12fcd; break; }
    memoryASet16(ds, 0x5ec8, r16[si]);
    r16[di] = 0x1818;
    yield* sub_10590();
  case 0x12fcd:
    r16[si] = memoryAGet16(es, r16[bx] + 274);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eca))
        { pc = 0x12fe6; break; }
    memoryASet16(ds, 0x5eca, r16[si]);
    r16[di] = 0x181a;
    yield* sub_10590();
  case 0x12fe6:
    r16[si] = memoryAGet16(es, r16[bx] + 276);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ecc))
        { pc = 0x12fff; break; }
    memoryASet16(ds, 0x5ecc, r16[si]);
    r16[di] = 0x181c;
    yield* sub_10590();
  case 0x12fff:
    r16[si] = memoryAGet16(es, r16[bx] + 278);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ece))
        { pc = 0x13018; break; }
    memoryASet16(ds, 0x5ece, r16[si]);
    r16[di] = 0x181e;
    yield* sub_10590();
  case 0x13018:
    r16[si] = memoryAGet16(es, r16[bx] + 280);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ed0))
        { pc = 0x13031; break; }
    memoryASet16(ds, 0x5ed0, r16[si]);
    r16[di] = 0x1820;
    yield* sub_10590();
  case 0x13031:
    r16[si] = memoryAGet16(es, r16[bx] + 282);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ed2))
        { pc = 0x1304a; break; }
    memoryASet16(ds, 0x5ed2, r16[si]);
    r16[di] = 0x1822;
    yield* sub_10590();
  case 0x1304a:
    r16[si] = memoryAGet16(es, r16[bx] + 284);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ed4))
        { pc = 0x13063; break; }
    memoryASet16(ds, 0x5ed4, r16[si]);
    r16[di] = 0x1824;
    yield* sub_10590();
  case 0x13063:
    r16[si] = memoryAGet16(es, r16[bx] + 286);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ed6))
        { pc = 0x1307c; break; }
    memoryASet16(ds, 0x5ed6, r16[si]);
    r16[di] = 0x1826;
    yield* sub_10590();
  case 0x1307c:
    r16[si] = memoryAGet16(es, r16[bx] + 288);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ed8))
        { pc = 0x13095; break; }
    memoryASet16(ds, 0x5ed8, r16[si]);
    r16[di] = 0x1828;
    yield* sub_10590();
  case 0x13095:
    r16[si] = memoryAGet16(es, r16[bx] + 290);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eda))
        { pc = 0x130ae; break; }
    memoryASet16(ds, 0x5eda, r16[si]);
    r16[di] = 0x182a;
    yield* sub_10590();
  case 0x130ae:
    r16[si] = memoryAGet16(es, r16[bx] + 292);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5edc))
        { pc = 0x130c7; break; }
    memoryASet16(ds, 0x5edc, r16[si]);
    r16[di] = 0x182c;
    yield* sub_10590();
  case 0x130c7:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 294);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ede))
        { pc = 0x130e4; break; }
    memoryASet16(ds, 0x5ede, r16[si]);
    r16[di] = 0x1b04;
    yield* sub_10590();
  case 0x130e4:
    r16[si] = memoryAGet16(es, r16[bx] + 296);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ee0))
        { pc = 0x130fd; break; }
    memoryASet16(ds, 0x5ee0, r16[si]);
    r16[di] = 0x1b06;
    yield* sub_10590();
  case 0x130fd:
    r16[si] = memoryAGet16(es, r16[bx] + 298);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ee2))
        { pc = 0x13116; break; }
    memoryASet16(ds, 0x5ee2, r16[si]);
    r16[di] = 0x1b08;
    yield* sub_10590();
  case 0x13116:
    r16[si] = memoryAGet16(es, r16[bx] + 300);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ee4))
        { pc = 0x1312f; break; }
    memoryASet16(ds, 0x5ee4, r16[si]);
    r16[di] = 0x1b0a;
    yield* sub_10590();
  case 0x1312f:
    r16[si] = memoryAGet16(es, r16[bx] + 302);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ee6))
        { pc = 0x13148; break; }
    memoryASet16(ds, 0x5ee6, r16[si]);
    r16[di] = 0x1b0c;
    yield* sub_10590();
  case 0x13148:
    r16[si] = memoryAGet16(es, r16[bx] + 304);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ee8))
        { pc = 0x13161; break; }
    memoryASet16(ds, 0x5ee8, r16[si]);
    r16[di] = 0x1b0e;
    yield* sub_10590();
  case 0x13161:
    r16[si] = memoryAGet16(es, r16[bx] + 306);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eea))
        { pc = 0x1317a; break; }
    memoryASet16(ds, 0x5eea, r16[si]);
    r16[di] = 0x1b10;
    yield* sub_10590();
  case 0x1317a:
    r16[si] = memoryAGet16(es, r16[bx] + 308);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eec))
        { pc = 0x13193; break; }
    memoryASet16(ds, 0x5eec, r16[si]);
    r16[di] = 0x1b12;
    yield* sub_10590();
  case 0x13193:
    r16[si] = memoryAGet16(es, r16[bx] + 310);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5eee))
        { pc = 0x131ac; break; }
    memoryASet16(ds, 0x5eee, r16[si]);
    r16[di] = 0x1b14;
    yield* sub_10590();
  case 0x131ac:
    r16[si] = memoryAGet16(es, r16[bx] + 312);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ef0))
        { pc = 0x131c5; break; }
    memoryASet16(ds, 0x5ef0, r16[si]);
    r16[di] = 0x1b16;
    yield* sub_10590();
  case 0x131c5:
    r16[si] = memoryAGet16(es, r16[bx] + 314);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ef2))
        { pc = 0x131de; break; }
    memoryASet16(ds, 0x5ef2, r16[si]);
    r16[di] = 0x1b18;
    yield* sub_10590();
  case 0x131de:
    r16[si] = memoryAGet16(es, r16[bx] + 316);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ef4))
        { pc = 0x131f7; break; }
    memoryASet16(ds, 0x5ef4, r16[si]);
    r16[di] = 0x1b1a;
    yield* sub_10590();
  case 0x131f7:
    r16[si] = memoryAGet16(es, r16[bx] + 318);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ef6))
        { pc = 0x13210; break; }
    memoryASet16(ds, 0x5ef6, r16[si]);
    r16[di] = 0x1b1c;
    yield* sub_10590();
  case 0x13210:
    r16[si] = memoryAGet16(es, r16[bx] + 320);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ef8))
        { pc = 0x13229; break; }
    memoryASet16(ds, 0x5ef8, r16[si]);
    r16[di] = 0x1b1e;
    yield* sub_10590();
  case 0x13229:
    r16[si] = memoryAGet16(es, r16[bx] + 322);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5efa))
        { pc = 0x13242; break; }
    memoryASet16(ds, 0x5efa, r16[si]);
    r16[di] = 0x1b20;
    yield* sub_10590();
  case 0x13242:
    r16[si] = memoryAGet16(es, r16[bx] + 324);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5efc))
        { pc = 0x1325b; break; }
    memoryASet16(ds, 0x5efc, r16[si]);
    r16[di] = 0x1b22;
    yield* sub_10590();
  case 0x1325b:
    r16[si] = memoryAGet16(es, r16[bx] + 326);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5efe))
        { pc = 0x13274; break; }
    memoryASet16(ds, 0x5efe, r16[si]);
    r16[di] = 0x1b24;
    yield* sub_10590();
  case 0x13274:
    r16[si] = memoryAGet16(es, r16[bx] + 328);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f00))
        { pc = 0x1328d; break; }
    memoryASet16(ds, 0x5f00, r16[si]);
    r16[di] = 0x1b26;
    yield* sub_10590();
  case 0x1328d:
    r16[si] = memoryAGet16(es, r16[bx] + 330);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f02))
        { pc = 0x132a6; break; }
    memoryASet16(ds, 0x5f02, r16[si]);
    r16[di] = 0x1b28;
    yield* sub_10590();
  case 0x132a6:
    r16[si] = memoryAGet16(es, r16[bx] + 332);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f04))
        { pc = 0x132bf; break; }
    memoryASet16(ds, 0x5f04, r16[si]);
    r16[di] = 0x1b2a;
    yield* sub_10590();
  case 0x132bf:
    r16[si] = memoryAGet16(es, r16[bx] + 334);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f06))
        { pc = 0x132d8; break; }
    memoryASet16(ds, 0x5f06, r16[si]);
    r16[di] = 0x1b2c;
    yield* sub_10590();
  case 0x132d8:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 336);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f08))
        { pc = 0x132f5; break; }
    memoryASet16(ds, 0x5f08, r16[si]);
    r16[di] = 0x1e04;
    yield* sub_10590();
  case 0x132f5:
    r16[si] = memoryAGet16(es, r16[bx] + 338);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f0a))
        { pc = 0x1330e; break; }
    memoryASet16(ds, 0x5f0a, r16[si]);
    r16[di] = 0x1e06;
    yield* sub_10590();
  case 0x1330e:
    r16[si] = memoryAGet16(es, r16[bx] + 340);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f0c))
        { pc = 0x13327; break; }
    memoryASet16(ds, 0x5f0c, r16[si]);
    r16[di] = 0x1e08;
    yield* sub_10590();
  case 0x13327:
    r16[si] = memoryAGet16(es, r16[bx] + 342);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f0e))
        { pc = 0x13340; break; }
    memoryASet16(ds, 0x5f0e, r16[si]);
    r16[di] = 0x1e0a;
    yield* sub_10590();
  case 0x13340:
    r16[si] = memoryAGet16(es, r16[bx] + 344);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f10))
        { pc = 0x13359; break; }
    memoryASet16(ds, 0x5f10, r16[si]);
    r16[di] = 0x1e0c;
    yield* sub_10590();
  case 0x13359:
    r16[si] = memoryAGet16(es, r16[bx] + 346);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f12))
        { pc = 0x13372; break; }
    memoryASet16(ds, 0x5f12, r16[si]);
    r16[di] = 0x1e0e;
    yield* sub_10590();
  case 0x13372:
    r16[si] = memoryAGet16(es, r16[bx] + 348);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f14))
        { pc = 0x1338b; break; }
    memoryASet16(ds, 0x5f14, r16[si]);
    r16[di] = 0x1e10;
    yield* sub_10590();
  case 0x1338b:
    r16[si] = memoryAGet16(es, r16[bx] + 350);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f16))
        { pc = 0x133a4; break; }
    memoryASet16(ds, 0x5f16, r16[si]);
    r16[di] = 0x1e12;
    yield* sub_10590();
  case 0x133a4:
    r16[si] = memoryAGet16(es, r16[bx] + 352);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f18))
        { pc = 0x133bd; break; }
    memoryASet16(ds, 0x5f18, r16[si]);
    r16[di] = 0x1e14;
    yield* sub_10590();
  case 0x133bd:
    r16[si] = memoryAGet16(es, r16[bx] + 354);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f1a))
        { pc = 0x133d6; break; }
    memoryASet16(ds, 0x5f1a, r16[si]);
    r16[di] = 0x1e16;
    yield* sub_10590();
  case 0x133d6:
    r16[si] = memoryAGet16(es, r16[bx] + 356);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f1c))
        { pc = 0x133ef; break; }
    memoryASet16(ds, 0x5f1c, r16[si]);
    r16[di] = 0x1e18;
    yield* sub_10590();
  case 0x133ef:
    r16[si] = memoryAGet16(es, r16[bx] + 358);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f1e))
        { pc = 0x13408; break; }
    memoryASet16(ds, 0x5f1e, r16[si]);
    r16[di] = 0x1e1a;
    yield* sub_10590();
  case 0x13408:
    r16[si] = memoryAGet16(es, r16[bx] + 360);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f20))
        { pc = 0x13421; break; }
    memoryASet16(ds, 0x5f20, r16[si]);
    r16[di] = 0x1e1c;
    yield* sub_10590();
  case 0x13421:
    r16[si] = memoryAGet16(es, r16[bx] + 362);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f22))
        { pc = 0x1343a; break; }
    memoryASet16(ds, 0x5f22, r16[si]);
    r16[di] = 0x1e1e;
    yield* sub_10590();
  case 0x1343a:
    r16[si] = memoryAGet16(es, r16[bx] + 364);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f24))
        { pc = 0x13453; break; }
    memoryASet16(ds, 0x5f24, r16[si]);
    r16[di] = 0x1e20;
    yield* sub_10590();
  case 0x13453:
    r16[si] = memoryAGet16(es, r16[bx] + 366);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f26))
        { pc = 0x1346c; break; }
    memoryASet16(ds, 0x5f26, r16[si]);
    r16[di] = 0x1e22;
    yield* sub_10590();
  case 0x1346c:
    r16[si] = memoryAGet16(es, r16[bx] + 368);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f28))
        { pc = 0x13485; break; }
    memoryASet16(ds, 0x5f28, r16[si]);
    r16[di] = 0x1e24;
    yield* sub_10590();
  case 0x13485:
    r16[si] = memoryAGet16(es, r16[bx] + 370);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f2a))
        { pc = 0x1349e; break; }
    memoryASet16(ds, 0x5f2a, r16[si]);
    r16[di] = 0x1e26;
    yield* sub_10590();
  case 0x1349e:
    r16[si] = memoryAGet16(es, r16[bx] + 372);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f2c))
        { pc = 0x134b7; break; }
    memoryASet16(ds, 0x5f2c, r16[si]);
    r16[di] = 0x1e28;
    yield* sub_10590();
  case 0x134b7:
    r16[si] = memoryAGet16(es, r16[bx] + 374);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f2e))
        { pc = 0x134d0; break; }
    memoryASet16(ds, 0x5f2e, r16[si]);
    r16[di] = 0x1e2a;
    yield* sub_10590();
  case 0x134d0:
    r16[si] = memoryAGet16(es, r16[bx] + 376);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f30))
        { pc = 0x134e9; break; }
    memoryASet16(ds, 0x5f30, r16[si]);
    r16[di] = 0x1e2c;
    yield* sub_10590();
  case 0x134e9:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 378);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f32))
        { pc = 0x13506; break; }
    memoryASet16(ds, 0x5f32, r16[si]);
    r16[di] = 0x2104;
    yield* sub_10590();
  case 0x13506:
    r16[si] = memoryAGet16(es, r16[bx] + 380);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f34))
        { pc = 0x1351f; break; }
    memoryASet16(ds, 0x5f34, r16[si]);
    r16[di] = 0x2106;
    yield* sub_10590();
  case 0x1351f:
    r16[si] = memoryAGet16(es, r16[bx] + 382);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f36))
        { pc = 0x13538; break; }
    memoryASet16(ds, 0x5f36, r16[si]);
    r16[di] = 0x2108;
    yield* sub_10590();
  case 0x13538:
    r16[si] = memoryAGet16(es, r16[bx] + 384);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f38))
        { pc = 0x13551; break; }
    memoryASet16(ds, 0x5f38, r16[si]);
    r16[di] = 0x210a;
    yield* sub_10590();
  case 0x13551:
    r16[si] = memoryAGet16(es, r16[bx] + 386);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f3a))
        { pc = 0x1356a; break; }
    memoryASet16(ds, 0x5f3a, r16[si]);
    r16[di] = 0x210c;
    yield* sub_10590();
  case 0x1356a:
    r16[si] = memoryAGet16(es, r16[bx] + 388);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f3c))
        { pc = 0x13583; break; }
    memoryASet16(ds, 0x5f3c, r16[si]);
    r16[di] = 0x210e;
    yield* sub_10590();
  case 0x13583:
    r16[si] = memoryAGet16(es, r16[bx] + 390);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f3e))
        { pc = 0x1359c; break; }
    memoryASet16(ds, 0x5f3e, r16[si]);
    r16[di] = 0x2110;
    yield* sub_10590();
  case 0x1359c:
    r16[si] = memoryAGet16(es, r16[bx] + 392);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f40))
        { pc = 0x135b5; break; }
    memoryASet16(ds, 0x5f40, r16[si]);
    r16[di] = 0x2112;
    yield* sub_10590();
  case 0x135b5:
    r16[si] = memoryAGet16(es, r16[bx] + 394);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f42))
        { pc = 0x135ce; break; }
    memoryASet16(ds, 0x5f42, r16[si]);
    r16[di] = 0x2114;
    yield* sub_10590();
  case 0x135ce:
    r16[si] = memoryAGet16(es, r16[bx] + 396);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f44))
        { pc = 0x135e7; break; }
    memoryASet16(ds, 0x5f44, r16[si]);
    r16[di] = 0x2116;
    yield* sub_10590();
  case 0x135e7:
    r16[si] = memoryAGet16(es, r16[bx] + 398);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f46))
        { pc = 0x13600; break; }
    memoryASet16(ds, 0x5f46, r16[si]);
    r16[di] = 0x2118;
    yield* sub_10590();
  case 0x13600:
    r16[si] = memoryAGet16(es, r16[bx] + 400);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f48))
        { pc = 0x13619; break; }
    memoryASet16(ds, 0x5f48, r16[si]);
    r16[di] = 0x211a;
    yield* sub_10590();
  case 0x13619:
    r16[si] = memoryAGet16(es, r16[bx] + 402);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f4a))
        { pc = 0x13632; break; }
    memoryASet16(ds, 0x5f4a, r16[si]);
    r16[di] = 0x211c;
    yield* sub_10590();
  case 0x13632:
    r16[si] = memoryAGet16(es, r16[bx] + 404);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f4c))
        { pc = 0x1364b; break; }
    memoryASet16(ds, 0x5f4c, r16[si]);
    r16[di] = 0x211e;
    yield* sub_10590();
  case 0x1364b:
    r16[si] = memoryAGet16(es, r16[bx] + 406);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f4e))
        { pc = 0x13664; break; }
    memoryASet16(ds, 0x5f4e, r16[si]);
    r16[di] = 0x2120;
    yield* sub_10590();
  case 0x13664:
    r16[si] = memoryAGet16(es, r16[bx] + 408);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f50))
        { pc = 0x1367d; break; }
    memoryASet16(ds, 0x5f50, r16[si]);
    r16[di] = 0x2122;
    yield* sub_10590();
  case 0x1367d:
    r16[si] = memoryAGet16(es, r16[bx] + 410);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f52))
        { pc = 0x13696; break; }
    memoryASet16(ds, 0x5f52, r16[si]);
    r16[di] = 0x2124;
    yield* sub_10590();
  case 0x13696:
    r16[si] = memoryAGet16(es, r16[bx] + 412);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f54))
        { pc = 0x136af; break; }
    memoryASet16(ds, 0x5f54, r16[si]);
    r16[di] = 0x2126;
    yield* sub_10590();
  case 0x136af:
    r16[si] = memoryAGet16(es, r16[bx] + 414);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f56))
        { pc = 0x136c8; break; }
    memoryASet16(ds, 0x5f56, r16[si]);
    r16[di] = 0x2128;
    yield* sub_10590();
  case 0x136c8:
    r16[si] = memoryAGet16(es, r16[bx] + 416);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f58))
        { pc = 0x136e1; break; }
    memoryASet16(ds, 0x5f58, r16[si]);
    r16[di] = 0x212a;
    yield* sub_10590();
  case 0x136e1:
    r16[si] = memoryAGet16(es, r16[bx] + 418);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f5a))
        { pc = 0x136fa; break; }
    memoryASet16(ds, 0x5f5a, r16[si]);
    r16[di] = 0x212c;
    yield* sub_10590();
  case 0x136fa:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 420);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f5c))
        { pc = 0x13717; break; }
    memoryASet16(ds, 0x5f5c, r16[si]);
    r16[di] = 0x2404;
    yield* sub_10590();
  case 0x13717:
    r16[si] = memoryAGet16(es, r16[bx] + 422);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f5e))
        { pc = 0x13730; break; }
    memoryASet16(ds, 0x5f5e, r16[si]);
    r16[di] = 0x2406;
    yield* sub_10590();
  case 0x13730:
    r16[si] = memoryAGet16(es, r16[bx] + 424);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f60))
        { pc = 0x13749; break; }
    memoryASet16(ds, 0x5f60, r16[si]);
    r16[di] = 0x2408;
    yield* sub_10590();
  case 0x13749:
    r16[si] = memoryAGet16(es, r16[bx] + 426);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f62))
        { pc = 0x13762; break; }
    memoryASet16(ds, 0x5f62, r16[si]);
    r16[di] = 0x240a;
    yield* sub_10590();
  case 0x13762:
    r16[si] = memoryAGet16(es, r16[bx] + 428);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f64))
        { pc = 0x1377b; break; }
    memoryASet16(ds, 0x5f64, r16[si]);
    r16[di] = 0x240c;
    yield* sub_10590();
  case 0x1377b:
    r16[si] = memoryAGet16(es, r16[bx] + 430);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f66))
        { pc = 0x13794; break; }
    memoryASet16(ds, 0x5f66, r16[si]);
    r16[di] = 0x240e;
    yield* sub_10590();
  case 0x13794:
    r16[si] = memoryAGet16(es, r16[bx] + 432);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f68))
        { pc = 0x137ad; break; }
    memoryASet16(ds, 0x5f68, r16[si]);
    r16[di] = 0x2410;
    yield* sub_10590();
  case 0x137ad:
    r16[si] = memoryAGet16(es, r16[bx] + 434);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f6a))
        { pc = 0x137c6; break; }
    memoryASet16(ds, 0x5f6a, r16[si]);
    r16[di] = 0x2412;
    yield* sub_10590();
  case 0x137c6:
    r16[si] = memoryAGet16(es, r16[bx] + 436);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f6c))
        { pc = 0x137df; break; }
    memoryASet16(ds, 0x5f6c, r16[si]);
    r16[di] = 0x2414;
    yield* sub_10590();
  case 0x137df:
    r16[si] = memoryAGet16(es, r16[bx] + 438);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f6e))
        { pc = 0x137f8; break; }
    memoryASet16(ds, 0x5f6e, r16[si]);
    r16[di] = 0x2416;
    yield* sub_10590();
  case 0x137f8:
    r16[si] = memoryAGet16(es, r16[bx] + 440);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f70))
        { pc = 0x13811; break; }
    memoryASet16(ds, 0x5f70, r16[si]);
    r16[di] = 0x2418;
    yield* sub_10590();
  case 0x13811:
    r16[si] = memoryAGet16(es, r16[bx] + 442);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f72))
        { pc = 0x1382a; break; }
    memoryASet16(ds, 0x5f72, r16[si]);
    r16[di] = 0x241a;
    yield* sub_10590();
  case 0x1382a:
    r16[si] = memoryAGet16(es, r16[bx] + 444);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f74))
        { pc = 0x13843; break; }
    memoryASet16(ds, 0x5f74, r16[si]);
    r16[di] = 0x241c;
    yield* sub_10590();
  case 0x13843:
    r16[si] = memoryAGet16(es, r16[bx] + 446);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f76))
        { pc = 0x1385c; break; }
    memoryASet16(ds, 0x5f76, r16[si]);
    r16[di] = 0x241e;
    yield* sub_10590();
  case 0x1385c:
    r16[si] = memoryAGet16(es, r16[bx] + 448);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f78))
        { pc = 0x13875; break; }
    memoryASet16(ds, 0x5f78, r16[si]);
    r16[di] = 0x2420;
    yield* sub_10590();
  case 0x13875:
    r16[si] = memoryAGet16(es, r16[bx] + 450);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f7a))
        { pc = 0x1388e; break; }
    memoryASet16(ds, 0x5f7a, r16[si]);
    r16[di] = 0x2422;
    yield* sub_10590();
  case 0x1388e:
    r16[si] = memoryAGet16(es, r16[bx] + 452);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f7c))
        { pc = 0x138a7; break; }
    memoryASet16(ds, 0x5f7c, r16[si]);
    r16[di] = 0x2424;
    yield* sub_10590();
  case 0x138a7:
    r16[si] = memoryAGet16(es, r16[bx] + 454);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f7e))
        { pc = 0x138c0; break; }
    memoryASet16(ds, 0x5f7e, r16[si]);
    r16[di] = 0x2426;
    yield* sub_10590();
  case 0x138c0:
    r16[si] = memoryAGet16(es, r16[bx] + 456);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f80))
        { pc = 0x138d9; break; }
    memoryASet16(ds, 0x5f80, r16[si]);
    r16[di] = 0x2428;
    yield* sub_10590();
  case 0x138d9:
    r16[si] = memoryAGet16(es, r16[bx] + 458);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f82))
        { pc = 0x138f2; break; }
    memoryASet16(ds, 0x5f82, r16[si]);
    r16[di] = 0x242a;
    yield* sub_10590();
  case 0x138f2:
    r16[si] = memoryAGet16(es, r16[bx] + 460);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f84))
        { pc = 0x1390b; break; }
    memoryASet16(ds, 0x5f84, r16[si]);
    r16[di] = 0x242c;
    yield* sub_10590();
  case 0x1390b:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 462);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f86))
        { pc = 0x13928; break; }
    memoryASet16(ds, 0x5f86, r16[si]);
    r16[di] = 0x2704;
    yield* sub_10590();
  case 0x13928:
    r16[si] = memoryAGet16(es, r16[bx] + 464);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f88))
        { pc = 0x13941; break; }
    memoryASet16(ds, 0x5f88, r16[si]);
    r16[di] = 0x2706;
    yield* sub_10590();
  case 0x13941:
    r16[si] = memoryAGet16(es, r16[bx] + 466);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f8a))
        { pc = 0x1395a; break; }
    memoryASet16(ds, 0x5f8a, r16[si]);
    r16[di] = 0x2708;
    yield* sub_10590();
  case 0x1395a:
    r16[si] = memoryAGet16(es, r16[bx] + 468);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f8c))
        { pc = 0x13973; break; }
    memoryASet16(ds, 0x5f8c, r16[si]);
    r16[di] = 0x270a;
    yield* sub_10590();
  case 0x13973:
    r16[si] = memoryAGet16(es, r16[bx] + 470);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f8e))
        { pc = 0x1398c; break; }
    memoryASet16(ds, 0x5f8e, r16[si]);
    r16[di] = 0x270c;
    yield* sub_10590();
  case 0x1398c:
    r16[si] = memoryAGet16(es, r16[bx] + 472);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f90))
        { pc = 0x139a5; break; }
    memoryASet16(ds, 0x5f90, r16[si]);
    r16[di] = 0x270e;
    yield* sub_10590();
  case 0x139a5:
    r16[si] = memoryAGet16(es, r16[bx] + 474);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f92))
        { pc = 0x139be; break; }
    memoryASet16(ds, 0x5f92, r16[si]);
    r16[di] = 0x2710;
    yield* sub_10590();
  case 0x139be:
    r16[si] = memoryAGet16(es, r16[bx] + 476);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f94))
        { pc = 0x139d7; break; }
    memoryASet16(ds, 0x5f94, r16[si]);
    r16[di] = 0x2712;
    yield* sub_10590();
  case 0x139d7:
    r16[si] = memoryAGet16(es, r16[bx] + 478);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f96))
        { pc = 0x139f0; break; }
    memoryASet16(ds, 0x5f96, r16[si]);
    r16[di] = 0x2714;
    yield* sub_10590();
  case 0x139f0:
    r16[si] = memoryAGet16(es, r16[bx] + 480);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f98))
        { pc = 0x13a09; break; }
    memoryASet16(ds, 0x5f98, r16[si]);
    r16[di] = 0x2716;
    yield* sub_10590();
  case 0x13a09:
    r16[si] = memoryAGet16(es, r16[bx] + 482);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f9a))
        { pc = 0x13a22; break; }
    memoryASet16(ds, 0x5f9a, r16[si]);
    r16[di] = 0x2718;
    yield* sub_10590();
  case 0x13a22:
    r16[si] = memoryAGet16(es, r16[bx] + 484);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f9c))
        { pc = 0x13a3b; break; }
    memoryASet16(ds, 0x5f9c, r16[si]);
    r16[di] = 0x271a;
    yield* sub_10590();
  case 0x13a3b:
    r16[si] = memoryAGet16(es, r16[bx] + 486);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5f9e))
        { pc = 0x13a54; break; }
    memoryASet16(ds, 0x5f9e, r16[si]);
    r16[di] = 0x271c;
    yield* sub_10590();
  case 0x13a54:
    r16[si] = memoryAGet16(es, r16[bx] + 488);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fa0))
        { pc = 0x13a6d; break; }
    memoryASet16(ds, 0x5fa0, r16[si]);
    r16[di] = 0x271e;
    yield* sub_10590();
  case 0x13a6d:
    r16[si] = memoryAGet16(es, r16[bx] + 490);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fa2))
        { pc = 0x13a86; break; }
    memoryASet16(ds, 0x5fa2, r16[si]);
    r16[di] = 0x2720;
    yield* sub_10590();
  case 0x13a86:
    r16[si] = memoryAGet16(es, r16[bx] + 492);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fa4))
        { pc = 0x13a9f; break; }
    memoryASet16(ds, 0x5fa4, r16[si]);
    r16[di] = 0x2722;
    yield* sub_10590();
  case 0x13a9f:
    r16[si] = memoryAGet16(es, r16[bx] + 494);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fa6))
        { pc = 0x13ab8; break; }
    memoryASet16(ds, 0x5fa6, r16[si]);
    r16[di] = 0x2724;
    yield* sub_10590();
  case 0x13ab8:
    r16[si] = memoryAGet16(es, r16[bx] + 496);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fa8))
        { pc = 0x13ad1; break; }
    memoryASet16(ds, 0x5fa8, r16[si]);
    r16[di] = 0x2726;
    yield* sub_10590();
  case 0x13ad1:
    r16[si] = memoryAGet16(es, r16[bx] + 498);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5faa))
        { pc = 0x13aea; break; }
    memoryASet16(ds, 0x5faa, r16[si]);
    r16[di] = 0x2728;
    yield* sub_10590();
  case 0x13aea:
    r16[si] = memoryAGet16(es, r16[bx] + 500);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fac))
        { pc = 0x13b03; break; }
    memoryASet16(ds, 0x5fac, r16[si]);
    r16[di] = 0x272a;
    yield* sub_10590();
  case 0x13b03:
    r16[si] = memoryAGet16(es, r16[bx] + 502);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fae))
        { pc = 0x13b1c; break; }
    memoryASet16(ds, 0x5fae, r16[si]);
    r16[di] = 0x272c;
    yield* sub_10590();
  case 0x13b1c:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 504);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fb0))
        { pc = 0x13b39; break; }
    memoryASet16(ds, 0x5fb0, r16[si]);
    r16[di] = 0x2a04;
    yield* sub_10590();
  case 0x13b39:
    r16[si] = memoryAGet16(es, r16[bx] + 506);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fb2))
        { pc = 0x13b52; break; }
    memoryASet16(ds, 0x5fb2, r16[si]);
    r16[di] = 0x2a06;
    yield* sub_10590();
  case 0x13b52:
    r16[si] = memoryAGet16(es, r16[bx] + 508);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fb4))
        { pc = 0x13b6b; break; }
    memoryASet16(ds, 0x5fb4, r16[si]);
    r16[di] = 0x2a08;
    yield* sub_10590();
  case 0x13b6b:
    r16[si] = memoryAGet16(es, r16[bx] + 510);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fb6))
        { pc = 0x13b84; break; }
    memoryASet16(ds, 0x5fb6, r16[si]);
    r16[di] = 0x2a0a;
    yield* sub_10590();
  case 0x13b84:
    r16[si] = memoryAGet16(es, r16[bx] + 512);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fb8))
        { pc = 0x13b9d; break; }
    memoryASet16(ds, 0x5fb8, r16[si]);
    r16[di] = 0x2a0c;
    yield* sub_10590();
  case 0x13b9d:
    r16[si] = memoryAGet16(es, r16[bx] + 514);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fba))
        { pc = 0x13bb6; break; }
    memoryASet16(ds, 0x5fba, r16[si]);
    r16[di] = 0x2a0e;
    yield* sub_10590();
  case 0x13bb6:
    r16[si] = memoryAGet16(es, r16[bx] + 516);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fbc))
        { pc = 0x13bcf; break; }
    memoryASet16(ds, 0x5fbc, r16[si]);
    r16[di] = 0x2a10;
    yield* sub_10590();
  case 0x13bcf:
    r16[si] = memoryAGet16(es, r16[bx] + 518);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fbe))
        { pc = 0x13be8; break; }
    memoryASet16(ds, 0x5fbe, r16[si]);
    r16[di] = 0x2a12;
    yield* sub_10590();
  case 0x13be8:
    r16[si] = memoryAGet16(es, r16[bx] + 520);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fc0))
        { pc = 0x13c01; break; }
    memoryASet16(ds, 0x5fc0, r16[si]);
    r16[di] = 0x2a14;
    yield* sub_10590();
  case 0x13c01:
    r16[si] = memoryAGet16(es, r16[bx] + 522);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fc2))
        { pc = 0x13c1a; break; }
    memoryASet16(ds, 0x5fc2, r16[si]);
    r16[di] = 0x2a16;
    yield* sub_10590();
  case 0x13c1a:
    r16[si] = memoryAGet16(es, r16[bx] + 524);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fc4))
        { pc = 0x13c33; break; }
    memoryASet16(ds, 0x5fc4, r16[si]);
    r16[di] = 0x2a18;
    yield* sub_10590();
  case 0x13c33:
    r16[si] = memoryAGet16(es, r16[bx] + 526);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fc6))
        { pc = 0x13c4c; break; }
    memoryASet16(ds, 0x5fc6, r16[si]);
    r16[di] = 0x2a1a;
    yield* sub_10590();
  case 0x13c4c:
    r16[si] = memoryAGet16(es, r16[bx] + 528);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fc8))
        { pc = 0x13c65; break; }
    memoryASet16(ds, 0x5fc8, r16[si]);
    r16[di] = 0x2a1c;
    yield* sub_10590();
  case 0x13c65:
    r16[si] = memoryAGet16(es, r16[bx] + 530);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fca))
        { pc = 0x13c7e; break; }
    memoryASet16(ds, 0x5fca, r16[si]);
    r16[di] = 0x2a1e;
    yield* sub_10590();
  case 0x13c7e:
    r16[si] = memoryAGet16(es, r16[bx] + 532);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fcc))
        { pc = 0x13c97; break; }
    memoryASet16(ds, 0x5fcc, r16[si]);
    r16[di] = 0x2a20;
    yield* sub_10590();
  case 0x13c97:
    r16[si] = memoryAGet16(es, r16[bx] + 534);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fce))
        { pc = 0x13cb0; break; }
    memoryASet16(ds, 0x5fce, r16[si]);
    r16[di] = 0x2a22;
    yield* sub_10590();
  case 0x13cb0:
    r16[si] = memoryAGet16(es, r16[bx] + 536);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fd0))
        { pc = 0x13cc9; break; }
    memoryASet16(ds, 0x5fd0, r16[si]);
    r16[di] = 0x2a24;
    yield* sub_10590();
  case 0x13cc9:
    r16[si] = memoryAGet16(es, r16[bx] + 538);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fd2))
        { pc = 0x13ce2; break; }
    memoryASet16(ds, 0x5fd2, r16[si]);
    r16[di] = 0x2a26;
    yield* sub_10590();
  case 0x13ce2:
    r16[si] = memoryAGet16(es, r16[bx] + 540);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fd4))
        { pc = 0x13cfb; break; }
    memoryASet16(ds, 0x5fd4, r16[si]);
    r16[di] = 0x2a28;
    yield* sub_10590();
  case 0x13cfb:
    r16[si] = memoryAGet16(es, r16[bx] + 542);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fd6))
        { pc = 0x13d14; break; }
    memoryASet16(ds, 0x5fd6, r16[si]);
    r16[di] = 0x2a2a;
    yield* sub_10590();
  case 0x13d14:
    r16[si] = memoryAGet16(es, r16[bx] + 544);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fd8))
        { pc = 0x13d2d; break; }
    memoryASet16(ds, 0x5fd8, r16[si]);
    r16[di] = 0x2a2c;
    yield* sub_10590();
  case 0x13d2d:
    r16[bx] += memoryAGet16(ds, 0x5654);
    r16[si] = memoryAGet16(es, r16[bx] + 546);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fda))
        { pc = 0x13d4a; break; }
    memoryASet16(ds, 0x5fda, r16[si]);
    r16[di] = 0x2d04;
    yield* sub_10590();
  case 0x13d4a:
    r16[si] = memoryAGet16(es, r16[bx] + 548);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fdc))
        { pc = 0x13d63; break; }
    memoryASet16(ds, 0x5fdc, r16[si]);
    r16[di] = 0x2d06;
    yield* sub_10590();
  case 0x13d63:
    r16[si] = memoryAGet16(es, r16[bx] + 550);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fde))
        { pc = 0x13d7c; break; }
    memoryASet16(ds, 0x5fde, r16[si]);
    r16[di] = 0x2d08;
    yield* sub_10590();
  case 0x13d7c:
    r16[si] = memoryAGet16(es, r16[bx] + 552);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fe0))
        { pc = 0x13d95; break; }
    memoryASet16(ds, 0x5fe0, r16[si]);
    r16[di] = 0x2d0a;
    yield* sub_10590();
  case 0x13d95:
    r16[si] = memoryAGet16(es, r16[bx] + 554);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fe2))
        { pc = 0x13dae; break; }
    memoryASet16(ds, 0x5fe2, r16[si]);
    r16[di] = 0x2d0c;
    yield* sub_10590();
  case 0x13dae:
    r16[si] = memoryAGet16(es, r16[bx] + 556);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fe4))
        { pc = 0x13dc7; break; }
    memoryASet16(ds, 0x5fe4, r16[si]);
    r16[di] = 0x2d0e;
    yield* sub_10590();
  case 0x13dc7:
    r16[si] = memoryAGet16(es, r16[bx] + 558);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fe6))
        { pc = 0x13de0; break; }
    memoryASet16(ds, 0x5fe6, r16[si]);
    r16[di] = 0x2d10;
    yield* sub_10590();
  case 0x13de0:
    r16[si] = memoryAGet16(es, r16[bx] + 560);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fe8))
        { pc = 0x13df9; break; }
    memoryASet16(ds, 0x5fe8, r16[si]);
    r16[di] = 0x2d12;
    yield* sub_10590();
  case 0x13df9:
    r16[si] = memoryAGet16(es, r16[bx] + 562);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fea))
        { pc = 0x13e12; break; }
    memoryASet16(ds, 0x5fea, r16[si]);
    r16[di] = 0x2d14;
    yield* sub_10590();
  case 0x13e12:
    r16[si] = memoryAGet16(es, r16[bx] + 564);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fec))
        { pc = 0x13e2b; break; }
    memoryASet16(ds, 0x5fec, r16[si]);
    r16[di] = 0x2d16;
    yield* sub_10590();
  case 0x13e2b:
    r16[si] = memoryAGet16(es, r16[bx] + 566);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5fee))
        { pc = 0x13e44; break; }
    memoryASet16(ds, 0x5fee, r16[si]);
    r16[di] = 0x2d18;
    yield* sub_10590();
  case 0x13e44:
    r16[si] = memoryAGet16(es, r16[bx] + 568);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ff0))
        { pc = 0x13e5d; break; }
    memoryASet16(ds, 0x5ff0, r16[si]);
    r16[di] = 0x2d1a;
    yield* sub_10590();
  case 0x13e5d:
    r16[si] = memoryAGet16(es, r16[bx] + 570);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ff2))
        { pc = 0x13e76; break; }
    memoryASet16(ds, 0x5ff2, r16[si]);
    r16[di] = 0x2d1c;
    yield* sub_10590();
  case 0x13e76:
    r16[si] = memoryAGet16(es, r16[bx] + 572);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ff4))
        { pc = 0x13e8f; break; }
    memoryASet16(ds, 0x5ff4, r16[si]);
    r16[di] = 0x2d1e;
    yield* sub_10590();
  case 0x13e8f:
    r16[si] = memoryAGet16(es, r16[bx] + 574);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ff6))
        { pc = 0x13ea8; break; }
    memoryASet16(ds, 0x5ff6, r16[si]);
    r16[di] = 0x2d20;
    yield* sub_10590();
  case 0x13ea8:
    r16[si] = memoryAGet16(es, r16[bx] + 576);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ff8))
        { pc = 0x13ec1; break; }
    memoryASet16(ds, 0x5ff8, r16[si]);
    r16[di] = 0x2d22;
    yield* sub_10590();
  case 0x13ec1:
    r16[si] = memoryAGet16(es, r16[bx] + 578);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ffa))
        { pc = 0x13eda; break; }
    memoryASet16(ds, 0x5ffa, r16[si]);
    r16[di] = 0x2d24;
    yield* sub_10590();
  case 0x13eda:
    r16[si] = memoryAGet16(es, r16[bx] + 580);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ffc))
        { pc = 0x13ef3; break; }
    memoryASet16(ds, 0x5ffc, r16[si]);
    r16[di] = 0x2d26;
    yield* sub_10590();
  case 0x13ef3:
    r16[si] = memoryAGet16(es, r16[bx] + 582);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x5ffe))
        { pc = 0x13f0c; break; }
    memoryASet16(ds, 0x5ffe, r16[si]);
    r16[di] = 0x2d28;
    yield* sub_10590();
  case 0x13f0c:
    r16[si] = memoryAGet16(es, r16[bx] + 584);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x6000))
        { pc = 0x13f25; break; }
    memoryASet16(ds, 0x6000, r16[si]);
    r16[di] = 0x2d2a;
    yield* sub_10590();
  case 0x13f25:
    r16[si] = memoryAGet16(es, r16[bx] + 586);
    r16[si] <<= 1;
    r16[si] = memoryAGet16(ss, r16[bp] + r16[si]);
    if (r16[si] == memoryAGet16(ds, 0x6002))
        { pc = 0x13f3e; break; }
    memoryASet16(ds, 0x6002, r16[si]);
    r16[di] = 0x2d2c;
    yield* sub_10590();
  case 0x13f3e:
    r16[bx] += memoryAGet16(ds, 0x5654);
    sp += 2; cs = pop();
    return;
  }
}
function fixReloc(seg)
{
        memoryASet16(seg, 0x0001, memoryAGet16(seg, 0x0001) + seg); // 1305 -> 14f2; lin=1
        memoryASet16(0x000d + seg, 0x000e, memoryAGet16(0x000d + seg, 0x000e) + seg); // 1303 -> 14f0; lin=de
        memoryASet16(0x0011 + seg, 0x0000, memoryAGet16(0x0011 + seg, 0x0000) + seg); // 1304 -> 14f1; lin=110
        memoryASet16(0x012a + seg, 0x000d, memoryAGet16(0x012a + seg, 0x000d) + seg); // 1208 -> 13f5; lin=12ad
        memoryASet16(0x0b7a + seg, 0x000c, memoryAGet16(0x0b7a + seg, 0x000c) + seg); // 0e6c -> 1059; lin=b7ac
        memoryASet16(0x0b7b + seg, 0x0004, memoryAGet16(0x0b7b + seg, 0x0004) + seg); // 0e6c -> 1059; lin=b7b4
        memoryASet16(0x0bc4 + seg, 0x000d, memoryAGet16(0x0bc4 + seg, 0x000d) + seg); // 1305 -> 14f2; lin=bc4d
        memoryASet16(0x0bc6 + seg, 0x0008, memoryAGet16(0x0bc6 + seg, 0x0008) + seg); // 1305 -> 14f2; lin=bc68
        memoryASet16(0x0bc8 + seg, 0x000e, memoryAGet16(0x0bc8 + seg, 0x000e) + seg); // 1305 -> 14f2; lin=bc8e
        memoryASet16(0x0bcb + seg, 0x0004, memoryAGet16(0x0bcb + seg, 0x0004) + seg); // 1305 -> 14f2; lin=bcb4
        memoryASet16(0x0bce + seg, 0x0005, memoryAGet16(0x0bce + seg, 0x0005) + seg); // 1305 -> 14f2; lin=bce5
        memoryASet16(0x0bd1 + seg, 0x0006, memoryAGet16(0x0bd1 + seg, 0x0006) + seg); // 1305 -> 14f2; lin=bd16
        memoryASet16(0x0bd5 + seg, 0x0002, memoryAGet16(0x0bd5 + seg, 0x0002) + seg); // 1305 -> 14f2; lin=bd52
        memoryASet16(0x0bd8 + seg, 0x000e, memoryAGet16(0x0bd8 + seg, 0x000e) + seg); // 1305 -> 14f2; lin=bd8e
        memoryASet16(0x0be1 + seg, 0x000e, memoryAGet16(0x0be1 + seg, 0x000e) + seg); // 1305 -> 14f2; lin=be1e
        memoryASet16(0x0bf9 + seg, 0x000e, memoryAGet16(0x0bf9 + seg, 0x000e) + seg); // 1305 -> 14f2; lin=bf9e
        memoryASet16(0x0d1c + seg, 0x0007, memoryAGet16(0x0d1c + seg, 0x0007) + seg); // 1305 -> 14f2; lin=d1c7
}

