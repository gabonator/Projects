void _sync();

class CVideoAdapter
{
public:
    virtual bool PortWrite16(int port, int data) = 0;
    virtual bool PortWrite8(int port, int data) = 0;
    virtual uint8_t PortRead8(int port) { assert(0); return 0; }
    virtual bool Interrupt(CicoContext::cicocontext_t* ctx) = 0;
    virtual void Write(uint32_t dwAddr, uint8_t bWrite) = 0;
    virtual uint8_t Read(uint32_t dwAddr) = 0;
    virtual uint32_t GetPixel(int x, int y) = 0;
    virtual void SetPixel(int x, int y, int c) = 0;
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
    virtual void SetPixel(int x, int y, int c) override
    {
        assert(0);
    }

    virtual bool PortWrite8(int port, int data) override
    {
        return false;
    }

    virtual bool PortWrite16(int port, int data) override
    {
        return false;
    }

    virtual bool Interrupt(CicoContext::cicocontext_t* ctx) override
    {
        //if ( CTextMode::Interrupt( ah, al, bh, bl ) )
//            return true;

        if ( ctx->a.r8.h == 0x0b )
        {
            if ( ctx->b.r8.h == 0x00 )
            {
                _cgaBackground = ctx->b.r8.l;
                return true;
            }
            if ( ctx->b.r8.h == 0x01 )
            {
                if (ctx->b.r8.l == 0x00)
                {
                    _cgaPalette[0] = 0x000000;
                    _cgaPalette[1] = 0x55aa55;
                    _cgaPalette[2] = 0xaa5555;
                    _cgaPalette[3] = 0xaaaa55;
                    return true;
                }
                if (ctx->b.r8.l == 0x01)
                {
                    _cgaPalette[0] = 0x000000;
                    _cgaPalette[1] = 0x55ffff;
                    _cgaPalette[2] = 0xff55ff;
                    _cgaPalette[3] = 0xffffff;
                    return true;
                }
            }
        }
        return false;
    }

