#include <stdio.h>
#include <cassert>
#include <stdarg.h>
#include <setjmp.h>
#define _HOST
#include "cicoctx.h"
#include <emscripten.h>
#include <emscripten/fiber.h>
#include <string.h>
#include "ega.h"
#include "font8x8.h"

CCga mVideo;

uint32_t mVideoPixels[320*200];
uint8_t asyncifyBuffer[1024+12];
uint8_t* appMemory = CicoContext::ctx.memory;
uint32_t* appVideo = mVideoPixels;
uint16_t appKeyBuffer = 0xffff;

// javascript imports
extern "C" {
int sprintf ( char * str, const char * format, ... );
  void apiPrint(char* msg);
  int apiRead(char* name, int readofs, int readlen, void* targetofs);
};

#include "indirect.h"

void start();

namespace CicoContext
{
  cicocontext_t ctx;
  void cicocontext_t::memoryBiosSet8(int seg, int ofs, uint8_t v)
  {
  }
  void cicocontext_t::memoryBiosSet16(int seg, int ofs, uint16_t v)
  {
  }
  uint8_t cicocontext_t::memoryBiosGet8(int seg, int ofs)
  {
    if (seg == 0x1d3)
    {
        const char env[] = "PATH=Z:\\"  "\x00"  "COMSPEC=Z:\\COMMAND.COM"  "\x00" 
          "BLASTER=A220 I7 D1 H5 T6"  "\x00\x00\x01\x00"  "C:\\BUM\\B.EXE" 
          "\x00\x00\x00\x00\x00\x00\x00";
        if (ofs<sizeof(env))
            return env[ofs];
        return 0;
    }
    if (seg == 0x1dd && ofs == 0x80)
        return 0;
    if (seg == 0x1dd && ofs == 0x81)
        return 0x0d;
    if (seg == 0xffff && ofs == 0x000e)
        return 0xfc;
    if (seg == 0xf000 && ofs == 0xfffe)
        return 0xfc; // pc at
    if (seg == 0x0040 && ofs == 0x0087)
        return 0x00; // ega active
    if (seg == 0x0040 && ofs == 0x0088)
        return 0x09;
    if (seg == 0x0040 && ofs == 0x0017) 
        return 0x00; // shift keys
    if (seg == 0x0040 && ofs == 0x0010)
        return 0x26;
    if (seg == 0x0040 && ofs == 0x006c)
        return 0; // number of ticks since midnight 54ms
    if (seg == 0x0000 && ofs == 0x0000)
        return 0x1a;
    if (seg == 0xf000 && ofs == 0xffea)
        return 0x00;
    if (seg == 0xf000 && ofs >= 0xfa6e && ofs < (0xfa6e + sizeof(font8x8)))
        return font8x8[ofs-0xfa6e];
      char temp[128];
      sprintf(temp, "cicocontext_t::memoryBiosGet8 rd %04x:%04x", seg, ofs);
      apiPrint(temp);

    assert(0);
    return 0;
  }
  uint16_t cicocontext_t::memoryBiosGet16(int seg, int ofs)
  {
    if ((seg == 0x01dd || seg == 0x01ed || seg == 0x01d3) && ofs < 256)
    {
        if (seg==0x1d3)
            return memoryBiosGet8(seg, ofs) | (memoryBiosGet8(seg, ofs) << 8);
        assert(seg == 0x1dd);
        switch (ofs)
        {
            case 0x02:
                // Segment of the first byte beyond the memory allocated to the program
                return 0x9fff;
            case 0x2c:
                // Environment segment
                return 0x1d3;
            default:
                assert(0);
                return 0;
        }
        assert(0);
    }
    if (seg == 0x0040 && ofs == 0x0063)
        return 0x3d4;
    if (seg == 0x0040 && ofs == 0x0080)
        return 0x1e;
    return 0;
  }

