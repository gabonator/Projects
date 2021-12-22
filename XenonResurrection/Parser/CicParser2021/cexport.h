// TODO: remove
shared_ptr<CIStop> xxx(new CIStop());

// TODO: cleanup
bool _ReturnsCarry(string name);
bool _ReturnsZero(string name);

class CCExport
{
	vector<shared_ptr<CInstruction>> m_arrSource;

public:
	vector<int> FindReferences(const vector<shared_ptr<CInstruction>>& arrCode, CLabel label)
	{
		vector<int> aux;

		for (int i=0; (size_t)i<arrCode.size(); i++)
		{
			shared_ptr<CIJump> pJump = dynamic_pointer_cast<CIJump>(arrCode[i]);
			if (pJump && pJump->m_label == label)
				aux.push_back(i);

			shared_ptr<CIConditionalJump> pConditional = dynamic_pointer_cast<CIConditionalJump>(arrCode[i]);
			if (pConditional && pConditional->m_label == label)
				aux.push_back(i);
		}

		return aux;
	}

	vector<shared_ptr<CInstruction>> GetDataStarting(CLabel label)
	{
		vector<shared_ptr<CInstruction>> aux;
		bool bFound = false;

		for (int i=0; (size_t)i<m_arrSource.size(); i++)
		{
			shared_ptr<CIData> pData = dynamic_pointer_cast<CIData>(m_arrSource[i]);
			if (pData && pData->m_strVariableName == label)
			{
				if (!bFound)
					bFound = true;
            }
            if (pData)
            {
			} else
			{
				if (bFound)
					return aux;
			}

			if (bFound)
				aux.push_back(pData);
		}

		_ASSERT(0);
		return aux;
	}

