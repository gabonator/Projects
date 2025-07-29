//
//  analyserFunction.h
//  cicodis32
//
//  Created by Gabriel Valky on 16/07/2025.
//

// FunctionAnalyser - traversing single function code and filling in instrInfo structure
class FunctionAnalyser : public ProgramAnalyser {
protected:
    std::map<address_t, int, cmp_adress_t> tempIndexPrecond, tempIndexZf, tempIndexCf, tempIndexSf, tempIndexOf;
    bool verbose{false};

public:
    FunctionAnalyser(Options& options) : ProgramAnalyser(options)
    {
        verbose = mOptions.verbose;
    }

    virtual std::set<address_t, cmp_adress_t> AnalyseInstruction(shared<instrInfo_t> instr, shared<info_t> info) = 0;
    
    virtual void AnalyseProc(address_t proc, procRequest_t req)
    {
        shared<info_t> info = mInfos.find(proc)->second;
        code_t& code = info->code;
        //code_t code = info->code;
        std::vector<std::pair<address_t, address_t>> head({{address_t(), proc}});

        tempIndexPrecond.clear();
        tempIndexZf.clear();
        tempIndexCf.clear();
        tempIndexSf.clear();
        tempIndexOf.clear();

        if (info->func.request != req)
        {
            // second iterat
            for (const auto& [addr, p] : info->code)
                p->processed = false;
        }
        info->func.request = req;
        info->func.callConv = GetCallConvention(code);
        
        if (verbose)
            DumpCode(proc, code, req);

        while (head.size())
        {
            std::vector<std::pair<address_t, address_t>> newHead;

            for (std::pair<address_t, address_t> link : head)
            {
                if (verbose)
                    printf("%x->%x: ", link.first.offset, link.second.offset);
                
                shared<CapInstr> instr = code.find(link.second)->second->instr;

                if (verbose)
                    printf("    instr: %s", instr->AsString().c_str());
                
//                if (link.first.offset == 0x54d && link.second.offset == 0x54f) // 55b ok
                if (link.second.offset == 0x2b9)
                {
                    int f =9;
                }

                shared<instrInfo_t> prevInfo = std::make_shared<instrInfo_t>();
                if (link.first)
                {
                    assert(info->code.find(link.first) != info->code.end());
                    *prevInfo = *info->code.find(link.first)->second;
                } else {
                    prevInfo->stack = 0; // TODO: long call?
                }
                
                shared<instrInfo_t> newInfo = code.find(link.second)->second;

                if (!newInfo->AdvanceAndMerge(prevInfo) && newInfo->processed)
                {
                    if (verbose)
                        printf(" no merge\n");
                    continue;
                }
                
                std::set<address_t, cmp_adress_t> clearInsns = AnalyseInstruction(newInfo, info);
                newInfo->processed = true;

                if (verbose)
                    printf("\n");

                for (address_t clear : clearInsns)
                    for (address_t child : info->code.find(clear)->second->instr->mNext)
                        newHead.push_back(std::pair<address_t, address_t>(clear, child));

                for (address_t next : instr->mNext)
                    newHead.push_back(std::pair<address_t, address_t>(link.second, next));

            }
            head = newHead;
        }

        // TODO: BAD, collect all RET, and merge
        PostProcess(info);
        mInfos.insert(std::pair<address_t, shared<info_t>>(proc, info));
    }
    
    void PostProcess(shared<info_t> info)
    {
        FindInfiniteLoops(info->code);
        bool stackGood = true;
        for (const auto& [a, p] : info->code)
        {
            if (p->stack < 0)
            {
                if (stackGood)
                {
                    p->stop = "stack_below";
                    stackGood = false;
                    continue;
                }
            }
            if (p->stack >= 0)
                stackGood = true;
            if (p->instr->mId == X86_INS_RET || p->instr->mId == X86_INS_RETF)
            {
                if (p->stack != 0)
                    p->stop = "stack_unbalanced";
            }
        }
    }
    
    void FindInfiniteLoops(code_t& code)
    {
        for (const auto& p : code)
        {
            shared<CapInstr> pinstr = p.second->instr;
            if (!pinstr->IsConditionalJump())
                continue;
            if (pinstr->mPrev.size() != 1)
                continue;
            shared<CapInstr> prev = code.find(*pinstr->mPrev.begin())->second->instr;
            if (!prev->isLabel)
                continue;
            if (prev->mId != X86_INS_CMP && prev->mId != X86_INS_TEST)
                continue;
            if (prev->mAddress != pinstr->JumpTarget())
                continue;
            code.find(prev->mAddress)->second->infiniteLoop = true;
        }
    }

    void DumpCode(address_t proc, code_t& code, procRequest_t req)
    {
        printf("    %x %x:%x proc %x", proc.linearOffset(), proc.segment, proc.offset, proc.linearOffset());
        switch (req)
        {
            case procRequest_t::returnNone: printf("\n"); break;
            case procRequest_t::returnCarry: printf(" +carry\n"); break;
            case procRequest_t::returnZero: printf(" +zero\n"); break;
            default:
                assert(0);
        }

        for (const auto& p : code)
        {
            if (p.second->instr->isLabel)
                printf("loc_");
            else
                printf("    ");
            printf("%x %x:%x %s %s\n", p.first.linearOffset(), p.first.segment, p.first.offset, p.second->instr->mMnemonic, p.second->instr->mOperands);
        }
    }

    callConv_t GetCallConvention(const code_t& code)
    {
        int retFar = 0, retNear = 0;
        bool stack = UsesStack(code);
        
        for (const auto& p : code)
        {
            if (p.second->instr->mId == X86_INS_RETF)
                retFar++;
            if (p.second->instr->mId == X86_INS_RET)
                retNear++;
        }
        
        if (retFar > 0)
        {
            assert(retNear == 0);
            return stack ? callConv_t::callConvShiftStackFar : callConv_t::callConvSimpleStackFar;
        }
        if (retNear > 0)
        {
            assert(retFar == 0);
            return stack ? callConv_t::callConvShiftStackNear : callConv_t::callConvSimpleStackNear;
        }
        return callConv_t::callConvUnknown;
    }
    
    bool UsesStack(const code_t& code)
    {
        cs_x86_op regsp = {.type=X86_OP_REG, .reg = X86_REG_SP};
        
        for (const auto& p : code)
        {
            for (int i=0; i<p.second->instr->mDetail.op_count; i++)
                //if (p.second->mDetail.operands[i].access & CS_AC_READ)
                    if (Capstone->Intersects(p.second->instr->mDetail.operands[i], regsp))
                        return true;
        }
        
        return false;
    }

    std::string TempVarFor(std::map<address_t, int, cmp_adress_t>& table, std::string prefix, address_t addr)
    {
        if (table.find(addr) == table.end())
            table.insert(std::pair<address_t, int>(addr, table.size()));

        int index = table.find(addr)->second;
        return index == 0 ? prefix : format("%s%d", prefix.c_str(), index);
    }
    
};


