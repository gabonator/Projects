//
//  main.cpp
//  CicParserSim
//
//  Created by Gabriel Valky on 12/16/20.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <list>

#include "cpu.h"
void __debugRect(int, int, int, int);
void __debugPoint(int, int);

void debugPoint(int, int);
int __fireptr = 0xffee;
bool __sync = false;
constexpr WORD appBase = 0x0000; //0x1020;
int _ss;

#include "ega.h"
#include "sdl.h"

CCga mVideo;
void _dump();

std::list<int> keyboardBuffer;
constexpr WORD _dseg = 0x7200;
constexpr WORD _code = 0x9000;

void memoryVideoAnd(WORD seg, WORD ofs, BYTE a)
{
    memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) & a);
}
void memoryVideoOr(WORD seg, WORD ofs, BYTE a)
{
    memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) | a);
}
BYTE& memoryCode(WORD segment, WORD offset);
WORD& memoryCode16(WORD segment, WORD offset);

void memoryVideoSet16(WORD seg, WORD ofs, WORD w);
void memoryVideoOr16(WORD seg, WORD ofs, WORD x);
void memoryVideoOr(WORD seg, WORD ofs, BYTE x);
WORD memoryVideoGet16(WORD seg, WORD ofs);
BYTE memoryBiosGet(WORD seg, WORD ofs)
{
    if (seg == 0xf000 && ofs == 0xfffe)
        return 0xff;
    std::cout << "ignore bios get " << (int)seg << ":" << (int)ofs << "\n";
    return 0;
}
BYTE memoryBiosGet16(WORD seg, WORD ofs)
{
    if (seg == 0xf000 && ofs == 0xfffe)
        return 0xff;
    //_ASSERT(0);
    std::cout << "ignore bios get " << (int)seg << ":" << (int)ofs << "\n";

    return 0;
}
void memoryBiosSet16(WORD seg, WORD ofs, WORD d)
{
    //word 0040:004E  Offset to the current display page
    if (ofs == 0x4E)
        return;
    
    std::cout << "ignore bios " << std::hex << seg << ":" << ofs << " = " << d << "\n";
//Offset to the current display page
}

void memoryBiosSet(WORD seg, WORD ofs, BYTE d)
{
    std::cout << "ignore bios set " << (int)seg << ":" << (int)ofs << " = " << (int) d << "\n";
}

#include "indirect.h"
#include "rick2.h"

//constexpr WORD seg000 = 0x1000;
//constexpr WORD seg002 = 0x24B9;
//constexpr WORD dataseg = 0x2853;
//constexpr WORD seg001 = 0x1f29;
//constexpr WORD seg003 = 0x2565;
//constexpr WORD seg005 = 0x3824;
//constexpr WORD seg007 = 0x449b;
//constexpr WORD seg008 = 0x5489;
//constexpr WORD seg009 = 0x63d0;
//constexpr WORD video = 0xa000;
//
//#include "code.h"
//#include "code-loader.h"
//#include "code-intro.h"
//#include "code-pregame.h"
//#include "code-game.h"

reg_t _reg;

uint8_t datasegment[0x8000];
uint8_t codesegment[0x100];
CSdl mSdl;
/*
uint8_t mark2[0x10000] = {0};
uint8_t mark1[0x10000] = {0};
uint8_t mark0[0x10000] = {0};
uint8_t mark3[0x10000] = {0};
uint8_t mark7[0x10000] = {0};
uint8_t mark5[0x10000] = {0};
uint8_t mark9[0x10000] = {0};
uint8_t markd[0x10000] = {0};
*/

