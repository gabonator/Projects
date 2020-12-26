#include <assert.h>
#include <stdint.h>
#include <vector>

#include "cpu.h"
#include "ega.h"

constexpr WORD _seg000 = 0x3A56;
constexpr WORD _dseg = 0x13A5;
const char* scene = "intro";

#include "code-goose.h"
#include "code-goose-2.h"
#include "code-goose-3.h"
#include "code-goose-4.h"
#include "code-goose-sound.h"

// 0x350c - 0x3a56
MemVideo memoryVideo;
CEga mVideo;
reg_t _reg;

uint8_t datasegment[0x10000*5]; // TODO:check size
uint8_t segment0[0x10000];
uint8_t pixelBuffer[320*200*3];

bool commonFileOpen(char* name);
void commonFileRead(uint8_t* ptr, int offset, int length);

class CSound
{
public:
    int mFrequency{0};
    bool PortWrite8(WORD port, WORD val)
    {
        static int _p42 = 0;
        static int _buffer42 = 0;
        
        
        if (port == 0x61)
        {
            if ((val & 3) == 3)
            {
                // speaker on
                return true;
            }
            if ((val & 3) == 0)
            {
                // speaker off
                mFrequency = 0;
                return true;
            }
            _ASSERT(0);
            return false;
        }
        if ( port == 0x43 )
        {
            if ( val == 0x36 ) // play tone, channel 0
            {
                _p42 = 0;
                _buffer42 = 0;
            }
          else if ( val == 0xB6 ) // play tone, channel 1/2?
          {
            _p42 = 0;
            _buffer42 = 0;
          } else if (val == 0x00)
          {
            //_buffer = (-getTick()*6) &0xffff;
          } else
              _ASSERT(0);
            // 0x36 = 0 0 1 1  0 1 1 0
            return true;
        }
        if ( port == 0x42 )
        {
          if ( _p42 == 0 )
          {
            _buffer42 = val;
            _p42++;
          } else if ( _p42 == 1 )
          {
            _buffer42 = (val<<8) | _buffer42;
            _tone(/*1193180 /*/ _buffer42);
              _p42 =0;
          }
            return true;
        }
        
        return false;
    }
    void _tone(int divider)
    {
        mFrequency = 1193180 / divider;
    }
};

CSound mSound;

int getPlayFrequency()
{
    return mSound.mFrequency;
}

void gooseSound();

void gooseInit()
{
    memset(datasegment, 0, sizeof(datasegment));
    memset(segment0, 0, sizeof(segment0));
    m_arrStack.resize(2*32, 0);
    _sp = 32;
    _ds = _es = _di = _bp = 0x6666;
}

void gooseLoop()
{
    static int _pc = 0;
    _pc = start(_pc);
    
    /*
    // TODO: optimize
    uint8_t* p = pixelBuffer;
    for (int y=0; y<200; y++)
        for (int x=0; x<320; x++)
        {
            uint32_t color = mVideo.GetPixel(x, y);
            *p++ = color >> 16;
            *p++ = color >> 8;
            *p++ = color >> 0;
        }
     */
    int shift = mVideo.cfgAddr;
    BYTE* planes = (BYTE*)(mVideo.memory + shift);
        
    uint8_t* p = pixelBuffer;
    for (int y=0; y<200; y++)
        for (int x=0; x<40; x++)
        {
            int plane0 = *planes++;
            int plane1 = *planes++;
            int plane2 = *planes++;
            int plane3 = *planes++;

            for (int i=0; i<8; i++)
            {
                int index = (plane0 & 128) + (plane1 & 128)*2 + (plane2 & 128)*4 + (plane3 & 128)*8;
                int color = mVideo.palette[index >> 7];
                *p++ = color >> 16;
                *p++ = color >> 8;
                *p++ = color >> 0;
                plane0 <<= 1;
                plane1 <<= 1;
                plane2 <<= 1;
                plane3 <<= 1;
            }
        }
}

void gooseSound()
{
    _ax = _dseg;
    _ds = _ax;
    memory(_dseg, 0x1CF54-0x13A50)++;
    sub_1387D();
}

BYTE memoryVideoGet(WORD seg, WORD ofs)
{
    return memoryVideo.Get8(seg, ofs);
}

void memoryVideoSet(WORD seg, WORD ofs, BYTE data)
{
    memoryVideo.Set8(seg, ofs, data);
}

BYTE MemVideo::Get8(WORD seg, WORD ofs)
{
    assert(seg == 0xa000 || seg == 0xa400|| seg == 0xa200 || seg == 0xa800);
    return mVideo.Read(seg*16+ofs);
}

void MemVideo::Set8(WORD seg, WORD ofs, BYTE data)
{
    assert(seg == 0xa000 || seg == 0xa400 || seg == 0xa200 || seg == 0xa800);
    mVideo.Write(seg*16+ofs, data);
}

BYTE MemAuto::Get8(WORD seg, WORD ofs)
{
    if (seg == 0xa000 || seg == 0xa800 || seg == 0xa400 || seg == 0xa200)
        return memoryVideoGet(seg, ofs);
    return memory(seg, ofs);
}

