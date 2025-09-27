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
std::vector<uint8_t> zeroSeg;

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
void sub_1c7c4c();

#include "ega.h"
#include "sdl.h"

CSdl sdl;

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

class CVgaInstance : public CVga
{
public:
    virtual uint8_t ReadMemory(int seg, int ofs) { assert(0); return 0; }
    virtual void sync() override
    {
        for (int y=0; y<200; y++)
          for (int x=0; x<320; x++)
            sdl.SetPixel(x, y, GetPixel(x, y));
        sdl.Loop();
    }
} vga;

void out8(int p, int v) {
    if (p == 0x3c8 || p == 0x3c9)
    {
        vga.PortWrite8(p, v);
        return;
    }
    printf("Write port %x %x\n", p, v);
//    stop();
}



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

uint8_t memoryAGet(int s, int o)
{
    if (o==0x3a2672)
    {
        int f=9;
    }

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
        return codeObject[o-0x196000];
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
    if (s == 0x168 && o == 0x3f4f0a)
    {
        int f = 9;
    }

    memoryASet(s, o, v & 255);
    memoryASet(s, o+1, (v>>8) & 255);
    memoryASet(s, o+2, (v>>16) & 255);
    memoryASet(s, o+3, (v>>24) & 255);
}
uint16_t memoryAGet16(int s, int o)
{
    if (s == 0x168 && o == 0x3f4ed8)
    {
        int f = 9;
    }
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

void sync()
{
    memoryASet32(ds, 0x3a7470, memoryAGet32(ds, 0x3a7470) + 2);
    vga.sync();
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    codeObject = GetFileContents("wrms1.bin");
    dataObject = GetFileContents("wrms2.bin");
    allocator.resize(0x100000);
    zeroSeg.resize(0x100);
//    dataObject.resize(dataObject.size() + 0x100000);
    //dataObject.insert(dataObject.end(), 0x10000, 0);
//    FILE *f = fopen("/Users/gabrielvalky/Documents/git/Projects/cicodis32/jit3/wrms1.bin", "wb");
//    fwrite(mMemoryObjects[0].data, 1, mMemoryObjects[0].size, f);
//    fclose(f);
//    f = fopen("/Users/gabrielvalky/Documents/git/Projects/cicodis32/jit3/wrms2.bin", "wb");
//    fwrite(mMemoryObjects[1].data, 1, mMemoryObjects[1].size, f);
//    fclose(f);

    sdl.Init();
    
    eax=ebx=ecx=edx=edi=ebp=0;
    esp=0x3f4f60;
    //si=160, sp=3f4f60
    ds=0x168; cs=0x160; es=0x0028; ss=0x168;
    sub_1c7c4c();
//    entry 160:1c7c4c
    return 0;
}
