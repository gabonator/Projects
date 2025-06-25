//
//  tracer.h
//  cicodis32
//
//  Created by Gabriel Valky on 23/06/2025.
//


struct instruction_t
{
    enum {
        readsUndef,
        readsNone,
        oneReadsFirst,
        twoReadsFirst,
        twoReadsSecond,
        twoReadsBoth,
        regAh
    } reads{readsUndef};
    enum {
        writesUndef,
        writesNone,
        oneWritesFirst,
        twoWritesFirst,
        twoWritesSecond,
//        writesFlags
    } writes{writesUndef};
    bool writesCF{false}, writesZF{false}, writesOF{false};
    bool continuous{true};
    bool simpleJump{false};
    bool calls{false};
    bool visibleFlags{false};
    int stack{0};
//    std::function<address_t(std::shared_ptr<CapInstr> instr)> jumps;
};

instruction_t Instructions[X86_INS_ENDING] = {
    [X86_INS_RET] = { .continuous = false, .reads = instruction_t::readsNone, .writes = instruction_t::writesNone },
    [X86_INS_RETF] = { .continuous = false, },
    [X86_INS_JMP] = {
        .continuous = false,
        .simpleJump = true,
//        .jumps = [](std::shared_ptr<CapInstr> instr) -> address_t {
//            assert(instr->mDetail.op_count == 1 &&
//                   (instr->mDetail.operands[0].size == 2 || instr->mDetail.operands[0].size == 4));
//            return address_t{instr->mAddress.segment, (int)instr->mDetail.operands[0].imm};
//        }
    },
    [X86_INS_JAE] = { .simpleJump = true },
    [X86_INS_JA] = { .simpleJump = true },
    [X86_INS_JBE] = { .simpleJump = true },
    [X86_INS_JB] = { .simpleJump = true },
    [X86_INS_JCXZ] = { .simpleJump = true },
    [X86_INS_JECXZ] = { .simpleJump = true },
    [X86_INS_JE] = { .simpleJump = true },
    [X86_INS_JGE] = { .simpleJump = true },
    [X86_INS_JG] = { .simpleJump = true },
    [X86_INS_JLE] = { .simpleJump = true },
    [X86_INS_JL] = { .simpleJump = true },
    [X86_INS_JNE] = { .simpleJump = true },
    [X86_INS_JNO] = { .simpleJump = true },
    [X86_INS_JNP] = { .simpleJump = true },
    [X86_INS_JNS] = { .simpleJump = true },
    [X86_INS_JO] = { .simpleJump = true },
    [X86_INS_JP] = { .simpleJump = true },
    [X86_INS_JRCXZ] = { .simpleJump = true },
    [X86_INS_JS] = { .simpleJump = true },
    [X86_INS_CALL] = { .calls = true, .reads = instruction_t::readsNone, .writes = instruction_t::writesNone },
    
    [X86_INS_PUSH] = { .stack = +2, .reads = instruction_t::oneReadsFirst, .writes = instruction_t::writesNone },
    [X86_INS_POP] = { .stack = -2, .writes = instruction_t::oneWritesFirst, .reads = instruction_t::readsNone },

    [X86_INS_LEA] = { .reads = instruction_t::twoReadsSecond, .writes = instruction_t::twoWritesFirst },
    [X86_INS_MOV] = { .reads = instruction_t::twoReadsSecond, .writes = instruction_t::twoWritesFirst },
    [X86_INS_SAHF] = { .reads = instruction_t::regAh, .writes = instruction_t::writesNone, .writesCF = true, .writesZF = true, .writesOF = true, .visibleFlags = true },
    [X86_INS_XOR] = { .reads = instruction_t::twoReadsSecond, .writes = instruction_t::twoWritesFirst},
    [X86_INS_TEST] = { .reads = instruction_t::twoReadsBoth, .writes = instruction_t::writesNone},
    
    [X86_INS_INT] = { .reads = instruction_t::regAh, .writes = instruction_t::writesNone }, // TODO
    [X86_INS_AND] = { .reads = instruction_t::twoReadsSecond, .writes = instruction_t::twoWritesFirst },
    [X86_INS_PUSHFD] = { .stack = +4, .reads = instruction_t::readsNone, .writes = instruction_t::writesNone },
    [X86_INS_POPFD] = { .stack = +4, .reads = instruction_t::readsNone, .writes = instruction_t::writesNone },
    [X86_INS_SBB] = { .reads = instruction_t::twoReadsBoth, .writes = instruction_t::twoWritesFirst},
    [X86_INS_SUB] = { .reads = instruction_t::twoReadsBoth, .writes = instruction_t::twoWritesFirst},
    [X86_INS_CMP] = { .reads = instruction_t::twoReadsBoth, .writes = instruction_t::writesNone},
    [X86_INS_ADD] = { .reads = instruction_t::twoReadsBoth, .writes = instruction_t::twoWritesFirst},
    [X86_INS_MOVZX] = { .reads = instruction_t::twoReadsSecond, .writes = instruction_t::twoWritesFirst },
};

