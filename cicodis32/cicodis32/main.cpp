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

class OperandIr {
public:
    enum class Type_t {
        Const,
        Register,
        Memory,
        Label,
        String,
        Operator,
        Variable,
        Capstone
    } type;

    // const
    int constValue;
    
    // register
    std::string regName;
    
    // memory
    std::string memSegment;
    std::string memOffset;
    
    // label
    std::string label;
    
    // string
    std::string string;
    
    // operator
    std::string oper;
    
    // variable
    std::string variable;
    
    // capstone
    std::string capstone;
    
    explicit OperandIr(Type_t type, std::string s)
    {
        switch (type)
        {
            case Type_t::Register:
                regName = s;
                break;
            case Type_t::Operator:
                oper = s;
                break;
            case Type_t::Label:
                label = s;
                break;
            case Type_t::Capstone:
                capstone = s;
                break;
            default:
                assert(0);
        }
    }
    explicit OperandIr(Type_t type, int v)
    {
        switch (type)
        {
            case Type_t::Const:
                constValue = v;
                break;
            default:
                assert(0);
        }

    }
};

struct StatementIr {
public:
    enum class Type_t {
        Assignment, // op1 = op2
        Compare, // op1 > op2
        Binary, // op1 = op2 +- op3
        Function, // func(op1)?
        Condition, // if (StatementIr) StatementIr
        Stop, // stop(op1)
        Goto, // jump(op1)
        Call, // op1()
        Label, // op1:
        Switch, // switch(selector) { case const: long/far call/jump }
        Comment, // // comment
    } type;
    shared<OperandIr> op1;
    shared<OperandIr> op2;
    shared<OperandIr> opOperator;
    shared<OperandIr> op3;
    shared<OperandIr> opFunc;
    shared<StatementIr> stCondition;
    shared<StatementIr> stStatement;
    shared<OperandIr> opSwitchSelector;
    std::vector<std::pair<shared<OperandIr>, shared<StatementIr>>> opSwitchCases;
    std::string label;
    std::string comment;
};



#include "loader.h"
#include "tracer.h"
#include "analyser.h"
#include "analyserFunction.h"
#include "analyserInstruction.h"
#include "formatter.h"
#include "converter.h"
#include "json.h"
#include "configParser.h"
#include "exportcglue.h"


class ProcIr {
public:
    std::string name;
    std::string info;
    std::vector<std::string> temps;
    std::vector<StatementIr> lines;
};

class ConvertIr {
    shared<Options> mOptions;
    Analyser& mAnalyser;
    
public:
    ConvertIr(Analyser& analyser, shared<Options> options) : mOptions(options), mAnalyser(analyser)
    {
    }
    
    shared<ProcIr> Convert(address_t proc)
    {
        shared<ProcIr> procir = std::make_shared<ProcIr>();
        
        assert(mAnalyser.mInfos.find(proc) != mAnalyser.mInfos.end());
        shared<Analyser::info_t> info = mAnalyser.mInfos.find(proc)->second;
        
        std::string extraInfo = "";
        if ((info->func.request != procRequest_t::none && info->func.request != procRequest_t::callNear) || mOptions->printLabelAddress)
        {
            if (mOptions->printLabelAddress)
                extraInfo += utils::format("%04x:%04x", proc.segment, proc.offset);
            
            extraInfo += info->func.makeProcIdentifier();
        }
        procir->name = format("void sub_%x()", proc.linearOffset());
        procir->info = extraInfo;

        //
        shared <Analyser::info_t> mInfo = mAnalyser.mInfos.find(proc)->second;
        Analyser::code_t& code = mInfo->code;
        assert(!code.empty());

        for (std::string str : GetTempVariables(code, info))
            if (!str.starts_with("flags."))
                procir->temps.push_back(str);

        //
        if (!((int)info->func.request & (int)procRequest_t::callIsolated))
        {
            StatementIr shiftSp{.type = StatementIr::Type_t::Binary,
                    .op1 = std::make_shared<OperandIr>(OperandIr::Type_t::Register, "sp"),
                    .op2 = std::make_shared<OperandIr>(OperandIr::Type_t::Register, "sp"),
                    .opOperator = std::make_shared<OperandIr>(OperandIr::Type_t::Operator, "-"),
                    .op3 = std::make_shared<OperandIr>(OperandIr::Type_t::Const, 2)
            };
            StatementIr shiftEsp{.type = StatementIr::Type_t::Binary,
                    .op1 = std::make_shared<OperandIr>(OperandIr::Type_t::Register, "esp"),
                    .op2 = std::make_shared<OperandIr>(OperandIr::Type_t::Register, "esp"),
                    .opOperator = std::make_shared<OperandIr>(OperandIr::Type_t::Operator, "-"),
                    .op3 = std::make_shared<OperandIr>(OperandIr::Type_t::Const, 4)
            };

            if (info->func.callConv == callConv_t::callConvShiftStackNear)
                procir->lines.push_back(shiftSp);
            if (info->func.callConv == callConv_t::callConvShiftStackFar)
                procir->lines.push_back(shiftSp);
            if (info->func.callConv == callConv_t::callConvShiftStackNearFar)
                procir->lines.push_back(shiftSp);
            if (info->func.callConv == callConv_t::callConvShiftStackLong)
                procir->lines.push_back(shiftEsp);
        }
        
        if (code.begin()->first != proc)
        {
            procir->lines.push_back(StatementIr{.type = StatementIr::Type_t::Goto,
                .op1 = std::make_shared<OperandIr>(OperandIr::Type_t::Label, format("loc_%x", proc.linearOffset()))});
        }

        //
        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                procir->lines.push_back(StatementIr{.type = StatementIr::Type_t::Comment,
                    .comment = format("gap %d bytes\n", p.first.offset - next.offset)});
            }
            
