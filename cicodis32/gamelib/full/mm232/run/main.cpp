//
//  main.cpp
//  cico32run
//
//  Created by Gabriel Valky on 23/09/2025.
//

#include <iostream>
#include <stdint.h>
#include <assert.h>
//      0 ..   a000 zero
//  10000 ..  4e000 code
//  4e000 .. 270840 data
// 279000 .. 3b9000 alloc

//     loadOverlay("WRMS_1", 0x10000);
//loadOverlay("WRMS_2", 0x4e000);

std::vector<uint8_t> dataObject;
std::vector<uint8_t> codeObject;
std::vector<uint8_t> allocator;
std::vector<uint8_t> allocator2;
std::vector<uint8_t> zeroSeg;
int codeObjectBase = 0;
int dataObjectBase = 0;
int allocatorBase = 0x400000; // worms2 0x400000 - 0x187000, mm2 400000
int allocatorSize = 0x120000;
int zeroSegSize = 0x1000; // 0x120 + 0x1e0;
int memoryTop = 0;
const char* appRootPath = "dos";
//TODO: check sync, CVga::usePlanes, memoryASet video size

// 0x197000 -> 0x10000
extern uint32_t eax, ebx, ecx, edx, edi, ebp, esp;
extern uint16_t ds, cs, es, ss;

#define al *reinterpret_cast<uint8_t*>(&eax)
#define ah *(reinterpret_cast<uint8_t*>(&eax) + 1)
#define bl *reinterpret_cast<uint8_t*>(&ebx)
#define bh *(reinterpret_cast<uint8_t*>(&ebx) + 1)
#define cl *reinterpret_cast<uint8_t*>(&ecx)
#define ch *(reinterpret_cast<uint8_t*>(&ecx) + 1)
#define dl *reinterpret_cast<uint8_t*>(&edx)
#define dh *(reinterpret_cast<uint8_t*>(&edx) + 1)

#define ax *reinterpret_cast<uint16_t*>(&eax)
#define cx *reinterpret_cast<uint16_t*>(&ecx)

#include "ega.h"
#include "sdl.h"

CSdl sdl;

void memoryASet(int s, int o, int v);
uint8_t memoryAGet(int s, int o);

class CVgaInstance : public CVga
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) override { return memoryAGet(seg, ofs);}
    virtual void sync() override
    {
        for (int y=0; y<240; y++)
          for (int x=0; x<320; x++)
            sdl.SetPixel(x, y, GetPixel(x, y));
        sdl.Loop();
    }
} vga;

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
    //assert(0);
    return {};
}


void memoryASet16(int s, int o, int v)
{
    if (s == 0x160 && o == 0x1bdc71)
    {
        int f = 9;
    }

    memoryASet(s, o, v & 255);
    memoryASet(s, o+1, (v>>8) & 255);
}

void memoryASet32(int s, int o, uint32_t v)
{
    if (o == 0x3183f0 && v == 0x8000)
    {
        int f = 9;
    }
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
    return memoryAGet(s, o) +
        memoryAGet(s, o+1) * 0x100 +
        memoryAGet(s, o+2) * 0x10000 +
        memoryAGet(s, o+3) * 0x1000000 +
        memoryAGet(s, o+4) * 0x100000000ull +
        memoryAGet(s, o+5) * 0x10000000000ull +
        memoryAGet(s, o+6) * 0x10000000000ull;
}


//
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





extern int mouseX;
extern int mouseY;
extern int mouseB;

void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
#ifdef WORMS
    int scancode = 0;
    switch (k)
    {
        case SDL_SCANCODE_1: scancode = 0x01; break;
        case SDL_SCANCODE_SPACE: scancode = 0x39; break;
        case SDL_SCANCODE_UP: scancode = 0x48; break;
        case SDL_SCANCODE_LEFT: scancode = 0x4b; break;
        case SDL_SCANCODE_RETURN: scancode = 0x1c; break;
        case SDL_SCANCODE_RIGHT: scancode = 0x4d; break;
        case SDL_SCANCODE_DOWN: scancode = 0x50; break;
        case SDL_SCANCODE_LCTRL: scancode = 0x1d; break;
    }

    if (scancode)
        memoryASet(0x168, scancode + 3842104, p);
