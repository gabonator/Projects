// index -> r16
var ax = 0, bx = 1, cx = 2, dx = 3, tx = 4, si = 5, di = 6;
// index -> r8
var al = 0, ah = 1, bl = 2, bh = 3, cl = 4, ch = 5, dl = 6, dh = 7, tl = 8, th = 9;
// other registers
var ds = 0, es = 0;
var bp = 0, sp = 0x100;

//start();

var _freeMem = 0x2000;
var _currentFile;
var video;
var ega = new EGA();
var vga = new VGA();

function interrupt(i)
{
    if (i == 0x10)
    {
       if (video && video.Interrupt())
         return;
    }

    if (i == 0x1A && r8[ah] == 0x00)
    {
        // time of day
        r16[cx] = 1;
        r16[dx] = 1;
        return;
    }
    if (i == 0x1a && r8[ah] == 0x04)
    {
        r16[cx] = 0x2022;
         
//        console.log("ignore timer " + r8[ah].toString(16));
        return;
    }


    if (i == 0x16 && r8[ah] == 0x00)
    {
        r8[ah] = 0x1c;
        return;
    }
    if (i == 0x10 && r8[ah] == 0x1a)
    {
        //https://dos4gw.org/INT_10H_1aH_Set_or_Query_Display_Combination_Code
        r8[al] = 0x1a;
        r8[bl] = 0x08; // vga color
        return;            
    }
    if (i == 0x10 && r8[ah] == 0x0f)
        return;
    if (i == 0x10 && r8[ah] == 0x01)
        return;
    if (i == 0x10 && r8[ah] == 0x06)
        return;
    if (i == 0x10 && r8[ah] == 0x02)
        return;
    if (i == 0x10 && r8[ah] == 0x09)
        return;
    if (i == 0x10 && r8[ah] == 0x00)
    {
        console.log("Set video mode " + r8[al]);
        if (r8[al] == 0x0d)
          video = ega; //new EGA(); 
        else
        if (r8[al] == 0x13)
          video = vga;
        else
          throw "Unkown video mode";

        return;
    }
    if (i == 0x10 && video.Interrupt())
        return;

    if (i == 0x80)
    {
        sub_24B90();
        return;
    }

    if (i == 0x21 && r8[ah] == 0x25)
        return; // set int vect
    if (i == 0x21 && r8[ah] == 0x35)
        return; // get int vect

    if (i == 0x21 && r8[ah] == 0x3d)
    {   // open file
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
                c='/';
            filename += c;
        }
        console.log("Open: " + filename);
        filename = filename.toLowerCase();
        if (!Module[filename])
        {
          throw "resource not found";
        }
        _currentFile = {ofs:0, len:Module[filename].length, data:Module[filename]};
        flags.carry = 0;
        r16[ax] = 1;
        return; 
    }
    if (i == 0x21 && r8[ah] == 0x3f)
    {
        var bytes = Math.min(r16[cx], _currentFile.len-_currentFile.ofs); 
        console.log("Read " + r16[cx].toString(16) + " (" + bytes + ")");
        var wptr = ds*16+r16[dx];
        var rptr = _currentFile.ofs;
        _currentFile.ofs += bytes;
        r16[ax] = bytes;
        while(bytes--)
            memory[wptr++] = _currentFile.data[rptr++];
        flags.carry = 0;
        return;
    }

    if (i == 0x21 && r8[ah] == 0x3e)
    {   // close file
        console.log("Close");
        _currentFile = null;
        return;
    }

    if (i == 0x21 && r8[ah] == 0x42 && r8[al] == 0x00 && r16[dx] == 0)
    {   // seek

        _currentFile.ofs = r16[cx];
        return;
    }

    console.log("Interrupt " + i.toString(16) + " ah="  + r8[ah].toString(16) + " al="+r8[al].toString(16));

    throw "uknown int";
    if (i == 0x21 && r8[ah] == 0x4a)
    {   // resize block
        flags.carry = false;
        return;
    }
    if (i == 0x21 && r8[ah] == 0x48)
    {   // malloc
        r16[ax] = _freeMem;
        _freeMem += r16[bx];
        flags.carry = false;
        return;
    }
    if (i == 0x21 && r8[ah] == 0x25)
        return; // set int vect
    if (i == 0x21 && r8[ah] == 0x35)
        return; // get int vect
    if (i == 0x21 && r8[ah] == 0x3d)
    {   // open file
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
        _currentFile = {ofs:0, len:Module[filename].length, data:Module[filename]};
        flags.carry = 0;
        r16[ax] = 1;
        return; 
    }

    if (i == 0x21 && r8[ah] == 0x3e)
    {   // close file
        _currentFile = null;
        return;
    }

    if (i == 0x10 && r8[ah] == 0x0f)
        return;
    if (i == 0x10 && r8[ah] == 0x00)
        return;
    if (i == 0x10 && r8[ah] == 0x10 && r8[al] == 0)
    {
        //EGA.SetPaletteIndex(r8[bl], r8[bh]);
        return;
    }
