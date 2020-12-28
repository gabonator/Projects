class CStaticAnalysis;

struct segmenntInfo {
    char name[32];
    int begin;
    int end;
    int base;
} segments[] =
/*
{
    {"x",      0x0000, 0xF000, 0x0000}, // unref
    {"", 0, 0, 0}
};
*/
{ // xenon
    {"dseg",   0x0000, 0xfd10, 0x2853},
    {"seg000", 0x0000, 0xf290, 0x1000},
    {"seg001", 0x0000, 0x5900, 0x1f29},
    {"seg002", 0x0000, 0x0ac0, 0x24b9},
    {"seg003", 0x0000, 0xe220, 0x2565},
    {"seg005", 0x0000, 0xc570, 0x3824},
    {"seg006", 0x0000, 0x0200, 0x447b}, // stack
    {"seg007", 0x0000, 0x0001, 0x449B},
    {"seg008", 0x0000, 0x0001, 0x5489},
    {"seg009", 0x0000, 0x0001, 0x63D0},
    {"seg010", 0x0000, 0x0001, 0x7218},
    {"", 0, 0, 0}
};

/*
{ // tetris
    {"seg000", 0x0000, 0x0050, 0x1000},
    {"seg001", 0x0000, 0x0080, 0x1005},
    {"seg002", 0x0000, 0x82c0, 0x100d},
    {"seg003", 0x0000, 0x2c80, 0x1839},
    {"", 0, 0, 0}
};
*/
/*
 // jsgoose
{
    {"seg000", 0x0000, 0x3A56, 0x1000}, // CODE
    {"dseg",   0x0006, 0x9570, 0x13A5}, // DATA
    {"seg002", 0x0000, 0x0100, 0x1CFC}, // STACK
    {"x",      0x0000, 0x8000, 0x0000}, // unref
    {"", 0, 0, 0}
};
 */

int FixPtr(int ofs)
{
    for (int i=0; segments[i].name[0]; i++)
    {
        if (ofs >= segments[i].base*16 + segments[i].begin &&
            ofs <= segments[i].base*16 + segments[i].end)
        {
            return ofs - segments[i].base*16;
        }
    }
    _ASSERT(0);
    return ofs;
}
    
class CValue : public CSerializable
{
public:
	enum EType {
		ah, al, ax,
		bh, bl, bx,
		ch, cl, cx,
		dh, dl, dx,
		ds, es, si, di, cs, bp, sp,
		ss,
		
		constant,
		
		//wordptr, byteptr, dwordptr, wordptrasbyte,
		//byteptrval, wordptrval,
        //ss_wordptr,
        //ss_ptr,
		
		si_plus,
		bx_plus,
		bx_plus_si,
		bp_plus,
		di_plus,

        ds_ptr,
        ss_ptr,
        ds_ptr_value,

		es_ptr_di,
        es_ptr_si,
		bx_plus_di,
		es_ptr_di_plus,
        es_ptr_si_plus,
		stack_bp_plus,
        cs_ptr_bx_plus,
        cs_ptr_bx_plus_di,
        cs_ptr_bx_plus_di_plus,
        ds_ptr_bp,
        cs_ptr_di,
        cs_ptr_di_plus,
        cs_ptr_bx,
        cs_ptr_bp,
        cs_ptr_bp_plus,
        cs_ptr_bp_plus_si_plus,
        cs_ptr_si,
        ss_byteptr,

		byteptrasword,

		byteptrseg,
		wordptrseg,
		segment,
		wordptr_es,
		dwordptrseg,
		dwordptrasword,

		es_ptr,
        cs_ptr,
		bx_plus_si_plus,
		ds_ptr_bp_plus,
        bx_plus_di_plus,
        bp_plus_di_plus,

        wordptr_es_di,
        wordptr_es_si,
        wordptr_bp_plus,

        stop, // need to be fixed manually
		invalid
	};

	enum ERegLength 
	{
		r8, r16, r32, unknown
	};

	enum ESegment {
		invalidsegment,
		dseg,
        seg000,
		seg002,
		seg003,
        seg004,
        seg005,
        seg006,
        seg007,
        seg008,
        seg009,
        seg001
	};

public:
	EType m_eType;
	ERegLength m_eRegLength;

