//
//  main.cpp
//  cicorunwin
//
//  Created by Gabriel Valky on 22/11/2025.
//

#include <iostream>
#include <assert.h>
#include "sdl.h"

CSdl sdl;


const char* appRootPath = "";
std::vector<uint8_t> binObject(0x434000 - 0x401000);
int binObjectBase = 0x401000;
std::vector<uint8_t> allocator(1024*1024*20);
int allocatorBase = 0;
int allocatorLast = 0;

std::vector<uint8_t> GetFileContents(std::string fullPath)
{
    FILE* f = fopen(fullPath.c_str(), "rb");
    if (f)
    {
        fseek(f, 0, SEEK_END);
        size_t dataSize = ftell(f);
        rewind(f);

        std::vector<uint8_t> Data(dataSize);
        fread(Data.data(), 1, dataSize, f);
        fclose(f);
        return Data;
    }
    assert(0);
    return {};
}

void memoryASet(int s, int o, int v)
{
//    int check = allocator[0x75a8e8+0x44+1-allocatorBase];
//    assert(check == 0xb0 || check == 0);
//    if (o== 0x412ff8 && v != 0) // yvect
//    if (o==0x412fe8) // ypos
    {
        int f = 9;
    }
    assert(o != 0x40d04c);
    if (s == 9999)
        return;
    if (o >= binObjectBase && o < binObjectBase + binObject.size())
        binObject[o-binObjectBase] = v;
    else if (o >= allocatorBase && o < allocatorBase + allocator.size())
        allocator[o-allocatorBase] = v;
    else
        assert(0);
}
extern uint32_t ptrAllegKeys;
uint8_t memoryAGet(int s, int o)
{
    if (o == 0x42bde0+0x1c)
    {
        int f = 9;
    }
//    assert(o != 0x40d04c);
    if (s == 9999)
        return 0;
    if (o >= binObjectBase && o < binObjectBase + binObject.size())
        return binObject[o-binObjectBase];
    else if (o >= allocatorBase && o < allocatorBase + allocator.size())
        return allocator[o-allocatorBase];
    else
        assert(0);
    return 0;
}

uint8_t* MemoryGetPtr(int s, int o)
{
    if (o >= binObjectBase && o < binObjectBase + binObject.size())
        return &binObject[o-binObjectBase];
    else if (o >= allocatorBase && o < allocatorBase + allocator.size())
        return &allocator[o-allocatorBase];
    else
        assert(0);
    return nullptr;
}

void loadOverlay(const char* image, int base)
{
    if (binObject.size() == 0)
    {
        //binObject = GetFileContents(std::string("/Users/gabrielvalky/Documents/git/Projects/cicodis32/jit3/") + image);
        binObject = GetFileContents(image);
        assert(binObject.size());
        binObjectBase = base;
    }
    else
    {
        assert(base >= binObjectBase);
        std::vector<uint8_t> data = GetFileContents(image);
//        binObject.resize(base-binObjectBase+data.size());
        memcpy(&binObject[base-binObjectBase], &data[0], data.size());
    }
    allocatorBase = base + (int)binObject.size() + 1024*1024;
    allocatorBase = (allocatorBase + 0xfff) & ~0xfff;
    allocatorLast = allocatorBase;
}

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
//    if (o==0x412ff8)
//        return 0;
//fpuinsns::FromFp64(memoryAGet64(ds, 0x412fe8))
//    if (o==0x412fe8) // ypos
//    {
//        if (random()% 100 == 0)
//        {
//            double d = 400;
//            int64_t t;
//            memcpy(&t, &d, 8);
//            return t; //fpuinsns::toFp64(400);
//        }
//    }
    return
    ((uint64_t)memoryAGet(s, o+0) << 0)+
    ((uint64_t)memoryAGet(s, o+1) << 8)+
    ((uint64_t)memoryAGet(s, o+2) << 16)+
    ((uint64_t)memoryAGet(s, o+3) << 24)+
    ((uint64_t)memoryAGet(s, o+4) << 32)+
    ((uint64_t)memoryAGet(s, o+5) << 40)+
    ((uint64_t)memoryAGet(s, o+6) << 48)+
    ((uint64_t)memoryAGet(s, o+7) << 56);
}


