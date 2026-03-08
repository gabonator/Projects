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
    uint32_t mSizeOfImage{0};
    uint32_t mSizeOfStackReserve{0};
    uint32_t mSizeOfStackCommit{0};
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
        mSizeOfImage = opt->SizeOfImage;
        mSizeOfStackReserve = opt->SizeOfStackReserve;
        mSizeOfStackCommit = opt->SizeOfStackCommit;
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
        
        return true;
    }
    
    void PrintSections()
    {
        size_t lastSlash = mName.find_last_of("/\\");
        std::string filenameWithExt = mName.substr(lastSlash + 1);
        size_t lastDot = filenameWithExt.find_last_of('.');
        std::string key = filenameWithExt.substr(0, lastDot);

        printf("// Sections of %s:\n", filenameWithExt.c_str());

        for (const auto& sec : mSections) {
            uint32_t start = mImageBase + sec.vaddr;
            uint32_t end = start + sec.vsize;
            printf("//  - %s: %x .. %x (%d bytes)\n", sec.name.c_str(), start, end, end-start);
            
            for (const auto& [addr, imp] : GetImports())
            {
                if (addr.offset >= start && addr.offset < end)
                {
                    *((uint32_t*)&sec.data[addr.offset-start]) = imp->targetAddr;
                }
            }
            
            char outname[1024];
            snprintf(outname, sizeof(outname), "%s_%s.bin", key.c_str(), sec.name.substr(1).c_str());
            FILE *f = fopen(outname, "wb");
            fwrite(&sec.data[0], 1, sec.data.size(), f);
            fclose(f);

        }
        printf("\n");
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

    virtual std::string GetMain() override { assert(0); return "-- todo --\n";}
    virtual std::string GetInit() override {
        // TODO: cleanup {
        PrintImports();
        PrintRTTI();
        PrintSections();
        // }

        std::string overlays = "";
        std::string includes = "";

        std::string lastDeclLib;
        std::vector<ExportSymbol> exp = ListExports();
        
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

        uint32_t symAddr = 0x6ab00000;
        int counter = 0;
        std::string indirectImport = "    switch ((ptrImportTable)o) {\n";
        std::string indirectEnum = format("\nenum class ptrImportTable {\n    ptr_begin = 0x%x,\n", symAddr);
        for (const auto& [addr, imp] : GetImports())
        {
            counter ++;
//            *((uint32_t*)GetBufferAt(addr)) = ++symAddr;
            indirectEnum += format("    ptr_%s_%s, // 0x%x \n", imp->namesp.c_str(), imp->symbol.c_str(), imp->addr.offset);
            indirectImport += format("        case ptrImportTable::ptr_%s_%s:\n            %s\n            break; // %x\n", imp->namesp.c_str(), imp->symbol.c_str(), imp->call.c_str(), symAddr+counter);
        }
        indirectEnum += "};\n\n";
        indirectImport += "    }\n";

        for (const auto& sec : mSections) {
            uint32_t start = mImageBase + sec.vaddr;
            
            char outname[1024];
            snprintf(outname, sizeof(outname), "%s_%s.bin", key.c_str(), sec.name.substr(1).c_str());
            overlays += format("    loadOverlay(\"%s_%s.bin\", 0x%x);\n", key.c_str(), sec.name.substr(1).c_str(), start);
        }
        std::string indirectImportHeader = "void indirectCall(int s, int o) {\n";
        std::string indirectImportFooter = "}\n";
        
        return includes + format("\nvoid sub_%x();\n\nvoid init()\n{\n%s    esp = 0x%x;\n    ebp = 0x%x;\n}\n\nvoid start()\n{\n    sub_%x();\n}\n",
                      mImageBase + mEntryPoint,
                      overlays.c_str(), 
                      mImageBase + mSizeOfImage,
                      mImageBase + mSizeOfImage,
                      mImageBase + mEntryPoint) + indirectEnum +
                    indirectImportHeader + indirectImport + indirectImportFooter;
        
        // TODO: addd indirect call table
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
            return getNamespace() + ".h";
        }
        
        std::string getNamespace()
        {
            // Compose header name (strip .dll/.DLL/.Dll, add .h)
            std::string dllFile = dll;
            size_t dot = dllFile.find_last_of('.');
            if (dot != std::string::npos) {
                dllFile = dllFile.substr(0, dot);
            }
            std::transform(dllFile.begin(), dllFile.end(), dllFile.begin(),
                               [](unsigned char c){ return std::tolower(c); });
            return dllFile;
        }

    };

    struct ExportSymbol {
        std::string name;      // empty if export-by-ordinal only
        uint32_t    ordinal;
        uint32_t    rva;
        bool        isForwarded = false;
        std::string forwarder; // "DLL.Func"
    };
    
    std::string demangle_msvc(const std::string &mangled) {
        // Check if it starts with '?' (MSVC mangled)
        if (mangled.empty() || mangled[0] != '?') return mangled;

        size_t pos = 1;

        // 1. Extract function name (up to first '@')
        size_t func_end = mangled.find('@', pos);
        if (func_end == std::string::npos) return mangled;
        std::string func = mangled.substr(pos, func_end - pos);
        pos = func_end + 1;

        // 2. Extract class name (up to next '@')
        size_t cls_end = mangled.find('@', pos);
        std::string cls;
        if (cls_end != std::string::npos) {
            cls = mangled.substr(pos, cls_end - pos);
            pos = cls_end + 2; // skip the @@
        }

        // 3. Extract simple parameters
        // For simplicity, we only handle pointers and basic types (P=pointer, V=void, etc.)
        std::string params;
        if (pos < mangled.size()) {
            std::vector<std::string> param_list;
            while (pos < mangled.size()) {
                char c = mangled[pos++];
                switch (c) {
                    case 'X': param_list.push_back("void"); break;
                    case 'H': param_list.push_back("int"); break;
                    case 'I': param_list.push_back("unsigned int"); break;
                    case 'P': // pointer
                        if (pos < mangled.size()) {
                            char next = mangled[pos++];
                            if (next == 'A') param_list.push_back("DXCtl*"); // custom type example
                        }
                        break;
                    case '@':
                        // end of parameter list
                        pos = mangled.size();
                        break;
                    default:
                        param_list.push_back("?");
                }
            }
            for (size_t i = 0; i < param_list.size(); ++i) {
                if (i > 0) params += ", ";
                params += param_list[i];
            }
        }

        // 4. Combine into declaration
        std::string decl;
        if (!cls.empty()) decl = cls + "::";
        decl += func + "(" + params + ")";

        return decl;
    }

    void PrintImports()
    {
        std::string lastOrdinal;
        std::map<int, std::string> lastOrdinals;
        std::string lastDeclLib;
        std::map<std::string, std::string> lastDecls;
        std::string namesp;
        
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
                        printf("// Missing imports for %s!\n", hdrFile.c_str());
//                        assert(0);
                    }                    
                }
                lastDecls = d.GetDeclarations();
                namesp = is.getNamespace();
            }
            if (is.byOrdinal)
            {
                if (is.dll != lastOrdinal)
                {
                    lastOrdinal = is.dll;
                    
                    DllImport d;
                    if (!d.LoadFile(is.dll))
                        printf("Missing dll for %s!\n", is.dll.c_str());
                        
//                    d.Dump();
                    lastOrdinals = d.GetOrdinals();
                }
                assert(lastOrdinals.size());
                auto it = lastOrdinals.find(is.ordinal);
                assert(it != lastOrdinals.end());
                
                std::string symbol = it->second;
                
                auto it2 = lastDecls.find(symbol);
                if(it2 != lastDecls.end())
                {
                    std::shared_ptr<import_t> impSymbol = std::make_shared<import_t>(
                     address_t(0, is.addr+mImageBase),
                     is.dll,
                     symbol,
                     makeDllCall(is.dll, it2->second),
                     namesp,
                     getStackShift(it2->second),
                     0);
                    mImports.insert({impSymbol->addr, impSymbol});
                } else {
                    std::shared_ptr<import_t> impSymbol = std::make_shared<import_t>(
                     address_t(0, is.addr+mImageBase),
                     is.dll,
                     symbol,
                     format("ordinal_%d", is.ordinal),
                     namesp,
                     0,
                     0);
                    mImports.insert({impSymbol->addr, impSymbol});

                }
            }
            else
            {
                std::string symbol = is.name;

                auto it2 = lastDecls.find(symbol);
                if(it2 != lastDecls.end())
                {
                    //                printf("app imports from %s symbol %s 0x%x, %s\n", is.dll.c_str(), symbol.c_str(), is.addr+mImageBase, it2->second.c_str());
                    std::shared_ptr<import_t> impSymbol = std::make_shared<import_t>(
                     address_t(0, is.addr+mImageBase),
                     is.dll,
                     symbol,
                     makeDllCall(is.dll, it2->second),
                     namesp,
                     getStackShift(it2->second),
                     0);
                    mImports.insert({impSymbol->addr, impSymbol});
                } else {
                    std::shared_ptr<import_t> impSymbol = std::make_shared<import_t>(
                     address_t(0, is.addr+mImageBase),
                     is.dll,
                     symbol,
                     "eax = " + namesp + "::" + demangle_msvc(symbol) + "();",
                     namesp,
                     0,
                     0);
                    mImports.insert({impSymbol->addr, impSymbol});
                }
            }
        }
        
        uint32_t targetAddr = 0x6ab00000;
        for (const auto& [addr, imp] : GetImports())
        {
            imp->targetAddr = ++targetAddr;
        }

    }
    
