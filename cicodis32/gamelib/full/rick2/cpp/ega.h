bool syncOnPageHigh = false;
bool syncOnPageLow = false;
const int alternative = 2; // ck1=1

class CVideoAdapter
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) = 0;
    virtual void sync() = 0;
    
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
        MemSize = 0x30000
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
    uint32_t egadefaultpal[16] = {
        0x000000, 0x0000b0, 0x00b000, 0x00b0b0, 0xb00000, 0xb000b0, 0xb0b000, 0xb0b0b0,
        0x808080, 0x0000ff, 0x00ff00, 0x00ffff, 0xff0000, 0xff00ff, 0xffff00, 0xffffff};
    int _videoMode = -1;

public:
    CEga()
    {
        for (int i=0; i<16; i++)
            palette[i] = egadefaultpal[i];
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
            //printf("Set video 0x%x\n", al);
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
      //          bh = 0x00;
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
            for (int i=0; i<16; i++)
            {
                int rgb = ReadMemory(es, dx+i); // 1040:9709+15
                // CGA emulation! http://www.techhelpmanual.com/137-int_10h_1000h__set_one_palette_register.html
                palette[i] = egadefaultpal[(rgb&7) + ((rgb&16)>>1)];
            }

            return true;
        }
        if (ax == 0x1012)
        {
            for (int i=0; i<cx; i++)
            {
                int r = ReadMemory(es, dx+i*3)*4;
                int g = ReadMemory(es, dx+i*3+1)*4;
                int b = ReadMemory(es, dx+i*3+2)*4;
                
                int palIndex = bx + i;
                palette[palIndex] = b | (g << 8) | (r << 16);
            }
            return true;
        }
        if (ax == 0x1130 && (bx>>8) == 0) // wtf
        {
            cx = 0x10;
            dl = 0x18;
            es = 0xc000;
            bp = 0x500;
            return true;
        }
        if (ax == 0x1130 && ((bx>>8) == 2 || (bx>>8) == 3)) // wtf 8x14 ptr!
        {
            printf("Warning: requests 8x14 font!\n"); // https://www.stanislavs.org/helppc/int_10-11.html
            cx = 8;
            dl = 0x18;
            es = 0xf000;
            bp = 0xfa6e;
//            cx = 0x10;
//            dl = 0x18;
//            es = 0xc000;
//            bp = 0x500;
            return true;
        }
        if (ax==0x1001)
            return true;
        if (ax==0x1200 && bl==0x10)
        {
            bh=0;
            bl=3;
            ch=0xff;
            cl=0;
            return true;
        }
        if (ah==0x1b)
        {
            uint8_t data[] = {
                0x00, 0x27, 0x00, 0xC0, 0x0D, 0x28, 0x00, 0x00,
                0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x07, 0x06, 0x00, 0xD4, 0x03,
                0x29, 0x30, 0x19, 0x08, 0x00, 0x08, 0x00, 0x10,
                0x00, 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
                0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            };

            for (int i=0; i<64; i++)
                memoryASet(es, di+i, data[i]);
            al = 0x1b;
            return true;
        }
        if (ah == 0x1a)
        {
            al = 0x1a;
            bx = 0x0404;
            return true;
        }
        /*
            case 0x0f:
                return true;
            case 0x1a:
                al = 0x1a;
                bx = 0x0404;
                return true;
         */
        if (ah == 0x10)
        {
            printf("EGA: skip int %04x\n", ax);
            return true;
        }

        assert(0);
        return false;
    }
    int last3c4reg = 0;
    int rowOffset = 40;
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
            printf("Skip video write out %x, %x\n", port, data);
            return true;
        }
        if ( port == 0x3d4 )
        {
            if ( (data & 0x00ff) == 0x0c )
            {
                SetAddrHi( data >>8 );
                if (syncOnPageHigh) sync(); // TODO: opt
                return true;
            }
            if ( (data & 0x00ff) == 0x0d )
            {
                SetAddrLo( data >> 8);
                if (syncOnPageLow) sync(); // TODO: opt
                return true;
            }
            if ((data & 0x00ff) == 0x13)
            {
                rowOffset = data >> 8;
            }

            printf("Skip video write out %x, %x\n", port, data);
            return true;
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
        if (port == 0x3d5)
        {
            if (data == 0x28)
            {
                mPitch = 80;
                return true;
            }

            printf("EGA skip write16 port %x=%x\n", port, data);
            return true;
        }
        assert(0);
        return false;
    }
    
    void SetPaletteIndex(int index, int rgb)
    {
        rgb = bx>>8;
        index = bx & 0xff; // wtf
        int r = ((rgb & 4) ? 2 : 0) + ((rgb & 32) ? 1 : 0);
        int g = ((rgb & 2) ? 2 : 0) + ((rgb & 16) ? 1 : 0);
        int b = ((rgb & 1) ? 2 : 0) + ((rgb & 8) ? 1 : 0);
        r = r * 255 / 3;
        g = g * 255 / 3;
        b = b * 255 / 3;
        palette[index] = b | (g << 8) | (r << 16);// | 0xff000000;
    }
    
    int crtReg = 0;
    int vgawritecolorindex = 0;
    int vgareadcolorindex{0};
    int colorindex{0}; // fox
    int mPitch{40};
    int mPanning{0};
    
    virtual bool PortWrite8(int port, int data) override
    {
        static int lastPort = 0, lastData = 0;
        if ( port == 0x3c0 )
        {
//assert(0);
            static int index = -1;
            
            
            /*
             1: 0000b0
             7/8: ffff00
             15:  ffffff
             
             */
            if (index == -1)
            {
                //if (data <= 0x10)
                    index = data;
            }
            else
            {
                if (index<16) {
                    SetPaletteIndex(index, data);
                } else {
                    if ((index & 0x1f) == 0x13)
                    {
                        static int sh = 0;
                        data &= 7;
                        mPanning = data; //((data&7) == 0) ? 0 : 7-(data & 7); //7-(data&7);
                        printf("panning: %d\n", mPanning);
//                         horizontal pel panning
                    } else
                        assert(0);
                }
                index = -1;
            }
//            std::cout << "port 3c0 ignore\n";
            return true;
        }
        if ( port == 0x3ce )
        {
//assert(0);
            lastPort = 0x3ce;
            lastData = data;
            return true;
        }
        if (port == 0x3cf)
        {
//assert(0);
            return PortWrite16 ( lastPort, (data<<8)|lastData);
        }
        if (port == 0x3d4)
        {
            crtReg = data;
            return true;
        }
        if (port == 0x3d5)
        {
            PortWrite16(0x3d4, (data << 8)|crtReg);
            return true;
        }
        
        if (port == 0x3c4)
        {
//assert(0);
            last3c4reg = data;
//            crtReg = data;
            return true;
        }
        if (port == 0x3c5)
        {
//assert(0);
            PortWrite16(0x3c4, (data << 8)|last3c4reg);
            return true;
        }

        // vga pal
        if (port == 0x3c8)
        {
//assert(0); // TODO: fox
            //_sync();
            //std::cout << "Set write color " << (int)data << "\n";
            //vgawritecolorindex = data*3; //*3/2;
            colorindex = data*3/2;
            return true;
        }

        if (port == 0x3c9)
        {
/*
            //modified = true;
//assert(0);
            int base = (vgawritecolorindex/3)&255;
            int ch = vgawritecolorindex%3;
            ((uint8_t*)palette)[base*4+ch] = data*4;

            vgawritecolorindex++;
            return true;
 */
            int base = colorindex/3;
            int xch = colorindex%3;
            if (data == 255) // wtf?
//            {
//                for (int i=base; i<16; i++)
//                    palette[base] = 0xffffff;
                return true;
//            }

            //data &= 63;
//            assert(data >= 0 && data < 64);  // TODO: GABO9
//            printf("set pal %d %d = %d\n", base, 2-ch, data);
            ((uint8_t*)palette)[base*4+2-xch] = data * 4;
            colorindex++;
            return true;
        }
        if (port == 0x3c7)
        {
//assert(0);
            vgareadcolorindex = data*3/2; //*3/2;
            return true;
        }

        //char temp[128];
        //sprintf(temp, "w8p=%04x", port);
        //apiPrint(temp);

        if (port == 0x3bf || port == 0x3b8 || port == 0x3b4 || port == 0x3b5)
        {
            printf("EGA: ignore port %x write %x\n", port, data);
            return true;
        }
            printf("EGA: FAIL ignore port %x write %x\n", port, data);
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
//assert(0);

        if (port == 0x3d4 && crtReg == 0x0c)
        {
            return cfgAddr>>8;
        }
//        if (port == 0x3c9)
//        {
//            int cindex = (vgareadcolorindex/3) & 255;
//            int cch = vgareadcolorindex%3;
//            vgareadcolorindex++;
//            return ((uint8_t*)palette)[cindex*4+2-cch]/4;
//        }
        if (port == 0x3c9)
        {
            int cindex = vgareadcolorindex/3;
            int cch = vgareadcolorindex%3;
            int data = ((uint8_t*)palette)[cindex*4+2-cch]/4;
//            printf("get pal %d %d %d = %d\n", vgareadcolorindex, cindex, 2-cch, data);
            vgareadcolorindex++;
            return data;
        }
        if (port == 0x3d5) // TODO: gabo9
        {
            return 0;
        }

        assert(0);
        return 0;
    }
    
    virtual uint32_t GetPixel(int x, int y) override
    {
        uint8_t* _video = (uint8_t*)egamemory;
        if (alternative == 2)
            mPitch = rowOffset*2; // 248;
        x += mPanning;

        uint32_t off = (int)y * mPitch + ((int)x / 8L);
        if (alternative == 1)
        {
            mPitch = 240;
            off = (int)y/5 * mPitch + (int)y%5 * (mPitch/5) + ((int)x / 8L);
        }
        int mask = 0x80 >> (x % 8);
        int page = cfgAddr;
        int shift = page*4;
        
        uint8_t b = 0;
        if ( _video[shift + off*4 + 0] & mask ) b |= 1;
        if ( _video[shift + off*4 + 1] & mask ) b |= 2;
        if ( _video[shift + off*4 + 2] & mask ) b |= 4;
        if ( _video[shift + off*4 + 3] & mask ) b |= 8;
        uint32_t c = palette[b];
        uint8_t cr = c & 255;
        uint8_t cg = (c >> 8) & 255;
        uint8_t cb = (c >> 16) & 255;
        
        return (cr<<16) | (cg<<8) | cb; //(c & 0xff00ff00) | ((c>>16)&255) || ((c&255)<<16);
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
//        if (bWrite)
//        {
//            int f=  9;
//        }
        modified = true;
        dwAddr -= 0xa000 * 16;
//        if (dwAddr>=0x1000 && dwAddr<=0x5200 )
//            bWrite = 0x55;

        if (nWriteMode != 1)
            LoadLatch(dwAddr);

        uint32_t data = ModeOperation(bWrite);

        TLatch pixels;
        pixels.u32Data = uLatch.u32Data;
        pixels.u32Data &= full_not_map_mask;
        pixels.u32Data |= (data & full_map_mask);

        uLatch.u32Data = pixels.u32Data;
        modified |= StoreLatch(dwAddr);
//        nWriteMode = old;

//        static int counter = 0;
//        if (bWrite)
//        {
//            if (counter++%1000==0)
//            {
//                sync();
//            }
//        }
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
//  if (!modified)
//    return false;
//  modified = false;
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
    
//    virtual void sync() = 0;
};