void renderPixels(uint8_t*pixels, uint32_t*pal)
{
    for (int y=0; y<480; y++)
        for (int x=0; x<640; x++)
        {
            sdl.SetPixel(x, y, pal[pixels[y*640+x]]);
        }
    sdl.Loop();
}
void sync()
{
    memoryASet32(0, 0x413028, memoryAGet32(0, 0x413028)+300); //0x413028
    memoryASet32(0, 0x42bbc0, 1);
    sdl.Loop();
}
void onMouseMove(int x, int y)
{
}
void onMouseButton(int b)
{
}
int playSound(uint8_t* ptr, int len, int samplerate, const char* fmt, bool);

void onKey(int k, int p)
{
    // 85, 82, 84
    switch (k)
    {
        case SDL_SCANCODE_ESCAPE:
            playSound(nullptr, 0, 0, "", false);
            exit(0);
            break;
    case SDL_SCANCODE_LEFT: memoryASet(0, memoryAGet32(0, 0x40d1a4)+82, p); break;
        case SDL_SCANCODE_RIGHT: memoryASet(0, memoryAGet32(0, 0x40d1a4)+83, p); break;
    case SDL_SCANCODE_UP: memoryASet(0, memoryAGet32(0, 0x40d1a4)+84, p); break;
    case SDL_SCANCODE_DOWN: memoryASet(0, memoryAGet32(0, 0x40d1a4)+85, p); break;
        case SDL_SCANCODE_4: memoryASet(0, memoryAGet32(0, 0x40d1a4)+0x28, p); break;
        case SDL_SCANCODE_1: memoryASet(0, memoryAGet32(0, 0x40d1a4)+0x1c, p); break;
        case SDL_SCANCODE_RETURN: memoryASet(0, memoryAGet32(0, 0x40d1a4)+67, p); break;
        case SDL_SCANCODE_SPACE: memoryASet(0, memoryAGet32(0, 0x40d1a4)+75, p); break;
    }
}

int playSound(uint8_t* ptr, int len, int samplerate, const char* fmt, bool loop)
{
    static bool init = false;
    static SDL_AudioDeviceID devices[16];
    if (!init)
    {
        SDL_AudioSpec want{};
        want.freq = samplerate;
        want.format = AUDIO_U16;  // signed 8-bit
        want.channels = 1;       // mono
        want.samples = 512;     // internal buffer size
        want.callback = nullptr; // we’ll use SDL_QueueAudio()

        for (int i=0; i<sizeof(devices)/sizeof(devices[0]); i++)
            devices[i] = SDL_OpenAudioDevice(nullptr, 0, &want, nullptr, 0);
//        assert(dev);
        init = true;
    }

    if (ptr == nullptr)
    {
        for (int i=0; i<sizeof(devices)/sizeof(devices[0]); i++)
        {
            SDL_CloseAudioDevice(devices[i]);
            devices[i] = 0;
        }
        SDL_CloseAudio();
        SDL_QuitSubSystem(SDL_INIT_AUDIO);
        return 0;
        // stop all
    }
//    static SDL_AudioDeviceID dev = 0;

    static int counter = 0;
//    printf("PLAY: %x\n", ofs);
    int handle = counter;
    SDL_QueueAudio(devices[counter], ptr, len);
    SDL_PauseAudioDevice(devices[counter++], 0);
    counter %= sizeof(devices)/sizeof(devices[0]);
    return 0x6ab60000 + handle;
}

void init();
void start();
int main(int argc, const char * argv[]) {
    // insert code here...
    init();
    assert(memoryAGet(0, 0x40e000+0x90) == 'S');
    sdl.Init();

    start();
    return EXIT_SUCCESS;
}
