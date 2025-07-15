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
    shared<CTracer> mTracer;
    std::vector<std::string> mCode;
    
public:
    Convert(const Analyser& anal, const Options& options) : mAnal(anal), mOptions(options)
    {
    }

    void ConvertProc(address_t proc)
    {
        const bool verbose{mOptions.verbose};
        
        mTracer = mAnal.mMethods.find(proc)->second;
        CTracer::code_t& code = mTracer->GetCode();
        assert(!code.empty());

        for (const auto& p : code)
        {
            if (verbose)
                printf("%s%x %x:%x %s %s\n", p.second->isLabel ? "loc_" : "    ", p.second->mAddress.linearOffset(), p.second->mAddress.segment, p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);
        }

        if (code.size() == 1 && code.begin()->second->mId == X86_INS_JMP)
        {
            // stub
            mCode.push_back(format("void sub_%x()\n{\n", proc.linearOffset()));
            mCode.push_back(format("  sub_%x();\n", code.begin()->second->JumpTarget().linearOffset()));
            mCode.push_back("}\n\n");
            return;
        }
        assert(mAnal.mInfos.find(proc) != mAnal.mInfos.end());
        shared<Analyser::info_t> info = mAnal.mInfos.find(proc)->second;
        
        std::string extraInfo = "";
        if (info->request != procRequest_t::returnNone)
        {
            extraInfo += " //";
            if ((int)info->request & (int)procRequest_t::returnCarry)
                extraInfo += " +returnCarry";
            if ((int)info->request & (int)procRequest_t::returnZero)
                extraInfo += " +returnZero";

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

        if (info->code.find(proc)->second->callConv == instrInfo_t::callConvShiftStackNear)
            mCode.push_back("    sp -= 2;\n");
        if (info->code.find(proc)->second->callConv == instrInfo_t::callConvShiftStackFar)
            mCode.push_back("    sp -= 4;\n");

        if (code.begin()->first != proc)
            mCode.push_back(format("    goto loc_%x;\n", proc.linearOffset()));

        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                mCode.push_back(format("  // gap %d bytes\n", p.first.offset - next.offset));
            }
            shared<CapInstr> pinstr = p.second;
            auto codeit = info->code.find(p.first);
            assert(codeit != info->code.end());
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            
            if (verbose)
                printf("/*%x %s %s*/\n", p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);

            if (pinstr->isLabel) // && !pinfo->isLast) // TODO: goto ret
                mCode.push_back(format("loc_%x:\n", pinstr->mAddress.linearOffset()));
                
            for (const instrInfo_t::instrInfoFlag_t* flag : pinfo->Flags())
            {
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
                    mCode.push_back("    " + std::string(flag->variableWrite) + " = " + iformat(pinstr, pinfo, save(p.second, pinfo)) + ";\n");
                }
            }
            
            if (pinfo->savePrecondition.size())
            {
                assert(pinfo->savePrecondition.size()==1);
                mCode.push_back("    " + pinfo->savePrecondition[0].variable + " = " + iformat(pinstr, pinfo, precondition(pinstr, pinfo->savePrecondition[0].readOp)) + ";\n");
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
            
            if (mOptions.GetJumpTable(pinstr->mAddress))
            {
                assert(pinstr->IsIndirectCall() || pinstr->IsIndirectJump());
                DumpIndirectTable(mOptions.GetJumpTable(pinstr->mAddress));
            } else
            if (convert[pinstr->mId].convert)
            {
                std::string command = iformat(pinstr, pinfo, convert[pinstr->mId].convert(p.second, pinfo));
                if (command.size())
                    mCode.push_back("    " + command + "\n");
            }
            else
            {
                printf("Conversion for '%s'/%x not implemented!\n", pinstr->AsString().c_str(), pinstr->mAddress.offset);
                assert(0);
            }
            
            if (!pinfo->stop.empty())
                mCode.push_back("    stop("  + pinfo->stop + ");\n;");
            if (pinstr->isTerminating)
                mCode.push_back("    stop(\"terminating\");\n");
            if (pinstr->isReturning)
                mCode.push_back("    return;\n");

            next = {p.second->mAddress.segment, p.second->mAddress.offset + p.second->mSize};
        }
        mCode.push_back("}\n");
    }
    
    std::set<std::string> GetTempVariables(CTracer::code_t& code, shared<Analyser::info_t> info)
    {
        std::set<std::string> tempNames;
        for (const auto& p : code)
        {
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            if (pinfo->flagSign.variableWrite[0])
                tempNames.insert(pinfo->flagSign.variableWrite);
            if (pinfo->flagCarry.variableWrite[0])
                tempNames.insert(pinfo->flagCarry.variableWrite);
            if (pinfo->flagZero.variableWrite[0])
                tempNames.insert(pinfo->flagZero.variableWrite);
            if (pinfo->flagOverflow.variableWrite[0])
                tempNames.insert(pinfo->flagOverflow.variableWrite);
            if (!pinfo->savePrecondition.empty())
                tempNames.insert(pinfo->savePrecondition[0].variable);
        }
        return tempNames;
    }

    void DumpIndirectTable(shared<jumpTable_t> jt)
    {
        mCode.push_back(format("    switch (%s)\n", jt->selector));
        mCode.push_back(format("    {\n"));
        for (int i=0; i<jt->GetSize(); i++)
            mCode.push_back(format("        %s\n", jt->GetCase(i).c_str()));
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
        assert(0);
        return "";
    }
    
    std::string InvertCondition(std::string cond)
    {
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
    
    virtual std::string BuildCondition(shared<CapInstr> instr, shared<instrInfo_t> info) override
    {
        if (!info->readPrecondition.empty())
        {
            assert(info->readPrecondition.size() == 1);
            return info->readPrecondition[0];
        }
        
        bool dirty = false;
        std::set<address_t, cmp_adress_t> lastSet;
        int needFlags = info->flagZero.needed + info->flagCarry.needed + info->flagSign.needed + info->flagOverflow.needed;
        char needFlag = 0;
        
        for (const instrInfo_t::instrInfoFlag_t* flag : info->Flags())
            if (flag->needed)
            {
                dirty |= flag->dirty[0] | flag->dirty[1] | flag->dirty[2];
                lastSet.insert(flag->lastSet.begin(), flag->lastSet.end());
                needFlag = flag->type;
            }
        
        if (!dirty && needFlags == 1 && lastSet.size() == 1)
        {
            // single flag needed
            shared<CapInstr> lastSetInstr = mTracer->GetCode().find(*lastSet.begin())->second;
            convert_t templ = convert[lastSetInstr->mId];
            convert_t cond = convert[instr->mId];
            std::string flagCondition = cond.flagCondition;
            
            for (const instrInfo_t::instrInfoFlag_t* flag : info->Flags())
            {
                if (flag->needed)
                {
                    // expression to recover flag value
                    std::string value = flag->variableRead;
                    if (value.empty())
                    {
                        switch (flag->type)
                        {
                            case 'c': value = templ.cf(lastSetInstr, info); break;
                            case 'z': value = templ.zf(lastSetInstr, info); break;
                            case 's': value = templ.sf(lastSetInstr, info); break;
                        }
                        assert(!value.empty());
                    }
                    
                    // needs to be inverted?
                    if (flagCondition[0] == '$' && flagCondition[1] == flag->type)
                        return iformat(lastSetInstr, info, value);
                    else if (flagCondition[0] == '!' && flagCondition[1] == '$' && flagCondition[2] == flag->type)
                        return iformat(lastSetInstr, info, InvertCondition(value));
                    else
                        assert(0);
                }
            }
            assert(0);
        }
        
        if ((dirty || lastSet.size() > 1) && needFlags == 1 && !info->GetFlag(needFlag).variableRead.empty())
        {
            convert_t cond = convert[instr->mId];
            std::string flagCondition = cond.flagCondition;
            if (flagCondition[1] == needFlag) // "$carry"
                return info->GetFlag(needFlag).variableRead;
            else if (flagCondition[0] == '!' && flagCondition[2] == needFlag) // "!$carry"
                return InvertCondition(info->GetFlag(needFlag).variableRead);
            else
                assert(0);
        }
        
        if (!dirty && needFlags > 1)
        {
            assert(lastSet.size() == 1);
            shared<CapInstr> lastSetInstr = mTracer->GetCode().find(*lastSet.begin())->second;
            shared<instrInfo_t> lastSetInfo = info; // TODO: NOT REAL!!
            return iformat(lastSetInstr, lastSetInfo, precondition(lastSetInstr, instr->mId));
        }
        assert(0);
        return "";
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
};
