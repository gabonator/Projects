//
//  printNice.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 19/12/2025.
//

class PrintIrCpp : public PrintIrBase {
public:
    PrintIrCpp(shared<Options> options) : PrintIrBase(options)
    {
        
    }
    
    virtual std::string OffsetRegister(std::string reg) override
    {
        return reg;
    }
    
    virtual std::string OffsetAsString(shared<OperandIr> op) override
    {
        bool mode16 = mOptions->arch == arch_t::arch16;
        
        std::string memOffset = "";
        if (!op->memOfsBase.empty())
            memOffset += OffsetRegister(op->memOfsBase);
        
        if (!op->memOfsIndex.empty())
        {
            if (!memOffset.empty())
                memOffset += " + ";
            memOffset += OffsetRegister(op->memOfsIndex);
        }
        if (op->memOfsScale != 1)
        {
            if (!memOffset.empty())
                memOffset += " * ";
            memOffset += format("%d", op->memOfsScale);
        }
        if (op->memOfsDisp != 0 || memOffset.empty())
        {
            if (memOffset.empty())
            {
                if (mode16)
                    memOffset += format("0x%04x", op->memOfsDisp & 0xffff);
                else
                    memOffset += format("0x%04x", op->memOfsDisp);
            } else {
                if (mode16)
                {
                    if ((uint16_t)op->memOfsDisp > (uint16_t)-100)
                        memOffset += format(" - %d", -op->memOfsDisp);
                    else
                        memOffset += format(" + %d", op->memOfsDisp & 0xffff);
                }
                else {
                    if (op->memOfsDisp >= 0)
                        memOffset += format(" + 0x%x", op->memOfsDisp);
                    else
                        memOffset += format(" - %d", -op->memOfsDisp);
                }
            }
        }
        return memOffset;
    }

    virtual std::string ToStringSetter(shared<OperandIr> op)
    {
        assert(op);
        switch (op->type)
        {
            case OperandIr::Type_t::Memory:
                    
                if (op->memSize == 1)
                    return format("    memoryASet(%s, %s, %%s);", op->memSegment.c_str(), OffsetAsString(op).c_str());
                else
                    return format("    memoryASet%d(%s, %s, %%s);", op->memSize*8, op->memSegment.c_str(), OffsetAsString(op).c_str());
            default:
                assert(0);
        }
        return "";
    }
    
    virtual std::string ToString(shared<OperandIr> op) override
    {
        assert(op);
        switch (op->type)
        {
            case OperandIr::Type_t::Memory:
                if (op->memSize == 1)
                    return format("memoryAGet(%s, %s)", op->memSegment.c_str(), OffsetAsString(op).c_str());
                else
                    return format("memoryAGet%d(%s, %s)", op->memSize*8, op->memSegment.c_str(), OffsetAsString(op).c_str());
            default:
                return PrintIrBase::ToString(op);
        }
    }

