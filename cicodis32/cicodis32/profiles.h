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
    
        .procModifiersStack = {
            {{0x1000, 0x1c0a}, 4},
            {{0x1000, 0x25e3}, 4},
            {{0x1000, 0x29ae}, 4},
            {{0x1000, 0x2cea}, 10},
            {{0x1000, 0x08ba}, 2},
            {{0x1000, 0x09b5}, 6},
            {{0x1000, 0x09e9}, 4},
            {{0x1000, 0x0ad5}, 4},
            {{0x1000, 0x0c24}, 8},
            {{0x1000, 0x269e}, 8},
            {{0x1000, 0x07fd}, 4},
            {{0x1000, 0x2d9a}, 8},
            {{0x1000, 0x3291}, 4},
            {{0x1000, 0x36d4}, 8},
            {{0x1000, 0x35bc}, 4},
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
    .procModifiersStack = {{{0x1020, 0x5133}, 2}},
    //{std::pair<address_t, procRequest_t>({0x1020, 0x5133}, procRequest_t::stackDrop2)},
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
    .procModifiersStack = {
        {{0x1ed, 0xa8ee}, 8},
        {{0x1ed, 0xa9f5}, 8},
        {{0x1ed, 0xa178}, 2}, //1ed:a178
        {{0x1ed, 0x98dd}, 4}, //1ed:98dd
        {{0x1ed, 0x9b14}, 4}, //1ed:9b14
        {{0x1ed, 0xa1ef}, 6}, //1ed:a1ef
        {{0x1ed, 0xa20a}, 2}, //1ed:a20a
        {{0xca6, 0x13bc}, 2},
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
//        {{0x01ed, 0x42f2}, procRequest_t::stackDrop2},
//        {{0x01ed, 0x3e4c}, procRequest_t::stackDrop6},
//        {{0x01ed, 0x5140}, procRequest_t::stackDrop8},
//        {{0x01ed, 0x6809}, procRequest_t::stackDrop2},
        
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

namespace ProfilesLe {
    Options optionsMandel = {
        // BP 160:15e390
        // memdumpbin 169:15e000 40000
    //        .loader = "LoaderSnapshot",
    //        .exec = "MEMDUMP.BIN",
        .loader = "LoaderLe",
        .loadAddress = 0x15e000,
        .exec = "MANDEL.EXE",
        .procList = {{0, 0x15fba3}}
    //        .start = true,
    //        .verbose = true,
    };

}


namespace Profiles {
    Options optionsCC1 = {
        .loader = "LoaderMz",
        .exec = "CC1.EXE",
        .arch = arch_t::arch16,
        .loadAddress = 0x01ed0,
        .terminators = {{0x01ed, 0xfb8a}},
        
        .procModifiers = {
#if 0
            /*
             {{0x01ed, 0x0000}, procRequest_t::popsCs},
             {{0x01ed, 0x0059}, procRequest_t::popsCs},
             {{0x01ed, 0x047d}, procRequest_t::popsCs},
             {{0x01ed, 0x06be}, procRequest_t::popsCs},
             {{0x01ed, 0x06ee}, procRequest_t::popsCs},
             {{0x01ed, 0x070d}, procRequest_t::popsCs},
             {{0x01ed, 0xfbb2}, procRequest_t::popsCs},
             {{0x01ed, 0xfc24}, procRequest_t::popsCs},
             {{0x01ed, 0xfc38}, procRequest_t::popsCs},
             {{0x11b2, 0x00ec}, procRequest_t::popsCs},
             {{0x11b2, 0x06c4}, procRequest_t::popsCs},
             {{0x11b2, 0x0877}, procRequest_t::popsCs},
             {{0x11b2, 0x1001}, procRequest_t::popsCs},
             {{0x11b2, 0x17f1}, procRequest_t::popsCs},
             {{0x11b2, 0x1851}, procRequest_t::popsCs},
             {{0x11b2, 0x18fa}, procRequest_t::popsCs},
             {{0x11b2, 0x1a72}, procRequest_t::popsCs},
             {{0x11b2, 0x1d58}, procRequest_t::popsCs},
             {{0x11b2, 0x2198}, procRequest_t::popsCs},
             {{0x11b2, 0x27a8}, procRequest_t::popsCs},
             {{0x11b2, 0x2f92}, procRequest_t::popsCs},
             {{0x11b2, 0x3cba}, procRequest_t::popsCs},
             {{0x11b2, 0x3eb7}, procRequest_t::popsCs},
             {{0x11b2, 0x4078}, procRequest_t::popsCs},
             {{0x11b2, 0x42b0}, procRequest_t::popsCs},
             {{0x11b2, 0x4cd7}, procRequest_t::popsCs},
             {{0x11b2, 0x5cc5}, procRequest_t::popsCs},
             {{0x11b2, 0x5e06}, procRequest_t::popsCs},
             {{0x11b2, 0x5fb0}, procRequest_t::popsCs},
             {{0x11b2, 0x6035}, procRequest_t::popsCs},
             {{0x11b2, 0x61b1}, procRequest_t::popsCs},
             {{0x11b2, 0x6448}, procRequest_t::popsCs},
             {{0x11b2, 0x66d7}, procRequest_t::popsCs},
             {{0x11b2, 0x67a3}, procRequest_t::popsCs},
             {{0x11b2, 0x6870}, procRequest_t::popsCs},
             {{0x11b2, 0x6a58}, procRequest_t::popsCs},
             {{0x11b2, 0x6c86}, procRequest_t::popsCs},
             {{0x11b2, 0x6dfd}, procRequest_t::popsCs},
             {{0x11b2, 0x6fe5}, procRequest_t::popsCs},
             {{0x11b2, 0x70ec}, procRequest_t::popsCs},
             {{0x11b2, 0x74f5}, procRequest_t::popsCs},
             {{0x11b2, 0x7914}, procRequest_t::popsCs},
             {{0x11b2, 0x80e1}, procRequest_t::popsCs},
             {{0x11b2, 0x863d}, procRequest_t::popsCs},
             {{0x11b2, 0x9e38}, procRequest_t::popsCs},
             {{0x11b2, 0xa1cf}, procRequest_t::popsCs},
             {{0x11b2, 0xa59e}, procRequest_t::popsCs},
             {{0x11b2, 0xa7ef}, procRequest_t::popsCs},
             {{0x11b2, 0xaa3a}, procRequest_t::popsCs},
             {{0x11b2, 0xaef2}, procRequest_t::popsCs},
             {{0x11b2, 0xaf3a}, procRequest_t::popsCs},
             {{0x11b2, 0xb9b9}, procRequest_t::popsCs},
             {{0x1f0b, 0x0000}, procRequest_t::popsCs},
             {{0x1f0b, 0x0045}, procRequest_t::popsCs},
             {{0x1f0b, 0x0097}, procRequest_t::popsCs},
             {{0x1f0b, 0x0399}, procRequest_t::popsCs},
             {{0x1f0b, 0x03fa}, procRequest_t::popsCs},
             {{0x1f0b, 0x0492}, procRequest_t::popsCs},
             {{0x1f0b, 0x04fe}, procRequest_t::popsCs},
             {{0x1f5c, 0x026b}, procRequest_t::popsCs},
             {{0x1f5c, 0x20a2}, procRequest_t::popsCs},
             {{0x28b3, 0x1643}, procRequest_t::popsCs},
             {{0x2a41, 0x0145}, procRequest_t::popsCs},
             {{0x2a41, 0x032e}, procRequest_t::popsCs},
             {{0x2aa3, 0x0201}, procRequest_t::popsCs},
             {{0x2aa3, 0x2708}, procRequest_t::popsCs},
             {{0x2aa3, 0x28a7}, procRequest_t::popsCs},
             {{0x2da3, 0x0ba2}, procRequest_t::popsCs},
             {{0x2da3, 0x0c6b}, procRequest_t::popsCs},
             
             {{0x2188, 0x021f}, procRequest_t::stackDrop4},
             */
            {{0x01ed, 0x0000}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
//            {{0x01ed, 0x0059}, procRequest_t((int)procRequest_t::stackDrop22 | (int)procRequest_t::popsCs)}, // retf
//            {{0x01ed, 0x047d}, procRequest_t((int)procRequest_t::stackDrop30 | (int)procRequest_t::popsCs)}, // retf
            {{0x01ed, 0x06be}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x01ed, 0x06ee}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x01ed, 0x070d}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x01ed, 0x0b2d}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0x0b88}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0x0baf}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0x0c3e}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0x0f38}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0x1037}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0x25f0}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xb1a9}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xcf46}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xcf6c}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd140}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd15c}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd17d}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd1c6}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd342}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd360}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd4e5}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd5c2}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd6d4}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd710}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xd72a}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xdcb9}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xe011}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xe36b}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xe51d}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xe5d3}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xeaea}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xebf2}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xeec1}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xef38}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x01ed, 0xfb96}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x01ed, 0xfbb2}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x01ed, 0xfc24}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x01ed, 0xfc38}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x0000}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x00ec}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x06c4}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x0877}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x1001}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x17f1}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x1851}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x18fa}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x1a72}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x1d58}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x2198}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x27a8}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x2f92}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x33e5}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x35e1}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0x3946}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0x3cba}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x3eb7}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x4078}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x42b0}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x4cd7}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x5b8e}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x5cc5}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x5e06}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x5ef4}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x5fb0}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x6035}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x6105}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0x61b1}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x6448}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x66d7}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x67a3}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x6870}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x694d}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0x6a58}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x6b4d}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x6c18}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0x6c86}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x6dfd}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x6f1a}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x6fe5}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x70ec}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x7213}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0x73fd}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0x74f5}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x7914}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x7d28}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x80e1}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x8265}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x8491}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x853b}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x863d}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x8738}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x899d}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x8d32}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0x94e0}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0x9e38}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xa1cf}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xa467}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0xa59e}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xa669}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xa72f}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xa7ef}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xaa3a}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xab90}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0xaba4}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0xac0b}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0xacc0}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0xad9e}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x11b2, 0xae3b}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xaef2}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xaf3a}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xaf85}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xb2cd}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xb51b}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xb63c}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xb7b9}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xb911}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xb965}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xb981}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xb9b9}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xbaf6}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xbb28}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x11b2, 0xd1e2}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f0b, 0x0000}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f0b, 0x0045}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