    virtual void Write(uint32_t dwAddr, uint8_t bWrite) override
    {
        assert(dwAddr >= 0xb800*16);
        dwAddr -= 0xb800 * 16;
        assert(dwAddr < MemSize);
        memory[dwAddr] = bWrite;
        
        static int t=0;
        if (t++ > 800){
//            t = 0; _sync();
            
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

class CEga : public CVideoAdapter
{
    enum {
        MemSize = 0x10000*2
    };

public:
    uint32_t egamemory[MemSize];
    int nWriteMode;
    int nReadMode;
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

    uint32_t palette[128] = {
        0x000000, 0x0000b0, 0x00b000, 0x00b0b0, 0xb00000, 0xb000b0, 0xb0b000, 0xb0b0b0,
        0x808080, 0x0000ff, 0x00ff00, 0x00ffff, 0xff0000, 0xff00ff, 0xffff00, 0xffffff};

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
    
        memset(egamemory, 0, sizeof(egamemory));
    }
    
    bool Interrupt(CicoContext::cicocontext_t* ctx) override
    {
        if (ctx->a.r16 == 0x1002)
        {
            // es:DX!!!! 17 uint8_ts (documentation says es:bx)
            for (int i=0; i<16; i++)
            {
                int rgb = ctx->memory8(ctx->_es, ctx->d.r16+i);
                int r = ((rgb & 4) ? 3 : 0) + ((rgb & 32) ? 1 : 0);
                int g = ((rgb & 2) ? 3 : 0) + ((rgb & 16) ? 1 : 0);
                int b = ((rgb & 1) ? 3 : 0) + ((rgb & 8) ? 1 : 0);
                r = r * 255 / 3;
                g = g * 255 / 3;
                b = b * 255 / 3;
//                std::cout << "pal[" << i << "] = " << r << ", " << g << ", " << b << std:: endl;
                palette[i] = b | (g << 8) | (r << 16);
            }
            // set palette BX first, CX count, ES:DX rgb ptr
            //std::cout << "set palette " << hex << (int)_bx << " .. " << (int)(_bx+_cx)
            // << " data " << (int)_es << ":" << (int)_dx << endl;
            return true;
        }
        if (ctx->a.r16 == 0x1012)
        {
            for (int i=0; i<ctx->c.r16; i++)
            {
                int r = ctx->memory8(ctx->_es, ctx->d.r16+i*3)*4;
                int g = ctx->memory8(ctx->_es, ctx->d.r16+i*3+1)*4;
                int b = ctx->memory8(ctx->_es, ctx->d.r16+i*3+2)*4;
                
                int palIndex = ctx->b.r16 + i;
                palette[palIndex] = b | (g << 8) | (r << 16);
            }
            // set palette BX first, CX count, ES:DX rgb ptr
            //std::cout << "set palette " << hex << (int)_bx << " .. " << (int)(_bx+_cx)
            //<< " data " << (int)_es << ":" << (int)_dx << endl;

            return true;
        }
        if (ctx->a.r16 == 0x1010)
        {
            //http://www.techhelpmanual.com/144-int_10h_1010h__set_one_dac_color_register.html
            assert(ctx->b.r16 < 16);
            int r = ctx->c.r8.h * 4;
            int g = ctx->c.r8.l * 4;
            int b = ctx->d.r8.h * 4;
            palette[ctx->b.r16] = b | (g << 8) | (r << 16);
            return true;
        }

        if (ctx->a.r16 == 0x0b)
        {
            printf( "set pallete not impl\n");
            
            return true;
        }
        if (ctx->a.r16 == 0x1203)
        {
            //https://stanislavs.org/helppc/int_10-12.html
            return true;
        }
        if (ctx->a.r16 == 0x1130 && ctx->b.r8.h == 0)
        {
            ctx->c.r16= 0x10;
            //ctx->a.r16= 0x5003;
            ctx->d.r8.l = 0x18;
            ctx->_es = 0xc000;
            ctx->_bp = 0x500;
            return true;
        }
        if (ctx->a.r8.h == 0x08)
        {
            ctx->a.r16= 0x0720;
            return true;
        }
        if (ctx->a.r8.h == 0x03)
        {
            
        }
        if (ctx->a.r8.h == 0x02)
        {
            // set cursor
            return true;
        }

        printf("not implemented!\n");
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
//                _sync();
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
       // _ASSERT(0);
        printf( "Unknown EGA reg\n");
        return true;

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
        palette[index] = b | (g << 8) | (r << 16);

    }
    
    int crtReg = 0;

    virtual bool PortWrite8(int port, int data) override
    {
        static int lastPort = 0, lastData = 0;
        if ( port == 0x3c0 )
        {
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
            lastPort = 0x3ce;
            lastData = data;
            return true;
        }
        if (port == 0x3cf)
        {
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
            last3c4reg = data;
//            crtReg = data;
            return true;
        }
        if (port == 0x3c5)
        {
            PortWrite16(0x3c4, (data << 8)|last3c4reg);
            return true;
        }
        // vga pal
        static int colorindex = 0;
        if (port == 0x3c8)
        {
            //_sync();
            //std::cout << "Set write color " << (int)data << "\n";
            colorindex = data*3/2;
            return true;
        }
        if (port == 0x3c9)
        {
            int base = colorindex/3;
            int ch = colorindex%3;
            ((uint8_t*)palette)[base*4+2-ch] = data*4;
            colorindex++;
            return true;
        }

        return false;
    }

    virtual uint8_t PortRead8(int port)
    {
        //        3d4h index 0Ch (W):  CRTC: Start Address High Register
        //        bit 0-7  Upper 8 bits of the start address of the display buffer

        if (crtReg == 0x0c)
        {
            return cfgAddr>>8;
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

    uint32_t GetPixelA(int x, int y, int base)
    {
        uint8_t* _video = (uint8_t*)egamemory;
        uint32_t off = (int)y * 40L + ((int)x / 8L);
        
        //uint32_t mem_addr = off;
        int mask = 0x80 >> (x % 8);

        //int page = ((getTick() >> 8) & 1) ? 0x6800 : cfgAddr; //cfgAddr; 0xa700-0
        int page = base;
    
        int shift = page*4;
        uint8_t b = 0;
        if ( _video[shift + off*4 + 0] & mask ) b |= 1;
        if ( _video[shift + off*4 + 1] & mask ) b |= 2;
        if ( _video[shift + off*4 + 2] & mask ) b |= 4;
        if ( _video[shift + off*4 + 3] & mask ) b |= 8;
        return palette[b];
    }

    virtual void SetPixel(int x, int y, int c) override
    {
        uint8_t* _video = (uint8_t*)egamemory;
        uint32_t off = (int)y * 80L + ((int)x / 8L);
        
        //uint32_t mem_addr = off;
        int mask = 0x80 >> (x % 8);
        int page = cfgAddr;
        int shift = page*4;

        _video[shift + off*4 + 0] &= ~mask;
        if (c&1)
            _video[shift + off*4 + 0] |= mask;

        _video[shift + off*4 + 1] &= ~mask;
        if (c&2)
            _video[shift + off*4 + 1] |= mask;

        _video[shift + off*4 + 2] &= ~mask;
        if (c&4)
            _video[shift + off*4 + 2] |= mask;

        _video[shift + off*4 + 3] &= ~mask;
        if (c&8)
            _video[shift + off*4 + 3] |= mask;
    }

    void SetAddrHi(uint8_t b)
    {
        cfgAddr &= 0x00ff;
        cfgAddr |= ((uint16_t)b)<<8;
        //std::cout << "video addr="<<std::hex << cfgAddr<<"\n";
    }

    void SetAddrLo(uint8_t b)
    {
        cfgAddr &= 0xff00;
        cfgAddr |= b;
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

        //cfgBitMask = b;
        //full_bit_mask = arrExpandTable[b];
    }
        
    virtual void Write(uint32_t dwAddr, uint8_t bWrite) override
    {
        dwAddr -= 0xa000 * 16;
        if (bWrite){
            int f = 9;
        }
        if (nWriteMode != 1)
            LoadLatch(dwAddr);

        uint32_t data = ModeOperation(bWrite);

        TLatch pixels;
        pixels.u32Data = uLatch.u32Data;
        //pixels.u32Data = ReadLatch(dwAddr); //((uint32_t*)&egamemory[dwAddr])[dwAddr];

        pixels.u32Data &= full_not_map_mask;
        pixels.u32Data |= (data & full_map_mask);

        uLatch.u32Data = pixels.u32Data;
        StoreLatch(dwAddr);
        static int q = 0;
        if (q++ > 50000)
        {
            _sync();
            q= 0;
        }
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
        //TLatch l;
        assert( dwAddr < MemSize );
        uLatch.u32Data = egamemory[dwAddr];
        /*
        l.u8Data[0] = egamemory[dwAddr];
        l.u8Data[1] = egamemory[dwAddr+ 0x2000];
        l.u8Data[2] = egamemory[dwAddr+ 0x4000];
        l.u8Data[3] = egamemory[dwAddr+ 0x6000];
        */
        //7return uLatch.u32Data;
    }
    
    void StoreLatch(uint32_t dwAddr)
    {
        //TLatch l;
        assert( dwAddr < MemSize );
        //uLatch.u32Data |= 0x10101010;
        egamemory[dwAddr] = uLatch.u32Data;
/*
        TLatch l;
        l.u32Data = dwData;
        egamemory[dwAddr] = l.u8Data[0];
        egamemory[dwAddr+ 0x2000] = l.u8Data[1];
        egamemory[dwAddr+ 0x4000] = l.u8Data[2];
        egamemory[dwAddr+ 0x6000] = l.u8Data[3];
*/
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
};


class CVga : public CVideoAdapter
{
public:
    uint8_t buffer[320*240*6];
    uint8_t palette[0x300];
    //uint8_t xpalette[0x300];
    int readcolorindex{0};

    CVga()
    {
      //  for (int i=0; i<0x300; i++)
        //    xpalette[i] = rand();
    }
    virtual bool PortWrite16(int port, int data)
    {
        return false;
    }
    virtual bool PortRead8(uint16_t port, uint8_t& data) //override
    {
        if (port == 0x3c9)
        {
            //std::cout << "Read color  " << (int)readcolorindex/3 << "."
            //<< (readcolorindex%3) << " = " << (int)palette[readcolorindex] << "\n";
            data = palette[readcolorindex++];
            return true;
        }
        return false;
    }

    virtual bool PortWrite8(int port, int data)
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
        return false;
    }
    virtual bool Interrupt()
    {
        return false;
    }
    virtual void Write(uint32_t dwAddr, uint8_t bWrite)
    {
        int addr = dwAddr - 0xa000*16;
        assert(addr >= 0 && addr < sizeof(buffer));
        buffer[addr] = bWrite;
        
        static int q = 0;
        if (q++ > 5000)
        {
            _sync();
            q= 0;
        }
    }
    virtual uint8_t Read(uint32_t dwAddr)
    {
        int addr = dwAddr - 0xa000*16;
        assert(addr >= 0 && addr < sizeof(buffer));
        return buffer[addr];
    }
    virtual uint32_t GetPixel(int x, int y)
    {
        uint8_t c = buffer[y*320+x];
        return (palette[3*c+2]*4) | ((palette[3*c+1]*4)<<8) | ((palette[3*c]*4)<<16);
    }
    virtual void SetPixel(int x, int y, int c)
    {
        assert(0);
    }
    virtual bool Interrupt(CicoContext::cicocontext_t* ctx)
    {
        return false;
    }
};
