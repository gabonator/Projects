#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "sdl.h"

//#define _HOST
//#include "cicoemu.h"
#include "ega.h"

CSdl mSdl;
CEga mVideo;

uint8_t mem[0x40000];

int watchdog = 0;
void _sync()
{
  watchdog = 0;
  CicoContext::ctx->sync();
}

void onKey(int k, int p)
{
/*
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
        case SDL_SCANCODE_ESCAPE: CicoContext::ctx->stop("user requested termination"); break;
    }
    CicoContext::ctx->memory8(0x1040, 0xB884) = keys;
*/
if (k == SDL_SCANCODE_ESCAPE) 
  CicoContext::ctx->stop("user requested termination");

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
uint8_t cicocontext_t::memoryAGet8(int seg, int ofs)
{
    ofs &= 0xffff;
//    if (ofs < 0 || ofs > 0xffff)
//      stop("offset out of range");

    if (watchdog++ >= 5000000)
      stop("infinite loop");
    ofs &= 0xffff;
    if (seg >= 0x1000 && seg < 0xa000)
        return memory8(seg, ofs);
    else if (seg >= 0xa000 && seg < 0xe000)
        return memoryVideoGet8(seg, ofs);
    else
        stop("bios read"); // bios
    return 0;
}

uint16_t cicocontext_t::memoryAGet16(int seg, int ofs)
{
    ofs &= 0xffff;
//    if (ofs < 0 || ofs > 0xffff)
//      stop("offset out of range");

    if (watchdog++ >= 5000000)
      stop("infinite loop");
    ofs &= 0xffff;
    if (seg >= 0x1000 && seg < 0xa000)
        return memory16(seg, ofs);
    else if (seg >= 0xa000 && seg < 0xe000)
        return memoryVideoGet16(seg, ofs);
    else
    {
        if (seg == 0x0040 && ofs == 0x0063)
            return 0x3d4;
            
        stop("bios read"); // bios
    }
    return 0;
}

void cicocontext_t::memoryASet8(int seg, int ofs, uint8_t val)
{
    ofs &= 0xffff;
//    if (ofs < 0 || ofs > 0xffff)
//      stop("offset out of range");

    if (watchdog++ >= 5000000)
      stop("infinite loop");
    if (seg >= 0x1000 && seg < 0xa000)
        memory8(seg, ofs) = val;
    else if (seg >= 0xa000 && seg < 0xe000)
        memoryVideoSet8(seg, ofs, val);
    else
        stop("bios write"); // bios
}

void cicocontext_t::memoryASet16(int seg, int ofs, uint16_t val)
{
    ofs &= 0xffff;
//    if (ofs < 0 || ofs > 0xffff)
//      stop("offset out of range");

    if (watchdog++ >= 5000000)
      stop("infinite loop");
    ofs &= 0xffff;
    if (seg >= 0x1000 && seg < 0xa000)
        memory16(seg, ofs) = val;
    else if (seg >= 0xa000 && seg < 0xe000)
        memoryVideoSet16(seg, ofs, val);
    else
    {
        if (seg == 0x0040 && ofs == 0x004e)
            return;

        stop("bios write"); // bios
    }
}

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
    if (i == 0x21 && ctx->a.r8.h == 0x4a)
    {
        // resize block
        ctx->carry = false;
        return;
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
        char fullname[128] = "../goose/";
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
        for (int i=0; i<c; i++)
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
    if (i == 0x21 && ctx->a.r8.h == 0x48)
    {
        static int freeMem = 0x2000;
        // _bx size
        printf("malloc %d bytes -> %04x:0000\n", ctx->b.r16, freeMem);
        ctx->a.r16 = freeMem;
        freeMem += ctx->b.r16;
        ctx->carry = false;
        return;
    }
    if (i == 0x10 && ctx->a.r8.h == 0x0f)
        return;

    
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
        mVideo.SetPaletteIndex(ctx->b.r8.l, ctx->b.r8.h);
        return;
    }
    if (i == 0x10 && ctx->a.r16 == 0x1012)
    {
        mVideo.Interrupt(ctx);
        return;
    }

    assert(0);
    printf("int %d\n", i);
}

void cicocontext_t::out(int port, uint8_t val)
{
    if (mVideo.PortWrite8(port, val))
    {
        return;
    }
}
void cicocontext_t::out(int port, uint16_t val)
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
    if (port == 0x201)
    {
        val = 0xff;
        return;
    }
    if (port == 0x40)
        return;
    val = 0;
    assert(0);
}

void cicocontext_t::push(const uint16_t& r)
{
    ctx->_sp -= 2;
    memory16(ctx->_ss, ctx->_sp) = r;
    assert(ctx->_sp > 0);
}
uint16_t cicocontext_t::pop(void)
{
    assert(ctx->_sp <= 0xffff);
    uint16_t aux = memory16(ctx->_ss, ctx->_sp);
    ctx->_sp += 2;
    return aux;
}
void cicocontext_t::push(const int& r)
{
    assert(r >= 0 && r <= 0xffff);
    ctx->_sp -= 2;
    memory16(ctx->_ss, ctx->_sp) = r;
}
void cicocontext_t::pop(int& r)
{
    ctx->_sp += 2;
    r = memory16(ctx->_ss, ctx->_sp);
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
    ctx->d.r8.h = remain;
}
void cicocontext_t::idiv(uint8_t r)
{
    int32_t dw = (ctx->d.r16 << 16) | ctx->a.r16;
    uint16_t result = dw / r;
    uint16_t remainder = dw % r;
    ctx->a.r16 = result;
    ctx->d.r16 = remainder;
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
    assert(0);
    return 0;
}
uint16_t cicocontext_t::rcr(uint16_t r, int i)
{
    assert(0);
    return 0;
}

uint8_t cicocontext_t::rol(uint8_t r, int l)
{
    assert(0);
    return 0;
}

uint8_t cicocontext_t::ror(uint8_t r, int l)
{
    assert(0);
    return 0;
}
uint16_t cicocontext_t::ror(uint16_t r, int l)
{
    assert(0);
    return 0;
}
void cicocontext_t::idiv(uint16_t r)
{
    assert(0);
}
void cicocontext_t::imul(uint16_t r)
{
    assert(0);
}

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
void cicocontext_t::imul(uint8_t r)
{
    int v = (char)r * (short)ctx->a.r16;
    ctx->a.r16 = v & 0xffff;
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

template <typename INT>
INT _rol(INT val) {
    return (val << 1) | (val >> (sizeof(INT)*CHAR_BIT-1));
}

uint16_t cicocontext_t::rol(uint16_t r, int l)
{
    while (l--)
        r = _rol<uint16_t>(r);
    return r;
}

void cicocontext_t::cmc()
{
    ctx->carry = !ctx->carry;
}
void cicocontext_t::aaa()
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

}