//            {{0x1f0b, 0x0097}, procRequest_t((int)procRequest_t::stackDrop14 | (int)procRequest_t::popsCs)}, // retf
//            {{0x1f0b, 0x0101}, procRequest_t((int)procRequest_t::stackDrop16 | (int)procRequest_t::popsCs)}, // retf
//            {{0x1f0b, 0x0309}, procRequest_t((int)procRequest_t::stackDrop16 | (int)procRequest_t::popsCs)}, // retf
//            {{0x1f0b, 0x0349}, procRequest_t((int)procRequest_t::stackDrop12 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f0b, 0x0399}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f0b, 0x03c7}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f0b, 0x03de}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
//            {{0x1f0b, 0x03fa}, procRequest_t((int)procRequest_t::stackDrop12 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f0b, 0x048a}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x1f0b, 0x0492}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f0b, 0x04fe}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f5c, 0x0000}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f5c, 0x000f}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f5c, 0x0047}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f5c, 0x00eb}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f5c, 0x01ac}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f5c, 0x026b}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f5c, 0x0c70}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
//            {{0x1f5c, 0x0d2d}, procRequest_t((int)procRequest_t::stackDrop14 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f5c, 0x0dc7}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
//            {{0x1f5c, 0x1915}, procRequest_t((int)procRequest_t::stackDrop12 | (int)procRequest_t::popsCs)}, // retf
            {{0x1f5c, 0x20a2}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x0000}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x0043}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x021f}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x02d3}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x0310}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x0357}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x0628}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x08a7}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x0a36}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2188, 0x251d}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x0000}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x0221}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