            shared<CapInstr> pinstr = p.second->instr;
            auto codeit = info->code.find(p.first);
            assert(codeit != info->code.end());
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            if (pinstr->isLabel)
            {
                std::string label = format("loc_%x", pinstr->mAddress.linearOffset());

                if (mOptions->printProcAddress)
                    procir->lines.push_back(StatementIr{.type = StatementIr::Type_t::Label,
                        .label = format("loc_%x", pinstr->mAddress.linearOffset()),
                        .comment = pinstr->mAddress.toString()});
                else
                    procir->lines.push_back(StatementIr{.type = StatementIr::Type_t::Label,
                        .label = format("loc_%x", pinstr->mAddress.linearOffset())});
            }
                        
            /*
            std::vector<std::string> post;
            for (const instrInfo_t::instrInfoFlag_t* flag : pinfo->Flags())
            {
                static const char* flagName[128] = {['c'] = "flags.carry",
                    ['z'] = "flags.zero", ['s'] = "flags.sign", ['o'] = "flags.overflow"};
                
                if (flag->save)
                {
                    std::function<std::string(convert_args)> save;
                    switch (flag->type)
                    {
                        case 'c': save = convert[pinstr->mId].savecf; break;
                        case 'z': save = convert[pinstr->mId].savezf; break;
                        case 'o': save = convert[pinstr->mId].saveof; break;
                        case 's': save = convert[pinstr->mId].savesf; break;
                    }
                    
                    std::string fName(flagName[flag->type]);
                    
                    if (!flag->depends.empty())
                    {
                        std::string tempName = utils::format("temp_%cf", flag->type);
                        
                        procir->lines.push_back(StatementIr{
                            .type = StatementIr::Type_t::Assignment,
                            .op1 = std::make_shared<OperandIr>(OperandIr::Type_t::Variable, fName),
                            .op2 = std::make_shared<OperandIr>(OperandIr::Type_t::Variable, tempName)
                        });
                        
                        fName = tempName;
                    }
                    
                    assert(save);
                    std::string cmd = iformat(pinstr, pinfo, info->func, save(pinstr, pinfo, info->func));
                    mCode.push_back(std::string("    ") + fName + " = " + cmd + ";\n");
                    
                }
            }
            */
            
            if (pinfo->savePrecondition.size())
            {
                assert(0);
                /*
                 for (const auto& prec : pinfo->savePrecondition)
                 {
                     std::string cmd = iformat(pinstr, pinfo, info->func, preCondition(pinstr, prec.readOp));
                     PostProcessMemoryHint(pMemoryHints, cmd);
                     mCode.push_back("    " + prec.variable + " = " + cmd + ";\n");
                 }

                 */
            }
            
            if (!pinfo->stop.empty() && pinfo->instr->mTemplate.ret)
            {
                assert(0);
//                mCode.push_back("    stop(\""  + pinfo->stop + "\");\n");
            }
            
            if (pinfo->instr->mTemplate.ret)
            {
                assert(0);
                /*
                 for (const instrInfo_t::instrInfoFlag_t* flag : pinfo->Flags())
                 {
                     if (flag->needed)
                     {
                         std::string flagvalue = BuildConditionFor(pinfo->instr, pinfo, info->func, flag);
                         if (!flagvalue.empty())
                             mCode.push_back("    " + flagvalue + ";\n");
                     }
                 }

                 */
            }
            
            if (mOptions->GetJumpTables(pinstr->mAddress).size())
            {
                assert(0);
//                assert(pinstr->IsIndirectCall() || pinstr->IsIndirectJump());
//                DumpIndirectTables(pMemoryHints, pinfo, info->func);

            } else
            if (convert[pinstr->mId].convert)
            {
                auto stf = convert[pinstr->mId].convertir;
                StatementIr st = stf(pinstr, pinfo, info->func);
                procir->lines.push_back(st);
                
//                std::string command = iformat(pinstr, pinfo, info->func, convert[pinstr->mId].convert(pinstr, pinfo, info->func));
//                
//                if (command.size())
//                    mCode.push_back("    " + command + "\n");
//
            } else
            {
                assert(0);
//                    mCode.push_back(utils::format("    stop(\"disassembly failed at %x:%x %s\");\n",
//                                                  pinstr->mAddress.segment, pinstr->mAddress.offset, pinstr->AsString().c_str()));

            }


