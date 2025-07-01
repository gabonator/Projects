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
        char buf[256];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buf, 256, fmt, args);
        va_end(args);
        return std::string(buf);
    }
};

class Loader {
public:
    virtual bool LoadFile(const char* executable, int loadAddress) = 0;
    virtual const uint8_t* GetBufferAt(address_t addr) = 0;
    virtual bool InRange(address_t addr, int size = 0) = 0;
    virtual address_t GetEntry() = 0;
};

using namespace utils;