//            {{0x28b3, 0x02ef}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x0446}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x059d}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x06ec}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x0711}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x0740}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x0992}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x13b5}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x1643}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x16ef}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x28b3, 0x1789}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a31, 0x0000}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a31, 0x0038}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a31, 0x0058}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a31, 0x0078}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a31, 0x00cc}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x0000}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x0030}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2a41, 0x0099}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2a41, 0x00e7}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2a41, 0x0145}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
//            Mixed ret in 2a41:0145 sub_2a555()
            {{0x2a41, 0x016d}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x01c2}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x0215}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x0259}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x0273}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x029e}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x02be}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2a41, 0x02f3}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x02fa}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x030c}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x032e}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2a41, 0x0474}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2a41, 0x047b}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2a41, 0x04d4}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2a41, 0x04f5}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2a41, 0x04fc}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2a41, 0x0608}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2aa3, 0x0000}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x00c9}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x00eb}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x00f9}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x011f}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x0172}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x01c5}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x0201}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x0220}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x025d}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x0278}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x039b}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x0445}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x054b}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x0714}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
//            {{0x2aa3, 0x16bb}, procRequest_t((int)procRequest_t::stackDrop14 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x1757}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x191f}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x1a4d}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x2389}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x2708}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x28a7}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x29c5}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x2a5e}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x2df5}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x2e58}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2aa3, 0x2ea1}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2d99, 0x000b}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2d99, 0x006c}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // retf
            {{0x2d99, 0x0084}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0000}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x00d8}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0194}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x01a2}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x01ae}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x01bc}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x01c3}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x01ce}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x01d6}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0207}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x020e}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x020e}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
