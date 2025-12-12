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
                    .opd = std::make_shared<OperandIr>(OperandIr::Type_t::Register, "sp"),
                    .opin1 = std::make_shared<OperandIr>(OperandIr::Type_t::Register, "sp"),
                    .oper = "-",
                    .opin2 = std::make_shared<OperandIr>(OperandIr::Type_t::Const, 2)
            };
            StatementIr shiftEsp{.type = StatementIr::Type_t::Binary,
                    .opd = std::make_shared<OperandIr>(OperandIr::Type_t::Register, "esp"),
                    .opin1 = std::make_shared<OperandIr>(OperandIr::Type_t::Register, "esp"),
                    .oper = "-",
                    .opin2 = std::make_shared<OperandIr>(OperandIr::Type_t::Const, 4)
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
            procir->lines.push_back(StatementIr{.type = StatementIr::Type_t::DirectJump,
                .addr = proc});
        }

        //
        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                procir->lines.push_back(StatementIr{.type = StatementIr::Type_t::Comment,
                    .comment = format("gap %d bytes", p.first.offset - next.offset)});
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
                        .addr = pinstr->mAddress,
                        .comment = pinstr->mAddress.toString()});
                else
                    procir->lines.push_back(StatementIr{.type = StatementIr::Type_t::Label,
                        .addr = pinstr->mAddress});
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
                    assert(flag->depends.empty());
                    StatementIr st{.type = StatementIr::Type_t::Assignment,
                            .opd = std::make_shared<OperandIr>(OperandIr::Type_t::Variable, flagName[flag->type]),
                            .stmt1 = std::make_shared<StatementIr>(PreCondition(pinfo->instr, flagCond[flag->type]))
                    };
                    
                    if (st)
                    {
//                        PrintIr::Print(st);
                        procir->lines.push_back(st);
                    }
                }
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
                 for (const instrInfo_t::instrInfoFlag_t* flag : pinfo->Flags())
                 {
                     if (flag->needed)
                     {
                         assert(0);
//                         std::string flagvalue = BuildConditionFor(pinfo->instr, pinfo, info->func, flag);
//                         if (!flagvalue.empty())
//                             mCode.push_back("    " + flagvalue + ";\n");
                     }
                 }
                
                auto stf = convert[pinstr->mId].convertir;
                assert(stf);
                StatementIr st = stf(pinstr, pinfo, info->func);
                if (st)
                    procir->lines.push_back(st);
                //procir->lines.push_back(StatementIr{.type = StatementIr::Type_t::Return});
            }
            else if ((pinstr->IsIndirectCall() || pinstr->IsIndirectJump()) && mOptions->GetJumpTables(pinstr->mAddress).size())
            {
                StatementIr st = DumpIndirectTables(pinstr, info->func);
                procir->lines.push_back(st);
            }
            else if (convert[pinstr->mId].convertir)
            {
                auto stf = convert[pinstr->mId].convertir;
                assert(stf);
                StatementIr st = stf(pinstr, pinfo, info->func);
                if(st.type == StatementIr::Type_t::Condition)
                    assert(st.stConditionTrue && st.stConditionExpr);

                if (st)
                {
//                    PrintIr::Print(st);
                    procir->lines.push_back(st);
                }
                
//                std::string command = iformat(pinstr, pinfo, info->func, convert[pinstr->mId].convert(pinstr, pinfo, info->func));
//
//                if (command.size())
//                    mCode.push_back("    " + command + "\n");
//
            }
            else if (pinstr->mTemplate.string)
            {
                StatementIr st = String(pinfo, info->func);
                if (st)
                {
//                    PrintIr::Print(st);
                    procir->lines.push_back(st);
                }
            }
            else if (pinstr->mTemplate.conditional)
            {
                StatementIr st;
//                if (pinstr->mId == X86_INS_LOOP)
//                {
//                    // Create: if (--cx) goto target
//                    auto cx = OP_REG("cx");
//                    st = StatementIr{
//                        .type = StatementIr::Type_t::Condition,
//                        .stConditionExpr = COMPARE(--cx).get(),
//                        .stConditionTrue = std::make_shared<StatementIr>(StatementIr{
//                            .type = StatementIr::Type_t::DirectJump,
//                            .opin1 = std::make_shared<OperandIr>(pinstr->mDetail.operands[0])
//                        })
//                    };
//                } else {
                st = StatementIr{
                    .type = StatementIr::Type_t::Condition,
                    .stConditionTrue = std::make_shared<StatementIr>(StatementIr{.type = StatementIr::Type_t::DirectJump, .addr = pinstr->JumpTarget()}),
                    .stConditionExpr = std::make_shared<StatementIr>(MakeCondition(pinfo, info))
                };
//                }
                assert(st.stConditionExpr->type != StatementIr::Type_t::None);
                if (st)
                {
//                    PrintIr::Print(st);
                    procir->lines.push_back(st);
                }

            }
            else
            {
                assert(0);
//                    mCode.push_back(utils::format("    stop(\"disassembly failed at %x:%x %s\");\n",
//                                                  pinstr->mAddress.segment, pinstr->mAddress.offset, pinstr->AsString().c_str()));

            }


            if (!pinfo->stop.empty() && !pinfo->instr->mTemplate.ret /*&& injectstr != "//quiet"*/)
                assert(0);
            if (pinstr->isTerminating)
                procir->lines.push_back(StatementIr{.type = StatementIr::Type_t::Stop, .stop = "terminating"});

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
    
    StatementIr MakeCondition(shared<instrInfo_t> pinfo, shared<Analyser::info_t> proc)
    {
        assert(pinfo->readPrecondition.empty());

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
//            assert(lastSet.size() == 1);
//            shared<instrInfo_t> lastSetInfo = proc->code.find(*lastSet.begin())->second;
/*
 loc_1054a: // 1000:054a
     al = lodsb<DS_SI>();
     if (al == 0x00)
         goto loc_10557;
     ah = 0x01;
     flags.zero = si == memoryAGet16(ds, 0x8f0b);   <<<<<<
     if (!flags.zero)
         goto loc_1055f;

 */
// cmp si, wordptr [123]
            // jne
            //
            convert_t cond = convert[pinfo->instr->mId];
            std::string flagCondition = cond.flagCondition;
            if (flagCondition.empty() && cond.conditionAs != X86_INS_INVALID)
                flagCondition = convert[cond.conditionAs].flagCondition;

//            char needFlag = *needType.begin();
//
//            std::string value;
//            switch (needFlag)
//            {
//                case 'c': value = "flags.carry"; break;
//                case 'z': value = "flags.zero"; break;
//                case 's': value = "flags.sign"; break;
//                default:
//                    assert(0);
//            }
//
            return Condition(X86_INS_CALL, pinfo->instr->mId);
//            return StatementIr{
//                .type = StatementIr::Type_t::Condition,
//                .stConditionTrue = std::make_shared<StatementIr>(StatementIr{.type = StatementIr::Type_t::DirectJump, .addr = pinfo->instr->JumpTarget()}),
//                .stConditionExpr = std::make_shared<StatementIr>(Condition(X86_INS_CALL, pinfo->instr->mId))
//            };

            
//            StatementIr st{.type = StatementIr::Type_t::Assignment,
//                    .opd = std::make_shared<OperandIr>(OperandIr::Type_t::Variable, flagName[flag->type]),
//                    .stmt1 = std::make_shared<StatementIr>(Condition(pinfo->instr, flagCond[flag->type]))
//            };

            assert(0);
//
//            if (flagCondition[0] == '$' && flagCondition[1] == needFlag)
//                return iformat(instr, info, func, value);
//            else if (flagCondition[0] == '!' && flagCondition[1] == '$' && flagCondition[2] == needFlag)
//                return iformat(instr, info, func, InvertCondition(value));
//            else if (flagCondition == "$ret")
//                return iformat(instr, info, func, value);
            assert(0);
        }

        if (!dirty)
        {
            /*
             loc_137db: // 1000:37db
                 sub_13801();
                 cx = memoryAGet16(ss, bp - 4);
                 if (cx==0)
                     goto loc_137d5;

             */
            
            shared<instrInfo_t> lastSetInfo;
            assert(lastSet.size() <= 1);
            if (lastSet.size() == 1)
            lastSetInfo = proc->code.find(*lastSet.begin())->second;
            x86_insn condInsn = pinfo->instr->mId;
            
            convert_t cond = convert[condInsn];
            assert(cond.conditionAs == X86_INS_INVALID);
//            if (cond.conditionAs != X86_INS_INVALID)
//                condInsn = cond.conditionAs;
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
        x86_insn setter = set->mId;
        // shr, jb
        if (setter == X86_INS_SHR && getter == X86_INS_JB)
        {
            assert(set->Imm() == 1);
            return OP_X86(set, 0) & OP_CONST(1);
        }
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
                default:
                    assert(0);
            }
        }
        
        // destructive
        if (setter == X86_INS_DEC || setter == X86_INS_INC ||setter == X86_INS_ADD || setter == X86_INS_SUB  || setter == X86_INS_SHR)
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
                        std::make_shared<StatementIr>(StatementIr{.type = StatementIr::Type_t::DirectCall, .addr = jt->GetTarget(i)})
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

