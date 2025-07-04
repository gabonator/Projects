class CVideoAdapter
{
public:
    virtual bool PortWrite16(int port, int data) = 0;
    virtual bool PortWrite8(int port, int data) = 0;
    virtual uint8_t PortRead8(int port) = 0;
    virtual bool Interrupt() = 0;
    virtual void Write(uint32_t dwAddr, uint8_t bWrite) = 0;
    virtual uint8_t Read(uint32_t dwAddr) = 0;
    virtual uint32_t GetPixel(int x, int y) = 0;
};

class CEga : public CVideoAdapter
{
    enum {
        MemSize = 0x20000
    };

public:
    uint32_t egamemory[MemSize];
    int nWriteMode;
    int nReadMode;
    bool modified{false};
    union TLatch
    {
        uint32_t u32Data;
        uint8_t u8Data[4];
    };
    TLatch uLatch;
    //
    uint16_t cfgAddr;
    uint8_t cfgReadMapSelect;
    uint8_t cfgBitMask;
    uint8_t cfgEnableSetReset;
    uint8_t cfgSetReset;
    uint8_t cfgDontCare;
    uint8_t cfgCompare;
    uint8_t cfgMapMask;
    uint8_t cfgDataRotate;
    uint8_t cfgRasterOp;

    uint32_t arrFillTable[16];
    uint32_t arrExpandTable[256];

    // temp
    uint32_t full_map_mask;
    uint32_t full_not_map_mask;
    uint32_t full_bit_mask;
    uint32_t full_set_reset;
    uint32_t full_enable_and_set_reset;
    uint32_t full_enable_set_reset;
    uint32_t full_not_enable_set_reset;

    uint32_t palette[256] = {
        0xff000000, 0xffb00000, 0xff00b000, 0xffb0b000, 0xff0000b0, 0xffb000b0, 0xff00b0b0, 0xffb0b0b0,
        0xff808080, 0xffff0000, 0xff00ff00, 0xffffff00, 0xff0000ff, 0xffff00ff, 0xff00ffff, 0xffffffff};
    int _videoMode = -1;

public:
    CEga()
    {
        nWriteMode = 0;
        nReadMode = 0;
        cfgAddr = 0x0000;

        cfgReadMapSelect = 0; // 3CF.4
        cfgBitMask = 0xff;
        cfgEnableSetReset = 0xff;
        cfgSetReset = 0xff;
        cfgDontCare = 15; // 3CF.7
        cfgCompare = 0;
        cfgMapMask = 15;
        cfgDataRotate = 0;
        cfgRasterOp = 0; // 3CF.3

        for ( int i=0; i<16; i++)
        {
            arrFillTable[i]=
                ((i & 1) ? 0x000000ff : 0) |
                ((i & 2) ? 0x0000ff00 : 0) |
                ((i & 4) ? 0x00ff0000 : 0) |
                ((i & 8) ? 0xff000000 : 0) ;
        }
        for ( int i=0; i<256; i++ )
        {
            arrExpandTable[i] = i | (i << 8)| (i <<16) | (i << 24);
        }
        full_not_enable_set_reset    = 0xffffffff;
        full_enable_set_reset        = 0xffffffff;
        full_set_reset                = 0xffffffff;
        full_map_mask                = 0xffffffff;
        full_not_map_mask            = ~full_map_mask;
        full_bit_mask                = 0xffffffff;
        modified = false;
        memset(egamemory, 0, sizeof(egamemory));
    }
    
