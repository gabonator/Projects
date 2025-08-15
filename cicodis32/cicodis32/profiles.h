//
//  profiles.h
//  cicodis32
//
//  Created by Gabriel Valky on 10/08/2025.
//

namespace Profiles {

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


Options optionsRick2 = {
    .loader = "LoaderMz",
    .exec = "RICK2.EXE",
    .arch = arch_t::arch16,
//    .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1040, /*0x5e22*/ 0x16222-0x10400}},
//    .procModifiers = {{{0x1040, 0x16222-0x10400}, (procRequest_t)((int)procRequest_t::returnCarry | (int)procRequest_t::callNear)}},

//            .verbose = true, .relocations = false, .recursive = false, .start = false, .procList = {{0x1040, /*0x5e22*/ 0x17222-0x10400}}, //    sub_111f1 - temp_cond 1040:e13 jg 0xe18
    
    //17222 - ADC 16222- flags, 1ae81, 1a1d7 - stack
    // 1c359 - sp shift? 18d28, 18351
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
        },
        .inject = {
            {{0x1040, 0x16d57 - 0x10400}, "sync();"},
            {{0x1040, 0x19a4b - 0x10400}, "sync();"},
            {{0x1040, 0x19e18 - 0x10400}, "memoryASet(cs, 0xbda2, 0xc3); flags.carry = false; return;"},
            {{0x1040, 0x1bfa0 - 0x10400}, "return;"},
            {{0x1040, 0x1c1a2 - 0x10400}, "return;"},
            {{0x1040, 0x1c2e2 - 0x10400}, "if (0)"},
            {{0x1040, 0x1c31f+3 - 0x10400}, "if (0)"},
        }
};

Options optionsGoose = {
    .loader = "LoaderMz",
    .exec = "GOOSE.EXE",
    .arch = arch_t::arch16,
    .simpleStack = true,
    .jumpTables = {
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x1000, 0x104e),
            .table = address_t(0x1000, 0x105a),
            .type = jumpTable_t::CallWords,
            .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34},
                .selector = "bx",
        })},
    
        .procModifiers = {
            {{0x1000, 0x1c0a}, procRequest_t::stackDrop4},
            {{0x1000, 0x25e3}, procRequest_t::stackDrop4},
            {{0x1000, 0x29ae}, procRequest_t::stackDrop4},
            {{0x1000, 0x2cea}, procRequest_t::stackDrop10},
            {{0x1000, 0x08ba}, procRequest_t::stackDrop2},
            {{0x1000, 0x09b5}, procRequest_t::stackDrop6},
            {{0x1000, 0x09e9}, procRequest_t::stackDrop4},
            {{0x1000, 0x0ad5}, procRequest_t::stackDrop4},
            {{0x1000, 0x0c24}, procRequest_t::stackDrop8},
            {{0x1000, 0x269e}, procRequest_t::stackDrop8},
            {{0x1000, 0x07fd}, procRequest_t::stackDrop4},
            {{0x1000, 0x2d9a}, procRequest_t::stackDrop8},
            {{0x1000, 0x3291}, procRequest_t::stackDrop4},
            {{0x1000, 0x36d4}, procRequest_t::stackDrop8},
            {{0x1000, 0x35bc}, procRequest_t::stackDrop4},
            //{{0x1000, 0x3801}, procRequest_t::stackDrop4}, force simple stack
        }
};
Options optionsRick1 = {
    .loader = "LoaderMz",
    .exec = "rick1.exe",
    //        .verbose = true,  .relocations = false, .recursive = false, .start = false, .procList = {{0x341b, 0x36413- 0x341b0}},
    //        .verbose = true,  .relocations = false, .recursive = false, .start = false, .procList = {{0x341b, 0x354c7- 0x341b0}},
    //sub_34442
//    .verbose = true,  .relocations = false, .recursive = false, .start = false, .procList = {{0x341b, 0x345e3 - 0x341b0}},
    .jumpTables = {
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x341b, 0x228a),
            .table = address_t(0x1040, 0x80bf),
            .type = jumpTable_t::JumpWords,
            .elements = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
                23},
                .selector = "di",
        })},
        .inject = {
            {{0x341b, 0x3430c - 0x341b0}, "sync();"},
            {{0x341b, 0x345e3 - 0x341b0}, "sync();"},
            {{0x341b, 0x3516e - 0x341b0}, "sync();"},
            {{0x341b, 0x35cbd - 0x341b0}, "sync();"},
            {{0x341b, 0x36122 - 0x341b0}, "sync(); return;"},
            {{0x341b, 0x3430c - 0x341b0}, "sync();"},
        },
