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
    bool GlobalExitLabel(string fname)
    {
        // not implemented
        return fname == "loc_15E04";
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

    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon5.x");
//    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGoose/GOOSE.x");
//    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputJbird/jbird.asm");
//    sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputJbird/jbird.x");
//    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputJbird/jbird.x");
        
//        sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/ETETRIS.asm");
//        sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/tetris.x");
//        sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/tetris.x");

    CCExport e;
    e.SetSource(sp.m_arrCode);
    
    string flist[] = {
        /*
        "start",
        //"sub_24B90",
        "sub_105A3",
        "sub_107ED",
        "sub_15E8A",
        "sub_15E5E",
        "sub_13C75",
        "sub_15EC3",
        "sub_15E7A",
        "sub_10000",
        "sub_10101",
        "sub_10067",
        "sub_10089",
        "sub_10097",
        "sub_106FE",
        "sub_1F2D5",
        "sub_14311",
        "sub_14759"
         */
        /*
        //game
        "sub_1FE70",
        "sub_1F787",
        "sub_1F6F8",
        "sub_1F585",
        "sub_10875",
        "sub_10DC5",
        "sub_109A7",
        "sub_10A73", //() // draw status bar health indicat",
        "sub_205ED",
        "sub_20627",
        "sub_2217E",
        "sub_24178",
        "sub_24185",
        "sub_24130",
        "sub_116A9", //() // draw sco",
        "sub_10E6F",
        "sub_208DC",
        "sub_116BA", //() // draw health - overflo",
        "sub_10762",
        "sub_1077C",
        "sub_1078E",
        "sub_11022",
        "sub_12BCC",
        "sub_135EB",
        "sub_107DC",
        "sub_107C0",
        "sub_10E91",
        "sub_208F9",
        "sub_1373D",
        "sub_11689",
        "sub_10FF0",
        "sub_13682",
        "sub_10EF5",
        "sub_13326",
        "sub_13A39",
        "sub_13AB2",
        "sub_14675",
        "sub_1465C",
        "sub_1472D",
        "sub_13589",
        "sub_11BEA",
        "sub_1714A",
        "sub_10F96",
        "sub_11C18",
        "sub_10F2F",
        "sub_144F3",
        "sub_11E29",
        "sub_11D1E",
        "sub_11E02",
        "sub_141E2",
        "sub_141B1",
        "sub_10A95",
        "sub_20653",
        "sub_10EDD",
        "sub_10EE1",
        "sub_11CCC",
        "sub_13A36",
        "sub_13615",
        //"sub_13360",
        //"sub_17132",
        //"sub_17138",
        "sub_170F1",
        "sub_10FB4",
        "sub_16EEF",
        "sub_10FD2",
        "sub_1758F",
        "sub_13389",
        //"sub_16F7F",
        //"sub_16F00",
        //"sub_16FE0",
        //"sub_1705B",
        "sub_1655B",
        "sub_172C4",
        "sub_1EBD0",
        "sub_10941",
        "sub_17520",
        //"sub_135CE",
        "sub_1EC6F",
        "sub_14871",
        "sub_11BB4",
        "sub_11BA2",
        "sub_11B90",
        "sub_11ED3",
        "sub_14865",
        "sub_1480B",
         */
        /*
        // pregame
        "sub_15B21",
        "sub_109EB",
        "sub_15935",
        "sub_15C7C",
        "sub_10B83",
        "sub_10BC7",
        "sub_15950",
        "sub_10BE9",
        "sub_20B5B",
        "sub_20A39",
        "sub_10E2B",
        "sub_1F3B5",
        "sub_20B8A",
        "sub_15CC5",
        "sub_1F325",
        "sub_1F363",
        "sub_11827",
        "sub_20568",
        "sub_11B43",
        "sub_11A19",
        "sub_11AAF",
        "sub_10F5A",
        "sub_10F78",
        "sub_15926",
        "sub_10985",
        "sub_20482",
        "sub_1080F",
        "sub_1F3EF",
        "sub_10ED5",
        "sub_1421C",
        "sub_10A2F",
        "sub_10E4D",
        "sub_20854",
        "sub_20919",
        "sub_2095F",
        "sub_10BA5",
        "sub_136FC",
        //"sub_1F585",
        "sub_1F57C",
        //"sub_1F6F8",
        //"sub_1FE70",
        "sub_10853",
        "sub_1370B",
        "sub_20AD0",
        "sub_15B10",
        "sub_15E24",
        "sub_15E35",
        "sub_15E52",
        "sub_15E59",
*/
        //"sub_1F57C",
        
        
        
        //"loc_16F7F"
//        "sub_1714A"
        //"loc_1F93B"
//        "sub_1F970"
        //"loc_1F93B"
        "loc_1FE85"

    };
    
    CCustomize custom;
    std::set<string> imports;
    auto& output = cout;
    
//    ofstream output;
//    output.open("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/SimulatorGoose/CicParserSim/code-goose.h");
    
    for (int i=0; i<sizeof(flist)/sizeof(flist[0]); i++)
    {
        CLabel testLabel(flist[i]);
        output << "void " << testLabel << "();" << endl;
    }
    std::cout << endl;

    for (int i=0; i<sizeof(flist)/sizeof(flist[0]); i++)
    {
        CLabel testLabel(flist[i]);
    
        vector<shared_ptr<CInstruction>> arrFunction = e.GetSubCode(sp.m_arrCode, testLabel);
        vector<shared_ptr<CCInstruction>> arrCFunction;
        string usingCs;
        
        for (int j=0; j<arrFunction.size(); j++)
        {/*
            shared_ptr<CICall> pCall = dynamic_pointer_cast<CICall>(arrFunction[i]);
            if (pCall)
                imports.insert(pCall->m_label);
            shared_ptr<CISwitch> pSwitch = dynamic_pointer_cast<CICall>(arrFunction[i]);
            if (pSwitch)
            {
                for (int j=0; j<pSwitch->m_)
                imports.insert(pCall->m_label);
            }*/
            shared_ptr<CIJump> pJump = dynamic_pointer_cast<CIJump>(arrFunction[j]);
            if (pJump && custom.GlobalExitLabel(pJump->m_label))
                arrFunction[j] = make_shared<CIStop>(pJump, "exit program");
            
            bool traceSegment = (arrFunction[j]->m_origin.find("cs") != string::npos) &&
            (arrFunction[j]->m_origin.find("push") == string::npos) &&
            (arrFunction[j]->m_origin.find("call") == string::npos);
                
            /*
            shared_ptr<CIAssignment> pAssign = dynamic_pointer_cast<CIAssignment>(arrFunction[j]);
            if (pAssign)
            {
                if (pAssign->m_valueFrom.ToC().find("_cs") != string::npos ||
                    pAssign->m_valueTo.ToC().find("_cs") != string::npos)
                {
                    traceSegment = true;
                }
            }
            shared_ptr<CIAssignment> pAssign = dynamic_pointer_cast<CISingleArgOp>(arrFunction[j]);
            if (pAssign)*/

            if (traceSegment)
            {
                int nBegin = e.FindLabel(sp.m_arrCode, testLabel);

                for (int k=nBegin; k>=0; k--)
                {
                    shared_ptr<CISegment> pSegment = dynamic_pointer_cast<CISegment>(sp.m_arrCode[k]);
                    if (pSegment)
                    {
                        usingCs = pSegment->m_strSegmentName;
                        break;
                    }
                }
                //cout << testLabel << "  -  " << usingCs << endl;
                _ASSERT(!usingCs.empty());
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
                CUtils::replace(label, "()", "");
                imports.insert(label);
            }
            shared_ptr<CCSwitch> pSwitch = dynamic_pointer_cast<CCSwitch>(arrCFunction[i]);
            if (pSwitch)
            {
                for (int j=0; j<pSwitch->m_arrLabels.size(); j++)
                    imports.insert(pSwitch->m_arrLabels[j]);
            }
        }

        output << "void " << testLabel << "()";
        string comment = custom.GetFunctionDesc(testLabel);
        if (!comment.empty())
            output << "  // " << comment;
        output << endl << "{" << endl;
        if (!usingCs.empty())
            output << "    WORD _cs = _" << usingCs << ";" << endl;
        e.DumpProgram(output, arrCFunction, 1);
        if (arrCFunction.size() > 0 && dynamic_pointer_cast<CCLabel>(arrCFunction[arrCFunction.size()-1]))
            output << "    return;" << endl;
        output << "}" << endl << endl;
    }
    
    for (int i=0; i<sizeof(flist)/sizeof(flist[0]); i++)
    {
        imports.erase(flist[i]);
    }
    
    output << endl << "// imports" << endl;
    for (const string& s : imports)
    {
        output << "void " << s << "() { _ASSERT(0); }" << endl;
    }
    output << endl;
//    output.close();
    return 0;
}
