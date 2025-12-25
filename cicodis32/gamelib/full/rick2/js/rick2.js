function init()
{
    headerSize = 0x0200;
    loadAddress = 0x1000;
    endAddress = 0x1c80;
    cs = 0x1040;
    ds = 0x1030;
    es = 0x1030;
    ss = 0x1000;
    sp = 0x0400;
    load("rick2.zip", "RICK2.EXE", 50927);
    fixReloc(loadAddress);
}

function* start()
{
    yield* sub_1c276();
}

function* sub_10524() // 1040:0124
{
    r8[ah] = 0x0f;
    interrupt(0x10);
    memorySet(ds, 0x006a, r8[al]);
    r16[ax] = 0x000d;
    interrupt(0x10);
}
function* sub_10533() // 1040:0133
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[ah] = 0x48;
    r16[bx] = 0x0200;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x1053f; break; }
    yield* sub_19731();
    return;
  case 0x1053f:
    memorySet16(ds, 0x004c, r16[ax]);
    r8[ah] = 0x48;
    r16[bx] = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x1054e; break; }
    yield* sub_19731();
    return;
  case 0x1054e:
    memorySet16(ds, 0x0062, r16[ax]);
    r8[ah] = 0x48;
    r16[bx] = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x1055d; break; }
    yield* sub_19731();
    return;
  case 0x1055d:
    memorySet16(ds, 0x0064, r16[ax]);
    r8[ah] = 0x48;
    r16[bx] = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x1056c; break; }
    yield* sub_19731();
    return;
  case 0x1056c:
    memorySet16(ds, 0x0066, r16[ax]);
    r8[ah] = 0x48;
    r16[bx] = 0x0aaa;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x1057b; break; }
    yield* sub_19731();
    return;
  case 0x1057b:
    memorySet16(ds, 0x0068, r16[ax]);
    r8[ah] = 0x48;
    r16[bx] = 0x0080;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x1058a; break; }
    yield* sub_19731();
    return;
  case 0x1058a:
    memorySet16(ds, 0x0052, r16[ax]);
    memorySet16(ds, 0x0056, 0xa400);
    return;
  }
}
function* sub_10594() // 1040:0194
{
    r16[ax] = memoryGet16(ds, 0x0062);
    r16[cx] = 0x4344;
    r16[dx] = 0x00cd;
    yield* sub_1a65b();
}
function* sub_105a1() // 1040:01a1
{
    r16[ax] = memoryGet16(ds, 0x004c);
    r16[cx] = 0x0000;
    r16[dx] = 0x00e5;
    yield* sub_1a65b();
    r16[cx] = 0x0400;
    r16[ax] = 0xa680;
    yield* sub_105f7();
    r16[ax] = memoryGet16(ds, 0x004c);
    r16[cx] = 0x0000;
    r16[dx] = 0x00f1;
    yield* sub_1a65b();
    r16[cx] = 0x0080;
    r16[ax] = 0xa700;
    yield* sub_105f7();
}
function* sub_105cc() // 1040:01cc
{
    r16[ax] = memoryGet16(ds, 0x004c);
    r16[cx] = 0x0000;
    r16[dx] = 0x00d9;
    yield* sub_1a65b();
    r16[cx] = 0x0400;
    r16[ax] = 0xa600;
    yield* sub_105f7();
    r16[ax] = memoryGet16(ds, 0x004c);
    r16[cx] = 0x0000;
    r16[dx] = 0x00fd;
    yield* sub_1a65b();
    r16[cx] = 0x0180;
    r16[ax] = 0xa980;
    yield* sub_105f7();
}
function* sub_105f7() // 1040:01f7
{
    push(ds);
    push(es);
    r16[bp] = r16[cx];
    r16[dx] = memoryGet16(ds, 0x004c);
    ds = r16[dx];
    es = r16[ax];
    r16[si] = 0;
    r16[di] = 0;
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
    r16[cx] = r16[bp];
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_VideoFwdESDI_MemFwdDSSI();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0202;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = r16[bp];
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_VideoFwdESDI_MemFwdDSSI();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0402;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = r16[bp];
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_VideoFwdESDI_MemFwdDSSI();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0802;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = r16[bp];
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_VideoFwdESDI_MemFwdDSSI();
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
function* sub_10661() // 1040:0261
{
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
}
function* sub_10702() // 1040:0302
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memorySet(ds, 0x0279, 0x00);
    r16[si] = 0x029a;
    r16[di] = 0x02ce;
    r16[cx] = 0x0033;
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
    r16[ax] = 0x1a00;
    interrupt(0x10);
    if (r8s[bl] <= signed8(0x05))
        { pc = 0x10731; break; }
    if (r8s[bl] < signed8(0x07))
        { pc = 0x10731; break; }
    if (r8s[bl] > signed8(0x08))
        { pc = 0x10731; break; }
    r16[si] = 0x028a;
    memorySet(ds, 0x0279, 0x01);
    { pc = 0x1073e; break; }
    // gap 1 bytes
  case 0x10731:
    r16[si] = 0x027a;
    memorySet(ds, 0x0279, 0x00);
    memorySet(ds, 0x0278, 0x01);
  case 0x1073e:
    memorySet(ds, 0x0301, 0x00);
    r16[cx] = 0x0010;
  case 0x10746:
    r8[ah] = 0x10;
    r8[al] = 0x00;
    r8[bh] = memoryGet(ds, r16[si]);
    r16[si]++;
    r8[bl] = memoryGet(ds, 0x0301);
    memorySet(ds, 0x0301, memoryGet(ds, 0x0301) + 1);
    push(r16[si]);
    push(r16[cx]);
    interrupt(0x10);
    r16[cx] = pop();
    r16[si] = pop();
    if (--r16[cx])
        { pc = 0x10746; break; }
    if (memoryGet(ds, 0x0279) != 0x01)
        { pc = 0x1076a; break; }
    yield* sub_10776();
    yield* sub_1079d();
  case 0x1076a:
    r16[di] = 0x029a;
    r16[si] = 0x02ce;
    r16[cx] = 0x0033;
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
    return;
  }
}
function* sub_10776() // 1040:0376
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] = 0x029a;
    memorySet(ds, 0x0301, 0x00);
    r16[cx] = 0x0010;
  case 0x10781:
    push(r16[cx]);
    r8[bh] = 0x09;
    r8[al] = memoryGet(ds, r16[si]);
    r16[ax] = (r8s[bh] * r16s[ax]) & 0xffff;
    memorySet(ds, r16[si], r8[al]);
    r16[si]++;
    r8[al] = memoryGet(ds, r16[si]);
    r16[ax] = (r8s[bh] * r16s[ax]) & 0xffff;
    memorySet(ds, r16[si], r8[al]);
    r16[si]++;
    r8[al] = memoryGet(ds, r16[si]);
    r16[ax] = (r8s[bh] * r16s[ax]) & 0xffff;
    memorySet(ds, r16[si], r8[al]);
    r16[si]++;
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x10781; break; }
    return;
  }
}
function* sub_1079d() // 1040:039d
{
    r16[bx] = 0;
    r16[cx] = 0x0010;
    r16[dx] = 0x029a;
    r8[al] = 0x12;
    r8[ah] = 0x10;
    interrupt(0x10);
}
function* sub_107ac() // 1040:03ac
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[dx] = 0;
    r16[cx] = r16[dx];
    r8[ch] = r8[ah];
    r8[dh] = r8[ah];
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[dx] += r16[cx];
    r8[ah] = 0;
    r16[dx] += r16[ax];
    r16[di] = r16[dx];
    push(ds);
    push(es);
    es = memoryGet16(ds, 0x005a);
    r16[cx] = 0x0027;
    r16[ax] = 0xa980;
    ds = r16[ax];
  case 0x107ce:
    r16[ax] = 0;
    r8[al] = memoryGet(cs, r16[si]);
    r16[si]++;
    if (r8[al] == 0xff)
        { pc = 0x107ee; break; }
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = r16[si];
    r16[si] = r16[ax];
    r16[ax] = r16[di];
    yield* sub_10661();
    r16[si] = r16[bx];
    r16[di] = r16[ax];
    r16[di]++;
    { pc = 0x107ce; break; }
  case 0x107ee:
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_107f1() // 1040:03f1
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[dx] = 0;
    r16[cx] = r16[dx];
    r8[ch] = r8[ah];
    r8[dh] = r8[ah];
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[dx] += r16[cx];
    r8[ah] = 0;
    r16[dx] += r16[ax];
    r16[di] = r16[dx];
    push(ds);
    push(es);
    es = memoryGet16(ds, 0x005a);
    r16[cx] = 0x0027;
    r16[ax] = 0xa600;
    ds = r16[ax];
  case 0x10813:
    r16[ax] = 0;
    r8[al] = memoryGet(cs, r16[si]);
    r16[si]++;
    if (r8[al] == 0xff)
        { pc = 0x10833; break; }
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = r16[si];
    r16[si] = r16[ax];
    r16[ax] = r16[di];
    yield* sub_10661();
    r16[si] = r16[bx];
    r16[di] = r16[ax];
    r16[di]++;
    { pc = 0x10813; break; }
  case 0x10833:
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_10836() // 1040:0436
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[dx] = 0;
    r16[cx] = r16[dx];
    r8[ch] = r8[ah];
    r8[dh] = r8[ah];
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[dx] += r16[cx];
    r8[ah] = 0;
    r16[dx] += r16[ax];
    r16[di] = r16[dx];
    push(ds);
    push(es);
    es = memoryGet16(ds, 0x005c);
    r16[cx] = 0x0027;
    r16[ax] = 0xa600;
    ds = r16[ax];
  case 0x10858:
    r16[ax] = 0;
    r8[al] = memoryGet(cs, r16[si]);
    r16[si]++;
    if (r8[al] == 0xff)
        { pc = 0x10878; break; }
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[bx] = r16[si];
    r16[si] = r16[ax];
    r16[ax] = r16[di];
    yield* sub_10661();
    r16[si] = r16[bx];
    r16[di] = r16[ax];
    r16[di]++;
    { pc = 0x10858; break; }
  case 0x10878:
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_1087b() // 1040:047b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[cx] = 0x0100;
    r16[ax] = 0x0000;
    r16[dx] = 0x0008;
    r16[di] = 0x2f73;
  case 0x10887:
    stosw_MemFwdESDI(r16[ax]);
    r16[ax] += r16[dx];
    if (--r16[cx])
        { pc = 0x10887; break; }
    return;
  }
}
function* sub_1088d() // 1040:048d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    es = memoryGet16(ds, 0x0056);
    r16[ax] = 0xa680;
    ds = r16[ax];
    r16[cx] = 0x0020;
  case 0x1089b:
    r16[bp] = r16[cx];
    r16[ax] = 0;
    r8[al] = memoryGet(cs, r16[bx]);
    if (r16s[ax] < signed16(0x00f8))
        { pc = 0x108aa; break; }
    yield* sub_19593();
  case 0x108aa:
    r16[bx]++;
    r16[ax] <<= 1;
    r16[ax] += 0x2f73;
    r16[si] = r16[ax];
    r16[si] = memoryGet16(cs, r16[si]);
    r16[cx] = 0x001f;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[cx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0xff20;
    r16[cx] = r16[bp];
    if (--r16[cx])
        { pc = 0x1089b; break; }
    r16[di] += 0x00e0;
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_108dd() // 1040:04dd
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx] = 0x571c;
    r16[di] = 0x1e00;
    yield* sub_1088d();
    r16[di] = 0x0000;
    r16[bx] = 0x573c;
    r16[cx] = 0x001a;
  case 0x108ef:
    push(r16[cx]);
    yield* sub_1088d();
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x108ef; break; }
    return;
  }
}
function* sub_108f7() // 1040:04f7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (!r16[ax])
        { pc = 0x1091a; break; }
    push(ds);
    push(es);
    r16[dx] = r16[ax];
    r16[bp] = 0x0020;
    r16[bx] = 0x0008;
    es = memoryGet16(cs, 0x005a);
    ds = memoryGet16(cs, 0x0056);
  case 0x1090f:
    r16[cx] = r16[bp];
    for (; r16[cx] != 0; --r16[cx]) movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += r16[bx];
    r16[dx]--;
    if (r16[dx])
        { pc = 0x1090f; break; }
    es = pop();
    ds = pop();
  case 0x1091a:
    return;
  }
}
function* sub_1091b() // 1040:051b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[dx] = memoryGet16(ds, 0x6c45);
    r16[dx] += 0x00c0;
    r16[dx] &= 0x00ff;
    if (r16s[dx] > signed16(memoryGet16(ds, 0x6c45)))
        { pc = 0x10969; break; }
    r16[ax] = r16[dx];
    r16[si] = 0x0000;
    r16[di] = 0x0144;
    r16[dx] = 0x0100;
    r16[dx] -= memoryGet16(ds, 0x6c45);
    r16[dx] += r16[dx];
    r16[bx] = 0x3173;
    r16[bx] += r16[dx];
    r16[di] += memoryGet16(ds, r16[bx]);
    yield* sub_108f7();
    r16[si] = 0x0000;
    r16[dx] = memoryGet16(ds, 0x6c45);
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[si] += r16[dx];
    r16[di] = 0x0144;
    r16[ax] = 0x0100;
    r16[ax] -= memoryGet16(ds, 0x6c45);
    yield* sub_108f7();
    return;
  case 0x10969:
    r16[si] = 0x0000;
    r16[dx] = memoryGet16(ds, 0x6c45);
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[si] += r16[dx];
    r16[di] = 0x0144;
    r16[ax] = 0x00c0;
    yield* sub_108f7();
    return;
  }
}
function* sub_10986() // 1040:0586
{
    r16[bx] = 0x573c;
    r16[ax] = memoryGet16(ds, 0x6c45);
    r16[ax] &= 0x00f8;
    r16[ax] -= 0x0008;
    r16[ax] &= 0x00ff;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[di] = r16[ax];
    yield* sub_1088d();
}
function* sub_109a5() // 1040:05a5
{
    r16[bx] = 0x5a5c;
    r16[ax] = memoryGet16(ds, 0x6c45);
    r16[ax] &= 0x00f8;
    r16[ax] += 0x00d0;
    r16[ax] &= 0x00ff;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[di] = r16[ax];
    yield* sub_1088d();
}
function* sub_109c4() // 1040:05c4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[di] = 0x3173;
    r16[ax] = 0;
    r16[cx] = 0x0100;
  case 0x109cc:
    stosw_MemFwdESDI(r16[ax]);
    r16[ax] += 0x0028;
    if (--r16[cx])
        { pc = 0x109cc; break; }
    return;
  }
}
function* sub_109d3() // 1040:05d3
{
    memorySet16(ds, 0x005a, 0xa000);
    memorySet16(ds, 0x005c, 0xa200);
    memorySet16(ds, 0x005e, 0x0000);
    memorySet16(ds, 0x0060, 0x2000);
}
function* sub_109ee() // 1040:05ee
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    r16[ax] = memoryGet16(ds, 0x005a);
    r16[dx] = memoryGet16(ds, 0x005c);
    memorySet16(ds, 0x005c, r16[ax]);
    memorySet16(ds, 0x005a, r16[dx]);
    r16[ax] = memoryGet16(ds, 0x005e);
    r16[dx] = memoryGet16(ds, 0x0060);
    memorySet16(ds, 0x0060, r16[ax]);
    memorySet16(ds, 0x005e, r16[dx]);
    r16[cx] = memoryGet16(ds, 0x0060);
    push(r16[dx]);
    push(r16[ax]);
    r16[ax] = 0x0040;
    es = r16[ax];
    r16[dx] = memoryBiosGet16(es, 0x0063);
    r16[dx] += 0x0006;
  case 0x10a22:
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x08;
    if (r8[al])
        { pc = 0x10a22; break; }
  case 0x10a27:
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x08;
    if (!r8[al])
        { pc = 0x10a27; break; }
    r16[dx] -= 0x0006;
    flags.interrupts = 0;
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
    flags.interrupts = 1;
    r8[ah] = r8[ch];
    r16[ax] <<= 1;
    memoryBiosSet16(es, 0x004e, r16[ax]);
    r16[ax] = 0x0040;
    es = r16[ax];
    r16[dx] = memoryBiosGet16(es, 0x0063);
    r16[dx] += 0x0006;
  case 0x10a55:
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x08;
    if (r8[al])
        { pc = 0x10a55; break; }
  case 0x10a5a:
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x08;
    if (!r8[al])
        { pc = 0x10a5a; break; }
    r16[ax] = pop();
    r16[dx] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    yield* sync();
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_10a67() // 1040:0667
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x9173))
        { pc = 0x10a6f; break; }
    return;
  case 0x10a6f:
    r16[bx] = memoryGet16(ds, 0x9175);
    r16[cx] = 0x0008;
  case 0x10a76:
    push(r16[cx]);
    r8[al] = memoryGet(ds, r16[bx]);
    if (!r8[al])
        { pc = 0x10ad2; break; }
    if (r8s[al] < 0)
        { pc = 0x10adc; break; }
    r16[dx] = 0;
    r8[dl] = memoryGet(ds, r16[bx] + 1);
    r8[cl] = r8[dl];
    r8[cl]++;
    r8[cl] &= 0x03;
    r8[dl] &= 0xfc;
    r8[dl] |= r8[cl];
    memorySet(ds, r16[bx] + 1, r8[dl]);
    r16[di] = memoryGet16(ds, r16[bx] + 4);
    r16[bp] = memoryGet16(cs, r16[bx] + 6);
    r16[si] = 0;
    push(ds);
    push(es);
    es = memoryGet16(ds, 0x0056);
    r16[ax] = 0xa700;
    ds = r16[ax];
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[si] = r16[dx];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x001f;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x001f;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x001f;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x001f;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x001f;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x001f;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x001f;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    es = pop();
    ds = pop();
  case 0x10ad2:
    r16[bx] += 0x0008;
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x10a76; break; }
    { pc = 0x10ae2; break; }
    // gap 1 bytes
  case 0x10adc:
    r16[bx] = 0x54fa;
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x10a76; break; }
  case 0x10ae2:
    memorySet16(ds, 0x9175, r16[bx]);
    return;
  }
}
function* sub_10ae7() // 1040:06e7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    r16[bx] = 0x573c;
    r16[di] = 0x0144;
    es = memoryGet16(ds, 0x0056);
    r16[ax] = 0xa680;
    ds = r16[ax];
    r16[cx] = 0x0018;
    r16[dx] = memoryGet16(cs, 0x8bf0);
    r16[dx] &= 0x0007;
    if (!r16[dx])
        { pc = 0x10b43; break; }
    r16[si] = r16[dx];
    r16[bp] = 0x0020;
    r16[dx] ^= 0x0007;
  case 0x10b0d:
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0;
    r8[al] = memoryGet(cs, r16[bx]);
    r16[bx]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[si] += r16[ax];
    push(r16[dx]);
  case 0x10b1e:
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    r16[dx]--;
    if (r16s[dx] >= 0)
        { pc = 0x10b1e; break; }
    r16[dx] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[di]++;
    r16[bp]--;
    if (r16[bp])
        { pc = 0x10b0d; break; }
    r16[dx]++;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[ax] = r16[dx];
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] += r16[ax];
    r16[dx] += 0xffe0;
    r16[di] += r16[dx];
    { pc = 0x10b80; break; }
    // gap 1 bytes
  case 0x10b43:
    r16[bp] = 0x0020;
  case 0x10b46:
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0;
    r8[al] = memoryGet(cs, r16[bx]);
    r16[bx]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[si] = r16[ax];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    r16[di] = pop();
    r16[si] = pop();
    r16[di]++;
    r16[bp]--;
    if (r16[bp])
        { pc = 0x10b46; break; }
    r16[di] += 0x0120;
  case 0x10b80:
    if (--r16[cx])
        { pc = 0x10b43; break; }
    r16[dx] = memoryGet16(cs, 0x8bf0);
    r16[dx] &= 0x0007;
    if (!r16[dx])
        { pc = 0x10bae; break; }
    r16[bp] = 0x0020;
  case 0x10b8f:
    push(r16[si]);
    push(r16[di]);
    r16[ax] = 0;
    r8[al] = memoryGet(cs, r16[bx]);
    r16[bx]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[si] = r16[ax];
    push(r16[dx]);
  case 0x10ba0:
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] += 0x0027;
    r16[dx]--;
    if (r16s[dx] >= 0)
        { pc = 0x10ba0; break; }
    r16[dx] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[di]++;
    r16[bp]--;
    if (r16[bp])
        { pc = 0x10b8f; break; }
  case 0x10bae:
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_10bb1() // 1040:07b1
{
    r16[ax] = memoryGet16(ds, 0x005a);
    push(r16[ax]);
    r16[ax] = memoryGet16(ds, 0x0056);
    memorySet16(ds, 0x005a, r16[ax]);
    yield* sub_11162();
    r16[ax] = pop();
    memorySet16(ds, 0x005a, r16[ax]);
}
function* sub_10bc4() // 1040:07c4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[cx] = memoryGet16(ds, 0x96f4);
    push(r16[cx]);
    memorySet16(ds, 0x96f4, 0x0001);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_1091b();
    memorySet16(ds, 0x0b1c, 0x0000);
    yield* sub_11162();
    memorySet16(ds, 0x0b1c, 0x0001);
    r16[dx] = pop();
    r16[ax] = pop();
    yield* sub_19351();
    yield* sub_19214();
    yield* sub_10ae7();
    yield* sub_1618f();
    yield* sub_15fe4();
    memorySet(ds, 0x5b3e, 0x01);
    yield* sub_15f40();
    memorySet(ds, 0x5b3e, 0x00);
    yield* sub_10bb1();
    yield* sub_19af6();
    yield* sub_109ee();
    r16[si] = 0x0162;
    r16[cx] = 0x0010;
  case 0x10c15:
    push(r16[cx]);
    push(r16[si]);
    yield* sub_10c98();
    yield* sub_109ee();
    r16[si] = pop();
    r16[cx] = pop();
    r16[si] += 0xfffe;
    if (--r16[cx])
        { pc = 0x10c15; break; }
    yield* sub_17047();
    r16[cx] = pop();
    memorySet16(ds, 0x96f4, r16[cx]);
    return;
  }
}
function* sub_10c2e() // 1040:082e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[cx] = memoryGet16(ds, 0x96f4);
    push(r16[cx]);
    memorySet16(ds, 0x96f4, 0x0001);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_1091b();
    memorySet16(ds, 0x0b1c, 0x0000);
    yield* sub_11162();
    memorySet16(ds, 0x0b1c, 0x0001);
    r16[dx] = pop();
    r16[ax] = pop();
    yield* sub_19351();
    yield* sub_19214();
    yield* sub_1618f();
    yield* sub_10ae7();
    yield* sub_15fe4();
    memorySet(ds, 0x5b3e, 0x01);
    yield* sub_15f40();
    memorySet(ds, 0x5b3e, 0x00);
    yield* sub_10bb1();
    yield* sub_19af6();
    yield* sub_109ee();
    r16[si] = 0x0144;
    r16[cx] = 0x0010;
  case 0x10c7f:
    push(r16[cx]);
    push(r16[si]);
    yield* sub_10ccd();
    yield* sub_109ee();
    r16[si] = pop();
    r16[cx] = pop();
    r16[si] += 0x0002;
    if (--r16[cx])
        { pc = 0x10c7f; break; }
    yield* sub_17047();
    r16[cx] = pop();
    memorySet16(ds, 0x96f4, r16[cx]);
    return;
  }
}
function* sub_10c98() // 1040:0898
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    r16[bx] = 0x0144;
    r16[di] = r16[bx];
    r16[bp] = 0x00c0;
    es = memoryGet16(ds, 0x005a);
    r16[ax] = memoryGet16(ds, 0x0056);
    r16[dx] = memoryGet16(ds, 0x005c);
  case 0x10cad:
    ds = r16[ax];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    movsb_VideoFwdESDI_VideoFwdDSSI();
    ds = r16[dx];
    push(r16[si]);
    r16[si] = r16[bx];
    r16[cx] = 0x001e;
    for (; r16[cx] != 0; --r16[cx]) movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[bx] = r16[si];
    r16[si] = pop();
    r16[bx] += 0x000a;
    r16[si] += 0x0026;
    r16[di] += 0x0008;
    r16[bp]--;
    if (r16[bp])
        { pc = 0x10cad; break; }
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_10ccd() // 1040:08cd
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    r16[bx] = 0x0146;
    r16[di] = 0x0144;
    r16[bp] = 0x00c0;
    es = memoryGet16(ds, 0x005a);
    r16[ax] = memoryGet16(ds, 0x0056);
    r16[dx] = memoryGet16(ds, 0x005c);
  case 0x10ce3:
    ds = r16[dx];
    push(r16[si]);
    r16[si] = r16[bx];
    r16[cx] = 0x001e;
    for (; r16[cx] != 0; --r16[cx]) movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[bx] = r16[si];
    r16[si] = pop();
    ds = r16[ax];
    movsb_VideoFwdESDI_VideoFwdDSSI();
    movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[bx] += 0x000a;
    r16[si] += 0x0026;
    r16[di] += 0x0008;
    r16[bp]--;
    if (r16[bp])
        { pc = 0x10ce3; break; }
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_10d03() // 1040:0903
{
    push(ds);
    push(es);
    r16[ax] = 0xa700;
    ds = r16[ax];
    es = memoryGet16(cs, 0x005a);
    r16[si] = 0x0100;
    r8[al] = lodsb_VideoFwdDSSI();
    r16[di] = 0;
    r16[cx] = 0x1f40;
    for (; r16[cx] != 0; --r16[cx]) stosb_VideoFwdESDI(r8[al]);
    es = pop();
    ds = pop();
    yield* sub_19b1c();
    yield* sub_109ee();
    push(ds);
    push(es);
    r16[ax] = 0xa700;
    ds = r16[ax];
    es = memoryGet16(cs, 0x005a);
    r16[si] = 0x0100;
    r8[al] = lodsb_VideoFwdDSSI();
    r16[di] = 0;
    r16[cx] = 0x1f40;
    for (; r16[cx] != 0; --r16[cx]) stosb_VideoFwdESDI(r8[al]);
    es = pop();
    ds = pop();
}
function* sub_10d3d() // 1040:093d
{
    r16[ax] = memoryGet16(ds, 0x0062);
    r16[cx] = 0x0000;
    r16[dx] = 0x010a;
    yield* sub_1a65b();
    yield* sub_10d5c();
    r16[ax] = memoryGet16(ds, 0x0062);
    r16[cx] = 0x0000;
    r16[dx] = 0x0116;
    yield* sub_1a65b();
    yield* sub_10daa();
}
function* sub_10d5c() // 1040:095c
{
    push(ds);
    push(es);
    r16[ax] = memoryGet16(ds, 0x0062);
    ds = r16[ax];
    r16[ax] = 0xa780;
    es = r16[ax];
    r16[si] = 0;
    r16[di] = 0;
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
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_VideoFwdESDI_MemFwdDSSI();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0202;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = 0x0fa0;
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_VideoFwdESDI_MemFwdDSSI();
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
function* sub_10daa() // 1040:09aa
{
    push(ds);
    push(es);
    r16[ax] = memoryGet16(ds, 0x0062);
    ds = r16[ax];
    r16[ax] = 0xa780;
    es = r16[ax];
    r16[si] = 0;
    r16[di] = 0;
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
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_VideoFwdESDI_MemFwdDSSI();
    push(r16[dx]);
    r16[dx] = 0x03c4;
    r16[ax] = 0x0802;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[cx] = 0x0fa0;
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_VideoFwdESDI_MemFwdDSSI();
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
function* sub_10df8() // 1040:09f8
{
    push(ds);
    push(es);
    r16[ax] = 0xa780;
    ds = r16[ax];
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[si] = 0;
    r16[di] = r16[si];
    r16[cx] = 0x1f40;
    for (; r16[cx] != 0; --r16[cx]) movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[ax] = 0xa780;
    ds = r16[ax];
    r16[ax] = 0xa200;
    es = r16[ax];
    r16[si] = 0;
    r16[di] = r16[si];
    r16[cx] = 0x1f40;
    for (; r16[cx] != 0; --r16[cx]) movsb_VideoFwdESDI_VideoFwdDSSI();
    es = pop();
    ds = pop();
}
function* sub_10e23() // 1040:0a23
{
    r16[dx] = 0;
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
    r16[di] = r16[dx];
    r8[ah] = 0;
    r16[di] += r16[ax];
}
function* sub_10e40() // 1040:0a40
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    r16[ax] = 0xa600;
    ds = r16[ax];
    es = memoryGet16(cs, 0x0056);
  case 0x10e4c:
    push(r16[cx]);
    push(r16[si]);
    push(r16[di]);
  case 0x10e4f:
    r16[ax] = 0;
    r8[al] = memoryGet(cs, r16[si]);
    r16[si]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[si]);
    push(r16[di]);
    r16[si] = r16[ax];
    push(r16[cx]);
    r16[cx] = 0x0027;
    yield* sub_10661();
    r16[cx] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[di]++;
    r8[cl]--;
    if (r8[cl])
        { pc = 0x10e4f; break; }
    r16[di] = pop();
    r16[di] += 0x0140;
    r16[si] = pop();
    r16[si] += 0x0020;
    r16[cx] = pop();
    r8[ch]--;
    if (r8[ch])
        { pc = 0x10e4c; break; }
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_10e7f() // 1040:0a7f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    es = memoryGet16(ds, 0x005a);
    ds = memoryGet16(ds, 0x0056);
    r16[di] = 0x0144;
    r16[si] = r16[di];
    r16[bp] = 0x00c0;
  case 0x10e91:
    r16[cx] = 0x0020;
    push(r16[si]);
    push(r16[di]);
    for (; r16[cx] != 0; --r16[cx]) movsb_VideoFwdESDI_VideoFwdDSSI();
    r16[di] = pop();
    r16[si] = pop();
    r16[si] += 0x0028;
    r16[di] += 0x0028;
    r16[bp]--;
    if (r16[bp])
        { pc = 0x10e91; break; }
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_10ea6() // 1040:0aa6
{
    push(ds);
    push(es);
    r16[ax] = 0xa700;
    ds = r16[ax];
    es = memoryGet16(cs, 0x0056);
    r16[si] = 0x0100;
    r8[al] = lodsb_VideoFwdDSSI();
    r16[di] = 0;
    r16[cx] = 0x1f40;
    for (; r16[cx] != 0; --r16[cx]) stosb_VideoFwdESDI(r8[al]);
    es = pop();
    ds = pop();
}
function* sub_10ec0() // 1040:0ac0
{
    r16[dx] = memoryGet16(ds, 0x005a);
    push(r16[dx]);
    r16[dx] = memoryGet16(ds, 0x0056);
    memorySet16(ds, 0x005a, r16[dx]);
    yield* sub_107f1();
    r16[dx] = pop();
    memorySet16(ds, 0x005a, r16[dx]);
}
function* sub_10ee4() // 1040:0ae4
{
}
function* sub_10ee5() // 1040:0ae5
{
}
function* sub_10ee6() // 1040:0ae6
{
}
function* sub_10ee7() // 1040:0ae7
{
}
function* sub_10ee8() // 1040:0ae8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = memoryGet16(cs, 0x96f4);
    if (r16[ax] == 0x0001)
        { pc = 0x10ef6; break; }
    r16[ax]--;
    memorySet16(cs, 0x96f4, r16[ax]);
  case 0x10ef6:
    return;
  }
}
function* sub_11162() // 1040:0d62
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    es = memoryGet16(ds, 0x005a);
    r16[si] = 0x0b00;
    r16[dx] = 0x03ce;
    r16[ax] = 0x0001;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0003;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0005;
    out16(r16[dx], r16[ax]);
  case 0x1117a:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16s[ax] < 0)
        { pc = 0x11196; break; }
    if (!r16[ax])
        { pc = 0x11191; break; }
    if (memoryGet16(ds, r16[si] + 10) == 0x00fe)
        { pc = 0x11191; break; }
    push(ds);
    push(r16[si]);
    yield* sub_111f1();
    r16[si] = pop();
    ds = pop();
  case 0x11191:
    r16[si] += 0x001c;
    { pc = 0x1117a; break; }
  case 0x11196:
    r16[si] = 0x0b56;
  case 0x11199:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r8s[ah] < 0)
        { pc = 0x111b7; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x111b2; break; }
    if (memoryGet16(ds, r16[si] + 10) == 0x00fe)
        { pc = 0x111b2; break; }
    push(ds);
    push(r16[si]);
    yield* sub_111f1();
    r16[si] = pop();
    ds = pop();
  case 0x111b2:
    r16[si] += 0x0034;
    { pc = 0x11199; break; }
  case 0x111b7:
    r16[si] = 0x0c28;
  case 0x111ba:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r8s[ah] < 0)
        { pc = 0x111d8; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x111d3; break; }
    if (memoryGet16(ds, r16[si] + 10) == 0x00fe)
        { pc = 0x111d3; break; }
    push(ds);
    push(r16[si]);
    yield* sub_111f1();
    r16[si] = pop();
    ds = pop();
  case 0x111d3:
    r16[si] += 0x0034;
    { pc = 0x111ba; break; }
  case 0x111d8:
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
  }
}
function* sub_111f1() // 1040:0df1
{
  var pc = 0;
  var temp_cond0;
  var temp_cond1;
  while (1) switch(pc)
  {
  case 0:
    r16[bp] = 0;
    r16[ax] = memoryGet16(ds, r16[si] + 4);
    r16[ax] -= 0x0038;
    r16[dx] = memoryGet16(ds, 0x8bf0);
    r16[dx] &= 0x0007;
    r16[ax] -= r16[dx];
    if (r16s[ax] >= signed16(0x0008))
        { pc = 0x1122c; break; }
    r16[cx] = 0x0008;
    r16[cx] -= r16[ax];
    r16[ax] = r16[cx];
    r16[cx] = -r16[cx];
    temp_cond0 = r16s[cx] + signed16(0x0015) > 0;
    r16[cx] += 0x0015;
    if (temp_cond0)
        { pc = 0x11218; break; }
    { pc = 0x112d5; break; }
  case 0x11218:
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] = r16[ax];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += r16[dx];
    r16[bp] = r16[ax];
    r16[ax] = 0x0140;
    { pc = 0x11252; break; }
    // gap 1 bytes
  case 0x1122c:
    if (r16s[ax] <= signed16(0x00b3))
        { pc = 0x11241; break; }
    r16[cx] = 0x00b3;
    r16[cx] -= r16[ax];
    temp_cond1 = r16s[cx] + signed16(0x0015) > 0;
    r16[cx] += 0x0015;
    if (temp_cond1)
        { pc = 0x1123e; break; }
    { pc = 0x112d5; break; }
  case 0x1123e:
    { pc = 0x11244; break; }
    // gap 1 bytes
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
    r16[di] = r16[ax];
    r16[ax] = memoryGet16(ds, r16[si] + 2);
    r16[ax] += 0x0020;
    r16[ax] &= 0xfff8;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[di] += r16[ax];
    r16[ax] = memoryGet16(ds, r16[si] + 10);
    if (r16s[ax] < signed16(0x0080))
        { pc = 0x11270; break; }
    r16[ax] -= 0x0040;
  case 0x11270:
    r16[bx] = 0x01a4;
    mul16(r16[bx]);
    r16[bx] = memoryGet16(ds, r16[si] + 2);
    r16[bx] += 0x0020;
    r16[bx] &= 0x0006;
    r16[bx] += 0x0062;
    ds = memoryGet16(ds, r16[bx]);
    r16[si] = r16[ax];
    r16[si] += r16[bp];
    r16[bp] = 0x0024;
    r8[dh] = 0x03;
  case 0x1128d:
    push(r16[cx]);
    r16[cx] = 0x0004;
  case 0x11291:
    r8[ah] = memoryGet(ds, r16[si]);
    if (!r8[ah])
        { pc = 0x112c9; break; }
    r8[al] = 0x08;
    r8[dl] = 0xce;
    out16(r16[dx], r16[ax]);
    r8[dl] = 0xc4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r8[ah] = memoryVideoGet(es, r16[di]);
    r8[ah] = 0x01;
    out16(r16[dx], r16[ax]);
    r8[ah] = memoryGet(ds, r16[si] + 1);
    memoryVideoSet(es, r16[di], r8[ah]);
    r8[ah] = 0x02;
    out16(r16[dx], r16[ax]);
    r8[ah] = memoryGet(ds, r16[si] + 2);
    memoryVideoSet(es, r16[di], r8[ah]);
    r8[ah] = 0x04;
    out16(r16[dx], r16[ax]);
    r8[ah] = memoryGet(ds, r16[si] + 3);
    memoryVideoSet(es, r16[di], r8[ah]);
    r8[ah] = 0x08;
    out16(r16[dx], r16[ax]);
    r8[ah] = memoryGet(ds, r16[si] + 4);
    memoryVideoSet(es, r16[di], r8[ah]);
  case 0x112c9:
    r16[di]++;
    r16[si] += 0x0005;
    if (--r16[cx])
        { pc = 0x11291; break; }
    r16[di] += r16[bp];
    r16[cx] = pop();
    r16[cx]--;
    if (r16[cx])
        { pc = 0x1128d; break; }
  case 0x112d5:
    return;
  }
}
function* sub_112d6() // 1040:0ed6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    ds = memoryGet16(ds, 0x0062);
    r16[bp] = 0x0064;
    r16[di] = 0;
    r16[si] = 0;
    r16[cx] = 0x0888;
  case 0x112e6:
    push(r16[cx]);
    push(r16[si]);
    push(r16[di]);
    r8[ah] = memoryGet(ds, r16[si]);
    r8[al] = memoryGet(ds, r16[si] + 5);
    r8[bh] = memoryGet(ds, r16[si] + 10);
    r8[bl] = 0x00;
    push(r16[bp]);
    r16[cx] = 0x0003;
  case 0x112f7:
    flags.carry = 0;
    r8[ah] = rcr8(r8[ah], 0x01);
    r8[al] = rcr8(r8[al], 0x01);
    r8[bh] = rcr8(r8[bh], 0x01);
    r8[bl] = rcr8(r8[bl], 0x01);
    flags.carry = 0;
    r8[ah] = rcr8(r8[ah], 0x01);
    r8[al] = rcr8(r8[al], 0x01);
    r8[bh] = rcr8(r8[bh], 0x01);
    r8[bl] = rcr8(r8[bl], 0x01);
    es = memoryGet16(cs, r16[bp]);
    r16[bp]++;
    r16[bp]++;
    memorySet(es, r16[di], r8[ah]);
    memorySet(es, r16[di] + 5, r8[al]);
    memorySet(es, r16[di] + 10, r8[bh]);
    memorySet(es, r16[di] + 15, r8[bl]);
    if (--r16[cx])
        { pc = 0x112f7; break; }
    r16[bp] = pop();
    r16[si]++;
    r16[di]++;
    r16[cx] = 0x0004;
  case 0x11326:
    push(r16[cx]);
    r8[ah] = memoryGet(ds, r16[si]);
    r8[al] = memoryGet(ds, r16[si] + 5);
    r8[bh] = memoryGet(ds, r16[si] + 10);
    r8[bl] = 0x00;
    push(r16[bp]);
    r16[cx] = 0x0003;
  case 0x11335:
    flags.carry = 0;
    r8[ah] = rcr8(r8[ah], 0x01);
    r8[al] = rcr8(r8[al], 0x01);
    r8[bh] = rcr8(r8[bh], 0x01);
    r8[bl] = rcr8(r8[bl], 0x01);
    flags.carry = 0;
    r8[ah] = rcr8(r8[ah], 0x01);
    r8[al] = rcr8(r8[al], 0x01);
    r8[bh] = rcr8(r8[bh], 0x01);
    r8[bl] = rcr8(r8[bl], 0x01);
    es = memoryGet16(cs, r16[bp]);
    r16[bp]++;
    r16[bp]++;
    memorySet(es, r16[di], r8[ah]);
    memorySet(es, r16[di] + 5, r8[al]);
    memorySet(es, r16[di] + 10, r8[bh]);
    memorySet(es, r16[di] + 15, r8[bl]);
    if (--r16[cx])
        { pc = 0x11335; break; }
    r16[bp] = pop();
    r16[si]++;
    r16[di]++;
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x11326; break; }
    r16[di] = pop();
    r16[si] = pop();
    r16[si] += 0x0014;
    r16[di] += 0x0014;
    r16[cx] = pop();
    r16[cx]--;
    if (!r16[cx])
        { pc = 0x11373; break; }
    { pc = 0x112e6; break; }
  case 0x11373:
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_11376() // 1040:0f76
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    es = memoryGet16(ds, 0x005a);
    r16[si] = 0x0b00;
    r16[dx] = 0x03ce;
    r16[ax] = 0x0001;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0003;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0005;
    out16(r16[dx], r16[ax]);
    r16[si] = 0x9bd6;
  case 0x11391:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16s[ax] < 0)
        { pc = 0x113b0; break; }
    if (!r16[ax])
        { pc = 0x113aa; break; }
    if (memoryGet16(ds, r16[si] + 10) == 0x00fe)
        { pc = 0x113aa; break; }
    push(r16[bx]);
    push(ds);
    push(r16[si]);
    yield* sub_111f1();
    r16[si] = pop();
    ds = pop();
    r16[bx] = pop();
  case 0x113aa:
    r16[si] += 0x001a;
    { pc = 0x11391; break; }
  case 0x113b0:
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
  }
}
function* sub_15f40() // 1040:5b40
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x762d) != 0x0001)
        { pc = 0x15f52; break; }
    if (memoryGet16(ds, 0x762f) == 0x0001)
        { pc = 0x15f51; break; }
    yield* sub_17a31();
  case 0x15f51:
    return;
  case 0x15f52:
    r16[bx] = memoryGet16(ds, 0x5b3c);
    if (r16[bx])
        { pc = 0x15f5b; break; }
    return;
  case 0x15f5b:
    r16[cx] = memoryGet16(ds, 0x8bf0);
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[cx] += 0x0025;
  case 0x15f68:
    r8[al] = memoryGet(ds, r16[bx]);
    if (r8[al])
        { pc = 0x15f6f; break; }
    return;
  case 0x15f6f:
    r8[ah] = r8[al];
    r16[bx]++;
    r8[al] = memoryGet(ds, r16[bx]);
    if (r8[al] < r8[cl])
        { pc = 0x15f79; break; }
    return;
  case 0x15f79:
    if (!(r8[ah] & 0x80))
        { pc = 0x15f90; break; }
    r16[bx]++;
  case 0x15f7f:
    r16[bx]++;
  case 0x15f80:
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r8[al] &= 0x03;
    if (!r8[al])
        { pc = 0x15f68; break; }
  case 0x15f87:
    r16[bx] += 0x0004;
    r8[al]--;
    if (r8[al])
        { pc = 0x15f87; break; }
    { pc = 0x15f68; break; }
  case 0x15f90:
    r16[bx]++;
    if (!(memoryGet(ds, r16[bx]) & 0x80))
        { pc = 0x15fd4; break; }
    r8[al] = memoryGet(ds, 0x5b3e);
    if (r8[al])
        { pc = 0x15fb9; break; }
    push(r16[cx]);
    r16[cx] = memoryGet16(ds, 0x8bf0);
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r8[ah] = r8[cl];
    r16[bx]--;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r8[al] -= r8[ah];
    r16[cx] = pop();
    if (r8[al] < 0x05)
        { pc = 0x15fb9; break; }
    if (r8[al] < 0x22)
        { pc = 0x15f7f; break; }
  case 0x15fb9:
    r16[bx]--;
    r16[bx]--;
    push(r16[bx]);
  case 0x15fbc:
    r16[si] = r16[bx];
    yield* sub_16205();
    r16[bx] = pop();
  case 0x15fc2:
    r16[bx]++;
    r16[bx]++;
    r16[bx]++;
    r16[cx] = memoryGet16(ds, 0x8bf0);
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[cx] += 0x0025;
    { pc = 0x15f80; break; }
  case 0x15fd4:
    r16[bx]--;
    r16[bx]--;
    push(r16[bx]);
    r16[si] = r16[bx];
    r16[dx] = 0;
    yield* sub_16222();
    r16[bx] = pop();
    if (!flags.carry)
        { pc = 0x15fc2; break; }
    push(r16[bx]);
    { pc = 0x15fbc; break; }
    return;
  }
}
function* sub_15fe4() // 1040:5be4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx] = memoryGet16(ds, 0x8bfc);
    memorySet16(ds, 0x5b3c, r16[bx]);
    if (r16[bx])
        { pc = 0x15ff1; break; }
    return;
  case 0x15ff1:
    r8[al] = memoryGet(ds, r16[bx]);
    if (r8[al])
        { pc = 0x15ff8; break; }
    return;
  case 0x15ff8:
    r16[bx]++;
    r16[cx] = memoryGet16(ds, 0x8bf0);
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    if (r8[cl] == memoryGet(ds, r16[bx]))
        { pc = 0x1601c; break; }
    if (r8[cl] < memoryGet(ds, r16[bx]))
        { pc = 0x1601c; break; }
    r16[bx] += 0x0002;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r8[al] &= 0x03;
    if (!r8[al])
        { pc = 0x15ff1; break; }
  case 0x16013:
    r16[bx] += 0x0004;
    r8[al]--;
    if (r8[al])
        { pc = 0x16013; break; }
    { pc = 0x15ff1; break; }
  case 0x1601c:
    r16[bx]--;
    memorySet16(ds, 0x5b3c, r16[bx]);
    return;
  }
}
function* sub_16022() // 1040:5c22
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_16126();
    if (!flags.carry)
        { pc = 0x16028; break; }
    return;
  case 0x16028:
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 50, r16[ax]);
    memorySet16(ds, r16[di] + 24, r16[ax]);
    memorySet16(ds, r16[di] + 34, r16[ax]);
    memorySet16(ds, r16[di] + 28, r16[si]);
    r16[cx] = 0;
    r8[cl] = memoryGet(ds, r16[si]);
    r16[cx] += r16[cx];
    r16[bx] = 0x117e;
    r16[bx] += r16[cx];
    r16[bx] = memoryGet16(ds, r16[bx]);
    r8[al] = memoryGet(ds, r16[bx]);
    cbw();
    memorySet16(ds, r16[di] + 30, r16[ax]);
    r16[bx]++;
    r8[al] = memoryGet(ds, r16[bx]);
    cbw();
    memorySet16(ds, r16[di] + 32, r16[ax]);
    r16[bx]++;
    r8[al] = memoryGet(ds, r16[bx]);
    r8[al] &= 0xc0;
    r8[dl] = r8[al];
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[si] + 3);
    r8[al] &= 0x3c;
    if (r8[al] != 0x10)
        { pc = 0x16072; break; }
    memorySet16(ds, r16[di] + 50, 0x0060);
    if (!(memoryGet(ds, r16[si] + 3) & 0x40))
        { pc = 0x16072; break; }
    memorySet16(ds, r16[di] + 28, 0x0000);
  case 0x16072:
    r8[al] |= 0x01;
    r8[al] |= r8[dl];
    memorySet(ds, r16[di], r8[al]);
    r8[al] &= 0x3f;
    r8[dl] = r8[al];
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r8[al] += r8[al];
    r8[al] += r8[al];
    r8[al] |= r8[dl];
    memorySet(ds, r16[di] + 44, r8[al]);
    r16[bx]++;
    r16[ax] = memoryGet16(ds, r16[bx]);
    r16[bx]++;
    r16[bx]++;
    memorySet16(ds, r16[di] + 36, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[bx]);
    r16[bx]++;
    r16[bx]++;
    memorySet16(ds, r16[di] + 22, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[bx]);
    r16[bx]++;
    r16[bx]++;
    memorySet16(ds, r16[di] + 40, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[bx]);
    memorySet16(ds, r16[di] + 42, r16[ax]);
    r8[al] = memoryGet(ds, r16[si] + 2);
    r16[ax] &= 0x001f;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    if (!(memoryGet(ds, r16[si] + 2) & 0x20))
        { pc = 0x160ba; break; }
    r16[ax]++;
    r16[ax]++;
    r16[ax]++;
    r16[ax]++;
  case 0x160ba:
    memorySet16(ds, r16[di] + 2, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x8bf0);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r8[dl] = r8[al];
    r8[al] = memoryGet(ds, r16[si] + 1);
    r8[al] -= r8[dl];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    if (!(memoryGet(ds, r16[si] + 2) & 0x40))
        { pc = 0x160dc; break; }
    r16[ax]++;
    r16[ax]++;
    r16[ax]++;
  case 0x160dc:
    memorySet16(ds, r16[di] + 4, r16[ax]);
    memorySet(ds, r16[si], memoryGet(ds, r16[si]) | 0x80);
    r8[al] = memoryGet(ds, r16[di]);
    r8[al] &= 0x3f;
    r8[ah] = 0x29;
    if (r8[al] != 0x21)
        { pc = 0x160f2; break; }
    memorySet(ds, r16[di] + 10, r8[ah]);
    { pc = 0x16125; break; }
    // gap 1 bytes
  case 0x160f2:
    r8[ah] = 0x27;
    if (r8[al] != 0x29)
        { pc = 0x160fe; break; }
    memorySet(ds, r16[di] + 10, r8[ah]);
    { pc = 0x16125; break; }
    // gap 1 bytes
  case 0x160fe:
    r8[ah] = 0x28;
    if (r8[al] != 0x2d)
        { pc = 0x1610a; break; }
    memorySet(ds, r16[di] + 10, r8[ah]);
    { pc = 0x16125; break; }
    // gap 1 bytes
  case 0x1610a:
    push(r16[si]);
    push(r16[di]);
    push(r16[bx]);
    r16[si] = r16[di];
    r16[ax] = memoryGet16(ds, r16[si] + 24);
    push(r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si] + 22);
    push(r16[ax]);
    yield* sub_1718e();
    r16[ax] = pop();
    memorySet16(ds, r16[si] + 22, r16[ax]);
    r16[ax] = pop();
    memorySet16(ds, r16[si] + 24, r16[ax]);
    r16[bx] = pop();
    r16[di] = pop();
    r16[si] = pop();
  case 0x16125:
    return;
  }
}
function* sub_16126() // 1040:5d26 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[di] = 0x0c28;
  case 0x16129:
    r16[ax] = memoryGet16(ds, r16[di]);
    if (r8s[ah] < 0)
        { pc = 0x16138; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x1613a; break; }
    r16[di] += 0x0034;
    { pc = 0x16129; break; }
  case 0x16138:
    flags.carry = 1;
    return;
  case 0x1613a:
    flags.carry = 0;
    return;
  }
}
function* sub_1613c() // 1040:5d3c +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[cx]);
    r16[cx] = memoryGet16(ds, r16[si] + 2);
    if (r16s[cx] < signed16(0x0000))
        { pc = 0x1615c; break; }
    if (r16s[cx] > signed16(0x00e8))
        { pc = 0x1615c; break; }
    r16[cx] = memoryGet16(ds, r16[si] + 4);
    if (r16s[cx] < signed16(0x0000))
        { pc = 0x1615c; break; }
    if (r16s[cx] >= signed16(0x0128))
        { pc = 0x1615c; break; }
    r16[cx] = pop();
    flags.carry = 0;
    return;
  case 0x1615c:
    r16[cx] = pop();
    flags.carry = 1;
    return;
  }
}
function* sub_1615f() // 1040:5d5f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (!(memoryGet16(ds, r16[si]) & 0x0001))
        { pc = 0x16173; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 28);
    if (!r16[bx])
        { pc = 0x1616f; break; }
    memorySet(ds, r16[bx], memoryGet(ds, r16[bx]) & 0x7f);
  case 0x1616f:
    memorySet16(ds, r16[si], 0x0000);
  case 0x16173:
    return;
  }
}
function* sub_16174() // 1040:5d74
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (!(memoryGet16(ds, r16[si]) & 0x0001))
        { pc = 0x1618e; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 28);
    if (!r16[bx])
        { pc = 0x1618a; break; }
    if (memoryGet(ds, r16[bx] + 3) & 0x40)
        { pc = 0x1618a; break; }
    memorySet(ds, r16[bx], memoryGet(ds, r16[bx]) & 0x7f);
  case 0x1618a:
    memorySet16(ds, r16[si], 0x0000);
  case 0x1618e:
    return;
  }
}
function* sub_1618f() // 1040:5d8f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[si]);
    r16[si] = 0x0b56;
  case 0x16193:
    if (memoryGet16(ds, r16[si]) == 0xffff)
        { pc = 0x161ad; break; }
    if (!(memoryGet16(ds, r16[si]) & 0x0001))
        { pc = 0x161a8; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 28);
    memorySet(ds, r16[bx], memoryGet(ds, r16[bx]) & 0x7f);
    memorySet16(ds, r16[si], 0x0000);
  case 0x161a8:
    r16[si] += 0x0034;
    { pc = 0x16193; break; }
  case 0x161ad:
    r16[si] = 0x0c28;
  case 0x161b0:
    if (memoryGet16(ds, r16[si]) == 0xffff)
        { pc = 0x161ca; break; }
    if (!(memoryGet16(ds, r16[si]) & 0x0001))
        { pc = 0x161c5; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 28);
    memorySet(ds, r16[bx], memoryGet(ds, r16[bx]) & 0x7f);
    memorySet16(ds, r16[si], 0x0000);
  case 0x161c5:
    r16[si] += 0x0034;
    { pc = 0x161b0; break; }
  case 0x161ca:
    r16[si] = pop();
    return;
  }
}
function* sub_16205() // 1040:5e05
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x16205; break; }
  case 0x161ce:
    memorySet(ds, r16[si], memoryGet(ds, r16[si]) | 0x80);
    memorySet16(ds, 0x5dcc, 0x0001);
    memorySet16(ds, 0x65e1, 0x0018);
    r16[si] = 0x661d;
    r16[di] = 0x6624;
    r16[cx] = 0x0006;
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
    r16[ax] = 0x0013;
    yield* sub_1aecd();
    return;
  case 0x161ef:
    memorySet(ds, r16[si], memoryGet(ds, r16[si]) | 0x80);
    memorySet16(ds, 0x5dcc, 0x0000);
    r16[si] = 0x6624;
    yield* sub_16bc7();
    r16[ax] = 0x0001;
    yield* sub_1aecd();
    return;
  case 0x16205:
    r8[ah] = 0;
    r8[al] = memoryGet(ds, r16[si]);
    if (r16[ax] == 0x0078)
        { pc = 0x161ce; break; }
    if (r16[ax] == 0x007c)
        { pc = 0x161ef; break; }
    if (r16s[ax] >= signed16(0x0075))
        { pc = 0x1621c; break; }
    yield* sub_16022();
    return;
  case 0x1621c:
    yield* sub_1691d();
    return;
  }
}
function* sub_16222() // 1040:5e22 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(memoryGet16(ds, 0x54f4));
    push(r16[dx]);
    memorySet16(ds, 0x54f4, pop());
    r16[dx] = pop();
    push(memoryGet16(ds, 0x54f6));
    push(r16[bx]);
    memorySet16(ds, 0x54f6, pop());
    r16[bx] = pop();
    r8[al] = memoryGet(ds, r16[si] + 3);
    r8[al] &= 0x03;
    if (r8[al])
        { pc = 0x1623e; break; }
    flags.carry = 0;
    return;
  case 0x1623e:
    r16[si] += 0x0004;
    push(memoryGet16(ds, 0x54f8));
    push(r16[ax]);
    memorySet16(ds, 0x54f8, pop());
    r16[ax] = pop();
    r8[al] = memoryGet(ds, r16[si] + 2);
    r8[cl] = r8[al];
    r8[al] >>= 1;
    r8[al] >>= 1;
    r8[al] >>= 1;
    r8[al] >>= 1;
    r8[al] &= 0x0f;
    r8[al]++;
    r8[ah] = r8[al];
    r16[dx] = memoryGet16(ds, 0x8bf0);
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r8[al] = memoryGet(ds, r16[si] + 1);
    r8[al] -= r8[dl];
    if (r8s[al] >= 0)
        { pc = 0x1627d; break; }
    r8[al] += r8[ah];
    if (r8s[al] >= 0)
        { pc = 0x16277; break; }
  case 0x16273:
    flags.carry = 0;
    { pc = 0x163f5; break; }
  case 0x16277:
    if (!r8[al])
        { pc = 0x16273; break; }
    r8[ah] = r8[al];
    r8[al] = 0;
  case 0x1627d:
    if (r8[al] >= 0x20)
        { pc = 0x16273; break; }
    r16[bx] = 0;
    r8[bl] = r8[al];
    r16[bx] += r16[bx];
    r16[bx] += r16[bx];
    r16[bx] += r16[bx];
    r8[ah] += r8[ah];
    r8[ah] += r8[ah];
    r8[ah] += r8[ah];
    r8[cl] &= 0x0f;
    r8[cl]++;
    r8[cl] += r8[cl];
    r8[cl] += r8[cl];
    r8[cl] += r8[cl];
    r8[dl] = r8[cl];
    r8[dh] = memoryGet(ds, r16[si]);
    push(r16[si]);
    r8[al] = memoryGet(ds, r16[si] + 3);
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    if (!flags.carry)
        { pc = 0x162cd; break; }
    push(r16[bx]);
    r8[cl] = r8[al];
    push(r16[cx]);
    r16[si] = 0x0b1c;
    yield* sub_16407();
    r16[cx] = pop();
    r8[al] = r8[cl];
    r16[bx] = pop();
    if (!flags.carry)
        { pc = 0x162cd; break; }
  case 0x162b8:
    r16[si] = pop();
    r8[al] = memoryGet(ds, r16[si] + 3);
    flags.carry = false;
    if (r8s[al] >= 0)
        { pc = 0x162c3; break; }
    { pc = 0x163f5; break; }
  case 0x162c3:
    r8[al] &= 0x40;
    if (r8[al])
        { pc = 0x162cb; break; }
    memorySet(ds, r16[si] + 3, memoryGet(ds, r16[si] + 3) | 0x80);
  case 0x162cb:
    flags.carry = 1;
    return;
  case 0x162cd:
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    if (!flags.carry)
        { pc = 0x162ec; break; }
    r8[cl] = r8[al];
    if (memoryGet16(ds, 0x0b00) != 0x0001)
        { pc = 0x162ea; break; }
    push(r16[cx]);
    push(r16[bx]);
    yield* sub_164a0();
    r16[bx] = pop();
    r16[cx] = pop();
    if (!flags.carry)
        { pc = 0x162ea; break; }
    memorySet(ds, 0x5e20, 0xff);
    { pc = 0x162b8; break; }
  case 0x162ea:
    r8[al] = r8[cl];
  case 0x162ec:
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    if (!flags.carry)
        { pc = 0x1630f; break; }
    r8[cl] = r8[al];
    if (memoryGet16(ds, 0x0b38) != 0x0002)
        { pc = 0x1630d; break; }
    r8[al] = memoryGet(ds, 0x0b4a);
    if (r8s[al] <= signed8(0x01))
        { pc = 0x1630d; break; }
    if (r8s[al] > signed8(0x04))
        { pc = 0x1630d; break; }
    push(r16[cx]);
    push(r16[bx]);
    yield* sub_164e1();
    r16[bx] = pop();
    r16[cx] = pop();
    if (flags.carry)
        { pc = 0x162b8; break; }
  case 0x1630d:
    r8[al] = r8[cl];
  case 0x1630f:
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    if (!flags.carry)
        { pc = 0x1632f; break; }
    r8[cl] = r8[al];
    if (memoryGet16(ds, 0x7ecc) != 0x0001)
        { pc = 0x1632d; break; }
    push(r16[cx]);
    push(r16[bx]);
    yield* sub_1646e();
    r16[bx] = pop();
    r16[cx] = pop();
    if (!flags.carry)
        { pc = 0x1632d; break; }
    r16[ax] = 0x0014;
    yield* sub_1aecd();
    { pc = 0x162b8; break; }
  case 0x1632d:
    r8[al] = r8[cl];
  case 0x1632f:
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    if (!flags.carry)
        { pc = 0x16389; break; }
    r8[cl] = r8[al];
    push(r16[si]);
    r16[si] = 0x0b56;
  case 0x16339:
    r16[bp] = memoryGet16(cs, r16[si]);
    if (r16[bp] == 0xffff)
        { pc = 0x1637d; break; }
    if (!(r16[bp] & 0x0001))
        { pc = 0x16378; break; }
    push(memoryGet16(ds, 0x54f4));
    push(r16[dx]);
    memorySet16(ds, 0x54f4, pop());
    r16[dx] = pop();
    push(memoryGet16(ds, 0x54f6));
    push(r16[bx]);
    memorySet16(ds, 0x54f6, pop());
    r16[bx] = pop();
    push(r16[cx]);
    push(r16[bx]);
    yield* sub_16519();
    r16[bx] = pop();
    r16[cx] = pop();
    push(memoryGet16(ds, 0x54f4));
    push(r16[dx]);
    memorySet16(ds, 0x54f4, pop());
    r16[dx] = pop();
    push(memoryGet16(ds, 0x54f6));
    push(r16[bx]);
    memorySet16(ds, 0x54f6, pop());
    r16[bx] = pop();
    if (flags.carry)
        { pc = 0x16382; break; }
  case 0x16378:
    r16[si] += 0x0034;
    { pc = 0x16339; break; }
  case 0x1637d:
    r16[si] = pop();
    flags.carry = 0;
    { pc = 0x16387; break; }
    // gap 1 bytes
  case 0x16382:
    r16[si] = pop();
    flags.carry = 1;
    { pc = 0x162b8; break; }
  case 0x16387:
    r8[al] = r8[cl];
  case 0x16389:
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    if (!flags.carry)
        { pc = 0x163f0; break; }
    push(memoryGet16(ds, 0x54f4));
    push(r16[dx]);
    memorySet16(ds, 0x54f4, pop());
    r16[dx] = pop();
    push(memoryGet16(ds, 0x54f6));
    push(r16[bx]);
    memorySet16(ds, 0x54f6, pop());
    r16[bx] = pop();
    r16[bx] = 0x0c28;
  case 0x163a4:
    r8[al] = memoryGet(ds, r16[bx] + 1);
    if (r8s[al] < 0)
        { pc = 0x163f0; break; }
    r8[al] = memoryGet(ds, r16[bx]);
    if (!r8[al])
        { pc = 0x163eb; break; }
    if (r16[bx] == r16[dx])
        { pc = 0x163eb; break; }
    r16[si] = r16[bx];
    push(memoryGet16(ds, 0x54f4));
    push(r16[dx]);
    memorySet16(ds, 0x54f4, pop());
    r16[dx] = pop();
    push(memoryGet16(ds, 0x54f6));
    push(r16[bx]);
    memorySet16(ds, 0x54f6, pop());
    r16[bx] = pop();
    push(r16[cx]);
    push(r16[bx]);
    yield* sub_16555();
    r16[bx] = pop();
    r16[cx] = pop();
    push(memoryGet16(ds, 0x54f4));
    push(r16[dx]);
    memorySet16(ds, 0x54f4, pop());
    r16[dx] = pop();
    push(memoryGet16(ds, 0x54f6));
    push(r16[bx]);
    memorySet16(ds, 0x54f6, pop());
    r16[bx] = pop();
    if (!flags.carry)
        { pc = 0x163eb; break; }
    { pc = 0x162b8; break; }
  case 0x163eb:
    r16[bx] += 0x0034;
    { pc = 0x163a4; break; }
  case 0x163f0:
    r16[si] = pop();
    flags.carry = false;
    memorySet(ds, r16[si] + 3, memoryGet(ds, r16[si] + 3) & 0x7f);
  case 0x163f5:
    push(memoryGet16(ds, 0x54f8));
    push(r16[ax]);
    memorySet16(ds, 0x54f8, pop());
    r16[ax] = pop();
    r8[al]--;
    if (!r8[al])
        { pc = 0x16406; break; }
    { pc = 0x1623e; break; }
  case 0x16406:
    return;
  }
}
function* sub_16407() // 1040:6007 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x7e16) != 0x0001)
        { pc = 0x16410; break; }
    flags.carry = 0;
    return;
  case 0x16410:
    r16[bp] = memoryGet16(ds, 0x0b1e);
    r16[bp] += 0x0014;
    r16[cx] = 0;
    r8[cl] = r8[dh];
    if (r16s[cx] >= r16s[bp])
        { pc = 0x1646c; break; }
    r16[bp] -= 0x0010;
    r8[al] = r8[dh];
    r8[dh] = 0;
    r16[cx] += r16[dx];
    r8[dh] = r8[al];
    if (r16s[cx] <= r16s[bp])
        { pc = 0x1646c; break; }
    r16[bp] = memoryGet16(ds, 0x0b20);
    r16[cx] = r16[bx];
    if (memoryGet16(ds, 0x7e04) == 0x0001)
        { pc = 0x16454; break; }
    r16[bp] += 0x0015;
    if (r16s[cx] >= r16s[bp])
        { pc = 0x1646c; break; }
    r16[bp] -= 0x0015;
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r8[ah] = 0;
    r16[cx] += r16[ax];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    if (r16s[cx] <= r16s[bp])
        { pc = 0x1646c; break; }
    { pc = 0x1646a; break; }
    // gap 1 bytes
  case 0x16454:
    r16[bp] += 0x0015;
    if (r16s[cx] >= r16s[bp])
        { pc = 0x1646c; break; }
    r16[bp] -= 0x0010;
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r8[ah] = 0;
    r16[cx] += r16[ax];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    if (r16s[cx] <= r16s[bp])
        { pc = 0x1646c; break; }
  case 0x1646a:
    flags.carry = 1;
    return;
  case 0x1646c:
    flags.carry = 0;
    return;
  }
}
function* sub_1646e() // 1040:606e +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bp] = memoryGet16(ds, 0x7ece);
    r16[cx] = 0;
    r8[cl] = r8[dh];
    if (r16s[cx] > r16s[bp])
        { pc = 0x1649e; break; }
    r8[al] = r8[dh];
    r8[dh] = 0;
    r16[cx] += r16[dx];
    r8[dh] = r8[al];
    if (r16s[cx] < r16s[bp])
        { pc = 0x1649e; break; }
    r16[bp] = memoryGet16(ds, 0x7ed0);
    r16[cx] = r16[bx];
    if (r16s[cx] > r16s[bp])
        { pc = 0x1649e; break; }
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r8[ah] = 0;
    r16[cx] += r16[ax];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    if (r16s[cx] < r16s[bp])
        { pc = 0x1649e; break; }
    flags.carry = 1;
    return;
  case 0x1649e:
    flags.carry = 0;
    return;
  }
}
function* sub_164a0() // 1040:60a0 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x0b00) != 0x0001)
        { pc = 0x164df; break; }
    r16[bp] = memoryGet16(cs, 0x0b02);
    r16[bp] += 0x0008;
    r16[cx] = 0;
    r8[cl] = r8[dh];
    if (r16s[cx] > r16s[bp])
        { pc = 0x164df; break; }
    r8[al] = r8[dh];
    r8[dh] = 0;
    r16[cx] += r16[dx];
    r8[dh] = r8[al];
    if (r16s[cx] < r16s[bp])
        { pc = 0x164df; break; }
    r16[bp] = memoryGet16(cs, 0x0b04);
    r16[bp] += 0x0004;
    r16[cx] = r16[bx];
    if (r16s[cx] > r16s[bp])
        { pc = 0x164df; break; }
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r8[ah] = 0;
    r16[cx] += r16[ax];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    if (r16s[cx] < r16s[bp])
        { pc = 0x164df; break; }
    flags.carry = 1;
    return;
  case 0x164df:
    flags.carry = 0;
    return;
  }
}
function* sub_164e1() // 1040:60e1 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bp] = memoryGet16(ds, 0x0b3a);
    r16[bp] += 0x000c;
    r16[cx] = 0;
    r8[cl] = r8[dh];
    if (r16s[cx] > r16s[bp])
        { pc = 0x16517; break; }
    r8[al] = r8[dh];
    r8[dh] = 0;
    r16[cx] += r16[dx];
    r8[dh] = r8[al];
    if (r16s[cx] < r16s[bp])
        { pc = 0x16517; break; }
    r16[bp] = memoryGet16(ds, 0x0b3c);
    r16[bp] += 0x000a;
    r16[cx] = r16[bx];
    if (r16s[cx] > r16s[bp])
        { pc = 0x16517; break; }
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r8[ah] = 0;
    r16[cx] += r16[ax];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    if (r16s[cx] < r16s[bp])
        { pc = 0x16517; break; }
    flags.carry = 1;
    return;
  case 0x16517:
    flags.carry = 0;
    return;
  }
}
function* sub_16519() // 1040:6119 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bp] = memoryGet16(ds, r16[si] + 2);
    r16[bp] += 0x0014;
    r16[cx] = 0;
    r8[cl] = r8[dh];
    if (r16s[cx] >= r16s[bp])
        { pc = 0x16553; break; }
    r16[bp] -= 0x0010;
    r8[al] = r8[dh];
    r8[dh] = 0;
    r16[cx] += r16[dx];
    r8[dh] = r8[al];
    if (r16s[cx] <= r16s[bp])
        { pc = 0x16553; break; }
    r16[bp] = memoryGet16(ds, r16[si] + 4);
    r16[cx] = r16[bx];
    r16[bp] += 0x0015;
    if (r16s[cx] >= r16s[bp])
        { pc = 0x16553; break; }
    r16[bp] -= 0x0015;
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r8[ah] = 0;
    r16[cx] += r16[ax];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    if (r16s[cx] <= r16s[bp])
        { pc = 0x16553; break; }
    flags.carry = 1;
    return;
  case 0x16553:
    flags.carry = 0;
    return;
  }
}
function* sub_16555() // 1040:6155 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bp] = memoryGet16(ds, r16[si] + 2);
    r16[bp] += memoryGet16(ds, r16[si] + 30);
    r16[cx] = 0;
    r8[cl] = r8[dh];
    if (r16s[cx] >= r16s[bp])
        { pc = 0x1658f; break; }
    r16[bp] -= memoryGet16(ds, r16[si] + 30);
    r8[al] = r8[dh];
    r8[dh] = 0;
    r16[cx] += r16[dx];
    r8[dh] = r8[al];
    if (r16s[cx] <= r16s[bp])
        { pc = 0x1658f; break; }
    r16[bp] = memoryGet16(ds, r16[si] + 4);
    r16[cx] = r16[bx];
    r16[bp] += memoryGet16(ds, r16[si] + 32);
    if (r16s[cx] >= r16s[bp])
        { pc = 0x1658f; break; }
    r16[bp] -= memoryGet16(ds, r16[si] + 32);
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r8[ah] = 0;
    r16[cx] += r16[ax];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    if (r16s[cx] <= r16s[bp])
        { pc = 0x1658f; break; }
    flags.carry = 1;
    return;
  case 0x1658f:
    flags.carry = 0;
    return;
  }
}
function* sub_16591() // 1040:6191
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x16591; break; }
  case 0x1615f:
    if (!(memoryGet16(ds, r16[si]) & 0x0001))
        { pc = 0x16173; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 28);
    if (!r16[bx])
        { pc = 0x1616f; break; }
    memorySet(ds, r16[bx], memoryGet(ds, r16[bx]) & 0x7f);
  case 0x1616f:
    memorySet16(ds, r16[si], 0x0000);
  case 0x16173:
    return;
  case 0x16174:
    if (!(memoryGet16(ds, r16[si]) & 0x0001))
        { pc = 0x1618e; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 28);
    if (!r16[bx])
        { pc = 0x1618a; break; }
    if (memoryGet(ds, r16[bx] + 3) & 0x40)
        { pc = 0x1618a; break; }
    memorySet(ds, r16[bx], memoryGet(ds, r16[bx]) & 0x7f);
  case 0x1618a:
    memorySet16(ds, r16[si], 0x0000);
  case 0x1618e:
    return;
    // gap 1026 bytes
  case 0x16591:
    r8[al] = memoryGet(ds, r16[si]);
    r8[al] &= 0x3f;
    r8[ah] = 0x29;
    if (r8[al] != 0x21)
        { pc = 0x1659e; break; }
    { pc = 0x167d9; break; }
  case 0x1659e:
    r8[ah] = 0x27;
    if (r8[al] != 0x29)
        { pc = 0x165a7; break; }
    { pc = 0x167d9; break; }
  case 0x165a7:
    r8[ah] = 0x28;
    if (r8[al] != 0x2d)
        { pc = 0x165b0; break; }
    { pc = 0x167d9; break; }
  case 0x165b0:
    if (!(r8[al] & 0x02))
        { pc = 0x165b7; break; }
    { pc = 0x16748; break; }
  case 0x165b7:
    r16[bx] = memoryGet16(ds, r16[si] + 36);
  case 0x165ba:
    r8[al] = memoryGet(ds, r16[bx]);
    if (!r8[al])
        { pc = 0x165cf; break; }
    if (r8[al] != 0xff)
        { pc = 0x16604; break; }
    r16[ax] = memoryGet16(ds, r16[bx] + 1);
    yield* sub_1aecd();
    r16[bx] += 0x0003;
    { pc = 0x165ba; break; }
  case 0x165cf:
    r16[bx]++;
    r16[bx] = memoryGet16(ds, r16[bx]);
    memorySet16(ds, r16[si] + 36, r16[bx]);
    r8[al] = memoryGet(ds, r16[si] + 50);
    if (!(r8[al] & 0x20))
        { pc = 0x165df; break; }
    { pc = 0x16174; break; }
  case 0x165df:
    if (!(r8[al] & 0x10))
        { pc = 0x165ba; break; }
    if (!(r8[al] & 0x08))
        { pc = 0x165ee; break; }
    memorySet(ds, r16[si] + 50, memoryGet(ds, r16[si] + 50) & 0xf7);
    { pc = 0x165f2; break; }
    // gap 1 bytes
  case 0x165ee:
    memorySet(ds, r16[si] + 50, memoryGet(ds, r16[si] + 50) & 0xef);
  case 0x165f2:
    r8[al] = memoryGet(ds, r16[si]);
    r8[al] &= 0x1c;
    if (r8[al] == 0x14)
        { pc = 0x165fd; break; }
    { pc = 0x1679d; break; }
  case 0x165fd:
    memorySet(ds, r16[si] + 50, memoryGet(ds, r16[si] + 50) | 0x20);
    { pc = 0x1679d; break; }
  case 0x16604:
    r16[bx]++;
    r8[al] = memoryGet(ds, r16[bx]);
    r8[al] = sar8(r8[al], 0x01);
    r8[al] = sar8(r8[al], 0x01);
    r8[al] = sar8(r8[al], 0x01);
    r8[al] = sar8(r8[al], 0x01);
    if (r8[al] != 0x07)
        { pc = 0x16615; break; }
    r8[al]++;
  case 0x16615:
    cbw();
    memorySet16(ds, r16[si] + 46, r16[ax]);
    if (r16s[ax] >= 0)
        { pc = 0x16625; break; }
    flags.carry = r16[ax] + memoryGet16(ds, r16[si] + 2) >= 0x10000;
    r16[ax] += memoryGet16(ds, r16[si] + 2);
    if (flags.carry)
        { pc = 0x1662a; break; }
    { pc = 0x1662a; break; }
    // gap 1 bytes
  case 0x16625:
    flags.carry = r16[ax] + memoryGet16(ds, r16[si] + 2) >= 0x10000;
    r16[ax] += memoryGet16(ds, r16[si] + 2);
    if (!flags.carry)
        { pc = 0x1662a; break; }
  case 0x1662a:
    memorySet16(ds, r16[si] + 2, r16[ax]);
    r8[dh] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r8[al] &= 0x0f;
    if (!(r8[al] & 0x08))
        { pc = 0x1663b; break; }
    r8[dh]--;
    r8[al] |= 0xf0;
  case 0x1663b:
    if (r8[al] != 0x07)
        { pc = 0x16641; break; }
    r8[al]++;
  case 0x16641:
    r8[dl] = r8[al];
    cbw();
    memorySet16(ds, r16[si] + 48, r16[ax]);
    r16[cx] = r16[bx];
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r16[bx] += r16[dx];
    memorySet16(ds, r16[si] + 4, r16[bx]);
    yield* sub_1613c();
    if (!flags.carry)
        { pc = 0x16659; break; }
    { pc = 0x1615f; break; }
  case 0x16659:
    r16[bx] = r16[cx];
    r16[bx]--;
    r8[al] = memoryGet(ds, r16[bx]);
    cbw();
    memorySet16(ds, r16[si] + 34, memoryGet16(ds, r16[si] + 34) + 1);
    if (r16[ax] == memoryGet16(ds, r16[si] + 34))
        { pc = 0x16669; break; }
    if (r16[ax] >= memoryGet16(ds, r16[si] + 34))
        { pc = 0x16673; break; }
  case 0x16669:
    memorySet16(ds, r16[si] + 34, 0x0000);
    r16[bx]++;
    r16[bx]++;
    memorySet16(ds, r16[si] + 36, r16[bx]);
  case 0x16673:
    yield* sub_1718e();
    if (!(memoryGet16(ds, r16[si]) & 0x0080))
        { pc = 0x166bd; break; }
    if (memoryGet16(ds, r16[si]) & 0x0040)
        { pc = 0x16685; break; }
    { pc = 0x16748; break; }
  case 0x16685:
    if (memoryGet16(ds, 0x0b38) != 0x0001)
        { pc = 0x166bd; break; }
    r16[bx] = memoryGet16(ds, 0x0b3c);
    r8[dh] = memoryGet(ds, 0x0b3a);
    r8[dh] += 0x08;
    r8[dl] = 0x08;
    r8[ah] = 0x10;
    yield* sub_16555();
    if (!flags.carry)
        { pc = 0x166bd; break; }
    memorySet16(ds, 0x0b38, 0x0002);
    memorySet16(ds, 0x0b50, 0x0000);
    memorySet16(ds, 0x0b4e, 0x7eb2);
    memorySet16(ds, 0x0b3c, memoryGet16(ds, 0x0b3c) - 0x0005);
    memorySet16(ds, 0x0b4a, 0x0000);
  case 0x166bd:
    if (memoryGet16(ds, r16[si]) & 0x0040)
        { pc = 0x166c6; break; }
    { pc = 0x16748; break; }
  case 0x166c6:
    if (memoryGet16(ds, r16[si] + 10) == 0x00fe)
        { pc = 0x16748; break; }
    r16[di] = 0x0b56;
  case 0x166d3:
    r16[ax] = memoryGet16(ds, r16[di]);
    if (r16[ax] == 0xffff)
        { pc = 0x16717; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x16712; break; }
    if (memoryGet16(ds, r16[di] + 22) == 0x0001)
        { pc = 0x16712; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r8[dh] = memoryGet(ds, r16[si] + 2);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[ah] = memoryGet(ds, r16[si] + 32);
    push(r16[si]);
    push(r16[di]);
    r16[si] = r16[di];
    yield* sub_16519();
    if (!flags.carry)
        { pc = 0x16710; break; }
    push(r16[si]);
    r16[si] = 0x6711;
    yield* sub_16bc7();
    r16[si] = pop();
    yield* sub_17674();
  case 0x16710:
    r16[di] = pop();
    r16[si] = pop();
  case 0x16712:
    r16[di] += 0x0034;
    { pc = 0x166d3; break; }
  case 0x16717:
    if (memoryGet16(ds, 0x7e16) == 0x0001)
        { pc = 0x16748; break; }
    if (!(memoryGet(ds, r16[si]) & 0x40))
        { pc = 0x16748; break; }
    r16[ax] = memoryGet16(ds, r16[si] + 10);
    if (r16[ax] == 0x00fe)
        { pc = 0x16748; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r8[dh] = memoryGet(ds, r16[si] + 2);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[ah] = memoryGet(ds, r16[si] + 32);
    yield* sub_16407();
    if (!flags.carry)
        { pc = 0x16748; break; }
    { pc = 0x168a8; break; }
  case 0x16748:
    r8[al] = memoryGet(ds, r16[si] + 50);
    if (!(r8[al] & 0x40))
        { pc = 0x16750; break; }
    return;
  case 0x16750:
    if (!(memoryGet(ds, r16[si] + 50) & 0x10))
        { pc = 0x1675c; break; }
    if (!(memoryGet(ds, r16[si]) & 0x20))
        { pc = 0x1675c; break; }
    return;
  case 0x1675c:
    push(r16[si]);
    r16[dx] = r16[si];
    r16[si] = memoryGet16(ds, r16[si] + 28);
    yield* sub_16222();
    r16[si] = pop();
    if (flags.carry)
        { pc = 0x16774; break; }
    r8[al] = memoryGet(ds, r16[si]);
    r8[al] &= 0x1c;
    if (r8[al] == 0x1c)
        { pc = 0x16771; break; }
    return;
  case 0x16771:
    { pc = 0x16174; break; }
  case 0x16774:
    r8[al] = memoryGet(ds, r16[si]);
    r8[al] &= 0x1c;
    if (r8[al])
        { pc = 0x16781; break; }
    r8[al] = memoryGet(ds, r16[si]);
    r8[al] ^= 0x02;
    memorySet(ds, r16[si], r8[al]);
    return;
  case 0x16781:
    if (r8[al] != 0x1c)
        { pc = 0x16786; break; }
    return;
  case 0x16786:
    if (r8[al] != 0x0c)
        { pc = 0x1678d; break; }
    { pc = 0x16174; break; }
  case 0x1678d:
    if (!(r8[al] & 0x08))
        { pc = 0x167ca; break; }
    memorySet(ds, r16[si] + 50, memoryGet(ds, r16[si] + 50) | 0x40);
    if (!(r8[al] & 0x10))
        { pc = 0x1679d; break; }
    memorySet(ds, r16[si] + 50, memoryGet(ds, r16[si] + 50) | 0x20);
  case 0x1679d:
    r16[bx] = memoryGet16(ds, r16[si] + 40);
    r16[cx] = memoryGet16(ds, r16[si] + 36);
    memorySet16(ds, r16[si] + 40, r16[cx]);
    memorySet16(ds, r16[si] + 36, r16[bx]);
    r16[bx] = memoryGet16(ds, r16[si] + 22);
    r16[cx] = memoryGet16(ds, r16[si] + 42);
    memorySet16(ds, r16[si] + 22, r16[cx]);
    memorySet16(ds, r16[si] + 42, r16[bx]);
    memorySet16(ds, r16[si] + 24, 0x0000);
    memorySet16(ds, r16[si] + 18, 0x0000);
    r8[al] = memoryGet(ds, r16[si]);
    r8[ah] = memoryGet(ds, r16[si] + 44);
    memorySet(ds, r16[si], r8[ah]);
    memorySet(ds, r16[si] + 44, r8[al]);
    return;
  case 0x167ca:
    memorySet(ds, r16[si] + 50, memoryGet(ds, r16[si] + 50) | 0x10);
    if (memoryGet(ds, r16[si]) & 0x20)
        { pc = 0x167d4; break; }
    return;
  case 0x167d4:
    memorySet(ds, r16[si] + 50, memoryGet(ds, r16[si] + 50) | 0x08);
    return;
  case 0x167d9:
    memorySet(ds, r16[si], r8[al]);
    memorySet(ds, r16[si] + 10, r8[ah]);
    memorySet(ds, r16[si] + 11, 0x00);
    memorySet16(ds, r16[si] + 30, 0x0018);
    memorySet16(ds, r16[si] + 32, 0x0015);
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r8[dh] = memoryGet(ds, r16[si] + 2);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[ah] = memoryGet(ds, r16[si] + 32);
    yield* sub_16407();
    if (!flags.carry)
        { pc = 0x16803; break; }
    yield* sub_1686f();
    yield* sub_16174();
  case 0x16803:
    if (memoryGet16(ds, 0x0b38) != 0x0002)
        { pc = 0x1683f; break; }
    r8[al] = memoryGet(ds, 0x0b4a);
    if (r8s[al] <= signed8(0x01))
        { pc = 0x1683f; break; }
    if (r8s[al] > signed8(0x04))
        { pc = 0x1683f; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r8[dh] = memoryGet(ds, r16[si] + 2);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[ah] = memoryGet(ds, r16[si] + 32);
    if (r8[dh] >= 0x0f)
        { pc = 0x1682b; break; }
    r8[dh] = 0;
    { pc = 0x1682e; break; }
    // gap 1 bytes
  case 0x1682b:
    r8[dh] -= 0x10;
  case 0x1682e:
    r16[bx] -= 0x000e;
    r8[dl] += 0x20;
    r8[ah] += 0x1d;
    yield* sub_164e1();
    if (!flags.carry)
        { pc = 0x1683f; break; }
    yield* sub_16174();
  case 0x1683f:
    if (memoryGet16(ds, 0x0b00) != 0x0001)
        { pc = 0x16866; break; }
    r8[al] = memoryGet(ds, r16[si]);
    if (r8[al] == 0x21)
        { pc = 0x16866; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r8[dh] = memoryGet(ds, r16[si] + 2);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[ah] = memoryGet(ds, r16[si] + 32);
    yield* sub_164a0();
    if (!flags.carry)
        { pc = 0x16866; break; }
    yield* sub_16174();
    memorySet16(ds, 0x0b00, 0x0000);
  case 0x16866:
    yield* sub_1613c();
    if (!flags.carry)
        { pc = 0x1686e; break; }
    yield* sub_1615f();
  case 0x1686e:
    return;
    // gap 57 bytes
  case 0x168a8:
    r16[ax] = 0x000b;
    yield* sub_1aecd();
    memorySet16(ds, 0x7e16, 0x0001);
    memorySet16(ds, 0x0b24, 0xfb00);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    if (r16s[ax] < signed16(0x0080))
        { pc = 0x168cb; break; }
    memorySet16(ds, 0x7e1c, 0xfffe);
    { pc = 0x168d1; break; }
    // gap 1 bytes
  case 0x168cb:
    memorySet16(ds, 0x7e1c, 0x0002);
  case 0x168d1:
    r16[ax] = memoryGet16(ds, 0x6614);
    if (!r16[ax])
        { pc = 0x168e3; break; }
    if (memoryGet(ds, 0x9804) == 0x01)
        { pc = 0x168e3; break; }
    memorySet16(ds, 0x6614, memoryGet16(ds, 0x6614) - 1);
  case 0x168e3:
    return;
  }
}
function* sub_1686f() // 1040:646f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[al] = memoryGet(ds, r16[si]);
    if (r8[al] != 0x21)
        { pc = 0x16884; break; }
    push(r16[si]);
    r16[si] = 0x6717;
    yield* sub_16bc7();
    r16[si] = pop();
    r16[ax] = 0x0012;
    yield* sub_1aecd();
    return;
  case 0x16884:
    if (r8[al] == 0x29)
        { pc = 0x16898; break; }
    memorySet16(ds, 0x6612, 0x0006);
    yield* sub_16c3d();
    r16[ax] = 0x0011;
    yield* sub_1aecd();
    return;
  case 0x16898:
    memorySet16(ds, 0x6610, 0x0006);
    yield* sub_16c27();
    r16[ax] = 0x0011;
    yield* sub_1aecd();
    return;
  }
}
function* sub_168a8() // 1040:64a8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x000b;
    yield* sub_1aecd();
    memorySet16(ds, 0x7e16, 0x0001);
    memorySet16(ds, 0x0b24, 0xfb00);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    if (r16s[ax] < signed16(0x0080))
        { pc = 0x168cb; break; }
    memorySet16(ds, 0x7e1c, 0xfffe);
    { pc = 0x168d1; break; }
    // gap 1 bytes
  case 0x168cb:
    memorySet16(ds, 0x7e1c, 0x0002);
  case 0x168d1:
    r16[ax] = memoryGet16(ds, 0x6614);
    if (!r16[ax])
        { pc = 0x168e3; break; }
    if (memoryGet(ds, 0x9804) == 0x01)
        { pc = 0x168e3; break; }
    memorySet16(ds, 0x6614, memoryGet16(ds, 0x6614) - 1);
  case 0x168e3:
    return;
  }
}
function* sub_168e4() // 1040:64e4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x762d) != 0x0001)
        { pc = 0x168ef; break; }
    yield* sub_17a8b();
    return;
  case 0x168ef:
    r16[si] = 0x0c28;
  case 0x168f2:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16s[ax] < 0)
        { pc = 0x16906; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x16901; break; }
    push(r16[si]);
    yield* sub_16591();
    r16[si] = pop();
  case 0x16901:
    r16[si] += 0x0034;
    { pc = 0x168f2; break; }
  case 0x16906:
    return;
  }
}
function* sub_16907() // 1040:6507 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[di] = 0x0b56;
  case 0x1690a:
    r16[ax] = memoryGet16(ds, r16[di]);
    if (r8s[ah] < 0)
        { pc = 0x16919; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x1691b; break; }
    r16[di] += 0x0034;
    { pc = 0x1690a; break; }
  case 0x16919:
    flags.carry = 1;
    return;
  case 0x1691b:
    flags.carry = 0;
    return;
  }
}
function* sub_1691d() // 1040:651d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_16907();
    if (!flags.carry)
        { pc = 0x16923; break; }
    return;
  case 0x16923:
    memorySet16(ds, r16[di] + 22, 0x0000);
    memorySet16(ds, r16[di] + 24, 0x0000);
    memorySet(ds, r16[si], memoryGet(ds, r16[si]) | 0x80);
    r8[al] = memoryGet(ds, r16[si]);
    r8[al] &= 0x03;
    memorySet(ds, r16[di] + 49, 0x00);
    memorySet(ds, r16[di] + 48, r8[al]);
    memorySet16(ds, r16[di] + 28, r16[si]);
    memorySet16(ds, r16[di], memoryGet16(ds, r16[di]) | 0x0001);
    r8[al] = memoryGet(ds, r16[si]);
    if (!(r8[al] & 0x04))
        { pc = 0x16954; break; }
    memorySet16(ds, r16[di] + 10, 0x002a);
    memorySet16(ds, r16[di] + 50, 0x002a);
    { pc = 0x1695e; break; }
    // gap 1 bytes
  case 0x16954:
    memorySet16(ds, r16[di] + 10, 0x0034);
    memorySet16(ds, r16[di] + 50, 0x0034);
  case 0x1695e:
    r8[al] = memoryGet(ds, r16[si] + 2);
    r16[ax] &= 0x001f;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    memorySet16(ds, r16[di] + 2, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x8bf0);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r8[dl] = r8[al];
    r8[al] = memoryGet(ds, r16[si] + 1);
    r8[al] -= r8[dl];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    if (!(memoryGet(ds, r16[si] + 2) & 0x40))
        { pc = 0x1698c; break; }
    r16[ax]++;
    r16[ax]++;
    r16[ax]++;
  case 0x1698c:
    memorySet16(ds, r16[di] + 4, r16[ax]);
    memorySet16(ds, r16[di] + 30, 0x0010);
    memorySet16(ds, r16[di] + 32, 0x0015);
    r16[ax] = memoryGet16(ds, r16[di] + 48);
    if (r16[ax] != 0x0001)
        { pc = 0x169b3; break; }
    r8[al] = memoryGet(ds, r16[si] + 3);
    r8[al] &= 0x3c;
    r16[ax] <<= 1;
    r16[ax] += 0x0008;
    memorySet16(ds, r16[di] + 18, r16[ax]);
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 20, r16[ax]);
  case 0x169b3:
    memorySet16(ds, r16[di] + 8, 0x0100);
    memorySet(ds, r16[di] + 6, 0x00);
    memorySet16(ds, r16[di] + 16, 0x0000);
    r16[ax] = 0x0000;
    memorySet16(ds, r16[di] + 34, r16[ax]);
    memorySet16(ds, r16[di] + 36, r16[ax]);
    memorySet16(ds, r16[di] + 38, r16[ax]);
    memorySet16(ds, r16[di] + 40, r16[ax]);
    memorySet16(ds, r16[di] + 42, r16[ax]);
    memorySet16(ds, r16[di] + 44, r16[ax]);
    memorySet16(ds, r16[di] + 26, 0x0000);
    memorySet16(ds, r16[di] + 16, 0x0002);
    return;
  }
}
function* sub_169e3() // 1040:65e3
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (!memoryGet16(ds, 0x5dcc))
        { pc = 0x16a0e; break; }
    r16[ax] = memoryGet16(ds, 0x65e1);
    r16[ax]++;
    if (r16[ax] != 0x0019)
        { pc = 0x16a0b; break; }
    r16[si] = 0x6624;
    r16[cx] = 0x0006;
    r8[al] = 0x00;
  case 0x169fb:
    if (r8[al] != memoryGet(ds, r16[si]))
        { pc = 0x16a03; break; }
    r16[si]++;
    if (--r16[cx])
        { pc = 0x169fb; break; }
    return;
  case 0x16a03:
    r16[si] = 0x662b;
    yield* sub_16bf7();
    r16[ax] = 0;
  case 0x16a0b:
    memorySet16(ds, 0x65e1, r16[ax]);
  case 0x16a0e:
    return;
  }
}
function* sub_16b3b() // 1040:673b
{
    push(ds);
    push(es);
    push(r16[bx]);
    yield* sub_16c53();
    yield* sub_16c27();
    yield* sub_16c3d();
    r16[ax] = 0x0004;
    r16[si] = 0x6616;
    yield* sub_107f1();
    r16[ax] = 0x000d;
    r16[si] = 0x66f6;
    yield* sub_107f1();
    r16[ax] = 0x0015;
    r16[si] = 0x66fd;
    yield* sub_107f1();
    r16[ax] = 0x001e;
    r16[si] = 0x6704;
    yield* sub_107f1();
    r16[ax] = 0x0004;
    r16[si] = 0x6616;
    yield* sub_10836();
    r16[ax] = 0x000d;
    r16[si] = 0x66f6;
    yield* sub_10836();
    r16[ax] = 0x0015;
    r16[si] = 0x66fd;
    yield* sub_10836();
    r16[ax] = 0x001e;
    r16[si] = 0x6704;
    yield* sub_10836();
    r16[bx] = pop();
    es = pop();
    ds = pop();
}
function* sub_16b9b() // 1040:679b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    yield* sub_10d03();
    yield* sub_10df8();
    memorySet(ds, 0x97da, 0x01);
    r16[cx] = 0x01e0;
  case 0x16bac:
    push(r16[cx]);
    yield* sub_19b1c();
    yield* sub_19bdc();
    if (r8[al] & 0x10)
        { pc = 0x16bc4; break; }
    r8[al] = memoryGet(ds, 0xb888);
    r8[al] &= 0x30;
    if (r8[al] == 0x30)
        { pc = 0x16bc4; break; }
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x16bac; break; }
    sp += 2;
    return;
  case 0x16bc4:
    { pc = 0x1c3b0; break; }
    // gap 22505 bytes
  case 0x1c3b0:
    memorySet16(ds, 0x6614, 0x0006);
    yield* sub_199c8();
    sp = memoryGet16(ds, 0xc0df);
    memorySet16(ds, 0x6610, 0x0006);
    memorySet16(ds, 0x6612, 0x0006);
    memorySet16(ds, 0x7e00, 0x0000);
    memorySet16(ds, 0x762d, 0x0000);
    memorySet16(ds, 0x762f, 0x0000);
    yield* sub_1a54a();
    push(cs);
    ds = pop();
    yield* sub_1a56b();
    yield* sub_10594();
    yield* sub_105a1();
    yield* sub_1a45c();
    yield* sub_1c4e2();
    yield* sub_112d6();
    yield* sub_10d03();
    yield* sub_10ee5();
    yield* sub_10ee7();
    r16[ax] = 0x0004;
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[ax] = memoryGet16(ds, 0x8bec);
    r16[ax]--;
    r16[ax] += r16[ax];
    r16[si] = 0x2f69;
    r16[si] += r16[ax];
    r16[ax] = memoryGet16(ds, r16[si]);
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[ax] = 0x0000;
    yield* sub_1a257();
    yield* sub_1a5f0();
    yield* sub_10d03();
    yield* sub_19420();
    memorySet16(ds, 0x973c, 0x3245);
    memorySet16(ds, 0x973e, 0x5432);
  case 0x1c439:
    memorySet16(ds, 0x7e16, 0x0000);
    memorySet16(ds, 0x7e18, 0x0000);
  case 0x1c445:
    yield* sub_16b3b();
    if (memoryGet16(ds, 0x7e18) != 0x0001)
        { pc = 0x1c467; break; }
    memorySet16(ds, 0x762f, 0x0000);
    yield* sub_1618f();
    yield* sub_19462();
    if (memoryGet16(ds, 0x6614))
        { pc = 0x1c465; break; }
    yield* sub_19f12();
    return;
  case 0x1c465:
    { pc = 0x1c439; break; }
  case 0x1c467:
    yield* sub_19bac();
    yield* sub_15f40();
    memorySet(ds, 0x5b3e, 0x00);
    yield* sub_169e3();
    yield* sub_168e4();
    yield* sub_17205();
    yield* sub_18351();
    yield* sub_18cbe();
    yield* sub_18d28();
    yield* sub_1705d();
    yield* sub_10a67();
    yield* sub_1091b();
    yield* sub_11162();
    yield* sub_109ee();
    yield* sub_19af6();
    yield* sub_10ee4();
    yield* sub_194c4();
    if (memoryGet(ds, 0xb888) != 0x10)
        { pc = 0x1c4b3; break; }
    yield* sub_19f8a();
    if (!flags.carry)
        { pc = 0x1c4b3; break; }
    yield* sub_1c359();
    return;
  case 0x1c4b3:
    if (memoryGet(ds, 0xb888) != 0x01)
        { pc = 0x1c445; break; }
    yield* sub_196f3();
    return;
  }
}
function* sub_16bc7() // 1040:67c7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] += 0x0005;
    r16[di] = 0x661b;
    r8[bl] = 0x00;
    r16[cx] = 0x0006;
  case 0x16bd2:
    r8[al] = memoryGet(ds, r16[si]);
    r8[ah] = memoryGet(ds, r16[di]);
    r8[ah] += r8[al];
    r8[ah] += r8[bl];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r8[ah] = 0;
    if (r16s[ax] < signed16(0x000a))
        { pc = 0x16bee; break; }
    r8[bl] = 0x01;
    r8[al] -= 0x0a;
    memorySet(ds, r16[di], r8[al]);
    r16[di]--;
    r16[si]--;
    if (--r16[cx])
        { pc = 0x16bd2; break; }
    return;
  case 0x16bee:
    r8[bl] = 0x00;
    memorySet(ds, r16[di], r8[al]);
    r16[di]--;
    r16[si]--;
    if (--r16[cx])
        { pc = 0x16bd2; break; }
    return;
  }
}
function* sub_16bf7() // 1040:67f7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] += 0x0005;
    r16[di] = 0x6629;
    r8[bl] = 0x00;
    r16[cx] = 0x0006;
  case 0x16c02:
    r8[al] = memoryGet(ds, r16[si]);
    r8[ah] = memoryGet(ds, r16[di]);
    r8[ah] += r8[al];
    r8[ah] += r8[bl];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r8[ah] = 0;
    if (r16s[ax] < signed16(0x000a))
        { pc = 0x16c1e; break; }
    r8[bl] = 0x01;
    r8[al] -= 0x0a;
    memorySet(ds, r16[di], r8[al]);
    r16[di]--;
    r16[si]--;
    if (--r16[cx])
        { pc = 0x16c02; break; }
    return;
  case 0x16c1e:
    r8[bl] = 0x00;
    memorySet(ds, r16[di], r8[al]);
    r16[di]--;
    r16[si]--;
    if (--r16[cx])
        { pc = 0x16c02; break; }
    return;
  }
}
function* sub_16c27() // 1040:6827
{
    r16[di] = 0x66f6;
    r16[cx] = 0x0006;
    r8[al] = 0x20;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
    r16[cx] = memoryGet16(ds, 0x6610);
    r16[di] = 0x66f6;
    r8[al] = 0x0a;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
}
function* sub_16c3d() // 1040:683d
{
    r16[di] = 0x66fd;
    r16[cx] = 0x0006;
    r8[al] = 0x20;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
    r16[cx] = memoryGet16(ds, 0x6612);
    r16[di] = 0x66fd;
    r8[al] = 0x0b;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
}
function* sub_16c53() // 1040:6853
{
    r16[di] = 0x6704;
    r16[cx] = 0x0006;
    r8[al] = 0x20;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
    r16[cx] = memoryGet16(ds, 0x6614);
    r16[di] = 0x6704;
    r8[al] = 0x0c;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
}
function* sub_16c69() // 1040:6869 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[cx] = 0x0008;
    r16[di] = 0x6632;
    r16[bx] = 0x668d;
  case 0x16c72:
    r16[si] = 0x6616;
    yield* sub_16cb8();
    if (flags.carry)
        { pc = 0x16c84; break; }
    r16[bx] += 0x000b;
    r16[di] += 0x0007;
    if (--r16[cx])
        { pc = 0x16c72; break; }
    flags.carry = 0;
    return;
  case 0x16c84:
    r16[si] = 0x6663;
  case 0x16c87:
    if (r16[si] == r16[di])
        { pc = 0x16c94; break; }
    r8[al] = memoryGet(ds, r16[si] - 1);
    memorySet(ds, r16[si] + 6, r8[al]);
    r16[si]--;
    { pc = 0x16c87; break; }
  case 0x16c94:
    r16[cx] = 0x0007;
    r16[si] = 0x6616;
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
    flags.carry = 1;
    return;
  }
}
function* sub_16cb8() // 1040:68b8 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[cx]);
    push(r16[di]);
    r16[cx] = 0x0006;
  case 0x16cbd:
    r8[al] = memoryGet(ds, r16[si]);
    r16[si]++;
    r8[ah] = memoryGet(ds, r16[di]);
    r16[di]++;
    if (r8s[al] < r8s[ah])
        { pc = 0x16ccf; break; }
    if (r8s[al] > r8s[ah])
        { pc = 0x16cd3; break; }
    if (--r16[cx])
        { pc = 0x16cbd; break; }
    r16[di] = pop();
    r16[cx] = pop();
    flags.carry = 1;
    return;
  case 0x16ccf:
    r16[di] = pop();
    r16[cx] = pop();
    flags.carry = 0;
    return;
  case 0x16cd3:
    r16[di] = pop();
    r16[cx] = pop();
    flags.carry = 1;
    return;
  }
}
function* sub_16cd7() // 1040:68d7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    yield* sub_10d03();
    r16[ax] = 0x0008;
    r16[si] = 0x9401;
    yield* sub_107ac();
    r16[ax] = 0x0108;
    r16[si] = 0x9421;
    yield* sub_107ac();
    r16[ax] = 0x0208;
    r16[si] = 0x9441;
    yield* sub_107ac();
    r16[si] = 0x668d;
    r16[ax] = 0x0617;
    r16[cx] = 0x0008;
  case 0x16d02:
    push(r16[si]);
    push(r16[ax]);
    push(r16[cx]);
    yield* sub_107f1();
    r16[cx] = pop();
    r16[ax] = pop();
    r16[si] = pop();
    r16[si] += 0x000b;
    r8[ah]++;
    r8[ah]++;
    if (--r16[cx])
        { pc = 0x16d02; break; }
    r16[si] = 0x6632;
    r16[ax] = 0x0607;
    r16[cx] = 0x0008;
  case 0x16d1e:
    push(r16[si]);
    push(r16[ax]);
    push(r16[cx]);
    yield* sub_107f1();
    r16[cx] = pop();
    r16[ax] = pop();
    r16[si] = pop();
    r16[si] += 0x0007;
    r8[ah]++;
    r8[ah]++;
    if (--r16[cx])
        { pc = 0x16d1e; break; }
    r16[si] = 0x6682;
    r16[ax] = 0x060d;
    r16[cx] = 0x0008;
  case 0x16d3a:
    push(r16[si]);
    push(r16[ax]);
    push(r16[cx]);
    yield* sub_107f1();
    r16[cx] = pop();
    r16[ax] = pop();
    r16[si] = pop();
    r8[ah]++;
    r8[ah]++;
    if (--r16[cx])
        { pc = 0x16d3a; break; }
    yield* sub_109ee();
    memorySet(ds, 0x97da, 0x01);
    r16[cx] = 0x01e0;
  case 0x16d57:
    yield* sync();
    push(r16[cx]);
    yield* sub_19b1c();
    yield* sub_19bdc();
    if (r8[al] & 0x10)
        { pc = 0x16d66; break; }
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x16d57; break; }
    sp += 2;
    return;
  case 0x16d66:
    { pc = 0x1c3b0; break; }
    // gap 22087 bytes
  case 0x1c3b0:
    memorySet16(ds, 0x6614, 0x0006);
    yield* sub_199c8();
    sp = memoryGet16(ds, 0xc0df);
    memorySet16(ds, 0x6610, 0x0006);
    memorySet16(ds, 0x6612, 0x0006);
    memorySet16(ds, 0x7e00, 0x0000);
    memorySet16(ds, 0x762d, 0x0000);
    memorySet16(ds, 0x762f, 0x0000);
    yield* sub_1a54a();
    push(cs);
    ds = pop();
    yield* sub_1a56b();
    yield* sub_10594();
    yield* sub_105a1();
    yield* sub_1a45c();
    yield* sub_1c4e2();
    yield* sub_112d6();
    yield* sub_10d03();
    yield* sub_10ee5();
    yield* sub_10ee7();
    r16[ax] = 0x0004;
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[ax] = memoryGet16(ds, 0x8bec);
    r16[ax]--;
    r16[ax] += r16[ax];
    r16[si] = 0x2f69;
    r16[si] += r16[ax];
    r16[ax] = memoryGet16(ds, r16[si]);
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[ax] = 0x0000;
    yield* sub_1a257();
    yield* sub_1a5f0();
    yield* sub_10d03();
    yield* sub_19420();
    memorySet16(ds, 0x973c, 0x3245);
    memorySet16(ds, 0x973e, 0x5432);
  case 0x1c439:
    memorySet16(ds, 0x7e16, 0x0000);
    memorySet16(ds, 0x7e18, 0x0000);
  case 0x1c445:
    yield* sub_16b3b();
    if (memoryGet16(ds, 0x7e18) != 0x0001)
        { pc = 0x1c467; break; }
    memorySet16(ds, 0x762f, 0x0000);
    yield* sub_1618f();
    yield* sub_19462();
    if (memoryGet16(ds, 0x6614))
        { pc = 0x1c465; break; }
    yield* sub_19f12();
    return;
  case 0x1c465:
    { pc = 0x1c439; break; }
  case 0x1c467:
    yield* sub_19bac();
    yield* sub_15f40();
    memorySet(ds, 0x5b3e, 0x00);
    yield* sub_169e3();
    yield* sub_168e4();
    yield* sub_17205();
    yield* sub_18351();
    yield* sub_18cbe();
    yield* sub_18d28();
    yield* sub_1705d();
    yield* sub_10a67();
    yield* sub_1091b();
    yield* sub_11162();
    yield* sub_109ee();
    yield* sub_19af6();
    yield* sub_10ee4();
    yield* sub_194c4();
    if (memoryGet(ds, 0xb888) != 0x10)
        { pc = 0x1c4b3; break; }
    yield* sub_19f8a();
    if (!flags.carry)
        { pc = 0x1c4b3; break; }
    yield* sub_1c359();
    return;
  case 0x1c4b3:
    if (memoryGet(ds, 0xb888) != 0x01)
        { pc = 0x1c445; break; }
    yield* sub_196f3();
    return;
  }
}
function* sub_16d69() // 1040:6969
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_16c69();
    if (!flags.carry)
        { pc = 0x16d7d; break; }
    push(r16[bx]);
    yield* sub_16eb2();
    r16[bx] = pop();
    r16[cx] = 0x000a;
    r16[si] = 0x6671;
    r16[di] = r16[bx];
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
  case 0x16d7d:
    return;
  }
}
function* sub_16e16() // 1040:6a16
{
    r16[ax] = 0;
    r16[dx] = memoryGet16(ds, 0x69f0);
    r8[al] = r8[dh];
    r8[al] -= 0x08;
    r16[ax] &= 0xfffe;
    r16[bx] = r16[ax];
    r16[ax] <<= 1;
    r16[bx] += r16[ax];
    r8[dh] = 0;
    r16[dx] -= 0x000e;
    r16[dx] >>= 1;
    r16[bx] += r16[dx];
    r16[bx] += 0x69f8;
    r8[al] = memoryGet(ds, r16[bx]);
}
function* sub_16e39() // 1040:6a39
{
    r16[ax] = memoryGet16(ds, 0x69f2);
    r16[si] = 0x69ee;
    yield* sub_107f1();
    r16[ax] = memoryGet16(ds, 0x69f0);
    r16[si] = 0x69ec;
    yield* sub_107f1();
    yield* sub_109ee();
    r16[ax] = memoryGet16(ds, 0x69f2);
    r16[si] = 0x69ee;
    yield* sub_107f1();
    r16[ax] = memoryGet16(ds, 0x69f0);
    r16[si] = 0x69ec;
    yield* sub_107f1();
}
function* sub_16e66() // 1040:6a66
{
    r16[ax] = memoryGet16(ds, 0x69f0);
    memorySet16(ds, 0x69f2, r16[ax]);
    memorySet16(ds, 0x69f0, r16[dx]);
    yield* sub_16e39();
}
function* sub_16e74() // 1040:6a74
{
    r16[ax] = memoryGet16(ds, 0x69f6);
    r16[si] = 0x69ee;
    yield* sub_107f1();
    r16[ax] = memoryGet16(ds, 0x69f4);
    r16[si] = 0x69ec;
    yield* sub_107f1();
    yield* sub_109ee();
    r16[ax] = memoryGet16(ds, 0x69f6);
    r16[si] = 0x69ee;
    yield* sub_107f1();
    r16[ax] = memoryGet16(ds, 0x69f4);
    r16[si] = 0x69ec;
    yield* sub_107f1();
}
function* sub_16ea1() // 1040:6aa1
{
    r16[ax] = memoryGet16(ds, 0x69f4);
    memorySet16(ds, 0x69f6, r16[ax]);
    memorySet16(ds, 0x69f4, r16[dx]);
    yield* sub_16e74();
}
function* sub_16eb2() // 1040:6ab2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x090e;
    memorySet16(ds, 0x69f0, r16[ax]);
    memorySet16(ds, 0x69f2, r16[ax]);
    r16[ax] = 0x150e;
    memorySet16(ds, 0x69f4, r16[ax]);
    memorySet16(ds, 0x69f6, r16[ax]);
    r16[di] = 0x6671;
    r16[cx] = 0x000a;
    r8[al] = 0x0e;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
    memorySet16(ds, 0x6ab0, 0x6671);
    yield* sub_10d03();
    r16[ax] = 0x0005;
    r16[si] = 0x93a1;
    yield* sub_107ac();
    r16[ax] = 0x0105;
    r16[si] = 0x93c1;
    yield* sub_107ac();
    r16[ax] = 0x0205;
    r16[si] = 0x93e1;
    yield* sub_107ac();
    r16[bx] = 0x69de;
    yield* sub_19c43();
    r16[ax] = 0x140e;
    r16[si] = 0x6671;
    yield* sub_107f1();
    yield* sub_109ee();
    r16[ax] = 0x0005;
    r16[si] = 0x93a1;
    yield* sub_107ac();
    r16[ax] = 0x0105;
    r16[si] = 0x93c1;
    yield* sub_107ac();
    r16[ax] = 0x0205;
    r16[si] = 0x93e1;
    yield* sub_107ac();
    r16[bx] = 0x69de;
    yield* sub_19c43();
    r16[ax] = 0x140e;
    r16[si] = 0x6671;
    yield* sub_107f1();
    yield* sub_16e39();
    yield* sub_16e74();
  case 0x16f3e:
    r16[ax] = 0x140e;
    r16[si] = 0x6671;
    yield* sub_107f1();
    yield* sub_109ee();
    r16[ax] = 0x140e;
    r16[si] = 0x6671;
    yield* sub_107f1();
    r16[cx] = 0x0006;
  case 0x16f59:
    yield* sub_19b1c();
    if (--r16[cx])
        { pc = 0x16f59; break; }
    yield* sub_1c4ca();
    if (memoryGet(ds, 0x6aaf) != 0x01)
        { pc = 0x16f71; break; }
    if (r8[al] & 0x10)
        { pc = 0x16f71; break; }
    memorySet(ds, 0x6aaf, 0x00);
  case 0x16f71:
    r16[dx] = memoryGet16(ds, 0x69f0);
    if (!(r8[al] & 0x08))
        { pc = 0x16f7c; break; }
    r8[dh] -= 0x02;
  case 0x16f7c:
    if (!(r8[al] & 0x04))
        { pc = 0x16f83; break; }
    r8[dh] += 0x02;
  case 0x16f83:
    if (!(r8[al] & 0x01))
        { pc = 0x16f8a; break; }
    r8[dl] += 0x02;
  case 0x16f8a:
    if (!(r8[al] & 0x02))
        { pc = 0x16f91; break; }
    r8[dl] -= 0x02;
  case 0x16f91:
    if (r8[al] & 0x10)
        { pc = 0x16fbc; break; }
    if (r8[dl] != 0x0c)
        { pc = 0x16f9f; break; }
    r8[dl] = 0x0e;
    { pc = 0x16fa6; break; }
    // gap 1 bytes
  case 0x16f9f:
    if (r8[dl] != 0x1a)
        { pc = 0x16fa6; break; }
    r8[dl] = 0x18;
  case 0x16fa6:
    if (r8[dh] != 0x07)
        { pc = 0x16fb0; break; }
    r8[dh] = 0x09;
    { pc = 0x16fb7; break; }
    // gap 1 bytes
  case 0x16fb0:
    if (r8[dh] != 0x13)
        { pc = 0x16fb7; break; }
    r8[dh] = 0x11;
  case 0x16fb7:
    yield* sub_16e66();
    { pc = 0x16f3e; break; }
  case 0x16fbc:
    if (memoryGet(ds, 0x6aaf) != 0x01)
        { pc = 0x16fc6; break; }
    { pc = 0x16f3e; break; }
  case 0x16fc6:
    yield* sub_16e16();
    memorySet(ds, 0x6aaf, 0x01);
    if (r8[al] == 0x11)
        { pc = 0x16fe2; break; }
    if (r8[al] != 0x10)
        { pc = 0x16fdc; break; }
    yield* sub_16ff5();
    { pc = 0x16f3e; break; }
  case 0x16fdc:
    yield* sub_17018();
    { pc = 0x16f3e; break; }
  case 0x16fe2:
    r16[si] = 0x6671;
    r16[cx] = 0x000a;
  case 0x16fe8:
    r8[al] = memoryGet(ds, r16[si]);
    if (r8[al] != 0x0e)
        { pc = 0x16ff1; break; }
    memorySet(ds, r16[si], 0x20);
  case 0x16ff1:
    r16[si]++;
    if (--r16[cx])
        { pc = 0x16fe8; break; }
    return;
  }
}
function* sub_16ff5() // 1040:6bf5
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[di] = memoryGet16(ds, 0x6ab0);
    r16[di]--;
    if (r16[di] == 0x6670)
        { pc = 0x17017; break; }
    memorySet(ds, r16[di], 0x0e);
    memorySet16(ds, 0x6ab0, r16[di]);
    r16[dx] = memoryGet16(ds, 0x6ab0);
    r16[dx] -= 0x6671;
    r8[dh] = 0x15;
    r8[dl] += 0x0e;
    yield* sub_16ea1();
  case 0x17017:
    return;
  }
}
function* sub_17018() // 1040:6c18
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[di] = memoryGet16(ds, 0x6ab0);
    if (r16[di] == 0x667b)
        { pc = 0x17029; break; }
    memorySet(ds, r16[di], r8[al]);
    r16[di]++;
    memorySet16(ds, 0x6ab0, r16[di]);
  case 0x17029:
    r16[dx] = memoryGet16(ds, 0x6ab0);
    r16[dx] -= 0x6671;
    r8[dh] = 0x15;
    if (r8[dl] != 0x0a)
        { pc = 0x1703a; break; }
    r8[dl] = 0x09;
  case 0x1703a:
    r8[dl] += 0x0e;
    push(r16[ax]);
    yield* sub_16ea1();
    r16[ax] = pop();
    return;
  }
}
function* sub_17047() // 1040:6c47
{
    memorySet16(ds, 0x6c43, 0x0000);
    r16[ax] = memoryGet16(ds, 0x8bf0);
    memorySet16(ds, 0x6c45, r16[ax]);
    memorySet16(ds, 0x6c45, memoryGet16(ds, 0x6c45) & 0x0007);
    yield* sub_108dd();
}
function* sub_1705d() // 1040:6c5d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x7e16) != 0x0001)
        { pc = 0x17065; break; }
    return;
  case 0x17065:
    r16[ax] = memoryGet16(ds, 0x8bf0);
    r16[ax] &= 0x0007;
    r16[dx] = memoryGet16(ds, 0x0b20);
    r16[dx] -= r16[ax];
    if (r16s[dx] >= signed16(0x009b))
        { pc = 0x17082; break; }
    r16[bx] = memoryGet16(ds, 0x6c43);
    if (r16s[bx] < 0)
        { pc = 0x17099; break; }
    { pc = 0x1709c; break; }
    // gap 1 bytes
  case 0x17082:
    if (r16s[dx] < signed16(0x0086))
        { pc = 0x1709c; break; }
    r16[bx] = memoryGet16(ds, 0x6c43);
    if (!r16[bx])
        { pc = 0x1709c; break; }
    if (r16s[bx] >= 0)
        { pc = 0x17095; break; }
    { pc = 0x1709c; break; }
    // gap 1 bytes
  case 0x17095:
    yield* sub_170e6();
    return;
  case 0x17099:
    yield* sub_1709d();
  case 0x1709c:
    return;
  }
}
function* sub_1709d() // 1040:6c9d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = memoryGet16(ds, 0x8bf0);
    r16[dx] = r16[ax];
    r16[ax] += memoryGet16(ds, 0x6c43);
    if (r16s[ax] >= signed16(memoryGet16(ds, 0x8bf2)))
        { pc = 0x170bb; break; }
    r16[cx] = memoryGet16(ds, 0x8bf2);
    r16[cx] -= memoryGet16(ds, 0x8bf0);
    memorySet16(ds, 0x6c43, r16[cx]);
    r16[ax] = memoryGet16(ds, 0x8bf2);
  case 0x170bb:
    memorySet16(ds, 0x8bf0, r16[ax]);
    if (r16[dx] == r16[ax])
        { pc = 0x170e1; break; }
    r16[dx] &= 0x0007;
    r16[dx] += memoryGet16(ds, 0x6c43);
    if (r16s[dx] >= 0)
        { pc = 0x170e2; break; }
    yield* sub_195ea();
    yield* sub_1930a();
    yield* sub_10986();
    yield* sub_17180();
    r16[dx] = 0x0008;
    yield* sub_17132();
    yield* sub_15fe4();
  case 0x170e1:
    return;
  case 0x170e2:
    yield* sub_17180();
    return;
  }
}
function* sub_170e6() // 1040:6ce6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = memoryGet16(ds, 0x8bf0);
    r16[dx] = r16[ax];
    r16[ax] += memoryGet16(ds, 0x6c43);
    if (r16s[ax] <= signed16(memoryGet16(ds, 0x8bf4)))
        { pc = 0x17104; break; }
    r16[cx] = memoryGet16(ds, 0x8bf4);
    r16[cx] -= memoryGet16(ds, 0x8bf0);
    memorySet16(ds, 0x6c43, r16[cx]);
    r16[ax] = memoryGet16(ds, 0x8bf4);
  case 0x17104:
    memorySet16(ds, 0x8bf0, r16[ax]);
    if (r16[dx] == r16[ax])
        { pc = 0x1712d; break; }
    r16[dx] &= 0x0007;
    r16[dx] += memoryGet16(ds, 0x6c43);
    if (r16s[dx] <= signed16(0x0007))
        { pc = 0x1712e; break; }
    yield* sub_1961d();
    yield* sub_192da();
    yield* sub_109a5();
    yield* sub_17180();
    r16[dx] = 0xfff8;
    yield* sub_17132();
    yield* sub_15fe4();
  case 0x1712d:
    return;
  case 0x1712e:
    yield* sub_17180();
    return;
  }
}
function* sub_17132() // 1040:6d32
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] = 0x0b00;
  case 0x17135:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16s[ax] < 0)
        { pc = 0x17145; break; }
    if (!r16[ax])
        { pc = 0x17140; break; }
    memorySet16(ds, r16[si] + 4, memoryGet16(ds, r16[si] + 4) + r16[dx]);
  case 0x17140:
    r16[si] += 0x001c;
    { pc = 0x17135; break; }
  case 0x17145:
    r16[si] = 0x0c28;
  case 0x17148:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16s[ax] < 0)
        { pc = 0x17162; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x1715d; break; }
    memorySet16(ds, r16[si] + 4, memoryGet16(ds, r16[si] + 4) + r16[dx]);
    yield* sub_1613c();
    if (!flags.carry)
        { pc = 0x1715d; break; }
    yield* sub_1615f();
  case 0x1715d:
    r16[si] += 0x0034;
    { pc = 0x17148; break; }
  case 0x17162:
    r16[si] = 0x0b56;
  case 0x17165:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16s[ax] < 0)
        { pc = 0x1717f; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x1717a; break; }
    memorySet16(ds, r16[si] + 4, memoryGet16(ds, r16[si] + 4) + r16[dx]);
    yield* sub_1613c();
    if (!flags.carry)
        { pc = 0x1717a; break; }
    yield* sub_1615f();
  case 0x1717a:
    r16[si] += 0x0034;
    { pc = 0x17165; break; }
  case 0x1717f:
    return;
  }
}
function* sub_17180() // 1040:6d80
{
    r16[ax] = memoryGet16(ds, 0x6c45);
    r16[ax] += memoryGet16(ds, 0x6c43);
    r16[ax] &= 0x00ff;
    memorySet16(ds, 0x6c45, r16[ax]);
}
function* sub_1718e() // 1040:6d8e +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, r16[si]) & 0xffff)
        { pc = 0x17196; break; }
    flags.carry = 0;
    return;
  case 0x17196:
    if (!(memoryGet16(ds, r16[si] + 24) & 0xffff))
        { pc = 0x171a2; break; }
    memorySet16(ds, r16[si] + 24, memoryGet16(ds, r16[si] + 24) - 1);
    flags.carry = 0;
    return;
  case 0x171a2:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[dx]);
    r16[dx] = 0;
    r16[bx] = memoryGet16(ds, r16[si] + 22);
  case 0x171aa:
    r16[ax] = memoryGet16(ds, r16[bx]);
    if (r16s[ax] < 0)
        { pc = 0x171bb; break; }
    memorySet16(ds, r16[si] + 10, r16[ax]);
    r16[bx]++;
    r16[bx]++;
    memorySet16(ds, r16[si] + 22, r16[bx]);
    { pc = 0x171f5; break; }
    // gap 1 bytes
  case 0x171bb:
    if (r16[ax] != 0xffff)
        { pc = 0x171cd; break; }
    r16[ax] = memoryGet16(ds, r16[bx] + 2);
    r16[bx] += r16[ax];
    memorySet16(ds, r16[si] + 22, r16[si]);
    r16[dx] = 0xffff;
    { pc = 0x171aa; break; }
  case 0x171cd:
    if (r16[ax] != 0xfffd)
        { pc = 0x171e0; break; }
    r16[ax] = memoryGet16(ds, r16[bx] + 2);
    yield* sub_1aecd();
    r16[bx] += 0x0004;
    memorySet16(ds, r16[si] + 22, r16[bx]);
    { pc = 0x171aa; break; }
  case 0x171e0:
    r16[ax] = memoryGet16(ds, r16[bx] + 2);
    memorySet16(ds, r16[si] + 24, r16[ax]);
    memorySet16(ds, r16[si] + 24, memoryGet16(ds, r16[si] + 24) - 1);
    r16[ax] = memoryGet16(ds, r16[bx] + 4);
    memorySet16(ds, r16[si] + 10, r16[ax]);
    r16[bx] += 0x0006;
    memorySet16(ds, r16[si] + 22, r16[bx]);
  case 0x171f5:
    if (r16[dx])
        { pc = 0x171fe; break; }
    r16[dx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    flags.carry = 0;
    return;
  case 0x171fe:
    r16[dx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    flags.carry = 1;
    return;
  }
}
function* sub_17205() // 1040:6e05
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_177fb();
    r16[si] = 0x0b56;
  case 0x1720b:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16s[ax] < 0)
        { pc = 0x1721f; break; }
    if (!(r8[al] & 0x01))
        { pc = 0x1721a; break; }
    push(r16[si]);
    yield* sub_17222();
    r16[si] = pop();
  case 0x1721a:
    r16[si] += 0x0034;
    { pc = 0x1720b; break; }
  case 0x1721f:
    return;
  }
}
function* sub_17222() // 1040:6e22
{
  var pc = 0;
  var temp_cf;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x17222; break; }
  case 0x168a8:
    r16[ax] = 0x000b;
    yield* sub_1aecd();
    memorySet16(ds, 0x7e16, 0x0001);
    memorySet16(ds, 0x0b24, 0xfb00);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    if (r16s[ax] < signed16(0x0080))
        { pc = 0x168cb; break; }
    memorySet16(ds, 0x7e1c, 0xfffe);
    { pc = 0x168d1; break; }
    // gap 1 bytes
  case 0x168cb:
    memorySet16(ds, 0x7e1c, 0x0002);
  case 0x168d1:
    r16[ax] = memoryGet16(ds, 0x6614);
    if (!r16[ax])
        { pc = 0x168e3; break; }
    if (memoryGet(ds, 0x9804) == 0x01)
        { pc = 0x168e3; break; }
    memorySet16(ds, 0x6614, memoryGet16(ds, 0x6614) - 1);
  case 0x168e3:
    return;
    // gap 2366 bytes
  case 0x17222:
    memorySet16(ds, 0x6e20, 0x0000);
    memorySet16(ds, 0x6e03, 0x0000);
    if (!memoryGet16(ds, r16[si] + 24))
        { pc = 0x17246; break; }
    memorySet16(ds, r16[si] + 24, memoryGet16(ds, r16[si] + 24) - 1);
    if (memoryGet16(ds, r16[si] + 22) != 0x0001)
        { pc = 0x17240; break; }
    { pc = 0x176a0; break; }
  case 0x17240:
    memorySet16(ds, 0x6e20, 0x0001);
  case 0x17246:
    memorySet16(ds, r16[si] + 44, 0x0000);
    memorySet16(ds, r16[si] + 46, 0x0000);
    if (memoryGet16(ds, r16[si] + 22) != 0x0001)
        { pc = 0x17259; break; }
    { pc = 0x176a0; break; }
  case 0x17259:
    if (memoryGet16(ds, r16[si] + 42) != 0x0001)
        { pc = 0x17262; break; }
    { pc = 0x17644; break; }
  case 0x17262:
    memorySet16(ds, r16[si] + 44, 0x0000);
    memorySet16(ds, r16[si] + 46, 0x0000);
    memorySet16(ds, r16[si] + 34, 0x0000);
    memorySet16(ds, r16[si] + 36, 0x0000);
    memorySet16(ds, r16[si] + 38, 0x0000);
    memorySet16(ds, r16[si] + 40, 0x0000);
    memorySet(ds, 0x796b, 0x01);
    memorySet16(ds, 0x6e03, 0x0000);
    r16[dx] = memoryGet16(ds, r16[si] + 8);
    r16[dx] += 0x0080;
    if (r16s[dx] <= signed16(0x0800))
        { pc = 0x1729c; break; }
    r16[dx] = 0x0800;
  case 0x1729c:
    memorySet16(ds, r16[si] + 8, r16[dx]);
    memorySet16(ds, 0x7961, r16[dx]);
    if (r16s[dx] < 0)
        { pc = 0x172ac; break; }
    r8[ch] = 0;
    { pc = 0x172ae; break; }
    // gap 1 bytes
  case 0x172ac:
    r8[ch] = 0xff;
  case 0x172ae:
    r16[ax] = memoryGet16(ds, r16[si] + 4);
    r8[cl] = memoryGet(ds, r16[si] + 6);
    flags.carry = r8[cl] + r8[dl] >= 0x100;
    r8[cl] += r8[dl];
    temp_cf = flags.carry;
    temp_cf = (r8[al] + r8[dh]) + flags.carry >= 0x100;
    r8[al] += (r8[dh] + flags.carry);
    flags.carry = temp_cf;
    r8[ah] += (r8[ch] + flags.carry);
    memorySet16(ds, 0x795f, r16[ax]);
    r16[dx] = memoryGet16(ds, r16[si] + 2);
    memorySet16(ds, 0x795d, r16[dx]);
    memorySet(ds, 0x796b, 0x01);
    yield* sub_17dfb();
  case 0x172cd:
    r8[ch] = memoryGet(ds, 0x7963);
    if (!(r8[ch] & 0x20))
        { pc = 0x172da; break; }
    { pc = 0x17674; break; }
  case 0x172da:
    if (!(r8[ch] & 0x40))
        { pc = 0x1733d; break; }
    r16[ax] = memoryGet16(ds, 0x7964);
    r8[cl] = 0;
    r16[ax] -= 0x0015;
    memorySet16(ds, 0x795f, r16[ax]);
    memorySet16(ds, r16[si] + 4, r16[ax]);
    memorySet(ds, r16[si] + 6, 0x00);
    memorySet16(ds, r16[si] + 34, 0x0001);
    push(r16[ax]);
    r16[ax] = memoryGet16(ds, 0x7966);
    memorySet16(ds, r16[si] + 44, r16[ax]);
    r16[ax] = pop();
    memorySet(ds, 0x796b, 0x00);
    yield* sub_17dfb();
    r8[ch] = memoryGet(ds, 0x7963);
    if (!(r8[ch] & 0x20))
        { pc = 0x17315; break; }
    { pc = 0x17674; break; }
  case 0x17315:
    r8[ch] &= 0x06;
    if (!r8[ch])
        { pc = 0x17321; break; }
    r8[ch] = memoryGet(ds, 0x7963);
    { pc = 0x1735c; break; }
    // gap 1 bytes
  case 0x17321:
    r16[bp] = memoryGet16(cs, r16[si] + 44);
    r16[bp] |= memoryGet16(cs, r16[si] + 46);
    if (!r16[bp])
        { pc = 0x17333; break; }
    memorySet16(ds, 0x6e03, 0x0001);
  case 0x17333:
    r8[ch] = memoryGet(ds, 0x7963);
    r16[dx] = 0x0100;
    { pc = 0x173e4; break; }
  case 0x1733d:
    if (!(r8[ch] & 0x20))
        { pc = 0x17346; break; }
    { pc = 0x17674; break; }
  case 0x17346:
    if (r8[ch] & 0x04)
        { pc = 0x1736d; break; }
    if (r8[ch] & 0x02)
        { pc = 0x17355; break; }
    { pc = 0x1740e; break; }
  case 0x17355:
    r16[bp] = memoryGet16(ds, r16[si] + 8);
    if (r16s[bp] >= 0)
        { pc = 0x1736d; break; }
  case 0x1735c:
    r16[ax] |= 0x0007;
    r16[ax]++;
    r8[cl] = 0;
    memorySet16(ds, r16[si] + 8, 0x0100);
    r16[dx] = 0x0100;
    { pc = 0x1740e; break; }
  case 0x1736d:
    if (memoryGet16(ds, r16[si] + 48) != 0x0003)
        { pc = 0x17394; break; }
    if (!(r8[ch] & 0x10))
        { pc = 0x17394; break; }
    yield* sub_176f4();
    if (flags.carry)
        { pc = 0x17394; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 2);
    r16[bx] &= 0x001f;
    if (r16[bx] != 0x0004)
        { pc = 0x17394; break; }
    memorySet16(ds, r16[si] + 42, 0x0001);
    { pc = 0x1740e; break; }
    // gap 1 bytes
  case 0x17394:
    memorySet16(ds, r16[si] + 42, 0x0000);
    memorySet16(ds, r16[si] + 34, 0x0001);
    r16[ax] += 0x000c;
    r16[ax] |= 0x0007;
    r16[ax] -= 0x0014;
    r8[cl] = 0;
    memorySet16(ds, r16[si] + 4, r16[ax]);
    memorySet(ds, r16[si] + 6, r8[cl]);
    r16[dx] = 0x0100;
    if (!(r8[ch] & 0x01))
        { pc = 0x173e4; break; }
    if (memoryGet16(ds, 0x8bec) != 0x0003)
        { pc = 0x173e4; break; }
    r16[dx] = memoryGet16(ds, r16[si] + 8);
    if (r16s[dx] < signed16(0x0200))
        { pc = 0x173d8; break; }
    r16[dx] = -r16[dx];
    r16[dx] += 0x0060;
    memorySet16(ds, r16[si] + 8, r16[dx]);
    r16[dx] = 0xf781;
    { pc = 0x1740e; break; }
    // gap 1 bytes
  case 0x173d8:
    memorySet16(ds, r16[si] + 8, 0x0100);
    r16[dx] = 0xfa00;
    { pc = 0x1740e; break; }
    // gap 1 bytes
  case 0x173e4:
    memorySet16(ds, r16[si] + 8, r16[dx]);
    r16[dx] = 0xfa00;
    if (!(r8[ch] & 0x01))
        { pc = 0x1740e; break; }
    if (memoryGet16(ds, 0x8bec) != 0x0001)
        { pc = 0x173ff; break; }
    r16[dx] = 0xfe00;
    { pc = 0x1740e; break; }
    // gap 1 bytes
  case 0x173ff:
    if (memoryGet16(ds, 0x8bec) != 0x0005)
        { pc = 0x1740e; break; }
    memorySet16(ds, r16[si] + 8, 0xf781);
    { pc = 0x1743b; break; }
    // gap 1 bytes
  case 0x1740e:
    memorySet16(ds, r16[si] + 4, r16[ax]);
    memorySet(ds, r16[si] + 6, r8[cl]);
    if (memoryGet16(ds, r16[si] + 48) != 0x0003)
        { pc = 0x1743b; break; }
    if (!(r8[ch] & 0x08))
        { pc = 0x1743b; break; }
    if (r8[ch] & 0x10)
        { pc = 0x1743b; break; }
    yield* sub_176f4();
    if (!flags.carry)
        { pc = 0x1743b; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 2);
    r16[bx] &= 0x001f;
    if (r16[bx] != 0x0004)
        { pc = 0x1743b; break; }
    memorySet16(ds, r16[si] + 42, 0x0001);
  case 0x1743b:
    if (memoryGet16(ds, 0x6e03) != 0x0001)
        { pc = 0x1744d; break; }
    r16[dx] = memoryGet16(ds, r16[si] + 44);
    r16[bx] = memoryGet16(ds, r16[si] + 2);
    r16[bx] += r16[dx];
    { pc = 0x17573; break; }
  case 0x1744d:
    r16[bp] = memoryGet16(cs, r16[si] + 8);
    if (r16s[bp] < 0)
        { pc = 0x1745e; break; }
    if (memoryGet16(ds, r16[si] + 34) == 0x0001)
        { pc = 0x1745e; break; }
    { pc = 0x1746a; break; }
    // gap 1 bytes
  case 0x1745e:
    if (memoryGet16(ds, r16[si] + 48) != 0x0003)
        { pc = 0x17473; break; }
    if (memoryGet16(ds, r16[si] + 42) != 0x0001)
        { pc = 0x17473; break; }
  case 0x1746a:
    r16[dx] = 0x0000;
    r16[bx] = memoryGet16(ds, r16[si] + 2);
    { pc = 0x17573; break; }
  case 0x17473:
    r16[dx] = memoryGet16(ds, r16[si] + 16);
    if (!(r8[ch] & 0x01))
        { pc = 0x174a3; break; }
    if (memoryGet16(ds, 0x8bec) == 0x0002)
        { pc = 0x1749e; break; }
    if (memoryGet16(ds, 0x8bec) != 0x0004)
        { pc = 0x174a3; break; }
    memorySet16(ds, r16[si] + 38, 0x0001);
    r16[dx] = 0x0001;
    if (!(memoryGet16(ds, r16[si] + 16) & 0x8000))
        { pc = 0x174a3; break; }
    r16[dx] = -r16[dx];
    { pc = 0x174a3; break; }
    // gap 1 bytes
  case 0x1749e:
    memorySet16(ds, r16[si] + 40, 0x0001);
  case 0x174a3:
    if (memoryGet16(ds, r16[si] + 48) != 0x0001)
        { pc = 0x174be; break; }
    memorySet16(ds, r16[si] + 20, memoryGet16(ds, r16[si] + 20) + 1);
    r16[ax] = memoryGet16(ds, r16[si] + 18);
    if (r16[ax] != memoryGet16(ds, r16[si] + 20))
        { pc = 0x174f8; break; }
    r16[ax] = 0;
    memorySet16(ds, r16[si] + 20, r16[ax]);
    r16[dx] = -r16[dx];
    { pc = 0x174f8; break; }
    // gap 1 bytes
  case 0x174be:
    if (memoryGet16(ds, r16[si] + 48) != 0x0002)
        { pc = 0x174e0; break; }
    r16[ax] = memoryGet16(ds, r16[si] + 2);
    r16[ax] &= 0x000f;
    if (r16[ax] != 0x0004)
        { pc = 0x174f8; break; }
    yield* sub_19b40();
    if (memoryGet(ds, 0x973f) & 0x01)
        { pc = 0x174f8; break; }
    yield* sub_176e6();
    { pc = 0x174f8; break; }
    // gap 1 bytes
  case 0x174e0:
    r16[ax] = memoryGet16(ds, r16[si] + 2);
    r16[ax] &= 0x000f;
    if (r16[ax] != 0x0004)
        { pc = 0x174f8; break; }
    yield* sub_19b40();
    if (memoryGet(ds, 0x973f) & 0x01)
        { pc = 0x174f8; break; }
    r16[dx] = -r16[dx];
  case 0x174f8:
    r16[dx] += memoryGet16(ds, r16[si] + 44);
    r16[bx] = memoryGet16(ds, r16[si] + 2);
    r16[bx] += r16[dx];
    if (!r16[dx])
        { pc = 0x1751e; break; }
    if (r16s[dx] >= 0)
        { pc = 0x17513; break; }
    if (r16s[bx] >= signed16(0x0000))
        { pc = 0x1751e; break; }
    r16[bx] = 0x0000;
    r16[dx] = -r16[dx];
    { pc = 0x1751e; break; }
    // gap 1 bytes
  case 0x17513:
    if (r16s[bx] < signed16(0x00e8))
        { pc = 0x1751e; break; }
    r16[bx] = 0x00e8;
    r16[dx] = -r16[dx];
  case 0x1751e:
    r16[ax] = memoryGet16(ds, r16[si] + 4);
    memorySet16(ds, 0x795f, r16[ax]);
    memorySet16(ds, 0x7961, 0xffff);
    memorySet16(ds, 0x795d, r16[bx]);
    memorySet(ds, 0x796b, 0x01);
    yield* sub_17dfb();
    r8[ch] = memoryGet(ds, 0x7963);
    if (!(r8[ch] & 0x20))
        { pc = 0x17544; break; }
    { pc = 0x17674; break; }
  case 0x17544:
    if (!(r8[ch] & 0x02))
        { pc = 0x17573; break; }
    if (r16s[dx] >= 0)
        { pc = 0x17562; break; }
    r16[bx] += 0x000c;
    r16[bx] &= 0x00f8;
    r16[bx] -= 0x0004;
    r16[dx] = -r16[dx];
    memorySet16(ds, r16[si] + 20, 0x0000);
    { pc = 0x17573; break; }
    // gap 1 bytes
  case 0x17562:
    r16[bx] += 0x0003;
    r16[bx] &= 0x00f8;
    r16[bx] -= 0x0004;
    r16[dx] = -r16[dx];
    memorySet16(ds, r16[si] + 20, 0x0000);
  case 0x17573:
    if (memoryGet16(ds, 0x6e20) == 0x0001)
        { pc = 0x17584; break; }
    memorySet16(ds, r16[si] + 2, r16[bx]);
    if (!r16[dx])
        { pc = 0x17584; break; }
    memorySet16(ds, r16[si] + 16, r16[dx]);
  case 0x17584:
    if (memoryGet16(ds, r16[si] + 48) != 0x0003)
        { pc = 0x17595; break; }
    if (r8[ch] & 0x08)
        { pc = 0x17595; break; }
    memorySet16(ds, r16[si] + 42, 0x0000);
  case 0x17595:
    if (memoryGet16(ds, 0x6e03) == 0x0001)
        { pc = 0x175a6; break; }
    if (memoryGet16(ds, 0x6e20) == 0x0001)
        { pc = 0x175a6; break; }
    yield* sub_17723();
  case 0x175a6:
    if (memoryGet16(ds, 0x7ecc) != 0x0001)
        { pc = 0x175c6; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r8[dh] = memoryGet(ds, r16[si] + 2);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[ah] = memoryGet(ds, r16[si] + 32);
    yield* sub_1646e();
    if (!flags.carry)
        { pc = 0x175c6; break; }
    memorySet16(ds, r16[si] + 24, 0x0028);
    { pc = 0x175de; break; }
    // gap 1 bytes
  case 0x175c6:
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r16[bx] += 0x0004;
    r8[dh] = memoryGet(ds, r16[si] + 2);
    r8[dh] += 0x04;
    r8[dl] = 0x10;
    r8[ah] = 0x15;
    yield* sub_16407();
    if (!flags.carry)
        { pc = 0x175de; break; }
    { pc = 0x168a8; break; }
  case 0x175de:
    if (memoryGet16(ds, 0x0b00) != 0x0001)
        { pc = 0x175ff; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r8[dh] = memoryGet(ds, r16[si] + 2);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[ah] = memoryGet(ds, r16[si] + 32);
    yield* sub_164a0();
    if (!flags.carry)
        { pc = 0x175ff; break; }
    memorySet16(ds, 0x0b00, 0x0000);
    { pc = 0x17674; break; }
    // gap 1 bytes
  case 0x175ff:
    if (memoryGet16(ds, 0x0b38) != 0x0002)
        { pc = 0x17643; break; }
    r8[al] = memoryGet(ds, 0x0b4a);
    if (r8s[al] <= signed8(0x01))
        { pc = 0x17643; break; }
    if (r8s[al] > signed8(0x04))
        { pc = 0x17643; break; }
    r16[bx] = memoryGet16(ds, r16[si] + 4);
    r8[dh] = memoryGet(ds, r16[si] + 2);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[ah] = memoryGet(ds, r16[si] + 32);
    if (r8[dh] >= 0x0f)
        { pc = 0x17627; break; }
    r8[dh] = 0;
    { pc = 0x1762a; break; }
    // gap 1 bytes
  case 0x17627:
    r8[dh] -= 0x10;
  case 0x1762a:
    r16[bx] -= 0x000e;
    r8[dl] += 0x20;
    r8[ah] += 0x1d;
    yield* sub_164e1();
    if (!flags.carry)
        { pc = 0x17643; break; }
    push(r16[si]);
    r16[si] = 0x670b;
    yield* sub_16bc7();
    r16[si] = pop();
    { pc = 0x17674; break; }
    // gap 1 bytes
  case 0x17643:
    return;
  case 0x17644:
    r16[ax] = memoryGet16(ds, r16[si] + 4);
    r8[cl] = 0;
    r16[bp] = memoryGet16(ds, 0x0b20);
    r16[bp]++;
    r16[bp] &= 0x00fe;
    r16[ax] &= 0x00fe;
    yield* sub_17702();
    memorySet16(ds, 0x7961, r16[bp]);
    r16[ax] = memoryGet16(ds, r16[si] + 4);
    r16[ax] += r16[bp];
    memorySet16(ds, r16[si] + 8, r16[bp]);
    memorySet16(ds, 0x795f, r16[ax]);
    r16[bx] = memoryGet16(ds, r16[si] + 2);
    memorySet16(ds, 0x795d, r16[bx]);
    yield* sub_17dfb();
    { pc = 0x172cd; break; }
  case 0x17674:
    push(r16[si]);
    r16[si] = 0x670b;
    yield* sub_16bc7();
    r16[si] = pop();
    memorySet16(ds, r16[si] + 22, 0x0001);
    memorySet16(ds, r16[si] + 8, 0xfb00);
    r16[ax] = 0x000c;
    yield* sub_1aecd();
    r16[ax] = memoryGet16(ds, r16[si] + 2);
    if (r16s[ax] < signed16(0x0080))
        { pc = 0x1769a; break; }
    memorySet16(ds, r16[si] + 16, 0xfffe);
    return;
  case 0x1769a:
    memorySet16(ds, r16[si] + 16, 0x0002);
    return;
  case 0x176a0:
    r16[dx] = memoryGet16(ds, r16[si] + 8);
    r16[dx] += 0x0080;
    memorySet16(ds, r16[si] + 8, r16[dx]);
    if (r16s[dx] < 0)
        { pc = 0x176b3; break; }
    r8[ch] = 0;
    { pc = 0x176b5; break; }
    // gap 1 bytes
  case 0x176b3:
    r8[ch] = 0xff;
  case 0x176b5:
    r16[ax] = memoryGet16(ds, r16[si] + 4);
    r8[cl] = memoryGet(ds, r16[si] + 6);
    flags.carry = r8[cl] + r8[dl] >= 0x100;
    r8[cl] += r8[dl];
    temp_cf = flags.carry;
    temp_cf = (r8[al] + r8[dh]) + flags.carry >= 0x100;
    r8[al] += (r8[dh] + flags.carry);
    flags.carry = temp_cf;
    r8[ah] += (r8[ch] + flags.carry);
    if (r16s[ax] <= signed16(0x0110))
        { pc = 0x176ca; break; }
    yield* sub_16174();
    return;
  case 0x176ca:
    memorySet16(ds, r16[si] + 4, r16[ax]);
    memorySet(ds, r16[si] + 6, r8[cl]);
    r16[ax] = memoryGet16(ds, 0x73ef);
    r16[ax] += 0x0006;
    r16[ax] += memoryGet16(ds, r16[si] + 50);
    memorySet16(ds, r16[si] + 10, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si] + 16);
    r16[ax] += memoryGet16(ds, r16[si] + 2);
    memorySet16(ds, r16[si] + 2, r16[ax]);
    return;
  }
}
function* sub_17674() // 1040:7274
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[si]);
    r16[si] = 0x670b;
    yield* sub_16bc7();
    r16[si] = pop();
    memorySet16(ds, r16[si] + 22, 0x0001);
    memorySet16(ds, r16[si] + 8, 0xfb00);
    r16[ax] = 0x000c;
    yield* sub_1aecd();
    r16[ax] = memoryGet16(ds, r16[si] + 2);
    if (r16s[ax] < signed16(0x0080))
        { pc = 0x1769a; break; }
    memorySet16(ds, r16[si] + 16, 0xfffe);
    return;
  case 0x1769a:
    memorySet16(ds, r16[si] + 16, 0x0002);
    return;
  }
}
function* sub_176e6() // 1040:72e6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (r16s[bx] <= signed16(memoryGet16(ds, 0x0b1e)))
        { pc = 0x176f0; break; }
    r16[dx] = 0xfffe;
    return;
  case 0x176f0:
    r16[dx] = 0x0002;
    return;
  }
}
function* sub_176f4() // 1040:72f4 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (r16s[ax] < signed16(memoryGet16(ds, 0x0b20)))
        { pc = 0x176fe; break; }
    if (r16[ax] == memoryGet16(ds, 0x0b20))
        { pc = 0x17700; break; }
    flags.carry = 1;
    return;
  case 0x176fe:
    flags.carry = 0;
    return;
  case 0x17700:
    flags.carry = 0;
    return;
  }
}
function* sub_17702() // 1040:7302
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x6e20) != 0x0001)
        { pc = 0x1770e; break; }
    flags.carry = 0;
    r16[bp] = 0x0000;
    return;
  case 0x1770e:
    if (r16s[ax] < r16s[bp])
        { pc = 0x17719; break; }
    if (r16[ax] == r16[bp])
        { pc = 0x1771e; break; }
    r16[bp] = 0xfffe;
    flags.carry = 1;
    return;
  case 0x17719:
    r16[bp] = 0x0002;
    flags.carry = 0;
    return;
  case 0x1771e:
    r16[bp] = 0x0000;
    flags.carry = 0;
    return;
  }
}
function* sub_17723() // 1040:7323
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, r16[si] + 42) == 0x0001)
        { pc = 0x17756; break; }
    if (memoryGet16(ds, r16[si] + 38) == 0x0001)
        { pc = 0x17770; break; }
    if (memoryGet16(ds, r16[si] + 40) == 0x0001)
        { pc = 0x1778b; break; }
    if (memoryGet16(ds, r16[si] + 34) != 0x0001)
        { pc = 0x177a6; break; }
    r16[ax] = memoryGet16(ds, r16[si] + 16);
    if (r16s[ax] < 0)
        { pc = 0x17748; break; }
    r16[ax] = 0x0000;
    { pc = 0x1774b; break; }
    // gap 1 bytes
  case 0x17748:
    r16[ax] = 0x0003;
  case 0x1774b:
    r16[ax] += memoryGet16(ds, 0x73e7);
    r16[ax] += memoryGet16(ds, r16[si] + 50);
    memorySet16(ds, r16[si] + 10, r16[ax]);
    return;
  case 0x17756:
    if (memoryGet16(ds, r16[si] + 42) != 0x0001)
        { pc = 0x17770; break; }
    r16[ax] = 0x0008;
    if (!memoryGet16(ds, r16[si] + 8))
        { pc = 0x17769; break; }
    r16[ax] += memoryGet16(ds, 0x73ed);
  case 0x17769:
    r16[ax] += memoryGet16(ds, r16[si] + 50);
    memorySet16(ds, r16[si] + 10, r16[ax]);
    return;
  case 0x17770:
    r16[ax] = memoryGet16(ds, r16[si] + 16);
    if (r16s[ax] < 0)
        { pc = 0x1777d; break; }
    r16[ax] = 0x0000;
    { pc = 0x17780; break; }
    // gap 1 bytes
  case 0x1777d:
    r16[ax] = 0x0003;
  case 0x17780:
    r16[ax] += memoryGet16(ds, 0x73e9);
    r16[ax] += memoryGet16(ds, r16[si] + 50);
    memorySet16(ds, r16[si] + 10, r16[ax]);
    return;
  case 0x1778b:
    r16[ax] = memoryGet16(ds, r16[si] + 16);
    if (r16s[ax] < 0)
        { pc = 0x17798; break; }
    r16[ax] = 0x0000;
    { pc = 0x1779b; break; }
    // gap 1 bytes
  case 0x17798:
    r16[ax] = 0x0003;
  case 0x1779b:
    r16[ax] += memoryGet16(ds, 0x73eb);
    r16[ax] += memoryGet16(ds, r16[si] + 50);
    memorySet16(ds, r16[si] + 10, r16[ax]);
    return;
  case 0x177a6:
    return;
  }
}
function* sub_177fb() // 1040:73fb
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = memoryGet16(ds, 0x73f1);
  case 0x177fe:
    r16[bx] = 0x73a7;
    r16[bx] += r16[ax];
    r16[dx] = memoryGet16(ds, r16[bx]);
    if (r16[dx] != 0x00ff)
        { pc = 0x17810; break; }
    r16[ax] = 0x0000;
    { pc = 0x177fe; break; }
  case 0x17810:
    memorySet16(ds, 0x73e7, r16[dx]);
    r16[ax]++;
    r16[ax]++;
    memorySet16(ds, 0x73f1, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x73f3);
  case 0x1781c:
    r16[bx] = 0x73b5;
    r16[bx] += r16[ax];
    r16[dx] = memoryGet16(ds, r16[bx]);
    if (r16[dx] != 0x00ff)
        { pc = 0x1782e; break; }
    r16[ax] = 0x0000;
    { pc = 0x1781c; break; }
  case 0x1782e:
    memorySet16(ds, 0x73e9, r16[dx]);
    r16[ax]++;
    r16[ax]++;
    memorySet16(ds, 0x73f3, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x73f5);
  case 0x1783a:
    r16[bx] = 0x73cf;
    r16[bx] += r16[ax];
    r16[dx] = memoryGet16(ds, r16[bx]);
    if (r16[dx] != 0x00ff)
        { pc = 0x1784c; break; }
    r16[ax] = 0x0000;
    { pc = 0x1783a; break; }
  case 0x1784c:
    memorySet16(ds, 0x73eb, r16[dx]);
    r16[ax]++;
    r16[ax]++;
    memorySet16(ds, 0x73f5, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x73f7);
  case 0x17858:
    r16[bx] = 0x73d7;
    r16[bx] += r16[ax];
    r16[dx] = memoryGet16(ds, r16[bx]);
    if (r16[dx] != 0x00ff)
        { pc = 0x1786a; break; }
    r16[ax] = 0x0000;
    { pc = 0x17858; break; }
  case 0x1786a:
    memorySet16(ds, 0x73ed, r16[dx]);
    r16[ax]++;
    r16[ax]++;
    memorySet16(ds, 0x73f7, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x73f9);
  case 0x17876:
    r16[bx] = 0x73e1;
    r16[bx] += r16[ax];
    r16[dx] = memoryGet16(ds, r16[bx]);
    if (r16[dx] != 0x00ff)
        { pc = 0x17888; break; }
    r16[ax] = 0x0000;
    { pc = 0x17876; break; }
  case 0x17888:
    memorySet16(ds, 0x73ef, r16[dx]);
    r16[ax]++;
    r16[ax]++;
    memorySet16(ds, 0x73f9, r16[ax]);
    return;
  }
}
function* sub_17896() // 1040:7496
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx] = memoryGet16(ds, r16[si] + 16);
    r8[al] = memoryGet(ds, r16[bx]);
    if (r8[al])
        { pc = 0x178a5; break; }
    r16[bx]++;
    r16[bx] = memoryGet16(ds, r16[bx]);
    memorySet16(ds, r16[si] + 16, r16[bx]);
  case 0x178a5:
    r16[bx]++;
    r8[al] = memoryGet(ds, r16[bx]);
    r8[al] = sar8(r8[al], 0x01);
    r8[al] = sar8(r8[al], 0x01);
    r8[al] = sar8(r8[al], 0x01);
    r8[al] = sar8(r8[al], 0x01);
    if (r8[al] != 0x07)
        { pc = 0x178b6; break; }
    r8[al]++;
  case 0x178b6:
    cbw();
    memorySet16(ds, 0x7492, r16[ax]);
    r8[al] = memoryGet(ds, r16[bx]);
    r8[al] &= 0x0f;
    if (!(r8[al] & 0x08))
        { pc = 0x178c4; break; }
    r8[al] |= 0xf0;
  case 0x178c4:
    if (r8[al] != 0x07)
        { pc = 0x178ca; break; }
    r8[al]++;
  case 0x178ca:
    cbw();
    memorySet16(ds, 0x7494, r16[ax]);
    r16[bx]--;
    r8[al] = memoryGet(ds, r16[bx]);
    cbw();
    memorySet16(ds, r16[si] + 18, memoryGet16(ds, r16[si] + 18) + 1);
    if (r16[ax] == memoryGet16(ds, r16[si] + 18))
        { pc = 0x178dc; break; }
    if (r16[ax] >= memoryGet16(ds, r16[si] + 18))
        { pc = 0x178e6; break; }
  case 0x178dc:
    memorySet16(ds, r16[si] + 18, 0x0000);
    r16[bx]++;
    r16[bx]++;
    memorySet16(ds, r16[si] + 16, r16[bx]);
  case 0x178e6:
    r16[ax] = memoryGet16(ds, 0x7492);
    r16[dx] = memoryGet16(ds, 0x7494);
    return;
  }
}
function* sub_17a31() // 1040:7631
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memorySet16(ds, 0x7629, 0x0014);
    r16[di] = 0x0c28;
    r16[si] = 0x74ee;
    r16[cx] = 0x0005;
  case 0x17a40:
    memorySet16(ds, r16[di], 0x0001);
    r16[ax] = lodsw_MemFwdDSSI();
    memorySet16(ds, r16[di] + 2, r16[ax]);
    r16[ax] = lodsw_MemFwdDSSI();
    memorySet16(ds, r16[di] + 4, r16[ax]);
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 14, r16[ax]);
    memorySet16(ds, r16[di] + 12, r16[ax]);
    r16[ax] = lodsw_MemFwdDSSI();
    memorySet16(ds, r16[di] + 22, r16[ax]);
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 24, r16[ax]);
    push(r16[si]);
    push(r16[di]);
    push(r16[cx]);
    r16[si] = r16[di];
    yield* sub_1718e();
    r16[cx] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 24, r16[ax]);
    r16[ax] = lodsw_MemFwdDSSI();
    memorySet16(ds, r16[di] + 16, r16[ax]);
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 18, r16[ax]);
    memorySet16(ds, r16[di] + 20, r16[ax]);
    r16[di] += 0x0034;
    if (--r16[cx])
        { pc = 0x17a40; break; }
    memorySet16(ds, 0x0d2c, r16[ax]);
    memorySet16(ds, 0x762b, r16[ax]);
    memorySet16(ds, 0x762f, 0x0001);
    return;
  }
}
function* sub_17a8b() // 1040:768b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x762d) != 0x0001)
        { pc = 0x17a9c; break; }
    if (memoryGet16(ds, 0x762f) == 0x0001)
        { pc = 0x17a9d; break; }
  case 0x17a9c:
    return;
  case 0x17a9d:
    r16[si] = 0x0c28;
    yield* sub_17896();
    r16[cx] = 0x0005;
  case 0x17aa6:
    push(r16[cx]);
    memorySet16(ds, r16[si] + 2, memoryGet16(ds, r16[si] + 2) + r16[ax]);
    memorySet16(ds, r16[si] + 4, memoryGet16(ds, r16[si] + 4) + r16[dx]);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_1718e();
    r16[dx] = pop();
    r16[ax] = pop();
    r16[si] += 0x0034;
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x17aa6; break; }
    r8[dh] = memoryGet(ds, 0x0c2a);
    r16[bx] = memoryGet16(ds, 0x0c2c);
    r8[dl] = 0x1c;
    r8[ah] = 0x40;
    yield* sub_16407();
    if (!flags.carry)
        { pc = 0x17ad1; break; }
    yield* sub_168a8();
    { pc = 0x17aeb; break; }
    // gap 1 bytes
  case 0x17ad1:
    r8[dh] = memoryGet(ds, 0x0c2a);
    r8[dh] += 0xec;
    r16[bx] = memoryGet16(ds, 0x0c2c);
    r16[bx] += 0x0018;
    r8[dl] = 0x14;
    r8[ah] = 0x20;
    yield* sub_16407();
    if (!flags.carry)
        { pc = 0x17aeb; break; }
    yield* sub_168a8();
  case 0x17aeb:
    r8[dh] = memoryGet(ds, 0x0c2a);
    r16[bx] = memoryGet16(ds, 0x0c2c);
    r8[dl] = 0x1c;
    r8[ah] = 0x40;
    yield* sub_164a0();
    if (!flags.carry)
        { pc = 0x17b0d; break; }
    memorySet16(ds, 0x0b00, 0x0000);
    yield* sub_17d53();
    if (!flags.carry)
        { pc = 0x17b0a; break; }
    { pc = 0x17ba5; break; }
  case 0x17b0a:
    { pc = 0x17b2f; break; }
    // gap 1 bytes
  case 0x17b0d:
    r8[dh] = memoryGet(ds, 0x0c2a);
    r8[dh] += 0xec;
    r16[bx] = memoryGet16(ds, 0x0c2c);
    r16[bx] += 0x0018;
    r8[dl] = 0x14;
    r8[ah] = 0x20;
    yield* sub_164a0();
    if (!flags.carry)
        { pc = 0x17b2f; break; }
    memorySet16(ds, 0x0b00, 0x0000);
    yield* sub_17d53();
    if (flags.carry)
        { pc = 0x17ba5; break; }
  case 0x17b2f:
    r8[dh] = memoryGet(ds, 0x0c2a);
    r16[bx] = memoryGet16(ds, 0x0c2c);
    r8[dl] = 0x1c;
    r8[ah] = 0x40;
    r8[dh] -= 0x10;
    r16[bx] -= 0x000e;
    r8[dl] += 0x20;
    r8[ah] += 0x1d;
    if (memoryGet16(ds, 0x0b38) != 0x0002)
        { pc = 0x17b96; break; }
    if (signed16(memoryGet16(ds, 0x0b4a)) > signed16(0x0004))
        { pc = 0x17b96; break; }
    if (signed16(memoryGet16(ds, 0x0b4a)) <= signed16(0x0001))
        { pc = 0x17b96; break; }
    yield* sub_164e1();
    if (!flags.carry)
        { pc = 0x17b6e; break; }
    yield* sub_17d53();
    if (flags.carry)
        { pc = 0x17ba5; break; }
    yield* sub_17d53();
    if (flags.carry)
        { pc = 0x17ba5; break; }
    { pc = 0x17b96; break; }
    // gap 1 bytes
  case 0x17b6e:
    r8[dh] = memoryGet(ds, 0x0c2a);
    r8[dh] += 0xec;
    r16[bx] = memoryGet16(ds, 0x0c2c);
    r16[bx] += 0x0018;
    r8[dl] = 0x14;
    r8[ah] = 0x20;
    r8[dh] -= 0x10;
    r16[bx] -= 0x000e;
    r8[dl] += 0x20;
    r8[ah] += 0x1d;
    yield* sub_164e1();
    if (!flags.carry)
        { pc = 0x17b96; break; }
    yield* sub_17d53();
    if (flags.carry)
        { pc = 0x17ba5; break; }
  case 0x17b96:
    if (memoryGet16(ds, 0x0d2c) == 0x0001)
        { pc = 0x17ba1; break; }
    yield* sub_17c64();
    return;
  case 0x17ba1:
    yield* sub_17cf4();
    return;
  case 0x17ba5:
    memorySet16(ds, 0x762d, 0x0000);
    memorySet16(ds, 0x762f, 0x0000);
    memorySet(ds, 0x5b3e, 0x01);
    r16[cx] = 0x0005;
    r16[si] = 0x758b;
    r16[di] = 0x0c28;
  case 0x17bbf:
    memorySet16(ds, r16[di], 0x0011);
    memorySet16(ds, r16[di] + 50, 0x0060);
    memorySet16(ds, r16[di] + 28, 0x0000);
    memorySet16(ds, r16[di] + 24, 0x0000);
    r16[ax] = lodsw_MemFwdDSSI();
    memorySet16(ds, r16[di] + 22, r16[ax]);
    memorySet16(ds, r16[di] + 18, 0x0000);
    memorySet16(ds, r16[di] + 20, 0x0000);
    r16[ax] = lodsw_MemFwdDSSI();
    memorySet16(ds, r16[di] + 16, r16[ax]);
    r16[di] += 0x0034;
    if (--r16[cx])
        { pc = 0x17bbf; break; }
    r16[di] = 0x0b56;
    memorySet16(ds, r16[di], 0x0001);
    r16[ax] = memoryGet16(ds, 0x0c2a);
    memorySet16(ds, r16[di] + 2, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x0c2c);
    memorySet16(ds, r16[di] + 4, r16[ax]);
    memorySet16(ds, r16[di] + 50, 0x0034);
    memorySet16(ds, r16[di] + 22, 0x0001);
    memorySet16(ds, r16[di] + 24, 0x0000);
    memorySet16(ds, r16[di] + 6, 0x0000);
    memorySet16(ds, r16[di] + 8, 0xfb00);
    memorySet16(ds, r16[di] + 16, 0xfffe);
    memorySet16(ds, r16[di] + 28, 0x0000);
    memorySet16(ds, 0x0d2c, 0x0000);
    if (memoryGet16(ds, 0x8bee) != 0x0001)
        { pc = 0x17c63; break; }
    r16[cx] = memoryGet16(ds, 0x6610);
    if (!r16[cx])
        { pc = 0x17c3e; break; }
  case 0x17c34:
    r16[si] = 0x6729;
    push(r16[cx]);
    yield* sub_16bc7();
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x17c34; break; }
  case 0x17c3e:
    r16[cx] = memoryGet16(ds, 0x6612);
    if (!r16[cx])
        { pc = 0x17c50; break; }
  case 0x17c46:
    r16[si] = 0x672f;
    push(r16[cx]);
    yield* sub_16bc7();
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x17c46; break; }
  case 0x17c50:
    r16[cx] = memoryGet16(ds, 0x6614);
    r16[cx]++;
    if (!r16[cx])
        { pc = 0x17c63; break; }
  case 0x17c59:
    r16[si] = 0x6735;
    push(r16[cx]);
    yield* sub_16bc7();
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x17c59; break; }
  case 0x17c63:
    return;
  }
}
function* sub_17c64() // 1040:7864
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (!(memoryGet16(ds, 0x762b) & 0xffff))
        { pc = 0x17c71; break; }
    memorySet16(ds, 0x762b, memoryGet16(ds, 0x762b) - 1);
    return;
  case 0x17c71:
    r16[ax] = 0x000d;
    yield* sub_1aecd();
    memorySet16(ds, 0x762b, 0x0032);
    memorySet16(ds, 0x0d2c, 0x0001);
    memorySet16(ds, 0x0d36, 0x0055);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    r16[ax] += 0x000c;
    r16[bx] = memoryGet16(ds, 0x0b20);
    r16[bx] += 0x000a;
    r16[cx] = memoryGet16(ds, 0x0c2a);
    r16[cx] += 0xffe4;
    memorySet16(ds, 0x0d2e, r16[cx]);
    r16[dx] = memoryGet16(ds, 0x0c2c);
    r16[dx] += 0x002c;
    memorySet16(ds, 0x0d30, r16[dx]);
    r16[ax] -= r16[cx];
    r16[cx] = r16[ax];
    r16[bx] -= r16[dx];
    r16[dx] = r16[bx];
  case 0x17cb4:
    if (r16s[ax] > signed16(0x0004))
        { pc = 0x17ccb; break; }
    if (r16s[ax] < signed16(0xfffc))
        { pc = 0x17ccb; break; }
    if (r16s[bx] > signed16(0x0004))
        { pc = 0x17ccb; break; }
    if (r16s[bx] < signed16(0xfffc))
        { pc = 0x17ccb; break; }
    { pc = 0x17cec; break; }
    // gap 1 bytes
  case 0x17ccb:
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[bx] = sar16(r16[bx], 0x0001);
    if (r16[ax])
        { pc = 0x17cb4; break; }
    if (r16[bx])
        { pc = 0x17cb4; break; }
    r16[ax] = 0x0004;
    r16[bx] = r16[ax];
    if (r16s[cx] >= signed16(0x0000))
        { pc = 0x17ce5; break; }
    r16[ax] = -r16[ax];
  case 0x17ce5:
    stop("infinite loop");
    if (r16s[dx] >= signed16(0x0000))
        { pc = 0x17ce5; break; }
    r16[bx] = -r16[bx];
  case 0x17cec:
    memorySet16(ds, 0x0d3c, r16[ax]);
    memorySet16(ds, 0x0d34, r16[bx]);
    return;
  }
}
function* sub_17cf4() // 1040:78f4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memorySet16(ds, 0x762b, memoryGet16(ds, 0x762b) - 1);
    if (signed16(memoryGet16(ds, 0x762b)) >= 0)
        { pc = 0x17d00; break; }
    memorySet16(ds, 0x762b, 0x0000);
  case 0x17d00:
    r16[ax] = memoryGet16(ds, 0x0d2e);
    r16[ax] += memoryGet16(ds, 0x0d3c);
    memorySet16(ds, 0x0d2e, r16[ax]);
    r16[dx] = memoryGet16(ds, 0x0d30);
    r16[dx] += memoryGet16(ds, 0x0d34);
    memorySet16(ds, 0x0d30, r16[dx]);
    r16[ax] += 0x0004;
    if (r16s[ax] <= signed16(0x0004))
        { pc = 0x17d4c; break; }
    if (r16s[ax] >= signed16(0x00fc))
        { pc = 0x17d4c; break; }
    r16[dx] += 0x0004;
    memorySet16(ds, 0x795d, r16[ax]);
    memorySet16(ds, 0x795f, r16[dx]);
    yield* sub_18014();
    r8[ch] = memoryGet(ds, 0x7963);
    if (r8[ch] & 0x02)
        { pc = 0x17d4c; break; }
    r16[ax]--;
    r16[ax]--;
    r16[bx] = r16[dx];
    r8[dh] = r8[al];
    r8[dl] = 0x04;
    r8[ah] = 0x04;
    yield* sub_16407();
    if (!flags.carry)
        { pc = 0x17d52; break; }
    yield* sub_168a8();
  case 0x17d4c:
    memorySet16(ds, 0x0d2c, 0x0000);
  case 0x17d52:
    return;
  }
}
function* sub_17d53() // 1040:7953 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memorySet16(ds, 0x7629, memoryGet16(ds, 0x7629) - 1);
    if (!memoryGet16(ds, 0x7629))
        { pc = 0x17d5b; break; }
    flags.carry = 0;
    return;
  case 0x17d5b:
    flags.carry = 1;
    return;
  }
}
function* sub_17d70() // 1040:7970
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[si]);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    memorySet16(ds, 0x796c, 0x0005);
    memorySet16(ds, 0x796e, 0x0010);
    memorySet16(ds, 0x7964, 0x7fff);
    memorySet16(ds, 0x7e02, 0x0000);
    r16[cx] = 0x0003;
    r16[dx] = memoryGet16(ds, 0x795f);
    r16[dx] &= 0x0007;
    if (r16s[dx] >= signed16(0x0004))
        { pc = 0x17d9f; break; }
    r16[cx] = 0x0002;
  case 0x17d9f:
    memorySet(ds, 0x796a, 0x00);
    r16[bp] = 0x0004;
    yield* sub_17ff3();
    r16[dx] &= 0x0007;
    if (!r16[dx])
        { pc = 0x17dd7; break; }
    r16[ax] = 0;
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] = memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r16[si] += 0x001d;
    r8[bl] &= 0x02;
    if (!r8[bl])
        { pc = 0x17e2f; break; }
    memorySet16(ds, 0x7e02, 0x0001);
    { pc = 0x17e2f; break; }
    // gap 1 bytes
  case 0x17dd7:
    r16[ax] = 0;
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] = memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r16[si] += 0x001e;
    r8[bl] &= 0x02;
    if (r8[bl])
        { pc = 0x17df2; break; }
    { pc = 0x17e8a; break; }
  case 0x17df2:
    memorySet16(ds, 0x7e02, 0x0001);
    { pc = 0x17e8a; break; }
    // gap 52 bytes
  case 0x17e2f:
    r16[bx] = 0;
    r16[ax] = 0;
    { pc = 0x17e4e; break; }
    // gap 1 bytes
  case 0x17e36:
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bh] |= memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r16[si] += 0x001d;
  case 0x17e4e:
    if (--r16[cx])
        { pc = 0x17e36; break; }
    r8[bl] &= 0x22;
    r8[bh] &= 0x2a;
    memorySet(ds, 0x796a, r8[bl]);
    memorySet(ds, 0x796a, memoryGet(ds, 0x796a) | r8[bh]);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] = memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bh] = memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[bl] &= 0x27;
    r8[bh] &= 0x7f;
    memorySet(ds, 0x796a, memoryGet(ds, 0x796a) | r8[bl]);
    memorySet(ds, 0x796a, memoryGet(ds, 0x796a) | r8[bh]);
    r8[al] = memoryGet(ds, 0x796a);
    memorySet(ds, 0x7963, r8[al]);
    { pc = 0x17ec9; break; }
    // gap 1 bytes
  case 0x17e8a:
    r16[bx] = 0;
    r16[ax] = 0;
    { pc = 0x17ea2; break; }
    // gap 1 bytes
  case 0x17e91:
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r16[si] += 0x001e;
  case 0x17ea2:
    if (--r16[cx])
        { pc = 0x17e91; break; }
    r8[bl] &= 0x2a;
    memorySet(ds, 0x796a, r8[bl]);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] = memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[bl] &= 0x7f;
    memorySet(ds, 0x796a, memoryGet(ds, 0x796a) | r8[bl]);
    r8[al] = memoryGet(ds, 0x796a);
    memorySet(ds, 0x7963, r8[al]);
    { pc = 0x17ec9; break; }
    // gap 1 bytes
  case 0x17ec9:
    r16[ax] = memoryGet16(ds, 0x7961);
    if (r16s[ax] >= 0)
        { pc = 0x17ed8; break; }
    r8[al] = memoryGet(ds, 0x7963);
    r8[al] &= 0xfb;
    memorySet(ds, 0x7963, r8[al]);
  case 0x17ed8:
    if (memoryGet(ds, 0x796b) == 0x01)
        { pc = 0x17ee2; break; }
    { pc = 0x17fb9; break; }
  case 0x17ee2:
    r16[si] = 0x0c28;
  case 0x17ee5:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16[ax] != 0xffff)
        { pc = 0x17eef; break; }
    { pc = 0x17fb9; break; }
  case 0x17eef:
    if (r8[al])
        { pc = 0x17ef6; break; }
    { pc = 0x17fb3; break; }
  case 0x17ef6:
    if (r8[al] & 0x80)
        { pc = 0x17efd; break; }
    { pc = 0x17fb3; break; }
  case 0x17efd:
    if (!(r8[al] & 0x40))
        { pc = 0x17f68; break; }
    r8[cl] = memoryGet(ds, r16[si] + 2);
    r16[di] = memoryGet16(ds, r16[si] + 4);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[bl] = memoryGet(ds, r16[si] + 32);
    r8[ch] = memoryGet(ds, 0x795d);
    r8[ch] += 0x04;
    r16[bp] = memoryGet16(ds, 0x795f);
    r16[bp] += memoryGet16(ds, 0x796c);
    r8[dh] = 0x10;
    r8[bh] = memoryGet(ds, 0x796e);
    push(r16[si]);
    yield* sub_17fbf();
    r16[si] = pop();
    if (flags.carry)
        { pc = 0x17f2f; break; }
    { pc = 0x17fb3; break; }
  case 0x17f2f:
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x02);
    if (r16s[di] > signed16(memoryGet16(ds, 0x7964)))
        { pc = 0x17f65; break; }
    r16[bx] = memoryGet16(ds, 0x795f);
    r16[bx] += 0x0014;
    r16[ax] = 0;
    r8[al] = memoryGet(ds, 0x7962);
    cbw();
    r16[ax] += 0x0008;
    r16[ax] += r16[di];
    if (r16s[bx] > r16s[ax])
        { pc = 0x17f65; break; }
    memorySet16(ds, 0x7964, r16[di]);
    memorySet16(ds, 0x7966, 0x0000);
    memorySet16(ds, 0x7968, 0x0000);
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x40);
  case 0x17f65:
    { pc = 0x17fb3; break; }
    // gap 1 bytes
  case 0x17f68:
    r16[ax] = memoryGet16(ds, 0x7961);
    if (r16s[ax] < 0)
        { pc = 0x17fb3; break; }
    r8[cl] = memoryGet(ds, r16[si] + 2);
    r16[di] = memoryGet16(ds, r16[si] + 4);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[bl] = memoryGet(ds, 0x7962);
    r8[bl] += 0x08;
    r8[ch] = memoryGet(ds, 0x795d);
    r8[ch] += 0x04;
    r16[bp] = memoryGet16(ds, 0x795f);
    r16[bp] += 0x0014;
    r8[dh] = 0x10;
    r8[bh] = 0x01;
    push(r16[si]);
    yield* sub_17fbf();
    r16[si] = pop();
    if (!flags.carry)
        { pc = 0x17fb3; break; }
    if (r16s[di] > signed16(memoryGet16(ds, 0x7964)))
        { pc = 0x17fb3; break; }
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x40);
    memorySet16(ds, 0x7964, r16[di]);
    r16[ax] = memoryGet16(ds, r16[si] + 46);
    memorySet16(ds, 0x7966, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si] + 48);
    memorySet16(ds, 0x7968, r16[ax]);
  case 0x17fb3:
    r16[si] += 0x0034;
    { pc = 0x17ee5; break; }
  case 0x17fb9:
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[si] = pop();
    return;
  }
}
function* sub_17dfb() // 1040:79fb
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[si]);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    memorySet16(ds, 0x796c, 0x0000);
    memorySet16(ds, 0x796e, 0x0015);
    memorySet16(ds, 0x7964, 0x7fff);
    r16[cx] = 0x0004;
    r16[dx] = memoryGet16(ds, 0x795f);
    r16[dx] &= 0x0007;
    if (r16s[dx] >= signed16(0x0004))
        { pc = 0x17e24; break; }
    r16[cx] = 0x0003;
  case 0x17e24:
    r16[bp] = 0x0004;
    yield* sub_17ff3();
    r16[dx] &= 0x0007;
    if (!r16[dx])
        { pc = 0x17e8a; break; }
    r16[bx] = 0;
    r16[ax] = 0;
    { pc = 0x17e4e; break; }
    // gap 1 bytes
  case 0x17e36:
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bh] |= memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r16[si] += 0x001d;
  case 0x17e4e:
    if (--r16[cx])
        { pc = 0x17e36; break; }
    r8[bl] &= 0x22;
    r8[bh] &= 0x2a;
    memorySet(ds, 0x796a, r8[bl]);
    memorySet(ds, 0x796a, memoryGet(ds, 0x796a) | r8[bh]);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] = memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bh] = memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[bl] &= 0x27;
    r8[bh] &= 0x7f;
    memorySet(ds, 0x796a, memoryGet(ds, 0x796a) | r8[bl]);
    memorySet(ds, 0x796a, memoryGet(ds, 0x796a) | r8[bh]);
    r8[al] = memoryGet(ds, 0x796a);
    memorySet(ds, 0x7963, r8[al]);
    { pc = 0x17ec9; break; }
    // gap 1 bytes
  case 0x17e8a:
    r16[bx] = 0;
    r16[ax] = 0;
    { pc = 0x17ea2; break; }
    // gap 1 bytes
  case 0x17e91:
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r16[si] += 0x001e;
  case 0x17ea2:
    if (--r16[cx])
        { pc = 0x17e91; break; }
    r8[bl] &= 0x2a;
    memorySet(ds, 0x796a, r8[bl]);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] = memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[bl] &= 0x7f;
    memorySet(ds, 0x796a, memoryGet(ds, 0x796a) | r8[bl]);
    r8[al] = memoryGet(ds, 0x796a);
    memorySet(ds, 0x7963, r8[al]);
    { pc = 0x17ec9; break; }
    // gap 1 bytes
  case 0x17ec9:
    r16[ax] = memoryGet16(ds, 0x7961);
    if (r16s[ax] >= 0)
        { pc = 0x17ed8; break; }
    r8[al] = memoryGet(ds, 0x7963);
    r8[al] &= 0xfb;
    memorySet(ds, 0x7963, r8[al]);
  case 0x17ed8:
    if (memoryGet(ds, 0x796b) == 0x01)
        { pc = 0x17ee2; break; }
    { pc = 0x17fb9; break; }
  case 0x17ee2:
    r16[si] = 0x0c28;
  case 0x17ee5:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16[ax] != 0xffff)
        { pc = 0x17eef; break; }
    { pc = 0x17fb9; break; }
  case 0x17eef:
    if (r8[al])
        { pc = 0x17ef6; break; }
    { pc = 0x17fb3; break; }
  case 0x17ef6:
    if (r8[al] & 0x80)
        { pc = 0x17efd; break; }
    { pc = 0x17fb3; break; }
  case 0x17efd:
    if (!(r8[al] & 0x40))
        { pc = 0x17f68; break; }
    r8[cl] = memoryGet(ds, r16[si] + 2);
    r16[di] = memoryGet16(ds, r16[si] + 4);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[bl] = memoryGet(ds, r16[si] + 32);
    r8[ch] = memoryGet(ds, 0x795d);
    r8[ch] += 0x04;
    r16[bp] = memoryGet16(ds, 0x795f);
    r16[bp] += memoryGet16(ds, 0x796c);
    r8[dh] = 0x10;
    r8[bh] = memoryGet(ds, 0x796e);
    push(r16[si]);
    yield* sub_17fbf();
    r16[si] = pop();
    if (flags.carry)
        { pc = 0x17f2f; break; }
    { pc = 0x17fb3; break; }
  case 0x17f2f:
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x02);
    if (r16s[di] > signed16(memoryGet16(ds, 0x7964)))
        { pc = 0x17f65; break; }
    r16[bx] = memoryGet16(ds, 0x795f);
    r16[bx] += 0x0014;
    r16[ax] = 0;
    r8[al] = memoryGet(ds, 0x7962);
    cbw();
    r16[ax] += 0x0008;
    r16[ax] += r16[di];
    if (r16s[bx] > r16s[ax])
        { pc = 0x17f65; break; }
    memorySet16(ds, 0x7964, r16[di]);
    memorySet16(ds, 0x7966, 0x0000);
    memorySet16(ds, 0x7968, 0x0000);
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x40);
  case 0x17f65:
    { pc = 0x17fb3; break; }
    // gap 1 bytes
  case 0x17f68:
    r16[ax] = memoryGet16(ds, 0x7961);
    if (r16s[ax] < 0)
        { pc = 0x17fb3; break; }
    r8[cl] = memoryGet(ds, r16[si] + 2);
    r16[di] = memoryGet16(ds, r16[si] + 4);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[bl] = memoryGet(ds, 0x7962);
    r8[bl] += 0x08;
    r8[ch] = memoryGet(ds, 0x795d);
    r8[ch] += 0x04;
    r16[bp] = memoryGet16(ds, 0x795f);
    r16[bp] += 0x0014;
    r8[dh] = 0x10;
    r8[bh] = 0x01;
    push(r16[si]);
    yield* sub_17fbf();
    r16[si] = pop();
    if (!flags.carry)
        { pc = 0x17fb3; break; }
    if (r16s[di] > signed16(memoryGet16(ds, 0x7964)))
        { pc = 0x17fb3; break; }
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x40);
    memorySet16(ds, 0x7964, r16[di]);
    r16[ax] = memoryGet16(ds, r16[si] + 46);
    memorySet16(ds, 0x7966, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si] + 48);
    memorySet16(ds, 0x7968, r16[ax]);
  case 0x17fb3:
    r16[si] += 0x0034;
    { pc = 0x17ee5; break; }
  case 0x17fb9:
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[si] = pop();
    return;
  }
}
function* sub_17fbf() // 1040:7bbf +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0;
    r8[al] = r8[ch];
    r16[si] = r16[ax];
    r8[al] = r8[dh];
    r16[si] += r16[ax];
    r8[al] = r8[cl];
    if (r16s[si] <= r16s[ax])
        { pc = 0x17ff1; break; }
    r16[si] = r16[ax];
    r8[al] = r8[dl];
    r16[si] += r16[ax];
    r8[al] = r8[ch];
    if (r16s[si] <= r16s[ax])
        { pc = 0x17ff1; break; }
    r16[cx] = 0;
    r8[cl] = r8[bh];
    r16[cx] += r16[bp];
    if (r16s[cx] <= r16s[di])
        { pc = 0x17ff1; break; }
    r16[ax] = 0;
    r8[al] = r8[bl];
    r16[ax] += r16[di];
    if (r16s[ax] <= r16s[bp])
        { pc = 0x17ff1; break; }
    flags.carry = 1;
    return;
  case 0x17ff1:
    flags.carry = 0;
    return;
  }
}
function* sub_17ff3() // 1040:7bf3
{
    r16[si] = 0x563c;
    r16[dx] = memoryGet16(ds, 0x795f);
    r16[dx] &= 0xfff8;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[si] += r16[dx];
    r16[dx] = memoryGet16(ds, 0x795d);
    r16[dx] += r16[bp];
    r16[bp] = r16[dx];
    r16[bp] >>= 1;
    r16[bp] >>= 1;
    r16[bp] >>= 1;
    r16[si] += r16[bp];
}
function* sub_18014() // 1040:7c14
{
    push(r16[ax]);
    push(r16[dx]);
    r16[bp] = 0;
    yield* sub_17ff3();
    r16[ax] = 0;
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[al] = memoryGet(ds, r16[di] + 21492);
    memorySet(ds, 0x7963, r8[al]);
    yield* sub_181c6();
    r16[dx] = pop();
    r16[ax] = pop();
}
function* sub_1802d() // 1040:7c2d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    r16[cx] = 0x0002;
    r16[ax] = memoryGet16(ds, 0x795f);
    r16[ax] &= 0x0007;
    if (!r16[ax])
        { pc = 0x1803f; break; }
    r16[cx] = 0x0003;
  case 0x1803f:
    r16[bp] = 0x0008;
    yield* sub_17ff3();
    r16[dx] &= 0x0007;
    if (!r16[dx])
        { pc = 0x18083; break; }
    r16[bx] = 0;
    r16[ax] = 0;
    { pc = 0x18062; break; }
    // gap 1 bytes
  case 0x18051:
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r16[si] += 0x001e;
  case 0x18062:
    if (--r16[cx])
        { pc = 0x18051; break; }
    r8[bl] &= 0x23;
    r8[bh] = r8[bl];
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] = memoryGet(ds, r16[di] + 21492);
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r8[bl] &= 0x27;
    r8[bh] |= r8[bl];
    memorySet(ds, 0x7963, r8[bh]);
    { pc = 0x180ae; break; }
    // gap 1 bytes
  case 0x18083:
    r16[bx] = 0;
    r16[ax] = 0;
    { pc = 0x18094; break; }
    // gap 1 bytes
  case 0x1808a:
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] |= memoryGet(ds, r16[di] + 21492);
    r16[si] += 0x001f;
  case 0x18094:
    if (--r16[cx])
        { pc = 0x1808a; break; }
    r8[bl] &= 0x2b;
    r8[bh] = r8[bl];
    r8[al] = lodsb_MemFwdDSSI();
    r16[di] = r16[ax];
    r8[bl] = memoryGet(ds, r16[di] + 21492);
    r8[bl] &= 0x27;
    r8[bh] |= r8[bl];
    memorySet(ds, 0x7963, r8[bh]);
    { pc = 0x180ae; break; }
    // gap 1 bytes
  case 0x180ae:
    r16[ax] = memoryGet16(ds, 0x7961);
    if (r16s[ax] >= 0)
        { pc = 0x180c0; break; }
    r8[bh] = memoryGet(ds, 0x7963);
    r8[bh] &= 0xfb;
    memorySet(ds, 0x7963, r8[bh]);
  case 0x180c0:
    if (memoryGet(ds, 0x796b) == 0x01)
        { pc = 0x180ca; break; }
    { pc = 0x1819f; break; }
  case 0x180ca:
    r16[si] = 0x0c28;
  case 0x180cd:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16[ax] != 0xffff)
        { pc = 0x180d7; break; }
    { pc = 0x1819f; break; }
  case 0x180d7:
    if (r8[al])
        { pc = 0x180de; break; }
    { pc = 0x18199; break; }
  case 0x180de:
    if (r8[al] & 0x80)
        { pc = 0x180e5; break; }
    { pc = 0x18199; break; }
  case 0x180e5:
    if (!(r8[al] & 0x40))
        { pc = 0x1814e; break; }
    r8[cl] = memoryGet(ds, r16[si] + 2);
    r16[di] = memoryGet16(ds, r16[si] + 4);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[bl] = memoryGet(ds, r16[si] + 32);
    r8[ch] = memoryGet(ds, 0x795d);
    r8[ch] += 0x08;
    r16[bp] = memoryGet16(ds, 0x795f);
    r16[bp] += memoryGet16(ds, 0x796c);
    r8[dh] = 0x08;
    r8[bh] = 0x10;
    push(r16[si]);
    yield* sub_17fbf();
    r16[si] = pop();
    if (flags.carry)
        { pc = 0x18115; break; }
    { pc = 0x18199; break; }
  case 0x18115:
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x02);
    if (r16s[di] > signed16(memoryGet16(ds, 0x7964)))
        { pc = 0x1814b; break; }
    r16[bx] = memoryGet16(ds, 0x795f);
    r16[bx] += 0x0010;
    r16[ax] = 0;
    r8[al] = memoryGet(ds, 0x7962);
    cbw();
    r16[ax] += 0x0008;
    r16[ax] += r16[di];
    if (r16s[bx] > r16s[ax])
        { pc = 0x1814b; break; }
    memorySet16(ds, 0x7964, r16[di]);
    memorySet16(ds, 0x7966, 0x0000);
    memorySet16(ds, 0x7968, 0x0000);
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x40);
  case 0x1814b:
    { pc = 0x18199; break; }
    // gap 1 bytes
  case 0x1814e:
    r16[ax] = memoryGet16(ds, 0x7961);
    if (r16s[ax] < 0)
        { pc = 0x18199; break; }
    r8[cl] = memoryGet(ds, r16[si] + 2);
    r16[di] = memoryGet16(ds, r16[si] + 4);
    r8[dl] = memoryGet(ds, r16[si] + 30);
    r8[bl] = memoryGet(ds, 0x7962);
    r8[bl] += 0x08;
    r8[ch] = memoryGet(ds, 0x795d);
    r8[ch] += 0x08;
    r16[bp] = memoryGet16(ds, 0x795f);
    r16[bp] += 0x000f;
    r8[dh] = 0x08;
    r8[bh] = 0x01;
    push(r16[si]);
    yield* sub_17fbf();
    r16[si] = pop();
    if (!flags.carry)
        { pc = 0x18199; break; }
    if (r16s[di] > signed16(memoryGet16(ds, 0x7964)))
        { pc = 0x18199; break; }
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x40);
    memorySet16(ds, 0x7964, r16[di]);
    r16[ax] = memoryGet16(ds, r16[si] + 46);
    memorySet16(ds, 0x7966, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si] + 48);
    memorySet16(ds, 0x7968, r16[ax]);
  case 0x18199:
    r16[si] += 0x0034;
    { pc = 0x180cd; break; }
  case 0x1819f:
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_181a4() // 1040:7da4 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[al] = r8[ch];
    r8[ah] = 0;
    r8[ch] = 0;
    if (r16s[ax] < r16s[cx])
        { pc = 0x181c4; break; }
    r8[dh] = 0;
    r16[cx] += r16[dx];
    if (r16s[ax] > r16s[cx])
        { pc = 0x181c4; break; }
    if (r16s[bp] < r16s[di])
        { pc = 0x181c4; break; }
    r8[bh] = 0;
    r16[di] += r16[bx];
    if (r16s[bp] > r16s[di])
        { pc = 0x181c4; break; }
    flags.carry = 1;
    return;
  case 0x181c4:
    flags.carry = 0;
    return;
  }
}
function* sub_181c6() // 1040:7dc6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] = 0x0c28;
  case 0x181c9:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16[ax] == 0xffff)
        { pc = 0x181fd; break; }
    if (!r8[al])
        { pc = 0x181f8; break; }
    if (!(r8[al] & 0x80))
        { pc = 0x181f8; break; }
    if (!(r8[al] & 0x40))
        { pc = 0x181f8; break; }
    r8[ch] = memoryGet(ds, 0x795d);
    r16[bp] = memoryGet16(ds, 0x795f);
    r8[cl] = memoryGet(ds, r16[si] + 2);
    r16[di] = memoryGet16(ds, r16[si] + 4);
    r8[dl] = 0x18;
    r8[bl] = 0x15;
    yield* sub_181a4();
    if (!flags.carry)
        { pc = 0x181f8; break; }
    memorySet(ds, 0x7963, memoryGet(ds, 0x7963) | 0x40);
  case 0x181f8:
    r16[si] += 0x0034;
    { pc = 0x181c9; break; }
  case 0x181fd:
    return;
  }
}
function* sub_18351() // 1040:7f51
{
  var pc = 0;
  var temp_cf;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x18351; break; }
  case 0x168a8:
    r16[ax] = 0x000b;
    yield* sub_1aecd();
    memorySet16(ds, 0x7e16, 0x0001);
    memorySet16(ds, 0x0b24, 0xfb00);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    if (r16s[ax] < signed16(0x0080))
        { pc = 0x168cb; break; }
    memorySet16(ds, 0x7e1c, 0xfffe);
    { pc = 0x168d1; break; }
    // gap 1 bytes
  case 0x168cb:
    memorySet16(ds, 0x7e1c, 0x0002);
  case 0x168d1:
    r16[ax] = memoryGet16(ds, 0x6614);
    if (!r16[ax])
        { pc = 0x168e3; break; }
    if (memoryGet(ds, 0x9804) == 0x01)
        { pc = 0x168e3; break; }
    memorySet16(ds, 0x6614, memoryGet16(ds, 0x6614) - 1);
  case 0x168e3:
    return;
    // gap 6765 bytes
  case 0x18351:
    if (memoryGet16(ds, 0x7e16) != 0x0001)
        { pc = 0x1835b; break; }
    { pc = 0x18f9a; break; }
  case 0x1835b:
    yield* sub_19c05();
    r16[ax] = memoryGet16(ds, 0x0b20);
    memorySet16(ds, 0x7dfe, r16[ax]);
    memorySet(ds, 0x90c2, 0x00);
    memorySet16(ds, 0x7e1a, 0x0000);
    yield* sub_1c4ca();
    if (!(memoryGet16(ds, 0x7ed2) & 0x00ff))
        { pc = 0x1837f; break; }
    memorySet16(ds, 0x7ed2, memoryGet16(ds, 0x7ed2) - 1);
  case 0x1837f:
    if (r8[al] == memoryGet(ds, 0x7eca))
        { pc = 0x18396; break; }
    memorySet(ds, 0x7eca, 0x00);
    memorySet16(ds, 0x7ecc, 0x0000);
    memorySet16(ds, 0x7ed2, 0x0000);
  case 0x18396:
    if (memoryGet16(ds, 0x7e00) != 0x0001)
        { pc = 0x183a0; break; }
    { pc = 0x18b03; break; }
  case 0x183a0:
    r16[ax] = memoryGet16(ds, 0x7e06);
    if (!r16[ax])
        { pc = 0x183aa; break; }
    { pc = 0x18987; break; }
  case 0x183aa:
    memorySet16(ds, 0x7e08, 0x0000);
    memorySet16(ds, 0x7e0a, 0x0000);
    memorySet16(ds, 0x7e0c, 0x0000);
    memorySet16(ds, 0x7e0e, 0x0000);
    memorySet16(ds, 0x7e10, 0x0000);
    memorySet16(ds, 0x7e14, 0x0000);
    memorySet(ds, 0x796b, 0x01);
    r16[dx] = memoryGet16(ds, 0x0b24);
    r16[dx] += 0x0080;
    if (r16s[dx] <= signed16(0x0800))
        { pc = 0x183e4; break; }
    r16[dx] = 0x0800;
  case 0x183e4:
    memorySet16(ds, 0x0b24, r16[dx]);
    memorySet16(ds, 0x7961, r16[dx]);
    if (r16s[dx] < 0)
        { pc = 0x183f5; break; }
    r8[ch] = 0;
    { pc = 0x183f7; break; }
    // gap 1 bytes
  case 0x183f5:
    r8[ch] = 0xff;
  case 0x183f7:
    r16[ax] = memoryGet16(ds, 0x0b20);
    r8[cl] = memoryGet(ds, 0x0b22);
    flags.carry = r8[cl] + r8[dl] >= 0x100;
    r8[cl] += r8[dl];
    temp_cf = flags.carry;
    temp_cf = (r8[al] + r8[dh]) + flags.carry >= 0x100;
    r8[al] += (r8[dh] + flags.carry);
    flags.carry = temp_cf;
    r8[ah] += (r8[ch] + flags.carry);
    memorySet16(ds, 0x795f, r16[ax]);
    r16[dx] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x795d, r16[dx]);
    memorySet(ds, 0x796b, 0x01);
    if (memoryGet16(ds, 0x7e04) != 0x0001)
        { pc = 0x18421; break; }
    yield* sub_17d70();
    { pc = 0x18424; break; }
    // gap 1 bytes
  case 0x18421:
    yield* sub_17dfb();
  case 0x18424:
    r8[ch] = memoryGet(ds, 0x7963);
    if (!(r8[ch] & 0x40))
        { pc = 0x18485; break; }
    r16[ax] = memoryGet16(ds, 0x7964);
    r8[cl] = 0;
    r16[ax] -= 0x0015;
    memorySet16(ds, 0x795f, r16[ax]);
    memorySet16(ds, 0x0b20, r16[ax]);
    memorySet(ds, 0x0b22, 0x00);
    memorySet16(ds, 0x7e08, 0x0001);
    push(r16[ax]);
    r16[ax] = memoryGet16(ds, 0x7966);
    memorySet16(ds, 0x7e1a, r16[ax]);
    r16[ax] = pop();
    memorySet(ds, 0x796b, 0x00);
    if (memoryGet16(ds, 0x7e04) != 0x0001)
        { pc = 0x18460; break; }
    yield* sub_17d70();
    { pc = 0x18463; break; }
    // gap 1 bytes
  case 0x18460:
    yield* sub_17dfb();
  case 0x18463:
    r8[ch] = memoryGet(ds, 0x7963);
    if (!(r8[ch] & 0x20))
        { pc = 0x1846f; break; }
    { pc = 0x168a8; break; }
  case 0x1846f:
    r8[ch] &= 0x06;
    if (!r8[ch])
        { pc = 0x1847b; break; }
    r8[ch] = memoryGet(ds, 0x7963);
    { pc = 0x184a3; break; }
    // gap 1 bytes
  case 0x1847b:
    r8[ch] = memoryGet(ds, 0x7963);
    r16[dx] = 0x0100;
    { pc = 0x1857c; break; }
  case 0x18485:
    if (!(r8[ch] & 0x20))
        { pc = 0x1848d; break; }
    { pc = 0x168a8; break; }
  case 0x1848d:
    if (r8[ch] & 0x04)
        { pc = 0x184da; break; }
    if (r8[ch] & 0x02)
        { pc = 0x1849a; break; }
    { pc = 0x186a8; break; }
  case 0x1849a:
    r16[bp] = memoryGet16(cs, 0x0b24);
    if (r16s[bp] >= 0)
        { pc = 0x184da; break; }
  case 0x184a3:
    if (memoryGet16(ds, 0x7e06) != 0x0001)
        { pc = 0x184c8; break; }
    r16[bp] = memoryGet16(cs, 0x0b1e);
    r16[bp] &= 0x001f;
    if (r16s[bp] >= signed16(0x000a))
        { pc = 0x184c8; break; }
    r16[bp] = memoryGet16(cs, 0x0b1e);
    r16[bp] &= 0x00f0;
    r16[bp] |= 0x0004;
    memorySet16(cs, 0x0b1e, r16[bp]);
  case 0x184c8:
    r16[ax] |= 0x0007;
    r16[ax]++;
    r8[cl] = 0;
    memorySet16(ds, 0x0b24, 0x0100);
    r16[dx] = 0x0100;
    { pc = 0x186a8; break; }
  case 0x184da:
    if (!(r8[ch] & 0x10))
        { pc = 0x18524; break; }
    if (memoryGet(ds, 0xb884) & 0x10)
        { pc = 0x18524; break; }
    if (memoryGet16(ds, 0x7e04) == 0x0001)
        { pc = 0x18524; break; }
    if (memoryGet16(ds, 0x7e06) != 0x0001)
        { pc = 0x184f8; break; }
    { pc = 0x186a8; break; }
  case 0x184f8:
    if (!(memoryGet(ds, 0xb884) & 0x04))
        { pc = 0x18524; break; }
    r16[bx] = memoryGet16(ds, 0x0b1e);
    r16[bx] &= 0x001f;
    if (r16s[bx] >= signed16(0x000a))
        { pc = 0x18524; break; }
    r16[bx] = memoryGet16(ds, 0x0b1e);
    r16[bx] &= 0x00f0;
    r16[bx] |= 0x0004;
    memorySet16(ds, 0x0b1e, r16[bx]);
    memorySet16(ds, 0x7e06, 0x0001);
    { pc = 0x186a8; break; }
  case 0x18524:
    memorySet16(ds, 0x7e06, 0x0000);
    memorySet16(ds, 0x7e08, 0x0001);
    r16[ax] += 0x000c;
    r16[ax] |= 0x0007;
    r16[ax] -= 0x0014;
    r8[cl] = 0;
    memorySet16(ds, 0x0b20, r16[ax]);
    memorySet(ds, 0x0b22, r8[cl]);
    r16[dx] = 0x0100;
    if (!(r8[ch] & 0x01))
        { pc = 0x1857c; break; }
    if (memoryGet16(ds, 0x8bec) != 0x0003)
        { pc = 0x1857c; break; }
    r16[dx] = memoryGet16(ds, 0x0b24);
    if (r16s[dx] < signed16(0x0200))
        { pc = 0x18570; break; }
    r16[dx] = -r16[dx];
    r16[dx] += 0x0060;
    memorySet16(ds, 0x0b24, r16[dx]);
    r16[dx] = 0xf781;
    r16[ax] = 0x0016;
    yield* sub_1aecd();
    { pc = 0x185ab; break; }
    // gap 1 bytes
  case 0x18570:
    memorySet16(ds, 0x0b24, 0x0100);
    r16[dx] = 0xfa00;
    { pc = 0x185ab; break; }
    // gap 1 bytes
  case 0x1857c:
    memorySet16(ds, 0x0b24, r16[dx]);
    r16[dx] = 0xfa00;
    if (!(r8[ch] & 0x01))
        { pc = 0x185ab; break; }
    if (memoryGet16(ds, 0x8bec) != 0x0001)
        { pc = 0x18595; break; }
    r16[dx] = 0xfe00;
    { pc = 0x185ab; break; }
    // gap 1 bytes
  case 0x18595:
    if (memoryGet16(ds, 0x8bec) != 0x0005)
        { pc = 0x185ab; break; }
    r16[ax] = 0x0017;
    yield* sub_1aecd();
    memorySet16(ds, 0x0b24, 0xf781);
    { pc = 0x186c1; break; }
  case 0x185ab:
    if (memoryGet16(ds, 0x7e04) != 0x0001)
        { pc = 0x185c5; break; }
    if (memoryGet16(ds, 0x7e02) != 0x0001)
        { pc = 0x185bc; break; }
    { pc = 0x186c1; break; }
  case 0x185bc:
    memorySet16(ds, 0x7e04, 0x0000);
    { pc = 0x185f2; break; }
    // gap 1 bytes
  case 0x185c5:
    if (memoryGet(ds, 0xb884) & 0x10)
        { pc = 0x18606; break; }
    if (!(memoryGet(ds, 0xb884) & 0x08))
        { pc = 0x185f2; break; }
    memorySet16(ds, 0x0b24, r16[dx]);
    if (!(r8[ch] & 0x10))
        { pc = 0x185e1; break; }
    { pc = 0x186c1; break; }
  case 0x185e1:
    if (r8[ch] & 0x08)
        { pc = 0x185e9; break; }
    { pc = 0x186c1; break; }
  case 0x185e9:
    memorySet16(ds, 0x7e06, 0x0001);
    { pc = 0x186c1; break; }
  case 0x185f2:
    if (memoryGet(ds, 0xb884) & 0x04)
        { pc = 0x185fd; break; }
    { pc = 0x186c1; break; }
  case 0x185fd:
    memorySet16(ds, 0x7e04, 0x0001);
    { pc = 0x186c1; break; }
  case 0x18606:
    if (!(memoryGet(ds, 0xb884) & 0x08))
        { pc = 0x18611; break; }
    { pc = 0x189c2; break; }
  case 0x18611:
    memorySet16(ds, 0x7e12, 0x0001);
    if (!(memoryGet(ds, 0xb884) & 0x04))
        { pc = 0x18622; break; }
    { pc = 0x189ff; break; }
  case 0x18622:
    push(r16[ax]);
    r8[al] = memoryGet(ds, 0xb884);
    if (r8[al] != memoryGet(ds, 0x7eca))
        { pc = 0x18630; break; }
    r16[ax] = pop();
    { pc = 0x189de; break; }
  case 0x18630:
    r16[ax] = pop();
    if (!(memoryGet(ds, 0xb884) & 0x02))
        { pc = 0x1866a; break; }
    memorySet16(ds, 0x0b36, 0x0001);
    r16[bx] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x7ece, r16[bx]);
    memorySet16(ds, 0x7ed0, r16[ax]);
    memorySet16(ds, 0x7ed0, memoryGet16(ds, 0x7ed0) + 0x0008);
    memorySet16(ds, 0x7ecc, 0x0001);
    memorySet16(ds, 0x7ed2, 0x000a);
    r8[al] = memoryGet(ds, 0xb884);
    memorySet(ds, 0x7eca, r8[al]);
    r16[ax] = 0x0022;
    yield* sub_1aecd();
    { pc = 0x189de; break; }
  case 0x1866a:
    if (!(memoryGet(ds, 0xb884) & 0x01))
        { pc = 0x186c1; break; }
    memorySet16(ds, 0x0b36, 0x0000);
    r16[bx] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x7ece, r16[bx]);
    memorySet16(ds, 0x7ece, memoryGet16(ds, 0x7ece) + 0x0018);
    memorySet16(ds, 0x7ed0, r16[ax]);
    memorySet16(ds, 0x7ed0, memoryGet16(ds, 0x7ed0) + 0x0008);
    memorySet16(ds, 0x7ecc, 0x0001);
    memorySet16(ds, 0x7ed2, 0x000a);
    r8[al] = memoryGet(ds, 0xb884);
    memorySet(ds, 0x7eca, r8[al]);
    r16[ax] = 0x0022;
    yield* sub_1aecd();
    { pc = 0x189de; break; }
  case 0x186a8:
    memorySet16(ds, 0x0b20, r16[ax]);
    memorySet(ds, 0x0b22, r8[cl]);
    r8[al] = memoryGet(ds, 0xb884);
    r8[al] &= 0x0c;
    if (!r8[al])
        { pc = 0x186c1; break; }
    if (!(r8[ch] & 0x08))
        { pc = 0x186c1; break; }
    memorySet16(ds, 0x7e06, 0x0001);
  case 0x186c1:
    if (memoryGet16(ds, 0x7e06) != 0x0001)
        { pc = 0x186e2; break; }
    if (r8[ch] & 0x08)
        { pc = 0x186e2; break; }
    memorySet16(ds, 0x7e06, 0x0000);
    r16[bp] = memoryGet16(cs, 0x0b24);
    if (r16s[bp] >= 0)
        { pc = 0x186e2; break; }
    memorySet16(ds, 0x0b24, 0xfe00);
  case 0x186e2:
    if (!(memoryGet(ds, 0xb884) & 0x02))
        { pc = 0x1871e; break; }
    memorySet16(ds, 0x0b36, 0x0001);
    r16[dx] = 0xfffe;
    if (r8[ch] & 0x01)
        { pc = 0x186fb; break; }
    { pc = 0x1878a; break; }
  case 0x186fb:
    if (memoryGet16(ds, 0x8bec) != 0x0004)
        { pc = 0x1870e; break; }
    r16[dx] = 0xffff;
    memorySet16(ds, 0x7e0c, 0x0001);
    { pc = 0x1878a; break; }
    // gap 1 bytes
  case 0x1870e:
    if (memoryGet16(ds, 0x8bec) != 0x0002)
        { pc = 0x1878a; break; }
    memorySet16(ds, 0x7e0e, 0x0001);
    { pc = 0x1878a; break; }
    // gap 1 bytes
  case 0x1871e:
    if (!(memoryGet(ds, 0xb884) & 0x01))
        { pc = 0x18757; break; }
    memorySet16(ds, 0x0b36, 0x0000);
    r16[dx] = 0x0002;
    if (!(r8[ch] & 0x01))
        { pc = 0x1878a; break; }
    if (memoryGet16(ds, 0x8bec) != 0x0004)
        { pc = 0x18747; break; }
    r16[dx] = 0x0001;
    memorySet16(ds, 0x7e0c, 0x0001);
    { pc = 0x1878a; break; }
    // gap 1 bytes
  case 0x18747:
    if (memoryGet16(ds, 0x8bec) != 0x0002)
        { pc = 0x1878a; break; }
    memorySet16(ds, 0x7e0e, 0x0001);
    { pc = 0x1878a; break; }
    // gap 1 bytes
  case 0x18757:
    r16[dx] = 0;
    if (r8[ch] & 0x01)
        { pc = 0x18767; break; }
    memorySet16(ds, 0x0b34, 0xffff);
    { pc = 0x1878a; break; }
    // gap 1 bytes
  case 0x18767:
    if (memoryGet16(ds, 0x8bec) == 0x0002)
        { pc = 0x18777; break; }
    memorySet16(ds, 0x0b34, 0xffff);
    { pc = 0x1878a; break; }
    // gap 1 bytes
  case 0x18777:
    memorySet16(ds, 0x7e0a, 0x0001);
    r16[dx] = 0x0002;
    if (!memoryGet16(ds, 0x0b36))
        { pc = 0x1878a; break; }
    r16[dx] = 0xfffe;
  case 0x1878a:
    r16[dx] += memoryGet16(ds, 0x7e1a);
    r16[bx] = memoryGet16(ds, 0x0b1e);
    r16[bx] += r16[dx];
    if (!r16[dx])
        { pc = 0x187b9; break; }
    if (r16s[dx] >= 0)
        { pc = 0x187aa; break; }
    if (r16s[bx] >= signed16(0x0000))
        { pc = 0x187b9; break; }
    r16[bx] = 0;
    memorySet(ds, 0x90c2, 0x01);
    { pc = 0x187b9; break; }
    // gap 1 bytes
  case 0x187aa:
    if (r16s[bx] < signed16(0x00e8))
        { pc = 0x187b9; break; }
    r16[bx] = 0x00e8;
    memorySet(ds, 0x90c2, 0x02);
  case 0x187b9:
    r16[ax] = memoryGet16(ds, 0x0b20);
    memorySet16(ds, 0x795f, r16[ax]);
    memorySet16(ds, 0x7961, 0xffff);
    memorySet16(ds, 0x795d, r16[bx]);
    memorySet(ds, 0x796b, 0x01);
    if (memoryGet16(ds, 0x7e04) != 0x0001)
        { pc = 0x187db; break; }
    yield* sub_17d70();
    { pc = 0x187de; break; }
    // gap 1 bytes
  case 0x187db:
    yield* sub_17dfb();
  case 0x187de:
    r8[ch] = memoryGet(ds, 0x7963);
    if (!(r8[ch] & 0x20))
        { pc = 0x187ea; break; }
    { pc = 0x168a8; break; }
  case 0x187ea:
    if (!(r8[ch] & 0x02))
        { pc = 0x18815; break; }
    if (r16s[dx] >= 0)
        { pc = 0x18804; break; }
    r16[bx] += 0x000c;
    r16[bx] &= 0x00f8;
    r16[bx] -= 0x0004;
    memorySet16(ds, 0x0b1e, r16[bx]);
    { pc = 0x1882b; break; }
    // gap 1 bytes
  case 0x18804:
    r16[bx] += 0x0003;
    r16[bx] &= 0x00f8;
    r16[bx] -= 0x0004;
    memorySet16(ds, 0x0b1e, r16[bx]);
    { pc = 0x1882b; break; }
    // gap 1 bytes
  case 0x18815:
    memorySet16(ds, 0x0b1e, r16[bx]);
    if (memoryGet16(ds, 0x7e06) != 0x0001)
        { pc = 0x1882b; break; }
    if (r8[ch] & 0x08)
        { pc = 0x1882b; break; }
    memorySet16(ds, 0x7e06, 0x0000);
  case 0x1882b:
    if (memoryGet16(ds, 0x7e00) != 0x0001)
        { pc = 0x1883e; break; }
    memorySet16(ds, 0x0b26, 0x000c);
    yield* sub_18c83();
    { pc = 0x18975; break; }
  case 0x1883e:
    if (memoryGet16(ds, 0x7e06) != 0x0001)
        { pc = 0x18865; break; }
    memorySet16(ds, 0x0b26, 0x001a);
    r16[bx] = memoryGet16(ds, 0x0b1e);
    r16[ax] = memoryGet16(ds, 0x0b20);
    r16[ax] ^= r16[bx];
    r16[ax] &= 0x0004;
    if (r16[ax])
        { pc = 0x1885c; break; }
    { pc = 0x18a8f; break; }
  case 0x1885c:
    memorySet16(ds, 0x0b26, 0x001b);
    { pc = 0x18a8f; break; }
  case 0x18865:
    if (memoryGet16(ds, 0x7e08) == 0x0001)
        { pc = 0x18875; break; }
    memorySet16(ds, 0x0b26, 0x0008);
    { pc = 0x18975; break; }
  case 0x18875:
    if (!(memoryGet16(ds, 0x7ed2) & 0x00ff))
        { pc = 0x18886; break; }
    memorySet16(ds, 0x0b26, 0x000a);
    { pc = 0x18975; break; }
  case 0x18886:
    if (memoryGet16(ds, 0x7e10) != 0x0001)
        { pc = 0x18896; break; }
    memorySet16(ds, 0x0b26, 0x0009);
    { pc = 0x18975; break; }
  case 0x18896:
    if (memoryGet16(ds, 0x7e14) != 0x0001)
        { pc = 0x188b6; break; }
    memorySet16(ds, 0x0b26, 0x0000);
    if (memoryGet16(ds, 0x0b52))
        { pc = 0x188ad; break; }
    { pc = 0x18975; break; }
  case 0x188ad:
    memorySet16(ds, 0x0b26, 0x000b);
    { pc = 0x18975; break; }
  case 0x188b6:
    if (memoryGet16(ds, 0x7e0a) != 0x0001)
        { pc = 0x188d6; break; }
    memorySet16(ds, 0x0b26, 0x0006);
    if (memoryGet16(ds, 0x7e04) != 0x0001)
        { pc = 0x188cd; break; }
    { pc = 0x18975; break; }
  case 0x188cd:
    memorySet16(ds, 0x0b26, 0x0000);
    { pc = 0x18975; break; }
  case 0x188d6:
    if (!(memoryGet(ds, 0x7eca) & 0xff))
        { pc = 0x188e6; break; }
    memorySet16(ds, 0x0b26, 0x0000);
    { pc = 0x18975; break; }
  case 0x188e6:
    r16[si] = 0x7e2c;
    memorySet16(ds, 0x0b26, 0x0006);
    if (memoryGet16(ds, 0x7e04) == 0x0001)
        { pc = 0x188ff; break; }
    r16[si] = 0x7e22;
    memorySet16(ds, 0x0b26, 0x0000);
  case 0x188ff:
    if (memoryGet16(ds, 0x0b34) != 0xffff)
        { pc = 0x1890f; break; }
    memorySet16(ds, 0x0b34, 0x0000);
    { pc = 0x18975; break; }
    // gap 1 bytes
  case 0x1890f:
    r16[ax] = 0x0001;
    if (memoryGet16(ds, 0x7e0c) == 0x0001)
        { pc = 0x18926; break; }
    r16[ax] = 0x0004;
    if (memoryGet16(ds, 0x7e0e) == 0x0001)
        { pc = 0x18926; break; }
    r16[ax] = 0x0002;
  case 0x18926:
    r16[ax] += memoryGet16(ds, 0x0b34);
    if (r16s[ax] < signed16(0x0028))
        { pc = 0x18932; break; }
    r16[ax] -= 0x0028;
  case 0x18932:
    memorySet16(ds, 0x0b34, r16[ax]);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    if (memoryGet16(ds, 0x7e04) != 0x0001)
        { pc = 0x18950; break; }
    if (!(r16[ax] & 0x0001))
        { pc = 0x1896c; break; }
    push(r16[ax]);
    r16[ax] = 0x0026;
    yield* sub_1aecd();
    r16[ax] = pop();
    { pc = 0x1896c; break; }
    // gap 1 bytes
  case 0x18950:
    if (r16[ax] == 0x0002)
        { pc = 0x18964; break; }
    if (r16[ax] == 0x0005)
        { pc = 0x18964; break; }
    if (r16[ax] == 0x0007)
        { pc = 0x18964; break; }
    if (r16[ax])
        { pc = 0x1896c; break; }
  case 0x18964:
    push(r16[ax]);
    r16[ax] = 0x0025;
    yield* sub_1aecd();
    r16[ax] = pop();
  case 0x1896c:
    r16[si] += r16[ax];
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[si]);
    memorySet16(ds, 0x0b26, r16[ax]);
  case 0x18975:
    if (memoryGet16(ds, 0x0b36))
        { pc = 0x1897f; break; }
    { pc = 0x18a8f; break; }
  case 0x1897f:
    memorySet16(ds, 0x0b26, memoryGet16(ds, 0x0b26) + 0x000d);
    { pc = 0x18a8f; break; }
  case 0x18987:
    r16[ax] = memoryGet16(ds, 0x0b20);
    r8[cl] = 0;
    r16[dx] = 0;
    if (!(memoryGet(ds, 0xb884) & 0x08))
        { pc = 0x1899c; break; }
    r16[dx] = 0xfffe;
    { pc = 0x189a7; break; }
    // gap 1 bytes
  case 0x1899c:
    if (!(memoryGet(ds, 0xb884) & 0x04))
        { pc = 0x189a7; break; }
    r16[dx] = 0x0002;
  case 0x189a7:
    memorySet16(ds, 0x0b24, r16[dx]);
    r16[ax] += r16[dx];
    memorySet16(ds, 0x7961, r16[dx]);
    memorySet16(ds, 0x795f, r16[ax]);
    r16[bx] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x795d, r16[bx]);
    yield* sub_17dfb();
    { pc = 0x18424; break; }
  case 0x189c2:
    memorySet16(ds, 0x7e10, 0x0001);
    if (!memoryGet16(ds, 0x7e12))
        { pc = 0x189de; break; }
    if (!(memoryGet16(ds, 0x6610) & 0x00ff))
        { pc = 0x189de; break; }
    if (memoryGet16(ds, 0x0b00) != 0x0001)
        { pc = 0x189f9; break; }
  case 0x189de:
    if (r8[ch] & 0x01)
        { pc = 0x189e6; break; }
    { pc = 0x1882b; break; }
  case 0x189e6:
    if (memoryGet16(ds, 0x8bec) == 0x0002)
        { pc = 0x189f0; break; }
    { pc = 0x1882b; break; }
  case 0x189f0:
    memorySet16(ds, 0x7e0a, 0x0001);
    { pc = 0x186c1; break; }
  case 0x189f9:
    yield* sub_18a9a();
    { pc = 0x1882b; break; }
  case 0x189ff:
    memorySet16(ds, 0x7e14, 0x0001);
    if (signed16(memoryGet16(ds, 0x0b38)) >= signed16(0x0001))
        { pc = 0x189de; break; }
    r16[ax] = memoryGet16(ds, 0x6612);
    if (r16[ax])
        { pc = 0x18a16; break; }
    { pc = 0x1882b; break; }
  case 0x18a16:
    if (memoryGet(ds, 0x9804) == 0x01)
        { pc = 0x18a21; break; }
    memorySet16(ds, 0x6612, memoryGet16(ds, 0x6612) - 1);
  case 0x18a21:
    memorySet16(ds, 0x0b38, 0x0001);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x0b3a, r16[ax]);
    memorySet(ds, 0x0b3f, 0x00);
    r16[ax] = memoryGet16(ds, 0x0b20);
    r16[ax] += 0x0005;
    memorySet16(ds, 0x0b3c, r16[ax]);
    memorySet(ds, 0x0b3e, 0x00);
    memorySet16(ds, 0x0b4a, 0x0000);
    memorySet16(ds, 0x0b50, 0x0000);
    memorySet16(ds, 0x0b52, 0x0000);
    memorySet16(ds, 0x0b40, 0x0100);
    memorySet16(ds, 0x0b4e, 0x7e36);
    if (!(memoryGet(ds, 0xb884) & 0x02))
        { pc = 0x18a75; break; }
    memorySet16(ds, 0x0b36, 0x0001);
    memorySet16(ds, 0x0b52, 0xfe00);
    { pc = 0x1882b; break; }
  case 0x18a75:
    if (memoryGet(ds, 0xb884) & 0x01)
        { pc = 0x18a80; break; }
    { pc = 0x1882b; break; }
  case 0x18a80:
    memorySet16(ds, 0x0b36, 0x0000);
    memorySet16(ds, 0x0b52, 0x0200);
    { pc = 0x1882b; break; }
  case 0x18a8f:
    r16[ax] = memoryGet16(ds, 0x0b20);
    r16[ax] -= memoryGet16(ds, 0x7dfe);
    memorySet16(ds, 0x6c43, r16[ax]);
    return;
    // gap 105 bytes
  case 0x18b03:
    memorySet16(ds, 0x7e08, 0x0000);
    memorySet16(ds, 0x7e0a, 0x0000);
    memorySet16(ds, 0x7e0c, 0x0000);
    memorySet16(ds, 0x7e0e, 0x0000);
    memorySet16(ds, 0x7e10, 0x0000);
    memorySet16(ds, 0x7e14, 0x0000);
    memorySet16(ds, 0x7e06, 0x0000);
    r16[dx] = memoryGet16(ds, 0x0b24);
    r16[dx] += 0x0040;
    if (r16s[dx] <= signed16(0x0400))
        { pc = 0x18b40; break; }
    r16[dx] = 0x0400;
  case 0x18b40:
    if (!(memoryGet(ds, 0xb884) & 0x08))
        { pc = 0x18b5e; break; }
    r16[dx] += 0xff40;
    if (r16s[dx] >= signed16(0xfc00))
        { pc = 0x18b79; break; }
    r16[dx] = 0xfc00;
    { pc = 0x18b79; break; }
    // gap 1 bytes
  case 0x18b5e:
    if (!(memoryGet(ds, 0xb884) & 0x04))
        { pc = 0x18b79; break; }
    r16[dx] += 0x0080;
    if (r16s[dx] <= signed16(0x0400))
        { pc = 0x18b79; break; }
    r16[dx] = 0x0400;
  case 0x18b79:
    memorySet16(ds, 0x0b24, r16[dx]);
    memorySet16(ds, 0x7961, r16[dx]);
    if (r16s[dx] < 0)
        { pc = 0x18b8d; break; }
    r8[ch] = 0;
    { pc = 0x18b8f; break; }
    // gap 1 bytes
  case 0x18b8d:
    r8[ch] = 0xff;
  case 0x18b8f:
    r16[ax] = memoryGet16(ds, 0x0b20);
    r8[cl] = memoryGet(ds, 0x0b22);
    flags.carry = r8[cl] + r8[dl] >= 0x100;
    r8[cl] += r8[dl];
    temp_cf = flags.carry;
    temp_cf = (r8[al] + r8[dh]) + flags.carry >= 0x100;
    r8[al] += (r8[dh] + flags.carry);
    flags.carry = temp_cf;
    r8[ah] += (r8[ch] + flags.carry);
    memorySet16(ds, 0x795f, r16[ax]);
    r16[dx] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x795d, r16[dx]);
    memorySet(ds, 0x796b, 0x01);
    yield* sub_17dfb();
    r8[ch] = memoryGet(ds, 0x7963);
    if (!(r8[ch] & 0x20))
        { pc = 0x18bbe; break; }
    { pc = 0x168a8; break; }
  case 0x18bbe:
    if (r8[ch] & 0x04)
        { pc = 0x18beb; break; }
    if (!(r8[ch] & 0x02))
        { pc = 0x18c00; break; }
    r16[bp] = memoryGet16(cs, 0x0b24);
    if (r16s[bp] >= 0)
        { pc = 0x18beb; break; }
    r16[ax] |= 0x0007;
    r16[ax]++;
    r16[dx] = 0;
    r8[cl] = 0;
    memorySet16(ds, 0x0b24, 0x0000);
    { pc = 0x18c00; break; }
    // gap 1 bytes
  case 0x18beb:
    r16[ax] += 0x000c;
    r16[ax] |= 0x0007;
    r16[ax] -= 0x0014;
    r8[cl] = 0;
    r16[dx] = 0;
    r8[cl] = 0;
    memorySet16(ds, 0x0b24, 0x0000);
  case 0x18c00:
    memorySet16(ds, 0x0b20, r16[ax]);
    r16[bp] = 0x0000;
    if (!(memoryGet(ds, 0xb884) & 0x02))
        { pc = 0x18c1d; break; }
    r16[bp] = 0xfffc;
    memorySet16(ds, 0x0b36, 0x0001);
    { pc = 0x18c31; break; }
    // gap 1 bytes
  case 0x18c1d:
    if (!(memoryGet(ds, 0xb884) & 0x01))
        { pc = 0x18c31; break; }
    r16[bp] = 0x0004;
    memorySet16(ds, 0x0b36, 0x0000);
  case 0x18c31:
    r16[bx] = memoryGet16(ds, 0x0b1e);
    r16[bx] += r16[bp];
    if (!r16[bp])
        { pc = 0x18c69; break; }
    if (r16s[bp] >= 0)
        { pc = 0x18c57; break; }
    if (r16s[bx] >= signed16(0x0000))
        { pc = 0x18c69; break; }
    r16[bx] = 0x0000;
    memorySet(ds, 0x90c2, 0x01);
    { pc = 0x18c69; break; }
    // gap 1 bytes
  case 0x18c57:
    if (r16s[bx] < signed16(0x00e8))
        { pc = 0x18c69; break; }
    r16[bx] = 0x00e8;
    memorySet(ds, 0x90c2, 0x02);
  case 0x18c69:
    r16[ax] = memoryGet16(ds, 0x0b20);
    memorySet16(ds, 0x795f, r16[ax]);
    memorySet16(ds, 0x7961, 0xffff);
    memorySet(ds, 0x796b, 0x01);
    memorySet16(ds, 0x795d, r16[bx]);
    r16[dx] = r16[bp];
    { pc = 0x187db; break; }
    // gap 791 bytes
  case 0x18f9a:
    r16[dx] = memoryGet16(ds, 0x0b24);
    r16[dx] += 0x0080;
    memorySet16(ds, 0x0b24, r16[dx]);
    if (r16s[dx] < 0)
        { pc = 0x18faf; break; }
    r8[ch] = 0;
    { pc = 0x18fb1; break; }
    // gap 1 bytes
  case 0x18faf:
    r8[ch] = 0xff;
  case 0x18fb1:
    r16[ax] = memoryGet16(ds, 0x0b20);
    r8[cl] = memoryGet(ds, 0x0b22);
    flags.carry = r8[cl] + r8[dl] >= 0x100;
    r8[cl] += r8[dl];
    temp_cf = flags.carry;
    temp_cf = (r8[al] + r8[dh]) + flags.carry >= 0x100;
    r8[al] += (r8[dh] + flags.carry);
    flags.carry = temp_cf;
    r8[ah] += (r8[ch] + flags.carry);
    if (r16s[ax] <= signed16(0x0110))
        { pc = 0x18fca; break; }
    memorySet16(ds, 0x7e18, 0x0001);
    return;
  case 0x18fca:
    memorySet16(ds, 0x0b20, r16[ax]);
    memorySet(ds, 0x0b22, r8[cl]);
    r8[al] = memoryGet(ds, 0x8b98);
    r8[al] = ~r8[al];
    memorySet(ds, 0x8b98, r8[al]);
    r8[al] &= 0x01;
    r16[ax] += 0x001c;
    memorySet16(ds, 0x0b26, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x7e1c);
    r16[ax] += memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x0b1e, r16[ax]);
    return;
  }
}
function* sub_18a9a() // 1040:869a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = memoryGet16(ds, 0x6610);
    if (!r16[ax])
        { pc = 0x18ae9; break; }
    if (memoryGet(ds, 0x9804) == 0x01)
        { pc = 0x18ab2; break; }
    memorySet16(ds, 0x6610, memoryGet16(ds, 0x6610) - 1);
  case 0x18ab2:
    r16[ax] = 0x000d;
    yield* sub_1aecd();
    memorySet16(ds, 0x0b00, 0x0001);
    r16[ax] = memoryGet16(ds, 0x0b20);
    r16[ax] += 0x0007;
    memorySet16(ds, 0x0b04, r16[ax]);
    if (memoryGet16(ds, 0x0b36))
        { pc = 0x18aea; break; }
    memorySet16(ds, 0x0b1a, 0x0008);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x0b02, r16[ax]);
    memorySet16(ds, 0x0b0a, 0x001f);
    memorySet16(ds, 0x7e12, 0x0000);
  case 0x18ae9:
    return;
  case 0x18aea:
    memorySet16(ds, 0x0b1a, 0xfff8);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x0b02, r16[ax]);
    memorySet16(ds, 0x0b0a, 0x001e);
    memorySet16(ds, 0x7e12, 0x0000);
    return;
  }
}
function* sub_18c83() // 1040:8883
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x18c83; break; }
  case 0x18a9a:
    r16[ax] = memoryGet16(ds, 0x6610);
    if (!r16[ax])
        { pc = 0x18ae9; break; }
    if (memoryGet(ds, 0x9804) == 0x01)
        { pc = 0x18ab2; break; }
    memorySet16(ds, 0x6610, memoryGet16(ds, 0x6610) - 1);
  case 0x18ab2:
    r16[ax] = 0x000d;
    yield* sub_1aecd();
    memorySet16(ds, 0x0b00, 0x0001);
    r16[ax] = memoryGet16(ds, 0x0b20);
    r16[ax] += 0x0007;
    memorySet16(ds, 0x0b04, r16[ax]);
    if (memoryGet16(ds, 0x0b36))
        { pc = 0x18aea; break; }
    memorySet16(ds, 0x0b1a, 0x0008);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x0b02, r16[ax]);
    memorySet16(ds, 0x0b0a, 0x001f);
    memorySet16(ds, 0x7e12, 0x0000);
  case 0x18ae9:
    return;
  case 0x18aea:
    memorySet16(ds, 0x0b1a, 0xfff8);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x0b02, r16[ax]);
    memorySet16(ds, 0x0b0a, 0x001e);
    memorySet16(ds, 0x7e12, 0x0000);
    return;
    // gap 384 bytes
  case 0x18c83:
    if (memoryGet(ds, 0xb884) & 0x10)
        { pc = 0x18c95; break; }
    memorySet16(ds, 0x7e12, 0x0001);
    return;
  case 0x18c95:
    memorySet16(ds, 0x7e10, 0x0001);
    if (!memoryGet16(ds, 0x7e12))
        { pc = 0x18cbd; break; }
    if (!(memoryGet16(ds, 0x6610) & 0x00ff))
        { pc = 0x18cbd; break; }
    if (memoryGet16(ds, 0x0b00) == 0x0001)
        { pc = 0x18cbd; break; }
    { pc = 0x18a9a; break; }
  case 0x18cbd:
    return;
  }
}
function* sub_18cbe() // 1040:88be
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x0b00) == 0x0001)
        { pc = 0x18cc9; break; }
    return;
  case 0x18cc9:
    r16[dx] = 0x0004;
    r16[ax] = memoryGet16(ds, 0x0b1a);
    if (r16s[ax] < 0)
        { pc = 0x18cd9; break; }
    r16[dx] = 0x0014;
  case 0x18cd9:
    r16[ax] += memoryGet16(ds, 0x0b02);
    r16[dx] += r16[ax];
    if (r16s[dx] < signed16(0x0003))
        { pc = 0x18d21; break; }
    if (r16s[dx] > signed16(0x00fc))
        { pc = 0x18d21; break; }
    memorySet16(ds, 0x795d, r16[dx]);
    r16[cx] = memoryGet16(ds, 0x0b04);
    memorySet16(ds, 0x795f, r16[cx]);
    memorySet16(ds, 0x795f, memoryGet16(ds, 0x795f) + 0x0004);
    yield* sub_18014();
    push(r16[ax]);
    yield* sub_181c6();
    r16[ax] = pop();
    r8[ch] = memoryGet(ds, 0x7963);
    if (r8[ch] & 0x02)
        { pc = 0x18d21; break; }
    if (r8[ch] & 0x40)
        { pc = 0x18d21; break; }
    memorySet16(ds, 0x0b02, r16[ax]);
    return;
  case 0x18d21:
    memorySet16(ds, 0x0b00, 0x0000);
    return;
  }
}
function* sub_18d28() // 1040:8928
{
  var pc = 0;
  var temp_cf;
  while (1) switch(pc)
  {
  case 0:
    memorySet16(ds, 0x7e1e, 0x0000);
    if (signed16(memoryGet16(ds, 0x0b38)) >= signed16(0x0001))
        { pc = 0x18d39; break; }
    return;
  case 0x18d39:
    if (signed16(memoryGet16(ds, 0x0b38)) <= signed16(0x0001))
        { pc = 0x18d3e; break; }
    { pc = 0x18f57; break; }
  case 0x18d3e:
    r16[si] = 0x0b38;
    yield* sub_1718e();
    if (!flags.carry)
        { pc = 0x18d49; break; }
    { pc = 0x18f3a; break; }
  case 0x18d49:
    r16[dx] = memoryGet16(ds, 0x0b40);
    r16[dx] += 0x0080;
    if (r16s[dx] <= signed16(0x0800))
        { pc = 0x18d5a; break; }
    r16[dx] = 0x0800;
  case 0x18d5a:
    memorySet16(ds, 0x0b40, r16[dx]);
    memorySet16(ds, 0x7961, r16[dx]);
    if (r16s[dx] < 0)
        { pc = 0x18d6b; break; }
    r8[ch] = 0;
    { pc = 0x18d6d; break; }
    // gap 1 bytes
  case 0x18d6b:
    r8[ch] = 0xff;
  case 0x18d6d:
    r16[ax] = memoryGet16(ds, 0x0b3c);
    r8[cl] = memoryGet(ds, 0x0b3e);
    flags.carry = r8[cl] + r8[dl] >= 0x100;
    r8[cl] += r8[dl];
    temp_cf = flags.carry;
    temp_cf = (r8[al] + r8[dh]) + flags.carry >= 0x100;
    r8[al] += (r8[dh] + flags.carry);
    flags.carry = temp_cf;
    r8[ah] += (r8[ch] + flags.carry);
    r16[dx] = r16[ax];
    if (r16s[dx] <= signed16(0x0171))
        { pc = 0x18d85; break; }
    { pc = 0x18f91; break; }
  case 0x18d85:
    if (r16s[dx] >= signed16(0x0000))
        { pc = 0x18d8d; break; }
    { pc = 0x18f91; break; }
  case 0x18d8d:
    memorySet16(ds, 0x795f, r16[dx]);
    r16[ax] = memoryGet16(ds, 0x0b3a);
    memorySet16(ds, 0x795d, r16[ax]);
    memorySet(ds, 0x796b, 0x01);
    yield* sub_1802d();
    r8[ch] = memoryGet(ds, 0x7963);
    if (!(r8[ch] & 0x40))
        { pc = 0x18dec; break; }
    r16[dx] = 0;
    r16[ax] = memoryGet16(ds, 0x7964);
    r8[cl] = 0;
    r16[ax] -= 0x0010;
    memorySet16(ds, 0x795f, r16[ax]);
    memorySet16(ds, 0x0b3c, r16[ax]);
    memorySet(ds, 0x0b3e, 0x00);
    push(r16[ax]);
    r16[ax] = memoryGet16(ds, 0x7966);
    memorySet16(ds, 0x7e1e, r16[ax]);
    r16[ax] = pop();
    memorySet(ds, 0x796b, 0x00);
    yield* sub_1802d();
    r8[ch] = memoryGet(ds, 0x7963);
    if (r8[ch] & 0x20)
        { pc = 0x18de4; break; }
    if (r8[ch] & 0x06)
        { pc = 0x18e08; break; }
    memorySet16(ds, 0x0b40, 0x0100);
    { pc = 0x18e5a; break; }
    // gap 1 bytes
  case 0x18de4:
    if (!(r8[ch] & 0x20))
        { pc = 0x18dec; break; }
    { pc = 0x18f3a; break; }
  case 0x18dec:
    if (r8[ch] & 0x04)
        { pc = 0x18e11; break; }
    if (r8[ch] & 0x02)
        { pc = 0x18e01; break; }
    memorySet16(ds, 0x0b3c, r16[dx]);
    memorySet(ds, 0x0b3e, r8[cl]);
    { pc = 0x18e5a; break; }
    // gap 1 bytes
  case 0x18e01:
    r16[ax] = memoryGet16(ds, 0x0b40);
    if (r16s[ax] >= 0)
        { pc = 0x18e11; break; }
  case 0x18e08:
    r16[dx] |= 0x0007;
    r16[dx]++;
    r8[cl] = 0;
    { pc = 0x18e18; break; }
    // gap 1 bytes
  case 0x18e11:
    r16[dx]--;
    r16[dx] &= 0x0ff8;
    r8[cl] = 0;
  case 0x18e18:
    memorySet16(ds, 0x0b3c, r16[dx]);
    memorySet(ds, 0x0b3e, r8[cl]);
    if (!(r8[ch] & 0x20))
        { pc = 0x18e28; break; }
    { pc = 0x18f3a; break; }
  case 0x18e28:
    if (!(r8[ch] & 0x01))
        { pc = 0x18e54; break; }
    if (memoryGet16(ds, 0x8bec) != 0x0003)
        { pc = 0x18e47; break; }
    r16[ax] = memoryGet16(ds, 0x0b40);
    if (r16s[ax] < signed16(0x0200))
        { pc = 0x18e54; break; }
    r16[ax] = -r16[ax];
    r16[ax] += 0x0060;
    memorySet16(ds, 0x0b40, r16[ax]);
    { pc = 0x18e5a; break; }
    // gap 1 bytes
  case 0x18e47:
    if (memoryGet16(ds, 0x8bec) != 0x0005)
        { pc = 0x18e54; break; }
    r16[ax] = 0xf781;
    { pc = 0x18e57; break; }
    // gap 1 bytes
  case 0x18e54:
    r16[ax] = 0x0100;
  case 0x18e57:
    memorySet16(ds, 0x0b40, r16[ax]);
  case 0x18e5a:
    r16[dx] = memoryGet16(ds, 0x0b52);
    r16[bx] = 0x0008;
    if (!(r8[ch] & 0x01))
        { pc = 0x18e7e; break; }
    if (memoryGet16(ds, 0x8bec) == 0x0001)
        { pc = 0x18e92; break; }
    if (memoryGet16(ds, 0x8bec) == 0x0002)
        { pc = 0x18ead; break; }
    if (memoryGet16(ds, 0x8bec) != 0x0004)
        { pc = 0x18e7e; break; }
    r16[bx] = 0x0010;
  case 0x18e7e:
    r16[bp] = memoryGet16(cs, 0x0b52);
    if (r16s[bp] < 0)
        { pc = 0x18e8e; break; }
    r16[dx] -= r16[bx];
    if (r16s[dx] >= 0)
        { pc = 0x18e94; break; }
    { pc = 0x18e92; break; }
    // gap 1 bytes
  case 0x18e8e:
    r16[dx] += r16[bx];
    if (r16s[dx] < 0)
        { pc = 0x18e94; break; }
  case 0x18e92:
    r16[dx] = 0;
  case 0x18e94:
    memorySet16(ds, 0x0b52, r16[dx]);
    r16[ax] = memoryGet16(ds, 0x7e1e);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] += r16[ax];
  case 0x18ead:
    r16[bx] = memoryGet16(ds, 0x0b3a);
    r8[cl] = memoryGet(ds, 0x0b3f);
    r16[ax] = memoryGet16(ds, 0x0b3c);
    memorySet16(ds, 0x795f, r16[ax]);
    memorySet16(ds, 0x7961, 0xffff);
    if (r16s[dx] < 0)
        { pc = 0x18eca; break; }
    r8[ch] = 0;
    { pc = 0x18ecc; break; }
    // gap 1 bytes
  case 0x18eca:
    r8[ch] = 0xff;
  case 0x18ecc:
    r16[bx] = memoryGet16(ds, 0x0b3a);
    r8[cl] = memoryGet(ds, 0x0b3f);
    flags.carry = r8[cl] + r8[dl] >= 0x100;
    r8[cl] += r8[dl];
    temp_cf = flags.carry;
    temp_cf = (r8[bl] + r8[dh]) + flags.carry >= 0x100;
    r8[bl] += (r8[dh] + flags.carry);
    flags.carry = temp_cf;
    r8[bh] += (r8[ch] + flags.carry);
    if (r16s[bx] < signed16(0x00e8))
        { pc = 0x18eee; break; }
    r8[cl] = 0;
    r16[bx] = 0x00e8;
    memorySet16(ds, 0x0b52, 0x0000);
    { pc = 0x18efd; break; }
    // gap 1 bytes
  case 0x18eee:
    if (r16s[bx] >= signed16(0x0000))
        { pc = 0x18efd; break; }
    r8[cl] = 0;
    r16[bx] = 0;
    memorySet16(ds, 0x0b52, 0x0000);
  case 0x18efd:
    memorySet16(ds, 0x795d, r16[bx]);
    memorySet(ds, 0x796b, 0x01);
    yield* sub_1802d();
    r8[ch] = memoryGet(ds, 0x7963);
    if (!(r8[ch] & 0x02))
        { pc = 0x18f2c; break; }
    r8[cl] = 0;
    r16[bp] = memoryGet16(ds, 0x0b52);
    r16[bp] += memoryGet16(ds, 0x7e1e);
    if (r16s[bp] >= 0)
        { pc = 0x18f27; break; }
    r16[bx] |= 0x0007;
    r16[bx]++;
    { pc = 0x18f2c; break; }
    // gap 1 bytes
  case 0x18f27:
    r16[bx]--;
    r16[bx] &= 0x00f8;
  case 0x18f2c:
    memorySet16(ds, 0x0b3a, r16[bx]);
    memorySet(ds, 0x0b3f, r8[cl]);
    if (r8[ch] & 0x20)
        { pc = 0x18f3a; break; }
    return;
  case 0x18f3a:
    memorySet16(ds, 0x0b38, 0x0002);
    memorySet16(ds, 0x0b50, 0x0000);
    memorySet16(ds, 0x0b4e, 0x7eb2);
    memorySet16(ds, 0x0b3c, memoryGet16(ds, 0x0b3c) - 0x0005);
    memorySet16(ds, 0x0b4a, 0x0000);
  case 0x18f57:
    r16[si] = 0x0b38;
    memorySet16(ds, 0x0b4a, memoryGet16(ds, 0x0b4a) + 1);
    if (signed8(memoryGet(ds, 0x0b4a)) <= signed8(0x01))
        { pc = 0x18f8c; break; }
    if (signed8(memoryGet(ds, 0x0b4a)) > signed8(0x04))
        { pc = 0x18f8c; break; }
    r16[dx] = memoryGet16(ds, 0x0b3a);
    r16[dx] -= 0x0004;
    if (r16s[dx] >= 0)
        { pc = 0x18f77; break; }
    r16[dx] = 0;
  case 0x18f77:
    r8[tl] = r8[dh];
    r8[dh] = r8[dl];
    r8[dl] = r8[tl];
    r16[bx] = memoryGet16(ds, 0x0b3c);
    r16[bx] -= 0x0004;
    r8[dl] = 0x20;
    r8[ah] = 0x1c;
    yield* sub_16407();
    if (!flags.carry)
        { pc = 0x18f8c; break; }
    yield* sub_168a8();
  case 0x18f8c:
    yield* sub_1718e();
    if (!flags.carry)
        { pc = 0x18f97; break; }
  case 0x18f91:
    memorySet16(ds, 0x0b38, 0x0000);
  case 0x18f97:
    return;
  }
}
function* sub_19214() // 1040:8e14
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx] = memoryGet16(ds, 0x8bf6);
    r16[di] = 0x563c;
    r16[cx] = 0x000a;
    r16[dx] = memoryGet16(ds, 0x8bf0);
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
    memorySet16(ds, 0x8bf8, r16[bx]);
    r16[ax] &= 0x0003;
    memorySet16(ds, 0x8bfa, r16[ax]);
    if (!r16[ax])
        { pc = 0x19257; break; }
    r16[dx] = 0x0004;
    r16[dx] -= r16[ax];
    push(r16[cx]);
    yield* sub_1926d();
    r16[cx] = pop();
    { pc = 0x1925c; break; }
    // gap 1 bytes
  case 0x19257:
    push(r16[cx]);
    yield* sub_192ae();
    r16[cx] = pop();
  case 0x1925c:
    if (--r16[cx])
        { pc = 0x19257; break; }
    r16[dx] = memoryGet16(ds, 0x8bfa);
    if (!r16[dx])
        { pc = 0x1926c; break; }
    r16[ax] = 0x0000;
    yield* sub_1926d();
  case 0x1926c:
    return;
  }
}
function* sub_1926d() // 1040:8e6d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[di]);
    push(r16[dx]);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[cx] = 0x0008;
  case 0x19276:
    push(r16[cx]);
    push(r16[ax]);
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r16[ax] <<= 1;
    r16[si] = 0x8c14;
    r16[si] += r16[ax];
    r16[ax] = pop();
    r16[si] = memoryGet16(ds, r16[si]);
    r16[si] += r16[ax];
    r16[bp] = r16[di];
    push(r16[dx]);
  case 0x1928c:
    r16[cx] = 0x0004;
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
    r16[di] += 0x001c;
    r16[dx]--;
    if (r16[dx])
        { pc = 0x1928c; break; }
    r16[dx] = pop();
    r16[di] = r16[bp];
    r16[di] += 0x0004;
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x19276; break; }
    r16[dx] = pop();
    r16[di] = pop();
    r16[dx]--;
    r16[dx] &= 0x0003;
    r16[dx]++;
    r8[cl] = 0x05;
    r16[dx] <<= r8[cl];
    r16[di] += r16[dx];
    return;
  }
}
function* sub_192ae() // 1040:8eae
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[cx] = 0x0008;
  case 0x192b1:
    r16[bp] = r16[cx];
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r16[ax] <<= 1;
    r16[si] = 0x8c14;
    r16[si] += r16[ax];
    r16[si] = memoryGet16(ds, r16[si]);
    r16[dx] = 0x0004;
  case 0x192c4:
    r16[cx] = 0x0004;
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
    r16[di] += 0x001c;
    r16[dx]--;
    if (r16[dx])
        { pc = 0x192c4; break; }
    r16[di] += 0xff84;
    r16[cx] = r16[bp];
    if (--r16[cx])
        { pc = 0x192b1; break; }
    r16[di] += 0x0060;
    return;
  }
}
function* sub_192da() // 1040:8eda
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[di] = 0x563c;
    r16[si] = 0x565c;
    r16[cx] = 0x0270;
    for (; r16[cx] != 0; --r16[cx]) movsw_MemFwdESDI_MemFwdDSSI();
    r16[ax] = memoryGet16(ds, 0x8bfa);
    r16[dx] = 0x0001;
    r16[bx] = memoryGet16(ds, 0x8bf8);
    r16[bx] += 0x0050;
    r16[di] = 0x5b1c;
    yield* sub_1926d();
    memorySet16(ds, 0x8bfa, memoryGet16(ds, 0x8bfa) + 0x0001);
    memorySet16(ds, 0x8bfa, memoryGet16(ds, 0x8bfa) & 0x0003);
    if (memoryGet16(ds, 0x8bfa))
        { pc = 0x19309; break; }
    memorySet16(ds, 0x8bf8, memoryGet16(ds, 0x8bf8) + 0x0008);
  case 0x19309:
    return;
  }
}
function* sub_1930a() // 1040:8f0a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] = 0x5b1a;
    r16[di] = 0x5b3a;
    flags.direction = 1;
    r16[cx] = 0x0270;
    for (; r16[cx] != 0; --r16[cx]) movsw_MemBwdESDI_MemBwdDSSI();
    flags.direction = 0;
    r16[bx] = memoryGet16(ds, 0x8bf8);
    memorySet16(ds, 0x8bfa, memoryGet16(ds, 0x8bfa) - 1);
    memorySet16(ds, 0x8bfa, memoryGet16(ds, 0x8bfa) & 0x0003);
    if (memoryGet16(ds, 0x8bfa) != 0x0003)
        { pc = 0x19332; break; }
    r16[bx] -= 0x0008;
    memorySet16(ds, 0x8bf8, r16[bx]);
  case 0x19332:
    r16[di] = 0x563c;
    r16[ax] = memoryGet16(ds, 0x8bfa);
    r16[dx] = 0x0001;
    yield* sub_1926d();
    return;
  }
}
function* sub_1933f() // 1040:8f3f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x3c74;
    r16[di] = 0x8c14;
    r16[dx] = 0x0010;
    r16[cx] = 0x0100;
  case 0x1934b:
    stosw_MemFwdESDI(r16[ax]);
    r16[ax] += r16[dx];
    if (--r16[cx])
        { pc = 0x1934b; break; }
    return;
  }
}
function* sub_19351() // 1040:8f51
{
    memorySet16(ds, 0x0b00, 0x0000);
    memorySet16(ds, 0x0b38, 0x0000);
    push(r16[ax]);
    r16[ax] = memoryGet16(ds, 0x0b1e);
    memorySet16(ds, 0x8c00, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x0b20);
    memorySet16(ds, 0x8c02, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x0b24);
    memorySet16(ds, 0x8c08, r16[ax]);
    r8[al] = memoryGet(ds, 0x0b22);
    memorySet(ds, 0x8c12, r8[al]);
    r16[ax] = memoryGet16(ds, 0x7e02);
    memorySet16(ds, 0x8c0a, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x7e04);
    memorySet16(ds, 0x8c0c, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x0b36);
    memorySet16(ds, 0x8c0e, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x7e00);
    memorySet16(ds, 0x8c10, r16[ax]);
    r16[ax] = pop();
    memorySet16(ds, 0x8c04, r16[ax]);
    memorySet16(ds, 0x8c06, r16[dx]);
    r16[si] = 0x4c74;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[si] += r16[ax];
    r16[ax] = 0;
    r16[ax] += memoryGet16(ds, r16[si]);
    r16[si]++;
    r16[si]++;
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r16[ax] += 0x3374;
    memorySet16(ds, 0x8bf6, r16[ax]);
    memorySet16(ds, 0x8bf2, 0x0000);
    r16[ax] = memoryGet16(ds, r16[si]);
    r16[si]++;
    r16[si]++;
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    memorySet16(ds, 0x8bf4, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si]);
    r16[si]++;
    r16[si]++;
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r16[ax] += 0x4c74;
    memorySet16(ds, 0x8bfe, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si]);
    r16[si]++;
    r16[si]++;
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    r16[ax] += 0x4c74;
    memorySet16(ds, 0x8bfc, r16[ax]);
    memorySet16(ds, 0x8bf0, r16[dx]);
    yield* sub_19577();
}
function* sub_19420() // 1040:9020
{
    r16[si] = 0x8fe4;
    r16[ax] = memoryGet16(ds, 0x8bec);
    r16[ax]--;
    r16[ax] <<= 1;
    r16[si] += r16[ax];
    r16[si] = memoryGet16(ds, r16[si]);
    r16[ax] = memoryGet16(ds, r16[si]);
    memorySet16(ds, 0x0b1e, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si] + 2);
    memorySet16(ds, 0x0b20, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si] + 4);
    r16[dx] = memoryGet16(ds, r16[si] + 6);
    r16[cx] = memoryGet16(ds, r16[si] + 8);
    memorySet16(ds, 0x0b36, r16[cx]);
    yield* sub_19351();
    yield* sub_19214();
    yield* sub_19577();
    yield* sub_17047();
    yield* sub_15fe4();
    memorySet(ds, 0x5b3e, 0x01);
    yield* sub_15f40();
    memorySet(ds, 0x5b3e, 0x00);
}
function* sub_19462() // 1040:9062
{
    r16[ax] = memoryGet16(ds, 0x8c00);
    memorySet16(ds, 0x0b1e, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x8c02);
    memorySet16(ds, 0x0b20, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x8c08);
    memorySet16(ds, 0x0b24, r16[ax]);
    r8[al] = memoryGet(ds, 0x8c12);
    memorySet(ds, 0x0b22, r8[al]);
    r16[ax] = memoryGet16(ds, 0x8c0a);
    memorySet16(ds, 0x7e02, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x8c0c);
    memorySet16(ds, 0x7e04, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x8c0e);
    memorySet16(ds, 0x0b36, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x8c10);
    memorySet16(ds, 0x7e00, r16[ax]);
    r16[ax] = memoryGet16(ds, 0x8c04);
    r16[dx] = memoryGet16(ds, 0x8c06);
    yield* sub_19351();
    yield* sub_19214();
    yield* sub_19577();
    yield* sub_17047();
    memorySet16(ds, 0x6612, 0x0006);
    memorySet16(ds, 0x6610, 0x0006);
    yield* sub_15fe4();
    memorySet(ds, 0x5b3e, 0x01);
    yield* sub_15f40();
    memorySet(ds, 0x5b3e, 0x00);
}
function* sub_194c4() // 1040:90c4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r8[al] = memoryGet(ds, 0x90c2);
    if (r8[al])
        { pc = 0x194cc; break; }
    sp += 2;
    return;
  case 0x194cc:
    r16[si] = memoryGet16(ds, 0x8bfe);
  case 0x194d0:
    r8[al] = memoryGet(ds, r16[si]);
    if (!r8[al])
        { pc = 0x19552; break; }
    r8[al] &= 0x03;
    if (r8[al] != memoryGet(ds, 0x90c2))
        { pc = 0x194f6; break; }
    r16[ax] = memoryGet16(ds, 0x8bf0);
    r16[ax] &= 0xfff8;
    r16[ax] += memoryGet16(ds, 0x0b20);
    r16[ax] += 0x0014;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    if (r8[al] == memoryGet(ds, r16[si] + 1))
        { pc = 0x194fb; break; }
  case 0x194f6:
    r16[si] += 0x0004;
    { pc = 0x194d0; break; }
  case 0x194fb:
    r8[al] = memoryGet(ds, r16[si]);
    r8[ah] = r8[al];
    r8[ah] &= 0x90;
    if (r8[ah] != 0x90)
        { pc = 0x1950a; break; }
    { pc = 0x19650; break; }
  case 0x1950a:
    if (!(r8[al] & 0x40))
        { pc = 0x19514; break; }
    memorySet16(ds, 0x762d, 0x0001);
  case 0x19514:
    if (!(r8[al] & 0x20))
        { pc = 0x19521; break; }
    memorySet16(ds, 0x7e00, 0x0001);
    { pc = 0x19527; break; }
    // gap 1 bytes
  case 0x19521:
    memorySet16(ds, 0x7e00, 0x0000);
  case 0x19527:
    r16[cx] = 0;
    r8[al] = memoryGet(ds, r16[si] + 2);
    r16[dx] = 0;
    r8[dl] = memoryGet(ds, r16[si] + 3);
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[cx] = memoryGet16(ds, 0x0b20);
    r16[cx] += 0x0014;
    r16[cx] &= 0xfff8;
    r16[dx] -= r16[cx];
    r16[cx] = memoryGet16(ds, 0x8bf0);
    r16[cx] &= 0x0007;
    r16[dx] &= 0xfff8;
    r16[dx] |= r16[cx];
    yield* sub_19553();
  case 0x19552:
    sp += 2;
    return;
    // gap 253 bytes
  case 0x19650:
    yield* sub_10ee5();
    r16[ax] = memoryGet16(ds, 0x8bec);
    if (r16[ax] != 0x0004)
        { pc = 0x19687; break; }
    if (memoryGet16(ds, 0x95c4) == 0x0001)
        { pc = 0x19673; break; }
    if (memoryGet16(ds, 0x8bee) == 0x0001)
        { pc = 0x19673; break; }
    r16[ax] = 0x0001;
    yield* sub_1a257();
    yield* sub_19f12();
    return;
  case 0x19673:
    memorySet16(ds, 0x8bec, memoryGet16(ds, 0x8bec) + 1);
    if (memoryGet16(ds, 0x8bec) != 0x0005)
        { pc = 0x19684; break; }
    memorySet16(ds, 0x95c4, 0x0001);
  case 0x19684:
    { pc = 0x1c3b9; break; }
  case 0x19687:
    if (memoryGet16(ds, 0x8bec) != 0x0005)
        { pc = 0x196a7; break; }
    if (memoryGet16(ds, 0x8bee) != 0x0001)
        { pc = 0x19698; break; }
    { pc = 0x19f37; break; }
  case 0x19698:
    memorySet16(ds, 0x95c4, 0x0001);
    r16[ax] = 0x0001;
    yield* sub_1a257();
    yield* sub_19f12();
    return;
  case 0x196a7:
    memorySet16(ds, 0x8bec, memoryGet16(ds, 0x8bec) + 1);
    { pc = 0x1c3b9; break; }
    // gap 2185 bytes
  case 0x19f37:
    yield* sub_10ee6();
    r16[ax] = 0x0004;
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[ax] = 0x0006;
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[ax] = 0x0002;
    yield* sub_1a257();
    yield* sub_16d69();
    yield* sub_1a5e3();
    yield* sub_16cd7();
    yield* sub_1c359();
    return;
    // gap 9306 bytes
  case 0x1c3b9:
    sp = memoryGet16(ds, 0xc0df);
    memorySet16(ds, 0x6610, 0x0006);
    memorySet16(ds, 0x6612, 0x0006);
    memorySet16(ds, 0x7e00, 0x0000);
    memorySet16(ds, 0x762d, 0x0000);
    memorySet16(ds, 0x762f, 0x0000);
    yield* sub_1a54a();
    push(cs);
    ds = pop();
    yield* sub_1a56b();
    yield* sub_10594();
    yield* sub_105a1();
    yield* sub_1a45c();
    yield* sub_1c4e2();
    yield* sub_112d6();
    yield* sub_10d03();
    yield* sub_10ee5();
    yield* sub_10ee7();
    r16[ax] = 0x0004;
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[ax] = memoryGet16(ds, 0x8bec);
    r16[ax]--;
    r16[ax] += r16[ax];
    r16[si] = 0x2f69;
    r16[si] += r16[ax];
    r16[ax] = memoryGet16(ds, r16[si]);
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[ax] = 0x0000;
    yield* sub_1a257();
    yield* sub_1a5f0();
    yield* sub_10d03();
    yield* sub_19420();
    memorySet16(ds, 0x973c, 0x3245);
    memorySet16(ds, 0x973e, 0x5432);
  case 0x1c439:
    memorySet16(ds, 0x7e16, 0x0000);
    memorySet16(ds, 0x7e18, 0x0000);
  case 0x1c445:
    yield* sub_16b3b();
    if (memoryGet16(ds, 0x7e18) != 0x0001)
        { pc = 0x1c467; break; }
    memorySet16(ds, 0x762f, 0x0000);
    yield* sub_1618f();
    yield* sub_19462();
    if (memoryGet16(ds, 0x6614))
        { pc = 0x1c465; break; }
    yield* sub_19f12();
    return;
  case 0x1c465:
    { pc = 0x1c439; break; }
  case 0x1c467:
    yield* sub_19bac();
    yield* sub_15f40();
    memorySet(ds, 0x5b3e, 0x00);
    yield* sub_169e3();
    yield* sub_168e4();
    yield* sub_17205();
    yield* sub_18351();
    yield* sub_18cbe();
    yield* sub_18d28();
    yield* sub_1705d();
    yield* sub_10a67();
    yield* sub_1091b();
    yield* sub_11162();
    yield* sub_109ee();
    yield* sub_19af6();
    yield* sub_10ee4();
    yield* sub_194c4();
    if (memoryGet(ds, 0xb888) != 0x10)
        { pc = 0x1c4b3; break; }
    yield* sub_19f8a();
    if (!flags.carry)
        { pc = 0x1c4b3; break; }
    yield* sub_1c359();
    return;
  case 0x1c4b3:
    if (memoryGet(ds, 0xb888) != 0x01)
        { pc = 0x1c445; break; }
    yield* sub_196f3();
    return;
  }
}
function* sub_19553() // 1040:9153
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx] = memoryGet16(ds, 0x0b1e);
    if (r16[bx])
        { pc = 0x19568; break; }
    memorySet16(ds, 0x0b1e, 0x00e8);
    yield* sub_10bc4();
    { pc = 0x19572; break; }
    // gap 1 bytes
  case 0x19568:
    memorySet16(ds, 0x0b1e, 0x0000);
    yield* sub_10c2e();
  case 0x19572:
    return;
  }
}
function* sub_19577() // 1040:9177
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memorySet16(ds, 0x9173, 0x0000);
    r16[si] = 0x54fa;
    memorySet16(ds, 0x9175, r16[si]);
  case 0x19584:
    r8[al] = memoryGet(ds, r16[si]);
    if (r8s[al] < 0)
        { pc = 0x19592; break; }
    memorySet(ds, r16[si], 0x00);
    r16[si] += 0x0008;
    { pc = 0x19584; break; }
  case 0x19592:
    return;
  }
}
function* sub_19593() // 1040:9193
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    push(r16[di]);
    push(r16[ax]);
    push(cs);
    ds = pop();
    if (signed16(memoryGet16(ds, 0x9173)) < signed16(0x0028))
        { pc = 0x195a5; break; }
    r16[ax] = pop();
    r16[di] = pop();
    es = pop();
    ds = pop();
    return;
  case 0x195a5:
    r16[dx] = 0;
    r8[dl] = r8[al];
    r16[dx] -= 0x00f8;
    r16[dx] += r16[dx];
    r16[dx] += r16[dx];
    r16[ax] = 0;
    yield* sub_19b40();
    r8[al] = memoryGet(ds, 0x973f);
    cbw();
    r8[al] &= 0x03;
    r16[dx] += r16[ax];
    r16[ax] = 0;
    r16[si] = 0x54fa;
  case 0x195c3:
    r8[al] = memoryGet(ds, r16[si]);
    if (r8s[al] < 0)
        { pc = 0x195e0; break; }
    if (r8[al])
        { pc = 0x195e5; break; }
    memorySet(ds, r16[si], 0x01);
    r16[si]++;
    memorySet(ds, r16[si], r8[dl]);
    r16[si]++;
    memorySet16(ds, r16[si], r16[bx]);
    r16[si]++;
    r16[si]++;
    memorySet16(ds, r16[si], r16[di]);
    r16[si]++;
    r16[si]++;
    memorySet16(ds, r16[si], r16[bp]);
    memorySet16(ds, 0x9173, memoryGet16(ds, 0x9173) + 1);
  case 0x195e0:
    r16[ax] = pop();
    r16[di] = pop();
    es = pop();
    ds = pop();
    return;
  case 0x195e5:
    r16[si] += 0x0008;
    { pc = 0x195c3; break; }
    return;
  }
}
function* sub_195ea() // 1040:91ea
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x9173))
        { pc = 0x195f2; break; }
    return;
  case 0x195f2:
    r16[si] = 0x54fa;
  case 0x195f5:
    r8[al] = memoryGet(ds, r16[si]);
    if (!r8[al])
        { pc = 0x19617; break; }
    if (r8s[al] < 0)
        { pc = 0x1961c; break; }
    r16[ax] = memoryGet16(ds, r16[si] + 2);
    r16[ax] += 0x0020;
    if (r16s[ax] < signed16(0x5a7c))
        { pc = 0x19614; break; }
    memorySet(ds, r16[si], 0x00);
    memorySet16(ds, 0x9173, memoryGet16(ds, 0x9173) - 1);
    r16[si] += 0x0008;
    { pc = 0x195f5; break; }
  case 0x19614:
    memorySet16(ds, r16[si] + 2, r16[ax]);
  case 0x19617:
    r16[si] += 0x0008;
    { pc = 0x195f5; break; }
  case 0x1961c:
    return;
  }
}
function* sub_1961d() // 1040:921d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryGet16(ds, 0x9173))
        { pc = 0x19625; break; }
    return;
  case 0x19625:
    r16[si] = 0x54fa;
  case 0x19628:
    r8[al] = memoryGet(ds, r16[si]);
    if (!r8[al])
        { pc = 0x1964a; break; }
    if (r8s[al] < 0)
        { pc = 0x1964f; break; }
    r16[ax] = memoryGet16(ds, r16[si] + 2);
    r16[ax] -= 0x0020;
    if (r16s[ax] >= signed16(0x573c))
        { pc = 0x19647; break; }
    memorySet(ds, r16[si], 0x00);
    memorySet16(ds, 0x9173, memoryGet16(ds, 0x9173) - 1);
    r16[si] += 0x0008;
    { pc = 0x19628; break; }
  case 0x19647:
    memorySet16(ds, r16[si] + 2, r16[ax]);
  case 0x1964a:
    r16[si] += 0x0008;
    { pc = 0x19628; break; }
  case 0x1964f:
    return;
  }
}
function* sub_196dd() // 1040:92dd
{
    yield* sub_10524();
    yield* sub_1933f();
    yield* sub_1087b();
    yield* sub_109c4();
    yield* sub_1adcb();
    yield* sub_1bc92();
}
function* sub_196f3() // 1040:92f3 +isolate
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    flags.interrupts = 0;
    yield* sub_1ae03();
    yield* sub_1bcb7();
    flags.interrupts = 1;
    r8[al] = memoryGet(ds, 0x006a);
    r8[ah] = 0;
    interrupt(0x10);
    if (memoryGet16(ds, 0xab2b) == 0x0001)
        { pc = 0x1970f; break; }
    yield* sub_1adb0();
    { pc = 0x1972d; break; }
    // gap 1 bytes
  case 0x1970f:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    r16[si] = 0x0000;
    r16[bx] = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
  case 0x1972d:
    r8[ah] = 0x4c;
    interrupt(0x21);
    stop("terminating");
    return;
  }
}
function* sub_19731() // 1040:9331 +isolate
{
    r8[ah] = 0x09;
    r16[dx] = 0x1040;
    ds = r16[dx];
    r16[dx] = 0x92b1;
    interrupt(0x21);
    r8[ah] = 0x4c;
    interrupt(0x21);
    stop("terminating");
}
function* sub_199c8() // 1040:95c8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memorySet(ds, 0x95ad, 0x01);
    yield* sub_10d03();
    r16[ax] = 0x0706;
    memorySet16(ds, 0x69f0, r16[ax]);
    memorySet16(ds, 0x69f2, r16[ax]);
    yield* sub_16e39();
    r16[ax] = 0x0008;
    r16[si] = 0x9461;
    yield* sub_107ac();
    r16[ax] = 0x0108;
    r16[si] = 0x9481;
    yield* sub_107ac();
    r16[ax] = 0x0208;
    r16[si] = 0x94a1;
    yield* sub_107ac();
    r16[bx] = 0x95b5;
    yield* sub_19c43();
    push(cs);
    ds = pop();
    if (memoryGet16(ds, 0x95c4) != 0x0001)
        { pc = 0x19a10; break; }
    r16[bx] = 0x95bf;
    yield* sub_19c43();
  case 0x19a10:
    yield* sub_109ee();
    r16[ax] = 0x0008;
    r16[si] = 0x9461;
    yield* sub_107ac();
    r16[ax] = 0x0108;
    r16[si] = 0x9481;
    yield* sub_107ac();
    r16[ax] = 0x0208;
    r16[si] = 0x94a1;
    yield* sub_107ac();
    r16[bx] = 0x95b5;
    yield* sub_19c43();
    if (memoryGet16(ds, 0x95c4) != 0x0001)
        { pc = 0x19a45; break; }
    r16[bx] = 0x95bf;
    yield* sub_19c43();
  case 0x19a45:
    memorySet(ds, 0x97da, 0x01);
  case 0x19a4b:
    yield* sync();
    yield* sub_19bdc();
    if (!(r8[al] & 0x10))
        { pc = 0x19a55; break; }
    { pc = 0x19ae0; break; }
  case 0x19a55:
    if (r8[al] == memoryGet(ds, 0x95c3))
        { pc = 0x19a4b; break; }
    memorySet(ds, 0x95c3, r8[al]);
    if (!(r8[al] & 0x08))
        { pc = 0x19a9e; break; }
    r16[dx] = memoryGet16(ds, 0x69f0);
    r8[dh]--;
    r8[dh]--;
    r8[dh]--;
    if (memoryGet16(ds, 0x95c4) == 0x0001)
        { pc = 0x19a84; break; }
    if (r8[dh] != 0x04)
        { pc = 0x19a95; break; }
    r8[dh] = 0x10;
    memorySet(ds, 0x95ad, 0x04);
    yield* sub_16e66();
    { pc = 0x19a4b; break; }
  case 0x19a84:
    if (r8[dh] != 0x04)
        { pc = 0x19a95; break; }
    r8[dh] = 0x13;
    memorySet(ds, 0x95ad, 0x05);
    yield* sub_16e66();
    { pc = 0x19a4b; break; }
  case 0x19a95:
    memorySet(ds, 0x95ad, memoryGet(ds, 0x95ad) - 1);
    yield* sub_16e66();
    { pc = 0x19a4b; break; }
  case 0x19a9e:
    if (!(r8[al] & 0x04))
        { pc = 0x19a4b; break; }
    r16[dx] = memoryGet16(ds, 0x69f0);
    r8[dh]++;
    r8[dh]++;
    r8[dh]++;
    if (memoryGet16(ds, 0x95c4) == 0x0001)
        { pc = 0x19ac4; break; }
    if (r8[dh] != 0x13)
        { pc = 0x19ad6; break; }
    r8[dh] = 0x07;
    memorySet(ds, 0x95ad, 0x01);
    yield* sub_16e66();
    { pc = 0x19a4b; break; }
  case 0x19ac4:
    if (r8[dh] != 0x16)
        { pc = 0x19ad6; break; }
    r8[dh] = 0x07;
    memorySet(ds, 0x95ad, 0x01);
    yield* sub_16e66();
    { pc = 0x19a4b; break; }
  case 0x19ad6:
    memorySet(ds, 0x95ad, memoryGet(ds, 0x95ad) + 1);
    yield* sub_16e66();
    { pc = 0x19a4b; break; }
  case 0x19ae0:
    r8[al] = memoryGet(ds, 0x95ad);
    cbw();
    r16[ax]--;
    r16[si] = 0x95af;
    r16[si] += r16[ax];
    r8[al] = memoryGet(ds, r16[si]);
    cbw();
    memorySet16(ds, 0x8bec, r16[ax]);
    memorySet16(ds, 0x8bee, r16[ax]);
    return;
  }
}
function* sub_19af6() // 1040:96f6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[dx]);
    push(r16[ax]);
    r16[ax] = memoryGet16(ds, 0x96f4);
  case 0x19afb:
    push(r16[ax]);
    push(es);
    r16[dx] = 0x0040;
    es = r16[dx];
    r16[dx] = memoryBiosGet16(es, 0x0063);
    es = pop();
    r8[dl] += 0x06;
  case 0x19b0b:
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x08;
    if (r8[al])
        { pc = 0x19b0b; break; }
  case 0x19b10:
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x08;
    if (!r8[al])
        { pc = 0x19b10; break; }
    r16[ax] = pop();
    r16[ax]--;
    if (r16[ax])
        { pc = 0x19afb; break; }
    r16[ax] = pop();
    r16[dx] = pop();
    return;
  }
}
function* sub_19b1c() // 1040:971c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[dx]);
    push(r16[ax]);
    push(r16[ax]);
    push(es);
    r16[dx] = 0x0040;
    es = r16[dx];
    r16[dx] = memoryBiosGet16(es, 0x0063);
    es = pop();
    r8[dl] += 0x06;
  case 0x19b2e:
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x08;
    if (r8[al])
        { pc = 0x19b2e; break; }
  case 0x19b33:
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x08;
    if (!r8[al])
        { pc = 0x19b33; break; }
    r16[ax] = pop();
    r16[ax] = pop();
    r16[dx] = pop();
    return;
  }
}
function* sub_19b40() // 1040:9740
{
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryGet16(ds, 0x973c);
    r16[dx] = memoryGet16(ds, 0x973e);
    r16[tx] = r16[dx];
    r16[dx] = r16[ax];
    r16[ax] = r16[tx];
    r16[dx] = rol16(r16[dx], 0x0001);
    r16[dx] = rol16(r16[dx], 0x0001);
    r16[dx] = rol16(r16[dx], 0x0001);
    r16[dx] -= 0x0007;
    r16[dx] ^= r16[ax];
    memorySet16(ds, 0x973c, r16[ax]);
    memorySet16(ds, 0x973e, r16[dx]);
    r16[dx] = pop();
    r16[ax] = pop();
}
function* sub_19bac() // 1040:97ac
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[al] = 0x11;
    if (memoryGet(ds, 0x97ab) == 0x01)
        { pc = 0x19bce; break; }
    if (memoryGet(ds, 0xb888) == r8[al])
        { pc = 0x19bbc; break; }
    return;
  case 0x19bbc:
    yield* sync();
    if (memoryGet(ds, 0xb888) == r8[al])
        { pc = 0x19bbc; break; }
  case 0x19bc2:
    yield* sync();
    if (memoryGet(ds, 0xb888) != r8[al])
        { pc = 0x19bc2; break; }
    memorySet(ds, 0x97ab, 0x01);
    return;
  case 0x19bce:
    if (r8[al] == memoryGet(ds, 0xb888))
        { pc = 0x19bd9; break; }
    memorySet(ds, 0x97ab, 0x00);
  case 0x19bd9:
    return;
  }
}
function* sub_19bdc() // 1040:97dc
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_1c4ca();
    if (!(r8[al] & 0x10))
        { pc = 0x19bf0; break; }
    if (memoryGet(ds, 0x97da) == 0x01)
        { pc = 0x19bf5; break; }
    memorySet(ds, 0x97da, 0x01);
    return;
  case 0x19bf0:
    memorySet(ds, 0x97da, 0x00);
  case 0x19bf5:
    r8[al] &= 0xef;
    return;
  }
}
function* sub_19c05() // 1040:9805
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(flagAsReg());
    push(r16[si]);
    push(r16[ax]);
    if (memoryGet(ds, 0x9804) == 0x01)
        { pc = 0x19c3f; break; }
    r16[si] = memoryGet16(ds, 0x97f8);
    r8[al] = memoryGet(ds, 0xb888);
    if (r8[al] & 0x80)
        { pc = 0x19c39; break; }
    if (!r8[al])
        { pc = 0x19c39; break; }
    r8[ah] = memoryGet(ds, r16[si]);
    if (r8[al] != r8[ah])
        { pc = 0x19c33; break; }
    r16[si]++;
    memorySet16(ds, 0x97f8, r16[si]);
    if (memoryGet(ds, r16[si]) != 0xff)
        { pc = 0x19c39; break; }
    memorySet(ds, 0x9804, 0x01);
  case 0x19c33:
    memorySet16(ds, 0x97f8, 0x97fa);
  case 0x19c39:
    memorySet(ds, 0xb888, 0x00);
  case 0x19c3f:
    r16[ax] = pop();
    r16[si] = pop();
    flagsFromReg(pop());
    return;
  }
}
function* sub_19c43() // 1040:9843
{
  var pc = 0x19c43;
  while (1) switch(pc)
  {
  case 0x19c43:
    r16[si] = memoryGet16(ds, r16[bx]);
    if (!r16[si])
        { pc = 0x19c59; break; }
    r8[al] = memoryGet(ds, r16[si]);
    r16[si]++;
    r8[ah] = memoryGet(ds, r16[si]);
    r16[si]++;
    push(r16[bx]);
    yield* sub_107f1();
    r16[bx] = pop();
    r16[bx]++;
    r16[bx]++;
    { pc = 0x19c43; break; }
  case 0x19c59:
    return;
  }
}
function* sub_19e18() // 1040:9a18 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memorySet(cs, 0xbda2, 0xc3); flags.carry = false; return;
    memorySet16(ds, 0x9a16, 0x0000);
    yield* sub_10d03();
  case 0x19e22:
    yield* sub_19ebb();
    r16[bx] = 0x99b3;
    yield* sub_19c43();
    yield* sub_109ee();
    r16[bx] = 0x99b3;
    yield* sub_19c43();
    yield* sub_109ee();
    memorySet(ds, 0xb888, 0x00);
    r16[ax] = memoryGet16(ds, 0x9a16);
    r16[ax] <<= 1;
    r16[di] = 0x9a0c;
    r16[di] += r16[ax];
    r16[di] = memoryGet16(ds, r16[di]);
  case 0x19e4b:
    yield* sub_1bf7c();
    r16[bx] &= 0x0003;
    if (r16[bx])
        { pc = 0x19e6a; break; }
    r8[ah] = memoryGet(ds, 0xb888);
    if (r8s[ah] < 0)
        { pc = 0x19e4b; break; }
    if (!r8[ah])
        { pc = 0x19e4b; break; }
    if (r8[ah] != 0x01)
        { pc = 0x19e6c; break; }
    memorySet(cs, 0xbda2, 0xc3);
    flags.carry = 0;
    return;
  case 0x19e6a:
    flags.carry = 1;
    return;
  case 0x19e6c:
    if (r8[ah] != 0x1c)
        { pc = 0x19e7d; break; }
    yield* sub_19ed0();
    r16[si] = 0x9a06;
    yield* sub_19eb5();
    { pc = 0x19e9b; break; }
    // gap 1 bytes
  case 0x19e7d:
    r16[si] = 0x99e5;
  case 0x19e80:
    r8[al] = lodsb_MemFwdDSSI();
    if (r8[al] == 0xff)
        { pc = 0x19eb2; break; }
    if (r8[al] != r8[ah])
        { pc = 0x19e80; break; }
    yield* sub_19ed0();
    r16[si]--;
    r16[si] -= 0x001a;
    r8[al] = memoryGet(ds, r16[si]);
    memorySet(ds, 0x9a00, r8[al]);
    r16[si] = 0x9a00;
    yield* sub_19eb5();
  case 0x19e9b:
    memorySet16(ds, 0x9a16, memoryGet16(ds, 0x9a16) + 1);
    if (memoryGet16(ds, 0x9a16) != 0x0005)
        { pc = 0x19eaf; break; }
    memorySet16(ds, 0x9a16, 0x0000);
    { pc = 0x19e22; break; }
  case 0x19eaf:
    { pc = 0x19e22; break; }
  case 0x19eb2:
    { pc = 0x19e22; break; }
    return;
  }
}
function* sub_19eb5() // 1040:9ab5
{
    r16[cx] = 0x0006;
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
}
function* sub_19ebb() // 1040:9abb
{
    r16[ax] = memoryGet16(ds, 0x9a16);
    r16[ax] <<= 1;
    r16[si] = 0x99a9;
    r16[si] += r16[ax];
    r16[si] = memoryGet16(ds, r16[si]);
    r16[di] = 0x9958;
    r16[cx] = 0x0005;
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
}
function* sub_19ed0() // 1040:9ad0
{
    r16[bx] = 0xb874;
    r16[cx] = memoryGet16(ds, 0x9a16);
    r16[bx] += r16[cx];
    memorySet(ds, r16[bx], r8[ah]);
}
function* sub_19ee5() // 1040:9ae5
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_10ee6();
    yield* sub_10d03();
    yield* sub_16b3b();
    r16[ax] = 0x0c0f;
    r16[si] = 0x9adc;
    yield* sub_107f1();
    yield* sub_109ee();
    r16[cx] = 0x01e0;
  case 0x19f01:
    push(r16[cx]);
    yield* sub_19b1c();
    yield* sub_19bdc();
    if (r8[al] & 0x10)
        { pc = 0x19f10; break; }
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x19f01; break; }
    return;
  case 0x19f10:
    r16[cx] = pop();
    return;
  }
}
function* sub_19f12() // 1040:9b12 +isolate
{
    yield* sub_10ee6();
    r16[ax] = 0x0004;
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[ax] = 0x0002;
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    yield* sub_19ee5();
    yield* sub_16d69();
    yield* sub_1a5e3();
    yield* sub_16cd7();
    yield* sub_1c359();
    return;
}
function* sub_19f8a() // 1040:9b8a +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    r16[ax] = 0x0c05;
    r16[si] = 0x9b5f;
    yield* sub_10836();
    r16[ax] = 0x0d0e;
    r16[si] = 0x9b7d;
    yield* sub_10836();
    yield* sub_10ee4();
  case 0x19fa4:
    r8[al] = memoryGet(cs, 0xb888);
    if (r8[al] != 0x15)
        { pc = 0x19fb0; break; }
    flags.carry = 1;
    { pc = 0x19fb5; break; }
    // gap 1 bytes
  case 0x19fb0:
    if (r8[al] != 0x31)
        { pc = 0x19fa4; break; }
    flags.carry = 0;
  case 0x19fb5:
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_1a102() // 1040:9d02
{
    r16[di] = 0x9ca8;
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r16[ax] <<= 1;
    r16[di] += r16[ax];
    r16[di] = memoryGet16(ds, r16[di]);
}
function* sub_1a111() // 1040:9d11
{
    r16[di] = 0x9cfa;
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r16[ax] <<= 1;
    r16[di] += r16[ax];
    r16[di] = memoryGet16(ds, r16[di]);
}
function* sub_1a120() // 1040:9d20
{
}
function* sub_1a121() // 1040:9d21
{
    yield* sub_1a102();
    memorySet16(ds, r16[di], 0x0001);
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    memorySet16(ds, r16[di] + 2, r16[ax]);
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    memorySet16(ds, r16[di] + 4, r16[ax]);
}
function* sub_1a137() // 1040:9d37
{
    yield* sub_1a102();
    memorySet16(ds, r16[di], 0x0000);
}
function* sub_1a13f() // 1040:9d3f
{
    yield* sub_1a102();
    memorySet16(ds, r16[di], 0x0002);
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    memorySet16(ds, r16[di] + 18, r16[ax]);
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    memorySet16(ds, r16[di] + 20, r16[ax]);
}
function* sub_1a155() // 1040:9d55
{
    yield* sub_1a102();
    r16[ax] = memoryGet16(ds, r16[bx]);
    r16[bx]++;
    r16[bx]++;
    r16[ax] += 0x2314;
    memorySet16(ds, r16[di] + 22, r16[ax]);
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 24, r16[ax]);
}
function* sub_1a168() // 1040:9d68
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    if (r8[al])
        { pc = 0x1a174; break; }
    yield* sub_10ea6();
    return;
  case 0x1a174:
    r8[ah] = 0;
    r16[ax]--;
    r16[ax] <<= 1;
    r16[si] = 0x2314;
    r16[si] = memoryGet16(ds, r16[si]);
    r16[si] += 0x2314;
    r16[si] += r16[ax];
    r16[si] = memoryGet16(ds, r16[si]);
    r16[si] += 0x2314;
    r16[si] += 0x0008;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r8[ah] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    yield* sub_10e23();
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r16[si] += r16[ax];
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r8[cl] = 0x05;
    r16[ax] <<= r8[cl];
    r16[si] += r16[ax];
    r8[cl] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r8[ch] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[di]);
    push(r16[si]);
    yield* sub_10e40();
    r16[si] = pop();
    r16[di] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_1a1bc() // 1040:9dbc
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r8[ah] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    r16[si] = r16[bx];
    push(r16[ax]);
    push(r16[bx]);
    push(r16[si]);
    yield* sub_10ec0();
    r16[si] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
  case 0x1a1ce:
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    if (r8[al] != 0xff)
        { pc = 0x1a1ce; break; }
    return;
  }
}
function* sub_1a1d7() // 1040:9dd7
{
    r8[al] = memoryGet(ds, r16[bx]);
    cbw();
    r16[bx]++;
    push(r16[bx]);
    memorySet16(ds, 0xbdf2, r16[ax]);
    yield* sub_1aecd();
    r16[bx] = pop();
}
function* sub_1a1e4() // 1040:9de4
{
    r16[bx]++;
}
function* sub_1a1e6() // 1040:9de6
{
    yield* sub_1a102();
    memorySet16(ds, r16[di], 0x0003);
    r16[ax] = memoryGet16(ds, r16[bx]);
    r16[bx]++;
    r16[bx]++;
    r16[ax] += 0x2314;
    memorySet16(ds, r16[di] + 6, r16[ax]);
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 8, r16[ax]);
}
function* sub_1a1fd() // 1040:9dfd
{
    yield* sub_1a111();
    memorySet16(ds, r16[di], 0x0001);
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    memorySet16(ds, r16[di] + 2, r16[ax]);
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    memorySet16(ds, r16[di] + 4, r16[ax]);
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    memorySet16(ds, r16[di] + 6, r16[ax]);
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    memorySet16(ds, r16[di] + 8, r16[ax]);
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    memorySet16(ds, r16[di] + 10, r16[ax]);
    memorySet16(ds, r16[di] + 12, 0x0000);
    r16[ax] = memoryGet16(ds, r16[bx]);
    r16[bx]++;
    r16[bx]++;
    r16[ax] += 0x2314;
    memorySet16(ds, r16[di] + 14, r16[ax]);
}
function* sub_1a234() // 1040:9e34
{
    yield* sub_1a111();
    memorySet16(ds, r16[di], 0x0000);
}
function* sub_1a23e() // 1040:9e3e
{
    r16[ax] = memoryGet16(ds, r16[bx]);
    r16[bx]++;
    r16[bx]++;
    r16[ax] += 0x2314;
    memorySet16(ds, 0x9e3c, r16[bx]);
    r16[bx] = r16[ax];
}
function* sub_1a24c() // 1040:9e4c
{
    r16[bx] = memoryGet16(ds, 0x9e3c);
}
function* sub_1a257() // 1040:9e57
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    memorySet16(ds, 0x9e51, sp);
    memorySet16(ds, 0x8bf0, 0x0000);
    memorySet16(ds, 0x9e55, r16[ax]);
    memorySet16(ds, 0x9e53, 0x0000);
    yield* sub_1c4ca();
    if (!(r8[al] & 0x10))
        { pc = 0x1a277; break; }
    memorySet16(ds, 0x9e53, 0x0001);
  case 0x1a277:
    yield* sub_16b3b();
    yield* sub_109ee();
    yield* sub_16b3b();
    r16[ax] = memoryGet16(ds, 0x9e55);
    r16[ax] <<= 1;
    r16[bx] = 0x2316;
    r16[bx] += r16[ax];
    r16[bx] = memoryGet16(ds, r16[bx]);
    r16[bx] += 0x2314;
    r16[di] = 0x9bd6;
    r16[cx] = 0x0008;
  case 0x1a297:
    memorySet16(ds, r16[di], 0x0000);
    r16[di] += 0x001a;
    if (--r16[cx])
        { pc = 0x1a297; break; }
    r16[di] = 0x9cb8;
    r16[cx] = 0x0004;
  case 0x1a2a6:
    memorySet16(ds, r16[di], 0x0000);
    r16[di] += 0x0010;
    if (--r16[cx])
        { pc = 0x1a2a6; break; }
  case 0x1a2af:
    r16[ax] = 0;
    r8[al] = memoryGet(ds, r16[bx]);
    r16[bx]++;
    if (!r8[al])
        { pc = 0x1a2c3; break; }
    r16[ax] <<= 1;
    r16[si] = 0x9bb8;
    r16[si] += r16[ax];
    switch (r16[ax])
    {
        case 0: yield* sub_1a120(); break;
        case 2: yield* sub_1a121(); break;
        case 4: yield* sub_1a137(); break;
        case 6: yield* sub_1a13f(); break;
        case 8: yield* sub_1a155(); break;
        case 10: yield* sub_1a168(); break;
        case 12: yield* sub_1a1bc(); break;
        case 14: yield* sub_1a1d7(); break;
        case 16: yield* sub_1a1e4(); break;
        case 18: yield* sub_1a2f6(); break;
        case 20: yield* sub_1a1e6(); break;
        case 22: yield* sub_1a1fd(); break;
        case 24: yield* sub_1a234(); break;
        case 26: yield* sub_1a23e(); break;
        case 28: yield* sub_1a24c(); break;
        default:
            stop("ind 1040:9ebf");
    }
    { pc = 0x1a2af; break; }
  case 0x1a2c3:
    sp += 2;
    return;
    return;
  }
}
function* sub_1a2c4() // 1040:9ec4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bx]);
    yield* sub_1c4ca();
    r16[bx] = pop();
    r16[dx] = memoryGet16(ds, 0x9e55);
    if (r16[dx])
        { pc = 0x1a2d3; break; }
    sp += 2;
    return;
  case 0x1a2d3:
    if (r16[dx] != 0x0001)
        { pc = 0x1a2f1; break; }
    if (!(r8[al] & 0x10))
        { pc = 0x1a2e8; break; }
    if (memoryGet16(ds, 0x9e53) == 0x0001)
        { pc = 0x1a2ee; break; }
    sp = memoryGet16(ds, 0x9e51);
    stop("stack_unbalanced");
    sp += 2;
    return;
  case 0x1a2e8:
    memorySet16(ds, 0x9e53, 0x0000);
  case 0x1a2ee:
    r8[al] &= 0xef;
    sp += 2;
    return;
  case 0x1a2f1:
    r8[al] &= 0xef;
    sp += 2;
    return;
  }
}
function* sub_1a2f6() // 1040:9ef6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_16b3b();
    memorySet16(ds, 0x9ef4, 0x0000);
    r16[cx] = 0;
    r8[cl] = memoryGet(ds, r16[bx]);
    r16[bx]++;
  case 0x1a304:
    push(r16[cx]);
    memorySet16(ds, 0x9ef4, memoryGet16(ds, 0x9ef4) + 1);
    if (memoryGet16(ds, 0x9ef4) != 0x0007)
        { pc = 0x1a316; break; }
    memorySet16(ds, 0x9ef4, 0x0000);
  case 0x1a316:
    yield* sub_1a389();
    yield* sub_1a437();
    yield* sub_1a2c4();
    if (!(r8[al] & 0x10))
        { pc = 0x1a32a; break; }
    if (memoryGet16(ds, 0x9ef4))
        { pc = 0x1a33d; break; }
  case 0x1a32a:
    yield* sub_10e7f();
    yield* sub_11376();
    yield* sub_19b1c();
    yield* sub_109ee();
    yield* sub_10ee4();
  case 0x1a33d:
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x1a304; break; }
    return;
  }
}
function* sub_1a389() // 1040:9f89
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] = 0x9bd6;
  case 0x1a38c:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16s[ax] < 0)
        { pc = 0x1a3ce; break; }
    if (!r16[ax])
        { pc = 0x1a3c9; break; }
    if (r16[ax] == 0x0001)
        { pc = 0x1a3c9; break; }
    if (r16[ax] != 0x0002)
        { pc = 0x1a3c2; break; }
    r16[ax] = memoryGet16(ds, r16[si] + 18);
    memorySet16(ds, r16[si] + 2, memoryGet16(ds, r16[si] + 2) + r16[ax]);
    if (signed16(memoryGet16(ds, r16[si] + 2)) < signed16(0x00e8))
        { pc = 0x1a3af; break; }
    memorySet16(ds, r16[si], 0x0000);
  case 0x1a3af:
    if (signed16(memoryGet16(ds, r16[si] + 2)) >= signed16(0x0000))
        { pc = 0x1a3b9; break; }
    memorySet16(ds, r16[si], 0x0000);
  case 0x1a3b9:
    r16[ax] = memoryGet16(ds, r16[si] + 20);
    memorySet16(ds, r16[si] + 4, memoryGet16(ds, r16[si] + 4) + r16[ax]);
    { pc = 0x1a3c9; break; }
    // gap 1 bytes
  case 0x1a3c2:
    push(r16[bx]);
    push(r16[si]);
    yield* sub_1a3cf();
    r16[si] = pop();
    r16[bx] = pop();
  case 0x1a3c9:
    r16[si] += 0x001a;
    { pc = 0x1a38c; break; }
  case 0x1a3ce:
    return;
  }
}
function* sub_1a3cf() // 1040:9fcf
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[bx]);
    r16[bx] = memoryGet16(ds, r16[si] + 6);
    r8[al] = memoryGet(ds, r16[bx]);
    if (r8[al])
        { pc = 0x1a3df; break; }
    r16[bx]++;
    r16[bx] = memoryGet16(ds, r16[bx]);
    memorySet16(ds, r16[si] + 6, r16[bx]);
  case 0x1a3df:
    r16[bx]++;
    r8[al] = memoryGet(ds, r16[bx]);
    r8[al] = sar8(r8[al], 0x01);
    r8[al] = sar8(r8[al], 0x01);
    r8[al] = sar8(r8[al], 0x01);
    r8[al] = sar8(r8[al], 0x01);
    if (r8[al] != 0x07)
        { pc = 0x1a3f0; break; }
    r8[al]++;
  case 0x1a3f0:
    cbw();
    memorySet16(ds, r16[si] + 2, memoryGet16(ds, r16[si] + 2) + r16[ax]);
    if (signed16(memoryGet16(ds, r16[si] + 2)) < signed16(0x00e8))
        { pc = 0x1a3ff; break; }
    memorySet16(ds, r16[si], 0x0000);
  case 0x1a3ff:
    if (signed16(memoryGet16(ds, r16[si] + 2)) >= signed16(0x0000))
        { pc = 0x1a409; break; }
    memorySet16(ds, r16[si], 0x0000);
  case 0x1a409:
    r8[al] = memoryGet(ds, r16[bx]);
    r8[al] &= 0x0f;
    if (!(r8[al] & 0x08))
        { pc = 0x1a413; break; }
    r8[al] |= 0xf0;
  case 0x1a413:
    if (r8[al] != 0x07)
        { pc = 0x1a419; break; }
    r8[al]++;
  case 0x1a419:
    cbw();
    memorySet16(ds, r16[si] + 4, memoryGet16(ds, r16[si] + 4) + r16[ax]);
    r16[bx]--;
    r8[al] = memoryGet(ds, r16[bx]);
    cbw();
    memorySet16(ds, r16[si] + 8, memoryGet16(ds, r16[si] + 8) + 1);
    if (r16[ax] == memoryGet16(ds, r16[si] + 8))
        { pc = 0x1a42b; break; }
    if (r16[ax] >= memoryGet16(ds, r16[si] + 8))
        { pc = 0x1a435; break; }
  case 0x1a42b:
    memorySet16(ds, r16[si] + 8, 0x0000);
    r16[bx]++;
    r16[bx]++;
    memorySet16(ds, r16[si] + 6, r16[bx]);
  case 0x1a435:
    r16[bx] = pop();
    return;
  }
}
function* sub_1a437() // 1040:a037
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] = 0x9bd6;
  case 0x1a43a:
    r16[ax] = memoryGet16(ds, r16[si]);
    if (r16s[ax] < 0)
        { pc = 0x1a44e; break; }
    if (!r16[ax])
        { pc = 0x1a449; break; }
    push(r16[bx]);
    push(r16[si]);
    yield* sub_1718e();
    r16[si] = pop();
    r16[bx] = pop();
  case 0x1a449:
    r16[si] += 0x001a;
    { pc = 0x1a43a; break; }
  case 0x1a44e:
    return;
  }
}
function* sub_1a44f() // 1040:a04f
{
    r16[ax] = memoryGet16(ds, 0x0062);
    r16[cx] = 0x0000;
    r16[dx] = 0x00c1;
    yield* sub_1a65b();
}
function* sub_1a45c() // 1040:a05c
{
    r16[ax] = 0x1040;
    r16[cx] = 0x3374;
    r16[dx] = 0x006b;
    yield* sub_1a65b();
    r16[ax] = 0x1040;
    r16[cx] = 0x3974;
    r16[dx] = 0x0077;
    yield* sub_1a65b();
    r16[ax] = 0x1040;
    r16[cx] = 0x3c74;
    r16[dx] = 0x0084;
    yield* sub_1a65b();
    r16[ax] = 0x1040;
    r16[cx] = 0x4c74;
    r16[dx] = 0x0091;
    yield* sub_1a65b();
    r16[ax] = 0x1040;
    r16[cx] = 0x53f4;
    r16[dx] = 0x009d;
    yield* sub_1a65b();
    r16[ax] = 0x1040;
    r16[cx] = 0x1180;
    r16[dx] = 0x00aa;
    yield* sub_1a65b();
    r16[ax] = 0x1040;
    r16[cx] = 0x2314;
    r16[dx] = 0x00b6;
    yield* sub_1a65b();
}
function* sub_1a54a() // 1040:a14a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] = 0x006b;
    r16[ax] = memoryGet16(ds, 0x8bec);
    r16[ax]--;
    r16[ax] += 0x0031;
  case 0x1a554:
    r8[ah] = memoryGet(ds, r16[si]);
    if (r8[ah] == 0xff)
        { pc = 0x1a56a; break; }
    if (r8s[ah] < signed8(0x31))
        { pc = 0x1a567; break; }
    if (r8s[ah] > signed8(0x35))
        { pc = 0x1a567; break; }
    memorySet(ds, r16[si], r8[al]);
  case 0x1a567:
    r16[si]++;
    { pc = 0x1a554; break; }
  case 0x1a56a:
    return;
  }
}
function* sub_1a56b() // 1040:a16b
{
    yield* sub_10d03();
    r16[ax] = 0x0a0c;
    r16[si] = 0x94c1;
    yield* sub_107ac();
    r16[ax] = 0x0b0c;
    r16[si] = 0x94e1;
    yield* sub_107ac();
    r16[ax] = 0x0c0c;
    r16[si] = 0x9501;
    yield* sub_107ac();
    yield* sub_109ee();
}
function* sub_1a592() // 1040:a192
{
    push(cs);
    ds = pop();
    r16[di] = 0x66f6;
    r16[cx] = 0x0006;
    r8[al] = 0x0a;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
    memorySet16(ds, 0x6610, 0x0006);
    r16[di] = 0x66fd;
    r16[cx] = 0x0006;
    r8[al] = 0x0b;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
    memorySet16(ds, 0x6612, 0x0006);
    r16[di] = 0x6704;
    r16[cx] = 0x0006;
    r8[al] = 0x0c;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
    memorySet16(ds, 0x6614, 0x0006);
    yield* sub_1a5f0();
    yield* sub_109d3();
    memorySet16(ds, 0x8bec, 0x0001);
    memorySet16(ds, 0x7e16, 0x0000);
    memorySet16(ds, 0x7e18, 0x0000);
    memorySet16(ds, 0x7e00, 0x0000);
    push(cs);
    ds = pop();
    r16[di] = 0x6616;
    r16[cx] = 0x0006;
    r8[al] = 0;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
}
function* sub_1a5e3() // 1040:a1e3
{
    push(cs);
    ds = pop();
    r16[di] = 0x6616;
    r16[cx] = 0x0006;
    r8[al] = 0;
    for (; r16[cx] != 0; --r16[cx]) stosb_MemFwdESDI(r8[al]);
}
function* sub_1a5f0() // 1040:a1f0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0;
    memorySet16(ds, 0x0b00, r16[ax]);
    memorySet16(ds, 0x0b38, r16[ax]);
    r16[ax]++;
    memorySet16(ds, 0x0b1c, r16[ax]);
    r16[ax]--;
    r16[di] = 0x0b56;
  case 0x1a600:
    r16[dx] = memoryGet16(ds, r16[di]);
    if (r16s[dx] < 0)
        { pc = 0x1a60c; break; }
    stosw_MemFwdESDI(r16[ax]);
    r16[di] += 0x0032;
    { pc = 0x1a600; break; }
  case 0x1a60c:
    r16[di] = 0x0c28;
  case 0x1a60f:
    r16[dx] = memoryGet16(ds, r16[di]);
    if (r16s[dx] < 0)
        { pc = 0x1a61b; break; }
    stosw_MemFwdESDI(r16[ax]);
    r16[di] += 0x0032;
    { pc = 0x1a60f; break; }
  case 0x1a61b:
    return;
  }
}
function* sub_1a65b() // 1040:a25b
{
    memorySet16(ds, 0xa255, r16[ax]);
    memorySet16(ds, 0xa257, r16[cx]);
    yield* sub_1a67b();
    push(ds);
    r16[bx] = memoryGet16(ds, 0xa259);
    r16[ax] = memoryGet16(ds, 0xa255);
    r16[dx] = memoryGet16(ds, 0xa257);
    ds = r16[ax];
    yield* sub_1a693();
    ds = pop();
    yield* sub_1a69d();
}
function* sub_1a67b() // 1040:a27b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[ah] = 0x3d;
    r8[al] = 0x00;
    interrupt(0x21);
    if (flags.carry)
        { pc = 0x1a6fb; break; }
    push(ds);
    push(r16[ax]);
    r16[ax] = 0x1040;
    ds = r16[ax];
    r16[ax] = pop();
    memorySet16(ds, 0xa259, r16[ax]);
    ds = pop();
    return;
    // gap 104 bytes
  case 0x1a6fb:
    push(ds);
    r16[ax] = 0x0003;
    interrupt(0x10);
    r16[ax] = 0x1040;
    ds = r16[ax];
    r16[dx] = 0xa21c;
    r8[ah] = 0x09;
    interrupt(0x21);
    ds = pop();
    r16[ax] = 0x1040;
    ds = r16[ax];
    memorySet(ds, 0xb888, 0x00);
  case 0x1a719:
    r8[al] = memoryGet(ds, 0xb888);
    if (!r8[al])
        { pc = 0x1a719; break; }
    yield* sub_196f3();
    return;
  }
}
function* sub_1a693() // 1040:a293
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[ah] = 0x3f;
    r16[cx] = 0xffff;
    interrupt(0x21);
    if (flags.carry)
        { pc = 0x1a6fb; break; }
    return;
    // gap 94 bytes
  case 0x1a6fb:
    push(ds);
    r16[ax] = 0x0003;
    interrupt(0x10);
    r16[ax] = 0x1040;
    ds = r16[ax];
    r16[dx] = 0xa21c;
    r8[ah] = 0x09;
    interrupt(0x21);
    ds = pop();
    r16[ax] = 0x1040;
    ds = r16[ax];
    memorySet(ds, 0xb888, 0x00);
  case 0x1a719:
    r8[al] = memoryGet(ds, 0xb888);
    if (!r8[al])
        { pc = 0x1a719; break; }
    yield* sub_196f3();
    return;
  }
}
function* sub_1a69d() // 1040:a29d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[ah] = 0x3e;
    r16[bx] = memoryGet16(ds, 0xa259);
    interrupt(0x21);
    if (flags.carry)
        { pc = 0x1a6fb; break; }
    return;
    // gap 83 bytes
  case 0x1a6fb:
    push(ds);
    r16[ax] = 0x0003;
    interrupt(0x10);
    r16[ax] = 0x1040;
    ds = r16[ax];
    r16[dx] = 0xa21c;
    r8[ah] = 0x09;
    interrupt(0x21);
    ds = pop();
    r16[ax] = 0x1040;
    ds = r16[ax];
    memorySet(ds, 0xb888, 0x00);
  case 0x1a719:
    r8[al] = memoryGet(ds, 0xb888);
    if (!r8[al])
        { pc = 0x1a719; break; }
    yield* sub_196f3();
    return;
  }
}
function* sub_1ad6e() // 1040:a96e
{
    r8[ah] = 0;
    r16[ax] <<= 1;
    r16[bx] = r16[ax];
    r16[ax] <<= 1;
    r16[ax] += r16[bx];
    r16[bx] = 0xa64d;
    r16[bx] += r16[ax];
    r16[bx] = memoryGet16(ds, r16[bx]);
    memorySet16(ds, 0xa854, r16[bx]);
    memorySet(ds, 0xa852, 0x01);
    memorySet(ds, 0xa84e, 0x00);
    memorySet16(ds, 0xa850, 0x0001);
    memorySet16(ds, 0xa856, 0x0000);
    memorySet16(ds, 0xa858, 0x0000);
    memorySet(ds, 0xa85a, 0x00);
    memorySet16(ds, 0xa85c, 0x0000);
    memorySet(ds, 0xa85e, 0xff);
}
function* sub_1adb0() // 1040:a9b0
{
    r8[al] = in8(0x61);
    r8[al] &= 0xfd;
    out8(0x61, r8[al]);
}
function* sub_1adcb() // 1040:a9cb
{
    push(ds);
    push(es);
    r8[ah] = 0x35;
    r8[al] = 0x08;
    interrupt(0x21);
    push(r16[ax]);
    r16[ax] = 0x1040;
    ds = r16[ax];
    r16[ax] = pop();
    memorySet16(ds, 0xb88e, es);
    memorySet16(cs, 0xaa7b, es);
    memorySet16(ds, 0xb890, r16[bx]);
    memorySet16(cs, 0xaa79, r16[bx]);
    r8[ah] = 0x25;
    r8[al] = 0x08;
    push(cs);
    ds = pop();
    r16[dx] = 0xaa28;
    interrupt(0x21);
    r16[ax] = 0x4000;
    out8(0x40, r8[al]);
    r8[al] = r8[ah];
    out8(0x40, r8[al]);
    es = pop();
    ds = pop();
}
function* sub_1ae03() // 1040:aa03
{
    push(ds);
    push(r16[ax]);
    r16[ax] = 0x0000;
    out8(0x40, r8[al]);
    r8[al] = r8[ah];
    out8(0x40, r8[al]);
    r16[ax] = 0x1040;
    ds = r16[ax];
    r16[dx] = memoryGet16(ds, 0xb890);
    ds = memoryGet16(ds, 0xb88e);
    r8[ah] = 0x25;
    r8[al] = 0x08;
    interrupt(0x21);
    r16[ax] = pop();
    ds = pop();
}
function* sub_1ae81() // 1040:aa81
{
  var pc = 0;
  var temp_cf;
  while (1) switch(pc)
  {
  case 0:
    r8[al] = memoryGet(ds, 0xaa26);
  case 0x1ae84:
    yield* sync();
    if (r8[al] == memoryGet(ds, 0xaa26))
        { pc = 0x1ae84; break; }
    r8[al] = memoryGet(ds, 0xaa26);
  case 0x1ae8d:
    flags.carry = memoryGet(ds, 0xaa7d) + 0x01 >= 0x100;
    memorySet(ds, 0xaa7d, memoryGet(ds, 0xaa7d) + 0x01);
    temp_cf = flags.carry;
    temp_cf = memoryGet(ds, 0xaa7e) + 0x00 + flags.carry >= 0x100;
    memorySet(ds, 0xaa7e, memoryGet(ds, 0xaa7e) + (0x00 + flags.carry));
    flags.carry = temp_cf;
    temp_cf = flags.carry;
    temp_cf = memoryGet(ds, 0xaa7f) + 0x00 + flags.carry >= 0x100;
    memorySet(ds, 0xaa7f, memoryGet(ds, 0xaa7f) + (0x00 + flags.carry));
    flags.carry = temp_cf;
    memorySet(ds, 0xaa80, memoryGet(ds, 0xaa80) + (0x00 + flags.carry));
    if (r8[al] == memoryGet(ds, 0xaa26))
        { pc = 0x1ae8d; break; }
    r16[ax] = memoryGet16(ds, 0xaa7d);
    if (r16s[ax] < signed16(0x0b00))
        { pc = 0x1aeb6; break; }
    memorySet16(ds, 0x96f4, 0x0003);
    return;
  case 0x1aeb6:
    if (r16s[ax] < signed16(0x0700))
        { pc = 0x1aec2; break; }
    memorySet16(ds, 0x96f4, 0x0002);
    return;
  case 0x1aec2:
    memorySet16(ds, 0x96f4, 0x0001);
    yield* sub_10ee8();
    return;
  }
}
function* sub_1aecd() // 1040:aacd
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (r16s[ax] < signed16(0x000b))
        { pc = 0x1aed5; break; }
    { pc = 0x1bb82; break; }
  case 0x1aed5:
    if (memoryGet16(ds, 0xab2b) == 0x0001)
        { pc = 0x1aee0; break; }
    yield* sub_1ad6e();
    return;
  case 0x1aee0:
    r16[bx] = r16[ax];
    yield* sub_1b95d();
    return;
    // gap 3228 bytes
  case 0x1bb82:
    push(r16[si]);
    push(r16[di]);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    ds = r16[bx];
    es = r16[bx];
    r16[ax] -= 0x000b;
    if (memoryGet16(ds, 0xab2b) == 0x0001)
        { pc = 0x1bb9e; break; }
    { pc = 0x1bc4a; break; }
  case 0x1bb9e:
    if (memoryGet(ds, 0xa85e) != 0xff)
        { pc = 0x1bba8; break; }
    { pc = 0x1bc40; break; }
  case 0x1bba8:
    r16[ax] += r16[ax];
    r16[ax] += r16[ax];
    r16[si] = 0xb181;
    r16[si] += r16[ax];
    r16[ax] = memoryGet16(ds, 0xab27);
    r16[ax]--;
    if (r16s[ax] >= 0)
        { pc = 0x1bbba; break; }
    r16[ax] = 0x0005;
  case 0x1bbba:
    memorySet16(ds, 0xab27, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[si] + 2);
    push(r16[ax]);
    r16[si] = memoryGet16(ds, r16[si]);
    push(r16[si]);
    r16[ax] = memoryGet16(ds, 0xab27);
    memorySet16(ds, 0xb3a7, r16[ax]);
    r16[si]++;
    r16[si]++;
    memorySet16(ds, 0xb3a9, r16[si]);
    memorySet16(ds, 0xb3ab, ds);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    r16[si] = 0x0015;
    r16[bx] = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[ax] = memoryGet16(ds, 0xab27);
    memorySet16(ds, 0xb3a7, r16[ax]);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    r16[si] = 0x0014;
    r16[bx] = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[ax] = memoryGet16(ds, 0xab27);
    memorySet16(ds, 0xb3a7, r16[ax]);
    r16[si] = pop();
    r16[ax] = pop();
    cbw();
    memorySet16(ds, 0xb3a9, r16[ax]);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    r16[si] = 0x0013;
    r16[bx] = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
  case 0x1bc40:
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[di] = pop();
    r16[si] = pop();
    return;
  case 0x1bc4a:
    if (memoryGet(ds, 0xa85e) != 0xff)
        { pc = 0x1bc53; break; }
    { pc = 0x1bc40; break; }
  case 0x1bc53:
    r16[dx] = memoryGet16(ds, 0xab29);
    if (!r16[dx])
        { pc = 0x1bc65; break; }
    if (r16[ax] == 0x001a)
        { pc = 0x1bc40; break; }
    if (r16[ax] == 0x001b)
        { pc = 0x1bc40; break; }
  case 0x1bc65:
    r16[ax] += r16[ax];
    r16[si] = 0xb32d;
    r16[si] += r16[ax];
    r16[si] = memoryGet16(ds, r16[si]);
    memorySet16(ds, 0xab29, r16[si]);
    { pc = 0x1bc40; break; }
    return;
  }
}
function* sub_1b95d() // 1040:b55d
{
    r16[ax] = cs;
    ds = r16[ax];
    memorySet16(ds, 0xb55b, 0x0001);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    r16[si] = 0x0000;
    r16[bx] = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    memorySet16(ds, 0xb3a7, 0x0001);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    r16[si] = 0x0006;
    r16[bx] = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[bx] += r16[bx];
    r16[ax] = r16[bx];
    r16[bx] += r16[bx];
    r16[bx] += r16[ax];
    r16[bx] += 0xa64d;
    r16[di] = 0xb369;
    memorySet16(ds, r16[di], 0x00ff);
    r16[ax] = memoryGet16(ds, r16[bx]);
    memorySet16(ds, r16[di] + 2, r16[ax]);
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 16, r16[ax]);
    memorySet16(ds, r16[di] + 12, r16[ax]);
    memorySet16(ds, r16[di] + 18, r16[ax]);
    push(r16[bx]);
    yield* sub_1bb3f();
    r16[bx] = pop();
    r16[bx]++;
    r16[bx]++;
    r16[di] = 0xb37d;
    memorySet16(ds, r16[di], 0x00ff);
    r16[ax] = memoryGet16(ds, r16[bx]);
    memorySet16(ds, r16[di] + 2, r16[ax]);
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 16, r16[ax]);
    r16[ax] = 0x0001;
    memorySet16(ds, r16[di] + 12, r16[ax]);
    memorySet16(ds, r16[di] + 18, r16[ax]);
    push(r16[bx]);
    yield* sub_1bb3f();
    r16[bx] = pop();
    r16[bx]++;
    r16[bx]++;
    r16[di] = 0xb391;
    memorySet16(ds, r16[di], 0x00ff);
    r16[ax] = memoryGet16(ds, r16[bx]);
    memorySet16(ds, r16[di] + 2, r16[ax]);
    r16[ax] = 0;
    memorySet16(ds, r16[di] + 16, r16[ax]);
    r16[ax] = 0x0002;
    memorySet16(ds, r16[di] + 12, r16[ax]);
    memorySet16(ds, r16[di] + 18, r16[ax]);
    yield* sub_1bb3f();
    memorySet16(ds, 0xb55b, 0x0000);
}
function* sub_1bb3f() // 1040:b73f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x1bb3f; break; }
  case 0x1ba58:
    r8[al] = memoryGet(ds, r16[si]);
    if (r8s[al] >= 0)
        { pc = 0x1bac7; break; }
    if (r8[al] != 0xff)
        { pc = 0x1ba72; break; }
    memorySet16(ds, r16[di] + 10, memoryGet16(ds, r16[di] + 10) - 1);
    if (memoryGet16(ds, r16[di] + 10))
        { pc = 0x1ba6a; break; }
    { pc = 0x1bb3f; break; }
  case 0x1ba6a:
    r16[si] = memoryGet16(ds, r16[di] + 4);
    memorySet16(ds, r16[di] + 6, r16[si]);
    { pc = 0x1ba58; break; }
  case 0x1ba72:
    r8[al] &= 0x7f;
    r8[al]--;
    r8[al] += r8[al];
    r8[ah] = 0;
    r16[bx] = r16[ax];
    r16[bx] += 0xb3b3;
    r16[bx] = memoryGet16(ds, r16[bx]);
    r8[al] = memoryGet(ds, r16[bx]);
    if (!r8[al])
        { pc = 0x1ba90; break; }
    r8[al] = memoryGet(ds, r16[bx] + 1);
    r8[ah] = 0;
    memorySet16(ds, r16[di] + 18, r16[ax]);
  case 0x1ba90:
    r16[bx] += 0x0002;
    memorySet16(ds, 0xb3a9, r16[bx]);
    r16[ax] = cs;
    memorySet16(ds, 0xb3ab, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[di] + 18);
    memorySet16(ds, 0xb3a7, r16[ax]);
    push(r16[di]);
    push(r16[si]);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    r16[si] = 0x0015;
    r16[bx] = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[si]++;
    { pc = 0x1ba58; break; }
  case 0x1bac7:
    memorySet16(ds, r16[di] + 8, 0x0000);
    memorySet16(ds, r16[di] + 6, r16[si]);
    r8[al] -= 0x20;
    cbw();
    r16[ax] += memoryGet16(ds, r16[di] + 16);
    memorySet16(ds, 0xb3a9, r16[ax]);
    r16[ax] = memoryGet16(ds, r16[di] + 14);
    memorySet16(ds, 0xb3a7, r16[ax]);
    r16[ax] = cs;
    es = r16[ax];
    r16[bx] = 0xb3a7;
    push(r16[di]);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    r16[si] = 0x0014;
    r16[bx] = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[di] = pop();
    r16[ax] = memoryGet16(ds, 0xb3a9);
    r16[ax] -= memoryGet16(ds, r16[di] + 16);
    if (r16[ax] == 0x001d)
        { pc = 0x1bb3e; break; }
    r16[ax] = memoryGet16(ds, r16[di] + 18);
    memorySet16(ds, r16[di] + 14, r16[ax]);
    memorySet16(ds, 0xb3a7, r16[ax]);
    r16[ax] = cs;
    es = r16[ax];
    r16[bx] = 0xb3a7;
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    push(r16[di]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[bx] = cs;
    es = r16[bx];
    r16[si] = 0x0013;
    r16[bx] = 0xb3a7;
    interrupt(0x65);
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[di] = pop();
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
  case 0x1bb3e:
    return;
  case 0x1bb3f:
    memorySet16(ds, r16[di] + 10, 0x0001);
    r16[si] = memoryGet16(ds, r16[di] + 2);
  case 0x1bb47:
    r8[al] = memoryGet(ds, r16[si]);
    if (r8[al] != 0xff)
        { pc = 0x1bb52; break; }
    memorySet16(ds, r16[di], 0x0000);
    return;
  case 0x1bb52:
    if (r8s[al] >= 0)
        { pc = 0x1bb6c; break; }
    if (r8[al] != 0xc0)
        { pc = 0x1bb64; break; }
    r16[si]++;
    r8[al] = memoryGet(ds, r16[si]);
    cbw();
    memorySet16(ds, r16[di] + 16, r16[ax]);
    r16[si]++;
    { pc = 0x1bb47; break; }
  case 0x1bb64:
    r8[al] &= 0x7f;
    memorySet(ds, r16[di] + 10, r8[al]);
    r16[si]++;
    { pc = 0x1bb47; break; }
  case 0x1bb6c:
    r16[si]++;
    memorySet16(ds, r16[di] + 2, r16[si]);
    r8[ah] = 0;
    r16[ax] += r16[ax];
    r16[bx] = r16[ax];
    r16[bx] += 0xa5e1;
    r16[si] = memoryGet16(ds, r16[bx]);
    memorySet16(ds, r16[di] + 4, r16[si]);
    { pc = 0x1ba58; break; }
    return;
  }
}
function* sub_1bc92() // 1040:b892
{
    push(ds);
    push(es);
    r8[ah] = 0x35;
    r8[al] = 0x09;
    interrupt(0x21);
    r16[ax] = 0x1040;
    ds = r16[ax];
    memorySet16(ds, 0xb88a, es);
    memorySet16(ds, 0xb88c, r16[bx]);
    r8[ah] = 0x25;
    r8[al] = 0x09;
    r16[dx] = cs;
    ds = r16[dx];
    r16[dx] = 0xb8cd;
    interrupt(0x21);
    es = pop();
    ds = pop();
}
function* sub_1bcb7() // 1040:b8b7
{
    push(ds);
    r16[ax] = 0x1040;
    ds = r16[ax];
    r16[dx] = memoryGet16(ds, 0xb88c);
    ds = memoryGet16(ds, 0xb88a);
    r8[ah] = 0x25;
    r8[al] = 0x09;
    interrupt(0x21);
    ds = pop();
}
function* sub_1bf7c() // 1040:bb7c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[dx] = 0x0201;
    r16[ax] = 0;
    r16[cx] = 0;
    r8[al] = in8(r16[dx]);
    r16[ax] &= 0x0030;
    if (r16[ax] == 0x0030)
        { pc = 0x1bf8f; break; }
    r16[cx] = 0xffff;
  case 0x1bf8f:
    push(r16[cx]);
    r8[bl] = 0x01;
    yield* sub_1bfa0();
    push(r16[cx]);
    r8[bl] = 0x02;
    yield* sub_1bfa0();
    r16[dx] = r16[cx];
    r16[cx] = pop();
    r16[bx] = pop();
    return;
  }
}
function* sub_1bfa0() // 1040:bba0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    return;
    push(r16[dx]);
    flags.interrupts = 0;
    r8[al] = 0x00;
    out8(0x43, r8[al]);
    { pc = 0x1bfa8; break; }
  case 0x1bfa8:
    r8[al] = in8(0x40);
    r8[ah] = r8[al];
    { pc = 0x1bfae; break; }
  case 0x1bfae:
    r8[al] = in8(0x40);
    r8[tl] = r8[al];
    r8[al] = r8[ah];
    r8[ah] = r8[tl];
    push(r16[ax]);
    r16[cx] = 0x04ff;
    out8(r16[dx], r8[al]);
    { pc = 0x1bfb9; break; }
  case 0x1bfb9:
    r8[al] = in8(r16[dx]);
    if (--r16[cx] && (r8[bl] & r8[al]))
        { pc = 0x1bfb9; break; }
    flags.zero = r16[cx] == 0x0000;
    r16[cx] = pop();
    if (!flags.zero)
        { pc = 0x1bfc9; break; }
    r16[cx] = 0;
    { pc = 0x1bff7; break; }
    // gap 1 bytes
  case 0x1bfc9:
    r8[al] = 0x00;
    out8(0x43, r8[al]);
    { pc = 0x1bfcf; break; }
  case 0x1bfcf:
    r8[al] = in8(0x40);
    r8[ah] = r8[al];
    { pc = 0x1bfd5; break; }
  case 0x1bfd5:
    r8[al] = in8(0x40);
    r8[tl] = r8[al];
    r8[al] = r8[ah];
    r8[ah] = r8[tl];
    if (r16[cx] >= r16[ax])
        { pc = 0x1bfe9; break; }
    push(r16[dx]);
    r16[dx] = 0xffff;
    r16[dx] -= r16[ax];
    r16[cx] += r16[dx];
    r16[dx] = pop();
    { pc = 0x1bfeb; break; }
    // gap 1 bytes
  case 0x1bfe9:
    r16[cx] -= r16[ax];
  case 0x1bfeb:
    r16[cx] &= 0x1ff0;
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[cx] >>= 1;
    r16[cx] >>= 1;
  case 0x1bff7:
    flags.interrupts = 1;
    r16[dx] = 0x0201;
    push(r16[cx]);
    push(r16[ax]);
    r16[cx] = 0x04ff;
  case 0x1c000:
    r8[al] = in8(r16[dx]);
    if (--r16[cx] && (r8[al] & 0x0f))
        { pc = 0x1c000; break; }
    r16[ax] = pop();
    r16[cx] = pop();
    r16[dx] = pop();
    return;
  }
}
function* sub_1c0a8() // 1040:bca8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_10d03();
    r16[bx] = 0xbc80;
    yield* sub_19c43();
    yield* sub_109ee();
    r16[bx] = 0xbc80;
    yield* sub_19c43();
    yield* sub_109ee();
  case 0x1c0c0:
    yield* sub_1bf7c();
    r16[bx] &= 0x0003;
    if (r16[bx])
        { pc = 0x1c0c0; break; }
  case 0x1c0c8:
    yield* sub_1bf7c();
    r16[bx] &= 0x0003;
    if (!r16[bx])
        { pc = 0x1c0c8; break; }
    memorySet16(ds, 0xbc98, r16[cx]);
    memorySet16(ds, 0xbc9a, r16[dx]);
    yield* sub_10d03();
    r16[bx] = 0xbc88;
    yield* sub_19c43();
    yield* sub_109ee();
    r16[bx] = 0xbc88;
    yield* sub_19c43();
    yield* sub_109ee();
  case 0x1c0f0:
    yield* sub_1bf7c();
    r16[bx] &= 0x0003;
    if (r16[bx])
        { pc = 0x1c0f0; break; }
  case 0x1c0f8:
    yield* sub_1bf7c();
    r16[bx] &= 0x0003;
    if (!r16[bx])
        { pc = 0x1c0f8; break; }
    memorySet16(ds, 0xbc9c, r16[cx]);
    memorySet16(ds, 0xbc9e, r16[dx]);
    yield* sub_10d03();
    r16[bx] = 0xbc90;
    yield* sub_19c43();
    yield* sub_109ee();
    r16[bx] = 0xbc90;
    yield* sub_19c43();
    yield* sub_109ee();
  case 0x1c120:
    yield* sub_1bf7c();
    r16[bx] &= 0x0003;
    if (r16[bx])
        { pc = 0x1c120; break; }
  case 0x1c128:
    yield* sub_1bf7c();
    r16[bx] &= 0x0003;
    if (!r16[bx])
        { pc = 0x1c128; break; }
    memorySet16(ds, 0xbca0, r16[cx]);
    memorySet16(ds, 0xbca2, r16[dx]);
    r16[ax] = memoryGet16(ds, 0xbc9c);
    r16[ax] -= memoryGet16(ds, 0xbc98);
    r16[bx] = memoryGet16(ds, 0xbc9e);
    r16[bx] -= memoryGet16(ds, 0xbc9a);
    r8[dl] = 0x06;
    idiv8(r8[dl]);
    r16[ax] &= 0x00ff;
    cbw();
    push(r16[ax]);
    r16[ax] = r16[bx];
    r8[dl] = 0x06;
    idiv8(r8[dl]);
    r8[al] &= 0xff;
    cbw();
    r16[bx] = r16[ax];
    r16[ax] = pop();
    memorySet16(ds, 0xbca4, r16[ax]);
    memorySet16(ds, 0xbca6, r16[bx]);
    return;
  }
}
function* sub_1c164() // 1040:bd64
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_1c0a8();
    yield* sub_1bf7c();
    r16[cx] |= r16[dx];
    if (r16[cx])
        { pc = 0x1c175; break; }
    memorySet(cs, 0xbda2, 0xc3);
    return;
  case 0x1c175:
    r16[ax] = memoryGet16(ds, 0xbca0);
    r16[dx] = memoryGet16(ds, 0xbca4);
    r16[ax] += r16[dx];
    memorySet16(ds, 0xb87e, r16[ax]);
    r16[ax] = memoryGet16(ds, 0xbca0);
    r16[dx] = -r16[dx];
    r16[ax] += r16[dx];
    memorySet16(ds, 0xb880, r16[ax]);
    r16[ax] = memoryGet16(ds, 0xbca2);
    r16[dx] = memoryGet16(ds, 0xbca6);
    r16[ax] += r16[dx];
    memorySet16(ds, 0xb87c, r16[ax]);
    r16[ax] = memoryGet16(ds, 0xbca2);
    r16[dx] = -r16[dx];
    r16[ax] += r16[dx];
    memorySet16(ds, 0xb87a, r16[ax]);
    return;
  }
}
function* sub_1c1a2() // 1040:bda2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    return;
    r16[ax] = 0x1040;
    ds = r16[ax];
    yield* sub_1bf7c();
    r16[bx] &= 0x0003;
    if (!r16[bx])
        { pc = 0x1c1b7; break; }
    r16[bx] = 0;
    r8[bl] |= 0x10;
    { pc = 0x1c1b9; break; }
    // gap 1 bytes
  case 0x1c1b7:
    r16[bx] = 0;
  case 0x1c1b9:
    if (r16[cx] < memoryGet16(ds, 0xb87e))
        { pc = 0x1c1c5; break; }
    r8[bl] |= 0x01;
    { pc = 0x1c1ce; break; }
    // gap 1 bytes
  case 0x1c1c5:
    if (r16[cx] >= memoryGet16(ds, 0xb880))
        { pc = 0x1c1ce; break; }
    r8[bl] |= 0x02;
  case 0x1c1ce:
    if (r16[dx] >= memoryGet16(ds, 0xb87a))
        { pc = 0x1c1da; break; }
    r8[bl] |= 0x08;
    { pc = 0x1c1e3; break; }
    // gap 1 bytes
  case 0x1c1da:
    if (r16[dx] < memoryGet16(ds, 0xb87c))
        { pc = 0x1c1e3; break; }
    r8[bl] |= 0x04;
  case 0x1c1e3:
    memorySet(ds, 0xb882, r8[bl]);
    r8[bh] = memoryGet(ds, 0xb886);
    r8[bl] |= r8[bh];
    memorySet(ds, 0xb884, r8[bl]);
    return;
  }
}
function* sub_1c276() // 1040:be76 +entry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    flags.direction = 0;
    r8[ah] = 0x4a;
    r16[bx] = 0x0e00;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x1c283; break; }
    yield* sub_19731();
    return;
  case 0x1c283:
    r16[ax] = cs;
    es = r16[ax];
    r16[si] = 0x0080;
    r16[di] = 0x1040;
    es = r16[di];
    r16[di] = 0xbdf6;
    r8[cl] = memoryGet(ds, r16[si]);
    r8[ch] = 0;
    r16[cx]++;
    flags.direction = 0;
    for (; r16[cx] != 0; --r16[cx]) movsb_MemFwdESDI_MemFwdDSSI();
    push(es);
    ds = pop();
    r16[si] = 0xbdf6;
    r16[cx] = 0x0080;
  case 0x1c2a2:
    r8[al] = memoryGet(ds, r16[si]);
    r16[si]++;
    if (r8[al] == 0x2f)
        { pc = 0x1c2ae; break; }
  case 0x1c2a9:
    if (--r16[cx])
        { pc = 0x1c2a2; break; }
    { pc = 0x1c2e2; break; }
    // gap 1 bytes
  case 0x1c2ae:
    r8[al] = memoryGet(ds, r16[si]);
    if (r8[al] == 0x63)
        { pc = 0x1c2d3; break; }
    if (r8[al] == 0x43)
        { pc = 0x1c2d3; break; }
    if (r8[al] == 0x65)
        { pc = 0x1c2ca; break; }
    if (r8[al] == 0x45)
        { pc = 0x1c2ca; break; }
    if (r8[al] == 0x74)
        { pc = 0x1c2e5; break; }
    if (r8[al] == 0x54)
        { pc = 0x1c2e5; break; }
    { pc = 0x1c2a9; break; }
  case 0x1c2ca:
    memorySet16(ds, 0x2f67, 0x2f4f);
    { pc = 0x1c2e2; break; }
    // gap 1 bytes
  case 0x1c2d3:
    memorySet16(ds, 0x2f67, 0x2f57);
    { pc = 0x1c2e2; break; }
    // gap 7 bytes
  case 0x1c2e2:
    if (0)
    yield* sub_1c4bd();
  case 0x1c2e5:
    yield* sub_10533();
    r16[si] = 0xbdf6;
    r16[cx] = 0x0080;
  case 0x1c2ef:
    r8[al] = memoryGet(ds, r16[si]);
    r16[si]++;
    if (r8[al] == 0x2f)
        { pc = 0x1c308; break; }
    if (--r16[cx])
        { pc = 0x1c2ef; break; }
    push(ds);
    r16[ax] = 0x1040;
    ds = r16[ax];
    memorySet16(ds, 0xab2b, 0x0000);
    ds = pop();
    { pc = 0x1c31f; break; }
    // gap 1 bytes
  case 0x1c308:
    r8[al] = memoryGet(ds, r16[si]);
    if (r8[al] == 0x61)
        { pc = 0x1c312; break; }
    if (r8[al] != 0x41)
        { pc = 0x1c31f; break; }
  case 0x1c312:
    r16[ax] = 0x1040;
    ds = r16[ax];
    es = r16[ax];
    memorySet16(ds, 0xab2b, 0x0001);
  case 0x1c31f:
    yield* sub_196dd();
    if (0)
    yield* sub_1ae81();
    memorySet(ds, 0xa860, 0x01);
    yield* sub_1c4e1();
    yield* sub_10d3d();
    yield* sub_105cc();
    yield* sub_1a44f();
    yield* sub_10702();
    yield* sub_10ee6();
    yield* sub_1a592();
    yield* sub_19e18();
    if (!flags.carry)
        { pc = 0x1c34b; break; }
    yield* sub_1c164();
  case 0x1c34b:
    memorySet16(ds, 0x95c4, 0x0000);
    yield* sub_10ee5();
    memorySet16(ds, 0xc0df, sp);
    sp = memoryGet16(ds, 0xc0df);
    yield* sub_10702();
    yield* sub_1a592();
    yield* sub_10ee6();
    memorySet16(ds, 0xbdf2, 0x0003);
    r16[ax] = memoryGet16(ds, 0xbdf2);
    yield* sub_1aecd();
    yield* sub_10df8();
  case 0x1c378:
    yield* sync();
    if (memoryGet(ds, 0xa85e) == 0xff)
        { pc = 0x1c378; break; }
    { pc = 0x1c398; break; }
    // gap 1 bytes
  case 0x1c382:
    if (memoryGet(ds, 0xa85e) == 0xff)
        { pc = 0x1c395; break; }
    memorySet16(ds, 0xbdf2, 0x0000);
    r16[ax] = memoryGet16(ds, 0xbdf2);
    yield* sub_1aecd();
  case 0x1c395:
    yield* sub_16b9b();
  case 0x1c398:
    if (memoryGet(ds, 0xa85e) == 0xff)
        { pc = 0x1c3ab; break; }
    memorySet16(ds, 0xbdf2, 0x0000);
    r16[ax] = memoryGet16(ds, 0xbdf2);
    yield* sub_1aecd();
  case 0x1c3ab:
    yield* sub_16cd7();
    { pc = 0x1c382; break; }
    return;
  }
}
function* sub_1c359() // 1040:bf59 +isolate
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp = memoryGet16(ds, 0xc0df);
    yield* sub_10702();
    yield* sub_1a592();
    yield* sub_10ee6();
    memorySet16(ds, 0xbdf2, 0x0003);
    r16[ax] = memoryGet16(ds, 0xbdf2);
    yield* sub_1aecd();
    yield* sub_10df8();
  case 0x1c378:
    yield* sync();
    if (memoryGet(ds, 0xa85e) == 0xff)
        { pc = 0x1c378; break; }
    { pc = 0x1c398; break; }
    // gap 1 bytes
  case 0x1c382:
    if (memoryGet(ds, 0xa85e) == 0xff)
        { pc = 0x1c395; break; }
    memorySet16(ds, 0xbdf2, 0x0000);
    r16[ax] = memoryGet16(ds, 0xbdf2);
    yield* sub_1aecd();
  case 0x1c395:
    yield* sub_16b9b();
  case 0x1c398:
    if (memoryGet(ds, 0xa85e) == 0xff)
        { pc = 0x1c3ab; break; }
    memorySet16(ds, 0xbdf2, 0x0000);
    r16[ax] = memoryGet16(ds, 0xbdf2);
    yield* sub_1aecd();
  case 0x1c3ab:
    yield* sub_16cd7();
    { pc = 0x1c382; break; }
    return;
  }
}
function* sub_1c4bd() // 1040:c0bd
{
    r16[ax] = cs;
    r16[cx] = 0x0000;
    r16[dx] = memoryGet16(ds, 0x2f67);
    yield* sub_1a65b();
}
function* sub_1c4ca() // 1040:c0ca
{
    yield* sub_1c1a2();
    r8[al] = memoryGet(ds, 0xb884);
}
function* sub_1c4e1() // 1040:c0e1
{
}
function* sub_1c4e2() // 1040:c0e2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = memoryGet16(ds, 0x6614);
    r16[ax]++;
    if (r16s[ax] > signed16(0x0006))
        { pc = 0x1c4ee; break; }
    memorySet16(ds, 0x6614, r16[ax]);
  case 0x1c4ee:
    return;
  }
}
function fixReloc(seg)
{
        memorySet16(0x0040 + seg, 0x9334, memoryGet16(0x0040 + seg, 0x9334) + seg); // 0040 -> 1040; lin=9734
        memorySet16(0x0040 + seg, 0xa05d, memoryGet16(0x0040 + seg, 0xa05d) + seg); // 0040 -> 1040; lin=a45d
        memorySet16(0x0040 + seg, 0xa069, memoryGet16(0x0040 + seg, 0xa069) + seg); // 0040 -> 1040; lin=a469
        memorySet16(0x0040 + seg, 0xa075, memoryGet16(0x0040 + seg, 0xa075) + seg); // 0040 -> 1040; lin=a475
        memorySet16(0x0040 + seg, 0xa081, memoryGet16(0x0040 + seg, 0xa081) + seg); // 0040 -> 1040; lin=a481
        memorySet16(0x0040 + seg, 0xa08d, memoryGet16(0x0040 + seg, 0xa08d) + seg); // 0040 -> 1040; lin=a48d
        memorySet16(0x0040 + seg, 0xa099, memoryGet16(0x0040 + seg, 0xa099) + seg); // 0040 -> 1040; lin=a499
        memorySet16(0x0040 + seg, 0xa0a5, memoryGet16(0x0040 + seg, 0xa0a5) + seg); // 0040 -> 1040; lin=a4a5
        memorySet16(0x0040 + seg, 0xa289, memoryGet16(0x0040 + seg, 0xa289) + seg); // 0040 -> 1040; lin=a689
        memorySet16(0x0040 + seg, 0xa2d0, memoryGet16(0x0040 + seg, 0xa2d0) + seg); // 0040 -> 1040; lin=a6d0
        memorySet16(0x0040 + seg, 0xa2e1, memoryGet16(0x0040 + seg, 0xa2e1) + seg); // 0040 -> 1040; lin=a6e1
        memorySet16(0x0040 + seg, 0xa2f1, memoryGet16(0x0040 + seg, 0xa2f1) + seg); // 0040 -> 1040; lin=a6f1
        memorySet16(0x0040 + seg, 0xa302, memoryGet16(0x0040 + seg, 0xa302) + seg); // 0040 -> 1040; lin=a702
        memorySet16(0x0040 + seg, 0xa30f, memoryGet16(0x0040 + seg, 0xa30f) + seg); // 0040 -> 1040; lin=a70f
        memorySet16(0x0040 + seg, 0xa864, memoryGet16(0x0040 + seg, 0xa864) + seg); // 0040 -> 1040; lin=ac64
        memorySet16(0x0040 + seg, 0xa86e, memoryGet16(0x0040 + seg, 0xa86e) + seg); // 0040 -> 1040; lin=ac6e
        memorySet16(0x0040 + seg, 0xa9d5, memoryGet16(0x0040 + seg, 0xa9d5) + seg); // 0040 -> 1040; lin=add5
        memorySet16(0x0040 + seg, 0xaa0f, memoryGet16(0x0040 + seg, 0xaa0f) + seg); // 0040 -> 1040; lin=ae0f
        memorySet16(0x0040 + seg, 0xaa33, memoryGet16(0x0040 + seg, 0xaa33) + seg); // 0040 -> 1040; lin=ae33
        memorySet16(0x0040 + seg, 0xaa7b, memoryGet16(0x0040 + seg, 0xaa7b) + seg); // 0040 -> 1040; lin=ae7b
        memorySet16(0x0040 + seg, 0xaae7, memoryGet16(0x0040 + seg, 0xaae7) + seg); // 0040 -> 1040; lin=aee7
        memorySet16(0x0040 + seg, 0xb53c, memoryGet16(0x0040 + seg, 0xb53c) + seg); // 0040 -> 1040; lin=b93c
        memorySet16(0x0040 + seg, 0xb89b, memoryGet16(0x0040 + seg, 0xb89b) + seg); // 0040 -> 1040; lin=bc9b
        memorySet16(0x0040 + seg, 0xb8b9, memoryGet16(0x0040 + seg, 0xb8b9) + seg); // 0040 -> 1040; lin=bcb9
        memorySet16(0x0040 + seg, 0xb8d2, memoryGet16(0x0040 + seg, 0xb8d2) + seg); // 0040 -> 1040; lin=bcd2
        memorySet16(0x0040 + seg, 0xbda3, memoryGet16(0x0040 + seg, 0xbda3) + seg); // 0040 -> 1040; lin=c1a3
        memorySet16(0x0040 + seg, 0xbe8b, memoryGet16(0x0040 + seg, 0xbe8b) + seg); // 0040 -> 1040; lin=c28b
        memorySet16(0x0040 + seg, 0xbefa, memoryGet16(0x0040 + seg, 0xbefa) + seg); // 0040 -> 1040; lin=c2fa
        memorySet16(0x0040 + seg, 0xbf13, memoryGet16(0x0040 + seg, 0xbf13) + seg); // 0040 -> 1040; lin=c313
}
