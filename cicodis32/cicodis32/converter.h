//
//  converter.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

#include <sstream>

std::string ConvertStringopName(shared<CapInstr> instr)
{
    auto replace = [](const char* in, const char* s, const char* r)
    {
        char temp[128];
        strcpy(temp, in);
        for (int i=0; temp[i]; i++)
            if (temp[i] == s[0])
                temp[i] = r[0];
        return std::string(temp);
    };
    auto split = [] (const std::string& input, const std::string& delimiter) -> std::vector<std::string> {
        std::vector<std::string> tokens;
        std::size_t start = 0;
        std::size_t end;

        while ((end = input.find(delimiter, start)) != std::string::npos) {
            tokens.push_back(input.substr(start, end - start));
            start = end + delimiter.length();
        }

        tokens.push_back(input.substr(start)); // add the last token
        return tokens;
    };
    auto argToTemplate = [](std::string in) -> std::string {
        if (in == "byte ptr es:[edi]" || in == "word ptr es:[edi]" || in == "dword ptr es:[edi]")
            return "ES_EDI";
        if (in == "byte ptr es:[di]" || in == "word ptr es:[di]")
            return "ES_DI";
        if (in == "word ptr [si]" || in == "byte ptr [si]")
            return "DS_SI";
        if (in == "word ptr [esi]")
            return "DS_ESI";
        assert(0);
        return "?";
    };
    std::string repeat = "";
    std::string templ = replace(instr->mMnemonic, " ", "_");
    std::vector<std::string> args = split(instr->mOperands, ", ");
    assert(args.size() == 2);
    if (templ.starts_with("rep_"))
    {
        repeat = "for (; cx != 0; --cx) ";
        templ = templ.substr(4);
    }
    if (args[1] == "al" || args[1] == "ax" || args[1] == "eax")
        return repeat + templ + "<" + argToTemplate(args[0]) + ">("+args[1]+");";
    else
        return repeat + templ + "<" + argToTemplate(args[0]) + ", " + argToTemplate(args[1]) + ">();";
}

