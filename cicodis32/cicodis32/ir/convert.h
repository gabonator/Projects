//
//  convert.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 09/12/2025.
//

class ConvertIr {
    shared<Options> mOptions;
    Analyser& mAnalyser;
    
public:
    ConvertIr(Analyser& analyser, shared<Options> options) : mOptions(options), mAnalyser(analyser)
    {
    }
    
    shared<ProcIr> Convert(address_t proc)
    {
        shared<ProcIr> xprocir = std::make_shared<ProcIr>();
        auto append = [&](address_t addr, const StatementIr& statement)
        {
            if (statement.type == StatementIr::Type_t::None)
                return;
//            PrintIr::Print(statement);
            xprocir->lines.push_back(statement);
            xprocir->lines.back().address = addr;
        };
        
        assert(mAnalyser.mInfos.find(proc) != mAnalyser.mInfos.end());
        shared<Analyser::info_t> info = mAnalyser.mInfos.find(proc)->second;
        
        std::string extraInfo = "";
        if ((info->func.request != procRequest_t::none && info->func.request != procRequest_t::callNear) || mOptions->printLabelAddress)
        {
            if (mOptions->printLabelAddress)
                extraInfo += utils::format("%04x:%04x", proc.segment, proc.offset);
            
            extraInfo += info->func.makeProcIdentifier();
        }
        xprocir->name = format("void sub_%x()", proc.linearOffset());
        xprocir->info = extraInfo;

        //
        shared <Analyser::info_t> mInfo = mAnalyser.mInfos.find(proc)->second;
        Analyser::code_t& code = mInfo->code;
        assert(!code.empty());

        for (std::string str : GetTempVariables(code, info))
            if (!str.starts_with("flags."))
                xprocir->temps.push_back(str);

        //
        if (!((int)info->func.request & (int)procRequest_t::callIsolated))
        {
            StatementIr shiftSp = OP_MOD("assign") << OP_BINARY(OP_VAR("sp"), "-", OP_CONST(2));
            StatementIr shiftEsp = OP_MOD("assign") << OP_BINARY(OP_VAR("esp"), "-", OP_CONST(4));

            if (info->func.callConv == callConv_t::callConvShiftStackNear)
                append(code.begin()->first, shiftSp);
            if (info->func.callConv == callConv_t::callConvShiftStackFar)
                append(code.begin()->first, shiftSp);
            if (info->func.callConv == callConv_t::callConvShiftStackNearFar)
                append(code.begin()->first, shiftSp);
            if (info->func.callConv == callConv_t::callConvShiftStackLong)
                append(code.begin()->first, shiftEsp);
        }
        
        if (code.begin()->first != proc)
        {
            append(code.begin()->first, StatementIr{.type = StatementIr::Type_t::DirectJump,
                .target = proc});
        }

        //
        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                append(p.first, StatementIr{.type = StatementIr::Type_t::Comment,
                    .comment = format("gap %d bytes", p.first.offset - next.offset)});
            }
            
            shared<CapInstr> pinstr = p.second->instr;
            auto codeit = info->code.find(p.first);
            assert(codeit != info->code.end());
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            StatementIr post;
            
            if (pinstr->isLabel)
            {
                std::string label = format("loc_%x", pinstr->mAddress.linearOffset());

                if (mOptions->printProcAddress)
                    append(p.first, StatementIr{.type = StatementIr::Type_t::Label,
                        .address = pinstr->mAddress,
                        .comment = pinstr->mAddress.toString()});
                else
                    append(p.first, StatementIr{.type = StatementIr::Type_t::Label,
                        .address = pinstr->mAddress});
            }

            for (const instrInfo_t::instrInfoFlag_t* flag : pinfo->Flags())
            {
                static const char* flagName[128] = {['c'] = "flags.carry",
                    ['z'] = "flags.zero", ['s'] = "flags.sign", ['o'] = "flags.overflow"};
                static const x86_insn flagCond[128] = {
                    ['c'] = X86_INS_JB,
                    ['z'] = X86_INS_JE,
                    ['s'] = X86_INS_JS,
                };
                if (flag->save)
                {
                    std::string useFlagName(flagName[flag->type]);
                    if (!flag->depends.empty())
                    {
                        std::string tempName = utils::format("temp_%cf", flag->type);
                        append(p.first, ASSIGN(OP_VAR(tempName), OP_VAR(useFlagName)));
                        assert(!post);
                        post = ASSIGN(OP_VAR(useFlagName), OP_VAR(tempName));
                        useFlagName = tempName;
                    }

                    StatementIr st{.type = StatementIr::Type_t::Assignment,
                            .opd = std::make_shared<OperandIr>(OperandIr::Type_t::Variable, useFlagName),
                            .stmt1 = std::make_shared<StatementIr>(PreCondition(pinfo->instr, flagCond[flag->type]))
                    };
                    append(p.first, st);
                }
            }
            
