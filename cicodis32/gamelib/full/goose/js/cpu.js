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

function load(path, name, size)
{
  var b = Module[name.toLowerCase()];
  var ofs = cs*16 - headerSize;
  for (var i=0; i<b.length; i++)
    memory[i+ofs] = b[i];
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
function cbw()
{
    r8[ah] = (r8[al] & 0x80) ? 0xff : 0;
}
function sar16(a, b)
{
    r16[tx] = a;
    r16s[tx] >>= b;
    return r16[tx];
}
function stosw_video_forward()
{
    assert(es*16 + di < memory.length && di <= 0xffff && flags.direction == 0);
    assert(es >= 0xa000);

    EGA.write(es*16 + di++, r8[al]);
    EGA.write(es*16 + di++, r8[ah]);
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
function rep_stosb_video_forward()
{
  assert(r16[cx]);
  while (r16[cx]--) 
    stosb_video_forward();
  r16[cx] = 0;
}
function lodsb_data_forward()
{
  assert(ds < 0xa000 && ds*16 + si < memory.length && si <= 0xffff);
  r8[al] = memory[ds*16 + si++];
}
function stosw_data_forward()
{
    assert(es*16 + di < memory.length && di <= 0xffff);
    assert(es < 0xa000);
    memory[es*16 + di++] = r8[al];
    memory[es*16 + di++] = r8[ah];
}
function rep_stosw_data_forward()
{
  while (r16[cx]--) 
    stosw_data_forward();
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
  assert(ds*16 + si < memory.length && es*16 + di < memory.length);

  while (r16[cx]--) 
  {
    EGA.write(es*16 + di++, memory[ds*16+si++]);
  }
  r16[cx] = 0;
}
function movsw_data_data_forward()
{
  assert(ds && es)
  assert(es < 0xa000 && ds < 0xa000 && r16[cx] > 0 && flags.direction == 0);
  assert(ds*16 + si < memory.length && es*16 + di < memory.length);

  memory[es*16 + di++] = memory[ds*16 + si++];
  memory[es*16 + di++] = memory[ds*16 + si++];
}
function div8(r)
{
    [r8[al], r8[ah]] = [r16[ax] / r, r16[ax] % r];
}
