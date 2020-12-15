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

// hladaj //gg
using namespace std;

#define _STATIC_ASSERT static_assert
#define _ASSERT assert
#define CheckEnum2(s, e) if (str==s) return e;
#define CheckEnum(e) if (str==#e) return e;

/*
#include "serializer.h"
#include "instructions.h"
#include "analysis.h"
#include "matchers.h"
#include "parser.h"
*/

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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    CSourceParser sp;
    sp.Parse("/Users/gabrielvalky/Documents/git/Projects/CicParser2021/xenon2.asm");
    sp.Save("/Users/gabrielvalky/Documents/git/Projects/CicParser2021/xenon2.x");
    return 0;
}
