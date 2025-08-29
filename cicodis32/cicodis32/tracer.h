//
//  tracer.h
//  cicodis32
//
//  Created by Gabriel Valky on 23/06/2025.
//


struct instruction_t
{
    bool continuous{true};
    bool simpleJump{false};
//    bool calls{false};
    int stack{0};
    bool conditional{false};
    bool unconditional{false};
    bool ret{false};
    bool destructiveCarry{false};
    bool savedVisiblyCarry{false};
};

instruction_t Instructions[X86_INS_ENDING] = {
    [X86_INS_RET] = { .continuous = false, .ret = true },
    [X86_INS_RETF] = { .continuous = false, .ret = true },
    [X86_INS_IRET] = { .continuous = false, .ret = true },
    [X86_INS_JMP] = {
        .continuous = false,
        .simpleJump = true,
        .unconditional = true
    },
    [X86_INS_LJMP] = {
        .continuous = false,
//        .simpleJump = true,
        .unconditional = true
    },
    [X86_INS_JAE] = { .conditional = true, .simpleJump = true },
    [X86_INS_JA] = { .conditional = true, .simpleJump = true },
    [X86_INS_JBE] = { .conditional = true, .simpleJump = true },
    [X86_INS_JB] = { .conditional = true, .simpleJump = true },
    [X86_INS_JCXZ] = { .conditional = true, .simpleJump = true },
    [X86_INS_JECXZ] = { .conditional = true, .simpleJump = true },
    [X86_INS_JE] = { .conditional = true, .simpleJump = true },
    [X86_INS_JGE] = { .conditional = true, .simpleJump = true },
    [X86_INS_JG] = { .conditional = true, .simpleJump = true },
    [X86_INS_JLE] = { .conditional = true, .simpleJump = true },
    [X86_INS_JL] = { .conditional = true, .simpleJump = true },
    [X86_INS_JNE] = { .conditional = true, .simpleJump = true },
    [X86_INS_JNO] = { .conditional = true, .simpleJump = true },
    [X86_INS_JNP] = { .conditional = true, .simpleJump = true },
    [X86_INS_JNS] = { .conditional = true, .simpleJump = true },
    [X86_INS_JO] = { .conditional = true, .simpleJump = true },
    [X86_INS_JP] = { .conditional = true, .simpleJump = true },
    [X86_INS_JRCXZ] = { .conditional = true, .simpleJump = true },
    [X86_INS_JS] = { .conditional = true, .simpleJump = true },
    [X86_INS_LOOP] = { .simpleJump = true },
    [X86_INS_LOOPE] = { .simpleJump = true, .conditional = true },
    [X86_INS_LOOPNE] = { .simpleJump = true, .conditional = true },
    [X86_INS_CALL] = { .savedVisiblyCarry = true },
    [X86_INS_LCALL] = { .savedVisiblyCarry = true },

    [X86_INS_PUSH] = { .stack = +2 },
    [X86_INS_POP] = { .stack = -2 },

    [X86_INS_LEA] = {  },
    [X86_INS_MOV] = {  },
    [X86_INS_XOR] = {},
    [X86_INS_TEST] = {},
    
    [X86_INS_INT] = { }, // TODO
    [X86_INS_AND] = { },
    [X86_INS_PUSHFD] = { .stack = +4 },
    [X86_INS_POPFD] = { .stack = +4 },
    [X86_INS_POPF] = { .stack = +4, .savedVisiblyCarry = true },
    [X86_INS_CMP] = { },
    [X86_INS_MOVZX] = { },
    
    [X86_INS_SHL] = { .destructiveCarry = true },
    [X86_INS_SHR] = { .destructiveCarry = true },
    [X86_INS_ADD] = { .destructiveCarry = true },
    [X86_INS_ADC] = { .destructiveCarry = true },
    [X86_INS_SUB] = { .destructiveCarry = true },
    [X86_INS_SBB] = { .destructiveCarry = true },
    [X86_INS_ROL] = { .destructiveCarry = true },
    [X86_INS_ROR] = { .destructiveCarry = true },
    [X86_INS_RCL] = { .savedVisiblyCarry = true },
    [X86_INS_RCR] = { .savedVisiblyCarry = true },
    [X86_INS_STC] = { .savedVisiblyCarry = true },
    [X86_INS_CLC] = { .savedVisiblyCarry = true },
    [X86_INS_CMC] = { .savedVisiblyCarry = true },

    [X86_INS_SAHF] = { .savedVisiblyCarry = true },
    [X86_INS_CMPSB] = { .savedVisiblyCarry = true }, // ZERO!

    //            case X86_INS_STC:
    //            case X86_INS_CLC:
    //            case X86_INS_CMC:
    //                info->GetFlag('c').savedVisibly |= true;

};

