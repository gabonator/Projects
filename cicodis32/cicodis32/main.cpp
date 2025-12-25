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
#include "loader/loader.h"
#include "tracer.h"
#include "ir/operand.h"
#include "ir/statement.h"
#include "ir/builder.h"
#include "ir/printBase.h"
#include "ir/printCpp.h"
#include "ir/printJs.h"

#include "analyser/analyser.h"
#include "analyser/analyserFunction.h"
#include "analyser/analyserInstruction.h"
#include "old/formatter.h"
#include "old/converter.h"
#include "json.h"
#include "configParser.h"
#include "exportcglue.h"

#include "ir/convtable.h"
#include "ir/convert.h"

//#define OLDCONVERTER

void MapHints(std::shared_ptr<Options> options, Analyser& analyser)
{
    for (hint_t& hint : options->memHints)
    {
        if (hint.label.find("-") != std::string::npos)
        {
            std::vector<std::string> parts = split(hint.label, "-");
            assert(parts.size() == 2);
            hint.begin = address_t::fromString(parts[0]);
            hint.end = address_t::fromString(parts[1]);
        } else if (hint.label.starts_with("sub_"))
        {
            int addrPart = std::stoi(hint.label.substr(4).c_str(), nullptr, 16);
            bool done = false;
            for (const auto& [addr, info] : analyser.mInfos)
            {
                if (addr.linearOffset() == addrPart)
                {
                    assert(info->code.size());
                    hint.begin = info->code.begin()->first;
                    hint.end = info->code.rbegin()->first;
                    done = true;
                    break;
                }
            }
            assert(done);
        } else if (hint.label.starts_with("loc_"))
        {
            int addrPart = std::stoi(hint.label.substr(4).c_str(), nullptr, 16);
            bool done = false;

            for (const auto& [addr, info] : analyser.mInfos)
            {
                if (addr.linearOffset() == addrPart)
                {
                    hint.begin = info->code.begin()->first;
                }

                for (const auto& [caddr, instr] : info->code)
                {
                    if (!hint.begin)
                    {
                        if (instr->instr->isLabel && caddr.linearOffset() == addrPart)
                        {
                            hint.begin = caddr;
                        }
                    } else {
                        hint.end = caddr;
                        done = true;
                        if (instr->instr->isLabel)
                            break;
                    }
                }
                if (done)
                    break;
            }
            assert(done);
        } else
            assert(0);
    }
}

