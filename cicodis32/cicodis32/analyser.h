//
//  analyser.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

// TODO: add stack depth

enum class flagMask_t {
    none = 0,
    zero = 1,
    carry = 2,
    overflow = 4,
    sign = 8
};

enum callConv_t {
    callConvUnknown = 0,
    callConvSimpleStackNear = 1,
    callConvSimpleStackFar = 2,
    callConvShiftStackNear = 3,
    callConvShiftStackFar = 4
};

struct funcInfo_t {
    procRequest_t request;
    callConv_t callConv{callConvUnknown};
};

struct instrInfo_t {
    bool processed{false};
    shared<CapInstr> instr;
    
//    struct instrInfoDepends_t {
//        char type{0};
//        std::set<address_t, cmp_adress_t> depends;
//        std::set<address_t, cmp_adress_t> provides;
//        std::set<address_t, cmp_adress_t> willSet;
//    } cd, zd, sd, od;
    
    struct instrInfoFlag_t {
        char type{0};
        bool save{false}; // TODO: redundant, remove
        std::string variableWrite;
        std::string variableRead;
        
        // this instruction requireds this flag for operation
        bool needed{false};
        // lastSet instructions were altered, so flag value extraction is not possible anymore
        bool dirty{false};
        // set of all instruction which modify any flags for this instruction
        std::set<address_t, cmp_adress_t> lastSet;
        // set of instruction having an effect on this instruction (lastSet && needed)
        std::set<address_t, cmp_adress_t> depends;
        // this instruction modifies flag for following set of instructions
        std::set<address_t, cmp_adress_t> provides;
                
        // private:
        // flag value cannnot be recovered from input operand after instruction evaluation
        // e.g. `cmp ax, bx` - flags can be fully recovered
        // e.g. `shl ax, 1` - carry flag is lost
        bool isDestructive{false};
        // instruction implementation internally saves default flag (e.g. flags.zero, flags.carry)
        bool savedVisibly{false};
        bool visible{false};
        // instruction requires the flag value to be set through default flag (e.g. flags.zero, flags.carry)
        bool usesInternal{false};
        std::set<address_t, cmp_adress_t> willSet;
        bool saved{false};

        void CopyFrom(instrInfo_t::instrInfoFlag_t& o);
        bool Equals(instrInfo_t::instrInfoFlag_t& o);
        bool Merge(instrInfo_t::instrInfoFlag_t& o);
    } cf, zf, sf, of;

    instrInfo_t()
    {
//        cf.type = cd.type = 'c';
//        zf.type = zd.type = 'z';
//        sf.type = sd.type = 's';
//        of.type = od.type = 'o';
        cf.type = 'c';
        zf.type  = 'z';
        sf.type  = 's';
        of.type  = 'o';
    }

//    std::vector<instrInfoDepends_t*> Deps()
//    {
//        return {&cd, &zd, &sd, &od};
//    }

    std::vector<instrInfoFlag_t*> Flags()
    {
        return {&cf, &zf, &sf, &of};
    }
    
//    instrInfoDepends_t& GetDeps(char c)
//    {
//        for (instrInfoDepends_t* f : Deps())
//        {
//            if (f->type == c)
//                return *f;
//        }
//        assert(0);
//        return *Deps()[0];
//    }

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
        flagMask_t needs{flagMask_t::none};
        x86_insn writeOp{X86_INS_INVALID};
        x86_insn readOp{X86_INS_INVALID};
        std::string variable;
        
        bool operator==(const precondition_t& other) const {
            return needs == other.needs && writeOp == other.writeOp &&
                readOp == other.readOp && variable == other.variable;
        }
    };
    
    std::vector<precondition_t> savePrecondition;
    std::vector<std::string> readPrecondition;
    bool infiniteLoop{false};
    std::string stop;
    int stack{-9999};
    int stackDelta{0};

    // private:
    procRequest_t procRequest{procRequest_t::returnNone};
    address_t procTarget;

    void CopyFrom(shared<instrInfo_t> o);
    bool Equals(shared<instrInfo_t> o);
    bool MergeMultiFlag(shared<instrInfo_t> o);
    bool AdvanceAndMerge(shared<instrInfo_t> o);
};

bool instrInfo_t::Equals(shared<instrInfo_t> o)
{
    if (instr || !o->instr)
        return false;
    if (instr->mId != o->instr->mId)
        return false;
    for (instrInfoFlag_t* p : Flags())
        if (!p->Equals(o->GetFlag(p->type)))
            return false;
    return true;
}

bool instrInfo_t::instrInfoFlag_t::Equals(instrInfo_t::instrInfoFlag_t& o)
{
    if (type != o.type || save != o.save || variableWrite != o.variableWrite ||
        variableRead != o.variableRead || needed != o.needed ||
        dirty != o.dirty ||
        lastSet != o.lastSet)
        return false;
    if (isDestructive != o.isDestructive || savedVisibly != o.savedVisibly ||
        visible != o.visible ||
        //!Capstone->Equals(depends[0], o.depends[0]) ||
        //!Capstone->Equals(depends[1], o.depends[1]) ||
        willSet != o.willSet ||
        saved != o.saved)
        return false;
    return true;
}

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
    if (visible != o.visible) // TODO: needed?
    {
        visible = o.visible;
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
        copy.dirty = !other.willSet.empty() ? false : other.dirty; // TODO: check?
        copy.visible |= other.savedVisibly;
        changed |= p->Merge(copy);
    }
    if (!processed)
        stack = o->stack + stackDelta;
    else
    {
        if (stack != o->stack + stackDelta)
            stop = "stack_bad";
    }
    return changed;
}

