#include <stdio.h>
#include <cassert>
#include <stdarg.h>
#include <setjmp.h>

// javascript imports
extern "C" {
  int sprintf ( char * str, const char * format, ... );
  void apiPrint(char* msg);
  int apiRead(char* name, int readofs, int readlen, void* targetofs);
};

#define _HOST
#include "cicoctx.h"
#include <emscripten.h>
#include <emscripten/fiber.h>
#include <string.h>
#include "ega.h"

CPagedVga mVideo;

uint32_t mVideoPixels[640*400];
uint8_t asyncifyBuffer[1024+12];
uint8_t* appMemory = CicoContext::ctx.memory;
uint32_t* appVideo = mVideoPixels;
uint32_t lastKey = 0;
uint32_t seed = 0;

void start();

namespace CicoContext
{
  int mFrameCounter = 0;
  cicocontext_t ctx;

  void cicocontext_t::memoryVideoSet8(int seg, uint16_t ofs, uint8_t data)
  {
    mVideo.Write(seg*16+ofs, data);
  }
  void cicocontext_t::memoryVideoSet16(int seg, uint16_t ofs, uint16_t data)
  {
    memoryVideoSet8(seg, ofs, data & 0xff);
    memoryVideoSet8(seg, ofs+1, data >> 8);
  }
  uint8_t cicocontext_t::memoryVideoGet8(int seg, uint16_t ofs)
  {
    assert(seg*16+ofs >= 0xa0000 && seg*16+ofs-0xa0000 < 0x10000*2*4);
    return mVideo.Read(seg*16+ofs);
  }
  uint16_t cicocontext_t::memoryVideoGet16(int seg, uint16_t ofs)
  {
    return memoryVideoGet8(seg, ofs) | (memoryVideoGet8(seg, ofs+1) << 8);
  }
  void cicocontext_t::callInterrupt(int i)
  {
    static char currentFile[128];
    static int currentOfs{0};

    if (i == 0x21 && ctx.a.r8.h == 0x35)
      return; // get int vect
    if (i == 0x21 && ctx.a.r8.h == 0x25)
      return; // set int vect
    if (i == 0x15 && ctx.a.r8.h == 0x84)
    {
        carry = true;
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
            if (c >= 'a' && c <= 'z')
                c -= 'a' - 'A';
            if (c == '\\')
                c = '/'; 
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
    if (i == 0x21 && ctx.a.r8.h == 0x2c)
    {
        ctx.c.r8.h = seed; // hr
        ctx.c.r8.l = seed >> 8; // min
        ctx.d.r8.h = seed >> 16; // sec
        ctx.d.r8.l = seed >> 24; // hundredths
        return;
    }
    if (i == 0x16 && ctx.a.r8.h == 0x01)
    {
        zero = true;
        return; 
    }
    if (i == 0x16 && ctx.a.r8.h == 0x00)
    {
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
    return false;
  }
  void cicocontext_t::load(const char* path, const char* file, int size)
  {
    apiPrint((char*)"load");
    int ofs = ctx._cs*16 - ctx._headerSize;
    if (ofs >= 0)
      apiRead((char*)file, 0, size, &ctx.memory[ofs]);
    else
      apiRead((char*)file, -ofs, size+ofs, &ctx.memory[0]);
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
  }
  void cicocontext_t::sync()
  {
    mFrameCounter++;
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
