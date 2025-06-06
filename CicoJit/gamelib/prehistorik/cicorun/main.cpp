// Other linker flags: /opt/homebrew/lib/libSDL2.dylib
// System header search paths: /opt/homebrew/include/SDL2
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "sdl.h"
#define _HOST
#include "cicoemu.h"
#include "ega.h"
#include <list>
//#include "game/game.h"

bool tracenow = false;
namespace CicoContext{
    cicocontext_t* ctx;
}

CSdl mSdl;
//CEga mVideo;
CEga mEga;
CCga mCga;
CVga mVga;
CText mText;
CVideoAdapter* mVideo = &mEga;
int lastKey = -1;
char root[1024];
uint8_t mem[0xa0000];
extern unsigned char font[2048];
int headerSize = 0;
int loadAddress = 0;

std::list<char> keyBuffer;
int newkey = -1;

void _sync()
{
    for (int y=0; y<200; y++)
      for (int x=0; x<320; x++)
        mSdl.SetPixel(x, y, mVideo->GetPixel(x, y));
    mSdl.Loop();
}
static int keys = 0;

void syncKeyb()
{
    mSdl.Loop(true);
}
/*
void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
      switch (k)
      {
          case SDL_SCANCODE_2: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x3c) = p; break;
          case SDL_SCANCODE_3: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x3d) = p; break;
          case SDL_SCANCODE_4: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x3e) = p; break;
          case SDL_SCANCODE_5: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x3f) = p; break;
          case SDL_SCANCODE_6: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x40) = p; break;
          case SDL_SCANCODE_7: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x41) = p; break;
          case SDL_SCANCODE_UP: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'H') = p; break;
          case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'M') = p; break;
          case SDL_SCANCODE_DOWN: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'P') = p; break;
          case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0x1228, 0x4d44 + 'K') = p; break;
          case SDL_SCANCODE_SPACE: CicoContext::ctx->memory8(0x1228, 0x4d44 + 0x1c) = p; break;
          }
}*/
void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    CicoContext::ctx->memory8(0x8070, 0x8dc4) = p;
      //if (p)
          switch (k)
          {
                  
//              case SDL_SCANCODE_ESCAPE: keyBuffer.push_back(27); break;
//              case SDL_SCANCODE_RETURN: keyBuffer.push_back(13); break;

//              case SDL_SCANCODE_SPACE: lastKey = 57;
//                  CicoContext::ctx->memory8(0x1ed, 0x03a1) = p;
//                  break;
//              case SDL_SCANCODE_LEFT:
//                 //a57:9c8 = 2|0xfffe, a57:9ca = 0/2
//                  keyBuffer.push_back(0);
//                  keyBuffer.push_back('M'); break;
//              case SDL_SCANCODE_RIGHT:
//                  keyBuffer.push_back(0);
//                  keyBuffer.push_back('K'); break;
//              case SDL_SCANCODE_UP:
//                  keyBuffer.push_back(0);
//                  keyBuffer.push_back('H'); break;
//              case SDL_SCANCODE_DOWN:
//                  keyBuffer.push_back(0);
//                  keyBuffer.push_back('P'); break;
                   
                  //0x0386 pause/*
              case SDL_SCANCODE_UP: CicoContext::ctx->memory8(0x1f86, 0x8db4) = p; break; // u
              case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0x1f86, 0x8da6) = p; break; // r
              case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0x1f86, 0x8baf) = p; break;// l
              case SDL_SCANCODE_SPACE: CicoContext::ctx->memory8(0x1f86, 0x92b5) = p; break;
              case SDL_SCANCODE_DOWN: CicoContext::ctx->memory8(0x1f86, 0x92b6) = p; break;

              case SDL_SCANCODE_1: CicoContext::ctx->memory8(0x1f86, 0x8b95) = p; break;
              case SDL_SCANCODE_2: CicoContext::ctx->memory8(0x1f86, 0x8ba8) = p; break;
              case SDL_SCANCODE_3: CicoContext::ctx->memory8(0x1f86, 0x8b94) = p; break;
              case SDL_SCANCODE_4: CicoContext::ctx->memory8(0x1f86, 0x8d9e) = p; break;

              case SDL_SCANCODE_5: CicoContext::ctx->memory8(0x1f86, 0x8da7) = p; break;
              case SDL_SCANCODE_6: CicoContext::ctx->memory8(0x1f86, 0x8b6a) = p; break;
              case SDL_SCANCODE_7: CicoContext::ctx->memory8(0x1f86, 0x8b94) = p; break;
              case SDL_SCANCODE_8: CicoContext::ctx->memory8(0x1f86, 0x919c) = p; break;

                             
                  /*
                   memoryASet(ds, 0x8b95, al);
                   memoryASet(ds, 0x8ba8, al);
                   memoryASet(ds, 0x8b94, al);
                   memoryASet(ds, 0x8d9e, al);
                   
                   memoryASet(ds, 0x92b5, al);
                   memoryASet(ds, 0x92b6, al);
                   memoryASet(ds, 0x8db4, al);
                   
                   memoryASet(ds, 0x8da6, al);
                   memoryASet(ds, 0x8baf, al);
                   */
              //case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0x1ed, 0x39a) = p; break;
              //case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0x1ed, 0x39c) = p; break;
              //case SDL_SCANCODE_UP: CicoContext::ctx->memory8(0x1ed, 0x388) = p; break;
              //case SDL_SCANCODE_DOWN: CicoContext::ctx->memory8(0x1ed, 0x39e) = p; break;
                  //case SDL_SCANCODE
                  /*
              case SDL_SCANCODE_1:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x2) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x3) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x4) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x5) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x6) = p;
                  break;
              case SDL_SCANCODE_2:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x7) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x8) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x9) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xa) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xb) = p;
                  break;
              case SDL_SCANCODE_3:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xc) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xd) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xe) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xf) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x10) = p;
                  break;
              case SDL_SCANCODE_4:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x11) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x12) = p;
//                  CicoContext::ctx->memory16(0x1ed, 0x387+0x13) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x14) = p;
//                  CicoContext::ctx->memory16(0x1ed, 0x387+0x15) = p;
                  break;
              case SDL_SCANCODE_5:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x16) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x17) = p;

                  break;
              case SDL_SCANCODE_6: CicoContext::ctx->memory16(0x1ed, 0x387+0x0) = p; break;
*/
          }
    
    
    
/*
    switch (k)
    {
        case SDL_SCANCODE_LEFT:
            CicoContext::ctx->memory16(0xa57, 0x9c8) = p ? -2 : 0;
            break;
        case SDL_SCANCODE_RIGHT:
            CicoContext::ctx->memory16(0xa57, 0x9c8) = p ? 2 : 0;
            break;
        case SDL_SCANCODE_UP:
            CicoContext::ctx->memory16(0xa57, 0x9c8+4) = p ? 1 : 0;
            break;
    }*/
}

uint8_t memoryBiosGet8(int seg, int ofs)
{
    if (seg == 0xffff && ofs == 0x000e)
        return 0xfc;
    if (seg == 0xf000 && ofs == 0xfffe)
        return 0xfc; // pc at
    if (seg == 0x0040 && ofs == 0x0087)
        return 0x00; // ega active
    if (seg == 0x0040 && ofs == 0x0088)
        return 0x09;
    if (seg == 0x0040 && ofs == 0x0017) // http://www.powernet.co.za/info/bios/mem/40_0017.htm
        return 0x00; // shift keys
    if (seg == 0xf000 && ofs >= 0xfa6e && ofs < (0xfa6e + sizeof(font)))
        return font[ofs-0xfa6e];
    if (seg == 0x0040 && ofs == 0x0010)
        return 0x26;
    if (seg == 0x0040 && ofs == 0x006c)
    {
        auto getTick = []() -> uint32_t {
            struct timespec ts;
            unsigned theTick = 0U;
            clock_gettime( CLOCK_REALTIME, &ts );
            theTick  = ts.tv_nsec / 1000000;
            theTick += ts.tv_sec * 1000;
            return theTick;
        };

        return getTick()/54; // 0xd1; // number of ticks since midnight 54ms
    }
    if (seg == 0x0000 && ofs == 0x0000)
        return 0x1a;
    if (seg == 0x0000 && ofs == 0x041a)
        return 0x00;
    if (seg == 0x0000 && ofs == 0x0484)
        return 40;
    assert(0);
    return 0;
}
uint8_t memoryPsp(int seg, int ofs)
{
    if (seg == 0x1d3)
    {
        const char env[] = "PATH=Z:\\" "\x00" "COMSPEC=Z:\\COMMAND.COM" "\x00"
          "BLASTER=A220 I7 D1 H5 T6" "\x00\x00\x01\x00" "C:\\PRE\\HISTORIK.EXE"
          "\x00\x00\x00\x00\x00\x00\x00";
        if (ofs<sizeof(env))
            return env[ofs];
        if (ofs<0xc0)
            return 0;
        
        assert(0);
        return 0;
    }
    if (seg == 0x1dd && ofs == 0x80)
        return 0;
    if (seg == 0x1dd && ofs == 0x81)
        return 0x0d;

    assert(0);
}
uint16_t memoryPsp16(int seg, int ofs)
{
    if (seg==0x1d3)
        return memoryPsp(seg, ofs) | (memoryPsp(seg, ofs+1)<<8);
    
    assert(seg == 0x1dd);
    // https://en.wikipedia.org/wiki/Program_Segment_Prefix
    switch (ofs)
    {
        case 0x02:
            //     Segment of the first byte beyond the memory allocated to the program
            return 0x9fff;
        case 0x2c:
            // Environment segment;
            return 0x1d3;
        default:
            assert(0);
            return 0;
    }
}
void memoryBiosSet8(int seg, int ofs, uint8_t v)
{
    printf("skip bios write %x:%x = %x\n", seg, ofs, v);
}
void memoryBiosSet16(int seg, int ofs, uint16_t v)
{
    printf("skip bios write %x:%x = %x\n", seg, ofs, v);
}

