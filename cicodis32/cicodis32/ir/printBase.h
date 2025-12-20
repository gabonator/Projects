//
//  print.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 09/12/2025.
//

class ProcIr {
public:
    address_t addr;
    std::string name;
    std::string info;
    std::vector<std::string> temps;
    std::vector<StatementIr> lines;
    bool labels;
};

class PrintIrBase {
protected:
    shared<Options> mOptions;
    
public:
    PrintIrBase(shared<Options> options) : mOptions(options)
    {
    }
    
    virtual std::string OffsetAsString(shared<OperandIr> op)
    {
        std::string memOffset = "";
        if (!op->memOfsBase.empty())
            memOffset += op->memOfsBase;
        
        if (!op->memOfsIndex.empty())
        {
            if (!memOffset.empty())
                memOffset += " + ";
            memOffset += op->memOfsIndex;
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
                memOffset += format("0x%04x", op->memOfsDisp);
            else
                memOffset += format(" + %d", op->memOfsDisp);
        }
        return memOffset;
    }
    
    virtual std::string SignedType(shared<OperandIr> op)
    {
        if (!op)
            return "";
        int sizeInBytes = 0;
        switch (op->type)
        {
            case OperandIr::Type_t::Memory:
                sizeInBytes = op->memSize;
                break;
            case OperandIr::Type_t::Register:
                sizeInBytes = op->regSize;
                break;
            case OperandIr::Type_t::Const:
                sizeInBytes = op->constValue != 0 ? op->constSize : 0;
                break;
            case OperandIr::Type_t::Variable:
                break;
            default:
                assert(0);
        }
        std::string prefix;
        switch (sizeInBytes)
        {
            case 0:
                prefix = "";
                break;
            case 1:
                prefix = "(char)";
                break;
            case 2:
                prefix = "(short)";
                break;
            default:
                assert(0);
        }
        return prefix + ToString(op);
    }

    virtual std::string ToString(shared<OperandIr> op)
    {
        assert(op);
        switch (op->type)
        {
            case OperandIr::Type_t::Const:
                switch (op->constSize)
                {
                    case -1:
                        return format("0x%x", op->constValue);
                    case 0:
                        return format("%d", op->constValue);
                    case 1:
                        return format("0x%02x", op->constValue & 0xff);
                    case 2:
                        return format("0x%04x", op->constValue & 0xffff);
                    case 4:
                        return format("0x%08x", op->constValue);
                    default:
                        assert(0);
                        return "";
                }
            case OperandIr::Type_t::Register:
                return op->regName;
            case OperandIr::Type_t::Memory:
                return format("memory%d(%s, %s)", op->memSize*8, op->memSegment.c_str(), OffsetAsString(op).c_str());
            case OperandIr::Type_t::String:
                return op->string;
            case OperandIr::Type_t::Operator:
                return op->oper;
            case OperandIr::Type_t::Variable:
                return op->variable;
            default:
                assert(0);
        }
        return "";
    }

    virtual void PrintProgram(shared<ProcIr> prog)
    {
        if (prog->info.empty())
            printf("void %s\n", prog->name.c_str());
        else
            printf("void %s // %s\n", prog->name.c_str(), prog->info.c_str());
        printf("{\n");
        for (auto t : prog->temps)
            printf("    bool %s;\n", t.c_str());
        for (auto l : prog->lines)
        {
            if (l.type != StatementIr::Type_t::Label && l.type != StatementIr::Type_t::Comment)
            {
                auto it = mOptions->inject.find(l.address);
                if (it != mOptions->inject.end())
                {
                    printf("    %s\n", it->second.c_str());
                }
            }
            PrintStatement(l);
        }
        printf("}\n");
    }
    
