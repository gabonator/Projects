//
//  analyserFunction.h
//  cicodis32
//
//  Created by Gabriel Valky on 16/07/2025.
//

// FunctionAnalyser - traversing single function code and filling in instrInfo structure
class FunctionAnalyser : public ProgramAnalyser {
protected:
    std::map<address_t, int> tempIndexPrecond, tempIndexZf, tempIndexCf, tempIndexSf, tempIndexOf;
    bool verbose{false};

public:
    FunctionAnalyser(Options& options) : ProgramAnalyser(options)
    {
        verbose = mOptions.verbose;
    }

    virtual std::set<address_t> AnalyseInstruction(shared<instrInfo_t> instr, shared<info_t> info) = 0;
    
    virtual void AnalyseProc(address_t proc, procRequest_t req, int stackDrop)
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

        for (const auto& [addr, p] : info->code)
            GetStackChange(p, info->code);

        if (info->func.request != req)
        {
            // second iteration
            for (const auto& [addr, p] : info->code)
                p->processed = false;
        }
        info->func.request = req;
        info->func.callConv = GetCallConvention(info);
        info->func.stackDrop = stackDrop;
        
        if (verbose)
            DumpCode(proc, code, req, stackDrop);

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
                
                std::set<address_t> clearInsns = AnalyseInstruction(newInfo, info);
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
        // static stack check
        for (const auto& [a, p] : info->code)
        {
            if (p->stack < 0)
            {
                if (stackGood)
                {
                    if (p->instr->mId == X86_INS_RET)
                    {
                        if (info->func.stackDrop != -p->stack)
                            p->stop = utils::format("stack_below, %d/%d", info->func.stackDrop, -p->stack);
                            //p->stop = "stack_below_ret";
                    } else
                    if (p->instr->mId == X86_INS_RETF)
                    {
                        if (info->func.stackDrop != -p->stack+2) // CHECK!!
                            p->stop = utils::format("stack_below_retf, %d/%d", info->func.stackDrop, -p->stack);
                    } else
                    if (p->instr->mId != X86_INS_RET && p->instr->mId != X86_INS_RETF /*|| !((int)info->func.stackDrop)*/)
                    {
                        p->stop = "stack_below";
                    }
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
        
        // marks
        for (const auto& [a, p] : info->code)
        {
            //0x2c187, 0x2aa3, 0x1757, 0x2aa3, 0x17e5, 
            int begin = p->instr->mAddress.linearOffset();
            int end = p->instr->mAddress.linearOffset() + p->instr->mSize;
            for (address_t addr : mOptions.marks)
                if (addr.linearOffset() >= begin && addr.linearOffset() <= end)
                    p->stop += utils::format("mark %04x:%04x, addr %04x:%04x, instr: %s %s, bytes: %s",
                                             addr.segment, addr.offset, p->instr->mAddress.segment, p->instr->mAddress.offset,
                                                 p->instr->mMnemonic,
                                             p->instr->mOperands,
                                             p->instr->GetBytes().c_str());
        }

        // propagate call requests
        for (const auto& [a, p] : info->code)
        {
            if (p->instr->mId == X86_INS_CALL || p->instr->mId == X86_INS_LCALL)
            {
                procRequest_t r = p->instr->mId == X86_INS_CALL ? procRequest_t::callNear : procRequest_t::callFar;
                
                for (instrInfo_t::instrInfoFlag_t* flag : p->Flags())
                {
                    if (!flag->provides.empty())
                    {
                        switch (flag->type)
                        {
                            case 'z':
                                if (p->instr->IsDirectCall())
                                    r = (procRequest_t)((int)r | (int)procRequest_t::returnZero);
                                else
                                    p->stop = "callee must return zero";
                                break;
                            case 'c':
                                if (p->instr->IsDirectCall())
                                    r = (procRequest_t)((int)r | (int)procRequest_t::returnCarry);
                                else
                                    p->stop = "callee must return carry";
                                break;
                            case 's':
                                p->stop = "propagate sign flag";
                                break;
                            default:
                                assert(0);
                        }
                    }
                }
                if (p->instr->IsDirectCall())
                    AddProcRequest(p, p->instr->CallTarget(), r);
            }
        }

        int tempCounter = 0;
        for (const auto& [a, p] : info->code)
        {
            // save full cond
            int needed = 0;
            bool anyDirty = false;
            std::set<address_t> deps;
            // check origin address of all flag sources/ mixed source??
            for (instrInfo_t::instrInfoFlag_t* flag : p->Flags())
            {
                if (flag->needed)
                {
                    needed++;
                    deps.insert(flag->depends.begin(), flag->depends.end());
                }
                if (flag->needed && flag->dirty)
                    anyDirty = true;
            }
            if (anyDirty && needed > 1 && deps.size() == 1)
            {
                assert(deps.size() == 1);
                shared<instrInfo_t> destructive = info->code.find(*deps.begin())->second;
                // save whole condition if couldnt be reconstructed by saving single flag
                //assert(destructive->savePrecondition.size() == 0); // check ck1:loc_283c
                destructive->savePrecondition.push_back({
                    .writeOp = destructive->instr->mId,
                    .readOp = p->instr->mId,
                    .variable = utils::format("temp_cond%d", tempCounter)
                });
                assert(p->readPrecondition.size() == 0);
                p->readPrecondition.push_back(utils::format("temp_cond%d", tempCounter));
                tempCounter++;
            }
        }

        // save single flag
        for (const auto& [a, p] : info->code)
        {
            for (instrInfo_t::instrInfoFlag_t* flag : p->Flags())
            {
                if (p->readPrecondition.size())
                {
                    assert(flag->depends.size() <= 1);
                    continue;
                }
                
                if (flag->depends.empty())
                    continue;
                
                if (flag->dirty || flag->depends.size() > 1 || p->instr->mTemplate.ret)
                {
                    // cannot calculate this flag value from input operands of lastSet
                    for (address_t depAddr : flag->depends)
                    {
                        shared<instrInfo_t> dep = info->code.find(depAddr)->second;
                        
                        if (dep->instr->mId == X86_INS_CALL)
                            continue;
                        if (flag->type == 'c' && dep->instr->mTemplate.savedVisiblyCarry)
                            continue;
                        if (flag->type == 'z' && dep->instr->mId == X86_INS_SCASB)
                            continue;
                        if (flag->type == 'z' && dep->instr->mId == X86_INS_CMPSB) // TODO: tables
                            continue;
                        if (flag->type == 'c' && dep->instr->mId == X86_INS_INT)
                            continue;
                        if (dep->instr->mId == X86_INS_POPF)
                            continue;

                        dep->GetFlag(flag->type).save = true;
                    }
                }
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

    void DumpCode(address_t proc, code_t& code, procRequest_t req, int stackDrop)
    {
        printf("    %x %x:%x proc %x", proc.linearOffset(), proc.segment, proc.offset, proc.linearOffset());
        if ((int)req & (int)procRequest_t::returnCarry)
            printf(" +carry");
        if ((int)req & (int)procRequest_t::returnZero)
            printf(" +zero");
        if (stackDrop != 0)
            printf(" +stackDrop%d", stackDrop);
        printf("\n");

        for (const auto& p : code)
        {
            if (p.second->instr->isLabel)
                printf("loc_");
            else
                printf("    ");
            printf("%x %x:%x %s %s\n", p.first.linearOffset(), p.first.segment, p.first.offset, p.second->instr->mMnemonic, p.second->instr->mOperands);
        }
    }

    callConv_t GetCallConvention(shared<info_t> info) // TODO: should be merged with procrequest?
    {
        bool stack = UsesReg(info->code, X86_REG_SP) || UsesReg(info->code, X86_REG_ESP);
        if (info->func.simpleStack)
            stack |= UsesReg(info->code, X86_REG_BP);
        procRequest_t req = mOptions.procModifiers.find(info->proc)->second;
        // TODO: nearfar!?
        if (((int)req & (int)procRequest_t::callNear) && ((int)req & (int)procRequest_t::callFar))
        {
            printf("// Problem: %04x:%04x sub_%x - near&far&uses stack!\n", info->proc.segment, info->proc.offset,
                   info->proc.linearOffset());
//            assert(!stack);
            return callConv_t::callConvShiftStackNearFar;
        }
        if ((int)req & (int)procRequest_t::callFar)
        {
            if (stack)
            {
                if (info->func.simpleStack)
                    return callConv_t::callConvSimpleStackFar;
                return callConv_t::callConvShiftStackFar;
            }
            return callConv_t::callConvFar;
        }
        else if ((int)req & (int)procRequest_t::callNear)
        {
            if (stack)
            {
                if (info->func.simpleStack)
                    return callConv_t::callConvSimpleStackNear;
                return callConv_t::callConvShiftStackNear;
            }
            return callConv_t::callConvNear;
        }
        else
        {
            assert(0);
            return callConv_t::callConvUnknown;
        }
    }
    
    bool UsesReg(const code_t& code, x86_reg reg)
    {
        cs_x86_op regsp = {.type=X86_OP_REG, .reg = reg};
        
        for (const auto& p : code)
        {
            for (int i=0; i<p.second->instr->mDetail.op_count; i++)
                //if (p.second->mDetail.operands[i].access & CS_AC_READ)
                    if (Capstone->Intersects(p.second->instr->mDetail.operands[i], regsp))
                        return true;
        }
        
        return false;
    }

    std::string TempVarFor(std::map<address_t, int>& table, std::string prefix, address_t addr)
    {
        if (table.find(addr) == table.end())
            table.insert(std::pair<address_t, int>(addr, table.size()));

        int index = table.find(addr)->second;
        return index == 0 ? prefix : format("%s%d", prefix.c_str(), index);
    }
    
};


