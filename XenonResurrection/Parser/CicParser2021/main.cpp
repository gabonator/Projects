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

#include "reganalysis.h"
#include "instructions.h"
#include "matchers.h"

// Matchers
#include "parser.h"
#include "dummy.h"



// Export
#include "cinstructions.h"
#include "cexport.h"
#include "cvalue.h"

class CCustomize
{
public:
    string GetFunctionDesc(string fname)
    {
        #define D(sub, comment) if (fname == sub) return comment;
        D("sub_15C8B", "load all files: x2spr.dat, x2weaps.dat, shop.dat, gr.dat");
        D("sub_10DA3", "Fix bitmap?");
        D("sub_1011C", "Opens and reads whole file");
        D("sub_104C9", "Read data")
        D("sub_10174", "Read data")
        D("sub_100CF", "Main game loop")
        D("sub_10FDA", "Draw sprite")
        D("sub_132FE", "Draw map")
        D("sub_13383", "Swap pages")
        D("sub_133D7", "V sync")
        D("sub_134A8", "Draw lines")
        D("sub_1069A", "Draw map")
        D("sub_10BDC", "Draw tile")
        D("sub_12E02", "Tunnel grid")
        D("sub_1300A", "Tunnel")
          
        //
        D("sub_160EF", "Joystick")
        D("sub_1F492", "Starfields")
        D("sub_2058D", "Clear screen")
        D("sub_1595D", "Label with startfields")
        D("sub_1F3D7", "Set palette")
        #undef D
        return "";
    }
    bool GlobalExitLabel(const string& fname)
    {
        // not implemented
        return fname == "loc_15E04";
    }
    bool isUsingVideoEs(const string& fname)
    {
        static bool init=true;
        static std::set<string> funcs;
        if (init)
        {
            init = false;
            std::vector<string> flist = {
                "sub_1487F", "sub_1793C", "sub_17D17", "sub_179E3", "sub_17B9A", "sub_17BCB", "sub_17DD8",
                "sub_17D32", "sub_17F7B", "sub_14791", "sub_147E7", "sub_14BFA", "sub_14CE4", "sub_14E74",
                "sub_15C79", "sub_1610E", "sub_167C7", "sub_1763F", "sub_17680", "sub_14F52", "sub_168F2",
                "loc_16D3D", "sub_16D16", "loc_16E88", "sub_16E59", "sub_16F07", "sub_16F47", "sub_16FAB",
                "sub_1741F", "sub_174D1", "sub_1752C", "sub_1756C", "sub_175AC", "sub_175D0", "sub_176C7",
                "sub_17738", "sub_16138", "sub_1616A", "sub_16184", "sub_161B6", "sub_161D8", "sub_16F87"
            };
            funcs.insert(flist.begin(), flist.end());
        }
        return funcs.find(fname) != funcs.end();
    }
    
    bool isUsingBiosEs(const string& fname)
    {
        static bool init=true;
        static std::set<string> funcs;
        if (init)
        {
            init = false;
            std::vector<string> flist = {
                "sub_180A7"
            };
            funcs.insert(flist.begin(), flist.end());
        }
        return funcs.find(fname) != funcs.end();
    }
    
};

int main(int argc, const char * argv[])
{
    // insert code here...
    
    CSourceParser sp;

//    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon5.asm");
//    sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon5.x");
//    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGoose/GOOSE.asm");
//    sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGoose/GOOSE.x");
//
//    return 0;

    //sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon5.x");
//    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGoose/GOOSE.x");
//    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputJbird/jbird.asm");
//    sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputJbird/jbird.x");
    //sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputJbird/jbird.x");
        
//        sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/ETETRIS.asm");
//        sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/tetris.x");
//        sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/tetris.x");

    
//        sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/fox.asm");
//        sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/fox.x");
//        sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/fox.x");

//            sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputPopcorn/popcorn.asm");
//            sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputPopcorn/popcorn.x");
            //sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputPopcorn/popcorn.x");

//    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/ETETRIS.asm");
//    sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/tetris.x");
//    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/tetris.x");

//        sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGolden/GOLD.asm");
//        sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGolden/gold.x");
//        sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGolden/gold.x");

//            sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/unpacked.asm");
//            sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/fox.x");
//            sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/fox.x");

//                sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputCdman/CD-MAN.asm");
//                sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputCdman/cdman.x");
                sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputCdman/cdman.x");

    
    CCExport e;
    e.SetSource(sp.m_arrCode);
    
    std::vector<string> flist;

    CCustomize custom;
    std::set<string> imports;
    auto& output = cout;
    
    flist = e.GetFunctionList(sp.m_arrCode);
    
//    ofstream output;
//    output.open("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/SimulatorGoose/CicParserSim/code-goose.h");
    
    for (int i=0; i<flist.size(); i++)
    {
        CLabel testLabel(flist[i]);
        output << "void " << testLabel << "();" << endl;
    }
    std::cout << endl;
    
//    flist = {"sub_17A24"};

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
                if ( CUtils::match("^(.*)(memory|memory16)\\(_es, (.*)\\) = (.*);( *)//(.*)$", line, arrMatches) )
                {
                    // prefix, memory, offset, value, space, comment
                    stringstream ss;
                    ss << arrMatches[0];
                    ss << (arrMatches[1] == "memory" ? "memoryVideoSet" : "memoryVideoSet16");
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
                    ss << (arrMatches[1] == "memory" ? "memoryVideoGet" : "memoryVideoGet16");
                    ss << "(_es, " << arrMatches[2] << ")" << arrMatches[3];
                    while (ss.str().length() < 48)
                        ss << " ";
                    ss << "//" << arrMatches[5];
                    //line = arrMatches[0] + (arrMatches[1] == "memory") ? "memoryVideoSet" : "memoryVideoSet16";
                    //line += string("(")
                    line = ss.str();
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
//    output.close();
    return 0;
}