//            {{0x2da3, 0x025d}, procRequest_t((int)procRequest_t::stackDrop12 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0279}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0329}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
//            Mixed ret in 2da3:0329 sub_2dd59()
            {{0x2da3, 0x0364}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
//            Mixed ret in 2da3:0364 sub_2dd94()
            {{0x2da3, 0x03b5}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0446}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0446}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x04e2}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x04e2}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x04e2}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0595}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0595}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x05b9}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x05ce}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x05ce}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0617}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0625}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0634}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
//            {{0x2da3, 0x064e}, procRequest_t((int)procRequest_t::stackDrop12 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0680}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x06c1}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x06ed}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0724}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x074f}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x07d0}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x08d4}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0980}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x09cf}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0a07}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0a14}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0a8e}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0a8e}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
//            {{0x2da3, 0x0b26}, procRequest_t((int)procRequest_t::stackDrop14 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0b71}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0ba2}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0c12}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0c17}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0c6b}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0ca6}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0e61}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0e85}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0e85}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x0eee}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0f0d}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0f51}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0fb6}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x0ff4}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x1022}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x102b}, procRequest_t((int)procRequest_t::stackDrop8 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x10a3}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x10c8}, procRequest_t((int)procRequest_t::stackDrop2 | (int)procRequest_t::popsCs)}, // ret
            {{0x2da3, 0x10d7}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x10de}, procRequest_t((int)procRequest_t::stackDrop6 | (int)procRequest_t::popsCs)}, // retf
            {{0x2da3, 0x11c8}, procRequest_t((int)procRequest_t::stackDrop10 | (int)procRequest_t::popsCs)}, // retf
            //
            {{0x28b3, 0x02ef}, procRequest_t((int)procRequest_t::stackDrop4 | (int)procRequest_t::popsCs | (int)procRequest_t::callFar)}, // retf