using namespace std;
void _interrupt(BYTE i)
{
    if (i == 0x16) // keyboard
    {
        // TODO
        static int simEnter = 1;
        if (_ah == 0x00)
        {
            if (simEnter)
            {
                simEnter = 0;
                _ah = 0x1c;
                return;
            }
            /*
            // returns ah = scan code
            // 0x1c=enter, 0x41=F7?, 0x39=space, 0x50=down, 0x4d=right, 0x48=up, 0x4b=left
            if (simEnter == 0 || simEnter == 1 || simEnter == 2 || simEnter == 3)
                _ah = 0; //0x48;
            else if (simEnter == 4)
                _ah = 0x1c;
            else
                _ah = 0;
            simEnter++;
             */
            //_sync();
            if (keyboardBuffer.size() > 0)
            {
                _ax = keyboardBuffer.front();
                keyboardBuffer.pop_front();
            }
            return;
        }
        if (_ah == 0x01)
        {
            _flags.zero = (keyboardBuffer.size() == 0);
        }
        return;

    }
    if (i == 0x10) // gfx
    {
        static bool newline = false;
        static int lasty = 0;
        
        if ( _ah == 0x0e )
        {
            // al = char, bh = page, bl = color
            std::cout << _al;
            return;
        }

        if (_ah == 0x1a)
        {
            //https://dos4gw.org/INT_10H_1aH_Set_or_Query_Display_Combination_Code
            _al = 0x1a;
            _bl = 0x08; // vga color
            return;
            
        }

        if (_ah == 0x10 && _al == 0x12)
        {
            mVideo.Interrupt();
            return;
        }
        if (_ah == 0x0b || _ax == 0x1010)
        {
            mVideo.Interrupt();
            return;
        }
        if (_ah == 0x1a)
        {
            // get video info
            //http://www.techhelpmanual.com/177-int_10h_1ah__set_or_query_display_combination_code.html
            _al = 0x1a;
            _bl = 5; // ega mono!?
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
            cout << hex << "\nset video mode " << (int)_al << endl;
            return;
        }
        if (_ah == 0x10 && _al == 0)
        {
            cout << hex << "\nset text palette[" << (int)_bl << "] = " << (int)_bh << endl;
            //mVideo.SetPaletteIndex(_bl, _bh);
            return;
        }
        if (_ax == 0x1002)
        {
            mVideo.Interrupt();
            //cout << "set palette " << endl;
            return;
        }
        if (_ax == 0x1001)
        {
            cout << "set border " << endl;
            return;
        }
        if (_ax == 0x1110)
        {
            cout << "set custom font " << endl;
            /*
             AX    1110H
             BH    height of each character (bytes per character definition)
             BL    font block to load (EGA: 0-3; VGA: 0-7)
             CX    number of characters to redefine
             DX    ASCII code of the first character defined at ES:BP
             ES:BP address of font-definition information
             */
            // set custom font
            // 1020:2639
            return;
        }
        if (_ax == 0x1201)
        {
            cout << "set vertical resolution " << endl;
            return;
        }
        if (_ax == 0x1103)
        {
            cout << "block specifier " << endl;
            return;
        }
        if (_ax == 0x1003)
        {
            cout << "toggle intensity blinking " << endl;
            return;
        }

        _ASSERT(0);
        return;
    }
    
    // star goose
    if (i == 0x12)
    {
        _ax = 0x800;
        return;
    }
    if (i == 0x21 && _ah == 0x09)
    {
        for(int i=0; i<200; i++)
        {
            char c = memory(_ds, _dx+i);
            if (c == '$')
                return;
            std::cout << c;
        }
        _ASSERT(0);
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
    
    if (i == 0x1A)
    {
        static uint32_t base = 0;
        int now = getTick();
        if (_ah == 0)
        {
            if (base == 0)
                base = now;
            now -= base;
            now = now /6; //* 65536 / (1000*60*60);
            _cx = now >> 16;
            _dx = now & 0xffff;
        } else {
            _ASSERT(_ah == 1 && _cx == 0 && _dx == 0);
            base = now;
        }
        return;
    }
    
    if (i == 0x21 && _ah == 0x2c)
    {
        _ch = 1; // hours
        _cl = 0; // mins
        _dx = 0;
        return;
        
    }
    if (i == 0x21 && _ah == 0x2a)
    {
        _dl = 1; // day
        _dh = 1; // month
        _cx = 2035;
        
        return;
        
    }
    if (i == 0x21 && _ah == 0x4a)
    {
        // resize block
        _flags.carry = false;
        return;
    }
    
    if (i == 0x21 && _ah == 0x48)
    {
        static int freeMem = 0x2000;
        // _bx size
        std::cout << "malloc " << dec << (int)(_bx*16) << "bytes -> " << hex << freeMem << ":0000\n";
        _ax = freeMem;
        freeMem += _bx;
        _flags.carry = false;
        return;
    }
    if (i == 0x21 && _ah == 0x4c)
    {
        // end program
    }
    if ( i == 0x11 )
    {
        // al = 0001 1110
        // ah = 1011 1001
        _ax = 0xb91e;
        return;
    }

    _ASSERT(0);
}
extern uint32_t getTick();

void _tone(int f)
{
//    std::cout << "tone " << hex << f << " f=" << dec << (1193180/f) << "\n";
}
void _out(WORD port, BYTE val)
{
    if (mVideo.PortWrite8(port, val))
    {
        return;
    }
    if (port == 0x201 )
    {
        return;
    }
    if (port == 0x40)
    {
        return;
    }
    
    if (port == 0x61)
    {
        if ((val & 3) == 3)
        {
            // speaker on
            return;
        }
        if ((val & 3) == 0)
        {
            // speaker ff
            return;
        }
        return;
        _ASSERT(0);
    }
    
    static int _p42 = 0;
    static int _buffer42 = 0;
    
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
        _buffer42 = (-getTick()*6) &0xffff;
      } else
          _ASSERT(0);
        // 0x36 = 0 0 1 1  0 1 1 0
        return;
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
        return;
    }
    if ( port == 0x3d9 )
    {
        return;
    }

    cout << "out8(" << std::hex << (int)port << ", " << (int)val << ")" << endl;
    _ASSERT(0);
}
void _out(WORD port, WORD val)
{
    //cout << "out16(" << std::hex << (int)port << ", " << (int)val << ")" << endl;
    if (mVideo.PortWrite16(port, val))
    {
        return;
    }
    _ASSERT(0);
}

