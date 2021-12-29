class CInstruction : public CSerializable
{
public:
    string m_origin;
    int m_line;

	virtual ~CInstruction() {}
	static CInstruction* FromName(string strClassName);
};

class CIFunction : public CInstruction
{
public:
	enum EBoundary {
		Begin,
		End,
        EndFail
	};

	string m_strName;
	EBoundary m_eBoundary;

public:
	CIFunction() {}
    virtual ~CIFunction() {}

	CIFunction(EBoundary eBoundary, string strName) : 
	  m_eBoundary(eBoundary), m_strName(strName)
	{
	}

	CIFunction(EBoundary eBoundary) : 
	  m_eBoundary(eBoundary)
	{
	}

	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << m_strName << _enum(m_eBoundary);
	}
};

class CINop : public CInstruction
{
public:
	string m_strComment;

public:
	CINop()
	{
	}

	CINop(const string& strComment) : m_strComment(strComment)	
	{
        if (m_strComment.length() > 42)
            m_strComment = m_strComment.substr(0, 42) + "...";
	}

	virtual void Eval(CMachine& m) {}

	virtual void Serialize(CSerializer& s) 
	{
		s << m_strComment;
	}
};

class CISegment : public CInstruction
{
public:
    string m_strSegmentName;

public:
    CISegment() {}
    
    CISegment(const string& strSegmentName) : m_strSegmentName(strSegmentName)
    {
    }

    virtual void Eval(CMachine& m) {}

    virtual void Serialize(CSerializer& s)
    {
        s << m_strSegmentName;
    }
};

class CILabel : public CInstruction
{
public:
	CLabel m_label;

public:
	CILabel() : m_label("") {}

	CILabel(string strName) : m_label(strName)
	{
	}

	virtual void Eval(CMachine& m) {}

	virtual void Serialize(CSerializer& s)
	{
		s << m_label;
	}
};

class CIReturn : public CInstruction
{
public:
	int m_nReduceStack;

public:
	CIReturn(int nReduceStack = 0) : m_nReduceStack(nReduceStack)
	{
	}

	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << m_nReduceStack;
	}
};

class CIZeroArgOp : public CInstruction
{
public:
	enum EType {
		cli, sti, _std, stc, ctc, cld, aaa, cbw, lodsw, lodsb, stosw, stosb, movsw, movsb, cmpsb, clc, sahf, lahf, popf, pushf, 
        xlat_cs, xlat_ds, xlat_es,
        cwd, cmc, scasb,
		// TODO: Should be in separate fake instruction
		FakeZeroTest, FakeCarryTest, FakeZeroCarryTest,
		invalid
	};

public:
	EType m_eType;

public:
	CIZeroArgOp() {}

	CIZeroArgOp(EType eType) : m_eType(eType)
	{
	}

	static EType GetType(string str)
	{
		CheckEnum(cli);		CheckEnum(sti);		CheckEnum2("std", _std);	CheckEnum(stc);
		CheckEnum(ctc);		CheckEnum(cld);		CheckEnum(aaa);		CheckEnum(cbw);
		CheckEnum(lodsw);	CheckEnum(lodsb);	CheckEnum(stosw);	CheckEnum(movsw);
		CheckEnum(movsb);	CheckEnum(clc);		CheckEnum(sahf);	CheckEnum(lahf);
		CheckEnum(popf);	CheckEnum(pushf);	CheckEnum(stosb);	
		CheckEnum(cmpsb);
	// xlat
        CheckEnum2("xlat cs", xlat_cs);
        CheckEnum2("xlat ds", xlat_ds);
        CheckEnum2("xlat es", xlat_es);
        // numeric
        CheckEnum(cwd); CheckEnum(cmc); CheckEnum(scasb);
		_ASSERT(0);
		return invalid;
	}
	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << _enum(m_eType) /*<< m_analysis*/;
	}
};

class CISingleArgOp : public CInstruction
{
public:
	enum EType {
		push,
		pop,
		interrupt,
		div,
        lods,
		invalid
	};

public:
	EType m_eType;
	CValue m_rvalue;

public:
	CISingleArgOp() {}

