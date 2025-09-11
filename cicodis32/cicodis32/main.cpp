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
//#include "profiles.h"
#include "json.h"

int main(int argc, char **argv) {
//    Options options = Profiles::optionsGoose;
//    Options options = Profiles::optionsRick2;
//    Options options = Profiles::optionsFox;
//    Options options = Profiles::optionsRick1;
//    Options options = Profiles::optionsBumpy;
//    Options options = Profiles::optionsAv;
//    Options options = Profiles::optionsCC1;
//    Options options = Profiles::optionsCK1;
//    Options options = Profiles::optionsCK4a;
//    options.verbose = true;
    Options options;
    options.printProcAddress = true;
    options.printLabelAddress = true;
//    options.verboseAsm = true;

#if 1
    assert(argc==2);
    std::vector<uint8_t> optFile = Loader::GetFileContents(argv[1]);
    assert(!optFile.empty());
    
    const char* strJson = (const char*)&optFile[0]; //R"({"id": "config", "loader": "LoaderMz", "executable": "KEEN4.EXE", "architecture": "arch16", "loadAddres": 0x01ed0})";
#else
    std::string strJson = R"({"id": "config", "loader": "LoaderMz", "executable": "KEEN4.EXE", "architecture": "arch16", "loadAddress": 0x01ed0, "verboseAsm": false}
//{"id": "config", "recursive": false, "relocations": false, "verboseAsm": true, "procList": ["01ed:35e1"]}
{"id": "indirectCall", "proc": "01ed:12a3"}
{"id": "inject", "addr": "01ed:35e1", "text": "//quiet"})";
#endif

    for (std::string line : utils::split(strJson, "\n"))
    {
        if (line.empty() || line.starts_with("//"))
            continue;
        CJson json(line.c_str());
        if (json["id"] == "config")
        {
            json.ForEach([&](const CSubstring& k, const CSubstring& v){
                if (k == "id")
                    return;
                if (k == "loader")
                    v.ToString(options.loader, sizeof(options.loader));
                else if (k == "executable")
                    v.ToString(options.exec, sizeof(options.exec));
                else if (k == "architecture" && v == "arch16")
                    options.arch = arch_t::arch16;
                else if (k == "architecture" && v == "arch32")
                    options.arch = arch_t::arch32;
                else if (k == "loadAddress")
                    options.loadAddress = CConversion(v).ToInt();
                else if (k == "verboseAsm" && v == "true")
                    options.verboseAsm = true;
                else if (k == "verboseAsm" && v == "false")
                    options.verboseAsm = false;
                else if (k == "recursive" && v == "false")
                    options.recursive = false;
                else if (k == "relocations" && v == "false")
                    options.relocations = false;
                else if (k == "stackShiftAlways" && v == "true")
                    options.stackShiftAlways = true;
                else if (k == "procList")
                {
                    CJson(v).ForEach([&](const CSubstring& v)
                    {
                        options.procList.push_back(address_t::fromString(CJson(v).GetString()));
                    });
                }
                else
                {
                    char temp1[128];
                    char temp2[128];
                    printf("Wrong attribute: %s=%s\n", k.ToString(temp1, 128), v.ToString(temp2, 128));
                    //                printf("Wrong attribute: k=%s\n", k.GetString());
                    //                printf("Wrong attribute: v=%s\n", v.GetString());
                    assert(0);
                }
            });
        } else
        if (json["id"] == "indirectCall")
        {
            options.indirectCalls.insert(address_t::fromString(json["proc"].GetString()));
        } else
        if (json["id"] == "indirectJump")
        {
            address_t target = address_t::fromString(json["target"].GetString());
            address_t parent = address_t::fromString(json["parent"].GetString());
            address_t origin = address_t::fromString(json["origin"].GetString());
            options.indirectJumps.push_back({.target = target, .parent = parent, .origin = origin});
        } else
        if (json["id"] == "inject")
        {
            options.inject.insert({address_t::fromString(json["addr"].GetString()), json["text"].GetString()});
        } else
        {
            printf("Wrong json: '%s'\n", line.c_str());
            assert(0);
        }
    }
    
    //sub_3c4b

    shared<Loader> loader;
    if (strcmp(options.loader, "LoaderMz") == 0)
        loader.reset(new LoaderMz);
    else if (strcmp(options.loader, "LoaderSnapshot") == 0)
        loader.reset(new LoaderSnapshot);
    else if (strcmp(options.loader, "LoaderLe") == 0)
        loader.reset(new LoaderLe);
    else
        assert(0);
    
