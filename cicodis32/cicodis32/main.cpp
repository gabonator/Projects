/*
 header search path: /opt/homebrew/include/
 library search path: /opt/homebrew/lib
 build phases -> link binary with libraries: /opt/homebrew/lib/libcapstone.dylib
 
 */
// TODO: bool CheckCodeAddress(int seg, int ofs), inf loop
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
#include "analyserFunction.h"
#include "analyserInstruction.h"
#include "formatter.h"
#include "converter.h"

int main(int argc, char **argv) {
    Options optionsRick2 = {
        .loader = "LoaderMz",
        .exec = "RICK2.EXE",
//        .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1040, 0x5e22}},
        .jumpTables = {
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1040, 0xffff),
                .table = address_t(0x1040, 0x0000),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37},
                .selector = "indirect",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1040, 0xffff),
                .table = address_t(0x1040, 0x9bb8),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
                .selector = "indirect",
            }),
        },
        .isolateLabels = {address_t(0x1040, 0x168a8-0x10400),
            address_t(0x1040, 0x196f3-0x10400),
            address_t(0x1040, 0x1c359-0x10400),
            address_t(0x1040, 0x19f12-0x10400),
            address_t(0x1040, 0x19731-0x10400)
        }
    };
    
    Options optionsGoose = {
        .loader = "LoaderMz",
        .exec = "GOOSE.EXE",
//        .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1000, 0x101ad- 0x10000}},
//                .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1000, 0x541}},

        .jumpTables = {
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1000, 0x104e),
                .table = address_t(0x1000, 0x105a),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34},
                .selector = "bx",
            })}
    };
    Options optionsRick1 = {
        .loader = "LoaderMz",
        .exec = "rick1.exe",
//        .verbose = true,  .relocations = false, .recursive = false, .start = false, .procList = {{0x341b, 0x36413- 0x341b0}},
//        .verbose = true,  .relocations = false, .recursive = false, .start = false, .procList = {{0x341b, 0x354c7- 0x341b0}},
        //sub_34442
        .jumpTables = {
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x341b, 0x228a),
                .table = address_t(0x1040, 0x80bf),
                .type = jumpTable_t::JumpWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                23},
                .selector = "di",
            })}
    };
    Options optionsFox = {
        .loader = "LoaderMz",
        .exec = "fox.exe",
//        .verbose =true,
//        .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1020, 0x6582}},
//        .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1020, 0x65be}},

        
//        .relocations = false, .recursive = false, .start = false, .procList = {{0x1020, 0x1c61}},
//        .relocations = false, .recursive = false, .start = false, .procList = {{0x1020, 0x40fa}},
//        .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1020, 0x12b94 - 0x10200}},
        
        //sub_1434b
        //1020:40fa
        //sub_34442
        .jumpTables = {
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x42e6),
                .table = address_t(0x168f, 0x6efb),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                23, 24, 25, 26, 27, 28, 29},
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x45a0),
                .table = address_t(0x168f, 0x727d),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x45cf),
                .table = address_t(0x168f, 0x7299),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58},
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x4629),
                .table = address_t(0x168f, 0x726f),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x5961),
                .table = address_t(0x168f, 0x8eb5),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37},
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x464b),
                .table = address_t(0x168f, 0x726F),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x57e4),
                .table = address_t(0x168f, 0x8EDB),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                .selector = "bx",
            }),
        }
    };

//    Options options = optionsGoose;
//    Options options = optionsRick2;
    Options options = optionsFox;
//    Options options = optionsRick1;

    shared<Loader> loader;
    if (strcmp(options.loader, "LoaderMz") == 0)
        loader.reset(new LoaderMz);
    else if (strcmp(options.loader, "LoaderSnapshot") == 0)
        loader.reset(new LoaderSnapshot);
    else
        assert(0);
    
    if (!loader->LoadFile(options.exec, options.loadAddress))
        return 1;
    // BP 160:15e390
    // memdumpbin 169:15e000 40000
    //    if (!loader->LoadFile("MEMDUMP.BIN", 0x15e000))
    //        return 1;
    Capstone->Set(loader);

    
    bool anyIndirectTable = false;
    for (auto t : options.jumpTables)
    {
        t->baseptr = loader->GetBufferAt(t->table);
        if (strcmp(t->selector, "indirect") == 0)
            anyIndirectTable = true;
    }

    std::vector<address_t> startEntries;
    
    if (options.start)
        startEntries.push_back(loader->GetEntry());
    for (address_t p : options.procList)
        startEntries.push_back(p);
    for (address_t p : options.isolateLabels)
        startEntries.push_back(p);
    for (shared<jumpTable_t> j : options.jumpTables)
        for (int i=0; i<j->GetSize(); i++)
            startEntries.push_back(j->GetTarget(i));
    
    printf("#include \"cico32.h\"\n\n");
    
    if (options.relocations)
        printf("%s\n", loader->GetMain().c_str()); // TODO: updates relocations
    
    std::map<address_t, procRequest_t, cmp_adress_t> procModifiers;