    shared_ptr<CCInstruction> Convert(string strFunction, shared_ptr<CInstruction> pInInstruction, shared_ptr<CInstruction> pPrevious)
	{
		shared_ptr<CCInstruction> pOutInstruction;

		if ( dynamic_pointer_cast<CINop>(pInInstruction) )
			return nullptr;

		shared_ptr<CICompare> pCompare = dynamic_pointer_cast<CICompare>(pInInstruction);
		if ( pCompare )
		{
            pOutInstruction = make_shared<CCCompare>(pCompare, CCCompare::ZeroFlag);
            return nullptr;
		}
		if (dynamic_pointer_cast<CITest>(pInInstruction) )
		{
			return nullptr;
		}

		if ( dynamic_pointer_cast<CIData>(pInInstruction) && dynamic_pointer_cast<CIData>(pInInstruction)->m_eType == CIData::Function )
		{
			return nullptr;
		}

		shared_ptr<CIReturn> pReturn = dynamic_pointer_cast<CIReturn>(pInInstruction);

		if (pReturn)
			pOutInstruction = make_shared<CCReturn>( pReturn );

		shared_ptr<CIAssignment> pAssignment = dynamic_pointer_cast<CIAssignment>(pInInstruction);
		if (pAssignment)
			pOutInstruction = make_shared<CCAssignment>(pAssignment);

		shared_ptr<CIAlu> pAlu = dynamic_pointer_cast<CIAlu>(pInInstruction);
		if (pAlu)
			pOutInstruction = make_shared<CCAssignment>( pAlu, pPrevious );

		shared_ptr<CIZeroArgOp> pZeroArgOp = dynamic_pointer_cast<CIZeroArgOp>(pInInstruction);
		if (pZeroArgOp)
			pOutInstruction = make_shared<CCZeroArgOp>( pZeroArgOp );

		shared_ptr<CISingleArgOp> pSingleArgOp = dynamic_pointer_cast<CISingleArgOp>(pInInstruction);
		if (pSingleArgOp)
			pOutInstruction = make_shared<CCSingleArgOp>( pSingleArgOp );

		shared_ptr<CITwoArgOp> pTwoArgOp = dynamic_pointer_cast<CITwoArgOp>(pInInstruction);
		if (pTwoArgOp)
			pOutInstruction = make_shared<CCTwoArgOp>( pTwoArgOp, pPrevious );

		shared_ptr<CIString> pStringOp = dynamic_pointer_cast<CIString>(pInInstruction);
		if (pStringOp)
			pOutInstruction = make_shared<CCStringOp>(pStringOp);

		shared_ptr<CIConditionalJump> pConditionalJump = dynamic_pointer_cast<CIConditionalJump>(pInInstruction);
		if (pConditionalJump)
        {
			pOutInstruction = make_shared<CCConditionalJump>( pConditionalJump, pPrevious );
            if (pConditionalJump->m_label == strFunction)
                dynamic_pointer_cast<CCConditionalJump>(pOutInstruction)->m_eLabelType = CCConditionalJump::Entry;
        }

		shared_ptr<CIJump> pJump = dynamic_pointer_cast<CIJump>(pInInstruction);
		if (pJump)
        {
			pOutInstruction = make_shared<CCConditionalJump>( pJump );
            if (pJump->m_label == strFunction)
                dynamic_pointer_cast<CCConditionalJump>(pOutInstruction)->m_eLabelType = CCConditionalJump::Entry;
        }

		shared_ptr<CILabel> pLabel = dynamic_pointer_cast<CILabel>(pInInstruction);
		if (pLabel)
			pOutInstruction = make_shared<CCLabel>( pLabel );

		shared_ptr<CICall> pCall = dynamic_pointer_cast<CICall>(pInInstruction);
		if (pCall)
			pOutInstruction = make_shared<CCCall>( pCall, pPrevious );

        shared_ptr<CIIndirectCall> pIndirectCall = dynamic_pointer_cast<CIIndirectCall>(pInInstruction);
        if (pIndirectCall)
            pOutInstruction = make_shared<CCIndirectCall>(pIndirectCall);

        shared_ptr<CIAbbrev> pAbbrev = dynamic_pointer_cast<CIAbbrev>(pInInstruction);
        if (pAbbrev)
            pOutInstruction = make_shared<CCAbbrev>(pAbbrev);

		shared_ptr<CISwitch> pSwitch = dynamic_pointer_cast<CISwitch>(pInInstruction);
		if (pSwitch)
		{
            if (pSwitch->m_label.find("ss:off") == string::npos)
            {
                vector<shared_ptr<CInstruction>> arrOptions = GetDataStarting(pSwitch->m_label);
                pOutInstruction = make_shared<CCSwitch>( pSwitch, arrOptions );
            } else {
                pOutInstruction = make_shared<CCStop>(xxx);
            }
		}

		shared_ptr<CILoop> pLoop = dynamic_pointer_cast<CILoop>(pInInstruction);
		if (pLoop)
		{
			if ( pLoop->m_eType != CILoop::Loop )
			{
				_ASSERT(pPrevious);
			}

			pOutInstruction = make_shared<CCConditionalJump>( pLoop, pPrevious );

            if (pLoop->m_label == strFunction)
                dynamic_pointer_cast<CCConditionalJump>(pOutInstruction)->m_eLabelType = CCConditionalJump::Entry;
		}
		
        shared_ptr<CIStop> pStop = dynamic_pointer_cast<CIStop>(pInInstruction);
        if (pStop)
            pOutInstruction = make_shared<CCStop>(pStop);

        if (pOutInstruction)
        {
            pOutInstruction->mOrigin = pInInstruction->m_origin;
            _ASSERT(pOutInstruction);
        }
		return pOutInstruction;
	}
    
    bool CheckCarryReturn(shared_ptr<CInstruction>& instr)
    {
        shared_ptr<CIZeroArgOp> zeroOp = dynamic_pointer_cast<CIZeroArgOp>(instr);
        if (!zeroOp)
            return false;
        return zeroOp->m_eType == CIZeroArgOp::stc || zeroOp->m_eType == CIZeroArgOp::clc;
    }
    
