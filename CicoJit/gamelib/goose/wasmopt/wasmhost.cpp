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

CEga mVideo;

uint32_t mVideoPixels[320*200];
uint8_t asyncifyBuffer[1024+12];
uint8_t* appMemory = CicoContext::ctx.memory;
uint32_t* appVideo = mVideoPixels;

// javascript imports
extern "C" {
  int sprintf ( char * str, const char * format, ... );
  void apiPrint(char* msg);
  int apiRead(char* name, int readofs, int readlen, void* targetofs);
  void foxEvent(const char* e);
};

void start();

namespace CicoContext
{
  cicocontext_t ctx;
  uint8_t cicocontext_t::memoryAGet8(int seg, uint16_t ofs)
  {
    assert(0);
    return 0;
  }
  void cicocontext_t::memoryASet8(int seg, uint16_t ofs, uint8_t v)
  {
    assert(0);
  }
  uint16_t cicocontext_t::memoryAGet16(int seg, uint16_t ofs)
  {
    assert(0);
    return 0;
  }
  void cicocontext_t::memoryASet16(int seg, uint16_t ofs, uint16_t v)
  {
    assert(0);
  }
  void cicocontext_t::memoryBiosSet8(int seg, int ofs, uint8_t v)
  {
    assert(0);
  }
  void cicocontext_t::memoryBiosSet16(int seg, int ofs, uint16_t v)
  {
    assert(0);
  }
  uint8_t cicocontext_t::memoryBiosGet8(int seg, int ofs)
  {
    assert(0);
    return 0;
  }
  uint16_t cicocontext_t::memoryBiosGet16(int seg, int ofs)
  {
    assert(0);
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
  void cicocontext_t::callInterrupt(int i)
  {
    static char currentFile[32];
    static int currentOfs{0};
    if (i == 0x10)
    {
        mVideo.Interrupt(&ctx);
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x25)
        return; // get int vect
    if (i == 0x21 && ctx.a.r8.h == 0x35)
        return; // get int vect

    if (i == 0x21 && ctx.a.r8.h == 0x09)
    {
        apiPrint((char*)ctx.memory + ctx._ds*16+ctx.d.r16);
        return;
    }

    if (i == 0x21 && ctx.a.r8.h == 0x3d)
    {
        char filename[32];
        int j = 0;
        for (int i=0; i<30; i++)
        {
            char c = ctx.memory[ctx._ds*16+ctx.d.r16+i];
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
        apiPrint(filename);
        strcpy(currentFile, filename);
        currentOfs = 0;
        ctx.carry = strcmp(filename, "HISCORES") == 0;
        ctx.a.r16 = 5;
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x3f)
    {
        assert(ctx._ds < 0xa000);
        int readBytes = apiRead(currentFile, currentOfs, ctx.c.r16, &memory[ctx._ds*16+ctx.d.r16]);
        currentOfs += readBytes;
        ctx.a.r16 = readBytes;
        ctx.carry = 0;
        return;
    }
    if (i == 0x21 && ctx.a.r8.h == 0x3e)
        return;
    if (i == 0x21 && ctx.a.r8.h == 0x3c)
    {
        ctx.carry = true;
        return;
    }
    if (i == 0x12)
    {
        ctx.a.r16 = 0x800;
        return;
    }

    if (i == 0x33 && ctx.a.r8.h == 0)
    {
        // mouse
        ctx.a.r16 = 0;
        return;
    }

    char temp[128];
    sprintf(temp, "unhanled interrupt 0x%02x ah=0x%02x", i, ctx.a.r8.h);
    apiPrint(temp);
    assert(0);
  }
  bool cicocontext_t::stop(const char* msg)
  {
    assert(0);
    return false;
  }
  void cicocontext_t::load(const char* path, const char* file, int size)
  {
    apiPrint((char*)"load!");
    int ofs = ctx._loadAddress*16 - ctx._headerSize;
    apiRead((char*)file, 0, size, &ctx.memory[ofs]);
  } 
  void cicocontext_t::out(int port, uint8_t val)
  {
    if (port > 0x300)
      mVideo.PortWrite8(port, val);
  }
  void cicocontext_t::out(int port, uint16_t val)
  {
    if (port > 0x300)
      mVideo.PortWrite16(port, val);
  }
  void cicocontext_t::in(uint8_t& val, int port)
  {
    val = 0;
    if (port > 0x300)
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
