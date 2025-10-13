//
//  common.h
//  cicodis32
//
//  Created by Gabriel Valky on 01/07/2025.
//

template<typename T> using shared = std::shared_ptr<T>;

namespace utils {
    std::string format(const char* fmt, ...)
    {
        char buf[4096];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buf, 4096, fmt, args);
        va_end(args);
        return std::string(buf);
    }
    std::string join(std::vector<std::string> tokens, std::string spacer)
    {
        std::string aux;
        for (std::string t : tokens)
        {
            if (!aux.empty())
                aux += spacer;
            aux += t;
        }
        return aux;
    }

    std::vector<std::string> split(const std::string& input, const std::string& delimiter) {
        std::vector<std::string> result;
        
        if (delimiter.empty()) {
            result.push_back(input); // or throw std::invalid_argument
            return result;
        }
        
        size_t start = 0;
        size_t end;
        
        while ((end = input.find(delimiter, start)) != std::string::npos) {
            result.push_back(input.substr(start, end - start));
            start = end + delimiter.length();
        }
        
        result.push_back(input.substr(start)); // Add the last segment
        return result;
    }
    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        if (first == std::string::npos)
            return ""; // all spaces

        size_t last = str.find_last_not_of(' ');
        return str.substr(first, last - first + 1);
    }

    std::string replace(std::string str, const std::string& find, const std::string& replace) {
        if (find.empty()) return str; // avoid infinite loop

        size_t pos = 0;
        while ((pos = str.find(find, pos)) != std::string::npos) {
            str.replace(pos, find.length(), replace);
            pos += replace.length(); // move past the replaced part
        }
        return str;
    }
};

using namespace utils;

class Loader {
public:
    static std::vector<uint8_t> GetFileContents(std::string fullPath);
    virtual bool LoadFile(const char* executable, int loadAddress) = 0;
    virtual const uint8_t* GetBufferAt(address_t addr) = 0;
    virtual const uint8_t* GetBufferAt(int offset) = 0;
    virtual bool InRange(address_t addr, int size = 0) = 0;
    virtual address_t GetEntry() = 0;
    virtual std::string GetMain() = 0;
    virtual std::string GetFooter() = 0;
    virtual void Overlay(address_t addr, const std::vector<uint8_t>& bytes) = 0;
};

struct jumpTable_t {
    address_t instruction;
    address_t table;
    std::vector<int> elements;
    enum switch_e {
        None,
        CallWords,
        CallDwords,
        JumpWords,
        JumpFix,
        Call,
        Call32,
        Jump32
//        CallWordsByOfs
    } type{None};
    
    std::string selector;
    const uint8_t* baseptr{nullptr};
    bool release{false};
    int minaddr{0};
    bool useCaseOffset{false};
    
    int fileoffset{0};
    int filestep{0};
    int filecount{0};
    