            if (pinfo->savePrecondition.size())
            {
                for (const auto& prec : pinfo->savePrecondition)
                {
                    StatementIr st = ASSIGN(OP_VAR(prec.variable), StatementBuilder(std::make_shared<StatementIr>(PreCondition(pinfo->instr, prec.readOp))));
                    append(p.first, st);
                }
            }
            
            if (!pinfo->stop.empty() && pinfo->instr->mTemplate.ret)
                append(p.first, StatementIr{.type = StatementIr::Type_t::Stop, .stop = pinfo->stop});
            
            if (pinfo->infiniteLoop)
            {
                bool memOp = false;
                for (int i=0; i<pinstr->mDetail.op_count; i++)
                    if (pinstr->mDetail.operands[i].type == X86_OP_MEM)
                        memOp = true;
                    
                if (memOp)
                    append(p.first, OP_FUNCTION("sync"));
                else
                    append(p.first, OP_FUNCTION("stop", OP_STR("\"infinite loop\"")));
            }

            if (pinfo->instr->mTemplate.ret)
            {
                 for (const instrInfo_t::instrInfoFlag_t* flag : pinfo->Flags())
                 {
                     if (flag->needed)
                     {
                         bool allVisible = true;
                         for (address_t a : flag->lastSet)
                         {
                             shared<instrInfo_t> lastSetInstr = mInfo->code.find(a)->second;
                             allVisible &= lastSetInstr->GetFlag(flag->type).save || lastSetInstr->GetFlag(flag->type).visible;
                         }
                         if (!allVisible)
                         {
                             assert(flag->lastSet.size() == 1);
                             StatementIr st;
                             shared<instrInfo_t> lastSetInstr = mInfo->code.find(*flag->lastSet.begin())->second;
                             if (lastSetInstr->instr->mId == X86_INS_AND && flag->type == 'c')
                             {
                                 st = ASSIGN(OP_VAR("flags.carry"), OP_CONST(0));
                             } else
                                 assert(0);
                             append(p.first, st);
                         }
                     }
                 }
                
                auto stf = convertir[pinstr->mId];
                assert(stf);
                StatementIr st = stf(pinstr, pinfo, info->func);
                append(p.first, st);
            }
            else if ((pinstr->IsIndirectCall() || pinstr->IsIndirectJump()) && mOptions->GetJumpTables(pinstr->mAddress).size())
            {
                append(p.first, DumpIndirectTables(pinstr, info->func));
            }
            else if (convertir[pinstr->mId])
            {
                auto stf = convertir[pinstr->mId];
                assert(stf);
                StatementIr st = stf(pinstr, pinfo, info->func);
                if(st.type == StatementIr::Type_t::Condition)
                    assert(st.stConditionTrue && st.stConditionExpr);
                append(p.first, st);
            }
            else if (pinstr->mTemplate.string)
            {
                append(p.first, String(pinfo, info->func));
            }
            else if (pinstr->mTemplate.conditional)
            {
                StatementIr st = StatementIr{
                    .type = StatementIr::Type_t::Condition,
                    .stConditionTrue = std::make_shared<StatementIr>(StatementIr{.type = StatementIr::Type_t::DirectJump, .target = pinstr->JumpTarget()}),
                    .stConditionExpr = std::make_shared<StatementIr>(MakeCondition(pinfo, info))
                };
                assert(st.stConditionExpr->type != StatementIr::Type_t::None);
                append(p.first, st);
            }
            else
            {
                assert(0);
//                    mCode.push_back(utils::format("    stop(\"disassembly failed at %x:%x %s\");\n",
//                                                  pinstr->mAddress.segment, pinstr->mAddress.offset, pinstr->AsString().c_str()));
            }

            append(p.first, post);
            
            if (!pinfo->stop.empty() && !pinfo->instr->mTemplate.ret /*&& injectstr != "//quiet"*/)
                append(p.first, StatementIr{.type = StatementIr::Type_t::Stop, .stop = pinfo->stop});

            if (pinstr->isTerminating)
                append(p.first, StatementIr{.type = StatementIr::Type_t::Stop, .stop = "terminating"});