#define convert_args shared<CapInstr> instr, shared<instrInfo_t> info
struct convert_t
{
    std::function<std::string(convert_args)> convert;
    std::function<std::string(convert_args)> zf;
    std::function<std::string(convert_args)> cf;
    std::function<std::string(convert_args)> sf;
    std::function<std::string(convert_args)> numeric;
    std::function<std::string(convert_args)> signedNumeric;
    std::function<std::string(convert_args)> savecf;
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
    [X86_INS_JNS] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JS] = {.convert = [](convert_args){ return "if ($cond) goto $target;"; } },
    [X86_INS_JMP] = {.convert = [](convert_args){ return "goto $target;"; } },
    [X86_INS_LOOP] = {.convert = [](convert_args){ return "if (--cx) goto $target;"; } },
    [X86_INS_JCXZ] = {.convert = [](convert_args){ return "if (cx==0) goto $target;"; } },
    [X86_INS_RET] = {.convert = [](convert_args){
        if (instr->mDetail.op_count == 1 && instr->mDetail.operands[0].type == X86_OP_IMM)
            return "sp += $immd0;\n  return;";
        else
            return "return;";
        } },
    [X86_INS_INT] = {.convert = [](convert_args){ return "interrupt($rd0);"; },
            .cf = [](convert_args){ return "flags.carry"; },
            .zf = [](convert_args){ return "flags.zero"; },
    },
    [X86_INS_AND] = {.convert = [](convert_args){ return "$rw0 &= $rd1;"; },
        .zf = [](convert_args){ return "!$rd0"; },
        .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
    },
    [X86_INS_OR] = {.convert = [](convert_args){ return "$rw0 |= $rd1;"; },
        .zf = [](convert_args){ return "!$rd0"; },
    },
    [X86_INS_ADD] = {.convert = [](convert_args){ return "$rw0 += $rd1;"; },
            .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
            .zf = [](convert_args){ return "!$rd0"; }},
    [X86_INS_LEA] = {.convert = [](convert_args){ return "$wr0 = $adr1;"; } },
    [X86_INS_SAHF] = {.convert = [](convert_args){ return "sahf();"; } },
    [X86_INS_PUSHFD] = {.convert = [](convert_args){ return "pushfd();"; } },
    [X86_INS_POPFD] = {.convert = [](convert_args){ return "popfd();"; } },
    [X86_INS_CALL] = {.convert = [](convert_args){
        if (instr->mDetail.operands[0].type == X86_OP_IMM)
            return "$method();";
        else
        {
            if (instr->mDetail.operands[0].size == 2)
                return "callIndirect(cs, $rd0);";
            else
            {
                assert(0);
                return "stop();";
            }
        }
    },
            .cf = [](convert_args){ return "flags.carry"; },
            .zf = [](convert_args){ return "flags.zero"; },
    },
    [X86_INS_SBB] = {.convert = [](convert_args){ return instr->ArgsEqual() ? "$wr0 = -flags.carry;" : "$wr0 -= $rd1 + flags.carry;"; } },
    [X86_INS_SUB] = {.convert = [](convert_args){ return "$rw0 -= $rd1;"; },
            .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
            .zf = [](convert_args){ return "!$rd0"; },

    },
    [X86_INS_CMP] = {
        .convert = [](convert_args){ return ""; },
        .zf = [](convert_args){ return "$rd0 == $rd1"; },
        .cf = [](convert_args){ return "$rd0 < $rd1"; },
        .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
        .numeric = [](convert_args){ return "$rd0"; },
    },
    [X86_INS_TEST] = {
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
    [X86_INS_CLI] = {.convert = [](convert_args){ return "flags.interrupts = 0;"; } },
    [X86_INS_STI] = {.convert = [](convert_args){ return "flags.interrupts = 1;"; } },
    [X86_INS_LODSB] = {.convert = [](convert_args){
        if (strcmp(instr->mOperands, "al, byte ptr [si]") == 0)
            return "al = lodsb<DS_SI>();";
        else if (strcmp(instr->mOperands, "al, byte ptr [esi]") == 0)
            return "al = lodsb<DS_ESI>();";
        assert(0);
        return "";
    } },
    [X86_INS_DEC] = {.convert = [](convert_args){ return "$rw0--;"; },
            .zf = [](convert_args){ return "!$rd0"; },
            .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
    },
    [X86_INS_INC] = {
        .convert = [](convert_args){ return "$rw0++;"; },
        .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
    },
    [X86_INS_SHR] = {.convert = [](convert_args){ return "$rw0 >>= $rd1;"; },
        .zf = [](convert_args){ return "!$rd0"; },
        //.cf = [](convert_args){ return "temp_cf"; }, // TODO: saved index
        .savecf = [](convert_args){ assert(instr->mDetail.operands[1].type == X86_OP_IMM && instr->mDetail.operands[1].imm == 1); return "$rd0 & 1"; },
    },
    [X86_INS_SHL] = {.convert = [](convert_args){ return "$rw0 <<= $rd1;"; } },
    [X86_INS_IMUL] = {.convert = [](convert_args){
        if (instr->mDetail.op_count == 3 && instr->mDetail.operands[2].type == X86_OP_IMM && instr->mDetail.operands[0].size == 4)
            return "$wr0 = $rd1 * $rd2;";
        assert(0);
        return "";
    } },
    [X86_INS_OUT] = {.convert = [](convert_args){ return "out$width1($rd0, $rd1);"; } },
    [X86_INS_INT3] = {.convert = [](convert_args){ return "stop();"; } },
    [X86_INS_NOT] = {.convert = [](convert_args){ return "$wr0 = ~$rd0;"; } },
    [X86_INS_DIV] = {.convert = [](convert_args){ return "div$width0($rd0);"; } },
    [X86_INS_IDIV] = {.convert = [](convert_args){ return "idiv$width0($rd0);"; } },
    [X86_INS_SAR] = {.convert = [](convert_args){ return "$wr0 = sar$width0($rd0, $rd1);"; } },
    [X86_INS_IN] = {.convert = [](convert_args){ return "$wr0 = in$width0($rd1);"; } },
    // float
    [X86_INS_FLD] = {.convert = [](convert_args){ return "fld$width0($rd0);"; } },
    [X86_INS_FILD] = {.convert = [](convert_args){ return "fild$width0($rd0);"; } },
    [X86_INS_FMUL] = {.convert = [](convert_args){ return "fmul$width0($rd0);"; } },
    [X86_INS_FDIV] = {.convert = [](convert_args){ return "fdiv$width0($rd0);"; } },
    [X86_INS_FADD] = {.convert = [](convert_args){
        if (strcmp(instr->mMnemonic, "fadd") == 0)
            return "fadd$width0($rd0);";
        else if (strcmp(instr->mMnemonic, "faddp") == 0)
            return "faddp$width0($rd0);";
        else
            assert(0);
    } },
    [X86_INS_FSTP] = {.convert = [](convert_args){ return "$wr0 = fstp$width0();"; } },
    [X86_INS_FLD1] = {.convert = [](convert_args){ return "fld1();"; } },
    [X86_INS_FSUBR] = {.convert = [](convert_args){ return "fsubr$width0($rd0);"; } },
    [X86_INS_FSUBP] = {.convert = [](convert_args){ return "fsubp$width0($rd0);"; } },
    [X86_INS_FCOMP] = {.convert = [](convert_args){
        return "fcomp$width0($rd0);"; } },
    [X86_INS_FISTP] = {.convert = [](convert_args){ return "$wr0 = fistp$width0();"; } },
    [X86_INS_FNSTSW] = {.convert = [](convert_args){ return "$wr0 = fnstsw();"; } },
    [X86_INS_FCOS] = {.convert = [](convert_args){ return "fcos();"; } },
    [X86_INS_WAIT] = {.convert = [](convert_args){ return ""; } },
    [X86_INS_FXCH] = {.convert = [](convert_args){ return "fxch($rd0);"; } },
    [X86_INS_FPREM] = {.convert = [](convert_args){ return "fprem();"; } },
    [X86_INS_FNSTCW] = {.convert = [](convert_args){ return "$wr0 = fnstcw();"; } },
    [X86_INS_FLDCW] = {.convert = [](convert_args){ return "fldcw($rd0);"; } },
    [X86_INS_FRNDINT] = {.convert = [](convert_args){ return "frndtint();"; } },

    [X86_INS_SCASB] = {.convert = [](convert_args){ return ConvertStringopName(instr); },
        .zf = [](convert_args){ return "flags.zero"; }
    },
    [X86_INS_MOVSB] = {.convert = [](convert_args){ return ConvertStringopName(instr); }},
    [X86_INS_STOSB] = {.convert = [](convert_args){ return ConvertStringopName(instr); }},
    [X86_INS_STOSW] = {.convert = [](convert_args){ return ConvertStringopName(instr); }},
    [X86_INS_MOVSW] = {.convert = [](convert_args){ return ConvertStringopName(instr); }},
    [X86_INS_STOSD] = {.convert = [](convert_args){ return ConvertStringopName(instr); }},
    [X86_INS_CWDE] = {.convert = [](convert_args){ return "$realmode ? cbw() : cwde();"; } }, // CBW/CWDE

};

