const videobuf = new ArrayBuffer(320*240*4);
const videoram = new Uint8Array(videobuf, 0, 320*240*4);
const vga = {
  palette: Array(256).fill(0),
  pitch: 320,
  planeMask: 0,
  panning: 0,
  pageStart: 0,
  getPixel: (x, y) => { // +0xab03*4
    x += vga.panning;
    return vga.palette[videoram[y*vga.pitch+x+vga.pageStart*4]];
  },
  memoryVideoGet: (s, o) => {
    o = (o - 0xa0000)*4;
//    return videoram[o];

    if (vga.planeMask & 1)
        return videoram[o];
    if (vga.planeMask & 2)
        return videoram[o+1];
    if (vga.planeMask & 4)
        return videoram[o+2];
    if (vga.planeMask & 8)
        return videoram[o+3];
    return 0xaa;

  },
  memoryVideoSet: (s, o, f) => {
    o = (o - 0xa0000)*4;
    if (vga.planeMask & 1)
      videoram[o] = f;
    if (vga.planeMask & 2)
      videoram[o+1] = f;
    if (vga.planeMask & 4)
      videoram[o+2] = f;
    if (vga.planeMask & 8)
      videoram[o+3] = f;
  },
  memoryVideoSet32: (s, o, f) => {
    vga.memoryVideoSet(s, o, f);
    vga.memoryVideoSet(s, o+1, f>>8);
    vga.memoryVideoSet(s, o+2, f>>16);
    vga.memoryVideoSet(s, o+3, f>>24);
  },
  memoryVideoSet16: (s, o, f) => {
    vga.memoryVideoSet(s, o, f);
    vga.memoryVideoSet(s, o+1, f>>8);
  },
  memoryVideoGet16: (s, o) =>
  {
    return vga.memoryVideoGet(s, o) + vga.memoryVideoGet(s, o+1)*256;
  },
  memoryVideoGet32: (s, o) =>
  {
    return vga.memoryVideoGet(s, o) | (vga.memoryVideoGet(s, o+1)<<8) |
      (vga.memoryVideoGet(s, o+2)<<16) | (vga.memoryVideoGet(s, o+3)<<24);
  },
  portRead8: (port, data) => {
    switch (port)
    {
      case 0x3c9:
        const ci = Math.trunc(vga._reg3c7/3);
        const ch = 2-(vga._reg3c7 % 3);
        vga._reg3c7++;
        return ((vga.palette[ci] >> (ci*8))&255)/4;
    }
    return 0;
  },
  portWrite8: (port, data) => {
    switch (port)
    {
      case 0x3c0:
        if (!vga._reg3c0)
          vga._reg3c0 = data;
        else {
          if ((vga._reg3c0 & 0x1f) == 0x13)
            vga.panning = (data & 7)>>1;
          vga._reg3c0 = null;
        }
      case 0x3d4:
        vga._reg3d4 = data;
        return;
      case 0x3d5:
        vga.portWrite16(0x3d4, (data << 8)|vga._reg3d4);
        return;      
      case 0x3c7:
        vga._reg3c7 = data*3;
        return;
      case 0x3c8:
        vga._reg3c8 = data*3;
        return;
      case 0x3c9:
        const ci = Math.trunc(vga._reg3c8/3);
        const ch = 2-(vga._reg3c8 % 3);
        let color = vga.palette[ci];
        color &= ~(0xff<<(ch*8));
        color |= (data*4)<<(ch*8)
        vga.palette[ci] = color;
        vga._reg3c8++;
        return;
    }
  },
  portWrite16: (port, data) => {
    switch (port)
    {
      case 0x3c4:
        switch (data & 0xff)
        {
          case 0x02:
            vga.planeMask = data >> 8;
            break;
        }
        return true;
      case 0x3d4:
        switch (data & 0xff)
        {
          case 0x13:
            vga.pitch = (data >> 8)*8;
            break;
          case 0x0c:
            vga.pageStart = (vga.pageStart & 0xff) | ((data >> 8) << 8);
            break;
          case 0x0d:
            vga.pageStart = (vga.pageStart & 0xff00) | (data >> 8);
            break;
        }
        return true;
    }
    return false;
  }
};

var can = document.getElementById("canvas");
var ctx = can.getContext('2d');
can.width = 320;
can.height = 240;
var data = ctx.createImageData(can.width, can.height);

function display()
{
  var p = 0;
  var pixels = data.data;
  for (var y=0; y<240-16; y++)
    for (var x=0; x<320; x++)
    {
      var c = vga.getPixel(x, y);
      pixels[p++] = c>>16;
      pixels[p++] = (c>>8)&0xff;
      pixels[p++] = c & 0xff;
      pixels[p++] = 255;
    }
  ctx.putImageData(data, 0, 0);
}