class CVga : public CVideoAdapter
{
public:
    uint8_t buffer[320*240*6];
    uint8_t palette[0x300];
    int readcolorindex{0};

    CVga()
    {
    }
    virtual bool PortWrite16(int port, int data) override
    {
        return false;
    }
    virtual uint8_t PortRead8(int port) override
    {
        if (port == 0x3c9)
        {
            return palette[readcolorindex++];
        }
        if (port == 0x3da)
        {
            static int retrace = 0;
            sync();
            return (retrace++ & 1) ? 9 : 0;
        }
        if (port == 0x3cf || port == 0x3d5)
        {
            printf("vga: skip read %x\n", port);
            return 0;
        }
        assert(0);
        return 0;
    }

    virtual bool PortWrite8(int port, int data) override
    {
        static int colorindex = 0;
        
        if (port == 0x3c7)
        {
            //std::cout << "Set read color " << (int)data << "\n";

            readcolorindex = data*3;
            return true;
        }
        if (port == 0x3c8)
        {
            //_sync();
            //std::cout << "Set write color " << (int)data << "\n";
            colorindex = data*3;
            return true;
        }
        if (port == 0x3c9)
        {
            palette[colorindex++] = data;
            return true;
        }
        if (port == 0x3c0)
        {
            return true;
        }
        if (port == 0x3ce || port == 0x3cf || port == 0x3d4 || port == 0x3d5 || port == 0x3c4 || port == 0x3c5)
        {
            printf("skip vga port write %x, %x\n", port, data);
            return true;
        }
        assert(0);
        return false;
    }
    virtual bool Interrupt() override
    {
        return true;
    }
    virtual void Write(uint32_t dwAddr, uint8_t bWrite) override
    {
        int addr = dwAddr - 0xa000*16;
        assert(addr >= 0 && addr < sizeof(buffer));
        buffer[addr] = bWrite;
    }
    virtual uint8_t Read(uint32_t dwAddr) override
    {
        int addr = dwAddr - 0xa000*16;
        assert(addr >= 0 && addr < sizeof(buffer));
        return buffer[addr];
    }
    virtual uint32_t GetPixel(int x, int y) override
    {
        uint8_t c = buffer[y*320+x];
        return (palette[3*c]*4) | ((palette[3*c+1]*4)<<8) | ((palette[3*c+2]*4)<<16);
    }
};

