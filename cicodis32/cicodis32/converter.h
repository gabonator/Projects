//
//  converter.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

#define convert_args shared<CapInstr> instr, shared<instrInfo_t> info
struct convert_t
{
    std::function<std::string(convert_args)> convert;
};

convert_t convert[X86_INS_ENDING] = {
    [X86_INS_PUSH] = {.convert = [](convert_args){ return "push($rd0);";} },
    [X86_INS_POP] = {.convert = [](convert_args){ return "$wr0 = pop();";} },
    [X86_INS_XOR] = {.convert = [](convert_args){
        if (instr->ArgsEqual(0, 1))
            return "$wr0 = 0;";
        else
            return "$wr0 ^= $rd1;";
    } },
    [X86_INS_MOV] = {.convert = [](convert_args){ return "$wr0 = $rd1;"; } },
    [X86_INS_TEST] = {.convert = [](convert_args){ return ""; } }, // TODO: BUG SETS CARRY!!!!!!! sub_164000
    [X86_INS_CMP] = {.convert = [](convert_args){ return ""; } },
    [X86_INS_JE] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JNE] = {.convert = [](convert_args){ return "if ($ncond) goto $target;"; } },
    [X86_INS_RET] = {.convert = [](convert_args){ return "return;"; } },
    [X86_INS_INT] = {.convert = [](convert_args){ return "interrupt($rd0);"; } },
    [X86_INS_AND] = {.convert = [](convert_args){ return "$rw0 &= $rd1;"; } },
    [X86_INS_LEA] = {.convert = [](convert_args){ return "$wr0 = $adr1;"; } },
    [X86_INS_SAHF] = {.convert = [](convert_args){ return "sahf();"; } },
    [X86_INS_PUSHFD] = {.convert = [](convert_args){ return "pushfd();"; } },
    [X86_INS_POPFD] = {.convert = [](convert_args){ return "popfd();"; } },
    [X86_INS_CALL] = {.convert = [](convert_args){ return "$target();"; } },
    [X86_INS_SBB] = {.convert = [](convert_args){ return instr->ArgsEqual(0, 1) ? "$wr0 = -flags.carry" : "$wr0 -= $rd1 + flags.carry"; } },
    [X86_INS_SUB] = {.convert = [](convert_args){ return "$rw0 -= $rd1;"; } },
};

class Convert : public Formatter
{
    const Analyser& mAnal;
    shared<CTracer> mTracer;
    
public:
    Convert(const Analyser& anal) : mAnal(anal)
    {
    }
    
    void ConvertProc(address_t proc)
    {
//        CTracer::code_t code =
        mTracer = mAnal.mMethods.find(proc)->second;
        CTracer::code_t& code = mTracer->GetCode();
        
        assert(mAnal.mInfos.find(proc) != mAnal.mInfos.end());
        shared<Analyser::info_t> info = mAnal.mInfos.find(proc)->second;
        
        printf("void sub_%x()\n{\n", proc.offset);
        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                printf("gap %d bytes\n", p.first.offset - next.offset);
            }
            shared<CapInstr> pinstr = p.second;
            auto codeit = info->code.find(p.first);
            assert(codeit != info->code.end());
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            //printf("%x %s %s\n", p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);
            if (pinstr->isLabel)
                printf("lab_%x:\n", pinstr->mAddress.offset);
            if (convert[pinstr->mId].convert)
                printf("  %s\n", format(pinstr, pinfo, convert[pinstr->mId].convert(p.second, pinfo)).c_str());
            else
            {
                printf("Conversion for '%s'/%x (ZF=%s/%x, CF=%s) not implemented!\n", pinstr->AsString().c_str(), pinstr->mAddress.offset, Capstone->ToString(pinfo->flagZero.lastSetInsn), pinfo->flagZero.lastSet.offset, Capstone->ToString(pinfo->flagCarry.lastSetInsn));
                assert(0);
            }
                
            next = {p.second->mAddress.segment, p.second->mAddress.offset + p.second->mSize};
        }
        printf("}\n\n");
        //std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> code;

    }
    
    virtual std::string BuildCondition(shared<CapInstr> instr, shared<instrInfo_t> info, bool invert) override
    {
        switch (instr->mId)
        {
            case X86_INS_JE:
                switch (info->flagZero.lastSetInsn)
                {
                    case X86_INS_TEST:
                    {
                        assert(!info->flagZero.dirtyRegisters[0] && !info->flagZero.dirtyRegisters[1]);
                        shared<CapInstr> ref = mTracer->GetCode().find(info->flagZero.lastSet)->second;
                        if (ref->ArgsEqual(0, 1))
                            return format(ref, info, "!$rd0");
                        else
                            return format(ref, info, "!($rd0 & $rd1)");
                    }
                    default:
                        assert(0);
                }
            case X86_INS_JNE:
                switch (info->flagZero.lastSetInsn)
                {
                    case X86_INS_TEST:
                    {
                        assert(!info->flagZero.dirtyRegisters[0] && !info->flagZero.dirtyRegisters[1]);
                        shared<CapInstr> ref = mTracer->GetCode().find(info->flagZero.lastSet)->second;
                        if (ref->ArgsEqual(0, 1))
                            return format(ref, info, "$rd0");
                        else
                            return format(ref, info, "$rd0 & $rd1");
                    }
                    default:
                        assert(0);
                }
            default:
                assert(0);
        }
        return "";
    }
    
private:

};
