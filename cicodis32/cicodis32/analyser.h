//
//  analyser.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

struct funcInfo_t {
    uint8_t readsReg[X86_REG_ENDING] = {0};
    uint8_t writesReg[X86_REG_ENDING] = {0};
    uint8_t alwaysWritesReg[X86_REG_ENDING] = {0}; // discards
    bool readsCarry = false;
    bool readsZero = false;
    bool writesCarry = false;
    bool writesZero = false;
    bool alwaysReadsCarry = false;
    bool alwaysReadsZero = false;
    bool alwaysWritesCarry = false;
    bool shouldWriteZero = false;
    bool shouldWriteCarry = false;
    bool noReturn = false;
};

struct instrInfo_t {
    enum callConv_t {
        callConvUnknown = 0,
        callConvSimpleStackNear = 1,
        callConvSimpleStackFar = 2,
        callConvShiftStackNear = 3,
        callConvShiftStackFar = 4
    } callConv{callConvUnknown}; // TODO: move to func info!
    
    struct instrInfoReg_t
    {
        bool wasRead{false};
        bool wasWritten{false};
    } reg[X86_REG_ENDING];
    
    int stackDepth{0};
    bool jumpsToRet{false};
    bool isLast{false};
    std::string stop;
    procRequest_t procRequest{procRequest_t::returnNone};
    address_t procTarget;
    bool infiniteLoop{false};

    struct instrInfoFlag_t {
        char type = 0;
        bool wasRead{false};
        bool wasWritten{false};
        bool isDestructive{false};
        bool save{false};
        bool saved{false};
        address_t savedFor;
        char variableRead[32] = {0};
        char variableWrite[32] = {0};

        std::set<address_t, cmp_adress_t> lastSet;
        x86_insn lastSetInsn{X86_INS_INVALID};
        cs_x86_op depends[2] = {{.type = X86_OP_INVALID}};
        bool dirty[2] = {false, false};
        bool broken{false};
    } flagZero, flagCarry, flagOverflow, flagSign;
    
    enum class flagMask_t {
        none = 0,
        zero = 1,
        carry = 2,
        overflow = 4,
        sign = 8
    };
    struct precondition_t {
        flagMask_t needs{flagMask_t::none};
        
        //address_t writeAddr;
        //address_t readAddr;
        x86_insn writeOp{X86_INS_INVALID};
        x86_insn readOp{X86_INS_INVALID};
        std::string variable;
    };
    
    std::vector<precondition_t> savePrecondition;
    std::vector<std::string> readPrecondition;
    
    void CopyFrom(const instrInfo_t& o)
    {
        stackDepth = o.stackDepth;
        for (int i=0; i<X86_REG_ENDING; i++)
        {
            reg[i] = o.reg[i];
        }
        flagZero = o.flagZero;
        flagCarry = o.flagCarry;
        flagOverflow = o.flagOverflow;
        flagSign = o.flagSign;
        
        flagCarry.variableRead[0] = 0;
        flagCarry.variableWrite[0] = 0;
        flagZero.variableRead[0] = 0;
        flagZero.variableWrite[0] = 0;
        flagSign.variableRead[0] = 0;
        flagSign.variableWrite[0] = 0;
        flagOverflow.variableRead[0] = 0;
        flagOverflow.variableWrite[0] = 0;

        //        flagCarry.isDestructive = false; // do not spread!
        flagCarry.save = false; // do not spread!
        flagCarry.saved = o.flagCarry.saved | o.flagCarry.save;
        flagZero.save = false; // do not spread!
        flagZero.saved = o.flagZero.saved | o.flagZero.save;
        flagSign.save = false; // do not spread!
        flagSign.saved = o.flagSign.saved | o.flagSign.save;
        flagOverflow.save = false; // do not spread!
        flagOverflow.saved = o.flagOverflow.saved | o.flagOverflow.save;

        callConv = o.callConv;
    }