            if (pinstr->isReturning)
                append(p.first, StatementIr{.type = StatementIr::Type_t::Return});
            
            next = {p.first.segment, p.first.offset + p.second->instr->mSize};
        }
        return xprocir;
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
    
    StatementIr MakeCondition(shared<instrInfo_t> pinfo, shared<Analyser::info_t> proc)
    {
        if (!pinfo->readPrecondition.empty())
        {
            assert(pinfo->readPrecondition.size() == 1);
            return StatementIr{.type = StatementIr::Type_t::Compare,
                .opin1 = OP_VAR(pinfo->readPrecondition[0]).get()};
        }
        
        bool dirty = false;
        std::set<address_t> lastSet;
        int needFlags = 0;
        std::set<char> needType;
        bool allVisible = false;
        
        for (const instrInfo_t::instrInfoFlag_t* flag : pinfo->Flags())
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
                shared<instrInfo_t> lastSetInstr = proc->code.find(adr)->second;
                if (!lastSetInstr->GetFlag(*needType.begin()).visible &&
                    !lastSetInstr->GetFlag(*needType.begin()).save)
                    allVisible = false;
            }
        }
        
        if (allVisible)
        {
            return Condition(X86_INS_CALL, pinfo->instr->mId);
        }

        if (!dirty)
        {
            shared<instrInfo_t> lastSetInfo;
            assert(lastSet.size() <= 1);
            if (lastSet.size() == 1)
            lastSetInfo = proc->code.find(*lastSet.begin())->second;
            x86_insn condInsn = pinfo->instr->mId;
            
            return Condition(lastSetInfo ? lastSetInfo->instr : nullptr, pinfo->instr);
        }
        assert(0);
        return StatementIr{};
    }
    
    StatementIr Condition(shared<CapInstr> set, shared<CapInstr> get)
    {
        return Condition(set, get->mId);
        
    }
    
    StatementIr Condition(x86_insn setter, x86_insn getter)
    {
        // TODO: duplicity
        if (setter == X86_INS_CALL)
        {
            // Flag-based conditions
            if (getter == X86_INS_JA)
                return !OP_VAR("flags.carry") && !OP_VAR("flags.zero");
            if (getter == X86_INS_JBE)
                return OP_VAR("flags.carry") || OP_VAR("flags.zero");
            if (getter == X86_INS_JNE)
                return !OP_VAR("flags.zero");
            if (getter == X86_INS_JE)
                return COMPARE(OP_VAR("flags.zero"));
            if (getter == X86_INS_JB)
                return COMPARE(OP_VAR("flags.carry"));
            if (getter == X86_INS_JAE)
                return !COMPARE(OP_VAR("flags.carry"));

            assert(0);
        }
        assert(0);
        return {};
    }
    StatementIr PreCondition(shared<CapInstr> set, x86_insn getter)
    {
        auto maxValue = [](shared<CapInstr> set, int op) {
            int w = set->mDetail.operands[op].size;
            switch (w)
            {
                case 1:
                    return 0x100;
                case 2:
                    return 0x10000;
                default:
                    assert(0);
                    return 0;
            }
        };
        x86_insn setter = set->mId;
        // shr, jb
        if ((setter == X86_INS_SHR || setter == X86_INS_ROR) && getter == X86_INS_JB)
        {
            if (set->mDetail.operands[1].type != X86_OP_IMM)
                return COMPARE(OP_VAR("JB_SHR/ROR/CNT???"));
            assert(set->Imm() == 1);
            return OP_X86(set, 0) & OP_CONST(1);
        }
        if ((setter == X86_INS_SHL || setter == X86_INS_ROL) && getter == X86_INS_JB)
        {
            assert(set->Imm() == 1);
            switch (set->mDetail.operands[0].size)
            {
                case 1:
                    return !!COMPARE(OP_X86(set, 0) & OP_CONST(0x80, 1));
                case 2:
                    return !!COMPARE(OP_X86(set, 0) & OP_CONST(0x8000, 2));
                default:
                    assert(0);
            }
        }
        if (setter == X86_INS_SUB && getter == X86_INS_JB)
            return OP_X86(set, 0) < OP_X86(set, 1);
        if (setter == X86_INS_SUB && getter == X86_INS_JG)
            return OP_MOD("signed") << (OP_X86(set, 0) > OP_X86(set, 1));
        if (setter == X86_INS_ADD && getter == X86_INS_JG)
            return (OP_SIGNED(OP_X86(set, 0)) + OP_SIGNED(OP_X86(set, 1))) > OP_CONST(0);
        if (setter == X86_INS_SUB && getter == X86_INS_JLE)
            return OP_MOD("signed") << (OP_X86(set, 0) <= OP_X86(set, 1));
        if (setter == X86_INS_ADD && getter == X86_INS_JB)
            return (OP_X86(set, 0) + OP_X86(set, 1)) >= OP_CONST(maxValue(set, 0), -1);
        if (setter == X86_INS_ADD && getter == X86_INS_JL)
            return OP_MOD("signed") << ((OP_X86(set, 0) + OP_X86(set, 1)) < OP_CONST(0));
        if (setter == X86_INS_ADD && getter == X86_INS_JLE)
            return OP_MOD("signed") << ((OP_X86(set, 0) + OP_X86(set, 1)) <= OP_CONST(0));
        if (setter == X86_INS_SUB && getter == X86_INS_JA)
            return (OP_X86(set, 0) > OP_X86(set, 1));
        if (setter == X86_INS_ADC && getter == X86_INS_JB)
            return (OP_X86(set, 0) + OP_X86(set, 1) + OP_VAR("flags.carry")) >= OP_CONST(maxValue(set, 0), -1);
        if (setter == X86_INS_OR && getter == X86_INS_JB)
            return COMPARE(OP_VAR("false"));
        if (setter == X86_INS_AND && getter == X86_INS_JB)
            return COMPARE(OP_VAR("false"));

        return Condition(set, getter);
    }
    StatementIr Condition(shared<CapInstr> set, x86_insn getter)
    {
        if (!set)
        {
            switch (getter)
            {
                case X86_INS_JCXZ:
                    return OP_REG("cx") == OP_CONST(0);
                default:
                    assert(0);
            }
            assert(0);
        }
        x86_insn setter = set->mId;
        
        if (setter == X86_INS_CALL)
        {
            // Flag-based conditions
            if (getter == X86_INS_JA)
                return !OP_VAR("flags.carry") && !OP_VAR("flags.zero");
            if (getter == X86_INS_JBE)
                return OP_VAR("flags.carry") || OP_VAR("flags.zero");
            
            assert(0);
        }
        
        if (setter == X86_INS_CMP)
        {
            // Binary comparisons on operands
            // Extract actual operands from the CMP instruction
            
            switch (getter)
            {
                case X86_INS_JGE:
                    return OP_MOD("signed") << (OP_X86(set, 0) >= OP_X86(set, 1));
                case X86_INS_JLE:
                    return OP_MOD("signed") << (OP_X86(set, 0) <= OP_X86(set, 1));
                case X86_INS_JG:
                    return OP_MOD("signed") << (OP_X86(set, 0) > OP_X86(set, 1));
                case X86_INS_JL:
                    return OP_MOD("signed") << (OP_X86(set, 0) < OP_X86(set, 1));
                case X86_INS_JA:
                    return OP_X86(set, 0) > OP_X86(set, 1);
                case X86_INS_JB:
                    return OP_X86(set, 0) < OP_X86(set, 1);
                case X86_INS_JBE:
                    return OP_X86(set, 0) <= OP_X86(set, 1);
                case X86_INS_JAE:
                    return OP_X86(set, 0) >= OP_X86(set, 1);
                case X86_INS_JNE:
                    return OP_X86(set, 0) != OP_X86(set, 1);
                case X86_INS_JE:
                    return OP_X86(set, 0) == OP_X86(set, 1);
                case X86_INS_JNS:
                    return OP_MOD("signed") << ((OP_X86(set, 0) >= OP_X86(set, 1)));
//                    if (set->Imm() == 0)
//                        return OP_MOD("signed") << ((OP_X86(set, 0) >= OP_CONST(0)));
//                    else
//                        return OP_MOD("signed") << ((OP_X86(set, 0) - OP_X86(set, 1)) >= OP_CONST(0));
                case X86_INS_JS:
                    return OP_MOD("signed") << ((OP_X86(set, 0) < OP_X86(set, 1)));
//                    if (set->Imm() == 0)
//                        return OP_MOD("signed") << ((OP_X86(set, 0) < OP_CONST(0)));
//                    else
//                        return OP_MOD("signed") << ((OP_X86(set, 0) - OP_X86(set, 1)) < OP_CONST(0));

                default:
                    assert(0);
            }
        }
        
        bool passive = setter == X86_INS_TEST && set->ArgsEqual();
        bool logalu = setter == X86_INS_AND || setter == X86_INS_OR;
        if (passive || logalu)
        {
            switch (getter)
            {
                case X86_INS_JGE:
                    return OP_MOD("signed") << (OP_X86(set, 0) >= OP_CONST(0));
                case X86_INS_JG:
                    return OP_MOD("signed") << (OP_X86(set, 0) > OP_CONST(0));
                case X86_INS_JLE:
                    return OP_MOD("signed") << (OP_X86(set, 0) <= OP_CONST(0));
                case X86_INS_JL:
                    return OP_MOD("signed") << (OP_X86(set, 0) < OP_CONST(0));
                case X86_INS_JE:
                    return OP_X86(set, 0) == OP_CONST(0);
                case X86_INS_JNE:
                    return OP_X86(set, 0) != OP_CONST(0);
                case X86_INS_JS:
                    return OP_MOD("signed") << (OP_X86(set, 0) < OP_CONST(0));
                case X86_INS_JNS:
                    return OP_MOD("signed") << (OP_X86(set, 0) >= OP_CONST(0));
                default:
                    assert(0);
            }
        }
        
        // destructive
        if (setter == X86_INS_DEC || setter == X86_INS_INC ||setter == X86_INS_ADD || setter == X86_INS_SUB || setter == X86_INS_SHR || setter == X86_INS_ADC || setter == X86_INS_ADD || setter == X86_INS_SAR || setter == X86_INS_XOR)
        {
            switch (getter)
            {
                case X86_INS_JS:
                    return OP_MOD("signed") << (OP_X86(set, 0) < OP_CONST(0));
                case X86_INS_JNS:
                    return OP_MOD("signed") << (OP_X86(set, 0) >= OP_CONST(0));
                case X86_INS_JE:
                    return OP_X86(set, 0) == OP_CONST(0);
                case X86_INS_JNE:
                    return OP_X86(set, 0) != OP_CONST(0);
                default:
                    assert(0);
            }
        }
        if (setter == X86_INS_TEST)
        {
            switch (getter)
            {
                case X86_INS_JNE:
                    return OP_X86(set, 0) & OP_X86(set, 1);
                case X86_INS_JE:
                    return !(OP_X86(set, 0) & OP_X86(set, 1));
                case X86_INS_JB:
                    return COMPARE(OP_VAR("JB_TEST_???"));
                case X86_INS_LOOPNE:
                    return OP_BINARY(OP_UNARY("--", OP_VAR("cx")), "&&", OP_X86(set, 0) & OP_X86(set, 1));
                default:
                    assert(0);
            }
        }
        
        assert(0);
        return StatementIr{}; // Return empty statement on error
    }

    StatementIr String(shared<instrInfo_t> instr, const funcInfo_t& func)
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
            if (in == "byte ptr [esi]")
                return "DS_ESI";
            if (in == "byte ptr es:[si]" || in == "word ptr es:[si]")
                return "ES_SI";
            if (in == "byte ptr cs:[si]" || in == "word ptr cs:[si]")
                return "CS_SI";
            if (in == "dword ptr [esi]")
                return "DS_ESI";
            assert(0);
            return "?";
        };
        std::string repeat = "";
        std::string templ = replace(instr->instr->mMnemonic, " ", "_");
        std::vector<std::string> args = split(instr->instr->mOperands, ", ");
        assert(args.size() == 2);
        if (templ.starts_with("rep_"))
        {
            if (func.arch == arch_t::arch16)
                repeat = "for (; cx != 0; --cx)";
            else
                repeat = "for (; ecx != 0; --ecx)";
            templ = templ.substr(4);
        }
        if (templ.starts_with("repne_"))
        {
            if (func.arch == arch_t::arch16)
                repeat = "for (flags.zero = 0; cx != 0 && !flags.zero; --cx)";
            else
                repeat = "for (flags.zero = 0; ecx != 0 && !flags.zero; --ecx)";
            templ = templ.substr(6);
        }
        if (templ.starts_with("repe_"))
        {
            if (func.arch == arch_t::arch16)
                repeat = "for (flags.zero = 1; cx != 0 && flags.zero; --cx)";
            else
                repeat = "for (flags.zero = 1; ecx != 0 && flags.zero; --ecx)";
            templ = templ.substr(5);
        }
