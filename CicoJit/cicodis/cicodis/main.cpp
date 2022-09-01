//
//  main.cpp
//  cicodis
//
//  Created by Gabriel Valky on 27/08/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <capstone/platform.h>
#include <capstone/capstone.h>

csh _handle;
//static void print_insn_detail(csh ud, cs_mode mode, cs_insn *ins);

std::string format(const char* fmt, ...)
{
    char buf[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buf, fmt, args);
    va_end(args);
    return std::string(buf);
}

struct address_t {
    int segment{-1};
    int offset{-1};

    bool isValid() const
    {
        return segment != -1;
    }
    int linearOffset() const
    {
        return segment*0x10+offset;
    }
};

enum class inject_t {
    none = 0,
    carry = 1,
    zero = 2
};

address_t operator +(const address_t a, int b)
{
    return address_t{a.segment, a.offset+b};
}

bool operator==(const address_t& a, const address_t& b)
{
    return a.linearOffset() == b.linearOffset();
}

bool operator!=(const address_t& a, const address_t& b)
{
    return a.linearOffset() != b.linearOffset();
}

bool operator <(const address_t& a, const address_t& b)
{
    return a.linearOffset() < b.linearOffset();
}
bool operator >(const address_t& a, const address_t& b)
{
    return a.linearOffset() > b.linearOffset();
}

bool operator >=(const address_t& a, const address_t& b)
{
    return a.linearOffset() >= b.linearOffset();
}
bool operator <=(const address_t& a, const address_t& b)
{
    return a.linearOffset() <= b.linearOffset();
}

struct cmp_adress_t {
    bool operator()(const address_t& a, const address_t& b) const {
        return a.segment*0x10+a.offset < b.segment*0x10+b.offset;
    }
};

struct switch_t {
    address_t origin;
    address_t begin;
    int elements{0};
    enum switch_e {
      Words
    } type{Words};
    x86_reg selector{X86_REG_INVALID};
    const uint8_t* baseptr{nullptr};
    
    
    address_t GetBaseAddress() const
    {
        return {begin.segment, begin.offset};
    }
    address_t GetAddressAt(int i) const
    {
        return {begin.segment, begin.offset + i*2};
    }
    int GetSize() const
    {
        return 2;
    }
    address_t GetTarget(int i) const //(const uint8_t* data)
    {
        uint16_t* parts = (uint16_t*)baseptr;
        return address_t{0x1000, parts[i]};
    }
    std::string GetCase(int i) const
    {
        return format("case %d: sub_%x(); break;", i*2, GetTarget(i).linearOffset());
    }
    std::string GetSelector() const
    {
        return cs_reg_name(_handle, selector);
    }
};

struct function_t {
    address_t begin;
    int length;
    // analysis
    bool setsCarry{false};
    bool setsZero{false};
    bool discards[X86_REG_ENDING] {0};
};

struct cmp_function_t {
    bool operator()(const function_t& a, const function_t& b) const {
        return a.begin.segment*0x10+a.begin.offset < b.begin.segment*0x10+b.begin.offset;
    }
};

class CapInstr
{
public: // remove!
    x86_insn mId;
    //uint64_t mAddress;
    cs_x86 mDetail;
    int mSize;
    char mMnemonic[64];
    char mOperands[64];
    address_t mAddress;
    address_t mNextInstr;
    address_t mBranchInstr;
    bool mLabel{false};
    bool mMark{false};
    inject_t mInject{inject_t::none};
    std::string mComment;
    bool mForceFlagCondition{false};
    
public:
    CapInstr(address_t addr, int size, const std::string& comment)
    {
        strcpy(mMnemonic, "");
        strcpy(mOperands, "");
        mAddress = addr;
        mSize = size;
        mMark = true;
        mComment = comment;
    }
    