uint16_t memoryBiosGet16(int seg, int ofs)
{
    if (seg == 0x0040 && ofs == 0x006c) // timer
        return 0;
    if (seg == 0x0000 && ofs == 0x041a) // int?
        return 0;
    if (seg == 0x0040 && ofs == 0x0063) // int?
        return 0x3d4;
    if (seg == 0x0000 && ofs < 400)
        return 0;
    if (seg == 0x0040 && ofs == 0x0080)
        return 0x1e;
    assert(0);
    return 0;
}

namespace CicoContext
{

uint8_t cicocontext_t::memoryAGet8(int seg, int ofs)
{
    if (seg == 0xf000)
    {
        int f= 9 ;
    }
//    assert(seg >= 0x01ed && seg < 0xa000);
//    assert(ofs >= 0x0000 && ofs <= 0xffff);
    if (seg == 0x1fe8 && ofs ==4)
    {
        int f = 9;
    }
    ofs &= 0xffff;
    if ((seg == 0x01ed || seg == 0x01dd || seg == 0x01d3) && ofs < 256)
        return memoryPsp(seg, ofs);
    else
    if (seg >= loadAddress && seg < 0xa000)
        return memory8(seg, ofs);
    else if (seg >= 0xa000 && seg < 0xe000)
        return memoryVideoGet8(seg, ofs);
    else
        return memoryBiosGet8(seg, ofs); // bios
}
uint8_t cicocontext_t::memoryBiosGet8(int seg, int ofs)
{
    if ((seg == 0x01dd || seg == loadAddress || seg == 0x01d3) && ofs < 256)
        return ::memoryPsp(seg, ofs);
    return ::memoryBiosGet8(seg, ofs);
}
void cicocontext_t::memoryBiosSet8(int seg, int ofs, uint8_t val)
{
//    assert(0);
}
uint16_t cicocontext_t::memoryBiosGet16(int seg, int ofs)
{
    if ((seg == 0x01dd || seg == loadAddress || seg == 0x01d3) && ofs < 256)
        return ::memoryPsp16(seg, ofs);
    return ::memoryBiosGet16(seg, ofs);
}
void cicocontext_t::memoryBiosSet16(int seg, int ofs, uint16_t val)
{
    if ((seg == 0x01dd || seg == loadAddress) && ofs < 256)
        assert(0); // ???
    else
        ::memoryBiosSet16(seg, ofs, val);
}

uint16_t cicocontext_t::memoryAGet16(int seg, int ofs)
{
//    assert(seg >= 0x01ed && seg < 0xa000);
//    assert(ofs >= 0 && ofs <= 0xffff);
    ofs &= 0xffff;
    if ((seg == 0x01dd || seg == loadAddress || seg == 0x01d3) && ofs < 256)
        return memoryPsp16(seg, ofs);
    else if (seg >= loadAddress && seg < 0xa000)
        return memory16(seg, ofs);
    else if (seg >= 0xa000 && seg < 0xe000)
        return memoryVideoGet16(seg, ofs);
    else
        return memoryBiosGet16(seg, ofs);
        //assert(0); // bios
}

void cicocontext_t::memoryASet8(int seg, int ofs, uint8_t val)
{
    if (seg == 0x598b && ofs == 0x03d8)
    {
        int f = 9;
    }
//    assert (seg >= 0x01ed && seg < 0xa000);
//    assert(ofs >= 0 && ofs <= 0xffff);
    ofs &= 0xffff;
    if ((seg == 0x01dd || seg == loadAddress) && ofs < 256)
        assert(0);
    else if (seg >= loadAddress && seg < 0xa000)
        memory8(seg, ofs) = val;
    else if (seg >= 0xa000 && seg < 0xe000)
        memoryVideoSet8(seg, ofs, val);
    else
        memoryBiosSet8(seg, ofs, val);
}

void cicocontext_t::memoryASet16(int seg, int ofs, uint16_t val)
{
//    assert(seg >= 0x01ed && seg < 0xa000);
//    assert(ofs >= 0x0000 && ofs <= 0xffff);

    ofs &= 0xffff;

    if ((seg == 0x01dd || seg == 0x01ed) && ofs < 256)
    {
        printf("Skip set before app\n");
//        assert(0); // ???
    }
    else
    if (seg >= loadAddress && seg < 0xa000)
        memory16(seg, ofs) = val;
    else if (seg >= 0xa000 && seg < 0xe000)
        memoryVideoSet16(seg, ofs, val);
    else
        memoryBiosSet16(seg, ofs, val);
}

uint8_t& cicocontext_t::memory8(int seg, int ofs){
    if (seg*16+ofs == 0x1f860 + 0x9896)
    {
        int f = 9;//(0x1ed, 0x387+0x1)
    }
    assert(seg >= loadAddress && seg < 0xa000 && ofs >= 0 && ofs <= 0xffff);
    int addr = seg*16 + ofs;
    addr -= loadAddress*16 - headerSize;
    assert(addr > 0 && addr < sizeof(mem));
    if (mem[addr-6] == 'L' && mem[addr-5] == 'e' && mem[addr-4] == 'v' &
        mem[addr-3] == 'e' && mem[addr-2] == 'l' && mem[addr-1] == ' ')
    {
        int  f= 9;
    }
    return mem[addr];
}

uint16_t& cicocontext_t::memory16(int seg, int ofs){
    if (seg*16+ofs == 0x1f860 + 0x9896)
    {
        int f = 9;
    }
    assert(seg >= loadAddress && seg < 0xa000 && ofs >= 0 && ofs <= 0xffff);
    int addr = seg*16 + ofs;
    addr -= loadAddress*16 - headerSize;
    assert(addr > 0 && addr < sizeof(mem));
    return *(uint16_t*)&mem[addr];
}

uint8_t cicocontext_t::memoryVideoGet8(int seg, int ofs)
{
    return mVideo->Read(seg*16+ofs);
}

void cicocontext_t::memoryVideoSet8(int seg, int ofs, uint8_t data)
{
    mVideo->Write(seg*16+ofs, data);
}

uint16_t cicocontext_t::memoryVideoGet16(int seg, int ofs)
{
    return memoryVideoGet8(seg, ofs) | (memoryVideoGet8(seg, ofs+1) << 8);
}

void cicocontext_t::memoryVideoSet16(int seg, int ofs, uint16_t data)
{
    memoryVideoSet8(seg, ofs, data & 0xff);
    memoryVideoSet8(seg, ofs+1, data >> 8);
}

void cicocontext_t::_int(int i)
{
    static FILE* f = nullptr;
    static int curhandle = 5;
    if (i == 0x10 && ctx->a.r16 == 0x1012)
    {
        int f = 9;
    }
    if (i == 0x12)
    {
        ctx->a.r16 = 0x800;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x09)
    {
        for(int i=0; i<200; i++)
        {
            char c = ctx->memory8(ctx->_ds, ctx->d.r16+i);
            assert(c);
            if (c == '$')
            {
                fflush(stdout);
                return;
            }
            printf("%c", c);
        }
        assert(0);
    }

    if (i == 0x21 && ctx->a.r8.h == 0x3d)
    {
        // read file DS:DX filename
        // AX = file handle
        char filename[100];
        int j = 0;
        for (int i=0; i<100; i++)
        {
            char c = ctx->memory8(ctx->_ds, ctx->d.r16+i);
            if (!c)
                break;
            if (c >= 'a' && c <= 'z')
                c -= 'a' - 'A';
            if (c != ' ')
            {
                filename[j++] = c;
                filename[j] = 0;
            }
        }
        //curhandle++;
        printf("Opening %s as %x\n", filename, curhandle);
        //char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/binary/";
        char fullname[1024];
        strcpy(fullname, root);
        strcat(fullname, "/");
        strcat(fullname, filename);
        for (int i=0; i<128 && fullname[i]; i++)
            if (fullname[i] == '\\')
                fullname[i] = '/';
        
        ctx->carry = 0;
        assert(f == nullptr);
        ctx->a.r16 = curhandle;
        
        f = fopen(fullname, "rb");
        if(!f)
        {
            printf("Not found: %s\n", filename);
            assert(0);
            ctx->carry = 1;
            ctx->a.r16 = 0;
        }
        return;

    }
    if (i == 0x21 && ctx->a.r8.h == 0x3f)
    {
        // read file CX bytes => CS:DX
        assert(ctx->b.r16 == curhandle);
        if (!f)
        {
            printf("no file opened!\n");
            return;
        } else {
//            printf("Read %d bytes -> %04x:%04x\n", ctx->c.r16, ctx->_ds, ctx->d.r16);
            uint8_t* buf = new uint8_t[ctx->c.r16];
            int c = fread(buf, 1, (size_t)ctx->c.r16, f);
            if (ctx->_ds >= 0xa000)
            {
                //printf("cfg=%d\n", mEga.cfgDataRotate);
                int shift = (mEga.cfgReadMapSelect*8);
                uint32_t mask = ~(0xff << shift);
                for (int i=0; i<c; i++)
                    mEga.egamemory[ctx->d.r16+i] &= mask;
                for (int i=0; i<c; i++)
                    mEga.egamemory[ctx->d.r16+i] |= buf[i]<<shift;
                //ctx->memoryASet8(ctx->_ds+overlap, (ctx->d.r16+i)&65535, buf[i]);
            } else {
                for (int i=0; i<c; i++)
                {
                    // memory overlap!
                    int overlap = ((ctx->d.r16+i) >> 16) ? 0x1000 : 0;
                    ctx->memoryASet8(ctx->_ds+overlap, (ctx->d.r16+i)&65535, buf[i]);
                }
            }
            delete[] buf;
            //std::cout << "read " << _cx << " (" << c << ")" << endl;
//            assert(c);
            ctx->a.r16 = c;
            ctx->carry = 0;
            return;
        }
    }
    if (i == 0x21 && ctx->a.r8.h == 0x3e)
    {
        printf("Closing file %x!\n", ctx->b.r16);
        fclose(f);
        f = nullptr;
        ctx->carry = 0;
        return;
    }
    static int _videoMode = -1;
    if (i == 0x10 && ctx->a.r8.h == 0x00)
    {
        // set video mode
        printf("Set video mode: %x\n", ctx->a.r8.l);
        _videoMode = ctx->a.r8.l;
        switch (ctx->a.r8.l)
        {
            case 0x13:
                mVideo = &mVga; break;
            case 13:
            case 0x12:
            case 0x10:
            case 0x02: // 80x25 16 shades of gray text (CGA,EGA,MCGA,VGA)?

            case 1:
                mVideo = &mEga; break;
            case 4:
                mVideo = &mCga; break;
            case 3: // exit
                mVideo = &mText;
                break;
            default:
                assert(0);
        }
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x25)
    {
        // set int vect AL DS:DX
        printf("Set int vector - ignore al=%02x to %04x:%04x\n", ctx->a.r8.l, ctx->_ds, ctx->d.r16);
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x35)
    {
        printf("Get int vector - ignore\n");
        ctx->_es = 0;
        ctx->b.r16 = 0;
        
        ctx->b.r16 = 0x1060;
        ctx->_es = 0xf000;
        return;
    }
    if (i == 0x33)
    {
        // mouse
        ctx->a.r16 = -1;
        ctx->b.r16 = 3;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x3c)
    {
        // create file
        ctx->carry = true;
        return;
    }
    //static int lastKey = -1;
    if (i == 0x16 && ctx->a.r8.h == 0x00)
    {
        while (lastKey == -1)
            sync();
            
        // wait for keystroke!
        ctx->a.r16 = lastKey;
        lastKey = -1;
        return;
    }
    if (i == 0x16 && ctx->a.r8.h == 0x01)
    {
        ctx->zero = lastKey == -1;
        return;
    }
    if (i == 0x10 && ctx->a.r8.h == 0x06)
        return;
    if (i == 0x21 && ctx->a.r8.h == 0x4a)
    {
        ctx->carry = false;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x48)
    {
        static int freeMem = 0x1D9E;
        // _bx size
        printf("malloc %d bytes -> %04x:0000\n", ctx->b.r16, freeMem);
        ctx->a.r16 = freeMem;
        freeMem += ctx->b.r16;
        freeMem ++;
        ctx->carry = false;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x40)
    {
        for (int j=0; j<ctx->c.r16; j++)
            printf("%c", ctx->memory8(ctx->_ds, ctx->d.r16 + j));
        ctx->carry = false;
        ctx->a.r16 = ctx->c.r16;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x3e)
        return;
    if (i == 0x21 && ctx->a.r8.h == 0x49)
        return;
    if (i == 0x21 && ctx->a.r8.h == 0x0a)
    {
        memory8(ctx->_ds, ctx->d.r16) = 'n';
        return;
    }
    if (i == 0x10 && ctx->a.r8.h == 0x0f)
    {
        if (_videoMode==-1)
        {
            ctx->a.r16 = 0x5003;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x12)
        {
            ctx->a.r16 = 0x5012;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x13)
        {
            ctx->a.r16 = 0x2813;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x10)
        {
            ctx->a.r16 = 0x5010;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x4)
        {
            ctx->a.r16 = 0x2804;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0xd)
        {
            ctx->a.r16 = 0x280d;
            ctx->b.r8.h = 0x00;
            return;
        }
        assert(0);
    }
    if (i == 0x10 && ctx->a.r8.h == 0x1a)
    {
        //https://dos4gw.org/INT_10H_1aH_Set_or_Query_Display_Combination_Code
        ctx->a.r8.l = 0x1a;
        ctx->b.r8.l = 0x08; // vga color
        return;
        
    }
    if (i == 0x10 && ctx->a.r8.h == 0x10 && ctx->a.r8.l == 0)
    {
        //cout << hex << "\nset text palette[" << (int)_bl << "] = " << (int)_bh << endl;
        printf("palette [%x] <- %x\n", ctx->b.r8.l, ctx->b.r8.h);
        mEga.SetPaletteIndex(ctx->b.r8.l, ctx->b.r8.h);
        return;
    }
    if (i == 0x10 && ctx->a.r16 == 0x1012)
    {
       // mEga.Interrupt(ctx);
        return;
    }
    if (i == 0x10 && ctx->a.r16 == 0x1200 && ctx->b.r8.l == 0x10)
    {
        ctx->b.r16 = 0x0003;
        return;
    }
    if (i == 0x10 && ctx->a.r8.h == 0x0e)
    {
        printf("%c", ctx->a.r8.l);
        return;
    }
    if (i == 0x10 && mVideo)
    {
        if (mVideo->Interrupt(ctx))
            return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x2c)
    {
        printf("get time\n");
        ctx->c.r8.h = 1; // hr
        ctx->c.r8.l = 20; // min
        ctx->d.r8.h = 17; // sec
        ctx->d.r8.l = 50; // hundredths
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x44)
    {
        ctx->a.r16 = 2; //ctx->a.r16 = 0x80d3;
        ctx->d.r16 = 2; //ctx->d.r16 = 0x80d3;
        ctx->carry = 0;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x30)
    {
        ctx->a.r16 = 0x0005;
        ctx->b.r16 = 0xff00;
        ctx->c.r16 = 0x0000;
        return;
    }
    if (i == 0x1A)
    {
        auto getTick = []() -> uint32_t {
            struct timespec ts;
            unsigned theTick = 0U;
            clock_gettime( CLOCK_REALTIME, &ts );
            theTick  = ts.tv_nsec / 1000000;
            theTick += ts.tv_sec * 1000;
            return theTick;
        };

        static uint32_t base = 0;
        int now = getTick();
        if (ctx->a.r8.h == 4)
        {
            
        }
        else if (ctx->a.r8.h == 0)
        {
            if (base == 0)
                base = now;
            now -= base;
            now = now /6; //* 65536 / (1000*60*60);
            ctx->c.r16 = now >> 16;
            ctx->d.r16 = now & 0xffff;
        } else {
            assert(ctx->a.r8.h == 1 && ctx->c.r16 == 0 && ctx->d.r16 == 0);
            base = now;
        }
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x42)
    {
        if (ctx->a.r8.l == 2 && ctx->c.r16 == 0 && ctx->d.r16 == 0)
        {
            assert(f);
            fseek(f, 0L, SEEK_END);
            ctx->a.r16 = ftell(f);
            fseek(f, 0L, SEEK_SET);
            ctx->d.r16 = 0;
            return;
        }
        if (ctx->a.r8.l == 0)
        {
            assert(f);
            fseek(f, ctx->c.r16*0x10000 + ctx->d.r16, SEEK_SET);
            ctx->carry = false;
            return;
        }

    }
    if (i == 0x21 && ctx->a.r8.h == 0x0b)
    {
        ctx->a.r8.l = keyBuffer.empty() ? 0 : 0xff; // check key
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x07)
    {
        ctx->a.r8.l = keyBuffer.front(); // key stdin
        keyBuffer.pop_front();
        return;
    }
    if (i == 0x11)
    {
        ctx->a.r16 = 0;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x42)
    {
        if (ctx->a.r8.l == 2 && ctx->c.r16 == 0 && ctx->d.r16 == 0)
        {
            assert(f);
            fseek(f, 0L, SEEK_END);
            ctx->a.r16 = ftell(f);
            fseek(f, 0L, SEEK_SET);
            ctx->d.r16 = 0;
            return;
        }
        if (ctx->a.r8.l == 1)
        {
            assert(ctx->c.r16 == 0);
            assert(f);
            fseek(f, ctx->d.r16, SEEK_CUR);
            ctx->d.r16 = ftell(f);
            ctx->a.r16 = 0;
            return;
        }
        if (ctx->a.r8.l == 1 && ctx->d.r16 == 0)
        {
            assert(f);
            fseek(f, ctx->c.r16, SEEK_CUR);
            return;
        }
        /*
        if (ctx->a.r8.l == 0)
        {
            assert(f);
            fseek(f, ctx->d.r16, SEEK_SET);
            return;
        }*/

    }
    if (i == 0x21 && ctx->a.r8.h == 0x19)
    {
        ctx->a.r8.l = 0x02;
        return;
    }
    if (i == 0x15 && ctx->a.r8.h == 0x06)
    {
        //wtf?
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x43)
    {
        // read file DS:DX filename
        // AX = file handle
        char filename[100];
        for (int i=0; i<100; i++)
        {
            char c = ctx->memory8(ctx->_ds, ctx->d.r16+i);
            if (!c)
                break;
            if (c >= 'a' && c <= 'z')
                c -= 'a' - 'A';
            filename[i] = c;
            filename[i+1] = 0;
        }
        printf("GetAttribute %s\n", filename);
        ctx->c.r16 = 1<<5;
        return;
    }

    if (i == 0x10 && ctx->a.r16 == 0x1015)
    {
        // read dac @ bx, ch, cl, dh
        return;
    }
    if (i == 0x21  && ctx->a.r8.h == 0x4c)
    {
        printf("Terminate app\n");
        exit(0);
    }
    printf("int %d\n", i);
    assert(0);
}
void cicocontext_t::out(int port, uint16_t val)
{
//    printf("port16 write %x = %x\n", port, val);
    if (mVideo->PortWrite16(port, val))
    {
        return;
    }
    printf("skip write %x, %x\n", port, val);
}
void cicocontext_t::out(int port, uint8_t val)
{
//    printf("port8 write %x = %x\n", port, val);

    if (port == 0x3c8)
    {
        int f = 9;
    }
    if (mVideo->PortWrite8(port, val))
    {
        return;
    }
    printf("skip write %x, %x\n", port, val);
}

void cicocontext_t::in(uint8_t& val, int port)
{
    if (port == 0x3da)
    {
        static int retrace = 0;
        retrace++;
        val = (retrace & 1) ? 9 : 0;
        return;
    }
    if (port == 0x201)
    {
//        printf("joystick skip\n");
        val = 0;
        return;
    }
    if (port == 0x61)
    {
        printf("timer skip\n");
        return;
    }
    if (port == 0x3c9)
    {
        if (mVga.PortRead8(port, val))
            return;
    }
    if (port == 0x388) //audio
    {
        val = 0x60;
        return;
    }
    if (port == 0x3b5) //mono
    {
        val = 0xff;
        return;
    }
    if (port == 0x301)
    {
        val = 0xff;
        //?
        return;
    }
    if (port == 0x331)
    {
        val = 0xbf;
        //?
        return;
    }
    if (port == 0x40)
    {
        static int counter = 0;
        val = (counter++ & 2) ? 0xff:0x00;
        return;
    }

    if (port == 0x3d4 || port == 0x3d5)
    {
        val = mVideo->PortRead8(port);
        return;
    }

    assert(0);
}

void cicocontext_t::push(const uint16_t& r)
{
    assert (ctx->_sp > 20);
    ctx->_sp -= 2;
    memory16(ctx->_ss, ctx->_sp) = r;
    assert(ctx->_sp > 0);
}
int checksp = -1;
uint16_t cicocontext_t::pop(void)
{
    assert(ctx->_sp <= 0xffff);
    uint16_t aux = memory16(ctx->_ss, ctx->_sp);
    if (checksp)
    {
        if (aux == checksp)
        {
            int f = 9;
        }
        
    }
    ctx->_sp += 2;
    return aux;
}
void cicocontext_t::push(const int& r)
{
    assert(r >= 0 && r <= 0xffff);
    ctx->_sp -= 2;
    memory16(ctx->_ss, ctx->_sp) = r;
}
//void cicocontext_t::pop(int& r)
//{
//    ctx->_sp += 2;
//    r = memory16(ctx->_ss, ctx->_sp);
//}
bool cicocontext_t::stop(const char* msg)
{
    assert(0);
    return false;
}

void cicocontext_t::cbw()
{
    ctx->a.r8.h = (ctx->a.r8.l & 0x80) ? 0xff : 0;
}
void cicocontext_t::div(uint16_t r)
{
    uint16_t result = ctx->a.r16 / r;
    uint16_t remain = ctx->a.r16 % r;
    ctx->a.r16 = result;
    ctx->d.r16 = remain;
}
void cicocontext_t::div(uint8_t r)
{
    uint16_t result = ctx->a.r16 / r;
    uint16_t remain = ctx->a.r16 % r;
    ctx->a.r8.l = result;
    ctx->a.r8.h = remain;
}
void cicocontext_t::daa()
{
    // TODO: set carry before!
    int oldcf = ctx->carry;
    if ((ctx->a.r8.l & 0xf) > 9)
    {
        ctx->a.r8.l += 6;
        ctx->carry = ctx->a.r8.l < 6;
    }
    if ((ctx->a.r8.l > 0x99) || oldcf)
    {
        ctx->a.r8.l += 0x60;
        ctx->carry = true;
    } else {
        ctx->carry = false;
    }
}

}

