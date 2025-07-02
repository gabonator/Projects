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
    enum {
        callConvUnknown = 0,
        callConvSimpleStackNear = 1,
        callConvSimpleStackFar = 2
    } callConv{callConvUnknown}; // TODO: move to func info!
    
    int stackDepth{0};
    struct instrInfoReg_t
    {
        bool wasRead{false};
        bool wasWritten{false};
    } reg[X86_REG_ENDING];
    
    struct instrInfoFlag_t {
        bool wasRead{false};
        bool wasWritten{false};
        bool isDestructive{false};
        bool save{false};
        bool saved{true};
        
        address_t lastSet;
        x86_insn lastSetInsn{X86_INS_INVALID};
        cs_x86_op depends[2] = {{.type = X86_OP_INVALID}};
        bool dirty[2] = {false, false};
        bool broken{false};
        
        void Dump()
        {
            if (!lastSet)
            {
                printf("not set");
                return;
            }
            printf("%c%c %x", wasRead ? 'R' : ' ', wasWritten ? 'W' : ' ', lastSet.offset);
            
            if (depends[0].type != X86_OP_INVALID)
                printf(" %s%c %s", Capstone->ToString(depends[0]).c_str(), dirty[0] ? '*' : ' ', Capstone->ToString(lastSetInsn));
            if (depends[1].type != X86_OP_INVALID)
                printf(" %s%c %s", Capstone->ToString(depends[1]).c_str(), dirty[1] ? '*' : ' ', Capstone->ToString(lastSetInsn));
        }
    } flagZero, flagCarry, flagOverflow, flagSign;
    
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
        
//        flagCarry.isDestructive = false; // do not spread!
        flagCarry.save = false; // do not spread!
        flagCarry.saved = o.flagCarry.saved | o.flagCarry.save;
        callConv = o.callConv;
    }
    void Dump()
    {
        printf("NEW stack: %d\n", stackDepth);
        printf("NEW flags: CF("); flagCarry.Dump();
        printf("), ZF("); flagZero.Dump();
        printf("), OF("); flagOverflow.Dump();
        printf("), SF("); flagSign.Dump();
        printf(")\n");
        printf("NEW reads: ");
        for (int i=0; i<X86_REG_ENDING; i++)
            if (reg[i].wasRead)
                printf("%s ", Capstone->ToString((x86_reg)i));
        printf("\n");
        printf("NEW writes: ");
        for (int i=0; i<X86_REG_ENDING; i++)
            if (reg[i].wasWritten)
                printf("%s ", Capstone->ToString((x86_reg)i));
        printf("\n");
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
        if (flagZero.lastSet != o->flagZero.lastSet)
            changed = flagZero.broken = true;
        if (flagCarry.lastSet != o->flagCarry.lastSet)
            changed = flagCarry.broken = true;
        if (flagOverflow.lastSet != o->flagOverflow.lastSet)
            changed = flagOverflow.broken = true;
        if (flagSign.lastSet != o->flagSign.lastSet)
            changed = flagSign.broken = true;
        return changed;
    }
};


