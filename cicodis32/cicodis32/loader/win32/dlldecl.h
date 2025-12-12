// dlldecl.h: Implements DllDecl for parsing function declarations from header files.
#pragma once

#include <map>
#include <string>
#include <regex>
#include <fstream>

class DllDecl {
    std::map<std::string, std::string> declarations;
public:
    bool LoadFile(const std::string& filename) {
        declarations.clear();
        std::ifstream in(filename);
        if (!in.is_open()) return false;
        std::string line;
        // Regex matches: returnType funcName(params);
        // Simple C-like function declaration (not macro, not struct/typedef)
        // e.g.
        // int WINAPI MessageBoxA(HWND, LPCSTR, LPCSTR, UINT);
        // BOOL LoadLibraryA(LPCSTR);
        //std::regex func_decl(R"(^\s*([\w\s\*]+)\s+([A-Za-z_]\w*)\s*\([^;{]*\);)" );
        std::regex func_decl("^(.*) \\*?([A-Za-z0-9_]+)\\((.+\\));");
        std::regex var_decl("^extern (.*) \\*?([A-Za-z0-9_]+);");
        //extern FONT *font;
        std::smatch m;
        while (std::getline(in, line)) {
            if (std::regex_search(line, m, func_decl)) {
                std::string funcName = m[2];
                // Save the whole line as declaration
                declarations[funcName] = line;
                
//                printf("%s -> %s\n", funcName.c_str(), line.c_str());
            }
            if (std::regex_search(line, m, var_decl)) {
                std::string varName = m[2];
                // Save the whole line as declaration
                declarations[varName] = line;
                
//                printf("%s -> %s\n", varName.c_str(), line.c_str());
            }
        }
        return true;
    }

    const std::map<std::string, std::string>& GetDeclarations() const {
        return declarations;
    }
};
