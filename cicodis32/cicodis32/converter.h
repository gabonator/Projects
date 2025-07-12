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
    if (args[0] == "al")
        return repeat + templ + "_inv<" + argToTemplate(args[1]) + ">("+args[0]+");";
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
    std::function<std::string(convert_args)> savezf;
    std::function<std::string(convert_args)> saveof;
    std::function<std::string(convert_args)> savesf;
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
    [X86_INS_JE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JNE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JLE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JL] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JAE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JA] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JB] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JBE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JG] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JGE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JP] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JNP] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JNS] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JS] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JMP] = {.convert = [](convert_args){ return "$goto_target;"; } },
    [X86_INS_LOOP] = {.convert = [](convert_args){ return "if (--cx)\n        $goto_target;"; } },
    [X86_INS_LOOPNE] = {.convert = [](convert_args){ return "if (--cx && $cond)\n        $goto_target;"; } },
    [X86_INS_JCXZ] = {.convert = [](convert_args){ return "if (cx==0)\n        $goto_target;"; } },
    [X86_INS_RET] = {.convert = [](convert_args){
        std::vector<std::string> aux;
        if (info->callConv == instrInfo_t::callConvShiftStackNear)
            aux.push_back("sp += 2;");
        if (info->callConv == instrInfo_t::callConvShiftStackFar)
            aux.push_back("sp += 4;");
        if (instr->Imm() != 0)
            aux.push_back("sp += $immd0;");
        if (!(info->isLast && !instr->isLabel))
            aux.push_back("return;");
        return utils::join(aux, "\n    ");
    } },
    [X86_INS_INT] = {.convert = [](convert_args){ return "interrupt($rd0);"; },
            .cf = [](convert_args){ return "flags.carry"; },
            .zf = [](convert_args){ return "flags.zero"; },
    },
    [X86_INS_AND] = {.convert = [](convert_args){ return "$rw0 &= $rd1;"; },
        .zf = [](convert_args){ return "!$rd0"; },
        .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
        .savecf = [](convert_args){ return "0"; },
        .savezf = [](convert_args){ return "!($rd0 & $rd1)"; },
    },
    [X86_INS_OR] = {.convert = [](convert_args){
        return instr->ArgsEqual() ? "" : "$rw0 |= $rd1;";
    },
        .zf = [](convert_args){ return "!$rd0"; },
        .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
    },
    [X86_INS_ADD] = {.convert = [](convert_args){ return "$rw0 += $rd1;"; },
            .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
            .zf = [](convert_args){ return "!$rd0"; },
            .savecf = [](convert_args){ return "($rd0 + $rd1) >= $overflow0"; },
    },
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
            {
//                if (instr->mDetail.operands[0].type == X86_OP_MEM)
//                {
//                    uint16_t realOfs = *(uint16_t*)Capstone->GetBufferAt(instr->CallTarget());
//                    address_t realCs(??);
//                    return format("assert(cs == 0x%04x && memoryAGet16(cs, $rd0) == 0x%04x);\n    sub_%x();\n", realCs, realOfs, realCs*16 + realOfs);
//                } else
                    return "callIndirect(cs, $rd0);";
            }
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
    [X86_INS_SBB] = {.convert = [](convert_args){ return instr->ArgsEqual() ? "$wr0 = -flags.carry;" : "$wr0 = $rd0 - $rd1 - flags.carry /* ggg3 */;"; } }, // TODO: flags carry?
    [X86_INS_SUB] = {.convert = [](convert_args){  return instr->ArgsEqual() ? "$wr0 = 0;" : "$rw0 -= $rd1;"; },
            .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
            .zf = [](convert_args){ return "!$rd0"; },
            .savezf = [](convert_args){ return "$rd0 == $rd1"; },
            .savesf = [](convert_args){ return "($rd0 - $rd1) & $msb0"; },
            .savecf = [](convert_args){ return "$rd0 < $rd1"; },

    },
    [X86_INS_CMP] = {
        .convert = [](convert_args){ return ""; },
        .zf = [](convert_args){ return "$rd0 == $rd1"; },
        .cf = [](convert_args){ return "$rd0 < $rd1"; },
        .sf = [](convert_args){ return "($sig0)$rd0 < ($sig1)$rd1"; }, // TODO: ugly, imm

        .savezf = [](convert_args){ return "$rd0 == $rd1"; },
        .savecf = [](convert_args){ return "$rd0 < $rd1"; },
        .savesf = [](convert_args){ return "($sig0)$rd0 < ($sig1)$rd1"; }, // TODO: ugly, imm
        .numeric = [](convert_args){ return "$rd0"; },
    },
    [X86_INS_TEST] = {
        .convert = [](convert_args){ return ""; },
        .zf = [](convert_args){ return instr->ArgsEqual() ? "!$rd0" : "!($rd0 & $rd1)"; },
        .numeric = [](convert_args){ return "$rd0"; },
        .signedNumeric = [](convert_args){ return "$rd0"; }, //[](convert_args){ return "(sig0)$rd0"; },
    },
    [X86_INS_NEG] = {.convert = [](convert_args){ return "$wr0 = -$rd0;"; },
            .zf = [](convert_args){ return "!$rd0"; },
    },
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
    [X86_INS_LODSW] = {.convert = [](convert_args){
        if (strcmp(instr->mOperands, "ax, word ptr [si]") == 0)
            return "ax = lodsw<DS_SI>();";
        else if (strcmp(instr->mOperands, "ax, word ptr [esi]") == 0)
            return "ax = lodsw<DS_ESI>();";
        assert(0);
        return "";
    } },
    [X86_INS_DEC] = {.convert = [](convert_args){ return "$rw0--;"; },
            .zf = [](convert_args){ return "!$rd0"; },
            .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
            .savezf = [](convert_args){ return "!$rd0 /*gabo-BADBADBAD*/"; },
    },
    [X86_INS_INC] = {
        .convert = [](convert_args){ return "$rw0++;"; },
        .sf = [](convert_args){ return "($sig0)$rd0 < 0";},
        .savezf = [](convert_args){ return "!$rd0 /*gabo-BADBADBAD*/"; }, // TODO:
    },
    [X86_INS_SHR] = {.convert = [](convert_args) {
            return instr->mDetail.operands[1].type == X86_OP_IMM ? "$rw0 >>= $immd1;" : "$rw0 >>= $rd1;";
        },
        .zf = [](convert_args){ return "!$rd0"; },
        //.cf = [](convert_args){ return "temp_cf"; }, // TODO: saved index
        .savecf = [](convert_args){ assert(instr->mDetail.operands[1].type == X86_OP_IMM && instr->mDetail.operands[1].imm == 1); return "$rd0 & 1"; },
    },
    [X86_INS_SHL] = {.convert = [](convert_args){
        return instr->mDetail.operands[1].type == X86_OP_IMM ? "$rw0 <<= $immd1;" : "$rw0 <<= $rd1;";
    } },
    [X86_INS_ROL] = {.convert = [](convert_args){
        return "$wr0 = rol$width0($rd0, $rd1);";
    },
            .cf = [](convert_args){ return "flags.carry /* ggg4 */"; },
    },
    [X86_INS_ROR] = {.convert = [](convert_args){
        return "$wr0 = ror$width0($rd0, $rd1);";
    } },
    [X86_INS_RCR] = {.convert = [](convert_args){
        return "$wr0 = rcr$width0($rd0, $rd1);";
    } },
    [X86_INS_RCL] = {.convert = [](convert_args){
        return "$wr0 = rcl$width0($rd0, $rd1);";
    } },
    [X86_INS_IMUL] = {.convert = [](convert_args){
        if (instr->mDetail.op_count == 3 && instr->mDetail.operands[2].type == X86_OP_IMM && instr->mDetail.operands[0].size == 4)
            return "$wr0 = $rd1 * $rd2;";
        if (instr->mDetail.op_count == 1 && instr->mDetail.operands[0].size == 1)
            return "ax = ((char)$rd0 * (short)ax) & 0xffff;";
        assert(0);
        return "";
    } },
    [X86_INS_OUT] = {.convert = [](convert_args){ return "out$width1($rd0, $rd1);"; } },
    [X86_INS_INT3] = {.convert = [](convert_args){ return "stop(\"breakpoint\");"; } },
    [X86_INS_NOT] = {.convert = [](convert_args){ return "$wr0 = ~$rd0;"; } },
    [X86_INS_DIV] = {.convert = [](convert_args){ return "div$width0($rd0);"; } },
    [X86_INS_IDIV] = {.convert = [](convert_args){ return "idiv$width0($rd0);"; } },
    [X86_INS_MUL] = {.convert = [](convert_args){
        return "mul$width0($rd0);";
    } },
    [X86_INS_SAR] = {.convert = [](convert_args){ return "$wr0 = sar$width0($rd0, $rd1);"; },
        .zf = [](convert_args){ return "!$rd0";},},
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
    [X86_INS_CMPSB] = {.convert = [](convert_args){ return ConvertStringopName(instr); },
        .zf = [](convert_args){ return "flags.zero"; }},
    [X86_INS_CWDE] = {.convert = [](convert_args){ return "$realmode ? cbw() : cwde();"; } }, // CBW/CWDE
    [X86_INS_NOP] = {.convert = [](convert_args){ return ""; } },
    [X86_INS_XCHG] = {.convert = [](convert_args){
        switch (instr->mDetail.operands[0].size)
        {
            case 1:
                return "tl = $rd0; $wr0 = $rd1; $wr1 = tl;";
            case 2:
                return "tx = $rd0; $wr0 = $rd1; $wr1 = tx;";
            default:
                assert(0);
        }
    } },
    [X86_INS_ADC] = {.convert = [](convert_args){
        assert(info->flagCarry.variableRead[0]);
        return format("$rw0 += $rd1 + %s;", info->flagCarry.variableRead); },
            .savecf = [](convert_args){
                assert(info->flagCarry.variableRead[0]);
                return format("($rd0 + $rd1 + %s) >= $overflow0", info->flagCarry.variableRead); },
            .zf = [](convert_args){ return "!$rd0 /*ggg*/"; },
            .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
    },
    [X86_INS_PUSHF] = {.convert = [](convert_args){ return "push(flagAsReg());"; } },
    [X86_INS_POPF] = {.convert = [](convert_args){ return "flagsFromReg(pop());"; } },
    [X86_INS_CMC] = {.convert = [](convert_args){ return "flags.carry = !flags.carry;"; } },
    [X86_INS_XLATB] = {.convert = [](convert_args){ return "al = memoryAGet($prefix, bx+al);"; } },
};