class Analyser {
public:
    std::map<address_t, std::shared_ptr<CTracer>, cmp_adress_t> mMethods;
    struct info_t {
        std::map<address_t, shared<instrInfo_t>, cmp_adress_t> code;
        funcInfo_t summary;
    };
    std::map<address_t, std::shared_ptr<info_t>, cmp_adress_t> mInfos;

public:
    void RecursiveScan(address_t proc)
    {
        std::vector<address_t> methodsToProcess{proc};
        std::set<address_t, cmp_adress_t> methodsProcessed;
        while (!methodsToProcess.empty())
        {
            std::vector<address_t> newMethodsToProcess;
            for (address_t methodToProcess : methodsToProcess)
            {
                methodsProcessed.insert(methodToProcess);
                
                std::shared_ptr<CTracer> tracer(new CTracer);
                tracer->Trace(methodToProcess);
                mMethods.insert(std::pair<address_t, std::shared_ptr<CTracer>>(methodToProcess, tracer));
                for (address_t newCallTarget : tracer->GetCalls())
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
    void AnalyseProc(address_t proc)
    {
        const bool verbose{false};
        shared<CTracer> tracer = mMethods.find(proc)->second;
        std::map<address_t, shared<CapInstr>, cmp_adress_t> code = tracer->GetCode();
        shared<info_t> info(new info_t);
        std::vector<std::pair<address_t, address_t>> head({{address_t(), tracer->Address()}});
        funcInfo_t funcInfo;
        
        mInfos.clear();
        
        int retFar = 0, retNear = 0;
        for (const auto& p : code)
        {
            if (p.second->mId == X86_INS_RETF)
                retFar++;
            if (p.second->mId == X86_INS_RET)
                retNear++;
        }
        
        if (retFar > 0)
            assert(retNear == 0);
        if (retNear > 0)
            assert(retFar == 0);

        while (head.size())
        {
            std::vector<std::pair<address_t, address_t>> newHead;
            for (std::pair<address_t, address_t> link : head)
            {
                if (verbose)
                    printf("%x->%x: ", link.first.offset, link.second.offset);
                shared<CapInstr> instr = code.find(link.second)->second;
                if (verbose)
                    printf("    instr: %s\n", instr->AsString().c_str());

                shared<instrInfo_t> prevInfo;
                if (link.first)
                {
                    assert(info->code.find(link.first) != info->code.end());
                    prevInfo = info->code.find(link.first)->second;
                    assert(prevInfo);
                } else {
                    prevInfo = shared<instrInfo_t>(new instrInfo_t);
                    if (retFar)
                        prevInfo->callConv = instrInfo_t::callConvSimpleStackFar;
                    if (retNear)
                        prevInfo->callConv = instrInfo_t::callConvSimpleStackNear;
                }
                
                shared<instrInfo_t> newInfo(new instrInfo_t);
                newInfo->CopyFrom(*prevInfo.get());

                std::set<x86_reg> reads = instr->ReadsRegisters();
                std::set<x86_reg> writes = instr->WritesRegisters();
                if (instr->mDetail.eflags & (X86_EFLAGS_PRIOR_CF | X86_EFLAGS_TEST_CF))
                {
                    shared<instrInfo_t> destructive = info->code.find(newInfo->flagCarry.lastSet)->second;
                    if (destructive->flagCarry.isDestructive)
                        destructive->flagCarry.save = true;
                    newInfo->flagCarry.wasRead = true;
                }
                if (instr->mDetail.eflags & (X86_EFLAGS_PRIOR_ZF | X86_EFLAGS_TEST_ZF))
                    newInfo->flagZero.wasRead = true;
                if (instr->mDetail.eflags & (X86_EFLAGS_PRIOR_OF | X86_EFLAGS_TEST_OF))
                    newInfo->flagOverflow.wasRead = true;
                if (instr->mDetail.eflags & (X86_EFLAGS_PRIOR_SF | X86_EFLAGS_TEST_SF))
                    newInfo->flagSign.wasRead = true;

                auto applyFlags = [&](uint64_t modifyMask, instrInfo_t::instrInfoFlag_t& flag)
                {
                    // TODO: Temp workaround, CALL sets all flags!
                    // TODO: interrupt could also update some flags
                    if (instr->mId == X86_INS_INT || instr->mId == X86_INS_CALL || (instr->mDetail.eflags & modifyMask))
                    {
                        flag.wasWritten = true;
                        flag.lastSet = instr->mAddress;
                        flag.lastSetInsn = instr->mId;

                        flag.depends[0].type = X86_OP_INVALID;
                        flag.depends[1].type = X86_OP_INVALID;
                        flag.dirty[0] = false;
                        flag.dirty[1] = false;
                        
                        flag.isDestructive = false;
                        flag.save = false;

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

                applyFlags(X86_EFLAGS_MODIFY_CF | X86_EFLAGS_RESET_CF | X86_EFLAGS_SET_CF, newInfo->flagCarry);
                applyFlags(X86_EFLAGS_MODIFY_ZF | X86_EFLAGS_RESET_ZF | X86_EFLAGS_SET_ZF, newInfo->flagZero);
                applyFlags(X86_EFLAGS_MODIFY_OF | X86_EFLAGS_RESET_OF | X86_EFLAGS_SET_OF, newInfo->flagOverflow);
                applyFlags(X86_EFLAGS_MODIFY_SF | X86_EFLAGS_RESET_SF | X86_EFLAGS_SET_SF, newInfo->flagSign);

                switch (instr->mId)
                {
                    case X86_INS_SHL:
                    case X86_INS_SHR:
                        newInfo->flagCarry.isDestructive = true;
                        break;
                    default:
//                        newInfo->flagCarry.isDestructive = false;
                        break;
                }
                
                newInfo->stackDepth = prevInfo->stackDepth + instr->mTemplate.stack;
                // update info, store
                bool forceScan = false;
                auto mergeInfoIt = info->code.find(link.second);
                if (mergeInfoIt != info->code.end())
                {
//                    printf("\nmerging ============= OLD\n");
//                    info->code.find(link.second)->second->Dump();
//                    printf("\nmerging ============= NEW\n");
//                    newInfo->Dump();
                    assert(!newInfo->flagCarry.save && !mergeInfoIt->second->flagCarry.save);
                    if (mergeInfoIt->second->Merge(newInfo))
                    {
                        // invalidate all paths
                        forceScan = true;
                    }
                } else
                    info->code.insert(std::pair<address_t, shared<instrInfo_t>>(link.second, newInfo));
                
                // TODO: cycle!
                for (address_t next : instr->mNext)
                {
                    if (forceScan || info->code.find(next) == info->code.end())
                        newHead.push_back(std::pair<address_t, address_t>(link.second, next));
                }
            }
            head = newHead;
        }
        // BAD, collect all RET, and merge
        mInfos.insert(std::pair<address_t, shared<info_t>>(proc, info));
    }
};
