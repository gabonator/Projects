
class CSourceParser
{
public:
	typedef shared_ptr<CInstructionMatcher> SInstructionMatcher;
	vector<SInstructionMatcher> m_arrMatchers;

	vector<shared_ptr<CInstruction>> m_arrCode;
	vector<string> m_arrSource;
    vector<int> m_arrLine;

	CSourceParser()
	{
		m_arrMatchers.push_back(std::make_shared<CIMFunction>());
		m_arrMatchers.push_back(std::make_shared<CIMLabel>());
		m_arrMatchers.push_back(std::make_shared<CIMReturn>());
		m_arrMatchers.push_back(std::make_shared<CIMFixedArgOp>());
		m_arrMatchers.push_back(std::make_shared<CIMStringOp>());
		m_arrMatchers.push_back(std::make_shared<CIMAssignment>());
		m_arrMatchers.push_back(std::make_shared<CIMAlu>());
		m_arrMatchers.push_back(std::make_shared<CIMFlow>());
		m_arrMatchers.push_back(std::make_shared<CIMCompare>());
		m_arrMatchers.push_back(std::make_shared<CIMData>());
		m_arrMatchers.push_back(std::make_shared<CIMNop>());
        m_arrMatchers.push_back(std::make_shared<CIMSegment>());

		m_arrCode.reserve(20000);
		m_arrSource.reserve(20000);
	}

	void MatchLine(int line, const string& strLine)
	{
		for (vector<SInstructionMatcher>::iterator i = m_arrMatchers.begin(); i != m_arrMatchers.end(); i++)
		{
			shared_ptr<CInstruction> sInstruction = (*i)->Match(strLine);
			if ( sInstruction ) 
			{
				m_arrCode.push_back(sInstruction);
				m_arrSource.push_back(strLine);
				//printf("%s -> %s\n", strLine.c_str(), typeid(*sInstruction).name());
				return;
			}
		}

		printf("\n[%d] %s\n", line, strLine.c_str());
		_ASSERT(0);
	}

	void Save(const char* strFileName)
	{
		std::ofstream f(strFileName, ios::binary);
		_ASSERT(f);

		int nSize = (int)m_arrCode.size();

		CSerializer serializer(f);
		serializer << nSize;

		for (int i=0; i<nSize; i++)
		{
            string line = m_arrSource[i];
            if (line.size() >= 47)
                line = line.substr(0, 42) + "...";
            
            serializer << i;
			serializer << line;
            
			serializer << string(typeid(*m_arrCode[i]).name());
			m_arrCode[i]->Serialize(serializer);
		}
		f.close();
	}

	void Load(const char* strFileName)
	{
		std::ifstream f;
		f.open(strFileName, ios::binary);
		_ASSERT(f);

		int nLength = 0;
        int line;
		CSerializer serializer(f);
		serializer << nLength;

		m_arrCode.resize(nLength);
		m_arrSource.resize(nLength);
        m_arrLine.resize(nLength);

		for (int i=0; i<nLength; i++)
		{
			string strSourceLine;
			string strClassName;

            serializer << line;
			serializer << strSourceLine;
			serializer << strClassName;

			CInstruction* pInstruction = CInstruction::FromName(strClassName);
			_ASSERT(pInstruction);
			pInstruction->Serialize(serializer);
            pInstruction->m_origin = strSourceLine;
            pInstruction->m_line = i;

			m_arrCode[i] = shared_ptr<CInstruction>(pInstruction);
			m_arrSource[i] = strSourceLine;
            m_arrLine[i] = i;
		}
		/*
		for (int i=0; (size_t)i<m_arrCode.size(); i++)
		{
			serializer << string(typeid(*m_arrCode[i]).name());		
			m_arrCode[i]->Serialize(serializer);
		}*/
		f.close();
	}

	void Parse(const char* strFileName)
	{
		FILE* f = fopen(strFileName, "r");
		int i = 0;
		while (!feof(f))
		{
            if ((i%1000) == 0)
                printf("line %d, ", i);
            i++;
			//printf("\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08%d", i++);

			// TODO:
			//if ( i > 2500 )
			//	break;

			char strLine[1024];
			fgets(strLine, 1023, f);
			if ( strLine[0] )
			{
				while ( strLine[strlen(strLine)-1] == 0x0d || strLine[strlen(strLine)-1] == 0x0a )
					strLine[strlen(strLine)-1] = 0;
			}
			
			string _strLine = Trim(strLine);

            if (strstr(strLine, "failed") != nullptr)
            {
                _strLine += "_failed";
            }
            
			if ( _strLine.length() == 0 )
				continue;

//            const char* test = _strLine.c_str();

			MatchLine(i, _strLine);
		}
		fclose(f);
	}

	string Trim(string strLine)
	{
		const char *b = strLine.c_str();
		const char *e = b + strlen(b);
		const char *cmt = strstr(b, ";");
		
		if ( cmt )
			e = cmt;

		while (b[0] == '\t' || b[0] == ' ')
			b++;
		while (e-b > 0 && (e[-1] == ' ' || e[-1] == '\t'))
			e--;

		for (char* i = (char*)b; i<e; i++)
			if ( *i == 9 )
				*i = ' ';

		return string(b, e);
	}

};
