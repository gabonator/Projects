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
    //ritesZero = false;
// TODO: flags visibility!
//    uint8_t readsReg[X86_REG_ENDING] = {0};
//    uint8_t writesReg[X86_REG_ENDING] = {0};

};

struct instrInfo_t {
//    bool valid{false};
//    uint8_t readsReg[X86_REG_ENDING] = {0};
//    uint8_t writesReg[X86_REG_ENDING] = {0};
//    bool readsCarry = false;
//    bool readsZero = false;
//    bool writesCarry = false;
//    bool writesZero = false;

    int stackDepth{0};
    struct instrInfoReg_t
    {
        bool wasRead{false};
//        bool wasReadPartially{false};
        bool wasWritten{false};
//        bool wasWrittenPartially{false};
//        address_t lastSet;
//        bool lastSetDirty{false};
    } reg[X86_REG_ENDING];
    
    struct instrInfoFlag_t {
        bool wasRead{false};
//        bool wasReadPartially{false};
        bool wasWritten{false};
//        bool wasWrittenPartially{false};
        
        address_t lastSet;
        x86_insn lastSetInsn;
        x86_reg dependsRegisters[2] = {X86_REG_INVALID, X86_REG_INVALID};
        bool dirtyRegisters[2] = {false, false};
        bool broken{false};
        
        void Dump()
        {
            if (!lastSet)
            {
                printf("not set");
                return;
            }
            printf("%c%c %x", wasRead ? 'R' : ' ', wasWritten ? 'W' : ' ', lastSet.offset);
            if (dependsRegisters[0] != X86_REG_INVALID)
                printf(" %s%c %s", Capstone->ToString(dependsRegisters[0]), dirtyRegisters[0] ? '*' : ' ', Capstone->ToString(lastSetInsn));
            if (dependsRegisters[1] != X86_REG_INVALID)
                printf(" %s%c %s", Capstone->ToString(dependsRegisters[1]), dirtyRegisters[1] ? '*' : ' ', Capstone->ToString(lastSetInsn));
        }
    } flagZero, flagCarry, flagOverflow;
    
    void CopyFrom(const instrInfo_t& o)
    {
//        readsCarry = o.readsCarry;
//        readsZero = o.readsZero;
//        writesCarry = o.writesCarry;
//        writesZero = o.writesZero;
        stackDepth = o.stackDepth;
        for (int i=0; i<X86_REG_ENDING; i++)
        {
            reg[i] = o.reg[i];
        }
        flagZero = o.flagZero;
        flagCarry = o.flagCarry;
        flagOverflow = o.flagOverflow;
    }
    void Dump()
    {
        printf("NEW stack: %d\n", stackDepth);
        printf("NEW flags: CF("); flagCarry.Dump();
        printf("), ZF("); flagZero.Dump();
        printf("), OF("); flagOverflow.Dump();
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
    void Merge(shared<instrInfo_t> o)
    {
        for (int i=0; i<X86_REG_ENDING; i++)
        {
            reg[i].wasRead |= o->reg[i].wasRead;
            reg[i].wasWritten |= o->reg[i].wasWritten;
        }
        if (flagZero.lastSet != o->flagZero.lastSet)
            flagZero.broken = true;
        if (flagCarry.lastSet != o->flagCarry.lastSet)
            flagCarry.broken = true;
        if (flagOverflow.lastSet != o->flagOverflow.lastSet)
            flagOverflow.broken = true;
    }
};


class Analyser {
public:
    uint8_t mRegMap[X86_REG_ENDING][X86_REG_ENDING] = {};
    std::map<address_t, std::shared_ptr<CTracer>, cmp_adress_t> mMethods;
    struct info_t {
        std::map<address_t, shared<instrInfo_t>, cmp_adress_t> code;
        funcInfo_t summary;
    };
    std::map<address_t, std::shared_ptr<info_t>, cmp_adress_t> mInfos;

public:
    Analyser()
    {
        mRegMap[X86_REG_EAX][X86_REG_AX] = 1;
        mRegMap[X86_REG_EAX][X86_REG_AL] = 1;
        mRegMap[X86_REG_EAX][X86_REG_AH] = 1;
        mRegMap[X86_REG_AX][X86_REG_AL] = 1;
        mRegMap[X86_REG_AX][X86_REG_AH] = 1;
        mRegMap[X86_REG_EBX][X86_REG_BX] = 1;
        mRegMap[X86_REG_EBX][X86_REG_BL] = 1;
        mRegMap[X86_REG_EBX][X86_REG_BH] = 1;
        mRegMap[X86_REG_BX][X86_REG_BL] = 1;
        mRegMap[X86_REG_BX][X86_REG_BH] = 1;
        mRegMap[X86_REG_ECX][X86_REG_CX] = 1;
        mRegMap[X86_REG_ECX][X86_REG_CL] = 1;
        mRegMap[X86_REG_ECX][X86_REG_CH] = 1;
        mRegMap[X86_REG_CX][X86_REG_CL] = 1;
        mRegMap[X86_REG_CX][X86_REG_CH] = 1;
        mRegMap[X86_REG_EDX][X86_REG_DX] = 1;
        mRegMap[X86_REG_EDX][X86_REG_CL] = 1;
        mRegMap[X86_REG_EDX][X86_REG_CH] = 1;
        mRegMap[X86_REG_DX][X86_REG_DL] = 1;
        mRegMap[X86_REG_DX][X86_REG_DH] = 1;

    }
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
        shared<CTracer> tracer = mMethods.find(proc)->second;
        std::map<address_t, shared<CapInstr>, cmp_adress_t> code = tracer->GetCode();
        shared<info_t> info(new info_t);
        std::vector<std::pair<address_t, address_t>> head({{address_t(), tracer->Address()}});
        funcInfo_t funcInfo;
        
