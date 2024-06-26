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
#include <map>
#include "cpu.h"

int origrenderer = 0;


void addimage(int x, int y, int w, int h, int o, int s, int f);
void clearimage();
constexpr WORD _seg001 = 0x1000;
constexpr WORD appBase = 0x0000; //0x1020;

int reloc(int p)
{
    return p;
    return p + 0x087c - 0x168f;
//    _ax = 0x087c; //fix relocation gabo//_ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
//    return 0x087c;
}
void memoryVideoSet16(WORD seg, WORD ofs, WORD w);
WORD memoryVideoGet16(WORD seg, WORD ofs);
void memoryVideoAdd(WORD seg, WORD ofs, BYTE data);


#include "ega.h"
#include "sdl.h"

class CVga : public CVideoAdapter
{
public:
    uint8_t buffer[320*240*6];
    uint8_t palette[0x300];
    int readcolorindex{0};

    virtual bool PortWrite16(int port, int data)
    {
        return false;
    }
    virtual bool PortRead8(uint16_t port, uint8_t& data) override
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
    virtual void Write(DWORD dwAddr, BYTE bWrite)
    {
        if (bWrite != 0)
        {
            int f = 9;
        }
        int addr = dwAddr - 0xa000*16;
        _ASSERT(addr >= 0 && addr < sizeof(buffer));
        buffer[addr] = bWrite;
        
        static int q = 0;
        if (q++ > 5000)
        {
            _sync();
            q= 0;
        }
    }
    virtual BYTE Read(DWORD dwAddr)
    {
        int addr = dwAddr - 0xa000*16;
        _ASSERT(addr >= 0 && addr < sizeof(buffer));
        return buffer[addr];
    }
    virtual DWORD GetPixel(int x, int y)
    {
        uint8_t c = buffer[y*320+x];
        /*
        if (y & 1)
            c = buffer[y*320+x + 320*240]+16;
        else
            c = buffer[y*320+x + 320*240*2]+16;
         */
        return (palette[3*c+2]*4) | ((palette[3*c+1]*4)<<8) | ((palette[3*c]*4)<<16);
    }
    virtual void SetPixel(int x, int y, int c)
    {
        _ASSERT(0);
    }
};


CVga mVga;
CEga mEga;
CVideoAdapter* mVideo = &mEga;
CSdl mSdl;

void _in(uint8_t& v, uint16_t a)
{
    if (mVideo->PortRead8(a, v))
    {
        return;
    }

    if (a == 0x201) // joystick
    {
        v = 0;
        return;
    }
    if (a == 0x3c9) //video
    {
        //_sync();
        mVga.PortRead8(a, v);
        std::cout << "video out\n";
        return;
    }
    if (a == 0x388) //audio
    {
        v = 0x60;
        //std::cout << "audio\n";
        return;
    }
    if (a == 0x61)
    {
        std::cout << "timer\n";
           return;
    }
    if (a == 0x3da)
    {
        static int retrace = 0;
        retrace++;
        v = (retrace & 1) ? 8 : 0;
        return;
    }

    _ASSERT(0);

}
void _out(uint16_t port, uint8_t val)
{
    if (mVideo->PortWrite8(port, val))
    {
        return;
    }

    if (port == 0x201) // joystick
    {
        return;
    }
    if (port == 0x3c9 || port == 0x3c8)
    {
        mVga.PortWrite8(port, val);
        return;
    }
    if (port == 0x3c7 || port == 0x3c8 || port == 0x3c0) // video
    {
        return;
    }
    if (port == 0x388 || port == 0x389) // sound
    {
        static int adr = -1;
        if (port==0x388)
            adr=val;
        if (port==0x389)
        {
            //std::cout << " fm [" << adr << "] = " << (int)val << "\n";
            adr = -1;
        }
        return;
    }
    if (port == 0x43 || port == 0x61 || port == 0x40)
    {
        return; // timer
    }
    if (port == 0x3bf || port == 0x3b8) // video
    {
        return;
    }
    if (port == 0x20) // video
    {
        return;
    }
    
    _ASSERT(0);

}
void _out(uint16_t port, uint16_t val)
{
    if (mVideo->PortWrite16(port, val))
    {
        return;
    }

    _ASSERT(0);
}