    bool Interrupt() override
    {
        if (ax == 0x0b)
        {
            return true;
        }
        if (ax == 0x1203)
        {
            //https://stanislavs.org/helppc/int_10-12.html
            return true;
        }
        if (ax == 0x1130 && bh == 0)
        {
            cx = 0x10;
            dl = 0x18;
            es = 0xc000;
            bp = 0x500;
            return true;
        }
        if (ah == 0x08)
        {
            ax = 0x0720;
            return true;
        }
        if (ah == 0x00)
        {
            _videoMode = al;
            return true;
        }
        if (ah == 0x03)
        {
        }
        if (ah == 0x02 || ah == 0x01 || ah == 0x06 || ah == 0x09)
        {
            return true;
        }

        if (ah == 0x0f)
        {
            if (_videoMode==-1)
            {
                ax = 0x5003;
                bh = 0x00;
                return true;
            }
            if (_videoMode==0x12)
            {
                ax = 0x5012;
                bh = 0x00;
                return true;
            }
            if (_videoMode==0x13)
            {
                ax = 0x2813;
                bh = 0x00;
                return true;
            }
            if (_videoMode==0x10)
            {
                ax = 0x5010;
                bh = 0x00;
                return true;
            }
            if (_videoMode==0x4)
            {
                ax = 0x2804;
                bh = 0x00;
                return true;
            }
            if (_videoMode==0xd)
            {
                ax = 0x280d;
                bh = 0x00;
                return true;
            }
            assert(0);
        }
        if (ah == 0x1a)
        {
            //https://dos4gw.org/INT_10H_1aH_Set_or_Query_Display_Combination_Code
            al = 0x1a;
            bl = 0x08; // vga color
            return true;
        }
        if (ax == 0x1000)
        {
            SetPaletteIndex(bl, bh);
            return true;
        }
        if (ax == 0x1002)
        {
            return true;
        }

        assert(0);
        return false;
    }
    int last3c4reg = 0;
    virtual bool PortWrite16(int port, int data) override
    {
        if ( port == 0x3c4 )
        {
            last3c4reg = data & 0xff;
            if ( (data & 0x00ff) == 0x02 )
            {
                /*
                01 = plane 0, 02 = plane 1, 04 = plane 2, 08 = plane 3
                0f = default
                */
                //printf("Write mask = %02x\n", data>>8 );
                SetMapMask( data>>8); // 3c5.2
                return true;
            }
            if ( (data & 0x00ff) == 0x01 )
            {
                // clocking mode??
                return true;
            }
            if ( (data & 0x00ff) == 0x08 )
            {
                // undocumented??
                return true;
            }
            if (data == 0x080c)
            {
            
            }
        }
        if ( port == 0x3d4 )
        {
            if ( (data & 0x00ff) == 0x0c )
            {
                SetAddrHi( data >>8 );
                sync();
                return true;
            }
            if ( (data & 0x00ff) == 0x0d )
            {
                SetAddrLo( data >> 8);
                return true;
            }
        }
        if ( port == 0x3ce )
        {
            switch ( data & 0xff )
            {
            case 0x00: SetSR( data >> 8 ); return true;
            case 0x01: SetEnableSR( data >> 8 ); return true;
            case 0x02: SetCompare( data >> 8 ); return true;
            case 0x05: SetMode( data >> 8 ); return true;
            case 0x07: SetDontCare( data >> 8 ); return true;
            case 0x08: SetBitMask( data >> 8 ); return true;
            case 0x03: SetRotate( data >> 8 ); return true;
                //case 0x04: std::cout <<"port 3ceh <- 4 not supported\n"; return true;
                case 0x04: cfgReadMapSelect = data >> 8; assert(cfgReadMapSelect >= 0 && cfgReadMapSelect <= 3); return true;
            default:
                assert(0);
            }
        }
        assert(0);
        return false;
    }
    
    void SetPaletteIndex(int index, int rgb)
    {
        int r = ((rgb & 4) ? 2 : 0) + ((rgb & 32) ? 1 : 0);
        int g = ((rgb & 2) ? 2 : 0) + ((rgb & 16) ? 1 : 0);
        int b = ((rgb & 1) ? 2 : 0) + ((rgb & 8) ? 1 : 0);
        r = r * 255 / 3;
        g = g * 255 / 3;
        b = b * 255 / 3;
        palette[index] = r | (g << 8) | (b << 16) | 0xff000000;
    }
    
    int crtReg = 0;
    int vgawritecolorindex = 0;
    int vgareadcolorindex{0};

    virtual bool PortWrite8(int port, int data) override
    {
        static int lastPort = 0, lastData = 0;
        if ( port == 0x3c0 )
        {
assert(0);
            static int index = -1;
            
            
            /*
             1: 0000b0
             7/8: ffff00
             15:  ffffff
             
             */
            if (index == -1)
            {
                if (data <= 0x10)
                    index = data;
            }
            else
            {
                SetPaletteIndex(index, data);
                index = -1;
            }
//            std::cout << "port 3c0 ignore\n";
            return true;
        }
        if ( port == 0x3ce )
        {
assert(0);
            lastPort = 0x3ce;
            lastData = data;
            return true;
        }
        if (port == 0x3cf)
        {
assert(0);
            return PortWrite16 ( lastPort, (data<<8)|lastData);
        }
        if (port == 0x3d4)
        {
assert(0);
            crtReg = data;
            return true;
        }
        if (port == 0x3d5)
        {
assert(0);
            PortWrite16(0x3d4, (data << 8)|crtReg);
            return true;
        }
        
        if (port == 0x3c4)
        {
assert(0);
            last3c4reg = data;
//            crtReg = data;
            return true;
        }
        if (port == 0x3c5)
        {
assert(0);
            PortWrite16(0x3c4, (data << 8)|last3c4reg);
            return true;
        }

        // vga pal
        if (port == 0x3c8)
        {
assert(0);
            //_sync();
            //std::cout << "Set write color " << (int)data << "\n";
            vgawritecolorindex = data*3; //*3/2;
            return true;
        }

        if (port == 0x3c9)
        {
            //modified = true;
assert(0);
            int base = (vgawritecolorindex/3)&255;
            int ch = vgawritecolorindex%3;
            ((uint8_t*)palette)[base*4+ch] = data*4;

            vgawritecolorindex++;
            return true;
        }
        if (port == 0x3c7)
        {
assert(0);
            vgareadcolorindex = data*3; //*3/2;
            return true;
        }

        //char temp[128];
        //sprintf(temp, "w8p=%04x", port);
        //apiPrint(temp);

        assert(0);
        return false;
    }

