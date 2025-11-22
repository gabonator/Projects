//
//  loader.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//
#include <fstream>
//#include <bit>
#include <algorithm>
#include "lib/miniz.h"


std::vector<uint8_t> Loader::GetFileContents(std::string fullPath)
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

    size_t pos = fullPath.find_last_of("/");
    assert (pos != std::string::npos);
    std::string zipPath = fullPath.substr(0, pos);
    std::string fileName = fullPath.substr(pos+1);

    f = fopen(zipPath.c_str(), "rb");
    assert(f);
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

class LoaderSnapshot : public Loader {
    std::vector<uint8_t> mBytes;
    int mLoadAddress{0};
    
public:
    virtual bool LoadFile(const char *filename, int loadAddress) override
    {
        mBytes = GetFileContents(filename);
        if (mBytes.empty())
        {
            perror("open failed");
            return false;
        }
        
        mLoadAddress = loadAddress;
        return true;
    }
    
    virtual bool InRange(address_t addr, int size = 0) override
    {
        return addr.linearOffset() - mLoadAddress >= 0 && addr.linearOffset() - mLoadAddress + size < mBytes.size();
    }
    virtual const uint8_t* GetBufferAt(address_t addr) override
    {
        int64_t address = addr.segment*16 + addr.offset;
        assert(address - mLoadAddress >= 0x0 && address - mLoadAddress+16 <= mBytes.size());
        return &mBytes[0] + address - mLoadAddress;
    }
    virtual const uint8_t* GetBufferAt(int offset) override
    {
        assert(0);
        return nullptr;
    }
    virtual address_t GetEntry() override
    {
        assert(0);
        return address_t(0, 0);
    }
    virtual std::string GetMain() override
    {
        return "";
    }
    virtual std::string GetFooter() override
    {
        return "";
    }
    void Overlay(address_t addr, const std::vector<uint8_t>& bytes) override
    {
        assert(0);
    }
};

class LoaderMz : public Loader {
    std::vector<uint8_t> buffer;
    int _loadBase;
    int _linearToFileOffset;

    struct MZHeader
    {
        char id[2];
        uint16_t lastPageBytes;
        uint16_t full512Pages;
        uint16_t relocations;
        uint16_t headerSize16;
        uint16_t minMemory;
        uint16_t maxMemory;
        uint16_t ss;
        uint16_t sp;
        uint16_t checksum;
        uint16_t ip;
        uint16_t cs;
        uint16_t relocationOffset;
        uint16_t overlayNumber;
    };
    struct MZRelocation
    {
        uint16_t offset;
        uint16_t segment;
    };

    MZHeader* header = nullptr;
    std::string strExecutable;
    std::streamsize size;
    size_t realSize;

public:
    virtual bool LoadFile(const char* executable, int loadAddress) override
    {
        _loadBase = loadAddress;
        strExecutable = executable;
                
//        std::ifstream file(strExecutable, std::ios::binary | std::ios::ate);
//        
//        if (!file)
//            return false;
//        
//        size = file.tellg();
//        assert(size >= 1024 && size < 1024*1024);
//        file.seekg(0, std::ios::beg);
//        
//        buffer.resize(size+16);
//        memset(&buffer[0], 0, size+16);
//        if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
//        {
//            file.close();
//            return false;
//        }

        buffer = GetFileContents(strExecutable);
        if (buffer.empty())
        {
            perror("open failed");
            return false;
        }
        
        // append extra 16 dummy bytes, match with GetBufferAt
        realSize = buffer.size();
        buffer.resize(buffer.size()+16);
        
        size = buffer.size();
        header = (MZHeader*)&buffer[0];
        assert(header->id[0] == 'M' && header->id[1] == 'Z');
        
        _linearToFileOffset = _loadBase - header->headerSize16*0x10;
        Relocate();
        return true;
    }
    
