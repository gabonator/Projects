#include <stdint.h>
#include <stdio.h>
#include <cassert>
#include <string.h>

uint32_t mVideoPixels[320*200];
uint8_t appMemory[0x10000*18];

extern "C" {
  int apiRead(char* name, int readofs, int readlen, void* targetofs);
  void apiPrint(char* msg);
};

struct flags_t {
  bool carry, zero, sign, interrupts, direction;
};

extern flags_t flags;
extern int headerSize, loadAddress, endAddress;
extern uint16_t ax, bx, cx, dx, es, bp, di, ds;

#define al *reinterpret_cast<uint8_t*>(&ax)
#define ah *(reinterpret_cast<uint8_t*>(&ax) + 1)
#define bl *reinterpret_cast<uint8_t*>(&bx)
#define bh *(reinterpret_cast<uint8_t*>(&bx) + 1)
#define cl *reinterpret_cast<uint8_t*>(&cx)
#define ch *(reinterpret_cast<uint8_t*>(&cx) + 1)
#define dl *reinterpret_cast<uint8_t*>(&dx)
#define dh *(reinterpret_cast<uint8_t*>(&dx) + 1)

void memoryASet(int s, int o, int v);
uint8_t memoryAGet(int s, int o);

#include "ega.h"
//#include "sdl.h"

//CSdl sdl;

void sync();
void appSync();
class CEgaInstance : public CEga
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) override { return memoryAGet(seg, ofs); }
    virtual void sync() override
    {
      blit(mVideoPixels);
    }
} ega;

void appSync()
{
  ega.sync();
}

void memoryASet(int s, int o, int v)
{
  if (s >= 0xa000)
  {
    ega.Write(s*16+o, v);
    return;
  }
  int a = s*16+(o&0xffff);// - loadAddress*16;
  assert(a >= 0 && a < sizeof(appMemory));
  appMemory[a] = v;
}
uint8_t memoryAGet(int s, int o)
{
    if (s == 0x1dd && o == 0x80)
        return 0;
    if (s == 0x1dd && o == 0x81)
        return 0x0d;
    if (s == 0xffff && o == 0x000e)
        return 0xfc;
    if (s == 0xf000 && o == 0xfffe)
        return 0xfc; // pc at
    if (s == 0x0040 && o == 0x0087)
        return 0x00; // ega active
    if (s == 0x0040 && o == 0x0088)
        return 0x09;
    if (s == 0x0040 && o == 0x0017) 
        return 0x00; // shift keys
    if (s == 0x0040 && o == 0x0010)
        return 0x26;
    if (s == 0x0040 && o == 0x006c)
        return 0; // number of ticks since midnight 54ms
    if (s == 0x0000 && o == 0x0000)
        return 0x1a;

//  if (safecount++ > 1000000)
//    assert(0);
  if (s >= 0xa000)
  {
    return ega.Read(s*16+o);
  }
  int a = s*16+(o&0xffff);// - loadAddress*16;
/*
  if (a==0x0040*16+0x0063)
    return 0x3d4;
  if (a==0x0040*16+0x0063+1)
    return 0x3d4>>8;
  if (a==0x0040*16+0x0080)
    return 0x1e;
*/

  assert(a >= 0 && a < sizeof(appMemory));
  return appMemory[a];
}


//uint32_t mVideoPixels[320*200];
//uint8_t asyncifyBuffer[1024+12];
//uint8_t* appMemory = CicoContext::ctx.memory;
//uint32_t* appVideo = mVideoPixels;
//uint32_t seed = 0;


void memoryASet16(int s, int o, int v)
{
    memoryASet(s, o, v & 255);
    memoryASet(s, o+1, (v>>8) & 255);
}

