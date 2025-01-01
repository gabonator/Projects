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
#include <assert.h>
#include <set>

bool verbose_asm = false;
bool segofs_in_comment = false;
csh _handle;
int _cs;
int _ds = 0;
int _loadBase = 0x1000;
bool _trace = false;
bool _simpleStack = false;
bool _stackGuard = false;
bool _dumpReloc = false;
bool _dumpTree = false;
bool _coverage = false;
bool _bit32 = false;
enum {Unknown, Near, Far} _currentCall = Unknown;
bool gNeedToRerun = false;
int _linearToFileOffset = 0;
//int _terminator = -1;
std::set<int> _terminators;
std::vector<char> disasmBytes;
int disasmAddressSeg = -1;
int disasmAddressOfs = -1;
int negativeoffset = 65536;
//int _entryFunction;
//static void print_insn_detail(csh ud, cs_mode mode, cs_insn *ins);

std::string format(const char* fmt, ...)
{
    char buf[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, 256, fmt, args);
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
                
                std::string rvalue_formatted = vassign(x86, rvalue, args);
                
                char segment[32], offset[32], tmp[128];
                GetOpAddress(op, segment, offset);
                snprintf(tmp, 128, "memoryASet%s(%s, %s, %s);",
                        x86.operands[0].size == 2 ? "16" : "", segment, offset, rvalue_formatted.c_str());
                return tmp;
            } else {
                char tmp[128];
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
                            snprintf(replace, 64, "memoryAGet(%s, %s)", segment, offset);
                            break;
                        case 2:
                            snprintf(replace, 64, "memoryAGet16(%s, %s)", segment, offset);
                            break;
                        case 4: // carefull!
                            snprintf(replace, 64, "memoryAGet16(%s, %s + 2), memoryAGet16(%s, %s)", segment, offset, segment, offset);
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
                snprintf(replace, 64, "memoryAGet16(%s, %s + 2)", segment, offset);
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
                snprintf(replace, 64, "memoryAGet%s(%s, %s + 2)",
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
                if(x86.op_count >= 2)
                {
                    if (getset && x86.operands[1].type == X86_OP_MEM)
                    {
                        char segment[32], offset[32];
                        GetOpAddress(x86.operands[1], segment, offset);
                        snprintf(replace, 64, "memoryAGet%s(%s, %s)",
                                 x86.operands[0].size == 2 ? "16" : "", segment, offset);
                    } else
                        strcpy(replace, ToCString(x86.operands[1]).c_str());
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
            strcpy(replace, ToCString(x86.operands[2]).c_str());
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
    vsnprintf(buf, 256, fmt, args);
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
        assert(o>=0);
    }
    address_t(int s, int o) : segment{s}, offset{o}
    {
        assert(o>=0);
    }
    bool isValid() const
    {
        return segment != -1;
    }
    int linearOffset() const
    {
        return segment*0x10+offset;
    }
    int fileOffset() const 
    {
        return linearOffset() - _linearToFileOffset;
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
    clearCarryFlag = 0x80,
    dynamic = 0x40000,
    tempPost = 0x80000,
    callsSync = 0x100000
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
//    int elements{0};
    std::vector<int> elements;
    enum switch_e {
        None,
        CallWords,
        CallDwords,
        JumpWords,
        JumpFix,
        Call,
        CallWordsByOfs
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
        return type == CallDwords ? 4 : 2;
    }
    address_t GetTarget(int i) const //(const uint8_t* data)
    {
        if (type == CallDwords)
        {
            uint16_t* parts = (uint16_t*)baseptr;
            return address_t{parts[i*2+1], parts[i*2]};
        }
        if (type == JumpFix || type == Call)
            return GetBaseAddress();
        uint16_t* parts = (uint16_t*)baseptr;
        return address_t{origin.segment, parts[i]};
    }
    std::string GetCase(int i) const
    {
        switch (type)
        {
            case CallWords:
                return format("case %d: sub_%x(); break;", i*2, GetTarget(i).linearOffset());
            case CallDwords:
                return format("case %d: cs = 0x%04x; sub_%x(); break;", i*4, GetTarget(i).segment, GetTarget(i).linearOffset());
            case JumpWords:
                return format("case %d: goto loc_%x;", i*2, /*GetTarget(i).linearOffset()-0x10000+_cs*0x10*/ GetTarget(i).linearOffset());
            case JumpFix:
                return format("case 0x%04x: goto loc_%x;", GetTarget(i).offset, GetTarget(i).linearOffset());
            case Call:
            case CallWordsByOfs:
                return format("case 0x%04x: sub_%x(); break;", GetTarget(i).offset, GetTarget(i).linearOffset());
            default:
                assert(0);
                return "stop(/*3*/);";
        }
    }
    std::string GetSelector() const
    {
        if (selector == X86_REG_INVALID)
            return "";
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

class CapInstr : public std::enable_shared_from_this<CapInstr>
{
public: // remove!
    x86_insn mId;
    cs_x86 mDetail;
    int mSize;
    char mMnemonic[64];
    char mOperands[64];
    uint8_t mBytes[24];
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
        //assert(mSize < 24);
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
        assert(mSize < 24);
        //mAddress = p->address;
        strcpy(mMnemonic, p->mnemonic);
        strcpy(mOperands, p->op_str);
        memset(mBytes, 0, sizeof(mBytes));
        memcpy(mBytes, p->bytes, mSize);
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
                    x86->operands[0].size == 4)
                {
                    mNextInstr = {};
                    break;
                }
                if (x86->op_count == 1 &&
                    x86->operands[0].size == 2)
                {
                    assert(x86->op_count == 1 &&
                           x86->operands[0].size == 2);
                    if (x86->operands[0].type == X86_OP_IMM)
                    {
                        mNextInstr = fromRelative(x86->operands[0].imm);
                        snprintf(mOperands, 64, "loc_%x", mNextInstr.segment*0x10+mNextInstr.offset);
                    } else {
                        mNextInstr = {};
                    }
                } else
                {
                    assert(0);
                }
                break;
                
            case X86_INS_LOOP:
            case X86_INS_LOOPE:
            case X86_INS_LOOPNE:
            case X86_INS_JAE ... X86_INS_JL:
            case X86_INS_JNE ... X86_INS_JS:
                assert(x86->op_count == 1 &&
                       x86->operands[0].type == X86_OP_IMM &&
                       (x86->operands[0].size == 2 || x86->operands[0].size == 4));
                mBranchInstr = fromRelative( x86->operands[0].imm);//{addr.segment, (int)x86->operands[0].imm - addr.segment*16 + 0x10000};
                snprintf(mOperands, 64, "loc_%x", mBranchInstr.linearOffset());
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
        return IsInstruction() && mId == X86_INS_JMP && (mDetail.operands[0].type == X86_OP_MEM || mDetail.operands[0].type == X86_OP_REG);
    }
    bool IsIndirectCall()
    {
        if (!IsInstruction())
            return false;
        
        if (mId == X86_INS_CALL)
        {
            assert(mDetail.op_count == 1);
            if (mDetail.operands[0].type != X86_OP_IMM)
                return true;
        }
        if (mId == X86_INS_LCALL)
        {
            if (mDetail.op_count == 1)
                return true;
//            assert(mDetail.op_count == 2);
            return mDetail.operands[0].type != X86_OP_IMM || mDetail.operands[1].type == X86_OP_IMM;
        }
        return false;
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
    address_t CallTarget()
    {
        assert(mId == X86_INS_CALL);
        return fromRelative(mDetail.operands[0].imm);
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
            printf("                            loc_%x:\n", mAddress.segment*0x10+mAddress.offset);
        char strBytes[128] = "";
        char *pBytes = strBytes;
        
        if (mMnemonic[0])
            for (int i=0; i<mSize; i++)
                pBytes += snprintf(pBytes, strBytes+sizeof(strBytes)-pBytes, "%02x ", mBytes[i]);
        
        printf("%04x:%04x  %-16s %s %s\n",
               mAddress.segment, mAddress.offset,
               strBytes,
               //mDetail.opcode[0], mDetail.opcode[1], mDetail.opcode[2], mDetail.opcode[3],
               mMnemonic, mOperands);
    }
    address_t fromRelative(uint64_t offset);
    bool InRange(const address_t& pp) const
    {
        assert(mMnemonic[0]);
        int p = pp.linearOffset();
        int a = mAddress.linearOffset();
        int b = a + mSize;
        return p >= a && p < b;
    }
    bool AddInject(inject_t inject)
    {
        if ((int)mInject & (int)inject)
            return false;
        mInject = (inject_t)((int)mInject | (int)inject);
        return true;
    }
};

address_t fromRelative(int segment, uint64_t offset)
{
    return address_t{segment, (int)offset};
}

address_t fromRelative(const std::shared_ptr<CapInstr>& instr, uint64_t offset)
{
    // TODO: capstone 5 with gcc returns 0xffff.... on rick2
    return fromRelative(instr->mAddress.segment, offset & 0xffff);
}

address_t CapInstr::fromRelative(uint64_t offset)
{
    // TODO: capstone 5 with gcc returns 0xffff.... on rick2
    return ::fromRelative(mAddress.segment, offset & 0xffff);
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
        cs_err err = cs_open(CS_ARCH_X86, _bit32 ? CS_MODE_32 : CS_MODE_16, &mHandle);
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
    
    bool InRange(address_t addr, int size = 0)
    {
        return addr.linearOffset() - mBase >= 0 && addr.linearOffset() - mBase + size < mSize;
    }
    
    const uint8_t* GetBufferAt(address_t addr)
    {
        int64_t address = addr.segment*16 + addr.offset;
        assert(address - mBase >= 0x0 && address - mBase+1 <= mSize);
        return mpBuffer + address - mBase;
    }
    
    std::shared_ptr<CapInstr> Disasm(address_t addr)
    {
        uint64_t address = addr.segment*16*0 + addr.offset;
        size_t codeSize = 32;
        const uint8_t* buf = GetBufferAt(addr);
        if (buf[0] == 0 && buf[1] == 0 && buf[2] == 0)
        {
            return std::shared_ptr<CapInstr>();
//            assert(0);
        }
            
        cs_disasm_iter(mHandle, &buf, &codeSize, &address, mInsn);
        return std::shared_ptr<CapInstr>(new CapInstr(addr, mInsn));
    }
};

bool ModifiesZeroFlag(const std::shared_ptr<CapInstr>& instr)
{
    return instr->mId == X86_INS_TEST || instr->mId == X86_INS_AND || instr->mId == X86_INS_CMP || instr->mId == X86_INS_OR;
}

bool FiltersZeroFlag(const std::shared_ptr<CapInstr>& instr)
{
    return instr->mId == X86_INS_JE || instr->mId == X86_INS_JNE;
}

bool IsIndirectJump(const std::vector<switch_t>& indirectJumps, const std::shared_ptr<CapInstr>& instr)
{
    for (int i=0; i<indirectJumps.size(); i++)
    {
        const switch_t& sw = indirectJumps[i];
        if (sw.origin == instr->mAddress)
            return true;
    }
    return false;
}

bool SetsZeroFlag(const std::shared_ptr<CapInstr>& instr)
{
    if ((instr->mId == X86_INS_XOR || instr->mId == X86_INS_SUB) &&
        instr->mDetail.op_count == 2 &&
        instr->mDetail.operands[0].type == X86_OP_REG &&
        instr->mDetail.operands[1].type == X86_OP_REG &&
        instr->mDetail.operands[0].reg == instr->mDetail.operands[1].reg)
        return true;
    if (strcmp(instr->mMnemonic, "jne") == 0)
        return true;
    return false;
}

bool ClearsZeroFlag(const std::shared_ptr<CapInstr>& instr1, const std::shared_ptr<CapInstr>& instr2)
{
    if (!instr1)
        return false;
    if (!instr2)
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
    if (strcmp(instr2->mMnemonic, "or") == 0 &&
        strcmp(instr2->mOperands, "sp, sp") == 0)
        return true;
    if (strcmp(instr1->mMnemonic, "xor") == 0 &&
        strcmp(instr1->mOperands, "ax, ax") == 0 &&
        strcmp(instr2->mMnemonic, "dec") == 0 &&
        strcmp(instr2->mOperands, "ax") == 0)
        return true;
    if (strcmp(instr1->mMnemonic, "mov") == 0 &&
        strcmp(instr1->mOperands, "ax, 0xffff") == 0 &&
        strcmp(instr2->mMnemonic, "test") == 0 &&
        strcmp(instr2->mOperands, "ax, ax") == 0)
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

bool ModifiesCarryFlag(const std::shared_ptr<CapInstr>& instr)
{
//    if ((instr->mId == X86_INS_XOR || instr->mId == X86_INS_SUB) &&
//        instr->mDetail.op_count == 2 &&
//        instr->mDetail.operands[0].type == X86_OP_REG &&
//        instr->mDetail.operands[1].type == X86_OP_REG &&
//        instr->mDetail.operands[0].reg == instr->mDetail.operands[1].reg)
//        return true;
    return instr->mId == X86_INS_CMP || instr->mId == X86_INS_DEC || instr->mId == X86_INS_SUB || instr->mId == X86_INS_INC || instr->mId == X86_INS_ADD || instr->mId == X86_INS_XOR || instr->mId == X86_INS_CMC;
}

bool FiltersCarryFlag(const std::shared_ptr<CapInstr>& instr)
{
    return instr->mId == X86_INS_JE || instr->mId == X86_INS_JNE || instr->mId == X86_INS_JB || instr->mId == X86_INS_JAE | instr->mId == X86_INS_JA;
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

class CTracer {
    const std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t>& mInstructions;
    
public:
    CTracer(const std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t>& instructions) :
        mInstructions(instructions)
    {
    }
    
    std::vector<std::shared_ptr<CapInstr>> allPathsTo(const std::shared_ptr<CapInstr>& instr)
    {
        std::vector<std::shared_ptr<CapInstr>> targets;
        std::shared_ptr<CapInstr> prev3;
        for( auto i = mInstructions.begin(); i != mInstructions.end(); i++ )
        {
            // instruction before branch
            if (i->second->NextBranch() == instr->mAddress) // cond
                targets.push_back(prev3);
            if (i->second->NextFollowing() != i->second->Next() && i->second->Next() == instr->mAddress) // jmp
                targets.push_back(prev3);
            if (i->second->NextFollowing() == instr->mAddress && i->second->mId != X86_INS_JMP) // right before
                targets.push_back(i->second);
            prev3 = i->second;
        }
        return targets;
    }
    std::vector<std::shared_ptr<CapInstr>> allPathsToSkipInert(const std::shared_ptr<CapInstr>& instr)
    {
        std::vector<std::shared_ptr<CapInstr>> targets = allPathsTo(instr);
        bool changed = true;
        while (changed)
        {
            changed = false;
            std::vector<std::shared_ptr<CapInstr>> newtargets;
            for (auto j : targets)
            {
                if (j->mId == X86_INS_POP || j->mId == X86_INS_MOV || j->mId == X86_INS_XCHG)
                {
                    changed = true;
                    std::vector<std::shared_ptr<CapInstr>> targets2 = allPathsTo(j);
                    newtargets.insert(newtargets.end(), targets2.begin(), targets2.end());
                } else
                    newtargets.push_back(j);
            }
            targets = newtargets;
        }
//        assert(targets.size());
        return targets;
    }
    std::shared_ptr<CapInstr> previousInstructionTo(const std::shared_ptr<CapInstr>& instr)
    {
        std::vector<std::shared_ptr<CapInstr>> prev = allPathsTo(instr);
        if (prev.size() == 1)
            return prev[0];
        return {};
    }
    static bool functionInjectsAdd(address_t method, inject_t inject)
    {
        auto injectptr = functionInjects.find(method);
        if (injectptr != functionInjects.end())
        {
            if (!((int)injectptr->second & (int)inject))
            {
                injectptr->second = (inject_t)((int)injectptr->second | (int)inject);
                // inserted, need to rerun
                return true;
            }
            return false;
        }
        functionInjects.insert(std::pair<address_t, inject_t>(method, inject));
        return true;
    }
};


bool ExtractMethod(Capstone& cap, address_t address, std::vector<std::shared_ptr<CapInstr>>& code, std::vector<switch_t>& indirectJumps, inject_t injectReturn, const std::vector<std::pair<address_t, address_t>>& extraLabels, const std::list<address_t>& dynamics)
{
    std::list<address_t> trace;
    trace.push_back(address);
    std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> instructions;
    // testing: force return flag
//    injectReturn = (inject_t)((int)inject_t::returnCarry | (int)inject_t::returnZero);
//    injectReturn = inject_t::returnZero;
//    injectReturn = inject_t::returnCarry;
    for (const std::pair<address_t, address_t>& pair : extraLabels)
        if (pair.first.linearOffset() == address.linearOffset())
            trace.push_back(pair.second);

    while (!trace.empty())
    {
        address_t pc = trace.front();
        trace.pop_front();
        assert(pc.offset >= 0 && pc.offset < 0xffff);
        if (instructions.find(pc) != instructions.end())
            continue;
        if (_terminators.find(pc.linearOffset()) != _terminators.end())
        {
            printf("// %04x:%04x Terminator reached\n", pc.segment, pc.offset);
            std::shared_ptr<CapInstr> outOfRange = std::shared_ptr<CapInstr>(new CapInstr(pc, 0, "Terminator reached"));
            instructions.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(pc, outOfRange));
            continue;
        }
        if (!cap.InRange(pc, 0))
        {
            printf("// %04x:%04x Out of file range\n", pc.segment, pc.offset);
            std::shared_ptr<CapInstr> outOfRange = std::shared_ptr<CapInstr>(new CapInstr(pc, 0, "Out of range"));
            instructions.insert(std::pair<address_t, std::shared_ptr<CapInstr>>(pc, outOfRange));
            assert(0);
            continue;
        }

        std::shared_ptr<CapInstr> instr = cap.Disasm(pc);
        for (const auto d : dynamics)
            if (instr->InRange(d))
            {
                instr->mInject = inject_t::dynamic;
                if (instr->mComment.empty())
                {
                    instr->mComment = format("%04x:%04x bytes:", instr->mAddress.segment, instr->mAddress.offset);
                    for (int i=0; i<instr->mSize; i++)
                        instr->mComment += format(" %02x", instr->mBytes[i]);
                }
                instr->mComment += format(", dynamic @ %04x:%04x", d.segment, d.offset);
            }
            
        if (_trace)
        {
            if (instr)
                printf("trace %02x:%02x %s %s\n", instr->mAddress.segment, instr->mAddress.offset, instr->mMnemonic, instr->mOperands);
            else
                printf("trace %02x:%02x FAILED\n", pc.segment, pc.offset);
        }
        
        if (!instr)
        {
            printf("%04x:%04x Cannot disassemble in sub_%x()\n", pc.segment, pc.offset, address.linearOffset());
            assert(0);
        }
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
                if (sw.origin == instr->mAddress && !sw.elements.empty())
                    for (int j : sw.elements)
                        trace.push_back(sw.GetTarget(j));
            }
        }
        
        if ((pc = instr->Next()).isValid())
            if (instructions.find(pc) == instructions.end())
            {
                //printf("ofs %x\n", pc.offset);
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
                if (sw.origin == iter->second->mAddress && !sw.elements.empty())
                    for (int j : sw.elements)
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
        if (instr->mLabel)
        {
            prev1 = nullptr;
            prev2 = nullptr;
            prev11 = nullptr;
            prev22 = nullptr;
        }

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
            if ((prev11 && prev11->mId == X86_INS_POP) && (prev22 && prev22->mId == X86_INS_PUSH))
            {
                // push es
                // pop ds
            }
//            else if ((prev11 && prev11->mId == X86_INS_MOV) && (prev22 && prev22->mId == X86_INS_PUSH))
//            {
//                // override stack
//                instr->mInject = inject_t::overrideStack;
//            }
            else if ((prev11 && prev11->mId == X86_INS_PUSH) || (prev22 && prev22->mId == X86_INS_PUSH))
            {
                // just pushing args before calling a method
                if (prev11->mId != X86_INS_CALL)
                {
                    // override stack
                    //if (1) instr->mInject = inject_t::modifyStack; else // REMOVE TEMPORARY!
                    instr->mInject = (inject_t)((int)instr->mInject | (int)inject_t::overrideStack);
                }
            }
            else if ((prev11 && prev11->mId == X86_INS_PUSH) || (prev22 && prev22->mId == X86_INS_PUSH))
            {
                if (((prev11 && prev11->mId != X86_INS_CALL) && (prev22 && prev22->mId != X86_INS_CALL)))
                    instr->mInject = inject_t::modifyStack; // TODO: never called?!
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
                    instr->mInject = (inject_t)((int)instr->mInject | (int)inject_t::stop);
            }
        }
        if (injectReturn != inject_t::none && (instr->mId == X86_INS_RET || instr->mId == X86_INS_RETF))
        {
            if ((int)injectReturn & (int)inject_t::returnZero)
            {
                CTracer tracer(instructions);
                if (IsIndirectJump(indirectJumps, instr))
                {
                    for (int i=0; i<indirectJumps.size(); i++)
                    {
                        switch_t& sw = indirectJumps[i];
                        if (sw.origin == instr->mAddress)
                            for (int j : sw.elements)
                                gNeedToRerun |= tracer.functionInjectsAdd(sw.GetTarget(j), injectReturn);
                    }
                } else {
                    std::vector<std::shared_ptr<CapInstr>> targets = tracer.allPathsToSkipInert(instr);
                    
                    if (all(targets, [&](auto& instr){ return /*IsIndirectJump(indirectJumps, instr) ||*/ SetsZeroFlag(instr) || ClearsZeroFlag(tracer.previousInstructionTo(instr), instr) || instr->mId == X86_INS_CALL || ModifiesZeroFlag(instr) || FiltersZeroFlag(instr); } ))
                    {
                        for (const auto& t : targets)
                        {
                            /*
                             if (IsIndirectJump(indirectJumps, t))
                             {
                             for (int i=0; i<indirectJumps.size(); i++)
                             {
                             switch_t& sw = indirectJumps[i];
                             if (sw.origin == t->mAddress)
                             for (int j : sw.elements)
                             gNeedToRerun |= tracer.functionInjectsAdd(sw.GetTarget(j), injectReturn);
                             }
                             } else*/
                            if (t->mId == X86_INS_CALL)
                                gNeedToRerun |= tracer.functionInjectsAdd(t->CallTarget(), injectReturn);
                            else if (ModifiesZeroFlag(t))
                                t->AddInject(inject_t::zero);
                            else if (SetsZeroFlag(t))
                                t->AddInject(inject_t::setZeroFlag);
                            else if (ClearsZeroFlag(tracer.previousInstructionTo(t), t))
                                t->AddInject(inject_t::clearZeroFlag);
                            else if (FiltersZeroFlag(t))
                                t->AddInject(inject_t::zero);
                        }
                    } else {
                        instr->mInject = (inject_t)((int)instr->mInject | (int)inject_t::stop);
                        printf("// INJECT: Error: cannot inject zero flag in sub_%x()!\n",
                               address.linearOffset());
                    }
                }
            }
            if ((int)injectReturn & (int)inject_t::returnCarry)
            {
                CTracer tracer(instructions);
                std::vector<std::shared_ptr<CapInstr>> targets = tracer.allPathsToSkipInert(instr);

                if (all(targets, [](auto& instr){ return SetsCarryFlag(instr) || ClearsCarryFlag(instr) || ModifiesCarryFlag(instr) || instr->mId == X86_INS_CALL || FiltersCarryFlag(instr); } ))
                {
                    for (const auto& t : targets)
                    {
                        if (ModifiesCarryFlag(t))
                            t->AddInject(inject_t::carry);
                        if (t->mId == X86_INS_CALL)
                            gNeedToRerun |= tracer.functionInjectsAdd(t->CallTarget(), injectReturn);
                        if (FiltersCarryFlag(t))
                            t->AddInject(inject_t::carry);
                    }
                } else {
                    instr->mInject = (inject_t)((int)instr->mInject | (int)inject_t::stop);
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
        snprintf(offset, 32, "0x%04x", (int)op.mem.disp & 0xffff);
    else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID && op.mem.disp == 0)
        snprintf(offset, 32, "%s", cs_reg_name(_handle, op.mem.base));
    else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index == X86_REG_INVALID)
    {
        if (op.mem.base != X86_REG_BP)
        {
            if ((op.mem.disp & 0xffff) > negativeoffset)
                snprintf(offset, 32, "%s - %d", cs_reg_name(_handle, op.mem.base), 65536-((int)op.mem.disp & 0xffff));
            else
                snprintf(offset, 32, "%s + %d", cs_reg_name(_handle, op.mem.base), (int)op.mem.disp & 0xffff);
        }
        else
        {
            if ((op.mem.disp & 0xffff) < 60000)
            {
                if ((op.mem.disp & 0xffff) > negativeoffset)
                    snprintf(offset, 32, "%s - %d", cs_reg_name(_handle, op.mem.base), 65536-((int)op.mem.disp & 0xffff));
                else
                    snprintf(offset, 32, "%s + %d", cs_reg_name(_handle, op.mem.base), (int)op.mem.disp & 0xffff);
            }
            else
                snprintf(offset, 32, "%s - %d", cs_reg_name(_handle, op.mem.base), 0x10000-abs((int)op.mem.disp & 0xffff));
        }
    }
    else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index != X86_REG_INVALID && op.mem.disp == 0)
        snprintf(offset, 32, "%s + %s", cs_reg_name(_handle, op.mem.base), cs_reg_name(_handle, op.mem.index));
    else if (op.mem.base != X86_REG_INVALID && op.mem.scale == 1 && op.mem.index != X86_REG_INVALID && op.mem.disp != 0)
    {
        if ((op.mem.disp & 0xffff) > negativeoffset)
            snprintf(offset, 32, "%s + %s - %d", cs_reg_name(_handle, op.mem.base), cs_reg_name(_handle, op.mem.index), 65536-((int)op.mem.disp & 0xffff) );
        else
            snprintf(offset, 32, "%s + %s + %d", cs_reg_name(_handle, op.mem.base), cs_reg_name(_handle, op.mem.index), (int)op.mem.disp & 0xffff);
    }
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
        snprintf(tmp, 32, "0x%04llx", op.imm & 0xffffffff);
        return tmp;
    }
    if (op.type == X86_OP_MEM)
    {
        char segment[32], offset[32], tmp[64];
        GetOpAddress(op, segment, offset);
        snprintf(tmp, 32, "memory%s(%s, %s)", op.size == 2 ? "16" : "", segment, offset);
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
        inject_t prev = inst->mInject;
        inst->mInject = inject_t::none;
        std::string cond = MakeCCondition(noticeCurrentMethod, inst, op);
        // rerun for temp
        if (inst->mInject == inject_t::temp || inst->mInject == inject_t::tempPost)
            cond = MakeCCondition(noticeCurrentMethod, inst, op);
        if (op == X86_INS_JNE || op == X86_INS_JE || op == X86_INS_JS || op == X86_INS_JNS)
            inst->mInject = inject_t((int)prev /*& ~(int)inject_t::discard */| (int)inject_t::tempPost);
        else
            inst->mInject = inject_t((int)prev /*& ~(int)inject_t::discard */| (int)inject_t::temp);
        std::string rd0 = assign(x86, "$rd0");
        std::string tmp0 = assign(x86, "$tmp0");
        cond = replaceStr(cond, rd0, tmp0);
        return assign(x86, "stop(\"check inject: %s %s\") && %s", inst->mMnemonic, inst->mOperands, cond.c_str());
    }
    
    const char* tempCond = nullptr;
    
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
                case X86_INS_JS:
                    assert (x86.operands[1].type == X86_OP_IMM && x86.operands[1].imm == 0);
                    return assign(x86, "($sig0)$rd0 < 0");
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
                    if (assign(x86, "$rd0") != assign(x86, "$rd1"))
                        return assign(x86, "!($rd0 & $rd1)");
                    else
                        return assign(x86, "!$rd0");
                case X86_INS_JNE:
                    if (assign(x86, "$rd0") != assign(x86, "$rd1"))
                        return assign(x86, "$rd0 & $rd1");
                    else
                        return assign(x86, "$rd0");
                case X86_INS_JNS:
                    assert (x86.operands[0].type == X86_OP_REG && x86.operands[1].type == X86_OP_REG &&
                            x86.operands[0].reg == x86.operands[1].reg);
                    return assign(x86, "($sig0)$rd0 >= 0");
                case X86_INS_JS:
                    assert (x86.operands[0].type == X86_OP_REG && x86.operands[1].type == X86_OP_REG &&
                            x86.operands[0].reg == x86.operands[1].reg);
                    return assign(x86, "($sig0)$rd0 < 0");
                case X86_INS_JLE:
                    assert (x86.operands[0].type == X86_OP_REG && x86.operands[1].type == X86_OP_REG &&
                            x86.operands[0].reg == x86.operands[1].reg);
                    return assign(x86, "($sig0)$rd0 <= 0");
                default:
                    return format("stop(/*82*/)");
                    //assert(0);
            }
            break;
            
        case X86_INS_SHR:
        case X86_INS_SHL:
        case X86_INS_INC:
        case X86_INS_DEC:
        case X86_INS_ADC:
        case X86_INS_ADD:
        case X86_INS_SUB:
        case X86_INS_ROL:
        case X86_INS_ROR:
        case X86_INS_RCR:
        case X86_INS_RCL:
            if (inst->mId == X86_INS_ADD && op == X86_INS_JG)
                tempCond = "($sig0)$tmp0 + ($sig0)$rd1 > 0";
            if (inst->mId == X86_INS_SUB && op == X86_INS_JG)
                tempCond = "($sig0)$tmp0 - ($sig0)$rd1 > 0";
            if (inst->mId == X86_INS_ADD && op == X86_INS_JGE)
                tempCond = "($sig0)$tmp0 + ($sig0)$rd1 >= 0";
            if (inst->mId == X86_INS_SUB && op == X86_INS_JGE)
                tempCond = "($sig0)$tmp0 - ($sig0)$rd1 >= 0";
            if (inst->mId == X86_INS_ADD && op == X86_INS_JL)
                tempCond = "($sig0)$tmp0 + ($sig0)$rd1 < 0";
            if (inst->mId == X86_INS_SUB && op == X86_INS_JL)
                tempCond = "($sig0)$tmp0 - ($sig0)$rd1 < 0";
            if (inst->mId == X86_INS_ADD && op == X86_INS_JLE)
                tempCond = "($sig0)$tmp0 + ($sig0)$rd1 <= 0";
            if (inst->mId == X86_INS_SUB && op == X86_INS_JLE)
                tempCond = "($sig0)$tmp0 - ($sig0)$rd1 <= 0";
            if (op == X86_INS_JA)
                tempCond = "$tmp0 > $rd1";
            if (inst->mId == X86_INS_SUB && op == X86_INS_JB)
                tempCond = "$tmp0 < $rd1";
            if (inst->mId == X86_INS_SUB && op == X86_INS_JBE)
                tempCond = "$tmp0 <= $rd1";
            if (inst->mId == X86_INS_DEC && op  == X86_INS_JL)
                tempCond = "($sig0)$tmp0 < 1";
            if (inst->mId == X86_INS_DEC && op == X86_INS_JG)
                tempCond = "($sig0)$tmp0 > 1"; // check unbalanced
//            if (inst->mId == X86_INS_DEC && op == X86_INS_JE)
//                tempCond = "$tmp0 == 1";
//            if (inst->mId == X86_INS_DEC && op == X86_INS_JNE)
//                tempCond = "$tmp0 != 1";
            if (inst->mId == X86_INS_DEC && op == X86_INS_JGE)
                tempCond = "($sig0)$tmp0 >= 1";

            if (tempCond)
            {
                if (inst->mInject != inject_t::temp)
                {
                    inst->mInject = inject_t::temp;
                    return format("stop(/*inject_t::temp - %s %s*/)", inst->mMnemonic, inst->mOperands);
                } else
                    return assign(x86, tempCond); // do calc in larger data type
            }

            switch (op)
            {
                case X86_INS_JE:
                case X86_INS_JNE:
                case X86_INS_JNS:
                case X86_INS_JS:
                    // fallback to general rule
                    break;
                case X86_INS_JAE:
                    if (inst->mInject != inject_t::carry)
                    {
                        inst->mInject = inject_t::carry;
                        return "stop(/*inject_t::carry*/)";
                    } else {
                        return "!flags.carry";
                    }
                case X86_INS_JB:
                    if (inst->mInject != inject_t::carry)
                    {
                        inst->mInject = inject_t::carry;
                        return "stop(/*inject_t::carry*/);";
                    } else {
                        return "flags.carry";
                    }
                case X86_INS_JLE:
                    return assign(x86, "($sig0)$rd0 <= 0");
                default:
                    return format("stop(/*82 - %s -> %s*/)", inst->mMnemonic, cs_insn_name(_handle, op));
            }

        case X86_INS_SBB:
        case X86_INS_NEG:
        case X86_INS_AND:
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
                case X86_INS_JLE:
                    if (inst->mId == X86_INS_NEG) // xenon2 sub, neg, jle
                        return assign(x86, "($sig0)$rd0 <= 0");
                    return "stop(/*jle*/)";
                case X86_INS_JL:
                    return "stop(/*jl*/)";
                case X86_INS_JA:
                    return "stop(/*ja*/)";
                case X86_INS_JG:
                    return "stop(/*jg*/)";
                case X86_INS_JAE:
                    if (inst->mId == X86_INS_SBB)
                    {
                        if (inst->AddInject(inject_t::carry))
                            return "stop(/*jae-1*/)";
                        else
                            return "!flags.carry";
                    }
                    return "stop(/*jae*/)";
                case X86_INS_JB:
                    return "stop(/*jb*/)";
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
                    if(x86.operands[0].type != X86_OP_IMM)
                        return "stop(/*call no imm*/);";
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
//                case X86_INS_JB:
//                    return assign(x86, "false"); // not sure!
                case X86_INS_JG:
                    return assign(x86, "($sig0)$rd0 > 0");

                default:
                    return assign(x86, "stop(/*condition!*/)");
                    //assert(0);
            }
            break;
        case X86_INS_CMPSB:
            switch (op)
            {
                case X86_INS_JE:
                    return assign(x86, "flags.zero");
                case X86_INS_JNE:
                    return assign(x86, "!flags.zero");
                default:
                    return "stop(/*70-1*/)";
            }
        case X86_INS_CMC:
            switch (op)
            {
                case X86_INS_JB:
                    return assign(x86, "flags.carry");
                case X86_INS_JAE:
                    return assign(x86, "!flags.carry");
                default:
                    return "stop(/*70-2*/)";
            }

        default:
            return format("stop(/*70 - %s*/)", cs_insn_name(_handle, op));
            //assert(0);
    }
}