/*
    if (i == 0x10 && r16[ax] == 0x1012)
    {
      for (var i=0; i<r16[cx]; i++)
      {
        var r = memory[es*16+r16[dx]+i*3]*4;
        var g = memory[es*16+r16[dx]+i*3+1]*4;
        var b = memory[es*16+r16[dx]+i*3+2]*4;
        video.palette[i] = b | (g << 8) | (r << 16);
      }
    }
*/
}

function out8(p, v)
{
    if (video && video.PortWrite8(p, v))
        return;
    if (p == 0x388 || p == 0x389)
    {
        console.log("sound");
        return;
    }
    if (p == 0x3c9 || p == 0x3c8)
        return;
    console.log("out8: "+p.toString(16) + " <- " + v.toString(16));
}
function out16(p, v)
{
    if (video && video.PortWrite16(p, v))
        return;
    console.log("out16: "+p.toString(16) + " <- " + v.toString(16));
}

function lodsb_data_forward()
{
  assert(ds < 0xa000 && ds*16 + r16[si] < memory.length && r16[si] <= 0xffff);
  r8[al] = memory[ds*16 + r16[si]++];
}

function lodsb_data_backward()
{
  assert(ds < 0xa000 && ds*16 + r16[si] < memory.length && r16[si] <= 0xffff);
  r8[al] = memory[ds*16 + r16[si]--];
}


function lodsw_data_forward()
{
  assert(ds < 0xa000 && ds*16 + r16[si] < memory.length && r16[si] <= 0xffff);
  r8[al] = memory[ds*16 + r16[si]++];
  r8[ah] = memory[ds*16 + r16[si]++];
}

function lodsb_video_forward()
{
  assert(ds >= 0xa000 && r16[si] <= 0xffff);
  r8[al] = video.read(ds*16 + r16[si]++);
}

function movsb_video_video_forward()
{
  assert(es >= 0xa000 && ds >= 0xa000 && r16[si] <= 0xffff && r16[di] <= 0xffff);
  video.write(es*16 + r16[di]++, video.read(ds*16 + r16[si]++));
}

function movsb_video_data_forward()
{
  assert(es >= 0xa000 && ds < 0xa000 && r16[si] <= 0xffff && r16[di] <= 0xffff);
  video.write(es*16 + r16[di]++, memory[ds*16 + r16[si]++]);
}

function movsb_auto_auto_auto()
{
  if (es < 0xa000 && ds < 0xa000)
    movsb_data_data_forward();
  else
  if (es >= 0xa000 && ds < 0xa000)
    movsb_video_data_forward();
  else
  if (es >= 0xa000 && ds >= 0xa000)
    movsb_video_video_forward(); 
  else
    assert(0);
}

function stosb_data_forward()
{
  assert(es < 0xa000  && es*16 + r16[di] < memory.length && r16[di] <= 0xffff);

  memory[es*16 + r16[di]++] = r8[al];
}

function stosb_video_forward()
{
  assert(es >= 0xa000);
  video.write(es*16 + r16[di]++, r8[al]);
}

function rep_stosb_data_forward()
{
  assert(es < 0xa000 && r16[cx] > 0 && es*16 + r16[di] < memory.length && r16[di] <= 0xffff);

  while (r16[cx]--)              
    memory[es*16 + r16[di]++] = r8[al];
  r16[cx] = 0;
}

function rep_stosw_video_forward()
{
  assert(es >= 0xa000 && r16[cx] > 0 && r16[di] <= 0xffff);

  while (r16[cx]--)              
  {
    video.write(es*16 + r16[di]++, r8[al]);
    video.write(es*16 + r16[di]++, r8[ah]);
  }
  r16[cx] = 0;
}

