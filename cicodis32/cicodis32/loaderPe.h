//
//  loaderLe.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 15/11/2025.
//

#include <map>
#include "win32/dllimport.h"
#include "win32/dlldecl.h"

class LoaderPe : public Loader {
#pragma pack(push, 1)
    struct DOSHeader {
        char     e_magic[2];    // "MZ"
        uint16_t e_cblp;
        uint16_t e_cp;
        uint16_t e_crlc;
        uint16_t e_cparhdr;
        uint16_t e_minalloc;
        uint16_t e_maxalloc;
        uint16_t e_ss;
        uint16_t e_sp;
        uint16_t e_csum;
        uint16_t e_ip;
        uint16_t e_cs;
        uint16_t e_lfarlc;
        uint16_t e_ovno;
        uint16_t e_res[4];
        uint16_t e_oemid;
        uint16_t e_oeminfo;
        uint16_t e_res2[10];
        uint32_t e_lfanew; // Offset to PE header
    };
    struct PEHeader {
        char Signature[4]; // "PE\0\0"
    };
    struct COFFHeader {
        uint16_t Machine;
        uint16_t NumberOfSections;
        uint32_t TimeDateStamp;
        uint32_t PointerToSymbolTable;
        uint32_t NumberOfSymbols;
        uint16_t SizeOfOptionalHeader;
        uint16_t Characteristics;
    };
    struct OptionalHeader {
        uint16_t Magic;
        uint8_t  MajorLinkerVersion;
        uint8_t  MinorLinkerVersion;
        uint32_t SizeOfCode;
        uint32_t SizeOfInitializedData;
        uint32_t SizeOfUninitializedData;
        uint32_t AddressOfEntryPoint;
        uint32_t BaseOfCode;
        uint32_t BaseOfData;
        uint32_t ImageBase;
        uint32_t SectionAlignment;
        uint32_t FileAlignment;
        uint16_t MajorOSVersion;
        uint16_t MinorOSVersion;
        uint16_t MajorImageVersion;
        uint16_t MinorImageVersion;
        uint16_t MajorSubsystemVersion;
        uint16_t MinorSubsystemVersion;
        uint32_t Win32VersionValue;
        uint32_t SizeOfImage;
        uint32_t SizeOfHeaders;
        uint32_t CheckSum;
        uint16_t Subsystem;
        uint16_t DllCharacteristics;
        uint32_t SizeOfStackReserve;
        uint32_t SizeOfStackCommit;
        uint32_t SizeOfHeapReserve;
        uint32_t SizeOfHeapCommit;
        uint32_t LoaderFlags;
        uint32_t NumberOfRvaAndSizes;
    };
    struct SectionHeader {
        char     Name[8];
        uint32_t VirtualSize;
        uint32_t VirtualAddress;
        uint32_t SizeOfRawData;
        uint32_t PointerToRawData;
        uint32_t PointerToRelocations;
        uint32_t PointerToLinenumbers;
        uint16_t NumberOfRelocations;
        uint16_t NumberOfLinenumbers;
        uint32_t Characteristics;
    };
#pragma pack(pop)
    struct Section {
        std::string name;
        uint32_t vaddr;
        uint32_t vsize;
        std::vector<uint8_t> data;
    };
    
    std::map<address_t, std::shared_ptr<import_t>> mImports;

    std::vector<uint8_t> mBytes;
    std::vector<Section> mSections;
    uint32_t mImageBase{0};
    uint32_t mEntryPoint{0};
    std::string mName;

public:
    virtual const std::map<address_t, std::shared_ptr<import_t>>& GetImports() override
    {
        return mImports;
    }
    