  void cicocontext_t::memoryVideoSet8(int seg, int ofs, uint8_t data)
  {
    mVideo.Write(seg*16+ofs, data);
  }
  void cicocontext_t::memoryVideoSet16(int seg, int ofs, uint16_t data)
  {
    memoryVideoSet8(seg, ofs, data & 0xff);
    memoryVideoSet8(seg, ofs+1, data >> 8);
  }
  uint8_t cicocontext_t::memoryVideoGet8(int seg, int ofs)
  {
    assert(seg*16+ofs >= 0xa0000 && seg*16+ofs-0xa0000 < 0x10000*2*4);
    return mVideo.Read(seg*16+ofs);
  }
  uint16_t cicocontext_t::memoryVideoGet16(int seg, int ofs)
  {
    return memoryVideoGet8(seg, ofs) | (memoryVideoGet8(seg, ofs+1) << 8);
  }
  uint8_t cicocontext_t::memoryAGet8(int seg, int ofs)
  {
      ofs &= 0xffff;
      if ((seg == 0x01dd || seg == 0x01ed || seg == 0x01d3) && ofs < 256)
          return memoryBiosGet8(seg, ofs);
      else if (seg >= 0x01ed && seg < 0xa000)
          return memory8(seg, ofs);
      else if (seg >= 0xa000 && seg < 0xe000)
          return memoryVideoGet8(seg, ofs);
      else
          return memoryBiosGet8(seg, ofs);
  }
  uint16_t cicocontext_t::memoryAGet16(int seg, int ofs)
  {
      ofs &= 0xffff;
      if ((seg == 0x01dd || seg == 0x01ed || seg == 0x01d3) && ofs < 256)
          return memoryBiosGet16(seg, ofs);
      else if (seg >= 0x01ed && seg < 0xa000)
          return memory16(seg, ofs);
      else if (seg >= 0xa000 && seg < 0xe000)
          return memoryVideoGet16(seg, ofs);
      else
          return memoryBiosGet16(seg, ofs);
  }
  void cicocontext_t::memoryASet8(int seg, int ofs, uint8_t val)
  {
      ofs &= 0xffff;
      if ((seg == 0x01dd || seg == 0x01ed) && ofs < 256)
          assert(0);
      else if (seg >= 0x01ed && seg < 0xa000)
          memory8(seg, ofs) = val;
      else if (seg >= 0xa000 && seg < 0xe000)
          memoryVideoSet8(seg, ofs, val);
      else
          memoryBiosSet8(seg, ofs, val);
  }
  void cicocontext_t::memoryASet16(int seg, int ofs, uint16_t val)
  {
      ofs &= 0xffff;
      if ((seg == 0x01dd || seg == 0x01ed) && ofs < 256)
          assert(0); // ???
      else if (seg >= 0x01ed && seg < 0xa000)
          memory16(seg, ofs) = val;
      else if (seg >= 0xa000 && seg < 0xe000)
          memoryVideoSet16(seg, ofs, val);
      else
          memoryBiosSet16(seg, ofs, val);
  }