    bool MergeMultiFlag(shared<instrInfo_t> o)
    {
        bool changed = false;
        for (const auto& ls : o->flagZero.lastSet)
            if (flagZero.lastSet.find(ls) == flagZero.lastSet.end())
            {
                flagZero.lastSet.insert(ls);
                changed = flagZero.broken = true;
            }
        for (const auto& ls : o->flagCarry.lastSet)
            if (flagCarry.lastSet.find(ls) == flagCarry.lastSet.end())
            {
                flagCarry.lastSet.insert(ls);
                changed = flagCarry.broken = true;
            }
        for (const auto& ls : o->flagOverflow.lastSet)
            if (flagOverflow.lastSet.find(ls) == flagOverflow.lastSet.end())
            {
                flagOverflow.lastSet.insert(ls);
                changed = flagOverflow.broken = true;
            }
        for (const auto& ls : o->flagSign.lastSet)
            if (flagSign.lastSet.find(ls) == flagSign.lastSet.end())
            {
                flagSign.lastSet.insert(ls);
                changed = flagSign.broken = true;
            }
        return changed;
    }
    bool Merge(shared<instrInfo_t> o)
    {
        bool changed = false;
        for (int i=0; i<X86_REG_ENDING; i++)
        {
            if (!reg[i].wasRead && o->reg[i].wasRead)
                changed = true;
            if (!reg[i].wasWritten && o->reg[i].wasWritten)
                changed = true;

            reg[i].wasRead |= o->reg[i].wasRead;
            reg[i].wasWritten |= o->reg[i].wasWritten;
        }
//        if (flagSign.lastSet != o->flagSign.lastSet)
//        {
//            for (const auto& ls : o->flagSign.lastSet)
//                flagSign.lastSet.insert(ls);
//            //changed = flagSign.broken = true;
//            changed = true;
//        }
        if (flagCarry.saved != o->flagCarry.saved)
        {
            flagCarry.saved |= o->flagCarry.saved;
            changed = true;
        }
        if (flagZero.saved != o->flagZero.saved)
        {
            flagZero.saved |= o->flagZero.saved;
            changed = true;
        }
        if (flagSign.saved != o->flagSign.saved)
        {
            flagSign.saved |= o->flagSign.saved;
            changed = true;
        }
        if (flagOverflow.saved != o->flagOverflow.saved)
        {
            flagOverflow.saved |= o->flagOverflow.saved;
            changed = true;
        }

        auto CopyVar = [](instrInfoFlag_t& a, instrInfoFlag_t& b)
        {
            if (b.variableRead[0])
            {
                if (!a.variableRead[0])
                    strncpy(a.variableRead, b.variableRead, sizeof(a.variableRead));
                assert(strcmp(a.variableRead, b.variableRead) == 0);
            }
            if (b.variableWrite[0])
            {
                if (!a.variableWrite[0])
                    strncpy(a.variableWrite, b.variableWrite, sizeof(a.variableWrite));
                assert(strcmp(a.variableWrite, b.variableWrite) == 0);
            }
        };
        
        CopyVar(flagSign, o->flagSign);
        CopyVar(flagZero, o->flagZero);
        CopyVar(flagOverflow, o->flagOverflow);
        CopyVar(flagCarry, o->flagCarry);
        
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
};

class Analyser {
public:
    const Options& mOptions;
    std::map<address_t, std::shared_ptr<CTracer>, cmp_adress_t> mMethods;
    struct info_t {
        std::map<address_t, shared<instrInfo_t>, cmp_adress_t> code;
        funcInfo_t summary;
        procRequest_t request;
    };
    std::map<address_t, std::shared_ptr<info_t>, cmp_adress_t> mInfos;
    //std::map<address_t, procRequest_t, cmp_adress_t> mRequests;

public:
    Analyser(Options& options) : mOptions(options)
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
    
    std::string TempVarFor(std::map<address_t, int, cmp_adress_t>& table, std::string prefix, address_t addr)
    {
        if (table.find(addr) == table.end())
            table.insert(std::pair<address_t, int>(addr, table.size()));

        int index = table.find(addr)->second;
        return index == 0 ? prefix : format("%s%d", prefix.c_str(), index);
    }
    