    virtual bool LoadFile(const char* filename, int loadAddress) override {
        mName = filename;
        mBytes = GetFileContents(mName);
        if (mBytes.empty()) {
            perror("open failed");
            return false;
        }
        // Parse DOS header
        if (mBytes.size() < sizeof(DOSHeader)) return false;
        const DOSHeader* dos = (const DOSHeader*)&mBytes[0];
        if (!(dos->e_magic[0] == 'M' && dos->e_magic[1] == 'Z')) return false;
        uint32_t pe_offset = dos->e_lfanew;
        if (pe_offset + sizeof(PEHeader) + sizeof(COFFHeader) > mBytes.size()) return false;
        const PEHeader* pe = (const PEHeader*)(&mBytes[pe_offset]);
        if (!(pe->Signature[0] == 'P' && pe->Signature[1] == 'E')) return false;
        const COFFHeader* coff = (const COFFHeader*)(&mBytes[pe_offset + sizeof(PEHeader)]);
        const OptionalHeader* opt = (const OptionalHeader*)(&mBytes[pe_offset + sizeof(PEHeader) + sizeof(COFFHeader)]);
        mImageBase = opt->ImageBase;
        mEntryPoint = opt->AddressOfEntryPoint;
        // Get section headers
        uint32_t secHdrOff = pe_offset + sizeof(PEHeader) + sizeof(COFFHeader) + coff->SizeOfOptionalHeader;
        for (int i = 0; i < coff->NumberOfSections; i++) {
            if (secHdrOff + i * sizeof(SectionHeader) + sizeof(SectionHeader) > mBytes.size()) break;
            const SectionHeader* sh = (const SectionHeader*)(&mBytes[secHdrOff + i * sizeof(SectionHeader)]);
            Section sec;
            sec.name = std::string(sh->Name, strnlen(sh->Name, 8));
            sec.vaddr = sh->VirtualAddress;
            sec.vsize = sh->VirtualSize;
//            printf("Section %s va %x fsz %x vsz %x at %x\n", sec.name.c_str(), sec.vaddr, sh->SizeOfRawData, sec.vsize, sh->PointerToRawData);
            uint32_t raw_size = std::min(sh->SizeOfRawData, sh->VirtualSize);
            sec.data.resize(sh->VirtualSize);
            if (sh->PointerToRawData && raw_size && sh->PointerToRawData + raw_size <= mBytes.size()) {
                memcpy(sec.data.data(), &mBytes[sh->PointerToRawData], raw_size);
            }
            mSections.push_back(sec);
        }
//        PrintSections();
        PrintImports();
//        exit(0);
        return true;
    }
    
    void PrintSections()
    {
        printf("Sections:\n");
        
        size_t lastSlash = mName.find_last_of("/\\");
        std::string filenameWithExt = mName.substr(lastSlash + 1);
        size_t lastDot = filenameWithExt.find_last_of('.');
        std::string key = filenameWithExt.substr(0, lastDot);

        for (const auto& sec : mSections) {
            uint32_t start = mImageBase + sec.vaddr;
            uint32_t end = start + sec.vsize;
            printf("  - %s: %x .. %x\n", sec.name.c_str(), start, end);
            
            char outname[1024];
            snprintf(outname, sizeof(outname), "%s_%s.bin", key.c_str(), sec.name.substr(1).c_str());
            FILE *f = fopen(outname, "wb");
            fwrite(&sec.data[0], 1, sec.data.size(), f);
            fclose(f);

        }
/*
 for (int i=0; i<mMemoryObjects.size(); i++)
 {
     char outname[1024];
     snprintf(outname, sizeof(outname), "%s_%d.bin", key.c_str(), i+1);
     FILE *f = fopen(outname, "wb");
     fwrite(mMemoryObjects[i].data, 1, mMemoryObjects[i].size, f);
     fclose(f);
 }

 */
        //        for (auto& sec : mSections) {
        //            uint32_t start = mImageBase + sec.vaddr;
        //            uint32_t end = start + sec.vsize;
        //            uint32_t lin = addr.linearOffset();
        //            if (lin >= start && lin + bytes.size() <= end) {
        //                memcpy(sec.data.data() + (lin - start), bytes.data(), bytes.size());
        //                return;
        //            }
        //        }
    }

    virtual bool InRange(address_t addr, int size = 0) override {
        uint32_t lin = addr.linearOffset();
        for (const auto& sec : mSections) {
            uint32_t start = mImageBase + sec.vaddr;
            uint32_t end = start + sec.vsize;
            if (lin >= start && lin + size <= end) return true;
        }
        return false;
    }

