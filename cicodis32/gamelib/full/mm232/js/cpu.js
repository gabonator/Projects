//"use strict";
let cs, ds, es, ss, sp;
const eax = 0, ebx = 1, ecx = 2, edx = 3, etx = 4, esi = 5, edi = 6, ebp = 7, esp = 8;
const ax = 0, bx = 2, cx = 4, dx = 6, tx = 8, si = 10, di = 12, bp = 14;
const al = 0, ah = 1, bl = 4, bh = 5, cl = 8, ch = 9, dl = 12, dh = 13, tl = 16, th = 17;
const r0 = new ArrayBuffer(64);
const r16 = new Uint16Array(r0, 0, 15);
const r16s = new Int16Array(r0, 0, 15);
const r8 = new Uint8Array(r0, 0, 18);
const r8s = new Int8Array(r0, 0, 18);
const r32 = new Uint32Array(r0, 0, 9);
const r32s = new Int32Array(r0, 0, 9);
const memorybuf = new ArrayBuffer(0x580000);
const memory = new Uint8Array(memorybuf, 0, 0x580000);
const memorys = new Int8Array(memorybuf, 0, 0x580000);
let allocatorPtr = 0x440000;

function stop(msg)
{
  if (msg == "stack_unbalanced") return;
  console.trace();
  throw "stop"
}
function assert(cond)
{
  if (!cond)
  {                
    console.trace();
    throw "assertion failed"
  }
}

function loadOverlay(file, addr)
{
  let b = archive[file];
  for (let i=0; i<b.length; i++)
    memory[i+addr] = b[i];
}

function push32(w)
{
  r32[esp] -= 4;
  memoryASet32(ss, r32[esp], w);
}

function pop32()
{
  let aux = memoryAGet32(ss, r32[esp]);
  r32[esp] += 4;
  return aux;
}
function stack32(n)
{
  return memoryAGet32(ss, r32[esp]+n*4);
}

const pop = pop32, push = push32;

function memoryASet32(seg, ofs, v)
{
  if (ofs >= 0xa0000 && ofs <= 0xa0000 + 320*240)
  {
    vga.memoryVideoSet32(seg, ofs, v);
    return;
  }

  assert(ofs < memory.length);
  memory[ofs] = v;
  memory[ofs+1] = v >> 8;
  memory[ofs+2] = v >> 16;
  memory[ofs+3] = v >> 24;
}
function memoryAGet32(seg, ofs)
{   
  if (ofs >= 0xa0000 && ofs <= 0xa0000 + 320*240)
    return vga.memoryVideoGet32(seg, ofs);

  assert(ofs < memory.length);
  return memory[ofs] | (memory[ofs+1]<<8) | (memory[ofs+2]<<16) | (memory[ofs+3]<<24);
}

function memoryASet16(seg, ofs, v)
{
  if (ofs >= 0xa0000 && ofs <= 0xa0000 + 320*240)
  {
    vga.memoryVideoSet16(seg, ofs, v);
    return;
  }

  assert(ofs < memory.length);
  memory[ofs] = v & 0xff;
  memory[ofs+1] = v >> 8;
}
function memoryAGet16(seg, ofs)
{   
  if (ofs >= 0xa0000 && ofs <= 0xa0000 + 320*240)
    return vga.memoryVideoGet16(seg, ofs);

  assert(ofs < memory.length);
  return memory[ofs] | (memory[ofs+1]<<8);
}

