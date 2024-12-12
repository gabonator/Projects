class VgaPaged
{
  constructor()
  {
    this.startAddr = 0;
    this.rowOffset = 0;
    this.palette = new Uint8Array(256*3);
    this.buffer = new Uint8Array(320*240*6);
  }
  interrupt(i)
  {
    throw "not supported"
  }
  portWrite8(port, value)
  {
    switch (port)
    {
      case 0x3c7:
        this.rdcolor = value*3;
        return true;
      case 0x3c8:
        this.wrcolor = value*3;
        return true;
      case 0x3c9:
        this.palette[this.wrcolor++] = value;
        return true;
      case 0x3c4:
        this.reg3c4 = value;
        return true;
      case 0x3c5:
        switch (this.reg3c4)
        {
          case 0x02:
            this.wrmask = [-1, 0, 1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -2][value & 15]
            return true;
        }
        break;
      case 0x3ce:
        this.reg3ce = value;
        return true;
      case 0x3cf:
        switch (this.reg3ce)
        {
          case 0x04:
            this.rdmask = value;
            return true;
        }
        break;
      case 0x3d4:
        this.reg3d4 = value;
        return true;
      case 0x3d5:
        switch (this.reg3d4)
        {
          case 0x0c:
            this.startAddr = (this.startAddr & 0x00ff) | (value << 8);
            return true;
          case 0x0d:
            console.log("should sync");//yield *sync();
          case 0xdd:
            this.startAddr = (this.startAddr & 0xff00) | (value);
            return true;
          case 0x13:
            this.rowOffset = value;
            return true;
        }
        break;
    }
    return false;
  }
  write(addr, value)
  {
    addr -= 0xa0000;
    addr *= 4;
    if (this.wrmask == -2)
    {
      this.buffer[addr++] = value;
      this.buffer[addr++] = value;
      this.buffer[addr++] = value;
      this.buffer[addr++] = value;
    } else {
      addr += this.wrmask;
      this.buffer[addr] = value;
    }
  }
  read(addr)
  {
    addr -= 0xa0000;
    addr *= 4;
    return this.buffer[addr+this.rdmask];
  }
  getPixel(x, y)
  {
    var o = this.startAddr*4;
    var c = this.buffer[o+((y/5)>>>0)*40*this.rowOffset+x+(y%5)*this.rowOffset*8];
    return (this.palette[3*c+2]*4) | ((this.palette[3*c+1]*4)<<8) | ((this.palette[3*c]*4)<<16);
  }
}
