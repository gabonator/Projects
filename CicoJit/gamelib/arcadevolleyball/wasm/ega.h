
class CVideoAdapter
{
public:
    virtual bool PortWrite16(int port, int data) = 0;
    virtual bool PortWrite8(int port, int data) = 0;
    virtual uint8_t PortRead8(int port) = 0;
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
    bool modified{false};

    CCga()
    {
        _cgaPalette[0] = 0xff000000;
        _cgaPalette[1] = 0xff808080;
        _cgaPalette[2] = 0xffb0b0b0;
        _cgaPalette[3] = 0xffffffff;
        
        _cgaPalette[0] = 0xff000000;
        _cgaPalette[1] = 0xffffff55;
        _cgaPalette[2] = 0xff0000bb;
        _cgaPalette[3] = 0xffffffff;

                    _cgaPalette[0] = 0xff000000;
                    _cgaPalette[1] = 0xffffff55;
                    _cgaPalette[2] = 0xffff55ff;
                    _cgaPalette[3] = 0xffffffff;

    }
    virtual void SetPixel(int x, int y, int c) override
    {
        assert(0);
    }

    virtual uint8_t PortRead8(int port) override
    {
        return 0;
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
        modified = true;
        assert(dwAddr >= 0xb800*16);
        dwAddr -= 0xb800 * 16;
        assert(dwAddr < MemSize);
        memory[dwAddr] = bWrite;
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

bool blit(uint32_t* pixels)
{
  if (!modified)
    return false;
  modified = false;
    int i=0;
    uint8_t* pi = &memory[0];
    uint32_t* po = pixels;
    for (int y=0, i=0; y<200; y+=2, i+=80, po += 320)
        for (int x=0; x<320/4; x++)
        {
            uint8_t pix4 = *pi++;
            *po++ = _cgaPalette[pix4 >> 6];
            pix4 <<= 2;
            *po++ = _cgaPalette[pix4 >> 6];
            pix4 <<= 2;
            *po++ = _cgaPalette[pix4 >> 6];
            pix4 <<= 2;
            *po++ = _cgaPalette[pix4 >> 6];
        }

    pi = &memory[0x2000];
    po = &pixels[320];
    for (int y=0, i=0; y<200; y+=2, i+=80, po += 320)
        for (int x=0; x<320/4; x++)
        {
            uint8_t pix4 = *pi++;
            *po++ = _cgaPalette[pix4 >> 6];
            pix4 <<= 2;
            *po++ = _cgaPalette[pix4 >> 6];
            pix4 <<= 2;
            *po++ = _cgaPalette[pix4 >> 6];
            pix4 <<= 2;
            *po++ = _cgaPalette[pix4 >> 6];
        }
    return true;
}
};