//        .procModifiers = {
//            {{0x341b, 0x345e3 - 0x341b0}, procRequest_t{(int)procRequest_t::returnZero | (int)procRequest_t::callNear}},
//        }

};

Options optionsFox = {
    .loader = "LoaderMz",
    .exec = "fox.exe",
    .arch = arch_t::arch16,
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
    },
    .inject = {
        {{0x1020, 0x105f7 - 0x10200}, "sync();"},
        {{0x1020, 0x10603 - 0x10200}, "sync();"},
        {{0x1020, 0x10cd2 - 0x10200}, "return false;"},
        {{0x1020, 0x10cf1 - 0x10200}, "return true;"},
        {{0x1020, 0x112dd - 0x10200}, "/*"},
        {{0x1020, 0x112f3 - 0x10200}, "*/"},
        {{0x1020, 0x119eb - 0x10200}, "sync(); return;"},
        {{0x1020, 0x13443 - 0x10200}, "static int counter=0; if (counter++%4==0) sync(); return;"},
        {{0x1020, 0x153f1 - 0x10200}, "sync();"},
        {{0x1020, 0x15444 - 0x10200}, "sync();"},

    }
};
Options optionsBumpy = {
    .loader = "LoaderMz",
    .exec = "BUMPY.EXE",
    .arch = arch_t::arch16,
    .loadAddress = 0x01ed0,
//    .verbose = true,
    //        .relocations = false, .verbose = true, .recursive = false, .procList = {{0x1ed, 0xaadd}},
    .procModifiers = {
        {{0x1ed, 0xa8ee}, procRequest_t::stackDrop8},
        {{0x1ed, 0xa9f5}, procRequest_t::stackDrop8},
        {{0x1ed, 0xa178}, procRequest_t::stackDrop2}, //1ed:a178
        {{0x1ed, 0x98dd}, procRequest_t::stackDrop4}, //1ed:98dd
        {{0x1ed, 0x9b14}, procRequest_t::stackDrop4}, //1ed:9b14
        {{0x1ed, 0xa1ef}, procRequest_t::stackDrop6}, //1ed:a1ef
        {{0x1ed, 0xa20a}, procRequest_t::stackDrop2}, //1ed:a20a
        {{0xca6, 0x13bc}, procRequest_t::stackDrop2},
        //sub_c9ad not needed!,   sub_dddb
//        {{0x01ed, 0xaadd}, (procRequest_t)((int)procRequest_t::returnZero | (int)procRequest_t::returnCarry | (int)procRequest_t::callNear)}
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
        },
};

