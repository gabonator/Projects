#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <list>
#include <vector>

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


extern uint16_t cs, ds, es, ss, sp, si, di, bp;
struct flags_t {
  bool carry, zero, interrupts, direction;
};
extern flags_t flags;

extern int headerSize, loadAddress, endAddress;
void init();
void start();
int GetProcAt(int seg, int ofs);
void memoryASet(int s, int o, int v);

uint8_t* memory = nullptr; // 1000:0000
int memorySize = 0;
char root[1024] = "";

#include "ega.h"
#ifndef HEADLESS
#include "sdl.h"
#endif

#ifndef HEADLESS
CSdl sdl;
#endif
int frameCounter = 0;
int frameCounterTerminate = 0;

class CEgaInstance : public CEga
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) override;
    virtual void sync() override
    {
      if (frameCounterTerminate==++frameCounter) {
        for (int y=0; y<200; y++)
            for (int x=0; x<320; x++) {
              uint32_t clr = GetPixel(x, y);
              fputc(clr&255, stderr);
              fputc((clr>>8)&255, stderr);
              fputc((clr>>16)&255, stderr);
            }
        exit(1);

    }

#ifndef HEADLESS
        for (int y=0; y<200; y++)
          for (int x=0; x<320; x++)
            sdl.SetPixel(x, y, GetPixel(x, y));
        static int temp = 0;
        temp = (temp+1)%320;
        sdl.SetPixel(temp, 0, 0xff0000ff);
        sdl.SetPixel(temp, 1, 0xff0000ff);
        sdl.SetPixel(temp, 2, 0xff0000ff);
        sdl.Loop();
#endif
    }
} ega;
/*
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
*/
CVideoAdapter* video = &ega;
void memoryASet16(int s, int o, int v);
uint16_t memoryAGet16(int s, int o);
uint8_t memoryAGet(int s, int o);
void sync()
{
    if (frameCounterTerminate==++frameCounter) {
      exit(1);
    }
printf("frame %d\n", frameCounter);
#ifndef HEADLESS
    video->sync();
#endif
}

std::list<char> keyBuffer;
int lastKey = 0;
void onKey(int k, int p)
{
#ifndef HEADLESS

    if (k == SDL_SCANCODE_ESCAPE) exit(1);
    if (1)
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
    //lastKey
#endif
}

void load(const char* path_, const char* file, int size)
{
    memorySize = (endAddress - loadAddress)*16 + 1024*256*8; //size-headerSize;
    assert(!memory);
    memory = new uint8_t[memorySize]; // TODO: release
    memset(memory, 0, memorySize);

    std::vector<uint8_t> bytes = getFileContents(file);
    assert(!bytes.empty());
    assert(size-headerSize < memorySize);
    memcpy(memory, &bytes[headerSize], size-headerSize);
}


void memoryASet(int s, int o, int v)
{

    o &= 0xffff;
    assert( s != 0x7777);
    assert(o <= 0xffff);
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
    if (s*16+o == 0x075d0 + 0xcc52+2)
    {
        int f = 9;
    }

    o &= 0xffff;
    assert(o <= 0xffff);
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
    if (s == 0x0040 && o == 0x0017)
        return;
    if (s == 0x0040 && o == 0x0050)
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
    if (s == 0x30d4 && o == 0xc6dd)
    {
        int f = 9;
    }
    o &= 0xffff;
    assert(o <= 0xffff);
    if (s >= 0xf000)
    {
//        if (s == 0xf000 && o >= 0xfa6e && o < (0xfa6e + sizeof(cga_font)))
//            return cga_font[o-0xfa6e];
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
    if (s == 0x0040 && o == 0x004a)
        return 80; // screen columns
//https://wiki.nox-rhea.org/back2root/ibm-pc-ms-dos/hardware/informations/bios_data_area
    if (s == 0x0040 && o == 0x0049)
        return 3; // current video mode
    assert(0);
    return 0;
}
uint16_t memoryAGet16(int s, int o)
{
    if (s*16+o == 0x075d0 + 0xcc52+2)
    {
        int f = 9;
    }

    if (s == 0x30d4 && o == 0xc6dd)
    {
        int f= 9;
    }
    o &= 0xffff;
    assert(o <= 0xffff);
    
    if (s >= 0xf000)
    {
//        if (s == 0xf000 && o >= 0xfa6e && o < (0xfa6e + sizeof(cga_font)))
//            return cga_font[o-0xfa6e] | (cga_font[o-0xfa6e + 1]<<8);
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
    if (s == 0x0040 && o == 0x006c)
        return 0x123; // ticks since midnight
    if (s == 0x0040 && o == 0x0017)
        return 0x0000; // keyboard shift status
    if (s == 0x0040 && o == 0x0050)
        return 0x0000; // ??

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
        strcpy(fullname, filename);
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
//                case 0x13: video = &vga; break;
                case 0x0d: video = &ega; break;
//                case 0x02: video = &ega; break; // bumpy?
//                case 0x04: video = &cga; break;
                    
                case 0x03:  // cc1
//                case 0x10: video = &text; break;
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
        // no mouse
        ax = 0;
        // mouse
        //ax = 0xffff;
        //bx = 3;
        return;
    }
    if (i == 0x21 && ah == 0x4a)
    {
        // TODO: freemem shift
        flags.carry = false;
        return;
    }
    if (i == 0x21 && ah == 0x48)
    {
        if (bx>=0xf000)
        {
            bx = 0x810c;
            flags.carry = true;
            return;
        }
        assert (bx < 0xf000);
        // golden axe 1ef3

        //static int freeMem = 0x1ef3; //TODO!!!0x4000; //0x1D9E;
        static int freeMem = 0x4000;
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
//        al = 0;
        al = keyBuffer.empty() ? 0 : 0xff; // check key
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
    if (i == 0x16 && ah == 0x02)
    {
        flags.zero = true;
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
    if (i==0x21 && ah == 0x1a)
    {
        // INT 21,1A - Set Disk Transfer Address (DTA)
        printf("Set Disk Transfer Address %04x:%04x\n", ds, dx);
        return;
    }
    if (i==0x21 && ah == 0x4c)
    {
        exit(1);
    }
    if (i == 0x21 && ah == 0x07)
    {
        assert(!keyBuffer.empty());
        al = keyBuffer.front(); // key stdin
        keyBuffer.pop_front();
        return;
    }
    if (i == 0x21 && ah == 0x3c)
    {
        flags.carry = 1;
        return;
    }

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
//uint8_t CVgaInstance::ReadMemory(int seg, int ofs)
//{
//    return memoryAGet(seg, ofs);
//}

//int main()
int main(int argc, char* argv[])
{
    if (argc == 2)
      frameCounterTerminate = atoi(argv[1]);

#ifndef HEADLESS
    sdl.Init();
#endif
    init();
    start();
#ifndef HEADLESS
    sdl.Deinit();
#endif
    return 0;
}


std::vector<uint8_t> getFileContents(const std::string& fullPath)
{
    // Simple fopen - files should be in the app's root directory
    FILE* file = fopen((std::string("dos/")+fullPath).c_str(), "rb");
    if (!file) {
        return {};
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    if (fileSize <= 0) {
        fclose(file);
        return {};
    }
    
    // Read the file contents
    std::vector<uint8_t> data(fileSize);
    size_t bytesRead = fread(data.data(), 1, fileSize, file);
    fclose(file);
    
    if (bytesRead != (size_t)fileSize) {
        return {};
    }
    
    return data;
}