class CapInstr : public std::enable_shared_from_this<CapInstr>
{
public:
    x86_insn mId;
    cs_x86 mDetail;
    int mSize;
    address_t mAddress;
    //
    std::vector<address_t> mNext;
    std::vector<address_t> mPrev;
    instruction_t mTemplate;
    bool isLabel{false};
    // processing
//    instrInfo_t mInfo;
    // debug
    char mMnemonic[64];
    char mOperands[64];
    uint8_t mBytes[24];
    
public:
    CapInstr(address_t addr, cs_insn* p);
    void Populate();
    bool IsDirectCall()
    {
        assert(mId == X86_INS_CALL);
        assert(mDetail.op_count == 1);
        return mDetail.operands[0].type == X86_OP_IMM;
    }
    address_t CallTarget()
    {
        assert(mId == X86_INS_CALL);
        assert(mDetail.op_count == 1);
        assert(mDetail.operands[0].type == X86_OP_IMM);
        assert(mDetail.operands[0].size == 4);
        return {mAddress.segment, (int)mDetail.operands[0].imm};
    }
    bool IsDirectJump()
    {
        if (mId != X86_INS_JMP)
            return false;
        assert(mDetail.op_count == 1);
        return mDetail.operands[0].type == X86_OP_IMM;
    }
    bool IsJump()
    {
        return mTemplate.simpleJump;
    }
    address_t JumpTarget()
    {
        assert (mTemplate.simpleJump);
        //assert(mId == X86_INS_JMP);
        assert(mDetail.op_count == 1);
        assert(mDetail.operands[0].type == X86_OP_IMM);
        assert(mDetail.operands[0].size == 4);
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
        switch (mTemplate.reads)
        {
            case instruction_t::readsUndef:
                assert(0);
                return {};
            case instruction_t::readsNone:
                return {};
            case instruction_t::oneReadsFirst:
                assert(mDetail.op_count == 1);
                if (mDetail.operands[0].type == X86_OP_REG)
                    return {mDetail.operands[0].reg};
                return {};
            case instruction_t::twoReadsFirst:
                assert(mDetail.op_count == 2);
                if (mDetail.operands[0].type == X86_OP_REG)
                    return {mDetail.operands[0].reg};
                return {};
            case instruction_t::twoReadsSecond:
               assert(mDetail.op_count == 2);
               if (mDetail.operands[1].type == X86_OP_REG)
                   return {mDetail.operands[1].reg};
               if (mDetail.operands[1].type == X86_OP_MEM)
               {
                   std::set<x86_reg> regs;
                   if (mDetail.operands[1].mem.base != X86_REG_INVALID)
                       regs.insert(mDetail.operands[1].mem.base);
                   if (mDetail.operands[1].mem.index != X86_REG_INVALID)
                       regs.insert(mDetail.operands[1].mem.index);
                   return regs;
               }
               return {};
            case instruction_t::twoReadsBoth:
            {
                assert(mDetail.op_count == 2);
                std::set<x86_reg> regs;
                
                switch (mDetail.operands[0].type)
                {
                    case X86_OP_REG:
                        regs.insert(mDetail.operands[0].reg);
                        break;
                    case X86_OP_IMM:
                        break;
                    case X86_OP_MEM:
                        if (mDetail.operands[0].mem.segment != X86_REG_INVALID)
                            regs.insert(mDetail.operands[0].mem.segment);
                        if (mDetail.operands[0].mem.base != X86_REG_INVALID)
                            regs.insert(mDetail.operands[0].mem.base);
                        if (mDetail.operands[0].mem.index != X86_REG_INVALID)
                            regs.insert(mDetail.operands[0].mem.index);
                        break;
                    default:
                        assert(0);
                }

                switch (mDetail.operands[1].type)
                {
                    case X86_OP_REG:
                        regs.insert(mDetail.operands[1].reg);
                        break;
                    case X86_OP_IMM:
                        break;
                    case X86_OP_MEM:
                        if (mDetail.operands[1].mem.segment != X86_REG_INVALID)
                            regs.insert(mDetail.operands[1].mem.segment);
                        if (mDetail.operands[1].mem.base != X86_REG_INVALID)
                            regs.insert(mDetail.operands[1].mem.base);
                        if (mDetail.operands[1].mem.index != X86_REG_INVALID)
                            regs.insert(mDetail.operands[1].mem.index);
                        break;
                    default:
                        assert(0);
                }
                return regs;
            }
            case instruction_t::regAh:
                return {X86_REG_AH};
            default:
                assert(0);
                return {};
        }
    }
    std::set<x86_reg> WritesRegisters()
    {
        if (mTemplate.simpleJump)
            return {};

        std::set<x86_reg> aux;

        switch (mTemplate.writes)
        {
            case instruction_t::writesUndef:
                assert(0);
                return {};
            case instruction_t::writesNone:
                return aux;
            case instruction_t::oneWritesFirst:
                assert(mDetail.op_count == 1);
                if (mDetail.operands[0].type == X86_OP_REG)
                    aux.insert(mDetail.operands[0].reg);
                return aux;
            case instruction_t::twoWritesFirst:
                assert(mDetail.op_count == 2);
                if (mDetail.operands[0].type == X86_OP_REG)
                    aux.insert(mDetail.operands[0].reg);
                return aux;
            case instruction_t::twoWritesSecond:
               assert(mDetail.op_count == 2);
               if (mDetail.operands[1].type == X86_OP_REG)
                   aux.insert(mDetail.operands[1].reg);
               return aux;
            default:
                assert(0);
                return {};
        }
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
};

CapInstr::CapInstr(address_t addr, cs_insn* p)
{
    assert(addr.segment != -1);
    memcpy(&mDetail, &p->detail->x86, sizeof(cs_x86));
    mId = (x86_insn)p->id;
    mAddress = addr;
    mSize = p->size;
    assert(mSize < 24);
    strcpy(mMnemonic, p->mnemonic);
    strcpy(mOperands, p->op_str);
    memset(mBytes, 0, sizeof(mBytes));
    memcpy(mBytes, p->bytes, mSize);
}
// dosbox 160:15e390
// bpm 160:15e6a6, 160:15e69c
// memdumpbin 160:15e000 8000
// 0160:15E47C  66268C1D5DE61500    mov  es:[0015E65D],ds (ds=168)
void CapInstr::Populate()
{
    const instruction_t& templ = Instructions[mId];
    mTemplate = templ;
    if (templ.continuous)
    {
//        if (AsString() == "int 0x21")
//        {
//            int f = 9;
//        }
        mNext.push_back({mAddress.segment, mAddress.offset + mSize});
    }
    if (templ.simpleJump)
    {
        assert(mDetail.op_count == 1 &&
               (mDetail.operands[0].size == 2 || mDetail.operands[0].size == 4));
        if (mDetail.operands[0].imm != 0x15e6a6) // wtf!?  6a6 69c
            mNext.push_back({mAddress.segment, (int)mDetail.operands[0].imm});
    }
    //for (address_t t : mNext)
//        printf("%x -> %x\n", mAddress.offset, t.offset);
//
//    if (std::find(mNext.begin(), mNext.end(), address_t{0, 0x15e6a6}) != mNext.end())
//    {
//        int f = 9;
//    }
//    if (std::find(mNext.begin(), mNext.end(), address_t{0, 0x15e6a8}) != mNext.end())
//    {
//        int f = 9;
//    }
}

class CCapstone
{
    csh mHandle;
    cs_insn* mInsn;
    shared<Loader> mLoader;
    
public:
    CCapstone()
    {
        cs_err err = cs_open(CS_ARCH_X86, CS_MODE_32, &mHandle);
        if (err) {
            printf("Failed on cs_open() with error returned: %u\n", err);
            abort();
        }
        cs_option(mHandle, CS_OPT_DETAIL, CS_OPT_ON);
        mInsn = cs_malloc(mHandle);
    }
    