//    procModifiers.insert(std::pair<address_t, procRequest_t>({0x1040, 0x5e22}, procRequest_t::returnCarry)); // rick2
//    procModifiers.insert(std::pair<address_t, procRequest_t>({0x341b, 0x354c7- 0x341b0}, procRequest_t::returnZero)); // rick1 - ignored in final listing TODO!
//        procModifiers.insert(std::pair<address_t, procRequest_t>({0x1020, 0x12b94 - 0x10200}, procRequest_t::returnCarry)); // rick1 - ignored in final listing TODO!

    Analyser analyser(options);
    if (options.recursive)
    {
        analyser.RecursiveScan(startEntries);
    } else {
        for (address_t p : options.procList)
            analyser.Scan(p);
    }

    if (options.declarations)
    {
        for (address_t proc : analyser.AllMethods())
            printf("void sub_%x();\n", proc.linearOffset());
        printf("\n");
    }

    if (anyIndirectTable)
    {
        printf("void callIndirect(int seg, int ofs)\n{\n");
        for (auto table : options.jumpTables)
            if (strcmp(table->selector, "indirect") == 0)
            {
                std::set<int> used;
                printf("    if (seg == 0x%04x)\n    {\n", table->instruction.segment);
                printf("        switch (ofs)\n");
                printf("        {\n");
                for (int i : table->elements)
                {
                    int v = table->GetTarget(i).offset;
                    if (used.find(v) != used.end())
                        continue;
                    used.insert(v);
                    printf("            case 0x%x: sub_%x(); return;\n", table->GetTarget(i).offset, table->GetTarget(i).linearOffset());
                }
                
                printf("        }\n");
                printf("    }\n");
                
            }
        printf("}\n\n");
    }
    
    std::set<address_t, cmp_adress_t> processNew;
    processNew = analyser.AllMethods();
    
    while (!processNew.empty())
    {
        std::set<address_t, cmp_adress_t> process = processNew;
        processNew.clear();
        
        for (address_t proc : process)
        {
            procRequest_t modifier = procRequest_t::returnNone;
            if (procModifiers.find(proc) != procModifiers.end())
                modifier = procModifiers.find(proc)->second;
            
            analyser.AnalyseProc(proc, modifier);
            if (options.recursive)
                for (std::pair<address_t, procRequest_t> req : analyser.GetRequests(proc))
                {
                    procRequest_t oldModifier = procRequest_t::returnNone;
                    if (procModifiers.find(req.first) != procModifiers.end())
                        oldModifier = procModifiers.find(proc)->second;
                    
                    if (oldModifier != req.second)
                    {
                        procModifiers.insert(req);
                        processNew.insert(req.first);
                    }
                }
        }
    }
//    std::map<address_t, int, cmp_adress_t> hits;
//    for (address_t proc : analyser.AllMethods())
//    {
//        for (address_t label : analyser.GetGapLabels(proc))
//        {
//            if (hits.find(label) != hits.end())
//                hits.find(label)->second++;
//            else
//                hits.insert(std::pair<address_t, int>(label, 1));
//        }
//    }

    for (address_t proc : analyser.AllMethods())
    {
        Convert convert(analyser, options);
        convert.SetOffsetMask(0xffff); // 16 bit
        convert.ConvertProc(proc);
        convert.Dump();
    }

//    for (std::pair<address_t, int> p : hits)
//    {
//        if (p.second > 1)
//            printf("// %d refs to loc_%x\n", p.second, p.first.linearOffset());
//    }


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
