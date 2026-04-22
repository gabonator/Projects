//
//  statement.h
//  cicodis-clean
//
//  Created by Gabriel Valky on 09/12/2025.
//

class StatementIr {
public:
    enum class Type_t {
        None,
        Assignment, // op1 = op2
        Compare, // op1 > op2
        Copy, // op1
        Unary, // op1 = !op2
        Binary, // op1 = op2 +- op3
        Function, // func(op1)?
        Condition, // if (StatementIr) StatementIr
        Stop, // stop(stop)
        DirectCall, // op1()
        DirectCallLong, // TODO: remove
        IndirectCall,
        IndirectCallLong,
        DirectJump, // op1()
        IndirectJump,
        Label, // op1:
        Switch, // switch(selector) { case const: long/far call/jump }
        Comment, // // comment
        Return,
        Dereference // op1:op2
    } type{Type_t::None};

    shared<OperandIr> opd;
    shared<OperandIr> opin1;
    shared<OperandIr> opin2;
    shared<StatementIr> stmt1;
    shared<StatementIr> stmt2;
    shared<StatementIr> stConditionExpr;
    shared<StatementIr> stConditionTrue;
    
    std::string opSwitchSelector;
    shared<OperandIr> opSwitchSelectorIr;
    std::vector<std::pair<shared<OperandIr>, shared<StatementIr>>> opSwitchCases;

    std::string comment;
    std::string stop;
    std::string repeat;
    std::string func;
    std::string templ1;
    std::string templ2;
    std::string oper;
    address_t address;
    address_t target;
    
    int suffix{0};
    bool postpone{false};
    
    shared<StatementIr> next;
    
    operator bool()
    {
        return type != Type_t::None;
    }
};