    virtual const uint8_t* GetBufferAt(address_t addr) override {
        uint32_t lin = addr.linearOffset();
        for (const auto& sec : mSections) {
            uint32_t start = mImageBase + sec.vaddr;
            uint32_t end = start + sec.vsize;
            if (lin >= start && lin < end) {
                return sec.data.data() + (lin - start);
            }
        }
        assert(0);
        return nullptr;
    }

    virtual const uint8_t* GetBufferAt(int offset) override {
        assert(0);
        return nullptr;
    }

    virtual address_t GetEntry() override {
        return address_t(0, mImageBase + mEntryPoint);
    }

    virtual std::string GetMain() override {
        std::string overlays = "";
        std::string includes = "";

        std::string lastDeclLib;
        
        for (auto& is : ListImports())
        {
            if (is.dll != lastDeclLib)
            {
                lastDeclLib = is.dll;
                includes += format("#include \"%s\"\n", is.getHeaderFile().c_str());
            }
        }

        size_t lastSlash = mName.find_last_of("/\\");
        std::string filenameWithExt = mName.substr(lastSlash + 1);
        size_t lastDot = filenameWithExt.find_last_of('.');
        std::string key = filenameWithExt.substr(0, lastDot);

        for (const auto& sec : mSections) {
            uint32_t start = mImageBase + sec.vaddr;
            
            char outname[1024];
            snprintf(outname, sizeof(outname), "%s_%s.bin", key.c_str(), sec.name.substr(1).c_str());
            overlays += format("    loadOverlay(\"%s_%s.bin\", 0x%x);\n", key.c_str(), sec.name.substr(1).c_str(), start);
        }

        return includes + format("\nvoid sub_%x();\n\nvoid init()\n{\n%s}\n\nvoid start()\n{\n    sub_%x();\n}\n",
                      mImageBase + mEntryPoint,
                      overlays.c_str(), mImageBase + mEntryPoint);
    }

    virtual std::string GetFooter() override {
        return "";
    }

    void Overlay(address_t addr, const std::vector<uint8_t>& bytes) override {
//        for (auto& sec : mSections) {
//            uint32_t start = mImageBase + sec.vaddr;
//            uint32_t end = start + sec.vsize;
//            uint32_t lin = addr.linearOffset();
//            if (lin >= start && lin + bytes.size() <= end) {
//                memcpy(sec.data.data() + (lin - start), bytes.data(), bytes.size());
//                return;
//            }
//        }
        assert(0);
    }

public:
    struct ImportSymbol {
        std::string dll;
        std::string name;
        uint32_t    ordinal{0};
        bool        byOrdinal{false};
        uint32_t    addr;
        
        std::string getHeaderFile()
        {
            // Compose header name (strip .dll/.DLL/.Dll, add .h)
            std::string dllFile = dll;
            size_t dot = dllFile.find_last_of('.');
            if (dot != std::string::npos) {
                dllFile = dllFile.substr(0, dot);
            }
            std::transform(dllFile.begin(), dllFile.end(), dllFile.begin(),
                               [](unsigned char c){ return std::tolower(c); });
            return dllFile + ".h";
        }

    };
    void PrintImports()
    {
        std::string lastOrdinal;
        std::map<int, std::string> lastOrdinals;
        std::string lastDeclLib;
        std::map<std::string, std::string> lastDecls;
        
        for (auto& is : ListImports())
        {
            if (is.dll != lastDeclLib)
            {
                lastDeclLib = is.dll;
                std::string hdrFile = is.getHeaderFile();
                DllDecl d;
                if (!d.LoadFile(hdrFile))
                {
                    if (!d.LoadFile("decl/"+hdrFile))
                    {
                        assert(0);
                    }                    
                }
                lastDecls = d.GetDeclarations();
            }
            if (is.byOrdinal)
            {
                if (is.dll != lastOrdinal)
                {
                    lastOrdinal = is.dll;
                    
                    DllImport d;
                    d.LoadFile(is.dll);
//                    d.Dump();
                    lastOrdinals = d.GetOrdinals();
                }
                assert(lastOrdinals.size());
                auto it = lastOrdinals.find(is.ordinal);
                assert(it != lastOrdinals.end());
                
                std::string symbol = it->second;
                
                auto it2 = lastDecls.find(symbol);
                assert(it2 != lastDecls.end());
                
                std::shared_ptr<import_t> impSymbol = std::make_shared<import_t>(
                    address_t(0, is.addr+mImageBase),
                    is.dll,
                    symbol,
                    makeDllCall(is.dll, it2->second),
                    getStackShift(it2->second));
                mImports.insert({impSymbol->addr, impSymbol});
            }
            else
            {
                std::string symbol = is.name;

                auto it2 = lastDecls.find(symbol);
                assert(it2 != lastDecls.end());
//                printf("app imports from %s symbol %s 0x%x, %s\n", is.dll.c_str(), symbol.c_str(), is.addr+mImageBase, it2->second.c_str());
                std::shared_ptr<import_t> impSymbol = std::make_shared<import_t>(
                    address_t(0, is.addr+mImageBase),
                    is.dll,
                    symbol,
                    makeDllCall(is.dll, it2->second),
                    getStackShift(it2->second));
                mImports.insert({impSymbol->addr, impSymbol});
            }
        }
    }
    
