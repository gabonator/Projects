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

//    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/xenon5.x");
    sp.Load("/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/InputGoose/GOOSE.x");

    CCExport e;
    e.SetSource(sp.m_arrCode);
    
    string flist[] = {
        /*
        "start",
        "sub_100A9",
        "sub_100CF",
        "sub_100FD",
        "sub_10442",
        "sub_10588",
        "sub_10591",
        "sub_105EC",
        "sub_10600",
        "sub_12762",
        "sub_1333C",
        "sub_1382A",
        //
        "sub_10103",
        "sub_101C0",
        "sub_10637",
        "sub_10644",
        "sub_10B8E",
        "sub_10DA7",
        "sub_10FDA",
        "sub_121DC",
        "sub_1220D",
        "sub_131A4",
        "sub_132FE",
        "sub_13383",
        "sub_133B3",
        "sub_133D7",
        "sub_13423",
        "sub_134A8",
        
        "sub_1019D",
        "sub_101AD",
        "sub_1033B",
        "sub_10529",
        "sub_1064D",
        "sub_1069A",
        "sub_109A4",
        "sub_10BDC",
        "sub_10D98",
        "sub_10DC0",
        "sub_10E07",
        "sub_10E3D",
        "sub_10E84",
        "sub_10F3C",
        "sub_110C6",
        "sub_110F3",
        "sub_11108",
        "sub_112A7",
        "sub_112CB",
        "sub_112EB",
        "sub_11384",
        "sub_113A8",
        "sub_11429",
        "sub_114F0",
        "sub_115FC",
        "sub_116D6",
        "sub_116DF",
        "sub_116FE",
        "sub_1171F",
        "sub_11740",
        "sub_1176C",
        "sub_11783",
        "sub_117AC",
        "sub_117D6",
        "sub_117F4",
        "sub_118A9",
        "sub_118C7",
        "sub_11993",
        "sub_119C2",
        "sub_11A9E",
        "sub_11B09",
        "sub_11B4A",
        "sub_12200",
        "sub_122B1",
        "sub_1239B",
        "sub_12464",
        "sub_1252F",
        "sub_12542",
        "sub_12577",
        "sub_1258A",
        "sub_125BF",
        "sub_125D2",
        "sub_1264A",
        "sub_1269E",
        "sub_12714",
        "sub_1279F",
        "sub_128DA",
        "sub_129DB",
        "sub_12A7F",
        "sub_12C45",
        "sub_12CEA",
        "sub_12E02",
        "sub_12F50",
        "sub_12FE8",
        "sub_1300A",
        "sub_131E7",
        "sub_13209",
        "sub_13439",
        "sub_13472",
        "sub_13498",
        "sub_135BC",
        "sub_136D4",
        "sub_13840",
        "sub_139B8",*/
//        "sub_12959",
//        "sub_1296F",
//        "sub_129AE"
//        "sub_12907",
//        "sub_129AE",
//        "sub_133E5",
        //"sub_13291"
        //"sub_10B7C"
        //"sub_12121"
//        "sub_10B58"
        //"sub_108BA"
        //"sub_1237C", "sub_123D4", "sub_123EC", "sub_12404", "sub_1241C", "sub_12434", "sub_1244C", "sub_12CEA"
        /*
        "sub_104F3",
        "sub_10541",
        "sub_10674",
        "sub_10AD5",
        "sub_1196F",
        "sub_11A04",
        "sub_11C0A",
        "sub_11C56",
        "sub_11CD9",
        "sub_11D1E",
        "sub_11DEF",
        "sub_11F0B",
        "sub_11FBA",
        "sub_12005",
        "sub_12047",
        "sub_12092",
        "sub_12099",
        "sub_120DB",
        "sub_1215B",
        "sub_122C1",
        "sub_122E1",
        "sub_122F9",
        "sub_12311",
        "sub_12329",
        "sub_1237C",
        "sub_12536",
        "sub_1257E",
        "sub_125C6",
        "sub_12662",
        "sub_12676",
        "sub_12809",
        "sub_12A64",
        "sub_12B28",
        "sub_12C07",
        "sub_12C9A",
        "sub_12D9A",
        "sub_12DDC",
        "sub_12DF6",
        "sub_13059",
        "sub_13084",
        "sub_1309D",
        "sub_13130",
        "sub_13801",
        "sub_13914",
        "sub_123D4",
        "sub_123EC",
        "sub_12404",
        "sub_1241C",
        "sub_12434",
        "sub_1244C",*/
        //"sub_1268A", "sub_1269E", "sub_122C1"
        /*
        "sub_104F3",
        "sub_10541",
        "sub_10674",
        "sub_10AD5",
        "sub_1196F",
        "sub_11A04",
        "sub_11C0A",
        "sub_11C56",
        "sub_11CD9",
        "sub_11D1E",
        "sub_11DEF",
        "sub_11F0B",
        "sub_11FBA",
        "sub_12005",
        "sub_12047",
        "sub_12092",
        "sub_12099",
        "sub_120DB",
        "sub_1215B",
        "sub_122C1",
        "sub_122E1",
        "sub_122F9",
        "sub_12311",
        "sub_12329",
        "sub_1237C",
        "sub_12536",
        "sub_1257E",
        "sub_125C6",
        "sub_12662",
        "sub_12676",
        "sub_12809",
        "sub_12A64",
        "sub_12B28",
        "sub_12C07",
        "sub_12C9A",
        "sub_12D9A",
        "sub_12DDC",
        "sub_12DF6",
        "sub_13059",
        "sub_13084",
        "sub_1309D",
        "sub_13130",
        "sub_13801",
        "sub_13914",
        "sub_123D4",
        "sub_123EC",
        "sub_12404",
        "sub_1241C",
        "sub_12434",
        "sub_1244C",
        "sub_11E7D",
*/
        //"sub_13130"
        //"sub_1315E", "sub_13167", "sub_13170", "sub_13178", "sub_13181", "sub_13188", "sub_13191", "sub_1319B"
        //"sub_13170"
        "sub_136D4"
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
            output << "    WORD _cs = " << usingCs << ";" << endl;
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
    //output.close();
    return 0;
}
