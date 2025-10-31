//
//  analyser.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

enum callConv_t {
    callConvUnknown = 0,
    callConvSimpleStackNear = 1,
    callConvSimpleStackFar = 2,
    callConvShiftStackNear = 3,
    callConvShiftStackFar = 4,
    callConvNear = 5,
    callConvFar = 6,
    callConvShiftStackNearFar = 7,
    callConvShiftStackLong = 8
};

struct funcInfo_t {
    address_t proc;
    procRequest_t request;
    int stackDrop{0};
    int stackEntry{0};
    callConv_t callConv{callConvUnknown};
    arch_t arch;
    bool jit;
    bool simpleStack{false};
    
    std::string makeProcIdentifier() const
    {
        std::string extraInfo;
        int temp = (int)request;
        if (temp & (int)procRequest_t::callNear && temp & (int)procRequest_t::callFar)
        {
            extraInfo += " +nearfar";
            temp ^= (int)procRequest_t::callNear;
            temp ^= (int)procRequest_t::callFar;
        } else {
            if (temp & (int)procRequest_t::callNear)
            {
                temp ^= (int)procRequest_t::callNear;
            }
            if (temp & (int)procRequest_t::callLong)
            {
                extraInfo += " +long";
                temp ^= (int)procRequest_t::callLong;
            }
            if (temp & (int)procRequest_t::callFar)
            {
                extraInfo += " +far";
                temp ^= (int)procRequest_t::callFar;
            }
        }
        if (temp & (int)procRequest_t::returnCarry)
        {
            extraInfo += " +returnCarry";
            temp ^= (int)procRequest_t::returnCarry;
        }
        if (temp & (int)procRequest_t::returnZero)
        {
            extraInfo += " +returnZero";
            temp ^= (int)procRequest_t::returnZero;
        }
        if (stackDrop != 0 && stackDrop != -999)
            extraInfo += utils::format(" +stackDrop%d", stackDrop);
        if (stackEntry != 0)
            extraInfo += utils::format(" +stackEntry%d", stackEntry);
        if (temp & (int)procRequest_t::callIsolated)
        {
            extraInfo += " +isolate";
            temp ^= (int)procRequest_t::callIsolated;
        }
        if (temp & (int)procRequest_t::popsCs)
        {
            extraInfo += " +popsCs";
            temp ^= (int)procRequest_t::popsCs;
        }
        if (temp & (int)procRequest_t::nearAsFar)
        {
            extraInfo += " +nearAsFar";
            temp ^= (int)procRequest_t::nearAsFar;
        }
        if (temp & (int)procRequest_t::entry)
        {
            extraInfo += " +entry";
            temp ^= (int)procRequest_t::entry;
        }
        assert(temp == 0);
        return extraInfo;
    }
};

struct instrInfo_t {
    bool processed{false};
    shared<CapInstr> instr;
    
    struct instrInfoFlag_t {
        char type{0};
        // this instruction requires this flag for operation
        bool needed{false};
        // lastSet instructions were altered, so flag value extraction is not possible anymore
        // dirty = flag cannot be recovered at the time when this instruction is being executed
        bool dirty{false};
        bool dirtyAfter{false};
        // set of all instruction which modify any flags for this instruction
        std::set<address_t> lastSet;
        // set of instruction having an effect on this instruction (lastSet && needed)
        std::set<address_t> depends;
        // this instruction modifies flag for following set of instructions
        std::set<address_t> provides;
                
//        // private:
//        // flag value cannnot be recovered from input operand after instruction evaluation
//        // e.g. `cmp ax, bx` - flags can be fully recovered
//        // e.g. `shl ax, 1` - carry flag is lost
//        bool isDestructive{false};
//        // instruction implementation internally saves default flag (e.g. flags.zero, flags.carry)
//        bool savedVisibly{false};
//        bool visible{false};
//        // instruction requires the flag value to be set through default flag (e.g. flags.zero, flags.carry)
//        bool usesInternal{false};
//        bool saved{false};

        std::set<address_t> willSet;
        bool willSetDirty{false};

        
        // second phase processing
        // should update the flag visibly?
        bool save{false};
        // sets the flag value directly?
        bool visible{false};

        bool Merge(instrInfo_t::instrInfoFlag_t& o);
    } cf, zf, sf, of;

