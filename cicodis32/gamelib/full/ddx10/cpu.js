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
const memorybuf = new ArrayBuffer(1024*1024);
const memory = new Uint8Array(memorybuf, 0, 1024*1024);
const memorys = new Int8Array(memorybuf, 0, 1024*1024);
const memoryView = new DataView(memorybuf);
let allocatorPtr = 0x10080000;



function stop(msg)
{
  if (msg.indexOf("stack") != -1) return;
  console.trace();
  throw "stop"
}
function assert(cond)
{
  if (!cond)
  {                
//    console.trace();
    throw "assertion failed"
  }
}

function loadOverlay(file, addr)
{
  let b = archive[file];
  for (let i=0; i<b.length; i++)
    memory[i+addr-0x10000000] = b[i];
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
/*
  if (ofs == 0x1008369c+100*4)
     console.log("write sample ", v.toString(16))
 if (ofs == 0x10081418 || ofs == 0x10080064)
   console.log("Write32: ", ofs.toString(16), v.toString(16), FromFp32(v))
//  if (ofs >= 0x100836c8 && ofs <= 0x10083ec8)
//    dbg();
  assert(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000);
*/
  ofs -= 0x10000000;
  memory[ofs] = v;
  memory[ofs+1] = v >> 8;
  memory[ofs+2] = v >> 16;
  memory[ofs+3] = v >> 24;
}
function memoryAGet32(seg, ofs)
{   
/*
  const pb = 0x10081084+8*96;
  if (ofs >= pb && ofs < pb + 96)
  {
    console.log("read patch ", (ofs-pb).toString(16));
  }
  if (!(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000))
    dbg();
  assert(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000);
*/
  ofs -= 0x10000000;
  return memory[ofs] | (memory[ofs+1]<<8) | (memory[ofs+2]<<16) | (memory[ofs+3]<<24);
}

function memoryASet16(seg, ofs, v)
{
  assert(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000);
  ofs -= 0x10000000;
  memory[ofs] = v & 0xff;
  memory[ofs+1] = v >> 8;
}
function memoryAGet16(seg, ofs)
{   
  assert(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000);
  ofs -= 0x10000000;
  return memory[ofs] | (memory[ofs+1]<<8);
}

function memoryASet(seg, ofs, v)
{
  assert(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000);
  ofs -= 0x10000000;
  memory[ofs] = v;
}
function memoryAGet(seg, ofs)
{   
  if (!(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000))
    dbg();
  assert(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000);
  ofs -= 0x10000000;
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

let flags = {carry:0, zero:0, direction:0, parity:0}

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
  return v;
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

function imul32(r) {
    // signed 32-bit operands
    const a = BigInt(r32[eax] | 0);
    const b = BigInt(r | 0);

    const num = a * b; // 64-bit signed result

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

function memoryAGet64(seg, ofs)
{
  //assert(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000);
 
  return memoryView.getBigUint64(ofs-0x10000000, true);
/*  
  ofs -= 0x10000000;
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
*/  
}

/*
  if (ofs == 0x10081080|| ofs == 0x10041598 || ofs == 0x10041590)
    console.log("write64: ", ofs.toString(16), FromFp64(v));
  if (ofs == 0x10081080+8)
  {
    console.log("write64: ", ofs.toString(16), FromFp64(v));
    if (FromFp64(v) > 10000)
      throw "bad"
  }
*/
/*
  if (ofs == 0x100800f8)
    console.log("write phase shift", v.toString(16), FromFp64(v))

  if (ofs == 0x10069f78)
  {
    console.log("write64Z: ", ofs.toString(16), FromFp64(v));
  }
  assert(ofs >= 0x10000000 + 0x1000 && ofs < 0x10000000 + 0xb0000);
*/

/*
function memoryASet64(seg, ofs, v)
{
  ofs -= 0x10000000;

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
*/
function memoryASet64(seg, ofs, v) {
  memoryView.setBigUint64(ofs - 0x10000000, BigInt(v), true);
}