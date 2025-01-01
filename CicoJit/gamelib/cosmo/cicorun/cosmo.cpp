#define jumpIndirect callIndirect
#include "cicoemu.h"
using namespace CicoContext;

class CStackGuard
{
    uint16_t minit;
    bool uses;
public:
    CStackGuard(int ofs, bool use):minit(sp+ofs),uses(use) { if (!uses) push(0xabcd);}
    ~CStackGuard() {
        if (!uses)
            assert(pop() == 0xabcd);
        assert(minit == sp);
    }
};

class CStackGuardFar
{
    uint16_t minit;
public:
    CStackGuardFar(int ofs, bool use):minit(sp+ofs) {}
    ~CStackGuardFar() { assert(minit == sp-2); }
};

void sub_1ed0();
void fixReloc(uint16_t seg);

void start()
{
    headerSize = 0x15b0;
    loadAddress = 0x01ed;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x24f8;
    sp = 0x00e6;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/cosmo/dos", "COSMO1.EXE", 123046);
    fixReloc(cs);
    sub_1ed0();
}
void fixReloc(uint16_t seg)
{
    memory16(0x0000 + seg, 0x0001) += seg; // 18a4 -> 1a91
    memory16(0x000d + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x000d + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x0010 + seg, 0x0005) += seg; // 00fa -> 02e7
    memory16(0x0010 + seg, 0x000b) += seg; // 1524 -> 1711
    memory16(0x0011 + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x001c + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x0028 + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x00c5 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x00ca + seg, 0x0007) += seg; // 152b -> 1718
    memory16(0x00cc + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x00d9 + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x00dd + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x00df + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x00fb + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x00fc + seg, 0x0006) += seg; // 16bf -> 18ac
    memory16(0x00fd + seg, 0x0002) += seg; // 16bf -> 18ac
    memory16(0x00fd + seg, 0x000e) += seg; // 16bf -> 18ac
    memory16(0x00fe + seg, 0x000a) += seg; // 16bf -> 18ac
    memory16(0x00ff + seg, 0x0006) += seg; // 16bf -> 18ac
    memory16(0x00ff + seg, 0x000d) += seg; // 1798 -> 1985
    memory16(0x0101 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x0102 + seg, 0x0005) += seg; // 1524 -> 1711
    memory16(0x0103 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x0104 + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0105 + seg, 0x0005) += seg; // 1611 -> 17fe
    memory16(0x010f + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x0112 + seg, 0x000f) += seg; // 0000 -> 01ed
    memory16(0x0114 + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x0115 + seg, 0x0002) += seg; // 184a -> 1a37
    memory16(0x0116 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x0116 + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x0117 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x011c + seg, 0x000d) += seg; // 183f -> 1a2c
    memory16(0x0122 + seg, 0x0002) += seg; // 180c -> 19f9
    memory16(0x0124 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x0126 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x0128 + seg, 0x0003) += seg; // 180c -> 19f9
    memory16(0x012c + seg, 0x0001) += seg; // 180c -> 19f9
    memory16(0x012d + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x012f + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0130 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0132 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x0135 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x0138 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x013a + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x013c + seg, 0x0009) += seg; // 162a -> 1817
    memory16(0x013d + seg, 0x0007) += seg; // 1611 -> 17fe
    memory16(0x0141 + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x0143 + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x0145 + seg, 0x0004) += seg; // 162a -> 1817
    memory16(0x0146 + seg, 0x0002) += seg; // 1611 -> 17fe
    memory16(0x0146 + seg, 0x000e) += seg; // 183f -> 1a2c
    memory16(0x0147 + seg, 0x000b) += seg; // 183f -> 1a2c
    memory16(0x0148 + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0148 + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x014a + seg, 0x0002) += seg; // 183f -> 1a2c
    memory16(0x014d + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x014d + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x014e + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0151 + seg, 0x0000) += seg; // 162a -> 1817
    memory16(0x0151 + seg, 0x000e) += seg; // 1611 -> 17fe
    memory16(0x015b + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x015d + seg, 0x0000) += seg; // 162a -> 1817
    memory16(0x015d + seg, 0x000e) += seg; // 1611 -> 17fe
    memory16(0x015f + seg, 0x0001) += seg; // 1095 -> 1282
    memory16(0x0160 + seg, 0x000c) += seg; // 162a -> 1817
    memory16(0x0162 + seg, 0x0006) += seg; // 162a -> 1817
    memory16(0x0164 + seg, 0x000c) += seg; // 162a -> 1817
    memory16(0x0165 + seg, 0x000a) += seg; // 1611 -> 17fe
    memory16(0x0169 + seg, 0x0006) += seg; // 183f -> 1a2c
    memory16(0x016c + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x016e + seg, 0x0006) += seg; // 162a -> 1817
    memory16(0x016f + seg, 0x0004) += seg; // 1611 -> 17fe
    memory16(0x0179 + seg, 0x0000) += seg; // 183f -> 1a2c
    memory16(0x0179 + seg, 0x000d) += seg; // 183f -> 1a2c
    memory16(0x017f + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x0182 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x0184 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x0185 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x01fe + seg, 0x0006) += seg; // 183f -> 1a2c
    memory16(0x0207 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x0208 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x0208 + seg, 0x000c) += seg; // 0000 -> 01ed
    memory16(0x0213 + seg, 0x0006) += seg; // 183f -> 1a2c
    memory16(0x021a + seg, 0x000c) += seg; // 0000 -> 01ed
    memory16(0x0224 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x0228 + seg, 0x0002) += seg; // 183f -> 1a2c
    memory16(0x022a + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x022b + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x022c + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x023e + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x0247 + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0249 + seg, 0x000c) += seg; // 162a -> 1817
    memory16(0x024a + seg, 0x000a) += seg; // 1611 -> 17fe
    memory16(0x024c + seg, 0x0002) += seg; // 183f -> 1a2c
    memory16(0x024c + seg, 0x000e) += seg; // 183f -> 1a2c
    memory16(0x0254 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x0272 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x0273 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x027b + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x027f + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x0282 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x0284 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x0285 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x0286 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x0287 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x028e + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x028f + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x0297 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x0299 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x02a3 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x02a8 + seg, 0x000b) += seg; // 183f -> 1a2c
    memory16(0x02b0 + seg, 0x000f) += seg; // 0000 -> 01ed
    memory16(0x02b3 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x02b4 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x02ba + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x0310 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x0314 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x033e + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x0344 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x034f + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x0353 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x035f + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x0386 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x0387 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x0391 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x0392 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x0392 + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0394 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x03da + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x03f4 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x03f5 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x0406 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x0409 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x040c + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x040e + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x040f + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x041d + seg, 0x000d) += seg; // 184a -> 1a37
    memory16(0x0423 + seg, 0x0005) += seg; // 184a -> 1a37
    memory16(0x0436 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x043a + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x044f + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x049d + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x049f + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x04a1 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x04a2 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x04a4 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x04e3 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x04e5 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x04f1 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x04f8 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x04fc + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x04fe + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x0538 + seg, 0x000e) += seg; // 184a -> 1a37
    memory16(0x0544 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x0545 + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0545 + seg, 0x000e) += seg; // 1095 -> 1282
    memory16(0x054c + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x0550 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x0552 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x0558 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x055a + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x058e + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x0594 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x05ac + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x05ae + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x0625 + seg, 0x0007) += seg; // 184a -> 1a37
    memory16(0x062a + seg, 0x0009) += seg; // 184a -> 1a37
    memory16(0x062d + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x062f + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x0630 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x0632 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x0634 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x0643 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x064a + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x064c + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x0654 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x0656 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x0658 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x0659 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x065b + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x06a2 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x06ab + seg, 0x0004) += seg; // 184a -> 1a37
    memory16(0x06ca + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x06d5 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x06de + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x06e2 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x06f3 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x06f5 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x071f + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x0723 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x0726 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x0729 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x072a + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x072c + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x072d + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x072f + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x0731 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x0733 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x0739 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x073f + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x0741 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x0743 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x0745 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x0747 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x0749 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x074b + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x074d + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x074f + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x0751 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x0752 + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x075e + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x0783 + seg, 0x0006) += seg; // 184a -> 1a37
    memory16(0x0784 + seg, 0x0004) += seg; // 184a -> 1a37
    memory16(0x0785 + seg, 0x0007) += seg; // 184a -> 1a37
    memory16(0x0786 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x078f + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x0791 + seg, 0x0003) += seg; // 1095 -> 1282
    memory16(0x0792 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x0795 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x0796 + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0798 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x079d + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x079f + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x07b3 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x07c2 + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x07c3 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x07d3 + seg, 0x000b) += seg; // 184a -> 1a37
    memory16(0x07d6 + seg, 0x0000) += seg; // 184a -> 1a37
    memory16(0x07ee + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x07f0 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x07f4 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x07f6 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x0806 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x0808 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x0812 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x0815 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x0816 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x0818 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x0819 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x081b + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x0825 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x082c + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x082e + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x0830 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x0833 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x083e + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x0840 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x0842 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x0843 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x0845 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x0846 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x0848 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x084a + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x084c + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x084d + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x084e + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0850 + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x0852 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x0859 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x0860 + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x0865 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x0869 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x086b + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x086d + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x086f + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x0871 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x0873 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x0878 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x0880 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x0885 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x088c + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0895 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x0897 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x0b09 + seg, 0x000d) += seg; // 184a -> 1a37
    memory16(0x0b0a + seg, 0x000e) += seg; // 184a -> 1a37
    memory16(0x0b0c + seg, 0x000a) += seg; // 184a -> 1a37
    memory16(0x0b0f + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x0b11 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x0b47 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x0b4c + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x0b4e + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x0b7f + seg, 0x0000) += seg; // 184a -> 1a37
    memory16(0x0b9f + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0bba + seg, 0x000a) += seg; // 1095 -> 1282
    memory16(0x0bf1 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0bfb + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0c00 + seg, 0x0004) += seg; // 1095 -> 1282
    memory16(0x0c0c + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x0c0f + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0c11 + seg, 0x000b) += seg; // 1095 -> 1282
    memory16(0x0c21 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0c24 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0c7c + seg, 0x000e) += seg; // 1095 -> 1282
    memory16(0x0c7e + seg, 0x0004) += seg; // 1095 -> 1282
    memory16(0x0c8d + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0c8e + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0c8f + seg, 0x0001) += seg; // 1095 -> 1282
    memory16(0x0c91 + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x0c94 + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0c98 + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x0c9a + seg, 0x0004) += seg; // 1095 -> 1282
    memory16(0x0c9c + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0ca3 + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0ca7 + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x0ca8 + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0cb2 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x0cbd + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x0cbf + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x0cc0 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x0cc2 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x0cc7 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x0cd9 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x0ce7 + seg, 0x0001) += seg; // 1095 -> 1282
    memory16(0x0cea + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0cee + seg, 0x000d) += seg; // 1095 -> 1282
    memory16(0x0d06 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x0d08 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x0d31 + seg, 0x000c) += seg; // 183f -> 1a2c
    memory16(0x0d32 + seg, 0x0009) += seg; // 183f -> 1a2c
    memory16(0x0d33 + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x0d33 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x0d34 + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x0d3d + seg, 0x000d) += seg; // 18a4 -> 1a91
    memory16(0x0d4f + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0d51 + seg, 0x000b) += seg; // 162a -> 1817
    memory16(0x0d53 + seg, 0x0001) += seg; // 16a1 -> 188e
    memory16(0x0d53 + seg, 0x000e) += seg; // 16bf -> 18ac
    memory16(0x0d55 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x0d55 + seg, 0x000e) += seg; // 1095 -> 1282
    memory16(0x0d57 + seg, 0x0000) += seg; // 1814 -> 1a01
    memory16(0x0d57 + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x0d58 + seg, 0x0000) += seg; // 188c -> 1a79
    memory16(0x0d58 + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0d59 + seg, 0x0006) += seg; // 1697 -> 1884
    memory16(0x0d5a + seg, 0x000a) += seg; // 1524 -> 1711
    memory16(0x0d5b + seg, 0x000b) += seg; // 1095 -> 1282
    memory16(0x0d5d + seg, 0x0007) += seg; // 162a -> 1817
    memory16(0x0d5e + seg, 0x0005) += seg; // 1611 -> 17fe
    memory16(0x0d5f + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0d61 + seg, 0x0004) += seg; // 162a -> 1817
    memory16(0x0d62 + seg, 0x0002) += seg; // 1611 -> 17fe
    memory16(0x0d63 + seg, 0x000f) += seg; // 1827 -> 1a14
    memory16(0x0d64 + seg, 0x000f) += seg; // 188c -> 1a79
    memory16(0x0d65 + seg, 0x000a) += seg; // 16bf -> 18ac
    memory16(0x0d66 + seg, 0x0003) += seg; // 1524 -> 1711
    memory16(0x0d66 + seg, 0x0009) += seg; // 1744 -> 1931
    memory16(0x0d69 + seg, 0x000d) += seg; // 1095 -> 1282
    memory16(0x0d6a + seg, 0x0004) += seg; // 188c -> 1a79
    memory16(0x0d6b + seg, 0x0007) += seg; // 1524 -> 1711
    memory16(0x0d6c + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x0d6c + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0d6d + seg, 0x0000) += seg; // 1744 -> 1931
    memory16(0x0d6d + seg, 0x000f) += seg; // 1814 -> 1a01
    memory16(0x0d6f + seg, 0x0003) += seg; // 1814 -> 1a01
    memory16(0x0d71 + seg, 0x0007) += seg; // 152b -> 1718
    memory16(0x0d72 + seg, 0x000e) += seg; // 1095 -> 1282
    memory16(0x0d74 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x0d74 + seg, 0x000b) += seg; // 1095 -> 1282
    memory16(0x0d75 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x0d76 + seg, 0x0001) += seg; // 152b -> 1718
    memory16(0x0d77 + seg, 0x000a) += seg; // 152b -> 1718
    memory16(0x0d79 + seg, 0x0003) += seg; // 152b -> 1718
    memory16(0x0d7a + seg, 0x000c) += seg; // 152b -> 1718
    memory16(0x0d80 + seg, 0x0007) += seg; // 152b -> 1718
    memory16(0x0d81 + seg, 0x0006) += seg; // 152b -> 1718
    memory16(0x0d82 + seg, 0x0005) += seg; // 152b -> 1718
    memory16(0x0d83 + seg, 0x0004) += seg; // 152b -> 1718
    memory16(0x0d84 + seg, 0x000f) += seg; // 152b -> 1718
    memory16(0x0d8e + seg, 0x000b) += seg; // 152b -> 1718
    memory16(0x0d92 + seg, 0x0004) += seg; // 152b -> 1718
    memory16(0x0d95 + seg, 0x000d) += seg; // 152b -> 1718
    memory16(0x0d98 + seg, 0x000d) += seg; // 152b -> 1718
    memory16(0x0d9b + seg, 0x0005) += seg; // 152b -> 1718
    memory16(0x0d9c + seg, 0x000d) += seg; // 1744 -> 1931
    memory16(0x0d9d + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x0d9d + seg, 0x000e) += seg; // 1095 -> 1282
    memory16(0x0d9e + seg, 0x000c) += seg; // 0000 -> 01ed
    memory16(0x0d9f + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0d9f + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x0d9f + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0de1 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0de5 + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x0ded + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0e7d + seg, 0x0001) += seg; // 184a -> 1a37
    memory16(0x0ec8 + seg, 0x0004) += seg; // 1095 -> 1282
    memory16(0x0ee6 + seg, 0x0003) += seg; // 1095 -> 1282
    memory16(0x0eee + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x0eef + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x0f01 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x0f02 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x0f0d + seg, 0x0004) += seg; // 1573 -> 1760
    memory16(0x0f0e + seg, 0x000a) += seg; // 1611 -> 17fe
    memory16(0x0f0f + seg, 0x000c) += seg; // 1816 -> 1a03
    memory16(0x0f11 + seg, 0x0005) += seg; // 162a -> 1817
    memory16(0x0f12 + seg, 0x0003) += seg; // 1816 -> 1a03
    memory16(0x0f13 + seg, 0x0008) += seg; // 1816 -> 1a03
    memory16(0x0f14 + seg, 0x0008) += seg; // 1816 -> 1a03
    memory16(0x0f15 + seg, 0x0008) += seg; // 1816 -> 1a03
    memory16(0x0f16 + seg, 0x0008) += seg; // 1816 -> 1a03
    memory16(0x0f17 + seg, 0x0008) += seg; // 1816 -> 1a03
    memory16(0x0f18 + seg, 0x0008) += seg; // 1816 -> 1a03
    memory16(0x0f19 + seg, 0x0008) += seg; // 1816 -> 1a03
    memory16(0x0f1b + seg, 0x000c) += seg; // 1816 -> 1a03
    memory16(0x0f1c + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0f1d + seg, 0x0006) += seg; // 1611 -> 17fe
    memory16(0x0f20 + seg, 0x000d) += seg; // 1573 -> 1760
    memory16(0x0f22 + seg, 0x0001) += seg; // 1842 -> 1a2f
    memory16(0x0f23 + seg, 0x0008) += seg; // 1651 -> 183e
    memory16(0x0f24 + seg, 0x000a) += seg; // 1842 -> 1a2f
    memory16(0x0f25 + seg, 0x000c) += seg; // 1842 -> 1a2f
    memory16(0x0f26 + seg, 0x000e) += seg; // 1842 -> 1a2f
    memory16(0x0f28 + seg, 0x0000) += seg; // 1842 -> 1a2f
    memory16(0x0f29 + seg, 0x0002) += seg; // 1842 -> 1a2f
    memory16(0x0f2a + seg, 0x0002) += seg; // 1842 -> 1a2f
    memory16(0x0f2b + seg, 0x0002) += seg; // 1842 -> 1a2f
    memory16(0x0f2c + seg, 0x0002) += seg; // 1842 -> 1a2f
    memory16(0x0f2e + seg, 0x0005) += seg; // 1842 -> 1a2f
    memory16(0x0f2f + seg, 0x0003) += seg; // 1611 -> 17fe
    memory16(0x0f31 + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0f33 + seg, 0x0003) += seg; // 1095 -> 1282
    memory16(0x0f36 + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0f39 + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x0f3a + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0f3c + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x0f40 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0f44 + seg, 0x000a) += seg; // 1095 -> 1282
    memory16(0x0f4c + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0f4d + seg, 0x000e) += seg; // 1095 -> 1282
    memory16(0x0f4f + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0f50 + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x0f52 + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x0f53 + seg, 0x000b) += seg; // 1095 -> 1282
    memory16(0x0f55 + seg, 0x0004) += seg; // 1095 -> 1282
    memory16(0x0f56 + seg, 0x0001) += seg; // 180c -> 19f9
    memory16(0x0f58 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x0f5a + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0f5b + seg, 0x000e) += seg; // 1095 -> 1282
    memory16(0x0f5f + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0f60 + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x0f60 + seg, 0x000e) += seg; // 1095 -> 1282
    memory16(0x0f67 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x0f68 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0f69 + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0f69 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0f6b + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0f6c + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0f6d + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x0f6d + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x0f6e + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0f70 + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0f70 + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x0f71 + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x0f71 + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x0f71 + seg, 0x000a) += seg; // 1095 -> 1282
    memory16(0x0f74 + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0f7a + seg, 0x000a) += seg; // 1095 -> 1282
    memory16(0x0f7e + seg, 0x000a) += seg; // 1095 -> 1282
    memory16(0x0f80 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x0f81 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0f81 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0f82 + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x0f92 + seg, 0x000c) += seg; // 1573 -> 1760
    memory16(0x0f94 + seg, 0x0006) += seg; // 1842 -> 1a2f
    memory16(0x0f96 + seg, 0x0002) += seg; // 1651 -> 183e
    memory16(0x0f97 + seg, 0x0000) += seg; // 1611 -> 17fe
    memory16(0x0f98 + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0f9a + seg, 0x000d) += seg; // 1816 -> 1a03
    memory16(0x0f9c + seg, 0x0008) += seg; // 162a -> 1817
    memory16(0x0f9d + seg, 0x0006) += seg; // 1611 -> 17fe
    memory16(0x0fa1 + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0fa3 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0fa7 + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x0fac + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x0fad + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0fae + seg, 0x0004) += seg; // 1095 -> 1282
    memory16(0x0faf + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x0faf + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0fb1 + seg, 0x0004) += seg; // 1095 -> 1282
    memory16(0x0fb3 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0fb5 + seg, 0x000b) += seg; // 1095 -> 1282
    memory16(0x0fbe + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x0fc2 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0fc3 + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0fc4 + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x0fc4 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x0fc5 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x0fc5 + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0fc6 + seg, 0x000b) += seg; // 1095 -> 1282
    memory16(0x0fca + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x0fca + seg, 0x000b) += seg; // 1095 -> 1282
    memory16(0x0fcb + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x0fcd + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x0fcd + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0fce + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0fd0 + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x0fd1 + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x0fd3 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0fd7 + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x0fd9 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x0fdb + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x0fdc + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x0fe0 + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x0fe1 + seg, 0x000a) += seg; // 1095 -> 1282
    memory16(0x0fe2 + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x0fe2 + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x0fe2 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x0fe4 + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x0fe5 + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x0fe5 + seg, 0x000d) += seg; // 1095 -> 1282
    memory16(0x0fe6 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x0fe6 + seg, 0x000d) += seg; // 1095 -> 1282
    memory16(0x0ff4 + seg, 0x000d) += seg; // 1095 -> 1282
    memory16(0x0ff5 + seg, 0x0003) += seg; // 1095 -> 1282
    memory16(0x0ff7 + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x1002 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x1003 + seg, 0x000c) += seg; // 0000 -> 01ed
    memory16(0x1004 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x1007 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x1008 + seg, 0x0003) += seg; // 1095 -> 1282
    memory16(0x1026 + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x1027 + seg, 0x0004) += seg; // 1816 -> 1a03
    memory16(0x1028 + seg, 0x0001) += seg; // 1816 -> 1a03
    memory16(0x102f + seg, 0x0008) += seg; // 1816 -> 1a03
    memory16(0x1033 + seg, 0x0007) += seg; // 162a -> 1817
    memory16(0x103a + seg, 0x000b) += seg; // 162a -> 1817
    memory16(0x103b + seg, 0x0009) += seg; // 1611 -> 17fe
    memory16(0x1045 + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x104a + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x104b + seg, 0x0009) += seg; // 183f -> 1a2c
    memory16(0x104c + seg, 0x0006) += seg; // 183f -> 1a2c
    memory16(0x104e + seg, 0x0004) += seg; // 162a -> 1817
    memory16(0x1051 + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x1055 + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x1059 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x105c + seg, 0x0006) += seg; // 1611 -> 17fe
    memory16(0x106d + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x106e + seg, 0x0000) += seg; // 1095 -> 1282
    memory16(0x106f + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x1070 + seg, 0x0001) += seg; // 1816 -> 1a03
    memory16(0x1071 + seg, 0x0001) += seg; // 1611 -> 17fe
    memory16(0x1071 + seg, 0x0008) += seg; // 1095 -> 1282
    memory16(0x1079 + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x107d + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x107e + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x107e + seg, 0x0007) += seg; // 1095 -> 1282
    memory16(0x107e + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x107f + seg, 0x0002) += seg; // 1095 -> 1282
    memory16(0x107f + seg, 0x000b) += seg; // 1095 -> 1282
    memory16(0x1080 + seg, 0x0001) += seg; // 1095 -> 1282
    memory16(0x1082 + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x1083 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x1084 + seg, 0x0005) += seg; // 1095 -> 1282
    memory16(0x1087 + seg, 0x0003) += seg; // 1095 -> 1282
    memory16(0x1092 + seg, 0x000c) += seg; // 1095 -> 1282
    memory16(0x1093 + seg, 0x000f) += seg; // 1095 -> 1282
    memory16(0x1098 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x1099 + seg, 0x0008) += seg; // 18a4 -> 1a91
    memory16(0x109b + seg, 0x000e) += seg; // 1814 -> 1a01
    memory16(0x10a4 + seg, 0x0001) += seg; // 1814 -> 1a01
    memory16(0x10c0 + seg, 0x0001) += seg; // 18a4 -> 1a91
    memory16(0x10c1 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x10c4 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x10ca + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x10d1 + seg, 0x0006) += seg; // 1814 -> 1a01
    memory16(0x10d2 + seg, 0x000e) += seg; // 1814 -> 1a01
    memory16(0x10d7 + seg, 0x0009) += seg; // 1095 -> 1282
    memory16(0x10d9 + seg, 0x0001) += seg; // 1814 -> 1a01
    memory16(0x10e8 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x10ea + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x10ec + seg, 0x000c) += seg; // 183f -> 1a2c
    memory16(0x10ed + seg, 0x0009) += seg; // 183f -> 1a2c
    memory16(0x10ee + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x10f0 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x10f3 + seg, 0x0008) += seg; // 183f -> 1a2c
    memory16(0x10f4 + seg, 0x0005) += seg; // 183f -> 1a2c
    memory16(0x10f7 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x10fe + seg, 0x0008) += seg; // 183f -> 1a2c
    memory16(0x10ff + seg, 0x0005) += seg; // 183f -> 1a2c
    memory16(0x1100 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x1123 + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x1124 + seg, 0x000b) += seg; // 183f -> 1a2c
    memory16(0x1125 + seg, 0x0008) += seg; // 183f -> 1a2c
    memory16(0x1127 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x112a + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x112c + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x112e + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x1130 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x1132 + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x1133 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x1135 + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x1137 + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x1139 + seg, 0x0003) += seg; // 169c -> 1889
    memory16(0x113a + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x113c + seg, 0x0000) += seg; // 169c -> 1889
    memory16(0x113c + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x113e + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x1140 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1157 + seg, 0x0006) += seg; // 1095 -> 1282
    memory16(0x115d + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x115e + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x115f + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1160 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1164 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x1169 + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x116b + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x116c + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x116d + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x1171 + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x1175 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x117c + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x117d + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1182 + seg, 0x0004) += seg; // 183f -> 1a2c
    memory16(0x1183 + seg, 0x0008) += seg; // 167c -> 1869
    memory16(0x1184 + seg, 0x0005) += seg; // 169c -> 1889
    memory16(0x1188 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x118a + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x118c + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x118e + seg, 0x0009) += seg; // 183f -> 1a2c
    memory16(0x118f + seg, 0x0006) += seg; // 183f -> 1a2c
    memory16(0x1191 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x1193 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x1195 + seg, 0x000c) += seg; // 183f -> 1a2c
    memory16(0x1196 + seg, 0x0009) += seg; // 183f -> 1a2c
    memory16(0x1198 + seg, 0x000d) += seg; // 183f -> 1a2c
    memory16(0x1199 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x119a + seg, 0x000c) += seg; // 0000 -> 01ed
    memory16(0x119c + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x119e + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x119f + seg, 0x000f) += seg; // 183f -> 1a2c
    memory16(0x11a0 + seg, 0x000c) += seg; // 183f -> 1a2c
    memory16(0x11a5 + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x11a7 + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x11a8 + seg, 0x000f) += seg; // 0000 -> 01ed
    memory16(0x11aa + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x11ad + seg, 0x0003) += seg; // 183f -> 1a2c
    memory16(0x11ad + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x11af + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x11b4 + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x11b8 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x11ba + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x11c5 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x11c5 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x11cb + seg, 0x000d) += seg; // 169e -> 188b
    memory16(0x11d1 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x11d1 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x11d5 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x11d8 + seg, 0x0006) += seg; // 188a -> 1a77
    memory16(0x11d9 + seg, 0x000a) += seg; // 1573 -> 1760
    memory16(0x11db + seg, 0x0007) += seg; // 162a -> 1817
    memory16(0x11dd + seg, 0x0009) += seg; // 1886 -> 1a73
    memory16(0x11e0 + seg, 0x000a) += seg; // 1611 -> 17fe
    memory16(0x11e1 + seg, 0x000e) += seg; // 1573 -> 1760
    memory16(0x11e3 + seg, 0x0009) += seg; // 162a -> 1817
    memory16(0x11e5 + seg, 0x000b) += seg; // 1886 -> 1a73
    memory16(0x11e8 + seg, 0x0009) += seg; // 1611 -> 17fe
    memory16(0x11e9 + seg, 0x000b) += seg; // 1573 -> 1760
    memory16(0x11eb + seg, 0x0005) += seg; // 1778 -> 1965
    memory16(0x11ed + seg, 0x0002) += seg; // 15be -> 17ab
    memory16(0x11ee + seg, 0x0009) += seg; // 162a -> 1817
    memory16(0x11f0 + seg, 0x0000) += seg; // 162a -> 1817
    memory16(0x11f1 + seg, 0x0006) += seg; // 15be -> 17ab
    memory16(0x11f7 + seg, 0x0002) += seg; // 162a -> 1817
    memory16(0x11f9 + seg, 0x0000) += seg; // 1611 -> 17fe
    memory16(0x11fc + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x11fd + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x11fe + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x11ff + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1200 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1201 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1202 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1203 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1204 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1205 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1206 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1207 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1208 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1209 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x120a + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x120f + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1210 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1211 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1212 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1213 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1214 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1215 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1216 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1217 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1218 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1219 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x121a + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x121e + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x121f + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1220 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1221 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1222 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1223 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1224 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1225 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1226 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1227 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1228 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1229 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x122e + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x122f + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1230 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1231 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1232 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1233 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1234 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1239 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x123a + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x123b + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x123c + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x123d + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x123e + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x123f + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x1240 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x1241 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x1242 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x1243 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1248 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x1249 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x124a + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x124b + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x124d + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x124e + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x124f + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1251 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x1252 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x1253 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1258 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x1259 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x125a + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x125c + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x125d + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x125e + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1260 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x1264 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x1265 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x1267 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1268 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x1269 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x126a + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x126c + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x126d + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x1271 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1272 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1274 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x1275 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1276 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x1277 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x1279 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x127a + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x127f + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x1280 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1281 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1283 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x1284 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x1285 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x128a + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x128b + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x128c + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x128d + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x128f + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x1290 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1291 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x1292 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1294 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x12a0 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x12a2 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x12a3 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x12a9 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x12aa + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x12ab + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x12ad + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x12ae + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x12b0 + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x12b1 + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x12b3 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x12b4 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x12b6 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x12b7 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x12b9 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x12ba + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x12f0 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x12f2 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x12f3 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x12f4 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x12f5 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x12f7 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x12f8 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x12f9 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x12fa + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x12fc + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x12fd + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x1301 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x1302 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1303 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x1305 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x1306 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x1307 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1308 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x130a + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x130b + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x130c + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x130d + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x1310 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x1312 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x1314 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x1316 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x1318 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x131a + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x131d + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x131e + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x131f + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x1320 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x1321 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x1326 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1327 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1328 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1329 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x132a + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x132b + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x132c + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x132d + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1333 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1334 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1335 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1336 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1337 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1338 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1339 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x133f + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1340 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1341 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1342 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1343 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1345 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x1346 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x1347 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x134e + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x134f + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x1350 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x1351 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x1352 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x1353 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x1359 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x135a + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x135b + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x135c + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x135d + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x135e + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x135f + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x1360 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x1367 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1368 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1369 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x136a + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x136b + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x136c + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x136d + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x136e + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x136f + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1370 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1371 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1372 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1376 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1377 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1378 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1379 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x137a + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x137b + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x137c + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x137d + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x137e + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x137f + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1380 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1381 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1382 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1383 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1384 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1389 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x138a + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x138b + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x138c + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x138d + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x138e + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x138f + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1390 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1391 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1392 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1393 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1398 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x1399 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x139a + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x139b + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x139c + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x139d + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x139e + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x139f + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x13a0 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x13a1 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x13a5 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13a6 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13a7 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13a8 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13a9 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13aa + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13ab + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13ac + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13ad + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13ae + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13af + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x13b4 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13b5 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13b6 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13b7 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13b8 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13b9 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13ba + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13bb + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13bc + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13bd + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13be + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x13c3 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13c4 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13c5 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13c6 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13c7 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13c8 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13c9 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13ca + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13cb + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13cc + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13cd + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13d4 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x13d5 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13d6 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13d7 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13dc + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x13e0 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13e1 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13e2 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x13e5 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x13e6 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x13e7 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x13e9 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x13fe + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x13ff + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x1407 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x1415 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x1417 + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x1418 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x1419 + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x1421 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x1422 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x1423 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x1424 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x1425 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x142d + seg, 0x0003) += seg; // 1573 -> 1760
    memory16(0x1432 + seg, 0x0008) += seg; // 169e -> 188b
    memory16(0x1434 + seg, 0x0006) += seg; // 169e -> 188b
    memory16(0x1436 + seg, 0x0004) += seg; // 169e -> 188b
    memory16(0x1438 + seg, 0x0002) += seg; // 169e -> 188b
    memory16(0x143a + seg, 0x0000) += seg; // 169e -> 188b
    memory16(0x143b + seg, 0x000e) += seg; // 169e -> 188b
    memory16(0x143d + seg, 0x000c) += seg; // 169e -> 188b
    memory16(0x143f + seg, 0x000a) += seg; // 169e -> 188b
    memory16(0x1441 + seg, 0x0008) += seg; // 169e -> 188b
    memory16(0x1442 + seg, 0x0009) += seg; // 15d3 -> 17c0
    memory16(0x1443 + seg, 0x0009) += seg; // 15d3 -> 17c0
    memory16(0x1444 + seg, 0x0009) += seg; // 15d3 -> 17c0
    memory16(0x1445 + seg, 0x0009) += seg; // 15d3 -> 17c0
    memory16(0x1446 + seg, 0x0009) += seg; // 15d3 -> 17c0
    memory16(0x1447 + seg, 0x0009) += seg; // 15d3 -> 17c0
    memory16(0x1448 + seg, 0x0009) += seg; // 15d3 -> 17c0
    memory16(0x1449 + seg, 0x0009) += seg; // 15d3 -> 17c0
    memory16(0x144c + seg, 0x0000) += seg; // 177f -> 196c
    memory16(0x144d + seg, 0x0008) += seg; // 177f -> 196c
    memory16(0x144f + seg, 0x0005) += seg; // 177f -> 196c
    memory16(0x1450 + seg, 0x0009) += seg; // 1611 -> 17fe
    memory16(0x1452 + seg, 0x0003) += seg; // 1573 -> 1760
    memory16(0x1453 + seg, 0x0009) += seg; // 16c2 -> 18af
    memory16(0x1454 + seg, 0x000d) += seg; // 16c2 -> 18af
    memory16(0x1456 + seg, 0x0001) += seg; // 16c2 -> 18af
    memory16(0x1457 + seg, 0x0005) += seg; // 16c2 -> 18af
    memory16(0x1458 + seg, 0x0009) += seg; // 16c2 -> 18af
    memory16(0x1459 + seg, 0x000d) += seg; // 16c2 -> 18af
    memory16(0x145a + seg, 0x000f) += seg; // 16c2 -> 18af
    memory16(0x145c + seg, 0x0001) += seg; // 16c2 -> 18af
    memory16(0x145e + seg, 0x0005) += seg; // 177c -> 1969
    memory16(0x145f + seg, 0x0008) += seg; // 177c -> 1969
    memory16(0x1461 + seg, 0x0005) += seg; // 177c -> 1969
    memory16(0x1462 + seg, 0x0009) += seg; // 1611 -> 17fe
    memory16(0x1463 + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x1463 + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x1465 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x1469 + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x146a + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x146c + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x146d + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x146e + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x146f + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x1471 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1472 + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x1473 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1475 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x1476 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1477 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x1478 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x1479 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x147b + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x1480 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x1481 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x1484 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x148b + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x148c + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x148d + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x148e + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x148f + seg, 0x0000) += seg; // 0104 -> 02f1
    memory16(0x1490 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x1491 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x1492 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1493 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x1494 + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x1495 + seg, 0x0009) += seg; // 0104 -> 02f1
    memory16(0x1496 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x1497 + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x1498 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x1499 + seg, 0x000f) += seg; // 0104 -> 02f1
    memory16(0x149b + seg, 0x0002) += seg; // 0104 -> 02f1
    memory16(0x149c + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x149d + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x149e + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x149f + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x14a0 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x14a1 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x14a3 + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x14a4 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x14a5 + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x14a6 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x14a9 + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x14aa + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x14ab + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x14ac + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x14ad + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x14b1 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x14b2 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x14b3 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x14b4 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x14b5 + seg, 0x000a) += seg; // 0104 -> 02f1
    memory16(0x14b8 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x14b9 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x14ba + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x14bb + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x14bf + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x14c0 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x14c1 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x14c2 + seg, 0x0003) += seg; // 0104 -> 02f1
    memory16(0x14c5 + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x14c8 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x14c9 + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x14ca + seg, 0x0005) += seg; // 0104 -> 02f1
    memory16(0x14e5 + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x14ea + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14eb + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14ec + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14ed + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14ee + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14ef + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14f0 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14f1 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14f2 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14f3 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14f4 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14f5 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14f6 + seg, 0x0006) += seg; // 0104 -> 02f1
    memory16(0x14f8 + seg, 0x0001) += seg; // 183f -> 1a2c
    memory16(0x14f8 + seg, 0x000e) += seg; // 183f -> 1a2c
    memory16(0x14f9 + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x14fa + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x14fc + seg, 0x000b) += seg; // 0104 -> 02f1
    memory16(0x14fd + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1500 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x1501 + seg, 0x000d) += seg; // 183f -> 1a2c
    memory16(0x1502 + seg, 0x000a) += seg; // 183f -> 1a2c
    memory16(0x1503 + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x1503 + seg, 0x000d) += seg; // 0104 -> 02f1
    memory16(0x1506 + seg, 0x0004) += seg; // 0104 -> 02f1
    memory16(0x150a + seg, 0x0007) += seg; // 0104 -> 02f1
    memory16(0x150b + seg, 0x000c) += seg; // 0104 -> 02f1
    memory16(0x150e + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x1510 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x1512 + seg, 0x000e) += seg; // 0104 -> 02f1
    memory16(0x1518 + seg, 0x0001) += seg; // 183f -> 1a2c
    memory16(0x1518 + seg, 0x000e) += seg; // 183f -> 1a2c
    memory16(0x1519 + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x151a + seg, 0x0001) += seg; // 0104 -> 02f1
    memory16(0x151c + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x151d + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x151e + seg, 0x0008) += seg; // 0104 -> 02f1
    memory16(0x1520 + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x1527 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x152b + seg, 0x000e) += seg; // 152b -> 1718
    memory16(0x152e + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x1535 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x1539 + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x153b + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x153e + seg, 0x000d) += seg; // 155c -> 1749
    memory16(0x1545 + seg, 0x000b) += seg; // 155c -> 1749
    memory16(0x154e + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x1551 + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x155a + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x1560 + seg, 0x000f) += seg; // 1571 -> 175e
    memory16(0x1566 + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x1567 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x156a + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x156c + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x156d + seg, 0x000c) += seg; // 0000 -> 01ed
    memory16(0x1572 + seg, 0x000c) += seg; // 1521 -> 170e
    memory16(0x1580 + seg, 0x0002) += seg; // 1623 -> 1810
    memory16(0x1586 + seg, 0x0002) += seg; // 159f -> 178c
    memory16(0x1589 + seg, 0x0005) += seg; // 15fb -> 17e8
    memory16(0x158c + seg, 0x0009) += seg; // 15fc -> 17e9
    memory16(0x158d + seg, 0x000b) += seg; // 1611 -> 17fe
    memory16(0x1599 + seg, 0x000f) += seg; // 1611 -> 17fe
    memory16(0x15a1 + seg, 0x0005) += seg; // 1521 -> 170e
    memory16(0x15a6 + seg, 0x0008) += seg; // 1521 -> 170e
    memory16(0x15a7 + seg, 0x0006) += seg; // 16a8 -> 1895
    memory16(0x15aa + seg, 0x0003) += seg; // 1521 -> 170e
    memory16(0x15ac + seg, 0x000f) += seg; // 1621 -> 180e
    memory16(0x15b0 + seg, 0x0001) += seg; // 15b9 -> 17a6
    memory16(0x15b1 + seg, 0x0005) += seg; // 15f8 -> 17e5
    memory16(0x15b4 + seg, 0x0000) += seg; // 15f8 -> 17e5
    memory16(0x15b6 + seg, 0x000e) += seg; // 16a8 -> 1895
    memory16(0x15be + seg, 0x0004) += seg; // 1521 -> 170e
    memory16(0x15c4 + seg, 0x0005) += seg; // 16b1 -> 189e
    memory16(0x15ca + seg, 0x000e) += seg; // 1679 -> 1866
    memory16(0x15cd + seg, 0x0006) += seg; // 16b1 -> 189e
    memory16(0x15cf + seg, 0x000a) += seg; // 1679 -> 1866
    memory16(0x15d6 + seg, 0x0004) += seg; // 16b1 -> 189e
    memory16(0x15db + seg, 0x0004) += seg; // 1643 -> 1830
    memory16(0x15e1 + seg, 0x000c) += seg; // 15d3 -> 17c0
    memory16(0x15eb + seg, 0x0002) += seg; // 15fb -> 17e8
    memory16(0x15ee + seg, 0x0006) += seg; // 15fc -> 17e9
    memory16(0x15f1 + seg, 0x0001) += seg; // 164f -> 183c
    memory16(0x15f2 + seg, 0x0007) += seg; // 16aa -> 1897
    memory16(0x15fb + seg, 0x0000) += seg; // 1521 -> 170e
    memory16(0x1604 + seg, 0x0006) += seg; // 15be -> 17ab
    memory16(0x1606 + seg, 0x0004) += seg; // 1746 -> 1933
    memory16(0x160a + seg, 0x0006) += seg; // 1626 -> 1813
    memory16(0x160b + seg, 0x000a) += seg; // 152b -> 1718
    memory16(0x1614 + seg, 0x0006) += seg; // 16b1 -> 189e
    memory16(0x1616 + seg, 0x000c) += seg; // 1746 -> 1933
    memory16(0x1618 + seg, 0x0006) += seg; // 161e -> 180b
    memory16(0x161c + seg, 0x0005) += seg; // 168c -> 1879
    memory16(0x161c + seg, 0x000c) += seg; // 1697 -> 1884
    memory16(0x161f + seg, 0x0007) += seg; // 1521 -> 170e
    memory16(0x1620 + seg, 0x0009) += seg; // 1621 -> 180e
    memory16(0x1623 + seg, 0x0000) += seg; // 1521 -> 170e
    memory16(0x1625 + seg, 0x000f) += seg; // 1611 -> 17fe
    memory16(0x1629 + seg, 0x0007) += seg; // 16b1 -> 189e
    memory16(0x1633 + seg, 0x0002) += seg; // 164f -> 183c
    memory16(0x1638 + seg, 0x000b) += seg; // 15d3 -> 17c0
    memory16(0x163d + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x1646 + seg, 0x0009) += seg; // 164f -> 183c
    memory16(0x164b + seg, 0x000a) += seg; // 164f -> 183c
    memory16(0x164d + seg, 0x000f) += seg; // 1679 -> 1866
    memory16(0x1651 + seg, 0x0006) += seg; // 1521 -> 170e
    memory16(0x1653 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x1656 + seg, 0x0002) += seg; // 16c2 -> 18af
    memory16(0x1659 + seg, 0x0003) += seg; // 16c2 -> 18af
    memory16(0x165d + seg, 0x0009) += seg; // 1670 -> 185d
    memory16(0x1667 + seg, 0x000f) += seg; // 1670 -> 185d
    memory16(0x166e + seg, 0x0002) += seg; // 1670 -> 185d
    memory16(0x1672 + seg, 0x000a) += seg; // 1679 -> 1866
    memory16(0x1675 + seg, 0x0002) += seg; // 1521 -> 170e
    memory16(0x1676 + seg, 0x0008) += seg; // 16a8 -> 1895
    memory16(0x167b + seg, 0x000d) += seg; // 1521 -> 170e
    memory16(0x168e + seg, 0x0008) += seg; // 1698 -> 1885
    memory16(0x1690 + seg, 0x0005) += seg; // 167c -> 1869
    memory16(0x1691 + seg, 0x0007) += seg; // 1698 -> 1885
    memory16(0x1695 + seg, 0x000d) += seg; // 1675 -> 1862
    memory16(0x1698 + seg, 0x0006) += seg; // 1521 -> 170e
    memory16(0x16a2 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x16aa + seg, 0x0001) += seg; // 1521 -> 170e
    memory16(0x16b0 + seg, 0x000f) += seg; // 1521 -> 170e
    memory16(0x16bd + seg, 0x0006) += seg; // 165a -> 1847
    memory16(0x16c0 + seg, 0x0003) += seg; // 16c2 -> 18af
    memory16(0x16c1 + seg, 0x000d) += seg; // 16ee -> 18db
    memory16(0x16c3 + seg, 0x000a) += seg; // 16c2 -> 18af
    memory16(0x16c8 + seg, 0x0008) += seg; // 16b1 -> 189e
    memory16(0x16ce + seg, 0x000e) += seg; // 16b1 -> 189e
    memory16(0x16d3 + seg, 0x0005) += seg; // 15fb -> 17e8
    memory16(0x16d6 + seg, 0x0009) += seg; // 15fc -> 17e9
    memory16(0x16d9 + seg, 0x0007) += seg; // 1670 -> 185d
    memory16(0x16db + seg, 0x0006) += seg; // 1670 -> 185d
    memory16(0x16e6 + seg, 0x000e) += seg; // 16b1 -> 189e
    memory16(0x16e8 + seg, 0x000e) += seg; // 1670 -> 185d
    memory16(0x171b + seg, 0x0000) += seg; // 167c -> 1869
    memory16(0x172d + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x1744 + seg, 0x0003) += seg; // 1744 -> 1931
    memory16(0x1745 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x1747 + seg, 0x0001) += seg; // 1746 -> 1933
    memory16(0x1748 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x1754 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x1756 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x1758 + seg, 0x0006) += seg; // 152b -> 1718
    memory16(0x175a + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x175b + seg, 0x0005) += seg; // 155c -> 1749
    memory16(0x1760 + seg, 0x0002) += seg; // 152b -> 1718
    memory16(0x1761 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x1764 + seg, 0x000f) += seg; // 155c -> 1749
    memory16(0x1766 + seg, 0x0000) += seg; // 155c -> 1749
    memory16(0x1769 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x176d + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x1775 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x177c + seg, 0x0005) += seg; // 1521 -> 170e
    memory16(0x177d + seg, 0x0002) += seg; // 16c2 -> 18af
    memory16(0x177e + seg, 0x000d) += seg; // 16ee -> 18db
    memory16(0x1780 + seg, 0x0008) += seg; // 188f -> 1a7c
    memory16(0x1781 + seg, 0x0000) += seg; // 15d3 -> 17c0
    memory16(0x1781 + seg, 0x000a) += seg; // 179e -> 198b
    memory16(0x1782 + seg, 0x000f) += seg; // 18a0 -> 1a8d
    memory16(0x1783 + seg, 0x0009) += seg; // 18a0 -> 1a8d
    memory16(0x1787 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x178c + seg, 0x0008) += seg; // 1896 -> 1a83
    memory16(0x178d + seg, 0x0008) += seg; // 1896 -> 1a83
    memory16(0x178e + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x178f + seg, 0x000c) += seg; // 0000 -> 01ed
    memory16(0x1793 + seg, 0x000b) += seg; // 184d -> 1a3a
    memory16(0x1795 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x1798 + seg, 0x0003) += seg; // 16ee -> 18db
    memory16(0x179c + seg, 0x0000) += seg; // 1841 -> 1a2e
    memory16(0x17b8 + seg, 0x0005) += seg; // 17ee -> 19db
    memory16(0x17c4 + seg, 0x000f) += seg; // 0000 -> 01ed
    memory16(0x17c8 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x17c9 + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x17c9 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x1819 + seg, 0x0008) += seg; // 15d3 -> 17c0
    memory16(0x181c + seg, 0x0008) += seg; // 15d3 -> 17c0
    memory16(0x181f + seg, 0x000e) += seg; // 1867 -> 1a54
    memory16(0x1822 + seg, 0x0001) += seg; // 1896 -> 1a83
    memory16(0x1822 + seg, 0x0009) += seg; // 1867 -> 1a54
    memory16(0x1825 + seg, 0x0009) += seg; // 1896 -> 1a83
    memory16(0x1826 + seg, 0x0007) += seg; // 1867 -> 1a54
    memory16(0x1828 + seg, 0x000d) += seg; // 1884 -> 1a71
    memory16(0x182a + seg, 0x0008) += seg; // 1827 -> 1a14
    memory16(0x1834 + seg, 0x0005) += seg; // 1521 -> 170e
    memory16(0x1836 + seg, 0x0008) += seg; // 1867 -> 1a54
    memory16(0x1838 + seg, 0x000a) += seg; // 1867 -> 1a54
    memory16(0x183c + seg, 0x0008) += seg; // 1896 -> 1a83
    memory16(0x183d + seg, 0x0003) += seg; // 1896 -> 1a83
    memory16(0x183e + seg, 0x0002) += seg; // 1867 -> 1a54
    memory16(0x1842 + seg, 0x0007) += seg; // 1782 -> 196f
    memory16(0x1845 + seg, 0x000a) += seg; // 16c2 -> 18af
    memory16(0x1848 + seg, 0x000d) += seg; // 16c2 -> 18af
    memory16(0x184c + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x1856 + seg, 0x0000) += seg; // 1835 -> 1a22
    memory16(0x1858 + seg, 0x0006) += seg; // 181e -> 1a0b
    memory16(0x185c + seg, 0x0001) += seg; // 181e -> 1a0b
    memory16(0x185f + seg, 0x0002) += seg; // 1835 -> 1a22
    memory16(0x1861 + seg, 0x0008) += seg; // 181e -> 1a0b
    memory16(0x1865 + seg, 0x0003) += seg; // 181e -> 1a0b
    memory16(0x1867 + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x186d + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x186f + seg, 0x000e) += seg; // 18a0 -> 1a8d
    memory16(0x1876 + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x1879 + seg, 0x000a) += seg; // 0000 -> 01ed
    memory16(0x187b + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x187e + seg, 0x0008) += seg; // 1896 -> 1a83
    memory16(0x188e + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x18a0 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x18c1 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18c1 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18c2 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18c2 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18c2 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18c2 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18c3 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18c3 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18c3 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18c3 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18c4 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18c4 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18c4 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18c4 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18c5 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18c5 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18c5 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18c5 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18c6 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18c6 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18c6 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18c6 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18c7 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18c7 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18c7 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18c7 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18c8 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18c8 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18c8 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18c8 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18c9 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18c9 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18c9 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18c9 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18ca + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18ca + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18ca + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18ca + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18cb + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18cb + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18cb + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18cb + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18cc + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18cc + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18cc + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18cc + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18cd + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18cd + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18cd + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18cd + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18ce + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18ce + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18ce + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18ce + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18cf + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18cf + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18cf + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18cf + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d0 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d0 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18d0 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18d0 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d1 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d1 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18d1 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18d1 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d2 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d2 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18d2 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18d2 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d3 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d3 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18d3 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18d3 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d4 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d4 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18d4 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18d4 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d5 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d5 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18d5 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18d5 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d6 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d6 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18d6 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18d6 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d7 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d7 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18d7 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18d7 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d8 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d8 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18d8 + seg, 0x000a) += seg; // 18a4 -> 1a91
    memory16(0x18d8 + seg, 0x000e) += seg; // 18a4 -> 1a91
    memory16(0x18d9 + seg, 0x0002) += seg; // 18a4 -> 1a91
    memory16(0x18d9 + seg, 0x0006) += seg; // 18a4 -> 1a91
    memory16(0x18fb + seg, 0x0000) += seg; // 18a4 -> 1a91
    memory16(0x18fb + seg, 0x0004) += seg; // 18a4 -> 1a91
    memory16(0x1c6a + seg, 0x000e) += seg; // 1524 -> 1711
    memory16(0x1c6b + seg, 0x0002) += seg; // 1524 -> 1711
    memory16(0x1c6b + seg, 0x0006) += seg; // 1524 -> 1711
    memory16(0x1cae + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x1cae + seg, 0x000c) += seg; // 0000 -> 01ed
    memory16(0x1caf + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x1caf + seg, 0x0004) += seg; // 0000 -> 01ed
}
// 01ed:01c7 Terminator reached
// 01ed:01c7 Terminator reached
void sub_1ed0();
void sub_1fdd();
void sub_1fff();
void sub_2042();
void sub_206f();
void sub_2077();
void sub_209d();
void sub_20b6();
void sub_20c6();
void sub_20d6();
void sub_212d();
void sub_2146();
void sub_21b0();
void sub_221a();
void sub_226a();
void sub_22d4();
void sub_22e0();
void sub_250b();
void sub_274f();
void sub_29fe();
void sub_2a6b();
void sub_2af9();
void sub_2b69();
void sub_2bad();
void sub_2c08();
void sub_2c29();
void sub_2c69();
void sub_2c98();
void sub_2cad();
void sub_2cbc();
void sub_2cdd();
void sub_2d97();
void sub_2e3a();
void sub_2e50();
void sub_2e5f();
void sub_2e7b();
void sub_2f10();
void sub_2f32();
void sub_2fcb();
void sub_3088();
void sub_3271();
void sub_32c6();
void sub_33ae();
void sub_3448();
void sub_3479();
void sub_34b4();
void sub_3530();
void sub_358f();
void sub_35ca();
void sub_3756();
void sub_37ec();
void sub_3a24();
void sub_3d13();
void sub_3dc8();
void sub_3ea5();
void sub_3f41();
void sub_4141();
void sub_4175();
void sub_4339();
void sub_4380();
void sub_443a();
void sub_45b4();
void sub_4750();
void sub_4873();
void sub_4923();
void sub_4943();
void sub_6284();
void sub_a84c();
void sub_ced3();
void sub_cf64();
void sub_cff3();
void sub_d082();
void sub_d29a();
void sub_d304();
void sub_d3cc();
void sub_d42a();
void sub_d48e();
void sub_d595();
void sub_d5b5();
void sub_d61c();
void sub_d74a();
void sub_d841();
void sub_d97d();
void sub_dbad();
void sub_efca();
void sub_f1b8();
void sub_f1df();
void sub_f226();
void sub_f3bb();
void sub_f414();
void sub_f47e();
void sub_f4bb();
void sub_f4f8();
void sub_f58c();
void sub_f8b7();
void sub_f8d2();
void sub_f95e();
void sub_fadf();
void sub_10843();
void sub_10c66();
void sub_10cd2();
void sub_10f02();
void sub_10f14();
void sub_10f20();
void sub_10f76();
void sub_110af();
void sub_111ca();
void sub_113e1();
void sub_11467();
void sub_11472();
void sub_1155c();
void sub_11564();
void sub_11574();
void sub_115b3();
void sub_115fa();
void sub_11704();
void sub_1178b();
void sub_117eb();
void sub_11846();
void sub_118ac();
void sub_11aea();
void sub_11d42();
void sub_11e52();
void sub_11f58();
void sub_12119();
void sub_12332();
void sub_1236a();
void sub_1249c();
void sub_12587();
void sub_12749();
void sub_12798();
void sub_12820();
void sub_12842();
void sub_12882();
void sub_12919();
void sub_12931();
void sub_12a21();
void sub_12b5a();
void sub_12b72();
void sub_12bbf();
void sub_12c3f();
void sub_12c6e();
void sub_12c75();
void sub_12cb0();
void sub_12d00();
void sub_12d0f();
void sub_12d22();
void sub_12d3b();
void sub_12d6d();
void sub_12d90();
void sub_12dc4();
void sub_12de7();
void sub_12def();
void sub_12df7();
void sub_12e5c();
void sub_12ead();
void sub_12ef2();
void sub_12f7b();
void sub_1310d();
void sub_132e3();
void sub_133a1();
void sub_136e6();
void sub_1375e();
void sub_137cc();
void sub_137e1();
void sub_1383f();
void sub_1384a();
void sub_138e4();
void sub_138ef();
void sub_13990();
void sub_1399b();
void sub_139c9();
void sub_13b11();
void sub_13c31();
void sub_13df5();
void sub_13dfe();
void sub_13e6e();
void sub_1482b();
void sub_14863();
void sub_14897();
void sub_148a4();
void sub_14b63();
void sub_14c93();
void sub_14dad();
void sub_15106();
void sub_15bc2();
void sub_15bec();
void sub_15c59();
void sub_15d6e();
void sub_15dac();
void sub_15e00();
void sub_15f66();
void sub_15fad();
void sub_16001();
void sub_16190();
void sub_163e0();
void sub_16500();
void sub_16b30();
void sub_16cfb();
void sub_16d51();
void sub_16e3d();
void sub_16ed9();
void sub_170e3();
void sub_1711f();
void sub_17181();
void sub_17196();
void sub_171fe();
void sub_172ae();
void sub_1731c();
void sub_17382();
void sub_17491();
void sub_17521();
void sub_17568();
void sub_175e3();
void sub_17603();
void sub_176f5();
void sub_177ce();
void sub_1781b();
void sub_178ce();
void sub_178ed();
void sub_17901();
void sub_17a6e();
void sub_17abb();
void sub_17b09();
void sub_17c08();
void sub_17c48();
void sub_17cda();
void sub_17cf4();
void sub_17e59();
void sub_17e86();
void sub_17e9e();
void sub_17fe0();
void sub_180b0();
void sub_180e1();
void sub_1813f();
void sub_18179();
void sub_18283();
void sub_18307();
void sub_183cc();
void sub_183ec();
void sub_18476();
void sub_185dc();
void sub_18667();
void sub_18694();
void sub_18745();
void sub_18790();
void sub_18840();
void sub_1885c();
void sub_1889e();
void sub_188b9();
void sub_188e2();
void sub_18956();
void sub_18977();
void sub_189e7();
void sub_18acf();
void sub_18af3();
void sub_18b12();
void sub_18ccd();
void sub_18de9();
void sub_18e0a();
void sub_18e13();
void sub_19310();
void sub_19318();
void sub_19335();
void sub_19347();
void sub_193e6();
void sub_1945e();
void sub_19543();
void sub_1960f();
void sub_19659();
void sub_1969e();
void sub_196c3();
void sub_19859();
void sub_198b7();
void sub_198cc();
void sub_199e7();
void sub_19a15();
void sub_19bd5();
void sub_19c17();
void sub_19dbf();
void sub_19ded();
void sub_19f91();
void sub_1a01b();
void sub_1a02d();
void sub_1a03e();
void sub_1a14f();
void sub_1a183();
void sub_1a2cc();
void sub_1a2fd();
void sub_1a383();
void sub_1a71c();
void sub_1a739();
void sub_1a773();
void sub_1a798();
void sub_1a7c8();

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    switch (seg*0x10000+ofs)
    {
        case 0x1ed019f: sub_206f(); return;
        case 0x1ed0dec: sub_2cbc(); return;
        case 0x1ed0f80: sub_2e50(); return;
        case 0x2f11031: sub_3f41(); return;
        case 0x2f11265: sub_4175(); return;
        case 0x2f1e562: sub_11472(); return;
        case 0x2f1e64c: sub_1155c(); return;
        case 0x2f1e654: sub_11564(); return;
        case 0x2f1e664: sub_11574(); return;
        case 0x2f1e6a3: sub_115b3(); return;
        case 0x17c000f4: sub_17cf4(); return;
        case 0x1813000f: sub_1813f(); return;
        case 0x18af01dd: sub_18ccd(); return;
        case 0x198b0137: sub_199e7(); return;
        case 0x198b0165: sub_19a15(); return;
        case 0x198b0325: sub_19bd5(); return;
        case 0x198b0367: sub_19c17(); return;
        case 0x1a7c0008: sub_1a7c8(); return;
        default:
            break;
    }
    assert(0);
}
// 01ed:01c7 Terminator reached
// 01ed:01c7 Terminator reached
// 01ed:01c7 Terminator reached
// 01ed:01c7 Terminator reached
// INJECT: Error: cannot inject zero flag in sub_2af9()!
// INJECT: Error: cannot inject carry flag in sub_2af9()!
// 01ed:01c7 Terminator reached
void sub_1ed0() // 01ed:0000
{
    dx = 0x1a91;
    memoryASet16(cs, 0x01c7, dx);
    ah = 0x30;
    interrupt(0x21);
    bp = memoryAGet16(ds, 0x0002);
    bx = memoryAGet16(ds, 0x002c);
    ds = dx;
    memoryASet16(ds, 0x007d, ax);
    memoryASet16(ds, 0x007b, es);
    memoryASet16(ds, 0x0077, bx);
    memoryASet16(ds, 0x0091, bp);
    memoryASet16(ds, 0x0081, 0xffff);
    sub_1fff(); // 01ed:012f
    di = memoryAGet16(ds, 0x0075);
    es = memoryAGet16(ds, 0x0075 + 2);
    ax = di;
    bx = ax;
    cx = 0x7fff;
loc_1f09: // 01ed:0039
    if (memoryAGet16(es, di) != 0x3738)
        goto loc_1f29;
    dx = memoryAGet16(es, di + 2);
    if (dl != 0x3d)
        goto loc_1f29;
    dh &= 0xdf;
    memoryASet16(ds, 0x0081, memoryAGet16(ds, 0x0081) + 1);
    if (dh != 0x59)
        goto loc_1f29;
    memoryASet16(ds, 0x0081, memoryAGet16(ds, 0x0081) + 1);
loc_1f29: // 01ed:0059
    repne_scasb<MemAuto, DirAuto>(al);
    if (cx == 0)
        goto loc_1f69;
    bx++;
    if (memoryAGet(es, di) != al)
        goto loc_1f09;
    ch |= 0x80;
    cx = -cx;
    memoryASet16(ds, 0x0075, cx);
    cx = 0x0002;
    bx <<= cl;
    bx += 0x0010;
    bx &= 0xfff0;
    memoryASet16(ds, 0x0079, bx);
    dx = ss;
    bp -= dx;
    di = memoryAGet16(ds, 0x3c78);
    if (di >= 0x0200)
        goto loc_1f60;
    di = 0x0200;
    memoryASet16(ds, 0x3c78, di);
loc_1f60: // 01ed:0090
    cl = 0x04;
    di >>= cl;
    di++;
    if (bp >= di)
        goto loc_1f6c;
loc_1f69: // 01ed:0099
    goto loc_207f;
loc_1f6c: // 01ed:009c
    bx = di;
    bx += dx;
    memoryASet16(ds, 0x0089, bx);
    memoryASet16(ds, 0x008d, bx);
    ax = memoryAGet16(ds, 0x007b);
    bx -= ax;
    es = ax;
    ah = 0x4a;
    push(di);
    interrupt(0x21);
    di = pop();
    di <<= cl;
    flags.interrupts = false;
    ss = dx;
    sp = di;
    flags.interrupts = true;
    ax = 0;
    es = memoryAGet16(cs, 0x01c7);
    di = 0x40b6;
    cx = 0xa66c;
    cx -= di;
    rep_stosb<MemAuto, DirAuto>();
    push(cs);
    callIndirect(cs, memoryAGet16(ds, 0x40a0)); // 01ed:00cf
    push(cs);
    cs = 0x01ed;
    sub_2a6b(); // 01ed:0b9b
    assert(cs == 0x01ed);
    push(cs);
    cs = 0x01ed;
    sub_2b69(); // 01ed:0c99
    assert(cs == 0x01ed);
    ah = 0x00;
    interrupt(0x1a);
    memoryASet16(ds, 0x0083, dx);
    memoryASet16(ds, 0x0085, cx);
    push(cs);
    callIndirect(cs, memoryAGet16(ds, 0x40a4)); // 01ed:00ea
    push(memoryAGet16(ds, 0x0073));
    push(memoryAGet16(ds, 0x0071));
    push(memoryAGet16(ds, 0x006f));
    push(memoryAGet16(ds, 0x006d));
    push(memoryAGet16(ds, 0x006b));
    push(cs);
    cs = 0x02e7;
    sub_2e7b(); // 02e7:000b
    assert(cs == 0x01ed);
    push(ax);
    push(cs);
    cs = 0x1711;
    sub_1711f(); // 1711:000f
    assert(cs == 0x01ed);
    ds = memoryAGet16(cs, 0x01c7);
    push(cs);
    cs = 0x01ed;
    sub_2042(); // 01ed:0172
    assert(cs == 0x01ed);
    push(cs);
    callIndirect(cs, memoryAGet16(ds, 0x40a2)); // 01ed:0118
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 4);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002f;
    goto loc_2086;
    //   gap of 128 bytes
loc_207f: // 01ed:01af
    cx = 0x001e;
    dx = 0x003d;
loc_2086: // 01ed:01b6
    ds = memoryAGet16(cs, 0x01c7);
    sub_2077(); // 01ed:01a7
    ax = 0x0003;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_1fdd(); // 01ed:010d
    assert(cs == 0x01ed);
    stop(/*7*/); //   Terminator reached
}
// 01ed:01c7 Terminator reached
void sub_1fdd() // 01ed:010d
{
    ds = memoryAGet16(cs, 0x01c7);
    push(cs);
    cs = 0x01ed;
    sub_2042(); // 01ed:0172
    assert(cs == 0x01ed);
    push(cs);
    callIndirect(cs, memoryAGet16(ds, 0x40a2)); // 01ed:0118
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 4);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002f;
    goto loc_2086;
    //   gap of 135 bytes
loc_2086: // 01ed:01b6
    ds = memoryAGet16(cs, 0x01c7);
    sub_2077(); // 01ed:01a7
    ax = 0x0003;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_1fdd(); // 01ed:010d
    assert(cs == 0x01ed);
    stop(/*7*/); //   Terminator reached
}
void sub_1fff() // 01ed:012f
{
    CStackGuard sg(0, false);
    push(ds);
    ax = 0x3500;
    interrupt(0x21);
    memoryASet16(ds, 0x005b, bx);
    memoryASet16(ds, 0x005d, es);
    ax = 0x3504;
    interrupt(0x21);
    memoryASet16(ds, 0x005f, bx);
    memoryASet16(ds, 0x0061, es);
    ax = 0x3505;
    interrupt(0x21);
    memoryASet16(ds, 0x0063, bx);
    memoryASet16(ds, 0x0065, es);
    ax = 0x3506;
    interrupt(0x21);
    memoryASet16(ds, 0x0067, bx);
    memoryASet16(ds, 0x0069, es);
    ax = 0x2500;
    dx = cs;
    ds = dx;
    dx = 0x0125;
    interrupt(0x21);
    ds = pop();
}
void sub_2042() // 01ed:0172
{
    CStackGuardFar sg(0, false);
    push(ds);
    ax = 0x2500;
    dx = memoryAGet16(ds, 0x005b);
    ds = memoryAGet16(ds, 0x005b + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2504;
    dx = memoryAGet16(ds, 0x005f);
    ds = memoryAGet16(ds, 0x005f + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2505;
    dx = memoryAGet16(ds, 0x0063);
    ds = memoryAGet16(ds, 0x0063 + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2506;
    dx = memoryAGet16(ds, 0x0067);
    ds = memoryAGet16(ds, 0x0067 + 2);
    interrupt(0x21);
    ds = pop();
    cs = pop();
}
void sub_206f() // 01ed:019f
{
    CStackGuardFar sg(0, false);
    memoryASet16(ds, 0x0081, 0x0000);
    cs = pop();
}
void sub_2077() // 01ed:01a7
{
    CStackGuard sg(0, false);
    ah = 0x40;
    bx = 0x0002;
    interrupt(0x21);
}
void sub_209d() // 01ed:01cd
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    ah = 0x00;
    interrupt(0x10);
    dx = 0x03ce;
    ax = 0x0007;
    out(dx, ax);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_20b6() // 01ed:01e6
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x10;
    al = 0x01;
    bx = memoryAGet16(ss, bp + 6);
    bh = bl;
    interrupt(0x10);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_20c6() // 01ed:01f6
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x1000;
    bl = memoryAGet(ss, bp + 6);
    bh = memoryAGet(ss, bp + 8);
    interrupt(0x10);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_20d6() // 01ed:0206
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    push(si);
    push(di);
    dx = memoryAGet16(cs, 0x01cb);
    es = dx;
    dx = 0xa400;
    ds = dx;
    si = memoryAGet16(ss, bp + 6);
    di = memoryAGet16(ss, bp + 8);
    al = memoryAGet(ds, si);
    memoryASet(es, di, al);
    al = memoryAGet(ds, si + 1);
    memoryASet(es, di + 40, al);
    al = memoryAGet(ds, si + 2);
    memoryASet(es, di + 80, al);
    al = memoryAGet(ds, si + 3);
    memoryASet(es, di + 120, al);
    al = memoryAGet(ds, si + 4);
    memoryASet(es, di + 160, al);
    al = memoryAGet(ds, si + 5);
    memoryASet(es, di + 200, al);
    al = memoryAGet(ds, si + 6);
    memoryASet(es, di + 240, al);
    al = memoryAGet(ds, si + 7);
    memoryASet(es, di + 280, al);
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_212d() // 01ed:025d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ax = memoryAGet16(cs, 0x01c9);
    tl = al;
    al = ah;
    ah = tl;
    ah <<= 1;
    bx = 0xa000;
    bx += ax;
    memoryASet16(cs, 0x01cb, bx);
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_2146() // 01ed:0276
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(cs, 0x01c9, ax);
    push(cs);
    cs = 0x01ed;
    sub_212d(); // 01ed:025d
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_21b0() // 01ed:02e0
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    push(di);
    push(si);
    dx = memoryAGet16(cs, 0x01cb);
    es = dx;
    di = memoryAGet16(ss, bp + 8);
    di <<= 1;
    bx = memoryAGet16(ds, di + 3090);
    bx += memoryAGet16(ss, bp + 6);
    dx = 0x03c5;
    al = 0x08;
    out(dx, al);
    dx = 0x03ce;
    ax = 0x0108;
    out(dx, ax);
    tl = memoryAGet(es, bx);
    memoryASet(es, bx, ah);
    ah = tl;
    ax = 0x0308;
    out(dx, ax);
    tl = memoryAGet(es, bx + 40);
    memoryASet(es, bx + 40, ah);
    ah = tl;
    ax = 0x0708;
    out(dx, ax);
    tl = memoryAGet(es, bx + 80);
    memoryASet(es, bx + 80, ah);
    ah = tl;
    ax = 0x0f08;
    out(dx, ax);
    tl = memoryAGet(es, bx + 120);
    memoryASet(es, bx + 120, ah);
    ah = tl;
    ax = 0x1f08;
    out(dx, ax);
    tl = memoryAGet(es, bx + 160);
    memoryASet(es, bx + 160, ah);
    ah = tl;
    ax = 0x3f08;
    out(dx, ax);
    tl = memoryAGet(es, bx + 200);
    memoryASet(es, bx + 200, ah);
    ah = tl;
    ax = 0x7f08;
    out(dx, ax);
    tl = memoryAGet(es, bx + 240);
    memoryASet(es, bx + 240, ah);
    ah = tl;
    ax = 0xff08;
    out(dx, ax);
    tl = memoryAGet(es, bx + 280);
    memoryASet(es, bx + 280, ah);
    ah = tl;
    si = pop();
    di = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_221a() // 01ed:034a
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    push(di);
    push(si);
    dx = memoryAGet16(cs, 0x01cb);
    es = dx;
    di = memoryAGet16(ss, bp + 8);
    di <<= 1;
    bx = memoryAGet16(ds, di + 3090);
    bx += memoryAGet16(ss, bp + 6);
    dx = 0x03ce;
    ax = 0xff08;
    out(dx, ax);
    dx = 0x03c5;
    al = 0x08;
    out(dx, al);
    al = 0xff;
    memoryASet(es, bx, al);
    memoryASet(es, bx + 40, al);
    memoryASet(es, bx + 80, al);
    memoryASet(es, bx + 120, al);
    memoryASet(es, bx + 160, al);
    memoryASet(es, bx + 200, al);
    memoryASet(es, bx + 240, al);
    memoryASet(es, bx + 280, al);
    si = pop();
    di = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_226a() // 01ed:039a
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    push(di);
    push(si);
    dx = memoryAGet16(cs, 0x01cb);
    es = dx;
    di = memoryAGet16(ss, bp + 8);
    di <<= 1;
    bx = memoryAGet16(ds, di + 3090);
    bx += memoryAGet16(ss, bp + 6);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03ce;
    ax = 0x8008;
    out(dx, ax);
    tl = memoryAGet(es, bx);
    memoryASet(es, bx, ah);
    ah = tl;
    ax = 0xc008;
    out(dx, ax);
    tl = memoryAGet(es, bx + 40);
    memoryASet(es, bx + 40, ah);
    ah = tl;
    ax = 0xe008;
    out(dx, ax);
    tl = memoryAGet(es, bx + 80);
    memoryASet(es, bx + 80, ah);
    ah = tl;
    ax = 0xf008;
    out(dx, ax);
    tl = memoryAGet(es, bx + 120);
    memoryASet(es, bx + 120, ah);
    ah = tl;
    ax = 0xf808;
    out(dx, ax);
    tl = memoryAGet(es, bx + 160);
    memoryASet(es, bx + 160, ah);
    ah = tl;
    ax = 0xfc08;
    out(dx, ax);
    tl = memoryAGet(es, bx + 200);
    memoryASet(es, bx + 200, ah);
    ah = tl;
    ax = 0xfe08;
    out(dx, ax);
    tl = memoryAGet(es, bx + 240);
    memoryASet(es, bx + 240, ah);
    ah = tl;
    ax = 0xff08;
    out(dx, ax);
    tl = memoryAGet(es, bx + 280);
    memoryASet(es, bx + 280, ah);
    ah = tl;
    si = pop();
    di = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_22d4() // 01ed:0404
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    ah = 0x05;
    interrupt(0x10);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_22e0() // 01ed:0410
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    di = memoryAGet16(ss, bp + 12);
    di <<= 1;
    di = memoryAGet16(ds, di + 3090);
    di += memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(cs, 0x01cb);
    si = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    es = ax;
    bl = memoryAGet(ds, si);
    bh = memoryAGet(ds, si + 5);
    cl = memoryAGet(ds, si + 10);
    ch = memoryAGet(ds, si + 15);
    dx = 0x03c4;
    ax = 0x0102;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0004;
    out(dx, ax);
    al = memoryAGet(es, di);
    al &= bl;
    al |= memoryAGet(ds, si + 1);
    memoryASet(es, di, al);
    al = memoryAGet(es, di + 40);
    al &= bh;
    al |= memoryAGet(ds, si + 6);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di + 80);
    al &= cl;
    al |= memoryAGet(ds, si + 11);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 120);
    al &= ch;
    al |= memoryAGet(ds, si + 16);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 21);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 26);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 31);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 36);
    memoryASet(es, di + 280, al);
    dx = 0x03c4;
    ax = 0x0202;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0104;
    out(dx, ax);
    al = memoryAGet(es, di);
    al &= bl;
    al |= memoryAGet(ds, si + 2);
    memoryASet(es, di, al);
    al = memoryAGet(es, di + 40);
    al &= bh;
    al |= memoryAGet(ds, si + 7);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di + 80);
    al &= cl;
    al |= memoryAGet(ds, si + 12);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 120);
    al &= ch;
    al |= memoryAGet(ds, si + 17);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 22);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 27);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 32);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 37);
    memoryASet(es, di + 280, al);
    dx = 0x03c4;
    ax = 0x0402;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0204;
    out(dx, ax);
    al = memoryAGet(es, di);
    al &= bl;
    al |= memoryAGet(ds, si + 3);
    memoryASet(es, di, al);
    al = memoryAGet(es, di + 40);
    al &= bh;
    al |= memoryAGet(ds, si + 8);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di + 80);
    al &= cl;
    al |= memoryAGet(ds, si + 13);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 120);
    al &= ch;
    al |= memoryAGet(ds, si + 18);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 23);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 28);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 33);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 38);
    memoryASet(es, di + 280, al);
    dx = 0x03c4;
    ax = 0x0802;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0304;
    out(dx, ax);
    al = memoryAGet(es, di);
    al &= bl;
    al |= memoryAGet(ds, si + 4);
    memoryASet(es, di, al);
    al = memoryAGet(es, di + 40);
    al &= bh;
    al |= memoryAGet(ds, si + 9);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di + 80);
    al &= cl;
    al |= memoryAGet(ds, si + 14);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 120);
    al &= ch;
    al |= memoryAGet(ds, si + 19);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 24);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 29);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 34);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 39);
    memoryASet(es, di + 280, al);
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_250b() // 01ed:063b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    di = memoryAGet16(ss, bp + 12);
    di <<= 1;
    di = memoryAGet16(ds, di + 3090);
    di += memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(cs, 0x01cb);
    si = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    si -= 0x3e80;
    es = ax;
    dx = 0x03ce;
    ax = 0x0005;
    out(dx, ax);
    bl = memoryAGet(ds, si);
    bh = memoryAGet(ds, si + 5);
    cl = memoryAGet(ds, si + 10);
    ch = memoryAGet(ds, si + 15);
    dx = 0x03c4;
    ax = 0x0102;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0004;
    out(dx, ax);
    al = memoryAGet(es, di);
    al &= bl;
    al |= memoryAGet(ds, si + 1);
    memoryASet(es, di, al);
    al = memoryAGet(es, di + 40);
    al &= bh;
    al |= memoryAGet(ds, si + 6);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di + 80);
    al &= cl;
    al |= memoryAGet(ds, si + 11);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 120);
    al &= ch;
    al |= memoryAGet(ds, si + 16);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 21);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 26);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 31);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 36);
    memoryASet(es, di + 280, al);
    dx = 0x03c4;
    ax = 0x0202;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0104;
    out(dx, ax);
    al = memoryAGet(es, di);
    al &= bl;
    al |= memoryAGet(ds, si + 2);
    memoryASet(es, di, al);
    al = memoryAGet(es, di + 40);
    al &= bh;
    al |= memoryAGet(ds, si + 7);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di + 80);
    al &= cl;
    al |= memoryAGet(ds, si + 12);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 120);
    al &= ch;
    al |= memoryAGet(ds, si + 17);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 22);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 27);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 32);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 37);
    memoryASet(es, di + 280, al);
    dx = 0x03c4;
    ax = 0x0402;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0204;
    out(dx, ax);
    al = memoryAGet(es, di);
    al &= bl;
    al |= memoryAGet(ds, si + 3);
    memoryASet(es, di, al);
    al = memoryAGet(es, di + 40);
    al &= bh;
    al |= memoryAGet(ds, si + 8);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di + 80);
    al &= cl;
    al |= memoryAGet(ds, si + 13);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 120);
    al &= ch;
    al |= memoryAGet(ds, si + 18);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 23);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 28);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 33);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 38);
    memoryASet(es, di + 280, al);
    dx = 0x03c4;
    ax = 0x0802;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0304;
    out(dx, ax);
    al = memoryAGet(es, di);
    al &= bl;
    al |= memoryAGet(ds, si + 4);
    memoryASet(es, di, al);
    al = memoryAGet(es, di + 40);
    al &= bh;
    al |= memoryAGet(ds, si + 9);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di + 80);
    al &= cl;
    al |= memoryAGet(ds, si + 14);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 120);
    al &= ch;
    al |= memoryAGet(ds, si + 19);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 24);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 29);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 34);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 39);
    memoryASet(es, di + 280, al);
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0105;
    out(dx, ax);
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_274f() // 01ed:087f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    di = memoryAGet16(ss, bp + 12);
    di <<= 1;
    di = memoryAGet16(ds, di + 3090);
    di += memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(cs, 0x01cb);
    si = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    es = ax;
    dx = 0x03c4;
    ax = 0x0102;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0004;
    out(dx, ax);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si);
    al |= memoryAGet(ds, si + 1);
    memoryASet(es, di + 280, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 5);
    al |= memoryAGet(ds, si + 6);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 10);
    al |= memoryAGet(ds, si + 11);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 15);
    al |= memoryAGet(ds, si + 16);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 120);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 21);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 80);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 26);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 40);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 31);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 36);
    memoryASet(es, di, al);
    dx = 0x03c4;
    ax = 0x0202;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0104;
    out(dx, ax);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si);
    al |= memoryAGet(ds, si + 2);
    memoryASet(es, di + 280, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 5);
    al |= memoryAGet(ds, si + 7);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 10);
    al |= memoryAGet(ds, si + 12);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 15);
    al |= memoryAGet(ds, si + 17);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 120);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 22);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 80);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 27);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 40);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 32);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 37);
    memoryASet(es, di, al);
    dx = 0x03c4;
    ax = 0x0402;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0204;
    out(dx, ax);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si);
    al |= memoryAGet(ds, si + 3);
    memoryASet(es, di + 280, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 5);
    al |= memoryAGet(ds, si + 8);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 10);
    al |= memoryAGet(ds, si + 13);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 15);
    al |= memoryAGet(ds, si + 18);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 120);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 23);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 80);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 28);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 40);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 33);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 38);
    memoryASet(es, di, al);
    dx = 0x03c4;
    ax = 0x0802;
    out(dx, ax);
    dx = 0x03ce;
    ax = 0x0304;
    out(dx, ax);
    al = memoryAGet(es, di + 280);
    al &= memoryAGet(ds, si);
    al |= memoryAGet(ds, si + 4);
    memoryASet(es, di + 280, al);
    al = memoryAGet(es, di + 240);
    al &= memoryAGet(ds, si + 5);
    al |= memoryAGet(ds, si + 9);
    memoryASet(es, di + 240, al);
    al = memoryAGet(es, di + 200);
    al &= memoryAGet(ds, si + 10);
    al |= memoryAGet(ds, si + 14);
    memoryASet(es, di + 200, al);
    al = memoryAGet(es, di + 160);
    al &= memoryAGet(ds, si + 15);
    al |= memoryAGet(ds, si + 19);
    memoryASet(es, di + 160, al);
    al = memoryAGet(es, di + 120);
    al &= memoryAGet(ds, si + 20);
    al |= memoryAGet(ds, si + 24);
    memoryASet(es, di + 120, al);
    al = memoryAGet(es, di + 80);
    al &= memoryAGet(ds, si + 25);
    al |= memoryAGet(ds, si + 29);
    memoryASet(es, di + 80, al);
    al = memoryAGet(es, di + 40);
    al &= memoryAGet(ds, si + 30);
    al |= memoryAGet(ds, si + 34);
    memoryASet(es, di + 40, al);
    al = memoryAGet(es, di);
    al &= memoryAGet(ds, si + 35);
    al |= memoryAGet(ds, si + 39);
    memoryASet(es, di, al);
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_29fe() // 01ed:0b2e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    push(si);
    push(di);
    tx = flags.carry | (flags.zero << 1); // I=1
    push(tx);
    ax = 0; // Z=1, P=1, I=1
    push(ax);
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    tx = flags.carry | (flags.zero << 1);
    push(tx); // all zero
    ax = pop(); // AX=2
    ax &= 0xf000;
    if (ax == 0xf000)
    {
        assert(0);
        goto loc_2a26;
    }
    dl = 0x06;
    ax = 0x7000;
    push(ax);
    tx = pop(); // all zero
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    tx = flags.carry | (flags.zero << 1) | 0x7000;
    push(tx);
    ax = pop(); // 7002
    ax &= 0x7000;
    if (ax == 0)
    {
        assert(0);
        goto loc_2a59;
    }
    dl++;
    goto loc_2a59;
loc_2a26: // 01ed:0b56
    dl = 0x04;
    al = 0xff;
    cl = 0x21;
    al >>= cl;
    if (al != 0)
        goto loc_2a44;
    dl = 0x02;
    flags.interrupts = true;
    push(si);
    si = 0x0000;
    cx = 0xffff;
    rep_lodsb<MemAuto, DirAuto>();
    si = pop();
    if (!cx)
        goto loc_2a44;
    dl = 0x00;
loc_2a44: // 01ed:0b74
    push(cs);
    es = pop();
    flags.direction = true;
    di = 0x0b88;
    al = 0xfb;
    cx = 0x0003;
    flags.interrupts = false;
    rep_stosb<MemAuto, DirAuto>();
    flags.direction = false;
    dx++;
    flags.interrupts = true;
loc_2a59: // 01ed:0b89
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    dh = 0;
    ax = dx;
    di = pop();
    si = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_2a6b() // 01ed:0b9b
{
//    stop(/*override stack*/); // 01ed:0b9b
    push(0x6666);
    memoryASet16(cs, 0x0b93, pop());
    memoryASet16(cs, 0x0b95, pop());
    memoryASet16(cs, 0x0b97, ds);
    flags.direction = false;
    es = memoryAGet16(ds, 0x007b);
    si = 0x0080;
    ah = 0;
    lodsb_es<MemAuto, DirAuto>();
    ax++;
    bp = es;
    tx = si;
    si = dx;
    dx = tx;
    tx = bx;
    bx = ax;
    ax = tx;
    si = memoryAGet16(ds, 0x0075);
    si += 0x0002;
    cx = 0x0001;
    if (memoryAGet(ds, 0x007d) < 0x03)
        goto loc_2aae;
    es = memoryAGet16(ds, 0x0077);
    di = si;
    cl = 0x7f;
    al = 0;
    repne_scasb<MemAuto, DirAuto>(al);
    if (cx == 0)
        goto loc_2b21;
    cl ^= 0x7f;
loc_2aae: // 01ed:0bde
    sp -= 0x0002;
    ax = 0x0001;
    ax += bx;
    ax += cx;
    ax &= 0xfffe;
    di = sp;
    tx = di;
    di -= ax;
    if (tx < ax)
        goto loc_2b21;
    sp = di;
    ax = es;
    ds = ax;
    ax = ss;
    es = ax;
    push(cx);
    cx--;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    al = 0;
    stosb<MemAuto, DirAuto>();
    ds = bp;
    tx = dx;
    dx = si;
    si = tx;
    tx = cx;
    cx = bx;
    bx = tx;
    ax = bx;
    dx = ax;
    bx++;
loc_2add: // 01ed:0c0d
    sub_2af9(); // 01ed:0c29
    if (!flags.zero && !flags.carry)
        goto loc_2ae9;
loc_2ae2: // 01ed:0c12
    if (flags.carry)
        goto loc_2b26;
    sub_2af9(); // 01ed:0c29
    if (!flags.zero && !flags.carry)
        goto loc_2ae2;
loc_2ae9: // 01ed:0c19
    if (al == 0x20)
        goto loc_2af5;
    if (al == 0x0d)
        goto loc_2af5;
    if (al != 0x09)
        goto loc_2add;
loc_2af5: // 01ed:0c25
    al = 0;
    goto loc_2add;
    //   gap of 40 bytes
loc_2b21: // 01ed:0c51
    cs = 0x01ed;
    callIndirect(0x01ed, 0x01af);
loc_2b26: // 01ed:0c56
    cx = pop();
    cx += dx;
    ds = memoryAGet16(cs, 0x0b97);
    memoryASet16(ds, 0x006b, bx);
    bx++;
    bx += bx;
    bx += bx;
    si = sp;
    bp = sp;
    tx = bp;
    bp -= bx;
    if (tx < bx)
        goto loc_2b21;
    sp = bp;
    memoryASet16(ds, 0x006d, bp);
    memoryASet16(ds, 0x006f, ss);
loc_2b49: // 01ed:0c79
    if (cx == 0)
        goto loc_2b5c;
    memoryASet16(ss, bp, si);
    memoryASet16(ss, bp + 2, ss);
    bp += 0x0004;
loc_2b54: // 01ed:0c84
    lodsb_ss<MemAuto, DirAuto>();
    if (--cx && al)
        goto loc_2b54;
    if (!al)
        goto loc_2b49;
loc_2b5c: // 01ed:0c8c
    flags.carry = false;
    ax = 0;
    memoryASet16(ss, bp, ax);
    memoryASet16(ss, bp + 2, ax);
    //daa(); // jmp far word cs:[0b93]
}
// INJECT: Error: cannot inject zero flag in sub_2af9()!
// INJECT: Error: cannot inject carry flag in sub_2af9()!
void sub_2af9() // 01ed:0c29+zero !! carry!
{
    CStackGuard sg(0, false);
    if (!ax)
        goto loc_2b04;
    dx++;
    stosb<MemAuto, DirAuto>();
    if (al)
        goto loc_2b04;
    bx++;
loc_2b04: // 01ed:0c34
    tl = al;
    al = ah;
    ah = tl;
    al = 0;
    flags.carry = true;
    if (cx == 0)
        goto loc_2b20;
    lodsb<MemAuto, DirAuto>();
    cx--;
    al -= 0x22;
    if (al == 0)
        goto loc_2b20;
    al += 0x22;
    if (al != 0x5c)
        goto loc_2b1e;
    if (memoryAGet(ds, si) != 0x22)
        goto loc_2b1e;
    lodsb<MemAuto, DirAuto>();
    flags.carry = cx == 0;
    cx--;
    flags.zero = !cx;
loc_2b1e: // 01ed:0c4e
    flags.zero = !si;
loc_2b20: // 01ed:0c50
    return;
}
void sub_2b69() // 01ed:0c99
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    es = memoryAGet16(ds, 0x0077);
    di = 0;
    push(es);
    push(memoryAGet16(ds, 0x0079));
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x01ed);
    sp += 0x0002;
    bx = ax;
    es = pop();
    memoryASet16(ds, 0x0071, ax);
    memoryASet16(ds, 0x0073, dx);
    push(ds);
    ds = dx;
    ax |= dx;
    if (ax)
        goto loc_2b92;
    cs = 0x01ed;
    callIndirect(0x01ed, 0x01af);
loc_2b92: // 01ed:0cc2
    ax = 0;
    cx = 0xffff;
loc_2b97: // 01ed:0cc7
    memoryASet16(ds, bx, di);
    memoryASet16(ds, bx + 2, es);
    bx += 0x0004;
    repne_scasb<MemAuto, DirAuto>(al);
    if (memoryAGet(es, di) != al)
        goto loc_2b97;
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, ax);
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_2bad() // 01ed:0cdd
{
    CStackGuardFar sg(0, false);
    if ((short)cx >= 0)
        goto loc_2bbe;
    bx = ~bx;
    cx = ~cx;
    flags.carry = (bx + 0x0001) >= 0x10000;
    bx += 0x0001;
    cx += flags.carry;
    goto loc_2bea;
loc_2bbe: // 01ed:0cee
    flags.carry = (ax + bx) >= 0x10000;
    ax += bx;
    if (!flags.carry)
        goto loc_2bc6;
    dx += 0x1000;
loc_2bc6: // 01ed:0cf6
    ch = cl;
    cl = 0x04;
    ch <<= cl;
    dh += ch;
    ch = al;
    ax >>= cl;
    dx += ax;
    al = ch;
    ax &= 0x000f;
    cs = pop();
    return;
    //   gap of 16 bytes
loc_2bea: // 01ed:0d1a
    flags.carry = ax < bx;
    ax -= bx;
    if (!flags.carry)
        goto loc_2bf2;
    dx -= 0x1000;
loc_2bf2: // 01ed:0d22
    bh = cl;
    cl = 0x04;
    bh <<= cl;
    bl = 0;
    dx -= bx;
    ch = al;
    ax >>= cl;
    dx += ax;
    al = ch;
    ax &= 0x000f;
    cs = pop();
}
void sub_2c08() // 01ed:0d38+zero
{
    CStackGuardFar sg(0, false);
    push(cx);
    ch = al;
    cl = 0x04;
    ax >>= cl;
    dx += ax;
    al = ch;
    ah = bl;
    bx >>= cl;
    cx = pop();
    cx += bx;
    bl = ah;
    ax &= 0x000f;
    bx &= 0x000f;
    flags.carry = dx < cx;
    flags.zero = dx == cx;
    if (dx != cx)
        goto loc_2c28;
    flags.carry = ax < bx;
    flags.zero = ax == bx;
loc_2c28: // 01ed:0d58
    cs = pop();
}
void sub_2c29() // 01ed:0d59
{
    CStackGuardFar sg(0, false);
    push(si);
    tx = si;
    si = ax;
    ax = tx;
    tx = dx;
    dx = ax;
    ax = tx;
    if (!ax)
        goto loc_2c32;
    mul(bx);
loc_2c32: // 01ed:0d62
    tx = cx;
    cx = ax;
    ax = tx;
    if (!ax)
        goto loc_2c3b;
    mul(si);
    cx += ax;
loc_2c3b: // 01ed:0d6b
    tx = si;
    si = ax;
    ax = tx;
    mul(bx);
    dx += cx;
    si = pop();
    cs = pop();
}
void sub_2c69() // 01ed:0d99
{
    CStackGuard sg(8, true);
    push(0x7777);
    push(bp);
    bp = sp;
    goto loc_2c86;
loc_2c6e: // 01ed:0d9e
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(ss, bp + 4, memoryAGet16(ss, bp + 4) + 1);
    al = memoryAGet(es, bx);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 1);
    if (al == memoryAGet(es, bx))
        goto loc_2c86;
    ax = 0;
    goto loc_2c94;
loc_2c86: // 01ed:0db6
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet(es, bx) != 0x00)
        goto loc_2c6e;
    ax = 0x0001;
loc_2c94: // 01ed:0dc4
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
void sub_2c98() // 01ed:0dc8
{
    CStackGuard sg(0, false);
    ax = 0x1130;
    bh = 0x00;
    dl = 0xff;
    push(cs);
    cs = 0x01ed;
    sub_2cad(); // 01ed:0ddd
    assert(cs == 0x01ed);
    al = dl;
    al++;
    ah = 0x00;
}
void sub_2cad() // 01ed:0ddd
{
    CStackGuardFar sg(0, false);
    push(si);
    push(di);
    memoryASet16(ds, 0xa66a, bp);
    interrupt(0x10);
    bp = memoryAGet16(ds, 0xa66a);
    di = pop();
    si = pop();
    cs = pop();
}
void sub_2cbc() // 01ed:0dec
{
    CStackGuardFar sg(0, false);
    ah = 0x0f;
    push(cs);
    sub_2cad(); // 01ed:0ddd
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_2cdd(); // 01ed:0e0d
    assert(cs == 0x01ed);
    cx = pop();
    ah = 0x08;
    bh = 0x00;
    push(cs);
    sub_2cad(); // 01ed:0ddd
    ah &= 0x7f;
    memoryASet(ds, 0x4007, ah);
    memoryASet(ds, 0x4006, ah);
    cs = pop();
}
void sub_2cdd() // 01ed:0e0d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 6);
    if (al <= 0x03)
        goto loc_2ced;
    if (al == 0x07)
        goto loc_2ced;
    al = 0x03;
loc_2ced: // 01ed:0e1d
    memoryASet(ds, 0x4008, al);
    ah = 0x0f;
    push(cs);
    sub_2cad(); // 01ed:0ddd
    if (al == memoryAGet(ds, 0x4008))
        goto loc_2d0e;
    al = memoryAGet(ds, 0x4008);
    ah = 0x00;
    push(cs);
    sub_2cad(); // 01ed:0ddd
    ah = 0x0f;
    push(cs);
    sub_2cad(); // 01ed:0ddd
    memoryASet(ds, 0x4008, al);
loc_2d0e: // 01ed:0e3e
    memoryASet(ds, 0x400a, ah);
    if (memoryAGet(ds, 0x4008) <= 0x03)
        goto loc_2d25;
    if (memoryAGet(ds, 0x4008) == 0x07)
        goto loc_2d25;
    ax = 0x0001;
    goto loc_2d27;
loc_2d25: // 01ed:0e55
    ax = 0;
loc_2d27: // 01ed:0e57
    memoryASet(ds, 0x400b, al);
    memoryASet(ds, 0x4009, 0x19);
    if (memoryAGet(ds, 0x4008) == 0x07)
        goto loc_2d56;
    dx = 0xf000;
    ax = 0xffea;
    push(dx);
    push(ax);
    push(ds);
    ax = 0x4013;
    push(ax);
    sub_2c69(); // 01ed:0d99
    if (ax)
        goto loc_2d56;
    sub_2c98(); // 01ed:0dc8
    if (ax)
        goto loc_2d56;
    ax = 0x0001;
    goto loc_2d58;
loc_2d56: // 01ed:0e86
    ax = 0;
loc_2d58: // 01ed:0e88
    memoryASet(ds, 0x400c, al);
    if (memoryAGet(ds, 0x4008) != 0x07)
        goto loc_2d67;
    ax = 0xb000;
    goto loc_2d6a;
loc_2d67: // 01ed:0e97
    ax = 0xb800;
loc_2d6a: // 01ed:0e9a
    memoryASet16(ds, 0x400f, ax);
    memoryASet16(ds, 0x400d, 0x0000);
    al = 0x00;
    memoryASet(ds, 0x4003, al);
    memoryASet(ds, 0x4002, al);
    al = memoryAGet(ds, 0x400a);
    al += 0xff;
    memoryASet(ds, 0x4004, al);
    memoryASet(ds, 0x4005, 0x18);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_2d97() // 01ed:0ec7
{
    CStackGuardFar sg(8, true);
    push(0x7777);
    cx = 0;
    goto loc_2da8;
    //   gap of 13 bytes
loc_2da8: // 01ed:0ed8
    push(bp);
    push(si);
    push(di);
    bp = sp;
    di = cx;
    ax = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 14);
    cx = memoryAGet16(ss, bp + 16);
    if (cx)
        goto loc_2dc7;
    if (!dx)
        goto loc_2e2c;
    if (!bx)
        goto loc_2e2c;
loc_2dc7: // 01ed:0ef7
    if (di & 0x0001)
        goto loc_2de9;
    if (!(dx & 0x8000))
        goto loc_2ddb;
    dx = -dx;
    flags.carry = ax != 0;
    ax = -ax;
    dx -= flags.carry;
    di |= 0x000c;
loc_2ddb: // 01ed:0f0b
    if (!(cx & 0x8000))
        goto loc_2de9;
    cx = -cx;
    flags.carry = bx != 0;
    bx = -bx;
    cx -= flags.carry;
    di ^= 0x0004;
loc_2de9: // 01ed:0f19
    bp = cx;
    cx = 0x0020;
    push(di);
    di = 0;
    si = 0;
loc_2df3: // 01ed:0f23
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl(dx, 0x0001);
    si = rcl(si, 0x0001);
    di = rcl(di, 0x0001);
    if (di < bp)
        goto loc_2e0a;
    if (di > bp)
        goto loc_2e05;
    if (si < bx)
        goto loc_2e0a;
loc_2e05: // 01ed:0f35
    flags.carry = si < bx;
    si -= bx;
    di -= bp + flags.carry;
    ax++;
loc_2e0a: // 01ed:0f3a
    if (--cx)
        goto loc_2df3;
    bx = pop();
    if (!(bx & 0x0002))
        goto loc_2e19;
    ax = si;
    dx = di;
    bx >>= 1;
loc_2e19: // 01ed:0f49
    if (!(bx & 0x0004))
        goto loc_2e26;
    dx = -dx;
    flags.carry = ax != 0;
    ax = -ax;
    dx -= flags.carry;
loc_2e26: // 01ed:0f56
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
    return;
loc_2e2c: // 01ed:0f5c
    div(bx);
    if (!(di & 0x0002))
        goto loc_2e36;
    ax = dx;
loc_2e36: // 01ed:0f66
    dx = 0;
    goto loc_2e26;
}
void sub_2e3a() // 01ed:0f6a
{
    CStackGuardFar sg(0, false);
    push(di);
    di = cx;
    ch = dh;
    cl = 0x04;
    dx <<= cl;
    ch >>= cl;
    flags.carry = (dx + ax) >= 0x10000;
    dx += ax;
    ch += flags.carry;
    ax = di;
    di <<= cl;
    ah >>= cl;
    flags.carry = (bx + di) >= 0x10000;
    bx += di;
    ah += flags.carry;
    flags.carry = dx < bx;
    dx -= bx;
    ch -= ah + flags.carry;
    al = ch;
    cbw();
    tx = dx;
    dx = ax;
    ax = tx;
    di = pop();
    cs = pop();
}
void sub_2e50() // 01ed:0f80
{
    CStackGuardFar sg(0, false);
    flags.carry = (bx + di) >= 0x10000;
    bx += di;
    ah += flags.carry;
    flags.carry = dx < bx;
    dx -= bx;
    ch -= ah + flags.carry;
    al = ch;
    cbw();
    tx = dx;
    dx = ax;
    ax = tx;
    di = pop();
    cs = pop();
}
void sub_2e5f() // 01ed:0f8f
{
    CStackGuardFar sg(8, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    si = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    flags.direction = false;
    flags.carry = cx & 1;
    cx >>= 1;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cx += cx + flags.carry;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
}
void sub_2e7b() // 02e7:000b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    push(si);
    push(cs);
    cs = 0x01ed;
    sub_29fe(); // 01ed:0b2e
    assert(cs == 0x02e7);
    si = ax;
    if ((short)si >= (short)0x0004)
        goto loc_2efa;
    push(ds);
    ax = 0x0094;
    push(ax);
    push(cs);
    cs = 0x18ac;
    sub_18acf(); // 18ac:000f
    assert(cs == 0x02e7);
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x00cc;
    push(ax);
    push(cs);
    cs = 0x18ac;
    sub_18acf(); // 18ac:000f
    assert(cs == 0x02e7);
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x0108;
    push(ax);
    push(cs);
    cs = 0x18ac;
    sub_18acf(); // 18ac:000f
    assert(cs == 0x02e7);
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x012d;
    push(ax);
    push(cs);
    cs = 0x18ac;
    sub_18acf(); // 18ac:000f
    assert(cs == 0x02e7);
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x0159;
    push(ax);
    push(cs);
    cs = 0x18ac;
    sub_18acf(); // 18ac:000f
    assert(cs == 0x02e7);
    cx = pop();
    cx = pop();
    push(cs);
    cs = 0x1985;
    sub_19859(); // 1985:0009
    assert(cs == 0x02e7);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x59)
        goto loc_2ede;
    if (memoryAGet(ss, bp - 1) != 0x79)
        goto loc_2eef;
loc_2ede: // 02e7:006e
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x02f1;
    sub_12798(); // 02f1:f888
    assert(cs == 0x02e7);
    sp += 0x0006;
loc_2eef: // 02e7:007f
    ax = 0;
    push(ax);
    push(cs);
    cs = 0x1711;
    sub_1711f(); // 1711:000f
    assert(cs == 0x02e7);
    cx = pop();
    goto loc_2f0b;
loc_2efa: // 02e7:008a
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x02f1;
    sub_12798(); // 02f1:f888
    assert(cs == 0x02e7);
    sp += 0x0006;
loc_2f0b: // 02e7:009b
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_2f10() // 02f1:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    sp = bp;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    sp = bp;
    dx = memoryAGet16(ds, 0xa460);
    ax = memoryAGet16(ds, 0xa45e);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_2f32() // 02f1:0022
{
    CStackGuardFar sg(0, false);
    memoryASet16(ds, 0xa472, 0x0000);
    memoryASet16(ds, 0xa14a, 0x0000);
    cs = pop();
}
void sub_2fcb() // 02f1:00bb
{
    CStackGuardFar sg(0, false);
    al = memoryAGet(ds, 0xa45a);
    ah = 0x00;
    ax--;
    if (ax <= 0x0004)
        goto loc_2fd9;
    goto loc_3087;
loc_2fd9: // 02f1:00c9
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 210)); // 02f1:00cd
    return;
    //   gap of 165 bytes
loc_3087: // 02f1:0177
    cs = pop();
}
void sub_3088() // 02f1:0178
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0xa;
    push(si);
    push(di);
    si = 0;
    di = si;
    memoryASet16(ss, bp - 2, si);
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    goto loc_3261;
loc_30a4: // 02f1:0194
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    if (memoryAGet(es, bx + si) == 0xfe)
        goto loc_30c2;
    if (memoryAGet(es, bx + si) == 0xfb)
        goto loc_30c2;
    if (memoryAGet(es, bx + si) == 0xfd)
        goto loc_30c2;
    if (memoryAGet(es, bx + si) == 0xfc)
        goto loc_30c2;
    goto loc_31b8;
loc_30c2: // 02f1:01b2
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += si;
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 10, al);
    bx = memoryAGet16(ss, bp + 10);
    bx += si;
    al = memoryAGet(es, bx + 2);
    memoryASet(ss, bp - 9, al);
    bx = memoryAGet16(ss, bp + 10);
    bx += si;
    al = memoryAGet(es, bx + 3);
    memoryASet(ss, bp - 8, al);
    memoryASet(ss, bp - 7, 0x00);
    push(ss);
    ax = bp - 0xa;
    push(ax);
    push(cs);
    cs = 0x19f9;
    sub_19f91(); // 19f9:0001
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    if (memoryAGet(es, bx + si) != 0xfd)
        goto loc_311a;
    push(0x0006);
    push(memoryAGet16(ss, bp + 8));
    ax = memoryAGet16(ss, bp + 6);
    ax += si;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x02f1;
    sub_4141(); // 02f1:1231
    assert(cs == 0x02f1);
    sp += 0x0008;
    goto loc_3137;
loc_311a: // 02f1:020a
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    if (memoryAGet(es, bx + si) != 0xfb)
        goto loc_313e;
    push(memoryAGet16(ss, bp + 8));
    ax = memoryAGet16(ss, bp + 6);
    ax += si;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x02f1;
    sub_4380(); // 02f1:1470
    assert(cs == 0x02f1);
    sp += 0x0006;
loc_3137: // 02f1:0227
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) + 0x0004);
    goto loc_3261;
loc_313e: // 02f1:022e
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    if (memoryAGet(es, bx + si) != 0xfc)
        goto loc_3161;
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) + 0x0004);
    push(ss);
    ax = bp - 0xa;
    push(ax);
    push(cs);
    cs = 0x19f9;
    sub_19f91(); // 19f9:0001
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    di = ax;
    ax = di;
    memoryASet16(ss, bp - 2, ax);
    goto loc_3261;
loc_3161: // 02f1:0251
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += si;
    al = memoryAGet(es, bx + 4);
    memoryASet(ss, bp - 10, al);
    bx = memoryAGet16(ss, bp + 10);
    bx += si;
    al = memoryAGet(es, bx + 5);
    memoryASet(ss, bp - 9, al);
    bx = memoryAGet16(ss, bp + 10);
    bx += si;
    al = memoryAGet(es, bx + 6);
    memoryASet(ss, bp - 8, al);
    memoryASet(ss, bp - 7, 0x00);
    push(ss);
    ax = bp - 0xa;
    push(ax);
    push(cs);
    cs = 0x19f9;
    sub_19f91(); // 19f9:0001
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 4, ax);
    push(0x0006);
    push(memoryAGet16(ss, bp + 8));
    ax = memoryAGet16(ss, bp + 6);
    ax += si;
    push(ax);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x02f1;
    sub_3ea5(); // 02f1:0f95
    assert(cs == 0x02f1);
    sp += 0x000a;
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) + 0x0007);
    goto loc_3261;
loc_31b8: // 02f1:02a8
    if (!di)
        goto loc_31cd;
    if (memoryAGet(ds, 0x59e2) != 0x39)
        goto loc_31cd;
    push(0x0001);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
    goto loc_31fb;
loc_31cd: // 02f1:02bd
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_31fb;
    push(0x0003);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) - 1);
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_31e7;
    goto loc_3261;
loc_31e7: // 02f1:02d7
    memoryASet16(ss, bp - 2, di);
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    if (memoryAGet(es, bx + si) == 0x20)
        goto loc_31fb;
    push(0x002c);
    push(cs);
    cs = 0x02f1;
    sub_3448(); // 02f1:0538
    assert(cs == 0x02f1);
    cx = pop();
loc_31fb: // 02f1:02eb
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    if (memoryAGet(es, bx + si) < 0x61)
        goto loc_3232;
    push(memoryAGet16(ss, bp + 8));
    ax = memoryAGet16(ss, bp + 6);
    ax += si;
    push(ax);
    al = memoryAGet(es, bx + si);
    ah = 0x00;
    ax += 0xff9f;
    imul(ax, ax, 0x0028);
    cx = memoryAGet16(ds, 0x58a2);
    bx = memoryAGet16(ds, 0x58a0);
    bx += ax;
    bx += 0x0ac8;
    push(cx);
    push(bx);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
    goto loc_3260;
loc_3232: // 02f1:0322
    push(memoryAGet16(ss, bp + 8));
    ax = memoryAGet16(ss, bp + 6);
    ax += si;
    push(ax);
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    al = memoryAGet(es, bx + si);
    ah = 0x00;
    ax += 0xffe8;
    imul(ax, ax, 0x0028);
    cx = memoryAGet16(ds, 0x58a2);
    bx = memoryAGet16(ds, 0x58a0);
    bx += ax;
    bx += 0x0050;
    push(cx);
    push(bx);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_3260: // 02f1:0350
    si++;
loc_3261: // 02f1:0351
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    if (memoryAGet(es, bx + si) == 0x00)
        goto loc_326d;
    goto loc_30a4;
loc_326d: // 02f1:035d
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_3271() // 02f1:0361
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(0x0001);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    si = 0;
    goto loc_32bd;
loc_32af: // 02f1:039f
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    al = memoryAGet(es, bx + si);
    al = ~al;
    memoryASet(es, bx + si, al);
    si += 0x0005;
loc_32bd: // 02f1:03ad
    if ((short)si < (short)0x0fa0)
        goto loc_32af;
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_32c6() // 02f1:03b6
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x8;
    push(si);
    push(di);
    memoryASet16(ss, bp - 2, 0xa000);
    memoryASet16(ss, bp - 4, 0x0000);
    if (memoryAGet16(ss, bp + 6) == 0x0001)
        goto loc_32e7;
    if (memoryAGet16(ss, bp + 6) == 0x0002)
        goto loc_32e7;
    push(cs);
    cs = 0x1282;
    sub_14897(); // 1282:2077
    assert(cs == 0x02f1);
loc_32e7: // 02f1:03d7
    ax = memoryAGet16(ss, bp + 6);
    if (ax == memoryAGet16(ds, 0x01a4))
        goto loc_3336;
    bx = ax;
    bx <<= 2;
    push(memoryAGet16(ds, bx + 482));
    push(memoryAGet16(ds, bx + 480));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x01a4, ax);
    push(dx);
    push(memoryAGet16(ss, bp - 8));
    push(0x0001);
    push(0x7d00);
    push(memoryAGet16(ds, 0x59f6));
    push(memoryAGet16(ds, 0x59f4));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
loc_3336: // 02f1:0426
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(0xff08);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(cs);
    cs = 0x1282;
    sub_12def(); // 1282:05cf
    assert(cs == 0x02f1);
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ss, bp - 6, 0x0100);
    di = 0;
    goto loc_3397;
loc_3365: // 02f1:0455
    ax = 0x0002;
    ax |= memoryAGet16(ss, bp - 6);
    push(ax);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    si = 0;
    goto loc_338a;
loc_337a: // 02f1:046a
    bx = memoryAGet16(ds, 0x59f4);
    es = memoryAGet16(ds, 0x59f4 + 2);
    bx += si;
    al = memoryAGet(es, bx + di);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet(es, bx + si, al);
    si++;
loc_338a: // 02f1:047a
    if ((short)si < (short)0x1f40)
        goto loc_337a;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) << 1);
    di += 0x1f40;
loc_3397: // 02f1:0487
    if (di < 0x7d00)
        goto loc_3365;
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_22d4(); // 01ed:0404
    assert(cs == 0x02f1);
    cx = pop();
    push(cs);
    cs = 0x1282;
    sub_12de7(); // 1282:05c7
    assert(cs == 0x02f1);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_33ae() // 02f1:049e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(0x0001);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    si = 0;
    goto loc_3440;
loc_33f6: // 02f1:04e6
    ax = si;
    ax <<= 3;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx + 16);
    ax >>= 1;
    ax <<= 1;
    cx = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 10);
    bx += ax;
    push(cx);
    push(bx);
    bx = si;
    bx += memoryAGet16(ss, bp + 14);
    bx <<= 2;
    ax = pop();
    dx = pop();
    memoryASet16(ds, bx + 41346, dx);
    memoryASet16(ds, bx + 41344, ax);
    ax = si;
    ax <<= 3;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 10);
    bx += ax;
    al = memoryAGet(es, bx + 18);
    bx = si;
    bx += memoryAGet16(ss, bp + 14);
    memoryASet(ds, bx + 22339, al);
    si++;
loc_3440: // 02f1:0530
    if ((short)si < (short)0x0017)
        goto loc_33f6;
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_3448() // 02f1:0538
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 6);
    al = memoryAGet(ds, si + 22338);
    ah = 0x00;
    if (ax < memoryAGet16(ds, 0xa474))
        goto loc_3476;
    al = memoryAGet(ds, si + 22338);
    ah = 0x00;
    memoryASet16(ds, 0xa474, ax);
    memoryASet16(ds, 0x57a6, 0x0001);
    ax = si;
    ax--;
    memoryASet16(ds, 0x57ba, ax);
    memoryASet16(ds, 0x59fc, 0x0000);
loc_3476: // 02f1:0566
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_3479() // 02f1:0569
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(0x0001);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_34b4() // 02f1:05a4
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(0x0001);
    push(0xffff);
    push(memoryAGet16(ds, 0x59ea));
    push(memoryAGet16(ds, 0x59e8));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(0xffff);
    push(memoryAGet16(ds, 0x59ee));
    push(memoryAGet16(ds, 0x59ec));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(ds);
    ax = 0x0970;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    ax++;
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x59f2));
    push(memoryAGet16(ds, 0x59f0));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_3530() // 02f1:0620
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x8;
    push(si);
    push(di);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(ss, bp - 6, es);
    memoryASet16(ss, bp - 8, bx);
    ax = memoryAGet16(ss, bp + 12);
    dx = 0;
    ax |= 0x0000;
    dx |= 0xa000;
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    di = 0;
    goto loc_3586;
loc_3555: // 02f1:0645
    si = 0x0100;
    goto loc_357f;
loc_355a: // 02f1:064a
    ax = si;
    ax |= 0x0002;
    push(ax);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet(es, bx + di, al);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
    ax = si;
    ax <<= 1;
    si = ax;
loc_357f: // 02f1:066f
    if (si < 0x1000)
        goto loc_355a;
    di++;
loc_3586: // 02f1:0676
    if (di < memoryAGet16(ss, bp + 10))
        goto loc_3555;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_358f() // 02f1:067f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(0x0001);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_35ca() // 02f1:06ba
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0xe;
    push(si);
    push(di);
    memoryASet16(ss, bp - 14, 0x0141);
    memoryASet16(ss, bp - 10, 0x0001);
    memoryASet16(ss, bp - 2, 0x6300);
    if (memoryAGet16(ds, 0x57b2) == 0x0000)
        goto loc_35fa;
    if (!(memoryAGet16(ds, 0x58a6) & 0x0001))
        goto loc_35f5;
    memoryASet16(ss, bp - 2, 0x7980);
    goto loc_35fa;
loc_35f5: // 02f1:06e5
    memoryASet16(ss, bp - 2, 0x6300);
loc_35fa: // 02f1:06ea
    ax = memoryAGet16(ds, 0x58a8);
    if (ax <= memoryAGet16(ds, 0xa456))
        goto loc_3609;
    ax = memoryAGet16(ds, 0xa456);
    memoryASet16(ds, 0x58a8, ax);
loc_3609: // 02f1:06f9
    if (memoryAGet16(ds, 0x57aa) == 0x0000)
        goto loc_361d;
    if (!(memoryAGet16(ds, 0x58a8) & 0x0001))
        goto loc_361d;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 0x2d00);
loc_361d: // 02f1:070d
    if (memoryAGet16(ds, 0x57aa) == 0x0000)
        goto loc_3637;
    ax = memoryAGet16(ds, 0x58a8);
    ax >>= 1;
    bx = 0x0012;
    dx = 0;
    div(bx);
    ax = dx;
    imul(ax, ax, 0x0050);
    goto loc_3639;
loc_3637: // 02f1:0727
    ax = 0;
loc_3639: // 02f1:0729
    push(ax);
    if (memoryAGet16(ds, 0x57b2) == 0x0000)
        goto loc_364f;
    ax = memoryAGet16(ds, 0x58a6);
    ax >>= 1;
    bx = 0x0028;
    dx = 0;
    div(bx);
    goto loc_3651;
loc_364f: // 02f1:073f
    dx = 0;
loc_3651: // 02f1:0741
    ax = pop();
    ax += dx;
    memoryASet16(ss, bp - 4, ax);
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    cl = memoryAGet(ds, 0x59fe);
    ax <<= cl;
    memoryASet16(ss, bp - 12, ax);
    di = memoryAGet16(ds, 0x58a8);
    cl = memoryAGet(ds, 0x59fe);
    di <<= cl;
loc_368a: // 02f1:077a
    si = 0;
loc_368c: // 02f1:077c
    ax = di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = si;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(ds, 0x58a6);
    ax <<= 1;
    bx += ax;
    memoryASet16(ss, bp - 6, es);
    memoryASet16(ss, bp - 8, bx);
    if (memoryAGet16(es, bx) >= 0x0050)
        goto loc_36d1;
    ax = si;
    ax += memoryAGet16(ss, bp - 14);
    push(ax);
    bx = memoryAGet16(ss, bp - 4);
    bx <<= 1;
    ax = si;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(ds, bx + 16572);
    ax += memoryAGet16(ss, bp - 2);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    goto loc_3731;
loc_36d1: // 02f1:07c1
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    if (memoryAGet16(es, bx) < 0x3e80)
        goto loc_371e;
    ax = si;
    ax += memoryAGet16(ss, bp - 14);
    push(ax);
    bx = memoryAGet16(ss, bp - 4);
    bx <<= 1;
    ax = si;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(ds, bx + 16572);
    ax += memoryAGet16(ss, bp - 2);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(memoryAGet16(ss, bp - 10));
    ax = si;
    ax++;
    push(ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    ax = memoryAGet16(es, bx);
    cx = memoryAGet16(ds, 0x58ac);
    bx = memoryAGet16(ds, 0x58aa);
    bx += ax;
    push(cx);
    push(bx);
    push(cs);
    cs = 0x01ed;
    sub_250b(); // 01ed:063b
    assert(cs == 0x02f1);
    sp += 0x0008;
    goto loc_3731;
loc_371e: // 02f1:080e
    ax = si;
    ax += memoryAGet16(ss, bp - 14);
    push(ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    push(memoryAGet16(es, bx));
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
loc_3731: // 02f1:0821
    si++;
    if ((short)si >= (short)0x0026)
        goto loc_373a;
    goto loc_368c;
loc_373a: // 02f1:082a
    memoryASet16(ss, bp - 14, memoryAGet16(ss, bp - 14) + 0x0140);
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0050);
    di += memoryAGet16(ds, 0xa468);
    if (di >= memoryAGet16(ss, bp - 12))
        goto loc_3752;
    goto loc_368a;
loc_3752: // 02f1:0842
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_3756() // 02f1:0846
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    es = memoryAGet16(ds, 0x5af0 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    dx = memoryAGet16(ss, bp + 8);
    dx <<= 2;
    ax += dx;
    memoryASet16(ss, bp - 2, ax);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    di = memoryAGet16(es, bx);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    si = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(ds, 0x58a6);
    if (ax > memoryAGet16(ss, bp + 10))
        goto loc_379f;
    ax += 0x0026;
    if (ax > memoryAGet16(ss, bp + 10))
        goto loc_37b2;
loc_379f: // 02f1:088f
    ax = memoryAGet16(ds, 0x58a6);
    if (ax < memoryAGet16(ss, bp + 10))
        goto loc_37e6;
    ax = memoryAGet16(ss, bp + 10);
    ax += si;
    if (ax <= memoryAGet16(ds, 0x58a6))
        goto loc_37e6;
loc_37b2: // 02f1:08a2
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    dx = memoryAGet16(ss, bp + 12);
    dx -= di;
    dx++;
    if (ax <= dx)
        goto loc_37cd;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= memoryAGet16(ss, bp + 12))
        goto loc_37e1;
loc_37cd: // 02f1:08bd
    ax = memoryAGet16(ss, bp + 12);
    if (ax < memoryAGet16(ds, 0x58a8))
        goto loc_37e6;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= memoryAGet16(ss, bp + 12))
        goto loc_37e6;
loc_37e1: // 02f1:08d1
    ax = 0x0001;
    goto loc_37e8;
loc_37e6: // 02f1:08d6
    ax = 0;
loc_37e8: // 02f1:08d8
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_37ec() // 02f1:08dc
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x8;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    es = memoryAGet16(ds, 0x5af0 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    dx = memoryAGet16(ss, bp + 10);
    dx <<= 2;
    ax += dx;
    memoryASet16(ss, bp - 2, ax);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    di = memoryAGet16(es, bx);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp + 6);
    if (ax <= 0x0003)
        goto loc_3833;
    goto loc_3a1e;
loc_3833: // 02f1:0923
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 2348)); // 02f1:0927
    return;
    //   gap of 482 bytes
loc_3a1e: // 02f1:0b0e
    ax = 0;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_3a24() // 02f1:0b14
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 8);
    memoryASet16(ds, 0x57d2, 0x0000);
    memoryASet16(ds, 0x57da, 0x0000);
    ax = memoryAGet16(ss, bp + 6);
    if (ax <= 0x0003)
        goto loc_3a44;
    goto loc_3d0d;
loc_3a44: // 02f1:0b34
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 2877)); // 02f1:0b38
    return;
    //   gap of 704 bytes
loc_3d0d: // 02f1:0dfd
    ax = 0;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_3d13() // 02f1:0e03
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x57fa) == 0x0000)
        goto loc_3d23;
    goto loc_3dc2;
loc_3d23: // 02f1:0e13
    ax = memoryAGet16(ss, bp + 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    es = memoryAGet16(ds, 0x5af0 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    dx = memoryAGet16(ss, bp + 8);
    dx <<= 2;
    ax += dx;
    memoryASet16(ss, bp - 2, ax);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    di = memoryAGet16(es, bx);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    si = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(ss, bp + 10);
    if (ax <= memoryAGet16(ds, 0xa468))
        goto loc_3d73;
    if (ax > 0xffff)
        goto loc_3d73;
    if (memoryAGet16(ss, bp + 6) != 0x001a)
        goto loc_3d73;
    ax += si;
    si = ax;
    memoryASet16(ss, bp + 10, 0x0000);
loc_3d73: // 02f1:0e63
    ax = memoryAGet16(ds, 0x5ae8);
    if (ax > memoryAGet16(ss, bp + 10))
        goto loc_3d83;
    ax += 0x0003;
    if (ax > memoryAGet16(ss, bp + 10))
        goto loc_3d96;
loc_3d83: // 02f1:0e73
    ax = memoryAGet16(ds, 0x5ae8);
    if (ax < memoryAGet16(ss, bp + 10))
        goto loc_3dc2;
    ax = memoryAGet16(ss, bp + 10);
    ax += si;
    if (ax <= memoryAGet16(ds, 0x5ae8))
        goto loc_3dc2;
loc_3d96: // 02f1:0e86
    ax = memoryAGet16(ss, bp + 12);
    ax -= di;
    if (ax >= memoryAGet16(ds, 0x5aee))
        goto loc_3da9;
    ax = memoryAGet16(ds, 0x5aee);
    if (ax <= memoryAGet16(ss, bp + 12))
        goto loc_3dbd;
loc_3da9: // 02f1:0e99
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffc;
    if (ax > memoryAGet16(ss, bp + 12))
        goto loc_3dc2;
    ax = memoryAGet16(ss, bp + 12);
    if (ax > memoryAGet16(ds, 0x5aee))
        goto loc_3dc2;
loc_3dbd: // 02f1:0ead
    ax = 0x0001;
    goto loc_3dc4;
loc_3dc2: // 02f1:0eb2
    ax = 0;
loc_3dc4: // 02f1:0eb4
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_3dc8() // 02f1:0eb8
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x8;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    es = memoryAGet16(ds, 0x5af0 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    dx = memoryAGet16(ss, bp + 8);
    dx <<= 2;
    ax += dx;
    memoryASet16(ss, bp - 6, ax);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    si = memoryAGet16(es, bx);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp + 14);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    ax = memoryAGet16(es, bx);
    dx = memoryAGet16(ss, bp + 16);
    dx <<= 2;
    ax += dx;
    memoryASet16(ss, bp - 2, ax);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    di = memoryAGet16(es, bx);
    ax = memoryAGet16(ss, bp - 2);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp + 10);
    if (ax <= memoryAGet16(ds, 0xa468))
        goto loc_3e53;
    if (ax > 0xffff)
        goto loc_3e53;
    ax += memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp + 10, 0x0000);
loc_3e53: // 02f1:0f43
    ax = memoryAGet16(ss, bp + 18);
    if (ax > memoryAGet16(ss, bp + 10))
        goto loc_3e63;
    ax += memoryAGet16(ss, bp - 4);
    if (ax > memoryAGet16(ss, bp + 10))
        goto loc_3e76;
loc_3e63: // 02f1:0f53
    ax = memoryAGet16(ss, bp + 18);
    if (ax < memoryAGet16(ss, bp + 10))
        goto loc_3e9f;
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 8);
    if (ax <= memoryAGet16(ss, bp + 18))
        goto loc_3e9f;
loc_3e76: // 02f1:0f66
    ax = memoryAGet16(ss, bp + 12);
    ax -= si;
    if (ax >= memoryAGet16(ss, bp + 20))
        goto loc_3e88;
    ax = memoryAGet16(ss, bp + 20);
    if (ax <= memoryAGet16(ss, bp + 12))
        goto loc_3e9a;
loc_3e88: // 02f1:0f78
    ax = memoryAGet16(ss, bp + 20);
    ax -= di;
    if (ax >= memoryAGet16(ss, bp + 12))
        goto loc_3e9f;
    ax = memoryAGet16(ss, bp + 12);
    if (ax > memoryAGet16(ss, bp + 20))
        goto loc_3e9f;
loc_3e9a: // 02f1:0f8a
    ax = 0x0001;
    goto loc_3ea1;
loc_3e9f: // 02f1:0f8f
    ax = 0;
loc_3ea1: // 02f1:0f91
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_3ea5() // 02f1:0f95
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0xe;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 10);
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    ax = memoryAGet16(ss, bp + 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    es = memoryAGet16(ds, 0x5af0 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    dx = memoryAGet16(ss, bp + 8);
    dx <<= 2;
    ax += dx;
    memoryASet16(ss, bp - 10, ax);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 12, ax);
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    bx = memoryAGet16(es, bx + 6);
    bx <<= 2;
    tx = bx;
    bx = memoryAGet16(ds, tx + 23016);
    es = memoryAGet16(ds, tx + 23016 + 2);
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    push(es);
    push(bx);
    bx = memoryAGet16(ds, 0x5af0);
    es = memoryAGet16(ds, 0x5af0 + 2);
    bx += ax;
    ax = pop();
    dx = pop();
    ax += memoryAGet16(es, bx + 4);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    ax = memoryAGet16(ss, bp + 14);
    if (ax > 0x0006)
        goto loc_3f63;
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 4131)); // 02f1:101e
    return;
    //   gap of 48 bytes
loc_3f63: // 02f1:1053
    if (memoryAGet16(ss, bp + 14) != 0x0004)
        goto loc_3f6c;
    goto loc_4018;
loc_3f6c: // 02f1:105c
    if (memoryAGet16(ss, bp + 14) != 0x0005)
        goto loc_3f75;
    goto loc_40a9;
loc_3f75: // 02f1:1065
    if (memoryAGet16(ss, bp + 14) != 0x0006)
        goto loc_3f7e;
    goto loc_4109;
loc_3f7e: // 02f1:106e
    di = memoryAGet16(ss, bp + 12);
    di -= memoryAGet16(ss, bp - 14);
    di++;
loc_3f85: // 02f1:1075
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_3fe9;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_3fe9;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_3fe9;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_3fe9;
    ax = si;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = di;
    cl = memoryAGet(ds, 0x59fe);
    ax <<= cl;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x20)
        goto loc_3fe9;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = memoryAGet16(ss, bp - 4 + 2);
    callIndirect(memoryAGet16(ss, bp - 4 + 2), memoryAGet16(ss, bp - 4));
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_3fe9: // 02f1:10d9
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_4014;
    if (di != memoryAGet16(ss, bp + 12))
        goto loc_400d;
    push(0xff08);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    goto loc_413d;
loc_400d: // 02f1:10fd
    si = memoryAGet16(ss, bp + 10);
    di++;
    goto loc_3f85;
loc_4014: // 02f1:1104
    si++;
    goto loc_3f85;
loc_4018: // 02f1:1108
    di = memoryAGet16(ss, bp + 12);
loc_401b: // 02f1:110b
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_4081;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_4081;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_4081;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_4081;
    ax = si;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = di;
    cl = memoryAGet(ds, 0x59fe);
    ax <<= cl;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x20)
        goto loc_4081;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x01ed;
    sub_274f(); // 01ed:087f
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_4081: // 02f1:1171
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_40a5;
    ax = memoryAGet16(ss, bp + 12);
    ax -= memoryAGet16(ss, bp - 14);
    ax++;
    if (ax != di)
        goto loc_409e;
    goto loc_413d;
loc_409e: // 02f1:118e
    si = memoryAGet16(ss, bp + 10);
    di--;
    goto loc_401b;
loc_40a5: // 02f1:1195
    si++;
    goto loc_401b;
loc_40a9: // 02f1:1199
    di = memoryAGet16(ss, bp + 12);
    di -= memoryAGet16(ss, bp - 14);
    di++;
loc_40b0: // 02f1:11a0
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_40ec;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_40ec;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_40ec;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_40ec;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = memoryAGet16(ss, bp - 4 + 2);
    callIndirect(memoryAGet16(ss, bp - 4 + 2), memoryAGet16(ss, bp - 4));
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_40ec: // 02f1:11dc
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_4106;
    if (di == memoryAGet16(ss, bp + 12))
        goto loc_413d;
    si = memoryAGet16(ss, bp + 10);
    di++;
    goto loc_40b0;
loc_4106: // 02f1:11f6
    si++;
    goto loc_40b0;
loc_4109: // 02f1:11f9
    di = memoryAGet16(ss, bp + 12);
    di -= memoryAGet16(ss, bp - 14);
    di++;
loc_4110: // 02f1:1200
    push(di);
    push(si);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_413a;
    if (di == memoryAGet16(ss, bp + 12))
        goto loc_413d;
    si = memoryAGet16(ss, bp + 10);
    di++;
    goto loc_4110;
loc_413a: // 02f1:122a
    si++;
    goto loc_4110;
loc_413d: // 02f1:122d
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_3f41() // 02f1:1031
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    memoryASet16(ss, bp - 2, 0x01ed);
    memoryASet16(ss, bp - 4, 0x0410);
    goto loc_3f63;
    //   gap of 22 bytes
loc_3f63: // 02f1:1053
    if (memoryAGet16(ss, bp + 14) != 0x0004)
        goto loc_3f6c;
    goto loc_4018;
loc_3f6c: // 02f1:105c
    if (memoryAGet16(ss, bp + 14) != 0x0005)
        goto loc_3f75;
    goto loc_40a9;
loc_3f75: // 02f1:1065
    if (memoryAGet16(ss, bp + 14) != 0x0006)
        goto loc_3f7e;
    goto loc_4109;
loc_3f7e: // 02f1:106e
    di = memoryAGet16(ss, bp + 12);
    di -= memoryAGet16(ss, bp - 14);
    di++;
loc_3f85: // 02f1:1075
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_3fe9;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_3fe9;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_3fe9;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_3fe9;
    ax = si;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = di;
    cl = memoryAGet(ds, 0x59fe);
    ax <<= cl;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x20)
        goto loc_3fe9;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = memoryAGet16(ss, bp - 4 + 2);
    callIndirect(memoryAGet16(ss, bp - 4 + 2), memoryAGet16(ss, bp - 4));
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_3fe9: // 02f1:10d9
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_4014;
    if (di != memoryAGet16(ss, bp + 12))
        goto loc_400d;
    push(0xff08);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    goto loc_413d;
loc_400d: // 02f1:10fd
    si = memoryAGet16(ss, bp + 10);
    di++;
    goto loc_3f85;
loc_4014: // 02f1:1104
    si++;
    goto loc_3f85;
loc_4018: // 02f1:1108
    di = memoryAGet16(ss, bp + 12);
loc_401b: // 02f1:110b
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_4081;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_4081;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_4081;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_4081;
    ax = si;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = di;
    cl = memoryAGet(ds, 0x59fe);
    ax <<= cl;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x20)
        goto loc_4081;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x01ed;
    sub_274f(); // 01ed:087f
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_4081: // 02f1:1171
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_40a5;
    ax = memoryAGet16(ss, bp + 12);
    ax -= memoryAGet16(ss, bp - 14);
    ax++;
    if (ax != di)
        goto loc_409e;
    goto loc_413d;
loc_409e: // 02f1:118e
    si = memoryAGet16(ss, bp + 10);
    di--;
    goto loc_401b;
loc_40a5: // 02f1:1195
    si++;
    goto loc_401b;
loc_40a9: // 02f1:1199
    di = memoryAGet16(ss, bp + 12);
    di -= memoryAGet16(ss, bp - 14);
    di++;
loc_40b0: // 02f1:11a0
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_40ec;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_40ec;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_40ec;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_40ec;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = memoryAGet16(ss, bp - 4 + 2);
    callIndirect(memoryAGet16(ss, bp - 4 + 2), memoryAGet16(ss, bp - 4));
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_40ec: // 02f1:11dc
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_4106;
    if (di == memoryAGet16(ss, bp + 12))
        goto loc_413d;
    si = memoryAGet16(ss, bp + 10);
    di++;
    goto loc_40b0;
loc_4106: // 02f1:11f6
    si++;
    goto loc_40b0;
loc_4109: // 02f1:11f9
    di = memoryAGet16(ss, bp + 12);
    di -= memoryAGet16(ss, bp - 14);
    di++;
loc_4110: // 02f1:1200
    push(di);
    push(si);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 10);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_413a;
    if (di == memoryAGet16(ss, bp + 12))
        goto loc_413d;
    si = memoryAGet16(ss, bp + 10);
    di++;
    goto loc_4110;
loc_413a: // 02f1:122a
    si++;
    goto loc_4110;
loc_413d: // 02f1:122d
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_4141() // 02f1:1231
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0xe;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 8);
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    ax = memoryAGet16(ss, bp + 12);
    if (ax > 0x0006)
        goto loc_4197;
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 4695)); // 02f1:1252
    assert(pop() == 0x7777); // CICO: preserve exit procedure
    cs = pop();
    return;
    //   gap of 48 bytes
loc_4197: // 02f1:1287
    if (memoryAGet16(ss, bp + 12) == 0x0006)
        goto loc_41c7;
    if (memoryAGet16(ds, 0xa446) != 0x00ff)
        goto loc_41a8;
    goto loc_4335;
loc_41a8: // 02f1:1298
    if (memoryAGet16(ds, 0xa2c4) == 0x0000)
        goto loc_41b2;
    goto loc_4335;
loc_41b2: // 02f1:12a2
    if (!(memoryAGet16(ds, 0xa464) & 0x0001))
        goto loc_41bd;
    goto loc_4335;
loc_41bd: // 02f1:12ad
    if (memoryAGet16(ds, 0x57b8) == 0x0000)
        goto loc_41c7;
    goto loc_4335;
loc_41c7: // 02f1:12b7
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    ax <<= 2;
    bx = memoryAGet16(ds, 0xa17c);
    es = memoryAGet16(ds, 0xa17c + 2);
    ax += memoryAGet16(es, bx);
    memoryASet16(ss, bp - 10, ax);
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa17c);
    bx += ax;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 12, ax);
    di = memoryAGet16(ss, bp + 10);
    di -= memoryAGet16(ss, bp - 14);
    di++;
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa17c);
    bx += ax;
    ax = memoryAGet16(es, bx + 4);
    bx = memoryAGet16(ds, 0x5aea);
    es = memoryAGet16(ds, 0x5aea + 2);
    bx += ax;
    memoryASet16(ss, bp - 6, es);
    memoryASet16(ss, bp - 8, bx);
    if (memoryAGet16(ss, bp + 12) != 0x0005)
        goto loc_4220;
    goto loc_42dc;
loc_4220: // 02f1:1310
    if (memoryAGet16(ss, bp + 12) != 0x0006)
        goto loc_4229;
    goto loc_42af;
loc_4229: // 02f1:1319
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_428d;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_428d;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_428d;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_428d;
    ax = si;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = di;
    cl = memoryAGet(ds, 0x59fe);
    ax <<= cl;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x20)
        goto loc_428d;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = memoryAGet16(ss, bp - 4 + 2);
    callIndirect(memoryAGet16(ss, bp - 4 + 2), memoryAGet16(ss, bp - 4));
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_428d: // 02f1:137d
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_42ab;
    if (di != memoryAGet16(ss, bp + 10))
        goto loc_42a4;
    goto loc_4335;
loc_42a4: // 02f1:1394
    si = memoryAGet16(ss, bp + 8);
    di++;
    goto loc_4229;
loc_42ab: // 02f1:139b
    si++;
    goto loc_4229;
loc_42af: // 02f1:139f
    push(di);
    push(si);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_42d9;
    if (di == memoryAGet16(ss, bp + 10))
        goto loc_4335;
    si = memoryAGet16(ss, bp + 8);
    di++;
    goto loc_42af;
loc_42d9: // 02f1:13c9
    si++;
    goto loc_42af;
loc_42dc: // 02f1:13cc
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_4318;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_4318;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_4318;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_4318;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = memoryAGet16(ss, bp - 4 + 2);
    callIndirect(memoryAGet16(ss, bp - 4 + 2), memoryAGet16(ss, bp - 4));
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_4318: // 02f1:1408
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_4332;
    if (di == memoryAGet16(ss, bp + 10))
        goto loc_4335;
    si = memoryAGet16(ss, bp + 8);
    di++;
    goto loc_42dc;
loc_4332: // 02f1:1422
    si++;
    goto loc_42dc;
loc_4335: // 02f1:1425
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_4175() // 02f1:1265
{
    // jump target
//    CStackGuardFar sg(0, true);
//    push(0x7777);
    memoryASet16(ss, bp - 2, 0x01ed);
    memoryASet16(ss, bp - 4, 0x0410);
    goto loc_4197;
    //   gap of 22 bytes
loc_4197: // 02f1:1287
    if (memoryAGet16(ss, bp + 12) == 0x0006)
        goto loc_41c7;
    if (memoryAGet16(ds, 0xa446) != 0x00ff)
        goto loc_41a8;
    goto loc_4335;
loc_41a8: // 02f1:1298
    if (memoryAGet16(ds, 0xa2c4) == 0x0000)
        goto loc_41b2;
    goto loc_4335;
loc_41b2: // 02f1:12a2
    if (!(memoryAGet16(ds, 0xa464) & 0x0001))
        goto loc_41bd;
    goto loc_4335;
loc_41bd: // 02f1:12ad
    if (memoryAGet16(ds, 0x57b8) == 0x0000)
        goto loc_41c7;
    goto loc_4335;
loc_41c7: // 02f1:12b7
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    ax <<= 2;
    bx = memoryAGet16(ds, 0xa17c);
    es = memoryAGet16(ds, 0xa17c + 2);
    ax += memoryAGet16(es, bx);
    memoryASet16(ss, bp - 10, ax);
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa17c);
    bx += ax;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 12, ax);
    di = memoryAGet16(ss, bp + 10);
    di -= memoryAGet16(ss, bp - 14);
    di++;
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa17c);
    bx += ax;
    ax = memoryAGet16(es, bx + 4);
    bx = memoryAGet16(ds, 0x5aea);
    es = memoryAGet16(ds, 0x5aea + 2);
    bx += ax;
    memoryASet16(ss, bp - 6, es);
    memoryASet16(ss, bp - 8, bx);
    if (memoryAGet16(ss, bp + 12) != 0x0005)
        goto loc_4220;
    goto loc_42dc;
loc_4220: // 02f1:1310
    if (memoryAGet16(ss, bp + 12) != 0x0006)
        goto loc_4229;
    goto loc_42af;
loc_4229: // 02f1:1319
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_428d;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_428d;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_428d;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_428d;
    ax = si;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = di;
    cl = memoryAGet(ds, 0x59fe);
    ax <<= cl;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x20)
        goto loc_428d;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = memoryAGet16(ss, bp - 4 + 2);
    callIndirect(memoryAGet16(ss, bp - 4 + 2), memoryAGet16(ss, bp - 4));
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_428d: // 02f1:137d
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_42ab;
    if (di != memoryAGet16(ss, bp + 10))
        goto loc_42a4;
    goto loc_4335;
loc_42a4: // 02f1:1394
    si = memoryAGet16(ss, bp + 8);
    di++;
    goto loc_4229;
loc_42ab: // 02f1:139b
    si++;
    goto loc_4229;
loc_42af: // 02f1:139f
    push(di);
    push(si);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_42d9;
    if (di == memoryAGet16(ss, bp + 10))
        goto loc_4335;
    si = memoryAGet16(ss, bp + 8);
    di++;
    goto loc_42af;
loc_42d9: // 02f1:13c9
    si++;
    goto loc_42af;
loc_42dc: // 02f1:13cc
    if (si < memoryAGet16(ds, 0x58a6))
        goto loc_4318;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= si)
        goto loc_4318;
    if (di < memoryAGet16(ds, 0x58a8))
        goto loc_4318;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0012;
    if (ax <= di)
        goto loc_4318;
    ax = di;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = si;
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = memoryAGet16(ss, bp - 4 + 2);
    callIndirect(memoryAGet16(ss, bp - 4 + 2), memoryAGet16(ss, bp - 4));
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_4318: // 02f1:1408
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 0x0028);
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp - 12);
    ax--;
    if (ax != si)
        goto loc_4332;
    if (di == memoryAGet16(ss, bp + 10))
        goto loc_4335;
    si = memoryAGet16(ss, bp + 8);
    di++;
    goto loc_42dc;
loc_4332: // 02f1:1422
    si++;
    goto loc_42dc;
loc_4335: // 02f1:1425
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
//    assert(pop() == 0x7777);
//    cs = pop();
}
void sub_4339() // 02f1:1429
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(0x0001);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(memoryAGet16(ds, 0x59fa));
    push(memoryAGet16(ds, 0x59f8));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_4380() // 02f1:1470
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0xa;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 8);
    push(0xff08);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    if (memoryAGet(ds, 0x01a3) == 0x01)
        goto loc_43b9;
    memoryASet(ds, 0x01a3, 0x01);
    push(ds);
    ax = 0x097b;
    push(ax);
    push(cs);
    sub_4339(); // 02f1:1429
    cx = pop();
    cx = pop();
loc_43b9: // 02f1:14a9
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    ax <<= 2;
    bx = memoryAGet16(ds, 0xa2ca);
    es = memoryAGet16(ds, 0xa2ca + 2);
    ax += memoryAGet16(es, bx);
    memoryASet16(ss, bp - 6, ax);
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa2ca);
    bx += ax;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 8, ax);
    di = memoryAGet16(ss, bp + 10);
    di -= memoryAGet16(ss, bp - 10);
    di++;
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa2ca);
    bx += ax;
    ax = memoryAGet16(es, bx + 4);
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
loc_4409: // 02f1:14f9
    push(di);
    push(si);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0028);
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp - 8);
    ax--;
    if (ax != si)
        goto loc_4433;
    if (di == memoryAGet16(ss, bp + 10))
        goto loc_4436;
    si = memoryAGet16(ss, bp + 8);
    di++;
    goto loc_4409;
loc_4433: // 02f1:1523
    si++;
    goto loc_4409;
loc_4436: // 02f1:1526
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_443a() // 02f1:152a
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0xa148) == 0x0000)
        goto loc_4449;
    goto loc_45b0;
loc_4449: // 02f1:1539
    bx = memoryAGet16(ds, 0xa17c);
    es = memoryAGet16(ds, 0xa17c + 2);
    di = memoryAGet16(es, bx);
    ax = di;
    ax <<= 1;
    bx += ax;
    si = memoryAGet16(es, bx + 2);
    si += memoryAGet16(ds, 0x5ae8);
    si--;
    if (memoryAGet(ds, 0xa45b) == 0x00)
        goto loc_4481;
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_4481;
    memoryASet(ds, 0xa45b, 0x00);
loc_4481: // 02f1:1571
    ax = memoryAGet16(ds, 0x5ae8);
    if (ax < memoryAGet16(ss, bp + 6))
        goto loc_448e;
    if (ax <= memoryAGet16(ss, bp + 8))
        goto loc_449e;
loc_448e: // 02f1:157e
    if (si >= memoryAGet16(ss, bp + 6))
        goto loc_4496;
    goto loc_45b0;
loc_4496: // 02f1:1586
    if (si <= memoryAGet16(ss, bp + 8))
        goto loc_449e;
    goto loc_45b0;
loc_449e: // 02f1:158e
    bx = memoryAGet16(ss, bp + 10);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) + ax);
    bx = memoryAGet16(ss, bp + 12);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 448);
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + ax);
    if (memoryAGet(ds, 0xa146) != 0x00)
        goto loc_44c6;
    if (memoryAGet(ds, 0xa2cf) == 0x00)
        goto loc_4521;
loc_44c6: // 02f1:15b6
    if (memoryAGet(ds, 0xa448) != 0x00)
        goto loc_4521;
    if (memoryAGet(ds, 0xa462) != 0x00)
        goto loc_4521;
    if (memoryAGet(ds, 0xa146) == 0x00)
        goto loc_44f2;
    if (memoryAGet16(ds, 0x58a8) <= 0x0000)
        goto loc_44f2;
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax >= 0x0011)
        goto loc_44f2;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
loc_44f2: // 02f1:15e2
    if (memoryAGet(ds, 0xa2cf) == 0x00)
        goto loc_4521;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0004;
    if (ax < memoryAGet16(ds, 0x5aee))
        goto loc_451d;
    bx = memoryAGet16(ss, bp + 12);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 448) != 0x0001)
        goto loc_4521;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0003;
    if (ax >= memoryAGet16(ds, 0x5aee))
        goto loc_4521;
loc_451d: // 02f1:160d
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
loc_4521: // 02f1:1611
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax <= 0x0011)
        goto loc_4533;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
    goto loc_4543;
loc_4533: // 02f1:1623
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax >= 0x0003)
        goto loc_4543;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
loc_4543: // 02f1:1633
    ax = memoryAGet16(ds, 0x5ae8);
    ax -= memoryAGet16(ds, 0x58a6);
    if (ax <= 0x0017)
        goto loc_4561;
    ax = memoryAGet16(ds, 0xa468);
    ax += 0xffda;
    if (ax <= memoryAGet16(ds, 0x58a6))
        goto loc_4561;
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) + 1);
    goto loc_4578;
loc_4561: // 02f1:1651
    ax = memoryAGet16(ds, 0x5ae8);
    ax -= memoryAGet16(ds, 0x58a6);
    if (ax >= 0x000c)
        goto loc_4578;
    if (memoryAGet16(ds, 0x58a6) <= 0x0000)
        goto loc_4578;
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) - 1);
loc_4578: // 02f1:1668
    bx = memoryAGet16(ss, bp + 12);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 448) != 0x0001)
        goto loc_4594;
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax <= 0x000e)
        goto loc_4594;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
loc_4594: // 02f1:1684
    bx = memoryAGet16(ss, bp + 12);
    bx <<= 1;
    if (memoryAGet16(ds, bx + 448) != 0xffff)
        goto loc_45b0;
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax >= 0x0003)
        goto loc_45b0;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
loc_45b0: // 02f1:16a0
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_45b4() // 02f1:16a4
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x6;
    push(si);
    push(di);
    di = 0;
    goto loc_46cf;
loc_45bf: // 02f1:16af
    ax = di;
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0x5a00;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 4, es);
    memoryASet16(ss, bp - 6, bx);
    si = 0x0002;
    goto loc_45f9;
loc_45d7: // 02f1:16c7
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(memoryAGet16(es, bx + 2));
    ax = memoryAGet16(es, bx);
    ax += si;
    ax += 0xfffc;
    push(ax);
    ax = si;
    ax <<= 1;
    bx += ax;
    push(memoryAGet16(es, bx));
    push(cs);
    cs = 0x02f1;
    sub_6284(); // 02f1:3374
    assert(cs == 0x02f1);
    sp += 0x0006;
    si++;
loc_45f9: // 02f1:16e9
    if (si < 0x0007)
        goto loc_45d7;
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(cs);
    cs = 0x02f1;
    sub_4923(); // 02f1:1a13
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    ax >>= 3;
    memoryASet16(ss, bp - 2, ax);
    if (memoryAGet16(ds, 0x57fa) != 0x0000)
        goto loc_464b;
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    ax = memoryAGet16(es, bx + 2);
    ax--;
    if (ax != memoryAGet16(ds, 0x5aee))
        goto loc_464b;
    if (memoryAGet16(ds, 0x5a94) == 0x0000)
        goto loc_464b;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 2));
    ax = memoryAGet16(es, bx);
    ax++;
    ax++;
    push(ax);
    ax = memoryAGet16(es, bx);
    ax += 0xfffe;
    push(ax);
    push(cs);
    sub_443a(); // 02f1:152a
    sp += 0x0008;
loc_464b: // 02f1:173b
    if (memoryAGet16(ds, 0x5a94) == 0x0000)
        goto loc_4671;
    bx = memoryAGet16(ss, bp - 2);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + ax);
    bx = memoryAGet16(ss, bp - 2);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 448);
    bx = memoryAGet16(ss, bp - 6);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + ax);
loc_4671: // 02f1:1761
    si = 0x0002;
    goto loc_469a;
loc_4676: // 02f1:1766
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(memoryAGet16(es, bx + 2));
    ax = memoryAGet16(es, bx);
    ax += si;
    ax += 0xfffc;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_4923(); // 02f1:1a13
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    dx = si;
    dx <<= 1;
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    bx += dx;
    memoryASet16(es, bx, ax);
    si++;
loc_469a: // 02f1:178a
    if (si < 0x0007)
        goto loc_4676;
    si = 0x0002;
    goto loc_46c9;
loc_46a4: // 02f1:1794
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    push(memoryAGet16(es, bx + 2));
    ax = memoryAGet16(es, bx);
    ax += si;
    ax += 0xfffc;
    push(ax);
    ax = si;
    ax += 0xfffe;
    ax <<= 3;
    ax += 0x3dd0;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_6284(); // 02f1:3374
    assert(cs == 0x02f1);
    sp += 0x0006;
    si++;
loc_46c9: // 02f1:17b9
    if (si < 0x0007)
        goto loc_46a4;
    di++;
loc_46cf: // 02f1:17bf
    if (di >= memoryAGet16(ds, 0x579c))
        goto loc_46d8;
    goto loc_45bf;
loc_46d8: // 02f1:17c8
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_4750() // 02f1:1840
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    si = 0;
    goto loc_4867;
loc_475a: // 02f1:184a
    ax = si;
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0xa2da;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    if (memoryAGet16(es, bx + 12) == 0x0000)
        goto loc_477b;
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) - 1);
    goto loc_4866;
loc_477b: // 02f1:186b
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 6, memoryAGet16(es, bx + 6) + 1);
    ax = memoryAGet16(es, bx + 6);
    if (ax != memoryAGet16(es, bx + 10))
        goto loc_47a8;
    memoryASet16(es, bx + 6, 0x0000);
    ax = memoryAGet16(es, bx + 4);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 12, 0x000a);
    goto loc_4866;
loc_47a8: // 02f1:1898
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(0x0000);
    push(cs);
    cs = 0x02f1;
    sub_6284(); // 02f1:3374
    assert(cs == 0x02f1);
    sp += 0x0006;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 2));
    ax = memoryAGet16(es, bx);
    ax++;
    ax++;
    push(ax);
    push(0x0000);
    push(cs);
    cs = 0x02f1;
    sub_6284(); // 02f1:3374
    assert(cs == 0x02f1);
    sp += 0x0006;
    if (memoryAGet16(ds, 0x57fa) != 0x0000)
        goto loc_481c;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 2);
    ax--;
    if (ax != memoryAGet16(ds, 0x5aee))
        goto loc_481c;
    if (memoryAGet16(es, bx + 4) == 0x0000)
        goto loc_4805;
    push(0x0005);
    push(0x0000);
    ax = memoryAGet16(es, bx);
    ax++;
    ax++;
    push(ax);
    push(memoryAGet16(es, bx));
    push(cs);
    sub_443a(); // 02f1:152a
    sp += 0x0008;
    goto loc_481c;
loc_4805: // 02f1:18f5
    push(0x0001);
    push(0x0000);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx);
    ax++;
    ax++;
    push(ax);
    push(memoryAGet16(es, bx));
    push(cs);
    sub_443a(); // 02f1:152a
    sp += 0x0008;
loc_481c: // 02f1:190c
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 4) == 0x0000)
        goto loc_4830;
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + 1);
    memoryASet16(es, bx + 8, memoryAGet16(es, bx + 8) - 1);
    goto loc_483b;
loc_4830: // 02f1:1920
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) - 1);
    memoryASet16(es, bx + 8, memoryAGet16(es, bx + 8) + 1);
loc_483b: // 02f1:192b
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(0x0048);
    push(cs);
    cs = 0x02f1;
    sub_6284(); // 02f1:3374
    assert(cs == 0x02f1);
    sp += 0x0006;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 2));
    ax = memoryAGet16(es, bx);
    ax++;
    ax++;
    push(ax);
    push(0x0048);
    push(cs);
    cs = 0x02f1;
    sub_6284(); // 02f1:3374
    assert(cs == 0x02f1);
    sp += 0x0006;
loc_4866: // 02f1:1956
    si++;
loc_4867: // 02f1:1957
    if (si >= memoryAGet16(ds, 0x57d8))
        goto loc_4870;
    goto loc_475a;
loc_4870: // 02f1:1960
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_4873() // 02f1:1963
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    push(di);
    memoryASet16(ds, 0x03dc, memoryAGet16(ds, 0x03dc) + 1);
    if (!(memoryAGet16(ds, 0x03dc) & 0x0001))
        goto loc_4889;
    memoryASet16(ds, 0x03da, memoryAGet16(ds, 0x03da) + 1);
loc_4889: // 02f1:1979
    di = 0;
    goto loc_4916;
loc_488e: // 02f1:197e
    ax = di;
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0xa2da;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    push(0x0000);
    ax = memoryAGet16(es, bx + 2);
    ax++;
    push(ax);
    push(memoryAGet16(es, bx));
    ax = memoryAGet16(ds, 0x03da);
    ax &= 0x0001;
    push(ax);
    push(0x004f);
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
    si = 0;
    goto loc_4909;
loc_48c0: // 02f1:19b0
    push(0x0000);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 2);
    ax += si;
    ax++;
    push(ax);
    ax = memoryAGet16(es, bx);
    ax++;
    push(ax);
    ax = memoryAGet16(ds, 0x03da);
    ax &= 0x0001;
    ax++;
    ax++;
    push(ax);
    push(0x004f);
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 2);
    ax += si;
    ax++;
    push(ax);
    ax = memoryAGet16(es, bx);
    ax++;
    push(ax);
    push(0x0002);
    push(0x004f);
    push(cs);
    sub_3d13(); // 02f1:0e03
    sp += 0x0008;
    if (!ax)
        goto loc_4908;
    push(cs);
    cs = 0x02f1;
    sub_d841(); // 02f1:a931
    assert(cs == 0x02f1);
loc_4908: // 02f1:19f8
    si++;
loc_4909: // 02f1:19f9
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 8);
    ax++;
    if (ax > si)
        goto loc_48c0;
    di++;
loc_4916: // 02f1:1a06
    if (di >= memoryAGet16(ds, 0x57d8))
        goto loc_491f;
    goto loc_488e;
loc_491f: // 02f1:1a0f
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_4923() // 02f1:1a13
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = memoryAGet16(ss, bp + 8);
    cl = memoryAGet(ds, 0x59fe);
    ax <<= cl;
    ax <<= 1;
    bx += ax;
    ax = memoryAGet16(es, bx);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_4943() // 02f1:1a33
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x6;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x5a8e) != 0x0000)
        goto loc_4953;
    goto loc_4a8f;
loc_4953: // 02f1:1a43
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    di = 0;
    goto loc_4a86;
loc_4964: // 02f1:1a54
    bx = di;
    bx <<= 3;
    bx += 0x5af4;
    push(ds);
    es = pop();
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 2, ax);
    bx = di;
    bx <<= 3;
    bx += 0x5af4;
    push(ds);
    es = pop();
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 6, ax);
    bx = di;
    bx <<= 3;
    bx += 0x5af4;
    push(ds);
    es = pop();
    ax = memoryAGet16(es, bx + 4);
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp - 6);
    if (ax >= memoryAGet16(ds, 0x58a6))
        goto loc_49a5;
    goto loc_4a1f;
loc_49a5: // 02f1:1a95
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= memoryAGet16(ss, bp - 6))
        goto loc_4a1f;
    ax = memoryAGet16(ss, bp - 4);
    if (ax < memoryAGet16(ds, 0x58a8))
        goto loc_4a1f;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0011;
    if (ax < memoryAGet16(ss, bp - 4))
        goto loc_4a1f;
    if (memoryAGet16(ss, bp - 2) != 0x0000)
        goto loc_49e5;
    ax = memoryAGet16(ss, bp - 4);
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_21b0(); // 01ed:02e0
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    goto loc_4a1f;
loc_49e5: // 02f1:1ad5
    if (memoryAGet16(ss, bp - 2) != 0x0001)
        goto loc_4a06;
    ax = memoryAGet16(ss, bp - 4);
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_221a(); // 01ed:034a
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    goto loc_4a1f;
loc_4a06: // 02f1:1af6
    ax = memoryAGet16(ss, bp - 4);
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_226a(); // 01ed:039a
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
loc_4a1f: // 02f1:1b0f
    si = memoryAGet16(ss, bp - 4);
    si++;
    goto loc_4a7b;
loc_4a25: // 02f1:1b15
    push(si);
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x01)
        goto loc_4a85;
    ax = memoryAGet16(ss, bp - 6);
    if (ax < memoryAGet16(ds, 0x58a6))
        goto loc_4a7a;
    ax = memoryAGet16(ds, 0x58a6);
    ax += 0x0026;
    if (ax <= memoryAGet16(ss, bp - 6))
        goto loc_4a7a;
    if (si < memoryAGet16(ds, 0x58a8))
        goto loc_4a7a;
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0011;
    if (ax < si)
        goto loc_4a7a;
    ax = si;
    ax -= memoryAGet16(ds, 0x58a8);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp - 6);
    ax -= memoryAGet16(ds, 0x58a6);
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_221a(); // 01ed:034a
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
loc_4a7a: // 02f1:1b6a
    si++;
loc_4a7b: // 02f1:1b6b
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x000b;
    if (ax > si)
        goto loc_4a25;
loc_4a85: // 02f1:1b75
    di++;
loc_4a86: // 02f1:1b76
    if (di >= memoryAGet16(ds, 0x57b6))
        goto loc_4a8f;
    goto loc_4964;
loc_4a8f: // 02f1:1b7f
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_6284() // 02f1:3374
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 8);
    dx <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += dx;
    dx = memoryAGet16(ss, bp + 10);
    cl = memoryAGet(ds, 0x59fe);
    dx <<= cl;
    dx <<= 1;
    bx += dx;
    memoryASet16(es, bx, ax);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_a84c() // 02f1:793c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 12);
    di = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0xa46e, ax);
    ax = memoryAGet16(ss, bp + 8);
    if (ax <= 0x0109)
        goto loc_a868;
    goto loc_cec9;
loc_a868: // 02f1:7958
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 31073)); // 02f1:795c
    return;
    //   gap of 9816 bytes
loc_cec9: // 02f1:9fb9
    al = 0x00;
    goto loc_cecf;
    //   gap of 2 bytes
loc_cecf: // 02f1:9fbf
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ced3() // 02f1:9fc3
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    si = 0;
    goto loc_cf1a;
loc_cee0: // 02f1:9fd0
    ax = si;
    imul(ax, ax, 0x0028);
    bx = ax;
    bx += 0x6136;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    if (memoryAGet16(es, bx + 30) == 0x0000)
        goto loc_cf19;
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(di);
    push(si);
    push(cs);
    sub_a84c(); // 02f1:793c
    sp += 0x0008;
    if (di != 0x0056)
        goto loc_cf60;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 8, 0x0001);
    goto loc_cf60;
loc_cf19: // 02f1:a009
    si++;
loc_cf1a: // 02f1:a00a
    if (si < memoryAGet16(ds, 0x579a))
        goto loc_cee0;
    if (memoryAGet16(ds, 0x579a) >= 0x0198)
        goto loc_cf60;
    ax = memoryAGet16(ds, 0x579a);
    imul(ax, ax, 0x0028);
    bx = ax;
    bx += 0x6136;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(di);
    push(memoryAGet16(ds, 0x579a));
    push(cs);
    sub_a84c(); // 02f1:793c
    sp += 0x0008;
    if (di != 0x0056)
        goto loc_cf5c;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 8, 0x0001);
loc_cf5c: // 02f1:a04c
    memoryASet16(ds, 0x579a, memoryAGet16(ds, 0x579a) + 1);
loc_cf60: // 02f1:a050
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cf64() // 02f1:a054
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
    push(cs);
    cs = 0x1a37;
    sub_1a383(); // 1a37:0013
    assert(cs == 0x02f1);
    bx = 0x0026;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    di = dx;
    di += memoryAGet16(ds, 0x58a6);
    push(cs);
    cs = 0x1a37;
    sub_1a383(); // 1a37:0013
    assert(cs == 0x02f1);
    bx = 0x0012;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    si = dx;
    si += memoryAGet16(ds, 0x58a8);
    push(si);
    push(di);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, ax);
    push(cs);
    cs = 0x1a37;
    sub_1a383(); // 1a37:0013
    assert(cs == 0x02f1);
    if (!(ax & 0x0001))
        goto loc_cfc5;
    ax = memoryAGet16(ss, bp - 2);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (!(memoryAGet(es, bx) & 0x10))
        goto loc_cfc5;
    push(0x0001);
    push(0x0000);
    push(si);
    push(di);
    push(0x0005);
    push(0x0063);
    push(cs);
    cs = 0x02f1;
    sub_d5b5(); // 02f1:a6a5
    assert(cs == 0x02f1);
    sp += 0x000c;
loc_cfc5: // 02f1:a0b5
    if (memoryAGet16(ds, 0x59de) == 0x0000)
        goto loc_cfef;
    si = memoryAGet16(ds, 0x58a8);
    si++;
    push(si);
    push(di);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    if (ax)
        goto loc_cfef;
    push(0x0014);
    push(0x0006);
    push(si);
    push(di);
    push(0x0001);
    push(0x001b);
    push(cs);
    cs = 0x02f1;
    sub_d5b5(); // 02f1:a6a5
    assert(cs == 0x02f1);
    sp += 0x000c;
loc_cfef: // 02f1:a0df
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cff3() // 02f1:a0e3
{
    CStackGuardFar sg(0, false);
    push(si);
    si = 0;
    goto loc_d00c;
loc_cff8: // 02f1:a0e8
    ax = si;
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0xa366;
    push(ds);
    es = pop();
    memoryASet16(es, bx + 8, 0x0000);
    si++;
loc_d00c: // 02f1:a0fc
    if (si < memoryAGet16(ds, 0x052a))
        goto loc_cff8;
    si = pop();
    cs = pop();
}
void sub_d082() // 02f1:a172
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    si = 0;
    goto loc_d28e;
loc_d08c: // 02f1:a17c
    ax = si;
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0xa366;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    if (memoryAGet16(es, bx + 8) != 0x0000)
        goto loc_d0a9;
    goto loc_d28d;
loc_d0a9: // 02f1:a199
    if (memoryAGet16(es, bx + 10) == 0x0000)
        goto loc_d0b7;
    if (memoryAGet16(es, bx + 10) != 0x0003)
        goto loc_d0ee;
loc_d0b7: // 02f1:a1a7
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 4);
    ax++;
    push(ax);
    ax = memoryAGet16(es, bx + 2);
    ax++;
    push(ax);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx));
    push(0x0003);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (ax)
        goto loc_d134;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + 1);
    if (memoryAGet16(es, bx + 10) != 0x0003)
        goto loc_d134;
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + 1);
    goto loc_d134;
loc_d0ee: // 02f1:a1de
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 10) == 0x0001)
        goto loc_d0ff;
    if (memoryAGet16(es, bx + 10) != 0x0004)
        goto loc_d134;
loc_d0ff: // 02f1:a1ef
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 4);
    ax++;
    push(ax);
    ax = memoryAGet16(es, bx + 2);
    ax--;
    push(ax);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx));
    push(0x0002);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (ax)
        goto loc_d134;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) - 1);
    if (memoryAGet16(es, bx + 10) != 0x0004)
        goto loc_d134;
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) - 1);
loc_d134: // 02f1:a224
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 8) >= 0x0005)
        goto loc_d143;
    memoryASet16(es, bx + 4, memoryAGet16(es, bx + 4) - 0x0002);
loc_d143: // 02f1:a233
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 8) != 0x0005)
        goto loc_d153;
    memoryASet16(es, bx + 4, memoryAGet16(es, bx + 4) - 1);
    goto loc_d192;
loc_d153: // 02f1:a243
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 8) != 0x0008)
        goto loc_d192;
    ax = memoryAGet16(es, bx + 4);
    ax++;
    push(ax);
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx));
    push(0x0001);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (!ax)
        goto loc_d18b;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 8, 0x0003);
    memoryASet16(es, bx + 4, memoryAGet16(es, bx + 4) + 0x0002);
    goto loc_d134;
loc_d18b: // 02f1:a27b
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 4, memoryAGet16(es, bx + 4) + 1);
loc_d192: // 02f1:a282
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 8) >= 0x0009)
        goto loc_d19f;
    goto loc_d237;
loc_d19f: // 02f1:a28f
    if (memoryAGet16(es, bx + 8) <= 0x0010)
        goto loc_d1c3;
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_3756(); // 02f1:0846
    sp += 0x0008;
    if (ax)
        goto loc_d1c3;
    goto loc_d284;
loc_d1c3: // 02f1:a2b3
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 12) != 0x0000)
        goto loc_d1eb;
    ax = memoryAGet16(es, bx + 4);
    ax++;
    push(ax);
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx));
    push(0x0001);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (ax)
        goto loc_d217;
loc_d1eb: // 02f1:a2db
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 4, memoryAGet16(es, bx + 4) + 1);
    if (memoryAGet16(es, bx + 12) != 0x0000)
        goto loc_d230;
    ax = memoryAGet16(es, bx + 4);
    ax++;
    push(ax);
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx));
    push(0x0001);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (!ax)
        goto loc_d230;
loc_d217: // 02f1:a307
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 8, 0x0003);
    memoryASet16(es, bx + 12, 0x0001);
    push(0x002e);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    goto loc_d134;
loc_d230: // 02f1:a320
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 4, memoryAGet16(es, bx + 4) + 1);
loc_d237: // 02f1:a327
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 8) != 0x0001)
        goto loc_d25b;
    push(0x0002);
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
    goto loc_d276;
loc_d25b: // 02f1:a34b
    push(0x0004);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
loc_d276: // 02f1:a366
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 8, memoryAGet16(es, bx + 8) + 1);
    if (memoryAGet16(es, bx + 8) <= 0x0028)
        goto loc_d28d;
loc_d284: // 02f1:a374
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 8, 0x0000);
loc_d28d: // 02f1:a37d
    si++;
loc_d28e: // 02f1:a37e
    if (si >= memoryAGet16(ds, 0x052a))
        goto loc_d297;
    goto loc_d08c;
loc_d297: // 02f1:a387
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d29a() // 02f1:a38a
{
    CStackGuardFar sg(0, false);
    push(si);
    si = 0;
    goto loc_d2b2;
loc_d29f: // 02f1:a38f
    ax = si;
    imul(ax, ax, 0x0006);
    bx = ax;
    bx += 0xa152;
    push(ds);
    es = pop();
    memoryASet16(es, bx, 0x0000);
    si++;
loc_d2b2: // 02f1:a3a2
    if (si < memoryAGet16(ds, 0x052e))
        goto loc_d29f;
    si = pop();
    cs = pop();
}
void sub_d304() // 02f1:a3f4
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    si = 0;
    goto loc_d3c0;
loc_d30e: // 02f1:a3fe
    ax = si;
    imul(ax, ax, 0x0006);
    bx = ax;
    bx += 0xa152;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    if (memoryAGet16(es, bx) != 0x0000)
        goto loc_d32a;
    goto loc_d3bf;
loc_d32a: // 02f1:a41a
    if (memoryAGet16(es, bx) != 0x0001)
        goto loc_d34f;
    push(0x0001);
    push(0x0000);
    ax = memoryAGet16(es, bx + 4);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(es, bx + 2);
    ax++;
    ax++;
    push(ax);
    push(0x0008);
    push(0x0017);
    push(cs);
    cs = 0x02f1;
    sub_d5b5(); // 02f1:a6a5
    assert(cs == 0x02f1);
    sp += 0x000c;
loc_d34f: // 02f1:a43f
    push(0x0000);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    ax = memoryAGet16(es, bx);
    ax--;
    ax &= 0x0003;
    push(ax);
    push(0x001a);
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    ax = memoryAGet16(es, bx);
    ax--;
    ax &= 0x0003;
    push(ax);
    push(0x001a);
    push(cs);
    sub_3d13(); // 02f1:0e03
    sp += 0x0008;
    if (!ax)
        goto loc_d392;
    push(cs);
    cs = 0x02f1;
    sub_d841(); // 02f1:a931
    assert(cs == 0x02f1);
loc_d392: // 02f1:a482
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + 1);
    if (memoryAGet16(es, bx) != 0x0009)
        goto loc_d3bf;
    memoryASet16(es, bx, 0x0000);
    push(0x0001);
    push(0x0001);
    ax = memoryAGet16(es, bx + 4);
    ax--;
    push(ax);
    ax = memoryAGet16(es, bx + 2);
    ax++;
    push(ax);
    push(0x0006);
    push(0x0062);
    push(cs);
    cs = 0x02f1;
    sub_d5b5(); // 02f1:a6a5
    assert(cs == 0x02f1);
    sp += 0x000c;
loc_d3bf: // 02f1:a4af
    si++;
loc_d3c0: // 02f1:a4b0
    if (si >= memoryAGet16(ds, 0x052e))
        goto loc_d3c9;
    goto loc_d30e;
loc_d3c9: // 02f1:a4b9
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d3cc() // 02f1:a4bc
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    si = 0;
    goto loc_d41f;
loc_d3d5: // 02f1:a4c5
    ax = si;
    imul(ax, ax, 0x0006);
    bx = ax;
    if (memoryAGet16(ds, bx + 41298) == 0x0000)
        goto loc_d41e;
    ax = si;
    imul(ax, ax, 0x0006);
    bx = ax;
    bx += 0xa152;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(0x0000);
    push(0x001a);
    push(cs);
    sub_3dc8(); // 02f1:0eb8
    sp += 0x0010;
    if (!ax)
        goto loc_d41e;
    ax = 0x0001;
    goto loc_d427;
loc_d41e: // 02f1:a50e
    si++;
loc_d41f: // 02f1:a50f
    if (si < memoryAGet16(ds, 0x052e))
        goto loc_d3d5;
    ax = 0;
loc_d427: // 02f1:a517
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d42a() // 02f1:a51a
{
    CStackGuardFar sg(0, false);
    push(si);
    si = 0;
    goto loc_d440;
loc_d42f: // 02f1:a51f
    bx = si;
    bx <<= 3;
    bx += 0x58ae;
    push(ds);
    es = pop();
    memoryASet16(es, bx, 0x0000);
    si++;
loc_d440: // 02f1:a530
    if (si < memoryAGet16(ds, 0x0530))
        goto loc_d42f;
    si = pop();
    cs = pop();
}
void sub_d48e() // 02f1:a57e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    si = 0;
    goto loc_d589;
loc_d498: // 02f1:a588
    bx = si;
    bx <<= 3;
    bx += 0x58ae;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    if (memoryAGet16(es, bx) != 0x0000)
        goto loc_d4b2;
    goto loc_d588;
loc_d4b2: // 02f1:a5a2
    memoryASet16(es, bx + 6, memoryAGet16(es, bx + 6) + 1);
    memoryASet16(es, bx + 4, memoryAGet16(es, bx + 4) - 1);
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(0x0000);
    push(memoryAGet16(es, bx));
    push(0x0000);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (ax)
        goto loc_d4fc;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 6) >= 0x0009)
        goto loc_d530;
    memoryASet16(es, bx + 4, memoryAGet16(es, bx + 4) - 1);
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(0x0000);
    push(memoryAGet16(es, bx));
    push(0x0000);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (!ax)
        goto loc_d530;
loc_d4fc: // 02f1:a5ec
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 4);
    ax++;
    push(ax);
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_ced3(); // 02f1:9fc3
    sp += 0x0006;
    push(0x0000);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 4);
    ax++;
    push(ax);
    push(memoryAGet16(es, bx + 2));
    push(0x0000);
    push(memoryAGet16(es, bx));
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
    goto loc_d565;
loc_d530: // 02f1:a620
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 6) != 0x000b)
        goto loc_d56f;
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_ced3(); // 02f1:9fc3
    sp += 0x0006;
    push(0x0004);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(0x0000);
    push(memoryAGet16(es, bx));
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
loc_d565: // 02f1:a655
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx, 0x0000);
    goto loc_d588;
loc_d56f: // 02f1:a65f
    push(0x0004);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(0x0000);
    push(memoryAGet16(es, bx));
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
loc_d588: // 02f1:a678
    si++;
loc_d589: // 02f1:a679
    if (si >= memoryAGet16(ds, 0x0530))
        goto loc_d592;
    goto loc_d498;
loc_d592: // 02f1:a682
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d595() // 02f1:a685
{
    CStackGuardFar sg(0, false);
    push(si);
    si = 0;
    goto loc_d5ad;
loc_d59a: // 02f1:a68a
    ax = si;
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0x5810;
    push(ds);
    es = pop();
    memoryASet16(es, bx, 0x0000);
    si++;
loc_d5ad: // 02f1:a69d
    if (si < memoryAGet16(ds, 0x0532))
        goto loc_d59a;
    si = pop();
    cs = pop();
}
void sub_d5b5() // 02f1:a6a5
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    si = 0;
    goto loc_d613;
loc_d5be: // 02f1:a6ae
    ax = si;
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0x5810;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    if (memoryAGet16(es, bx) != 0x0000)
        goto loc_d612;
    memoryASet16(es, bx, 0x0001);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(es, bx + 2, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(es, bx + 4, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(es, bx + 6, ax);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(es, bx + 8, ax);
    ax = memoryAGet16(ss, bp + 14);
    memoryASet16(es, bx + 10, ax);
    ax = memoryAGet16(ss, bp + 16);
    memoryASet16(es, bx + 12, ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 22460, 0x0000);
    goto loc_d619;
loc_d612: // 02f1:a702
    si++;
loc_d613: // 02f1:a703
    if (si < memoryAGet16(ds, 0x0532))
        goto loc_d5be;
loc_d619: // 02f1:a709
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_d61c() // 02f1:a70c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    si = 0;
    goto loc_d73e;
loc_d626: // 02f1:a716
    ax = si;
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0x5810;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    if (memoryAGet16(es, bx) != 0x0000)
        goto loc_d642;
    goto loc_d73d;
loc_d642: // 02f1:a732
    push(memoryAGet16(es, bx + 8));
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(cs);
    sub_3756(); // 02f1:0846
    sp += 0x0008;
    if (ax)
        goto loc_d660;
    goto loc_d735;
loc_d660: // 02f1:a750
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 2) == 0x0063)
        goto loc_d68c;
    push(0x0000);
    push(memoryAGet16(es, bx + 8));
    push(memoryAGet16(es, bx + 6));
    bx = si;
    bx <<= 1;
    push(memoryAGet16(ds, bx + 22460));
    bx = memoryAGet16(ss, bp - 4);
    push(memoryAGet16(es, bx + 2));
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
    goto loc_d6af;
loc_d68c: // 02f1:a77c
    push(0x0005);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 8));
    push(memoryAGet16(es, bx + 6));
    bx = si;
    bx <<= 1;
    push(memoryAGet16(ds, bx + 22460));
    bx = memoryAGet16(ss, bp - 4);
    push(memoryAGet16(es, bx + 2));
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
loc_d6af: // 02f1:a79f
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 2) != 0x001b)
        goto loc_d6cf;
    memoryASet16(es, bx + 6, memoryAGet16(es, bx + 6) - 1);
    push(cs);
    cs = 0x1a37;
    sub_1a383(); // 1a37:0013
    assert(cs == 0x02f1);
    bx = 0x0003;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 8, memoryAGet16(es, bx + 8) + dx);
loc_d6cf: // 02f1:a7bf
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    bx = memoryAGet16(es, bx + 10);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    bx = memoryAGet16(ss, bp - 4);
    memoryASet16(es, bx + 6, memoryAGet16(es, bx + 6) + ax);
    bx = memoryAGet16(ss, bp - 4);
    bx = memoryAGet16(es, bx + 10);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 448);
    bx = memoryAGet16(ss, bp - 4);
    memoryASet16(es, bx + 8, memoryAGet16(es, bx + 8) + ax);
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 22460, memoryAGet16(ds, bx + 22460) + 1);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 22460);
    bx = memoryAGet16(ss, bp - 4);
    if (ax != memoryAGet16(es, bx + 4))
        goto loc_d73d;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 22460, 0x0000);
    bx = memoryAGet16(ss, bp - 4);
    if (memoryAGet16(es, bx + 12) == 0x0000)
        goto loc_d73d;
    bx = memoryAGet16(ss, bp - 4);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) - 1);
    bx = memoryAGet16(ss, bp - 4);
    if (memoryAGet16(es, bx + 12) != 0x0000)
        goto loc_d73d;
loc_d735: // 02f1:a825
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx, 0x0000);
loc_d73d: // 02f1:a82d
    si++;
loc_d73e: // 02f1:a82e
    if ((short)si >= (short)memoryAGet16(ds, 0x0532))
        goto loc_d747;
    goto loc_d626;
loc_d747: // 02f1:a837
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d74a() // 02f1:a83a
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 6);
    if (memoryAGet16(ds, 0x57fa) == 0x0000)
        goto loc_d75b;
    goto loc_d83c;
loc_d75b: // 02f1:a84b
    if (memoryAGet16(ds, 0xa14a) == 0x0000)
        goto loc_d765;
    goto loc_d83c;
loc_d765: // 02f1:a855
    if (memoryAGet16(ds, 0x035a) == 0x0000)
        goto loc_d780;
    if (memoryAGet16(ds, 0x035a) != 0x0000)
        goto loc_d776;
    goto loc_d7fe;
loc_d776: // 02f1:a866
    if (memoryAGet16(ds, 0x0358) < 0x0002)
        goto loc_d780;
    goto loc_d7fe;
loc_d780: // 02f1:a870
    if (memoryAGet(ds, 0x58a4) == 0x00)
        goto loc_d78e;
    if ((short)memoryAGet16(ds, 0x5740) >= (short)0x0000)
        goto loc_d795;
loc_d78e: // 02f1:a87e
    if (memoryAGet(ds, 0x5742) <= 0x06)
        goto loc_d7fe;
loc_d795: // 02f1:a885
    if (memoryAGet16(ds, 0x57a8) == 0x0000)
        goto loc_d7fe;
    ax = si;
    ax++;
    memoryASet16(ds, 0x0358, ax);
    memoryASet16(ds, 0x40b6, ax);
    memoryASet16(ds, 0x035a, 0x0001);
    push(cs);
    sub_2f32(); // 02f1:0022
    if ((short)si <= (short)0x0012)
        goto loc_d7bc;
    memoryASet16(ds, 0x579e, 0x0001);
    goto loc_d7c2;
loc_d7bc: // 02f1:a8ac
    memoryASet16(ds, 0x579e, 0x0000);
loc_d7c2: // 02f1:a8b2
    memoryASet16(ds, 0x57e6, 0x0002);
    if (si != 0x0007)
        goto loc_d7f6;
    memoryASet16(ds, 0x57d0, memoryAGet16(ds, 0x57d0) + 1);
    if (memoryAGet16(ds, 0x57d0) != 0x000a)
        goto loc_d837;
    memoryASet16(ds, 0x57d0, 0x0000);
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffb;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    push(0x00f6);
    push(cs);
    sub_ced3(); // 02f1:9fc3
    sp += 0x0006;
    goto loc_d837;
loc_d7f6: // 02f1:a8e6
    memoryASet16(ds, 0x57d0, 0x0000);
    goto loc_d837;
loc_d7fe: // 02f1:a8ee
    ax = memoryAGet16(ds, 0x40b6);
    ax += 0xfffe;
    if (ax >= memoryAGet16(ds, 0x0358))
        goto loc_d83c;
    if (memoryAGet16(ds, 0x57a8) == 0x0000)
        goto loc_d83c;
    if (memoryAGet16(ds, 0x035a) == 0x0000)
        goto loc_d83c;
    push(cs);
    sub_2f32(); // 02f1:0022
    if (memoryAGet16(ds, 0x0358) <= 0x0012)
        goto loc_d82b;
    memoryASet16(ds, 0x579e, 0x0001);
    goto loc_d831;
loc_d82b: // 02f1:a91b
    memoryASet16(ds, 0x579e, 0x0000);
loc_d831: // 02f1:a921
    memoryASet16(ds, 0x57e6, 0x0002);
loc_d837: // 02f1:a927
    ax = 0x0001;
    goto loc_d83e;
loc_d83c: // 02f1:a92c
    ax = 0;
loc_d83e: // 02f1:a92e
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d841() // 02f1:a931
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    if (memoryAGet16(ds, 0x57fa) == 0x0000)
        goto loc_d84b;
    goto loc_d8de;
loc_d84b: // 02f1:a93b
    if (memoryAGet16(ds, 0x01d4) == 0x0000)
        goto loc_d855;
    goto loc_d8de;
loc_d855: // 02f1:a945
    if (memoryAGet16(ds, 0x57b8) == 0x0000)
        goto loc_d85f;
    goto loc_d8de;
loc_d85f: // 02f1:a94f
    if (memoryAGet16(ds, 0xa2c4) == 0x0000)
        goto loc_d869;
    goto loc_d8de;
loc_d869: // 02f1:a959
    if (memoryAGet(ds, 0xa478) != 0x00)
        goto loc_d8de;
    if (memoryAGet(ds, 0x57d6) != 0x00)
        goto loc_d8de;
    if (memoryAGet16(ds, 0xa464) != 0x0000)
        goto loc_d8de;
    memoryASet(ds, 0xa45b, 0x00);
    if (memoryAGet16(ds, 0x01aa) != 0x0000)
        goto loc_d8b3;
    memoryASet16(ds, 0x01aa, 0x0001);
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffb;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    push(0x00eb);
    push(cs);
    sub_ced3(); // 02f1:9fc3
    sp += 0x0006;
    if (memoryAGet16(ds, 0x57e6) != 0x0000)
        goto loc_d8b3;
    memoryASet16(ds, 0x57e6, 0x0001);
loc_d8b3: // 02f1:a9a3
    memoryASet16(ds, 0x589c, memoryAGet16(ds, 0x589c) - 1);
    if (memoryAGet16(ds, 0x589c) != 0x0000)
        goto loc_d8cc;
    memoryASet16(ds, 0x57fa, 0x0001);
    memoryASet16(ds, 0xa148, 0x0000);
    goto loc_d8de;
loc_d8cc: // 02f1:a9bc
    push(cs);
    cs = 0x1282;
    sub_1399b(); // 1282:117b
    assert(cs == 0x02f1);
    memoryASet16(ds, 0xa464, 0x002c);
    push(0x000e);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_d8de: // 02f1:a9ce
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d97d() // 02f1:aa6d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 10);
    si = memoryAGet16(ss, bp + 6);
    ax = si;
    cx = 0x0029;
    bx = 0xaa90;
loc_d990: // 02f1:aa80
    if (ax == memoryAGet16(cs, bx))
        goto loc_d99c;
    bx++;
    bx++;
    if (--cx)
        goto loc_d990;
    goto loc_dac8;
loc_d99c: // 02f1:aa8c
    jumpIndirect(cs, memoryAGet16(cs, bx + 82)); // 02f1:aa8c
    return;
    //   gap of 296 bytes
loc_dac8: // 02f1:abb8
    ax = 0;
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_dbad() // 02f1:ac9d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x10;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    imul(ax, ax, 0x0028);
    bx = ax;
    bx += 0x6136;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 4, es);
    memoryASet16(ss, bp - 6, bx);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    sub_3756(); // 02f1:0846
    sp += 0x0008;
    if (ax)
        goto loc_dbe1;
    goto loc_eeeb;
loc_dbe1: // 02f1:acd1
    ax = memoryAGet16(ss, bp + 8);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    es = memoryAGet16(ds, 0x5af0 + 2);
    bx += ax;
    di = memoryAGet16(es, bx);
    ax = memoryAGet16(ss, bp + 10);
    ax <<= 2;
    di += ax;
    ax = di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    si = memoryAGet16(es, bx);
    ax = di;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x5af0);
    bx += ax;
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ss, bp - 2, ax);
    memoryASet16(ds, 0x57a8, 0x0000);
    if (memoryAGet16(ss, bp + 8) != 0x0066)
        goto loc_dc59;
    si = 0x0007;
    ax = memoryAGet16(ss, bp + 14);
    ax -= si;
    ax += 0x0005;
    if (ax >= memoryAGet16(ds, 0x5aee))
        goto loc_dc35;
    goto loc_dca4;
loc_dc35: // 02f1:ad25
    ax = memoryAGet16(ss, bp + 14);
    ax -= si;
    if (ax > memoryAGet16(ds, 0x5aee))
        goto loc_dca4;
    ax = memoryAGet16(ds, 0x5ae8);
    ax++;
    ax++;
    if (ax < memoryAGet16(ss, bp + 12))
        goto loc_dca4;
    ax = memoryAGet16(ss, bp + 12);
    ax += memoryAGet16(ss, bp - 2);
    ax--;
    if (ax < memoryAGet16(ds, 0x5ae8))
        goto loc_dca4;
    goto loc_dc9e;
loc_dc59: // 02f1:ad49
    if ((short)memoryAGet16(ds, 0x5740) <= (short)0x0003)
        goto loc_dc65;
    ax = 0x0001;
    goto loc_dc67;
loc_dc65: // 02f1:ad55
    ax = 0;
loc_dc67: // 02f1:ad57
    dx = memoryAGet16(ss, bp + 14);
    dx -= si;
    ax += dx;
    ax++;
    if (ax < memoryAGet16(ds, 0x5aee))
        goto loc_dca4;
    ax = memoryAGet16(ss, bp + 14);
    ax -= si;
    if (ax > memoryAGet16(ds, 0x5aee))
        goto loc_dca4;
    ax = memoryAGet16(ds, 0x5ae8);
    ax++;
    ax++;
    if (ax < memoryAGet16(ss, bp + 12))
        goto loc_dca4;
    ax = memoryAGet16(ss, bp + 12);
    ax += memoryAGet16(ss, bp - 2);
    ax--;
    if (ax < memoryAGet16(ds, 0x5ae8))
        goto loc_dca4;
    if (memoryAGet16(ds, 0xa148) != 0x0000)
        goto loc_dca4;
loc_dc9e: // 02f1:ad8e
    memoryASet16(ds, 0x57a8, 0x0001);
loc_dca4: // 02f1:ad94
    ax = memoryAGet16(ss, bp + 8);
    cx = 0x0018;
    bx = 0xadad;
loc_dcad: // 02f1:ad9d
    if (ax == memoryAGet16(cs, bx))
        goto loc_dcb9;
    bx++;
    bx++;
    if (--cx)
        goto loc_dcad;
    goto loc_e460;
loc_dcb9: // 02f1:ada9
    jumpIndirect(cs, memoryAGet16(cs, bx + 48)); // 02f1:ada9
    return;
    //   gap of 1955 bytes
loc_e460: // 02f1:b550
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    sub_3d13(); // 02f1:0e03
    sp += 0x0008;
    if (ax)
        goto loc_e47a;
    goto loc_efc4;
loc_e47a: // 02f1:b56a
    ax = memoryAGet16(ss, bp + 8);
    ax--;
    if (ax <= 0x00ec)
        goto loc_e486;
    goto loc_efc4;
loc_e486: // 02f1:b576
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 46463)); // 02f1:b57a
    return;
    //   gap of 2652 bytes
loc_eeeb: // 02f1:bfdb
    ax = 0x0001;
    goto loc_efc6;
    //   gap of 211 bytes
loc_efc4: // 02f1:c0b4
    ax = 0;
loc_efc6: // 02f1:c0b6
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_efca() // 02f1:c0ba
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    si = memoryAGet16(ss, bp + 6);
    ax = si;
    imul(ax, ax, 0x0028);
    bx = ax;
    bx += 0x6136;
    push(ds);
    es = pop();
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    if (memoryAGet16(es, bx + 30) == 0x0000)
        goto loc_efef;
    goto loc_f1b5;
loc_efef: // 02f1:c0df
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(ds, 0xa456);
    dx += 0x0015;
    if (ax <= dx)
        goto loc_f001;
    goto loc_f168;
loc_f001: // 02f1:c0f1
    memoryASet16(ds, 0xa2c0, 0x0000);
    if (memoryAGet(es, bx + 34) == 0x00)
        goto loc_f012;
    memoryASet(es, bx + 34, memoryAGet(es, bx + 34) - 1);
loc_f012: // 02f1:c102
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_3756(); // 02f1:0846
    sp += 0x0008;
    if (!ax)
        goto loc_f041;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 10) == 0x0000)
        goto loc_f054;
    memoryASet16(es, bx + 8, 0x0001);
    goto loc_f054;
loc_f041: // 02f1:c131
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 8) != 0x0000)
        goto loc_f04e;
    goto loc_f1b5;
loc_f04e: // 02f1:c13e
    memoryASet16(ds, 0xa2c0, 0x0001);
loc_f054: // 02f1:c144
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 14) != 0x0000)
        goto loc_f061;
    goto loc_f102;
loc_f061: // 02f1:c151
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    push(0x0000);
    push(memoryAGet16(es, bx));
    push(0x0001);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (!ax)
        goto loc_f088;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 6, memoryAGet16(es, bx + 6) - 1);
    memoryASet16(es, bx + 32, 0x0000);
loc_f088: // 02f1:c178
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 6);
    ax++;
    push(ax);
    push(memoryAGet16(es, bx + 4));
    push(0x0000);
    push(memoryAGet16(es, bx));
    push(0x0001);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (ax)
        goto loc_f0f9;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 32) >= 0x0005)
        goto loc_f0b5;
    memoryASet16(es, bx + 32, memoryAGet16(es, bx + 32) + 1);
loc_f0b5: // 02f1:c1a5
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 32) <= 0x0001)
        goto loc_f0ca;
    if (memoryAGet16(es, bx + 32) >= 0x0006)
        goto loc_f0ca;
    memoryASet16(es, bx + 6, memoryAGet16(es, bx + 6) + 1);
loc_f0ca: // 02f1:c1ba
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet16(es, bx + 32) != 0x0005)
        goto loc_f102;
    ax = memoryAGet16(es, bx + 6);
    ax++;
    push(ax);
    push(memoryAGet16(es, bx + 4));
    push(0x0000);
    push(memoryAGet16(es, bx));
    push(0x0001);
    push(cs);
    sub_37ec(); // 02f1:08dc
    sp += 0x000a;
    if (ax)
        goto loc_f0f9;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 6, memoryAGet16(es, bx + 6) + 1);
    goto loc_f102;
loc_f0f9: // 02f1:c1e9
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 32, 0x0000);
loc_f102: // 02f1:c1f2
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_3756(); // 02f1:0846
    sp += 0x0008;
    if (!ax)
        goto loc_f125;
    memoryASet16(ds, 0xa2c0, 0x0000);
loc_f125: // 02f1:c215
    push(si);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(cs);
    cs = memoryAGet16(es, bx + 36 + 2);
    callIndirect(memoryAGet16(es, bx + 36 + 2), memoryAGet16(es, bx + 36));
    assert(cs == 0x02f1);
    cx = pop();
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_d3cc(); // 02f1:a4bc
    sp += 0x0008;
    if (!ax)
        goto loc_f173;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_d97d(); // 02f1:aa6d
    sp += 0x0008;
    if (!ax)
        goto loc_f173;
loc_f168: // 02f1:c258
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 30, 0x0001);
    goto loc_f1b5;
loc_f173: // 02f1:c263
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(si);
    push(cs);
    sub_dbad(); // 02f1:ac9d
    sp += 0x000a;
    if (ax)
        goto loc_f1b5;
    if (memoryAGet16(ds, 0xa2c0) == 0x0001)
        goto loc_f1b5;
    push(memoryAGet16(ds, 0xa2c0));
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
loc_f1b5: // 02f1:c2a5
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_f1b8() // 02f1:c2a8
{
    CStackGuardFar sg(0, false);
    push(si);
    memoryASet16(ds, 0xa46c, 0x0000);
    si = 0;
    goto loc_f1ca;
loc_f1c3: // 02f1:c2b3
    push(si);
    push(cs);
    sub_efca(); // 02f1:c0ba
    cx = pop();
    si++;
loc_f1ca: // 02f1:c2ba
    if (si < memoryAGet16(ds, 0x579a))
        goto loc_f1c3;
    if (memoryAGet16(ds, 0x573e) == 0x0000)
        goto loc_f1dd;
    memoryASet16(ds, 0x573e, 0x0000);
loc_f1dd: // 02f1:c2cd
    si = pop();
    cs = pop();
}
void sub_f1df() // 02f1:c2cf
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x02f1);
    cx = pop();
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    cs = 0x02f1;
    sub_118ac(); // 02f1:e99c
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet(ss, bp - 1, al);
    ax = memoryAGet16(ss, bp + 6);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x02f1);
    cx = pop();
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_f226() // 02f1:c316
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
    memoryASet16(ss, bp - 2, 0x0000);
    di = 0;
    goto loc_f29a;
loc_f235: // 02f1:c325
    si = 0;
    goto loc_f294;
loc_f239: // 02f1:c329
    ax = memoryAGet16(ss, bp - 2);
    push(ax);
    ax = di;
    imul(ax, ax, 0x00a0);
    bx = ax;
    ax = si;
    ax <<= 1;
    bx += ax;
    ax = pop();
    memoryASet16(ds, bx + 16652, ax);
    push(ax);
    ax = di;
    imul(ax, ax, 0x00a0);
    bx = ax;
    ax = si;
    ax <<= 1;
    bx += ax;
    ax = pop();
    memoryASet16(ds, bx + 16572, ax);
    ax = memoryAGet16(ss, bp - 2);
    push(ax);
    ax = di;
    imul(ax, ax, 0x00a0);
    bx = ax;
    ax = si;
    ax <<= 1;
    bx += ax;
    ax = pop();
    memoryASet16(ds, bx + 19532, ax);
    push(ax);
    ax = di;
    imul(ax, ax, 0x00a0);
    bx = ax;
    ax = si;
    ax <<= 1;
    bx += ax;
    ax = pop();
    memoryASet16(ds, bx + 19452, ax);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 0x0008);
    si++;
loc_f294: // 02f1:c384
    if ((short)si < (short)0x0028)
        goto loc_f239;
    di++;
loc_f29a: // 02f1:c38a
    if ((short)di < (short)0x0012)
        goto loc_f235;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_f3bb() // 02f1:c4ab
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x8;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ss, bp - 2, 0xb800);
    memoryASet16(ss, bp - 4, 0x0000);
    push(dx);
    push(ax);
    push(0x0001);
    push(0x0fa0);
    push(ds);
    ax = 0x40bc;
    push(ax);
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(0x0fa0);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(ds);
    ax = 0x40bc;
    push(ax);
    push(cs);
    cs = 0x188e;
    sub_188e2(); // 188e:0002
    assert(cs == 0x02f1);
    sp += 0x000a;
    push(ds);
    ax = 0x0987;
    push(ax);
    push(cs);
    cs = 0x18ac;
    sub_18acf(); // 18ac:000f
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_f414() // 02f1:c504
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    ax = 0x099e;
    push(ax);
    push(memoryAGet16(ds, 0xa47c));
    push(memoryAGet16(ds, 0xa47a));
    push(cs);
    cs = 0x02f1;
    sub_10f20(); // 02f1:e010
    assert(cs == 0x02f1);
    sp += 0x0008;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1282;
    sub_163e0(); // 1282:3bc0
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    flags.interrupts = false;
    push(memoryAGet16(ds, 0x57e4));
    push(memoryAGet16(ds, 0x57e2));
    push(0x0009);
    push(cs);
    cs = 0x1a01;
    sub_1a02d(); // 1a01:001d
    assert(cs == 0x02f1);
    sp += 0x0006;
    flags.interrupts = true;
    push(cs);
    cs = 0x1282;
    sub_12def(); // 1282:05cf
    assert(cs == 0x02f1);
    push(0x0003);
    push(cs);
    cs = 0x1a79;
    sub_1a798(); // 1a79:0008
    assert(cs == 0x02f1);
    cx = pop();
    in(al, 0x61);
    al &= 0xfd;
    out(0x61, al);
    push(cs);
    cs = 0x1282;
    sub_12c3f(); // 1282:041f
    assert(cs == 0x02f1);
    push(ds);
    ax = 0x09a9;
    push(ax);
    push(cs);
    cs = 0x1884;
    sub_18840(); // 1884:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x09b4;
    push(ax);
    push(cs);
    sub_f3bb(); // 02f1:c4ab
    cx = pop();
    cx = pop();
    push(0x0000);
    push(cs);
    cs = 0x1711;
    sub_1711f(); // 1711:000f
    assert(cs == 0x02f1);
    cx = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_f47e() // 02f1:c56e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(0x0001);
    push(0x1b58);
    push(memoryAGet16(ds, 0xa2d2));
    push(memoryAGet16(ds, 0xa2d0));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_f4bb() // 02f1:c5ab
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(0x0001);
    push(0x9c40);
    push(memoryAGet16(ds, 0x58ac));
    push(memoryAGet16(ds, 0x58aa));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_f4f8() // 02f1:c5e8
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x14;
    memoryASet(ss, bp - 19, 0x0f);
    push(ss);
    ax = bp - 0x14;
    push(ax);
    push(ss);
    ax = bp - 0x14;
    push(ax);
    push(0x0010);
    push(cs);
    cs = 0x1a14;
    sub_1a14f(); // 1a14:000f
    assert(cs == 0x02f1);
    sp += 0x000a;
    if (memoryAGet(ss, bp - 20) == 0x0d)
        goto loc_f536;
    push(0x0003);
    push(cs);
    cs = 0x1a79;
    sub_1a798(); // 1a79:0008
    assert(cs == 0x02f1);
    cx = pop();
    push(ds);
    ax = 0x09bf;
    push(ax);
    push(cs);
    cs = 0x18ac;
    sub_18acf(); // 18ac:000f
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(0x0000);
    push(cs);
    cs = 0x1711;
    sub_1711f(); // 1711:000f
    assert(cs == 0x02f1);
    cx = pop();
loc_f536: // 02f1:c626
    push(cs);
    cs = 0x1931;
    sub_19310(); // 1931:0000
    assert(cs == 0x02f1);
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    if (memoryAGet(ds, 0xa5aa) == 0x00)
        goto loc_f554;
    if (dx < 0x0005)
        goto loc_f56a;
    if (dx != 0x0005)
        goto loc_f554;
    if (ax < 0xf688)
        goto loc_f56a;
loc_f554: // 02f1:c644
    if (memoryAGet(ds, 0xa5aa) != 0x00)
        goto loc_f58a;
    if (memoryAGet16(ss, bp - 2) > 0x0005)
        goto loc_f58a;
    if (memoryAGet16(ss, bp - 2) < 0x0005)
        goto loc_f56a;
    if (memoryAGet16(ss, bp - 4) >= 0xdb30)
        goto loc_f58a;
loc_f56a: // 02f1:c65a
    push(cs);
    cs = 0x1282;
    sub_12c3f(); // 1282:041f
    assert(cs == 0x02f1);
    push(0x0003);
    push(cs);
    cs = 0x1a79;
    sub_1a798(); // 1a79:0008
    assert(cs == 0x02f1);
    cx = pop();
    push(ds);
    ax = 0x09d7;
    push(ax);
    push(cs);
    sub_f3bb(); // 02f1:c4ab
    cx = pop();
    cx = pop();
    push(0x0000);
    push(cs);
    cs = 0x1711;
    sub_1711f(); // 1711:000f
    assert(cs == 0x02f1);
    cx = pop();
loc_f58a: // 02f1:c67a
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_f58c() // 02f1:c67c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(0x000d);
    push(cs);
    cs = 0x01ed;
    sub_209d(); // 01ed:01cd
    assert(cs == 0x02f1);
    cx = pop();
    push(cs);
    cs = 0x1282;
    sub_12bbf(); // 1282:039f
    assert(cs == 0x02f1);
    push(cs);
    sub_f4f8(); // 02f1:c5e8
    push(cs);
    cs = 0x1931;
    sub_19310(); // 1931:0000
    assert(cs == 0x02f1);
    memoryASet16(ds, 0xa2d6, dx);
    memoryASet16(ds, 0xa2d4, ax);
    flags.interrupts = false;
    push(0x0009);
    push(cs);
    cs = 0x1a01;
    sub_1a01b(); // 1a01:000b
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x57e4, dx);
    memoryASet16(ds, 0x57e2, ax);
    push(cs);
    ax = 0xc393;
    push(ax);
    push(0x0009);
    push(cs);
    cs = 0x1a01;
    sub_1a02d(); // 1a01:001d
    assert(cs == 0x02f1);
    sp += 0x0006;
    memoryASet16(ds, 0x59fc, 0x0000);
    memoryASet16(ds, 0xa474, 0x0000);
    memoryASet16(ds, 0xa44e, 0x0000);
    memoryASet16(ds, 0xa150, 0x0001);
    flags.interrupts = true;
    push(0x88b8);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x59f6, dx);
    memoryASet16(ds, 0x59f4, ax);
    push(0x0000);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
    push(0x00c8);
    push(cs);
    cs = 0x1282;
    sub_12d22(); // 1282:0502
    assert(cs == 0x02f1);
    cx = pop();
    push(ds);
    ax = 0x099e;
    push(ax);
    push(memoryAGet16(ds, 0xa47c));
    push(memoryAGet16(ds, 0xa47a));
    push(cs);
    cs = 0x02f1;
    sub_10f20(); // 02f1:e010
    assert(cs == 0x02f1);
    sp += 0x0008;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1282;
    sub_16190(); // 1282:3970
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_20b6(); // 01ed:01e6
    assert(cs == 0x02f1);
    cx = pop();
    push(cs);
    sub_f226(); // 02f1:c316
    push(0x9c40);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x58ac, dx);
    memoryASet16(ds, 0x58aa, ax);
    push(ds);
    ax = 0x09e4;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x5a92, dx);
    memoryASet16(ds, 0x5a90, ax);
    push(ds);
    ax = 0x09ef;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x5800, dx);
    memoryASet16(ds, 0x57fe, ax);
    push(ds);
    ax = 0x09fb;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x5804, dx);
    memoryASet16(ds, 0x5802, ax);
    push(0x0000);
    push(memoryAGet16(ds, 0x5a92));
    push(memoryAGet16(ds, 0x5a90));
    push(ds);
    ax = 0x09e4;
    push(ax);
    push(cs);
    sub_33ae(); // 02f1:049e
    sp += 0x000a;
    push(0x0017);
    push(memoryAGet16(ds, 0x5800));
    push(memoryAGet16(ds, 0x57fe));
    push(ds);
    ax = 0x09ef;
    push(ax);
    push(cs);
    sub_33ae(); // 02f1:049e
    sp += 0x000a;
    push(0x002e);
    push(memoryAGet16(ds, 0x5804));
    push(memoryAGet16(ds, 0x5802));
    push(ds);
    ax = 0x09fb;
    push(ax);
    push(cs);
    sub_33ae(); // 02f1:049e
    sp += 0x000a;
    push(ds);
    ax = 0x0a07;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x5aec, dx);
    memoryASet16(ds, 0x5aea, ax);
    push(0xffff);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x59fa, dx);
    memoryASet16(ds, 0x59f8, ax);
    push(0xffff);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x59ea, dx);
    memoryASet16(ds, 0x59e8, ax);
    push(0xffff);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x59ee, dx);
    memoryASet16(ds, 0x59ec, ax);
    push(ds);
    ax = 0x0970;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    ax++;
    ax++;
    push(ax);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x59f2, dx);
    memoryASet16(ds, 0x59f0, ax);
    push(0x1c80);
    push(memoryAGet16(ds, 0x59ea));
    push(memoryAGet16(ds, 0x59e8));
    push(ds);
    ax = 0x0a13;
    push(ax);
    push(cs);
    sub_3479(); // 02f1:0569
    sp += 0x000a;
    push(0x8000);
    push(0x0720);
    push(memoryAGet16(ds, 0x59ea));
    push(memoryAGet16(ds, 0x59e8));
    push(cs);
    sub_3530(); // 02f1:0620
    sp += 0x0008;
    push(0xfa00);
    push(memoryAGet16(ds, 0x59ea));
    push(memoryAGet16(ds, 0x59e8));
    push(ds);
    ax = 0x0a1e;
    push(ax);
    push(cs);
    sub_3479(); // 02f1:0569
    sp += 0x000a;
    push(0x4000);
    push(0x3e80);
    push(memoryAGet16(ds, 0x59ea));
    push(memoryAGet16(ds, 0x59e8));
    push(cs);
    sub_3530(); // 02f1:0620
    sp += 0x0008;
    push(ds);
    ax = 0x0970;
    push(ax);
    push(cs);
    sub_34b4(); // 02f1:05a4
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x0a07;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(memoryAGet16(ds, 0x5aec));
    push(memoryAGet16(ds, 0x5aea));
    push(ds);
    ax = 0x0a07;
    push(ax);
    push(cs);
    sub_3479(); // 02f1:0569
    sp += 0x000a;
    push(ds);
    ax = 0x0a28;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x5af2, dx);
    memoryASet16(ds, 0x5af0, ax);
    push(ds);
    ax = 0x0a28;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(memoryAGet16(ds, 0x5af2));
    push(memoryAGet16(ds, 0x5af0));
    push(ds);
    ax = 0x0a28;
    push(ax);
    push(cs);
    sub_358f(); // 02f1:067f
    sp += 0x000a;
    push(ds);
    ax = 0x0a35;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0xa17e, dx);
    memoryASet16(ds, 0xa17c, ax);
    push(ds);
    ax = 0x0a35;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(memoryAGet16(ds, 0xa17e));
    push(memoryAGet16(ds, 0xa17c));
    push(ds);
    ax = 0x0a35;
    push(ax);
    push(cs);
    sub_358f(); // 02f1:067f
    sp += 0x000a;
    push(ds);
    ax = 0x0a42;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0xa2cc, dx);
    memoryASet16(ds, 0xa2ca, ax);
    push(ds);
    ax = 0x0a42;
    push(ax);
    push(cs);
    sub_2f10(); // 02f1:0000
    cx = pop();
    cx = pop();
    push(ax);
    push(memoryAGet16(ds, 0xa2cc));
    push(memoryAGet16(ds, 0xa2ca));
    push(ds);
    ax = 0x0a42;
    push(ax);
    push(cs);
    sub_358f(); // 02f1:067f
    sp += 0x000a;
    push(0x0fa0);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x58a2, dx);
    memoryASet16(ds, 0x58a0, ax);
    push(0x0fa0);
    push(dx);
    push(ax);
    push(ds);
    ax = 0x0a4f;
    push(ax);
    push(cs);
    sub_3271(); // 02f1:0361
    sp += 0x000a;
    if (memoryAGet(ds, 0xa5aa) == 0x00)
        goto loc_f89a;
    push(0x1b58);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0xa2d2, dx);
    memoryASet16(ds, 0xa2d0, ax);
    push(ds);
    ax = 0x0a59;
    push(ax);
    push(cs);
    sub_f47e(); // 02f1:c56e
    cx = pop();
    cx = pop();
loc_f89a: // 02f1:c98a
    push(cs);
    cs = 0x1931;
    sub_19310(); // 1931:0000
    assert(cs == 0x02f1);
    memoryASet16(ds, 0xa454, dx);
    memoryASet16(ds, 0xa452, ax);
    push(cs);
    cs = 0x1282;
    sub_12ead(); // 1282:068d
    assert(cs == 0x02f1);
    push(cs);
    cs = 0x1282;
    sub_15bec(); // 1282:33cc
    assert(cs == 0x02f1);
    memoryASet16(ds, 0xa2c6, 0x0000);
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_f8b7() // 02f1:c9a7
{
    CStackGuardFar sg(0, false);
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x02f1);
    cx = pop();
    push(cs);
    cs = 0x1282;
    sub_16cfb(); // 1282:44db
    assert(cs == 0x02f1);
    push(0x0001);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x02f1);
    cx = pop();
    push(cs);
    cs = 0x1282;
    sub_16cfb(); // 1282:44db
    assert(cs == 0x02f1);
    cs = pop();
}
void sub_f8d2() // 02f1:c9c2
{
    CStackGuardFar sg(0, false);
    memoryASet16(ds, 0x59e4, 0x0000);
    memoryASet16(ds, 0x5a8c, 0x0000);
    memoryASet16(ds, 0xa14c, 0x0000);
    memoryASet16(ds, 0xa44a, 0x0000);
    memoryASet16(ds, 0x59e6, 0x0000);
    memoryASet16(ds, 0xa446, 0x0000);
    memoryASet16(ds, 0x035a, 0x0000);
    memoryASet16(ds, 0x0358, 0x0000);
    memoryASet(ds, 0x57dd, 0x00);
    memoryASet(ds, 0x58a4, 0x01);
    memoryASet16(ds, 0x5740, 0x0000);
    cs = pop();
}
void sub_f95e() // 02f1:ca4e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    di = 0;
    if (memoryAGet16(ds, 0x59e4) != di)
        goto loc_f96b;
    goto loc_fadc;
loc_f96b: // 02f1:ca5b
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_f980;
    if (memoryAGet(ds, 0x57dd) == 0x00)
        goto loc_f980;
    memoryASet16(ds, 0x59e4, di);
    goto loc_fadc;
loc_f980: // 02f1:ca70
    si = 0;
    goto loc_fa84;
loc_f985: // 02f1:ca75
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    ax += memoryAGet16(ds, 0x5ae8);
    if (stop(/*condition!*/))
        goto loc_f9bb;
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    ax += memoryAGet16(ds, 0x5ae8);
    ax++;
    ax++;
    if (ax >= memoryAGet16(ds, 0xa468))
        goto loc_f9bb;
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) + ax);
loc_f9bb: // 02f1:caab
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 448);
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + ax);
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    ax += memoryAGet16(ds, 0x58a6);
    if (stop(/*condition!*/))
        goto loc_fa02;
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    ax += memoryAGet16(ds, 0x58a6);
    dx = memoryAGet16(ds, 0xa468);
    dx += 0xffdb;
    if (ax >= dx)
        goto loc_fa02;
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) + ax);
loc_fa02: // 02f1:caf2
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 448);
    ax += memoryAGet16(ds, 0x58a8);
    if (ax <= 0x0002)
        goto loc_fa23;
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 448);
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + ax);
loc_fa23: // 02f1:cb13
    if (memoryAGet16(ds, 0xa466) == 0x0000)
        goto loc_fa83;
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0002);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_fa7e;
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0003);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_fa7e;
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0000);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_fa7e;
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_fa83;
loc_fa7e: // 02f1:cb6e
    di = 0x0001;
    goto loc_fa8d;
loc_fa83: // 02f1:cb73
    si++;
loc_fa84: // 02f1:cb74
    if (si >= memoryAGet16(ds, 0x59e6))
        goto loc_fa8d;
    goto loc_f985;
loc_fa8d: // 02f1:cb7d
    if (!di)
        goto loc_facb;
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) - ax);
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 448);
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - ax);
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 430);
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) - ax);
    bx = memoryAGet16(ds, 0x5a8c);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 448);
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - ax);
    goto loc_fad8;
loc_facb: // 02f1:cbbb
    memoryASet16(ds, 0xa44a, memoryAGet16(ds, 0xa44a) + 1);
    ax = memoryAGet16(ds, 0xa44a);
    if (ax < memoryAGet16(ds, 0xa14c))
        goto loc_fadc;
loc_fad8: // 02f1:cbc8
    push(cs);
    sub_f8d2(); // 02f1:c9c2
loc_fadc: // 02f1:cbcc
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_fadf() // 02f1:cbcf
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x6;
    push(si);
    push(di);
    di = 0;
    si = di;
    memoryASet16(ds, 0x59e0, si);
    if (memoryAGet16(ds, 0x57fa) == si)
        goto loc_faf6;
    goto loc_1083f;
loc_faf6: // 02f1:cbe6
    if (memoryAGet16(ds, 0xa2c4) == si)
        goto loc_faff;
    goto loc_1083f;
loc_faff: // 02f1:cbef
    if (memoryAGet16(ds, 0xa148) == si)
        goto loc_fb08;
    goto loc_1083f;
loc_fb08: // 02f1:cbf8
    if (memoryAGet16(ds, 0xa14a) == si)
        goto loc_fb11;
    goto loc_1083f;
loc_fb11: // 02f1:cc01
    if (memoryAGet16(ds, 0x57b8) == si)
        goto loc_fb1a;
    goto loc_1083f;
loc_fb1a: // 02f1:cc0a
    memoryASet16(ds, 0x0554, memoryAGet16(ds, 0x0554) + 1);
    push(cs);
    sub_f95e(); // 02f1:ca4e
    if (memoryAGet16(ds, 0x59e4) == 0x0000)
        goto loc_fb31;
    memoryASet(ds, 0xa45b, 0x00);
    goto loc_1083f;
loc_fb31: // 02f1:cc21
    if (memoryAGet(ds, 0xa45b) != 0x00)
        goto loc_fb3b;
    goto loc_fc33;
loc_fb3b: // 02f1:cc2b
    if (memoryAGet(ds, 0xa45b) != 0x02)
        goto loc_fb59;
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 4, ax);
    goto loc_fb70;
loc_fb59: // 02f1:cc49
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0x0003;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 4, ax);
loc_fb70: // 02f1:cc60
    ax = memoryAGet16(ss, bp - 4);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x10)
        goto loc_fb85;
    goto loc_fc1c;
loc_fb85: // 02f1:cc75
    ax = memoryAGet16(ss, bp - 4);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    bx += ax;
    if (memoryAGet(es, bx) & 0x80)
        goto loc_fb9a;
    goto loc_fc1c;
loc_fb9a: // 02f1:cc8a
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_fbb3;
    goto loc_fc2e;
loc_fbb3: // 02f1:cca3
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
    si = 0x0001;
    if (memoryAGet(ds, 0xa45b) != 0x02)
        goto loc_fbd8;
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 4, ax);
    goto loc_fbef;
loc_fbd8: // 02f1:ccc8
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0x0003;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 4, ax);
loc_fbef: // 02f1:ccdf
    ax = memoryAGet16(ss, bp - 4);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x10)
        goto loc_fc33;
    ax = memoryAGet16(ss, bp - 4);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    bx += ax;
    if (memoryAGet(es, bx) & 0x80)
        goto loc_fc33;
    memoryASet(ds, 0xa45b, 0x00);
    si = 0;
    goto loc_fc33;
loc_fc1c: // 02f1:cd0c
    ax = memoryAGet16(ss, bp - 4);
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    if (memoryAGet(es, bx) & 0x80)
        goto loc_fc33;
loc_fc2e: // 02f1:cd1e
    memoryASet(ds, 0xa45b, 0x00);
loc_fc33: // 02f1:cd23
    if (memoryAGet(ds, 0xa45b) == 0x00)
        goto loc_fc3d;
    goto loc_fddc;
loc_fc3d: // 02f1:cd2d
    if (memoryAGet(ds, 0xa485) != 0x00)
        goto loc_fc4a;
    memoryASet16(ds, 0x0556, 0x0000);
loc_fc4a: // 02f1:cd3a
    if (memoryAGet(ds, 0xa485) == 0x00)
        goto loc_fc5e;
    if (memoryAGet16(ds, 0x0556) != 0x0000)
        goto loc_fc5e;
    memoryASet16(ds, 0x0556, 0x0002);
loc_fc5e: // 02f1:cd4e
    if (memoryAGet16(ds, 0x0556) != 0x0000)
        goto loc_fc68;
    goto loc_fdd7;
loc_fc68: // 02f1:cd58
    if (memoryAGet16(ds, 0x0556) != 0x0001)
        goto loc_fc72;
    goto loc_fdd7;
loc_fc72: // 02f1:cd62
    memoryASet16(ds, 0x0556, memoryAGet16(ds, 0x0556) - 1);
    if (memoryAGet16(ds, 0x0556) == 0x0001)
        goto loc_fc80;
    goto loc_fddc;
loc_fc80: // 02f1:cd70
    if (memoryAGet16(ds, 0x01a6) == 0x0000)
        goto loc_fc8a;
    goto loc_fd3b;
loc_fc8a: // 02f1:cd7a
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    ax &= 0x0004;
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0xfffe;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    ax &= 0x0004;
    memoryASet16(ss, bp - 4, ax);
    if (memoryAGet16(ds, 0x589e) != 0x0000)
        goto loc_fcf4;
    if (memoryAGet16(ds, 0x57ec) != 0x0000)
        goto loc_fcf4;
    memoryASet16(ds, 0x57ec, 0x0001);
    push(cs);
    cs = 0x1282;
    sub_16e3d(); // 1282:461d
    assert(cs == 0x02f1);
    goto loc_fddc;
loc_fcf4: // 02f1:cde4
    if (memoryAGet16(ss, bp - 6) != 0x0000)
        goto loc_fd31;
    if (memoryAGet16(ss, bp - 4) != 0x0000)
        goto loc_fd31;
    if (memoryAGet16(ds, 0x589e) <= 0x0000)
        goto loc_fd31;
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0xfffe;
    push(ax);
    push(0x0018);
    push(cs);
    sub_ced3(); // 02f1:9fc3
    sp += 0x0006;
loc_fd1e: // 02f1:ce0e
    memoryASet16(ds, 0x589e, memoryAGet16(ds, 0x589e) - 1);
    push(cs);
    cs = 0x1282;
    sub_138e4(); // 1282:10c4
    assert(cs == 0x02f1);
    push(0x001d);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    goto loc_fddc;
loc_fd31: // 02f1:ce21
    push(0x001c);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    goto loc_fddc;
loc_fd3b: // 02f1:ce2b
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0x0003;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    ax &= 0x0008;
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0x0004;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    ax &= 0x0008;
    memoryASet16(ss, bp - 4, ax);
    if (memoryAGet16(ds, 0x589e) != 0x0000)
        goto loc_fda4;
    if (memoryAGet16(ds, 0x57ec) != 0x0000)
        goto loc_fda4;
    memoryASet16(ds, 0x57ec, 0x0001);
    push(cs);
    cs = 0x1282;
    sub_16e3d(); // 1282:461d
    assert(cs == 0x02f1);
loc_fda4: // 02f1:ce94
    if (memoryAGet16(ss, bp - 6) != 0x0000)
        goto loc_fd31;
    if (memoryAGet16(ss, bp - 4) == 0x0000)
        goto loc_fdb3;
    goto loc_fd31;
loc_fdb3: // 02f1:cea3
    if (memoryAGet16(ds, 0x589e) > 0x0000)
        goto loc_fdbd;
    goto loc_fd31;
loc_fdbd: // 02f1:cead
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0x0003;
    push(ax);
    push(0x0018);
    push(cs);
    sub_ced3(); // 02f1:9fc3
    sp += 0x0006;
    goto loc_fd1e;
loc_fdd7: // 02f1:cec7
    memoryASet(ds, 0xa485, 0x00);
loc_fddc: // 02f1:cecc
    if (memoryAGet(ds, 0x5742) == 0x00)
        goto loc_fde6;
    goto loc_fe6a;
loc_fde6: // 02f1:ced6
    if (memoryAGet(ds, 0xa485) != 0x00)
        goto loc_fdf0;
    goto loc_fe6a;
loc_fdf0: // 02f1:cee0
    if (memoryAGet(ds, 0x58a4) == 0x00)
        goto loc_fdfa;
    goto loc_fe6a;
loc_fdfa: // 02f1:ceea
    if (memoryAGet(ds, 0xa45b) != 0x00)
        goto loc_fe6a;
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_fe0f;
    if (memoryAGet(ds, 0xa46a) == 0x00)
        goto loc_fe6a;
loc_fe0f: // 02f1:ceff
    if (memoryAGet(ds, 0xa448) == 0x00)
        goto loc_fe2b;
    memoryASet16(ds, 0xa458, 0x0002);
    memoryASet16(ds, 0x57d4, 0x0002);
    memoryASet16(ds, 0x01a6, 0x0000);
    goto loc_10496;
loc_fe2b: // 02f1:cf1b
    if (memoryAGet(ds, 0xa462) == 0x00)
        goto loc_fe47;
    memoryASet16(ds, 0xa458, 0x0003);
    memoryASet16(ds, 0x57d4, 0x0003);
    memoryASet16(ds, 0x01a6, 0x0017);
    goto loc_10496;
loc_fe47: // 02f1:cf37
    if (memoryAGet16(ds, 0xa458) != 0x0002)
        goto loc_fe57;
    memoryASet16(ds, 0x57d4, 0x0002);
    goto loc_10496;
loc_fe57: // 02f1:cf47
    if (memoryAGet16(ds, 0xa458) == 0x0003)
        goto loc_fe61;
    goto loc_10496;
loc_fe61: // 02f1:cf51
    memoryASet16(ds, 0x57d4, 0x0003);
    goto loc_10496;
loc_fe6a: // 02f1:cf5a
    memoryASet16(ds, 0x57d4, 0x0000);
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (memoryAGet16(ds, 0x57d2) == 0x0000)
        goto loc_fe93;
    if (memoryAGet16(ds, 0x57da) == 0x0000)
        goto loc_fe93;
    goto loc_ff56;
loc_fe93: // 02f1:cf83
    if (memoryAGet16(ds, 0x57da) == 0x0000)
        goto loc_fef2;
    if (memoryAGet(ds, 0xa45b) != 0x00)
        goto loc_fea5;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) - 1);
loc_fea5: // 02f1:cf95
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_fec6;
    if (memoryAGet(ds, 0xa45b) != 0x00)
        goto loc_fec6;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
loc_fec6: // 02f1:cfb6
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax <= 0x000e)
        goto loc_fed6;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
loc_fed6: // 02f1:cfc6
    ax = memoryAGet16(ds, 0x5ae8);
    ax -= memoryAGet16(ds, 0x58a6);
    if (ax >= 0x000c)
        goto loc_feed;
    if (memoryAGet16(ds, 0x58a6) <= 0x0000)
        goto loc_feed;
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) - 1);
loc_feed: // 02f1:cfdd
    memoryASet(ds, 0xa45b, 0x00);
loc_fef2: // 02f1:cfe2
    if (memoryAGet16(ds, 0x57d2) == 0x0000)
        goto loc_ff56;
    if (memoryAGet(ds, 0xa45b) != 0x00)
        goto loc_ff04;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) + 1);
loc_ff04: // 02f1:cff4
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_ff25;
    if (memoryAGet(ds, 0xa45b) != 0x00)
        goto loc_ff25;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
loc_ff25: // 02f1:d015
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax <= 0x000e)
        goto loc_ff35;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
loc_ff35: // 02f1:d025
    ax = memoryAGet16(ds, 0x5ae8);
    ax -= memoryAGet16(ds, 0x58a6);
    if (ax <= 0x0017)
        goto loc_ff51;
    ax = memoryAGet16(ds, 0xa468);
    ax += 0xffda;
    if (ax <= memoryAGet16(ds, 0x58a6))
        goto loc_ff51;
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) + 1);
loc_ff51: // 02f1:d041
    memoryASet(ds, 0xa45b, 0x00);
loc_ff56: // 02f1:d046
    if (memoryAGet(ds, 0xa448) != 0x00)
        goto loc_ff60;
    goto loc_10059;
loc_ff60: // 02f1:d050
    if (memoryAGet(ds, 0xa45b) == 0x00)
        goto loc_ff6a;
    goto loc_10059;
loc_ff6a: // 02f1:d05a
    if (memoryAGet(ds, 0xa462) == 0x00)
        goto loc_ff74;
    goto loc_10059;
loc_ff74: // 02f1:d064
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    di = ax;
    if (memoryAGet16(ds, 0xa458) != 0x0002)
        goto loc_ff95;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) - 1);
    goto loc_ff9b;
loc_ff95: // 02f1:d085
    memoryASet16(ds, 0xa458, 0x0002);
loc_ff9b: // 02f1:d08b
    memoryASet16(ds, 0x01a6, 0x0000);
    if (memoryAGet16(ds, 0x5ae8) >= 0x0001)
        goto loc_ffaf;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) + 1);
    goto loc_10024;
loc_ffaf: // 02f1:d09f
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0002);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    memoryASet16(ss, bp - 2, ax);
    if (ax != 0x0001)
        goto loc_10024;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) + 1);
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_10024;
    if (memoryAGet16(ds, 0x59e0) == 0x0000)
        goto loc_10024;
    memoryASet(ds, 0xa45b, 0x02);
    memoryASet16(ds, 0x035a, 0x0000);
    memoryASet16(ds, 0x0358, 0x0000);
    push(0x0004);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    memoryASet(ds, 0x58a4, 0x00);
    memoryASet(ds, 0x5742, 0x00);
    memoryASet16(ds, 0x5740, 0x0000);
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_1001f;
    memoryASet(ds, 0xa46a, 0x01);
    goto loc_10024;
loc_1001f: // 02f1:d10f
    memoryASet(ds, 0xa46a, 0x00);
loc_10024: // 02f1:d114
    if (memoryAGet16(ss, bp - 2) != 0x0002)
        goto loc_10030;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
    goto loc_10059;
loc_10030: // 02f1:d120
    if (di != 0x0002)
        goto loc_10059;
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_10059;
    memoryASet(ds, 0x58a4, 0x00);
    memoryASet(ds, 0x5742, 0x00);
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
loc_10059: // 02f1:d149
    if (memoryAGet(ds, 0xa462) != 0x00)
        goto loc_10063;
    goto loc_10162;
loc_10063: // 02f1:d153
    if (memoryAGet(ds, 0xa45b) == 0x00)
        goto loc_1006d;
    goto loc_10162;
loc_1006d: // 02f1:d15d
    if (memoryAGet(ds, 0xa448) == 0x00)
        goto loc_10077;
    goto loc_10162;
loc_10077: // 02f1:d167
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    di = ax;
    if (memoryAGet16(ds, 0xa458) != 0x0003)
        goto loc_10098;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) + 1);
    goto loc_1009e;
loc_10098: // 02f1:d188
    memoryASet16(ds, 0xa458, 0x0003);
loc_1009e: // 02f1:d18e
    memoryASet16(ds, 0x01a6, 0x0017);
    ax = memoryAGet16(ds, 0xa468);
    ax += 0xfffc;
    if (ax >= memoryAGet16(ds, 0x5ae8))
        goto loc_100b7;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) - 1);
    goto loc_1012c;
loc_100b7: // 02f1:d1a7
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0003);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    memoryASet16(ss, bp - 2, ax);
    if (ax != 0x0001)
        goto loc_1012c;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) - 1);
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_1012c;
    if (memoryAGet16(ds, 0x59e0) == 0x0000)
        goto loc_1012c;
    memoryASet(ds, 0xa45b, 0x03);
    memoryASet16(ds, 0x035a, 0x0000);
    memoryASet16(ds, 0x0358, 0x0000);
    push(0x0004);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    memoryASet(ds, 0x5742, 0x00);
    memoryASet(ds, 0x58a4, 0x00);
    memoryASet16(ds, 0x5740, 0x0000);
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_10127;
    memoryASet(ds, 0xa46a, 0x01);
    goto loc_1012c;
loc_10127: // 02f1:d217
    memoryASet(ds, 0xa46a, 0x00);
loc_1012c: // 02f1:d21c
    if (memoryAGet16(ss, bp - 2) != 0x0002)
        goto loc_10138;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
    goto loc_10162;
loc_10138: // 02f1:d228
    if (di != 0x0002)
        goto loc_10162;
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_10162;
    memoryASet(ds, 0x58a4, 0x00);
    memoryASet16(ds, 0x5740, 0x0000);
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
loc_10162: // 02f1:d252
    if (memoryAGet(ds, 0xa45b) == 0x00)
        goto loc_1017c;
    if (memoryAGet(ds, 0xa46a) == 0x00)
        goto loc_1017c;
    if (memoryAGet(ds, 0xa484) != 0x00)
        goto loc_1017c;
    memoryASet(ds, 0xa46a, 0x00);
loc_1017c: // 02f1:d26c
    if (memoryAGet16(ds, 0x0358) != 0x0000)
        goto loc_101b6;
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_10198;
    if (memoryAGet(ds, 0x58a4) != 0x00)
        goto loc_10198;
    if (memoryAGet(ds, 0xa46a) == 0x00)
        goto loc_101b6;
loc_10198: // 02f1:d288
    if (memoryAGet(ds, 0xa45b) != 0x00)
        goto loc_101a2;
    goto loc_1037d;
loc_101a2: // 02f1:d292
    if (memoryAGet(ds, 0xa484) != 0x00)
        goto loc_101ac;
    goto loc_1037d;
loc_101ac: // 02f1:d29c
    if (memoryAGet(ds, 0xa46a) == 0x00)
        goto loc_101b6;
    goto loc_1037d;
loc_101b6: // 02f1:d2a6
    if (memoryAGet16(ds, 0x035a) != 0x0000)
        goto loc_101c0;
    goto loc_10240;
loc_101c0: // 02f1:d2b0
    if (memoryAGet16(ds, 0x0358) > 0x0000)
        goto loc_101ca;
    goto loc_10240;
loc_101ca: // 02f1:d2ba
    memoryASet16(ds, 0x0358, memoryAGet16(ds, 0x0358) - 1);
    if (memoryAGet16(ds, 0x0358) >= 0x000a)
        goto loc_101db;
    memoryASet16(ds, 0x579e, 0x0000);
loc_101db: // 02f1:d2cb
    if (memoryAGet16(ds, 0x0358) <= 0x0001)
        goto loc_101e6;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
loc_101e6: // 02f1:d2d6
    if (memoryAGet16(ds, 0x0358) <= 0x000d)
        goto loc_10212;
    memoryASet16(ds, 0x0358, memoryAGet16(ds, 0x0358) - 1);
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0000);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_1020c;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
    goto loc_10212;
loc_1020c: // 02f1:d2fc
    memoryASet16(ds, 0x579e, 0x0000);
loc_10212: // 02f1:d302
    memoryASet16(ss, bp - 4, 0x0000);
    if (memoryAGet16(ds, 0x0358) == 0x0000)
        goto loc_10221;
    goto loc_102c8;
loc_10221: // 02f1:d311
    memoryASet(ds, 0x5742, 0x00);
    memoryASet16(ds, 0x035a, 0x0000);
    memoryASet16(ds, 0x5740, 0x0000);
    memoryASet16(ds, 0x579e, 0x0000);
    memoryASet(ds, 0xa46a, 0x01);
    goto loc_102c8;
loc_10240: // 02f1:d330
    if (memoryAGet(ds, 0xa45b) != 0x02)
        goto loc_10262;
    if (memoryAGet(ds, 0xa448) == 0x00)
        goto loc_10255;
    memoryASet(ds, 0xa45b, 0x00);
    goto loc_10262;
loc_10255: // 02f1:d345
    if (memoryAGet(ds, 0xa462) == 0x00)
        goto loc_10262;
    memoryASet16(ds, 0x01a6, 0x0017);
loc_10262: // 02f1:d352
    if (memoryAGet(ds, 0xa45b) != 0x03)
        goto loc_10284;
    if (memoryAGet(ds, 0xa462) == 0x00)
        goto loc_10277;
    memoryASet(ds, 0xa45b, 0x00);
    goto loc_10284;
loc_10277: // 02f1:d367
    if (memoryAGet(ds, 0xa448) == 0x00)
        goto loc_10284;
    memoryASet16(ds, 0x01a6, 0x0000);
loc_10284: // 02f1:d374
    if (memoryAGet(ds, 0xa45b) != 0x00)
        goto loc_1029c;
    al = memoryAGet(ds, 0x5742);
    ah = 0x00;
    bx = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 1344);
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + ax);
loc_1029c: // 02f1:d38c
    if (memoryAGet(ds, 0x5742) != 0x00)
        goto loc_102bd;
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0000);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_102bd;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
loc_102bd: // 02f1:d3ad
    memoryASet16(ds, 0x035a, 0x0000);
    memoryASet16(ss, bp - 4, 0x0001);
loc_102c8: // 02f1:d3b8
    memoryASet(ds, 0xa45b, 0x00);
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0000);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_10340;
    if (memoryAGet(ds, 0x5742) > 0x00)
        goto loc_102f0;
    if (memoryAGet16(ds, 0x035a) == 0x0000)
        goto loc_102f7;
loc_102f0: // 02f1:d3e0
    push(0x0005);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_102f7: // 02f1:d3e7
    memoryASet16(ds, 0x0358, 0x0000);
    memoryASet16(ds, 0x035a, 0x0000);
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0000);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_1031d;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
loc_1031d: // 02f1:d40d
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
    memoryASet(ds, 0x58a4, 0x01);
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_10332;
    memoryASet(ds, 0xa46a, 0x01);
loc_10332: // 02f1:d422
    memoryASet16(ds, 0x5740, 0x0000);
    memoryASet16(ds, 0x579e, 0x0000);
    goto loc_10354;
loc_10340: // 02f1:d430
    if (memoryAGet16(ss, bp - 4) == 0x0000)
        goto loc_10354;
    if (memoryAGet(ds, 0x5742) != 0x00)
        goto loc_10354;
    push(0x0002);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_10354: // 02f1:d444
    if (memoryAGet16(ds, 0x035a) != 0x0000)
        goto loc_1037d;
    al = memoryAGet(ds, 0x5742);
    memoryASet(ds, 0x5742, memoryAGet(ds, 0x5742) + 1);
    if (al <= 0x06)
        goto loc_1037d;
    memoryASet(ds, 0x58a4, 0x01);
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_10377;
    memoryASet(ds, 0xa46a, 0x01);
loc_10377: // 02f1:d467
    memoryASet16(ds, 0x5740, 0x0000);
loc_1037d: // 02f1:d46d
    if (memoryAGet(ds, 0xa45b) == 0x00)
        goto loc_10387;
    goto loc_10496;
loc_10387: // 02f1:d477
    if (memoryAGet(ds, 0x58a4) == 0x00)
        goto loc_1039a;
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_1039a;
    memoryASet(ds, 0xa46a, 0x01);
loc_1039a: // 02f1:d48a
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_103a8;
    if (memoryAGet(ds, 0xa46a) == 0x00)
        goto loc_103ba;
loc_103a8: // 02f1:d498
    if (memoryAGet(ds, 0x58a4) != 0x00)
        goto loc_103ba;
    memoryASet(ds, 0x58a4, 0x01);
    memoryASet16(ds, 0x5740, 0x0000);
loc_103ba: // 02f1:d4aa
    if (memoryAGet(ds, 0x58a4) != 0x00)
        goto loc_103c4;
    goto loc_1047d;
loc_103c4: // 02f1:d4b4
    if (memoryAGet16(ds, 0x035a) == 0x0000)
        goto loc_103ce;
    goto loc_1047d;
loc_103ce: // 02f1:d4be
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_1041c;
    if (memoryAGet16(ds, 0x5740) == 0x0000)
        goto loc_103f5;
    push(0x0003);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_103f5: // 02f1:d4e5
    memoryASet(ds, 0x58a4, 0x00);
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
    memoryASet(ds, 0x5742, 0x00);
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_10411;
    memoryASet(ds, 0xa46a, 0x01);
    goto loc_10416;
loc_10411: // 02f1:d501
    memoryASet(ds, 0xa46a, 0x00);
loc_10416: // 02f1:d506
    memoryASet16(ds, 0x5740, 0x0000);
loc_1041c: // 02f1:d50c
    if ((short)memoryAGet16(ds, 0x5740) <= (short)0x0003)
        goto loc_10472;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_10472;
    push(0x0003);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    memoryASet(ds, 0x58a4, 0x00);
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
    memoryASet(ds, 0x5742, 0x00);
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_10467;
    memoryASet(ds, 0xa46a, 0x01);
    goto loc_1046c;
loc_10467: // 02f1:d557
    memoryASet(ds, 0xa46a, 0x00);
loc_1046c: // 02f1:d55c
    memoryASet16(ds, 0x5740, 0x0000);
loc_10472: // 02f1:d562
    if ((short)memoryAGet16(ds, 0x5740) >= (short)0x0019)
        goto loc_1047d;
    memoryASet16(ds, 0x5740, memoryAGet16(ds, 0x5740) + 1);
loc_1047d: // 02f1:d56d
    if (memoryAGet(ds, 0x58a4) == 0x00)
        goto loc_10496;
    if (memoryAGet16(ds, 0x5740) != 0x0001)
        goto loc_10496;
    if (memoryAGet16(ds, 0x035a) != 0x0000)
        goto loc_10496;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
loc_10496: // 02f1:d586
    if (memoryAGet16(ds, 0x57d4) == 0x0000)
        goto loc_104ac;
    memoryASet16(ds, 0x053e, 0x0000);
    memoryASet16(ds, 0x01a8, 0x000e);
    goto loc_107a8;
loc_104ac: // 02f1:d59c
    if (memoryAGet(ds, 0xa146) != 0x00)
        goto loc_104bd;
    if (memoryAGet(ds, 0xa2cf) != 0x00)
        goto loc_104bd;
    goto loc_1058d;
loc_104bd: // 02f1:d5ad
    if (memoryAGet(ds, 0xa448) == 0x00)
        goto loc_104c7;
    goto loc_1058d;
loc_104c7: // 02f1:d5b7
    if (memoryAGet(ds, 0xa462) == 0x00)
        goto loc_104d1;
    goto loc_1058d;
loc_104d1: // 02f1:d5c1
    if (memoryAGet(ds, 0x58a4) == 0x00)
        goto loc_104db;
    goto loc_1058d;
loc_104db: // 02f1:d5cb
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_104e5;
    goto loc_1058d;
loc_104e5: // 02f1:d5d5
    memoryASet16(ds, 0x053e, 0x0000);
    if (memoryAGet(ds, 0xa146) == 0x00)
        goto loc_10538;
    if (memoryAGet16(ds, 0xa480) != 0x0000)
        goto loc_10538;
    if (memoryAGet16(ds, 0xa46c) != 0x0000)
        goto loc_10538;
    if (memoryAGet16(ds, 0x58a8) <= 0x0000)
        goto loc_10517;
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax >= 0x0011)
        goto loc_10517;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
loc_10517: // 02f1:d607
    if (!si)
        goto loc_1051f;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
loc_1051f: // 02f1:d60f
    if (memoryAGet(ds, 0xa45b) == 0x00)
        goto loc_1052f;
    memoryASet16(ds, 0x01a8, 0x000b);
    goto loc_1083f;
loc_1052f: // 02f1:d61f
    memoryASet16(ds, 0x01a8, 0x0005);
    goto loc_1083f;
loc_10538: // 02f1:d628
    if (memoryAGet(ds, 0xa2cf) != 0x00)
        goto loc_10542;
    goto loc_1083f;
loc_10542: // 02f1:d632
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0003;
    if (ax >= memoryAGet16(ds, 0x5aee))
        goto loc_10574;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
    if (si)
        goto loc_10564;
    if (memoryAGet16(ds, 0x57d2) != 0x0000)
        goto loc_10564;
    if (memoryAGet16(ds, 0x57da) == 0x0000)
        goto loc_10574;
loc_10564: // 02f1:d654
    ax = memoryAGet16(ds, 0x58a8);
    ax += 0x0003;
    if (ax >= memoryAGet16(ds, 0x5aee))
        goto loc_10574;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
loc_10574: // 02f1:d664
    if (memoryAGet(ds, 0xa45b) == 0x00)
        goto loc_10584;
    memoryASet16(ds, 0x01a8, 0x000c);
    goto loc_1083f;
loc_10584: // 02f1:d674
    memoryASet16(ds, 0x01a8, 0x0006);
    goto loc_1083f;
loc_1058d: // 02f1:d67d
    if (memoryAGet(ds, 0xa45b) != 0x02)
        goto loc_105a3;
    memoryASet16(ds, 0x053e, 0x0000);
    if (memoryAGet(ds, 0xa462) != 0x00)
        goto loc_105b7;
    goto loc_105c0;
loc_105a3: // 02f1:d693
    if (memoryAGet(ds, 0xa45b) != 0x03)
        goto loc_105c9;
    memoryASet16(ds, 0x053e, 0x0000);
    if (memoryAGet(ds, 0xa448) == 0x00)
        goto loc_105c0;
loc_105b7: // 02f1:d6a7
    memoryASet16(ds, 0x01a8, 0x000a);
    goto loc_107a8;
loc_105c0: // 02f1:d6b0
    memoryASet16(ds, 0x01a8, 0x0009);
    goto loc_107a8;
loc_105c9: // 02f1:d6b9
    if (memoryAGet(ds, 0x58a4) == 0x00)
        goto loc_105d7;
    if (memoryAGet16(ds, 0x035a) == 0x0000)
        goto loc_105e5;
loc_105d7: // 02f1:d6c7
    if (memoryAGet(ds, 0x5742) <= 0x06)
        goto loc_10640;
    if (memoryAGet(ds, 0x58a4) != 0x00)
        goto loc_10640;
loc_105e5: // 02f1:d6d5
    memoryASet16(ds, 0x053e, 0x0000);
    if (memoryAGet16(ds, 0x035a) != 0x0000)
        goto loc_10603;
    if (memoryAGet(ds, 0x58a4) != 0x00)
        goto loc_10603;
    if (memoryAGet(ds, 0x5742) <= 0x06)
        goto loc_10603;
    goto loc_10689;
loc_10603: // 02f1:d6f3
    if ((short)memoryAGet16(ds, 0x5740) < (short)0x000a)
        goto loc_1061a;
    if ((short)memoryAGet16(ds, 0x5740) >= (short)0x0019)
        goto loc_1061a;
    memoryASet16(ds, 0x01a8, 0x000d);
    goto loc_107a8;
loc_1061a: // 02f1:d70a
    if (memoryAGet16(ds, 0x5740) != 0x0019)
        goto loc_10630;
    memoryASet16(ds, 0x01a8, 0x0010);
    memoryASet16(ds, 0xa472, 0x0001);
    goto loc_107a8;
loc_10630: // 02f1:d720
    if (memoryAGet(ds, 0x58a4) != 0x00)
        goto loc_10689;
    memoryASet16(ds, 0x01a8, 0x0007);
    goto loc_107a8;
loc_10640: // 02f1:d730
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_1064e;
    if (memoryAGet(ds, 0xa46a) == 0x00)
        goto loc_10655;
loc_1064e: // 02f1:d73e
    if (memoryAGet16(ds, 0x035a) == 0x0000)
        goto loc_10692;
loc_10655: // 02f1:d745
    memoryASet16(ds, 0x053e, 0x0000);
    memoryASet16(ds, 0x01a8, 0x0007);
    if (memoryAGet16(ds, 0x035a) == 0x0000)
        goto loc_10675;
    if (memoryAGet16(ds, 0x579e) == 0x0000)
        goto loc_10675;
    memoryASet16(ds, 0x01a8, 0x0016);
loc_10675: // 02f1:d765
    if (memoryAGet16(ds, 0x0358) < 0x0003)
        goto loc_1067f;
    goto loc_107a8;
loc_1067f: // 02f1:d76f
    if (memoryAGet16(ds, 0x035a) != 0x0000)
        goto loc_10689;
    goto loc_107a8;
loc_10689: // 02f1:d779
    memoryASet16(ds, 0x01a8, 0x0008);
    goto loc_107a8;
loc_10692: // 02f1:d782
    al = memoryAGet(ds, 0xa448);
    if (al == memoryAGet(ds, 0xa462))
        goto loc_1069e;
    goto loc_10773;
loc_1069e: // 02f1:d78e
    push(cs);
    cs = 0x1a37;
    sub_1a383(); // 1a37:0013
    assert(cs == 0x02f1);
    bx = 0x0032;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    memoryASet(ss, bp - 3, dl);
    memoryASet16(ds, 0x01a8, 0x0004);
    if (memoryAGet(ds, 0xa448) == 0x00)
        goto loc_106bc;
    goto loc_10751;
loc_106bc: // 02f1:d7ac
    if (memoryAGet(ds, 0xa462) == 0x00)
        goto loc_106c6;
    goto loc_10751;
loc_106c6: // 02f1:d7b6
    if (memoryAGet(ds, 0x58a4) == 0x00)
        goto loc_106d0;
    goto loc_10751;
loc_106d0: // 02f1:d7c0
    memoryASet16(ds, 0x053e, memoryAGet16(ds, 0x053e) + 1);
    if (memoryAGet16(ds, 0x053e) <= 0x0064)
        goto loc_106eb;
    if (memoryAGet16(ds, 0x053e) >= 0x006e)
        goto loc_106eb;
    memoryASet16(ds, 0x01a8, 0x0005);
    goto loc_10751;
loc_106eb: // 02f1:d7db
    if (memoryAGet16(ds, 0x053e) <= 0x008b)
        goto loc_10703;
    if (memoryAGet16(ds, 0x053e) >= 0x0096)
        goto loc_10703;
    memoryASet16(ds, 0x01a8, 0x0006);
    goto loc_10751;
loc_10703: // 02f1:d7f3
    if (memoryAGet16(ds, 0x053e) == 0x00b4)
        goto loc_1073b;
    if (memoryAGet16(ds, 0x053e) == 0x00b5)
        goto loc_1072b;
    if (memoryAGet16(ds, 0x053e) != 0x00b6)
        goto loc_10723;
    memoryASet16(ds, 0x01a8, 0x0015);
    goto loc_10751;
loc_10723: // 02f1:d813
    if (memoryAGet16(ds, 0x053e) != 0x00b7)
        goto loc_10733;
loc_1072b: // 02f1:d81b
    memoryASet16(ds, 0x01a8, 0x0014);
    goto loc_10751;
loc_10733: // 02f1:d823
    if (memoryAGet16(ds, 0x053e) != 0x00b8)
        goto loc_10743;
loc_1073b: // 02f1:d82b
    memoryASet16(ds, 0x01a8, 0x0013);
    goto loc_10751;
loc_10743: // 02f1:d833
    if (memoryAGet16(ds, 0x053e) != 0x00b9)
        goto loc_10751;
    memoryASet16(ds, 0x053e, 0x0000);
loc_10751: // 02f1:d841
    if (memoryAGet16(ds, 0x01a8) == 0x0005)
        goto loc_107a8;
    if (memoryAGet16(ds, 0x01a8) == 0x0006)
        goto loc_107a8;
    if (memoryAGet(ss, bp - 3) == 0x00)
        goto loc_1076b;
    if (memoryAGet(ss, bp - 3) != 0x1f)
        goto loc_107a8;
loc_1076b: // 02f1:d85b
    memoryASet16(ds, 0x01a8, 0x0012);
    goto loc_107a8;
loc_10773: // 02f1:d863
    if (memoryAGet(ds, 0x58a4) != 0x00)
        goto loc_107a8;
    memoryASet16(ds, 0x053e, 0x0000);
    if (!(memoryAGet16(ds, 0x0554) & 0x0001))
        goto loc_1079b;
    if (!(memoryAGet16(ds, 0x01a8) & 0x0001))
        goto loc_10797;
    push(0x0013);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_10797: // 02f1:d887
    memoryASet16(ds, 0x01a8, memoryAGet16(ds, 0x01a8) + 1);
loc_1079b: // 02f1:d88b
    if (memoryAGet16(ds, 0x01a8) <= 0x0003)
        goto loc_107a8;
    memoryASet16(ds, 0x01a8, 0x0000);
loc_107a8: // 02f1:d898
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax <= 0x000e)
        goto loc_107b8;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
loc_107b8: // 02f1:d8a8
    if (!si)
        goto loc_107ce;
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax <= 0x000e)
        goto loc_107ce;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
    goto loc_10803;
loc_107ce: // 02f1:d8be
    if (memoryAGet16(ds, 0x0358) <= 0x000a)
        goto loc_107ec;
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax >= 0x0007)
        goto loc_107ec;
    if (memoryAGet16(ds, 0x58a8) <= 0x0000)
        goto loc_107ec;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
loc_107ec: // 02f1:d8dc
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax >= 0x0007)
        goto loc_10803;
    if (memoryAGet16(ds, 0x58a8) <= 0x0000)
        goto loc_10803;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
loc_10803: // 02f1:d8f3
    ax = memoryAGet16(ds, 0x5ae8);
    ax -= memoryAGet16(ds, 0x58a6);
    if (ax <= 0x0017)
        goto loc_10828;
    ax = memoryAGet16(ds, 0xa468);
    ax += 0xffda;
    if (ax <= memoryAGet16(ds, 0x58a6))
        goto loc_10828;
    if (memoryAGet16(ds, 0x59fe) <= 0x0005)
        goto loc_10828;
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) + 1);
    goto loc_1083f;
loc_10828: // 02f1:d918
    ax = memoryAGet16(ds, 0x5ae8);
    ax -= memoryAGet16(ds, 0x58a6);
    if (ax >= 0x000c)
        goto loc_1083f;
    if (memoryAGet16(ds, 0x58a6) <= 0x0000)
        goto loc_1083f;
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) - 1);
loc_1083f: // 02f1:d92f
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_10843() // 02f1:d933
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(cs);
    sub_2f32(); // 02f1:0022
    memoryASet16(ds, 0x57a8, 0x0000);
    memoryASet16(ds, 0x0358, 0x0000);
    memoryASet(ds, 0x58a4, 0x00);
    if (memoryAGet16(ds, 0x57fa) == 0x0000)
        goto loc_10864;
    goto loc_10c63;
loc_10864: // 02f1:d954
    if (memoryAGet16(ds, 0xa148) <= 0x0001)
        goto loc_10876;
    memoryASet(ds, 0xa146, 0x01);
    memoryASet16(ds, 0xa148, memoryAGet16(ds, 0xa148) - 1);
    goto loc_108b5;
loc_10876: // 02f1:d966
    if (memoryAGet(ds, 0xa484) == 0x00)
        goto loc_108b5;
    memoryASet(ds, 0xa46a, 0x01);
    memoryASet16(ds, 0xa148, 0x0000);
    memoryASet(ds, 0x58a4, 0x01);
    memoryASet16(ds, 0x5740, 0x0001);
    memoryASet16(ds, 0x035a, 0x0000);
    memoryASet16(ds, 0x57a8, 0x0001);
    push(0x0009);
    push(cs);
    sub_d74a(); // 02f1:a83a
    cx = pop();
    memoryASet16(ds, 0x0358, memoryAGet16(ds, 0x0358) - 0x0002);
    push(0x0002);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    goto loc_10c63;
loc_108b5: // 02f1:d9a5
    if (memoryAGet(ds, 0xa448) != 0x00)
        goto loc_108bf;
    goto loc_10944;
loc_108bf: // 02f1:d9af
    if (memoryAGet(ds, 0xa462) == 0x00)
        goto loc_108c9;
    goto loc_10944;
loc_108c9: // 02f1:d9b9
    if (memoryAGet16(ds, 0x01a6) != 0x0000)
        goto loc_108d4;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) - 1);
loc_108d4: // 02f1:d9c4
    memoryASet16(ds, 0x01a6, 0x0000);
    memoryASet16(ds, 0x01a8, 0x0004);
    if (memoryAGet16(ds, 0x5ae8) >= 0x0001)
        goto loc_108eb;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) + 1);
loc_108eb: // 02f1:d9db
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0002);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_10916;
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0002);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_1091a;
loc_10916: // 02f1:da06
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) + 1);
loc_1091a: // 02f1:da0a
    if (!(memoryAGet16(ds, 0x5ae8) & 0x0001))
        goto loc_10944;
    push(0x0001);
    push(0x0003);
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0x0003;
    push(ax);
    push(0x0004);
    push(0x0013);
    push(cs);
    sub_d5b5(); // 02f1:a6a5
    sp += 0x000c;
    push(0x0018);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_10944: // 02f1:da34
    if (memoryAGet(ds, 0xa462) != 0x00)
        goto loc_1094e;
    goto loc_109d6;
loc_1094e: // 02f1:da3e
    if (memoryAGet(ds, 0xa448) == 0x00)
        goto loc_10958;
    goto loc_109d6;
loc_10958: // 02f1:da48
    if (memoryAGet16(ds, 0x01a6) == 0x0000)
        goto loc_10963;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) + 1);
loc_10963: // 02f1:da53
    memoryASet16(ds, 0x01a6, 0x0017);
    memoryASet16(ds, 0x01a8, 0x0004);
    ax = memoryAGet16(ds, 0xa468);
    ax += 0xfffc;
    if (ax >= memoryAGet16(ds, 0x5ae8))
        goto loc_1097f;
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) - 1);
loc_1097f: // 02f1:da6f
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0003);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (ax)
        goto loc_109aa;
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0003);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_109ae;
loc_109aa: // 02f1:da9a
    memoryASet16(ds, 0x5ae8, memoryAGet16(ds, 0x5ae8) - 1);
loc_109ae: // 02f1:da9e
    if (!(memoryAGet16(ds, 0x5ae8) & 0x0001))
        goto loc_109d6;
    push(0x0001);
    push(0x0007);
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    push(0x0004);
    push(0x0013);
    push(cs);
    sub_d5b5(); // 02f1:a6a5
    sp += 0x000c;
    push(0x0018);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_109d6: // 02f1:dac6
    if (memoryAGet(ds, 0xa146) == 0x00)
        goto loc_10a38;
    if (memoryAGet(ds, 0xa2cf) != 0x00)
        goto loc_10a38;
    memoryASet16(ds, 0x01a8, 0x0005);
    if (memoryAGet16(ds, 0x5aee) <= 0x0004)
        goto loc_109f5;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
loc_109f5: // 02f1:dae5
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0000);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_10a0e;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
loc_10a0e: // 02f1:dafe
    if (!(memoryAGet16(ds, 0x5aee) & 0x0001))
        goto loc_10a7e;
    push(0x0001);
    push(0x0005);
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax++;
    push(ax);
    push(0x0004);
    push(0x0013);
    push(cs);
    sub_d5b5(); // 02f1:a6a5
    sp += 0x000c;
    push(0x0018);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    goto loc_10a7e;
loc_10a38: // 02f1:db28
    if (memoryAGet(ds, 0xa2cf) == 0x00)
        goto loc_10a78;
    if (memoryAGet(ds, 0xa146) != 0x00)
        goto loc_10a78;
    memoryASet16(ds, 0x01a8, 0x0006);
    ax = memoryAGet16(ds, 0xa456);
    ax += 0x0011;
    if (ax <= memoryAGet16(ds, 0x5aee))
        goto loc_10a5c;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
loc_10a5c: // 02f1:db4c
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_10a7e;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
    goto loc_10a7e;
loc_10a78: // 02f1:db68
    memoryASet16(ds, 0x01a8, 0x0004);
loc_10a7e: // 02f1:db6e
    if (memoryAGet(ds, 0xa485) != 0x00)
        goto loc_10a8b;
    memoryASet16(ds, 0x0558, 0x0000);
loc_10a8b: // 02f1:db7b
    if (memoryAGet(ds, 0xa485) == 0x00)
        goto loc_10aa5;
    if (memoryAGet16(ds, 0x0558) != 0x0000)
        goto loc_10aa5;
    memoryASet16(ds, 0x0558, 0x0001);
    memoryASet16(ds, 0x01a8, 0x000e);
loc_10aa5: // 02f1:db95
    if (memoryAGet16(ds, 0x0558) != 0x0000)
        goto loc_10aaf;
    goto loc_10be2;
loc_10aaf: // 02f1:db9f
    if (memoryAGet16(ds, 0x0558) != 0x0002)
        goto loc_10ab9;
    goto loc_10be2;
loc_10ab9: // 02f1:dba9
    memoryASet16(ds, 0x01a8, 0x000e);
    if (memoryAGet16(ds, 0x0558) != 0x0000)
        goto loc_10ac9;
    goto loc_10be7;
loc_10ac9: // 02f1:dbb9
    memoryASet16(ds, 0x0558, 0x0002);
    if (memoryAGet16(ds, 0x01a6) == 0x0000)
        goto loc_10ad9;
    goto loc_10b69;
loc_10ad9: // 02f1:dbc9
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    si = ax;
    si &= 0x0004;
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0xfffe;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    di = ax;
    di &= 0x0004;
    if (si)
        goto loc_10b60;
    if (di)
        goto loc_10b60;
    if (memoryAGet16(ds, 0x589e) <= 0x0000)
        goto loc_10b60;
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0xfffe;
    push(ax);
    push(0x0018);
    push(cs);
    sub_ced3(); // 02f1:9fc3
    sp += 0x0006;
loc_10b4d: // 02f1:dc3d
    memoryASet16(ds, 0x589e, memoryAGet16(ds, 0x589e) - 1);
    push(cs);
    cs = 0x1282;
    sub_138e4(); // 1282:10c4
    assert(cs == 0x02f1);
    push(0x001d);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    goto loc_10be7;
loc_10b60: // 02f1:dc50
    push(0x001c);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    goto loc_10be7;
loc_10b69: // 02f1:dc59
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0x0003;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    si = ax;
    si &= 0x0008;
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0x0004;
    push(ax);
    push(cs);
    sub_4923(); // 02f1:1a13
    cx = pop();
    cx = pop();
    ax >>= 3;
    bx = memoryAGet16(ds, 0xa2d0);
    es = memoryAGet16(ds, 0xa2d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    di = ax;
    di &= 0x0008;
    if (si)
        goto loc_10b60;
    if (di)
        goto loc_10b60;
    if (memoryAGet16(ds, 0x589e) <= 0x0000)
        goto loc_10b60;
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax += 0x0003;
    push(ax);
    push(0x0018);
    push(cs);
    sub_ced3(); // 02f1:9fc3
    sp += 0x0006;
    goto loc_10b4d;
loc_10be2: // 02f1:dcd2
    memoryASet(ds, 0xa485, 0x00);
loc_10be7: // 02f1:dcd7
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax <= 0x000e)
        goto loc_10bf9;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) + 1);
    goto loc_10c2e;
loc_10bf9: // 02f1:dce9
    if (memoryAGet16(ds, 0x0358) <= 0x000a)
        goto loc_10c17;
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax >= 0x0007)
        goto loc_10c17;
    if (memoryAGet16(ds, 0x58a8) <= 0x0000)
        goto loc_10c17;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
loc_10c17: // 02f1:dd07
    ax = memoryAGet16(ds, 0x5aee);
    ax -= memoryAGet16(ds, 0x58a8);
    if (ax >= 0x0007)
        goto loc_10c2e;
    if (memoryAGet16(ds, 0x58a8) <= 0x0000)
        goto loc_10c2e;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
loc_10c2e: // 02f1:dd1e
    ax = memoryAGet16(ds, 0x5ae8);
    ax -= memoryAGet16(ds, 0x58a6);
    if (ax <= 0x0017)
        goto loc_10c4c;
    ax = memoryAGet16(ds, 0xa468);
    ax += 0xffda;
    if (ax <= memoryAGet16(ds, 0x58a6))
        goto loc_10c4c;
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) + 1);
    goto loc_10c63;
loc_10c4c: // 02f1:dd3c
    ax = memoryAGet16(ds, 0x5ae8);
    ax -= memoryAGet16(ds, 0x58a6);
    if (ax >= 0x000c)
        goto loc_10c63;
    if (memoryAGet16(ds, 0x58a6) <= 0x0000)
        goto loc_10c63;
    memoryASet16(ds, 0x58a6, memoryAGet16(ds, 0x58a6) - 1);
loc_10c63: // 02f1:dd53
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_10c66() // 02f1:dd56
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    if (memoryAGet(ds, 0xa45b) == 0x00)
        goto loc_10c79;
    memoryASet16(ds, 0xa472, 0x0000);
    memoryASet16(ds, 0xa14a, 0x0000);
loc_10c79: // 02f1:dd69
    if (memoryAGet16(ds, 0xa472) == 0x0000)
        goto loc_10ca9;
    ax = memoryAGet16(ds, 0x5aee);
    ax++;
    push(ax);
    push(memoryAGet16(ds, 0x5ae8));
    push(0x0001);
    push(cs);
    sub_3a24(); // 02f1:0b14
    sp += 0x0006;
    if (!ax)
        goto loc_10ca9;
    memoryASet16(ds, 0xa472, 0x0000);
    memoryASet16(ds, 0xa14a, 0x0008);
    push(0x0003);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_10ca9: // 02f1:dd99
    if (memoryAGet16(ds, 0xa14a) == 0x0000)
        goto loc_10cd1;
    bx = memoryAGet16(ds, 0xa14a);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 1370);
    memoryASet16(ds, 0x01a8, ax);
    memoryASet16(ds, 0xa14a, memoryAGet16(ds, 0xa14a) - 1);
    memoryASet(ds, 0x58a4, 0x00);
    if (memoryAGet16(ds, 0xa14a) <= 0x0008)
        goto loc_10cd1;
    push(cs);
    sub_2f32(); // 02f1:0022
loc_10cd1: // 02f1:ddc1
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_10cd2() // 02f1:ddc2
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    ax = memoryAGet16(ds, 0xa456);
    ax += 0x0015;
    if (ax >= memoryAGet16(ds, 0x5aee))
        goto loc_10d10;
    if (memoryAGet16(ds, 0x57fa) != 0x0000)
        goto loc_10d10;
    memoryASet(ds, 0x01d6, 0x01);
    memoryASet16(ds, 0x57fa, 0x0001);
    ax = memoryAGet16(ds, 0xa456);
    ax += 0x0016;
    if (ax != memoryAGet16(ds, 0x5aee))
        goto loc_10d00;
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) + 1);
loc_10d00: // 02f1:ddf0
    memoryASet(ds, 0x056c, memoryAGet(ds, 0x056c) + 1);
    if (memoryAGet(ds, 0x056c) != 0x05)
        goto loc_10d10;
    memoryASet(ds, 0x056c, 0x00);
loc_10d10: // 02f1:de00
    if (memoryAGet(ds, 0x01d6) != 0x00)
        goto loc_10d1a;
    goto loc_10dcc;
loc_10d1a: // 02f1:de0a
    memoryASet(ds, 0x01d6, memoryAGet(ds, 0x01d6) + 1);
    if (memoryAGet(ds, 0x01d6) != 0x02)
        goto loc_10d3a;
    push(0x000e);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    goto loc_10d3a;
loc_10d2e: // 02f1:de1e
    push(0x0002);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet(ds, 0x01d6, memoryAGet(ds, 0x01d6) + 1);
loc_10d3a: // 02f1:de2a
    if (memoryAGet(ds, 0x01d6) < 0x0c)
        goto loc_10d2e;
    if (memoryAGet(ds, 0x01d6) != 0x0d)
        goto loc_10d4f;
    push(0x0007);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_10d4f: // 02f1:de3f
    if (memoryAGet(ds, 0x01d6) <= 0x0c)
        goto loc_10d83;
    if (memoryAGet(ds, 0x01d6) >= 0x13)
        goto loc_10d83;
    push(0x0005);
    al = memoryAGet(ds, 0x01d6);
    ah = 0x00;
    dx = memoryAGet16(ds, 0x5aee);
    dx -= ax;
    dx += 0x000d;
    push(dx);
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    al = memoryAGet(ds, 0x056c);
    ah = 0x00;
    push(ax);
    push(0x00de);
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
loc_10d83: // 02f1:de73
    if (memoryAGet(ds, 0x01d6) <= 0x12)
        goto loc_10da8;
    push(0x0005);
    ax = memoryAGet16(ds, 0x5aee);
    ax += 0xfffa;
    push(ax);
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    al = memoryAGet(ds, 0x056c);
    ah = 0x00;
    push(ax);
    push(0x00de);
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
loc_10da8: // 02f1:de98
    if (memoryAGet(ds, 0x01d6) > 0x1e)
        goto loc_10db2;
    goto loc_10eff;
loc_10db2: // 02f1:dea2
    push(0x0054);
    push(cs);
    cs = 0x02f1;
    sub_10f76(); // 02f1:e066
    assert(cs == 0x02f1);
    cx = pop();
    push(memoryAGet16(ds, 0xa450));
    push(cs);
    cs = 0x02f1;
    sub_12587(); // 02f1:f677
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet(ds, 0x01d6, 0x00);
    goto loc_10efb;
loc_10dcc: // 02f1:debc
    if (memoryAGet16(ds, 0x57fa) == 0x0000)
        goto loc_10dd6;
    goto loc_10e64;
loc_10dd6: // 02f1:dec6
    if (memoryAGet16(ds, 0xa464) != 0x002c)
        goto loc_10df6;
    push(0x0002);
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    al = memoryAGet(ds, 0x01a6);
    al += 0x0f;
    push(ax);
    push(cs);
    sub_4141(); // 02f1:1231
    sp += 0x0008;
    goto loc_10e14;
loc_10df6: // 02f1:dee6
    if (memoryAGet16(ds, 0xa464) <= 0x0028)
        goto loc_10e14;
    push(0x0000);
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    al = memoryAGet(ds, 0x01a6);
    al += 0x0f;
    push(ax);
    push(cs);
    sub_4141(); // 02f1:1231
    sp += 0x0008;
loc_10e14: // 02f1:df04
    if (memoryAGet16(ds, 0xa464) == 0x0000)
        goto loc_10e1f;
    memoryASet16(ds, 0xa464, memoryAGet16(ds, 0xa464) - 1);
loc_10e1f: // 02f1:df0f
    if (memoryAGet16(ds, 0xa464) < 0x0029)
        goto loc_10e29;
    goto loc_10eff;
loc_10e29: // 02f1:df19
    if (memoryAGet16(ds, 0x59e4) != 0x0000)
        goto loc_10e4c;
    push(0x0000);
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    al = memoryAGet(ds, 0x01a6);
    al += memoryAGet(ds, 0x01a8);
    push(ax);
    push(cs);
    sub_4141(); // 02f1:1231
    sp += 0x0008;
    goto loc_10eff;
loc_10e4c: // 02f1:df3c
    push(0x0000);
    push(memoryAGet16(ds, 0x5aee));
    push(memoryAGet16(ds, 0x5ae8));
    push(memoryAGet16(ds, 0xa446));
    push(cs);
    sub_4141(); // 02f1:1231
    sp += 0x0008;
    goto loc_10eff;
loc_10e64: // 02f1:df54
    if (memoryAGet16(ds, 0x57fa) >= 0x000a)
        goto loc_10e99;
    if (memoryAGet16(ds, 0x57fa) != 0x0001)
        goto loc_10e79;
    push(0x000e);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_10e79: // 02f1:df69
    memoryASet16(ds, 0x57fa, memoryAGet16(ds, 0x57fa) + 1);
    push(0x0005);
    push(memoryAGet16(ds, 0x5aee));
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    al = memoryAGet(ds, 0x57fa);
    al &= 0x01;
    al += 0x2e;
    push(ax);
    push(cs);
    sub_4141(); // 02f1:1231
    sp += 0x0008;
    goto loc_10eff;
loc_10e99: // 02f1:df89
    if (memoryAGet16(ds, 0x57fa) <= 0x0009)
        goto loc_10eff;
    if (memoryAGet16(ds, 0x58a8) <= 0x0000)
        goto loc_10eb2;
    if (memoryAGet16(ds, 0x57fa) >= 0x000c)
        goto loc_10eb2;
    memoryASet16(ds, 0x58a8, memoryAGet16(ds, 0x58a8) - 1);
loc_10eb2: // 02f1:dfa2
    if (memoryAGet16(ds, 0x57fa) != 0x000a)
        goto loc_10ec0;
    push(0x0007);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_10ec0: // 02f1:dfb0
    memoryASet16(ds, 0x5aee, memoryAGet16(ds, 0x5aee) - 1);
    memoryASet16(ds, 0x57fa, memoryAGet16(ds, 0x57fa) + 1);
    push(0x0005);
    push(memoryAGet16(ds, 0x5aee));
    ax = memoryAGet16(ds, 0x5ae8);
    ax--;
    push(ax);
    al = memoryAGet(ds, 0x57fa);
    al &= 0x01;
    al += 0x2e;
    push(ax);
    push(cs);
    sub_4141(); // 02f1:1231
    sp += 0x0008;
    if (memoryAGet16(ds, 0x57fa) <= 0x0024)
        goto loc_10eff;
    push(0x0054);
    push(cs);
    cs = 0x02f1;
    sub_10f76(); // 02f1:e066
    assert(cs == 0x02f1);
    cx = pop();
    push(memoryAGet16(ds, 0xa450));
    push(cs);
    cs = 0x02f1;
    sub_12587(); // 02f1:f677
    assert(cs == 0x02f1);
    cx = pop();
loc_10efb: // 02f1:dfeb
    al = 0x01;
    goto loc_10f01;
loc_10eff: // 02f1:dfef
    al = 0x00;
loc_10f01: // 02f1:dff1
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_10f02() // 02f1:dff2
{
    CStackGuardFar sg(0, false);
    memoryASet(ds, 0x59e2, 0x00);
loc_10f07: // 02f1:dff7
    sync();
    if (!(memoryAGet(ds, 0x59e2) & 0x80)) // 1a91:59e2
        goto loc_10f07;
    al = memoryAGet(ds, 0x59e2);
    al &= 0x7f;
    cs = pop();
}
void sub_10f14() // 02f1:e004
{
    sync();
    sync();
    sync();
    sync();
    al = 1;
    return;
    CStackGuardFar sg(0, false);
    in(al, 0x60);
    al &= 0x80;
    flags.carry = al != 0;
    al = -al;
    al -= al + flags.carry;
    al++;
    cbw();
    cs = pop();
}
void sub_10f20() // 02f1:e010
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet(es, bx) != 0x00)
        goto loc_10f36;
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    goto loc_10f72;
loc_10f36: // 02f1:e026
    si = 0;
    goto loc_10f45;
loc_10f3a: // 02f1:e02a
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, bx + si);
    memoryASet(ds, si + 23190, al);
    si++;
loc_10f45: // 02f1:e035
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet(es, bx + si) != 0x00)
        goto loc_10f3a;
    memoryASet(ds, si + 23190, 0x5c);
    si++;
    di = 0;
    goto loc_10f64;
loc_10f58: // 02f1:e048
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    al = memoryAGet(es, bx + di);
    memoryASet(ds, si + 23190, al);
    si++;
    di++;
loc_10f64: // 02f1:e054
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    if (memoryAGet(es, bx + di) != 0x00)
        goto loc_10f58;
    ax = 0x5a96;
    dx = ds;
loc_10f72: // 02f1:e062
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_10f76() // 02f1:e066
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    al = memoryAGet(ss, bp + 6);
    bx = memoryAGet16(ds, 0x056e);
    es = memoryAGet16(ds, 0x056e + 2);
    memoryASet(es, bx + 9, al);
    push(ds);
    ax = 0x0a71;
    push(ax);
    push(memoryAGet16(ds, 0x0570));
    push(bx);
    push(memoryAGet16(ds, 0xa47c));
    push(memoryAGet16(ds, 0xa47a));
    push(cs);
    sub_10f20(); // 02f1:e010
    sp += 0x0008;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1760;
    sub_1781b(); // 1760:021b
    assert(cs == 0x02f1);
    sp += 0x0008;
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    ax |= dx;
    if (ax)
        goto loc_10fc3;
    push(dx);
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    al = 0x00;
    goto loc_110ac;
loc_10fc3: // 02f1:e0b3
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x589c, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(0x0004);
    push(ds);
    ax = 0x5808;
    push(ax);
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ds, 0x5796, dx);
    memoryASet16(ds, 0x5794, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0xa450, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x589e, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x5ae6, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0xa2c8, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x57ec, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x57e6, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x580e, ax);
    si = memoryAGet16(ds, 0x589c);
    si += memoryAGet16(ds, 0x5794);
    si += memoryAGet16(ds, 0xa450);
    si += memoryAGet16(ds, 0x589e);
    si += memoryAGet16(ds, 0x5ae6);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    if (ax == si)
        goto loc_1109d;
    push(cs);
    cs = 0x1282;
    sub_15c59(); // 1282:3439
    assert(cs == 0x02f1);
    push(cs);
    sub_f414(); // 02f1:c504
loc_1109d: // 02f1:e18d
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    al = 0x01;
loc_110ac: // 02f1:e19c
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_110af() // 02f1:e19f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    al = memoryAGet(ss, bp + 6);
    bx = memoryAGet16(ds, 0x0572);
    es = memoryAGet16(ds, 0x0572 + 2);
    memoryASet(es, bx + 9, al);
    push(ds);
    ax = 0x0a74;
    push(ax);
    push(memoryAGet16(ds, 0x0574));
    push(bx);
    push(memoryAGet16(ds, 0xa47c));
    push(memoryAGet16(ds, 0xa47a));
    push(cs);
    sub_10f20(); // 02f1:e010
    sp += 0x0008;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1760;
    sub_1781b(); // 1760:021b
    assert(cs == 0x02f1);
    sp += 0x0008;
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(memoryAGet16(ds, 0x589c));
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(0x0004);
    push(ds);
    ax = 0x5808;
    push(ax);
    push(cs);
    cs = 0x183e;
    sub_183ec(); // 183e:000c
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x5794));
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0xa450));
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x589e));
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x5ae6));
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0xa2c8));
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0002);
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    si = memoryAGet16(ds, 0x589c);
    si += memoryAGet16(ds, 0x5794);
    si += memoryAGet16(ds, 0xa450);
    si += memoryAGet16(ds, 0x589e);
    si += memoryAGet16(ds, 0x5ae6);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(si);
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_111ca() // 02f1:e2ba
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(ds);
    ax = 0x0a87;
    push(ax);
    push(ds);
    ax = 0x0a77;
    push(ax);
    push(0x001c);
    push(0x0007);
    push(0x000b);
    push(cs);
    cs = 0x1282;
    sub_132e3(); // 1282:0ac3
    assert(cs == 0x02f1);
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x0a9a;
    push(ax);
    push(0x000e);
    push(si);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
    push(0x000e);
    ax = si;
    ax += 0x0018;
    push(ax);
    push(cs);
    cs = 0x1282;
    sub_12e5c(); // 1282:063c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x01)
        goto loc_1127b;
    if (memoryAGet(ss, bp - 1) == 0x39)
        goto loc_1127b;
    if (memoryAGet(ss, bp - 1) == 0x1c)
        goto loc_1127b;
    if (memoryAGet(ss, bp - 1) < 0x02)
        goto loc_11252;
    if (memoryAGet(ss, bp - 1) >= 0x0b)
        goto loc_11252;
    push(memoryAGet16(ss, bp - 1));
    push(0x000e);
    ax = si;
    ax += 0x0018;
    push(ax);
    push(cs);
    cs = 0x1282;
    sub_148a4(); // 1282:2084
    assert(cs == 0x02f1);
    sp += 0x0006;
    al = memoryAGet(ss, bp - 1);
    al += 0x2f;
    push(ax);
    push(cs);
    sub_10f76(); // 02f1:e066
    cx = pop();
    if (al)
        goto loc_1124e;
    al = 0x00;
    goto loc_1127d;
loc_1124e: // 02f1:e33e
    al = 0x01;
    goto loc_1127d;
loc_11252: // 02f1:e342
    push(ds);
    ax = 0x0ac8;
    push(ax);
    push(ds);
    ax = 0x0ab3;
    push(ax);
    push(0x001c);
    push(0x0004);
    push(0x000b);
    push(cs);
    cs = 0x1282;
    sub_132e3(); // 1282:0ac3
    assert(cs == 0x02f1);
    sp += 0x000e;
    si = ax;
    push(0x000d);
    ax = si;
    ax += 0x0019;
    push(ax);
    push(cs);
    cs = 0x1282;
    sub_12e5c(); // 1282:063c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
loc_1127b: // 02f1:e36b
    al = 0x02;
loc_1127d: // 02f1:e36d
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_113e1() // 02f1:e4d1
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x1e;
    push(si);
    push(ss);
    ax = bp - 0x1e;
    push(ax);
    push(ds);
    ax = 0x0576;
    push(ax);
    cx = 0x001a;
    push(cs);
    cs = 0x01ed;
    sub_2e5f(); // 01ed:0f8f
    assert(cs == 0x02f1);
    push(ds);
    ax = 0x0b28;
    push(ax);
    push(ds);
    ax = 0x0b1d;
    push(ax);
    push(0x001c);
    push(0x0004);
    push(0x0002);
    push(cs);
    cs = 0x1282;
    sub_132e3(); // 1282:0ac3
    assert(cs == 0x02f1);
    sp += 0x000e;
    si = ax;
    push(0x0002);
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(0x0004);
    ax = si;
    ax += 0x0015;
    push(ax);
    push(cs);
    cs = 0x1282;
    sub_133a1(); // 1282:0b81
    assert(cs == 0x02f1);
    sp += 0x000a;
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(cs);
    cs = 0x19f9;
    sub_19f91(); // 19f9:0001
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    si = ax;
    si--;
    if ((short)si < 0)
        goto loc_11462;
    if ((short)si > (short)0x000c)
        goto loc_11462;
    memoryASet16(ds, 0xa450, si);
    push(0x0054);
    push(cs);
    sub_10f76(); // 02f1:e066
    cx = pop();
    bx = si;
    bx <<= 1;
    ax = bp - 0x1e;
    bx += ax;
    push(memoryAGet16(ss, bx));
    push(cs);
    cs = 0x02f1;
    sub_12587(); // 02f1:f677
    assert(cs == 0x02f1);
    cx = pop();
    al = 0x01;
    goto loc_11464;
loc_11462: // 02f1:e552
    al = 0x00;
loc_11464: // 02f1:e554
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11467() // 02f1:e557
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
    memoryASet(ds, 0x57b0, 0x00);
loc_11472: // 02f1:e562
    push(0x0012);
    push(cs);
    cs = 0x1282;
    sub_14863(); // 1282:2043
    assert(cs == 0x02f1);
    cx = pop();
    push(0x0001);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
    di = 0;
    memoryASet16(ds, 0xa44e, di);
    goto loc_114a8;
loc_11489: // 02f1:e579
    push(0x0003);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
    di++;
    if (di != 0x0258)
        goto loc_1149f;
    push(0x0002);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
loc_1149f: // 02f1:e58f
    if (di != 0x04b0)
        goto loc_114a8;
    goto loc_115aa;
loc_114a8: // 02f1:e598
    push(cs);
    sub_10f14(); // 02f1:e004
    if (!al)
        goto loc_11489;
    push(cs);
    sub_10f02(); // 02f1:dff2
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x10)
        goto loc_114c3;
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_114d2;
loc_114c3: // 02f1:e5b3
    push(cs);
    cs = 0x1282;
    sub_15d6e(); // 1282:354e
    assert(cs == 0x02f1);
    if (!al)
        goto loc_11472;
    push(cs);
    sub_f414(); // 02f1:c504
    goto loc_11472;
loc_114d2: // 02f1:e5c2
    push(cs);
    cs = 0x1282;
    sub_16d51(); // 1282:4531
    assert(cs == 0x02f1);
loc_114d7: // 02f1:e5c7
    push(0x0015);
    push(0x001c);
    push(cs);
    cs = 0x1282;
    sub_12e5c(); // 1282:063c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cx = 0x0011;
    bx = 0xe5ef;
loc_114f0: // 02f1:e5e0
    if (ax == memoryAGet16(cs, bx))
        goto loc_114fb;
    bx++;
    bx++;
    if (--cx)
        goto loc_114f0;
    goto loc_114d7;
loc_114fb: // 02f1:e5eb
    jumpIndirect(cs, memoryAGet16(cs, bx + 34)); // 02f1:e5eb
    return;
    //   gap of 171 bytes
loc_115aa: // 02f1:e69a
    push(cs);
    cs = 0x02f1;
    sub_12749(); // 02f1:f839
    assert(cs == 0x02f1);
    al = 0x02;
    goto loc_115f6;
    //   gap of 67 bytes
loc_115f6: // 02f1:e6e6
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_11472() // 02f1:e562
{
    CStackGuardFar sg(0, false);
loc_11472: // 02f1:e562
    push(0x0012);
    push(cs);
    cs = 0x1282;
    sub_14863(); // 1282:2043
    assert(cs == 0x02f1);
    cx = pop();
    push(0x0001);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
    di = 0;
    memoryASet16(ds, 0xa44e, di);
    goto loc_114a8;
loc_11489: // 02f1:e579
    push(0x0003);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
    di++;
    if (di != 0x0258)
        goto loc_1149f;
    push(0x0002);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
loc_1149f: // 02f1:e58f
    if (di != 0x04b0)
        goto loc_114a8;
    goto loc_115aa;
loc_114a8: // 02f1:e598
    push(cs);
    sub_10f14(); // 02f1:e004
    if (!al)
        goto loc_11489;
    push(cs);
    sub_10f02(); // 02f1:dff2
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x10)
        goto loc_114c3;
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_114d2;
loc_114c3: // 02f1:e5b3
    push(cs);
    cs = 0x1282;
    sub_15d6e(); // 1282:354e
    assert(cs == 0x02f1);
    if (!al)
        goto loc_11472;
    push(cs);
    sub_f414(); // 02f1:c504
    goto loc_11472;
loc_114d2: // 02f1:e5c2
    push(cs);
    cs = 0x1282;
    sub_16d51(); // 1282:4531
    assert(cs == 0x02f1);
loc_114d7: // 02f1:e5c7
    push(0x0015);
    push(0x001c);
    push(cs);
    cs = 0x1282;
    sub_12e5c(); // 1282:063c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cx = 0x0011;
    bx = 0xe5ef;
loc_114f0: // 02f1:e5e0
    if (ax == memoryAGet16(cs, bx))
        goto loc_114fb;
    bx++;
    bx++;
    if (--cx)
        goto loc_114f0;
    goto loc_114d7;
loc_114fb: // 02f1:e5eb
    jumpIndirect(cs, memoryAGet16(cs, bx + 34)); // 02f1:e5eb
    return;
    //   gap of 171 bytes
loc_115aa: // 02f1:e69a
    push(cs);
    cs = 0x02f1;
    sub_12749(); // 02f1:f839
    assert(cs == 0x02f1);
    al = 0x02;
    goto loc_115f6;
    //   gap of 67 bytes
loc_115f6: // 02f1:e6e6
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_1155c() // 02f1:e64c
{
    CStackGuard sg(-1, false); // no return
    goto loc_1155c;
loc_114d2: // 02f1:e5c2
    push(cs);
    cs = 0x1282;
    sub_16d51(); // 1282:4531
    assert(cs == 0x02f1);
loc_114d7: // 02f1:e5c7
    push(0x0015);
    push(0x001c);
    push(cs);
    cs = 0x1282;
    sub_12e5c(); // 1282:063c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cx = 0x0011;
    bx = 0xe5ef;
loc_114f0: // 02f1:e5e0
    if (ax == memoryAGet16(cs, bx))
        goto loc_114fb;
    bx++;
    bx++;
    if (--cx)
        goto loc_114f0;
    goto loc_114d7;
loc_114fb: // 02f1:e5eb
    jumpIndirect(cs, memoryAGet16(cs, bx + 34)); // 02f1:e5eb
    return;
    //   gap of 93 bytes
loc_1155c: // 02f1:e64c
    push(cs);
    cs = 0x1282;
    sub_13e6e(); // 1282:164e
    assert(cs == 0x02f1);
    goto loc_115ec;
    //   gap of 136 bytes
loc_115ec: // 02f1:e6dc
    push(0x0001);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
    goto loc_114d2;
}
void sub_11564() // 02f1:e654
{
    CStackGuard sg(-1, false); // no return
    goto loc_11564;
loc_114d2: // 02f1:e5c2
    push(cs);
    cs = 0x1282;
    sub_16d51(); // 1282:4531
    assert(cs == 0x02f1);
loc_114d7: // 02f1:e5c7
    push(0x0015);
    push(0x001c);
    push(cs);
    cs = 0x1282;
    sub_12e5c(); // 1282:063c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cx = 0x0011;
    bx = 0xe5ef;
loc_114f0: // 02f1:e5e0
    if (ax == memoryAGet16(cs, bx))
        goto loc_114fb;
    bx++;
    bx++;
    if (--cx)
        goto loc_114f0;
    goto loc_114d7;
loc_114fb: // 02f1:e5eb
    jumpIndirect(cs, memoryAGet16(cs, bx + 34)); // 02f1:e5eb
    return;
    //   gap of 101 bytes
loc_11564: // 02f1:e654
    push(cs);
    cs = 0x1282;
    sub_15106(); // 1282:28e6
    assert(cs == 0x02f1);
    goto loc_115ec;
    //   gap of 128 bytes
loc_115ec: // 02f1:e6dc
    push(0x0001);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
    goto loc_114d2;
}
void sub_11574() // 02f1:e664
{
    CStackGuardFar sg(0, false);
    goto loc_11574;
loc_114d2: // 02f1:e5c2
    push(cs);
    cs = 0x1282;
    sub_16d51(); // 1282:4531
    assert(cs == 0x02f1);
loc_114d7: // 02f1:e5c7
    push(0x0015);
    push(0x001c);
    push(cs);
    cs = 0x1282;
    sub_12e5c(); // 1282:063c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cx = 0x0011;
    bx = 0xe5ef;
loc_114f0: // 02f1:e5e0
    if (ax == memoryAGet16(cs, bx))
        goto loc_114fb;
    bx++;
    bx++;
    if (--cx)
        goto loc_114f0;
    goto loc_114d7;
loc_114fb: // 02f1:e5eb
    jumpIndirect(cs, memoryAGet16(cs, bx + 34)); // 02f1:e5eb
    return;
    //   gap of 117 bytes
loc_11574: // 02f1:e664
    push(cs);
    sub_111ca(); // 02f1:e2ba
    memoryASet(ss, bp - 2, al);
    if (memoryAGet(ss, bp - 2) != 0x01)
        goto loc_11586;
    al = 0x00;
    goto loc_115f6;
loc_11586: // 02f1:e676
    if (memoryAGet(ss, bp - 2) != 0x00)
        goto loc_115ec;
    push(cs);
    cs = 0x1282;
    sub_15bc2(); // 1282:33a2
    assert(cs == 0x02f1);
    goto loc_115ec;
    //   gap of 89 bytes
loc_115ec: // 02f1:e6dc
    push(0x0001);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
    goto loc_114d2;
loc_115f6: // 02f1:e6e6
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_115b3() // 02f1:e6a3
{
    CStackGuard sg(-1, false); // no return
    goto loc_115b3;
loc_114d2: // 02f1:e5c2
    push(cs);
    cs = 0x1282;
    sub_16d51(); // 1282:4531
    assert(cs == 0x02f1);
loc_114d7: // 02f1:e5c7
    push(0x0015);
    push(0x001c);
    push(cs);
    cs = 0x1282;
    sub_12e5c(); // 1282:063c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cx = 0x0011;
    bx = 0xe5ef;
loc_114f0: // 02f1:e5e0
    if (ax == memoryAGet16(cs, bx))
        goto loc_114fb;
    bx++;
    bx++;
    if (--cx)
        goto loc_114f0;
    goto loc_114d7;
loc_114fb: // 02f1:e5eb
    jumpIndirect(cs, memoryAGet16(cs, bx + 34)); // 02f1:e5eb
    return;
    //   gap of 180 bytes
loc_115b3: // 02f1:e6a3
    push(cs);
    cs = 0x1282;
    sub_15d6e(); // 1282:354e
    assert(cs == 0x02f1);
    if (!al)
        goto loc_115ec;
    push(cs);
    sub_f414(); // 02f1:c504
    goto loc_115ec;
    //   gap of 42 bytes
loc_115ec: // 02f1:e6dc
    push(0x0001);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
    goto loc_114d2;
}
void sub_115fa() // 02f1:e6ea
{
    CStackGuard sg(-1, true); // no return
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(ds);
    ax = 0x0a87;
    push(ax);
    push(ds);
    ax = 0x0b3c;
    push(ax);
    push(0x0016);
    push(0x000c);
    push(0x0002);
    push(cs);
    cs = 0x1282;
    sub_132e3(); // 1282:0ac3
    assert(cs == 0x02f1);
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x0b46;
    push(ax);
    push(0x0005);
    push(si);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
    push(ds);
    ax = 0x0b57;
    push(ax);
    push(0x0006);
    push(si);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
    push(ds);
    ax = 0x0b68;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
    push(ds);
    ax = 0x0b6f;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
    push(ds);
    ax = 0x0b7f;
    push(ax);
    push(0x0009);
    push(si);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
    push(ds);
    ax = 0x0b92;
    push(ax);
    push(0x000a);
    push(si);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
loc_11673: // 02f1:e763
    push(0x000c);
    push(0x001d);
    push(cs);
    cs = 0x1282;
    sub_12e5c(); // 1282:063c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cx = 0x0007;
    bx = 0xe78b;
loc_1168c: // 02f1:e77c
    if (ax == memoryAGet16(cs, bx))
        goto loc_11697;
    bx++;
    bx++;
    if (--cx)
        goto loc_1168c;
    goto loc_11673;
loc_11697: // 02f1:e787
    jumpIndirect(cs, memoryAGet16(cs, bx + 14)); // 02f1:e787
}
void sub_11704() // 02f1:e7f4
{
    CStackGuardFar sg(0, false);
    bx = memoryAGet16(ds, 0x59f4);
    es = memoryAGet16(ds, 0x59f4 + 2);
    bx += memoryAGet16(ds, 0xa44c);
    al = memoryAGet(es, bx);
    al &= 0x01;
    memoryASet(ds, 0xa448, al);
    bx = memoryAGet16(ds, 0x59f4);
    bx += memoryAGet16(ds, 0xa44c);
    al = memoryAGet(es, bx);
    al &= 0x02;
    memoryASet(ds, 0xa462, al);
    bx = memoryAGet16(ds, 0x59f4);
    bx += memoryAGet16(ds, 0xa44c);
    al = memoryAGet(es, bx);
    al &= 0x04;
    memoryASet(ds, 0xa146, al);
    bx = memoryAGet16(ds, 0x59f4);
    bx += memoryAGet16(ds, 0xa44c);
    al = memoryAGet(es, bx);
    al &= 0x08;
    memoryASet(ds, 0xa2cf, al);
    bx = memoryAGet16(ds, 0x59f4);
    bx += memoryAGet16(ds, 0xa44c);
    al = memoryAGet(es, bx);
    al &= 0x10;
    memoryASet(ds, 0xa484, al);
    bx = memoryAGet16(ds, 0x59f4);
    bx += memoryAGet16(ds, 0xa44c);
    al = memoryAGet(es, bx);
    al &= 0x20;
    memoryASet(ds, 0xa485, al);
    bx = memoryAGet16(ds, 0x59f4);
    bx += memoryAGet16(ds, 0xa44c);
    al = memoryAGet(es, bx);
    ah = 0x00;
    ax &= 0x0040;
    memoryASet16(ds, 0xa470, ax);
    memoryASet16(ds, 0xa44c, memoryAGet16(ds, 0xa44c) + 1);
    ax = memoryAGet16(ds, 0xa44c);
    if (ax <= memoryAGet16(ds, 0x5798))
        goto loc_11788;
    al = 0x01;
    goto loc_1178a;
loc_11788: // 02f1:e878
    al = 0x00;
loc_1178a: // 02f1:e87a
    cs = pop();
}
void sub_1178b() // 02f1:e87b
{
    CStackGuardFar sg(0, false);
    if (memoryAGet16(ds, 0x5798) <= 0x1386)
        goto loc_11797;
    al = 0x01;
    goto loc_117ea;
loc_11797: // 02f1:e887
    al = memoryAGet(ds, 0x590b);
    ah = 0x00;
    memoryASet16(ds, 0xa470, ax);
    al = memoryAGet(ds, 0xa462);
    al <<= 1;
    al |= memoryAGet(ds, 0xa448);
    dl = memoryAGet(ds, 0xa146);
    dl <<= 2;
    al |= dl;
    dl = memoryAGet(ds, 0xa2cf);
    dl <<= 3;
    al |= dl;
    dl = memoryAGet(ds, 0xa484);
    dl <<= 4;
    al |= dl;
    dl = memoryAGet(ds, 0xa485);
    dl <<= 5;
    al |= dl;
    dl = memoryAGet(ds, 0xa470);
    dl <<= 6;
    al |= dl;
    bx = memoryAGet16(ds, 0x59f4);
    es = memoryAGet16(ds, 0x59f4 + 2);
    bx += memoryAGet16(ds, 0xa44c);
    memoryASet(es, bx, al);
    memoryASet16(ds, 0xa44c, memoryAGet16(ds, 0xa44c) + 1);
    memoryASet16(ds, 0x5798, memoryAGet16(ds, 0x5798) + 1);
    al = 0x00;
loc_117ea: // 02f1:e8da
    cs = pop();
}
void sub_117eb() // 02f1:e8db
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(ds);
    ax = 0x0a74;
    push(ax);
    push(ds);
    ax = 0x0b9e;
    push(ax);
    push(cs);
    cs = 0x1760;
    sub_1781b(); // 1760:021b
    assert(cs == 0x02f1);
    sp += 0x0008;
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ds, 0x01a4, 0xfff1);
    push(dx);
    push(ax);
    push(memoryAGet16(ds, 0x5798));
    push(cs);
    cs = 0x1a2f;
    sub_1a2fd(); // 1a2f:000d
    assert(cs == 0x02f1);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(memoryAGet16(ds, 0x5798));
    push(memoryAGet16(ds, 0x59f6));
    push(memoryAGet16(ds, 0x59f4));
    push(cs);
    cs = 0x183e;
    sub_183ec(); // 183e:000c
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11846() // 02f1:e936
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(ds);
    ax = 0x0b9e;
    push(ax);
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ds, 0x01a4, 0xfff1);
    ax |= dx;
    if (ax)
        goto loc_11874;
    memoryASet16(ds, 0x5798, 0x0000);
    memoryASet16(ds, 0xa44c, 0x0000);
    goto loc_1189d;
loc_11874: // 02f1:e964
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x5798, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(ax);
    push(memoryAGet16(ds, 0x59f6));
    push(memoryAGet16(ds, 0x59f4));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
loc_1189d: // 02f1:e98d
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_118ac() // 02f1:e99c
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    if (memoryAGet(ss, bp + 6) != 0x02)
        goto loc_118b9;
    goto loc_11a2f;
loc_118b9: // 02f1:e9a9
    if (memoryAGet(ds, 0x58ed) == 0x00)
        goto loc_118ea;
    if (memoryAGet(ds, 0x5936) == 0x00)
        goto loc_118ea;
    if (memoryAGet(ds, 0x5931) == 0x00)
        goto loc_118ea;
    al = memoryAGet(ds, 0x01ac);
    flags.carry = al != 0;
    al = -al;
    al -= al + flags.carry;
    al++;
    cbw();
    memoryASet(ds, 0x01ac, al);
    push(0x0029);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    push(0x005a);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
loc_118ea: // 02f1:e9da
    if (memoryAGet(ds, 0x5922) != 0x00)
        goto loc_118f4;
    goto loc_11966;
loc_118f4: // 02f1:e9e4
    if (memoryAGet(ds, 0x01ac) != 0x00)
        goto loc_118fe;
    goto loc_11966;
loc_118fe: // 02f1:e9ee
    if (memoryAGet(ds, 0x5900) == 0x00)
        goto loc_1190a;
    push(cs);
    cs = 0x1282;
    sub_15fad(); // 1282:378d
    assert(cs == 0x02f1);
loc_1190a: // 02f1:e9fa
    if (memoryAGet(ds, 0x58ef) == 0x00)
        goto loc_1191c;
    push(cs);
    sub_113e1(); // 02f1:e4d1
    if (!al)
        goto loc_1191c;
    goto loc_11a01;
loc_1191c: // 02f1:ea0c
    if (memoryAGet(ds, 0x58f7) == 0x00)
        goto loc_1193f;
    push(0x0029);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
loc_1192a: // 02f1:ea1a
    sync();
    if (memoryAGet(ds, 0x58f7) != 0x00)
        goto loc_1192a;
loc_11931: // 02f1:ea21
    sync();
    if (memoryAGet(ds, 0x58f7) == 0x00)
        goto loc_11931;
loc_11938: // 02f1:ea28
    sync();
    if (memoryAGet(ds, 0x58f7) != 0x00)
        goto loc_11938;
loc_1193f: // 02f1:ea2f
    if (memoryAGet(ds, 0x5910) == 0x00)
        goto loc_1194b;
    push(cs);
    cs = 0x1282;
    sub_16001(); // 1282:37e1
    assert(cs == 0x02f1);
loc_1194b: // 02f1:ea3b
    if (memoryAGet(ds, 0x58f0) == 0x00)
        goto loc_11966;
    if (memoryAGet(ds, 0x590f) == 0x00)
        goto loc_11966;
    if (memoryAGet(ds, 0x58fe) == 0x00)
        goto loc_11966;
    memoryASet16(ds, 0x40ba, 0x0001);
loc_11966: // 02f1:ea56
    if (memoryAGet(ds, 0x590c) == 0x00)
        goto loc_119b6;
    if (memoryAGet(ds, 0x58e9) == 0x00)
        goto loc_119b6;
    if (memoryAGet(ds, 0x5922) == 0x00)
        goto loc_119b6;
    if (memoryAGet16(ds, 0xa2c8) != 0x0000)
        goto loc_119b6;
    push(0x0029);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    memoryASet16(ds, 0xa2c8, 0x0001);
    push(cs);
    cs = 0x1282;
    sub_16b30(); // 1282:4310
    assert(cs == 0x02f1);
    memoryASet16(ds, 0x5ae6, 0x0005);
    memoryASet16(ds, 0x589e, 0x0009);
    memoryASet16(ds, 0x57ec, 0x0001);
    memoryASet16(ds, 0x589c, 0x0006);
    push(cs);
    cs = 0x1282;
    sub_138e4(); // 1282:10c4
    assert(cs == 0x02f1);
    push(cs);
    cs = 0x1282;
    sub_1399b(); // 1282:117b
    assert(cs == 0x02f1);
loc_119b6: // 02f1:eaa6
    if (memoryAGet(ds, 0x58fd) == 0x00)
        goto loc_119c5;
    push(cs);
    cs = 0x1282;
    sub_15dac(); // 1282:358c
    assert(cs == 0x02f1);
    goto loc_11a38;
loc_119c5: // 02f1:eab5
    if (memoryAGet(ds, 0x5910) == 0x00)
        goto loc_119d3;
    push(cs);
    cs = 0x1282;
    sub_15e00(); // 1282:35e0
    assert(cs == 0x02f1);
    goto loc_11a38;
loc_119d3: // 02f1:eac3
    if (memoryAGet(ds, 0x58df) != 0x00)
        goto loc_119e1;
    if (memoryAGet(ds, 0x58ee) == 0x00)
        goto loc_119ed;
loc_119e1: // 02f1:ead1
    push(cs);
    cs = 0x1282;
    sub_15d6e(); // 1282:354e
    assert(cs == 0x02f1);
    if (!al)
        goto loc_11a38;
    goto loc_11ae2;
loc_119ed: // 02f1:eadd
    if (memoryAGet(ds, 0x5919) == 0x00)
        goto loc_11a1a;
    push(cs);
    sub_115fa(); // 02f1:e6ea
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_11a06;
loc_11a01: // 02f1:eaf1
    al = 0x02;
    goto loc_11ae8;
loc_11a06: // 02f1:eaf6
    if (memoryAGet(ss, bp - 1) != 0x02)
        goto loc_11a38;
    push(cs);
    cs = 0x1282;
    sub_15d6e(); // 1282:354e
    assert(cs == 0x02f1);
    if (!al)
        goto loc_11a18;
    goto loc_11ae2;
loc_11a18: // 02f1:eb08
    goto loc_11a38;
loc_11a1a: // 02f1:eb0a
    if (memoryAGet(ds, 0x58f7) == 0x00)
        goto loc_11a38;
    push(0x0029);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    push(cs);
    cs = 0x1282;
    sub_15f66(); // 1282:3746
    assert(cs == 0x02f1);
    goto loc_11a38;
loc_11a2f: // 02f1:eb1f
    in(al, 0x60);
    if (al & 0x80)
        goto loc_11a38;
    goto loc_11ae2;
loc_11a38: // 02f1:eb28
    if (memoryAGet(ss, bp + 6) != 0x02)
        goto loc_11a41;
    goto loc_11ada;
loc_11a41: // 02f1:eb31
    if (memoryAGet16(ds, 0xa2c6) != 0x0000)
        goto loc_11ab0;
    al = memoryAGet(ds, 0xa2ce);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 22750);
    cl = memoryAGet(ds, 0x573c);
    al >>= cl;
    memoryASet(ds, 0xa448, al);
    al = memoryAGet(ds, 0xa45c);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 22750);
    cl = memoryAGet(ds, 0x573c);
    al >>= cl;
    memoryASet(ds, 0xa462, al);
    al = memoryAGet(ds, 0xa47e);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 22750);
    cl = memoryAGet(ds, 0x573c);
    al >>= cl;
    memoryASet(ds, 0xa484, al);
    al = memoryAGet(ds, 0x6134);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 22750);
    memoryASet(ds, 0xa146, al);
    al = memoryAGet(ds, 0xa2c2);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 22750);
    memoryASet(ds, 0xa2cf, al);
    al = memoryAGet(ds, 0xa47f);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 22750);
    memoryASet(ds, 0xa485, al);
    goto loc_11ab8;
loc_11ab0: // 02f1:eba0
    push(0x0001);
    push(cs);
    cs = 0x1282;
    sub_12f7b(); // 1282:075b
    assert(cs == 0x02f1);
    cx = pop();
loc_11ab8: // 02f1:eba8
    if (memoryAGet16(ds, 0x57b8) == 0x0000)
        goto loc_11aca;
    al = 0x00;
    memoryASet(ds, 0xa485, al);
    memoryASet(ds, 0xa2cf, al);
    memoryASet(ds, 0xa146, al);
loc_11aca: // 02f1:ebba
    if (memoryAGet(ss, bp + 6) != 0x01)
        goto loc_11ae6;
    push(cs);
    sub_1178b(); // 02f1:e87b
    if (al)
        goto loc_11ae2;
    goto loc_11ae6;
loc_11ada: // 02f1:ebca
    push(cs);
    sub_11704(); // 02f1:e7f4
    if (!al)
        goto loc_11ae6;
loc_11ae2: // 02f1:ebd2
    al = 0x01;
    goto loc_11ae8;
loc_11ae6: // 02f1:ebd6
    al = 0x00;
loc_11ae8: // 02f1:ebd8
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_11aea() // 02f1:ebda
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
    memoryASet16(ss, bp - 2, 0x0000);
    push(cs);
    cs = 0x1282;
    sub_14897(); // 1282:2077
    assert(cs == 0x02f1);
    ax = memoryAGet16(ds, 0x5794);
    ax |= memoryAGet16(ds, 0x5796);
    if (ax)
        goto loc_11b0b;
    push(cs);
    cs = 0x1282;
    sub_12def(); // 1282:05cf
    assert(cs == 0x02f1);
    goto loc_11cdf;
loc_11b0b: // 02f1:ebfb
    push(0x0003);
    push(cs);
    cs = 0x1282;
    sub_12d6d(); // 1282:054d
    assert(cs == 0x02f1);
    cx = pop();
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x02f1);
    cx = pop();
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_22d4(); // 01ed:0404
    assert(cs == 0x02f1);
    cx = pop();
    push(cs);
    cs = 0x1282;
    sub_12ead(); // 1282:068d
    assert(cs == 0x02f1);
    push(ds);
    ax = 0x05a0;
    push(ax);
    push(ds);
    ax = 0x0bab;
    push(ax);
    push(0x001e);
    push(0x000e);
    push(0x0002);
    push(cs);
    cs = 0x1282;
    sub_132e3(); // 1282:0ac3
    assert(cs == 0x02f1);
    sp += 0x000e;
    push(0x0006);
    push(0x0008);
    push(0x0008);
    push(0x0002);
    push(0x0001);
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
    push(ds);
    ax = 0x0bc0;
    push(ax);
    push(0x0007);
    push(0x000e);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
    dx = memoryAGet16(ds, 0x5796);
    ax = memoryAGet16(ds, 0x5794);
    cx = 0;
    bx = 0x03e8;
    push(cs);
    cs = 0x01ed;
    sub_2c29(); // 01ed:0d59
    assert(cs == 0x02f1);
    push(dx);
    push(ax);
    push(0x0007);
    push(0x001b);
    push(cs);
    cs = 0x1282;
    sub_136e6(); // 1282:0ec6
    assert(cs == 0x02f1);
    sp += 0x0008;
    push(0x0032);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
    push(ds);
    ax = 0x0bc9;
    push(ax);
    push(0x000c);
    push(0x000a);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
    push(memoryAGet16(ds, 0x580a));
    push(memoryAGet16(ds, 0x5808));
    push(0x000c);
    push(0x001d);
    push(cs);
    cs = 0x1282;
    sub_136e6(); // 1282:0ec6
    assert(cs == 0x02f1);
    sp += 0x0008;
    push(cs);
    cs = 0x1282;
    sub_12de7(); // 1282:05c7
    assert(cs == 0x02f1);
    push(0x0064);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
    di = memoryAGet16(ds, 0x5794);
    goto loc_11cc3;
loc_11bc0: // 02f1:ecb0
    flags.carry = (memoryAGet16(ds, 0x5808) + 0x03e8) >= 0x10000;
    memoryASet16(ds, 0x5808, memoryAGet16(ds, 0x5808) + 0x03e8);
    memoryASet16(ds, 0x580a, memoryAGet16(ds, 0x580a) + flags.carry);
    push(0x000f);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
    si = 0;
    goto loc_11bf4;
loc_11bd7: // 02f1:ecc7
    push(0x000c);
    ax = si;
    ax += 0x0017;
    push(ax);
    dx = memoryAGet16(ds, 0x58a2);
    ax = memoryAGet16(ds, 0x58a0);
    ax += 0x0f28;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
    si++;
loc_11bf4: // 02f1:ece4
    if (si < 0x0007)
        goto loc_11bd7;
    push(0x0001);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    push(memoryAGet16(ds, 0x580a));
    push(memoryAGet16(ds, 0x5808));
    push(0x000c);
    push(0x001d);
    push(cs);
    cs = 0x1282;
    sub_136e6(); // 1282:0ec6
    assert(cs == 0x02f1);
    sp += 0x0008;
    ax = memoryAGet16(ss, bp - 2);
    bx = 0x0006;
    dx = 0;
    div(bx);
    if (ax >= 0x000d)
        goto loc_11c26;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_11c26: // 02f1:ed16
    si = 0;
    goto loc_11c73;
loc_11c2a: // 02f1:ed1a
    if (si >= 0x0007)
        goto loc_11c4b;
    push(0x0007);
    ax = si;
    ax += 0x0016;
    push(ax);
    dx = memoryAGet16(ds, 0x58a2);
    ax = memoryAGet16(ds, 0x58a0);
    ax += 0x0f28;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_11c4b: // 02f1:ed3b
    ax = memoryAGet16(ss, bp - 2);
    ax &= 0x0007;
    if (ax != 0x0001)
        goto loc_11c72;
    push(0x000e);
    ax = si;
    ax += 0x000d;
    push(ax);
    dx = memoryAGet16(ds, 0x58a2);
    ax = memoryAGet16(ds, 0x58a0);
    ax += 0x0f28;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x02f1);
    sp += 0x0008;
loc_11c72: // 02f1:ed62
    si++;
loc_11c73: // 02f1:ed63
    if (si < 0x0010)
        goto loc_11c2a;
    ax = di;
    ax--;
    dx = 0;
    cx = 0;
    bx = 0x03e8;
    push(cs);
    cs = 0x01ed;
    sub_2c29(); // 01ed:0d59
    assert(cs == 0x02f1);
    push(dx);
    push(ax);
    push(0x0007);
    push(0x001b);
    push(cs);
    cs = 0x1282;
    sub_136e6(); // 1282:0ec6
    assert(cs == 0x02f1);
    sp += 0x0008;
    ax = memoryAGet16(ss, bp - 2);
    ax &= 0x0007;
    if (ax != 0x0001)
        goto loc_11cc2;
    ax = memoryAGet16(ss, bp - 2);
    bx = 0x0006;
    dx = 0;
    div(bx);
    bx = ax;
    bx <<= 2;
    push(memoryAGet16(ds, bx + 806));
    push(memoryAGet16(ds, bx + 804));
    push(0x000e);
    push(0x000d);
    push(cs);
    sub_3088(); // 02f1:0178
    sp += 0x0008;
loc_11cc2: // 02f1:edb2
    di--;
loc_11cc3: // 02f1:edb3
    if (stop(/*condition!*/))
        goto loc_11cca;
    goto loc_11bc0;
loc_11cca: // 02f1:edba
    push(0x0190);
    push(cs);
    cs = 0x1282;
    sub_12d0f(); // 1282:04ef
    assert(cs == 0x02f1);
    cx = pop();
    memoryASet16(ds, 0x5796, 0x0000);
    memoryASet16(ds, 0x5794, 0x0000);
loc_11cdf: // 02f1:edcf
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11d42() // 02f1:ee32
{
    CStackGuardFar sg(0, false);
    push(si);
    si = memoryAGet16(ds, 0x5794);
    if (memoryAGet(ds, 0x59dd) == 0x00)
        goto loc_11d9b;
    ax = memoryAGet16(ds, 0xa450);
    cx = 0x0004;
    bx = 0xee57;
loc_11d57: // 02f1:ee47
    if (ax == memoryAGet16(cs, bx))
        goto loc_11d63;
    bx++;
    bx++;
    if (--cx)
        goto loc_11d57;
    goto loc_11e50;
loc_11d63: // 02f1:ee53
    jumpIndirect(cs, memoryAGet16(cs, bx + 8)); // 02f1:ee53
    return;
    //   gap of 52 bytes
loc_11d9b: // 02f1:ee8b
    ax = memoryAGet16(ds, 0xa450);
    if (ax <= 0x001b)
        goto loc_11da6;
    goto loc_11e50;
loc_11da6: // 02f1:ee96
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 61087)); // 02f1:ee9a
    return;
    //   gap of 161 bytes
loc_11e50: // 02f1:ef40
    si = pop();
    cs = pop();
}
void sub_11e52() // 02f1:ef42
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
loc_11e56: // 02f1:ef46
    sync();
    if (memoryAGet16(ds, 0xa44e) < 0x000d)
        goto loc_11e56;
    memoryASet16(ds, 0xa44e, 0x0000);
    push(cs);
    sub_2fcb(); // 02f1:00bb
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ds, 0x01d2));
    push(cs);
    sub_f1df(); // 02f1:c2cf
    cx = pop();
    cx = pop();
    ah = 0x00;
    si = ax;
    if (si != 0x0001)
        goto loc_11e80;
    goto loc_11f55;
loc_11e80: // 02f1:ef70
    if (si == 0x0002)
        goto loc_11e56;
    push(cs);
    sub_fadf(); // 02f1:cbcf
    if (memoryAGet16(ds, 0xa148) == 0x0000)
        goto loc_11e94;
    push(cs);
    sub_10843(); // 02f1:d933
loc_11e94: // 02f1:ef84
    if (memoryAGet16(ds, 0xa472) != 0x0000)
        goto loc_11ea2;
    if (memoryAGet16(ds, 0xa14a) == 0x0000)
        goto loc_11ea6;
loc_11ea2: // 02f1:ef92
    push(cs);
    sub_10c66(); // 02f1:dd56
loc_11ea6: // 02f1:ef96
    push(cs);
    sub_45b4(); // 02f1:16a4
    push(cs);
    sub_4750(); // 02f1:1840
    push(cs);
    sub_35ca(); // 02f1:06ba
    push(cs);
    sub_10cd2(); // 02f1:ddc2
    if (al)
        goto loc_11e56;
    push(cs);
    sub_4873(); // 02f1:1963
    push(cs);
    sub_f1b8(); // 02f1:c2a8
    push(cs);
    sub_d082(); // 02f1:a172
    push(cs);
    sub_d48e(); // 02f1:a57e
    push(cs);
    sub_cf64(); // 02f1:a054
    push(cs);
    sub_d304(); // 02f1:a3f4
    push(cs);
    sub_d61c(); // 02f1:a70c
    push(cs);
    sub_4943(); // 02f1:1a33
    if (memoryAGet(ds, 0x59dd) == 0x00)
        goto loc_11ef3;
    push(0x0006);
    push(0x0004);
    push(0x0012);
    push(0x0000);
    push(0x010a);
    push(cs);
    sub_3ea5(); // 02f1:0f95
    sp += 0x000a;
loc_11ef3: // 02f1:efe3
    push(memoryAGet16(ds, 0x01d2));
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x02f1);
    cx = pop();
    ax = memoryAGet16(ds, 0x01d2);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    memoryASet16(ds, 0x01d2, ax);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22d4(); // 01ed:0404
    assert(cs == 0x02f1);
    cx = pop();
    if (memoryAGet16(ds, 0x57e6) != 0x0001)
        goto loc_11f21;
    memoryASet16(ds, 0x57e6, 0x0002);
    push(cs);
    cs = 0x1282;
    sub_16ed9(); // 1282:46b9
    assert(cs == 0x02f1);
loc_11f21: // 02f1:f011
    if (memoryAGet16(ds, 0xa470) == 0x0000)
        goto loc_11f46;
    memoryASet16(ds, 0xa470, 0x0000);
    push(0x000b);
    push(cs);
    sub_3448(); // 02f1:0538
    cx = pop();
    push(cs);
    sub_11d42(); // 02f1:ee32
    push(memoryAGet16(ds, 0xa450));
    push(cs);
    cs = 0x02f1;
    sub_12587(); // 02f1:f677
    assert(cs == 0x02f1);
    cx = pop();
    goto loc_11e56;
loc_11f46: // 02f1:f036
    if (memoryAGet16(ds, 0x40ba) != 0x0000)
        goto loc_11f50;
    goto loc_11e56;
loc_11f50: // 02f1:f040
    push(cs);
    cs = 0x1282;
    sub_16500(); // 1282:3ce0
    assert(cs == 0x02f1);
loc_11f55: // 02f1:f045
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11f58() // 02f1:f048
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 12);
    si = memoryAGet16(ss, bp + 10);
    if (memoryAGet16(ss, bp + 8) < 0x0020)
        goto loc_11f6c;
    goto loc_120f4;
loc_11f6c: // 02f1:f05c
    ax = memoryAGet16(ss, bp + 8);
    if (ax <= 0x0008)
        goto loc_11f77;
    goto loc_120f4;
loc_11f77: // 02f1:f067
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 61552)); // 02f1:f06b
    return;
    //   gap of 372 bytes
loc_120f4: // 02f1:f1e4
    if (memoryAGet16(ss, bp + 8) < 0x001f)
        goto loc_12115;
    push(di);
    push(si);
    ax = memoryAGet16(ss, bp + 8);
    ax += 0xffe1;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_a84c(); // 02f1:793c
    sp += 0x0008;
    if (!al)
        goto loc_12115;
    memoryASet16(ds, 0x579a, memoryAGet16(ds, 0x579a) + 1);
loc_12115: // 02f1:f205
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12119() // 02f1:f209
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0xa;
    push(si);
    push(di);
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 2;
    push(memoryAGet16(ds, bx + 610));
    push(memoryAGet16(ds, bx + 608));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    memoryASet(ds, 0x01a3, 0x00);
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0xa468, ax);
    cx = 0x0007;
    bx = 0xf25d;
loc_1215e: // 02f1:f24e
    if (ax == memoryAGet16(cs, bx))
        goto loc_12169;
    bx++;
    bx++;
    if (--cx)
        goto loc_1215e;
    goto loc_121bf;
loc_12169: // 02f1:f259
    jumpIndirect(cs, memoryAGet16(cs, bx + 14)); // 02f1:f259
    return;
    //   gap of 82 bytes
loc_121bf: // 02f1:f2af
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 8, ax);
    memoryASet16(ds, 0x579a, 0x0000);
    memoryASet16(ds, 0x579c, 0x0000);
    memoryASet16(ds, 0x57d8, 0x0000);
    memoryASet16(ds, 0x57b6, 0x0000);
    memoryASet16(ds, 0x5a8e, 0x0001);
    memoryASet16(ds, 0x40b8, 0x0000);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0002);
    push(ax);
    push(memoryAGet16(ds, 0x59fa));
    push(memoryAGet16(ds, 0x59f8));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    memoryASet16(ss, bp - 10, 0x0000);
    goto loc_1225e;
loc_12213: // 02f1:f303
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ss, bp - 6, ax);
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    bx += ax;
    si = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(ss, bp - 10);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    bx += ax;
    di = memoryAGet16(es, bx + 4);
    push(di);
    push(si);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ds, 0x579a));
    push(cs);
    sub_11f58(); // 02f1:f048
    sp += 0x0008;
    if (memoryAGet16(ds, 0x579a) > 0x0199)
        goto loc_12266;
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 0x0003);
loc_1225e: // 02f1:f34e
    ax = memoryAGet16(ss, bp - 10);
    if (ax < memoryAGet16(ss, bp - 8))
        goto loc_12213;
loc_12266: // 02f1:f356
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(0xffff);
    push(memoryAGet16(ds, 0x59fa));
    push(memoryAGet16(ds, 0x59f8));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 10, 0x0000);
    goto loc_12307;
loc_12294: // 02f1:f384
    memoryASet16(ss, bp - 6, 0x0002);
    goto loc_122fe;
loc_1229b: // 02f1:f38b
    ax = memoryAGet16(ss, bp - 10);
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0x5a00;
    push(ds);
    es = pop();
    ax = memoryAGet16(es, bx);
    ax <<= 1;
    bx = memoryAGet16(ds, 0x59f8);
    es = memoryAGet16(ds, 0x59f8 + 2);
    bx += ax;
    ax = memoryAGet16(ss, bp - 10);
    imul(ax, ax, 0x000e);
    push(es);
    push(bx);
    bx = ax;
    bx += 0x5a00;
    push(ds);
    es = pop();
    ax = memoryAGet16(es, bx + 2);
    cl = memoryAGet(ds, 0x59fe);
    ax <<= cl;
    ax <<= 1;
    bx = pop();
    es = pop();
    bx += ax;
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    bx += ax;
    bx += 0xfff8;
    ax = memoryAGet16(es, bx);
    push(ax);
    ax = memoryAGet16(ss, bp - 10);
    imul(ax, ax, 0x000e);
    bx = ax;
    bx += 0x5a00;
    push(ds);
    es = pop();
    ax = memoryAGet16(ss, bp - 6);
    ax <<= 1;
    bx += ax;
    ax = pop();
    memoryASet16(es, bx, ax);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
loc_122fe: // 02f1:f3ee
    if (memoryAGet16(ss, bp - 6) < 0x0007)
        goto loc_1229b;
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + 1);
loc_12307: // 02f1:f3f7
    ax = memoryAGet16(ss, bp - 10);
    if (ax < memoryAGet16(ds, 0x579c))
        goto loc_12294;
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0xa450, ax);
    ax = memoryAGet16(ds, 0xa468);
    ax <<= 1;
    dx = 0;
    push(dx);
    push(ax);
    push(0x0001);
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_2d97(); // 01ed:0ec7
    assert(cs == 0x02f1);
    ax += 0xffed;
    memoryASet16(ds, 0xa456, ax);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12332() // 02f1:f422
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    if (ax != memoryAGet16(ds, 0x0590))
        goto loc_12350;
    ax = memoryAGet16(ds, 0x57b2);
    if (ax != memoryAGet16(ds, 0x0592))
        goto loc_12350;
    ax = memoryAGet16(ds, 0x57aa);
    if (ax == memoryAGet16(ds, 0x0594))
        goto loc_12366;
loc_12350: // 02f1:f440
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x0590, ax);
    ax = memoryAGet16(ds, 0x57b2);
    memoryASet16(ds, 0x0592, ax);
    ax = memoryAGet16(ds, 0x57aa);
    memoryASet16(ds, 0x0594, ax);
    al = 0x01;
    goto loc_12368;
loc_12366: // 02f1:f456
    al = 0x00;
loc_12368: // 02f1:f458
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1236a() // 02f1:f45a
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(0xff08);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x01a4, 0xffff);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(0x0001);
    push(0x5a00);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(0xa300);
    push(0x1680);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    sub_3530(); // 02f1:0620
    sp += 0x0008;
    if (memoryAGet16(ds, 0x57b2) == 0x0000)
        goto loc_12402;
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    ax += 0x5a00;
    push(dx);
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    cs = 0x1282;
    sub_14c93(); // 1282:2473
    assert(cs == 0x02f1);
    sp += 0x0008;
    push(0xb980);
    push(0x1680);
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    ax += 0x5a00;
    push(dx);
    push(ax);
    push(cs);
    sub_3530(); // 02f1:0620
    sp += 0x0008;
loc_12402: // 02f1:f4f2
    if (memoryAGet16(ds, 0x57aa) != 0x0000)
        goto loc_1240c;
    goto loc_1248d;
loc_1240c: // 02f1:f4fc
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    ax += 0xb400;
    push(dx);
    push(ax);
    dx = memoryAGet16(ds, 0x59f6);
    ax = memoryAGet16(ds, 0x59f4);
    ax += 0x1388;
    push(dx);
    push(ax);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    cs = 0x1282;
    sub_14b63(); // 1282:2343
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(0xd000);
    push(0x1680);
    dx = memoryAGet16(ds, 0x59f6);
    ax = memoryAGet16(ds, 0x59f4);
    ax += 0x1388;
    push(dx);
    push(ax);
    push(cs);
    sub_3530(); // 02f1:0620
    sp += 0x0008;
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    ax += 0xb400;
    push(dx);
    push(ax);
    dx = memoryAGet16(ds, 0x59f6);
    ax = memoryAGet16(ds, 0x59f4);
    ax += 0x1388;
    push(dx);
    push(ax);
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    ax += 0x5a00;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1282;
    sub_14b63(); // 1282:2343
    assert(cs == 0x02f1);
    sp += 0x000c;
    push(0xe680);
    push(0x1680);
    dx = memoryAGet16(ds, 0x59f6);
    ax = memoryAGet16(ds, 0x59f4);
    ax += 0x1388;
    push(dx);
    push(ax);
    push(cs);
    sub_3530(); // 02f1:0620
    sp += 0x0008;
loc_1248d: // 02f1:f57d
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1249c() // 02f1:f58c
{
    CStackGuardFar sg(0, false);
    memoryASet16(ds, 0x40ba, 0x0000);
    memoryASet(ds, 0xa45b, 0x00);
    memoryASet(ds, 0x58a4, 0x01);
    memoryASet(ds, 0xa46a, 0x01);
    memoryASet(ds, 0x5742, 0x00);
    memoryASet16(ds, 0x5740, 0x0001);
    memoryASet16(ds, 0x035a, 0x0000);
    memoryASet16(ds, 0x0358, 0x0000);
    memoryASet16(ds, 0xa458, 0x0003);
    memoryASet16(ds, 0x01a8, 0x0000);
    memoryASet16(ds, 0x01a6, 0x0017);
    memoryASet16(ds, 0x57fa, 0x0000);
    memoryASet16(ds, 0xa470, 0x0000);
    memoryASet16(ds, 0xa464, 0x0028);
    memoryASet16(ds, 0x57b4, 0x0000);
    memoryASet16(ds, 0xa2c4, 0x0000);
    memoryASet(ds, 0x57d6, 0x00);
    memoryASet16(ds, 0xa148, 0x0000);
    memoryASet16(ds, 0xa480, 0x0000);
    memoryASet16(ds, 0xa46c, 0x0000);
    memoryASet16(ds, 0x57a0, 0x0001);
    memoryASet(ds, 0x573c, 0x00);
    push(cs);
    sub_2f32(); // 02f1:0022
    memoryASet16(ds, 0x57b8, 0x0000);
    memoryASet16(ds, 0x5a94, 0x0001);
    memoryASet(ds, 0xa478, 0x00);
    memoryASet16(ds, 0x57ae, 0x0000);
    memoryASet16(ds, 0x57ac, 0x0000);
    memoryASet16(ds, 0xa482, 0x0000);
    memoryASet(ds, 0x01d6, 0x00);
    memoryASet16(ds, 0x01aa, 0x0000);
    memoryASet(ds, 0x57dc, 0x00);
    memoryASet16(ds, 0x57a4, 0x0000);
    memoryASet16(ds, 0x57a2, 0x0000);
    memoryASet16(ds, 0x57d0, 0x0000);
    ax = 0;
    memoryASet16(ds, 0x57ea, ax);
    memoryASet16(ds, 0x57f6, ax);
    memoryASet16(ds, 0x57e8, ax);
    memoryASet16(ds, 0x57e0, ax);
    memoryASet16(ds, 0x57f8, ax);
    memoryASet16(ds, 0x57de, ax);
    memoryASet16(ds, 0x580c, ax);
    memoryASet16(ds, 0x57fc, ax);
    memoryASet16(ds, 0x57f2, ax);
    memoryASet16(ds, 0x57f4, ax);
    memoryASet16(ds, 0x5806, ax);
    cs = pop();
}
void sub_12587() // 02f1:f677
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 6);
    if (si)
        goto loc_125ad;
    if (memoryAGet(ds, 0x57b0) == 0x00)
        goto loc_125ad;
    push(0x0005);
    push(cs);
    sub_32c6(); // 02f1:03b6
    cx = pop();
    push(0x012c);
    push(cs);
    cs = 0x1282;
    sub_12d22(); // 1282:0502
    assert(cs == 0x02f1);
    cx = pop();
    goto loc_125b2;
loc_125ad: // 02f1:f69d
    push(cs);
    cs = 0x1282;
    sub_12def(); // 1282:05cf
    assert(cs == 0x02f1);
loc_125b2: // 02f1:f6a2
    bx = si;
    bx <<= 2;
    push(memoryAGet16(ds, bx + 610));
    push(memoryAGet16(ds, bx + 608));
    push(cs);
    cs = 0x1282;
    sub_13c31(); // 1282:1411
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1a03;
    sub_1a03e(); // 1a03:000e
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0xa2d8, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x02f1);
    cx = pop();
    cx = pop();
    push(cs);
    cs = 0x1282;
    sub_14897(); // 1282:2077
    assert(cs == 0x02f1);
    ax = memoryAGet16(ds, 0xa2d8);
    ax &= 0x0020;
    memoryASet16(ds, 0x59de, ax);
    di = memoryAGet16(ds, 0xa2d8);
    di &= 0x001f;
    ax = memoryAGet16(ds, 0xa2d8);
    ax &= 0x0040;
    memoryASet16(ds, 0x57b2, ax);
    ax = memoryAGet16(ds, 0xa2d8);
    ax &= 0x0080;
    memoryASet16(ds, 0x57aa, ax);
    ax = memoryAGet16(ds, 0xa2d8);
    ax >>= 8;
    al &= 0x07;
    memoryASet(ds, 0xa45a, al);
    ax = memoryAGet16(ds, 0xa2d8);
    ax >>= 11;
    ax &= 0x001f;
    memoryASet16(ds, 0xa476, ax);
    push(cs);
    sub_1249c(); // 02f1:f58c
    push(di);
    push(cs);
    sub_12332(); // 02f1:f422
    cx = pop();
    if (!al)
        goto loc_1264e;
    push(memoryAGet16(ds, 0x59fa));
    push(memoryAGet16(ds, 0x59f8));
    bx = di;
    bx <<= 2;
    push(memoryAGet16(ds, bx + 506));
    push(memoryAGet16(ds, bx + 504));
    push(cs);
    sub_1236a(); // 02f1:f45a
    sp += 0x0008;
loc_1264e: // 02f1:f73e
    push(si);
    push(cs);
    sub_12119(); // 02f1:f209
    cx = pop();
    if (si)
        goto loc_12669;
    if (memoryAGet(ds, 0x57b0) == 0x00)
        goto loc_12669;
    push(cs);
    cs = 0x1282;
    sub_12def(); // 1282:05cf
    assert(cs == 0x02f1);
    memoryASet(ds, 0x57b0, 0x00);
loc_12669: // 02f1:f759
    if (memoryAGet(ds, 0x59dd) != 0x00)
        goto loc_126d3;
    ax = si;
    if (ax > 0x0011)
        goto loc_126d3;
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 63344)); // 02f1:f76b
    return;
    //   gap of 83 bytes
loc_126d3: // 02f1:f7c3
    push(cs);
    sub_cff3(); // 02f1:a0e3
    push(cs);
    sub_d29a(); // 02f1:a38a
    push(cs);
    sub_d595(); // 02f1:a685
    push(cs);
    sub_f8d2(); // 02f1:c9c2
    push(cs);
    sub_d42a(); // 02f1:a51a
    push(cs);
    sub_f8b7(); // 02f1:c9a7
    push(memoryAGet16(ds, 0x01d2));
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x02f1);
    cx = pop();
    ax = memoryAGet16(ds, 0x01d2);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    memoryASet16(ds, 0x01d2, ax);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22d4(); // 01ed:0404
    assert(cs == 0x02f1);
    cx = pop();
    push(0x0054);
    push(cs);
    sub_110af(); // 02f1:e19f
    cx = pop();
    push(memoryAGet16(ds, 0xa476));
    push(cs);
    cs = 0x1282;
    sub_1482b(); // 1282:200b
    assert(cs == 0x02f1);
    cx = pop();
    if (memoryAGet(ds, 0xa5aa) != 0x00)
        goto loc_12740;
    bx = memoryAGet16(ds, 0x59f4);
    es = memoryAGet16(ds, 0x59f4 + 2);
    bx += 0x1388;
    memoryASet16(ds, 0xa2d2, es);
    memoryASet16(ds, 0xa2d0, bx);
    memoryASet16(ds, 0x01a4, 0x1111);
    push(ds);
    ax = 0x0a59;
    push(ax);
    push(cs);
    sub_f47e(); // 02f1:c56e
    cx = pop();
    cx = pop();
loc_12740: // 02f1:f830
    push(cs);
    cs = 0x1282;
    sub_12de7(); // 1282:05c7
    assert(cs == 0x02f1);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12749() // 02f1:f839
{
    CStackGuardFar sg(0, false);
    memoryASet16(ds, 0x580a, 0x0000);
    memoryASet16(ds, 0x5808, 0x0000);
    memoryASet16(ds, 0x589c, 0x0004);
    memoryASet16(ds, 0x5ae6, 0x0003);
    memoryASet16(ds, 0xa450, 0x0000);
    memoryASet16(ds, 0x589e, 0x0000);
    memoryASet16(ds, 0x5796, 0x0000);
    memoryASet16(ds, 0x5794, 0x0000);
    memoryASet16(ds, 0xa44c, 0x0000);
    memoryASet16(ds, 0x5798, 0x0000);
    memoryASet16(ds, 0xa2c8, 0x0000);
    memoryASet16(ds, 0x57ec, 0x0000);
    memoryASet16(ds, 0x580e, 0x0000);
    cs = pop();
}
void sub_12798() // 02f1:f888
{
    CStackGuard sg(-1, true); // no return
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 6) != 0x0002)
        goto loc_127b2;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx + 4);
    es = memoryAGet16(es, tx + 4 + 2);
    memoryASet16(ds, 0xa47c, es);
    memoryASet16(ds, 0xa47a, bx);
    goto loc_127bc;
loc_127b2: // 02f1:f8a2
    memoryASet16(ds, 0xa47c, ds);
    memoryASet16(ds, 0xa47a, 0x0c03);
loc_127bc: // 02f1:f8ac
    push(cs);
    sub_f58c(); // 02f1:c67c
loc_127c0: // 02f1:f8b0
    push(cs);
    sub_11467(); // 02f1:e557
    memoryASet(ds, 0x59dd, al);
    push(memoryAGet16(ds, 0xa450));
    push(cs);
    sub_12587(); // 02f1:f677
    cx = pop();
    push(ds);
    ax = 0x0c05;
    push(ax);
    push(cs);
    sub_f4bb(); // 02f1:c5ab
    sp = bp;
    if (memoryAGet(ds, 0x59dd) != 0x02)
        goto loc_127e6;
    push(cs);
    sub_11846(); // 02f1:e936
loc_127e6: // 02f1:f8d6
    memoryASet(ds, 0x01a2, 0x01);
    push(memoryAGet16(ds, 0x59dd));
    push(cs);
    sub_11e52(); // 02f1:ef42
    cx = pop();
    memoryASet(ds, 0x01a2, 0x00);
    push(cs);
    cs = 0x1282;
    sub_14897(); // 1282:2077
    assert(cs == 0x02f1);
    if (memoryAGet(ds, 0x59dd) == 0x02)
        goto loc_12811;
    if (memoryAGet(ds, 0x59dd) == 0x01)
        goto loc_12811;
    push(cs);
    cs = 0x1282;
    sub_13b11(); // 1282:12f1
    assert(cs == 0x02f1);
loc_12811: // 02f1:f901
    if (memoryAGet(ds, 0x59dd) != 0x01)
        goto loc_127c0;
    push(cs);
    sub_117eb(); // 02f1:e8db
    goto loc_127c0;
}
void sub_12820() // 1282:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    al = 0x36;
    out(0x43, al);
    al = memoryAGet(ss, bp + 6);
    out(0x40, al);
    ax = memoryAGet16(ss, bp + 6);
    ax >>= 8;
    out(0x40, al);
    ax = memoryAGet16(ss, bp + 6);
    dx = 0;
    memoryASet16(ds, 0xa5cf, dx);
    memoryASet16(ds, 0xa5cd, ax);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12842() // 1282:0022
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    dx = 0;
    push(dx);
    push(ax);
    push(0x0012);
    push(0x305e);
    push(cs);
    cs = 0x01ed;
    sub_2d97(); // 01ed:0ec7
    assert(cs == 0x1282);
    push(ax);
    push(cs);
    sub_12820(); // 1282:0000
    cx = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12882() // 1282:0062
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(di);
    push(cs);
    ax = 0x003e;
    push(ax);
    push(0x0008);
    push(cs);
    cs = 0x1a01;
    sub_1a02d(); // 1a01:001d
    assert(cs == 0x1282);
    sp += 0x0006;
    push(0x03e8);
    push(cs);
    sub_12842(); // 1282:0022
    cx = pop();
    di = 0;
    si = di;
    goto loc_128ce;
loc_128a1: // 1282:0081
    dx = 0;
    cx = 0xffff;
    memoryASet16(ds, 0xa59e, cx);
loc_128aa: // 1282:008a
    sync();
    memoryASet16(ds, 0xa59e, memoryAGet16(ds, 0xa59e) | 0x0000);
    if (memoryAGet16(ds, 0xa59e))
        goto loc_128aa;
loc_128b1: // 1282:0091
    if (memoryAGet16(ds, 0xa59e) & 0x0001)
        goto loc_128bb;
    if (--cx)
        goto loc_128b1;
loc_128bb: // 1282:009b
    ax = 0xffff;
    ax -= memoryAGet16(ds, 0xa58c);
    if (ax <= si)
        goto loc_128cd;
    si = 0xffff;
    si -= memoryAGet16(ds, 0xa58c);
loc_128cd: // 1282:00ad
    di++;
loc_128ce: // 1282:00ae
    if ((short)di < (short)0x000a)
        goto loc_128a1;
    ax = si;
    ax >>= 1;
    si += ax;
    ax = si;
    bx = 0x0064;
    dx = 0;
    div(bx);
    memoryASet16(ds, 0xa56e, ax);
    ax = si;
    bx = 0x0028;
    dx = 0;
    div(bx);
    memoryASet16(ds, 0xa570, ax);
    ax = si;
    bx = 0x000a;
    dx = 0;
    div(bx);
    memoryASet16(ds, 0xa572, ax);
    push(0x0000);
    push(cs);
    sub_12820(); // 1282:0000
    cx = pop();
    push(memoryAGet16(ds, 0xa5c5));
    push(memoryAGet16(ds, 0xa5c3));
    push(0x0008);
    push(cs);
    cs = 0x1a01;
    sub_1a02d(); // 1a01:001d
    assert(cs == 0x1282);
    sp += 0x0006;
    di = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12919() // 1282:00f9
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 6) == 0x0000)
        goto loc_1292f;
    cx = memoryAGet16(ss, bp + 6);
loc_12925: // 1282:0105
    if (memoryAGet16(ds, 0xa59e) & 0x0000)
        goto loc_1292f;
    if (--cx)
        goto loc_12925;
loc_1292f: // 1282:010f
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12931() // 1282:0111
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    dx = 0x0388;
    al = memoryAGet(ss, bp + 6);
    out(dx, al);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    dx = 0x0389;
    al = memoryAGet(ss, bp + 8);
    out(dx, al);
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    dx = 0x0388;
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12a21() // 1282:0201
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(0x0060);
    push(0x0004);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    push(0x0080);
    push(0x0004);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    dx = 0x0388;
    in(al, dx);
    memoryASet(ss, bp - 4, al);
    push(0x00ff);
    push(0x0002);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    push(0x0021);
    push(0x0004);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    push(memoryAGet16(ds, 0xa572));
    push(cs);
    sub_12919(); // 1282:00f9
    cx = pop();
    dx = 0x0388;
    in(al, dx);
    memoryASet(ss, bp - 3, al);
    push(0x0060);
    push(0x0004);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    push(0x0080);
    push(0x0004);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    if (memoryAGet(ss, bp - 4) & 0xe0)
        goto loc_12ac3;
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax &= 0x00e0;
    if (ax != 0x00c0)
        goto loc_12ac3;
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_12aa3;
loc_12a95: // 1282:0275
    push(0x0000);
    push(memoryAGet16(ss, bp - 2));
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_12aa3: // 1282:0283
    if ((short)memoryAGet16(ss, bp - 2) <= (short)0x00f5)
        goto loc_12a95;
    push(0x0020);
    push(0x0001);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    push(0x0000);
    push(0x0008);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    ax = 0x0001;
    goto loc_12ac5;
loc_12ac3: // 1282:02a3
    ax = 0;
loc_12ac5: // 1282:02a5
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_12b5a() // 1282:033a
{
    CStackGuardFar sg(0, false);
    push(si);
    if (memoryAGet16(ds, 0xa58a) != 0x0001)
        goto loc_12b67;
    si = 0x0230;
    goto loc_12b6a;
loc_12b67: // 1282:0347
    si = 0x008c;
loc_12b6a: // 1282:034a
    push(si);
    push(cs);
    sub_12842(); // 1282:0022
    cx = pop();
    si = pop();
    cs = pop();
}
void sub_12b72() // 1282:0352
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(cs);
    cs = 0x1282;
    sub_12d00(); // 1282:04e0
    assert(cs == 0x1282);
    ax = memoryAGet16(ss, bp + 6);
    if (!ax)
        goto loc_12b89;
    if (ax == 0x0001)
        goto loc_12b96;
    goto loc_12ba5;
loc_12b89: // 1282:0369
    memoryASet16(ds, 0xa5a0, 0x0000);
loc_12b8f: // 1282:036f
    memoryASet16(ss, bp - 2, 0x0001);
    goto loc_12baa;
loc_12b96: // 1282:0376
    if (memoryAGet16(ds, 0xa5c7) == 0x0000)
        goto loc_12baa;
    memoryASet16(ds, 0xa5a0, 0x0001);
    goto loc_12b8f;
loc_12ba5: // 1282:0385
    memoryASet16(ss, bp - 2, 0x0000);
loc_12baa: // 1282:038a
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_12bb6;
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0xa58a, ax);
loc_12bb6: // 1282:0396
    push(cs);
    sub_12b5a(); // 1282:033a
    ax = memoryAGet16(ss, bp - 2);
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_12bbf() // 1282:039f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    if (memoryAGet16(ds, 0xa5a2) == 0x0000)
        goto loc_12bc9;
    goto loc_12c3e;
loc_12bc9: // 1282:03a9
    memoryASet16(ds, 0xa5c1, 0x0000);
    memoryASet16(ds, 0xa5a8, 0x0000);
    memoryASet16(ds, 0xa5d5, 0x0000);
    memoryASet16(ds, 0xa5d3, 0x0000);
    push(0x0008);
    push(cs);
    cs = 0x1a01;
    sub_1a01b(); // 1a01:000b
    assert(cs == 0x1282);
    cx = pop();
    memoryASet16(ds, 0xa5c5, dx);
    memoryASet16(ds, 0xa5c3, ax);
    push(cs);
    sub_12882(); // 1282:0062
    push(cs);
    ax = 0x02a7;
    push(ax);
    push(0x0008);
    push(cs);
    cs = 0x1a01;
    sub_1a02d(); // 1a01:001d
    assert(cs == 0x1282);
    sp += 0x0006;
    dx = 0;
    ax = dx;
    memoryASet16(ds, 0xa5cb, dx);
    memoryASet16(ds, 0xa5c9, ax);
    memoryASet16(ds, 0xa5af, dx);
    memoryASet16(ds, 0xa5ad, ax);
    memoryASet16(ds, 0xa588, dx);
    memoryASet16(ds, 0xa586, ax);
    push(0x0000);
    push(cs);
    sub_12b72(); // 1282:0352
    cx = pop();
    if (memoryAGet16(ds, 0xa5a8) != 0x0000)
        goto loc_12c31;
    push(cs);
    sub_12a21(); // 1282:0201
    memoryASet16(ds, 0xa5c7, ax);
loc_12c31: // 1282:0411
    memoryASet16(ds, 0xa5a2, 0x0001);
    push(cs);
    sub_12a21(); // 1282:0201
    memoryASet(ds, 0xa5aa, al);
loc_12c3e: // 1282:041e
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12c3f() // 1282:041f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    if (memoryAGet16(ds, 0xa5a2) == 0x0000)
        goto loc_12c6d;
    push(cs);
    cs = 0x1282;
    sub_12c75(); // 1282:0455
    assert(cs == 0x1282);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    push(0x0000);
    push(cs);
    sub_12820(); // 1282:0000
    cx = pop();
    push(memoryAGet16(ds, 0xa5c5));
    push(memoryAGet16(ds, 0xa5c3));
    push(0x0008);
    push(cs);
    cs = 0x1a01;
    sub_1a02d(); // 1a01:001d
    assert(cs == 0x1282);
    sp += 0x0006;
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    memoryASet16(ds, 0xa5a2, 0x0000);
loc_12c6d: // 1282:044d
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12c6e() // 1282:044e
{
    CStackGuardFar sg(0, false);
    memoryASet16(ds, 0xa59c, 0x0001);
    cs = pop();
}
void sub_12c75() // 1282:0455
{
    CStackGuardFar sg(0, false);
    push(si);
    ax = memoryAGet16(ds, 0xa58a);
    if (ax == 0x0001)
        goto loc_12c80;
    goto loc_12ca8;
loc_12c80: // 1282:0460
    memoryASet16(ds, 0xa574, 0x0000);
    push(0x0000);
    push(0x00bd);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    si = 0;
    goto loc_12ca3;
loc_12c95: // 1282:0475
    push(0x0000);
    ax = si;
    al += 0xb1;
    push(ax);
    push(cs);
    sub_12931(); // 1282:0111
    cx = pop();
    cx = pop();
    si++;
loc_12ca3: // 1282:0483
    if (si < 0x000a)
        goto loc_12c95;
loc_12ca8: // 1282:0488
    memoryASet16(ds, 0xa59c, 0x0000);
    si = pop();
    cs = pop();
}
void sub_12cb0() // 1282:0490
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    sub_12c75(); // 1282:0455
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    if (memoryAGet16(ds, 0xa58a) != 0x0001)
        goto loc_12cfd;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    bx++;
    bx++;
    memoryASet16(ds, 0xa578, es);
    memoryASet16(ds, 0xa576, bx);
    memoryASet16(ds, 0xa5b9, es);
    memoryASet16(ds, 0xa5b7, bx);
    bx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0xa5b5, ax);
    memoryASet16(ds, 0xa5d7, ax);
    memoryASet16(ds, 0xa5b3, 0x0000);
    memoryASet16(ds, 0xa5b1, 0x0000);
    memoryASet16(ds, 0xa5cb, 0x0000);
    memoryASet16(ds, 0xa5c9, 0x0000);
    push(cs);
    sub_12c6e(); // 1282:044e
loc_12cfd: // 1282:04dd
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12d00() // 1282:04e0
{
    CStackGuardFar sg(0, false);
    ax = memoryAGet16(ds, 0xa58a);
    if (ax == 0x0001)
        goto loc_12d0a;
    goto loc_12d0e;
loc_12d0a: // 1282:04ea
    push(cs);
    sub_12c75(); // 1282:0455
loc_12d0e: // 1282:04ee
    cs = pop();
}
void sub_12d0f() // 1282:04ef
{
    sync();
    cs = pop();
    return;
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    memoryASet16(ds, 0xa44e, 0x0000);
loc_12d18: // 1282:04f8
    sync();
    ax = memoryAGet16(ds, 0xa44e);
    if (ax < memoryAGet16(ss, bp + 6))
        goto loc_12d18;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12d22() // 1282:0502
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    memoryASet16(ds, 0xa44e, 0x0000);
    sync();
    sync();
    sync();
    sync();
    sync();
    sync();
    
//loc_12d2b: // 1282:050b
//    ax = memoryAGet16(ds, 0xa44e);
//    if (ax >= memoryAGet16(ss, bp + 6))
//        goto loc_12d39;
//    in(al, 0x60);
//    if (al & 0x80)
//        goto loc_12d2b;
loc_12d39: // 1282:0519
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12d3b() // 1282:051b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = 0;
    si = di;
    goto loc_12d64;
loc_12d46: // 1282:0526
    if (si != 0x0008)
        goto loc_12d4e;
    di = 0x0008;
loc_12d4e: // 1282:052e
    ax = si;
    ax += di;
    push(ax);
    push(si);
    push(cs);
    cs = 0x01ed;
    sub_20c6(); // 01ed:01f6
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    si++;
loc_12d64: // 1282:0544
    if (si < 0x0010)
        goto loc_12d46;
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12d6d() // 1282:054d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = 0;
    goto loc_12d88;
loc_12d75: // 1282:0555
    push(0x0017);
    push(si);
    push(cs);
    cs = 0x01ed;
    sub_20c6(); // 01ed:01f6
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    si++;
loc_12d88: // 1282:0568
    if (si < 0x0010)
        goto loc_12d75;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12d90() // 1282:0570
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    sp = bp;
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    sp = bp;
    ax = memoryAGet16(ss, bp + 8);
    imul(ax, ax, 0x0140);
    ax += memoryAGet16(ss, bp + 6);
    push(ax);
    push(0x3e78);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12dc4() // 1282:05a4
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = 0;
    goto loc_12ddf;
loc_12dcc: // 1282:05ac
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    push(0x0000);
    push(si);
    push(cs);
    cs = 0x01ed;
    sub_20c6(); // 01ed:01f6
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    si++;
loc_12ddf: // 1282:05bf
    if ((short)si < (short)0x0010)
        goto loc_12dcc;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12de7() // 1282:05c7
{
    CStackGuardFar sg(0, false);
    push(0x0003);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    cs = pop();
}
void sub_12def() // 1282:05cf
{
    CStackGuardFar sg(0, false);
    push(0x0003);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    cs = pop();
}
void sub_12df7() // 1282:05d7
{
    sync();
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    memoryASet(ss, bp - 1, 0x00);
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    if (memoryAGet16(ds, 0xa44e) <= 0x0005)
        goto loc_12e2b;
    memoryASet16(ds, 0x0e64, memoryAGet16(ds, 0x0e64) + 0x0008);
    memoryASet16(ds, 0xa44e, 0x0000);
loc_12e2b: // 1282:060b
    if (memoryAGet16(ds, 0x0e64) != 0x0020)
        goto loc_12e38;
    memoryASet16(ds, 0x0e64, 0x0000);
loc_12e38: // 1282:0618
    ax = memoryAGet16(ss, bp + 8);
    imul(ax, ax, 0x0140);
    ax += memoryAGet16(ss, bp + 6);
    push(ax);
    ax = memoryAGet16(ds, 0x0e64);
    ax += 0x3e18;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    al = memoryAGet(ds, 0x59e2);
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_12e5c() // 1282:063c
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 8);
    si = memoryAGet16(ss, bp + 6);
loc_12e68: // 1282:0648
    push(di);
    push(si);
    push(cs);
    sub_12df7(); // 1282:05d7
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (!(memoryAGet(ss, bp - 1) & 0x80))
        goto loc_12e68;
loc_12e79: // 1282:0659
    push(di);
    push(si);
    push(cs);
    sub_12df7(); // 1282:05d7
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) & 0x80)
        goto loc_12e79;
    al = memoryAGet(ds, 0x59e2);
    memoryASet(ss, bp - 1, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    bx = ax;
    memoryASet(ds, bx + 22750, 0x00);
    push(di);
    push(si);
    push(cs);
    sub_12d90(); // 1282:0570
    cx = pop();
    cx = pop();
    al = memoryAGet(ss, bp - 1);
    al &= 0x7f;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_12ead() // 1282:068d
{
    CStackGuardFar sg(0, false);
    push(si);
    push(di);
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    di = 0;
    goto loc_12ee9;
loc_12ecd: // 1282:06ad
    si = 0;
    goto loc_12ee0;
loc_12ed1: // 1282:06b1
    ax = di;
    ax += si;
    push(ax);
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    si++;
loc_12ee0: // 1282:06c0
    if (si < 0x0028)
        goto loc_12ed1;
    di += 0x0140;
loc_12ee9: // 1282:06c9
    if (di < 0x1f40)
        goto loc_12ecd;
    di = pop();
    si = pop();
    cs = pop();
}
void sub_12ef2() // 1282:06d2
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x6;
    push(si);
    push(di);
    if (memoryAGet16(ss, bp + 6) != 0x0001)
        goto loc_12f0a;
    memoryASet16(ss, bp - 4, 0x0001);
    memoryASet16(ss, bp - 2, 0x0002);
    goto loc_12f14;
loc_12f0a: // 1282:06ea
    memoryASet16(ss, bp - 4, 0x0004);
    memoryASet16(ss, bp - 2, 0x0008);
loc_12f14: // 1282:06f4
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, 0x0000);
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(es, bx, 0x0000);
    dx = 0x0201;
    in(al, dx);
    out(dx, al);
loc_12f29: // 1282:0709
    dx = 0x0201;
    in(al, dx);
    ah = 0x00;
    si = ax;
    ax = memoryAGet16(ss, bp - 4);
    if (!(ax & si))
        goto loc_12f3d;
    di = 0x0001;
    goto loc_12f3f;
loc_12f3d: // 1282:071d
    di = 0;
loc_12f3f: // 1282:071f
    ax = memoryAGet16(ss, bp - 2);
    if (!(ax & si))
        goto loc_12f4b;
    ax = 0x0001;
    goto loc_12f4d;
loc_12f4b: // 1282:072b
    ax = 0;
loc_12f4d: // 1282:072d
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + di);
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + ax);
    ax = di;
    ax += memoryAGet16(ss, bp - 6);
    if (ax == 0)
        goto loc_12f77;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if ((short)memoryAGet16(es, bx) >= (short)0x01f4)
        goto loc_12f77;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    if ((short)memoryAGet16(es, bx) < (short)0x01f4)
        goto loc_12f29;
loc_12f77: // 1282:0757
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_12f7b() // 1282:075b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0xe;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 14, 0x0000);
    memoryASet16(ss, bp - 12, 0x0000);
    memoryASet16(ss, bp - 10, 0x0000);
    memoryASet16(ss, bp - 8, 0x0000);
    push(ss);
    ax = bp - 0xc;
    push(ax);
    push(ss);
    ax = bp - 0xe;
    push(ax);
    push(si);
    push(cs);
    sub_12ef2(); // 1282:06d2
    sp += 0x000a;
    if ((short)memoryAGet16(ss, bp - 14) <= (short)0x01f4)
        goto loc_12fb6;
    ax = 0x0001;
    goto loc_12fb8;
loc_12fb6: // 1282:0796
    ax = 0;
loc_12fb8: // 1282:0798
    push(ax);
    if ((short)memoryAGet16(ss, bp - 12) <= (short)0x01f4)
        goto loc_12fc5;
    ax = 0x0001;
    goto loc_12fc7;
loc_12fc5: // 1282:07a5
    ax = 0;
loc_12fc7: // 1282:07a7
    dx = pop();
    dx |= ax;
    if (!dx)
        goto loc_12fe4;
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 42382);
    ax++;
    memoryASet16(ss, bp - 14, ax);
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 42388);
    ax++;
    memoryASet16(ss, bp - 12, ax);
loc_12fe4: // 1282:07c4
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 42362);
    if ((short)ax >= (short)memoryAGet16(ss, bp - 14))
        goto loc_12ff8;
    memoryASet16(ss, bp - 10, 0x0001);
    goto loc_1300a;
loc_12ff8: // 1282:07d8
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 42382);
    if ((short)ax <= (short)memoryAGet16(ss, bp - 14))
        goto loc_1300a;
    memoryASet16(ss, bp - 10, 0xffff);
loc_1300a: // 1282:07ea
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 42368);
    if ((short)ax >= (short)memoryAGet16(ss, bp - 12))
        goto loc_1301e;
    memoryASet16(ss, bp - 8, 0x0001);
    goto loc_13030;
loc_1301e: // 1282:07fe
    bx = si;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 42388);
    if ((short)ax <= (short)memoryAGet16(ss, bp - 12))
        goto loc_13030;
    memoryASet16(ss, bp - 8, 0xffff);
loc_13030: // 1282:0810
    memoryASet(ds, 0xa448, 0x00);
    memoryASet(ds, 0xa462, 0x00);
    memoryASet(ds, 0xa146, 0x00);
    memoryASet(ds, 0xa2cf, 0x00);
    ax = memoryAGet16(ss, bp - 8);
    imul(ax, ax, 0x0003);
    ax += memoryAGet16(ss, bp - 10);
    ax -= 0xfffc;
    if (ax > 0x0008)
        goto loc_130a4;
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 2110)); // 1282:0839
    return;
    //   gap of 70 bytes
loc_130a4: // 1282:0884
    dx = 0x0201;
    in(al, dx);
    ah = 0x00;
    di = ax;
    if (si != 0x0001)
        goto loc_130d7;
    if (di & 0x0010)
        goto loc_130bc;
    ax = 0x0001;
    goto loc_130be;
loc_130bc: // 1282:089c
    ax = 0;
loc_130be: // 1282:089e
    memoryASet16(ss, bp - 4, ax);
    memoryASet(ds, 0xa484, al);
    if (di & 0x0020)
        goto loc_130cf;
    ax = 0x0001;
    goto loc_130d1;
loc_130cf: // 1282:08af
    ax = 0;
loc_130d1: // 1282:08b1
    memoryASet16(ss, bp - 2, ax);
    memoryASet(ds, 0xa485, al);
loc_130d7: // 1282:08b7
    if (memoryAGet16(ds, 0xa5bb) == 0x0000)
        goto loc_130f2;
    di = memoryAGet16(ss, bp - 4);
    ax = memoryAGet16(ss, bp - 2);
    memoryASet16(ss, bp - 4, ax);
    memoryASet(ds, 0xa484, al);
    ax = di;
    memoryASet16(ss, bp - 2, ax);
    memoryASet(ds, 0xa485, al);
loc_130f2: // 1282:08d2
    bx = 0xa486;
    push(ds);
    push(bx);
    bx = bp - 0x6;
    push(ss);
    push(bx);
    cx = 0x0006;
    push(cs);
    cs = 0x01ed;
    sub_2e5f(); // 01ed:0f8f
    assert(cs == 0x1282);
    dx = ds;
    ax = 0xa486;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1310d() // 1282:08ed
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    di = 0x0001;
    goto loc_1315b;
loc_13131: // 1282:0911
    si = 0x0001;
    goto loc_13152;
loc_13136: // 1282:0916
    ax = di;
    ax += memoryAGet16(ss, bp + 8);
    imul(ax, ax, 0x0140);
    dx = si;
    dx += memoryAGet16(ss, bp + 6);
    ax += dx;
    push(ax);
    push(0x3e78);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    si++;
loc_13152: // 1282:0932
    ax = memoryAGet16(ss, bp + 12);
    ax--;
    if ((short)ax > (short)si)
        goto loc_13136;
    di++;
loc_1315b: // 1282:093b
    ax = memoryAGet16(ss, bp + 10);
    ax--;
    if ((short)ax > (short)di)
        goto loc_13131;
    di = 0;
    goto loc_1319c;
loc_13167: // 1282:0947
    ax = di;
    ax += memoryAGet16(ss, bp + 8);
    imul(ax, ax, 0x0140);
    ax += memoryAGet16(ss, bp + 6);
    push(ax);
    push(0x3e68);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    ax = di;
    ax += memoryAGet16(ss, bp + 8);
    imul(ax, ax, 0x0140);
    dx = memoryAGet16(ss, bp + 6);
    dx += memoryAGet16(ss, bp + 12);
    ax += dx;
    ax--;
    push(ax);
    push(0x3e70);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    di++;
loc_1319c: // 1282:097c
    if ((short)di < (short)memoryAGet16(ss, bp + 10))
        goto loc_13167;
    si = 0;
    goto loc_131dc;
loc_131a5: // 1282:0985
    ax = memoryAGet16(ss, bp + 8);
    imul(ax, ax, 0x0140);
    dx = si;
    dx += memoryAGet16(ss, bp + 6);
    ax += dx;
    push(ax);
    push(0x3e58);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp + 10);
    ax--;
    imul(ax, ax, 0x0140);
    dx = si;
    dx += memoryAGet16(ss, bp + 6);
    ax += dx;
    push(ax);
    push(0x3e60);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    si++;
loc_131dc: // 1282:09bc
    if ((short)si < (short)memoryAGet16(ss, bp + 12))
        goto loc_131a5;
    ax = memoryAGet16(ss, bp + 8);
    imul(ax, ax, 0x0140);
    ax += memoryAGet16(ss, bp + 6);
    push(ax);
    push(0x3e38);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    ax = memoryAGet16(ss, bp + 8);
    imul(ax, ax, 0x0140);
    dx = memoryAGet16(ss, bp + 12);
    dx += memoryAGet16(ss, bp + 6);
    ax += dx;
    ax--;
    push(ax);
    push(0x3e40);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp + 10);
    ax--;
    imul(ax, ax, 0x0140);
    ax += memoryAGet16(ss, bp + 6);
    push(ax);
    push(0x3e48);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp + 10);
    ax--;
    imul(ax, ax, 0x0140);
    dx = memoryAGet16(ss, bp + 12);
    dx += memoryAGet16(ss, bp + 6);
    ax += dx;
    ax--;
    push(ax);
    push(0x3e50);
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    if (memoryAGet(ss, bp + 22) == 0x00)
        goto loc_132a6;
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = 0x1889;
    sub_1889e(); // 1889:000e
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    ax >>= 1;
    dx = 0x0014;
    dx -= ax;
    push(dx);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(memoryAGet16(ss, bp + 20));
    push(memoryAGet16(ss, bp + 18));
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp + 10);
    ax += 0xfffe;
    push(ax);
    push(memoryAGet16(ss, bp + 20));
    push(memoryAGet16(ss, bp + 18));
    push(cs);
    cs = 0x1889;
    sub_1889e(); // 1889:000e
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    ax >>= 1;
    dx = 0x0014;
    dx -= ax;
    push(dx);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    goto loc_132db;
loc_132a6: // 1282:0a86
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(memoryAGet16(ss, bp + 20));
    push(memoryAGet16(ss, bp + 18));
    ax = memoryAGet16(ss, bp + 8);
    ax += memoryAGet16(ss, bp + 10);
    ax += 0xfffe;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
loc_132db: // 1282:0abb
    ax = memoryAGet16(ss, bp + 6);
    ax++;
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_132e3() // 1282:0ac3
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x6;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 10);
    ax = sar(ax, 1);
    di = 0x0014;
    di -= ax;
    memoryASet16(ss, bp - 6, 0x0013);
    ax = memoryAGet16(ss, bp + 8);
    ax = sar(ax, 1);
    ax += memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, 0x0001);
    si = memoryAGet16(ss, bp - 6);
    goto loc_13336;
loc_1330d: // 1282:0aed
    push(0x0000);
    push(ds);
    ax = 0x0e79;
    push(ax);
    push(ds);
    ax = 0x0e78;
    push(ax);
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 0x0002);
    ax = memoryAGet16(ss, bp - 2);
    push(ax);
    push(0x0002);
    push(memoryAGet16(ss, bp - 4));
    push(si);
    push(cs);
    sub_1310d(); // 1282:08ed
    sp += 0x0012;
    push(0x0001);
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    si--;
loc_13336: // 1282:0b16
    if ((short)si > (short)di)
        goto loc_1330d;
    memoryASet16(ss, bp - 2, 0x0000);
    si = memoryAGet16(ss, bp - 4);
    goto loc_1336c;
loc_13344: // 1282:0b24
    push(0x0000);
    push(ds);
    ax = 0x0e7b;
    push(ax);
    push(ds);
    ax = 0x0e7a;
    push(ax);
    push(memoryAGet16(ss, bp + 10));
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 0x0002);
    ax = memoryAGet16(ss, bp - 2);
    push(ax);
    push(si);
    push(di);
    push(cs);
    sub_1310d(); // 1282:08ed
    sp += 0x0012;
    push(0x0001);
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    si--;
loc_1336c: // 1282:0b4c
    ax = memoryAGet16(ss, bp + 8);
    ax &= 0x0001;
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    ax += memoryAGet16(ss, bp + 6);
    if ((short)ax < (short)si)
        goto loc_13344;
    push(0x0001);
    push(memoryAGet16(ss, bp + 18));
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(di);
    push(cs);
    sub_1310d(); // 1282:08ed
    sp += 0x0012;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_133a1() // 1282:0b81
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    si = 0;
loc_133a8: // 1282:0b88
    push(memoryAGet16(ss, bp + 8));
    ax = memoryAGet16(ss, bp + 6);
    ax += si;
    ax++;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x1c)
        goto loc_133cb;
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet(es, bx + si, 0x00);
    goto loc_13462;
loc_133cb: // 1282:0bab
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_133db;
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet(es, bx, 0x00);
    goto loc_13462;
loc_133db: // 1282:0bbb
    if (memoryAGet(ss, bp - 1) != 0x0e)
        goto loc_133e8;
    if ((short)si <= 0)
        goto loc_133a8;
    si--;
    goto loc_133a8;
loc_133e8: // 1282:0bc8
    if (si >= memoryAGet16(ss, bp + 14))
        goto loc_133a8;
    if (memoryAGet(ss, bp - 1) < 0x02)
        goto loc_133f9;
    if (memoryAGet(ss, bp - 1) <= 0x0d)
        goto loc_1341d;
loc_133f9: // 1282:0bd9
    if (memoryAGet(ss, bp - 1) < 0x10)
        goto loc_13405;
    if (memoryAGet(ss, bp - 1) <= 0x19)
        goto loc_1341d;
loc_13405: // 1282:0be5
    if (memoryAGet(ss, bp - 1) < 0x1e)
        goto loc_13411;
    if (memoryAGet(ss, bp - 1) <= 0x28)
        goto loc_1341d;
loc_13411: // 1282:0bf1
    if (memoryAGet(ss, bp - 1) < 0x2c)
        goto loc_1344e;
    if (memoryAGet(ss, bp - 1) > 0x35)
        goto loc_1344e;
loc_1341d: // 1282:0bfd
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    imul(ax, ax, 0x0006);
    bx = ax;
    bx += 0x0c44;
    push(ds);
    es = pop();
    al = memoryAGet(es, bx);
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet(es, bx + si, al);
    si++;
    push(memoryAGet16(ss, bp - 1));
    push(memoryAGet16(ss, bp + 8));
    ax = memoryAGet16(ss, bp + 6);
    ax += si;
    push(ax);
    push(cs);
    cs = 0x1282;
    sub_148a4(); // 1282:2084
    assert(cs == 0x1282);
    sp += 0x0006;
    goto loc_133a8;
loc_1344e: // 1282:0c2e
    if (memoryAGet(ss, bp - 1) == 0x39)
        goto loc_13457;
    goto loc_133a8;
loc_13457: // 1282:0c37
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet(es, bx + si, 0x20);
    si++;
    goto loc_133a8;
loc_13462: // 1282:0c42
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_136e6() // 1282:0ec6
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x10;
    push(si);
    push(di);
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(0x000a);
    push(ss);
    ax = bp - 0x10;
    push(ax);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    cs = 0x1869;
    sub_18745(); // 1869:00b5
    assert(cs == 0x1282);
    sp += 0x000a;
    push(ss);
    ax = bp - 0x10;
    push(ax);
    push(cs);
    cs = 0x1889;
    sub_1889e(); // 1889:000e
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    di = ax;
    si = di;
    si--;
    goto loc_13756;
loc_13720: // 1282:0f00
    push(memoryAGet16(ss, bp + 8));
    ax = memoryAGet16(ss, bp + 6);
    ax -= si;
    push(ax);
    bx = di;
    bx -= si;
    ax = bp - 0x11;
    bx += ax;
    al = memoryAGet(ss, bx);
    ah = 0x00;
    ax += 0xffd0;
    imul(ax, ax, 0x0028);
    cx = memoryAGet16(ds, 0x58a2);
    bx = memoryAGet16(ds, 0x58a0);
    bx += ax;
    bx += 0x0410;
    push(cx);
    push(bx);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x1282);
    sp += 0x0008;
    si--;
loc_13756: // 1282:0f36
    if ((short)si >= 0)
        goto loc_13720;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1375e() // 1282:0f3e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    flags.carry = (memoryAGet16(ds, 0x5808) + ax) >= 0x10000;
    memoryASet16(ds, 0x5808, memoryAGet16(ds, 0x5808) + ax);
    memoryASet16(ds, 0x580a, memoryAGet16(ds, 0x580a) + (dx + flags.carry));
    push(memoryAGet16(ds, 0x01d2));
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(memoryAGet16(ds, 0x580a));
    push(memoryAGet16(ds, 0x5808));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp = bp;
    ax = memoryAGet16(ds, 0x01d2);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(memoryAGet16(ds, 0x580a));
    push(memoryAGet16(ds, 0x5808));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp = bp;
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    sp = bp;
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_137cc() // 1282:0fac
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(0x0016);
    push(0x0009);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_1375e(); // 1282:0f3e
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_137e1() // 1282:0fc1
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ds, 0x01d2));
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    ax = memoryAGet16(ds, 0x5794);
    dx = 0;
    push(dx);
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp = bp;
    ax = memoryAGet16(ds, 0x01d2);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    ax = memoryAGet16(ds, 0x5794);
    dx = 0;
    push(dx);
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp = bp;
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    sp = bp;
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1383f() // 1282:101f
{
    CStackGuardFar sg(0, false);
    push(0x0016);
    push(0x0023);
    push(cs);
    sub_137e1(); // 1282:0fc1
    cx = pop();
    cx = pop();
    cs = pop();
}
void sub_1384a() // 1282:102a
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 8);
    si = memoryAGet16(ss, bp + 6);
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(memoryAGet16(ds, 0x01d2));
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(di);
    push(si);
    dx = memoryAGet16(ds, 0x58a2);
    ax = memoryAGet16(ds, 0x58a0);
    ax += 0x0f28;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x1282);
    sp += 0x0008;
    ax = memoryAGet16(ds, 0x589e);
    dx = 0;
    push(dx);
    push(ax);
    push(di);
    push(si);
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp += 0x0008;
    ax = memoryAGet16(ds, 0x01d2);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(di);
    push(si);
    dx = memoryAGet16(ds, 0x58a2);
    ax = memoryAGet16(ds, 0x58a0);
    ax += 0x0f28;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x1282);
    sp += 0x0008;
    ax = memoryAGet16(ds, 0x589e);
    dx = 0;
    push(dx);
    push(ax);
    push(di);
    push(si);
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp += 0x0008;
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_138e4() // 1282:10c4
{
    CStackGuardFar sg(0, false);
    push(0x0017);
    push(0x0018);
    push(cs);
    sub_1384a(); // 1282:102a
    cx = pop();
    cx = pop();
    cs = pop();
}
void sub_138ef() // 1282:10cf
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    si = 0;
    goto loc_13983;
loc_138fc: // 1282:10dc
    if (si < 0x0008)
        goto loc_13904;
    goto loc_13982;
loc_13904: // 1282:10e4
    ax = memoryAGet16(ds, 0x589c);
    ax--;
    if (ax <= si)
        goto loc_13948;
    push(memoryAGet16(ss, bp + 8));
    ax = di;
    ax -= si;
    push(ax);
    dx = memoryAGet16(ds, 0x58a2);
    ax = memoryAGet16(ds, 0x58a0);
    ax += 0x0ed8;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x1282);
    sp += 0x0008;
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    ax = di;
    ax -= si;
    push(ax);
    dx = memoryAGet16(ds, 0x58a2);
    ax = memoryAGet16(ds, 0x58a0);
    ax += 0x0f00;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x1282);
    sp += 0x0008;
    goto loc_13982;
loc_13948: // 1282:1128
    push(memoryAGet16(ss, bp + 8));
    ax = di;
    ax -= si;
    push(ax);
    dx = memoryAGet16(ds, 0x58a2);
    ax = memoryAGet16(ds, 0x58a0);
    ax += 0x0168;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x1282);
    sp += 0x0008;
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    push(ax);
    ax = di;
    ax -= si;
    push(ax);
    dx = memoryAGet16(ds, 0x58a2);
    ax = memoryAGet16(ds, 0x58a0);
    ax += 0x0140;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_22e0(); // 01ed:0410
    assert(cs == 0x1282);
    sp += 0x0008;
loc_13982: // 1282:1162
    si++;
loc_13983: // 1282:1163
    if (si >= memoryAGet16(ds, 0x5ae6))
        goto loc_1398c;
    goto loc_138fc;
loc_1398c: // 1282:116c
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_13990() // 1282:1170
{
    CStackGuardFar sg(0, false);
    push(0x0016);
    push(0x0011);
    push(cs);
    sub_138ef(); // 1282:10cf
    cx = pop();
    cx = pop();
    cs = pop();
}
void sub_1399b() // 1282:117b
{
    CStackGuardFar sg(0, false);
    push(0x0005);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(memoryAGet16(ds, 0x01d2));
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(cs);
    sub_13990(); // 1282:1170
    ax = memoryAGet16(ds, 0x01d2);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(cs);
    sub_13990(); // 1282:1170
    cs = pop();
}
void sub_139c9() // 1282:11a9
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
loc_139cf: // 1282:11af
    push(ds);
    ax = 0x0f4c;
    push(ax);
    push(ds);
    ax = 0x0f3f;
    push(ax);
    push(0x001e);
    push(0x0011);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    di = ax;
    si = 0;
    goto loc_13a5d;
loc_139ec: // 1282:11cc
    ax = si;
    ax++;
    dx = 0;
    push(dx);
    push(ax);
    ax = si;
    ax += 0x0005;
    push(ax);
    ax = di;
    ax++;
    ax++;
    push(ax);
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp += 0x0008;
    push(ds);
    ax = 0x0f63;
    push(ax);
    ax = si;
    ax += 0x0005;
    push(ax);
    ax = di;
    ax += 0x0003;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    bx = si;
    bx <<= 2;
    push(memoryAGet16(ds, bx + 42126));
    push(memoryAGet16(ds, bx + 42124));
    ax = si;
    ax += 0x0005;
    push(ax);
    ax = di;
    ax += 0x000b;
    push(ax);
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp += 0x0008;
    push(ds);
    ax = si;
    ax <<= 4;
    ax += 0xa4b8;
    push(ax);
    ax = si;
    ax += 0x0005;
    push(ax);
    ax = di;
    ax += 0x000d;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    si++;
loc_13a5d: // 1282:123d
    if (si >= 0x000a)
        goto loc_13a64;
    goto loc_139ec;
loc_13a64: // 1282:1244
    push(ds);
    ax = 0x0f65;
    push(ax);
    push(0x0010);
    ax = di;
    ax += 0x0003;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    if (memoryAGet(ds, 0x01a2) != 0x00)
        goto loc_13a84;
    push(cs);
    sub_12de7(); // 1282:05c7
loc_13a84: // 1282:1264
    push(0x0011);
    ax = di;
    ax += 0x001b;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x44)
        goto loc_13a9e;
    goto loc_13b0d;
loc_13a9e: // 1282:127e
    push(ds);
    ax = 0x0f96;
    push(ax);
    push(ds);
    ax = 0x0f7d;
    push(ax);
    push(0x001c);
    push(0x0004);
    push(0x0005);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    di = ax;
    push(0x0007);
    ax = di;
    ax += 0x0016;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x15)
        goto loc_13af8;
    si = 0;
    goto loc_13af3;
loc_13ad2: // 1282:12b2
    bx = si;
    bx <<= 2;
    memoryASet16(ds, bx + 42126, 0x0000);
    memoryASet16(ds, bx + 42124, 0x0000);
    bx = si;
    bx <<= 4;
    bx += 0xa4b8;
    push(ds);
    es = pop();
    memoryASet(es, bx, 0x00);
    si++;
loc_13af3: // 1282:12d3
    if (si < 0x000a)
        goto loc_13ad2;
loc_13af8: // 1282:12d8
    if (memoryAGet(ds, 0x01a2) == 0x00)
        goto loc_13b02;
    goto loc_139cf;
loc_13b02: // 1282:12e2
    push(cs);
    sub_12def(); // 1282:05cf
    push(cs);
    sub_12ead(); // 1282:068d
    goto loc_139cf;
loc_13b0d: // 1282:12ed
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_13b11() // 1282:12f1
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
    push(cs);
    sub_12def(); // 1282:05cf
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_22d4(); // 01ed:0404
    assert(cs == 0x1282);
    cx = pop();
    push(cs);
    sub_12ead(); // 1282:068d
    si = 0;
    goto loc_13c11;
loc_13b34: // 1282:1314
    bx = si;
    bx <<= 2;
    dx = memoryAGet16(ds, bx + 42126);
    ax = memoryAGet16(ds, bx + 42124);
    if (dx <= memoryAGet16(ds, 0x580a))
        goto loc_13b4a;
    goto loc_13c10;
loc_13b4a: // 1282:132a
    if (dx < memoryAGet16(ds, 0x580a))
        goto loc_13b55;
    if (ax < memoryAGet16(ds, 0x5808))
        goto loc_13b55;
    goto loc_13c10;
loc_13b55: // 1282:1335
    di = 0x000a;
    goto loc_13b93;
loc_13b5a: // 1282:133a
    bx = di;
    bx--;
    bx <<= 2;
    dx = memoryAGet16(ds, bx + 42126);
    ax = memoryAGet16(ds, bx + 42124);
    bx = di;
    bx <<= 2;
    memoryASet16(ds, bx + 42126, dx);
    memoryASet16(ds, bx + 42124, ax);
    push(ds);
    ax = di;
    ax--;
    ax <<= 4;
    ax += 0xa4b8;
    push(ax);
    push(ds);
    ax = di;
    ax <<= 4;
    ax += 0xa4b8;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    di--;
loc_13b93: // 1282:1373
    if ((short)di > (short)si)
        goto loc_13b5a;
    bx = si;
    bx <<= 4;
    bx += 0xa4b8;
    push(ds);
    es = pop();
    memoryASet(es, bx, 0x00);
    dx = memoryAGet16(ds, 0x580a);
    ax = memoryAGet16(ds, 0x5808);
    bx = si;
    bx <<= 2;
    memoryASet16(ds, bx + 42126, dx);
    memoryASet16(ds, bx + 42124, ax);
    push(ds);
    ax = 0x0fcc;
    push(ax);
    push(ds);
    ax = 0x0fa9;
    push(ax);
    push(0x0024);
    push(0x0007);
    push(0x0005);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    memoryASet16(ss, bp - 2, ax);
    push(ds);
    ax = 0x0fdf;
    push(ax);
    push(0x0008);
    push(memoryAGet16(ss, bp - 2));
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(cs);
    sub_12de7(); // 1282:05c7
    push(0x0034);
    push(cs);
    cs = 0x02f1;
    sub_3448(); // 02f1:0538
    assert(cs == 0x1282);
    cx = pop();
    push(0x000e);
    push(ds);
    ax = si;
    ax <<= 4;
    ax += 0xa4b8;
    push(ax);
    push(0x0008);
    ax = memoryAGet16(ss, bp - 2);
    ax += 0x0010;
    push(ax);
    push(cs);
    sub_133a1(); // 1282:0b81
    sp += 0x000a;
    goto loc_13c19;
loc_13c10: // 1282:13f0
    si++;
loc_13c11: // 1282:13f1
    if ((short)si >= (short)0x000a)
        goto loc_13c19;
    goto loc_13b34;
loc_13c19: // 1282:13f9
    push(cs);
    sub_12def(); // 1282:05cf
    push(cs);
    sub_12ead(); // 1282:068d
    push(0x0033);
    push(cs);
    cs = 0x02f1;
    sub_3448(); // 02f1:0538
    assert(cs == 0x1282);
    cx = pop();
    push(cs);
    sub_139c9(); // 1282:11a9
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_13c31() // 1282:1411
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x404;
    push(si);
    push(di);
    si = 0;
    goto loc_13c45;
loc_13c3b: // 1282:141b
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, bx + si);
    memoryASet(ss, bp + si + 65508, al);
    si++;
loc_13c45: // 1282:1425
    if ((short)si < (short)0x0013)
        goto loc_13c3b;
    memoryASet(ss, bp - 9, 0x00);
    push(ss);
    ax = bp - 0x1c;
    push(ax);
    push(cs);
    cs = 0x1a77;
    sub_1a773(); // 1a77:0003
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x0ff0;
    push(ax);
    push(memoryAGet16(ds, 0x01da));
    push(memoryAGet16(ds, 0x01d8));
    push(cs);
    cs = 0x1760;
    sub_1781b(); // 1760:021b
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    di = 0;
    push(dx);
    push(ax);
    push(0x03c0);
    push(0x0001);
    push(ss);
    ax = bp - 0x404;
    push(ax);
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x1282);
    sp += 0x000c;
    si = 0;
    goto loc_13cc4;
loc_13c90: // 1282:1470
    if (memoryAGet(ss, bp + si + 64508) == 0x00)
        goto loc_13cca;
    push(0x000b);
    push(ss);
    ax = bp - 0x1c;
    push(ax);
    push(ss);
    ax = bp - 0x404;
    ax += si;
    push(ax);
    push(cs);
    cs = 0x1a73;
    sub_1a739(); // 1a73:0009
    assert(cs == 0x1282);
    sp += 0x000a;
    if (ax)
        goto loc_13cc1;
    ax = si;
    ax += 0x000c;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    di = 0x0001;
loc_13cc1: // 1282:14a1
    si += 0x0014;
loc_13cc4: // 1282:14a4
    if ((short)si < (short)0x03d4)
        goto loc_13c90;
loc_13cca: // 1282:14aa
    if (!di)
        goto loc_13cd1;
    goto loc_13d91;
loc_13cd1: // 1282:14b1
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x0ff3;
    push(ax);
    push(memoryAGet16(ds, 0x01de));
    push(memoryAGet16(ds, 0x01dc));
    push(cs);
    cs = 0x1760;
    sub_1781b(); // 1760:021b
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    push(dx);
    push(ax);
    push(0x03c0);
    push(0x0001);
    push(ss);
    ax = bp - 0x404;
    push(ax);
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x1282);
    sp += 0x000c;
    si = 0;
    goto loc_13d46;
loc_13d12: // 1282:14f2
    if (memoryAGet(ss, bp + si + 64508) == 0x00)
        goto loc_13d4c;
    push(0x000b);
    push(ss);
    ax = bp - 0x1c;
    push(ax);
    push(ss);
    ax = bp - 0x404;
    ax += si;
    push(ax);
    push(cs);
    cs = 0x1a73;
    sub_1a739(); // 1a73:0009
    assert(cs == 0x1282);
    sp += 0x000a;
    if (ax)
        goto loc_13d43;
    ax = si;
    ax += 0x000c;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    di = 0x0001;
loc_13d43: // 1282:1523
    si += 0x0014;
loc_13d46: // 1282:1526
    if ((short)si < (short)0x03d4)
        goto loc_13d12;
loc_13d4c: // 1282:152c
    if (di)
        goto loc_13d91;
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x0ff6;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1760;
    sub_1781b(); // 1760:021b
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx + 4);
    ah = 0x00;
    si = ax;
    push(si);
    push(cs);
    cs = 0x1965;
    sub_19659(); // 1965:0009
    assert(cs == 0x1282);
    cx = pop();
    memoryASet16(ds, 0xa460, dx);
    memoryASet16(ds, 0xa45e, ax);
    goto loc_13deb;
loc_13d91: // 1282:1571
    push(0x0000);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x17ab;
    sub_17b09(); // 17ab:0059
    assert(cs == 0x1282);
    sp += 0x000a;
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(0x0001);
    push(0x0004);
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x1282);
    sp += 0x000c;
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(0x0001);
    push(0x0004);
    push(ds);
    ax = 0xa45e;
    push(ax);
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x1282);
    sp += 0x000c;
    push(0x0000);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x17ab;
    sub_17b09(); // 17ab:0059
    assert(cs == 0x1282);
    sp += 0x000a;
loc_13deb: // 1282:15cb
    dx = memoryAGet16(ss, bp - 6);
    ax = memoryAGet16(ss, bp - 8);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_13df5() // 1282:15d5
{
    CStackGuardFar sg(0, false);
    ax = memoryAGet16(ds, 0xa5c7);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    cs = pop();
}
void sub_13dfe() // 1282:15de
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x8;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    memoryASet16(ds, 0x01a4, 0xffff);
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 2;
    push(memoryAGet16(ds, bx + 730));
    push(memoryAGet16(ds, bx + 728));
    push(cs);
    sub_13c31(); // 1282:1411
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    push(dx);
    push(ax);
    ax = memoryAGet16(ds, 0xa45e);
    ax++;
    ax++;
    push(ax);
    push(0x0001);
    dx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    ax++;
    ax++;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1817;
    sub_18283(); // 1817:0113
    assert(cs == 0x1282);
    sp += 0x000c;
    ax = memoryAGet16(ds, 0xa45e);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx, ax);
    push(0x0001);
    push(cs);
    sub_12b72(); // 1282:0352
    cx = pop();
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_13e6e() // 1282:164e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(cs);
    sub_12def(); // 1282:05cf
    push(cs);
    sub_12ead(); // 1282:068d
    push(ds);
    ax = 0x100e;
    push(ax);
    push(ds);
    ax = 0x0ff9;
    push(ax);
    push(0x0026);
    push(0x0018);
    push(0x0000);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x101d;
    push(ax);
    push(0x0002);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x104c;
    push(ax);
    push(0x0004);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x106b;
    push(ax);
    push(0x0005);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x108d;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x10ad;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x10d1;
    push(ax);
    push(0x0009);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x10f3;
    push(ax);
    push(0x000a);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1114;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1131;
    push(ax);
    push(0x000d);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1154;
    push(ax);
    push(0x000e);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1176;
    push(ax);
    push(0x000f);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1198;
    push(ax);
    push(0x0010);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x11b9;
    push(ax);
    push(0x0012);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x11da;
    push(ax);
    push(0x0013);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x11f8;
    push(ax);
    push(0x0016);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    push(0x0016);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(0x0001);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    push(cs);
    sub_12ead(); // 1282:068d
    push(ds);
    ax = 0x123c;
    push(ax);
    push(ds);
    ax = 0x1227;
    push(ax);
    push(0x0026);
    push(0x0016);
    push(0x0001);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x124b;
    push(ax);
    push(0x0004);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1269;
    push(ax);
    push(0x0006);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x128c;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x12ac;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x12cb;
    push(ax);
    push(0x0009);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x12e9;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1309;
    push(ax);
    push(0x000c);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1323;
    push(ax);
    push(0x000d);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1344;
    push(ax);
    push(0x000f);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1366;
    push(ax);
    push(0x0010);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1387;
    push(ax);
    push(0x0013);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x139d;
    push(ax);
    push(0x0014);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    push(0x0015);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(0x0001);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    push(cs);
    sub_12ead(); // 1282:068d
    push(ds);
    ax = 0x13d7;
    push(ax);
    push(ds);
    ax = 0x13c2;
    push(ax);
    push(0x0026);
    push(0x0016);
    push(0x0001);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x13e6;
    push(ax);
    push(0x0004);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1406;
    push(ax);
    push(0x0005);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1421;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1441;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1460;
    push(ax);
    push(0x000a);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x147b;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1496;
    push(ax);
    push(0x000c);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x14b6;
    push(ax);
    push(0x000e);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x14e4;
    push(ax);
    push(0x000f);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x14fe;
    push(ax);
    push(0x0012);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x151a;
    push(ax);
    push(0x0013);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1534;
    push(ax);
    push(0x0014);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    push(0x0015);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(0x0001);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    push(cs);
    sub_12ead(); // 1282:068d
    push(ds);
    ax = 0x1578;
    push(ax);
    push(ds);
    ax = 0x1559;
    push(ax);
    push(0x0026);
    push(0x000f);
    push(0x0004);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x1587;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x15aa;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x15cb;
    push(ax);
    push(0x0009);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x15ea;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x160c;
    push(ax);
    push(0x000c);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x162d;
    push(ax);
    push(0x000d);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x164e;
    push(ax);
    push(0x000f);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    push(0x0011);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(0x0001);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    push(cs);
    sub_12ead(); // 1282:068d
    push(ds);
    ax = 0x1684;
    push(ax);
    push(ds);
    ax = 0x166e;
    push(ax);
    push(0x0026);
    push(0x0014);
    push(0x0001);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    si++;
    si++;
    push(ds);
    ax = 0x1693;
    push(ax);
    push(0x0004);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x16b3;
    push(ax);
    push(0x0005);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x16d1;
    push(ax);
    push(0x0006);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x16f0;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x170e;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x172e;
    push(ax);
    push(0x000a);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x174e;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x176e;
    push(ax);
    push(0x000d);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x178c;
    push(ax);
    push(0x000e);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x17a8;
    push(ax);
    push(0x000f);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x17c7;
    push(ax);
    push(0x0011);
    ax = si;
    ax += 0xfffe;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    push(0x0013);
    ax = si;
    ax += 0x0021;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1482b() // 1282:200b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    sub_13df5(); // 1282:15d5
    if (al)
        goto loc_14861;
    dx = memoryAGet16(ds, 0x59f6);
    ax = memoryAGet16(ds, 0x59f4);
    ax += 0x1388;
    push(dx);
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_13dfe(); // 1282:15de
    sp = bp;
    memoryASet16(ds, 0x57f0, dx);
    memoryASet16(ds, 0x57ee, ax);
    if (memoryAGet16(ds, 0xa14e) == 0x0000)
        goto loc_14861;
    push(dx);
    push(ax);
    push(cs);
    sub_12cb0(); // 1282:0490
    sp = bp;
loc_14861: // 1282:2041
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_14863() // 1282:2043
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    sub_13df5(); // 1282:15d5
    if (al)
        goto loc_14895;
    push(memoryAGet16(ds, 0x58ac));
    push(memoryAGet16(ds, 0x58aa));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_13dfe(); // 1282:15de
    sp = bp;
    memoryASet16(ds, 0x57f0, dx);
    memoryASet16(ds, 0x57ee, ax);
    if (memoryAGet16(ds, 0xa14e) == 0x0000)
        goto loc_14895;
    push(dx);
    push(ax);
    push(cs);
    sub_12cb0(); // 1282:0490
    sp = bp;
loc_14895: // 1282:2075
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_14897() // 1282:2077
{
    CStackGuardFar sg(0, false);
    push(cs);
    sub_13df5(); // 1282:15d5
    if (al)
        goto loc_148a3;
    push(cs);
    sub_12c75(); // 1282:0455
loc_148a3: // 1282:2083
    cs = pop();
}
void sub_148a4() // 1282:2084
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x2;
    al = memoryAGet(ss, bp + 10);
    ah = 0x00;
    imul(ax, ax, 0x0006);
    bx = ax;
    bx += 0x0c44;
    push(ds);
    es = pop();
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 2, al);
    memoryASet(ss, bp - 1, 0x00);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_14b63() // 1282:2343
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x6;
    push(si);
    push(di);
    memoryASet16(ss, bp - 6, 0x0000);
    memoryASet16(ss, bp - 4, 0x0000);
    si = 0;
    goto loc_14ba2;
loc_14b77: // 1282:2357
    di = 0;
    goto loc_14b98;
loc_14b7b: // 1282:235b
    ax = memoryAGet16(ss, bp - 4);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    dx = memoryAGet16(ss, bp - 6);
    bx = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    bx += dx;
    memoryASet(es, bx, al);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
    di++;
loc_14b98: // 1282:2378
    if (di < 0x0010)
        goto loc_14b7b;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0010);
    si++;
loc_14ba2: // 1282:2382
    if (si < 0x0028)
        goto loc_14b77;
    memoryASet16(ss, bp - 2, 0x0000);
    goto loc_14c46;
loc_14baf: // 1282:238f
    memoryASet16(ss, bp - 4, 0x0000);
    si = 0;
    goto loc_14bf3;
loc_14bb8: // 1282:2398
    di = 0;
    goto loc_14be9;
loc_14bbc: // 1282:239c
    ax = memoryAGet16(ss, bp - 2);
    imul(ax, ax, 0x0500);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    bx += ax;
    ax = memoryAGet16(ss, bp - 4);
    bx += ax;
    al = memoryAGet(es, bx + 16);
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += memoryAGet16(ss, bp - 4);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    imul(ax, ax, 0x0500);
    bx += ax;
    ax = pop();
    memoryASet(es, bx, al);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    di++;
loc_14be9: // 1282:23c9
    if (di < 0x0010)
        goto loc_14bbc;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0010);
    si++;
loc_14bf3: // 1282:23d3
    if (si < 0x0028)
        goto loc_14bb8;
    memoryASet16(ss, bp - 4, 0x0000);
    si = 0;
    goto loc_14c3e;
loc_14c01: // 1282:23e1
    di = 0;
    goto loc_14c34;
loc_14c05: // 1282:23e5
    ax = memoryAGet16(ss, bp - 2);
    imul(ax, ax, 0x0500);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    bx += ax;
    ax = memoryAGet16(ss, bp - 4);
    bx += ax;
    al = memoryAGet(es, bx + 1280);
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += memoryAGet16(ss, bp - 4);
    push(ax);
    ax = memoryAGet16(ss, bp - 2);
    imul(ax, ax, 0x0500);
    bx += ax;
    ax = pop();
    memoryASet(es, bx + 16, al);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    di++;
loc_14c34: // 1282:2414
    if (di < 0x0010)
        goto loc_14c05;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0010);
    si++;
loc_14c3e: // 1282:241e
    if (si < 0x0028)
        goto loc_14c01;
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 1);
loc_14c46: // 1282:2426
    if (memoryAGet16(ss, bp - 2) >= 0x0012)
        goto loc_14c4f;
    goto loc_14baf;
loc_14c4f: // 1282:242f
    memoryASet16(ss, bp - 4, 0x0000);
    memoryASet16(ss, bp - 6, 0x0000);
    si = 0;
    goto loc_14c8a;
loc_14c5d: // 1282:243d
    di = 0;
    goto loc_14c80;
loc_14c61: // 1282:2441
    ax = memoryAGet16(ss, bp - 6);
    bx = memoryAGet16(ss, bp + 14);
    es = memoryAGet16(ss, bp + 14 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    dx = memoryAGet16(ss, bp - 4);
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += dx;
    memoryASet(es, bx + 21776, al);
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    di++;
loc_14c80: // 1282:2460
    if (di < 0x0010)
        goto loc_14c61;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0010);
    si++;
loc_14c8a: // 1282:246a
    if (si < 0x0028)
        goto loc_14c5d;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_14c93() // 1282:2473
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x8;
    push(si);
    push(di);
    si = 0;
    goto loc_14da0;
loc_14c9e: // 1282:247e
    memoryASet16(ss, bp - 6, 0x0000);
    goto loc_14d93;
loc_14ca6: // 1282:2486
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_14cc8;
loc_14cad: // 1282:248d
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    bx += memoryAGet16(ss, bp - 8);
    bx += memoryAGet16(ss, bp - 6);
    al = memoryAGet(es, bx + si);
    al >>= 4;
    bx = bp - 0x4;
    bx += memoryAGet16(ss, bp - 8);
    memoryASet(ss, bx, al);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_14cc8: // 1282:24a8
    if (memoryAGet16(ss, bp - 8) < 0x0004)
        goto loc_14cad;
    di = 0;
    goto loc_14d4d;
loc_14cd3: // 1282:24b3
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_14cfc;
loc_14cda: // 1282:24ba
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    bx += di;
    bx += memoryAGet16(ss, bp - 8);
    bx += memoryAGet16(ss, bp - 6);
    al = memoryAGet(es, bx + si);
    al <<= 4;
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += di;
    bx += memoryAGet16(ss, bp - 8);
    bx += memoryAGet16(ss, bp - 6);
    memoryASet(es, bx + si, al);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_14cfc: // 1282:24dc
    if (memoryAGet16(ss, bp - 8) < 0x0004)
        goto loc_14cda;
    if (di == 0x04e0)
        goto loc_14d4a;
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_14d44;
loc_14d0f: // 1282:24ef
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += memoryAGet16(ss, bp - 8);
    bx += memoryAGet16(ss, bp - 6);
    bx += si;
    al = memoryAGet(es, bx + di);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    bx += memoryAGet16(ss, bp - 8);
    bx += memoryAGet16(ss, bp - 6);
    bx += si;
    bx += di;
    dl = memoryAGet(es, bx + 32);
    dl >>= 4;
    al |= dl;
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += di;
    bx += memoryAGet16(ss, bp - 8);
    bx += memoryAGet16(ss, bp - 6);
    memoryASet(es, bx + si, al);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_14d44: // 1282:2524
    if (memoryAGet16(ss, bp - 8) < 0x0004)
        goto loc_14d0f;
loc_14d4a: // 1282:252a
    di += 0x0020;
loc_14d4d: // 1282:252d
    if (di >= 0x0500)
        goto loc_14d56;
    goto loc_14cd3;
loc_14d56: // 1282:2536
    memoryASet16(ss, bp - 8, 0x0000);
    goto loc_14d89;
loc_14d5d: // 1282:253d
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    bx += memoryAGet16(ss, bp - 8);
    bx += si;
    bx += memoryAGet16(ss, bp - 6);
    al = memoryAGet(es, bx + 1248);
    bx = bp - 0x4;
    bx += memoryAGet16(ss, bp - 8);
    al |= memoryAGet(ss, bx);
    bx = memoryAGet16(ss, bp + 10);
    bx += memoryAGet16(ss, bp - 8);
    bx += si;
    bx += memoryAGet16(ss, bp - 6);
    memoryASet(es, bx + 1248, al);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + 1);
loc_14d89: // 1282:2569
    if (memoryAGet16(ss, bp - 8) < 0x0004)
        goto loc_14d5d;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 0x0004);
loc_14d93: // 1282:2573
    if (memoryAGet16(ss, bp - 6) >= 0x0020)
        goto loc_14d9c;
    goto loc_14ca6;
loc_14d9c: // 1282:257c
    si += 0x0500;
loc_14da0: // 1282:2580
    if (si >= 0x5a00)
        goto loc_14da9;
    goto loc_14c9e;
loc_14da9: // 1282:2589
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_14dad() // 1282:258d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 6);
    di--;
    push(ds);
    ax = 0x1c83;
    push(ax);
    push(ds);
    ax = 0x1c76;
    push(ax);
    push(0x0026);
    push(0x0012);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x1c92;
    push(ax);
    ax = di;
    ax += 0x0004;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1cb5;
    push(ax);
    ax = di;
    ax += 0x0005;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1cd7;
    push(ax);
    ax = di;
    ax += 0x0006;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1cef;
    push(ax);
    ax = di;
    ax += 0x0008;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1d13;
    push(ax);
    ax = di;
    ax += 0x0009;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1d37;
    push(ax);
    ax = di;
    ax += 0x000a;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1d57;
    push(ax);
    ax = di;
    ax += 0x000b;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1d7b;
    push(ax);
    ax = di;
    ax += 0x000d;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1d9f;
    push(ax);
    ax = di;
    ax += 0x000e;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1dc3;
    push(ax);
    ax = di;
    ax += 0x000f;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1de1;
    push(ax);
    ax = di;
    ax += 0x0010;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    ax = di;
    ax += 0x0011;
    push(ax);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x1e18;
    push(ax);
    push(ds);
    ax = 0x1e02;
    push(ax);
    push(0x0026);
    push(0x0012);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x1e19;
    push(ax);
    ax = di;
    ax += 0x0004;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1e33;
    push(ax);
    ax = di;
    ax += 0x0005;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1e4c;
    push(ax);
    ax = di;
    ax += 0x0007;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1e6f;
    push(ax);
    ax = di;
    ax += 0x0008;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1e93;
    push(ax);
    ax = di;
    ax += 0x0009;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1ea0;
    push(ax);
    ax = di;
    ax += 0x000a;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1eba;
    push(ax);
    ax = di;
    ax += 0x000b;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1ed4;
    push(ax);
    ax = di;
    ax += 0x000c;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1eee;
    push(ax);
    ax = di;
    ax += 0x000d;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1f16;
    push(ax);
    ax = di;
    ax += 0x000e;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1f31;
    push(ax);
    ax = di;
    ax += 0x0011;
    push(ax);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    al = memoryAGet(ds, 0x6134);
    ah = 0x00;
    imul(ax, ax, 0x0006);
    ax += 0x0c44;
    push(ax);
    ax = di;
    ax += 0x0007;
    push(ax);
    ax = si;
    ax += 0x0018;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    al = memoryAGet(ds, 0xa2c2);
    ah = 0x00;
    imul(ax, ax, 0x0006);
    ax += 0x0c44;
    push(ax);
    ax = di;
    ax += 0x000e;
    push(ax);
    ax = si;
    ax += 0x0018;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    al = memoryAGet(ds, 0xa2ce);
    ah = 0x00;
    imul(ax, ax, 0x0006);
    ax += 0x0c44;
    push(ax);
    ax = di;
    ax += 0x000e;
    push(ax);
    ax = si;
    ax += 0x000e;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    al = memoryAGet(ds, 0xa45c);
    ah = 0x00;
    imul(ax, ax, 0x0006);
    ax += 0x0c44;
    push(ax);
    ax = di;
    ax += 0x000e;
    push(ax);
    ax = si;
    ax += 0x001e;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    al = memoryAGet(ds, 0xa47e);
    ah = 0x00;
    imul(ax, ax, 0x0006);
    ax += 0x0c44;
    push(ax);
    ax = di;
    ax += 0x000f;
    push(ax);
    ax = si;
    ax++;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    al = memoryAGet(ds, 0xa47f);
    ah = 0x00;
    imul(ax, ax, 0x0006);
    ax += 0x0c44;
    push(ax);
    ax = di;
    ax += 0x000f;
    push(ax);
    ax = si;
    ax += 0x0008;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    ax = di;
    ax += 0x0011;
    push(ax);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x1f67;
    push(ax);
    push(ds);
    ax = 0x1f4b;
    push(ax);
    push(0x0022);
    push(0x000b);
    push(0x0004);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x1f76;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1f8f;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1fb0;
    push(ax);
    push(0x0009);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1fcb;
    push(ax);
    push(0x000a);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x1fe6;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x000d);
    ax = si;
    ax += 0x001f;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_15106() // 1282:28e6
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(cs);
    sub_12def(); // 1282:05cf
    push(cs);
    sub_12ead(); // 1282:068d
loc_15113: // 1282:28f3
    push(0x0001);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    push(ds);
    ax = 0x201e;
    push(ax);
    push(ds);
    ax = 0x1fff;
    push(ax);
    push(0x0026);
    push(0x0018);
    push(0x0000);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x2041;
    push(ax);
    push(0x0004);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2052;
    push(ax);
    push(0x0006);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2076;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2096;
    push(ax);
    push(0x000a);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x20a0;
    push(ax);
    push(0x000d);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x20c4;
    push(ax);
    push(0x000f);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x20e6;
    push(ax);
    push(0x0011);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2109;
    push(ax);
    push(0x0013);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
loc_151ba: // 1282:299a
    push(0x0016);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x49)
        goto loc_151ba;
    if (memoryAGet(ss, bp - 1) == 0x48)
        goto loc_151ba;
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_151e0;
    goto loc_15518;
loc_151e0: // 1282:29c0
    push(0x0001);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    push(ds);
    ax = 0x2136;
    push(ax);
    push(ds);
    ax = 0x2117;
    push(ax);
    push(0x0026);
    push(0x0018);
    push(0x0000);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x2158;
    push(ax);
    push(0x0004);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x217b;
    push(ax);
    push(0x0006);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x219c;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x21ad;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x21cf;
    push(ax);
    push(0x000d);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x21ef;
    push(ax);
    push(0x000f);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x220a;
    push(ax);
    push(0x0014);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    push(0x0016);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_15291;
    goto loc_15518;
loc_15291: // 1282:2a71
    if (memoryAGet(ss, bp - 1) != 0x48)
        goto loc_1529a;
    goto loc_15113;
loc_1529a: // 1282:2a7a
    if (memoryAGet(ss, bp - 1) != 0x49)
        goto loc_152a3;
    goto loc_15113;
loc_152a3: // 1282:2a83
    push(0x0001);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    push(ds);
    ax = 0x2255;
    push(ax);
    push(ds);
    ax = 0x2234;
    push(ax);
    push(0x0026);
    push(0x0018);
    push(0x0000);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x2277;
    push(ax);
    push(0x0004);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2296;
    push(ax);
    push(0x0006);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x22b7;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x22d4;
    push(ax);
    push(0x000a);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x22e8;
    push(ax);
    push(0x000d);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x230c;
    push(ax);
    push(0x0012);
    ax = si;
    ax += 0x0005;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2314;
    push(ax);
    push(0x0014);
    ax = si;
    ax += 0x0005;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2330;
    push(ax);
    push(0x0014);
    ax = si;
    ax += 0x0005;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    push(0x0016);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_15373;
    goto loc_15518;
loc_15373: // 1282:2b53
    if (memoryAGet(ss, bp - 1) != 0x48)
        goto loc_1537c;
    goto loc_151e0;
loc_1537c: // 1282:2b5c
    if (memoryAGet(ss, bp - 1) != 0x49)
        goto loc_15385;
    goto loc_151e0;
loc_15385: // 1282:2b65
    push(0x0001);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    push(ds);
    ax = 0x237b;
    push(ax);
    push(ds);
    ax = 0x235b;
    push(ax);
    push(0x0026);
    push(0x0018);
    push(0x0000);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x239d;
    push(ax);
    push(0x0005);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x23c0;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x23de;
    push(ax);
    push(0x0009);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x23fe;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2418;
    push(ax);
    push(0x0012);
    ax = si;
    ax += 0x0004;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2436;
    push(ax);
    push(0x0013);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    push(0x0016);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_1542b;
    goto loc_15518;
loc_1542b: // 1282:2c0b
    if (memoryAGet(ss, bp - 1) != 0x48)
        goto loc_15434;
    goto loc_152a3;
loc_15434: // 1282:2c14
    if (memoryAGet(ss, bp - 1) != 0x49)
        goto loc_1543d;
    goto loc_152a3;
loc_1543d: // 1282:2c1d
    push(0x0001);
    push(cs);
    sub_12dc4(); // 1282:05a4
    cx = pop();
    push(ds);
    ax = 0x2476;
    push(ax);
    push(ds);
    ax = 0x2456;
    push(ax);
    push(0x0026);
    push(0x0018);
    push(0x0000);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x2490;
    push(ax);
    push(0x0005);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x24b3;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x24d5;
    push(ax);
    push(0x0009);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x24f7;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x251a;
    push(ax);
    push(0x000d);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2538;
    push(ax);
    push(0x000f);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x254c;
    push(ax);
    push(0x0012);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2565;
    push(ax);
    push(0x0014);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0001);
    push(cs);
    sub_12d3b(); // 1282:051b
    cx = pop();
    push(0x0016);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x01)
        goto loc_15518;
    if (memoryAGet(ss, bp - 1) != 0x48)
        goto loc_15504;
    goto loc_15385;
loc_15504: // 1282:2ce4
    if (memoryAGet(ss, bp - 1) != 0x49)
        goto loc_1550d;
    goto loc_15385;
loc_1550d: // 1282:2ced
    push(cs);
    sub_12ead(); // 1282:068d
    push(0x0003);
    push(cs);
    sub_14dad(); // 1282:258d
    cx = pop();
loc_15518: // 1282:2cf8
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_15bc2() // 1282:33a2
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(ds);
    ax = 0x2f6d;
    push(ax);
    push(ds);
    ax = 0x2f5d;
    push(ax);
    push(0x0014);
    push(0x0004);
    push(0x0005);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(0x0007);
    ax = si;
    ax += 0x0011;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_15bec() // 1282:33cc
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(ds);
    ax = 0x2f89;
    push(ax);
    push(ds);
    ax = 0x2f7f;
    push(ax);
    push(0x001a);
    push(0x000d);
    push(0x0004);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x2f9c;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2fb1;
    push(ax);
    push(0x0009);
    ax = si;
    ax += 0x000b;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2fb5;
    push(ax);
    push(0x000b);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x2fd3;
    push(ax);
    push(0x000d);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x02bc);
    push(cs);
    sub_12d22(); // 1282:0502
    cx = pop();
    push(cs);
    sub_12def(); // 1282:05cf
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_15c59() // 1282:3439
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(ds);
    ax = 0x2ffb;
    push(ax);
    push(ds);
    ax = 0x2fe6;
    push(ax);
    push(0x001c);
    push(0x0004);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(0x0004);
    ax = si;
    ax += 0x0019;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_15d6e() // 1282:354e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(ds);
    ax = 0x30df;
    push(ax);
    push(ds);
    ax = 0x30ce;
    push(ax);
    push(0x0012);
    push(0x0004);
    push(0x000b);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(0x000d);
    ax = si;
    ax += 0x000e;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x15)
        goto loc_15da7;
    al = 0x01;
    goto loc_15da9;
loc_15da7: // 1282:3587
    al = 0x00;
loc_15da9: // 1282:3589
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_15dac() // 1282:358c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    ax = memoryAGet16(ds, 0xa150);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    memoryASet16(ds, 0xa150, ax);
    if (!ax)
        goto loc_15dd7;
    push(ds);
    ax = 0x30fb;
    push(ax);
    push(ds);
    ax = 0x30ee;
    push(ax);
    push(0x0018);
    push(0x0004);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    goto loc_15df0;
loc_15dd7: // 1282:35b7
    push(ds);
    ax = 0x311d;
    push(ax);
    push(ds);
    ax = 0x3110;
    push(ax);
    push(0x0018);
    push(0x0004);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
loc_15df0: // 1282:35d0
    push(0x0004);
    ax = si;
    ax += 0x0015;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_15e00() // 1282:35e0
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(cs);
    sub_13df5(); // 1282:15d5
    if (!al)
        goto loc_15e0c;
    goto loc_15e73;
loc_15e0c: // 1282:35ec
    ax = memoryAGet16(ds, 0xa14e);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    memoryASet16(ds, 0xa14e, ax);
    if (!ax)
        goto loc_15e48;
    push(ds);
    ax = 0x3140;
    push(ax);
    push(ds);
    ax = 0x3133;
    push(ax);
    push(0x0018);
    push(0x0004);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(memoryAGet16(ds, 0x57f0));
    push(memoryAGet16(ds, 0x57ee));
    push(cs);
    sub_12cb0(); // 1282:0490
    cx = pop();
    cx = pop();
    push(cs);
    sub_12c6e(); // 1282:044e
    goto loc_15e65;
loc_15e48: // 1282:3628
    push(ds);
    ax = 0x3162;
    push(ax);
    push(ds);
    ax = 0x3155;
    push(ax);
    push(0x0018);
    push(0x0004);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(cs);
    sub_12c75(); // 1282:0455
loc_15e65: // 1282:3645
    push(0x0004);
    ax = si;
    ax += 0x0015;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
loc_15e73: // 1282:3653
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_15f66() // 1282:3746
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(ds);
    ax = 0x31e2;
    push(ax);
    push(ds);
    ax = 0x31d5;
    push(ax);
    push(0x0012);
    push(0x0004);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(cs);
    sub_12c75(); // 1282:0455
    push(0x0004);
    ax = si;
    ax += 0x000f;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    if (memoryAGet16(ds, 0xa14e) == 0x0000)
        goto loc_15fab;
    push(memoryAGet16(ds, 0x57f0));
    push(memoryAGet16(ds, 0x57ee));
    push(cs);
    sub_12cb0(); // 1282:0490
    cx = pop();
    cx = pop();
    push(cs);
    sub_12c6e(); // 1282:044e
loc_15fab: // 1282:378b
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_15fad() // 1282:378d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    ax = memoryAGet16(ds, 0x01d4);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    memoryASet16(ds, 0x01d4, ax);
    if (!ax)
        goto loc_15fd8;
    push(ds);
    ax = 0x31fc;
    push(ax);
    push(ds);
    ax = 0x31f1;
    push(ax);
    push(0x001c);
    push(0x0004);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    goto loc_15ff1;
loc_15fd8: // 1282:37b8
    push(ds);
    ax = 0x321f;
    push(ax);
    push(ds);
    ax = 0x3214;
    push(ax);
    push(0x001c);
    push(0x0004);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
loc_15ff1: // 1282:37d1
    push(0x0004);
    ax = si;
    ax += 0x0019;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_16001() // 1282:37e1
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(ds);
    ax = 0x3249;
    push(ax);
    push(ds);
    ax = 0x3238;
    push(ax);
    push(0x001e);
    push(0x0008);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x3258;
    push(ax);
    push(0x0004);
    ax = si;
    ax += 0x0006;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3265;
    push(ax);
    push(0x0005);
    ax = si;
    ax += 0x000a;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x326e;
    push(ax);
    push(0x0006);
    ax = si;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3287;
    push(ax);
    push(0x0007);
    ax = si;
    ax += 0x0005;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(memoryAGet16(ds, 0xa454));
    push(memoryAGet16(ds, 0xa452));
    push(0x0004);
    ax = si;
    ax += 0x0018;
    push(ax);
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp += 0x0008;
    push(memoryAGet16(ds, 0xa2d6));
    push(memoryAGet16(ds, 0xa2d4));
    push(0x0005);
    ax = si;
    ax += 0x0018;
    push(ax);
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp += 0x0008;
    ax = memoryAGet16(ds, 0x579a);
    dx = 0;
    push(dx);
    push(ax);
    push(0x0007);
    ax = si;
    ax += 0x0018;
    push(ax);
    push(cs);
    sub_136e6(); // 1282:0ec6
    sp += 0x0008;
    push(0x0008);
    ax = si;
    ax += 0x001b;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_16190() // 1282:3970
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x6;
    push(si);
    push(ds);
    ax = 0x3309;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1760;
    sub_1781b(); // 1760:021b
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 6, ax);
    ax |= dx;
    if (!ax)
        goto loc_161b5;
    goto loc_162f0;
loc_161b5: // 1282:3995
    memoryASet(ds, 0x6134, 0x48);
    memoryASet(ds, 0xa2c2, 0x50);
    memoryASet(ds, 0xa2ce, 0x4b);
    memoryASet(ds, 0xa45c, 0x4d);
    memoryASet(ds, 0xa47e, 0x1d);
    memoryASet(ds, 0xa47f, 0x38);
    memoryASet16(ds, 0xa14e, 0x0001);
    memoryASet16(ds, 0xa150, 0x0001);
    memoryASet16(ds, 0xa48e, 0x000f);
    memoryASet16(ds, 0xa48c, 0x4240);
    push(ds);
    ax = 0x330c;
    push(ax);
    push(ds);
    ax = 0xa4b8;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ds, 0xa492, 0x000d);
    memoryASet16(ds, 0xa490, 0xbba0);
    push(ds);
    ax = 0x3311;
    push(ax);
    push(ds);
    ax = 0xa4c8;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ds, 0xa496, 0x000c);
    memoryASet16(ds, 0xa494, 0x3500);
    push(ds);
    ax = 0x3316;
    push(ax);
    push(ds);
    ax = 0xa4d8;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ds, 0xa49a, 0x000a);
    memoryASet16(ds, 0xa498, 0xae60);
    push(ds);
    ax = 0x331c;
    push(ax);
    push(ds);
    ax = 0xa4e8;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ds, 0xa49e, 0x0009);
    memoryASet16(ds, 0xa49c, 0x27c0);
    push(ds);
    ax = 0x3322;
    push(ax);
    push(ds);
    ax = 0xa4f8;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ds, 0xa4a2, 0x0007);
    memoryASet16(ds, 0xa4a0, 0xa120);
    push(ds);
    ax = 0x332b;
    push(ax);
    push(ds);
    ax = 0xa508;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ds, 0xa4a6, 0x0006);
    memoryASet16(ds, 0xa4a4, 0x1a80);
    push(ds);
    ax = 0x3335;
    push(ax);
    push(ds);
    ax = 0xa518;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ds, 0xa4aa, 0x0004);
    memoryASet16(ds, 0xa4a8, 0x93e0);
    push(ds);
    ax = 0x333c;
    push(ax);
    push(ds);
    ax = 0xa528;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ds, 0xa4ae, 0x0003);
    memoryASet16(ds, 0xa4ac, 0x0d40);
    push(ds);
    ax = 0x3343;
    push(ax);
    push(ds);
    ax = 0xa538;
    push(ax);
    push(cs);
    cs = 0x188b;
    sub_188b9(); // 188b:0009
    assert(cs == 0x1282);
    sp += 0x0008;
    goto loc_163dd;
loc_162f0: // 1282:3ad0
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x17c0;
    sub_17cf4(); // 17c0:00f4
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    memoryASet(ds, 0x6134, al);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x17c0;
    sub_17cf4(); // 17c0:00f4
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    memoryASet(ds, 0xa2c2, al);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x17c0;
    sub_17cf4(); // 17c0:00f4
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    memoryASet(ds, 0xa2ce, al);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x17c0;
    sub_17cf4(); // 17c0:00f4
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    memoryASet(ds, 0xa45c, al);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x17c0;
    sub_17cf4(); // 17c0:00f4
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    memoryASet(ds, 0xa47e, al);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x17c0;
    sub_17cf4(); // 17c0:00f4
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    memoryASet(ds, 0xa47f, al);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x17c0;
    sub_17cf4(); // 17c0:00f4
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0xa14e, ax);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x17c0;
    sub_17cf4(); // 17c0:00f4
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0xa150, ax);
    si = 0;
    goto loc_163cb;
loc_16374: // 1282:3b54
    ax = si;
    ax <<= 2;
    bx = 0xa48c;
    cx = ds;
    bx += ax;
    push(cx);
    push(bx);
    push(ds);
    ax = 0x3349;
    push(ax);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x196c;
    sub_196c3(); // 196c:0003
    assert(cs == 0x1282);
    sp += 0x000c;
    push(ss);
    ax = bp - 0x1;
    push(ax);
    push(ds);
    ax = 0x334d;
    push(ax);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x196c;
    sub_196c3(); // 196c:0003
    assert(cs == 0x1282);
    sp += 0x000c;
    push(ds);
    ax = si;
    ax <<= 4;
    ax += 0xa4b8;
    push(ax);
    push(ds);
    ax = 0x3350;
    push(ax);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x196c;
    sub_196c3(); // 196c:0003
    assert(cs == 0x1282);
    sp += 0x000c;
    si++;
loc_163cb: // 1282:3bab
    if ((short)si < (short)0x000a)
        goto loc_16374;
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
loc_163dd: // 1282:3bbd
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_163e0() // 1282:3bc0
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x4;
    push(si);
    push(ds);
    ax = 0x3357;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1760;
    sub_1781b(); // 1760:021b
    assert(cs == 0x1282);
    sp += 0x0008;
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    push(dx);
    push(ax);
    al = memoryAGet(ds, 0x6134);
    ah = 0x00;
    push(ax);
    push(cs);
    cs = 0x18af;
    sub_18b12(); // 18af:0022
    assert(cs == 0x1282);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    al = memoryAGet(ds, 0xa2c2);
    ah = 0x00;
    push(ax);
    push(cs);
    cs = 0x18af;
    sub_18b12(); // 18af:0022
    assert(cs == 0x1282);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    al = memoryAGet(ds, 0xa2ce);
    ah = 0x00;
    push(ax);
    push(cs);
    cs = 0x18af;
    sub_18b12(); // 18af:0022
    assert(cs == 0x1282);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    al = memoryAGet(ds, 0xa45c);
    ah = 0x00;
    push(ax);
    push(cs);
    cs = 0x18af;
    sub_18b12(); // 18af:0022
    assert(cs == 0x1282);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    al = memoryAGet(ds, 0xa47e);
    ah = 0x00;
    push(ax);
    push(cs);
    cs = 0x18af;
    sub_18b12(); // 18af:0022
    assert(cs == 0x1282);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    al = memoryAGet(ds, 0xa47f);
    ah = 0x00;
    push(ax);
    push(cs);
    cs = 0x18af;
    sub_18b12(); // 18af:0022
    assert(cs == 0x1282);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0xa14e));
    push(cs);
    cs = 0x18af;
    sub_18b12(); // 18af:0022
    assert(cs == 0x1282);
    sp += 0x0006;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0xa150));
    push(cs);
    cs = 0x18af;
    sub_18b12(); // 18af:0022
    assert(cs == 0x1282);
    sp += 0x0006;
    si = 0;
    goto loc_164eb;
loc_1649a: // 1282:3c7a
    bx = si;
    bx <<= 2;
    push(memoryAGet16(ds, bx + 42126));
    push(memoryAGet16(ds, bx + 42124));
    push(ds);
    ax = 0x335a;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1969;
    sub_1969e(); // 1969:000e
    assert(cs == 0x1282);
    sp += 0x000c;
    push(ds);
    ax = 0x335e;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1969;
    sub_1969e(); // 1969:000e
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = si;
    ax <<= 4;
    ax += 0xa4b8;
    push(ax);
    push(ds);
    ax = 0x3360;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1969;
    sub_1969e(); // 1969:000e
    assert(cs == 0x1282);
    sp += 0x000c;
    si++;
loc_164eb: // 1282:3ccb
    if ((short)si < (short)0x000a)
        goto loc_1649a;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_16500() // 1282:3ce0
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(0x0000);
    push(cs);
    cs = 0x01ed;
    sub_22d4(); // 01ed:0404
    assert(cs == 0x1282);
    cx = pop();
    push(0x0005);
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    push(cs);
    sub_12def(); // 1282:05cf
    push(0x0004);
    push(cs);
    cs = 0x02f1;
    sub_32c6(); // 02f1:03b6
    assert(cs == 0x1282);
    cx = pop();
    push(0x0018);
    push(0x0027);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(0x0004);
    push(cs);
    sub_12d6d(); // 1282:054d
    cx = pop();
    push(cs);
    sub_12ead(); // 1282:068d
    push(ds);
    ax = 0x3365;
    push(ax);
    push(ds);
    ax = 0x3364;
    push(ax);
    push(0x0026);
    push(0x0018);
    push(0x0001);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x3374;
    push(ax);
    push(0x000d);
    ax = si;
    ax += 0x0004;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3379;
    push(ax);
    push(0x0016);
    ax = si;
    ax += 0x001c;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(cs);
    sub_12de7(); // 1282:05c7
    push(ds);
    ax = 0x337e;
    push(ax);
    push(0x0004);
    ax = si;
    ax += 0x000e;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3396;
    push(ax);
    push(0x0005);
    ax = si;
    ax += 0x000e;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x33ac;
    push(ax);
    push(0x0006);
    ax = si;
    ax += 0x000e;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x33c2;
    push(ax);
    push(0x0008);
    ax = si;
    ax += 0x000e;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x33dc;
    push(ax);
    push(0x0009);
    ax = si;
    ax += 0x000e;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x33f5;
    push(ax);
    push(0x000a);
    ax = si;
    ax += 0x000e;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x340e;
    push(ax);
    push(0x000b);
    ax = si;
    ax += 0x000e;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x342a;
    push(ax);
    push(0x000f);
    ax = si;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3441;
    push(ax);
    push(0x0010);
    ax = si;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x345e;
    push(ax);
    push(0x0011);
    ax = si;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x347b;
    push(ax);
    push(0x0012);
    ax = si;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3496;
    push(ax);
    push(0x0013);
    ax = si;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x34bb;
    push(ax);
    push(0x0015);
    ax = si;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x0017);
    ax = si;
    ax += 0x0023;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(cs);
    sub_12def(); // 1282:05cf
    push(cs);
    sub_12ead(); // 1282:068d
    push(ds);
    ax = 0x34e3;
    push(ax);
    push(ds);
    ax = 0x34d9;
    push(ax);
    push(0x0018);
    push(0x0004);
    push(0x0006);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(cs);
    sub_12de7(); // 1282:05c7
    push(0x0064);
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    push(0x0008);
    ax = si;
    ax += 0x0015;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(cs);
    sub_13e6e(); // 1282:164e
    push(cs);
    cs = 0x02f1;
    sub_11aea(); // 02f1:ebda
    assert(cs == 0x1282);
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_16b30() // 1282:4310
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(ds);
    ax = 0x39fa;
    push(ax);
    push(ds);
    ax = 0x39e4;
    push(ax);
    push(0x0020);
    push(0x0009);
    push(0x0003);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x3a09;
    push(ax);
    push(0x0006);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3a26;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3a44;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x000a);
    ax = si;
    ax += 0x001d;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_16cfb() // 1282:44db
{
    CStackGuardFar sg(0, false);
    push(bp);
    bp = sp;
    sp -= 0x2;
    push(si);
    push(di);
    memoryASet16(ss, bp - 2, 0x4000);
    push(cs);
    sub_12ead(); // 1282:068d
    di = 0x0013;
    goto loc_16d32;
loc_16d0f: // 1282:44ef
    si = 0x0001;
    goto loc_16d2c;
loc_16d14: // 1282:44f4
    ax = di;
    imul(ax, ax, 0x0140);
    ax += si;
    push(ax);
    push(memoryAGet16(ss, bp - 2));
    push(cs);
    cs = 0x01ed;
    sub_20d6(); // 01ed:0206
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, memoryAGet16(ss, bp - 2) + 0x0008);
    si++;
loc_16d2c: // 1282:450c
    if (si < 0x0027)
        goto loc_16d14;
    di++;
loc_16d32: // 1282:4512
    if (di < 0x0019)
        goto loc_16d0f;
    push(0x0000);
    push(0x0000);
    push(cs);
    sub_137cc(); // 1282:0fac
    cx = pop();
    cx = pop();
    push(cs);
    sub_1383f(); // 1282:101f
    push(cs);
    sub_138e4(); // 1282:10c4
    push(cs);
    sub_1399b(); // 1282:117b
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    cs = pop();
}
void sub_16d51() // 1282:4531
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    push(ds);
    ax = 0x3a61;
    push(ax);
    push(ds);
    ax = 0x3a57;
    push(ax);
    push(0x0014);
    push(0x0015);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x3a62;
    push(ax);
    push(0x0005);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3a73;
    push(ax);
    push(0x0006);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3a84;
    push(ax);
    push(0x0007);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3a8c;
    push(ax);
    push(0x0008);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3a9b;
    push(ax);
    push(0x0009);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3aa9;
    push(ax);
    push(0x000a);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3ab9;
    push(ax);
    push(0x000c);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3aca;
    push(ax);
    push(0x000e);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3adb;
    push(ax);
    push(0x000f);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3aea;
    push(ax);
    push(0x0010);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3af1;
    push(ax);
    push(0x0011);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3afb;
    push(ax);
    push(0x0012);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3b0a;
    push(ax);
    push(0x0014);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_16e3d() // 1282:461d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    if (memoryAGet(ds, 0x59dd) == 0x00)
        goto loc_16e48;
    goto loc_16ed7;
loc_16e48: // 1282:4628
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(memoryAGet16(ds, 0x01d2));
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(0x001e);
    push(cs);
    cs = 0x02f1;
    sub_3448(); // 02f1:0538
    assert(cs == 0x1282);
    cx = pop();
    push(ds);
    ax = 0x3b17;
    push(ax);
    push(ds);
    ax = 0x3b16;
    push(ax);
    push(0x001c);
    push(0x0004);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x3b18;
    push(ax);
    push(0x0003);
    ax = si;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3b2e;
    push(ax);
    push(0x0004);
    ax = si;
    ax++;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x003c);
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    push(0x0004);
    ax = si;
    ax += 0x0019;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    ax = memoryAGet16(ds, 0x01d2);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
loc_16ed7: // 1282:46b7
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_16ed9() // 1282:46b9
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(si);
    if (memoryAGet(ds, 0x59dd) == 0x00)
        goto loc_16ee4;
    goto loc_16fb5;
loc_16ee4: // 1282:46c4
    push(0x0f02);
    push(0x03c4);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(0x0105);
    push(0x03ce);
    push(cs);
    cs = 0x1a2c;
    sub_1a2cc(); // 1a2c:000c
    assert(cs == 0x1282);
    cx = pop();
    cx = pop();
    push(memoryAGet16(ds, 0x01d2));
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
    push(0x001e);
    push(cs);
    cs = 0x02f1;
    sub_3448(); // 02f1:0538
    assert(cs == 0x1282);
    cx = pop();
    push(ds);
    ax = 0x3b5f;
    push(ax);
    push(ds);
    ax = 0x3b4c;
    push(ax);
    push(0x0016);
    push(0x0005);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x3b72;
    push(ax);
    push(0x0004);
    push(si);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x003c);
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    push(0x0005);
    ax = si;
    ax += 0x0013;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    push(ds);
    ax = 0x3b94;
    push(ax);
    push(ds);
    ax = 0x3b87;
    push(ax);
    push(0x0014);
    push(0x000d);
    push(0x0002);
    push(cs);
    sub_132e3(); // 1282:0ac3
    sp += 0x000e;
    si = ax;
    push(ds);
    ax = 0x3ba3;
    push(ax);
    push(0x0009);
    ax = si;
    ax += 0x0005;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(ds);
    ax = 0x3bab;
    push(ax);
    push(0x000b);
    ax = si;
    ax += 0x0005;
    push(ax);
    push(cs);
    cs = 0x02f1;
    sub_3088(); // 02f1:0178
    assert(cs == 0x1282);
    sp += 0x0008;
    push(0x003c);
    push(cs);
    sub_12d0f(); // 1282:04ef
    cx = pop();
    push(0x000d);
    ax = si;
    ax += 0x0011;
    push(ax);
    push(cs);
    sub_12e5c(); // 1282:063c
    cx = pop();
    cx = pop();
    ax = memoryAGet16(ds, 0x01d2);
    flags.carry = ax != 0;
    ax = -ax;
    ax -= ax + flags.carry;
    ax++;
    push(ax);
    push(cs);
    cs = 0x01ed;
    sub_2146(); // 01ed:0276
    assert(cs == 0x1282);
    cx = pop();
loc_16fb5: // 1282:4795
    si = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_170e3() // 170e:0003
{
    CStackGuardFar sg(2, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 6);
    if ((short)si < 0)
        goto loc_17102;
    if (si <= 0x0058)
        goto loc_170f6;
loc_170f3: // 170e:0013
    si = 0x0057;
loc_170f6: // 170e:0016
    memoryASet16(ds, 0x3c10, si);
    al = memoryAGet(ds, si + 15378);
    cbw();
    tx = si;
    si = ax;
    ax = tx;
    goto loc_1710f;
loc_17102: // 170e:0022
    si = -si;
    if (si > 0x0023)
        goto loc_170f3;
    memoryASet16(ds, 0x3c10, 0xffff);
loc_1710f: // 170e:002f
    ax = si;
    memoryASet16(ds, 0x007f, ax);
    ax = 0xffff;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 2;
}
void sub_1711f() // 1711:000f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    goto loc_17130;
loc_17124: // 1711:0014
    bx = memoryAGet16(ds, 0x3c7a);
    bx <<= 1;
    bx <<= 1;
    push(cs);
    cs = memoryAGet16(ds, bx + 42458 + 2);
    callIndirect(memoryAGet16(ds, bx + 42458 + 2), memoryAGet16(ds, bx + 42458));
    assert(cs == 0x1711);
loc_17130: // 1711:0020
    ax = memoryAGet16(ds, 0x3c7a);
    memoryASet16(ds, 0x3c7a, memoryAGet16(ds, 0x3c7a) - 1);
    if (ax)
        goto loc_17124;
    push(cs);
    cs = memoryAGet16(ds, 0x3c6c + 2);
    callIndirect(memoryAGet16(ds, 0x3c6c + 2), memoryAGet16(ds, 0x3c6c));
    assert(cs == 0x1711);
    push(cs);
    cs = memoryAGet16(ds, 0x3c70 + 2);
    callIndirect(memoryAGet16(ds, 0x3c70 + 2), memoryAGet16(ds, 0x3c70));
    assert(cs == 0x1711);
    push(cs);
    cs = memoryAGet16(ds, 0x3c74 + 2);
    callIndirect(memoryAGet16(ds, 0x3c74 + 2), memoryAGet16(ds, 0x3c74));
    assert(cs == 0x1711);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x01ed;
    sub_1fdd(); // 01ed:010d
    assert(cs == 0x1711);
    cx = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17181() // 1718:0001
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    dx = 0;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1718;
    sub_17382(); // 1718:0202
    assert(cs == 0x1718);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17196() // 1718:0016
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = memoryAGet16(es, bx + 14);
    ax = memoryAGet16(es, bx + 12);
    memoryASet16(ds, 0x3c86, dx);
    memoryASet16(ds, 0x3c84, ax);
    cx = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1718);
    if (!flags.zero)
        goto loc_171c9;
    memoryASet16(ds, 0x3c86, 0x0000);
    memoryASet16(ds, 0x3c84, 0x0000);
    goto loc_171fa;
loc_171c9: // 1718:0049
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx + 8);
    es = memoryAGet16(es, tx + 8 + 2);
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    bx = memoryAGet16(ds, 0x3c84);
    es = memoryAGet16(ds, 0x3c84 + 2);
    memoryASet16(es, bx + 10, dx);
    memoryASet16(es, bx + 8, ax);
    dx = memoryAGet16(ds, 0x3c86);
    ax = memoryAGet16(ds, 0x3c84);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
loc_171fa: // 1718:007a
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_171fe() // 1718:007e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    flags.carry = memoryAGet16(es, bx) < ax;
    memoryASet16(es, bx, memoryAGet16(es, bx) - ax);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) - (dx + flags.carry));
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    cx = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(es, bx);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    push(cs);
    cs = 0x01ed;
    sub_2bad(); // 01ed:0cdd
    assert(cs == 0x1718);
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx, ax);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 4, ax);
    cx = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ds, 0x3c82);
    ax = memoryAGet16(ds, 0x3c80);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1718);
    if (!flags.zero)
        goto loc_17277;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(ds, 0x3c82, es);
    memoryASet16(ds, 0x3c80, bx);
    goto loc_1729f;
loc_17277: // 1718:00f7
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    cx = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 10);
    push(cs);
    cs = 0x01ed;
    sub_2bad(); // 01ed:0cdd
    assert(cs == 0x1718);
    memoryASet16(ss, bp + 8, dx);
    memoryASet16(ss, bp + 6, ax);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 4, ax);
loc_1729f: // 1718:011f
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0008;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_172ae() // 1718:012e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1749;
    sub_17568(); // 1749:00d8
    assert(cs == 0x1718);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    if (memoryAGet16(ss, bp - 2) != 0xffff)
        goto loc_172d9;
    if (memoryAGet16(ss, bp - 4) != 0xffff)
        goto loc_172d9;
    dx = 0;
    ax = 0;
    goto loc_17318;
loc_172d9: // 1718:0159
    dx = memoryAGet16(ds, 0x3c82);
    ax = memoryAGet16(ds, 0x3c80);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 4, ax);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx, ax);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(ds, 0x3c82, es);
    memoryASet16(ds, 0x3c80, bx);
    dx = memoryAGet16(ds, 0x3c82);
    ax = memoryAGet16(ds, 0x3c80);
    ax += 0x0008;
loc_17318: // 1718:0198
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1731c() // 1718:019c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1749;
    sub_17568(); // 1749:00d8
    assert(cs == 0x1718);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    if (memoryAGet16(ss, bp - 2) != 0xffff)
        goto loc_17347;
    if (memoryAGet16(ss, bp - 4) != 0xffff)
        goto loc_17347;
    dx = 0;
    ax = 0;
    goto loc_1737e;
loc_17347: // 1718:01c7
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(ds, 0x3c7e, es);
    memoryASet16(ds, 0x3c7c, bx);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(ds, 0x3c82, es);
    memoryASet16(ds, 0x3c80, bx);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx, ax);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0008;
loc_1737e: // 1718:01fe
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17382() // 1718:0202
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    ax = memoryAGet16(ss, bp + 6);
    ax |= memoryAGet16(ss, bp + 8);
    if (ax)
        goto loc_17397;
    dx = 0;
    ax = 0;
    goto loc_1748d;
loc_17397: // 1718:0217
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    flags.carry = (ax + 0x0017) >= 0x10000;
    ax += 0x0017;
    dx += flags.carry;
    ax &= 0xfff0;
    dx &= 0xffff;
    memoryASet16(ss, bp + 8, dx);
    memoryASet16(ss, bp + 6, ax);
    cx = 0;
    bx = 0;
    dx = memoryAGet16(ds, 0x3c7e);
    ax = memoryAGet16(ds, 0x3c7c);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1718);
    if (!flags.zero)
        goto loc_173d1;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_1731c(); // 1718:019c
    cx = pop();
    cx = pop();
    goto loc_1748d;
loc_173d1: // 1718:0251
    dx = memoryAGet16(ds, 0x3c86);
    ax = memoryAGet16(ds, 0x3c84);
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    cx = 0;
    bx = 0;
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1718);
    if (!flags.zero)
        goto loc_173ec;
    goto loc_1747f;
loc_173ec: // 1718:026c
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    dx = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(es, bx);
    cx = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    flags.carry = (bx + 0x0030) >= 0x10000;
    bx += 0x0030;
    cx += flags.carry;
    if (dx < cx)
        goto loc_17421;
    if (dx != cx)
        goto loc_1740c;
    if (ax < bx)
        goto loc_17421;
loc_1740c: // 1718:028c
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    sub_171fe(); // 1718:007e
    sp += 0x0008;
    goto loc_1748d;
loc_17421: // 1718:02a1
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    dx = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(es, bx);
    if (dx < memoryAGet16(ss, bp + 8))
        goto loc_1745a;
    if (dx != memoryAGet16(ss, bp + 8))
        goto loc_17437;
    if (ax < memoryAGet16(ss, bp + 6))
        goto loc_1745a;
loc_17437: // 1718:02b7
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    sub_17196(); // 1718:0016
    cx = pop();
    cx = pop();
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    flags.carry = (memoryAGet16(es, bx) + 0x0001) >= 0x10000;
    memoryASet16(es, bx, memoryAGet16(es, bx) + 0x0001);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + flags.carry);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    ax += 0x0008;
    goto loc_1748d;
loc_1745a: // 1718:02da
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    cx = memoryAGet16(ds, 0x3c86);
    bx = memoryAGet16(ds, 0x3c84);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1718);
    if (flags.zero)
        goto loc_1747f;
    goto loc_173ec;
loc_1747f: // 1718:02ff
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_172ae(); // 1718:012e
    cx = pop();
    cx = pop();
loc_1748d: // 1718:030d
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17491() // 1749:0001
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 6);
    si++;
    si -= memoryAGet16(ds, 0x007b);
    ax = si;
    ax += 0x003f;
    cl = 0x06;
    ax >>= cl;
    si = ax;
    if (si != memoryAGet16(ds, 0x3c88))
        goto loc_174bf;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(ds, 0x008d, es);
    memoryASet16(ds, 0x008b, bx);
    ax = 0x0001;
    goto loc_1751b;
loc_174bf: // 1749:002f
    cl = 0x06;
    si <<= cl;
    di = memoryAGet16(ds, 0x0091);
    ax = si;
    ax += memoryAGet16(ds, 0x007b);
    if (ax <= di)
        goto loc_174d7;
    si = di;
    si -= memoryAGet16(ds, 0x007b);
loc_174d7: // 1749:0047
    push(si);
    push(memoryAGet16(ds, 0x007b));
    push(cs);
    cs = 0x175e;
    sub_175e3(); // 175e:0003
    assert(cs == 0x1749);
    cx = pop();
    cx = pop();
    di = ax;
    if (di != 0xffff)
        goto loc_17505;
    ax = si;
    cl = 0x06;
    ax >>= cl;
    memoryASet16(ds, 0x3c88, ax);
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(ds, 0x008d, es);
    memoryASet16(ds, 0x008b, bx);
    ax = 0x0001;
    goto loc_1751b;
    //   gap of 2 bytes
loc_17505: // 1749:0075
    ax = memoryAGet16(ds, 0x007b);
    ax += di;
    dx = 0;
    dx = ax;
    ax = 0;
    memoryASet16(ds, 0x0091, dx);
    memoryASet16(ds, 0x008f, ax);
    ax = 0;
loc_1751b: // 1749:008b
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_17521() // 1749:0091
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    cx = memoryAGet16(ds, 0x0089);
    bx = memoryAGet16(ds, 0x0087);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1749);
    if (flags.carry)
        goto loc_1755b;
    cx = memoryAGet16(ds, 0x0091);
    bx = memoryAGet16(ds, 0x008f);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1749);
    if (!flags.zero && !flags.carry)
        goto loc_1755b;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    sub_17491(); // 1749:0001
    if (ax)
        goto loc_17562;
loc_1755b: // 1749:00cb
    ax = 0xffff;
    goto loc_17566;
    //   gap of 2 bytes
loc_17562: // 1749:00d2
    ax = 0;
loc_17566: // 1749:00d6
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17568() // 1749:00d8
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    dx = memoryAGet16(ds, 0x008d);
    ax = memoryAGet16(ds, 0x008b);
    cx = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    push(cs);
    cs = 0x01ed;
    sub_2bad(); // 01ed:0cdd
    assert(cs == 0x1749);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    cx = memoryAGet16(ds, 0x0089);
    bx = memoryAGet16(ds, 0x0087);
    dx = memoryAGet16(ss, bp - 6);
    ax = memoryAGet16(ss, bp - 8);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1749);
    if (flags.carry)
        goto loc_175b0;
    cx = memoryAGet16(ds, 0x0091);
    bx = memoryAGet16(ds, 0x008f);
    dx = memoryAGet16(ss, bp - 6);
    ax = memoryAGet16(ss, bp - 8);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1749);
    if (flags.zero || flags.carry)
        goto loc_175b8;
loc_175b0: // 1749:0120
    dx = 0xffff;
    ax = 0xffff;
    goto loc_175df;
loc_175b8: // 1749:0128
    bx = memoryAGet16(ds, 0x008b);
    es = memoryAGet16(ds, 0x008b + 2);
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    sub_17491(); // 1749:0001
    if (ax)
        goto loc_175d7;
    dx = 0xffff;
    ax = 0xffff;
    goto loc_175df;
loc_175d7: // 1749:0147
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
loc_175df: // 1749:014f
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_175e3() // 175e:0003
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x4a;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_175f7;
    ax = 0xffff;
    goto loc_17601;
loc_175f7: // 175e:0017
    push(bx);
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x175e);
    ax = pop();
loc_17601: // 175e:0021
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17603() // 1760:0003
{
    CStackGuard sg(12, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    si = 0;
    memoryASet16(ss, bp - 4, 0x0000);
    di = 0;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) + 1);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (al != 0x72)
        goto loc_1762c;
    si = 0x0001;
    di = 0x0001;
    goto loc_17657;
loc_1762c: // 1760:002c
    if (memoryAGet(ss, bp - 1) != 0x77)
        goto loc_1763f;
    si = 0x0302;
    memoryASet16(ss, bp - 4, 0x0080);
    di = 0x0002;
    goto loc_17657;
loc_1763f: // 1760:003f
    if (memoryAGet(ss, bp - 1) != 0x61)
        goto loc_17652;
    si = 0x0902;
    memoryASet16(ss, bp - 4, 0x0080);
    di = 0x0002;
    goto loc_17657;
loc_17652: // 1760:0052
    ax = 0;
    goto loc_176ed;
loc_17657: // 1760:0057
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) + 1);
    if (memoryAGet(ss, bp - 1) == 0x2b)
        goto loc_1767e;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    if (memoryAGet(es, bx) != 0x2b)
        goto loc_1769f;
    if (memoryAGet(ss, bp - 1) == 0x74)
        goto loc_1767e;
    if (memoryAGet(ss, bp - 1) != 0x62)
        goto loc_1769f;
loc_1767e: // 1760:007e
    if (memoryAGet(ss, bp - 1) != 0x2b)
        goto loc_1768d;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
loc_1768d: // 1760:008d
    ax = si;
    ax &= 0xfffc;
    ax |= 0x0004;
    si = ax;
    memoryASet16(ss, bp - 4, 0x0180);
    di = 0x0003;
loc_1769f: // 1760:009f
    if (memoryAGet(ss, bp - 1) != 0x74)
        goto loc_176ab;
    si |= 0x4000;
    goto loc_176ce;
loc_176ab: // 1760:00ab
    if (memoryAGet(ss, bp - 1) != 0x62)
        goto loc_176bb;
    si |= 0x8000;
    di |= 0x0040;
    goto loc_176ce;
loc_176bb: // 1760:00bb
    ax = memoryAGet16(ds, 0x3f44);
    ax &= 0xc000;
    si |= ax;
    ax = si;
    if (!(ax & 0x8000))
        goto loc_176ce;
    di |= 0x0040;
loc_176ce: // 1760:00ce
    memoryASet16(ds, 0x3c72, 0x1810);
    memoryASet16(ds, 0x3c70, 0x0007);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, si);
    ax = memoryAGet16(ss, bp - 4);
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx, ax);
    ax = di;
loc_176ed: // 1760:00ed
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 12;
}
void sub_176f5() // 1760:00f5
{
    CStackGuard sg(12, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(ss);
    ax = bp - 0x2;
    push(ax);
    sub_17603(); // 1760:0003
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(es, bx + 2, ax);
    if (!ax)
        goto loc_17742;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    if ((char)memoryAGet(es, bx + 4) >= (char)0x00)
        goto loc_17759;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    cs = 0x178c;
    sub_17901(); // 178c:0041
    assert(cs == 0x1760);
    sp += 0x0008;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet(es, bx + 4, al);
    if ((char)al >= 0)
        goto loc_17759;
loc_17742: // 1760:0142
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet(es, bx + 4, 0xff);
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(es, bx + 2, 0x0000);
    dx = 0;
    ax = 0;
    goto loc_177c8;
loc_17759: // 1760:0159
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x17e8;
    sub_17e86(); // 17e8:0006
    assert(cs == 0x1760);
    cx = pop();
    if (!ax)
        goto loc_17775;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0200);
loc_17775: // 1760:0175
    ax = 0x0200;
    push(ax);
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0200))
        goto loc_17789;
    ax = 0x0001;
    goto loc_1778b;
loc_17789: // 1760:0189
    ax = 0;
loc_1778b: // 1760:018b
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(cs);
    cs = 0x17e9;
    sub_17e9e(); // 17e9:000e
    assert(cs == 0x1760);
    sp += 0x000c;
    if (!ax)
        goto loc_177b7;
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(cs);
    cs = 0x17fe;
    sub_17fe0(); // 17fe:0000
    assert(cs == 0x1760);
    cx = pop();
    cx = pop();
    dx = 0;
    ax = 0;
    goto loc_177c8;
    //   gap of 2 bytes
loc_177b7: // 1760:01b7
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(es, bx + 16, 0x0000);
    dx = memoryAGet16(ss, bp + 14);
    ax = memoryAGet16(ss, bp + 12);
loc_177c8: // 1760:01c8
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 12;
}
void sub_177ce() // 1760:01ce
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    memoryASet16(ss, bp - 2, ds);
    memoryASet16(ss, bp - 4, 0x3d8c);
    goto loc_177e0;
loc_177de: // 1760:01de
loc_177e0: // 1760:01e0
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if ((char)memoryAGet(es, bx + 4) < (char)0x00)
        goto loc_177fd;
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0014);
    bx = 0x3f1c;
    cx = ds;
    if (ax < bx)
        goto loc_177de;
loc_177fd: // 1760:01fd
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if ((char)memoryAGet(es, bx + 4) < (char)0x00)
        goto loc_1780f;
    dx = 0;
    ax = 0;
    goto loc_17817;
    //   gap of 2 bytes
loc_1780f: // 1760:020f
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
loc_17817: // 1760:0217
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1781b() // 1760:021b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    sub_177ce(); // 1760:01ce
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    dx |= ax;
    if (dx)
        goto loc_17836;
    dx = 0;
    ax = 0;
    goto loc_1784d;
    //   gap of 2 bytes
loc_17836: // 1760:0236
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    sub_176f5(); // 1760:00f5
loc_1784d: // 1760:024d
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_178ce() // 178c:000e
{
    CStackGuard sg(6, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    cx = memoryAGet16(ss, bp + 4);
    ah = 0x3c;
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_178e1;
    goto loc_178e9;
loc_178e1: // 178c:0021
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x178c);
loc_178e9: // 178c:0029
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_178ed() // 178c:002d
{
    CStackGuard sg(2, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    cx = 0;
    dx = 0;
    ah = 0x40;
    interrupt(0x21);
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_17901() // 178c:0041
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 10);
    if (di & 0xc000)
        goto loc_1791a;
    ax = memoryAGet16(ds, 0x3f44);
    ax &= 0xc000;
    di |= ax;
loc_1791a: // 178c:005a
    if (di & 0x0100)
        goto loc_17923;
    goto loc_179c2;
loc_17923: // 178c:0063
    ax = memoryAGet16(ds, 0x3f46);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) & ax);
    ax = memoryAGet16(ss, bp + 12);
    if (ax & 0x0180)
        goto loc_1793a;
    ax = 0x0001;
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x178c);
loc_1793a: // 178c:007a
    ax = 0;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1895;
    sub_18956(); // 1895:0006
    assert(cs == 0x178c);
    sp += 0x0006;
    memoryASet16(ss, bp - 4, ax);
    if (ax != 0xffff)
        goto loc_17966;
    if (!(memoryAGet16(ss, bp + 12) & 0x0080))
        goto loc_1795e;
    ax = 0;
    goto loc_17961;
loc_1795e: // 178c:009e
    ax = 0x0001;
loc_17961: // 178c:00a1
    memoryASet16(ss, bp - 4, ax);
    goto loc_1797c;
loc_17966: // 178c:00a6
    if (!(di & 0x0400))
        goto loc_1797a;
    ax = 0x0050;
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x178c);
    goto loc_17a68;
    //   gap of 2 bytes
loc_1797a: // 178c:00ba
    goto loc_179c2;
loc_1797c: // 178c:00bc
    if (!(di & 0x00f0))
        goto loc_179a6;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    ax = 0;
    push(ax);
    sub_178ce(); // 178c:000e
    si = ax;
    ax = si;
    if ((short)ax >= 0)
        goto loc_1799b;
    ax = si;
    goto loc_17a68;
loc_1799b: // 178c:00db
    push(si);
    push(cs);
    cs = 0x180e;
    sub_180e1(); // 180e:0001
    assert(cs == 0x178c);
    cx = pop();
    goto loc_179c7;
    //   gap of 2 bytes
loc_179a6: // 178c:00e6
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp - 4));
    sub_178ce(); // 178c:000e
    si = ax;
    ax = si;
    if ((short)ax >= 0)
        goto loc_179bf;
    ax = si;
    goto loc_17a68;
loc_179bf: // 178c:00ff
    goto loc_17a43;
loc_179c2: // 178c:0102
    memoryASet16(ss, bp - 4, 0x0000);
loc_179c7: // 178c:0107
    push(di);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x17a6;
    sub_17a6e(); // 17a6:000e
    assert(cs == 0x178c);
    sp += 0x0006;
    si = ax;
    ax = si;
    if ((short)ax < 0)
        goto loc_17a43;
    ax = 0;
    push(ax);
    push(si);
    push(cs);
    cs = 0x17e5;
    sub_17e59(); // 17e5:0009
    assert(cs == 0x178c);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 2, ax);
    if (!(ax & 0x0080))
        goto loc_17a17;
    di |= 0x2000;
    if (!(di & 0x8000))
        goto loc_17a15;
    ax = memoryAGet16(ss, bp - 2);
    ax &= 0x00ff;
    ax |= 0x0020;
    dx = 0;
    push(dx);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(si);
    push(cs);
    cs = 0x17e5;
    sub_17e59(); // 17e5:0009
    assert(cs == 0x178c);
    sp += 0x0008;
loc_17a15: // 178c:0155
    goto loc_17a21;
loc_17a17: // 178c:0157
    if (!(di & 0x0200))
        goto loc_17a21;
    push(si);
    sub_178ed(); // 178c:002d
loc_17a21: // 178c:0161
    if (memoryAGet16(ss, bp - 4) == 0x0000)
        goto loc_17a43;
    if (!(di & 0x00f0))
        goto loc_17a43;
    ax = 0x0001;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1895;
    sub_18956(); // 1895:0006
    assert(cs == 0x178c);
    sp += 0x0008;
loc_17a43: // 178c:0183
    if ((short)si < 0)
        goto loc_17a64;
    if (!(di & 0x0300))
        goto loc_17a52;
    ax = 0x1000;
    goto loc_17a54;
loc_17a52: // 178c:0192
    ax = 0;
loc_17a54: // 178c:0194
    dx = di;
    dx &= 0xf8ff;
    ax |= dx;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16156, ax);
loc_17a64: // 178c:01a4
    ax = si;
loc_17a68: // 178c:01a8
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17a6e() // 17a6:000e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    al = 0x01;
    cx = memoryAGet16(ss, bp + 10);
    if (cx & 0x0002)
        goto loc_17a87;
    al = 0x02;
    if (cx & 0x0004)
        goto loc_17a87;
    al = 0x00;
loc_17a87: // 17a6:0027
    push(ds);
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    cl = 0xf0;
    cl &= memoryAGet(ss, bp + 10);
    al |= cl;
    ah = 0x3d;
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_17ab0;
    si = ax;
    ax = memoryAGet16(ss, bp + 10);
    ax &= 0xf8ff;
    ax |= 0x8000;
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16156, ax);
    ax = si;
    goto loc_17ab8;
loc_17ab0: // 17a6:0050
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x17a6);
loc_17ab8: // 17a6:0058
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17abb() // 17ab:000b
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    si = memoryAGet16(es, bx);
    di = si;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0040))
        goto loc_17ada;
    ax = si;
    goto loc_17b01;
loc_17ada: // 17ab:002a
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    goto loc_17af6;
loc_17ae9: // 17ab:0039
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    if (memoryAGet(es, bx) != 0x0a)
        goto loc_17af6;
    di++;
loc_17af6: // 17ab:0046
    ax = si;
    si--;
    if (ax)
        goto loc_17ae9;
    ax = di;
loc_17b01: // 17ab:0051
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_17b09() // 17ab:0059
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x189e;
    sub_189e7(); // 189e:0007
    assert(cs == 0x17ab);
    sp = bp;
    if (!ax)
        goto loc_17b23;
    ax = 0xffff;
    goto loc_17b95;
loc_17b23: // 17ab:0073
    if (memoryAGet16(ss, bp + 14) != 0x0001)
        goto loc_17b42;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if ((short)memoryAGet16(es, bx) <= (short)0x0000)
        goto loc_17b42;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    sub_17abb(); // 17ab:000b
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, bp + 10) < ax;
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) - ax);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) - (dx + flags.carry));
loc_17b42: // 17ab:0092
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xfe5f);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx, 0x0000);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = memoryAGet16(es, bx + 10);
    ax = memoryAGet16(es, bx + 8);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x1866;
    sub_18667(); // 1866:0007
    assert(cs == 0x17ab);
    sp = bp;
    if (dx != 0xffff)
        goto loc_17b91;
    if (ax != 0xffff)
        goto loc_17b91;
    ax = 0xffff;
    goto loc_17b93;
loc_17b91: // 17ab:00e1
    ax = 0;
loc_17b93: // 17ab:00e3
loc_17b95: // 17ab:00e5
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17c08() // 17c0:0008
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    si = 0x0014;
    memoryASet16(ss, bp - 2, ds);
    memoryASet16(ss, bp - 4, 0x3d8c);
    goto loc_17c3c;
loc_17c1c: // 17c0:001c
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 2);
    ax &= 0x0300;
    if (ax != 0x0300)
        goto loc_17c38;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x189e;
    sub_189e7(); // 189e:0007
    assert(cs == 0x17c0);
    cx = pop();
    cx = pop();
loc_17c38: // 17c0:0038
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0014);
loc_17c3c: // 17c0:003c
    ax = si;
    si--;
    if (ax)
        goto loc_17c1c;
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_17c48() // 17c0:0048
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0200))
        goto loc_17c59;
    sub_17c08(); // 17c0:0008
loc_17c59: // 17c0:0059
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    push(memoryAGet16(es, bx + 6));
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    dx = memoryAGet16(es, bx + 10);
    ax = memoryAGet16(es, bx + 8);
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
    push(dx);
    push(ax);
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x1830;
    sub_18307(); // 1830:0007
    assert(cs == 0x17c0);
    sp = bp;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx, ax);
    if ((short)ax <= 0)
        goto loc_17ca1;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xffdf);
    ax = 0;
    goto loc_17cd6;
    //   gap of 2 bytes
loc_17ca1: // 17c0:00a1
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet16(es, bx) != 0x0000)
        goto loc_17cc0;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 2);
    ax &= 0xfe7f;
    ax |= 0x0020;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, ax);
    goto loc_17cd1;
loc_17cc0: // 17c0:00c0
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx, 0x0000);
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0010);
loc_17cd1: // 17c0:00d1
    ax = 0xffff;
loc_17cd6: // 17c0:00d6
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_17cda() // 17c0:00da
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + 1);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x17c0;
    sub_17cf4(); // 17c0:00f4
    assert(cs == 0x17c0);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17cf4() // 17c0:00f4
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
loc_17cfa: // 17c0:00fa
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    tx = memoryAGet16(es, bx);
    memoryASet16(es, bx, memoryAGet16(es, bx) - 1);
    if ((short)tx < 1)
        goto loc_17d16;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) + 1);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    bx--;
    al = memoryAGet(es, bx);
    ah = 0x00;
    goto loc_17e47;
loc_17d16: // 17c0:0116
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + 1);
    if ((short)memoryAGet16(es, bx) < 0)
        goto loc_17d29;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0110))
        goto loc_17d38;
loc_17d29: // 17c0:0129
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0010);
    ax = 0xffff;
    goto loc_17e47;
loc_17d38: // 17c0:0138
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0080);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, bx + 6) == 0x0000)
        goto loc_17d63;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    sub_17c48(); // 17c0:0048
    if (!ax)
        goto loc_17d5e;
    ax = 0xffff;
    goto loc_17e47;
loc_17d5e: // 17c0:015e
    goto loc_17cfa;
    //   gap of 3 bytes
loc_17d63: // 17c0:0163
    if (memoryAGet16(ds, 0x3f48) != 0x0000)
        goto loc_17dbe;
    ax = memoryAGet16(ss, bp + 6);
    bx = 0x3d8c;
    cx = ds;
    if (ax != bx)
        goto loc_17dbe;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x17e8;
    sub_17e86(); // 17e8:0006
    assert(cs == 0x17c0);
    cx = pop();
    if (ax)
        goto loc_17d92;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xfdff);
loc_17d92: // 17c0:0192
    ax = 0x0200;
    push(ax);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0200))
        goto loc_17da6;
    ax = 0x0001;
    goto loc_17da8;
loc_17da6: // 17c0:01a6
    ax = 0;
loc_17da8: // 17c0:01a8
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x17e9;
    sub_17e9e(); // 17e9:000e
    assert(cs == 0x17c0);
    sp += 0x000c;
    goto loc_17d38;
loc_17dbe: // 17c0:01be
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0200))
        goto loc_17dcc;
    sub_17c08(); // 17c0:0008
loc_17dcc: // 17c0:01cc
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp - 0x1;
    push(ax);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x183c;
    sub_183cc(); // 183c:000c
    assert(cs == 0x17c0);
    sp += 0x0008;
    if (ax == 0x0001)
        goto loc_17e23;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x1897;
    sub_18977(); // 1897:0007
    assert(cs == 0x17c0);
    cx = pop();
    if (ax == 0x0001)
        goto loc_17e0a;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0010);
    goto loc_17e1e;
loc_17e0a: // 17c0:020a
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 2);
    ax &= 0xfe7f;
    ax |= 0x0020;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, ax);
loc_17e1e: // 17c0:021e
    ax = 0xffff;
    goto loc_17e47;
loc_17e23: // 17c0:0223
    if (memoryAGet(ss, bp - 1) != 0x0d)
        goto loc_17e37;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0040)
        goto loc_17e37;
    goto loc_17dbe;
loc_17e37: // 17c0:0237
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xffdf);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
loc_17e47: // 17c0:0247
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17e59() // 17e5:0009
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x44;
    al = memoryAGet(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    cx = memoryAGet16(ss, bp + 14);
    dx = memoryAGet16(ss, bp + 10);
    ds = memoryAGet16(ss, bp + 10 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_17e7c;
    if (memoryAGet16(ss, bp + 8) != 0x0000)
        goto loc_17e7a;
    ax = dx;
    goto loc_17e84;
loc_17e7a: // 17e5:002a
    goto loc_17e84;
loc_17e7c: // 17e5:002c
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x17e5);
loc_17e84: // 17e5:0034
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17e86() // 17e8:0006
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x4400;
    bx = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    ax = 0x0000;
    if (flags.carry)
        goto loc_17e9a;
    flags.carry = !!(dx & 0x8000);
    dx <<= 1;
    ax = rcl(ax, 0x0001);
loc_17e9a: // 17e8:001a
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17e9e() // 17e9:000e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 16);
    di = memoryAGet16(ss, bp + 14);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 18);
    dx = memoryAGet16(ss, bp + 6);
    if (ax != dx)
        goto loc_17ec2;
    if ((short)di > (short)0x0002)
        goto loc_17ec2;
    if (si <= 0x7fff)
        goto loc_17ec8;
loc_17ec2: // 17e9:0032
    ax = 0xffff;
    goto loc_17fdc;
loc_17ec8: // 17e9:0038
    if (memoryAGet16(ds, 0x3f4a) != 0x0000)
        goto loc_17ee3;
    ax = memoryAGet16(ss, bp + 6);
    bx = 0x3da0;
    cx = ds;
    if (ax != bx)
        goto loc_17ee3;
    memoryASet16(ds, 0x3f4a, 0x0001);
    goto loc_17efc;
loc_17ee3: // 17e9:0053
    if (memoryAGet16(ds, 0x3f48) != 0x0000)
        goto loc_17efc;
    ax = memoryAGet16(ss, bp + 6);
    bx = 0x3d8c;
    cx = ds;
    if (ax != bx)
        goto loc_17efc;
    memoryASet16(ds, 0x3f48, 0x0001);
loc_17efc: // 17e9:006c
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, bx) == 0x0000)
        goto loc_17f1b;
    ax = 0x0001;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x17ab;
    sub_17b09(); // 17ab:0059
    assert(cs == 0x17e9);
    sp += 0x000a;
loc_17f1b: // 17e9:008b
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0004))
        goto loc_17f38;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(memoryAGet16(es, bx + 10));
    push(memoryAGet16(es, bx + 8));
    push(cs);
    cs = 0x1933;
    sub_19335(); // 1933:0005
    assert(cs == 0x17e9);
    cx = pop();
    cx = pop();
loc_17f38: // 17e9:00a8
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xfff3);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 6, 0x0000);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    ax += 0x0005;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 10, dx);
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
    if (di == 0x0002)
        goto loc_17fd8;
    if ((short)di < 0 || si == 0)
        goto loc_17fd8;
    memoryASet16(ds, 0x3c6e, 0x1813);
    memoryASet16(ds, 0x3c6c, 0x000f);
    ax = memoryAGet16(ss, bp + 10);
    ax |= memoryAGet16(ss, bp + 12);
    if (ax)
        goto loc_17fa7;
    push(si);
    push(cs);
    cs = 0x1718;
    sub_17181(); // 1718:0001
    assert(cs == 0x17e9);
    cx = pop();
    memoryASet16(ss, bp + 12, dx);
    memoryASet16(ss, bp + 10, ax);
    dx |= ax;
    if (!dx)
        goto loc_17fa2;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0004);
    goto loc_17fa7;
loc_17fa2: // 17e9:0112
    ax = 0xffff;
    goto loc_17fdc;
loc_17fa7: // 17e9:0117
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 10, dx);
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 6, si);
    if (di != 0x0001)
        goto loc_17fd8;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0008);
loc_17fd8: // 17e9:0148
    ax = 0;
loc_17fdc: // 17e9:014c
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_17fe0() // 17fe:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = 0xffff;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 18);
    dx = memoryAGet16(ss, bp + 6);
    if (ax == dx)
        goto loc_17ffa;
    ax = si;
    goto loc_180ad;
loc_17ffa: // 17fe:001a
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, bx + 6) == 0x0000)
        goto loc_18040;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if ((short)memoryAGet16(es, bx) >= (short)0x0000)
        goto loc_18023;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x189e;
    sub_189e7(); // 189e:0007
    assert(cs == 0x17fe);
    cx = pop();
    cx = pop();
    if (!ax)
        goto loc_18023;
    ax = si;
    goto loc_180ad;
loc_18023: // 17fe:0043
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0004))
        goto loc_18040;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(memoryAGet16(es, bx + 10));
    push(memoryAGet16(es, bx + 8));
    push(cs);
    cs = 0x1933;
    sub_19335(); // 1933:0005
    assert(cs == 0x17fe);
    cx = pop();
    cx = pop();
loc_18040: // 17fe:0060
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if ((char)memoryAGet(es, bx + 4) < (char)0x00)
        goto loc_1805b;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x180b;
    sub_180b0(); // 180b:0000
    assert(cs == 0x17fe);
    cx = pop();
    si = ax;
loc_1805b: // 17fe:007b
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, 0x0000);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 6, 0x0000);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx, 0x0000);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet(es, bx + 4, 0xff);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, bx + 16) == 0x0000)
        goto loc_180a9;
    ax = 0;
    push(ax);
    push(ax);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    push(memoryAGet16(es, bx + 16));
    push(cs);
    cs = 0x1879;
    sub_18790(); // 1879:0000
    assert(cs == 0x17fe);
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1884;
    sub_18840(); // 1884:0000
    assert(cs == 0x17fe);
    cx = pop();
    cx = pop();
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 16, 0x0000);
loc_180a9: // 17fe:00c9
    ax = si;
loc_180ad: // 17fe:00cd
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_180b0() // 180b:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 6);
    if ((short)si < 0)
        goto loc_180c0;
    if ((short)si < (short)0x0014)
        goto loc_180cb;
loc_180c0: // 180b:0010
    ax = 0x0006;
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x180b);
    goto loc_180de;
loc_180cb: // 180b:001b
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 16156, 0xffff);
    push(si);
    push(cs);
    cs = 0x180e;
    sub_180e1(); // 180e:0001
    assert(cs == 0x180b);
    cx = pop();
loc_180de: // 180b:002e
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_180e1() // 180e:0001
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 6);
    ah = 0x3e;
    bx = si;
    interrupt(0x21);
    if (flags.carry)
        goto loc_180fc;
    bx <<= 1;
    memoryASet16(ds, bx + 16156, 0xffff);
    ax = 0;
    goto loc_18104;
loc_180fc: // 180e:001c
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x180e);
loc_18104: // 180e:0024
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1813f() // 1813:000f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    si = 0x0004;
    memoryASet16(ss, bp - 2, ds);
    memoryASet16(ss, bp - 4, 0x3d8c);
    goto loc_18170;
loc_18153: // 1813:0023
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0003))
        goto loc_1816b;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x189e;
    sub_189e7(); // 189e:0007
    assert(cs == 0x1813);
    cx = pop();
    cx = pop();
loc_1816b: // 1813:003b
    si--;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0014);
loc_18170: // 1813:0040
    if (si)
        goto loc_18153;
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18179() // 1817:0009
{
    CStackGuard sg(10, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    goto loc_1826f;
loc_18181: // 1817:0011
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 1);
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 6);
    if (ax <= memoryAGet16(ss, bp + 8))
        goto loc_18195;
    di = memoryAGet16(ss, bp + 8);
    goto loc_1819c;
loc_18195: // 1817:0025
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    di = memoryAGet16(es, bx + 6);
loc_1819c: // 1817:002c
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0040)
        goto loc_181aa;
    goto loc_1821b;
loc_181aa: // 1817:003a
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet16(es, bx + 6) == 0x0000)
        goto loc_1821b;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 6);
    if (ax >= memoryAGet16(ss, bp + 8))
        goto loc_1821b;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet16(es, bx) != 0x0000)
        goto loc_1821b;
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) - 1);
    di = 0;
    goto loc_181e3;
loc_181d0: // 1817:0060
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 6);
    di += ax;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 6);
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) - ax);
loc_181e3: // 1817:0073
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 6);
    if (ax <= memoryAGet16(ss, bp + 8))
        goto loc_181d0;
    push(di);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x183c;
    sub_183cc(); // 183c:000c
    assert(cs == 0x1817);
    sp += 0x0008;
    si = ax;
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) + si);
    if (si == di)
        goto loc_18219;
    ax = di;
    ax -= si;
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + ax);
    goto loc_18278;
loc_18219: // 1817:00a9
    goto loc_1826f;
loc_1821b: // 1817:00ab
    goto loc_18228;
loc_1821d: // 1817:00ad
    ax = si;
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    memoryASet(es, bx, al);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) + 1);
loc_18228: // 1817:00b8
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) - 1);
    ax = memoryAGet16(ss, bp + 8);
    if (!ax)
        goto loc_18268;
    di--;
    if (di == 0)
        goto loc_18268;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    tx = memoryAGet16(es, bx);
    memoryASet16(es, bx, memoryAGet16(es, bx) - 1);
    if ((short)tx < 1)
        goto loc_18252;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) + 1);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    bx--;
    al = memoryAGet(es, bx);
    ah = 0x00;
    si = ax;
    goto loc_18261;
loc_18252: // 1817:00e2
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    push(cs);
    cs = 0x17c0;
    sub_17cda(); // 17c0:00da
    assert(cs == 0x1817);
    cx = pop();
    cx = pop();
    si = ax;
loc_18261: // 1817:00f1
    ax = si;
    if (ax != 0xffff)
        goto loc_1821d;
loc_18268: // 1817:00f8
    if (si != 0xffff)
        goto loc_1826f;
    goto loc_18278;
loc_1826f: // 1817:00ff
    if (memoryAGet16(ss, bp + 8) == 0x0000)
        goto loc_18278;
    goto loc_18181;
loc_18278: // 1817:0108
    ax = memoryAGet16(ss, bp + 8);
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    sp += 10;
}
void sub_18283() // 1817:0113
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 10);
    if (si)
        goto loc_18296;
    ax = 0;
    goto loc_18301;
loc_18296: // 1817:0126
    ax = si;
    dx = 0;
    bx = memoryAGet16(ss, bp + 12);
    cx = 0;
    push(cs);
    cs = 0x01ed;
    sub_2c29(); // 01ed:0d59
    assert(cs == 0x1817);
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    if (dx > 0x0001)
        goto loc_182d6;
    if (dx < 0x0001)
        goto loc_182b5;
    if (stop(/*condition!*/))
        goto loc_182d6;
loc_182b5: // 1817:0145
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    sub_18179(); // 1817:0009
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    dx = pop();
    ax -= dx;
    dx = 0;
    div(si);
    goto loc_18301;
    //   gap of 2 bytes
loc_182d6: // 1817:0166
    di = memoryAGet16(ss, bp + 12);
    di++;
    goto loc_182df;
loc_182dc: // 1817:016c
    memoryASet16(ss, bp + 6, memoryAGet16(ss, bp + 6) + si);
loc_182df: // 1817:016f
    di--;
    ax = di;
    if (!ax)
        goto loc_182fa;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(si);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    sub_18179(); // 1817:0009
    if (!ax)
        goto loc_182dc;
loc_182fa: // 1817:018a
    ax = memoryAGet16(ss, bp + 12);
    ax -= di;
loc_18301: // 1817:0191
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18307() // 1830:0007
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 12);
    ax++;
    if (ax < 0x0002)
        goto loc_18325;
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 16156) & 0x0200))
        goto loc_1832a;
loc_18325: // 1830:0025
    ax = 0;
    goto loc_183c6;
loc_1832a: // 1830:002a
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x183c;
    sub_183cc(); // 183c:000c
    assert(cs == 0x1830);
    sp += 0x0008;
    memoryASet16(ss, bp - 4, ax);
    ax = memoryAGet16(ss, bp - 4);
    ax++;
    if (ax < 0x0002)
        goto loc_18357;
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 16156) & 0x8000))
        goto loc_1835d;
loc_18357: // 1830:0057
    ax = memoryAGet16(ss, bp - 4);
    goto loc_183c6;
loc_1835d: // 1830:005d
    cx = memoryAGet16(ss, bp - 4);
    si = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    di = si;
    bx = si;
    flags.direction = false;
loc_18368: // 1830:0068
    lodsb_es<MemAuto, DirAuto>();
    if (al == 0x1a)
        goto loc_1839e;
    if (al == 0x0d)
        goto loc_18377;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_18368;
    goto loc_18396;
loc_18377: // 1830:0077
    if (--cx)
        goto loc_18368;
    push(es);
    push(bx);
    ax = 0x0001;
    push(ax);
    ax = bp - 0x1;
    push(ss);
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x183c;
    sub_183cc(); // 183c:000c
    assert(cs == 0x1830);
    sp += 0x0008;
    bx = pop();
    es = pop();
    flags.direction = false;
    al = memoryAGet(ss, bp - 1);
    stosb<MemAuto, DirAuto>();
loc_18396: // 1830:0096
    if (di != bx)
        goto loc_1839c;
    goto loc_1832a;
loc_1839c: // 1830:009c
    goto loc_183c0;
loc_1839e: // 1830:009e
    push(bx);
    ax = 0x0002;
    push(ax);
    flags.carry = cx != 0;
    cx = -cx;
    ax -= ax + flags.carry;
    push(ax);
    push(cx);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1866;
    sub_18667(); // 1866:0007
    assert(cs == 0x1830);
    sp += 0x0008;
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    memoryASet16(ds, bx + 16156, memoryAGet16(ds, bx + 16156) | 0x0200);
    bx = pop();
loc_183c0: // 1830:00c0
    ax = di;
    ax -= bx;
loc_183c6: // 1830:00c6
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_183cc() // 183c:000c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x3f;
    bx = memoryAGet16(ss, bp + 6);
    cx = memoryAGet16(ss, bp + 12);
    dx = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_183e2;
    goto loc_183ea;
loc_183e2: // 183c:0022
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x183c);
loc_183ea: // 183c:002a
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_183ec() // 183e:000c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 10);
    if (si)
        goto loc_18401;
    ax = memoryAGet16(ss, bp + 12);
    goto loc_18470;
loc_18401: // 183e:0021
    ax = si;
    dx = 0;
    bx = memoryAGet16(ss, bp + 12);
    cx = 0;
    push(cs);
    cs = 0x01ed;
    sub_2c29(); // 01ed:0d59
    assert(cs == 0x183e);
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    if (dx > 0x0001)
        goto loc_18443;
    if (dx < 0x0001)
        goto loc_18420;
    if (stop(/*condition!*/))
        goto loc_18443;
loc_18420: // 183e:0040
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = 0x18af;
    sub_18ccd(); // 18af:01dd
    assert(cs == 0x183e);
    push(ax);
    ax = memoryAGet16(ss, bp - 4);
    dx = pop();
    ax -= dx;
    dx = 0;
    div(si);
    goto loc_18470;
    //   gap of 2 bytes
loc_18443: // 183e:0063
    di = memoryAGet16(ss, bp + 12);
    di++;
    goto loc_1844c;
loc_18449: // 183e:0069
    memoryASet16(ss, bp + 6, memoryAGet16(ss, bp + 6) + si);
loc_1844c: // 183e:006c
    di--;
    ax = di;
    if (!ax)
        goto loc_18469;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(si);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = 0x18af;
    sub_18ccd(); // 18af:01dd
    assert(cs == 0x183e);
    if (!ax)
        goto loc_18449;
loc_18469: // 183e:0089
    ax = memoryAGet16(ss, bp + 12);
    ax -= di;
loc_18470: // 183e:0090
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18476() // 1847:0006
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x008e;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 12);
    ax++;
    if (ax >= 0x0002)
        goto loc_1848d;
    ax = 0;
    goto loc_185d6;
loc_1848d: // 1847:001d
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 16156) & 0x8000))
        goto loc_184b1;
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x185d;
    sub_185dc(); // 185d:000c
    assert(cs == 0x1847);
    sp += 0x0008;
    goto loc_185d6;
loc_184b1: // 1847:0041
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    memoryASet16(ds, bx + 16156, memoryAGet16(ds, bx + 16156) & 0xfdff);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(ss, bp - 132, es);
    memoryASet16(ss, bp - 134, bx);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(ss, bp - 138, ax);
    bx = ss;
    es = bx;
    bx = bp - 0x82;
    memoryASet16(ss, bp - 140, es);
    memoryASet16(ss, bp - 142, bx);
    goto loc_18582;
loc_184e1: // 1847:0071
    memoryASet16(ss, bp - 138, memoryAGet16(ss, bp - 138) - 1);
    bx = memoryAGet16(ss, bp - 134);
    es = memoryAGet16(ss, bp - 134 + 2);
    memoryASet16(ss, bp - 134, memoryAGet16(ss, bp - 134) + 1);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 135, al);
    if (al != 0x0a)
        goto loc_18504;
    bx = memoryAGet16(ss, bp - 142);
    es = memoryAGet16(ss, bp - 142 + 2);
    memoryASet(es, bx, 0x0d);
    memoryASet16(ss, bp - 142, memoryAGet16(ss, bp - 142) + 1);
loc_18504: // 1847:0094
    al = memoryAGet(ss, bp - 135);
    bx = memoryAGet16(ss, bp - 142);
    es = memoryAGet16(ss, bp - 142 + 2);
    memoryASet(es, bx, al);
    memoryASet16(ss, bp - 142, memoryAGet16(ss, bp - 142) + 1);
    ax = memoryAGet16(ss, bp - 142);
    cx = ss;
    bx = bp - 0x82;
    dx = 0;
    flags.carry = ax < bx;
    ax -= bx;
    dx -= flags.carry;
    if ((short)dx < 0)
        goto loc_18582;
    if (dx)
        goto loc_1852f;
    if (ax < 0x0080)
        goto loc_18582;
loc_1852f: // 1847:00bf
    ax = memoryAGet16(ss, bp - 142);
    cx = ss;
    bx = bp - 0x82;
    dx = 0;
    flags.carry = ax < bx;
    ax -= bx;
    dx -= flags.carry;
    si = ax;
    push(si);
    push(ss);
    ax = bp - 0x82;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x185d;
    sub_185dc(); // 185d:000c
    assert(cs == 0x1847);
    sp += 0x0008;
    di = ax;
    ax = di;
    if (ax == si)
        goto loc_18572;
    if (stop(/*condition!*/))
        goto loc_18565;
    ax = 0xffff;
    goto loc_18570;
loc_18565: // 1847:00f5
    ax = memoryAGet16(ss, bp + 12);
    ax -= memoryAGet16(ss, bp - 138);
    ax += di;
    ax -= si;
loc_18570: // 1847:0100
    goto loc_185d6;
loc_18572: // 1847:0102
    bx = ss;
    es = bx;
    bx = bp - 0x82;
    memoryASet16(ss, bp - 140, es);
    memoryASet16(ss, bp - 142, bx);
loc_18582: // 1847:0112
    if (memoryAGet16(ss, bp - 138) == 0x0000)
        goto loc_1858c;
    goto loc_184e1;
loc_1858c: // 1847:011c
    ax = memoryAGet16(ss, bp - 142);
    cx = ss;
    bx = bp - 0x82;
    dx = 0;
    flags.carry = ax < bx;
    ax -= bx;
    dx -= flags.carry;
    si = ax;
    ax = si;
    if (ax <= bx)
        goto loc_185d1;
    push(si);
    push(ss);
    ax = bp - 0x82;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x185d;
    sub_185dc(); // 185d:000c
    assert(cs == 0x1847);
    sp += 0x0008;
    di = ax;
    ax = di;
    if (ax == si)
        goto loc_185d1;
    if (stop(/*condition!*/))
        goto loc_185c8;
    ax = 0xffff;
    goto loc_185cf;
loc_185c8: // 1847:0158
    ax = memoryAGet16(ss, bp + 12);
    ax += di;
    ax -= si;
loc_185cf: // 1847:015f
    goto loc_185d6;
loc_185d1: // 1847:0161
    ax = memoryAGet16(ss, bp + 12);
loc_185d6: // 1847:0166
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_185dc() // 185d:000c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 16156) & 0x0800))
        goto loc_185fe;
    ax = 0x0002;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1866;
    sub_18667(); // 1866:0007
    assert(cs == 0x185d);
    sp = bp;
loc_185fe: // 185d:002e
    push(ds);
    ah = 0x40;
    bx = memoryAGet16(ss, bp + 6);
    cx = memoryAGet16(ss, bp + 12);
    dx = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_1861e;
    push(ax);
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    memoryASet16(ds, bx + 16156, memoryAGet16(ds, bx + 16156) | 0x1000);
    ax = pop();
    goto loc_18626;
loc_1861e: // 185d:004e
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x185d);
loc_18626: // 185d:0056
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18667() // 1866:0007
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    memoryASet16(ds, bx + 16156, memoryAGet16(ds, bx + 16156) & 0xfdff);
    ah = 0x42;
    al = memoryAGet(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 6);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 8);
    interrupt(0x21);
    if (flags.carry)
        goto loc_18689;
    goto loc_18692;
loc_18689: // 1866:0029
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x1866);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
loc_18692: // 1866:0032
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18694() // 1869:0004
{
    CStackGuardFar sg(14, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0022;
    push(si);
    push(di);
    push(es);
    di = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    bx = memoryAGet16(ss, bp + 10);
    if (bx > 0x0024)
        goto loc_18704;
    if (bl < 0x02)
        goto loc_18704;
    ax = memoryAGet16(ss, bp + 16);
    cx = memoryAGet16(ss, bp + 18);
    if ((short)cx >= 0)
        goto loc_186c9;
    if (memoryAGet(ss, bp + 8) == 0x00)
        goto loc_186c9;
    memoryASet(es, di, 0x2d);
    di++;
    cx = -cx;
    flags.carry = ax != 0;
    ax = -ax;
    cx -= flags.carry;
loc_186c9: // 1869:0039
    si = bp - 0x22;
    if (cx == 0)
        goto loc_186de;
loc_186ce: // 1869:003e
    tx = cx;
    cx = ax;
    ax = tx;
    dx = 0;
    div(bx);
    tx = cx;
    cx = ax;
    ax = tx;
    div(bx);
    memoryASet(ss, si, dl);
    si++;
    if (cx == 0)
        goto loc_186e6;
    goto loc_186ce;
loc_186de: // 1869:004e
    dx = 0;
    div(bx);
    memoryASet(ss, si, dl);
    si++;
loc_186e6: // 1869:0056
    if (ax)
        goto loc_186de;
    cx = bp - 0x22;
    cx = -cx;
    cx += si;
    flags.direction = false;
loc_186f2: // 1869:0062
    si--;
    al = memoryAGet(ss, si);
    flags.carry = al < 0x0a;
    al -= 0x0a;
    if (!flags.carry)
        goto loc_186fe;
    al += 0x3a;
    goto loc_18701;
loc_186fe: // 1869:006e
    al += memoryAGet(ss, bp + 6);
loc_18701: // 1869:0071
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_186f2;
loc_18704: // 1869:0074
    al = 0x00;
    stosb<MemAuto, DirAuto>();
    es = pop();
    dx = memoryAGet16(ss, bp + 14);
    ax = memoryAGet16(ss, bp + 12);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 14;
}
void sub_18745() // 1869:00b5
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 14));
    al = 0x00;
    push(ax);
    al = 0x61;
    push(ax);
    push(cs);
    sub_18694(); // 1869:0004
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18790() // 1879:0000
{
    CStackGuardFar sg(6, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 8);
    ax |= memoryAGet16(ss, bp + 10);
    if (ax)
        goto loc_187a3;
    memoryASet16(ss, bp + 10, ds);
    memoryASet16(ss, bp + 8, 0xa65c);
loc_187a3: // 1879:0013
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet(es, bx, 0x00);
    push(ds);
    ax = 0x3f4c;
    push(ax);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    cs = 0x1885;
    sub_1885c(); // 1885:000c
    assert(cs == 0x1879);
    sp = bp;
    ax = 0x000a;
    push(ax);
    dx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    ax += 0x0003;
    push(dx);
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    dx = 0;
    push(dx);
    push(ax);
    push(cs);
    cs = 0x1869;
    sub_18745(); // 1869:00b5
    assert(cs == 0x1879);
    sp = bp;
    push(ds);
    ax = 0x3f50;
    push(ax);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    cs = 0x1885;
    sub_1885c(); // 1885:000c
    assert(cs == 0x1879);
    sp = bp;
    dx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 6;
}
void sub_18840() // 1884:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x41;
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_18852;
    ax = 0;
    goto loc_1885a;
loc_18852: // 1884:0012
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x1884);
loc_1885a: // 1884:001a
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1885c() // 1885:000c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    flags.direction = false;
    push(ds);
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = di;
    al = 0;
    cx = 0xffff;
    repne_scasb<MemAuto, DirAuto>(al);
    push(es);
    si = di + 0xffffffff;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    cx = 0xffff;
    repne_scasb<MemAuto, DirAuto>(al);
    cx = ~cx;
    di -= cx;
    push(es);
    ds = pop();
    es = pop();
    tx = di;
    di = si;
    si = tx;
    if (!(si & 0x0001))
        goto loc_1888c;
    movsb<MemAuto, MemAuto, DirAuto>();
    cx--;
loc_1888c: // 1885:003c
    flags.carry = cx & 1;
    cx >>= 1;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    if (!flags.carry)
        goto loc_18893;
    movsb<MemAuto, MemAuto, DirAuto>();
loc_18893: // 1885:0043
    ax = dx;
    dx = es;
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1889e() // 1889:000e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    flags.direction = false;
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = 0;
    cx = 0xffff;
    repne_scasb<MemAuto, DirAuto>(al);
    ax = cx;
    ax = ~ax;
    ax--;
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_188b9() // 188b:0009
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    flags.direction = false;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    si = di;
    al = 0;
    cx = 0xffff;
    repne_scasb<MemAuto, DirAuto>(al);
    cx = ~cx;
    push(ds);
    push(es);
    ds = pop();
    di = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    ds = pop();
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_188e2() // 188e:0002
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    cx = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x188e);
    if (!flags.carry)
        goto loc_18901;
    flags.direction = true;
    ax = 0x0001;
    goto loc_18904;
loc_18901: // 188e:0021
    flags.direction = false;
    ax = 0;
loc_18904: // 188e:0024
    si = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    cx = memoryAGet16(ss, bp + 14);
    if (!ax)
        goto loc_18917;
    si += cx;
    si--;
    di += cx;
    di--;
loc_18917: // 188e:0037
    if (!(di & 0x0001))
        goto loc_18921;
    if (cx == 0)
        goto loc_18930;
    movsb<MemAuto, MemAuto, DirAuto>();
    cx--;
loc_18921: // 188e:0041
    si -= ax;
    di -= ax;
    flags.carry = cx & 1;
    cx >>= 1;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    if (!flags.carry)
        goto loc_18930;
    si += ax;
    di += ax;
    movsb<MemAuto, MemAuto, DirAuto>();
loc_18930: // 188e:0050
    flags.direction = false;
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18956() // 1895:0006
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x43;
    al = memoryAGet(ss, bp + 10);
    cx = memoryAGet16(ss, bp + 12);
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_1896d;
    tx = cx;
    cx = ax;
    ax = tx;
    goto loc_18975;
loc_1896d: // 1895:001d
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x1895);
loc_18975: // 1895:0025
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18977() // 1897:0007
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    bx = memoryAGet16(ss, bp + 6);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 16156) & 0x0200))
        goto loc_18990;
    ax = 0x0001;
    goto loc_189e3;
loc_18990: // 1897:0020
    ax = 0x4400;
    bx = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_189db;
    if (dl & 0x80)
        goto loc_189d7;
    ax = 0x4201;
    cx = 0;
    dx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_189db;
    push(dx);
    push(ax);
    ax = 0x4202;
    cx = 0;
    dx = 0;
    interrupt(0x21);
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    dx = pop();
    cx = pop();
    if (flags.carry)
        goto loc_189db;
    ax = 0x4200;
    interrupt(0x21);
    if (flags.carry)
        goto loc_189db;
    if (dx < memoryAGet16(ss, bp - 2))
        goto loc_189d7;
    if (dx > memoryAGet16(ss, bp - 2))
        goto loc_189d2;
    if (ax < memoryAGet16(ss, bp - 4))
        goto loc_189d7;
loc_189d2: // 1897:0062
    ax = 0x0001;
    goto loc_189e3;
loc_189d7: // 1897:0067
    ax = 0;
    goto loc_189e3;
loc_189db: // 1897:006b
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x1897);
loc_189e3: // 1897:0073
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_189e7() // 189e:0007
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 18);
    dx = memoryAGet16(ss, bp + 6);
    if (ax == dx)
        goto loc_189ff;
    ax = 0xffff;
    goto loc_18acc;
loc_189ff: // 189e:001f
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if ((short)memoryAGet16(es, bx) < (short)0x0000)
        goto loc_18a6d;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0008)
        goto loc_18a2f;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = memoryAGet16(es, bx + 14);
    ax = memoryAGet16(es, bx + 12);
    cx = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    bx += 0x0005;
    if (dx != cx)
        goto loc_18a69;
    if (ax != bx)
        goto loc_18a69;
loc_18a2f: // 189e:004f
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx, 0x0000);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = memoryAGet16(es, bx + 14);
    ax = memoryAGet16(es, bx + 12);
    cx = memoryAGet16(ss, bp + 8);
    bx = memoryAGet16(ss, bp + 6);
    bx += 0x0005;
    if (dx != cx)
        goto loc_18a69;
    if (ax != bx)
        goto loc_18a69;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = memoryAGet16(es, bx + 10);
    ax = memoryAGet16(es, bx + 8);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
loc_18a69: // 189e:0089
    ax = 0;
    goto loc_18acc;
loc_18a6d: // 189e:008d
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    si = memoryAGet16(es, bx + 6);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    si += memoryAGet16(es, bx);
    si++;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) - si);
    push(si);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = memoryAGet16(es, bx + 10);
    ax = memoryAGet16(es, bx + 8);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
    push(dx);
    push(ax);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x1847;
    sub_18476(); // 1847:0006
    assert(cs == 0x189e);
    sp += 0x0008;
    if (ax == si)
        goto loc_18ac8;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0200)
        goto loc_18ac8;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0010);
    ax = 0xffff;
    goto loc_18acc;
loc_18ac8: // 189e:00e8
    ax = 0;
loc_18acc: // 189e:00ec
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18acf() // 18ac:000f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x18af;
    push(ax);
    ax = 0x01dd;
    push(ax);
    push(ds);
    ax = 0x3da0;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(ss);
    ax = bp + 0xa;
    push(ax);
    push(cs);
    cs = 0x18db;
    sub_18de9(); // 18db:0039
    assert(cs == 0x18ac);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18af3() // 18af:0003
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) - 1);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(ss, bp + 6);
    cbw();
    push(ax);
    push(cs);
    cs = 0x18af;
    sub_18b12(); // 18af:0022
    assert(cs == 0x18af);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18b12() // 18af:0022
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0002;
    al = memoryAGet(ss, bp + 6);
    memoryASet(ss, bp - 1, al);
loc_18b1e: // 18af:002e
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + 1);
    if ((short)memoryAGet16(es, bx) >= 0)// stop(/*82 - inc -> jge*/))
        goto loc_18b6e;
    al = memoryAGet(ss, bp - 1);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) + 1);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    bx--;
    memoryASet(es, bx, al);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0008))
        goto loc_18b66;
    if (memoryAGet(ss, bp - 1) == 0x0a)
        goto loc_18b4f;
    if (memoryAGet(ss, bp - 1) != 0x0d)
        goto loc_18b66;
loc_18b4f: // 18af:005f
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    cs = 0x189e;
    sub_189e7(); // 189e:0007
    assert(cs == 0x18af);
    cx = pop();
    cx = pop();
    if (!ax)
        goto loc_18b66;
    ax = 0xffff;
    goto loc_18cb0;
loc_18b66: // 18af:0076
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    goto loc_18cb0;
loc_18b6e: // 18af:007e
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) - 1);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0090)
        goto loc_18b8a;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0002)
        goto loc_18b99;
loc_18b8a: // 18af:009a
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0010);
    ax = 0xffff;
    goto loc_18cb0;
loc_18b99: // 18af:00a9
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0100);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, bx + 6) == 0x0000)
        goto loc_18be6;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, bx) == 0x0000)
        goto loc_18bce;
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    cs = 0x189e;
    sub_189e7(); // 189e:0007
    assert(cs == 0x18af);
    cx = pop();
    cx = pop();
    if (!ax)
        goto loc_18bcc;
    ax = 0xffff;
    goto loc_18cb0;
loc_18bcc: // 18af:00dc
    goto loc_18be0;
loc_18bce: // 18af:00de
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    ax = 0xffff;
    dx = memoryAGet16(es, bx + 6);
    ax -= dx;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, ax);
loc_18be0: // 18af:00f0
    goto loc_18b1e;
    //   gap of 3 bytes
loc_18be6: // 18af:00f6
    if (memoryAGet16(ds, 0x3f4a) != 0x0000)
        goto loc_18c41;
    ax = memoryAGet16(ss, bp + 8);
    bx = 0x3da0;
    cx = ds;
    if (ax != bx)
        goto loc_18c41;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x17e8;
    sub_17e86(); // 17e8:0006
    assert(cs == 0x18af);
    cx = pop();
    if (ax)
        goto loc_18c15;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xfdff);
loc_18c15: // 18af:0125
    ax = 0x0200;
    push(ax);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0200))
        goto loc_18c29;
    ax = 0x0002;
    goto loc_18c2b;
loc_18c29: // 18af:0139
    ax = 0;
loc_18c2b: // 18af:013b
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(cs);
    cs = 0x17e9;
    sub_17e9e(); // 17e9:000e
    assert(cs == 0x18af);
    sp += 0x000c;
    goto loc_18b99;
loc_18c41: // 18af:0151
    if (memoryAGet(ss, bp - 1) != 0x0a)
        goto loc_18c71;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0040)
        goto loc_18c71;
    ax = 0x0001;
    push(ax);
    push(ds);
    ax = 0x3f88;
    push(ax);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x185d;
    sub_185dc(); // 185d:000c
    assert(cs == 0x18af);
    sp += 0x0008;
    if (ax != 0x0001)
        goto loc_18c90;
loc_18c71: // 18af:0181
    ax = 0x0001;
    push(ax);
    push(ss);
    ax = bp + 0x6;
    push(ax);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x185d;
    sub_185dc(); // 185d:000c
    assert(cs == 0x18af);
    sp += 0x0008;
    if (ax == 0x0001)
        goto loc_18ca9;
loc_18c90: // 18af:01a0
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0200)
        goto loc_18ca9;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0010);
    ax = 0xffff;
    goto loc_18cb0;
loc_18ca9: // 18af:01b9
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
loc_18cb0: // 18af:01c0
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_18ccd() // 18af:01dd
{
    CStackGuardFar sg(10, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 10);
    si++;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0008))
        goto loc_18d0c;
    goto loc_18ce5;
loc_18ce3: // 18af:01f3
loc_18ce5: // 18af:01f5
    si--;
    ax = si;
    if (!ax)
        goto loc_18d09;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) + 1);
    al = memoryAGet(es, bx);
    cbw();
    push(ax);
    push(cs);
    sub_18b12(); // 18af:0022
    sp += 0x0006;
    if (ax != 0xffff)
        goto loc_18ce3;
loc_18d09: // 18af:0219
    goto loc_18db4;
loc_18d0c: // 18af:021c
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0040))
        goto loc_18d69;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, bx + 6) == 0x0000)
        goto loc_18d69;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    if (ax >= si)
        goto loc_18d69;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    if (memoryAGet16(es, bx) == 0x0000)
        goto loc_18d4a;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x189e;
    sub_189e7(); // 189e:0007
    assert(cs == 0x18af);
    cx = pop();
    cx = pop();
    if (!ax)
        goto loc_18d4a;
    ax = 0;
    goto loc_18db8;
loc_18d4a: // 18af:025a
    si--;
    push(si);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    push(cs);
    cs = 0x185d;
    sub_185dc(); // 185d:000c
    assert(cs == 0x18af);
    sp += 0x0008;
    di = ax;
    si -= di;
    goto loc_18db4;
loc_18d69: // 18af:0279
    goto loc_18d6d;
loc_18d6b: // 18af:027b
loc_18d6d: // 18af:027d
    si--;
    ax = si;
    if (!ax)
        goto loc_18db4;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + 1);
    if (stop(/*82 - inc -> jge*/))
        goto loc_18d98;
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) + 1);
    al = memoryAGet(es, bx);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) + 1);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    bx--;
    memoryASet(es, bx, al);
    ah = 0x00;
    goto loc_18daf;
loc_18d98: // 18af:02a8
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    bx = memoryAGet16(ss, bp + 12);
    es = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) + 1);
    al = memoryAGet(es, bx);
    push(ax);
    push(cs);
    sub_18af3(); // 18af:0003
    sp += 0x0006;
loc_18daf: // 18af:02bf
    if (ax != 0xffff)
        goto loc_18d6b;
loc_18db4: // 18af:02c4
    ax = si;
loc_18db8: // 18af:02c8
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 10;
}
void sub_18de9() // 18db:0039
{
    CStackGuardFar sg(16, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0096;
    push(si);
    push(di);
    memoryASet16(ss, bp - 86, 0x0000);
    memoryASet(ss, bp - 83, 0x50);
    goto loc_18e3a;
    //   gap of 61 bytes
loc_18e3a: // 18db:008a
    push(es);
    flags.direction = false;
    di = bp - 0x52;
    memoryASet16(ss, bp - 148, di);
    di = memoryAGet16(ss, bp - 148);
    si = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
loc_18e4a: // 18db:009a
    lodsb_es<MemAuto, DirAuto>();
    if (!al)
        goto loc_18e62;
    if (al == 0x25)
        goto loc_18e65;
loc_18e54: // 18db:00a4
    memoryASet(ss, di, al);
    di++;
    tl = memoryAGet(ss, bp - 83);
    memoryASet(ss, bp - 83, memoryAGet(ss, bp - 83) - 1);
    if ((char)tl > 1)
        goto loc_18e4a;
    sub_18e13(); // 18db:0063
    goto loc_18e4a;
loc_18e62: // 18db:00b2
    goto loc_192f9;
loc_18e65: // 18db:00b5
    memoryASet16(ss, bp - 136, si);
    lodsb_es<MemAuto, DirAuto>();
    if (al == 0x25)
        goto loc_18e54;
    memoryASet16(ss, bp - 148, di);
    cx = 0;
    memoryASet16(ss, bp - 138, cx);
    memoryASet16(ss, bp - 150, 0x0020);
    memoryASet(ss, bp - 139, cl);
    memoryASet16(ss, bp - 144, 0xffff);
    memoryASet16(ss, bp - 142, 0xffff);
    goto loc_18e93;
    //   gap of 2 bytes
loc_18e93: // 18db:00e3
    ah = 0;
    dx = ax;
    bx = ax;
    bl -= 0x20;
    if (bl >= 0x60)
        goto loc_18ee8;
    bl = memoryAGet(ds, bx + 16289);
    ax = bx;
    if (ax <= 0x0017)
        goto loc_18eaf;
    goto loc_192e3;
loc_18eaf: // 18db:00ff
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 264)); // 18db:0103
    return;
    //   gap of 48 bytes
loc_18ee8: // 18db:0138
    goto loc_192e3;
    //   gap of 1016 bytes
loc_192e3: // 18db:0533
    si = memoryAGet16(ss, bp - 136);
    es = memoryAGet16(ss, bp + 12);
    di = memoryAGet16(ss, bp - 148);
    al = 0x25;
loc_192f0: // 18db:0540
    sub_18e0a(); // 18db:005a
    lodsb_es<MemAuto, DirAuto>();
    if (al)
        goto loc_192f0;
loc_192f9: // 18db:0549
    if ((char)memoryAGet(ss, bp - 83) >= (char)0x50)
        goto loc_19302;
    sub_18e13(); // 18db:0063
loc_19302: // 18db:0552
    es = pop();
    ax = memoryAGet16(ss, bp - 86);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 16;
}
void sub_18e0a() // 18db:005a
{
    CStackGuard sg(0, false);
    memoryASet(ss, di, al);
    di++;
    memoryASet(ss, bp - 83, memoryAGet(ss, bp - 83) - 1);
    if ((char)memoryAGet(ss, bp - 83) <= 0)
        return;
    push(bx);
    push(cx);
    push(dx);
    push(es);
    ax = bp - 0x52;
    di -= ax;
    push(ss);
    ax = bp - 0x52;
    push(ax);
    push(di);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 18 + 2);
    callIndirect(memoryAGet16(ss, bp + 18 + 2), memoryAGet16(ss, bp + 18));
    assert(cs == 0x18db);
    memoryASet(ss, bp - 83, 0x50);
    memoryASet16(ss, bp - 86, memoryAGet16(ss, bp - 86) + di);
    di = bp - 0x52;
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_18e13() // 18db:0063
{
    CStackGuard sg(0, false);
    push(bx);
    push(cx);
    push(dx);
    push(es);
    ax = bp - 0x52;
    di -= ax;
    push(ss);
    ax = bp - 0x52;
    push(ax);
    push(di);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 18 + 2);
    callIndirect(memoryAGet16(ss, bp + 18 + 2), memoryAGet16(ss, bp + 18));
    assert(cs == 0x18db);
    memoryASet(ss, bp - 83, 0x50);
    memoryASet16(ss, bp - 86, memoryAGet16(ss, bp - 86) + di);
    di = bp - 0x52;
    es = pop();
    dx = pop();
    cx = pop();
    bx = pop();
}
void sub_19310() // 1931:0000
{
    CStackGuardFar sg(0, false);
    push(cs);
    cs = 0x1931;
    sub_19318(); // 1931:0008
    assert(cs == 0x1931);
    cs = pop();
}
void sub_19318() // 1931:0008
{
    CStackGuardFar sg(0, false);
    dx = memoryAGet16(ds, 0x0091);
    ax = memoryAGet16(ds, 0x008f);
    cx = memoryAGet16(ds, 0x008d);
    bx = memoryAGet16(ds, 0x008b);
    push(cs);
    cs = 0x01ed;
    sub_2e3a(); // 01ed:0f6a
    assert(cs == 0x1931);
    flags.carry = (ax + 0xfff8) >= 0x10000;
    ax += 0xfff8;
    dx += 0xffff + flags.carry;
    cs = pop();
}
void sub_19335() // 1933:0005
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1933;
    sub_1960f(); // 1933:02df
    assert(cs == 0x1933);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_19347() // 1933:0017
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    cx = 0;
    bx = 0;
    dx = memoryAGet16(ds, 0x3c86);
    ax = memoryAGet16(ds, 0x3c84);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1933);
    if (flags.zero)
        goto loc_193b5;
    bx = memoryAGet16(ds, 0x3c84);
    es = memoryAGet16(ds, 0x3c84 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ds, 0x3c84);
    es = memoryAGet16(ds, 0x3c84 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 10, dx);
    memoryASet16(es, bx + 8, ax);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
    dx = memoryAGet16(ds, 0x3c86);
    ax = memoryAGet16(ds, 0x3c84);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 10, dx);
    memoryASet16(es, bx + 8, ax);
    goto loc_193e2;
loc_193b5: // 1933:0085
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(ds, 0x3c86, es);
    memoryASet16(ds, 0x3c84, bx);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 10, dx);
    memoryASet16(es, bx + 8, ax);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
loc_193e2: // 1933:00b2
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_193e6() // 1933:00b6
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    dx = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(es, bx);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    flags.carry = (memoryAGet16(es, bx) + ax) >= 0x10000;
    memoryASet16(es, bx, memoryAGet16(es, bx) + ax);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + (dx + flags.carry));
    cx = memoryAGet16(ss, bp + 12);
    bx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ds, 0x3c82);
    ax = memoryAGet16(ds, 0x3c80);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1933);
    if (!flags.zero)
        goto loc_19421;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(ds, 0x3c82, es);
    memoryASet16(ds, 0x3c80, bx);
    goto loc_1944d;
loc_19421: // 1933:00f1
    bx = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    cx = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(es, bx);
    dx = memoryAGet16(ss, bp + 12);
    ax = memoryAGet16(ss, bp + 10);
    push(cs);
    cs = 0x01ed;
    sub_2bad(); // 01ed:0cdd
    assert(cs == 0x1933);
    memoryASet16(ss, bp - 2, dx);
    memoryASet16(ss, bp - 4, ax);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 4, ax);
loc_1944d: // 1933:011d
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(cs);
    cs = 0x1718;
    sub_17196(); // 1718:0016
    assert(cs == 0x1933);
    cx = pop();
    cx = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1945e() // 1933:012e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    cx = memoryAGet16(ds, 0x3c82);
    bx = memoryAGet16(ds, 0x3c80);
    dx = memoryAGet16(ds, 0x3c7e);
    ax = memoryAGet16(ds, 0x3c7c);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1933);
    if (!flags.zero)
        goto loc_194a6;
    push(memoryAGet16(ds, 0x3c7e));
    push(memoryAGet16(ds, 0x3c7c));
    push(cs);
    cs = 0x1749;
    sub_17521(); // 1749:0091
    assert(cs == 0x1933);
    cx = pop();
    cx = pop();
    memoryASet16(ds, 0x3c82, 0x0000);
    memoryASet16(ds, 0x3c80, 0x0000);
    bx = 0;
    es = bx;
    bx = 0;
    memoryASet16(ds, 0x3c7e, es);
    memoryASet16(ds, 0x3c7c, bx);
    goto loc_1953f;
loc_194a6: // 1933:0176
    bx = memoryAGet16(ds, 0x3c80);
    es = memoryAGet16(ds, 0x3c80 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx + 4);
    es = memoryAGet16(es, tx + 4 + 2);
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    dx = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(es, bx);
    ax &= 0x0001;
    dx &= 0x0000;
    dx |= ax;
    if (dx)
        goto loc_19525;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1718;
    sub_17196(); // 1718:0016
    assert(cs == 0x1933);
    cx = pop();
    cx = pop();
    cx = memoryAGet16(ds, 0x3c7e);
    bx = memoryAGet16(ds, 0x3c7c);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1933);
    if (!flags.zero)
        goto loc_19507;
    memoryASet16(ds, 0x3c82, 0x0000);
    memoryASet16(ds, 0x3c80, 0x0000);
    bx = 0;
    es = bx;
    bx = 0;
    memoryASet16(ds, 0x3c7e, es);
    memoryASet16(ds, 0x3c7c, bx);
    goto loc_19516;
loc_19507: // 1933:01d7
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx + 4);
    es = memoryAGet16(es, tx + 4 + 2);
    memoryASet16(ds, 0x3c82, es);
    memoryASet16(ds, 0x3c80, bx);
loc_19516: // 1933:01e6
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(cs);
    cs = 0x1749;
    sub_17521(); // 1749:0091
    assert(cs == 0x1933);
    cx = pop();
    cx = pop();
    goto loc_1953f;
loc_19525: // 1933:01f5
    push(memoryAGet16(ds, 0x3c82));
    push(memoryAGet16(ds, 0x3c80));
    push(cs);
    cs = 0x1749;
    sub_17521(); // 1749:0091
    assert(cs == 0x1933);
    cx = pop();
    cx = pop();
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(ds, 0x3c82, es);
    memoryASet16(ds, 0x3c80, bx);
loc_1953f: // 1933:020f
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_19543() // 1933:0213
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    flags.carry = memoryAGet16(es, bx) < 0x0001;
    memoryASet16(es, bx, memoryAGet16(es, bx) - 0x0001);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) - flags.carry);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    cx = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(es, bx);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    push(cs);
    cs = 0x01ed;
    sub_2bad(); // 01ed:0cdd
    assert(cs == 0x1933);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 8, ax);
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx + 4);
    es = memoryAGet16(es, tx + 4 + 2);
    memoryASet16(ss, bp - 2, es);
    memoryASet16(ss, bp - 4, bx);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    dx = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(es, bx);
    ax &= 0x0001;
    dx &= 0x0000;
    dx |= ax;
    if (dx)
        goto loc_195d7;
    cx = memoryAGet16(ds, 0x3c7e);
    bx = memoryAGet16(ds, 0x3c7c);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    push(cs);
    cs = 0x01ed;
    sub_2c08(); // 01ed:0d38
    assert(cs == 0x1933);
    if (flags.zero)
        goto loc_195d7;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    dx = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(es, bx);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    flags.carry = (memoryAGet16(es, bx) + ax) >= 0x10000;
    memoryASet16(es, bx, memoryAGet16(es, bx) + ax);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + (dx + flags.carry));
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 4, ax);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(ss, bp + 8, es);
    memoryASet16(ss, bp + 6, bx);
    goto loc_195e3;
loc_195d7: // 1933:02a7
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_19347(); // 1933:0017
    cx = pop();
    cx = pop();
loc_195e3: // 1933:02b3
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    dx = memoryAGet16(es, bx + 2);
    ax = memoryAGet16(es, bx);
    ax &= 0x0001;
    dx &= 0x0000;
    dx |= ax;
    if (dx)
        goto loc_1960b;
    push(memoryAGet16(ss, bp - 6));
    push(memoryAGet16(ss, bp - 8));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_193e6(); // 1933:00b6
    sp += 0x0008;
loc_1960b: // 1933:02db
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1960f() // 1933:02df
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    ax |= memoryAGet16(ss, bp + 8);
    if (ax)
        goto loc_1961c;
    goto loc_19657;
loc_1961c: // 1933:02ec
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    cx = 0xffff;
    bx = 0xfff8;
    push(cs);
    cs = 0x01ed;
    sub_2bad(); // 01ed:0cdd
    assert(cs == 0x1933);
    memoryASet16(ss, bp + 8, dx);
    memoryASet16(ss, bp + 6, ax);
    dx = memoryAGet16(ss, bp + 8);
    ax = memoryAGet16(ss, bp + 6);
    if (dx != memoryAGet16(ds, 0x3c82))
        goto loc_1964b;
    if (ax != memoryAGet16(ds, 0x3c80))
        goto loc_1964b;
    push(cs);
    sub_1945e(); // 1933:012e
    goto loc_19657;
loc_1964b: // 1933:031b
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    sub_19543(); // 1933:0213
    sp = bp;
loc_19657: // 1933:0327
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_19659() // 1965:0009
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    ax = 0x4201;
    bx = memoryAGet16(ss, bp + 6);
    cx = 0;
    dx = 0;
    interrupt(0x21);
    if (flags.carry)
        goto loc_19691;
    push(dx);
    push(ax);
    ax = 0x4202;
    cx = 0;
    dx = 0;
    interrupt(0x21);
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    dx = pop();
    cx = pop();
    if (flags.carry)
        goto loc_19691;
    ax = 0x4200;
    interrupt(0x21);
    if (flags.carry)
        goto loc_19691;
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    goto loc_1969a;
loc_19691: // 1965:0041
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x1965);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
loc_1969a: // 1965:004a
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1969e() // 1969:000e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x18af;
    push(ax);
    ax = 0x01dd;
    push(ax);
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(ss);
    ax = bp + 0xe;
    push(ax);
    push(cs);
    cs = 0x18db;
    sub_18de9(); // 18db:0039
    assert(cs == 0x1969);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_196c3() // 196c:0003
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ss);
    ax = bp + 0xe;
    push(ax);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    ax = 0x1a7c;
    push(ax);
    ax = 0x0008;
    push(ax);
    ax = 0x17c0;
    push(ax);
    ax = 0x00f4;
    push(ax);
    push(cs);
    cs = 0x198b;
    sub_198b7(); // 198b:0007
    assert(cs == 0x196c);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_19859() // 1985:0009
{
    CStackGuardFar sg(0, false);
    if (memoryAGet(ds, 0x401a) == 0x00)
        goto loc_1986a;
    memoryASet(ds, 0x401a, 0x00);
    al = memoryAGet(ds, 0x401b);
    goto loc_1986f;
loc_1986a: // 1985:001a
    ax = 0x0700;
    interrupt(0x21);
loc_1986f: // 1985:001f
    ah = 0x00;
    cs = pop();
}
void sub_198b7() // 198b:0007
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x002a;
    push(si);
    push(di);
    memoryASet16(ss, bp - 40, 0x0000);
    memoryASet16(ss, bp - 38, 0x0000);
    goto loc_198e7;
    //   gap of 28 bytes
loc_198e7: // 198b:0037
    push(es);
    flags.direction = false;
    si = memoryAGet16(ss, bp + 18);
loc_198ec: // 198b:003c
    es = memoryAGet16(ss, bp + 20);
    lodsb_es<MemAuto, DirAuto>();
    if (!al)
        goto loc_19962;
    if (al == 0x25)
        goto loc_19965;
    cbw();
    tx = di;
    di = ax;
    ax = tx;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    if ((short)ax < 0)
        goto loc_19936;
    if (di & 0x8000)
        goto loc_1994b;
    if (memoryAGet(ds, di + 16412) != 0x01)
        goto loc_1994b;
loc_19918: // 198b:0068
    tx = bx;
    bx = ax;
    ax = tx;
    if (bl & 0x80)
        goto loc_19939;
    if (memoryAGet(ds, bx + 16412) != 0x01)
        goto loc_19939;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    if ((short)ax > 0)
        goto loc_19918;
loc_19936: // 198b:0086
    goto loc_19d0c;
loc_19939: // 198b:0089
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(bx);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) - 1);
    goto loc_198ec;
loc_1994b: // 198b:009b
    if (ax == di)
        goto loc_198ec;
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) - 1);
    goto loc_19d24;
loc_19962: // 198b:00b2
    goto loc_19d24;
loc_19965: // 198b:00b5
    memoryASet16(ss, bp - 34, 0xffff);
    es = memoryAGet16(ss, bp + 20);
    memoryASet(ss, bp - 41, 0x20);
    lodsb_es<MemAuto, DirAuto>();
    cbw();
    memoryASet16(ss, bp + 18, si);
    tx = di;
    di = ax;
    ax = tx;
    if ((short)di < 0)
        goto loc_199c4;
    bl = memoryAGet(ds, di + 16412);
    bh = 0;
    ax = bx;
    if (ax <= 0x0015)
        goto loc_1998c;
    goto loc_19d0c;
loc_1998c: // 198b:00dc
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 229)); // 198b:00e0
    assert(pop() == 0x7777); // TODO: cico must preserve same exit procedure
    cs = pop();
    return;
    //   gap of 47 bytes
loc_199c4: // 198b:0114
    goto loc_19d24;
    //   gap of 837 bytes
loc_19d0c: // 198b:045c
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    ax = 0xffff;
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    flags.carry = memoryAGet16(ss, bp - 40) < 0x0001;
    memoryASet16(ss, bp - 40, memoryAGet16(ss, bp - 40) - flags.carry);
loc_19d24: // 198b:0474
    es = pop();
    ax = memoryAGet16(ss, bp - 40);
    goto loc_19db9;
    //   gap of 142 bytes
loc_19db9: // 198b:0509
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7771);
    cs = pop();
}
void sub_198cc() // 198b:001c
{
    CStackGuard sg(0, false);
    di = memoryAGet16(ss, bp + 22);
    es = memoryAGet16(ss, bp + 22 + 2);
    if (!(memoryAGet(ss, bp - 41) & 0x20))
        goto loc_198dd;
    tx = di;
    di = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    memoryASet16(ss, bp + 22, memoryAGet16(ss, bp + 22) + 0x0004);
    return;
loc_198dd: // 198b:002d
    di = memoryAGet16(es, di);
    push(ds);
    es = pop();
    memoryASet16(ss, bp + 22, memoryAGet16(ss, bp + 22) + 0x0002);
}
void sub_199e7() // 198b:0137
{
    // no guard, jump target
    //    CStackGuardFar sg(0, true);
    //    push(0x7777);
    goto loc_199e7;
loc_19971: // 198b:00c1
    lodsb_es<MemAuto, DirAuto>();
    cbw();
    memoryASet16(ss, bp + 18, si);
    tx = di;
    di = ax;
    ax = tx;
    if ((short)di < 0)
        goto loc_199c4;
    bl = memoryAGet(ds, di + 16412);
    bh = 0;
    ax = bx;
    if (ax <= 0x0015)
        goto loc_1998c;
    goto loc_19d0c;
loc_1998c: // 198b:00dc
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 229)); // 198b:00e0
    return;
    //   gap of 47 bytes
loc_199c4: // 198b:0114
    goto loc_19d24;
    //   gap of 32 bytes
loc_199e7: // 198b:0137
    memoryASet(ss, bp - 41, memoryAGet(ss, bp - 41) | 0x04);
    goto loc_19971;
    //   gap of 799 bytes
loc_19d0c: // 198b:045c
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    ax = 0xffff;
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    flags.carry = memoryAGet16(ss, bp - 40) < 0x0001;
    memoryASet16(ss, bp - 40, memoryAGet16(ss, bp - 40) - flags.carry);
loc_19d24: // 198b:0474
    es = pop();
    ax = memoryAGet16(ss, bp - 40);
    goto loc_19db9;
    //   gap of 142 bytes
loc_19db9: // 198b:0509
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
}
void sub_19a15() // 198b:0165
{
    // no guard, jump target
    goto loc_19a15;
loc_198e9: // 198b:0039
    si = memoryAGet16(ss, bp + 18);
loc_198ec: // 198b:003c
    es = memoryAGet16(ss, bp + 20);
    lodsb_es<MemAuto, DirAuto>();
    if (!al)
        goto loc_19962;
    if (al == 0x25)
        goto loc_19965;
    cbw();
    tx = di;
    di = ax;
    ax = tx;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    if ((short)ax < 0)
        goto loc_19936;
    if (di & 0x8000)
        goto loc_1994b;
    if (memoryAGet(ds, di + 16412) != 0x01)
        goto loc_1994b;
loc_19918: // 198b:0068
    tx = bx;
    bx = ax;
    ax = tx;
    if (bl & 0x80)
        goto loc_19939;
    if (memoryAGet(ds, bx + 16412) != 0x01)
        goto loc_19939;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    if ((short)ax > 0)
        goto loc_19918;
loc_19936: // 198b:0086
    goto loc_19d0c;
loc_19939: // 198b:0089
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(bx);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) - 1);
    goto loc_198ec;
loc_1994b: // 198b:009b
    if (ax == di)
        goto loc_198ec;
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) - 1);
    goto loc_19d24;
loc_19962: // 198b:00b2
    goto loc_19d24;
loc_19965: // 198b:00b5
    memoryASet16(ss, bp - 34, 0xffff);
    es = memoryAGet16(ss, bp + 20);
    memoryASet(ss, bp - 41, 0x20);
    lodsb_es<MemAuto, DirAuto>();
    cbw();
    memoryASet16(ss, bp + 18, si);
    tx = di;
    di = ax;
    ax = tx;
    if ((short)di < 0)
        goto loc_199c4;
    bl = memoryAGet(ds, di + 16412);
    bh = 0;
    ax = bx;
    if (ax <= 0x0015)
        goto loc_1998c;
    goto loc_19d0c;
loc_1998c: // 198b:00dc
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 229)); // 198b:00e0
    return;
    //   gap of 47 bytes
loc_199c4: // 198b:0114
    goto loc_19d24;
    //   gap of 78 bytes
loc_19a15: // 198b:0165
    si = 0x000a;
    goto loc_19a22;
    //   gap of 8 bytes
loc_19a22: // 198b:0172
    if (di & 0x0020)
        goto loc_19a2c;
    memoryASet(ss, bp - 41, memoryAGet(ss, bp - 41) | 0x04);
loc_19a2c: // 198b:017c
    push(ss);
    ax = bp - 0x24;
    push(ax);
    push(ss);
    ax = bp - 0x26;
    push(ax);
    ax = memoryAGet16(ss, bp - 34);
    ax &= 0x7fff;
    push(ax);
    ax = si;
    push(ax);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x19db;
    sub_19ded(); // 19db:003d
    assert(cs == 0x198b);
    sp += 0x0018;
    if ((short)memoryAGet16(ss, bp - 36) <= (short)0x0000)
        goto loc_19a78;
    if (memoryAGet(ss, bp - 41) & 0x01)
        goto loc_19a75;
    memoryASet16(ss, bp - 40, memoryAGet16(ss, bp - 40) + 1);
    sub_198cc(); // 198b:001c
    stosw<MemAuto, DirAuto>();
    if (!(memoryAGet(ss, bp - 41) & 0x04))
        goto loc_19a75;
    tx = dx;
    dx = ax;
    ax = tx;
    stosw<MemAuto, DirAuto>();
loc_19a75: // 198b:01c5
    goto loc_198e9;
loc_19a78: // 198b:01c8
    if ((short)memoryAGet16(ss, bp - 36) < (short)0x0000)
        goto loc_19a7d;
    goto loc_19d24;
loc_19a7d: // 198b:01cd
    goto loc_19d0c;
    //   gap of 652 bytes
loc_19d0c: // 198b:045c
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    ax = 0xffff;
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    flags.carry = memoryAGet16(ss, bp - 40) < 0x0001;
    memoryASet16(ss, bp - 40, memoryAGet16(ss, bp - 40) - flags.carry);
loc_19d24: // 198b:0474
    es = pop();
    ax = memoryAGet16(ss, bp - 40);
    goto loc_19db9;
    //   gap of 142 bytes
loc_19db9: // 198b:0509
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
//    assert(pop() == 0x7777);
//    cs = pop();
}
void sub_19bd5() // 198b:0325
{
    // jump target
    goto loc_19bd5;
loc_198e9: // 198b:0039
    si = memoryAGet16(ss, bp + 18);
loc_198ec: // 198b:003c
    es = memoryAGet16(ss, bp + 20);
    lodsb_es<MemAuto, DirAuto>();
    if (!al)
        goto loc_19962;
    if (al == 0x25)
        goto loc_19965;
    cbw();
    tx = di;
    di = ax;
    ax = tx;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    if ((short)ax < 0)
        goto loc_19936;
    if (di & 0x8000)
        goto loc_1994b;
    if (memoryAGet(ds, di + 16412) != 0x01)
        goto loc_1994b;
loc_19918: // 198b:0068
    tx = bx;
    bx = ax;
    ax = tx;
    if (bl & 0x80)
        goto loc_19939;
    if (memoryAGet(ds, bx + 16412) != 0x01)
        goto loc_19939;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    if ((short)ax > 0)
        goto loc_19918;
loc_19936: // 198b:0086
    goto loc_19d0c;
loc_19939: // 198b:0089
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(bx);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) - 1);
    goto loc_198ec;
loc_1994b: // 198b:009b
    if (ax == di)
        goto loc_198ec;
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) - 1);
    goto loc_19d24;
loc_19962: // 198b:00b2
    goto loc_19d24;
loc_19965: // 198b:00b5
    memoryASet16(ss, bp - 34, 0xffff);
    es = memoryAGet16(ss, bp + 20);
    memoryASet(ss, bp - 41, 0x20);
    lodsb_es<MemAuto, DirAuto>();
    cbw();
    memoryASet16(ss, bp + 18, si);
    tx = di;
    di = ax;
    ax = tx;
    if ((short)di < 0)
        goto loc_199c4;
    bl = memoryAGet(ds, di + 16412);
    bh = 0;
    ax = bx;
    if (ax <= 0x0015)
        goto loc_1998c;
    goto loc_19d0c;
loc_1998c: // 198b:00dc
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 229)); // 198b:00e0
    return;
    //   gap of 47 bytes
loc_199c4: // 198b:0114
    goto loc_19d24;
    //   gap of 526 bytes
loc_19bd5: // 198b:0325
    if (memoryAGet(ss, bp - 41) & 0x01)
        goto loc_19bde;
    sub_198cc(); // 198b:001c
loc_19bde: // 198b:032e
    si = memoryAGet16(ss, bp - 34);
    if ((short)si >= 0)
        goto loc_19be8;
    si = 0x0001;
loc_19be8: // 198b:0338
    if (si == 0)
        goto loc_19c08;
loc_19bea: // 198b:033a
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(es);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    es = pop();
    if (memoryAGet(ss, bp - 41) & 0x01)
        goto loc_19c01;
    stosb<MemAuto, DirAuto>();
loc_19c01: // 198b:0351
    if ((short)ax < 0)
        goto loc_19c14;
    tx = si;
    si--;
    if ((short)tx > 1)
        goto loc_19bea;
loc_19c08: // 198b:0358
    if (memoryAGet(ss, bp - 41) & 0x01)
        goto loc_19c11;
    memoryASet16(ss, bp - 40, memoryAGet16(ss, bp - 40) + 1);
loc_19c11: // 198b:0361
    goto loc_198e9;
loc_19c14: // 198b:0364
    goto loc_19d0c;
    //   gap of 245 bytes
loc_19d0c: // 198b:045c
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    ax = 0xffff;
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    flags.carry = memoryAGet16(ss, bp - 40) < 0x0001;
    memoryASet16(ss, bp - 40, memoryAGet16(ss, bp - 40) - flags.carry);
loc_19d24: // 198b:0474
    es = pop();
    ax = memoryAGet16(ss, bp - 40);
    goto loc_19db9;
    //   gap of 142 bytes
loc_19db9: // 198b:0509
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
//    assert(pop() == 0x7777);
//    cs = pop();
}
void sub_19c17() // 198b:0367
{
    // jump targer
    goto loc_19c17;
loc_198e9: // 198b:0039
    si = memoryAGet16(ss, bp + 18);
loc_198ec: // 198b:003c
    es = memoryAGet16(ss, bp + 20);
    lodsb_es<MemAuto, DirAuto>();
    if (!al)
        goto loc_19962;
    if (al == 0x25)
        goto loc_19965;
    cbw();
    tx = di;
    di = ax;
    ax = tx;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    if ((short)ax < 0)
        goto loc_19936;
    if (di & 0x8000)
        goto loc_1994b;
    if (memoryAGet(ds, di + 16412) != 0x01)
        goto loc_1994b;
loc_19918: // 198b:0068
    tx = bx;
    bx = ax;
    ax = tx;
    if (bl & 0x80)
        goto loc_19939;
    if (memoryAGet(ds, bx + 16412) != 0x01)
        goto loc_19939;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    if ((short)ax > 0)
        goto loc_19918;
loc_19936: // 198b:0086
    goto loc_19d0c;
loc_19939: // 198b:0089
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(bx);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) - 1);
    goto loc_198ec;
loc_1994b: // 198b:009b
    if (ax == di)
        goto loc_198ec;
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) - 1);
    goto loc_19d24;
loc_19962: // 198b:00b2
    goto loc_19d24;
loc_19965: // 198b:00b5
    memoryASet16(ss, bp - 34, 0xffff);
    es = memoryAGet16(ss, bp + 20);
    memoryASet(ss, bp - 41, 0x20);
    lodsb_es<MemAuto, DirAuto>();
    cbw();
    memoryASet16(ss, bp + 18, si);
    tx = di;
    di = ax;
    ax = tx;
    if ((short)di < 0)
        goto loc_199c4;
    bl = memoryAGet(ds, di + 16412);
    bh = 0;
    ax = bx;
    if (ax <= 0x0015)
        goto loc_1998c;
    goto loc_19d0c;
loc_1998c: // 198b:00dc
    bx = ax;
    bx <<= 1;
    jumpIndirect(cs, memoryAGet16(cs, bx + 229)); // 198b:00e0
    return;
    //   gap of 47 bytes
loc_199c4: // 198b:0114
    goto loc_19d24;
    //   gap of 592 bytes
loc_19c17: // 198b:0367
    push(es);
    ax = 0;
    flags.direction = false;
    push(ss);
    es = pop();
    di = bp - 0x20;
    cx = 0x0010;
    rep_stosw<MemAuto, DirAuto>();
    es = pop();
    lodsb_es<MemAuto, DirAuto>();
    memoryASet(ss, bp - 41, memoryAGet(ss, bp - 41) & 0xef);
    if (al != 0x5e)
        goto loc_19c36;
    memoryASet(ss, bp - 41, memoryAGet(ss, bp - 41) | 0x10);
    lodsb_es<MemAuto, DirAuto>();
loc_19c36: // 198b:0386
    ah = 0x00;
loc_19c38: // 198b:0388
    dl = al;
    di = ax;
    cl = 0x03;
    di >>= cl;
    cx = 0x0107;
    cl &= dl;
    ch <<= cl;
    memoryASet(ss, bp + di + 65504, memoryAGet(ss, bp + di + 65504) | ch);
loc_19c4a: // 198b:039a
    lodsb_es<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_19c79;
    if (al == 0x5d)
        goto loc_19c7c;
    if (al != 0x2d)
        goto loc_19c38;
    if (dl > memoryAGet(es, si))
        goto loc_19c38;
    if (memoryAGet(es, si) == 0x5d)
        goto loc_19c38;
    lodsb_es<MemAuto, DirAuto>();
    al -= dl;
    if (al == 0)
        goto loc_19c4a;
    dl += al;
loc_19c6b: // 198b:03bb
    flags.carry = !!(ch & 0x80);
    ch = rol(ch, 0x01);
    di += flags.carry;
    memoryASet(ss, bp + di + 65504, memoryAGet(ss, bp + di + 65504) | ch);
    al--;
    if (al != 0)
        goto loc_19c6b;
    goto loc_19c4a;
loc_19c79: // 198b:03c9
    goto loc_19d24;
loc_19c7c: // 198b:03cc
    memoryASet16(ss, bp + 18, si);
    memoryASet16(ss, bp - 34, memoryAGet16(ss, bp - 34) & 0x7fff);
    si = memoryAGet16(ss, bp - 34);
    if (memoryAGet(ss, bp - 41) & 0x01)
        goto loc_19c90;
    sub_198cc(); // 198b:001c
loc_19c90: // 198b:03e0
    tx = si;
    si--;
    if ((short)tx < 1)
        goto loc_19ceb;
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) + 1);
    push(es);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x198b);
    cx = pop();
    cx = pop();
    es = pop();
    if ((short)ax < 0)
        goto loc_19cfa;
    tx = si;
    si = ax;
    ax = tx;
    bx = si;
    cl = 0x03;
    si >>= cl;
    cx = 0x0107;
    cl &= bl;
    ch <<= cl;
    tx = si;
    si = ax;
    ax = tx;
    tx = bx;
    bx = ax;
    ax = tx;
    if (!(memoryAGet(ss, bp + si + 65504) & ch))
        goto loc_19cc4;
    if (!(memoryAGet(ss, bp - 41) & 0x10))
        goto loc_19cca;
    goto loc_19cd3;
loc_19cc4: // 198b:0414
    if (!(memoryAGet(ss, bp - 41) & 0x10))
        goto loc_19cd3;
loc_19cca: // 198b:041a
    if (memoryAGet(ss, bp - 41) & 0x01)
        goto loc_19c90;
    stosb<MemAuto, DirAuto>();
    goto loc_19c90;
loc_19cd3: // 198b:0423
    push(es);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    es = pop();
    memoryASet16(ss, bp - 38, memoryAGet16(ss, bp - 38) - 1);
    si++;
    if ((short)si >= (short)memoryAGet16(ss, bp - 34))
        goto loc_19cf4;
loc_19ceb: // 198b:043b
    if (memoryAGet(ss, bp - 41) & 0x01)
        goto loc_19cf7;
    memoryASet16(ss, bp - 40, memoryAGet16(ss, bp - 40) + 1);
loc_19cf4: // 198b:0444
    al = 0x00;
    stosb<MemAuto, DirAuto>();
loc_19cf7: // 198b:0447
    goto loc_198e9;
loc_19cfa: // 198b:044a
    si++;
    if ((short)si >= (short)memoryAGet16(ss, bp - 34))
        goto loc_19d0c;
    if (memoryAGet(ss, bp - 41) & 0x01)
        goto loc_19d0c;
    al = 0x00;
    stosb<MemAuto, DirAuto>();
    memoryASet16(ss, bp - 40, memoryAGet16(ss, bp - 40) + 1);
loc_19d0c: // 198b:045c
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    ax = 0xffff;
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x198b);
    sp += 0x0006;
    flags.carry = memoryAGet16(ss, bp - 40) < 0x0001;
    memoryASet16(ss, bp - 40, memoryAGet16(ss, bp - 40) - flags.carry);
loc_19d24: // 198b:0474
    es = pop();
    ax = memoryAGet16(ss, bp - 40);
    goto loc_19db9;
    //   gap of 142 bytes
loc_19db9: // 198b:0509
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
}
void sub_19dbf() // 19db:000f+carry
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bx);
    tl = bl;
    bl -= 0x30;
    if (tl < 0x30)
        goto loc_19de8;
    if (bl <= 0x09)
        goto loc_19ddc;
    if (bl > 0x2a)
        goto loc_19dd4;
    bl -= 0x07;
    goto loc_19dd7;
loc_19dd4: // 19db:0024
    bl -= 0x27;
loc_19dd7: // 19db:0027
    if (bl <= 0x09)
        goto loc_19de8;
loc_19ddc: // 19db:002c
    if (bl >= cl)
        goto loc_19de8;
    sp += 0x0002;
    flags.carry = false;
    bh = 0x00;
loc_19de6: // 19db:0036
    goto loc_19dec;
loc_19de8: // 19db:0038
    bx = pop();
    flags.carry = true;
    goto loc_19de6;
loc_19dec: // 19db:003c
    assert(pop() == 0x7777);
}
void sub_19ded() // 19db:003d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    memoryASet(ss, bp - 5, 0x00);
    memoryASet16(ss, bp - 4, 0x0000);
    memoryASet16(ss, bp - 2, 0x0001);
    push(es);
    di = 0x3c8b;
loc_19e07: // 19db:0057
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x19db);
    cx = pop();
    cx = pop();
    if ((short)ax < 0)
        goto loc_19e87;
    cbw();
    tx = bx;
    bx = ax;
    ax = tx;
    if (bl & 0x80)
        goto loc_19e25;
    if (memoryAGet(ds, bx + di) & 0x01)
        goto loc_19e07;
loc_19e25: // 19db:0075
    tx = bx;
    bx = ax;
    ax = tx;
    tx = memoryAGet16(ss, bp + 20);
    memoryASet16(ss, bp + 20, memoryAGet16(ss, bp + 20) - 1);
    if ((short)tx < 1)
        goto loc_19e8e;
    if (al == 0x2b)
        goto loc_19e36;
    if (al != 0x2d)
        goto loc_19e4d;
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_19e36: // 19db:0086
    tx = memoryAGet16(ss, bp + 20);
    memoryASet16(ss, bp + 20, memoryAGet16(ss, bp + 20) - 1);
    if ((short)tx < 1)
        goto loc_19e8e;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x19db);
    cx = pop();
    cx = pop();
    if ((short)ax < 0)
        goto loc_19e87;
loc_19e4d: // 19db:009d
    si = 0;
    di = si;
    cx = memoryAGet16(ss, bp + 18);
    if (cx == 0)
        goto loc_19eac;
    if (cx > 0x0024)
        goto loc_19e8e;
    if (cl < 0x02)
        goto loc_19e8e;
    if (al != 0x30)
        goto loc_19edc;
    if (cl != 0x10)
        goto loc_19eda;
    tx = memoryAGet16(ss, bp + 20);
    memoryASet16(ss, bp + 20, memoryAGet16(ss, bp + 20) - 1);
    if ((short)tx < 1)
        goto loc_19ea9;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x19db);
    cx = pop();
    cx = pop();
    if (al == 0x78)
        goto loc_19eda;
    if (al == 0x58)
        goto loc_19eda;
    goto loc_19f06;
loc_19e87: // 19db:00d7
    memoryASet16(ss, bp - 2, 0xffff);
    goto loc_19e93;
loc_19e8e: // 19db:00de
    memoryASet16(ss, bp - 2, 0x0000);
loc_19e93: // 19db:00e3
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x19db);
    sp += 0x0006;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) - 1);
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    goto loc_19f60;
loc_19ea9: // 19db:00f9
    goto loc_19f50;
loc_19eac: // 19db:00fc
    memoryASet16(ss, bp + 18, 0x000a);
    if (al != 0x30)
        goto loc_19edc;
    tx = memoryAGet16(ss, bp + 20);
    memoryASet16(ss, bp + 20, memoryAGet16(ss, bp + 20) - 1);
    if ((short)tx < 1)
        goto loc_19ea9;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x19db);
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp + 18, 0x0008);
    if (al == 0x78)
        goto loc_19ed5;
    if (al != 0x58)
        goto loc_19f06;
loc_19ed5: // 19db:0125
    memoryASet16(ss, bp + 18, 0x0010);
loc_19eda: // 19db:012a
    goto loc_19ef3;
loc_19edc: // 19db:012c
    cx = memoryAGet16(ss, bp + 18);
    tx = bx;
    bx = ax;
    ax = tx;
    sub_19dbf(); // 19db:000f
    tx = bx;
    bx = ax;
    ax = tx;
    if (flags.carry)
        goto loc_19e8e;
    tx = si;
    si = ax;
    ax = tx;
    goto loc_19ef3;
loc_19ee9: // 19db:0139
    tx = si;
    si = ax;
    ax = tx;
    mul(memoryAGet16(ss, bp + 18));
    flags.carry = (si + ax) >= 0x10000;
    si += ax;
    di += dx + flags.carry;
    if (di != 0)
        goto loc_19f23;
loc_19ef3: // 19db:0143
    tx = memoryAGet16(ss, bp + 20);
    memoryASet16(ss, bp + 20, memoryAGet16(ss, bp + 20) - 1);
    if ((short)tx < 1)
        goto loc_19f50;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x19db);
    cx = pop();
    cx = pop();
loc_19f06: // 19db:0156
    cx = memoryAGet16(ss, bp + 18);
    tx = bx;
    bx = ax;
    ax = tx;
    sub_19dbf(); // 19db:000f
    tx = bx;
    bx = ax;
    ax = tx;
    if (!flags.carry)
        goto loc_19ee9;
    goto loc_19f40;
loc_19f12: // 19db:0162
    tx = si;
    si = ax;
    ax = tx;
    mul(cx);
    tx = di;
    di = ax;
    ax = tx;
    tx = dx;
    dx = cx;
    cx = tx;
    mul(dx);
    flags.carry = (si + di) >= 0x10000;
    si += di;
    tl = flags.carry;
    flags.carry = (ax + cx + tl) >= 0x10000;
    ax += cx + tl;
    tx = di;
    di = ax;
    ax = tx;
    dl += dh + flags.carry;
    if (dl != 0)
        goto loc_19f75;
loc_19f23: // 19db:0173
    tx = memoryAGet16(ss, bp + 20);
    memoryASet16(ss, bp + 20, memoryAGet16(ss, bp + 20) - 1);
    if ((short)tx < 1)
        goto loc_19f50;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(cs);
    cs = memoryAGet16(ss, bp + 6 + 2);
    callIndirect(memoryAGet16(ss, bp + 6 + 2), memoryAGet16(ss, bp + 6));
    assert(cs == 0x19db);
    cx = pop();
    cx = pop();
    cx = memoryAGet16(ss, bp + 18);
    tx = bx;
    bx = ax;
    ax = tx;
    sub_19dbf(); // 19db:000f
    tx = bx;
    bx = ax;
    ax = tx;
    if (!flags.carry)
        goto loc_19f12;
loc_19f40: // 19db:0190
    push(memoryAGet16(ss, bp + 16));
    push(memoryAGet16(ss, bp + 14));
    push(ax);
    push(cs);
    cs = memoryAGet16(ss, bp + 10 + 2);
    callIndirect(memoryAGet16(ss, bp + 10 + 2), memoryAGet16(ss, bp + 10));
    assert(cs == 0x19db);
    sp += 0x0006;
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) - 1);
loc_19f50: // 19db:01a0
    dx = di;
    tx = si;
    si = ax;
    ax = tx;
    if (memoryAGet(ss, bp - 5) == 0x00)
        goto loc_19f60;
    dx = -dx;
    flags.carry = ax != 0;
    ax = -ax;
    dx -= flags.carry;
loc_19f60: // 19db:01b0
    di = memoryAGet16(ss, bp + 22);
    es = memoryAGet16(ss, bp + 22 + 2);
    bx = memoryAGet16(ss, bp - 4);
    memoryASet16(es, di, memoryAGet16(es, di) + bx);
    di = memoryAGet16(ss, bp + 26);
    es = memoryAGet16(ss, bp + 26 + 2);
    bx = memoryAGet16(ss, bp - 2);
    memoryASet16(es, di, bx);
    es = pop();
    goto loc_19f8b;
loc_19f75: // 19db:01c5
    ax = 0xffff;
    dx = 0x7fff;
    flags.carry = (al + memoryAGet(ss, bp - 5)) >= 0x100;
    al += memoryAGet(ss, bp - 5);
    tl = flags.carry;
    flags.carry = (ah + 0x00 + tl) >= 0x100;
    ah += tl;
    dx += flags.carry;
    memoryASet16(ss, bp - 2, 0x0002);
    goto loc_19f60;
loc_19f8b: // 19db:01db
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_19f91() // 19f9:0001
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(es);
    push(bp);
    si = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    flags.direction = false;
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    cx = 0x000a;
    bh = 0x00;
    di = 0x3c8b;
loc_19fa7: // 19f9:0017
    bl = memoryAGet(es, si);
    si++;
    if (memoryAGet(ds, bx + di) & 0x01)
        goto loc_19fa7;
    bp = 0x0000;
    if (bl == 0x2b)
        goto loc_19fbe;
    if (bl != 0x2d)
        goto loc_19fc2;
    bp++;
loc_19fbe: // 19f9:002e
    bl = memoryAGet(es, si);
    si++;
loc_19fc2: // 19f9:0032
    if (bl > 0x39)
        goto loc_19ff6;
    tl = bl;
    bl -= 0x30;
    if (tl < 0x30)
        goto loc_19ff6;
    mul(cx);
    flags.carry = (ax + bx) >= 0x10000;
    ax += bx;
    dl += dh + flags.carry;
    if (dl == 0)
        goto loc_19fbe;
    goto loc_19fe8;
loc_19fd6: // 19f9:0046
    di = dx;
    cx = 0x000a;
    mul(cx);
    tx = di;
    di = ax;
    ax = tx;
    tx = cx;
    cx = dx;
    dx = tx;
    mul(dx);
    tx = dx;
    dx = ax;
    ax = tx;
    tx = di;
    di = ax;
    ax = tx;
    flags.carry = (ax + bx) >= 0x10000;
    ax += bx;
    dx += cx + flags.carry;
loc_19fe8: // 19f9:0058
    bl = memoryAGet(es, si);
    si++;
    if (bl > 0x39)
        goto loc_19ff6;
    flags.carry = bl < 0x30;
    bl -= 0x30;
    if (!flags.carry)
        goto loc_19fd6;
loc_19ff6: // 19f9:0066
    tx = bp;
    bp--;
    if ((short)tx < 1)
        goto loc_1a000;
    dx = -dx;
    flags.carry = ax != 0;
    ax = -ax;
    dx -= flags.carry;
loc_1a000: // 19f9:0070
    bp = pop();
    es = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a01b() // 1a01:000b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x35;
    al = memoryAGet(ss, bp + 6);
    interrupt(0x21);
    ax = bx;
    dx = es;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a02d() // 1a01:001d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x25;
    al = memoryAGet(ss, bp + 6);
    push(ds);
    dx = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
    interrupt(0x21);
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a03e() // 1a03:000e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    tx = memoryAGet16(es, bx);
    memoryASet16(es, bx, memoryAGet16(es, bx) - 1);
    if ((short)tx < 1)
        goto loc_1a05f;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) + 1);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    bx--;
    al = memoryAGet(es, bx);
    ah = 0x00;
    goto loc_1a06c;
loc_1a05f: // 1a03:002f
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x17c0;
    sub_17cda(); // 17c0:00da
    assert(cs == 0x1a03);
    cx = pop();
    cx = pop();
loc_1a06c: // 1a03:003c
    memoryASet16(ss, bp - 4, ax);
    if (ax == 0xffff)
        goto loc_1a0b1;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    tx = memoryAGet16(es, bx);
    memoryASet16(es, bx, memoryAGet16(es, bx) - 1);
    if ((short)tx < 1)
        goto loc_1a08f;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) + 1);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    bx--;
    al = memoryAGet(es, bx);
    ah = 0x00;
    goto loc_1a09c;
loc_1a08f: // 1a03:005f
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x17c0;
    sub_17cda(); // 17c0:00da
    assert(cs == 0x1a03);
    cx = pop();
    cx = pop();
loc_1a09c: // 1a03:006c
    memoryASet16(ss, bp - 2, ax);
    if (ax != 0xffff)
        goto loc_1a0ab;
    memoryASet16(ss, bp - 4, 0xffff);
    goto loc_1a0b1;
loc_1a0ab: // 1a03:007b
    al = memoryAGet(ss, bp - 2);
    memoryASet(ss, bp - 3, al);
loc_1a0b1: // 1a03:0081
    ax = memoryAGet16(ss, bp - 4);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a14f() // 1a14:000f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(ss);
    ax = bp - 0x8;
    push(ax);
    push(cs);
    cs = 0x1a71;
    sub_1a71c(); // 1a71:000c
    assert(cs == 0x1a14);
    cx = pop();
    cx = pop();
    push(ss);
    ax = bp - 0x8;
    push(ax);
    push(memoryAGet16(ss, bp + 14));
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x1a14;
    sub_1a183(); // 1a14:0043
    assert(cs == 0x1a14);
    sp += 0x000e;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a183() // 1a14:0043
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    push(ds);
    cx = bp - 0xa;
    memoryASet16(ss, bp - 14, cx);
    memoryASet16(ss, bp - 12, ss);
    memoryASet(ss, bp - 10, 0x55);
    memoryASet(ss, bp - 9, 0xcd);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet(ss, bp - 8, al);
    memoryASet16(ss, bp - 7, 0xcb5d);
    if (al < 0x25)
        goto loc_1a1c1;
    if (al > 0x26)
        goto loc_1a1c1;
    memoryASet(ss, bp - 7, 0x36);
    memoryASet16(ss, bp - 6, 0x068f);
    memoryASet16(ss, bp - 4, cx);
    memoryASet16(ss, bp - 2, 0xcb5d);
loc_1a1c1: // 1a14:0081
    si = memoryAGet16(ss, bp + 16);
    ds = memoryAGet16(ss, bp + 16 + 2);
    push(memoryAGet16(ds, si));
    push(memoryAGet16(ds, si + 6));
    si = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
    ax = memoryAGet16(ds, si);
    bx = memoryAGet16(ds, si + 2);
    cx = memoryAGet16(ds, si + 4);
    dx = memoryAGet16(ds, si + 6);
    di = memoryAGet16(ds, si + 10);
    si = memoryAGet16(ds, si + 8);
    ds = pop();
    es = pop();
    uint8_t buf[] = {
        memoryAGet(memoryAGet16(ss, bp - 14 + 2), memoryAGet16(ss, bp - 14)+0),
        memoryAGet(memoryAGet16(ss, bp - 14 + 2), memoryAGet16(ss, bp - 14)+1),
        memoryAGet(memoryAGet16(ss, bp - 14 + 2), memoryAGet16(ss, bp - 14)+2),
        memoryAGet(memoryAGet16(ss, bp - 14 + 2), memoryAGet16(ss, bp - 14)+3),
        memoryAGet(memoryAGet16(ss, bp - 14 + 2), memoryAGet16(ss, bp - 14)+4)
    };
    assert(buf[0] == 0x55 && buf[1] == 0xcd && buf[3] == 0x5d && buf[4] == 0xcb);
    interrupt(buf[2]);
//    push(cs);
//    cs = memoryAGet16(ss, bp - 14 + 2);
//    callIndirect(memoryAGet16(ss, bp - 14 + 2), memoryAGet16(ss, bp - 14));
//    assert(cs == 0x1a14);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(si);
    push(ds);
    push(es);
    si = memoryAGet16(ss, bp + 16);
    ds = memoryAGet16(ss, bp + 16 + 2);
    memoryASet16(ds, si, pop());
    memoryASet16(ds, si + 6, pop());
    si = memoryAGet16(ss, bp + 12);
    ds = memoryAGet16(ss, bp + 12 + 2);
    memoryASet16(ds, si + 8, pop());
    memoryASet16(ds, si + 14, pop());
    memoryASet16(ds, si + 12, pop());
    memoryASet16(ds, si + 12, memoryAGet16(ds, si + 12) & 0x0001);
    memoryASet16(ds, si + 10, di);
    memoryASet16(ds, si + 6, dx);
    memoryASet16(ds, si + 4, cx);
    memoryASet16(ds, si + 2, bx);
    memoryASet16(ds, si, ax);
    ds = pop();
    if (memoryAGet16(ds, si + 12) == 0)
        goto loc_1a218;
    push(ax);
    push(ax);
    push(cs);
    cs = 0x170e;
    sub_170e3(); // 170e:0003
    assert(cs == 0x1a14);
    ax = pop();
loc_1a218: // 1a14:00d8
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a2cc() // 1a2c:000c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 8);
    out(dx, ax);
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a2fd() // 1a2f:000d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + 1);
    if (stop(/*82 - inc -> jge*/))
        goto loc_1a31e;
    al = memoryAGet(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) + 1);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    bx--;
    memoryASet(es, bx, al);
    ah = 0x00;
    goto loc_1a32e;
loc_1a31e: // 1a2f:002e
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x18af;
    sub_18af3(); // 18af:0003
    assert(cs == 0x1a2f);
    sp = bp;
loc_1a32e: // 1a2f:003e
    if (ax == 0xffff)
        goto loc_1a36b;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + 1);
    if (stop(/*82 - inc -> jge*/))
        goto loc_1a351;
    al = memoryAGet(ss, bp + 7);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) + 1);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    bx--;
    memoryASet(es, bx, al);
    ah = 0x00;
    goto loc_1a361;
loc_1a351: // 1a2f:0061
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 7));
    push(cs);
    cs = 0x18af;
    sub_18af3(); // 18af:0003
    assert(cs == 0x1a2f);
    sp = bp;
loc_1a361: // 1a2f:0071
    if (ax == 0xffff)
        goto loc_1a36b;
    ax = memoryAGet16(ss, bp + 6);
    goto loc_1a370;
loc_1a36b: // 1a2f:007b
    ax = 0xffff;
loc_1a370: // 1a2f:0080
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a383() // 1a37:0013
{
    CStackGuardFar sg(0, false);
    dx = memoryAGet16(ds, 0x409e);
    ax = memoryAGet16(ds, 0x409c);
    cx = 0x015a;
    bx = 0x4e35;
    push(cs);
    cs = 0x01ed;
    sub_2c29(); // 01ed:0d59
    assert(cs == 0x1a37);
    flags.carry = (ax + 0x0001) >= 0x10000;
    ax += 0x0001;
    dx += flags.carry;
    memoryASet16(ds, 0x409e, dx);
    memoryASet16(ds, 0x409c, ax);
    ax = memoryAGet16(ds, 0x409e);
    ax &= 0x7fff;
    cs = pop();
}
void sub_1a71c() // 1a71:000c
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    ax = es;
    si = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    memoryASet16(es, si, ax);
    memoryASet16(es, si + 2, cs);
    memoryASet16(es, si + 4, ss);
    memoryASet16(es, si + 6, ds);
    es = ax;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a739() // 1a73:0009
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    dx = ds;
    flags.direction = false;
    di = memoryAGet16(ss, bp + 10);
    es = memoryAGet16(ss, bp + 10 + 2);
    si = di;
    ax = memoryAGet16(ss, bp + 14);
    cx = ax;
    if (cx == 0)
        goto loc_1a76b;
    bx = ax;
    al = 0;
    repne_scasb<MemAuto, DirAuto>(al);
    bx -= cx;
    cx = bx;
    di = si;
    si = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    repe_cmpsb<MemData, MemData, DirAuto>();
    al = memoryAGet(ds, si + 65535);
    bl = memoryAGet(es, di + 65535);
    ah = 0;
    bh = ah;
    ax -= bx;
loc_1a76b: // 1a73:003b
    ds = dx;
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a773() // 1a77:0003
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    flags.direction = false;
    push(ds);
    si = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    dx = si;
    goto loc_1a78b;
loc_1a780: // 1a77:0010
    al -= 0x61;
    if (al > 0x19)
        goto loc_1a78b;
    al += 0x41;
    memoryASet(ds, si + 65535, al);
loc_1a78b: // 1a77:001b
    lodsb<MemAuto, DirAuto>();
    if (al != 0)
        goto loc_1a780;
    ax = dx;
    dx = ds;
    ds = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a798() // 1a79:0008
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if ((short)memoryAGet16(ss, bp + 6) <= (short)0x0003)
        goto loc_1a7a9;
    if (memoryAGet16(ss, bp + 6) == 0x0007)
        goto loc_1a7a9;
    goto loc_1a7c6;
loc_1a7a9: // 1a79:0019
    if (memoryAGet16(ss, bp + 6) != 0xffff)
        goto loc_1a7b7;
    al = memoryAGet(ds, 0x4008);
    ah = 0x00;
    memoryASet16(ss, bp + 6, ax);
loc_1a7b7: // 1a79:0027
    push(memoryAGet16(ss, bp + 6));
    push(cs);
    cs = 0x01ed;
    sub_2cdd(); // 01ed:0e0d
    assert(cs == 0x1a79);
    cx = pop();
    al = memoryAGet(ds, 0x4007);
    memoryASet(ds, 0x4006, al);
loc_1a7c6: // 1a79:0036
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_1a7c8() // 1a7c:0008
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ss, bp + 6) == 0xffff)
        goto loc_1a829;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) + 1);
    ax = memoryAGet16(es, bx);
    if ((short)ax <= (short)0x0001)
        goto loc_1a7f6;
    al = memoryAGet(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx + 12, memoryAGet16(es, bx + 12) - 1);
    tx = bx;
    bx = memoryAGet16(es, tx + 12);
    es = memoryAGet16(es, tx + 12 + 2);
    memoryASet(es, bx, al);
    ah = 0x00;
    goto loc_1a82e;
    //   gap of 2 bytes
loc_1a7f6: // 1a7c:0036
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    if (memoryAGet16(es, bx) != 0x0001)
        goto loc_1a823;
    dx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    ax += 0x0005;
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx + 14, dx);
    memoryASet16(es, bx + 12, ax);
    al = memoryAGet(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet(es, bx + 5, al);
    ah = 0x00;
    goto loc_1a82e;
    //   gap of 2 bytes
loc_1a823: // 1a7c:0063
    bx = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(es, bx, memoryAGet16(es, bx) - 1);
loc_1a829: // 1a7c:0069
    ax = 0xffff;
loc_1a82e: // 1a7c:006e
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