	shared_ptr<CValue> m_value;
	int m_nValue;	
	ESegment m_eSegment;

public:
	CValue()
	{
		m_eRegLength = unknown;
		m_eType = invalid;
		m_eSegment = invalidsegment;
	}

	CValue(const std::string& str, ERegLength eRegLength = unknown)
	{
		m_nValue = 0;
		Parse(str, eRegLength);
        if (!m_value && (str.find("byte_") != string::npos || str.find("word_") != string::npos))
        {
            _ASSERT(m_nValue >= 0x0000 && m_nValue <= 0xffff);
        }
	}

	void Parse(const std::string& str, ERegLength eRegLength = unknown)
	{
		m_eRegLength = unknown;
		m_eSegment = invalidsegment;
		std::string value = CUtils::Trim(str);
		
        m_nValue = -999999;
		m_eType = RegisterType8(value);
		
		if (m_eType != invalid)
		{
			m_eRegLength = r8;
			return;
		}

		m_eType = RegisterType16(value);
		
		if (m_eType != invalid)
		{
			m_eRegLength = r16;
			return;
		}

		if (CUtils::ParseLiteral(str, m_nValue))
		{
			m_eRegLength = eRegLength;

			if ( CUtils::match("^[0-9A-F]{2}h$", value.c_str()) )
				m_eRegLength = r8;
			if ( CUtils::match("^0[0-9A-F]{2}h$", value.c_str()) )
				m_eRegLength = r8;
			if ( CUtils::match("^0[0-9A-F]{4}h$", value.c_str()) )
				m_eRegLength = r16;
			
			m_eType = constant;
			return;
		}

        if (str.substr(0, 4) == "seg ")
        {
            m_nValue = 0;
            m_eType = segment;
            m_eSegment = invalidsegment;
            
            if (str == "seg dseg" || str == "seg data")
                m_eSegment = dseg;
            if (str == "seg seg000")
                m_eSegment = seg000;
            if (str == "seg seg001")
                m_eSegment = seg001;
            if (str == "seg seg002")
                m_eSegment = seg002;
            if (str == "seg seg003")
                m_eSegment = seg003;
            if (str == "seg seg004")
                m_eSegment = seg004;
            if (str == "seg seg005")
                m_eSegment = seg005;
            if (str == "seg seg006")
                m_eSegment = seg006;
            if (str == "seg seg007")
                m_eSegment = seg007;
            if (str == "seg seg008")
                m_eSegment = seg008;
            _ASSERT(m_eSegment != invalidsegment);
            return;
        }

		vector<string> matches;
		if ( CUtils::match("^word_data_(.+)\\+(.+)$", value.c_str(), matches) )
		{
			m_eType = ds_ptr; // urcite ptr?
			m_eRegLength = r16;
			m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]) + CUtils::ParseLiteral(matches[1]));
			return;
		}

		if ( CUtils::match("^word_data_(.*)$", value.c_str(), matches) )
		{
			m_eType = ds_ptr; // urcite ptr?
			m_eRegLength = r16;
			m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
			return;
		}

		if ( CUtils::match("^byte ptr \\[(.*)\\]$", value.c_str(), matches) )
		{
			m_eType = ds_ptr;
			m_eRegLength = r8;
			m_value = make_shared<CValue>(matches[0]);
			return;
		}

        if ( CUtils::match("^byte ptr loc_(.*)\\+(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r8;
            m_nValue = CUtils::ParseLiteral("0x" + matches[0]) + CUtils::ParseLiteral(matches[1]);
            return;
        }

        if ( CUtils::match("^word ptr \\[bp-(.*)\\]$", value.c_str(), matches) )
        {
            m_eType = wordptr_bp_plus;
            m_eRegLength = r16;
            m_nValue = -CUtils::ParseLiteral(matches[0]);
            return;
        }


		if ( CUtils::match("^word ptr \\[(.*)\\]$", value.c_str(), matches) )
		{
			m_eType = ds_ptr;
			m_eRegLength = r16;
			m_value = make_shared<CValue>(matches[0]);
			return;
		}

        if ( value == "word ptr es:[di]" )  //xenon
        {
            m_eRegLength = r16;
            m_eType = wordptr_es_di;
            return;
        }

        if ( value == "word ptr es:[si]" )  //xenon
        {
            m_eRegLength = r16;
            m_eType = wordptr_es_si;
            return;
        }

        if ( CUtils::match("^word ptr (es):loc_(.+)$", value.c_str(), matches) )
        {
            m_eType = wordptr_es;
            m_eRegLength = r16;
            m_nValue = CUtils::ParseLiteral("0x"+matches[1]);
            return;
        }

		if ( CUtils::match("^word ptr (es):(.+)$", value.c_str(), matches) )
		{
			m_eType = wordptr_es;
			m_eRegLength = r16;
			m_nValue = CUtils::ParseLiteral(matches[1]);
			return;
		}

		if ( CUtils::match("^byte ptr word_data_(.+)\\+(.+)$", value.c_str(), matches) )
		{
            _ASSERT(0);
			m_eRegLength = r8;
			m_eType = ds_ptr;
			m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]) + CUtils::ParseLiteral(matches[1]));
			return;
		}

        if ( CUtils::match("^word ptr ss:byte_(.+)\\+(.+)$", value.c_str(), matches) )
        {
            m_eRegLength = r16;
            m_eType = ss_ptr;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0])) + CUtils::ParseLiteral(matches[1]);
            return;
        }