    void AnalyseProc(address_t proc, procRequest_t req)
    {
        const bool verbose{true}; // TODO: dual tracing !!!
        shared<CTracer> tracer = check(mMethods.find(proc), mMethods.end())->second;
        std::map<address_t, shared<CapInstr>, cmp_adress_t> code = tracer->GetCode();
        shared<info_t> info(new info_t);
        info->request = req;
        std::vector<std::pair<address_t, address_t>> head({{address_t(), tracer->Address()}});
        funcInfo_t funcInfo;
        int tempIndexCf{0}, tempIndexSf{0};
        std::map<address_t, int, cmp_adress_t> tempIndexPrecond, tempIndexZf; //, tempIndexOf{0};
        
        instrInfo_t::callConv_t callConv = GetCallConvention(code);
        
        if (verbose)
        {
            printf("    %x %x:%x proc %x\n", proc.linearOffset(), proc.segment, proc.offset, proc.linearOffset());
            for (const auto& p : code)
            {
                if (p.second->isLabel)
                    printf("loc_");
                else
                    printf("    ");
                printf("%x %x:%x %s %s\n", p.second->mAddress.linearOffset(), p.second->mAddress.segment, p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);
            }
        }

        while (head.size())
        {
            std::vector<std::pair<address_t, address_t>> newHead;
            for (std::pair<address_t, address_t> link : head)
            {
                if (verbose)
                    printf("%x->%x: ", link.first.offset, link.second.offset);
                
                shared<CapInstr> instr = code.find(link.second)->second;
                if (verbose)
                    printf("    instr: %s", instr->AsString().c_str());
                
                shared<instrInfo_t> prevInfo;
                if (link.first)
                {
                    assert(info->code.find(link.first) != info->code.end());
                    prevInfo = info->code.find(link.first)->second;
                    assert(prevInfo);
                } else {
                    prevInfo = shared<instrInfo_t>(new instrInfo_t);
                    prevInfo->callConv = callConv;
                }
                
                shared<instrInfo_t> newInfo(new instrInfo_t);
                newInfo->CopyFrom(*prevInfo.get());
            again:
                //TODO goto ret
//                if (instr->IsDirectJump())
//                {
//                    shared<CapInstr> target = code.find(instr->JumpTarget())->second;
//                    if ((target->mId == X86_INS_RET || target->mId == X86_INS_RETF) &&
//                        newInfo->callConv != instrInfo_t::callConvShiftStackNear &&
//                        newInfo->callConv != instrInfo_t::callConvShiftStackFar)
//                    {
//                        assert(target->Imm() == 0);
//                        newInfo->jumpsToRet = true;
//                    }
//                }
                
                auto ClearChildren = [&](address_t addr) {
                    shared<CapInstr> destructed = code.find(addr)->second;
                    // spread the flag
                    for (address_t next : destructed->mNext) // TODO: not twice!
                    {
                        newHead.push_back(std::pair<address_t, address_t>(destructed->mAddress, next));
                    }
                };
                
                std::set<x86_reg> reads = instr->ReadsRegisters();
                std::set<x86_reg> writes = instr->WritesRegisters();
                bool needsCf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_CF | X86_EFLAGS_TEST_CF);
                bool needsZf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_ZF | X86_EFLAGS_TEST_ZF);
                bool needsOf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_OF | X86_EFLAGS_TEST_OF);
                bool needsSf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_SF | X86_EFLAGS_TEST_SF);

                // RET
                if (instr->mId == X86_INS_RETF || instr->mId == X86_INS_RET)
                {
                    switch (req)
                    {
                        case procRequest_t::returnNone:
                            break;
                        case procRequest_t::returnZero:
                            needsZf = true;
                            break;
                        case procRequest_t::returnCarry:
                            needsCf = true;
                            break;
                    }
                }