class CapInstr : public std::enable_shared_from_this<CapInstr>
{
public:
    x86_insn mId;
    cs_x86 mDetail;
    int mSize;
    address_t mAddress;

    //
    std::set<address_t> mNext;
    std::set<address_t> mPrev;
    instruction_t mTemplate;
    bool isLabel{false};
    bool isTerminating{false};
    bool isReturning{false};
    bool isLast{false};
    
    // debug
    char mMnemonic[64];
    char mOperands[64];
    uint8_t mBytes[24];
    
public:
    CapInstr(address_t addr, cs_insn* p);
    void Populate();
    bool IsDirectCall()
    {
        if(mId == X86_INS_CALL)
        {
            assert(mDetail.op_count == 1);
            return mDetail.operands[0].type == X86_OP_IMM;
        }
        if(mId == X86_INS_LCALL)
        {
            if (mDetail.op_count == 2 && mDetail.operands[0].type == X86_OP_IMM && mDetail.operands[1].type == X86_OP_IMM)
                return true;
            if (mDetail.op_count == 1 && mDetail.operands[0].type == X86_OP_MEM)
                return false;
            assert(0);
        }
        assert(0);
        return false;
    }
    bool IsIndirectCall()
    {
        if (mId == X86_INS_CALL)
        {
            assert(mDetail.op_count == 1);
            return mDetail.operands[0].type != X86_OP_IMM;
        }
        if (mId == X86_INS_LCALL)
        {
            if (mDetail.op_count == 1 && mDetail.operands[0].type == X86_OP_MEM)
                return true;
            if (mDetail.op_count == 2 && mDetail.operands[0].type == X86_OP_IMM && mDetail.operands[1].type == X86_OP_IMM)
                return false;
            assert(0);
        }
        return false;
    }
    bool IsIndirectJump()
    {
        if (mId != X86_INS_JMP)
            return false;
        assert(mDetail.op_count == 1);
        return mDetail.operands[0].type != X86_OP_IMM;
    }
    address_t CallTarget()
    {
        if(mId == X86_INS_CALL)
        {
            assert(mDetail.op_count == 1);
            assert(mDetail.operands[0].type == X86_OP_IMM);
            assert(mDetail.operands[0].size == 2 || mDetail.operands[0].size == 4);
            if (mDetail.operands[0].size == 2)
                return {mAddress.segment, (int)mDetail.operands[0].imm & 0xffff};
            return {mAddress.segment, (int)mDetail.operands[0].imm};
        }
        if(mId == X86_INS_LCALL)
        {
            assert(mDetail.op_count == 2);
            assert(mDetail.operands[0].type == X86_OP_IMM && mDetail.operands[1].type == X86_OP_IMM);
            return {(int)mDetail.operands[0].imm, (int)mDetail.operands[1].imm};
            
            //assert(mDetail.operands[0].size == 2 || mDetail.operands[0].size == 4);
            //if (mDetail.operands[0].size == 2)
            //    return {mAddress.segment, (int)mDetail.operands[0].imm & 0xffff};
            //return {mAddress.segment, (int)mDetail.operands[0].imm};
        }
        assert(0);
    }
    