class Convert : public Formatter
{
    const Analyser& mAnal;
    const Options& mOptions;
    shared<CTracer> mTracer;
//    std::set<address_t, cmp_adress_t> mCalls;
    std::vector<std::string> mCode;
    
public:
    Convert(const Analyser& anal, const Options& options) : mAnal(anal), mOptions(options)
    {
    }

    void ConvertProc(address_t proc)
    {
        const bool verbose{true};
        
        mTracer = mAnal.mMethods.find(proc)->second;
        CTracer::code_t& code = mTracer->GetCode();

        for (const auto& p : code)
        {
            if (verbose)
                printf("%s%x %x:%x %s %s\n", p.second->isLabel ? "loc_" : "    ", p.second->mAddress.linearOffset(), p.second->mAddress.segment, p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);
        }

        if (code.size() == 1 && code.begin()->second->mId == X86_INS_JMP)
        {
            // stub
            mCode.push_back(format("void sub_%x()\n{\n", proc.linearOffset()));
            mCode.push_back(format("  sub_%x();\n", code.begin()->second->JumpTarget().linearOffset()));
            mCode.push_back("}\n\n");
//            mCalls.insert(code.begin()->second->JumpTarget());
            return;
        }
        assert(mAnal.mInfos.find(proc) != mAnal.mInfos.end());
        shared<Analyser::info_t> info = mAnal.mInfos.find(proc)->second;
        
        std::string extraInfo = "";
        if (info->request != procRequest_t::returnNone)
        {
            extraInfo += " //";
            if ((int)info->request & (int)procRequest_t::returnCarry)
                extraInfo += " +returnCarry";
            if ((int)info->request & (int)procRequest_t::returnZero)
                extraInfo += " +returnZero";

        }
        mCode.push_back(format("void sub_%x()%s\n{\n", proc.linearOffset(), extraInfo.c_str()));

        struct tempFlag_t {
            char flag = ' ';
            address_t addr;
            char variable[32] = "";
            int index = 0;
        };
        std::set<std::string> tempNames;
        int tempCounter = 0;
        for (const auto& p : code)
        {
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            if (pinfo->flagSign.variableWrite[0])
                tempNames.insert(pinfo->flagSign.variableWrite);
            if (pinfo->flagCarry.variableWrite[0])
                tempNames.insert(pinfo->flagCarry.variableWrite);
            if (pinfo->flagZero.variableWrite[0])
                tempNames.insert(pinfo->flagZero.variableWrite);
            if (pinfo->flagOverflow.variableWrite[0])
                tempNames.insert(pinfo->flagOverflow.variableWrite);
            if (!pinfo->savePrecondition.empty())
                tempNames.insert(pinfo->savePrecondition[0].variable);
        }
        
        for (std::string str : tempNames)
            if (!str.starts_with("flags."))
                mCode.push_back(format("    bool %s;\n", str.c_str()));

        if (tempCounter)
            mCode.push_back("\n");

        assert(!code.empty());

        if (info->code.find(proc)->second->callConv == instrInfo_t::callConvShiftStackNear)
            mCode.push_back("    sp -= 2;\n");
        if (info->code.find(proc)->second->callConv == instrInfo_t::callConvShiftStackFar)
            mCode.push_back("    sp -= 4;\n");

        if (code.begin()->first != proc)
            mCode.push_back(format("    goto loc_%x;\n", proc.linearOffset()));

        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                mCode.push_back(format("  // gap %d bytes\n", p.first.offset - next.offset));
            }
            shared<CapInstr> pinstr = p.second;
//            if (pinstr->mId == X86_INS_CALL)
//            {
//                assert(pinstr->mDetail.op_count == 1);
//                if (pinstr->mDetail.operands[0].type == X86_OP_IMM)
//                    mCalls.insert(pinstr->CallTarget());
//            }
            auto codeit = info->code.find(p.first);
            assert(codeit != info->code.end());
            shared<instrInfo_t> pinfo = info->code.find(p.first)->second;
            if (verbose)
                printf("/*%x %s %s*/\n", p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);
            if (pinstr->isLabel) // && !pinfo->isLast) // TODO: goto ret
                mCode.push_back(format("loc_%x:\n", pinstr->mAddress.linearOffset()));
            // TODO: cmp between label and jump
            //if (std::find(pinstr->mNext.begin(), pinstr->mNext.end(), pinstr->mAddress) != pinstr->mNext.end())
            //    mCode.push_back("    sync();\n");
                