void _in(BYTE& val, WORD port)
{
    //cout << "in(" << std::hex << (int)port << ")" << endl;
    if (port == 0x40)
    {
        val = 0;
        return;
    }
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
    _ASSERT(0);
}
void _xlat()
{
    _al = memory(_ds, _bx+_al);
}
BYTE MemData::Get8(WORD seg, WORD ofs)
{
    if (seg >= 0xa000 && seg <= 0xd000)
        return memoryVideoGet(seg, ofs);
    return memory(seg, ofs);
}
void MemData::Set8(WORD seg, WORD ofs, BYTE data)
{
    if (seg >= 0xa000)
    {
        //_ASSERT(0);
        //data ^= 0xff;
        memoryVideoSet(seg, ofs, data);
        return;
    }
    memory(seg, ofs) = data;
}

BYTE MemVideo::Get8(WORD seg, WORD ofs)
{
    _ASSERT(seg >= 0xa000);
    return mVideo.Read(seg*16+ofs);
}
void MemVideo::Set8(WORD seg, WORD ofs, BYTE data)
{
    _ASSERT(seg >= 0xa000);
    mVideo.Write(seg*16+ofs, data);
}

BYTE memoryVideoGet(WORD seg, WORD ofs)
{
    MemVideo memoryVideo;
    return memoryVideo.Get8(seg, ofs);
}

WORD memoryVideoGet16(WORD seg, WORD ofs)
{
    MemVideo memoryVideo;
    return memoryVideo.Get8(seg, ofs) | (memoryVideo.Get8(seg, ofs+1)<<8);
}


void memoryVideoSet(WORD seg, WORD ofs, BYTE data)
{
    MemVideo memoryVideo;
    memoryVideo.Set8(seg, ofs, data);
}

//void memoryVideoOr(WORD seg, WORD ofs, BYTE data)
//{
//    memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) | data);
//}

void memoryVideoSet16(WORD seg, WORD ofs, WORD w)
{
    memoryVideoSet(seg, ofs+1, w>>8);
    memoryVideoSet(seg, ofs, w & 255);
}


void memoryVideoOr16(WORD seg, WORD ofs, WORD x)
{
    memoryVideoOr(seg, ofs, x&0xff);
    memoryVideoOr(seg, ofs+1, x>>8);
}


BYTE& memoryCode(WORD segment, WORD offset)
{
    _ASSERT(offset >= 0x1300 && offset < 0x1400);
    return *(codesegment + offset - 0x1300);
}

WORD& memoryCode16(WORD segment, WORD offset)
{
    _ASSERT(offset >= 0x1300 && offset < 0x1400);
    return *(WORD*)(codesegment + offset - 0x1300);
}

WORD& memory16(WORD segment, WORD offset)
{
    if (segment != _dseg )
    {
        _ASSERT(0);
    }
    
    _ASSERT(offset >= 0x0 && offset < sizeof(datasegment));
    return *(WORD*)(datasegment + offset);
}

BYTE& memory(WORD segment, WORD offset)
{
    if (segment != _dseg )
    {
        _ASSERT(0);
    }
    _ASSERT(offset >= 0x0 && offset < sizeof(datasegment));
    return *(datasegment + offset);
}

void _repne_scasw()
{
    _ASSERT(0);
}

void onKey(int k, int p)
{
    // de right&leftn
    // cf
    // cd
    // ef
    int keys[] = {
        SDL_SCANCODE_UP, SDL_SCANCODE_RIGHT, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT,
        1, 1, 1, 1, 1,
        SDL_SCANCODE_Y, SDL_SCANCODE_N, SDL_SCANCODE_K, SDL_SCANCODE_H, SDL_SCANCODE_T,
        SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_R, SDL_SCANCODE_RETURN, SDL_SCANCODE_SPACE, 0};
// aj 0x6bc sa analyzuje
    
    for (int i=0; keys[i]; i++)
        if (k == keys[i])
            memory(_dseg, 0x6B8+i) = p ? 0x00 : 0x80;

    if (p)
        memory16(_dseg, 0x693)++;
}

void loadSegment(uint8_t* buffer, const char* suffix, int len)
{
    //memset(buffer, 0, 0x10000);
    char fname[128];
    sprintf(fname, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputCat/%s", suffix);
    
    FILE* f = fopen(fname, "rb");
    fread(buffer, len, 1, f);
    fclose(f);
}

void _sync()
{

    for (int y=0; y<200; y++)
      for (int x=0; x<320; x++)
      {
        mSdl.SetPixel(x, y, mVideo.GetPixel(x, y));
      }

    mSdl.Loop();
}

int main(int argc, const char * argv[]) {
    m_arrStack.resize(2*256, 0);
    _sp = 256;
    _ds = _es = _di = _bp = 0x6666;

    memset(datasegment, 0, sizeof(datasegment));
    loadSegment(datasegment, "datasegment", 28976); //33436);
    mSdl.Init();
    while (1)
    {
        start();
        _sync();
    }
    mSdl.Deinit();
    return 0;
}