    bool CheckCarryReturn(CLabel label)
    {
        vector<shared_ptr<CInstruction>> arrFunction = GetSubCode(m_arrSource, label);
        _ASSERT(arrFunction.size() > 0);
        for (int i=1; i<arrFunction.size(); i++)
        {
            if (dynamic_pointer_cast<CIReturn>(arrFunction[i]))
            {
                if (!CheckCarryReturn(arrFunction[i-1]))
                    return false;
            }
        }
        return true;
    }
    
	shared_ptr<CInstruction> TracebackCondition(CIConditionalJump::EType eType, vector<shared_ptr<CInstruction>>& arrInput, int nLine)
	{
        if (eType == CIConditionalJump::jcxz)
            return nullptr;
        
		for (int nTraceBack=nLine; nTraceBack>=max(0, nLine-10); nTraceBack--)
		{
			shared_ptr<CInstruction> pPrev = nTraceBack > 0 ? arrInput[nTraceBack-1] : nullptr;
			shared_ptr<CInstruction> pInstruction = arrInput[nTraceBack];
			/*
			if ( eType == CIConditionalJump::jb )
			{
				//carry 
				shared_ptr<CIAlu> pAlu = dynamic_pointer_cast<CIAlu>(pInstruction);
				if (pAlu->m_eType == CIAlu::Decrement)
					return pAlu;

				shared_ptr<CIZeroArgOp> pZeroArgOp = dynamic_pointer_cast<CIZeroArgOp>(pInstruction);
				if ( pZeroArgOp->m_eType == CIZeroArgOp::sahf
				continue;
			}*/

			if (dynamic_pointer_cast<CITest>(pInstruction) || dynamic_pointer_cast<CICompare>(pInstruction) ||
				dynamic_pointer_cast<CIAlu>(pInstruction) ||
                dynamic_pointer_cast<CITwoArgOp>(pInstruction))
			{
				return pInstruction;
			}
			if (dynamic_pointer_cast<CIConditionalJump>(pInstruction) || dynamic_pointer_cast<CILoop>(pInstruction) )
			{
				continue;
			}
			if (dynamic_pointer_cast<CISingleArgOp>(pInstruction) && dynamic_pointer_cast<CISingleArgOp>(pInstruction)->m_eType == CISingleArgOp::pop)
			{
				continue;
			}
			if (dynamic_pointer_cast<CISingleArgOp>(pInstruction) && dynamic_pointer_cast<CISingleArgOp>(pInstruction)->m_eType == CISingleArgOp::interrupt)
			{
				return pInstruction;
			}
			if ( dynamic_pointer_cast<CILabel>(pInstruction) && dynamic_pointer_cast<CIJump>(pPrev) )
			{
				vector<int> arrRefs = FindReferences(arrInput, dynamic_pointer_cast<CILabel>(pInstruction)->m_label);
				if (arrRefs.size() == 1)
                    return TracebackCondition(eType, arrInput, arrRefs[0]);
                else
                    return nullptr;
			}
			if (dynamic_pointer_cast<CICall>(pInstruction))
			{
                if (_ReturnsCarry(dynamic_pointer_cast<CICall>(pInstruction)->m_label))
                    return make_shared<CIZeroArgOp>( CIZeroArgOp::FakeCarryTest );
                if (_ReturnsZero(dynamic_pointer_cast<CICall>(pInstruction)->m_label))
                    return make_shared<CIZeroArgOp>( CIZeroArgOp::FakeZeroTest );

                if (CheckCarryReturn(dynamic_pointer_cast<CICall>(pInstruction)->m_label))
                    return make_shared<CIZeroArgOp>( CIZeroArgOp::FakeCarryTest );
                else
                {
                    //_ASSERT(0);
                    return make_shared<CIStop>(pInstruction);
                }
                
				return pInstruction;
			}
		}
        return make_shared<CIStop>();
		//_ASSERT(0);
		//return nullptr;
	}