Options optionsAv = {
    .loader = "LoaderMz",
    .exec = "av.exe",
    .arch = arch_t::arch16,
//    .verbose = true,
    .loadAddress = 0x01ed0,
    
    .jumpTables = {
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x01ed, 0x007e),
            .table = address_t(0x0a57, 0x0958),
            .type = jumpTable_t::CallWords,
            .elements = {0},
            .selector = "memoryAGet16(ds, 0x0958)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x01ed, 0x00fe),
            .table = address_t(0x0a57, 0x095c),
            .type = jumpTable_t::CallWords,
            .elements = {0},
            .selector = "memoryAGet16(ds, 0x095c)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x01ed, 0x6710),
            .baseptr = (const uint8_t*)"\x00\x00\xe6\x08",
            .type = jumpTable_t::CallDwords,
            .elements = {0},
            .selector = "memoryAGet32(ds, 0x0412)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x08e6, 0x0004),
            .table = address_t(0x08e6, 0x000f),
            .type = jumpTable_t::CallWords,
            .elements = sequence("0-28"),
            .selector = "si"
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x043e, 0x0005),
            .table = address_t(0x043e, 0x0016),
            .type = jumpTable_t::CallWords,
            .elements = sequence("0-28"),
            .selector = "si"
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x08e6, 0x01df),
            .baseptr = (const uint8_t*)"\x00\x00\x3e\x04",
            .type = jumpTable_t::CallDwords,
            .elements = {0},
            .selector = "memoryAGet32(ds, 0x0049)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x043e, 0x047a),
            .baseptr = (const uint8_t*)"\x82\x04",
            .type = jumpTable_t::CallWords,
            .elements = {0},
            .selector = "memoryAGet16(ds, bx + 8)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x08e6, 0x0259),
            .baseptr = (const uint8_t*)"\x00\x00\x3e\x04",
            .type = jumpTable_t::CallDwords,
            .elements = {0},
            .selector = "memoryAGet32(ds, 0x0049)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x01ed, 0x695c),
            .baseptr = (const uint8_t*)"\x00\x00\xe6\x08",
            .type = jumpTable_t::CallDwords,
            .elements = {0},
            .selector = "memoryAGet32(ds, 0x0412)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x08e6, 0x11f5),
            .baseptr = (const uint8_t*)"\x00\x00\x3e\x04",
            .type = jumpTable_t::CallDwords,
            .elements = {0},
            .selector = "memoryAGet32(ds, 0x0049)",
            .useCaseOffset = true
        }),

        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6744), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6796), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6821), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6833), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6850), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x687c), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6973), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6990), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x69d0), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6a33), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6a8f), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6aa2), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6b1c), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6b3b), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6bc4), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6c2a), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6c39), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6c56), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6c6f), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6cb5), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6cdb), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6d04), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x6da7), .baseptr = (const uint8_t*)"\x00\x00\xe6\x08", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(ds, 0x0412)", .useCaseOffset = true }),

        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x043e, 0x08e4),
            .baseptr = (const uint8_t*)"\xf1\x07",
            .type = jumpTable_t::CallWords,
            .elements = {0},
            .selector = "memoryAGet16(cs, 0x07cf)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x043e, 0x0927),
            .baseptr = (const uint8_t*)"\xf1\x07",
            .type = jumpTable_t::CallWords,
            .elements = {0},
            .selector = "memoryAGet16(cs, 0x07cf)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{ .instruction = address_t(0x043e, 0x08ca), .baseptr = (const uint8_t*)"\x38\x05", .type = jumpTable_t::CallWords, .elements = {0}, .selector = "memoryAGet16(ds, 0x051e)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{ .instruction = address_t(0x043e, 0x0e66), .baseptr = (const uint8_t*)"\x38\x05", .type = jumpTable_t::CallWords, .elements = {0}, .selector = "memoryAGet16(ds, 0x051e)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{ .instruction = address_t(0x043e, 0x0e70), .baseptr = (const uint8_t*)"\x38\x05", .type = jumpTable_t::CallWords, .elements = {0}, .selector = "memoryAGet16(cs, 0x051e)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{ .instruction = address_t(0x043e, 0x0f3e), .baseptr = (const uint8_t*)"\x38\x05", .type = jumpTable_t::CallWords, .elements = {0}, .selector = "memoryAGet16(ds, 0x051e)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{ .instruction = address_t(0x043e, 0x0b18), .baseptr = (const uint8_t*)"\x38\x05", .type = jumpTable_t::CallWords, .elements = {0}, .selector = "memoryAGet16(cs, 0x051e)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{ .instruction = address_t(0x043e, 0x0b23), .baseptr = (const uint8_t*)"\x38\x05", .type = jumpTable_t::CallWords, .elements = {0}, .selector = "memoryAGet16(ds, 0x051e)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{ .instruction = address_t(0x043e, 0x0726), .baseptr = (const uint8_t*)"\x38\x05\x48\x05", .type = jumpTable_t::CallWords, .elements = {0, 1}, .selector = "memoryAGet16(ds, 0x051e)", .useCaseOffset = true }),

        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x08e6, 0x03dc),
            .baseptr = (const uint8_t*)"\x00\x00\x3e\x04",
            .type = jumpTable_t::CallDwords,
            .elements = {0},
            .selector = "memoryAGet32(ds, 0x0049)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x08e6, 0x1267),
            .baseptr = (const uint8_t*)"\x00\x00\x3e\x04",
            .type = jumpTable_t::CallDwords,
            .elements = {0},
            .selector = "memoryAGet32(ds, 0x0049)",
            .useCaseOffset = true
        }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{
            .instruction = address_t(0x08e6, 0x1298),
            .baseptr = (const uint8_t*)"\x00\x00\x3e\x04",
            .type = jumpTable_t::CallDwords,
            .elements = {0},
            .selector = "memoryAGet32(ds, 0x0049)",
            .useCaseOffset = true
        }),

    },

    .procModifiers = {
        {{0x01ed, 0x017d}, procRequest_t::popsCs},
        {{0x01ed, 0x415d}, procRequest_t::popsCs},
        {{0x01ed, 0x4169}, procRequest_t::popsCs},
        {{0x01ed, 0x4175}, procRequest_t::popsCs},
        {{0x01ed, 0x433d}, procRequest_t::popsCs},
        {{0x01ed, 0x449f}, procRequest_t::popsCs},
        {{0x01ed, 0x53b5}, procRequest_t::popsCs},
        {{0x01ed, 0x547d}, procRequest_t::popsCs},
        {{0x01ed, 0x5513}, procRequest_t::popsCs},
        {{0x01ed, 0x566d}, procRequest_t::popsCs},
        {{0x01ed, 0x59f2}, procRequest_t::popsCs},
        {{0x01ed, 0x5cb6}, procRequest_t::popsCs},
        {{0x01ed, 0x5d98}, procRequest_t::popsCs},
        {{0x01ed, 0x5e9e}, procRequest_t::popsCs},
        {{0x01ed, 0x5f8b}, procRequest_t::popsCs},
        {{0x01ed, 0x608c}, procRequest_t::popsCs},
        {{0x01ed, 0x6197}, procRequest_t::popsCs},
        {{0x01ed, 0x62fa}, procRequest_t::popsCs},
        {{0x01ed, 0x643d}, procRequest_t::popsCs},
        {{0x01ed, 0x647d}, procRequest_t::popsCs},
        {{0x01ed, 0x666c}, procRequest_t::popsCs},
        {{0x01ed, 0x66bc}, procRequest_t::popsCs},
        {{0x01ed, 0x66f1}, procRequest_t::popsCs},
        {{0x01ed, 0x6721}, procRequest_t::popsCs},
        {{0x01ed, 0x6781}, procRequest_t::popsCs},
        {{0x01ed, 0x6809}, procRequest_t::popsCs},
        {{0x01ed, 0x683c}, procRequest_t::popsCs},
        {{0x01ed, 0x6859}, procRequest_t::popsCs},
        {{0x01ed, 0x68ab}, procRequest_t::popsCs},
        {{0x01ed, 0x6940}, procRequest_t::popsCs},
        {{0x01ed, 0x6965}, procRequest_t::popsCs},
        {{0x01ed, 0x697c}, procRequest_t::popsCs},
        {{0x01ed, 0x69b6}, procRequest_t::popsCs},
        {{0x01ed, 0x6a7b}, procRequest_t::popsCs},
        {{0x01ed, 0x6b25}, procRequest_t::popsCs},
        {{0x01ed, 0x6ba4}, procRequest_t::popsCs},
        {{0x01ed, 0x6c12}, procRequest_t::popsCs},
        {{0x01ed, 0x6c78}, procRequest_t::popsCs},
        {{0x01ed, 0x6cbe}, procRequest_t::popsCs},
        {{0x01ed, 0x6ce4}, procRequest_t::popsCs},
        {{0x043e, 0x0000}, procRequest_t::popsCs},
        {{0x08e6, 0x007a}, procRequest_t::popsCs},
        {{0x08e6, 0x00ec}, procRequest_t::popsCs},
        {{0x08e6, 0x0108}, procRequest_t::popsCs},
        {{0x08e6, 0x0126}, procRequest_t::popsCs},
        {{0x08e6, 0x0140}, procRequest_t::popsCs},
        {{0x08e6, 0x0149}, procRequest_t::popsCs},
        {{0x08e6, 0x0156}, procRequest_t::popsCs},
        {{0x08e6, 0x01b4}, procRequest_t::popsCs},
        {{0x08e6, 0x01ba}, procRequest_t::popsCs},
        {{0x08e6, 0x01c8}, procRequest_t::popsCs},
        {{0x08e6, 0x01d2}, procRequest_t::popsCs},
        {{0x08e6, 0x0222}, procRequest_t::popsCs},
        {{0x01ed, 0x42f2}, procRequest_t::stackDrop2},
        //{{0x01ed, 0x464e}, procRequest_t::stackDrop2},
        {{0x01ed, 0x3e4c}, procRequest_t::stackDrop6},
        {{0x01ed, 0x5140}, procRequest_t::stackDrop8},
        {{0x01ed, 0x6809}, procRequest_t::stackDrop2},
        
        {{0x08e6, 0x0222}, procRequest_t::popsCs},
    },
    .inject = {
        {{0x01ed, 0x0641}, "sync();"},
    },
        .isolateLabels = {
            {0x8e6, 0x75}
        }
    //.procList = {{0x043e, 0x0072}}
};

};