class CCga : public CVideoAdapter
{
    enum {
        MemSize = 0x10000*2
    };

public:
    uint8_t memory[MemSize];

    uint32_t _cgaPalette[4];
    uint32_t _cgaBackground;

    CCga()
    {
        _cgaPalette[0] = 0x000000;
        _cgaPalette[1] = 0x808080;
        _cgaPalette[2] = 0xb0b0b0;
        _cgaPalette[3] = 0xffffff;
        
        _cgaPalette[0] = 0x000000;
        _cgaPalette[1] = 0x55ffff;
        _cgaPalette[2] = 0xbb0000;
        _cgaPalette[3] = 0xffffff;

    }
//    void SetPixel(int x, int y, int c)
//    {
//        bool _xor = c & 0x80;
//        c &= 0x7f;
//        
//        if ((y&1) == 0)
//        {
//            y /= 2;
//            uint8_t& pix4 = memory[y*80+x/4];
//            int bit = 6-((x&3)*2);
//            int mask = 3 << bit;
//            if (_xor)
//                pix4 = pix4 ^ (c << bit);
//            else
//                pix4 = (pix4 & ~mask) | (c << bit);
//        } else
//        {
//            y /= 2;
//            uint8_t& pix4 = memory[0x2000+y*80+x/4];
//            int bit = 6-((x&3)*2);
//            int mask = 3 << bit;
//            if (_xor)
//                pix4 = pix4 ^ (c << bit);
//            else
//                pix4 = (pix4 & ~mask) | (c << bit);
//        }
//        static int q=0;
//        if (q++ > 100)
//        {
//            q = 0;
//            sync();
//        }
//    }