void memoryASet32(int s, int o, uint32_t v)
{
    memoryASet(s, o, v & 255);
    memoryASet(s, o+1, (v>>8) & 255);
    memoryASet(s, o+2, (v>>16) & 255);
    memoryASet(s, o+3, (v>>24) & 255);
}
void memoryASet64(int s, int o, uint64_t v)
{
    memoryASet(s, o, v & 255);
    memoryASet(s, o+1, (v>>8) & 255);
    memoryASet(s, o+2, (v>>16) & 255);
    memoryASet(s, o+3, (v>>24) & 255);
    memoryASet(s, o+4, (v>>32) & 255);
    memoryASet(s, o+5, (v>>40) & 255);
    memoryASet(s, o+6, (v>>48) & 255);
    memoryASet(s, o+7, (v>>56) & 255);
}
uint16_t memoryAGet16(int s, int o)
{
    if (s == 0x0040 && o == 0x0063)
        return 0x3d4;
    if (s == 0x0040 && o == 0x0080)
        return 0x1e;

    return memoryAGet(s, o) +
        memoryAGet(s, o+1)*0x100;
}
uint32_t memoryAGet32(int s, int o)
{
    return memoryAGet(s, o) +
        memoryAGet(s, o+1) * 0x100 +
        memoryAGet(s, o+2) * 0x10000 +
        memoryAGet(s, o+3) * 0x1000000;
}
uint64_t memoryAGet64(int s, int o)
{
    return memoryAGet(s, o) +
        memoryAGet(s, o+1) * 0x100 +
        memoryAGet(s, o+2) * 0x10000 +
        memoryAGet(s, o+3) * 0x1000000 +
        memoryAGet(s, o+4) * 0x100000000ull +
        memoryAGet(s, o+5) * 0x10000000000ull +
        memoryAGet(s, o+6) * 0x10000000000ull;
}

//

  void out8(int port, int val)
  {
    if (port / 0x100 == 3)
      ega.PortWrite8(port, val);
  }
  void out16(int port, int val)
  {
    if (port / 0x100 == 3)
      ega.PortWrite16(port, val);
  }
  int in8(int port)
  {
    static int counter = 0;
    if (port == 0x3da)
        return (counter++ & 1) ? 9 : 0;
    if (port == 0x40)
        return (counter++ & 2) ? 0xff:0x00;
    if (port == 0x201)
        return 0;
    if (port == 0x3d4 || port == 0x3d5)
        return ega.PortRead8(port);
    return 0;
  }


  void load(const char* path, const char* file, int size)
  {
    int ofs = loadAddress*16 - headerSize;
    apiRead((char*)file, 0, size, &appMemory[ofs]);
  } 

///

  void interrupt(int i)
  {
    static char currentFile[128];
    static int currentOfs{0};
    if (i == 0x10)
    {
        ega.Interrupt();
        return;
    }
    if (i == 0x21 && ah == 0x30)
    {
        ax = 0x0005;
        bx = 0xff00;
        cx = 0x0000;
        return;
    }
    if (i == 0x21 && ah == 0x35)
        return; // get int vect
    if (i == 0x21 && ah == 0x25)
        return; // get int vect
    if (i == 0x21 && ah == 0x4c)
        assert(!!"end program");
    if (i == 0x21 && ah == 0x40)
        return;
    if (i == 0x21 && ah == 0x4a)
    {
        flags.carry = false;
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
    if (i == 0x21 && ah == 0x44)
    {
        ax = 0x80d3;
        dx = 0x80d3;
        flags.carry = 0;
        return;
    }
    if (i == 0x21 && ah == 0x48)
    {
        static int freeMem = 0x1d9e; // TODO!
        ax = freeMem;
        freeMem += bx;
        freeMem ++;
        flags.carry = false;
        return;
    }
    if (i == 0x33)
    {
        ax = 0;
        return;
    }
    if (i == 0x21 && ah == 0x09)
    {
        char temp[128];
        for (int i=0; i<100; i++)
        {
            char c = appMemory[ds*16+dx+i];
            if (c=='$' || c == 0)
                break;
            temp[i] = c;
            temp[i+1] = 0;
        }
        apiPrint(temp);
        return;
    }
    if (i == 0x21 && ah == 0x3d)
    {
        char filename[100];
        int j = 0;
        for (int i=0; i<100; i++)
        {
            char c = appMemory[ds*16+dx+i];
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
        flags.carry = 0;
        ax = 5;
        return;
    }
    if (i == 0x21 && ah == 0x3f)
    {
        int readBytes = apiRead(currentFile, currentOfs, cx, &appMemory[ds*16+dx]);
        assert(readBytes > 0);
        currentOfs += readBytes;
        ax = readBytes;
        flags.carry = 0;
        return;
    }
    if (i == 0x21 && ah == 0x3e)
    {   
        return;
    }
    char temp[128];
    snprintf(temp, 128, "unhanled interrupt 0x%02x ah=0x%02x", i, ah);
    apiPrint(temp);
    assert(0);
  }
