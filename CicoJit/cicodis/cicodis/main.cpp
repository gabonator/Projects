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
#include <sstream>
#include <string>
#include <regex>

bool verbose_asm = false;
bool segofs_in_comment = false;
csh _handle;
int _cs;
int _ds = 0;
int _loadBase = 0x1000;
bool _simpleStack = false;
bool _stackGuard = false;
bool _dumpReloc = false;
enum {Unknown, Near, Far} _currentCall = Unknown;
bool gNeedToRerun = false;
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
                    switch (x86.operands[0].size)
                    {
                        case 1:
                            sprintf(replace, "memoryAGet(%s, %s)", segment, offset);
                            break;
                        case 2:
                            sprintf(replace, "memoryAGet16(%s, %s)", segment, offset);
                            break;
                        case 4: // carefull!
                            sprintf(replace, "memoryAGet16(%s, %s + 2)*16 + memoryAGet16(%s, %s)", segment, offset, segment, offset);
                            break;
                        default:
                            assert(0);
                    }
                } else
                    strcpy(replace, ToCString(x86.operands[0]).c_str());
            }
        }
        if (strcmp(tok, "rns0") == 0)
        {
            assert(x86.op_count >= 1);
            if (getset && x86.operands[0].type == X86_OP_MEM)
            {
                assert(x86.operands[0].size == 4);
                char segment[32], offset[32];
                GetOpAddress(x86.operands[0], segment, offset);
                sprintf(replace, "memoryAGet16(%s, %s + 2)", segment, offset);
            } else
                assert(0);
        }

        if (strcmp(tok, "rn1") == 0)
        {
            assert(x86.op_count >= 2);
            if (getset && x86.operands[1].type == X86_OP_MEM)
            {
                char segment[32], offset[32];
                GetOpAddress(x86.operands[1], segment, offset);
                sprintf(replace, "memoryAGet%s(%s, %s + 2)",
                        x86.operands[0].size == 2 ? "16" : "", segment, offset);
            } else
                assert(0);

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
    static address_t fromString(const std::string& s)
    {
        std::regex functionSegofs("^([0-9a-fA-f]+):([0-9a-fA-f]+)$");
        std::smatch matches;
        if (std::regex_search(s, matches, functionSegofs))
        {
            std::string strSeg = matches.str(1);
            std::string strOfs = matches.str(2);
            int addrSeg = (int)strtol(strSeg.c_str(), nullptr, 16);
            int addrOfs = (int)strtol(strOfs.c_str(), nullptr, 16);
            return {addrSeg, addrOfs};
        }
        assert(0);
        return {0, 0};
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
    modifyStack = 0x10000,
    overrideStack = 0x20000,
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
                if (x86->op_count == 1 &&
                    x86->operands[0].size == 2)
                {
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
                } else {
                    int f = 9;
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
            case X86_INS_IRET:
            case X86_INS_LJMP:
                mNextInstr = address_t{};
                break;
            default:
                break;
        }
    }
    
    bool IsInstruction()
    {
        return mMnemonic[0] != 0;
    }
    
    bool IsIndirectJump()
    {
        return IsInstruction() && mId == X86_INS_JMP && mDetail.operands[0].type == X86_OP_MEM;
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
        printf("%04x:%04x\t%s\t%s\n",
               mAddress.segment, mAddress.offset,
               //mDetail.opcode[0], mDetail.opcode[1], mDetail.opcode[2], mDetail.opcode[3],
               mMnemonic, mOperands);
    }
    address_t fromRelative(uint64_t offset);
};

address_t fromRelative(int segment, uint64_t offset)
{
    return address_t{segment, (int)offset};
}

