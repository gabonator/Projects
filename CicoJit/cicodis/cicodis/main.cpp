/*
 /Users/gabrielvalky/Documents/git/Projects/CicoJit/games/fox/GAME.EXE
 start,1020:5dce,1020:476c,1020:4dfd,1020:4e87,1020:63f1,1020:63bf,1020:4d0b,1020:4748,1020:47b7,1020:47fa,1020:4df9,1020:47b7,1020:47d3,1020:5a04,1020:4e88,1020:4d0c,1020:4dc9,1020:4d10,1020:4db1,1020:4826,1020:4f03,1020:4e2e,1020:495b,1020:48cc,1020:48d6,1020:622e,1020:4833,1020:14e5,1020:157c,1020:147a,1020:147d,1020:1585,1020:14dd,1020:158c,1020:1591
 
 
 xenon
 start,14311,14759,137df,172c4,1758f,1655b,10853,10761,17520,170f1,16eef,141e2,1480b,1714a,108b9,10f2b,137ca,11e61,128df,12ab2,13aa7,12a6e,16d22,13a39,1308c,139ee,1091f,10897,13998,141fb,11f4d,13835,13b76,16a0a,125a8,16aad,13bdf,16696,169d0,166a6,16bca,12ad0,16e2c,171dd,12a48,1714d,169c8,13246,13a99,17569,18ca7,17f32,17f79,18e01,189ae,188a9,18c3e,17dde,16284,19f02,19f9a,19fe6,19f4e,121e9,1246d,128b8,14f96,12aa4,180ca,1866d,18114,18126,180f5,187d5,18783,14311,14759,137df,172c4,1758f,1655b,10853,10761,17520,170f1,16eef,141e2,1480b,1714a,108b9,10f2b,137ca,11e61,128df,12ab2,13aa7,12a6e,16d22,13a39,1308c,139ee,1091f,10897,13998,141fb,11f4d,13835,13b76,16a0a,125a8,16aad,13bdf,16696,169d0,166a6,16ac7,16bca,12ad0,16e2c,171dd,12a48,1714d,169c8,13246,13a99,17569,18ca7,17f32,17f79,18e01,189ae,188a9,18c3e,17dde,16284,19f02,19f9a,19fe6,19f4e,121e9,1246d,128b8,14f96,12aa4,180ca,1866d,18114,18126,180f5,187d5,18783
 
 */
//
//  main.cpp
//  cicodis
//
//  Created by Gabriel Valky on 27/08/2022.
//

/*
 
cicodis rd1.exe start,0x12345,0x12345,1000:0123 -recursive -o mojfile.cpp
 cicodis rd1.exe start,0x12345,0x12345,1000:0123 -recursive -o mojfolder/
cicodis rd1.exe 1000:0232 -resume /games/rd1/cicocode/ -asm?

 todo: if (--cx && bl & al)
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <capstone/platform.h>
#include <capstone/capstone.h>
#include <sstream>
#include <string>
#include <regex>

bool verbose_asm = false;
bool segofs_in_comment = false;
csh _handle;
int _cs;
int _ds = 0;
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

std::string ToCString(const cs_x86_op& op);
void GetOpAddress(const cs_x86_op& op, char* segment, char* offset);

const char* SignedType(const cs_x86_op& op)
{
    if (op.size == 1)
        return "char";
    if (op.size == 2)
        return "short";
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

std::string vassign(const cs_x86& x86, const char* fmt_, va_list args)
{
    const bool getset = true;
    char fmt[256];
    char tok[32];
    strcpy(fmt, fmt_);
    char* p = fmt;
    
    if (getset)
    {
        bool firstWr = memcmp(fmt, "$wr", 3) == 0;
        bool firstRdWr = memcmp(fmt, "$rw", 3) == 0;
        if (firstWr || firstRdWr)
        {
            int index = fmt[3] - '0';
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
                        sprintf(newfmt, "$wr%d = $rd%d + 1;", index, index);
                    else if (strcmp(fmt+4, "--;") == 0)
                        sprintf(newfmt, "$wr%d = $rd%d - 1;", index, index);
                    else if (strncmp(fmt+4, " |= ", 4) == 0)
                        sprintf(newfmt, "$wr%d = $rd%d | %s;", index, index, enclose(fmt+8).c_str());
                    else if (strncmp(fmt+4, " &= ", 4) == 0)
                        sprintf(newfmt, "$wr%d = $rd%d & %s;", index, index, enclose(fmt+8).c_str());
                    else if (strncmp(fmt+4, " += ", 4) == 0)
                        sprintf(newfmt, "$wr%d = $rd%d + %s;", index, index, enclose(fmt+8).c_str());
                    else if (strncmp(fmt+4, " -= ", 4) == 0)
                        sprintf(newfmt, "$wr%d = $rd%d - %s;", index, index, enclose(fmt+8).c_str());
                    else if (strncmp(fmt+4, " ^= ", 4) == 0)
                        sprintf(newfmt, "$wr%d = $rd%d ^ %s;", index, index, enclose(fmt+8).c_str());
                    else if (strncmp(fmt+4, " >>= ", 5) == 0)
                        sprintf(newfmt, "$wr%d = $rd%d >> %s;", index, index, enclose(fmt+9).c_str());
                    else if (strncmp(fmt+4, " <<= ", 5) == 0)
                        sprintf(newfmt, "$wr%d = $rd%d << %s;", index, index, enclose(fmt+9).c_str());
                    else
                        assert(0);
                    strcpy(fmt, newfmt);
                }
                char rvalue[32] = "";
                assert(fmt[5] == '=' && fmt[6] == ' ');
                strcat(rvalue, fmt+7);
                assert(rvalue[strlen(rvalue)-1] == ';');
                rvalue[strlen(rvalue)-1] = 0;
                
                std::string rvalue_formatted = vassign(x86, rvalue, args);
                
                char segment[32], offset[32], tmp[64];
                GetOpAddress(op, segment, offset);
                sprintf(tmp, "memoryASet%s(%s, %s, %s);",
                        x86.operands[0].size == 2 ? "16" : "", segment, offset, rvalue_formatted.c_str());
                return tmp;
            } else {
                char tmp[64];
                strcpy(tmp, ToCString(op).c_str());
                strcat(tmp, fmt+4);
                strcpy(fmt, tmp);
            }
        }
    }
    
    while ((p = strstr(p, "$")) != nullptr)
    {
        char replace[64];
        p++;
        tok[0] = 0;
        for (int i=0; i<32; i++)
        {
            tok[i] = p[i];
            if ((p[i] >= '0' && p[i] <= '9') || (p[i] >= 'a' && p[i] <= 'z') )
                continue;
            
            tok[i] = 0;
            break;
        }
        
        strcpy(replace, "");
        if (strcmp(tok, "reg0") == 0)
        {
            assert(x86.op_count >= 1 /*&& x86.operands[0].type == X86_OP_REG*/);
            strcpy(replace, ToCString(x86.operands[0]).c_str());
        }
        if (strcmp(tok, "reg1") == 0)
        {
            assert(x86.op_count == 2 && x86.operands[1].type == X86_OP_REG);
            strcpy(replace, ToCString(x86.operands[1]).c_str());
        }
        if (strcmp(tok, "immd0") == 0)
        {
            assert(x86.op_count >= 1 && x86.operands[0].type == X86_OP_IMM);
            sprintf(replace, "%d", (int)x86.operands[0].imm);
        }
        if (strcmp(tok, "immx0") == 0)
        {
            assert(x86.op_count >= 1 && x86.operands[0].type == X86_OP_IMM);
            sprintf(replace, "0x%x", (int)x86.operands[0].imm);
        }
        if (strcmp(tok, "immd1") == 0)
        {
            assert(x86.op_count >= 2 && x86.operands[1].type == X86_OP_IMM);
            sprintf(replace, "%d", (int)x86.operands[1].imm);
        }
        if (strcmp(tok, "immx1") == 0)
        {
            assert(x86.op_count >= 2 && x86.operands[1].type == X86_OP_IMM);
            sprintf(replace, "0x%x", (int)x86.operands[1].imm);
        }
        if (strcmp(tok, "wr0") == 0 || strcmp(tok, "rd0") == 0 || strcmp(tok, "rw0") == 0)
        {
            if (x86.op_count == 0)
            {
                strcpy(replace, "PROBLEM-11");
            } else {
                assert(x86.op_count >= 1);
                if (getset && x86.operands[0].type == X86_OP_MEM)
                {
                    char segment[32], offset[32];
                    GetOpAddress(x86.operands[0], segment, offset);
                    sprintf(replace, "memoryAGet%s(%s, %s)",
                            x86.operands[0].size == 2 ? "16" : "", segment, offset);
                } else
                    strcpy(replace, ToCString(x86.operands[0]).c_str());
            }
        }
        if (strcmp(tok, "wr1") == 0 || strcmp(tok, "rd1") == 0 || strcmp(tok, "rw1") == 0)
        {
            if (x86.op_count == 0)
                strcpy(replace, "PROBLEM-11f");
            else
            {
                assert(x86.op_count >= 2);
                if (getset && x86.operands[1].type == X86_OP_MEM)
                {
                    char segment[32], offset[32];
                    GetOpAddress(x86.operands[1], segment, offset);
                    sprintf(replace, "memoryAGet%s(%s, %s)",
                            x86.operands[0].size == 2 ? "16" : "", segment, offset);
                } else
                    strcpy(replace, ToCString(x86.operands[1]).c_str());
            }
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
            strcpy(replace, x86.operands[0].size == 1 ? "0x80" : "0x8000");
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

        assert(replace[0] > 0);
        char temp[128];
        memcpy(temp, fmt, (p-1)-fmt);
        temp[p-1-fmt] = 0;
        strcat(temp, replace);
        strcat(temp, p+strlen(tok));
        strcpy(fmt, temp);
        if (p-fmt>=strlen(fmt))
            break;
    }
    
    char buf[256];
    vsprintf(buf, fmt, args);
    return std::string(buf);
}