    ~jumpTable_t()
    {
        if (release)
        {
            assert(baseptr);
            delete baseptr;
            baseptr = nullptr;
        }
    }
    address_t GetBaseAddress() const
    {
        return table;
    }
    int GetSize() const
    {
        return (int)elements.size();
    }
    address_t GetAddressAt(int i) const
    {
        int size = type == CallDwords ? 4 : 2;
        return {table.segment, table.offset + elements[i]*size};
    }
    address_t GetTarget(int i) const
    {
        if (filestep)
        {
            if (type == CallDwords)
            {
                uint16_t* parts = (uint16_t*)(baseptr + i*filestep);
                return address_t{parts[1], parts[0]};
            }
            assert(0);
        }
        if (type == CallDwords)
        {
//            assert(0);
            uint16_t* parts = (uint16_t*)baseptr;
            return address_t{parts[i*2+1], parts[i*2]};
        }
        if (type == Call32 || type == Jump32)
        {
            uint32_t* parts = (uint32_t*)baseptr;
            return address_t{instruction.segment, (int)parts[i]};
        }
        if (type == JumpFix || type == Call)
            return GetBaseAddress();
        uint16_t* parts = (uint16_t*)baseptr;
        return address_t{instruction.segment, parts[elements[i]]};
    }
    bool IsValid(int i) const
    {
        if (minaddr == 0)
            return true;
        if (type == Jump32 || type == Call32)
        {
            uint32_t* parts = (uint32_t*)baseptr;
            return parts[elements[i]] >= minaddr;
        }
        assert(type == CallWords || type == JumpWords || type == Jump32);
        uint16_t* parts = (uint16_t*)baseptr;
        return parts[elements[i]] >= minaddr;
    }
    std::string GetCase(int i) const
    {
        assert(IsValid(i));
        switch (type)
        {
            case CallWords:
                if (useCaseOffset)
                    return format("case 0x%04x: sub_%x(); break;", GetTarget(i).offset, GetTarget(i).linearOffset());
                else
                    return format("case %d: sub_%x(); break;", i*2, GetTarget(i).linearOffset());
            case CallDwords:
                if (useCaseOffset)
                    return format("case 0x%x: push(cs); cs = 0x%04x; sub_%x(); assert(cs == 0x%04x); break;", (GetTarget(i).segment<<16) | GetTarget(i).offset, GetTarget(i).segment, GetTarget(i).linearOffset(), instruction.segment);
                else
                    return format("case %d: push(cs); cs = 0x%04x; sub_%x(); assert(cs == 0x%04x); break;", i*4, GetTarget(i).segment, GetTarget(i).linearOffset(), instruction.segment);
            case JumpWords:
            {
                if (useCaseOffset)
                    return format("case 0x%04x: goto loc_%x;", GetTarget(i).offset,  GetTarget(i).linearOffset());
                else
                    return format("case %d: goto loc_%x;", i*2,  GetTarget(i).linearOffset());
            }
            case JumpFix:
                return format("case 0x%04x: goto loc_%x;", GetTarget(i).offset, GetTarget(i).linearOffset());
            case Call:
//            case CallWordsByOfs:
                return format("case 0x%04x: sub_%x(); break;", GetTarget(i).offset, GetTarget(i).linearOffset());
            case Call32:
                if (useCaseOffset)
                    return format("case 0x%x: sub_%x(); break;", GetTarget(i).offset, GetTarget(i).linearOffset());
                else
                    return format("case %d: sub_%x(); break;", i, GetTarget(i).linearOffset());
            case Jump32:
                if (useCaseOffset)
                    return format("case 0x%x: goto loc_%x;", GetTarget(i).offset, GetTarget(i).linearOffset());
                else
                    return format("case %d: goto loc_%x;", i, GetTarget(i).linearOffset());
            default:
                assert(0);
                return "stop(/*3*/);";
        }
    }
    std::string GetSelector() const
    {
        return selector;
    }
};

enum class procRequest_t
{
    none = 0,
    returnCarry = 1,
    returnZero = 2,
//    stackDrop2 = 4,
    callNear = 8,
    callFar = 16,
    callIsolated = 512,
    popsCs = 1024,
    nearAsFar = 2048,
    entry = 4096,
    callLong = 8192,
};

enum class arch_t {
    archNone = 0,
    arch16 = 1,
    arch32 = 2
};

struct indirectJump_t
{
    address_t target;
    address_t parent;
    address_t origin;
};

class Options {
public:
    //-jumptable 1000:104e 1000:105a 35 callwords bx"
//    struct jumptable_t {
//        address_t instruction;
//        address_t table;
//        enum { callWords } type;
//        int width;
//        int entries;
//        char index[32];
//    };
    char loader[32];
    char exec[1024];
    bool recursive{true};
    bool start{true};
    bool relocations{true};
    bool declarations{true};
    int loadAddress{0x10000};
    arch_t arch{arch_t::archNone};
    bool simpleStack{false};
    bool stackShiftAlways{false};
    bool jit{false};
    
    std::vector<address_t> procList;
    std::vector<shared<jumpTable_t>> jumpTables;
    std::set<address_t> isolateLabels;
    std::set<address_t> terminators;
    std::map<address_t, procRequest_t> procModifiers;
    std::map<address_t, int> procModifiersStack;
    std::map<address_t, std::string> inject;
    std::set<address_t> marks;
    std::vector<indirectJump_t> indirectCalls;
    std::vector<indirectJump_t> indirectJumps;
    std::vector<shared<jumpTable_t>> GetJumpTables(address_t addr) const
    {
        std::vector<shared<jumpTable_t>> aux;
        for (auto jt : jumpTables)
            if (jt->instruction == addr)
                aux.push_back(jt);
//                return jt;
//        return nullptr;
        return aux;
    }
    bool verbose{false};
    bool verboseAsm{false};
    bool printProcAddress{false};
    bool printLabelAddress{false};
    bool printOpcodes{true};
    
    address_t overlayBase;
    std::vector<uint8_t> overlayBytes;
};

template<typename T, typename U> T check(T o, U end)
{
    assert (o != end);
    return o;
}
