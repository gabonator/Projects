#include <stdio.h>
#include <cassert>
#include <stdarg.h>
#include <setjmp.h>
#define _HOST
#include "cicoctx.h"

jmp_buf bufferA, bufferB;
bool resumeJump{false};

// javascript imports
extern "C" {
int sprintf ( char * str, const char * format, ... );
  void apiPrint(char* msg);
  void apiRead(char* name, void* ofs);
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

  void cicocontext_t::memoryVideoSet8(int seg, int ofs, uint8_t v)
  {
  }
  void cicocontext_t::memoryVideoSet16(int seg, int ofs, uint16_t v)
  {
  }
  uint8_t cicocontext_t::memoryVideoGet8(int seg, int ofs)
  {
    return 0;
  }
  uint16_t cicocontext_t::memoryVideoGet16(int seg, int ofs)
  {
    return 0;
  }
  void cicocontext_t::callInterrupt(int i)
  {
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
    apiPrint((char*)"unhanled interrupt");
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
    apiRead((char*)file, &ctx.memory[ofs]);
  } 
  void cicocontext_t::out(int port, uint8_t val)
  {
  }
  void cicocontext_t::out(int port, uint16_t val)
  {
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
  }
  void cicocontext_t::sync()
  {
    apiPrint((char*)"--x");
    resumeJump = true;
    apiPrint((char*)"sync");
    apiPrint((char*)"--y");
    if (!setjmp(bufferB))
    {
      apiPrint((char*)"--v");
      longjmp(bufferA, 1);
      apiPrint((char*)"--w");
    } else {
      apiPrint((char*)"--z");
    } 
//    assert(0);
  }
  void cicocontext_t::syncKeyb()
  {
    apiPrint((char*)"syncKeyb");
    assert(0);
  }
};

// javascript exports
extern "C" void appLoop() { }
extern "C" void appFinish() {}
extern "C" void appInit() { 
  apiPrint((char*)"--a");
  if (!setjmp(bufferA))
  {  
    apiPrint((char*)"--b");
    if (resumeJump)
    {
      apiPrint((char*)"--c");
      longjmp(bufferB, 1);
      apiPrint((char*)"--d");
    } else {
      apiPrint((char*)"--e");
      start(); 
      apiPrint((char*)"--f");
    }
  } else {
    apiPrint((char*)"--g");
  }
}
