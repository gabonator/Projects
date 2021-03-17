//
//  main.cpp
//  CicParser2021
//
//  Created by Gabriel Valky on 12/14/20.
//

#include <iostream>
#include <regex>
#include <map>
#include <utility>
#include <fstream>
#include <sstream>
#include <set>

// hladaj //gg
using namespace std;

#define _STATIC_ASSERT static_assert
#define _ASSERT assert
#define CheckEnum2(s, e) if (str==s) return e;
#define CheckEnum(e) if (str==#e) return e;
#include "utils.h"

std::map<string, regex> CUtils::m_mapCache;

#include "serializer.h"

#include "value.h"
#include "label.h"

class CMachine;

#include "instructions.h"
#include "matchers.h"

// Matchers
#include "parser.h"
#include "dummy.h"

// Export
#include "cinstructions.h"
#include "cexport.h"
#include "cvalue.h"

#include "json.h"

class CCustomize
{
public:
    struct segmentInfo_t {
        char name[32];
        int begin;
        int end;
        int base;
    };
    
    vector<segmentInfo_t> mSegments;
    vector<pair<string, string>> mFuncDescription;
    set<string> mFuncGlobalExit;
    set<string> mFuncVideoEs;
    set<string> mFuncVideoDs;
    set<string> mFuncBiosEs;
    set<string> mFuncReturnCarry;
    set<string> mFuncReturnZero;
    vector<string> mArguments;
    vector<string> mFuncList;
    vector<string> mNewArguments;
    string mDefaultMemory{"MemAuto"};
    string mDefaultDirection{"DirAuto"};

    void addSegmentInfo(string name, int begin, int end, int base)
    {
        segmentInfo_t newSegment;
        _ASSERT(name.length() < sizeof(newSegment.name)-1);
        strcpy(newSegment.name, name.c_str());
        newSegment.begin = begin;
        newSegment.end = end;
        newSegment.base = base;
        
        mSegments.push_back(newSegment);
    }

    string GetFunctionDesc(string fname)
    {
        for (auto iter = mFuncDescription.begin(); iter != mFuncDescription.end(); iter++)
            if (iter->first == fname)
                return iter->second;
        return "";
    }
    bool GlobalExitLabel(const string& fname)
    {
        return mFuncGlobalExit.find(fname) != mFuncGlobalExit.end();
    }
    bool isUsingVideoEs(const string& fname)
    {
        return mFuncVideoEs.find(fname) != mFuncVideoEs.end();
    }
    bool isUsingVideoDs(const string& fname)
    {
        return mFuncVideoDs.find(fname) != mFuncVideoDs.end();
    }
    bool isUsingBiosEs(const string& fname)
    {
        return mFuncBiosEs.find(fname) != mFuncBiosEs.end();
    }
    bool isReturningCarry(const string& fname)
    {
        return mFuncReturnCarry.find(fname) != mFuncReturnCarry.end();
    }
    bool isReturningZero(const string& fname)
    {
        return mFuncReturnZero.find(fname) != mFuncReturnZero.end();
    }
    int fixPtr(int ofs)
    {
        for (int i=0; i<mSegments.size(); i++)
        {
            if (ofs >= mSegments[i].base*16 + mSegments[i].begin &&
                ofs < mSegments[i].base*16 + mSegments[i].end)
            {
                return ofs - mSegments[i].base*16;
            }
        }
        _ASSERT(0);
        return ofs;
    }

};
/*
{ // rick2
"seg000", 0, 0x10400-0x10000, 0x1000,
"seg001", 0, 0x1c4ef-0x10400, 0x1040,
    {"", 0, 0, 0}
};
*/

CSourceParser sp;
CCExport e;
CCustomize custom;

string _DefaultDirection()
{
    return custom.mDefaultDirection;
}

string _DefaultMemory()
{
    return custom.mDefaultMemory;
}

bool _ReturnsCarry(string name)
{
    return custom.isReturningCarry(name);
}
bool _ReturnsZero(string name)
{
    return custom.isReturningZero(name);
}

int FixPtr(int ofs)
{
    return custom.fixPtr(ofs);
}