    virtual std::string ToString(const StatementIr& st) override
    {
        std::string suffix = "";
        if (st.suffix != 0)
            suffix = format("%d", st.suffix);
        
        switch (st.type)
        {
            case StatementIr::Type_t::Assignment:
                if (st.opd->type == OperandIr::Type_t::Memory)
                {
                    if (st.opin1)
                        return format(ToStringSetter(st.opd).c_str(), ToString(st.opin1).c_str());
                    else if (st.stmt1)
                        return format(ToStringSetter(st.opd).c_str(), ToString(*st.stmt1).c_str());
                    else
                        assert(0);
                }
                return PrintIrBase::ToString(st);

            case StatementIr::Type_t::Binary:
                {
                    std::string leftStr, rightStr;
                    
                    // Handle left side
                    if (st.stmt1)
                        leftStr = ToString(*st.stmt1);
                    else if (st.opin1)
                        leftStr = ToString(st.opin1);
                    else
                        assert(0);
                    
                    // Handle right side
                    if (st.stmt2)
                        rightStr = ToString(*st.stmt2);
                    else if (st.opin2)
                        rightStr = ToString(st.opin2);
                    else
                        assert(0);
                    
                    if (leftStr.find(" ") != std::string::npos && !leftStr.starts_with("memory") && st.oper != "?")
                        leftStr = std::string("(") + leftStr + ")";
                    if (rightStr.find(" ") != std::string::npos && rightStr.find(":") == std::string::npos && !rightStr.starts_with("memory"))
                        rightStr = std::string("(") + rightStr + ")";

                    if (!st.opd)
                        return format("%s %s %s", leftStr.c_str(), st.oper.c_str(), rightStr.c_str());
                    else if (st.opd->type == OperandIr::Type_t::Memory) // use memory getter/setter
                        return ToString(StatementIr{
                            .type = StatementIr::Type_t::Assignment,
                            .opd = st.opd,
                            .stmt1 = std::make_shared<StatementIr>(StatementIr{
                                .type = StatementIr::Type_t::Binary,
                                .opin1 = st.opin1,
                                .opin2 = st.opin2,
                                .stmt1 = st.stmt1,
                                .stmt2 = st.stmt2,
                                .oper = st.oper
                            })});
                    else if (ToString(st.opd) == leftStr)
                    {
                        // Assignment shortcuts (+=, ++, etc.)
                        if (st.opin2 && st.opin2->type == OperandIr::Type_t::Const && st.opin2->constValue == 1 && st.oper == "+")
                            return format("    %s++;", ToString(st.opd).c_str());
                        else if (st.opin2 && st.opin2->type == OperandIr::Type_t::Const && st.opin2->constValue == 1 && st.oper == "-")
                            return format("    %s--;", ToString(st.opd).c_str());
                        else
                            return format("    %s %s= %s;", ToString(st.opd).c_str(), st.oper.c_str(), rightStr.c_str());
                    }
                    else
                        return format("    %s = %s %s %s;", ToString(st.opd).c_str(), leftStr.c_str(), st.oper.c_str(), rightStr.c_str());
                }
                break;

            case StatementIr::Type_t::Function:
            {
                std::string repeat = st.repeat.empty() ? "" : st.repeat + " ";
                std::string rhs;
                
                if (st.opin1 && st.opin2)
                    rhs = format("%s%s(%s, %s)", ProcessFuncName(st).c_str(), ProcessFuncTemplate(st).c_str(), ToString(st.opin1).c_str(), ToString(st.opin2).c_str());
                else if (st.opin1)
                    rhs = format("%s%s(%s)", ProcessFuncName(st).c_str(), ProcessFuncTemplate(st).c_str(), ToString(st.opin1).c_str());
                else
                    rhs = format("%s%s()", ProcessFuncName(st).c_str(), ProcessFuncTemplate(st).c_str());
                
                if (st.opd && st.opd->type == OperandIr::Type_t::Memory)
                    return repeat + format(ToStringSetter(st.opd).c_str(), rhs.c_str());
                
                return PrintIrBase::ToString(st);
            }
            case StatementIr::Type_t::Condition:
                assert(st.stConditionExpr && st.stConditionTrue);
                if (st.stConditionExpr->type == StatementIr::Type_t::Compare &&
                    st.stConditionExpr->opin1 &&
                    st.stConditionExpr->opin2 &&
                    st.stConditionExpr->opin2->type == OperandIr::Type_t::Const &&
                    st.stConditionExpr->opin2->constValue == 0)
                {
                    if (st.stConditionExpr->oper == "==")
                        return format("    if (!%s)\n    %s", ToString(st.stConditionExpr->opin1).c_str(), ToString(*st.stConditionTrue).c_str());
                    if (st.stConditionExpr->oper == "!=")
                        return format("    if (%s)\n    %s", ToString(st.stConditionExpr->opin1).c_str(), ToString(*st.stConditionTrue).c_str());
                }
                return PrintIrBase::ToString(st);
            default:
                return PrintIrBase::ToString(st);
        }
    }
};

class PrintIrCppHints : public PrintIrCpp {
    std::vector<hint_t> activeProgHints; // TODO: ptr
    std::vector<hint_t> activeStatementHints; // TODO: ptr
    shared<Analyser::info_t> instructions;
    shared<instrInfo_t> instruction;

public:
    PrintIrCppHints(shared<Options> options) : PrintIrCpp(options)
    {
    }

    virtual void PrepareProgram(shared<ProcIr> prog)
    {
        activeProgHints.clear();
        if (prog->lines.size())
        {
            address_t begin = prog->lines.begin()->address;
            address_t end = prog->lines.rbegin()->address;
            for (const hint_t& h : mOptions->memHints)
            {
                if (h.end < begin || h.begin > end)
                    continue;
                activeProgHints.push_back(h);
            }
        }
    }
    
    virtual void PrintProgram(shared<ProcIr> prog, shared<Analyser::info_t> info) override
    {
        instructions = info;
        PrepareProgram(prog);
        PrintIrCpp::PrintProgram(prog, info);
    }
    
    virtual void PrepareStatement(const StatementIr& st)
    {
        instruction = instructions->code.find(st.address)->second;
        activeStatementHints.clear();
        for (const hint_t& h : activeProgHints)
            if (h.begin <= st.address && st.address <= h.end)
                activeStatementHints.push_back(h);
    }
    