bool FindCalls(const std::vector<std::shared_ptr<CapInstr>>& code, std::list<address_t>& toProcess, std::vector<switch_t>& indirectJumps)
{
    bool callsUncoveredIndirect = false;
    for (const std::shared_ptr<CapInstr>& instr : code)
    {
        if (instr->IsIndirectCall())
        {
            bool identified = false;
            if (IsIndirectJump(indirectJumps, instr))
            {
                for (int i=0; i<indirectJumps.size(); i++)
                {
                    switch_t& sw = indirectJumps[i];
                    if (sw.origin == instr->mAddress)
                    {
                        identified = true;
                        for (int j : sw.elements)
                        {
                            address_t newAddr = sw.GetTarget(j);
                            if (std::find(toProcess.begin(), toProcess.end(), newAddr) == toProcess.end())
                                toProcess.push_back(newAddr);
                        }
                    }
                }
            }
            // TODO: what if this indirect is not covered by jump tables?
            callsUncoveredIndirect |= identified;
        }

        if (instr->mId == X86_INS_CALL)
        {
            const cs_x86& x86 = instr->mDetail;

            if (x86.op_count == 1 && x86.operands[0].type == X86_OP_IMM && x86.operands[0].size == 2)
            {
                address_t newAddr = fromRelative(instr, x86.operands[0].imm);
                if (std::find(toProcess.begin(), toProcess.end(), newAddr) == toProcess.end())
                    toProcess.push_back(newAddr);
            }
        }
        if (instr->mId == X86_INS_LCALL)
        {
            const cs_x86& x86 = instr->mDetail;
            if (x86.op_count == 2 &&
                x86.operands[0].type == X86_OP_IMM && x86.operands[0].size == 2 &&
                x86.operands[1].type == X86_OP_IMM && x86.operands[1].size >= 2)
            {
                address_t newAddr = address_t{(int)x86.operands[0].imm, (int)x86.operands[1].imm};
                if (std::find(toProcess.begin(), toProcess.end(), newAddr) == toProcess.end())
                    toProcess.push_back(newAddr);
            }
        }
    }
    return callsUncoveredIndirect;
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

std::string functionAnnotation(address_t m)
{
    auto injectptr = functionInjects.find(m);
    inject_t inject = injectptr != functionInjects.end() ? injectptr->second : inject_t::none;
    std::string strInject = "";
    if ((int)inject & (int)inject_t::returnZero)
        strInject += "+zero";
    else if ((int)inject & (int)inject_t::returnCarry)
        strInject += "+carry";
    else if ((int)inject & (int)inject_t::callsSync)
        strInject += "+sync";

    return format("%04x:%04x%s", m.segment, m.offset, strInject.c_str());
}

std::vector<std::pair<address_t, address_t>> getRanges(const std::vector<std::shared_ptr<CapInstr>>& code)
{
    std::vector<std::pair<address_t, address_t>> ranges;
    address_t first, last;
    
    for (const std::shared_ptr<CapInstr>& inst : code)
    {
        if (inst->mSize == 0)
            continue;
        if (!inst->mComment.empty())
            continue;
        address_t instbegin = inst->mAddress;
        address_t instend{instbegin.segment, instbegin.offset + inst->mSize};
        if (!first.isValid() || instbegin != last)
        {
            if (first.isValid())
                ranges.push_back({first, last});
            first = instbegin;
            last = instend;
        } else
        {
            assert (instbegin == last);
            last = instend;
        }
    }
    if (first.isValid())
        ranges.push_back({first, last});
    return ranges;
}

bool DumpCodeAsC(const std::vector<std::shared_ptr<CapInstr>>& code, std::vector<std::string>& text, std::vector<switch_t>& switches, std::vector<switch_t> jumps, bool lines = false)
{
    assert(!code.empty());
    bool noReturn = false;
//    if (code.back()->mId == X86_INS_RET)
//        _currentCall = Near;
//    else
//        if (code.back()->mId == X86_INS_RETF)
//            _currentCall = Far;
//    else
//    {
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
    if (retn == 0 && retf == 0)
        noReturn = true;
//    }
    
    bool usesStack = false;
    for (const auto& ins : code)
    {
        if (!ins->IsInstruction())
            continue;
        if (ins->mId == X86_INS_PUSH || ins->mId == X86_INS_POP)
            continue;
        if (strcmp(ins->mMnemonic, "or") == 0 && strcmp(ins->mOperands, "sp, sp") == 0)
        {
            // only clears zero flag
        } else
        {
//            if (strstr(ins->mOperands, "bp") || strstr(ins->mOperands, "sp"))
//                usesStack = true;
            
            if (ins->mDetail.op_count >= 1)
            {
                std::string arg0 = assign(ins->mDetail, "$rd0");
                if (ins->mDetail.operands[0].type == X86_OP_REG && ins->mDetail.operands[0].reg == X86_REG_SP)
                    usesStack = true;
                /*
                // TODO: could be optimized!
                if (arg0.find("sp") != std::string::npos || arg0.find("bp") != std::string::npos)
                {
                    if (ins->mId == X86_INS_MOV && ins->mDetail.op_count == 2 &&
                        ins->mDetail.operands[0].type == X86_OP_REG &&
                        ins->mDetail.operands[0].reg == X86_REG_BP &&
                        (ins->mDetail.operands[1].type == X86_OP_IMM || ins->mDetail.operands[1].type == X86_OP_MEM))
                    {
                        // uses bp only as variable
                    } else
                        usesStack = true;
                    break;
                }*/
            }
            if (ins->mDetail.op_count >= 2)
            {
                if (ins->mDetail.operands[1].type == X86_OP_REG && ins->mDetail.operands[1].reg == X86_REG_SP)
                    usesStack = true;
    /*
                std::string arg1 = assign(ins->mDetail, "$rd1");
                if (arg1.find("sp") != std::string::npos || arg1.find("bp") != std::string::npos)
                {
                    if (ins->mId == X86_INS_CMP && ins->mDetail.op_count == 2 &&
                        (ins->mDetail.operands[0].reg == X86_REG_BP || ins->mDetail.operands[1].reg == X86_REG_BP))
                    {
                        
                    } else
                        usesStack = true;
                    break;
                }*/
            }
        }
    }
    
    auto functionHeader = [&]()
    {
        std::set<int> offsets;
        for (const auto& i : code)
        {
            if (i->mId == X86_INS_RET || i->mId == X86_INS_RETF)
            {
                if (i->mDetail.op_count == 1 && i->mDetail.operands[0].type == X86_OP_IMM)
                    offsets.insert(i->mDetail.operands[0].imm);
                else
                    offsets.insert(0);
            }
        }
        int ofs = (offsets.size() == 1) ? *offsets.begin() : -1;
        switch (_currentCall)
        {
            case Near:
                if (_stackGuard)
                    text.push_back(format("CStackGuard sg(%d, %s);", ofs, usesStack ? "true" : "false"));
                if (!_simpleStack && usesStack)
                    text.push_back("push(0x7777);");
                break;
            case Far:
                if (_stackGuard)
                    text.push_back(format("CStackGuardFar sg(%d, %s);", ofs, usesStack ? "true" : "false"));
                //text.push_back("push(0x8888);");
                if (!_simpleStack && usesStack)
                    text.push_back("push(0x7777);");
                break;
            default:
                if (!noReturn)
                    text.push_back("stop(/*unk call conv*/);");
                else {
                    if (_stackGuard)
                        text.push_back(format("CStackGuard sg(%d, %s); // no return", ofs, usesStack ? "true" : "false"));
                    else if (!_simpleStack && usesStack)
                        text.push_back("push(0x7777); // no return");
                    else
                        text.push_back("// no return");
                }
        }
    };
    auto functionFooter = [&]()
    {
        switch (_currentCall)
        {
            case Near:
                if (!_simpleStack && usesStack)
                    text.push_back("assert(pop() == 0x7777);");
                break;
            case Far:
                if (!_simpleStack && usesStack)
                    text.push_back("assert(pop() == 0x7777);");
                text.push_back("cs = pop();");
                break;
            default:
                if (noReturn)
                    text.push_back("stop(/*no return*/);");
                else
                    text.push_back("stop(/*unk call conv*/);");
        }
    };

    bool modified = false;
    if (segofs_in_comment)
    {
//        auto injectptr = functionInjects.find(code[0]->mAddress);
//        inject_t inject = injectptr != functionInjects.end() ? injectptr->second : inject_t::none;
//        std::string strInject = "";
//        if ((int)inject & (int)inject_t::returnZero)
//            strInject += "+zero";
//        else if ((int)inject & (int)inject_t::returnCarry)
//            strInject += "+carry";
//        else if ((int)inject & (int)inject_t::callsSync)
//            strInject += "+sync";

//        text.push_back(format("void sub_%x() // %04x:%04x%s", code[0]->mAddress.linearOffset(),
//                              code[0]->mAddress.segment, code[0]->mAddress.offset, strInject.c_str()));
            text.push_back(format("void sub_%x() // %s", code[0]->mAddress.linearOffset(), functionAnnotation(code[0]->mAddress).c_str()));
    }
    else
        text.push_back(format("void sub_%x()", code[0]->mAddress.linearOffset()));


    if (_trace)
        printf("trace: void sub_%x()\n", code[0]->mAddress.linearOffset());

    text.push_back(format("{"));
    if (_coverage)
    {
        std::vector<std::pair<address_t, address_t>> ranges = getRanges(code);
        for (const auto& range : ranges)
        {
            text.push_back(format("// coverage: 0x%x-0x%x method sub_%x", range.first.fileOffset(), range.second.fileOffset(), code[0]->mAddress.linearOffset()));
            text.push_back(format("// coverage2: %04x:%04x-%04x:%04x method sub_%x // ins(0x%04x, 0x%04x, 0x%04x);", range.first.segment, range.first.offset, range.second.segment, range.second.offset, code[0]->mAddress.linearOffset(),
                                  range.first.offset, range.second.offset, code[0]->mAddress.offset));
        }
    }
    std::shared_ptr<CapInstr> lastCompare;
    std::shared_ptr<CapInstr> prevInstr;
    bool keepLastCompare{false};
    
    functionHeader();
    
    for (const std::shared_ptr<CapInstr>& instr : code)
    {
        inject_t injectLater = inject_t::none;
        const cs_x86& x86 = instr->mDetail;
        keepLastCompare = false;
        
        if (_trace)
            printf("trace: %s %s\n", instr->mMnemonic, instr->mOperands);
        if (instr->mMark)
        {
            if (instr->mComment.substr(0, 6) == "gap of")
                text.push_back(format("// %s %s %s", instr->mMnemonic, instr->mOperands, instr->mComment.c_str()));
            else
            {
                if (instr->mMnemonic[0] || instr->mOperands[0] || instr->mComment != "")
                    text.push_back(format("stop(/*7*/); // %s %s %s", instr->mMnemonic, instr->mOperands, instr->mComment.c_str()));
            }
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
        snprintf(current, 128, "%s %s", instr->mMnemonic, instr->mOperands);
        
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
                    case X86_INS_ROL:
                        text.push_back(assign(x86, "flags.carry = !!($rd0 & $msb0);"));
                        break;
                    case X86_INS_ROR:
                        text.push_back(assign(x86, "flags.carry = $rd0 & 1;"));
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
                    case X86_INS_XOR:
                        text.push_back(assign(x86, "flags.carry = false;"));
                        break;
                    case X86_INS_JE:
                    case X86_INS_JNE:
                    case X86_INS_JB:
                    case X86_INS_JA:
                    case X86_INS_JAE:
                        if (lastCompare)
                            modified |= lastCompare->AddInject(inject_t::carry);
                        else
                            assert(0);
                        break;
                    case X86_INS_SBB:
                        text.push_back(assign(x86, "tl = $rd0 < $rd1 + flags.carry;"));
                        break;
                    case X86_INS_CMC:
                        if (lastCompare)
                            modified |= lastCompare->AddInject(inject_t::carry);
                        else
                            text.push_back("stop(/*74-3*/);");
                        break;
                    case X86_INS_NEG:
                        text.push_back(assign(x86, "flags.carry = $rd0 != 0;"));
                        break;
                    default:
                        text.push_back(format("stop(/*74*/);"));
                        //text.push_back(format("stop(/*74 inject carry %s*/);", cs_insn_name(_handle, instr->mId)));
                        //assert(0);
                        break;
                }
                any = true;
            }
            if ((int)instr->mInject & (int)inject_t::zero)
            {
//                if (instr->mLabel)
//                    text.push_back("stop(\"inject check all paths\")");
                    
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
                    case X86_INS_OR:
                        injectLater = inject_t::zero;
//                        text.push_back(assign(x86, "flags.zero = $rd0 == 0;"));
                        break;
                    case X86_INS_JE:
                    case X86_INS_JNE:
                        if (lastCompare)
                            modified |= lastCompare->AddInject(inject_t::zero);
                        else
                            assert(0);
//                        injectLater = inject_t::zero;
                        // processed later
                        break;
                    default:
                        text.push_back(assign(x86, "flags.zero = stop(\"43\");"));
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
            else if ((int)instr->mInject & (int)inject_t::tempPost)
            {
            }
            else if ((int)instr->mInject & (int)inject_t::setZeroFlag)
            {
                // post
//                text.push_back(assign(x86, "flags.zero = true;"));
            }
            else if ((int)instr->mInject & (int)inject_t::clearZeroFlag)
            {
                // post
//                text.push_back(assign(x86, "flags.zero = false;"));
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
                assert(0); // unused
                if (segofs_in_comment)
                    text.push_back(assign(x86, "callIndirect(cs, pop()); // %04x:%04x", instr->mAddress.segment, instr->mAddress.offset));
                else
                    text.push_back(assign(x86, "callIndirect(cs, pop());"));
            }
            else if ((int)instr->mInject & (int)inject_t::overrideStack)
            {
                // process later
            }
            else if ((int)instr->mInject & (int)inject_t::dynamic)
            {
                text.push_back(assign(x86, "stop(/*%s*/);", instr->mComment.c_str()));
            }
            else
            if (any)
            {
            }
            else
                assert(0);

            if ((int)instr->mInject & (int)inject_t::overrideStack)
            {
                const auto sw = std::find_if(jumps.begin(), jumps.end(), [&](const switch_t& sw){
                 return sw.origin == instr->mAddress;
                });
                if (sw != jumps.end())
                {
                    assert (sw->type == switch_t::CallWordsByOfs);
                    assert (sw->selector == X86_REG_INVALID);

                    assert(!sw->elements.empty());
                    text.push_back(format("switch (%s)", "pop()"));
                    text.push_back("{");
                    for (int i : sw->elements)
                        text.push_back(sw->GetCase(i));
                    text.push_back("default:");
                    text.push_back("assert(0);");
                    text.push_back("}");
                } else {
                    if (segofs_in_comment)
                        text.push_back(assign(x86, "stop(/*override stack*/); // %04x:%04x", instr->mAddress.segment, instr->mAddress.offset));
                    else
                        text.push_back(assign(x86, "stop(/*override stack*/);"));
                }
            }
        }

        switch (instr->mId)
        {
            case X86_INS_DIV:
                assert(x86.op_count == 1);
                text.push_back(assign(x86, "div($reg0);"));
                break;
            case X86_INS_IDIV:
                assert(x86.op_count == 1);
                assert(x86.operands[0].size == 1 || x86.operands[0].size == 2);
                text.push_back(assign(x86, "idiv($rd0);"));
                break;
            case X86_INS_IMUL:
                //assert(x86.operands[0].size == 1);
                if (x86.op_count == 1)
                    text.push_back(assign(x86, "imul($rd0);"));
                else if (x86.op_count == 2)
                    text.push_back(assign(x86, "imul($rd0, $rd1);"));
                else if (x86.op_count == 3)
                    text.push_back(assign(x86, "imul($rd0, $rd1, $rd2);"));
                else
                    assert(0);
                break;
            case X86_INS_MUL:
                //assert(x86.operands[0].size == 1);
                assert(x86.op_count == 1);
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
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_XOR:
                if (assign(x86, "$rd0") == assign(x86, "$rd1"))
                {
                    if (assign(x86, "$rd0") == "eax")
                        text.push_back(assign(x86, "ax = 0;")); // 16 bit!
                    else
                        text.push_back(assign(x86, "$rw0 = 0;"));
                }
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
                keepLastCompare = true;
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
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_IMM &&
                       (x86.operands[0].size == 2 || x86.operands[0].size == 4));

                if (!lastCompare && !instr->mForceFlagCondition)
                {
                    std::map<address_t, std::shared_ptr<CapInstr>, cmp_adress_t> instructions;
                    for (const auto& i : code)
                        instructions.insert({i->mAddress, i});
                    
                    CTracer tracer(instructions);
                    std::vector<std::shared_ptr<CapInstr>> targets = tracer.allPathsToSkipInert(instr);
                    if (targets.size() == 1)
                        lastCompare = targets[0];
                }
                {
                    inject_t injectPrev = lastCompare ? lastCompare->mInject : inject_t::none;

                    if (!instr->mForceFlagCondition)
                    {
                        if (lastCompare)
                        {
                            assert(lastCompare);
                            if (lastCompare->mId == X86_INS_CMP && lastCompare->mAddress == fromRelative(instr, x86.operands[0].imm))
                                text.push_back("sync();"); // infinite loop
                            text.push_back(format("if (%s)", MakeCCondition(code[0]->mAddress, lastCompare, instr->mId).c_str()));
                        } else {
                            text.push_back(format("if (stop(/*1 - %s %s*/))", instr->mMnemonic, instr->mOperands));
                        }
                    }
                    else
                        text.push_back(format("if (%s)", MakeCFlagCondition(instr->mId).c_str()));
                    
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
                if (x86.op_count == 1 && x86.operands[0].size == 4)
                {
                    text.push_back(format("stop(/* %s %s */);", instr->mMnemonic, instr->mOperands));
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
                    auto sw = std::find_if(jumps.begin(), jumps.end(), [&](const switch_t& sw){ return sw.origin == instr->mAddress; });
                    if (sw != jumps.end() && !sw->elements.empty())
                    {
                        // duplicate
                        std::string selector = sw->GetSelector().c_str(); // indirect
                        if (selector.empty())
                        {
                            if (x86.operands[0].type == X86_OP_MEM &&
                                x86.operands[0].mem.index == X86_REG_INVALID &&
                                x86.operands[0].mem.base != X86_REG_INVALID &&
                                x86.operands[0].mem.scale == 1)
                            {
                                if (x86.operands[0].mem.segment != X86_REG_INVALID)
                                    text.push_back(format("assert(%s == 0x%04x);", cs_reg_name(_handle, x86.operands[0].mem.segment), sw->GetBaseAddress().segment));
                                selector = cs_reg_name(_handle, x86.operands[0].mem.base);
                                assert((uint16_t)sw->GetBaseAddress().offset == (uint16_t)x86.operands[0].mem.disp);
                            }
                        }
                        if (selector.empty())
                        {
                            selector = "stop(\"$rd0\")";
                        }

                        text.push_back(format("switch (%s)", selector.c_str()));
                        text.push_back("{");
                        while(sw != jumps.end())
                        {
                            if (_coverage)
                            {
                                text.push_back(format("// coverage: 0x%x-0x%x switch", sw->GetBaseAddress().fileOffset(), sw->GetBaseAddress().fileOffset() + sw->elements.back() * sw->GetSize()));
                            }

                            for (int i : sw->elements)
                                text.push_back(sw->GetCase(i));
                            sw = std::find_if (++sw, jumps.end(), [&](const switch_t& sw){ return sw.origin == instr->mAddress; });
                        }
                        text.push_back("default:");
                        text.push_back("assert(0);");
                        text.push_back("}");
                    } else {
                        if (x86.operands[0].type == X86_OP_MEM)
                        {
                            if (segofs_in_comment)
                                text.push_back(assign(x86, "jumpIndirect(cs, $rd0); // %04x:%04x", instr->mAddress.segment, instr->mAddress.offset));
                            else
                                text.push_back(assign(x86, "jumpIndirect(cs, $rd0);"));
                            text.push_back(assign(x86, "return;"));
                        }
                        else
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

                if (!lastCompare)
                {
                    text.push_back(format("if (--cx && stop(\"loopne no compare\"))"));
                    text.push_back(format("goto loc_%x;", fromRelative(instr, x86.operands[0].imm).linearOffset()));
                    break;
                }
                assert(lastCompare);
                keepLastCompare = true;
                text.push_back(format("if (--cx && %s)", MakeCCondition(code[0]->mAddress, lastCompare, X86_INS_JNE).c_str()));
                text.push_back(format("goto loc_%x;", fromRelative(instr, x86.operands[0].imm).linearOffset()));
                break;

            case X86_INS_LOOPE:
                assert(x86.op_count == 1 &&
                       x86.operands[0].type == X86_OP_IMM &&
                       x86.operands[0].size == 2);

                if (!lastCompare)
                {
                    text.push_back("stop(/*e2*/);");
                } else {
                    keepLastCompare = true;
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
                    if (segofs_in_comment)
                        text.push_back(format("sub_%x(); // %04x:%04x", fromRelative(instr, x86.operands[0].imm).linearOffset(),
                                       fromRelative(instr, x86.operands[0].imm).segment,
                                        fromRelative(instr, x86.operands[0].imm).offset));
                    else
                        text.push_back(format("sub_%x();", fromRelative(instr, x86.operands[0].imm).linearOffset()));
                    lastCompare = instr;
                    keepLastCompare = true;
                    break;
                }
                if (x86.op_count == 1 && x86.operands[0].type == X86_OP_REG /*&& x86.operands[0].size == 2*/)
                {
                    switch_t* sw = nullptr;
                    const auto sw1 = std::find_if(switches.begin(), switches.end(), [&](const switch_t& sw){
                        return sw.origin == instr->mAddress;
                    });
                    if (sw1 != switches.end())
                        sw = &*sw1;
                    else {
                        const auto sw2 = std::find_if(jumps.begin(), jumps.end(), [&](const switch_t& sw){
                            return sw.origin == instr->mAddress;
                        });
                        if (sw2 != jumps.end())
                            sw = &*sw2;
                    }

                    if (sw)
                    {
                        if (sw->type == switch_t::CallWordsByOfs)
                        {
                            assert (x86.operands[0].type == X86_OP_REG &&
                                x86.operands[0].reg == sw->selector);

                            assert(!sw->elements.empty());
                            text.push_back(format("switch (%s)", sw->GetSelector().c_str()));
                            text.push_back("{");
                            for (int i : sw->elements)
                                text.push_back(sw->GetCase(i));
                            text.push_back("default:");
                            text.push_back("assert(0);");
                            text.push_back("}");
                        }
                        break;
                    }
                }
                if (x86.op_count == 1 && x86.operands[0].type == X86_OP_MEM && x86.operands[0].size == 2)
                {
                    switch_t* sw = nullptr;
                    const auto sw1 = std::find_if(switches.begin(), switches.end(), [&](const switch_t& sw){
                        return sw.origin == instr->mAddress;
                    });
                    if (sw1 != switches.end())
                        sw = &*sw1;
                    else {
                        const auto sw2 = std::find_if(jumps.begin(), jumps.end(), [&](const switch_t& sw){
                            return sw.origin == instr->mAddress;
                        });
                        if (sw2 != jumps.end())
                            sw = &*sw2;
                    }

                    if (sw)
                    {
                        std::string selector = sw->GetSelector().c_str(); // indirect
                        if (sw->type == switch_t::Call)
                        {
                            assert (x86.operands[0].type == X86_OP_MEM &&
                                x86.operands[0].mem.index == X86_REG_INVALID &&
                                x86.operands[0].mem.base != X86_REG_INVALID &&
                                x86.operands[0].mem.scale == 1);
                            text.push_back(format("assert(cs == 0x%04x);", sw->GetBaseAddress().segment));
                            selector = assign(x86, "$rd0");
                        }
                        if (sw->type == switch_t::CallWordsByOfs)
                        {
                            assert (x86.operands[0].type == X86_OP_MEM &&
                                x86.operands[0].mem.index == X86_REG_INVALID &&
                                x86.operands[0].mem.base != X86_REG_INVALID &&
                                x86.operands[0].mem.scale == 1);
                            text.push_back(format("assert(cs == 0x%04x);", sw->origin.segment));
                            selector = assign(x86, "$rd0");
                        }

                        if (selector.empty())
                        {
                            if (x86.operands[0].type == X86_OP_MEM &&
                                x86.operands[0].mem.index == X86_REG_INVALID &&
                                x86.operands[0].mem.base != X86_REG_INVALID &&
                                x86.operands[0].mem.scale == 1)
                            {
                                text.push_back(format("assert(%s == 0x%04x);", cs_reg_name(_handle, x86.operands[0].mem.segment), sw->GetBaseAddress().segment));
                                selector = cs_reg_name(_handle, x86.operands[0].mem.base);
                                assert(sw->GetBaseAddress().offset == x86.operands[0].mem.disp);
                            }
                        }
                        if (selector.empty())
                        {
                            selector = "stop(\"$rd0\")";
                        }
                        assert(!sw->elements.empty());
                        text.push_back(format("switch (%s)", selector.c_str()));
                        text.push_back("{");
                        for (int i : sw->elements)
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
                        if (segofs_in_comment)
                            text.push_back(assign(x86, "callIndirect(cs, $rd0); // %04x:%04x", instr->mAddress.segment, instr->mAddress.offset));
                        else
                            text.push_back(assign(x86, "callIndirect(cs, $rd0);"));
                    }
                    break;
                }
                
                if (segofs_in_comment)
                    text.push_back(assign(x86, "callIndirect(cs, $rd0); // %04x:%04x", instr->mAddress.segment, instr->mAddress.offset));
                else
                    text.push_back(assign(x86, "callIndirect(cs, $rd0);"));
                break;
            case X86_INS_LCALL:
//                text.push_back("push(0);"); // TODO: use long call instead, function might not be using stack at all
                if (x86.op_count == 2 && x86.operands[0].type == X86_OP_IMM && x86.operands[1].type == X86_OP_IMM)
                {
                    text.push_back(assign(x86, "push(cs);"));
                    text.push_back(assign(x86, "cs = 0x%04x;", x86.operands[0].imm));
                    if (segofs_in_comment)
                        text.push_back(format("sub_%x(); // %04x:%04x", address_t{(int)x86.operands[0].imm, (int)x86.operands[1].imm}.linearOffset(), (int)x86.operands[0].imm, (int)x86.operands[1].imm));
                    else
                        text.push_back(format("sub_%x();", address_t{(int)x86.operands[0].imm, (int)x86.operands[1].imm}.linearOffset()));
                    text.push_back(assign(x86, "assert(cs == 0x%04x);", code.front()->mAddress.segment));
                    lastCompare = instr;
                    keepLastCompare = true;
                }
                else if (x86.op_count == 1 && x86.operands[0].type == X86_OP_MEM)
                {
                    text.push_back(assign(x86, "push(cs);"));
                    const auto sw = std::find_if(jumps.begin(), jumps.end(), [&](const switch_t& sw){
                        return sw.origin == instr->mAddress;
                    });
                    if (sw != jumps.end())
                    {
                        assert(sw->type == switch_t::CallDwords);
                        assert (x86.operands[0].type == X86_OP_MEM &&
                                x86.operands[0].size == 4 &&
                                x86.operands[0].mem.index == X86_REG_INVALID &&
                                x86.operands[0].mem.base == sw->selector &&
                                x86.operands[0].mem.scale == 1);

                        assert(!sw->elements.empty());
                        text.push_back(format("switch (%s)", sw->GetSelector().c_str()));
                        text.push_back("{");
                        for (int i : sw->elements)
                            text.push_back(sw->GetCase(i));
                        text.push_back("default:");
                        text.push_back("assert(0);");
                        text.push_back("}");
                    } else
                    // TODO: cs destroys cs in args!
                    if (assign(x86, "$rd0").find("cs") == std::string::npos)
                    {
                        text.push_back(assign(x86, "cs = $rns0;"));
                        if (x86.operands[0].size == 4)
                            text.push_back(assign(x86, "callIndirect($rd0);")); // not a full addr
                        else
                            text.push_back(assign(x86, "callIndirect(cs, $rd0);")); // not a full addr
                    } else {
                        text.push_back(assign(x86, "tx = cs;"));
                        text.push_back(assign(x86, "cs = $rns0;"));
                        if (x86.operands[0].size == 4)
                        {
                            if (segofs_in_comment)
                                text.push_back(replaceStr(assign(x86, "callIndirect($rd0); // %04x:%04x", instr->mAddress.segment, instr->mAddress.offset), "cs", "tx")); // not a full addr
                            else
                                text.push_back(replaceStr(assign(x86, "callIndirect($rd0);"), "cs", "tx")); // not a full addr
                        }
                        else
                            text.push_back(replaceStr(assign(x86, "callIndirect(cs, $rd0);"), "cs", "tx")); // not a full addr
                    }
                    text.push_back(assign(x86, "assert(cs == 0x%04x);", code.front()->mAddress.segment));
                }
                else
                    text.push_back(format("stop(); // %s %s", instr->mMnemonic, instr->mOperands));
//                text.push_back("pop();");
                break;
            case X86_INS_MOV:
                if (!(x86.op_count == 2 && x86.operands[0].size == x86.operands[1].size))
                {
                    text.push_back("stop(/*mov*/); ");
                    break;
                }
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
                        printf("// Discard check failed in sub_%04x: cur=%04x:%04x last=%04x:%04x> %s modifies %s\n", code[0]->mAddress.linearOffset(),
                               instr->mAddress.segment, instr->mAddress.offset,
                               lastCompare->mAddress.segment, lastCompare->mAddress.offset,
                               assign(lastCompare->mDetail, "$rd0").c_str(), assign(x86, "$rd0").c_str());
//                        assert(discards1 == discards2);
                    }
                    if (discards1)
                        lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::discard);
                }
                keepLastCompare = true;
                break;
            case X86_INS_LAHF:
                if (!lastCompare)
                {
                    text.push_back("stop(\"check carry and zero\");");
                } else {
                    lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::zero | (int)inject_t::carry);
                }
                text.push_back("ah = flags.carry | (flags.zero << 1);");
                break;
            case X86_INS_SAHF:
                text.push_back("flags.carry = ah & 1;");
                text.push_back("flags.zero = (ah >> 1) & 1;");
                lastCompare = instr;
                keepLastCompare = true;
                break;
            case X86_INS_RCR:
                // TODO: prev carry!
                //assert(lastCompare);
                //lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::carry);
                if (!lastCompare || (lastCompare->mId != X86_INS_RCR &&
                                     lastCompare->mId != X86_INS_STC &&
                                     lastCompare->mId != X86_INS_CLC &&
                                     lastCompare->mId != X86_INS_SAHF))
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
                keepLastCompare = true;
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
                    lastCompare = instr;
                    keepLastCompare = true;
                    break;
                }
                if (strcmp(instr->mMnemonic, "repe cmpsb") == 0 &&
                    strcmp(instr->mOperands, "byte ptr [si], byte ptr es:[di]") == 0)
                {
                    lastCompare = instr;
                    keepLastCompare = true;
                    text.push_back("repe_cmpsb<MemData, MemData, DirAuto>();");
                    break;
                }
                if (strcmp(instr->mMnemonic, "repne cmpsb") == 0 &&
                    strcmp(instr->mOperands, "byte ptr [si], byte ptr es:[di]") == 0)
                {
                    lastCompare = instr;
                    keepLastCompare = true;
                    text.push_back("repne_cmpsb<MemData, MemData, DirAuto>();");
                    break;
                }
                assert(0);
                break;
            case X86_INS_PUSHF:
                if (prevInstr && prevInstr->mId == X86_INS_POP)
                    text.push_back("stop(/*flag probing*/);");

                text.push_back("tx = flags.carry | (flags.zero << 1);");
                text.push_back("push(tx);");
                break;
            case X86_INS_POPF:
                if (prevInstr && prevInstr->mId == X86_INS_PUSH)
                    text.push_back("stop(/*flag probing*/);");

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
                
                if ((int)instr->mInject & (int)inject_t::carry)
                    text.push_back(assign(x86, "flags.carry = tl;"));

                lastCompare = instr;
                keepLastCompare = true;

                //text.push_back("dx = ax & 0x8000 ? 0xffff : 0x0000;");
                break;
            case X86_INS_INT3:
                break;
            case X86_INS_LEA:
            {
                if (!(x86.op_count == 2 && x86.operands[0].type == X86_OP_REG &&
                      x86.operands[1].type == X86_OP_MEM &&
                      x86.operands[1].size == 2 &&
                      x86.operands[1].reg == X86_REG_INVALID &&
                      x86.operands[1].mem.segment == X86_REG_INVALID &&
                      x86.operands[1].mem.index == X86_REG_INVALID))
                {
                    text.push_back("stop(); // lea!");
                    break;
                }
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
                    text.push_back(assign(x86, "$wr0 = bx - 0x%x;", -x86.operands[1].mem.disp));
                else if (x86.operands[1].mem.base == X86_REG_BX && x86.operands[1].mem.disp == 0)
                    text.push_back(assign(x86, "$wr0 = bx;", x86.operands[1].mem.disp));
                else
                {
                    assert(0);
                }
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
            case X86_INS_LJMP:
                if(x86.op_count == 2)
                {
                    assert(x86.operands[0].type == X86_OP_IMM);
                    assert(x86.operands[0].size == 2 && x86.operands[0].imm <= 0xffff);
                    assert(x86.operands[1].type == X86_OP_IMM && (x86.operands[1].size == 4 || x86.operands[1].size == 2) && x86.operands[1].imm <= 0xffff);
                    text.push_back(format("cs = 0x%04x;", x86.operands[0].imm));
                    text.push_back(format("callIndirect(0x%04x, 0x%04x);", x86.operands[0].imm, x86.operands[1].imm));
                    break;
                }
            case X86_INS_DAA:
                if (!lastCompare)
                    text.push_back("stop(/*inject carry*/);");
                else {
                    modified |= !((int)lastCompare->mInject & (int)inject_t::carry);
                    lastCompare->mInject = inject_t((int)lastCompare->mInject | (int)inject_t::carry);
                }
                text.push_back("daa();");
                break;
            case X86_INS_LEAVE:
                assert(x86.op_count == 0);
                text.push_back("sp = bp;");
                text.push_back("bp = pop();");
                break;
            case X86_INS_ENTER:
                assert(x86.op_count == 2);
                assert(x86.operands[0].imm > 0);
                assert(x86.operands[1].imm == 0);
                text.push_back("push(bp);");
                text.push_back("bp = sp;");
                text.push_back(format("sp -= 0x%x;", x86.operands[0].imm));
                break;

            case X86_INS_DAS:
            case X86_INS_SCASW:
            case X86_INS_FLD:
            case X86_INS_FMUL:
            case X86_INS_FIDIV:
            case X86_INS_BOUND:
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
                text.push_back(format("stop(); // %s %s PROBLEM-11", instr->mMnemonic, instr->mOperands));
//                assert(0);
        }

        if ((int)instr->mInject & (int)inject_t::tempPost)
        {
            assert(instr->mInject == inject_t::tempPost);
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

        if (injectLater != inject_t::none)
        {
            if ((int)instr->mInject & (int)inject_t::zero)
            {
                switch (instr->mId)
                {
                    case X86_INS_AND:
                    case X86_INS_OR:
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

        prevInstr = instr;
        if (!keepLastCompare)
            lastCompare.reset();
    }

    text.push_back(format("}"));

    for (const auto& instr : code)
        instr->mInject = inject_t((int)instr->mInject & ~(int)inject_t::discard);

    return modified;
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

std::list<address_t> parseMethods(MZHeader* header, const char* methods)
{
    std::list<address_t> list;
    if (!methods)
        return list;
    
    std::istringstream is(methods);
    std::string token;
    std::regex functionHex("^([0-9a-fA-f]+)$");
    std::regex functionSegofs("^([0-9a-fA-f]+):([0-9a-fA-f]+)$");
    std::regex functionName("^sub_([0-9a-fA-f]+)$");
    // functionInjects.insert(std::pair<address_t, inject_t>(targetAddr, injectReturn));

    // tokenize by comma
    while (getline(is, token, ','))
    {
        inject_t inject = inject_t::none;
        if (token.find("+carry") != std::string::npos)
        {
            token = replaceStr(token, "+carry", "");
            inject = inject_t((int)inject | (int)inject_t::returnCarry);
        }
        if (token.find("+zero") != std::string::npos)
        {
            token = replaceStr(token, "+zero", "");
            inject = inject_t((int)inject | (int)inject_t::returnZero);
        }
        if (token.find("+sync") != std::string::npos)
        {
            token = replaceStr(token, "+sync", "");
            inject = inject_t((int)inject | (int)inject_t::callsSync);
        }
//            functionInjects.insert(std::pair<address_t, inject_t>(targetAddr, injectReturn));
        std::smatch matches;
        
        if (token == "start")
        {
            assert(header);
            list.push_back({header->cs+_loadBase, header->ip});
        }
        else if (std::regex_search(token, matches, functionHex))
        {
            std::string strAddr = matches.str(1);
            int addr = (int)strtol(strAddr.c_str(), nullptr, 16);
            int addrSeg = _cs;
            int addrOfs = addr - addrSeg*16;
            assert(addrOfs >= 0 && addrOfs < 0xffff);
            list.push_back({addrSeg, addrOfs});
        } else if (std::regex_search(token, matches, functionSegofs))
        {
            std::string strSeg = matches.str(1);
            std::string strOfs = matches.str(2);
            int addrSeg = (int)strtol(strSeg.c_str(), nullptr, 16);
            int addrOfs = (int)strtol(strOfs.c_str(), nullptr, 16);
            list.push_back({addrSeg, addrOfs});
        } else if (std::regex_search(token, matches, functionName))
        {
            std::string strAddr = matches.str(1);
            int addr = (int)strtol(strAddr.c_str(), nullptr, 16);
            int addrSeg = _cs;
            int addrOfs = addr - addrSeg*16;
            assert(addrOfs >= 0 && addrOfs < 0xffff);
            list.push_back({addrSeg, addrOfs});
        } else
            assert(0);
        
        if (inject != inject_t::none)
        {
            assert(functionInjects.find(list.back()) == functionInjects.end());
            functionInjects.insert(std::pair<address_t, inject_t>(list.back(), inject));
        }
    }
    return list;
}

int main(int argc, const char * argv[]) {
    const char* executable = nullptr;
    const char* methods = nullptr;
    const char* indirects = nullptr;
    const char* output = nullptr;
    bool outputFolder = false;
    int outputLimit = 0;
    const char* resume = nullptr;
    bool recursive = false;
    bool lines = false;
    bool printctx = false;
    const char* extraLabelsStr = nullptr;
    std::vector<switch_t> jumpTables;
    address_t dumpRawAddress;
    int dumpRawEntries = 0;
    int dumpRawSize = 2;
    const char* dynamics = nullptr;

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
                const char* strJumpEntries = argv[++i];

                std::vector<int> jumpEntries;
                if (strstr(strJumpEntries, "-"))
                {
                    int jumpTableEntriesBegin = (int)strtol(strJumpEntries, nullptr, 10);
                    strJumpEntries = strstr(strJumpEntries, "-")+1;
                    int jumpTableEntriesEnd = (int)strtol(strJumpEntries, nullptr, 10);
                    for (int i=jumpTableEntriesBegin; i<=jumpTableEntriesEnd; i++)
                        jumpEntries.push_back(i);
                } else
                {
                    int jumpTableEntries = (int)strtol(strJumpEntries, nullptr, 10);
                    for (int i=0; i<jumpTableEntries; i++)
                        jumpEntries.push_back(i);
                }
                
                const char* jumpTableEntryType = argv[++i];
                
                switch_t::switch_e tableType = switch_t::switch_e::None;
                if (strcmp(jumpTableEntryType, "jumpwords") == 0)
                    tableType = switch_t::switch_e::JumpWords;
                if (strcmp(jumpTableEntryType, "callwords") == 0)
                    tableType = switch_t::switch_e::CallWords;
                if (strcmp(jumpTableEntryType, "calldwords") == 0)
                    tableType = switch_t::switch_e::CallDwords;
                if (strcmp(jumpTableEntryType, "jumpfix") == 0)
                    tableType = switch_t::switch_e::JumpFix;
                if (strcmp(jumpTableEntryType, "call") == 0)
                    tableType = switch_t::switch_e::Call;
                if (strcmp(jumpTableEntryType, "callwordsbyofs") == 0)
                    tableType = switch_t::switch_e::CallWordsByOfs;
                assert(tableType != switch_t::switch_e::None);
                
                const char* jumpSelector = argv[++i];
                
                x86_reg index = X86_REG_INVALID;
                if (strcmp(jumpSelector, "bx") == 0)
                    index = X86_REG_BX;
                else if (strcmp(jumpSelector, "di") == 0)
                    index = X86_REG_DI;
                else if (strcmp(jumpSelector, "bp") == 0)
                    index = X86_REG_BP;
                else if (strcmp(jumpSelector, "ax") == 0)
                    index = X86_REG_AX;
                else if (strcmp(jumpSelector, "si") == 0)
                    index = X86_REG_SI;
                else if (strcmp(jumpSelector, "none") == 0)
                    index = X86_REG_INVALID;
                else if (strcmp(jumpSelector, "indirect") == 0)
                    index = X86_REG_INVALID;
                else
                    assert(0);
                if (strcmp(jumpSelector, "indirect") == 0)
                    jumpTables.push_back({indirectJumpAddr, jumpTableBegin, jumpEntries, tableType, index, nullptr});
                else
                    jumpTables.push_back({indirectJumpAddr, jumpTableBegin, jumpEntries, tableType, index, nullptr});
            }
            else if (strcmp(arg, "-raw") == 0)
            {
                const char* rawType = argv[++i];
                if (strcmp(rawType, "words") == 0)
                    dumpRawSize = 2;
                else if (strcmp(rawType, "dwords") == 0)
                    dumpRawSize = 4;
                else
                    assert(0);
                
                address_t rawAddress = address_t::fromString(argv[++i]);
                int rawEntries = atoi(argv[++i]);
                
                dumpRawAddress = rawAddress;
                dumpRawEntries = rawEntries;
            }
            else if (strcmp(arg, "-terminator") == 0)
                _terminators.insert(address_t::fromString(argv[++i]).linearOffset());
            else if (strcmp(arg, "-simplestack") == 0)
                _simpleStack = true;
            else if (strcmp(arg, "-indirect") == 0)
                indirects = argv[++i];
            else if (strcmp(arg, "-coverage") == 0)
                _coverage = true;
            else if (strcmp(arg, "-trace") == 0)
                _trace = true;
            else if (strcmp(arg, "-disasm") == 0)
            {
//                methods = argv[i+1];
                address_t disasmAddress = address_t::fromString(argv[++i]);
                disasmAddressSeg = disasmAddress.segment;
                disasmAddressOfs = disasmAddress.offset;
                
                const char* code = argv[++i];
                while (*code) {
                    if (isspace(*code)) {
                        code++;
                        continue;
                    }
                    int nbyte;
                    if (sscanf(code, "%2x", &nbyte) != 1)
                        assert(0);
                    disasmBytes.push_back(nbyte);
                    code += 2;
                }
            }
            else if (strcmp(arg, "-dynamic") == 0)
                dynamics = argv[++i];
            else if (strcmp(arg, "-negative") == 0)
                negativeoffset = atoi(argv[++i]);
            else if (strcmp(arg, "-tree") == 0)
                _dumpTree = true;
            else if (strcmp(arg, "-32bit") == 0)
                _bit32 = true;
            else
                assert(0);
        } else {
            if (!executable)
                executable = arg;
            else if (!methods)
                methods = arg;
            else
                assert(0);
        }
    }

    std::vector<char> buffer;
    MZHeader* header = nullptr;
    std::vector<std::pair<address_t, address_t>> extraLabels;
    FILE* fout = stdout;
    
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

    if (disasmAddressSeg == -1)
    {
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
        
        buffer.resize(size);
        if (!file.read(buffer.data(), size))
            throw "problem";
        
        header = (MZHeader*)&buffer[0];
        assert(header->id[0] == 'M' && header->id[1] == 'Z');
        
        if (outputLimit)
            fout = fopen(format("%s%s", output, ".h").c_str(), "w");
        else if (output && !outputFolder)
            fout = fopen(output, "w");
                
        _linearToFileOffset = 16*_loadBase - header->headerSize16*0x10;
                
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
            
            if (_dumpReloc)
                fprintf(fout, "void fixReloc(uint16_t seg);\n");
            
            if (_coverage)
            {
                fprintf(fout, "\n// info: executable %s/%s\n", execPath.c_str(), execName.c_str());
                fprintf(fout, "// info: arguments");
                for (int i=1; i<argc; i++)
                    fprintf(fout, " %s", argv[i]);
                fprintf(fout, "\n");
                fprintf(fout, "// info: linearToFile 0x%x", _linearToFileOffset);
            }
            
            fprintf(fout, R"(
void start()
{
    headerSize = 0x%04x;
    loadAddress = 0x%04x;
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
                    _loadBase,
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
        if (_coverage)
        {
            printf("%s// coverage: 0x%x-0x%x header\n", _dumpReloc ? "    " : "", 0, (int)sizeof(MZHeader));
            printf("%s// coverage: 0x%x-0x%x reloc\n", _dumpReloc ? "    " : "", header->relocationOffset, header->relocationOffset + header->relocations*4);
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
    }

    Capstone cap;
    if (disasmAddressSeg != -1)
    {
        address_t disasmAddress{disasmAddressSeg, disasmAddressOfs};
        _linearToFileOffset = disasmAddress.linearOffset();
        cap.Set(disasmBytes, _linearToFileOffset);
    } else {
        cap.Set(buffer, _linearToFileOffset);
    }
        
    if (dumpRawAddress.isValid())
    {
        printf("Dumping %d words starting %04x:%04x\n", dumpRawEntries, dumpRawAddress.segment, dumpRawAddress.offset);
        const uint16_t* buf = (const uint16_t*)cap.GetBufferAt(dumpRawAddress);
        if (!buf)
        {
            printf("Wrong address");
            return 1;
        }
        for (int i=0; i<dumpRawEntries; i++)
            if (dumpRawSize==2)
                printf("%2d. %04x:%04x = %04x\n", i, dumpRawAddress.segment, dumpRawAddress.offset+i*dumpRawSize, buf[i]);
            else
                printf("%2d. %04x:%04x = %04x:%04x\n", i, dumpRawAddress.segment, dumpRawAddress.offset+i*dumpRawSize, buf[i*2+1], buf[i*2]);
        return 0;
    }
    if (!methods)
    {
        printf("Nothing to do\n");
        return 0;
    }

    std::map<address_t, function_t, cmp_adress_t> processed;
    std::vector<address_t> failed;
    std::list<address_t> toProcess = parseMethods(header, methods);
    std::list<address_t> toIndirects = parseMethods(header, indirects);
    std::list<address_t> toDynamic = parseMethods(header, dynamics);

    toProcess.merge(std::list{toIndirects});
    std::vector<switch_t> switches;
    std::vector<switch_t> jumps;
    
    std::map<address_t, std::set<address_t>> callTreeChildren;
    std::map<address_t, std::set<address_t>> callTreeParent;

    for (switch_t& s : jumpTables)
    {
        s.baseptr = cap.GetBufferAt(s.begin);
        jumps.push_back(s);
    }
    
    for (const switch_t& table : jumpTables)
    {
        if (table.type == switch_t::switch_e::CallWords || table.type == switch_t::switch_e::CallDwords || table.type == switch_t::switch_e::Call || table.type == switch_t::switch_e::CallWordsByOfs)
        {
            for (int i : table.elements)
                toProcess.push_back(table.GetTarget(i));
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

            std::vector<std::shared_ptr<CapInstr>> code;
            if (!ExtractMethod(cap, method, code, jumps, inject_t::none, extraLabels, toDynamic))
            {
                //assert(0);
                printf("Conversion of %04x:%04x failed!\n", method.segment, method.offset);
                
                if (verbose_asm)
                {
                    printf("\nAssembly listing of failed %04x:%04x sub_%x()\n", method.segment, method.offset,
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
                assert(method == code[0]->mAddress);
                std::list<address_t> foundCalls;
                FindCalls(code, foundCalls, jumps);
                for (const address_t& found : foundCalls)
                    if (std::find(toProcess.begin(), toProcess.end(), found) == toProcess.end())
                        toProcess.push_back(found);
                //toProcess.insert(toProcess.end(), foundCalls.begin(), foundCalls.end());
                
                for (const address_t& child : foundCalls)
                {
                    // Children which are called by method
                    auto pSet = callTreeChildren.find(method);
                    if (pSet == callTreeChildren.end())
                        callTreeChildren.insert({method, {child}});
                    else
                        pSet->second.insert(child);

                    // Parents calling this method
                    pSet = callTreeParent.find(child);
                    if (pSet == callTreeParent.end())
                        callTreeParent.insert({child, {method}});
                    else
                        pSet->second.insert(method);
                }
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
        
    if (!outputFolder)
        for (const auto& decl : processed)
            fprintf(fout, "void sub_%x();\n", decl.second.begin.linearOffset());
     
    bool anyIndirectTable = false;
    for (const switch_t& table : jumpTables)
    {
        if (table.type == switch_t::switch_e::CallWords && table.origin.offset == (uint16_t)-1)
        {
            if (!anyIndirectTable)
            {
                fprintf(fout, "\n");
                fprintf(fout, "#ifdef callIndirect\n");
                fprintf(fout, "#undef callIndirect\n");
                fprintf(fout, "#endif\n");
                fprintf(fout, "\n");
                fprintf(fout, "void callIndirect(int seg, int ofs)\n");
                fprintf(fout, "{\n");
                anyIndirectTable = true;
            }
            fprintf(fout, "    if(seg == 0x%04x)\n", table.origin.segment);
            fprintf(fout, "    switch (ofs)\n");
            fprintf(fout, "    {\n");
            std::map<int, int> used;
            if (_coverage)
            {
                fprintf(fout, "        // coverage: 0x%x-0x%x switch\n", table.GetBaseAddress().fileOffset(), table.GetBaseAddress().fileOffset() + table.elements.back() * table.GetSize());
            }

            for (int i : table.elements)
            {
                int v = table.GetTarget(i).offset;
                if (used.find(v) != used.end())
                    continue;
                used.insert(std::pair<int, int>(v, 0));
                fprintf(fout, "        case 0x%x: sub_%x(); return;\n", table.GetTarget(i).offset, table.GetTarget(i).linearOffset());
            }
            fprintf(fout, "        default:\n");
            fprintf(fout, "            break;\n");
            fprintf(fout, "    }\n");
        }
    }
    if (toIndirects.size())
    {
        if (!anyIndirectTable)
        {
            fprintf(fout, "\n");
            fprintf(fout, "#ifdef callIndirect\n");
            fprintf(fout, "#undef callIndirect\n");
            fprintf(fout, "#endif\n");
            fprintf(fout, "\n");
            fprintf(fout, "void callIndirect(int seg, int ofs)\n");
            fprintf(fout, "{\n");
            anyIndirectTable = true;
        }
        fprintf(fout, "    switch (seg*0x10000+ofs)\n");
        fprintf(fout, "    {\n");
        toIndirects.sort([](const address_t& a, const address_t& b) {
                return a.linearOffset() < b.linearOffset();
        });
        address_t last;
        for (address_t i : toIndirects)
        {
            if (i.linearOffset() == last.linearOffset())
                continue;
            last = i;
            fprintf(fout, "        case 0x%x: sub_%x(); return;\n", i.segment*0x10000+i.offset, i.linearOffset());
        }
        fprintf(fout, "        default:\n");
        fprintf(fout, "            break;\n");
        fprintf(fout, "    }\n");

    }
    if (anyIndirectTable)
    {
        fprintf(fout, "    assert(0);\n");
        fprintf(fout, "}\n");
    }

    // collect notices, TODO: check
    for (const auto& decl : processed)
    {
        std::vector<std::string> text;
        std::vector<std::shared_ptr<CapInstr>> code;
        if (!ExtractMethod(cap, decl.first, code, jumps, inject_t::none, extraLabels, toDynamic))
            assert(0);
        if (_trace)
            printf("trace: %02x:%02x sub_%x()\n", decl.first.segment, decl.first.offset,
               decl.first.segment*16+decl.first.offset);
        DumpCodeAsC(code, text, switches, jumps);
    }

    gNeedToRerun = true;
    while (gNeedToRerun)
    {
        gNeedToRerun = false;
        for (const auto& decl : processed)
        {
            std::vector<std::shared_ptr<CapInstr>> code;
            auto injectptr = functionInjects.find(decl.first);
            inject_t inject = injectptr != functionInjects.end() ? injectptr->second : inject_t::none;

            if (!ExtractMethod(cap, decl.first, code, jumps, inject, extraLabels, toDynamic))
                assert(0);
        }
    }

    // propagate sync flag to parent
    bool retry = true;
    while (retry)
    {
        retry = false;
        for (const auto& tree : callTreeParent)
        {
            auto injectptr = functionInjects.find(tree.first);
            inject_t inject = injectptr != functionInjects.end() ? injectptr->second : inject_t::none;
            if ((int)inject & (int)inject_t::callsSync)
            {
                for (const auto& child : tree.second)
                    retry |= CTracer::functionInjectsAdd(child, inject_t::callsSync);
            }
        }
    }

    // dump
    for (const auto& decl : processed)
    {
        std::vector<std::shared_ptr<CapInstr>> code;
        auto injectptr = functionInjects.find(decl.first);
        inject_t inject = injectptr != functionInjects.end() ? injectptr->second : inject_t::none;

        if (!ExtractMethod(cap, decl.first, code, jumps, inject, extraLabels, toDynamic))
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
            FindCalls(code, imports, jumps);

            for (const switch_t& lsw : localswitches)
            {
                const auto sw = std::find_if(switches.begin(), switches.end(), [&](const switch_t& sw){
                    return sw.origin == lsw.origin;
                });
                if (sw != switches.end() && !sw->elements.empty())
                {
                    for (int i : sw->elements)
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
        if (verbose_asm)
        {
            fprintf(fout, "/* Assembly listing of %04x:%04x sub_%x()\n", decl.first.segment, decl.first.offset,
                   decl.first.segment*16+decl.first.offset);
            fprintf(fout, "            sub_%x PROC\n", decl.first.linearOffset());
            for (const auto& instr : code)
                instr->Dump();
            fprintf(fout, "            sub_%x ENDP\n", decl.first.linearOffset());
            fprintf(fout, "*/\n");
        }

        PrintFormatted(fout, text);
        finishWriting();
    }
    
    if (_dumpTree)
    {
        for (const auto& tree : callTreeChildren)
        {
            fprintf(fout, "// tree: children of sub_%x %s: ", tree.first.linearOffset(), functionAnnotation(tree.first).c_str());
            for (const auto& child : tree.second)
                fprintf(fout, "sub_%x %s, ", child.linearOffset(), functionAnnotation(child).c_str());
            fprintf(fout, "\n");
        }
        for (const auto& tree : callTreeParent)
        {
            fprintf(fout, "// tree: parents of sub_%x %s: ", tree.first.linearOffset(),  functionAnnotation(tree.first).c_str());
            for (const auto& child : tree.second)
                fprintf(fout, "sub_%x %s, ", child.linearOffset(), functionAnnotation(child).c_str());
            fprintf(fout, "\n");
        }
    }
    fclose(fout);

    return 0;
}

// 2461 -> 5261