void sub_bb32();
void sub_c91e();
void sub_df4f();
void sub_fb7f();
void sub_c27e();
void sub_f9c4();
void sub_e600();
void sub_e2e4();
void sub_ca60();
void sub_ca8b();
void sub_12245();
void sub_d016();
void sub_d080();
void sub_d0d7();
void sub_d500();
void sub_d530();
void sub_d250();
void sub_d283();
void sub_dac0();
void sub_dae7();
void sub_fbb9();
void sub_fdcd();
void sub_e067();
void sub_fe71();
void sub_d810();
void sub_d840();
void sub_d593();
void sub_8fe1();
void sub_85e7();
void sub_841e();
void sub_8457();
void sub_84cb();
void sub_47c9();
void sub_4286();
void sub_42f3();
void sub_4340();
void sub_435e();
void sub_8518();
void sub_85a8();
void sub_8242();
void sub_8405();
void sub_84b5();
void sub_84f7();
void sub_8569();
void sub_84e1();
void sub_81f6();
void sub_83ec();
void sub_81f6();

void sub_860a();
void sub_83b2();
void sub_83cf();
void sub_3d0d();
void sub_834e();
void sub_8659();
void sub_8618();
void sub_84a2();
void sub_880a();
void sub_82dc();
void sub_87ce();


