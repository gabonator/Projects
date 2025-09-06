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
    
    .procModifiersStack = {
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
        {{0x1f5c, 0x10d7}, 14}, // sub_20697 retf
        {{0x1f5c, 0x1915}, 12}, // sub_20ed5 retf
        {{0x1f5c, 0x19e3}, 4}, // sub_20fa3 retf
        {{0x2188, 0x0000}, 6}, // sub_21880 retf
        {{0x2188, 0x0043}, 6}, // sub_218c3 retf
        {{0x2188, 0x021f}, 4}, // sub_21a9f retf
        {{0x2188, 0x02d3}, 6}, // sub_21b53 retf
        {{0x2188, 0x0310}, 4}, // sub_21b90 retf
        {{0x2188, 0x0357}, 4}, // sub_21bd7 retf
        {{0x2188, 0x03ab}, 6}, // sub_21c2b retf
        {{0x2188, 0x068d}, 4}, // sub_21f0d retf
        {{0x2188, 0x075e}, 6}, // sub_21fde retf
        {{0x2188, 0x08a7}, 8}, // sub_22127 retf
        {{0x2188, 0x0a66}, 8}, // sub_222e6 retf
        {{0x2188, 0x1ddb}, 12}, // sub_2365b retf
        {{0x2188, 0x1e74}, 14}, // sub_236f4 retf
        {{0x2188, 0x1f58}, 6}, // sub_237d8 retf
        {{0x2188, 0x1fb9}, 8}, // sub_23839 retf
        {{0x2188, 0x1fc2}, 8}, // sub_23842 retf
        {{0x2188, 0x2176}, 8}, // sub_239f6 retf
        {{0x2188, 0x251d}, 8}, // sub_23d9d retf
        {{0x2188, 0x2850}, 8}, // sub_240d0 retf
        {{0x2188, 0x2877}, 8}, // sub_240f7 retf
        {{0x2188, 0x298a}, 8}, // sub_2420a retf
        {{0x2188, 0x2acf}, 8}, // sub_2434f retf
        {{0x2188, 0x2bd4}, 8}, // sub_24454 retf
        {{0x2188, 0x2d37}, 8}, // sub_245b7 retf
        {{0x2188, 0x2e25}, 8}, // sub_246a5 retf
        {{0x2188, 0x2f83}, 8}, // sub_24803 retf
        {{0x2188, 0x323c}, 8}, // sub_24abc retf
        {{0x2188, 0x32f6}, 8}, // sub_24b76 retf
        {{0x2188, 0x3416}, 8}, // sub_24c96 retf
        {{0x2188, 0x36b0}, 8}, // sub_24f30 retf
        {{0x2188, 0x3904}, 8}, // sub_25184 retf
        {{0x2188, 0x3a2e}, 8}, // sub_252ae retf
        {{0x2188, 0x3be8}, 8}, // sub_25468 retf
        {{0x2188, 0x3d23}, 8}, // sub_255a3 retf
        {{0x2188, 0x3e70}, 8}, // sub_256f0 retf
        {{0x2188, 0x3f13}, 8}, // sub_25793 retf
        {{0x2188, 0x3f6c}, 8}, // sub_257ec retf
        {{0x2188, 0x403a}, 8}, // sub_258ba retf
        {{0x2188, 0x4145}, 8}, // sub_259c5 retf
        {{0x2188, 0x47b9}, 8}, // sub_26039 retf
        {{0x2188, 0x48fe}, 8}, // sub_2617e retf
        {{0x2188, 0x4a4b}, 8}, // sub_262cb retf
        {{0x2188, 0x4a82}, 8}, // sub_26302 retf
        {{0x2188, 0x4ad3}, 8}, // sub_26353 retf
        {{0x2188, 0x4c92}, 8}, // sub_26512 retf
        {{0x2188, 0x4fd4}, 8}, // sub_26854 retf
        {{0x2188, 0x52e7}, 8}, // sub_26b67 retf
        {{0x2188, 0x55ec}, 8}, // sub_26e6c retf
        {{0x2188, 0x5855}, 8}, // sub_270d5 retf
        {{0x2188, 0x5bbe}, 8}, // sub_2743e retf
        {{0x2188, 0x5c8f}, 8}, // sub_2750f retf
        {{0x2188, 0x6232}, 8}, // sub_27ab2 retf
        {{0x2188, 0x62f2}, 8}, // sub_27b72 retf
        {{0x2188, 0x6458}, 8}, // sub_27cd8 retf
        {{0x2188, 0x6681}, 8}, // sub_27f01 retf
        {{0x2188, 0x672b}, 8}, // sub_27fab retf
        {{0x2188, 0x69d3}, 8}, // sub_28253 retf
        {{0x2188, 0x6afa}, 8}, // sub_2837a retf
        {{0x2188, 0x6d31}, 8}, // sub_285b1 retf
        {{0x2188, 0x6ff6}, 8}, // sub_28876 retf
        {{0x2188, 0x70e4}, 8}, // sub_28964 retf
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
        {{0x2a41, 0x02c6}, 4}, // sub_2a6d6 retf
        {{0x2a41, 0x032e}, 6}, // sub_2a73e retf
        {{0x2a41, 0x0359}, 6}, // sub_2a769 retf
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
        {{0x2d99, 0x0045}, 8}, // sub_2d9d5 retf
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
        {{0x2da3, 0x0cb7}, 6}, // sub_2e6e7 retf
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
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x2da3, 0x0caa), .baseptr = (const uint8_t*)"\xb7\x0c\xa3\x2d\x59\x03\x41\x2a", .type = jumpTable_t::CallDwords, .elements = {0, 1}, .selector = "memoryAGet32(es, bx + di)", .useCaseOffset = true }),
            //0x2a41 0359
            //
            // 2188 2241   \x41\x22\x88\x21
            // remvoe \x3f\x0a\xed\x01 \x27\x07\xed\x01
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xd87c), .baseptr = (const uint8_t*)"\x50\x28\x88\x21\x77\x28\x88\x21\x58\x64\x88\x21\xbe\x5b\x88\x21\x83\x2f\x88\x21\xb9\x1f\x88\x21\x55\x58\x88\x21\x8f\x5c\x88\x21\x32\x62\x88\x21\x4b\x4a\x88\x21\x82\x4a\x88\x21\xfa\x6a\x88\x21\x13\x3f\x88\x21\x31\x6d\x88\x21\xf6\x6f\x88\x21\xe4\x70\x88\x21\xec\x55\x88\x21\xd4\x4f\x88\x21\x8a\x29\x88\x21\xd3\x4a\x88\x21\x3c\x32\x88\x21\xf6\x32\x88\x21\x16\x34\x88\x21\xcf\x2a\x88\x21\x45\x41\x88\x21\x70\x3e\x88\x21\xd4\x2b\x88\x21\x37\x2d\x88\x21\xb0\x36\x88\x21\x04\x39\x88\x21\x2e\x3a\x88\x21\xe8\x3b\x88\x21\x23\x3d\x88\x21\x76\x21\x88\x21\xc2\x1f\x88\x21\xb9\x47\x88\x21\xfe\x48\x88\x21\xe7\x52\x88\x21\x92\x4c\x88\x21\xf2\x62\x88\x21\x6c\x3f\x88\x21\x3a\x40\x88\x21\x25\x2e\x88\x21\x81\x66\x88\x21\x2b\x67\x88\x21\xd3\x69\x88\x21\x41\x22\x88\x21\x31\x08\x88\x21", .type = jumpTable_t::CallDwords, .elements = sequence("0-47"), .selector = "memoryAGet32(ds, di + 17927)", .useCaseOffset = true }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xd8d8), .baseptr = (const uint8_t*)"\x50\x28\x88\x21\x77\x28\x88\x21\x58\x64\x88\x21\xbe\x5b\x88\x21\x83\x2f\x88\x21\xb9\x1f\x88\x21\x55\x58\x88\x21\x8f\x5c\x88\x21\x32\x62\x88\x21\x4b\x4a\x88\x21\x82\x4a\x88\x21\xfa\x6a\x88\x21\x13\x3f\x88\x21\x31\x6d\x88\x21\xf6\x6f\x88\x21\xe4\x70\x88\x21\xec\x55\x88\x21\xd4\x4f\x88\x21\x8a\x29\x88\x21\xd3\x4a\x88\x21\x3c\x32\x88\x21\xf6\x32\x88\x21\x16\x34\x88\x21\xcf\x2a\x88\x21\x45\x41\x88\x21\x70\x3e\x88\x21\xd4\x2b\x88\x21\x37\x2d\x88\x21\xb0\x36\x88\x21\x04\x39\x88\x21\x2e\x3a\x88\x21\xe8\x3b\x88\x21\x23\x3d\x88\x21\x76\x21\x88\x21\xc2\x1f\x88\x21\xb9\x47\x88\x21\xfe\x48\x88\x21\xe7\x52\x88\x21\x92\x4c\x88\x21\xf2\x62\x88\x21\x6c\x3f\x88\x21\x3a\x40\x88\x21\x25\x2e\x88\x21\x81\x66\x88\x21\x2b\x67\x88\x21\xd3\x69\x88\x21\x41\x22\x88\x21\x31\x08\x88\x21", .type = jumpTable_t::CallDwords, .elements = sequence("0-47"), .selector = "memoryAGet32(ds, di + 17927)", .useCaseOffset = true }),
            
            //\xb9\x1f\x88\x21\x50\x28\x88\x21\x77\x28\x88\x21\x23\x3d\x88\x21\x13\x3f\x88\x21\xfa\x6a\x88\x21\x31\x6d\x88\x21\xf6\x6f\x88\x21\xe4\x70\x88\x21
            
            
            
            //    push(cs); cs = memoryAGet16(ds, di + 17927 + 2); callIndirect(cs, memoryAGet16(ds, di + 17927)); assert(cs == 0x01ed); // 01ed:d8d8;   2ec1:4607 - 2188:3f13
            
            //                di=10e, 2188:70e4 sub_218870e4()
            //    push(cs); cs = memoryAGet16(ds, di + 17927 + 2); callIndirect(cs, memoryAGet16(ds, di + 17927)); assert(cs == 0x01ed); // 01ed:d87c;  // 2188:6ff6   ds=2ec1, di=225   01ed:d87c
            
        },
        .procList = {{0x1f5c, 0x10d7}, {0x01ed, 0x0727}, {0x2d99, 0x0045}}, // label as function
    //            .marks = {{0x2aa3, 0x17e8}},
    
    //        2da3:0caa - 2da3:0cb7
    //        .verbose = true, .relocations = false, .verbose = true, .recursive = false, .procList = {{0x28b3, 0x02ef}},
    //            .verboseAsm = true
};


