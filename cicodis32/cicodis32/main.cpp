/*
 header search path: /opt/homebrew/include/
 library search path: /opt/homebrew/lib
 build phases -> link binary with libraries: /opt/homebrew/lib/libcapstone.dylib
 
 */
// TODO: bool CheckCodeAddress(int seg, int ofs), inf loop
#include <capstone/platform.h>
#include <capstone/capstone.h>
#include <stdint.h>
#include <assert.h>
#include <regex>
#include <list>
#include <map>
#include <set>

#include "address.h"
#include "common.h"
#include "loader.h"
#include "tracer.h"
#include "analyser.h"
#include "analyserFunction.h"
#include "analyserInstruction.h"
#include "formatter.h"
#include "converter.h"

std::vector<int> sequence(const char* seq)
{
    std::vector<int> aux;
    std::vector<std::string> parts = utils::split(seq, "-");
    assert(parts.size() == 2);
    int b = std::stoi(parts[0]);
    int e = std::stoi(parts[1]);
    for (int i=b; i<=e; i++)
        aux.push_back(i);
    return aux;
}

int main(int argc, char **argv) {
    Options optionsRick2 = {
        .loader = "LoaderMz",
        .exec = "RICK2.EXE",
//        .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1040, 0x5e22}},
        .jumpTables = {
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1040, 0xffff),
                .table = address_t(0x1040, 0x0000),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37},
                .selector = "indirect",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1040, 0xffff),
                .table = address_t(0x1040, 0x9bb8),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
                .selector = "indirect",
            }),
        },
        .isolateLabels = {address_t(0x1040, 0x168a8-0x10400),
            address_t(0x1040, 0x196f3-0x10400),
            address_t(0x1040, 0x1c359-0x10400),
            address_t(0x1040, 0x19f12-0x10400),
            address_t(0x1040, 0x19731-0x10400)
        }
    };
    
    Options optionsGoose = {
        .loader = "LoaderMz",
        .exec = "GOOSE.EXE",
//        .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1000, 0x101ad- 0x10000}},
//                .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1000, 0x541}},

        .jumpTables = {
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1000, 0x104e),
                .table = address_t(0x1000, 0x105a),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34},
                .selector = "bx",
            })}
    };
    Options optionsRick1 = {
        .loader = "LoaderMz",
        .exec = "rick1.exe",
//        .verbose = true,  .relocations = false, .recursive = false, .start = false, .procList = {{0x341b, 0x36413- 0x341b0}},
//        .verbose = true,  .relocations = false, .recursive = false, .start = false, .procList = {{0x341b, 0x354c7- 0x341b0}},
        //sub_34442
        .jumpTables = {
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x341b, 0x228a),
                .table = address_t(0x1040, 0x80bf),
                .type = jumpTable_t::JumpWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                23},
                .selector = "di",
            })}
    };
    Options optionsFox = {
        .loader = "LoaderMz",
        .exec = "fox.exe",
        .procModifiers = {std::pair<address_t, procRequest_t>({0x1020, 0x5133}, procRequest_t::stackDrop2)},
        .jumpTables = {
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x42e6),
                .table = address_t(0x168f, 0x6efb),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                23, 24, 25, 26, 27, 28, 29},
                .minaddr = 1,
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x45a0),
                .table = address_t(0x168f, 0x727d),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                .minaddr = 1,
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x45cf),
                .table = address_t(0x168f, 0x7299),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58},
                .minaddr = 1,
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x4629),
                .table = address_t(0x168f, 0x726f),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                .minaddr = 1,
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x5961),
                .table = address_t(0x168f, 0x8eb5),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37},
                .minaddr = 1,
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x464b),
                .table = address_t(0x168f, 0x726F),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                .minaddr = 1,
                .selector = "bx",
            }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{
                .instruction = address_t(0x1020, 0x57e4),
                .table = address_t(0x168f, 0x8EDB),
                .type = jumpTable_t::CallWords,
                .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18},
                .minaddr = 1,
                .selector = "bx",
            }),
        }
    };
    Options optionsBumpy = {
        .loader = "LoaderMz",
        .exec = "BUMPY.EXE",
        .arch = arch_t::arch16,
        .loadAddress = 0x01ed0,
//        .verbose = true,
//        .relocations = false, .verbose = true, .recursive = false, .procList = {{0x0ca6, 0x1087}},
        .procModifiers = {
            {{0x1ed, 0xa8ee}, procRequest_t::stackDrop8},
            {{0x1ed, 0xa9f5}, procRequest_t::stackDrop8},
            {{0x1ed, 0xa178}, procRequest_t::stackDrop2}, //1ed:a178
            {{0x1ed, 0x98dd}, procRequest_t::stackDrop4}, //1ed:98dd
            {{0x1ed, 0x9b14}, procRequest_t::stackDrop4}, //1ed:9b14
            {{0x1ed, 0xa1ef}, procRequest_t::stackDrop6}, //1ed:a1ef
            {{0x1ed, 0xa20a}, procRequest_t::stackDrop2}, //1ed:a20a
            {{0xca6, 0x13bc}, procRequest_t::stackDrop2},
            //sub_dddb
//            {{0x01ed, 0xaa2b}, (procRequest_t)((int)procRequest_t::returnZero | (int)procRequest_t::returnCarry | (int)procRequest_t::callNear)}
        },
            //.procList = {{0x1ed, 0x9c62}, {0x1ed, 0xaa4e}},
            .jumpTables = {
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x1ed, 0x1da),
                    .table = address_t(0x1227, 0),
                    .type = jumpTable_t::CallWords,
                    .elements = {1, 4},
                    .selector = "memoryAGet16(es, bx + 2)",
                    .useCaseOffset = true
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x1ed, 0x46dc),
                    .table = address_t(0x1ed, 0x4725),
                    .type = jumpTable_t::JumpWords,
                    .elements = {0, 1, 2, 3},
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x1ed, 0x37db),
                    .table = address_t(0x1ed, 0x384a),
                    .type = jumpTable_t::JumpWords,
                    .elements = {0, 1, 2, 3},
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x1ed, 0x6e7e),
                    .table = address_t(0x1ed, 0x70e7),
                    .type = jumpTable_t::JumpWords,
                    .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19},
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x0264),
                    .table = address_t(0x1228, 0x5469),
                    .type = jumpTable_t::JumpWords,
                    .elements = {0, 1, 2, 3, 4, 5},
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x020a),
                    .table = address_t(0x1228, 0x545d),
                    .type = jumpTable_t::JumpWords,
                    .elements = {0, 1, 2, 3, 4, 5},
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x0374),
                    .table = address_t(0x1228, 0x5475),
                    .type = jumpTable_t::JumpWords,
                    .elements = {0, 1, 2},
                    .selector = "bp",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0xca6, 0x1321),
                    .table = address_t(0x1228, 0x6946),
                    .type = jumpTable_t::CallWords,
                    .elements = {0, 1, 2, 3, 4, 5},
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0xed9, 0x2dbe),
                    .table = address_t(0xed9, 0x2dc6),
                    .type = jumpTable_t::CallWords,
                    .elements = {0, 1, 2, 3, 4, 5},
                    .selector = "di",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x1ed, 0x7284),
                    .type = jumpTable_t::CallWords,
                    .baseptr = (const uint8_t*)"\xae\xa3",
                    .elements = {0},
                    .selector = "memoryAGet16(ss, bp + 4)",
                    .useCaseOffset = true
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ed9, 0x2d01),
                    .table = address_t(0xed9, 0x2d09),
                    .type = jumpTable_t::CallWords,
                    .elements = {0, 1, 2, 3, 4, 5},
                    .selector = "ax",
                    .useCaseOffset = true
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0e15, 0x005e),
                    .table = address_t(0x1228, 0x4e37),
                    .type = jumpTable_t::CallWords,
                    .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
                    .selector = "bp",
                    .useCaseOffset = true
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x01ed, 0x23b0),
                    .table = address_t(0x1228, 0x43c0),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-1084"),
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x01ed, 0x1e32),
                    .table = address_t(0x1228, 0x07ca),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-63"),
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x01a4),
                    .table = address_t(0x1228, 0x4dda),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-6"),
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x0028),
                    .baseptr = (const uint8_t*)"\x2b\x00",
                    .type = jumpTable_t::CallWords,
                    .elements = {0},
                    .selector = "ax",
                    .useCaseOffset = true
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x1223, 0x000b),
                    .table = address_t(0x1228, 0x6976),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-5"),
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x01f3),
                    .table = address_t(0x1228, 0x5435),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-13"),
                    .selector = "bp",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x02c3),
                    .table = address_t(0x1228, 0x5441),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-5"),
                    .selector = "bp",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x0d9e),
                    .table = address_t(0x1228, 0x555e),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-5"),
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x0acd),
                    .table = address_t(0x1228, 0x5550),
                    //.baseptr = (const uint8_t*)"\xd0\x0a",
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-7"),
                    .selector = "ax",
                    .useCaseOffset = true
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x0a92),
                    .table = address_t(0x1228, 0x5544),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-18"),
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x01ed, 0x4db9),
                    .table = address_t(0x1228, 0x0870),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-11"),
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x01ed, 0x501f),
                    .table = address_t(0x1228, 0x085c),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-20"),
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x129d),
                    .table = address_t(0x1228, 0x56c2),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-5"),
                    .selector = "si",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x0820),
                    .table = address_t(0x1228, 0x5536),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-25"),
                    .selector = "ax",
                    .useCaseOffset = true
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x1084),
                    .table = address_t(0x1228, 0x56b4),
                    .type = jumpTable_t::CallWords,
                    .elements = {0, 1, 2, 3, 4, 5, 6, 7},
                    .selector = "ax /*1*/",
                    .useCaseOffset = true
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ed9, 0x2d94),
                    .table = address_t(0x0ed9, 0x2d9c),
                    .type = jumpTable_t::CallWords,
                    .elements = {0, 1, 2, 3, 4, 5},
                    .selector = "di",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x13e2),
                    .table = address_t(0x1228, 0x6952),
                    .type = jumpTable_t::CallWords,
                    .elements = {0, 1, 2, 3, 4, 5},
                    .selector = "bx",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ed9, 0x2d2f),
                    .table = address_t(0x0ed9, 0x2d37),
                    .type = jumpTable_t::CallWords,
                    .elements = {0, 1, 2, 3, 4, 5},
                    .selector = "di",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ed9, 0x11d3),
                    .table = address_t(0x0ed9, 0x210b),
                    .type = jumpTable_t::JumpFix,
                    .elements = {0},
                    .selector = "ax",
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ed9, 0x25e4),
                    .baseptr = (const uint8_t*)"\x04\x20\x63\x20\x46\x1f\xfa\x20",
                    .type = jumpTable_t::JumpWords,
                    .elements = {0, 1, 2, 3},
                    .selector = "ax",
                    .useCaseOffset = true
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x104e),
                    .table = address_t(0x1228, 0x5698),
                    .type = jumpTable_t::CallWords,
                    .elements = sequence("0-5"),
                    .selector = "bx"
                }),
                std::shared_ptr<jumpTable_t>(new jumpTable_t{
                    .instruction = address_t(0x0ca6, 0x0ddd),
                    .table = address_t(0x1228, 0x568a), // 0x0de0),
                    .type = jumpTable_t::CallWords,
                    .elements = {0},
                    .selector = "bx"
                }),

                
                // 0ca6:0ddd;  0ca6:0de0 bx
                
            },
        
        
        //1ed:aa2b
        
        //1ed:a8ee
