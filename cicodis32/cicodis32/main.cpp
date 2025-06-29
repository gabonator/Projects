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
    shared<LoaderSnapshot> loader(new LoaderSnapshot);
    if (!loader->LoadFile("MEMDUMP.BIN", 0x15e000))
        return 1;
    
    Capstone->Set(loader);

    std::set<address_t, cmp_adress_t> process{address_t(0, 0x15e010)};
    std::set<address_t, cmp_adress_t> processed;
        
    Analyser analyser;
    analyser.RecursiveScan({0, 0x15e390});
    while (!process.empty())
    {
        address_t proc = *process.begin();
        process.erase(proc);
        processed.insert(proc);
        
        analyser.AnalyseProc(proc);
        Convert convert(analyser);
        convert.ConvertProc(proc);
        convert.Dump();
        for (address_t call : convert.GetCalls())
            if (process.find(call) == process.end() && processed.find(call) == processed.end())
                process.insert(call);
    }
    
    return 0;
}

