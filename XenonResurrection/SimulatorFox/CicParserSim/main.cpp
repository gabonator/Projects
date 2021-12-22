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


#include "ega.h"
#include "sdl.h"

class CVga : public CVideoAdapter
{
public:
    uint8_t buffer[320*240*6];
    virtual bool PortWrite16(int port, int data)
    {
        return false;
    }
    virtual bool PortWrite8(int port, int data)
    {
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
        uint8_t c = buffer[y*320+x]+16;
        return c | (c<<8) | (c<<16);
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
    if (a == 0x201) // joystick
    {
        v = 0;
        return;
    }
    if (a == 0x3c9) //video
    {
        //_sync();
        std::cout << "video out\n";
        return;
    }
    if (a == 0x388) //audio
    {
        std::cout << "audio\n";
        return;
    }
    if (a == 0x61)
    {
        std::cout << "timer\n";
           return;
    }
    if (a == 0x3da) //video
    {
        //_sync();
        v = rand();
        std::cout << "video\n";
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
    if (port == 0x3c7 || port == 0x3c8 || port == 0x3c9 || port == 0x3c0) // video
    {
        return;
    }
    if (port == 0x388 || port == 0x389 || port == 0x3c4 || port == 0x3c5) // sound
    {
        return;
    }
    if (port == 0x43 || port == 0x61 || port == 0x40)
    {
        return; // timer
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
void _indirectCall(int ofs)
{
    _ASSERT(0);
}

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
    static int fileHandle = 5;
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
        char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/working/";
        strcat(fullname, filename);
        for (int i=0; i<128 && fullname[i]; i++)
            if (fullname[i] == '\\')
                fullname[i] = '/';
        
        std::cout << "Open file: " << filename << endl;
            _flags.carry = 0;
        _ASSERT(f == nullptr);
        _ax = fileHandle++;
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
        
        if (_ah == 0x1a)
        {
            //https://dos4gw.org/INT_10H_1aH_Set_or_Query_Display_Combination_Code
            _al = 0x1a;
            _bl = 0x08; // vga color
            return;
            
        }

        if (_ah == 0x10 && _al == 0x12)
        {
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
        if (_ah == 0x00)
        {
            cout << hex << "\nset video mode " << (int)_al << endl;
            if (_al == 0x13)
                mVideo = &mVga;
            else
                mVideo = &mEga;
            return;
        }
        if (_ah == 0x10 && _al == 0)
        {
            cout << hex << "\nset text palette[" << (int)_bl << "] = " << (int)_bh << endl;
            return;
        }
        if (_ax == 0x1002)
        {
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
void _xlat()
{
    _al = memory(_ds, _bx+_al);
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
    
    _ASSERT(segment >= 0x0180 && segment < 0xa000);
    int ofs = (segment)*16 + offset;
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
}

void loadSegment(uint8_t* buffer, const char* fname, int len, int ofs)
{
    
    FILE* f = fopen(fname, "rb");
    fread(buffer + ofs, len, 1, f);
    fclose(f);
}

void _sync()
{
    for (int y=0; y<200; y++)
      for (int x=0; x<320; x++)
      {
        mSdl.SetPixel(x, y, mVideo->GetPixel(x, y));
      }

    mSdl.Loop();
    SDL_Delay(30);
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
    
    // ds @ 168f:0000    0x6af0 -> 0x168f0
    loadSegment(datasegment, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/working/TEST.EXE", 84992, 0x168f0 - 0x6af0); //33436);
    _ds = 0x168f;
    _cs = 0x1020;
    _ss = 0x200; //0x169f;
    
    
    
    //0x87c0 == 0x6af0
    _ASSERT(memory(_ds, 0x0) == 'F');
    _ASSERT(memory(_cs, 0x0) == 3);
    
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
