#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <string>

std::vector<uint8_t> getFileContents(const std::string& zipPath);

extern uint16_t ax, bx, cx, dx;

#define al *reinterpret_cast<uint8_t*>(&ax)
#define ah *(reinterpret_cast<uint8_t*>(&ax) + 1)
#define bl *reinterpret_cast<uint8_t*>(&bx)
#define bh *(reinterpret_cast<uint8_t*>(&bx) + 1)
#define cl *reinterpret_cast<uint8_t*>(&cx)
#define ch *(reinterpret_cast<uint8_t*>(&cx) + 1)
#define dl *reinterpret_cast<uint8_t*>(&dx)
#define dh *(reinterpret_cast<uint8_t*>(&dx) + 1)

//extern uint8_t& al, bl, cl, dl;
//extern uint8_t& ah, bh, ch, dh;

//uint8_t& al = *reinterpret_cast<uint8_t*>(&ax);
//uint8_t& ah = *(reinterpret_cast<uint8_t*>(&ax) + 1);
//uint8_t& bl = *reinterpret_cast<uint8_t*>(&bx);
//uint8_t& bh = *(reinterpret_cast<uint8_t*>(&bx) + 1);
//uint8_t& cl = *reinterpret_cast<uint8_t*>(&cx);
//uint8_t& ch = *(reinterpret_cast<uint8_t*>(&cx) + 1);
//uint8_t& dl = *reinterpret_cast<uint8_t*>(&dx);
//uint8_t& dh = *(reinterpret_cast<uint8_t*>(&dx) + 1);

extern uint16_t cs, ds, es, ss, sp, si, di, bp;
struct flags_t {
  bool carry, zero, interrupts, direction;
};
extern flags_t flags;

extern int headerSize, loadAddress, endAddress;
void start();
int GetProcAt(int seg, int ofs);
void memoryASet(int s, int o, int v);

uint8_t* memory = nullptr; // 1000:0000
int memorySize = 0;
char root[1024] = "";

#include "ega.h"
#include "font.h"
#include "sdl.h"

CSdl sdl;
class CEgaInstance : public CEga
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) override;
    virtual void sync() override
    {
        for (int y=0; y<200; y++)
          for (int x=0; x<320; x++)
            sdl.SetPixel(x, y, GetPixel(x, y));
        sdl.Loop();
    }
} ega;

class CVgaInstance : public CVga
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) override;
    virtual void sync() override
    {
        for (int y=0; y<200; y++)
          for (int x=0; x<320; x++)
            sdl.SetPixel(x, y, GetPixel(x, y));
        sdl.Loop();
    }
} vga;

class CCgaInstance : public CCga
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) override { assert(0); return 0;}
    virtual void sync() override
    {
        for (int y=0; y<200; y++)
          for (int x=0; x<320; x++)
            sdl.SetPixel(x, y, GetPixel(x, y));
        sdl.Loop();
    }
} cga;

class CTextInstance : public CText
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) override { assert(0); return 0;}
    virtual void sync() override
    {
        for (int y=0; y<200; y++)
          for (int x=0; x<320; x++)
            sdl.SetPixel(x, y, GetPixel(x, y));
        sdl.Loop();
    }
} text;

CVideoAdapter* video = &ega;
void memoryASet16(int s, int o, int v);
uint16_t memoryAGet16(int s, int o);
uint8_t memoryAGet(int s, int o);
void sync()
{
    video->sync();
//    memoryASet16(0x2ec1, 0x2b5e, memoryAGet16(0x2ec1, 0x2b5e) + 1);
    // cc1
//    memoryASet16(0x2ec1, 0x2b60, memoryAGet16(0x2ec1, 0x2b60) + 1);
//    memoryASet16(0x2ec1, 0x2b60, memoryAGet16(0x2ec1, 0x2b60) % 0x200);

    
    // ck4
    int x = memoryAGet16(ds, 0xa53d);
    x += 5;
    memoryASet16(ds, 0xa53d, x);
    if (x >= 0x10000)
        memoryASet16(ds, 0xa53e, memoryAGet16(ds, 0xa53e)+1);
    // ck1
//    memoryASet16(ds, 0x5135, memoryAGet16(ds, 0x5135) + 6);
}