    std::string makeDllCall(std::string dll, std::string decl)
    {
        // input:
        // dll=KERNEL32.DLL; decl=int set_gfx_mode(int card, int w, int h, int v_w, int v_h);
        // output:
        // eax = kernel32::set_gfx_mode(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4)); esp += 20;
        
        // Detect calling convention from declaration
        bool isStdcall = (decl.find("WINAPI") != std::string::npos ||
                          decl.find("__stdcall") != std::string::npos ||
                          decl.find("CALLBACK") != std::string::npos ||
                          decl.find("PASCAL") != std::string::npos);
        
        bool isCdecl = (decl.find("__cdecl") != std::string::npos ||
                        decl.find("ALLEGRO_CC") != std::string::npos);  // Add ALLEGRO_CC detection
        
        // Check for variadic functions (always __cdecl)
        bool isVariadic = (decl.find("...") != std::string::npos);
        
        if (isVariadic) {
            isCdecl = true;
            isStdcall = false;
        }
        
        // Default to stdcall for Windows DLLs if no explicit convention specified
        if (!isStdcall && !isCdecl) {
            isStdcall = true;
        }
        
        // Convert DLL name to lowercase and strip .DLL extension
        std::string dllNamespace = dll;
        std::transform(dllNamespace.begin(), dllNamespace.end(), dllNamespace.begin(), ::tolower);
        size_t dotPos = dllNamespace.find_last_of('.');
        if (dotPos != std::string::npos) {
            dllNamespace = dllNamespace.substr(0, dotPos);
        }
        
        // Parse the declaration to extract return type, function name, and parameters
        // Format: "return_type function_name(param1, param2, ...)"
        
        // Find function name: it's between return type and '('
        size_t parenPos = decl.find('(');
        if (parenPos == std::string::npos) {
            return "stop(\"invalid decl\");";
        }
        
        size_t parenEndPos = decl.find(')', parenPos);
        if (parenEndPos == std::string::npos) {
            return "stop(\"invalid decl\");";
        }
        
        // Extract the part before '(' and split to get return type and function name
        std::string beforeParen = decl.substr(0, parenPos);
        
        // Trim whitespace
        auto trim = [](std::string& s) {
            s.erase(0, s.find_first_not_of(" \t"));
            s.erase(s.find_last_not_of(" \t") + 1);
        };
        trim(beforeParen);
        
        // Find the function name by looking for the last identifier (after spaces and *)
        // Handle cases like "int* func" or "void func" or "struct foo* func"
        size_t nameStart = beforeParen.find_last_of(" \t*");
        if (nameStart == std::string::npos) {
            return "stop(\"invalid decl\");";
        }
        
        std::string functionName = beforeParen.substr(nameStart + 1);
        std::string returnType = beforeParen.substr(0, nameStart + 1);
        
        trim(returnType);
        trim(functionName);
        
        // Extract parameters
        std::string paramStr = decl.substr(parenPos + 1, parenEndPos - parenPos - 1);
        trim(paramStr);
        
        // Count parameters by splitting on commas
        std::vector<std::string> params;
        if (!paramStr.empty() && paramStr != "void") {
            size_t start = 0;
            int depth = 0; // Track parentheses depth for complex types
            
            for (size_t i = 0; i <= paramStr.length(); ++i) {
                if (i == paramStr.length() || (paramStr[i] == ',' && depth == 0)) {
                    std::string param = paramStr.substr(start, i - start);
                    trim(param);
                    if (!param.empty()) {
                        params.push_back(param);
                    }
                    start = i + 1;
                } else if (paramStr[i] == '(') {
                    depth++;
                } else if (paramStr[i] == ')') {
                    depth--;
                }
            }
        }
        
        // Generate the call
        std::string result;
        
        // Check if function returns void
        bool returnsVoid = (returnType == "void" || returnType.empty());
        
        if (!returnsVoid) {
            result += "eax = ";
        }
        
        result += dllNamespace + "::" + functionName + "(";
        
        // Add stack parameters in forward order
        // stack32(0), stack32(1), ..., stack32(n-1)
        for (size_t i = 0; i < params.size(); ++i) {
            if (i > 0) {
                result += ", ";
            }
            result += "stack32(" + std::to_string(i) + ")";
        }
        
        result += ");";
        
        // Add stack cleanup based on calling convention
        if (params.size() > 0) {
            if (isStdcall) {
                // __stdcall: callee cleans up the stack (inside the DLL function)
                // We embed the esp += here because the cleanup doesn't appear in the disassembled code
                result += " esp += " + std::to_string(params.size() * 4) + ";";
            } else if (isCdecl) {
                // __cdecl: caller cleans up the stack
                // The cleanup instruction (add esp, X) appears in the actual disassembled code
                // So we DON'T embed it here - it will be a separate instruction
                // (Do nothing - the disassembler will handle the add esp instruction)
            }
        }
        
        return result;
    }