std::string assign(const cs_x86& x86, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    std::string str = vassign(x86, fmt, args);
    va_end(args);
    return str;
}


struct address_t {
    int segment{-1};
    int offset{-1};
    address_t() {}
    address_t(long s, long o) : segment{(int)s}, offset{(int)o}
    {
    }
    address_t(int s, int o) : segment{s}, offset{o}
    {
    }
    bool isValid() const
    {
        return segment != -1;
    }
    int linearOffset() const
    {
        return segment*0x10+offset;
    }
};

address_t fromRelative(int segment, uint64_t offset);

enum class inject_t {
    none = 0,
    carry = 1,
    zero = 2,
    stop = 0x400,
    discard = 0x1000,
    temp = 0x2000,
    returnZero = 0x4000,
    returnCarry = 0x8000,
    setZeroFlag = 0x10,
    clearZeroFlag = 0x20,
    setCarryFlag = 0x40,
    clearCarryFlag = 0x80
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
        None,
        CallWords,
        JumpWords
    } type{None};
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
        return address_t{begin.segment, parts[i]};
    }
    std::string GetCase(int i) const
    {
        switch (type)
        {
            case CallWords:
                return format("case %d: sub_%x(); break;", i*2, GetTarget(i).linearOffset());
            case JumpWords:
                return format("case %d: goto loc_%x;", i*2, /*GetTarget(i).linearOffset()-0x10000+_cs*0x10*/ GetTarget(i).linearOffset());
            default:
                assert(0);
                return "stop(/*3*/);";
        }
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

class CapInstr : public std::enable_shared_from_this<CapInstr>
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
    CapInstr(x86_insn id, address_t addr)
    {
        assert(id == X86_INS_JMP);
        mId = id;
        mAddress = addr;
        mNextInstr = addr;
        strcpy(mMnemonic, "");
        strcpy(mOperands, "");
        mSize = 0;
        mDetail.op_count = 0;
    }
    
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
                       x86->operands[0].size == 2);
                if (x86->operands[0].type == X86_OP_IMM)
                {
                    mNextInstr = fromRelative(x86->operands[0].imm);//{addr.segment, (int)x86->operands[0].imm - addr.segment*16 + 0x10000};
                    //mNextInstr = {0x1000, (int)x86->operands[0].imm};
                    sprintf(mOperands, "loc_%x", mNextInstr.segment*0x10+mNextInstr.offset);
                } else {
                    mNextInstr = {};
                }
                break;
                
            case X86_INS_LOOP:
            case X86_INS_LOOPNE:
            case X86_INS_JAE ... X86_INS_JL:
            case X86_INS_JNE ... X86_INS_JS:
                //print_insn_detail(_handle, CS_MODE_16, p);
                if (x86->op_count == 0)
                {
                    sprintf(mOperands, "PROBLEM-11A");
                    break;
                }
                assert(x86->op_count == 1 &&
                       x86->operands[0].type == X86_OP_IMM &&
                       x86->operands[0].size == 2);
                mBranchInstr = fromRelative( x86->operands[0].imm);//{addr.segment, (int)x86->operands[0].imm - addr.segment*16 + 0x10000};
                //1723:003b: 1723:003b      je    0x726f   ->1726f
                sprintf(mOperands, "loc_%x", mBranchInstr.linearOffset());
                break;
            case X86_INS_RET:
            case X86_INS_RETF:
                mNextInstr = address_t{};
                break;
            default:
                break;
        }
    }
    
    bool IsIndirectJump()
    {
        return mId == X86_INS_JMP && mDetail.operands[0].type == X86_OP_MEM;
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
    address_t fromRelative(uint64_t offset);
};

address_t fromRelative(int segment, uint64_t offset)
{
    // rd1
    //return address_t{segment, (int)offset - 0x41b0};
    return address_t{segment, (int)offset - segment*16 + 0x10000};
}

address_t fromRelative(const std::shared_ptr<CapInstr>& instr, uint64_t offset)
{
    return fromRelative(instr->mAddress.segment, offset);
    // address_t{instr->mAddress.segment, (int)offset - instr->mAddress.segment*16 + 0x10000};
}

address_t CapInstr::fromRelative(uint64_t offset)
{
    return ::fromRelative(mAddress.segment, offset);
}

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
        assert(address - mBase > 0x0 && address - mBase+1 <= mSize);
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

bool SetsZeroFlag(const std::shared_ptr<CapInstr>& instr)
{
    if (strcmp(instr->mMnemonic, "sub") == 0 &&
        strcmp(instr->mOperands, "al, al") == 0)
        return true;
    if (strcmp(instr->mMnemonic, "jne") == 0)
        return true;
    return false;
}

bool ClearsZeroFlag(const std::shared_ptr<CapInstr>& instr1, const std::shared_ptr<CapInstr>& instr2)
{
    if (!instr1)
        return false;
    if (strcmp(instr1->mMnemonic, "sub") == 0 &&
        strcmp(instr1->mOperands, "al, al") == 0 &&
        strcmp(instr2->mMnemonic, "dec") == 0 &&
        strcmp(instr2->mOperands, "al") == 0)
        return true;
    if (strcmp(instr1->mMnemonic, "sub") == 0 &&
        strcmp(instr1->mOperands, "ax, ax") == 0 &&
        strcmp(instr2->mMnemonic, "inc") == 0 &&
        strcmp(instr2->mOperands, "ax") == 0)
        return true;
    return false;
}

bool SetsCarryFlag(const std::shared_ptr<CapInstr>& instr)
{
    if (strcmp(instr->mMnemonic, "stc") == 0)
        return true;
    return false;
}

bool ClearsCarryFlag(const std::shared_ptr<CapInstr>& instr)
{
    if (strcmp(instr->mMnemonic, "clc") == 0)
        return true;
    return false;
}

