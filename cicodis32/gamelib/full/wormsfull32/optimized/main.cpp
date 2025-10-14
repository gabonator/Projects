//
//  main.cpp
//  cico32run
//
//  Created by Gabriel Valky on 23/09/2025.
//

#include <iostream>
#include <stdint.h>
#include <assert.h>

std::vector<uint8_t> dataObject;
std::vector<uint8_t> codeObject;
std::vector<uint8_t> allocator;
std::vector<uint8_t> allocator2;
std::vector<uint8_t> zeroSeg;
int codeObjectBase = 0;
int dataObjectBase = 0;
int allocatorBase = 0x400000 - 0x187000;
int allocatorSize = 0x140000;
int zeroSegSize = 0xa000;
int memoryTop = 0;

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

class CVgaInstance : public CVga
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) { assert(0); return 0; }
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
//
//    size_t pos = fullPath.find_last_of("/");
//    assert (pos != std::string::npos);
//    std::string zipPath = fullPath.substr(0, pos);
//    std::string fileName = fullPath.substr(pos+1);
//
//    f = fopen(zipPath.c_str(), "rb");
//    assert(f);
//    fseek(f, 0, SEEK_END);
//    size_t zipSize = ftell(f);
//    rewind(f);
//
//    std::vector<uint8_t> zipData(zipSize);
//    fread(zipData.data(), 1, zipSize, f);
//    fclose(f);
//
//    mz_zip_archive zip = {};
//    if (!mz_zip_reader_init_mem(&zip, zipData.data(), zipData.size(), 0))
//    {
//        assert(0);
//        return {};
//    }
//
//    if (fileName.starts_with("./"))
//        fileName = fileName.substr(2);
//
//    int fileIndex = mz_zip_reader_locate_file(&zip, fileName.c_str(), nullptr, 0);
//    if (fileIndex < 0)
//        return {};
//
//    size_t uncompressedSize = 0;
//    void* p = mz_zip_reader_extract_to_heap(&zip, fileIndex, &uncompressedSize, 0);
//    if (!p)
//        return {};
//
//    std::vector<uint8_t> buffer((uint8_t*)p, (uint8_t*)p + uncompressedSize);
//
//    mz_free(p);
//    mz_zip_reader_end(&zip);
//
//    return buffer;
}

void memoryASet(int s, int o, int v);
uint8_t memoryAGet(int s, int o);

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


#if 0
extern int mouseX;
extern int mouseY;
extern int mouseB;

void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
}
void onMouseMove(int x, int y)
{
    mouseX = x/2;
    mouseY = y/2;
    
}
void onMouseButton(int b)
{
    mouseB = b;
}


void out8(int p, int v) {
    if (p == 0x3c8 || p == 0x3c9)
    {
        vga.PortWrite8(p, v);
        return;
    }
    printf("Write port %x %x\n", p, v);
//    stop();
}



uint8_t memoryAGet(int s, int o)
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
    if (s == 0x160)
    {
        if (o >= 0x196000 && o < 0x196000 + codeObject.size())
            return codeObject[o-0x196000];
    }
    
    assert(s == 0x168);
    if (o >= 0x1d1000 && o < 0x1d1000 + dataObject.size()) // 0x1d1000+2244480= 3F4F80h
        return dataObject[o-0x1d1000];
    if (o >= 0x196000 && o < 0x196000 + codeObject.size())
    {
//        printf("read code @ %x\n", o-0x196000 );
        return codeObject[o-0x196000];
    }
    if (o >= 0x15d000 && o < 0x15d000 + allocator.size())
        return allocator[o-0x15d000];

    assert(0);
}
void memoryASet(int s, int o, int v)
{
    
    if (o==0x3a2672)
    {
        int f=9;
    }
    assert(s == 0x168);
    if (o >= 0xa0000 && o < 0xf0000)
    {
        vga.Write(o, v);
        return;
    }
    if (o >= 0x1d1000 && o < 0x1d1000 + dataObject.size())
    {
        dataObject[o-0x1d1000] = v;
        return;
    }
    if (o >= 0x196000 && o < 0x196000 + codeObject.size())
    {
        if (o-0x196000 == 0x2cef8)
        {
            int f = 9;
        }
//        printf("write    code @ %x\n", o-0x196000 );
        codeObject[o-0x196000] = v;
        return;
    }
    if (o >= 0x15d000 && o < 0x15d000 + allocator.size())
    {
        allocator[o-0x15d000] = v;
        return;
    }
    if (o >= 0 && o < zeroSeg.size())
    {
        zeroSeg[o] = v;
        return;
    }

    assert(0);
}

void sync()
{
    memoryASet32(ds, 0x3a7470, memoryAGet32(ds, 0x3a7470) + 2);
    vga.sync();
}