                if (needsCf + needsZf + needsOf + needsSf > 1)
                {
                    std::map<address_t, x86_insn, cmp_adress_t> dest;
                    for (address_t ls : newInfo->flagCarry.lastSet)
                    {
                        shared<instrInfo_t> instrSet = info->code.find(ls)->second;
                        if (instrSet->flagCarry.isDestructive)
                            dest.insert(std::pair<address_t, x86_insn>(ls, code.find(ls)->second->mId));
                    }
                    for (address_t ls : newInfo->flagZero.lastSet)
                    {
                        shared<instrInfo_t> instrSet = info->code.find(ls)->second;
                        if (instrSet->flagZero.isDestructive)
                            dest.insert(std::pair<address_t, x86_insn>(ls, code.find(ls)->second->mId));
                    }
                    for (address_t ls : newInfo->flagOverflow.lastSet)
                    {
                        shared<instrInfo_t> instrSet = info->code.find(ls)->second;
                        if (instrSet->flagOverflow.isDestructive)
                            dest.insert(std::pair<address_t, x86_insn>(ls, code.find(ls)->second->mId));
                    }
                    for (address_t ls : newInfo->flagSign.lastSet)
                    {
                        shared<instrInfo_t> instrSet = info->code.find(ls)->second;
                        if (instrSet->flagSign.isDestructive)
                            dest.insert(std::pair<address_t, x86_insn>(ls, code.find(ls)->second->mId));
                    }
                    if (dest.size())
                    {
                        assert(dest.size() == 1);
                        address_t addr = dest.begin()->first;
                        x86_insn set = dest.begin()->second;
                        x86_insn cond = instr->mId;
                        shared<instrInfo_t> destructive = info->code.find(addr)->second;
                        std::string variable = TempVarFor(tempIndexPrecond, "temp_cond", instr->mAddress);
                        instrInfo_t::flagMask_t needs = (instrInfo_t::flagMask_t)(
                             (int)(needsCf ? instrInfo_t::flagMask_t::carry : instrInfo_t::flagMask_t::none) |
                             (int)(needsZf ? instrInfo_t::flagMask_t::zero : instrInfo_t::flagMask_t::none) |
                             (int)(needsOf ? instrInfo_t::flagMask_t::overflow : instrInfo_t::flagMask_t::none) |
                              (int)(needsSf ? instrInfo_t::flagMask_t::sign : instrInfo_t::flagMask_t::none));

                        if (destructive->savePrecondition.size() == 0 || destructive->savePrecondition[0].needs != needs || destructive->savePrecondition[0].writeOp != set || destructive->savePrecondition[0].readOp != cond || destructive->savePrecondition[0].variable != variable)
                        {
                            destructive->savePrecondition.push_back({
                                .needs = needs,
                                .writeOp = set,
                                .readOp = cond,
                                .variable = variable
                            });
                        }
                        assert(newInfo->readPrecondition.size() == 0);
                        newInfo->readPrecondition.push_back(variable);
                        
                        needsCf = needsZf = needsOf = needsSf = 0;
                        // do not use simple flow
                    }
                }
                // TODO: check dirty flags
                if (needsCf)
                {
                    for (address_t o : newInfo->flagCarry.lastSet)
                    {
                        shared<CapInstr> oi = code.find(o)->second;
                        if (oi->mId == X86_INS_CALL)
                        {
                            if (oi->IsDirectCall())
                                AddProcRequest(newInfo, oi->CallTarget(), procRequest_t::returnCarry);
                            else
                                newInfo->stop = "callee must return carry"; // TODO: function metadata runtime
                        }
                    }
                    
                    assert(newInfo->flagCarry.lastSet.size() == 1);
                    address_t ls = *newInfo->flagCarry.lastSet.begin();
                    shared<instrInfo_t> destructive = info->code.find(ls)->second;
                    if (destructive->flagCarry.isDestructive)
                    {
                        if (!destructive->flagCarry.save)
                        {
                            if (tempIndexCf == 0)
                                snprintf(newInfo->flagCarry.variableRead, sizeof(newInfo->flagCarry.variableRead), "temp_cf");
                            else
                                snprintf(newInfo->flagCarry.variableRead, sizeof(newInfo->flagCarry.variableRead), "temp_cf%d", tempIndexCf);
                            tempIndexCf++;
                            
                            strcpy(destructive->flagCarry.variableWrite, newInfo->flagCarry.variableRead);
                            destructive->flagCarry.save = true;
                            destructive->flagCarry.savedFor = instr->mAddress;
                            ClearChildren(ls);
                        }
                    }
                    newInfo->flagCarry.wasRead = true;
                }
                if (needsZf)
                {
                    for (address_t o : newInfo->flagZero.lastSet)
                    {
                        shared<CapInstr> oi = code.find(o)->second;
                        if (oi->mId == X86_INS_CALL)
                        {
                            if (oi->IsDirectCall())
                                AddProcRequest(newInfo, oi->CallTarget(), procRequest_t::returnZero);
                            else
                                newInfo->stop = "callee must return zero";
                        }
                    }
                    
                    if (newInfo->flagZero.saved)
                    {
                        address_t setflag = *newInfo->flagZero.lastSet.begin();
                        shared<instrInfo_t> setflaginfo = info->code.find(setflag)->second;
                        strncpy(newInfo->flagZero.variableRead,
                                setflaginfo->flagZero.variableWrite, sizeof(newInfo->flagZero.variableRead));
                    }
                    
                    if (newInfo->flagZero.lastSet.size() == 1)
                    {
                        if (newInfo->flagZero.dirty[0] || newInfo->flagZero.dirty[1])
                        {
                            address_t setZeroAddr = *newInfo->flagZero.lastSet.begin();
                            shared<instrInfo_t> setZeroInfo = info->code.find(setZeroAddr)->second;
                            if (!setZeroInfo->flagZero.save)
                            {
                                strcpy(newInfo->flagZero.variableRead, "flags.zero");
                                strcpy(setZeroInfo->flagZero.variableWrite, newInfo->flagZero.variableRead);
                                setZeroInfo->flagZero.save = true;
                                setZeroInfo->flagZero.savedFor = instr->mAddress;
                                ClearChildren(setZeroAddr);
                            }
                            
                        }
                        
                        address_t ls = *newInfo->flagZero.lastSet.begin();
                        shared<instrInfo_t> destructive = info->code.find(ls)->second;
                        if (destructive->flagZero.isDestructive)
                        {
                            assert(0);
                        }
                    }
                    
                    if (newInfo->flagZero.lastSet.size() > 1)
                    {
                        std::string variable = TempVarFor(tempIndexZf, "temp_zf", instr->mAddress);

                        strcpy(newInfo->flagZero.variableRead, variable.c_str());
                        
                        for (address_t setZeroAddr : newInfo->flagZero.lastSet)
                        {
                            shared<instrInfo_t> setZeroInfo = info->code.find(setZeroAddr)->second;
                            if (!setZeroInfo->flagZero.save)
                            {
                                strcpy(setZeroInfo->flagZero.variableWrite, newInfo->flagZero.variableRead);
                                setZeroInfo->flagZero.save = true;
                                setZeroInfo->flagZero.savedFor = instr->mAddress;
                                ClearChildren(setZeroAddr);
                            }
                        }
                    }
                    newInfo->flagZero.wasRead = true;
                }
                if (needsOf)
                {
                    if (instr->mId == X86_INS_CALL)
                        assert(0);
                    
                    assert(newInfo->flagOverflow.lastSet.size() == 1);
                    newInfo->flagOverflow.wasRead = true;
                }
                if (needsSf)
                {
                    if (instr->mId == X86_INS_CALL)
                        assert(0);
                    
                    if (newInfo->flagSign.lastSet.size() > 1)
                    {
                        snprintf(newInfo->flagZero.variableRead, sizeof(newInfo->flagZero.variableRead), "temp_sf%d", tempIndexSf++);
                        
                        for (address_t setSignAddr : newInfo->flagSign.lastSet)
                        {
                            shared<instrInfo_t> setSignInfo = info->code.find(setSignAddr)->second;
                            if (!setSignInfo->flagSign.save)
                            {
                                strcpy(setSignInfo->flagZero.variableWrite, newInfo->flagZero.variableRead);
                                setSignInfo->flagSign.save = true;
                                setSignInfo->flagSign.savedFor = instr->mAddress;
                                ClearChildren(setSignAddr);
                            }
                        }
                    }
                    newInfo->flagSign.wasRead = true;
                }
                