    virtual uint8_t PortRead8(int port) override
    {
        if (port == 0x3da)
        {
          static uint8_t retrace = 0;
          retrace++;
          return (retrace & 1) ? 9 : 0;
        }


        //        3d4h index 0Ch (W):  CRTC: Start Address High Register
        //        bit 0-7  Upper 8 bits of the start address of the display buffer
assert(0);

        if (port == 0x3d4 && crtReg == 0x0c)
        {
            return cfgAddr>>8;
        }
        if (port == 0x3c9)
        {
            int cindex = (vgareadcolorindex/3) & 255;
            int cch = vgareadcolorindex%3;
            vgareadcolorindex++;
            return ((uint8_t*)palette)[cindex*4+2-cch]/4;
        }
        assert(0);
        return 0;
    }
    
    virtual uint32_t GetPixel(int x, int y) override
    {
        uint8_t* _video = (uint8_t*)egamemory;
        uint32_t off = (int)y * 40L + ((int)x / 8L);
        
        //uint32_t mem_addr = off;
        int mask = 0x80 >> (x % 8);

        //int page = ((getTick() >> 8) & 1) ? 0x6800 : cfgAddr; //cfgAddr; 0xa700-0
        int page = cfgAddr;
    
        int shift = page*4;
        uint8_t b = 0;
        if ( _video[shift + off*4 + 0] & mask ) b |= 1;
        if ( _video[shift + off*4 + 1] & mask ) b |= 2;
        if ( _video[shift + off*4 + 2] & mask ) b |= 4;
        if ( _video[shift + off*4 + 3] & mask ) b |= 8;
        return palette[b];
    }


    void SetAddrHi(uint8_t b)
    {
        cfgAddr &= 0x00ff;
        cfgAddr |= ((uint16_t)b)<<8;
            modified = true;
        //std::cout << "video addr="<<std::hex << cfgAddr<<"\n";
    }

    void SetAddrLo(uint8_t b)
    {
        cfgAddr &= 0xff00;
        cfgAddr |= b;
            modified = true;
    }

    void SetMapMask(uint8_t b) // 3c5.2
    {
        cfgMapMask = b;
        full_map_mask = arrFillTable[b & 15];
        full_not_map_mask = ~full_map_mask;
    }

    void SetSR(uint8_t b)
    {
        cfgSetReset = b & 0x0f;
        full_set_reset = arrFillTable[b & 0x0f];
        full_enable_and_set_reset = full_set_reset & full_enable_set_reset;
    }
    void SetEnableSR(uint8_t b)
    {
        cfgEnableSetReset = b & 0x0f;
        full_enable_set_reset = arrFillTable[b & 0x0f];
        full_not_enable_set_reset = ~full_enable_set_reset;
        full_enable_and_set_reset = full_set_reset & full_enable_set_reset;
    }
    void SetCompare(uint8_t b)
    {
        cfgCompare = b & 0xf;
    }
    void SetMode(uint8_t b)
    {
        nWriteMode = b & 3;
        nReadMode = (b >> 3) & 1;
    }
    void SetDontCare(uint8_t b)
    {
        cfgDontCare = b & 0xf;
    }
    void SetBitMask(uint8_t b)
    {
        cfgBitMask = b;
        full_bit_mask = arrExpandTable[b];
    }
    void SetRotate(uint8_t b)
    {
        cfgDataRotate = b & 7;
        cfgRasterOp = (b >> 3)&3;
    }
        
    virtual void Write(uint32_t dwAddr, uint8_t bWrite) override
    {
        if (_videoMode != 0x0d)
            return;
        modified = true;
        dwAddr -= 0xa000 * 16;

        if (nWriteMode != 1)
            LoadLatch(dwAddr);

        uint32_t data = ModeOperation(bWrite);

        TLatch pixels;
        pixels.u32Data = uLatch.u32Data;
        //pixels.u32Data = ReadLatch(dwAddr); //((uint32_t*)&egamemory[dwAddr])[dwAddr];

        pixels.u32Data &= full_not_map_mask;
        pixels.u32Data |= (data & full_map_mask);

        uLatch.u32Data = pixels.u32Data;
        modified |= StoreLatch(dwAddr);
    }

