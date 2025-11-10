//
//  loader.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//
#include <fstream>
//#include <bit>
#include <algorithm>
#include "miniz.h"


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
                execPath.c_str(), execName.c_str(), size,
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

class LoaderLe : public Loader {
#pragma pack(push, 1)
    struct LEHeader_t {
        char  magic[2];         // Magic number for LX/LE/LC
        uint8_t  border;           // Byte ordering for EXE
        uint8_t  worder;           // Word ordering for EXE
        uint32_t level;            // EXE Format Level
        uint16_t cpu;              // CPU
        uint16_t os;               // OS
        uint32_t ver;              // Version of the linear EXE module
        uint32_t mflags;           // Flag bits for the module.
        uint32_t mpages;           // # of physical pages in module
        uint32_t startobj;         // Object # to which the Entry Address is relative.
        uint32_t eip;              // Entry Address of module.
        uint32_t stackobj;         // Object number to which ESP is relative
        uint32_t esp;                  // Starting stack address of module.
        uint32_t pagesize;              // The size of one page for this system.
        uint32_t lastpagesize;     // Bytes on last page (only LE) / Page offset shift (LX)
        uint32_t fixupsize;        // Total size of the fixup information in bytes.
        uint32_t fixupsum;         // Checksum for fixup information.
        uint32_t ldrsize;          // Flag bits for the module.
        uint32_t ldrsum;           // Checksum for loader section.
        uint32_t objtab;           // Object Table offset.
        uint32_t objcnt;           // # of entries in Object Table.
        uint32_t objmap;           // Object Page Table offset. (pageTableOffset)
        uint32_t itermap;          // Object Iterated Pages offset.
        uint32_t rsrctab;          // Resource Table offset.
        uint32_t rsrccnt;          // # of entries in Resource Table.
        uint32_t restab;           // Resident Name Table offset.
        uint32_t enttab;           // Entry Table offset.
        uint32_t dirtab;           // Module Format Directives Table offset.
        uint32_t dircnt;           // # of Module Format Directives in the Table.
        uint32_t fpagetab;         // Fixup Page Table offset.
        uint32_t frectab;          // Fixup Record Table Offset.
        uint32_t impmod;           // Import Module Name Table offset.
        uint32_t impmodcnt;        // # of entries in the Import Module Name Table
        uint32_t impproc;          // Import Procedure Name Table offset.
        uint32_t pagesum;          // Per-Page Checksum Table offset.
        uint32_t datapage;         // Data Pages Offset.
        uint32_t preload;          // # of Preload pages for this module.
        uint32_t nrestab;          // Non-Resident Name Table offset.
        uint32_t cbnrestab;        // # of bytes in the Non-resident name table
        uint32_t nressum;          // Non-Resident Name Table Checksum
        uint32_t autodata;         // Auto Data Segment Object number.
        uint32_t debuginfo;        // Debug Information offset.
        uint32_t debuglen;         // Debug Information length
        uint32_t instpreload;      // # of instance data pages found in the preload section.
        uint32_t instdemand;      // # of instance data pages found in the demand section.
        uint32_t heapsize;         // Heap size added to the Auto DS Object
        uint32_t stacksize;        // Stack size
        uint8_t  res3[8];          // reserved
        uint32_t winresoff;        //
        uint32_t winreslen;        //
        uint16_t Dev386_Device_ID;     //
        uint16_t Dev386_DDK_Version;   //
    };
    struct LEObject_t {
        uint32_t size;
        uint32_t base;
        uint32_t flags;
        uint32_t pageTableIndex;
        uint32_t pageCount;
        uint32_t __paddingCheckTodo;
    };
#pragma pack(pop)
    class Fixup_t
    {
    public:
        enum {
            SOURCE_16BIT_OFFSET_FIXUP = 5,
            SOURCE_32BIT_OFFSET_FIXUP = 7,
            SOURCE_16BIT_SELECTOR_FIXUP = 2,
        };

