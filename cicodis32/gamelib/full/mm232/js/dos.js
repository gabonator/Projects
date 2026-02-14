let allocatorBase = 0x440000; //0x400000;
let top32 = allocatorBase;
let top16 = 0x0080;

function out8(port, val) {
  if (port >= 0x300 && port < 0x400)
  {
    if (vga.portWrite8(port, val))
      return;
  }
  if (port ==0x20 || port == 0x201 || port == 0x40 || port == 0x43)return;
// console.log("out8", port.toString(16), val.toString(16))
}

function out16(port, val) {
  if (port >= 0x300 && port < 0x400)
  {
    if (vga.portWrite16(port, val))
      return;
  }
// console.log("out16", port.toString(16), val.toString(16))
}
let retrace = 0;
function in8(port) {
//  console.log("in8", port.toString(16))

    if (port == 0x40)
        return 0xe0;
    if (port == 0x201)
        return 0xff;
    if (port == 0x3da)
        return (retrace++ & 1) ? 9 : 0;

//  console.log("in8", port.toString(16))
  return 0;
}

let files = {id:40, handles:{}};

function interruptfs()
{
  if (r8[ah] == 0x3d)
  {
      var filename = "";
      var dot = false;
      for (var i=0; i<100; i++)
      {
          var c = String.fromCharCode(memoryAGet(ds, r32[edx]+i));
          if (c==' ')
              continue;
          if (c=='\0')
              break;
          if (c=='\\')
              c = "/";
          filename += c;
      }
      filename = filename.toUpperCase();
      console.log("Open: " + filename);
if (filename.includes("MAPS/"))
{
var f = 9;
}
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
  if (r8[ah] == 0x3f)
  {
      let file = files.handles[r16[bx]];
      var bytes = Math.min(r32[ecx], file.len-file.ofs); 
      //var wptr = ds*16+r16[dx];
      var wptr = 0;
      var rptr = file.ofs;
      r32[eax] = bytes;
      file.ofs += bytes;
      while (bytes--)
          memoryASet(es, r32[edx]+wptr++, file.data[rptr++]);
      flags.carry = 0;
      return;
  }
  if (r8[ah] == 0x3e)
  {   
      delete files.handles[r16[bx]]
      return;
  }
  if (r8[ah] == 0x44)
  {
//      r16[ax] = 2; // TODO
//      r16[dx] = 2;

      r16[ax] = 0x80d3; // TODO
      r16[dx] = 0x80d3;
      flags.carry = false;
      return;
  }
  if (r8[ah] == 0x40)
  {
      r16[ax] = r16[cx];
      flags.carry = false;
  }
  if (r8[ah] == 0x42)
  {
      let file = files.handles[r16[bx]];
      if (r8[al] == 2 && r16[cx] == 0 && r16[dx] == 0)
      {
          file.ofs = file.len;
          r16[ax] = file.ofs; // gabooooo!! file.len
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
throw "bad"
  }

}
function interrupt(i)
{
  switch (i)
  {
    case 0x10:
      switch (r8[ah])
      {
        case 0x00:
          console.log("Set video mode", r8[al].toString(16));
          return;
      }
      break;
    case 0x33:
      r16[ax] = 0;
      return;
    case 0x21:
      switch (r8[ah])
      {
        case 0x30:
          r16[ax] = 5;
          return;
        case 0xff:
          r32[eax] = 0x4734ffff;
          return;
        case 0x42: case 0x3e: case 0x3f: case 0x3d: case 0x40:
          interruptfs();
          return;
        case 0x25:
        case 0x35:
          return;
        case 0x44:
          switch (r8[al])
          {
            case 0x00:
                r16[ax] = 2;
                r16[dx] = 2;
                return;
          }
          break;
        case 0x2f:
          r32[ebx] = 0x77777; // get dta
          return;                
        case 0x1a:  // dta
          return;                
        case 0x4e:  // find first - skip
          flags.carry = true;
          return;                
      }
      break;
    case 0x31:
        switch (r16[ax])
        {
            case 0x0006:
                //https://www.delorie.com/djgpp/doc/dpmi/api/310006.html
                r16[cx] = 0;
                r16[dx] = 0;
                return;
            case 0x0501:
            {
                const sz = cx + bx*0x10000;
                r16[bx] = top32 >> 16; r16[cx] = top32 & 0xffff;
                r16[si] = 0x0001; r16[di] = 0x5893;
                console.log("Alloc linear ", sz.toString(16), " bytes to ", top32.toString(16));
                top32 += (sz + 0x1000 -1) & ~(0x1000-1);
                flags.carry = false;
                return;
            }
            case 0x0600:
            {
                //https://www.delorie.com/djgpp/doc/dpmi/api/310600.html
                flags.carry = false;
                return;
            }
            case 0x0100:
            {
                r16[ax] = top16;
                r16[dx] = 123;
                console.log("Alloc low ", r16[bx].toString(16), " par to ", top16.toString(16), ":0000");
                base += r16[bx];
                flags.carry = false;
                return;
            }
            case 0x0101:
                flags.carry = false;
                return;
        }
        break;
    case 0x1a:
      return;

  }
  console.log("unhandled interrupt ", i.toString(16), "ax=", r16[ax].toString(16));
  stop();
  throw "bad"
}