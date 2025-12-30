//
//  operand.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 09/12/2025.
//

class OperandIr {
public:
    enum class Type_t {
        Const,
        Register,
        Memory,
        String,
        Operator,
        Variable,
    } type;
    
    // const
    int constValue{0};
    int constSize{0};
    
    // register
    std::string regName;
    int regSize{0};
    
    // memory
    std::string memSegment;
    std::string memOfsBase;
    std::string memOfsIndex;
    int memOfsScale{0};
    int memOfsDisp{0};
    int memSize{0};
    
    // string
    std::string string;
    
    // operator
    std::string oper;
    
    // variable
    std::string variable;
    
    explicit OperandIr(cs_x86_op op)
    {
        switch (op.type)
        {
            case X86_OP_REG:
                type = Type_t::Register;
                regName = Capstone->ToString(op);
                regSize = op.size;
                break;
            case X86_OP_IMM:
                type = Type_t::Const;
                constValue = (int)op.imm;
                constSize = op.size;
                break;
            case X86_OP_MEM:
                type = Type_t::Memory;
                memSize = op.size;
                if (op.mem.segment != X86_REG_INVALID)
                    memSegment = Capstone->ToString(op.mem.segment);
                else if (op.mem.base == X86_REG_BP)
                    memSegment = Capstone->ToString(X86_REG_SS);
                else
                    memSegment = Capstone->ToString(X86_REG_DS);
                
                memOfsBase = op.mem.base != X86_REG_INVALID ? Capstone->ToString(op.mem.base) : "";
                memOfsIndex = op.mem.index != X86_REG_INVALID ? Capstone->ToString(op.mem.index) : "";
                memOfsScale = op.mem.scale;
                memOfsDisp = (int)op.mem.disp;
                break;
            case X86_OP_INVALID:
                assert(0);
                break;
            default:
                assert(0);
        }
    }
    
    explicit OperandIr(Type_t type, std::string s) : type(type)
    {
        switch (type)
        {
//            case Type_t::Register:
//                assert(0);
//                regName = s;
//                switch (regName[1])
//                {
//                    case 'x':
//                        regSize = 2;
//                        break;
//                    case 'h':
//                    case 'l':
//                        regSize = 1;
//                        break;
//                }
//                break;
            case Type_t::Operator:
                oper = s;
                break;
            case Type_t::String:
                string = s;
                break;
            case Type_t::Variable:
                variable = s;
                break;
            default:
                assert(0);
        }
    }
    explicit OperandIr(Type_t type, std::string s, int size) : type(type)
    {
        switch (type)
        {
            case Type_t::Register:
                assert(size);
                regName = s;
                regSize = size;
                break;
            default:
                assert(0);
        }
    }

    explicit OperandIr(Type_t type, int v, int size = 0) : type(type)
    {
        switch (type)
        {
            case Type_t::Const:
                constValue = v;
                constSize = size;
                break;
            default:
                assert(0);
        }
    }
};