void sub_25f7(int scancode);
int lastKey = 0;
/*
void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    #define MAPKEY( c, v ) if (k==c) memoryASet(0x13a5, 0x8e8a+v, p)
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
*/
/*
void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
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
        case SDL_SCANCODE_SPACE:
            memoryASet(0x1040, 0xa85e, p ? 0 : 0xff);
            
            keys = p ? keys | 16 : keys & ~16; break;
        //case SDL_SCANCODE_LCTRL:
        //case SDL_SCANCODE_RCTRL: slowdown = p;
    }
    memoryASet(0x1040, 0xB884, keys);
}*/
void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    if (strstr(root, "goose."))
    {
        #define MAPKEY( c, v ) if (k==c) memoryASet(0x13a5, 0x8e8a+v, p)
        MAPKEY( SDL_SCANCODE_LEFT, 75 );
        MAPKEY( SDL_SCANCODE_RIGHT, 77 );
        MAPKEY( SDL_SCANCODE_DOWN, 80 );
        MAPKEY( SDL_SCANCODE_UP, 72 );
        MAPKEY( SDL_SCANCODE_SPACE, 57 );
        MAPKEY( SDL_SCANCODE_N, 49 );
        MAPKEY( SDL_SCANCODE_M, 50 );
        MAPKEY( SDL_SCANCODE_Q, 16 );
        MAPKEY( SDL_SCANCODE_Y, 21 );
        #undef MAPKEY
    }
    
    if (strstr(root, "fox."))
    {
        switch (k)
        {
            case SDL_SCANCODE_UP: memoryASet(0x168f, 0x488, p); break; // up
            case SDL_SCANCODE_DOWN: memoryASet(0x168f, 0x490, p); break; // down
            case SDL_SCANCODE_RIGHT: memoryASet(0x168f, 0x48d, p); break; // left
            case SDL_SCANCODE_LEFT: memoryASet(0x168f, 0x48b, p); break; // right
            case SDL_SCANCODE_SPACE: memoryASet(0x168f, 0x45c, p);
                memoryASet(0x168f, 0x042b, p); break; // enter
        }
    }
    
    if (strstr(root, "rick2."))
    {
        static int keys = 0;
        switch (k)
        {
            case SDL_SCANCODE_UP: keys = p ? keys | 8 : keys & ~8; break;
            case SDL_SCANCODE_DOWN: keys = p ? keys | 4 : keys & ~4; break;
            case SDL_SCANCODE_LEFT: keys = p ? keys | 2 : keys & ~2; break;
            case SDL_SCANCODE_RIGHT: keys = p ? keys | 1 : keys & ~1; break;
            case SDL_SCANCODE_SPACE:
                memoryASet(0x1040, 0xa85e, p ? 0 : 0xff);
                keys = p ? keys | 16 : keys & ~16;
                break;
        }
        memoryASet(0x1040, 0xB884, keys);
    }
    
    if (strstr(root, "rick1."))
    {
        static int keys = 0;
        switch (k)
        {
            case SDL_SCANCODE_UP: keys = p ? (keys | 8) : (keys & ~8); break;
            case SDL_SCANCODE_DOWN: keys = p ? (keys | 4) : (keys & ~4); break;
            case SDL_SCANCODE_RIGHT: keys = p ? (keys | 1) : (keys & ~1); break;
            case SDL_SCANCODE_LEFT: keys = p ? (keys | 2) : (keys & ~2); break;
            case SDL_SCANCODE_SPACE:
                memoryASet(0x1040, 0x7e43, 0x39);
                keys = p ? (keys | 16) : (keys & ~16); break; // enter
        }
        memoryASet(0x1040, 0x7e44, keys);
    }
    
    if (strstr(root, "bumpy."))
    {
        switch (k)
        {
            case SDL_SCANCODE_2: memoryASet(0x1228, 0x4d44 + 0x3c, p); break;
            case SDL_SCANCODE_3: memoryASet(0x1228, 0x4d44 + 0x3d, p); break;
            case SDL_SCANCODE_4: memoryASet(0x1228, 0x4d44 + 0x3e, p); break;
            case SDL_SCANCODE_5: memoryASet(0x1228, 0x4d44 + 0x3f, p); break;
            case SDL_SCANCODE_6: memoryASet(0x1228, 0x4d44 + 0x40, p); break;
            case SDL_SCANCODE_7: memoryASet(0x1228, 0x4d44 + 0x41, p); break;
            case SDL_SCANCODE_0: memoryASet(0x1228, 0x4d44 + 0x01, p); break;
            case SDL_SCANCODE_UP: memoryASet(0x1228, 0x4d44 + 'H', p); break;
            case SDL_SCANCODE_RIGHT: memoryASet(0x1228, 0x4d44 + 'M', p); break;
            case SDL_SCANCODE_DOWN: memoryASet(0x1228, 0x4d44 + 'P', p); break;
            case SDL_SCANCODE_LEFT: memoryASet(0x1228, 0x4d44 + 'K', p); break;
            case SDL_SCANCODE_SPACE: memoryASet(0x1228, 0x4d44 + 0x1c, p); break;
        }
    }
    
    if (strstr(root, "cc1."))
    {
        int scancode = -1;
        switch (k)
        {
    case SDL_SCANCODE_UP: memoryASet(ds, 0x338b, p); break;
    case SDL_SCANCODE_LEFT: memoryASet(ds, 0x338e, p); break;
    case SDL_SCANCODE_RIGHT: memoryASet(ds, 0x338f, p); break;
    case SDL_SCANCODE_DOWN: memoryASet(ds, 0x3390, p); break;
            case SDL_SCANCODE_SPACE: lastKey = p;
                //scancode = 0x29 + p * 128;
                memoryASet16(ds, 0x2b5e, p ? 0x29 : 0x29 + 128);
                break; // ? 1 : 0; break; // enter
            case SDL_SCANCODE_N:
//                scancode = 0x31 - 1 + (1-p) * 128;
                memoryASet16(ds, 0x2b5e, p ? 0x31 : 0x31 + 128);
                memoryASet16(ds, 0xa0b4, 0); break;
//            case SDL_SCANCODE_1: scancode = 0x60 + p * 128; break;
//            case SDL_SCANCODE_2: scancode = 12 + p * 128; break;
//            case SDL_SCANCODE_3: scancode = 1 + p * 128; break;
//            case SDL_SCANCODE_4: scancode = 6 + p * 128; break;
            case SDL_SCANCODE_1:
                memoryASet16(ds, 0x2b5e, p ? 1 : 1 + 128);
                memoryASet16(ds, 0xa0b4, 0);
                break;

/*
 kbmap 2ec1:2b40=1 ESC
 kbmap 2ec1:2b41=31 N // xxx crash - new game?
 kbmap 2ec1:2b42=10 Q // quit to dos
 kbmap 2ec1:2b43=17 I // instructions
 kbmap 2ec1:2b44=1f S // galactic encyclopedia
 kbmap 2ec1:2b45=18 O // how to order
 kbmap 2ec1:2b46=23 H // high scores
 kbmap 2ec1:2b47=13 R // restore game
 kbmap 2ec1:2b48=39 ' ' // xxxx crash
 kbmap 2ec1:2b49=1c '\n' // xxx crash
 kbmap 2ec1:2b4a=1e 'A' // about apogee
 kbmap 2ec1:2b4b=2e 'C' // official bbs
 kbmap 2ec1:2b4c=21 'F' // foreign customers
 kbmap 2ec1:2b4d=2f 'V' // video compatibility
 */
        }
        //assert(0);
//        if (scancode != -1)
//        {
////            sub_25f7(scancode);
//            memoryASet16(ds, 0x2b5e, scancode+1);
////            ax = 0;
//            memoryASet16(ds, 0xa0b4, 0);
//
//        }
    }
    if (strstr(root, "keen1."))
    {
        int scancode = 0;
        switch (k)
        {
            case SDL_SCANCODE_SPACE: scancode = 0x39; break;
            case SDL_SCANCODE_UP: scancode = 0x48; break;
            case SDL_SCANCODE_LEFT: scancode = 0x4b; break;
            case SDL_SCANCODE_RIGHT: scancode = 0x4d; break;
            case SDL_SCANCODE_DOWN: scancode = 0x50; break;
            case SDL_SCANCODE_LCTRL: scancode = 0x1d; break;
        }
        if (scancode)
        {
            if (p)
            {
                memoryASet(0x14f2, 0x50ac, scancode);
                memoryASet(0x14f2, 0x50ac, memoryAGet(0x14f2, 0x50ac) | 0x80);
            }
            memoryASet(0x14f2, scancode + 20524, p);
        }
    }
    if (strstr(root, "keen4."))
    {
        int scancode = 0;
        switch (k)
        {
            case SDL_SCANCODE_SPACE: memoryASet(0x30d4, 0xc643, p); break;
            case SDL_SCANCODE_UP: memoryASet(0x30d4, 0xa545, p ? 0x48 : 0); break;
            case SDL_SCANCODE_DOWN: memoryASet(0x30d4, 0xa545, p ? 0x50 : 0); break;
            case SDL_SCANCODE_RETURN: memoryASet(0x30d4, 0xa545, p ? 0x1c : 0);break;

                
        }
    }
}
/*
void onKey(int k, int p)
{
    // rick1
    static int keys = 0;
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
    switch (k)
    {
       
        case SDL_SCANCODE_UP: keys = p ? (keys | 8) : (keys & ~8); break;
        case SDL_SCANCODE_DOWN: keys = p ? (keys | 4) : (keys & ~4); break;
        case SDL_SCANCODE_RIGHT: keys = p ? (keys | 1) : (keys & ~1); break;
        case SDL_SCANCODE_LEFT: keys = p ? (keys | 2) : (keys & ~2); break;
        case SDL_SCANCODE_SPACE:
            memoryASet(0x1040, 0x7e43, 0x39);
            keys = p ? (keys | 16) : (keys & ~16); break; // enter
            
        case SDL_SCANCODE_Z: keys = p ? (keys | 128) : (keys & ~128); break; // PAUSE
        case SDL_SCANCODE_X: keys = p ? (keys | 64) : (keys & ~64); break; // ESC
    }
    memoryASet(0x1040, 0x7e44, keys);
}

*/