    CapInstr(address_t addr, cs_insn* p)
    {
        assert(addr.segment != -1);
        //mDetail = p->detail->x86;
        memcpy(&mDetail, &p->detail->x86, sizeof(cs_x86));
        mId = (x86_insn)p->id;
        mAddress = addr;
        mSize = p->size;
        //mAddress = p->address;
        strcpy(mMnemonic, p->mnemonic);
        strcpy(mOperands, p->op_str);
        mNextInstr = {addr.segment, addr.offset + p->size};
        
        cs_x86 *x86 = &(p->detail->x86);
        //Dump();
        //print_insn_detail(_handle, CS_MODE_16, p);
        
        switch (mId)
        {
            case X86_INS_MOV:
                break;

            case X86_INS_JMP:
                assert(x86->op_count == 1 &&
                       x86->operands[0].type == X86_OP_IMM &&
                       x86->operands[0].size == 2);
                mNextInstr = {addr.segment, (int)x86->operands[0].imm};
                sprintf(mOperands, "loc_%x", mNextInstr.segment*0x10+mNextInstr.offset);
                //print_insn_detail(_handle, CS_MODE_16, p);
                break;
                
                //tuto
            case X86_INS_LOOP:
            case X86_INS_JAE ... X86_INS_JL:
            case X86_INS_JNE ... X86_INS_JS:
                //print_insn_detail(_handle, CS_MODE_16, p);
                assert(x86->op_count == 1 &&
                       x86->operands[0].type == X86_OP_IMM &&
                       x86->operands[0].size == 2);
                mBranchInstr = {addr.segment, (int)x86->operands[0].imm};
                sprintf(mOperands, "loc_%x", mBranchInstr.segment*0x10+mBranchInstr.offset);
                break;
            case X86_INS_RET:
                mNextInstr = address_t{};
                break;
            default:
                break;
        }
    }
    address_t Next()
    {
        return mNextInstr;
    }
    address_t NextBranch()
    {
        return mBranchInstr;
    }
    address_t NextFollowing()
    {
        return mAddress + mSize;
    }
    /*
    address_t Next()
    {
        address_t temp = mNextInstr;
        mNextInstr = mBranchInstr;
        mBranchInstr = address_t{};

        return temp;
    }*/
    bool isConditionalBranch()
    {
        return false;
    }
    void Dump() const
    {
        if (mLabel)
            printf("        \tloc_%x:\n", mAddress.segment*0x10+mAddress.offset);
        printf("%04x:%04x\t  %s\t%s\n", mAddress.segment, mAddress.offset, mMnemonic, mOperands);
    }
};

class Capstone
{
    csh mHandle;
    cs_insn* mInsn;
    const uint8_t* mpBuffer;
    size_t mSize;
    uint64_t mBase;
    
public:
    Capstone()
    {
        cs_err err = cs_open(CS_ARCH_X86, CS_MODE_16, &mHandle);
        if (err) {
            printf("Failed on cs_open() with error returned: %u\n", err);
            abort();
        }
        cs_option(mHandle, CS_OPT_DETAIL, CS_OPT_ON);
        mInsn = cs_malloc(mHandle);
        _handle = mHandle;
    }
    ~Capstone()
    {
        cs_free(mInsn, 1);
        cs_close(&mHandle);
    }
    
    void Set(const std::vector<char>& buffer, uint64_t base)
    {
        mpBuffer = (const uint8_t*)buffer.data();
        mSize = buffer.size();
        mBase = base;
    }
    
    const uint8_t* GetBufferAt(address_t addr)
    {
        uint64_t address = addr.segment*16 + addr.offset;
        assert(address - mBase > 0x200 && address - mBase+32 < mSize);
        return mpBuffer + address - mBase;
    }
    
    std::shared_ptr<CapInstr> Disasm(address_t addr)
    {
        uint64_t address = addr.segment*16 + addr.offset;
        size_t codeSize = 32;
        const uint8_t* buf = GetBufferAt(addr);
        cs_disasm_iter(mHandle, &buf, &codeSize, &address, mInsn);
/*
        print_insn_detail(_handle, CS_MODE_16, mInsn);
        
        cs_x86 *x86 = &(mInsn->detail->x86);
        for (int i=0; i<x86->op_count; i++)
            if (x86->operands[i].type == X86_OP_MEM)
                assert(x86->operands[i].mem.disp >= 0);
*/
        
        return std::shared_ptr<CapInstr>(new CapInstr(addr, mInsn));
    }
};

bool ExtractMethod(Capstone& cap, address_t address, std::vector<std::shared_ptr<CapInstr>>& code)
{
    std::list<address_t> trace;
    trace.push_back(address);
    std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> instructions;
    
    while (!trace.empty())
    {
        address_t pc = trace.front();
        trace.pop_front();
        std::shared_ptr<CapInstr> instr = cap.Disasm(pc);
        instructions.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(pc, instr));
        
        //instr->Dump();
        if ((pc = instr->Next()).segment != -1)
            if (instructions.find(pc) == instructions.end())
            {
                if (pc.linearOffset() < address.linearOffset())
                {
                    instr->mMark = true;
                    continue;
                } else {
                    assert(pc.linearOffset() >= address.linearOffset());
                    trace.push_back(pc);
                }
            }
        if ((pc = instr->NextBranch()).segment != -1)
            if (instructions.find(pc) == instructions.end())
            {
                assert(pc.linearOffset() >= address.linearOffset());
                trace.push_back(pc);
            }
    }

    for( auto iter = instructions.begin(); iter != instructions.end(); iter++ )
    {
        address_t branch = iter->second->NextBranch();
        if (iter->second->Next().isValid() &&
            iter->second->Next().linearOffset() != iter->second->NextFollowing().linearOffset())
            branch = iter->second->Next();
        if (branch.segment != -1)
            instructions.find(branch)->second->mLabel = true;
    }

    
    // fix small gaps
    address_t nextAddr;
    for( auto iter = instructions.begin(); iter != instructions.end(); iter++ )
    {
        address_t addr = iter->first;
        std::shared_ptr<CapInstr> instr = iter->second;
        if (nextAddr.segment != -1 && addr.linearOffset() != nextAddr.linearOffset())
        {
            int gapsize = addr.linearOffset() - nextAddr.linearOffset();
            assert(gapsize <= 4);
            std::shared_ptr<CapInstr> gap = std::shared_ptr<CapInstr>(new CapInstr(nextAddr, gapsize, format("gap of %d bytes", gapsize)));
            instructions.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(nextAddr, gap));
        }