void sub_1c7c4c();


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    codeObject = GetFileContents("wrms1.bin");
    dataObject = GetFileContents("wrms2.bin");
    allocator.resize(0x100000);
    zeroSeg.resize(0x100);
    sdl.Init();
    
    eax=ebx=ecx=edx=edi=ebp=0;
    esp=0x3f4f60;
    //si=160, sp=3f4f60
    ds=0x168; cs=0x160; es=0x0028; ss=0x168;
    sub_1c7c4c();
//    entry 160:1c7c4c
    return 0;
}
#endif


#if 0
// mm2
void init();
void start();

void onMouseMove(int x, int y)
{
}
void onMouseButton(int b)
{
}
void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
//    memoryASet(0x168, 0x30b080, p);
    auto toggle = [](int a, int b, int p)
    {
        memoryASet(0x168, a, p);
//        b = 1<<(b-1);
//        if (p)
//            memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | b);
//        else
//            memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) & ~b);
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
        
    /*
     memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | 0x40)
     al = memoryAGet(ds, 0x30b080);
     if (!al)
         goto loc_1bdf4b;
     memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | 0x40);
 loc_1bdf4b: // 0160:1bdf4b
     al = memoryAGet(ds, 0x30b088);
     if (!al)
         goto loc_1bdf5f;
     memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | 0x20);
 loc_1bdf5f: // 0160:1bdf5f
     al = memoryAGet(ds, 0x30b0ec);
     if (al)
         goto loc_1bdf79;
     al = memoryAGet(ds, 0x30b08c);
     if (!al)
         goto loc_1bdf80;
 loc_1bdf79: // 0160:1bdf79
     memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | 0x80);
 loc_1bdf80: // 0160:1bdf80
     al = memoryAGet(ds, 0x30b08e);
     if (!al)
         goto loc_1bdf94;
     memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | 0x10);
 loc_1bdf94: // 0160:1bdf94
     if (memoryAGet(ds, 0x30b118) == 0x00)
         goto loc_1bdfa4;
     memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | 0x01);
 loc_1bdfa4: // 0160:1bdfa4
     if (memoryAGet(ds, 0x30b120) == 0x00)
         goto loc_1bdfb4;
     memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | 0x02);
 loc_1bdfb4: // 0160:1bdfb4
     if (memoryAGet(ds, 0x30b11d) == 0x00)
         goto loc_1bdfc4;
     memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | 0x08);
 loc_1bdfc4: // 0160:1bdfc4
     if (memoryAGet(ds, 0x30b11b) == 0x00)
         goto loc_1bdfd4;
     memoryASet(ds, 0x20c840, memoryAGet(ds, 0x20c840) | 0x04);
 loc_1bdfd4: // 0160:1bdfd4

     */
}
// Overlay1: base 0x1a8000 size 0x43f5f
// Overlay2: base 0x1ec000 size 0x12c570

uint8_t memoryAGet(int s, int o)
{
    if (o == 0x30b088)
    {
        int f = 9;
    }
    if (o == 0x30B070 || o ==0x2eebe8 || (o >3190896 && o <3190896+128))
    {
        int f = 9;
    }
    /*
     bl += memoryAGet(ds, 0x2eebe8);
     memoryASet(ds, 0x2eebe8, 0x00);
     al = ~al;
     al >>= 7;
     memoryASet(ds, ebx + 3190896, al); // 30B070h
     ah = memoryAGet(ds, 0x30b0a8);

     */
    if (o >= 0xa0000 && o < 0xa0000 + 320*200*2)
        return vga.Read(o);

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

    if (s == 0x160 && o >= 0x1a8000 && o < 0x1a8000 + codeObject.size())
        return codeObject[o-0x1a8000];
    if (s == 0x168 && o >= 0x1ec000 && o < 0x1ec000 + dataObject.size())
        return dataObject[o-0x1ec000];
    if (o >= 0x15d000 && o < 0x15d000 + allocator.size())
        return allocator[o-0x15d000];
    if (o >= 0x319000 && o < 0x319000 + allocator2.size())
        return allocator2[o-0x319000];
    if (o >= 0 && o < zeroSeg.size())
        return zeroSeg[o];
if (o >= 0xc9000)
    return 0; // TODO
    assert(0);
}
void memoryASet(int s, int o, int v)
{
    if (o == 0x20c840)
    {
        int f =9;
    }
    if (o == 0x30b11d)
    {
        int f = 9;
    }

    if (o >= 0xa0000 && o < 0xa0000 + 320*200*2)
    {
        vga.Write(o, v);
        return;
    }

    if (/*s == 0x160 &&*/ o >= 0x1a8000 && o < 0x1a8000 + codeObject.size())
    {
        codeObject[o-0x1a8000] = v;
        return;
    }
    if (s == 0x168 && o >= 0x1ec000 && o < 0x1ec000 + dataObject.size()) //1230192
    {
        dataObject[o-0x1ec000] = v;
        return;
    }
    if (o >= 0x15d000 && o < 0x15d000 + allocator.size())
    {
        allocator[o-0x15d000] = v;
        return;
    }
    if (o >= 0x319000 && o < 0x319000 + allocator2.size())
    {
        allocator2[o-0x319000] = v;
        return;
    }
    if (o >= 0 && o < zeroSeg.size())
    {
        zeroSeg[o] = v;
        return;
    }
    if (o >= 0xc0000 && o < 0x180000)
        return;
    assert(0);
}