            if (pinfo->flagCarry.save)
            {
                assert(convert[pinstr->mId].savecf);
                mCode.push_back("    " + std::string(pinfo->flagCarry.variableWrite) + " = " + iformat(pinstr, pinfo, convert[pinstr->mId].savecf(p.second, pinfo)) + ";\n");
            }
            if (pinfo->flagZero.save)
            {
                assert(convert[pinstr->mId].savezf);
                mCode.push_back("    " + std::string(pinfo->flagZero.variableWrite) + " = " + iformat(pinstr, pinfo, convert[pinstr->mId].savezf(p.second, pinfo)) + ";\n");
            }
            if (pinfo->flagOverflow.save)
            {
                assert(convert[pinstr->mId].saveof);
                mCode.push_back("    " + std::string(pinfo->flagOverflow.variableWrite) + " = " + iformat(pinstr, pinfo, convert[pinstr->mId].saveof(p.second, pinfo)) + ";\n");
            }
            if (pinfo->flagSign.save)
            {
                assert(convert[pinstr->mId].savesf);
                mCode.push_back("    " + std::string(pinfo->flagSign.variableWrite) + " = " + iformat(pinstr, pinfo, convert[pinstr->mId].savesf(p.second, pinfo)) + ";\n");
            }
            if (pinfo->savePrecondition.size())
            {
                assert(pinfo->savePrecondition.size()==1);
                mCode.push_back("    " + pinfo->savePrecondition[0].variable + " = " + iformat(pinstr, pinfo, precondition(pinstr, pinfo->savePrecondition[0].readOp)) + ";\n");

            }

