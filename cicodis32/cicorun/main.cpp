#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <string>

std::vector<uint8_t> getFileContents(const std::string& zipPath);

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

CVideoAdapter* video = &ega;

void sync()
{
    video->sync();
}

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
    assert(0);
}
void memoryASet16(int s, int o, int v)
{
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

    assert(0);
}
uint8_t memoryAGet(int s, int o)
{
    o &= 0xffff;
    assert(o <= 0xffff);
    if (s==cs && o==1)
    {
        int f= 9;
    }
    if (s >= 0xa000)
        return video->Read(s*16+o);

    int linear = (s-loadAddress)*16 + o;
    if (linear >= 0 && linear < memorySize)
        return memory[linear];
    assert(0);
    return 0;
}
uint16_t memoryAGet16(int s, int o)
{
    o &= 0xffff;
    assert(o <= 0xffff);
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

    assert(0);
    return 0;
}

void interrupt(int i)
{
    //static FILE* f = nullptr;
    static std::vector<uint8_t> currentFile;
    static int currentFileOffset;
    
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
        
        assert(currentFile.empty());
        currentFile = getFileContents(fullname);
        currentFileOffset = 0;

        if (currentFile.empty())
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
        assert(!currentFile.empty());
        assert(ds < 0xa000);
//        uint8_t* buf = new uint8_t[cx];
        
        int c = cx;
        if (c > currentFile.size() - currentFileOffset)
            c = currentFile.size() - currentFileOffset;
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
        memcpy(&memory[linear], &currentFile[currentFileOffset], c);
        currentFileOffset += c;
//        delete[] buf;
        ax = c;
        flags.carry = 0;
        return;
    }
    if (i == 0x21 && ah == 0x3e)
    {
        currentFile.clear();
        //fclose(f);
//        f = nullptr;
        return;
    }
    if (i == 0x21 && ah == 0x42 && al == 0x00)
    {
        assert(!currentFile.empty());
        currentFileOffset = cx*0x10000 + dx;
        flags.carry = 0;
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
                default:
                    assert(0);
            }
        }
        if (video->Interrupt())
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
    if (i == 0x21 && ah == 0x4a)
    {
        flags.carry = false;
        return;
    }
    if (i == 0x21 && ah == 0x48)
    {
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
    if (port == 0x201 || port == 0x40 || port == 0x61)
        return 0;
    if (port == 0x388) //audio
        return 0x60;

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