#endif
            
        },
            .procModifiersStack = {
//                {{0x01ed, 0x0000}, 8},
                {{0x01ed, 0x0000}, 10}, // sub_1ed0 retf
                {{0x01ed, 0x0059}, 22}, // sub_1f29 retf
                {{0x01ed, 0x047d}, 30}, // sub_234d retf
                {{0x01ed, 0x0f38}, 8}, // sub_2e08 ret
                {{0x01ed, 0x1037}, 8}, // sub_2f07 ret
                {{0x01ed, 0x25f0}, 6}, // sub_44c0 ret
                {{0x01ed, 0xb1a9}, 2}, // sub_d079 ret
                {{0x01ed, 0xd5c2}, 2}, // sub_f492 ret
                {{0x01ed, 0xe51d}, 4}, // sub_103ed ret
                {{0x11b2, 0x00ec}, 4}, // sub_11c0c retf
                {{0x11b2, 0x06c4}, 10}, // sub_121e4 retf
                {{0x11b2, 0x0877}, 4}, // sub_12397 retf
                {{0x11b2, 0x1001}, 4}, // sub_12b21 retf
                {{0x11b2, 0x6c86}, 4}, // sub_187a6 retf
                {{0x11b2, 0x6fe5}, 4}, // sub_18b05 retf
                {{0x11b2, 0x7213}, 2}, // sub_18d33 ret
                {{0x11b2, 0x73fd}, 2}, // sub_18f1d ret
                {{0x11b2, 0x80e1}, 10}, // sub_19c01 retf
                {{0x11b2, 0x899d}, 6}, // sub_1a4bd retf
                {{0x11b2, 0xaef2}, 4}, // sub_1ca12 retf
                {{0x11b2, 0xaf3a}, 4}, // sub_1ca5a retf
                {{0x11b2, 0xb9b9}, 4}, // sub_1d4d9 retf
                {{0x11b2, 0xbb28}, 6}, // sub_1d648 retf
                {{0x1f0b, 0x0000}, 6}, // sub_1f0b0 retf
                {{0x1f0b, 0x0045}, 6}, // sub_1f0f5 retf
                {{0x1f0b, 0x0097}, 14}, // sub_1f147 retf
                {{0x1f0b, 0x0101}, 16}, // sub_1f1b1 retf
                {{0x1f0b, 0x0309}, 16}, // sub_1f3b9 retf
                {{0x1f0b, 0x0349}, 12}, // sub_1f3f9 retf
                {{0x1f0b, 0x03fa}, 12}, // sub_1f4aa retf
                {{0x1f5c, 0x000f}, 4}, // sub_1f5cf retf
                {{0x1f5c, 0x0047}, 4}, // sub_1f607 retf
                {{0x1f5c, 0x01ac}, 4}, // sub_1f76c retf
                {{0x1f5c, 0x0d2d}, 14}, // sub_202ed retf
                {{0x1f5c, 0x1915}, 12}, // sub_20ed5 retf
                {{0x2188, 0x0000}, 6}, // sub_21880 retf
                {{0x2188, 0x0043}, 6}, // sub_218c3 retf
                {{0x2188, 0x021f}, 4}, // sub_21a9f retf
                {{0x2188, 0x02d3}, 6}, // sub_21b53 retf
                {{0x2188, 0x0310}, 4}, // sub_21b90 retf
                {{0x2188, 0x0357}, 4}, // sub_21bd7 retf
                {{0x2188, 0x08a7}, 8}, // sub_22127 retf
                {{0x2188, 0x251d}, 8}, // sub_23d9d retf
                {{0x28b3, 0x0000}, 6}, // sub_28b30 retf
                {{0x28b3, 0x0221}, 6}, // sub_28d51 retf
                {{0x28b3, 0x02ef}, 4}, // sub_28e1f retf
                {{0x28b3, 0x0446}, 4}, // sub_28f76 retf
                {{0x28b3, 0x059d}, 4}, // sub_290cd retf
                {{0x28b3, 0x0711}, 4}, // sub_29241 retf
                {{0x28b3, 0x0740}, 6}, // sub_29270 retf
                {{0x28b3, 0x0992}, 6}, // sub_294c2 retf
                {{0x28b3, 0x13b5}, 8}, // sub_29ee5 retf
                {{0x2a31, 0x00cc}, 4}, // sub_2a3dc retf
                {{0x2a41, 0x0145}, 4}, // sub_2a555 ret retf
                {{0x2a41, 0x016d}, 4}, // sub_2a57d retf
                {{0x2a41, 0x0215}, 6}, // sub_2a625 retf
                {{0x2a41, 0x0259}, 4}, // sub_2a669 retf
                {{0x2a41, 0x0273}, 4}, // sub_2a683 retf
                {{0x2a41, 0x029e}, 4}, // sub_2a6ae retf
                {{0x2a41, 0x032e}, 6}, // sub_2a73e retf
                {{0x2aa3, 0x00c9}, 4}, // sub_2aaf9 retf
                {{0x2aa3, 0x00eb}, 4}, // sub_2ab1b retf
                {{0x2aa3, 0x00f9}, 4}, // sub_2ab29 retf
                {{0x2aa3, 0x011f}, 6}, // sub_2ab4f retf
                {{0x2aa3, 0x0172}, 6}, // sub_2aba2 retf
                {{0x2aa3, 0x01c5}, 4}, // sub_2abf5 retf
                {{0x2aa3, 0x0220}, 4}, // sub_2ac50 retf
                {{0x2aa3, 0x025d}, 4}, // sub_2ac8d retf
                {{0x2aa3, 0x0278}, 6}, // sub_2aca8 retf
                {{0x2aa3, 0x039b}, 10}, // sub_2adcb retf
                {{0x2aa3, 0x0445}, 10}, // sub_2ae75 retf
                {{0x2aa3, 0x054b}, 4}, // sub_2af7b retf
                {{0x2aa3, 0x0714}, 10}, // sub_2b144 retf
                {{0x2aa3, 0x16bb}, 14}, // sub_2c0eb retf
                {{0x2aa3, 0x1757}, 10}, // sub_2c187 retf
                {{0x2aa3, 0x191f}, 10}, // sub_2c34f retf
                {{0x2aa3, 0x1a4d}, 10}, // sub_2c47d retf
                {{0x2aa3, 0x2389}, 10}, // sub_2cdb9 retf
                {{0x2aa3, 0x28a7}, 4}, // sub_2d2d7 retf
                {{0x2aa3, 0x29c5}, 10}, // sub_2d3f5 retf
                {{0x2aa3, 0x2a5e}, 10}, // sub_2d48e retf
                {{0x2aa3, 0x2df5}, 10}, // sub_2d825 retf
                {{0x2d99, 0x006c}, 8}, // sub_2d9fc retf
                {{0x2d99, 0x0084}, 8}, // sub_2da14 retf
                {{0x2da3, 0x025d}, 12}, // sub_2dc8d retf
                {{0x2da3, 0x0329}, 8}, // sub_2dd59 retf
                {{0x2da3, 0x0364}, 8}, // sub_2dd94 retf
                {{0x2da3, 0x0634}, 6}, // sub_2e064 retf
                {{0x2da3, 0x064e}, 12}, // sub_2e07e retf
                {{0x2da3, 0x0680}, 10}, // sub_2e0b0 retf
                {{0x2da3, 0x06c1}, 6}, // sub_2e0f1 retf
                {{0x2da3, 0x06ed}, 10}, // sub_2e11d retf
                {{0x2da3, 0x0724}, 10}, // sub_2e154 retf
                {{0x2da3, 0x074f}, 4}, // sub_2e17f retf
                {{0x2da3, 0x07d0}, 10}, // sub_2e200 retf
                {{0x2da3, 0x08d4}, 8}, // sub_2e304 retf
                {{0x2da3, 0x0980}, 4}, // sub_2e3b0 retf
                {{0x2da3, 0x0b26}, 14}, // sub_2e556 retf
                {{0x2da3, 0x0b71}, 10}, // sub_2e5a1 retf
                {{0x2da3, 0x0ba2}, 10}, // sub_2e5d2 retf
                {{0x2da3, 0x0c12}, 6}, // sub_2e642 retf
                {{0x2da3, 0x0c17}, 6}, // sub_2e647 retf
                {{0x2da3, 0x0c6b}, 6}, // sub_2e69b retf
                {{0x2da3, 0x0eee}, 6}, // sub_2e91e retf
                {{0x2da3, 0x0f0d}, 6}, // sub_2e93d retf
                {{0x2da3, 0x0f51}, 6}, // sub_2e981 retf
                {{0x2da3, 0x0fb6}, 8}, // sub_2e9e6 retf
                {{0x2da3, 0x0ff4}, 10}, // sub_2ea24 retf
                {{0x2da3, 0x1022}, 8}, // sub_2ea52 retf
                {{0x2da3, 0x102b}, 8}, // sub_2ea5b retf
                {{0x2da3, 0x10a3}, 6}, // sub_2ead3 retf
                {{0x2da3, 0x10d7}, 6}, // sub_2eb07 retf
                {{0x2da3, 0x10de}, 6}, // sub_2eb0e retf
                {{0x2da3, 0x11c8}, 10}, // sub_2ebf8 retf
            },
            .jumpTables = {
                std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x2da3, 0x0caa), .baseptr = (const uint8_t*)"\xb7\x0c\xa3\x2d", .type = jumpTable_t::CallDwords, .elements = {0}, .selector = "memoryAGet32(es, bx + di)", .useCaseOffset = true }),
            },

//        2da3:0caa - 2da3:0cb7
//        .verbose = true, .relocations = false, .verbose = true, .recursive = false, .procList = {{0x28b3, 0x02ef}},
//            .verboseAsm = true
    };
}