    virtual bool PortWrite8(int port, int data) override
    {
        assert(0);
        return false;
    }

    virtual bool PortWrite16(int port, int data) override
    {
        assert(0);
        return false;
    }
    virtual uint8_t PortRead8(int port) override
    {
        if (port == 0x3da)
        {
            static int retrace = 0;
            retrace++;
            return (retrace & 1) ? 9 : 0;
        }

        assert(0);
        return 0;
    }

    virtual bool Interrupt() override
    {
        if (ax == 0x0004)
            return true;
        //if ( CTextMode::Interrupt( ah, al, bh, bl ) )
//            return true;
        if (ah == 0x02)
            return true;

        if ( ah == 0x0b )
        {
//            if ( ah == 0x00 )
//            {
//                _cgaBackground = bl;
//                return true;
//            }
            int xbh = bx >> 8;
            int xbl = bx & 255;
            if ( xbh == 0x01 ) // WTF?
            {
                if (xbl == 0x00)
                {
                    _cgaPalette[0] = 0x000000;
                    _cgaPalette[1] = 0x55aa55;
                    _cgaPalette[2] = 0x5555aa;
                    _cgaPalette[3] = 0x55aaaa;
                    return true;
                }
                if (xbl == 0x01)
                {
                    _cgaPalette[0] = 0x000000;
                    _cgaPalette[1] = 0xffff55;
                    _cgaPalette[2] = 0xff55ff;
                    _cgaPalette[3] = 0xffffff;
                    return true;
                }
            }
        }
        if (ah == 0x0c)
        {
            assert(0);
//            SetPixel(ctx->c.r16, ctx->c.r16, ctx->a.r8.l);
            return true;
        }

        printf("Ignore int ax=%04x\n", ax);
        return true;
        return false;
    }