#include "indirect.h"

void bios16set(int seg, int ofs, int val)
{
    std::cout << "bios write\n";
}
int bios16get(int seg, int ofs)
{
    std::cout << "bios read\n";
    return 0;
    
    
}
#include "fox.h"
reg_t _reg;

uint8_t datasegment[0x10000*80];


void saveSegment(uint8_t* buffer, int ofs, int size, const char* suffix)
{
    char fname[128];
    sprintf(fname, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputRick1/src/%s.out", suffix);

    FILE* f = fopen(fname, "wb");
    fwrite(buffer+ofs, size, 1, f);
    fclose(f);
}

std::map<int, FILE*> myfiles;

using namespace std;
void _interrupt(BYTE i)
{
    static int curdoshandle = 0;
    static int fileHandle = 5;
    static FILE* f = nullptr;
    if (i == 0x21 && _ah == 0x3e)
    {
        _ASSERT(_bx == curdoshandle);
        curdoshandle = -1;
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
        char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/raw/";
        strcat(fullname, filename);
        for (int i=0; i<128 && fullname[i]; i++)
            if (fullname[i] == '\\')
                fullname[i] = '/';
        
        std::cout << "Open file: " << filename << endl;
            _flags.carry = 0;
        _ASSERT(f == nullptr);
        _ax = fileHandle++;
        curdoshandle = _ax;
        myfiles.insert(std::pair<int, FILE*>(_ax, f));
        
        
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
        _ASSERT(_bx == curdoshandle);
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
        _ax = c;
        std::cout << "read " << _cx << " (" << c << ")" << endl;
        //_ASSERT(c);
        _flags.carry = 0; //c == 0;
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
            return;
        }
        if (_ah == 0x01)
        {
            _flags.zero =1;
        }
        return;

    }
    if (i == 0x10) // gfx
    {
        static bool newline = false;
        static int lasty = 0;
        if (_ah == 0x00)
        {
            cout << hex << "\nset video mode " << (int)_al << endl;
            if (_al == 0x13)
                mVideo = &mVga;
            else
                mVideo = &mEga;
            return;
        }

        if (mVideo->Interrupt())
        {
            return;
        }
        if (_ah == 0x1a)
        {
            //https://dos4gw.org/INT_10H_1aH_Set_or_Query_Display_Combination_Code
            _al = 0x1a;
            _bl = 0x08; // vga color
            return;
            
        }

        if (_ah == 0x0b)
        {
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
            fprintf(stdout, "%c", _al < 0x80 ? _al : '#');
            return;
        }
        if (_ah == 0x10 && _al == 0)
        {
            cout << hex << "\nset text palette[" << (int)_bl << "] = " << (int)_bh << endl;
            return;
        }
        if (_ax == 0x1002 || _ax == 0x1012)
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
        if (_ax == 0x1203)
        {
            cout << "video 0x1203? " << endl;
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
        std::cout << "Requested size " << (int)_bx << " paragraphs\n";
        _flags.carry = false;
        return;
    }
    
    if (i == 0x21 && _ah == 0x48)
    {
        if (_bx == (WORD)-1)
        {
            _bx = 0x8000;
            return;
        }
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

    if (i == 0x20)
    {
        saveSegment(datasegment, 0x2000*16, 123255, "blk1");
        ///saveSegment(datasegment, 0x11fff*16, 1048560, "blk2");

    }
    if (i == 0x1a)
    {
        std::cout << "ignore timer\n";
        return;
    }
    _ASSERT(0);
}
extern uint32_t getTick();

void _tone(int f)
{
//    std::cout << "tone " << hex << f << " f=" << dec << (1193180/f) << "\n";
}

void _xlat_cs()
{
    _al = memory(_cs, _bx+_al);
}

void _xlat_ds()
{
    _al = memory(_ds, _bx+_al);
}

void _xlat_es()
{
    _al = memory(_es, _bx+_al);
}

BYTE MemBios::Get8(WORD seg, int ofs)
{
    std::cout << "bios read 2\n";
    return 0;
}
void MemBios::Set8(WORD seg, int ofs, BYTE v)
{
    std::cout << "bios write 2\n";
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
    _ASSERT(ofs >= 0 && ofs <= 0xffff);

    _ASSERT(seg >= 0xa000);
    return mVideo->Read(seg*16+ofs);
}
void MemVideo::Set8(WORD seg, int ofs, BYTE data)
{
    _ASSERT(ofs >= 0 && ofs <= 0xffff);

    _ASSERT(seg >= 0xa000);
    mVideo->Write(seg*16+ofs, data);
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

void memoryVideoAdd(WORD seg, WORD ofs, BYTE data)
{
    memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) + data);
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
    if (segment*16 + offset == 0x168f*16 + 0x527c + 14)
    {
        int f=9;
    }
    if (segment*16+offset == 0x4f5b0)
    {
        int f = 9;
    }
    /*
    if (segment==_seg001 && (offset==0xB369 || offset==0xB37D || offset==0xB391))
    {
        int f = 9;
    }*/
    segment += appBase;
    //_ASSERT(segment == 0x1020 || segment == 0x2499);
    
    _ASSERT(segment >= 0x0180 && segment < 0xa000);
    int ofs = (segment)*16 + offset;
    _ASSERT(ofs >= 0 && ofs < sizeof(datasegment));
    return *(WORD*)(datasegment + ofs);
}

BYTE& memory(WORD segment, int offset)
{
    if (segment*16 + offset == 0x168f*16 + 0x5285)
    {
        int f=9;
    }

    if (segment ==_ds && offset == 21125)
    {
        int f= 9;
    }
    if (segment*16 +offset== 0x10200 + 0x0af4)
    {
        int f=9;
    }

    if (segment*16+offset == 0x4f5b0)
    {
        int f = 9;
    }

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
    _ASSERT(segment >= 0x0100 && segment < 0xa000);
    int ofs = (segment)*16 + offset;
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
    switch (k)
    {
        case SDL_SCANCODE_Q: memory(0x168f, 1067) = p; break;
        case SDL_SCANCODE_W: memory(0x168f, 1069) = p; break;
        case SDL_SCANCODE_E: memory(0x168f, 1070) = p; break;
        case SDL_SCANCODE_R: memory(0x168f, 1084) = p; break;

        case SDL_SCANCODE_UP: memory(0x168f, 0x488) = p; break; // up
        case SDL_SCANCODE_DOWN: memory(0x168f, 0x490) = p; break; // down
        case SDL_SCANCODE_RIGHT: memory(0x168f, 0x48d) = p; break; // left
        case SDL_SCANCODE_LEFT: memory(0x168f, 0x48b) = p; break; // right
        case SDL_SCANCODE_SPACE: memory(0x168f, 0x45c) = p; break; // enter
        case SDL_SCANCODE_P: memory(0x168f, 0x459) = p; break;
        case SDL_SCANCODE_Z:
        {
            /*
             for (int i=0; i<256; i++)
             {
                 for (int y=0; y<16; y++)
                   for (int x=0; x<16; x++)
                   {
                       uint32_t p = mEga.GetPixel2(x, y, 2, 0x5dc0+i*32);
                       p = mEga.palette[p];
                       pixel((i%16)*16+x, (i/16)*16+y, p);
                   }
             }

             */
            uint8_t sprites[256*256];
            FILE* f = fopen("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/sprites", "w");
            for (int i=0; i<256; i++)
            {
                for (int y=0; y<16; y++)
                  for (int x=0; x<16; x++)
                  {
                      uint32_t p = mEga.GetPixel2(x, y, 2, 0x5dc0+i*32);
                      sprites[((i/16)*16+y)*256 + (i%16)*16+x] = p;
                      //p = mEga.palette[p];
                      //pixel((i%16)*16+x, (i/16)*16+y, p);
                  }
            }
            for (int y=0; y<256; y++)
            {
                for (int x=0; x<256; x++)
                {
                    fprintf(f, "%x", sprites[y*256+x]);
                }
                fprintf(f, "\n");
            }
            for (int x=0; x<16; x++)
                fprintf(f, "%08x ", mEga.palette[x]);
            fprintf(f, "\n");

            fclose(f);
            f = fopen("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/map", "w");
            for (int y=0; y<37; y++)
            {
                for (int x=0;x<256; x++)
                {
                    int s = memory(0x5b33, y*256+x);
                    fprintf(f, "%02x ", s);
                }
                fprintf(f, "\n");
            }
            fclose(f);
                
        }
            //0x5b33:0000
            //memory(0x168f, 0x459) = p; break;
    }
    //memory16(0x168f, 0x5285) = 1;
    // ds:1069, ds:1070, ds:1084, ds:1067
}

void loadSegment(uint8_t* buffer, const char* fname, int len, int ofs)
{
    
    FILE* f = fopen(fname, "rb");
    fread(buffer + ofs, len, 1, f);
    fclose(f);
}
std::vector<int> collectx, collecty, collectw, collecth, collects, collecto, collectf;
void addimage(int x, int y, int w, int h, int o, int s, int f)
{
    collectx.push_back(x);
    collecty.push_back(y);
    collectw.push_back(w);
    collecth.push_back(h);
    collects.push_back(s);
    collecto.push_back(o);
    collectf.push_back(f);
}

void pixel(int x, int y, int c)
{
    if (x>=0 && x<320 && y>=0 && y<200)
        mSdl.SetPixel(x, y, c);
}
void rect(int l, int t, int r, int b, int c)
{
    for (int x=l; x<r; x++)
        pixel(x, t, c);
    for (int x=l; x<r; x++)
        pixel(x, b, c);
    for (int y=t; y<b; y++)
        pixel(l, y, c);
    for (int y=t; y<b; y++)
        pixel(r, y, c);
}
void clearimage()
{
    collectx.clear();
    collecty.clear();
    collectw.clear();
    collecth.clear();
    collects.clear();
    collecto.clear();
    collectf.clear();
}
int getmaptile(int x, int y)
{
    return memory(0x5b33, y*256+x);
}
int nearest(int x)
{
    
    int power = 0;
    while(power < x)
        power+=8;
    return power;
}
#include <set>
std::set<int> exportedSprites;

void _sync()
{
    if (0)
    std::cout << "pos " << (int)memory16(0x168f, 0x5270)
    << ","<< (int)memory16(0x168f, 0x5272)
    << ","<< (int)memory(0x168f, 0x5274)
    << ","<< (int)memory(0x168f, 0x5276) << "\n";
    
    if (0)
    std::cout << "energy " << (int)memory(0x168f, 1049) << "\n";
//
//    _ah = memory(_ds, 0x5272);                   //mov ah, byte ptr [0x5272]
//    _al = memory(_ds, 0x5270);                  //mov al, [0x5270]

    if (1)
    {
    for (int y=0; y<200; y++)
      for (int x=0; x<320; x++)
      {
        mSdl.SetPixel(x, y, mVideo->GetPixel(x, y));
      }
    } else
    {
    for (int y=0; y<12; y++)
      for (int x=0; x<20; x++)
      {
          int t = getmaptile((int)memory16(0x168f, 0x5270)+x, memory(0x168f, 0x5272)+y);
          for (int _y=0; _y<16; _y++)
              for (int _x=0; _x<16; _x++)
              {
                  int p = mEga.GetPixel2(_x, _y, 2, 0x5dc0+t*32);
                  p = mEga.palette[p];
                  pixel(x*16+_x, y*16+_y, p);
              }
      }

    for(int i=0; i<collectx.size(); i++)
    {
        FILE* f = nullptr;
        /*
        int spriteid = collects[i]*16 + collecto[i];
        
        if (exportedSprites.find(spriteid) == exportedSprites.end())
        {
            exportedSprites.insert(spriteid);
            char path[256];
            sprintf(path, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/sprites/%04x_%04x", collects[i], collecto[i]);
            f = fopen(path, "w");
        }*/
            
        int frame = collectw[i]*collecth[i];
        int pitch = collectw[i];
        for (int y=0; y<collecth[i]; y++)
        {
            for (int x=0; x<collectw[i]*8; x++)
            {
                int plane0 = memory(collects[i], collecto[i]+y*pitch+x/8+frame*0);
                int plane1 = memory(collects[i], collecto[i]+y*pitch+x/8+frame*1);
                int plane2 = memory(collects[i], collecto[i]+y*pitch+x/8+frame*2);
                int plane3 = memory(collects[i], collecto[i]+y*pitch+x/8+frame*3);
                int plane4 = memory(collects[i], collecto[i]+y*pitch+x/8+frame*4);
                int p0 = (plane0 >> (7-(x&7)))&1;
                int p1 = (plane1 >> (7-(x&7)))&1;
                int p2 = (plane2 >> (7-(x&7)))&1;
                int p3 = (plane3 >> (7-(x&7)))&1;
                int p4 = (plane4 >> (7-(x&7)))&1;
                int p = p1 + 2*p2 + 4*p3 + 8*p4;
                if (f)
                {
                    if (p0)
                        fprintf(f, "%x", p);
                    else
                        fprintf(f, " ");
                }
                p = mEga.palette[p];
                if (p0)
                {
                    if (!collectf[i])
                        pixel((short)collectx[i]+ x, (short)collecty[i] + y, p);
                    else
                        pixel((short)collectx[i]+ collectw[i]*8-1 - x, (short)collecty[i] + y, p);
                }

            }
            if (f)
                fprintf(f, "\n");
        }
        if (f)
            fclose(f);
        if (0)
        rect((short)collectx[i], (short)collecty[i], (short)collectx[i] + (short)collectw[i]*8, (short)collecty[i] + (short)collecth[i], 0xff0000);
    }
    }
    mSdl.Loop();
    SDL_Delay(5);
    /*
    int f = _reg.flags.f16;
    int sp = _sp;
    static int cycle = 0;
    cycle++;
    _push(_ax);
    _push(_bx);
    _push(_cx);
    _push(_dx);
    _push(_si);
    _push(_di);
    _push(_ds);
    _push(_es);
    
    sub_138b();
    _es = _pop();
    _ds = _pop();
    _di = _pop();
    _si = _pop();
    _dx = _pop();
    _cx = _pop();
    _bx = _pop();
    _ax = _pop();
    _ASSERT(_ds);
    _ASSERT(_sp == sp);
    _reg.flags.f16 = f;
     */
}

int main(int argc, const char * argv[]) {
    m_arrStack.resize(2*64, 0);
    _sp = 64;
    _ds = _es = _di = _bp = 0x6666;
    _ds = reloc(0x168f);
    _ss = reloc(0x168f);
    _cs = (0x0fe00+0x400)/0x10;
    //_cs = seg000;
    
    // 0x6af0 -> reloc(0x168f):0000    !!! -> 087C:0000
    // 0x400  -> cs:0000        !!! -> 020d:0000
    int ofs = reloc(0x168f) - 0x087C;
    _ds -= ofs;
    _cs -= ofs;
    
    // file ofs 0x6af0 => ptr reloc(0x168f)0
    // load binary at reloc(0x168f)0 - 0x6af0 = 0xfe00
    
    memset(datasegment, 0, sizeof(datasegment));
    /*
    // ds @ 087c:0000
    loadSegment(datasegment, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/working/TEST.EXE", 84992, 0x1cd0); //33436);
    _cs = 0x020d;
*/
    
    // ds @ 168f:0000    0x6af0 -> 0x168f0  (+0xfe00)
    loadSegment(datasegment, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/raw/game.exe", 84992, 0x168f0 - 0x6af0); //33436);
    _ds = 0x168f;
    _cs = 0x1020;
    _ss = 0x200; //0x169f;
    
    
    
    //0x87c0 == 0x6af0
    _ASSERT(memory(_ds, 0x0) == 'F');
    _ASSERT(memory(_cs, 0x0) == 3);
    _ds = 0x01dd-0x087c+0x168f;
    _ss = 0x01ed-0x087c+0x168f;
    _bp = 0x091c;
    _es = _ds;

    mSdl.Init();
/*
    _ds = 0x01dd;
    _ss = 0x01ed;
    _es = 0x01dd;
    memory(0x01dd, 0x0080) = 0;
    memory(0x01dd, 0x0081) = 0x0d;
 */
    memory(_ds, 0x0080) = 0;
    memory(_ds, 0x0081) = 0x0d;
    entry();
    mSdl.Deinit();
    return 0;
}