    bool IsDirectJump() // TODO: conditional direct
    {
        if (!mTemplate.simpleJump)
            return false;
        assert(mDetail.op_count == 1);
        return mDetail.operands[0].type == X86_OP_IMM;
    }
    bool IsJump()
    {
        return mTemplate.simpleJump;
    }
    bool IsConditionalJump()
    {
        return mTemplate.conditional;
    }
    bool HasJumpTarget()
    {
        return mTemplate.simpleJump;
    }
    address_t JumpTarget()
    {
        assert (mTemplate.simpleJump);
        assert(mDetail.op_count == 1);
        assert(mDetail.operands[0].type == X86_OP_IMM);
        assert(mDetail.operands[0].size == 2 || mDetail.operands[0].size == 4);
        if (mDetail.operands[0].size == 2)
            return {mAddress.segment, (int)mDetail.operands[0].imm & 0xffff};
        return {mAddress.segment, (int)mDetail.operands[0].imm};
    }

    std::string AsString()
    {
        return std::string(mMnemonic) + " " + std::string(mOperands);
    }
    
    std::set<x86_reg> ReadsRegisters()
    {
        if (mTemplate.simpleJump)
            return {};
        
        std::set<x86_reg> regs;
        for (int i=0; i<mDetail.op_count; i++)
        {
            if (mDetail.operands[i].access & CS_AC_READ)
            {
                if (mDetail.operands[i].type == X86_OP_REG)
                    regs.insert(mDetail.operands[i].reg);
                if (mDetail.operands[i].type == X86_OP_MEM)
                {
                    if (mDetail.operands[i].mem.base != X86_REG_INVALID)
                        regs.insert(mDetail.operands[i].mem.base);
                    if (mDetail.operands[i].mem.index != X86_REG_INVALID)
                        regs.insert(mDetail.operands[i].mem.index);
                }
            }
        }
        return regs;
    }
    std::set<x86_reg> WritesRegisters()
    {
        if (mTemplate.simpleJump)
            return {};

        std::set<x86_reg> regs;
        for (int i=0; i<mDetail.op_count; i++)
        {
            if (mDetail.operands[i].access & CS_AC_WRITE)
            {
                if (mDetail.operands[i].type == X86_OP_REG)
                    regs.insert(mDetail.operands[i].reg);
                if (mDetail.operands[i].type == X86_OP_MEM)
                {
                    if (mDetail.operands[i].mem.base != X86_REG_INVALID)
                        regs.insert(mDetail.operands[i].mem.base);
                    if (mDetail.operands[i].mem.index != X86_REG_INVALID)
                        regs.insert(mDetail.operands[i].mem.index);
                }
            }
        }
        return regs;
    }

    bool ArgsEqual()
    {
        return ArgsEqual(0, 1);
    }
    
    bool ArgsEqual(int a, int b)
    {
        assert(a < mDetail.op_count);
        assert(b < mDetail.op_count);
        if (mDetail.operands[a].type != mDetail.operands[b].type)
            return false;
        switch (mDetail.operands[a].type)
        {
            case X86_OP_REG:
                return mDetail.operands[a].reg == mDetail.operands[b].reg;
            case X86_OP_MEM:
                return mDetail.operands[a].mem.segment == mDetail.operands[b].mem.segment &&
                    mDetail.operands[a].mem.base == mDetail.operands[b].mem.base &&
                    mDetail.operands[a].mem.index == mDetail.operands[b].mem.index &&
                    mDetail.operands[a].mem.scale == mDetail.operands[b].mem.scale &&
                    mDetail.operands[a].mem.disp == mDetail.operands[b].mem.disp;
            case X86_OP_IMM:
                return mDetail.operands[a].imm == mDetail.operands[b].imm;
            default:
                assert(0);
        }
    }
    int Imm()
    {
        if (mDetail.op_count == 0)
        {
            assert(mId == X86_INS_RET || mId == X86_INS_RETF);
            return 0;
        }
        if (mDetail.op_count == 1)
        {
            assert (mDetail.operands[0].type == X86_OP_IMM);
            return (int)mDetail.operands[0].imm;
        }
        assert (mDetail.op_count == 2);
        assert (mDetail.operands[1].type == X86_OP_IMM);
        return (int)mDetail.operands[1].imm;
    }
    std::string GetBytes()
    {
        std::string aux;
        for (int i=0; i<mSize; i++)
        {
            if (i>0)
                aux += " ";
            aux += utils::format("%02x", mBytes[i]);
        }
        return aux;
    }
};