    virtual std::string ToString(const StatementIr& st) override
    {
        // internal operands do not have address set
        if (st.address.isValid())
            PrepareStatement(st);
        return PrintIrCpp::ToString(st);
    }
    
    std::string GetHintForSegment(std::string seg, std::string base)
    {
        for (const hint_t& h : activeStatementHints)
        {
            if (h.pattern.find(",") == std::string::npos)
            {
                if (h.pattern == seg)
                    return h.getTypeAsString(false);
            } else {
                if (h.pattern == seg + ", " + base)
                    return h.getTypeAsString(false);
            }
        }
        if (mOptions->memHintDefault.isValid())
            return mOptions->memHintDefault.getTypeAsString(false);
        return "A";
    }
    
    std::string GetHintForTemplate(std::string templ)
    {
        for (const hint_t& h : activeStatementHints)
            if (h.pattern == templ)
                return h.getTypeAsString(true) + h.getDirectionAsString() + "_" + templ;
        if (mOptions->memHintDefault.isValid())
            return mOptions->memHintDefault.getTypeAsString(true) + mOptions->memHintDefault.getDirectionAsString() + "_" + templ;
        return templ;
    }
    
    virtual std::string ToStringSetter(shared<OperandIr> op) override
    {
        assert(op);
        switch (op->type)
        {
            case OperandIr::Type_t::Memory:
                if (op->memSize == 1)
                    return format("    memory%sSet(%s, %s, %%s);", GetHintForSegment(op->memSegment, op->memOfsBase).c_str(), op->memSegment.c_str(), OffsetAsString(op).c_str());
                else
                    return format("    memory%sSet%d(%s, %s, %%s);", GetHintForSegment(op->memSegment, op->memOfsBase).c_str(), op->memSize*8, op->memSegment.c_str(), OffsetAsString(op).c_str());
            default:
                assert(0);
        }
        return "";
    }
    
    virtual std::string ToString(shared<OperandIr> op) override
    {
        assert(op);
        switch (op->type)
        {
            case OperandIr::Type_t::Memory:
                if (op->memSize == 1)
                    return format("memory%sGet(%s, %s)", GetHintForSegment(op->memSegment, op->memOfsBase).c_str(), op->memSegment.c_str(), OffsetAsString(op).c_str());
                else
                    return format("memory%sGet%d(%s, %s)", GetHintForSegment(op->memSegment, op->memOfsBase).c_str(), op->memSize*8, op->memSegment.c_str(), OffsetAsString(op).c_str());
            default:
                return PrintIrBase::ToString(op);
        }
    }

    virtual std::string ProcessFuncTemplate(const StatementIr& st) override
    {
        if (st.templ1.empty())
            return "";
        if (st.templ2.empty())
            return format("<%s>", GetHintForTemplate(st.templ1).c_str());
        return format("<%s, %s>", GetHintForTemplate(st.templ1).c_str(), GetHintForTemplate(st.templ2).c_str());
    }
    
    virtual std::string OffsetAsString(shared<OperandIr> op) override
    {
        if (mOptions->arch == arch_t::arch16)
            return PrintIrCpp::OffsetAsString(op);
        
        std::string memOffset = "";
        if (!op->memOfsBase.empty())
            memOffset += OffsetRegister(op->memOfsBase);
        
        if (!op->memOfsIndex.empty())
        {
            if (!memOffset.empty())
                memOffset += " + ";
            memOffset += OffsetRegister(op->memOfsIndex);
        }
        if (op->memOfsScale != 1)
        {
            if (!memOffset.empty())
                memOffset += " * ";
            memOffset += format("%d", op->memOfsScale);
        }
        if (op->memOfsDisp != 0 || memOffset.empty())
        {
            // worms2 trick
            // TODO: only when 6 byte long instr
            assert(instruction);
            if (op->memOfsDisp == 0x7fffffff)
            {
                // size=8, ofs=4
                // size=6, ofs=2
                int immOfs = instruction->instr->mSize-4;
                assert(instruction->instr->mBytes[immOfs+3] == 0x7f && instruction->instr->mBytes[immOfs+2] == 0xff && instruction->instr->mBytes[immOfs+1] == 0xff && instruction->instr->mBytes[immOfs] == 0xff);
                memOffset += format("%smemoryGet32(cs, 0x%x)", memOffset.empty() ? "" : " + ", instruction->instr->mAddress.linearOffset()+2);
            }
            else if (op->memOfsDisp >= 0)
                memOffset += format("%s0x%x", memOffset.empty() ? "" : " + ", op->memOfsDisp);
            else
                memOffset += format("%s%d", memOffset.empty() ? "-" : " - ", -op->memOfsDisp);
        }
        return memOffset;
    }

};