function stosw_video_forward()
{
  assert(es >= 0xa000 && r16[di] <= 0xffff);
  video.write(es*16 + r16[di]++, r8[al]);
  video.write(es*16 + r16[di]++, r8[ah]);
}

function rep_stosb_video_forward()
{
  assert(es >= 0xa000 && r16[cx] > 0 && r16[di] <= 0xffff);

  while (r16[cx]--)
    video.write(es*16 + r16[di]++, r8[al]); 
  r16[cx] = 0;
}

function rep_movsb_data_data_forward()
{
  assert(es < 0xa000 && ds < 0xa000 && r16[cx] > 0 && r16[si] <= 0xffff && r16[di] <= 0xffff);
  assert(ds*16 + r16[si] < memory.length && es*16 + r16[di] < memory.length);

  while (r16[cx]--) 
    memory[es*16 + r16[di]++] = memory[ds*16 + r16[si]++];
  r16[cx] = 0;
}

function rep_movsb_data_data_backward()
{
  assert(es < 0xa000 && ds < 0xa000 && r16[cx] > 0 && r16[si] <= 0xffff && r16[di] <= 0xffff);
  assert(ds*16 + r16[si] < memory.length && es*16 + r16[di] < memory.length);

  while (r16[cx]--) 
    memory[es*16 + r16[di]--] = memory[ds*16 + r16[si]--];
  r16[cx] = 0;
}

function rep_movsb_video_data_forward()
{
  assert(es >= 0xa000 && ds < 0xa000 && r16[cx] > 0 && r16[si] <= 0xffff && r16[di] <= 0xffff);
  assert(ds*16 + r16[si] < memory.length && es*16 + r16[di] < memory.length);

  while (r16[cx]--) 
    video.write(es*16 + r16[di]++, memory[ds*16 + r16[si]++]);
  r16[cx] = 0;
}

function movsb_data_data_forward()
{
  assert(es < 0xa000 && ds < 0xa000);

  memory[es*16 + r16[di]++] = memory[ds*16 + r16[si]++];
}

function movsw_data_data_forward()
{
  assert(ds && es)
  assert(es < 0xa000 && ds < 0xa000);

  memory[es*16 + r16[di]++] = memory[ds*16 + r16[si]++];
  memory[es*16 + r16[di]++] = memory[ds*16 + r16[si]++];
}

function rep_movsw_data_data_forward()
{
  assert(ds && es)

  assert(es < 0xa000 && ds < 0xa000 && r16[cx] > 0);
  assert(ds*16 + r16[si] < memory.length && es*16 + r16[di] < memory.length);

  while (r16[cx]--)
  { 
    memory[es*16 + r16[di]++] = memory[ds*16 + r16[si]++];
    memory[es*16 + r16[di]++] = memory[ds*16 + r16[si]++];
  }
  r16[cx] = 0;
}

function rep_movsw_data_data_backward()
{
  assert(es < 0xa000 && ds < 0xa000 && r16[cx] > 0 && r16[si] <= 0xffff && r16[di] <= 0xffff);
  assert(ds*16 + r16[si] < memory.length && es*16 + r16[di] < memory.length);

  while (r16[cx]--)
  { 
    memory[es*16 + r16[di]--] = memory[ds*16 + r16[si]--];
    memory[es*16 + r16[di]--] = memory[ds*16 + r16[si]--];
  }
  r16[cx] = 0;
}

function rep_movsb_video_video_forward()
{
  assert(es >= 0xa000 && ds >= 0xa000 && r16[si] <= 0xffff && r16[di] <= 0xffff);

  while (r16[cx]--) 
    video.write(es*16 + r16[di]++, video.read(ds*16 + r16[si]++));
  r16[cx] = 0;
}


function rep_movsw_video_data_forward()
{
  assert(es >= 0xa000 && ds < 0xa000 && r16[cx] > 0 && r16[si] <= 0xffff && r16[di] <= 0xffff);
  assert(ds*16 + r16[si] < memory.length);
  while (r16[cx]--) 
  {
    video.write(es*16 + r16[di]++, memory[ds*16 + r16[si]++]);
    video.write(es*16 + r16[di]++, memory[ds*16 + r16[si]++]);
  }
  r16[cx] = 0;
}

