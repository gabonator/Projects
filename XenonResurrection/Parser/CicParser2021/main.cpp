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

    //sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon5.x");
//    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGoose/GOOSE.x");
//    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputJbird/jbird.asm");
//    sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputJbird/jbird.x");
//    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputJbird/jbird.x");
        
//        sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/ETETRIS.asm");
//        sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/tetris.x");
//        sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputTetris/tetris.x");

    
//        sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/fox.asm");
//        sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/fox.x");
//        sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputFox/fox.x");

//            sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputPopcorn/popcorn.asm");
//            sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputPopcorn/popcorn.x");
            sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputPopcorn/popcorn.x");

    CCExport e;
    e.SetSource(sp.m_arrCode);
    
    string flist[] = {
        /*
        "start",

        "sub_2ACA5",
        "sub_2ACB0",
        "sub_2AD26",
        "sub_2AFD0",
        "sub_2AFF1",
        "sub_2B06B",
        "sub_2B093",
        "sub_2B141",
        "sub_2B355",
        "sub_2B3AB",
        "sub_2B4E8",
        "sub_2B72B",
        "sub_2B8E5",
        "sub_2B94E",
        "sub_2BCFE",
        "sub_2BE32",
        "sub_2C0D3",
        "sub_2C129",
        "sub_2C1A1",
        "sub_2C493",
        "sub_2CAD9",
        "sub_2ECE0",
        "sub_2F52D",
        "sub_2F5DC",
        "sub_2F69A",
        "sub_2F700",
        "sub_2F76F",
        "sub_2F9B6",
        "sub_2FA3A",
        "sub_2FCB9",
        "sub_2FCDC",
        "sub_2FCFF",
        "sub_2FD91",
        "sub_2FDB6",
        "sub_2FFE2",
        "sub_30096",
        "sub_300F6",
        "sub_30205",
        "sub_302A0",
        "sub_30560",
        
        
        "sub_2ACB7",
        "sub_2B17E",
        "sub_2B218",
        "sub_2B531",
        "sub_2B5E5",
        "sub_2B884",
        "sub_2BCAC",
        "sub_2BCE5",
        "sub_2BCF1",
        "sub_2BF74",
        "sub_2BFD8",
        "sub_2C234",
        "sub_2C262",
        "sub_2C26C",
        "sub_2C86F",
        "sub_2CBE1",
        "sub_2CC54",
        "sub_2CCD9",
        "sub_2CD29",
        "sub_2CD68",
        "sub_2CDA7",
        "sub_2CE3A",
        "sub_2CEA1",
        "sub_2CEC9",
        "sub_2CEFE",
        "sub_2D09F",
        "sub_2D3F7",
        "sub_2D447",
        "sub_2D4A1",
        "sub_2DA3E",
        "sub_2DB03",
        "sub_2DD66",
        "sub_2DE52",
        "sub_2DE77",
        "sub_2E288",
        "sub_2E31B",
        "sub_2E9B5",
        "sub_2EDF4",
        "sub_2F54F",
        "sub_2F577",
        "sub_2F79A",
        "sub_2F957",
        "sub_2F9DB",
        "sub_2FA0A",
        "sub_2FB78",
        "sub_2FB93",
        "sub_2FD60",
        "sub_2FDD6",
        "sub_300AA",
        "sub_30663",
        "sub_30676",
        "sub_307A0",
        "sub_307D5",
        
        "sub_2B1B8",
        "sub_2B63D",
        "sub_2C0C7",
        "sub_2CA43",
        "sub_2CA70",
        "sub_2CF36",
        "sub_2D16D",
        "sub_2D375",
        "sub_2DC8B",
        "sub_2DCFD",
        "sub_2EDD1",
        "sub_2EE05",
        "sub_2F8E1",
        "sub_2F97D",
        "sub_2FA24",
        "sub_2FBC7",
        "sub_2FBF3",
        "sub_2FC11",
        "sub_2FC39",
        "sub_2FC65",
        "sub_2FF37",
        "sub_2FFAD",
        "sub_30068",
        "sub_30617",
        "sub_306FD",
        "sub_30856",
        
        "sub_2D3D7"
*/
        "sub_2E7CC"

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
