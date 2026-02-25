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
#include <iostream>
#include <string>
#include <ranges>
#include <string_view>

#include "address.h"
#include "common.h"
#include "loader/loader.h"
#include "tracer.h"
#include "ir/operand.h"
#include "ir/statement.h"
#include "ir/builder.h"

#include "analyser/analyser.h"
#include "analyser/analyserFunction.h"
#include "analyser/analyserInstruction.h"

#include "ir/printBase.h"
#include "ir/printCpp.h"
#include "ir/printJs.h"
#include "ir/printJsSync.h"

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

void ApplyLoaderShift(const std::shared_ptr<Options> &options)
{
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
}

void PrepareJumpTables(const shared<Loader> &loader, const std::shared_ptr<Options> &options)
{
    for (auto t : options->jumpTables)
    {
        if (t->baseptr)
            continue;
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
}

std::vector<address_t> BuildEntriesList(const shared<Loader> &loader, const std::shared_ptr<Options> &options) {
    std::vector<address_t> startEntries;
    
    if (options->start)
    {
        if (options->procModifiers.find(loader->GetEntry()) == options->procModifiers.end())
            options->procModifiers.insert({loader->GetEntry(), procRequest_t{(int)procRequest_t::entry | (int) procRequest_t::callNear}});
        startEntries.push_back(loader->GetEntry());
    }
    for (address_t p : options->procList)
        startEntries.push_back(p);
    for (address_t p : options->isolateLabels)
    {
        if (options->procModifiers.find(p) == options->procModifiers.end())
            options->procModifiers.insert({p, procRequest_t::callIsolated});
        startEntries.push_back(p);
    }
    for (shared<jumpTable_t> j : options->jumpTables)
        if (j->type == jumpTable_t::Call || j->type == jumpTable_t::CallWords || j->type == jumpTable_t::CallDwords)
            for (int i=0; i<j->GetSize(); i++)
                if (j->IsValid(i))
                    startEntries.push_back(j->GetTarget(i));
    
    for (indirectJump_t j : options->indirectCalls)
        startEntries.push_back(j.target);
    
    for (indirectJump_t j : options->indirectJumps)
    {
        if (options->procModifiers.find(j.target) == options->procModifiers.end())
            options->procModifiers.insert({j.target, procRequest_t::callIsolated});
        startEntries.push_back(j.target);
    }
    
    for (address_t p : startEntries)
    {
        if (options->procModifiers.find(p) == options->procModifiers.end())
            options->procModifiers.insert({p, options->arch == arch_t::arch16 ? procRequest_t::callNear : procRequest_t::callLong});
    }
    return startEntries;
}

void FilterIncrementalEntries(std::set<address_t>& newSet, std::set<address_t>& oldSet)
{
    std::set<address_t> aux;
    for (const address_t& addr : newSet)
    {
        if (oldSet.find(addr) == oldSet.end())
        {
            oldSet.insert(addr);
            aux.insert(addr);
        }
    }
    newSet = aux;
}

void FilterIncrementalEntries(std::vector<address_t>& newSet, std::set<address_t>& oldSet)
{
    std::vector<address_t> aux;
    for (const address_t& addr : newSet)
    {
        if (oldSet.find(addr) == oldSet.end())
        {
            oldSet.insert(addr);
            aux.push_back(addr);
        }
    }
    newSet = aux;
}
/*
void PostProcess(shared<ProcIr> prog, Analyser& analyser)
{
    shared<Analyser::info_t> info = analyser.mInfos.find(prog->addr)->second;
    
    auto ProcessOp = [&](address_t addr, shared<OperandIr> op) {
        if (!op)
            return;
        if (op->type != OperandIr::Type_t::Memory)
            return;
        if (op->memOfsDisp == 0x7fffffff)
        {
            //                    if (op->memOfsDisp == 0x7fffffff  && info->instr->mSize == 6)
            //                        memOffset += format("memoryGet32(cs, 0x%x)", active.linearOffset()+2);
            //                    else

            shared<instrInfo_t> inst = info->code.find(addr)->second;
            if (inst->instr->mSize == 6 && inst->instr->mBytes[5] == 0x7f && inst->instr->mBytes[4] == 0xff && inst->instr->mBytes[3] == 0xff && inst->instr->mBytes[2] == 0xff)
            {
                op->memOfsDisp = 0;
                op->memDynamicSize = 4;
                op->memDynamicSegment = "cs";
                op->memDynamicOffset = 0xabababab;
            }
            //info->code
            
        }
    };
    
    std::function<void (address_t, StatementIr&)> ProcessStmt = [&](address_t addr, StatementIr& stmt) -> void {
        ProcessOp(addr, stmt.opd);
        ProcessOp(addr, stmt.opin1);
        ProcessOp(addr, stmt.opin2);
        if (stmt.stmt1)
            ProcessStmt(addr, *stmt.stmt1);
        if (stmt.stmt2)
            ProcessStmt(addr, *stmt.stmt2);
    };
    
    for (StatementIr& stmt : prog->lines)
        ProcessStmt(stmt.address, stmt);
}
*/
bool DoIteration(shared<Loader> &loader, const std::shared_ptr<Options> &options, Analyser& analyser) {
    if (!loader)
    {
        if (!options->loader[0] || !options->exec[0])
            return true;
        
        // Only once
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
        
        ApplyLoaderShift(options);
        
        if (!loader->LoadFile(options->exec, options->loadAddress))
        {
            printf("Cannot open file %s\n", options->exec);
            return false;
        }
        if (options->overlayBase)
            loader->Overlay(options->overlayBase, options->overlayBytes);
        
        options->imports = loader->GetImports();
        Capstone->Set(loader, options);
    }
    
    PrepareJumpTables(loader, options);
    
    std::vector<address_t> startEntries = BuildEntriesList(loader, options);
    FilterIncrementalEntries(startEntries, options->incrementalAnalyse);
    
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
    FilterIncrementalEntries(processNew, options->incrementalProcess);
    std::set<address_t> processed;

    std::string all = "";
    for (address_t adr : processNew)
        all += format(" sub_%x", adr.linearOffset());
    
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
    PrintIrBase* print = nullptr;
    if (options->frontend == "base")
        print = new PrintIrBase(options);
    else if (options->frontend == "c++")
        print = new PrintIrCppHints(options);
    else if (options->frontend == "javascript")
        print = new PrintIrJs(options);
    else if (options->frontend == "javascriptSync")
        print = new PrintIrJsSync(options);
    else
        assert(0);
    
    bool firstRun = options->incrementalPrint.empty();
    if (firstRun)
    {
//        std::string initCode = loader->GetInit();
//        if (!initCode.empty())
//            printf("%s", initCode.c_str());
//        else
            print->PrintHeading(loader);
        
        print->PrintDeclarations(analyser.AllMethods());
        print->PrintGlobalIndirectTable(BuildGlobalIndirectTable(options));
    }
#endif
    
    std::set<address_t> allMethods = analyser.AllMethods();
    FilterIncrementalEntries(allMethods, options->incrementalPrint);

    for (address_t proc : allMethods)
    {
#ifdef OLDCONVERTER
        Convert convert(analyser, *options);
        convert.SetOffsetMask(options->arch == arch_t::arch16 ? 0xffff : -1); // 16 bit
        convert.ConvertProc(proc);
        convert.Dump();
#else
        auto ir = conv.Convert(proc);
//        PostProcess(ir, analyser);
        shared<Analyser::info_t> info = analyser.mInfos.find(proc)->second;

        print->PrintProgram(ir, info);
#endif
    }
    
#ifndef OLDCONVERTER
    if (firstRun)
        print->PrintRelocations(loader->GetRelocations());
#endif
    if (allMethods.size())
        printf("\n\n");
    return true;
}

int main(int argc, char **argv) {
    shared<Options> options = std::make_shared<Options>();
    shared<Loader> loader;
    Analyser analyser(options);

    if (argc == 2)
    {
        // non-interactive mode
        std::vector<uint8_t> optFile = Loader::GetFileContents(argv[1]);
        assert(!optFile.empty());
        // Parse configuration from JSON file
        if (1)
        {
            if (!ConfigParser::ParseConfiguration(optFile, options))
            {
                printf("Failed to parse configuration file\n");
                return 1;
            }
            if (!DoIteration(loader, options, analyser))
                return 1;
            return 0;
        } else {
            std::string text(reinterpret_cast<const char*>(optFile.data()),
                             optFile.size());
            
            for (auto line : text | std::views::split('\n')) {
                std::string_view sv(line.begin(), line.end());
                
                if (!sv.empty() && sv.back() == '\r')
                    sv.remove_suffix(1);
                
                if (sv.empty() || sv.starts_with("//"))
                    continue;
                
                ConfigParser::ParseConfigLine(std::string(sv), options);
                assert(DoIteration(loader, options, analyser));
            }
        }
        return 0;
    }

    std::string line;
    while (std::getline(std::cin, line))
    {
        ConfigParser::ParseConfigLine(line, options);
        if (!DoIteration(loader, options, analyser))
            return 1;
    }

    return 0;
}
