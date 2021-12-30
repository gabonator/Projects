class VGA
{
  constructor()
  {
    this.buffer = new Uint8Array(320*240*6);
    this.palette = new Uint8Array(0x300);
    this.readcolorindex = 0;
    this.writecolorindex = 0;
    this.xpal = new Uint8Array(0x300);
  }

  PortWrite16(port, data)
  {
    return false;
  }

  PortRead8(port)
    {
        if (port == 0x3c9)
        {
            return this.palette[this.readcolorindex++];
        }
        return null;
    }

    PortWrite8(port, data)
    {        
        if (port == 0x3c7)
        {
            this.readcolorindex = data*3;
            return true;
        }
        if (port == 0x3c8)
        {
            this.writecolorindex = data*3;
            return true;
        }
        if (port == 0x3c9)
        {
            this.palette[this.writecolorindex++] = data;
            return true;
        }
        return false;
    }

    Interrupt()
    {
        return false;
    }

    write(dwAddr, bWrite)
    {
        var addr = dwAddr - 0xa000*16;
        assert(addr >= 0 && addr < this.buffer.length);
        this.buffer[addr] = bWrite;
    }

    read(dwAddr)
    {
        var addr = dwAddr - 0xa000*16;
        assert(addr >= 0 && addr < this.buffer.length);
        return this.buffer[addr];
    }

    getPixel(x, y)
    {
        var c = this.buffer[y*320+x];
        return (this.palette[3*c+2]*4) | ((this.palette[3*c+1]*4)<<8) | ((this.palette[3*c]*4)<<16);
    }
};
