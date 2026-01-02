//
//  builder.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 09/12/2025.
//

// Helper builder classes for fluent interface
class OperandBuilder {
private:
    shared<OperandIr> operand;
    
public:
    explicit OperandBuilder(shared<OperandIr> op) : operand(op) {}
    
    shared<OperandIr> get() const { return operand; }
};

class StatementBuilder {
private:
    shared<StatementIr> statement;
    
public:
    StatementBuilder() : statement(std::make_shared<StatementIr>()) {}
    explicit StatementBuilder(shared<StatementIr> stmt) : statement(stmt) {}
    
    shared<StatementIr> get() const { return statement; }
    
    // Convert to StatementIr
    operator StatementIr() const { return *statement; }
};

// Helper functions to create operands
inline OperandBuilder OP_VAR(const std::string& name) {
    return OperandBuilder(std::make_shared<OperandIr>(OperandIr::Type_t::Variable, name));
}

inline OperandBuilder OP_OP(const std::string& op) {
    return OperandBuilder(std::make_shared<OperandIr>(OperandIr::Type_t::Operator, op));
}

inline OperandBuilder OP_CONST(int value, int size = 0) {
    return OperandBuilder(std::make_shared<OperandIr>(OperandIr::Type_t::Const, value, size));
}

inline OperandBuilder OP_REG(const std::string& reg, int size) {
    return OperandBuilder(std::make_shared<OperandIr>(OperandIr::Type_t::Register, reg, size));
}

inline OperandBuilder OP_STR(const std::string& str) {
    return OperandBuilder(std::make_shared<OperandIr>(OperandIr::Type_t::String, str));
}

// Helper to extract x86 operand from capstone instruction
inline OperandBuilder OP_X86(shared<CapInstr> instr, int index) {
    assert(index >= 0 && index < instr->mDetail.op_count);
    return OperandBuilder(std::make_shared<OperandIr>(instr->mDetail.operands[index]));
}

inline OperandBuilder OP_X86(cs_x86_op op) {
    return OperandBuilder(std::make_shared<OperandIr>(op));
}

// Unary operator: ! prefix for OperandBuilder
inline StatementBuilder operator!(const OperandBuilder& operand) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->oper = "!";
    stmt->opin1 = operand.get();
    return StatementBuilder(stmt);
}

// Unary operator: - prefix for OperandBuilder (negation)
inline StatementBuilder operator-(const OperandBuilder& operand) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->oper = "-";
    stmt->opin1 = operand.get();
    return StatementBuilder(stmt);
}

// Unary operator: ~ prefix for OperandBuilder (bitwise NOT)
inline StatementBuilder operator~(const OperandBuilder& operand) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->oper = "~";
    stmt->opin1 = operand.get();
    return StatementBuilder(stmt);
}

// Unary operator: ! prefix for StatementBuilder
inline StatementBuilder operator!(const StatementBuilder& statement) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->oper = "!";
    stmt->stmt1 = statement.get();
    return StatementBuilder(stmt);
}