    instrInfo_t()
    {
        cf.type = 'c';
        zf.type = 'z';
        sf.type = 's';
        of.type = 'o';
    }

    std::vector<instrInfoFlag_t*> Flags()
    {
        return {&cf, &zf, &sf, &of};
    }

    instrInfoFlag_t& GetFlag(char c)
    {
        for (instrInfoFlag_t* f : Flags())
        {
            if (f->type == c)
                return *f;
        }
        assert(0);
        return *Flags()[0];
    }
    
    struct precondition_t {
        x86_insn writeOp{X86_INS_INVALID};
        x86_insn readOp{X86_INS_INVALID};
        std::string variable;
    };
    
    std::vector<precondition_t> savePrecondition;
    std::vector<std::string> readPrecondition;
    bool infiniteLoop{false};
    std::string stop;
    int stack{-9999};
    int stackRel{0};
    int stackAbs{-9999};

    // private:
    procRequest_t procRequest{procRequest_t::none};
    address_t procTarget;

    bool AdvanceAndMerge(shared<instrInfo_t> o);
};

bool instrInfo_t::instrInfoFlag_t::Merge(instrInfo_t::instrInfoFlag_t& o)
{
    bool changed = false;
    assert(type == o.type);
    if (dirty != o.dirty)
    {
        dirty |= o.dirty;
        changed = true;
    }
    if (lastSet != o.lastSet)
    {
        lastSet.insert(o.lastSet.begin(), o.lastSet.end());
        changed = true;
    }
    if (willSet != o.willSet)
    {
        willSet.insert(o.willSet.begin(), o.willSet.end());
        changed = true;
    }
    return changed;
}

bool instrInfo_t::AdvanceAndMerge(shared<instrInfo_t> o)
{
    bool changed = false;
    for (instrInfoFlag_t* p : Flags())
    {
        instrInfoFlag_t& other = o->GetFlag(p->type);
        instrInfoFlag_t copy;
        copy.type = other.type;
        copy.lastSet = !other.willSet.empty() ? other.willSet : other.lastSet;
        copy.dirty = !other.willSet.empty() ? other.willSetDirty : other.dirty; // TODO: check?
        if (other.willSet.empty())
            copy.dirty |= other.dirtyAfter;
        if (copy.dirty)
        {
            int f = 9;
        }
        changed |= p->Merge(copy);
    }
    if (!processed)
    {
        stack = stackAbs == -9999 ? o->stack + stackRel : stackAbs;
    }
    else
    {
        // does it enter following instruction from multiple paths?
        if (stack != (stackAbs == -9999 ? o->stack + stackRel : stackAbs))
            stop = "stack_bad";
    }
    return changed;
}

// PathAnalyser - keep whole decoded application in memory
class ProgramAnalyser {
public:
    typedef std::map<address_t, shared<instrInfo_t>> code_t;
    Options& mOptions;
    struct info_t {
        //address_t proc;
        code_t code;
        funcInfo_t func;
        procRequest_t reqSelf{procRequest_t::none};
    };
    std::map<address_t, shared<info_t>> mInfos;
//    std::map<address_t, address_t> mIndirectToParent; // TODO
    
public:
    ProgramAnalyser(Options& options) : mOptions(options)
    {
    }
    
    void Scan(address_t method)
    {
        std::shared_ptr<CTracer> tracer(new CTracer(mOptions));
        tracer->Trace(method);
        std::shared_ptr<info_t> newInfo = std::make_shared<info_t>();
        newInfo->func.proc = method;
        newInfo->func.arch = mOptions.arch;
        newInfo->func.simpleStack = mOptions.simpleStack;
        newInfo->func.jit = mOptions.jit;
        
        for (const auto& [addr, instr] : tracer->GetCode())
        {
            shared<instrInfo_t> info = std::make_shared<instrInfo_t>();
            info->instr = instr;
            newInfo->code.insert({addr, info});
//            if (instr->IsIndirectCall() || instr->IsIndirectJump())
//            {
//                if (mIndirectToParent.find(instr->mAddress) == mIndirectToParent.end())
//                    mIndirectToParent.insert({instr->mAddress, method});
//            }
        }
        mInfos.insert({method, newInfo});
    }
    