    virtual void Write(uint32_t dwAddr, uint8_t bWrite) override
    {
        assert(dwAddr >= 0xb800*16);
        dwAddr -= 0xb800 * 16;
        assert(dwAddr < MemSize);
        assert(dwAddr < 17000);
//        dwAddr %= 16000;
        memory[dwAddr] = bWrite;
        
        static int t=0;
        if (t++ > 800){
            t = 0;
            //sync();
        }
    }

    virtual uint8_t Read(uint32_t dwAddr) override
    {
        assert(dwAddr >= 0xb800*16);
        dwAddr -= 0xb800 * 16;
        assert(dwAddr < MemSize);
        return memory[dwAddr];
    }


    uint32_t GetPixel(int x, int y) override
    {
        if ((y&1) == 0)
        {
            y /= 2;
            uint8_t pix4 = memory[y*80+x/4];
            pix4 <<= (x&3)*2;
            return _cgaPalette[pix4 >> 6];
        } else
        {
            y /= 2;
            uint8_t pix4 = memory[0x2000+y*80+x/4];
            pix4 <<= (x&3)*2;
            return _cgaPalette[pix4 >> 6];
        }
        return 0;
    }
};

class CText : public CVideoAdapter
{
    uint8_t buffer[80*25*2];
public:
    virtual bool PortWrite8(int port, int data) override
    {
        printf("Text write8 %x=%x\n", port, data);
        return false;
    }

    virtual bool PortWrite16(int port, int data) override
    {
        printf("Text write16 %x=%x\n", port, data);
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

        assert(0);
        return 0;
    }

    virtual bool Interrupt() override
    {
        switch (ah)
        {
            case 0x0f:
                if (al == 0x03)
                {
                    ah = 80;
                    al = 3;
                    bh = 0;
                }
                return true;
            case 0x11:
                if (al == 0x30 && bh == 0)
                {
                    es = 0xeeee;
                    bp = 0xeeee;
                    dl = 25-1;
                    cx = 14;
                    return true;
                }
                break;
            case 0x1a:
                al = 0x1a;
                bx = 0x0404;
                return true;
            default:
                break;
        }
        printf("UNIMPLEMENTED: Text intr ax=%x\n", ax);
        return true;
    }

    virtual void Write(uint32_t dwAddr, uint8_t bWrite) override
    {
//        if (dwAddr % 2 == 0)
//            printf("%c", bWrite);
        dwAddr -= 0xb8000;
        if (dwAddr < sizeof(buffer))
            buffer[dwAddr] = bWrite;
        //else if (bWrite)
            printf("Text write %x = %x\n", dwAddr, bWrite);
//        static int cnt=0;
//        if (cnt++%200 == 0)
//            sync();
    }

    virtual uint8_t Read(uint32_t dwAddr) override
    {
        printf("Text read %x\n", dwAddr);
        return 0;
    }

    uint32_t GetPixel(int x, int y) override
    {
        int row = y/8;
        int col = x/8;
        int subx = x%8;
        int suby = y%8;
        int chr = buffer[(row*80+col)*2];
        int attr = buffer[(row*80+col)*2+1];
        assert(0);
/*
        if (cga_font[chr*8+suby] & (128>>subx))
            return 0xffffffff;
        else
            return 0x00000000;
*/        
        return 0;
    }
};

