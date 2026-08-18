"use strict";
EGA.init();
var can = document.getElementById("canvas");
var ctx = can.getContext('2d');
can.width = 320;
can.height = 200;
var data = ctx.createImageData(can.width, can.height);
var sequence = start();

setInterval( ()=>
{
  sequence.next();
  if (EGA.access)
  {
    EGA.access = false;
    display();
  }
}, 40);

function display()
{
  var p = 0;
  var pixels = data.data;
  for (var y=0; y<200; y++)
    for (var x=0; x<320; x++)
    {
      var c = EGA.getPixel(x, y);
      pixels[p++] = (c>>16);
      pixels[p++] = ((c>>8)&0xff);
      pixels[p++] = (c & 0xff);
      pixels[p++] = 255;
    }
  ctx.putImageData(data, 0, 0);
}

function* sync(k)
{
  yield 0;
}

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
        {
          console.log("resource not found");
          flags.carry = 1;
          return;
        }
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
    if (i == 0x12)
    {
        r16[ax] = 0x800;
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