    void RecursiveScan(std::vector<address_t> methodsToProcess)
    {
        std::set<address_t> methodsProcessed;
        while (!methodsToProcess.empty())
        {
            std::vector<address_t> newMethodsToProcess;
            for (address_t methodToProcess : methodsToProcess)
            {
                methodsProcessed.insert(methodToProcess);

                Scan(methodToProcess);
                
                for (const auto& [newCallTarget, newCallConv] : GetCalls(methodToProcess))
                {
                    if (mOptions.procModifiers.find(newCallTarget) == mOptions.procModifiers.end())
                    {
                        mOptions.procModifiers.insert(std::pair<address_t, procRequest_t>{newCallTarget, newCallConv});
                    } else {
                        procRequest_t& req = mOptions.procModifiers.find(newCallTarget)->second;
                        req = (procRequest_t)((int)req | (int)newCallConv);
                    }
                    
                    if (methodsProcessed.find(newCallTarget) == methodsProcessed.end() &&
                        std::find(methodsToProcess.begin(), methodsToProcess.end(), newCallTarget) == methodsToProcess.end() &&
                        std::find(newMethodsToProcess.begin(), newMethodsToProcess.end(), newCallTarget) ==  newMethodsToProcess.end())
                    {
                        newMethodsToProcess.push_back(newCallTarget);
                    }
                }
            }
            methodsToProcess = newMethodsToProcess;
        }
    }
    std::set<address_t> AllMethods()
    {
        std::set<address_t> methods;
        for (const auto& [addr, instr] : mInfos)
            methods.insert(addr);
        return methods;
    }
    
    void GetStackChange(shared<instrInfo_t> info, code_t& code)
    {
        shared<CapInstr> instr = info->instr;
        if (instr->mAddress.offset == 0x433)
        {
            int f = 9;
        }
        int stackChange = instr->mTemplate.stack;
        
        // push/pop shifts esp by 32
        if (mOptions.arch == arch_t::arch32 && abs(stackChange) == 2)
            stackChange *= 2;
        
        if (instr->mId == X86_INS_RET || instr->mId == X86_INS_RETF)
        {
//            if (info->procRequest & procRequest_t::nearAsFar)
//            {
//                assert(0);
//                int f = 9;
//            }
//           if (instr->mId == X86_INS_RETF)
            stackChange -= instr->Imm();
        }
        
        if (instr->mDetail.op_count >= 1 && instr->mDetail.operands[0].type == X86_OP_REG &&
            (instr->mDetail.operands[0].reg == X86_REG_SP || instr->mDetail.operands[0].reg == X86_REG_ESP))
        {
            switch (instr->mId)
            {
                case X86_INS_MOV:
                    // TODO: not very smart
                    stackChange = 111;
                    if (instr->mDetail.operands[1].type == X86_OP_REG && (instr->mDetail.operands[1].reg == X86_REG_BP || instr->mDetail.operands[1].reg == X86_REG_EBP) )
                    {
                        bool saved = false;
                        int sum = 0;
                        for (const auto& [addr, i] : code)
                        {
                            if (i->instr->mId == X86_INS_MOV && (strcmp(i->instr->mOperands, "sp, bp") == 0 || strcmp(i->instr->mOperands, "esp, ebp") == 0))
                            {
//                                if (addr != instr->mAddress)
//                                    saved = false;
                                break;
                            }
                            if (!saved)
                                sum += i->stackRel;
                            if (i->instr->mId == X86_INS_MOV && (strcmp(i->instr->mOperands, "bp, sp") == 0 || strcmp(i->instr->mOperands, "ebp, esp") == 0))
                                saved = true;
                            if (!saved)
                            {
                                std::set<x86_reg> wr = i->instr->WritesRegisters();
                                if(wr.find(X86_REG_BP) != wr.end())
                                {
                                    int f = 9;
                                    saved = false;
                                    break;
                                }
                            }
                        }
                        if (saved)
                            info->stackAbs = sum;
                    }
                    break;
                case X86_INS_INC:
                    stackChange--;
                    break;
                case X86_INS_DEC:
                    stackChange++;
                    break;
                case X86_INS_AND:
                    // and sp, fffe !?
                    break;
                case X86_INS_ADD:
                    if (instr->mDetail.operands[1].type == X86_OP_IMM)
                        stackChange -= instr->Imm();
                    else
                        stackChange = 111;
                    break;
                case X86_INS_SUB:
                    if (instr->mDetail.operands[1].type == X86_OP_IMM)
                        stackChange += instr->Imm();
                    else
                        stackChange = 111;
                    break;
                case X86_INS_LEA:
                    stackChange = 333;
                    break;
                default:
                    assert(0);
            }
        }
        if ((instr->mId == X86_INS_CALL || instr->mId == X86_INS_LCALL) && instr->IsDirectCall())
        {
            int change = GuessStackBalanceForProcCached(instr->CallTarget());
            if (change != -999)
            {
                stackChange -= GuessStackBalanceForProcCached(instr->CallTarget());
                if (instr->mId == X86_INS_LCALL)
                    stackChange += 2;
            }
/*
            if (mOptions.procModifiersStack.find(instr->CallTarget()) != mOptions.procModifiersStack.end())
            {
                stackChange -= mOptions.procModifiersStack.find(instr->CallTarget())->second;
                if (instr->mId == X86_INS_LCALL)
                    stackChange += 2;
            }
 */
            // TODO: if indirect, then it is just a guess. Provide some method to specify stack balance for indirects
        }
        info->stackRel = stackChange;
        //return stackChange;
    }
    