//        assert(0);
        if (templ.starts_with("lod"))
        {
            assert(args[0] == "al" || args[0] == "ax" || args[0] == "eax");
            return {.type = StatementIr::Type_t::Function,
                    .repeat = repeat,
                    .func = templ + "<" + argToTemplate(args[1]) + ">",
                    .opd = std::make_shared<OperandIr>(instr->instr->mDetail.operands[0])};
        }
        if (templ.starts_with("mov"))
        {
            return {.type = StatementIr::Type_t::Function,
                    .repeat = repeat,
                    .func = templ + "<" + argToTemplate(args[0]) + ", " + argToTemplate(args[1]) + ">"};

        }
        if (templ.starts_with("sca"))
        {
            if (args[1] == "al" || args[1] == "ax" || args[1] == "eax")
                return {.type = StatementIr::Type_t::Function,
                        .repeat = repeat,
                        .func = templ + "<" + argToTemplate(args[0]) + ">",
                        .opin1 = std::make_shared<OperandIr>(instr->instr->mDetail.operands[1])};
            else if (args[0] == "al" || args[0] == "ax" || args[0] == "eax")
                return {.type = StatementIr::Type_t::Function,
                        .repeat = repeat,
                        .func = templ + "<" + argToTemplate(args[1]) + ">",
                        .opin1 = std::make_shared<OperandIr>(instr->instr->mDetail.operands[0])};
            else
                assert(0);
        }
        assert(args[1] == "al" || args[1] == "ax" || args[1] == "eax");
        
