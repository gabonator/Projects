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

constexpr WORD appBase = 0x0000; //0x1020;

#include "ega.h"
#include "sdl.h"

CEga mVideo;
void _dump();

std::list<int> keyboardBuffer;
constexpr WORD _seg000 = 0x1000 - appBase;
constexpr WORD _seg001 = 0x1040 - appBase;
//constexpr WORD _seg002 = 0x13EC - appBase;

void memoryVideoSet16(WORD seg, WORD ofs, WORD w);
void memoryVideoOr16(WORD seg, WORD ofs, WORD x);
void memoryVideoOr(WORD seg, WORD ofs, BYTE x);
WORD memoryVideoGet16(WORD seg, WORD ofs);
WORD memoryBiosGet16(WORD seg, WORD ofs)
{
    if (seg == 0x0040 && ofs == 0x0063)
        return 0x3d4;
    _ASSERT(0);
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

uint8_t datasegment[0x10000*20];

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
    static int fileHandle = 1;
    static FILE* f = nullptr;
    if (i == 0x21 && _ah == 0x3e)
    {
        std::cout << "Close file" << endl;
        _ASSERT(f);
        fclose(f);
        f = nullptr;
        _flags.carry = 0;
        return;
    }

    if (i == 0x21 && _ah == 0x3d)
    {
        // read file DS:DX filename
        // AX = file handle
        char filename[100];
        bool dot = false;
        int p = 0;
        for (int i=0; i<100; i++)
        {
            char c = memory(_ds, _dx+i);
            if (c==' ')
                continue;
            if (!c)
                break;
            filename[p++] = c;
        }
        filename[p] = 0;
        //char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/binary/";
        char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputRick2/binary/";
        strcat(fullname, filename);
        for (int i=0; i<128 && fullname[i]; i++)
            if (fullname[i] == '\\')
                fullname[i] = '/';
        
        std::cout << "Open file: " << filename << endl;
            _flags.carry = 0;
        _ASSERT(f == nullptr);
        _ax = fileHandle++;
        
        f = fopen(fullname, "rb");
        if (!f)
        {
            std::cout << "Not found: " << filename << endl;
            
            f = fopen(fullname, "rb");
            if (!f)
            {
                _flags.carry = 1;
                _ax = 0;
            }
        }
        return;

    }
    if (i == 0x21 && _ah == 0x3f)
    {
        // read file CX bytes => CS:DX
        _ASSERT(f);
        //int16_t s = _cx;
        //_ASSERT(s > 0);
        uint8_t* buf = new uint8_t[_cx];
        int c = fread(buf, 1, _cx, f);
        for (int i=0; i<c; i++)
            MemData::Set8(_ds, _dx+i, buf[i]);
            //memory(_ds, _dx+i) = buf[i];
        delete[] buf;
        std::cout << "read " << _cx << " (" << c << ")" << endl;
        _ASSERT(c);
        _flags.carry = 0;
        return;

    }
    
    if (i == 0x21 && _ah == 0x42)
    {
        // move file pointer
        if (_al == 2 && _cx == 0 && _dx == 0)
        {
            _ASSERT(f);
            fseek(f, 0L, SEEK_END);
            _ax = ftell(f);
            fseek(f, 0L, SEEK_SET);
            _dx = 0;
            return;
        }
        if (_al == 0 &&  _dx == 0)
        {
            _ASSERT(f);
            fseek(f, _cx, SEEK_SET);
            return;
        }

    }

    if (i == 0x21 && _ah == 0x35)
    {        
        // get int vect AL ES:BX
        // AL == 08 -> system timer
        _es = 0;
        _bx = 0;
        return;

    }
    if (i == 0x21 && _ah == 0x25)
    {
        // set int vect AL DS:DX
        // seg000:600b - TODO: ignorujeme
        std::cout << "set int vect " << std::hex << (int)_al << "\n";
        return;

    }
    if (i == 0x80)
    {
        //sub_24B90();
        return;

    }
    
    if (i == 0x16) // keyboard
    {
        // TODO
        static int simEnter = 0;
        if (_ah == 0x00)
        {
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
        if (_ah == 0x0b)
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
            mVideo.SetPaletteIndex(_bl, _bh);
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
    
    if (i == 0x1A && _ah == 0x00)
    {
        // time of day
        _cx = 1;
        _dx = 1;
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
        //_buffer = (-getTick()*6) &0xffff;
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
BYTE MemData::Get8(WORD seg, int ofs)
{
    if (seg >= 0xa000 && seg <= 0xd000)
        _ASSERT(0);
        //return memoryVideoGet(seg, ofs);
    return memory(seg, ofs);
}
void MemData::Set8(WORD seg, int ofs, BYTE data)
{
    if (seg >= 0xa000)
    {
        _ASSERT(0);
        //memoryVideoSet(seg, ofs, data);
        return;
    }
    memory(seg, ofs) = data;
}

BYTE MemVideo::Get8(WORD seg, int ofs)
{
    _ASSERT(seg >= 0xa000);
    return mVideo.Read(seg*16+ofs);
}
void MemVideo::Set8(WORD seg, int ofs, BYTE data)
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

void memoryVideoOr(WORD seg, WORD ofs, BYTE data)
{
    memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) | data);
}

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



WORD& memory16(WORD segment, int offset)
{
    _ASSERT(offset <= 0xffff && offset >= 0);
    _ASSERT(segment != 0);
    /*
    if (segment==_seg001 && (offset==0xB369 || offset==0xB37D || offset==0xB391))
    {
        int f = 9;
    }*/
    segment += appBase;
    //_ASSERT(segment == 0x1020 || segment == 0x2499);
    
    _ASSERT(segment >= 0x1000);
    _ASSERT(segment >= 0x1000 && segment < 0xa000);
    int ofs = (segment-0x1000)*16 + offset;
    _ASSERT(ofs >= 0 && ofs < sizeof(datasegment));
    return *(WORD*)(datasegment + ofs);
}

BYTE& memory(WORD segment, int offset)
{
    _ASSERT(offset <= 0xffff && offset >= 0);
    if (segment==_seg001 && offset == 0x571c)
    {
        int f = 9;
    }
    if (segment==_seg001 && (offset==0xB369 || offset==0xB37D || offset==0xB391))
    {
        int f = 9;
    }
//    if (segment == _seg001 && offset == 0xA85E)
//    {
//        int f=9;
//    }
    segment += appBase;
    _ASSERT(segment >= 0x1000 && segment < 0xa000);
    int ofs = (segment-0x1000)*16 + offset;
    _ASSERT(ofs >= 0 && ofs < sizeof(datasegment));
    return *(datasegment + ofs);
}

void _repne_scasw()
{
    _ASSERT(0);
}
bool slowdown{false};

void onKey(int k, int p)
{
    static int keys = 0;
    switch (k)
    {
        case SDL_SCANCODE_UP: keys = p ? keys | 8 : keys & ~8; break;
        case SDL_SCANCODE_DOWN: keys = p ? keys | 4 : keys & ~4; break;
        case SDL_SCANCODE_LEFT: keys = p ? keys | 2 : keys & ~2; break;
        case SDL_SCANCODE_RIGHT: keys = p ? keys | 1 : keys & ~1; break;
        case SDL_SCANCODE_RSHIFT:
        case SDL_SCANCODE_LSHIFT:
        case SDL_SCANCODE_Z:
        case SDL_SCANCODE_SPACE: keys = p ? keys | 16 : keys & ~16; break;
        case SDL_SCANCODE_LCTRL:
        case SDL_SCANCODE_RCTRL: slowdown = p;
    }
    //memory(_seg001, 0xA85E) = p ? 0 : 255;
    memory(_seg001, 0xB884) = keys;
    
    if (p)
    {
        int key = 0;
        switch (k)
        {
        
            case SDL_SCANCODE_D: key = 0x1 << 8; break;
            case SDL_SCANCODE_E: key = 0x30 << 8; break;
        }

    }

}

void loadSegment(uint8_t* buffer, const char* suffix, int len)
{
    //memset(buffer, 0, 0x10000);
    char fname[128];
    sprintf(fname, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputRick2/%s", suffix);
    //sprintf(fname, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon.%s", suffix);
    
    FILE* f = fopen(fname, "rb");
    fread(buffer, len, 1, f);
    fclose(f);
}
//extern int synccalls;
void _sync()
{
    /*
    static int calls = 0;
    if (calls++ > 20)
    {
        calls = 0;
        memory(_seg001, 0xA85E) = 0x00;
    } else
        memory(_seg001, 0xA85E) = 0xff;
    
    if (memory(_seg001, 0xA85E) > 0)
    {
        memory(_seg001, 0xA85E)--;
    }*/

//    synccalls = 0;
    static int xx =0;
    xx++;
    for (int k=1430; k<1431; k++)
    {
        //memory(0x2000, k+0x0000) = 0xff;
        //memory(0x2000, k+0x0800) = 0xff;
        //memory(0x2000, k+0x1000) = 0xff;
        //memory(0x2000, k+0x1800) = 0xff;
        //memory(0x2000, k+0x2000) = 0xff;
    }
    for (int y=0; y<200; y++)
      for (int x=0; x<320; x++)
      {
        mSdl.SetPixel(x, y, mVideo.GetPixel(x, y, 0));
        /*
          
          BYTE* _video = (BYTE*)&memory(0x2000, 0x0000); //datasegment+0x1000*16;
          //DWORD off = (int)y * 40L + ((int)x / 8L);
          
          //DWORD mem_addr = off;
          int mask = 0x80 >> (x % 8);

          //int page = ((getTick() >> 8) & 1) ? 0x6800 : cfgAddr; //cfgAddr; 0xa700-0
          //int page = 0;
      
          int off = 0x800;
          int shift = (int)y * 1L + ((int)x / 8L)*180;
          BYTE b = 0;
          if ( _video[shift + off*0] & mask ) b |= 1;
          if ( _video[shift + off*1] & mask ) b |= 2;
          if ( _video[shift + off*2] & mask ) b |= 4;
          if ( _video[shift + off*3] & mask ) b |= 8;

          mSdl.SetPixel(x+320, y, mVideo.palette[b]);
*/
          //int c = memory(0x2000, x)
      }

    mSdl.Loop();
        SDL_Delay(slowdown ? 120 : 30);

}

//
//void saveSegment(uint8_t* buffer, const char* suffix)
//{
//    char fname[128];
//    sprintf(fname, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/%s.out", suffix);
//
//    FILE* f = fopen(fname, "wb");
//    fwrite(buffer, 0x10000, 1, f);
//    fclose(f);
//}
//
//void _dump()
//{
//    static bool once = true;
//    if (once)
//        once = false;
//    else
//        return;
//
//    stringstream ss;
//    ss << "palette = [";
//    for (int i=0; i<16; i++)
//        ss << "0x" << hex << std::setw(6) << std::setfill('0') << mVideo.palette[i] << ", ";
//    ss << "]";
//    cout << ss.str();
//
//    saveSegment(segment0, "seg0");
//    saveSegment(segment2, "seg2");
//    saveSegment(segment3, "seg3");
//    saveSegment(segment5, "seg5");
//    saveSegment(segment7, "seg7");
//    saveSegment(segment9, "seg9");
//    saveSegment(datasegment, "segd");
//}
//
int main(int argc, const char * argv[]) {
    m_arrStack.resize(2*64, 0);
    _sp = 64;
    _ds = _es = _di = _bp = 0x6666;
    _ds = _seg001;
    //_cs = seg000;
//    loadSegment(datasegment, "dseg", 21815);
//    loadSegment(segment2, "seg2", 2742);
//    loadSegment(segment0, "seg0", 62096);
//    loadSegment(segment3, "seg3", 11999); // ma byt 12000 !!!
//    loadSegment(segment1, "seg1", 0x5900);
//    memset(segment5, 0, 0x10000);
//    memset(segment7, 0, 0x10000);
//    memset(segment8, 0, 0x10000);
//    memset(segment9, 0, 0x10000);
//    //memset(videoram, 0xff, 0x10000);
    
    
    memset(datasegment, 0, sizeof(datasegment));
    loadSegment(datasegment, "rick2.data", 50415); //33436);
    mSdl.Init();
    while (1)
    {
        start();
        _sync();
    }
    mSdl.Deinit();
    return 0;
}