void sub_d37f();
void sub_d65d();
void sub_d665();
void sub_4191();
void sub_4180();
void sub_81d5();
void sub_447d();
void sub_6c8f();
void sub_6f29();
void sub_6d99();
void sub_6e1e();
void sub_6f3f();
void sub_41a2();
void sub_6ef5();
void sub_6f0f();
void sub_6d14();
void sub_3d2e();
void sub_8391();
void sub_86e3();
void sub_40b7();
void sub_86cb();
void sub_46e0();
void sub_3d60();
void sub_6214();
void sub_6307();
void sub_43a7();
void sub_86b2();
void sub_4008();
void sub_8702();
void sub_871b();
void sub_87b6();
void sub_87f2();
void sub_8760();
void sub_878b();
void sub_832d();
void sub_869a();
void sub_43da();

void sub_3d92();
void sub_3e0e();
/*
 // 11d7a-11dfa, 80 b, 40 w
 {
     bool tmp[65536] = {0};
     for (int i=0; i<40; i++)
     {
         int adr =memoryAGet16(ds, 1994+i*2);
         if (tmp[adr])
             continue;
         tmp[adr] =1;
         printf("case 0x%x: sub_%x(); break; // %04x:%04x\n",
                cs*16+adr, cs*16+adr, cs, adr);
     }
 }
 printf("%02x %02x %02x %02x  %02x %02x %02x %02x\n",
        memoryAGet(ds, 1994), memoryAGet(ds, 1994+1),
        memoryAGet(ds, 1994+2), memoryAGet(ds, 1994+3),
        memoryAGet(ds, 1994+4), memoryAGet(ds, 1994+5),
        memoryAGet(ds, 1994+6), memoryAGet(ds, 1994+7));

 */

