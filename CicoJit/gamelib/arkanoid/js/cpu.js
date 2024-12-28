"use strict";
// index -> r16
var ax = 0, bx = 1, cx = 2, dx = 3, tx = 4
// index -> r8
var al = 0, ah = 1, bl = 2, bh = 3, cl = 4, ch = 5, dl = 6, dh = 7, tl = 8, th = 9;

var cs, ds, es, ss, sp, bp, si, di;

var r0 = new ArrayBuffer(16);
var r16 = new Uint16Array(r0, 0, 8);
var r16s = new Int16Array(r0, 0, 8);
var r8 = new Uint8Array(r0, 0, 16);
var r8s = new Int8Array(r0, 0, 16);

var memorybuf = new ArrayBuffer(0x10000*14);
var memory = new Uint8Array(memorybuf, 0, 0x10000*14);
var memorys = new Int8Array(memorybuf, 0, 0x10000*14);
var flags = {carry:0, direction:0, zero:0};

var headerSize = 0;
var loadAddress = 0;

function overlay(path, name, size, seg, ofs)
{
  while (ofs<0)
  {
      ofs += 0x10;
      seg--;
  }
  var b = Module[name];
  for (var i=0; i<b.length; i++)
    memory[seg*16+ofs+i] = b[i];
}

function assert(x)
{
  if (!x) 
  {
    console.log([ds, si, es, di].map(x=>x.toString(16)));
    throw new Error("assertion failed");
  }
}
function push(r)
{
    assert(sp >= 10 && sp < 0xfff0);
    sp -= 2;
    memory16set(ss, sp, r);
}
function pop()
{
    assert(sp >= 10 && sp < 0xfff0);
    var aux = memory16get(ss, sp);
    sp += 2;
    return aux;
}
function memory16set(seg, ofs, v)
{
  assert(ofs >= 0 && ofs < 0xffff);
  var i = seg*16+ofs;
  assert(i < memory.length);

  memory[i] = v & 0xff;
  memory[i+1] = v >> 8;
}
function memory16get(seg, ofs)
{
  assert(ofs >= 0 && ofs < 0xffff);
  var i = seg*16+ofs;
  assert(i < memory.length);
  return memory[i] | (memory[i+1]<<8);
}
function memory16gets(seg, ofs)
{
  assert(ofs >= 0 && ofs < 0xffff);
    var i = seg*16+ofs;
    assert(i < memory.length);
    r16[tx] = memory[i] | (memory[i+1]<<8);
    return r16s[tx];
}
function videoSet(seg, ofs, v)
{
  EGA.write(seg*16 + ofs, v);
}
function videoGet(seg, ofs)
{
  return EGA.read(seg*16 + ofs);
}
function signed8(v)
{
  r8[th] = v;
  return r8s[th];
}
function signed16(v)
{
  r16[tx] = v;
  return r16s[tx];
}
function rcr16(r, c)
{
    assert(c == 1);
    var newCarry = !!(r & 0x1);
    r >>= 1;
    r |= flags.carry ? 0x8000 : 0;
    flags.carry = newCarry;
    return r;
}
function mul16(v16)
{
    var v = v16 * r16[ax];
    r16[ax] = v & 0xffff;
    r16[dx] = v >> 16;
}
function mul8(v)
{
    r16[ax] = r8[al] * v;
}
function mul16(r)
{
    r *= r16[ax];
    [r16[ax], r16[dx]] = [r, r >> 16];
}
function rep_stosb_data_forward()
{
  assert(es < 0xa000 && r16[cx] > 0 && es*16 + di < memory.length && di <= 0xffff && di + r16[cx] <= 0xffff );

  while (r16[cx]--)              
    memory[es*16 + di++] = r8[al];
  r16[cx] = 0;
}
function stosb_video_forward()
{
    assert(es*16 + di < memory.length && di <= 0xffff && flags.direction == 0);
    assert(es >= 0xa000);

    EGA.write(es*16 + di++, r8[al]);
}
function rep_stosw_video_forward()
{
  assert(r16[cx]);
  while (r16[cx]--) 
    stosw_video_forward();
  r16[cx] = 0;
}
function lodsb_data_forward()
{
  assert(ds < 0xa000 && ds*16 + si < memory.length && si <= 0xffff);
  r8[al] = memory[ds*16 + si++];
}
function stosb_data_forward()
{
  assert(es < 0xa000 && es*16 + di < memory.length && di <= 0xffff);
  memory[es*16 + di++] = r8[al];
}
function lodsw_data_forward()
{
  assert(ds < 0xa000 && ds*16 + si < memory.length && si <= 0xffff);
  r8[al] = memory[ds*16 + si++];
  r8[ah] = memory[ds*16 + si++];
}
function rep_stosw_data_forward()
{
  while (r16[cx]--) 
    stosw_data_forward();
  r16[cx] = 0;
}
function rep_movsw_data_data_forward()
{
  assert(ds && es)
  assert(es < 0xa000 && ds < 0xa000 && r16[cx] > 0 && flags.direction == 0);
  assert(ds*16 + si < memory.length && es*16 + di < memory.length);

  while (r16[cx]--)
  { 
    memory[es*16 + di++] = memory[ds*16 + si++];
    memory[es*16 + di++] = memory[ds*16 + si++];
  }
  r16[cx] = 0;
}
function rep_movsb_data_data_forward()
{
  if (r16[cx] == 0)
    return;
  assert(ds && es)
  assert(es < 0xa000 && ds < 0xa000 && r16[cx] > 0 && flags.direction == 0);
  assert(ds*16 + si < memory.length && es*16 + di < memory.length);

  while (r16[cx]--)
    memory[es*16 + di++] = memory[ds*16 + si++];
  r16[cx] = 0;
}
function rep_movsb_video_video_forward()
{
  assert(ds && es)
  assert(es >= 0xa000 && ds >= 0xa000 && r16[cx] > 0 && flags.direction == 0);

  while (r16[cx]--)
    EGA.write(es*16 + di++, EGA.read(ds*16 + si++));
  r16[cx] = 0;
}
function rep_movsb_video_data_forward()
{
  assert(es >= 0xa000 && ds < 0xa000 && r16[cx] > 0 && si <= 0xffff && di <= 0xffff);
  assert(ds*16 + si < memory.length);

  while (r16[cx]--) 
  {
    EGA.write(es*16 + di++, memory[ds*16+si++]);
  }
  r16[cx] = 0;
}
function memoryBiosSet16(seg, ofs, v)
{
}
function memoryBiosGet16(seg, ofs)
{
    return 0;
}
function memoryBiosGet(seg, ofs)
{
    if (seg == 0x1dd && ofs == 0x80)
        return 0;
    if (seg == 0x1dd && ofs == 0x81)
        return 0x0d;
    if (seg == 0xffff && ofs == 0x000e)
        return 0xfc;
    if (seg == 0xf000 && ofs == 0xfffe)
        return 0xfc; // pc at
    if (seg == 0x0040 && ofs == 0x0087)
        return 0x00; // ega active
    if (seg == 0x0040 && ofs == 0x0088)
        return 0x09;
    if (seg == 0x0040 && ofs == 0x0017) 
        return 0x00; // shift keys
    if (seg == 0x0040 && ofs == 0x0010)
        return 0x26;
    if (seg == 0x0040 && ofs == 0x006c)
        return (new Date().getTime())/1000/54; // number of ticks since midnight 54ms
    if (seg == 0x0000 && ofs == 0x0000)
        return 0x1a;
    //assert(0);
    return 0;
}
function memoryBiosSet(seg, ofs, v)
{
}

// add
function stosw_video_forward()
{
    assert(es*16 + di < memory.length && di <= 0xffff);
    assert(es >= 0xa000);
    EGA.write(es*16 + di++, r8[al]);
    EGA.write(es*16 + di++, r8[ah]);
}

function daa()
{
    var oldcf = flags.carry;
    if ((r8[al] & 0xf) > 9)
    {
        r8[al] += 6;
        flags.carry = r8[al] < 6;
    }
    if ((r8[al] > 0x99) || oldcf)
    {
        r8[al] += 0x60;
        flags.carry = true;
    } else {
        flags.carry = false;
    }
}

function lodsb_video_forward()
{
  assert(ds >= 0xa000);
  r8[al] = EGA.read(ds*16 + si++);
}