//        .verbose = true,  .relocations = false, .recursive = false, .start = false, .procList = {{0x1000, 0xa9f5}},
//        .verbose = true,  .relocations = false, .recursive = false, .start = false, .procList = {{0x1000, 0xC7BE - 0x1ed0}},
        
    };
/*
 es:bx+2 = 1227:0002 = 9c62;  cs:x = sub_bb32
 es:bx+2 = 1227:0008 = aa4e;  cs:x = sub_c91e
 */
//    Options options = optionsGoose;
//    Options options = optionsRick2;
//    Options options = optionsFox;
//    Options options = optionsRick1;
    Options options = optionsBumpy;

    shared<Loader> loader;
    if (strcmp(options.loader, "LoaderMz") == 0)
        loader.reset(new LoaderMz);
    else if (strcmp(options.loader, "LoaderSnapshot") == 0)
        loader.reset(new LoaderSnapshot);
    else
        assert(0);
    
    if (!loader->LoadFile(options.exec, options.loadAddress))
    {
        printf("Cannot open file %s\n", options.exec);
        return 1;
    }
    // BP 160:15e390
    // memdumpbin 169:15e000 40000
    //    if (!loader->LoadFile("MEMDUMP.BIN", 0x15e000))
    //        return 1;
    Capstone->Set(loader, options);

    
    bool anyIndirectTable = false;
    for (auto t : options.jumpTables)
    {
        if (!t->baseptr)
            t->baseptr = loader->GetBufferAt(t->table);
        if (strcmp(t->selector, "indirect") == 0)
            anyIndirectTable = true;
    }

    std::vector<address_t> startEntries;
    
    if (options.start)
        startEntries.push_back(loader->GetEntry());
    for (address_t p : options.procList)
        startEntries.push_back(p);
    for (address_t p : options.isolateLabels)
        startEntries.push_back(p);
    for (shared<jumpTable_t> j : options.jumpTables)
        if (j->type == jumpTable_t::Call || j->type == jumpTable_t::CallWords)
        for (int i=0; i<j->GetSize(); i++)
            if (j->IsValid(i))
                startEntries.push_back(j->GetTarget(i));
    
    for (address_t p : startEntries)
    {
        if (options.procModifiers.find(p) == options.procModifiers.end())
            options.procModifiers.insert({p, procRequest_t::callNear});
    }

    printf("#include \"cico32.h\"\n\n");
    
    if (options.relocations)
        printf("%s\n", loader->GetMain().c_str());

    Analyser analyser(options);
    if (options.recursive)
    {
        analyser.RecursiveScan(startEntries);
    } else {
        for (address_t p : options.procList)
            analyser.Scan(p);
    }

    if (options.declarations)
    {
        for (address_t proc : analyser.AllMethods())
            printf("void sub_%x();\n", proc.linearOffset());
        printf("\n");
    }

    if (anyIndirectTable)
    {
        printf("void callIndirect(int seg, int ofs)\n{\n");
        for (auto table : options.jumpTables)
            if (strcmp(table->selector, "indirect") == 0)
            {
                std::set<int> used;
                printf("    if (seg == 0x%04x)\n    {\n", table->instruction.segment);
                printf("        switch (ofs)\n");
                printf("        {\n");
                for (int i : table->elements)
                {
                    if (!table->IsValid(i))
                        continue;
                    int v = table->GetTarget(i).offset;
                    if (used.find(v) != used.end())
                        continue;
                    used.insert(v);
                    printf("            case 0x%x: sub_%x(); return;\n", table->GetTarget(i).offset, table->GetTarget(i).linearOffset());
                }
                
                printf("        }\n");
                printf("    }\n");
                
            }
        printf("}\n\n");
    }
    
    std::set<address_t> processNew;
    processNew = analyser.AllMethods();
    // TODO: call conv!
    
    while (!processNew.empty())
    {
        std::set<address_t> process = processNew;
        processNew.clear();
        
        for (address_t proc : process)
        {
            procRequest_t modifier = procRequest_t::none;
            if (options.procModifiers.find(proc) != options.procModifiers.end())
                modifier = options.procModifiers.find(proc)->second;
            
            analyser.AnalyseProc(proc, modifier);
            if (options.recursive)
            {
                for (std::pair<address_t, procRequest_t> req : analyser.GetRequests(proc))
                {
                    procRequest_t oldModifier = procRequest_t::none;
                    if (options.procModifiers.find(req.first) != options.procModifiers.end())
                        oldModifier = options.procModifiers.find(req.first)->second;
                    
                    if (oldModifier != req.second)
                    {
                        req.second = (procRequest_t)((int)req.second | (int)oldModifier);
                        if (options.procModifiers.find(req.first) != options.procModifiers.end())
                            options.procModifiers.find(req.first)->second = req.second;
                        else
                            options.procModifiers.insert(req);
                        processNew.insert(req.first);
                    }
                }
            }
        }
    }

    for (address_t proc : analyser.AllMethods())
    {
        Convert convert(analyser, options);
        convert.SetOffsetMask(0xffff); // 16 bit
        convert.ConvertProc(proc);
        convert.Dump();
    }
    
    if (options.relocations)
        printf("%s\n", loader->GetFooter().c_str());


    std::vector<int> procMap;
    for (address_t proc : analyser.AllMethods())
    {
        for (const auto& [begin, end] : analyser.GetProcRanges(proc))
        {
            procMap.push_back(proc.linearOffset());
            procMap.push_back(begin.segment);
            procMap.push_back(begin.offset);
            procMap.push_back(end.segment);
            procMap.push_back(end.offset);
        }
    }

    printf("int GetProcAt(int seg, int ofs)\n");
    printf("{\n");
    printf("    int map[] = {\n");
    for (int i=0; i<procMap.size(); i++)
    {
        if (i%10 == 0)
            printf("        ");
        printf("0x%x, ", procMap[i]);
        if (i%10 == 9)
            printf("\n");
    }
    printf("    };\n");
    printf("    for (int i=0; i<sizeof(map)/sizeof(map[0]); i+=5)\n");
    printf("        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs <= map[i+3]*16 + map[i+4])\n");
    printf("            return map[i];\n");
    printf("}\n");