                auto applyFlags = [&](char type, uint64_t modifyMask, instrInfo_t::instrInfoFlag_t& flag)
                {
                    // TODO: Temp workaround, CALL sets all flags!
                    // TODO: interrupt could also update some flags
                    if (instr->mId == X86_INS_INT || instr->mId == X86_INS_CALL || (instr->mDetail.eflags & modifyMask))
                    {
                        if (verbose)
                            printf("(set %cf) ", type);

                        flag.type = type;
                        flag.wasWritten = true;
                        flag.lastSet = {instr->mAddress}; // gabo!
                        flag.lastSetInsn = instr->mId;
                        
                        flag.depends[0].type = X86_OP_INVALID;
                        flag.depends[1].type = X86_OP_INVALID;
                        flag.dirty[0] = false;
                        flag.dirty[1] = false;
                        
                        flag.isDestructive = false;
                        flag.save = false;
                        flag.saved = false;
                        
                        // scasb sets the flag directly
                        if (flag.lastSetInsn == X86_INS_SCASB)
                            return;
                        
                        int j = 0;
                        if (instr->mDetail.op_count == 3)
                        {
                            assert(instr->mDetail.operands[2].type == X86_OP_IMM);
                        } else {
                            assert(instr->mDetail.op_count <= 2);
                        }
                        for (int i=0; i<instr->mDetail.op_count; i++)
                            if (instr->mDetail.operands[i].access & CS_AC_READ)
                                flag.depends[j++] = instr->mDetail.operands[i];
                    }
                };
                auto checkDirtyFlags = [&](instrInfo_t::instrInfoFlag_t& flag, cs_x86_op change)
                {
                    //flag.depends[0].type != X86_OP_INVALID &&
                    if (Capstone->Intersects(flag.depends[0], change))
                        flag.dirty[0] = true;
                    if (Capstone->Intersects(flag.depends[1], change))
                        flag.dirty[1] = true;
                };
                for (x86_reg r : reads)
                {
                    if (!prevInfo->reg[r].wasWritten)
                        funcInfo.readsReg[r] = true;
                    newInfo->reg[r].wasRead = true;
                }
                
