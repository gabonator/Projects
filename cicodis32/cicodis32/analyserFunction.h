//
//  analyserFunction.h
//  cicodis32
//
//  Created by Gabriel Valky on 16/07/2025.
//

// FunctionAnalyser - traversing single function code and filling in instrInfo structure
class FunctionAnalyser : public ProgramAnalyser {
protected:
    std::map<address_t, int, cmp_adress_t> tempIndexPrecond, tempIndexZf, tempIndexCf, tempIndexSf, tempIndexOf;
    bool verbose{false};

public:
    FunctionAnalyser(Options& options) : ProgramAnalyser(options)
    {
        verbose = mOptions.verbose;
    }

    virtual std::set<address_t, cmp_adress_t> AnalyseInstruction(shared<instrInfo_t> info, shared<CapInstr> instr, const funcInfo_t& func, std::map<address_t, shared<instrInfo_t>, cmp_adress_t>& code, std::map<address_t, shared<CapInstr>, cmp_adress_t>& instructions) = 0;
    
    virtual void AnalyseProc(address_t proc, procRequest_t req)
    {
        shared<CTracer> tracer = check(mMethods.find(proc), mMethods.end())->second;
        std::map<address_t, shared<CapInstr>, cmp_adress_t> code = tracer->GetCode();
        std::vector<std::pair<address_t, address_t>> head({{address_t(), tracer->Address()}});

        tempIndexPrecond.clear();
        tempIndexZf.clear();
        tempIndexCf.clear();
        tempIndexSf.clear();
        tempIndexOf.clear();

        shared<info_t> info(new info_t);
        info->func.request = req;
        info->func.callConv = GetCallConvention(code);
        
        if (verbose)
            DumpCode(proc, code);

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
                }
                
                shared<instrInfo_t> newInfo(new instrInfo_t);
                newInfo->CopyFrom(prevInfo);
                
            again:
                std::set<address_t, cmp_adress_t> clearInsns = AnalyseInstruction(newInfo, instr, info->func, info->code, code);
                
                for (address_t addr : clearInsns)
                {
                     shared<CapInstr> destructed = code.find(addr)->second;
                     // spread the flag
                     for (address_t next : destructed->mNext) // TODO: not twice!
                         newHead.push_back(std::pair<address_t, address_t>(destructed->mAddress, next));
                 }
        

                // update info, store
                bool forceScan = false;
                bool skipScan = false;
                auto mergeInfoIt = info->code.find(link.second);
                if (mergeInfoIt != info->code.end())
                {
                    if (verbose)
                        printf("* merge %x->%x: ",link.first.offset, link.second.offset);

                    // no need to add this info, just update old one
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
                        } else {
                            // identical
//                            skipScan = true;
//                            printf("* skip scan ");
                        }
                    if (verbose)
                        printf("* ok\n");
                } else  // TODO: remove, create dummy entries and merge all!
                    info->code.insert(std::pair<address_t, shared<instrInfo_t>>(link.second, newInfo));
                
                if (skipScan)
                    continue;
                
                // TODO: HIGH not working when going backward with new flag last set
                for (address_t next : instr->mNext)
                {
                    if (forceScan)
                        newHead.push_back(std::pair<address_t, address_t>(link.second, next));
                    else if (info->code.find(next) == info->code.end())
                        newHead.push_back(std::pair<address_t, address_t>(link.second, next));
                    else
                    {
//                        newHead.push_back(std::pair<address_t, address_t>(link.second, next));
                        /*
                        shared<instrInfo_t> advanceInfo(new instrInfo_t);
                        advanceInfo->CopyFrom(newInfo); // willset->lastset

                        auto mergeInfoIt = info->code.find(next);
                        printf("Existing target %x >", next.offset);
                        if (mergeInfoIt->second->MergeMultiFlag(advanceInfo))
                            newHead.push_back(std::pair<address_t, address_t>(link.second, next));
                         */
                    }
                    
                    //mergeInfoIt->second->MergeMultiFlag(newInfo)
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
        FindInfiniteLoops(tracer, info);
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

    void DumpCode(address_t proc, std::map<address_t, shared<CapInstr>, cmp_adress_t>& code)
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

    callConv_t GetCallConvention(const CTracer::code_t& code)
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
            return stack ? callConv_t::callConvShiftStackFar : callConv_t::callConvSimpleStackFar;
        }
        if (retNear > 0)
        {
            assert(retFar == 0);
            return stack ? callConv_t::callConvShiftStackNear : callConv_t::callConvSimpleStackNear;
        }
        return callConv_t::callConvUnknown;
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

    std::string TempVarFor(std::map<address_t, int, cmp_adress_t>& table, std::string prefix, address_t addr)
    {
        if (table.find(addr) == table.end())
            table.insert(std::pair<address_t, int>(addr, table.size()));

        int index = table.find(addr)->second;
        return index == 0 ? prefix : format("%s%d", prefix.c_str(), index);
    }
    
};


