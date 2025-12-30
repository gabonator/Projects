//
//  convtable.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 12/12/2025.
//

#define convert_args shared<CapInstr> instr, shared<instrInfo_t> info, const funcInfo_t& func

std::function<StatementIr(convert_args)> convertir[X86_INS_ENDING] = {
    [X86_INS_PUSH] = [](convert_args){ return StatementIr{
        .type = StatementIr::Type_t::Function,
        .func = "push",
        .opin1 = std::make_shared<OperandIr>(instr->mDetail.operands[0])}; },
    [X86_INS_POP] = [](convert_args){ //return ASSIGN(OP_X86(instr, 0), OP_FUNCTION("pop")); },
        return StatementIr{
        .type = StatementIr::Type_t::Function,
        .opd = std::make_shared<OperandIr>(instr->mDetail.operands[0]),
        .func = "pop"}; },
    [X86_INS_MOV] = [](convert_args){ return StatementIr{
        .type = StatementIr::Type_t::Assignment,
        .opd = std::make_shared<OperandIr>(instr->mDetail.operands[0]),
        .opin1 = std::make_shared<OperandIr>(instr->mDetail.operands[1])}; },
    [X86_INS_JMP] = [](convert_args){
        assert(instr->mDetail.op_count == 1);
        if (instr->mDetail.operands[0].type == X86_OP_IMM)
            return StatementIr{.type = StatementIr::Type_t::DirectJump, .target = instr->JumpTarget()};
        else
            return StatementIr{.type = StatementIr::Type_t::IndirectJump, .opin1 = OP_REG("cs", 2).get(), .opin2 = OP_X86(instr, 0).get()};
    },
    [X86_INS_LOOP] = [](convert_args){
        auto loopTarget = std::make_shared<StatementIr>(StatementIr{
            .type = StatementIr::Type_t::DirectJump,
            .target = instr->JumpTarget()});
        auto loopCounter = std::make_shared<StatementIr>(StatementIr{
            .type = StatementIr::Type_t::Unary,
            .oper = "--",
            .opin1 = std::make_shared<OperandIr>(OperandIr::Type_t::Register, "cx", 2)});
        auto loopCond = std::make_shared<StatementIr>(StatementIr{
            .type = StatementIr::Type_t::Compare,
            .stmt1 = loopCounter});
        
        return StatementIr{
            .type = StatementIr::Type_t::Condition,
            .stConditionExpr = loopCond,
            .stConditionTrue = loopTarget}; },
    [X86_INS_RET] = [](convert_args){
        int shift = 0;
        assert(((int)func.request & (int)procRequest_t::callNear) ||
               ((int)func.request & (int)procRequest_t::callLong));
        assert(func.callConv == callConv_t::callConvNear ||
               func.callConv == callConv_t::callConvShiftStackNear ||
               func.callConv == callConv_t::callConvSimpleStackNear ||
               func.callConv == callConv_t::callConvShiftStackLong);
        if (func.callConv == callConv_t::callConvShiftStackLong)
            shift += 4;
        if (func.callConv == callConv_t::callConvShiftStackNear)
            shift += 2;
        shift += instr->Imm();
        
        if (shift == 0)
        {
            if (!(instr->isLast && !instr->isLabel))
                return StatementIr{.type = StatementIr::Type_t::Return};
            else
                return StatementIr{};
        } else {
            StatementIr st = OP_MOD("assign") << OP_REG("sp", 2) + OP_CONST(shift);
            if (!(instr->isLast && !instr->isLabel))
                st.next = std::make_shared<StatementIr>(StatementIr{.type = StatementIr::Type_t::Return});
            return st;
        } },
    [X86_INS_RETF] = [](convert_args){
        /*
        int shift = 0;
        assert(((int)func.request & (int)procRequest_t::callNear) ||
               ((int)func.request & (int)procRequest_t::callLong));
        assert(func.callConv == callConv_t::callConvNear ||
               func.callConv == callConv_t::callConvShiftStackNear ||
               func.callConv == callConv_t::callConvSimpleStackNear ||
               func.callConv == callConv_t::callConvShiftStackLong);
        if (func.callConv == callConv_t::callConvShiftStackLong)
            shift += 4;
        if (func.callConv == callConv_t::callConvShiftStackNear)
            shift += 2;
        shift += instr->Imm();
        
        if (shift == 0)
        {
            if (!(instr->isLast && !instr->isLabel))
                return StatementIr{.type = StatementIr::Type_t::Return};
            else
                return StatementIr{};
        } else {
            StatementIr st = OP_MOD("assign") << OP_REG("sp", 2) + OP_CONST(shift);
            if (!(instr->isLast && !instr->isLabel))
                st.next = std::make_shared<StatementIr>(StatementIr{.type = StatementIr::Type_t::Return});
            return st;
        }
         */
        int shift = 0;
        if (!((int)func.request & (int)procRequest_t::callFar))
        {
            if (func.callConv == callConv_t::callConvShiftStackNear)
                shift += 2;
                //aux.push_back("sp += 2;"); // we expect pop,push,push at start  --- TODO
        }
        if (func.callConv == callConv_t::callConvShiftStackFar)
            shift += 2; //assert(0); //aux.push_back("sp += 2;");  // -- TODO POP CS????
        if (func.callConv == callConv_t::callConvShiftStackNearFar)
            shift += 2; //assert(0); //aux.push_back("sp += 2;");
        //aux.push_back("cs = pop();");
        
        shift += instr->Imm();
        
        if (shift == 0)
        {
            StatementIr popcs{.type = StatementIr::Type_t::Function, .opd = OP_REG("cs", 2).get(), .func = "pop"};
            StatementIr ret = {.type = StatementIr::Type_t::Return};
                    
            if (!(instr->isLast && !instr->isLabel))
                popcs.next = std::make_shared<StatementIr>(StatementIr{ret});
            return popcs;
        } else {
            StatementIr spshift = OP_MOD("assign") << OP_REG("sp", 2) + OP_CONST(2);
            StatementIr popcs{.type = StatementIr::Type_t::Function, .opd = OP_REG("cs", 2).get(), .func = "pop"};
            StatementIr spargs = OP_MOD("assign") << OP_REG("sp", 2) + OP_CONST(shift-2);
            StatementIr ret = {.type = StatementIr::Type_t::Return};
            //st.next = std::make_shared<StatementIr>(StatementIr{ret});
            if (!(instr->isLast && !instr->isLabel))
                spargs.next = std::make_shared<StatementIr>(ret);
            popcs.next = std::make_shared<StatementIr>(spargs);
            spshift.next = std::make_shared<StatementIr>(popcs);
            return spshift;
        }
         },
    [X86_INS_INT] = [](convert_args){ return StatementIr{
        .type = StatementIr::Type_t::Function,
        .func = "interrupt",
        .opin1 = std::make_shared<OperandIr>(instr->mDetail.operands[0])}; },
    [X86_INS_AND] = [](convert_args){ return OP_MOD("assign") << (OP_X86(instr, 0) & OP_X86(instr, 1)); },
    [X86_INS_OR] = [](convert_args){
        if (instr->ArgsEqual())
            return StatementIr{};
        return StatementIr(OP_MOD("assign") << (OP_X86(instr, 0) | OP_X86(instr, 1)));
    },
    [X86_INS_ADD] = [](convert_args){ return OP_MOD("assign") << (OP_X86(instr, 0) + OP_X86(instr, 1)); },
    [X86_INS_ADC] = [](convert_args){
        auto sum = OP_BINARY(OP_X86(instr, 1), "+", OP_VAR("flags.carry"));
        return OP_MOD("assign") << OP_BINARY(OP_X86(instr, 0), "+", sum);
    },
    [X86_INS_SBB] = [](convert_args){
        if (instr->ArgsEqual())
            return ASSIGN(OP_X86(instr, 0), - OP_VAR("flags.carry"));
        //return instr->ArgsEqual() ?
        //OP_MOD("assign") << - OP_VAR("flags.carry") :
        return OP_MOD("assign") << OP_BINARY(OP_X86(instr, 0), "-", OP_BINARY(OP_X86(instr, 1), "+", OP_VAR("flags.carry")));
    },
        //(OP_X86(instr, 1) + OP_VAR("flags.carry"))); },
//    [X86_INS_SBB] = {.convert = [](convert_args){ return instr->ArgsEqual() ? "$wr0 = -$carry;" : "$wr0 = $rd0 - $rd1 - $carry;"; },

    [X86_INS_XOR] = [](convert_args){
        if (instr->ArgsEqual())
            return ASSIGN(OP_X86(instr, 0), OP_CONST(0));
        return OP_MOD("assign") << (OP_X86(instr, 0) ^ OP_X86(instr, 1)); },
    [X86_INS_CALL] = [](convert_args){
        if (instr->mDetail.operands[0].type == X86_OP_IMM)
            return StatementIr{.type = StatementIr::Type_t::DirectCall, .target = instr->CallTarget()};
        else
            return StatementIr{.type = StatementIr::Type_t::IndirectCall, .opin1 = OP_X86(instr, 0).get()};
    },
    [X86_INS_SUB] = [](convert_args){ return OP_MOD("assign") << (OP_X86(instr, 0) - OP_X86(instr, 1)); },
    [X86_INS_CMP] = [](convert_args){ return StatementIr{.type = StatementIr::Type_t::None}; },
    [X86_INS_TEST] = [](convert_args){ return StatementIr{.type = StatementIr::Type_t::None}; },
    [X86_INS_NEG] = [](convert_args){ return OP_MOD("assign") << -OP_X86(instr, 0); },
    [X86_INS_CLD] = [](convert_args){ return ASSIGN(OP_VAR("flags.direction"), OP_CONST(0)); },
    [X86_INS_CLI] = [](convert_args){ return ASSIGN(OP_VAR("flags.interrupts"), OP_CONST(0)); },
    [X86_INS_STI] = [](convert_args){ return ASSIGN(OP_VAR("flags.interrupts"), OP_CONST(1)); },
    [X86_INS_CLC] = [](convert_args){ return ASSIGN(OP_VAR("flags.carry"), OP_CONST(0)); },
    [X86_INS_STC] = [](convert_args){ return ASSIGN(OP_VAR("flags.carry"), OP_CONST(1)); },
    [X86_INS_CLD] = [](convert_args){ return ASSIGN(OP_VAR("flags.direction"), OP_CONST(0)); },
    [X86_INS_STD] = [](convert_args){ return ASSIGN(OP_VAR("flags.direction"), OP_CONST(1)); },
    [X86_INS_DEC] = [](convert_args){ return OP_MOD("assign") << (OP_X86(instr, 0) - OP_CONST(1)); },
    [X86_INS_INC] = [](convert_args){ return OP_MOD("assign") << (OP_X86(instr, 0) + OP_CONST(1)); },
    [X86_INS_SHR] = [](convert_args){ return OP_MOD("assign", "decimm") << OP_BINARY(OP_X86(instr, 0), ">>", OP_X86(instr, 1)); },
    [X86_INS_SHL] = [](convert_args){ return OP_MOD("assign", "decimm") << OP_BINARY(OP_X86(instr, 0), "<<", OP_X86(instr, 1)); },
    [X86_INS_RCL] = [](convert_args){ return OP_MOD("assign") << OP_FUNCTION("rcl#", OP_X86(instr, 0), OP_X86(instr, 1)); },
    [X86_INS_RCR] = [](convert_args){ return OP_MOD("assign") << OP_FUNCTION("rcr#", OP_X86(instr, 0), OP_X86(instr, 1)); },
    [X86_INS_ROL] = [](convert_args){ return OP_MOD("assign") << OP_FUNCTION("rol#", OP_X86(instr, 0), OP_X86(instr, 1)); },
    [X86_INS_ROR] = [](convert_args){ return OP_MOD("assign") << OP_FUNCTION("ror#", OP_X86(instr, 0), OP_X86(instr, 1)); },
    [X86_INS_MUL] = [](convert_args){ return OP_FUNCTION("mul#", OP_X86(instr, 0)); },
    [X86_INS_IMUL] = [](convert_args){
        assert(instr->mDetail.op_count < 3);
        if (instr->mDetail.op_count == 1 && instr->mDetail.operands[0].size == 1)
        {
            auto multiplication = OP_BINARY(OP_SIGNED(OP_X86(instr, 0)), "*", OP_SIGNED(OP_REG("ax", 2)));
            return StatementIr(ASSIGN(OP_REG("ax", 2), OP_BINARY(multiplication, "&", OP_CONST(0xffff, 2))));
        }
        if (instr->mDetail.op_count == 1)
            return StatementIr(OP_FUNCTION("imul#", OP_X86(instr, 0)));
        assert(0);
        return StatementIr{};
    },
    [X86_INS_IDIV] = [](convert_args){ assert(instr->mDetail.op_count == 1); return OP_FUNCTION("idiv#", OP_X86(instr, 0)); },
    [X86_INS_OUT] = [](convert_args){ return StatementIr{
                .type = StatementIr::Type_t::Function,
                .func = "out",
                .opin1 = std::make_shared<OperandIr>(instr->mDetail.operands[0]),
                .opin2 = std::make_shared<OperandIr>(instr->mDetail.operands[1]),
                .suffix = instr->mDetail.operands[1].size*8}; },
    [X86_INS_NOT] = [](convert_args){ return OP_MOD("assign") << ~OP_X86(instr, 0); },
    [X86_INS_DIV] = [](convert_args){ return StatementIr{
                .type = StatementIr::Type_t::Function,
                .func = "div",
                .opin1 = std::make_shared<OperandIr>(instr->mDetail.operands[0]),
                .suffix = instr->mDetail.operands[0].size*8 }; },
    [X86_INS_SAR] = [](convert_args){ return StatementIr{
                .type = StatementIr::Type_t::Function,
                .func = "sar",
                .opd = std::make_shared<OperandIr>(instr->mDetail.operands[0]),
                .opin1 = std::make_shared<OperandIr>(instr->mDetail.operands[0]),
                .opin2 = std::make_shared<OperandIr>(instr->mDetail.operands[1]),
                .suffix = instr->mDetail.operands[0].size*8 }; },
    [X86_INS_IN] = [](convert_args){ return StatementIr{
                .type = StatementIr::Type_t::Function,
                .func = "in",
                .opd = std::make_shared<OperandIr>(instr->mDetail.operands[0]),
                .opin1 = std::make_shared<OperandIr>(instr->mDetail.operands[1]),
                .suffix = instr->mDetail.operands[0].size*8}; },
    [X86_INS_CWDE] = [](convert_args){ return StatementIr{
                .type = StatementIr::Type_t::Function,
                .func = func.arch == arch_t::arch16 ? "cbw" : "cwde"}; },
    [X86_INS_NOP] = [](convert_args){ return StatementIr{}; },
    
    [X86_INS_XCHG] = [](convert_args){
        int tempSize = instr->mDetail.operands[0].size;
        std::string tempReg = "";
        switch (tempSize)
        {
            case 1: tempReg = "tl"; break;
            case 2: tempReg = "tx"; break;
            default: assert(0);
        }
        StatementIr a = ASSIGN(OP_REG(tempReg, tempSize), OP_X86(instr, 0));
        StatementIr b = ASSIGN(OP_X86(instr, 0), OP_X86(instr, 1));
        StatementIr c = ASSIGN(OP_X86(instr, 1), OP_REG(tempReg, tempSize));
        b.next = std::make_shared<StatementIr>(c);
        a.next = std::make_shared<StatementIr>(b);
        return a;
    },
    [X86_INS_XLATB] = [](convert_args){
        cs_x86_op op = {
            .type = X86_OP_MEM,
            .size = 1,
            .mem = {
                .base = X86_REG_BX,
                .index = X86_REG_AL,
                .scale = 1,
                .disp = 0
            }
        };
        
        switch (instr->mDetail.prefix[1])
        {
            case 0:
            case X86_PREFIX_DS: op.mem.segment = X86_REG_DS; break;
            case X86_PREFIX_CS: op.mem.segment = X86_REG_CS; break;
            case X86_PREFIX_ES: op.mem.segment = X86_REG_ES; break;
            case X86_PREFIX_SS: op.mem.segment = X86_REG_SS; break;
        }
        
        return ASSIGN(OP_VAR("al"), OP_X86(op));
    },
    [X86_INS_LEA] = [](convert_args){
        //OperandIr op(instr->mDetail.operands[1]);
        //assert()
        assert(instr->mDetail.operands[1].type == X86_OP_MEM);
        assert(instr->mDetail.operands[1].mem.segment == X86_REG_INVALID);
        assert(instr->mDetail.operands[1].mem.index == X86_REG_INVALID);
        assert(instr->mDetail.operands[1].mem.base != X86_REG_INVALID);
        // TODO: bad! ax = bp - 8; loc_21d5
        // TODO: sbc? loc_261a
        // loc_2da4 (?)ax
        std::string regBase = Capstone->ToString(instr->mDetail.operands[1].mem.base);
        assert(regBase == "bp" || regBase == "di");
        if (instr->mDetail.operands[1].mem.disp == 0)
            return ASSIGN(OP_X86(instr, 0), OP_REG(regBase, 2));
        else if (instr->mDetail.operands[1].mem.disp >= 0)
            return ASSIGN(OP_X86(instr, 0), OP_REG(regBase, 2) + OP_CONST(instr->mDetail.operands[1].mem.disp));
        else
            return ASSIGN(OP_X86(instr, 0), OP_REG(regBase, 2) - OP_CONST(-instr->mDetail.operands[1].mem.disp));
    },

    [X86_INS_SAR] = [](convert_args){ return OP_MOD("assign") << OP_FUNCTION("sar#", OP_X86(instr, 0), OP_X86(instr, 1)); },
    [X86_INS_CDQ] = [](convert_args){
        assert(func.arch == arch_t::arch16);
        return ASSIGN(OP_VAR("dx"), OP_VAR("ax & 0x8000 ? 0xffff : 0x0000"));
    },
    [X86_INS_CMC] = [](convert_args){ return ASSIGN(OP_VAR("flags.carry"), !OP_VAR("flags.carry")); },
    [X86_INS_PUSHF] = [](convert_args){ return OP_FUNCTION("push", OP_VAR("flagAsReg()")); },
    [X86_INS_POPF] = [](convert_args){ return OP_FUNCTION("flagsFromReg", OP_VAR("pop()")); },
//
    [X86_INS_LCALL] = [](convert_args){
        if (instr->mDetail.op_count == 2 && instr->mDetail.operands[0].type == X86_OP_IMM && instr->mDetail.operands[1].type == X86_OP_IMM)
        {
            return StatementIr{.type = StatementIr::Type_t::DirectCallLong, .target = instr->CallTarget()};
        }
        if (instr->mDetail.op_count == 1 && instr->mDetail.operands[0].type == X86_OP_MEM)
        {
            cs_x86_op lowWord = instr->mDetail.operands[0];
            cs_x86_op highWord = instr->mDetail.operands[0];
            assert(highWord.type == X86_OP_MEM);
            highWord.mem.disp += 2;
            highWord.size = 2;
            lowWord.size = 2;

            return StatementIr{.type = StatementIr::Type_t::IndirectCallLong,
                .opin1 = OP_X86(highWord).get(), .opin2 = OP_X86(lowWord).get()};
            //return StatementIr(OP_FUNCTION("indirectCall", OP_X86(highWord), OP_X86(lowWord)));
        }

        assert(0);
        return StatementIr{};
    },
    [X86_INS_LDS] = [](convert_args){
        cs_x86_op ds{.type = X86_OP_REG, .reg = X86_REG_DS, .size = 2};
        if(Capstone->Intersects(instr->mDetail.operands[1], instr->mDetail.operands[0]) /*|| Capstone->Intersects(instr->mDetail.operands[1], ds)*/)
        {
            assert(0);
        }
        
        cs_x86_op lowWord = instr->mDetail.operands[1];
        cs_x86_op highWord = instr->mDetail.operands[1];
        assert(highWord.type == X86_OP_MEM);
        highWord.mem.disp += 2;
        
        StatementIr a = ASSIGN(OP_X86(instr, 0), OP_X86(lowWord));
        StatementIr b = ASSIGN(OP_X86(ds), OP_X86(highWord));
        a.next = std::make_shared<StatementIr>(b);
        return a;
    },
    [X86_INS_LES] = [](convert_args){
        cs_x86_op es{.type = X86_OP_REG, .reg = X86_REG_ES, .size = 2};
        cs_x86_op lowWord = instr->mDetail.operands[1];
        cs_x86_op highWord = instr->mDetail.operands[1];
        assert(highWord.type == X86_OP_MEM);
        highWord.mem.disp += 2;

        if(Capstone->Intersects(instr->mDetail.operands[1], instr->mDetail.operands[0]) /*|| Capstone->Intersects(instr->mDetail.operands[1], es)*/)
        {
            /*
             les bx, es:[bx+8]
                temp = es:[bx+8]
                es = es:[bx+8+2]
                bx = temp
             */
            StatementIr a = ASSIGN(OP_REG("tx", 2), OP_X86(lowWord));
            StatementIr b = ASSIGN(OP_X86(es), OP_X86(highWord));
            StatementIr c = ASSIGN(OP_X86(instr, 0), OP_REG("tx", 2));
            b.next = std::make_shared<StatementIr>(c);
            a.next = std::make_shared<StatementIr>(b);
            return a;
        }
                
        StatementIr a = ASSIGN(OP_X86(instr, 0), OP_X86(lowWord));
        StatementIr b = ASSIGN(OP_X86(es), OP_X86(highWord));
        a.next = std::make_shared<StatementIr>(b);
        return a;
    },
    /*
    {.convert = [](convert_args){
        cs_x86_op es{.type = X86_OP_REG, .reg = X86_REG_ES};
        // les bx, es:[bx]
        if(Capstone->Intersects(instr->mDetail.operands[1], instr->mDetail.operands[0]) || Capstone->Intersects(instr->mDetail.operands[1], es))
            return "{int tmp1 = $rd1; int tmp2 = $rn1; $wr0 = tmp1; es = tmp2;};";
        assert(!Capstone->Intersects(instr->mDetail.operands[1], instr->mDetail.operands[0]));
        return "$wr0 = $rd1; es = $rn1;";
    } },
    [X86_INS_LDS] = {.convert = [](convert_args){
        cs_x86_op ds{.type = X86_OP_REG, .reg = X86_REG_DS};
//        assert(!Capstone->Intersects(instr->mDetail.operands[1], ds));
        if(Capstone->Intersects(instr->mDetail.operands[1], instr->mDetail.operands[0]))
            return "{int tmp1 = $rd1; int tmp2 = $rn1; $wr0 = tmp1; ds = tmp2; };";
        return "$wr0 = $rd1; ds = $rn1;";
    } },
*/

};
