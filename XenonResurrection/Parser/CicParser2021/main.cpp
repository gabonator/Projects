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

int main(int argc, const char * argv[])
{
    // insert code here...
    
    CSourceParser sp;
//    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/CicParser2021/test3.asm");
//    sp.Save("/Users/gabrielvalky/Documents/git/Projects/CicParser2021/test3.x");
//    sp.Load("/Users/gabrielvalky/Documents/git/Projects/CicParser2021/test3.x");

//    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/CicParser2021/xenon3.asm");
//    sp.Save("/Users/gabrielvalky/Documents/git/Projects/CicParser2021/xenon3.x");
//    return 0;

    sp.Load("/Users/gabrielvalky/Documents/git/Projects/CicParser2021/xenon3.x");
//    sp.Load("/Users/gabrielvalky/Documents/git/Projects/CicParser2021/test3.x");

    CCExport e;
    e.SetSource(sp.m_arrCode);
    
    
    string flist[] = {/*"start", "sub_24B90", "sub_105A3", "sub_107ED", "sub_15E8A", "sub_15E5E", "sub_15C8B",
        "sub_13C75", "sub_15EC3", "sub_15E7A"*/
        //"sub_10101"
        //"sub_1F2D5",
        /*
        "sub_1011C", "sub_1019A",
        "sub_10230", "sub_102A8", "sub_102D4", "sub_1034C",
        "sub_10174", "sub_10373", "sub_103DD", "sub_103FD",
        "sub_10423", "sub_104C9"
         */
        //"sub_10DA3" // dorobit: call    cs:off_10DB1[bp]
        //"sub_16058", "sub_160EF",
        
        //"sub_160EF"
        //"sub_1426A", "sub_141A1", "sub_14191"
        //"sub_10D5F"
        //"sub_21836"
        /*
        "sub_15863", "sub_10831",
        "sub_10A0D", "sub_10A51",
        "sub_10AFB",  "sub_10D1B",
        "sub_10D81", "sub_10DE7",
        "sub_14191",
        "sub_159AA",
        "sub_10B3F",
        "sub_1595D",
         */
        //"sub_1F3A7", "sub_1F38C"
        //"sub_1F3D7"
        //"sub_205A9", "sub_2058D"
        //"sub_211CC", "sub_20CBB", "sub_20CFE"
        //"sub_1F492", "sub_10ED9", "sub_14191"
        //"sub_205AE", "sub_10EF1", "sub_160A5", "sub_160EF"
        //"sub_2098C", "sub_20A2E", "sub_20A47", "sub_20A5C", "sub_20AC0"
        
        //"sub_1F3C7", "sub_1F371"
        //"sub_209E9", "sub_1F492", "sub_2058D", "sub_20973", "sub_20A1D", "sub_10ED9", "sub_2098C", "sub_2098C",
        //"sub_14191", "sub_20A2E", "sub_20A3C", "sub_20A47", "sub_20A5C"
        "sub_20973"
    };
    
    std::set<string> imports;
    
    for (int i=0; i<sizeof(flist)/sizeof(flist[0]); i++)
    {
        CLabel testLabel(flist[i]);
        std::cout << "void " << testLabel << "();" << endl;
    }
    std::cout << endl;

    for (int i=0; i<sizeof(flist)/sizeof(flist[0]); i++)
    {
        CLabel testLabel(flist[i]);
    
        vector<shared_ptr<CInstruction>> arrFunction = e.GetSubCode(sp.m_arrCode, testLabel);
        vector<shared_ptr<CCInstruction>> arrCFunction;
        
        for (int i=0; i<arrFunction.size(); i++)
        {
            shared_ptr<CICall> pCall = dynamic_pointer_cast<CICall>(arrFunction[i]);
            if (pCall)
                imports.insert(pCall->m_label);
        }
            
        // Two pass for alu conditional injections
        e.Convert(testLabel, arrFunction, arrCFunction);
        arrCFunction.clear();
        e.Convert(testLabel, arrFunction, arrCFunction);
        std::cout << "void " << testLabel << "()" << endl
            << "{" << endl;
        e.DumpProgram(cout, arrCFunction, 1);
        std::cout << "}" << endl << endl;
    }
    
    for (int i=0; i<sizeof(flist)/sizeof(flist[0]); i++)
    {
        imports.erase(flist[i]);
    }
    
    std::cout << endl << "// imports" << endl;
    for (const string& s : imports)
    {
        std::cout << "void " << s << "();" << endl;
    }
    std::cout << endl;

    //e.Convert(CLabel("sub_872"), arrFunction, arrCFunction);
            
    //e.OptimizeRedirects(arrCFunction);
    //e.OptimizeExits(arrCFunction);
    //e.OptimizeDeadLoops(arrCFunction);
    //e.OptimizeUnreferenced(arrCFunction);

    return 0;
}