  void cicocontext_t::callInterrupt(int i)
  {
    static char currentFile[128];
    static int currentOfs{0};

    if (i == 0x21 && ctx.a.r8.h == 0x30)
    {
        ctx.a.r16 = 0x0005;
        ctx.b.r16 = 0xff00;
        ctx.c.r16 = 0x0000;
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x35)
        return; // get int vect
    if (i == 0x21 && ctx.a.r8.h == 0x25)
        return; // get int vect
    if (i == 0x21 && ctx.a.r8.h == 0x4c)
        assert(!!"end program");
    if (i == 0x21 && ctx.a.r8.h == 0x40)
        return;
    if (i == 0x21 && ctx.a.r8.h == 0x4a)
    {
        ctx.carry = false;
        return;
    }
    if (i == 0x1A)
    {
/*
        var now = new Date().getTime() / 1000;
        if (r8[ah] == 4)
        {            
        }
        else if (r8[ah] == 0)
        {
           if (!window.baseTick)
               window.baseTick = now;
            now -= window.baseTick;
            now = now / 6;
            r16[cx] = now >> 16;
            r16[dx] = now & 0xffff;
        } else {
            window.baseTick = now;
        }
*/
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x44)
    {
        ctx.a.r16 = 0x80d3;
        ctx.d.r16 = 0x80d3;
        ctx.carry = 0;
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x48)
    {
        static int freeMem = 0x1d9e;
        ctx.a.r16 = freeMem;
        freeMem += ctx.b.r16;
        freeMem ++;
        ctx.carry = false;
        return;
    }
    if (i == 0x33)
    {
        ctx.a.r16 = 0;
        return;
    }
    if (i == 0x10)
    {
        if (ctx.a.r8.h == 0)
            return;
        if (ctx.a.r8.h == 2)
            return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x09)
    {
        char temp[128];
        for (int i=0; i<100; i++)
        {
            char c = ctx.memory[ctx._ds*16+ctx.d.r16+i];
            if (c=='$' || c == 0)
                break;
            temp[i] = c;
            temp[i+1] = 0;
        }
        apiPrint(temp);
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x3d)
    {
        char filename[100];
        int j = 0;
        for (int i=0; i<100; i++)
        {
            char c = ctx.memory[ctx._ds*16+ctx.d.r16+i];
            if (!c)
                break;
            if (c >= 'A' && c <= 'Z')
                c += 'a' - 'A';
            if (c != ' ')
            {
                filename[j++] = c;
                filename[j] = 0;
            }
        }
        apiPrint(filename);
        strcpy(currentFile, filename);
        currentOfs = 0;
        ctx.carry = 0;
        ctx.a.r16 = 5;
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x3f)
    {
        int readBytes = apiRead(currentFile, currentOfs, ctx.c.r16, &memory[ctx._ds*16+ctx.d.r16]);
        assert(readBytes > 0);
        currentOfs += readBytes;
        ctx.a.r16 = readBytes;
        ctx.carry = 0;
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x3e)
    {   
        return;
    }
    static int _videoMode = -1;
    if (i == 0x10 && ctx.a.r8.h == 0x00)
    {
        // set video mode
        printf("Set video mode: %d\n", ctx.a.r8.l);
        _videoMode = ctx.a.r8.l;
    }
    if (i == 0x10 && ctx.a.r8.h == 0x0f)
    {
        if (_videoMode==-1)
        {
            ctx.a.r16 = 0x5003;
            ctx.b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x12)
        {
            ctx.a.r16 = 0x5012;
            ctx.b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x13)
        {
            ctx.a.r16 = 0x2813;
            ctx.b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x10)
        {
            ctx.a.r16 = 0x5010;
            ctx.b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x4)
        {
            ctx.a.r16 = 0x2804;
            ctx.b.r8.h = 0x00;
            return;
        }
        assert(0);
    }
    if (i == 0x10 && ctx.a.r16 == 0x1130 && ctx.b.r8.h == 0)
    {
        ctx.c.r16= 0x10;
        //ctx->a.r16= 0x5003;
        ctx.d.r8.l = 0x18;
        ctx._es = 0xc000;
        ctx._bp = 0x500;
        return;
    }
    if (i == 0x10 && ctx.a.r8.h == 0x08)
    {
        ctx.a.r16= 0x0720;
        return;
    }
    if (i == 0x10 && ctx.a.r8.h == 0x0b)
    {
      // set pal
      return;
    }
    if (i == 0x11)
    {
        ctx.a.r16 = 0;
        return;
    }
    if (i == 0x10 && ctx.a.r8.h == 0x06)
        return;
    if (i == 0x21 && ctx.a.r8.h == 0x0b)
    {
        ctx.a.r8.l = (appKeyBuffer & 0xff) == 0xff ? 0 : 0xff;
//        ctx->a.r8.l = keyBuffer.empty() ? 0 : 0xff; // check key
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x07)
    {
        ctx.a.r8.l = appKeyBuffer;
        appKeyBuffer >>= 8;
        appKeyBuffer |= 0xff00;
//        ctx->a.r8.l = keyBuffer.front(); // key stdin
//        keyBuffer.pop_front();
        return;
    }

    char temp[128];
    sprintf(temp, "unhanled interrupt 0x%02x ah=0x%02x al=0x%02x", i, ctx.a.r8.h, ctx.a.r8.l);
    apiPrint(temp);
    assert(0);
  }
  bool cicocontext_t::stop(const char* msg)
  {
    return false;
  }
  void cicocontext_t::load(const char* path, const char* file, int size)
  {
    apiPrint((char*)"load!");
    int ofs = ctx._cs*16 - ctx._headerSize;
    apiRead((char*)file, 0, size, &ctx.memory[ofs]);
  } 
  void cicocontext_t::out(int port, uint8_t val)
  {
    mVideo.PortWrite8(port, val);
  }
  void cicocontext_t::out(int port, uint16_t val)
  {
    mVideo.PortWrite16(port, val);
  }
  void cicocontext_t::in(uint8_t& val, int port)
  {
    static int counter = 0;
    val = 0;
    if (port == 0x3da)
        val = (counter++ & 1) ? 9 : 0;
    if (port == 0x40)
        val = (counter++ & 2) ? 0xff:0x00;
    if (port == 0x201)
        val = 0;
    if (port == 0x3d4 || port == 0x3d5)
        val = mVideo.PortRead8(port);
  }
  void cicocontext_t::sync()
  {
    emscripten_sleep(0);
  }
};

extern "C" bool appBlit() { 
  return mVideo.blit(mVideoPixels);
}

// javascript exports
extern "C" void appLoop() { 
  start();
}
extern "C" void appFinish() {
}
extern "C" void appInit() { 
}
