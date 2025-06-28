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
    std::function<std::string(convert_args)> zf;
    std::function<std::string(convert_args)> cf;
    std::function<std::string(convert_args)> numeric;
    std::function<std::string(convert_args)> signedNumeric;
};

convert_t convert[X86_INS_ENDING] = {
    [X86_INS_PUSH] = {.convert = [](convert_args){ return instr->mDetail.operands[0].size == 4 ? "push32($rd0);" : "push($rd0);";} },
    [X86_INS_POP] = {.convert = [](convert_args){ return instr->mDetail.operands[0].size == 4 ? "$wr0 = pop32();" : "$wr0 = pop();";} },
    [X86_INS_XOR] = {.convert = [](convert_args){
        if (instr->ArgsEqual(0, 1))
            return "$wr0 = 0;";
        else
            return "$wr0 ^= $rd1;";
    } },
    [X86_INS_MOV] = {.convert = [](convert_args){ return "$wr0 = $rd1;"; } },
    [X86_INS_MOVZX] = {.convert = [](convert_args){
        return "$wr0 = $rd1;"; } },
    [X86_INS_JE] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JNE] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JLE] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JL] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JAE] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JA] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JMP] = {.convert = [](convert_args){ return "goto $target;"; } },
    [X86_INS_RET] = {.convert = [](convert_args){ return "return;"; } },
    [X86_INS_INT] = {.convert = [](convert_args){ return "interrupt($rd0);"; } },
    [X86_INS_AND] = {.convert = [](convert_args){ return "$rw0 &= $rd1;"; } },
    [X86_INS_ADD] = {.convert = [](convert_args){ return "$rw0 += $rd1;"; } },
    [X86_INS_LEA] = {.convert = [](convert_args){ return "$wr0 = $adr1;"; } },
    [X86_INS_SAHF] = {.convert = [](convert_args){ return "sahf();"; } },
    [X86_INS_PUSHFD] = {.convert = [](convert_args){ return "pushfd();"; } },
    [X86_INS_POPFD] = {.convert = [](convert_args){ return "popfd();"; } },
    [X86_INS_CALL] = {.convert = [](convert_args){ return "$target();"; } },
    [X86_INS_SBB] = {.convert = [](convert_args){ return instr->ArgsEqual(0, 1) ? "$wr0 = -flags.carry" : "$wr0 -= $rd1 + flags.carry"; } },
    [X86_INS_SUB] = {.convert = [](convert_args){ return "$rw0 -= $rd1;"; } },
    [X86_INS_CMP] = {
        .convert = [](convert_args){ return ""; },
        .zf = [](convert_args){ return "$rd0 == $rd1"; },
        .cf = [](convert_args){ return "$rd0 < $rd1"; },
        .numeric = [](convert_args){ return "$rd0"; },
    },
    [X86_INS_TEST] = {// TODO: BUG SETS CARRY!!!!!!! sub_164000
        .convert = [](convert_args){ return ""; },
        .zf = [](convert_args){ return instr->ArgsEqual() ? "$rd0" : "$rd0 & $rd1"; },
        .numeric = [](convert_args){ return "$rd0"; },
        .signedNumeric = [](convert_args){ return "$rd0"; }, //[](convert_args){ return "(sig0)$rd0"; },
    },
    [X86_INS_NEG] = {.convert = [](convert_args){ return "$wr0 = -$rd0;"; } },
    [X86_INS_CLD] = {.convert = [](convert_args){ return "flags.direction = 0;"; } },
    [X86_INS_STD] = {.convert = [](convert_args){ return "flags.direction = 1;"; } },
    [X86_INS_LODSB] = {.convert = [](convert_args){
        if (strcmp(instr->mOperands, "al, byte ptr [si]") == 0 || strcmp(instr->mOperands, "al, byte ptr [esi]") == 0)
            return "lodsb<MemAuto, DirAuto>();";
        assert(0);
        return "";
    } },
    [X86_INS_DEC] = {.convert = [](convert_args){ return "$rw0--;"; } },
    [X86_INS_INC] = {.convert = [](convert_args){ return "$rw0++;"; } },

};

/*
 164059 add eax, esi             SF = (eax+esi) & (1<<31)    OF = (eax+esi) >= (1<<32)
 16405b test eax, eax            ZF = !eax    CF = 0, OF = 0, SF = MSB
 16405d jle 0x164080             ZF = 1 or SF <> OF
 
 add eax, esi
 test eax, eax
 jle 0x164080
 */

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
            printf("/*%x %s %s*/", p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);
            if (pinstr->isLabel)
                printf("lab_%x:\n", pinstr->mAddress.offset);
            if (convert[pinstr->mId].convert)
                printf("  %s\n", format(pinstr, pinfo, convert[pinstr->mId].convert(p.second, pinfo)).c_str());
            else
            {
                printf("Conversion for '%s'/%x (ZF=%s/%x, CF=%s, OF=%s, SF=%s) not implemented!\n", pinstr->AsString().c_str(), pinstr->mAddress.offset, Capstone->ToString(pinfo->flagZero.lastSetInsn), pinfo->flagZero.lastSet.offset, Capstone->ToString(pinfo->flagCarry.lastSetInsn), Capstone->ToString(pinfo->flagOverflow.lastSetInsn), Capstone->ToString(pinfo->flagSign.lastSetInsn));
                assert(0);
            }
                
            next = {p.second->mAddress.segment, p.second->mAddress.offset + p.second->mSize};
        }
        printf("}\n\n");
        //std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> code;

    }
    
    std::string InvertCondition(std::string cond)
    {
        if (cond == "$rd0")
            return "!$rd0";
        if (cond == "$rd0 == $rd1")
            return "$rd0 != $rd1";
        if (cond == "$rd0 < $rd1")
            return "$rd0 >= $rd1";
        assert(0);
        return "!(" + cond + ")";
    }
    virtual std::string BuildCondition(shared<CapInstr> instr, shared<instrInfo_t> info, bool invert) override
    {
        convert_t c = convert[info->flagZero.lastSetInsn];
        std::string cond;
        shared<CapInstr> ref = mTracer->GetCode().find(info->flagZero.lastSet)->second;
        
        switch (instr->mId)
        {
            case X86_INS_JE:
                assert(c.zf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return format(ref, info, c.zf(ref, info));
            case X86_INS_JNE:
                assert(c.zf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return format(ref, info, InvertCondition(c.zf(ref, info)));
            case X86_INS_JAE:
                assert(c.cf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return format(ref, info, InvertCondition(c.cf(ref, info)));
            case X86_INS_JLE:
                assert(c.signedNumeric);
                if (c.signedNumeric(ref, info) == "$rd0")
                    return format(ref, info, "($sig0)$rd0 <= 0");
                assert(0);
                return "";
            case X86_INS_JL:
                assert(c.signedNumeric);
                if (c.signedNumeric(ref, info) == "$rd0")
                    return format(ref, info, "($sig0)$rd0 < 0"); // BLBOST!!!
                assert(0);
                return "";
            case X86_INS_JA:
                assert(c.cf && c.zf); // CF == 0 && ZF == 0
                if (c.cf(ref, info) == "$rd0 < $rd1" && c.zf(ref, info) == "$rd0 == $rd1")
                    return format(ref, info, "$rd0 > $rd1");
                assert(0);
                return "";
            default:
                assert(0);
        }
        return "";
    }
    
private:

};
