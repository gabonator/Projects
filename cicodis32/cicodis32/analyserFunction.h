//
//  analyserFunction.h
//  cicodis32
//
//  Created by Gabriel Valky on 16/07/2025.
//

#pragma once
//#include "tracer.h"
//#include "analyser.h"

// FunctionAnalyser - traversing single function code and filling in instrInfo structure
class FunctionAnalyser : public ProgramAnalyser {
public:
    // Constructor
    FunctionAnalyser(shared<Options> options) : ProgramAnalyser(options)
    {
        verbose = mOptions->verbose;
    }

    // Analyze a procedure, filling instruction info and processing control flow
    virtual void AnalyseProc(address_t proc, procRequest_t req, int stackDrop)
    {
        auto info = mInfos.find(proc)->second;
        auto& code = info->code;
        std::vector<std::pair<address_t, address_t>> head({{address_t(), proc}});

        tempIndexPrecond.clear();
        tempIndexZf.clear();
        tempIndexCf.clear();
        tempIndexSf.clear();
        tempIndexOf.clear();

        for (const auto& [addr, p] : info->code)
            GetStackChange(p, info->code);

        // Reset instruction states for new analysis iteration
        for (auto& [addr, p] : info->code)
        {
            p->processed = false;
            p->savePrecondition.clear();
            p->readPrecondition.clear();
        }
        info->func.request = req;
        info->func.callConv = GetCallConvention(info);
        info->func.stackDrop = stackDrop;

        if (verbose)
            DumpCode(proc, code, req, stackDrop);

        while (!head.empty())
        {
            std::vector<std::pair<address_t, address_t>> newHead;

            for (auto link : head)
            {
                if (verbose)
                    printf("%x->%x: ", link.first.offset, link.second.offset);
                
                auto instr = code.find(link.second)->second->instr;

                if (verbose)
                    printf("    instr: %s", instr->AsString().c_str());
                
                auto prevInfo = std::make_shared<instrInfo_t>();
                if (link.first)
                {
                    assert(info->code.find(link.first) != info->code.end());
                    *prevInfo = *info->code.find(link.first)->second;
                } 
                else 
                {
                    if ((int)req & (int)procRequest_t::callIsolated)
                        prevInfo->stack = ResumeStackFromIndirectJump(proc);
                    else
                        prevInfo->stack = 0; // TODO: long call?
                }
                
                auto newInfo = code.find(link.second)->second;

                if (!newInfo->AdvanceAndMerge(prevInfo) && newInfo->processed)
                {
                    if (verbose)
                        printf(" no merge\n");
                    continue;
                }
                
                auto clearInsns = AnalyseInstruction(newInfo, info);
                newInfo->processed = true;

                if (verbose)
                    printf("\n");

                for (auto clear : clearInsns)
                    for (auto child : info->code.find(clear)->second->instr->mNext)
                        newHead.emplace_back(clear, child);

                for (auto next : instr->mNext)
                    newHead.emplace_back(link.second, next);
            }
            head = std::move(newHead);
        }

        // Post processing after analysis
        PostProcess(info, req);
        mInfos.insert(std::pair<address_t, shared<info_t>>(proc, info));
    }

    // Pure virtual: Analyze a single instruction and return addresses for further analysis
    virtual std::set<address_t> AnalyseInstruction(shared<instrInfo_t> instr, shared<info_t> info) = 0;

    // Dump procedure code and associated information for debugging
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

