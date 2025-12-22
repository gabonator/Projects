//
//  printNice.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 19/12/2025.
//

class PrintIrJs : public PrintIrCpp {
public:
    PrintIrJs(shared<Options> options) : PrintIrCpp(options)
    {
    }
    
    virtual std::string OffsetRegister(std::string reg) override
    {
        assert(reg.size() == 2);
        if (reg == "si" || reg == "di" || reg == "bp" || reg[1] == 'x')
            return RegisterName(reg, 2, false);
//            return format("r16[%s]", reg.c_str());
        if (reg[1] == 'h' || reg[1] == 'l')
            return RegisterName(reg, 1, false);
//            return format("r8[%s]", reg.c_str());
        assert(0);
        return "";
    }

    virtual void PrintProgram(shared<ProcIr> prog) override
    {
        if (prog->info.empty())
            printf("function* %s\n", prog->name.c_str());
        else
            printf("function* %s // %s\n", prog->name.c_str(), prog->info.c_str());
        printf("{\n");
//        if (prog->labels)
//            printf("  var pc = 0x%x;\n", prog->addr.linearOffset());
        
        if (prog->labels)
        {
            if (prog->lines.begin()->type != StatementIr::Type_t::Label)
                printf("  var pc = 0;\n");
            else
                printf("  var pc = 0x%x;\n", prog->lines.begin()->address.linearOffset());
        }
        for (auto t : prog->temps)
            printf("  var %s;\n", t.c_str());
        
        if (prog->labels)
            printf("  while (1) switch(pc)\n  {\n");
        bool first = prog->labels;
        bool lastRet = false;
        for (auto l : prog->lines)
        {
            if (first && l.type != StatementIr::Type_t::Label)
                printf("  case 0:\n");
//                printf("  case 0x%x:\n", prog->addr.linearOffset()); //l.address.linearOffset()); TODO
            
            first = false;
            if (l.type != StatementIr::Type_t::Label && l.type != StatementIr::Type_t::Comment)
            {
                auto it = mOptions->inject.find(l.address);
                if (it != mOptions->inject.end())
                {
                    if (it->second.find("sync()") == std::string::npos)
                        printf("    %s\n", it->second.c_str());
                    else
                        printf("    yield* %s\n", it->second.c_str());
                }
            }
            lastRet = l.type == StatementIr::Type_t::Return;
            PrintIrCpp::PrintStatement(l);
        }
        if (prog->labels)
        {
            if (!lastRet)
                printf("    return;\n");
            printf("  }\n");
        }
        printf("}\n");
    }

    virtual std::string ToString(shared<OperandIr> op) override
    {
        assert(op);
        switch (op->type)
        {
            case OperandIr::Type_t::Register:
                return RegisterName(op->regName, op->regSize, false);
//                if (op->regName == "ax" || op->regName == "bx" || op->regName == "cx" || op->regName == "dx" || op->regName == "ah" || op->regName == "al" || op->regName == "bh" || op->regName == "bl" || op->regName == "ch" || op->regName == "cl" || op->regName == "dh" || op->regName == "dl" || op->regName == "si" || op->regName == "di")
//                {
//                    return format("r%d[%s]", op->regSize*8, op->regName.c_str());
//                } else {
//                    return op->regName;
//                }
            default:
                return PrintIrCpp::ToString(op);
        }
        return "";
    }
    
    virtual std::string ToString(const StatementIr& st) override
    {
        switch (st.type)
        {
            case StatementIr::Type_t::Label:
                return format("  case 0x%x:", st.address.linearOffset());
            case StatementIr::Type_t::DirectJump:
                return format("    { pc = 0x%x; break; }", st.target.linearOffset());
            case StatementIr::Type_t::DirectCall:
                return format("    yield* sub_%x();", st.target.linearOffset());
            case StatementIr::Type_t::IndirectCall:
                assert(st.opin1);
                return format("    yield* indirectCall(cs, %s);", ToString(st.opin1).c_str());
                
            default:
                return PrintIrCpp::ToString(st);
        }
    }
    
    virtual std::string ProcessFuncName(const StatementIr& st) override
    {
        std::string repeat = st.repeat.empty() ? "" : st.repeat + " ";
        std::string func = st.func;
        func = replace(func, "<", "_");
        func = replace(func, ">", "");
        func = replace(func, ", ", "_");
        repeat = replace(repeat, "cx", "r16[cx]");
        
        if (st.func.starts_with("sub_") || st.func == "sync")
        {
            if (st.suffix)
                return format("yield* %s%s%d", repeat.c_str(), func.c_str(), st.suffix);
            else
                return format("yield* %s%s", repeat.c_str(), func.c_str());
        } else {
            if (st.suffix)
                return format("%s%s%d", repeat.c_str(), func.c_str(), st.suffix);
            else
                return format("%s%s", repeat.c_str(), func.c_str());
        }
    }
    
    std::string RegisterName(const std::string& regName, int regSize, bool sign)
    {
        if (regName == "ax" || regName == "bx" || regName == "cx" || regName == "dx" || regName == "ah" || regName == "al" || regName == "bh" || regName == "bl" || regName == "ch" || regName == "cl" || regName == "dh" || regName == "dl" || regName == "si" || regName == "di" || regName == "bp" || regName == "th" || regName == "tl" || regName == "tx")
        {
            if (sign)
                return format("r%ds[%s]", regSize*8, regName.c_str());
            else
                return format("r%d[%s]", regSize*8, regName.c_str());
        } else {
            if (sign)
                return format("signed%d(%s)", regSize*8, regName.c_str());
            else
                return regName;
        }
    }
    virtual std::string SignedType(shared<OperandIr> op) override
    {
        assert(op);
        switch (op->type)
        {
            case OperandIr::Type_t::Register:
                return RegisterName(op->regName, op->regSize, true);
            case OperandIr::Type_t::Const:
                if (op->constSize == 0 && op->constValue == 0)
                    return "0";
                return utils::format("signed%d(%s)", op->constSize*8, ToString(op).c_str());
            case OperandIr::Type_t::Memory:
                return utils::format("signed%d(%s)", op->memSize*8, ToString(op).c_str());
            default:
                assert(0);
        }
    }

    virtual void PrintHeading(shared<Loader> loader) override
    {
        if (mOptions->relocations)
        {
            printf(R"(function init()
{
%s
}

function* start()
{
    yield* sub_%x();
}

)", loader->GetInit().c_str(), loader->GetEntry().linearOffset());
        }
    }

    virtual void PrintGlobalIndirectTable(const StatementIr& stmt) override
    {
        printf("function* indirectCall(seg, ofs)\n{\n");
        PrintStatement(stmt);
        printf("}\n");
    }

    virtual void PrintDeclarations(std::set<address_t> allMethods) override
    {
    }
    
    virtual void PrintRelocations(const std::vector<std::string>& allRelocs)
    {
        printf("function fixReloc(seg)\n{\n");
        for (auto l : allRelocs)
            printf("    %s\n", l.c_str());
        printf("}\n");
    }

};
