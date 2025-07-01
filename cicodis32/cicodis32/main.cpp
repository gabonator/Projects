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
//    Test t;
//    printf("done\n");
//    return 0;
    //shared<LoaderSnapshot> loader(new LoaderSnapshot);
    shared<Loader> loader(new LoaderMz);
    if (!loader->LoadFile("GOOSE.EXE", 0x1000*16))
        return 1;
    // BP 160:15e390
    // memdumpbin 169:15e000 40000
//    if (!loader->LoadFile("MEMDUMP.BIN", 0x15e000))
//        return 1;
    
    // 0x17c004 = 0xb020c49cl
    // 0x17c00c =
    // 0x17c014 =
//    const uint8_t* p = loader->GetBufferAt(address_t(0, 0x17c004));
//    double dp;
//    memcpy(&dp, p, 8);
//    printf("case 0x17c004: return 0x%08llx; // %g\n", *((uint64_t*)p), dp);
//    const uint8_t* p1 = loader->GetBufferAt(address_t(0, 0x17c00c));
//    memcpy(&dp, p1, 8);
//    printf("case 0x17c00c: return 0x%08llx; // %g\n", *((uint64_t*)p1), dp);
//    const uint8_t* p2 = loader->GetBufferAt(address_t(0, 0x17c014));
//    memcpy(&dp, p2, 8);
//    printf("case 0x17c014: return 0x%08llx; // %g\n", *((uint64_t*)p2), dp);
//    const uint8_t* p3 = loader->GetBufferAt(address_t(0, 0x17c01c));
//    memcpy(&dp, p3, 8);
//    printf("case 0x17c01c: return 0x%08llx; // %g\n", *((uint64_t*)p3), dp);
//    
//    const uint8_t* p4 = loader->GetBufferAt(address_t(0, 0x17c024));
//    memcpy(&dp, p4, 8);
//    printf("case 0x17c024: return 0x%08llx; // %g\n", *((uint64_t*)p4), dp);
//
//    const uint8_t* p5 = loader->GetBufferAt(address_t(0, 0x17c02c));
//    memcpy(&dp, p5, 8);
//    printf("case 0x17c02c: return 0x%08llx; // %g\n", *((uint64_t*)p5), dp);
//
//    const uint8_t* p51 = loader->GetBufferAt(address_t(0, 0x17c034));
//    memcpy(&dp, p51, 8);
//    printf("case 0x17c034: return 0x%08llx; // %g\n", *((uint64_t*)p51), dp);
//
//    const uint8_t* p6 = loader->GetBufferAt(address_t(0, 0x17c03c));
//    memcpy(&dp, p6, 8);
//    printf("case 0x17c03c: return 0x%08llx; // %g\n", *((uint64_t*)p6), dp);
//
//    const uint8_t* p7 = loader->GetBufferAt(address_t(0, 0x17c044));
//    memcpy(&dp, p7, 8);
//    printf("case 0x17c044: return 0x%08llx; // %g\n", *((uint64_t*)p7), dp);
//
//
//    const uint8_t* p8 = loader->GetBufferAt(address_t(0, 0x17c04c));
//    memcpy(&dp, p8, 8);
//    printf("case 0x17c04c: return 0x%08llx; // %g\n", *((uint64_t*)p8), dp);
//
//    const uint8_t* p9 = loader->GetBufferAt(address_t(0, 0x17c054));
//    memcpy(&dp, p9, 8);
//    printf("case 0x17c054: return 0x%08llx; // %g\n", *((uint64_t*)p9), dp);
//
//
//    return 0;
    Capstone->Set(loader);

    //address_t(0, 0x15e390)
    address_t entry{loader->GetEntry()};
//    entry.offset = 0x8ba;
    std::set<address_t, cmp_adress_t> process{entry};
    std::set<address_t, cmp_adress_t> processed;
        
    Analyser analyser;
    analyser.RecursiveScan(entry);
    
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

