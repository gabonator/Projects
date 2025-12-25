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
        PrintImports();
        PrintSections();
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

    virtual std::string GetInit() override { return "-- todo --\n";}
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

        uint32_t symAddr = 0x6ab00000;
        std::string indirectImport = "switch ((ptrImportTable)o) {\n";
        std::string indirectEnum = format("enum class ptrImportTable {\n    ptr_begin = 0x%x,\n", symAddr);
        for (const auto& [addr, imp] : GetImports())
        {
//            *((uint32_t*)GetBufferAt(addr)) = ++symAddr;
            indirectEnum += format("    ptr_%s_%s,\n", imp->namesp.c_str(), imp->symbol.c_str());
            indirectImport += format("    case ptrImportTable::ptr_%s_%s:\n        %s\n        break;\n", imp->namesp.c_str(), imp->symbol.c_str(), imp->call.c_str());
        }
        indirectEnum += "};\n";
        indirectImport += "}\n";

        for (const auto& sec : mSections) {
            uint32_t start = mImageBase + sec.vaddr;
            
            char outname[1024];
            snprintf(outname, sizeof(outname), "%s_%s.bin", key.c_str(), sec.name.substr(1).c_str());
            overlays += format("    loadOverlay(\"%s_%s.bin\", 0x%x);\n", key.c_str(), sec.name.substr(1).c_str(), start);
        }

        return includes + format("\nvoid sub_%x();\n\nvoid init()\n{\n%s    esp = 0x%x;\n    ebp = 0x%x;\n}\n\nvoid start()\n{\n    sub_%x();\n}\n",
                      mImageBase + mEntryPoint,
                      overlays.c_str(), 
                      mImageBase + mSizeOfImage,
                      mImageBase + mSizeOfImage,
                      mImageBase + mEntryPoint) + indirectEnum + indirectImport;
        
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
                        assert(0);
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
                    namesp,
                    getStackShift(it2->second),
                    0);
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
                    namesp,
                    getStackShift(it2->second),
                    0);
                mImports.insert({impSymbol->addr, impSymbol});
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
};

