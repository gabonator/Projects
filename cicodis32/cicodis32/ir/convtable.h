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
    [X86_INS_JMP] = [](convert_args){ return StatementIr{
        .type = instr->mDetail.operands[0].type == X86_OP_IMM ? StatementIr::Type_t::DirectJump : StatementIr::Type_t::IndirectJump,
        .target = instr->JumpTarget()}; },
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
    [X86_INS_SBB] = [](convert_args){ return instr->ArgsEqual() ?
        OP_MOD("assign") << - OP_VAR("flags.carry") :
        OP_MOD("assign") << ((OP_X86(instr, 0) - OP_X86(instr, 1)) - OP_VAR("flags.carry")); },
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
        
        return ASSIGN(OP_X86(instr, 0), OP_X86(instr->mDetail.operands[1]) + OP_CONST(instr->mDetail.operands[1].mem.disp));
    },

    [X86_INS_SAR] = [](convert_args){ return OP_MOD("assign") << OP_FUNCTION("sar#", OP_X86(instr, 0), OP_X86(instr, 1)); },
    [X86_INS_CDQ] = [](convert_args){
        assert(func.arch == arch_t::arch16);
        return ASSIGN(OP_VAR("dx"), OP_VAR("ax & 0x8000 ? 0xffff : 0x0000"));
    },
    [X86_INS_CMC] = [](convert_args){ return ASSIGN(OP_VAR("flags.carry"), !OP_VAR("flags.carry")); },
    [X86_INS_PUSHF] = [](convert_args){ return OP_FUNCTION("push", OP_VAR("flagAsReg()")); },
    [X86_INS_POPF] = [](convert_args){ return OP_FUNCTION("flagsFromReg", OP_VAR("pop()")); },

};