#endif
#ifdef MM2
#else
        auto toggle = [](int a, int b, int p)
        {
            memoryASet(0x168, a, p);
        };
        
        switch (k)
        {
            case SDL_SCANCODE_Q: toggle(0x30b080, 1, p); break;
            case SDL_SCANCODE_W: toggle(0x30b088, 2, p); break;
            case SDL_SCANCODE_E: toggle(0x30b0ec, 3, p); break; // return
            case SDL_SCANCODE_R: toggle(0x30b08c, 4, p); break;
            case SDL_SCANCODE_T: toggle(0x30b08e, 5, p); break;
            case SDL_SCANCODE_Y: toggle(0x30b118, 6, p); break;
            case SDL_SCANCODE_U: toggle(0x30b120, 7, p); break;
            case SDL_SCANCODE_I: toggle(0x30b11d, 8, p); break;
            //case SDL_SCANCODE_O: toggle(0x30b11b, 9, p); break;
            case SDL_SCANCODE_P: toggle(0x30b171, 9, p); break;
            case SDL_SCANCODE_A: toggle(0x20ed81, 9, p); break;
            case SDL_SCANCODE_S: toggle(0x30b08e, 9, p); break;
            case SDL_SCANCODE_D: toggle(0x30b078, 1, p); break;
            case SDL_SCANCODE_F: toggle(0x30b07c, 1, p); break;
            case SDL_SCANCODE_G: toggle(0x30b084, 1, p); break;
            case SDL_SCANCODE_H: toggle(0x30b08c, 1, p); break;

                
            case SDL_SCANCODE_LEFT: toggle(0x30b088, 1, p); break;
            case SDL_SCANCODE_RIGHT: toggle(0x30b089, 1, p); break;
            case SDL_SCANCODE_UP: toggle(0x30b118, 6, p); toggle(0x30b080, 1, p); break;
            case SDL_SCANCODE_DOWN: toggle(0x30b120, 7, p); break;
            case SDL_SCANCODE_SPACE: toggle(0x30b0ec, 3, p); break; // return
                
                
        }
            

#endif
}
void onMouseMove(int x, int y)
{
    mouseX += x/2;
    mouseY += y/2;
//    printf("%d, %d\n", mouseX, mouseY);
    return;
    memoryASet32(0x168, 0x1e36ec, mouseX);
    memoryASet32(0x168, 0x1e36f0, mouseY);
    memoryASet32(0x168, 0x1e0088, mouseX*4);
    memoryASet32(0x168, 0x1e008c, mouseY);
    //    memoryASet32(ds, 0x1e0088, ecx);
    //    memoryASet32(ds, 0x1e008c, edi);

    memoryASet32(0x168, 0x3a1f14, mouseX*12-200);
    memoryASet32(0x168, 0x3a1f18, mouseY*6-100); // new scroll?

    
}
void onMouseButton(int b)
{
    mouseB = b;
}


void out8(int p, int v) {
    if (p >= 0x300 & p <= 0x400 )
    {
        vga.PortWrite8(p, v);
        return;
    }
    //    if (p == 0x226)
    //        return;
    if (p== 0x20 || p == 0x43 || p == 0x201 || p == 0x40)
        return;
    printf("Write port %x %x\n", p, v);
//    stop();
}

void out16(int p, int v) {
    if (p >= 0x300 & p <= 0x400 )
    {
        bool consumed = vga.PortWrite16(p, v);
        if(consumed)
            return;
    }

    //printf("Write16 port %x %x\n", p, v);
//    assert(0);
}

int in8(int port) {
    if (port == 0x3da)
    {
        static uint8_t retrace = 0;
        retrace++;
        return (retrace & 1) ? 9 : 0;
    }
    if (port == 0x22e) // rd avail
        return 0x80;
    if (port == 0x22c) // wr avail
        return 0x80;
    if (port == 0x22a)
    {
        return 0xaa;
    }
    if (port == 0x21)
        return 0;
//    if (port == 0x22e || port == 0x24e || port == 0x26e || port == 0x28e || port == 0x28c)
//        return 0x0;
//    if (port == 0x22a || port == 0x24a || port == 0x26a || port == 0x28a)
//        return 0x0;

    if (port == 0x3c5 || port == 0x3d5)
        return 0;
    if (port == 0x40)
        return 0xe0;
    if (port == 0x201)
        return 0xff;
//    if (port == 0x22c)
//        return 0x0;
    if (port == 0x3cf)
    {
        return vga.PortRead8(port);  // TODO!!!!
    }
    assert(0); return 0;
}


uint8_t memoryVideoGet(int s, int o)
{
//    assert(o - 0xa0000 < 320*240*3);
    return vga.Read(o);
}

uint8_t _memoryAGet(int s, int o)
{
    if (s <= 0x40)
        return memoryPspGet(s, o);
    if (o >= codeObjectBase && o < codeObjectBase + codeObject.size())
        return codeObject[o-codeObjectBase];
    if (o >= dataObjectBase && o < dataObjectBase + dataObject.size())
        return dataObject[o-dataObjectBase];
    if (o >= allocatorBase && o < allocatorBase + allocator.size())
        return allocator[o-allocatorBase];
    if (o >= 0 && o < 0 + zeroSeg.size())
        return zeroSeg[o];
    if (o >= 0xa0000 && o <= 0xa0000 + 320*240) // worms 320*200, mm2 320*240?
        return memoryVideoGet(s, o);
    assert(0);
}


