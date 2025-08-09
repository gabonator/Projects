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
    .verbose = true,
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
        {{0x01ed, 0xaadd}, (procRequest_t)((int)procRequest_t::returnZero | (int)procRequest_t::returnCarry | (int)procRequest_t::callNear)}
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

};
