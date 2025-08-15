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
};

struct funcInfo_t {
    procRequest_t request;
    callConv_t callConv{callConvUnknown};
    arch_t arch;
    bool simpleStack{false};
};

struct instrInfo_t {
    bool processed{false};
    shared<CapInstr> instr;
    
    struct instrInfoFlag_t {
        char type{0};
        // this instruction requireds this flag for operation
        bool needed{false};
        // lastSet instructions were altered, so flag value extraction is not possible anymore
        bool dirty{false};
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
//        copy.visible |= other.savedVisibly;
        changed |= p->Merge(copy);
    }
    if (!processed)
    {
        stack = stackAbs == -9999 ? o->stack + stackRel : stackAbs;
    }
    else
    {
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
//        std::map<address_t, std::shared_ptr<CTracer>> mMethods;
        struct info_t {
            address_t proc;
            code_t code;
            funcInfo_t func;
        };
        std::map<address_t, shared<info_t>> mInfos;
    
public:
    ProgramAnalyser(Options& options) : mOptions(options)
    {
    }
    
    void Scan(address_t method)
    {
        std::shared_ptr<CTracer> tracer(new CTracer(mOptions));
        tracer->Trace(method);
        std::shared_ptr<info_t> newInfo = std::make_shared<info_t>();
        newInfo->proc = method;
        newInfo->func.arch = mOptions.arch;
        newInfo->func.simpleStack = mOptions.simpleStack;
        
        for (const auto& [addr, instr] : tracer->GetCode())
        {
            shared<instrInfo_t> info = std::make_shared<instrInfo_t>();
            info->instr = instr;
            newInfo->code.insert({addr, info});
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
        if (instr->mId == X86_INS_RET || instr->mId == X86_INS_RETF)
            stackChange -= instr->Imm();
        if (instr->mDetail.op_count >= 1 && instr->mDetail.operands[0].type == X86_OP_REG &&
            instr->mDetail.operands[0].reg == X86_REG_SP)
        {
            switch (instr->mId)
            {
                case X86_INS_MOV:
                    // TODO: not very smart
                    stackChange = 111;
                    if (instr->mDetail.operands[1].type == X86_OP_REG && instr->mDetail.operands[1].reg == X86_REG_BP)
                    {
                        bool saved = false;
                        int sum = 0;
                        for (const auto& [addr, i] : code)
                        {
                            if (i->instr->mId == X86_INS_MOV && strcmp(i->instr->mOperands, "sp, bp") == 0)
                            {
//                                if (addr != instr->mAddress)
//                                    saved = false;
                                break;
                            }
                            if (!saved)
                                sum += i->stackRel;
                            if (i->instr->mId == X86_INS_MOV && strcmp(i->instr->mOperands, "bp, sp") == 0)
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
                default:
                    assert(0);
            }
        }
        if ((instr->mId == X86_INS_CALL || instr->mId == X86_INS_LCALL) && instr->IsDirectCall())
        {
            if (mOptions.procModifiers.find(instr->CallTarget()) != mOptions.procModifiers.end())
            {
                procRequest_t req = mOptions.procModifiers.find(instr->CallTarget())->second;
                if ((int)req & (int)procRequest_t::stackDrop2)
                    stackChange -= 2;
                if ((int)req & (int)procRequest_t::stackDrop4)
                    stackChange -= 4;
                if ((int)req & (int)procRequest_t::stackDrop6)
                    stackChange -= 6;
                if ((int)req & (int)procRequest_t::stackDrop8)
                    stackChange -= 8;
                if ((int)req & (int)procRequest_t::stackDrop10)
                    stackChange -= 10;
            }
        }
        info->stackRel = stackChange;
        //return stackChange;
    }
    void AddProcRequest(shared<instrInfo_t> info, address_t target, procRequest_t req)
    {
        info->procRequest = (procRequest_t)((int)info->procRequest | (int)req);
        info->procTarget = target;
    }
    
    virtual void AnalyseProc(address_t proc, procRequest_t req) = 0;
    
    std::map<address_t, procRequest_t> GetRequests(address_t proc)
    {
        std::map<address_t, procRequest_t> aux;
        shared<info_t> info = check(mInfos.find(proc), mInfos.end())->second;
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
            calls.push_back({code.begin()->second->instr->JumpTarget(), procRequest_t::callNear});
            return calls;
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
                        calls.push_back({pinstr->CallTarget(), procRequest_t::callNear});
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

            shared<jumpTable_t> jt;
            if (pinstr->IsIndirectCall())
            {
                jt = mOptions.GetJumpTable(pinstr->mAddress);
                if (jt)
                {
                    for (int i=0; i<jt->GetSize(); i++)
                        if (jt->IsValid(i))
                            if (unique.find(jt->GetTarget(i)) == unique.end())
                            {
                                unique.insert(jt->GetTarget(i));
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