private:
    // Structure to represent a parsed function argument
    struct ArgumentInfo {
        std::string fullDeclaration;  // Full argument declaration (e.g., "int* ptr")
        std::string type;              // Type without identifier (e.g., "int*")
        std::string name;              // Argument name (e.g., "ptr")
        bool isVariadic{false};        // True if this is "..."
    };
    
    // Structure to represent a parsed function declaration
    struct ParsedDeclaration {
        std::string returnType;        // Return type (e.g., "int")
        std::string callingConvention; // WINAPI, __stdcall, __cdecl, ALLEGRO_CC, etc.
        std::string symbolName;        // Function name
        std::vector<ArgumentInfo> arguments;
        bool isValid{false};
        
        // Helper to determine calling convention type
        bool isStdcall() const {
            return (callingConvention == "WINAPI" ||
                    callingConvention == "__stdcall" ||
                    callingConvention == "CALLBACK" ||
                    callingConvention == "PASCAL");
        }
        
        bool isCdecl() const {
            return (callingConvention == "__cdecl" ||
                    callingConvention == "ALLEGRO_CC");
        }
        
        bool isVariadic() const {
            return !arguments.empty() && arguments.back().isVariadic;
        }
        
        bool returnsVoid() const {
            return returnType == "void" || returnType.empty();
        }
        
        // Debug output
        void Dump() const {
            printf("ParsedDeclaration:\n");
            printf("  Valid: %s\n", isValid ? "true" : "false");
            if (!isValid) return;
            
            printf("  Return Type: '%s'\n", returnType.c_str());
            printf("  Calling Convention: '%s'", callingConvention.c_str());
            if (!callingConvention.empty()) {
                if (isStdcall()) printf(" (stdcall)");
                else if (isCdecl()) printf(" (cdecl)");
            } else {
                printf(" (default/stdcall)");
            }
            printf("\n");
            printf("  Symbol Name: '%s'\n", symbolName.c_str());
            printf("  Returns Void: %s\n", returnsVoid() ? "true" : "false");
            printf("  Is Variadic: %s\n", isVariadic() ? "true" : "false");
            printf("  Arguments (%zu):\n", arguments.size());
            
            for (size_t i = 0; i < arguments.size(); ++i) {
                const auto& arg = arguments[i];
                printf("    [%zu] ", i);
                if (arg.isVariadic) {
                    printf("... (variadic)\n");
                } else {
                    printf("'%s' - type: '%s', name: '%s'\n", 
                           arg.fullDeclaration.c_str(),
                           arg.type.c_str(),
                           arg.name.c_str());
                }
            }
        }
    };
    
    // Helper function to trim whitespace
    static void trim(std::string& s) {
        s.erase(0, s.find_first_not_of(" \t"));
        s.erase(s.find_last_not_of(" \t") + 1);
    }
    
    // Parse a function declaration into structured components
    ParsedDeclaration parseDeclaration(const std::string& decl) const {
        ParsedDeclaration parsed;
                
        // Find the opening parenthesis for the parameter list
        size_t parenPos = decl.find('(');
        if (parenPos == std::string::npos) {
            return parsed; // Invalid
        }
        
        // Find the MATCHING closing parenthesis (not just the first one)
        size_t parenEndPos = std::string::npos;
        int depth = 1; // We're already at the opening '('
        for (size_t i = parenPos + 1; i < decl.length(); ++i) {
            if (decl[i] == '(') {
                depth++;
            } else if (decl[i] == ')') {
                depth--;
                if (depth == 0) {
                    parenEndPos = i;
                    break;
                }
            }
        }
        
        if (parenEndPos == std::string::npos) {
            return parsed; // Invalid - no matching closing paren
        }
        
        // Extract the part before '(' - contains return type, calling convention, and function name
        std::string beforeParen = decl.substr(0, parenPos);
        trim(beforeParen);
        
        // Known calling conventions
        const std::vector<std::string> callingConventions = {
            "WINAPI", "__stdcall", "CALLBACK", "PASCAL", 
            "__cdecl", "ALLEGRO_CC", "__fastcall"
        };
        
        // Find calling convention in the declaration
        for (const auto& conv : callingConventions) {
            size_t pos = beforeParen.find(conv);
            if (pos != std::string::npos) {
                parsed.callingConvention = conv;
                // Remove it from beforeParen
                beforeParen.erase(pos, conv.length());
                trim(beforeParen);
                break;
            }
        }
        
        // Now beforeParen should be: "return_type function_name"
        // Find the function name (last identifier after spaces and *)
        size_t nameStart = beforeParen.find_last_of(" \t*");
        if (nameStart == std::string::npos) {
            return parsed; // Invalid
        }
        
        parsed.symbolName = beforeParen.substr(nameStart + 1);
        parsed.returnType = beforeParen.substr(0, nameStart + 1);
        trim(parsed.returnType);
        trim(parsed.symbolName);
        
        // Extract parameters
        std::string paramStr = decl.substr(parenPos + 1, parenEndPos - parenPos - 1);
        trim(paramStr);
        
        // Parse parameters
        if (!paramStr.empty() && paramStr != "void") {
            std::vector<std::string> params;
            size_t start = 0;
            int depth = 0; // Track parentheses depth for function pointer types
            
            // First pass: split by commas at depth 0
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
            
            // Second pass: parse each parameter
            for (const auto& param : params) {
                ArgumentInfo argInfo;
                argInfo.fullDeclaration = param;
                
                // Check for variadic
                if (param == "...") {
                    argInfo.isVariadic = true;
                    argInfo.type = "...";
                    argInfo.name = "";
                } else {
                    // Parse parameter to extract type and name
                    // Handle function pointer types like: "void (*proc)(void)" or "int (*callback)(int, int)"
                    size_t funcPtrPos = param.find("(*");
                    if (funcPtrPos != std::string::npos) {
                        // We have a function pointer
                        // Find the matching closing paren for the pointer name (*name)
                        size_t nameStart = funcPtrPos + 2; // after '(*'
                        
                        // Find the closing paren for (*name) - it's the first ')' after '(*'
                        size_t nameEnd = std::string::npos;
                        int parenDepth = 1; // We're already inside (*
                        for (size_t i = nameStart; i < param.length(); ++i) {
                            if (param[i] == '(') {
                                parenDepth++;
                            } else if (param[i] == ')') {
                                parenDepth--;
                                if (parenDepth == 0) {
                                    nameEnd = i;
                                    break;
                                }
                            }
                        }
                        
                        if (nameEnd != std::string::npos) {
                            argInfo.name = param.substr(nameStart, nameEnd - nameStart);
                            trim(argInfo.name);
                            // Type: "void (*)(void)" - replace the name with nothing
                            argInfo.type = param.substr(0, nameStart) + ")" + param.substr(nameEnd + 1);
                            trim(argInfo.type);
                        } else {
                            // Malformed function pointer, treat as type only
                            argInfo.type = param;
                            argInfo.name = "";
                        }
                    } else {
                        // Regular parameter: "int count" or "char* str"
                        // Find the last space or tab that's not inside parentheses
                        size_t lastSpace = std::string::npos;
                        int parenDepth = 0;
                        for (size_t i = param.length(); i > 0; --i) {
                            char c = param[i - 1];
                            if (c == ')') parenDepth++;
                            else if (c == '(') parenDepth--;
                            else if ((c == ' ' || c == '\t') && parenDepth == 0) {
                                lastSpace = i - 1;
                                break;
                            }
                        }
                        
                        if (lastSpace != std::string::npos) {
                            argInfo.name = param.substr(lastSpace + 1);
                            argInfo.type = param.substr(0, lastSpace);
                            trim(argInfo.type);
                            trim(argInfo.name);
                        } else {
                            // No name, just type
                            argInfo.type = param;
                            argInfo.name = "";
                        }
                    }
                }
                
                parsed.arguments.push_back(argInfo);
            }
        }
        
        parsed.isValid = true;
        
//        printf("---- decl=%s\n", decl.c_str());
//        parsed.Dump();

        return parsed;
    }