        while (head.size())
        {
            std::vector<std::pair<address_t, address_t>> newHead;
            for (std::pair<address_t, address_t> link : head)
            {
                shared<instrInfo_t> prevInfo;
                if (link.first)
                {
                    assert(info->code.find(link.first) != info->code.end());
                    prevInfo = info->code.find(link.first)->second;
                    assert(prevInfo);
                } else {
                    prevInfo = shared<instrInfo_t>(new instrInfo_t);
                }
                
                shared<instrInfo_t> newInfo(new instrInfo_t);
                newInfo->CopyFrom(*prevInfo.get());

                shared<CapInstr> instr = code.find(link.second)->second;
                
                printf("%x->%x: ", link.first.offset, link.second.offset);
                printf("    instr: %s\n", instr->AsString().c_str());
                
                std::set<x86_reg> reads = instr->ReadsRegisters();
                std::set<x86_reg> writes = instr->WritesRegisters();
                if (instr->mDetail.eflags & X86_EFLAGS_PRIOR_CF)
                    newInfo->flagCarry.wasRead = true;
                if (instr->mDetail.eflags & X86_EFLAGS_PRIOR_ZF)
                    newInfo->flagZero.wasRead = true;
                if (instr->mDetail.eflags & X86_EFLAGS_PRIOR_OF)
                    newInfo->flagOverflow.wasRead = true;

                auto applyFlags = [&](uint64_t modifyMask, instrInfo_t::instrInfoFlag_t& flag)
                {
                    if (instr->mDetail.eflags & modifyMask)
                    {
                        flag.wasWritten = true;
                        flag.lastSet = instr->mAddress;
                        flag.lastSetInsn = instr->mId;
                        switch (reads.size())
                        {
                            case 0:
                                flag.dependsRegisters[0] = X86_REG_INVALID;
                                flag.dependsRegisters[1] = X86_REG_INVALID;
                                flag.dirtyRegisters[0] = false;
                                flag.dirtyRegisters[1] = false;
                                break;
                            case 1:
                                flag.dependsRegisters[0] = *reads.begin();
                                flag.dependsRegisters[1] = X86_REG_INVALID;
                                flag.dirtyRegisters[0] = false;
                                flag.dirtyRegisters[1] = false;
                                break;
                            case 2:
                                flag.dependsRegisters[0] = *reads.begin();
                                flag.dependsRegisters[1] = *(std::next(reads.begin(), 1));
                                flag.dirtyRegisters[0] = false;
                                flag.dirtyRegisters[1] = false;
                                break;
                        }
                    }
                };
                auto checkDirtyFlags = [&](instrInfo_t::instrInfoFlag_t& flag, x86_reg reg)
                {
                    // TODO: int -> dirty all!
                    // depends: ah, reg: eax -> true
                    // depends: eax, reg: ah -> true
                    // depends: eax, reg: ah -> true
                    if (mRegMap[flag.dependsRegisters[0]][reg] || mRegMap[reg][flag.dependsRegisters[0]])
                        flag.dirtyRegisters[0] = true;
                    if (mRegMap[flag.dependsRegisters[1]][reg] || mRegMap[reg][flag.dependsRegisters[0]])
                        flag.dirtyRegisters[1] = true;
                };
                for (x86_reg r : reads)
                {
                    if (!prevInfo->reg[r].wasWritten)
                        funcInfo.readsReg[r] = true;
                    newInfo->reg[r].wasRead = true;

                }
                if (!writes.empty())
                {
                    assert(writes.size() == 1);
                    checkDirtyFlags(newInfo->flagCarry, *writes.begin());
                    checkDirtyFlags(newInfo->flagZero, *writes.begin());
                    checkDirtyFlags(newInfo->flagOverflow, *writes.begin());
                    //printf("%s; writes %s\n", instr->AsString().c_str(), Capstone->ToString((x86_reg)*writes.begin()));
                    funcInfo.writesReg[*writes.begin()] = true;
                    newInfo->reg[*writes.begin()].wasWritten = true;
                }

                applyFlags(X86_EFLAGS_MODIFY_CF | X86_EFLAGS_RESET_CF | X86_EFLAGS_SET_CF, newInfo->flagCarry);
                applyFlags(X86_EFLAGS_MODIFY_ZF | X86_EFLAGS_RESET_ZF | X86_EFLAGS_SET_ZF, newInfo->flagZero);
                applyFlags(X86_EFLAGS_MODIFY_OF | X86_EFLAGS_RESET_OF | X86_EFLAGS_SET_OF, newInfo->flagOverflow);

                newInfo->stackDepth = prevInfo->stackDepth + instr->mTemplate.stack;
                // update info, store
                auto mergeInfoIt = info->code.find(link.second);
                if (mergeInfoIt != info->code.end())
                {
//                    printf("\nmerging ============= OLD\n");
//                    info->code.find(link.second)->second->Dump();
//                    printf("\nmerging ============= NEW\n");
//                    newInfo->Dump();
                    mergeInfoIt->second->Merge(newInfo);
                } else
                    info->code.insert(std::pair<address_t, shared<instrInfo_t>>(link.second, newInfo));
                
                //if (instr->mId == X86_INS_RET)
                if (0)
                {
                    //newInfo->Dump();
                }
                // TODO: cycle!
                for (address_t next : instr->mNext)
                    newHead.push_back(std::pair<address_t, address_t>(link.second, next));
            }
            head = newHead;
        }
        // BAD, collect all RET, and merge
        mInfos.insert(std::pair<address_t, shared<info_t>>(proc, info));
    }
};
