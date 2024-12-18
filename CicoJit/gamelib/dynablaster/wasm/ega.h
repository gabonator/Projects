class CVideoAdapter
{
public:
    virtual bool PortWrite16(int port, int data) = 0;
    virtual bool PortWrite8(int port, int data) = 0;
    virtual bool PortRead8(int port, uint8_t& data) { assert(0); return false; }
    virtual bool Interrupt(CicoContext::cicocontext_t* ctx) = 0;
    virtual void Write(uint32_t dwAddr, uint8_t bWrite) = 0;
    virtual uint8_t Read(uint32_t dwAddr) = 0;
};

class CPagedVga : public CVideoAdapter
{
    uint16_t startAddr = 0;
    uint16_t rowOffset = 0;
    uint8_t palette[256*3];
    uint8_t buffer[320*240*6];
private:
    int rdcolor, wrcolor, rdmask, wrmask, reg3c4, reg3ce, reg3d4;
    bool modified = false;

public:
    CPagedVga() : CVideoAdapter()
    {
    }
    virtual bool PortWrite16(int port, int data) 
    { 
      assert(0);
      return false;  
    }
    virtual bool PortWrite8(int port, int value) 
    { 
      const int wrmasktable[] = {-1, 0, 1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -2};
      switch (port)
      {
        case 0x3c7:
          rdcolor = value*3;
          return true;
        case 0x3c8:
          wrcolor = value*3;
          return true;
        case 0x3c9:
          palette[wrcolor++] = value;
          return true;
        case 0x3c4:
          reg3c4 = value;
          return true;
        case 0x3c5:
          switch (reg3c4)
          {
            case 0x02:
              wrmask = wrmasktable[value & 15];
              return true;
          }
          break;
        case 0x3ce:
          reg3ce = value;
          return true;
        case 0x3cf:
          switch (reg3ce)
          {
            case 0x04:
              rdmask = value;
              return true;
          }
          break;
        case 0x3d4:
          reg3d4 = value;
          return true;
        case 0x3d5:
          switch (reg3d4)
          {
            case 0x0c:
              startAddr = (startAddr & 0x00ff) | (value << 8);
              return true;
            case 0x0d:
              // todo sync!
            case 0xdd:
              startAddr = (startAddr & 0xff00) | (value);
              return true;
            case 0x13:
              rowOffset = value;
              return true;
          }
          break;
      }
      return false;
    }
    virtual bool PortRead8(int port, uint8_t& data) 
    { 
      assert(0); 
      return false; 
    }
    virtual bool Interrupt(CicoContext::cicocontext_t* ctx) 
    {
      assert(0);
      return false;
    }
    virtual void Write(uint32_t addr, uint8_t value)
    {
      addr -= 0xa0000;
      addr *= 4;
      if (wrmask == -2)
      {
        buffer[addr++] = value;
        buffer[addr++] = value;
        buffer[addr++] = value;
        buffer[addr++] = value;
      } else {
        addr += wrmask;
        buffer[addr] = value;
      }
    }
    virtual uint8_t Read(uint32_t addr)
    {     
      addr -= 0xa0000;
      addr *= 4;
      return buffer[addr+rdmask];
    }
    uint32_t GetPixel(int x, int y)
    {
      int o = startAddr*4;
      int c = buffer[o+(y/5)*40*rowOffset+x+(y%5)*rowOffset*8];
      return (palette[3*c]*4) | ((palette[3*c+1]*4)<<8) | ((palette[3*c+2]*4)<<16) | 0xff000000;
    }
    bool blit(uint32_t* pixels)
    {
      for (int y=0; y<240; y++)
        for (int x=0; x<256; x++)
          *pixels++ = GetPixel(x, y);
return true;
        if (!modified)
            return false;
/*
        modified = false;
        uint8_t *src = screen+0x8000;
        uint32_t* pix0 = pixels;
        uint32_t* pix1 = pixels+640;
        uint32_t* pix2 = pixels+640*2;
        uint32_t* pix3 = pixels+640*3;
        for (int y=0; y<100; y++)
        {
          for (int x=0; x<80; x++)
          {
            uint8_t symbol = *src++;
            uint8_t attr = *src++;
            uint32_t colors[2] = {palette[attr >> 4] | 0xff000000, palette[attr & 15] | 0xff000000};
            const uint8_t* pf = &egafont14x8[symbol*14];
            uint8_t f0 = *pf++;
            uint8_t f1 = *pf++;
            uint8_t f2 = *pf++;
            uint8_t f3 = *pf++;
            for (int xx=0; xx<8; xx++)
            {
              *pix0++ = colors[f0 >> 7];
              f0 <<= 1;
              *pix1++ = colors[f1 >> 7];
              f1 <<= 1;
              *pix2++ = colors[f2 >> 7];
              f2 <<= 1;
              *pix3++ = colors[f3 >> 7];
              f3 <<= 1;
            }
          }
          pix0 += 640*3;
          pix1 += 640*3;
          pix2 += 640*3;
          pix3 += 640*3;
        }
	
            for (int x=0; x<350; x++)
        for (int y=0; y<640; y++)
            {
                *pixels++ = GetPixel(y, x) | 0xff000000;
            }
*/
        return true;
    }
};

