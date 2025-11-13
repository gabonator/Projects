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
        std::vector<std::pair<address_t, address_t>> head({{address_t(), proc}});

        tempIndexPrecond.clear();
        tempIndexZf.clear();
        tempIndexCf.clear();
        tempIndexSf.clear();
        tempIndexOf.clear();

        for (const auto& [addr, p] : info->code)
            GetStackChange(p, info->code);

        // TODO: can we always reset?
//        if (info->func.request != req)
        {
            // second iteration
            for (const auto& [addr, p] : info->code)
            {
                p->processed = false;
                p->savePrecondition.clear();
                p->readPrecondition.clear();
//                for (instrInfo_t::instrInfoFlag_t* flag : p->Flags())
//                    p->lastSet.clear();
            }
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
                    if ((int)req & (int)procRequest_t::callIsolated)
                        prevInfo->stack = ResumeStackFromIndirectJump(proc);
                    else
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
        PostProcess(info, req);
        mInfos.insert(std::pair<address_t, shared<info_t>>(proc, info));
    }
    
    int ResumeStackFromIndirectJump(address_t proc)
    {
        // find parent, reuse attributes
        if (mOptions.isolateLabels.find(proc) != mOptions.isolateLabels.end())
            return 0;
        for (indirectJump_t j : mOptions.indirectJumps)
            if (j.target == proc)
            {
//                auto pParent = mIndirectToParent.find(j.origin);
//                if (pParent == mIndirectToParent.end())
//                    assert(0);
                
                shared<info_t> parentInfo = mInfos.find(j.parent)->second;
                for (const auto& [a, p] : parentInfo->code)
                    if (a == j.origin)
                    {
                        //assert(p->stack != -9999); // last pass must be valid
                        return p->stack;
                    }
                
                assert(0);
            }
        assert(0);
        return 0;
    }
    
    void PostProcess(shared<info_t> info, procRequest_t req)
    {
        bool isolate = (int)req & (int)procRequest_t::callIsolated; // TODO: risky!
        int stackOffset = (int)req & (int)procRequest_t::nearAsFar ? 2 : 0;
        int stackOffsetRetf = (int)req & (int)procRequest_t::nearAsFar ? -2 : 0;

        // TODO: stop cleanup in second pass!
        for (const auto& [a, p] : info->code)
        {
            if (p->stop.starts_with("stack_"))
                p->stop.clear();
        }

        FindInfiniteLoops(info->code);
        bool stackGood = true;
        // static stack check
        for (const auto& [a, p] : info->code)
        {
            if (a == info->func.proc)
                stackGood = true;

            if (p->stack + stackOffset < 0)
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
            if (p->stack + stackOffset >= 0)
                stackGood = true;
            if (p->instr->mId == X86_INS_RET )
            {
                if (p->stack + stackOffset != 0 && !isolate)
                    p->stop = "stack_unbalanced";
            }
            if (p->instr->mId == X86_INS_RETF)
            {
                if (p->stack + stackOffsetRetf != 0 && !isolate)
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
                                {
                                    r = (procRequest_t)((int)r | (int)procRequest_t::returnZero);
                                    flag->visible = true;
                                }
                                else
                                    p->stop = "callee must return zero";
                                break;
                            case 'c':
                                if (p->instr->IsDirectCall())
                                {
                                    r = (procRequest_t)((int)r | (int)procRequest_t::returnCarry);
                                    flag->visible = true;
                                }
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
            if (p->instr->mId == X86_INS_RET || p->instr->mId == X86_INS_RETF)
                continue;

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
            if (anyDirty && needed > 1 /* && deps.size() == 1*/)
            {
                for (address_t depAddr : deps)
                {
//                    assert(deps.size() == 1);
                    shared<instrInfo_t> destructive = info->code.find(depAddr)->second;
                    // save whole condition if couldnt be reconstructed by saving single flag
                    //assert(destructive->savePrecondition.size() == 0); // check ck1:loc_283c
                    destructive->savePrecondition.push_back({
                        .writeOp = destructive->instr->mId,
                        .readOp = p->instr->mId,
                        .variable = utils::format("temp_cond%d", tempCounter)
                    });
                }
                if (p->readPrecondition.size() == 0)
                    p->readPrecondition.push_back(utils::format("temp_cond%d", tempCounter));
                else
                    p->readPrecondition = {"stop(\"xxx multi precond\")"};
                tempCounter++;
            }
        }

        static const uint64_t readFlagDirectMask[128] =
        {
            ['c'] = X86_EFLAGS_TEST_CF,
            ['z'] = X86_EFLAGS_TEST_ZF,
            ['o'] = X86_EFLAGS_TEST_OF,
            ['s'] = X86_EFLAGS_TEST_SF,
        };

        // save single flag
        for (const auto& [a, p] : info->code)
        {
            if (a.offset == 0x426)
            {
                int f=9;
            }

            for (instrInfo_t::instrInfoFlag_t* flag : p->Flags())
            {
                if (p->readPrecondition.size())
                {
//                    assert(flag->depends.size() <= 1);
                    continue;
                }
                
                if (flag->depends.empty())
                    continue;
                
                // CC1 - loc_1f4d1: TEST should set carry for RCR
                // TODO: inconsistent!
                if (!p->instr->mTemplate.simpleJump &&
                    !p->instr->mTemplate.simpleCond &&
                    (p->instr->mDetail.eflags & readFlagDirectMask[flag->type]))
                {
                    for (address_t depAddr : flag->depends)
                    {
                        shared<instrInfo_t> dep = info->code.find(depAddr)->second;
                        switch (flag->type)
                        {
                            case 'c':
                                if (!dep->instr->mTemplate.savedVisiblyCarry)
                                    dep->GetFlag(flag->type).save = true;
                                break;
                            case 'z':
                                if (!dep->instr->mTemplate.savedVisiblyZero)
                                    dep->GetFlag(flag->type).save = true;
                                break;
                            default:
                                assert(0);
                        }
                    }
                }
                
                if (flag->dirty || flag->depends.size() > 1)
                {
                    // cannot calculate this flag value from input operands of lastSet
                    for (address_t depAddr : flag->depends)
                    {
                        shared<instrInfo_t> dep = info->code.find(depAddr)->second;
                        if (dep->savePrecondition.size())
                            continue;

                        if (dep->instr->mId == X86_INS_CALL)
                            continue;
                        if (flag->type == 'c' && dep->instr->mTemplate.savedVisiblyCarry)
                            continue;
                        if (flag->type == 'z' && dep->instr->mId == X86_INS_SCASB)
                            continue;
                        if (flag->type == 'z' && dep->instr->mId == X86_INS_SCASW)
                            continue;
                        if (flag->type == 'z' && dep->instr->mId == X86_INS_CMPSB) // TODO: tables
                            continue;
                        if (flag->type == 'z' && dep->instr->mId == X86_INS_CMPSW) // TODO: tables
                            continue;
                        if (flag->type == 'z' && dep->instr->mId == X86_INS_CMPSD) // TODO: tables
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
        
        // self modifying
        if (info->code.size() > 5 && info->code.begin()->second->instr->mAddress == info->func.proc)
        {
            std::vector<shared<instrInfo_t>> linear;
            std::set<x86_insn> exits;
            
            for (const auto& [a, p] : info->code)
            {
                if (!p->instr->mTemplate.continuous)
                    break;
                if (p->instr->mNext.size() != 1)
                    break;
                if (linear.size() > 5)
                    break;
                linear.push_back(p);
            }
            for (const auto& [a, p] : info->code)
            {
                if (p->instr->mTemplate.ret)
                    exits.insert(p->instr->mId);
            }

            if (linear.size() > 2 &&
                linear[0]->instr->mId == X86_INS_POP &&
                linear[1]->instr->mId == X86_INS_PUSH &&
                strcmp(linear[1]->instr->mOperands, "cs") == 0 &&
                linear[2]->instr->mId == X86_INS_PUSH &&
                strcmp(linear[2]->instr->mOperands, linear[0]->instr->mOperands) == 0 &&
                exits.size() == 1 &&
                *exits.begin() == X86_INS_RETF)
            {
                info->reqSelf = procRequest_t((int)info->reqSelf | (int)procRequest_t::nearAsFar);
            }
            
        }
        //AddProcRequest(p, p->instr->CallTarget(), r);
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
            printf("%+3d", p.second->stack);
            if (p.second->instr->isLabel)
                printf("loc_");
            else
                printf("    ");
            printf("%x %x:%x %s %s\n", p.first.linearOffset(), p.first.segment, p.first.offset, p.second->instr->mMnemonic, p.second->instr->mOperands);
        }
    }

    callConv_t GetCallConvention(shared<info_t> info) // TODO: should be merged with procrequest?
    {
        procRequest_t req = mOptions.procModifiers.find(info->func.proc)->second;
        if ((int)req & (int)procRequest_t::callIsolated)
        {
            // resume stack balance?
            if (mOptions.stackShiftAlways) // TODO: wtf?
                for (const auto& [a, i] : info->code)
                {
                    if (i->instr->mId == X86_INS_RETF)
                    {
                        if (mOptions.stackShiftAlways)
                            return callConv_t::callConvShiftStackFar;
                        return callConv_t::callConvFar;
                    }
                    if (i->instr->mId == X86_INS_RET)
                    {
                        if (mOptions.stackShiftAlways && (int)req & (int)procRequest_t::callLong)
                            return callConv_t::callConvShiftStackLong; // TODO: cleanup
                        if (mOptions.stackShiftAlways)
                            return callConv_t::callConvShiftStackNear;
                        return callConv_t::callConvNear;
                    }
                }
//            assert(0);
            // what if isolated part uses stack and parent doesn't?
            if (mOptions.stackShiftAlways)
                return callConv_t::callConvShiftStackNear;
            return callConv_t::callConvNear;
        }

        bool stack = UsesReg(info->code, X86_REG_SP) || UsesReg(info->code, X86_REG_ESP);
        if (info->func.simpleStack)
            stack |= UsesReg(info->code, X86_REG_BP);
        // TODO: nearfar!?
        if (((int)req & (int)procRequest_t::callNear) && ((int)req & (int)procRequest_t::callFar))
        {
//            printf("// Problem: %04x:%04x sub_%x - near&far&uses stack!\n", info->proc.segment, info->proc.offset,
//                   info->proc.linearOffset());
//            assert(!stack);
            return callConv_t::callConvShiftStackNearFar;
        }
        
        if ((int)req & (int)procRequest_t::nearAsFar)
        {
            return callConv_t::callConvShiftStackNear;
        } else
        if ((int)req & (int)procRequest_t::callFar)
        {
            if (mOptions.stackShiftAlways)
                return callConv_t::callConvShiftStackFar;
            if (stack)
            {
                if (info->func.simpleStack)
                    return callConv_t::callConvSimpleStackFar;
                return callConv_t::callConvShiftStackFar;
            }
            return callConv_t::callConvFar;
        }
        else if ((int)req & (int)procRequest_t::callLong) // TODO: near | long
        {
            if (mOptions.stackShiftAlways)
            {
                if ((int)info->func.request & (int)procRequest_t::entry)
                    return callConv_t::callConvNear;
                else
                    return callConv_t::callConvShiftStackLong;
            }
            assert(0);
        }
        else if ((int)req & (int)procRequest_t::callNear)
        {
            if (mOptions.stackShiftAlways)
            {
                if ((int)info->func.request & (int)procRequest_t::entry)
                    return callConv_t::callConvNear;
                else
                    return callConv_t::callConvShiftStackNear;
            }
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