    private:
        const uint8_t* buffer;
    public:
        Fixup_t(const uint8_t* b) : buffer{b}
        {
        }
        int getSourceType() const
        {
            return buffer[0];
        }
        int getFlags() const
        {
            return buffer[1];
        }
        bool isInternalTarget() {
            return (getFlags() & 0x3) == 0;
        }

        int getSourceOffset() const
        {
            return (int16_t)(buffer[2] | (buffer[3] << 8));
        }
        int getObjectNumber() const
        {
            return buffer[4];
        }
        uint32_t getTargetOffset() const
        {
            switch (getSourceType())
            {
                case SOURCE_16BIT_OFFSET_FIXUP:
                case SOURCE_32BIT_OFFSET_FIXUP:
                    switch (getFlags())
                    {
                        case 0:
                            return buffer[5] | (buffer[6] << 8);
                        case 0x10:
                            return buffer[5] | (buffer[6] << 8) | (buffer[7] << 16) | (buffer[8] << 24);
                        default: assert(0);
                    }
                    break;
                case SOURCE_16BIT_SELECTOR_FIXUP:
                    return 0;
                default:
                    assert(0);
            }

        }

        int getSize() const
        {
            switch (getSourceType())
            {
                case SOURCE_32BIT_OFFSET_FIXUP:
                case SOURCE_16BIT_OFFSET_FIXUP:
                    switch (getFlags())
                    {
                        case 0: return 7;
                        case 0x10: return 7+2;
                        default: assert(0);
                    }
                    break;
                case SOURCE_16BIT_SELECTOR_FIXUP:
                    return 5;
                default:
                    printf("reloc=%x / %x \n", getSourceType(), getFlags());
                    for (int i=0; i<30; i++)
                        printf("%02x ", buffer[i]);

                    // 02 00 [2d 0b] 02
                    // 02 00 a1 0a 02
                    // 02 00 e9 08 02
                    
                    // 07 10 [68 0d] 02 [d0 2b 10 00]
                    // 07 10 62 0d 02 d0
                    printf("\n");
                    assert(0);
            }
            return 0;
        }
    };
/*
    struct LEFixupHead_t
    {
        uint8_t sourceType;
        uint8_t targetFlags;
    };
    struct LEFixup0700_t
    {
        uint8_t sourceType;
        uint8_t targetFlags;
        int16_t sourceOffset;
        uint8_t objectNumber;
        uint16_t targetOffset;
    };
    struct LEFixup0710_t
    {
        uint8_t sourceType;
        uint8_t targetFlags;
        int16_t sourceOffset;
        uint8_t objectNumber;
        uint32_t targetOffset;
    };
*/
    struct LEPage_t
    {
        uint32_t dataOffset;
        uint8_t flags;
        uint32_t size;
    };
    
    struct MemoryObject_t
    {
        uint8_t* data;
        uint32_t size;
        uint32_t base;
    };
    std::vector<uint8_t> mBytes;
    uint8_t* mMzData{nullptr};
    uint8_t* mLeData{nullptr};
    LEHeader_t mHeader;
    size_t mFileSize{0};
    int mLoadAddress{0};
    std::vector<LEObject_t> mObjects;
    std::vector<LEPage_t> mPages;
    std::vector<std::vector<Fixup_t>> mFixups;
    std::vector<MemoryObject_t> mMemoryObjects;
    std::string mName;
    
private:
    uint32_t swap32(uint32_t val) {
        return ((val >> 24) & 0x000000FF) |
               ((val >> 8)  & 0x0000FF00) |
               ((val << 8)  & 0x00FF0000) |
               ((val << 24) & 0xFF000000);
    }
public:
    ~LoaderLe()
    {
//        if (mMzData)
//            free(mMzData);
        mMzData = nullptr;
        mLeData = nullptr;
        mBytes.clear();
        
        for (const MemoryObject_t& mo : mMemoryObjects)
            free(mo.data);
        mMemoryObjects.clear();
    }
    