//        if (args[0] == "al" || args[0] == "ax")
//            return repeat + templ + "_inv<" + argToTemplate(args[1]) + ">("+args[0]+");";
//        if (args[1] == "al" || args[1] == "ax" || args[1] == "eax")
//            return repeat + templ + "<" + argToTemplate(args[0]) + ">("+args[1]+");";
//        else
//            return repeat + templ + "<" + argToTemplate(args[0]) + ", " + argToTemplate(args[1]) + ">();";
        return {.type = StatementIr::Type_t::Function,
                .repeat = repeat,
                .func = templ + "<" + argToTemplate(args[0]) + ">",
                .opin1 = std::make_shared<OperandIr>(instr->instr->mDetail.operands[1])};
    }

    StatementIr DumpIndirectTables(shared<CapInstr> instr, funcInfo_t func)
    {
        std::set<int> dupl;
        std::string selector;
        bool first = true;

        std::vector<std::pair<shared<OperandIr>, shared<StatementIr>>> opSwitchCases;

        for (shared<jumpTable_t> jt : mOptions->GetJumpTables(instr->mAddress))
        {
            if (selector.empty())
                selector = jt->selector;
            
            if (selector.empty())
            {
//                if (instr->mId == X86_INS_CALL && instr->mDetail.op_count == 1 && jt->type == jumpTable_t::switch_e::CallWords)
//                    selector = iformat(instr, info, func, "$rd0");
//                else if (instr->mId == X86_INS_CALL && instr->mDetail.op_count == 1 && jt->type == jumpTable_t::switch_e::CallDwords)
//                    selector = iformat(instr, info, func, "cs*0x10000 + $rd0");
//                else if (instr->mId == X86_INS_CALL && instr->mDetail.op_count == 1 && jt->type == jumpTable_t::switch_e::Call32)
//                    selector = iformat(instr, info, func, "$rd0");
//                else if (instr->mId == X86_INS_LCALL && instr->mDetail.op_count == 1)
//                    selector = iformat(instr, info, func, "$rns0*0x10000 + $rm0");
//                else if (instr->mId == X86_INS_JMP && instr->mDetail.op_count == 1)
//                    selector = iformat(instr, info, func, "$rd0");
//                else if (instr->mId == X86_INS_LJMP && instr->mDetail.op_count == 1)
//                    selector = iformat(instr, info, func, "$rns0*0x10000 + $rm0");
//                else
                    assert(0);
            }
            
            // multiple tables must use the same selector
            assert(jt->selector.empty() || selector == jt->selector);
                                
            
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
                    
                    opSwitchCases.push_back({
                        std::make_shared<OperandIr>(OperandIr{OperandIr::Type_t::Const, (int)jt->GetCaseKey(i), 0}),
                        std::make_shared<StatementIr>(StatementIr{.type = StatementIr::Type_t::DirectCall, .address = jt->GetTarget(i)})
                    });
                }
        }
        
        return StatementIr{
            .type = StatementIr::Type_t::Switch,
            .opSwitchSelector = selector,
            .opSwitchCases = opSwitchCases
        };
        
    }
};