                for (int i=0; i<instr->mDetail.op_count; i++)
                {
                    if (instr->mDetail.operands[i].access & CS_AC_WRITE)
                    {
                        checkDirtyFlags(newInfo->flagCarry, instr->mDetail.operands[i]);
                        checkDirtyFlags(newInfo->flagZero, instr->mDetail.operands[i]);
                        checkDirtyFlags(newInfo->flagOverflow, instr->mDetail.operands[i]);
                        checkDirtyFlags(newInfo->flagSign, instr->mDetail.operands[i]);
                    }
                }
                
                for (x86_reg r : writes)
                {
                    funcInfo.writesReg[r] = true;
                    newInfo->reg[r].wasWritten = true;
                }
                
                applyFlags('c', X86_EFLAGS_MODIFY_CF | X86_EFLAGS_RESET_CF | X86_EFLAGS_SET_CF, newInfo->flagCarry);
                applyFlags('z', X86_EFLAGS_MODIFY_ZF | X86_EFLAGS_RESET_ZF | X86_EFLAGS_SET_ZF, newInfo->flagZero);
                applyFlags('o', X86_EFLAGS_MODIFY_OF | X86_EFLAGS_RESET_OF | X86_EFLAGS_SET_OF, newInfo->flagOverflow);
                applyFlags('s', X86_EFLAGS_MODIFY_SF | X86_EFLAGS_RESET_SF | X86_EFLAGS_SET_SF, newInfo->flagSign);
                