            if (pinfo->infiniteLoop)
            {
                bool memOp = false;
                for (int i=0; i<pinstr->mDetail.op_count; i++)
                    if (pinstr->mDetail.operands[i].type == X86_OP_MEM)
                        memOp = true;
                    
                if (memOp)
                    mCode.push_back("    sync();\n");
                else
                    mCode.push_back("    stop(\"infinite loop\");\n");
            }
            if (pinstr->IsIndirectCall() && mOptions.GetJumpTable(pinstr->mAddress))
            {
                DumpIndirectTable(mOptions.GetJumpTable(pinstr->mAddress));
            } else
            if (pinstr->IsIndirectJump() /*&& mOptions.GetJumpTable(pinstr->mAddress)*/)
            {
                DumpIndirectTable(mOptions.GetJumpTable(pinstr->mAddress));
            } else
            if (convert[pinstr->mId].convert)
            {
                std::string command = iformat(pinstr, pinfo, convert[pinstr->mId].convert(p.second, pinfo));
                if (command.size())
                    mCode.push_back("    " + command + "\n");
            }
            else
            {
                printf("Conversion for '%s'/%x (ZF=%s/%x, CF=%s, OF=%s, SF=%s) not implemented!\n", pinstr->AsString().c_str(), pinstr->mAddress.offset, Capstone->ToString(pinfo->flagZero.lastSetInsn), 0/*pinfo->flagZero.lastSet.offset*/, Capstone->ToString(pinfo->flagCarry.lastSetInsn), Capstone->ToString(pinfo->flagOverflow.lastSetInsn), Capstone->ToString(pinfo->flagSign.lastSetInsn));
                assert(0);
            }
            if (!pinfo->stop.empty())
            {
                mCode.push_back("    stop("  + pinfo->stop + ");\n;");
            }

