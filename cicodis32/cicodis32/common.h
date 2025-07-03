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
};

using namespace utils;

class Loader {
public:
    virtual bool LoadFile(const char* executable, int loadAddress) = 0;
    virtual const uint8_t* GetBufferAt(address_t addr) = 0;
    virtual bool InRange(address_t addr, int size = 0) = 0;
    virtual address_t GetEntry() = 0;
    virtual std::string GetMain() = 0;
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
        CallWordsByOfs
    } type{None};
    
    char selector[64];
    const uint8_t* baseptr{nullptr};
    
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
        if (type == CallDwords)
        {
            assert(0);
            uint16_t* parts = (uint16_t*)baseptr;
            return address_t{parts[i*2+1], parts[i*2]};
        }
        if (type == JumpFix || type == Call)
            return GetBaseAddress();
        uint16_t* parts = (uint16_t*)baseptr;
        return address_t{instruction.segment, parts[elements[i]]};
    }
    std::string GetCase(int i) const
    {
        switch (type)
        {
            case CallWords:
                return format("case %d: sub_%x(); break;", i*2, GetTarget(i).linearOffset());
            case CallDwords:
                return format("case %d: cs = 0x%04x; sub_%x(); break;", i*4, GetTarget(i).segment, GetTarget(i).linearOffset());
            case JumpWords:
                return format("case %d: goto loc_%x;", i*2,  GetTarget(i).linearOffset());
            case JumpFix:
                return format("case 0x%04x: goto loc_%x;", GetTarget(i).offset, GetTarget(i).linearOffset());
            case Call:
            case CallWordsByOfs:
                return format("case 0x%04x: sub_%x(); break;", GetTarget(i).offset, GetTarget(i).linearOffset());
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
    std::vector<shared<jumpTable_t>> jumpTables;
    shared<jumpTable_t> GetJumpTable(address_t addr) const
    {
        for (auto jt : jumpTables)
            if (jt->instruction == addr)
                return jt;
        return nullptr;
    }
};