bool ExtractMethod(Capstone& cap, address_t address, std::vector<std::shared_ptr<CapInstr>>& code, std::vector<switch_t>& indirectJumps, inject_t injectReturn)
{
    std::list<address_t> trace;
    trace.push_back(address);
    std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> instructions;
    
    while (!trace.empty())
    {
        address_t pc = trace.front();
        trace.pop_front();
        assert(pc.offset >= 0 && pc.offset < 0xffff);
        
        if (trace.size() == 0) // skip indirect jumps
        {
            // start processing indirect jumps when everything is finished
            assert(indirectJumps.size() <= 1);
            for (int i=0; i<indirectJumps.size(); i++)
            {
                switch_t& sw = indirectJumps[i];
                
                // already processed all entries?
                if (sw.elements != -1)
                    continue;
                
                for (int i=0; i<200; i++)
                {
                    address_t source = sw.GetAddressAt(i);
                    if (instructions.find(source) != instructions.end())
                    {
                        // case (offset in table) is already part of code, we've gone too far
                        sw.elements = i;
                        break;
                    }
                    address_t target{_cs, sw.GetTarget(i).offset};
                    if (target.offset == 0)
                    {
                        sw.elements = i-1;
                        break;
                    }
                    auto match = instructions.find(target);
                    if (match == instructions.end())
                    {
                        // try one more label and trace the code again
                        trace.push_back(target);
                        break;
                    } else
                        match->second->mLabel = true;
                }
            }
        }
        if (instructions.find(pc) != instructions.end())
            continue;
        
        std::shared_ptr<CapInstr> instr = cap.Disasm(pc);
        //if (verbose_asm)
          //  instr->Dump();
        instructions.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(pc, instr));
        
        if (instr->mId == X86_INS_INT && instr->mDetail.operands[0].imm == 0x21)
        {
            const auto& prev = instructions.find({pc.segment, pc.offset-2});
            // TODO: use instr->IsTerminating()?
            if (prev != instructions.end())
            {
                // app termination
                if (strcmp(prev->second->mMnemonic, "mov") == 0 &&
                    strcmp(prev->second->mOperands, "ah, 0x4c") == 0)
                {
                    continue;
                }
                // app termination
                if (strcmp(prev->second->mMnemonic, "mov") == 0 &&
                    strcmp(prev->second->mOperands, "ax, 0x4c00") == 0)
                {
                    continue;
                }
            }
        }
        
        if (1 && instr->IsIndirectJump())
        {
            assert(instr->mDetail.op_count == 1);
            const auto& op = instr->mDetail.operands[0];
            if (op.mem.segment == X86_REG_INVALID)
            {
                assert(op.mem.segment == X86_REG_INVALID); // ds?
                assert(op.mem.base == X86_REG_DI);
                assert(_ds);
                address_t table{_ds, (int)instr->mDetail.operands[0].mem.disp}; // TODO: was cs!
                const uint8_t* ptr = cap.GetBufferAt(table);
                indirectJumps.push_back({instr->mAddress, address_t{_cs, 0}, -1, switch_t::JumpWords, op.mem.base, ptr});
            } else {
                printf("// skipping indirect jump\n");
            }
        }
            
        if ((pc = instr->Next()).isValid())
            if (instructions.find(pc) == instructions.end())
            {
                assert(pc.offset >= 0 && pc.offset < 0xffff);
                trace.push_back(pc);
                /*
                if (pc.linearOffset() < address.linearOffset())
                {
                    instr->mMark = true;
                    continue;
                } else {
                    
                    assert(pc.linearOffset() >= address.linearOffset());
                    if (abs(pc.linearOffset() - address.linearOffset()) < 0x700)                    trace.push_back(pc);
                    else
                    {
                        instr->mMark = true;
                        printf("// Skipping long jump to %04x:%04x (%x) in %04x:%04x\n",
                               pc.segment, pc.offset, pc.linearOffset(), address.segment, address.offset);
                    }

                    //printf("next %04x:%04x ", pc.segment, pc.offset);
                }*/
            }
        if ((pc = instr->NextBranch()).isValid())
            if (instructions.find(pc) == instructions.end())
            {
                assert(pc.offset >= 0 && pc.offset < 0xffff);
                trace.push_back(pc);
                /*
                //assert(pc.linearOffset() >= address.linearOffset());
                if (pc.linearOffset() >= address.linearOffset() && abs(pc.linearOffset() - address.linearOffset()) < 0x700)
                    trace.push_back(pc);
                else
                {
                    instr->mMark = true;
                    printf("// Skipping long jump to %04x:%04x (%x) in %04x:%04x\n",
                           pc.segment, pc.offset, pc.linearOffset(), address.segment, address.offset);
                }
                 */
//                printf("branch %04x:%04x ", pc.segment, pc.offset);
            }
    }

    for( auto iter = instructions.begin(); iter != instructions.end(); iter++ )
    {
        address_t branch = iter->second->NextBranch();
        if (iter->second->Next().isValid() &&
            iter->second->Next().linearOffset() != iter->second->NextFollowing().linearOffset())
            branch = iter->second->Next();
        if (branch.isValid())
            instructions.find(branch)->second->mLabel = true;
        
        if (iter != instructions.begin() && iter->first == address)
        {
            iter->second->mLabel = true;
        }
        
    }

    // fix small gaps
    address_t nextAddr;
    for( auto iter = instructions.begin(); iter != instructions.end(); iter++ )
    {
        address_t addr = iter->first;
        std::shared_ptr<CapInstr> instr = iter->second;
        if (nextAddr.segment != -1 && addr.linearOffset() != nextAddr.linearOffset())
        {
            // TODO: fill data with indirect jumps
            int gapsize = addr.linearOffset() - nextAddr.linearOffset();
            /*
            if (gapsize > 140)
            {
                for (const auto &i : instructions)
                    i.second->Dump();
                
                return false;
            }
            assert(gapsize <= 140);
             */
            std::shared_ptr<CapInstr> gap = std::shared_ptr<CapInstr>(new CapInstr(nextAddr, gapsize, format("gap of %d bytes", gapsize)));
            instructions.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(nextAddr, gap));
        }

        //printf("%04x:%04x %s %s (%d)\n", iter->first.segment, iter->first.offset,
        //       iter->second->mMnemonic, iter->second->mOperands, instr->mSize);
        nextAddr = instr->NextFollowing();
    }
    
    if (instructions.begin()->first != address)
    {
//        printf("// Jump to first in %04x:%04x\n", address.segment, address.offset);
        code.push_back(std::shared_ptr<CapInstr>(new CapInstr(X86_INS_JMP, address)));
    }
        
    nextAddr = address_t{};
    std::shared_ptr<CapInstr> prev1, prev2;
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
        if (injectReturn != inject_t::none && (instr->mId == X86_INS_RET || instr->mId == X86_INS_RETF))
        {
            if (injectReturn == inject_t::returnZero)
            {
                if (prev1->mId == X86_INS_CMP || prev1->mId == X86_INS_AND)
                {
                    prev1->mInject = inject_t((int)prev1->mInject | (int)inject_t::zero);
//                    printf("// INJECT: use instruction in sub_%x()\n", address.linearOffset());
                }
                else
                if (SetsZeroFlag(prev1))
                {
                    assert(instr->mInject == inject_t::none);
                    instr->mInject = inject_t::setZeroFlag;
//                    printf("// INJECT: set sub_%x()\n", address.linearOffset());
                }
                else if (ClearsZeroFlag(prev2, prev1))
                {
                    assert(instr->mInject == inject_t::none);
                    instr->mInject = inject_t::clearZeroFlag;
//                    printf("// INJECT: clear sub_%x()\n", address.linearOffset());
                } else
                {
                    instr->mInject = inject_t::stop;
                    printf("// INJECT: Error: cannot inject zero flag in sub_%x()!\n",
                           address.linearOffset());
    //                assert(0);
                }
            } else
            if (injectReturn == inject_t::returnCarry)
            {
                // TOTO: check if there is function call before, mark function, run again!
                if (SetsCarryFlag(prev1))
                {
                    assert(instr->mInject == inject_t::none);
                    //instr->mInject = inject_t::setCarryFlag;
//                    printf("// INJECT: use set sub_%x()\n", address.linearOffset());
                }
                else if (ClearsCarryFlag(prev1))
                {
                    assert(instr->mInject == inject_t::none);
                    //instr->mInject = inject_t::clearCarryFlag;
//                    printf("// INJECT: use clear sub_%x()\n", address.linearOffset());
                } else
                {
                    instr->mInject = inject_t::stop;
                    printf("// INJECT: Error: cannot inject carry flag in sub_%x()!\n",
                           address.linearOffset());
                }
            }
        }
        code.push_back(instr);
        if (instr->mId != X86_INS_NOP && instr->mId != X86_INS_POP && instr->mId != X86_INS_MOV)
        {
            prev2 = prev1;
            prev1 = instr;
        }
        if (verbose_asm)
            instr->Dump();
    }
    
    return true;
}

void DumpCode(const std::vector<std::shared_ptr<CapInstr>>& code)
{
    for (const std::shared_ptr<CapInstr>& instr : code)
        instr->Dump();
}

void GetOpAddress(const cs_x86_op& op, char* segment, char* offset)
{
    strcpy(offset, "");
    
    if (op.mem.base == X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID)
        sprintf(offset, "0x%04x", (int)op.mem.disp & 0xffff);
    else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID && op.mem.disp == 0)
        sprintf(offset, "%s", cs_reg_name(_handle, op.mem.base));
    else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID)
    {
        if (op.mem.base != X86_REG_BP)
            sprintf(offset, "%s + %d", cs_reg_name(_handle, op.mem.base), (int)op.mem.disp & 0xffff);
        else
        {
            if ((op.mem.disp & 0xffff) < 60000)
                sprintf(offset, "%s + %d", cs_reg_name(_handle, op.mem.base), (int)op.mem.disp & 0xffff);
            else
                sprintf(offset, "%s - %d", cs_reg_name(_handle, op.mem.base), 0x10000-abs((int)op.mem.disp & 0xffff));
        }
    }
    else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index != X86_REG_INVALID && op.mem.disp == 0)
        sprintf(offset, "%s + %s", cs_reg_name(_handle, op.mem.base), cs_reg_name(_handle, op.mem.index));
    else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index != X86_REG_INVALID && op.mem.disp != 0)
        sprintf(offset, "%s + %s + %d", cs_reg_name(_handle, op.mem.base), cs_reg_name(_handle, op.mem.index), (int)op.mem.disp & 0xffff);
    else
        assert(0);
    
    strcpy(segment, "?");
    switch (op.mem.segment)
    {
        case X86_REG_INVALID:
            strcpy(segment, op.mem.base == X86_REG_BP ? "ss" : "ds");
            if (op.mem.base == X86_REG_BP)
                strcat(offset, "- 2");
            break;
        default:
            strcpy(segment, cs_reg_name(_handle, op.mem.segment));
    }
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
        char segment[32], offset[32], tmp[64];
        GetOpAddress(op, segment, offset);
        sprintf(tmp, "memory%s(%s, %s)", op.size == 2 ? "16" : "", segment, offset);
        return tmp;
    }

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
            return "stop(/*4*/)";
    }
}

// TODO: cleanup
//std::map<address_t, std::string, cmp_adress_t> notices;
std::map<address_t, inject_t> functionInjects;
//address_t noticeCurrentMethod;