//    std::map<address_t, int> hits;
//    for (address_t proc : analyser.AllMethods())
//    {
//        for (address_t label : analyser.GetGapLabels(proc))
//        {
//            if (hits.find(label) != hits.end())
//                hits.find(label)->second++;
//            else
//                hits.insert(std::pair<address_t, int>(label, 1));
//        }
//    }

//    for (std::pair<address_t, int> p : hits)
//    {
//        if (p.second > 1)
//            printf("// %d refs to loc_%x\n", p.second, p.first.linearOffset());
//    }


    return 0;
}







/*
 // -jumptable 01ed:46dc 01ed:4725 4 jumpwords bx
 address_t indirectJumpAddr = address_t::fromString(argv[++i]);
 address_t jumpTableBegin = address_t::fromString(argv[++i]);
 const char* strJumpEntries = argv[++i];

 std::vector<int> jumpEntries;
 if (strstr(strJumpEntries, "-"))
 {
     int jumpTableEntriesBegin = (int)strtol(strJumpEntries, nullptr, 10);
     strJumpEntries = strstr(strJumpEntries, "-")+1;
     int jumpTableEntriesEnd = (int)strtol(strJumpEntries, nullptr, 10);
     for (int i=jumpTableEntriesBegin; i<=jumpTableEntriesEnd; i++)
         jumpEntries.push_back(i);
 } else
 {
     int jumpTableEntries = (int)strtol(strJumpEntries, nullptr, 10);
     for (int i=0; i<jumpTableEntries; i++)
         jumpEntries.push_back(i);
 }
 
 const char* jumpTableEntryType = argv[++i];
 
 switch_t::switch_e tableType = switch_t::switch_e::None;
 if (strcmp(jumpTableEntryType, "jumpwords") == 0)
     tableType = switch_t::switch_e::JumpWords;
 if (strcmp(jumpTableEntryType, "callwords") == 0)
     tableType = switch_t::switch_e::CallWords;
 if (strcmp(jumpTableEntryType, "calldwords") == 0)
     tableType = switch_t::switch_e::CallDwords;
 if (strcmp(jumpTableEntryType, "jumpfix") == 0)
     tableType = switch_t::switch_e::JumpFix;
 if (strcmp(jumpTableEntryType, "call") == 0)
     tableType = switch_t::switch_e::Call;
 if (strcmp(jumpTableEntryType, "callwordsbyofs") == 0)
     tableType = switch_t::switch_e::CallWordsByOfs;
 assert(tableType != switch_t::switch_e::None);
 
 const char* jumpSelector = argv[++i];
 
 x86_reg index = X86_REG_INVALID;
 if (strcmp(jumpSelector, "bx") == 0)
     index = X86_REG_BX;
 else if (strcmp(jumpSelector, "di") == 0)
     index = X86_REG_DI;
 else if (strcmp(jumpSelector, "bp") == 0)
     index = X86_REG_BP;
 else if (strcmp(jumpSelector, "ax") == 0)
     index = X86_REG_AX;
 else if (strcmp(jumpSelector, "si") == 0)
     index = X86_REG_SI;
 else if (strcmp(jumpSelector, "none") == 0)
     index = X86_REG_INVALID;
 else if (strcmp(jumpSelector, "indirect") == 0)
     index = X86_REG_INVALID;
 else
     assert(0);
 if (strcmp(jumpSelector, "indirect") == 0)
     jumpTables.push_back({indirectJumpAddr, jumpTableBegin, jumpEntries, tableType, index, nullptr});
 else
     jumpTables.push_back({indirectJumpAddr, jumpTableBegin, jumpEntries, tableType, index, nullptr});

 */
