//
//  analyser.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

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
    
    address_t parent;
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
        bool needed{false};
        address_t savedFor;
        std::string variableRead;
        std::string variableWrite;
        bool savedVisibly{false};

        std::set<address_t, cmp_adress_t> lastSet;
        x86_insn lastSetInsn{X86_INS_INVALID};

        std::set<address_t, cmp_adress_t> willSet;
        x86_insn willSetInsn{X86_INS_INVALID};

        cs_x86_op depends[2] = {{.type = X86_OP_INVALID}};
        bool dirty[3] = {false, false, false}; // 2 depends + 1 destructive
        bool broken{false};
        
        void CopyFrom(const instrInfoFlag_t& o)
        {
            type = o.type;
            wasRead = o.wasRead;
            wasWritten = o.wasWritten;
            save = false;
            saved = o.saved | o.save;
            savedFor = o.savedFor;
            
            lastSet = o.willSet.empty() ? o.lastSet : o.willSet;
            lastSetInsn = o.willSet.empty() ? o.lastSetInsn : o.willSetInsn;
            dirty[0] = o.dirty[0];
            dirty[1] = o.dirty[1];
            dirty[2] = o.dirty[2];
            depends[0] = o.depends[0];
            depends[1] = o.depends[1];
            savedVisibly = o.savedVisibly;
        }
    } flagZero, flagCarry, flagOverflow, flagSign;
    
    std::vector<instrInfoFlag_t*> Flags()
    {
        return {&flagZero, &flagCarry, &flagOverflow, &flagSign};
    }
    
    instrInfoFlag_t& GetFlag(char c)
    {
        switch (c)
        {
            case 'z': return flagZero;
            case 'c': return flagCarry;
            case 's': return flagSign;
            case 'o': return flagOverflow;
            default:
                assert(0);
                return flagZero;
        }
    }
    enum class flagMask_t {
        none = 0,
        zero = 1,
        carry = 2,
        overflow = 4,
        sign = 8
    };
    struct precondition_t {
        flagMask_t needs{flagMask_t::none};
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
        flagZero.CopyFrom(o.flagZero);
        flagCarry.CopyFrom(o.flagCarry);
        flagOverflow.CopyFrom(o.flagOverflow);
        flagSign.CopyFrom(o.flagSign);
        callConv = o.callConv;
        parent = o.parent;
    }

    bool MergeMultiFlag(shared<instrInfo_t> o)
    {
        bool changed = false;
        char types[] = "zcos";
        for (int i=0; types[i]; i++)
        {
            instrInfoFlag_t& thisFlag = GetFlag(types[i]);
            instrInfoFlag_t& thatFlag = o->GetFlag(types[i]);
            
            for (const auto& ls : thatFlag.lastSet)
                if (thisFlag.lastSet.find(ls) == thisFlag.lastSet.end())
                {
                    thisFlag.lastSet.insert(ls);
                    if (!thisFlag.variableRead.empty())
                        thisFlag.variableRead = "obsolete:" + thisFlag.variableRead; // TODO
                    if (!thatFlag.variableRead.empty())
                        thatFlag.variableRead = "obsolete:" + thatFlag.variableRead;
//                    thisFlag.variableRead = thatFlag.variableRead;
//                    thisFlag.variableWrite = thatFlag.variableWrite;
                    changed = thisFlag.broken = true;
                }
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
            if (a.variableRead != b.variableRead)
            {
                if (a.variableRead.empty())
                    a.variableRead = b.variableRead;
                else if (b.variableRead.empty())
                    b.variableRead = a.variableRead;
                else {
                    //printf("varRead=%s (%d) / %s (%d)\n", a.variableRead.c_str(), a.lastSet.size(), b.variableRead.c_str(), b.lastSet.size());
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
        procRequest_t request;
    };
    std::map<address_t, std::shared_ptr<info_t>, cmp_adress_t> mInfos;

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
        const bool verbose{mOptions.verbose}; // TODO: dual tracing !!!
        shared<CTracer> tracer = check(mMethods.find(proc), mMethods.end())->second;
        std::map<address_t, shared<CapInstr>, cmp_adress_t> code = tracer->GetCode();
        shared<info_t> info(new info_t);
        info->request = req;
        std::vector<std::pair<address_t, address_t>> head({{address_t(), tracer->Address()}});
        std::map<address_t, int, cmp_adress_t> tempIndexPrecond, tempIndexZf, tempIndexCf, tempIndexSf, tempIndexOf;
        
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
            auto ClearChildren = [&](std::set<address_t, cmp_adress_t> addrs) {
                for (address_t addr : addrs)
                {
                    shared<CapInstr> destructed = code.find(addr)->second;
                    // spread the flag
                    for (address_t next : destructed->mNext) // TODO: not twice!
                    {
                        newHead.push_back(std::pair<address_t, address_t>(destructed->mAddress, next));
                    }
                }
            };

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
                    prevInfo->parent = proc;
                }
                
                shared<instrInfo_t> newInfo(new instrInfo_t);
                newInfo->CopyFrom(*prevInfo.get());
                
            again:
                //TODO goto ret
                
                std::set<x86_reg> reads = instr->ReadsRegisters();
                std::set<x86_reg> writes = instr->WritesRegisters();
                bool forceSave = false;
                bool needsCf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_CF | X86_EFLAGS_TEST_CF);
                bool needsZf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_ZF | X86_EFLAGS_TEST_ZF);
                bool needsOf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_OF | X86_EFLAGS_TEST_OF);
                bool needsSf = instr->mDetail.eflags & (X86_EFLAGS_PRIOR_SF | X86_EFLAGS_TEST_SF);
                
                newInfo->flagCarry.needed = needsCf;
                newInfo->flagZero.needed = needsZf;
                newInfo->flagOverflow.needed = needsOf;
                newInfo->flagSign.needed = needsSf;
                
                // RET
                if (instr->mId == X86_INS_RETF || instr->mId == X86_INS_RET)
                {
                    switch (req)
                    {
                        case procRequest_t::returnNone:
                            break;
                        case procRequest_t::returnZero:
                            forceSave = true;
                            needsZf = true;
                            break;
                        case procRequest_t::returnCarry:
                            forceSave = true;
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
                        // condition covered, do not use simple flow
                    }
                }
                if (needsCf)
                {
                    ClearChildren(NeedsFlag(code, info->code, newInfo, newInfo->flagCarry, instr, tempIndexCf, forceSave));
                    if (verbose)
                        printf("(cf=%s) ", newInfo->flagCarry.variableRead.c_str());
                }
                if (needsZf)
                {
                    ClearChildren(NeedsFlag(code, info->code, newInfo, newInfo->flagZero, instr, tempIndexZf, forceSave));
                    if (verbose)
                        printf("(zf=%s) ", newInfo->flagZero.variableRead.c_str());
                }
                if (needsSf)
                    ClearChildren(NeedsFlag(code, info->code, newInfo, newInfo->flagSign, instr, tempIndexSf, forceSave));
                if (needsOf)
                    ClearChildren(NeedsFlag(code, info->code, newInfo, newInfo->flagOverflow, instr, tempIndexOf, forceSave));
                
                auto applyFlags = [&](char type, uint64_t modifyMask, uint64_t setMask, instrInfo_t::instrInfoFlag_t& flag)
                {
                    // TODO: Temp workaround, CALL sets all flags!
                    // TODO: interrupt could also update some flags
                    if (instr->mId == X86_INS_INT || instr->mId == X86_INS_CALL || (instr->mDetail.eflags & (modifyMask | setMask)))
                    {
                        if (verbose)
                            printf("(set %cf) ", type);

                        flag.type = type;
                        flag.wasWritten = true;
//                        flag.lastSet = {instr->mAddress}; // gabo!
//                        flag.lastSetInsn = instr->mId;
                        flag.willSet = {instr->mAddress}; // gabo!
                        flag.willSetInsn = instr->mId;

                        flag.depends[0].type = X86_OP_INVALID;
                        flag.depends[1].type = X86_OP_INVALID;
                        flag.dirty[0] = false;
                        flag.dirty[1] = false;
                        flag.dirty[2] = false;
                        
                        flag.isDestructive = false;
//                        flag.save = false; // TODO: do not clear save flag in second pass!
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
                    newInfo->reg[r].wasRead = true;
                
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
                    newInfo->reg[r].wasWritten = true;
                
                // TODO: save flag is lost in second pass!!!
                applyFlags('c', X86_EFLAGS_MODIFY_CF, X86_EFLAGS_RESET_CF | X86_EFLAGS_SET_CF, newInfo->flagCarry);
                applyFlags('z', X86_EFLAGS_MODIFY_ZF, X86_EFLAGS_RESET_ZF | X86_EFLAGS_SET_ZF, newInfo->flagZero);
                applyFlags('o', X86_EFLAGS_MODIFY_OF, X86_EFLAGS_RESET_OF | X86_EFLAGS_SET_OF, newInfo->flagOverflow);
                applyFlags('s', X86_EFLAGS_MODIFY_SF, X86_EFLAGS_RESET_SF | X86_EFLAGS_SET_SF, newInfo->flagSign);
                
                switch (instr->mId)
                {
                    case X86_INS_STC:
                    case X86_INS_CLC:
                    case X86_INS_CMC:
                        newInfo->flagCarry.savedVisibly = true;
                        break;
                    case X86_INS_SHL:
                    case X86_INS_SHR:
                    case X86_INS_ADD:
                    case X86_INS_ADC:
                    case X86_INS_SUB:
                    case X86_INS_SBB:
                        newInfo->flagCarry.isDestructive = true;
                        newInfo->flagCarry.dirty[2] = true;
                        break;
                    default:
                        //                        newInfo->flagCarry.isDestructive = false;
                        break;
                }
                
                if (verbose)
                    printf("\n");

                if (instr->mAddress.offset == 0x557)
                {
                    int f=9;
                }

                newInfo->stackDepth = prevInfo->stackDepth + instr->mTemplate.stack;
                // update info, store
                bool forceScan = false;
                auto mergeInfoIt = info->code.find(link.second);
                if (mergeInfoIt != info->code.end())
                {
                    if (verbose)
                        printf("* merge %x->%x: ",link.first.linearOffset(), link.second.linearOffset());

                    if (mergeInfoIt->second->MergeMultiFlag(newInfo))
                    {
                        if (verbose)
                            printf("* multi flag\n");

                        // .save attribute is saved, but next pass will clear it!!
                        newInfo = mergeInfoIt->second;
                        goto again;
                    } else
                        if (verbose)
                            printf("* no multi flag, ");

                        if (mergeInfoIt->second->Merge(newInfo))
                        {
                            if (verbose)
                                printf("* force scan\n");
                            forceScan = true;
                        }
                    if (verbose)
                        printf("* ok\n");
                } else
                    info->code.insert(std::pair<address_t, shared<instrInfo_t>>(link.second, newInfo));
                
                // TODO: HIGH not working when going backward with new flag last set
                for (address_t next : instr->mNext)
                {
                    if (forceScan || info->code.find(next) == info->code.end())
                        newHead.push_back(std::pair<address_t, address_t>(link.second, next));
                }
            }
            head = newHead;
        }

        // BAD, collect all RET, and merge
        PostProcess(tracer, info, req);
        mInfos.insert(std::pair<address_t, shared<info_t>>(proc, info));
    }
    
    std::set<address_t, cmp_adress_t> NeedsFlag(std::map<address_t, shared<CapInstr>, cmp_adress_t>& code, std::map<address_t, shared<instrInfo_t>, cmp_adress_t>& info, shared<instrInfo_t> newInfo, instrInfo_t::instrInfoFlag_t& flag, shared<CapInstr> instr, std::map<address_t, int, cmp_adress_t>& tempIndex, bool forceSave)
    {
        std::set<address_t, cmp_adress_t> clearChildren;
        std::string defaultFlag;
        switch (flag.type)
        {
            case 'z': defaultFlag = "flags.zero"; break;
            case 'c': defaultFlag = "flags.carry"; break;
            case 's': defaultFlag = "flags.sign"; break;
            case 'o': defaultFlag = "flags.overflow"; break;
            default:
                assert(0);
        }

        std::string defaultPrefix;
        switch (flag.type)
        {
            case 'z': defaultPrefix = "temp_zf"; break;
            case 'c': defaultPrefix = "temp_cf"; break;
            case 's': defaultPrefix = "temp_sf"; break;
            case 'o': defaultPrefix = "temp_of"; break;
            default:
                assert(0);
        }

        for (address_t o : flag.lastSet)
        {
            shared<CapInstr> oi = code.find(o)->second;
            if (oi->mId == X86_INS_CALL)
            {
                switch (flag.type)
                {
                    case 'z':
                        if (oi->IsDirectCall())
                            AddProcRequest(newInfo, oi->CallTarget(), procRequest_t::returnZero);
                        else
                            newInfo->stop = "callee must return zero";
                        break;
                    case 'c':
                        if (oi->IsDirectCall())
                            AddProcRequest(newInfo, oi->CallTarget(), procRequest_t::returnCarry);
                        else
                            newInfo->stop = "callee must return carry";
                        break;
                    default:
                        assert(0);
                }

            }
        }
        
        if (flag.saved)
        {
            assert(flag.lastSet.size() == 1);
            address_t setflag = *flag.lastSet.begin();
            shared<instrInfo_t> setflaginfo = info.find(setflag)->second;
            flag.variableRead = setflaginfo->GetFlag(flag.type).variableWrite;
        }
        
        if (flag.lastSet.size() == 1)
        {
            if (flag.dirty[0] || flag.dirty[1])
            {
                address_t setFlagAddr = *flag.lastSet.begin();
                shared<instrInfo_t> setFlagInfo = info.find(setFlagAddr)->second;
                if (!setFlagInfo->GetFlag(flag.type).save)
                {
                    flag.variableRead = defaultFlag;
                    setFlagInfo->GetFlag(flag.type).variableWrite = flag.variableRead;
                    setFlagInfo->GetFlag(flag.type).save = true;
                    setFlagInfo->GetFlag(flag.type).savedFor = instr->mAddress;
                    clearChildren.insert(setFlagAddr);
                }
            }
            
            address_t ls = *flag.lastSet.begin();
            shared<instrInfo_t> destructive = info.find(ls)->second;
            if (destructive->GetFlag(flag.type).isDestructive)
            {
                if (!destructive->GetFlag(flag.type).save)
                {
                    flag.variableRead = TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
                    destructive->GetFlag(flag.type).variableWrite = flag.variableRead;
                    destructive->GetFlag(flag.type).save = true;
                    destructive->GetFlag(flag.type).savedFor = instr->mAddress;
                    clearChildren.insert(ls);
                }
            } else if (forceSave)
            {
                if (!destructive->GetFlag(flag.type).savedVisibly)
                {
                    destructive->GetFlag(flag.type).variableWrite = defaultFlag;
                    destructive->GetFlag(flag.type).save = true;
                    destructive->GetFlag(flag.type).savedFor = instr->mAddress;
                }
            }
        }
        
        if (flag.lastSet.size() > 1)
        {
            std::string variable = TempVarFor(tempIndex, defaultPrefix, instr->mAddress);
            flag.variableRead = variable;
            
            for (address_t setFlagAddr : flag.lastSet)
            {
                shared<instrInfo_t> setFlagInfo = info.find(setFlagAddr)->second;
                if (!setFlagInfo->GetFlag(flag.type).save)
                {
                    setFlagInfo->GetFlag(flag.type).variableWrite = flag.variableRead;
                    setFlagInfo->GetFlag(flag.type).save = true;
                    setFlagInfo->GetFlag(flag.type).savedFor = instr->mAddress;
                    //ClearChildren(setZeroAddr);
                    clearChildren.insert(setFlagAddr);
                }
            }
        }
        flag.wasRead = true;
        return clearChildren;
    }

    void PostProcess(shared<CTracer> tracer, shared<info_t> info, procRequest_t req)
    {
        std::map<address_t, shared<CapInstr>, cmp_adress_t> code = tracer->GetCode();
        info->code[code.rbegin()->first]->isLast = true;

        FindInfiniteLoops(tracer, info);
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
        
        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                shared<CapInstr> pinstr = p.second;
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