    int GuessStackBalanceForProcCached(address_t proc)
    {
        if (mOptions.procModifiersStack.find(proc) != mOptions.procModifiersStack.end())
        {
            return mOptions.procModifiersStack.find(proc)->second;
        }
        int b = GuessStackBalanceForProc(proc);
        mOptions.procModifiersStack.insert({proc, b});
        return b;
    }
    
    int GuessStackBalanceForProc(address_t proc)
    {
        if(mInfos.find(proc) == mInfos.end())
        {
            return -999;
        }
        shared<info_t> info = mInfos.find(proc)->second;
        std::set<int> retArgs;
        bool retCs = false;
        bool instrRet = false, instrRetf = false;
        for (const auto& [addr, instr] : info->code)
        {
            instrRet |= instr->instr->mId == X86_INS_RET;
            instrRetf |= instr->instr->mId == X86_INS_RETF;
            if (instr->instr->mId == X86_INS_RET || instr->instr->mId == X86_INS_RETF)
            {
                retArgs.insert(instr->instr->Imm());
                if (instr->instr->mPrev.size()==1)
                {
                    shared<instrInfo_t> prev = info->code.find(*instr->instr->mPrev.begin())->second;
                    if (prev->instr->mId == X86_INS_POP && strcmp(prev->instr->mOperands, "cs")==0)
                        retCs = true;
//                    if (prev->instr->mId == X86_INS_ADD && strstr(prev->instr->mOperands, "sp, "))
//                        retArgs.insert(prev->instr->Imm());
                }
            }
            if (instr->instr->isTerminating)
                retArgs.insert(0);
            //shared<instrInfo_t>
        }
        if (retArgs.size()>1)
        {
            if (retArgs.size() == 2 && *retArgs.begin() == 0)
                retArgs.erase(0);
            else
                printf("// Mixed ret in %04x:%04x sub_%x()\n", proc.segment, proc.offset, proc.linearOffset());
        }
        if (retArgs.size()==1 && (*retArgs.begin() != 0 || instrRetf))
        {
//            printf("{{0x%04x, 0x%04x}, %d}, // sub_%x%s%s%s\n", proc.segment, proc.offset, *retArgs.begin() + retCs*2 + instrRetf*2, proc.linearOffset(), instrRet ? " ret" : "", instrRetf ? " retf" : "", retCs ? " popcs" : "");
            return *retArgs.begin() + retCs*2 + instrRetf*2;
        }
        if (retArgs.size()==1 && *retArgs.begin() == 0)
        {
            // far?
            return 0;
        }
//        assert(0);
        return -999;
    }
    
    void AddProcRequest(shared<instrInfo_t> info, address_t target, procRequest_t req)
    {
        info->procRequest = (procRequest_t)((int)info->procRequest | (int)req);
        info->procTarget = target;
    }
    
    virtual void AnalyseProc(address_t proc, procRequest_t req, int stackShift) = 0;
    
