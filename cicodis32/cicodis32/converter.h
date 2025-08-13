//
//  converter.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

#include <sstream>
#include "convtable.h"

class Convert : public Formatter
{
    const Analyser& mAnal;
    const Options& mOptions;
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
        Analyser::code_t& code = mInfo->code;
        assert(!code.empty());

        if (verbose)
            DumpInput(code);

        // TODO: bStub!
        if (code.size() == 1 && code.begin()->second->instr->mId == X86_INS_JMP)
        {
            // stub
            mCode.push_back(format("void sub_%x()\n{\n", proc.linearOffset()));
            mCode.push_back(format("  sub_%x();\n", code.begin()->second->instr->JumpTarget().linearOffset()));
            mCode.push_back("}\n\n");
            return;
        }
        assert(mAnal.mInfos.find(proc) != mAnal.mInfos.end());
        shared<Analyser::info_t> info = mAnal.mInfos.find(proc)->second;
        
        std::string extraInfo = "";
        if (info->func.request != procRequest_t::none && info->func.request != procRequest_t::callNear)
        {
            extraInfo += " //";
            int temp = (int)info->func.request;
            if (temp & (int)procRequest_t::callNear && temp & (int)procRequest_t::callFar)
            {
                extraInfo += " +nearfar";
                temp ^= (int)procRequest_t::callNear;
                temp ^= (int)procRequest_t::callFar;
            } else {
                if (temp & (int)procRequest_t::callNear)
                {
                    temp ^= (int)procRequest_t::callNear;
                }
                if (temp & (int)procRequest_t::callFar)
                {
                    extraInfo += " +far";
                    temp ^= (int)procRequest_t::callFar;
                }
            }
            if (temp & (int)procRequest_t::returnCarry)
            {
                extraInfo += " +returnCarry";
                temp ^= (int)procRequest_t::returnCarry;
            }
            if (temp & (int)procRequest_t::returnZero)
            {
                extraInfo += " +returnZero";
                temp ^= (int)procRequest_t::returnZero;
            }
            if (temp & (int)procRequest_t::stackDrop2)
            {
                extraInfo += " +stackDrop2";
                temp ^= (int)procRequest_t::stackDrop2;
            }
            if (temp & (int)procRequest_t::stackDrop4)
            {
                extraInfo += " +stackDrop4";
                temp ^= (int)procRequest_t::stackDrop4;
            }
            if (temp & (int)procRequest_t::stackDrop6)
            {
                extraInfo += " +stackDrop6";
                temp ^= (int)procRequest_t::stackDrop6;
            }
            if (temp & (int)procRequest_t::stackDrop8)
            {
                extraInfo += " +stackDrop8";
                temp ^= (int)procRequest_t::stackDrop8;
            }
            if (temp & (int)procRequest_t::stackDrop10)
            {
                extraInfo += " +stackDrop10";
                temp ^= (int)procRequest_t::stackDrop10;
            }
            if (temp & (int)procRequest_t::callIsolated)
            {
                extraInfo += " +isolate";
                temp ^= (int)procRequest_t::callIsolated;
            }
            assert(temp == 0);
        }
        mCode.push_back(format("void sub_%x()%s\n{\n", proc.linearOffset(), extraInfo.c_str()));

        bool anyTemp = false;
        for (std::string str : GetTempVariables(code, info))
            if (!str.starts_with("flags."))
            {
                mCode.push_back(format("    bool %s;\n", str.c_str()));
                anyTemp = true;
            }

        if (anyTemp)
            mCode.push_back("\n");

        if (info->func.callConv == callConv_t::callConvShiftStackNear)
            mCode.push_back("    sp -= 2;\n");
        if (info->func.callConv == callConv_t::callConvShiftStackFar)
            mCode.push_back("    sp -= 2;\n"); // TODO!!!

