#include <stdint.h>
#include <cassert>
#include <string.h>
#include <emscripten.h>
#include <emscripten/fiber.h>
#include <stdio.h>

uint8_t memory[3812*1024];
uint8_t video[320*200];
uint8_t asyncifyBuffer[1024+12];
uint32_t palette[256];

uint32_t mVideoPixels[320*200];
//uint32_t* appEgaPalette = mVideo.palette;
uint32_t* appFrameBuffer = mVideoPixels;

int allocatorBase = 0x400000 - 0x187000;
int mouseX;
int mouseY;
int mouseB;

// javascript imports
extern "C" {
  int sprintf ( char * str, const char * format, ... );
  void apiPrint(char* msg);
  int apiOpen(char* name);
  int apiRead(char* name, int readofs, int readlen, int targetofs);
};

//

void loadOverlay(const char* image, int base)
{
  apiPrint((char*)__FUNCTION__);
  apiOpen((char*)image);
  apiPrint((char*)"pre sleep");
  emscripten_sleep(0);
  apiPrint((char*)"post sleep");
  apiRead((char*)image, 0, -1, base);
}


/*
void out16(int, int)
{
  apiPrint((char*)__FUNCTION__);
}

void out8(int, int)
{
  apiPrint((char*)__FUNCTION__);
}
*/
void memoryVideoSet(int s, int o, int v)
{
//  if (o % 10000 == 0)
//    printf("vid %x %x\n", o, v);
  video[o-0xa0000] = v;
}
void memoryVideoSet32(int s, int o, uint32_t v)
{
//  if (o % 10000 == 0)
//    printf("vid32 %x %x\n", o, v);
  *((uint32_t*)&video[o-0xa0000]) = v;
}

void sync()
{
  int i = 0;
  for (int y=0; y<200; y++)
    for (int x=0; x<320; x++, i++)
      mVideoPixels[i] = palette[video[i]];

  emscripten_sleep(1);
}

/*void interrupt(int i)
{
  apiPrint((char*)__FUNCTION__);
}
int in8(int port)
{
  apiPrint((char*)__FUNCTION__);
  return 0;
}
int in16(int port)
{
  apiPrint((char*)__FUNCTION__);
  return 0;
}
*/
void playSound(int seg, uint32_t ofs, int len, int samplerate, const char* fmt)
{
  apiPrint((char*)__FUNCTION__);
}

/*
uint8_t memoryPspGet(int s, int o)
{
  apiPrint((char*)__FUNCTION__);
  return 0;
}
uint16_t memoryPspGet16(int s, int o)
{
  apiPrint((char*)__FUNCTION__);
  return 0;
}
uint32_t memoryPspGet32(int s, int o)
{
  apiPrint((char*)__FUNCTION__);
  return 0;
}
*/

uint8_t memoryPspGet(int s, int o)
{
    if (s == 0x28)
    {
        switch (o)
        {
            case 0x2c: return 0x30;
            case 0x2d: return 0x00;
            case 0x80: return 0x20;
            default:
                if (o > 0x80 && o <= 0x80 + 0x40)
                {
                    const char p[] = "\\W\\WRMS.EXE\x00\x00";
                    if (o-0x81 >= 0 && o-0x81 < sizeof(p))
                        return p[o-0x81];
                    return 0;
                }
        }
        assert(0);
    }
    if (s == 0x30)
    {
        if (o < 0x100)
        {
            const char p[] = "PATH=Z:\\\x00"
            "COMSPEC=Z:\\COMMAND.COM\x00"
            "BLASTER=A220 I7 D1 H5 T6\x00\x00\x01\0x00"
            "C:\\W\\WRMS.EXE\x00\x00\x00\x00";
            if (o < sizeof(p))
                return p[o];
            return 0;
        }
        
    }
    assert(0);
    return 0;
}

uint16_t memoryPspGet16(int s, int o)
{
    return memoryPspGet(s, o) +
        memoryPspGet(s, o+1)*0x100;
}
uint32_t memoryPspGet32(int s, int o)
{
    return memoryPspGet(s, o) +
        memoryPspGet(s, o+1) * 0x100 +
        memoryPspGet(s, o+2) * 0x10000 +
        memoryPspGet(s, o+3) * 0x1000000;
}

void out8(int p, int v) {
    static int palIndex = 0;
    if (p == 0x3c8)
    {
      palIndex = v*4;
      return;
    }
    if (p == 0x3c9)
    {
      ((uint8_t*)palette)[palIndex++] = v*4;
      if (palIndex%4 == 3)
        ((uint8_t*)palette)[palIndex++] = 255;
      return;
    }
    printf("Write port %x %x\n", p, v);
}

bool stop(const char* msg = nullptr, const char* info = nullptr)
{
    printf("stop called\n");
    return 0;
}

// javascript exports

void init();
void start();

extern "C" void appMain() { 
  printf("Memory at %x\n", (int)memory);
  memset(memory, 0, sizeof(memory));
  init();
  start();
}