	CISingleArgOp(EType eType, const CValue& rvalue) : 
	  m_eType(eType), m_rvalue(rvalue)
	{
	}

	static EType GetType(string str)
	{
		CheckEnum(push);	CheckEnum(pop);	CheckEnum(div);
		CheckEnum2("int", interrupt);
        CheckEnum(lods);
		_ASSERT(0);
		return invalid;
	}
	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << _enum(m_eType) << m_rvalue;
	}
};

class CITwoArgOp : public CInstruction
{
public:
	enum EType {
		out, in, xchg, rcr, rcl, rol,
		les, lea, sbb, lds, invalid
	};

public:
	EType m_eType;
	CValue m_rvalue1;
	CValue m_rvalue2;

public:
	CITwoArgOp() {}

	CITwoArgOp(EType eType, const CValue& rvalue1, const CValue& rvalue2) : 
	  m_eType(eType), m_rvalue1(rvalue1), m_rvalue2(rvalue2)
	{
	}

	static EType GetType(string str)
	{
		CheckEnum(out);	CheckEnum(in); CheckEnum(xchg); CheckEnum(rcr); CheckEnum(rcl);
        CheckEnum(rol); CheckEnum(les); CheckEnum(lea); CheckEnum(sbb); CheckEnum(lds);
        CheckEnum(les);
		_ASSERT(0);
		return invalid;
	}

	virtual void Eval(CMachine& m);
	virtual void Serialize(CSerializer& s)
	{
		s << _enum(m_eType) << m_rvalue1 << m_rvalue2;
	}

};

class CIString : public CInstruction
{
public:
	enum ERule
	{
		rep,
		repne,
        repe,
		invalidrule
	};

	enum EOperation
	{
		stosb, lodsb, stosw, lodsw, movsw, movsb, scasw, scasb,
        cmpsb, outsb,
		invalidop
	};

public:
	ERule m_rule;
	EOperation m_operation;

public:
	CIString() {}

	CIString(ERule eRule, EOperation eOperation) : 
	  m_rule(eRule), m_operation(eOperation)
	{
	}

	static ERule GetRule(string str)
	{
        CheckEnum(rep);	CheckEnum(repne); CheckEnum(repe);
		_ASSERT(0);
		return invalidrule;
	}

	static EOperation GetOperation(string str)
	{
		CheckEnum(stosb);	CheckEnum(lodsb);
		CheckEnum(stosw);	CheckEnum(lodsw);
		CheckEnum(movsw);	CheckEnum(movsb);
		CheckEnum(scasw);	CheckEnum(scasb);
        CheckEnum(cmpsb);   CheckEnum(outsb);
		_ASSERT(0);
		return invalidop;
	}

	virtual void Eval(CMachine& m);
	static void EvalLodsb(CMachine& m);
	static void EvalLodsw(CMachine& m);
	static void EvalStosb(CMachine& m);
	static void EvalStosw(CMachine& m);
	static void EvalMovsb(CMachine& m);
	static void EvalMovsw(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << _enum(m_rule) << _enum(m_operation) /*<< m_analysis*/;
	}
};

class CIAssignment : public CInstruction
{
public:
	CValue m_valueFrom;
	CValue m_valueTo;

public:
	CIAssignment() {}

	CIAssignment(const CValue& valueTo, const CValue& valueFrom) : 
	  m_valueFrom(valueFrom), m_valueTo(valueTo)
	{
	}

	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << m_valueTo << m_valueFrom /*<< m_analysis*/;
	}
};

class CIAlu : public CInstruction
{
public:
	enum EType
	{
		Increment,
		Decrement,
		Add,
		Sub,
		Xor,
		And,
		Or,
		Not,
		Neg,
		AddWithCarry,
		Shl,
		Shr,
		Sar,
		Mul,
        IMul,
        IDiv,
        Ror
	};

public:
	CValue m_op1;
	CValue m_op2;
	EType m_eType;

	// Realtime
    enum {None, Carry, Sign, Overflow} m_ExportInsertion;

public:
	CIAlu() : m_ExportInsertion(None) {}

	CIAlu(EType eType, const CValue& op1) : 
	  m_eType(eType), m_op1(op1), m_ExportInsertion(None)
	{
	}

