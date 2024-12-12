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
  var b = Module[name];
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
  video.write(seg*16 + ofs, v);
}
function rcl8(r, c)
{
    assert(c == 1);
    var newCarry = !!(r & 0x80);
    r <<= 1;
    r |= flags.carry ? 0x1 : 0;
    flags.carry = newCarry;
    return r;
}
function rcl16(r, c)
{
    assert(c == 1);
    var newCarry = !!(r & 0x8000);
    r <<= 1;
    r |= flags.carry ? 0x1 : 0;
    flags.carry = newCarry;
    return r;
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
function ror16(r, l)
{
    return (r >> l) | (r << (16-l));
}
function rol16(r, l)
{
    return (r << l) | (r >> (16-l));
}
function rol8(r, l)
{
    return (r << l) | (r >> (8-l));
}
function mul16(v16)
{
    var v = v16 * r16[ax];
    r16[ax] = v & 0xffff;
    r16[dx] = v >> 16;
}
function div16(r)
{
    [r16[ax], r16[dx]] = [r16[ax] / r, r16[ax] % r];
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

    video.write(es*16 + di++, r8[al]);
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
function rep_movsb_video_data_forward()
{
  assert(es >= 0xa000 && ds < 0xa000 && r16[cx] > 0 && si <= 0xffff && di <= 0xffff);
  assert(ds*16 + si < memory.length && es*16 + di < memory.length);

  while (r16[cx]--) 
  {
    video.write(es*16 + di++, memory[ds*16+si++]);
  }
  r16[cx] = 0;
}
function rep_movsb_data_video_forward()
{
  assert(ds && es)
  assert(es < 0xa000 && ds >= 0xa000 && r16[cx] > 0 && flags.direction == 0);

  while (r16[cx]--)
    memory[es*16 + di++] = video.read(ds*16 + si++);
  r16[cx] = 0;
}
