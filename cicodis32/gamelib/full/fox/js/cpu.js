//"use strict";
let cs, ds, es, ss, sp;
const ax = 0, bx = 1, cx = 2, dx = 3, tx = 4, si = 5, di = 6, bp = 7;
const al = 0, ah = 1, bl = 2, bh = 3, cl = 4, ch = 5, dl = 6, dh = 7, tl = 8, th = 9;
const r0 = new ArrayBuffer(16);
const r16 = new Uint16Array(r0, 0, 8);
const r16s = new Int16Array(r0, 0, 8);
const r8 = new Uint8Array(r0, 0, 16);
const r8s = new Int8Array(r0, 0, 16);
const memorybuf = new ArrayBuffer(0x10000*12);
const memory = new Uint8Array(memorybuf, 0, 0x10000*12);
const memorys = new Int8Array(memorybuf, 0, 0x10000*12);
const video = new Ega();

let files = {id:40, handles:{}};

function stop(msg)
{
  //if (msg == "stack_below") return;
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

function load(arch, exec, size)
{
  //var b = Module["main.exe"];
  let b = archive[exec];
  let ofs = loadAddress*16 - headerSize;
  for (let i=0; i<b.length; i++)
    memory[i+ofs] = b[i];
}

function push(r)
{
    //assert(sp >= 0 && sp < 0xfff0);
    sp -= 2;
    sp &= 0xffff;
//    console.log("st:push", ss.toString(16)+ ":" + sp.toString(16) + "="+ r.toString(16));
    memorySet16(ss, sp, r); // TODO: 
}
function pop()
{
    //assert(sp >= 0 && sp < 0xfff0);
    var aux = memoryGet16(ss, sp); // TODO:
//    console.log("st:pop ", ss.toString(16) + ":" + sp.toString(16)+ "="+ aux.toString(16));
    sp += 2;
    sp &= 0xffff;
    return aux;
}

function memoryASet16(seg, ofs, v)
{
  if (seg == 0x0000 && ofs > 0x0010 && ofs < 0x00a0)
    return;
  if (seg == 0x0040 && ofs == 0x004e)
    return;
  if (seg >= 0xa000 && seg < 0xc000)
  {
    memoryVideoSet(seg, ofs, v & 0xff);
    memoryVideoSet(seg, ofs+1, v >> 8);
    return;
  }
  assert(seg >= loadAddress-0x20);
  assert(seg < 0xa000);
  assert(ofs >= 0 && ofs < 0xffff);
  var i = seg*16+ofs;
  assert(i < memory.length);

  memory[i] = v & 0xff;
  memory[i+1] = v >> 8;
}
function memoryAGet16(seg, ofs)
{   
  ofs &= 0xffff;
  if (seg == 0x0000 && ofs > 0x0010 && ofs < 0x00a0)
    return 0;
  if (seg == 0x0040 && ofs == 0x0063)
    return 0x3d4;
  if (seg >= 0xa000 && seg < 0xc000)
  {
    return memoryVideoGet(seg, ofs) + memoryVideoGet(seg, ofs+1)*256;
  }
  assert(seg < 0xa000);
  assert(seg >= loadAddress-0x20);
  assert(ofs >= 0 && ofs < 0xffff);
  var i = seg*16+ofs;
  assert(i < memory.length);
  return memory[i] | (memory[i+1]<<8);
}

function memoryAGet32(seg, ofs)
{   
  let low = memoryAGet16(seg, ofs)
  let high = memoryAGet16(seg, ofs+2)
  assert(high < 0x8000);
  return (high<<16)|low;
}
function memoryAGet(seg, ofs)
{
  ofs &= 0xffff;
  if (seg >= 0xa000)
  {
    return video.read(seg*16+ofs);
  }
  assert(seg > loadAddress-0x20);
  assert(seg < 0xa000);
  assert(ofs >= 0 && ofs <= 0xffff);
  var i = seg*16+ofs;
  assert(i < memory.length);
  return memory[i];
}
function memoryASet(seg, ofs, v)
{
  if (seg == 0x0000 && ofs > 0x0010 && ofs < 0x00a0)
    return;
  if (seg >= 0xa000)
  {
    video.write(seg*16+ofs, v);
    return;
  }
  assert(seg > loadAddress-0x20);
  assert(seg < 0xa000);
  assert(ofs >= 0 && ofs < 0xffff);
  var i = seg*16+ofs;
  assert(i < memory.length);

  memory[i] = v;
}
function memoryGet(seg, ofs)
{
  let i = seg*16+ofs;
  assert(i >= 0x10000 && i < memory.length);
  return memory[i];
}

function memorySet(seg, ofs, v)
{
  let i = seg*16+ofs;
  assert(i >= 0x10000 && i < memory.length);
  memory[i] = v;
}

function memoryGet16(seg, ofs)
{
  let i = seg*16+ofs;
  assert(i >= 0x10000 && i < memory.length);
  return memory[i] | (memory[i+1]<<8);
}

function memorySet16(seg, ofs, v)
{
  let i = seg*16+ofs;
  assert(i >= 0x10000 && i < memory.length);
  memory[i] = v;
  memory[i+1] = v>>8;
}

function memoryVideoSet(seg, ofs, v)
{
  video.write(seg*16+ofs, v);
}

function memoryVideoGet(seg, ofs)
{
  return video.read(seg*16+ofs);
}

function memoryVideoGet16(seg, ofs)
{
  return video.read(seg*16+ofs) | (video.read(seg*16+ofs+1)<<8);
}


function memoryBiosGet16(seg, ofs)
{
  if (seg == 0x0040 && ofs == 0x0063)
    return 0x3d4;
  return 0;
}

function memoryBiosSet16(seg, ofs, v)
{
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
  if(flags.direction == 0)
    memoryASet(es, r16[di]++, memoryAGet(ds, r16[si]++));
  else
    memoryASet(es, r16[di]--, memoryAGet(ds, r16[si]--));
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
  if(flags.direction == 0)
    return memoryAGet(ds, r16[si]++);
  else
    return memoryAGet(ds, r16[si]--);
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



function out8(port, val) {
 console.log("out8", port.toString(16), val.toString(16))
}
let flags = {carry:0, zero:0}

function interrupt(i)
{
  console.log("interrupt", i.toString(16), r16[ax].toString(16))
}

function interrupt(i)
{
  if (i == 0x10 && video.interrupt(i))
    return;  
  if (i == 0x21 && r8[ah] == 0x35)
    return; // get int vect
  if (i == 0x21 && r8[ah] == 0x25)
    return; // set int vect
  if (i == 0x15 && r8[ah] == 0x84)
  {
      flags.carry = true;
      return;
  }
  if (i == 0x21 && r8[ah] == 0x2c)
  {
      r8[ch] = Math.random()*256;
      r8[cl] = Math.random()*256;
      r8[dh] = 117;
      r8[dl] = 150;
      return;
  }
  if (i == 0x21 && r8[ah] == 0x3d)
  {
      var filename = "";
      var dot = false;
      for (var i=0; i<100; i++)
      {
          var c = String.fromCharCode(memory[ds*16+r16[dx]+i]);
          if (c==' ')
              continue;
          if (c=='\0')
              break;
          if (c=='\\')
              c = "/";
          filename += c;
      }
      console.log("Open: " + filename);
      if (!archive[filename])
      {
        console.log("resource not found");
        flags.carry = 1;
        return;
      }
//      window.currentFile = {ofs:0, len:archive[filename].length, data:archive[filename]};
      flags.carry = 0;
      files.handles[files.id] = {ofs:0, len:archive[filename].length, data:archive[filename]};
      r16[ax] = files.id++;
      return; 
  }
  if (i == 0x21 && r8[ah] == 0x3f)
  {
      let file = files.handles[r16[bx]];
      var bytes = Math.min(r16[cx], file.len-file.ofs); 
console.log("read", bytes.toString(16));
      var wptr = ds*16+r16[dx];
      var rptr = file.ofs;
      r16[ax] = bytes;
      file.ofs += bytes;
      while (bytes--)
          memory[wptr++] = file.data[rptr++];
      flags.carry = 0;
      return;
  }
  if (i == 0x21 && r8[ah] == 0x3e)
  {   
      delete files.handles[r16[bx]]
      return;
  }
  if (i == 0x16 && r8[ah] == 0x01)
  {
      flags.zero = lastKey == null;
      return; 
  }
  if (i == 0x16 && r8[ah] == 0x00)
  {
      r16[ax] = lastKey;
      lastKey = -1;
      return; 
  }
  if (i == 0x21 && r8[ah] == 0x30)
  {
      r16[ax] = 0x0005;
      r16[bx] = 0xff00;
      r16[cx] = 0x0000;
      return;
  }
  if (i == 0x21 && r8[ah] == 0x44)
  {
//      r16[ax] = 2; // TODO
//      r16[dx] = 2;

      r16[ax] = 0x80d3; // TODO
      r16[dx] = 0x80d3;
      flags.carry = false;
      return;
  }
  if (i == 0x21 && r8[ah] == 0x42)
  {
      let file = files.handles[r16[bx]];
      if (r8[al] == 2 && r16[cx] == 0 && r16[dx] == 0)
      {
          r16[ax] = file.len;
          r16[dx] = file.ofs>>16;
          return;
      }
      if (r8[al] == 1)
      {
          file.ofs += r16[cx]*0x10000 + r16[dx];
          r16[ax] = file.ofs;
          r16[dx] = file.ofs>>16;
          flags.carry = false;
          return;
      }
      if (r8[al] == 0)
      {
          file.ofs = r16[cx]*0x10000 + r16[dx];
          r16[ax] = file.ofs;
          r16[dx] = file.ofs>>16;
          flags.carry = false;
          return;
      }
  }
  if (i == 0x21 && r8[ah] == 0x43)
  {
      r16[cx] = 1<<5;
      return;
  }
  if (i == 0x21 && r8[ah] == 0x40)
  {
      flags.carry = false;
      r16[ax] = r16[cx];
      return;
  }
  if (i == 0x21 && r8[ah] == 0x19)
  {
      r8[al] = 2;
      return;
  }
  if (i == 0x15 && r8[ah] == 0x06)
  {
      return;
  }
  if (i == 0x11)
  {
      r16[ax] = 0;
      return;
  }
  if (i == 0x33)
  {
//      r16[ax] = -1;
//      r16[bx] = 3;
      r16[ax] = 0;

      return;
  }
  if (i == 0x21 && r8[ah] == 0x4a)
  {
      console.log("Resize ", endAddress.toString(16), "->", (loadAddress+r16[bx]).toString(16))
      if (endAddress > loadAddress+r16[bx])
      {
        console.log("Bad impl, ignore");
        flags.carry = false;
        return;
      }
      assert(loadAddress+r16[bx] >= endAddress);
      endAddress = loadAddress+r16[bx];
      flags.carry = false;
      return;
  }
    if (i == 0x21 && r8[ah] == 0x48)
    {
        if (r16[bx]>=0xf000)
        {
            r16[bx] = 0x810c;
            flags.carry = true;
            return;
        }
        assert (r16[bx] < 0xf000);
        console.log("Alloc", r16[bx].toString(16), "->", endAddress.toString(16));
        r16[ax] = endAddress;
        endAddress += r16[bx];
        endAddress++;
        flags.carry = false;
        return;
    }
  if (i == 0x1a && r8[ah] == 0x00)
  {
    r16[cx] = 0;
    r16[dx] = 0;
    return;
  }
  if (i == 0x2f)
    return;
  if (i == 0x1a && r8[ah] == 0x04)
      return;
  console.log(i.toString(16), r8[ah].toString(16), r8[al].toString(16));
  throw "unhandled interrupt"
}
function cbw()
{
    r8[ah] = (r8[al] & 0x80) ? 0xff : 0;
}

function rcl8(r, c)
{
    assert(c == 1);
    var newCarry = !!(r & 0x80);
    r <<= 1;
    r |= flags.carry ? 1 : 0;
    flags.carry = newCarry;
    return r;
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

function rcr16(r, c)
{
    assert(c == 1);
    var newCarry = !!(r & 0x1);
    r >>= 1;
    r |= flags.carry ? 0x8000 : 0;
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
    [r16[ax], r16[dx]] = [r16[ax] / r, r16[ax] % r];
}
function div8(r)
{
    [r8[al], r8[ah]] = [r16[ax] / r, r16[ax] % r];
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
function rol16(r, l)
{
    return (r << l) | (r >> (16-l));
}
function ror16(r, l)
{
    return (r >> l) | (r << (16-l));
}
function ror8(r, l)
{
    return (r >> l) | (r << (8-l));
}
function rol8(r, l)
{
    return (r << l) | (r >> (8-l));
}

function mul8(v)
{
    r16[ax] = r8[al] * v;
}

function out8(port, val)
{
  if (port >= 0x200)
    video.portWrite8(port, val);
}
function out16(port, val)
{
  video.portWrite16(port, val);
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
    if (port == 0x3d4 || port == 0x3d5)
        return video.PortRead8(port);
  return 0;
}
var can = document.getElementById("canvas");
var ctx = can.getContext('2d');
can.width = 320;
can.height = 200;
var data = ctx.createImageData(can.width, can.height);

function display()
{
  var p = 0;
  var pixels = data.data;
    for (var x=0; x<200; x++)
  for (var y=0; y<320; y++)
    {
      var c = video.getPixel(y, x);
      pixels[p++] = c>>16;
      pixels[p++] = (c>>8)&0xff;
      pixels[p++] = c & 0xff;
      pixels[p++] = 255;
    }
  ctx.putImageData(data, 0, 0);
}