    void Convert(CLabel strFunction, vector<shared_ptr<CInstruction>>& arrInput, vector<shared_ptr<CCInstruction>>& arrOutput)
	{
		shared_ptr<CCInstruction> pPrev;

		for (int i=0; i<(int)arrInput.size(); i++)
		{
            //std::cout << arrInput[i]->m_origin << "\n";
			shared_ptr<CInstruction> pInInstruction = arrInput[i];
			shared_ptr<CInstruction> pCondition = i > 0 ? arrInput[i-1] : nullptr;
			/*
			if (dynamic_pointer_cast<CITwoArgOp>(pInInstruction) && 
				(dynamic_pointer_cast<CITwoArgOp>(pInInstruction)->m_eType == CITwoArgOp::rcl ||
				 dynamic_pointer_cast<CITwoArgOp>(pInInstruction)->m_eType == CITwoArgOp::rcr ))
			{
				pCondition = TracebackCondition(CIConditionalJump::jb, arrInput, i-1);
			}

			if (dynamic_pointer_cast<CIAlu>(pInInstruction) && 
				dynamic_pointer_cast<CIAlu>(pInInstruction)->m_eType == CIAlu::AddWithCarry )
			{
				pCondition = TracebackCondition(CIConditionalJump::jb, arrInput, i-1);
			}
			*/
			if (dynamic_pointer_cast<CIConditionalJump>(pInInstruction))
			{
				pCondition = TracebackCondition(dynamic_pointer_cast<CIConditionalJump>(pInInstruction)->m_eType, arrInput, i-1);
			}
			if (dynamic_pointer_cast<CILoop>(pInInstruction) && dynamic_pointer_cast<CILoop>(pInInstruction)->m_eType == CILoop::WhileEqual)
			{
				pCondition = TracebackCondition(CIConditionalJump::jz, arrInput, i-1);
			}
			if (dynamic_pointer_cast<CILoop>(pInInstruction) && dynamic_pointer_cast<CILoop>(pInInstruction)->m_eType == CILoop::WhileNotEqual)
			{
				pCondition = TracebackCondition(CIConditionalJump::jnz, arrInput, i-1);
			}

			shared_ptr<CCInstruction> pOutInstruction = Convert(strFunction, pInInstruction, pCondition);
            
            if (!pOutInstruction)
				continue;

            if (pOutInstruction->mDropPrevious)
                arrOutput.pop_back();

			if (pOutInstruction->TryJoin(pPrev))
				arrOutput.pop_back();

			//printf("%s\n", pOutInstruction->ToString().c_str());
			pPrev = pOutInstruction;
			arrOutput.push_back(pOutInstruction);
		}

		if ( !arrOutput.empty() && arrOutput.back()->ToString() == "return;" )
			arrOutput.pop_back();
	}

	void DumpProgram(vector<shared_ptr<CCInstruction>>& arrOutput, int nBaseIndent = 0)
	{
		int nIndent = 0;
		for (int i=0; i<(int)arrOutput.size(); i++)
		{	
			if ( !dynamic_pointer_cast<CCSwitch>(arrOutput[i]) )
			{
				if ( arrOutput[i]->ToString().find("}") != string::npos )
					nIndent--;
			}

			string strPad;
			if ( !dynamic_pointer_cast<CCLabel>(arrOutput[i]) )
				for (int j=0; j<nBaseIndent + nIndent; j++)
					strPad += "    ";

			string all(arrOutput[i]->ToString());
			CUtils::replace(all, "\r", "\n"); 
			istringstream is(all);
			string line;
			while (getline(is, line, '\n'))
				printf("%s%s\n", strPad.c_str(), line.c_str());

			if ( arrOutput[i]->ToString().find("{") != string::npos )
				nIndent++;
		}
	}

