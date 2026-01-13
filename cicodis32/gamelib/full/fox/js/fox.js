function init()
{
    headerSize = 0x0200;
    loadAddress = 0x1000;
    endAddress = 0x1fa0;
    cs = 0x1020;
    ds = 0x1010;
    es = 0x1010;
    ss = 0x1000;
    sp = 0x0200;
    load("fox.zip", "FOX.EXE", 84992);
    fixReloc(loadAddress);
}

let savedSp;
function saveSp()
{
    push(0xbebe);
    savedSp = sp;
}

function dropsSp()
{
    if (savedSp == sp)
    {
        assert(pop() == 0xbebe);
        return false;
    }
    return true;
}


function* start()
{
    yield* sub_10205();
}

function* sub_10205() // 1020:0005 +entry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    flags.interrupts = 1;
    flags.direction = 0;
    r16[dx] = 0xffff;
    r16[si] = 0x0080;
    r8[al] = lodsb_DSSI();
    cbw();
    r16[cx] = r16[ax];
    if (!r16[cx])
        { pc = 0x1024f; break; }
  case 0x10213: // 1020:0013
    r8[al] = lodsb_DSSI();
    if (r8[al] == 0x2f)
        { pc = 0x1021c; break; }
    if (--r16[cx])
        { pc = 0x10213; break; }
    { pc = 0x1024f; break; }
  case 0x1021c: // 1020:001c
    r8[al] = lodsb_DSSI();
    r8[al] &= 0xdf;
    if (r8[al] != 0x56)
        { pc = 0x10225; break; }
    r8[dl] = 0x05;
  case 0x10225: // 1020:0025
    if (r8[al] != 0x45)
        { pc = 0x1022b; break; }
    r8[dl] = 0x03;
  case 0x1022b: // 1020:002b
    if (r8[al] != 0x54)
        { pc = 0x10231; break; }
    r8[dl] = 0x02;
  case 0x10231: // 1020:0031
    if (r8[al] != 0x43)
        { pc = 0x10237; break; }
    r8[dl] = 0x01;
  case 0x10237: // 1020:0037
    if (r8[al] != 0x48)
        { pc = 0x1023d; break; }
    r8[dl] = 0x00;
  case 0x1023d: // 1020:003d
    if (r8[al] != 0x42)
        { pc = 0x10243; break; }
    r8[dh] = 0x00;
  case 0x10243: // 1020:0043
    if (r8[al] != 0x46)
        { pc = 0x1024d; break; }
    memoryASet(cs, 0x0003, 0x00);
  case 0x1024d: // 1020:004d
    if (--r16[cx])
        { pc = 0x10213; break; }
  case 0x1024f: // 1020:004f
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet(cs, 0x0001, r8[dl]);
    memoryASet(cs, 0x0002, r8[dh]);
    r16[ax] = 0x8f01;
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[ax] += 0x1690;
    memoryASet16(ds, 0x04c1, r16[ax]);
    push(ds);
    r16[ax] = 0;
    ds = r16[ax];
    memoryASet16(ds, 0x0090, 0x08d0);
    memoryASet16(ds, 0x0092, cs);
    ds = pop();
    yield* sub_119fe();
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0x168f;
    ds = r16[ax];
    yield* sub_1127d();
    yield* sub_10eeb();
    yield* sub_10901();
    yield* sub_1327d();
    yield* sub_13360();
    r16[dx] = 0x0000;
    push(ds);
    push(es);
    yield* sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x000e, r16[ax]);
    yield* sub_11a3f();
    yield* sub_11398();
    r16[ax] = 0x4000;
    out8(0x40, r8[al]);
    r8[al] = r8[ah];
    out8(0x40, r8[al]);
    yield* sub_155a2();
    yield* sub_154ec();
    yield* sub_126c9();
    r16[ax] = memoryAGet16(ds, 0x04c1);
    memoryASet16(ds, 0x000c, r16[ax]);
  case 0x102c5: // 1020:00c5
    r16[dx] = memoryAGet16(ds, 0x000c);
    memoryASet16(ds, 0x04c1, r16[dx]);
    if (!r16[ax])
        { pc = 0x102e9; break; }
    yield* sub_153c6();
    yield* sub_13360();
    memoryASet(ds, 0x041b, 0x02);
    memoryASet(ds, 0x0419, 0x10);
    memoryASet(ds, 0x041a, 0x00);
    yield* sub_10373();
  case 0x102e9: // 1020:00e9
    yield* sub_13360();
    r8[al] = memoryAGet(ds, 0x5250);
    yield* sub_130b7();
    yield* sub_1398d();
    yield* sub_158cc();
    r16[ax] = 0x168f;
    ds = r16[ax];
    r8[bl] = memoryAGet(ds, 0x5250);
    r8[bh] = 0;
    r8[al] = memoryAGet(ds, r16[bx] + 20620);
    cbw();
    yield* sub_112ff();
    yield* sub_140e8();
    yield* sub_12f62();
    yield* sub_12e87();
    yield* sub_13471();
  case 0x10317: // 1020:0117
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet16(ds, 0x64fe, memoryAGet16(ds, 0x64fe) + 1);
    yield* sub_14028();
    yield* sub_13bc7();
    yield* sub_1434b();
    yield* sub_15b45();
    yield* sub_15ac8();
    yield* sub_15937();
    yield* sub_13ab5();
    yield* sub_139f5();
    yield* sub_14146();
    yield* sub_12da2();
    yield* sub_12e87();
    yield* sub_11e61();
    yield* sub_13827();
    if (!flags.carry)
        { pc = 0x1034c; break; }
    { pc = 0x102c5; break; }
  case 0x1034c: // 1020:014c
    yield* sub_107b7();
    yield* sub_10358();
    yield* sub_13471();
    { pc = 0x10317; break; }
    return;
  }
}
function* sub_10358() // 1020:0158
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (memoryAGet(cs, 0x16e4) != 0x03)
        { pc = 0x10372; break; }
    if (memoryAGet(ds, 0x09b2))
        { pc = 0x10372; break; }
    r16[ax] = memoryAGet16(ds, 0x0913);
    yield* sub_112ff();
  case 0x10372: // 1020:0172
    return;
  }
}
function* sub_10373() // 1020:0173
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0x0000;
    yield* sub_112ff();
    yield* sub_12a11();
    yield* sub_103f8();
    if (memoryAGet(ds, 0x041a) < 0x0a)
        { pc = 0x103c6; break; }
    yield* sub_105f2();
  case 0x10397: // 1020:0197
    if (memoryAGet(ds, 0x041a) < 0x0a)
        { pc = 0x103c6; break; }
    r16[dx] = 0x000a;
  case 0x103a1: // 1020:01a1
    memoryASet(ds, 0x041a, memoryAGet(ds, 0x041a) - 1);
    push(r16[dx]);
    yield* sub_10444();
    r16[dx] = pop();
    r16[cx] = 0x000f;
  case 0x103ad: // 1020:01ad
    yield* sub_13443();
    if (--r16[cx])
        { pc = 0x103ad; break; }
    r16[dx]--;
    if (r16[dx])
        { pc = 0x103a1; break; }
    memoryASet(ds, 0x041b, memoryAGet(ds, 0x041b) + 1);
    yield* sub_10444();
    r16[cx] = 0x000a;
  case 0x103bf: // 1020:01bf
    yield* sub_13443();
    if (--r16[cx])
        { pc = 0x103bf; break; }
    { pc = 0x10397; break; }
  case 0x103c6: // 1020:01c6
    yield* sub_10444();
    yield* sub_105f2();
    yield* sub_105ae();
    r16[bp] = pop();
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
}
function* sub_103d9() // 1020:01d9
{
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    yield* sub_12a11();
    yield* sub_103f8();
    yield* sub_105f2();
    yield* sub_105ae();
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_103f8() // 1020:01f8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    yield* sub_1058a();
    memoryASet16(ds, 0x01f5, 0x000d);
    memoryASet16(ds, 0x01f7, 0x0960);
    yield* sub_105dc();
    r8[cl] = memoryAGet(ds, 0x5250);
    r8[ch] = 0;
    r16[si] = 0x5104;
    if (!r16[cx])
        { pc = 0x10423; break; }
  case 0x1041a: // 1020:021a
    r8[al] = lodsb_DSSI();
    if (r8[al])
        { pc = 0x1041a; break; }
    r16[si]++;
    if (--r16[cx])
        { pc = 0x1041a; break; }
    r16[si]--;
  case 0x10423: // 1020:0223
    r16[bx] = 0;
  case 0x10425: // 1020:0225
    r16[bx]++;
    if (memoryAGet(ds, r16[bx] + r16[si]))
        { pc = 0x10425; break; }
    r16[bx]--;
    flags.carry = r16[bx] & 1;
    r16[bx] >>= 1;
    r8[bl] += (0x01 + flags.carry);
    memoryASet16(ds, 0x01f5, 0x0014);
    memoryASet16(ds, 0x01f7, 0x0be0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - r16[bx]);
    yield* sub_10688();
    memoryASet16(ds, 0x01f5, 0x000a);
    memoryASet16(ds, 0x01f7, 0x12c0);
    r16[si] = 0x0010;
    yield* sub_10688();
    r8[dl] = memoryAGet(ds, 0x041a);
    r8[dh] = 0;
    yield* sub_10623();
    memoryASet16(ds, 0x01f5, 0x000a);
    memoryASet16(ds, 0x01f7, 0x14a0);
    r16[si] = 0x001e;
    yield* sub_10688();
    r8[dl] = memoryAGet(ds, 0x041b);
    r8[dh] = 0;
    yield* sub_10623();
    return;
  }
}
function* sub_10444() // 1020:0244
{
    memoryASet16(ds, 0x01f5, 0x000a);
    memoryASet16(ds, 0x01f7, 0x12c0);
    r16[si] = 0x0010;
    yield* sub_10688();
    r8[dl] = memoryAGet(ds, 0x041a);
    r8[dh] = 0;
    yield* sub_10623();
    memoryASet16(ds, 0x01f5, 0x000a);
    memoryASet16(ds, 0x01f7, 0x14a0);
    r16[si] = 0x001e;
    yield* sub_10688();
    r8[dl] = memoryAGet(ds, 0x041b);
    r8[dh] = 0;
    yield* sub_10623();
}
function* sub_1047b() // 1020:027b +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(r16[bp]);
    push(ds);
    push(es);
    r16[ax] = 0x168f;
    ds = r16[ax];
    yield* sub_13360();
    yield* sub_1058a();
    memoryASet16(ds, 0x01f5, 0x000e);
    memoryASet16(ds, 0x01f7, 0x0c80);
    r16[si] = 0x002c;
    yield* sub_10688();
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x0004);
    r16[dx] = 0;
    r16[cx] = 0x0004;
  case 0x104aa: // 1020:02aa
    memoryASet(ds, 0x04c0, 0x00);
  case 0x104af: // 1020:02af
    yield *sync();
    r8[bl] = memoryAGet(ds, 0x04c0);
    if (r8[bl] & 0x80)
        { pc = 0x104aa; break; }
    r8[bh] = 0;
    r8[al] = memoryAGet(ds, r16[bx] + 373);
    if (r8[al] == 0x2d)
        { pc = 0x104af; break; }
    r8[ah] = r8[al];
    r8[ah] -= 0x30;
    if (r8[ah] <= 0x09)
        { pc = 0x104cf; break; }
    r8[ah] -= 0x07;
  case 0x104cf: // 1020:02cf
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r8[dl] |= r8[ah];
    yield* sub_1070e();
    if (--r16[cx])
        { pc = 0x104aa; break; }
    memoryASet16(ds, 0x01f5, 0x000b);
    memoryASet16(ds, 0x01f7, 0x1040);
    r16[cx] = 0;
  case 0x104ec: // 1020:02ec
    r16[ax] = r16[cx];
    yield* sub_16782();
    if (r16[ax] == r16[dx])
        { pc = 0x10507; break; }
    r16[cx]++;
    if (r16[cx] <= 0x0014)
        { pc = 0x104ec; break; }
  case 0x104fb: // 1020:02fb
    r16[si] = 0x0037;
    yield* sub_10688();
    yield* sub_105f2();
    flags.carry = 1;
    { pc = 0x1052a; break; }
  case 0x10507: // 1020:0307
    r16[si] = 0x0048;
    yield* sub_10688();
    r16[bx] = r16[cx];
    r8[dl] = memoryAGet(ds, r16[bx] + 21052);
    r8[dh] = 0;
    if (r8[dl] != 0xff)
        { pc = 0x10521; break; }
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x0009);
    { pc = 0x104fb; break; }
  case 0x10521: // 1020:0321
    push(r16[bx]);
    yield* sub_10623();
    yield* sub_105f2();
    r16[ax] = pop();
    flags.carry = 0;
  case 0x1052a: // 1020:032a
    es = pop();
    ds = pop();
    r16[bp] = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    return;
  }
}
function* sub_10533() // 1020:0333
{
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    yield* sub_12a11();
    yield* sub_1058a();
    memoryASet16(ds, 0x01f5, 0x000d);
    memoryASet16(ds, 0x01f7, 0x1040);
    yield* sub_105dc();
    memoryASet16(ds, 0x01f5, 0x000e);
    memoryASet16(ds, 0x01f7, 0x0c80);
    r16[si] = 0x0052;
    yield* sub_10688();
    r8[al] = memoryAGet(ds, 0x5250);
    cbw();
    yield* sub_16782();
    r16[dx] = r16[ax];
    yield* sub_10665();
    yield* sub_105f2();
    yield* sub_13443();
    yield* sub_105ae();
    yield* sub_1296f();
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_1058a() // 1020:038a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] == 0x05)
        { pc = 0x1059e; break; }
    if (r8[al] >= 0x03)
        { pc = 0x105a5; break; }
    return;
  case 0x1059e: // 1020:039e
    r16[dx] = 0x04c4;
    yield* sub_10610();
    return;
  case 0x105a5: // 1020:03a5
    r16[dx] = 0x04f4;
    r16[ax] = 0x1002;
    interrupt(0x10);
    return;
  }
}
function* sub_105ae() // 1020:03ae
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    yield* sub_129df();
    r8[al] = memoryAGet(cs, 0x0001);
//    if (r8[al] == 0x05)
        { pc = 0x105c5; break; }
    if (r8[al] >= 0x03)
        { pc = 0x105d3; break; }
    return;
  case 0x105c5: // 1020:03c5
    r16[ax] = 0x1012;
    r16[bx] = 0;
    r16[cx] = 0x0010;
    r16[dx] = 0x5057;
    interrupt(0x10);
    return;
  case 0x105d3: // 1020:03d3
    r16[dx] = 0x5035;
    r16[ax] = 0x1002;
    interrupt(0x10);
    return;
  }
}
function* sub_105dc() // 1020:03dc
{
    r16[si] = 0x0059;
    yield* sub_10688();
    r8[bl] = memoryAGet(ds, 0x5250);
    r8[bh] = 0;
    r8[dl] = memoryAGet(ds, r16[bx] + 21052);
    r8[dh] = 0;
    yield* sub_10623();
}
function* sub_105f2() // 1020:03f2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
  case 0x105f7: // 1020:03f7
    yield* sync();
    yield* sub_10a05();
    r8[al] = memoryAGet(ds, 0x047e);
    r8[al] |= memoryAGet(ds, 0x042b);
    if (!r8[al])
        { pc = 0x105f7; break; }
  case 0x10603: // 1020:0403
    yield* sync();
    yield* sub_10a05();
    r8[al] = memoryAGet(ds, 0x042b);
    r8[al] |= memoryAGet(ds, 0x047e);
    if (r8[al])
        { pc = 0x10603; break; }
    return;
  }
}
function* sub_10610() // 1020:0410
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] != 0x05)
        { pc = 0x10622; break; }
    r16[ax] = 0x1012;
    r16[bx] = 0;
    r16[cx] = 0x0010;
    interrupt(0x10);
  case 0x10622: // 1020:0422
    return;
  }
}
function* sub_10623() // 1020:0423
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memoryASet(ds, 0x0418, 0x00);
    r16[bx] = 0x2710;
  case 0x1062b: // 1020:042b
    r8[al] = 0x30;
  case 0x1062d: // 1020:042d
    if (r16[dx] < r16[bx])
        { pc = 0x10637; break; }
    r16[dx] -= r16[bx];
    r8[al]++;
    { pc = 0x1062d; break; }
  case 0x10637: // 1020:0437
    if (r8[al] != 0x30)
        { pc = 0x1064b; break; }
    if (r16[bx] == 0x0001)
        { pc = 0x1064b; break; }
    if (memoryAGet(ds, 0x0418))
        { pc = 0x1064b; break; }
    r8[al] = 0x20;
    { pc = 0x10650; break; }
  case 0x1064b: // 1020:044b
    memoryASet(ds, 0x0418, 0x01);
  case 0x10650: // 1020:0450
    yield* sub_1070e();
    r16[ax] = r16[bx];
    push(r16[dx]);
    r16[dx] = 0;
    r16[bx] = 0x000a;
    div16(r16[bx]);
    r16[dx] = pop();
    r16[bx] = r16[ax];
    if (r16[bx])
        { pc = 0x1062b; break; }
    return;
  }
}
function* sub_10665() // 1020:0465
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[cx] = 0x0004;
  case 0x10668: // 1020:0468
    r16[ax] = 0;
    flags.carry = !!(r16[dx] & 0x8000);
    r16[dx] <<= 1;
    r16[ax] = rcl16(r16[ax], 0x0001);
    flags.carry = !!(r16[dx] & 0x8000);
    r16[dx] <<= 1;
    r16[ax] = rcl16(r16[ax], 0x0001);
    flags.carry = !!(r16[dx] & 0x8000);
    r16[dx] <<= 1;
    r16[ax] = rcl16(r16[ax], 0x0001);
    flags.carry = !!(r16[dx] & 0x8000);
    r16[dx] <<= 1;
    r16[ax] = rcl16(r16[ax], 0x0001);
    if (r8[al] <= 0x09)
        { pc = 0x10680; break; }
    r8[al] += 0x07;
  case 0x10680: // 1020:0480
    r8[al] += 0x30;
    yield* sub_1070e();
    if (--r16[cx])
        { pc = 0x10668; break; }
    return;
  }
}
function* sub_10688() // 1020:0488
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
  case 0x10689: // 1020:0489
    r8[al] = lodsb_DSSI();
    if (!r8[al])
        { pc = 0x10693; break; }
    yield* sub_1070e();
    { pc = 0x10689; break; }
  case 0x10693: // 1020:0493
    r16[ax] = pop();
    return;
  }
}
function* sub_1070e() // 1020:050e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x1070e; break; }
  case 0x10695: // 1020:0495
    r8[dl] = r8[al];
    if (memoryAGet(ds, 0x043b))
        { pc = 0x106bd; break; }
    memoryASet(ds, 0x043b, memoryAGet(ds, 0x043b) + 1);
    memoryASet16(cs, 0x6676, 0x0597);
    ds = memoryAGet16(ds, 0x000e);
    r16[si] = 0;
    r16[cx] = 0x0029;
  case 0x106b2: // 1020:04b2
    r16[ax] = 0x010c;
    yield* sub_167be();
    r16[si] += 0x0030;
    if (--r16[cx])
        { pc = 0x106b2; break; }
  case 0x106bd: // 1020:04bd
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[di] = memoryAGet16(ds, 0x01f5);
    r16[di] <<= 1;
    r16[di] += memoryAGet16(ds, 0x01f7);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) + 1);
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[cx] = 0x0006;
    r8[al] = r8[dl];
    if (r8[al] != 0x20)
        { pc = 0x106ee; break; }
    r16[ax] = 0;
  case 0x106e0: // 1020:04e0
    stosw_ESDI(r16[ax]);
    r16[di] += 0x1ffe;
    stosw_ESDI(r16[ax]);
    r16[di] -= 0x1fb2;
    if (--r16[cx])
        { pc = 0x106e0; break; }
    { pc = 0x1070c; break; }
  case 0x106ee: // 1020:04ee
    r8[al] -= 0x30;
    if (r8[al] <= 0x09)
        { pc = 0x106f6; break; }
    r8[al] -= 0x02;
  case 0x106f6: // 1020:04f6
    ds = memoryAGet16(ds, 0x000e);
    r8[ah] = 0x30;
    mul8(r8[ah]);
    r16[si] = r16[ax];
  case 0x10700: // 1020:0500
    movsw_ESDI_DSSI();
    r16[di] += 0x1ffe;
    movsw_ESDI_DSSI();
    r16[di] -= 0x1fb2;
    if (--r16[cx])
        { pc = 0x10700; break; }
  case 0x1070c: // 1020:050c
    { pc = 0x1078d; break; }
  case 0x1070e: // 1020:050e
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    if (memoryAGet(cs, 0x0001) >= 0x03)
        { pc = 0x10722; break; }
    { pc = 0x10695; break; }
  case 0x10722: // 1020:0522
    r16[di] = memoryAGet16(ds, 0x01f7);
    r16[di] += memoryAGet16(ds, 0x01f5);
    r16[di] += memoryAGet16(ds, 0x5268);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) + 1);
    if (r8[al] != 0x20)
        { pc = 0x10756; break; }
    r16[ax] = 0xa000;
    es = r16[ax];
    yield* sub_134dc();
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r8[al] = 0;
    r16[cx] = 0x000c;
  case 0x1074a: // 1020:054a
    stosb_ESDI(r8[al]);
    r16[di] += 0x0027;
    if (--r16[cx])
        { pc = 0x1074a; break; }
    r16[di] -= 0x01e0;
    { pc = 0x1078d; break; }
  case 0x10756: // 1020:0556
    r8[al] -= 0x30;
    if (r8[al] <= 0x09)
        { pc = 0x1075e; break; }
    r8[al] -= 0x02;
  case 0x1075e: // 1020:055e
    ds = memoryAGet16(ds, 0x000e);
    r8[ah] = 0x30;
    mul8(r8[ah]);
    r16[si] = r16[ax];
    r16[ax] = 0xa000;
    es = r16[ax];
    yield* sub_134dc();
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = 0x01;
  case 0x10779: // 1020:0579
    out8(r16[dx], r8[al]);
    r16[cx] = 0x000c;
  case 0x1077d: // 1020:057d
    movsb_ESDI_DSSI();
    r16[di] += 0x0027;
    if (--r16[cx])
        { pc = 0x1077d; break; }
    r16[di] -= 0x01e0;
    r8[al] <<= 1;
    if (r8[al] <= 0x08)
        { pc = 0x10779; break; }
  case 0x1078d: // 1020:058d
    r16[bp] = pop();
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
}
function* sub_107b7() // 1020:05b7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    flags.carry = memoryAGet(ds, 0x6506) < 0x01;
    memoryASet(ds, 0x6506, memoryAGet(ds, 0x6506) - 0x01);
    memoryASet(ds, 0x6506, memoryAGet(ds, 0x6506) + (0x00 + flags.carry));
    if (!memoryAGet(ds, 0x6506))
        { pc = 0x107c6; break; }
    yield* sub_107c7();
  case 0x107c6: // 1020:05c6
    return;
  }
}
function* sub_107c7() // 1020:05c7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x10836; break; }
    r16[si] = memoryAGet16(ds, 0x526a);
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
    r8[cl] = memoryAGet(ds, 0x0419);
    r8[bl] = r8[cl];
    r8[ch] = 0;
    r16[ax] = 0xa000;
    ds = r16[ax];
    r16[bp] = 0x0028;
    if (!r16[cx])
        { pc = 0x10819; break; }
  case 0x10814: // 1020:0614
    yield* sub_10891();
    if (--r16[cx])
        { pc = 0x10814; break; }
  case 0x10819: // 1020:0619
    r8[cl] = 0x10;
    r8[cl] -= r8[bl];
    if (!r8[cl])
        { pc = 0x10824; break; }
  case 0x1081f: // 1020:061f
    yield* sub_108ea();
    if (--r16[cx])
        { pc = 0x1081f; break; }
  case 0x10824: // 1020:0624
    r16[ax] = 0x0001;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0xff08;
    out16(r16[dx], r16[ax]);
  case 0x1082c: // 1020:062c
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  case 0x10836: // 1020:0636
    r16[bp] = 0x004f;
    r16[di] = 0x02e8;
    es = memoryAGet16(ds, 0x5262);
    r8[al] = 0xff;
    r8[cl] = memoryAGet(ds, 0x0419);
    r8[ch] = 0;
    if (!r16[cx])
        { pc = 0x1084f; break; }
  case 0x1084a: // 1020:064a
    yield* sub_1085e();
    if (--r16[cx])
        { pc = 0x1084a; break; }
  case 0x1084f: // 1020:064f
    r8[cl] = 0x10;
    r8[cl] -= memoryAGet(ds, 0x0419);
    if (!r16[cx])
        { pc = 0x1082c; break; }
  case 0x10857: // 1020:0657
    yield* sub_108d4();
    if (--r16[cx])
        { pc = 0x10857; break; }
    { pc = 0x1082c; break; }
    return;
  }
}
function* sub_1085e() // 1020:065e
{
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] -= 0x04af;
}
function* sub_10891() // 1020:0691
{
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] -= 0x0257;
}
function* sub_108d4() // 1020:06d4
{
    r16[di] += 0x01e0;
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] += r16[bp];
    stosb_ESDI(r8[al]);
    r16[di] -= 0x031f;
}
function* sub_108ea() // 1020:06ea
{
    r16[si] += 0x00f0;
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] += r16[bp];
    memoryASet(ds, r16[si], memoryAGet(ds, r16[si]) + r8[al]);
    r16[si] -= 0x0167;
}
function* sub_10901() // 1020:0701
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet(ds, 0x0428, 0x03);
  case 0x1090b: // 1020:070b
    memoryASet(ds, 0x041c, 0x00);
    memoryASet16(ds, 0x041d, 0x0320);
    r16[dx] = 0x0201;
    r16[cx] = 0x0c80;
    r8[ah] = 0x03;
    flags.interrupts = 0;
  case 0x1091f: // 1020:071f
    r8[al] = in8(r16[dx]);
    if (!(r8[al] & 0x03))
        { pc = 0x10927; break; }
    r8[ah] &= 0x02;
  case 0x10927: // 1020:0727
    if (!(r8[al] & 0x0c))
        { pc = 0x1092e; break; }
    r8[ah] &= 0x01;
  case 0x1092e: // 1020:072e
    if (--r16[cx])
        { pc = 0x1091f; break; }
    r8[al] = 0xff;
    if (!(r8[ah] & 0x02))
        { pc = 0x1093a; break; }
    r8[al] = memoryAGet(ds, 0x042a);
  case 0x1093a: // 1020:073a
    if (!(r8[ah] & 0x01))
        { pc = 0x10942; break; }
    r8[al] = memoryAGet(ds, 0x0429);
  case 0x10942: // 1020:0742
    memoryASet(ds, 0x0427, r8[al]);
    yield* sub_109b0();
    if (flags.carry)
        { pc = 0x10996; break; }
    if (r16[ax] >= 0x0320)
        { pc = 0x10996; break; }
    if (r16[bx] >= 0x0320)
        { pc = 0x10996; break; }
    if (!r16[ax])
        { pc = 0x10996; break; }
    if (!r16[bx])
        { pc = 0x10996; break; }
    r8[cl] = 0x02;
    r16[bp] = r16[ax];
    r16[ax] >>= r8[cl];
    r16[ax] -= r16[bp];
    r16[ax] = -r16[ax];
    memoryASet16(ds, 0x041f, r16[ax]);
    r16[ax] = r16[bp];
    r16[ax] >>= r8[cl];
    r16[ax] += r16[bp];
    memoryASet16(ds, 0x0425, r16[ax]);
    r16[bp] = r16[bx];
    r16[bx] >>= r8[cl];
    r16[bx] -= r16[bp];
    r16[bx] = -r16[bx];
    memoryASet16(ds, 0x0421, r16[bx]);
    r16[bx] = r16[bp];
    r16[bx] >>= r8[cl];
    r16[bx] += r16[bp];
    memoryASet16(ds, 0x0423, r16[bx]);
    if (r16[ax] >= r16[bx])
        { pc = 0x1098f; break; }
    r16[ax] = r16[bx];
  case 0x1098f: // 1020:078f
    r16[ax] <<= 1;
    memoryASet16(ds, 0x041d, r16[ax]);
    { pc = 0x109ae; break; }
  case 0x10996: // 1020:0796
    memoryASet(ds, 0x0428, memoryAGet(ds, 0x0428) - 1);
    if (!memoryAGet(ds, 0x0428))
        { pc = 0x109a9; break; }
    r8[al] = memoryAGet(ds, 0x0429);
    r8[tl] = memoryAGet(ds, 0x042a); memoryASet(ds, 0x042a, r8[al]); r8[al] = r8[tl];
    memoryASet(ds, 0x0429, r8[al]);
    { pc = 0x1090b; break; }
  case 0x109a9: // 1020:07a9
    memoryASet(ds, 0x0427, 0xff);
  case 0x109ae: // 1020:07ae
    flags.interrupts = 1;
    return;
  }
}
function* sub_109b0() // 1020:07b0 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[cl] = memoryAGet(ds, 0x0427);
    if (r8s[cl] < 0)
        { pc = 0x10a02; break; }
    if (memoryAGet(ds, 0x041c))
        { pc = 0x10a02; break; }
    r16[dx] = 0x0201;
    r8[al] = in8(r16[dx]);
    r8[al] >>= r8[cl];
    if (r8[al] & 0x03)
        { pc = 0x10a02; break; }
    r8[al] ^= 0x30;
    r8[al] >>= 1;
    r8[al] >>= 1;
    r8[al] >>= 1;
    r8[al] >>= 1;
    r16[bp] = 0;
    r16[di] = 0;
    r16[bx] = 0;
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    memoryASet(ds, 0x042b, memoryAGet(ds, 0x042b) - (r8[bh] + flags.carry));
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    memoryASet(ds, 0x042b, memoryAGet(ds, 0x042b) - (r8[bh] + flags.carry));
    r16[si] = memoryAGet16(ds, 0x041d);
    flags.interrupts = 0;
    out8(r16[dx], r8[al]);
  case 0x109eb: // 1020:07eb
    r8[al] = in8(r16[dx]);
    r8[al] >>= r8[cl];
    if (!(r8[al] & 0x03))
        { pc = 0x109fd; break; }
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    r16[di] += (r16[bp] + flags.carry);
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    r16[bx] += (r16[bp] + flags.carry);
    r16[si]--;
    if (r16[si])
        { pc = 0x109eb; break; }
  case 0x109fd: // 1020:07fd
    r16[ax] = r16[di];
    flags.interrupts = 1;
    flags.carry = 0;
    return;
  case 0x10a02: // 1020:0802
    flags.interrupts = 1;
    flags.carry = 1;
    return;
  }
}
function* sub_10a05() // 1020:0805
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0;
    memoryASet(ds, 0x042d, r8[al]);
    memoryASet(ds, 0x042e, r8[al]);
    memoryASet(ds, 0x042f, r8[al]);
    memoryASet(ds, 0x0430, r8[al]);
    memoryASet(ds, 0x042b, r8[al]);
    memoryASet(ds, 0x042c, r8[al]);
    yield* sub_109b0();
    if (flags.carry)
        { pc = 0x10a5c; break; }
    if (r16[ax] > memoryAGet16(ds, 0x041f))
        { pc = 0x10a39; break; }
    memoryASet(ds, 0x0430, 0xff);
    { pc = 0x10a44; break; }
  case 0x10a39: // 1020:0839
    if (r16[ax] < memoryAGet16(ds, 0x0425))
        { pc = 0x10a44; break; }
    memoryASet(ds, 0x042f, 0xff);
  case 0x10a44: // 1020:0844
    if (r16[bx] > memoryAGet16(ds, 0x0421))
        { pc = 0x10a51; break; }
    memoryASet(ds, 0x042d, 0xff);
    { pc = 0x10a5c; break; }
  case 0x10a51: // 1020:0851
    if (r16[bx] < memoryAGet16(ds, 0x0423))
        { pc = 0x10a5c; break; }
    memoryASet(ds, 0x042e, 0xff);
  case 0x10a5c: // 1020:085c
    r8[al] = memoryAGet(ds, 0x0488);
    r8[al] |= memoryAGet(ds, 0x04bc);
    r8[al] |= memoryAGet(ds, 0x0469);
    r8[al] |= memoryAGet(ds, 0x0450);
    memoryASet(ds, 0x042d, memoryAGet(ds, 0x042d) | r8[al]);
    r8[al] = memoryAGet(ds, 0x0490);
    r8[al] |= memoryAGet(ds, 0x04bb);
    r8[al] |= memoryAGet(ds, 0x048a);
    r8[al] |= memoryAGet(ds, 0x045e);
    memoryASet(ds, 0x042e, memoryAGet(ds, 0x042e) | r8[al]);
    r8[al] = memoryAGet(ds, 0x048d);
    r8[al] |= memoryAGet(ds, 0x04b9);
    r8[al] |= memoryAGet(ds, 0x048e);
    r8[al] |= memoryAGet(ds, 0x0467);
    memoryASet(ds, 0x042f, memoryAGet(ds, 0x042f) | r8[al]);
    r8[al] = memoryAGet(ds, 0x048b);
    r8[al] |= memoryAGet(ds, 0x04ba);
    r8[al] |= memoryAGet(ds, 0x046b);
    r8[al] |= memoryAGet(ds, 0x0466);
    memoryASet(ds, 0x0430, memoryAGet(ds, 0x0430) | r8[al]);
    r8[al] = memoryAGet(ds, 0x045c);
    r8[al] |= memoryAGet(ds, 0x0479);
    r8[al] |= memoryAGet(ds, 0x04b4);
    r8[al] |= memoryAGet(ds, 0x0497);
    memoryASet(ds, 0x042b, memoryAGet(ds, 0x042b) | r8[al]);
    r8[al] = memoryAGet(ds, 0x0459);
    r8[al] |= memoryAGet(ds, 0x0484);
    memoryASet(ds, 0x042c, memoryAGet(ds, 0x042c) | r8[al]);
    r16[bp] = pop();
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
}
function* sub_10b7b() // 1020:097b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x10b7b; break; }
  case 0x10aea: // 1020:08ea
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0x0003;
    interrupt(0x10);
    r8[ah] = 0x09;
    r16[dx] = 0x0077;
    interrupt(0x21);
    { pc = 0x10b6c; break; }
  case 0x10afd: // 1020:08fd
    r16[ax] = 0x0003;
    interrupt(0x10);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r8[ah] = 0x09;
    r16[dx] = 0x008a;
    interrupt(0x21);
    { pc = 0x10b6c; break; }
  case 0x10b10: // 1020:0910
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    r16[ax] = 0x0003;
    interrupt(0x10);
    r16[di] = r16[dx];
    push(r16[dx]);
    if (!memoryAGet(ds, 0x0417))
        { pc = 0x10b2d; break; }
    r8[ah] = 0x09;
    r16[dx] = 0x009e;
    interrupt(0x21);
    { pc = 0x10b34; break; }
  case 0x10b2d: // 1020:092d
    r8[ah] = 0x09;
    r16[dx] = 0x00b1;
    interrupt(0x21);
  case 0x10b34: // 1020:0934
    r16[cx] = 0x005a;
    r16[ax] = 0;
    for (flags.zero = 0; r16[cx] != 0 && !flags.zero; --r16[cx]) scasb_inv_ESDI(r8[al]);
    memoryASet(ds, r16[di], 0x24);
    r16[dx] = pop();
    r8[ah] = 0x09;
    interrupt(0x21);
    if (memoryAGet(ds, 0x0417) == 0x01)
        { pc = 0x10b6c; break; }
    memoryASet(ds, 0x04c3, 0x00);
    r8[ah] = 0x09;
    r16[dx] = 0x00d5;
    interrupt(0x21);
    memoryASet(ds, 0x04c0, 0x00);
  case 0x10b5b: // 1020:095b
    r8[al] = memoryAGet(ds, 0x04c0);
    if (r8[al] != 0x1c)
        { pc = 0x10b5b; break; }
    yield* sub_13360();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    { pc = 0x10b7b; break; }
  case 0x10b6c: // 1020:096c
    r8[ah] = 0x09;
    r16[dx] = 0x0109;
    interrupt(0x21);
    memoryASet(ds, 0x04c3, 0x00);
    flags.interrupts = 1;
  case 0x10b79: // 1020:0979
    { pc = 0x10b79; break; }
  case 0x10b7b: // 1020:097b
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    memoryASet(cs, 0x6bb3, 0x01);
    r16[ax] = 0x3d00;
    interrupt(0x21);
    memoryASet(cs, 0x6bb3, 0x00);
    if (!flags.carry)
        { pc = 0x10b98; break; }
    { pc = 0x10b10; break; }
  case 0x10b98: // 1020:0998
    memoryASet16(cs, 0x0af2, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x04c1);
    memoryASet16(cs, 0x0af4, r16[ax]);
    ds = r16[ax];
    memoryASet(cs, 0x6bb3, 0x01);
    r16[bx] = memoryAGet16(cs, 0x0af2);
    r16[cx] = 0x0006;
    r16[dx] = 0x041a;
    r8[ah] = 0x3f;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x10bbf; break; }
    { pc = 0x10afd; break; }
  case 0x10bbf: // 1020:09bf
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    r16[si] = r16[dx];
    r16[ax] = lodsw_DSSI();
    if (r8[ah] != 0x10)
        { pc = 0x10bcf; break; }
    { pc = 0x10cf6; break; }
  case 0x10bcf: // 1020:09cf
    r16[bx] = r16[ax];
    r16[ax] = lodsw_DSSI();
    r16[cx] = 0x0004;
  case 0x10bd5: // 1020:09d5
    flags.carry = r16[bx] & 1;
    r16[bx] >>= 1;
    r16[ax] = rcr16(r16[ax], 0x0001);
    if (--r16[cx])
        { pc = 0x10bd5; break; }
    r16[ax]++;
    r16[cx] = memoryAGet16(ds, r16[si]);
    r16[ax] += memoryAGet16(es, 0x04c1);
    memoryASet16(es, 0x04c1, r16[ax]);
    ds = r16[ax];
    r16[ax] = memoryAGet16(cs, 0x0af4);
    es = r16[ax];
    memoryASet(cs, 0x6bb3, 0x01);
    r16[bx] = memoryAGet16(cs, 0x0af2);
    r16[cx] = r16[cx];
    r16[dx] = 0x0006;
    r8[ah] = 0x3f;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x10c08; break; }
    { pc = 0x10afd; break; }
  case 0x10c08: // 1020:0a08
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    r8[dl] = 0x01;
    memoryASet16(ds, 0x0000, 0x0002);
    r16[di] = 0;
  case 0x10c17: // 1020:0a17
    r16[bx] = 0;
    saveSp();
    yield* sub_10cbe();
    if (dropsSp()) return;
    if (!r8[bh])
        { pc = 0x10c66; break; }
    if (r8[bl] < 0x02)
        { pc = 0x10c35; break; }
    r8[cl] = r8[bl];
    r8[ch] = 0;
    r16[bp] = r16[ax];
    r8[al] = memoryAGet(es, r16[di] - 1);
    for (; r16[cx] != 0; --r16[cx]) stosb_ESDI(r8[al]);
    r16[ax] = r16[bp];
    { pc = 0x10c6a; break; }
  case 0x10c35: // 1020:0a35
    if (r8[bl])
        { pc = 0x10c4c; break; }
    r16[bx] = 0;
    yield* sub_10cbe();
    r16[bp] = r16[ax];
    r16[cx] = r16[bx];
    r8[al] = memoryAGet(es, r16[di] - 1);
    for (; r16[cx] != 0; --r16[cx]) stosb_ESDI(r8[al]);
    r16[ax] = r16[bp];
    { pc = 0x10c6a; break; }
  case 0x10c4c: // 1020:0a4c
    r16[bx] = 0;
    saveSp();
    yield* sub_10cbe();
    if (dropsSp()) return;
    r8[ch] = r8[bl];
    r16[bx] = 0;
    saveSp();
    yield* sub_10cbe();
    if (dropsSp()) return;
    r8[cl] = r8[bl];
    r16[bp] = r16[ax];
    r8[al] = memoryAGet(es, r16[di] - 1);
    for (; r16[cx] != 0; --r16[cx]) stosb_ESDI(r8[al]);
    r16[ax] = r16[bp];
    { pc = 0x10c6a; break; }
  case 0x10c66: // 1020:0a66
    memoryASet(es, r16[di], r8[bl]);
    r16[di]++;
  case 0x10c6a: // 1020:0a6a
    if (r16[di] < 0x4000)
        { pc = 0x10c17; break; }
    r16[bx] = es;
    r16[bx] += 0x03ff;
    es = r16[bx];
    r16[di] -= 0x3ff0;
    { pc = 0x10c6a; break; }
    // gap 120 bytes // gap 120 bytes
  case 0x10cf6: // 1020:0af6
    r16[dx] = 0;
    r16[cx] = 0;
    r16[ax] = 0x4200;
    memoryASet(cs, 0x6bb3, 0x01);
    interrupt(0x21);
    memoryASet(cs, 0x6bb3, 0x00);
    r16[ax] = 0x168f;
    es = r16[ax];
    r16[ax] = memoryAGet16(cs, 0x0af4);
    ds = r16[ax];
    r16[cx] = 0x0004;
    r16[dx] = 0x000e;
    r16[bx] = memoryAGet16(cs, 0x0af2);
    r8[ah] = 0x3f;
    memoryASet(cs, 0x6bb3, 0x01);
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x10d30; break; }
    { pc = 0x10afd; break; }
  case 0x10d30: // 1020:0b30
    memoryASet(cs, 0x6bb3, 0x00);
    r8[al] = memoryAGet(ds, 0x000f);
    r8[al] &= 0xf0;
    if (r8[al] == 0x10)
        { pc = 0x10d42; break; }
    { pc = 0x10aea; break; }
  case 0x10d42: // 1020:0b42
    r16[di] = 0;
    r16[bx] = memoryAGet16(ds, 0x000e);
    r16[ax] = memoryAGet16(ds, 0x0010);
    r16[cx] = 0x0004;
  case 0x10d4e: // 1020:0b4e
    flags.carry = r16[bx] & 1;
    r16[bx] >>= 1;
    r16[ax] = rcr16(r16[ax], 0x0001);
    if (--r16[cx])
        { pc = 0x10d4e; break; }
    r16[ax]++;
    r16[ax] += memoryAGet16(es, 0x04c1);
    memoryASet16(es, 0x04c1, r16[ax]);
    ds = r16[ax];
    r16[ax] = memoryAGet16(cs, 0x0af4);
    es = r16[ax];
    memoryASet16(ds, 0x0000, r16[di]);
    memoryASet16(ds, 0x0002, r16[di]);
  case 0x10d6e: // 1020:0b6e
    yield* sub_10e1e();
    yield* sub_10e30();
    flags.zero = r16[ax] == 0x0101;
    if (flags.zero)
        { pc = 0x10d8b; break; }
    memoryASet16(ds, 0x0005, r16[ax]);
    memoryASet(ds, 0x0004, r8[al]);
    stosb_ESDI(r8[al]);
  case 0x10d80: // 1020:0b80
    yield* sub_10e30();
    if (r16[ax] == 0x0100)
        { pc = 0x10d6e; break; }
    flags.zero = r16[ax] == 0x0101;
  case 0x10d8b: // 1020:0b8b
    if (flags.zero)
        { pc = 0x10e02; break; }
    memoryASet16(ds, 0x0007, r16[ax]);
    r16[si] = 0x4010;
    if (memoryAGet16(ds, 0x000c) > r16[ax])
        { pc = 0x10da3; break; }
    r8[dl] = memoryAGet(ds, 0x0004);
    memoryASet(ds, r16[si], r8[dl]);
    r16[si]++;
    r16[ax] = memoryAGet16(ds, 0x0005);
  case 0x10da3: // 1020:0ba3
    if (!r8[ah])
        { pc = 0x10db8; break; }
    r16[bx] = r16[ax];
    r8[dl] = memoryAGet(ds, r16[bx] + 4112);
    memoryASet(ds, r16[si], r8[dl]);
    r16[si]++;
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 8208);
    { pc = 0x10da3; break; }
  case 0x10db8: // 1020:0bb8
    memoryASet(ds, r16[si], r8[al]);
    r16[si]++;
    memoryASet(ds, 0x0004, r8[al]);
  case 0x10dbe: // 1020:0bbe
    r16[si]--;
    r8[al] = memoryAGet(ds, r16[si]);
    stosb_ESDI(r8[al]);
    if (r16[di] < 0x8000)
        { pc = 0x10dd3; break; }
    r16[ax] = es;
    r16[ax] += 0x0800;
    es = r16[ax];
    r16[di] -= 0x8000;
  case 0x10dd3: // 1020:0bd3
    if (r16[si] != 0x4010)
        { pc = 0x10dbe; break; }
    r16[bx] = memoryAGet16(ds, 0x000c);
    if (r16[bx] >= 0x1000)
        { pc = 0x10df9; break; }
    r8[dl] = memoryAGet(ds, 0x0004);
    memoryASet(ds, r16[bx] + 4112, r8[dl]);
    r16[dx] = memoryAGet16(ds, 0x0005);
    r16[bx] <<= 1;
    memoryASet16(ds, r16[bx] + 8208, r16[dx]);
    memoryASet16(ds, 0x000c, memoryAGet16(ds, 0x000c) + 1);
  case 0x10df9: // 1020:0bf9
    r16[ax] = memoryAGet16(ds, 0x0007);
    memoryASet16(ds, 0x0005, r16[ax]);
    { pc = 0x10d80; break; }
  case 0x10e02: // 1020:0c02
    memoryASet(ds, 0x04c3, 0x01);
    r16[bx] = memoryAGet16(cs, 0x0af2);
    r8[ah] = 0x3e;
    interrupt(0x21);
    memoryASet(ds, 0x04c3, memoryAGet(ds, 0x04c3) - 1);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = memoryAGet16(cs, 0x0af4);
    return;
  }
}
function* sub_10cbe() // 1020:0abe
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x10cbe; break; }
  case 0x10afd: // 1020:08fd
    r16[ax] = 0x0003;
    interrupt(0x10);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r8[ah] = 0x09;
    r16[dx] = 0x008a;
    interrupt(0x21);
    { pc = 0x10b6c; break; }
    // gap 92 bytes // gap 92 bytes
  case 0x10b6c: // 1020:096c
    r8[ah] = 0x09;
    r16[dx] = 0x0109;
    interrupt(0x21);
    memoryASet(ds, 0x04c3, 0x00);
    flags.interrupts = 1;
  case 0x10b79: // 1020:0979
    { pc = 0x10b79; break; }
    // gap 259 bytes // gap 259 bytes
  case 0x10c7e: // 1020:0a7e
    memoryASet16(ds, 0x0000, memoryAGet16(ds, 0x0000) - 0x0002);
    if (memoryAGet16(ds, 0x0000))
        { pc = 0x10cb9; break; }
    push(r16[bx]);
    push(r16[di]);
    memoryASet(cs, 0x6bb3, 0x01);
    r16[bx] = memoryAGet16(cs, 0x0af2);
    r16[cx] = 0x1000;
    r16[dx] = 0x041a;
    r8[ah] = 0x3f;
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x10ca1; break; }
    { pc = 0x10afd; break; }
  case 0x10ca1: // 1020:0aa1
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    memoryASet16(ds, 0x0000, r16[ax]);
    r16[di] = pop();
    r16[bx] = pop();
    if (!r16[ax])
        { pc = 0x10cd3; break; }
    flags.carry = r16[ax] & 1;
    r16[ax] >>= 1;
    memoryASet16(ds, 0x0000, memoryAGet16(ds, 0x0000) + (0x0000 + flags.carry));
    r16[si] = 0x041a;
  case 0x10cb9: // 1020:0ab9
    r16[ax] = lodsw_DSSI();
    r8[tl] = r8[ah]; r8[ah] = r8[al]; r8[al] = r8[tl];
    r8[dl] = 0x11;
  case 0x10cbe: // 1020:0abe
    r8[dl]--;
    if (!r8[dl])
        { pc = 0x10c7e; break; }
    flags.carry = !!(r16[ax] & 0x8000);
    r16[ax] = rol16(r16[ax], 0x0001);
    if (!flags.carry)
        { pc = 0x10cc8; break; }
    r16[bx]++;
    r16[bx]++;
  case 0x10cc8: // 1020:0ac8
    r16[bx] = memoryAGet16(ds, r16[bx] + 6);
    if (r8s[bh] >= 0)
        { pc = 0x10cbe; break; }
    r8[bh] &= 0x7f;
    return;
  case 0x10cd3: // 1020:0ad3
    r16[ax] = pop();
    //stop("stack_below");
    memoryASet(cs, 0x6bb3, 0x01);
    r16[bx] = memoryAGet16(cs, 0x0af2);
    r8[ah] = 0x3e;
    interrupt(0x21);
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = memoryAGet16(cs, 0x0af4);
    //stop("stack_unbalanced");
    return;
  }
}
function* sub_10e1e() // 1020:0c1e
{
    memoryASet16(ds, 0x000a, 0x0200);
    memoryASet(ds, 0x0009, 0x09);
    memoryASet16(ds, 0x000c, 0x0102);
}
function* sub_10e30() // 1020:0c30
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x10e30; break; }
  case 0x10afd: // 1020:08fd
    r16[ax] = 0x0003;
    interrupt(0x10);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r8[ah] = 0x09;
    r16[dx] = 0x008a;
    interrupt(0x21);
    { pc = 0x10b6c; break; }
    // gap 92 bytes // gap 92 bytes
  case 0x10b6c: // 1020:096c
    r8[ah] = 0x09;
    r16[dx] = 0x0109;
    interrupt(0x21);
    memoryASet(ds, 0x04c3, 0x00);
    flags.interrupts = 1;
  case 0x10b79: // 1020:0979
    { pc = 0x10b79; break; }
    // gap 693 bytes // gap 693 bytes
  case 0x10e30: // 1020:0c30
    r16[ax] = memoryAGet16(ds, 0x000c);
    if (memoryAGet16(ds, 0x000a) != r16[ax])
        { pc = 0x10e48; break; }
    if (memoryAGet(ds, 0x0009) == 0x0c)
        { pc = 0x10e48; break; }
    memoryASet(ds, 0x0009, memoryAGet(ds, 0x0009) + 1);
    memoryASet16(ds, 0x000a, memoryAGet16(ds, 0x000a) << 1);
  case 0x10e48: // 1020:0c48
    r16[bx] = memoryAGet16(ds, 0x0002);
    r16[si] = r16[bx];
    flags.carry = r8[bl] + memoryAGet(ds, 0x0009) >= 0x100;
    r8[bl] += memoryAGet(ds, 0x0009);
    r8[bh] += (0x00 + flags.carry);
    if (memoryAGet16(ds, 0x0000) >= r16[bx])
        { pc = 0x10eaf; break; }
    r16[cx] = 0x1000;
    r16[dx] = 0x0010;
    r16[bx] = 0x0010;
    r16[bx] -= memoryAGet16(ds, 0x0000);
    r16[bx] += memoryAGet16(ds, 0x0002);
    memoryASet16(ds, 0x0002, r16[bx]);
    r16[si] = r16[bx];
    r16[ax] = memoryAGet16(ds, 0x100e);
    memoryASet16(ds, 0x000e, r16[ax]);
    r16[bx] = memoryAGet16(cs, 0x0af2);
    r8[ah] = 0x3f;
    memoryASet(cs, 0x6bb3, 0x01);
    interrupt(0x21);
    if (!flags.carry)
        { pc = 0x10e8c; break; }
    { pc = 0x10afd; break; }
  case 0x10e8c: // 1020:0c8c
    memoryASet(cs, 0x6bb3, memoryAGet(cs, 0x6bb3) - 1);
    r16[ax]++;
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    memoryASet16(ds, 0x0000, r16[ax]);
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
  case 0x10eaf: // 1020:0caf
    r16[cx] = r16[si];
    r16[si] >>= 1;
    r16[si] >>= 1;
    r16[si] >>= 1;
    r8[cl] &= 0x07;
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    r8[tl] = r8[ah]; r8[ah] = r8[al]; r8[al] = r8[tl];
    r8[dh] = 0;
    r16[ax] <<= r8[cl];
    r8[ch] = 0x10;
    r8[ch] -= r8[cl];
    flags.carry = r8[ch] < memoryAGet(ds, 0x0009);
    r8[ch] -= memoryAGet(ds, 0x0009);
    if (!flags.carry)
        { pc = 0x10ed8; break; }
    r8[ch] = -r8[ch];
    r8[cl] = 0x08;
    r8[cl] -= r8[ch];
    r8[dh] = memoryAGet(ds, r16[si] + 16);
    r8[dh] >>= r8[cl];
  case 0x10ed8: // 1020:0cd8
    r8[bl] = memoryAGet(ds, 0x0009);
    r8[bh] = 0;
    memoryASet16(ds, 0x0002, memoryAGet16(ds, 0x0002) + r16[bx]);
    r8[cl] = 0x10;
    r8[cl] -= r8[bl];
    r16[ax] >>= r8[cl];
    r8[al] |= r8[dh];
    return;
  }
}
function* sub_10eeb() // 1020:0ceb
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0;
    es = r16[ax];
    r16[si] = 0x0433;
    r16[di] = 0x0020;
    r16[cx] = 0x0004;
    flags.interrupts = 0;
    flags.direction = 0;
  case 0x10f05: // 1020:0d05
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[tx] = memoryAGet16(ds, r16[si]); memoryASet16(ds, r16[si], r16[ax]); r16[ax] = r16[tx];
    stosw_ESDI(r16[ax]);
    r16[si]++;
    r16[si]++;
    if (--r16[cx])
        { pc = 0x10f05; break; }
    push(ds);
    es = pop();
    r16[di] = 0x0440;
    r16[ax] = 0;
    r16[cx] = 0x0040;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    flags.interrupts = 1;
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_1127d() // 1020:107d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    flags.interrupts = 0;
    push(ds);
    push(es);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0;
    es = r16[ax];
    push(memoryAGet16(es, 0x0018));
    push(memoryAGet16(es, 0x001a));
    memoryASet16(es, 0x0018, 0x10bc);
    memoryASet16(es, 0x001a, cs);
    r8[al] = 0x01;
    r8[cl] = 0x20;
    r8[al] <<= r8[cl];
    if (r8[al] == 0x01)
        { pc = 0x112b1; break; }
    memoryASet(cs, 0x0004, 0x00);
    { pc = 0x112c5; break; }
  case 0x112b1: // 1020:10b1
    r16[ax] = 0;
    memoryASet(cs, 0x0004, 0x03);
    { pc = 0x112c5; break; }
    // gap 9 bytes // gap 9 bytes
  case 0x112c5: // 1020:10c5
    memoryASet16(es, 0x001a, pop());
    memoryASet16(es, 0x0018, pop());
    flags.interrupts = 1;
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_112d3() // 1020:10d3
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet(ds, 0x651a, 0x00);
  case 0x112dd: // 1020:10dd
    /*
    r16[ax] = memoryAGet16(ds, 0x0431);
    r16[ax] -= memoryAGet16(cs, 0x16e0);
    if (r16s[ax] >= 0)
        { pc = 0x112e9; break; }
    r16[ax] = -r16[ax];
  case 0x112e9: // 1020:10e9
    if (r16[ax] < 0x0002)
        { pc = 0x112dd; break; }
    if (r16[ax] > 0x0002)
        { pc = 0x112f7; break; }
    yield* sub_13443();
    */
    memoryASet(ds, 0x651a, memoryAGet(ds, 0x651a) + 1);
  case 0x112f7: // 1020:10f7
    r16[ax] = memoryAGet16(cs, 0x16e0);
    memoryASet16(ds, 0x0431, r16[ax]);
    return;
  }
}
function* sub_112ff() // 1020:10ff
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[dx] = 0x168f;
    ds = r16[dx];
    es = r16[dx];
    r16[bx] = r16[ax];
    if (memoryAGet(ds, r16[bx] + 1285) == 0x01)
        { pc = 0x1131d; break; }
    memoryASet16(ds, 0x0913, r16[ax]);
    { pc = 0x1131d; break; }
  case 0x1131d: // 1020:111d
    memoryASet(cs, 0x16e4, memoryAGet(cs, 0x16e4) | 0x01);
    flags.interrupts = 0;
    if (memoryAGet(cs, 0x16e3) == 0x01)
        { pc = 0x11357; break; }
    r16[bx] = r16[ax];
    r8[al] = memoryAGet(ds, r16[bx] + 2466);
    memoryASet(ds, 0x0980, r8[al]);
    memoryASet(ds, 0x0981, r8[al]);
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 2434);
    memoryASet(cs, 0x70a2, 0x01);
    memoryASet16(ds, 0x0b07, r16[ax]);
    if (!(memoryAGet(cs, 0x16e4) & 0x02))
        { pc = 0x1138d; break; }
    r8[al] = in8(0x61);
    r8[al] |= 0x03;
    out8(0x61, r8[al]);
    { pc = 0x1138d; break; }
  case 0x11357: // 1020:1157
    yield* sub_1184f();
    r16[bx] = 0x0515;
    r16[cx] = r16[ax];
    if (!r16[cx])
        { pc = 0x1136b; break; }
  case 0x11361: // 1020:1161
    r16[bx]++;
    r16[bx]++;
    if (memoryAGet16(ds, r16[bx] - 2) != 0xffff)
        { pc = 0x11361; break; }
    if (--r16[cx])
        { pc = 0x11361; break; }
  case 0x1136b: // 1020:116b
    r16[cx] = r16[ax];
    r16[ax] = r16[bx];
    r16[bx] = 0x0675;
    if (!r16[cx])
        { pc = 0x1137e; break; }
  case 0x11374: // 1020:1174
    r16[bx]++;
    r16[bx]++;
    if (memoryAGet16(ds, r16[bx] - 2) != 0xffff)
        { pc = 0x11374; break; }
    if (--r16[cx])
        { pc = 0x11374; break; }
  case 0x1137e: // 1020:117e
    r16[si] = r16[bx];
  case 0x11380: // 1020:1180
    r16[si]++;
    r16[si]++;
    if (memoryAGet16(ds, r16[si]) != 0xffff)
        { pc = 0x11380; break; }
    r16[cx] = memoryAGet16(ds, r16[si] - 2);
    yield* sub_11469();
  case 0x1138d: // 1020:118d
    flags.interrupts = 1;
    r16[bp] = pop();
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
}
function* sub_11398() // 1020:1198
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (!memoryAGet(cs, 0x0002))
        { pc = 0x113d2; break; }
    r16[ax] = 0x2001;
    yield* sub_117a7();
    yield* sub_11810();
    if (flags.carry)
        { pc = 0x113d2; break; }
    flags.interrupts = 0;
    r16[ax] = 0x0008;
    yield* sub_117a7();
    r16[ax] = 0x00bd;
    yield* sub_117a7();
    yield* sub_1184f();
    memoryASet(cs, 0x16e3, 0x01);
    flags.interrupts = 1;
    { pc = 0x113dc; break; }
  case 0x113d2: // 1020:11d2
    r8[al] = 0xb6;
    out8(0x43, r8[al]);
    r8[al] = in8(0x61);
    r8[al] |= 0x03;
    out8(0x61, r8[al]);
  case 0x113dc: // 1020:11dc
    r16[bp] = pop();
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
}
function* sub_113e6() // 1020:11e6
{
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[bx] = 0x168f;
    ds = r16[bx];
    memoryASet16(ds, 0x0172, 0x000f);
    r8[bl] = r8[al];
    r8[bh] = 0;
    r16[bx] <<= 1;
    r16[bx] = memoryAGet16(ds, r16[bx] + 342);
    memoryASet(ds, 0x0174, 0x01);
    flags.interrupts = 0;
    r8[dl] = 0x13;
    yield* sub_117de();
    r8[dl] -= 0x03;
    r16[bx] += 0x0005;
    yield* sub_117de();
    r8[ah] = memoryAGet(ds, r16[bx] + 5);
    r8[al] = 0xc6;
    yield* sub_117a7();
    flags.interrupts = 1;
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_11469() // 1020:1269
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[si]);
    push(r16[di]);
    memoryASet(cs, 0x16e2, 0x00);
    memoryASet(ds, 0x0981, r8[cl]);
    memoryASet(ds, 0x0980, r8[cl]);
    memoryASet16(ds, 0x0917, r16[bx]);
    r16[di] = 0x09b3;
    r16[si] = r16[ax];
    r16[ax] = 0;
    r16[dx] = 0;
    memoryASet(ds, 0x09b2, 0xff);
  case 0x1148d: // 1020:128d
    r16[cx] = 0x0011;
    for (; r16[cx] != 0; --r16[cx]) stosb_ESDI(r8[al]);
    r16[cx] = memoryAGet16(ds, r16[si]);
    r16[si]++;
    r16[si]++;
    memoryASet(ds, 0x09b2, memoryAGet(ds, 0x09b2) + 1);
    memoryASet16(ds, r16[di] - 4, r16[cx]);
    memoryASet(ds, r16[di] - 12, r8[dl]);
    r16[dx]++;
    if (r16[cx] != 0xffff)
        { pc = 0x1148d; break; }
    r16[di] = pop();
    r16[si] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_117a7() // 1020:15a7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[dx]);
    push(r16[ax]);
    push(r16[cx]);
    if (memoryAGet(cs, 0x0004) >= 0x03)
        { pc = 0x117c8; break; }
    r16[dx] = 0x0388;
    out8(r16[dx], r8[al]);
    r16[cx] = 0x0005;
  case 0x117b9: // 1020:15b9
    if (--r16[cx])
        { pc = 0x117b9; break; }
    r16[dx]++;
    r8[al] = r8[ah];
    out8(r16[dx], r8[al]);
    r16[cx] = 0x0023;
  case 0x117c2: // 1020:15c2
    if (--r16[cx])
        { pc = 0x117c2; break; }
    r16[cx] = pop();
    r16[ax] = pop();
    r16[dx] = pop();
    return;
  case 0x117c8: // 1020:15c8
    r16[dx] = 0x0388;
    out8(r16[dx], r8[al]);
    r16[cx] = 0x0014;
  case 0x117cf: // 1020:15cf
    if (--r16[cx])
        { pc = 0x117cf; break; }
    r16[dx]++;
    r8[al] = r8[ah];
    out8(r16[dx], r8[al]);
    r16[cx] = 0x008c;
  case 0x117d8: // 1020:15d8
    if (--r16[cx])
        { pc = 0x117d8; break; }
    r16[cx] = pop();
    r16[ax] = pop();
    r16[dx] = pop();
    return;
  }
}
function* sub_117de() // 1020:15de
{
    r8[ah] = memoryAGet(ds, r16[bx]);
    r8[al] = r8[dl];
    r8[al] += 0x60;
    yield* sub_117a7();
    r8[ah] = memoryAGet(ds, r16[bx] + 1);
    r8[al] = r8[dl];
    r8[al] += 0x80;
    yield* sub_117a7();
    r8[ah] = memoryAGet(ds, r16[bx] + 2);
    r8[al] = r8[dl];
    r8[al] += 0x40;
    yield* sub_117a7();
    r8[ah] = memoryAGet(ds, r16[bx] + 3);
    r8[al] = r8[dl];
    r8[al] += 0x20;
    yield* sub_117a7();
    r8[ah] = memoryAGet(ds, r16[bx] + 4);
    r8[al] = r8[dl];
    r8[al] += 0xe0;
    yield* sub_117a7();
}
function* sub_11810() // 1020:1610 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x6304;
    yield* sub_117a7();
    r16[dx] = 0x0388;
    r16[cx] = 0x2000;
  case 0x1181c: // 1020:161c
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x60;
    if (r8[al])
        { pc = 0x1184d; break; }
    if (--r16[cx])
        { pc = 0x1181c; break; }
    r16[ax] = 0x2304;
    yield* sub_117a7();
    r16[cx] = 0x9fff;
  case 0x1182c: // 1020:162c
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x60;
    if (r8[al] == 0x40)
        { pc = 0x11837; break; }
    if (--r16[cx])
        { pc = 0x1182c; break; }
    { pc = 0x1184d; break; }
  case 0x11837: // 1020:1637
    r16[ax] = 0x4304;
    yield* sub_117a7();
    r16[cx] = 0x9fff;
  case 0x11840: // 1020:1640
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x60;
    if (r8[al] == 0x20)
        { pc = 0x1184b; break; }
    if (--r16[cx])
        { pc = 0x11840; break; }
    { pc = 0x1184d; break; }
  case 0x1184b: // 1020:164b
    flags.carry = 0;
    return;
  case 0x1184d: // 1020:164d
    flags.carry = 1;
    return;
  }
}
function* sub_1184f() // 1020:164f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    r16[ax] = 0x00b0;
  case 0x11853: // 1020:1653
    yield* sub_117a7();
    r16[ax]++;
    if (r8[al] < 0xb9)
        { pc = 0x11853; break; }
    r16[ax] = 0x00a0;
  case 0x1185e: // 1020:165e
    yield* sub_117a7();
    r16[ax]++;
    if (r8[al] < 0xb9)
        { pc = 0x1185e; break; }
    r16[ax] = 0x0008;
    yield* sub_117a7();
    r16[ax] = 0x00bd;
    yield* sub_117a7();
    r16[ax] = 0x3f40;
    yield* sub_117a7();
    r16[ax] = 0x3f41;
    yield* sub_117a7();
    r16[ax] = 0x3f42;
    yield* sub_117a7();
    r16[ax] = 0x3f43;
    yield* sub_117a7();
    r16[ax] = 0x3f44;
    yield* sub_117a7();
    r16[ax] = 0x3f45;
    yield* sub_117a7();
    r16[ax] = 0x3f48;
    yield* sub_117a7();
    r16[ax] = 0x3f49;
    yield* sub_117a7();
    r16[ax] = 0x3f4a;
    yield* sub_117a7();
    r16[ax] = 0x3f4b;
    yield* sub_117a7();
    r16[ax] = 0x3f4c;
    yield* sub_117a7();
    r16[ax] = 0x3f4d;
    yield* sub_117a7();
    r16[ax] = 0x3f50;
    yield* sub_117a7();
    r16[ax] = 0x3f51;
    yield* sub_117a7();
    r16[ax] = 0x3f52;
    yield* sub_117a7();
    r16[ax] = 0x3f53;
    yield* sub_117a7();
    r16[ax] = 0x3f54;
    yield* sub_117a7();
    r16[ax] = 0x3f55;
    yield* sub_117a7();
    r16[ax] = pop();
    return;
  }
}
function* sub_119eb() // 1020:17eb
{
  var pc = 0x119eb;
  while (1) switch(pc)
  {
  case 0x119eb: // 1020:17eb
    yield* sync(); return;
    r8[al] = memoryAGet(cs, 0x16e4);
    r8[al] &= 0x03;
    if (r8[al] != 0x03)
        { pc = 0x119fc; break; }
    if (memoryAGet(ds, 0x09b2))
        { pc = 0x119eb; break; }
  case 0x119fc: // 1020:17fc
    return;
  }
}
function* sub_119fe() // 1020:17fe
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    r8[ah] = 0x04;
    interrupt(0x1a);
    if (flags.carry)
        { pc = 0x11a3d; break; }
    push(r16[dx]);
    r16[ax] = 0;
    r8[bl] = 0x04;
    r16[bp] = 0x000a;
  case 0x11a11: // 1020:1811
    mul16(r16[bp]);
    flags.carry = !!(r16[cx] & 0x8000);
    r16[cx] <<= 1;
    r8[dh] = rcl8(r8[dh], 0x01);
    flags.carry = !!(r16[cx] & 0x8000);
    r16[cx] <<= 1;
    r8[dh] = rcl8(r8[dh], 0x01);
    flags.carry = !!(r16[cx] & 0x8000);
    r16[cx] <<= 1;
    r8[dh] = rcl8(r8[dh], 0x01);
    flags.carry = !!(r16[cx] & 0x8000);
    r16[cx] <<= 1;
    r8[dh] = rcl8(r8[dh], 0x01);
    r8[al] += r8[dh];
    r8[bl]--;
    if (r8[bl])
        { pc = 0x11a11; break; }
    r16[dx] = pop();
    if (r16[ax] >= 0x0813)
        { pc = 0x11a3d; break; }
    if (r16[ax] != 0x07c8)
        { pc = 0x11a3a; break; }
    if (r8[dh] >= 0x06)
        { pc = 0x11a3a; break; }
    r16[ax]--;
  case 0x11a3a: // 1020:183a
    memoryASet16(ds, 0x000a, r16[ax]);
  case 0x11a3d: // 1020:183d
    return;
  }
}
function* sub_11a3f() // 1020:183f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x11a3f; break; }
  case 0x11a3e: // 1020:183e
    return;
  case 0x11a3f: // 1020:183f
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (memoryAGet16(ds, 0x000a) < 0x07cc)
        { pc = 0x11a3e; break; }
    yield* sub_129df();
    yield* sub_1058a();
    memoryASet16(ds, 0x01f5, 0x0005);
    memoryASet16(ds, 0x01f7, 0x0960);
    r16[si] = 0x4e6e;
    yield* sub_10688();
    memoryASet16(ds, 0x01f5, 0x0000);
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    r16[si] = 0x4e7a;
    yield* sub_10688();
    r16[dx] = memoryAGet16(ds, 0x000a);
    yield* sub_10623();
    r16[si] = 0x4e9a;
    yield* sub_10688();
    memoryASet16(ds, 0x01f5, 0x0001);
    memoryASet16(ds, 0x01f7, 0x1680);
    r16[si] = 0x4e9e;
    yield* sub_10688();
    memoryASet16(ds, 0x01f5, 0x0003);
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    r16[si] = 0x4ec3;
    yield* sub_10688();
    yield* sub_105f2();
    yield* sub_129df();
    return;
  }
}
function* sub_11aaf() // 1020:18af
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x11aaf; break; }
  case 0x11aae: // 1020:18ae
    return;
  case 0x11aaf: // 1020:18af
    r8[al] = memoryAGet(ds, 0x045d);
    r8[al] &= memoryAGet(ds, 0x0478);
    r8[ah] = r8[al];
    r8[ah] &= memoryAGet(ds, 0x0451);
    if (r8[ah])
        { pc = 0x11ac4; break; }
    r8[al] &= memoryAGet(ds, 0x0450);
    if (!r8[al])
        { pc = 0x11aae; break; }
  case 0x11ac4: // 1020:18c4
    r16[bx] = 0x0001;
    r8[al] = 0;
  case 0x11ac9: // 1020:18c9
    if (r8[bl] == 0x10)
        { pc = 0x11ae3; break; }
    if (r8[bl] == 0x11)
        { pc = 0x11ae3; break; }
    if (r8[bl] == 0x1d)
        { pc = 0x11ae3; break; }
    if (r8[bl] == 0x38)
        { pc = 0x11ae3; break; }
    r8[al] |= memoryAGet(ds, r16[bx] + 1088);
    if (r8[al])
        { pc = 0x11aae; break; }
  case 0x11ae3: // 1020:18e3
    r16[bx]++;
    if (r8[bl] < 0x7f)
        { pc = 0x11ac9; break; }
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    if (!memoryAGet(ds, 0x0450))
        { pc = 0x11b09; break; }
    if (memoryAGet(ds, 0x041a) < 0x0a)
        { pc = 0x11b09; break; }
    memoryASet(ds, 0x041b, memoryAGet(ds, 0x041b) + 1);
    memoryASet(ds, 0x041a, memoryAGet(ds, 0x041a) - 0x0a);
  case 0x11b09: // 1020:1909
    yield* sub_11b58();
    yield* sub_105f2();
    yield* sub_105ae();
    r16[bp] = pop();
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
}
function* sub_11b1c() // 1020:191c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    yield* sub_13360();
    yield* sub_11b58();
    memoryASet16(ds, 0x043c, 0x0000);
  case 0x11b36: // 1020:1936
    yield* sub_10a05();
    if (memoryAGet(ds, 0x042b))
        { pc = 0x11b48; break; }
    if (memoryAGet16(ds, 0x043c) < 0x0168)
        { pc = 0x11b36; break; }
  case 0x11b48: // 1020:1948
    memoryASet16(ds, 0x043c, 0x0870);
    r16[bp] = pop();
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
}
function* sub_11b58() // 1020:1958
{
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0x0009;
    yield* sub_112ff();
    yield* sub_12a11();
    yield* sub_1058a();
    memoryASet16(ds, 0x01f5, 0x0005);
    memoryASet16(ds, 0x01f7, 0x03c0);
    r16[si] = 0x4ee3;
    yield* sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    r16[si] = 0x4f02;
    yield* sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    r16[si] = 0x4f21;
    yield* sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    r16[si] = 0x4f40;
    yield* sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    r16[si] = 0x4f5f;
    yield* sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    r16[si] = 0x4f7e;
    yield* sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    r16[si] = 0x4f9d;
    yield* sub_10688();
    memoryASet16(ds, 0x01f7, memoryAGet16(ds, 0x01f7) + 0x01e0);
    memoryASet16(ds, 0x01f5, memoryAGet16(ds, 0x01f5) - 0x001e);
    r16[si] = 0x4fbc;
    yield* sub_10688();
    memoryASet16(ds, 0x01f5, 0x000f);
    memoryASet16(ds, 0x01f7, 0x1770);
    r16[si] = 0x4fdb;
    yield* sub_10688();
    memoryASet16(ds, 0x01f5, 0x0000);
    memoryASet16(ds, 0x01f7, 0x1a40);
    r16[si] = 0x4fe5;
    yield* sub_10688();
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_11c2a() // 1020:1a2a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x11c2a; break; }
  case 0x11c29: // 1020:1a29
    return;
  case 0x11c2a: // 1020:1a2a
    r8[al] = memoryAGet(ds, 0x045d);
    r8[al] &= memoryAGet(ds, 0x0478);
    r8[al] &= memoryAGet(ds, 0x0452);
    if (!r8[al])
        { pc = 0x11c29; break; }
    r16[bx] = 0x0001;
    r8[al] = 0;
  case 0x11c3c: // 1020:1a3c
    if (r8[bl] == 0x12)
        { pc = 0x11c51; break; }
    if (r8[bl] == 0x1d)
        { pc = 0x11c51; break; }
    if (r8[bl] == 0x38)
        { pc = 0x11c51; break; }
    r8[al] |= memoryAGet(ds, r16[bx] + 1088);
    if (r8[al])
        { pc = 0x11c29; break; }
  case 0x11c51: // 1020:1a51
    r16[bx]++;
    if (r8[bl] < 0x7f)
        { pc = 0x11c3c; break; }
    { pc = 0x11c61; break; }
    // gap 8 bytes // gap 8 bytes
  case 0x11c61: // 1020:1a61
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[dx] = 0x500e;
    push(ds);
    push(es);
    yield* sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, r16[ax]);
    memoryASet16(ds, 0x4e52, r16[ax]);
    yield* sub_11c8d();
    r16[ax] = 0x0009;
    yield* sub_112ff();
    r16[bp] = pop();
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
}
function* sub_11c59() // 1020:1a59
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x11c59; break; }
  case 0x11c29: // 1020:1a29
    return;
    // gap 47 bytes // gap 47 bytes
  case 0x11c59: // 1020:1a59
    if (memoryAGet16(ds, 0x000a) < 0x07c8)
        { pc = 0x11c29; break; }
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[dx] = 0x500e;
    push(ds);
    push(es);
    yield* sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, r16[ax]);
    memoryASet16(ds, 0x4e52, r16[ax]);
    yield* sub_11c8d();
    r16[ax] = 0x0009;
    yield* sub_112ff();
    r16[bp] = pop();
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
}
function* sub_11c8d() // 1020:1a8d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_13360();
    if (memoryAGet(cs, 0x0001) != 0x05)
        { pc = 0x11ce4; break; }
    r16[ax] = 0x000d;
    interrupt(0x10);
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    r16[dx] = 0x4e54;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[dx] = 0x03c8;
    r8[al] = 0;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r16[cx] = 0x0010;
    r8[al] = 0;
  case 0x11cb8: // 1020:1ab8
    out8(r16[dx], r8[al]);
    { pc = 0x11cbb; break; }
  case 0x11cbb: // 1020:1abb
    out8(r16[dx], r8[al]);
    { pc = 0x11cbe; break; }
  case 0x11cbe: // 1020:1abe
    out8(r16[dx], r8[al]);
    r8[al] += 0x04;
    if (--r16[cx])
        { pc = 0x11cb8; break; }
    r16[ax] = 0xa000;
    es = r16[ax];
    ds = memoryAGet16(ds, 0x4e52);
    r16[si] = 0;
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
  case 0x11cd4: // 1020:1ad4
    out16(r16[dx], r16[ax]);
    r16[cx] = 0x0fa0;
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r8[ah] <<= 1;
    if (r8[ah] <= 0x08)
        { pc = 0x11cd4; break; }
    return;
  case 0x11ce4: // 1020:1ae4
    if (!memoryAGet(cs, 0x0001))
        { pc = 0x11cf1; break; }
    r16[ax] = 0x0006;
    interrupt(0x10);
  case 0x11cf1: // 1020:1af1
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[ax] = 0;
    r16[di] = 0;
    r16[cx] = 0x3e80;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    memoryASet(ds, 0x4e6a, 0x00);
    memoryASet16(ds, 0x4e68, 0x0000);
    memoryASet(ds, 0x4e6d, 0x00);
    memoryASet16(ds, 0x4e6b, 0x0000);
    r16[bx] = 0;
  case 0x11d17: // 1020:1b17
    yield* sub_11db6();
    push(r16[ax]);
    r16[bx] += r16[ax];
    if (r16s[bx] < signed16(0x0010))
        { pc = 0x11d30; break; }
    yield* sub_11d83();
    yield* sub_11e09();
    r16[ax] &= 0x0001;
    r16[bx] -= 0x0010;
    r16[bx] += r16[ax];
  case 0x11d30: // 1020:1b30
    memoryASet16(ds, 0x4e68, memoryAGet16(ds, 0x4e68) + 1);
    r16[ax] = pop();
    r16[bx] += r16[ax];
    if (r16s[bx] < signed16(0x0010))
        { pc = 0x11d4a; break; }
    yield* sub_11d83();
    yield* sub_11e09();
    r16[ax] &= 0x0001;
    r16[bx] -= 0x0010;
    r16[bx] += r16[ax];
  case 0x11d4a: // 1020:1b4a
    memoryASet16(ds, 0x4e68, memoryAGet16(ds, 0x4e68) + 1);
    if (memoryAGet16(ds, 0x4e68) < 0x0280)
        { pc = 0x11d67; break; }
    memoryASet16(ds, 0x4e68, 0x0000);
    memoryASet(ds, 0x4e6a, memoryAGet(ds, 0x4e6a) + 1);
    if (memoryAGet(ds, 0x4e6a) >= 0xc8)
        { pc = 0x11d82; break; }
  case 0x11d67: // 1020:1b67
    if (memoryAGet16(ds, 0x4e6b) < 0x0140)
        { pc = 0x11d80; break; }
    memoryASet16(ds, 0x4e6b, 0x0000);
    memoryASet(ds, 0x4e6d, memoryAGet(ds, 0x4e6d) + 1);
    if (memoryAGet(ds, 0x4e6d) >= 0xc8)
        { pc = 0x11d82; break; }
  case 0x11d80: // 1020:1b80
    { pc = 0x11d17; break; }
  case 0x11d82: // 1020:1b82
    return;
  }
}
function* sub_11d83() // 1020:1b83
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[di]);
    r8[al] = memoryAGet(ds, 0x4e6a);
    r8[al] >>= 1;
    r8[ah] = 0x50;
    mul8(r8[ah]);
    if (!(memoryAGet(ds, 0x4e6a) & 0x01))
        { pc = 0x11d99; break; }
    r16[ax] += 0x2000;
  case 0x11d99: // 1020:1b99
    r16[di] = r16[ax];
    r16[ax] = memoryAGet16(ds, 0x4e68);
    r8[cl] = 0x03;
    r16[ax] >>= r8[cl];
    r16[di] += r16[ax];
    r8[cl] = memoryAGet(ds, 0x4e68);
    r8[cl] &= 0x07;
    r8[ah] = 0x80;
    r8[ah] >>= r8[cl];
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) | r8[ah]);
    r16[di] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_11db6() // 1020:1bb6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[cx]);
    push(r16[di]);
    r8[al] = memoryAGet(ds, 0x4e6d);
    r8[ah] = 0x28;
    mul8(r8[ah]);
    r16[di] = 0;
    r16[di] &= 0xfff0;
    r16[di] += r16[ax];
    r16[ax] = memoryAGet16(ds, 0x4e6b);
    r8[cl] = 0x03;
    r16[ax] >>= r8[cl];
    r16[di] += r16[ax];
    r8[cl] = memoryAGet(ds, 0x4e6b);
    r8[cl] &= 0x07;
    r8[ah] = 0x80;
    r8[ah] >>= r8[cl];
    r8[al] = 0;
    push(ds);
    ds = memoryAGet16(ds, 0x4e52);
    if (!(memoryAGet(ds, r16[di]) & r8[ah]))
        { pc = 0x11de7; break; }
    r8[al]++;
  case 0x11de7: // 1020:1be7
    if (!(memoryAGet(ds, r16[di] + 8000) & r8[ah]))
        { pc = 0x11def; break; }
    r8[al] += 0x02;
  case 0x11def: // 1020:1bef
    if (!(memoryAGet(ds, r16[di] + 16000) & r8[ah]))
        { pc = 0x11df7; break; }
    r8[al] += 0x04;
  case 0x11df7: // 1020:1bf7
    if (!(memoryAGet(ds, r16[di] + 24000) & r8[ah]))
        { pc = 0x11dff; break; }
    r8[al] += 0x08;
  case 0x11dff: // 1020:1bff
    ds = pop();
    r8[ah] = 0;
    memoryASet16(ds, 0x4e6b, memoryAGet16(ds, 0x4e6b) + 1);
    r16[di] = pop();
    r16[cx] = pop();
    return;
  }
}
function* sub_11e09() // 1020:1c09
{
    r16[ax] = memoryAGet16(ds, 0x4e65);
    r16[ax] += 0x9248;
    r16[ax] = ror16(r16[ax], 0x0001);
    r16[ax] = ror16(r16[ax], 0x0001);
    r16[ax] = ror16(r16[ax], 0x0001);
    memoryASet16(ds, 0x4e65, r16[ax]);
}
function* sub_11e1a() // 1020:1c1a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x11e2f; break; }
    push(r16[dx]);
    push(r16[ax]);
    r16[dx] = 0x03da;
    r8[al] = in8(r16[dx]);
    r8[dl] = 0xc0;
    r8[al] = 0x20;
    out8(r16[dx], r8[al]);
    r16[ax] = pop();
    r16[dx] = pop();
  case 0x11e2f: // 1020:1c2f
    return;
  }
}
function* sub_11e30() // 1020:1c30
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x11e45; break; }
    push(r16[dx]);
    push(r16[ax]);
    r16[dx] = 0x03da;
    r8[al] = in8(r16[dx]);
    r8[dl] = 0xc0;
    r8[al] = 0;
    out8(r16[dx], r8[al]);
    r16[ax] = pop();
    r16[dx] = pop();
  case 0x11e45: // 1020:1c45
    return;
  }
}
function* sub_11e61() // 1020:1c61
{
  var pc = 0;
  var temp_cond0;
  var temp_cond1;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[si] = 0x567e;
  case 0x11e72: // 1020:1c72
    memoryASet16(ds, 0x527a, r16[si]);
    if (memoryAGet16(ds, r16[si] + 4) != 0xffff)
        { pc = 0x11e7f; break; }
    { pc = 0x126a9; break; }
  case 0x11e7f: // 1020:1c7f
    r16[ax] = 0;
    memoryASet(cs, 0x1c49, r8[al]);
    memoryASet(cs, 0x1c53, r8[al]);
    memoryASet(cs, 0x1c56, r8[al]);
    memoryASet(cs, 0x1c57, r8[al]);
    memoryASet16(cs, 0x1c46, r16[ax]);
    memoryASet(ds, r16[si] + 5, memoryAGet(ds, r16[si] + 5) & 0xdf);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    flags.carry = !!(r16[bx] & 0x8000);
    r16[bx] <<= 1;
    memoryASet(cs, 0x1c48, rcl8(memoryAGet(cs, 0x1c48), 0x01));
    r8[al] = 0x01;
    if (!(r8[bh] & 0x80))
        { pc = 0x11eaf; break; }
    r8[al] = 0x41;
    r8[bh] &= 0x7f;
  case 0x11eaf: // 1020:1caf
    memoryASet(cs, 0x1c5e, r8[al]);
    r16[dx] = memoryAGet16(ds, r16[bx] + 26213);
    r8[al] = memoryAGet(ds, r16[bx] + 26927);
    if (!(memoryAGet(cs, 0x1c48) & 0x01))
        { pc = 0x11ec9; break; }
    r8[al] -= memoryAGet(ds, r16[bx] + 26213);
    r8[al] = -r8[al];
  case 0x11ec9: // 1020:1cc9
    cbw();
    r16[ax] = -r16[ax];
    r16[ax] += memoryAGet16(ds, r16[si]);
    r16[cx] = memoryAGet16(ds, 0x5270);
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[ax] -= r16[cx];
    r16[cx] = r16[ax];
    memoryASet16(cs, 0x1c50, r16[ax]);
    if (r16s[ax] < signed16(0x0140))
        { pc = 0x11eea; break; }
    { pc = 0x126a9; break; }
  case 0x11eea: // 1020:1cea
    flags.carry = r8[cl] + r8[dl] >= 0x100;
    r8[cl] += r8[dl];
    r8[ch] += (0x00 + flags.carry);
    if (r8s[ch] >= 0)
        { pc = 0x11ef4; break; }
    { pc = 0x126a9; break; }
  case 0x11ef4: // 1020:1cf4
    r8[al] = memoryAGet(ds, r16[bx] + 26928);
    cbw();
    r16[ax] += memoryAGet16(ds, r16[si] + 2);
    r16[ax]++;
    r16[cx] = memoryAGet16(ds, 0x5272);
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    r16[cx] <<= 1;
    temp_cond0 = r16s[ax] > r16s[cx];
    r16[ax] -= r16[cx];
    if (temp_cond0)
        { pc = 0x11f10; break; }
    { pc = 0x126a9; break; }
  case 0x11f10: // 1020:1d10
    memoryASet16(ds, 0x5278, r16[ax]);
    memoryASet(cs, 0x1c52, r8[dh]);
    memoryASet(cs, 0x1c4c, r8[dh]);
    flags.carry = r8[al] < r8[dh];
    r8[al] -= r8[dh];
    r8[ah] -= (0x00 + flags.carry);
    if (r16s[ax] < signed16(0x00c0))
        { pc = 0x11f2a; break; }
    { pc = 0x126a9; break; }
  case 0x11f2a: // 1020:1d2a
    memoryASet16(cs, 0x1c4e, r16[ax]);
    r8[cl] = memoryAGet(cs, 0x0000);
    r8[dl] >>= r8[cl];
    memoryASet(cs, 0x1c4a, r8[dl]);
    memoryASet(cs, 0x1c4b, r8[dl]);
    r8[dh] = 0;
    r16[cx] = 0;
    if (r16s[ax] >= 0)
        { pc = 0x11f5a; break; }
    r16[ax] = -r16[ax];
    memoryASet(cs, 0x1c52, memoryAGet(cs, 0x1c52) - r8[al]);
    mul8(r8[dl]);
    r16[cx] = r16[ax];
    memoryASet16(cs, 0x1c46, r16[ax]);
    r16[di] = 0;
    { pc = 0x11f60; break; }
  case 0x11f5a: // 1020:1d5a
    mul8(memoryAGet(ds, 0x525c));
    r16[di] = r16[ax];
  case 0x11f60: // 1020:1d60
    r16[di] += memoryAGet16(ds, 0x526a);
    memoryASet16(cs, 0x1c58, r16[di]);
    r16[ax] = memoryAGet16(ds, r16[bx] + 24004);
    memoryASet16(cs, 0x1c5c, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[bx] + 23204);
    r16[ax] += r16[cx];
    memoryASet16(cs, 0x1c5a, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5278);
    temp_cond1 = r16s[ax] <= signed16(0x00c0);
    r16[ax] -= 0x00c0;
    if (temp_cond1)
        { pc = 0x11f8f; break; }
    memoryASet(cs, 0x1c52, memoryAGet(cs, 0x1c52) - r8[al]);
    mul8(r8[dl]);
    memoryASet16(cs, 0x1c46, memoryAGet16(cs, 0x1c46) + r16[ax]);
  case 0x11f8f: // 1020:1d8f
    r16[ax] = memoryAGet16(cs, 0x1c50);
    if (r16s[ax] >= 0)
        { pc = 0x11fb0; break; }
    r8[cl] = memoryAGet(cs, 0x0000);
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet(cs, 0x1c4a, memoryAGet(cs, 0x1c4a) + r8[al]);
    r8[al] = -r8[al];
    memoryASet(cs, 0x1c53, r8[al]);
    memoryASet(cs, 0x1c49, memoryAGet(cs, 0x1c49) + 1);
    { pc = 0x11fe8; break; }
  case 0x11fb0: // 1020:1db0
    r8[cl] = memoryAGet(cs, 0x0000);
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet16(cs, 0x1c58, memoryAGet16(cs, 0x1c58) + r16[ax]);
    r16[ax] = memoryAGet16(cs, 0x1c50);
    r8[cl] = memoryAGet(cs, 0x0000);
    r16[ax] >>= r8[cl];
    flags.carry = r8[al] + memoryAGet(cs, 0x1c4a) >= 0x100;
    r8[al] += memoryAGet(cs, 0x1c4a);
    r8[ah] += (0x00 + flags.carry);
    flags.carry = r16[ax] < memoryAGet16(ds, 0x525c);
    r16[ax] -= memoryAGet16(ds, 0x525c);
    if (flags.carry)
        { pc = 0x11fe8; break; }
    memoryASet(cs, 0x1c4a, memoryAGet(cs, 0x1c4a) - r8[al]);
    memoryASet(cs, 0x1c49, memoryAGet(cs, 0x1c49) + 1);
    memoryASet(cs, 0x1c56, r8[al]);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
  case 0x11fe8: // 1020:1de8
    memoryASet(ds, r16[si] + 5, memoryAGet(ds, r16[si] + 5) | 0x20);
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x11ff7; break; }
    { pc = 0x1223a; break; }
  case 0x11ff7: // 1020:1df7
    if (memoryAGet(cs, 0x1c5e) == 0x01)
        { pc = 0x12002; break; }
    { pc = 0x126a9; break; }
  case 0x12002: // 1020:1e02
    r8[al] = memoryAGet(cs, 0x1c4b);
    mul8(memoryAGet(cs, 0x1c4c));
    memoryASet16(cs, 0x1c5f, r16[ax]);
    es = memoryAGet16(ds, 0x5262);
    r16[di] = memoryAGet16(cs, 0x1c58);
    ds = memoryAGet16(cs, 0x1c5c);
    r16[bx] = memoryAGet16(cs, 0x1c5f);
    r16[si] = memoryAGet16(cs, 0x1c5a);
    r8[dl] = memoryAGet(cs, 0x1c52);
    if (memoryAGet(cs, 0x1c49))
        { pc = 0x120a3; break; }
    if (memoryAGet16(cs, 0x1c50) & 0x0003)
        { pc = 0x120a3; break; }
    r8[dh] = memoryAGet(cs, 0x1c4a);
    r8[ch] = 0;
    r8[cl] = r8[dh];
    if (memoryAGet(cs, 0x1c48) & 0x01)
        { pc = 0x1206c; break; }
    r16[bp] = 0x0050;
    r16[bp] -= r16[cx];
  case 0x12053: // 1020:1e53
    r16[cx] >>= 1;
  case 0x12055: // 1020:1e55
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[ax] &= memoryAGet16(ds, r16[bx] + r16[si]);
    r16[ax] |= memoryAGet16(ds, r16[si]);
    stosw_ESDI(r16[ax]);
    r16[si]++;
    r16[si]++;
    if (--r16[cx])
        { pc = 0x12055; break; }
    r8[cl] = r8[dh];
    r16[di] += r16[bp];
    r8[dl]--;
    if (r8[dl])
        { pc = 0x12053; break; }
    { pc = 0x126a9; break; }
  case 0x1206c: // 1020:1e6c
    r16[bp] = r16[bx];
    r16[bx] = 0x330e;
    r16[di] += r16[cx];
    r16[di]--;
  case 0x12074: // 1020:1e74
    r16[cx] >>= 1;
  case 0x12076: // 1020:1e76
    r16[ax] = memoryAGet16(ds, r16[bp] + r16[si]);
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) & r8[al]);
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) | r8[al]);
    r16[di]--;
    r8[al] = r8[ah];
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) & r8[al]);
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) | r8[al]);
    r16[di]--;
    if (--r16[cx])
        { pc = 0x12076; break; }
    r8[cl] = r8[dh];
    r16[di] += r16[cx];
    r16[di] += 0x0050;
    r8[dl]--;
    if (r8[dl])
        { pc = 0x12074; break; }
  case 0x120a0: // 1020:1ea0
    { pc = 0x126a9; break; }
  case 0x120a3: // 1020:1ea3
    if (!memoryAGet(cs, 0x1c4a))
        { pc = 0x120a0; break; }
    r8[cl] = memoryAGet(cs, 0x1c50);
    r8[cl] &= 0x03;
    r8[cl] <<= 1;
    r8[ch] = 0xff;
    r8[ch] <<= r8[cl];
    if (memoryAGet(cs, 0x1c48) & 0x01)
        { pc = 0x1213e; break; }
  case 0x120c1: // 1020:1ec1
    r8[al] = memoryAGet(cs, 0x1c4a);
    cbw();
    r16[bp] = r16[ax];
    r8[al] = memoryAGet(cs, 0x1c53);
    cbw();
    r16[si] += r16[ax];
    r8[ch] = ~r8[ch];
    r16[dx] = 0xff00;
    r8[dh] &= r8[ch];
    if (!r16[ax])
        { pc = 0x120e4; break; }
    r8[dh] = memoryAGet(ds, r16[bx] + r16[si] - 1);
    r8[dh] &= r8[ch];
    r8[dl] = memoryAGet(ds, r16[si] - 1);
    r8[dl] &= r8[ch];
  case 0x120e4: // 1020:1ee4
    r8[ch] = ~r8[ch];
  case 0x120e6: // 1020:1ee6
    r8[al] = memoryAGet(ds, r16[bx] + r16[si]);
    r8[ah] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[dh];
    r8[al] = ror8(r8[al], r8[cl]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) & r8[al]);
    r8[al] = lodsb_DSSI();
    r8[dh] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[dl];
    r8[al] = ror8(r8[al], r8[cl]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) | r8[al]);
    r8[ch] = ~r8[ch];
    r8[dl] = r8[dh];
    r8[dh] = r8[ah];
    r8[dl] &= r8[ch];
    r8[dh] &= r8[ch];
    r8[ch] = ~r8[ch];
    r16[di]++;
    r16[bp]--;
    if (r16[bp])
        { pc = 0x120e6; break; }
    if (memoryAGet(cs, 0x1c57))
        { pc = 0x12123; break; }
    r8[dh] |= r8[ch];
    r8[dh] = ror8(r8[dh], r8[cl]);
    r8[dl] = ror8(r8[dl], r8[cl]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) & r8[dh]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) | r8[dl]);
  case 0x12123: // 1020:1f23
    r8[al] = memoryAGet(cs, 0x1c4a);
    cbw();
    r16[di] -= r16[ax];
    r16[di] += 0x0050;
    r8[al] = memoryAGet(cs, 0x1c56);
    cbw();
    r16[si] += r16[ax];
    memoryASet(cs, 0x1c52, memoryAGet(cs, 0x1c52) - 1);
    if (memoryAGet(cs, 0x1c52))
        { pc = 0x120c1; break; }
    { pc = 0x126a9; break; }
  case 0x1213e: // 1020:1f3e
    r8[al] = memoryAGet(cs, 0x1c53);
    memoryASet(cs, 0x1c54, r8[al]);
    r8[cl] = memoryAGet(cs, 0x1c50);
    r8[cl] &= 0x03;
    r8[cl] -= 0x04;
    r8[cl] = -r8[cl];
    r8[cl] &= 0x03;
    r8[cl] <<= 1;
    r8[ch] = 0xff;
    r8[ch] >>= r8[cl];
    r16[bp] = r16[bx];
    r16[bx] = 0x330e;
    if (!memoryAGet(cs, 0x1c53))
        { pc = 0x1217d; break; }
    r16[di]--;
    if (!(memoryAGet16(cs, 0x1c50) & 0x0003))
        { pc = 0x1217d; break; }
    memoryASet(cs, 0x1c53, memoryAGet(cs, 0x1c53) - 1);
    memoryASet(cs, 0x1c4a, memoryAGet(cs, 0x1c4a) + 1);
  case 0x1217d: // 1020:1f7d
    if (!memoryAGet(cs, 0x1c57))
        { pc = 0x1219a; break; }
    r16[di]--;
    if (!(memoryAGet16(cs, 0x1c50) & 0x0003))
        { pc = 0x1219a; break; }
    r16[di]++;
    memoryASet(cs, 0x1c4a, memoryAGet(cs, 0x1c4a) - 1);
    memoryASet(cs, 0x1c56, memoryAGet(cs, 0x1c56) + 1);
  case 0x1219a: // 1020:1f9a
    r8[al] = memoryAGet(cs, 0x1c4a);
    cbw();
    r16[di] += r16[ax];
  case 0x121a1: // 1020:1fa1
    r8[al] = memoryAGet(cs, 0x1c4a);
    memoryASet(cs, 0x1c4d, r8[al]);
    r8[ch] = ~r8[ch];
    r16[dx] = 0xff00;
    r8[dh] &= r8[ch];
    r8[ch] = ~r8[ch];
    if (!memoryAGet(cs, 0x1c57))
        { pc = 0x121d7; break; }
    r8[al] = memoryAGet(cs, 0x1c56);
    cbw();
    r16[si] += r16[ax];
    r8[al] = memoryAGet(ds, r16[bp] + r16[si] - 1);
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[dh] = r8[al];
    r8[al] = memoryAGet(ds, r16[si] - 1);
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[dl] = r8[al];
    memoryASet(cs, 0x1c4d, memoryAGet(cs, 0x1c4d) + 1);
    { pc = 0x121fa; break; }
  case 0x121d7: // 1020:1fd7
    r8[al] = memoryAGet(ds, r16[bp] + r16[si]);
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[ah] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[dh];
    r8[al] = rol8(r8[al], r8[cl]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) & r8[al]);
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[dh] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[dl];
    r8[al] = rol8(r8[al], r8[cl]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) | r8[al]);
    r16[di]--;
    r8[dl] = r8[dh];
    r8[dh] = r8[ah];
  case 0x121fa: // 1020:1ffa
    r8[ch] = ~r8[ch];
    r8[dl] &= r8[ch];
    r8[dh] &= r8[ch];
    r8[ch] = ~r8[ch];
    memoryASet(cs, 0x1c4d, memoryAGet(cs, 0x1c4d) - 1);
    if (memoryAGet(cs, 0x1c4d))
        { pc = 0x121d7; break; }
    if (memoryAGet(cs, 0x1c54))
        { pc = 0x1221d; break; }
    r8[dh] |= r8[ch];
    r8[dh] = rol8(r8[dh], r8[cl]);
    r8[dl] = rol8(r8[dl], r8[cl]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) & r8[dh]);
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) | r8[dl]);
  case 0x1221d: // 1020:201d
    r8[al] = memoryAGet(cs, 0x1c4a);
    cbw();
    r16[di] += r16[ax];
    r16[di] += 0x0050;
    r8[al] = memoryAGet(cs, 0x1c53);
    r16[si] += r16[ax];
    memoryASet(cs, 0x1c52, memoryAGet(cs, 0x1c52) - 1);
    if (!memoryAGet(cs, 0x1c52))
        { pc = 0x12237; break; }
    { pc = 0x121a1; break; }
  case 0x12237: // 1020:2037
    { pc = 0x126a9; break; }
  case 0x1223a: // 1020:203a
    yield* sub_134dc();
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r8[cl] = memoryAGet(cs, 0x1c50);
    r8[cl] &= 0x07;
    r8[ch] = 0xff;
    r8[ch] <<= r8[cl];
    r16[di] = memoryAGet16(cs, 0x1c58);
    r16[si] = memoryAGet16(cs, 0x1c5a);
    r8[dl] = 0xce;
    r8[al] = 0x03;
    r8[ah] = r8[cl];
    r8[ah] |= 0x08;
    out16(r16[dx], r16[ax]);
    r8[bh] = r8[ch];
    r8[bh] = ~r8[bh];
    r8[dh] = memoryAGet(cs, 0x1c4a);
    r8[cl] = r8[dh];
    r8[al] = r8[cl];
    cbw();
    r16[ax] -= 0x0028;
    r16[bp] = r16[ax];
    r8[dl] = memoryAGet(cs, 0x1c52);
    ds = memoryAGet16(cs, 0x1c5c);
    r16[ax] = 0xa000;
    es = r16[ax];
    if (memoryAGet(cs, 0x1c48) & 0x01)
        { pc = 0x12291; break; }
    { pc = 0x124e9; break; }
  case 0x12291: // 1020:2091
    memoryASet(cs, 0x1c4c, r8[dl]);
    r16[dx] = r16[bx];
    r16[bx] = 0x340e;
    flags.direction = 1;
    r16[si]--;
    if (!memoryAGet(cs, 0x1c49))
        { pc = 0x122a8; break; }
    { pc = 0x123ef; break; }
  case 0x122a8: // 1020:20a8
    r8[al] = r8[cl];
    cbw();
    r16[si] += r16[ax];
    if (r8[ch] == 0xff)
        { pc = 0x122b5; break; }
    { pc = 0x1233c; break; }
  case 0x122b5: // 1020:20b5
    r8[ch] = 0;
  case 0x122b7: // 1020:20b7
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[al] = ~r8[al];
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[al]); r8[al] = r8[tl];
    r16[di]++;
    if (--r16[cx])
        { pc = 0x122b7; break; }
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[al] = r8[cl];
    cbw();
    r16[si] += r16[ax];
    r16[si] += r16[ax];
    r16[di] -= r16[bp];
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        { pc = 0x122b7; break; }
    push(r16[dx]);
    r16[dx] = 0x03ce;
    r16[ax] = 0x1003;
    out16(r16[dx], r16[ax]);
    r8[dl] = 0xc4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r8[al] = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
    r16[dx] = pop();
  case 0x122ee: // 1020:20ee
    push(r16[dx]);
    memoryASet(cs, 0x1c4d, r8[al]);
    r16[dx] = 0x03c5;
    out8(r16[dx], r8[al]);
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[dl] = memoryAGet(cs, 0x1c52);
    memoryASet(cs, 0x1c4c, r8[dl]);
    r16[di] = memoryAGet16(cs, 0x1c58);
    r16[si] += memoryAGet16(cs, 0x1c46);
    r16[dx] = pop();
  case 0x12311: // 1020:2111
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[al]); r8[al] = r8[tl];
    r16[di]++;
    if (--r16[cx])
        { pc = 0x12311; break; }
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[al] = r8[cl];
    cbw();
    r16[si] += r16[ax];
    r16[si] += r16[ax];
    r16[di] -= r16[bp];
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        { pc = 0x12311; break; }
    r8[al] = memoryAGet(cs, 0x1c4d);
    r8[al] <<= 1;
    if (r8[al] < 0x10)
        { pc = 0x122ee; break; }
    { pc = 0x126a9; break; }
  case 0x1233c: // 1020:213c
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[dl] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[ah];
    r8[al] = ~r8[al];
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[al]); r8[al] = r8[tl];
    r16[di]++;
    r8[dl] &= r8[dh];
    r8[ah] = r8[dl];
    r8[cl]--;
    if (r8[cl])
        { pc = 0x1233c; break; }
    r8[ah] = ~r8[ah];
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[ah]); r8[ah] = r8[tl];
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[al] = r8[cl];
    cbw();
    r16[si] += r16[ax];
    r16[si] += r16[ax];
    r16[di] -= r16[bp];
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        { pc = 0x1233c; break; }
    push(r16[dx]);
    r8[cl] = memoryAGet(cs, 0x1c50);
    r8[cl] &= 0x07;
    r16[dx] = 0x03ce;
    r8[al] = 0x03;
    r8[ah] = r8[cl];
    r8[ah] |= 0x10;
    out16(r16[dx], r16[ax]);
    r8[dl] = 0xc4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r8[al] = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
    r16[dx] = pop();
  case 0x12390: // 1020:2190
    push(r16[dx]);
    memoryASet(cs, 0x1c4d, r8[al]);
    r16[dx] = 0x03c5;
    out8(r16[dx], r8[al]);
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[dl] = memoryAGet(cs, 0x1c52);
    memoryASet(cs, 0x1c4c, r8[dl]);
    r16[di] = memoryAGet16(cs, 0x1c58);
    r16[si] += memoryAGet16(cs, 0x1c46);
    r16[dx] = pop();
    r16[ax] = 0;
  case 0x123b5: // 1020:21b5
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[dl] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[ah];
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[al]); r8[al] = r8[tl];
    r16[di]++;
    r8[dl] &= r8[dh];
    r8[ah] = r8[dl];
    r8[cl]--;
    if (r8[cl])
        { pc = 0x123b5; break; }
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[ah]); r8[ah] = r8[tl];
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[al] = r8[cl];
    cbw();
    r16[si] += r16[ax];
    r16[si] += r16[ax];
    r16[di] -= r16[bp];
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        { pc = 0x123b5; break; }
    r8[al] = memoryAGet(cs, 0x1c4d);
    r8[al] <<= 1;
    if (r8[al] < 0x10)
        { pc = 0x12390; break; }
    { pc = 0x126a9; break; }
  case 0x123ef: // 1020:21ef
    r8[al] = memoryAGet(cs, 0x1c4b);
    cbw();
    r16[si] += r16[ax];
  case 0x123f6: // 1020:21f6
    r8[al] = memoryAGet(cs, 0x1c53);
    cbw();
    if (!r16[ax])
        { pc = 0x1240a; break; }
    r16[ax]--;
    r16[si] -= r16[ax];
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[dl] = r8[al];
    r16[cx]++;
    { pc = 0x12419; break; }
  case 0x1240a: // 1020:220a
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[dl] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[ah];
    r8[al] = ~r8[al];
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[al]); r8[al] = r8[tl];
    r16[di]++;
  case 0x12419: // 1020:2219
    r8[dl] &= r8[dh];
    r8[ah] = r8[dl];
    r8[cl]--;
    if (r8[cl])
        { pc = 0x1240a; break; }
    r8[ah] = ~r8[ah];
    r8[ah] |= memoryAGet(cs, 0x1c57);
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[ah]); r8[ah] = r8[tl];
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[al] = memoryAGet(cs, 0x1c4b);
    cbw();
    r16[si] += r16[ax];
    r8[al] -= memoryAGet(cs, 0x1c56);
    r16[si] += r16[ax];
    r16[di] -= r16[bp];
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        { pc = 0x123f6; break; }
    push(r16[dx]);
    r8[cl] = memoryAGet(cs, 0x1c50);
    r8[cl] &= 0x07;
    r16[dx] = 0x03ce;
    r8[al] = 0x03;
    r8[ah] = r8[cl];
    r8[ah] |= 0x10;
    out16(r16[dx], r16[ax]);
    r8[dl] = 0xc4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r8[al] = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
    r16[dx] = pop();
  case 0x1246a: // 1020:226a
    push(r16[dx]);
    memoryASet(cs, 0x1c4d, r8[al]);
    r16[dx] = 0x03c5;
    out8(r16[dx], r8[al]);
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[dl] = memoryAGet(cs, 0x1c52);
    memoryASet(cs, 0x1c4c, r8[dl]);
    r16[di] = memoryAGet16(cs, 0x1c58);
    r16[si] += memoryAGet16(cs, 0x1c46);
    r16[dx] = pop();
  case 0x1248d: // 1020:228d
    r8[al] = memoryAGet(cs, 0x1c53);
    cbw();
    if (!r16[ax])
        { pc = 0x124a1; break; }
    r16[ax]--;
    r16[si] -= r16[ax];
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[dl] = r8[al];
    r16[cx]++;
    { pc = 0x124ae; break; }
  case 0x124a1: // 1020:22a1
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    r8[dl] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[ah];
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[al]); r8[al] = r8[tl];
    r16[di]++;
  case 0x124ae: // 1020:22ae
    r8[dl] &= r8[dh];
    r8[ah] = r8[dl];
    r8[cl]--;
    if (r8[cl])
        { pc = 0x124a1; break; }
    r8[ah] &= memoryAGet(cs, 0x1c57);
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[ah]); r8[ah] = r8[tl];
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[al] = memoryAGet(cs, 0x1c4b);
    cbw();
    r16[si] += r16[ax];
    r8[al] -= memoryAGet(cs, 0x1c56);
    r16[si] += r16[ax];
    r16[di] -= r16[bp];
    memoryASet(cs, 0x1c4c, memoryAGet(cs, 0x1c4c) - 1);
    if (memoryAGet(cs, 0x1c4c))
        { pc = 0x1248d; break; }
    r8[al] = memoryAGet(cs, 0x1c4d);
    r8[al] <<= 1;
    if (r8[al] >= 0x10)
        { pc = 0x124e6; break; }
    { pc = 0x1246a; break; }
  case 0x124e6: // 1020:22e6
    { pc = 0x126a9; break; }
  case 0x124e9: // 1020:22e9
    if (!memoryAGet(cs, 0x1c49))
        { pc = 0x124f4; break; }
    { pc = 0x125e2; break; }
  case 0x124f4: // 1020:22f4
    if (r8[ch] != 0xff)
        { pc = 0x12554; break; }
    r8[ch] = 0;
  case 0x124fb: // 1020:22fb
    r8[al] = lodsb_DSSI();
    r8[al] = ~r8[al];
    scasb_inv_ESDI(r8[al]);
    r16[di]--;
    stosb_ESDI(r8[al]);
    if (--r16[cx])
        { pc = 0x124fb; break; }
    r8[cl] = r8[dh];
    r16[di] -= r16[bp];
    r8[dl]--;
    if (r8[dl])
        { pc = 0x124fb; break; }
    r16[dx] = 0x03ce;
    r16[ax] = 0x1003;
    out16(r16[dx], r16[ax]);
    r8[dl] = 0xc4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r8[al] = memoryAGet(cs, 0x1c5e);
  case 0x1251b: // 1020:231b
    memoryASet(cs, 0x1c4d, r8[al]);
    r16[dx] = 0x03c5;
    out8(r16[dx], r8[al]);
    r8[dh] = memoryAGet(cs, 0x1c4a);
    r8[cl] = r8[dh];
    r8[dl] = memoryAGet(cs, 0x1c52);
    r16[di] = memoryAGet16(cs, 0x1c58);
    r16[si] += memoryAGet16(cs, 0x1c46);
  case 0x12539: // 1020:2339
    r8[al] = lodsb_DSSI();
    scasb_inv_ESDI(r8[al]);
    r16[di]--;
    stosb_ESDI(r8[al]);
    if (--r16[cx])
        { pc = 0x12539; break; }
    r16[di] -= r16[bp];
    r8[cl] = r8[dh];
    r8[dl]--;
    if (r8[dl])
        { pc = 0x12539; break; }
    r8[al] = memoryAGet(cs, 0x1c4d);
    r8[al] <<= 1;
    if (r8[al] < 0x10)
        { pc = 0x1251b; break; }
    { pc = 0x126a9; break; }
  case 0x12554: // 1020:2354
    r16[ax] = 0;
  case 0x12556: // 1020:2356
    r8[al] = lodsb_DSSI();
    r8[bl] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[ah];
    r8[al] = ~r8[al];
    scasb_inv_ESDI(r8[al]);
    r16[di]--;
    stosb_ESDI(r8[al]);
    r8[bl] &= r8[bh];
    r8[ah] = r8[bl];
    r8[cl]--;
    if (r8[cl])
        { pc = 0x12556; break; }
    r8[ah] = ~r8[ah];
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[ah]); r8[ah] = r8[tl];
    r8[cl] = r8[dh];
    r16[di] -= r16[bp];
    r8[dl]--;
    if (r8[dl])
        { pc = 0x12554; break; }
    r8[cl] = memoryAGet(cs, 0x1c50);
    r8[cl] &= 0x07;
    r16[dx] = 0x03ce;
    r8[al] = 0x03;
    r8[ah] = r8[cl];
    r8[ah] |= 0x10;
    out16(r16[dx], r16[ax]);
    r8[dl] = 0xc4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r8[al] = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
  case 0x12598: // 1020:2398
    memoryASet(cs, 0x1c4d, r8[al]);
    r16[dx] = 0x03c5;
    out8(r16[dx], r8[al]);
    r8[dh] = memoryAGet(cs, 0x1c4a);
    r8[cl] = r8[dh];
    r8[dl] = memoryAGet(cs, 0x1c52);
    r16[di] = memoryAGet16(cs, 0x1c58);
    r16[si] += memoryAGet16(cs, 0x1c46);
  case 0x125b6: // 1020:23b6
    r16[ax] = 0;
  case 0x125b8: // 1020:23b8
    r8[al] = lodsb_DSSI();
    r8[bl] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[ah];
    scasb_inv_ESDI(r8[al]);
    r16[di]--;
    stosb_ESDI(r8[al]);
    r8[bl] &= r8[bh];
    r8[ah] = r8[bl];
    r8[cl]--;
    if (r8[cl])
        { pc = 0x125b8; break; }
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[ah]); r8[ah] = r8[tl];
    r8[cl] = r8[dh];
    r16[di] -= r16[bp];
    r8[dl]--;
    if (r8[dl])
        { pc = 0x125b6; break; }
    r8[al] = memoryAGet(cs, 0x1c4d);
    r8[al] <<= 1;
    if (r8[al] < 0x10)
        { pc = 0x12598; break; }
    { pc = 0x126a9; break; }
  case 0x125e2: // 1020:23e2
    r8[al] = memoryAGet(cs, 0x1c53);
    cbw();
    if (!r16[ax])
        { pc = 0x125f4; break; }
    r16[ax]--;
    r16[cx]++;
    r16[si] += r16[ax];
    r8[al] = lodsb_DSSI();
    r8[bl] = r8[al];
    { pc = 0x12600; break; }
  case 0x125f4: // 1020:23f4
    r8[al] = lodsb_DSSI();
    r8[bl] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[ah];
    r8[al] = ~r8[al];
    scasb_inv_ESDI(r8[al]);
    r16[di]--;
    stosb_ESDI(r8[al]);
  case 0x12600: // 1020:2400
    r8[bl] &= r8[bh];
    r8[ah] = r8[bl];
    r8[cl]--;
    if (r8[cl])
        { pc = 0x125f4; break; }
    r8[ah] = ~r8[ah];
    r8[ah] |= memoryAGet(cs, 0x1c57);
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[ah]); r8[ah] = r8[tl];
    r8[al] = memoryAGet(cs, 0x1c56);
    cbw();
    r16[si] += r16[ax];
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r16[di] -= r16[bp];
    r8[dl]--;
    if (r8[dl])
        { pc = 0x125e2; break; }
    r8[cl] = memoryAGet(cs, 0x1c50);
    r8[cl] &= 0x07;
    r16[dx] = 0x03ce;
    r8[al] = 0x03;
    r8[ah] = r8[cl];
    r8[ah] |= 0x10;
    out16(r16[dx], r16[ax]);
    r8[dl] = 0xc4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r8[al] = memoryAGet(cs, 0x1c5e);
    memoryASet(cs, 0x1c57, ~memoryAGet(cs, 0x1c57));
  case 0x12645: // 1020:2445
    memoryASet(cs, 0x1c4d, r8[al]);
    r16[dx] = 0x03c5;
    out8(r16[dx], r8[al]);
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r8[dl] = memoryAGet(cs, 0x1c52);
    r16[di] = memoryAGet16(cs, 0x1c58);
    r16[si] += memoryAGet16(cs, 0x1c46);
  case 0x12661: // 1020:2461
    r8[al] = memoryAGet(cs, 0x1c53);
    cbw();
    if (!r16[ax])
        { pc = 0x12673; break; }
    r16[ax]--;
    r16[cx]++;
    r16[si] += r16[ax];
    r8[al] = lodsb_DSSI();
    r8[bl] = r8[al];
    { pc = 0x1267d; break; }
  case 0x12673: // 1020:2473
    r8[al] = lodsb_DSSI();
    r8[bl] = r8[al];
    r8[al] &= r8[ch];
    r8[al] |= r8[ah];
    scasb_inv_ESDI(r8[al]);
    r16[di]--;
    stosb_ESDI(r8[al]);
  case 0x1267d: // 1020:247d
    r8[bl] &= r8[bh];
    r8[ah] = r8[bl];
    r8[cl]--;
    if (r8[cl])
        { pc = 0x12673; break; }
    r8[ah] &= memoryAGet(cs, 0x1c57);
    r8[tl] = memoryAGet(es, r16[di]); memoryASet(es, r16[di], r8[ah]); r8[ah] = r8[tl];
    r8[al] = memoryAGet(cs, 0x1c56);
    cbw();
    r16[si] += r16[ax];
    r8[cl] = memoryAGet(cs, 0x1c4a);
    r16[di] -= r16[bp];
    r8[dl]--;
    if (r8[dl])
        { pc = 0x12661; break; }
    r8[al] = memoryAGet(cs, 0x1c4d);
    r8[al] <<= 1;
    if (r8[al] < 0x10)
        { pc = 0x12645; break; }
  case 0x126a9: // 1020:24a9
    flags.direction = 0;
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[si] = memoryAGet16(ds, 0x527a);
    r16[si] -= 0x0012;
    if (r16[si] < 0x527c)
        { pc = 0x126bf; break; }
    { pc = 0x11e72; break; }
  case 0x126bf: // 1020:24bf
    r16[bp] = pop();
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
}
function* sub_126c9() // 1020:24c9
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (memoryAGet(cs, 0x0001) >= 0x03)
        { pc = 0x126f1; break; }
    r16[ax] = memoryAGet16(ds, 0x04c1);
    memoryASet16(ds, 0x5262, r16[ax]);
    r16[ax] += 0x0400;
    memoryASet16(ds, 0x5264, r16[ax]);
    memoryASet16(ds, 0x04c1, memoryAGet16(ds, 0x04c1) + 0x0800);
  case 0x126f1: // 1020:24f1
    r16[si] = 0x7255;
    r16[bx] = 0;
  case 0x126f6: // 1020:24f6
    r16[ax] = lodsw_DSSI();
    if (r16[ax] == 0xffff)
        { pc = 0x1271a; break; }
  case 0x126fc: // 1020:24fc
    if (r16[ax] == r16[bx])
        { pc = 0x12708; break; }
    memoryASet(ds, r16[bx] + 28869, 0x00);
    r16[bx]++;
    { pc = 0x126fc; break; }
  case 0x12708: // 1020:2508
    r16[ax] = lodsw_DSSI();
  case 0x12709: // 1020:2509
    memoryASet(ds, r16[bx] + 28869, 0x01);
    r16[bx]++;
    r16[ax]--;
    if (r16[ax])
        { pc = 0x12709; break; }
    { pc = 0x126f6; break; }
  case 0x12714: // 1020:2514
    memoryASet(ds, r16[bx] + 28869, 0x00);
    r16[bx]++;
  case 0x1271a: // 1020:251a
    if (r16[bx] == 0x0190)
        { pc = 0x12714; break; }
    r16[dx] = 0x501a;
    push(ds);
    push(es);
    yield* sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x5260, r16[ax]);
    r16[bx] = 0;
  case 0x1272f: // 1020:252f
    r8[al] = memoryAGet(ds, r16[bx] + 26214);
    if (!r8[al])
        { pc = 0x12743; break; }
    memoryASet(ds, r16[bx] + 26928, memoryAGet(ds, r16[bx] + 26928) - r8[al]);
    memoryASet(ds, r16[bx] + 26928, -memoryAGet(ds, r16[bx] + 26928));
    r16[bx]++;
    r16[bx]++;
    { pc = 0x1272f; break; }
  case 0x12743: // 1020:2543
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x1274e; break; }
    { pc = 0x1283e; break; }
  case 0x1274e: // 1020:254e
    r16[si] = 0;
    memoryASet16(cs, 0x6676, 0x274f);
    r16[ax] = memoryAGet16(ds, 0x5260);
    memoryASet16(ds, 0x5268, r16[ax]);
    memoryASet16(ds, 0x525e, 0x0000);
    es = memoryAGet16(ds, 0x04c1);
  case 0x12767: // 1020:2567
    push(es);
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[di] = 0x1ef0;
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[cx] = memoryAGet16(ds, 0x525e);
    r16[dx] = r16[cx];
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[di] += r16[dx];
    r8[al] = 0xc0;
    r8[cl] &= 0x03;
    r8[cl] <<= 1;
    r8[al] >>= r8[cl];
    memoryASet(es, r16[di], memoryAGet(es, r16[di]) | r8[al]);
    es = pop();
    r16[ax] = r16[si];
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    memoryASet16(ds, 0x5268, memoryAGet16(ds, 0x5268) + r16[ax]);
    r16[si] &= 0x000f;
    r16[di] = 0;
    r16[bx] = memoryAGet16(ds, 0x525e);
    memoryASet16(ds, 0x525e, memoryAGet16(ds, 0x525e) + 1);
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[bx] + 26213);
    r16[dx] = r16[ax];
    mul8(r8[ah]);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    if (!r16[ax])
        { pc = 0x12808; break; }
    r16[cx] = r16[ax];
    push(r16[si]);
    ds = memoryAGet16(ds, 0x5268);
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[si] = pop();
    r16[bx] = r16[ax];
    r8[al] = r8[dh];
    r8[ah] = r8[dl];
    r8[ah] >>= 1;
    r8[ah] >>= 1;
    r8[ah] >>= 1;
    yield* sub_167be();
    r16[si] += r16[bx];
    r16[bx] >>= 1;
    r16[bp] = r16[bx];
    r16[di] = 0;
  case 0x127da: // 1020:25da
    r8[al] = memoryAGet(es, r16[di]);
    r16[di] += r16[bx];
    r8[al] |= memoryAGet(es, r16[di]);
    r16[di] += r16[bx];
    r8[al] |= memoryAGet(es, r16[di]);
    r8[al] |= memoryAGet(es, r16[bx] + r16[di]);
    r16[di] -= r16[bx];
    r16[di] -= r16[bx];
    r16[cx] = 0x0008;
  case 0x127f1: // 1020:25f1
    flags.carry = r8[al] & 1;
    r8[al] >>= 1;
    r16[dx] = rcr16(r16[dx], 0x0001);
    r16[dx] = sar16(r16[dx], 0x0001);
    if (--r16[cx])
        { pc = 0x127f1; break; }
    r8[tl] = r8[dh]; r8[dh] = r8[dl]; r8[dl] = r8[tl];
    r16[dx] = ~r16[dx];
    memoryASet16(ds, r16[si], r16[dx]);
    r16[si]++;
    r16[si]++;
    r16[di]++;
    r16[bp]--;
    if (r16[bp])
        { pc = 0x127da; break; }
    { pc = 0x12767; break; }
  case 0x12808: // 1020:2608
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[di] = 0;
    r16[bx] = memoryAGet16(ds, 0x5260);
    r16[cx] = 0;
  case 0x12815: // 1020:2615
    memoryASet16(ds, r16[di] + 24004, r16[bx]);
    memoryASet16(ds, r16[di] + 23204, r16[cx]);
    r16[ax] = memoryAGet16(ds, r16[di] + 26213);
    r16[di]++;
    r16[di]++;
    mul8(r8[ah]);
    r16[ax] >>= 1;
    if (!r16[ax])
        { pc = 0x1283b; break; }
    r16[cx] += r16[ax];
    if (r16[cx] < 0x1000)
        { pc = 0x12815; break; }
    r16[cx] -= 0x1000;
    r16[bx] += 0x0100;
    { pc = 0x12815; break; }
  case 0x1283b: // 1020:263b
    { pc = 0x1293d; break; }
  case 0x1283e: // 1020:263e
    flags.direction = 1;
    r16[ax] = memoryAGet16(ds, 0x04c1);
    r16[bx] = memoryAGet16(ds, 0x5260);
    r16[ax] -= r16[bx];
    r16[bp] = r16[ax];
    r16[dx] = r16[ax];
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[dx]++;
    r16[ax] += r16[dx];
    r16[ax] += r16[bx];
    memoryASet16(ds, 0x04c1, r16[ax]);
    r16[ax]--;
    r16[bx] = r16[ax];
    r16[ax] -= r16[dx];
  case 0x1285d: // 1020:265d
    ds = r16[ax];
    es = r16[bx];
    r16[si] = 0x000f;
    r16[di] = r16[si];
    r16[cx] = 0x0010;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[ax]--;
    r16[bx]--;
    r16[bp]--;
    if (r16[bp])
        { pc = 0x1285d; break; }
    flags.direction = 0;
    r16[dx] = 0x168f;
    ds = r16[dx];
    r16[ax]++;
    r16[bx]++;
    memoryASet16(ds, 0x5087, r16[ax]);
    memoryASet16(ds, 0x5089, r16[bx]);
    r16[bx] = 0x6665;
    r16[si] = 0;
    r16[di] = 0;
  case 0x12886: // 1020:2686
    r16[ax] = r16[si];
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    memoryASet16(ds, 0x5089, memoryAGet16(ds, 0x5089) + r16[ax]);
    r16[si] &= 0x000f;
    r16[ax] = r16[di];
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    memoryASet16(ds, 0x5087, memoryAGet16(ds, 0x5087) + r16[ax]);
    r16[di] &= 0x000f;
    r16[ax] = memoryAGet16(ds, r16[bx]);
    if (!r8[al])
        { pc = 0x128f2; break; }
    r8[al] = ror8(r8[al], 0x01);
    r8[al] = ror8(r8[al], 0x01);
    r8[al] = ror8(r8[al], 0x01);
    if (!(r8[al] & 0xe0))
        { pc = 0x128bc; break; }
    r8[al] &= 0x1f;
    r8[al]++;
  case 0x128bc: // 1020:26bc
    r16[bx]++;
    r16[bx]++;
    mul8(r8[ah]);
    r16[bp] = r16[ax];
    es = memoryAGet16(ds, 0x5087);
    ds = memoryAGet16(ds, 0x5089);
    r16[cx] = r16[bp];
    push(r16[si]);
  case 0x128cd: // 1020:26cd
    r8[al] = memoryAGet(ds, r16[si]);
    r8[al] |= memoryAGet(ds, r16[bp] + r16[si]);
    r16[si] += r16[bp];
    r8[al] |= memoryAGet(ds, r16[bp] + r16[si]);
    r16[si] += r16[bp];
    r8[al] |= memoryAGet(ds, r16[bp] + r16[si]);
    r16[si] -= r16[bp];
    r16[si] -= r16[bp];
    stosb_ESDI(r8[al]);
    r16[si]++;
    if (--r16[cx])
        { pc = 0x128cd; break; }
    r16[si] = pop();
    r16[cx] = r16[bp];
    r16[cx] <<= 1;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[ax] = 0x168f;
    ds = r16[ax];
    { pc = 0x12886; break; }
  case 0x128f2: // 1020:26f2
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    r16[bx] = memoryAGet16(ds, 0x5260);
    r16[si] = 0x6665;
    r16[di] = 0;
    r16[dx] = 0;
  case 0x12904: // 1020:2704
    r16[ax] = lodsw_DSSI();
    if (!r8[al])
        { pc = 0x1293d; break; }
    r8[al] = ror8(r8[al], 0x01);
    r8[al] = ror8(r8[al], 0x01);
    r8[al] = ror8(r8[al], 0x01);
    if (!(r8[al] & 0xe0))
        { pc = 0x12917; break; }
    r8[al] &= 0x1f;
    r8[al]++;
  case 0x12917: // 1020:2717
    mul8(r8[ah]);
    r16[bp] = r16[ax];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += r16[bp];
    memoryASet16(ds, r16[di] + 23204, r16[dx]);
    memoryASet16(ds, r16[di] + 24004, r16[bx]);
    if (r16[dx] < 0x1000)
        { pc = 0x12937; break; }
    r16[dx] -= 0x1000;
    r16[bx] += 0x0100;
  case 0x12937: // 1020:2737
    r16[di]++;
    r16[di]++;
    r16[dx] += r16[ax];
    { pc = 0x12904; break; }
  case 0x1293d: // 1020:273d
    r16[bp] = pop();
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
}
function* sub_1296f() // 1020:276f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(ds);
    push(es);
    yield* sub_12e87();
    r16[ax] = 0x168f;
    ds = r16[ax];
    yield* sub_129df();
    yield* sub_134f4();
    r16[bp] = 0x0002;
    r16[di] = 0x0c92;
  case 0x12989: // 1020:2789
    yield* sub_13443();
    r16[cx] = r16[bp];
  case 0x1298e: // 1020:278e
    yield* sub_12acd();
    r16[di]++;
    r16[di]++;
    if (--r16[cx])
        { pc = 0x1298e; break; }
    r16[di]--;
    r16[di]--;
    r16[cx] = r16[bp];
    r16[cx]--;
  case 0x1299a: // 1020:279a
    r16[di] += 0x0190;
    yield* sub_12acd();
    if (--r16[cx])
        { pc = 0x1299a; break; }
    r16[cx] = r16[bp];
    r16[cx]--;
  case 0x129a6: // 1020:27a6
    r16[di]--;
    r16[di]--;
    yield* sub_12acd();
    if (--r16[cx])
        { pc = 0x129a6; break; }
    r16[cx] = r16[bp];
    r16[cx]--;
  case 0x129b0: // 1020:27b0
    r16[di] -= 0x0190;
    yield* sub_12acd();
    if (--r16[cx])
        { pc = 0x129b0; break; }
    r16[bp]++;
    r16[bp]++;
    r16[di] -= 0x0192;
    if (r16[bp] < 0x0014)
        { pc = 0x12989; break; }
    r16[di] = memoryAGet16(ds, 0x526a);
    r16[si] = memoryAGet16(ds, 0x5268);
    r16[ax] = 0xa000;
    es = r16[ax];
    ds = r16[ax];
    r16[cx] = 0x1e00;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    es = pop();
    ds = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_129df() // 1020:27df
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) >= 0x03)
        { pc = 0x129ec; break; }
    yield* sub_13360();
    { pc = 0x12a10; break; }
  case 0x129ec: // 1020:27ec
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(es);
    yield* sub_134dc();
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r16[di] = memoryAGet16(ds, 0x5268);
    r16[cx] = 0x0f00;
    r16[ax] = 0;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    es = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
  case 0x12a10: // 1020:2810
    return;
  }
}
function* sub_12a11() // 1020:2811
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) >= 0x03)
        { pc = 0x12a1d; break; }
    yield* sub_13360();
    return;
  case 0x12a1d: // 1020:281d
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(ds);
    push(es);
    yield* sub_134dc();
    r16[dx] = 0x03c4;
    r16[ax] = 0x0f02;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[di] = memoryAGet16(ds, 0x5268);
    r16[cx] = 0x0014;
    memoryASet16(cs, 0x274d, 0x0026);
    memoryASet16(cs, 0x274b, 0x1c70);
  case 0x12a47: // 1020:2847
    yield* sub_13443();
    push(r16[cx]);
    push(r16[di]);
    memoryASet16(cs, 0x2747, 0x0000);
    memoryASet16(cs, 0x2749, 0x0000);
  case 0x12a5a: // 1020:285a
    r16[di] += memoryAGet16(cs, 0x2749);
    yield* sub_12af8();
    r16[di] += memoryAGet16(cs, 0x274b);
    yield* sub_12af8();
    r16[di] -= memoryAGet16(cs, 0x274b);
    r16[di] -= memoryAGet16(cs, 0x2749);
    if (memoryAGet16(cs, 0x2747) <= 0x1c70)
        { pc = 0x12a83; break; }
    r16[di] += 0x1c70;
    { pc = 0x12a88; break; }
  case 0x12a83: // 1020:2883
    r16[di] += memoryAGet16(cs, 0x2747);
  case 0x12a88: // 1020:2888
    yield* sub_12af8();
    r16[di] += memoryAGet16(cs, 0x274d);
    yield* sub_12af8();
    r16[di] -= memoryAGet16(cs, 0x274d);
    r16[di] -= memoryAGet16(cs, 0x2747);
    memoryASet16(cs, 0x2747, memoryAGet16(cs, 0x2747) + 0x0190);
    memoryASet16(cs, 0x2749, memoryAGet16(cs, 0x2749) + 0x0002);
    if (--r16[cx])
        { pc = 0x12a5a; break; }
    r16[di] = pop();
    r16[di] += 0x0192;
    memoryASet16(cs, 0x274d, memoryAGet16(cs, 0x274d) - 0x0004);
    memoryASet16(cs, 0x274b, memoryAGet16(cs, 0x274b) - 0x0320);
    r16[cx] = pop();
    r16[cx]--;
    r16[cx]--;
    if (r16[cx])
        { pc = 0x12a47; break; }
    yield* sub_134dc();
    es = pop();
    ds = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_12acd() // 1020:28cd
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    r16[si] = r16[di];
    r16[si] += memoryAGet16(ds, 0x526a);
    r16[di] += memoryAGet16(ds, 0x5268);
    r16[ax] = 0xa000;
    ds = r16[ax];
    es = r16[ax];
    r16[cx] = 0x000a;
  case 0x12ae7: // 1020:28e7
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += 0x0026;
    r16[si] += 0x0026;
    if (--r16[cx])
        { pc = 0x12ae7; break; }
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_12af8() // 1020:28f8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[di]);
    push(es);
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[cx] = 0x000a;
    r16[ax] = 0;
  case 0x12b06: // 1020:2906
    stosw_ESDI(r16[ax]);
    r16[di] += 0x0026;
    if (--r16[cx])
        { pc = 0x12b06; break; }
    es = pop();
    r16[di] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_12b11() // 1020:2911 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (!memoryAGet16(ds, 0x5272))
        { pc = 0x12b46; break; }
    memoryASet16(ds, 0x5272, memoryAGet16(ds, 0x5272) - 1);
    r16[ax] = memoryAGet16(ds, 0x5276);
    r16[ax]--;
    if (r16s[ax] >= 0)
        { pc = 0x12b2e; break; }
    r16[ax] = 0x000b;
  case 0x12b2e: // 1020:292e
    r16[di] = 0;
    memoryASet16(ds, 0x5276, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5274);
    yield* sub_12d67();
    r8[ah] = memoryAGet(ds, 0x5272);
    r8[al] = memoryAGet(ds, 0x5270);
    yield* sub_12c0d();
    flags.carry = 0;
    { pc = 0x12b47; break; }
  case 0x12b46: // 1020:2946
    flags.carry = 1;
  case 0x12b47: // 1020:2947
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_12b4c() // 1020:294c +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r8[al] = memoryAGet(ds, 0x508b);
    r8[ah] = 0;
    r16[ax] -= 0x000c;
    if (memoryAGet16(ds, 0x5272) >= r16[ax])
        { pc = 0x12b8e; break; }
    memoryASet16(ds, 0x5272, memoryAGet16(ds, 0x5272) + 1);
    r16[ax] = memoryAGet16(ds, 0x5276);
    r16[ax]++;
    if (r16[ax] < 0x000c)
        { pc = 0x12b72; break; }
    r16[ax] = 0;
  case 0x12b72: // 1020:2972
    r16[di] = 0x1b80;
    memoryASet16(ds, 0x5276, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5274);
    yield* sub_12d67();
    r8[ah] = memoryAGet(ds, 0x5272);
    r8[al] = memoryAGet(ds, 0x5270);
    r16[ax] += 0x0b00;
    yield* sub_12c0d();
    flags.carry = 0;
    { pc = 0x12b8f; break; }
  case 0x12b8e: // 1020:298e
    flags.carry = 1;
  case 0x12b8f: // 1020:298f
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_12b94() // 1020:2994 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[di] = 0;
    if (!memoryAGet16(ds, 0x5270))
        { pc = 0x12c07; break; }
    memoryASet16(ds, 0x5270, memoryAGet16(ds, 0x5270) - 1);
    r16[ax] = memoryAGet16(ds, 0x5274);
    r16[ax]--;
    if (r16s[ax] >= 0)
        { pc = 0x12bf2; break; }
    r16[ax] = 0x0013;
    { pc = 0x12bf2; break; }
    // gap 61 bytes // gap 61 bytes
  case 0x12bf2: // 1020:29f2
    memoryASet16(ds, 0x5274, r16[ax]);
    yield* sub_12d67();
    r8[ah] = memoryAGet(ds, 0x5272);
    r8[al] = memoryAGet(ds, 0x5270);
    r16[ax] += r16[di];
    yield* sub_12cb1();
    flags.carry = 0;
    { pc = 0x12c08; break; }
  case 0x12c07: // 1020:2a07
    flags.carry = 1;
  case 0x12c08: // 1020:2a08
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_12bb5() // 1020:29b5 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] -= 0x0014;
    if (signed16(memoryAGet16(ds, 0x7d3d)) >= r16s[ax])
        { pc = 0x12bd7; break; }
    r16[ax] = 0x00ec;
    { pc = 0x12bda; break; }
  case 0x12bd7: // 1020:29d7
    r16[ax] = memoryAGet16(ds, 0x7d3d);
  case 0x12bda: // 1020:29da
    if (memoryAGet16(ds, 0x5270) >= r16[ax])
        { pc = 0x12c07; break; }
    r16[di] = 0x0013;
    memoryASet16(ds, 0x5270, memoryAGet16(ds, 0x5270) + 1);
    r16[ax] = memoryAGet16(ds, 0x5274);
    r16[ax]++;
    if (r16[ax] < 0x0014)
        { pc = 0x12bf2; break; }
    r16[ax] = 0;
  case 0x12bf2: // 1020:29f2
    memoryASet16(ds, 0x5274, r16[ax]);
    yield* sub_12d67();
    r8[ah] = memoryAGet(ds, 0x5272);
    r8[al] = memoryAGet(ds, 0x5270);
    r16[ax] += r16[di];
    yield* sub_12cb1();
    flags.carry = 0;
    { pc = 0x12c08; break; }
  case 0x12c07: // 1020:2a07
    flags.carry = 1;
  case 0x12c08: // 1020:2a08
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_12c0d() // 1020:2a0d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    push(ds);
    es = pop();
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x12c6c; break; }
    yield* sub_134f4();
    r16[si] = r16[ax];
    r16[di] += memoryAGet16(ds, 0x5266);
    r16[dx] = memoryAGet16(ds, 0x5274);
    r16[bx] = 0x63e4;
    ds = memoryAGet16(ds, 0x526c);
    r16[cx] = 0x0014;
  case 0x12c36: // 1020:2a36
    if (r16[di] < 0x5c80)
        { pc = 0x12c40; break; }
    r16[di] -= 0x1e00;
  case 0x12c40: // 1020:2a40
    r8[al] = lodsb_DSSI();
    r8[ah] = r8[al];
    r8[al] = memoryAGet(es, r16[bx] + r8[al]);
    memoryASet(es, 0x64f5, memoryAGet(es, 0x64f5) | r8[al]);
    r8[al] = r8[ah];
    push(es);
    r16[bp] = 0xa000;
    es = r16[bp];
    yield* sub_12ff5();
    es = pop();
    r16[dx]++;
    if (r16[dx] < 0x0014)
        { pc = 0x12c61; break; }
    r16[di] -= 0x0028;
    r16[dx] = 0;
  case 0x12c61: // 1020:2a61
    if (--r16[cx])
        { pc = 0x12c36; break; }
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  case 0x12c6c: // 1020:2a6c
    r16[si] = r16[ax];
    r16[di] <<= 1;
    r16[di] += memoryAGet16(ds, 0x5266);
    r16[dx] = memoryAGet16(ds, 0x5274);
    r16[bx] = 0x63e4;
    ds = memoryAGet16(ds, 0x526c);
    r16[cx] = 0x0014;
  case 0x12c82: // 1020:2a82
    if (r16[di] < 0x3c00)
        { pc = 0x12c8c; break; }
    r16[di] -= 0x3c00;
  case 0x12c8c: // 1020:2a8c
    r8[al] = lodsb_DSSI();
    r8[ah] = r8[al];
    r8[al] = memoryAGet(es, r16[bx] + r8[al]);
    memoryASet(es, 0x64f5, memoryAGet(es, 0x64f5) | r8[al]);
    r8[al] = r8[ah];
    yield* sub_13053();
    r16[dx]++;
    if (r16[dx] < 0x0014)
        { pc = 0x12ca6; break; }
    r16[di] -= 0x0050;
    r16[dx] = 0;
  case 0x12ca6: // 1020:2aa6
    if (--r16[cx])
        { pc = 0x12c82; break; }
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_12cb1() // 1020:2ab1
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x12d0d; break; }
    push(ds);
    push(es);
    push(ds);
    es = pop();
    yield* sub_134f4();
    r16[si] = r16[ax];
    r16[ax] = r16[di];
    r16[di] <<= 1;
    r16[di] += memoryAGet16(ds, 0x5266);
    r16[ax] += memoryAGet16(ds, 0x5274);
    if (r16[ax] < 0x0014)
        { pc = 0x12cd6; break; }
    r16[di] -= 0x0028;
  case 0x12cd6: // 1020:2ad6
    ds = memoryAGet16(ds, 0x526c);
    r16[cx] = 0x000c;
    r16[bx] = 0x63e4;
  case 0x12ce0: // 1020:2ae0
    if (r16[di] < 0x5c80)
        { pc = 0x12cea; break; }
    r16[di] -= 0x1e00;
  case 0x12cea: // 1020:2aea
    r8[al] = lodsb_DSSI();
    r8[ah] = r8[al];
    r8[al] = memoryAGet(es, r16[bx] + r8[al]);
    memoryASet(es, 0x64f5, memoryAGet(es, 0x64f5) | r8[al]);
    r8[al] = r8[ah];
    push(es);
    r16[dx] = 0xa000;
    es = r16[dx];
    yield* sub_12ff5();
    es = pop();
    r16[si] += 0x00ff;
    r16[di] += 0x027e;
    if (--r16[cx])
        { pc = 0x12ce0; break; }
    es = pop();
    ds = pop();
    return;
  case 0x12d0d: // 1020:2b0d
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    push(ds);
    es = pop();
    r16[si] = r16[ax];
    r16[ax] = r16[di];
    r16[di] <<= 1;
    r16[di] <<= 1;
    r16[di] += memoryAGet16(ds, 0x5266);
    r16[ax] += memoryAGet16(ds, 0x5274);
    if (r16[ax] < 0x0014)
        { pc = 0x12d30; break; }
    r16[di] -= 0x0050;
  case 0x12d30: // 1020:2b30
    ds = memoryAGet16(ds, 0x526c);
    r16[cx] = 0x000c;
    r16[bx] = 0x63e4;
  case 0x12d3a: // 1020:2b3a
    if (r16[di] < 0x3c00)
        { pc = 0x12d44; break; }
    r16[di] -= 0x3c00;
  case 0x12d44: // 1020:2b44
    r8[al] = lodsb_DSSI();
    r8[ah] = r8[al];
    r8[al] = memoryAGet(es, r16[bx] + r8[al]);
    memoryASet(es, 0x64f5, memoryAGet(es, 0x64f5) | r8[al]);
    r8[al] = r8[ah];
    yield* sub_13053();
    r16[si] += 0x00ff;
    r16[di] += 0x04fc;
    if (--r16[cx])
        { pc = 0x12d3a; break; }
    r16[bp] = pop();
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
}
function* sub_12d67() // 1020:2b67
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x12d88; break; }
    r16[ax] <<= 1;
    r8[dh] = memoryAGet(ds, 0x5276);
    r8[dl] = 0;
    r16[bx] = r16[dx];
    r16[bx] <<= 1;
    r16[dx] >>= 1;
    r16[ax] += r16[dx];
    r16[ax] += r16[bx];
    r16[ax] += 0x3e80;
    memoryASet16(ds, 0x5266, r16[ax]);
    return;
  case 0x12d88: // 1020:2b88
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = 0x0500;
    r8[dl] = memoryAGet(ds, 0x5276);
    r8[dh] = 0;
    mul16(r16[dx]);
    r16[dx] = pop();
    r16[ax] += r16[dx];
    memoryASet16(ds, 0x5266, r16[ax]);
    return;
  }
}
function* sub_12da2() // 1020:2ba2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x12da2; break; }
  case 0x12d9f: // 1020:2b9f
    { pc = 0x12e7d; break; }
  case 0x12da2: // 1020:2ba2
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = memoryAGet16(ds, 0x526c);
    yield* sub_134f4();
    if (!memoryAGet(ds, 0x64f5))
        { pc = 0x12d9f; break; }
    if (memoryAGet(ds, 0x64fc) & 0x03)
        { pc = 0x12d9f; break; }
    memoryASet(ds, 0x64f5, 0x00);
    r8[ah] = memoryAGet(ds, 0x5272);
    r8[al] = memoryAGet(ds, 0x5270);
    r16[si] = r16[ax];
    r8[ch] = 0x0c;
    r8[bh] = 0;
    r16[di] = memoryAGet16(ds, 0x5266);
    if (memoryAGet(cs, 0x0001) >= 0x03)
        { pc = 0x12e32; break; }
  case 0x12de3: // 1020:2be3
    r16[dx] = memoryAGet16(ds, 0x5274);
    r8[cl] = 0x14;
  case 0x12de9: // 1020:2be9
    r8[bl] = memoryAGet(es, r16[si]);
    if (!memoryAGet(ds, r16[bx] + 25572))
        { pc = 0x12e11; break; }
    memoryASet(ds, 0x64f5, 0x01);
    r8[al] = r8[bl];
    r16[bx] = memoryAGet16(ds, 0x64f6);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[bh] = 0;
    if (r16[di] < 0x3c00)
        { pc = 0x12e0b; break; }
    r16[di] -= 0x3c00;
  case 0x12e0b: // 1020:2c0b
    yield* sub_13053();
    r16[di] -= 0x0004;
  case 0x12e11: // 1020:2c11
    r16[dx]++;
    if (r16[dx] < 0x0014)
        { pc = 0x12e1c; break; }
    r16[di] -= 0x0050;
    r16[dx] = 0;
  case 0x12e1c: // 1020:2c1c
    r16[di] += 0x0004;
    r16[si]++;
    r8[cl]--;
    if (r8[cl])
        { pc = 0x12de9; break; }
    r16[di] += 0x0500;
    r16[si] += 0x00ec;
    r8[ch]--;
    if (r8[ch])
        { pc = 0x12de3; break; }
    { pc = 0x12e7d; break; }
  case 0x12e32: // 1020:2c32
    r16[dx] = memoryAGet16(ds, 0x5274);
    r8[cl] = 0x14;
  case 0x12e38: // 1020:2c38
    r8[bl] = memoryAGet(es, r16[si]);
    if (!memoryAGet(ds, r16[bx] + 25572))
        { pc = 0x12e5f; break; }
    memoryASet(ds, 0x64f5, 0x01);
    r8[al] = r8[bl];
    r16[bx] = memoryAGet16(ds, 0x64f6);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[bh] = 0;
    if (r16[di] < 0x5c80)
        { pc = 0x12e5a; break; }
    r16[di] -= 0x1e00;
  case 0x12e5a: // 1020:2c5a
    yield* sub_12fe8();
    r16[di]--;
    r16[di]--;
  case 0x12e5f: // 1020:2c5f
    r16[dx]++;
    if (r16[dx] < 0x0014)
        { pc = 0x12e6a; break; }
    r16[di] -= 0x0028;
    r16[dx] = 0;
  case 0x12e6a: // 1020:2c6a
    r16[di]++;
    r16[di]++;
    r16[si]++;
    r8[cl]--;
    if (r8[cl])
        { pc = 0x12e38; break; }
    r16[di] += 0x0280;
    r16[si] += 0x00ec;
    r8[ch]--;
    if (r8[ch])
        { pc = 0x12e32; break; }
  case 0x12e7d: // 1020:2c7d
    r16[bp] = pop();
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
}
function* sub_12e87() // 1020:2c87
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x12efb; break; }
    push(r16[bx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    yield* sub_134f4();
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[si] = memoryAGet16(ds, 0x5266);
    r16[di] = memoryAGet16(ds, 0x526a);
    r8[dl] = 0x14;
    r8[dh] = memoryAGet(ds, 0x5274);
    r8[dl] -= r8[dh];
    r8[dl] <<= 1;
    r8[dh] <<= 1;
    r16[bp] = 0x000c;
    r16[bp] -= memoryAGet16(ds, 0x5276);
    r8[cl] = 0x04;
    r16[bp] <<= r8[cl];
    r16[ax] = 0xa000;
    es = r16[ax];
    ds = r16[ax];
    r8[ch] = 0;
    r16[ax] = 0x0028;
    r16[bx] = 0x00c0;
    r16[bx] -= r16[bp];
  case 0x12ecc: // 1020:2ccc
    r8[cl] = r8[dl];
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[si] -= r16[ax];
    r8[cl] = r8[dh];
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[si] += r16[ax];
    r16[bp]--;
    if (r16[bp])
        { pc = 0x12ecc; break; }
    if (!r16[bx])
        { pc = 0x12ef5; break; }
    r16[si] = 0x3e80;
    r8[cl] = r8[dh];
    r16[si] += r16[cx];
  case 0x12ee6: // 1020:2ce6
    r8[cl] = r8[dl];
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[si] -= r16[ax];
    r8[cl] = r8[dh];
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[si] += r16[ax];
    r16[bx]--;
    if (r16[bx])
        { pc = 0x12ee6; break; }
  case 0x12ef5: // 1020:2cf5
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[bx] = pop();
    return;
  case 0x12efb: // 1020:2cfb
    push(r16[bx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[si] = memoryAGet16(ds, 0x5266);
    r16[di] = 0;
    r8[dl] = 0x14;
    r8[dh] = memoryAGet(ds, 0x5274);
    r8[dl] -= r8[dh];
    r8[dl] <<= 1;
    r8[dh] <<= 1;
    r16[bp] = 0x000c;
    r16[bp] -= memoryAGet16(ds, 0x5276);
    r8[cl] = 0x04;
    r16[bp] <<= r8[cl];
    es = memoryAGet16(ds, 0x5262);
    ds = memoryAGet16(ds, 0x5264);
    r8[ch] = 0;
    r16[ax] = 0x0050;
    r16[bx] = 0x00c0;
    r16[bx] -= r16[bp];
  case 0x12f34: // 1020:2d34
    r8[cl] = r8[dl];
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[si] -= r16[ax];
    r8[cl] = r8[dh];
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[si] += r16[ax];
    r16[bp]--;
    if (r16[bp])
        { pc = 0x12f34; break; }
    if (!r16[bx])
        { pc = 0x12f5c; break; }
    r8[cl] = r8[dh];
    r16[si] = r16[cx];
    r16[si] += r16[cx];
  case 0x12f4d: // 1020:2d4d
    r8[cl] = r8[dl];
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[si] -= r16[ax];
    r8[cl] = r8[dh];
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[si] += r16[ax];
    r16[bx]--;
    if (r16[bx])
        { pc = 0x12f4d; break; }
  case 0x12f5c: // 1020:2d5c
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[bx] = pop();
    return;
  }
}
function* sub_12f62() // 1020:2d62
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    push(es);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[ax] = 0;
    yield* sub_12a11();
    memoryASet16(ds, 0x5270, r16[ax]);
    memoryASet16(ds, 0x5272, r16[ax]);
    memoryASet16(ds, 0x5274, r16[ax]);
    memoryASet16(ds, 0x5276, r16[ax]);
    yield* sub_12d67();
    r16[di] = memoryAGet16(ds, 0x5266);
    es = memoryAGet16(ds, 0x526c);
    r16[si] = 0;
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x12faf; break; }
    yield* sub_134f4();
    r8[ch] = 0x0c;
  case 0x12f94: // 1020:2d94
    r8[cl] = 0x14;
  case 0x12f96: // 1020:2d96
    r8[al] = memoryAGet(es, r16[si]);
    yield* sub_12fe8();
    r16[si]++;
    r8[cl]--;
    if (r8[cl])
        { pc = 0x12f96; break; }
    r16[si] += 0x00ec;
    r16[di] += 0x0258;
    r8[ch]--;
    if (r8[ch])
        { pc = 0x12f94; break; }
    { pc = 0x12fca; break; }
  case 0x12faf: // 1020:2daf
    r8[ch] = 0x0c;
  case 0x12fb1: // 1020:2db1
    r8[cl] = 0x14;
  case 0x12fb3: // 1020:2db3
    r8[al] = memoryAGet(es, r16[si]);
    yield* sub_13053();
    r16[si]++;
    r8[cl]--;
    if (r8[cl])
        { pc = 0x12fb3; break; }
    r16[si] += 0x00ec;
    r16[di] += 0x04b0;
    r8[ch]--;
    if (r8[ch])
        { pc = 0x12fb1; break; }
  case 0x12fca: // 1020:2dca
    yield* sub_14146();
    r8[al] = memoryAGet(ds, 0x6521);
    r8[al] |= memoryAGet(ds, 0x6520);
    if (r8[al])
        { pc = 0x12fca; break; }
    yield* sub_1296f();
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_12fdc() // 1020:2ddc
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x13053; break; }
    r16[di] += 0x3e80;
    push(r16[dx]);
    push(es);
    r16[dx] = 0xa000;
    es = r16[dx];
    yield* sub_12ff5();
    es = pop();
    r16[dx] = pop();
    return;
    // gap 94 bytes // gap 94 bytes
  case 0x13053: // 1020:2e53
    push(r16[si]);
    push(ds);
    push(r16[bp]);
    push(es);
    r8[ah] = r8[al];
    r8[al] = 0;
    r16[ax] >>= 1;
    r16[si] = r16[ax];
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = memoryAGet16(ds, 0x5264);
    ds = memoryAGet16(cs, 0xb95e);
    r16[bp] = 0x004c;
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] -= 0x04b0;
    es = pop();
    r16[bp] = pop();
    ds = pop();
    r16[si] = pop();
    return;
  }
}
function* sub_12fe8() // 1020:2de8
{
    push(r16[dx]);
    push(es);
    r16[dx] = 0xa000;
    es = r16[dx];
    yield* sub_12ff5();
    es = pop();
    r16[dx] = pop();
}
function* sub_12ff5() // 1020:2df5
{
    push(r16[si]);
    push(ds);
    r8[ah] = 0;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[si] = r16[ax];
    r16[si] += 0x5dc0;
    push(es);
    ds = pop();
    r16[bp] = 0x0026;
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] += r16[bp];
    movsb_ESDI_DSSI();
    movsb_ESDI_DSSI();
    r16[di] -= 0x0258;
    ds = pop();
    r16[si] = pop();
}
function* sub_13053() // 1020:2e53
{
    push(r16[si]);
    push(ds);
    push(r16[bp]);
    push(es);
    r8[ah] = r8[al];
    r8[al] = 0;
    r16[ax] >>= 1;
    r16[si] = r16[ax];
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = memoryAGet16(ds, 0x5264);
    ds = memoryAGet16(cs, 0xb95e);
    r16[bp] = 0x004c;
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] += r16[bp];
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[di] -= 0x04b0;
    es = pop();
    r16[bp] = pop();
    ds = pop();
    r16[si] = pop();
}
function* sub_130b7() // 1020:2eb7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(ds);
    r16[dx] = 0x168f;
    ds = r16[dx];
    es = r16[dx];
    memoryASet(ds, 0x5250, r8[al]);
    r8[al] += 0x30;
    if (r8[al] <= 0x39)
        { pc = 0x130ca; break; }
    r8[al] += 0x07;
  case 0x130ca: // 1020:2eca
    memoryASet(ds, 0x5256, r8[al]);
    r16[di] = 0x72a3;
    r16[cx] = 0x0bf4;
    r8[al] = 0xff;
    for (; r16[cx] != 0; --r16[cx]) stosb_ESDI(r8[al]);
    r16[di] = 0x527c;
    r16[cx] = 0x020a;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    yield* sub_134dc();
    r16[dx] = 0x5251;
    yield* sub_10b7b();
    memoryASet16(ds, 0x526c, r16[ax]);
    push(r16[ax]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    r8[al] = memoryAGet(ds, 0x5250);
    r8[ah] = 0x03;
    mul8(r8[ah]);
    r16[si] = r16[ax];
    r16[si] += 0x50c8;
    r16[di] = 0x5081;
    r16[cx] = 0x0003;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[dx] = 0x5057;
    yield* sub_10610();
    r16[ax] = pop();
    yield* sub_13209();
    r16[ax] = 0x168f;
    es = r16[ax];
    r16[di] = 0x72a3;
    r16[cx] = 0x0180;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[cx] = 0x00f0;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r8[cl] = 0x03;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[cx] = 0x0514;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[cx] = 0x0190;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    movsw_ESDI_DSSI();
    r16[cx] = 0x008c;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    r16[cx] = 0x00c8;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    movsw_ESDI_DSSI();
    movsw_ESDI_DSSI();
    yield* sub_13176();
    yield* sub_131dd();
    r16[ax] = memoryAGet16(ds, 0x7695);
    memoryASet16(ds, 0x64e4, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x7697);
    memoryASet16(ds, 0x64e6, r16[ax]);
    r16[si] = 0x7dcb;
    r16[cx] = 0x000a;
  case 0x13157: // 1020:2f57
    if (memoryAGet(es, r16[si] + 7) < 0x08)
        { pc = 0x13164; break; }
    memoryASet16(es, r16[si] + 4, 0xffff);
  case 0x13164: // 1020:2f64
    r16[si] += 0x0014;
    if (--r16[cx])
        { pc = 0x13157; break; }
    r16[si] = 0x75a3;
    r16[di] = 0x7e97;
    r16[cx] = 0x08f4;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    ds = pop();
    return;
  }
}
function* sub_13176() // 1020:2f76
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[bx] = 0;
    r16[cx] = 0x0100;
    r8[dl] = 0;
  case 0x13182: // 1020:2f82
    if (memoryAGet(ds, r16[bx] + 29859) & 0x80)
        { pc = 0x1319c; break; }
    memoryASet(ds, r16[bx] + 24804, r8[bl]);
    memoryASet(ds, r16[bx] + 25060, r8[bl]);
    memoryASet(ds, r16[bx] + 25316, r8[bl]);
    memoryASet(ds, r16[bx] + 25572, 0x00);
    { pc = 0x131d3; break; }
  case 0x1319c: // 1020:2f9c
    r8[dl] = 0x01;
    r8[al] = r8[bl];
    memoryASet(ds, r16[bx] + 24804, r8[al]);
    memoryASet(ds, r16[bx] + 25062, r8[al]);
    memoryASet(ds, r16[bx] + 25317, r8[al]);
    r16[ax]++;
    memoryASet(ds, r16[bx] + 24805, r8[al]);
    memoryASet(ds, r16[bx] + 25060, r8[al]);
    memoryASet(ds, r16[bx] + 25318, r8[al]);
    r16[ax]++;
    memoryASet(ds, r16[bx] + 24806, r8[al]);
    memoryASet(ds, r16[bx] + 25061, r8[al]);
    memoryASet(ds, r16[bx] + 25316, r8[al]);
    memoryASet(ds, r16[bx] + 25572, 0x01);
    memoryASet16(ds, r16[bx] + 25573, 0x0101);
    r16[bx]++;
    r16[bx]++;
  case 0x131d3: // 1020:2fd3
    r16[bx]++;
    if (!r8[bh])
        { pc = 0x13182; break; }
    memoryASet(ds, 0x64f5, r8[dl]);
    return;
  }
}
function* sub_131dd() // 1020:2fdd
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = memoryAGet16(ds, 0x526c);
    r16[si] = 0x7bad;
    r16[cx] = 0x0064;
  case 0x131f2: // 1020:2ff2
    r16[di] = memoryAGet16(ds, r16[si] + 2);
    if (r16[di] == 0xffff)
        { pc = 0x131fd; break; }
    r8[al] = memoryAGet(ds, r16[si]);
    stosb_ESDI(r8[al]);
  case 0x131fd: // 1020:2ffd
    r16[si] += 0x0004;
    if (--r16[cx])
        { pc = 0x131f2; break; }
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_13209() // 1020:3009
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[bl] = memoryAGet(ds, 0x5250);
    r8[bh] = memoryAGet(ds, r16[bx] + 20640);
    memoryASet(ds, 0x508b, r8[bh]);
    if (memoryAGet(cs, 0x0001) >= 0x03)
        { pc = 0x13244; break; }
    r8[bl] = 0;
    r8[cl] = 0x04;
    r16[bx] >>= r8[cl];
    r16[ax] += r16[bx];
    ds = r16[ax];
    r16[si] = 0;
    memoryASet16(cs, 0xb95e, r16[ax]);
    memoryASet16(cs, 0x6676, 0x66b8);
    r16[cx] = 0x0100;
  case 0x13237: // 1020:3037
    r16[ax] = 0x0210;
    yield* sub_167be();
    r16[si] += 0x0080;
    if (--r16[cx])
        { pc = 0x13237; break; }
    return;
  case 0x13244: // 1020:3044
    r8[bl] = 0;
    r8[cl] = 0x04;
    r16[bx] >>= r8[cl];
    r16[ax] += r16[bx];
    memoryASet16(ds, 0x04c1, r16[ax]);
    ds = r16[ax];
    r16[si] = 0;
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[di] = 0x5dc0;
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r16[bx] = 0x0100;
  case 0x13265: // 1020:3065
    r8[al] = 0x01;
  case 0x13267: // 1020:3067
    out8(r16[dx], r8[al]);
    r16[cx] = 0x0010;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[di] -= 0x0020;
    r8[al] <<= 1;
    if (r8[al] < 0x10)
        { pc = 0x13267; break; }
    r16[di] += 0x0020;
    r16[bx]--;
    if (r16[bx])
        { pc = 0x13265; break; }
    return;
  }
}
function* sub_1327d() // 1020:307d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (memoryAGet(cs, 0x0001) == 0xff)
        { pc = 0x1328d; break; }
    { pc = 0x13360; break; }
  case 0x1328d: // 1020:308d
    r16[ax] = 0x000d;
    interrupt(0x10);
    r16[dx] = 0x03c8;
    r8[al] = 0x40;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r16[cx] = 0x001e;
    r16[si] = 0x5057;
  case 0x1329f: // 1020:309f
    r8[al] = lodsb_DSSI();
    r8[al] &= 0x3f;
    out8(r16[dx], r8[al]);
    if (--r16[cx])
        { pc = 0x1329f; break; }
    r16[cx] = 0x001e;
    r16[si] -= r16[cx];
    r8[al] = 0x40;
    r8[dl] = 0xc7;
    out8(r16[dx], r8[al]);
    r8[dl] = 0xc9;
  case 0x132b1: // 1020:30b1
    r8[ah] = memoryAGet(ds, r16[si]);
    r16[si]++;
    r8[ah] &= 0x3f;
    r8[al] = in8(r16[dx]);
    if (r8[al] != r8[ah])
        { pc = 0x132ca; break; }
    if (--r16[cx])
        { pc = 0x132b1; break; }
    yield* sub_13326();
    if (flags.carry)
        { pc = 0x132e6; break; }
    memoryASet(cs, 0x0001, 0x05);
    return;
  case 0x132ca: // 1020:30ca
    yield* sub_13326();
    if (flags.carry)
        { pc = 0x132e6; break; }
    memoryASet(cs, 0x0001, 0x04);
    r8[ah] = 0x12;
    r8[bl] = 0x10;
    interrupt(0x10);
    if (r8[bl])
        { pc = 0x13325; break; }
    memoryASet(cs, 0x0001, 0x03);
    return;
  case 0x132e6: // 1020:30e6
    r16[ax] = 0x0003;
    interrupt(0x10);
    r8[ah] = 0x0f;
    interrupt(0x10);
    if (r16[ax] == 0x5003)
        { pc = 0x132fb; break; }
    memoryASet(cs, 0x0001, 0x00);
    return;
  case 0x132fb: // 1020:30fb
    memoryASet(cs, 0x0001, 0x02);
    r16[ax] = 0x0009;
    interrupt(0x10);
    r16[ax] = 0xb800;
    es = r16[ax];
    memoryASet(es, 0x4000, 0xff);
    r8[al] = memoryAGet(es, 0x4000);
    r8[ah] = memoryAGet(es, 0x0000);
    if (r16[ax] == 0x00ff)
        { pc = 0x13325; break; }
    memoryASet(cs, 0x0001, 0x01);
  case 0x13325: // 1020:3125
    return;
    // gap 58 bytes // gap 58 bytes
  case 0x13360: // 1020:3160
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] == 0x01)
        { pc = 0x133c5; break; }
    if (r8[al] == 0x02)
        { pc = 0x133c5; break; }
    if (!r8[al])
        { pc = 0x133e9; break; }
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    r16[ax] = 0x000d;
    interrupt(0x10);
    r16[dx] = 0x03d4;
    r16[ax] = 0x2411;
    out16(r16[dx], r16[ax]);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x526a, 0x1f40);
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] == 0x05)
        { pc = 0x133a4; break; }
    if (r8[al] >= 0x03)
        { pc = 0x133bb; break; }
  case 0x133a4: // 1020:31a4
    r16[dx] = 0x5046;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[ax] = 0x1012;
    r16[bx] = 0;
    r16[cx] = 0x0010;
    r16[dx] = 0x5057;
    interrupt(0x10);
    { pc = 0x133e7; break; }
  case 0x133bb: // 1020:31bb
    r16[dx] = 0x5035;
    r16[ax] = 0x1002;
    interrupt(0x10);
    { pc = 0x133e7; break; }
  case 0x133c5: // 1020:31c5
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet16(ds, 0x526a, 0x0000);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x525c, 0x0050);
    memoryASet(cs, 0x0000, 0x02);
    r16[ax] = 0x0004;
    interrupt(0x10);
  case 0x133e7: // 1020:31e7
    { pc = 0x13439; break; }
  case 0x133e9: // 1020:31e9
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet16(ds, 0x526a, 0x0000);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x525c, 0x0050);
    memoryASet(cs, 0x0000, 0x02);
    r16[si] = 0x5025;
    r16[dx] = 0x03bf;
    r8[al] = 0x03;
    out8(r16[dx], r8[al]);
    r8[dl] = 0xb8;
    r8[al] = 0x82;
    out8(r16[dx], r8[al]);
    r8[dl] = 0xb4;
    r16[cx] = 0x000e;
    r16[ax] = 0;
  case 0x1341b: // 1020:321b
    r8[al] = r8[ah];
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = lodsb_DSSI();
    out8(r16[dx], r8[al]);
    r16[dx]--;
    r8[ah]++;
    if (--r16[cx])
        { pc = 0x1341b; break; }
    r16[cx] = 0x2000;
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[ax] = 0;
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    r8[dl] = 0xb8;
    r8[al] = 0x8a;
    out8(r16[dx], r8[al]);
  case 0x13439: // 1020:3239
    r16[bp] = pop();
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
}
function* sub_13326() // 1020:3126 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x000d;
    interrupt(0x10);
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
    memoryASet(es, 0x2000, r8[al]);
    if (memoryAGet(es, 0x2000) != r8[al])
        { pc = 0x1335e; break; }
    r16[ax] = 0x0103;
    out16(r16[dx], r16[ax]);
    memoryASet(es, r16[si], 0xaa);
    if (memoryAGet(es, r16[si]) != 0x55)
        { pc = 0x1335e; break; }
    flags.carry = 0;
    return;
  case 0x1335e: // 1020:315e
    flags.carry = 1;
    return;
  }
}
function* sub_13360() // 1020:3160
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] == 0x01)
        { pc = 0x133c5; break; }
    if (r8[al] == 0x02)
        { pc = 0x133c5; break; }
    if (!r8[al])
        { pc = 0x133e9; break; }
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    r16[ax] = 0x000d;
    interrupt(0x10);
    r16[dx] = 0x03d4;
    r16[ax] = 0x2411;
    out16(r16[dx], r16[ax]);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x526a, 0x1f40);
    r8[al] = memoryAGet(cs, 0x0001);
//    if (r8[al] == 0x05)
        { pc = 0x133a4; break; }
    if (r8[al] >= 0x03)
        { pc = 0x133bb; break; }
  case 0x133a4: // 1020:31a4
    r16[dx] = 0x5046;
    r16[ax] = 0x1002;
    interrupt(0x10);
    r16[ax] = 0x1012;
    r16[bx] = 0;
    r16[cx] = 0x0010;
    r16[dx] = 0x5057;
    interrupt(0x10);
    { pc = 0x133e7; break; }
  case 0x133bb: // 1020:31bb
    r16[dx] = 0x5035;
    r16[ax] = 0x1002;
    interrupt(0x10);
    { pc = 0x133e7; break; }
  case 0x133c5: // 1020:31c5
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet16(ds, 0x526a, 0x0000);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x525c, 0x0050);
    memoryASet(cs, 0x0000, 0x02);
    r16[ax] = 0x0004;
    interrupt(0x10);
  case 0x133e7: // 1020:31e7
    { pc = 0x13439; break; }
  case 0x133e9: // 1020:31e9
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet16(ds, 0x526a, 0x0000);
    memoryASet16(ds, 0x5268, 0x0000);
    memoryASet16(ds, 0x525c, 0x0050);
    memoryASet(cs, 0x0000, 0x02);
    r16[si] = 0x5025;
    r16[dx] = 0x03bf;
    r8[al] = 0x03;
    out8(r16[dx], r8[al]);
    r8[dl] = 0xb8;
    r8[al] = 0x82;
    out8(r16[dx], r8[al]);
    r8[dl] = 0xb4;
    r16[cx] = 0x000e;
    r16[ax] = 0;
  case 0x1341b: // 1020:321b
    r8[al] = r8[ah];
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = lodsb_DSSI();
    out8(r16[dx], r8[al]);
    r16[dx]--;
    r8[ah]++;
    if (--r16[cx])
        { pc = 0x1341b; break; }
    r16[cx] = 0x2000;
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[ax] = 0;
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    r8[dl] = 0xb8;
    r8[al] = 0x8a;
    out8(r16[dx], r8[al]);
  case 0x13439: // 1020:3239
    r16[bp] = pop();
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
}
let sub_13443_counter = 0;
function* sub_13443() // 1020:3243
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    /*if (sub_13443_counter++%4==0) */yield* sync(); return;
    push(r16[ax]);
    push(r16[dx]);
    if (!memoryAGet(cs, 0x0001))
        { pc = 0x1345f; break; }
    r16[dx] = 0x03da;
    r8[ah] = 0x08;
  case 0x13452: // 1020:3252
    r8[al] = in8(r16[dx]);
    if (r8[ah] & r8[al])
        { pc = 0x13452; break; }
  case 0x13457: // 1020:3257
    r8[al] = in8(r16[dx]);
    if (!(r8[ah] & r8[al]))
        { pc = 0x13457; break; }
    r16[dx] = pop();
    r16[ax] = pop();
    return;
  case 0x1345f: // 1020:325f
    r16[dx] = 0x03ba;
    r8[ah] = 0x01;
  case 0x13464: // 1020:3264
    r8[al] = in8(r16[dx]);
    if (r8[ah] & r8[al])
        { pc = 0x13464; break; }
  case 0x13469: // 1020:3269
    r8[al] = in8(r16[dx]);
    if (!(r8[ah] & r8[al]))
        { pc = 0x13469; break; }
    r16[dx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_13471() // 1020:3271
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x134a4; break; }
    yield* sub_112d3();
    r16[dx] = 0x03d4;
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[bx] = memoryAGet16(ds, 0x526a);
    r8[al] = 0x0d;
    r8[ah] = r8[bl];
    out16(r16[dx], r16[ax]);
    r16[ax]--;
    r8[ah] = r8[bh];
    out16(r16[dx], r16[ax]);
    r16[tx] = memoryAGet16(ds, 0x5268); memoryASet16(ds, 0x5268, r16[bx]); r16[bx] = r16[tx];
    memoryASet16(ds, 0x526a, r16[bx]);
    if (!memoryAGet(ds, 0x651a))
        { pc = 0x134a3; break; }
    yield* sub_13443();
  case 0x134a3: // 1020:32a3
    return;
  case 0x134a4: // 1020:32a4
    push(ds);
    push(es);
    push(r16[si]);
    push(r16[di]);
    push(r16[dx]);
    push(r16[ax]);
    push(r16[cx]);
    ds = memoryAGet16(ds, 0x5262);
    r16[si] = 0;
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[di] = 0;
    r16[dx] = 0x0060;
    r16[ax] = 0x0028;
  case 0x134be: // 1020:32be
    r16[cx] = r16[ax];
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[di] += 0x1fb0;
    r16[cx] = r16[ax];
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[di] -= 0x2000;
    r16[dx]--;
    if (r16[dx])
        { pc = 0x134be; break; }
    yield* sub_112d3();
    r16[cx] = pop();
    r16[ax] = pop();
    r16[dx] = pop();
    r16[di] = pop();
    r16[si] = pop();
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_134dc() // 1020:32dc
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x134f3; break; }
    push(r16[ax]);
    push(r16[dx]);
    r16[dx] = 0x03ce;
    r16[ax] = 0x0005;
    out16(r16[dx], r16[ax]);
    r16[ax] = 0x0003;
    out16(r16[dx], r16[ax]);
    r16[dx] = pop();
    r16[ax] = pop();
  case 0x134f3: // 1020:32f3
    return;
  }
}
function* sub_134f4() // 1020:32f4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x1350d; break; }
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
  case 0x1350d: // 1020:330d
    return;
  }
}
function* sub_13811() // 1020:3611
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx] = memoryAGet16(ds, r16[si] + 12);
    r16[bx]++;
    r16[bx]++;
  case 0x13816: // 1020:3616
    r16[ax] = memoryAGet16(ds, r16[bx]);
    if (r16s[ax] >= 0)
        { pc = 0x13820; break; }
    r16[bx] += r16[ax];
    { pc = 0x13816; break; }
  case 0x13820: // 1020:3620
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 12, r16[bx]);
    return;
  }
}
function* sub_13827() // 1020:3627 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x13827; break; }
  case 0x1370e: // 1020:350e
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    memoryASet(ds, 0x5250, 0x00);
    memoryASet(ds, 0x6518, 0x00);
    r16[di] = 0x527c;
    r16[cx] = 0x003a;
  case 0x13725: // 1020:3525
    memoryASet16(ds, r16[di] + 4, 0xffff);
    r16[di] += 0x0012;
    if (--r16[cx])
        { pc = 0x13725; break; }
    memoryASet16(ds, 0x5280, 0x0157);
    memoryASet16(ds, 0x527c, 0xff9c);
    memoryASet16(ds, 0x527e, 0x00b4);
    memoryASet16(ds, 0x5288, 0x6609);
    memoryASet16(ds, 0x52b6, 0x0151);
    memoryASet16(ds, 0x52b2, 0x01a4);
    memoryASet16(ds, 0x52b4, 0x00b4);
    memoryASet16(ds, 0x52be, 0x65e3);
  case 0x1375f: // 1020:355f
    yield* sub_14146();
    yield* sub_12da2();
    r16[si] = 0x527c;
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) + 0x0003);
    yield* sub_13811();
    r16[si] = 0x52b2;
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - 0x0003);
    yield* sub_13811();
    yield* sub_12e87();
    yield* sub_11e61();
    yield* sub_13471();
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] += 0x001c;
    if (signed16(memoryAGet16(ds, 0x52b2)) > r16s[ax])
        { pc = 0x1375f; break; }
    memoryASet16(ds, 0x52b6, 0x815a);
    memoryASet16(ds, 0x52b2, memoryAGet16(ds, 0x52b2) - 0x0018);
    r16[si] = 0x527c;
    memoryASet16(ds, 0x5288, 0x661d);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) - 0x0010);
    r16[cx] = 0x0010;
  case 0x137a8: // 1020:35a8
    push(r16[cx]);
    yield* sub_13811();
    yield* sub_14146();
    yield* sub_12da2();
    yield* sub_12e87();
    yield* sub_11e61();
    yield* sub_13471();
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) + 1);
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x137a8; break; }
    memoryASet16(ds, 0x5280, 0x0163);
    r16[si] = 0x663f;
  case 0x137cb: // 1020:35cb
    r8[al] = lodsb_DSSI();
    r8[ah] = 0;
    memoryASet16(ds, 0x527c, r16[ax]);
    r8[al] = lodsb_DSSI();
    r8[ah] = 0;
    memoryASet16(ds, 0x527e, r16[ax]);
    push(r16[si]);
    yield* sub_14146();
    yield* sub_12da2();
    yield* sub_12e87();
    yield* sub_11e61();
    yield* sub_13471();
    yield* sub_10a05();
    r16[si] = pop();
    if (memoryAGet(ds, 0x042b))
        { pc = 0x137fd; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    if (r16[ax] != 0xffdc)
        { pc = 0x137cb; break; }
    r16[si] += r16[ax];
    { pc = 0x137cb; break; }
  case 0x137fd: // 1020:35fd
    r16[ax] = 0x014f;
    r16[dx] = 0x0150;
    r16[si] = 0x527c;
    yield* sub_1392f();
    yield* sub_11c59();
    r16[ax] = 0x0001;
    flags.carry = 1;
    return;
    // gap 22 bytes // gap 22 bytes
  case 0x13827: // 1020:3627
    r16[ax] = 0;
    if (memoryAGet(ds, 0x6519) == 0x01)
        { pc = 0x1384e; break; }
    r16[ax]++;
    if (memoryAGet(ds, 0x6517) != 0x01)
        { pc = 0x1383b; break; }
    { pc = 0x13910; break; }
  case 0x1383b: // 1020:363b
    if (memoryAGet(ds, 0x6516) == 0x01)
        { pc = 0x13860; break; }
    if (memoryAGet(ds, 0x6518) != 0x01)
        { pc = 0x1384c; break; }
    { pc = 0x1370e; break; }
  case 0x1384c: // 1020:364c
    flags.carry = 0;
    return;
  case 0x1384e: // 1020:364e
    yield* sub_10373();
    memoryASet(ds, 0x0419, 0x10);
    yield* sub_1398d();
    r16[ax] = 0;
    memoryASet16(ds, 0x64fa, r16[ax]);
    flags.carry = 1;
    return;
  case 0x13860: // 1020:3660
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x0001;
    yield* sub_112ff();
    yield* sub_14ce9();
    memoryASet16(ds, 0x5280, 0x000d);
    memoryASet16(ds, 0x528a, 0x000f);
    r16[cx] = 0x003c;
  case 0x13881: // 1020:3681
    push(r16[cx]);
    yield* sub_12e87();
    yield* sub_13bc7();
    yield* sub_11e61();
    yield* sub_13471();
    yield* sub_13443();
    r16[ax] = memoryAGet16(ds, 0x528a);
    r16[ax]--;
    if (r16s[ax] >= signed16(0xfff0))
        { pc = 0x1389d; break; }
    r16[ax] = 0xfff0;
  case 0x1389d: // 1020:369d
    memoryASet16(ds, 0x528a, r16[ax]);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) - r16[ax]);
    r16[cx] = pop();
    if (--r16[cx])
        { pc = 0x13881; break; }
    yield* sub_1398d();
    r16[ax] = memoryAGet16(ds, 0x64e4);
    memoryASet16(ds, 0x527c, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x64e6);
    memoryASet16(ds, 0x527e, r16[ax]);
    if (!memoryAGet16(ds, 0x64fa))
        { pc = 0x138e3; break; }
    r16[si] = 0x52a0;
    r16[cx] = 0x0028;
  case 0x138c3: // 1020:36c3
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r16[bx] -= 0x0038;
    if (r16[bx] > 0x0001)
        { pc = 0x138de; break; }
    r16[ax] = memoryAGet16(ds, 0x64f8);
    memoryASet16(ds, r16[si], r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x64fa);
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    { pc = 0x138e3; break; }
  case 0x138de: // 1020:36de
    r16[si] += 0x0012;
    if (--r16[cx])
        { pc = 0x138c3; break; }
  case 0x138e3: // 1020:36e3
    memoryASet(ds, 0x0419, 0x10);
    yield* sub_119eb();
    r16[ax] = 0x0000;
    yield* sub_112ff();
    yield* sub_103d9();
    r8[bl] = memoryAGet(ds, 0x5250);
    r8[bh] = 0;
    r8[al] = memoryAGet(ds, r16[bx] + 20620);
    cbw();
    yield* sub_112ff();
    yield* sub_12f62();
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    flags.carry = 0;
    return;
  case 0x13910: // 1020:3710
    r16[ax] = 0x0002;
    yield* sub_112ff();
    memoryASet(ds, 0x0419, 0x10);
    memoryASet(ds, 0x041a, 0x00);
    memoryASet16(ds, 0x5280, 0x000d);
    r16[si] = 0x528e;
    r16[ax] = 0x014d;
    r16[dx] = 0x014e;
    r16[di] = r16[si] + 18;
    r8[cl] = 0x04;
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5270);
    r16[ax] <<= r8[cl];
    r16[ax] -= 0x0076;
    memoryASet16(ds, r16[si], r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5272);
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0064;
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    memoryASet16(ds, r16[di] + 4, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x5270);
    r16[ax] <<= r8[cl];
    r16[ax] += 0x01b6;
    memoryASet16(ds, r16[di], r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5272);
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0064;
    memoryASet16(ds, r16[di] + 2, r16[ax]);
    r16[cx] = 0x001f;
  case 0x13967: // 1020:3767
    push(r16[cx]);
    yield* sub_12e87();
    yield* sub_11e61();
    yield* sub_13471();
    r16[cx] = pop();
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) + 0x0008);
    memoryASet16(ds, r16[di], memoryAGet16(ds, r16[di]) - 0x0008);
    if (--r16[cx])
        { pc = 0x13967; break; }
    yield* sub_11c2a();
    memoryASet(ds, 0x5250, 0x00);
    memoryASet16(ds, 0x64fa, 0x0000);
    r16[ax] = 0x0001;
    flags.carry = 1;
    return;
  }
}
function* sub_1392f() // 1020:372f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[di] = r16[si] + 18;
    r8[cl] = 0x04;
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5270);
    r16[ax] <<= r8[cl];
    r16[ax] -= 0x0076;
    memoryASet16(ds, r16[si], r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5272);
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0064;
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    memoryASet16(ds, r16[di] + 4, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x5270);
    r16[ax] <<= r8[cl];
    r16[ax] += 0x01b6;
    memoryASet16(ds, r16[di], r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5272);
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0064;
    memoryASet16(ds, r16[di] + 2, r16[ax]);
    r16[cx] = 0x001f;
  case 0x13967: // 1020:3767
    push(r16[cx]);
    yield* sub_12e87();
    yield* sub_11e61();
    yield* sub_13471();
    r16[cx] = pop();
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) + 0x0008);
    memoryASet16(ds, r16[di], memoryAGet16(ds, r16[di]) - 0x0008);
    if (--r16[cx])
        { pc = 0x13967; break; }
    yield* sub_11c2a();
    memoryASet(ds, 0x5250, 0x00);
    memoryASet16(ds, 0x64fa, 0x0000);
    r16[ax] = 0x0001;
    flags.carry = 1;
    return;
  }
}
function* sub_1398d() // 1020:378d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    r16[di] = 0x64fc;
    r16[cx] = 0x002b;
    r8[al] = 0x00;
    for (; r16[cx] != 0; --r16[cx]) stosb_ESDI(r8[al]);
    r16[si] = 0x7e97;
    r16[di] = 0x75a3;
    r16[cx] = 0x08f4;
    for (; r16[cx] != 0; --r16[cx]) movsb_ESDI_DSSI();
    memoryASet(ds, 0x6504, r8[al]);
    memoryASet(ds, 0x6510, r8[al]);
    memoryASet(ds, 0x6511, 0x04);
    memoryASet(ds, 0x650d, r8[al]);
    memoryASet(ds, 0x6512, r8[al]);
    memoryASet(ds, 0x6514, r8[al]);
    memoryASet(ds, 0x6513, r8[al]);
    memoryASet(ds, 0x6505, r8[al]);
    memoryASet(ds, 0x650a, r8[al]);
    memoryASet(ds, 0x6509, r8[al]);
    memoryASet(ds, 0x6502, r8[al]);
    memoryASet(ds, 0x6517, r8[al]);
    memoryASet(ds, 0x6519, r8[al]);
    memoryASet(ds, 0x6516, r8[al]);
    memoryASet(ds, 0x651b, r8[al]);
    memoryASet(ds, 0x6500, r8[al]);
    r16[ax] = 0xffff;
    r16[si] = 0x5600;
    r16[cx] = 0x0004;
  case 0x139e5: // 1020:37e5
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    r16[si] += 0x0012;
    if (--r16[cx])
        { pc = 0x139e5; break; }
    yield* sub_158cc();
    yield* sub_140e8();
    r16[ax] = pop();
    return;
  }
}
function* sub_139f5() // 1020:37f5
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(ds, 0x5287))
        { pc = 0x13a20; break; }
    if (memoryAGet(ds, 0x651c) != 0x01)
        { pc = 0x13a20; break; }
    if (memoryAGet16(ds, 0x651e) < 0x008c)
        { pc = 0x13a20; break; }
    r8[al] = 0x1d;
    if (memoryAGet16(ds, 0x651e) < 0x00af)
        { pc = 0x13a1d; break; }
    r8[al] = 0;
    memoryASet16(ds, 0x651e, 0x0000);
  case 0x13a1d: // 1020:381d
    memoryASet(ds, 0x5280, r8[al]);
  case 0x13a20: // 1020:3820
    r16[si] = 0x528e;
    r16[cx] = 0x0029;
    r16[bx] = memoryAGet16(ds, 0x64fe);
  case 0x13a2a: // 1020:382a
    r16[ax] = memoryAGet16(ds, r16[si] + 4);
    if (!(r8[ah] & 0x20))
        { pc = 0x13aab; break; }
    if (r16[ax] == 0xffff)
        { pc = 0x13aab; break; }
    if (r8[bl] & 0x07)
        { pc = 0x13a6f; break; }
    r8[dl] = r8[al];
    r8[dl] -= 0x38;
    if (!r8[dl])
        { pc = 0x13a4f; break; }
    if (r8[dl] > 0x01)
        { pc = 0x13a5a; break; }
    if (memoryAGet(ds, 0x64fe) & 0x3f)
        { pc = 0x13aab; break; }
  case 0x13a4f: // 1020:384f
    r8[dl] ^= 0x01;
    r8[dl] += 0x38;
    memoryASet(ds, r16[si] + 4, r8[dl]);
    { pc = 0x13aab; break; }
  case 0x13a5a: // 1020:385a
    r8[dl] = r8[al];
    r8[dl] -= 0x33;
    if (r8[dl] > 0x01)
        { pc = 0x13a6f; break; }
    r8[dl] ^= 0x01;
    r8[dl] += 0x33;
    memoryASet(ds, r16[si] + 4, r8[dl]);
    { pc = 0x13aab; break; }
  case 0x13a6f: // 1020:386f
    if (r8[bl] & 0x01)
        { pc = 0x13aab; break; }
    r8[dl] = r8[al];
    r8[dl] -= 0x36;
    if (r8[dl] > 0x01)
        { pc = 0x13aab; break; }
    r8[dl] = 0x37;
    if (!memoryAGet(ds, r16[si] + 8))
        { pc = 0x13aa6; break; }
    r8[dh] = 0x01;
    if (memoryAGet(ds, 0x6511) <= 0x01)
        { pc = 0x13a91; break; }
    r8[dh] = 0;
  case 0x13a91: // 1020:3891
    memoryASet(ds, r16[si] + 8, memoryAGet(ds, r16[si] + 8) & r8[dh]);
    r8[dl]--;
    if (r8[al] == 0x36)
        { pc = 0x13aa6; break; }
    r16[di] = memoryAGet16(ds, r16[si] + 9);
    memoryASet16(ds, r16[di] + 2, memoryAGet16(ds, r16[di] + 2) + 0x0005);
    memoryASet(ds, 0x6511, 0x03);
  case 0x13aa6: // 1020:38a6
    memoryASet(ds, r16[si] + 4, r8[dl]);
    { pc = 0x13aab; break; }
  case 0x13aab: // 1020:38ab
    r16[si] += 0x0012;
    r16[cx]--;
    if (!r16[cx])
        { pc = 0x13ab4; break; }
    { pc = 0x13a2a; break; }
  case 0x13ab4: // 1020:38b4
    return;
  }
}
function* sub_13ab5() // 1020:38b5
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (memoryAGet(ds, 0x64fd))
        { pc = 0x13b37; break; }
    if (memoryAGet(ds, 0x5250) != 0x09)
        { pc = 0x13ad6; break; }
    r16[ax] = memoryAGet16(ds, 0x5292);
    r8[ah] &= 0x1f;
    r16[ax] -= 0x0038;
    if (r16[ax] > 0x0001)
        { pc = 0x13b37; break; }
  case 0x13ad6: // 1020:38d6
    if (memoryAGet(ds, 0x5250) != 0x10)
        { pc = 0x13ae2; break; }
    memoryASet(ds, 0x6518, 0x01);
  case 0x13ae2: // 1020:38e2
    r16[ax] = memoryAGet16(ds, 0x527c);
    r8[al] &= 0xf0;
    if (memoryAGet16(ds, 0x7e93) == r16[ax])
        { pc = 0x13af6; break; }
    r16[ax] -= 0x0010;
    if (memoryAGet16(ds, 0x7e93) != r16[ax])
        { pc = 0x13b37; break; }
  case 0x13af6: // 1020:38f6
    r16[ax] = memoryAGet16(ds, 0x527e);
    r8[al] &= 0xf0;
    if (memoryAGet16(ds, 0x7e95) == r16[ax])
        { pc = 0x13b0a; break; }
    r16[ax] -= 0x0010;
    if (memoryAGet16(ds, 0x7e95) != r16[ax])
        { pc = 0x13b37; break; }
  case 0x13b0a: // 1020:390a
    r16[ax] = 0x0004;
    yield* sub_112ff();
    yield* sub_119eb();
    yield* sub_12a11();
    r8[bl] = memoryAGet(ds, 0x5250);
    r8[bh] = 0;
    r16[si] = 0x523c;
    r8[al] = memoryAGet(ds, r16[bx] + r16[si]);
    r16[ax]++;
  case 0x13b22: // 1020:3922
    if (memoryAGet(ds, r16[si]) == r8[al])
        { pc = 0x13b29; break; }
    r16[si]++;
    { pc = 0x13b22; break; }
  case 0x13b29: // 1020:3929
    r16[ax] = r16[si];
    r16[ax] -= 0x523c;
    memoryASet(ds, 0x5250, r8[al]);
    memoryASet(ds, 0x6519, 0x01);
    return;
  case 0x13b37: // 1020:3937
    if (!memoryAGet(ds, 0x6510))
        { pc = 0x13b5d; break; }
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r8[dh] = r8[al];
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r8[dl] = r8[al];
    r16[si] = 0x7d3f;
    r16[cx] = 0x0014;
  case 0x13b54: // 1020:3954
    if (memoryAGet16(ds, r16[si]) == r16[dx])
        { pc = 0x13b5e; break; }
    r16[si] += 0x0007;
    if (--r16[cx])
        { pc = 0x13b54; break; }
  case 0x13b5d: // 1020:395d
    return;
  case 0x13b5e: // 1020:395e
    memoryASet16(ds, 0x5282, 0x0000);
    memoryASet16(ds, 0x528a, 0x0000);
    yield* sub_12a11();
    push(memoryAGet16(ds, 0x7d3d));
    push(r16[si]);
    memoryASet16(ds, 0x7d3d, 0x00ec);
    r16[ax] = memoryAGet16(ds, r16[si] + 4);
    r8[cl] = 0x04;
    r8[dl] = r8[al];
    r8[dh] = 0;
    r16[dx] <<= r8[cl];
    memoryASet16(ds, 0x527c, r16[dx]);
    r8[dl] = r8[ah];
    r8[dh] = 0;
    r16[dx] <<= r8[cl];
    memoryASet16(ds, 0x527e, r16[dx]);
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
  case 0x13b94: // 1020:3994
    if (memoryAGet(ds, 0x5272) == r8[ah])
        { pc = 0x13ba6; break; }
    if (memoryAGet(ds, 0x5272) < r8[ah])
        { pc = 0x13ba1; break; }
    yield* sub_12b11();
    { pc = 0x13b94; break; }
  case 0x13ba1: // 1020:39a1
    yield* sub_12b4c();
    { pc = 0x13b94; break; }
  case 0x13ba6: // 1020:39a6
    if (memoryAGet(ds, 0x5270) == r8[al])
        { pc = 0x13bb8; break; }
    if (memoryAGet(ds, 0x5270) < r8[al])
        { pc = 0x13bb3; break; }
    yield* sub_12b94();
    { pc = 0x13ba6; break; }
  case 0x13bb3: // 1020:39b3
    yield* sub_12bb5();
    { pc = 0x13ba6; break; }
  case 0x13bb8: // 1020:39b8
    r16[si] = pop();
    memoryASet16(ds, 0x7d3d, pop());
    r8[al] = memoryAGet(ds, r16[si] + 6);
    memoryASet(ds, 0x6502, r8[al]);
    yield* sub_1296f();
    return;
  }
}
function* sub_13bc7() // 1020:39c7
{
  var pc = 0;
  var temp_cond0;
  var temp_cond1;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(ds, 0x6511))
        { pc = 0x13bd1; break; }
    { pc = 0x13f96; break; }
  case 0x13bd1: // 1020:39d1
    es = memoryAGet16(ds, 0x526c);
    memoryASet16(ds, 0x64eb, 0x0028);
    r16[si] = 0x52a0;
    r8[cl] = 0x04;
  case 0x13be0: // 1020:39e0
    if (memoryAGet16(ds, r16[si] + 4) != 0xffff)
        { pc = 0x13be9; break; }
    { pc = 0x13f8a; break; }
  case 0x13be9: // 1020:39e9
    r16[ax] = memoryAGet16(ds, r16[si]);
    if (r16s[ax] > signed16(0x0008))
        { pc = 0x13bfa; break; }
    memoryASet16(ds, r16[si] + 6, 0x0020);
    memoryASet16(ds, r16[si] + 14, 0x0000);
  case 0x13bfa: // 1020:39fa
    if (r16s[ax] < signed16(0x0ff8))
        { pc = 0x13c09; break; }
    memoryASet16(ds, r16[si] + 6, 0xffe0);
    memoryASet16(ds, r16[si] + 14, 0x0000);
  case 0x13c09: // 1020:3a09
    r8[ah] = memoryAGet(ds, r16[si] + 4);
    r8[al] = r8[ah];
    if (memoryAGet16(ds, 0x64fe) & 0x0003)
        { pc = 0x13c42; break; }
    if (signed16(memoryAGet16(ds, r16[si] + 14)) <= signed16(0x0000))
        { pc = 0x13c42; break; }
    if (memoryAGet(ds, 0x6503) == 0x02)
        { pc = 0x13c42; break; }
    r8[al] -= 0x31;
    if (!r8[al])
        { pc = 0x13c30; break; }
    r8[al]--;
    if (r8[al])
        { pc = 0x13c42; break; }
    memoryASet16(ds, r16[si] + 6, 0x0000);
  case 0x13c30: // 1020:3a30
    memoryASet16(ds, r16[si] + 6, sar16(memoryAGet16(ds, r16[si] + 6), 0x0001));
    memoryASet16(ds, r16[si] + 4, memoryAGet16(ds, r16[si] + 4) + 1);
    memoryASet(ds, 0x6503, 0x01);
    memoryASet(ds, 0x6504, 0xc8);
    { pc = 0x13c85; break; }
  case 0x13c42: // 1020:3a42
    r8[ah] -= 0x33;
    if (r8[ah] > 0x01)
        { pc = 0x13c85; break; }
    memoryASet(ds, 0x6511, 0x04);
    if (!memoryAGet(ds, 0x6503))
        { pc = 0x13c6f; break; }
    r16[dx] = 0;
    memoryASet16(ds, r16[si] + 12, r16[dx]);
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= 0x0008;
    if (memoryAGet16(ds, r16[si] + 2) == r16[ax])
        { pc = 0x13c6c; break; }
    r8[dl] = 0x10;
    if (signed16(memoryAGet16(ds, r16[si] + 2)) < r16s[ax])
        { pc = 0x13c6c; break; }
    r16[dx] = -r16[dx];
  case 0x13c6c: // 1020:3a6c
    memoryASet16(ds, r16[si] + 14, r16[dx]);
  case 0x13c6f: // 1020:3a6f
    if (memoryAGet(ds, 0x6504))
        { pc = 0x13c85; break; }
    memoryASet16(ds, r16[si] + 4, 0x0031);
    memoryASet16(ds, r16[si] + 6, 0x0000);
    memoryASet(ds, 0x6503, 0x02);
  case 0x13c85: // 1020:3a85
    if (memoryAGet16(ds, r16[si] + 6))
        { pc = 0x13c8e; break; }
    { pc = 0x13d25; break; }
  case 0x13c8e: // 1020:3a8e
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] = sar16(r16[ax], r8[cl]);
    if (memoryAGet(ds, r16[si] + 2) & 0x0f)
        { pc = 0x13c9a; break; }
    r16[ax]--;
  case 0x13c9a: // 1020:3a9a
    r8[tl] = r8[al]; r8[al] = r8[ah]; r8[ah] = r8[tl];
    r16[di] = memoryAGet16(ds, r16[si]);
    r16[di] = sar16(r16[di], r8[cl]);
    r16[di] += r16[ax];
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (r8[al])
        { pc = 0x13cde; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[dx] = memoryAGet16(ds, r16[si] + 6);
    r16[dx] = sar16(r16[dx], r8[cl]);
    r16[dx] += r16[ax];
    r16[dx] = sar16(r16[dx], r8[cl]);
    r16[ax] = sar16(r16[ax], r8[cl]);
    if (r16[ax] == r16[dx])
        { pc = 0x13ce8; break; }
    r16[ax] = 0x0001;
    if (!(memoryAGet(ds, r16[si] + 7) & 0x80))
        { pc = 0x13cc9; break; }
    r16[ax] = -r16[ax];
  case 0x13cc9: // 1020:3ac9
    r16[di] += r16[ax];
    r16[dx] = memoryAGet16(ds, r16[si]);
    r16[dx] = sar16(r16[dx], r8[cl]);
    r16[ax] += r16[dx];
    if (r16[ax] >= 0x0100)
        { pc = 0x13cde; break; }
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (!r8[al])
        { pc = 0x13ce8; break; }
  case 0x13cde: // 1020:3ade
    memoryASet16(ds, r16[si] + 6, -memoryAGet16(ds, r16[si] + 6));
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) + r16[ax]);
  case 0x13ce8: // 1020:3ae8
    memoryASet(ds, 0x6511, 0x04);
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    if (r16s[ax] >= 0)
        { pc = 0x13cf6; break; }
    r16[ax] = -r16[ax];
  case 0x13cf6: // 1020:3af6
    r16[dx] = 0x0003;
    if (r16[ax] < 0x0010)
        { pc = 0x13d00; break; }
    r8[dl] = 0x01;
  case 0x13d00: // 1020:3b00
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    if (r16s[ax] >= 0)
        { pc = 0x13d09; break; }
    r16[dx] = -r16[dx];
  case 0x13d09: // 1020:3b09
    r16[bp] = r16[ax];
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) + r16[ax]);
    r16[ax] = r16[bp];
    r16[ax] -= r16[dx];
    r16[dx] = r16[ax];
    if (r16s[ax] >= 0)
        { pc = 0x13d1b; break; }
    r16[ax] = -r16[ax];
  case 0x13d1b: // 1020:3b1b
    if (r16[ax] >= 0x0010)
        { pc = 0x13d22; break; }
    r16[dx] = 0;
  case 0x13d22: // 1020:3b22
    memoryASet16(ds, r16[si] + 6, r16[dx]);
  case 0x13d25: // 1020:3b25
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet16(ds, 0x64ed, r16[ax]);
    r8[tl] = r8[al]; r8[al] = r8[ah]; r8[ah] = r8[tl];
    r16[di] = memoryAGet16(ds, r16[si]);
    r16[di] = sar16(r16[di], r8[cl]);
    r16[di] += r16[ax];
    if (signed16(memoryAGet16(ds, r16[si] + 14)) >= signed16(0x0000))
        { pc = 0x13d8a; break; }
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[al] = memoryAGet(ds, r16[bx] + 27640);
    r8[al] >>= r8[cl];
    cbw();
    r16[ax]++;
    r8[tl] = r8[al]; r8[al] = r8[ah]; r8[ah] = r8[tl];
    r16[di] -= r16[ax];
    r16[bx] = 0x74a3;
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x7f;
    if (r8[al])
        { pc = 0x13d78; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[ax] += memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= memoryAGet16(ds, 0x64ed);
    if (r16[ax])
        { pc = 0x13d6b; break; }
    { pc = 0x13f5a; break; }
  case 0x13d6b: // 1020:3b6b
    r8[al] = memoryAGet(es, r16[di] + 65280);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x7f;
    if (r8[al])
        { pc = 0x13d78; break; }
    { pc = 0x13f5a; break; }
  case 0x13d78: // 1020:3b78
    memoryASet16(ds, r16[si] + 14, 0x0000);
    push(r16[si]);
    yield* sub_15333();
    if (!flags.zero)
        { pc = 0x13d87; break; }
    memoryASet(ds, r16[si] + 2, memoryAGet(ds, r16[si] + 2) & 0xf0);
  case 0x13d87: // 1020:3b87
    { pc = 0x13f8a; break; }
  case 0x13d8a: // 1020:3b8a
    r16[ax] = memoryAGet16(ds, r16[si] + 4);
    r16[dx] = r16[ax];
    r8[dh] &= 0x1f;
    if (memoryAGet(ds, r16[si] + 11) & 0x01)
        { pc = 0x13da8; break; }
    r16[bx] = r16[dx];
    if (!(memoryAGet(ds, r16[bx] + 28441) & 0x08))
        { pc = 0x13db8; break; }
    if (signed16(memoryAGet16(ds, r16[si] + 14)) < signed16(0x00a0))
        { pc = 0x13db8; break; }
  case 0x13da8: // 1020:3ba8
    if (!(r8[ah] & 0x20))
        { pc = 0x13db0; break; }
    { pc = 0x13f5a; break; }
  case 0x13db0: // 1020:3bb0
    memoryASet16(ds, r16[si] + 4, 0xffff);
    { pc = 0x13f8a; break; }
  case 0x13db8: // 1020:3bb8
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(es, r16[di]);
    r8[ah] = r8[al];
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[tl] = r8[ah]; r8[ah] = r8[al]; r8[al] = r8[tl];
    r16[bx] = 0x73a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    if (signed16(memoryAGet16(ds, r16[si] + 2)) > signed16(0x0006))
        { pc = 0x13dd1; break; }
    r8[al] = 0;
    { pc = 0x13de8; break; }
  case 0x13dd1: // 1020:3bd1
    r8[dl] = memoryAGet(ds, 0x508b);
    r8[dh] = 0;
    r16[dx] <<= r8[cl];
    if (signed16(memoryAGet16(ds, r16[si] + 2)) < r16s[dx])
        { pc = 0x13de8; break; }
    r8[al] = 0;
    r16[dx] += 0x0040;
    if (signed16(memoryAGet16(ds, r16[si] + 2)) >= r16s[dx])
        { pc = 0x13dfe; break; }
  case 0x13de8: // 1020:3be8
    if (r8[al] == 0x09)
        { pc = 0x13dfe; break; }
    if (r8[al] != 0x08)
        { pc = 0x13e03; break; }
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    r8[dh] &= 0x1f;
    if (r16[dx] != 0x0027)
        { pc = 0x13dfe; break; }
    { pc = 0x13d78; break; }
  case 0x13dfe: // 1020:3bfe
    memoryASet16(ds, r16[si] + 4, 0xffff);
  case 0x13e03: // 1020:3c03
    if (r8[al] == 0x06)
        { pc = 0x13e13; break; }
    r8[ah] &= 0x01;
    r8[al] |= r8[ah];
    r8[al] &= 0x07;
    if (!r8[al])
        { pc = 0x13e13; break; }
    { pc = 0x13d78; break; }
  case 0x13e13: // 1020:3c13
    r16[dx] = memoryAGet16(ds, r16[si] + 14);
    r16[dx] = sar16(r16[dx], r8[cl]);
    r16[dx] += memoryAGet16(ds, r16[si] + 2);
    r16[dx] = sar16(r16[dx], r8[cl]);
    r16[dx] -= memoryAGet16(ds, 0x64ed);
    if (!r16[dx])
        { pc = 0x13e70; break; }
    memoryASet16(ds, 0x64ed, r16[dx]);
    push(r16[bx]);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    yield* sub_15245();
    r16[bx] = pop();
    if (flags.carry)
        { pc = 0x13e7b; break; }
    r16[dx] = memoryAGet16(ds, 0x64ed);
  case 0x13e35: // 1020:3c35
    r16[di] += 0x0100;
    r8[al] = memoryAGet(es, r16[di]);
    push(r16[bx]);
    r16[bx] = 0x72a3;
    r8[ah] = r8[al];
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[tl] = r8[ah]; r8[ah] = r8[al]; r8[al] = r8[tl];
    r16[bx] = pop();
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    if (r8[al] == 0x09)
        { pc = 0x13dfe; break; }
    if (r8[al] != 0x08)
        { pc = 0x13e5d; break; }
    r16[dx] = memoryAGet16(ds, r16[si] + 4);
    r8[dh] &= 0x1f;
    if (r16[dx] != 0x0027)
        { pc = 0x13e5d; break; }
    { pc = 0x13eed; break; }
  case 0x13e5d: // 1020:3c5d
    if (r8[al] == 0x06)
        { pc = 0x13e6d; break; }
    r8[ah] &= 0x01;
    r8[al] |= r8[ah];
    r8[al] &= 0x07;
    if (!r8[al])
        { pc = 0x13e6d; break; }
    { pc = 0x13eed; break; }
  case 0x13e6d: // 1020:3c6d
    r16[dx]--;
    if (r16[dx])
        { pc = 0x13e35; break; }
  case 0x13e70: // 1020:3c70
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    yield* sub_15245();
    if (flags.carry)
        { pc = 0x13e7b; break; }
    { pc = 0x13f5a; break; }
  case 0x13e7b: // 1020:3c7b
    memoryASet16(ds, r16[si] + 12, 0x0000);
    r16[di] = r16[ax];
    push(r16[si]);
    yield* sub_15333();
    if (!flags.zero)
        { pc = 0x13ed4; break; }
    push(r16[di]);
    yield* sub_15333();
    if (!flags.zero)
        { pc = 0x13e9e; break; }
    memoryASet16(ds, r16[si] + 2, r16[dx]);
    memoryASet16(ds, r16[si] + 14, 0x0000);
    memoryASet16(ds, r16[si] + 12, 0x0000);
    { pc = 0x13f8a; break; }
  case 0x13e9e: // 1020:3c9e
    memoryASet(ds, r16[di] + 8, memoryAGet(ds, r16[di] + 8) | 0x01);
    memoryASet16(ds, r16[di] + 9, r16[si]);
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    r16[ax] = -r16[ax];
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[bx] = r16[ax];
    r16[ax] += 0x0010;
    if (r16s[ax] >= 0)
        { pc = 0x13eb8; break; }
    r16[bx] += 0x0020;
    if (r16s[bx] < 0)
        { pc = 0x13ec3; break; }
  case 0x13eb8: // 1020:3cb8
    memoryASet16(ds, r16[si] + 14, 0x0000);
    memoryASet16(ds, r16[si] + 2, r16[dx]);
    { pc = 0x13f8a; break; }
  case 0x13ec3: // 1020:3cc3
    memoryASet16(ds, r16[di] + 14, r16[bx]);
    memoryASet16(ds, r16[si] + 14, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r16[ax] = sar16(r16[ax], 0x0001);
    memoryASet16(ds, r16[di] + 6, r16[ax]);
    { pc = 0x13f5a; break; }
  case 0x13ed4: // 1020:3cd4
    push(r16[di]);
    yield* sub_15333();
    if (!flags.zero)
        { pc = 0x13eeb; break; }
    memoryASet16(ds, r16[si] + 2, r16[dx]);
    if (memoryAGet16(ds, r16[si] + 14) >= 0x0010)
        { pc = 0x13f3f; break; }
    memoryASet16(ds, r16[si] + 14, 0x0000);
    { pc = 0x13f8a; break; }
  case 0x13eeb: // 1020:3ceb
    { pc = 0x13e9e; break; }
  case 0x13eed: // 1020:3ced
    push(r16[si]);
    yield* sub_15333();
    if (!flags.zero)
        { pc = 0x13f37; break; }
    memoryASet16(ds, r16[si] + 14, 0x0000);
    memoryASet(ds, r16[si] + 2, memoryAGet(ds, r16[si] + 2) & 0xf0);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + 0x0010);
    r8[al] = memoryAGet(ds, r16[si] + 4);
    r8[al] -= 0x31;
    if (r8[al] > 0x03)
        { pc = 0x13f12; break; }
    memoryASet(ds, r16[si] + 4, 0x31);
    memoryASet(ds, 0x6503, 0x00);
  case 0x13f12: // 1020:3d12
    if (!(memoryAGet(ds, r16[si] + 5) & 0x20))
        { pc = 0x13f8a; break; }
    if (memoryAGet16(ds, 0x5292) != 0xffff)
        { pc = 0x13f8a; break; }
    memoryASet(ds, 0x6505, 0x20);
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    memoryASet16(ds, 0x5290, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si]);
    memoryASet16(ds, 0x528e, r16[ax]);
    memoryASet16(ds, 0x5292, 0x002e);
    { pc = 0x13f8a; break; }
  case 0x13f37: // 1020:3d37
    memoryASet(ds, r16[si] + 2, memoryAGet(ds, r16[si] + 2) & 0xf0);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + 0x0010);
  case 0x13f3f: // 1020:3d3f
    memoryASet(ds, 0x6511, 0x04);
    memoryASet16(ds, r16[si] + 12, 0x0000);
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    r16[ax] = -r16[ax];
    temp_cond0 = r16s[ax] < 0;
    r16[ax] += 0x0030;
    if (temp_cond0)
        { pc = 0x13f55; break; }
    r16[ax] = 0;
  case 0x13f55: // 1020:3d55
    memoryASet16(ds, r16[si] + 14, r16[ax]);
    { pc = 0x13f8a; break; }
  case 0x13f5a: // 1020:3d5a
    r8[dl] = 0x0f;
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    if (r8[bl] >= 0x65)
        { pc = 0x13f6b; break; }
    r8[dl] = memoryAGet(ds, r16[bx] + 28512);
  case 0x13f6b: // 1020:3d6b
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    r16[ax] = sar16(r16[ax], r8[cl]);
    if (!r16[ax])
        { pc = 0x13f77; break; }
    memoryASet(ds, 0x6511, 0x04);
  case 0x13f77: // 1020:3d77
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (r8s[al] >= r8s[dl])
        { pc = 0x13f87; break; }
    temp_cond1 = signed16(memoryAGet16(ds, r16[si] + 14) + 0x0010) <= 0;
    memoryASet16(ds, r16[si] + 14, memoryAGet16(ds, r16[si] + 14) + 0x0010);
    if (temp_cond1)
        { pc = 0x13f87; break; }
    memoryASet16(ds, r16[si] + 12, memoryAGet16(ds, r16[si] + 12) + 1);
  case 0x13f87: // 1020:3d87
    yield* sub_13f97();
  case 0x13f8a: // 1020:3d8a
    r16[si] += 0x0012;
    memoryASet16(ds, 0x64eb, memoryAGet16(ds, 0x64eb) - 1);
    if (!memoryAGet16(ds, 0x64eb))
        { pc = 0x13f96; break; }
    { pc = 0x13be0; break; }
  case 0x13f96: // 1020:3d96
    return;
  }
}
function* sub_13f97() // 1020:3d97
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[dx]);
    if (memoryAGet16(ds, r16[si] + 12) >= 0x000a)
        { pc = 0x13fa3; break; }
    { pc = 0x14024; break; }
  case 0x13fa3: // 1020:3da3
    if (signed16(memoryAGet16(ds, 0x528a)) >= signed16(0x00c0))
        { pc = 0x14024; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x13fb5; break; }
    r16[ax] = -r16[ax];
  case 0x13fb5: // 1020:3db5
    if (r16[ax] >= 0x0020)
        { pc = 0x14024; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x13fc3; break; }
    r16[ax] = -r16[ax];
  case 0x13fc3: // 1020:3dc3
    if (r16[ax] >= 0x0020)
        { pc = 0x14024; break; }
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[bl] = memoryAGet(ds, r16[bx] + 27639);
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[dx] = memoryAGet16(ds, 0x527c);
    if (r16s[ax] <= r16s[dx])
        { pc = 0x13fe1; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r8[bl] = 0x18;
  case 0x13fe1: // 1020:3de1
    r8[bh] = 0;
    r16[ax] += r16[bx];
    if (r16s[ax] < r16s[dx])
        { pc = 0x14024; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[dx] = memoryAGet16(ds, 0x527e);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[bl] = memoryAGet(ds, r16[bx] + 27640);
    r8[bl]--;
    if (r16s[ax] >= r16s[dx])
        { pc = 0x14005; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r8[bl] = 0x20;
  case 0x14005: // 1020:3e05
    r8[bh] = 0;
    r16[ax] -= r16[bx];
    if (r16s[ax] >= r16s[dx])
        { pc = 0x14024; break; }
    r8[al] = 0x05;
    yield* sub_113e6();
    memoryASet(ds, 0x6513, 0x18);
    if (!(memoryAGet(ds, r16[si] + 11) & 0x02))
        { pc = 0x14024; break; }
    yield* sub_15bcc();
    memoryASet(ds, r16[si] + 11, memoryAGet(ds, r16[si] + 11) & 0xfd);
  case 0x14024: // 1020:3e24
    r16[dx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_14028() // 1020:3e28
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[bp] = 0xffff;
    memoryASet16(ds, 0x564c, r16[bp]);
    memoryASet16(ds, 0x565e, r16[bp]);
    memoryASet16(ds, 0x5670, r16[bp]);
    memoryASet16(ds, 0x5682, r16[bp]);
    r16[si] = 0x7dcb;
    r16[di] = 0x5648;
    r16[ax] = memoryAGet16(ds, 0x5270);
    r16[dx] = memoryAGet16(ds, 0x5272);
    r8[cl] = 0x04;
    r16[ax] <<= r8[cl];
    r16[dx] <<= r8[cl];
    r16[cx] = 0x000a;
  case 0x14056: // 1020:3e56
    if (memoryAGet16(ds, r16[si] + 4) == r16[bp])
        { pc = 0x140c7; break; }
    push(r16[ax]);
    push(r16[dx]);
    r8[al] = memoryAGet(ds, r16[si] + 7);
    cbw();
    r8[dl] = memoryAGet(ds, r16[si] + 6);
    if (r8[dl])
        { pc = 0x1406e; break; }
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) - r16[ax]);
    { pc = 0x140d0; break; }
  case 0x1406e: // 1020:3e6e
    if (r8[dl] != 0x02)
        { pc = 0x14078; break; }
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    { pc = 0x140d0; break; }
  case 0x14078: // 1020:3e78
    if (r8[dl] != 0x01)
        { pc = 0x14081; break; }
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) + r16[ax]);
    { pc = 0x140d0; break; }
  case 0x14081: // 1020:3e81
    if (r8[dl] != 0x03)
        { pc = 0x1408a; break; }
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    { pc = 0x140d0; break; }
  case 0x1408a: // 1020:3e8a
    r16[dx] = pop();
    r16[ax] = pop();
    r16[bx] = memoryAGet16(ds, r16[si]);
    r16[bx] += 0x0010;
    flags.carry = r16[bx] < r16[ax];
    r16[bx] -= r16[ax];
    if (flags.carry)
        { pc = 0x140c7; break; }
    r16[bx] -= 0x0020;
    if (r16s[bx] > signed16(0x0140))
        { pc = 0x140c7; break; }
    r16[bx] = memoryAGet16(ds, r16[si] + 2);
    flags.carry = r16[bx] < r16[dx];
    r16[bx] -= r16[dx];
    if (flags.carry)
        { pc = 0x140c7; break; }
    r16[bx] -= 0x0010;
    if (r16s[bx] > signed16(0x00c0))
        { pc = 0x140c7; break; }
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r16[bx] += 0x001e;
    memoryASet16(ds, r16[di] + 4, r16[bx]);
    r16[bx] = memoryAGet16(ds, r16[si]);
    memoryASet16(ds, r16[di], r16[bx]);
    r16[bx] = memoryAGet16(ds, r16[si] + 2);
    memoryASet16(ds, r16[di] + 2, r16[bx]);
    memoryASet16(ds, r16[di] + 9, r16[si]);
    r16[di] += 0x0012;
  case 0x140c7: // 1020:3ec7
    r16[si] += 0x0014;
    r16[cx]--;
    if (!r16[cx])
        { pc = 0x140cf; break; }
    { pc = 0x14056; break; }
  case 0x140cf: // 1020:3ecf
    return;
  case 0x140d0: // 1020:3ed0
    memoryASet16(ds, r16[si] + 17, memoryAGet16(ds, r16[si] + 17) + 1);
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    if (memoryAGet16(ds, r16[si] + 10) != r16[ax])
        { pc = 0x1408a; break; }
    r8[dl] ^= 0x02;
    memoryASet16(ds, r16[si] + 17, 0x0000);
    memoryASet(ds, r16[si] + 6, r8[dl]);
    { pc = 0x1408a; break; }
    return;
  }
}
function* sub_140e8() // 1020:3ee8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[bx]);
    push(r16[di]);
    push(r16[si]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    es = r16[ax];
    r16[di] = 0x527c;
    r16[cx] = 0x020a;
    r16[ax] = 0;
    for (; r16[cx] != 0; --r16[cx]) stosw_ESDI(r16[ax]);
    r16[di] = 0x527c;
    r16[cx] = 0x003a;
  case 0x14102: // 1020:3f02
    memoryASet16(ds, r16[di] + 4, 0xffff);
    r16[di] += 0x0012;
    if (--r16[cx])
        { pc = 0x14102; break; }
    r16[si] = 0x52a0;
    r16[di] = 0x75a3;
    r16[cx] = 0x0028;
  case 0x14115: // 1020:3f15
    r16[ax] = memoryAGet16(ds, r16[di]);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[di] + 2);
    memoryASet16(ds, r16[si], r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[di] + 4);
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    memoryASet(ds, r16[si] + 11, 0x00);
    r16[si] += 0x0012;
    r16[di] += 0x0006;
    if (--r16[cx])
        { pc = 0x14115; break; }
    memoryASet(ds, 0x6511, 0x04);
    r16[ax] = memoryAGet16(ds, 0x7695);
    memoryASet16(ds, 0x527c, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x7697);
    memoryASet16(ds, 0x527e, r16[ax]);
    r16[si] = pop();
    r16[di] = pop();
    r16[bx] = pop();
    return;
  }
}
function* sub_14146() // 1020:3f46
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet(ds, 0x64fc, memoryAGet(ds, 0x64fc) + 1);
    if (memoryAGet(ds, 0x64fc) & 0x03)
        { pc = 0x14166; break; }
    r16[ax] = memoryAGet16(ds, 0x64f6);
    r8[ah]++;
    if (r16[ax] != 0x63e4)
        { pc = 0x14163; break; }
    r8[ah] -= 0x03;
  case 0x14163: // 1020:3f63
    memoryASet16(ds, 0x64f6, r16[ax]);
  case 0x14166: // 1020:3f66
    if (memoryAGet(ds, 0x6502))
        { pc = 0x14173; break; }
    yield* sub_1423c();
    yield* sub_14174();
  case 0x14173: // 1020:3f73
    return;
  }
}
function* sub_14174() // 1020:3f74
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (memoryAGet16(ds, 0x528a))
        { pc = 0x14185; break; }
    memoryASet(ds, 0x6521, 0x00);
  case 0x14185: // 1020:3f85
    r16[dx] = memoryAGet16(ds, 0x527e);
    r8[cl] = 0x04;
    r16[dx] = sar16(r16[dx], r8[cl]);
    r16[dx] -= memoryAGet16(ds, 0x5272);
    if (memoryAGet(ds, 0x6521))
        { pc = 0x141cf; break; }
    if (memoryAGet16(ds, 0x528a))
        { pc = 0x141a6; break; }
    if (!memoryAGet(ds, 0x650d))
        { pc = 0x141b8; break; }
  case 0x141a6: // 1020:3fa6
    r16[ax] = 0x0003;
    if (r16s[dx] >= signed16(0x000a))
        { pc = 0x141c8; break; }
    r16[ax] = 0x0009;
    if (r16s[dx] > signed16(0x0002))
        { pc = 0x141cf; break; }
    { pc = 0x141c8; break; }
  case 0x141b8: // 1020:3fb8
    r16[ax] = 0x000a;
    if (r16s[dx] >= signed16(0x000b))
        { pc = 0x141c8; break; }
    r16[ax] = 0x0009;
    if (r16s[dx] > signed16(0x0002))
        { pc = 0x141cf; break; }
  case 0x141c8: // 1020:3fc8
    memoryASet16(ds, 0x6524, r16[ax]);
    memoryASet(ds, 0x6521, memoryAGet(ds, 0x6521) + 1);
  case 0x141cf: // 1020:3fcf
    r16[ax] = memoryAGet16(ds, 0x7693);
    r16[ax] += 0x000c;
    r16[ax] <<= r8[cl];
    if (memoryAGet16(ds, 0x527e) > r16[ax])
        { pc = 0x141e8; break; }
    r16[bx] = memoryAGet16(ds, 0x5272);
    r16[bx]--;
    if (signed16(memoryAGet16(ds, 0x7693)) < r16s[bx])
        { pc = 0x14231; break; }
  case 0x141e8: // 1020:3fe8
    r16[ax] = memoryAGet16(ds, 0x7693);
    r16[ax] -= memoryAGet16(ds, 0x5272);
    if (r16[ax] >= 0x0005)
        { pc = 0x14205; break; }
    r16[ax] = memoryAGet16(ds, 0x7693);
    r16[ax] += 0x000c;
    r16[ax] <<= r8[cl];
    r16[ax] -= memoryAGet16(ds, 0x527e);
    if (r16[ax] < 0x0070)
        { pc = 0x1422a; break; }
  case 0x14205: // 1020:4005
    if (!memoryAGet(ds, 0x6521))
        { pc = 0x1423b; break; }
    if (memoryAGet16(ds, 0x6524) == r16[dx])
        { pc = 0x14236; break; }
    if (signed16(memoryAGet16(ds, 0x6524)) > r16s[dx])
        { pc = 0x14231; break; }
    r16[ax] = memoryAGet16(ds, 0x7693);
    r16[dx] = r16[ax];
    r16[dx] += 0x000c;
    r16[dx] <<= r8[cl];
    if (memoryAGet16(ds, 0x527e) > r16[dx])
        { pc = 0x1422a; break; }
    if (memoryAGet16(ds, 0x5272) > r16[ax])
        { pc = 0x14236; break; }
  case 0x1422a: // 1020:402a
    yield* sub_12b4c();
    if (flags.carry)
        { pc = 0x14236; break; }
    { pc = 0x1423b; break; }
  case 0x14231: // 1020:4031
    yield* sub_12b11();
    if (!flags.carry)
        { pc = 0x1423b; break; }
  case 0x14236: // 1020:4036
    memoryASet(ds, 0x6521, 0x00);
  case 0x1423b: // 1020:403b
    return;
  }
}
function* sub_1423c() // 1020:403c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[dx] = memoryAGet16(ds, 0x527c);
    r8[cl] = 0x04;
    r16[dx] = sar16(r16[dx], r8[cl]);
    r16[dx] -= memoryAGet16(ds, 0x5270);
    if (!memoryAGet(ds, 0x6520))
        { pc = 0x14257; break; }
    { pc = 0x142d7; break; }
  case 0x14257: // 1020:4057
    if (memoryAGet16(ds, 0x651e) < 0x0016)
        { pc = 0x142c6; break; }
    r8[al] = memoryAGet(ds, 0x5287);
    r8[al] &= 0x0f;
    if (r8[al] != 0x01)
        { pc = 0x142a1; break; }
    r16[ax] = memoryAGet16(ds, 0x5282);
    if (r16s[ax] >= 0)
        { pc = 0x14270; break; }
    r16[ax] = -r16[ax];
  case 0x14270: // 1020:4070
    if (r16[ax] == 0x0040)
        { pc = 0x1427e; break; }
    if (signed16(memoryAGet16(ds, 0x5280)) < signed16(0x0000))
        { pc = 0x1429c; break; }
    { pc = 0x1428a; break; }
  case 0x1427e: // 1020:407e
    if (signed16(memoryAGet16(ds, 0x5282)) < signed16(0x0000))
        { pc = 0x14297; break; }
    if (r16s[dx] < signed16(0x000d))
        { pc = 0x142d7; break; }
  case 0x1428a: // 1020:408a
    r16[ax] = 0x0002;
  case 0x1428d: // 1020:408d
    memoryASet16(ds, 0x6522, r16[ax]);
    memoryASet(ds, 0x6520, 0x01);
    { pc = 0x142d7; break; }
  case 0x14297: // 1020:4097
    if (r16s[dx] > signed16(0x0007))
        { pc = 0x142d7; break; }
  case 0x1429c: // 1020:409c
    r16[ax] = 0x0012;
    { pc = 0x1428d; break; }
  case 0x142a1: // 1020:40a1
    r16[ax] = memoryAGet16(ds, 0x5282);
    r16[ax] |= memoryAGet16(ds, 0x528a);
    if (r16[ax])
        { pc = 0x142c6; break; }
    if (memoryAGet16(ds, 0x651e) != 0x0021)
        { pc = 0x142c6; break; }
    yield* sub_142fa();
    memoryASet16(ds, 0x6522, r16[ax]);
    { pc = 0x142bf; break; }
  case 0x142b9: // 1020:40b9
    memoryASet16(ds, 0x6522, 0x000a);
  case 0x142bf: // 1020:40bf
    memoryASet(ds, 0x6520, 0x01);
    { pc = 0x142d7; break; }
  case 0x142c6: // 1020:40c6
    if (memoryAGet(ds, 0x6520))
        { pc = 0x142d7; break; }
    if (r16s[dx] > signed16(0x0012))
        { pc = 0x142b9; break; }
    if (r16s[dx] < signed16(0x0002))
        { pc = 0x142b9; break; }
  case 0x142d7: // 1020:40d7
    if (!memoryAGet(ds, 0x6520))
        { pc = 0x142f9; break; }
    if (memoryAGet16(ds, 0x6522) == r16[dx])
        { pc = 0x142f4; break; }
    if (signed16(memoryAGet16(ds, 0x6522)) > r16s[dx])
        { pc = 0x142ed; break; }
    yield* sub_12bb5();
    if (flags.carry)
        { pc = 0x142f4; break; }
    { pc = 0x142f9; break; }
  case 0x142ed: // 1020:40ed
    yield* sub_12b94();
    if (flags.carry)
        { pc = 0x142f4; break; }
    { pc = 0x142f9; break; }
  case 0x142f4: // 1020:40f4
    memoryASet(ds, 0x6520, 0x00);
  case 0x142f9: // 1020:40f9
    return;
  }
}
function* sub_142fa() // 1020:40fa
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[si]);
    r16[dx] = memoryAGet16(ds, 0x527c);
    r16[si] = 0x5570;
    r16[cx] = 0x0008;
    r16[ax] = 0x000a;
  case 0x1430b: // 1020:410b
    if (memoryAGet16(ds, r16[si] + 4) == 0xffff)
        { pc = 0x14333; break; }
    r16[bx] = 0;
    flags.carry = memoryAGet16(ds, r16[si]) < r16[dx];
    r8[bl] += (0x00 + flags.carry);
    r8[bh] = memoryAGet(ds, 0x5281);
    r8[bh] = rol8(r8[bh], 0x01);
    r8[bh] &= 0x01;
    r8[bl] ^= r8[bh];
    if (!r8[bl])
        { pc = 0x14333; break; }
    r16[bx] = memoryAGet16(ds, r16[si]);
    r16[bx] -= r16[dx];
    if (r16s[bx] >= 0)
        { pc = 0x1432d; break; }
    r16[bx] = -r16[bx];
  case 0x1432d: // 1020:412d
    if (r16[bx] < 0x00c8)
        { pc = 0x14346; break; }
  case 0x14333: // 1020:4133
    r16[si] += 0x0012;
    if (--r16[cx])
        { pc = 0x1430b; break; }
    r16[ax] = 0x0003;
    if (!(memoryAGet16(ds, 0x5281) & 0x0080))
        { pc = 0x14346; break; }
    r16[ax] = 0x0011;
  case 0x14346: // 1020:4146
    r16[si] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    return;
  }
}
function* sub_1434b() // 1020:414b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    if (memoryAGet(ds, 0x6516))
        { pc = 0x14371; break; }
    if (!memoryAGet(ds, 0x047b))
        { pc = 0x14371; break; }
    yield* sub_14fc0();
    memoryASet(ds, 0x6516, memoryAGet(ds, 0x6516) - 1);
    { pc = 0x1467a; break; }
  case 0x14371: // 1020:4171
    if (!memoryAGet(ds, 0x047c))
        { pc = 0x14387; break; }
    memoryASet(ds, 0x6517, 0x01);
  case 0x1437d: // 1020:417d
    yield* sync();
    if (!memoryAGet(ds, 0x047c))
        { pc = 0x1437d; break; }
    { pc = 0x1467a; break; }
  case 0x14387: // 1020:4187
    if (!memoryAGet(ds, 0x0452))
        { pc = 0x14393; break; }
    memoryASet(ds, 0x6506, 0x32);
  case 0x14393: // 1020:4193
    if (!memoryAGet(ds, 0x047e))
        { pc = 0x143ad; break; }
  case 0x1439a: // 1020:419a
    yield* sync();
    if (memoryAGet(ds, 0x047e))
        { pc = 0x1439a; break; }
    yield* sub_129df();
    yield* sub_103f8();
    yield* sub_105f2();
    yield* sub_105ae();
  case 0x143ad: // 1020:41ad
    yield* sub_11aaf();
    es = memoryAGet16(ds, 0x526c);
    r16[si] = 0x527c;
    yield* sub_14d49();
    yield* sub_10a05();
    r16[ax] = 0x550b;
    if (!memoryAGet(ds, 0x6513))
        { pc = 0x143ca; break; }
    { pc = 0x1448a; break; }
  case 0x143ca: // 1020:41ca
    r8[al] = 0x0c;
    r8[al] += memoryAGet(ds, 0x6501);
    if (!memoryAGet(ds, 0x6514))
        { pc = 0x143da; break; }
    { pc = 0x1448a; break; }
  case 0x143da: // 1020:41da
    memoryASet(ds, 0x6501, 0x00);
    r8[al] = 0xaa;
    if (!memoryAGet(ds, 0x042f))
        { pc = 0x143eb; break; }
    r16[ax] = 0x0101;
  case 0x143eb: // 1020:41eb
    if (!memoryAGet(ds, 0x0430))
        { pc = 0x143f5; break; }
    r16[ax] = 0xff01;
  case 0x143f5: // 1020:41f5
    if (!memoryAGet(ds, 0x650d))
        { pc = 0x14400; break; }
    r8[al] = 0x06;
    { pc = 0x14442; break; }
  case 0x14400: // 1020:4200
    if (memoryAGet(ds, 0x650e))
        { pc = 0x14415; break; }
    if (memoryAGet(ds, 0x650f) == 0x06)
        { pc = 0x14420; break; }
    if (!memoryAGet(ds, 0x042e))
        { pc = 0x14420; break; }
  case 0x14415: // 1020:4215
    if (r8[ah] == 0x55)
        { pc = 0x1441e; break; }
    r8[al] = 0x03;
    { pc = 0x14420; break; }
  case 0x1441e: // 1020:421e
    r8[al] = 0x05;
  case 0x14420: // 1020:4220
    if (memoryAGet(ds, 0x650e))
        { pc = 0x14442; break; }
    if (!memoryAGet(ds, 0x042d))
        { pc = 0x14442; break; }
    if (memoryAGet(ds, 0x650f))
        { pc = 0x14442; break; }
    r8[al] = 0x02;
    if (memoryAGet(ds, r16[si] + 11) != 0x05)
        { pc = 0x14442; break; }
    memoryASet(ds, 0x6512, 0x64);
  case 0x14442: // 1020:4242
    if (r8[al] != 0xaa)
        { pc = 0x14448; break; }
    r8[al] = 0;
  case 0x14448: // 1020:4248
    if (!memoryAGet(ds, 0x042b))
        { pc = 0x14480; break; }
    if (memoryAGet(ds, 0x650e))
        { pc = 0x14480; break; }
    if (memoryAGet(ds, 0x650a))
        { pc = 0x1448a; break; }
    if (r8[al] == 0x03)
        { pc = 0x14465; break; }
    if (r8[al] != 0x05)
        { pc = 0x1446e; break; }
  case 0x14465: // 1020:4265
    memoryASet(ds, 0x650b, 0x00);
    r8[al] = 0x07;
    { pc = 0x1448a; break; }
  case 0x1446e: // 1020:426e
    if (!memoryAGet(ds, 0x6509))
        { pc = 0x1448a; break; }
    if (!memoryAGet(ds, 0x650b))
        { pc = 0x1448a; break; }
    r8[al] = 0x08;
    { pc = 0x1448a; break; }
  case 0x14480: // 1020:4280
    memoryASet(ds, 0x650b, 0x01);
    memoryASet(ds, 0x650c, 0x00);
  case 0x1448a: // 1020:428a
    r8[al] += memoryAGet(ds, 0x6509);
    if (r8[ah] != 0x55)
        { pc = 0x14496; break; }
    r8[ah] = memoryAGet(ds, r16[si] + 10);
  case 0x14496: // 1020:4296
    r8[dl] = memoryAGet(ds, 0x0430);
    r8[dl] |= memoryAGet(ds, 0x042f);
    memoryASet(ds, 0x6507, r8[dl]);
    r8[dl] = memoryAGet(ds, 0x042d);
    r8[dl] |= memoryAGet(ds, 0x042e);
    memoryASet(ds, 0x6508, r8[dl]);
    r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    r8[dl] |= r8[ah];
    if (memoryAGet16(ds, r16[si] + 9) == r16[dx])
        { pc = 0x144c1; break; }
    memoryASet16(ds, r16[si] + 9, r16[dx]);
  case 0x144b9: // 1020:42b9
    memoryASet16(ds, 0x651e, 0x0001);
    { pc = 0x144e1; break; }
  case 0x144c1: // 1020:42c1
    if (r8[al] == 0x01)
        { pc = 0x144c9; break; }
    if (r8[al])
        { pc = 0x144d2; break; }
  case 0x144c9: // 1020:42c9
    if (!memoryAGet(ds, 0x6512))
        { pc = 0x144d2; break; }
    r8[al] += 0x09;
  case 0x144d2: // 1020:42d2
    if (memoryAGet(ds, r16[si] + 11) != r8[al])
        { pc = 0x144b9; break; }
    flags.carry = memoryAGet16(ds, 0x651e) + 0x0001 >= 0x10000;
    memoryASet16(ds, 0x651e, memoryAGet16(ds, 0x651e) + 0x0001);
    memoryASet16(ds, 0x651e, memoryAGet16(ds, 0x651e) - (0x0000 + flags.carry));
  case 0x144e1: // 1020:42e1
    cbw();
    r16[bx] = r16[ax];
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: yield* sub_1496c(); break;
        case 2: yield* sub_149fa(); break;
        case 4: yield* sub_14948(); break;
        case 6: yield* sub_149d3(); break;
        case 10: yield* sub_149b7(); break;
        case 12: yield* sub_14a33(); break;
        case 14: yield* sub_14b5b(); break;
        case 16: yield* sub_14ad6(); break;
        case 18: yield* sub_1496c(); break;
        case 20: yield* sub_14a07(); break;
        case 22: yield* sub_14a14(); break;
        case 24: yield* sub_14a26(); break;
        case 26: yield* sub_14a26(); break;
        case 32: yield* sub_1496c(); break;
        case 34: yield* sub_149fa(); break;
        case 36: yield* sub_14948(); break;
        case 38: yield* sub_149fa(); break;
        case 42: yield* sub_14acc(); break;
        case 44: yield* sub_14a33(); break;
        case 46: yield* sub_14b5b(); break;
        case 48: yield* sub_14ad6(); break;
        case 54: yield* sub_14a21(); break;
        case 56: yield* sub_14a26(); break;
        case 58: yield* sub_14a26(); break;
        default:
            stop("ind 1020:42e6");
    }
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    r8[cl] = 0x04;
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) + r16[ax]);
    if (signed16(memoryAGet16(ds, r16[si])) < signed16(0x0008))
        { pc = 0x144fe; break; }
    if (memoryAGet16(ds, r16[si]) < 0x0ff8)
        { pc = 0x14500; break; }
  case 0x144fe: // 1020:42fe
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
  case 0x14500: // 1020:4300
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    r8[cl] = 0x04;
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    yield* sub_14684();
    r8[al] = memoryAGet(ds, 0x650a);
    if (!r8[al])
        { pc = 0x14578; break; }
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, 0x5294);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[ax] += memoryAGet16(ds, 0x528e);
    if (r16[ax] >= 0x1000)
        { pc = 0x1456b; break; }
    r16[bx] = memoryAGet16(ds, 0x5270);
    r16[bx] <<= r8[cl];
    r16[bx] -= 0x0028;
    if (r16s[bx] > r16s[ax])
        { pc = 0x1456b; break; }
    r16[bx] += 0x0190;
    if (r16s[bx] < r16s[ax])
        { pc = 0x1456b; break; }
    memoryASet16(ds, 0x528e, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x529c);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[ax] += memoryAGet16(ds, 0x5290);
    r8[bl] = memoryAGet(ds, 0x508b);
    r8[bh] = 0;
    r16[bx] <<= r8[cl];
    if (r16[ax] >= r16[bx])
        { pc = 0x1456b; break; }
    r16[bx] = memoryAGet16(ds, 0x5272);
    r16[bx] <<= r8[cl];
    r16[bx] -= 0x0014;
    if (r16s[bx] > r16s[ax])
        { pc = 0x1456b; break; }
    r16[bx] += 0x00e8;
    if (r16s[bx] < r16s[ax])
        { pc = 0x1456b; break; }
    memoryASet16(ds, 0x5290, r16[ax]);
    { pc = 0x14576; break; }
  case 0x1456b: // 1020:436b
    memoryASet16(ds, 0x5292, 0xffff);
    memoryASet(ds, 0x650a, 0x00);
  case 0x14576: // 1020:4376
    { pc = 0x145ea; break; }
  case 0x14578: // 1020:4378
    if (!memoryAGet(ds, 0x6509))
        { pc = 0x145ea; break; }
    r16[bx] = memoryAGet16(ds, 0x5280);
    r16[dx] = r16[bx];
    r8[dh] &= 0x1f;
    r8[al] = memoryAGet(ds, 0x5287);
    if (memoryAGet(ds, 0x650d))
        { pc = 0x145ab; break; }
    if (r8[al] == 0x15)
        { pc = 0x1459a; break; }
    if (r8[al] != 0x17)
        { pc = 0x145ab; break; }
  case 0x1459a: // 1020:439a
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= 0x0004;
    memoryASet16(ds, 0x5290, r16[ax]);
    yield* sub_15322();
    memoryASet16(ds, 0x528e, r16[ax]);
    { pc = 0x145ea; break; }
  case 0x145ab: // 1020:43ab
    r8[al] &= 0x0f;
    if (r16[dx] == 0x000e)
        { pc = 0x145ba; break; }
    if (r8[al] == 0x07)
        { pc = 0x145ea; break; }
    if (r8[al] == 0x08)
        { pc = 0x145ea; break; }
  case 0x145ba: // 1020:43ba
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax]++;
    r16[ax]++;
    flags.carry = r16[dx] < 0x0017;
    r16[dx] -= 0x0017;
    if (flags.carry)
        { pc = 0x145d4; break; }
    if (r16[dx] > 0x0001)
        { pc = 0x145d4; break; }
    r16[ax] -= 0x000a;
    if (!(r8[bh] & 0x80))
        { pc = 0x145d4; break; }
    r16[ax] += 0x0012;
  case 0x145d4: // 1020:43d4
    r8[bh] &= 0x1f;
    memoryASet16(ds, 0x528e, r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[bx] <<= 1;
    flags.carry = r8[al] < memoryAGet(ds, r16[bx] + 27640);
    r8[al] -= memoryAGet(ds, r16[bx] + 27640);
    r8[ah] -= (0x00 + flags.carry);
    r16[ax]++;
    memoryASet16(ds, 0x5290, r16[ax]);
  case 0x145ea: // 1020:43ea
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x145fd; break; }
    memoryASet(ds, 0x6515, memoryAGet(ds, 0x6515) - 1);
    if (memoryAGet(ds, 0x6515))
        { pc = 0x145fd; break; }
    memoryASet16(ds, 0x5292, 0xffff);
  case 0x145fd: // 1020:43fd
    r16[dx] = 0x0001;
    flags.carry = memoryAGet(ds, 0x651b) < r8[dl];
    memoryASet(ds, 0x651b, memoryAGet(ds, 0x651b) - r8[dl]);
    memoryASet(ds, 0x651b, memoryAGet(ds, 0x651b) + (r8[dh] + flags.carry));
    flags.carry = memoryAGet(ds, 0x6516) < r8[dl];
    memoryASet(ds, 0x6516, memoryAGet(ds, 0x6516) - r8[dl]);
    memoryASet(ds, 0x6516, memoryAGet(ds, 0x6516) + (r8[dh] + flags.carry));
    flags.carry = memoryAGet(ds, 0x6504) < r8[dl];
    memoryASet(ds, 0x6504, memoryAGet(ds, 0x6504) - r8[dl]);
    memoryASet(ds, 0x6504, memoryAGet(ds, 0x6504) + (r8[dh] + flags.carry));
    flags.carry = memoryAGet(ds, 0x6510) < r8[dl];
    memoryASet(ds, 0x6510, memoryAGet(ds, 0x6510) - r8[dl]);
    memoryASet(ds, 0x6510, memoryAGet(ds, 0x6510) + (r8[dh] + flags.carry));
    flags.carry = memoryAGet(ds, 0x6511) < r8[dl];
    memoryASet(ds, 0x6511, memoryAGet(ds, 0x6511) - r8[dl]);
    memoryASet(ds, 0x6511, memoryAGet(ds, 0x6511) + (r8[dh] + flags.carry));
    flags.carry = memoryAGet(ds, 0x6512) < r8[dl];
    memoryASet(ds, 0x6512, memoryAGet(ds, 0x6512) - r8[dl]);
    memoryASet(ds, 0x6512, memoryAGet(ds, 0x6512) + (r8[dh] + flags.carry));
    flags.carry = memoryAGet(ds, 0x6514) < r8[dl];
    memoryASet(ds, 0x6514, memoryAGet(ds, 0x6514) - r8[dl]);
    memoryASet(ds, 0x6514, memoryAGet(ds, 0x6514) + (r8[dh] + flags.carry));
    if (memoryAGet16(ds, 0x528a))
        { pc = 0x14647; break; }
    flags.carry = memoryAGet(ds, 0x6513) < r8[dl];
    memoryASet(ds, 0x6513, memoryAGet(ds, 0x6513) - r8[dl]);
    memoryASet(ds, 0x6513, memoryAGet(ds, 0x6513) + (r8[dh] + flags.carry));
  case 0x14647: // 1020:4447
    r16[ax] = memoryAGet16(ds, 0x5282);
    r16[ax] |= memoryAGet16(ds, 0x528a);
    if (r16[ax])
        { pc = 0x14654; break; }
    memoryASet(ds, 0x6514, r8[dh]);
  case 0x14654: // 1020:4454
    flags.carry = memoryAGet(ds, 0x6505) < r8[dl];
    memoryASet(ds, 0x6505, memoryAGet(ds, 0x6505) - r8[dl]);
    memoryASet(ds, 0x6505, memoryAGet(ds, 0x6505) + (r8[dh] + flags.carry));
    if (!memoryAGet(ds, 0x6505))
        { pc = 0x1467a; break; }
    if (memoryAGet(ds, 0x6505) & 0x03)
        { pc = 0x1467a; break; }
    memoryASet16(ds, 0x5292, memoryAGet16(ds, 0x5292) + 1);
    if (memoryAGet(ds, 0x5292) != 0x31)
        { pc = 0x1467a; break; }
    memoryASet16(ds, 0x5292, 0xffff);
    memoryASet(ds, 0x6505, r8[dh]);
  case 0x1467a: // 1020:447a
    r16[bp] = pop();
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
}
function* sub_14684() // 1020:4484
{
  var pc = 0;
  var temp_cond0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    r16[si] = 0x527c;
    r16[ax] = memoryAGet16(ds, 0x527e);
    r8[cl] = 0x04;
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[ax]--;
    r8[tl] = r8[al]; r8[al] = r8[ah]; r8[ah] = r8[tl];
    r16[bx] = memoryAGet16(ds, 0x5280);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[dh] = memoryAGet(ds, r16[bx] + 27640);
    r16[bx] = 0x0008;
    if (signed16(memoryAGet16(ds, 0x5282)) > signed16(0x0000))
        { pc = 0x146b1; break; }
    if (signed16(memoryAGet16(ds, 0x5282)) < signed16(0x0000))
        { pc = 0x146af; break; }
    r16[bx] = 0;
  case 0x146af: // 1020:44af
    r16[bx] = -r16[bx];
  case 0x146b1: // 1020:44b1
    push(r16[ax]);
    push(r16[bx]);
    r16[bx] = memoryAGet16(ds, 0x527c);
    r16[bx] = sar16(r16[bx], r8[cl]);
    r16[bx] += r16[ax];
    if (signed16(memoryAGet16(ds, 0x527e)) <= signed16(0x0000))
        { pc = 0x146d9; break; }
    r8[al] = memoryAGet(ds, 0x508b);
    r8[ah] = 0;
    r16[ax]++;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    if (signed16(memoryAGet16(ds, 0x527e)) <= r16s[ax])
        { pc = 0x146d9; break; }
    yield* sub_14fc0();
  case 0x146d9: // 1020:44d9
    memoryASet(ds, 0x6526, 0x00);
    r8[al] = memoryAGet(ds, 0x527c);
    r8[al] &= 0x0f;
    flags.carry = r8[al] < 0x04;
    r8[al] -= 0x04;
    r16[bx] -= (0x0000 + flags.carry);
    r16[bp] = r16[bx];
    yield* sub_14761();
    if (memoryAGet(ds, 0x6526) != 0x01)
        { pc = 0x14739; break; }
    flags.carry = r8[al] + 0x08 >= 0x100;
    r8[al] += 0x08;
    r16[bx] += (0x0000 + flags.carry);
    flags.carry = r8[al] < 0x0f;
    flags.carry = !flags.carry;
    r16[bx] += (0x0000 + flags.carry);
    if (r16[bx] == r16[bp])
        { pc = 0x14706; break; }
    yield* sub_14761();
  case 0x14706: // 1020:4506
    if (memoryAGet(ds, 0x6526) != 0x01)
        { pc = 0x14739; break; }
    if (memoryAGet(ds, 0x6510))
        { pc = 0x14736; break; }
    if (memoryAGet(ds, 0x6513))
        { pc = 0x14736; break; }
    yield* sub_14857();
    if (memoryAGet(ds, 0x6526) != 0x01)
        { pc = 0x14739; break; }
    yield* sub_1511f();
    if (memoryAGet(ds, 0x6526) == 0x01)
        { pc = 0x14736; break; }
    memoryASet(ds, 0x5284, 0x00);
    { pc = 0x14739; break; }
  case 0x14736: // 1020:4536
    yield* sub_14e65();
  case 0x14739: // 1020:4539
    r16[bx] = pop();
    r16[ax] = pop();
    if (signed16(memoryAGet16(ds, 0x527e)) <= signed16(0x0000))
        { pc = 0x1475d; break; }
    r16[bx] += memoryAGet16(ds, 0x527c);
    r16[bx] = sar16(r16[bx], r8[cl]);
    r16[bx] += r16[ax];
    yield* sub_14817();
    { pc = 0x14752; break; }
  case 0x1474f: // 1020:454f
    yield* sub_14831();
  case 0x14752: // 1020:4552
    flags.carry = r16[bx] < 0x0100;
    r16[bx] -= 0x0100;
    if (flags.carry)
        { pc = 0x1475d; break; }
    temp_cond0 = r8[dh] > 0x10;
    r8[dh] -= 0x10;
    if (temp_cond0)
        { pc = 0x1474f; break; }
  case 0x1475d: // 1020:455d
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_14761() // 1020:4561
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[bp]);
    memoryASet(ds, 0x651c, 0x00);
    memoryASet(ds, 0x650e, 0x00);
    memoryASet(ds, 0x650d, 0x00);
    if (signed16(memoryAGet16(ds, 0x527e)) > signed16(0xffff))
        { pc = 0x14785; break; }
    yield* sub_14e65();
    memoryASet(ds, 0x6526, 0xff);
    { pc = 0x14813; break; }
  case 0x14785: // 1020:4585
    r8[al] = memoryAGet(ds, 0x5287);
    r8[al] &= 0x0f;
    if (r8[al] == 0x02)
        { pc = 0x147a5; break; }
    push(r16[bx]);
    r16[di] = r16[bx] + 256;
    r8[al] = memoryAGet(es, r16[di]);
    r16[bx] = 0x73a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[ah] = 0;
    r16[bx] = r16[ax];
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: yield* sub_14ff9(); break;
        case 2: yield* sub_14ffd(); break;
        case 4: yield* sub_15013(); break;
        case 6: yield* sub_1501c(); break;
        case 8: yield* sub_15025(); break;
        case 10: yield* sub_15001(); break;
        case 12: yield* sub_1502e(); break;
        case 14: yield* sub_14f10(); break;
        case 16: yield* sub_14fc0(); break;
        case 18: yield* sub_14fc0(); break;
        case 20: yield* sub_14fc0(); break;
        case 22: yield* sub_14fb1(); break;
        case 24: yield* sub_14fc9(); break;
        case 26: yield* sub_14f9a(); break;
        case 28: yield* sub_15087(); break;
        case 30: yield* sub_15088(); break;
        case 32: yield* sub_15103(); break;
        case 34: yield* sub_14fc9(); break;
        case 36: yield* sub_14fc0(); break;
        default:
            stop("ind 1020:45a0");
    }
    r16[bx] = pop();
  case 0x147a5: // 1020:45a5
    flags.carry = r16[bx] < 0x0100;
    r16[bx] -= 0x0100;
    if (flags.carry)
        { pc = 0x14813; break; }
    if (signed16(memoryAGet16(ds, 0x528a)) > signed16(0x0000))
        { pc = 0x14813; break; }
    r16[di] = r16[bx];
    r8[ah] = memoryAGet(es, r16[bx]);
    r8[al] = memoryAGet(es, r16[bx] + 256);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[tl] = r8[al]; r8[al] = r8[ah]; r8[ah] = r8[tl];
    r16[bx] = 0x74a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x7f;
    r8[bl] = r8[al];
    r8[bh] = 0;
    r16[bx] <<= 1;
    push(r16[ax]);
    switch (r16[bx])
    {
        case 0: yield* sub_15087(); break;
        case 2: yield* sub_15088(); break;
        case 4: yield* sub_15103(); break;
        case 6: yield* sub_14fc9(); break;
        case 8: yield* sub_14fc0(); break;
        default:
            stop("ind 1020:45cf");
    }
    r16[ax] = pop();
    r8[ah] &= 0x01;
    if (!r8[ah])
        { pc = 0x14813; break; }
    if (signed16(memoryAGet16(ds, 0x527e)) <= signed16(0x0000))
        { pc = 0x14813; break; }
    r16[dx] = 0xffff;
    r16[bx] = 0x72a3;
    if (signed16(memoryAGet16(ds, 0x5282)) > signed16(0x0000))
        { pc = 0x147ef; break; }
    r16[dx] = -r16[dx];
  case 0x147ef: // 1020:45ef
    push(r16[di]);
    r16[di] += r16[dx];
    r8[al] = memoryAGet(es, r16[di] + 256);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    if (!r8[al])
        { pc = 0x1480c; break; }
    r16[dx] = -r16[dx];
    r16[di] += r16[dx];
    r16[di] += r16[dx];
    r8[al] = memoryAGet(es, r16[di] + 256);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    if (r8[al])
        { pc = 0x14812; break; }
  case 0x1480c: // 1020:460c
    r16[dx] <<= 1;
    memoryASet16(ds, 0x527c, memoryAGet16(ds, 0x527c) + r16[dx]);
  case 0x14812: // 1020:4612
    r16[di] = pop();
  case 0x14813: // 1020:4613
    r16[bp] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_14817() // 1020:4617
{
    push(r16[bx]);
    push(r16[dx]);
    push(r16[di]);
    r16[di] = r16[bx];
    r8[al] = memoryAGet(es, r16[bx]);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[ah] = 0;
    r16[bx] = r16[ax];
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: yield* sub_14f0b(); break;
        case 2: yield* sub_14f0c(); break;
        case 4: yield* sub_14f10(); break;
        case 6: yield* sub_14fc0(); break;
        case 8: yield* sub_14fb1(); break;
        case 10: yield* sub_14fc9(); break;
        case 12: yield* sub_14f9a(); break;
        case 14: yield* sub_14ff9(); break;
        case 16: yield* sub_14ffd(); break;
        case 18: yield* sub_15013(); break;
        case 20: yield* sub_1501c(); break;
        case 22: yield* sub_15025(); break;
        case 24: yield* sub_15001(); break;
        case 26: yield* sub_1502e(); break;
        default:
            stop("ind 1020:4629");
    }
    r16[di] = pop();
    r16[dx] = pop();
    r16[bx] = pop();
}
function* sub_14831() // 1020:4631
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[bx]);
    push(r16[dx]);
    push(r16[di]);
    r16[di] = r16[bx];
    r8[al] = memoryAGet(es, r16[bx]);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    if (r8[al] == 0x04)
        { pc = 0x14845; break; }
    if (r8[al] != 0x02)
        { pc = 0x1484f; break; }
  case 0x14845: // 1020:4645
    r8[ah] = 0;
    r16[bx] = r16[ax];
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: yield* sub_14f0b(); break;
        case 2: yield* sub_14f0c(); break;
        case 4: yield* sub_14f10(); break;
        case 6: yield* sub_14fc0(); break;
        case 8: yield* sub_14fb1(); break;
        case 10: yield* sub_14fc9(); break;
        case 12: yield* sub_14f9a(); break;
        case 14: yield* sub_14ff9(); break;
        case 16: yield* sub_14ffd(); break;
        case 18: yield* sub_15013(); break;
        case 20: yield* sub_1501c(); break;
        case 22: yield* sub_15025(); break;
        case 24: yield* sub_15001(); break;
        case 26: yield* sub_1502e(); break;
        case 28: yield* sub_14f10(); break;
        case 30: yield* sub_14fc0(); break;
        case 32: yield* sub_14fc0(); break;
        case 34: yield* sub_14fc0(); break;
        case 36: yield* sub_14fb1(); break;
        case 38: yield* sub_14fc9(); break;
        case 40: yield* sub_14f9a(); break;
        case 42: yield* sub_15087(); break;
        case 44: yield* sub_15088(); break;
        case 46: yield* sub_15103(); break;
        case 48: yield* sub_14fc9(); break;
        case 50: yield* sub_14fc0(); break;
        default:
            stop("ind 1020:464b");
    }
  case 0x1484f: // 1020:464f
    r16[di] = pop();
    r16[dx] = pop();
    r16[bx] = pop();
    return;
  }
}
function* sub_14857() // 1020:4657
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x14857; break; }
  case 0x14853: // 1020:4653
    return;
  case 0x14854: // 1020:4654
    { pc = 0x14935; break; }
  case 0x14857: // 1020:4657
    if (signed16(memoryAGet16(ds, 0x528a)) < signed16(0x0000))
        { pc = 0x14853; break; }
    if (memoryAGet(ds, 0x6510))
        { pc = 0x14853; break; }
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[si] = 0x5648;
    r16[cx] = 0x0004;
  case 0x14874: // 1020:4674
    if (memoryAGet16(ds, r16[si] + 4) == 0xffff)
        { pc = 0x14854; break; }
    if (!(memoryAGet(ds, r16[si] + 5) & 0x20))
        { pc = 0x14854; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, 0x527c);
    if (r16s[ax] >= 0)
        { pc = 0x1488a; break; }
    r16[ax] = -r16[ax];
  case 0x1488a: // 1020:468a
    if (r16[ax] >= 0x0040)
        { pc = 0x14854; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= memoryAGet16(ds, 0x527e);
    if (r16s[ax] >= 0)
        { pc = 0x1489a; break; }
    r16[ax] = -r16[ax];
  case 0x1489a: // 1020:469a
    if (r16[ax] >= 0x0010)
        { pc = 0x14854; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[dx] = memoryAGet16(ds, 0x527c);
    flags.carry = r8[dl] < memoryAGet(ds, 0x692f);
    r8[dl] -= memoryAGet(ds, 0x692f);
    r8[dh] -= (0x00 + flags.carry);
    r8[bl] = memoryAGet(ds, 0x6bf7);
    if (r16s[dx] < r16s[ax])
        { pc = 0x148c1; break; }
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[bl] = memoryAGet(ds, r16[bx] + 27639);
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
  case 0x148c1: // 1020:46c1
    r8[bh] = 0;
    r16[dx] += r16[bx];
    if (r16s[dx] <= r16s[ax])
        { pc = 0x14935; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[dx] = memoryAGet16(ds, 0x527e);
    flags.carry = r8[dl] < 0x06;
    r8[dl] -= 0x06;
    r8[dh] -= (0x00 + flags.carry);
    r8[bl] = 0x08;
    if (r16s[dx] < r16s[ax])
        { pc = 0x148e9; break; }
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[bl] = memoryAGet(ds, r16[bx] + 27640);
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
  case 0x148e9: // 1020:46e9
    r8[bh] = 0;
    r16[dx] += r16[bx];
    if (r16s[dx] <= r16s[ax])
        { pc = 0x14935; break; }
    if (memoryAGet16(ds, 0x651e) != 0x000e)
        { pc = 0x148fe; break; }
    memoryASet16(ds, 0x651e, 0x0010);
  case 0x148fe: // 1020:46fe
    memoryASet(ds, 0x6526, 0x00);
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    memoryASet16(ds, 0x527e, r16[ax]);
    yield* sub_14ef0();
    r16[bx] = memoryAGet16(ds, r16[si] + 9);
    r8[al] = memoryAGet(ds, r16[bx] + 7);
    cbw();
    r8[dl] = memoryAGet(ds, r16[bx] + 6);
    if (r8[dl] == 0x01)
        { pc = 0x1492f; break; }
    if (r8[dl] == 0x02)
        { pc = 0x14929; break; }
    r16[ax] = -r16[ax];
    if (r8[dl] == 0x03)
        { pc = 0x1492f; break; }
    { pc = 0x1493e; break; }
  case 0x14929: // 1020:4729
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) + r16[ax]);
    { pc = 0x1493e; break; }
  case 0x1492f: // 1020:472f
    memoryASet16(ds, 0x527c, memoryAGet16(ds, 0x527c) + r16[ax]);
    { pc = 0x1493e; break; }
  case 0x14935: // 1020:4735
    r16[si] += 0x0012;
    r16[cx]--;
    if (!r16[cx])
        { pc = 0x1493e; break; }
    { pc = 0x14874; break; }
  case 0x1493e: // 1020:473e
    r16[bp] = pop();
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
}
function* sub_14948() // 1020:4748
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(ds, 0x651d) < 0x03)
        { pc = 0x14955; break; }
    memoryASet(ds, 0x650f, 0x06);
    return;
  case 0x14955: // 1020:4755
    memoryASet(ds, 0x651d, memoryAGet(ds, 0x651d) + 1);
    r16[bp] = 0x0030;
    yield* sub_14db6();
    r16[bp] = 0x0040;
    yield* sub_14d7d();
    yield* sub_14e12();
    yield* sub_14e2a();
    return;
  }
}
function* sub_1496c() // 1020:476c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[dx]);
    memoryASet(ds, 0x5287, r8[al]);
    yield* sub_14de8();
    if (r16s[ax] >= 0)
        { pc = 0x1497b; break; }
    r16[ax] = -r16[ax];
  case 0x1497b: // 1020:477b
    if (r16[ax] < 0x0010)
        { pc = 0x1499d; break; }
    r8[al] = memoryAGet(ds, 0x5281);
    r8[ah] = memoryAGet(ds, 0x5283);
    r8[al] = rol8(r8[al], 0x01);
    r8[ah] = rol8(r8[ah], 0x01);
    r16[ax] &= 0x0101;
    if (r8[al] != r8[ah])
        { pc = 0x1499d; break; }
    r8[bl] = memoryAGet(ds, 0x6509);
    r8[bh] = 0;
    r16[bx] += 0x0004;
    r16[bx] <<= 1;
  case 0x1499d: // 1020:479d
    r16[bx] = memoryAGet16(ds, r16[bx] + 28351);
    memoryASet16(ds, 0x5288, r16[bx]);
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r8[dh] = memoryAGet(ds, 0x5285);
    r8[dh] &= 0x80;
    r8[ah] |= r8[dh];
    memoryASet16(ds, 0x5280, r16[ax]);
    r16[dx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_149b7() // 1020:47b7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_14e12();
    yield* sub_14e2a();
    yield* sub_14de8();
    if (memoryAGet16(ds, 0x651e) != 0x000f)
        { pc = 0x149d2; break; }
    memoryASet(ds, 0x6510, 0x06);
    memoryASet16(ds, 0x528a, 0x0000);
  case 0x149d2: // 1020:47d2
    return;
  }
}
function* sub_149d3() // 1020:47d3
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_14e12();
    yield* sub_14e2a();
    r16[bp] = 0x0020;
    yield* sub_14d7d();
    r16[ax] = memoryAGet16(ds, 0x5282);
    if (r16s[ax] >= 0)
        { pc = 0x149e8; break; }
    r16[ax] = -r16[ax];
  case 0x149e8: // 1020:47e8
    if (r16[ax] >= 0x0020)
        { pc = 0x149f9; break; }
    r8[al] = 0x06;
    r8[ah] = memoryAGet(ds, 0x5285);
    r8[ah] &= 0x80;
    memoryASet16(ds, 0x5280, r16[ax]);
  case 0x149f9: // 1020:47f9
    return;
  }
}
function* sub_149fa() // 1020:47fa
{
    r16[bp] = 0x0040;
    yield* sub_14d7d();
    yield* sub_14e12();
    yield* sub_14e2a();
}
function* sub_14a07() // 1020:4807
{
    r16[bp] = 0x0030;
    yield* sub_14d7d();
    yield* sub_14e12();
    yield* sub_14e2a();
}
function* sub_14a14() // 1020:4814
{
    memoryASet16(ds, 0x5282, 0x0000);
    yield* sub_14e12();
    yield* sub_14e2a();
}
function* sub_14a21() // 1020:4821
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x14a21; break; }
  case 0x14a14: // 1020:4814
    memoryASet16(ds, 0x5282, 0x0000);
    yield* sub_14e12();
    yield* sub_14e2a();
    return;
  case 0x14a21: // 1020:4821
    yield* sub_14ce9();
    { pc = 0x14a14; break; }
    return;
  }
}
function* sub_14a26() // 1020:4826
{
    r16[bp] = 0x00c0;
    yield* sub_14dd0();
    yield* sub_14e12();
    yield* sub_14e2a();
}
function* sub_14a33() // 1020:4833
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (!memoryAGet(ds, 0x6507))
        { pc = 0x14a42; break; }
    r16[bp] = 0x0040;
    yield* sub_14d7d();
    { pc = 0x14a45; break; }
  case 0x14a42: // 1020:4842
    yield* sub_14de8();
  case 0x14a45: // 1020:4845
    if (memoryAGet16(ds, 0x651e) > 0x0001)
        { pc = 0x14a5c; break; }
    r16[ax] = 0x000c;
    if (!memoryAGet(ds, 0x6509))
        { pc = 0x14a59; break; }
    r16[ax] = 0x0017;
  case 0x14a59: // 1020:4859
    memoryASet16(ds, 0x5280, r16[ax]);
  case 0x14a5c: // 1020:485c
    r16[ax] = 0;
    if (memoryAGet(ds, 0x6508) == r8[al])
        { pc = 0x14ac8; break; }
    r8[al] = 0x06;
    r8[al] += memoryAGet(ds, 0x6509);
    cbw();
    r16[bx] = r16[ax];
    r16[bx] <<= 1;
    yield* sub_14e12();
    yield* sub_14e2a();
    memoryASet(ds, 0x527c, memoryAGet(ds, 0x527c) & 0xf0);
    memoryASet(ds, 0x527c, memoryAGet(ds, 0x527c) + 0x08);
    r16[bx] = 0x73a3;
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, 0x527e);
    r8[al] &= 0xf0;
    r16[ax] <<= r8[cl];
    r16[di] = memoryAGet16(ds, 0x527c);
    r16[di] = sar16(r16[di], r8[cl]);
    r16[di] += r16[ax];
    es = memoryAGet16(ds, 0x526c);
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    if (r8[al] == 0x06)
        { pc = 0x14abc; break; }
    r16[dx] = 0xfff0;
    r8[al] = memoryAGet(es, r16[di] - 1);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    if (r8[al] == 0x06)
        { pc = 0x14ab8; break; }
    r16[dx] = -r16[dx];
    r8[al] = memoryAGet(es, r16[di] + 1);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    if (r8[al] == 0x06)
        { pc = 0x14ab8; break; }
    r16[dx] = 0;
  case 0x14ab8: // 1020:48b8
    memoryASet16(ds, 0x527c, memoryAGet16(ds, 0x527c) + r16[dx]);
  case 0x14abc: // 1020:48bc
    r16[ax] = 0x0040;
    if (!memoryAGet(ds, 0x042d))
        { pc = 0x14ac8; break; }
    r16[ax] = -r16[ax];
  case 0x14ac8: // 1020:48c8
    memoryASet16(ds, 0x528a, r16[ax]);
    return;
  }
}
function* sub_14acc() // 1020:48cc
{
    yield* sub_14e12();
    yield* sub_14e2a();
    yield* sub_14de8();
}
function* sub_14ad6() // 1020:48d6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_14e12();
    yield* sub_14e2a();
    yield* sub_14de8();
    if (!memoryAGet(ds, 0x6509))
        { pc = 0x14b5a; break; }
    r16[ax] = 0;
    r16[dx] = 0xff60;
    if (memoryAGet(ds, 0x042d))
        { pc = 0x14b0a; break; }
    r16[dx] = 0xff20;
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    if (memoryAGet(ds, 0x5281) & 0x80)
        { pc = 0x14aff; break; }
    r16[ax] = -r16[ax];
  case 0x14aff: // 1020:48ff
    r16[bx] = memoryAGet16(ds, 0x527e);
    r16[bx] -= 0x0010;
    memoryASet16(ds, 0x5290, r16[bx]);
  case 0x14b0a: // 1020:490a
    if (r16[dx])
        { pc = 0x14b21; break; }
    r16[bx] = memoryAGet16(ds, 0x5292);
    r8[bh] &= 0x1f;
    if (r16[bx] >= 0x0065)
        { pc = 0x14b38; break; }
    if (!(memoryAGet(ds, r16[bx] + 28441) & 0x04))
        { pc = 0x14b38; break; }
  case 0x14b21: // 1020:4921
    yield* sub_14ce9();
    r16[bx] = memoryAGet16(ds, 0x64e9);
    memoryASet16(ds, r16[bx] + 14, r16[dx]);
    r16[dx] = r16[ax];
    r16[dx] = sar16(r16[dx], 0x0001);
    r16[dx] = sar16(r16[dx], 0x0001);
    r16[ax] -= r16[dx];
    memoryASet16(ds, r16[bx] + 6, r16[ax]);
    { pc = 0x14b49; break; }
  case 0x14b38: // 1020:4938
    memoryASet(ds, 0x650a, 0x01);
    memoryASet16(ds, 0x5294, r16[ax]);
    memoryASet16(ds, 0x529c, r16[dx]);
    r8[al] = 0x03;
    yield* sub_113e6();
  case 0x14b49: // 1020:4949
    r8[al] = 0x0a;
    r8[ah] = memoryAGet(ds, 0x5285);
    r8[ah] &= 0x80;
    memoryASet16(ds, 0x5280, r16[ax]);
    memoryASet(ds, 0x6509, 0x00);
  case 0x14b5a: // 1020:495a
    return;
  }
}
function* sub_14b5b() // 1020:495b
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    yield* sub_14e12();
    yield* sub_14e2a();
    yield* sub_14de8();
    if (memoryAGet(ds, 0x650c))
        { pc = 0x14baf; break; }
    if (memoryAGet16(ds, 0x651e) != 0x0001)
        { pc = 0x14bb2; break; }
    if (!memoryAGet(ds, 0x6509))
        { pc = 0x14bb2; break; }
    yield* sub_14ce9();
    r16[bx] = memoryAGet16(ds, 0x64e9);
    r16[ax] = memoryAGet16(ds, r16[bx] + 2);
    r8[cl] = 0x04;
    r16[ax] = sar16(r16[ax], r8[cl]);
    r8[tl] = r8[al]; r8[al] = r8[ah]; r8[ah] = r8[tl];
    r16[di] = r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[di] += r16[ax];
    r16[ax] = memoryAGet16(es, r16[di]);
    r16[bx] = 0x73a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x07;
    if (!r8[al])
        { pc = 0x14baf; break; }
    r16[dx] = 0xffd0;
    r8[al] = r8[ah];
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x07;
    if (!r8[al])
        { pc = 0x14ba8; break; }
    r16[dx] = -r16[dx];
  case 0x14ba8: // 1020:49a8
    r16[bx] = memoryAGet16(ds, 0x64e9);
    memoryASet16(ds, r16[bx] + 6, r16[dx]);
  case 0x14baf: // 1020:49af
    { pc = 0x14ce3; break; }
  case 0x14bb2: // 1020:49b2
    if (!memoryAGet(ds, 0x6509))
        { pc = 0x14bbc; break; }
    { pc = 0x14cc1; break; }
  case 0x14bbc: // 1020:49bc
    r16[di] = 0x52a0;
    r16[cx] = 0x0030;
    r16[bx] = memoryAGet16(ds, 0x527e);
    r16[dx] = memoryAGet16(ds, 0x527c);
  case 0x14bca: // 1020:49ca
    if (memoryAGet16(ds, r16[di] + 4) != 0xffff)
        { pc = 0x14bd3; break; }
    { pc = 0x14cda; break; }
  case 0x14bd3: // 1020:49d3
    r16[ax] = r16[bx];
    r16[ax] -= memoryAGet16(ds, r16[di] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x14bdc; break; }
    r16[ax] = -r16[ax];
  case 0x14bdc: // 1020:49dc
    if (r16[ax] < 0x0014)
        { pc = 0x14be4; break; }
    { pc = 0x14cda; break; }
  case 0x14be4: // 1020:49e4
    r16[ax] = r16[dx];
    r16[ax] -= memoryAGet16(ds, r16[di]);
    if (memoryAGet(ds, 0x5281) & 0x80)
        { pc = 0x14bf1; break; }
    r16[ax] = -r16[ax];
  case 0x14bf1: // 1020:49f1
    if (r16[ax] < 0x0014)
        { pc = 0x14bf9; break; }
    { pc = 0x14cda; break; }
  case 0x14bf9: // 1020:49f9
    if (r16[cx] > 0x0008)
        { pc = 0x14c11; break; }
    r16[bx] = memoryAGet16(ds, r16[di] + 4);
    r8[bh] &= 0x1f;
    r8[al] = memoryAGet(ds, r16[bx] + 28538);
    r8[al] &= 0x0f;
    if (r8[al] != 0x0f)
        { pc = 0x14c11; break; }
    { pc = 0x14cd2; break; }
  case 0x14c11: // 1020:4a11
    r16[bx] = memoryAGet16(ds, r16[di] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[bl] = memoryAGet(ds, r16[bx] + 27639);
    r16[ax] = memoryAGet16(ds, 0x527c);
    if (r16s[ax] <= r16s[dx])
        { pc = 0x14c27; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r8[bl] = 0x20;
  case 0x14c27: // 1020:4a27
    r8[bh] = 0;
    r16[ax] += r16[bx];
    if (r16s[ax] >= r16s[dx])
        { pc = 0x14c32; break; }
    { pc = 0x14cd2; break; }
  case 0x14c32: // 1020:4a32
    r16[ax] = memoryAGet16(ds, r16[di] + 2);
    r16[dx] = memoryAGet16(ds, 0x527e);
    r16[bx] = memoryAGet16(ds, r16[di] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[bl] = memoryAGet(ds, r16[bx] + 27640);
    r8[bl]--;
    if (r16s[ax] >= r16s[dx])
        { pc = 0x14c4e; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r8[bl] = 0x0a;
  case 0x14c4e: // 1020:4a4e
    r8[bh] = 0;
    r16[ax] -= r16[bx];
    if (r16s[ax] >= r16s[dx])
        { pc = 0x14cd2; break; }
    if (memoryAGet(ds, r16[di] + 4) < 0x65)
        { pc = 0x14c90; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[di]);
    if (!(memoryAGet(ds, r16[di] + 5) & 0x80))
        { pc = 0x14c69; break; }
    r16[ax] = -r16[ax];
  case 0x14c69: // 1020:4a69
    if (r16s[ax] < 0)
        { pc = 0x14cd2; break; }
    r16[bx] = memoryAGet16(ds, r16[di] + 9);
    memoryASet16(ds, r16[bx] + 4, 0xffff);
    r16[bx] = memoryAGet16(ds, r16[di] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28538);
    r8[bl] &= 0x0f;
    r8[bh] = 0;
    r16[bx] <<= 1;
    r16[bx] = memoryAGet16(ds, r16[bx] + 28613);
    r16[bx] += 0x0065;
    memoryASet16(ds, r16[di] + 4, r16[bx]);
  case 0x14c90: // 1020:4a90
    r8[al] = 0x09;
    yield* sub_113e6();
    r16[ax] = 0;
    memoryASet(ds, 0x6505, r8[al]);
    memoryASet16(ds, r16[di] + 14, r16[ax]);
    memoryASet16(ds, r16[di] + 6, r16[ax]);
    memoryASet(ds, 0x6511, 0x04);
    r16[ax] = 0xffff;
    r16[tx] = memoryAGet16(ds, r16[di] + 4); memoryASet16(ds, r16[di] + 4, r16[ax]); r16[ax] = r16[tx];
    memoryASet16(ds, 0x5292, r16[ax]);
    memoryASet(ds, 0x6509, 0x10);
    memoryASet(ds, 0x6515, 0x00);
    if (r8[al] != 0x31)
        { pc = 0x14cc1; break; }
    memoryASet(ds, 0x6503, 0x00);
  case 0x14cc1: // 1020:4ac1
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= 0x0004;
    memoryASet16(ds, 0x5290, r16[ax]);
    yield* sub_15322();
    memoryASet16(ds, 0x528e, r16[ax]);
    { pc = 0x14ce3; break; }
  case 0x14cd2: // 1020:4ad2
    r16[bx] = memoryAGet16(ds, 0x527e);
    r16[dx] = memoryAGet16(ds, 0x527c);
  case 0x14cda: // 1020:4ada
    r16[di] += 0x0012;
    r16[cx]--;
    if (!r16[cx])
        { pc = 0x14ce3; break; }
    { pc = 0x14bca; break; }
  case 0x14ce3: // 1020:4ae3
    memoryASet(ds, 0x650c, 0x01);
    return;
  }
}
function* sub_14ce9() // 1020:4ae9
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet16(ds, 0x5292) == 0xffff)
        { pc = 0x14d48; break; }
    if (!memoryAGet(ds, 0x6509))
        { pc = 0x14d48; break; }
    push(r16[ax]);
    push(r16[di]);
    r16[di] = 0x528e;
    r16[ax] = 0xffff;
  case 0x14cff: // 1020:4aff
    r16[di] += 0x0012;
    if (memoryAGet16(ds, r16[di] + 4) != r16[ax])
        { pc = 0x14cff; break; }
    r16[tx] = memoryAGet16(ds, 0x5292); memoryASet16(ds, 0x5292, r16[ax]); r16[ax] = r16[tx];
    memoryASet16(ds, r16[di] + 4, r16[ax]);
    r8[ah] &= 0x1f;
    flags.carry = r16[ax] < 0x0065;
    r8[al] = 0x00;
    if (flags.carry)
        { pc = 0x14d1a; break; }
    r8[al]++;
  case 0x14d1a: // 1020:4b1a
    memoryASet(ds, r16[di] + 11, r8[al]);
    r16[ax] = memoryAGet16(ds, 0x528e);
    memoryASet16(ds, r16[di], r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5290);
    memoryASet16(ds, r16[di] + 2, r16[ax]);
    r16[ax] = 0;
    memoryASet(ds, 0x6509, r8[al]);
    memoryASet16(ds, r16[di] + 12, r16[ax]);
    memoryASet16(ds, r16[di] + 14, r16[ax]);
    memoryASet16(ds, r16[di] + 6, r16[ax]);
    memoryASet(ds, r16[di] + 8, r8[al]);
    r16[ax]++;
    memoryASet(ds, 0x650c, r8[al]);
    memoryASet(ds, 0x6511, 0x04);
    memoryASet16(ds, 0x64e9, r16[di]);
    r16[di] = pop();
    r16[ax] = pop();
  case 0x14d48: // 1020:4b48
    return;
  }
}
function* sub_14d49() // 1020:4b49
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (!memoryAGet(ds, 0x0459))
        { pc = 0x14d7c; break; }
  case 0x14d50: // 1020:4b50
    yield* sync();
    if (memoryAGet(ds, 0x0459))
        { pc = 0x14d50; break; }
    yield* sub_12e87();
    push(memoryAGet16(ds, 0x5280));
    memoryASet16(ds, 0x5280, 0x001d);
    yield* sub_11e61();
    yield* sub_13471();
    memoryASet16(ds, 0x5280, pop());
  case 0x14d6e: // 1020:4b6e
    yield* sync();
    if (!memoryAGet(ds, 0x0459))
        { pc = 0x14d6e; break; }
  case 0x14d75: // 1020:4b75
    yield* sync();
    if (memoryAGet(ds, 0x0459))
        { pc = 0x14d75; break; }
  case 0x14d7c: // 1020:4b7c
    return;
  }
}
function* sub_14d7d() // 1020:4b7d
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[bp]);
    r16[ax] = 0;
    if (!memoryAGet(ds, 0x6507))
        { pc = 0x14d95; break; }
    r16[ax] = memoryAGet16(ds, 0x5285);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
  case 0x14d95: // 1020:4b95
    r8[cl] = memoryAGet(ds, 0x5284);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[dx] = memoryAGet16(ds, 0x5282);
    r16[dx] += r16[ax];
    if (r16s[dx] >= r16s[bp])
        { pc = 0x14dad; break; }
    r16[bp] = -r16[bp];
    if (r16s[dx] <= r16s[bp])
        { pc = 0x14dad; break; }
    r16[bp] = r16[dx];
  case 0x14dad: // 1020:4bad
    memoryASet16(ds, 0x5282, r16[bp]);
    r16[bp] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_14db6() // 1020:4bb6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x528a);
    r16[dx] += 0xffe0;
    r16[bp] = -r16[bp];
    if (r16s[dx] >= r16s[bp])
        { pc = 0x14dc8; break; }
    r16[bp] = r16[dx];
  case 0x14dc8: // 1020:4bc8
    memoryASet16(ds, 0x528a, r16[bp]);
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_14dd0() // 1020:4bd0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[cx]);
    push(r16[dx]);
    r16[dx] = memoryAGet16(ds, 0x528a);
    r16[dx] += 0x0010;
    if (r16s[dx] >= r16s[bp])
        { pc = 0x14de0; break; }
    r16[bp] = r16[dx];
  case 0x14de0: // 1020:4be0
    memoryASet16(ds, 0x528a, r16[bp]);
    r16[dx] = pop();
    r16[cx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_14de8() // 1020:4be8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[cx]);
    push(r16[dx]);
    r8[ch] = 0;
    r16[ax] = memoryAGet16(ds, 0x5282);
    if (r16s[ax] >= 0)
        { pc = 0x14df7; break; }
    r16[ax] = -r16[ax];
    r8[ch]++;
  case 0x14df7: // 1020:4bf7
    r8[cl] = memoryAGet(ds, 0x5284);
    r16[dx] = 0x000c;
    r16[dx] >>= r8[cl];
    flags.carry = r16[ax] < r16[dx];
    r16[ax] -= r16[dx];
    if (!flags.carry)
        { pc = 0x14e06; break; }
    r16[ax] = 0;
  case 0x14e06: // 1020:4c06
    if (!r8[ch])
        { pc = 0x14e0c; break; }
    r16[ax] = -r16[ax];
  case 0x14e0c: // 1020:4c0c
    memoryASet16(ds, 0x5282, r16[ax]);
    r16[dx] = pop();
    r16[cx] = pop();
    return;
  }
}
function* sub_14e12() // 1020:4c12
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(ds, 0x5287) == r8[al])
        { pc = 0x14e25; break; }
    memoryASet(ds, 0x5287, r8[al]);
    r16[bx] = memoryAGet16(ds, r16[bx] + 28351);
    memoryASet16(ds, 0x5288, r16[bx]);
    { pc = 0x14e29; break; }
  case 0x14e25: // 1020:4c25
    r16[bx] = memoryAGet16(ds, 0x5288);
  case 0x14e29: // 1020:4c29
    return;
  }
}
function* sub_14e2a() // 1020:4c2a
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, r16[bx]);
    if (r16s[ax] >= 0)
        { pc = 0x14e37; break; }
    r16[bx] += r16[ax];
    r16[ax] = memoryAGet16(ds, r16[bx]);
  case 0x14e37: // 1020:4c37
    r8[dh] = memoryAGet(ds, 0x5285);
    r8[dh] &= 0x80;
    r8[ah] |= r8[dh];
    memoryASet16(ds, 0x5280, r16[ax]);
    r16[bx]++;
    r16[bx]++;
    memoryASet16(ds, 0x5288, r16[bx]);
    r16[dx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_14e65() // 1020:4c65
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memoryASet(ds, 0x650f, 0x06);
    if (memoryAGet(ds, 0x6514))
        { pc = 0x14ea1; break; }
    push(r16[ax]);
    push(r16[bp]);
    r16[bp] = 0x0040;
    yield* sub_14d7d();
    r16[bp] = 0x00c0;
    yield* sub_14dd0();
    if (!memoryAGet(ds, 0x6513))
        { pc = 0x14e8a; break; }
    r8[al] = 0x0f;
    { pc = 0x14e95; break; }
  case 0x14e8a: // 1020:4c8a
    r8[al] = 0x0a;
    if (!memoryAGet(ds, 0x6509))
        { pc = 0x14e95; break; }
    r8[al] = 0x15;
  case 0x14e95: // 1020:4c95
    r8[ah] = memoryAGet(ds, 0x5285);
    r8[ah] &= 0x80;
    memoryASet16(ds, 0x5280, r16[ax]);
    r16[bp] = pop();
    r16[ax] = pop();
  case 0x14ea1: // 1020:4ca1
    return;
  }
}
function* sub_14ea2() // 1020:4ca2
{
    memoryASet(ds, 0x6526, memoryAGet(ds, 0x6526) | 0x01);
}
function* sub_14ea8() // 1020:4ca8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    r16[ax] = memoryAGet16(ds, 0x5282);
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] = sar16(r16[ax], 0x0001);
    r16[ax] = sar16(r16[ax], 0x0001);
    memoryASet16(ds, 0x527c, memoryAGet16(ds, 0x527c) - r16[ax]);
    memoryASet16(ds, 0x5282, 0x0000);
    if (!memoryAGet(ds, 0x6514))
        { pc = 0x14ed6; break; }
    if (memoryAGet(ds, 0x650f) == 0x06)
        { pc = 0x14ed6; break; }
    memoryASet(ds, 0x6513, 0x14);
    memoryASet(ds, 0x6514, 0x00);
  case 0x14ed6: // 1020:4cd6
    r16[ax] = pop();
    return;
  }
}
function* sub_14ed8() // 1020:4cd8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x14ed8; break; }
  case 0x14ea2: // 1020:4ca2
    memoryASet(ds, 0x6526, memoryAGet(ds, 0x6526) | 0x01);
    return;
    // gap 48 bytes // gap 48 bytes
  case 0x14ed8: // 1020:4cd8
    memoryASet(ds, 0x651c, 0x01);
    memoryASet(ds, 0x5284, 0x00);
    if (signed16(memoryAGet16(ds, 0x528a)) >= signed16(0x0000))
        { pc = 0x14eeb; break; }
    { pc = 0x14ea2; break; }
  case 0x14eeb: // 1020:4ceb
    memoryASet(ds, 0x527e, memoryAGet(ds, 0x527e) & 0xf0);
    memoryASet16(ds, 0x528a, 0x0000);
    flags.carry = memoryAGet(ds, 0x650f) < 0x01;
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) - 0x01);
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) + (0x00 + flags.carry));
    memoryASet(ds, 0x651d, 0x00);
    memoryASet(ds, 0x6526, 0x02);
    return;
  }
}
function* sub_14ef0() // 1020:4cf0
{
    memoryASet16(ds, 0x528a, 0x0000);
    flags.carry = memoryAGet(ds, 0x650f) < 0x01;
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) - 0x01);
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) + (0x00 + flags.carry));
    memoryASet(ds, 0x651d, 0x00);
    memoryASet(ds, 0x6526, 0x02);
}
function* sub_14ef6() // 1020:4cf6
{
    flags.carry = memoryAGet(ds, 0x650f) < 0x01;
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) - 0x01);
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) + (0x00 + flags.carry));
    memoryASet(ds, 0x651d, 0x00);
    memoryASet(ds, 0x6526, 0x02);
}
function* sub_14f0b() // 1020:4d0b
{
}
function* sub_14f0c() // 1020:4d0c
{
    yield* sub_14ea8();
}
function* sub_14f10() // 1020:4d10 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[si] = 0x7bad;
    r16[cx] = 0x0064;
  case 0x14f1f: // 1020:4d1f
    if (memoryAGet16(ds, r16[si] + 2) == r16[di])
        { pc = 0x14f2b; break; }
    r16[si] += 0x0004;
    if (--r16[cx])
        { pc = 0x14f1f; break; }
    { pc = 0x14f8f; break; }
  case 0x14f2b: // 1020:4d2b
    if (memoryAGet(ds, r16[si]) < 0xfd)
        { pc = 0x14f39; break; }
    r16[ax] = 0x0006;
    yield* sub_112ff();
    yield* sub_15ba1();
  case 0x14f39: // 1020:4d39
    r8[al] = memoryAGet(ds, r16[si] + 1);
    memoryASet(es, r16[di], r8[al]);
    r8[bl] = 0x50;
    r8[bh] = 0x02;
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x14f52; break; }
    yield* sub_134f4();
    r8[bl] = 0x28;
    r8[bh] = 0x01;
  case 0x14f52: // 1020:4d52
    r16[ax] = r16[di];
    r8[al] = r8[ah];
    r8[ah] = 0;
    r8[dl] = 0x0c;
    div8(r8[dl]);
    r8[al] = r8[bl];
    mul8(r8[ah]);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    push(r16[ax]);
    r16[ax] = r16[di];
    r8[ah] = 0;
    r8[dl] = 0x14;
    div8(r8[dl]);
    r8[al] = r8[ah];
    r8[ah] = 0;
    r8[cl] = r8[bh];
    r16[ax] <<= r8[cl];
    r16[di] = pop();
    r16[di] += r16[ax];
    r8[al] = memoryAGet(ds, r16[si] + 1);
    yield* sub_12fdc();
    memoryASet(ds, 0x6511, 0x04);
    memoryASet(ds, 0x64f5, 0x01);
    flags.carry = 0;
    { pc = 0x14f90; break; }
  case 0x14f8f: // 1020:4d8f
    flags.carry = 1;
  case 0x14f90: // 1020:4d90
    r16[bp] = pop();
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
}
function* sub_14f9a() // 1020:4d9a
{
    r16[ax] = 0x0007;
    yield* sub_112ff();
    r8[al] = memoryAGet(ds, 0x5250);
    memoryASet(ds, 0x5250, 0x0e);
    push(r16[ax]);
    yield* sub_14fb1();
    r16[ax] = pop();
    memoryASet(ds, 0x5250, r8[al]);
}
function* sub_14fb1() // 1020:4db1
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x0007;
    yield* sub_112ff();
    yield* sub_14f10();
    if (flags.carry)
        { pc = 0x14fbf; break; }
    yield* sub_10533();
  case 0x14fbf: // 1020:4dbf
    return;
  }
}
function* sub_14fc0() // 1020:4dc0
{
    yield* sub_15be7();
    memoryASet(ds, 0x6516, 0x02);
}
function* sub_14fc9() // 1020:4dc9
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x0005;
    yield* sub_112ff();
    yield* sub_14f10();
    if (flags.carry)
        { pc = 0x14ff8; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    memoryASet16(ds, 0x64e4, r16[ax]);
    r16[dx] = memoryAGet16(ds, 0x527e);
    memoryASet16(ds, 0x64e6, r16[dx]);
    r16[bx] = memoryAGet16(ds, 0x5292);
    r8[bh] &= 0x1f;
    r16[bx] -= 0x0038;
    if (r16[bx] > 0x0001)
        { pc = 0x14ff8; break; }
    memoryASet16(ds, 0x64f8, r16[ax]);
    memoryASet16(ds, 0x64fa, r16[dx]);
  case 0x14ff8: // 1020:4df8
    return;
  }
}
function* sub_14ff9() // 1020:4df9
{
    yield* sub_14ea2();
}
function* sub_14ffd() // 1020:4dfd
{
    yield* sub_14ed8();
}
function* sub_15001() // 1020:4e01
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x15001; break; }
  case 0x14ea2: // 1020:4ca2
    memoryASet(ds, 0x6526, memoryAGet(ds, 0x6526) | 0x01);
    return;
    // gap 48 bytes // gap 48 bytes
  case 0x14ed8: // 1020:4cd8
    memoryASet(ds, 0x651c, 0x01);
    memoryASet(ds, 0x5284, 0x00);
    if (signed16(memoryAGet16(ds, 0x528a)) >= signed16(0x0000))
        { pc = 0x14eeb; break; }
    { pc = 0x14ea2; break; }
  case 0x14eeb: // 1020:4ceb
    memoryASet(ds, 0x527e, memoryAGet(ds, 0x527e) & 0xf0);
    memoryASet16(ds, 0x528a, 0x0000);
    flags.carry = memoryAGet(ds, 0x650f) < 0x01;
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) - 0x01);
    memoryASet(ds, 0x650f, memoryAGet(ds, 0x650f) + (0x00 + flags.carry));
    memoryASet(ds, 0x651d, 0x00);
    memoryASet(ds, 0x6526, 0x02);
    return;
    // gap 246 bytes // gap 246 bytes
  case 0x15001: // 1020:4e01
    memoryASet(ds, 0x5284, 0x00);
    if (memoryAGet(ds, 0x6510))
        { pc = 0x15010; break; }
    { pc = 0x14ed8; break; }
  case 0x15010: // 1020:4e10
    { pc = 0x14ea2; break; }
    return;
  }
}
function* sub_15013() // 1020:4e13
{
    yield* sub_14ed8();
    memoryASet(ds, 0x5284, 0x01);
}
function* sub_1501c() // 1020:4e1c
{
    yield* sub_14ed8();
    memoryASet(ds, 0x5284, 0x02);
}
function* sub_15025() // 1020:4e25
{
    yield* sub_14ed8();
    memoryASet(ds, 0x5284, 0x03);
}
function* sub_1502e() // 1020:4e2e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x1502e; break; }
  case 0x14ff9: // 1020:4df9
    yield* sub_14ea2();
    return;
  case 0x14ffd: // 1020:4dfd
    yield* sub_14ed8();
    return;
    // gap 45 bytes // gap 45 bytes
  case 0x1502e: // 1020:4e2e
    if (memoryAGet(ds, 0x6513))
        { pc = 0x14ff9; break; }
    r8[al] = memoryAGet(ds, 0x5287);
    r8[al] &= 0x0f;
    if (r8[al] == 0x01)
        { pc = 0x14ffd; break; }
    flags.zero = r8[al] == 0x03;
  case 0x15040: // 1020:4e40
    if (flags.zero)
        { pc = 0x14ffd; break; }
    if (r8[al] == 0x07)
        { pc = 0x14ffd; break; }
    flags.zero = r8[al] == 0x08;
    if (flags.zero)
        { pc = 0x15040; break; }
    if (r8[al] != 0x05)
        { pc = 0x1505c; break; }
    yield* sub_14ff9();
    memoryASet16(ds, 0x5280, 0x000e);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) + 0x0008);
  case 0x1505c: // 1020:4e5c
    push(ds);
    ds = memoryAGet16(ds, 0x526c);
    r8[bl] = memoryAGet(ds, r16[di] + 65280);
    ds = pop();
    r8[bh] = 0;
    r8[ah] = memoryAGet(ds, r16[bx] + 29603);
    if (r8[ah] == 0x06)
        { pc = 0x1507e; break; }
    flags.zero = r8[al] == 0x00;
    if (flags.zero)
        { pc = 0x15040; break; }
    r8[ah] = memoryAGet(ds, 0x042d);
    flags.zero = r16[ax] == 0xff06;
    if (flags.zero)
        { pc = 0x15040; break; }
  case 0x1507e: // 1020:4e7e
    yield* sub_14ef6();
    memoryASet(ds, 0x650d, 0x01);
    return;
  }
}
function* sub_15087() // 1020:4e87
{
}
function* sub_15088() // 1020:4e88
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (!memoryAGet16(ds, 0x528a))
        { pc = 0x150a5; break; }
    memoryASet16(ds, 0x528a, 0x0000);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) & 0xfff0);
    memoryASet16(ds, 0x527e, memoryAGet16(ds, 0x527e) + 0x0010);
    memoryASet(ds, 0x651d, 0xff);
    return;
  case 0x150a5: // 1020:4ea5
    r8[al] = memoryAGet(ds, 0x5280);
    if (r8[al] == 0x0a)
        { pc = 0x15102; break; }
    if (r8[al] == 0x15)
        { pc = 0x15102; break; }
    if (memoryAGet(ds, 0x650f) == 0x06)
        { pc = 0x15102; break; }
    memoryASet(ds, 0x650e, 0x01);
    if (!memoryAGet(ds, 0x6509))
        { pc = 0x15102; break; }
    yield* sub_14ce9();
    push(r16[bx]);
    push(r16[di]);
    r16[di] = memoryAGet16(ds, 0x64e9);
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, r16[di] + 2);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r8[bh] = r8[al];
    r16[ax] = memoryAGet16(ds, r16[di]);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r8[bl] = r8[al];
    r16[di] = r16[bx];
    es = memoryAGet16(ds, 0x526c);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(es, r16[di]);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (!r8[al])
        { pc = 0x15100; break; }
    r16[dx] = 0x0010;
    r8[al] = memoryAGet(es, r16[di] - 1);
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (r8[al])
        { pc = 0x150fa; break; }
    r16[dx] = -r16[dx];
  case 0x150fa: // 1020:4efa
    r16[di] = memoryAGet16(ds, 0x64e9);
    memoryASet16(ds, r16[di], memoryAGet16(ds, r16[di]) + r16[dx]);
  case 0x15100: // 1020:4f00
    r16[di] = pop();
    r16[bx] = pop();
  case 0x15102: // 1020:4f02
    return;
  }
}
function* sub_15103() // 1020:4f03
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (signed16(memoryAGet16(ds, 0x528a)) >= signed16(0x0000))
        { pc = 0x1511b; break; }
    if (memoryAGet16(ds, 0x5282))
        { pc = 0x1511b; break; }
    memoryASet(ds, 0x651d, 0x0a);
    memoryASet(ds, 0x650d, 0x01);
  case 0x1511b: // 1020:4f1b
    return;
  }
}
function* sub_1511f() // 1020:4f1f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x1511f; break; }
  case 0x1511c: // 1020:4f1c
    { pc = 0x1523b; break; }
  case 0x1511f: // 1020:4f1f
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    if (signed16(memoryAGet16(ds, r16[si] + 14)) < signed16(0x0000))
        { pc = 0x1511c; break; }
    r16[si] = 0x527c;
    r16[bx] = 0;
    yield* sub_15245();
    if (!flags.carry)
        { pc = 0x1511c; break; }
    memoryASet16(ds, 0x527e, r16[dx]);
    r16[di] = r16[ax];
    r8[al] = memoryAGet(ds, r16[di] + 4);
    r8[al] -= 0x36;
    if (r8[al] > 0x01)
        { pc = 0x1514e; break; }
    memoryASet(ds, r16[di] + 8, memoryAGet(ds, r16[di] + 8) | 0x02);
    memoryASet16(ds, r16[di] + 9, r16[si]);
  case 0x1514e: // 1020:4f4e
    r8[al] = memoryAGet(ds, r16[di] + 4);
    r8[al] -= 0x33;
    if (r8[al] > 0x01)
        { pc = 0x1517b; break; }
    r16[ax] = 0x0060;
    r8[dl] = memoryAGet(ds, 0x5281);
    r8[dl] &= 0x80;
    if (!r8[dl])
        { pc = 0x15165; break; }
    r16[ax] = -r16[ax];
  case 0x15165: // 1020:4f65
    memoryASet(ds, r16[di] + 5, memoryAGet(ds, r16[di] + 5) & 0x7f);
    memoryASet(ds, r16[di] + 5, memoryAGet(ds, r16[di] + 5) | r8[dl]);
    memoryASet16(ds, r16[di] + 6, r16[ax]);
    memoryASet(ds, 0x6511, 0x04);
    memoryASet(ds, 0x6503, 0x00);
    { pc = 0x151b9; break; }
  case 0x1517b: // 1020:4f7b
    if (signed16(memoryAGet16(ds, 0x651e)) <= signed16(0x000a))
        { pc = 0x151b9; break; }
    if (memoryAGet(ds, 0x5287) & 0x0f)
        { pc = 0x151b9; break; }
    if (memoryAGet16(ds, 0x528a))
        { pc = 0x151b9; break; }
    r8[al] = memoryAGet(ds, r16[di] + 4);
    if (r8[al] == 0x53)
        { pc = 0x1519b; break; }
    if (r8[al] != 0x5e)
        { pc = 0x151b9; break; }
  case 0x1519b: // 1020:4f9b
    r16[ax] = 0x0030;
    if (!(memoryAGet(ds, 0x5281) & 0x80))
        { pc = 0x151a7; break; }
    r16[ax] = -r16[ax];
  case 0x151a7: // 1020:4fa7
    memoryASet16(ds, r16[di] + 6, r16[ax]);
    r8[ah] &= 0x80;
    memoryASet(ds, r16[di] + 5, memoryAGet(ds, r16[di] + 5) & 0x7f);
    memoryASet(ds, r16[di] + 5, memoryAGet(ds, r16[di] + 5) | r8[ah]);
    memoryASet(ds, 0x6511, 0x04);
  case 0x151b9: // 1020:4fb9
    r16[dx] = 0x0010;
    r16[ax] = memoryAGet16(ds, r16[di] + 6);
    if (!r16[ax])
        { pc = 0x151cc; break; }
    if (r16s[ax] >= 0)
        { pc = 0x151c7; break; }
    r16[dx] = 0;
  case 0x151c7: // 1020:4fc7
    r16[ax] += r16[dx];
    memoryASet16(ds, 0x5282, r16[ax]);
  case 0x151cc: // 1020:4fcc
    if (memoryAGet(ds, 0x6510))
        { pc = 0x15229; break; }
    if (signed16(memoryAGet16(ds, 0x528a)) <= signed16(0x0030))
        { pc = 0x15229; break; }
    push(r16[di]);
    yield* sub_15333();
    if (flags.zero)
        { pc = 0x15229; break; }
    r16[ax] = memoryAGet16(ds, 0x528a);
    r16[dx] = 0xfff0;
    if (!memoryAGet(ds, 0x042d))
        { pc = 0x151f0; break; }
    r16[dx] = 0x0030;
  case 0x151f0: // 1020:4ff0
    if (memoryAGet(ds, 0x042e))
        { pc = 0x151fb; break; }
    r16[ax] += r16[dx];
    if (r16s[ax] >= 0)
        { pc = 0x151fd; break; }
  case 0x151fb: // 1020:4ffb
    r16[ax] = 0;
  case 0x151fd: // 1020:4ffd
    r16[ax] = -r16[ax];
    memoryASet16(ds, 0x528a, r16[ax]);
    memoryASet16(ds, 0x651e, 0x0000);
    if (memoryAGet16(ds, r16[di] + 14))
        { pc = 0x1523b; break; }
    r8[al] = 0x0c;
    yield* sub_113e6();
    r16[ax] = memoryAGet16(ds, 0x528a);
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[di] + 14, r16[ax]);
    r8[cl] = 0x04;
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet16(ds, r16[di] + 2, memoryAGet16(ds, r16[di] + 2) - r16[ax]);
    memoryASet(ds, 0x6511, 0x04);
    { pc = 0x1523b; break; }
  case 0x15229: // 1020:5029
    r16[ax] = memoryAGet16(ds, r16[di] + 14);
    if (!r16[ax])
        { pc = 0x15238; break; }
    memoryASet16(ds, 0x528a, r16[ax]);
    yield* sub_14ef6();
    { pc = 0x1523b; break; }
  case 0x15238: // 1020:5038
    yield* sub_14ef0();
  case 0x1523b: // 1020:503b
    r16[bp] = pop();
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
}
function* sub_15245() // 1020:5045 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[cx]);
    push(r16[di]);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[al] = memoryAGet(ds, r16[bx] + 27639);
    r8[ah] = 0;
    memoryASet16(ds, 0x64ef, r16[ax]);
    r8[bl] = memoryAGet(ds, r16[bx] + 26213);
    r8[bh] = 0;
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[dx] = memoryAGet16(ds, r16[si] + 2);
    r16[bx] >>= 1;
    r16[ax] -= r16[bx];
    memoryASet16(ds, 0x64f1, r16[ax]);
    memoryASet16(ds, 0x64f3, r16[dx]);
    r16[cx] = 0x0028;
    r16[di] = 0x52a0;
  case 0x15271: // 1020:5071
    if (r16[si] == r16[di])
        { pc = 0x1528c; break; }
    r16[bx] = memoryAGet16(ds, r16[di] + 4);
    if (r16[bx] == 0xffff)
        { pc = 0x1528c; break; }
    r8[bh] &= 0x1f;
    if (!(memoryAGet(ds, r16[bx] + 28441) & 0x01))
        { pc = 0x1528c; break; }
    yield* sub_15353();
    if (flags.carry)
        { pc = 0x15292; break; }
  case 0x1528c: // 1020:508c
    r16[di] += 0x0012;
    if (--r16[cx])
        { pc = 0x15271; break; }
    flags.carry = 0;
  case 0x15292: // 1020:5092
    r16[di] = pop();
    r16[cx] = pop();
    return;
  }
}
function* sub_15295() // 1020:5095 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, r16[di]);
    if (r16s[ax] >= 0)
        { pc = 0x152a0; break; }
    r16[ax] = -r16[ax];
  case 0x152a0: // 1020:50a0
    if (r16[ax] >= 0x0040)
        { pc = 0x1531d; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= memoryAGet16(ds, r16[di] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x152af; break; }
    r16[ax] = -r16[ax];
  case 0x152af: // 1020:50af
    if (r16[ax] >= 0x0046)
        { pc = 0x1531d; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[dx] = memoryAGet16(ds, r16[di] + 2);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    if (r16s[ax] >= r16s[dx])
        { pc = 0x152c5; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r16[bx] = memoryAGet16(ds, r16[di] + 4);
  case 0x152c5: // 1020:50c5
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[bl] = memoryAGet(ds, r16[bx] + 27640);
    r8[bh] = 0;
    r16[bx] -= 0x0003;
    r16[ax] -= r16[bx];
    if (r16s[ax] >= r16s[dx])
        { pc = 0x1531d; break; }
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r16[bp] = r16[bx];
    r8[al] = memoryAGet(ds, r16[bx] + 26927);
    r8[ah] = 0;
    r16[dx] = memoryAGet16(ds, r16[si]);
    r16[dx] -= r16[ax];
    r16[bx] = memoryAGet16(ds, r16[di] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r16[ax] = memoryAGet16(ds, r16[di]);
    flags.carry = r8[al] < memoryAGet(ds, r16[bx] + 26927);
    r8[al] -= memoryAGet(ds, r16[bx] + 26927);
    r8[ah] -= (0x00 + flags.carry);
    r8[bl] = memoryAGet(ds, r16[bx] + 27639);
    r8[bl] >>= 1;
    if (r16s[ax] < r16s[dx])
        { pc = 0x15310; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r8[bl] = memoryAGet(ds, r16[bp] + 27639);
    r8[bl] >>= 1;
  case 0x15310: // 1020:5110
    r8[bh] = 0;
    r16[ax] += r16[bx];
    if (r16s[ax] <= r16s[dx])
        { pc = 0x1531d; break; }
    r16[dx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    flags.carry = 1;
    return;
  case 0x1531d: // 1020:511d
    r16[dx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    flags.carry = 0;
    return;
  }
}
function* sub_15322() // 1020:5122
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[dx] = 0x000c;
    if (!(memoryAGet(ds, r16[si] + 5) & 0x80))
        { pc = 0x15330; break; }
    r16[dx] = 0xfff6;
  case 0x15330: // 1020:5130
    r16[ax] += r16[dx];
    return;
  }
}
function* sub_15333() // 1020:5133 +returnZero +stackDrop2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    push(r16[bx]);
    push(r16[bp]);
    r16[bp] = sp;
    r16[bx] = memoryAGet16(ss, r16[bp] + 6);
    r16[bx] = memoryAGet16(ds, r16[bx] + 4);
    r8[bh] &= 0x1f;
    if (r8[bl] < 0x65)
        { pc = 0x15349; break; }
    r16[bx] = 0;
    flags.zero = r16[bx] == 0;
    { pc = 0x1534e; break; }
  case 0x15349: // 1020:5149
    flags.zero = !(memoryAGet(ds, r16[bx] + 28441) & 0x02);
  case 0x1534e: // 1020:514e
    r16[bp] = pop();
    r16[bx] = pop();
    sp += 4;
    return;
  }
}
function* sub_15353() // 1020:5153 +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx] = memoryAGet16(ds, r16[di]);
    r16[bx] -= r16[ax];
    if (r16s[bx] >= 0)
        { pc = 0x1535b; break; }
    r16[bx] = -r16[bx];
  case 0x1535b: // 1020:515b
    if (r16[bx] > 0x0040)
        { pc = 0x153c3; break; }
    r16[bx] = memoryAGet16(ds, r16[di] + 2);
    r16[bx] -= r16[dx];
    if (r16s[bx] >= 0)
        { pc = 0x15369; break; }
    r16[bx] = -r16[bx];
  case 0x15369: // 1020:5169
    if (r16[bx] > 0x0046)
        { pc = 0x153c3; break; }
    r16[bx] = memoryAGet16(ds, r16[di] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r16[bp] = r16[bx];
    r8[bl] = memoryAGet(ds, r16[bx] + 27639);
    r8[bh] = 0;
    push(r16[bx]);
    r16[bx] >>= 1;
    r16[dx] = memoryAGet16(ds, r16[di]);
    r16[dx] -= r16[bx];
    r16[bx] = pop();
    if (r16s[dx] <= r16s[ax])
        { pc = 0x1538f; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
    r16[bx] = memoryAGet16(ds, 0x64ef);
  case 0x1538f: // 1020:518f
    r16[dx] += r16[bx];
    if (r16s[dx] <= r16s[ax])
        { pc = 0x153bc; break; }
    r8[bl] = memoryAGet(ds, r16[bp] + 27640);
    r8[bh] = 0;
    r16[bp] = r16[bx];
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[bx] >>= 1;
    r16[dx] = memoryAGet16(ds, r16[di] + 2);
    r16[ax] = memoryAGet16(ds, 0x64f3);
    r16[dx] -= r16[bx];
    if (r16s[dx] < r16s[ax])
        { pc = 0x153bc; break; }
    r16[dx] += r16[bx];
    r16[dx] -= r16[bp];
    if (r16s[dx] > r16s[ax])
        { pc = 0x153bc; break; }
    r16[ax] = r16[di];
    flags.carry = 1;
    return;
  case 0x153bc: // 1020:51bc
    r16[ax] = memoryAGet16(ds, 0x64f1);
    r16[dx] = memoryAGet16(ds, 0x64f3);
  case 0x153c3: // 1020:51c3
    flags.carry = 0;
    return;
  }
}
function* sub_153c6() // 1020:51c6
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    yield* sub_15538();
    memoryASet16(ds, 0x043c, 0x0000);
  case 0x153d4: // 1020:51d4
    memoryASet(ds, 0x87d4, 0x00);
  case 0x153d9: // 1020:51d9
    if (memoryAGet16(ds, 0x000a) < 0x07c8)
        { pc = 0x153f1; break; }
    if (memoryAGet16(ds, 0x043c) < 0x0ca8)
        { pc = 0x153f1; break; }
    yield* sub_11b1c();
    yield* sub_155c8();
    { pc = 0x153d4; break; }
  case 0x153f1: // 1020:51f1
    yield* sync();
    yield* sub_10a05();
    if (!memoryAGet(ds, 0x042d))
        { pc = 0x1540b; break; }
    if (!memoryAGet(ds, 0x87d4))
        { pc = 0x1540b; break; }
    yield* sub_15452();
    memoryASet(ds, 0x87d4, memoryAGet(ds, 0x87d4) - 1);
    { pc = 0x153d9; break; }
  case 0x1540b: // 1020:520b
    if (!memoryAGet(ds, 0x042e))
        { pc = 0x15422; break; }
    if (memoryAGet(ds, 0x87d4))
        { pc = 0x15422; break; }
    yield* sub_15452();
    memoryASet(ds, 0x87d4, memoryAGet(ds, 0x87d4) + 1);
    { pc = 0x153d9; break; }
  case 0x15422: // 1020:5222
    if (memoryAGet(ds, 0x042b))
        { pc = 0x1542b; break; }
    { pc = 0x153d9; break; }
  case 0x1542b: // 1020:522b
    if (!memoryAGet(ds, 0x87d4))
        { pc = 0x15444; break; }
    yield* sub_1047b();
    if (flags.carry)
        { pc = 0x1543a; break; }
    memoryASet(ds, 0x5250, r8[al]);
  case 0x1543a: // 1020:523a
    yield* sub_155c8();
    memoryASet(ds, 0x87d4, 0x00);
    { pc = 0x153d9; break; }
  case 0x15444: // 1020:5244
    yield* sync();
    yield* sub_10a05();
    if (memoryAGet(ds, 0x042b))
        { pc = 0x15444; break; }
    yield* sub_15845();
    return;
  }
}
function* sub_15452() // 1020:5252
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] == 0x05)
        { pc = 0x15460; break; }
    if (r8[al] >= 0x03)
        { pc = 0x1548b; break; }
    { pc = 0x154bb; break; }
  case 0x15460: // 1020:5260
    push(ds);
    r16[ax] = 0xa000;
    ds = r16[ax];
    r16[si] = 0xc878;
    r16[di] = 0xd8b8;
    r16[dx] = 0x0008;
  case 0x1546f: // 1020:526f
    r16[cx] = 0x0004;
  case 0x15472: // 1020:5272
    r16[ax] = memoryAGet16(ds, r16[di]);
    r16[tx] = memoryAGet16(ds, r16[si]); memoryASet16(ds, r16[si], r16[ax]); r16[ax] = r16[tx];
    memoryASet16(ds, r16[di], r16[ax]);
    r16[si]++;
    r16[si]++;
    r16[di]++;
    r16[di]++;
    if (--r16[cx])
        { pc = 0x15472; break; }
    r16[si] += 0x0138;
    r16[di] += 0x0138;
    r16[dx]--;
    if (r16[dx])
        { pc = 0x1546f; break; }
    ds = pop();
    return;
  case 0x1548b: // 1020:528b
    push(ds);
    r16[ax] = 0xa000;
    ds = r16[ax];
    yield* sub_134f4();
    r16[cx] = 0x0008;
    r16[si] = 0x190f;
    r16[di] = 0x1b17;
  case 0x1549d: // 1020:529d
    r8[al] = memoryAGet(ds, r16[si]);
    memoryASet(ds, 0x0000, r8[al]);
    r8[al] = memoryAGet(ds, r16[di]);
    memoryASet(ds, r16[si], r8[al]);
    r8[al] = memoryAGet(ds, 0x0000);
    memoryASet(ds, r16[di], r8[al]);
    r8[al] = memoryAGet(ds, 0x0001);
    memoryASet(ds, 0x0000, r8[al]);
    r16[si] += 0x0028;
    r16[di] += 0x0028;
    if (--r16[cx])
        { pc = 0x1549d; break; }
    ds = pop();
    return;
  case 0x154bb: // 1020:52bb
    push(ds);
    push(es);
    r16[ax] = 0xb800;
    ds = r16[ax];
    es = r16[ax];
    r16[cx] = 0x0005;
    r16[si] = 0x191e;
    r16[di] = 0x1afe;
  case 0x154cd: // 1020:52cd
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[tx] = memoryAGet16(es, r16[di]); memoryASet16(es, r16[di], r16[ax]); r16[ax] = r16[tx];
    memoryASet16(ds, r16[si], r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 8192);
    r16[tx] = memoryAGet16(es, r16[di] + 8192); memoryASet16(es, r16[di] + 8192, r16[ax]); r16[ax] = r16[tx];
    memoryASet16(ds, r16[si] + 8192, r16[ax]);
    r16[si] += 0x0050;
    r16[di] += 0x0050;
    if (--r16[cx])
        { pc = 0x154cd; break; }
    es = pop();
    ds = pop();
    return;
  }
}
function* sub_154ec() // 1020:52ec
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] != 0x05)
        { pc = 0x15515; break; }
    push(ds);
    r16[dx] = 0x878c;
    push(ds);
    push(es);
    yield* sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, r16[ax]);
    memoryASet16(ds, 0x526c, r16[ax]);
    r16[ax] = 0x000f;
    yield* sub_112ff();
    yield* sub_15757();
    ds = pop();
    return;
  case 0x15515: // 1020:5315
    push(ds);
    r16[dx] = 0x8796;
    push(ds);
    push(es);
    yield* sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, r16[ax]);
    memoryASet16(ds, 0x526c, r16[ax]);
    r16[ax] = 0x000f;
    yield* sub_112ff();
    memoryASet16(cs, 0x6676, 0x6678);
    yield* sub_15677();
    ds = pop();
    return;
  }
}
function* sub_15538() // 1020:5338
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] == 0x05)
        { pc = 0x1554b; break; }
    if (r8[al] >= 0x03)
        { pc = 0x15573; break; }
    { pc = 0x15573; break; }
  case 0x1554b: // 1020:534b
    push(ds);
    r16[dx] = 0x87a3;
    push(ds);
    push(es);
    yield* sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, r16[ax]);
    memoryASet16(ds, 0x526c, r16[ax]);
    if (!memoryAGet(ds, 0x87d3))
        { pc = 0x15566; break; }
    yield* sub_105f2();
  case 0x15566: // 1020:5366
    memoryASet(ds, 0x87d3, 0x01);
    yield* sub_15845();
    yield* sub_15757();
    ds = pop();
    return;
  case 0x15573: // 1020:5373
    push(ds);
    r16[dx] = 0x87ac;
    push(ds);
    push(es);
    yield* sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, r16[ax]);
    memoryASet16(ds, 0x526c, r16[ax]);
    if (!memoryAGet(ds, 0x87d3))
        { pc = 0x1558e; break; }
    yield* sub_105f2();
  case 0x1558e: // 1020:538e
    memoryASet(ds, 0x87d3, 0x01);
    yield* sub_11e30();
    memoryASet16(cs, 0x6676, 0x6698);
    yield* sub_15677();
    ds = pop();
    return;
  }
}
function* sub_155a2() // 1020:53a2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    push(ds);
    r16[dx] = 0x87b8;
    push(ds);
    push(es);
    yield* sub_10b7b();
    es = pop();
    ds = pop();
    memoryASet16(ds, 0x04c1, r16[ax]);
    memoryASet16(ds, 0x526c, r16[ax]);
    yield* sub_15757();
    r16[cx] = 0x0046;
  case 0x155be: // 1020:53be
    yield* sub_13443();
    if (--r16[cx])
        { pc = 0x155be; break; }
    yield* sub_15845();
    ds = pop();
    return;
  }
}
function* sub_155c8() // 1020:53c8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] == 0x05)
        { pc = 0x155d9; break; }
    if (r8[al] < 0x03)
        { pc = 0x155d7; break; }
    { pc = 0x15677; break; }
  case 0x155d7: // 1020:53d7
    { pc = 0x15625; break; }
  case 0x155d9: // 1020:53d9
    push(ds);
    r16[ax] = 0x0013;
    interrupt(0x10);
    yield* sub_11e30();
    yield* sub_13443();
    r16[ax] = 0x168f;
    ds = r16[ax];
    ds = memoryAGet16(ds, 0x526c);
    r16[si] = 0;
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[dx] = 0x03c8;
    r8[al] = 0x00;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r16[cx] = 0x0100;
  case 0x155ff: // 1020:53ff
    r8[al] = lodsb_DSSI();
    { pc = 0x15602; break; }
  case 0x15602: // 1020:5402
    out8(r16[dx], r8[al]);
    r8[al] = lodsb_DSSI();
    { pc = 0x15606; break; }
  case 0x15606: // 1020:5406
    out8(r16[dx], r8[al]);
    r8[al] = lodsb_DSSI();
    { pc = 0x1560a; break; }
  case 0x1560a: // 1020:540a
    out8(r16[dx], r8[al]);
    if (--r16[cx])
        { pc = 0x155ff; break; }
    r16[si] = ds;
    r16[si] += 0x0030;
    ds = r16[si];
    r16[si] = 0;
    r16[cx] = 0x7d00;
    r16[di] = 0;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    yield* sub_13443();
    yield* sub_11e1a();
    ds = pop();
    return;
  case 0x15625: // 1020:5425
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    ds = memoryAGet16(ds, 0x526c);
    { pc = 0x1564d; break; }
  case 0x15639: // 1020:5439
    yield* sub_13360();
    r16[ax] = 0x168f;
    ds = r16[ax];
    ds = memoryAGet16(ds, 0x526c);
    r16[si] = 0;
    r16[ax] = 0x28c8;
    yield* sub_167be();
  case 0x1564d: // 1020:544d
    r16[si] = 0;
    r16[di] = 0;
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[dx] = 0x0064;
  case 0x15659: // 1020:5459
    r16[cx] = 0x0028;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[di] += 0x1fb0;
    r8[cl] = 0x28;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[di] -= 0x2000;
    r16[dx]--;
    if (r16[dx])
        { pc = 0x15659; break; }
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  case 0x15677: // 1020:5477
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x15639; break; }
    r16[ax] = 0x000d;
    interrupt(0x10);
    yield* sub_11e30();
    r16[ax] = 0x168f;
    ds = r16[ax];
    ds = memoryAGet16(ds, 0x526c);
    r16[si] = 0;
    r16[di] = 0;
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
  case 0x156a8: // 1020:54a8
    out16(r16[dx], r16[ax]);
    r16[cx] = 0x0fa0;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[di] = 0;
    r8[ah] <<= 1;
    if (r8[ah] < 0x10)
        { pc = 0x156a8; break; }
    yield* sub_11e1a();
    r16[bp] = pop();
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
}
function* sub_15677() // 1020:5477
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x15677; break; }
  case 0x15639: // 1020:5439
    yield* sub_13360();
    r16[ax] = 0x168f;
    ds = r16[ax];
    ds = memoryAGet16(ds, 0x526c);
    r16[si] = 0;
    r16[ax] = 0x28c8;
    yield* sub_167be();
    r16[si] = 0;
    r16[di] = 0;
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[dx] = 0x0064;
  case 0x15659: // 1020:5459
    r16[cx] = 0x0028;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[di] += 0x1fb0;
    r8[cl] = 0x28;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[di] -= 0x2000;
    r16[dx]--;
    if (r16[dx])
        { pc = 0x15659; break; }
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    return;
  case 0x15677: // 1020:5477
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    if (memoryAGet(cs, 0x0001) < 0x03)
        { pc = 0x15639; break; }
    r16[ax] = 0x000d;
    interrupt(0x10);
    yield* sub_11e30();
    r16[ax] = 0x168f;
    ds = r16[ax];
    ds = memoryAGet16(ds, 0x526c);
    r16[si] = 0;
    r16[di] = 0;
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[dx] = 0x03c4;
    r16[ax] = 0x0102;
  case 0x156a8: // 1020:54a8
    out16(r16[dx], r16[ax]);
    r16[cx] = 0x0fa0;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[di] = 0;
    r8[ah] <<= 1;
    if (r8[ah] < 0x10)
        { pc = 0x156a8; break; }
    yield* sub_11e1a();
    r16[bp] = pop();
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
}
function* sub_15757() // 1020:5557
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x15757; break; }
  case 0x156c4: // 1020:54c4
    yield* sub_13360();
    yield* sub_1582d();
    r16[bx] = 0x66e0;
    r16[ax] = 0xb800;
    es = r16[ax];
    r16[di] = 0;
    r8[dl] = 0xc8;
  case 0x156d6: // 1020:54d6
    r8[ch] = 0x50;
  case 0x156d8: // 1020:54d8
    r8[ah] = 0;
    r8[cl] = 0x04;
  case 0x156dc: // 1020:54dc
    r8[al] = lodsb_DSSI();
    r8[al] = memoryAGet(cs, r16[bx] + r8[al]);
    flags.carry = !!(r8[al] & 0x80);
    r8[al] <<= 1;
    r8[ah] = rcl8(r8[ah], 0x01);
    flags.carry = !!(r8[al] & 0x80);
    r8[al] <<= 1;
    r8[ah] = rcl8(r8[ah], 0x01);
    r8[cl]--;
    if (r8[cl])
        { pc = 0x156dc; break; }
    memoryASet(es, r16[di], r8[ah]);
    r16[di]++;
    r8[ch]--;
    if (r8[ch])
        { pc = 0x156d8; break; }
    if (r16s[di] < signed16(0x2000))
        { pc = 0x156ff; break; }
    r16[di] -= 0x2000;
    { pc = 0x15703; break; }
  case 0x156ff: // 1020:54ff
    r16[di] += 0x1fb0;
  case 0x15703: // 1020:5503
    r8[dl]--;
    if (r8[dl])
        { pc = 0x156d6; break; }
    return;
  case 0x15708: // 1020:5508
    r16[ax] = 0x000d;
    interrupt(0x10);
    yield* sub_11e30();
    yield* sub_1582d();
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[bl] = 0x01;
  case 0x1571c: // 1020:551c
    r8[al] = r8[bl];
    out8(r16[dx], r8[al]);
  case 0x1571f: // 1020:551f
    r8[ah] = 0;
    r8[cl] = 0x08;
  case 0x15723: // 1020:5523
    r8[al] = lodsb_DSSI();
    flags.carry = false;
    if (!(r8[bl] & r8[al]))
        { pc = 0x15729; break; }
    flags.carry = 1;
  case 0x15729: // 1020:5529
    r8[ah] = rcl8(r8[ah], 0x01);
    r8[cl]--;
    if (r8[cl])
        { pc = 0x15723; break; }
    r8[al] = r8[ah];
    stosb_ESDI(r8[al]);
    if (r16[si] < 0xfa00)
        { pc = 0x1571f; break; }
    r16[di] = 0;
    r16[si] -= 0xfa00;
    r8[bl] <<= 1;
    if (r8[bl] < 0x10)
        { pc = 0x1571c; break; }
    r16[ax] = 0x168f;
    es = r16[ax];
    r16[dx] = 0x87c2;
    r16[ax] = 0x1002;
    interrupt(0x10);
    yield* sub_11e1a();
    return;
    // gap 1 bytes // gap 1 bytes
  case 0x15757: // 1020:5557
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] == 0x05)
        { pc = 0x15766; break; }
    if (r8[al] >= 0x03)
        { pc = 0x15708; break; }
    { pc = 0x156c4; break; }
  case 0x15766: // 1020:5566
    push(ds);
    r16[ax] = 0x0013;
    interrupt(0x10);
    yield* sub_11e30();
    yield* sub_13443();
    r16[dx] = 0x03c8;
    r8[al] = 0x00;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r16[cx] = 0x0300;
  case 0x1577c: // 1020:557c
    out8(r16[dx], r8[al]);
    if (--r16[cx])
        { pc = 0x1577c; break; }
    yield* sub_1582d();
    r16[cx] = 0x7d00;
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    yield* sub_13443();
    yield* sub_11e1a();
    r16[si] = ds;
    r16[si] -= 0x0030;
    ds = r16[si];
  case 0x15794: // 1020:5594
    memoryASet(cs, 0x5556, 0x00);
    r16[si] = 0;
    r16[bp] = 0;
  case 0x1579e: // 1020:559e
    if (memoryAGet(cs, 0x5556) & 0x0f)
        { pc = 0x157a9; break; }
    yield* sub_13443();
  case 0x157a9: // 1020:55a9
    if (!memoryAGet(cs, 0x0003))
        { pc = 0x1581d; break; }
    r16[dx] = 0x03c7;
    r8[al] = memoryAGet(cs, 0x5556);
    out8(r16[dx], r8[al]);
    r8[dl] = 0xc9;
    { pc = 0x157bd; break; }
  case 0x157bd: // 1020:55bd
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x3f;
    r8[ah] = r8[al];
    { pc = 0x157c4; break; }
  case 0x157c4: // 1020:55c4
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x3f;
    r8[bl] = r8[al];
    { pc = 0x157cb; break; }
  case 0x157cb: // 1020:55cb
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x3f;
    r8[bh] = r8[al];
    r8[dl] = 0xc8;
    r8[al] = memoryAGet(cs, 0x5556);
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = r8[ah];
    if (memoryAGet(ds, r16[si]) <= r8[al])
        { pc = 0x157e5; break; }
    if (r8[al] > 0x3d)
        { pc = 0x157e5; break; }
    r8[al] += 0x02;
    r16[bp]++;
  case 0x157e5: // 1020:55e5
    out8(r16[dx], r8[al]);
    r8[al] = r8[bl];
    if (memoryAGet(ds, r16[si] + 1) <= r8[al])
        { pc = 0x157f4; break; }
    if (r8[al] > 0x3d)
        { pc = 0x157f4; break; }
    r8[al] += 0x02;
    r16[bp]++;
  case 0x157f4: // 1020:55f4
    out8(r16[dx], r8[al]);
    r8[al] = r8[bh];
    if (memoryAGet(ds, r16[si] + 2) <= r8[al])
        { pc = 0x15803; break; }
    if (r8[al] > 0x3d)
        { pc = 0x15803; break; }
    r8[al] += 0x02;
    r16[bp]++;
  case 0x15803: // 1020:5603
    out8(r16[dx], r8[al]);
    r16[si] += 0x0003;
    memoryASet(cs, 0x5556, memoryAGet(cs, 0x5556) + 1);
    if (memoryAGet(cs, 0x5556) < 0x40)
        { pc = 0x1579e; break; }
    if (!r16[bp])
        { pc = 0x1581b; break; }
    { pc = 0x15794; break; }
  case 0x1581b: // 1020:561b
    { pc = 0x1582b; break; }
  case 0x1581d: // 1020:561d
    r16[dx] = 0x03c8;
    r8[al] = 0x00;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r16[cx] = 0x00c0;
  case 0x15827: // 1020:5627
    r8[al] = lodsb_DSSI();
    out8(r16[dx], r8[al]);
    if (--r16[cx])
        { pc = 0x15827; break; }
  case 0x1582b: // 1020:562b
    ds = pop();
    return;
  }
}
function* sub_1582d() // 1020:562d
{
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[si] = memoryAGet16(ds, 0x526c);
    r16[si] += 0x0030;
    ds = r16[si];
    r16[si] = 0;
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[di] = 0;
}
function* sub_15845() // 1020:5645
{
  var pc = 0x15845;
  while (1) switch(pc)
  {
  case 0x15845: // 1020:5645
    if (!memoryAGet(cs, 0x0003))
        { pc = 0x158cb; break; }
    r8[al] = memoryAGet(cs, 0x0001);
    if (r8[al] == 0x05)
        { pc = 0x15856; break; }
    return;
  case 0x15856: // 1020:5656
    memoryASet(cs, 0x5556, 0x00);
    r16[bp] = 0;
  case 0x1585e: // 1020:565e
    if (memoryAGet(cs, 0x5556) & 0x0f)
        { pc = 0x15869; break; }
    yield* sub_13443();
  case 0x15869: // 1020:5669
    r16[dx] = 0x03c7;
    r8[al] = memoryAGet(cs, 0x5556);
    out8(r16[dx], r8[al]);
    r8[dl] = 0xc9;
    { pc = 0x15875; break; }
  case 0x15875: // 1020:5675
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x3f;
    r8[ah] = r8[al];
    { pc = 0x1587c; break; }
  case 0x1587c: // 1020:567c
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x3f;
    r8[bl] = r8[al];
    { pc = 0x15883; break; }
  case 0x15883: // 1020:5683
    r8[al] = in8(r16[dx]);
    r8[al] &= 0x3f;
    r8[bh] = r8[al];
    r8[dl] = 0xc8;
    r8[al] = memoryAGet(cs, 0x5556);
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = r8[ah];
    flags.carry = r8[al] < 0x01;
    r8[al]--;
    r8[al] += (0x00 + flags.carry);
    flags.carry = r8[al] < 0x01;
    r8[al]--;
    r8[al] += (0x00 + flags.carry);
    r16[bp] |= r16[ax];
    out8(r16[dx], r8[al]);
    r8[al] = r8[bl];
    flags.carry = r8[al] < 0x01;
    r8[al]--;
    r8[al] += (0x00 + flags.carry);
    flags.carry = r8[al] < 0x01;
    r8[al]--;
    r8[al] += (0x00 + flags.carry);
    r16[bp] |= r16[ax];
    out8(r16[dx], r8[al]);
    r8[al] = r8[bh];
    flags.carry = r8[al] < 0x01;
    r8[al]--;
    r8[al] += (0x00 + flags.carry);
    flags.carry = r8[al] < 0x01;
    r8[al]--;
    r8[al] += (0x00 + flags.carry);
    r16[bp] |= r16[ax];
    out8(r16[dx], r8[al]);
    memoryASet(cs, 0x5556, memoryAGet(cs, 0x5556) + 1);
    if (memoryAGet(cs, 0x5556) < 0x40)
        { pc = 0x1585e; break; }
    if (!r16[bp])
        { pc = 0x158cb; break; }
    { pc = 0x15845; break; }
  case 0x158cb: // 1020:56cb
    return;
  }
}
function* sub_158cc() // 1020:56cc
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[si]);
    push(r16[cx]);
    push(r16[bx]);
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[si] = 0x7699;
    r16[cx] = 0x0032;
    memoryASet(ds, 0x64fd, 0x00);
  case 0x158df: // 1020:56df
    r16[di] = 0x87d3;
    r16[ax] = memoryAGet16(ds, r16[si] + 4);
    if (r16[ax] == 0xffff)
        { pc = 0x15900; break; }
    r8[ah] &= 0x1f;
  case 0x158ed: // 1020:56ed
    r16[di]++;
    r16[di]++;
    if (memoryAGet16(ds, r16[di]) != r16[ax])
        { pc = 0x158ed; break; }
    memoryASet16(ds, r16[si] + 10, r16[di]);
    r16[di] = r16[ax];
    r8[al] = memoryAGet(ds, r16[di] + 28869);
    memoryASet(ds, 0x64fd, memoryAGet(ds, 0x64fd) + r8[al]);
  case 0x15900: // 1020:5700
    r16[si] += 0x001a;
    if (--r16[cx])
        { pc = 0x158df; break; }
    r16[si] = 0x7dcb;
    r16[cx] = 0x000a;
  case 0x1590b: // 1020:570b
    r16[ax] = memoryAGet16(ds, r16[si] + 12);
    memoryASet16(ds, r16[si], r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    r8[al] = memoryAGet(ds, r16[si] + 16);
    memoryASet(ds, r16[si] + 6, r8[al]);
    memoryASet16(ds, r16[si] + 17, 0x0000);
    r16[si] += 0x0014;
    if (--r16[cx])
        { pc = 0x1590b; break; }
    r8[bl] = memoryAGet(ds, 0x5250);
    r8[bh] = 0;
    r8[al] = memoryAGet(ds, r16[bx] + 20660);
    memoryASet(ds, 0x64e8, r8[al]);
    r16[bx] = pop();
    r16[cx] = pop();
    r16[si] = pop();
    return;
  }
}
function* sub_15937() // 1020:5737
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    sp -= 2;
    r16[si] = 0x7699;
    r16[di] = 0x5570;
    r16[bp] = 0xffff;
    memoryASet16(ds, 0x5574, r16[bp]);
    memoryASet16(ds, 0x5586, r16[bp]);
    memoryASet16(ds, 0x5598, r16[bp]);
    memoryASet16(ds, 0x55aa, r16[bp]);
    memoryASet16(ds, 0x55bc, r16[bp]);
    memoryASet16(ds, 0x55ce, r16[bp]);
    memoryASet16(ds, 0x55e0, r16[bp]);
    memoryASet16(ds, 0x55f2, r16[bp]);
    r16[ax] = memoryAGet16(ds, 0x5270);
    r16[dx] = memoryAGet16(ds, 0x5272);
    r8[cl] = 0x04;
    r16[ax] <<= r8[cl];
    r16[dx] <<= r8[cl];
    r16[cx] = 0x0032;
  case 0x15970: // 1020:5770
    if (memoryAGet16(ds, r16[si] + 4) != r16[bp])
        { pc = 0x15978; break; }
    { pc = 0x15aa6; break; }
  case 0x15978: // 1020:5778
    memoryASet(ds, r16[si] + 5, memoryAGet(ds, r16[si] + 5) & 0xdf);
    r16[bx] = memoryAGet16(ds, r16[si]);
    r16[bx] += 0x0020;
    flags.carry = r16[bx] < r16[ax];
    r16[bx] -= r16[ax];
    if (!flags.carry)
        { pc = 0x15988; break; }
    { pc = 0x15a9d; break; }
  case 0x15988: // 1020:5788
    r16[bx] -= 0x0040;
    if (r16s[bx] <= signed16(0x0140))
        { pc = 0x15994; break; }
    { pc = 0x15a9d; break; }
  case 0x15994: // 1020:5794
    r16[bx] = memoryAGet16(ds, r16[si] + 2);
    flags.carry = r16[bx] < r16[dx];
    r16[bx] -= r16[dx];
    if (!flags.carry)
        { pc = 0x1599e; break; }
    { pc = 0x15a9d; break; }
  case 0x1599e: // 1020:579e
    r16[bx] -= 0x0020;
    if (r16s[bx] <= signed16(0x00c0))
        { pc = 0x159aa; break; }
    { pc = 0x15a9d; break; }
  case 0x159aa: // 1020:57aa
    memoryASet(ds, r16[si] + 5, memoryAGet(ds, r16[si] + 5) | 0x20);
    push(r16[ax]);
    push(r16[dx]);
    yield* sub_166ff();
    memoryASet16(ds, r16[di] + 9, r16[si]);
    r16[bx] = memoryAGet16(ds, r16[si]);
    memoryASet16(ds, r16[di], r16[bx]);
    r16[bx] = memoryAGet16(ds, r16[si] + 2);
    memoryASet16(ds, r16[di] + 2, r16[bx]);
    push(r16[cx]);
    push(r16[si]);
    if (!(memoryAGet(ds, r16[si] + 7) & 0xc0))
        { pc = 0x159cb; break; }
    { pc = 0x15a91; break; }
  case 0x159cb: // 1020:57cb
    if (memoryAGet(ds, 0x6514))
        { pc = 0x159e8; break; }
    if (memoryAGet16(ds, r16[si] + 4) != 0x05aa)
        { pc = 0x159dc; break; }
    { pc = 0x15a91; break; }
  case 0x159dc: // 1020:57dc
    r16[bx] = memoryAGet16(ds, r16[si] + 6);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: yield* sub_15c04(); break;
        case 2: yield* sub_15c04(); break;
        case 4: yield* sub_15c04(); break;
        case 6: yield* sub_15c04(); break;
        case 8: yield* sub_15c04(); break;
        case 10: yield* sub_15c04(); break;
        case 12: yield* sub_15c04(); break;
        case 14: yield* sub_15c04(); break;
        case 16: yield* sub_15c04(); break;
        case 18: yield* sub_15c04(); break;
        case 20: yield* sub_15c04(); break;
        case 22: yield* sub_15c04(); break;
        case 24: yield* sub_15c04(); break;
        case 26: yield* sub_15c04(); break;
        case 28: yield* sub_15c04(); break;
        case 30: yield* sub_15c03(); break;
        case 32: yield* sub_15c03(); break;
        case 34: yield* sub_15c03(); break;
        case 36: yield* sub_15c04(); break;
        default:
            stop("ind 1020:57e4");
    }
  case 0x159e8: // 1020:57e8
    if (!memoryAGet(ds, 0x6511))
        { pc = 0x15a25; break; }
    r16[si] = 0x52a0;
    r16[cx] = 0x0028;
  case 0x159f5: // 1020:57f5
    if (memoryAGet16(ds, r16[si] + 6))
        { pc = 0x15a0a; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    if (!r16[ax])
        { pc = 0x15a20; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 12);
    if (r16[ax] < 0x000a)
        { pc = 0x15a20; break; }
  case 0x15a0a: // 1020:580a
    r16[ax] = r16[bx];
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    flags.zero = !(memoryAGet(ds, r16[bx] + 28441) & 0x10);
    r16[bx] = r16[ax];
    if (!flags.zero)
        { pc = 0x15a20; break; }
    yield* sub_15295();
    if (flags.carry)
        { pc = 0x15a4e; break; }
  case 0x15a20: // 1020:5820
    r16[si] += 0x0012;
    if (--r16[cx])
        { pc = 0x159f5; break; }
  case 0x15a25: // 1020:5825
    if (!memoryAGet(ds, 0x650a))
        { pc = 0x15a91; break; }
    if (memoryAGet(ds, 0x6509))
        { pc = 0x15a91; break; }
    r16[si] = 0x528e;
    if (memoryAGet16(ds, r16[si] + 4) == 0xffff)
        { pc = 0x15a91; break; }
    yield* sub_15295();
    if (!flags.carry)
        { pc = 0x15a91; break; }
    memoryASet(ds, 0x651b, 0x00);
    memoryASet16(ds, r16[si] + 4, 0xffff);
    yield* sub_15ab0();
  case 0x15a4e: // 1020:584e
    if (memoryAGet(ds, r16[si] + 4) == 0x49)
        { pc = 0x15a57; break; }
    memoryASet16(ds, r16[si] + 6, -memoryAGet16(ds, r16[si] + 6));
  case 0x15a57: // 1020:5857
    r8[al] = 0x01;
    yield* sub_113e6();
    memoryASet(ds, 0x650a, 0x00);
    r16[bx] = memoryAGet16(ds, r16[di] + 4);
    r8[bh] &= 0x1f;
    if (!memoryAGet(ds, r16[bx] + 28768))
        { pc = 0x15a88; break; }
    if (memoryAGet(ds, 0x651b))
        { pc = 0x15a91; break; }
    memoryASet(ds, 0x651b, 0x0a);
    memoryASet(ds, r16[di] + 5, memoryAGet(ds, r16[di] + 5) | 0x40);
    memoryASet(ds, 0x64e8, memoryAGet(ds, 0x64e8) - 1);
    if (memoryAGet(ds, 0x64e8))
        { pc = 0x15a91; break; }
    memoryASet(ds, 0x64fd, memoryAGet(ds, 0x64fd) - 1);
  case 0x15a88: // 1020:5888
    r16[bp] = sp;
    r16[si] = memoryAGet16(ss, r16[bp]);
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x80);
  case 0x15a91: // 1020:5891
    r16[si] = pop();
    r16[cx] = pop();
    r16[bp] = 0xffff;
    r16[di] += 0x0012;
    r16[dx] = pop();
    r16[ax] = pop();
    { pc = 0x15aa6; break; }
  case 0x15a9d: // 1020:589d
    if (!(memoryAGet(ds, r16[si] + 7) & 0xc0))
        { pc = 0x15aa6; break; }
    memoryASet16(ds, r16[si] + 4, r16[bp]);
  case 0x15aa6: // 1020:58a6
    r16[si] += 0x001a;
    r16[cx]--;
    if (!r16[cx])
        { pc = 0x15aaf; break; }
    { pc = 0x15970; break; }
  case 0x15aaf: // 1020:58af
    sp += 2; return;
    return;
  }
}
function* sub_15ab0() // 1020:58b0
{
    memoryASet16(ds, 0x5292, 0x002d);
    memoryASet16(ds, 0x5294, 0x0000);
    memoryASet16(ds, 0x529c, 0x0000);
    memoryASet(ds, 0x6515, 0x05);
}
function* sub_15ac8() // 1020:58c8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[si] = 0x5600;
    r16[dx] = 0x0004;
    r8[cl] = 0x04;
  case 0x15ad0: // 1020:58d0
    if (memoryAGet16(ds, r16[si] + 4) == 0xffff)
        { pc = 0x15b26; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 6);
    flags.zero = !(r16[ax] | r16[ax]);
    if (flags.zero)
        { pc = 0x15af0; break; }
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) + r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] >>= r8[cl];
    flags.carry = r16[ax] < memoryAGet16(ds, 0x5270);
    r16[ax] -= memoryAGet16(ds, 0x5270);
    if (flags.carry)
        { pc = 0x15b0a; break; }
    flags.zero = r16[ax] == 0x0014;
    if (r16s[ax] > signed16(0x0014))
        { pc = 0x15b0a; break; }
  case 0x15af0: // 1020:58f0
    r16[ax] = memoryAGet16(ds, r16[si] + 14);
    if (flags.zero)
        { pc = 0x15b11; break; }
    r16[ax] = sar16(r16[ax], r8[cl]);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] >>= r8[cl];
    flags.carry = r16[ax] < memoryAGet16(ds, 0x5272);
    r16[ax] -= memoryAGet16(ds, 0x5272);
    if (flags.carry)
        { pc = 0x15b0a; break; }
    if (r16s[ax] <= signed16(0x00c0))
        { pc = 0x15b11; break; }
  case 0x15b0a: // 1020:590a
    memoryASet16(ds, r16[si] + 4, 0xffff);
    { pc = 0x15b26; break; }
  case 0x15b11: // 1020:5911
    r16[di] = 0x527c;
    yield* sub_15295();
    if (!flags.carry)
        { pc = 0x15b26; break; }
    r16[bp] = 0x0046;
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, r16[si] + 6);
    yield* sub_15b6f();
    { pc = 0x15b0a; break; }
  case 0x15b26: // 1020:5926
    r16[si] += 0x0012;
    r16[dx]--;
    if (r16[dx])
        { pc = 0x15ad0; break; }
    return;
  }
}
function* sub_15b2d() // 1020:592d +returnCarry
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[di] = 0x5600;
    push(r16[cx]);
    r16[cx] = 0x0004;
  case 0x15b34: // 1020:5934
    if (memoryAGet16(ds, r16[di] + 4) != 0xffff)
        { pc = 0x15b3d; break; }
    r16[cx] = pop();
    flags.carry = 0;
    return;
  case 0x15b3d: // 1020:593d
    r16[di] += 0x0012;
    if (--r16[cx])
        { pc = 0x15b34; break; }
    r16[cx] = pop();
    flags.carry = 1;
    return;
  }
}
function* sub_15b45() // 1020:5945
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x168f;
    ds = r16[ax];
    memoryASet16(ds, 0x8eb3, 0x0032);
    r16[si] = 0x7699;
  case 0x15b53: // 1020:5953
    if (memoryAGet16(ds, r16[si] + 4) == 0xffff)
        { pc = 0x15b65; break; }
    r16[bx] = memoryAGet16(ds, r16[si] + 6);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    switch (r16[bx])
    {
        case 0: yield* sub_165bf(); break;
        case 2: yield* sub_165bf(); break;
        case 4: yield* sub_165f1(); break;
        case 6: yield* sub_164c9(); break;
        case 8: yield* sub_164c9(); break;
        case 10: yield* sub_1642e(); break;
        case 12: yield* sub_1642e(); break;
        case 14: yield* sub_162e0(); break;
        case 16: yield* sub_1620f(); break;
        case 18: yield* sub_160f2(); break;
        case 20: yield* sub_15fce(); break;
        case 22: yield* sub_15eca(); break;
        case 24: yield* sub_15e60(); break;
        case 26: yield* sub_15dbb(); break;
        case 28: yield* sub_16209(); break;
        case 30: yield* sub_161f9(); break;
        case 32: yield* sub_161fe(); break;
        case 34: yield* sub_15d4e(); break;
        case 36: yield* sub_15cb8(); break;
        case 38: yield* sub_15c04(); break;
        case 40: yield* sub_15c04(); break;
        case 42: yield* sub_15c04(); break;
        case 44: yield* sub_15c04(); break;
        case 46: yield* sub_15c04(); break;
        case 48: yield* sub_15c04(); break;
        case 50: yield* sub_15c04(); break;
        case 52: yield* sub_15c04(); break;
        case 54: yield* sub_15c04(); break;
        case 56: yield* sub_15c04(); break;
        case 58: yield* sub_15c04(); break;
        case 60: yield* sub_15c04(); break;
        case 62: yield* sub_15c04(); break;
        case 64: yield* sub_15c04(); break;
        case 66: yield* sub_15c04(); break;
        case 68: yield* sub_15c03(); break;
        case 70: yield* sub_15c03(); break;
        case 72: yield* sub_15c03(); break;
        case 74: yield* sub_15c04(); break;
        default:
            stop("ind 1020:5961");
    }
  case 0x15b65: // 1020:5965
    r16[si] += 0x001a;
    memoryASet16(ds, 0x8eb3, memoryAGet16(ds, 0x8eb3) - 1);
    if (memoryAGet16(ds, 0x8eb3))
        { pc = 0x15b53; break; }
    return;
  }
}
function* sub_15b6f() // 1020:596f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    r8[al] = 0x04;
    yield* sub_113e6();
    r16[ax] = pop();
    yield* sub_15bcc();
    yield* sub_15bcc();
    memoryASet(ds, 0x6514, 0x18);
    memoryASet(ds, 0x6513, 0x00);
    memoryASet(ds, 0x5287, 0x00);
    if (signed16(memoryAGet16(ds, 0x527c)) > r16s[ax])
        { pc = 0x15b93; break; }
    r16[bp] = -r16[bp];
  case 0x15b93: // 1020:5993
    memoryASet16(ds, 0x5282, r16[bp]);
    memoryASet16(ds, 0x528a, 0xff80);
    yield* sub_14ce9();
    return;
  }
}
function* sub_15ba1() // 1020:59a1
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memoryASet(ds, 0x6506, 0x32);
    memoryASet(ds, 0x0419, memoryAGet(ds, 0x0419) + 1);
    if (memoryAGet(ds, 0x0419) <= 0x10)
        { pc = 0x15bba; break; }
    memoryASet(ds, 0x0419, 0x10);
    memoryASet(ds, 0x041a, memoryAGet(ds, 0x041a) + 1);
  case 0x15bba: // 1020:59ba
    return;
  }
}
function* sub_15bcc() // 1020:59cc
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memoryASet(ds, 0x6506, 0x32);
    if (memoryAGet(ds, 0x6516))
        { pc = 0x15be6; break; }
    memoryASet(ds, 0x0419, memoryAGet(ds, 0x0419) - 1);
    if (signed8(memoryAGet(ds, 0x0419)) >= 0)
        { pc = 0x15be6; break; }
    memoryASet(ds, 0x0419, 0x00);
    yield* sub_15be7();
  case 0x15be6: // 1020:59e6
    return;
  }
}
function* sub_15be7() // 1020:59e7
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memoryASet(ds, 0x6516, 0x0a);
    if (!memoryAGet(ds, 0x041b))
        { pc = 0x15bfd; break; }
    memoryASet(ds, 0x041b, memoryAGet(ds, 0x041b) - 1);
    memoryASet(ds, 0x6506, 0x00);
    return;
  case 0x15bfd: // 1020:59fd
    memoryASet(ds, 0x6517, 0x01);
    return;
  }
}
function* sub_15c03() // 1020:5a03
{
}
function* sub_15c04() // 1020:5a04
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    r16[si] = 0x527c;
    yield* sub_15295();
    if (!flags.carry)
        { pc = 0x15c40; break; }
    r16[bx] = memoryAGet16(ds, r16[di] + 9);
    if (memoryAGet(ds, r16[bx] + 6) == 0x0b)
        { pc = 0x15c2c; break; }
    r16[ax] = memoryAGet16(ds, r16[bx] + 4);
    r8[ah] &= 0x1f;
    if (r16[ax] == 0x00b2)
        { pc = 0x15c2c; break; }
    memoryASet16(ds, r16[bx] + 8, -memoryAGet16(ds, r16[bx] + 8));
  case 0x15c2c: // 1020:5a2c
    r16[ax] = memoryAGet16(ds, r16[di] + 4);
    r8[ah] &= 0x1f;
    r16[ax] -= 0x009a;
    if (r16[ax] > 0x0002)
        { pc = 0x15c3f; break; }
    memoryASet(ds, 0x6501, 0x01);
  case 0x15c3f: // 1020:5a3f
    flags.carry = 1;
  case 0x15c40: // 1020:5a40
    r16[bp] = pop();
    es = pop();
    ds = pop();
    r16[si] = pop();
    r16[di] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    if (!flags.carry)
        { pc = 0x15c57; break; }
    r16[bp] = memoryAGet16(ds, r16[si] + 12);
    if (!r16[bp])
        { pc = 0x15c57; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    yield* sub_15b6f();
  case 0x15c57: // 1020:5a57
    return;
  }
}
function* sub_15cb8() // 1020:5ab8
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x15cb8; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
  case 0x15cb8: // 1020:5ab8
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x15cc1; break; }
    { pc = 0x15c58; break; }
  case 0x15cc1: // 1020:5ac1
    r16[ax] = memoryAGet16(ds, r16[si] + 20);
    r16[dx] = memoryAGet16(ds, r16[si] + 15);
    r16[ax] -= r16[dx];
    if (signed16(memoryAGet16(ds, 0x527c)) < r16s[ax])
        { pc = 0x15d21; break; }
    r16[ax] += r16[dx];
    r16[ax] += r16[dx];
    if (signed16(memoryAGet16(ds, 0x527c)) > r16s[ax])
        { pc = 0x15d21; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 22);
    r16[dx] = memoryAGet16(ds, r16[si] + 17);
    r16[ax] -= r16[dx];
    if (signed16(memoryAGet16(ds, 0x527e)) < r16s[ax])
        { pc = 0x15d21; break; }
    r16[ax] += r16[dx];
    r16[ax] += r16[dx];
    if (signed16(memoryAGet16(ds, 0x527e)) > r16s[ax])
        { pc = 0x15d21; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    if (r16s[ax] >= 0)
        { pc = 0x15cfa; break; }
    r16[ax] = -r16[ax];
  case 0x15cfa: // 1020:5afa
    r16[dx] = memoryAGet16(ds, r16[si]);
    if (memoryAGet16(ds, 0x527c) == r16[dx])
        { pc = 0x15d0b; break; }
    if (signed16(memoryAGet16(ds, 0x527c)) < r16s[dx])
        { pc = 0x15d06; break; }
    r16[ax] = -r16[ax];
  case 0x15d06: // 1020:5b06
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
  case 0x15d0b: // 1020:5b0b
    r8[al] = memoryAGet(ds, r16[si] + 19);
    r16[dx] = memoryAGet16(ds, r16[si] + 2);
    if (memoryAGet16(ds, 0x527e) == r16[dx])
        { pc = 0x15d1f; break; }
    if (signed16(memoryAGet16(ds, 0x527e)) < r16s[dx])
        { pc = 0x15d1b; break; }
    r8[al] = -r8[al];
  case 0x15d1b: // 1020:5b1b
    cbw();
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) - r16[ax]);
  case 0x15d1f: // 1020:5b1f
    { pc = 0x15d4d; break; }
  case 0x15d21: // 1020:5b21
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    if (r16s[ax] >= 0)
        { pc = 0x15d2a; break; }
    r16[ax] = -r16[ax];
  case 0x15d2a: // 1020:5b2a
    r16[dx] = memoryAGet16(ds, r16[si]);
    if (memoryAGet16(ds, r16[si] + 20) == r16[dx])
        { pc = 0x15d3a; break; }
    if (signed16(memoryAGet16(ds, r16[si] + 20)) < r16s[dx])
        { pc = 0x15d35; break; }
    r16[ax] = -r16[ax];
  case 0x15d35: // 1020:5b35
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
  case 0x15d3a: // 1020:5b3a
    r8[al] = memoryAGet(ds, r16[si] + 19);
    r16[dx] = memoryAGet16(ds, r16[si] + 2);
    if (memoryAGet16(ds, r16[si] + 22) == r16[dx])
        { pc = 0x15d4d; break; }
    if (signed16(memoryAGet16(ds, r16[si] + 22)) < r16s[dx])
        { pc = 0x15d49; break; }
    r8[al] = -r8[al];
  case 0x15d49: // 1020:5b49
    cbw();
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) - r16[ax]);
  case 0x15d4d: // 1020:5b4d
    return;
  }
}
function* sub_15d4e() // 1020:5b4e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) & 0x3f);
    r16[ax] = memoryAGet16(ds, r16[si] + 19);
    r16[ax]++;
    if (memoryAGet16(ds, r16[si] + 17) > r16[ax])
        { pc = 0x15db7; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, 0x527c);
    if (r16s[ax] >= 0)
        { pc = 0x15d65; break; }
    r16[ax] = -r16[ax];
  case 0x15d65: // 1020:5b65
    if (memoryAGet16(ds, r16[si] + 15) < r16[ax])
        { pc = 0x15db5; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (signed16(memoryAGet16(ds, r16[si] + 21)) < r16s[ax])
        { pc = 0x15dba; break; }
    r16[di] = 0x528e;
    r16[ax] = 0xffff;
  case 0x15d7b: // 1020:5b7b
    r16[di] += 0x0012;
    if (memoryAGet16(ds, r16[di] + 4) != r16[ax])
        { pc = 0x15d7b; break; }
    if (r16[di] >= 0x5570)
        { pc = 0x15db5; break; }
    yield* sub_166df();
    r16[bx] = memoryAGet16(ds, r16[si] + 10);
    r16[ax] = memoryAGet16(ds, r16[bx]);
    r8[ah] &= 0x1f;
    r8[ah] |= 0x80;
    memoryASet16(ds, r16[di] + 4, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si]);
    memoryASet16(ds, r16[di], r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    memoryASet16(ds, r16[di] + 2, r16[ax]);
    memoryASet(ds, r16[di] + 11, 0x03);
    memoryASet16(ds, r16[di] + 14, 0x0000);
    memoryASet(ds, 0x6511, 0x04);
    yield* sub_166ef();
  case 0x15db5: // 1020:5bb5
    r16[ax] = 0;
  case 0x15db7: // 1020:5bb7
    memoryASet16(ds, r16[si] + 19, r16[ax]);
  case 0x15dba: // 1020:5bba
    return;
  }
}
function* sub_15dbb() // 1020:5bbb
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x15dbb; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 259 bytes // gap 259 bytes
  case 0x15dbb: // 1020:5bbb
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x15dc5; break; }
    { pc = 0x15c58; break; }
  case 0x15dc5: // 1020:5bc5
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x15e07; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    if (r16s[ax] >= 0)
        { pc = 0x15dd5; break; }
    r16[ax] = -r16[ax];
  case 0x15dd5: // 1020:5bd5
    r16[dx] = memoryAGet16(ds, 0x527c);
    r16[dx] -= memoryAGet16(ds, r16[si]);
    if (r16s[dx] >= 0)
        { pc = 0x15de1; break; }
    r16[ax] = -r16[ax];
    r16[dx] = -r16[dx];
  case 0x15de1: // 1020:5be1
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    if (memoryAGet16(ds, r16[si] + 23) < r16[dx])
        { pc = 0x15e5f; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x15df5; break; }
    r16[ax] = -r16[ax];
  case 0x15df5: // 1020:5bf5
    if (r16[ax] > 0x0028)
        { pc = 0x15e5f; break; }
    yield* sub_166df();
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    memoryASet16(ds, r16[si] + 21, 0x000a);
    { pc = 0x15e5f; break; }
  case 0x15e07: // 1020:5c07
    if (r8[al] != 0x01)
        { pc = 0x15e23; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 21);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) - r16[ax]);
    memoryASet16(ds, r16[si] + 21, memoryAGet16(ds, r16[si] + 21) - 1);
    if (memoryAGet16(ds, r16[si] + 21))
        { pc = 0x15e5f; break; }
    yield* sub_166df();
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    { pc = 0x15e5f; break; }
  case 0x15e23: // 1020:5c23
    if (r8[al] != 0x02)
        { pc = 0x15e49; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 21);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    memoryASet16(ds, r16[si] + 21, memoryAGet16(ds, r16[si] + 21) + 1);
    if (memoryAGet16(ds, r16[si] + 21) <= 0x000a)
        { pc = 0x15e5f; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    yield* sub_166df();
    r8[al] = memoryAGet(ds, r16[si] + 20);
    memoryASet(ds, r16[si] + 21, r8[al]);
    { pc = 0x15e5f; break; }
  case 0x15e49: // 1020:5c49
    if (r8[al] != 0x03)
        { pc = 0x15e5f; break; }
    memoryASet(ds, r16[si] + 21, memoryAGet(ds, r16[si] + 21) - 1);
    if (memoryAGet(ds, r16[si] + 21))
        { pc = 0x15e5f; break; }
    yield* sub_166ef();
    yield* sub_166ef();
    yield* sub_166ef();
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15e5f: // 1020:5c5f
    return;
  }
}
function* sub_15e60() // 1020:5c60
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) & 0x3f);
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x15e80; break; }
    yield* sub_166df();
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    memoryASet16(ds, r16[si] + 17, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    memoryASet16(ds, r16[si] + 20, r16[ax]);
    memoryASet(ds, r16[si] + 14, 0x01);
    { pc = 0x15ec9; break; }
  case 0x15e80: // 1020:5c80
    if (r8[al] != 0x01)
        { pc = 0x15e95; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) - r16[ax]);
    memoryASet16(ds, r16[si] + 17, memoryAGet16(ds, r16[si] + 17) - 1);
    if (memoryAGet16(ds, r16[si] + 17))
        { pc = 0x15ec9; break; }
    memoryASet(ds, r16[si] + 14, 0x02);
    { pc = 0x15ec9; break; }
  case 0x15e95: // 1020:5c95
    if (r8[al] != 0x02)
        { pc = 0x15ebc; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    memoryASet16(ds, r16[si] + 17, memoryAGet16(ds, r16[si] + 17) + 1);
    r16[ax] = memoryAGet16(ds, r16[si] + 20);
    if (signed16(memoryAGet16(ds, r16[si] + 2)) < r16s[ax])
        { pc = 0x15ec9; break; }
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    r8[al] = memoryAGet(ds, r16[si] + 19);
    memoryASet(ds, r16[si] + 17, r8[al]);
    memoryASet(ds, r16[si] + 14, 0x03);
    yield* sub_166ef();
    { pc = 0x15ec9; break; }
  case 0x15ebc: // 1020:5cbc
    if (r8[al] != 0x03)
        { pc = 0x15ec9; break; }
    memoryASet(ds, r16[si] + 17, memoryAGet(ds, r16[si] + 17) - 1);
    if (memoryAGet(ds, r16[si] + 17))
        { pc = 0x15ec9; break; }
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15ec9: // 1020:5cc9
    return;
  }
}
function* sub_15eca() // 1020:5cca
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x15eca; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 530 bytes // gap 530 bytes
  case 0x15eca: // 1020:5cca
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x15ed4; break; }
    { pc = 0x15c58; break; }
  case 0x15ed4: // 1020:5cd4
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x15f09; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x15ee4; break; }
    r16[ax] = -r16[ax];
  case 0x15ee4: // 1020:5ce4
    if (memoryAGet16(ds, r16[si] + 23) < r16[ax])
        { pc = 0x15f01; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x15ef3; break; }
    r16[ax] = -r16[ax];
  case 0x15ef3: // 1020:5cf3
    if (r16[ax] > 0x001a)
        { pc = 0x15f01; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    yield* sub_166df();
    yield* sub_1641c();
  case 0x15f01: // 1020:5d01
    return;
    // gap 7 bytes // gap 7 bytes
  case 0x15f09: // 1020:5d09
    if (r8[al] != 0x01)
        { pc = 0x15f7a; break; }
    yield* sub_16767();
    if (r8[al])
        { pc = 0x15f17; break; }
    yield* sub_160ca();
  case 0x15f17: // 1020:5d17
    memoryASet(ds, r16[si] + 2, memoryAGet(ds, r16[si] + 2) & 0xf0);
    r8[al] = memoryAGet(es, r16[di] + 65280);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (!r8[al])
        { pc = 0x15f2b; break; }
    memoryASet16(ds, r16[si] + 8, -memoryAGet16(ds, r16[si] + 8));
  case 0x15f2b: // 1020:5d2b
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    if (signed16(memoryAGet16(ds, r16[si])) >= 0)
        { pc = 0x15f39; break; }
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    memoryASet16(ds, r16[si] + 8, r16[ax]);
  case 0x15f39: // 1020:5d39
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x15f42; break; }
    r16[ax] = -r16[ax];
  case 0x15f42: // 1020:5d42
    if (r16[ax] < 0x0280)
        { pc = 0x15f4c; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    { pc = 0x15f01; break; }
  case 0x15f4c: // 1020:5d4c
    flags.carry = memoryAGet(ds, r16[si] + 20) < 0x01;
    memoryASet(ds, r16[si] + 20, memoryAGet(ds, r16[si] + 20) - 0x01);
    memoryASet(ds, r16[si] + 20, memoryAGet(ds, r16[si] + 20) + (0x00 + flags.carry));
    if (memoryAGet(ds, r16[si] + 20))
        { pc = 0x15fcd; break; }
    if (r16[ax] > 0x0040)
        { pc = 0x15fcd; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x15f65; break; }
    r16[ax] = -r16[ax];
  case 0x15f65: // 1020:5d65
    if (r16[ax] > 0x0014)
        { pc = 0x15fcd; break; }
    yield* sub_1641c();
    memoryASet(ds, r16[si] + 14, 0x03);
    yield* sub_166df();
    memoryASet(ds, r16[si] + 20, 0x14);
    { pc = 0x15fcd; break; }
  case 0x15f7a: // 1020:5d7a
    if (r8[al] != 0x02)
        { pc = 0x15fb0; break; }
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[ax] -= memoryAGet16(ds, 0x5270);
    if (r16[ax] >= 0x0015)
        { pc = 0x15f9c; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[ax] -= memoryAGet16(ds, 0x5272);
    if (r16[ax] <= 0x000d)
        { pc = 0x15fcd; break; }
  case 0x15f9c: // 1020:5d9c
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    memoryASet16(ds, r16[si], r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    yield* sub_166ef();
    memoryASet(ds, r16[si] + 14, 0x00);
    { pc = 0x15fcd; break; }
  case 0x15fb0: // 1020:5db0
    if (r8[al] != 0x03)
        { pc = 0x15fcd; break; }
    if (!(memoryAGet(ds, r16[si] + 7) & 0x20))
        { pc = 0x15fcd; break; }
    yield* sub_15b2d();
    if (flags.carry)
        { pc = 0x15fc6; break; }
    memoryASet16(ds, r16[si] + 10, memoryAGet16(ds, r16[si] + 10) + 0x0004);
    yield* sub_16696();
  case 0x15fc6: // 1020:5dc6
    yield* sub_166ef();
    memoryASet(ds, r16[si] + 14, 0x01);
  case 0x15fcd: // 1020:5dcd
    return;
  }
}
function* sub_15fce() // 1020:5dce
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x15fce; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 790 bytes // gap 790 bytes
  case 0x15fce: // 1020:5dce
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x15fd8; break; }
    { pc = 0x15c58; break; }
  case 0x15fd8: // 1020:5dd8
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x1600e; break; }
    if (memoryAGet(ds, 0x6512))
        { pc = 0x16044; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x15fef; break; }
    r16[ax] = -r16[ax];
  case 0x15fef: // 1020:5def
    if (memoryAGet16(ds, r16[si] + 23) < r16[ax])
        { pc = 0x16044; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x15ffe; break; }
    r16[ax] = -r16[ax];
  case 0x15ffe: // 1020:5dfe
    if (r16[ax] > 0x001a)
        { pc = 0x16044; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    yield* sub_166df();
    yield* sub_1641c();
    { pc = 0x16044; break; }
  case 0x1600e: // 1020:5e0e
    if (r8[al] != 0x01)
        { pc = 0x1604c; break; }
    if (memoryAGet(ds, 0x6512))
        { pc = 0x16044; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x16022; break; }
    r16[ax] = -r16[ax];
  case 0x16022: // 1020:5e22
    if (memoryAGet16(ds, r16[si] + 23) < r16[ax])
        { pc = 0x16045; break; }
    r16[ax] += 0x0032;
    if (memoryAGet16(ds, r16[si] + 23) < r16[ax])
        { pc = 0x16044; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x16039; break; }
    r16[ax] = -r16[ax];
  case 0x16039: // 1020:5e39
    if (r16[ax] > 0x003c)
        { pc = 0x16044; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    yield* sub_166df();
  case 0x16044: // 1020:5e44
    return;
  case 0x16045: // 1020:5e45
    yield* sub_166ef();
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) - 1);
    return;
  case 0x1604c: // 1020:5e4c
    if (r8[al] != 0x02)
        { pc = 0x16092; break; }
    yield* sub_16767();
    if (r8[al])
        { pc = 0x1605a; break; }
    yield* sub_160ca();
  case 0x1605a: // 1020:5e5a
    memoryASet(ds, r16[si] + 2, memoryAGet(ds, r16[si] + 2) & 0xf0);
    yield* sub_160e4();
    r8[al] = memoryAGet(es, r16[di] + 65280);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (!r8[al])
        { pc = 0x16071; break; }
    yield* sub_160ca();
  case 0x16071: // 1020:5e71
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    if (signed16(memoryAGet16(ds, r16[si])) >= 0)
        { pc = 0x1607f; break; }
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    memoryASet16(ds, r16[si] + 8, r16[ax]);
  case 0x1607f: // 1020:5e7f
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x16088; break; }
    r16[ax] = -r16[ax];
  case 0x16088: // 1020:5e88
    if (r16[ax] < 0x0280)
        { pc = 0x160c9; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    { pc = 0x160c9; break; }
  case 0x16092: // 1020:5e92
    if (r8[al] != 0x03)
        { pc = 0x160c9; break; }
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[ax] -= memoryAGet16(ds, 0x5270);
    if (r16[ax] >= 0x0015)
        { pc = 0x160b4; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    r16[ax] = sar16(r16[ax], r8[cl]);
    r16[ax] -= memoryAGet16(ds, 0x5272);
    if (r16[ax] <= 0x000d)
        { pc = 0x160c9; break; }
  case 0x160b4: // 1020:5eb4
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    memoryASet16(ds, r16[si], r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    yield* sub_166ef();
    yield* sub_166ef();
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x160c9: // 1020:5ec9
    return;
  }
}
function* sub_160ca() // 1020:5eca
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[dx]);
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    if (r16s[ax] >= 0)
        { pc = 0x160d5; break; }
    r16[ax] = -r16[ax];
  case 0x160d5: // 1020:5ed5
    r16[dx] = memoryAGet16(ds, r16[si]);
    if (signed16(memoryAGet16(ds, r16[si] + 15)) <= r16s[dx])
        { pc = 0x160de; break; }
    r16[ax] = -r16[ax];
  case 0x160de: // 1020:5ede
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    r16[dx] = pop();
    r16[ax] = pop();
    return;
  }
}
function* sub_160e4() // 1020:5ee4
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = 0x0001;
    if (signed16(memoryAGet16(ds, r16[si] + 8)) > signed16(0x0000))
        { pc = 0x160ef; break; }
    r16[ax] = -r16[ax];
  case 0x160ef: // 1020:5eef
    r16[di] -= r16[ax];
    return;
  }
}
function* sub_160f2() // 1020:5ef2
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x160f2; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 1082 bytes // gap 1082 bytes
  case 0x160f2: // 1020:5ef2
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x160fc; break; }
    { pc = 0x15c58; break; }
  case 0x160fc: // 1020:5efc
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x1612a; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x1610c; break; }
    r16[ax] = -r16[ax];
  case 0x1610c: // 1020:5f0c
    if (memoryAGet16(ds, r16[si] + 23) < r16[ax])
        { pc = 0x16129; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x1611b; break; }
    r16[ax] = -r16[ax];
  case 0x1611b: // 1020:5f1b
    if (r16[ax] > 0x003c)
        { pc = 0x16129; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    yield* sub_166df();
    yield* sub_1641c();
  case 0x16129: // 1020:5f29
    return;
  case 0x1612a: // 1020:5f2a
    if (r8[al] != 0x01)
        { pc = 0x16198; break; }
    memoryASet(ds, 0x6500, memoryAGet(ds, 0x6500) + 1);
    if (memoryAGet(ds, 0x6500) & 0x04)
        { pc = 0x16144; break; }
    if (memoryAGet16(ds, 0x64fe) & 0x01ff)
        { pc = 0x16144; break; }
    yield* sub_166df();
  case 0x16144: // 1020:5f44
    if (memoryAGet(ds, 0x64fe) & 0x7f)
        { pc = 0x16155; break; }
    r8[al] = 0x03;
    memoryASet(ds, r16[si] + 14, r8[al]);
    yield* sub_166df();
    { pc = 0x16198; break; }
  case 0x16155: // 1020:5f55
    yield* sub_16767();
    if (r8[al])
        { pc = 0x1615f; break; }
    yield* sub_160ca();
  case 0x1615f: // 1020:5f5f
    memoryASet(ds, r16[si] + 2, memoryAGet(ds, r16[si] + 2) & 0xf0);
    yield* sub_160e4();
    r8[al] = memoryAGet(es, r16[di] + 65280);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (!r8[al])
        { pc = 0x16176; break; }
    memoryASet16(ds, r16[si] + 8, -memoryAGet16(ds, r16[si] + 8));
  case 0x16176: // 1020:5f76
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    if (signed16(memoryAGet16(ds, r16[si])) >= 0)
        { pc = 0x16184; break; }
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    memoryASet16(ds, r16[si] + 8, r16[ax]);
  case 0x16184: // 1020:5f84
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x1618d; break; }
    r16[ax] = -r16[ax];
  case 0x1618d: // 1020:5f8d
    if (r16[ax] < 0x0500)
        { pc = 0x16129; break; }
    memoryASet(ds, r16[si] + 14, 0x02);
    { pc = 0x161f8; break; }
  case 0x16198: // 1020:5f98
    if (r8[al] != 0x02)
        { pc = 0x161ce; break; }
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    r16[ax] >>= r8[cl];
    r16[ax] -= memoryAGet16(ds, 0x5272);
    if (r16[ax] > 0x000c)
        { pc = 0x161ba; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    r16[ax] >>= r8[cl];
    r16[ax] -= memoryAGet16(ds, 0x5270);
    if (r16[ax] < 0x0019)
        { pc = 0x161f8; break; }
  case 0x161ba: // 1020:5fba
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    memoryASet16(ds, r16[si], r16[ax]);
    memoryASet(ds, r16[si] + 14, 0x00);
    yield* sub_166ef();
    { pc = 0x161f8; break; }
  case 0x161ce: // 1020:5fce
    if (r8[al] != 0x03)
        { pc = 0x161f8; break; }
    if (memoryAGet(ds, r16[si] + 5) & 0x20)
        { pc = 0x161eb; break; }
    yield* sub_166df();
    memoryASet16(ds, r16[si] + 10, memoryAGet16(ds, r16[si] + 10) - 0x0002);
    yield* sub_166ff();
    yield* sub_1641c();
    memoryASet(ds, r16[si] + 14, 0x01);
    { pc = 0x161f8; break; }
  case 0x161eb: // 1020:5feb
    if (!(memoryAGet(ds, r16[si] + 7) & 0x20))
        { pc = 0x161f8; break; }
    yield* sub_1641c();
    memoryASet(ds, r16[si] + 14, 0x01);
  case 0x161f8: // 1020:5ff8
    return;
  }
}
function* sub_161f9() // 1020:5ff9
{
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) & 0x3f);
}
function* sub_161fe() // 1020:5ffe
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x161fe; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 1350 bytes // gap 1350 bytes
  case 0x161fe: // 1020:5ffe
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x16208; break; }
    { pc = 0x15c58; break; }
  case 0x16208: // 1020:6008
    return;
  }
}
function* sub_16209() // 1020:6009
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) & 0x3f);
    { pc = 0x16219; break; }
    // gap 10 bytes // gap 10 bytes
  case 0x16219: // 1020:6019
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x1624a; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, 0x527c);
    if (r16s[ax] >= 0)
        { pc = 0x1622a; break; }
    r16[ax] = -r16[ax];
  case 0x1622a: // 1020:602a
    if (r16[ax] > 0x0154)
        { pc = 0x1623f; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= memoryAGet16(ds, 0x527e);
    if (r16s[ax] >= 0)
        { pc = 0x1623a; break; }
    r16[ax] = -r16[ax];
  case 0x1623a: // 1020:603a
    if (r16[ax] < 0x00e6)
        { pc = 0x16264; break; }
  case 0x1623f: // 1020:603f
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    yield* sub_166df();
    yield* sub_1641c();
    { pc = 0x16264; break; }
  case 0x1624a: // 1020:604a
    if (r8[al] != 0x01)
        { pc = 0x162ab; break; }
    yield* sub_16767();
    if (r8[al])
        { pc = 0x16265; break; }
    if (memoryAGet16(ds, r16[si] + 21) >= 0x0010)
        { pc = 0x1625e; break; }
    memoryASet16(ds, r16[si] + 21, memoryAGet16(ds, r16[si] + 21) + 1);
  case 0x1625e: // 1020:605e
    r16[ax] = memoryAGet16(ds, r16[si] + 21);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
  case 0x16264: // 1020:6064
    return;
  case 0x16265: // 1020:6065
    if (!memoryAGet16(ds, r16[si] + 21))
        { pc = 0x1626e; break; }
    yield* sub_1641c();
  case 0x1626e: // 1020:606e
    memoryASet16(ds, r16[si] + 21, 0x0000);
    memoryASet(ds, r16[si] + 2, memoryAGet(ds, r16[si] + 2) & 0xf0);
    yield* sub_160e4();
    r8[al] = memoryAGet(es, r16[di] + 65280);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (!r8[al])
        { pc = 0x1628a; break; }
    memoryASet16(ds, r16[si] + 8, -memoryAGet16(ds, r16[si] + 8));
  case 0x1628a: // 1020:608a
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    if (signed16(memoryAGet16(ds, r16[si])) >= 0)
        { pc = 0x16298; break; }
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    memoryASet16(ds, r16[si] + 8, r16[ax]);
  case 0x16298: // 1020:6098
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x162a1; break; }
    r16[ax] = -r16[ax];
  case 0x162a1: // 1020:60a1
    if (r16[ax] < 0x0280)
        { pc = 0x162df; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    { pc = 0x162df; break; }
  case 0x162ab: // 1020:60ab
    if (r8[al] != 0x02)
        { pc = 0x162df; break; }
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    r16[ax] >>= r8[cl];
    r16[ax] -= memoryAGet16(ds, 0x5272);
    if (r16[ax] > 0x000c)
        { pc = 0x162cd; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    r16[ax] >>= r8[cl];
    r16[ax] -= memoryAGet16(ds, 0x5270);
    if (r16[ax] < 0x0013)
        { pc = 0x162df; break; }
  case 0x162cd: // 1020:60cd
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    memoryASet16(ds, r16[si], r16[ax]);
    memoryASet(ds, r16[si] + 14, 0x00);
    yield* sub_166ef();
  case 0x162df: // 1020:60df
    return;
  }
}
function* sub_1620f() // 1020:600f
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x1620f; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 1367 bytes // gap 1367 bytes
  case 0x1620f: // 1020:600f
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x16219; break; }
    { pc = 0x15c58; break; }
  case 0x16219: // 1020:6019
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x1624a; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, 0x527c);
    if (r16s[ax] >= 0)
        { pc = 0x1622a; break; }
    r16[ax] = -r16[ax];
  case 0x1622a: // 1020:602a
    if (r16[ax] > 0x0154)
        { pc = 0x1623f; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= memoryAGet16(ds, 0x527e);
    if (r16s[ax] >= 0)
        { pc = 0x1623a; break; }
    r16[ax] = -r16[ax];
  case 0x1623a: // 1020:603a
    if (r16[ax] < 0x00e6)
        { pc = 0x16264; break; }
  case 0x1623f: // 1020:603f
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    yield* sub_166df();
    yield* sub_1641c();
    { pc = 0x16264; break; }
  case 0x1624a: // 1020:604a
    if (r8[al] != 0x01)
        { pc = 0x162ab; break; }
    yield* sub_16767();
    if (r8[al])
        { pc = 0x16265; break; }
    if (memoryAGet16(ds, r16[si] + 21) >= 0x0010)
        { pc = 0x1625e; break; }
    memoryASet16(ds, r16[si] + 21, memoryAGet16(ds, r16[si] + 21) + 1);
  case 0x1625e: // 1020:605e
    r16[ax] = memoryAGet16(ds, r16[si] + 21);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
  case 0x16264: // 1020:6064
    return;
  case 0x16265: // 1020:6065
    if (!memoryAGet16(ds, r16[si] + 21))
        { pc = 0x1626e; break; }
    yield* sub_1641c();
  case 0x1626e: // 1020:606e
    memoryASet16(ds, r16[si] + 21, 0x0000);
    memoryASet(ds, r16[si] + 2, memoryAGet(ds, r16[si] + 2) & 0xf0);
    yield* sub_160e4();
    r8[al] = memoryAGet(es, r16[di] + 65280);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (!r8[al])
        { pc = 0x1628a; break; }
    memoryASet16(ds, r16[si] + 8, -memoryAGet16(ds, r16[si] + 8));
  case 0x1628a: // 1020:608a
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    if (signed16(memoryAGet16(ds, r16[si])) >= 0)
        { pc = 0x16298; break; }
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    memoryASet16(ds, r16[si] + 8, r16[ax]);
  case 0x16298: // 1020:6098
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x162a1; break; }
    r16[ax] = -r16[ax];
  case 0x162a1: // 1020:60a1
    if (r16[ax] < 0x0280)
        { pc = 0x162df; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    { pc = 0x162df; break; }
  case 0x162ab: // 1020:60ab
    if (r8[al] != 0x02)
        { pc = 0x162df; break; }
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    r16[ax] >>= r8[cl];
    r16[ax] -= memoryAGet16(ds, 0x5272);
    if (r16[ax] > 0x000c)
        { pc = 0x162cd; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    r16[ax] >>= r8[cl];
    r16[ax] -= memoryAGet16(ds, 0x5270);
    if (r16[ax] < 0x0013)
        { pc = 0x162df; break; }
  case 0x162cd: // 1020:60cd
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    memoryASet16(ds, r16[si], r16[ax]);
    memoryASet(ds, r16[si] + 14, 0x00);
    yield* sub_166ef();
  case 0x162df: // 1020:60df
    return;
  }
}
function* sub_162e0() // 1020:60e0
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x162e0; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 1576 bytes // gap 1576 bytes
  case 0x162e0: // 1020:60e0
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x162ea; break; }
    { pc = 0x15c58; break; }
  case 0x162ea: // 1020:60ea
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x16323; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    if (signed16(memoryAGet16(ds, r16[si] + 2)) > r16s[ax])
        { pc = 0x16340; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, 0x527c);
    if (r16s[ax] >= 0)
        { pc = 0x16303; break; }
    r16[ax] = -r16[ax];
  case 0x16303: // 1020:6103
    if (memoryAGet16(ds, r16[si] + 23) < r16[ax])
        { pc = 0x16340; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= memoryAGet16(ds, 0x527e);
    if (r16s[ax] >= 0)
        { pc = 0x16313; break; }
    r16[ax] = -r16[ax];
  case 0x16313: // 1020:6113
    if (r16[ax] > 0x00c8)
        { pc = 0x16340; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    yield* sub_166df();
    yield* sub_1641c();
    { pc = 0x16340; break; }
  case 0x16323: // 1020:6123
    if (r8[al] == 0x01)
        { pc = 0x1632a; break; }
    { pc = 0x163d4; break; }
  case 0x1632a: // 1020:612a
    yield* sub_16767();
    if (r8[al])
        { pc = 0x16341; break; }
    if (memoryAGet16(ds, r16[si] + 21) >= 0x0010)
        { pc = 0x1633a; break; }
    memoryASet16(ds, r16[si] + 21, memoryAGet16(ds, r16[si] + 21) + 1);
  case 0x1633a: // 1020:613a
    r16[ax] = memoryAGet16(ds, r16[si] + 21);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
  case 0x16340: // 1020:6140
    return;
  case 0x16341: // 1020:6141
    if (!memoryAGet16(ds, r16[si] + 21))
        { pc = 0x1634a; break; }
    yield* sub_1641c();
  case 0x1634a: // 1020:614a
    memoryASet16(ds, r16[si] + 21, 0x0000);
    memoryASet(ds, r16[si] + 2, memoryAGet(ds, r16[si] + 2) & 0xf0);
    yield* sub_160e4();
    r8[al] = memoryAGet(es, r16[di] + 65280);
    r16[bx] = 0x72a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
    r8[al] &= 0x01;
    if (!r8[al])
        { pc = 0x16366; break; }
    memoryASet16(ds, r16[si] + 8, -memoryAGet16(ds, r16[si] + 8));
  case 0x16366: // 1020:6166
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    if (signed16(memoryAGet16(ds, r16[si])) >= 0)
        { pc = 0x16374; break; }
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    memoryASet16(ds, r16[si] + 8, r16[ax]);
  case 0x16374: // 1020:6174
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x1637d; break; }
    r16[ax] = -r16[ax];
  case 0x1637d: // 1020:617d
    if (r16[ax] > 0x0280)
        { pc = 0x16391; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x1638c; break; }
    r16[ax] = -r16[ax];
  case 0x1638c: // 1020:618c
    if (r16[ax] < 0x0190)
        { pc = 0x16398; break; }
  case 0x16391: // 1020:6191
    memoryASet(ds, r16[si] + 14, 0x02);
    { pc = 0x1641b; break; }
  case 0x16398: // 1020:6198
    if (memoryAGet(ds, r16[si] + 14) != 0x01)
        { pc = 0x1641b; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x163a7; break; }
    r16[ax] = -r16[ax];
  case 0x163a7: // 1020:61a7
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r16[bx] <<= 1;
    r8[dl] = memoryAGet(ds, r16[bx] + 26213);
    r8[dh] = 0;
    r16[dx] += 0x0006;
    if (r16[ax] > r16[dx])
        { pc = 0x1641b; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x163c6; break; }
    r16[ax] = -r16[ax];
  case 0x163c6: // 1020:61c6
    if (r16[ax] > 0x0008)
        { pc = 0x1641b; break; }
    memoryASet(ds, r16[si] + 14, 0x03);
    yield* sub_166df();
    { pc = 0x1641b; break; }
  case 0x163d4: // 1020:61d4
    if (r8[al] != 0x02)
        { pc = 0x1640a; break; }
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    r16[ax] >>= r8[cl];
    r16[ax] -= memoryAGet16(ds, 0x5272);
    if (r16[ax] > 0x000d)
        { pc = 0x163f6; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    r16[ax] >>= r8[cl];
    r16[ax] -= memoryAGet16(ds, 0x5270);
    if (r16[ax] < 0x0015)
        { pc = 0x1641b; break; }
  case 0x163f6: // 1020:61f6
    r16[ax] = memoryAGet16(ds, r16[si] + 17);
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 15);
    memoryASet16(ds, r16[si], r16[ax]);
    memoryASet(ds, r16[si] + 14, 0x00);
    yield* sub_166ef();
    { pc = 0x1641b; break; }
  case 0x1640a: // 1020:620a
    if (r8[al] != 0x03)
        { pc = 0x1641b; break; }
    if (memoryAGet(ds, r16[si] + 7) & 0x20)
        { pc = 0x16417; break; }
    { pc = 0x1632a; break; }
  case 0x16417: // 1020:6217
    memoryASet(ds, r16[si] + 14, 0x01);
  case 0x1641b: // 1020:621b
    return;
  }
}
function* sub_1641c() // 1020:621c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r8[dl] = memoryAGet(ds, r16[si] + 19);
    r8[dh] = 0;
    r16[ax] = memoryAGet16(ds, 0x527c);
    if (signed16(memoryAGet16(ds, r16[si])) > r16s[ax])
        { pc = 0x1642a; break; }
    r16[dx] = -r16[dx];
  case 0x1642a: // 1020:622a
    memoryASet16(ds, r16[si] + 8, r16[dx]);
    return;
  }
}
function* sub_1642e() // 1020:622e
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x1642e; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 1910 bytes // gap 1910 bytes
  case 0x1642e: // 1020:622e
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x16438; break; }
    { pc = 0x15c58; break; }
  case 0x16438: // 1020:6238
    yield* sub_165c9();
    if (memoryAGet(ds, r16[si] + 5) & 0x20)
        { pc = 0x16444; break; }
    { pc = 0x164c8; break; }
  case 0x16444: // 1020:6244
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x16484; break; }
    r16[dx] = 0xfffe;
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= memoryAGet16(ds, 0x527e);
    if (r16s[ax] >= 0)
        { pc = 0x1645b; break; }
    r16[ax] = -r16[ax];
    r16[dx] = -r16[dx];
  case 0x1645b: // 1020:625b
    r8[cl] = memoryAGet(ds, r16[si] + 19);
    r8[ch] = 0;
    if (r16[ax] > r16[cx])
        { pc = 0x164c8; break; }
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, 0x527c);
    if (r16s[ax] >= 0)
        { pc = 0x1646e; break; }
    r16[ax] = -r16[ax];
  case 0x1646e: // 1020:626e
    if (r16[ax] > 0x0028)
        { pc = 0x164c8; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    memoryASet16(ds, r16[si] + 22, r16[ax]);
    memoryASet16(ds, r16[si] + 20, r16[dx]);
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    yield* sub_166df();
    { pc = 0x164c8; break; }
  case 0x16484: // 1020:6284
    if (r8[al] != 0x01)
        { pc = 0x164ac; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 20);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= memoryAGet16(ds, r16[si] + 22);
    if (r16s[ax] >= 0)
        { pc = 0x16498; break; }
    r16[ax] = -r16[ax];
  case 0x16498: // 1020:6298
    r8[cl] = memoryAGet(ds, r16[si] + 19);
    r8[ch] = 0;
    if (r16[ax] < r16[cx])
        { pc = 0x164c8; break; }
    memoryASet16(ds, r16[si] + 20, -memoryAGet16(ds, r16[si] + 20));
    yield* sub_166df();
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    { pc = 0x164c8; break; }
  case 0x164ac: // 1020:62ac
    if (r8[al] != 0x02)
        { pc = 0x164c8; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 20);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 22);
    if (memoryAGet16(ds, r16[si] + 2) != r16[ax])
        { pc = 0x164c8; break; }
    yield* sub_166ef();
    yield* sub_166ef();
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x164c8: // 1020:62c8
    return;
  }
}
function* sub_164c9() // 1020:62c9
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x164c9; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 2065 bytes // gap 2065 bytes
  case 0x164c9: // 1020:62c9
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x164d3; break; }
    { pc = 0x15c58; break; }
  case 0x164d3: // 1020:62d3
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x16542; break; }
    yield* sub_165c9();
    if (!(memoryAGet(ds, r16[si] + 5) & 0x20))
        { pc = 0x16541; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[ax] -= memoryAGet16(ds, 0x527e);
    if (r8[ah])
        { pc = 0x16541; break; }
    if (memoryAGet(ds, r16[si] + 19) < r8[al])
        { pc = 0x16541; break; }
    r8[cl] = r8[al];
    r8[dh] = 0;
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, 0x527c);
    if (r16s[ax] >= 0)
        { pc = 0x16503; break; }
    r16[ax] = -r16[ax];
    r8[dh] = 0x80;
  case 0x16503: // 1020:6303
    r8[dl] = memoryAGet(ds, r16[si] + 5);
    r8[dl] &= 0x80;
    if (r8[dl] != r8[dh])
        { pc = 0x16541; break; }
    if (r16s[ax] >= signed16(0x0030))
        { pc = 0x16541; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si] + 15);
    if (r16s[ax] >= 0)
        { pc = 0x1651c; break; }
    r16[ax] = -r16[ax];
  case 0x1651c: // 1020:631c
    if (memoryAGet16(ds, r16[si] + 17) < r16[ax])
        { pc = 0x16541; break; }
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    r16[dx] = 0;
  case 0x16526: // 1020:6326
    r8[dl]++;
    r8[dh] += r8[dl];
    if (r8[cl] > r8[dh])
        { pc = 0x16526; break; }
    r8[al] = r8[dl];
    cbw();
    r16[ax] = -r16[ax];
    memoryASet16(ds, r16[si] + 20, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    memoryASet16(ds, r16[si] + 22, r16[ax]);
    yield* sub_166df();
    { pc = 0x165be; break; }
  case 0x16541: // 1020:6341
    return;
  case 0x16542: // 1020:6342
    if (!(memoryAGet(ds, r16[si] + 5) & 0x20))
        { pc = 0x16541; break; }
    if (r8[al] != 0x01)
        { pc = 0x16591; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 20);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    r16[ax]++;
    if (!r16[ax])
        { pc = 0x1656f; break; }
    memoryASet16(ds, r16[si] + 20, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 22);
    flags.carry = r8[al] < memoryAGet(ds, r16[si] + 19);
    r8[al] -= memoryAGet(ds, r16[si] + 19);
    r8[ah] -= (0x00 + flags.carry);
    if (signed16(memoryAGet16(ds, r16[si] + 2)) > r16s[ax])
        { pc = 0x165be; break; }
  case 0x1656f: // 1020:636f
    yield* sub_166df();
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) + 1);
    memoryASet16(ds, r16[si] + 20, 0x0000);
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    if (r16s[ax] >= 0)
        { pc = 0x16583; break; }
    r16[ax] = -r16[ax];
  case 0x16583: // 1020:6383
    r16[dx] = memoryAGet16(ds, r16[si] + 15);
    if (signed16(memoryAGet16(ds, r16[si])) <= r16s[dx])
        { pc = 0x1658c; break; }
    r16[ax] = -r16[ax];
  case 0x1658c: // 1020:638c
    memoryASet16(ds, r16[si] + 8, r16[ax]);
    { pc = 0x165be; break; }
  case 0x16591: // 1020:6391
    if (r8[al] != 0x02)
        { pc = 0x165be; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 20);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    r16[ax]++;
    memoryASet16(ds, r16[si] + 20, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 22);
    if (signed16(memoryAGet16(ds, r16[si] + 2)) < r16s[ax])
        { pc = 0x165be; break; }
    memoryASet16(ds, r16[si] + 2, r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    memoryASet(ds, r16[si] + 14, 0x00);
    yield* sub_166ef();
    yield* sub_166ef();
  case 0x165be: // 1020:63be
    return;
  }
}
function* sub_165bf() // 1020:63bf
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x165bf; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 2311 bytes // gap 2311 bytes
  case 0x165bf: // 1020:63bf
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x165c9; break; }
    { pc = 0x15c58; break; }
  case 0x165c9: // 1020:63c9
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, r16[si] + 15);
    r16[dx] = r16[ax];
    if (r16s[ax] >= 0)
        { pc = 0x165d9; break; }
    r16[ax] = -r16[ax];
  case 0x165d9: // 1020:63d9
    if (r16[ax] <= memoryAGet16(ds, r16[si] + 17))
        { pc = 0x165f0; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    if (r16s[ax] >= 0)
        { pc = 0x165e7; break; }
    r16[ax] = -r16[ax];
  case 0x165e7: // 1020:63e7
    if (r16s[dx] >= 0)
        { pc = 0x165ed; break; }
    r16[ax] = -r16[ax];
  case 0x165ed: // 1020:63ed
    memoryASet16(ds, r16[si] + 8, r16[ax]);
  case 0x165f0: // 1020:63f0
    return;
  }
}
function* sub_165c9() // 1020:63c9
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si], memoryAGet16(ds, r16[si]) - r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si]);
    r16[ax] -= memoryAGet16(ds, r16[si] + 15);
    r16[dx] = r16[ax];
    if (r16s[ax] >= 0)
        { pc = 0x165d9; break; }
    r16[ax] = -r16[ax];
  case 0x165d9: // 1020:63d9
    if (r16[ax] <= memoryAGet16(ds, r16[si] + 17))
        { pc = 0x165f0; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    if (r16s[ax] >= 0)
        { pc = 0x165e7; break; }
    r16[ax] = -r16[ax];
  case 0x165e7: // 1020:63e7
    if (r16s[dx] >= 0)
        { pc = 0x165ed; break; }
    r16[ax] = -r16[ax];
  case 0x165ed: // 1020:63ed
    memoryASet16(ds, r16[si] + 8, r16[ax]);
  case 0x165f0: // 1020:63f0
    return;
  }
}
function* sub_165f1() // 1020:63f1
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    { pc = 0x165f1; break; }
  case 0x15c58: // 1020:5a58
    if (r8[al] & 0x40)
        { pc = 0x15c98; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | 0x40);
    r16[bx] = memoryAGet16(ds, r16[si] + 4);
    r8[bh] &= 0x1f;
    r8[bl] = memoryAGet(ds, r16[bx] + 28639);
    r8[bl] &= 0xf0;
    if (r8[bl] == 0xf0)
        { pc = 0x15c8f; break; }
    r8[cl] = 0x03;
    r8[bh] = 0;
    r16[bx] >>= r8[cl];
    r8[ah] = memoryAGet(ds, r16[si] + 5);
    r16[ax] &= 0x8000;
    r16[ax] |= memoryAGet16(ds, r16[bx] + 28627);
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    memoryASet16(ds, r16[si] + 8, 0x0000);
    memoryASet(ds, r16[si] + 14, 0xff);
    return;
  case 0x15c8f: // 1020:5a8f
    memoryASet16(ds, r16[si] + 8, 0xfff6);
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x15c98: // 1020:5a98
    if (memoryAGet(ds, r16[si] + 14) == 0xff)
        { pc = 0x15cb7; break; }
    r16[ax] = memoryAGet16(ds, r16[si] + 8);
    memoryASet16(ds, r16[si] + 2, memoryAGet16(ds, r16[si] + 2) + r16[ax]);
    if (!memoryAGet(ds, 0x6515))
        { pc = 0x15caf; break; }
    memoryASet16(ds, 0x5290, memoryAGet16(ds, 0x5290) + r16[ax]);
  case 0x15caf: // 1020:5aaf
    if (r16s[ax] >= signed16(0x0014))
        { pc = 0x15cb7; break; }
    memoryASet16(ds, r16[si] + 8, memoryAGet16(ds, r16[si] + 8) + 1);
  case 0x15cb7: // 1020:5ab7
    return;
    // gap 2361 bytes // gap 2361 bytes
  case 0x165f1: // 1020:63f1
    r8[al] = memoryAGet(ds, r16[si] + 7);
    if (!(r8[al] & 0xc0))
        { pc = 0x165fb; break; }
    { pc = 0x15c58; break; }
  case 0x165fb: // 1020:63fb
    if (memoryAGet(ds, r16[si] + 5) & 0x20)
        { pc = 0x16604; break; }
    { pc = 0x16695; break; }
  case 0x16604: // 1020:6404
    r8[al] = memoryAGet(ds, r16[si] + 18);
    if (!(r8[al] & 0xc0))
        { pc = 0x16614; break; }
    r16[dx] = 0;
    if (r8[al] & 0x40)
        { pc = 0x1661e; break; }
    r16[dx]--;
    { pc = 0x1661e; break; }
  case 0x16614: // 1020:6414
    r16[dx] = 0;
    r16[ax] = memoryAGet16(ds, 0x527c);
    if (signed16(memoryAGet16(ds, r16[si])) >= r16s[ax])
        { pc = 0x1661e; break; }
    r16[dx]--;
  case 0x1661e: // 1020:641e
    memoryASet16(ds, r16[si] + 8, r16[dx]);
    r8[al] = memoryAGet(ds, r16[si] + 14);
    if (r8[al])
        { pc = 0x16676; break; }
    flags.carry = memoryAGet(ds, r16[si] + 15) < 0x01;
    memoryASet(ds, r16[si] + 15, memoryAGet(ds, r16[si] + 15) - 0x01);
    memoryASet(ds, r16[si] + 15, memoryAGet(ds, r16[si] + 15) + (0x00 + flags.carry));
    if (memoryAGet(ds, r16[si] + 15))
        { pc = 0x16695; break; }
    r16[ax] = memoryAGet16(ds, 0x527e);
    r16[ax] -= memoryAGet16(ds, r16[si] + 2);
    if (r16s[ax] >= 0)
        { pc = 0x1663c; break; }
    r16[ax] = -r16[ax];
  case 0x1663c: // 1020:643c
    if (r16[ax] > 0x0018)
        { pc = 0x16695; break; }
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[ax] -= memoryAGet16(ds, r16[si]);
    if (r16s[ax] >= 0)
        { pc = 0x1664a; break; }
    r16[ax] = -r16[ax];
  case 0x1664a: // 1020:644a
    r16[dx] = memoryAGet16(ds, r16[si] + 17);
    r8[dh] &= 0x3f;
    if (r16[dx] < r16[ax])
        { pc = 0x16695; break; }
    r8[al] = memoryAGet(ds, r16[si] + 18);
    r8[al] = rol8(r8[al], 0x01);
    r8[al] = rol8(r8[al], 0x01);
    r8[al] &= 0x03;
    if (!r8[al])
        { pc = 0x1666d; break; }
    flags.zero = r8[al] == 0x01;
    r16[ax] = memoryAGet16(ds, 0x527c);
    r16[dx] = memoryAGet16(ds, r16[si]);
    if (flags.zero)
        { pc = 0x16669; break; }
    r16[tx] = r16[dx]; r16[dx] = r16[ax]; r16[ax] = r16[tx];
  case 0x16669: // 1020:6469
    if (r16s[ax] > r16s[dx])
        { pc = 0x16695; break; }
  case 0x1666d: // 1020:646d
    memoryASet(ds, r16[si] + 14, 0x1e);
    yield* sub_166df();
    { pc = 0x16695; break; }
  case 0x16676: // 1020:6476
    memoryASet(ds, r16[si] + 14, memoryAGet(ds, r16[si] + 14) - 1);
    if (!(memoryAGet(ds, r16[si] + 7) & 0x20))
        { pc = 0x16695; break; }
    memoryASet16(ds, r16[si] + 10, memoryAGet16(ds, r16[si] + 10) + 0x0004);
    yield* sub_15b2d();
    if (flags.carry)
        { pc = 0x16691; break; }
    yield* sub_16696();
    r8[al] = memoryAGet(ds, r16[si] + 16);
    memoryASet(ds, r16[si] + 15, r8[al]);
  case 0x16691: // 1020:6491
    memoryASet(ds, r16[si] + 14, 0x00);
  case 0x16695: // 1020:6495
    return;
  }
}
function* sub_16696() // 1020:6496
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[ax] = memoryAGet16(ds, r16[si]);
    memoryASet16(ds, r16[di], r16[ax]);
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r16[bx] = memoryAGet16(ds, r16[si] + 10);
    r16[bp] = r16[bx];
    r16[bx] = memoryAGet16(ds, r16[bx] - 2);
    r8[bh] = 0;
    r16[tx] = r16[bx]; r16[bx] = r16[ax]; r16[ax] = r16[tx];
    cbw();
    r16[tx] = r16[bx]; r16[bx] = r16[ax]; r16[ax] = r16[tx];
    r16[ax] -= r16[bx];
    memoryASet16(ds, r16[di] + 2, r16[ax]);
    r16[bx] = memoryAGet16(ds, r16[bp] - 4);
    r8[bh] &= 0x1f;
    r16[bx] += 0x801e;
    r16[dx] = 0x00b0;
    r16[ax] = memoryAGet16(ds, 0x527c);
    if (signed16(memoryAGet16(ds, r16[si])) < r16s[ax])
        { pc = 0x166c9; break; }
    r16[dx] = -r16[dx];
    r8[bh] ^= 0x80;
  case 0x166c9: // 1020:64c9
    memoryASet16(ds, r16[di] + 4, r16[bx]);
    memoryASet16(ds, r16[di] + 6, r16[dx]);
    memoryASet16(ds, r16[di] + 14, 0x0000);
    r16[dx] = sar16(r16[dx], 0x0001);
    r16[dx] = sar16(r16[dx], 0x0001);
    r16[dx] = sar16(r16[dx], 0x0001);
    r16[dx] = sar16(r16[dx], 0x0001);
    memoryASet16(ds, r16[di], memoryAGet16(ds, r16[di]) + r16[dx]);
    return;
  }
}
function* sub_166df() // 1020:64df
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx] = memoryAGet16(ds, r16[si] + 10);
  case 0x166e2: // 1020:64e2
    r16[bx]++;
    r16[bx]++;
    if (signed16(memoryAGet16(ds, r16[bx])) >= signed16(0x0000))
        { pc = 0x166e2; break; }
    r16[bx]++;
    r16[bx]++;
    memoryASet16(ds, r16[si] + 10, r16[bx]);
    return;
  }
}
function* sub_166ef() // 1020:64ef
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx] = memoryAGet16(ds, r16[si] + 10);
  case 0x166f2: // 1020:64f2
    r16[bx]--;
    r16[bx]--;
    if (signed16(memoryAGet16(ds, r16[bx])) >= signed16(0x0000))
        { pc = 0x166f2; break; }
    r16[bx]--;
    r16[bx]--;
    memoryASet16(ds, r16[si] + 10, r16[bx]);
    return;
  }
}
function* sub_166ff() // 1020:64ff
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    if (memoryAGet(ds, r16[si] + 7) & 0xc0)
        { pc = 0x1674b; break; }
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) & 0xdf);
    r16[bx] = memoryAGet16(ds, r16[si] + 10);
  case 0x1670c: // 1020:650c
    r16[ax] = memoryAGet16(ds, r16[bx]);
    if (r16s[ax] >= 0)
        { pc = 0x16716; break; }
    r16[bx] += r16[ax];
    { pc = 0x1670c; break; }
  case 0x16716: // 1020:6516
    if (r16[ax] != 0x55aa)
        { pc = 0x16727; break; }
    memoryASet16(ds, r16[di] + 4, 0xffff);
    memoryASet16(ds, r16[si] + 4, 0x05aa);
    { pc = 0x1675c; break; }
  case 0x16727: // 1020:6527
    r8[dh] = r8[ah];
    r8[dh] &= 0x20;
    r8[ah] &= 0xdf;
    memoryASet(ds, r16[si] + 7, memoryAGet(ds, r16[si] + 7) | r8[dh]);
    r8[dh] = memoryAGet(ds, r16[si] + 9);
    r8[dh] &= 0x80;
    r8[ah] |= r8[dh];
    memoryASet16(ds, r16[si] + 4, r16[ax]);
    r16[ax] += 0x0065;
    memoryASet16(ds, r16[di] + 4, r16[ax]);
    yield* sub_1675c();
    memoryASet16(ds, r16[si] + 10, r16[bx]);
    { pc = 0x16757; break; }
  case 0x1674b: // 1020:654b
    r16[ax] = memoryAGet16(ds, r16[si] + 4);
    r8[ah] &= 0xdf;
    r16[ax] += 0x0065;
    memoryASet16(ds, r16[di] + 4, r16[ax]);
  case 0x16757: // 1020:6557
    memoryASet(ds, r16[si] + 5, memoryAGet(ds, r16[si] + 5) | 0x20);
    return;
  case 0x1675c: // 1020:655c
    r16[bx]++;
    r16[bx]++;
    r16[ax] = memoryAGet16(ds, r16[bx]);
    if (r16s[ax] >= 0)
        { pc = 0x16766; break; }
    r16[bx] += r16[ax];
  case 0x16766: // 1020:6566
    return;
  }
}
function* sub_1675c() // 1020:655c
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    r16[bx]++;
    r16[bx]++;
    r16[ax] = memoryAGet16(ds, r16[bx]);
    if (r16s[ax] >= 0)
        { pc = 0x16766; break; }
    r16[bx] += r16[ax];
  case 0x16766: // 1020:6566
    return;
  }
}
function* sub_16767() // 1020:6567
{
    r8[cl] = 0x04;
    r16[ax] = memoryAGet16(ds, r16[si] + 2);
    r8[al] &= 0xf0;
    r16[ax] <<= r8[cl];
    r16[di] = memoryAGet16(ds, r16[si]);
    r16[di] >>= r8[cl];
    r16[di] += r16[ax];
    es = memoryAGet16(ds, 0x526c);
    r8[al] = memoryAGet(es, r16[di]);
    r16[bx] = 0x73a3;
    r8[al] = memoryAGet(ds, r16[bx] + r8[al]);
}
function* sub_16782() // 1020:6582
{
  var pc = 0;
  var temp_cf;
  while (1) switch(pc)
  {
  case 0:
    push(r16[bx]);
    push(r16[cx]);
    push(r16[si]);
    push(es);
    push(ds);
    r16[bx] = r16[ax];
    r16[ax] = 0xf000;
    es = ds; //r16[ax]; password from bios
    r16[ax] = 0x168f;
    ds = r16[ax];
    r16[si] = 0xfff0;
    r16[ax] = memoryAGet16(es, r16[bx]);
    r8[cl] = memoryAGet(cs, 0x0004);
    r8[al] += memoryAGet(es, r16[bx] + 61440);
    r8[ah] -= memoryAGet(es, r16[bx] + 61442);
    flags.carry = !!(r16[ax] & 16);
    r16[ax] = ror16(r16[ax], r8[cl]);
    r16[cx] = 0x0008;
  case 0x167ad: // 1020:65ad
    temp_cf = flags.carry;
    temp_cf = (r16[ax] + memoryAGet16(es, r16[si])) + flags.carry >= 0x10000;
    r16[ax] += memoryAGet16(es, r16[si]) + flags.carry;
    flags.carry = temp_cf;
    r16[si]++;
    r16[si]++;
    if (--r16[cx])
        { pc = 0x167ad; break; }
    r8[cl] = r8[bl];
    r16[ax] = rol16(r16[ax], r8[cl]);
    ds = pop();
    es = pop();
    r16[si] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    return;
  }
}
function* sub_167be() // 1020:65be
{
  var pc = 0;
  while (1) switch(pc)
  {
  case 0:
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(r16[di]);
    push(r16[si]);
    push(ds);
    push(es);
    push(r16[bp]);
    push(r16[si]);
    memoryASet(cs, 0x66d9, r8[al]);
    memoryASet(cs, 0x66da, r8[ah]);
    mul8(r8[ah]);
    memoryASet16(cs, 0x66dd, r16[ax]);
    r16[ax] = 0x168f;
    es = r16[ax];
    r16[ax] = memoryAGet16(es, 0x04c1);
    r16[ax] += 0x07d1;
    es = r16[ax];
    r16[di] = 0;
    r16[bp] = 0;
  case 0x167e9: // 1020:65e9
    r8[al] = memoryAGet(cs, 0x66da);
    memoryASet(cs, 0x66d8, r8[al]);
  case 0x167f1: // 1020:65f1
    r16[bx] = memoryAGet16(cs, 0x66dd);
    r8[ah] = memoryAGet(ds, r16[bx] + r16[si]);
    r16[dx] = 0;
    memoryASet16(cs, 0x66db, r16[dx]);
    if (memoryAGet(cs, 0x66df) != r8[dl])
        { pc = 0x16811; break; }
    r16[bx] <<= 1;
    r8[dl] = memoryAGet(ds, r16[bx] + r16[si]);
    r16[bx] += memoryAGet16(cs, 0x66dd);
    r8[dh] = memoryAGet(ds, r16[bx] + r16[si]);
  case 0x16811: // 1020:6611
    r8[al] = lodsb_DSSI();
    r16[cx] = 0x0008;
  case 0x16815: // 1020:6615
    r16[bx] = 0;
    flags.carry = !!(r8[dh] & 0x80);
    r8[dh] <<= 1;
    r16[bx] = rcl16(r16[bx], 0x0001);
    flags.carry = !!(r8[dl] & 0x80);
    r8[dl] <<= 1;
    r16[bx] = rcl16(r16[bx], 0x0001);
    flags.carry = !!(r8[ah] & 0x80);
    r8[ah] <<= 1;
    r16[bx] = rcl16(r16[bx], 0x0001);
    flags.carry = !!(r8[al] & 0x80);
    r8[al] <<= 1;
    r16[bx] = rcl16(r16[bx], 0x0001);
    r16[bx] <<= 1;
    r16[bx] += r16[bp];
    r16[bx] += memoryAGet16(cs, 0x6676);
    r8[bl] = memoryAGet(cs, r16[bx]);
    r16[bp] ^= 0x0001;
    flags.carry = !!(r8[bl] & 0x80);
    r8[bl] <<= 1;
    memoryASet16(cs, 0x66db, rcl16(memoryAGet16(cs, 0x66db), 0x01));
    flags.carry = !!(r8[bl] & 0x80);
    r8[bl] <<= 1;
    memoryASet16(cs, 0x66db, rcl16(memoryAGet16(cs, 0x66db), 0x01));
    if (--r16[cx])
        { pc = 0x16815; break; }
    r16[ax] = memoryAGet16(cs, 0x66db);
    r8[tl] = r8[ah]; r8[ah] = r8[al]; r8[al] = r8[tl];
    stosw_ESDI(r16[ax]);
    memoryASet(cs, 0x66d8, memoryAGet(cs, 0x66d8) - 1);
    if (memoryAGet(cs, 0x66d8))
        { pc = 0x167f1; break; }
    r16[bp] ^= 0x0001;
    memoryASet(cs, 0x66d9, memoryAGet(cs, 0x66d9) - 1);
    if (memoryAGet(cs, 0x66d9))
        { pc = 0x167e9; break; }
    r16[di] = pop();
    r16[si] = 0;
    push(ds);
    push(es);
    ds = pop();
    es = pop();
    r16[cx] = memoryAGet16(cs, 0x66dd);
    for (; r16[cx] != 0; --r16[cx]) movsw_ESDI_DSSI();
    r16[bp] = pop();
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
}
function fixReloc(seg)
{
        memoryASet16(0x0020 + seg, 0x0050, memoryAGet16(0x0020 + seg, 0x0050) + seg); // 068f -> 168f; lin=250
        memoryASet16(0x0020 + seg, 0x0066, memoryAGet16(0x0020 + seg, 0x0066) + seg); // 0690 -> 1690; lin=266
        memoryASet16(0x0020 + seg, 0x007f, memoryAGet16(0x0020 + seg, 0x007f) + seg); // 068f -> 168f; lin=27f
        memoryASet16(0x0020 + seg, 0x0084, memoryAGet16(0x0020 + seg, 0x0084) + seg); // 068f -> 168f; lin=284
        memoryASet16(0x0020 + seg, 0x00f9, memoryAGet16(0x0020 + seg, 0x00f9) + seg); // 068f -> 168f; lin=2f9
        memoryASet16(0x0020 + seg, 0x0118, memoryAGet16(0x0020 + seg, 0x0118) + seg); // 068f -> 168f; lin=318
        memoryASet16(0x0020 + seg, 0x0159, memoryAGet16(0x0020 + seg, 0x0159) + seg); // 068f -> 168f; lin=359
        memoryASet16(0x0020 + seg, 0x017d, memoryAGet16(0x0020 + seg, 0x017d) + seg); // 068f -> 168f; lin=37d
        memoryASet16(0x0020 + seg, 0x01f9, memoryAGet16(0x0020 + seg, 0x01f9) + seg); // 068f -> 168f; lin=3f9
        memoryASet16(0x0020 + seg, 0x0284, memoryAGet16(0x0020 + seg, 0x0284) + seg); // 068f -> 168f; lin=484
        memoryASet16(0x0020 + seg, 0x033d, memoryAGet16(0x0020 + seg, 0x033d) + seg); // 068f -> 168f; lin=53d
        memoryASet16(0x0020 + seg, 0x038b, memoryAGet16(0x0020 + seg, 0x038b) + seg); // 068f -> 168f; lin=58b
        memoryASet16(0x0020 + seg, 0x03af, memoryAGet16(0x0020 + seg, 0x03af) + seg); // 068f -> 168f; lin=5af
        memoryASet16(0x0020 + seg, 0x03f3, memoryAGet16(0x0020 + seg, 0x03f3) + seg); // 068f -> 168f; lin=5f3
        memoryASet16(0x0020 + seg, 0x04be, memoryAGet16(0x0020 + seg, 0x04be) + seg); // 068f -> 168f; lin=6be
        memoryASet16(0x0020 + seg, 0x05d1, memoryAGet16(0x0020 + seg, 0x05d1) + seg); // 068f -> 168f; lin=7d1
        memoryASet16(0x0020 + seg, 0x0702, memoryAGet16(0x0020 + seg, 0x0702) + seg); // 068f -> 168f; lin=902
        memoryASet16(0x0020 + seg, 0x080f, memoryAGet16(0x0020 + seg, 0x080f) + seg); // 068f -> 168f; lin=a0f
        memoryASet16(0x0020 + seg, 0x08d6, memoryAGet16(0x0020 + seg, 0x08d6) + seg); // 068f -> 168f; lin=ad6
        memoryASet16(0x0020 + seg, 0x08eb, memoryAGet16(0x0020 + seg, 0x08eb) + seg); // 068f -> 168f; lin=aeb
        memoryASet16(0x0020 + seg, 0x0903, memoryAGet16(0x0020 + seg, 0x0903) + seg); // 068f -> 168f; lin=b03
        memoryASet16(0x0020 + seg, 0x097c, memoryAGet16(0x0020 + seg, 0x097c) + seg); // 068f -> 168f; lin=b7c
        memoryASet16(0x0020 + seg, 0x0ae9, memoryAGet16(0x0020 + seg, 0x0ae9) + seg); // 068f -> 168f; lin=ce9
        memoryASet16(0x0020 + seg, 0x0b0c, memoryAGet16(0x0020 + seg, 0x0b0c) + seg); // 068f -> 168f; lin=d0c
        memoryASet16(0x0020 + seg, 0x0c15, memoryAGet16(0x0020 + seg, 0x0c15) + seg); // 068f -> 168f; lin=e15
        memoryASet16(0x0020 + seg, 0x0cf2, memoryAGet16(0x0020 + seg, 0x0cf2) + seg); // 068f -> 168f; lin=ef2
        memoryASet16(0x0020 + seg, 0x0d31, memoryAGet16(0x0020 + seg, 0x0d31) + seg); // 068f -> 168f; lin=f31
        memoryASet16(0x0020 + seg, 0x0d56, memoryAGet16(0x0020 + seg, 0x0d56) + seg); // 068f -> 168f; lin=f56
        memoryASet16(0x0020 + seg, 0x0e5b, memoryAGet16(0x0020 + seg, 0x0e5b) + seg); // 068f -> 168f; lin=105b
        memoryASet16(0x0020 + seg, 0x0e93, memoryAGet16(0x0020 + seg, 0x0e93) + seg); // 068f -> 168f; lin=1093
        memoryASet16(0x0020 + seg, 0x1081, memoryAGet16(0x0020 + seg, 0x1081) + seg); // 068f -> 168f; lin=1281
        memoryASet16(0x0020 + seg, 0x10d4, memoryAGet16(0x0020 + seg, 0x10d4) + seg); // 068f -> 168f; lin=12d4
        memoryASet16(0x0020 + seg, 0x1109, memoryAGet16(0x0020 + seg, 0x1109) + seg); // 068f -> 168f; lin=1309
        memoryASet16(0x0020 + seg, 0x11a2, memoryAGet16(0x0020 + seg, 0x11a2) + seg); // 068f -> 168f; lin=13a2
        memoryASet16(0x0020 + seg, 0x11f0, memoryAGet16(0x0020 + seg, 0x11f0) + seg); // 068f -> 168f; lin=13f0
        memoryASet16(0x0020 + seg, 0x1235, memoryAGet16(0x0020 + seg, 0x1235) + seg); // 068f -> 168f; lin=1435
        memoryASet16(0x0020 + seg, 0x12b6, memoryAGet16(0x0020 + seg, 0x12b6) + seg); // 068f -> 168f; lin=14b6
        memoryASet16(0x0020 + seg, 0x1345, memoryAGet16(0x0020 + seg, 0x1345) + seg); // 068f -> 168f; lin=1545
        memoryASet16(0x0020 + seg, 0x16f0, memoryAGet16(0x0020 + seg, 0x16f0) + seg); // 068f -> 168f; lin=18f0
        memoryASet16(0x068f + seg, 0x0435, memoryAGet16(0x068f + seg, 0x0435) + seg); // 0020 -> 1020; lin=6d25
        memoryASet16(0x068f + seg, 0x0439, memoryAGet16(0x068f + seg, 0x0439) + seg); // 0020 -> 1020; lin=6d29
        memoryASet16(0x0020 + seg, 0x17ff, memoryAGet16(0x0020 + seg, 0x17ff) + seg); // 068f -> 168f; lin=19ff
        memoryASet16(0x0020 + seg, 0x1840, memoryAGet16(0x0020 + seg, 0x1840) + seg); // 068f -> 168f; lin=1a40
        memoryASet16(0x0020 + seg, 0x1926, memoryAGet16(0x0020 + seg, 0x1926) + seg); // 068f -> 168f; lin=1b26
        memoryASet16(0x0020 + seg, 0x1962, memoryAGet16(0x0020 + seg, 0x1962) + seg); // 068f -> 168f; lin=1b62
        memoryASet16(0x0020 + seg, 0x1a9e, memoryAGet16(0x0020 + seg, 0x1a9e) + seg); // 068f -> 168f; lin=1c9e
        memoryASet16(0x0020 + seg, 0x1c6b, memoryAGet16(0x0020 + seg, 0x1c6b) + seg); // 068f -> 168f; lin=1e6b
        memoryASet16(0x0020 + seg, 0x24ab, memoryAGet16(0x0020 + seg, 0x24ab) + seg); // 068f -> 168f; lin=26ab
        memoryASet16(0x0020 + seg, 0x24d3, memoryAGet16(0x0020 + seg, 0x24d3) + seg); // 068f -> 168f; lin=26d3
        memoryASet16(0x0020 + seg, 0x2571, memoryAGet16(0x0020 + seg, 0x2571) + seg); // 068f -> 168f; lin=2771
        memoryASet16(0x0020 + seg, 0x2609, memoryAGet16(0x0020 + seg, 0x2609) + seg); // 068f -> 168f; lin=2809
        memoryASet16(0x0020 + seg, 0x2672, memoryAGet16(0x0020 + seg, 0x2672) + seg); // 068f -> 168f; lin=2872
        memoryASet16(0x0020 + seg, 0x26ec, memoryAGet16(0x0020 + seg, 0x26ec) + seg); // 068f -> 168f; lin=28ec
        memoryASet16(0x0020 + seg, 0x26f3, memoryAGet16(0x0020 + seg, 0x26f3) + seg); // 068f -> 168f; lin=28f3
        memoryASet16(0x0020 + seg, 0x2779, memoryAGet16(0x0020 + seg, 0x2779) + seg); // 068f -> 168f; lin=2979
        memoryASet16(0x0020 + seg, 0x282e, memoryAGet16(0x0020 + seg, 0x282e) + seg); // 068f -> 168f; lin=2a2e
        memoryASet16(0x0020 + seg, 0x2916, memoryAGet16(0x0020 + seg, 0x2916) + seg); // 068f -> 168f; lin=2b16
        memoryASet16(0x0020 + seg, 0x2951, memoryAGet16(0x0020 + seg, 0x2951) + seg); // 068f -> 168f; lin=2b51
        memoryASet16(0x0020 + seg, 0x2999, memoryAGet16(0x0020 + seg, 0x2999) + seg); // 068f -> 168f; lin=2b99
        memoryASet16(0x0020 + seg, 0x29ba, memoryAGet16(0x0020 + seg, 0x29ba) + seg); // 068f -> 168f; lin=2bba
        memoryASet16(0x0020 + seg, 0x2bac, memoryAGet16(0x0020 + seg, 0x2bac) + seg); // 068f -> 168f; lin=2dac
        memoryASet16(0x0020 + seg, 0x2c98, memoryAGet16(0x0020 + seg, 0x2c98) + seg); // 068f -> 168f; lin=2e98
        memoryASet16(0x0020 + seg, 0x2d01, memoryAGet16(0x0020 + seg, 0x2d01) + seg); // 068f -> 168f; lin=2f01
        memoryASet16(0x0020 + seg, 0x2d65, memoryAGet16(0x0020 + seg, 0x2d65) + seg); // 068f -> 168f; lin=2f65
        memoryASet16(0x0020 + seg, 0x2e60, memoryAGet16(0x0020 + seg, 0x2e60) + seg); // 068f -> 168f; lin=3060
        memoryASet16(0x0020 + seg, 0x2eb9, memoryAGet16(0x0020 + seg, 0x2eb9) + seg); // 068f -> 168f; lin=30b9
        memoryASet16(0x0020 + seg, 0x2eed, memoryAGet16(0x0020 + seg, 0x2eed) + seg); // 068f -> 168f; lin=30ed
        memoryASet16(0x0020 + seg, 0x2f13, memoryAGet16(0x0020 + seg, 0x2f13) + seg); // 068f -> 168f; lin=3113
        memoryASet16(0x0020 + seg, 0x2f77, memoryAGet16(0x0020 + seg, 0x2f77) + seg); // 068f -> 168f; lin=3177
        memoryASet16(0x0020 + seg, 0x2fe4, memoryAGet16(0x0020 + seg, 0x2fe4) + seg); // 068f -> 168f; lin=31e4
        memoryASet16(0x0020 + seg, 0x307e, memoryAGet16(0x0020 + seg, 0x307e) + seg); // 068f -> 168f; lin=327e
        memoryASet16(0x0020 + seg, 0x317a, memoryAGet16(0x0020 + seg, 0x317a) + seg); // 068f -> 168f; lin=337a
        memoryASet16(0x0020 + seg, 0x31c6, memoryAGet16(0x0020 + seg, 0x31c6) + seg); // 068f -> 168f; lin=33c6
        memoryASet16(0x0020 + seg, 0x31ea, memoryAGet16(0x0020 + seg, 0x31ea) + seg); // 068f -> 168f; lin=33ea
        memoryASet16(0x0020 + seg, 0x3280, memoryAGet16(0x0020 + seg, 0x3280) + seg); // 068f -> 168f; lin=3480
        memoryASet16(0x0020 + seg, 0x350f, memoryAGet16(0x0020 + seg, 0x350f) + seg); // 068f -> 168f; lin=370f
        memoryASet16(0x0020 + seg, 0x378f, memoryAGet16(0x0020 + seg, 0x378f) + seg); // 068f -> 168f; lin=398f
        memoryASet16(0x0020 + seg, 0x38b6, memoryAGet16(0x0020 + seg, 0x38b6) + seg); // 068f -> 168f; lin=3ab6
        memoryASet16(0x0020 + seg, 0x3e29, memoryAGet16(0x0020 + seg, 0x3e29) + seg); // 068f -> 168f; lin=4029
        memoryASet16(0x0020 + seg, 0x3eec, memoryAGet16(0x0020 + seg, 0x3eec) + seg); // 068f -> 168f; lin=40ec
        memoryASet16(0x0020 + seg, 0x3f47, memoryAGet16(0x0020 + seg, 0x3f47) + seg); // 068f -> 168f; lin=4147
        memoryASet16(0x0020 + seg, 0x3f75, memoryAGet16(0x0020 + seg, 0x3f75) + seg); // 068f -> 168f; lin=4175
        memoryASet16(0x0020 + seg, 0x403d, memoryAGet16(0x0020 + seg, 0x403d) + seg); // 068f -> 168f; lin=423d
        memoryASet16(0x0020 + seg, 0x4155, memoryAGet16(0x0020 + seg, 0x4155) + seg); // 068f -> 168f; lin=4355
        memoryASet16(0x0020 + seg, 0x51c7, memoryAGet16(0x0020 + seg, 0x51c7) + seg); // 068f -> 168f; lin=53c7
        memoryASet16(0x0020 + seg, 0x52ed, memoryAGet16(0x0020 + seg, 0x52ed) + seg); // 068f -> 168f; lin=54ed
        memoryASet16(0x0020 + seg, 0x5339, memoryAGet16(0x0020 + seg, 0x5339) + seg); // 068f -> 168f; lin=5539
        memoryASet16(0x0020 + seg, 0x53a3, memoryAGet16(0x0020 + seg, 0x53a3) + seg); // 068f -> 168f; lin=55a3
        memoryASet16(0x0020 + seg, 0x53e6, memoryAGet16(0x0020 + seg, 0x53e6) + seg); // 068f -> 168f; lin=55e6
        memoryASet16(0x0020 + seg, 0x542f, memoryAGet16(0x0020 + seg, 0x542f) + seg); // 068f -> 168f; lin=562f
        memoryASet16(0x0020 + seg, 0x543d, memoryAGet16(0x0020 + seg, 0x543d) + seg); // 068f -> 168f; lin=563d
        memoryASet16(0x0020 + seg, 0x5491, memoryAGet16(0x0020 + seg, 0x5491) + seg); // 068f -> 168f; lin=5691
        memoryASet16(0x0020 + seg, 0x5546, memoryAGet16(0x0020 + seg, 0x5546) + seg); // 068f -> 168f; lin=5746
        memoryASet16(0x0020 + seg, 0x562e, memoryAGet16(0x0020 + seg, 0x562e) + seg); // 068f -> 168f; lin=582e
        memoryASet16(0x0020 + seg, 0x56d0, memoryAGet16(0x0020 + seg, 0x56d0) + seg); // 068f -> 168f; lin=58d0
        memoryASet16(0x0020 + seg, 0x5946, memoryAGet16(0x0020 + seg, 0x5946) + seg); // 068f -> 168f; lin=5b46
        memoryASet16(0x0020 + seg, 0x658f, memoryAGet16(0x0020 + seg, 0x658f) + seg); // 068f -> 168f; lin=678f
        memoryASet16(0x0020 + seg, 0x65d8, memoryAGet16(0x0020 + seg, 0x65d8) + seg); // 068f -> 168f; lin=67d8
}