function memoryASet(seg, ofs, v)
{
  if (ofs >= 0xa0000 && ofs <= 0xa0000 + 320*240)
  {
    vga.memoryVideoSet(seg, ofs, v);
    return;
  }

  assert(ofs < memory.length);
  memory[ofs] = v;
}
function memoryAGet(seg, ofs)
{   
  if (ofs >= 0xa0000 && ofs <= 0xa0000 + 320*240)
    return vga.memoryVideoGet(seg, ofs);

if (memory[ofs] == "F".charCodeAt(0) &&memory[ofs+1] == "E".charCodeAt(0) && memory[ofs+2] == "R".charCodeAt(0))
{
  var f = 9;
}
  assert(ofs < memory.length);
  return memory[ofs];
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

function movsb_MemFwdESDI_MemFwdDSSI() 
{
  assert(flags.direction == 0);
  memorySet(es, r16[di]++, memoryGet(ds, r16[si]++));
}
function movsw_MemFwdESDI_MemFwdDSSI() 
{
  assert(flags.direction == 0);
  memorySet(es, r16[di]++, memoryGet(ds, r16[si]++));
  memorySet(es, r16[di]++, memoryGet(ds, r16[si]++));
}
function movsw_MemBwdESDI_MemBwdDSSI() 
{                              
  assert(flags.direction == 1);
  memorySet(es, r16[di]--, memoryGet(ds, r16[si]--));
  memorySet(es, r16[di]--, memoryGet(ds, r16[si]--));
}
function stosw_MemFwdESDI() 
{
  assert(flags.direction == 0);
  memorySet(es, r16[di]++, r8[al]);
  memorySet(es, r16[di]++, r8[ah]);
}

function movsw_VideoFwdESDI_VideoFwdDSSI() 
{
  assert(flags.direction == 0);
  memoryVideoSet(es, r16[di]++, memoryVideoGet(ds, r16[si]++));
  memoryVideoSet(es, r16[di]++, memoryVideoGet(ds, r16[si]++));
}

function movsw_VideoFwdESDI_MemFwdDSSI()
{
  assert(flags.direction == 0);
  memoryVideoSet(es, r16[di]++, memoryGet(ds, r16[si]++));
  memoryVideoSet(es, r16[di]++, memoryGet(ds, r16[si]++));
}

function movsb_VideoFwdESDI_MemFwdDSSI()
{
  assert(flags.direction == 0);
  memoryVideoSet(es, r16[di]++, memoryGet(ds, r16[si]++));
}

function movsb_VideoFwdESDI_VideoFwdDSSI() 
{
  assert(flags.direction == 0);
  memoryVideoSet(es, r16[di]++, memoryVideoGet(ds, r16[si]++));
}

function stosb_MemFwdESDI() 
{
  memorySet(es, r16[di]++, r8[al]);
}
function lodsb_VideoFwdDSSI() 
{ 
  assert(flags.direction == 0);
  return memoryVideoGet(ds, r16[si]++);
}
function stosb_VideoFwdESDI() 
{
  memoryVideoSet(es, r16[di]++, r8[al]);
}
function lodsb_MemFwdDSSI() 
{ 
  assert(flags.direction == 0);
  return memoryGet(ds, r16[si]++);
}

function lodsb_ESSI() 
{ 
  assert(flags.direction == 0);
  return memoryAGet(es, r16[si]++);
}

function lodsb_SSSI() 
{ 
  assert(flags.direction == 0);
  return memoryAGet(ss, r16[si]++);
}

function movsb_ESDI_DSSI() 
{
  assert(flags.direction == 0);
  memoryASet(es, r16[di]++, memoryAGet(ds, r16[si]++));
}
function movsb_ESEDI_DSESI() 
{
  assert(flags.direction == 0);
  memoryASet(es, r32[edi]++, memoryAGet(ds, r32[esi]++));
}

function movsw_ESDI_DSSI() 
{
  if(flags.direction == 0)
  {
    memoryASet(es, r16[di]++, memoryAGet(ds, r16[si]++));
    memoryASet(es, r16[di]++, memoryAGet(ds, r16[si]++));
  } else {
    memoryASet(es, r16[di]--, memoryAGet(ds, r16[si]--));
    memoryASet(es, r16[di]--, memoryAGet(ds, r16[si]--));
  }
}

function stosw_ESDI() 
{
  assert(flags.direction == 0);
  memoryASet(es, r16[di]++, r8[al]);
  memoryASet(es, r16[di]++, r8[ah]);
}
function stosw_ESEDI() 
{
  assert(flags.direction == 0);
  memoryASet(es, r32[edi]++, r8[al]);
  memoryASet(es, r32[edi]++, r8[ah]);
}
function stosb_ESEDI() 
{
  assert(flags.direction == 0);
  memoryASet(es, r32[edi]++, r8[al]);
}
function stosd_ESEDI() 
{
  assert(flags.direction == 0);
  memoryASet32(es, r32[edi], r32[eax]);
  r32[edi] += 4;
}
function lodsb_DSESI() 
{ 
  assert(flags.direction == 0);
  return memoryAGet(ds, r32[esi]++);
}
function lodsb_DSSI() 
{ 
  assert(flags.direction == 0);
  return memoryAGet(ds, r16[si]++);
}
function lodsw_DSSI() 
{ 
  assert(flags.direction == 0);
  let v = memoryAGet16(ds, r16[si]);
  r16[si] += 2;
  return v;
}
function stosb_ESDI() 
{
  memoryASet(es, r16[di]++, r8[al]);
}

function scasb_inv_ESDI(b) 
{ 
  assert(flags.direction == 0);
  flags.zero = memoryAGet(es, r16[di]++) == b;
}

function cmpsb_DSSI_ESDI() 
{ 
  assert(flags.direction == 0);
  flags.zero = memoryAGet(ds, r16[si]++) == memoryAGet(es, r16[di]++);
}

let flags = {carry:0, zero:0, direction:0}

function cbw()
{
    r8[ah] = (r8[al] & 0x80) ? 0xff : 0;
}
function rcr8(r, c)
{
    assert(c == 1);
    var newCarry = !!(r & 0x1);
    r >>= 1;
    r |= flags.carry ? 0x80 : 0;
    flags.carry = newCarry;
    return r;
}

function rcl16(r, c)
{
    assert(c == 1);
    var newCarry = !!(r & 0x8000);
    r <<= 1;
    r |= flags.carry ? 1 : 0;
    flags.carry = newCarry;
    return r;
}
function rcl32(r, c)
{
    assert(c === 1);
    r >>>= 0;
    var newCarry = !!(r & 0x80000000);
    r = (r << 1) >>> 0;
    r |= flags.carry ? 1 : 0;
    flags.carry = newCarry;
    return r;
}
function rcr32(r, c)
{
    assert(c === 1);
    r >>>= 0;
    var newCarry = !!(r & 1);
    r = (r >>> 1) >>> 0;
    r |= flags.carry ? 0x80000000 : 0;
    flags.carry = newCarry;
    return r;
}


function mul16(v16)
{
    var v = v16 * r16[ax];
    r16[ax] = v & 0xffff;
    r16[dx] = v >> 16;
}

function imul16(r)
{
    let v = signed16(r16[ax]) * signed16(r);
    r16[ax] = v & 0xffff;
    r16[dx] = v >> 16;
}

function div16(r)
{
    let res = Math.trunc(r16[ax] / r);
    let rem = r16[ax] % r;
    r16[ax] = res;
    r16[dx] = rem;
}

function signed32(v)
{
 // TODO: check?
  r32[etx] = v;
  return r32s[etx];
//  return v;
}

function idiv16(r)
{
// TODO: overflow?
    var n = signed32((r16[dx] << 16) | r16[ax]);
    [r16[ax], r16[dx]] = [n / r, n % r];
}

function sar8(a, b)
{
    r8[tl] = a;
    r8s[tl] >>= b;
    return r8[tl];
}
function sar16(a, b)
{
    r16[tx] = a;
    r16s[tx] >>= b;
    return r16[tx];
}
function sar32(a, b)
{
    r32[etx] = a;
    r32s[etx] >>= b;
    return r32[etx];
}
function rol16(r, l)
{
    return (r << l) | (r >> (16-l));
}

function* sync(k)
{
  yield 0;
}

function flagAsReg()
{
  return flags.zero + flags.carry*2;
}
function flagsFromReg(r)
{
  flags.zero = r &1;
  flags.carry = (r>>1) & 1;
}

let counter = 0;
function in8(port)
{
    if (port == 0x3da)
        return (counter++ & 1) ? 9 : 0;
    if (port == 0x40)
        return (counter++ & 2) ? 0xff:0x00;
    if (port == 0x201)
        return 0;
    return video.PortRead8(port);
  return 0;
}

function imul32(r) {
    // signed 32-bit operands
    const a = BigInt(r32[eax] | 0);
    const b = BigInt(r | 0);

    const num = a * b; // 64-bit signed result

    // write back low/high 32 bits
    r32[eax] = Number(num & 0xFFFFFFFFn) >>> 0;
    r32[edx] = Number((num >> 32n) & 0xFFFFFFFFn) >>> 0;
}

function mul32(r) {
    // unsigned 32-bit operands
    const a = BigInt(r32[eax] >>> 0);
    const b = BigInt(r >>> 0);

    const num = a * b; // 64-bit unsigned result

    // write back low/high 32 bits
    r32[eax] = Number(num & 0xFFFFFFFFn) >>> 0;
    r32[edx] = Number((num >> 32n) & 0xFFFFFFFFn) >>> 0;
}

function idiv32(r) {
    const divisor = BigInt(r | 0);

    // construct signed 64-bit numerator: EDX:EAX
    const hi = BigInt(r32[edx] | 0);
    const lo = BigInt(r32[eax] >>> 0);

    const num = (hi << 32n) | lo;

    const q = num / divisor; // truncates toward zero
    const rem = num % divisor;

    r32[eax] = Number(q & 0xFFFFFFFFn);
    r32[edx] = Number(rem & 0xFFFFFFFFn);
}
function scasb_inv_ESEDI(b) 
{ 
  assert(flags.direction == 0);
  flags.zero = memoryAGet(es, r32[edi]++) == b;
}

function movsd_ESEDI_DSESI() 
{
  assert(flags.direction == 0);
  memoryASet32(es, r32[edi], memoryAGet32(ds, r32[esi]));
  r32[esi] += 4;
  r32[edi] += 4;
}
function movsw_ESEDI_DSESI() 
{
  assert(flags.direction == 0);
  memoryASet16(es, r32[edi], memoryAGet16(ds, r32[esi]));
  r32[esi] += 2;
  r32[edi] += 2;
}

function memoryAGet64(seg, ofs)
{
  return (
    BigInt(memory[ofs]) |
    (BigInt(memory[ofs + 1]) << 8n) |
    (BigInt(memory[ofs + 2]) << 16n) |
    (BigInt(memory[ofs + 3]) << 24n) |
    (BigInt(memory[ofs + 4]) << 32n) |
    (BigInt(memory[ofs + 5]) << 40n) |
    (BigInt(memory[ofs + 6]) << 48n) |
    (BigInt(memory[ofs + 7]) << 56n)
  );
}

function memoryASet64(seg, ofs, v)
{
  v = BigInt(v);

  memory[ofs]     = Number(v & 0xFFn);
  memory[ofs + 1] = Number((v >> 8n)  & 0xFFn);
  memory[ofs + 2] = Number((v >> 16n) & 0xFFn);
  memory[ofs + 3] = Number((v >> 24n) & 0xFFn);
  memory[ofs + 4] = Number((v >> 32n) & 0xFFn);
  memory[ofs + 5] = Number((v >> 40n) & 0xFFn);
  memory[ofs + 6] = Number((v >> 48n) & 0xFFn);
  memory[ofs + 7] = Number((v >> 56n) & 0xFFn);
}


function overflow32(a, b, c) 
{
  if (c)
    return overflow32(b, c) || overflow32(a, b + c);
  return a > 0xFFFFFFFF - b;
}

function flagAsReg32()
{
  return 0;
}

function flagsFromReg32()
{
  console.log("flags from reg - ignored")
}
/*
function ror32(r, l)
{
    l &= 31;          // rotate count mod 32
    r >>>= 0;         // force unsigned 32-bit
    return ((r >>> l) | (r << (32 - l))) >>> 0;
}*/
function ror32(r, l) {
    l &= 31;
    r >>>= 0;
    // split into two 16-bit halves to avoid JS signed shift issues
    const high = (r >>> 16) & 0xFFFF;
    const low = r & 0xFFFF;
    if (l === 16) {
        return ((low << 16) | high) >>> 0;
    }
    return ((r >>> l) | (r << (32 - l))) >>> 0;
}

function ror8(r, l)
{
    return (r >> l) | (r << (8-l));
}

function rol8(r, l)
{
    return (r << l) | (r >> (8-l));
}

function ror16(r, l)
{
    return (r >> l) | (r << (16-l));
}

function mul8(v)
{
    r16[ax] = r8[al] * v;
}

function div16(r)
{
    [r16[ax], r16[dx]] = [r16[ax] / r, r16[ax] % r];
}
function div8(r)
{
    [r8[al], r8[ah]] = [r16[ax] / r, r16[ax] % r];
}

function rol32(r, l)
{
    l &= 31;          // rotate count mod 32
    r >>>= 0;         // force unsigned 32-bit
    return ((r << l) | (r >>> (32 - l))) >>> 0;
}

function div32(r)
{
    const dividend =
        (BigInt(r32[edx] >>> 0) << 32n) |
         BigInt(r32[eax] >>> 0);

    const divisor = BigInt(r >>> 0);

    const q = dividend / divisor;
    const rem = dividend % divisor;

    r32[eax] = Number(q & 0xFFFFFFFFn) >>> 0;
    r32[edx] = Number(rem & 0xFFFFFFFFn) >>> 0;
}
