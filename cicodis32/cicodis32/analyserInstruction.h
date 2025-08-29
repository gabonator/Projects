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

        if (info->instr->mAddress == address_t{0x2da3, 0xc5c})
        {
            int f = 9;
        }
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
            
            if (flag->type == 'c' && instr->mTemplate.destructiveCarry)
                flag->willSetDirty = true;
            if (flag->type == 'o' && instr->mTemplate.destructiveCarry) // TODO!!
                flag->willSetDirty = true;
            if (flag->type == 'c' && instr->mTemplate.savedVisiblyCarry)
                flag->visible = true;
            if (flag->type == 's' && instr->mTemplate.savedVisiblyCarry) // TODO
                flag->visible = true;
        }
    };

    void NeedsFlag(std::set<address_t>& clearChildren, shared<info_t> info, shared<instrInfo_t> newInfo, instrInfo_t::instrInfoFlag_t* flag)
    {
        shared<CapInstr> instr = newInfo->instr;
        for (address_t o : flag->lastSet)
        {
            shared<instrInfo_t> oi = info->code.find(o)->second;
            if (flag->needed)
            {
                oi->GetFlag(flag->type).provides.insert(newInfo->instr->mAddress);
                flag->depends.insert(o);
            }
        }
    }
};

typedef InstructionAnalyser Analyser;