        if (code.begin()->first != proc)
            mCode.push_back(format("    goto loc_%x;\n", proc.linearOffset()));

        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                mCode.push_back(format("  // gap %d bytes\n", p.first.offset - next.offset));
            }
            shared<CapInstr> pinstr = p.second->instr;
            auto codeit = info->code.find(p.first);
            assert(codeit != info->code.end());
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            
            if (verbose)
                printf("/*%x %s %s*/\n", p.second->instr->mAddress.offset, p.second->instr->mMnemonic, p.second->instr->mOperands);

            if (pinstr->isLabel) // && !pinfo->isLast) // TODO: goto ret
                mCode.push_back(format("loc_%x:\n", pinstr->mAddress.linearOffset()));

            const auto& injectit = mOptions.inject.find(p.first);
            if (injectit != mOptions.inject.end())
                mCode.push_back(std::string("    ") + injectit->second + "\n");

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
                    assert(save);
                    
                    std::string fName(flagName[flag->type]);
                                        
                    if (!flag->depends.empty())
                    {
                        std::string tempName = utils::format("temp_%cf", flag->type);
                        post.push_back(std::string("    ") + fName + " = " + tempName + ";\n");
                        fName = tempName;
                    }
                        
                    mCode.push_back(std::string("    ") + fName + " = " + iformat(pinstr, pinfo, info->func, save(pinstr, pinfo, info->func)) + ";\n");
                }
            }

            if (pinfo->savePrecondition.size())
            {
                assert(pinfo->savePrecondition.size()==1);
                mCode.push_back("    " + pinfo->savePrecondition[0].variable + " = " + iformat(pinstr, pinfo, info->func, precondition(pinstr, pinfo->savePrecondition[0].readOp)) + ";\n");
            }

            if (pinfo->infiniteLoop)
            {
                bool memOp = false;
                for (int i=0; i<pinstr->mDetail.op_count; i++)
                    if (pinstr->mDetail.operands[i].type == X86_OP_MEM)
                        memOp = true;
                    
                if (memOp)
                    mCode.push_back("    sync();\n");
                else
                    mCode.push_back("    stop(\"infinite loop\");\n");
            }
            
            
            if (!pinfo->stop.empty() && pinfo->instr->mTemplate.ret)
                mCode.push_back("    stop(\""  + pinfo->stop + "\");\n");

            if (mOptions.GetJumpTable(pinstr->mAddress))
            {
                assert(pinstr->IsIndirectCall() || pinstr->IsIndirectJump());
                DumpIndirectTable(mOptions.GetJumpTable(pinstr->mAddress));
            } else
            if (convert[pinstr->mId].convert)
            {
                if (pinstr->mAddress.offset == 3953)
                {
                    int f = 9;
                }
                std::string command = iformat(pinstr, pinfo, info->func, convert[pinstr->mId].convert(pinstr, pinfo, info->func));
                if (command.size())
                    mCode.push_back("    " + command + "\n");
            }
            else
            {
                printf("Conversion for '%s'/%x not implemented!\n", pinstr->AsString().c_str(), pinstr->mAddress.offset);
                assert(0);
            }
            
            mCode.insert(mCode.end(), post.begin(), post.end());

            if (!pinfo->stop.empty() && !pinfo->instr->mTemplate.ret)
                mCode.push_back("    stop(\""  + pinfo->stop + "\");\n");
            if (pinstr->isTerminating)
                mCode.push_back("    stop(\"terminating\");\n");
            if (pinstr->isReturning)
            {
//                mCode.push_back("    stop(\"TODO:stack_correction\");\n");
//                assert(0); // TODO: insert stack correction!!
                // return flags?
                mCode.push_back("    return;\n");
            }

            next = {p.first.segment, p.first.offset + p.second->instr->mSize};
        }
        mCode.push_back("}\n");
    }
    
    std::set<std::string> GetTempVariables(Analyser::code_t& code, shared<Analyser::info_t> info)
    {
        std::set<std::string> tempNames;
        for (const auto& p : code)
        {
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            
            for (const instrInfo_t::instrInfoFlag_t* flag : pinfo->Flags())
                if (flag->save && !flag->depends.empty())
                    tempNames.insert(utils::format("temp_%cf", flag->type));

            if (!pinfo->savePrecondition.empty())
                tempNames.insert(pinfo->savePrecondition[0].variable);
        }
        return tempNames;
    }

    void DumpIndirectTable(shared<jumpTable_t> jt)
    {
        std::set<int> dupl;
        
        mCode.push_back(format("    switch (%s)\n", jt->selector));
        mCode.push_back(format("    {\n"));
        for (int i=0; i<jt->GetSize(); i++)
            if (jt->IsValid(i))
            {
                if (jt->useCaseOffset)
                {
                    int addr = jt->GetTarget(i).linearOffset();
                    if (dupl.find(addr) != dupl.end())
                        continue;
                    dupl.insert(addr);
                }
                
                mCode.push_back(format("        %s\n", jt->GetCase(i).c_str()));
            }
        mCode.push_back(format("        default:\n"));
        mCode.push_back(format("            stop();\n"));
        mCode.push_back(format("    }\n"));
    }
    
    std::string precondition(shared<CapInstr> instr, x86_insn cond)
    {
        x86_insn set = instr->mId;
        if (set == X86_INS_ADD && cond == X86_INS_JG)
            return "($sig0)$rd0 + ($sig0)$rd1 > 0";
        if (set == X86_INS_ADD && cond == X86_INS_JL)
            return "($sig0)$rd0 + ($sig0)$rd1 < 0";
        if (set == X86_INS_ADD && cond == X86_INS_JLE)
            return "($sig0)$rd0 + ($sig0)$rd1 <= 0";
        if (set == X86_INS_SUB && cond == X86_INS_JG)
            return "($sig0)$rd0 - ($sig0)$rd1 > 0";
        if (set == X86_INS_SUB && cond == X86_INS_JLE)
            return "($sig0)$rd0 - ($sig0)$rd1 <= 0";
        if (set == X86_INS_SUB && cond == X86_INS_JA)
            return "$rd0 - $rd1 > 0";
        
        // simple
        if (set == X86_INS_CMP && cond == X86_INS_JGE)
            return "($sig0)$rd0 >= ($sig0)$rd1";
        if (set == X86_INS_CMP && cond == X86_INS_JLE)
            return "($sig0)$rd0 <= ($sig0)$rd1";
        if (set == X86_INS_CMP && cond == X86_INS_JA)
            return "$rd0 > $rd1";
        if (set == X86_INS_CMP && cond == X86_INS_JG)
            return "($sig0)$rd0 > ($sig0)$rd1";
        if (set == X86_INS_CMP && cond == X86_INS_JL)
            return "($sig0)$rd0 < ($sig0)$rd1";
        if (set == X86_INS_CMP && cond == X86_INS_JBE)
            return "$rd0 <= $rd1";
        if (set == X86_INS_OR && cond == X86_INS_JA) // cf=0, zf=?, ja: !cf & !zf
            return "!$rd0 /*ggg6*/";
        if (set == X86_INS_OR && cond == X86_INS_JGE)
            return "($sig0)$rd0 >= 0";
        if (set == X86_INS_OR && cond == X86_INS_JLE)
            return "($sig0)$rd0 <= 0";
        if (set == X86_INS_OR && cond == X86_INS_JL)
            return "($sig0)$rd0 < 0";
        if (set == X86_INS_CALL && cond == X86_INS_JA)
            return "!flags.carry && !flags.zero";
        if (set == X86_INS_CALL && cond == X86_INS_JBE)
            return "flags.carry || flags.zero";
        if (set == X86_INS_OR && cond == X86_INS_JBE)
            return "!$rd0";
        if (set == X86_INS_DEC && cond == X86_INS_JG)
            return "($sig0)$rd0 > 0 /*ggg7*/ && stop()"; // check unbalanced

        assert(0);
        return "";
    }
    
    std::string InvertCondition(std::string cond)
    {
        if (cond.find("stop") != std::string::npos)
            return "!" + cond;
        if (cond == "$rd0" || cond == "flags.carry" || cond == "flags.zero")
            return "!" + cond;
        if (cond == "$rd0 == $rd1")
            return "$rd0 != $rd1";
        if (cond == "$rd0 < $rd1")
            return "$rd0 >= $rd1";
        if (cond == "$rd0 & $rd1")
            return "!($rd0 & $rd1)";
        if (cond == "!($rd0 & $rd1)")
            return "$rd0 & $rd1";
        if (cond == "($sig0)$rd0 < 0")
            return "($sig0)$rd0 >= 0";
        if (cond == "!$rd0")
            return "$rd0";
        if (cond.starts_with("temp_"))
            return "!" + cond;
        if (cond == "($sig0)$rd0 < ($sig1)$rd1")
            return "($sig0)$rd0 >= ($sig1)$rd1";
        if (cond == "!$rd0 /* gabo-3 */")
            return "$rd0 /* gabo-3 */";
        if (cond.starts_with("flags."))
            return "!"+cond;
        assert(0);
        return "!(" + cond+ ")";
    }
    
    virtual std::string BuildCondition(shared<CapInstr> instr, shared<instrInfo_t> info, const funcInfo_t& func) override
    {
        if (instr->mAddress.offset == 0xe13)
        {
            int f= 9;
        }
        if (!info->readPrecondition.empty())
        {
            assert(info->readPrecondition.size() == 1);
            return info->readPrecondition[0];
        }
        
        bool dirty = false;
        std::set<address_t> lastSet;
        int needFlags = 0; //info->flagZero.needed + info->flagCarry.needed + info->flagSign.needed + info->flagOverflow.needed;
        std::set<char> needType;
        
        bool allVisible = false;
        for (const instrInfo_t::instrInfoFlag_t* flag : info->Flags())
            if (flag->needed)
            {
                assert(!flag->lastSet.empty());
                needFlags++;
                dirty |= flag->dirty;
                lastSet.insert(flag->lastSet.begin(), flag->lastSet.end());
                needType.insert(flag->type);
            }
        
        if (needType.size() == 1)
        {
            allVisible = true;
            for (address_t adr : lastSet)
            {
                shared<instrInfo_t> lastSetInstr = mInfo->code.find(adr)->second;
                if (!lastSetInstr->GetFlag(*needType.begin()).visible &&
                    !lastSetInstr->GetFlag(*needType.begin()).save)
                    allVisible = false;
//                allVisible &= lastSetInstr->GetFlag(*needType.begin()).visible;
            }
        }
        if (allVisible)
        {
            convert_t cond = convert[instr->mId];
            std::string flagCondition = cond.flagCondition;
            char needFlag = *needType.begin();

            std::string value;
            switch (needFlag)
            {
                case 'c': value = "flags.carry"; break;
                case 'z': value = "flags.zero"; break;
                case 's': value = "flags.sign"; break;
                default:
                    assert(0);
            }
            if (flagCondition[0] == '$' && flagCondition[1] == needFlag)
                return iformat(instr, info, func, value);
            else if (flagCondition[0] == '!' && flagCondition[1] == '$' && flagCondition[2] == needFlag)
                return iformat(instr, info, func, InvertCondition(value));
            else if (flagCondition == "$ret")
                return iformat(instr, info, func, value);
            assert(0);
        }
        
        if (!dirty && needFlags == 1 && lastSet.size() == 1)
        {
            // single flag needed
            shared<instrInfo_t> lastSetInstr = mInfo->code.find(*lastSet.begin())->second;
            convert_t templ = convert[lastSetInstr->instr->mId];
            convert_t cond = convert[instr->mId];
            std::string flagCondition = cond.flagCondition;
            
            for (const instrInfo_t::instrInfoFlag_t* flag : info->Flags())
            {
                if (flag->needed)
                {
                    // expression to recover flag value
                    std::string value;
                    if (lastSetInstr->GetFlag(flag->type).save || lastSetInstr->GetFlag(flag->type).visible)
                    {
                        switch (flag->type)
                        {
                            case 'c': value = "flags.carry"; break;
                            case 'z': value = "flags.zero"; break;
                            default:
                                assert(0);
                        }
                    }
                    if (value.empty())
                    {
                        switch (flag->type)
                        {
                            case 'c': value = templ.cf(lastSetInstr->instr, info, func); break;
                            case 'z': value = templ.zf(lastSetInstr->instr, info, func); break;
                            case 's': value = templ.sf(lastSetInstr->instr, info, func); break;
                        }
                        assert(!value.empty());
                    }
                    
                    // needs to be inverted?
                    if (flagCondition[0] == '$' && flagCondition[1] == flag->type)
                        return iformat(lastSetInstr->instr, info, func, value);
                    else if (flagCondition[0] == '!' && flagCondition[1] == '$' && flagCondition[2] == flag->type)
                        return iformat(lastSetInstr->instr, info, func, InvertCondition(value));
                    else if (flagCondition == "$ret")
                        return iformat(lastSetInstr->instr, info, func, value);
                    else
                        assert(0);
                }
            }
            assert(0);
        }
        
        if (dirty)
        {
            convert_t cond = convert[instr->mId];
            std::string flagCondition = cond.flagCondition;
            if (flagCondition == "$carry")
                return "flags.carry";
            else if (flagCondition == "!$carry")
                return "!flags.carry";
            else if (flagCondition == "$zero")
                return "flags.zero";
            else if (flagCondition == "!$zero")
                return "!flags.zero";
            assert(0);
        }
//        if ((dirty || lastSet.size() > 1) && needFlags == 1 && needType.size() == 1 && !info->GetFlag(*needType.begin()).variableRead.empty())
//        {
//            char needFlag = *needType.begin();
//            convert_t cond = convert[instr->mId];
//            std::string flagCondition = cond.flagCondition;
//            if (flagCondition[1] == needFlag) // "$carry"
//                return info->GetFlag(needFlag).variableRead;
//            else if (flagCondition[0] == '!' && flagCondition[2] == needFlag) // "!$carry"
//                return InvertCondition(info->GetFlag(needFlag).variableRead);
//            else
//                assert(0);
//        }
        
        if (!dirty && needFlags > 1)
        {
            assert(lastSet.size() == 1);
            shared<instrInfo_t> lastSetInfo = mInfo->code.find(*lastSet.begin())->second;
            return iformat(lastSetInfo->instr, lastSetInfo, func, precondition(lastSetInfo->instr, instr->mId));
        }
        assert(0);
        return "stop(\"build_condition_failed\")";
    }
    
    virtual std::string BuildStringOp(shared<CapInstr> instr, shared<instrInfo_t> info) override
    {
        auto replace = [](const char* in, const char* s, const char* r)
        {
            char temp[128];
            strcpy(temp, in);
            for (int i=0; temp[i]; i++)
                if (temp[i] == s[0])
                    temp[i] = r[0];
            return std::string(temp);
        };
        auto split = [] (const std::string& input, const std::string& delimiter) -> std::vector<std::string> {
            std::vector<std::string> tokens;
            std::size_t start = 0;
            std::size_t end;

            while ((end = input.find(delimiter, start)) != std::string::npos) {
                tokens.push_back(input.substr(start, end - start));
                start = end + delimiter.length();
            }

            tokens.push_back(input.substr(start)); // add the last token
            return tokens;
        };
        auto argToTemplate = [](std::string in) -> std::string {
            if (in == "byte ptr es:[edi]" || in == "word ptr es:[edi]" || in == "dword ptr es:[edi]")
                return "ES_EDI";
            if (in == "byte ptr es:[di]" || in == "word ptr es:[di]")
                return "ES_DI";
            if (in == "word ptr [si]" || in == "byte ptr [si]")
                return "DS_SI";
            if (in == "word ptr [esi]")
                return "DS_ESI";
            assert(0);
            return "?";
        };
        std::string repeat = "";
        std::string templ = replace(instr->mMnemonic, " ", "_");
        std::vector<std::string> args = split(instr->mOperands, ", ");
        assert(args.size() == 2);
        if (templ.starts_with("rep_"))
        {
            repeat = "for (; cx != 0; --cx) ";
            templ = templ.substr(4);
        }
        if (templ.starts_with("repne_"))
        {
            repeat = "for (flags.zero = 0; cx != 0 && !flags.zero; --cx) ";
            templ = templ.substr(6);
        }
        if (args[0] == "al")
            return repeat + templ + "_inv<" + argToTemplate(args[1]) + ">("+args[0]+");";
        if (args[1] == "al" || args[1] == "ax" || args[1] == "eax")
            return repeat + templ + "<" + argToTemplate(args[0]) + ">("+args[1]+");";
        else
            return repeat + templ + "<" + argToTemplate(args[0]) + ", " + argToTemplate(args[1]) + ">();";
    }

    void Dump()
    {
        for (std::string line : mCode)
            printf("%s", line.c_str());
    }
    
    void DumpInput(Analyser::code_t& code)
    {
        for (const auto& [addr, pi] : code)
        {
            shared<CapInstr> p = pi->instr;
            char disasm[40];
            char depends[120] = {0};
            char provides[120] = {0};
            for (instrInfo_t::instrInfoFlag_t* f : pi->Flags())
            {
                for (const auto addr : f->depends)
                {
                    char temp[120];
                    snprintf(temp, sizeof(temp), "r%cf: %x ", f->type, addr.offset);
                    strncat(depends, temp, sizeof(depends)-1);
                    if (f->dirty)
                        strncat(depends, "(dirty) ", sizeof(depends)-1);
                }
                for (const auto addr : f->provides)
                {
                    char temp[120];
                    snprintf(temp, sizeof(temp), "w%cf: %x ", f->type, addr.offset);
                    strncat(provides, temp, sizeof(provides)-1);
                    if (f->save)
                        strncat(provides, "(save) ", sizeof(depends)-1);
                }
            }
            snprintf(disasm, sizeof(disasm), "%s %s", p->mMnemonic, p->mOperands);
            printf("%3d ", pi->stack);
            printf("%s%x %x:%x %-30s %s%s\n", p->isLabel ? "loc_" : "    ", p->mAddress.linearOffset(), p->mAddress.segment, p->mAddress.offset, disasm, depends, provides);
        }
    }
};
