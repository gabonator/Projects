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
//    Options options = Profiles::optionsCC1;
//    Options options = Profiles::optionsCK1;
    Options options = Profiles::optionsCK4;
//    options.verbose = true;
    options.printProcAddress = true;
    options.printLabelAddress = true;
//    options.verboseAsm = true;
    
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

    printf(R"(
    void callIndirect(int s, int o)
    {
        stop("ind");
    }

    void indirectJump(int s, int o)
    {
        stop("ind");
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
            int modifierStack = 0;
            if (options.procModifiersStack.find(proc) != options.procModifiersStack.end())
                modifierStack = options.procModifiersStack.find(proc)->second;

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

    printf("/*\n");
    options.verboseAsm = false;
    for (address_t proc : analyser.AllMethods())
    {
        if (proc.offset == 0x0c6b)
        {
            int f = 9;
        }
        Convert convert(analyser, options);
        convert.SetOffsetMask(options.arch == arch_t::arch16 ? 0xffff : -1); // 16 bit
        convert.ConvertProc(proc);

//        for (std::string line : convert.GetCode())
//            if (line.find("near_proc_retf") != std::string::npos)
//                printf("{{0x%04x, 0x%04x}, procRequest_t::popsCs},\n", proc.segment, proc.offset);
        
        shared<Analyser::info_t> info = analyser.mInfos.find(proc)->second;
        std::set<int> retArgs;
        bool retCs = false;
        bool instrRet = false, instrRetf = false;
        for (const auto& [addr, instr] : info->code)
        {
            instrRet |= instr->instr->mId == X86_INS_RET;
            instrRetf |= instr->instr->mId == X86_INS_RETF;
            if (instr->instr->mId == X86_INS_RET || instr->instr->mId == X86_INS_RETF)
            {
                retArgs.insert(instr->instr->Imm());
                if (instr->instr->mPrev.size()==1)
                {
                    shared<instrInfo_t> prev = info->code.find(*instr->instr->mPrev.begin())->second;
                    if (prev->instr->mId == X86_INS_POP && strcmp(prev->instr->mOperands, "cs")==0)
                        retCs = true;
//                    if (prev->instr->mId == X86_INS_ADD && strstr(prev->instr->mOperands, "sp, "))
//                        retArgs.insert(prev->instr->Imm());
                }
            }
            //shared<instrInfo_t>
        }
        if (retArgs.size()>1)
        {
            if (retArgs.size() == 2 && *retArgs.begin() == 0)
                retArgs.erase(0);
            else
                printf("// Mixed ret in %04x:%04x sub_%x()\n", proc.segment, proc.offset, proc.linearOffset());
        }
        if (retArgs.size()==1 && (*retArgs.begin() != 0 || instrRetf))
        {
//                    assert(retArgs.size() == 1);  xv xvxvx
//                    if (retCs)
//                        printf("{{0x%04x, 0x%04x}, procRequest_t((int)procRequest_t::stackDrop%d | (int)procRequest_t::popsCs)}, // %s\n", proc.segment, proc.offset, *retArgs.begin() + retCs*2, instr->instr->mMnemonic);
//                    else
            printf("{{0x%04x, 0x%04x}, %d}, // sub_%x%s%s%s\n", proc.segment, proc.offset, *retArgs.begin() + retCs*2 + instrRetf*2, proc.linearOffset(), instrRet ? " ret" : "", instrRetf ? " retf" : "", retCs ? " popcs" : "");
        }
        /*
         shared <Analyser::info_t> mInfo;
     //    shared<CTracer> mTracer;
         std::vector<std::string> mCode;
         
     public:
         Convert(const Analyser& anal, const Options& options) : mAnal(anal), mOptions(options)
         {
         }

         void ConvertProc(address_t proc)
         {
             const bool verbose{mOptions.verbose};
             mInfo = mAnal.mInfos.find(proc)->second;

         */
    }
    printf("*/\n");

    return 0;
}
