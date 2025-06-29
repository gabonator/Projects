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
    [X86_INS_JB] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JBE] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JG] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JGE] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JP] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JNP] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JMP] = {.convert = [](convert_args){ return "goto $target;"; } },
    [X86_INS_RET] = {.convert = [](convert_args){ return "return;"; } },
    [X86_INS_INT] = {.convert = [](convert_args){ return "interrupt($rd0);"; } },
    [X86_INS_AND] = {.convert = [](convert_args){ return "$rw0 &= $rd1;"; } },
    [X86_INS_OR] = {.convert = [](convert_args){ return "$rw0 |= $rd1;"; } },
    [X86_INS_ADD] = {.convert = [](convert_args){ return "$rw0 += $rd1;"; } },
    [X86_INS_LEA] = {.convert = [](convert_args){ return "$wr0 = $adr1;"; } },
    [X86_INS_SAHF] = {.convert = [](convert_args){ return "sahf();"; } },
    [X86_INS_PUSHFD] = {.convert = [](convert_args){ return "pushfd();"; } },
    [X86_INS_POPFD] = {.convert = [](convert_args){ return "popfd();"; } },
    [X86_INS_CALL] = {.convert = [](convert_args){
        if (instr->mDetail.operands[0].type == X86_OP_IMM)
            return "$method();";
        else
            return "callIndirect($rd0);";
    },
            .cf = [](convert_args){ return "flags.carry"; },
            .zf = [](convert_args){ return "flags.zero"; },
    },
    [X86_INS_SBB] = {.convert = [](convert_args){ return instr->ArgsEqual() ? "$wr0 = -flags.carry;" : "$wr0 -= $rd1 + flags.carry;"; } },
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
    [X86_INS_CLC] = {.convert = [](convert_args){ return "flags.carry = 0;"; } },
    [X86_INS_STC] = {.convert = [](convert_args){ return "flags.carry = 1;"; } },
    [X86_INS_LODSB] = {.convert = [](convert_args){
        if (strcmp(instr->mOperands, "al, byte ptr [si]") == 0 || strcmp(instr->mOperands, "al, byte ptr [esi]") == 0)
            return "lodsb<MemAuto, DirAuto>();";
        assert(0);
        return "";
    } },
    [X86_INS_DEC] = {.convert = [](convert_args){ return "$rw0--;"; } },
    [X86_INS_INC] = {.convert = [](convert_args){ return "$rw0++;"; } },
    [X86_INS_SHR] = {.convert = [](convert_args){ return "$rw0 >>= $rd1;"; } },
    [X86_INS_IMUL] = {.convert = [](convert_args){
        if (instr->mDetail.op_count == 3 && instr->mDetail.operands[2].type == X86_OP_IMM)
            return "$wr0 = $rd1 * $rd2";
        assert(0);
        return "";
    } },
    [X86_INS_OUT] = {.convert = [](convert_args){ return "out($rd0, $rd1);"; } },
    [X86_INS_INT3] = {.convert = [](convert_args){ return "stop();"; } },
    // float
    [X86_INS_FLD] = {.convert = [](convert_args){ return "fld$width0($rd0);"; } },
    [X86_INS_FILD] = {.convert = [](convert_args){ return "fild$width0($rd0);"; } },
    [X86_INS_FMUL] = {.convert = [](convert_args){ return "fmul$width0($rd0);"; } },
    [X86_INS_FDIV] = {.convert = [](convert_args){ return "fdiv$width0($rd0);"; } },
    [X86_INS_FADD] = {.convert = [](convert_args){ return "fadd$width0($rd0);"; } },
    [X86_INS_FSTP] = {.convert = [](convert_args){ return "$wr0 = fstp$width0();"; } },
    [X86_INS_FLD1] = {.convert = [](convert_args){ return "fld1();"; } },
    [X86_INS_FSUBR] = {.convert = [](convert_args){ return "fsubr$width0($rd0);"; } },
    [X86_INS_FSUBP] = {.convert = [](convert_args){ return "fsubp$width0($rd0);"; } },
    [X86_INS_FCOMP] = {.convert = [](convert_args){ return "fcomp$width0($rd0);"; } },
    [X86_INS_FISTP] = {.convert = [](convert_args){ return "$wr0 = fistp();"; } },
    [X86_INS_FNSTSW] = {.convert = [](convert_args){ return "$wr0 = fnstsw();"; } },
    [X86_INS_FCOS] = {.convert = [](convert_args){ return "fcos();"; } },
    [X86_INS_WAIT] = {.convert = [](convert_args){ return ""; } },
    [X86_INS_FXCH] = {.convert = [](convert_args){ return "fxch($rd0);"; } },
    [X86_INS_FPREM] = {.convert = [](convert_args){ return "fprem();"; } },
    [X86_INS_FNSTCW] = {.convert = [](convert_args){ return "$wr0 = fnstcw();"; } },
    [X86_INS_FLDCW] = {.convert = [](convert_args){ return "fldcw($rd0);"; } },
    [X86_INS_FRNDINT] = {.convert = [](convert_args){ return "frndtint();"; } },
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
    std::set<address_t, cmp_adress_t> mCalls;
    std::vector<std::string> mCode;
    
