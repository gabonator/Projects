//
//  convtable.h
//  cicodis32
//
//  Created by Gabriel Valky on 14/07/2025.
//

#define convert_args shared<CapInstr> instr, shared<instrInfo_t> info, const funcInfo_t& func
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
    std::string flagCondition;
    
};

convert_t convert[X86_INS_ENDING] = {
    [X86_INS_PUSH] = {.convert = [](convert_args){ return instr->mDetail.operands[0].size == 4 ? "push32($rd0);" : "push($rd0);";} },
    [X86_INS_POP] = {.convert = [](convert_args){ return instr->mDetail.operands[0].size == 4 ? "$wr0 = pop32();" : "$wr0 = pop();";} },
    [X86_INS_XOR] = {.convert = [](convert_args){
        if (instr->ArgsEqual())
            return "$wr0 = 0;";
        else
            return "$wr0 ^= $rd1;";
    },
        .zf = [](convert_args){ return "!$rd0"; },
        .savezf = [](convert_args){ assert(instr->ArgsEqual()); return "0"; },
    },
    [X86_INS_MOV] = {.convert = [](convert_args){ return "$wr0 = $rd1;"; } },
    [X86_INS_MOVZX] = {.convert = [](convert_args){
        return "$wr0 = $rd1;"; } },
    [X86_INS_JE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; },
        .flagCondition = "$zero"},
    [X86_INS_JNE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; },
        .flagCondition = "!$zero"},
    [X86_INS_JLE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JL] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JAE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; },
        .flagCondition = "!$carry"},
    [X86_INS_JA] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JB] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; },
        .flagCondition = "$carry"},
    [X86_INS_JBE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JG] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JGE] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JP] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JNP] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; } },
    [X86_INS_JNS] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; },
        .flagCondition = "!$sign"},
    [X86_INS_JS] = {.convert = [](convert_args){ return "if ($cond)\n        $goto_target;"; },
        .flagCondition = "$sign"},
    [X86_INS_JMP] = {.convert = [](convert_args){ return "$goto_target;"; } },
    [X86_INS_LOOP] = {.convert = [](convert_args){ return "if (--cx)\n        $goto_target;"; } },
    [X86_INS_LOOPNE] = {.convert = [](convert_args){ return "if (--cx && $cond)\n        $goto_target;"; },
        .flagCondition = "!$zero"},
    [X86_INS_JCXZ] = {.convert = [](convert_args){ return "if (cx==0)\n        $goto_target;"; } },
    [X86_INS_RET] = {.convert = [](convert_args){
        std::vector<std::string> aux;
        if (func.callConv == callConv_t::callConvShiftStackNear)
            aux.push_back("sp += 2;");
        if (func.callConv == callConv_t::callConvShiftStackFar)
            aux.push_back("sp += 4;");
        if (instr->Imm() != 0)
            aux.push_back("sp += $immd0;");
        if (!(instr->isLast && !instr->isLabel))
            aux.push_back("return;");
        return utils::join(aux, "\n    ");
    },
        .flagCondition = "$ret",
    },
    [X86_INS_INT] = {.convert = [](convert_args){ return "interrupt($rd0);"; },
            .cf = [](convert_args){ return "flags.carry"; },
            .zf = [](convert_args){ return "flags.zero"; },
    },
    [X86_INS_AND] = {.convert = [](convert_args){
        return instr->ArgsEqual() ? "" : "$rw0 &= $rd1;"; },
        .zf = [](convert_args){ return "!$rd0"; },
        .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
        .savecf = [](convert_args){ return "0"; },
        .savezf = [](convert_args){ return "!($rd0 & $rd1)"; },
        .savesf = [](convert_args){ return instr->ArgsEqual() ? "($sig0)$rd0 < 0" : "($sig0)($rd0 & $rd1) < 0"; },
    },
    [X86_INS_OR] = {.convert = [](convert_args){
        return instr->ArgsEqual() ? "" : "$rw0 |= $rd1;";
    },
        .zf = [](convert_args){ return "!$rd0"; },
        .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
        .savecf = [](convert_args){ return "0 /* gabo-bad */"; },
        .savezf = [](convert_args){ assert(instr->ArgsEqual()); return "!$rd0"; },
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
    [X86_INS_SBB] = {.convert = [](convert_args){ return instr->ArgsEqual() ? "$wr0 = -$rdcarry;" : "$wr0 = $rd0 - $rd1 - $rdcarry;"; } }, // TODO: flags carry?
    [X86_INS_SUB] = {.convert = [](convert_args){  return instr->ArgsEqual() ? "$wr0 = 0;" : "$rw0 -= $rd1;"; },
            .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
            .zf = [](convert_args){ return instr->ArgsEqual() ? "1" : "!$rd0"; },
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
        .savezf = [](convert_args){
            return "!($rd0 & $rd1)"; },
        .savecf = [](convert_args){ return "0"; },

    },
    [X86_INS_NEG] = {.convert = [](convert_args){ return "$wr0 = -$rd0;"; },
            .zf = [](convert_args){ return "!$rd0"; },
    },
    [X86_INS_CLD] = {.convert = [](convert_args){ return "flags.direction = 0;"; } },
    [X86_INS_STD] = {.convert = [](convert_args){ return "flags.direction = 1;"; } },
    [X86_INS_CLC] = {.convert = [](convert_args){
//        return "flags.carry = 0;";
        return "$wrcarry = 0;";
    },
//            .savecf = [](convert_args){ return "0"; },
    },
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
        .zf = [](convert_args){ return "!$rd0";},
        .savezf = [](convert_args){ return "!$rd0 /*gabo-BADBADBAD*/"; }, // TODO:
    },
    [X86_INS_SHR] = {.convert = [](convert_args) {
            return instr->mDetail.operands[1].type == X86_OP_IMM ? "$rw0 >>= $immd1;" : "$rw0 >>= $rd1;";
        },
        .zf = [](convert_args){ return "!$rd0"; },
        .cf = [](convert_args){ return "$rdcarry"; }, // TODO: saved index
        //.cf = [](convert_args){ return "temp_cf"; }, // TODO: saved index
        .savecf = [](convert_args){ assert(instr->mDetail.operands[1].type == X86_OP_IMM && instr->mDetail.operands[1].imm == 1); return "$rd0 & 1"; },
    },
    [X86_INS_SHL] = {.convert = [](convert_args){
        return instr->mDetail.operands[1].type == X86_OP_IMM ? "$rw0 <<= $immd1;" : "$rw0 <<= $rd1;";
    },
            .savecf = [](convert_args){ assert(instr->Imm() == 1); return "!!($rd0 & $msb0) /*ggg5*/"; },
    },
    [X86_INS_ROL] = {.convert = [](convert_args){
        return "$wr0 = rol$width0($rd0, $rd1);";
    },
            .savecf = [](convert_args){ assert(instr->Imm() == 1); return "!!($rd0 & $msb0)"; },
//            .cf = [](convert_args){ return "flags.carry /* ggg4 */"; },
    },
    [X86_INS_ROR] = {.convert = [](convert_args){
        return "$wr0 = ror$width0($rd0, $rd1);";
    },
            .savecf = [](convert_args){
                return "!!($rd0 & (1 << ($rd1-1))) /*ggg - TODO BAD!*/";
            },
    },
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

    [X86_INS_SCASB] = {.convert = [](convert_args){ return "$string"; },
        .zf = [](convert_args){ return "flags.zero"; }
    },
    [X86_INS_MOVSB] = {.convert = [](convert_args){ return "$string"; }},
    [X86_INS_STOSB] = {.convert = [](convert_args){ return "$string"; }},
    [X86_INS_STOSW] = {.convert = [](convert_args){ return "$string"; }},
    [X86_INS_MOVSW] = {.convert = [](convert_args){ return "$string"; }},
    [X86_INS_STOSD] = {.convert = [](convert_args){ return "$string"; }},
    [X86_INS_CMPSB] = {.convert = [](convert_args){ return "$string"; },
        .zf = [](convert_args){ return "flags.zero"; }},
    [X86_INS_CWDE] = {.convert = [](convert_args){ return "$realmode ? cbw() : cwde();"; } }, // CBW/CWDE
    [X86_INS_CDQ] = {.convert = [](convert_args){ return "if ($realmode)\n        dx = ax & 0x8000 ? 0xffff : 0x0000;\n    else\n        stop(\"cdq\");"; } }, // CWD/CWDE
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
            assert(!info->GetFlag('c').variableRead.empty()); // TODO
                return format("$rw0 += $rd1 + %s;", info->GetFlag('c').variableRead.c_str());
        },
            .savecf = [](convert_args){
                //assert(!info->GetFlag('c').variableRead.empty());
                return "($rd0 + $rd1 + $rdcarry) >= $overflow0"; //, info->GetFlag('c').variableRead.c_str());
            },
            .zf = [](convert_args){ return "!$rd0"; },
            .sf = [](convert_args){ return "($sig0)$rd0 < 0"; },
    },
    [X86_INS_PUSHF] = {.convert = [](convert_args){ return "push(flagAsReg());"; } },
    [X86_INS_POPF] = {.convert = [](convert_args){ return "flagsFromReg(pop());"; } },
    [X86_INS_CMC] = {.convert = [](convert_args){
        return "$wrcarry = !$rdcarry;"; },
        //.savecf = [](convert_args){ return "!$rdcarry /*gabo!!*/"; },
    },
    [X86_INS_XLATB] = {.convert = [](convert_args){ return "al = memoryAGet($prefix, bx+al);"; } },
};