            if (pinstr->isTerminating)
                mCode.push_back("    stop(\"terminating\");\n");
            if (pinstr->isReturning)
                mCode.push_back("    return;\n");

            next = {p.second->mAddress.segment, p.second->mAddress.offset + p.second->mSize};
        }
        mCode.push_back("}\n");
    }
    
    void DumpIndirectTable(shared<jumpTable_t> jt)
    {
        mCode.push_back(format("    switch (%s)\n", jt->selector));
        mCode.push_back(format("    {\n"));
        for (int i=0; i<jt->GetSize(); i++)
            mCode.push_back(format("        %s\n", jt->GetCase(i).c_str()));
        mCode.push_back(format("        default:\n"));
        mCode.push_back(format("            stop();\n"));
        mCode.push_back(format("    }\n"));
    }
    
    std::string precondition(shared<CapInstr> instr, x86_insn cond)
    {
        x86_insn set = instr->mId;
        if (set == X86_INS_ADD && cond == X86_INS_JG)
            return "($sig0)$rd0 + ($sig0)$rd1 > 0";
        if (set == X86_INS_ADD && cond == X86_INS_JL)
            return "($sig0)$rd0 + ($sig0)$rd1 < 0";
        if (set == X86_INS_ADD && cond == X86_INS_JLE)
            return "($sig0)$rd0 + ($sig0)$rd1 <= 0";
        if (set == X86_INS_SUB && cond == X86_INS_JG)
            return "($sig0)$rd0 - ($sig0)$rd1 > 0";
        if (set == X86_INS_SUB && cond == X86_INS_JLE)
            return "($sig0)$rd0 - ($sig0)$rd1 <= 0";
        assert(0);
        return "";
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
        if (cond == "!($rd0 & $rd1)")
            return "$rd0 & $rd1";
        if (cond == "($sig0)$rd0 < 0")
            return "($sig0)$rd0 >= 0";
        if (cond == "!$rd0")
            return "$rd0";
        if (cond.starts_with("temp_"))
            return "!" + cond;
        if (cond == "($sig0)$rd0 < ($sig1)$rd1")
            return "($sig0)$rd0 >= ($sig1)$rd1";
        if (cond == "!$rd0 /* gabo-3 */")
            return "$rd0 /* gabo-3 */";
        if (cond.starts_with("flags."))
            return "!"+cond;
        assert(0);
        return "!(" + cond + ")";
    }
    virtual std::string BuildCondition(shared<CapInstr> instr, shared<instrInfo_t> info, bool invert) override
    {
        if (!info->readPrecondition.empty())
        {
            assert(info->readPrecondition.size() == 1);
            return info->readPrecondition[0];
        }
        convert_t czf = convert[info->flagZero.lastSetInsn];
        convert_t csf = convert[info->flagSign.lastSetInsn];
        convert_t ccf = convert[info->flagCarry.lastSetInsn];

        std::string cond;
        shared<CapInstr> refzf;
        shared<CapInstr> refcf;
        shared<CapInstr> refsf;

        if (info->flagZero.lastSet.size() == 1)
            refzf = mTracer->GetCode().find(*info->flagZero.lastSet.begin())->second;
        if (info->flagCarry.lastSet.size() == 1)
            refcf = mTracer->GetCode().find(*info->flagCarry.lastSet.begin())->second;
        if (info->flagSign.lastSet.size() == 1)
            refsf = mTracer->GetCode().find(*info->flagSign.lastSet.begin())->second;
        
        switch (instr->mId)
        {
            case X86_INS_JE:
                if (info->flagZero.saved)
                {
                    assert(info->flagZero.variableRead[0]);
                    return info->flagZero.variableRead;
                }
                assert(czf.zf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return iformat(refzf, info, czf.zf(refzf, info));
            case X86_INS_LOOPNE:
            case X86_INS_JNE:
                if (info->flagZero.saved)
                {
                    assert(info->flagZero.variableRead[0]);
                    return InvertCondition(info->flagZero.variableRead);
                }
                assert(czf.zf);
                assert(!info->flagZero.dirty[0] && !info->flagZero.dirty[1]);
                return iformat(refzf, info, InvertCondition(czf.zf(refzf, info)));
            case X86_INS_JAE:
                if (info->flagCarry.saved)
                {
                    assert(info->flagCarry.variableRead[0]);
                    return InvertCondition(info->flagCarry.variableRead);
                }
                assert(ccf.cf);
                assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                return iformat(refcf, info, InvertCondition(ccf.cf(refcf, info)));
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
                    case X86_INS_CALL:
                    case X86_INS_INT:
                        return "flags.carry";
                    default:
                        assert(refcf);
                        assert(!info->flagCarry.dirty[0] && !info->flagCarry.dirty[1]);
                        assert(info->flagCarry.variableRead[0]);
                        return iformat(refcf, info, info->flagCarry.variableRead);
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
                if (info->flagSign.saved)
                    return InvertCondition("temp_sf");
                assert(csf.sf);
                assert(!info->flagSign.dirty[0] && !info->flagSign.dirty[1]);
                return iformat(refsf, info, InvertCondition(csf.sf(refsf, info)));
            case X86_INS_JS:
                if (info->flagSign.saved)
                    return "temp_sf";
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
//    const std::set<address_t, cmp_adress_t>& GetCalls()
//    {
//        return mCalls;
//    }

};