public:
    std::string makeDllCall(std::string dll, std::string decl)
    {
        // input:
        // dll=KERNEL32.DLL; decl=int set_gfx_mode(int card, int w, int h, int v_w, int v_h);
        // output:
        // eax = kernel32::set_gfx_mode(stack32(0), stack32(1), stack32(2), stack32(3), stack32(4)); esp += 20;
        
        // Parse the declaration into structured components
        ParsedDeclaration parsed = parseDeclaration(decl);
        
        if (!parsed.isValid) {
            return "stop(\"invalid decl\");";
        }
        
        // Determine calling convention
        bool isStdcall = parsed.isStdcall();
        bool isCdecl = parsed.isCdecl();
        bool isVariadic = parsed.isVariadic();
        
        // Variadic functions are always __cdecl
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
        
        // Generate the call syntax
        std::string result;
        
        // Add return value assignment if not void
        if (!parsed.returnsVoid()) {
            result += "eax = ";
        }
        
        // Add function call
        result += dllNamespace + "::" + parsed.symbolName + "(";
        
        // Add stack parameters with types
        bool firstArgEmitted = false;
        for (size_t i = 0; i < parsed.arguments.size(); ++i) {
            const auto& arg = parsed.arguments[i];
            
            // Skip variadic marker
            if (arg.isVariadic) {
                continue;
            }
            
            if (firstArgEmitted) {
                result += ", ";
            }
            firstArgEmitted = true;
            
            result += "stack32<" + arg.type + ">(" + std::to_string(i) + ")";
        }
        
        result += ");";
        
        // Add stack cleanup based on calling convention
        // Count non-variadic arguments
        size_t paramCount = 0;
        for (const auto& arg : parsed.arguments) {
            if (!arg.isVariadic) {
                paramCount++;
            }
        }
        
        if (paramCount > 0) {
            if (isStdcall) {
                // __stdcall: callee cleans up the stack (inside the DLL function)
                // We embed the esp += here because the cleanup doesn't appear in the disassembled code
                result += " esp += " + std::to_string(paramCount * 4) + ";";
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
        
        // Parse the declaration using our helper function
        ParsedDeclaration parsed = parseDeclaration(decl);
        
        if (!parsed.isValid) {
            return 0;
        }
        
        // Determine calling convention
        bool isStdcall = parsed.isStdcall();
        bool isCdecl = parsed.isCdecl();
        bool isVariadic = parsed.isVariadic();
        
        // Variadic functions are always __cdecl
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
        // Count non-variadic parameters
        int paramCount = 0;
        for (const auto& arg : parsed.arguments) {
            if (!arg.isVariadic) {
                paramCount++;
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
    std::vector<ExportSymbol> ListExports() const
    {
        std::vector<ExportSymbol> exports;
        if (mBytes.empty()) return exports;

        // --- DOS + PE headers ---
        if (mBytes.size() < sizeof(DOSHeader)) return exports;
        const DOSHeader* dos = (const DOSHeader*)&mBytes[0];
        if (dos->e_magic[0] != 'M' || dos->e_magic[1] != 'Z') return exports;

        uint32_t pe_offset = dos->e_lfanew;
        if (pe_offset + sizeof(PEHeader) + sizeof(COFFHeader) > mBytes.size())
            return exports;

        const PEHeader* pe = (const PEHeader*)(&mBytes[pe_offset]);
        if (pe->Signature[0] != 'P' || pe->Signature[1] != 'E')
            return exports;

        // Optional header start
        const uint8_t* opt_bytes =
            &mBytes[pe_offset + sizeof(PEHeader) + sizeof(COFFHeader)];

        // Export directory = DataDirectory[0]
        uint32_t exportDirRVA  = *(uint32_t*)(opt_bytes + 96); // 0x60
        uint32_t exportDirSize = *(uint32_t*)(opt_bytes + 100);
        if (!exportDirRVA || !exportDirSize) return exports;

        // RVA → file pointer helper
        auto rvaToFile = [&](uint32_t rva) -> const uint8_t* {
            for (const auto& sec : mSections) {
                uint32_t start = sec.vaddr;
                uint32_t end   = start + sec.vsize;
                if (rva >= start && rva < end) {
                    return sec.data.data() + (rva - start);
                }
            }
            return nullptr;
        };

        const uint8_t* dirPtr = rvaToFile(exportDirRVA);
        if (!dirPtr) return exports;

        struct ExportDir {
            uint32_t Characteristics;
            uint32_t TimeDateStamp;
            uint16_t MajorVersion;
            uint16_t MinorVersion;
            uint32_t NameRVA;
            uint32_t Base;
            uint32_t NumberOfFunctions;
            uint32_t NumberOfNames;
            uint32_t AddressOfFunctions;
            uint32_t AddressOfNames;
            uint32_t AddressOfNameOrdinals;
        };

        const ExportDir* dir = (const ExportDir*)dirPtr;

        const uint32_t* funcRVAs =
            (const uint32_t*)rvaToFile(dir->AddressOfFunctions);
        const uint32_t* nameRVAs =
            (const uint32_t*)rvaToFile(dir->AddressOfNames);
        const uint16_t* ordinals =
            (const uint16_t*)rvaToFile(dir->AddressOfNameOrdinals);

        if (!funcRVAs) return exports;

        // --- Build name map (ordinal -> name) ---
        std::vector<std::string> names(dir->NumberOfFunctions);
        if (nameRVAs && ordinals) {
            for (uint32_t i = 0; i < dir->NumberOfNames; ++i) {
                uint16_t ord = ordinals[i];
                const char* nm = (const char*)rvaToFile(nameRVAs[i]);
                if (nm && ord < names.size())
                    names[ord] = nm;
            }
        }

        // --- Enumerate exports ---
        for (uint32_t i = 0; i < dir->NumberOfFunctions; ++i) {
            uint32_t rva = funcRVAs[i];
            if (!rva) continue;

            ExportSymbol sym;
            sym.ordinal = dir->Base + i;
            sym.rva     = rva;
            sym.name    = names[i];

            // Forwarded export?
            if (rva >= exportDirRVA &&
                rva < exportDirRVA + exportDirSize) {
                const char* fwd = (const char*)rvaToFile(rva);
                if (fwd) {
                    sym.isForwarded = true;
                    sym.forwarder = fwd;
                }
            }

            exports.push_back(std::move(sym));
        }

        return exports;
    }

    virtual std::vector<std::string> GetRelocations() override
    {
        // postprocessed image is already relocated
        return {};
    }

    // RTTI structures for MSVC (32-bit PE)
    struct RTTITypeDescriptor {
        uint32_t pVFTable;     // Pointer to type_info vtable
        uint32_t spare;        // Reserved
        char name[1];          // Mangled name (variable length)
    };

    struct RTTIBaseClassDescriptor {
        uint32_t pTypeDescriptor;       // Type descriptor of the base class
        uint32_t numContainedBases;     // Number of nested classes in base class
        int32_t  mdisp;                 // Member displacement
        int32_t  pdisp;                 // Vbtable displacement
        int32_t  vdisp;                 // Displacement inside vbtable
        uint32_t attributes;            // Flags
    };

    struct RTTIClassHierarchyDescriptor {
        uint32_t signature;             // Always 0
        uint32_t attributes;            // Bit 0 set = multiple inheritance
        uint32_t numBaseClasses;        // Number of base classes
        uint32_t pBaseClassArray;       // Array of base class descriptors
    };

    struct RTTICompleteObjectLocator {
        uint32_t signature;    // Always 0 for 32-bit
        uint32_t offset;       // Offset of this vtable in the complete class
        uint32_t cdOffset;     // Constructor displacement offset
        uint32_t pTypeDescriptor;   // RVA to TypeDescriptor (in PE32+) or pointer (in PE32)
        uint32_t pClassDescriptor;  // RVA to ClassHierarchyDescriptor
    };

    struct BaseClassInfo {
        std::string name;
        std::string demangledName;
        int32_t offset;         // Offset of base class in derived class
        int32_t vbtableOffset;  // Virtual base table offset
        int32_t vbtableIndex;   // Index into virtual base table
    };

    struct RTTIInfo {
        std::string mangledName;   // Mangled type name from TypeDescriptor
        std::string demangledName; // Demangled class name
        uint32_t vtableRVA;        // RVA of the vtable
        uint32_t colRVA;           // RVA of CompleteObjectLocator
        uint32_t offset;           // Offset in complete object
        std::vector<BaseClassInfo> baseClasses;  // Base class information
        std::vector<uint32_t> virtualFunctions;  // RVAs of virtual functions
        bool hasMultipleInheritance{false};
        bool hasVirtualInheritance{false};
    };

    std::vector<RTTIInfo> ListRTTI() const
    {
        std::vector<RTTIInfo> rttiList;
        if (mBytes.empty() || mSections.empty()) return rttiList;

        // Helper to map RVA to file pointer
        auto rvaToFile = [&](uint32_t rva) -> const uint8_t* {
            for (const auto& sec : mSections) {
                uint32_t start = sec.vaddr;
                uint32_t end = start + sec.vsize;
                if (rva >= start && rva < end) {
                    uint32_t offset = rva - start;
                    if (offset < sec.data.size()) {
                        return sec.data.data() + offset;
                    }
                }
            }
            return nullptr;
        };

        // Helper to check if RVA is valid
        auto isValidRVA = [&](uint32_t rva) -> bool {
            return rvaToFile(rva) != nullptr;
        };

        // Find .rdata section (where RTTI usually lives)
        const Section* rdataSection = nullptr;
        for (const auto& sec : mSections) {
            if (sec.name == ".rdata" || sec.name == ".data") {
                rdataSection = &sec;
                break;
            }
        }

        if (!rdataSection) return rttiList;

        // Scan .rdata for potential vtables
        // A vtable entry is a pointer, and the pointer at vtable[-1] points to CompleteObjectLocator
        for (uint32_t i = 4; i < rdataSection->data.size() - 4; i += 4) {
            uint32_t vtableRVA = rdataSection->vaddr + i;
            
            // Read the potential vtable pointer
            const uint8_t* vtablePtr = rvaToFile(vtableRVA);
            if (!vtablePtr) continue;

            uint32_t firstEntry = *(uint32_t*)vtablePtr;
            
            // Check if this looks like a code pointer (points to executable section)
            bool isCode = false;
            for (const auto& sec : mSections) {
                if (sec.name == ".text") {
                    uint32_t start = mImageBase + sec.vaddr;
                    uint32_t end = start + sec.vsize;
                    if (firstEntry >= start && firstEntry < end) {
                        isCode = true;
                        break;
                    }
                }
            }

            if (!isCode) continue;

            // Check vtable[-1] for CompleteObjectLocator pointer
            if (i < 4) continue;
            const uint8_t* colPtrData = rvaToFile(vtableRVA - 4);
            if (!colPtrData) continue;

            uint32_t colAddr = *(uint32_t*)colPtrData;
            
            // Convert to RVA (subtract image base if it's an absolute address)
            uint32_t colRVA = colAddr;
            if (colAddr >= mImageBase) {
                colRVA = colAddr - mImageBase;
            }

            // Validate COL RVA
            if (!isValidRVA(colRVA)) continue;

            const RTTICompleteObjectLocator* col = 
                (const RTTICompleteObjectLocator*)rvaToFile(colRVA);
            if (!col) continue;

            // Validate signature (should be 0 for 32-bit PE)
            if (col->signature != 0 && col->signature != 1) continue;

            // Get TypeDescriptor
            uint32_t tdRVA = col->pTypeDescriptor;
            if (tdRVA >= mImageBase) {
                tdRVA -= mImageBase;
            }

            if (!isValidRVA(tdRVA)) continue;

            const RTTITypeDescriptor* td = 
                (const RTTITypeDescriptor*)rvaToFile(tdRVA);
            if (!td) continue;

            // Read the mangled name (it's null-terminated)
            const char* namePtr = (const char*)&td->name[0];
            std::string mangledName;
            
            // Read up to 256 chars or until null
            for (int j = 0; j < 256; ++j) {
                if (namePtr[j] == '\0') break;
                // Basic validation - printable ASCII
                if (namePtr[j] < 0x20 || namePtr[j] > 0x7E) {
                    break;
                }
                mangledName += namePtr[j];
            }

            // Must start with . for MSVC RTTI
            if (mangledName.empty() || mangledName[0] != '.') continue;

            // Create RTTI info
            RTTIInfo info;
            info.mangledName = mangledName;
            info.demangledName = DemangleMSVCType(mangledName);
            info.vtableRVA = vtableRVA;
            info.colRVA = colRVA;
            info.offset = col->offset;

            // Extract class hierarchy information
            uint32_t classHierarchyRVA = col->pClassDescriptor;
            if (classHierarchyRVA >= mImageBase) {
                classHierarchyRVA -= mImageBase;
            }

            if (isValidRVA(classHierarchyRVA)) {
                const RTTIClassHierarchyDescriptor* hierarchy = 
                    (const RTTIClassHierarchyDescriptor*)rvaToFile(classHierarchyRVA);
                
                if (hierarchy && hierarchy->signature == 0) {
                    info.hasMultipleInheritance = (hierarchy->attributes & 0x01) != 0;
                    info.hasVirtualInheritance = (hierarchy->attributes & 0x02) != 0;

                    // Get base class array
                    uint32_t baseArrayRVA = hierarchy->pBaseClassArray;
                    if (baseArrayRVA >= mImageBase) {
                        baseArrayRVA -= mImageBase;
                    }

                    if (isValidRVA(baseArrayRVA)) {
                        const uint32_t* baseClassPtrs = (const uint32_t*)rvaToFile(baseArrayRVA);
                        
                        // Iterate through base classes (skip first - it's the class itself)
                        for (uint32_t i = 1; i < hierarchy->numBaseClasses && i < 16; ++i) {
                            uint32_t baseDescRVA = baseClassPtrs[i];
                            if (baseDescRVA >= mImageBase) {
                                baseDescRVA -= mImageBase;
                            }

                            if (!isValidRVA(baseDescRVA)) continue;

                            const RTTIBaseClassDescriptor* baseDesc = 
                                (const RTTIBaseClassDescriptor*)rvaToFile(baseDescRVA);
                            if (!baseDesc) continue;

                            // Get base class type descriptor
                            uint32_t baseTDRVA = baseDesc->pTypeDescriptor;
                            if (baseTDRVA >= mImageBase) {
                                baseTDRVA -= mImageBase;
                            }

                            if (!isValidRVA(baseTDRVA)) continue;

                            const RTTITypeDescriptor* baseTD = 
                                (const RTTITypeDescriptor*)rvaToFile(baseTDRVA);
                            if (!baseTD) continue;

                            // Read base class name
                            const char* baseNamePtr = (const char*)&baseTD->name[0];
                            std::string baseMangledName;
                            for (int j = 0; j < 256; ++j) {
                                if (baseNamePtr[j] == '\0') break;
                                if (baseNamePtr[j] < 0x20 || baseNamePtr[j] > 0x7E) break;
                                baseMangledName += baseNamePtr[j];
                            }

                            if (!baseMangledName.empty() && baseMangledName[0] == '.') {
                                BaseClassInfo baseInfo;
                                baseInfo.name = baseMangledName;
                                baseInfo.demangledName = DemangleMSVCType(baseMangledName);
                                baseInfo.offset = baseDesc->mdisp;
                                baseInfo.vbtableOffset = baseDesc->pdisp;
                                baseInfo.vbtableIndex = baseDesc->vdisp;
                                info.baseClasses.push_back(baseInfo);
                            }
                        }
                    }
                }
            }

            // Extract virtual function pointers from vtable
            const uint8_t* vtableData = rvaToFile(vtableRVA);
            if (vtableData) {
                // Read up to 64 virtual function pointers (or until we hit invalid data)
                for (int vfIdx = 0; vfIdx < 64; ++vfIdx) {
                    const uint8_t* vfPtrData = rvaToFile(vtableRVA + vfIdx * 4);
                    if (!vfPtrData) break;

                    uint32_t vfAddr = *(uint32_t*)vfPtrData;
                    
                    // Check if this looks like a code pointer
                    bool validCodePtr = false;
                    for (const auto& sec : mSections) {
                        if (sec.name == ".text") {
                            uint32_t start = mImageBase + sec.vaddr;
                            uint32_t end = start + sec.vsize;
                            if (vfAddr >= start && vfAddr < end) {
                                validCodePtr = true;
                                break;
                            }
                        }
                    }

                    if (!validCodePtr) break;

                    info.virtualFunctions.push_back(vfAddr);
                }
            }

            rttiList.push_back(info);
        }

        return rttiList;
    }

    // Enhanced MSVC type name demangler with template support
    std::string DemangleMSVCType(const std::string& mangled) const
    {
        // MSVC RTTI type names have format: .?AV<name>@@ or .?AU<name>@@ or .?AW<name>@@
        // .?AV = class
        // .?AU = struct  
        // .?AW = union
        // Templates: ?$ introduces a template, @ separates template args
        // Example: .?AV?$basic_ifstream@DU?$char_traits@D@std@@@std@@
        //   = std::basic_ifstream<char, std::char_traits<char>>

        if (mangled.size() < 4 || mangled[0] != '.') return mangled;

        size_t pos = 1;

        // Skip past .?A
        if (mangled.substr(pos, 2) != "?A") return mangled;
        pos += 2;

        // Get type (V=class, U=struct, W=union)
        char typeChar = (pos < mangled.size()) ? mangled[pos++] : '?';
        std::string typePrefix;
        switch (typeChar) {
            case 'V': typePrefix = ""; break; // Don't show "class" prefix
            case 'U': typePrefix = ""; break; // Don't show "struct" prefix
            case 'W': typePrefix = "union "; break;
            default: return mangled;
        }

        // Parse the rest recursively
        std::string result = typePrefix + ParseMangledName(mangled, pos);
        return result;
    }

private:
    // Helper to parse a single mangled type/name component
    std::string ParseMangledName(const std::string& mangled, size_t& pos) const
    {
        if (pos >= mangled.size()) return "";

        // Check for template
        if (pos < mangled.size() - 1 && mangled[pos] == '?' && mangled[pos + 1] == '$') {
            pos += 2; // Skip ?$
            return ParseTemplate(mangled, pos);
        }

        // Check for nested type (V=class, U=struct, etc.)
        if (mangled[pos] == 'V' || mangled[pos] == 'U' || mangled[pos] == 'W') {
            pos++; // Skip type indicator
            return ParseMangledName(mangled, pos);
        }

        // Parse regular identifier and namespace
        std::vector<std::string> components;
        std::string current;
        
        while (pos < mangled.size()) {
            char c = mangled[pos];
            
            if (c == '@') {
                pos++;
                if (!current.empty()) {
                    components.push_back(current);
                    current.clear();
                }
                // @@ terminates the name
                if (pos < mangled.size() && mangled[pos] == '@') {
                    pos++; // Consume second @
                    break;
                }
            } else if (c == '?') {
                // Start of nested template or type
                if (!current.empty()) {
                    components.push_back(current);
                    current.clear();
                }
                std::string nested = ParseMangledName(mangled, pos);
                if (!nested.empty()) {
                    components.push_back(nested);
                }
            } else {
                current += c;
                pos++;
            }
        }

        if (!current.empty()) {
            components.push_back(current);
        }

        // Build result: namespace::namespace::class
        if (components.empty()) return "";

        // Reverse order (MSVC stores innermost first)
        std::reverse(components.begin(), components.end());

        std::string result;
        for (size_t i = 0; i < components.size(); ++i) {
            if (i > 0) result += "::";
            result += components[i];
        }

        return result;
    }

    // Parse template: name<arg1, arg2, ...>
    std::string ParseTemplate(const std::string& mangled, size_t& pos) const
    {
        // Read template name until @
        std::string templateName;
        while (pos < mangled.size() && mangled[pos] != '@') {
            templateName += mangled[pos++];
        }
        
        if (pos >= mangled.size()) return templateName;
        pos++; // Skip @

        // Parse template arguments
        std::vector<std::string> args;
        while (pos < mangled.size()) {
            // Check for end of template args
            if (mangled[pos] == '@') {
                pos++; // Skip @
                // Check for end of entire name (@@)
                if (pos < mangled.size() && mangled[pos] == '@') {
                    // Don't consume - let outer parser handle it
                    break;
                }
                // Check for namespace separator
                if (pos < mangled.size() && mangled[pos] != '@' && mangled[pos] != '?') {
                    // This @ is part of namespace, continue parsing namespace
                    break;
                }
                continue;
            }

            // Parse template argument
            std::string arg = ParseTemplateArg(mangled, pos);
            if (!arg.empty()) {
                args.push_back(arg);
            } else {
                break;
            }
        }

        // Parse namespace if present
        std::vector<std::string> namespaces;
        std::string current;
        while (pos < mangled.size()) {
            char c = mangled[pos];
            if (c == '@') {
                pos++;
                if (!current.empty()) {
                    namespaces.push_back(current);
                    current.clear();
                }
                if (pos < mangled.size() && mangled[pos] == '@') {
                    pos++; // Consume @@
                    break;
                }
            } else {
                current += c;
                pos++;
            }
        }
        if (!current.empty()) {
            namespaces.push_back(current);
        }

        // Build result
        std::string result;
        
        // Add namespace in reverse order
        if (!namespaces.empty()) {
            std::reverse(namespaces.begin(), namespaces.end());
            for (const auto& ns : namespaces) {
                result += ns + "::";
            }
        }
        
        result += templateName;
        
        // Add template arguments
        if (!args.empty()) {
            result += "<";
            for (size_t i = 0; i < args.size(); ++i) {
                if (i > 0) result += ", ";
                result += args[i];
            }
            result += ">";
        }

        return result;
    }

    // Parse a single template argument
    std::string ParseTemplateArg(const std::string& mangled, size_t& pos) const
    {
        if (pos >= mangled.size()) return "";

        char c = mangled[pos];

        // Basic types
        switch (c) {
            case 'D': pos++; return "char";
            case 'E': pos++; return "unsigned char";
            case 'F': pos++; return "short";
            case 'G': pos++; return "unsigned short";
            case 'H': pos++; return "int";
            case 'I': pos++; return "unsigned int";
            case 'J': pos++; return "long";
            case 'K': pos++; return "unsigned long";
            case 'M': pos++; return "float";
            case 'N': pos++; return "double";
            case 'X': pos++; return "void";
            case '_':
                pos++;
                if (pos < mangled.size()) {
                    char c2 = mangled[pos++];
                    switch (c2) {
                        case 'N': return "bool";
                        case 'W': return "wchar_t";
                        case 'J': return "long long";
                        case 'K': return "unsigned long long";
                    }
                }
                return "?";
        }

        // Pointer/reference modifiers
        if (c == 'P' || c == 'Q' || c == 'A') {
            pos++;
            std::string base = ParseTemplateArg(mangled, pos);
            if (c == 'P') return base + "*";
            if (c == 'Q') return base + "* const";
            if (c == 'A') return base + "&";
        }

        // User-defined type (class/struct)
        if (c == 'V' || c == 'U' || c == 'W') {
            pos++; // Skip type indicator
            return ParseMangledName(mangled, pos);
        }

        // Template
        if (c == '?' && pos + 1 < mangled.size() && mangled[pos + 1] == '$') {
            pos += 2; // Skip ?$
            return ParseTemplate(mangled, pos);
        }

        // Unknown - skip until @ or end
        pos++;
        return "?";
    }

    void PrintRTTI()
    {
        auto rttiInfo = ListRTTI();
        
        if (rttiInfo.empty()) {
            printf("// No RTTI information found\n\n");
            return;
        }

        printf("// RTTI Information (%zu classes with vtables):\n", rttiInfo.size());
        printf("// ================================================================\n\n");
        
        for (const auto& info : rttiInfo) {
            printf("// VTable Address: 0x%08x Class: %s", mImageBase + info.vtableRVA, info.demangledName.c_str());
//            printf("// Class: %s\n", info.demangledName.c_str());
//            printf("//   VTable Address: 0x%08x\n", mImageBase + info.vtableRVA);
//            printf("//   Mangled Name: %s\n", info.mangledName.c_str());
//            printf("//   Object Offset: %d\n", info.offset);
            
            // Print inheritance information
            if (!info.baseClasses.empty()) {
                printf(" (Base Classes:");
                for (const auto& base : info.baseClasses) {
                    printf(" %s", base.demangledName.c_str());
                    continue;
                    if (base.offset != 0) {
                        printf(" (offset: %d)", base.offset);
                    }
                    if (base.vbtableIndex != -1) {
                        printf(" [virtual base: vbtable_offset=%d, index=%d]", 
                               base.vbtableOffset, base.vbtableIndex);
                    }
                    printf("\n");
                }
                printf(")");
            } else {
//                printf("//   Base Classes: none\n");
            }
//            printf("\n");

//            // Print inheritance type
//            if (info.hasVirtualInheritance) {
//                printf("//   Inheritance: Virtual\n");
//            } else if (info.hasMultipleInheritance) {
//                printf("//   Inheritance: Multiple\n");
//            } else if (!info.baseClasses.empty()) {
//                printf("//   Inheritance: Single\n");
//            }

            // Print virtual functions
            if (!info.virtualFunctions.empty()) {
                printf(" (%d virtual functions)", (int)info.virtualFunctions.size());
//                printf("//   Virtual Functions (%zu):\n", info.virtualFunctions.size());
//                for (size_t i = 0; i < info.virtualFunctions.size() && i < 10; ++i) {
//                    printf("//     [%2zu] 0x%08x\n", i, info.virtualFunctions[i]);
//                }
//                if (info.virtualFunctions.size() > 10) {
//                    printf("//     ... (%zu more)\n", info.virtualFunctions.size() - 10);
//                }
            }
            
            printf("\n");
            //printf("//\n");
        }
        printf("\n");
    }
};