void load(const char* path_, const char* file, int size)
{
    strcpy(root, file);
    for (int i=0; root[i]; i++)
    {
        if (root[i] >= 'A' && root[i] < 'Z')
            root[i] = root[i] - 'A' + 'a';
        if (root[i] == '.')
        {
            root[i] = 0;
            break;
        }
    }
    strcat(root, ".zip");
    
    assert(!memory);
    memorySize = (endAddress - loadAddress)*16 + 1024*256*8; //size-headerSize;
    memory = new uint8_t[memorySize]; // TODO: release
    memset(memory, 0, memorySize);
    
    //strncpy(root, path, 1024);
    char fpath[1024];
    snprintf(fpath, 1024, "%s/%s", root, file);
    std::vector<uint8_t> bytes = getFileContents(fpath);
    assert(!bytes.empty());
    assert(size-headerSize < memorySize);
    memcpy(memory, &bytes[headerSize], size-headerSize);
    
//    FILE* f = fopen(fpath, "rb");
//    fseek(f, headerSize, SEEK_SET);
//    assert(size-headerSize < memorySize);
//    fread(memory, size-headerSize, 1, f);
//    fclose(f);
}

void memoryASet(int s, int o, int v)
{
    if (s*16+o == 0x2ec10 + 0x4615)
    {
        int f = 9;
    }
    int proc = GetProcAt(s, o);
    if(proc!=0)
    {
        printf("Writing to code %04x:%0x in sub_%x(), prev %02x, new %02x\n", s, o, proc,
               memoryAGet(s, o), v);
    }

    if (s == 0x7777)
    {
        if (o >= 0xa0000)
        {
            video->Write(o, v);
            return;
        }
        int linear = o;
        if (linear >= 0 && linear < memorySize)
        {
            memory[linear] = v;
            return;
        }
        assert(0);
    }
    assert(o <= 0xffff);
//    if (sp != 0xeeee)
//    {
//        int p = GetProcAt(s, o);
//        if (p)
//        {
//            printf("Writing to code sub_%x, mem=%x:%x=%x value=%x\n", p, s, o, s*16+o, v);
//            assert(0);
//        }
//    }
    if (s >= 0xa000)
    {
        video->Write(s*16+o, v);
        return;
    }
    int linear = (s-loadAddress)*16 + o;
    if (linear >= 0 && linear < memorySize)
    {
        memory[linear] = v;
        return;
    }
    if (s == 0x40)
    {
        // ignore
        return;
    }
    assert(0);
}
void memoryASet16(int s, int o, int v)
{
    if (s*16+o == 0x14f20 + 0x6052)
    {
        int f = 9;
    }

    o &= 0xffff;
    assert(o <= 0xffff);
    int p = GetProcAt(s, o);

//    if (sp != 0xeeee)
//    {
//        int p = GetProcAt(s, o);
//        if (!p)
//            p = GetProcAt(s, o+1);
        if (p)
        {
            printf("Writing to code sub_%x, mem=%x:%x=%x prev=%x new=%x\n", p, s, o, s*16+o,
                   memoryAGet16(s, o), v);
//            assert(0);
        }
//    }
    if (s >= 0xa000)
    {
        video->Write(s*16+o, v & 255);
        video->Write(s*16+o+1, v >> 8);
        return;
    }
    int linear = (s-loadAddress)*16 + o;
    if (linear >= 0 && linear+1 < memorySize)
    {
        *((uint16_t*)&memory[linear]) = v;
        return;
    }
    if (s == 0x0040 && o == 0x004e)
        return;
    if (s == 0x0000 && o == 0x0090)
        return;
    if (s == 0x0000 && o == 0x0092)
        return;
    if (s == 0x0000 && o == 0x0018)
        return;
    if (s == 0x0000 && o == 0x001a)
        return;
    if (s == 0x0000 && o < 400)
        return;
    if (s == 0x0040 && o == 0x001a)
        return;
    if (s == 0x0040 && o == 0x001c)
        return;
    if (s == 0x0000)
    {
        printf("skip bios write %x:%x = %x\n", s, o, v);
        return;
    }

    assert(0);
}
uint8_t memoryAGet(int s, int o)
{
    o &= 0xffff;
    assert(o <= 0xffff);
    if (s >= 0xf000)
    {
        if (s == 0xf000 && o >= 0xfa6e && o < (0xfa6e + sizeof(cga_font)))
            return cga_font[o-0xfa6e];
        assert(0);
    }
    if (s >= 0xa000)
        return video->Read(s*16+o);

    int linear = (s-loadAddress)*16 + o;
    if (linear >= 0 && linear < memorySize)
        return memory[linear];
    
    if (s == loadAddress - 0x1a)
    {
        const char env[] = "PATH=Z:\\" "\x00" "COMSPEC=Z:\\COMMAND.COM" "\x00"
          "BLASTER=A220 I7 D1 H5 T6" "\x00\x00\x01\x00" "C:\\BUM\\B.EXE"
          "\x00\x00\x00\x00\x00\x00\x00";
        if (o < sizeof(env))
            return env[o];
        assert(0);
        return 0; // env
    }
    if (s == loadAddress - 0x10 && o == 0x80)
        return 0;
    if (s == loadAddress - 0x10 && o == 0x81)
        return 0x0d;
    if (s == 0x0040 && o == 0x0010)
        return 0x26;
    if (s == 0x0040 && o == 0x0087)
        return 0x00;
    if (s == 0x0040 && o == 0x006c)
    {
        auto getTick = []() -> uint32_t {
            struct timespec ts;
            unsigned theTick = 0U;
            clock_gettime( CLOCK_REALTIME, &ts );
            theTick  = ts.tv_nsec / 1000000;
            theTick += ts.tv_sec * 1000;
            return theTick;
        };

        return getTick()/54; // 0xd1; // number of ticks since midnight 54ms
    }
    if (s == 0x0000 && o == 0x0000)
        return 0x1a;

    assert(0);
    return 0;
}
uint16_t memoryAGet16(int s, int o)
{
    if (s==0x11b2 && o==0x084d)
    {
        int f= 9;
    }
    o &= 0xffff;
    assert(o <= 0xffff);
    
    if (s >= 0xf000)
    {
        if (s == 0xf000 && o >= 0xfa6e && o < (0xfa6e + sizeof(cga_font)))
            return cga_font[o-0xfa6e] | (cga_font[o-0xfa6e + 1]<<8);
        assert(0);
    }

    if (s >= 0xa000)
        return video->Read(s*16+o) | (video->Read(s*16+o+1)<<8);

    int linear = (s-loadAddress)*16 + o;
    if (linear >= 0 && linear+1 < memorySize)
        return *((uint16_t*)&memory[linear]);
    
    if (s == 0x0040 && o == 0x0063)
        return 0x3d4;
    if (s == 0x0000 && o == 0x0018)
        return 0;
    if (s == 0x0000 && o == 0x001a)
        return 0;
    if (s == 0x0000 && o < 400)
        return 0;
    if (s == loadAddress - 0x10 && o == 2)
        return 0x9fff; // Segment of the first byte beyond the memory allocated to the program
    if (s == loadAddress - 0x10 && o == 0x2c)
        return loadAddress - 0x1a; // Segment of the first byte beyond the memory allocated to the program
    if (s == loadAddress - 0x1a)
    {
        return memoryAGet(s, o) | (memoryAGet(s, o+1) << 8); // env
    }
    if (s == 0x0040 && o == 0x0080)
        return 0x1e;
    if (s == 0x0000 && o == 0x041a)
        return 0x00;

    if (s == 0x0000 && o == 0x0487)
        return 0x60;
    assert(0);
    return 0;
}
uint32_t memoryAGet32(int s, int o)
{
    int a = memoryAGet16(s, o);
    int b = memoryAGet16(s, o+2);
    int c = a | (b<<16);
    return c;
    //return memoryAGet16(s, o) | (memoryAGet16(s, o+2)<<16);
}

