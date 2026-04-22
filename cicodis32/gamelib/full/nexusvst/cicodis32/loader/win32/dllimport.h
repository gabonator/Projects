// dllimport.h
// Utility to open a Windows DLL and list all exported symbols (by ordinal/name)

#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include <cassert>
#include <map>

struct DllExportSymbol {
    std::string name;
    uint32_t    ordinal;
    uint32_t    rva;
};

class DllImport {
    std::vector<uint8_t> mBytes;
public:
    bool LoadFile(std::string filename) {
        std::ifstream ifs(filename, std::ios::binary);
        if (!ifs) return false;
        mBytes = std::vector<uint8_t>(std::istreambuf_iterator<char>(ifs), {});
        return !mBytes.empty();
    }

    void Dump()
    {
        for (auto& sym : ListExports())
        {
            printf("alleg40.dll exports %s as ordinal_%d\n", sym.name.c_str(), sym.ordinal);
        }
    }
    
    std::map<int, std::string> GetOrdinals()
    {
        std::map<int, std::string> aux;
        for (auto& sym : ListExports())
            aux.insert({sym.ordinal, sym.name});
        return aux;
    }
    
    std::vector<DllExportSymbol> ListExports() const {
        std::vector<DllExportSymbol> exports;
        if (mBytes.size() < 0x100) return exports;
        // DOS header - check MZ signature
        if (mBytes[0] != 'M' || mBytes[1] != 'Z') return exports;
        uint32_t pe_offset = *(uint32_t*)&mBytes[0x3c];
        if (pe_offset + 0x100 > mBytes.size()) return exports;
        // PE Signature
        if (!(mBytes[pe_offset] == 'P' && mBytes[pe_offset+1] == 'E' && 
              mBytes[pe_offset+2] == 0 && mBytes[pe_offset+3] == 0)) return exports;
        
        // Read COFF header
        uint16_t optHdrSize = *(uint16_t*)(&mBytes[pe_offset+20]);
        if (optHdrSize < 96) return exports; // Optional header too small
        
        // Check optional header magic
        uint16_t optMagic = *(uint16_t*)(&mBytes[pe_offset+24]);
        bool pe32 = (optMagic == 0x10b);
        bool pe64 = (optMagic == 0x20b);
        if (!pe32 && !pe64) return exports;
        
        // Data directory is at different offsets for PE32 vs PE64
        // PE32: optional_header + 96 bytes
        // PE64: optional_header + 112 bytes
        uint32_t dataDirBase = pe_offset + 24 + (pe32 ? 96 : 112);
        if (dataDirBase + 8 > mBytes.size()) return exports;
        
        // First data directory entry is Export Table
        uint32_t exportRVA = *(uint32_t*)(&mBytes[dataDirBase]);
        uint32_t exportSize = *(uint32_t*)(&mBytes[dataDirBase+4]);
        if (!exportRVA || !exportSize) return exports;
        // Section header search - convert RVA to file offset
        auto rvaToFile = [&](uint32_t rva) -> const uint8_t* {
            if (rva == 0) return nullptr;
            // Number of sections is in COFF header at offset 6
            uint16_t nSec = *(uint16_t*)(&mBytes[pe_offset+6]);
            // Section table starts after COFF header (20 bytes) + optional header
            uint16_t optHdrSize = *(uint16_t*)(&mBytes[pe_offset+20]);
            uint32_t secHdrBase = pe_offset + 24 + optHdrSize;
            
            for (int i=0; i<nSec; i++) {
                uint32_t secOffset = secHdrBase + i*40;
                if (secOffset + 40 > mBytes.size()) return nullptr;
                
                const uint8_t* sh = &mBytes[secOffset];
                uint32_t virtualSize = *(uint32_t*)(sh+8);
                uint32_t virtualAddr = *(uint32_t*)(sh+12);
                uint32_t rawSize = *(uint32_t*)(sh+16);
                uint32_t rawAddr = *(uint32_t*)(sh+20);
                
                // Check if RVA falls within this section
                if (rva >= virtualAddr && rva < virtualAddr + virtualSize) {
                    uint32_t offset = rawAddr + (rva - virtualAddr);
                    if (offset < mBytes.size()) {
                        return &mBytes[offset];
                    }
                    return nullptr;
                }
            }
            return nullptr;
        };
        const uint8_t* exportDir = rvaToFile(exportRVA);
        if (!exportDir) return exports;
        uint32_t nFuncs = *(uint32_t*)(exportDir+20);
        uint32_t nNames = *(uint32_t*)(exportDir+24);
        uint32_t addrFunc = *(uint32_t*)(exportDir+28);
        uint32_t addrNames = *(uint32_t*)(exportDir+32);
        uint32_t addrOrdinals = *(uint32_t*)(exportDir+36);
        uint32_t baseOrdinal = *(uint32_t*)(exportDir+16);
        for (uint32_t i=0; i<nFuncs; ++i) {
            DllExportSymbol sym;
            sym.ordinal = i + baseOrdinal;
            const uint8_t* funcAddrPtr = rvaToFile(addrFunc);
            if (!funcAddrPtr) break;
            sym.rva = *(uint32_t*)(funcAddrPtr + i*4);
            sym.name = "";
            exports.push_back(sym);
        }
        // Assign names
        const uint8_t* namesTable = rvaToFile(addrNames);
        const uint8_t* ordinalsTable = rvaToFile(addrOrdinals);
        if (namesTable && ordinalsTable) {
            for (uint32_t i=0; i<nNames; ++i) {
                uint32_t nameRVA = *(uint32_t*)(namesTable + i*4);
                const char* nameStr = (const char*)rvaToFile(nameRVA);
                uint16_t ordIdx = *(uint16_t*)(ordinalsTable + i*2);
                if (nameStr && ordIdx < exports.size()) {
                    exports[ordIdx].name = nameStr;
                }
            }
        }
        return exports;
    }
};