public:
    Convert(const Analyser& anal) : mAnal(anal)
    {
    }

    std::string format(const char* fmt, ...)
    {
        char buf[256];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buf, 256, fmt, args);
        va_end(args);
        return std::string(buf);
    }

    void ConvertProc(address_t proc)
    {
//        CTracer::code_t code =
        mTracer = mAnal.mMethods.find(proc)->second;
        CTracer::code_t& code = mTracer->GetCode();
        
        assert(mAnal.mInfos.find(proc) != mAnal.mInfos.end());
        shared<Analyser::info_t> info = mAnal.mInfos.find(proc)->second;
        
        mCode.push_back(format("void sub_%x()\n{\n", proc.offset));
        assert(!code.empty() && code.begin()->first == proc);
        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                mCode.push_back(format("gap %d bytes\n", p.first.offset - next.offset));
            }
            shared<CapInstr> pinstr = p.second;
            if (pinstr->mId == X86_INS_CALL)
            {
                assert(pinstr->mDetail.op_count == 1);
                if (pinstr->mDetail.operands[0].type == X86_OP_IMM)
                    mCalls.insert(pinstr->CallTarget());
            }
            auto codeit = info->code.find(p.first);
            assert(codeit != info->code.end());
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
//            printf("/*%x %s %s*/", p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);
            if (pinstr->isLabel)
                mCode.push_back(format("lab_%x:\n", pinstr->mAddress.offset));
            if (convert[pinstr->mId].convert)
                mCode.push_back("  " + iformat(pinstr, pinfo, convert[pinstr->mId].convert(p.second, pinfo)) + "\n");
            else
            {
                printf("Conversion for '%s'/%x (ZF=%s/%x, CF=%s, OF=%s, SF=%s) not implemented!\n", pinstr->AsString().c_str(), pinstr->mAddress.offset, Capstone->ToString(pinfo->flagZero.lastSetInsn), pinfo->flagZero.lastSet.offset, Capstone->ToString(pinfo->flagCarry.lastSetInsn), Capstone->ToString(pinfo->flagOverflow.lastSetInsn), Capstone->ToString(pinfo->flagSign.lastSetInsn));
                assert(0);
            }
                
            next = {p.second->mAddress.segment, p.second->mAddress.offset + p.second->mSize};
        }
        mCode.push_back("}\n\n");
        //std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> code;

    }
    
    std::string InvertCondition(std::string cond)
    {
        if (cond == "$rd0" || cond == "flags.carry" || cond == "flags.zero")
            return "!" + cond;
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
                return iformat(ref, info, c.zf(ref, info));
            case X86_INS_JNE:
                assert(c.zf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return iformat(ref, info, InvertCondition(c.zf(ref, info)));
            case X86_INS_JAE:
                assert(c.cf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return iformat(ref, info, InvertCondition(c.cf(ref, info)));
            case X86_INS_JLE:
                switch(ref->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(ref, info, "($sig0)$rd0 <= ($sig1)$rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JGE:
                switch(ref->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(ref, info, "($sig0)$rd0 >= ($sig1)$rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JL:
                switch(ref->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(ref, info, "($sig0)$rd0 < ($sig1)$rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JG:
                switch(ref->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(ref, info, "($sig0)$rd0 > ($sig1)$rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JA:
                assert(c.cf && c.zf); // CF == 0 && ZF == 0
                if (c.cf(ref, info) == "$rd0 < $rd1" && c.zf(ref, info) == "$rd0 == $rd1")
                    return iformat(ref, info, "$rd0 > $rd1");
                assert(0);
                return "";
            case X86_INS_JB:
                switch(ref->mId)
                {
                    case X86_INS_SAHF:
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(ref, info, "flags.carry");
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(ref, info, "$rd0 < $rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JBE:
                switch(ref->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(ref, info, "$rd0 <= $rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JNP:
                switch(ref->mId)
                {
                    case X86_INS_SAHF:
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(ref, info, "!flags.parity");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JP:
                switch(ref->mId)
                {
                    case X86_INS_SAHF:
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(ref, info, "flags.parity");
                    default:
                        assert(0);
                        return "";
                }
            default:
                assert(0);
        }
        return "";
    }
    
    void Dump()
    {
        for (std::string line : mCode)
            printf("%s", line.c_str());
    }
    const std::set<address_t, cmp_adress_t>& GetCalls()
    {
        return mCalls;
    }

};