    std::map<address_t, procRequest_t> GetRequests(address_t proc)
    {
        std::map<address_t, procRequest_t> aux;
        shared<info_t> info = check(mInfos.find(proc), mInfos.end())->second;
        if (info->reqSelf != procRequest_t::none)
        {
            aux.insert(std::pair<address_t, procRequest_t>(info->func.proc, info->reqSelf));
        }
        for (auto i : info->code)
        {
            if (i.second->procRequest != procRequest_t::none)
            {
                if (aux.find(i.second->procTarget) == aux.end())
                {
                    aux.insert(std::pair<address_t, procRequest_t>(i.second->procTarget, i.second->procRequest));
                } else {
                    aux.find(i.second->procTarget)->second = (procRequest_t)((int)aux.find(i.second->procTarget)->second | (int)i.second->procRequest);
                }
            }
        }
        return aux;
    }

    std::vector<std::pair<address_t, procRequest_t>> GetCalls(address_t proc)
    {
        std::vector<std::pair<address_t, procRequest_t>> calls;
        std::set<address_t> unique;
        
        code_t& code = mInfos.find(proc)->second->code;

        if (code.size() == 1 && code.begin()->second->instr->mId == X86_INS_JMP)
        {
            // stub
            if (code.begin()->second->instr->mDetail.operands[0].type == X86_OP_IMM)
            {
                if (mOptions.arch == arch_t::arch16)
                    calls.push_back({code.begin()->second->instr->JumpTarget(), procRequest_t::callNear});
                else
                    calls.push_back({code.begin()->second->instr->JumpTarget(), procRequest_t::callLong});
                return calls;
            }
        }
        for (const auto& p : code)
        {
            shared<CapInstr> pinstr = p.second->instr;
            if (pinstr->mId == X86_INS_CALL)
            {
                assert(pinstr->mDetail.op_count == 1);
                if (pinstr->mDetail.operands[0].type == X86_OP_IMM)
                {
                    if (unique.find(pinstr->CallTarget()) == unique.end())
                    {
                        unique.insert(pinstr->CallTarget());
                        if (pinstr->mDetail.operands[0].size == 2)
                            calls.push_back({pinstr->CallTarget(), procRequest_t::callNear});
                        else
                            calls.push_back({pinstr->CallTarget(), procRequest_t::callLong});
                    }
                }
            }
            
            if (pinstr->mId == X86_INS_LCALL)
            {
                if (pinstr->mDetail.op_count == 2 && pinstr->mDetail.operands[0].type == X86_OP_IMM && pinstr->mDetail.operands[1].type == X86_OP_IMM)
                {
                    if (unique.find(pinstr->CallTarget()) == unique.end())
                    {
                        unique.insert(pinstr->CallTarget());
                        calls.push_back({pinstr->CallTarget(), procRequest_t::callFar});
                    }
                }
            }

            std::vector<shared<jumpTable_t>> jts;
            if (pinstr->IsIndirectCall())
            {
                jts = mOptions.GetJumpTables(pinstr->mAddress);
                for (shared<jumpTable_t> jt : jts)
                {
                    for (int i=0; i<jt->GetSize(); i++)
                        if (jt->IsValid(i))
                            if (unique.find(jt->GetTarget(i)) == unique.end())
                            {
                                unique.insert(jt->GetTarget(i));
                                if (jt->type == jumpTable_t::switch_e::Call32)
                                    calls.push_back({jt->GetTarget(i), procRequest_t::callLong});
                                else
                                    calls.push_back({jt->GetTarget(i), procRequest_t::callNear});
                            }
                }
            }
        }
        return calls;
    }
    std::vector<std::pair<address_t, address_t>> GetProcRanges(address_t proc)
    {
        std::vector<std::pair<address_t, procRequest_t>> calls;
        std::set<address_t> unique;
        
        code_t& code = mInfos.find(proc)->second->code;

        std::vector<std::pair<address_t, address_t>> ranges;
        address_t first, last;
        
        for (const auto& [addr, info] : code)
        {
            if (info->instr->mSize == 0)
                continue;
            if (!info->stop.empty())
                continue;
            address_t instbegin = info->instr->mAddress;
            address_t instend{instbegin.segment, instbegin.offset + info->instr->mSize};
            if (!first.isValid() || instbegin != last)
            {
                if (first.isValid())
                    ranges.push_back({first, last});
                first = instbegin;
                last = instend;
            } else
            {
                assert (instbegin == last);
                last = instend;
            }
        }
        if (first.isValid())
            ranges.push_back({first, last});
        return ranges;
    }

};

