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
#include "profiles.h"

int main(int argc, char **argv) {
//    Options options = Profiles::optionsGoose;
//    Options options = Profiles::optionsRick2;
//    Options options = Profiles::optionsFox;
//    Options options = Profiles::optionsRick1;
//    Options options = Profiles::optionsBumpy;
//    Options options = Profiles::optionsAv;
    Options options = {
        // BP 160:15e390
        // memdumpbin 169:15e000 40000
//        .loader = "LoaderSnapshot",
//        .exec = "MEMDUMP.BIN",
        .loader = "LoaderLe",
        .loadAddress = 0x15e000,
        .exec = "MANDEL.EXE",
        .procList = {{0, 0x15fba3}}
//        .start = true,
//        .verbose = true,
    };
//    options.verbose = true;
//    options.printProcAddress = true;
    //options.printLabelAddress = true;
    
    shared<Loader> loader;
    if (strcmp(options.loader, "LoaderMz") == 0)
        loader.reset(new LoaderMz);
    else if (strcmp(options.loader, "LoaderSnapshot") == 0)
        loader.reset(new LoaderSnapshot);
    else if (strcmp(options.loader, "LoaderLe") == 0)
        loader.reset(new LoaderLe);
    else
        assert(0);
    
    if (!loader->LoadFile(options.exec, options.loadAddress))
    {
        printf("Cannot open file %s\n", options.exec);
        return 1;
    }
    Capstone->Set(loader, options);

    
    bool anyIndirectTable = false;
    for (auto t : options.jumpTables)
    {
        if (!t->baseptr)
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
    {
        options.procModifiers.insert({p, procRequest_t::callIsolated});
        startEntries.push_back(p);
    }
    for (shared<jumpTable_t> j : options.jumpTables)
        if (j->type == jumpTable_t::Call || j->type == jumpTable_t::CallWords)
        for (int i=0; i<j->GetSize(); i++)
            if (j->IsValid(i))
                startEntries.push_back(j->GetTarget(i));
    
    for (address_t p : startEntries)
    {
        if (options.procModifiers.find(p) == options.procModifiers.end())
            options.procModifiers.insert({p, procRequest_t::callNear});
    }

    printf("#include \"cico32.h\"\n\n");
    
    if (options.relocations)
        printf("%s\n", loader->GetMain().c_str());

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
                    if (!table->IsValid(i))
                        continue;
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
    
    std::set<address_t> processNew;
    processNew = analyser.AllMethods();
    // TODO: call conv!
    
    while (!processNew.empty())
    {
        std::set<address_t> process = processNew;
        processNew.clear();
        
        for (address_t proc : process)
        {
            procRequest_t modifier = procRequest_t::none;
            if (options.procModifiers.find(proc) != options.procModifiers.end())
                modifier = options.procModifiers.find(proc)->second;
            
            analyser.AnalyseProc(proc, modifier);
            if (options.recursive)
            {
                for (std::pair<address_t, procRequest_t> req : analyser.GetRequests(proc))
                {
                    procRequest_t oldModifier = procRequest_t::none;
                    if (options.procModifiers.find(req.first) != options.procModifiers.end())
                        oldModifier = options.procModifiers.find(req.first)->second;
                    
                    if (oldModifier != req.second)
                    {
                        req.second = (procRequest_t)((int)req.second | (int)oldModifier);
                        if (options.procModifiers.find(req.first) != options.procModifiers.end())
                            options.procModifiers.find(req.first)->second = req.second;
                        else
                            options.procModifiers.insert(req);
                        processNew.insert(req.first);
                    }
                }
            }
        }
    }

    for (address_t proc : analyser.AllMethods())
    {
        Convert convert(analyser, options);
        convert.SetOffsetMask(options.arch == arch_t::arch16 ? 0xffff : -1); // 16 bit
        convert.ConvertProc(proc);
        convert.Dump();
    }
    
    if (options.relocations)
        printf("%s\n", loader->GetFooter().c_str());

    std::vector<int> procMap;
    for (address_t proc : analyser.AllMethods())
    {
        for (const auto& [begin, end] : analyser.GetProcRanges(proc))
        {
            procMap.push_back(proc.linearOffset());
            procMap.push_back(begin.segment);
            procMap.push_back(begin.offset);
            procMap.push_back(end.segment);
            procMap.push_back(end.offset);
        }
    }

    printf("int GetProcAt(int seg, int ofs)\n");
    printf("{\n");
    printf("    int map[] = {\n");
    for (int i=0; i<procMap.size(); i++)
    {
        if (i%10 == 0)
            printf("        ");
        printf("0x%x, ", procMap[i]);
        if (i%10 == 9)
            printf("\n");
    }
    printf("    };\n");
    printf("    for (int i=0; i<sizeof(map)/sizeof(map[0]); i+=5)\n");
    printf("        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs <= map[i+3]*16 + map[i+4])\n");
    printf("            return map[i];\n");
    printf("    return 0;\n");
    printf("}\n");

//    std::map<address_t, int> hits;
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

//    for (std::pair<address_t, int> p : hits)
//    {
//        if (p.second > 1)
//            printf("// %d refs to loc_%x\n", p.second, p.first.linearOffset());
//    }


    return 0;
}
