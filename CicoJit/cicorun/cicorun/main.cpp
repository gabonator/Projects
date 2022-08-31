#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "sdl.h"
#include "ega.h"
#define _HOST
#include "cicoemu.h"
CSdl mSdl;
CEga mVideo;

uint8_t mem[0x40000];

void _sync()
{
    for (int y=0; y<200; y++)
      for (int x=0; x<320; x++)
        mSdl.SetPixel(x, y, mVideo.GetPixel(x, y));
    mSdl.Loop();
}

void onKey(int k, int p)
{
#define MAPKEY( c, v ) if (k==c) CicoContext::ctx->memory8(0x13a5, 0x8e8a+v) = p
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
namespace CicoContext
{

uint8_t& cicocontext_t::memory8(int seg, int ofs){
    assert(seg >= 0x1000 && seg < 0xa000 && ofs >= 0 && ofs <= 0xffff);
    int addr = seg*16 + ofs;
    addr -= 0x10000 - 0x200;
    assert(addr > 0 && addr < sizeof(mem));
    return mem[addr];
}

uint16_t& cicocontext_t::memory16(int seg, int ofs){
    assert(seg >= 0x1000 && seg < 0xa000 && ofs >= 0 && ofs <= 0xffff);
    int addr = seg*16 + ofs;
    addr -= 0x10000 - 0x200;
    assert(addr > 0 && addr < sizeof(mem));
    return *(uint16_t*)&mem[addr];
}

uint8_t cicocontext_t::memoryVideoGet8(int seg, int ofs)
{
    return mVideo.Read(seg*16+ofs);
}

void cicocontext_t::memoryVideoSet8(int seg, int ofs, uint8_t data)
{
    mVideo.Write(seg*16+ofs, data);
}

uint16_t cicocontext_t::memoryVideoGet16(int seg, int ofs)
{
    assert(0);
    return 0;
}

void cicocontext_t::memoryVideoSet16(int seg, int ofs, uint16_t data)
{
    assert(0);
}

void cicocontext_t::_int(int i)
{
    static FILE* f = nullptr;
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
            if (c == '$')
                return;
            printf("%c", c);
        }
        assert(0);
    }

    if (i == 0x21 && ctx->a.r8.h == 0x3d)
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
        printf("Opening %s\n", filename);
        //char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/binary/";
        char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGoose/";
        strcat(fullname, filename);
        for (int i=0; i<128 && fullname[i]; i++)
            if (fullname[i] == '\\')
                fullname[i] = '/';
        
        ctx->carry = 0;
        assert(f == nullptr);
        ctx->a.r16 = 1;
        
        f = fopen(fullname, "rb");
        if(!f)
        {
            printf("Not found: %s\n", filename);
            ctx->carry = 1;
            ctx->a.r16 = 0;
        }
        return;

    }
    if (i == 0x21 && ctx->a.r8.h == 0x3f)
    {
        // read file CX bytes => CS:DX
        assert(f);
        uint8_t* buf = new uint8_t[ctx->c.r16];
        int c = fread(buf, 1, (size_t)ctx->c.r16, f);
        for (int i=0; i<ctx->c.r16; i++)
            ctx->memory8(ctx->_ds, ctx->d.r16+i) = buf[i];
        delete[] buf;
        //std::cout << "read " << _cx << " (" << c << ")" << endl;
        assert(c);
        ctx->carry = 0;
        return;

    }
    if (i == 0x21 && ctx->a.r8.h == 0x3e)
    {
        fclose(f);
        f = nullptr;
        ctx->carry = 0;
        return;
    }
    if (i == 0x10 && ctx->a.r8.h == 0x00)
    {
        // set video mode
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x25)
    {
        // set int vect AL DS:DX
        printf("Set int vector - ignore\n");
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x35)
    {
        printf("Get int vector - ignore\n");
        ctx->_es = 0;
        ctx->b.r16 = 0;
        return;
    }
    if (i == 0x33)
    {
        // mouse
        ctx->a.r16 = 0;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x3c)
    {
        // create file
        ctx->carry = true;
        return;
    }
    printf("int %d\n", i);
}
void cicocontext_t::out(int port, int val)
{
    if (mVideo.PortWrite16(port, val))
    {
        return;
    }
}
void cicocontext_t::in(uint8_t& val, int port)
{
    if (port == 0x3da)
    {
        static int retrace = 0;
        retrace++;
        val = (retrace & 1) ? 8 : 0;
        return;
    }
    assert(0);
}

void cicocontext_t::push(const uint16_t& r)
{
    memory16(ctx->_ss, ctx->_sp) = r;
    ctx->_sp -= 2;
    assert(ctx->_sp > 0);
}
void cicocontext_t::pop(uint16_t& r)
{
    assert(ctx->_sp <= 0xffff);
    ctx->_sp += 2;
    r = memory16(ctx->_ss, ctx->_sp);
}
void cicocontext_t::push(const int& r)
{
    assert(r >= 0 && r <= 0xffff);
    memory16(ctx->_ss, ctx->_sp) = r;
    ctx->_sp -= 2;
}
void cicocontext_t::pop(int& r)
{
    ctx->_sp += 2;
    r = memory16(ctx->_ss, ctx->_sp);
}
void cicocontext_t::stop(int a)
{
    assert(0);
}