	CIAlu(EType eType, const CValue& op1, const CValue& op2) : 
	  m_eType(eType), m_op1(op1), m_op2(op2), m_ExportInsertion(None)
	{
	}

	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << _enum(m_eType) << m_op1 << m_op2;
	}
};

class CIJump : public CInstruction
{
public:
	CLabel m_label;
    bool m_stop{false};

public:
	CIJump() : m_label("") {}

	CIJump(const CLabel& label) : 
	  m_label(label)
	{
	}

	virtual void Serialize(CSerializer& s)
	{
		s << m_label;
	}

	virtual void Eval(CMachine& m);
};

class CIConditionalJump : public CInstruction
{
public:
	enum EType {
		jbe, jz, jnz, ja, jb, jnb, jle, jg, jge, jns, jl, js, jcxz,
		invalid
	};

public:
	EType m_eType;
	CLabel m_label;
    bool m_stop{false};
    bool m_function{false};

public:
	CIConditionalJump() : m_label("") {}

	CIConditionalJump(EType eType, const CLabel& label) : 
	  m_eType(eType), m_label(label)
	{
	}

  	static EType GetType(string str)
	{
		CheckEnum(jbe);	CheckEnum(jz); CheckEnum(jnz); CheckEnum(ja); CheckEnum(jb);
		CheckEnum(jnb);	CheckEnum(jle); CheckEnum(jg); CheckEnum(jge); CheckEnum(jns);
		CheckEnum(jl);	CheckEnum(js); CheckEnum(jcxz);
		if (str == "jc") return jb;
		if (str == "jnc") return jnb;
		_ASSERT(0);
		return invalid;
	}

	virtual void Eval(CMachine& m);

	static bool SatisfiesCondition1(CMachine& m, CIConditionalJump::EType eType);
	static bool SatisfiesCondition2(CMachine& m, CIConditionalJump::EType eType);
	bool EvalByPrevInstruction(CMachine& m, shared_ptr<CInstruction> pInstruction);

	virtual void Serialize(CSerializer& s)
	{
		s << _enum(m_eType) << m_label;
	}
};

class CICall : public CInstruction
{
public:
    enum EType {
        Default,
        NearPtr,
        Jump
    } m_type;
	CLabel m_label;

public:
	CICall() : m_label(""), m_type(Default) {}

	CICall(const CLabel& label, EType type) :
	  m_label(label), m_type(type)
	{
	}

	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << m_label << _enum(m_type);
	}
};

class CIIndirectCall : public CInstruction
{
public:
    enum EType {
        Undefined,
        WordPtr,
    } m_type;
    CValue m_value;
    bool m_jump;

public:
    CIIndirectCall() : m_type(Undefined) {}

    CIIndirectCall(EType type, CValue value, bool jump = false) :
      m_value(value), m_type(type), m_jump(jump)
    {
    }

    virtual void Serialize(CSerializer& s)
    {
        s << m_value << _enum(m_type) << m_jump;
    }
};

class CISwitch : public CInstruction
{
public:
	enum EType
	{
		Jump,
		Call,
        FarCall
	};

public:
	CLabel m_label;
	CValue m_reg;
	EType m_eType;

public:
	CISwitch() : m_label("") {}

	CISwitch(const CLabel& label, const CValue& reg, EType eType) : 
	  m_label(label), m_reg(reg), m_eType(eType)
	{
	}

	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << m_label << m_reg << _enum(m_eType);
	}
};

class CILoop : public CInstruction
{
public:
	enum EType {
		Loop, WhileEqual, WhileNotEqual
	};

public:
	EType m_eType;
	CLabel m_label;
    bool m_stop{false};

public:
	CILoop() : m_label("") {}

	CILoop(EType eType, const CLabel& label) : 
	  m_eType(eType), m_label(label)
	{
	}

	virtual void Serialize(CSerializer& s)
	{
		s << _enum(m_eType) << m_label;
	}

	virtual void Eval(CMachine& m);
};

class CICompare : public CInstruction
{
public:
	CValue m_op1;
	CValue m_op2;

public:
	CICompare() {}

