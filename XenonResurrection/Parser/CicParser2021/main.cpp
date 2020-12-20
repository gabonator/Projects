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
        //
        D("sub_160EF", "Joystick")
        D("sub_1F492", "Starfields")
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

//    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon3.asm");
//    sp.Save("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon3.x");
//    return 0;

    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon3.x");

    CCExport e;
    e.SetSource(sp.m_arrCode);
    
    string flist[] = {
        /*
         //code-loader.h
        "sub_15C8B", "sub_10DA3", "sub_1011C", "sub_1019A", "sub_10230",
        "sub_102A8", "sub_104C9", "sub_102D4", "sub_10174", "sub_10373",
        "sub_1034C", "sub_103DD", "sub_103FD", "sub_10423",
         */
        /*
        // code-intro.h
        "sub_16058", "sub_160EF", "sub_1426A", "sub_141A1", "sub_14191", "sub_10D5F",
        "sub_21836", "sub_15863", "sub_10831", "sub_10A0D", "sub_10A51", "sub_10AFB",
        "sub_10D1B", "sub_10D81", "sub_10DE7", "sub_159AA", "sub_10B3F", "sub_1595D",
        "sub_1F3A7", "sub_1F38C", "sub_1F3D7", "sub_205A9", "sub_2058D", "sub_211CC",
        "sub_20CBB", "sub_20CFE", "sub_1F492", "sub_10ED9", "sub_205AE", "sub_10EF1",
        "sub_160A5", "sub_2098C", "sub_20A2E", "sub_20A47", "sub_20A5C", "sub_20AC0",
        "sub_1F3C7", "sub_1F371", "sub_209E9", "sub_20A1D", "sub_20A3C", "sub_20973",
         */
        /*
        // code-pregame.h
        "sub_15B21", "sub_109EB", "sub_15935", "sub_15C7C", "sub_10B83", "sub_10BC7",
        "sub_15950", "sub_10BE9", "sub_20B5B", "sub_20A39", "sub_10E2B", "sub_1F3B5",
        "sub_20B8A", "sub_15CC5", "sub_1F325", "sub_1F363", "sub_11827", "sub_20568",
        "sub_11B43", "sub_11A19", "sub_11AAF", "sub_10F5A", "sub_10F78", "sub_15926",
        "sub_10985", "sub_20482", "sub_1080F", "sub_1F3EF", "sub_10ED5", "sub_1421C",
        "sub_10A2F", "sub_10E4D", "sub_20854", "sub_20919", "sub_2095F", "sub_10BA5",
        "sub_136FC", "sub_1370B", "sub_20AD0",
         */
        "sub_15B10", "sub_15935"

/*
 goto nearptr -> call
 goto near ptr sub_205AE;                      //jmp near ptr sub_205AE

 sub_2058D - es video
 nemame lsi lea, adresa namiesto ptr
 */
    };
    
    CCustomize custom;
    std::set<string> imports;
    //ofstream output;
    auto& output = cout;
    
    //output.open("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Simulator/CicParserSim/code-pregame.h");
    
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
            shared_ptr<CIAssignment> pAssign = dynamic_pointer_cast<CIAssignment>(arrFunction[j]);
            if (pAssign)
            {
                if (pAssign->m_valueFrom.ToC().find("_cs") != string::npos ||
                    pAssign->m_valueTo.ToC().find("_cs") != string::npos)
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
                    cout << testLabel << "  -  " << usingCs << endl;
                    _ASSERT(!usingCs.empty());
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
            output << "    _cs = " << usingCs << ";" << endl;
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
        output << "void " << s << "();" << endl;
    }
    output << endl;
    //output.close();
    return 0;
}
