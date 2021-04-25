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

CEga mVideoEga;
CCga mVideoCga;
CVideoAdapter* mVideo = &mVideoCga;
void _dump();

constexpr WORD _seg000 = 0x1000;
constexpr WORD _seg001 = 0x1005;
constexpr WORD _seg002 = 0x100d;
constexpr WORD _seg003 = 0x1839;

int lastPressed = 0;


BYTE memoryBiosGet(WORD seg, WORD ofs)
{
    if (seg == 0xf000 && ofs == 0xfffe)
        return 0xfc; // pc at
    if (seg == 0x0040 && ofs == 0x0087)
        return 0x00; // ega active
    if (seg == 0x0040 && ofs == 0x0017) // http://www.powernet.co.za/info/bios/mem/40_0017.htm
        return 0x00; // shift keys
    _ASSERT(0);
    return 0;
}

void memoryBiosSet(WORD seg, WORD ofs, BYTE v)
{
    std::cout << "Ignoring bios set\n";
}

WORD memoryBiosGet16(WORD seg, WORD ofs)
{
    if (seg == 0x0040 && ofs == 0x006C)
    {
        static WORD c = 0;
        c += 100;
        return c;
    }
    _ASSERT(0);
    return 0;
}

void sub_1AE5E();
void sub_1ABFC();
void sub_1ADF9();
void sub_1AF12();

int _indirectCall(WORD seg, WORD ptr)
{
    switch (ptr)
    {
        case 0x1abe:
            sub_1AE5E();
            return 0x19F23;
        case 0x1ab2: // left
            sub_1ABFC();
            return 0x19F23;
        case 0x1ab8: // right
            sub_1ADF9();
            return 0x19F23;
        case 0x1b8d:
            sub_1AF12();
            return 0x19F89;
        case 0x0000:
            std::cout << "Zero indirect!\n";
            return 0x19F23;
    }
    std::cout << "Ignore indirect call " << seg << " " << ptr;
    _ASSERT(0);
    return 0;
}

#include "tetris.h"

reg_t _reg;

uint8_t data[133296+65536*2];

CSdl mSdl;