//        printf("%04x:%04x %s %s (%d)\n", iter->first.segment, iter->first.offset,
//               iter->second->mMnemonic, iter->second->mOperands, instr->mSize);
        nextAddr = instr->NextFollowing();
    }
    
    nextAddr = address_t{};
    for( auto iter = instructions.begin(); iter != instructions.end(); iter++ )
    {
        address_t addr = iter->first;
        std::shared_ptr<CapInstr> instr = iter->second;
        if (nextAddr.segment != -1)
        {
            if (addr != nextAddr)
                return false;
            
            assert(addr == nextAddr);
        }
            
        nextAddr = instr->NextFollowing();
        code.push_back(instr);
    }
    return true;
}

void DumpCode(const std::vector<std::shared_ptr<CapInstr>>& code)
{
    for (const std::shared_ptr<CapInstr>& instr : code)
        instr->Dump();
}

std::string ToCString(const cs_x86_op& op)
{
    if (op.type == X86_OP_REG)
        return cs_reg_name(_handle, op.reg);
    if (op.type == X86_OP_IMM && op.size == 1)
    {
        char tmp[32];
        sprintf(tmp, "0x%02llx", op.imm);
        return tmp;
    }
    if (op.type == X86_OP_IMM && op.size == 2)
    {
        char tmp[32];
        sprintf(tmp, "0x%04llx", op.imm & 0xffff);
        return tmp;
    }
    if (op.type == X86_OP_MEM)
    {
        char offset[32] = "";
        if (op.mem.base == X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID)
            sprintf(offset, "0x%04x", op.mem.disp & 0xffff);
        else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID && op.mem.disp == 0)
            sprintf(offset, "%s", cs_reg_name(_handle, op.mem.base));
        else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID)
        {
            if (op.mem.base != X86_REG_BP)
                sprintf(offset, "%s + %d", cs_reg_name(_handle, op.mem.base), op.mem.disp & 0xffff);
            else
            {
                if ((op.mem.disp & 0xffff) < 60000)
                    sprintf(offset, "%s + %d", cs_reg_name(_handle, op.mem.base), op.mem.disp & 0xffff);
                else
                    sprintf(offset, "%s - %d", cs_reg_name(_handle, op.mem.base), 0x10000-abs(op.mem.disp & 0xffff));
            }
        }
        else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index != X86_REG_INVALID && op.mem.disp == 0)
            sprintf(offset, "%s + %s", cs_reg_name(_handle, op.mem.base), cs_reg_name(_handle, op.mem.index));
        else
            assert(0);
        
        char tmp[64];
        const char* segment = "?";
        switch (op.mem.segment)
        {
            case X86_REG_INVALID:
                segment = op.mem.base == X86_REG_BP ? "ss" : "ds";
                break;
            default:
                segment = cs_reg_name(_handle, op.mem.segment);
        }

        sprintf(tmp, "memory%s(%s, %s)", op.size == 2 ? "16" : "", segment, offset);
        return tmp;
    }

    assert(0);
    return "?";
}

std::string SignedType(const cs_x86_op& op)
{
    if (op.size == 1)
        return "char";
    if (op.size == 2)
        return "short";
    assert(0);
    return "?";
}

