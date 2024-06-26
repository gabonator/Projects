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

#include "cpu.h"

#include "ega.h"
#include "sdl.h"

CEga mVideo;
void _dump();

constexpr WORD _seg000 = 0x3A56;
constexpr WORD _seg002 = 0x1CFC;
constexpr WORD _dseg = 0x13A5;


void memoryVideoAnd(WORD seg, int ofs, BYTE a)
{
    _ASSERT(ofs >= 0 && ofs <= 0xffff);
    memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) & a);
}
void memoryVideoOr(WORD seg, int ofs, BYTE a)
{
    _ASSERT(ofs >= 0 && ofs <= 0xffff);
    memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) | a);
}

#include "goose.h"

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

uint8_t datasegment[0x10000];
uint8_t segment2[0x10000];
uint8_t segment1[0x10000];
uint8_t segment0[0x10000];
uint8_t segment3[0x10000];
uint8_t segment7[0x10000];
uint8_t segment5[0x10000];
uint8_t segment8[0x10000];
uint8_t segment9[0x10000];
//uint8_t videoram[0x10000];

CSdl mSdl;


BYTE MemData::Get8(WORD seg, int ofs)
{
    _ASSERT(ofs >= 0 && ofs <= 0xffff);

    if (seg >= 0xa000 && seg <= 0xd000)
    {
        _ASSERT(0);
        return memoryVideoGet(seg, ofs);
    }
    return memory(seg, ofs);
}
void MemData::Set8(WORD seg, int ofs, BYTE data)
{
    _ASSERT(ofs >= 0 && ofs <= 0xffff);

    if (seg >= 0xa000)
    {
        _ASSERT(0);
        //data ^= 0xff;
        memoryVideoSet(seg, ofs, data);
        return;
    }
    memory(seg, ofs) = data;
}


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
        for (int i=0; i<100; i++)
        {
            char c = memory(_ds, _dx+i);
            if (!c)
                break;
            filename[i] = c;
            filename[i+1] = 0;
        }
        //char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/binary/";
        char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGoose/";
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
            _flags.carry = 1;
            _ax = 0;
        }
        return;

    }
    if (i == 0x21 && _ah == 0x3f)
    {
        // read file CX bytes => CS:DX
        _ASSERT(f);
        uint8_t* buf = new uint8_t[_cx];
        int c = fread(buf, 1, _cx, f);
        for (int i=0; i<_cx; i++)
            memory(_ds, _dx+i) = buf[i];
        delete[] buf;
        //std::cout << "read " << _cx << " (" << c << ")" << endl;
        _ASSERT(c);
        _flags.carry = 0;
        return;

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
        return;

    }
    if (i == 0x80)
    {
        //sub_24B90();
        return;

    }
    
    if (i == 0x16) // keyboard
    {
        static int simEnter = 0;
        if (_ah == 0x00)
        {
            // returns ah = scan code
            // 0x1c=enter, 0x41=F7?, 0x39=space, 0x50=down, 0x4d=right, 0x48=up, 0x4b=left
            if (simEnter == 0 || simEnter == 1 || simEnter == 2 || simEnter == 3)
                _ah = 0; //0x48;
            else if (simEnter == 4)
                _ah = 0x1c;
            else
                _ah = 0;
            simEnter++;
        }
        return;

    }
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
            cout << hex << "\nset video mode " << (int)_al << endl;
            return;
        }
        if (_ah == 0x10 && _al == 0)
        {
            cout << hex << "\nset text palette[" << (int)_bl << "] = " << (int)_bh << endl;
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

    _ASSERT(0);
}
extern uint32_t getTick();