std::string MakeCCondition(address_t noticeCurrentMethod, std::shared_ptr<CapInstr>& inst, x86_insn op)
{
    const cs_x86& x86 = inst->mDetail;
    if ((int)inst->mInject & (int)inject_t::discard)
    {
        switch (op)
        {
            case X86_INS_JE:
                inst->mInject = inject_t((int)inst->mInject | (int)inject_t::temp);
                return assign(x86, "$tmp0 == 0");
            case X86_INS_JNE:
                inst->mInject = inject_t((int)inst->mInject | (int)inject_t::temp);
                return assign(x86, "$tmp0 != 0");
            case X86_INS_JAE:
                inst->mInject = inject_t((int)inst->mInject | (int)inject_t::temp);
                return assign(x86, "$tmp0 >= $rd1");
            case X86_INS_JNS:
                inst->mInject = inject_t((int)inst->mInject | (int)inject_t::temp);
                return assign(x86, "($sig0)$tmp0 >= 0");
            default:
                assert(0);
        }
        assert(0);
    }
    switch(inst->mId)
    {
        case X86_INS_CMP:
            assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
            switch (op)
            {
                case X86_INS_JE:
                    return assign(x86, "$rd0 == $rd1");
                case X86_INS_JNE:
                    return assign(x86, "$rd0 != $rd1");
                case X86_INS_JAE:
                    return assign(x86, "$rd0 >= $rd1");
                case X86_INS_JGE:
                    return assign(x86, "($sig0)$rd0 >= ($sig1)$rd1");
                case X86_INS_JG:
                    return assign(x86, "($sig0)$rd0 > ($sig1)$rd1");
                case X86_INS_JNS:
                    return assign(x86, "($sig0)$rd0 >= 0");
                case X86_INS_JL:
                    return assign(x86, "($sig0)$rd0 < ($sig1)$rd1");
                case X86_INS_JLE:
                    return assign(x86, "($sig0)$rd0 <= ($sig1)$rd1");
                case X86_INS_JBE:
                    return assign(x86, "$rd0 <= $rd1");
                case X86_INS_JB:
                    return assign(x86, "$rd0 < $rd1");
                case X86_INS_JA:
                    return assign(x86, "$rd0 > $rd1");
                default:
                    return "stop(/*72*/)";
                    //assert(0);
            }
            break;
        case X86_INS_TEST:
            assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
            switch (op)
            {
                case X86_INS_JE:
                    return assign(x86, "!($rd0 & $rd1)");
                case X86_INS_JNE:
                    return assign(x86, "$rd0 & $rd1");
                default:
                    return "stop(/*82*/)";
                    //assert(0);
            }
            break;
        case X86_INS_ADD:
        case X86_INS_SUB:
        case X86_INS_AND:
        case X86_INS_DEC:
        case X86_INS_SHR:
        case X86_INS_SHL:
        case X86_INS_INC:
        case X86_INS_ADC:
            assert(x86.op_count >= 1);
            //assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
            switch (op)
            {
                case X86_INS_JE:
                    return assign(x86, "$rd0 == 0");
                case X86_INS_JNE:
                    return assign(x86, "$rd0 != 0");
                case X86_INS_JNS:
                    return assign(x86, "($sig0)$rd0 >= 0");
                case X86_INS_JS:
                    return assign(x86, "($sig0)$rd0 < 0");
                case X86_INS_JL:
                    if (inst->mInject != inject_t::carry)
                    {
                        inst->mInject = inject_t::carry;
                        return "stop(/*5*/)";
                    } else {
                        return "flags.carry";
                    }

//                    return assign(x86, "($sig0)$rd0 < 0"); // TODO: same as js?
                case X86_INS_JA:
                    return "stop(/*ja*/)";
                case X86_INS_JG:
                    return assign(x86, "($sig0)$rd0 > 0");
                case X86_INS_JAE:
                    if (inst->mInject != inject_t::carry)
                    {
                        inst->mInject = inject_t::carry;
                        return "stop(/*5*/)";
                    } else {
                        return "!flags.carry";
                    }
                case X86_INS_JB:
                    if (inst->mInject != inject_t::carry)
                    {
                        inst->mInject = inject_t::carry;
                        return "stop(/*6*/);";
                    } else {
                        return "flags.carry";
                    }

                default:
                    return "stop(/*71*/)";
                    //assert(0);
            }
            break;
        case X86_INS_CALL:
            switch (op)
            {
                case X86_INS_JE:
                    functionInjects.insert(std::pair<address_t, inject_t>(fromRelative(inst, x86.operands[0].imm), inject_t::returnZero));
                    break;
                case X86_INS_JNE:
                    functionInjects.insert(std::pair<address_t, inject_t>(fromRelative(inst, x86.operands[0].imm), inject_t::returnZero));
                    break;
                case X86_INS_JAE:
                    functionInjects.insert(std::pair<address_t, inject_t>(fromRelative(inst, x86.operands[0].imm), inject_t::returnCarry));
                    break;
                case X86_INS_JB:
                    functionInjects.insert(std::pair<address_t, inject_t>(fromRelative(inst, x86.operands[0].imm), inject_t::returnCarry));
                    break;
                default:
                    return "stop(/*call - strange cond*/)";
                    //assert(0);
            }
            // fall through
        case X86_INS_INT:
            switch (op)
            {
                case X86_INS_JAE:
                    return "!flags.carry";
                case X86_INS_JB:
                    return "flags.carry";
                case X86_INS_JE:
                    return "flags.zero";
                case X86_INS_JNE:
                    return "!flags.zero";
                default:
                    assert(0);
            }
            break;
        case X86_INS_OR:
        case X86_INS_XOR:
            switch (op)
            {
                case X86_INS_JE:
                    return assign(x86, "!$rd0");
                case X86_INS_JNE:
                    return assign(x86, "$rd0");
                case X86_INS_JS:
                    return assign(x86, "$rd0 & $msb0");
                case X86_INS_JNS:
                    return assign(x86, "!($rd0 & $msb0)");
                case X86_INS_JGE:
                    return assign(x86, "($sig0)$rd0 >= 0");
                default:
                    return assign(x86, "stop(/*condition!*/)");
                    //assert(0);
            }
            break;
            
        default:
            return "stop(/*70*/)";
            //assert(0);
    }
}

void FindCalls(const std::vector<std::shared_ptr<CapInstr>>& code, std::list<address_t>& toProcess)
{
    for (const std::shared_ptr<CapInstr>& instr : code)
    {
        if (instr->mId == X86_INS_CALL)
        {
            const cs_x86& x86 = instr->mDetail;

            if (x86.op_count == 1 && x86.operands[0].type == X86_OP_IMM && x86.operands[0].size == 2)
            {
                //int newOfs = x86.operands[0].imm - instr->mAddress.segment*16 + 0x10000;
                address_t newAddr = fromRelative(instr, x86.operands[0].imm);
                if (std::find(toProcess.begin(), toProcess.end(), newAddr) == toProcess.end())
                    toProcess.push_back(newAddr);
                
                //toProcess.push_back(address_t{/*instr->mAddress.segment*/ 0x1000, (int)x86.operands[0].imm});
                //toProcess.push_back(address_t{instr->mAddress.segment, (int)x86.operands[0].imm});
            } else if (x86.op_count == 1 && x86.operands[0].type == X86_OP_MEM && x86.operands[0].size == 2)
            {
                if (x86.operands[0].mem.segment == X86_REG_INVALID &&
                    x86.operands[0].mem.base == X86_REG_INVALID &&
                    x86.operands[0].mem.index == X86_REG_INVALID)
                {
                    // ds:imm?
                    //int f=9;
                    //toProcess.push_back(address_t{0x1040, (int)x86.operands[0].mem.disp});
                }

                // indirect
            }/* else if (x86.op_count == 1 && x86.operands[0].type == X86_OP_REG)
            {
                
            } else
                assert(0);*/
        }
        if (instr->mId == X86_INS_LCALL)
        {
            const cs_x86& x86 = instr->mDetail;
            if (x86.op_count == 2 && x86.operands[0].type == X86_OP_IMM && x86.operands[0].size == 2)
            {
                address_t newAddr = address_t{(int)x86.operands[0].imm, (int)x86.operands[1].imm};
                if (std::find(toProcess.begin(), toProcess.end(), newAddr) == toProcess.end())
                    toProcess.push_back(newAddr);
            }
        }

    }
}

void FindSwitches(const std::vector<std::shared_ptr<CapInstr>>& code, std::vector<switch_t>& switches)
{
//    return; // TODO:
    std::shared_ptr<CapInstr> prev;
    for (const std::shared_ptr<CapInstr>& instr : code)
    {
        if (instr->mId == X86_INS_CALL)
        {
            if (strcmp(instr->mOperands, "word ptr [si]") == 0)
                continue;
            
            const cs_x86& x86 = instr->mDetail;
            if (x86.op_count == 1 && x86.operands[0].type == X86_OP_MEM && x86.operands[0].size == 2 &&
                x86.operands[0].mem.base != X86_REG_INVALID)
            {
//                assert(prev && prev->mId == X86_INS_SHL && prev->mDetail.operands[1].type == X86_OP_IMM && prev->mDetail.operands[1].imm == 1);
                if (prev && prev->mId == X86_INS_SHL && prev->mDetail.operands[1].type == X86_OP_IMM && prev->mDetail.operands[1].imm == 1)
                {
                    if (x86.operands[0].mem.segment == X86_REG_CS)
                    {
                        assert(x86.operands[0].mem.segment == X86_REG_CS);
                        assert(x86.operands[0].mem.scale == 1);
                        assert(x86.operands[0].mem.base == X86_REG_BX);
                        switches.push_back({instr->mAddress, address_t{_cs, (int)x86.operands[0].mem.disp},
                            -1, switch_t::CallWords, x86.operands[0].mem.base});
                    } else
                        printf("// skipping indirect call\n");
                } else {
                    printf("// skipping indirect call\n");
                }
            }
        }
        prev = instr;
    }
}

bool checkDiscards(const cs_x86_op& prev, const cs_x86_op& next)
{
    if (prev.type != next.type)
        return false;
    if (prev.type == X86_OP_MEM)
    {
        return prev.mem.index == next.mem.index &&
            prev.mem.scale == next.mem.scale &&
            prev.mem.segment == next.mem.segment &&
            prev.mem.base == next.mem.base &&
            prev.mem.disp == next.mem.disp;
    }
    if (prev.type == X86_OP_REG)
    {
        return prev.reg == next.reg;
    }
    return false;
}

bool checkDiscards(const cs_x86_op& op, std::shared_ptr<CapInstr> next)
{
    if (next->mDetail.op_count == 0)
        return false;
    if (next->mDetail.op_count == 1)
        return checkDiscards(op, next->mDetail.operands[0]);
    if (next->mDetail.op_count == 2)
        return checkDiscards(op, next->mDetail.operands[0]) || checkDiscards(op, next->mDetail.operands[0]);

    assert(0);
    return false;
}

bool checkDiscards(std::shared_ptr<CapInstr> prev, std::shared_ptr<CapInstr> next)
{
    if (prev->mDetail.op_count == 0)
        return false;
    if (prev->mDetail.op_count == 1)
        return checkDiscards(prev->mDetail.operands[0], next);
    if (prev->mDetail.op_count == 2)
        return checkDiscards(prev->mDetail.operands[0], next) || checkDiscards(prev->mDetail.operands[1], next);
    assert(0);
    return false;
}