std::string MakeCFlagCondition(x86_insn op)
{
    switch (op)
    {
        case X86_INS_JE:
            return "flags.zero";
        case X86_INS_JNE:
            return "!flags.zero";
        default:
            assert(0);
            return "stop()";
    }
}
std::string MakeCCondition(std::shared_ptr<CapInstr>& inst, x86_insn op)
{
    const cs_x86& x86 = inst->mDetail;

    char tmp[64];
    switch(inst->mId)
    {
        case X86_INS_CMP:
            assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
            switch (op)
            {
                case X86_INS_JE:
                    sprintf(tmp, "%s == %s", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JNE:
                    sprintf(tmp, "%s != %s", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JAE:
                    sprintf(tmp, "%s >= %s", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JGE:
                    sprintf(tmp, "(%s)%s >= (%s)%s", SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[0]).c_str(), SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JG:
                    sprintf(tmp, "(%s)%s > (%s)%s", SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[0]).c_str(), SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JNS:
                    sprintf(tmp, "(%s)%s >= 0", SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[0]).c_str());
                    return tmp;
                case X86_INS_JL:
                    sprintf(tmp, "(%s)%s < (%s)%s", SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[0]).c_str(), SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JLE:
                    sprintf(tmp, "(%s)%s <= (%s)%s", SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[0]).c_str(), SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JBE:
                    sprintf(tmp, "%s <= %s", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JB:
                    sprintf(tmp, "%s < %s", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JA:
                    sprintf(tmp, "%s > %s", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                default:
                    assert(0);
            }
            break;
        case X86_INS_TEST:
            assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
            switch (op)
            {
                case X86_INS_JE:
                    sprintf(tmp, "!(%s & %s)", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                case X86_INS_JNE:
                    sprintf(tmp, "%s & %s", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str());
                    return tmp;
                default:
                    assert(0);
            }
            break;
        case X86_INS_ADD:
        case X86_INS_SUB:
        case X86_INS_AND:
        case X86_INS_DEC:
        case X86_INS_SHR:
        case X86_INS_INC:
            assert(x86.op_count >= 1);
            //assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
            switch (op)
            {
                case X86_INS_JE:
                    sprintf(tmp, "%s == 0", ToCString(x86.operands[0]).c_str());
                    return tmp;
                case X86_INS_JNE:
                    sprintf(tmp, "%s != 0", ToCString(x86.operands[0]).c_str());
                    return tmp;
                case X86_INS_JNS:
                    sprintf(tmp, "(%s)%s >= 0", SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[0]).c_str());
                    return tmp;
                case X86_INS_JS:
                    sprintf(tmp, "(%s)%s < 0", SignedType(x86.operands[0]).c_str(), ToCString(x86.operands[0]).c_str());
                    return tmp;
                case X86_INS_JAE:
                    if (inst->mInject != inject_t::carry)
                    {
                        inst->mInject = inject_t::carry;
                        sprintf(tmp, "stop()");
                    } else {
                        sprintf(tmp, "!flags.carry");
                    }
                    return tmp;
                default:
                    assert(0);
            }
            break;
        case X86_INS_INT:
            switch (op)
            {
                case X86_INS_JAE:
                    sprintf(tmp, "!flags.carry");
                    return tmp;
                default:
                    assert(0);
            }
            break;
        default:
            assert(0);
    }
}

void FindCalls(const std::vector<std::shared_ptr<CapInstr>>& code, std::list<address_t>& toProcess)
{
    for (const std::shared_ptr<CapInstr>& instr : code)
        if (instr->mId == X86_INS_CALL)
        {
            const cs_x86& x86 = instr->mDetail;

            if (x86.op_count == 1 && x86.operands[0].type == X86_OP_IMM && x86.operands[0].size == 2)
            {
                toProcess.push_back(address_t{instr->mAddress.segment, (int)x86.operands[0].imm});
            } else if (x86.op_count == 1 && x86.operands[0].type == X86_OP_MEM && x86.operands[0].size == 2)
            {
                // indirect
            } else
                assert(0);
        }
}

void FindSwitches(const std::vector<std::shared_ptr<CapInstr>>& code, std::vector<switch_t>& switches)
{
    std::shared_ptr<CapInstr> prev;
    for (const std::shared_ptr<CapInstr>& instr : code)
    {
        if (instr->mId == X86_INS_CALL)
        {
            const cs_x86& x86 = instr->mDetail;
            if (x86.op_count == 1 && x86.operands[0].type == X86_OP_MEM && x86.operands[0].size == 2 &&
                x86.operands[0].mem.base != X86_REG_INVALID)
            {
                assert(prev && prev->mId == X86_INS_SHL && prev->mDetail.operands[1].type == X86_OP_IMM && prev->mDetail.operands[1].imm == 1);
                assert(x86.operands[0].mem.segment == X86_REG_CS);
                assert(x86.operands[0].mem.scale == 1);
                assert(x86.operands[0].mem.base == X86_REG_BX);
                switches.push_back({instr->mAddress, address_t{0x1000, (int)x86.operands[0].mem.disp}, -1, switch_t::Words, x86.operands[0].mem.base});
            }
        }
        prev = instr;
    }
}

bool DumpCodeAsC(const std::vector<std::shared_ptr<CapInstr>>& code, std::vector<std::string>& text, std::vector<switch_t>& switches)
{
    bool modified = false;
    text.push_back(format("void sub_%x()", code[0]->mAddress.linearOffset()));
    text.push_back(format("{"));
    std::shared_ptr<CapInstr> lastCompare;
    bool keepLastCompare{false};
    
    auto GetPrev = [&](const std::shared_ptr<CapInstr>& p)->std::shared_ptr<CapInstr>
    {
        for (int i=0; i<code.size(); i++)
            if (code[i]->mAddress == p->mAddress)
                return code[i-1];
        assert(0);
        return {};
    };
    
    for (const std::shared_ptr<CapInstr>& instr : code)
    {
        const cs_x86& x86 = instr->mDetail;
        keepLastCompare = false;
        
        if (instr->mMark)
        {
            text.push_back(format("stop(); // %s %s %s", instr->mMnemonic, instr->mOperands, instr->mComment.c_str()));
            continue;
        }
        
        if (instr->mLabel)
        {
            lastCompare.reset();
            text.push_back(format("loc_%x:", instr->mAddress.linearOffset()));
        }

        if (instr->mInject != inject_t::none)
        {
            if ((int)instr->mInject & (int)inject_t::carry)
            {
                switch (instr->mId)
                {
                    case X86_INS_SHR:
                        text.push_back(format("flags.carry = %s & 1;", ToCString(x86.operands[0]).c_str()));
                        break;
                    default:
                        assert(0);
                        break;
                }
            } else
            if ((int)instr->mInject & (int)inject_t::zero)
            {
                switch (instr->mId)
                {
                    case X86_INS_CMP:
                        text.push_back(format("flags.zero = %s == %s;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                        break;
                    default:
                        assert(0);
                        break;
                }
            } else
                assert(0);
        }

        switch (instr->mId)
        {
            case X86_INS_DIV:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_REG);
                text.push_back(format("div(%s);", ToCString(x86.operands[0]).c_str()));
                break;

            case X86_INS_CWDE:
                text.push_back(format("cbw();"));
                break;

            case X86_INS_NOT:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_REG &&
                       x86.operands[0].size == 2);
                text.push_back(format("%s = ~%s;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[0]).c_str()));
                break;
            case X86_INS_NEG:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_REG);
                text.push_back(format("%s = -%s;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[0]).c_str()));
                break;
            case X86_INS_PUSH:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_REG &&
                       x86.operands[0].size == 2);
                text.push_back(format("push(%s);", ToCString(x86.operands[0]).c_str()));
                keepLastCompare = true;
                break;
            case X86_INS_POP:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_REG &&
                       x86.operands[0].size == 2);
                text.push_back(format("pop(%s);", ToCString(x86.operands[0]).c_str()));
                keepLastCompare = true;
                break;

            case X86_INS_STOSW:
                if (strcmp(instr->mMnemonic, "rep stosw") == 0 &&
                    strcmp(instr->mOperands, "word ptr es:[di], ax") == 0)
                {
                    text.push_back(format("rep_stosw<MemAuto, DirAuto>();"));
                    break;
                }
                assert(0);
                break;
            case X86_INS_STOSB:
                if (strcmp(instr->mMnemonic, "rep stosb") == 0 &&
                    strcmp(instr->mOperands, "byte ptr es:[di], al") == 0)
                {
                    text.push_back(format("rep_stosb<MemAuto, DirAuto>();"));
                    break;
                }
                assert(0);
                break;
            case X86_INS_MOVSB:
                if (strcmp(instr->mMnemonic, "rep movsb") == 0 &&
                    strcmp(instr->mOperands, "byte ptr es:[di], byte ptr [si]") == 0)
                {
                    text.push_back(format("rep_movsb<MemAuto, MemAuto, DirAuto>();"));
                    break;
                }
                assert(0);
                break;
            case X86_INS_MOVSW:
                if (strcmp(instr->mMnemonic, "movsw") == 0 &&
                    strcmp(instr->mOperands, "word ptr es:[di], word ptr [si]") == 0)
                {
                    text.push_back(format("movsw<MemAuto, MemAuto, DirAuto>();"));
                    break;
                }
                assert(0);
                break;
            case X86_INS_LODSB:
                if (strcmp(instr->mMnemonic, "lodsb") == 0 &&
                    strcmp(instr->mOperands, "al, byte ptr [si]") == 0)
                {
                    text.push_back(format("lodsb<MemAuto, DirAuto>();"));
                    break;
                }
                assert(0);
                break;
            case X86_INS_INC:
                text.push_back(format("%s++;", ToCString(x86.operands[0]).c_str()));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_DEC:
                text.push_back(format("%s--;", ToCString(x86.operands[0]).c_str()));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_IN:
                text.push_back(format("in(%s, %s);", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                break;
            case X86_INS_OUT:
                text.push_back(format("out(%s, %s);", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                break;
            case X86_INS_CLD:
                text.push_back(format("flags.direction = false;"));
                break;
            case X86_INS_STD:
                text.push_back(format("flags.direction = true;"));
                break;
            case X86_INS_CLI:
                text.push_back(format("flags.interrupts = false;"));
                break;
            case X86_INS_STI:
                text.push_back(format("flags.interrupts = true;"));
                break;
            case X86_INS_INT:
                assert(x86.op_count == 1 && x86.operands[0].type == X86_OP_IMM);
                text.push_back(format("interrupt(0x%x);", (int)x86.operands[0].imm));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_ADD:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                text.push_back(format("%s += %s;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                lastCompare = instr;
                keepLastCompare = true;
                break;
                /*
            case X86_INS_ADC:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                text.push_back(format("%s += %s + flags.carry;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                lastCompare = instr;
                keepLastCompare = true;
                break;
                 */
            case X86_INS_AND:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                text.push_back(format("%s &= %s;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_OR:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                text.push_back(format("%s |= %s;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                //lastCompare = instr;
                //keepLastCompare = true;
                break;
            case X86_INS_SUB:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                text.push_back(format("%s -= %s;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_SAR:
                assert(x86.op_count == 2 && x86.operands[1].type == X86_OP_IMM);
                text.push_back(format("sar(%s, %d);", ToCString(x86.operands[0]).c_str(), (int)x86.operands[1].imm));
                break;
            case X86_INS_SHL:
                assert(x86.op_count == 2 && x86.operands[1].type == X86_OP_IMM);
                text.push_back(format("%s <<= %d;", ToCString(x86.operands[0]).c_str(), (int)x86.operands[1].imm));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_SHR:
                if (x86.op_count == 2 && x86.operands[1].type == X86_OP_IMM)
                {
                    assert(x86.op_count == 2 && x86.operands[1].type == X86_OP_IMM);
                    text.push_back(format("%s >>= %d;", ToCString(x86.operands[0]).c_str(), (int)x86.operands[1].imm));
                } else
                if (x86.op_count == 2 && x86.operands[1].type == X86_OP_REG)
                {
                    text.push_back(format("%s >>= %s;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                } else
                    assert(0);
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_RET:
                if (x86.op_count == 0)
                    text.push_back(format("return;"));
                else if (x86.op_count == 1 && x86.operands[0].type == X86_OP_IMM)
                {
                    text.push_back(format("sp += %d;", x86.operands[0].imm));
                    text.push_back(format("return;"));
                }
                else
                    assert(0);
                break;
            case X86_INS_CMP:
            case X86_INS_TEST:
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_JE:
            case X86_INS_JAE:
            case X86_INS_JNE:
            case X86_INS_JGE:
            case X86_INS_JLE:
            case X86_INS_JBE:
            case X86_INS_JNS:
            case X86_INS_JS:
            case X86_INS_JB:
            case X86_INS_JG:
            case X86_INS_JA:
            case X86_INS_JL:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_IMM &&
                       x86.operands[0].size == 2);

                if (!lastCompare && !instr->mForceFlagCondition)
                {
                    // try to follow all paths to this instruction
                    if (instr->mLabel)
                    {
                        // find all paths to this label
                        std::vector<std::shared_ptr<CapInstr>> allPaths;
                        std::shared_ptr<CapInstr> prev = GetPrev(instr);
                        if (prev && prev->mId != X86_INS_JMP && prev->mId != X86_INS_RET)
                            allPaths.push_back(prev);

                        for (const std::shared_ptr<CapInstr>& i : code)
                        {
                            if (i->NextBranch() == instr->mAddress)
                            {
                                assert(!i->mLabel);
                                allPaths.push_back(GetPrev(i));
                            }
                        }
                        if (allPaths.size() == 1)
                            lastCompare = allPaths[0];
                        else
                        {
                            if (allPaths.size() == 2 &&
                                allPaths[0]->mId == X86_INS_CMP &&
                                allPaths[1]->mId == X86_INS_CMP &&
                                allPaths[0]->mDetail.op_count == 2 &&
                                allPaths[1]->mDetail.op_count == 2 &&
                                allPaths[0]->mDetail.operands[0].type == X86_OP_REG &&
                                allPaths[1]->mDetail.operands[0].type == X86_OP_REG &&
                                allPaths[0]->mDetail.operands[0].reg == allPaths[1]->mDetail.operands[0].reg)
                            {
                                if (instr->mId == X86_INS_JE || instr->mId == X86_INS_JNE)
                                {
                                    allPaths[0]->mInject = (inject_t)((int)allPaths[0]->mInject | (int)inject_t::zero);
                                    allPaths[1]->mInject = (inject_t)((int)allPaths[0]->mInject | (int)inject_t::zero);
                                    instr->mForceFlagCondition = true;
                                    modified = true;
                                }
                            }
                        }
                    }
                }
                {
                    inject_t injectPrev = lastCompare ? lastCompare->mInject : inject_t::none;

                    if (!instr->mForceFlagCondition)
                    {
                        assert(lastCompare);
                        text.push_back(format("if (%s)", MakeCCondition(lastCompare, instr->mId).c_str()));
                    }
                    else
                        text.push_back(format("if (%s)", MakeCFlagCondition(instr->mId).c_str()));
                    text.push_back(format("goto loc_%x;", address_t{instr->mAddress.segment, (int)x86.operands[0].imm}.linearOffset()));
                    keepLastCompare = true;
                    if (injectPrev != (lastCompare ? lastCompare->mInject : inject_t::none))
                        modified = true;
                }
                break;
            case X86_INS_JCXZ:
                text.push_back(format("if (cx == 0)"));
                text.push_back(format("goto loc_%x;", address_t{instr->mAddress.segment, (int)x86.operands[0].imm}.linearOffset()));
                break;
            case X86_INS_JMP:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_IMM &&
                       x86.operands[0].size == 2);

                text.push_back(format("goto loc_%x;", address_t{instr->mAddress.segment, (int)x86.operands[0].imm}.linearOffset()));
                break;
            case X86_INS_LOOP:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_IMM &&
                       x86.operands[0].size == 2);

               text.push_back(format("if (--cx)"));
               text.push_back(format("goto loc_%x;", address_t{instr->mAddress.segment, (int)x86.operands[0].imm}.linearOffset()));
                break;

            case X86_INS_CALL:
                
                if (x86.op_count == 1 && x86.operands[0].type == X86_OP_IMM && x86.operands[0].size == 2)
                {
                    text.push_back(format("sub_%x();", address_t{instr->mAddress.segment, (int)x86.operands[0].imm}.linearOffset()));
                } else if (x86.op_count == 1 && x86.operands[0].type == X86_OP_MEM && x86.operands[0].size == 2)
                {
                    const auto sw = std::find_if(switches.begin(), switches.end(), [&](const switch_t& sw){
                        return sw.origin == instr->mAddress;
                    });
                    if (sw != switches.end() && sw->elements != -1)
                    {
                        text.push_back(format("switch (%s)", sw->GetSelector().c_str()));
                        text.push_back("{");
                        for (int i=0; i<sw->elements; i++)
                            text.push_back(sw->GetCase(i));
                        text.push_back("default:");
                        text.push_back("assert(0);");
                        text.push_back("}");
                        // TODO: possible to use switch after analysis finish
                    } else {
                        text.push_back(format("callIndirect(%s);", ToCString(x86.operands[0]).c_str()));
                    }
                } else
                    assert(0);
                break;
            case X86_INS_MOV:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                text.push_back(format("%s = %s;", ToCString(x86.operands[0]).c_str(), ToCString(x86.operands[1]).c_str()));
                break;
                
            default:
                assert(0);
        }

        if (!keepLastCompare)
            lastCompare.reset();
    }
    text.push_back(format("}"));
    return modified;
    //X86_INS_MOV
}

void ReplaceAll(std::vector<std::string>& text, const std::string& from, const std::string& to)
{
    for (auto i=text.begin(); i!=text.end(); i++)
        if (*i == from)
            *i = to;
}

void OptimizeCode(std::vector<std::string>& text)
{
    if (text[text.size()-2] == "return;")
    {
        const std::string& label = text[text.size()-3];
        if (label.substr(0, 4) == "loc_")
        {
            // replace all local labels with return
            ReplaceAll(text, "goto "+label.substr(0, label.length()-1) + ";", "return;");
            text.erase(std::prev(text.end(), 3));
        }
        text.erase(std::prev(text.end(), 2));
    }
}


struct MZHeader
{
    char id[2];
    uint16_t lastPageBytes;
    uint16_t full512Pages;
    uint16_t relocations;
    uint16_t headerSize16;
    uint16_t minMemory;
    uint16_t maxMemory;
    uint16_t ss;
    uint16_t sp;
    uint16_t checksum;
    uint16_t ip;
    uint16_t cs;
    uint16_t relocationOffset;
    uint16_t overlayNumber;
};
struct MZRelocation
{
    uint16_t offset;
    uint16_t segment;
};

int main(int argc, const char * argv[]) {
    std::ifstream file("/Users/gabrielvalky/Documents/git/Projects/CicoJit/capst/GOOSE.EXE", std::ios::binary | std::ios::ate);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size))
        throw "problem";

    MZHeader* header = (MZHeader*)&buffer[0];
    assert(header->id[0] == 'M' && header->id[1] == 'Z');
    
    printf(R"(
#include "cicoemu.h"
using namespace CicoContext;
void sub_%x();

void start()
{
  cs = 0x%04x;
  ss = 0x%04x;
  sp = 0x%04x; // check!
  sub_%x();
}
)", (0x1000+header->cs)*16+header->ip, header->cs+0x1000,
           header->ss+0x1000, header->sp, (0x1000+header->cs)*16+header->ip);

    // fix relocations, we are loading the image to 1000:0000
    for (int i=0; i<header->relocations; i++)
    {
        MZRelocation* reloc = (MZRelocation*)&buffer[header->relocationOffset+i*4];
        int linearOffset = reloc->segment*16 + reloc->offset + header->headerSize16*16;
        uint16_t* addr = (uint16_t*)&buffer[linearOffset];
        *addr += 0x1000;
    }

    Capstone cap;
    cap.Set(buffer, 0x10000 - header->headerSize16*0x10);
    
    //std::map<address_t, CapFunction_t> functions;
    std::map<address_t, function_t, cmp_adress_t> processed;
    std::vector<address_t> failed;
    std::list<address_t> toProcess;
    std::vector<switch_t> switches;
    toProcess.push_back({header->cs+0x1000, header->ip});
    //toProcess.push_back({0x1000, 0x0bdc});
    
    for (int i=0; i<=136; i+=4)
    {
        const uint8_t* p = cap.GetBufferAt({0x1000, 0x105a+i/2});
        address_t targ{0x1000, p[1]*256+p[0]};
//        printf("case 0x%x: sub_%x(); // %04x:%04x\n", targ.linearOffset(), targ.linearOffset(), targ.segment, targ.offset);
        toProcess.push_back(targ);
    }
    
    
    while (!toProcess.empty())
    {
        address_t method = toProcess.front();
        toProcess.pop_front();

        if (processed.find(method) != processed.end())
            continue;
        if (std::find(failed.begin(), failed.end(), method) != failed.end())
            continue;

        std::vector<std::shared_ptr<CapInstr>> code;
//        printf("// extracting %04x:%04x, converted %d, to convert %d, failed %d\n", method.segment, method.offset, processed.size(), toProcess.size(), failed.size());
        if (!ExtractMethod(cap, method, code))
        {
            printf("Conversion failed!\n");
            failed.push_back(method);
            continue;
        }
        int size = code[code.size()-1]->NextFollowing().linearOffset() - code[0]->mAddress.linearOffset();
        processed.insert(std::pair<address_t, function_t>(method, function_t{method, size}));

        //DumpCode(code);
        FindCalls(code, toProcess);
        FindSwitches(code, switches);
    }
    auto CheckOverlap = [&](const address_t& begin, int size)
    {
        return std::find_if(processed.begin(), processed.end(), [&](const auto& t){
            const function_t& func = t.second;
            return !((begin >= func.begin + func.length) || (begin+size < func.begin));
        }) != processed.end();
    };
    
    for (auto& sw : switches)
    {
        sw.baseptr = cap.GetBufferAt(sw.GetBaseAddress());
        
        for (int i=0; i<200; i++)
        {
            address_t addr = sw.GetAddressAt(i);
            int size = sw.GetSize();
            if (CheckOverlap(addr, size))
            {
                sw.elements = i;
                break;
            }
            toProcess.push_back(sw.GetTarget(i));
        }
        assert(sw.elements != -1);
    }
    
    while (!toProcess.empty())
    {
        address_t method = toProcess.front();
        toProcess.pop_front();

        if (processed.find(method) != processed.end())
            continue;
        if (std::find(failed.begin(), failed.end(), method) != failed.end())
            continue;

        std::vector<std::shared_ptr<CapInstr>> code;
        //printf("// extracting %04x:%04x, converted %d, to convert %d, failed %d\n", method.segment, method.offset, processed.size(), toProcess.size(), failed.size());
        if (!ExtractMethod(cap, method, code))
        {
            printf("Conversion failed!\n");
            failed.push_back(method);
            continue;
        }
        int size = code[code.size()-1]->NextFollowing().linearOffset() - code[0]->mAddress.linearOffset();
        processed.insert(std::pair<address_t, function_t>(method, function_t{method, size}));

        FindCalls(code, toProcess);
        FindSwitches(code, switches);
    }
    
    for (const auto& decl : processed)
        printf("void sub_%x();\n", decl.second.begin.linearOffset());
     
    for (const auto& decl : processed)
    {
        std::vector<std::shared_ptr<CapInstr>> code;
        if (!ExtractMethod(cap, decl.first, code))
            assert(0);

        std::vector<std::string> text;
        if (DumpCodeAsC(code, text, switches))
        {
            text.clear();
            DumpCodeAsC(code, text, switches);
        }
        OptimizeCode(text);
        for (const auto& l : text)
            printf("%s\n", l.c_str());
    }
    
    return 0;
}