void interrupt(int i)
{
    struct fileslot_t {
        bool opened{false};
        int handle{-1};
        int offset{0};
        char name[1024] = {0};
        std::vector<uint8_t> data;
    };
    static fileslot_t slots[32];
    static int slotCounter = 0;
    
    //static FILE* f = nullptr;
    //static std::vector<uint8_t> currentFile;
    //static int currentFileOffset;
    
    if (i == 0x12)
    {
        ax = 0x800;
        return;
    }
    if (i == 0x21 && ah == 0x09)
    {
        for (int i=0; memoryAGet(ds, dx+i) != '$'; i++)
            printf("%c", memoryAGet(ds, dx+i));
        return;
    }
    if (i == 0x21 && ah == 0x3d)
    {
        char filename[32];
        int j = 0;
        for (int i=0; i<16; i++)
        {
            char c = memoryAGet(ds, dx+i);
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
        
        char fullname[1024];
        strcpy(fullname, root);
        strcat(fullname, "/");
        strcat(fullname, filename);
        for (int i=0; i<1024 && fullname[i]; i++)
            if (fullname[i] == '\\')
                fullname[i] = '/';
        
//        if (!currentFile.empty())
//        {
//            printf("Warning single file not closed!\n");
//            currentFile.clear();
//        }
//        assert(currentFile.empty());
        assert(slotCounter < sizeof(slots)/sizeof(slots[0]));
        
        std::vector<uint8_t> data = getFileContents(fullname);

        if (data.empty())
        {
            printf("Not found: %s\n", fullname);
            flags.carry = 1;
            ax = 0;
        } else {

            slots[slotCounter].opened = true;
            slots[slotCounter].handle = 0xb0+slotCounter;
            slots[slotCounter].offset = 0;
            strncpy(slots[slotCounter].name, fullname, sizeof(slots[slotCounter].name));
            slots[slotCounter].data = std::move(data);

            ax = slots[slotCounter].handle;
            flags.carry = 0;
            printf("Opening %s as %x\n", fullname, ax);
            slotCounter++;
        }
        return;
    }
    if (i == 0x21 && ah == 0x3f)
    {
        fileslot_t& slot = slots[bx-0xb0];
        assert(slot.handle == bx);
        assert(slot.opened);
        assert(ds < 0xa000);
//        uint8_t* buf = new uint8_t[cx];
        
        int c = cx;
        if (c > slot.data.size() - slot.offset)
            c = slot.data.size() - slot.offset;
        if (c <= 0)
        {
            ax = 0;
            assert(c==0);
            flags.carry = 0;
            return;
        }
        //memcpy()
        //int c = (int)fread(buf, 1, (size_t)cx, f);
        int linear = (ds-loadAddress)*16 + dx;
        assert (linear >= 0 && linear+c < memorySize);
        //memcpy(&memory[linear], buf, c);
        memcpy(&memory[linear], &slot.data[slot.offset], c);
        slot.offset += c;
//        delete[] buf;
        ax = c;
        flags.carry = 0;
        return;
    }
    if (i == 0x21 && ah == 0x3e)
    {
        fileslot_t& slot = slots[bx-0xb0];
        assert(slot.handle == bx);
        assert(slot.opened);

        printf("Closing %s as %x\n", slot.name, slot.handle);
        slot.data.clear();
        slot.opened = false;
        return;
    }
    if (i == 0x21 && ah == 0x42 && al == 0x00)
    {
        fileslot_t& slot = slots[bx-0xb0];
        assert(slot.handle == bx);
        assert(slot.opened);

        if (slot.data.empty())
        {
            flags.carry = 1;
            return;
        }
        assert(!slot.data.empty());
        slot.offset = cx*0x10000 + dx;
        assert(slot.offset <= slot.data.size());
        flags.carry = 0;
        return;        
    }
    if (i == 0x21 && ah == 0x42 && al == 0x01)
    {
        fileslot_t& slot = slots[bx-0xb0];
        assert(slot.handle == bx);
        assert(slot.opened);
        assert(slot.data.empty());

        slot.offset += cx*0x10000 + dx;
        assert(slot.offset <= slot.data.size());
        flags.carry = 0;
        return;
    }
    if (i == 0x21 && ah == 0x42 && al == 0x02)
    {
        fileslot_t& slot = slots[bx-0xb0];
        assert(slot.handle == bx);
        assert(slot.opened);
        assert(slot.data.empty());

        assert(cx == 0 && dx == 0);
        slot.offset = slot.data.size();
        ax = slot.offset & 0xffff;
        dx = slot.offset >> 16;
        flags.carry = 0;
        return;
    }
    if (i == 0x21 && ah == 0x43)
    {
        // CHANGE mode
        printf("change mode: ");
        for (int i=0; i<20 && memoryAGet(ds, dx+i); i++)
            printf("%c", memoryAGet(ds, dx+i));
        printf("\n");
        flags.carry = 0;
        if (al == 0)
            cx = 0;
        return;
    }

    if (i == 0x10)
    {
        if (ah == 0x00)
        {
            printf("Setting video mode 0x%02x\n", al);
            switch (al)
            {
                case 0x13: video = &vga; break;
                case 0x0d: video = &ega; break;
                case 0x02: video = &ega; break; // bumpy?
                case 0x04: video = &cga; break;
                    
                case 0x03:  // cc1
                case 0x10: video = &text; break;
                default:
                    assert(0);
            }
        }
//        test();
        if (video->Interrupt())
            return;
    }
    if (i == 0x21 && ah == 0x25)
    {
        printf("Set int vector - %02x to %04x:%04x\n", al, ds, dx);
        return;
    }
    if (i == 0x21 && ah == 0x35)
        return;
    if (i == 0x33)
    {
        ax = 0;
        return;
    }
    if (i == 0x21 && ah == 0x4a)
    {
        flags.carry = false;
        return;
    }
    if (i == 0x21 && ah == 0x48)
    {
        static int freeMem = 0x4000; //0x1D9E;
        // _bx size
        printf("malloc %d bytes -> %04x:0000\n", bx, freeMem);
        ax = freeMem;
        freeMem += bx;
        freeMem ++;
        flags.carry = false;
        return;

        return;
//        flags.carry = true;
        ax = endAddress+0x100+0x4000-0x1d80;
        printf("malloc %d bytes -> %04x:0000\n", bx, ax);
        endAddress += bx + 1;
        flags.carry = false;
        assert((loadAddress - endAddress)*16 < memorySize);
        
        //static int freeMem = 0x1D9E; // TODO:!!!!
//        static int freeMem = 0x4000;
//        // _bx size
//        printf("malloc %d bytes -> %04x:0000\n", ctx->b.r16, freeMem);
//        ctx->a.r16 = freeMem;
//        freeMem += ctx->b.r16;
//        freeMem ++;
//        ctx->carry = false;
        return;
    }
    if (i == 0x1a && ah == 0x04)
        return;
    if (i == 0x21 && ah == 0x30)
    {
        ax = 0x0005;
        bx = 0xff00;
        cx = 0x0000;
        return;
    }
    if (i == 0x1a && ah == 0)
    {
        printf("skip timer\n");
        cx = 0;
        dx = 0;
        return;
    }
    if (i == 0x21 && ah == 0x44)
    {
        ax = 0x80d3;
        dx = 0x80d3; // TODO!
        flags.carry = 0;
        return;
    }
    if (i == 0x11)
    {
        ax = 0;
        return;
    }
    if (i == 0x21 && ah == 0x0b)
    {
        al = 0;
        //ctx->a.r8.l = keyBuffer.empty() ? 0 : 0xff; // check key
        return;
    }
    if (i == 0x21 && ah == 0x2c)
    {
        printf("get time\n");
        ch = 1; // hr
        cl = 20; // min
        dh = 17; // sec
        dl = 50; // hundredths
        return;
    }
    if (i == 0x16 && ah == 0x01)
    {
        flags.zero = lastKey == 0;
        return;
    }
    if (i == 0x21 && ah == 0x40)
    {
        //write file
        printf("Write file:");
        for (int i=0; i<cx; i++)
            printf("%c", memoryAGet(ds, dx+i));
        printf("\n");
        ax = cx;
        flags.carry = false;
        return;
    }
    if (i==0x2f)
        return;

    assert(0);
}

void out16(int port, int data)
{
    video->PortWrite16(port, data);
}
void out8(int port, int data)
{
    if (port == 0x388 || port == 0x389) //audio
        return;

    if (port > 0x300)
        video->PortWrite8(port, data);
}
int in8(int port)
{
    if (port == 0x201 || port == 0x61)
        return 0;
    if (port == 0x388) //audio
        return 0x60;
    if (port == 0x40)
    {
        static int counter = 0;
        return (counter++ & 2) ? 0xff:0x00;
    }

    return video->PortRead8(port);
}

uint8_t CEgaInstance::ReadMemory(int seg, int ofs)
{
    return memoryAGet(seg, ofs);
}
uint8_t CVgaInstance::ReadMemory(int seg, int ofs)
{
    return memoryAGet(seg, ofs);
}

#ifdef __APPLE__
void SuppressAppleEvents();
#endif

//int main()
int main(int argc, char* argv[])
{
#ifdef __APPLE__
    SuppressAppleEvents();
#endif

//    NSApplicationMain(); // NSDocumentRevisionsDebugMode
    sdl.Init();
    start();
    sdl.Deinit();
    return 0;
}


#include "lib/miniz.h"

std::vector<uint8_t> readFileFromZip(const std::string& zipPath, std::string fileName)
{
    FILE* f = fopen(zipPath.c_str(), "rb");
    if (!f)
    {
        f = fopen(fileName.c_str(), "rb");
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
        printf("GABO-ERROR cant open '%s'\n", zipPath.c_str());
        assert(0);
        return {};
    }
    

    fseek(f, 0, SEEK_END);
    size_t zipSize = ftell(f);
    rewind(f);

    std::vector<uint8_t> zipData(zipSize);
    fread(zipData.data(), 1, zipSize, f);
    fclose(f);

    mz_zip_archive zip = {};
    if (!mz_zip_reader_init_mem(&zip, zipData.data(), zipData.size(), 0))
    {
        assert(0);
        return {};
    }

    if (fileName.starts_with("./"))
        fileName = fileName.substr(2);
    
    int fileIndex = mz_zip_reader_locate_file(&zip, fileName.c_str(), nullptr, 0);
    if (fileIndex < 0)
        return {};

    size_t uncompressedSize = 0;
    void* p = mz_zip_reader_extract_to_heap(&zip, fileIndex, &uncompressedSize, 0);
    if (!p)
        return {};

    std::vector<uint8_t> buffer((uint8_t*)p, (uint8_t*)p + uncompressedSize);

    mz_free(p);
    mz_zip_reader_end(&zip);

    return buffer;
}

std::vector<uint8_t> getFileContents(const std::string& fullPath)
{
    size_t pos = fullPath.find_last_of("/");
    assert (pos != std::string::npos);
    return readFileFromZip(fullPath.substr(0, pos), fullPath.substr(pos+1));
}