    ~CCapstone()
    {
        cs_free(mInsn, 1);
        cs_close(&mHandle);
    }
    
    void Set(shared<Loader> loader)
    {
        mLoader = loader;
    }
        
    std::shared_ptr<CapInstr> Disasm(address_t addr)
    {
        uint64_t address = addr.segment*16*0 + addr.offset;
        size_t codeSize = 32;
        const uint8_t* buf = mLoader->GetBufferAt(addr);
        if (buf[0] == 0 && buf[1] == 0 && buf[2] == 0)
        {
            return std::shared_ptr<CapInstr>();
//            assert(0);
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
};

std::unique_ptr<CCapstone> Capstone{new CCapstone};

class CTracer {
public:
    typedef std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> code_t;
    
private:
    code_t code;
    address_t address;
    //funcInfo_t info;
    
public:
    void Trace(address_t a)
    {
        address_t stub;
        address = a;
        assert(code.empty());
        //        std::vector<address_t> calls;
        std::vector<std::pair<address_t, address_t>> queue;
        
        queue.push_back({{},a});
        while (!queue.empty())
        {
            std::vector<std::pair<address_t, address_t>> newQueue;
            
            for (std::pair<address_t, address_t> addr : queue)
            {
//                printf("disasm: %x->%x ", addr.first.offset, addr.second.offset);
                std::shared_ptr<CapInstr> instr = Capstone->Disasm(addr.second);
                //                if (instr->mTemplate.calls)
                //                    calls.push_back(instr->CallTarget());
                assert(instr);
                if (instr->mAddress == a && instr->IsDirectJump())
                {
                    // dont trace stubs
                    stub = *instr->mNext.begin();
                    instr->mNext.clear();
                }
//                if (!instr)
//                {
//                    int f = 9;
//                    instr = Capstone->Disasm(addr.second);
//                }
                if (addr.first)
                    instr->mPrev.push_back(addr.first);
//                printf("(+%d) %s %s\n", instr->mSize, instr->mMnemonic, instr->mOperands);
                if (instr->AsString() == "int 0x21")
                {
                    assert(instr->mPrev.size() == 1);
                    std::string prev = code.find(instr->mPrev[0])->second->AsString();
                    if (prev.find("mov ax, 0x4c") != std::string::npos)
                        instr->mNext.clear();
                    if (prev.find("mov ah, 0x4c") != std::string::npos)
                        instr->mNext.clear();
                }
                code.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(addr.second, instr));
                for (address_t cont : instr->mNext)
                {
//                    code.find(cont)->second->mPrev.push_back(addr);
                    if (code.find(cont) == code.end())
                        newQueue.push_back(std::pair<address_t, address_t>(addr.second, cont));
                    else
                        code.find(cont)->second->mPrev.push_back(addr.second);
                }
            }
            queue = newQueue;
        }
        // set labels
        for (const auto& p : code)
        {
            //if (p.second->IsDirectJump())
            if (p.second->IsJump())
            {
                address_t target = p.second->JumpTarget();
                if (target != stub)
                    code.find(target)->second->isLabel = true;
            }
        }

    }
    void Dump()
    {
        printf("sub_%x begin\n", address.offset);
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
        printf("sub_%x ends\n\n", address.offset);
        //std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> code;
    }
    std::set<address_t, cmp_adress_t> GetCalls()
    {
        std::set<address_t, cmp_adress_t> aux;
        if (code.size() == 1 && code.begin()->second->IsDirectJump())
        {
            // stub jump
            aux.insert(code.begin()->second->JumpTarget());
        }
        for (const auto& p : code)
        {
            //if (p.second->IsDirectJump())
            if (p.second->mTemplate.calls && p.second->IsDirectCall())
            {
//                printf("GetCalls: %x %s %s -> sub_%x\n", p.first.offset, p.second->mMnemonic, p.second->mOperands, p.second->CallTarget().offset);
                aux.insert(p.second->CallTarget());
            }
        }
        return aux;
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