                switch (instr->mId)
                {
                    case X86_INS_SHL:
                    case X86_INS_SHR:
                    case X86_INS_ADD:
                    case X86_INS_ADC:
                    case X86_INS_SUB:
                    case X86_INS_SBB:
                        newInfo->flagCarry.isDestructive = true;
                        break;
                    default:
                        //                        newInfo->flagCarry.isDestructive = false;
                        break;
                }
                
                if (verbose)
                    printf("\n");

                newInfo->stackDepth = prevInfo->stackDepth + instr->mTemplate.stack;
                // update info, store
                bool forceScan = false;
                bool forceAgain = false;
                auto mergeInfoIt = info->code.find(link.second);
                if (mergeInfoIt != info->code.end())
                {
                    if (verbose)
                        printf("* merge %x->%x: ",link.first.linearOffset(), link.second.linearOffset());

                    // TODO: why?
//                    assert(!newInfo->flagCarry.save && !mergeInfoIt->second->flagCarry.save);
                    if (mergeInfoIt->second->MergeMultiFlag(newInfo))
                    {
                        if (verbose)
                            printf("* multi flag\n");

                        //printf("--- multi flag\n");
                        //forceAgain = true;
                        newInfo = mergeInfoIt->second;
                        goto again;
                    } else
                        if (verbose)
                            printf("* no multi flag, ");

                        if (mergeInfoIt->second->Merge(newInfo))
                        {
                            if (verbose)
                                printf("* force scan\n");
                            //printf("--- regular\n");
                            // invalidate current?
                            //                        newHead.push_back(std::pair<address_t, address_t>(address_t(), link.second));
                            //                        newHead.push_back(link);
                            // invalidate all paths
                            forceScan = true;
                            // TODO: if multiple flag source -> force scan only current, do not spread
                            
                            //TODO: mess!
                            
                        }
                    if (verbose)
                        printf("* ok\n");
                } else
                    info->code.insert(std::pair<address_t, shared<instrInfo_t>>(link.second, newInfo));
                