void sub_bb32();
void sub_c91e();
void sub_df4f();
void sub_fb7f();
void sub_c27e();
void sub_f9c4();
void sub_e600();
void sub_e2e4();
void sub_ca60();
void sub_ca8b();
void sub_12245();
void sub_d016();
void sub_d080();
void sub_d0d7();
void sub_d500();
void sub_d530();
void sub_d250();
void sub_d283();
void sub_dac0();
void sub_dae7();
void sub_fbb9();
void sub_fdcd();

void sub_204d();
void sub_5d62();
void sub_8e60();
void sub_9032();
void sub_43e0();
void sub_45b7();
void sub_9082();
void sub_4611();
void sub_4862();
void sub_4778();
void sub_8edf();
void sub_4430();
void sub_8f3c();
void sub_4677();
void sub_90d3();
void sub_4666();
void sub_86d9();
void sub_90e2();
void sub_44c3();
void sub_8fb6();
void sub_9112();
void sub_47b2();
void sub_9028();
void sub_8ed9();
void sub_444c();
void sub_8fa0(); // 08e6:0140
void sub_4bde();
void sub_4bd1();
void sub_4918();
void sub_8f74();
void sub_4464();
void sub_4918();
void sub_4628();
void sub_8f86();
void sub_4693();
void sub_4928();
void sub_9014();
void sub_473c();
void sub_8fa9();
void sub_43f0();

void sub_201a();
void sub_2021();

void CicoContext::cicocontext_t::callIndirect(int s, int o)
{
#if 0
    int a = s*16+o;
#if 1
    printf("Skipping indirect=%04x:%04x 'case 0x%x: sub_%x(); return;'\n", CicoContext::ctx->_cs, a - CicoContext::ctx->_cs*16, a, a);
/// 2956:21d8 int 33
    switch (a)
    {
        case 0x201a: sub_201a(); return;
        case 0x2021: sub_2021(); return;
        case 0x2b748:
            CicoContext::ctx->_int(0x10);
            CicoContext::ctx->_cs = CicoContext::ctx->pop();
            return;
        case 0x2b73c:
            CicoContext::ctx->_int(0x15);
            CicoContext::ctx->_cs = CicoContext::ctx->pop();
            return;
    }
    //01ed:1e90,01ed:64c1,01ed:1e5e,01ed:4344,01ed:5025
//    Skipping indirect=01ed:1e90
//    Skipping indirect=01ed:64c1x
//    sync();
    //kipping indirect=01ed:1e5e
    //kipping indirect=01ed:1e5e
    //Skipping indirect=01ed:4344
    //Skipping indirect=01ed:5025
    //Skipping indirect=01ed:1e90
    //=01ed:2810
    /*
    switch (a)
    {
        case 0x8518: sub_8518(); return; // 01ed:6648
        case 0x8fe1: sub_8fe1(); return; // 01ed:7111
        case 0x85e7: sub_85e7(); return; // 01ed:6717
        case 0x841e: sub_841e(); return; // 01ed:654e
        case 0x8457: sub_8457(); return; // 01ed:6587
        case 0x84cb: sub_84cb(); return; // 01ed:65fb
        case 0x8569: sub_8569(); return; // 01ed:6699
        case 0x81f6: sub_81f6(); return; // 01ed:6326
        case 0x83ec: sub_83ec(); return; // 01ed:651c
        case 0x84b5: sub_84b5(); return; // 01ed:65e5
        case 0x84f7: sub_84f7(); return; // 01ed:6627
        case 0x85a8: sub_85a8(); return; // 01ed:66d8
        case 0x8242: sub_8242(); return; // 01ed:6372
        case 0x8405: sub_8405(); return; // 01ed:6535
        case 0x860a: sub_860a(); return; // 01ed:673a
        case 0x83b2: sub_83b2(); return; // 01ed:64e2
        case 0x84e1: sub_84e1(); return; // 01ed:6611
        case 0x83cf: sub_83cf(); return; // 01ed:64ff
        case 0x834e: sub_834e(); return; // 01ed:647e
        case 0x8618: sub_8618(); return; // 01ed:6748
        case 0x8659: sub_8659(); return; // 01ed:6789
        case 0x81d5: sub_81d5(); return; // 01ed:6305
        case 0x82dc: sub_82dc(); return; // 01ed:640c
        case 0x832d: sub_832d(); return; // 01ed:645d
        case 0x84a2: sub_84a2(); return; // 01ed:65d2
        case 0x87ce: sub_87ce(); return; // 01ed:68fe
        case 0x880a: sub_880a(); return; // 01ed:693a
        case 0x8391: sub_8391(); return; // 01ed:64c1
        case 0x86b2: sub_86b2(); return; // 01ed:67e2
        case 0x86e3: sub_86e3(); return; // 01ed:6813
        case 0x869a: sub_869a(); return; // 01ed:67ca
        case 0x86cb: sub_86cb(); return; // 01ed:67fb
        case 0x8702: sub_8702(); return; // 01ed:6832
        case 0x871b: sub_871b(); return; // 01ed:684b
        case 0x87b6: sub_87b6(); return; // 01ed:68e6
        case 0x87f2: sub_87f2(); return; // 01ed:6922
        case 0x8760: sub_8760(); return; // 01ed:6890
        case 0x878b: sub_878b(); return; // 01ed:68bb
            
            // sub_3cd2
        case 0x47c9: sub_47c9(); return; // 01ed:28f9
        case 0x4286: sub_4286(); return; // 01ed:23b6
        case 0x42f3: sub_42f3(); return; // 01ed:2423
        case 0x4340: sub_4340(); return; // 01ed:2470
        case 0x435e: sub_435e(); return; // 01ed:248e
        case 0x43a7: sub_43a7(); return; // 01ed:24d7
        case 0x43da: sub_43da(); return; // 01ed:250a
        case 0x447d: sub_447d(); return; // 01ed:25ad
        case 0x4180: sub_4180(); return; // 01ed:22b0
        case 0x6214: sub_6214(); return; // 01ed:4344
        case 0x6307: sub_6307(); return; // 01ed:4437
        case 0x3d2e: sub_3d2e(); return; // 01ed:1e5e
        case 0x3d60: sub_3d60(); return; // 01ed:1e90
        case 0x3d92: sub_3d92(); return; // 01ed:1ec2
        case 0x3e0e: sub_3e0e(); return; // 01ed:1f3e
        case 0x4008: sub_4008(); return; // 01ed:2138
        case 0x40b7: sub_40b7(); return; // 01ed:21e7
    }
    //if (a != 0x12245 && a != 0xfbb9)
    //if (a != 0xd500 && a != 0xd530 && a != 0xd810 && a != 0xd840)
    //    printf("indi %x\n", a);
    switch (a)
    {
        case 0xbb32: sub_bb32(); return;
        case 0xc91e: sub_c91e(); return;
        case 0xdf4f: sub_df4f(); return;
        case 0xfb7f: sub_fb7f(); return;
        case 0xc27e: sub_c27e(); return;
        case 0xf9c4: sub_f9c4(); return;
        case 0xe600: sub_e600(); return;
        case 0xe2e4: sub_e2e4(); return;
        case 0xca60: sub_ca60(); return;
        case 0xca8b: sub_ca8b(); return;
        case 0x12245: sub_12245(); return;
        case 0xd016: sub_d016(); return;
        case 0xd080: sub_d080(); return;
        case 0xd0d7: sub_d0d7(); return;
        case 0xd500: sub_d500(); return;
        case 0xd530: sub_d530(); return;
        case 0xd250: sub_d250(); return;
        case 0xd283: sub_d283(); return;
        case 0xdac0: sub_dac0(); return;
        case 0xdae7: sub_dae7(); return;
        case 0xfbb9: sub_fbb9(); return;
        case 0xfdcd: sub_fdcd(); return;
        case 0xe067: sub_e067(); return;
        case 0xfe71: sub_fe71(); return;
        case 0xd810: sub_d810(); return;
        case 0xd840: sub_d840(); return;
        case 0xd593: sub_d593(); return;
                        
        case 0x3d0d: sub_3d0d(); return;
        case 0xd37f: sub_d37f(); return;
        case 0xd65d: sub_d65d(); return;
        case 0xd665: sub_d665(); return;
        case 0x4191: sub_4191(); return;
//        case 0x81d5: sub_81d5(); return;
        case 0x6c8f: sub_6c8f(); return;
        case 0x6f29: sub_6f29(); return;
        case 0x6d99: sub_6d99(); return;
        case 0x6f3f: sub_6f3f(); return;
        case 0x6e1e: sub_6e1e(); return;
        case 0x41a2: sub_41a2(); return;
        case 0x6ef5: sub_6ef5(); return;
            
        case 0x6f0f: sub_6f0f(); return;
        case 0x6d14: sub_6d14(); return;
        case 0x46e0: sub_46e0(); return;
     */
    
    /*av
    switch (a) {
case 0x204d: sub_204d(); return;
case 0x5d62: sub_5d62(); return;
case 0x402e: return;
case 0x8e60: sub_8e60(); return;
case 0x9032: sub_9032(); return;
case 0x43e0: sub_43e0(); return;
case 0x45b7: sub_45b7(); return;
case 0x9082: sub_9082(); return;
case 0x4611: sub_4611(); return;
case 0x4862: sub_4862(); return;
case 0x4778: sub_4778(); return;
case 0x8edf: sub_8edf(); return;
case 0x4430: sub_4430(); return;
case 0x8f3c: sub_8f3c(); return;
case 0x4677: sub_4677(); return;
case 0x90d3: sub_90d3(); return;
case 0x4666: sub_4666(); return;
case 0x86d9: sub_86d9(); return;
case 0x90e2: sub_90e2(); return;
case 0x44c3: sub_44c3(); return;
case 0x8fb6: sub_8fb6(); return;
case 0x9112: sub_9112(); return;
case 0x47b2: sub_47b2(); return;
case 0x9028: sub_9028(); return;
case 0x8ed9: sub_8ed9(); return;
case 0x444c: sub_444c(); return;
case 0x8fa0: sub_8fa0(); return;
case 0x4bde: sub_4bde(); return;
case 0x4bd1: sub_4bd1(); return;
case 0x4918: sub_4918(); return;
case 0x8f74: sub_8f74(); return;
case 0x4464: sub_4464(); return;
case 0x1a50a: // mouse
    ctx->_cs = pop(); // retf
    ctx->a.r16 = 0xffff;
    ctx->b.r16 = 3;
    
    return; //0A57:0000FF9A int 33
case 0x4628: sub_4628(); return;
//        case 0xcbed: sub_1cbed(); return;
//        case 0xe5a1: sub_1e5a1(); return;
case 0x8f86: sub_8f86(); return;
case 0x4693: sub_4693(); return;
case 0x4928: sub_4928(); return;
case 0x9014: sub_9014(); return;
case 0x473c: sub_473c(); return;
case 0x8fa9: sub_8fa9(); return;
case 0x43f0: sub_43f0(); return;

        default:
            printf("Skipping indirect=%04x:%04x 'case 0x%x: sub_%x(); return;'\n", CicoContext::ctx->_cs, a - CicoContext::ctx->_cs*16, a, a);
            //assert(0);
    }
     */
    assert(0);
#endif
#endif
}

