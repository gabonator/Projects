//
//  print.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 09/12/2025.
//

class ProcIr {
public:
    std::string name;
    std::string info;
    std::vector<std::string> temps;
    std::vector<StatementIr> lines;
};

class PrintIr {
    const static bool mode16{true};
    
public:
    static std::string OffsetAsString(shared<OperandIr> op)
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
        if (op->memOfsDisp != 0)
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
                else
                    memOffset += format(" + %d", op->memOfsDisp);
            }
        }
        return memOffset;
    }
    
    static std::string SignedType(shared<OperandIr> op)
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
        switch (sizeInBytes)
        {
            case 0:
                return "";
            case 1:
                return "(char)";
            case 2:
                return "(short)";

            default:
                assert(0);
                return "";
        }
    }

    static std::string ToString(shared<OperandIr> op)
    {
        assert(op);
        switch (op->type)
        {
            case OperandIr::Type_t::Const:
                switch (op->constSize)
                {
                    case 0:
                        return format("%d", op->constValue);
                    case 1:
                        return format("0x%02x", op->constValue & 0xff);
                    case 2:
                        return format("0x%04x", op->constValue & 0xffff);
                    default:
                        assert(0);
                        return "";
                }
            case OperandIr::Type_t::Register:
                return op->regName;
            case OperandIr::Type_t::Memory:
                if (op->memSize == 1)
                    return format("memoryAGet(%s, %s)", op->memSegment.c_str(), OffsetAsString(op).c_str());
                else
                    return format("memoryAGet%d(%s, %s)", op->memSize*8, op->memSegment.c_str(), OffsetAsString(op).c_str());
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
    static std::string ToStringSetter(shared<OperandIr> op)
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

    void Print(shared<ProcIr> prog)
    {
        if (prog->info.empty())
            printf("%s\n", prog->name.c_str());
        else
            printf("%s // %s\n", prog->name.c_str(), prog->info.c_str());
        printf("{\n");
        
        size_t lines = prog->lines.size();
//        if (lines >= 2 &&
//            prog->lines[lines-1].type == StatementIr::Type_t::Return &&
//            prog->lines[lines-2].type != StatementIr::Type_t::Label)
//        {
//            lines--;
//        }
        
        for (size_t i=0; i<lines; i++)
            Print(prog->lines[i]);
        printf("}\n");
    }
    
    static std::string ToString(const StatementIr& st)
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
                } else {
                    if (st.opin1)
                        return format("    %s = %s;", ToString(st.opd).c_str(), ToString(st.opin1).c_str());
                    else if (st.stmt1)
                        return format("    %s = %s;", ToString(st.opd).c_str(), ToString(*st.stmt1).c_str());
                    else
                        assert(0);
                }
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
                if (st.opd && st.opin1 && st.opin2)
                    return format("    %s%s = %s%s(%s, %s);", repeat.c_str(), ToString(st.opd).c_str(), st.func.c_str(), suffix.c_str(), ToString(st.opin1).c_str(), ToString(st.opin2).c_str());
                else if (st.opd && st.opin1)
                    return format("    %s%s = %s%s(%s);", repeat.c_str(), ToString(st.opd).c_str(), st.func.c_str(), suffix.c_str(), ToString(st.opin1).c_str());
                else if (st.opd && !st.opin1)
                    return format("    %s%s = %s%s();", repeat.c_str(), ToString(st.opd).c_str(), st.func.c_str(), suffix.c_str());
                else if (st.opin1 && st.opin2)
                    return format("    %s%s%s(%s, %s);", repeat.c_str(), st.func.c_str(), suffix.c_str(), ToString(st.opin1).c_str(), ToString(st.opin2).c_str());
                else if (st.opin1)
                    return format("    %s%s%s(%s);", repeat.c_str(), st.func.c_str(), suffix.c_str(), ToString(st.opin1).c_str());
                else
                    return format("    %s%s%s();", repeat.c_str(), st.func.c_str(), suffix.c_str());
                //assert(0);
                break;
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
                            
                            return format("%s%s %s %s%s",
                                          leftSigned.c_str(), leftStr.c_str(),
                                          st.oper.c_str(),
                                          rightSigned.c_str(), rightStr.c_str());
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
                return format("    goto loc_%x;", st.addr.linearOffset());
            case StatementIr::Type_t::DirectCall:
                return format("    sub_%x();", st.addr.linearOffset());
            case StatementIr::Type_t::Stop:
                return format("    stop(\"%s\");", st.stop.c_str());
            case StatementIr::Type_t::Comment:
                return format("    // %s", st.comment.c_str());
            case StatementIr::Type_t::Label:
                return format("loc_%x: // %s", st.addr.linearOffset(), st.addr.toString().c_str());
            case StatementIr::Type_t::Return:
                return "    return;";
                //return format(st.shiftStack ? "    sp += %d;\n    return;" : "    return;", st.shiftStack);
            case StatementIr::Type_t::Switch:
            {
                std::string aux = format("    switch (%s)\n    {\n", st.opSwitchSelector.c_str());
                for (auto p : st.opSwitchCases)
                    aux += format("        case %s: %s break;\n", ToString(p.first).c_str(), trim(ToString(*p.second)).c_str());
                aux += "        default:\n";
                aux += format("            stop(\"ind %s\")\n", address_t(0, 0).toString().c_str()); // TODO
                aux += "    }";
                return aux;
            }
            default:
                assert(0);
                return "";
        }

    }
    static void Print(const StatementIr& st)
    {
        if (ToString(st).find("(ax - 0x0000 >=") != std::string::npos)
        {
            printf("%s\n", ToString(st).c_str());
            int f = 9; // TODO: ugly
            ToString(st);
        }
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
};