void MemAuto::Set8(WORD seg, WORD ofs, BYTE data)
{
    if (seg == 0xa000 || seg == 0xa800 || seg == 0xa400 || seg == 0xa200)
    {
        memoryVideoSet(seg, ofs, data);
        return;
    }
    memory(seg, ofs) = data;
}

void _interrupt(BYTE i)
{
    static int fileOffset = 0;
    
    if (i == 0x10) // gfx
    {
        static bool newline = false;
        static int lasty = 0;
        
        if (_ah == 0x10 && _al == 0x12)
        {
            mVideo.Interrupt();
            return;
        }
        if (_ah == 0x1a)
        {
            // get video info
            //http://www.techhelpmanual.com/177-int_10h_1ah__set_or_query_display_combination_code.html
            _al = 0x1a;
            _bl = 5;
            return;
        }
        if (_ah == 0x0f)
        {
            // get character count
            //https://vitaly_filatov.tripod.com/ng/asm/asm_023.16.html
            _al = 3;
            _ah = 80;
            _bh = 0;
            return;
        }
        if (_ah == 0x01)
        {
            // set cursor size
            return;
        }
        if (_ah == 0x06)
        {
             // scroll down
            return;
        }
        if (_ah == 0x02)
        {
             // goto y=dh, y=dl
            if (lasty != _dh)
            {
                fprintf(stdout, "\n");
                newline = true;
                lasty = _dh;
            }
            return;
        }
        if (_ah == 0x09)
        {
             // write character al = code, bl = color
            if (newline)
            {
                newline = false;
                fprintf(stdout, "[%02x]", _bl);
            }
            fprintf(stdout, "%c", _al);
            return;
        }
        if (_ah == 0x00)
        {
            return;
        }
        if (_ah == 0x10 && _al == 0)
        {
            return;
        }
        if (_ax == 0x1002)
        {
            mVideo.Interrupt();
            //cout << "set palette " << endl;
            return;
        }
        _ASSERT(0);
        return;
    }
    

    if (i == 0x21 && _ah == 0x3e)
    {
        // Close file
        _flags.carry = 0;
        return;
    }

    if (i == 0x21 && _ah == 0x3d)
    {
        fileOffset = 0;
        // open file DS:DX filename
        // AX = file handle
        char filename[100];
        for (int i=0; i<100; i++)
        {
            char c = memory(_ds, _dx+i);
            if (!c)
                break;
            filename[i] = c;
            filename[i+1] = 0;
        }
        // open file
        if (commonFileOpen(filename))
        {
            _flags.carry = 0;
            _ax = 1;
        } else {
            _flags.carry = 1;
        }
        return;
    }
    
    if (i == 0x21 && _ah == 0x3f)
    {
        assert(fileOffset >= 0);
        commonFileRead(&memory(_ds, _dx), fileOffset, _cx);
        _flags.carry = 0;
        return;
    }

    if (i == 0x12)
    {
        _ax = 0x800;
        return;
    }
    
    if (i == 0x21 && _ah == 0x09)
    {
        // print text _ds:_dx
        return;
    }

    if (i == 0x33) // mouse
    {
        _ax = 0;
        return;
    }
    
    if (i == 0x21 && _ah == 0x3c)
    {
        // create file
        _flags.carry = 1;
        return;
    }

    if (i == 0x21 && _ah == 0x35)
    {
        // GetIntVect
        return;
    }
    
    if (i == 0x21 && _ah == 0x25)
    {
        // SetIntVect
        return;
    }

    assert(0);
}

void _out(WORD port, BYTE val)
{
    if (mVideo.PortWrite8(port, val))
    {
        return;
    }
    if (port == 0x40 || port == 0x201)
    {
        return;
    }
    if (mSound.PortWrite8(port, val))
        return;
    _ASSERT(0);
}

void _out(WORD port, WORD val)
{
    if (mVideo.PortWrite16(port, val))
    {
        return;
    }
    _ASSERT(0);
}

void _sync() {}

BYTE& memory(WORD segment, WORD offset)
{
    if (segment == 0x1d0c ||
        segment == 0x1d0c+0x800*1 ||
        segment == 0x1d0c+0x800*2 ||
        segment == 0x1d0c+0x800*3 ||
        segment == 0x1d0c+0x800*4 ||
        segment == 0x1d0c+0x800*5 ||
        segment == 0x1d0c+0x800*6 )
        return *(datasegment + offset + (segment-_dseg)*16);
    if (segment == _dseg)
        return *(datasegment + offset);
    if (segment == _seg000)
        return *(segment0 + offset);
    
    static BYTE dummy = 0;
    assert(0);
    return dummy;
}

void _in(BYTE& val, WORD port)
{
    if (port == 0x61) // speaker
    {
        val = 0;
        return;
    }
    if (port == 0x201) // joystick
    {
        val = 0xff;
        return;
    }
    if (port == 0x3da)
    {
        static int retrace = 0;
        retrace++;
        val = (retrace & 1) ? 8 : 0;
        return;
    }
    assert(0);
}

WORD& memory16(WORD segment, WORD offset)
{
    if (segment == _dseg)
        return *(WORD*)(datasegment + offset);
    if (segment == _seg000)
        return *(WORD*)(segment0 + offset);

    static WORD dummy;
    _ASSERT(0);
    return dummy;
}