// PathAnalyser - keep whole decoded application in memory
class ProgramAnalyser {
public:
    typedef std::map<address_t, shared<instrInfo_t>, cmp_adress_t> code_t;
    const Options& mOptions;
//        std::map<address_t, std::shared_ptr<CTracer>, cmp_adress_t> mMethods;
        struct info_t {
            code_t code;
            funcInfo_t func;
        };
        std::map<address_t, shared<info_t>, cmp_adress_t> mInfos;
    
public:
    ProgramAnalyser(Options& options) : mOptions(options)
    {
    }
    
    void Scan(address_t method)
    {
        std::shared_ptr<CTracer> tracer(new CTracer(mOptions));
        tracer->Trace(method);
        std::shared_ptr<info_t> newInfo = std::make_shared<info_t>();
        for (const auto& [addr, instr] : tracer->GetCode())
        {
            shared<instrInfo_t> info = std::make_shared<instrInfo_t>();
            info->instr = instr;
            newInfo->code.insert({addr, info});
        }
        mInfos.insert({method, newInfo});
        
//        mMethods.insert(std::pair<address_t, std::shared_ptr<CTracer>>(method, tracer));
    }
    
    void RecursiveScan(std::vector<address_t> methodsToProcess)
    {
        std::set<address_t, cmp_adress_t> methodsProcessed;
        while (!methodsToProcess.empty())
        {
            std::vector<address_t> newMethodsToProcess;
            for (address_t methodToProcess : methodsToProcess)
            {
                methodsProcessed.insert(methodToProcess);

                Scan(methodToProcess);
                
                for (address_t newCallTarget : GetCalls(methodToProcess))
                    if (methodsProcessed.find(newCallTarget) == methodsProcessed.end() &&
                        std::find(methodsToProcess.begin(), methodsToProcess.end(), newCallTarget) == methodsToProcess.end() &&
                        std::find(newMethodsToProcess.begin(), newMethodsToProcess.end(), newCallTarget) ==  newMethodsToProcess.end())
                    {
                        newMethodsToProcess.push_back(newCallTarget);
                    }
            }
            methodsToProcess = newMethodsToProcess;
        }
    }
    std::set<address_t, cmp_adress_t> AllMethods()
    {
        std::set<address_t, cmp_adress_t> methods;
        for (const auto& [addr, instr] : mInfos)
            methods.insert(addr);
        return methods;
    }
    
    int GetStackChange(shared<CapInstr> instr)
    {
        int stackChange = instr->mTemplate.stack;
        if (instr->mId == X86_INS_RET || instr->mId == X86_INS_RETF)
            stackChange -= instr->Imm();
        if (instr->mDetail.op_count >= 1 && instr->mDetail.operands[0].type == X86_OP_REG &&
            instr->mDetail.operands[0].reg == X86_REG_SP)
        {
            switch (instr->mId)
            {
                default:
                    assert(0);
            }
        }
        if (instr->mId == X86_INS_CALL)
        {
            procRequest_t req = mOptions.procModifiers.find(instr->mAddress)->second;
            if ((int)req & (int)procRequest_t::stackDrop16)
                stackChange -= 2;
        }

        /*
        if (mOptions.procModifiers.find(addr) != mOptions.procModifiers.end())
        {
            procRequest_t req = mOptions.procModifiers.find(addr)->second;
            if ((int)req & (int)procRequest_t::stackDrop16)
                return -2;
        }*/
        return stackChange;
    }
    void AddProcRequest(shared<instrInfo_t> info, address_t target, procRequest_t req)
    {
        info->procRequest = (procRequest_t)((int)info->procRequest | (int)req);
        info->procTarget = target;
    }
    
    virtual void AnalyseProc(address_t proc, procRequest_t req) = 0;
    
    std::map<address_t, procRequest_t, cmp_adress_t> GetRequests(address_t proc)
    {
        std::map<address_t, procRequest_t, cmp_adress_t> aux;
        shared<info_t> info = check(mInfos.find(proc), mInfos.end())->second;
        for (auto i : info->code)
        {
            if (i.second->procRequest != procRequest_t::returnNone)
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

    std::set<address_t, cmp_adress_t> GetCalls(address_t proc)
    {
        std::set<address_t, cmp_adress_t> calls;
        
        code_t& code = mInfos.find(proc)->second->code;

        if (code.size() == 1 && code.begin()->second->instr->mId == X86_INS_JMP)
        {
            // stub
            calls.insert(code.begin()->second->instr->JumpTarget());
            return calls;
        }
        for (const auto& p : code)
        {
            shared<CapInstr> pinstr = p.second->instr;
            if (pinstr->mId == X86_INS_CALL)
            {
                assert(pinstr->mDetail.op_count == 1);
                if (pinstr->mDetail.operands[0].type == X86_OP_IMM)
                    calls.insert(pinstr->CallTarget());
            }
            shared<jumpTable_t> jt;
            if (pinstr->IsIndirectCall())
            {
                jt = mOptions.GetJumpTable(pinstr->mAddress);
                if (jt)
                {
                    for (int i=0; i<jt->GetSize(); i++)
                        if (jt->IsValid(i))
                            calls.insert(jt->GetTarget(i));
                }
            }
        }
        return calls;
    }

};

