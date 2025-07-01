//
//  loader.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//
#include <fstream>

//#include <iostream>
//#include <sstream>

class LoaderSnapshot : public Loader {
    uint8_t* mData{nullptr};
    size_t mSize{0};
    int mLoadAddress{0};
    
public:
    virtual bool LoadFile(const char *filename, int loadAddress) override
    {
        mLoadAddress = loadAddress;
        FILE *f = fopen(filename, "rb");
        if (!f) {
            perror("fopen");
            return false;
        }

        fseek(f, 0, SEEK_END);
        mSize = ftell(f);
        rewind(f);

        mData = (uint8_t*)malloc(mSize);
        if (!mData) {
            perror("malloc");
            fclose(f);
            return false;
        }

        fread(mData, 1, mSize, f);
        fclose(f);
        return true;
    }
    
    virtual bool InRange(address_t addr, int size = 0) override
    {
        return addr.linearOffset() - mLoadAddress >= 0 && addr.linearOffset() - mLoadAddress + size < mSize;
    }
    virtual const uint8_t* GetBufferAt(address_t addr) override
    {
        int64_t address = addr.segment*16 + addr.offset;
        assert(address - mLoadAddress >= 0x0 && address - mLoadAddress+16 <= mSize);
        return mData + address - mLoadAddress;
    }
    virtual address_t GetEntry() override
    {
        assert(0);
        return address_t(0, 0);
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

public:
    virtual bool LoadFile(const char* executable, int loadAddress) override
    {
        _loadBase = loadAddress;
        
        std::string strExecutable(executable);
        const size_t lastSlash = strExecutable.find_last_of("\\/");
        std::string execName = std::string::npos != lastSlash ? strExecutable.substr(lastSlash+1) : strExecutable;
        std::string execPath = std::string::npos != lastSlash ? strExecutable.substr(0, lastSlash) : "";
        
        std::ifstream file(strExecutable, std::ios::binary | std::ios::ate);
        
        if (!file)
            return false;
        
        std::streamsize size = file.tellg();
        assert(size >= 1024 && size < 1024*1024);
        file.seekg(0, std::ios::beg);
        
        buffer.resize(size);
        if (!file.read(reinterpret_cast<char*>(buffer.data()), size))
        {
            file.close();
            return false;
        }
        
        header = (MZHeader*)&buffer[0];
        assert(header->id[0] == 'M' && header->id[1] == 'Z');
        
        _linearToFileOffset = _loadBase - header->headerSize16*0x10;
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
    virtual address_t GetEntry() override
    {
        return address_t(header->cs + (_loadBase >> 4), header->ip + (_loadBase % 16));
    }
};
