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

    virtual std::set<address_t, cmp_adress_t> AnalyseInstruction(shared<instrInfo_t> info, shared<info_t> info_) override
    {
        code_t& code = info_->code;
        shared<CapInstr> instr = info->instr;
        
        std::set<x86_reg> reads = instr->ReadsRegisters();
        std::set<x86_reg> writes = instr->WritesRegisters();
        bool forceSave = false;
        bool needsCf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_CF | X86_EFLAGS_TEST_CF);
        bool needsZf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_ZF | X86_EFLAGS_TEST_ZF);
        bool needsOf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_OF | X86_EFLAGS_TEST_OF);
        bool needsSf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_SF | X86_EFLAGS_TEST_SF);
        
        info->GetFlag('c').needed |= needsCf;
        info->GetFlag('z').needed |= needsZf;
        info->GetFlag('o').needed |= needsOf;
        info->GetFlag('s').needed |= needsSf;
        
        // RET
        if (instr->mId == X86_INS_RETF || instr->mId == X86_INS_RET)
        {
            switch (info_->func.request)
            {
                case procRequest_t::returnNone:
                    break;
                case procRequest_t::returnZero:
                    forceSave = true;
                    needsZf = true;
                    break;
                case procRequest_t::returnCarry:
                    forceSave = true;
                    needsCf = true;
                    break;
            }
        }
        
        if (needsCf + needsZf + needsOf + needsSf > 1)
        {
            std::map<address_t, x86_insn, cmp_adress_t> dest;
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
//                    assert(0); // check dupl
                    destructive->savePrecondition.push_back({
                        .needs = needs,
                        .writeOp = set,
                        .readOp = cond,
                        .variable = variable
                    });
                }
                assert(info->readPrecondition.size() == 0);
                info->readPrecondition.push_back(variable);
                
                needsCf = needsZf = needsOf = needsSf = 0;
                // condition covered, do not use simple flow
            }
        }
        
        std::set<address_t, cmp_adress_t> clear;
        if (needsCf)
        {
            NeedsFlag(clear, info_, info, info->GetFlag('c'), tempIndexCf, forceSave);
            if (verbose)
                printf("(cf=%s) ", info->GetFlag('c').variableRead.c_str());
        }
        if (needsZf)
        {
            NeedsFlag(clear, info_, info, info->GetFlag('z'), tempIndexZf, forceSave);
            if (verbose)
                printf("(zf=%s) ", info->GetFlag('z').variableRead.c_str());
        }
        if (needsSf)
            NeedsFlag(clear, info_, info, info->GetFlag('s'), tempIndexSf, forceSave);
        if (needsOf)
            NeedsFlag(clear, info_, info, info->GetFlag('o'), tempIndexOf, forceSave);
        
        for (int i=0; i<instr->mDetail.op_count; i++)
        {
            if (instr->mDetail.operands[i].access & CS_AC_WRITE)
            {
                checkDirtyFlags(code, info->GetFlag('c'), instr->mDetail.operands[i]);
                checkDirtyFlags(code, info->GetFlag('z'), instr->mDetail.operands[i]);
                checkDirtyFlags(code, info->GetFlag('o'), instr->mDetail.operands[i]);
                checkDirtyFlags(code, info->GetFlag('s'), instr->mDetail.operands[i]);
            }
        }
                
        // TODO: save flag is lost in second pass!!!
        applyFlags(instr, 'c', X86_EFLAGS_MODIFY_CF, X86_EFLAGS_RESET_CF | X86_EFLAGS_SET_CF, info->GetFlag('c'));
        applyFlags(instr, 'z', X86_EFLAGS_MODIFY_ZF, X86_EFLAGS_RESET_ZF | X86_EFLAGS_SET_ZF, info->GetFlag('z'));
        applyFlags(instr, 'o', X86_EFLAGS_MODIFY_OF, X86_EFLAGS_RESET_OF | X86_EFLAGS_SET_OF, info->GetFlag('o'));
        applyFlags(instr, 's', X86_EFLAGS_MODIFY_SF, X86_EFLAGS_RESET_SF | X86_EFLAGS_SET_SF, info->GetFlag('s'));
        
        switch (instr->mId)
        {
            case X86_INS_STC:
            case X86_INS_CLC:
            case X86_INS_CMC:
                info->GetFlag('c').savedVisibly |= true;
                break;
            case X86_INS_SHL:
            case X86_INS_SHR:
            case X86_INS_ADD:
            case X86_INS_ADC:
            case X86_INS_SUB:
            case X86_INS_SBB:
                info->GetFlag('c').isDestructive |= true;
                info->GetFlag('c').dirty |= true;
                break;
            default:
                break;
        }
        
        if (verbose)
            printf("\n");
        
        
        return clear;
    }

    void checkDirtyFlags(code_t& code, instrInfo_t::instrInfoFlag_t& flag, cs_x86_op change)
    {
        if (flag.dirty)
            return;
        
        for (address_t addr : flag.lastSet)
        {
            shared<CapInstr> dep = code.find(addr)->second->instr;
            for (int i=0; i<dep->mDetail.op_count; i++)
                if (Capstone->Intersects(dep->mDetail.operands[i], change))
                {
                    flag.dirty = true;
                    return;
                }
        }
    };

    void applyFlags(shared<CapInstr> instr, char type, uint64_t modifyMask, uint64_t setMask, instrInfo_t::instrInfoFlag_t& flag)
    {
        // TODO: Temp workaround, CALL sets all flags!
        // TODO: interrupt could also update some flags
        if (instr->mId == X86_INS_INT || instr->mId == X86_INS_CALL || (instr->mDetail.eflags & (modifyMask | setMask)))
        {
            if (verbose)
                printf("(set %cf) ", type);
            
//            flag.type = type;
            flag.willSet = {instr->mAddress}; // gabo!
            
//            flag.dirty = false;
            
            flag.isDestructive = false;
//            flag.saved = false;
        }
    };

    void NeedsFlag(std::set<address_t, cmp_adress_t>& clearChildren, shared<info_t> info, shared<instrInfo_t> newInfo, instrInfo_t::instrInfoFlag_t& flag, std::map<address_t, int, cmp_adress_t>& tempIndex, bool forceSave)
    {
        shared<CapInstr> instr = newInfo->instr;
        
        std::string defaultFlag;
        switch (flag.type)
        {
            case 'z': defaultFlag = "flags.zero"; break;
            case 'c': defaultFlag = "flags.carry"; break;
            case 's': defaultFlag = "flags.sign"; break;
            case 'o': defaultFlag = "flags.overflow"; break;
            default:
                assert(0);
        }

        std::string defaultPrefix;
        switch (flag.type)
        {
            case 'z': defaultPrefix = "temp_zf"; break;
            case 'c': defaultPrefix = "temp_cf"; break;
            case 's': defaultPrefix = "temp_sf"; break;
            case 'o': defaultPrefix = "temp_of"; break;
            default:
                assert(0);
        }

        for (address_t o : flag.lastSet)
        {
            shared<CapInstr> oi = info->code.find(o)->second->instr;
            if (oi->mId == X86_INS_CALL)
            {
                switch (flag.type)
                {
                    case 'z':
                        if (oi->IsDirectCall())
                            AddProcRequest(newInfo, oi->CallTarget(), procRequest_t::returnZero);
                        else
                            newInfo->stop = "callee must return zero";
                        break;
                    case 'c':
                        if (oi->IsDirectCall())
                            AddProcRequest(newInfo, oi->CallTarget(), procRequest_t::returnCarry);
                        else
                            newInfo->stop = "callee must return carry";
                        break;
                    default:
                        assert(0);
                }

            }
        }
        
        if (flag.saved)
        {
            assert(flag.lastSet.size() < 3);
            if (flag.lastSet.size() >= 2)
            {
                int f = 9;
            }
            std::set<std::string> variableRead;
            for (address_t a : flag.lastSet)
            {
                shared<instrInfo_t> setflaginfo = info->code.find(a)->second;
                variableRead.insert(setflaginfo->GetFlag(flag.type).variableWrite);
            }
            assert(variableRead.size() == 1);
            flag.variableRead = *variableRead.begin();
        }
        
        if (flag.lastSet.size() == 1)
        {
            if (flag.dirty)
            {
                address_t setFlagAddr = *flag.lastSet.begin();
                shared<instrInfo_t> setFlagInfo = info->code.find(setFlagAddr)->second;
                if (!setFlagInfo->GetFlag(flag.type).save)
                {
                    assert(setFlagInfo->instr->mId != X86_INS_STC);

                    flag.variableRead = defaultFlag;
                    setFlagInfo->GetFlag(flag.type).variableWrite = flag.variableRead;
                    setFlagInfo->GetFlag(flag.type).save = true;
                    clearChildren.insert(setFlagAddr);
                    return;
                }
            }
            
            address_t ls = *flag.lastSet.begin();
            shared<instrInfo_t> destructive = info->code.find(ls)->second;
            if (destructive->GetFlag(flag.type).isDestructive)
            {
                if (!destructive->GetFlag(flag.type).save)
                {
                    assert(destructive->instr->mId != X86_INS_STC);

                    flag.variableRead = TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
                    destructive->GetFlag(flag.type).variableWrite = flag.variableRead;
                    destructive->GetFlag(flag.type).save = true;
                    clearChildren.insert(ls);
                    return;
                }
            } else if (forceSave)
            {
                if (!destructive->GetFlag(flag.type).savedVisibly)
                {
                    assert(destructive->instr->mId != X86_INS_STC);
                    flag.variableRead = defaultFlag;
                    destructive->GetFlag(flag.type).variableWrite = defaultFlag;
                    destructive->GetFlag(flag.type).save = true;
                } else {
                    flag.variableRead = defaultFlag;
                }
            } else {
                //flag.variableRead = defaultFlag; // TODO: gabo removed! simple condition
            }
            //assert(!flag.variableRead.empty()); // TODO: simple cmp condition without
            return;
        }
        
        if (flag.lastSet.size() > 1)
        {
            // not always through temp; CLC (flags.zero) -> ret, AND (can use flags.zero) -> ret
            // rick2 sub_16222
            if (forceSave)
            {
                // try saving as default
                for (address_t setFlagAddr : flag.lastSet)
                {
                    shared<instrInfo_t> setFlagInfo = info->code.find(setFlagAddr)->second;
                    if (setFlagInfo->GetFlag(flag.type).savedVisibly)
                    {
                        // nothing needs to be done
                    }
                    else if (setFlagInfo->GetFlag(flag.type).save)
                    {
                        assert(setFlagInfo->GetFlag(flag.type).variableWrite == defaultFlag);
                    } else
                    {
                        assert(setFlagInfo->instr->mId != X86_INS_STC);

                        setFlagInfo->GetFlag(flag.type).variableWrite = defaultFlag;
                        setFlagInfo->GetFlag(flag.type).save = true;
                        clearChildren.insert(setFlagAddr);
                    }
                }
                return;
            }
            /*
            assert(0);
            bool simpleSave = true;
            
            for (address_t setFlagAddr : flag.lastSet)
            {
                switch (flag.type)
                {
                    case 'c':
                    {
                        static const bool simpleSaveInsns[X86_INS_ENDING] = {
                            [X86_INS_STC] = true,
                            [X86_INS_CLC] = true,
                            [X86_INS_AND] = true,
                            [X86_INS_OR] = true
                        };
                        simpleSave &= simpleSaveInsns[info->code.find(setFlagAddr)->second->instr->mId];
                    }
                    default:
                        assert(0);
                }
            }
            
            if (simpleSave)
            {
                for (address_t setFlagAddr : flag.lastSet)
                {
                    shared<instrInfo_t> setFlagInfo = info->code.find(setFlagAddr)->second;
                    if (!setFlagInfo->GetFlag(flag.type).save)
                    {
                        setFlagInfo->GetFlag(flag.type).variableWrite = flag.variableRead;
                        setFlagInfo->GetFlag(flag.type).save = true;
                        clearChildren.insert(setFlagAddr);
                    }
                }
                return;
            }
            if (!simpleSave)
            {
                assert(0);
            }
             */
            std::string variable = TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
            flag.variableRead = variable;
            
            for (address_t setFlagAddr : flag.lastSet)
            {
                shared<instrInfo_t> setFlagInfo = info->code.find(setFlagAddr)->second;
                if (!setFlagInfo->GetFlag(flag.type).save)
                {
                    setFlagInfo->GetFlag(flag.type).variableWrite = flag.variableRead;
                    setFlagInfo->GetFlag(flag.type).save = true;
                    clearChildren.insert(setFlagAddr);
                }
            }
            return;
        }
        assert(0);
    }
    
};

typedef InstructionAnalyser Analyser;