int main(int argc, char **argv) {
    std::shared_ptr<Options> options = std::make_shared<Options>();
    options->printProcAddress = true;
    options->printLabelAddress = true;
//    options->verboseAsm = true;

    assert(argc==2);
    std::vector<uint8_t> optFile = Loader::GetFileContents(argv[1]);
    assert(!optFile.empty());
    
    // Parse configuration from JSON file
    if (!ConfigParser::ParseConfiguration(optFile, options))
    {
        printf("Failed to parse configuration file\n");
        return 1;
    }
    
    //sub_3c4b

    shared<Loader> loader;
    if (strcmp(options->loader, "LoaderMz") == 0)
        loader.reset(new LoaderMz);
    else if (strcmp(options->loader, "LoaderSnapshot") == 0)
        loader.reset(new LoaderSnapshot);
    else if (strcmp(options->loader, "LoaderLe") == 0)
        loader.reset(new LoaderLe);
    else if (strcmp(options->loader, "LoaderPe") == 0)
        loader.reset(new LoaderPe);
    else
        assert(0);
        
    if (options->loadAddressShift != 0)
    {
        options->loadAddress += options->loadAddressShift;
        
        std::map<address_t, std::string> injectShift;
        for (auto [addr, inject] : options->inject)
            injectShift.insert({address_t{addr.segment, addr.offset + options->loadAddressShift}, inject});
        options->inject = injectShift;
        
        std::set<address_t> marksShift;
        for (auto addr : options->marks)
            marksShift.insert({addr.segment, addr.offset + options->loadAddressShift});
        options->marks = marksShift;

        assert(options->procList.size() == 0);
        assert(options->isolateLabels.size() == 0);
        assert(options->terminators.size() == 0);
        assert(options->procModifiers.size() == 0);
        assert(options->procModifiersStack.size() == 0);
        for (auto jt : options->jumpTables)
        {
            if (jt->table.isValid())
                jt->table.offset += options->loadAddressShift;
            if (jt->instruction.isValid())
                jt->instruction.offset += options->loadAddressShift;
            if (jt->baseptr)
            {
                assert(jt->type == jumpTable_t::switch_e::Call32 || jt->type == jumpTable_t::switch_e::Jump32);
                uint32_t* ptr = (uint32_t*)jt->baseptr;
                for (int e : jt->elements)
                    ptr[e] += options->loadAddressShift;
            }
        }
        assert(options->indirectCalls.size() == 0);
        assert(options->indirectJumps.size() == 0);
    }

    if (!loader->LoadFile(options->exec, options->loadAddress))
    {
        printf("Cannot open file %s\n", options->exec);
        return 1;
    }
    if (options->overlayBase)
        loader->Overlay(options->overlayBase, options->overlayBytes);
    
    options->imports = loader->GetImports();
    Capstone->Set(loader, options);
    
    for (auto t : options->jumpTables)
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
    }

    std::vector<address_t> startEntries;
    
    if (options->start)
    {
        options->procModifiers.insert({loader->GetEntry(), procRequest_t{(int)procRequest_t::entry | (int) procRequest_t::callNear}});
        startEntries.push_back(loader->GetEntry());
    }
    for (address_t p : options->procList)
        startEntries.push_back(p);
    for (address_t p : options->isolateLabels)
    {
        options->procModifiers.insert({p, procRequest_t::callIsolated});
        startEntries.push_back(p);
    }
    for (shared<jumpTable_t> j : options->jumpTables)
        if (j->type == jumpTable_t::Call || j->type == jumpTable_t::CallWords || j->type == jumpTable_t::CallDwords)
        for (int i=0; i<j->GetSize(); i++)
            if (j->IsValid(i))
                startEntries.push_back(j->GetTarget(i));

    for (indirectJump_t j : options->indirectCalls)
    {
        startEntries.push_back(j.target);
    }

    for (indirectJump_t j : options->indirectJumps)
    {
        options->procModifiers.insert({j.target, procRequest_t::callIsolated});
        startEntries.push_back(j.target);
    }

    for (address_t p : startEntries)
    {
        if (options->procModifiers.find(p) == options->procModifiers.end())
            options->procModifiers.insert({p, options->arch == arch_t::arch16 ? procRequest_t::callNear : procRequest_t::callLong});
    }
    
    Analyser analyser(options);
    if (options->recursive)
    {
        analyser.RecursiveScan(startEntries);
    } else {
        for (address_t p : options->procList)
            analyser.Scan(p);
    }
        
    std::map<address_t, address_t> dependency;
    for (const indirectJump_t& j : options->indirectJumps)
        dependency.insert({j.target, j.parent});

    std::set<address_t> processNew;
    processNew = analyser.AllMethods();
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
        
        processNew = keep;
        
        for (address_t proc : process)
        {
            procRequest_t modifier = procRequest_t::none;
            if (options->procModifiers.find(proc) != options->procModifiers.end())
                modifier = options->procModifiers.find(proc)->second;
            int modifierStack = analyser.GuessStackBalanceForProcCached(proc);

            if ((int)modifier & (int)procRequest_t::callIsolated)
            {
                // find parent, reuse attributes
                for (indirectJump_t j : options->indirectJumps)
                    if (j.target == proc)
                    {
                        address_t parent = j.parent;
                        if (options->procModifiers.find(parent) != options->procModifiers.end())
                            modifier = procRequest_t{(int)modifier | (int)options->procModifiers.find(parent)->second};
                        modifierStack = analyser.GuessStackBalanceForProcCached(parent);
                        break;
                    }
            }

            analyser.AnalyseProc(proc, modifier, modifierStack);
            processed.insert(proc);
            
            if (options->recursive)
            {
                for (std::pair<address_t, procRequest_t> req : analyser.GetRequests(proc))
                {
                    procRequest_t oldModifier = procRequest_t::none;
                    if (options->procModifiers.find(req.first) != options->procModifiers.end())
                        oldModifier = options->procModifiers.find(req.first)->second;
                    
                    if (((int)oldModifier & (int)req.second) != (int)req.second) // should set new flag
                    {
                        req.second = (procRequest_t)((int)req.second | (int)oldModifier);
                        if (options->procModifiers.find(req.first) != options->procModifiers.end())
                            options->procModifiers.find(req.first)->second = req.second;
                        else
                            options->procModifiers.insert(req);
                        processNew.insert(req.first);
                        processed.erase(req.first);
                    }
                }
            }
        }
    }
    
    // map hints
    MapHints(options, analyser);

#ifndef OLDCONVERTER
    ConvertIr conv(analyser, options);
//    PrintIrCpp print(options);
//    PrintIrCppHints print(options);
    PrintIrJs print(options);
    
    print.PrintHeading(loader);
    print.PrintDeclarations(analyser.AllMethods());
    print.PrintGlobalIndirectTable(BuildGlobalIndirectTable(options));
#endif
    
    for (address_t proc : analyser.AllMethods())
    {
#ifdef OLDCONVERTER
        Convert convert(analyser, *options);
        convert.SetOffsetMask(options->arch == arch_t::arch16 ? 0xffff : -1); // 16 bit
        convert.ConvertProc(proc);
        convert.Dump();
#else
        auto ir = conv.Convert(proc);
        print.PrintProgram(ir);
#endif
    }
    
#ifndef OLDCONVERTER
    print.PrintRelocations(loader->GetRelocations());
#endif
    return 0;
}

