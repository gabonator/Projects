//
//  analyserInstruction.h
//  cicodis32
//
//  Created by Gabriel Valky on 16/07/2025.
//

// InstructionAnalyser - fill in instrInfo based on x86 instruction
class InstructionAnalyser : public FunctionAnalyser {
public:
    InstructionAnalyser(Options& options) : FunctionAnalyser(options)
    {
    }

    virtual std::set<address_t> AnalyseInstruction(shared<instrInfo_t> info, shared<info_t> info_) override
    {
        code_t& code = info_->code;
        shared<CapInstr> instr = info->instr;

        static const uint64_t readFlagMask[128] =
        {
            ['c'] = X86_EFLAGS_PRIOR_CF | X86_EFLAGS_TEST_CF,
            ['z'] = X86_EFLAGS_PRIOR_ZF | X86_EFLAGS_TEST_ZF,
            ['o'] = X86_EFLAGS_PRIOR_OF | X86_EFLAGS_TEST_OF,
            ['s'] = X86_EFLAGS_PRIOR_SF | X86_EFLAGS_TEST_SF,
        };

        static const uint64_t applyFlagMask[128] =
        {
            ['c'] = X86_EFLAGS_MODIFY_CF | X86_EFLAGS_RESET_CF | X86_EFLAGS_SET_CF,
            ['z'] = X86_EFLAGS_MODIFY_ZF | X86_EFLAGS_RESET_ZF | X86_EFLAGS_SET_ZF,
            ['o'] = X86_EFLAGS_MODIFY_OF | X86_EFLAGS_RESET_OF | X86_EFLAGS_SET_OF,
            ['s'] = X86_EFLAGS_MODIFY_SF | X86_EFLAGS_RESET_SF | X86_EFLAGS_SET_SF,
        };

        std::set<address_t> clear;
        
        for (instrInfo_t::instrInfoFlag_t* flag : info->Flags())
        {
            flag->needed |= instr->mDetail.eflags & readFlagMask[flag->type];
            if (info->instr->mTemplate.ret && info_->func.request != procRequest_t::none)
            {
                if (flag->type == 'c' && ((int)info_->func.request & (int)procRequest_t::returnCarry))
                    flag->needed = true;
                if (flag->type == 'z' && ((int)info_->func.request & (int)procRequest_t::returnZero))
                    flag->needed = true;
            }
            
            NeedsFlag(clear, info_, info, flag);
            
            for (int i=0; i<instr->mDetail.op_count; i++)
                if (instr->mDetail.operands[i].access & CS_AC_WRITE)
                    checkDirtyFlags(code, flag, instr->mDetail.operands[i]);

            applyFlags(instr, applyFlagMask[flag->type], flag);
        }
/*
        if (needsCf + needsZf + needsOf + needsSf > 1 && !(instr->mId == X86_INS_RETF || instr->mId == X86_INS_RET))
        {
            std::map<address_t, x86_insn> dest;
            for (address_t ls : info->GetFlag('c').lastSet)
            {
                shared<instrInfo_t> instrSet = code.find(ls)->second;
                if (instrSet->GetFlag('c').isDestructive)
                    dest.insert(std::pair<address_t, x86_insn>(ls, code.find(ls)->second->instr->mId));
            }
            for (address_t ls : info->GetFlag('z').lastSet)
            {
                shared<instrInfo_t> instrSet = code.find(ls)->second;
                if (instrSet->GetFlag('z').isDestructive)
                    dest.insert(std::pair<address_t, x86_insn>(ls, code.find(ls)->second->instr->mId));
            }
            for (address_t ls : info->GetFlag('o').lastSet)
            {
                shared<instrInfo_t> instrSet = code.find(ls)->second;
                if (instrSet->GetFlag('o').isDestructive)
                    dest.insert(std::pair<address_t, x86_insn>(ls, code.find(ls)->second->instr->mId));
            }
            for (address_t ls : info->GetFlag('s').lastSet)
            {
                shared<instrInfo_t> instrSet = code.find(ls)->second;
                if (instrSet->GetFlag('s').isDestructive)
                    dest.insert(std::pair<address_t, x86_insn>(ls, code.find(ls)->second->instr->mId));
            }
            if (dest.size())
            {
                assert(dest.size() == 1);
                address_t addr = dest.begin()->first;
                x86_insn set = dest.begin()->second;
                x86_insn cond = instr->mId;
                shared<instrInfo_t> destructive = code.find(addr)->second;
                std::string variable = TempVarFor(tempIndexPrecond, "temp_cond", instr->mAddress);
                flagMask_t needs = flagMask_t(
                      (int)(needsCf ? flagMask_t::carry : flagMask_t::none) |
                      (int)(needsZf ? flagMask_t::zero : flagMask_t::none) |
                      (int)(needsOf ? flagMask_t::overflow : flagMask_t::none) |
                      (int)(needsSf ? flagMask_t::sign : flagMask_t::none));
                
                if (destructive->savePrecondition.size() == 0 || destructive->savePrecondition[0].needs != needs || destructive->savePrecondition[0].writeOp != set || destructive->savePrecondition[0].readOp != cond || destructive->savePrecondition[0].variable != variable)
                {
                    assert(destructive->savePrecondition.size() == 0);
                    destructive->savePrecondition.push_back({
                        .needs = needs,
                        .writeOp = set,
                        .readOp = cond,
                        .variable = variable
                    });
                }
                if (info->readPrecondition.size() == 0)
                {
                    //assert(info->readPrecondition.size() == 0);
                    info->readPrecondition.push_back(variable);
                } else {
                    assert(info->readPrecondition.size() == 1);
                    assert(info->readPrecondition[0] == variable);
                }
                
                needsCf = needsZf = needsOf = needsSf = 0;
                // condition covered, do not use simple flow
            }
        }
        */
                
        // TODO: save flag is lost in second pass!!!
        
//        switch (instr->mId)
//        {
//            case X86_INS_STC:
//            case X86_INS_CLC:
//            case X86_INS_CMC:
//                info->GetFlag('c').savedVisibly |= true;
//                break;
//            case X86_INS_SHL:
//            case X86_INS_SHR:
//            case X86_INS_ADD:
//            case X86_INS_ADC:
//            case X86_INS_SUB:
//            case X86_INS_SBB:
//                info->GetFlag('c').isDestructive |= true;
//                info->GetFlag('c').dirty |= true;
//                break;
//            case X86_INS_ROL:
//            case X86_INS_ROR:
//                info->GetFlag('c').isDestructive |= true;
//                info->GetFlag('c').dirty |= true;
//                break;
//            case X86_INS_RCL:
//            case X86_INS_RCR:
//                info->GetFlag('c').usesInternal = true;
//                info->GetFlag('c').savedVisibly = true;
//            default:
//                break;
//        }
        
        return clear;
    }