bool doParse(string asmPath)
{
    sp.Parse(asmPath.c_str());
    return true;
}

bool doSave(string xPath)
{
    sp.Save(xPath.c_str());
    return true;
}

bool doLoad(string xPath)
{
    sp.Load(xPath.c_str());
    return true;
}

bool doGetAllFunctions(std::vector<string>& flist)
{
    e.SetSource(sp.m_arrCode);
    flist = e.GetFunctionList(sp.m_arrCode);
    return true;
}

bool doExport(ostream& output, std::vector<string>& flist)
{
    e.SetSource(sp.m_arrCode);
    
    std::set<string> imports;
    
    for (int i=0; i<flist.size(); i++)
    {
        CLabel testLabel(flist[i]);
        output << "void " << testLabel << "();" << endl;
    }
    std::cout << endl;
    
    for (int i=0; i<flist.size(); i++)
    {
        CLabel testLabel(flist[i]);
    
        vector<shared_ptr<CInstruction>> arrFunction = e.GetSubCode(sp.m_arrCode, testLabel);
        vector<shared_ptr<CCInstruction>> arrCFunction;
        std::set<string> internalLabels;

        for (int j=0; j<arrFunction.size(); j++)
        {
            shared_ptr<CILabel> pLabel = dynamic_pointer_cast<CILabel>(arrFunction[j]);
            if (pLabel)
            {
                internalLabels.insert(pLabel->m_label);
            }

            shared_ptr<CIJump> pJump = dynamic_pointer_cast<CIJump>(arrFunction[j]);
            if (pJump && custom.GlobalExitLabel(pJump->m_label))
            {
                arrFunction[j] = make_shared<CIStop>(pJump, "exit program");
            }
            
        }
        for (int j=0; j<arrFunction.size(); j++)
        {
            shared_ptr<CIJump> pJump = dynamic_pointer_cast<CIJump>(arrFunction[j]);
            if (pJump)
            {
                if (internalLabels.find(pJump->m_label) == internalLabels.end())
                {
                    string labelAsFunction = pJump->m_label;
                    CUtils::replace(labelAsFunction, "loc_", "sub_");

                    if (pJump->m_label == testLabel)
                    {
                        
                    } else
                    if (std::find(flist.begin(), flist.end(), pJump->m_label) != flist.end())
                    {
                        // is function
                        arrFunction[j] = make_shared<CICall>(pJump->m_label, CICall::Jump);
                    } else
                    if (std::find(flist.begin(), flist.end(), labelAsFunction) != flist.end())
                    {
                        // label as function
                        arrFunction[j] = make_shared<CICall>(labelAsFunction, CICall::Jump);
                    } else
                        pJump->m_stop = true;
                }
            }
            shared_ptr<CIConditionalJump> pCond = dynamic_pointer_cast<CIConditionalJump>(arrFunction[j]);
            if (pCond)
            {
                if (internalLabels.find(pCond->m_label) == internalLabels.end())
                {
                    if (pCond->m_label != testLabel)
                        pCond->m_stop = true;
                }
            }
            shared_ptr<CILoop> pLoop = dynamic_pointer_cast<CILoop>(arrFunction[j]);
            if (pLoop)
            {
                if (internalLabels.find(pLoop->m_label) == internalLabels.end())
                {
                    if (pLoop->m_label != testLabel)
                        pLoop->m_stop = true;
                }
            }
        }

        // Two pass for alu conditional injections
        e.Convert(testLabel, arrFunction, arrCFunction);
        arrCFunction.clear();
        e.Convert(testLabel, arrFunction, arrCFunction);
        
        for (int i=0; i<arrCFunction.size(); i++)
        {
            shared_ptr<CCCall> pCall = dynamic_pointer_cast<CCCall>(arrCFunction[i]);
            if (pCall)
            {
                string label = pCall->m_strCall;
                
                vector<string> arrMatches;

                // assignment
                if (label.find("indirect") != string::npos)
                {
                } else
                if ( CUtils::match("^\\{?(.*)\\(\\).*$", label, arrMatches) )
                {
                    imports.insert(arrMatches[0]);
                } else {
                    _ASSERT(0);
                }
            }
            shared_ptr<CCSwitch> pSwitch = dynamic_pointer_cast<CCSwitch>(arrCFunction[i]);
            if (pSwitch)
            {
                for (int j=0; j<pSwitch->m_arrLabels.size(); j++)
                    imports.insert(pSwitch->m_arrLabels[j]);
            }
        }
        
        vector<string> outLines;
        e.DumpProgram(outLines, arrCFunction, 1);
        if (arrCFunction.size() > 0 && dynamic_pointer_cast<CCLabel>(arrCFunction[arrCFunction.size()-1]))
            outLines.push_back("    return;");
        
        string entryLabel(testLabel);
        CUtils::replace(entryLabel, "sub_", "loc_");

        // post process
        bool usingEntry = false;
        bool usingCs = false;
        bool usingVideoEs = custom.isUsingVideoEs(testLabel);
        bool usingVideoDs = custom.isUsingVideoDs(testLabel);
        bool usingBiosEs = custom.isUsingBiosEs(testLabel);
        string csValue;

        for (int i=0; i<outLines.size(); i++)
        {
            string& line = outLines[i];
            if (line.find(entryLabel) != string::npos)
            {
                if (line.find("//") == string::npos || line.find(entryLabel) < line.find("//"))
                    // insert entry label
                    usingEntry = true;
            }
            if (line.find("_cs") != string::npos)
            {
                usingCs = true;
            }
            
            if (usingVideoEs)
            {
                vector<string> arrMatches;

                // assignment
                if ( CUtils::match("^(.*)(memory|memory16)\\(_es, (.*)\\) (=|&=|\\|=|\\^=) (.*);( *)//(.*)$", line, arrMatches) )
                {
                    // prefix, memory, offset, value, space, comment
                    stringstream ss;
                    ss << arrMatches[0];
                    if (arrMatches[3] == "=")
                        ss << (arrMatches[1] == "memory" ? "memoryVideoSet" : "memoryVideoSet16");
                    else if (arrMatches[3] == "|=")
                        ss << (arrMatches[1] == "memory" ? "memoryVideoOr" : "memoryVideoOr16");
                    else if (arrMatches[3] == "&=")
                        ss << (arrMatches[1] == "memory" ? "memoryVideoAnd" : "memoryVideoAnd16");
                    else if (arrMatches[3] == "^=")
                        ss << (arrMatches[1] == "memory" ? "memoryVideoXor" : "memoryVideoXor16");

                    ss << "(_es, " << arrMatches[2] << ", " << arrMatches[4] << ");";
                    while (ss.str().length() < 48)
                        ss << " ";
                    ss << "//" << arrMatches[6];
                    line = ss.str();
                }
                
                arrMatches.clear();
                // read
                if ( CUtils::match("^(.*)(memory|memory16)\\(_es, (.*)\\)(.*?)( *)//(.*)$", line, arrMatches) )
                {
                    // prefix, memory, offset, suffix, space, comment
                    stringstream ss;
                    ss << arrMatches[0];
                    ss << (arrMatches[1] == "memory" ? "memoryVideoGet" : "memoryVideoGet16");
                    ss << "(_es, " << arrMatches[2] << ")" << arrMatches[3];
                    while (ss.str().length() < 48)
                        ss << " ";
                    ss << "//" << arrMatches[5];
                    //line = arrMatches[0] + (arrMatches[1] == "memory") ? "memoryVideoSet" : "memoryVideoSet16";
                    //line += string("(")
                    line = ss.str();
                }
                
                arrMatches.clear();
                if ( CUtils::match("^(.*)<(.*), (.*), (Dir.*)>\\(\\);.*$", line, arrMatches) )
                {
                    arrMatches[1] = "MemVideo";
                    line = arrMatches[0] + "<" + arrMatches[1] + ", " + arrMatches[2] + ", " + arrMatches[3] + ">();";
                }

                arrMatches.clear();
                if ( CUtils::match("^(.*sto.*)<(.*), (Dir.*)>\\(\\);.*$", line, arrMatches) )
                {
                    arrMatches[1] = "MemVideo";
                    line = arrMatches[0] + "<" + arrMatches[1] + ", " + arrMatches[2] + ">();";
                }
            }

            if (usingVideoDs)
            {
                vector<string> arrMatches;
                if ( CUtils::match("^(.*)<(.*), (.*), (Dir.*)>\\(\\);.*$", line, arrMatches) )
                {
                    arrMatches[2] = "MemVideo";
                    line = arrMatches[0] + "<" + arrMatches[1] + ", " + arrMatches[2] + ", " + arrMatches[3] + ">();";
                }

                arrMatches.clear();
                if ( CUtils::match("^(.*lod.*)<(.*), (Dir.*)>\\(\\);.*$", line, arrMatches) )
                {
                    arrMatches[1] = "MemVideo";
                    line = arrMatches[0] + "<" + arrMatches[1] + ", " + arrMatches[2] + ">();";
                }
            }
            
            if (usingBiosEs)
            {
                vector<string> arrMatches;

                // assignment
                if ( CUtils::match("^(.*)(memory|memory16)\\(_es, (.*)\\) = (.*);( *)//(.*)$", line, arrMatches) )
                {
                    // prefix, memory, offset, value, space, comment
                    stringstream ss;
                    ss << arrMatches[0];
                    ss << (arrMatches[1] == "memory" ? "memoryBiosSet" : "memoryBiosSet16");
                    ss << "(_es, " << arrMatches[2] << ", " << arrMatches[3] << ");";
                    while (ss.str().length() < 48)
                        ss << " ";
                    ss << "//" << arrMatches[5];
                    //line = arrMatches[0] + (arrMatches[1] == "memory") ? "memoryVideoSet" : "memoryVideoSet16";
                    //line += string("(")
                    line = ss.str();
                }
                
                arrMatches.clear();
                // read
                if ( CUtils::match("^(.*)(memory|memory16)\\(_es, (.*)\\)(.*?)( *)//(.*)$", line, arrMatches) )
                {
                    // prefix, memory, offset, suffix, space, comment
                    stringstream ss;
                    ss << arrMatches[0];
                    ss << (arrMatches[1] == "memory" ? "memoryBiosGet" : "memoryBiosGet16");
                    ss << "(_es, " << arrMatches[2] << ")" << arrMatches[3];
                    while (ss.str().length() < 48)
                        ss << " ";
                    ss << "//" << arrMatches[5];
                    //line = arrMatches[0] + (arrMatches[1] == "memory") ? "memoryVideoSet" : "memoryVideoSet16";
                    //line += string("(")
                    line = ss.str();
                }
            }

        }
                
        if (usingCs)
        {
            int nBegin = e.FindLabel(sp.m_arrCode, testLabel);

            for (int k=nBegin; k>=0; k--)
            {
                shared_ptr<CISegment> pSegment = dynamic_pointer_cast<CISegment>(sp.m_arrCode[k]);
                if (pSegment)
                {
                    csValue = pSegment->m_strSegmentName;
                    break;
                }
            }
            _ASSERT(!csValue.empty());
            stringstream ss;
            ss << "    WORD _cs = _" << csValue << ";" << endl;
            outLines.insert(outLines.begin(), ss.str());
        }

        if (usingEntry)
        {
            outLines.insert(outLines.begin(), entryLabel + ":");
        }

        output << "void " << testLabel << "()";
        string comment = custom.GetFunctionDesc(testLabel);
        if (!comment.empty())
            output << "  // " << comment;
        output << endl << "{" << endl;
        for (int i=0; i<outLines.size(); i++)
            output << outLines[i] << endl;
        output << "}" << endl << endl;
    }
    
    for (int i=0; i<flist.size(); i++)
    {
        imports.erase(flist[i]);
    }
    if (imports.size() > 0)
    {
        output << endl << "// imports" << endl;
        for (const string& s : imports)
        {
            output << "void " << s << "() { _ASSERT(0); }" << endl;
        }
    }
    output << endl;
    return true;
}

