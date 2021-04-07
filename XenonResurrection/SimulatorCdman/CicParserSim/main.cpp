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

#include "cpu.h"
#include "sdl.h"
#include "ega.h"

constexpr WORD appBase = 0x1020;
constexpr WORD _seg000 = 0x1000 - appBase;
constexpr WORD _seg001 = 0x1020 - appBase;
constexpr WORD _seg002 = 0x13EC - appBase;

CEga mVideo;
reg_t _reg;
uint8_t datasegment[0x10000*3];
CSdl mSdl;
std::list<int> keyboardBuffer;

#include "machine.h"
#include "memory.h"
#include "cdman.h"
#include "indirect.h"

void onKey(int k, int p)
{
    if (!p)
        return;

    int key = 0;
    switch (k)
    {
        case SDL_SCANCODE_UP: key = 0x4800; break;
        case SDL_SCANCODE_DOWN: key = 0x5000; break;
        case SDL_SCANCODE_LEFT: key = 0x4b00; break;
        case SDL_SCANCODE_RIGHT: key = 0x4d00; break;
        case SDL_SCANCODE_SPACE: key = 0x3920; break;
        case SDL_SCANCODE_RETURN: key = 0x1c0d; break;
        case SDL_SCANCODE_5:
            for (int i=0; i<4; i++)
            {
                memory(_ds, i + 104) = 0x4d;
                memory16(_ds, i*2 + 491) = memory16(_ds, 0x1059);
                memory16(_ds, i*2 + 499) = memory16(_ds, 0x1059 + 2);
                memory16(_ds, i*2 + 507) = memory16(_ds, 0x1059 + 4);
            }
            break;
    }

    if (key)
    {
        keyboardBuffer.push_back(key);
    }
}

void loadSegment(uint8_t* buffer, const char* suffix, int len)
{
    char fname[128];
    sprintf(fname, "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputCdman/%s", suffix);
    FILE* f = fopen(fname, "rb");
    fread(buffer, len, 1, f);
    fclose(f);
}

void _sync()
{
    for (int y=0; y<350; y++)
      for (int x=0; x<640; x++)
        mSdl.SetPixel(x, y, mVideo.GetPixel(x, y));
    
    mSdl.Loop();
}

int main(int argc, const char * argv[]) {
    m_arrStack.resize(2*64, 0);
    _sp = 64;
    _ds = _es = _di = _bp = 0xdddd;
    
    memset(datasegment, 0, sizeof(datasegment));
    loadSegment(datasegment, "CD-MAN.data", 0x3ec0);
    mSdl.Init();
    while (1)
    {
        start();
        _sync();
    }
    mSdl.Deinit();
    return 0;
}