	CICompare(const CValue& op1, const CValue& op2) : 
	  m_op1(op1), m_op2(op2)
	{
	}

	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << m_op1 << m_op2;
	}
};

class CITest : public CInstruction
{
public:
	CValue m_op1;
	CValue m_op2;

public:
	CITest() {}

	CITest(const CValue& op1, const CValue& op2) : 
	  m_op1(op1), m_op2(op2)
	{
	}

	virtual void Eval(CMachine& m);

	virtual void Serialize(CSerializer& s)
	{
		s << m_op1 << m_op2;
	}
};

class CIData : public CInstruction
{
public:
	enum EType {
		WordPtr, Word, Byte,
		Function
	};

public:
	EType m_eType;
	CLabel m_strVariableName;
	unsigned int m_nValue;
	string m_strFunction;

public:
	CIData() : m_strVariableName("") {}

	CIData(EType eType, const string& strValue) : 
	  m_eType(eType), m_strVariableName(strValue)
	{
	}

	CIData(EType eType, const string& strVariableName, int nValue) : 
	  m_eType(eType), m_strVariableName(strVariableName), m_nValue(nValue)
	{
	}

	CIData(EType eType, const string& strVariableName, const string& strFunction) : 
	  m_eType(eType), m_strVariableName(strVariableName), m_strFunction(strFunction)
	{
		_ASSERT(m_eType == Function || m_eType == Word);
	}

	virtual void Serialize(CSerializer& s)
	{
		s << _enum(m_eType) << m_strVariableName << m_nValue << m_strFunction;
	}
};

class CIStop : public CInstruction
{
public:
    string mComment;

public:
    CIStop(shared_ptr<CInstruction> pOrigin = nullptr, string comment = "")
    {
        if (pOrigin)
            m_origin = pOrigin->m_origin;
        mComment = comment;
    }

    virtual void Eval(CMachine& m) {_ASSERT(0);}
    virtual void Serialize(CSerializer& s)
    {
    }
};

class CIAbbrev : public CInstruction
{
public:
    string m_strKey;
    string m_strValue;

public:
    CIAbbrev()
    {
    }

    CIAbbrev(const string& strKey, const string& strValue)
    {
        m_strKey = strKey;
        m_strValue = strValue;
    }

    virtual void Eval(CMachine& m) {}

    virtual void Serialize(CSerializer& s)
    {
        s << m_strKey << m_strValue;
    }
};

CInstruction* CInstruction::FromName(string strClassName)
{
    // OSX
    while (strClassName[0] >= '0' && strClassName[0] <= '9')
        strClassName = strClassName.substr(1, strClassName.length()-1);
    strClassName = "class " + strClassName;
    
	if (strClassName == "class CIFunction")
		return new CIFunction();
	if (strClassName == "class CINop")
		return new CINop();
	if (strClassName == "class CILabel")
		return new CILabel();
	if (strClassName == "class CIReturn")
		return new CIReturn();
	if (strClassName == "class CIZeroArgOp")
		return new CIZeroArgOp();
	if (strClassName == "class CISingleArgOp")
		return new CISingleArgOp();
	if (strClassName == "class CITwoArgOp")
		return new CITwoArgOp();
	if (strClassName == "class CIString")
		return new CIString();
	if (strClassName == "class CIAssignment")
		return new CIAssignment();
	if (strClassName == "class CIAlu")
		return new CIAlu();
	if (strClassName == "class CIJump")
		return new CIJump();
	if (strClassName == "class CIConditionalJump")
		return new CIConditionalJump();
	if (strClassName == "class CICall")
		return new CICall();
    if (strClassName == "class CIIndirectCall")
        return new CIIndirectCall();
	if (strClassName == "class CISwitch")
		return new CISwitch();
	if (strClassName == "class CILoop")
		return new CILoop();
	if (strClassName == "class CICompare")
		return new CICompare();
	if (strClassName == "class CITest")
		return new CITest();
	if (strClassName == "class CIData")
		return new CIData();
    if (strClassName == "class CIStop")
        return new CIStop();
    if (strClassName == "class CISegment")
        return new CISegment();
    if (strClassName == "class CIAbbrev")
        return new CIAbbrev();
	return nullptr;
}