    int getStackShift(std::string decl)
    {
        // Calculate stack shift based on calling convention and parameter count
        // This returns the amount that's embedded in the generated call string
        // For __stdcall: we embed esp += X in makeDllCall, so return X
        // For __cdecl: the actual add esp instruction is separate, so return 0
        
        // Detect calling convention (same logic as makeDllCall)
        bool isStdcall = (decl.find("WINAPI") != std::string::npos ||
                          decl.find("__stdcall") != std::string::npos ||
                          decl.find("CALLBACK") != std::string::npos ||
                          decl.find("PASCAL") != std::string::npos);
        
        bool isCdecl = (decl.find("__cdecl") != std::string::npos ||
                        decl.find("ALLEGRO_CC") != std::string::npos);
        
        bool isVariadic = (decl.find("...") != std::string::npos);
        
        if (isVariadic) {
            isCdecl = true;
            isStdcall = false;
        }
        
        // Default to stdcall for Windows DLLs
        if (!isStdcall && !isCdecl) {
            isStdcall = true;
        }
        
        // For __cdecl, the stack cleanup is a separate instruction, not embedded
        if (isCdecl) {
            return 0;
        }
        
        // For __stdcall, we embed the stack cleanup in the call string
        // So return the amount that will be in the embedded "esp += X;"
        
        // Find the parameter list
        size_t parenPos = decl.find('(');
        if (parenPos == std::string::npos) {
            return 0;
        }
        
        size_t parenEndPos = decl.find(')', parenPos);
        if (parenEndPos == std::string::npos) {
            return 0;
        }
        
        // Extract parameters
        std::string paramStr = decl.substr(parenPos + 1, parenEndPos - parenPos - 1);
        
        // Trim whitespace
        auto trim = [](std::string& s) {
            s.erase(0, s.find_first_not_of(" \t"));
            s.erase(s.find_last_not_of(" \t") + 1);
        };
        trim(paramStr);
        
        // Empty or void parameter list
        if (paramStr.empty() || paramStr == "void") {
            return 0;
        }
        
        // Count parameters by splitting on commas
        int paramCount = 0;
        int depth = 0; // Track parentheses depth for complex types
        
        for (size_t i = 0; i <= paramStr.length(); ++i) {
            if (i == paramStr.length() && depth == 0) {
                // End of string counts as one more parameter
                paramCount++;
                break;
            } else if (paramStr[i] == ',' && depth == 0) {
                paramCount++;
            } else if (paramStr[i] == '(') {
                depth++;
            } else if (paramStr[i] == ')') {
                depth--;
            }
        }
        
        // Return the stack cleanup amount for __stdcall
        return paramCount * 4;
    }

