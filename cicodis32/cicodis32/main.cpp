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

#include "address.h"
#include "common.h"
#include "loader.h"
#include "tracer.h"
#include "analyser.h"
#include "formatter.h"
#include "converter.h"

int main(int argc, char **argv) {
    //shared<LoaderSnapshot> loader(new LoaderSnapshot);
    shared<Loader> loader(new LoaderMz);
    if (!loader->LoadFile("GOOSE.EXE", 0x1000*16))
        return 1;
    // BP 160:15e390
    // memdumpbin 169:15e000 40000
//    if (!loader->LoadFile("MEMDUMP.BIN", 0x15e000))
//        return 1;
    Capstone->Set(loader);

    //address_t(0, 0x15e390)
    address_t entry{loader->GetEntry()};
    std::set<address_t, cmp_adress_t> process{entry};
    std::set<address_t, cmp_adress_t> processed;
        
    Analyser analyser;
    analyser.RecursiveScan(entry);
    
    printf("#include \"cico32.h\"\n\n");
    printf("%s\n", loader->GetMain().c_str());
    
    for (std::pair<address_t, std::shared_ptr<CTracer>> proc : analyser.mMethods)
        printf("void sub_%x();\n", proc.first.linearOffset());
    printf("\n");
    while (!process.empty())
    {
        address_t proc = *process.begin();
        process.erase(proc);
        processed.insert(proc);
        
        analyser.AnalyseProc(proc);
        Convert convert(analyser);
        convert.SetOffsetMask(0xffff); // 16 bit
        convert.ConvertProc(proc);
        convert.Dump();
        for (address_t call : convert.GetCalls())
            if (process.find(call) == process.end() && processed.find(call) == processed.end())
                process.insert(call);
    }
    
    return 0;
}