CapInstr::CapInstr(address_t addr, cs_insn* p)
{
    assert(addr.segment != -1);
    memcpy(&mDetail, &p->detail->x86, sizeof(cs_x86));
    mId = (x86_insn)p->id;
    if (mId == X86_INS_TEST)
    {
        if (mDetail.eflags == 0)
        {
            assert(mDetail.eflags == 0); // 84 25 52 4e test byte ptr [di], ah
            //errata?
            mDetail.eflags = X86_EFLAGS_RESET_CF | X86_EFLAGS_RESET_OF | X86_EFLAGS_MODIFY_SF | X86_EFLAGS_MODIFY_ZF;
        }
    }
    if (mId == X86_INS_CMC)
    {
        // errata
        mDetail.eflags = X86_EFLAGS_MODIFY_CF | X86_EFLAGS_TEST_CF;
    }
    if (mId == X86_INS_RCL || mId == X86_INS_RCR)
    {
        // errata
        mDetail.eflags |= X86_EFLAGS_TEST_CF;
    }
    if (mId == X86_INS_FILD || mId == X86_INS_FMUL || mId == X86_INS_FDIV || mId == X86_INS_FADD || mId == X86_INS_FSTP ||
        mId == X86_INS_FSUBP || mId == X86_INS_FLD  || mId == X86_INS_FILD || mId == X86_INS_FSUBR || mId == X86_INS_FSUB ||
        mId == X86_INS_FISTP)
        mDetail.eflags = 0;

    if (mId == X86_INS_RCL && mDetail.op_count == 2 && mDetail.operands[1].type == X86_OP_IMM && mDetail.operands[1].size == 0 && mDetail.operands[1].imm == 1)
    {
        mDetail.operands[1].size = 1;
    }
        

    mAddress = addr;
    mSize = p->size;
    assert(mSize < 24);
    strcpy(mMnemonic, p->mnemonic);
    strcpy(mOperands, p->op_str);
    memset(mBytes, 0, sizeof(mBytes));
    memcpy(mBytes, p->bytes, mSize);
}

void CapInstr::Populate()
{
    const instruction_t& templ = Instructions[mId];
    mTemplate = templ;
    if (templ.continuous)
    {
        mNext.insert({mAddress.segment, mAddress.offset + mSize});
    }
    if (templ.simpleJump)
    {
//        if (mId == X86_INS_LJMP)
//        {
//            assert(mDetail.op_count == 2 &&
//                   (mDetail.operands[0].size == 2 && mDetail.operands[1].size == 2) &&
//                   mDetail.operands[0].type == X86_OP_IMM && mDetail.operands[1].type == X86_OP_IMM);
//            
//            if (IsDirectJump())
//            {
//                mNext.insert({(int)mDetail.operands[0].imm, (int)mDetail.operands[1].imm & 0xffff});
//            } else {
//                assert(0);
//            }
//        }
//        if (mId == X86_INS_JMP)
//        {
            assert(mDetail.op_count == 1 &&
                   (mDetail.operands[0].size == 2 || mDetail.operands[0].size == 4));
            //if (mDetail.operands[0].imm != 0x15e6a6) // wtf!?  6a6 69c
            if (IsDirectJump())
            {
                if (mDetail.operands[0].size == 2)
                    mNext.insert({mAddress.segment, (int)mDetail.operands[0].imm & 0xffff});
                else
                    mNext.insert({mAddress.segment, (int)mDetail.operands[0].imm});
            }
//        }
    }
}