void CicoContext::cicocontext_t::cmc()
{
    ctx->carry = !ctx->carry;
}
void CicoContext::cicocontext_t::aaa()
{
    if ((ctx->a.r8.l & 0x0F) > 9 /*|| (r8[af] = 1)*/)
    {
        ctx->a.r8.l = (ctx->a.r8.l + 6) & 0x0f;
        ctx->a.r8.h ++;
        //af = 1;
        ctx->carry = 1;
    } else {
        ctx->carry = 0;
        //af = 0;
    }
}
namespace CicoContext {
void cicocontext_t::mul(uint8_t r)
{
    int v = r * ctx->a.r8.l;
    ctx->a.r16 = v & 0xffff;
}
void cicocontext_t::mul(uint16_t r)
{
    int v = r * ctx->a.r16;
    ctx->a.r16 = v & 0xffff;
    ctx->d.r16 = v >> 16;
}
void cicocontext_t::imul(uint16_t r)
{
    int v = (int16_t)ctx->a.r16 * (int16_t)r;
    ctx->a.r16 = v & 0xffff;
    ctx->d.r16 = v >> 16;
}
void cicocontext_t::imul(uint8_t r)
{
    int v = (char)r * (short)ctx->a.r16;
    ctx->a.r16 = v & 0xffff;
}
void cicocontext_t::idiv(uint16_t r)
{
    int32_t n = (ctx->d.r16 << 16) | ctx->a.r16;
    ctx->a.r16 = n / (int16_t)r;
    ctx->d.r16 = n % (int16_t)r;
}
void cicocontext_t::idiv(uint8_t r)
{
    int32_t dw = (ctx->d.r16 << 16) | ctx->a.r16;
    uint16_t result = dw / r;
    uint16_t remainder = dw % r;
    ctx->a.r16 = result;
    ctx->d.r16 = remainder;
}

uint8_t cicocontext_t::rcr(uint8_t r, int i)
{
    assert(i == 1);
    int newCarry = !!(r & 0x1);
    r >>= 1;
    r |= ctx->carry ? 0x80 : 0;
    ctx->carry = newCarry;
    return r;
}
uint8_t cicocontext_t::rcl(uint8_t r, int i)
{
    assert(i == 1);
    int newCarry = !!(r & 0x80);
    r <<= 1;
    r |= ctx->carry;
    ctx->carry = newCarry;
    return r;
}
uint16_t cicocontext_t::rcl(uint16_t r, int i)
{
    while (i > 0)
    {
        int newCarry = !!(r & 0x8000);
        r <<= 1;
        r |= ctx->carry ? 0x0001 : 0x0000;
        ctx->carry = newCarry;
        i--;
    }
    return r;
}
uint16_t cicocontext_t::rcr(uint16_t r, int i)
{
    while (i > 0)
    {
        int newCarry = !!(r & 0x0001);
        r >>= 1;
        r |= ctx->carry ? 0x8000 : 0x0000;
        ctx->carry = newCarry;
        i--;
    }
    return r;
}
template <typename INT>
INT _rol(INT val) {
    return (val << 1) | (val >> (sizeof(INT)*CHAR_BIT-1));
}

uint8_t cicocontext_t::rol(uint8_t r, int l)
{
    while (l--)
        r = _rol<uint8_t>(r);
    return r;
}
uint16_t cicocontext_t::rol(uint16_t r, int l)
{
    while (l--)
        r = _rol<uint16_t>(r);
    return r;
}
uint16_t cicocontext_t::sar(uint16_t a, uint8_t b)
{
    int16_t sa = (short)a;
    sa >>= b;
    return sa;
}
uint8_t cicocontext_t::sar(uint8_t a, uint8_t b)
{
    int8_t sa = (char)a;
    sa >>= b;
    return sa;
}

uint8_t cicocontext_t::ror(uint8_t r, int l)
{
    return (r >> l) | (r << (8-l));
}
uint16_t cicocontext_t::ror(uint16_t r, int l)
{
    return (r >> l) | (r << (16-l));
}
void cicocontext_t::sync(void)
{
    memory16(0x1f86, 0x8dd8)++;
    _sync();
}
void cicocontext_t::load(const char* path, const char* file, int size)
{
    char fpath[1024];
    sprintf(root, path);
    sprintf(fpath, "%s/%s", path, file);
    FILE* f = fopen(fpath, "rb");
    fread(mem, size, 1, f);
    fclose(f);
    headerSize = this->_headerSize;
    loadAddress = CicoContext::ctx->_cs;
}

}
void start();
int main(int argc, const char * argv[])
{
    CicoContext::ctx = new CicoContext::cicocontext_t();

    memset(mem, 0, sizeof(mem));

    mSdl.Init();
    start();
    mSdl.Deinit();
    return 0;
}


//#include "goose.cpp"