Options optionsCK1 = {
    .loader = "LoaderMz",
    .exec = "KEEN1.EXE",
    .arch = arch_t::arch16,
    .loadAddress = 0x01ed0,
    //   .terminators = {{0x01ed, 0xfb8a}},
    .procModifiersStack = {
        {{0x01ed, 0xc5fa}, 4}, // sub_e4ca ret
        {{0x01ed, 0xc7dc}, 2}, // sub_e6ac ret
        {{0x01ed, 0xca7c}, 6}, // sub_e94c ret
        {{0x01ed, 0xd296}, 2}, // sub_f166 ret
        {{0x01ed, 0xd30d}, 12}, // sub_f1dd ret
        {{0x01ed, 0xd473}, 4}, // sub_f343 ret
        {{0x01ed, 0xd48c}, 2}, // sub_f35c ret
        {{0x01ed, 0xd7a9}, 8}, // sub_f679 ret
        {{0x01ed, 0xe0a3}, 10}, // sub_ff73 retf
        {{0x01ed, 0xe0b2}, 8}, // sub_ff82 retf
        {{0x01ed, 0xe29b}, 8}, // sub_1016b retf
        
    },
        .jumpTables = {
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x0210), .table = {0x14f0, 0x0002}, .type = jumpTable_t::CallWords, .elements = {0, 3, 0x0c/2}, .selector = "memoryAGet16(es, bx + 2)", .useCaseOffset = true }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xc19a), .baseptr = (const uint8_t*)"\xaf\xc1", .type = jumpTable_t::CallWords, .elements = sequence("0-0"), .selector = "ax", .useCaseOffset = true }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x162f), .table = {0x01ed, 5897}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
            //indirectJump(cs, memoryAGet16(cs, bx + 5897)); // 01ed:162f;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x5a60), .table = {0x01ed, 23349}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 23349)); // 01ed:5a60;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x5650), .table = {0x01ed, 22217}, .type = jumpTable_t::JumpWords, .elements = sequence("0-8"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 22217)); // 01ed:5650;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xb82d), .baseptr = (const uint8_t*)"\xd4\xa1\xeb\xa1\x97\xa4\xfd\x95\xab\x97\xf0\x97\x6c\x98\x6d\x9e", .type = jumpTable_t::CallWords, .elements = sequence("0-7"), .selector = "cx", .useCaseOffset = true }),
            
            //callIndirect(cs, cx); // 01ed:b82d; 01ed:a1d4 : a1d4, a1eb, a479 (a497)
            // 95fd, 97ab, 97f0, 986c, 9e6d
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x9680), .table = {0x01ed, 38568}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
            
            //        indirectJump(cs, memoryAGet16(cs, bx + 38568)); // 01ed:9680;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x956b), .table = {0x01ed, 38381}, .type = jumpTable_t::JumpWords, .elements = sequence("0-7"), .selector = "bx"}),
            //callIndirect(cs, memoryAGet16(ss, 0x5016)); // 01ed:bba4; //14f2:20484 0-4
            
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xbba4), .table = {0x14f2, 20484}, .type = jumpTable_t::CallWords, .elements = sequence("0-4"), .selector = "bx"}),
            
            //callIndirect(cs, memoryAGet16(ss, 0x5016)); // 01ed:bbce;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xbbce), .table = {0x14f2, 20484}, .type = jumpTable_t::CallWords, .elements = sequence("0-4"), .selector = "bx"}),
            //callIndirect(cs, memoryAGet16(ss, 0x5016)); // 01ed:bbf8;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xbbf8), .table = {0x14f2, 20484}, .type = jumpTable_t::CallWords, .elements = sequence("0-4"), .selector = "bx"}),
            //    callIndirect(cs, memoryAGet16(ss, 0x5016)); // 01ed:bc22;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xbc22), .table = {0x14f2, 20484}, .type = jumpTable_t::CallWords, .elements = sequence("0-4"), .selector = "bx"}),
            //indirectJump(cs, memoryAGet16(cs, bx + 44556)); // 01ed:ab73;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xab73), .table = {0x01ed, 44556}, .type = jumpTable_t::JumpWords, .elements = sequence("0-7"), .selector = "bx"}),
            //callIndirect(cs, memoryAGet16(ds, 0x8252)); // 01ed:4d26; 3867, 194f, 3c99
            //19d3, 3867, 3b8b, 3c99, 3e12, 3ec8, 4054,41f8, 0x194f   // 0x1a2c
            // 3867, 40ef, 41f8
            // \xd3\x19\x67\x38\x8b\x3b\x99\x3c\x12\x3e\xc8\x3e\x54\x40\xf8\x41
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x4d26), .baseptr = (const uint8_t*)"\xd3\x19\x67\x38\x8b\x3b\x99\x3c\x12\x3e\xc8\x3e\x54\x40\xf8\x41\x4f\x19\x2c\x1a\x67\x38\xef\x40\xf8\x41", .type = jumpTable_t::CallWords, .elements = sequence("0-12"), .selector = "memoryAGet16(ds, 0x8252)", .useCaseOffset = true }),
            //callIndirect(cs, memoryAGet16(ds, 0x8252)); // 01ed:4db7;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x4db7), .baseptr = (const uint8_t*)"\xd3\x19\x67\x38\x8b\x3b\x99\x3c\x12\x3e\xc8\x3e\x54\x40\xf8\x41\x4f\x19\x2c\x1a\x67\x38\xef\x40\xf8\x41", .type = jumpTable_t::CallWords, .elements = sequence("0-12"), .selector = "memoryAGet16(ds, 0x8252)", .useCaseOffset = true }),
            //        indirectJump(cs, memoryAGet16(cs, bx + 15229)); // 01ed:3926; 0-6
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x3926), .table = {0x01ed, 15229}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 15876)); // 01ed:3ca9; 0-6
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x3ca9), .table = {0x01ed, 15876}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 17808)); // 01ed:4382; 0-0x19
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x4382), .table = {0x01ed, 17808}, .type = jumpTable_t::JumpWords, .elements = sequence("0-25"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 23079)); // 01ed:597a; 0-8
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x597a), .table = {0x01ed, 23079}, .type = jumpTable_t::JumpWords, .elements = sequence("0-8"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 56381)); // 01ed:d871; 0..0x17
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0xd871), .table = {0x01ed, 56381}, .type = jumpTable_t::JumpWords, .elements = sequence("0-10"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 15499)); // 01ed:3bd9; 0..6
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x3bd9), .table = {0x01ed, 15499}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
            //    callIndirect(cs, memoryAGet16(ds, si + 52)); // 01ed:4e3c; 1a68, 1bce, 1d6e, 1e94, 22bb, 2927, 4849, 3360 45c4
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x4e3c), .baseptr = (const uint8_t*)"\x68\x1a\xce\x1b\x6e\x1d\x94\x1e\xbb\x22\x27\x29\x49\x48\x60\x33\xc4\x45", .type = jumpTable_t::CallWords, .elements = sequence("0-8"), .selector = "memoryAGet16(ds, si + 52)", .useCaseOffset = true }), //
            //        callIndirect(cs, memoryAGet16(ds, di + 52)); // 01ed:4e44;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x4e44), .baseptr = (const uint8_t*)"\x68\x1a\xce\x1b\x6e\x1d\x94\x1e\xbb\x22\x27\x29\x49\x48\x60\x33\xc4\x45", .type = jumpTable_t::CallWords, .elements = sequence("0-8"), .selector = "memoryAGet16(ds, si + 52)", .useCaseOffset = true }),
            //indirectJump(cs, memoryAGet16(cs, bx + 18078)); // 01ed:45dd; 0..13
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x45dd), .table = {0x01ed, 18078}, .type = jumpTable_t::JumpWords, .elements = sequence("0-13"), .selector = "bx"}),
            
        },
        .procList = {{0x01ed,0x015c},{0x01ed,0xbf97},{0x01ed,0xbe1a},{0x01ed,0xd1bd}}
    
    //    indirect bx=0 tab=14f0:2 target=1ed:cbed sub_eabd()
    //    indirect bx=c tab=14f0:2 target=1ed:e5a1 sub_10471()
    
    //01ed:0210; 14f0:2
};
Options optionsCK4 = {
    .loader = "LoaderMz",
    .exec = "KEEN4.EXE",
    .arch = arch_t::arch16,
    .loadAddress = 0x01ed0,
    .procModifiersStack = {
        {{0x01ed, 0x01ae}, 2}, // sub_207e retf
        {{0x01ed, 0x0226}, 2}, // sub_20f6 retf
        {{0x01ed, 0x026d}, 2}, // sub_213d retf
        {{0x01ed, 0x029a}, 6}, // sub_216a ret
        {{0x01ed, 0x03e3}, 2}, // sub_22b3 retf
        {{0x01ed, 0x03fc}, 2}, // sub_22cc ret
        {{0x01ed, 0x04b5}, 6}, // sub_2385 ret
        {{0x01ed, 0x059d}, 2}, // sub_246d retf
        {{0x01ed, 0x05bb}, 2}, // sub_248b retf
        {{0x01ed, 0x05e0}, 4}, // sub_24b0 ret
        {{0x01ed, 0x070c}, 2}, // sub_25dc retf
        {{0x01ed, 0x075e}, 2}, // sub_262e retf
        {{0x01ed, 0x07e0}, 2}, // sub_26b0 retf
        {{0x01ed, 0x0a42}, 2}, // sub_2912 ret
        {{0x01ed, 0x0ab1}, 2}, // sub_2981 retf
        {{0x01ed, 0x0b5c}, 2}, // sub_2a2c retf
        {{0x01ed, 0x0c43}, 2}, // sub_2b13 retf
        {{0x01ed, 0x0d23}, 2}, // sub_2bf3 retf
        {{0x01ed, 0x0d3c}, 2}, // sub_2c0c retf
        {{0x01ed, 0x0e55}, 6}, // sub_2d25 ret
        {{0x01ed, 0x0fa3}, 2}, // sub_2e73 retf
        {{0x01ed, 0x101d}, 4}, // sub_2eed ret
        {{0x01ed, 0x1056}, 4}, // sub_2f26 ret
        {{0x01ed, 0x1084}, 10}, // sub_2f54 ret
        {{0x01ed, 0x114a}, 10}, // sub_301a ret
        {{0x01ed, 0x1188}, 8}, // sub_3058 ret
        {{0x01ed, 0x11cb}, 6}, // sub_309b ret
        {{0x01ed, 0x11ee}, 12}, // sub_30be ret
        {{0x01ed, 0x1314}, 2}, // sub_31e4 retf
        {{0x01ed, 0x13ec}, 2}, // sub_32bc retf
        {{0x01ed, 0x142f}, 2}, // sub_32ff retf
        {{0x01ed, 0x145b}, 2}, // sub_332b retf
        {{0x01ed, 0x14b3}, 2}, // sub_3383 retf
        {{0x01ed, 0x15cf}, 2}, // sub_349f retf
        {{0x01ed, 0x165c}, 2}, // sub_352c retf
        {{0x01ed, 0x1706}, 2}, // sub_35d6 retf
        {{0x01ed, 0x1719}, 2}, // sub_35e9 retf
        {{0x01ed, 0x1734}, 2}, // sub_3604 retf
        {{0x01ed, 0x1752}, 2}, // sub_3622 retf
        {{0x01ed, 0x1915}, 2}, // sub_37e5 retf
        {{0x01ed, 0x1975}, 2}, // sub_3845 retf
        {{0x01ed, 0x19b6}, 2}, // sub_3886 retf
        {{0x01ed, 0x1a12}, 2}, // sub_38e2 retf
        {{0x01ed, 0x1a2d}, 2}, // sub_38fd retf
        {{0x01ed, 0x1a8b}, 2}, // sub_395b retf
        {{0x01ed, 0x1a9a}, 2}, // sub_396a retf
        {{0x01ed, 0x1ae3}, 2}, // sub_39b3 retf
        {{0x01ed, 0x1b54}, 2}, // sub_3a24 retf
        {{0x01ed, 0x1b7b}, 2}, // sub_3a4b ret
        {{0x01ed, 0x1bb8}, 2}, // sub_3a88 retf
        {{0x01ed, 0x1bc9}, 2}, // sub_3a99 retf
        {{0x01ed, 0x1bf2}, 12}, // sub_3ac2 ret
        {{0x01ed, 0x1c6f}, 2}, // sub_3b3f retf
        {{0x01ed, 0x1c9b}, 2}, // sub_3b6b retf
        {{0x01ed, 0x1cb5}, 2}, // sub_3b85 retf
        {{0x01ed, 0x1cdc}, 2}, // sub_3bac retf
        {{0x01ed, 0x1cfd}, 2}, // sub_3bcd retf
        {{0x01ed, 0x1d25}, 2}, // sub_3bf5 retf
        {{0x01ed, 0x1d40}, 2}, // sub_3c10 retf
        {{0x01ed, 0x1d62}, 4}, // sub_3c32 ret
        {{0x01ed, 0x1d7b}, 2}, // sub_3c4b ret
        {{0x01ed, 0x1d8d}, 2}, // sub_3c5d retf
        {{0x01ed, 0x1ec4}, 2}, // sub_3d94 retf
        {{0x01ed, 0x1f10}, 2}, // sub_3de0 retf
        {{0x01ed, 0x1fcb}, 2}, // sub_3e9b retf
        {{0x01ed, 0x1ffb}, 2}, // sub_3ecb retf
        {{0x01ed, 0x201a}, 4}, // sub_3eea ret
        {{0x01ed, 0x2040}, 12}, // sub_3f10 ret
        {{0x01ed, 0x20f1}, 4}, // sub_3fc1 ret
        {{0x01ed, 0x2265}, 2}, // sub_4135 retf
        {{0x01ed, 0x2281}, 2}, // sub_4151 retf
        {{0x01ed, 0x22ba}, 2}, // sub_418a retf
        {{0x01ed, 0x22e9}, 2}, // sub_41b9 retf
        {{0x01ed, 0x230d}, 2}, // sub_41dd retf
        {{0x01ed, 0x2327}, 2}, // sub_41f7 retf
        {{0x01ed, 0x2353}, 2}, // sub_4223 retf
        {{0x01ed, 0x2840}, 4}, // sub_4710 ret
        {{0x01ed, 0x2866}, 10}, // sub_4736 ret
        {{0x01ed, 0x28df}, 2}, // sub_47af retf
        {{0x01ed, 0x2ddd}, 2}, // sub_4cad retf
        {{0x01ed, 0x2ec3}, 2}, // sub_4d93 retf
        {{0x01ed, 0x308a}, 2}, // sub_4f5a retf
        {{0x01ed, 0x30c5}, 10}, // sub_4f95 retf
        {{0x01ed, 0x3173}, 2}, // sub_5043 retf
        {{0x01ed, 0x31b4}, 2}, // sub_5084 retf
        {{0x01ed, 0x31d5}, 2}, // sub_50a5 retf
        {{0x01ed, 0x3219}, 2}, // sub_50e9 retf
        {{0x01ed, 0x325a}, 2}, // sub_512a retf
        {{0x01ed, 0x325d}, 2}, // sub_512d retf
        {{0x01ed, 0x32ba}, 2}, // sub_518a retf
        {{0x01ed, 0x32e5}, 10}, // sub_51b5 retf
        {{0x01ed, 0x3307}, 2}, // sub_51d7 retf
        {{0x01ed, 0x3328}, 2}, // sub_51f8 retf
        {{0x01ed, 0x33f7}, 2}, // sub_52c7 retf
        {{0x01ed, 0x374c}, 2}, // sub_561c retf
        {{0x01ed, 0x37b3}, 2}, // sub_5683 retf
        {{0x056a, 0x000c}, 2}, // sub_56ac retf
        {{0x056a, 0x007f}, 2}, // sub_571f retf
        {{0x056a, 0x00a7}, 2}, // sub_5747 retf
        {{0x056a, 0x022f}, 2}, // sub_58cf retf
        {{0x056a, 0x0329}, 2}, // sub_59c9 retf
        {{0x056a, 0x0349}, 2}, // sub_59e9 retf
        {{0x056a, 0x04f7}, 2}, // sub_5b97 retf
        {{0x056a, 0x06ab}, 2}, // sub_5d4b retf
        {{0x05da, 0x000b}, 2}, // sub_5dab retf
        {{0x05da, 0x19ca}, 2}, // sub_776a retf
        {{0x05da, 0x1a31}, 2}, // sub_77d1 retf
        {{0x05da, 0x1b13}, 2}, // sub_78b3 retf
        {{0x05da, 0x1bfe}, 2}, // sub_799e retf
        {{0x05da, 0x1d55}, 2}, // sub_7af5 retf
        {{0x07b1, 0x0063}, 2}, // sub_7b73 retf
        {{0x07b1, 0x0093}, 2}, // sub_7ba3 retf
        {{0x07b1, 0x0484}, 2}, // sub_7f94 retf
        {{0x07b1, 0x0541}, 2}, // sub_8051 retf
        {{0x07b1, 0x0591}, 2}, // sub_80a1 retf
        {{0x07b1, 0x0860}, 2}, // sub_8370 retf
        {{0x07b1, 0x08f4}, 2}, // sub_8404 retf
        {{0x07b1, 0x0d81}, 2}, // sub_8891 retf
        {{0x08aa, 0x000b}, 2}, // sub_8aab retf
        {{0x08aa, 0x008f}, 2}, // sub_8b2f retf
        {{0x08aa, 0x0169}, 2}, // sub_8c09 retf
        {{0x08aa, 0x04ee}, 2}, // sub_8f8e retf
        {{0x08aa, 0x0611}, 2}, // sub_90b1 retf
        {{0x08aa, 0x0673}, 2}, // sub_9113 retf
        {{0x08aa, 0x07dc}, 2}, // sub_927c retf
        {{0x08aa, 0x0c60}, 2}, // sub_9700 retf
        {{0x08aa, 0x0cd5}, 2}, // sub_9775 retf
        {{0x08aa, 0x0fa2}, 2}, // sub_9a42 retf
        {{0x08aa, 0x1021}, 2}, // sub_9ac1 retf
        {{0x08aa, 0x16f1}, 2}, // sub_a191 retf
        {{0x08aa, 0x18a5}, 2}, // sub_a345 retf
        {{0x08aa, 0x1983}, 2}, // sub_a423 retf
        {{0x08aa, 0x1acd}, 2}, // sub_a56d retf
        {{0x08aa, 0x1d9e}, 2}, // sub_a83e retf
        {{0x08aa, 0x1e11}, 2}, // sub_a8b1 retf
        {{0x08aa, 0x1e8b}, 2}, // sub_a92b retf
        {{0x08aa, 0x1ef2}, 2}, // sub_a992 retf
        {{0x08aa, 0x1f47}, 2}, // sub_a9e7 retf
        {{0x08aa, 0x2092}, 2}, // sub_ab32 retf
        {{0x08aa, 0x20c7}, 2}, // sub_ab67 retf
        {{0x08aa, 0x21c6}, 2}, // sub_ac66 retf
        {{0x0b02, 0x000a}, 2}, // sub_b02a retf
        {{0x0b02, 0x001d}, 2}, // sub_b03d retf
        {{0x0b02, 0x0083}, 2}, // sub_b0a3 retf
        {{0x0b02, 0x00a1}, 2}, // sub_b0c1 retf
        {{0x0b02, 0x0128}, 2}, // sub_b148 retf
        {{0x0b02, 0x0357}, 2}, // sub_b377 retf
        {{0x0b02, 0x03bc}, 2}, // sub_b3dc retf
        {{0x0b02, 0x03de}, 2}, // sub_b3fe retf
        {{0x0b02, 0x0492}, 2}, // sub_b4b2 retf
        {{0x0b02, 0x06a1}, 2}, // sub_b6c1 retf
        {{0x0b02, 0x079c}, 2}, // sub_b7bc retf
        {{0x0b02, 0x09a5}, 2}, // sub_b9c5 retf
        {{0x0bc9, 0x0005}, 2}, // sub_bc95 retf
        {{0x0bc9, 0x002d}, 2}, // sub_bcbd retf
        {{0x0bc9, 0x0055}, 2}, // sub_bce5 retf
        {{0x0bc9, 0x019f}, 2}, // sub_be2f retf
        {{0x0bc9, 0x02da}, 2}, // sub_bf6a retf
        {{0x0bc9, 0x0469}, 2}, // sub_c0f9 retf
        {{0x0bc9, 0x0558}, 2}, // sub_c1e8 retf
        {{0x0bc9, 0x06a5}, 2}, // sub_c335 retf
        {{0x0bc9, 0x0936}, 2}, // sub_c5c6 retf
        {{0x0bc9, 0x0b49}, 2}, // sub_c7d9 retf
        {{0x0bc9, 0x0eee}, 2}, // sub_cb7e retf
        {{0x0bc9, 0x1097}, 2}, // sub_cd27 retf
        {{0x0bc9, 0x118c}, 2}, // sub_ce1c retf
        {{0x0bc9, 0x120a}, 2}, // sub_ce9a retf
        {{0x0d6d, 0x13e9}, 2}, // sub_eab9 retf
        {{0x0d6d, 0x16cd}, 2}, // sub_ed9d retf
        {{0x0d6d, 0x18e9}, 2}, // sub_efb9 retf
        {{0x0f7c, 0x0078}, 2}, // sub_f838 retf
        {{0x0f7c, 0x00cb}, 2}, // sub_f88b retf
        {{0x0f7c, 0x014f}, 2}, // sub_f90f retf
        {{0x0f7c, 0x04b8}, 2}, // sub_fc78 retf
        {{0x0f7c, 0x08a9}, 2}, // sub_10069 retf
        {{0x0f7c, 0x09fd}, 2}, // sub_101bd retf
        {{0x0f7c, 0x0a5b}, 2}, // sub_1021b retf
        {{0x107c, 0x0003}, 2}, // sub_107c3 retf
        {{0x107c, 0x0a66}, 2}, // sub_11226 retf
        {{0x1493, 0x000f}, 2}, // sub_1493f retf
        {{0x1493, 0x0094}, 2}, // sub_149c4 retf
        {{0x1493, 0x00f4}, 2}, // sub_14a24 retf
        {{0x1493, 0x0140}, 2}, // sub_14a70 retf
        {{0x1493, 0x0283}, 2}, // sub_14bb3 retf
        {{0x1493, 0x02cc}, 2}, // sub_14bfc retf
        {{0x1493, 0x03f5}, 2}, // sub_14d25 retf
        {{0x1493, 0x0685}, 2}, // sub_14fb5 retf
        {{0x1493, 0x0741}, 2}, // sub_15071 retf
        {{0x1493, 0x08dd}, 2}, // sub_1520d retf
        {{0x1493, 0x0910}, 2}, // sub_15240 retf
        {{0x1493, 0x0954}, 2}, // sub_15284 retf
        {{0x1493, 0x0999}, 2}, // sub_152c9 retf
        {{0x1493, 0x09c2}, 2}, // sub_152f2 retf
        {{0x1493, 0x0b28}, 2}, // sub_15458 retf
        {{0x1493, 0x0bae}, 2}, // sub_154de retf
        {{0x1493, 0x0c29}, 2}, // sub_15559 retf
        {{0x1493, 0x0f05}, 2}, // sub_15835 retf
        {{0x1493, 0x1117}, 2}, // sub_15a47 retf
        {{0x1493, 0x1260}, 2}, // sub_15b90 retf
        {{0x1493, 0x14cd}, 2}, // sub_15dfd retf
        {{0x1493, 0x14ed}, 2}, // sub_15e1d retf
        {{0x1493, 0x151a}, 2}, // sub_15e4a retf
        {{0x1493, 0x1562}, 2}, // sub_15e92 retf
        {{0x1493, 0x1593}, 2}, // sub_15ec3 retf
        {{0x1493, 0x161f}, 2}, // sub_15f4f retf
        {{0x1493, 0x184b}, 2}, // sub_1617b retf
        {{0x164d, 0x01d0}, 2}, // sub_166a0 retf
        {{0x164d, 0x01e8}, 2}, // sub_166b8 retf
        {{0x164d, 0x01fd}, 2}, // sub_166cd retf
        {{0x164d, 0x0298}, 2}, // sub_16768 retf
        {{0x164d, 0x043f}, 2}, // sub_1690f retf
        {{0x164d, 0x0478}, 2}, // sub_16948 retf
        {{0x164d, 0x04cb}, 2}, // sub_1699b retf
        {{0x164d, 0x0508}, 2}, // sub_169d8 retf
        {{0x164d, 0x0536}, 2}, // sub_16a06 retf
        {{0x164d, 0x055b}, 2}, // sub_16a2b retf
        {{0x164d, 0x0560}, 2}, // sub_16a30 retf
        {{0x164d, 0x05d7}, 2}, // sub_16aa7 retf
        {{0x164d, 0x0662}, 2}, // sub_16b32 retf
        {{0x164d, 0x06bf}, 2}, // sub_16b8f retf
        {{0x164d, 0x0794}, 2}, // sub_16c64 retf
        {{0x164d, 0x0826}, 2}, // sub_16cf6 retf
        {{0x164d, 0x0868}, 2}, // sub_16d38 retf
        {{0x164d, 0x08a8}, 2}, // sub_16d78 retf
        {{0x164d, 0x08cb}, 2}, // sub_16d9b retf
        {{0x164d, 0x08f9}, 2}, // sub_16dc9 retf
        {{0x164d, 0x09be}, 2}, // sub_16e8e retf
        {{0x164d, 0x0d28}, 2}, // sub_171f8 retf
        {{0x164d, 0x0d39}, 2}, // sub_17209 retf
        {{0x164d, 0x0d81}, 2}, // sub_17251 retf
        {{0x164d, 0x0da1}, 2}, // sub_17271 retf
        {{0x164d, 0x0dbf}, 2}, // sub_1728f retf
        {{0x164d, 0x0e1f}, 2}, // sub_172ef retf
        {{0x164d, 0x0e5a}, 2}, // sub_1732a retf
        {{0x164d, 0x0edf}, 2}, // sub_173af retf
        {{0x164d, 0x0f43}, 2}, // sub_17413 retf
        {{0x164d, 0x0f92}, 2}, // sub_17462 retf
        {{0x174b, 0x0001}, 2}, // sub_174b1 retf
        {{0x174b, 0x0037}, 2}, // sub_174e7 retf
        {{0x174b, 0x00e5}, 2}, // sub_17595 retf
        {{0x174b, 0x0109}, 2}, // sub_175b9 retf
        {{0x174b, 0x0181}, 2}, // sub_17631 retf
        {{0x174b, 0x019c}, 2}, // sub_1764c retf
        {{0x174b, 0x020b}, 2}, // sub_176bb retf
        {{0x174b, 0x0236}, 2}, // sub_176e6 retf
        {{0x174b, 0x03c5}, 2}, // sub_17875 retf
        {{0x174b, 0x042b}, 2}, // sub_178db retf
        {{0x174b, 0x06e2}, 2}, // sub_17b92 retf
        {{0x174b, 0x0712}, 2}, // sub_17bc2 retf
        {{0x174b, 0x0987}, 2}, // sub_17e37 retf
        {{0x174b, 0x0a52}, 2}, // sub_17f02 retf
        {{0x174b, 0x0ad5}, 2}, // sub_17f85 retf
        {{0x174b, 0x0b5d}, 2}, // sub_1800d retf
        {{0x174b, 0x0d3d}, 2}, // sub_181ed retf
        {{0x174b, 0x0e7f}, 2}, // sub_1832f retf
        {{0x174b, 0x0ee6}, 2}, // sub_18396 retf
        {{0x174b, 0x0f64}, 2}, // sub_18414 retf
        {{0x1841, 0x000f}, 2}, // sub_1841f retf
        {{0x1841, 0x0134}, 2}, // sub_18544 retf
        {{0x1841, 0x0139}, 2}, // sub_18549 retf
        {{0x1841, 0x01c2}, 2}, // sub_185d2 retf
        {{0x1841, 0x0318}, 2}, // sub_18728 retf
        {{0x1841, 0x06e2}, 2}, // sub_18af2 retf
        {{0x1841, 0x071a}, 2}, // sub_18b2a retf
        {{0x1841, 0x0868}, 2}, // sub_18c78 retf
        {{0x1841, 0x08ab}, 2}, // sub_18cbb retf
        {{0x1841, 0x0946}, 2}, // sub_18d56 retf
        {{0x1841, 0x0a31}, 2}, // sub_18e41 retf
        {{0x1841, 0x0a78}, 2}, // sub_18e88 retf
        {{0x1841, 0x0afb}, 2}, // sub_18f0b retf
        {{0x1841, 0x0b08}, 2}, // sub_18f18 retf
        {{0x1841, 0x0b61}, 2}, // sub_18f71 retf
        {{0x1841, 0x0c50}, 2}, // sub_19060 retf
        {{0x1841, 0x0c62}, 2}, // sub_19072 retf
        {{0x1841, 0x0d59}, 2}, // sub_19169 retf
        {{0x1841, 0x1025}, 2}, // sub_19435 retf
        {{0x1841, 0x1220}, 2}, // sub_19630 retf
        {{0x1841, 0x12ec}, 2}, // sub_196fc retf
        {{0x1841, 0x1333}, 2}, // sub_19743 retf
        {{0x1841, 0x13dd}, 2}, // sub_197ed retf
        {{0x1841, 0x1641}, 2}, // sub_19a51 retf
        {{0x1841, 0x185b}, 2}, // sub_19c6b retf
        {{0x1841, 0x18e3}, 2}, // sub_19cf3 retf
        {{0x1841, 0x1a6e}, 2}, // sub_19e7e retf
        {{0x1841, 0x1c6e}, 2}, // sub_1a07e retf
        {{0x1a13, 0x000c}, 2}, // sub_1a13c retf
        {{0x1a13, 0x01ea}, 2}, // sub_1a31a retf
        {{0x1a13, 0x0344}, 2}, // sub_1a474 retf
        {{0x1a61, 0x000e}, 2}, // sub_1a61e retf
        {{0x1a61, 0x0033}, 2}, // sub_1a643 retf
        {{0x1a61, 0x007b}, 2}, // sub_1a68b retf
        {{0x1a61, 0x00a9}, 2}, // sub_1a6b9 retf
        {{0x1a61, 0x0144}, 2}, // sub_1a754 retf
        {{0x1a61, 0x015e}, 2}, // sub_1a76e retf
        {{0x1a61, 0x01a0}, 2}, // sub_1a7b0 retf
        {{0x1a61, 0x01c1}, 2}, // sub_1a7d1 retf
        {{0x1a61, 0x02d7}, 2}, // sub_1a8e7 retf
        {{0x1a61, 0x0491}, 2}, // sub_1aaa1 retf
        {{0x1a61, 0x04cb}, 2}, // sub_1aadb retf
        {{0x1a61, 0x0504}, 2}, // sub_1ab14 retf
        {{0x1a61, 0x0529}, 2}, // sub_1ab39 retf
        {{0x1a61, 0x06d7}, 2}, // sub_1ace7 retf
        {{0x1a61, 0x06fb}, 2}, // sub_1ad0b retf
        {{0x1a61, 0x0712}, 2}, // sub_1ad22 retf
        {{0x1a61, 0x072d}, 2}, // sub_1ad3d retf
        {{0x1a61, 0x074b}, 2}, // sub_1ad5b retf
        {{0x1a61, 0x07d0}, 2}, // sub_1ade0 retf
        {{0x1a61, 0x0826}, 2}, // sub_1ae36 retf
        {{0x1a61, 0x0913}, 2}, // sub_1af23 retf
        {{0x1a61, 0x099f}, 2}, // sub_1afaf retf
        {{0x1a61, 0x09f1}, 2}, // sub_1b001 retf
        {{0x1a61, 0x0a90}, 2}, // sub_1b0a0 retf
        {{0x1a61, 0x0ad7}, 2}, // sub_1b0e7 retf
        {{0x1a61, 0x0afd}, 2}, // sub_1b10d retf
        {{0x1a61, 0x0b0a}, 2}, // sub_1b11a retf
        {{0x1a61, 0x0b15}, 2}, // sub_1b125 retf
        {{0x1a61, 0x0b62}, 2}, // sub_1b172 retf
        {{0x1a61, 0x0bb4}, 2}, // sub_1b1c4 retf
        {{0x1a61, 0x0bc7}, 2}, // sub_1b1d7 retf
        {{0x1b1e, 0x0144}, 2}, // sub_1b324 retf
        {{0x1b1e, 0x0154}, 2}, // sub_1b334 retf
        {{0x1b1e, 0x0180}, 2}, // sub_1b360 retf
        {{0x1b1e, 0x0348}, 2}, // sub_1b528 retf
        {{0x1b1e, 0x0490}, 2}, // sub_1b670 retf
        {{0x1b1e, 0x0547}, 2}, // sub_1b727 retf
        {{0x1b1e, 0x05c1}, 2}, // sub_1b7a1 retf
        {{0x1b1e, 0x05e2}, 2}, // sub_1b7c2 retf
        {{0x1b1e, 0x05ff}, 2}, // sub_1b7df retf
        {{0x1b1e, 0x06b5}, 2}, // sub_1b895 retf
        {{0x1b1e, 0x06fe}, 2}, // sub_1b8de retf
        {{0x1b1e, 0x0783}, 2}, // sub_1b963 retf
        {{0x1b1e, 0x079a}, 2}, // sub_1b97a retf
        {{0x1b1e, 0x081e}, 2}, // sub_1b9fe retf
        {{0x1b1e, 0x08b0}, 2}, // sub_1ba90 retf
        {{0x1b1e, 0x0911}, 2}, // sub_1baf1 retf
        {{0x1b1e, 0x0c3c}, 2}, // sub_1be1c retf
        {{0x1b1e, 0x0cda}, 2}, // sub_1beba retf
        {{0x1b1e, 0x0cf9}, 2}, // sub_1bed9 retf
        {{0x1b1e, 0x0d72}, 2}, // sub_1bf52 retf
        {{0x1b1e, 0x0d9a}, 2}, // sub_1bf7a retf
        {{0x1b1e, 0x0dc2}, 2}, // sub_1bfa2 retf
        {{0x1b1e, 0x0e1f}, 2}, // sub_1bfff retf
        {{0x1b1e, 0x0e60}, 2}, // sub_1c040 retf
        {{0x1b1e, 0x0ebd}, 2}, // sub_1c09d retf
        {{0x1b1e, 0x0f02}, 2}, // sub_1c0e2 retf
        {{0x1b1e, 0x0f2f}, 2}, // sub_1c10f retf
        {{0x1b1e, 0x1070}, 2}, // sub_1c250 retf
        {{0x1b1e, 0x11af}, 2}, // sub_1c38f retf
        {{0x1b1e, 0x1205}, 2}, // sub_1c3e5 retf
        {{0x1c76, 0x0005}, 2}, // sub_1c765 retf
        {{0x1c76, 0x0024}, 2}, // sub_1c784 retf
        {{0x1c76, 0x004b}, 2}, // sub_1c7ab retf
        {{0x1c76, 0x0078}, 2}, // sub_1c7d8 retf
        {{0x1c76, 0x0110}, 2}, // sub_1c870 retf
        {{0x1c76, 0x01a6}, 2}, // sub_1c906 retf
        {{0x1c76, 0x024c}, 2}, // sub_1c9ac retf
        {{0x1c76, 0x035e}, 2}, // sub_1cabe retf
        {{0x1c76, 0x0391}, 2}, // sub_1caf1 retf
        {{0x1c76, 0x0536}, 2}, // sub_1cc96 retf
        {{0x1c76, 0x06e8}, 2}, // sub_1ce48 retf
        {{0x1c76, 0x086b}, 2}, // sub_1cfcb retf
        {{0x1c76, 0x1e9e}, 2}, // sub_1e5fe retf
        {{0x1c76, 0x1ef6}, 2}, // sub_1e656 retf
        {{0x1c76, 0x1f37}, 2}, // sub_1e697 retf
        {{0x1c76, 0x1fda}, 2}, // sub_1e73a retf
        {{0x1c76, 0x2067}, 2}, // sub_1e7c7 retf
        {{0x1c76, 0x20a0}, 2}, // sub_1e800 retf
        {{0x1c76, 0x20ca}, 2}, // sub_1e82a retf
        {{0x1c76, 0x2108}, 2}, // sub_1e868 retf
        {{0x1c76, 0x2153}, 2}, // sub_1e8b3 retf
        {{0x1c76, 0x219f}, 2}, // sub_1e8ff retf
        {{0x1c76, 0x2265}, 2}, // sub_1e9c5 retf
        {{0x1c76, 0x2355}, 2}, // sub_1eab5 retf
        {{0x1c76, 0x2426}, 2}, // sub_1eb86 retf
        {{0x1c76, 0x2480}, 2}, // sub_1ebe0 retf
        {{0x1c76, 0x24db}, 2}, // sub_1ec3b retf
        {{0x1c76, 0x2582}, 2}, // sub_1ece2 retf
        {{0x1eef, 0x0002}, 2}, // sub_1eef2 retf
        {{0x1eef, 0x002a}, 2}, // sub_1ef1a retf
        {{0x1ef3, 0x0005}, 2}, // sub_1ef35 retf
        {{0x1ef3, 0x0090}, 2}, // sub_1efc0 retf
        {{0x1ef3, 0x00ac}, 2}, // sub_1efdc retf
        {{0x1ef3, 0x00e9}, 2}, // sub_1f019 retf
        {{0x1ef3, 0x0152}, 2}, // sub_1f082 retf
        {{0x1ef3, 0x016f}, 2}, // sub_1f09f retf
        {{0x1ef3, 0x02dd}, 2}, // sub_1f20d retf
        {{0x1ef3, 0x030d}, 2}, // sub_1f23d retf
        {{0x1ef3, 0x035c}, 2}, // sub_1f28c retf
        {{0x1ef3, 0x057d}, 2}, // sub_1f4ad retf
        {{0x1ef3, 0x064e}, 2}, // sub_1f57e retf
        {{0x1ef3, 0x074d}, 2}, // sub_1f67d retf
        {{0x1ef3, 0x078d}, 2}, // sub_1f6bd retf
        {{0x1ef3, 0x07d7}, 2}, // sub_1f707 retf
        {{0x1ef3, 0x0829}, 2}, // sub_1f759 retf
        {{0x1ef3, 0x0886}, 2}, // sub_1f7b6 retf
        {{0x1ef3, 0x088f}, 2}, // sub_1f7bf retf
        {{0x1ef3, 0x092b}, 2}, // sub_1f85b retf
        {{0x1ef3, 0x0981}, 2}, // sub_1f8b1 retf
        {{0x1ef3, 0x0999}, 2}, // sub_1f8c9 retf
        {{0x1ef3, 0x09bb}, 2}, // sub_1f8eb retf
        {{0x1ef3, 0x0a9b}, 2}, // sub_1f9cb retf
        {{0x1ef3, 0x0abb}, 2}, // sub_1f9eb retf
        {{0x1ef3, 0x0b0e}, 2}, // sub_1fa3e retf
        {{0x1ef3, 0x0c79}, 2}, // sub_1fba9 retf
        {{0x1ef3, 0x0d29}, 2}, // sub_1fc59 retf
        {{0x1ef3, 0x0de3}, 2}, // sub_1fd13 retf
        {{0x1ef3, 0x0e2c}, 2}, // sub_1fd5c retf
        {{0x1ef3, 0x0e75}, 2}, // sub_1fda5 retf
        {{0x1ef3, 0x0faf}, 2}, // sub_1fedf retf
        {{0x1ef3, 0x0ff8}, 2}, // sub_1ff28 retf
        {{0x1ff7, 0x0000}, 2}, // sub_1ff70 retf
        {{0x1ff7, 0x004f}, 2}, // sub_1ffbf retf
        {{0x1ff7, 0x00af}, 2}, // sub_2001f retf
        {{0x1ff7, 0x0449}, 2}, // sub_203b9 retf
        {{0x1ff7, 0x0495}, 2}, // sub_20405 retf
        {{0x1ff7, 0x059f}, 2}, // sub_2050f retf
        {{0x1ff7, 0x05da}, 2}, // sub_2054a retf
        {{0x1ff7, 0x0759}, 2}, // sub_206c9 retf
        {{0x1ff7, 0x07da}, 2}, // sub_2074a retf
        {{0x1ff7, 0x09b9}, 2}, // sub_20929 retf
        {{0x1ff7, 0x0ad3}, 2}, // sub_20a43 retf
        {{0x1ff7, 0x0b1a}, 2}, // sub_20a8a retf
    },
        .isolateLabels = {address_t(0x01ed, 0x0226)},
        .jumpTables = {
            //callIndirect(cs, memoryAGet16(es, bx + 2)); // 01ed:0216; bx=744c ofs=12a3
            //// es=30d4, bx=745e ofs=36f4 ; // bx=7458, ofs=35e1 // bx=7458 ofs=0x35e1 //181e
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x0216), .baseptr = (const uint8_t*)"\xa3\x12\xf4\x36\xe1\x35\x1e\x18", .type = jumpTable_t::CallWords, .elements = sequence("0-3"), .selector = "memoryAGet16(es, bx + 2)", .useCaseOffset = true }),
            //callIndirect(cs, ax); // 1ff7:0b4b; ax=0b60
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x0b4b), .baseptr = (const uint8_t*)"\x60\x0b", .type = jumpTable_t::CallWords, .elements = sequence("0-0"), .selector = "ax", .useCaseOffset = true }),
            //indirectJump(cs, memoryAGet16(cs, bx + 1257)); // 056a:0443; 0..6
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x056a, 0x0443), .table = {0x056a, 1257}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
            //indirectJump(cs, memoryAGet16(cs, bx + 996)); // 05da:02ed;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x05da, 0x02ed), .table = {0x05da, 996}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
            //    indirectJump(cs, memoryAGet16(ss, di + 24600)); // 1ff7:0507; ss=30d4
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x0507), .table = {0x30d4, 24600}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "di"}),
            //    push(cs); cs = memoryAGet16(ds, 0x7ae8 + 2); callIndirect(cs, memoryAGet16(ds, 0x7ae8)); assert(cs == 0x1493); // 1493:18e7; 7b1:66d, 1439:1650
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1493, 0x18e7), .baseptr = (const uint8_t*)"\x6d\x06\xb1\x07\x50\x16\x39\x14", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x7ae8)", .useCaseOffset = true }),
            //indirectJump(cs, memoryAGet16(ss, 0x6016)); // 1ff7:017e; 1ff7:01ba, 1a0, 1ec, 1d6, 202
            //        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x017e), .baseptr = (const uint8_t*)"\xba\x01\xa0\x01\xec\x01\xd6\x01\x02\x02", .type = jumpTable_t::JumpWords, .elements = sequence("0-4"), .selector = "memoryAGet16(ss, 0x6016)", .useCaseOffset = true }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x017e), .table = {0x30d4, 24554}, .type = jumpTable_t::JumpWords, .elements = sequence("0-21"), .selector = "memoryAGet16(ss, 0x6016)", .useCaseOffset = true }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x017e), .baseptr = (const uint8_t*)"\xa0\x01", .type = jumpTable_t::JumpWords, .elements = sequence("0-0"), .selector = "memoryAGet16(ss, 0x6016)", .useCaseOffset = true }),
            
            //    push(cs); cs = memoryAGet16(ds, 0x43bc + 2); callIndirect(cs, memoryAGet16(ds, 0x43bc)); assert(cs == 0x056a); // 056a:004a; 1ef3:78d
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x056a, 0x004a), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //push(cs); cs = memoryAGet16(ds, 0x43bc + 2); callIndirect(cs, memoryAGet16(ds, 0x43bc)); assert(cs == 0x1b1e); // 1b1e:0e74; 1ef3:078d
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x0e74), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //        push(cs); cs = memoryAGet16(ds, 0x43c0 + 2); callIndirect(cs, memoryAGet16(ds, 0x43c0)); assert(cs == 0x1b1e); // 1b1e:0eaa; // 1ef3:0e2c
            
            //        05da:1bc2
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x05da, 0x1bc2), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //        1b1e:0d27
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x0d27), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //        1b1e:0dd6
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x0dd6), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //        1b1e:11dd
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x11dd), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //        1b1e:1407
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x1407), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //        1c76:054d
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x054d), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //        1c76:0560
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x0560), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //        1c76:0575
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x0575), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x0eaa), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //indirectJump(cs, memoryAGet16(ss, si + 26234)); // 1ff7:08a0;  // 30d4:26234 1ff7:08a5 0,2
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x08a0), .table = {0x30d4, 26234}, .type = jumpTable_t::JumpWords, .elements = sequence("0-2"), .selector = "si"}),
            //    push(cs); cs = memoryAGet16(ds, 0x7ae4 + 2); callIndirect(cs, memoryAGet16(ds, 0x7ae4)); assert(cs == 0x1493); // 1493:1933; // 07b1:07ea
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1493, 0x1933), .baseptr = (const uint8_t*)"\xea\x07\xb1\x07", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x7ae4)", .useCaseOffset = true }),
            //    push(cs); cs = memoryAGet16(ds, 0x7ae0 + 2); callIndirect(cs, memoryAGet16(ds, 0x7ae0)); assert(cs == 0x1493); // 1493:1ba1; // 7b1:85b
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1493, 0x1ba1), .baseptr = (const uint8_t*)"\x5b\x08\xb1\x07", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x7ae0)", .useCaseOffset = true }),
            // push(cs); cs = memoryAGet16(ds, 0x43c0 + 2); callIndirect(cs, memoryAGet16(ds, 0x43c0)); assert(cs == 0x1c76); // 1c76:01c2; // 1ef3:0e2c
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x01c2), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        push(cs); cs = memoryAGet16(ds, 0x43c0 + 2); callIndirect(cs, memoryAGet16(ds, 0x43c0)); assert(cs == 0x1c76); // 1c76:01eb;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x01eb), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //      push(cs); cs = memoryAGet16(ds, 0x43c0 + 2); callIndirect(cs, memoryAGet16(ds, 0x43c0)); assert(cs == 0x1c76); // 1c76:0224;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x0224), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //1b1e:0d3c
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x0d3c), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1b1e:0e13
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x0e13), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1b1e:11f9
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x11f9), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1b1e:147d
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x147d), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1b1e:14a8
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x14a8), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1b1e:1558
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x1558), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1c76:05fb
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x05fb), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1c76:064d
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x064d), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1c76:0673
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x673), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1c76:1952
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x1952), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        1c76:1994
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x1994), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            
            //    push(cs); cs = memoryAGet16(ds, 0x43bc + 2); callIndirect(cs, memoryAGet16(ds, 0x43bc)); assert(cs == 0x1c76); // 1c76:01d6; // 1ef3:078d
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x01d6), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //push(cs); cs = memoryAGet16(ds, 0x43bc + 2); callIndirect(cs, memoryAGet16(ds, 0x43bc)); assert(cs == 0x1c76); // 1c76:01ff;
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x01ff), .baseptr = (const uint8_t*)"\x8d\x07\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43bc)", .useCaseOffset = true }),
            //    push(cs); cs = memoryAGet16(ds, 0x43c0 + 2); callIndirect(cs, memoryAGet16(ds, 0x43c0)); assert(cs == 0x1c76); // 1c76:0198;  // 1ef3:0e2c
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x0198), .baseptr = (const uint8_t*)"\x2c\x0e\xf3\x1e", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0x43c0)", .useCaseOffset = true }),
            //        push(cs); cs = memoryAGet16(es, bx + 12 + 2); callIndirect(cs, memoryAGet16(es, bx + 12)); assert(cs == 0x1c76); // 1c76:213e; 1c76:1e34
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x213e), .baseptr = (const uint8_t*)"\x34\x1e\x76\x1c", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(es, bx + 12)", .useCaseOffset = true }),
            
            //    indirectJump(cs, memoryAGet16(cs, bx + 1429)); // 107c:005f; gg 0..0x57
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x107c, 0x005f), .table = {0x107c, 1429}, .type = jumpTable_t::JumpWords, .elements = sequence("0-87"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 1976)); // 1c76:071b; gg 0..5
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x071b), .table = {0x1c76, 1976}, .type = jumpTable_t::JumpWords, .elements = sequence("0-5"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 2543)); // 0f7c:0985; gg 0..6
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0f7c, 0x0985), .table = {0x0f7c, 2543}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 2841)); // 0b02:0ac8; gg 0..9
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0b02, 0x0ac8), .table = {0x0b02, 2841}, .type = jumpTable_t::JumpWords, .elements = sequence("0-9"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 3358)); // 164d:0a71; gg 0..4
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x164d, 0x0a71), .table = {0x164d, 3358}, .type = jumpTable_t::JumpWords, .elements = sequence("0-4"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 3409)); // 1841:0c77; gg 0..3
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1841, 0x0c77), .table = {0x1841, 3409}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 3969)); // 07b1:0e67; gg 0..12
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x07b1, 0x0e67), .table = {0x07b1, 3969}, .type = jumpTable_t::JumpWords, .elements = sequence("0-12"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 5495)); // 1b1e:12f6; gg 0..6
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x12f6), .table = {0x1b1e, 5495}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 6727)); // 0d6d:196c; gg 0..0x19
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0d6d, 0x196c), .table = {0x0d6d, 6727}, .type = jumpTable_t::JumpWords, .elements = sequence("0-25"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 817)); // 0b02:0154; gg 0..0x12
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0b02, 0x0154), .table = {0x0b02, 817}, .type = jumpTable_t::JumpWords, .elements = sequence("0-18"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 9330)); // 1c76:2434; gg 0..6
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x2434), .table = {0x1c76, 9330}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 959)); // 01ed:02d9; gg 0..6
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x02d9), .table = {0x01ed, 959}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
            
            //        indirectJump(cs, memoryAGet16(cs, bx + 3388)); // 126d:0ce7; gy 0..3
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x126d, 0x0ce7), .table = {0x126d, 3388}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 3454)); // 138f:0d28; gy 0..3
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x138f, 0x0d28), .table = {0x138f, 3454}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
            //        indirectJump(cs, memoryAGet16(cs, bx + 3806)); // 138f:0e7d; gy 0..3
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x138f, 0x0e7d), .table = {0x138f, 3806}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
            
            
            //        push(cs); cs = memoryAGet16(ds, 0xe7fa + 2); callIndirect(cs, memoryAGet16(ds, 0xe7fa)); assert(cs == 0x1c76); // 1c76:250f;  //07b1:0466
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x250f), .baseptr = (const uint8_t*)"\x66\x04\xb1\x07", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0xe7fa)", .useCaseOffset = true }),
            //        push(cs); cs = memoryAGet16(ds, di + 16 + 2); callIndirect(cs, memoryAGet16(ds, di + 16)); assert(cs == 0x0bc9); // 0bc9:0fb0;  // f7c:6af 0f7c06f0
            //        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0bc9, 0x0fb0), .baseptr = (const uint8_t*)"\xaf\x06\x7c\x0f\xf0\x06\x7c\x0f", .type = jumpTable_t::CallDwords, .elements = sequence("0-1"), .selector = "memoryAGet32(ds, di + 16)", .useCaseOffset = true }),
            //        push(cs); cs = memoryAGet16(ds, bx + 24 + 2); callIndirect(cs, memoryAGet16(ds, bx + 24)); assert(cs == 0x08aa); // 08aa:2468; // 0bc9:176e
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x08aa, 0x2468), .baseptr = (const uint8_t*)"\x6e\x17\xc9\x0b", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, bx + 24)", .useCaseOffset = true }),
            //    push(cs); cs = memoryAGet16(ds, 0xdda8 + 2); callIndirect(cs, memoryAGet16(ds, 0xdda8)); assert(cs == 0x1841); // 1841:1cb7; // 07b1:0561
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1841, 0x1cb7), .baseptr = (const uint8_t*)"\x61\x05\xb1\x07", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, 0xdda8)", .useCaseOffset = true }),
            //        push(cs); cs = memoryAGet16(ds, di + 16 + 2); callIndirect(cs, memoryAGet16(ds, di + 16)); assert(cs == 0x0bc9); // 0bc9:106d; // 1195:002e 1195008b 119500b3 119500db 0f7c06af
            
            //        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0bc9, 0x106d), .baseptr = (const uint8_t*)"\x2e\x00\x95\x11\x8b\x00\x95\x11\xb3\x00\x95\x11\xdb\x00\x95\x11\xaf\x06\x7c\x0f", .type = jumpTable_t::CallDwords, .elements = sequence("0-4"), .selector = "memoryAGet32(ds, di + 16)", .useCaseOffset = true }),
            
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0bc9, 0x106d), .fileoffset = 0x33a6c,
                .filestep = 30, .filecount = 300/30, .type = jumpTable_t::CallDwords, .selector = "memoryAGet32(ds, di + 16)", .useCaseOffset = true }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0bc9, 0x106d), .fileoffset = 0x33102,
                .filestep = 30, .filecount = 300/30, .type = jumpTable_t::CallDwords, .selector = "memoryAGet32(ds, di + 16)", .useCaseOffset = true }),
            
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0bc9, 0x0fb0), .fileoffset = 0x33a6c,
                .filestep = 30, .filecount = 300/30, .type = jumpTable_t::CallDwords, .selector = "memoryAGet32(ds, di + 16)", .useCaseOffset = true }),
            std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0bc9, 0x0fb0), .fileoffset = 0x33102,
                .filestep = 30, .filecount = 300/30, .type = jumpTable_t::CallDwords, .selector = "memoryAGet32(ds, di + 16)", .useCaseOffset = true }),
            
            //0x33210+30
            //        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0bc9, 0x106d), .baseptr = (const uint8_t*)"\xaf\x06\x7c\x0f", .type = jumpTable_t::CallDwords, .elements = sequence("0-0"), .selector = "memoryAGet32(ds, di + 16)", .useCaseOffset = true }),
            
            
        },
        .procList = {{0x164d,0x000b},{0x1a61,0x05f5},{0x01ed,0x1aab}},
    
};

