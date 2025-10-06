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

    assert(argc==2);
    std::vector<uint8_t> optFile = Loader::GetFileContents(argv[1]);
    assert(!optFile.empty());
    
    const char* strJson = (const char*)&optFile[0];

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
                else if (k == "start" && v == "false")
                    options.start = false;
                else if (k == "verbose" && v == "true")
                    options.verbose = true;
                else if (k == "verboseAsm" && v == "true")
                    options.verboseAsm = true;
                else if (k == "verboseAsm" && v == "false")
                    options.verboseAsm = false;
                else if (k == "recursive" && v == "false")
                    options.recursive = false;
                else if (k == "relocations" && v == "false")
                    options.relocations = false;
                else if (k == "declarations" && v == "false")
                    options.declarations = false;
                else if (k == "stackShiftAlways" && v == "true")
                    options.stackShiftAlways = true;
                else if (k == "procList")
                {
                    CJson(v).ForEach([&](const CSubstring& v)
                    {
                        std::string strAddr = CJson(v).GetString();
                        if (strAddr.find("+") != std::string::npos)
                        {
                            int plus = (int)strAddr.find("+");
                            std::string modifier = strAddr.substr(plus);
                            strAddr = strAddr.substr(0, plus);
                            procRequest_t req = procRequest_t::none;
                            if (modifier == "+returnZero")
                                req = procRequest_t((int)procRequest_t::returnZero | (int)procRequest_t::callNear);
                            else if (modifier == "+returnCarry+returnZero")
                                req = procRequest_t((int)procRequest_t::returnZero | (int)procRequest_t::returnCarry | (int)procRequest_t::callNear);
                            else
                                assert(0);
                            options.procModifiers.insert({address_t::fromString(strAddr), req});
                        }
                        options.procList.push_back(address_t::fromString(strAddr));
                    });
                }
                else if (k == "isolate")
                {
                    CJson(v).ForEach([&](const CSubstring& v)
                    {
                        options.isolateLabels.insert(address_t::fromString(CJson(v).GetString()));
                    });
                }
                else if (k == "terminator")
                {
                    CJson(v).ForEach([&](const CSubstring& v)
                    {
                        options.terminators.insert(address_t::fromString(CJson(v).GetString()));
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
            address_t target = address_t::fromString(json["target"].GetString());
            //address_t parent = address_t::fromString(json["parent"].GetString());
            address_t origin = address_t::fromString(json["origin"].GetString());
            options.indirectCalls.push_back({.target = target, /*.parent = parent,*/ .origin = origin});
        } else
        if (json["id"] == "indirectJump")
        {
            address_t target = address_t::fromString(json["target"].GetString());
            address_t parent = address_t::fromString(json["parent"].GetString());
            address_t origin = address_t::fromString(json["origin"].GetString());
            options.indirectJumps.push_back({.target = target, .parent = parent, .origin = origin});
        } else
        if (json["id"] == "jumpTable" && json["callsFar"])
        {
            std::vector<uint16_t> targets;
            std::vector<int> elements;

            address_t instruction = address_t::fromString(json["addr"].GetString());
            CJson(json["callsFar"]).ForEach([&](const CSubstring& v)
            {
                address_t target = address_t::fromString(CJson(v).GetString());
                targets.push_back(target.offset);
                targets.push_back(target.segment);
                elements.push_back((int)elements.size());
            });
            uint16_t* ptargets = new uint16_t[targets.size()];
            memcpy(ptargets, &targets[0], sizeof(uint16_t) * targets.size());
            
            std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
                .type = jumpTable_t::switch_e::CallDwords, .useCaseOffset = true, .elements = elements});
            
            options.jumpTables.push_back(jt);
        } else
        if (json["id"] == "jumpTable" && json["callsNear"])
        {
            std::vector<uint16_t> targets;
            std::vector<int> elements;

            address_t instruction = address_t::fromString(json["addr"].GetString());
            CJson(json["callsNear"]).ForEach([&](const CSubstring& v)
            {
                address_t target = address_t::fromString(CJson(v).GetString());
                assert(target.segment == instruction.segment);
                targets.push_back(target.offset);
                elements.push_back((int)elements.size());
            });
            uint16_t* ptargets = new uint16_t[targets.size()];
            memcpy(ptargets, &targets[0], sizeof(uint16_t) * targets.size());
            
            std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
                .type = jumpTable_t::switch_e::CallWords, .useCaseOffset = true, .elements = elements});
            
            options.jumpTables.push_back(jt);
        } else
        if (json["id"] == "jumpTable" && json["calls32"])
        {
            std::vector<uint32_t> targets;
            std::vector<int> elements;

            address_t instruction = address_t::fromString(json["addr"].GetString());
            CJson(json["calls32"]).ForEach([&](const CSubstring& v)
            {
                address_t target = address_t::fromString(CJson(v).GetString());
                assert(target.segment == instruction.segment);
                targets.push_back(target.offset);
                elements.push_back((int)elements.size());
            });
            uint32_t* ptargets = new uint32_t[targets.size()];
            memcpy(ptargets, &targets[0], sizeof(uint32_t) * targets.size());
            
            std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
                .type = jumpTable_t::switch_e::Call32, .useCaseOffset = true, .elements = elements});
            
            options.jumpTables.push_back(jt);
        } else
        if (json["id"] == "jumpTable" && json["jumps"])
        {
            std::vector<uint16_t> targets;
            std::vector<int> elements;

            address_t instruction = address_t::fromString(json["addr"].GetString());
            CJson(json["jumps"]).ForEach([&](const CSubstring& v)
            {
                address_t target = address_t::fromString(CJson(v).GetString());
                assert(target.segment == instruction.segment);
                targets.push_back(target.offset);
                elements.push_back((int)elements.size());
            });
            uint16_t* ptargets = new uint16_t[targets.size()];
            memcpy(ptargets, &targets[0], sizeof(uint16_t) * targets.size());
            
            std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
                .type = jumpTable_t::switch_e::JumpWords, .useCaseOffset = true, .elements = elements});
            
            options.jumpTables.push_back(jt);
        } else
        if (json["id"] == "jumpTable" && json["jumps32"])
        {
            std::vector<uint32_t> targets;
            std::vector<int> elements;

            address_t instruction = address_t::fromString(json["addr"].GetString());
            CJson(json["jumps32"]).ForEach([&](const CSubstring& v)
            {
                address_t target = address_t::fromString(CJson(v).GetString());
                assert(target.segment == instruction.segment);
                targets.push_back(target.offset);
                elements.push_back((int)elements.size());
            });
            uint32_t* ptargets = new uint32_t[targets.size()];
            memcpy(ptargets, &targets[0], sizeof(uint32_t) * targets.size());
            
            std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = instruction, .baseptr = (uint8_t*)ptargets, .release = true,
                .type = jumpTable_t::switch_e::Jump32, .useCaseOffset = true, .elements = elements});
            
            options.jumpTables.push_back(jt);
        } else
        if (json["id"] == "jumpTable")
        {
            address_t instruction = address_t::fromString(json["addr"].GetString());
//            if (json["addr"])
//                instruction = address_t::fromString(json["addr"].GetString());
            address_t table = address_t::fromString(json["table"].GetString());
            
            //int entries = json["entries"].GetNumber();
            std::string strType = json["type"].GetString();
            std::string selector = json["selector"].GetString();
            int minaddr = json["filterMin"] ? json["filterMin"].GetNumber() : 0;
            
            bool useCaseOffset = json["useCaseOffset"] ? json["useCaseOffset"].GetBoolean() : false;

            std::vector<int> elements;

            if (json["entries"].IsArray())
            {
                CJson(json["entries"]).ForEach([&](const CSubstring& v)
                {
                    elements.push_back(CJson(v).GetNumber());
                });
            } else {
                int entries = json["entries"].GetNumber();
                for (int i=0; i<entries; i++)
                    elements.push_back(i);
            }
            
            jumpTable_t::switch_e type = jumpTable_t::switch_e::None;
            if (strType == "jumpwords")
                type = jumpTable_t::switch_e::JumpWords;
            else if (strType == "callwords")
                type = jumpTable_t::switch_e::CallWords;
            else if (strType == "calldwords")
                type = jumpTable_t::switch_e::CallDwords;
            else if (strType == "jumpfix")
                type = jumpTable_t::switch_e::JumpFix;
            else if (strType == "jump32")
                type = jumpTable_t::switch_e::Jump32;
            else if (strType == "call32")
                type = jumpTable_t::switch_e::Call32;
            else
                assert(0);
            

            std::shared_ptr<jumpTable_t> jt = std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = instruction, .table = table, .type = type, .elements = elements, .selector = selector,
                .minaddr = minaddr, .useCaseOffset = useCaseOffset});
            
            options.jumpTables.push_back(jt);
        } else
        if (json["id"] == "inject")
        {
            options.inject.insert({address_t::fromString(json["addr"].GetString()), json["text"].GetString()});
        } else
        if (json["id"] == "marks")
        {
            CJson(json["marks"]).ForEach([&](const CSubstring& v)
            {
                options.marks.insert(address_t::fromString(CJson(v).GetString()));
            });
        } else
        if (json["id"] == "overlay")
        {
            options.overlayBase = address_t::fromString(json["addr"].GetString());
            CJson(json["bytes"]).ForEach([&](const CSubstring& v)
            {
                int b = CJson(v).GetNumber();
                options.overlayBytes.push_back(b);
            });
        }
        else {
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
    if (options.overlayBase)
        loader->Overlay(options.overlayBase, options.overlayBytes);
    Capstone->Set(loader, options);

    
    bool anyIndirectTable = false;
    for (auto t : options.jumpTables)
    {
        if (t->fileoffset)
            t->baseptr = loader->GetBufferAt(t->fileoffset);
        if (t->filecount)
        {
            for (int i=0; i<t->filecount; i++)
                t->elements.push_back(i);
        }

        if (!t->baseptr)
            t->baseptr = loader->GetBufferAt(t->table);
        if (t->selector == "indirect")
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
        if (j->type == jumpTable_t::Call || j->type == jumpTable_t::CallWords || j->type == jumpTable_t::CallDwords)
        for (int i=0; i<j->GetSize(); i++)
            if (j->IsValid(i))
                startEntries.push_back(j->GetTarget(i));

    for (indirectJump_t j : options.indirectCalls)
    {
        startEntries.push_back(j.target);
    }

    for (indirectJump_t j : options.indirectJumps)
    {
        options.procModifiers.insert({j.target, procRequest_t::callIsolated});
        startEntries.push_back(j.target);
    }

    for (address_t p : startEntries)
    {
        if (options.procModifiers.find(p) == options.procModifiers.end())
            options.procModifiers.insert({p, options.arch == arch_t::arch16 ? procRequest_t::callNear : procRequest_t::callLong});
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

    auto IndirectOrigins = [](std::vector<indirectJump_t> tab)
    {
        std::set<address_t> org;
        for (const indirectJump_t& j : tab)
            org.insert(j.origin);
        return org;
    };
    
    if (options.jit)
    {
        printf(R"(#include <stdio.h>

void indirectCall(int s, int o, int orgs, int orgo)
{
    switch (orgs*0x10000+orgo)
    {
)");
        for (address_t org : IndirectOrigins(options.indirectCalls))
        {
            printf(R"(        case 0x%x: 
            switch (s*0x10000+o)
            {
)", org.segment*0x10000 + org.offset);
            
            for (const indirectJump_t& j : options.indirectCalls)
            {
                if (j.origin == org)
                    printf("                case 0x%x: sub_%x(); return;\n", j.target.segment*0x10000 + j.target.offset, j.target.linearOffset());
            }
            printf(R"(            }
            break;
)");
        }
        printf(R"(    }
    printf("\nMISSING INDIRECT CALL %%04x:%%04x @ %%04x:%%04x\n", s, o, orgs, orgo);
    exit(3);
}

void indirectJump(int s, int o, int orgs, int orgo, int pars, int paro)
{
    switch (orgs*0x10000+orgo)
    {
)");
        for (address_t org : IndirectOrigins(options.indirectJumps))
        {
            printf(R"(        case 0x%x: 
            switch (s*0x10000+o)
            {
)", org.segment*0x10000 + org.offset);
            
            for (const indirectJump_t& j : options.indirectJumps)
            {
                if (j.origin == org)
                    printf("                case 0x%x: sub_%x(); return;\n", j.target.segment*0x10000 + j.target.offset, j.target.linearOffset());
            }
            printf(R"(            }
            break;
)");
        }
        printf(R"(    }
    printf("\nMISSING INDIRECT JUMP %%04x:%%04x @ %%04x:%%04x/%%04x:%%04x\n", s, o, orgs, orgo, pars, paro);
    exit(3);
}

)");
    }
    
    if (anyIndirectTable)
    {
        printf("void indirectCall(int seg, int ofs)\n{\n");
        for (auto table : options.jumpTables)
            if (table->selector == "indirect")
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
        printf("    stop(\"ind\");\n");
        printf("}\n\n");
    }
    
    std::map<address_t, address_t> dependency;
    for (const indirectJump_t& j : options.indirectJumps)
        dependency.insert({j.target, j.parent});

    std::set<address_t> processNew;
    processNew = analyser.AllMethods();
    // TODO: call conv!
    std::set<address_t> processed;
    
    while (!processNew.empty())
    {
        std::set<address_t> keep;
        std::set<address_t> process;
        
        for (address_t p : processNew)
        {
            bool depends = false;

            auto pDeps = dependency.find(p);
            if (pDeps != dependency.end())
                depends = processed.find(pDeps->second) == processed.end();
                
            if (depends)
                keep.insert(p);
            else
                process.insert(p);
        }
        
        //std::set<address_t> process = processNew;
        //processNew.clear();
        processNew = keep;
        
        for (address_t proc : process)
        {
            procRequest_t modifier = procRequest_t::none;
            if (options.procModifiers.find(proc) != options.procModifiers.end())
                modifier = options.procModifiers.find(proc)->second;
            int modifierStack = analyser.GuessStackBalanceForProcCached(proc);

            if (/*processFinal.empty() &&*/ (int)modifier & (int)procRequest_t::callIsolated)
            {
                // find parent, reuse attributes
                for (indirectJump_t j : options.indirectJumps)
                    if (j.target == proc)
                    {
//                        auto pParent = analyser.mIndirectToParent.find(j.origin);
//                        assert(pParent != analyser.mIndirectToParent.end());
//                        address_t parent = pParent->second;
                        address_t parent = j.parent;
                        if (options.procModifiers.find(parent) != options.procModifiers.end())
                            modifier = procRequest_t{(int)modifier | (int)options.procModifiers.find(parent)->second};
                        modifierStack = analyser.GuessStackBalanceForProcCached(parent);
                        break;
                    }
            }

            analyser.AnalyseProc(proc, modifier, modifierStack);
            processed.insert(proc);
            
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
                        processed.erase(req.first);
                    }
                }
            }
        }
        
//        // TODO: dependency tree!!!
//        if (processFinal5.empty())
//            processFinal5 = std::move(processFinal6);
//        if (processFinal4.empty())
//            processFinal4 = std::move(processFinal5);
//        if (processFinal3.empty())
//            processFinal3 = std::move(processFinal4);
//        if (processFinal2.empty())
//            processFinal2 = std::move(processFinal3);
//        if (processFinal.empty())
//            processFinal = std::move(processFinal2);
//        if (processNew.empty())
//            processNew = std::move(processFinal);
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
    if (options.marks.size())
    {
        printf("    int marks[] = {\n");
        for (address_t mark : options.marks)
            printf("0x%04x, 0x%04x, ", mark.segment, mark.offset);
        printf("    };\n");
        printf("    for (int i=0; i<sizeof(marks)/sizeof(marks[0]); i+=2)\n");
        printf("        if (seg == marks[i] && ofs == marks[i+1])\n");
        printf("            return 0;\n");
        printf("\n");
    }
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
    printf("\n");
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