bool DumpCodeAsC(const std::vector<std::shared_ptr<CapInstr>>& code, std::vector<std::string>& text, std::vector<switch_t>& switches, std::vector<switch_t> jumps, bool lines = false)
{
    bool modified = false;
    if (segofs_in_comment)
        text.push_back(format("void sub_%x() // %04x:%04x", code[0]->mAddress.linearOffset(),
                          code[0]->mAddress.segment, code[0]->mAddress.offset));
    else
        text.push_back(format("void sub_%x()", code[0]->mAddress.linearOffset()));
                       
    text.push_back(format("{"));
    std::shared_ptr<CapInstr> lastCompare;
    bool keepLastCompare{false};
//    const auto& notice = notices.find(code[0]->mAddress);
//    if (notice != notices.end())
//    {
//        text.push_back(format("stop(); // %s", notice->second.c_str()));
//    }
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
        inject_t injectLater = inject_t::none;
        const cs_x86& x86 = instr->mDetail;
        keepLastCompare = false;
        
        if (instr->mMark)
        {
            if (instr->mComment.substr(0, 6) == "gap of")
                text.push_back(format("// %s %s %s", instr->mMnemonic, instr->mOperands, instr->mComment.c_str()));
            else
                text.push_back(format("stop(/*7*/); // %s %s %s", instr->mMnemonic, instr->mOperands, instr->mComment.c_str()));
            continue;
        }
        
        if (instr->mLabel)
        {
            lastCompare.reset();
            text.push_back(format("loc_%x:", instr->mAddress.linearOffset()));
        }
        
        if (lines)
            text.push_back(format("L(0x%x);", instr->mAddress.linearOffset()));
            
        if (instr->mInject != inject_t::none)
        {
            if ((int)instr->mInject & (int)inject_t::carry)
            {
                switch (instr->mId)
                {
                    case X86_INS_SHR:
                        text.push_back(assign(x86, "flags.carry = $rd0 & 1;"));
                        break;
                    case X86_INS_SHL:
                        text.push_back(assign(x86, "flags.carry = !!($rd0 & $msb0);"));
                        break;
                    case X86_INS_SUB:
                        text.push_back(assign(x86, "flags.carry = $rd0 < $rd1;"));
                        break;
                    case X86_INS_ADD:
                        text.push_back(assign(x86, "flags.carry = ($rd0 + $rd1) >= 0x%x;", x86.operands[0].size == 1 ? 0x100 : 0x10000));
                        break;
                    case X86_INS_ADC:
                        text.push_back("tl = flags.carry;");
                        text.push_back(assign(x86, "flags.carry = ($rd0 + $rd1 + tl) >= 0x%x;", x86.operands[0].size == 1 ? 0x100 : 0x10000));
                        break;
                    case X86_INS_INC: // TODO: CHECK!!!
                        text.push_back(assign(x86, "flags.carry = $rd0 == 0x%x;",
                            x86.operands[0].size == 1 ? 0x0ff : 0xffff));
                        break;
                    case X86_INS_DEC:
                        text.push_back(assign(x86, "flags.carry = $rd0 == 0;"));
                        break;
                    default:
                        text.push_back("stop(/*74*/);");
                        //assert(0);
                        break;
                }
            } else
            if ((int)instr->mInject & (int)inject_t::zero)
            {
                switch (instr->mId)
                {
                    case X86_INS_CMP:
                        text.push_back(assign(x86, "flags.zero = $rd0 == $rd1;"));
                        break;
                    case X86_INS_TEST:
                        text.push_back(assign(x86, "flags.zero = !($rd0 & $rd1);"));
                        break;
                    case X86_INS_AND:
                        injectLater = inject_t::zero;
//                        text.push_back(assign(x86, "flags.zero = $rd0 == 0;"));
                        break;
                    default:
                        assert(0);
                        break;
                }
            } else
            if ((int)instr->mInject & (int)inject_t::discard)
            {
                assert(0);
            } else
            if ((int)instr->mInject & (int)inject_t::temp)
            {
                assert(instr->mInject == inject_t::temp);
                text.push_back(assign(x86, "$tmp0 = $rd0;"));
            }
            else if ((int)instr->mInject & (int)inject_t::setZeroFlag)
            {
                text.push_back(assign(x86, "flags.zero = true;"));
            }
            else if ((int)instr->mInject & (int)inject_t::clearZeroFlag)
            {
                text.push_back(assign(x86, "flags.zero = false;"));
            }
            else if ((int)instr->mInject & (int)inject_t::setCarryFlag)
            {
                text.push_back(assign(x86, "flags.carry = true;"));
            }
            else if ((int)instr->mInject & (int)inject_t::clearCarryFlag)
            {
                text.push_back(assign(x86, "flags.carry = false;"));
            }
            else if ((int)instr->mInject & (int)inject_t::stop)
            {
                text.push_back(assign(x86, "stop(/*inject ret*/);"));
            }
            else
                assert(0);
        }

        switch (instr->mId)
        {
            case X86_INS_DIV:
                text.push_back(assign(x86, "div($reg0);"));
                break;
            case X86_INS_IDIV:
                assert(x86.operands[0].size == 1 || x86.operands[0].size == 2);
                text.push_back(assign(x86, "idiv($rd0);"));
                break;
            case X86_INS_IMUL:
                //assert(x86.operands[0].size == 1);
                text.push_back(assign(x86, "imul($rd0);"));
                break;
            case X86_INS_MUL:
                text.push_back(assign(x86, "mul($rd0);"));
                break;
            case X86_INS_CWDE:
                text.push_back(format("cbw();"));
                break;
            case X86_INS_NOT:
                text.push_back(assign(x86, "$wr0 = ~$rd0;"));
                break;
            case X86_INS_NEG:
                text.push_back(assign(x86, "$wr0 = -$rd0;"));
                break;
            case X86_INS_XOR:
                if (assign(x86, "$rd0") == assign(x86, "$rd1"))
                    text.push_back(assign(x86, "$rw0 = 0;"));
                else
                    text.push_back(assign(x86, "$rw0 ^= $rd1;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_PUSH:
                text.push_back(assign(x86, "push($rd0);"));
                keepLastCompare = true;
                break;
            case X86_INS_POP:
                text.push_back(assign(x86, "$wr0 = pop();"));
                keepLastCompare = true;
                break;

            case X86_INS_STOSW:
                assert(strcmp(instr->mOperands, "word ptr es:[di], ax") == 0);
                if (strcmp(instr->mMnemonic, "rep stosw") == 0)
                {
                    text.push_back(format("rep_stosw<MemAuto, DirAuto>();"));
                    break;
                }
                if (strcmp(instr->mMnemonic, "stosw") == 0)
                {
                    text.push_back(format("stosw<MemAuto, DirAuto>();"));
                    break;
                }
                assert(0);
                break;
            case X86_INS_LODSW:
                if (strcmp(instr->mMnemonic, "lodsw") == 0 &&
                    strcmp(instr->mOperands, "ax, word ptr [si]") == 0)
                {
                    text.push_back(format("lodsw<MemAuto, DirAuto>();"));
                    break;
                }
                assert(0);
                break;
            case X86_INS_STOSB:
                assert(strcmp(instr->mOperands, "byte ptr es:[di], al") == 0);
                if (strcmp(instr->mMnemonic, "rep stosb") == 0)
                {
                    text.push_back(format("rep_stosb<MemAuto, DirAuto>();"));
                    break;
                }
                if (strcmp(instr->mMnemonic, "stosb") == 0)
                {
                    text.push_back(format("stosb<MemAuto, DirAuto>();"));
                    break;
                }
                assert(0);
                break;
            case X86_INS_MOVSB:
                assert(strcmp(instr->mOperands, "byte ptr es:[di], byte ptr [si]") == 0);
                if (strcmp(instr->mMnemonic, "rep movsb") == 0)
                {
                    text.push_back(format("rep_movsb<MemAuto, MemAuto, DirAuto>();"));
                    break;
                }
                if (strcmp(instr->mMnemonic, "movsb") == 0)
                {
                    text.push_back(format("movsb<MemAuto, MemAuto, DirAuto>();"));
                    break;
                }
                assert(0);
                break;
            case X86_INS_MOVSW:
                //assert(strcmp(instr->mOperands, "word ptr es:[di], word ptr [si]") == 0);
                if (strcmp(instr->mMnemonic, "movsw") == 0)
                {
                    text.push_back(format("movsw<MemAuto, MemAuto, DirAuto>();"));
                    break;
                }
                if (strcmp(instr->mMnemonic, "rep movsw") == 0)
                {
                    text.push_back(format("rep_movsw<MemAuto, MemAuto, DirAuto>();"));
                    break;
                }
                text.push_back("PROBLEM-11h");
                //assert(0);
                break;
            case X86_INS_LODSB:
                assert(strcmp(instr->mMnemonic, "lodsb") == 0);
                if (strcmp(instr->mOperands, "al, byte ptr [si]") == 0)
                    text.push_back(format("lodsb<MemAuto, DirAuto>();"));
                else if (strcmp(instr->mOperands, "al, byte ptr es:[si]") == 0)
                    text.push_back(format("lodsb<MemAuto, DirAuto>(es);"));
                else if (strcmp(instr->mOperands, "al, byte ptr ss:[si]") == 0)
                    text.push_back(format("lodsb<MemAuto, DirAuto>(ss);"));
                else
                    assert(0);
                break;
            case X86_INS_INC:
                text.push_back(assign(x86, "$rw0++;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_DEC:
                text.push_back(assign(x86, "$rw0--;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_IN:
                text.push_back(assign(x86, "in($rd0, $rd1);"));
                break;
            case X86_INS_OUT:
                text.push_back(assign(x86, "out($rd0, $rd1);"));
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
            case X86_INS_CLC:
                text.push_back(format("flags.carry = false;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_STC:
                text.push_back(format("flags.carry = true;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_INT:
                text.push_back(assign(x86, "interrupt($immx0);"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_ADD:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                text.push_back(assign(x86, "$rw0 += $rd1;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
                /*
                 mov    ax, [si+4]
                 mov    cl, [si+6]
                                   carry = (cl+dl)>>8                <-- inject
                 add    cl, dl     cl += dl
                 adc    al, dh     al += dh + carry
                 adc    ah, ch     ah += ch + carry
                 ---------

                 mov    ax, [si+4]
                 mov    cl, [si+6]
                                   carry = (cl+dl)>>8                <-- inject
                 add    cl, dl     cl += dl
                                   tl = carry; carry=(al+dh+tl)>>8   <-- inject
                 adc    al, dh     al += dh + tl
                 adc    ah, ch     ah += ch + carry

                 */
            case X86_INS_ADC:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                if (lastCompare)
                {
                    modified |= !((int)lastCompare->mInject & (int)inject_t::carry);
                    lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::carry);
                }
                else
                    text.push_back("stop(/*8*/); // inject carry failed");
                //text.push_back(assign("%o += %o + flags.carry", x86.operands[0], x86.operands[1]);
                if (assign(x86, "$rd1") == "0x00" || assign(x86, "$rd1") == "0x0000")
                {
                    if ((int)instr->mInject & (int)inject_t::carry)
                        text.push_back(assign(x86, "$rw0 += tl;"));
                    else
                        text.push_back(assign(x86, "$rw0 += flags.carry;"));
                } else
                {
                    if ((int)instr->mInject & (int)inject_t::carry)
                        text.push_back(assign(x86, "$rw0 += $rd1 + tl;"));
                    else
                        text.push_back(assign(x86, "$rw0 += $rd1 + flags.carry;"));
                }
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
                //text.push_back(assign("%o &= %o", x86.operands[0], x86.operands[1]);
                if (assign(x86, "$rd0") != assign(x86, "$rd1"))
                    text.push_back(assign(x86, "$rw0 &= $rd1;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_OR:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                if (assign(x86, "$rd0") != assign(x86, "$rd1"))
                    text.push_back(assign(x86, "$rw0 |= $rd1;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_SUB:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                if (assign(x86, "$rd0") == assign(x86, "$rd1"))
                    text.push_back(assign(x86, "$wr0 = 0;"));
                else
                    text.push_back(assign(x86, "$rw0 -= $rd1;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_SAR:
                assert(x86.op_count == 2);
                if (x86.operands[1].type == X86_OP_IMM)
                    text.push_back(assign(x86, "$wr0 = sar($rd0, $immd1);"));
                else
                    text.push_back(assign(x86, "$wr0 = sar($rd0, $rd1);"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_SHL:
                assert(x86.op_count == 2);
                if (x86.operands[1].type == X86_OP_IMM)
                    text.push_back(assign(x86, "$rw0 <<= $immd1;"));
                else
                    text.push_back(assign(x86, "$rw0 <<= $rd1;"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_SHR:
                if (x86.op_count == 2 && x86.operands[1].type == X86_OP_IMM)
                {
                    assert(x86.op_count == 2 && x86.operands[1].type == X86_OP_IMM);
                    text.push_back(assign(x86, "$rw0 >>= $immd1;"));
                } else
                if (x86.op_count == 2 && x86.operands[1].type == X86_OP_REG)
                {
                    text.push_back(assign(x86, "$rw0 >>= $rd1;"));
                } else
                    assert(0);
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_RET:
            case X86_INS_RETF:
                if (x86.op_count == 0)
                    text.push_back(format("return;"));
                else if (x86.op_count == 1 && x86.operands[0].type == X86_OP_IMM)
                {
                    text.push_back(assign(x86, "sp += $immd0;"));
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
                if (x86.op_count == 0)
                {
                    text.push_back(format("PROBLEM-11;"));
                                   break;

                }
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
                                //assert(!i->mLabel);
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
                        if (lastCompare)
                        {
                            assert(lastCompare);
                            text.push_back(format("if (%s)", MakeCCondition(code[0]->mAddress, lastCompare, instr->mId).c_str()));
                        } else {
                            text.push_back("if (stop(/*1*/))");
                        }
                    }
                    else
                        text.push_back(format("if (%s)", MakeCFlagCondition(instr->mId).c_str()));
                    
                    //address_t target = {instr->mAddress.segment, (int)x86.operands[0].imm - instr->mAddress.segment*16 + 0x10000};

                    text.push_back(format("goto loc_%x;", fromRelative(instr, x86.operands[0].imm).linearOffset()));
                    keepLastCompare = true;
                    if (injectPrev != (lastCompare ? lastCompare->mInject : inject_t::none))
                        modified = true;
                }
                break;
            case X86_INS_JCXZ:
            {
                //address_t target = {instr->mAddress.segment, (int)x86.operands[0].imm - instr->mAddress.segment*16 + 0x10000};

                text.push_back(format("if (cx == 0)"));
                text.push_back(format("goto loc_%x;", fromRelative(instr, x86.operands[0].imm).linearOffset()));
            }
                break;
            case X86_INS_JMP:
                if (x86.op_count == 0)
                {
                    text.push_back(format("goto loc_%x;", instr->mAddress.linearOffset()));
                    break;
                }
                if (instr->Next() == instr->NextFollowing())
                {
                    // dummy jump to next instruction to breakup pipeline?
                    continue;
                }
                assert(x86.op_count == 1 && x86.operands[0].size == 2);
                if (x86.operands[0].type == X86_OP_IMM)
                {
                    //address_t target = {instr->mAddress.segment, (int)x86.operands[0].imm - instr->mAddress.segment*16 + 0x10000};

                    text.push_back(format("goto loc_%x;", fromRelative(instr, x86.operands[0].imm).linearOffset()));
                }
                else
                {
                    const auto sw = std::find_if(jumps.begin(), jumps.end(), [&](const switch_t& sw){ return sw.origin == instr->mAddress; });
                    if (sw != jumps.end() && sw->elements != -1)
                    {
                        text.push_back(format("switch (%s)", sw->GetSelector().c_str()));
                        text.push_back("{");
                        for (int i=0; i<sw->elements; i++)
                            text.push_back(sw->GetCase(i));
                        text.push_back("default:");
                        text.push_back("assert(0);");
                        text.push_back("}");
                    } else {
                        text.push_back(assign(x86, "stop(/*2*/); // (%s %s) jump Indirect $rd0",
                                       instr->mMnemonic, instr->mOperands));
                    }
                }
                //else
                //    text.push_back("stop();");
                break;
            case X86_INS_LOOP:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_IMM &&
                       x86.operands[0].size == 2);

                text.push_back(format("if (--cx)"));
            {
                //address_t target = {instr->mAddress.segment, (int)x86.operands[0].imm - instr->mAddress.segment*16 + 0x10000};

                text.push_back(format("goto loc_%x;", fromRelative(instr, x86.operands[0].imm).linearOffset()));
            }
                break;

            case X86_INS_LOOPNE:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_IMM &&
                       x86.operands[0].size == 2);

                assert(lastCompare);
                text.push_back(format("if (--cx && %s)", MakeCCondition(code[0]->mAddress, lastCompare, X86_INS_JNE).c_str()));
            {
                //address_t target = {instr->mAddress.segment, (int)x86.operands[0].imm - instr->mAddress.segment*16 + 0x10000};

                text.push_back(format("goto loc_%x;", fromRelative(instr, x86.operands[0].imm).linearOffset()));
            }
                break;

            case X86_INS_LOOPE:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_IMM &&
                       x86.operands[0].size == 2);

                assert(lastCompare);
                text.push_back(format("if (--cx && %s)", MakeCCondition(code[0]->mAddress, lastCompare, X86_INS_JE).c_str()));
            {
                //address_t target = {instr->mAddress.segment, (int)x86.operands[0].imm - instr->mAddress.segment*16 + 0x10000};

                text.push_back(format("goto loc_%x;", fromRelative(instr, x86.operands[0].imm).linearOffset()));
            }
                break;

            case X86_INS_CALL:
                if (x86.op_count == 1 && x86.operands[0].type == X86_OP_IMM && x86.operands[0].size == 2)
                {
                    //int newOfs = x86.operands[0].imm - instr->mAddress.segment*16 + 0x10000;
                    text.push_back(format("sub_%x();", /*address_t{instr->mAddress.segment, newOfs}*/fromRelative(instr, x86.operands[0].imm).linearOffset()));
                    lastCompare = instr;
                    keepLastCompare = true;
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
                        if (x86.operands[0].mem.segment == X86_REG_INVALID &&
                            x86.operands[0].mem.base == X86_REG_INVALID &&
                            x86.operands[0].mem.index == X86_REG_INVALID)
                        {
                            // ds:imm?
                        }
                        text.push_back(assign(x86, "callIndirect($rd0);"));
                    }
                } else
                    text.push_back(assign(x86, "callIndirect($rd0);"));
                    //assert(0);
                break;
            case X86_INS_LCALL:
                text.push_back(format("sub_%x();", address_t{(int)x86.operands[0].imm, (int)x86.operands[1].imm}.linearOffset()));
                break;
            case X86_INS_MOV:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                text.push_back(assign(x86, "$wr0 = $rd1;"));
                if (lastCompare && checkDiscards(x86.operands[0], lastCompare))
                    lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::discard);
                keepLastCompare = true;
                break;
            case X86_INS_LAHF:
                text.push_back("ah = flags.carry | (flags.zero << 1);");
                break;
            case X86_INS_SAHF:
                text.push_back("flags.carry = ah & 1;");
                text.push_back("flags.zero = (ah >> 1) & 1;");
                break;
            case X86_INS_RCR:
                // TODO: prev carry!
                //assert(lastCompare);
                //lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::carry);
                if (!lastCompare || (lastCompare->mId != X86_INS_RCR &&
                                     lastCompare->mId != X86_INS_STC &&
                                     lastCompare->mId != X86_INS_CLC))
                {
                    if (lastCompare->mId == X86_INS_AND)
                    {
                        // AND clears CF https://www.felixcloutier.com/x86/and
                        text.push_back(assign(x86, "flags.carry = 0;"));
                    } else if (lastCompare->mId == X86_INS_ADD || lastCompare->mId == X86_INS_ADC)
                    {
                        modified |= !((int)lastCompare->mInject & (int)inject_t::carry);
                        lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::carry);
                    }
                    else
                        text.push_back(assign(x86, "stop(/*carry1*/);")); // 8bit/16bit!
                }
                text.push_back(assign(x86, "$wr0 = rcr($rd0, $rd1);")); // 8bit/16bit!
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_RCL:
                // TODO: prev carry!
//                assert(lastCompare);
//                lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::carry);
                //assert(x86.operands[0].size == 1);
                if (lastCompare)
                {
                    modified |= !((int)lastCompare->mInject & (int)inject_t::carry);
                    lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::carry);
                } else
                    text.push_back(assign(x86, "stop(/*carry2*/);")); // 8bit/16bit!
                text.push_back(assign(x86, "$wr0 = rcl($rd0, $rd1);"));
                break;
            case X86_INS_ROR:
                text.push_back(assign(x86, "$wr0 = ror($rd0, $rd1);"));
                break;
            case X86_INS_ROL:
                text.push_back(assign(x86, "$wr0 = rol($rd0, $rd1);"));
                break;
            case X86_INS_NOP:
                keepLastCompare = true;
                break;
            case X86_INS_XCHG:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                if (x86.operands[0].size == 1)
                {
                    text.push_back(assign(x86, "tl = $rd0;"));
                    text.push_back(assign(x86, "$wr0 = $rd1;"));
                    text.push_back(assign(x86, "$wr1 = tl;"));
                } else
                if (x86.operands[0].size == 2)
                {
                    text.push_back(assign(x86, "tx = $rd0;"));
                    text.push_back(assign(x86, "$wr0 = $rd1;"));
                    text.push_back(assign(x86, "$wr1 = tx;"));
                } else
                    assert(0);
                break;
            case X86_INS_AAA:
                text.push_back("aaa();");
                break;
            case X86_INS_CMC:
                text.push_back("flags.carry = !flags.carry;");
                break;
            case X86_INS_CMPSB:
                text.push_back("cmpsb<MemData, MemData, DirAuto>();");
                break;
            case X86_INS_PUSHF:
                text.push_back("tx = flags.carry | (flags.zero << 1);");
                text.push_back("push(tx);");
                break;
            case X86_INS_POPF:
                text.push_back("tx = pop();");
                text.push_back("flags.carry = tx & 1;");
                text.push_back("flags.zero = (tx << 1) & 1;");
                break;
            case X86_INS_XLATB:
                switch (instr->mDetail.prefix[1])
                {
                    case 0:
                    case X86_PREFIX_DS:
                        text.push_back("al = memory(ds, bx+al);");
                        break;
                    case X86_PREFIX_CS:
                        text.push_back("al = memory(cs, bx+al);");
                        break;
                    case X86_PREFIX_ES:
                        text.push_back("al = memory(es, bx+al);");
                        break;
                    case X86_PREFIX_SS:
                        text.push_back("al = memory(ss, bx+al);");
                        break;
                    default:
                        assert(0);
                }
                break;
            case X86_INS_SCASB:
                if (strcmp(instr->mMnemonic, "repne scasb") == 0 &&
                    strcmp(instr->mOperands, "al, byte ptr es:[di]") == 0)
                {
                    text.push_back(format("repne_scasb<MemAuto, DirAuto>(al);"));
                    break;
                }
                if (strcmp(instr->mMnemonic, "scasb") != 0)
                {
                    text.push_back(format("stop(); // %s %s", instr->mMnemonic, instr->mOperands));
                    break;
                }
                assert(strcmp(instr->mMnemonic, "scasb") == 0);
                assert(strcmp(instr->mOperands, "al, byte ptr es:[di]") == 0);
                //assert(instr->mDetail.prefix[0]==0 && instr->mDetail.prefix[1]==0); // WTF?
                text.push_back("flags.zero = memoryAGet(es, di++) == al;");
                break;
            case X86_INS_CDQ:
                text.push_back("dx = ax & 0x8000 ? 0xffff : 0x0000;");
                break;
            case X86_INS_SBB:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                if (!lastCompare)
                    text.push_back("stop(/*81*/);");
                else
                {
                    if (lastCompare->mInject == inject_t::none)
                    {
                        lastCompare->mInject = inject_t::carry;
                        modified = true;
                    } else if (lastCompare->mInject == inject_t::carry)
                    {
                    } else
                    {
                        text.push_back("stop(/*PROBLEM-11g*/);");
                        //assert(0);
                        break;
                    }
                    assert(lastCompare->mInject == inject_t::none || lastCompare->mInject == inject_t::carry);
                    lastCompare->mInject = inject_t::carry;
                }
                if (assign(x86, "$rd1") == "0x00" || assign(x86, "$rd1") == "0x0000")
                    text.push_back(assign(x86, "$rw0 -= flags.carry;"));
                else
                    text.push_back(assign(x86, "$rw0 -= $rd1 + flags.carry;"));
                lastCompare = instr;
                keepLastCompare = true;

                //text.push_back("dx = ax & 0x8000 ? 0xffff : 0x0000;");
                break;
            case X86_INS_INT3:
                break;
            case X86_INS_LEA:
            {
                assert(x86.op_count == 2 && x86.operands[0].type == X86_OP_REG &&
                       x86.operands[1].type == X86_OP_MEM &&
                       x86.operands[1].size == 2 &&
                       x86.operands[1].reg == X86_REG_INVALID &&
                       x86.operands[1].mem.segment == X86_REG_INVALID &&
                       x86.operands[1].mem.index == X86_REG_INVALID);
                
                if (x86.operands[1].mem.base == X86_REG_SI)
                    text.push_back(assign(x86, "$wr0 = si + 0x%x; /*chk4*/", x86.operands[1].mem.disp));
                else if (x86.operands[1].mem.base == X86_REG_DI)
                    text.push_back(assign(x86, "$wr0 = di + 0x%x; /*chk4*/", x86.operands[1].mem.disp));
                else if (x86.operands[1].mem.base == X86_REG_INVALID)
                    text.push_back(assign(x86, "$wr0 = 0x%x;", x86.operands[1].mem.disp));
                else
                    assert(0);
            }
                break;
            case X86_INS_LES:
            case X86_INS_LDS:
//            case X86_INS_LCALL:
            case X86_INS_DAS:
            case X86_INS_DAA:
            case X86_INS_SCASW:
                
            case X86_INS_FLD:
            case X86_INS_FMUL:
            case X86_INS_LJMP:
            case X86_INS_FIDIV:
            case X86_INS_BOUND:
            case X86_INS_ENTER:
            case X86_INS_LEAVE:
            case X86_INS_FCOMP:
            case X86_INS_CMPSW:
            case X86_INS_FSTP:
            case X86_INS_OUTSB:
            case X86_INS_FCMOVE:
            case X86_INS_JO:
                text.push_back(format("stop(); // %s %s", instr->mMnemonic, instr->mOperands));
                break;
            default:
//                text.push_back(format("stop(); // %s %s PROBLEM-11", instr->mMnemonic, instr->mOperands));
                assert(0);
        }

        if (injectLater != inject_t::none)
        {
            if ((int)instr->mInject & (int)inject_t::zero)
            {
                switch (instr->mId)
                {
                    case X86_INS_AND:
                        text.push_back(assign(x86, "flags.zero = $rd0 == 0;"));
                        break;
                    default:
                        assert(0);
                        break;
                }
            } else
                assert(0);
        }

        if (!keepLastCompare)
            lastCompare.reset();
    }
    text.push_back(format("}"));

    for (const auto& instr : code)
        instr->mInject = inject_t((int)instr->mInject & ~(int)inject_t::discard);

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

void PrintFormatted(FILE* f, std::vector<std::string>& text)
{
    std::string prefix = "";
    std::string curline;
    std::string nexline;
    bool prevIf = false;
    for (const auto& l : text)
    {
        if (l.substr(0,2) == "L(")
        {
            curline = l + "  ";
            continue;
        }
        if (l == "}" && !curline.empty())
        {
            fprintf(f, "%s%s\n%s\n", prefix.c_str(), curline.c_str(), l.c_str());
            curline.clear();
            if (l == "}")
                prefix = prefix.substr(0, prefix.length()-2);
            continue;
        }

        if (l == "}")
            prefix = prefix.substr(0, prefix.length()-2);
        
        if (l.substr(l.length()-1, 1) == ":")
            fprintf(f, "%s\n", l.c_str());
        else
            fprintf(f, "%s%s%s%s\n", prefix.c_str(), curline.c_str(), nexline.c_str(), l.c_str());
        
        nexline.clear();
        if (l.substr(0,2) == "if" && !curline.empty())
        {
            nexline.assign(curline.size(), ' ');
        }

        curline.clear();
        
        if (l == "{")
            prefix += "  ";
        if (prevIf)
        {
            prefix = prefix.substr(0, prefix.length()-2);
            prevIf = false;
        }
        if (l.substr(0, 2) == "if")
        {
            prefix += "  ";
            prevIf = true;
        }
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
    const char* executable = nullptr;
    const char* methods = nullptr;
    const char* output = nullptr;
    bool outputFolder = false;
    const char* resume = nullptr;
    bool recursive = false;
    bool lines = false;
    bool printctx = false;
    
    for (int i=1; i<argc; i++)
    {
        const char* arg = argv[i];
        if (arg[0] == '-')
        {
            if (strcmp(arg, "-recursive") == 0)
                recursive = true;
            else if (strcmp(arg, "-asm") == 0)
                verbose_asm = true;
            else if (strcmp(arg, "-lines") == 0)
                lines = true;
            else if (strcmp(arg, "-ctx") == 0)
                printctx = true;
            else if (strcmp(arg, "-o") == 0)
            {
                output = argv[++i];
                if (output[strlen(output)-1] == '/')
                    outputFolder = true;
            }
            else if (strcmp(arg, "-resume") == 0)
                resume = argv[++i];
            else if (strcmp(arg, "-assume_ds") == 0)
                _ds = (int)strtol(argv[++i], nullptr, 16);
            else
                assert(0);

            
           //cicodis rd1.exe start,0x12345,0x12345,1000:0123 -recursive -o mojfile.cpp
            //cicodis rd1.exe start,0x12345,0x12345,1000:0123 -recursive -o mojfolder/
           //cicodis rd1.exe 1000:0232 -resume /games/rd1/cicocode/ -asm?

        } else {
            if (!executable)
                executable = arg;
            else if (!methods)
                methods = arg;
            else
                assert(0);
        }
    }
    if (!executable)
    {
        printf("No exe file specified.\n");
        return 0;
    }
    std::ifstream file(executable, std::ios::binary | std::ios::ate);
    
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size))
        throw "problem";

    MZHeader* header = (MZHeader*)&buffer[0];
    assert(header->id[0] == 'M' && header->id[1] == 'Z');
    FILE* fout = (output && !outputFolder) ? fopen(output, "w") : stdout;

    auto startWriting = [&](const std::string& id){
        if (outputFolder)
        {
            fout = fopen(format("%s%s", output, id.c_str()).c_str(), "w");
            fprintf(fout, "#include \"cicoemu.h\"\n");
            fprintf(fout, "using namespace CicoContext;\n");
            fprintf(fout, "\n");
        }
    };
    auto finishWriting = [&](){
        if (outputFolder)
        {
            fclose(fout);
            fout = stdout;
        }
    };
    
    if (printctx)
    {
        fprintf(fout, R"(#include "cicoemu.h"
using namespace CicoContext;

)");
    }
    if (methods && strstr(methods, "start"))
    {
        startWriting("start.cpp");
        if (outputFolder)
            fprintf(fout, "import(sub_%x);\n", (0x1000+header->cs)*16+header->ip);
        else
            fprintf(fout, "void sub_%x();\n", (0x1000+header->cs)*16+header->ip);

        fprintf(fout, R"(
void start()
{
  headerSize = 0x%04x;
  ds = 0x%04x;
  cs = 0x%04x;
  ss = 0x%04x;
  sp = 0x%04x;
  sub_%x();
}
)",
        header->headerSize16*16,
        header->cs+0x1000,
        header->cs+0x1000,
        header->ss+0x1000,
        header->sp,
        (0x1000+header->cs)*16+header->ip);
        finishWriting();
    }
    _cs = header->cs+0x1000;
    
    // fix relocations, we are loading the image to 1000:0000
    for (int i=0; i<header->relocations; i++)
    {
        MZRelocation* reloc = (MZRelocation*)&buffer[header->relocationOffset+i*4];
        int linearOffset = reloc->segment*16 + reloc->offset + header->headerSize16*16;
        uint16_t* addr = (uint16_t*)&buffer[linearOffset];
        *addr += 0x1000;
    }

    if (!methods)
    {
        printf("Nothing to do\n");
        return 0;
    }
    Capstone cap;
    cap.Set(buffer, 1*0x10000 - header->headerSize16*0x10);
    
    std::map<address_t, function_t, cmp_adress_t> processed;
    std::vector<address_t> failed;
    std::list<address_t> toProcess;
    std::vector<switch_t> switches;
    
    if (methods)
    {
        std::istringstream is(methods);
        std::string token;
        std::regex functionHex("^([0-9a-fA-f]+)$");
        std::regex functionSegofs("^([0-9a-fA-f]+):([0-9a-fA-f]+)$");
        std::regex functionName("^sub_([0-9a-fA-f]+)$");
        // tokenize by comma
        while (getline(is, token, ','))
        {
            std::smatch matches;
            
            if (token == "start")
                toProcess.push_back({header->cs+0x1000, header->ip});
            else if (std::regex_search(token, matches, functionHex))
            {
                std::string strAddr = matches.str(1);
                int addr = (int)strtol(strAddr.c_str(), nullptr, 16);
                int addrSeg = _cs;
                int addrOfs = addr - addrSeg*16;
                assert(addrOfs >= 0 && addrOfs < 0xffff);
                toProcess.push_back({addrSeg, addrOfs});
            } else if (std::regex_search(token, matches, functionSegofs))
            {
                std::string strSeg = matches.str(1);
                std::string strOfs = matches.str(2);
                int addrSeg = (int)strtol(strSeg.c_str(), nullptr, 16);
                int addrOfs = (int)strtol(strOfs.c_str(), nullptr, 16);
                toProcess.push_back({addrSeg, addrOfs});
            } else if (std::regex_search(token, matches, functionName))
            {
                std::string strAddr = matches.str(1);
                int addr = (int)strtol(strAddr.c_str(), nullptr, 16);
                int addrSeg = _cs;
                int addrOfs = addr - addrSeg*16;
                assert(addrOfs >= 0 && addrOfs < 0xffff);
                toProcess.push_back({addrSeg, addrOfs});
            } else
                assert(0);
        }
    }

    auto TraceFunctions = [&]()
    {
        while (!toProcess.empty())
        {
            address_t method = toProcess.front();
            toProcess.pop_front();

            if (processed.find(method) != processed.end())
                continue;
            if (std::find(failed.begin(), failed.end(), method) != failed.end())
                continue;

            std::vector<switch_t> jumps;
            std::vector<std::shared_ptr<CapInstr>> code;
            //printf("// extracting %04x:%04x, converted %d, to convert %d, failed %d\n", method.segment, method.offset, processed.size(), toProcess.size(), failed.size());
            if (!ExtractMethod(cap, method, code, jumps, inject_t::none))
            {
                //assert(0);
                printf("Conversion of %04x:%04x failed!\n", method.segment, method.offset);
                failed.push_back(method);
                continue;
            }
            int size = code[code.size()-1]->NextFollowing().linearOffset() - code[0]->mAddress.linearOffset();
            processed.insert(std::pair<address_t, function_t>(method, function_t{method, size}));

            if (recursive)
            {
                FindCalls(code, toProcess);
                FindSwitches(code, switches);
            }
        }
    };
    
    auto CheckOverlap = [&](const address_t& begin, int size)
    {
        return std::find_if(processed.begin(), processed.end(), [&](const auto& t){
            const function_t& func = t.second;
            bool matching = !((begin >= (func.begin + func.length)) || ((begin + size) <= func.begin));
            return matching;
        }) != processed.end();
    };
    
    TraceFunctions();
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
            TraceFunctions();
        }
        assert(sw.elements != -1);
    }
        
    if (!outputFolder)
        for (const auto& decl : processed)
            fprintf(fout, "void sub_%x();\n", decl.second.begin.linearOffset());
     
    // collect notices, TODO: check
    for (const auto& decl : processed)
    {
        std::vector<switch_t> jumps;
        std::vector<std::string> text;
        std::vector<std::shared_ptr<CapInstr>> code;
        if (!ExtractMethod(cap, decl.first, code, jumps, inject_t::none))
            assert(0);

        DumpCodeAsC(code, text, switches, jumps);
    }

    // dump
    for (const auto& decl : processed)
    {
        std::vector<switch_t> jumps;
        std::vector<std::shared_ptr<CapInstr>> code;
        auto injectptr = functionInjects.find(decl.first);
        inject_t inject = injectptr != functionInjects.end() ? injectptr->second : inject_t::none;

        if (!ExtractMethod(cap, decl.first, code, jumps, inject))
            assert(0);

        std::vector<std::string> text;
        if (DumpCodeAsC(code, text, switches, jumps, lines)) // TODO: collect all notices
        {
            text.clear();
            DumpCodeAsC(code, text, switches, jumps, lines);
        }
        OptimizeCode(text);
        startWriting(format("sub_%x.cpp", code[0]->mAddress.linearOffset()));
        if (outputFolder)
        {
            std::vector<switch_t> localswitches;
            std::list<address_t> imports;
            FindCalls(code, imports);
            FindSwitches(code, localswitches);

            for (const switch_t& lsw : localswitches)
            {
                const auto sw = std::find_if(switches.begin(), switches.end(), [&](const switch_t& sw){
                    return sw.origin == lsw.origin;
                });
                if (sw != switches.end() && sw->elements != -1)
                {
                    for (int i=0; i<sw->elements; i++)
                    {
                        address_t target = sw->GetTarget(i);
                        if (std::find(imports.begin(), imports.end(), target) == imports.end())
                            imports.push_back(target);
                    }
                }
            }

            if (!imports.empty())
            {
                for (const auto& decl : imports)
                {
                    if (decl.linearOffset() != code[0]->mAddress.linearOffset())
                        fprintf(fout, "import(sub_%x);\n", decl.linearOffset());
                }
                fprintf(fout, "\n");
            }
        }
        PrintFormatted(fout, text);
        finishWriting();
    }

    fclose(fout);
//    for (const auto& decl : notices)
//        printf("// Notice: sub_%x(): %s\n", decl.first.segment*0x10+decl.first.offset, decl.second.c_str());

    return 0;
}