function stosw_data_forward()
{
    assert(es*16 + r16[di] < memory.length && r16[di] <= 0xffff);

    assert(es < 0xa000);
    memory[es*16 + r16[di]++] = r8[al];
    memory[es*16 + r16[di]++] = r8[ah];
}


function stosw_bios_forward()
{
    bios16set(es, r16[di]++, r8[al]);
    bios16set(es, r16[di]++, r8[ah]);
}

function rep_stosw_data_forward()
{
  while (r16[cx]--) 
    stosw_data_forward();
  r16[cx] = 0;
}


function push(i)
{
    sp -= 2;
    memory16set(ss*16+sp, i);
}
function pop()
{
    var o = memory16get(ss*16+sp);
    sp += 2;
    return o;
}

function _lea(r, s, o)
{
  r16[r] = o;
}

function memory16set(i, v)
{
  assert(i < memory.length);

  memory[i] = v & 0xff;
  memory[i+1] = v >> 8;
}
function memory16get(i)
{
  assert(i < memory.length);
  return memory[i] | (memory[i+1]<<8);
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

function _cwd()
{
    if (r16[ax] & 0x8000)
        r16[dx] = 0xffff;
    else
        r16[dx] = 0x0000;
}

function rcr8(r, c)
{
    assert(c == 1);
    var newCarry = !!(r8[r] & 0x1);
    r8[r] >>= 1;
    r8[r] |= flags.carry ? 0x80 : 0;
    flags.carry = newCarry;
}

function rcr16(r, c)
{
    assert(c == 1);
    var newCarry = !!(r16[r] & 1);
    r16[r] >>= 1;
    r16[r] |= flags.carry ? 0x8000 : 0x0000;
    flags.carry = newCarry;
}

function rcl16(r, c)
{
    assert(c == 1);
    var newCarry = !!(r16[r] & 0x8000);
    r16[r] <<= 1;
    r16[r] |= flags.carry;
    flags.carry = newCarry;
}

function _idiv(d)
{
    // DX:AX / d -> AX result, DX remainder
    var dw = (r16s[dx] << 16) | r16[ax];
    var result = dw / d;
    var remainder = dw % d;
    r16[ax] = result;
    r16[dx] = remainder;
}

/*
function imul16(w)
{
    var v = r16s[ax] * signed16(w);
    r16[ax] = v & 0xffff;
    r16[dx] = v >> 16;
}
*/
function sar8(r, c)
{
    r8s[r] >>= c;
}

function sar16(r, c)
{
    r16s[r] >>= c;
}

function rol16(r, c)
{
    assert(c>=0 && c<8);
    r16[r] = (r16[r] << c) | (r16[r] >> (16-c));
}

/*function rol8(r, c)
{
    assert(c>=1 && c<8);
    r8[r] = (r8[r] << c) | (r8[r] >> (8-c));
} */

function rol8(r, c)
{
    assert(c>=0 && c<8);
    r8[r] = (r8[r] << c) | (r8[r] >> (8-c));
}

function ror8(r, c)
{
    assert(c>=0 && c<8);
    r8[r] = (r8[r] >> c) | (r8[r] << (8-c));
}

function ror16(r, c)
{
    assert(c>=0 && c<16);
    r16[r] = (r16[r] >> c) | (r16[r] << (16-c));
}

function _cbw()
{
    r8[ah] = (r8[al] & 0x80) ? 0xff : 0x00;
}

function xchg8(a, b)
{
  var t = r8[a];
  r8[a] = r8[b];
  r8[b] = t;
}

function xchg16(a, b)
{          
  var t = r16[a];
  r16[a] = r16[b];
  r16[b] = t;
}

function xchgr16(r, addr)
{          
  var t = r16[r];
  r16[r] = memory16get(addr);
  memory16set(addr, t)
}
/*
function div(r)
{
    assert(r != 0);
    var result = r16[ax] / r;
    var remain = r16[ax] % r;
    r16[ax] = result;
    r16[dx] = remain;
}
*/

function _div16(v)
{
    assert(v != 0);
    var result = Math.floor(r16[ax] / v);
    var remain = r16[ax] % v;
    r16[ax] = result;
    r16[dx] = remain;
}

function _div8(v)
{
    assert(v != 0);
    var result = Math.floor(r16[ax] / v);
    var remain = r16[ax] % v;
    r8[al] = result;
    r8[ah] = remain;
}

/*
function _mul(v16)
{
//  r16[ax] = v16 * r8[al];
    var v = v16 * r16[ax];
    r16[ax] = v & 0xffff;
    r16[dx] = v >> 16;
}
*/

function _mul16(w)
{
    var v = w * r16[ax];
    r16[ax] = v & 0xffff;
    r16[dx] = v >> 16;
}

function _mul8(b)
{
    var v = b * r8[al];
    r16[ax] = v & 0xffff;
}

function les(r, seg, ofs)
{
    r16[r] = memory16get(seg*16 + ofs);
    es = memory16get(seg*16 + ofs + 2);
}

function memory16gets(i)
{
    r16[tx] = memory[i] | (memory[i+1]<<8);
    return r16s[tx];
}

function memoryBiosGet16(seg, ofs)
{
    if (seg == 0x0040 && ofs == 0x0063)
        return 0x3d4;
    throw "not supported";
}

function memoryBiosSet16(seg, ofs, data)
{
    //word 0040:004E  Offset to the current display page
    if (ofs == 0x4E)
        return;
    throw "not supported";
}

function memoryVideoGet(seg, ofs)
{
    return video.read(seg*16+ofs);
}

function memoryVideoGet16(seg, ofs)
{
    return video.read(seg*16+ ofs) | (video.read(seg*16+ofs+1)<<8);
}

function memoryVideoSet(seg, ofs, v)
{
    return video.write(seg*16+ofs, v);
}

function memoryVideoSet16(seg, ofs, w)
{
    video.write(seg*16+ofs+1, w>>8);
    video.write(seg*16+ofs, w & 255);
}

function memoryVideoAnd(seg, ofs, v)
{
    video.write(seg*16+ofs, video.read(seg*16+ofs) & v);
}

function memoryVideoOr(seg, ofs, v)
{
    video.write(seg*16+ofs, video.read(seg*16+ofs) | v);
}

function memoryVideoAdd(seg, ofs, v)
{
    video.write(seg*16+ofs, video.read(seg*16+ofs) + v);
}


function _repne_scasb()
{
    assert(flags.direction == 0);
    flags.zero = 0;
    while ( r16[cx]-- && flags.zero == 0 )
    {
        flags.zero = (r8[al] - memory[es*16+ r16[di]]) == 0;
        r16[di]++;
    }
}

var _retrace = 0;
function in8(port)
{
  if (port == 0x61)
    return 0;
  if (port == 0x201)
    return 0;

    if (port == 0x3da)
    {
        return (_retrace++ & 1) ? 8 : 0;;
    }

    if (port == 0x3c9)
    {
      var t = vga.PortRead8(port);
      if (t !== null)
        return t;
    }
    console.log("port in " + port.toString(16) + " not supported")
    throw "error";
}



function bios16set(seg, ofs, v)
{
}

function bios16get(seg, ofs)
{
  return 0;
}
function _rcl16(r, c)
{
    assert(c == 1);
    var newCarry = !!(r16[r] & 0x8000);
    r16[r] <<= 1;
    r16[r] |= flags.carry;
    flags.carry = newCarry;
}

function _rcr16(r, c)
{
    assert(c == 1);
    var newCarry = !!(r8[r] & 1);
    r8[r] >>= 1;
    r8[r] |= flags.carry ? 0x8000 : 0x0000;
    flags.carry = newCarry;
}

function _rcr8(r, c)
{
    assert(c == 1);
    var newCarry = !!(r8[r] & 0x1);
    r8[r] >>= 1;
    r8[r] |= flags.carry ? 0x80 : 0;
    flags.carry = newCarry;
}

function _rcl8(r, c)
{
    assert(c == 1);
    var newCarry = !!(r8[r] & 0x80);
    r8[r] <<= 1;
    r8[r] |= flags.carry;
    flags.carry = newCarry;
}

function _rclm8(r, c)
{
    assert(c == 1);
    var newCarry = !!(memory[r] & 0x80);
    memory[r] <<= 1;
    memory[r] |= flags.carry;
    flags.carry = newCarry;
}



function _xlatcs()
{
    r8[al] = memory[cs*16 + r16[bx] + r8[al]];
}

function _xlatds()
{
    r8[al] = memory[ds*16 + r16[bx] + r8[al]];
}

function _xlates()
{
    r8[al] = memory[es*16 + r16[bx] + r8[al]];
}

function _cmc()
{
    flags.carry = !flags.carry;
}