// Binary operators between operands
inline StatementBuilder operator&&(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "&&";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator||(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "||";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Binary operators between statements
inline StatementBuilder operator&&(const StatementBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = "&&";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator||(const StatementBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = "||";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

// Mixed: statement && operand
inline StatementBuilder operator&&(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = "&&";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator||(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = "||";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Mixed: operand && statement
inline StatementBuilder operator&&(const OperandBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "&&";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator||(const OperandBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "||";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

// Assignment operator (creates assignment statement)
// Usage: ASSIGN(OP_VAR("x"), OP_CONST(5))
inline StatementBuilder ASSIGN(const OperandBuilder& dest, const OperandBuilder& src) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Assignment;
    stmt->opd = dest.get();
    stmt->opin1 = src.get();
    return StatementBuilder(stmt);
}

// Assignment operator overload for StatementBuilder as source
// Usage: ASSIGN(OP_VAR("x"), some_statement)
inline StatementBuilder ASSIGN(const OperandBuilder& dest, const StatementBuilder& src) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Assignment;
    stmt->opd = dest.get();
    stmt->stmt1 = src.get();
    return StatementBuilder(stmt);
}

// Comparison operators (unsigned by default)
inline StatementBuilder operator==(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->opin1 = left.get();
    stmt->oper = "==";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator!=(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->opin1 = left.get();
    stmt->oper = "!=";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator>(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->opin1 = left.get();
    stmt->oper = ">";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator<(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->opin1 = left.get();
    stmt->oper = "<";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator<(const OperandBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->opin1 = left.get();
    stmt->oper = "<";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator>=(const StatementBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = ">=";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator>(const StatementBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = ">";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator>=(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->opin1 = left.get();
    stmt->oper = ">=";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator<=(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->opin1 = left.get();
    stmt->oper = "<=";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Modifier class for applying modifications to statements
class StatementModifier {
private:
    std::vector<std::string> modTypes;
    std::function<int()> suffixComputer; // Lambda to compute suffix dynamically
    
public:
    explicit StatementModifier(const std::string& type) : modTypes({type}), suffixComputer(nullptr) {}
    explicit StatementModifier(const std::string& type1, const std::string& type2) : modTypes({type1, type2}), suffixComputer(nullptr) {}
    explicit StatementModifier(const std::string& type, std::function<int()> suffixFunc) : modTypes({type}), suffixComputer(suffixFunc) {}
    
    // Apply modifier to a StatementBuilder
    StatementBuilder apply(const StatementBuilder& builder) const {
        auto stmt = builder.get();
        
        // Apply suffix if provided
        if (suffixComputer) {
            stmt->suffix = suffixComputer();
        }
        
        // Apply each modifier in sequence
        for (const auto& modType : modTypes) {
            if (modType == "assign") {
                // Convert Binary expression to Assignment with compound operation
                // e.g., (a + b) with "assign" becomes a = a + b (stored as Binary type with opd)
                if (stmt->type == StatementIr::Type_t::Binary && !stmt->opd) {
                    // This is a binary expression, convert to compound assignment
                    // opd = destination (left operand), opin1 = left, oper = operator, opin2 = right
                    if (stmt->opin1) {
                        stmt->opd = stmt->opin1; // destination is the left operand
                    }
                }
                // TODO: bad, it should be assignment initially
                // Convert Unary expression to Assignment with unary operation
                // e.g., (-a) with "assign" becomes a = -a (stored as Assignment type)
                else if (stmt->type == StatementIr::Type_t::Unary && !stmt->opd) {
                    if (stmt->opin1) {
                        // Create an assignment: opd = unary(opin1)
                        auto unaryStmt = std::make_shared<StatementIr>(*stmt); // copy the unary operation
                        stmt->type = StatementIr::Type_t::Assignment;
                        stmt->opd = stmt->opin1; // destination is the operand
                        stmt->stmt1 = unaryStmt; // the unary operation becomes a sub-statement
                        stmt->opin1.reset(); // clear the operand from the assignment level
                        stmt->oper.clear(); // clear the operator from the assignment level
                    }
                }
                // For Function type with "assign", set opd to opin1
                else if (stmt->type == StatementIr::Type_t::Function && !stmt->opd) {
                    if (stmt->opin1) {
                        stmt->opd = stmt->opin1; // destination is the first operand
                    }
                }
            } else if (modType == "decimm") {
                // Mark immediate operands to be printed as decimal instead of hexadecimal
                assert(stmt->opin2);
                stmt->opin2->constSize = 0;
            } else
                assert(0);
        }
        
        return StatementBuilder(stmt);
    }
    
    std::string getType() const { return modTypes.empty() ? "" : modTypes[0]; }
};

// Helper function to create modifiers (one or two modifiers)
inline StatementModifier OP_MOD(const std::string& modifierType) {
    return StatementModifier(modifierType);
}

inline StatementModifier OP_MOD(const std::string& modifierType1, const std::string& modifierType2) {
    return StatementModifier(modifierType1, modifierType2);
}

// Helper function to create modifier with suffix computer
inline StatementModifier OP_MOD(const std::string& modifierType, std::function<int()> suffixFunc) {
    return StatementModifier(modifierType, suffixFunc);
}

// Operator << to apply modifier to statement
inline StatementBuilder operator<<(const StatementModifier& mod, const StatementBuilder& stmt) {
    return mod.apply(stmt);
}

// Arithmetic operators between operands
inline StatementBuilder operator+(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "+";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator-(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "-";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Arithmetic operators between StatementBuilder and OperandBuilder (for chaining)
inline StatementBuilder operator+(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = "+";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator-(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = "-";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Arithmetic operators between two StatementBuilders
inline StatementBuilder operator+(const StatementBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = "+";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator-(const StatementBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = "-";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

// Comparison operators for StatementBuilder (left side)
inline StatementBuilder operator>=(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = ">=";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator<=(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = "<=";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator<=(const StatementBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = "<=";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}


inline StatementBuilder operator<(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = "<";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator<(const StatementBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = "<";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator>(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = ">";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}


inline StatementBuilder operator==(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = "==";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator!=(const StatementBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Compare;
    stmt->stmt1 = left.get();
    stmt->oper = "!=";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Helper function to create binary operations with custom operators
inline StatementBuilder OP_BINARY(const OperandBuilder& left, const std::string& op, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = op;
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Overload for OP_BINARY with StatementBuilder on both sides
inline StatementBuilder OP_BINARY(const StatementBuilder& left, const std::string& op, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = op;
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

// Overload for OP_BINARY with StatementBuilder on the left and OperandBuilder on the right
inline StatementBuilder OP_BINARY(const StatementBuilder& left, const std::string& op, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->stmt1 = left.get();
    stmt->oper = op;
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Overload for OP_BINARY with OperandBuilder on the left and StatementBuilder on the right
inline StatementBuilder OP_BINARY(const OperandBuilder& left, const std::string& op, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = op;
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

// Helper function to create unary operations with custom operators
inline StatementBuilder OP_UNARY(const std::string& op, const OperandBuilder& operand) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->oper = op;
    stmt->opin1 = operand.get();
    return StatementBuilder(stmt);
}

// Overload for OP_UNARY with StatementBuilder
inline StatementBuilder OP_UNARY(const std::string& op, const StatementBuilder& statement) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->oper = op;
    stmt->stmt1 = statement.get();
    return StatementBuilder(stmt);
}

// Helper function to create a signed cast expression
// Usage: OP_SIGNED(OP_X86(instr, 0)) creates a unary cast to signed type
inline StatementBuilder OP_SIGNED(const OperandBuilder& operand) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->opin1 = operand.get();
    stmt->oper = "signed";
    return StatementBuilder(stmt);
}

// Overload for OP_SIGNED with StatementBuilder
inline StatementBuilder OP_SIGNED(const StatementBuilder& statement) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->stmt1 = statement.get();
    stmt->oper = "signed";
    return StatementBuilder(stmt);
}

// Helper function to create function call statements
inline StatementBuilder OP_FUNCTION(const std::string& funcName, const OperandBuilder& arg1, const OperandBuilder& arg2) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Function;
    if (!funcName.ends_with("#"))
        stmt->func = funcName;
    else {
        stmt->func = funcName.substr(0, funcName.size()-1);
        stmt->suffix = (arg1.get()->regSize + arg1.get()->memSize)*8;
    }
    stmt->opin1 = arg1.get();
    stmt->opin2 = arg2.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder OP_FUNCTION(const std::string& funcName, const OperandBuilder& arg1) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Function;
    if (!funcName.ends_with("#"))
        stmt->func = funcName;
    else {
        stmt->func = funcName.substr(0, funcName.size()-1);
        stmt->suffix = (arg1.get()->regSize + arg1.get()->memSize)*8;
    }
    stmt->opin1 = arg1.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder OP_FUNCTION(const std::string& funcName) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Function;
    stmt->func = funcName;
    return StatementBuilder(stmt);
}

// Bitwise shift operators between operands
inline StatementBuilder SHL(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "<<";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder SHR(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = ">>";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Bitwise OR operator between operands (separate from logical OR)
inline StatementBuilder BIT_OR(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "|";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

// Bitwise AND operator between operands
inline StatementBuilder operator&(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "&";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator&(const OperandBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "&";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

// Bitwise OR operator between operands
inline StatementBuilder operator|(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "|";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator|(const OperandBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "|";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

// Bitwise XOR operator between operands
inline StatementBuilder operator^(const OperandBuilder& left, const OperandBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "^";
    stmt->opin2 = right.get();
    return StatementBuilder(stmt);
}

inline StatementBuilder operator^(const OperandBuilder& left, const StatementBuilder& right) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Binary;
    stmt->opin1 = left.get();
    stmt->oper = "^";
    stmt->stmt2 = right.get();
    return StatementBuilder(stmt);
}

// NOTE: always prefix operator
inline StatementBuilder operator--(OperandBuilder& operand) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->oper = "--";
    stmt->opin1 = operand.get();
    return StatementBuilder(stmt);
}

// Prefix increment operator ++ creates a unary statement
inline StatementBuilder operator++(OperandBuilder& operand) {
    auto stmt = std::make_shared<StatementIr>();
    stmt->type = StatementIr::Type_t::Unary;
    stmt->oper = "++";
    stmt->opin1 = operand.get();
    return StatementBuilder(stmt);
}

// Helper to create a comparison statement (truthiness check)
// Usage: COMPARE(--OP_REG("cx")) creates a Compare statement
inline StatementBuilder COMPARE(const StatementBuilder& stmt) {
    auto compare = std::make_shared<StatementIr>();
    compare->type = StatementIr::Type_t::Compare;
    compare->stmt1 = stmt.get();
    return StatementBuilder(compare);
}

// Overload to accept OperandBuilder for truthiness check
// Usage: COMPARE(OP_VAR("flags.zero")) creates a Compare statement
inline StatementBuilder COMPARE(const OperandBuilder& operand) {
    auto compare = std::make_shared<StatementIr>();
    compare->type = StatementIr::Type_t::Compare;
    compare->opin1 = operand.get();
    return StatementBuilder(compare);
}
