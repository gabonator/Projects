//
//  loader.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

class Loader {
public:
    virtual const uint8_t* GetBufferAt(address_t addr) = 0;
    virtual bool InRange(address_t addr, int size = 0) = 0;
};

class LoaderSnapshot : public Loader {
    uint8_t* mData{nullptr};
    size_t mSize{0};
    int mLoadAddress{0};
    
public:
    bool LoadFile(const char *filename, int loadAddress)
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

};

