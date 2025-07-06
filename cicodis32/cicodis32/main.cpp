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
        
    Options options;
//    options.recursive = false;
    options.jumpTables.push_back(std::shared_ptr<jumpTable_t>(new jumpTable_t{
        .instruction = address_t(0x1000, 0x104e),
        .table = address_t(0x1000, 0x105a),
        .type = jumpTable_t::CallWords,
        .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
        23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34},
        .selector = "bx",
        .baseptr = loader->GetBufferAt(address_t(0x1000, 0x105a))
    }));
    
    address_t entry{loader->GetEntry()};
//    entry = {0x1000, 0x1c0a};
    std::set<address_t, cmp_adress_t> process{entry};
    std::set<address_t, cmp_adress_t> processed;
    std::vector<address_t> startEntries{entry};
    
    for (shared<jumpTable_t> j : options.jumpTables)
        for (int i=0; i<j->GetSize(); i++)
            startEntries.push_back(j->GetTarget(i));
        
    printf("#include \"cico32.h\"\n\n");
    printf("%s\n", loader->GetMain().c_str()); // TODO: updates relocations

    Analyser analyser;
    analyser.RecursiveScan(startEntries);

    for (std::pair<address_t, std::shared_ptr<CTracer>> proc : analyser.mMethods)
        printf("void sub_%x();\n", proc.first.linearOffset());
    printf("\n");
    while (!process.empty())
    {
        address_t proc = *process.begin();
        process.erase(proc);
        processed.insert(proc);
        
        analyser.AnalyseProc(proc);
        Convert convert(analyser, options);
        convert.SetOffsetMask(0xffff); // 16 bit
        convert.ConvertProc(proc);
        convert.Dump();
        if (options.recursive)
        {
            for (address_t call : convert.GetCalls())
                if (process.find(call) == process.end() && processed.find(call) == processed.end())
                    process.insert(call);
        }
    }
    
    return 0;
}







/*
 // -jumptable 01ed:46dc 01ed:4725 4 jumpwords bx
 address_t indirectJumpAddr = address_t::fromString(argv[++i]);
 address_t jumpTableBegin = address_t::fromString(argv[++i]);
 const char* strJumpEntries = argv[++i];

 std::vector<int> jumpEntries;
 if (strstr(strJumpEntries, "-"))
 {
     int jumpTableEntriesBegin = (int)strtol(strJumpEntries, nullptr, 10);
     strJumpEntries = strstr(strJumpEntries, "-")+1;
     int jumpTableEntriesEnd = (int)strtol(strJumpEntries, nullptr, 10);
     for (int i=jumpTableEntriesBegin; i<=jumpTableEntriesEnd; i++)
         jumpEntries.push_back(i);
 } else
 {
     int jumpTableEntries = (int)strtol(strJumpEntries, nullptr, 10);
     for (int i=0; i<jumpTableEntries; i++)
         jumpEntries.push_back(i);
 }
 
 const char* jumpTableEntryType = argv[++i];
 
 switch_t::switch_e tableType = switch_t::switch_e::None;
 if (strcmp(jumpTableEntryType, "jumpwords") == 0)
     tableType = switch_t::switch_e::JumpWords;
 if (strcmp(jumpTableEntryType, "callwords") == 0)
     tableType = switch_t::switch_e::CallWords;
 if (strcmp(jumpTableEntryType, "calldwords") == 0)
     tableType = switch_t::switch_e::CallDwords;
 if (strcmp(jumpTableEntryType, "jumpfix") == 0)
     tableType = switch_t::switch_e::JumpFix;
 if (strcmp(jumpTableEntryType, "call") == 0)
     tableType = switch_t::switch_e::Call;
 if (strcmp(jumpTableEntryType, "callwordsbyofs") == 0)
     tableType = switch_t::switch_e::CallWordsByOfs;
 assert(tableType != switch_t::switch_e::None);
 
 const char* jumpSelector = argv[++i];
 
 x86_reg index = X86_REG_INVALID;
 if (strcmp(jumpSelector, "bx") == 0)
     index = X86_REG_BX;
 else if (strcmp(jumpSelector, "di") == 0)
     index = X86_REG_DI;
 else if (strcmp(jumpSelector, "bp") == 0)
     index = X86_REG_BP;
 else if (strcmp(jumpSelector, "ax") == 0)
     index = X86_REG_AX;
 else if (strcmp(jumpSelector, "si") == 0)
     index = X86_REG_SI;
 else if (strcmp(jumpSelector, "none") == 0)
     index = X86_REG_INVALID;
 else if (strcmp(jumpSelector, "indirect") == 0)
     index = X86_REG_INVALID;
 else
     assert(0);
 if (strcmp(jumpSelector, "indirect") == 0)
     jumpTables.push_back({indirectJumpAddr, jumpTableBegin, jumpEntries, tableType, index, nullptr});
 else
     jumpTables.push_back({indirectJumpAddr, jumpTableBegin, jumpEntries, tableType, index, nullptr});

 */