uint8_t memoryAGet(int s, int o)
{
    if (_memoryAGet(s, o) == 'T' && _memoryAGet(s, o+1) == 'R' && _memoryAGet(s, o+2) == 'A'  && _memoryAGet(s, o+3) == 'I')
    {
        for (int i=0; i<40; i++)
            printf("%c", _memoryAGet(s, o+i));
        printf("\n");
        int f=  9;
    }
    return _memoryAGet(s, o);
}

void memoryVideoSet(int s, int o, int v)
{
//    assert(o - 0xa0000 < 320*240*3);
    vga.Write(o, v);
}

void memoryVideoSet32(int s, int o, uint32_t v)
{
    memoryVideoSet(s, o, v & 255);
    memoryVideoSet(s, o+1, (v>>8) & 255);
    memoryVideoSet(s, o+2, (v>>16) & 255);
    memoryVideoSet(s, o+3, (v>>24) & 255);
}

void memoryASet(int s, int o, int v)
{
    assert(s == 0x168);
    if (o >= codeObjectBase && o < codeObjectBase + codeObject.size())
        codeObject[o-codeObjectBase] = v;
    else if (o >= dataObjectBase && o < dataObjectBase + dataObject.size())
        dataObject[o-dataObjectBase] = v;
    else if (o >= allocatorBase && o < allocatorBase + allocator.size())
        allocator[o-allocatorBase] = v;
    else if (o >= 0 && o < zeroSeg.size())
        zeroSeg[o] = v;
    else if (o >= 0xa0000 && o <= 0xa0000 + 320*240) // worms 320*200, mm2 320*240?
        memoryVideoSet(s, o, v);
    else
        assert(0);
}

void sub_1a88e4();
void sub_1b4f37();
void sync()
{
    // mm2
    static int frame = 0;
    memoryASet32(ds, 0x2eebd0, memoryAGet32(ds, 0x2eebd0)+4);
    
    for (int i=0; i<10; i++)
        sub_1a88e4();
    /*
    switch (frame)
    {
        case 1200: memoryASet(0x168, 0x30b0ec, 1); break;
        case 1201: memoryASet(0x168, 0x30b0ec, 0); break;
        case 1250: memoryASet(0x168, 0x30b0ec, 1); break;
        case 1251: memoryASet(0x168, 0x30b0ec, 0); break;
        case 1300: memoryASet(0x168, 0x30b0ec, 1); break;
        case 1301: memoryASet(0x168, 0x30b0ec, 0); break;
        case 1350: memoryASet(0x168, 0x30b0ec, 1); break;
        case 1351: memoryASet(0x168, 0x30b0ec, 0); break;
        case 1400: memoryASet(0x168, 0x30b0ec, 1); break;
        case 1401: memoryASet(0x168, 0x30b0ec, 0); break;
    }
    if (frame++ < 1400)
        return;
     */
    
    // wormsfull
//    assert(ds == 0x168);
//    memoryASet32(ds, 0x22313c, memoryAGet32(ds, 0x22313c)+2);
    vga.sync();
}


void playSound(int seg, uint32_t ofs, int len, int samplerate, const char* fmt)
{
    assert(ofs >= allocatorBase && ofs+len < allocatorBase + allocator.size());
    uint8_t* ptr = &allocator[0] + ofs - allocatorBase;
        
    static bool init = false;
    static SDL_AudioDeviceID devices[16];
//    static SDL_AudioDeviceID dev = 0;
    if (!init)
    {
        SDL_AudioSpec want{};
        want.freq = samplerate;
        want.format = AUDIO_S8;  // signed 8-bit
        want.channels = 1;       // mono
        want.samples = 512;     // internal buffer size
        want.callback = nullptr; // we’ll use SDL_QueueAudio()

        for (int i=0; i<sizeof(devices)/sizeof(devices[0]); i++)
            devices[i] = SDL_OpenAudioDevice(nullptr, 0, &want, nullptr, 0);
//        assert(dev);
        init = true;
    }

    static int counter = 0;
    printf("PLAY: %x %x %x\n", counter, ofs, len);
    SDL_QueueAudio(devices[counter], ptr, len);
    SDL_PauseAudioDevice(devices[counter++], 0);  // start playback
    counter %= sizeof(devices)/sizeof(devices[0]);
}

void init();
void start();

void loadOverlay(const char* image, int base)
{
    if (codeObject.size() == 0)
    {
        codeObject = GetFileContents(std::string("res/") + image);
        assert(codeObject.size());
        codeObjectBase = base;
        memoryTop = base + codeObject.size();
    }
    else if (dataObject.size() == 0)
    {
        dataObject = GetFileContents(std::string("res/") + image);
        assert(dataObject.size());
        dataObjectBase = base;
        memoryTop = base + dataObject.size();
    }
    else
        assert(0);

    memoryTop = (memoryTop + 0xfff) & ~0xfff;
}

int main(int argc, const char * argv[]) {
    allocator.resize(allocatorSize);
    zeroSeg.resize(zeroSegSize);
    sdl.Init();
//    sdl.MouseRelativeMode();
    init();
    start();
    
    return 0;
}
