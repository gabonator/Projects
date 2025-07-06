#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

extern uint16_t ax, bx, cx, dx;
extern uint8_t& al, bl, cl, dl;
extern uint8_t& ah, bh, ch, dh;
extern uint16_t cs, ds, es, ss, sp, si, di, bp;
struct flags_t {
  bool carry, zero, interrupts, direction;
};
extern flags_t flags;

extern int headerSize, loadAddress, endAddress;
void start();
void memoryASet(int s, int o, int v);

uint8_t* memory = nullptr; // 1000:0000
int memorySize = 0;
char root[1024] = "";

#include "ega.h"
#include "sdl.h"

CSdl sdl;

class CEgaInstance : public CEga
{
public:
    virtual void sync() override
    {
        for (int y=0; y<200; y++)
          for (int x=0; x<320; x++)
            sdl.SetPixel(x, y, GetPixel(x, y));
        sdl.Loop();
    }
} video;

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

void load(const char* path, const char* file, int size)
{
    path = ".";
    assert(!memory);
    memorySize = (endAddress - loadAddress)*16 + 1024*256; //size-headerSize;
    memory = new uint8_t[memorySize]; // TODO: release
    memset(memory, 0, memorySize);
    
    char fpath[1024];
    strncpy(root, path, 1024);
    snprintf(fpath, 1024, "%s/%s", path, file);
    FILE* f = fopen(fpath, "rb");
    fseek(f, headerSize, SEEK_SET);
    assert(size-headerSize < memorySize);
    fread(memory, size-headerSize, 1, f);
    fclose(f);
}

void memoryASet(int s, int o, int v)
{
    if (s >= 0xa000)
    {
        video.Write(s*16+o, v);
        return;
    }
    int linear = (s-loadAddress)*16 + o;
    if (linear >= 0 && linear < memorySize)
    {
        memory[linear] = v;
        return;
    }
    assert(0);
}
void memoryASet16(int s, int o, int v)
{
    if (s >= 0xa000)
    {
        video.Write(s*16+o, v & 255);
        video.Write(s*16+o+1, v >> 8);
        return;
    }
    int linear = (s-loadAddress)*16 + o;
    if (linear >= 0 && linear+1 < memorySize)
    {
        *((uint16_t*)&memory[linear]) = v;
        return;
    }
    assert(0);
}
uint8_t memoryAGet(int s, int o)
{
    if (s >= 0xa000)
        return video.Read(s*16+o);

    int linear = (s-loadAddress)*16 + o;
    if (linear >= 0 && linear < memorySize)
        return memory[linear];
    assert(0);
    return 0;
}
uint16_t memoryAGet16(int s, int o)
{
    if (s >= 0xa000)
        return video.Read(s*16+o) | (video.Read(s*16+o+1)<<8);

    int linear = (s-loadAddress)*16 + o;
    if (linear >= 0 && linear+1 < memorySize)
        return *((uint16_t*)&memory[linear]);
    assert(0);
    return 0;
}

void interrupt(int i)
{
    static FILE* f = nullptr;
    
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
        
        assert(f == nullptr);
        f = fopen(fullname, "rb");
        if (!f)
        {
            printf("Not found: %s\n", fullname);
            flags.carry = 1;
            ax = 0;
        } else {
            printf("Opening %s\n", fullname);
            flags.carry = 0;
            ax = 1;
        }
        return;
    }
    if (i == 0x21 && ah == 0x3f)
    {
        assert(f);
        assert(ds < 0xa000);
        uint8_t* buf = new uint8_t[cx];
        int c = (int)fread(buf, 1, (size_t)cx, f);
        int linear = (ds-loadAddress)*16 + dx;
        assert (linear >= 0 && linear+c < memorySize);
        memcpy(&memory[linear], buf, c);
        delete[] buf;
        ax = c;
        flags.carry = 0;
        return;
    }
    if (i == 0x21 && ah == 0x3e)
    {
        fclose(f);
        f = nullptr;
        return;
    }
    if (i == 0x10)
    {
        if (video.Interrupt())
            return;
    }
    if (i == 0x21 && ah == 0x25)
        return;
    if (i == 0x21 && ah == 0x35)
        return;
    if (i == 0x33)
    {
        ax = 0;
        return;
    }

    assert(0);
}

void out16(int port, int data)
{
    video.PortWrite16(port, data);
}
void out8(int port, int data)
{
    if (port > 0x300)
        video.PortWrite8(port, data);
}
int in8(int port)
{
    return video.PortRead8(port);
}

int main()
{
    sdl.Init();
    start();
    sdl.Deinit();
    return 0;
}
