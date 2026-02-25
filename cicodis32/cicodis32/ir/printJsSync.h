class PrintIrJsSync : public PrintIrCppHints {
public:
    PrintIrJsSync(shared<Options> options) : PrintIrCppHints(options)
    {
    }
    
    virtual std::string OffsetRegister(std::string reg) override
    {
        if (reg.size() == 3)
            return RegisterName(reg, 4, false);
        assert(reg.size() == 2);
        if (reg == "si" || reg == "di" || reg == "bp" || reg[1] == 'x')
            return RegisterName(reg, 2, false);
        if (reg[1] == 'h' || reg[1] == 'l')
            return RegisterName(reg, 1, false);
        assert(0);
        return "";
    }

    virtual void PrintProgram(shared<ProcIr> prog, shared<Analyser::info_t>) override
    {
        PrintIrCppHints::PrepareProgram(prog);
        
        if (prog->info.empty())
            printf("function %s\n", prog->name.c_str());
        else
            printf("function %s // %s\n", prog->name.c_str(), prog->info.c_str());
        printf("{\n");
        
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
                    if (it->second == "//comment")
                        continue;
                    printf("    %s\n", it->second.c_str());
                }
            }
            lastRet = l.type == StatementIr::Type_t::Return;
            PrintIrCppHints::PrintStatement(l);
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
            case OperandIr::Type_t::Variable:
                if (op->variable == "th" || op->variable == "tl")
                    return RegisterName(op->variable, 1, false);
                if (op->variable == "tx")
                    return RegisterName(op->variable, 2, false);
                return PrintIrCppHints::ToString(op);
            default:
                return PrintIrCppHints::ToString(op);
        }
        return "";
    }
    
    virtual std::string ToString(const StatementIr& st) override
    {
        PrepareStatement(st);
        switch (st.type)
        {
            case StatementIr::Type_t::Label:
                return format("  case 0x%x:", st.address.linearOffset());
            case StatementIr::Type_t::DirectJump:
                return format("    { pc = 0x%x; break; }", st.target.linearOffset()); // TODO: extra break at end
            case StatementIr::Type_t::DirectCall:
                return format("    sub_%x();", st.target.linearOffset());
            case StatementIr::Type_t::DirectCallLong:
                return format("    push(cs); cs = 0x%04x; sub_%x(); assert(cs == 0x%04x);",
                              st.target.segment, st.target.linearOffset(), st.address.segment);
            case StatementIr::Type_t::IndirectCall:
                assert(st.opin1);
                return format("    indirectCall(cs, %s);", ToString(st.opin1).c_str());
            case StatementIr::Type_t::Switch:
                assert(st.opSwitchCases.size());
                if (st.opSwitchCases.begin()->second->type == StatementIr::Type_t::DirectJump)
                    return PrintIrCppHints::ToString(st) + "\n    break;";
                else
                    return PrintIrCppHints::ToString(st);
            case StatementIr::Type_t::Binary:
            {
                // for 32bit numbers use unsigned bitshift (replace " >> " not " >>>" which is already correct)
                std::string temp = PrintIrCppHints::ToString(st);
                temp = utils::replace(temp, " >> ", " >>> ");
                temp = utils::replace(temp, " >>= ", " >>>= ");
                return temp;
            }
            default:
                return PrintIrCppHints::ToString(st);
        }
    }
    
    virtual std::string ProcessFuncName(const StatementIr& st) override
    {
        std::string repeat = st.repeat.empty() ? "" : st.repeat + " ";
        std::string func = st.func;
        repeat = replace(repeat, "ecx", "r16[ecx]");
        repeat = replace(repeat, "cx", "r16[cx]");

        if (st.suffix)
            return format("%s%s%d", repeat.c_str(), func.c_str(), st.suffix);
        else
            return format("%s%s", repeat.c_str(), func.c_str());
    }
    
    virtual std::string ProcessFuncTemplate(const StatementIr& st) override
    {
        if (st.templ1.empty())
            return "";
        if (st.templ2.empty())
            return format("_%s", replace(GetHintForTemplate(st.templ1), "_", "").c_str());
        return format("_%s_%s", replace(GetHintForTemplate(st.templ1), "_", "").c_str(),
                      replace(GetHintForTemplate(st.templ2), "_", "").c_str());
    }

    std::string RegisterName(const std::string& regName, int regSize, bool sign)
    {
        assert(regSize != 3);
        if (regName.size() == 3 ||
            regName == "ax" || regName == "bx" || regName == "cx" || regName == "dx" || regName == "ah" || regName == "al" || regName == "bh" || regName == "bl" || regName == "ch" || regName == "cl" || regName == "dh" || regName == "dl" || regName == "si" || regName == "di" || regName == "bp" || regName == "th" || regName == "tl" || regName == "tx")
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
                return utils::format("signed%d", op->constSize*8);
            case OperandIr::Type_t::Memory:
                return utils::format("signed%d", op->memSize*8);
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

function start()
{
    sub_%x();
}

)", loader->GetInit().c_str(), loader->GetEntry().linearOffset());
        }
    }

    virtual void PrintGlobalIndirectTable(const StatementIr& stmt) override
    {
        if (stmt.opSwitchCases.empty())
            return;

        printf("function* indirectCall(seg, ofs)\n{\n");
        PrintStatement(stmt);
        printf("}\n");
    }

    virtual void PrintDeclarations(std::set<address_t> allMethods) override
    {
    }
    
    virtual void PrintRelocations(const std::vector<std::string>& allRelocs) override
    {
        printf("function fixReloc(seg)\n{\n");
        for (std::string l : allRelocs)
        {
            if (mOptions->memHintDefault.isValid())
                l = replace(l, "memoryA", "memory");
            printf("    %s\n", l.c_str());
        }
        printf("}\n");
    }
    virtual std::string ToStringExpression(std::string str) override
    {
        // TODO: ugly
        if (str == "edx" || str == "eax" || str == "ecx")
            return format("r32[%s]", str.c_str());
        if (str == "ax = 0x0168;")
            return "r16[ax] = 0x0168;";
        if (str == "esp += 4; return;")
            return "r32[esp] += 4; return;";
        if (str == "return;")
            return "return;";
        assert(0);
        return str;
    }

};