    virtual bool LoadFile(const char *filename, int loadAddress) override
    {
        mName = filename;
        mLoadAddress = loadAddress;
        mBytes = GetFileContents(mName);
        
        if (mBytes.empty())
        {
            perror("open failed");
            return false;
        }
        mFileSize = mBytes.size();
        mMzData = &mBytes[0];
        
        assert(mMzData[0] == 'M' && mMzData[1] == 'Z');
        
        uint32_t new_header_offset = *((uint32_t*)(mMzData+0x3c));
        assert(new_header_offset < mFileSize);
        
        mLeData = mMzData + new_header_offset;
        memcpy(&mHeader, mLeData, sizeof(LEHeader_t));
        
        // Parse header
        assert(mHeader.magic[0] == 'L' && mHeader.magic[1] == 'E');
        std::vector<uint32_t> bases;
        int curAddress = loadAddress;
        
        for (int i=0; i<mHeader.objcnt; i++)
        {
            LEObject_t leObj = *((LEObject_t*)(mLeData + mHeader.objtab + i*sizeof(LEObject_t)));
            leObj.base = curAddress;
            mObjects.push_back(leObj);
            
            bases.push_back(curAddress);
            int alignedSize = (leObj.size + mHeader.pagesize - 1) & ~(mHeader.pagesize - 1);
            curAddress += alignedSize;
        }
        for (int i=0; i<mHeader.mpages; i++)
        {
            uint32_t data = *(uint32_t*)(mLeData + mHeader.objmap + i*4);
            data = swap32(data);
            assert((data & 0xffff00ff) == 0);
            mPages.push_back({data >> 8, (uint8_t)(data & 0xff), i == mHeader.mpages-1 ? mHeader.lastpagesize : mHeader.pagesize});
        }
        uint32_t* fixupOffsets = (uint32_t*)(mLeData + mHeader.fpagetab);
        for (int i=0; i<mHeader.mpages; i++)
        {
            std::vector<Fixup_t> pageFixups;
            for (int o=fixupOffsets[i]; o<fixupOffsets[i+1];)
            {
                Fixup_t fixup(mLeData + mHeader.frectab + o);
                pageFixups.push_back(fixup);
                o += fixup.getSize();
            }
            mFixups.push_back(pageFixups);
        }
        Relocate();
        return true;
    }
    