////byteptrasword, wordptr, wordptrasbyte, byteptr, dwordptrx
		if ( CUtils::match("^word ptr byte_data_(.+)\\+(.+)$", value.c_str(), matches) )
		{
			m_eRegLength = r16;
			m_eType = byteptrasword;
			m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]) + CUtils::ParseLiteral(matches[1]));
			return;
		}

		if ( CUtils::match("^byte ptr word_data_(.*)$", value.c_str(), matches) )
		{
			m_eRegLength = r8;
			m_eType = ds_ptr;
			m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
			return;
		}

		if ( CUtils::match("^byte_data_(.*)$", value.c_str(), matches) )
		{
			m_eType = ds_ptr;
			m_eRegLength = r8;
			m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
			return;
		}

		if ( CUtils::match("^ds:\\[bp\\+(.*)\\]$", value.c_str(), matches) )
		{
			m_eType = ds_ptr_bp_plus;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			_ASSERT(eRegLength == r16 || eRegLength == r8);
			m_eRegLength = eRegLength;
			return;
		}

        if (value.find("bp") != string::npos)
        {
            if ( CUtils::match("^\\[bp\\+arg_(.*)\\]$", value.c_str(), matches) )
            {
                m_eType = stack_bp_plus;
                m_nValue = CUtils::ParseLiteral("0x"+matches[0])+4;
                _ASSERT(eRegLength == r16 || eRegLength == r8);
                m_eRegLength = eRegLength;
                return;
            }

            if ( CUtils::match("^\\[bp\\+var_(.*)\\]$", value.c_str(), matches) )
            {
                m_eType = stack_bp_plus;
                m_nValue = -CUtils::ParseLiteral("0x"+matches[0]);
                m_eRegLength = r16;
                return;
            }
            if ( CUtils::match("^\\[bp\\+(.*)\\]$", value.c_str(), matches) )
            {
                m_eType = stack_bp_plus;
                m_nValue = CUtils::ParseLiteral(matches[0]);
                m_eRegLength = r16;
                return;
            }
            if ( value == "word ptr ds:[bp+0]" )
            {
                m_eRegLength = r16;
                m_eType = ds_ptr_bp;
                return;
            }
            if ( value == "byte ptr ds:[bp+0]" )
            {
                m_eRegLength = r8;
                m_eType = ds_ptr_bp;
                return;
            }
            if ( value == "cs:[bp+0]" )
            {
                _ASSERT(eRegLength != unknown);
                m_eRegLength = eRegLength;
                m_eType = cs_ptr_bp;
                return;
            }

            if ( value == "word ptr cs:[bp+0]" )
            {
                m_eRegLength = r16;
                m_eType = cs_ptr_bp;
                return;
            }

            if ( CUtils::match("^cs:\\[bp\\+si\\+(.*)\\]$", value.c_str(), matches) )
            {
                _ASSERT(eRegLength == r16 || eRegLength == r8);
                m_eRegLength = eRegLength;
                m_eType = cs_ptr_bp_plus_si_plus;
                m_nValue = CUtils::ParseLiteral(matches[0]);
                return;
            }

            if ( CUtils::match("^cs:\\[bp\\+(.*)\\]$", value.c_str(), matches) )
            {
                _ASSERT(eRegLength == r16 || eRegLength == r8);
                m_eRegLength = eRegLength;
                m_eType = cs_ptr_bp_plus;
                m_nValue = CUtils::ParseLiteral(matches[0]);
                return;
            }


            _ASSERT(0);
        }

		if ( CUtils::match("^\\[(.*)\\]$", value.c_str(), matches) )
		{
			_ASSERT(eRegLength != unknown);
			if ( eRegLength == r8 )
			{
				m_value = make_shared<CValue>(matches[0], CValue::r8);
				m_eType = ds_ptr_value;
				m_eRegLength = r8;
				return;
			}
			if ( eRegLength == r16 )
			{
				m_value = make_shared<CValue>(matches[0], CValue::r16);
				m_eType = ds_ptr_value;
				m_eRegLength = r16;
				return;
			}
		}

		if ( CUtils::match("^si\\+(.*)$", value.c_str(), matches) )
		{
			m_eType = si_plus;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

		if ( value == "bx+di" )
		{
			m_eRegLength = r16;
			m_eType = bx_plus_di;
			return;
		}

		if ( CUtils::match("^bx\\+si\\+(.*)$", value.c_str(), matches) )
		{
			_ASSERT(eRegLength == r16);
			m_eType = bx_plus_si_plus;
			m_eRegLength = eRegLength;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

        if ( CUtils::match("^bx\\+di\\+(.*)$", value.c_str(), matches) )
        {
            m_eType = bx_plus_di_plus;
            m_nValue = CUtils::ParseLiteral(matches[0]);
            return;
        }

		if ( CUtils::match("^bx\\+(.*)$", value.c_str(), matches) )
		{
			m_eType = bx_plus;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

		if ( CUtils::match("^bx\\-(.*)$", value.c_str(), matches) )
		{
			m_eType = bx_plus;
			m_nValue = -CUtils::ParseLiteral(matches[0]);
			return;
		}

		if ( CUtils::match("^di\\+(.*)$", value.c_str(), matches) )
		{
			m_eType = di_plus;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

        if ( CUtils::match("^di\\-(.*)$", value.c_str(), matches) )
        {
            m_eType = di_plus;
            m_nValue = -CUtils::ParseLiteral(matches[0]);
            return;
        }

		if ( CUtils::match("^si\\-(.*)$", value.c_str(), matches) )
		{
			m_eType = si_plus;
			m_nValue = -CUtils::ParseLiteral(matches[0]);
			return;
		}

		if ( CUtils::match("^bp\\+arg_(.*)$", value.c_str(), matches) )
		{
			_ASSERT(0);
			m_eType = bp_plus;
			m_nValue = CUtils::ParseLiteral("0x"+matches[0]);
			return;
		}

		if ( CUtils::match("^bp\\+var_(.*)$", value.c_str(), matches) )
		{
			_ASSERT(0);
			m_eType = bp_plus;
			m_nValue = -CUtils::ParseLiteral("0x"+matches[0]);
			return;

        }

        if ( CUtils::match("^ss:byte_(.*)\\+(.*)$", value.c_str(), matches) )
        {
            m_eType = ss_byteptr;
            m_eRegLength = r8;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0])) + CUtils::ParseLiteral(matches[1]);
            return;
        }

        if ( CUtils::match("^ss:byte_(.*)$", value.c_str(), matches) )
        {
            m_eType = ss_byteptr;
            m_eRegLength = r8;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        
		if ( CUtils::match("^cs:word_code_(.*)$", value.c_str(), matches) )
		{
			m_eType = cs_ptr;
			m_eRegLength = r16;
			m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
			return;
		}

		if ( CUtils::match("^cs:byte_code_(.*)$", value.c_str(), matches) )
		{
			m_eType = cs_ptr;
			m_eRegLength = r8;
			m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
			return;
		}

		if ( CUtils::match("^offset loc_seg002_(.+)$", value.c_str(), matches) )
		{
			m_eType = constant;
			m_eRegLength = r16;
			m_nValue = CUtils::ParseLiteral("0x" + matches[0]);
			return;
		}

		if ( CUtils::match("^offset loc_code_(.+)$", value.c_str(), matches) )
		{
			m_eType = constant;
			m_eRegLength = r16;
			m_nValue = CUtils::ParseLiteral("0x" + matches[0]);
			return;
		}

		if ( value == "es:[di]" )
		{
			_ASSERT(eRegLength != unknown);
			m_eRegLength = eRegLength;
			m_eType = es_ptr_di;
			return;
		}

        if ( value == "cs:[bx]" )
        {
            _ASSERT(eRegLength != unknown);
            m_eRegLength = eRegLength;
            m_eType = cs_ptr_bx;
            return;
        }
        
        if ( CUtils::match("^cs:\\[bx\\+di\\]$", value.c_str(), matches) )
        {
            _ASSERT(eRegLength == r16 || eRegLength == r8);
            m_eRegLength = eRegLength;
            m_eType = cs_ptr_bx_plus_di;
            return;
        }
        if ( CUtils::match("^cs:\\[bx\\+di\\+(.*)\\]$", value.c_str(), matches) )
        {
            _ASSERT(eRegLength == r16 || eRegLength == r8);
            m_eRegLength = eRegLength;
            m_eType = cs_ptr_bx_plus_di_plus;
            m_nValue = CUtils::ParseLiteral(matches[0]);
            return;
        }


        if ( CUtils::match("^cs:\\[bx\\+(.*)\\]$", value.c_str(), matches) )
        {
            _ASSERT(eRegLength == r16 || eRegLength == r8);
            m_eRegLength = eRegLength;
            m_eType = cs_ptr_bx_plus;
            m_nValue = CUtils::ParseLiteral(matches[0]);
            return;
        }


        if ( value == "cs:[di]" )
        {
            _ASSERT(eRegLength != unknown);
            m_eRegLength = eRegLength;
            m_eType = cs_ptr_di;
            return;
        }

        if ( value == "es:[si]" )
        {
            _ASSERT(eRegLength != unknown);
            m_eRegLength = eRegLength;
            m_eType = es_ptr_si;
            return;
        }

        if ( value == "cs:[si]" )
        {
            _ASSERT(eRegLength != unknown);
            m_eRegLength = eRegLength;
            m_eType = cs_ptr_si;
            return;
        }

		if ( CUtils::match("^es:\\[di\\+(.*)\\]$", value.c_str(), matches) )
		{
			_ASSERT(eRegLength == r16 || eRegLength == r8);
			m_eRegLength = eRegLength;
			m_eType = es_ptr_di_plus;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

        if ( CUtils::match("^cs:\\[di\\+(.*)\\]$", value.c_str(), matches) )
        {
            _ASSERT(eRegLength == r16 || eRegLength == r8);
            m_eRegLength = eRegLength;
            m_eType = cs_ptr_di_plus;
            m_nValue = CUtils::ParseLiteral(matches[0]);
            return;
        }

        if ( CUtils::match("^word ptr cs:\\[bx\\+(.*)\\]$", value.c_str(), matches) )
        {
            m_eRegLength = r16;
            m_eType = cs_ptr_bx_plus;
            m_nValue = CUtils::ParseLiteral(matches[0]);
            return;
        }

        if ( CUtils::match("^word ptr cs:unk_(.*)$", value.c_str(), matches) )
        {
            m_eRegLength = r16;
            m_eType = cs_ptr;
            m_nValue = CUtils::ParseLiteral(matches[0] + "h");
            return;
        }
        /*
        if ( CUtils::match("^cs:\\[bx\\+(.*)\\]$", value.c_str(), matches) )
        {
            _ASSERT(eRegLength == r16 || eRegLength == r8);
            m_eRegLength = eRegLength;
            m_eType = cs_ptr_bx_plus;
            m_nValue = CUtils::ParseLiteral(matches[0]);
            return;
        }
*/
        if ( CUtils::match("^es:\\[si\\+(.*)\\]$", value.c_str(), matches) )
        {
            _ASSERT(eRegLength == r16 || eRegLength == r8);
            m_eRegLength = eRegLength;
            m_eType = es_ptr_si_plus;
            m_nValue = CUtils::ParseLiteral(matches[0]);
            return;
        }

		if ( CUtils::match("^ds:(.*)$", value.c_str(), matches) )
		{
            m_eType = ds_ptr;
			_ASSERT(eRegLength == r16 || eRegLength == r8);
			if ( eRegLength == r16 )
			{
				m_eRegLength = r16;
			} else
			if ( eRegLength == r8 )
			{
				m_eRegLength = r8;
			} else
			{
				_ASSERT(0);
			}

			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

		if ( CUtils::match("^byte ptr ds:(.*)$", value.c_str(), matches) )
		{
			m_eType = ds_ptr;
			m_eRegLength = r8;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

        if ( CUtils::match("^word ptr byte_(.*)\\+(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r16;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x"+matches[0])) + CUtils::ParseLiteral(matches[1]);
            return;
        }

        if ( CUtils::match("^word ptr byte_(.*)$", value.c_str(), matches) )
        {
            _ASSERT(0);
            /*
            m_eType = wordptr;
            m_eRegLength = r16;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x"+matches[0])); // WTF!!!
             */
            return;
        }


		if ( CUtils::match("^word ptr ds:(.*)$", value.c_str(), matches) )
		{
			m_eType = ds_ptr;
			m_eRegLength = r16;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}
        
        if ( CUtils::match("^bp\\+di\\+(.*)$", value.c_str(), matches) )
        {
            m_eType = bp_plus_di_plus;
            m_nValue = CUtils::ParseLiteral(matches[0]);
            return;
        }

		if ( CUtils::match("^bp\\+(.*)$", value.c_str(), matches) )
		{
			m_eType = bp_plus;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

		if ( CUtils::match("^es:word_data_(.+)\\+(.+)$", value.c_str(), matches) )
		{
			m_eRegLength = r16;
			m_eType = es_ptr;
			m_nValue = FixPtr(CUtils::ParseLiteral("0x"+matches[0])) + CUtils::ParseLiteral(matches[1]);
			return;
		}

        if ( CUtils::match("^cs:word_(.*)$", value.c_str(), matches) )
        {
            m_eRegLength = r16;
            m_eType = cs_ptr;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x"+matches[0]));
            return;
        }
        
        if ( CUtils::match("^es:word_(.*)$", value.c_str(), matches) )
        {
            m_eRegLength = r16;
            m_eType = es_ptr;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x"+matches[0]));
            return;
        }

        if ( CUtils::match("^es:\\[di\\-(.+)\\]$", value.c_str(), matches) )
        {
            _ASSERT(eRegLength == r8 || eRegLength == r16);
            m_eRegLength = eRegLength;
            m_eType = es_ptr_di_plus;
            m_nValue = -CUtils::ParseLiteral(matches[0]);
            return;
        }

        if ( CUtils::match("^byte ptr es:\\[di\\+(.+)\\]$", value.c_str(), matches) )
        {
            _ASSERT(eRegLength == r8 || eRegLength == r16);
            m_eRegLength = eRegLength;
            m_eType = es_ptr_di_plus;
            m_nValue = CUtils::ParseLiteral(matches[0]);
            return;
        }

        if ( CUtils::match("^es:byte_(.+)$", value.c_str(), matches) )
        {
            m_eRegLength = r8;
            m_eType = es_ptr;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x"+matches[0])); // should be fixed!
            return;
        }

		if ( CUtils::match("^es:(.+)$", value.c_str(), matches) )
		{
			_ASSERT(eRegLength == r8 || eRegLength == r16);
			m_eRegLength = eRegLength;
			m_eType = es_ptr;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

        if ( CUtils::match("^cs:byte_(.+)$", value.c_str(), matches) )
        {            
            m_eRegLength = r8;
            m_eType = cs_ptr;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        if ( CUtils::match("^byte ptr es:\\[di\\]$", value.c_str(), matches) )
        {
            m_eRegLength = r8;
            m_eType = es_ptr_di;
            return;
        }

		if ( CUtils::match("^byte ptr es:(.+)$", value.c_str(), matches) )
		{
			m_eRegLength = r8;
			m_eType = es_ptr;
			m_nValue = CUtils::ParseLiteral(matches[0]);
			return;
		}

        //xenon
        if ( CUtils::match("^byte_(.*)\\+(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r8;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0])) + CUtils::ParseLiteral(matches[1]);
            return;
        }

        if ( CUtils::match("^byte_(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r8;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        if ( CUtils::match("^word_(.*)\\+(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r16;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0])) + CUtils::ParseLiteral(matches[1]);
            return;
        }

        if ( CUtils::match("^seg_(.*)$", value.c_str(), matches) )
        {
            // seg_2C785 (memory where is segment value located)
            m_eType = ds_ptr;
            m_eRegLength = r16;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        if ( CUtils::match("^word_(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r16;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        if ( CUtils::match("^dword_(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r32;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        if ( CUtils::match("^word ptr dword_(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r16;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        if ( CUtils::match("^word ptr unk_(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r16;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        if ( CUtils::match("^word ptr loc_(.*)\\+(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r16;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0])) + CUtils::ParseLiteral(matches[1]);
            return;
        }

        if ( CUtils::match("^word ptr loc_(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r16;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        if ( CUtils::match("^byte ptr word_(.*)\\+(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r8;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0])) + CUtils::ParseLiteral(matches[1]);
            return;
        }

        if ( CUtils::match("^byte ptr word_(.*)$", value.c_str(), matches) )
        {
            m_eType = ds_ptr;
            m_eRegLength = r8;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x" + matches[0]));
            return;
        }

        if ( CUtils::match("^offset loc_(.*)$", value.c_str(), matches) )
        {
            m_eType = stop;
            m_eRegLength = r16;
            m_nValue = 0;
            return;
        }

        if ( CUtils::match("^ss:(.*)h$", value.c_str(), matches) )
        {
            _ASSERT(eRegLength == r8 || eRegLength == r16);
            m_eType = ss_ptr;
            m_nValue = CUtils::ParseLiteral("0x"+matches[0]);
            return;
        }

        if ( CUtils::match("^word ptr ss:(.*)h$", value.c_str(), matches) )
        {
            eRegLength = r16;
            m_eType = ss_ptr;
            m_nValue = CUtils::ParseLiteral("0x"+matches[0]);
            return;
        }

        if ( CUtils::match("^dword ptr cs:word_(.*)$", value.c_str(), matches) )
        {
            eRegLength = r16;
            m_eType = cs_ptr;
            m_nValue = FixPtr(CUtils::ParseLiteral("0x"+matches[0]));
            return;
        }

		printf("%s\n", str.c_str());
		_ASSERT(0);
	}

	static void SameOperands(CValue& op1, CValue& op2, string str1, string str2)
	{
		if (str1.length() == 2)
		{
			op1.Parse(str1);
			op2.Parse(str2, op1.GetRegisterLength());
		} else
		{
			op2.Parse(str2);
			op1.Parse(str1, op2.GetRegisterLength());
		}
	}

	static EType RegisterType8(std::string str)
	{
		CheckEnum(ah);		CheckEnum(al);
		CheckEnum(bh);		CheckEnum(bl);
		CheckEnum(ch);		CheckEnum(cl);
		CheckEnum(dh);		CheckEnum(dl);
		return invalid;
	}

	static EType RegisterType16(std::string str)
	{
		CheckEnum(ax);		CheckEnum(bx);		CheckEnum(cx);		CheckEnum(dx);
		CheckEnum(ds);		CheckEnum(es);		CheckEnum(si);		CheckEnum(di);
		CheckEnum(cs);		CheckEnum(bp);		CheckEnum(sp);		CheckEnum(ss);
		CheckEnum2("bx+si", bx_plus_si);
		return invalid;
	}

	ERegLength GetRegisterLength()
	{
		return m_eRegLength;
	}


	virtual void Serialize(CSerializer& s)
	{
		s << _enum(m_eType) << _enum(m_eRegLength) << _shared<CValue>(m_value) << m_nValue << _enum(m_eSegment);
	}

	string ToC();
	string GetC(CStaticAnalysis* pAnalysis);
	string SetC(CStaticAnalysis* pAnalysis);
};