    std::vector<ImportSymbol> ListImports() const
    {
        std::vector<ImportSymbol> imports;
        if (mBytes.empty()) return imports;
        // Locate DOS and PE headers
        if (mBytes.size() < sizeof(DOSHeader)) return imports;
        const DOSHeader* dos = (const DOSHeader*)&mBytes[0];
        if (!(dos->e_magic[0] == 'M' && dos->e_magic[1] == 'Z')) return imports;
        uint32_t pe_offset = dos->e_lfanew;
        if (pe_offset + sizeof(PEHeader) + sizeof(COFFHeader) > mBytes.size()) return imports;
        const PEHeader* pe = (const PEHeader*)(&mBytes[pe_offset]);
        if (!(pe->Signature[0] == 'P' && pe->Signature[1] == 'E')) return imports;
        const COFFHeader* coff = (const COFFHeader*)(&mBytes[pe_offset + sizeof(PEHeader)]);
        const OptionalHeader* opt = (const OptionalHeader*)(&mBytes[pe_offset + sizeof(PEHeader) + sizeof(COFFHeader)]);
        // DataDirectory #1 is import table RVA/size
        const uint32_t dirBase = pe_offset + sizeof(PEHeader) + sizeof(COFFHeader) + sizeof(OptionalHeader);
        if (dirBase + 8 > mBytes.size()) return imports;
        // Most PE32 use IMAGE_OPTIONAL_HEADER32 and IMAGE_DATA_DIRECTORY[]
        const uint8_t* opt_bytes = &mBytes[pe_offset + sizeof(PEHeader) + sizeof(COFFHeader)];
        uint32_t importDirRVA = *(uint32_t*)(opt_bytes + 104); // 0x68 offset for import directory RVA
        uint32_t importDirSize = *(uint32_t*)(opt_bytes + 108);
        if (!importDirRVA || !importDirSize) return imports;
        // Helper to map RVA to file offset
        auto rvaToFile = [&](uint32_t rva) -> const uint8_t* {
            for (const auto& sec : mSections) {
                uint32_t start = sec.vaddr;
                uint32_t end = start + sec.vsize;
                if (rva >= start && rva < end) {
                    return sec.data.data() + (rva - start);
                }
            }
            return nullptr;
        };
        struct ImportDirEntry {
            uint32_t ImportLookupTableRVA;
            uint32_t TimeDateStamp;
            uint32_t ForwarderChain;
            uint32_t NameRVA;
            uint32_t ImportAddressTableRVA;
        };
        for (uint32_t entryRVA = importDirRVA;; entryRVA += sizeof(ImportDirEntry)) {
            const uint8_t* entryPtr = rvaToFile(entryRVA);
            if (!entryPtr) break;
            ImportDirEntry entry = *(const ImportDirEntry*)entryPtr;
            if (entry.ImportLookupTableRVA == 0 && entry.NameRVA == 0)
                break;
            const char* dllName = (const char*)rvaToFile(entry.NameRVA);
            if (!dllName) break;
            std::string dllstr = dllName;
            // Import Lookup Table: array of 32-bit entries, 0 for end
            for (uint32_t thunkIdx = 0;; ++thunkIdx) {
                const uint8_t* thunkPtr = rvaToFile(entry.ImportLookupTableRVA + thunkIdx*4);
                if (!thunkPtr) break;
                uint32_t thunk = *(uint32_t*)thunkPtr;
                if (!thunk) break;
                ImportSymbol sym;
                sym.dll = dllstr;
                sym.addr = entry.ImportAddressTableRVA + thunkIdx*4;
                if ((thunk & 0x80000000) != 0) {
                    // Import by ordinal
                    sym.byOrdinal = true;
                    sym.ordinal = thunk & 0xFFFF;
                } else {
                    const uint8_t* hintNamePtr = rvaToFile(thunk);
                    if (hintNamePtr) {
                        sym.ordinal = *(uint16_t*)hintNamePtr;
                        sym.name = std::string((const char*)hintNamePtr + 2);
                    }
                }
                imports.push_back(std::move(sym));
            }
        }
        return imports;
    }
};

