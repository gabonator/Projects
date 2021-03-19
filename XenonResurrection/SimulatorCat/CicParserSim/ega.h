#include "font.h"

uint32_t getTick() {
    struct timespec ts;
    unsigned theTick = 0U;
    clock_gettime( CLOCK_REALTIME, &ts );
    theTick  = ts.tv_nsec / 1000000;
    theTick += ts.tv_sec * 1000;
    return theTick;
}

typedef uint32_t DWORD;

class CVideoAdapter
{
public:
	virtual bool PortWrite16(int port, int data) = 0;
    virtual bool PortWrite8(int port, int data) = 0;
	virtual bool Interrupt() = 0;
	virtual void Write(DWORD dwAddr, BYTE bWrite) = 0;
	virtual BYTE Read(DWORD dwAddr) = 0;
	virtual DWORD GetPixel(int x, int y) = 0;
    virtual void SetPixel(int x, int y, int c) = 0;
};
/*
class CTextMode : public CVideoAdapter
{
public:
	virtual bool Interrupt(int ah, int al, int bh, int bl) override
	{
		if (ah == 0x02)
		{
			// gotoxy dl, dh
			return true;
		}
		if (ah == 0x0e)
		{
			printf("%c", al);
			return true;
		}
		return false;

	}
};
*/

class CCga : public CVideoAdapter
{
	enum {
		MemSize = 0x10000*2
	};

public:
	BYTE memory[MemSize];

	DWORD _cgaPalette[4];
	DWORD _cgaBackground;

	CCga()
	{
		_cgaPalette[0] = 0x000000;
		_cgaPalette[1] = 0x808080;
		_cgaPalette[2] = 0xb0b0b0;
		_cgaPalette[3] = 0xffffff;
	}
    virtual void SetPixel(int x, int y, int c) override
    {
        _ASSERT(0);
    }

    virtual bool PortWrite8(int port, int data) override
    {
        return false;
    }

	virtual bool PortWrite16(int port, int data) override
	{
		return false;
	}

	virtual bool Interrupt() override
	{
		//if ( CTextMode::Interrupt( ah, al, bh, bl ) )
//			return true;

		if ( _ah == 0x0b )
		{
            if ( _bh == 0x00 )
			{
				_cgaBackground = _bl;
				return true;
			}
			if ( _bh == 0x01 )
			{
				if (_bl == 0x00)
				{
					_cgaPalette[0] = 0x000000;
					_cgaPalette[1] = 0x55aa55;
					_cgaPalette[2] = 0xaa5555;
					_cgaPalette[3] = 0xaaaa55;
					return true;
				}
				if (_bl == 0x01)
				{
					_cgaPalette[0] = 0x000000;
					_cgaPalette[1] = 0x00ffff;
					_cgaPalette[2] = 0xff00ff;
					_cgaPalette[3] = 0xffffff;
					return true;
				}
			}
		}
		return false;
	}

	virtual void Write(DWORD dwAddr, BYTE bWrite) override
	{
		_ASSERT(dwAddr >= 0xb800*16);
		dwAddr -= 0xb800 * 16;
		_ASSERT(dwAddr < MemSize);
		memory[dwAddr] = bWrite;
        
        static int t=0;
        if (t++ > 2000){
            t = 0; _sync();
            
        }
	}

	virtual BYTE Read(DWORD dwAddr) override
	{
		_ASSERT(dwAddr >= 0xb800*16);
		dwAddr -= 0xb800 * 16;
		_ASSERT(dwAddr < MemSize);
		return memory[dwAddr];
	}


	DWORD GetPixel(int x, int y) override
	{
		if ((y&1) == 0)
		{
			y /= 2;
			BYTE pix4 = memory[y*80+x/4];
			pix4 <<= (x&3)*2;
			return _cgaPalette[pix4 >> 6];
		} else
		{
			y /= 2;
			BYTE pix4 = memory[0x2000+y*80+x/4];
			pix4 <<= (x&3)*2;
			return _cgaPalette[pix4 >> 6];
		}
		return 0;
	}
};