class Convert : public Formatter
{
    const Analyser& mAnal;
    const Options& mOptions;
    shared<CTracer> mTracer;
    std::set<address_t, cmp_adress_t> mCalls;
    std::vector<std::string> mCode;
    
public:
    Convert(const Analyser& anal, const Options& options) : mAnal(anal), mOptions(options)
    {
    }

    void ConvertProc(address_t proc)
    {
        const bool verbose{false};
        
        mTracer = mAnal.mMethods.find(proc)->second;
        CTracer::code_t& code = mTracer->GetCode();

        if (code.size() == 1 && code.begin()->second->mId == X86_INS_JMP)
        {
            // stub
            mCode.push_back(format("void sub_%x()\n{\n", proc.linearOffset()));
            mCode.push_back(format("  sub_%x();\n", code.begin()->second->JumpTarget().linearOffset()));
            mCode.push_back("}\n\n");
            mCalls.insert(code.begin()->second->JumpTarget());
            return;
        }
        assert(mAnal.mInfos.find(proc) != mAnal.mInfos.end());
        shared<Analyser::info_t> info = mAnal.mInfos.find(proc)->second;
        
        mCode.push_back(format("void sub_%x()\n{\n", proc.linearOffset()));
        
        int tempCounter = 0;
        for (const auto& p : code)
        {
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            if (pinfo->flagCarry.save)
            {
                assert(tempCounter++ == 0);
                mCode.push_back("  bool temp_cf;\n");
            }
        }

        if (tempCounter)
            mCode.push_back("\n");

        assert(!code.empty());
        if (code.begin()->first != proc)
            mCode.push_back(format("  goto loc_%x;\n", proc.linearOffset()));

        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                mCode.push_back(format("  // gap %d bytes\n", p.first.offset - next.offset));
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
            if (verbose)
                printf("/*%x %s %s*/\n", p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);
            if (pinstr->isLabel)
                mCode.push_back(format("loc_%x:\n", pinstr->mAddress.linearOffset()));
            if (pinfo->flagCarry.save)
            {
                assert(convert[pinstr->mId].savecf);
                mCode.push_back(("  temp_cf = " + iformat(pinstr, pinfo, convert[pinstr->mId].savecf(p.second, pinfo) + ";\n")).c_str());
            }
            
            if (pinstr->IsIndirectCall() && mOptions.GetJumpTable(pinstr->mAddress))
            {
                DumpIndirectTable(mOptions.GetJumpTable(pinstr->mAddress));
            } else
            if (convert[pinstr->mId].convert)
            {
                mCode.push_back("  " + iformat(pinstr, pinfo, convert[pinstr->mId].convert(p.second, pinfo)) + "\n");
            }
            else
            {
                printf("Conversion for '%s'/%x (ZF=%s/%x, CF=%s, OF=%s, SF=%s) not implemented!\n", pinstr->AsString().c_str(), pinstr->mAddress.offset, Capstone->ToString(pinfo->flagZero.lastSetInsn), pinfo->flagZero.lastSet.offset, Capstone->ToString(pinfo->flagCarry.lastSetInsn), Capstone->ToString(pinfo->flagOverflow.lastSetInsn), Capstone->ToString(pinfo->flagSign.lastSetInsn));
                assert(0);
            }
            if (pinstr->isTerminating)
                mCode.push_back("  stop();\n");
                
            next = {p.second->mAddress.segment, p.second->mAddress.offset + p.second->mSize};
        }
        mCode.push_back("}\n\n");
    }
    
    void DumpIndirectTable(shared<jumpTable_t> jt)
    {
        mCode.push_back(format("  switch (%s)\n", jt->selector));
        mCode.push_back(format("  {\n"));
        for (int i=0; i<jt->GetSize(); i++)
        {
            mCode.push_back(format("    %s\n", jt->GetCase(i).c_str()));
            mCalls.insert(jt->GetTarget(i));
        }
        mCode.push_back(format("    default:\n"));
        mCode.push_back(format("      stop();\n"));
        mCode.push_back(format("  }\n"));
    }
    
    std::string InvertCondition(std::string cond)
    {
        if (cond == "$rd0" || cond == "flags.carry" || cond == "flags.zero")
            return "!" + cond;
        if (cond == "$rd0 == $rd1")
            return "$rd0 != $rd1";
        if (cond == "$rd0 < $rd1")
            return "$rd0 >= $rd1";
        if (cond == "$rd0 & $rd1")
            return "!($rd0 & $rd1)";
        if (cond == "($sig0)$rd0 < 0")
            return "($sig0)$rd0 >= 0";
        if (cond == "!$rd0")
            return "$rd0";
        if (cond == "temp_cf")
            return "!temp_cf";
        assert(0);
        return "!(" + cond + ")";
    }
    virtual std::string BuildCondition(shared<CapInstr> instr, shared<instrInfo_t> info, bool invert) override
    {
        convert_t czf = convert[info->flagZero.lastSetInsn];
        convert_t csf = convert[info->flagSign.lastSetInsn];
        convert_t ccf = convert[info->flagCarry.lastSetInsn];

        std::string cond;
        shared<CapInstr> refzf;
        shared<CapInstr> refcf;
        shared<CapInstr> refsf;

        if (info->flagZero.lastSet)
            refzf = mTracer->GetCode().find(info->flagZero.lastSet)->second;
        if (info->flagCarry.lastSet)
            refcf = mTracer->GetCode().find(info->flagCarry.lastSet)->second;
        if (info->flagSign.lastSet)
            refsf = mTracer->GetCode().find(info->flagSign.lastSet)->second;
        
        switch (instr->mId)
        {
            case X86_INS_JE:
                assert(czf.zf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return iformat(refzf, info, czf.zf(refzf, info));
            case X86_INS_JNE:
                assert(czf.zf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return iformat(refzf, info, InvertCondition(czf.zf(refzf, info)));
            case X86_INS_JAE:
                if (info->flagCarry.saved)
                    return InvertCondition("temp_cf");
                assert(ccf.cf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return iformat(refcf, info, InvertCondition(ccf.cf(refzf, info)));
            case X86_INS_JLE:
                switch(refzf->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(refzf, info, "($sig0)$rd0 <= ($sig1)$rd1");
                    case X86_INS_TEST:
                        assert(refzf->ArgsEqual());
                        return iformat(refzf, info, "($sig0)$rd0 <= 0");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JGE:
                switch(refzf->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(refzf, info, "($sig0)$rd0 >= ($sig1)$rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JL:
                switch(refzf->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(refzf, info, "($sig0)$rd0 < ($sig1)$rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JG:
                switch(refzf->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(refzf, info, "($sig0)$rd0 > ($sig1)$rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JA:
                assert(ccf.cf && czf.zf); // CF == 0 && ZF == 0
                if (ccf.cf(refcf, info) == "$rd0 < $rd1" && czf.zf(refzf, info) == "$rd0 == $rd1")
                    return iformat(refzf, info, "$rd0 > $rd1");
                assert(0);
                return "";
            case X86_INS_JB:
                switch(refcf->mId)
                {
                    case X86_INS_SAHF:
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(refcf, info, "flags.carry");
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(refcf, info, "$rd0 < $rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JBE:
                switch(refcf->mId)
                {
                    case X86_INS_CMP:
                        assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(refcf, info, "$rd0 <= $rd1");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JNP:
                switch(refzf->mId)
                {
                    case X86_INS_SAHF:
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(refzf, info, "!flags.parity");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JP:
                switch(refzf->mId)
                {
                    case X86_INS_SAHF:
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        return iformat(refzf, info, "flags.parity");
                    default:
                        assert(0);
                        return "";
                }
            case X86_INS_JNS:
                assert(csf.sf);
                assert(!info->flagSign.dirty[0] && !info->flagSign.dirty[1]);
                return iformat(refsf, info, InvertCondition(csf.sf(refsf, info)));
            case X86_INS_JS:
                assert(csf.sf);
                assert(!info->flagSign.dirty[0] && !info->flagSign.dirty[1]);
                return iformat(refsf, info, csf.sf(refsf, info));

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