            if (!pinfo->stop.empty() && !pinfo->instr->mTemplate.ret /*&& injectstr != "//quiet"*/)
                assert(0);
            if (pinstr->isTerminating)
                assert(0);
            if (pinstr->isReturning)
                assert(0);
            
            next = {p.first.segment, p.first.offset + p.second->instr->mSize};
        }

        /*


             
             if (mOptions.GetJumpTables(pinstr->mAddress).size())
             {
                 assert(pinstr->IsIndirectCall() || pinstr->IsIndirectJump());
                 DumpIndirectTables(pMemoryHints, pinfo, info->func);
             } else
             if (convert[pinstr->mId].convert)
             {
                 std::string command = iformat(pinstr, pinfo, info->func, convert[pinstr->mId].convert(pinstr, pinfo, info->func));
                 if (injectstr == "//comment")
                     command = "// " + utils::replace(command, "\n", "");
                 PostProcessMemoryHint(pMemoryHints, command);
                 
                 if (command.size())
                     mCode.push_back("    " + command + "\n");
             }
             else
             {
                 mCode.push_back(utils::format("    stop(\"disassembly failed at %x:%x %s\");\n",
                                               pinstr->mAddress.segment, pinstr->mAddress.offset, pinstr->AsString().c_str()));
 //                break;
 //                printf("Conversion for '%s'@ %x:%x not implemented!\n", pinstr->AsString().c_str(), pinstr->mAddress.segment, pinstr->mAddress.offset);
 //                assert(0);
             }
             
             mCode.insert(mCode.end(), post.begin(), post.end());

             if (!pinfo->stop.empty() && !pinfo->instr->mTemplate.ret && injectstr != "//quiet")
                 mCode.push_back("    stop(\""  + pinfo->stop + "\", \"" + pinfo->instr->mAddress.toString() + "\");\n");
             if (pinstr->isTerminating)
                 mCode.push_back("    stop(\"terminating\");\n");
             if (pinstr->isReturning)
             {
                 mCode.push_back("    return;\n");
             }

             next = {p.first.segment, p.first.offset + p.second->instr->mSize};
         }

         */
        return procir;
    }
    
private:
    std::set<std::string> GetTempVariables(Analyser::code_t& code, shared<Analyser::info_t> info)
    {
        std::set<std::string> tempNames;
        for (const auto& p : code)
        {
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            
            for (const instrInfo_t::instrInfoFlag_t* flag : pinfo->Flags())
                if (flag->save && !flag->depends.empty())
                    tempNames.insert(utils::format("temp_%cf", flag->type));

            for (const auto& p : pinfo->savePrecondition)
                tempNames.insert(p.variable);
        }
        return tempNames;
    }

};

class PrintIr {
public:
    std::string ToString(shared<OperandIr> op)
    {
        switch (op->type)
        {
            case OperandIr::Type_t::Const:
                assert(0);
                break;
            case OperandIr::Type_t::Register:
                assert(0);
                break;
            case OperandIr::Type_t::Memory:
                assert(0);
                break;
            case OperandIr::Type_t::String:
                assert(0);
                break;
            case OperandIr::Type_t::Operator:
                assert(0);
                break;
            default:
                assert(0);
        }
        return "";
    }
    void Print(shared<ProcIr> prog)
    {
        if (prog->info.empty())
            printf("void %s()\n", prog->name.c_str());
        else
            printf("void %s() // %s\n", prog->name.c_str(), prog->info.c_str());
        printf("{\n");
        for (auto st : prog->lines)
        {
            switch (st.type)
            {
                case StatementIr::Type_t::Assignment:
                    printf("    %s = %s\n", ToString(st.op1).c_str(), ToString(st.op2).c_str());
                    break;
                default:
                    assert(0);
            }
        }
        printf("}\n");
    }
};

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
    Capstone->Set(loader, *options);
    
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
    
    printHeading(options, loader, analyser);
    
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

//    ConvertIr conv(analyser, options);
//    PrintIr print;
    for (address_t proc : analyser.AllMethods())
    {
        
        Convert convert(analyser, *options);
        convert.SetOffsetMask(options->arch == arch_t::arch16 ? 0xffff : -1); // 16 bit
        convert.ConvertProc(proc);
        convert.Dump();
         
        
//        auto ir = conv.Convert(proc);
//        print.Print(ir);
    }
    
    printFooter(options, loader, analyser);

    return 0;
}