void cicocontext_t::cbw()
{
    ctx->a.r8.h = (ctx->a.r8.l & 0x80) ? 0xff : 0;
}
void cicocontext_t::div(uint16_t& r)
{
    uint16_t result = ctx->a.r16 / r;
    uint16_t remain = ctx->a.r16 % r;
    ctx->a.r16 = result;
    ctx->d.r16 = remain;
}
void cicocontext_t::div(uint8_t& r)
{
    uint16_t result = ctx->a.r16 / r;
    uint16_t remain = ctx->a.r16 % r;
    ctx->a.r8.l = result;
    ctx->d.r8.h = remain;
}
void cicocontext_t::sar(uint16_t& a, uint8_t b)
{
    int16_t& sa = (short&)a;
    sa >>= b;
}

}

void sub_11108();
void sub_1176c();
void sub_11783();
void sub_110c6();
void sub_117ac();
void sub_117d6();
void sub_118a9();
void sub_11a9e();
void sub_110c6();
void sub_11993();
void sub_119c2();
void sub_12e02();
void sub_110c6();
void sub_12fe8();
void sub_1300a();
void sub_116fe();
void sub_112cb();
void sub_110c6();
void sub_112eb();
void sub_115fc();
void sub_116df();
void sub_116d6();
void sub_11740();
void sub_11384();
void sub_113a8();
void sub_114f0();
void sub_110f3();
void sub_118c7();
void sub_11429();
void sub_117f4();
void sub_1171f();
void sub_11b09();
void sub_11b4a();
void sub_12f50();
void sub_112a7();

void CicoContext::cicocontext_t::callIndirect(int a)
{
    switch (0x10000 + a)
    {
        case 0x11108: sub_11108(); break; // 1000:1108
        case 0x1176c: sub_1176c(); break; // 1000:176c
        case 0x11783: sub_11783(); break; // 1000:1783
        case 0x110c6: sub_110c6(); break; // 1000:10c6
        case 0x117ac: sub_117ac(); break; // 1000:17ac
        case 0x117d6: sub_117d6(); break; // 1000:17d6
        case 0x118a9: sub_118a9(); break; // 1000:18a9
        case 0x11a9e: sub_11a9e(); break; // 1000:1a9e
        //case 0x110c6: sub_110c6(); break; // 1000:10c6
        case 0x11993: sub_11993(); break; // 1000:1993
        case 0x119c2: sub_119c2(); break; // 1000:19c2
        case 0x12e02: sub_12e02(); break; // 1000:2e02
        //case 0x110c6: sub_110c6(); break; // 1000:10c6
        case 0x12fe8: sub_12fe8(); break; // 1000:2fe8
        case 0x1300a: sub_1300a(); break; // 1000:300a
        case 0x116fe: sub_116fe(); break; // 1000:16fe
        case 0x112cb: sub_112cb(); break; // 1000:12cb  <--------
        //case 0x110c6: sub_110c6(); break; // 1000:10c6
        case 0x112eb: sub_112eb(); break; // 1000:12eb
        case 0x115fc: sub_115fc(); break; // 1000:15fc
        case 0x116df: sub_116df(); break; // 1000:16df
        case 0x116d6: sub_116d6(); break; // 1000:16d6
        case 0x11740: sub_11740(); break; // 1000:1740
        case 0x11384: sub_11384(); break; // 1000:1384
        case 0x113a8: sub_113a8(); break; // 1000:13a8
        case 0x114f0: sub_114f0(); break; // 1000:14f0
        case 0x110f3: sub_110f3(); break; // 1000:10f3
        case 0x118c7: sub_118c7(); break; // 1000:18c7
        case 0x11429: sub_11429(); break; // 1000:1429
        case 0x117f4: sub_117f4(); break; // 1000:17f4
        case 0x1171f: sub_1171f(); break; // 1000:171f
        case 0x11b09: sub_11b09(); break; // 1000:1b09
        case 0x11b4a: sub_11b4a(); break; // 1000:1b4a
        case 0x12f50: sub_12f50(); break; // 1000:2f50
        case 0x112a7: sub_112a7(); break; // 1000:12a7
        default:
            assert(0);
    }
    //assert(0);
}

void sub_10010();
int main(int argc, const char * argv[])
{
    CicoContext::ctx = new CicoContext::cicocontext_t();
    CicoContext::ctx->_cs = 0x1000;
    CicoContext::ctx->_ss = 0x1cfc;
    CicoContext::ctx->_sp = 0x0020;

    memset(mem, 0, sizeof(mem));
    FILE* f = fopen("/Users/gabrielvalky/Documents/git/Projects/CicoJit/capout/GOOSE.EXE", "rb");
    fread(mem, 53684, 1, f);
    fclose(f);

    mSdl.Init();
    sub_10010();
    mSdl.Deinit();
    return 0;
}


//#include "goose.cpp"