class CCapstone
{
    csh mHandle;
    cs_insn* mInsn;
    shared<Loader> mLoader;
    uint8_t mRegMap[X86_REG_ENDING][X86_REG_ENDING] = {};

public:
    CCapstone()
    {
//        cs_err err = cs_open(CS_ARCH_X86, CS_MODE_32, &mHandle);
        //
        mRegMap[X86_REG_EAX][X86_REG_AX] = 1;
        mRegMap[X86_REG_EAX][X86_REG_AL] = 1;
        mRegMap[X86_REG_EAX][X86_REG_AH] = 1;
        mRegMap[X86_REG_AX][X86_REG_AL] = 1;
        mRegMap[X86_REG_AX][X86_REG_AH] = 1;
        mRegMap[X86_REG_EBX][X86_REG_BX] = 1;
        mRegMap[X86_REG_EBX][X86_REG_BL] = 1;
        mRegMap[X86_REG_EBX][X86_REG_BH] = 1;
        mRegMap[X86_REG_BX][X86_REG_BL] = 1;
        mRegMap[X86_REG_BX][X86_REG_BH] = 1;
        mRegMap[X86_REG_ECX][X86_REG_CX] = 1;
        mRegMap[X86_REG_ECX][X86_REG_CL] = 1;
        mRegMap[X86_REG_ECX][X86_REG_CH] = 1;
        mRegMap[X86_REG_CX][X86_REG_CL] = 1;
        mRegMap[X86_REG_CX][X86_REG_CH] = 1;
        mRegMap[X86_REG_EDX][X86_REG_DX] = 1;
        mRegMap[X86_REG_EDX][X86_REG_CL] = 1;
        mRegMap[X86_REG_EDX][X86_REG_CH] = 1;
        mRegMap[X86_REG_DX][X86_REG_DL] = 1;
        mRegMap[X86_REG_DX][X86_REG_DH] = 1;
    }
    
    ~CCapstone()
    {
        if (mInsn)
        {
            cs_free(mInsn, 1);
            cs_close(&mHandle);
            mInsn = nullptr;
        }
    }
    
    void Set(shared<Loader> loader, Options& options)
    {
        mLoader = loader;
        
        cs_mode mode = options.arch == arch_t::arch16 ? CS_MODE_16 : cs_mode(/*CS_MODE_16 |*/ CS_MODE_32);
        cs_err err = cs_open(CS_ARCH_X86, mode, &mHandle);
        if (err) {
            printf("Failed on cs_open() with error returned: %u\n", err);
            abort();
        }
        cs_option(mHandle, CS_OPT_DETAIL, CS_OPT_ON);
        mInsn = cs_malloc(mHandle);

    }
        
    std::shared_ptr<CapInstr> Disasm(address_t addr)
    {
        uint64_t address = addr.offset;
        size_t codeSize = 32;
        const uint8_t* buf = mLoader->GetBufferAt(addr);
        if (buf[0] == 0 && buf[1] == 0 && buf[2] == 0)
        {
            return std::shared_ptr<CapInstr>();
        }
            
        cs_disasm_iter(mHandle, &buf, &codeSize, &address, mInsn);
        std::shared_ptr<CapInstr> instr(new CapInstr(addr, mInsn));
        instr->Populate();
        return instr;
    }
    const char* ToString(x86_reg r)
    {
        return cs_reg_name(mHandle, r);
    }
    const char* ToString(x86_insn r)
    {
        return cs_insn_name(mHandle, r);
    }
    
    std::string ToString(cs_x86_op op)
    {
        switch (op.type)
        {
            case X86_OP_INVALID:
                assert(0);
                return "INVALID!";
            case X86_OP_IMM:
                return format("0x%x", op.imm);
            case X86_OP_REG:
                return ToString(op.reg);
            case X86_OP_MEM:
            {
                std::string aux;
                if (op.mem.segment != X86_REG_INVALID)
                    aux += ToString(op.mem.segment);
                aux += "[";
                if (op.mem.base != X86_REG_INVALID)
                {
                    aux += ToString(op.mem.base);
                    aux += " + ";
                }
                aux += ToString(op.mem.index);
                if (op.mem.scale != 1)
                    aux += format(" * %d", op.mem.scale);
                if (op.mem.disp != 0)
                    aux += format(" + %d", op.mem.disp);
                aux += "]";
                return aux;
            }
        }
    }