unsigned char font[2048] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x81, 0xa5, 0x81,
  0xbd, 0x99, 0x81, 0x7e, 0x7e, 0xff, 0xdb, 0xff, 0xc3, 0xe7, 0xff, 0x7e,
  0x6c, 0xfe, 0xfe, 0xfe, 0x7c, 0x38, 0x10, 0x00, 0x10, 0x38, 0x7c, 0xfe,
  0x7c, 0x38, 0x10, 0x00, 0x38, 0x7c, 0x38, 0xfe, 0xfe, 0x7c, 0x38, 0x7c,
  0x10, 0x10, 0x38, 0x7c, 0xfe, 0x7c, 0x38, 0x7c, 0x00, 0x00, 0x18, 0x3c,
  0x3c, 0x18, 0x00, 0x00, 0xff, 0xff, 0xe7, 0xc3, 0xc3, 0xe7, 0xff, 0xff,
  0x00, 0x3c, 0x66, 0x42, 0x42, 0x66, 0x3c, 0x00, 0xff, 0xc3, 0x99, 0xbd,
  0xbd, 0x99, 0xc3, 0xff, 0x0f, 0x07, 0x0f, 0x7d, 0xcc, 0xcc, 0xcc, 0x78,
  0x3c, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x7e, 0x18, 0x3f, 0x33, 0x3f, 0x30,
  0x30, 0x70, 0xf0, 0xe0, 0x7f, 0x63, 0x7f, 0x63, 0x63, 0x67, 0xe6, 0xc0,
  0x99, 0x5a, 0x3c, 0xe7, 0xe7, 0x3c, 0x5a, 0x99, 0x80, 0xe0, 0xf8, 0xfe,
  0xf8, 0xe0, 0x80, 0x00, 0x02, 0x0e, 0x3e, 0xfe, 0x3e, 0x0e, 0x02, 0x00,
  0x18, 0x3c, 0x7e, 0x18, 0x18, 0x7e, 0x3c, 0x18, 0x66, 0x66, 0x66, 0x66,
  0x66, 0x00, 0x66, 0x00, 0x7f, 0xdb, 0xdb, 0x7b, 0x1b, 0x1b, 0x1b, 0x00,
  0x3e, 0x63, 0x38, 0x6c, 0x6c, 0x38, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x00,
  0x7e, 0x7e, 0x7e, 0x00, 0x18, 0x3c, 0x7e, 0x18, 0x7e, 0x3c, 0x18, 0xff,
  0x18, 0x3c, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18,
  0x7e, 0x3c, 0x18, 0x00, 0x00, 0x18, 0x0c, 0xfe, 0x0c, 0x18, 0x00, 0x00,
  0x00, 0x30, 0x60, 0xfe, 0x60, 0x30, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0,
  0xc0, 0xfe, 0x00, 0x00, 0x00, 0x24, 0x66, 0xff, 0x66, 0x24, 0x00, 0x00,
  0x00, 0x18, 0x3c, 0x7e, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7e,
  0x3c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x30, 0x78, 0x78, 0x30, 0x30, 0x00, 0x30, 0x00, 0x6c, 0x6c, 0x6c, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x6c, 0x6c, 0xfe, 0x6c, 0xfe, 0x6c, 0x6c, 0x00,
  0x30, 0x7c, 0xc0, 0x78, 0x0c, 0xf8, 0x30, 0x00, 0x00, 0xc6, 0xcc, 0x18,
  0x30, 0x66, 0xc6, 0x00, 0x38, 0x6c, 0x38, 0x76, 0xdc, 0xcc, 0x76, 0x00,
  0x60, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x30, 0x60, 0x60,
  0x60, 0x30, 0x18, 0x00, 0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00,
  0x00, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x30, 0x30, 0xfc,
  0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60,
  0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x30, 0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00,
  0x7c, 0xc6, 0xce, 0xde, 0xf6, 0xe6, 0x7c, 0x00, 0x30, 0x70, 0x30, 0x30,
  0x30, 0x30, 0xfc, 0x00, 0x78, 0xcc, 0x0c, 0x38, 0x60, 0xcc, 0xfc, 0x00,
  0x78, 0xcc, 0x0c, 0x38, 0x0c, 0xcc, 0x78, 0x00, 0x1c, 0x3c, 0x6c, 0xcc,
  0xfe, 0x0c, 0x1e, 0x00, 0xfc, 0xc0, 0xf8, 0x0c, 0x0c, 0xcc, 0x78, 0x00,
  0x38, 0x60, 0xc0, 0xf8, 0xcc, 0xcc, 0x78, 0x00, 0xfc, 0xcc, 0x0c, 0x18,
  0x30, 0x30, 0x30, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0xcc, 0xcc, 0x78, 0x00,
  0x78, 0xcc, 0xcc, 0x7c, 0x0c, 0x18, 0x70, 0x00, 0x00, 0x30, 0x30, 0x00,
  0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x60,
  0x18, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x18, 0x00, 0x00, 0x00, 0xfc, 0x00,
  0x00, 0xfc, 0x00, 0x00, 0x60, 0x30, 0x18, 0x0c, 0x18, 0x30, 0x60, 0x00,
  0x78, 0xcc, 0x0c, 0x18, 0x30, 0x00, 0x30, 0x00, 0x7c, 0xc6, 0xde, 0xde,
  0xde, 0xc0, 0x78, 0x00, 0x30, 0x78, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0x00,
  0xfc, 0x66, 0x66, 0x7c, 0x66, 0x66, 0xfc, 0x00, 0x3c, 0x66, 0xc0, 0xc0,
  0xc0, 0x66, 0x3c, 0x00, 0xf8, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0xf8, 0x00,
  0xfe, 0x62, 0x68, 0x78, 0x68, 0x62, 0xfe, 0x00, 0xfe, 0x62, 0x68, 0x78,
  0x68, 0x60, 0xf0, 0x00, 0x3c, 0x66, 0xc0, 0xc0, 0xce, 0x66, 0x3e, 0x00,
  0xcc, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0xcc, 0x00, 0x78, 0x30, 0x30, 0x30,
  0x30, 0x30, 0x78, 0x00, 0x1e, 0x0c, 0x0c, 0x0c, 0xcc, 0xcc, 0x78, 0x00,
  0xe6, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0xe6, 0x00, 0xf0, 0x60, 0x60, 0x60,
  0x62, 0x66, 0xfe, 0x00, 0xc6, 0xee, 0xfe, 0xfe, 0xd6, 0xc6, 0xc6, 0x00,
  0xc6, 0xe6, 0xf6, 0xde, 0xce, 0xc6, 0xc6, 0x00, 0x38, 0x6c, 0xc6, 0xc6,
  0xc6, 0x6c, 0x38, 0x00, 0xfc, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0, 0x00,
  0x78, 0xcc, 0xcc, 0xcc, 0xdc, 0x78, 0x1c, 0x00, 0xfc, 0x66, 0x66, 0x7c,
  0x6c, 0x66, 0xe6, 0x00, 0x78, 0xcc, 0xe0, 0x70, 0x1c, 0xcc, 0x78, 0x00,
  0xfc, 0xb4, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xfc, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x00,
  0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00, 0xc6, 0xc6, 0x6c, 0x38,
  0x38, 0x6c, 0xc6, 0x00, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x30, 0x78, 0x00,
  0xfe, 0xc6, 0x8c, 0x18, 0x32, 0x66, 0xfe, 0x00, 0x78, 0x60, 0x60, 0x60,
  0x60, 0x60, 0x78, 0x00, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x02, 0x00,
  0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00, 0x10, 0x38, 0x6c, 0xc6,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
  0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x0c,
  0x7c, 0xcc, 0x76, 0x00, 0xe0, 0x60, 0x60, 0x7c, 0x66, 0x66, 0xdc, 0x00,
  0x00, 0x00, 0x78, 0xcc, 0xc0, 0xcc, 0x78, 0x00, 0x1c, 0x0c, 0x0c, 0x7c,
  0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00,
  0x38, 0x6c, 0x60, 0xf0, 0x60, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x76, 0xcc,
  0xcc, 0x7c, 0x0c, 0xf8, 0xe0, 0x60, 0x6c, 0x76, 0x66, 0x66, 0xe6, 0x00,
  0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00, 0x0c, 0x00, 0x0c, 0x0c,
  0x0c, 0xcc, 0xcc, 0x78, 0xe0, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0xe6, 0x00,
  0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 0x00, 0x00, 0xcc, 0xfe,
  0xfe, 0xd6, 0xc6, 0x00, 0x00, 0x00, 0xf8, 0xcc, 0xcc, 0xcc, 0xcc, 0x00,
  0x00, 0x00, 0x78, 0xcc, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0x00, 0xdc, 0x66,
  0x66, 0x7c, 0x60, 0xf0, 0x00, 0x00, 0x76, 0xcc, 0xcc, 0x7c, 0x0c, 0x1e,
  0x00, 0x00, 0xdc, 0x76, 0x66, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x7c, 0xc0,
  0x78, 0x0c, 0xf8, 0x00, 0x10, 0x30, 0x7c, 0x30, 0x30, 0x34, 0x18, 0x00,
  0x00, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0xcc, 0xcc,
  0xcc, 0x78, 0x30, 0x00, 0x00, 0x00, 0xc6, 0xd6, 0xfe, 0xfe, 0x6c, 0x00,
  0x00, 0x00, 0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00, 0xcc, 0xcc,
  0xcc, 0x7c, 0x0c, 0xf8, 0x00, 0x00, 0xfc, 0x98, 0x30, 0x64, 0xfc, 0x00,
  0x1c, 0x30, 0x30, 0xe0, 0x30, 0x30, 0x1c, 0x00, 0x18, 0x18, 0x18, 0x00,
  0x18, 0x18, 0x18, 0x00, 0xe0, 0x30, 0x30, 0x1c, 0x30, 0x30, 0xe0, 0x00,
  0x76, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x6c,
  0xc6, 0xc6, 0xfe, 0x00, 0x78, 0xcc, 0xc0, 0xcc, 0x78, 0x18, 0x0c, 0x78,
  0x00, 0xcc, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00, 0x1c, 0x00, 0x78, 0xcc,
  0xfc, 0xc0, 0x78, 0x00, 0x7e, 0xc3, 0x3c, 0x06, 0x3e, 0x66, 0x3f, 0x00,
  0xcc, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00, 0xe0, 0x00, 0x78, 0x0c,
  0x7c, 0xcc, 0x7e, 0x00, 0x30, 0x30, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00,
  0x00, 0x00, 0x78, 0xc0, 0xc0, 0x78, 0x0c, 0x38, 0x7e, 0xc3, 0x3c, 0x66,
  0x7e, 0x60, 0x3c, 0x00, 0xcc, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00,
  0xe0, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00, 0xcc, 0x00, 0x70, 0x30,
  0x30, 0x30, 0x78, 0x00, 0x7c, 0xc6, 0x38, 0x18, 0x18, 0x18, 0x3c, 0x00,
  0xe0, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00, 0xc6, 0x38, 0x6c, 0xc6,
  0xfe, 0xc6, 0xc6, 0x00, 0x30, 0x30, 0x00, 0x78, 0xcc, 0xfc, 0xcc, 0x00,
  0x1c, 0x00, 0xfc, 0x60, 0x78, 0x60, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0x0c,
  0x7f, 0xcc, 0x7f, 0x00, 0x3e, 0x6c, 0xcc, 0xfe, 0xcc, 0xcc, 0xce, 0x00,
  0x78, 0xcc, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0xcc, 0x00, 0x78,
  0xcc, 0xcc, 0x78, 0x00, 0x00, 0xe0, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00,
  0x78, 0xcc, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00, 0x00, 0xe0, 0x00, 0xcc,
  0xcc, 0xcc, 0x7e, 0x00, 0x00, 0xcc, 0x00, 0xcc, 0xcc, 0x7c, 0x0c, 0xf8,
  0xc3, 0x18, 0x3c, 0x66, 0x66, 0x3c, 0x18, 0x00, 0xcc, 0x00, 0xcc, 0xcc,
  0xcc, 0xcc, 0x78, 0x00, 0x18, 0x18, 0x7e, 0xc0, 0xc0, 0x7e, 0x18, 0x18,
  0x38, 0x6c, 0x64, 0xf0, 0x60, 0xe6, 0xfc, 0x00, 0xcc, 0xcc, 0x78, 0xfc,
  0x30, 0xfc, 0x30, 0x30, 0xf8, 0xcc, 0xcc, 0xfa, 0xc6, 0xcf, 0xc6, 0xc7,
  0x0e, 0x1b, 0x18, 0x3c, 0x18, 0x18, 0xd8, 0x70, 0x1c, 0x00, 0x78, 0x0c,
  0x7c, 0xcc, 0x7e, 0x00, 0x38, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00,
  0x00, 0x1c, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0x1c, 0x00, 0xcc,
  0xcc, 0xcc, 0x7e, 0x00, 0x00, 0xf8, 0x00, 0xf8, 0xcc, 0xcc, 0xcc, 0x00,
  0xfc, 0x00, 0xcc, 0xec, 0xfc, 0xdc, 0xcc, 0x00, 0x3c, 0x6c, 0x6c, 0x3e,
  0x00, 0x7e, 0x00, 0x00, 0x38, 0x6c, 0x6c, 0x38, 0x00, 0x7c, 0x00, 0x00,
  0x30, 0x00, 0x30, 0x60, 0xc0, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x00, 0xfc,
  0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x0c, 0x0c, 0x00, 0x00,
  0xc3, 0xc6, 0xcc, 0xde, 0x33, 0x66, 0xcc, 0x0f, 0xc3, 0xc6, 0xcc, 0xdb,
  0x37, 0x6f, 0xcf, 0x03, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00,
  0x00, 0x33, 0x66, 0xcc, 0x66, 0x33, 0x00, 0x00, 0x00, 0xcc, 0x66, 0x33,
  0x66, 0xcc, 0x00, 0x00, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88,
  0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0xdb, 0x77, 0xdb, 0xee,
  0xdb, 0x77, 0xdb, 0xee, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x18, 0xf8, 0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0x18,
  0xf8, 0x18, 0x18, 0x18, 0x36, 0x36, 0x36, 0x36, 0xf6, 0x36, 0x36, 0x36,
  0x00, 0x00, 0x00, 0x00, 0xfe, 0x36, 0x36, 0x36, 0x00, 0x00, 0xf8, 0x18,
  0xf8, 0x18, 0x18, 0x18, 0x36, 0x36, 0xf6, 0x06, 0xf6, 0x36, 0x36, 0x36,
  0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x00, 0x00, 0xfe, 0x06,
  0xf6, 0x36, 0x36, 0x36, 0x36, 0x36, 0xf6, 0x06, 0xfe, 0x00, 0x00, 0x00,
  0x36, 0x36, 0x36, 0x36, 0xfe, 0x00, 0x00, 0x00, 0x18, 0x18, 0xf8, 0x18,
  0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x18, 0x1f, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x18, 0x1f, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
  0xff, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0xff, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x1f, 0x18, 0x1f, 0x18, 0x18, 0x18, 0x36, 0x36, 0x36, 0x36,
  0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0x37, 0x30, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3f, 0x30, 0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0xf7, 0x00,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xf7, 0x36, 0x36, 0x36,
  0x36, 0x36, 0x37, 0x30, 0x37, 0x36, 0x36, 0x36, 0x00, 0x00, 0xff, 0x00,
  0xff, 0x00, 0x00, 0x00, 0x36, 0x36, 0xf7, 0x00, 0xf7, 0x36, 0x36, 0x36,
  0x18, 0x18, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00, 0x36, 0x36, 0x36, 0x36,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0x18, 0x18, 0x18,
  0x00, 0x00, 0x00, 0x00, 0xff, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  0x3f, 0x00, 0x00, 0x00, 0x18, 0x18, 0x1f, 0x18, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1f, 0x18, 0x1f, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x3f, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36,
  0x18, 0x18, 0xff, 0x18, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x18, 0x18, 0x18,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0xdc, 0xc8, 0xdc, 0x76, 0x00,
  0x00, 0x78, 0xcc, 0xf8, 0xcc, 0xf8, 0xc0, 0xc0, 0x00, 0xfc, 0xcc, 0xc0,
  0xc0, 0xc0, 0xc0, 0x00, 0x00, 0xfe, 0x6c, 0x6c, 0x6c, 0x6c, 0x6c, 0x00,
  0xfc, 0xcc, 0x60, 0x30, 0x60, 0xcc, 0xfc, 0x00, 0x00, 0x00, 0x7e, 0xd8,
  0xd8, 0xd8, 0x70, 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x7c, 0x60, 0xc0,
  0x00, 0x76, 0xdc, 0x18, 0x18, 0x18, 0x18, 0x00, 0xfc, 0x30, 0x78, 0xcc,
  0xcc, 0x78, 0x30, 0xfc, 0x38, 0x6c, 0xc6, 0xfe, 0xc6, 0x6c, 0x38, 0x00,
  0x38, 0x6c, 0xc6, 0xc6, 0x6c, 0x6c, 0xee, 0x00, 0x1c, 0x30, 0x18, 0x7c,
  0xcc, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x7e, 0xdb, 0xdb, 0x7e, 0x00, 0x00,
  0x06, 0x0c, 0x7e, 0xdb, 0xdb, 0x7e, 0x60, 0xc0, 0x38, 0x60, 0xc0, 0xf8,
  0xc0, 0x60, 0x38, 0x00, 0x78, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x00,
  0x00, 0xfc, 0x00, 0xfc, 0x00, 0xfc, 0x00, 0x00, 0x30, 0x30, 0xfc, 0x30,
  0x30, 0x00, 0xfc, 0x00, 0x60, 0x30, 0x18, 0x30, 0x60, 0x00, 0xfc, 0x00,
  0x18, 0x30, 0x60, 0x30, 0x18, 0x00, 0xfc, 0x00, 0x0e, 0x1b, 0x1b, 0x18,
  0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xd8, 0xd8, 0x70,
  0x30, 0x30, 0x00, 0xfc, 0x00, 0x30, 0x30, 0x00, 0x00, 0x76, 0xdc, 0x00,
  0x76, 0xdc, 0x00, 0x00, 0x38, 0x6c, 0x6c, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x0f, 0x0c, 0x0c, 0x0c, 0xec, 0x6c, 0x3c, 0x1c,
  0x78, 0x6c, 0x6c, 0x6c, 0x6c, 0x00, 0x00, 0x00, 0x70, 0x18, 0x30, 0x60,
  0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