	void DumpProgram(vector<string>& out, vector<shared_ptr<CCInstruction>>& arrOutput, int nBaseIndent = 0)
	{
        //vector<string> outBuf;
		int nIndent = 0;
		for (int i=0; i<(int)arrOutput.size(); i++)
		{	
			if ( !dynamic_pointer_cast<CCSwitch>(arrOutput[i]) )
			{
                if ( arrOutput[i]->ToString().find("{") != string::npos && arrOutput[i]->ToString().find("}") != string::npos)
                {
                }
                else if ( arrOutput[i]->ToString().find("}") != string::npos )
					nIndent--;
			}

			string strPad;
			if ( !dynamic_pointer_cast<CCLabel>(arrOutput[i]) )
				for (int j=0; j<nBaseIndent + nIndent; j++)
					strPad += "    ";

			string all(arrOutput[i]->ToString());
			CUtils::replace(all, "\r", "\n"); 
			istringstream is(all);
			string line;
            bool first = true;
			while (getline(is, line, '\n'))
            {
                if (first)
                {
                    first = false;
                    if (line.length() < 50)
                    {
                        while (line.length() + strPad.length() < 48)
                            line += " ";
                        //TODO: f call
                        line += "//" + arrOutput[i]->mOrigin;
                    }
                }
                
				out.push_back(strPad+line);
            }

			if ( !dynamic_pointer_cast<CCSwitch>(arrOutput[i]) )
			{
                if ( arrOutput[i]->ToString().find("{") != string::npos && arrOutput[i]->ToString().find("}") != string::npos)
                {
                }
                else if ( arrOutput[i]->ToString().find("{") != string::npos )
					nIndent++;
			}
		}
	}

	// TODO: Duplicity
	int FindLabel(const vector<shared_ptr<CInstruction>>& arrCode, string label)
	{
		for (int i=0; (size_t)i<arrCode.size(); i++)
		{
			shared_ptr<CIFunction> pFunction = dynamic_pointer_cast<CIFunction>(arrCode[i]);
			if (pFunction && pFunction->m_eBoundary == CIFunction::Begin && pFunction->m_strName == label)
			{
				return i;
			}
            shared_ptr<CILabel> pLabel = dynamic_pointer_cast<CILabel>(arrCode[i]);
            if (pLabel && pLabel->m_label == label)
            {
                return i;
            }
		}
		_ASSERT(0);
		return -1;
	}

    vector<string> GetFunctionList(const vector<shared_ptr<CInstruction>>& arrCode)
    {
        vector<string> names;
        
        bool inFunction = false;
        for (int i=0; (size_t)i<arrCode.size(); i++)
        {
            shared_ptr<CIFunction> pFunction = dynamic_pointer_cast<CIFunction>(arrCode[i]);
            if (pFunction && pFunction->m_eBoundary == CIFunction::Begin)
            {
                names.push_back(pFunction->m_strName);
                inFunction = true;
            }
            if (pFunction && pFunction->m_eBoundary == CIFunction::End)
            {
                inFunction = false;
            }
            
            if (!inFunction)
            {
                shared_ptr<CILabel> pLabel = dynamic_pointer_cast<CILabel>(arrCode[i]);
                if (pLabel)
                {
                    names.push_back(pLabel->m_label);
                    inFunction = true;
                }
            }
        }
        return names;
    }
    
    vector<shared_ptr<CInstruction>> GetSubCode(const vector<shared_ptr<CInstruction>>& arrCode, CLabel label)
	{
		vector<shared_ptr<CInstruction>> aux;

		int nBegin = FindLabel(arrCode, label);
		_ASSERT(nBegin >= 0);
		for (int i=nBegin+1; i<(int)arrCode.size(); i++)
        {
            shared_ptr<CIFunction> pFunc = dynamic_pointer_cast<CIFunction>(arrCode[i]);
            if (pFunc && pFunc->m_eBoundary == CIFunction::EndFail)
            {
                aux.push_back(make_shared<CIStop>(arrCode[i], "sp-trace-fail"));
                aux.push_back(make_shared<CIStop>(arrCode[i+1], "continues"));
            }
            if (pFunc)
                break;
			aux.push_back(arrCode[i]);
        }

		return move(aux);
	}
    void SetSource(const vector<shared_ptr<CInstruction>>& arrSource)
    {
        m_arrSource = arrSource;
    }

};