void _tone(int f)
{
    std::cout << "tone " << hex << f << " f=" << dec << (1193180/f) << "\n";
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
BYTE MemAuto::Get8(WORD seg, int ofs)
{
    _ASSERT(ofs == (WORD)ofs);
    if (seg == 0xa000 || seg == 0xa800 || seg == 0xa400 || seg == 0xa200)
        return memoryVideoGet(seg, ofs);
    return memory(seg, ofs);
}
void MemAuto::Set8(WORD seg, int ofs, BYTE data)
{
    _ASSERT(ofs == (WORD)ofs);
    if (seg == 0xa000 || seg == 0xa800 || seg == 0xa400 || seg == 0xa200)
    {
        memoryVideoSet(seg, ofs, data);
        return;
    }
    memory(seg, ofs) = data;
}

BYTE MemVideo::Get8(WORD seg, int ofs)
{    _ASSERT(ofs == (WORD)ofs);
    _ASSERT(seg == 0xa000 || seg == 0xa400|| seg == 0xa200 || seg == 0xa800);
    return mVideo.Read(seg*16+ofs);
}
void MemVideo::Set8(WORD seg, int ofs, BYTE data)
{
    _ASSERT(ofs == (WORD)ofs);
    _ASSERT(seg == 0xa000 || seg == 0xa400 || seg == 0xa200 || seg == 0xa800);
    mVideo.Write(seg*16+ofs, data);
}

BYTE memoryVideoGet(WORD seg, WORD ofs)
{
    MemVideo memoryVideo;
    return memoryVideo.Get8(seg, ofs);
}

void memoryVideoSet(WORD seg, WORD ofs, BYTE data)
{
    if (seg == 0xa800)
    {
        int f = 9;
    }
    MemVideo memoryVideo;
    memoryVideo.Set8(seg, ofs, data);
}

WORD& memory16(WORD segment, int offset)
{
    _ASSERT(offset == (WORD)offset);
    if (segment == _dseg)
        return *(WORD*)(datasegment + offset);
    if (segment == _seg000)
        return *(WORD*)(segment0 + offset);
    /*
    if (offset==0x236e) {
        int f = 9;
    }
    if (segment == dataseg && offset == 0x9c80)
    {
        int f = 9;
    }
    if (segment == dataseg) // dseg
    {
        return *(WORD*)(datasegment + offset);
    }
    if (segment == seg002) // seg002
    {
        return *(WORD*)(segment2 + offset);
    }
    if (segment == seg003) // seg003
    {
        return *(WORD*)(segment3 + offset);
    }
    if (segment == seg005) // seg003
    {
        return *(WORD*)(segment5 + offset);
    }
    if (segment == seg007) // seg003
    {
        return *(WORD*)(segment7 + offset);
    }
    if (segment == seg008)
    {
        return *(WORD*)(segment8 + offset);
    }
    if (segment == seg009)
    {
        return *(WORD*)(segment9 + offset);
    }
    if (segment == seg000) // seg003
    {
        return *(WORD*)(segment0 + offset);
    }
    if (segment == 0x0000 && (offset == 512 || offset == 514)) // custom int 80h handler
    {
        static WORD dummy = 0;
        return dummy;
    }
    if (segment == 0x0040 && offset == 0x0063)
    {
        static WORD videoAddress = 0x3d4;
        return videoAddress;
    }
*/
    static WORD dummy = 0;
    _ASSERT(0);
    return dummy;
}

BYTE& memory(WORD segment, int offset)
{
    _ASSERT(offset == (WORD)offset);
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

    /*
    if (segment == dataseg && offset == 0x9c80)
    {
        int f = 9;
    }

    if (segment == 0x2565 && offset==0x2472) {
        int f = 9;
    }
    if (segment == dataseg) // dseg
    {
        return *(datasegment + offset);
    }
    if (segment == seg002)
    {
        return *(segment2 + offset);
    }
    if (segment == seg003)
    {
        return *(segment3 + offset);
    }
    if (segment == seg005)
    {
        return *(segment5 + offset);
    }
    if (segment == seg007) // seg003
    {
        return *(segment7 + offset);
    }
    if (segment == seg008)
    {
        return *(segment8 + offset);
    }
    if (segment == seg009)
    {
        return *(segment9 + offset);
    }
    if (segment == seg000)
    {
        return *(segment0 + offset);
    }
    if (segment == seg001)
    {
        return *(segment1 + offset);
    }*/
    static BYTE dummy = 0;
    _ASSERT(0);
    return dummy;
}

void _repne_scasw()
{
    _ASSERT(0);
}

void onKey(int k, int p)
{
 //   memory(dataseg, 0x8f5b) = 0xff;
//    memory(dataseg, 0x8f59) = 0x80;
    /*
    int code = 0;
    switch (k)
    {
        case SDL_SCANCODE_UP: code = 1; break;
        case SDL_SCANCODE_DOWN: code = 2; break;
        case SDL_SCANCODE_LEFT: code = 4; break;
        case SDL_SCANCODE_RIGHT: code = 5; break;
        case SDL_SCANCODE_SPACE: code = 0x80; break;
            
        case SDL_SCANCODE_RETURN: code = 0x80;
            memory(dataseg, 0x8f5b) = 0xff; break;
    }
    memory(dataseg, 0x8f59) = code;*/
    
    
    #define MAPKEY( c, v ) if (k==c) memory(_dseg, 0x8e8a+v) = p
    // http://www.ee.bgu.ac.il/~microlab/MicroLab/Labs/ScanCodes.htm
    MAPKEY( SDL_SCANCODE_LEFT, 75 );
    MAPKEY( SDL_SCANCODE_RIGHT, 77 );
    MAPKEY( SDL_SCANCODE_DOWN, 80 );
    MAPKEY( SDL_SCANCODE_UP, 72 );
    MAPKEY( SDL_SCANCODE_SPACE, 57 );
    MAPKEY( SDL_SCANCODE_N, 49 );
    MAPKEY( SDL_SCANCODE_M, 50 );
    MAPKEY( SDL_SCANCODE_Q, 16 );
    MAPKEY( SDL_SCANCODE_Y, 21 );

}

void loadSegment(uint8_t* buffer, const char* suffix, int len)
{
    memset(buffer, 0, 0x10000);
    char fname[128];
    sprintf(fname, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGoose/goose.%s", suffix);
    //sprintf(fname, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon.%s", suffix);
    
    FILE* f = fopen(fname, "rb");
    fread(buffer, len, 1, f);
    fclose(f);
}

void _sync()
{
    for (int y=0; y<200; y++)
      for (int x=0; x<320; x++)
    {
        //mSdl.SetPixel(x, y, mVideo.GetPixel(x, y, 0x0000));
        //mSdl.SetPixel(x+320, y, mVideo.GetPixel(x, y, 0x2000));
        mSdl.SetPixel(x, y, mVideo.GetPixel(x, y));
        //int pix = memory(0x4d0c, y*256/8+x/8);
        //mSdl.SetPixel(x+320, y, mVideo.palette[((pix >> (7-(x&7))) & 1)*13] );
        //mSdl.SetPixel(x+320, y, mVideo.GetPixel(x, y, 0x0800));
    }
    mSdl.Loop();
    _push(_ax); _push(_bx); _push(_cx); _push(_dx);
    _push(_si); _push(_di); _push(_bp); _push(_ds);
    _ax = _dseg;
    _ds = _ax;
    memory(_dseg, 0x1CF54-0x13A50)++;
    sub_1387D();
    _ds = _pop(); _bp = _pop(); _di = _pop(); _si = _pop();
    _dx = _pop(); _cx = _pop(); _bx = _pop(); _ax = _pop();
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
    
    
    loadSegment(datasegment, "dseg", 38244);
    memset(segment0, 0, 0x10000);
    //loadSegment(segment0, "seg0", 62096);
    mSdl.Init();
    start();
    mSdl.Deinit();
    return 0;
}