void doConfig(const string& jsonFile)
{
    std::ifstream t(jsonFile);
    std::string strConfig((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());
    
    CJson json(strConfig.c_str());
    if (json["segments"])
    {
        json["segments"].ForEach([](const CSubstring& sub){
            CJson segment(sub);
            
            CCustomize::segmentInfo_t seg;
            
            strcpy(seg.name, segment["name"].GetString());
            seg.begin = 0; //segment["begin"].GetNumber();
            seg.end = segment["end"].GetNumber() - segment["begin"].GetNumber();
            seg.base = segment["begin"].GetNumber() / 16;
            
            custom.mSegments.push_back(seg);
        });
    }
    if (json["cli"])
    {
        custom.mNewArguments.clear();
        json["cli"].ForEach([](const CSubstring& sub){
            custom.mNewArguments.push_back(CJson(sub).GetString());
        });
    }
    if (json["hints"])
    {
        json["hints"].ForEach([](const CSubstring& func, const CSubstring& attrsSub){
            char funcName[64];
            func.ToString(funcName, 64);
            CJson attrs(attrsSub);
            if (string(attrs["es"].GetString()) == "video")
                custom.mFuncVideoEs.insert(funcName);
            if (string(attrs["ds"].GetString()) == "video")
                custom.mFuncVideoDs.insert(funcName);
            if (string(attrs["es"].GetString()) == "bios")
                custom.mFuncBiosEs.insert(funcName);
            if (string(attrs["return"].GetString()) == "carry")
                custom.mFuncReturnCarry.insert(funcName);
            if (string(attrs["return"].GetString()) == "zero")
                custom.mFuncReturnZero.insert(funcName);
        });
    }
    if (json["defaults"])
    {
        custom.mDefaultMemory = json["defaults"]["memory"].GetString();
        custom.mDefaultDirection = json["defaults"]["direction"].GetString();
    }
}

vector<string> explode(string const & s, char delim)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
        result.push_back(move(token));

    return result;
}

