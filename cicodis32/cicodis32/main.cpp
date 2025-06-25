/*
 header search path: /opt/homebrew/include/
 library search path: /opt/homebrew/lib
 build phases -> link binary with libraries: /opt/homebrew/lib/libcapstone.dylib
 
 */
#include <capstone/platform.h>
#include <capstone/capstone.h>
#include <stdint.h>
#include <assert.h>
#include <regex>
#include <list>
#include <map>
#include <set>

template<typename T> using shared = std::shared_ptr<T>;
#include "address.h"
#include "loader.h"
#include "tracer.h"
#include "analyser.h"
#include "formatter.h"
#include "converter.h"


int main(int argc, char **argv) {
    size_t file_size;
//    uint8_t *file_data = (uint8_t *)load_file("MANDEL.EXE", &file_size);
//    if (!file_data) return 1;
//    Capstone->Set(file_data, file_size, 0x15e010 - 0x1560); //0x10390-0x18e0);

    shared<LoaderSnapshot> loader(new LoaderSnapshot);
    if (!loader->LoadFile("MEMDUMP.BIN", 0x15e000))
        return 1;
    
    Capstone->Set(loader);

    address_t test(0, 0x164000);
    Analyser analyser;
    analyser.RecursiveScan({0, 0x15e390});
//    analyser.RecursiveScan({0, 0x15e370});
    //analyser.AnalyseProc({0, 0x15e370});
//    analyser.AnalyseProc({0, 0x15fac8});
    analyser.AnalyseProc(test);
    Convert convert(analyser);
//    convert.ConvertProc({0, 0x15e370});
//    convert.ConvertProc({0, 0x15fac8});
    convert.ConvertProc(test);
    
    
    return 0;
}