    bool Equals(const cs_x86_op& a, const cs_x86_op& b)
    {
        if (a.type != b.type)
            return false;
        switch (a.type)
        {
            case X86_OP_INVALID:
                return true;
            case X86_OP_IMM:
                return a.imm == b.imm;
            case X86_OP_REG:
                return a.reg == b.reg;
            case X86_OP_MEM:
                return a.mem.segment == b.mem.segment && a.mem.base == b.mem.base && a.mem.index == b.mem.index && a.mem.scale == b.mem.scale && a.mem.disp == b.mem.disp;
            default:
                assert(0);
        }
    }
    bool Intersects(const cs_x86_op& a, const cs_x86_op& b)
    {
        // check if operand A becomes invalidated after writing to operand B
        if (a.type == X86_OP_INVALID || b.type == X86_OP_IMM)
            return false;
        if (a.type == X86_OP_IMM || b.type == X86_OP_IMM)
            return false;
        if (a.type == X86_OP_REG && b.type == X86_OP_REG)
            return a.reg == b.reg || mRegMap[a.reg][b.reg] || mRegMap[b.reg][a.reg];
        if (a.type == X86_OP_MEM && b.type == X86_OP_REG)
        {
            if (a.mem.segment == X86_REG_INVALID && b.reg == X86_REG_DS)
                return true;
            return a.mem.index == b.reg || a.mem.segment == b.reg || a.mem.base == b.reg;
        }
        if (a.type == X86_OP_MEM && b.type == X86_OP_MEM)
            return a.mem.segment == b.mem.segment && a.mem.base == b.mem.base && a.mem.index == b.mem.index && a.mem.scale == b.mem.scale && a.mem.disp == b.mem.disp;
        if (a.type == X86_OP_REG && b.type == X86_OP_MEM)
            return false;

        assert(0);
        return false;
    }
    virtual const uint8_t* GetBufferAt(address_t addr) // TODO: remove?
    {
        return mLoader->GetBufferAt(addr);
    }
};

std::unique_ptr<CCapstone> Capstone{new CCapstone};

class CTracer {
public:
    const Options& mOptions;
    typedef std::map<address_t, std::shared_ptr<CapInstr>> code_t;
    
private:
    code_t code;
    address_t address;
    //funcInfo_t info;
    
public:
    CTracer(const Options& options) : mOptions(options)
    {
    }
    