Options optionsCK4a = {
    .loader = "LoaderMz",
    .exec = "KEEN4.EXE",
    .arch = arch_t::arch16,
    .loadAddress = 0x01ed0,
    .procModifiersStack = {
        {{0x01ed, 0x01ae}, 2}, // sub_207e retf
        {{0x01ed, 0x0226}, 2}, // sub_20f6 retf
        {{0x01ed, 0x026d}, 2}, // sub_213d retf
        {{0x01ed, 0x029a}, 6}, // sub_216a ret
        {{0x01ed, 0x03e3}, 2}, // sub_22b3 retf
        {{0x01ed, 0x03fc}, 2}, // sub_22cc ret
        {{0x01ed, 0x04b5}, 6}, // sub_2385 ret
        {{0x01ed, 0x059d}, 2}, // sub_246d retf
        {{0x01ed, 0x05bb}, 2}, // sub_248b retf
        {{0x01ed, 0x05e0}, 4}, // sub_24b0 ret
        {{0x01ed, 0x070c}, 2}, // sub_25dc retf
        {{0x01ed, 0x075e}, 2}, // sub_262e retf
        {{0x01ed, 0x07e0}, 2}, // sub_26b0 retf
        {{0x01ed, 0x0a42}, 2}, // sub_2912 ret
        {{0x01ed, 0x0ab1}, 2}, // sub_2981 retf
        {{0x01ed, 0x0b5c}, 2}, // sub_2a2c retf
        {{0x01ed, 0x0c43}, 2}, // sub_2b13 retf
        {{0x01ed, 0x0d23}, 2}, // sub_2bf3 retf
        {{0x01ed, 0x0d3c}, 2}, // sub_2c0c retf
        {{0x01ed, 0x0e55}, 6}, // sub_2d25 ret
        {{0x01ed, 0x0fa3}, 2}, // sub_2e73 retf
        {{0x01ed, 0x101d}, 4}, // sub_2eed ret
        {{0x01ed, 0x1056}, 4}, // sub_2f26 ret
        {{0x01ed, 0x1084}, 10}, // sub_2f54 ret
        {{0x01ed, 0x114a}, 10}, // sub_301a ret
        {{0x01ed, 0x1188}, 8}, // sub_3058 ret
        {{0x01ed, 0x11cb}, 6}, // sub_309b ret
        {{0x01ed, 0x11ee}, 12}, // sub_30be ret
        {{0x01ed, 0x1314}, 2}, // sub_31e4 retf
        {{0x01ed, 0x13ec}, 2}, // sub_32bc retf
        {{0x01ed, 0x142f}, 2}, // sub_32ff retf
        {{0x01ed, 0x145b}, 2}, // sub_332b retf
        {{0x01ed, 0x14b3}, 2}, // sub_3383 retf
        {{0x01ed, 0x15cf}, 2}, // sub_349f retf
        {{0x01ed, 0x165c}, 2}, // sub_352c retf
        {{0x01ed, 0x1706}, 2}, // sub_35d6 retf
        {{0x01ed, 0x1719}, 2}, // sub_35e9 retf
        {{0x01ed, 0x1734}, 2}, // sub_3604 retf
        {{0x01ed, 0x1752}, 2}, // sub_3622 retf
        {{0x01ed, 0x1915}, 2}, // sub_37e5 retf
        {{0x01ed, 0x1975}, 2}, // sub_3845 retf
        {{0x01ed, 0x19b6}, 2}, // sub_3886 retf
        {{0x01ed, 0x1a12}, 2}, // sub_38e2 retf
        {{0x01ed, 0x1a2d}, 2}, // sub_38fd retf
        {{0x01ed, 0x1a8b}, 2}, // sub_395b retf
        {{0x01ed, 0x1a9a}, 2}, // sub_396a retf
        {{0x01ed, 0x1ae3}, 2}, // sub_39b3 retf
        {{0x01ed, 0x1b54}, 2}, // sub_3a24 retf
        {{0x01ed, 0x1b7b}, 2}, // sub_3a4b ret
        {{0x01ed, 0x1bb8}, 2}, // sub_3a88 retf
        {{0x01ed, 0x1bc9}, 2}, // sub_3a99 retf
        {{0x01ed, 0x1bf2}, 12}, // sub_3ac2 ret
        {{0x01ed, 0x1c6f}, 2}, // sub_3b3f retf
        {{0x01ed, 0x1c9b}, 2}, // sub_3b6b retf
        {{0x01ed, 0x1cb5}, 2}, // sub_3b85 retf
        {{0x01ed, 0x1cdc}, 2}, // sub_3bac retf
        {{0x01ed, 0x1cfd}, 2}, // sub_3bcd retf
        {{0x01ed, 0x1d25}, 2}, // sub_3bf5 retf
        {{0x01ed, 0x1d40}, 2}, // sub_3c10 retf
        {{0x01ed, 0x1d62}, 4}, // sub_3c32 ret
        {{0x01ed, 0x1d7b}, 2}, // sub_3c4b ret
        {{0x01ed, 0x1d8d}, 2}, // sub_3c5d retf
        {{0x01ed, 0x1ec4}, 2}, // sub_3d94 retf
        {{0x01ed, 0x1f10}, 2}, // sub_3de0 retf
        {{0x01ed, 0x1fcb}, 2}, // sub_3e9b retf
        {{0x01ed, 0x1ffb}, 2}, // sub_3ecb retf
        {{0x01ed, 0x201a}, 4}, // sub_3eea ret
        {{0x01ed, 0x2040}, 12}, // sub_3f10 ret
        {{0x01ed, 0x20f1}, 4}, // sub_3fc1 ret
        {{0x01ed, 0x2265}, 2}, // sub_4135 retf
        {{0x01ed, 0x2281}, 2}, // sub_4151 retf
        {{0x01ed, 0x22ba}, 2}, // sub_418a retf
        {{0x01ed, 0x22e9}, 2}, // sub_41b9 retf
        {{0x01ed, 0x230d}, 2}, // sub_41dd retf
        {{0x01ed, 0x2327}, 2}, // sub_41f7 retf
        {{0x01ed, 0x2353}, 2}, // sub_4223 retf
        {{0x01ed, 0x2840}, 4}, // sub_4710 ret
        {{0x01ed, 0x2866}, 10}, // sub_4736 ret
        {{0x01ed, 0x28df}, 2}, // sub_47af retf
        {{0x01ed, 0x2ddd}, 2}, // sub_4cad retf
        {{0x01ed, 0x2ec3}, 2}, // sub_4d93 retf
        {{0x01ed, 0x308a}, 2}, // sub_4f5a retf
        {{0x01ed, 0x30c5}, 10}, // sub_4f95 retf
        {{0x01ed, 0x3173}, 2}, // sub_5043 retf
        {{0x01ed, 0x31b4}, 2}, // sub_5084 retf
        {{0x01ed, 0x31d5}, 2}, // sub_50a5 retf
        {{0x01ed, 0x3219}, 2}, // sub_50e9 retf
        {{0x01ed, 0x325a}, 2}, // sub_512a retf
        {{0x01ed, 0x325d}, 2}, // sub_512d retf
        {{0x01ed, 0x32ba}, 2}, // sub_518a retf
        {{0x01ed, 0x32e5}, 10}, // sub_51b5 retf
        {{0x01ed, 0x3307}, 2}, // sub_51d7 retf
        {{0x01ed, 0x3328}, 2}, // sub_51f8 retf
        {{0x01ed, 0x33f7}, 2}, // sub_52c7 retf
        {{0x01ed, 0x374c}, 2}, // sub_561c retf
        {{0x01ed, 0x37b3}, 2}, // sub_5683 retf
        {{0x056a, 0x000c}, 2}, // sub_56ac retf
        {{0x056a, 0x007f}, 2}, // sub_571f retf
        {{0x056a, 0x00a7}, 2}, // sub_5747 retf
        {{0x056a, 0x022f}, 2}, // sub_58cf retf
        {{0x056a, 0x0329}, 2}, // sub_59c9 retf
        {{0x056a, 0x0349}, 2}, // sub_59e9 retf
        {{0x056a, 0x04f7}, 2}, // sub_5b97 retf
        {{0x056a, 0x06ab}, 2}, // sub_5d4b retf
        {{0x05da, 0x000b}, 2}, // sub_5dab retf
        {{0x05da, 0x19ca}, 2}, // sub_776a retf
        {{0x05da, 0x1a31}, 2}, // sub_77d1 retf
        {{0x05da, 0x1b13}, 2}, // sub_78b3 retf
        {{0x05da, 0x1bfe}, 2}, // sub_799e retf
        {{0x05da, 0x1d55}, 2}, // sub_7af5 retf
        {{0x07b1, 0x0063}, 2}, // sub_7b73 retf
        {{0x07b1, 0x0093}, 2}, // sub_7ba3 retf
        {{0x07b1, 0x0484}, 2}, // sub_7f94 retf
        {{0x07b1, 0x0541}, 2}, // sub_8051 retf
        {{0x07b1, 0x0591}, 2}, // sub_80a1 retf
        {{0x07b1, 0x0860}, 2}, // sub_8370 retf
        {{0x07b1, 0x08f4}, 2}, // sub_8404 retf
        {{0x07b1, 0x0d81}, 2}, // sub_8891 retf
        {{0x08aa, 0x000b}, 2}, // sub_8aab retf
        {{0x08aa, 0x008f}, 2}, // sub_8b2f retf
        {{0x08aa, 0x0169}, 2}, // sub_8c09 retf
        {{0x08aa, 0x04ee}, 2}, // sub_8f8e retf
        {{0x08aa, 0x0611}, 2}, // sub_90b1 retf
        {{0x08aa, 0x0673}, 2}, // sub_9113 retf
        {{0x08aa, 0x07dc}, 2}, // sub_927c retf
        {{0x08aa, 0x0c60}, 2}, // sub_9700 retf
        {{0x08aa, 0x0cd5}, 2}, // sub_9775 retf
        {{0x08aa, 0x0fa2}, 2}, // sub_9a42 retf
        {{0x08aa, 0x1021}, 2}, // sub_9ac1 retf
        {{0x08aa, 0x16f1}, 2}, // sub_a191 retf
        {{0x08aa, 0x18a5}, 2}, // sub_a345 retf
        {{0x08aa, 0x1983}, 2}, // sub_a423 retf
        {{0x08aa, 0x1acd}, 2}, // sub_a56d retf
        {{0x08aa, 0x1d9e}, 2}, // sub_a83e retf
        {{0x08aa, 0x1e11}, 2}, // sub_a8b1 retf
        {{0x08aa, 0x1e8b}, 2}, // sub_a92b retf
        {{0x08aa, 0x1ef2}, 2}, // sub_a992 retf
        {{0x08aa, 0x1f47}, 2}, // sub_a9e7 retf
        {{0x08aa, 0x2092}, 2}, // sub_ab32 retf
        {{0x08aa, 0x20c7}, 2}, // sub_ab67 retf
        {{0x08aa, 0x21c6}, 2}, // sub_ac66 retf
        {{0x0b02, 0x000a}, 2}, // sub_b02a retf
        {{0x0b02, 0x001d}, 2}, // sub_b03d retf
        {{0x0b02, 0x0083}, 2}, // sub_b0a3 retf
        {{0x0b02, 0x00a1}, 2}, // sub_b0c1 retf
        {{0x0b02, 0x0128}, 2}, // sub_b148 retf
        {{0x0b02, 0x0357}, 2}, // sub_b377 retf
        {{0x0b02, 0x03bc}, 2}, // sub_b3dc retf
        {{0x0b02, 0x03de}, 2}, // sub_b3fe retf
        {{0x0b02, 0x0492}, 2}, // sub_b4b2 retf
        {{0x0b02, 0x06a1}, 2}, // sub_b6c1 retf
        {{0x0b02, 0x079c}, 2}, // sub_b7bc retf
        {{0x0b02, 0x09a5}, 2}, // sub_b9c5 retf
        {{0x0bc9, 0x0005}, 2}, // sub_bc95 retf
        {{0x0bc9, 0x002d}, 2}, // sub_bcbd retf
        {{0x0bc9, 0x0055}, 2}, // sub_bce5 retf
        {{0x0bc9, 0x019f}, 2}, // sub_be2f retf
        {{0x0bc9, 0x02da}, 2}, // sub_bf6a retf
        {{0x0bc9, 0x0469}, 2}, // sub_c0f9 retf
        {{0x0bc9, 0x0558}, 2}, // sub_c1e8 retf
        {{0x0bc9, 0x06a5}, 2}, // sub_c335 retf
        {{0x0bc9, 0x0936}, 2}, // sub_c5c6 retf
        {{0x0bc9, 0x0b49}, 2}, // sub_c7d9 retf
        {{0x0bc9, 0x0eee}, 2}, // sub_cb7e retf
        {{0x0bc9, 0x1097}, 2}, // sub_cd27 retf
        {{0x0bc9, 0x118c}, 2}, // sub_ce1c retf
        {{0x0bc9, 0x120a}, 2}, // sub_ce9a retf
        {{0x0d6d, 0x13e9}, 2}, // sub_eab9 retf
        {{0x0d6d, 0x16cd}, 2}, // sub_ed9d retf
        {{0x0d6d, 0x18e9}, 2}, // sub_efb9 retf
        {{0x0f7c, 0x0078}, 2}, // sub_f838 retf
        {{0x0f7c, 0x00cb}, 2}, // sub_f88b retf
        {{0x0f7c, 0x014f}, 2}, // sub_f90f retf
        {{0x0f7c, 0x04b8}, 2}, // sub_fc78 retf
        {{0x0f7c, 0x08a9}, 2}, // sub_10069 retf
        {{0x0f7c, 0x09fd}, 2}, // sub_101bd retf
        {{0x0f7c, 0x0a5b}, 2}, // sub_1021b retf
        {{0x107c, 0x0003}, 2}, // sub_107c3 retf
        {{0x107c, 0x0a66}, 2}, // sub_11226 retf
        {{0x1493, 0x000f}, 2}, // sub_1493f retf
        {{0x1493, 0x0094}, 2}, // sub_149c4 retf
        {{0x1493, 0x00f4}, 2}, // sub_14a24 retf
        {{0x1493, 0x0140}, 2}, // sub_14a70 retf
        {{0x1493, 0x0283}, 2}, // sub_14bb3 retf
        {{0x1493, 0x02cc}, 2}, // sub_14bfc retf
        {{0x1493, 0x03f5}, 2}, // sub_14d25 retf
        {{0x1493, 0x0685}, 2}, // sub_14fb5 retf
        {{0x1493, 0x0741}, 2}, // sub_15071 retf
        {{0x1493, 0x08dd}, 2}, // sub_1520d retf
        {{0x1493, 0x0910}, 2}, // sub_15240 retf
        {{0x1493, 0x0954}, 2}, // sub_15284 retf
        {{0x1493, 0x0999}, 2}, // sub_152c9 retf
        {{0x1493, 0x09c2}, 2}, // sub_152f2 retf
        {{0x1493, 0x0b28}, 2}, // sub_15458 retf
        {{0x1493, 0x0bae}, 2}, // sub_154de retf
        {{0x1493, 0x0c29}, 2}, // sub_15559 retf
        {{0x1493, 0x0f05}, 2}, // sub_15835 retf
        {{0x1493, 0x1117}, 2}, // sub_15a47 retf
        {{0x1493, 0x1260}, 2}, // sub_15b90 retf
        {{0x1493, 0x14cd}, 2}, // sub_15dfd retf
        {{0x1493, 0x14ed}, 2}, // sub_15e1d retf
        {{0x1493, 0x151a}, 2}, // sub_15e4a retf
        {{0x1493, 0x1562}, 2}, // sub_15e92 retf
        {{0x1493, 0x1593}, 2}, // sub_15ec3 retf
        {{0x1493, 0x161f}, 2}, // sub_15f4f retf
        {{0x1493, 0x184b}, 2}, // sub_1617b retf
        {{0x164d, 0x01d0}, 2}, // sub_166a0 retf
        {{0x164d, 0x01e8}, 2}, // sub_166b8 retf
        {{0x164d, 0x01fd}, 2}, // sub_166cd retf
        {{0x164d, 0x0298}, 2}, // sub_16768 retf
        {{0x164d, 0x043f}, 2}, // sub_1690f retf
        {{0x164d, 0x0478}, 2}, // sub_16948 retf
        {{0x164d, 0x04cb}, 2}, // sub_1699b retf
        {{0x164d, 0x0508}, 2}, // sub_169d8 retf
        {{0x164d, 0x0536}, 2}, // sub_16a06 retf
        {{0x164d, 0x055b}, 2}, // sub_16a2b retf
        {{0x164d, 0x0560}, 2}, // sub_16a30 retf
        {{0x164d, 0x05d7}, 2}, // sub_16aa7 retf
        {{0x164d, 0x0662}, 2}, // sub_16b32 retf
        {{0x164d, 0x06bf}, 2}, // sub_16b8f retf
        {{0x164d, 0x0794}, 2}, // sub_16c64 retf
        {{0x164d, 0x0826}, 2}, // sub_16cf6 retf
        {{0x164d, 0x0868}, 2}, // sub_16d38 retf
        {{0x164d, 0x08a8}, 2}, // sub_16d78 retf
        {{0x164d, 0x08cb}, 2}, // sub_16d9b retf
        {{0x164d, 0x08f9}, 2}, // sub_16dc9 retf
        {{0x164d, 0x09be}, 2}, // sub_16e8e retf
        {{0x164d, 0x0d28}, 2}, // sub_171f8 retf
        {{0x164d, 0x0d39}, 2}, // sub_17209 retf
        {{0x164d, 0x0d81}, 2}, // sub_17251 retf
        {{0x164d, 0x0da1}, 2}, // sub_17271 retf
        {{0x164d, 0x0dbf}, 2}, // sub_1728f retf
        {{0x164d, 0x0e1f}, 2}, // sub_172ef retf
        {{0x164d, 0x0e5a}, 2}, // sub_1732a retf
        {{0x164d, 0x0edf}, 2}, // sub_173af retf
        {{0x164d, 0x0f43}, 2}, // sub_17413 retf
        {{0x164d, 0x0f92}, 2}, // sub_17462 retf
        {{0x174b, 0x0001}, 2}, // sub_174b1 retf
        {{0x174b, 0x0037}, 2}, // sub_174e7 retf
        {{0x174b, 0x00e5}, 2}, // sub_17595 retf
        {{0x174b, 0x0109}, 2}, // sub_175b9 retf
        {{0x174b, 0x0181}, 2}, // sub_17631 retf
        {{0x174b, 0x019c}, 2}, // sub_1764c retf
        {{0x174b, 0x020b}, 2}, // sub_176bb retf
        {{0x174b, 0x0236}, 2}, // sub_176e6 retf
        {{0x174b, 0x03c5}, 2}, // sub_17875 retf
        {{0x174b, 0x042b}, 2}, // sub_178db retf
        {{0x174b, 0x06e2}, 2}, // sub_17b92 retf
        {{0x174b, 0x0712}, 2}, // sub_17bc2 retf
        {{0x174b, 0x0987}, 2}, // sub_17e37 retf
        {{0x174b, 0x0a52}, 2}, // sub_17f02 retf
        {{0x174b, 0x0ad5}, 2}, // sub_17f85 retf
        {{0x174b, 0x0b5d}, 2}, // sub_1800d retf
        {{0x174b, 0x0d3d}, 2}, // sub_181ed retf
        {{0x174b, 0x0e7f}, 2}, // sub_1832f retf
        {{0x174b, 0x0ee6}, 2}, // sub_18396 retf
        {{0x174b, 0x0f64}, 2}, // sub_18414 retf
        {{0x1841, 0x000f}, 2}, // sub_1841f retf
        {{0x1841, 0x0134}, 2}, // sub_18544 retf
        {{0x1841, 0x0139}, 2}, // sub_18549 retf
        {{0x1841, 0x01c2}, 2}, // sub_185d2 retf
        {{0x1841, 0x0318}, 2}, // sub_18728 retf
        {{0x1841, 0x06e2}, 2}, // sub_18af2 retf
        {{0x1841, 0x071a}, 2}, // sub_18b2a retf
        {{0x1841, 0x0868}, 2}, // sub_18c78 retf
        {{0x1841, 0x08ab}, 2}, // sub_18cbb retf
        {{0x1841, 0x0946}, 2}, // sub_18d56 retf
        {{0x1841, 0x0a31}, 2}, // sub_18e41 retf
        {{0x1841, 0x0a78}, 2}, // sub_18e88 retf
        {{0x1841, 0x0afb}, 2}, // sub_18f0b retf
        {{0x1841, 0x0b08}, 2}, // sub_18f18 retf
        {{0x1841, 0x0b61}, 2}, // sub_18f71 retf
        {{0x1841, 0x0c50}, 2}, // sub_19060 retf
        {{0x1841, 0x0c62}, 2}, // sub_19072 retf
        {{0x1841, 0x0d59}, 2}, // sub_19169 retf
        {{0x1841, 0x1025}, 2}, // sub_19435 retf
        {{0x1841, 0x1220}, 2}, // sub_19630 retf
        {{0x1841, 0x12ec}, 2}, // sub_196fc retf
        {{0x1841, 0x1333}, 2}, // sub_19743 retf
        {{0x1841, 0x13dd}, 2}, // sub_197ed retf
        {{0x1841, 0x1641}, 2}, // sub_19a51 retf
        {{0x1841, 0x185b}, 2}, // sub_19c6b retf
        {{0x1841, 0x18e3}, 2}, // sub_19cf3 retf
        {{0x1841, 0x1a6e}, 2}, // sub_19e7e retf
        {{0x1841, 0x1c6e}, 2}, // sub_1a07e retf
        {{0x1a13, 0x000c}, 2}, // sub_1a13c retf
        {{0x1a13, 0x01ea}, 2}, // sub_1a31a retf
        {{0x1a13, 0x0344}, 2}, // sub_1a474 retf
        {{0x1a61, 0x000e}, 2}, // sub_1a61e retf
        {{0x1a61, 0x0033}, 2}, // sub_1a643 retf
        {{0x1a61, 0x007b}, 2}, // sub_1a68b retf
        {{0x1a61, 0x00a9}, 2}, // sub_1a6b9 retf
        {{0x1a61, 0x0144}, 2}, // sub_1a754 retf
        {{0x1a61, 0x015e}, 2}, // sub_1a76e retf
        {{0x1a61, 0x01a0}, 2}, // sub_1a7b0 retf
        {{0x1a61, 0x01c1}, 2}, // sub_1a7d1 retf
        {{0x1a61, 0x02d7}, 2}, // sub_1a8e7 retf
        {{0x1a61, 0x0491}, 2}, // sub_1aaa1 retf
        {{0x1a61, 0x04cb}, 2}, // sub_1aadb retf
        {{0x1a61, 0x0504}, 2}, // sub_1ab14 retf
        {{0x1a61, 0x0529}, 2}, // sub_1ab39 retf
        {{0x1a61, 0x06d7}, 2}, // sub_1ace7 retf
        {{0x1a61, 0x06fb}, 2}, // sub_1ad0b retf
        {{0x1a61, 0x0712}, 2}, // sub_1ad22 retf
        {{0x1a61, 0x072d}, 2}, // sub_1ad3d retf
        {{0x1a61, 0x074b}, 2}, // sub_1ad5b retf
        {{0x1a61, 0x07d0}, 2}, // sub_1ade0 retf
        {{0x1a61, 0x0826}, 2}, // sub_1ae36 retf
        {{0x1a61, 0x0913}, 2}, // sub_1af23 retf
        {{0x1a61, 0x099f}, 2}, // sub_1afaf retf
        {{0x1a61, 0x09f1}, 2}, // sub_1b001 retf
        {{0x1a61, 0x0a90}, 2}, // sub_1b0a0 retf
        {{0x1a61, 0x0ad7}, 2}, // sub_1b0e7 retf
        {{0x1a61, 0x0afd}, 2}, // sub_1b10d retf
        {{0x1a61, 0x0b0a}, 2}, // sub_1b11a retf
        {{0x1a61, 0x0b15}, 2}, // sub_1b125 retf
        {{0x1a61, 0x0b62}, 2}, // sub_1b172 retf
        {{0x1a61, 0x0bb4}, 2}, // sub_1b1c4 retf
        {{0x1a61, 0x0bc7}, 2}, // sub_1b1d7 retf
        {{0x1b1e, 0x0144}, 2}, // sub_1b324 retf
        {{0x1b1e, 0x0154}, 2}, // sub_1b334 retf
        {{0x1b1e, 0x0180}, 2}, // sub_1b360 retf
        {{0x1b1e, 0x0348}, 2}, // sub_1b528 retf
        {{0x1b1e, 0x0490}, 2}, // sub_1b670 retf
        {{0x1b1e, 0x0547}, 2}, // sub_1b727 retf
        {{0x1b1e, 0x05c1}, 2}, // sub_1b7a1 retf
        {{0x1b1e, 0x05e2}, 2}, // sub_1b7c2 retf
        {{0x1b1e, 0x05ff}, 2}, // sub_1b7df retf
        {{0x1b1e, 0x06b5}, 2}, // sub_1b895 retf
        {{0x1b1e, 0x06fe}, 2}, // sub_1b8de retf
        {{0x1b1e, 0x0783}, 2}, // sub_1b963 retf
        {{0x1b1e, 0x079a}, 2}, // sub_1b97a retf
        {{0x1b1e, 0x081e}, 2}, // sub_1b9fe retf
        {{0x1b1e, 0x08b0}, 2}, // sub_1ba90 retf
        {{0x1b1e, 0x0911}, 2}, // sub_1baf1 retf
        {{0x1b1e, 0x0c3c}, 2}, // sub_1be1c retf
        {{0x1b1e, 0x0cda}, 2}, // sub_1beba retf
        {{0x1b1e, 0x0cf9}, 2}, // sub_1bed9 retf
        {{0x1b1e, 0x0d72}, 2}, // sub_1bf52 retf
        {{0x1b1e, 0x0d9a}, 2}, // sub_1bf7a retf
        {{0x1b1e, 0x0dc2}, 2}, // sub_1bfa2 retf
        {{0x1b1e, 0x0e1f}, 2}, // sub_1bfff retf
        {{0x1b1e, 0x0e60}, 2}, // sub_1c040 retf
        {{0x1b1e, 0x0ebd}, 2}, // sub_1c09d retf
        {{0x1b1e, 0x0f02}, 2}, // sub_1c0e2 retf
        {{0x1b1e, 0x0f2f}, 2}, // sub_1c10f retf
        {{0x1b1e, 0x1070}, 2}, // sub_1c250 retf
        {{0x1b1e, 0x11af}, 2}, // sub_1c38f retf
        {{0x1b1e, 0x1205}, 2}, // sub_1c3e5 retf
        {{0x1c76, 0x0005}, 2}, // sub_1c765 retf
        {{0x1c76, 0x0024}, 2}, // sub_1c784 retf
        {{0x1c76, 0x004b}, 2}, // sub_1c7ab retf
        {{0x1c76, 0x0078}, 2}, // sub_1c7d8 retf
        {{0x1c76, 0x0110}, 2}, // sub_1c870 retf
        {{0x1c76, 0x01a6}, 2}, // sub_1c906 retf
        {{0x1c76, 0x024c}, 2}, // sub_1c9ac retf
        {{0x1c76, 0x035e}, 2}, // sub_1cabe retf
        {{0x1c76, 0x0391}, 2}, // sub_1caf1 retf
        {{0x1c76, 0x0536}, 2}, // sub_1cc96 retf
        {{0x1c76, 0x06e8}, 2}, // sub_1ce48 retf
        {{0x1c76, 0x086b}, 2}, // sub_1cfcb retf
        {{0x1c76, 0x1e9e}, 2}, // sub_1e5fe retf
        {{0x1c76, 0x1ef6}, 2}, // sub_1e656 retf
        {{0x1c76, 0x1f37}, 2}, // sub_1e697 retf
        {{0x1c76, 0x1fda}, 2}, // sub_1e73a retf
        {{0x1c76, 0x2067}, 2}, // sub_1e7c7 retf
        {{0x1c76, 0x20a0}, 2}, // sub_1e800 retf
        {{0x1c76, 0x20ca}, 2}, // sub_1e82a retf
        {{0x1c76, 0x2108}, 2}, // sub_1e868 retf
        {{0x1c76, 0x2153}, 2}, // sub_1e8b3 retf
        {{0x1c76, 0x219f}, 2}, // sub_1e8ff retf
        {{0x1c76, 0x2265}, 2}, // sub_1e9c5 retf
        {{0x1c76, 0x2355}, 2}, // sub_1eab5 retf
        {{0x1c76, 0x2426}, 2}, // sub_1eb86 retf
        {{0x1c76, 0x2480}, 2}, // sub_1ebe0 retf
        {{0x1c76, 0x24db}, 2}, // sub_1ec3b retf
        {{0x1c76, 0x2582}, 2}, // sub_1ece2 retf
        {{0x1eef, 0x0002}, 2}, // sub_1eef2 retf
        {{0x1eef, 0x002a}, 2}, // sub_1ef1a retf
        {{0x1ef3, 0x0005}, 2}, // sub_1ef35 retf
        {{0x1ef3, 0x0090}, 2}, // sub_1efc0 retf
        {{0x1ef3, 0x00ac}, 2}, // sub_1efdc retf
        {{0x1ef3, 0x00e9}, 2}, // sub_1f019 retf
        {{0x1ef3, 0x0152}, 2}, // sub_1f082 retf
        {{0x1ef3, 0x016f}, 2}, // sub_1f09f retf
        {{0x1ef3, 0x02dd}, 2}, // sub_1f20d retf
        {{0x1ef3, 0x030d}, 2}, // sub_1f23d retf
        {{0x1ef3, 0x035c}, 2}, // sub_1f28c retf
        {{0x1ef3, 0x057d}, 2}, // sub_1f4ad retf
        {{0x1ef3, 0x064e}, 2}, // sub_1f57e retf
        {{0x1ef3, 0x074d}, 2}, // sub_1f67d retf
        {{0x1ef3, 0x078d}, 2}, // sub_1f6bd retf
        {{0x1ef3, 0x07d7}, 2}, // sub_1f707 retf
        {{0x1ef3, 0x0829}, 2}, // sub_1f759 retf
        {{0x1ef3, 0x0886}, 2}, // sub_1f7b6 retf
        {{0x1ef3, 0x088f}, 2}, // sub_1f7bf retf
        {{0x1ef3, 0x092b}, 2}, // sub_1f85b retf
        {{0x1ef3, 0x0981}, 2}, // sub_1f8b1 retf
        {{0x1ef3, 0x0999}, 2}, // sub_1f8c9 retf
        {{0x1ef3, 0x09bb}, 2}, // sub_1f8eb retf
        {{0x1ef3, 0x0a9b}, 2}, // sub_1f9cb retf
        {{0x1ef3, 0x0abb}, 2}, // sub_1f9eb retf
        {{0x1ef3, 0x0b0e}, 2}, // sub_1fa3e retf
        {{0x1ef3, 0x0c79}, 2}, // sub_1fba9 retf
        {{0x1ef3, 0x0d29}, 2}, // sub_1fc59 retf
        {{0x1ef3, 0x0de3}, 2}, // sub_1fd13 retf
        {{0x1ef3, 0x0e2c}, 2}, // sub_1fd5c retf
        {{0x1ef3, 0x0e75}, 2}, // sub_1fda5 retf
        {{0x1ef3, 0x0faf}, 2}, // sub_1fedf retf
        {{0x1ef3, 0x0ff8}, 2}, // sub_1ff28 retf
        {{0x1ff7, 0x0000}, 2}, // sub_1ff70 retf
        {{0x1ff7, 0x004f}, 2}, // sub_1ffbf retf
        {{0x1ff7, 0x00af}, 2}, // sub_2001f retf
        {{0x1ff7, 0x0449}, 2}, // sub_203b9 retf
        {{0x1ff7, 0x0495}, 2}, // sub_20405 retf
        {{0x1ff7, 0x059f}, 2}, // sub_2050f retf
        {{0x1ff7, 0x05da}, 2}, // sub_2054a retf
        {{0x1ff7, 0x0759}, 2}, // sub_206c9 retf
        {{0x1ff7, 0x07da}, 2}, // sub_2074a retf
        {{0x1ff7, 0x09b9}, 2}, // sub_20929 retf
        {{0x1ff7, 0x0ad3}, 2}, // sub_20a43 retf
        {{0x1ff7, 0x0b1a}, 2}, // sub_20a8a retf
    },
    .isolateLabels = {address_t(0x01ed, 0x0226)},
    .jumpTables = {
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x056a, 0x0443), .table = {0x056a, 1257}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
        //indirectJump(cs, memoryAGet16(cs, bx + 996)); // 05da:02ed;
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x05da, 0x02ed), .table = {0x05da, 996}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
        //    indirectJump(cs, memoryAGet16(ss, di + 24600)); // 1ff7:0507; ss=30d4
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x0507), .table = {0x30d4, 24600}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "di"}),
        //    push(cs); cs = memoryAGet16(ds, 0x7ae8 + 2); callIndirect(cs, memoryAGet16(ds, 0x7ae8)); assert(cs == 0x1493); // 1493:18e7; 7b1:66d, 1439:1650
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x017e), .table = {0x30d4, 24554}, .type = jumpTable_t::JumpWords, .elements = sequence("0-21"), .selector = "memoryAGet16(ss, 0x6016)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x017e), .baseptr = (const uint8_t*)"\xa0\x01", .type = jumpTable_t::JumpWords, .elements = sequence("0-0"), .selector = "memoryAGet16(ss, 0x6016)", .useCaseOffset = true }),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1ff7, 0x08a0), .table = {0x30d4, 26234}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "si"}),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x107c, 0x005f), .table = {0x107c, 1429}, .type = jumpTable_t::JumpWords, .elements = sequence("0-87"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 1976)); // 1c76:071b; gg 0..5
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x071b), .table = {0x1c76, 1976}, .type = jumpTable_t::JumpWords, .elements = sequence("0-5"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 2543)); // 0f7c:0985; gg 0..6
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0f7c, 0x0985), .table = {0x0f7c, 2543}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 2841)); // 0b02:0ac8; gg 0..9
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0b02, 0x0ac8), .table = {0x0b02, 2841}, .type = jumpTable_t::JumpWords, .elements = sequence("0-9"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 3358)); // 164d:0a71; gg 0..4
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x164d, 0x0a71), .table = {0x164d, 3358}, .type = jumpTable_t::JumpWords, .elements = sequence("0-4"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 3409)); // 1841:0c77; gg 0..3
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1841, 0x0c77), .table = {0x1841, 3409}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 3969)); // 07b1:0e67; gg 0..12
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x07b1, 0x0e67), .table = {0x07b1, 3969}, .type = jumpTable_t::JumpWords, .elements = sequence("0-12"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 5495)); // 1b1e:12f6; gg 0..6
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1b1e, 0x12f6), .table = {0x1b1e, 5495}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 6727)); // 0d6d:196c; gg 0..0x19
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0d6d, 0x196c), .table = {0x0d6d, 6727}, .type = jumpTable_t::JumpWords, .elements = sequence("0-25"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 817)); // 0b02:0154; gg 0..0x12
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0b02, 0x0154), .table = {0x0b02, 817}, .type = jumpTable_t::JumpWords, .elements = sequence("0-18"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 9330)); // 1c76:2434; gg 0..6
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x1c76, 0x2434), .table = {0x1c76, 9330}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 959)); // 01ed:02d9; gg 0..6
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x01ed, 0x02d9), .table = {0x01ed, 959}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),