using namespace std;
void _interrupt(BYTE i)
{
    static int fileHandle = 1;
    static FILE* f = nullptr;
    if (i == 0x21 && _ah == 0x3e)
    {
        std::cout << "Close file" << endl;
        if (!f)
        {
            _flags.carry = 1;
            return;
        }
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
        for (int j=0; j<100; j++)
        {
            char c = memory(_ds, _dx+j);
            if (!c)
                break;
            filename[j] = c;
            filename[j+1] = 0;
        }
        //char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/binary/";
        char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/res/";
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
    if (i == 0x21 && _ah == 0x40)
    {
        // write file
        std::cout << "Skip write file\n";
        return;
    }
    
    if (i == 0x21 && _ah == 0x3f)
    {
        // read file CX bytes => CS:DX
        
        if (!f)
        {
            _flags.carry  = 1;
            return;
        }
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
    /*
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
        
        if (_ah == 0x01)
        {
            // any key? set _flags.zero 
        }
        return;

    }*/
    if (i == 0x10) // gfx
    {
        static bool newline = false;
        static int lasty = 0;
        
        if (_ah == 0x10 && _al == 0x12)
        {
            mVideo->Interrupt();
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
            if (_al == 0x0d)
                mVideo = &mVideoEga;
            else
                mVideo = &mVideoCga;
            return;
        }
        if (_ah == 0x10 && _al == 0)
        {
            cout << hex << "\nset text palette[" << (int)_bl << "] = " << (int)_bh << endl;
            return;
        }
        if (_ax == 0x1002)
        {
            mVideo->Interrupt();
            //cout << "set palette " << endl;
            return;
        }
        if (_ax == 0x1001)
        {
            cout << "set border " << endl;
            return;
        }
        if (_ah == 0x0c)
        {
            mVideo->SetPixel(_cx, _dx, _al);
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
    if (i == 0x21 && _ah == 0x19)
    {
        // default current drive
        _al = 0;
        return;
    }

    if (i == 0x16 && _ah == 0x01)
    {
        //3b (F1), 3c (F2), 3d (F3), 3e (F4), 3f (F5), 40 (F6), 41 (F7), 42 (F8), 43 (F9), 44 (F10)
        //_ah = 0x3c;
        if (lastPressed == 0)
            _flags.zero = true;
        else
            _flags.zero = false;
        return;
    }

    if (i == 0x16 && _ah == 0x00)
    {
        // K$M&L% 1c H 17 P 2 9
        //0x430,  0x4200, 0x4100, 44, 3b
        _al = 0;
        switch (lastPressed)
        {
            case SDL_SCANCODE_1: _ah = 0x3b; break;
            case SDL_SCANCODE_2: _ah = 0x3c; break;
            case SDL_SCANCODE_3: _ah = 0x3d; break;
            case SDL_SCANCODE_4: _ah = 0x3e; break;
            case SDL_SCANCODE_5: _ah = 0x3f; break;
            case SDL_SCANCODE_6: _ah = 0x40; break;
            case SDL_SCANCODE_7: _ah = 0x41; break;
            case SDL_SCANCODE_8: _ah = 0x42; break;
            case SDL_SCANCODE_9: _ah = 0x43; break;
            case SDL_SCANCODE_0: _ah = 0x44; break;
            case SDL_SCANCODE_Q: _ah = 0x1C; break;
            case SDL_SCANCODE_W: _ah = 0x10; break;
            case SDL_SCANCODE_E: _ah = 0x13; break;
            case SDL_SCANCODE_R: _ah = 0x1F; break;
            case SDL_SCANCODE_T: _ah = 0x01; break;

            case SDL_SCANCODE_Y: _ah = 0x31; break; // 0x15
                
                
            case SDL_SCANCODE_SPACE: _ah = 0x1C; break;
            case SDL_SCANCODE_LEFT: _ah = 'K'; break; // left
            case SDL_SCANCODE_RIGHT: _ah = 'M'; break; // right
            case SDL_SCANCODE_UP: _ah = 'L'; break;
            case SDL_SCANCODE_DOWN: _ah = 'P'; break;
        }
        lastPressed = 0;
        return;
    }
    if (i == 0x21 && _ah == 0x07)
    {
        static int pos = 0;
        const char msg[] = "GABO\r";
        if (msg[pos] == 0)
            _al = 0;
        else
          _al = msg[pos++];
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
    if (i == 0x21 && _ah == 0x0A)
    {
        // buffered input DS:DX
        memory(_ds, _dx+1) = 1;
        memory(_ds, _dx+2) = 'n';
        memory(_ds, _dx+3) = '\n';
        return;
    }
    if (i == 0x21 && _ah == 0x4A)
    {
        // resize memory block
        _flags.carry = false;
        return;
    }
    if (i == 0x1a && _ah == 0x00)
    {
        static int c = 0;
        c += 100;
        _dx = c;
        _cx = 0;
        _al = 0;
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
    if (mVideo->PortWrite8(port, val))
    {
        return;
    }
    if (port == 0x3c4 || port == 0x3c5 || port == 0x3ce || port == 0x3c0)
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

    if (port == 0x3d8 || port == 0x3d9)
    {
//        if (mVideoEga.PortWrite8(port, val))
//            return;
        std::cout << "ignore video out\n";
        return;
    }
    cout << "out8(" << std::hex << (int)port << ", " << (int)val << ")" << endl;
    _ASSERT(0);
}
void _out(WORD port, WORD val)
{
    //cout << "out16(" << std::hex << (int)port << ", " << (int)val << ")" << endl;
    if (mVideo->PortWrite16(port, val))
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
BYTE MemAuto::Get8(WORD seg, WORD ofs)
{
    //if (seg == 0xa000 || seg == 0xa800 || seg == 0xa400 || seg == 0xa200)
    if (seg == 0xa000)
        return memoryVideoGet(seg, ofs);
    return memory(seg, ofs);
}
void MemAuto::Set8(WORD seg, WORD ofs, BYTE data)
{
    //if (seg == 0xa000 || seg == 0xa800 || seg == 0xa400 || seg == 0xa200)
    if (seg == 0xb800 || seg == 0xa000)
    {
        memoryVideoSet(seg, ofs, data);
        return;
    }
    memory(seg, ofs) = data;
}

BYTE MemVideo::Get8(WORD seg, WORD ofs)
{
    _ASSERT(seg == 0xa000);
    return mVideo->Read(seg*16+ofs);
}
void MemVideo::Set8(WORD seg, WORD ofs, BYTE data)
{
    _ASSERT(seg == 0xa000 || seg == 0xb800);
    mVideo->Write(seg*16+ofs, data);
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

WORD& memory16(WORD segment, WORD offset)
{
    if ((segment & 0xa000) == 0xa000)
    {
        int f = 9;
    }

    if (offset == 0x6dff+40)
    {
        int f = 9;
    }
    if (offset == 0x148d)
    {        
        int f = 9;
    }
    _ASSERT(segment >= 0x1000);
    segment -= 0x1000;
    _ASSERT(segment*16+offset < sizeof(data));
    return *(WORD*)(&data[segment*16 + offset]);
}

BYTE& memory(WORD segment, WORD offset)
{
    if (segment*16 + offset >= 0x100d0 + 0x05fa && segment*16 + offset <= 0x100d0 + 0x05fa + 0x01d8)
    {
//        _ASSERT(0);
    }
    _ASSERT(segment >= 0x1000 && segment <= 0xA000);
    segment -= 0x1000;
    _ASSERT(segment*16+offset < sizeof(data));
    return data[segment*16 + offset];
}

void _repne_scasw()
{
    _ASSERT(0);
}

void onKey(int k, int p)
{
    if (p==1)
        lastPressed = k;
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
    /*
    
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
*/
}

void loadSegment(uint8_t* buffer, const char* suffix, int len)
{
    char fname[128];
    sprintf(fname, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/tetris.%s", suffix);
    
    FILE* f = fopen(fname, "rb");
    //fread(buffer+8+4, len, 1, f); ///
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
        mSdl.SetPixel(x, y, mVideo->GetPixel(x, y));
        //int pix = memory(0x4d0c, y*256/8+x/8);
        //mSdl.SetPixel(x+320, y, mVideo.palette[((pix >> (7-(x&7))) & 1)*13] );
        //mSdl.SetPixel(x+320, y, mVideo.GetPixel(x, y, 0x0800));
    }
    mSdl.Loop();
    /*
    _push(_ax); _push(_bx); _push(_cx); _push(_dx);
    _push(_si); _push(_di); _push(_bp); _push(_ds);
    _ax = _dseg;
    _ds = _ax;
    memory(_dseg, 0x1CF54-0x13A50)++;
    sub_1387D();
    _ds = _pop(); _bp = _pop(); _di = _pop(); _si = _pop();
    _dx = _pop(); _cx = _pop(); _bx = _pop(); _ax = _pop();*/
}

int main(int argc, const char * argv[]) {
    m_arrStack.resize(2*64, 0);
    _sp = 64;
    _ds = _es = _di = _bp = 0x6666;
    _ds = _seg000;
    //_cs = _seg003;
    
    
    memset(data, 0, sizeof(data));

    loadSegment(data, "data", 44976);
    mSdl.Init();
    start();
    mSdl.Deinit();
    return 0;
}