    virtual std::string ToString(const StatementIr& st)
    {
//        std::string suffix = "";
//        if (st.suffix != 0)
//            suffix = format("%d", st.suffix);
        
        switch (st.type)
        {
            case StatementIr::Type_t::Assignment:
                if (st.opin1)
                    return format("    %s = %s;", ToString(st.opd).c_str(), ToString(st.opin1).c_str());
                else if (st.stmt1)
                    return format("    %s = %s;", ToString(st.opd).c_str(), ToString(*st.stmt1).c_str());
                else
                    assert(0);
                break;
            case StatementIr::Type_t::Unary:
                if (st.stmt1)
                {
                    if (ToString(*st.stmt1).starts_with("flags.") || ToString(*st.stmt1).starts_with("!")) // TODO: ugly
                        return format("%s%s", st.oper.c_str(), ToString(*st.stmt1).c_str());
                    else
                        return format("%s(%s)", st.oper.c_str(), ToString(*st.stmt1).c_str());
                }
                else if (st.opin1)
                    return format("%s%s", st.oper.c_str(), ToString(st.opin1).c_str());
                else
                    assert(0);
                break;
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
                    
                    if (leftStr.find(" ") != std::string::npos && !leftStr.starts_with("memory"))
                        leftStr = std::string("(") + leftStr + ")";
                    if (rightStr.find(" ") != std::string::npos && !rightStr.starts_with("memory"))
                        rightStr = std::string("(") + rightStr + ")";
                    assert(!st.isSigned);

                    if (!st.opd)
                        return format("%s %s %s", leftStr.c_str(), st.oper.c_str(), rightStr.c_str());
                    else
                        return format("    %s = %s %s %s;", ToString(st.opd).c_str(), leftStr.c_str(), st.oper.c_str(), rightStr.c_str());
                }
                break;
            case StatementIr::Type_t::Copy:
                assert(st.isSigned && st.opin1);
                return SignedType(st.opin1);

            case StatementIr::Type_t::Function:
            {
                std::string rhs;
                
                if (st.opin1 && st.opin2)
                    rhs = format("%s(%s, %s)", ProcessFuncName(st).c_str(), ToString(st.opin1).c_str(), ToString(st.opin2).c_str());
                else if (st.opin1)
                    rhs = format("%s(%s)", ProcessFuncName(st).c_str(), ToString(st.opin1).c_str());
                else
                    rhs = format("%s()", ProcessFuncName(st).c_str());
                
                if (st.opd)
                    return format("    %s = %s;", ToString(st.opd).c_str(), rhs.c_str());
                else
                    return format("    %s;", rhs.c_str());
                break;
            }
            case StatementIr::Type_t::Condition:
                return format("    if (%s)\n    %s", ToString(*st.stConditionExpr).c_str(), ToString(*st.stConditionTrue).c_str());
            case StatementIr::Type_t::Compare:
                {
                    std::string leftStr, rightStr;
                    
                    if (st.stmt1)
                        leftStr = ToString(*st.stmt1);
                    else if (st.opin1)
                        leftStr = ToString(st.opin1);
                    else
                        return "true"; // Handle empty compare
                    
                    if (st.oper.empty())
                        return leftStr;
                    
                    if (st.stmt2)
                        rightStr = ToString(*st.stmt2);
                    else if (st.opin2)
                        rightStr = ToString(st.opin2);
                    else
                        assert(0);
                    
                    // Add cast prefix for signed comparisons
                    if (st.isSigned)
                    {
                        if (st.opin1 && st.opin2)
                        {
                            std::string leftSigned = SignedType(st.opin1);
                            std::string rightSigned = SignedType(st.opin2);
                            
                            return format("%s %s %s",
                                          leftSigned.c_str(),
                                          st.oper.c_str(),
                                          rightSigned.c_str());
                        } else {
                            return format("(?)%s %s (?)%s",
                                          leftStr.c_str(),
                                          st.oper.c_str(),
                                          rightStr.c_str());
                        }
                        assert(0);
                    }
                    
                    return format("%s %s %s", leftStr.c_str(), st.oper.c_str(), rightStr.c_str());
                }
            case StatementIr::Type_t::DirectJump:
                return format("    goto loc_%x;", st.target.linearOffset());
            case StatementIr::Type_t::DirectCall:
                return format("    sub_%x();", st.target.linearOffset());
            case StatementIr::Type_t::IndirectCall:
                assert(st.opin1);
                return format("    indirectCall(cs, %s); // %s", ToString(st.opin1).c_str(), st.address.toString().c_str());
            case StatementIr::Type_t::Stop:
                return format("    stop(\"%s\");", st.stop.c_str());
            case StatementIr::Type_t::Comment:
                return format("    // %s", st.comment.c_str());
            case StatementIr::Type_t::Label:
                return format("loc_%x: // %s", st.address.linearOffset(), st.address.toString().c_str());
            case StatementIr::Type_t::Return:
                return "    return;";
                //return format(st.shiftStack ? "    sp += %d;\n    return;" : "    return;", st.shiftStack);
            case StatementIr::Type_t::Switch:
            {
                std::string aux = format("    switch (%s)\n    {\n", st.opSwitchSelector.c_str());
                for (auto p : st.opSwitchCases)
                    aux += format("        case %s: %s break;\n", ToString(p.first).c_str(), trim(ToString(*p.second)).c_str());
                aux += "        default:\n";
                aux += format("            stop(\"ind %s\")\n", st.address.toString().c_str()); // TODO
                aux += "    }";
                return aux;
            }
            default:
                assert(0);
                return "";
        }
    }
    
    virtual void PrintStatement(const StatementIr& st)
    {
        printf("%s\n", ToString(st).c_str());
        if (st.next)
        {
            printf("%s\n", ToString(*st.next).c_str());
            if (st.next->next)
            {
                printf("%s\n", ToString(*st.next->next).c_str());
                assert(!st.next->next->next);
            }
        }
    }
    
    virtual std::string ProcessFuncName(const StatementIr& st)
    {
        std::string repeat = st.repeat.empty() ? "" : st.repeat + " ";
        if (st.suffix)
            return format("%s%s%d", repeat.c_str(), st.func.c_str(), st.suffix);
        else
            return format("%s%s", repeat.c_str(), st.func.c_str());
    }

    virtual void PrintGlobalIndirectTable(const StatementIr& stmt)
    {
        printf("void indirectCall(int seg, int ofs)\n{\n");
        PrintStatement(stmt);
        printf("}\n");
    }
    
    virtual void PrintHeading(shared<Loader> loader)
    {
        printf("#include \"cico%s.h\"\n", mOptions->arch == arch_t::arch16 ? "16" : "32");
        
        if (mOptions->usePrintf)
            printf("#include <stdio.h>");
        printf("\n");
        
        if (mOptions->relocations)
        {
            printf(R"(void fixReloc(uint16_t seg);
void sub_%x();

void init()
{
%s
}

void start()
{
    sub_%x();
}

)", loader->GetEntry().linearOffset(), loader->GetInit().c_str(), loader->GetEntry().linearOffset());
        }
    }
    
    virtual void PrintDeclarations(std::set<address_t> allMethods)
    {
        if (mOptions->declarations)
        {
            for (address_t proc : allMethods)
                printf("void sub_%x();\n", proc.linearOffset());
            printf("\n");
        }
    }
    
    virtual void PrintRelocations(const std::vector<std::string>& allRelocs)
    {
        printf("void fixReloc(uint16_t seg)\n{\n");
        for (auto l : allRelocs)
            printf("    %s\n", l.c_str());
        printf("}\n");
    }

};