                // TODO: cycle!
                if (forceAgain)
                {
                    newHead.push_back(link);
                } else {
                    for (address_t next : instr->mNext)
                    {
                        if (forceScan || info->code.find(next) == info->code.end())
                            newHead.push_back(std::pair<address_t, address_t>(link.second, next));
                    }
                }
            }
            head = newHead;
        }

        // BAD, collect all RET, and merge
        PostProcess(tracer, info, req);
        mInfos.insert(std::pair<address_t, shared<info_t>>(proc, info));
    }
    
    void PostProcess(shared<CTracer> tracer, shared<info_t> info, procRequest_t req)
    {
        std::map<address_t, shared<CapInstr>, cmp_adress_t> code = tracer->GetCode();
        info->code[code.rbegin()->first]->isLast = true;

        FindInfiniteLoops(tracer, info);
        if (req == procRequest_t::returnNone)
            return;
        
        // post process
        for (const auto& p : code)
        {
            if (p.second->mId == X86_INS_RETF || p.second->mId == X86_INS_RET)
            {
                shared<instrInfo_t> infoRet = info->code.find(p.first)->second;
                shared<instrInfo_t> infoSet;
                shared<CapInstr> instrSet;
                
                switch (req)
                {
                    case procRequest_t::returnNone:
                        break;
                    case procRequest_t::returnZero:
                        /*
                        assert(infoRet->flagZero.lastSet.size() == 1);
                        infoSet = info->code.find(*infoRet->flagZero.lastSet.begin())->second;
                        // TODO: advance 1 instruction, .update / .dump = true or .postSave = true
                        infoSet->flagZero.save = true;
                        strncpy(infoSet->flagZero.variableWrite, "flags.zero", sizeof(infoSet->flagZero.variableWrite));
                         */
                        break;
                    case procRequest_t::returnCarry:
                        
                        assert(infoRet->flagCarry.lastSet.size() == 1);
                        instrSet = code.find(*infoRet->flagCarry.lastSet.begin())->second;
                        if (instrSet->mId != X86_INS_STC && instrSet->mId != X86_INS_CLC)
                        {
                            infoSet = info->code.find(*infoRet->flagCarry.lastSet.begin())->second;
                            infoSet->flagCarry.save = true;
                            strncpy(infoSet->flagCarry.variableWrite, "flags.carry", sizeof(infoSet->flagCarry.variableWrite));
                        }
                        break;
                }
                
            }
        }
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
    
    std::set<address_t, cmp_adress_t> GetGapLabels(address_t proc)
    {
        std::set<address_t, cmp_adress_t> labels;
        
        CTracer::code_t& code = mMethods.find(proc)->second->GetCode();
/*
        if (code.size() == 1 && code.begin()->second->mId == X86_INS_JMP)
            return {};

        for (const auto& p : code)
        {
            shared<CapInstr> pinstr = p.second;
            if (pinstr->HasJumpTarget())
                labels.insert(pinstr->JumpTarget());
        }*/
        
        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                shared<CapInstr> pinstr = p.second;
//                printf("gap %d bytes\n", p.first.offset - next.offset);
                //if (pinstr->HasJumpTarget())
                
                //    labels.insert(pinstr->JumpTarget());
                if (pinstr->isLabel)
                    labels.insert(pinstr->mAddress);
            }
            next = {p.second->mAddress.segment, p.second->mAddress.offset + p.second->mSize};
        }

        return labels;
    }

    instrInfo_t::callConv_t GetCallConvention(const CTracer::code_t& code)
    {
        int retFar = 0, retNear = 0;
        bool stack = UsesStack(code);
        
        for (const auto& p : code)
        {
            if (p.second->mId == X86_INS_RETF)
                retFar++;
            if (p.second->mId == X86_INS_RET)
                retNear++;
        }
        
        if (retFar > 0)
        {
            assert(retNear == 0);
            return stack ? instrInfo_t::callConvShiftStackFar : instrInfo_t::callConvSimpleStackFar;
        }
        if (retNear > 0)
        {
            assert(retFar == 0);
            return stack ? instrInfo_t::callConvShiftStackNear : instrInfo_t::callConvSimpleStackNear;
        }
        return instrInfo_t::callConvUnknown;
    }
    
    bool UsesStack(const CTracer::code_t& code)
    {
        cs_x86_op regsp = {.type=X86_OP_REG, .reg = X86_REG_SP};
        
        for (const auto& p : code)
        {
            for (int i=0; i<p.second->mDetail.op_count; i++)
                //if (p.second->mDetail.operands[i].access & CS_AC_READ)
                    if (Capstone->Intersects(p.second->mDetail.operands[i], regsp))
                        return true;
        }
        
        return false;
    }
    
    void FindInfiniteLoops(shared<CTracer> tracer, shared<info_t> info)
    {
        std::map<address_t, shared<CapInstr>, cmp_adress_t> code = tracer->GetCode();
        // post process
        for (const auto& p : code)
        {
            shared<CapInstr> pinstr = p.second;
            if (!pinstr->IsConditionalJump())
                continue;
            if (pinstr->mPrev.size() != 1)
                continue;
            shared<CapInstr> prev = code.find(*pinstr->mPrev.begin())->second;
            if (!prev->isLabel)
                continue;
            if (prev->mId != X86_INS_CMP && prev->mId != X86_INS_TEST)
                continue;
            if (prev->mAddress != pinstr->JumpTarget())
                continue;
            info->code.find(prev->mAddress)->second->infiniteLoop = true;
        }
    }

};