void doFunctions(string funcs)
{
    custom.mFuncList.clear();
    if (funcs == "all")
    {
        doGetAllFunctions(custom.mFuncList);
        return;
    }
    
    custom.mFuncList = explode(funcs, ',');
    _ASSERT(custom.mFuncList.size() > 0);
}

int main(int argc, const char * argv[])
{
    ofstream outputFile;
    ostream* output = &cout;
        
    for (int i=1; i<argc; i++)
        custom.mArguments.push_back(argv[i]);
    
    // TEST:
    //custom.mArguments = {"-config", "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Parser/test/config.cfg"};

    custom.mArguments = {"-config", "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputRick2/cico.cfg"};

    for (auto it = custom.mArguments.begin(); it != custom.mArguments.end(); )
    {
        if (*it == "-config")
        {
            it++;
            doConfig(*it);
            if (custom.mNewArguments.size())
            {
                custom.mArguments = std::move(custom.mNewArguments);
                it = custom.mArguments.begin();
                continue;
            }
            it++;
            continue;
        }
        if (*it == "-parse")
        {
            it++;
            doParse(*it);
            it++;
            continue;
        }
        if (*it == "-save")
        {
            it++;
            doSave(*it);
            it++;
            continue;
        }
        if (*it == "-load")
        {
            it++;
            doLoad(*it);
            it++;
            continue;
        }
        if (*it == "-functions")
        {
            it++;
            doFunctions(*it);
            it++;
            continue;
        }
        if (*it == "-export")
        {
            it++;
            if (it != custom.mArguments.end() && it->c_str()[0] != '-')
            {
                // export to file
                outputFile.open(*it);
                it++;
                
                output = &outputFile;
            }
            
            doExport(*output, custom.mFuncList);
            
            if (outputFile.is_open())
                outputFile.close();
            
            output = &cout;
            continue;
        }
        
        cout << "Unsupported command: " << *it;
        return 1;
    }
    /*
    // -c config -p parse.asm -s interm.x
    // -l interm.x -f all -x [out.cpp]
    
    //doConfig("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Parser/test/config.cfg");
    //doParse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Parser/test/input.asm");
    //doSave("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Parser/test/input.x");
    doLoad("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Parser/test/input.x");
    
    std::vector<string> flist;
    doGetAllFunctions(flist);
    ostream& out = cout;
    
    doExport(out, flist);
    */
    return 0;
}