    virtual uint8_t Read(uint32_t dwAddr) override
    {
        dwAddr -= 0xa000 * 16;
        assert( dwAddr < sizeof(egamemory) );
        LoadLatch(dwAddr); //((uint32_t*)&egamemory[dwAddr])[dwAddr];
        if ( nReadMode == 0 )
            return uLatch.u8Data[cfgReadMapSelect];
        if ( nReadMode == 1 )
        {
            TLatch temp;
            temp.u32Data = (uLatch.u32Data & arrFillTable[cfgDontCare]) ^
                arrFillTable[cfgCompare & cfgDontCare];
            return ~(temp.u8Data[0] | temp.u8Data[1] | temp.u8Data[2] | temp.u8Data[3]);
        }
        assert(0);
        return 0;
    }
    
    void LoadLatch(uint32_t dwAddr)
    {
        assert( dwAddr < MemSize );
        uLatch.u32Data = egamemory[dwAddr];
    }
    
    bool StoreLatch(uint32_t dwAddr)
    {
        assert( dwAddr < MemSize );
        if (egamemory[dwAddr] == uLatch.u32Data)
            return false;
        egamemory[dwAddr] = uLatch.u32Data;
        return true;
    }

    uint32_t ModeOperation(uint8_t val)
    {
        uint32_t full;
        switch (nWriteMode) {
        case 0x00:
            // Write Mode 0: In this mode, the host data is first rotated as per the Rotate Count field, then the Enable Set/Reset mechanism selects data from this or the Set/Reset field. Then the selected Logical Operation is performed on the resulting data and the data in the latch register. Then the Bit Mask field is used to select which bits come from the resulting data and which come from the latch register. Finally, only the bit planes enabled by the egamemory Plane Write Enable field are written to egamemory.
            val = ((val >> cfgDataRotate) | (val << (8-cfgDataRotate)));
            full = arrExpandTable[val];
            full = (full & full_not_enable_set_reset) | full_enable_and_set_reset;
            full = RasterOp(full,full_bit_mask);
            break;
        case 0x01:
            // Write Mode 1: In this mode, data is transferred directly from the 32 bit latch register to display egamemory, affected only by the egamemory Plane Write Enable field. The host data is not used in this mode.
            full = uLatch.u32Data;
            break;
        case 0x02:
            //Write Mode 2: In this mode, the bits 3-0 of the host data are replicated across all 8 bits of their respective planes. Then the selected Logical Operation is performed on the resulting data and the data in the latch register. Then the Bit Mask field is used to select which bits come from the resulting data and which come from the latch register. Finally, only the bit planes enabled by the egamemory Plane Write Enable field are written to egamemory.
            full = RasterOp(arrFillTable[val&0xF], full_bit_mask);
            break;
        case 0x03:
            // Write Mode 3: In this mode, the data in the Set/Reset field is used as if the Enable Set/Reset field were set to 1111b. Then the host data is first rotated as per the Rotate Count field, then logical ANDed with the value of the Bit Mask field. The resulting value is used on the data obtained from the Set/Reset field in the same way that the Bit Mask field would ordinarily be used. to select which bits come from the expansion of the Set/Reset field and which come from the latch register. Finally, only the bit planes enabled by the egamemory Plane Write Enable field are written to egamemory.
            val=((val >> cfgDataRotate) | (val << (8-cfgDataRotate)));
            full=RasterOp(full_set_reset, arrExpandTable[val] & full_bit_mask);
            break;
        default:
            assert(0);
            break;
        }
        return full;
    }

    uint32_t RasterOp(uint32_t input, uint32_t mask)
    {
        switch (cfgRasterOp) {
        case 0x00: /* None */
            return (input & mask) | (uLatch.u32Data & ~mask);
        case 0x01: /* AND */
            return (input | ~mask) & uLatch.u32Data;
        case 0x02: /* OR */
            return (input & mask) | uLatch.u32Data;
        case 0x03: /* XOR */
            return (input & mask) ^ uLatch.u32Data;
        };
        return 0;
    }

bool blit(uint32_t* pixels)
{
  if (!modified)
    return false;
  modified = false;
    uint8_t* planes = (uint8_t*)egamemory+cfgAddr*4;
        
    for (int y=0; y<320; y++)
        for (int x=0; x<200/8; x++)
        {
            int plane0 = *planes++;
            int plane1 = *planes++;
            int plane2 = *planes++;
            int plane3 = *planes++;

            for (int i=0; i<8; i++)
            {
                int index = (plane0 & 128) + (plane1 & 128)*2 + (plane2 & 128)*4 + (plane3 & 128)*8;
                plane0 <<= 1;
                plane1 <<= 1;
                plane2 <<= 1;
                plane3 <<= 1;
                *pixels++ = palette[index >> 7];
            }
        }
  return true;
}
    
    virtual void sync() = 0;
};
