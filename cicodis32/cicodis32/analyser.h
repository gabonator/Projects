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
    struct instrInfoFlag_t {
        char type{0};
        bool save{false};
        std::string variableWrite;
        std::string variableRead;
        bool needed;
        bool dirty[3];
        std::set<address_t, cmp_adress_t> lastSet;
        x86_insn lastSetInsn{X86_INS_INVALID};
                
        // private:
        bool isDestructive{false};
        bool savedVisibly{false};
        cs_x86_op depends[2];
        std::set<address_t, cmp_adress_t> willSet;
        x86_insn willSetInsn{X86_INS_INVALID};
        bool saved{false};

        void CopyFrom(instrInfo_t::instrInfoFlag_t& o);
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
        flagMask_t needs{flagMask_t::none};
        x86_insn writeOp{X86_INS_INVALID};
        x86_insn readOp{X86_INS_INVALID};
        std::string variable;
    };
    
    std::vector<precondition_t> savePrecondition;
    std::vector<std::string> readPrecondition;
    bool infiniteLoop{false};
    std::string stop;
    
    // private:
    procRequest_t procRequest{procRequest_t::returnNone};
    address_t procTarget;

    void CopyFrom(shared<instrInfo_t> o);
    bool MergeMultiFlag(shared<instrInfo_t> o);
    bool Merge(shared<instrInfo_t> o);
};

void instrInfo_t::instrInfoFlag_t::CopyFrom(instrInfo_t::instrInfoFlag_t& o)
{
    type = o.type;
    save = false;
    saved = o.saved | o.save;
    //savedFor = o.savedFor;
    
    lastSet = o.willSet.empty() ? o.lastSet : o.willSet;
    lastSetInsn = o.willSet.empty() ? o.lastSetInsn : o.willSetInsn;
    dirty[0] = o.dirty[0];
    dirty[1] = o.dirty[1];
    dirty[2] = o.dirty[2];
    depends[0] = o.depends[0];
    depends[1] = o.depends[1];
    savedVisibly = o.savedVisibly;
}

void instrInfo_t::CopyFrom(shared<instrInfo_t> o)
{
    for (instrInfoFlag_t* p : Flags())
        p->CopyFrom(o->GetFlag(p->type));
}

bool instrInfo_t::MergeMultiFlag(shared<instrInfo_t> o)
{
    bool changed = false;
    for (instrInfoFlag_t* p : Flags())
    {
        instrInfoFlag_t& thisFlag = *p;
        instrInfoFlag_t& thatFlag = o->GetFlag(p->type);
        
        std::set<address_t, cmp_adress_t> thatSet = thatFlag.willSet.empty() ?
            thatFlag.lastSet : thatFlag.willSet;
        thatSet = thatFlag.lastSet;
//        if (p->type == 'c')
//        {
//            printf("cur deps: THIS(");
//            for (const auto& ls : thisFlag.lastSet)
//                printf("%x ", ls.offset);
//            printf(") THAT(");
//            for (const auto& ls : thatSet)
//                printf("%x ", ls.offset);
//            printf(")\n");
//        }

        for (const auto& ls : thatSet)
        {
            if (thisFlag.lastSet.find(ls) == thisFlag.lastSet.end())
            {
                thisFlag.lastSet.insert(ls);
                ///assert(thisFlag.lastSet.size() < 3);
                
                if (!thisFlag.variableRead.empty())
                    thisFlag.variableRead = "obsolete:" + thisFlag.variableRead; // TODO
                if (!thatFlag.variableRead.empty())
                    thatFlag.variableRead = "obsolete:" + thatFlag.variableRead;
                changed =  true;
            }
        }
    }
    return changed;
}

bool instrInfo_t::Merge(shared<instrInfo_t> o)
{
    bool changed = false;
    for (instrInfoFlag_t* p : Flags())
    {
        if (p->saved != o->GetFlag(p->type).saved)
        {
            p->saved |= o->GetFlag(p->type).saved;
            changed = true;
        }
    }

    auto CopyVar = [](instrInfoFlag_t& a, instrInfoFlag_t& b)
    {
//        printf("debug-copyvar %s/%s\n", a.variableRead.c_str(), b.variableRead.c_str());
        if (a.variableRead != b.variableRead)
        {
            // TODO: baaad
            if (a.variableRead == "obsolete:flags.carry" && b.variableRead == "temp_cf")
            {
                a.variableRead = b.variableRead;
            } else
            if (a.variableRead.empty())
                a.variableRead = b.variableRead;
            else if (b.variableRead.empty())
                b.variableRead = a.variableRead;
            else {
                //printf("varRead=%s (%d) / %s (%d)\n", a.variableRead.c_str(), a.lastSet.size(), b.variableRead.c_str(), b.lastSet.size());
                // TODO: not sufficient
                assert(a.lastSet.size() != b.lastSet.size());
                if (a.lastSet.size() > b.lastSet.size())
                    b.variableRead = a.variableRead;
                else
                    a.variableRead = b.variableRead;
            }
        }
        if (a.variableWrite != b.variableWrite)
        {
            //printf("varRead=%s (%d) / %s (%d)\n", a.variableRead.c_str(), a.lastSet.size(), b.variableRead.c_str(), b.lastSet.size());
            assert(0);
        }
    };
    
    for (instrInfoFlag_t* p : Flags())
        CopyVar(*p, o->GetFlag(p->type));
    
    stop += o->stop;
    procRequest = (procRequest_t)((int)procRequest | (int)o->procRequest);
    if (o->readPrecondition.size() != 0)
    {
        assert(readPrecondition.size() == o->readPrecondition.size());
        for (int i=0; i<readPrecondition.size(); i++)
            assert(readPrecondition[i] == o->readPrecondition[i]);
    }
    
    return changed;
}

// PathAnalyser - keep whole decoded application in memory
class ProgramAnalyser {
public:
    const Options& mOptions;
        std::map<address_t, std::shared_ptr<CTracer>, cmp_adress_t> mMethods;
        struct info_t {
            std::map<address_t, shared<instrInfo_t>, cmp_adress_t> code;
            funcInfo_t func;
        };
        std::map<address_t, std::shared_ptr<info_t>, cmp_adress_t> mInfos;
    
public:
    ProgramAnalyser(Options& options) : mOptions(options)
    {
    }
    
    void Scan(address_t method)
    {
        std::shared_ptr<CTracer> tracer(new CTracer(mOptions));
        tracer->Trace(method);
        mMethods.insert(std::pair<address_t, std::shared_ptr<CTracer>>(method, tracer));
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
        for (std::pair<address_t, std::shared_ptr<CTracer>> procpair : mMethods)
            methods.insert(procpair.first);
        return methods;
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
        
        CTracer::code_t& code = mMethods.find(proc)->second->GetCode();

        if (code.size() == 1 && code.begin()->second->mId == X86_INS_JMP)
        {
            // stub
            calls.insert(code.begin()->second->JumpTarget());
            return calls;
        }
        for (const auto& p : code)
        {
            shared<CapInstr> pinstr = p.second;
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
                        calls.insert(jt->GetTarget(i));
                }
            }
        }
        return calls;
    }

};