    virtual bool InRange(address_t addr, int size = 0) override
    {
        return addr.linearOffset() - _linearToFileOffset >= 0 && addr.linearOffset() - _linearToFileOffset + size < buffer.size();
    }
    virtual const uint8_t* GetBufferAt(address_t addr) override
    {
        int rel = addr.linearOffset() - _linearToFileOffset;
        assert(rel >= 0x0 && rel+16 <= buffer.size());
        return &buffer[rel];
    }
    virtual const uint8_t* GetBufferAt(int offset) override
    {
        assert(offset >= 0x0 && offset+16 <= buffer.size());
        return &buffer[offset];
    }
    virtual address_t GetEntry() override
    {
        return address_t(header->cs + (_loadBase >> 4), header->ip + (_loadBase % 16));
    }
    
    virtual std::string GetMain() override
    {
        bool _dumpReloc{true};
        const size_t lastSlash = strExecutable.find_last_of("\\/");
        std::string execName = std::string::npos != lastSlash ? strExecutable.substr(lastSlash+1) : strExecutable;
        std::string execPath = std::string::npos != lastSlash ? strExecutable.substr(0, lastSlash) : "";

        std::string strMain = format(R"(void init()
{
    headerSize = 0x%04x;
    loadAddress = 0x%04x;
    endAddress = 0x%04x;
    cs = 0x%04x;
    ds = 0x%04x;
    es = 0x%04x;
    ss = 0x%04x;
    sp = 0x%04x;
    load("%s", "%s", %d);%s
}

void start()
{
    sub_%x();
}
)",
                header->headerSize16*16,
                _loadBase/16,
                _loadBase/16+header->full512Pages*512/16,
                header->cs+_loadBase/16,
                header->cs+_loadBase/16 - 0x10,
                header->cs+_loadBase/16 - 0x10,
                header->ss+_loadBase/16,
                header->sp,
                execPath.c_str(), execName.c_str(), realSize,
                _dumpReloc ? "\n    fixReloc(loadAddress);" : "",
                (_loadBase/16+header->cs)*16+header->ip);
                
        std::string strForward = format("void fixReloc(uint16_t seg);\nvoid sub_%x();\n\n", (_loadBase/16+header->cs)*16+header->ip);
        
        return strForward + strMain + "\n"; //+ strReloc + "\n";
    }
    
    virtual std::string GetFooter() override
    {
        std::string strReloc = "void fixReloc(uint16_t seg)\n{\n";
        
        for (int i=0; i<header->relocations; i++)
        {
            MZRelocation* reloc = (MZRelocation*)&buffer[header->relocationOffset+i*4];
            int linearOffset = reloc->segment*16 + reloc->offset + header->headerSize16*16;
            uint16_t* addr = (uint16_t*)&buffer[linearOffset];
            if (reloc->segment == 0)
                strReloc += format("    memoryASet16(seg, 0x%04x, memoryAGet16(seg, 0x%04x) + seg); // %04x -> %04x; lin=%x\n",
                       reloc->offset, reloc->offset, *addr - _loadBase/16, *addr, reloc->segment*16+reloc->offset);
            else
                strReloc += format("    memoryASet16(0x%04x + seg, 0x%04x, memoryAGet16(0x%04x + seg, 0x%04x) + seg); // %04x -> %04x; lin=%x\n",
                   reloc->segment, reloc->offset, reloc->segment, reloc->offset, *addr - _loadBase/16, *addr, reloc->segment*16+reloc->offset);
        }

        strReloc += "}\n";
        
        return strReloc;
    }

    
    void Relocate()
    {
        for (int i=0; i<header->relocations; i++)
        {
            MZRelocation* reloc = (MZRelocation*)&buffer[header->relocationOffset+i*4];
            int linearOffset = reloc->segment*16 + reloc->offset + header->headerSize16*16;
            uint16_t* addr = (uint16_t*)&buffer[linearOffset];
            *addr += _loadBase/16;
        }
    }

    void Overlay(address_t addr, const std::vector<uint8_t>& bytes) override
    {
        // GetBufferAt
        int rel = addr.linearOffset() - _linearToFileOffset;
        assert(rel >= 0x0 && rel+16 <= buffer.size());
        uint8_t* buf = &buffer[rel];

        memcpy(buf, &bytes[0], bytes.size());
    }
};

#include "loaderLe.h"
#include "loaderPe.h"