    void Trace(address_t a)
    {
        const bool verbose = mOptions.verbose;
        address_t stub;
        address = a;
        assert(code.empty());
        std::vector<std::pair<address_t, address_t>> queue;

        if (verbose)
            printf("disasm: proc %04x:%04x sub_%x\n", a.segment, a.offset, a.linearOffset());

        queue.push_back({{},a});
        while (!queue.empty())
        {
            std::vector<std::pair<address_t, address_t>> newQueue;
            
            for (std::pair<address_t, address_t> addr : queue)
            {
                if (verbose)
                    printf("disasm: %x->%x ", addr.first.offset, addr.second.offset);
               
                std::shared_ptr<CapInstr> instr = Capstone->Disasm(addr.second);
                assert(instr);
                if (instr->mAddress == a && instr->IsDirectJump())
                {
                    // dont trace stubs
                    stub = *instr->mNext.begin();
                    instr->mNext.clear();
                }
                if (instr->HasJumpTarget() && instr->IsDirectJump() && mOptions.isolateLabels.find(instr->JumpTarget()) != mOptions.isolateLabels.end())
                {
                    // TODO: jb - after int 0x21, fs error handler, instr->isolateBranch = true
                    assert(instr->mId == X86_INS_JMP);
                    instr->mId = X86_INS_CALL;
                    instr->mTemplate = Instructions[instr->mId];
                    // TODO: not a real function do not alter SP!!!
                    instr->mNext.clear();
                    instr->isReturning = true;
                }
                if (addr.first)
                    instr->mPrev.insert(addr.first);
                if (verbose)
                    printf("(+%d) %s %s\n", instr->mSize, instr->mMnemonic, instr->mOperands);
                if (instr->AsString() == "int 0x20")
                {
                    instr->mNext.clear();
                    instr->isTerminating = true;
                }
                if (instr->AsString() == "int 0x21")
                {
                    assert(instr->mPrev.size() == 1);
                    address_t prevAddr = *instr->mPrev.begin();
                    std::string prev = code.find(prevAddr)->second->AsString();
                    std::string prev1;
                    
                    if (code.find(prevAddr)->second->mPrev.size())
                    {
                        address_t prevAddr1 = *code.find(prevAddr)->second->mPrev.begin();
                        prev1 = code.find(prevAddr1)->second->AsString();
                    }
                    if (prev.find("mov ax, 0x4c") != std::string::npos || prev1.find("mov ax, 0x4c") != std::string::npos)
                    {
                        instr->mNext.clear();
                        instr->isTerminating = true;
                    }
                    if (prev.find("mov ah, 0x4c") != std::string::npos || prev1.find("mov ah, 0x4c") != std::string::npos)
                    {
                        instr->mNext.clear();
                        instr->isTerminating = true;
                    }
                }
                if (mOptions.terminators.find(addr.second) != mOptions.terminators.end())
                {
//                    continue;
                    instr->mNext.clear();
                    instr->isTerminating = true;
                }

                if (instr->IsIndirectJump())
                {
                    shared<jumpTable_t> jt = mOptions.GetJumpTable(instr->mAddress);
                    if (jt)
                    {
                        for (int i=0; i<jt->GetSize(); i++)
                            if (jt->IsValid(i))
                                instr->mNext.insert(jt->GetTarget(i));
                    }
                }

                code.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(addr.second, instr));
                // TODO: include jumptable labels!
                for (address_t cont : instr->mNext)
                {
                    if (code.find(cont) == code.end())
                        newQueue.push_back(std::pair<address_t, address_t>(addr.second, cont));
                    else
                        code.find(cont)->second->mPrev.insert(addr.second);
                }
            }
            queue = newQueue;
        }
        // set labels
        for (const auto& p : code)
        {
            if (p.second->HasJumpTarget() && p.second->IsDirectJump())
            {
                address_t target = p.second->JumpTarget();
                if (target != stub)
                {
                    auto t = code.find(target);
                    if (t != code.end())
                        t->second->isLabel = true;
                    else {
                        // jumping inside another instruction!?
                    }
                }
            }
            if (p.second->IsIndirectJump()) // use mNext?
            {
                shared<jumpTable_t> jt = mOptions.GetJumpTable(p.first);
                if (jt)
                {
                    for (int i=0; i<jt->GetSize(); i++)
                    {
                        if (jt->IsValid(i))
                        {
                            address_t target = jt->GetTarget(i);
                            code.find(target)->second->isLabel = true;
                        }
                    }
                }
            }

        }
        if (code.begin()->first != a)
            code.find(a)->second->isLabel = true;
        code.rbegin()->second->isLast = true;
    }

    void Dump()
    {
        printf("sub_%x begin\n", address.linearOffset());
        address_t next;
        for (const auto& p : code)
        {
            if (next && p.first != next)
            {
                printf("gap %d bytes\n", p.first.offset - next.offset);
            }
            printf("%x %s %s\n", p.second->mAddress.offset, p.second->mMnemonic, p.second->mOperands);
            next = {p.second->mAddress.segment, p.second->mAddress.offset + p.second->mSize};
        }
        printf("sub_%x ends\n\n", address.linearOffset());
    }

    address_t Address()
    {
        return address;
    }

    code_t& GetCode()
    {
        return code;
    }
};