    void Relocate()
    {
        assert(mMemoryObjects.size() == 0);
        // Apply relocations
        for (const LEObject_t& leObj : mObjects)
        {
            MemoryObject_t obj{
                .data = (uint8_t*)malloc(leObj.size),
                .size = leObj.size,
                .base = leObj.base
            };
            
            memset(obj.data, 0, leObj.size);
            
            for (int i=0; i<leObj.pageCount; i++)
            {
                int pageIndex = leObj.pageTableIndex+i-1;
                LEPage_t page = mPages[pageIndex];
                uint32_t pageFileOffset = mHeader.datapage + (page.dataOffset-1)*mHeader.pagesize;
                uint32_t pageSize = std::min(mHeader.pagesize, leObj.size - (i)*mHeader.pagesize);
                uint8_t* pageData = obj.data + i*mHeader.pagesize;
                memcpy(pageData, mMzData + pageFileOffset, pageSize);
                
                for (const Fixup_t& fixup : mFixups[pageIndex])
                {
                    uint32_t value = 0;
                    switch (fixup.getSourceType())
                    {
                        case Fixup_t::SOURCE_32BIT_OFFSET_FIXUP:
                            value = fixup.getTargetOffset() + mObjects[fixup.getObjectNumber()-1].base;
                            if (fixup.getSourceOffset() >= 0 && fixup.getSourceOffset() < pageSize)
                                pageData[fixup.getSourceOffset()] = value;
                            if (fixup.getSourceOffset()+1 >= 0 && fixup.getSourceOffset()+1 < pageSize)
                                pageData[fixup.getSourceOffset()+1] = value>>8;
                            if (fixup.getSourceOffset()+2 >= 0 && fixup.getSourceOffset()+2 < pageSize)
                                pageData[fixup.getSourceOffset()+2] = value>>16;
                            if (fixup.getSourceOffset()+3 >= 0 && fixup.getSourceOffset()+3 < pageSize)
                                pageData[fixup.getSourceOffset()+3] = value>>24;
                            break;
                        case Fixup_t::SOURCE_16BIT_OFFSET_FIXUP:
                        case Fixup_t::SOURCE_16BIT_SELECTOR_FIXUP:
                            // TODO: check!
                            value = fixup.getTargetOffset() + mObjects[fixup.getObjectNumber()-1].base;
                            if (fixup.getSourceOffset() >= 0 && fixup.getSourceOffset() < pageSize)
                                pageData[fixup.getSourceOffset()] = value;
                            if (fixup.getSourceOffset()+1 >= 0 && fixup.getSourceOffset()+1 < pageSize)
                                pageData[fixup.getSourceOffset()+1] = value>>8;
                            break;
                        default:
                            assert(0);
                        
                    }
                }
            }
            mMemoryObjects.push_back(obj);
        }
                
        // export relocated overlays
        size_t lastSlash = mName.find_last_of("/\\");
        std::string filenameWithExt = mName.substr(lastSlash + 1);
        size_t lastDot = filenameWithExt.find_last_of('.');
        std::string key = filenameWithExt.substr(0, lastDot);
        
        for (int i=0; i<mMemoryObjects.size(); i++)
        {
            char outname[1024];
            snprintf(outname, sizeof(outname), "%s_%d.bin", key.c_str(), i+1);
            FILE *f = fopen(outname, "wb");
            fwrite(mMemoryObjects[i].data, 1, mMemoryObjects[i].size, f);
            fclose(f);
        }
    }
    
    virtual std::string GetFooter() override
    {
        return "";
    }

    virtual bool InRange(address_t addr, int size = 0) override
    {
        for (const MemoryObject_t& mo : mMemoryObjects)
            if (addr >= mo.base && addr+size < mo.base + mo.size)
                return true;

        return false;
    }
    virtual const uint8_t* GetBufferAt(address_t addr) override
    {
        for (const MemoryObject_t& mo : mMemoryObjects)
            if (addr.offset >= mo.base && addr.offset < mo.base + mo.size)
                return mo.data + addr.offset - mo.base;
        assert(0);
        return nullptr;
    }
    virtual const uint8_t* GetBufferAt(int offset) override
    {
        assert(0);
        return nullptr;
    }
    virtual address_t GetEntry() override
    {
        // TODO: object index as segment?
        // NO: linearAddress would mess it up (int)mHeader.startobj
        return address_t(0x160, mMemoryObjects[mHeader.startobj-1].base + (int)mHeader.eip);
    }
    virtual std::string GetMain() override
    {
        // export relocated overlays
        size_t lastSlash = mName.find_last_of("/\\");
        std::string filenameWithExt = mName.substr(lastSlash + 1);
        size_t lastDot = filenameWithExt.find_last_of('.');
        std::string key = filenameWithExt.substr(0, lastDot);
        // TODO: fix 160/168 addresses
        return format(R"(void init()
{
    ds = 0x0168;
    cs = 0x%04x;
    es = 0x0028;
    ss = 0x0168;
    esp = 0x%x;
    loadOverlay("%s_1.bin", 0x%x);
    loadOverlay("%s_2.bin", 0x%x);
}

void sub_%x();

void start()
{
    sub_%x();
}
)",
    GetEntry().segment,
    mMemoryObjects[mHeader.stackobj-1].base + mHeader.esp,
    key.c_str(), mMemoryObjects[0].base,
    key.c_str(), mMemoryObjects[1].base,
    GetEntry().linearOffset(),
    GetEntry().linearOffset());
}

    void Overlay(address_t addr, const std::vector<uint8_t>& bytes) override
    {
        assert(0);
    }
};
