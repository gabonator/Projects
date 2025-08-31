//
//  formatter.h
//  cicodis32
//
//  Created by Gabriel Valky on 26/06/2025.
//

class Formatter {
    uint64_t mOffsetMask{-1ul};
    
public:
    virtual std::string BuildCondition(shared<CapInstr> instr, shared<instrInfo_t> info, const funcInfo_t& func) = 0;
    virtual std::string BuildStringOp(shared<CapInstr> instr, shared<instrInfo_t> info) = 0;
    
    void SetOffsetMask(uint64_t mask)
    {
        mOffsetMask = mask;
    }
    
    const char* memorySuffix(int w)
    {
        switch (w)
        {
            case 1: return "";
            case 2: return "16";
            case 4: return "32";
            case 8: return "64";
            default:
                assert(0);
                return "";
        }
    }
    void GetOpAddress(const cs_x86_op& op, char* segment, char* offset, shared<instrInfo_t> info, funcInfo_t func)
    {
        const int negativeoffset = 65536;
        strcpy(offset, "");
        
        if (op.mem.base == X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID)
            snprintf(offset, 32, "0x%04x", (int)(op.mem.disp & mOffsetMask));
        else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID && op.mem.disp == 0)
            snprintf(offset, 32, "%s", Capstone->ToString(op.mem.base));
        else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID)
        {
            if (op.mem.base != X86_REG_BP && op.mem.base != X86_REG_EBP)
            {
                if (func.arch == arch_t::arch16)
                {
                    if ((op.mem.disp & 0xffff) > negativeoffset)
                        snprintf(offset, 32, "%s - %d", Capstone->ToString(op.mem.base), 65536-((int)op.mem.disp & 0xffff));
                    else
                        snprintf(offset, 32, "%s + %d", Capstone->ToString(op.mem.base), (int)op.mem.disp & 0xffff);
                } else {
                    snprintf(offset, 32, "%s + %d", Capstone->ToString(op.mem.base), (int)op.mem.disp);
                }
            }
            else
            {
                if (func.arch == arch_t::arch16)
                {
                    if ((op.mem.disp & 0xffff) < 60000)
                    {
                        if ((op.mem.disp & 0xffff) > negativeoffset)
                            snprintf(offset, 32, "%s - %d", Capstone->ToString(op.mem.base), 65536-((int)op.mem.disp & 0xffff));
                        else
                            snprintf(offset, 32, "%s + %d", Capstone->ToString(op.mem.base), (int)op.mem.disp & 0xffff);
                    }
                    else
                        snprintf(offset, 32, "%s - %d", Capstone->ToString(op.mem.base), 0x10000-abs((int)op.mem.disp & 0xffff));
                } else
                    snprintf(offset, 32, "%s + %d", Capstone->ToString(op.mem.base), (int)op.mem.disp);
            }
        }
        else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index != X86_REG_INVALID && op.mem.disp == 0)
            snprintf(offset, 32, "%s + %s", Capstone->ToString(op.mem.base), Capstone->ToString(op.mem.index));
        else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index != X86_REG_INVALID && op.mem.disp != 0)
        {
//            assert(0);
//            if ((op.mem.disp & 0xffff) > negativeoffset)
//                snprintf(offset, 32, "%s + %s - %d", Capstone->ToString(op.mem.base), Capstone->ToString(op.mem.index), 65536-((int)op.mem.disp & 0xffff) );
//            else
//                snprintf(offset, 32, "%s + %s + %d", Capstone->ToString(op.mem.base), Capstone->ToString(op.mem.index), (int)op.mem.disp & 0xffff);
            snprintf(offset, 32, "%s + %s + %d", Capstone->ToString(op.mem.base), Capstone->ToString(op.mem.index), (int)op.mem.disp);
        }
        else if (op.mem.base != X86_REG_INVALID && op.mem.index != X86_REG_INVALID && op.mem.scale != 1 && op.mem.disp == 0)
        {
            snprintf(offset, 32, "%s + %s*%d", Capstone->ToString(op.mem.base), Capstone->ToString(op.mem.index), (int)op.mem.scale);
        }
        else
            assert(0);
        
        strcpy(segment, "?");
        switch (op.mem.segment)
        {
            case X86_REG_INVALID:
                strcpy(segment, op.mem.base == X86_REG_BP || op.mem.base == X86_REG_EBP ? "ss" : "ds");
                if (op.mem.base == X86_REG_BP || op.mem.base == X86_REG_EBP)
                {
                    switch (func.callConv)
                    {
                        case callConv_t::callConvSimpleStackNear:
                            strcat(offset, " - 2");
                            break;
                        case callConv_t::callConvSimpleStackFar:
                            strcat(offset, " - 4");
                            break;
                        case callConv_t::callConvShiftStackNear:
                        case callConv_t::callConvShiftStackFar:
                        case callConv_t::callConvShiftStackNearFar:
                        case callConv_t::callConvNear:
                        case callConv_t::callConvFar:
                            break;
                        default:
                            strcat(offset, " - stop(\"simple stack\")");
                            break;
                    }
                }
                break;
            default:
                strcpy(segment, Capstone->ToString(op.mem.segment));
        }
    }
    
    std::string ToCString(const cs_x86_op& op, shared<instrInfo_t> info, const funcInfo_t& func)
    {
        if (op.type == X86_OP_REG)
            return Capstone->ToString(op.reg);
        if (op.type == X86_OP_IMM && op.size == 1)
        {
            char tmp[32];
            snprintf(tmp, 32, "0x%02llx", op.imm);
            return tmp;
        }
        if (op.type == X86_OP_IMM && op.size == 2)
        {
            char tmp[32];
            snprintf(tmp, 32, "0x%04llx", op.imm & 0xffff);
            return tmp;
        }
        if (op.type == X86_OP_IMM && op.size == 4)
        {
            char tmp[32];
            snprintf(tmp, 32, "0x%08llx", op.imm & 0xffffffff);
            return tmp;
        }
        if (op.type == X86_OP_IMM && op.size == 0)
        {
            assert(0);
            char tmp[32];
            snprintf(tmp, 32, "%d", (int)(op.imm & 0xffffffff));
            return tmp;
        }
        if (op.type == X86_OP_MEM)
        {
            char segment[32], offset[32], tmp[64];
            GetOpAddress(op, segment, offset, info, func);
            snprintf(tmp, 32, "memory%s(%s, %s)", memorySuffix(op.size), segment, offset);
            return tmp;
        }
        printf("error: %d, %d\n", op.type, op.size);
        assert(0);
        return "?";
    }
    
    std::string enclose(const std::string& str)
    {
        assert(str[str.length()-1] == ';');
        if (str.find(" ") == std::string::npos)
            return str.substr(0, str.length()-1);
        return format("(%s)", str.substr(0, str.length()-1).c_str());
    }
    const char* SignedType(const cs_x86_op& op)
    {
        if (op.size == 1)
            return "char";
        if (op.size == 2)
            return "short";
        if (op.size == 4)
            return "int32_t";
        assert(0);
        return "?";
    }
    
    //std::string format(const cs_x86& x86, std::string fmt_)
    std::string iformat(shared<CapInstr> instr, shared<instrInfo_t> info, const funcInfo_t& func, std::string fmt_)
    {
        if (fmt_.find("; ") != std::string::npos)
        {
            assert(fmt_.substr(fmt_.size()-1, 1) == ";");
            std::vector<std::string> parts = utils::split(fmt_.substr(0, fmt_.size()-1), ";");
            std::vector<std::string> newParts;
            std::string aux;
            for (std::string part : parts)
                aux += iformat(instr, info, func, utils::trim(part)+";") + " ";
            return utils::trim(aux);
        }
        
        if (fmt_ == "")
            return "";
        if (fmt_ == "$string")
            return BuildStringOp(instr, info);
        
        const cs_x86& x86 = instr->mDetail;
        assert(fmt_.length() < 128);
        
        const bool getset = true;
        char fmt[256];
        char tok[32];
        
        strcpy(fmt, fmt_.c_str());
        char* p = fmt;
        
        if (getset)
        {
            bool firstWr = memcmp(fmt, "$wr", 3) == 0 && fmt[3] >= '0' && fmt[3] <= '5';
            bool firstRdWr = memcmp(fmt, "$rw", 3) == 0 && fmt[3] >= '0' && fmt[3] <= '5';
            if (firstWr || firstRdWr)
            {
                int index = fmt[3] - '0';
                assert(index >= 0 && index <= 5);
                if (x86.op_count < index+1)
                    return "PROBLEM-11d";
                
                assert(x86.op_count >= index+1);
                const cs_x86_op& op = x86.operands[index];
                assert(op.type == X86_OP_MEM || op.type == X86_OP_REG);
                if (op.type == X86_OP_MEM)
                {
                    if (firstRdWr)
                    {
                        char newfmt[64] = "";
                        if (strcmp(fmt+4, "++;") == 0)
                            snprintf(newfmt, 64, "$wr%d = $rd%d + 1;", index, index);
                        else if (strcmp(fmt+4, "--;") == 0)
                            snprintf(newfmt, 64, "$wr%d = $rd%d - 1;", index, index);
                        else if (strncmp(fmt+4, " |= ", 4) == 0)
                            snprintf(newfmt, 64, "$wr%d = $rd%d | %s;", index, index, enclose(fmt+8).c_str());
                        else if (strncmp(fmt+4, " &= ", 4) == 0)
                            snprintf(newfmt, 64, "$wr%d = $rd%d & %s;", index, index, enclose(fmt+8).c_str());
                        else if (strncmp(fmt+4, " += ", 4) == 0)
                            snprintf(newfmt, 64, "$wr%d = $rd%d + %s;", index, index, enclose(fmt+8).c_str());
                        else if (strncmp(fmt+4, " -= ", 4) == 0)
                            snprintf(newfmt, 64, "$wr%d = $rd%d - %s;", index, index, enclose(fmt+8).c_str());
                        else if (strncmp(fmt+4, " ^= ", 4) == 0)
                            snprintf(newfmt, 64, "$wr%d = $rd%d ^ %s;", index, index, enclose(fmt+8).c_str());
                        else if (strncmp(fmt+4, " >>= ", 5) == 0)
                            snprintf(newfmt, 64, "$wr%d = $rd%d >> %s;", index, index, enclose(fmt+9).c_str());
                        else if (strncmp(fmt+4, " <<= ", 5) == 0)
                            snprintf(newfmt, 64, "$wr%d = $rd%d << %s;", index, index, enclose(fmt+9).c_str());
                        else
                            assert(0);
                        strcpy(fmt, newfmt);
                    }
                    char rvalue[32] = "";
                    assert(fmt[5] == '=' && fmt[6] == ' ');
                    strcat(rvalue, fmt+7);
                    assert(rvalue[strlen(rvalue)-1] == ';');
                    rvalue[strlen(rvalue)-1] = 0;
                    
                    std::string rvalue_formatted = iformat(instr, info, func, rvalue);
                    
                    char segment[32], offset[32], tmp[128];
                    GetOpAddress(op, segment, offset, info, func);
                    snprintf(tmp, 128, "memoryASet%s(%s, %s, %s);", memorySuffix(x86.operands[index].size), segment, offset, rvalue_formatted.c_str());
                    return tmp;
                } else {
                    char tmp[128];
                    //assert(0);
                    strcpy(tmp, ToCString(op, info, func).c_str());
                    strcat(tmp, fmt+4);
                    strcpy(fmt, tmp);
                }
            }
        }
        
        while ((p = strstr(p, "$")) != nullptr)
        {
            char replace[128];
            p++;
            tok[0] = 0;
            for (int i=0; i<32; i++)
            {
                tok[i] = p[i];
                if ((p[i] >= '0' && p[i] <= '9') || (p[i] >= 'a' && p[i] <= 'z') || p[i] == '_')
                    continue;
                
                tok[i] = 0;
                break;
            }
            
            strcpy(replace, "");
            if (strcmp(tok, "reg0") == 0)
            {
                assert(x86.op_count >= 1 /*&& x86.operands[0].type == X86_OP_REG*/);
                strcpy(replace, ToCString(x86.operands[0], info, func).c_str());
            }
            if (strcmp(tok, "reg1") == 0)
            {
                assert(x86.op_count == 2 && x86.operands[1].type == X86_OP_REG);
                strcpy(replace, ToCString(x86.operands[1], info, func).c_str());
            }
            if (strcmp(tok, "immd0") == 0)
            {
                assert(x86.op_count >= 1 && x86.operands[0].type == X86_OP_IMM);
                snprintf(replace, 64, "%d", (int)x86.operands[0].imm);
            }
            if (strcmp(tok, "immx0") == 0)
            {
                assert(x86.op_count >= 1 && x86.operands[0].type == X86_OP_IMM);
                snprintf(replace, 64, "0x%x", (int)x86.operands[0].imm);
            }
            if (strcmp(tok, "immd1") == 0)
            {
                assert(x86.op_count >= 2 && x86.operands[1].type == X86_OP_IMM);
                snprintf(replace, 64, "%d", (int)x86.operands[1].imm);
            }
            if (strcmp(tok, "immx1") == 0)
            {
                assert(x86.op_count >= 2 && x86.operands[1].type == X86_OP_IMM);
                snprintf(replace, 64, "0x%x", (int)x86.operands[1].imm);
            }
            if (strcmp(tok, "wr0") == 0 || strcmp(tok, "rd0") == 0 || strcmp(tok, "rw0") == 0 || strcmp(tok, "rm0") == 0)
            {
                if (x86.op_count == 0)
                {
                    strcpy(replace, "PROBLEM-11");
                } else {
                    assert(x86.op_count >= 1);
                    if (getset && x86.operands[0].type == X86_OP_MEM)
                    {
                        char segment[32], offset[32];
                        GetOpAddress(x86.operands[0], segment, offset, info, func);
                        switch (tok[1] == 'm' ? 2 : x86.operands[0].size)
                        {
                            case 1:
                                snprintf(replace, 64, "memoryAGet(%s, %s)", segment, offset);
                                break;
                            case 2:
                                snprintf(replace, 64, "memoryAGet16(%s, %s)", segment, offset);
                                break;
                            case 4:
                                snprintf(replace, 64, "memoryAGet32(%s, %s)", segment, offset);
                                break;
                            case 8:
                                snprintf(replace, 64, "memoryAGet64(%s, %s)", segment, offset);
                                break;
                            case 10:
                                snprintf(replace, 64, "memoryAGet80(%s, %s)", segment, offset);
                                break;
                            default:
                                assert(0);
                        }
                    } else
                        strcpy(replace, ToCString(x86.operands[0], info, func).c_str());
                }
            }
            if (strcmp(tok, "rns0") == 0)
            {
                assert(x86.op_count >= 1);
                if (getset && x86.operands[0].type == X86_OP_MEM)
                {
                    assert(x86.operands[0].size == 4);
                    char segment[32], offset[32];
                    GetOpAddress(x86.operands[0], segment, offset, info, func);
                    snprintf(replace, 64, "memoryAGet16(%s, %s + 2)", segment, offset);
                } else
                    assert(0);
            }
            if (strcmp(tok, "adr1") == 0)
            {
                assert(x86.op_count >= 1);
                if (getset && x86.operands[1].type == X86_OP_MEM)
                {
                    char segment[32], offset[32];
                    GetOpAddress(x86.operands[1], segment, offset, info, func);
                    strcpy(replace, offset);
                } else
                    assert(0);
            }
            if (strcmp(tok, "addr") == 0)
            {
                snprintf(replace, 64, "%04x:%04x", instr->mAddress.segment, instr->mAddress.offset);
            }
            if (strcmp(tok, "seg") == 0)
            {
                snprintf(replace, 64, "0x%04x", instr->mAddress.segment);
            }
            if (strcmp(tok, "ltarget") == 0)
            {
                // LCALL target
                assert(instr->IsDirectCall());
                snprintf(replace, 64, "sub_%x", instr->CallTarget().linearOffset());
            }

            if (strcmp(tok, "rn1") == 0)
            {
                assert(x86.op_count >= 2);
                if (getset && x86.operands[1].type == X86_OP_MEM)
                {
                    char segment[32], offset[32];
                    GetOpAddress(x86.operands[1], segment, offset, info, func);
//                    if (instr->mId == X86_INS_LES || instr->mId == X86_INS_LDS)
//                        snprintf(replace, 64, "memoryAGet16(%s, %s + 2)", segment, offset);
//                    else
                        snprintf(replace, 64, "memoryAGet%s(%s, %s + 2)",
                             memorySuffix(x86.operands[1].size), segment, offset);
                } else
                    assert(0);
                
            }
            if (strcmp(tok, "wr1") == 0 || strcmp(tok, "rd1") == 0 || strcmp(tok, "rw1") == 0)
            {
                if (x86.op_count == 0)
                    strcpy(replace, "PROBLEM-11f");
                else
                {
                    if(x86.op_count >= 2)
                    {
                        if (getset && x86.operands[1].type == X86_OP_MEM)
                        {
                            char segment[32], offset[32];
                            GetOpAddress(x86.operands[1], segment, offset, info, func);
                            if (instr->mId == X86_INS_LES || instr->mId == X86_INS_LDS)
                                snprintf(replace, 64, "memoryAGet16(%s, %s)", segment, offset);
                            else
                                snprintf(replace, 64, "memoryAGet%s(%s, %s)",
                                     memorySuffix(x86.operands[1].size), segment, offset);
                        } else
                            strcpy(replace, ToCString(x86.operands[1], info, func).c_str());
                    } else {
                        // capstone 5
                        if (x86.opcode[0] == 0xd0 || x86.opcode[0] == 0xd1 || x86.opcode[0] == 0xfe) // RCL, INC
                            strcpy(replace, "1");
                        else
                        {
                            printf("single arg opcode: %02x %02x %02x %02x", x86.opcode[0], x86.opcode[1], x86.opcode[2], x86.opcode[3]);
                            assert(!"two args expected");
                        }
                    }
                }
            }
            if (strcmp(tok, "rd2") == 0)
            {
                assert(x86.op_count >= 3);
                strcpy(replace, ToCString(x86.operands[2], info, func).c_str());
            }
            if (strcmp(tok, "sig0") == 0)
            {
                assert(x86.op_count >= 1);
                strcpy(replace, SignedType(x86.operands[0]));
            }
            if (strcmp(tok, "sig1") == 0)
            {
                assert(x86.op_count >= 2);
                strcpy(replace, SignedType(x86.operands[1]));
            }
            if (strcmp(tok, "msb0") == 0)
            {
                assert(x86.op_count >= 1);
                switch (x86.operands[0].size)
                {
                    case 1:
                        strcpy(replace, "0x80");
                        break;
                    case 2:
                        strcpy(replace, "0x8000");
                        break;
                    case 4:
                        strcpy(replace, "0x80000000");
                        break;
                    default:
                        assert(0);
                }
            }
            if (strcmp(tok, "overflow0") == 0)
            {
                assert(x86.op_count >= 1);
                switch (x86.operands[0].size)
                {
                    case 1:
                        strcpy(replace, "0x100");
                        break;
                    case 2:
                        strcpy(replace, "0x10000");
                        break;
                    default:
                        assert(0);
                }
            }
            if (strcmp(tok, "tmp0") == 0)
            {
                assert(x86.op_count >= 1);
                if (x86.operands[0].size == 1)
                    strcpy(replace, "tl");
                else if (x86.operands[0].size == 2)
                    strcpy(replace, "tx");
                else
                    assert(0);
            }
            if (strcmp(tok, "cond") == 0)
            {
                strcpy(replace, BuildCondition(instr, info, func).c_str());
                assert(replace[0]);
            }
            if (strcmp(tok, "target") == 0)
            {
                assert(x86.op_count == 1);
                assert(x86.operands[0].type == X86_OP_IMM);
                snprintf(replace, 64, "loc_%x", (int)address_t(instr->mAddress.segment, x86.operands[0].imm).linearOffset());
            }
            if (strcmp(tok, "prefix") == 0)
            {
                // TODO: prefix?
                switch (instr->mDetail.prefix[1])
                {
                    case 0:
                    case X86_PREFIX_DS: strncpy(replace, "ds", 64); break;
                    case X86_PREFIX_CS: strncpy(replace, "cs", 64); break;
                    case X86_PREFIX_ES: strncpy(replace, "es", 64); break;
                    case X86_PREFIX_SS: strncpy(replace, "ss", 64); break;
                }
            }
            if (strcmp(tok, "goto_target") == 0)
            {
                assert(x86.op_count == 1);
                if (x86.operands[0].type != X86_OP_IMM)
                {
                    snprintf(replace, 64, "indirectJump(cs, %s); // %04x:%04x", iformat(instr, info, func, "$rd0").c_str(), instr->mAddress.segment, instr->mAddress.offset);
                } else
                {
                    if (x86.operands[0].size == 2)
                        snprintf(replace, 64, "goto loc_%x", (int)address_t(instr->mAddress.segment, x86.operands[0].imm & 0xffff).linearOffset());
                    else
                        snprintf(replace, 64, "goto loc_%x", (int)address_t(instr->mAddress.segment, x86.operands[0].imm).linearOffset());
                }
            }
            if (strcmp(tok, "goto_ltarget") == 0)
            {
                assert(instr->mId == X86_INS_LJMP);
                if (x86.op_count == 2)
                {
                    snprintf(replace, sizeof(replace), "indirectJump(%s, %s);",
                             iformat(instr, info, func, "$rd0").c_str(),
                             iformat(instr, info, func, "$rd1").c_str());
                } else if (x86.op_count == 1)
                {
                    snprintf(replace, sizeof(replace), "cs = %s; indirectJump(cs, %s); stop();",
                             iformat(instr, info, func, "$rns0").c_str(),
                             iformat(instr, info, func, "$rm0").c_str());
                }
            }
            if (strcmp(tok, "method") == 0)
            {
                assert(x86.op_count == 1);
                assert(x86.operands[0].type == X86_OP_IMM);
                if (x86.operands[0].size == 2)
                    snprintf(replace, 64, "sub_%x", (int)address_t(instr->mAddress.segment, x86.operands[0].imm & 0xffff).linearOffset());
                else
                    snprintf(replace, 64, "sub_%x", (int)address_t(instr->mAddress.segment, x86.operands[0].imm).linearOffset());
            }
            if (strcmp(tok, "width0") == 0)
            {
                assert(x86.op_count >= 1);
                snprintf(replace, 64, "%d", x86.operands[0].size*8);
            }
            if (strcmp(tok, "width1") == 0)
            {
                assert(x86.op_count >= 2);
                snprintf(replace, 64, "%d", x86.operands[1].size*8);
            }
//            if (strcmp(tok, "realmode") == 0)
//            {
//                if (mOffsetMask == -1)
//                    strncpy(replace, "false", 64);
//                else
//                    strncpy(replace, "true", 64);
//            }
//            if (strcmp(tok, "rdcarry") == 0)
//            {
//                assert(!info->GetFlag('c').variableRead.empty());
//                strncpy(replace, info->GetFlag('c').variableRead.c_str(), 64);
//            }
//            if (strcmp(tok, "wrcarry") == 0)
//            {
//                if (info->GetFlag('c').variableWrite.empty()) // TODO: should be always set?
//                    strncpy(replace, "flags.carry", 64);
//                else
//                {
//                    assert(!info->GetFlag('c').variableWrite.empty());
//                    strncpy(replace, info->GetFlag('c').variableWrite.c_str(), 64);
//                }
//            }
            if (strcmp(tok, "carry") == 0)
            {
                strncpy(replace, "flags.carry", 64);
            }

            assert(replace[0]);
            char temp[128];
            memcpy(temp, fmt, (p-1)-fmt);
            temp[p-1-fmt] = 0;
            strcat(temp, replace);
            strcat(temp, p+strlen(tok));
            strcpy(fmt, temp);
            if (p-fmt>=strlen(fmt))
                break;
        }
        
        return fmt;
    }
    
};