//    for (int i=2; i<argc; i++)
//        options.indirects.insert(address_t::fromString(argv[i]));
    
    if (!loader->LoadFile(options.exec, options.loadAddress))
    {
        printf("Cannot open file %s\n", options.exec);
        return 1;
    }
    Capstone->Set(loader, options);

    
    bool anyIndirectTable = false;
    for (auto t : options.jumpTables)
    {
//        int fileoffset{0};
//        int filestep{0};
//        int filecount{0};
        if (t->fileoffset)
            t->baseptr = loader->GetBufferAt(t->fileoffset);
        if (t->filecount)
        {
            for (int i=0; i<t->filecount; i++)
                t->elements.push_back(i);
        }

        if (!t->baseptr)
            t->baseptr = loader->GetBufferAt(t->table);
        if (strcmp(t->selector, "indirect") == 0)
            anyIndirectTable = true;
    }

    std::vector<address_t> startEntries;
    
    if (options.start)
    {
        options.procModifiers.insert({loader->GetEntry(), procRequest_t{(int)procRequest_t::entry | (int) procRequest_t::callNear}});
        startEntries.push_back(loader->GetEntry());
    }
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

    for (address_t proc : options.indirectCalls)
    {
        startEntries.push_back(proc);
    }

    for (indirectJump_t j : options.indirectJumps)
    {
        options.procModifiers.insert({j.target, procRequest_t::callIsolated});
        startEntries.push_back(j.target);
    }

    for (address_t p : startEntries)
    {
        if (options.procModifiers.find(p) == options.procModifiers.end())
            options.procModifiers.insert({p, procRequest_t::callNear});
    }
    
    printf("#include \"cico%s.h\"\n\n", options.arch == arch_t::arch16 ? "16" : "32");
    
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

    printf(R"(#include <stdio.h>

void callIndirect(int s, int o)
{
    switch (s*0x10000+o)
    {
)");
    for (address_t proc : options.indirectCalls)
    {
        printf("        case 0x%x: sub_%x(); break;\n", proc.segment*0x10000 + proc.offset, proc.linearOffset());
    }
    printf(R"(        default:
            printf("\nMISSING INDIRECT CALL %%04x:%%04x\n", s, o);
            exit(3);
    }
}

void indirectJump(int s, int o, const char* info)
{
    switch (s*0x10000+o)
    {
)");
    for (const indirectJump_t& j : options.indirectJumps)
    {
        printf("        case 0x%x: sub_%x(); break;\n", j.target.segment*0x10000 + j.target.offset, j.target.linearOffset());
    }
    printf(R"(        default:
            printf("\nMISSING INDIRECT JUMP %%04x:%%04x @ %%s\n", s, o, info);
            exit(3);
    }
}

)");
    
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
    
    std::set<address_t> processFinal;
    std::set<address_t> processFinal2;
    std::set<address_t> processFinal3;
    std::set<address_t> processFinal4;
    std::set<address_t> processFinal5;
    std::set<address_t> processFinal6;
    for (indirectJump_t j : options.indirectJumps)
    {
        processFinal.insert(j.target);
        processFinal2.insert(j.target);
        processFinal3.insert(j.target);
        processFinal4.insert(j.target);
        processFinal5.insert(j.target);
        processFinal6.insert(j.target);
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
//            int modifierStack = 0;
//            if (options.procModifiersStack.find(proc) != options.procModifiersStack.end())
//                modifierStack = options.procModifiersStack.find(proc)->second;
            int modifierStack = analyser.GuessStackBalanceForProcCached(proc);

            if (processFinal.empty() && (int)modifier & (int)procRequest_t::callIsolated)
            {
                // find parent, reuse attributes
                for (indirectJump_t j : options.indirectJumps)
                    if (j.target == proc)
                    {
                        if (options.procModifiers.find(j.parent) != options.procModifiers.end())
                            modifier = procRequest_t{(int)modifier | (int)options.procModifiers.find(j.parent)->second};
                        modifierStack = analyser.GuessStackBalanceForProcCached(j.parent);
                        break;
                    }
            }

            analyser.AnalyseProc(proc, modifier, modifierStack);
            if (options.recursive)
            {
                for (std::pair<address_t, procRequest_t> req : analyser.GetRequests(proc))
                {
                    procRequest_t oldModifier = procRequest_t::none;
                    if (options.procModifiers.find(req.first) != options.procModifiers.end())
                        oldModifier = options.procModifiers.find(req.first)->second;
                    
                    if (((int)oldModifier & (int)req.second) != (int)req.second) // should set new flag
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
        
        // TODO: dependency tree!!!
        if (processFinal5.empty())
            processFinal5 = std::move(processFinal6);
        if (processFinal4.empty())
            processFinal4 = std::move(processFinal5);
        if (processFinal3.empty())
            processFinal3 = std::move(processFinal4);
        if (processFinal2.empty())
            processFinal2 = std::move(processFinal3);
        if (processFinal.empty())
            processFinal = std::move(processFinal2);
        if (processNew.empty())
            processNew = std::move(processFinal);
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
    printf("        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs < map[i+3]*16 + map[i+4])\n");
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