//        indirectJump(cs, memoryAGet16(cs, bx + 3388)); // 126d:0ce7; gy 0..3
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x126d, 0x0ce7), .table = {0x126d, 3388}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 3454)); // 138f:0d28; gy 0..3
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x138f, 0x0d28), .table = {0x138f, 3454}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
//        indirectJump(cs, memoryAGet16(cs, bx + 3806)); // 138f:0e7d; gy 0..3
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x138f, 0x0e7d), .table = {0x138f, 3806}, .type = jumpTable_t::JumpWords, .elements = sequence("0-3"), .selector = "bx"}),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0d6d, 0x1502), .table = {0x0d6d, 5658}, .type = jumpTable_t::JumpWords, .elements = sequence("0-11"), .selector = "bx"}),
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0d6d, 0x1649), .table = {0x0d6d, 5813}, .type = jumpTable_t::JumpWords, .elements = sequence("0-11"), .selector = "bx"}),
        //    indirectJump(cs, memoryAGet16(cs, bx + 3381)); // 0f7c:0cd2;
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0f7c, 0x0cd2), .table = {0x0f7c, 3381}, .type = jumpTable_t::JumpWords, .elements = sequence("0-6"), .selector = "bx"}),
        //    indirectJump(cs, memoryAGet16(cs, bx + 6690)); // 0bc9:198d; 0..21
        std::shared_ptr<jumpTable_t>(new jumpTable_t{.instruction = address_t(0x0bc9, 0x198d), .table = {0x0bc9, 6690}, .type = jumpTable_t::JumpWords, .elements = sequence("0-21"), .selector = "bx"}),


    },
    .procList = {{0x164d,0x000b},{0x1a61,0x05f5},{0x01ed,0x1aab}},

};

}