    void checkDirtyFlags(code_t& code, instrInfo_t::instrInfoFlag_t* flag, cs_x86_op change)
    {
        if (flag->dirty)
            return;
        
        for (address_t addr : flag->lastSet)
        {
            shared<CapInstr> dep = code.find(addr)->second->instr;
            for (int i=0; i<dep->mDetail.op_count; i++)
                if (Capstone->Intersects(dep->mDetail.operands[i], change))
                {
                    flag->dirty = true;
                    return;
                }
        }
    };

    void applyFlags(shared<CapInstr> instr, uint64_t modifyMask, instrInfo_t::instrInfoFlag_t* flag)
    {
        if (instr->mId == X86_INS_INT || instr->mId == X86_INS_CALL || instr->mId == X86_INS_LCALL || (instr->mDetail.eflags & modifyMask))
        {
            if (verbose)
                printf("(set %cf) ", flag->type);
            flag->willSet = {instr->mAddress};
//            flag->isDestructive = false;
        }
    };

    void NeedsFlag(std::set<address_t>& clearChildren, shared<info_t> info, shared<instrInfo_t> newInfo, instrInfo_t::instrInfoFlag_t* flag)
    {
        shared<CapInstr> instr = newInfo->instr;
        
//        std::string defaultFlag;
//        switch (flag.type)
//        {
//            case 'z': defaultFlag = "flags.zero"; break;
//            case 'c': defaultFlag = "flags.carry"; break;
//            case 's': defaultFlag = "flags.sign"; break;
//            case 'o': defaultFlag = "flags.overflow"; break;
//            default:
//                assert(0);
//        }
//
//        std::string defaultPrefix;
//        switch (flag.type)
//        {
//            case 'z': defaultPrefix = "temp_zf"; break;
//            case 'c': defaultPrefix = "temp_cf"; break;
//            case 's': defaultPrefix = "temp_sf"; break;
//            case 'o': defaultPrefix = "temp_of"; break;
//            default:
//                assert(0);
//        }
//
        for (address_t o : flag->lastSet)
        {
            shared<instrInfo_t> oi = info->code.find(o)->second;
            if (flag->needed)
            {
                oi->GetFlag(flag->type).provides.insert(newInfo->instr->mAddress);
                flag->depends.insert(o);
            }
        }
            
//            if (oi->instr->mId == X86_INS_CALL || oi->instr->mId == X86_INS_LCALL)
//            {
//                procRequest_t r = oi->instr->mId == X86_INS_CALL ? procRequest_t::callNear : procRequest_t::callFar;
//                if (flag.needed)
//                {
//                    oi->GetFlag(flag.type).savedVisibly = true;
//                    switch (flag.type)
//                    {
//                        case 'z':
//                            if (oi->instr->IsDirectCall())
//                                r = (procRequest_t)((int)r | (int)procRequest_t::returnZero);
//                            else
//                                newInfo->stop = "callee must return zero";
//                            break;
//                        case 'c':
//                            if (oi->instr->IsDirectCall())
//                                r = (procRequest_t)((int)r | (int)procRequest_t::returnCarry);
//                            else
//                                newInfo->stop = "callee must return carry";
//                            break;
//                        default:
//                            assert(0);
//                    }
//                }
//                AddProcRequest(newInfo, oi->instr->CallTarget(), r);
//        }
//        
//        if (flag.saved)
//        {
//            assert(flag.lastSet.size() < 3);
//            std::set<std::string> variableRead;
//            for (address_t a : flag.lastSet)
//            {
//                shared<instrInfo_t> setflaginfo = info->code.find(a)->second;
//                variableRead.insert(setflaginfo->GetFlag(flag.type).variableWrite);
//            }
//            assert(variableRead.size() == 1);
//            flag.variableRead = *variableRead.begin();
//        }
//        
//        if (flag.lastSet.size() == 1)
//        {
//            if (flag.dirty)
//            {
//                address_t setFlagAddr = *flag.lastSet.begin(); // TODO: ROR bad!
//                shared<instrInfo_t> setFlagInfo = info->code.find(setFlagAddr)->second;
//                if (!setFlagInfo->GetFlag(flag.type).save)
//                {
//                    assert(setFlagInfo->instr->mId != X86_INS_STC);
//
//                    //flag.variableRead = defaultFlag;
//                    flag.variableRead = TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
//                    setFlagInfo->GetFlag(flag.type).variableWrite = flag.variableRead;
//                    setFlagInfo->GetFlag(flag.type).save = true;
//                    clearChildren.insert(setFlagAddr);
//                    return;
//                }
//            }
            
//            address_t ls = *flag.lastSet.begin();
//            shared<instrInfo_t> destructive = info->code.find(ls)->second;
//            if (destructive->GetFlag(flag.type).isDestructive)
//            {
//                if (!destructive->GetFlag(flag.type).save)
//                {
//                    assert(destructive->instr->mId != X86_INS_STC);
//
//                    flag.variableRead = TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
//                    destructive->GetFlag(flag.type).variableWrite = flag.variableRead;
//                    destructive->GetFlag(flag.type).save = true;
//                    clearChildren.insert(ls);
//                    return;
//                }
//            } else {
//                // TODO: more general rules, remove
//                if (newInfo->instr->mId == X86_INS_CALL || newInfo->instr->mId == X86_INS_LCALL)
//                {
//                    flag.variableRead = defaultFlag;
//                }
//                // bumpy 1ed:aa2b proc c8fb +carry +zero
////                if (newInfo->instr->mId == X86_INS_RET)
////                {
////                    if (!destructive->GetFlag(flag.type).save && !destructive->GetFlag(flag.type).savedVisibly)
////                    {
////                        destructive->GetFlag(flag.type).variableWrite = defaultFlag; // gabo-check TODO
////                        destructive->GetFlag(flag.type).save = true;
////                    }
////                }
//                if (newInfo->instr->mId == X86_INS_CMC && destructive->instr->mId == X86_INS_CMP)
//                {
//                    if (!destructive->GetFlag(flag.type).save)
//                    {
//                        flag.variableRead = TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
//                        destructive->GetFlag(flag.type).variableWrite = flag.variableRead;
//                        destructive->GetFlag(flag.type).save = true;
//                    }
//                }
//                if (newInfo->instr->mId == X86_INS_SBB && destructive->instr->mId == X86_INS_NEG)
//                {
//                    if (!destructive->GetFlag(flag.type).save)
//                    {
//                        flag.variableRead = TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
//                        destructive->GetFlag(flag.type).variableWrite = flag.variableRead;
//                        destructive->GetFlag(flag.type).save = true;
//                    }
//                }
//
//                if (newInfo->instr->mId == X86_INS_ADC)
//                {
//                    if (destructive->instr->mId == X86_INS_CMC)
//                    {
//                        flag.variableRead = destructive->GetFlag(flag.type).variableWrite;
//                        if (flag.variableRead.empty())
//                            flag.variableRead = defaultFlag;
//                    }
//                    if (destructive->instr->mId == X86_INS_CMP)
//                    {
//                        if (!destructive->GetFlag(flag.type).save)
//                        {
//                            flag.variableRead = TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
//                            destructive->GetFlag(flag.type).variableWrite = flag.variableRead;
//                            destructive->GetFlag(flag.type).save = true;
//                        }
//                    }
//                }
//                //flag.variableRead = defaultFlag; // TODO: gabo removed! simple condition
//            }
//            return;
//        }
        
//        if (flag->lastSet.size() > 1) // depends?
//        {
//            int savedVisibly = 0, savedInvisibly = 0;
//            for (address_t setFlagAddr : flag.lastSet)
//            {
//                shared<instrInfo_t> setFlagInfo = info->code.find(setFlagAddr)->second;
//                if (setFlagInfo->GetFlag(flag.type).savedVisibly)
//                    savedVisibly++;
//                else
//                    savedInvisibly++;
//            }
//            if (savedVisibly > 0 && savedInvisibly == 0)
//            {
//                flag.variableRead = defaultFlag;
//                return;
//            }
//            bool mixed = (savedVisibly > 0 && savedInvisibly > 0);
//            if (mixed)
//            {
//                int f=9;
//            }
//            std::string variable = mixed ? defaultFlag : TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
//            flag.variableRead = variable;
//            
//            for (address_t setFlagAddr : flag.lastSet)
//            {
//                shared<instrInfo_t> setFlagInfo = info->code.find(setFlagAddr)->second;
//                if (setFlagInfo->GetFlag(flag.type).savedVisibly)
//                {
//                    assert(setFlagInfo->GetFlag(flag.type).variableWrite.empty());
//                } else
//                if (!setFlagInfo->GetFlag(flag.type).save)
//                {
//                    setFlagInfo->GetFlag(flag.type).variableWrite = flag.variableRead;
//                    setFlagInfo->GetFlag(flag.type).save = true;
//                    clearChildren.insert(setFlagAddr);
//                } else {
//                    if (setFlagInfo->GetFlag(flag.type).variableWrite != flag.variableRead)
//                        setFlagInfo->GetFlag(flag.type).variableWrite += " / problem9 / " + flag.variableRead;
////                    assert(setFlagInfo->GetFlag(flag.type).variableWrite == flag.variableRead);
//                }
//            }
//            return;
//        }
//        assert(0);
    }
    
};

typedef InstructionAnalyser Analyser;