void out8(int p, int v) {
    if (p == 0x3c8 || p == 0x3c9 || p == 0x3ce || p == 0x3cf || p == 0x3d4 || p == 0x3d5)
    {
        vga.PortWrite8(p, v);
        return;
    }
    printf("Write8 port %x %x\n", p, v);
//    stop();
}
void out16(int p, int v) {
    
    if (p==0)
        return;
    if (p == 0x3c4 || p == 0x3ce)
    {
        bool consumed = vga.PortWrite16(p, v);
        if(consumed)
            return;
    }
    printf("Write16 port %x %x\n", p, v);
    //assert(0);
}


void sync()
{
    memoryASet32(ds, 0x3a7470, memoryAGet32(ds, 0x3a7470) + 2);
    memoryASet32(ds, 0x2eebd0, memoryAGet32(ds, 0x2eebd0) + 4);
//    int clk = memoryASet32(ds, 0x2eebd0
    vga.sync();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    codeObject = GetFileContents("/Users/gabrielvalky/Documents/git/Projects/cicodis32/jit3/mm21.bin");
    dataObject = GetFileContents("/Users/gabrielvalky/Documents/git/Projects/cicodis32/jit3/mm22.bin");
    allocator.resize(0x100000);
    allocator2.resize(0x200000);
    zeroSeg.resize(0x35000); //(0x1000 + 0x9a70+0x4000+0x4000);0x22d41
    sdl.Init();
    
    eax=ebx=ecx=edx=edi=ebp=0;
//    esp=0x3f4f60;
    //si=160, sp=3f4f60
//    ds=0x168; cs=0x160; es=0x0028; ss=0x168;
    init();
    start();
    return 0;
}
#endif



extern int mouseX;
extern int mouseY;
extern int mouseB;

void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);

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
    if (p == 0x3c8 || p == 0x3c9 )
    {
        vga.PortWrite8(p, v);
        return;
    }
//    if (p == 0x226)
//        return;
    printf("Write port %x %x\n", p, v);
//    stop();
}

void out16(int p, int v) {
    
    printf("Write16 port %x %x\n", p, v);
    assert(0);
}


uint8_t memoryAGet(int s, int o)
{
    assert(s > 0x40);
    if (o >= codeObjectBase && o < codeObjectBase + codeObject.size())
        return codeObject[o-codeObjectBase];
    if (o >= dataObjectBase && o < dataObjectBase + dataObject.size())
        return dataObject[o-dataObjectBase];
    if (o >= allocatorBase && o < allocatorBase + allocator.size())
        return allocator[o-allocatorBase];
    if (o >= 0 && o < 0 + zeroSeg.size())
        return zeroSeg[o];
    assert(0);
}

void memoryVideoSet(int s, int o, int v)
{
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
    else if (o >= dataObjectBase && o < dataObjectBase + dataObject.size()) // 0x1d1000+2244480= 3F4F80h
        dataObject[o-dataObjectBase] = v;
    else if (o >= allocatorBase && o < allocatorBase + allocator.size())
        allocator[o-allocatorBase] = v;
    else if (o >= 0 && o < zeroSeg.size())
        zeroSeg[o] = v;
    else
        assert(0);
}

void sync()
{
    //memoryASet32(ds, 0x3a7470, memoryAGet32(ds, 0x3a7470) + 2);
//    memoryASet32(ds, 0x1e36fc, memoryAGet32(ds, 0x1e36fc)+2);
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
        codeObject = GetFileContents(std::string("/Users/gabrielvalky/Documents/git/Projects/cicodis32/jit3/") + image + ".bin");
        assert(codeObject.size());
        codeObjectBase = base;
        memoryTop = base + codeObject.size();
    }
    else if (dataObject.size() == 0)
    {
        dataObject = GetFileContents(std::string("/Users/gabrielvalky/Documents/git/Projects/cicodis32/jit3/") + image + ".bin");
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
    sdl.MouseRelativeMode();
    init();
    start();
    
    return 0;
}