address_t fromRelative(const std::shared_ptr<CapInstr>& instr, uint64_t offset)
{
    return fromRelative(instr->mAddress.segment, offset);
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
    int64_t mBase;
    
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
    
    void Set(const std::vector<char>& buffer, int64_t base)
    {
        //assert(base > 0); // TODO!
        mpBuffer = (const uint8_t*)buffer.data();
        mSize = buffer.size();
        mBase = base;
    }
    
    const uint8_t* GetBufferAt(address_t addr)
    {
        int64_t address = addr.segment*16 + addr.offset;
        assert(address - mBase > 0x0 && address - mBase+1 <= mSize);
        return mpBuffer + address - mBase;
    }
    
    std::shared_ptr<CapInstr> Disasm(address_t addr)
    {
        uint64_t address = addr.segment*16*0 + addr.offset;
        size_t codeSize = 32;
        const uint8_t* buf = GetBufferAt(addr);
        cs_disasm_iter(mHandle, &buf, &codeSize, &address, mInsn);
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

// TODO: cleanup
//std::map<address_t, std::string, cmp_adress_t> notices;
std::map<address_t, inject_t> functionInjects;
//address_t noticeCurrentMethod;

bool all(std::vector<std::shared_ptr<CapInstr>>& arr, std::function<bool(std::shared_ptr<CapInstr>&)> test)
{
    bool aux = true;
    for (auto& i : arr)
        aux &= test(i);
    return aux;
}

bool ExtractMethod(Capstone& cap, address_t address, std::vector<std::shared_ptr<CapInstr>>& code, std::vector<switch_t>& indirectJumps, inject_t injectReturn, const std::vector<std::pair<address_t, address_t>>& extraLabels)
{
    std::list<address_t> trace;
    trace.push_back(address);
    std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> instructions;
//    injectReturn = (inject_t)((int)inject_t::returnCarry | (int)inject_t::returnZero);
    for (const std::pair<address_t, address_t>& pair : extraLabels)
        if (pair.first.linearOffset() == address.linearOffset())
            trace.push_back(pair.second);

    while (!trace.empty())
    {
        address_t pc = trace.front();
        trace.pop_front();
        assert(pc.offset >= 0 && pc.offset < 0xffff);
        if (trace.size() == 0) // skip indirect jumps
        {
            // start processing indirect jumps when everything is finished
            //assert(indirectJumps.size() <= 1);
            for (int i=0; i<indirectJumps.size(); i++)
            {
                switch_t& sw = indirectJumps[i];
                if (instructions.find(sw.origin) == instructions.end())
                    continue;
                
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
        
        if (instr->IsIndirectJump())
        {
            for (int i=0; i<indirectJumps.size(); i++)
            {
                switch_t& sw = indirectJumps[i];
                if (sw.origin == instr->mAddress && sw.elements > 0)
                    for (int j=0; j<sw.elements; j++)
                        trace.push_back(sw.GetTarget(j));
            }
        }
        
        if (0 && instr->IsIndirectJump())
        {
            assert(instr->mDetail.op_count == 1);
            const auto& op = instr->mDetail.operands[0];
            if (op.mem.base == X86_REG_INVALID &&
                op.mem.segment == X86_REG_INVALID &&
                op.mem.index == X86_REG_INVALID &&
                op.mem.scale == 1 &&
                op.mem.disp != 0)
            {
                
            }
            else if (op.mem.segment == X86_REG_INVALID)
            {
                assert(op.mem.segment == X86_REG_INVALID); // ds?
                assert(op.mem.base == X86_REG_DI || op.mem.base == X86_REG_SI);
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
                if (!(pc.offset >= 0 && pc.offset < 0xffff))
                {
                    printf("// Skipping jump to %04x:%04x (%x) in %04x:%04x on %04x:%04x\n",
                           pc.segment, pc.offset, pc.linearOffset(), address.segment, address.offset,
                           instr->mAddress.segment, instr->mAddress.offset);
                }
                    else
                    {
                    assert(pc.offset >= 0 && pc.offset < 0xffff);
                    trace.push_back(pc);
                    }
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
        
        if (iter->second->IsIndirectJump())
        {
            for (int i=0; i<indirectJumps.size(); i++)
            {
                switch_t& sw = indirectJumps[i];
                if (sw.origin == iter->second->mAddress && sw.elements > 0)
                    for (int j=0; j<sw.elements; j++)
                    {
                        auto tinst = instructions.find(sw.GetTarget(j));
                        assert(tinst != instructions.end());
                        tinst->second->mLabel = true;
                    }
            }
        }
        

    }
    
    for (const std::pair<address_t, address_t>& pair : extraLabels)
        if (pair.first.linearOffset() == address.linearOffset())
            if (instructions.find(pair.second) != instructions.end())
                instructions.find(pair.second)->second->mLabel = true;

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
            if (gapsize == 1 && cap.GetBufferAt(nextAddr)[0] == 0x90)
            {
                // nop
                std::shared_ptr<CapInstr> gap = std::shared_ptr<CapInstr>(new CapInstr(nextAddr, gapsize, ""));
                instructions.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(nextAddr, gap));
            } else {
                std::shared_ptr<CapInstr> gap = std::shared_ptr<CapInstr>(new CapInstr(nextAddr, gapsize, format("gap of %d bytes", gapsize)));
                instructions.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(nextAddr, gap));
            }
        }

        nextAddr = instr->NextFollowing();
    }
    
    if (instructions.begin()->first != address)
        code.push_back(std::shared_ptr<CapInstr>(new CapInstr(X86_INS_JMP, address)));
        
    nextAddr = address_t{};
    std::shared_ptr<CapInstr> prev1, prev2;
    std::shared_ptr<CapInstr> prev11, prev22;
    if (!instructions.empty() && instructions.begin()->second->mId == X86_INS_POP)
        instructions.begin()->second->mInject = inject_t::overrideStack;
        
    for( auto iter = instructions.begin(); iter != instructions.end(); iter++ )
    {
        address_t addr = iter->first;
        std::shared_ptr<CapInstr> instr = iter->second;
        if (nextAddr.segment != -1)
        {
            if (addr != nextAddr)
            {
                printf("Failed instruction flow at %04x:%04x '%s %s' -> %04x:%04x, gap %d bytes\n", addr.segment, addr.offset, instr->mMnemonic, instr->mOperands, nextAddr.segment, nextAddr.offset,
                       nextAddr.linearOffset()-addr.linearOffset());
                return false;
            }
            
            assert(addr == nextAddr);
        }
            
        nextAddr = instr->NextFollowing();
        if (instr->mId == X86_INS_RET)
        {
            if ((prev11 && prev11->mId == X86_INS_POP) || (prev22 && prev22->mId == X86_INS_PUSH))
            {
                // push es
                // pop ds
            }
            else if ((prev11 && prev11->mId == X86_INS_PUSH) && (prev22 && prev22->mId == X86_INS_PUSH))
            {
                // override stack
                instr->mInject = inject_t::overrideStack;
            }
            else if ((prev11 && prev11->mId == X86_INS_PUSH) || (prev22 && prev22->mId == X86_INS_PUSH))
            {
                if (((prev11 && prev11->mId != X86_INS_CALL) && (prev22 && prev22->mId != X86_INS_CALL)))
                    instr->mInject = inject_t::modifyStack;
            }
        }
        if (instr->mId == X86_INS_RETF)
        {
            if ((prev11 && prev11->mId == X86_INS_POP) || (prev22 && prev22->mId == X86_INS_PUSH))
            {
                // push es
                // pop ds
            }
            else if ((prev11 && prev11->mId == X86_INS_PUSH) && (prev22 && prev22->mId == X86_INS_PUSH))
            {
                // override stack
                instr->mInject = inject_t::overrideStack;
            }
            else if ((prev11 && prev11->mId == X86_INS_PUSH) || (prev22 && prev22->mId == X86_INS_PUSH))
            {
                if (((prev11 && prev11->mId != X86_INS_CALL) && (prev22 && prev22->mId != X86_INS_CALL)))
                    instr->mInject = inject_t::stop;
            }
        }
        if (injectReturn != inject_t::none && (instr->mId == X86_INS_RET || instr->mId == X86_INS_RETF))
        {
            if (instr->mLabel)
            {
                std::vector<std::shared_ptr<CapInstr>> targets;
                std::shared_ptr<CapInstr> prev3;
                for( auto i = instructions.begin(); i != instructions.end(); i++ )
                {
                    if (i->second->NextBranch() == instr->mAddress)
                    {
                        targets.push_back(prev3);
                    }
                    prev3 = i->second;
                }
                targets.push_back(prev1);
                if (all(targets, [](auto& instr){ return instr->mId == X86_INS_CMP; } ))
                {
                    inject_t injectVal = inject_t::none;
                    if ((int)injectReturn & (int)inject_t::returnCarry)
                        injectVal = (inject_t)((int)injectVal | (int)inject_t::carry);
                    if ((int)injectReturn & (int)inject_t::returnZero)
                        injectVal = (inject_t)((int)injectVal | (int)inject_t::zero);
                    assert((int)injectVal);
                    all(targets, [injectVal](auto& instr){ instr->mInject = inject_t((int)instr->mInject | (int)injectVal); return true; } );
                } else
                {
                    instr->mInject = inject_t::stop;
                    printf("// INJECT: Error: cannot inject flag in sub_%x() because of being label!\n",
                           address.linearOffset());
                }
            }
            else if (injectReturn == inject_t::returnZero)
            {
                if (prev1->mId == X86_INS_CALL)
                {
                    assert(prev1->mDetail.op_count == 1);
                    assert(prev1->mDetail.operands[0].type == X86_OP_IMM);
                    
                    address_t targetAddr = fromRelative(instr, prev1->mDetail.operands[0].imm);
                    
                    //addInject(targetAddr, inject_t::zero);
                    auto injectptr = functionInjects.find(targetAddr);
                    if (injectptr != functionInjects.end())
                    {
                        if (!((int)injectptr->second & (int)injectReturn))
                        {
                            gNeedToRerun = true;
                            injectptr->second = (inject_t)((int)injectptr->second | (int)injectReturn);
                        }
                    }
                    else
                    {
                        gNeedToRerun = true;
                        functionInjects.insert(std::pair<address_t, inject_t>(targetAddr, injectReturn));
                    }

                    /*
                    auto injectptr = functionInjects.find(targetAddr);
                    int inject = injectptr != functionInjects.end() ? (int)injectptr->second : (int)inject_t::none;
                    inject |= (int)inject_t::zero;
                    functionInjects.insert(std::pair<address_t, inject_t>(targetAddr, (inject_t)inject));
                     */
                }
                else if (prev1->mId == X86_INS_CMP || prev1->mId == X86_INS_AND)
                {
                    prev1->mInject = inject_t((int)prev1->mInject | (int)inject_t::zero);
                }
                else
                if (SetsZeroFlag(prev1))
                {
                    assert(instr->mInject == inject_t::none);
                    instr->mInject = inject_t::setZeroFlag;
                }
                else if (ClearsZeroFlag(prev2, prev1))
                {
                    assert(instr->mInject == inject_t::none);
                    instr->mInject = inject_t::clearZeroFlag;
                } else
                {
                    instr->mInject = inject_t::stop;
                    printf("// INJECT: Error: cannot inject zero flag in sub_%x()!\n",
                           address.linearOffset());
                }
            } else
            if (injectReturn == inject_t::returnCarry)
            {
                // TOTO: check if there is function call before, mark function, run again!
                if (SetsCarryFlag(prev1))
                {
                    assert(instr->mInject == inject_t::none);
                }
                else if (ClearsCarryFlag(prev1))
                {
                    assert(instr->mInject == inject_t::none);
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
        prev22 = prev11;
        prev11 = instr;
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
            
            if (_simpleStack && op.mem.base == X86_REG_BP)
            {
                switch (_currentCall)
                {
                    case Near:
                        strcat(offset, " - 2");
                        break;
                    case Far:
                        strcat(offset, " - 4");
                        break;
                    default:
                        strcat(offset, " - stop()");
                        break;
                }
            }
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

std::string MakeCCondition(address_t noticeCurrentMethod, std::shared_ptr<CapInstr>& inst, x86_insn op)
{
    address_t targetAddr;
    const cs_x86& x86 = inst->mDetail;
    if ((int)inst->mInject & (int)inject_t::discard)
    {
        switch (op)
        {
            case X86_INS_JE:
                inst->mInject = inject_t((int)inst->mInject | (int)inject_t::temp);
                return assign(x86, "$tmp0 == 0");
            case X86_INS_JNE:
                //inst->mInject = inject_t((int)inst->mInject | (int)inject_t::temp);
                //return assign(x86, "$tmp0 != 0");
                inst->mInject = inject_t((int)inst->mInject | (int)inject_t::zero);
                return assign(x86, "!flags.zero");
            case X86_INS_JAE:
                inst->mInject = inject_t((int)inst->mInject | (int)inject_t::temp);
                return assign(x86, "$tmp0 >= $rd1");
            case X86_INS_JNS:
                inst->mInject = inject_t((int)inst->mInject | (int)inject_t::temp);
                return assign(x86, "($sig0)$tmp0 >= 0");
            case X86_INS_JB:
                return "stop(/*jb*/)";
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
        case X86_INS_RCL:
        case X86_INS_RCR:
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
        case X86_INS_LCALL:
        case X86_INS_CALL:
            {
                if (inst->mId == X86_INS_CALL)
                {
                    assert(x86.op_count == 1);
                    assert(x86.operands[0].type == X86_OP_IMM);
                } else {
                    if (x86.op_count != 2)
                    {
                        return "stop(/*lcall*/)";
                    }
                    assert(x86.op_count == 2);
                    assert(x86.operands[0].type == X86_OP_IMM);
                    assert(x86.operands[1].type == X86_OP_IMM);
                }
                
                address_t targetAddr = inst->mId == X86_INS_CALL ? fromRelative(inst, x86.operands[0].imm) : address_t((int)x86.operands[0].imm, (int)x86.operands[1].imm);
                auto injectptr = functionInjects.find(targetAddr);
                int inject = injectptr != functionInjects.end() ? (int)injectptr->second : (int)inject_t::none;
                // TODO: should not insert, but join!!!
                switch (op)
                {
                    case X86_INS_JE:
                        inject |= (int)inject_t::returnZero;
                        break;
                    case X86_INS_JNE:
                        inject |= (int)inject_t::returnZero;
                        break;
                    case X86_INS_JAE:
                        inject |= (int)inject_t::returnCarry;
                        break;
                    case X86_INS_JB:
                        inject |= (int)inject_t::returnCarry;
                        break;
                    case X86_INS_JA:
                        inject |= (int)inject_t::returnCarry | (int)inject_t::returnZero;
                        break;
                    case X86_INS_JBE:
                        inject |= (int)inject_t::returnCarry | (int)inject_t::returnZero;
                        break;
                    default:
                        return "stop(/*call - strange cond*/)";
                        //assert(0);
                }
                if (injectptr != functionInjects.end())
                    injectptr->second = (inject_t)inject;
                else
                    functionInjects.insert(std::pair<address_t, inject_t>(targetAddr, (inject_t)inject));
                assert(functionInjects.find(targetAddr)->second == (inject_t)inject);
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
                case X86_INS_JA:
                    return "!flags.zero && !flags.carry";
                case X86_INS_JBE:
                    return "flags.zero || flags.carry";
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
                case X86_INS_JLE:
                    return assign(x86, "($sig0)$rd0 <= 0");
                case X86_INS_JL:
                    return assign(x86, "($sig0)$rd0 < 0");
                case X86_INS_JB:
                    return assign(x86, "false"); // not sure!
                    
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
            if (x86.op_count == 2 &&
                x86.operands[0].type == X86_OP_IMM && x86.operands[0].size == 2 &&
                x86.operands[1].type == X86_OP_IMM && x86.operands[1].size == 2)
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
//                        assert(x86.operands[0].mem.base == X86_REG_BX);
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
    {
        if (next.type == X86_OP_MEM && prev.type == X86_OP_REG)
        {
            x86_reg reg1 = next.mem.segment == X86_REG_INVALID ? X86_REG_DS : next.mem.segment;
            x86_reg reg2 = next.mem.base;
            x86_reg reg3 = next.mem.index;
            if (prev.reg == reg1 || prev.reg == reg2 || prev.reg == reg3)
                return true;
        }
        return false;
    }
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

std::string replaceStr(const std::string& s, const std::string& from, const std::string to)
{
    std::string str(s);
    if(from.empty())
        return str;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
    return str;
}

bool DumpCodeAsC(const std::vector<std::shared_ptr<CapInstr>>& code, std::vector<std::string>& text, std::vector<switch_t>& switches, std::vector<switch_t> jumps, bool lines = false)
{
    if (code.back()->mId == X86_INS_RET)
        _currentCall = Near;
    else
        if (code.back()->mId == X86_INS_RETF)
            _currentCall = Far;
    else
    {
        _currentCall = Unknown;
        int retn = 0, retf = 0;
        for (const auto& r : code)
        {
            if (r->mId == X86_INS_RET)
                retn++;
            if (r->mId == X86_INS_RETF)
                retf++;
        }
        if (retn > 0 && retf == 0)
            _currentCall = Near;
        if (retn == 0 && retf > 0)
            _currentCall = Far;
    }
    
    bool usesStack = false;
    for (const auto& ins : code)
    {
        if (!ins->IsInstruction())
            continue;
        if (ins->mId == X86_INS_PUSH || ins->mId == X86_INS_POP)
            continue;
        if (ins->mDetail.op_count >= 1)
        {
            std::string arg0 = assign(ins->mDetail, "$rd0");
            if (arg0.find("sp") != std::string::npos || arg0.find("bp") != std::string::npos)
            {
                usesStack = true;
                break;
            }
        }
        if (ins->mDetail.op_count >= 2)
        {
            std::string arg1 = assign(ins->mDetail, "$rd1");
            if (arg1.find("sp") != std::string::npos || arg1.find("bp") != std::string::npos)
            {
                usesStack = true;
                break;
            }
        }
    }
    
    auto functionHeader = [&]()
    {
        int ofs = 0;
        
        if (code.size() > 1 && code.back()->mId == X86_INS_RET &&
            code.back()->mDetail.op_count == 1 &&
            code.back()->mDetail.operands[0].type == X86_OP_IMM)
        {
            ofs = code.back()->mDetail.operands[0].imm;
//            char temp[32];
//            sprintf(temp, "%d", code.back()->mDetail.operands[0].imm);
//            ext = temp;
//            //ext = assign(code.back()->mDetail, "$immd0");
        }
        switch (_currentCall)
        {
            case Near:
                if (_stackGuard)
                    text.push_back(format("CStackGuard sg(%d, %s);", ofs, usesStack ? "true" : "false"));
                if (usesStack)
                    text.push_back("push(0x7777);");
                break;
            case Far:
                if (_stackGuard)
                    text.push_back(format("CStackGuardFar sg(%d, %s);", ofs, usesStack ? "true" : "false"));
                //text.push_back("push(0x8888);");
                if (usesStack)
                    text.push_back("push(0x7777);");
                break;
            default:
                text.push_back("stop(/*unk call conv*/);");
        }
    };
    auto functionFooter = [&]()
    {
        switch (_currentCall)
        {
            case Near:
                if (usesStack)
                    text.push_back("assert(pop() == 0x7777);");
                break;
            case Far:
                if (usesStack)
                    text.push_back("assert(pop() == 0x7777);");
                text.push_back("cs = pop();");
                break;
            default:
                text.push_back("stop(/*unk call conv*/);");
        }
    };

    bool modified = false;
    if (segofs_in_comment)
        text.push_back(format("void sub_%x() // %04x:%04x", code[0]->mAddress.linearOffset(),
                          code[0]->mAddress.segment, code[0]->mAddress.offset));
    else
        text.push_back(format("void sub_%x()", code[0]->mAddress.linearOffset()));
                       
    text.push_back(format("{"));
    std::shared_ptr<CapInstr> lastCompare;
    bool keepLastCompare{false};
    
    functionHeader();

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
            if (segofs_in_comment)
                text.push_back(format("loc_%x: // %04x:%04x",
                    instr->mAddress.linearOffset(), instr->mAddress.segment, instr->mAddress.offset));
            else
                text.push_back(format("loc_%x:", instr->mAddress.linearOffset()));

        }
        
        if (lines)
            text.push_back(format("L(0x%x);", instr->mAddress.linearOffset()));
            
        char current[128];
        sprintf(current, "%s %s", instr->mMnemonic, instr->mOperands);
        
        if (instr->mInject != inject_t::none)
        {
            bool any = false;
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
                    case X86_INS_RCL:
                    case X86_INS_RCR:
                        // updates carry flag internally
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
                    case X86_INS_CMP:
                        text.push_back(assign(x86, "flags.carry = $rd0 < $rd1;"));
                        break;
                    default:
                        text.push_back("stop(/*74*/);");
                        //assert(0);
                        break;
                }
                any = true;
            }
            if ((int)instr->mInject & (int)inject_t::zero)
            {
                switch (instr->mId)
                {
                    case X86_INS_CMP:
                        text.push_back(assign(x86, "flags.zero = $rd0 == $rd1;"));
                        break;
                    case X86_INS_DEC:
                        injectLater = inject_t::zero;
                        //text.push_back(assign(x86, "flags.zero = $rd0 == $rd1;"));
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
                any = true;
            }
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
            else if ((int)instr->mInject & (int)inject_t::modifyStack)
            {
                text.push_back(assign(x86, "callIndirect(pop());"));
            }
            else if ((int)instr->mInject & (int)inject_t::overrideStack)
            {
                text.push_back(assign(x86, "stop(/*override stack*/);"));
            }
            else
            if (any)
            {
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
                if (strcmp(instr->mMnemonic, "repne stosw") == 0)
                {
                    text.push_back(format("repne_stosw<MemAuto, DirAuto>();"));
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
                if (strcmp(instr->mMnemonic, "repne stosb") == 0)
                {
                    text.push_back(format("repne_stosb<MemAuto, DirAuto>();"));
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
                keepLastCompare = true;
                if (strcmp(instr->mMnemonic, "rep movsb") == 0)
                {
                    text.push_back(format("rep_movsb<MemAuto, MemAuto, DirAuto>();"));
                    break;
                }
                if (strcmp(instr->mMnemonic, "repne movsb") == 0)
                {
                    text.push_back(format("repne_movsb<MemAuto, MemAuto, DirAuto>();"));
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
                keepLastCompare = true;
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
                if (strcmp(instr->mMnemonic, "repne movsw") == 0)
                {
                    text.push_back(format("repne_movsw<MemAuto, MemAuto, DirAuto>();"));
                    break;
                }
//                text.push_back("PROBLEM-11h");
                assert(0);
                break;
            case X86_INS_LODSB:
                if (strcmp(instr->mMnemonic, "rep lodsb") == 0 &&
                    strcmp(instr->mOperands, "al, byte ptr es:[si]") == 0)
                {
                    text.push_back(format("rep_lodsb<MemAuto, DirAuto>();"));
                    break;
                }
                assert(strcmp(instr->mMnemonic, "lodsb") == 0);
                if (strcmp(instr->mOperands, "al, byte ptr [si]") == 0)
                    text.push_back(format("lodsb<MemAuto, DirAuto>();"));
                else if (strcmp(instr->mOperands, "al, byte ptr es:[si]") == 0)
                    text.push_back(format("lodsb_es<MemAuto, DirAuto>();"));
                else if (strcmp(instr->mOperands, "al, byte ptr ss:[si]") == 0)
                    text.push_back(format("lodsb_ss<MemAuto, DirAuto>();"));
                else if (strcmp(instr->mOperands, "al, byte ptr cs:[si]") == 0)
                    text.push_back(format("lodsb_cs<MemAuto, DirAuto>();"));
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
                // TODO: sometimes before return to modify zero flag
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
                {
                    functionFooter();
                    text.push_back(format("return;"));
                }
                else if (x86.op_count == 1 && x86.operands[0].type == X86_OP_IMM)
                {
                    functionFooter();
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
                    // special injected jump at beginning of function!
//                    text.push_back(format("stop(/* %s %s */);", instr->mMnemonic, instr->mOperands));
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
//                        text.push_back(assign(x86, "stop(/*2*/); // (%s %s) jump Indirect $rd0",
//                                       instr->mMnemonic, instr->mOperands));
                        text.push_back(assign(x86, "stop(/*2*/); // %04x:%04x %s %s - jump Indirect $rd0",
                                       instr->mAddress.segment, instr->mAddress.offset, instr->mMnemonic, instr->mOperands));
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

                if (!lastCompare)
                {
                    text.push_back("stop(/*e2*/);");
                }else {
                assert(lastCompare);
                text.push_back(format("if (--cx && %s)", MakeCCondition(code[0]->mAddress, lastCompare, X86_INS_JE).c_str()));
                }
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
                        text.push_back(assign(x86, "callIndirect(cs*16+$rd0);"));
                    }
                } else
                    text.push_back(assign(x86, "callIndirect(cs*16+$rd0);"));
                    //assert(0);
                break;
            case X86_INS_LCALL:
//                text.push_back("push(0);"); // TODO: use long call instead, function might not be using stack at all
                if (x86.op_count == 2 && x86.operands[0].type == X86_OP_IMM && x86.operands[1].type == X86_OP_IMM)
                {
//                    text.push_back(format("sub_%x_%x();", x86.operands[0].imm, x86.operands[1].imm));
                    //text.push_back(format("sub_%x(); // %04x:%04x", address_t{(int)x86.operands[0].imm, (int)x86.operands[1].imm}.linearOffset(), x86.operands[0].imm, x86.operands[1].imm));

                    text.push_back(assign(x86, "push(cs);"));
                    text.push_back(assign(x86, "cs = 0x%04x;", x86.operands[0].imm));
                    text.push_back(format("sub_%x();", address_t{(int)x86.operands[0].imm, (int)x86.operands[1].imm}.linearOffset()));
                    text.push_back(assign(x86, "assert(cs == 0x%04x);", code.front()->mAddress.segment));
                    lastCompare = instr;
                    keepLastCompare = true;
                }
                else if (x86.op_count == 1 && x86.operands[0].type == X86_OP_MEM)
                {
                    text.push_back(assign(x86, "push(cs);"));
                    text.push_back(assign(x86, "cs = $rns0;"));
                    text.push_back(assign(x86, "callIndirect($rd0);")); // not a full addr
                    text.push_back(assign(x86, "assert(cs == 0x%04x);", code.front()->mAddress.segment));
                }
                else
                    text.push_back(format("stop(); // %s %s", instr->mMnemonic, instr->mOperands));
//                text.push_back("pop();");
                break;
            case X86_INS_MOV:
                assert(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size);
                text.push_back(assign(x86, "$wr0 = $rd1;"));
//                if (assign(x86, "$wr0 = $rd1;") == "ds = bp;" && lastCompare && lastCompare->mId == X86_INS_DEC)
//                {
//                    std::string tmp1 = assign(lastCompare->mDetail, "$rd0"); // memoryAGet(ds, 0x4e16)
//                    std::string tmp0 = assign(x86, "$wr0"); // ds
//                    /*
//                     memoryASet(ds, 0x4e16, memoryAGet(ds, 0x4e16) - 1); // ONO ZACINA!
//                     ds = bp; // WTF!!! CONDITION ON ABOVE INSTRUCTION SEGMENT CHANGE!!!! CICO TODO
//                     if (memoryAGet(ds, 0x4e16) != 0)
//
//                     */
//                    printf("Gabo!\n");
//                }
                if (lastCompare) // TODO: Not only mov can discard lastCompare!
                {
                    bool discards1 = checkDiscards(x86.operands[0], lastCompare);
                    bool discards2 = false;
//                    if (lastCompare->mId != X86_INS_CALL && lastCompare->mId != X86_INS_LCALL)
                        discards2 = replaceStr(assign(lastCompare->mDetail, "$rd0"), "Get16", "Get").find(replaceStr(assign(x86, "$rd0"), "Get16", "Get")) != std::string::npos;
                    if (discards1 != discards2)
                    {
                        printf("Discard check failed in sub_%04x: cur=%04x:%04x last=%04x:%04x> %s modifies %s\n", code[0]->mAddress.linearOffset(),
                               instr->mAddress.segment, instr->mAddress.offset,
                               lastCompare->mAddress.segment, lastCompare->mAddress.offset,
                               assign(lastCompare->mDetail, "$rd0").c_str(), assign(x86, "$rd0").c_str());
                        assert(discards1 == discards2);
                    }
                    if (discards1)
                        lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::discard);
                }
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
                    if (lastCompare && lastCompare->mId == X86_INS_AND)
                    {
                        // AND clears CF https://www.felixcloutier.com/x86/and
                        text.push_back(assign(x86, "flags.carry = 0;"));
                    } else if (lastCompare && (lastCompare->mId == X86_INS_ADD || lastCompare->mId == X86_INS_ADC || lastCompare->mId == X86_INS_SHR || lastCompare->mId == X86_INS_SHL))
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
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_ROR:
                text.push_back(assign(x86, "$wr0 = ror($rd0, $rd1);"));
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_ROL:
                text.push_back(assign(x86, "$wr0 = rol($rd0, $rd1);"));
                lastCompare = instr;
                keepLastCompare = true;
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
                if (strcmp(instr->mMnemonic, "cmpsb") == 0 &&
                    strcmp(instr->mOperands, "byte ptr [si], byte ptr es:[di]") == 0)
                {
                    text.push_back("cmpsb<MemData, MemData, DirAuto>();");
                    break;
                }
                if (strcmp(instr->mMnemonic, "repe cmpsb") == 0 &&
                    strcmp(instr->mOperands, "byte ptr [si], byte ptr es:[di]") == 0)
                {
                    text.push_back("repe_cmpsb<MemData, MemData, DirAuto>();");
                    break;
                }
                assert(0);
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
                        text.push_back("al = memoryAGet(ds, bx+al);");
                        break;
                    case X86_PREFIX_CS:
                        text.push_back("al = memoryAGet(cs, bx+al);");
                        break;
                    case X86_PREFIX_ES:
                        text.push_back("al = memoryAGet(es, bx+al);");
                        break;
                    case X86_PREFIX_SS:
                        text.push_back("al = memoryAGet(ss, bx+al);");
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
                    text.push_back(assign(x86, "$wr0 = si + 0x%x;", x86.operands[1].mem.disp));
                else if (x86.operands[1].mem.base == X86_REG_DI)
                    text.push_back(assign(x86, "$wr0 = di + 0x%x;", x86.operands[1].mem.disp));
                else if (x86.operands[1].mem.base == X86_REG_INVALID)
                    text.push_back(assign(x86, "$wr0 = 0x%x;", x86.operands[1].mem.disp));
                else if (x86.operands[1].mem.base == X86_REG_BP && x86.operands[1].mem.disp < 0)
                    text.push_back(assign(x86, "$wr0 = bp - 0x%x;", -x86.operands[1].mem.disp));
                else if (x86.operands[1].mem.base == X86_REG_BP && x86.operands[1].mem.disp > 0)
                    text.push_back(assign(x86, "$wr0 = bp + 0x%x;", x86.operands[1].mem.disp));
                else if (x86.operands[1].mem.base == X86_REG_BX && x86.operands[1].mem.disp > 0)
                    text.push_back(assign(x86, "$wr0 = bx + 0x%x;", x86.operands[1].mem.disp));
                else if (x86.operands[1].mem.base == X86_REG_BX && x86.operands[1].mem.disp < 0)
                    text.push_back(assign(x86, "$wr0 = bx - 0x%x;", x86.operands[1].mem.disp));
                else
                    assert(0);
            }
                break;
            case X86_INS_LES:
                if (assign(x86, "$rd1").find(assign(x86, "$wr0")) != std::string::npos)
                {
                    std::string shared = assign(x86, "$rd0");
                    text.push_back(assign(x86, "tx = $rd0;"));
                    text.push_back(assign(x86, "$wr0 = %s;", replaceStr(assign(x86, "$rd1"), shared, "tx").c_str()));
                    text.push_back(assign(x86, "es = %s;", replaceStr(assign(x86, "$rn1"), shared, "tx").c_str()));
                } else {
                    text.push_back(assign(x86, "$wr0 = $rd1;"));
                    text.push_back(assign(x86, "es = $rn1;"));
                }
                break;
            case X86_INS_LDS:
                if (assign(x86, "$rd1").find(assign(x86, "$wr0")) != std::string::npos)
                {
                    std::string shared = assign(x86, "$rd0");
                    text.push_back(assign(x86, "tx = $rd0;"));
                    text.push_back(assign(x86, "$wr0 = %s;", replaceStr(assign(x86, "$rd1"), shared, "tx").c_str()));
                    text.push_back(assign(x86, "ds = %s;", replaceStr(assign(x86, "$rn1"), shared, "tx").c_str()));
                } else {
                    text.push_back(assign(x86, "$wr0 = $rd1;"));
                    text.push_back(assign(x86, "ds = $rn1;"));
                }
                break;
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
            case X86_INS_IRET:
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
                    case X86_INS_DEC:
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
            std::string labelName = label.substr(0, label.find(':'));
            ReplaceAll(text, "goto " + labelName + ";", "return;");
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
            curline = l + "    ";
            continue;
        }
        if (l == "}" && !curline.empty())
        {
            fprintf(f, "%s%s\n%s\n", prefix.c_str(), curline.c_str(), l.c_str());
            curline.clear();
            if (l == "}")
                prefix = prefix.substr(0, prefix.length()-4);
            continue;
        }

        if (l == "}")
            prefix = prefix.substr(0, prefix.length()-4);
        
        if (l.substr(l.length()-1, 1) == ":" || l.find(": // ") != std::string::npos)
        {
            if (l == "default:")
                fprintf(f, "%s%s%s%s\n", prefix.c_str(), curline.c_str(), nexline.c_str(), l.c_str());
            else
                fprintf(f, "%s\n", l.c_str());
        }
        else
            fprintf(f, "%s%s%s%s\n", prefix.c_str(), curline.c_str(), nexline.c_str(), l.c_str());
        
        nexline.clear();
        if (l.substr(0,2) == "if" && !curline.empty())
        {
            nexline.assign(curline.size(), ' ');
        }

        curline.clear();
        
        if (l == "{")
            prefix += "    ";
        if (prevIf)
        {
            prefix = prefix.substr(0, prefix.length()-4);
            prevIf = false;
        }
        if (l.substr(0, 2) == "if")
        {
            prefix += "    ";
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
    int outputLimit = 0;
    const char* resume = nullptr;
    bool recursive = false;
    bool lines = false;
    bool printctx = false;
    const char* extraLabelsStr = nullptr;
    std::vector<switch_t> jumpTables;

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
            else if (strcmp(arg, "-segofscomment") == 0)
                segofs_in_comment = true;
            else if (strcmp(arg, "-ctx") == 0)
                printctx = true;
            else if (strcmp(arg, "-reloc") == 0)
                _dumpReloc = true;
            else if (strcmp(arg, "-stackguard") == 0)
                _stackGuard = true;
            else if (strcmp(arg, "-load") == 0)
                _loadBase = (int)strtol(argv[++i], nullptr, 16);
            else if (strcmp(arg, "-labels") == 0)
                extraLabelsStr = argv[++i];
            else if (strcmp(arg, "-o") == 0)
            {
                output = argv[++i];
                if (output[strlen(output)-1] == '/')
                    outputFolder = true;
            }
            else if (strcmp(arg, "-olimit") == 0)
                outputLimit = (int)strtol(argv[++i], nullptr, 10);
            else if (strcmp(arg, "-resume") == 0)
                resume = argv[++i];
            else if (strcmp(arg, "-assume_ds") == 0)
                _ds = (int)strtol(argv[++i], nullptr, 16);
            else if (strcmp(arg, "-jumptable") == 0)
            {
                // -jumptable 01ed:46dc 01ed:4725 4 jumpwords bx
                address_t indirectJumpAddr = address_t::fromString(argv[++i]);
                address_t jumpTableBegin = address_t::fromString(argv[++i]);
                int jumpTableEntries = (int)strtol(argv[++i], nullptr, 10);
                const char* jumpTableEntryType = argv[++i];
                assert(strcmp(jumpTableEntryType, "jumpwords") == 0);
                const char* jumpSelector = argv[++i];
                assert(strcmp(jumpSelector, "bx") == 0);
                
                jumpTables.push_back({indirectJumpAddr, jumpTableBegin, jumpTableEntries, switch_t::JumpWords, X86_REG_BX, nullptr});
            } else
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
    std::string strExecutable(executable);
    const size_t lastSlash = strExecutable.find_last_of("\\/");
    assert(std::string::npos != lastSlash);
    std::string execName = strExecutable.substr(lastSlash+1);
    std::string execPath = strExecutable.substr(0, lastSlash);

    std::ifstream file(strExecutable, std::ios::binary | std::ios::ate);
    
    std::streamsize size = file.tellg();
    int execSize = (int)size;
    assert(size >= 1024 && size < 1024*1024);
    file.seekg(0, std::ios::beg);

    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size))
        throw "problem";

    MZHeader* header = (MZHeader*)&buffer[0];
    assert(header->id[0] == 'M' && header->id[1] == 'Z');
    FILE* fout = stdout;
    if (outputLimit)
        fout = fopen(format("%s%s", output, ".h").c_str(), "w");
    else if (output && !outputFolder)
        fout = fopen(output, "w");

    bool fileCounterOpened = false;
    int methodCounter = 0;
    int fileCounter = 0;
    
    auto startWriting = [&](const std::string& id){
        if (outputLimit && id != "start.cpp")
        {
            if (!fileCounterOpened)
            {
                fileCounterOpened = true;
                fout = fopen(format("%s%d.cpp", output, fileCounter++).c_str(), "w");
                fprintf(fout, "#include \"%s.h\"\n\n", output);
            }
        }
        if (outputFolder)
        {
            fout = fopen(format("%s%s", output, id.c_str()).c_str(), "w");
            fprintf(fout, "#include \"cicoemu.h\"\n");
            fprintf(fout, "using namespace CicoContext;\n");
            fprintf(fout, "\n");
        }
    };
    auto finishWriting = [&](){
        if (outputLimit)
        {
            if (methodCounter++ >= outputLimit)
            {
                methodCounter = 0;
                fclose(fout);
                fout = stdout;
                fileCounterOpened = false;
            }
        }
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
    if (_stackGuard)
    {
        fprintf(fout, R"(class CStackGuard
{
    uint16_t minit;
    bool uses;
public:
    CStackGuard(int ofs, bool use):minit(sp+ofs),uses(use) { if (!uses) push(0xabcd);}
    ~CStackGuard() {
        if (!uses)
            assert(pop() == 0xabcd);
        assert(minit == sp);
    }
};

class CStackGuardFar
{
    uint16_t minit;
public:
    CStackGuardFar(int ofs, bool use):minit(sp+ofs) {}
    ~CStackGuardFar() { assert(minit == sp-2); }
};

)");
    }
    if (methods && strstr(methods, "start"))
    {
        startWriting("start.cpp");
        if (outputFolder)
            fprintf(fout, "import(sub_%x);\n", (_loadBase+header->cs)*16+header->ip);
        else
            fprintf(fout, "void sub_%x();\n", (_loadBase+header->cs)*16+header->ip);

        fprintf(fout, "void fixReloc(uint16_t seg);\n");

        fprintf(fout, R"(
void start()
{
    headerSize = 0x%04x;
    cs = 0x%04x;
    ds = 0x%04x;
    es = 0x%04x;
    ss = 0x%04x;
    sp = 0x%04x;
    load("%s", "%s", %d);
    %ssub_%x();
}
)",
        header->headerSize16*16,
        header->cs+_loadBase,
        header->cs+_loadBase - 0x10,
        header->cs+_loadBase - 0x10,
        header->ss+_loadBase,
        header->sp,
        execPath.c_str(), execName.c_str(), execSize,
        _dumpReloc ? "fixReloc(cs);\n    " : "",
        (_loadBase+header->cs)*16+header->ip);
        finishWriting();
    }
    _cs = header->cs+_loadBase;
    
    // map extra labels 
    std::vector<std::pair<address_t, address_t>> extraLabels;
    if (extraLabelsStr)
    {
        std::istringstream is(extraLabelsStr);
        std::regex functionSegofs("^([0-9a-fA-f]+):([0-9a-fA-f]+)$");
        std::regex functionName("^sub_([0-9a-fA-f]+)$");
        std::regex labelName("^loc_([0-9a-fA-f]+)$");

        std::string token;
        address_t parent;
        while (getline(is, token, ','))
        {
            std::smatch matches;
            if (std::regex_search(token, matches, functionName))
            {
                std::string strAddr = matches.str(1);
                int addr = (int)strtol(strAddr.c_str(), nullptr, 16);
                int addrSeg = _cs;
                int addrOfs = addr - addrSeg*16;
                assert(addrOfs >= 0 && addrOfs < 0xffff);
                parent = {addrSeg, addrOfs};
            } else
            if (std::regex_search(token, matches, labelName))
            {
                std::string strAddr = matches.str(1);
                int addr = (int)strtol(strAddr.c_str(), nullptr, 16);
                int addrSeg = _cs;
                int addrOfs = addr - addrSeg*16;
                assert(addrOfs >= 0 && addrOfs < 0xffff);
                extraLabels.push_back({parent, {addrSeg, addrOfs}});
            } else
            if (std::regex_search(token, matches, functionSegofs))
            {
                std::string strSeg = matches.str(1);
                std::string strOfs = matches.str(2);
                int addrSeg = (int)strtol(strSeg.c_str(), nullptr, 16);
                int addrOfs = (int)strtol(strOfs.c_str(), nullptr, 16);
                extraLabels.push_back({parent, {addrSeg, addrOfs}});
            } else
                assert(0);
        }
    }
    // fix relocations, we are loading the image to 1000:0000
    if (_dumpReloc)
    {
        printf("void fixReloc(uint16_t seg)\n{\n");
    }
    for (int i=0; i<header->relocations; i++)
    {
        MZRelocation* reloc = (MZRelocation*)&buffer[header->relocationOffset+i*4];
        int linearOffset = reloc->segment*16 + reloc->offset + header->headerSize16*16;
        uint16_t* addr = (uint16_t*)&buffer[linearOffset];
        if (_dumpReloc)
        {
            printf("    memory16(0x%04x + seg, 0x%04x) += seg; // %04x -> %04x\n",
                   reloc->segment, reloc->offset, *addr, *addr + _loadBase);
        }
        *addr += _loadBase;
    }
    if (_dumpReloc)
    {
        printf("}\n");
    }

    if (!methods)
    {
        printf("Nothing to do\n");
        return 0;
    }
    Capstone cap;
    cap.Set(buffer, 16*_loadBase - header->headerSize16*0x10);
    
    std::map<address_t, function_t, cmp_adress_t> processed;
    std::vector<address_t> failed;
    std::list<address_t> toProcess;
    std::vector<switch_t> switches;
    std::vector<switch_t> jumps;
    for (switch_t& s : jumpTables)
    {
        s.baseptr = cap.GetBufferAt(s.begin);
        jumps.push_back(s);
    }
    
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
                toProcess.push_back({header->cs+_loadBase, header->ip});
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

//            std::vector<switch_t> jumps;
            std::vector<std::shared_ptr<CapInstr>> code;
            //printf("// extracting %04x:%04x, converted %d, to convert %d, failed %d\n", method.segment, method.offset, processed.size(), toProcess.size(), failed.size());
            if (!ExtractMethod(cap, method, code, jumps, inject_t::none, extraLabels))
            {
                //assert(0);
                printf("Conversion of %04x:%04x failed!\n", method.segment, method.offset);
                
                if (verbose_asm)
                {
                    printf("\nAssembly listing of faield %04x:%04x sub_%x()\n", method.segment, method.offset,
                           method.segment*16+ method.offset);
                    for (const auto& instr : code)
                        instr->Dump();
                }

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
    
    gNeedToRerun = true;
    while (gNeedToRerun)
    {
        gNeedToRerun = false;
        TraceFunctions();
    }
    for (auto& sw : switches)
    {
        sw.baseptr = cap.GetBufferAt(sw.GetBaseAddress());
        
        for (int i=0; i<2000; i++)
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
//        std::vector<switch_t> jumps;
        std::vector<std::string> text;
        std::vector<std::shared_ptr<CapInstr>> code;
        if (!ExtractMethod(cap, decl.first, code, jumps, inject_t::none, extraLabels))
            assert(0);

        if (verbose_asm)
        {
            printf("\nAssembly listing of %04x:%04x sub_%x()\n", decl.first.segment, decl.first.offset,
                   decl.first.segment*16+decl.first.offset);
            for (const auto& instr : code)
                instr->Dump();
        }

        DumpCodeAsC(code, text, switches, jumps);
    }

    gNeedToRerun = true;
    while (gNeedToRerun)
    {
        gNeedToRerun = false;
        for (const auto& decl : processed)
        {
//            std::vector<switch_t> jumps;
            std::vector<std::shared_ptr<CapInstr>> code;
            auto injectptr = functionInjects.find(decl.first);
            inject_t inject = injectptr != functionInjects.end() ? injectptr->second : inject_t::none;

            if (!ExtractMethod(cap, decl.first, code, jumps, inject, extraLabels))
                assert(0);
        }
    }


    // dump
    for (const auto& decl : processed)
    {
//        std::vector<switch_t> jumps;
        std::vector<std::shared_ptr<CapInstr>> code;
        auto injectptr = functionInjects.find(decl.first);
        inject_t inject = injectptr != functionInjects.end() ? injectptr->second : inject_t::none;

        if (!ExtractMethod(cap, decl.first, code, jumps, inject, extraLabels))
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

// 2461 -> 5261
