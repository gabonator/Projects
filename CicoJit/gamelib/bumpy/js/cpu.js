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

// mess
EGA.init();
var can = document.getElementById("canvas");
var ctx = can.getContext('2d');
can.width = 320;
can.height = 200;
var data = ctx.createImageData(can.width, can.height);

function load(path, name, size)
{
  console.log("load");
  var b = Module[name];
  var ofs = cs*16 - headerSize;
  for (var i=0; i<b.length; i++)
    memory[i+ofs] = b[i];
}
// cpu
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
  var i = seg*16+ofs;
  assert(i < memory.length);

  memory[i] = v & 0xff;
  memory[i+1] = v >> 8;
}
function memory16get(seg, ofs)
{
  var i = seg*16+ofs;
  assert(i < memory.length);
  return memory[i] | (memory[i+1]<<8);
}
function memory16gets(seg, ofs)
{
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
function signed32(v)
{
  return v;
}

// alu
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
function imul16(w)
{
    var v = r16s[ax] * signed16(w);
    r16[ax] = v & 0xffff;
    r16[dx] = v >> 16;
}
function mul16(v16)
{
    var v = v16 * r16[ax];
    r16[ax] = v & 0xffff;
    r16[dx] = v >> 16;
}
function sar16(a, b)
{
    r16[tx] = a;
    r16s[tx] >>= b;
    return r16[tx];
}
function mul8(v)
{
    r16[ax] *= v;
}
function div16(r)
{
    [r16[ax], r16[bx]] = [r16[ax] / r, r16[ax] % r];
}
function idiv16(r)
{
    var n = signed32((r16[dx] << 16) | r16[ax]);
    [r16[ax], r16[dx]] = [n / r, n % r];
}
function mul16(r)
{
    r *= r16[ax];
    [r16[ax], r16[dx]] = [r, r >> 16];
}

// strings
function repne_scasb_bios_forward(value)
{                                  
    flags.zero = 0;
    while (r16[cx] != 0 && flags.zero == 0)
    {
        flags.zero = value == memoryBiosGet(es, di);
        di++;
        r16[cx]--;
    }
}
function repne_scasb_psp_forward(value)
{                                  
    flags.zero = 0;
    while (r16[cx] != 0 && flags.zero == 0)
    {
        flags.zero = value == memoryPspGet(es, di);
        di++;
        r16[cx]--;
    }
}
function rep_stosb_data_forward()
{
  assert(es < 0xa000 && r16[cx] > 0 && es*16 + di < memory.length && di <= 0xffff && di + r16[cx] <= 0xffff );

  while (r16[cx]--)              
    memory[es*16 + di++] = r8[al];
  r16[cx] = 0;
}
function stosw_video_forward()
{
    assert(es*16 + di < memory.length && di <= 0xffff && flags.direction == 0);
    assert(es >= 0xa000);

    EGA.write(es*16 + di++, r8[al]);
    EGA.write(es*16 + di++, r8[ah]);
}
function rep_stosw_video_forward()
{
  assert(r16[cx]);
  while (r16[cx]--) 
    stosw_video_forward();
  r16[cx] = 0;
}
function lodsb_es_bios_forward()
{
  assert(es < 0xa000 && es*16 + si < memory.length && si <= 0xffff);
  r8[al] = memoryBiosGet(es, si++);
}
function lodsb_es_psp_forward()
{
  assert(es < 0xa000 && es*16 + si < memory.length && si <= 0xffff);
  r8[al] = memoryPspGet(es, si++);
}
function lodsb_ss_data_forward()
{
  assert(ss < 0xa000 && ss*16 + si < memory.length && si <= 0xffff);
  r8[al] = memory[ss*16 + si++];
}
function rep_movsb_data_bios_forward()
{
  assert(es < 0xa000 && ds < 0xa000 && r16[cx] > 0 && si <= 0xffff && di <= 0xffff);
  assert(ds*16 + si < memory.length && es*16 + di < memory.length);

  while (r16[cx]--) 
    memory[es*16 + di++] = memoryBiosGet(ds, si++);
  r16[cx] = 0;
}
function rep_movsb_data_psp_forward()
{
  assert(es < 0xa000 && ds < 0xa000 && r16[cx] > 0 && si <= 0xffff && di <= 0xffff);
  assert(ds*16 + si < memory.length && es*16 + di < memory.length);

  while (r16[cx]--) 
    memory[es*16 + di++] = memoryPspGet(ds, si++);
  r16[cx] = 0;
}
function stosb_data_forward()
{
  assert(es < 0xa000 && es*16 + di < memory.length && di <= 0xffff);
  memory[es*16 + di++] = r8[al];
}
function lodsb_bios_forward()
{
  assert(ds < 0xa000 && si <= 0xffff);
  r8[al] = memoryBiosGet(ds, si++);
}
function lodsb_psp_forward()
{
  assert(ds < 0xa000 && si <= 0xffff);
  r8[al] = memoryPspGet(ds, si++);
}
function lodsw_data_forward()
{
  assert(ds < 0xa000 && ds*16 + si < memory.length && si <= 0xffff);
  r8[al] = memory[ds*16 + si++];
  r8[ah] = memory[ds*16 + si++];
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
function rep_movsw_video_data_forward()
{
  assert(es >= 0xa000 && ds < 0xa000 && r16[cx] > 0 && si <= 0xffff && di <= 0xffff);
  assert(ds*16 + si < memory.length);
  while (r16[cx]--) 
  {
    EGA.write(es*16 + di++, memory[ds*16 + si++]);
    EGA.write(es*16 + di++, memory[ds*16 + si++]);
  }
  r16[cx] = 0;
}
function movsb_data_video_forward()
{
  assert(es < 0xa000 && ds >= 0xa000 && si <= 0xffff && di <= 0xffff);
  assert(es*16 + di < memory.length);
  memory[es*16 + di++] = EGA.read(ds*16 + si++);
}
function movsb_video_data_forward()
{
  assert(es >= 0xa000 && ds < 0xa000 && si <= 0xffff && di <= 0xffff);
  assert(ds*16 + si < memory.length);
  EGA.write(es*16 + di++, memory[ds*16 + si++]);
}
function rep_movsw_data_video_forward()
{
  assert(es < 0xa000 && ds >= 0xa000 && r16[cx] > 0 && si <= 0xffff && di <= 0xffff);
  assert(es*16 + di < memory.length);
  while (r16[cx]--) 
  {
    memory[es*16 + di++] = EGA.read(ds*16 + si++);
    memory[es*16 + di++] = EGA.read(ds*16 + si++);
  }
  r16[cx] = 0;
}

// bios / psp
function memoryBiosSet16(seg, ofs, v)
{
}
function memoryBiosGet16(seg, ofs)
{
    if (seg == 0x0040 && ofs == 0x0063)
        return 0x3d4;
    if (seg == 0x0040 && ofs == 0x0080)
        return 0x1e;
    return 0;
}
function memoryPspGet16(seg, ofs)
{
    if ((seg == 0x01dd || seg == 0x01ed || seg == 0x01d3) && ofs < 256)
    {
        if (seg==0x1d3)
            return memoryBiosGet(seg, ofs) | (memoryBiosGet(seg, ofs) << 8);
        assert(seg == 0x1dd);
        switch (ofs)
        {
            case 0x02:
                // Segment of the first byte beyond the memory allocated to the program
                return 0x9fff;
            case 0x2c:
                // Environment segment
                return 0x1d3;
            default:
                assert(0);
                return 0;
        }

        assert(0);
    }
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
    assert(0);
    return 0;
}
function memoryPspGet(seg, ofs)
{
    if (seg == 0x1d3)
    {
        var env = "PATH=Z:\\" + "\x00" + "COMSPEC=Z:\\COMMAND.COM" + "\x00" +
          "BLASTER=A220 I7 D1 H5 T6" + "\x00\x00\x01\x00" + "C:\\BUM\\B.EXE" +
          "\x00\x00\x00\x00\x00\x00\x00";
        if (ofs<env.length)
            return env.charCodeAt(ofs);
        return 0;
    }
}
// dos
function interrupt(i)
{
    if (i == 0x21 && r8[ah] == 0x30)
    {
        r16[ax] = 0x0005;
        r16[bx] = 0xff00;
        r16[cx] = 0x0000;
        return;
    }
    if (i == 0x21 && r8[ah] == 0x35)
        return; // get int vect
    if (i == 0x21 && r8[ah] == 0x25)
        return; // get int vect
    if (i == 0x21 && r8[ah] == 0x4c)
        throw "end program";
    if (i == 0x21 && r8[ah] == 0x40)
        return;
    if (i == 0x21 && r8[ah] == 0x4a)
    {
        flags.carry = false;
        return;
    }
    if (i == 0x1A)
    {
        var now = new Date().getTime() / 1000;
        if (r8[ah] == 4)
        {            
        }
        else if (r8[ah] == 0)
        {
           if (!window.baseTick)
               window.baseTick = now;
            now -= window.baseTick;
            now = now / 6;
            r16[cx] = now >> 16;
            r16[dx] = now & 0xffff;
        } else {
            window.baseTick = now;
        }
        return;
    }
    if (i == 0x21 && r8[ah] == 0x44)
    {
        r16[ax] = 0x80d3;
        r16[dx] = 0x80d3;
        flags.carry = 0;
        return;
    }
    if (i == 0x21 && r8[ah] == 0x48)
    {
        if (!window.freeMem)
            window.freeMem = 0x1d9e;
        r16[ax] = window.freeMem;
        window.freeMem += r16[bx];
        window.freeMem ++;
        flags.carry = false;
        return;
    }
    if (i == 0x33)
    {
        r16[ax] = 0;
        return;
    }
    if (i == 0x10)
    {
        if (r8[ah] == 0)
            return;
        if (r8[ah] == 2)
            return;
    }
    if (i == 0x21 && r8[ah] == 0x09)
    {
        var str = "";
        for (var i=0; i<100; i++)
        {
            var c = String.fromCharCode(memory[ds*16+r16[dx]+i]);
            if (c=='$' || c == "\0")
                break;
            str += c;
        }
        console.log(str);
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
            filename += c;
        }
        console.log("Open: " + filename);
        if (!Module[filename])
          throw "resource not found";
        window.currentFile = {ofs:0, len:Module[filename].length, data:Module[filename]};
        flags.carry = 0;
        r16[ax] = 1;
        return; 
    }
    if (i == 0x21 && r8[ah] == 0x3f)
    {
        var bytes = Math.min(r16[cx], window.currentFile.len); 
        var wptr = ds*16+r16[dx];
        var rptr = window.currentFile.ofs;
        r16[ax] = bytes;
        window.currentFile.ofs += bytes;
        while (bytes--)
            memory[wptr++] = window.currentFile.data[rptr++];
        flags.carry = 0;
        return;
    }
    if (i == 0x21 && r8[ah] == 0x3e)
    {   
        window.currentFile = null;
        return;
    }
    console.log("unimplemented interrupt ", i.toString(16), r8[ah].toString(16));
    assert(0);
}
function out8(port, v)
{
  if (port == 0x43 || port == 0x40 || port == 0x201)
    return;
  EGA.PortWrite8(port, v);
}
function out16(port, v)
{
  EGA.PortWrite16(port, v);
}
function in8(port)
{
    if (port == 0x3da)
    {
        if (!("incounter" in window))
            window.incounter = 0;
        return (window.incounter++ & 1) ? 9 : 0;
    }
    if (port == 0x40)
    {
        if (!("incounter" in window))
            window.incounter = 0;
        return (window.incounter++ & 2) ? 0xff:0x00;
    }
    if (port == 0x201)
    {
        return 0;
    }
    if (port == 0x3d4 || port == 0x3d5)
    {
        return EGA.PortRead8(port);
    }

    assert(0);
}

function* sync(k)
{
  yield 0;
}