        for (auto& p : code)
        {
            printf("%+3d", p.second->stack);
            if (p.second->instr->isLabel)
                printf("loc_");
            else
                printf("    ");
            printf("%x %x:%x %s %s\n", p.first.linearOffset(), p.first.segment, p.first.offset, p.second->instr->mMnemonic, p.second->instr->mOperands);
        }
    }

    // Post-process analyzed info, checking stack, flags, and adding annotations
    void PostProcess(shared<info_t> info, procRequest_t req)
    {
        bool isolate = (int)req & (int)procRequest_t::callIsolated; // TODO: risky!
        int stackOffset = ((int)req & (int)procRequest_t::nearAsFar) ? 2 : 0;
        int stackOffsetRetf = ((int)req & (int)procRequest_t::nearAsFar) ? -2 : 0;

        // Clear stack stop flags before analysis
        for (auto& [a, p] : info->code)
        {
            if (p->stop.starts_with("stack_"))
                p->stop.clear();
        }

        FindInfiniteLoops(info->code);
        bool stackGood = true;
        // Static stack check
        for (auto& [a, p] : info->code)
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
                    } 
                    else if (p->instr->mId == X86_INS_RETF)
                    {
                        if (info->func.stackDrop != -p->stack + 2) // CHECK!!
                            p->stop = utils::format("stack_below_retf, %d/%d", info->func.stackDrop, -p->stack);
                    } 
                    else if (p->instr->mId != X86_INS_RET && p->instr->mId != X86_INS_RETF)
                    {
                        p->stop = "stack_below";
                    }
                    stackGood = false;
                    continue;
                }
            }
            if (p->stack + stackOffset >= 0)
                stackGood = true;

            if (p->instr->mId == X86_INS_RET)
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
        
        // Mark instructions related to special marks
        for (auto& [a, p] : info->code)
        {
            int begin = p->instr->mAddress.linearOffset();
            int end = p->instr->mAddress.linearOffset() + p->instr->mSize;
            for (auto addr : mOptions->marks)
                if (addr.linearOffset() >= begin && addr.linearOffset() <= end)
                    p->stop += utils::format("mark %04x:%04x, addr %04x:%04x, instr: %s %s, bytes: %s",
                                             addr.segment, addr.offset, p->instr->mAddress.segment, p->instr->mAddress.offset,
                                             p->instr->mMnemonic,
                                             p->instr->mOperands,
                                             p->instr->GetBytes().c_str());
        }

        // Propagate call requests based on flags
        for (auto& [a, p] : info->code)
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
        for (auto& [a, p] : info->code)
        {
            if (p->instr->mId == X86_INS_RET || p->instr->mId == X86_INS_RETF)
                continue;

            // Save full condition when multiple flags needed
            int needed = 0;
            bool anyDirty = false;
            std::set<address_t> deps;
            for (auto flag : p->Flags())
            {
                if (flag->needed)
                {
                    needed++;
                    deps.insert(flag->depends.begin(), flag->depends.end());
                }
                if (flag->needed && flag->dirty)
                    anyDirty = true;
            }
            if (anyDirty && needed > 1)
            {
                for (auto depAddr : deps)
                {
                    auto destructive = info->code.find(depAddr)->second;
                    destructive->savePrecondition.push_back({
                        .writeOp = destructive->instr->mId,
                        .readOp = p->instr->mId,
                        .variable = utils::format("temp_cond%d", tempCounter)
                    });
                }
                if (p->readPrecondition.empty())
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

        // Save single flags where possible
        for (auto& [a, p] : info->code)
        {
            if (a.offset == 0x426)
            {
                int f=9;
            }

            for (auto flag : p->Flags())
            {
                if (!p->readPrecondition.empty())
                    continue;
                
                if (flag->depends.empty())
                    continue;
                
                // CC1 - loc_1f4d1: TEST should set carry for RCR
                if (!p->instr->mTemplate.simpleJump &&
                    !p->instr->mTemplate.simpleCond &&
                    (p->instr->mDetail.eflags & readFlagDirectMask[flag->type]))
                {
                    for (auto depAddr : flag->depends)
                    {
                        auto dep = info->code.find(depAddr)->second;
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
                    // Cannot calculate this flag value from input operands of lastSet
                    for (auto depAddr : flag->depends)
                    {
                        auto dep = info->code.find(depAddr)->second;
                        if (!dep->savePrecondition.empty())
                            continue;

                        if (dep->instr->mId == X86_INS_CALL)
                            continue;
                        if (flag->type == 'c' && dep->instr->mTemplate.savedVisiblyCarry)
                            continue;
                        if (flag->type == 'z' && (dep->instr->mId == X86_INS_SCASB || dep->instr->mId == X86_INS_SCASW ||
                                                  dep->instr->mId == X86_INS_CMPSB || dep->instr->mId == X86_INS_CMPSW || dep->instr->mId == X86_INS_CMPSD))
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

        // Self modifying code detection heuristics
        if (info->code.size() > 5 && info->code.begin()->second->instr->mAddress == info->func.proc)
        {
            std::vector<shared<instrInfo_t>> linear;
            std::set<x86_insn> exits;

            for (auto& [a, p] : info->code)
            {
                if (!p->instr->mTemplate.continuous)
                    break;
                if (p->instr->mNext.size() != 1)
                    break;
                if (linear.size() > 5)
                    break;
                linear.push_back(p);
            }
            for (auto& [a, p] : info->code)
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
    }

    // Resume stack balance from indirect jump parent information
    int ResumeStackFromIndirectJump(address_t proc)
    {
        // find parent, reuse attributes
        if (mOptions->isolateLabels.find(proc) != mOptions->isolateLabels.end())
            return 0;
        for (auto& j : mOptions->indirectJumps)
            if (j.target == proc)
            {
                auto parentInfo = mInfos.find(j.parent)->second;
                for (auto& [a, p] : parentInfo->code)
                {
                    if (a == j.origin)
                    {
                        return p->stack;
                    }
                }
                assert(0);
            }
        assert(0);
        return 0;
    }

    // Determine calling convention based on procRequest and code usage
    callConv_t GetCallConvention(shared<info_t> info)
    {
        auto req = mOptions->procModifiers.find(info->func.proc)->second;
        if ((int)req & (int)procRequest_t::callIsolated)
        {
            if (mOptions->stackShiftAlways)
            {
                for (auto& [a, i] : info->code)
                {
                    if (i->instr->mId == X86_INS_RETF)
                    {
                        return callConv_t::callConvShiftStackFar;
                    }
                    if (i->instr->mId == X86_INS_RET)
                    {
                        if ((int)req & (int)procRequest_t::callLong)
                            return callConv_t::callConvShiftStackLong;
                        return callConv_t::callConvShiftStackNear;
                    }
                }
            }
            if (mOptions->stackShiftAlways)
                return callConv_t::callConvShiftStackNear;
            return callConv_t::callConvNear;
        }

        bool stack = UsesReg(info->code, X86_REG_SP) || UsesReg(info->code, X86_REG_ESP);
        if (info->func.simpleStack)
            stack |= UsesReg(info->code, X86_REG_BP);

        if (((int)req & (int)procRequest_t::callNear) && ((int)req & (int)procRequest_t::callFar))
        {
            return callConv_t::callConvShiftStackNearFar;
        }
        
        if ((int)req & (int)procRequest_t::nearAsFar)
        {
            return callConv_t::callConvShiftStackNear;
        } 
        else if ((int)req & (int)procRequest_t::callFar)
        {
            if (mOptions->stackShiftAlways)
                return callConv_t::callConvShiftStackFar;
            if (stack)
            {
                if (info->func.simpleStack)
                    return callConv_t::callConvSimpleStackFar;
                return callConv_t::callConvShiftStackFar;
            }
            return callConv_t::callConvFar;
        }
        else if ((int)req & (int)procRequest_t::callLong)
        {
            if (mOptions->stackShiftAlways)
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
            if (mOptions->stackShiftAlways)
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

    // Check if code uses a given register
    bool UsesReg(const code_t& code, x86_reg reg)
    {
        cs_x86_op regsp = {.type=X86_OP_REG, .reg = reg};
        
        for (auto& p : code)
        {
            for (int i = 0; i < p.second->instr->mDetail.op_count; i++)
                if (Capstone->Intersects(p.second->instr->mDetail.operands[i], regsp))
                    return true;
        }
        return false;
    }

    // Generate temporary variable name for a given address
    std::string TempVarFor(std::map<address_t, int>& table, std::string prefix, address_t addr)
    {
        if (table.find(addr) == table.end())
            table.insert(std::pair<address_t, int>(addr, table.size()));

        int index = table.find(addr)->second;
        return index == 0 ? prefix : format("%s%d", prefix.c_str(), index);
    }

protected:
    // Helper methods

    // Mark infinite loops in code based on conditional jumps and jump targets
    void FindInfiniteLoops(code_t& code)
    {
        for (auto& p : code)
        {
            auto pinstr = p.second->instr;
            if (!pinstr->IsConditionalJump())
                continue;
            if (pinstr->mPrev.size() != 1)
                continue;
            auto prev = code.find(*pinstr->mPrev.begin())->second->instr;
            if (!prev->isLabel)
                continue;
            if (prev->mId != X86_INS_CMP && prev->mId != X86_INS_TEST)
                continue;
            if (prev->mAddress != pinstr->JumpTarget())
                continue;
            code.find(prev->mAddress)->second->infiniteLoop = true;
        }
    }

    // Member variables: temp index tables for flags
    std::map<address_t, int> tempIndexPrecond, tempIndexZf, tempIndexCf, tempIndexSf, tempIndexOf;

    // Verbosity flag
    bool verbose{false};
};
