#include "cicoctx.h"
using namespace CicoContext;

void sub_1ed0();
void fixReloc(uint16_t seg);

#ifdef callIndirect
#undef callIndirect
#endif

void callIndirect(int seg, int ofs)
{
    assert(0);
}

void start()
{
    headerSize = 0x26d0;
    loadAddress = 0x01ed;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x1490;
    sp = 0x1c00;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/dynablaster/dos", "dyna.exe", 93440);
    fixReloc(cs);
    sub_1ed0();
}
void fixReloc(uint16_t seg)
{
    memory16(0x0000 + seg, 0x0001) += seg; // 0965 -> 0b52
    memory16(0x002c + seg, 0x000c) += seg; // 2403 -> 25f0
    memory16(0x004e + seg, 0x000d) += seg; // 0965 -> 0b52
    memory16(0x0050 + seg, 0x0004) += seg; // 2403 -> 25f0
    memory16(0x0050 + seg, 0x000c) += seg; // 0965 -> 0b52
    memory16(0x0051 + seg, 0x000d) += seg; // 2403 -> 25f0
    memory16(0x0054 + seg, 0x0008) += seg; // 0965 -> 0b52
    memory16(0x0057 + seg, 0x0009) += seg; // 0965 -> 0b52
    memory16(0x00ba + seg, 0x000f) += seg; // 4110 -> 42fd
    memory16(0x00bc + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x00bd + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x00bf + seg, 0x0005) += seg; // 4110 -> 42fd
    memory16(0x00d9 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0135 + seg, 0x000e) += seg; // 0965 -> 0b52
    memory16(0x013f + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x013f + seg, 0x000b) += seg; // 0965 -> 0b52
    memory16(0x0140 + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x0141 + seg, 0x0009) += seg; // 0965 -> 0b52
    memory16(0x014e + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x014e + seg, 0x0009) += seg; // 0965 -> 0b52
    memory16(0x014e + seg, 0x000f) += seg; // 0000 -> 01ed
    memory16(0x0157 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x0159 + seg, 0x0002) += seg; // 0000 -> 01ed
    memory16(0x015a + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x015b + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x015c + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x015f + seg, 0x0005) += seg; // 0965 -> 0b52
    memory16(0x0160 + seg, 0x0008) += seg; // 0965 -> 0b52
    memory16(0x0162 + seg, 0x0005) += seg; // 0965 -> 0b52
    memory16(0x0218 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0219 + seg, 0x0008) += seg; // 4110 -> 42fd
    memory16(0x0245 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0246 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x024d + seg, 0x0001) += seg; // 1463 -> 1650
    memory16(0x024e + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0250 + seg, 0x000b) += seg; // 1463 -> 1650
    memory16(0x02c3 + seg, 0x0005) += seg; // 2403 -> 25f0
    memory16(0x02f8 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x02fa + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x02fd + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x0353 + seg, 0x0003) += seg; // 3170 -> 335d
    memory16(0x039f + seg, 0x0000) += seg; // 2403 -> 25f0
    memory16(0x03a0 + seg, 0x0009) += seg; // 0965 -> 0b52
    memory16(0x03a0 + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x03d0 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x03d3 + seg, 0x000d) += seg; // 4110 -> 42fd
    memory16(0x0573 + seg, 0x0008) += seg; // 2403 -> 25f0
    memory16(0x0579 + seg, 0x0003) += seg; // 2403 -> 25f0
    memory16(0x057a + seg, 0x0003) += seg; // 2403 -> 25f0
    memory16(0x057a + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0591 + seg, 0x0001) += seg; // 2403 -> 25f0
    memory16(0x0595 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x059d + seg, 0x0004) += seg; // 0965 -> 0b52
    memory16(0x05a1 + seg, 0x0003) += seg; // 0965 -> 0b52
    memory16(0x05a3 + seg, 0x0008) += seg; // 0965 -> 0b52
    memory16(0x062b + seg, 0x000d) += seg; // 1463 -> 1650
    memory16(0x062d + seg, 0x0001) += seg; // 1463 -> 1650
    memory16(0x06e6 + seg, 0x0003) += seg; // 50b0 -> 529d
    memory16(0x06e9 + seg, 0x0005) += seg; // 5b9b -> 5d88
    memory16(0x070f + seg, 0x0005) += seg; // 1463 -> 1650
    memory16(0x0721 + seg, 0x0005) += seg; // 0964 -> 0b51
    memory16(0x0723 + seg, 0x000c) += seg; // 0964 -> 0b51
    memory16(0x0726 + seg, 0x0004) += seg; // 0964 -> 0b51
    memory16(0x0728 + seg, 0x0002) += seg; // 0964 -> 0b51
    memory16(0x072f + seg, 0x0007) += seg; // 0964 -> 0b51
    memory16(0x073b + seg, 0x000f) += seg; // 0964 -> 0b51
    memory16(0x073d + seg, 0x000d) += seg; // 0964 -> 0b51
    memory16(0x073e + seg, 0x000a) += seg; // 0964 -> 0b51
    memory16(0x073f + seg, 0x0007) += seg; // 0964 -> 0b51
    memory16(0x0740 + seg, 0x0002) += seg; // 0964 -> 0b51
    memory16(0x0742 + seg, 0x000d) += seg; // 0964 -> 0b51
    memory16(0x075a + seg, 0x0006) += seg; // 077e -> 096b
    memory16(0x075a + seg, 0x000b) += seg; // 0964 -> 0b51
    memory16(0x075b + seg, 0x0008) += seg; // 077e -> 096b
    memory16(0x075c + seg, 0x0003) += seg; // 077e -> 096b
    memory16(0x075c + seg, 0x000b) += seg; // 077e -> 096b
    memory16(0x075c + seg, 0x000f) += seg; // 0964 -> 0b51
    memory16(0x075d + seg, 0x000c) += seg; // 077e -> 096b
    memory16(0x075e + seg, 0x000d) += seg; // 077e -> 096b
    memory16(0x075f + seg, 0x000f) += seg; // 077e -> 096b
    memory16(0x0760 + seg, 0x000b) += seg; // 077e -> 096b
    memory16(0x0761 + seg, 0x0004) += seg; // 077e -> 096b
    memory16(0x0762 + seg, 0x000e) += seg; // 077e -> 096b
    memory16(0x0764 + seg, 0x0002) += seg; // 077e -> 096b
    memory16(0x0764 + seg, 0x000e) += seg; // 077e -> 096b
    memory16(0x0765 + seg, 0x0007) += seg; // 077e -> 096b
    memory16(0x0766 + seg, 0x0006) += seg; // 077e -> 096b
    memory16(0x0766 + seg, 0x000c) += seg; // 0964 -> 0b51
    memory16(0x0769 + seg, 0x000c) += seg; // 0964 -> 0b51
    memory16(0x076a + seg, 0x0009) += seg; // 081a -> 0a07
    memory16(0x076b + seg, 0x0001) += seg; // 081a -> 0a07
    memory16(0x076b + seg, 0x0006) += seg; // 0964 -> 0b51
    memory16(0x076c + seg, 0x0001) += seg; // 081a -> 0a07
    memory16(0x076e + seg, 0x0008) += seg; // 081a -> 0a07
    memory16(0x076f + seg, 0x000b) += seg; // 081a -> 0a07
    memory16(0x0771 + seg, 0x0001) += seg; // 081a -> 0a07
    memory16(0x0771 + seg, 0x000e) += seg; // 081a -> 0a07
    memory16(0x0772 + seg, 0x000e) += seg; // 081a -> 0a07
    memory16(0x0773 + seg, 0x000e) += seg; // 081a -> 0a07
    memory16(0x0774 + seg, 0x0008) += seg; // 081a -> 0a07
    memory16(0x0775 + seg, 0x0001) += seg; // 081a -> 0a07
    memory16(0x0776 + seg, 0x0000) += seg; // 081a -> 0a07
    memory16(0x0776 + seg, 0x000d) += seg; // 081a -> 0a07
    memory16(0x0777 + seg, 0x000a) += seg; // 081a -> 0a07
    memory16(0x0778 + seg, 0x0001) += seg; // 0964 -> 0b51
    memory16(0x0779 + seg, 0x000e) += seg; // 081a -> 0a07
    memory16(0x077a + seg, 0x000f) += seg; // 081a -> 0a07
    memory16(0x077b + seg, 0x0008) += seg; // 081a -> 0a07
    memory16(0x077c + seg, 0x0002) += seg; // 081a -> 0a07
    memory16(0x077d + seg, 0x000b) += seg; // 081a -> 0a07
    memory16(0x0a53 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a53 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a54 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a54 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a55 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a55 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a56 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a56 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a57 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a57 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a58 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a58 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a59 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a59 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a5a + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a5a + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a5b + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a5b + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a5c + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a5c + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a5d + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a5d + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a5e + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a5e + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a5f + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a5f + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a60 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a60 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a61 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a61 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a62 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a62 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a63 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a63 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a64 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a64 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a65 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a65 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a66 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a66 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a67 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a67 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a68 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a68 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a69 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a69 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a6a + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a6a + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a6b + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a6b + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a6c + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a6c + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a6d + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a6d + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a6e + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a6e + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a6f + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a6f + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a70 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a70 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a71 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a71 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a72 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a72 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a73 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a73 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a74 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a74 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a75 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a75 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a76 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a76 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a77 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a77 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a78 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a78 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a79 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a79 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a7a + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a7a + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a7b + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a7b + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a7c + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a7c + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a7d + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a7d + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a7e + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a7e + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a7f + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a7f + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a80 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a80 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a81 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a81 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a82 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a82 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a83 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a83 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a84 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a84 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a85 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a85 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a86 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a86 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0a87 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0a87 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a88 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a88 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a89 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a89 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a8a + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a8a + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a8b + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a8b + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a8c + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a8c + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a8d + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a8d + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a8e + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a8e + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a8f + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a8f + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a90 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a90 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a91 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a91 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a92 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a92 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a93 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a93 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a94 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a94 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a95 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a95 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a96 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a96 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a97 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a97 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a98 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a98 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a99 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a99 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a9a + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a9a + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0a9b + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0a9b + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0a9c + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0a9c + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0a9d + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0a9d + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0a9e + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0a9e + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0a9f + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0a9f + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aa0 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa0 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aa1 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa1 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aa2 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa2 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aa3 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa3 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0aa4 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa4 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aa5 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa5 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aa6 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa6 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aa7 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa7 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aa8 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa8 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aa9 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aa9 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aaa + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aaa + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aab + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aab + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aac + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aac + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aad + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aad + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0aae + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0aae + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0aaf + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0aaf + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0ab0 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ab0 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0ab1 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ab1 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0ab2 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ab2 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0ab3 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ab3 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0ab4 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0ab4 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0ab5 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ab5 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0ab6 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ab6 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ab7 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ab7 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0ae5 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0ae6 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0ae6 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0ae6 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0ae7 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0ae7 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0ae7 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0ae8 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0ae8 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0ae8 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0ae9 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0ae9 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0ae9 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0aea + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0aea + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0aea + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0aeb + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0aeb + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0aeb + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0aec + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0aec + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0aec + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0aed + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0aed + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0aed + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0aee + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0aee + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0aee + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0aef + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0aef + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0aef + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af0 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af0 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af0 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af1 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af1 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af1 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af2 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af2 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af2 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af3 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af3 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af3 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af4 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af4 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af4 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af5 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af5 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af5 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af6 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af6 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af6 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af7 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af7 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af7 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af8 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af8 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af8 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0af9 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0af9 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0af9 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0afa + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0afa + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0afa + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0afb + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0afb + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0afb + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0afc + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0afc + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0afc + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0afd + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0afd + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0afd + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0afe + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0afe + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0afe + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0aff + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0aff + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0aff + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b00 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b00 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b00 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b01 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b01 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b01 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b02 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b02 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b02 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b03 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b03 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b03 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b04 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b04 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b04 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b05 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b05 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b05 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b06 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b06 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b06 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b07 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b07 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b07 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b08 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b08 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b08 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b09 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b09 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b09 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b0a + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b0a + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b0a + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b0b + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b0b + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b0b + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b0c + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b0c + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b0c + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b0d + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b0d + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b0d + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b0e + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b0e + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b0e + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b0f + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b0f + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b0f + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b10 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b10 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b10 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b11 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b11 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b11 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b12 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b12 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b12 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b13 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b13 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b13 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b14 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b14 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b14 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b15 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b15 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b15 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b16 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b16 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b16 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b17 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b17 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b17 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b18 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b18 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b18 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b19 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b19 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b19 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b1a + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b1a + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b1a + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b1b + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b1b + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b1b + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b1c + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b1c + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b1c + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b1d + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b1d + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b1d + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b1e + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b1e + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b1e + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b1f + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b1f + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b1f + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b20 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b20 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b20 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b21 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b21 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b21 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b22 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b22 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b22 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b23 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b23 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b23 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b24 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b24 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b24 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b25 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b25 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b25 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b26 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b26 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b26 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b27 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b27 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b27 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b28 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b28 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b28 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b29 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b29 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b29 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b2a + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b2a + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b2a + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b2b + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b2b + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b2b + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b2c + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b2c + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b2c + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b2d + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b2d + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b2d + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b2e + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b2e + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b2e + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b2f + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b2f + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b2f + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b30 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b30 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b30 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b31 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b31 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b31 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b32 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b32 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b32 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b33 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b33 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b33 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b34 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b34 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b34 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0b35 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b35 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b35 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b36 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b36 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b36 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b37 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b37 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b37 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b38 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b38 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b38 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b39 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b39 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b39 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b3a + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b3a + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b3a + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b3b + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b3b + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b3b + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b3c + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b3c + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b3c + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b3d + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b3d + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b3d + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b3e + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b3e + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b3e + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b3f + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b3f + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b3f + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b40 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b40 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b40 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b41 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b41 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b41 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b42 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b42 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b42 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b43 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b43 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b43 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b44 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b44 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b44 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b45 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b45 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b45 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b46 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b46 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b46 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b47 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b47 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b47 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b48 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b48 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b48 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b49 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b49 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b49 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b4a + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b4a + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b4a + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b4b + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b4b + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b4b + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b4c + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b4c + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b4c + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b4d + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b4d + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b4d + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b4e + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b4e + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b4e + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b4f + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b4f + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b4f + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b50 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b50 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b50 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b51 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b51 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b51 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b52 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b52 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b52 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b53 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b53 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b53 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b54 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b54 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b54 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b55 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b55 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b55 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b56 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b56 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b56 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b57 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b57 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b57 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b58 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b58 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b58 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b59 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b59 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b59 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b5a + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b5a + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b5a + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b5b + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b5b + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b5b + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b5c + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b5c + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b5c + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b5d + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b5d + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b5d + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b5e + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b5e + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b5e + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b5f + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b5f + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b5f + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b60 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b60 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b60 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b61 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b61 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b61 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b62 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b62 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b62 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b63 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b63 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b63 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b64 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b64 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b64 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b65 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b65 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b65 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b66 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b66 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b66 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b67 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b67 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0b67 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0b68 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0b68 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0baa + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0baa + seg, 0x0008) += seg; // 2403 -> 25f0
    memory16(0x0baa + seg, 0x000c) += seg; // 2403 -> 25f0
    memory16(0x0bac + seg, 0x0000) += seg; // 2403 -> 25f0
    memory16(0x0bac + seg, 0x0004) += seg; // 2403 -> 25f0
    memory16(0x0bad + seg, 0x0008) += seg; // 2403 -> 25f0
    memory16(0x0bad + seg, 0x000c) += seg; // 2403 -> 25f0
    memory16(0x0bae + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0baf + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0bb0 + seg, 0x0004) += seg; // 2403 -> 25f0
    memory16(0x0bb0 + seg, 0x0008) += seg; // 2403 -> 25f0
    memory16(0x0bb1 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0bb1 + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0bb3 + seg, 0x0000) += seg; // 2403 -> 25f0
    memory16(0x0bb3 + seg, 0x0004) += seg; // 2403 -> 25f0
    memory16(0x0bb3 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0bb4 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0bb4 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0bb5 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0bb5 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0bb6 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0bb6 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0bb7 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0bb7 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0bb8 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0bb8 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0bb9 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0bb9 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0bba + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0bba + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0bbb + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0bbb + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0bbc + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0bbc + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0bbd + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0bbd + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0bbd + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0bbe + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0bbe + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0bbf + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0bbf + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0bbf + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0bbf + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0bc0 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0bf5 + seg, 0x0004) += seg; // 2403 -> 25f0
    memory16(0x0bf5 + seg, 0x0008) += seg; // 2403 -> 25f0
    memory16(0x0c7b + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0c7b + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0c7b + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0c7b + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0c87 + seg, 0x000c) += seg; // 2403 -> 25f0
    memory16(0x0c88 + seg, 0x0000) += seg; // 2403 -> 25f0
    memory16(0x0c8b + seg, 0x0005) += seg; // 2403 -> 25f0
    memory16(0x0c8b + seg, 0x0009) += seg; // 2403 -> 25f0
    memory16(0x0c8b + seg, 0x000d) += seg; // 1463 -> 1650
    memory16(0x0c8c + seg, 0x0005) += seg; // 1463 -> 1650
    memory16(0x0c8c + seg, 0x000d) += seg; // 1463 -> 1650
    memory16(0x0c8d + seg, 0x0005) += seg; // 1463 -> 1650
    memory16(0x0d0b + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0d0b + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0d0b + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0d0b + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0d0c + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0d0c + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0d0c + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0d46 + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0d46 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0d47 + seg, 0x000c) += seg; // 2403 -> 25f0
    memory16(0x0d48 + seg, 0x0000) += seg; // 2403 -> 25f0
    memory16(0x0d49 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0d49 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0d7f + seg, 0x000b) += seg; // 3170 -> 335d
    memory16(0x0d7f + seg, 0x000f) += seg; // 3170 -> 335d
    memory16(0x0d80 + seg, 0x0003) += seg; // 3170 -> 335d
    memory16(0x0d80 + seg, 0x0007) += seg; // 3170 -> 335d
    memory16(0x0d80 + seg, 0x000b) += seg; // 3170 -> 335d
    memory16(0x0d80 + seg, 0x000f) += seg; // 3170 -> 335d
    memory16(0x0d81 + seg, 0x0003) += seg; // 3170 -> 335d
    memory16(0x0d81 + seg, 0x0007) += seg; // 3170 -> 335d
    memory16(0x0d82 + seg, 0x0003) += seg; // 2403 -> 25f0
    memory16(0x0d82 + seg, 0x0007) += seg; // 2403 -> 25f0
    memory16(0x0d83 + seg, 0x0003) += seg; // 2403 -> 25f0
    memory16(0x0d83 + seg, 0x0007) += seg; // 2403 -> 25f0
    memory16(0x0d84 + seg, 0x0003) += seg; // 2403 -> 25f0
    memory16(0x0d84 + seg, 0x0007) += seg; // 2403 -> 25f0
    memory16(0x0d8c + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0d8c + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0d8d + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0d8d + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0d8d + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0d8e + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0d8e + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0d8e + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0d8f + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0d8f + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0d90 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dab + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0dab + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0dab + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0dac + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0dac + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0dac + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0dac + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0dad + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0dad + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0dad + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0dad + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0dae + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0dae + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0dae + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0dae + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0daf + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0daf + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0daf + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0db0 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0db0 + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0db0 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0db0 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0db1 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0db1 + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0db1 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0db1 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0db2 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0db2 + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0db2 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0db2 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0db3 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0db3 + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0db3 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0db4 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0db4 + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0db4 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0db4 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0db5 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0db5 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0db5 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0db6 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0db6 + seg, 0x0006) += seg; // 4110 -> 42fd
    memory16(0x0db6 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0db6 + seg, 0x000e) += seg; // 4110 -> 42fd
    memory16(0x0db7 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0db7 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0db7 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0db8 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0db8 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0db8 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0db8 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0db9 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0db9 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0db9 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0db9 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dba + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dba + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dba + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dba + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dbb + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dbb + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dbb + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dbc + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dbc + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dbc + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dbd + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dbd + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dbd + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dbd + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dbe + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dbe + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dbe + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dbe + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dbf + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dbf + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dbf + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dbf + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dc0 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dc0 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dc0 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dc0 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dc1 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dc1 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dc1 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dc2 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dc2 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dc2 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dc2 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dc3 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dc3 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dc3 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dc3 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dc4 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dc4 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dc4 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dc4 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dc5 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dc5 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dc5 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dc5 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dc6 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dc6 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dc6 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dc6 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dc7 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dc7 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dc7 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dc8 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dc8 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dc8 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dc8 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dc9 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dc9 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dc9 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dca + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dca + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dca + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dca + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dcb + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dcb + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dcb + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dcb + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dcc + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dcc + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dcc + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dcc + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dcd + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dcd + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dcd + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dce + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dce + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dce + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dce + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dcf + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dcf + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dcf + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dcf + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dd0 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dd0 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dd0 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dd0 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dd1 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dd1 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dd1 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dd1 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dd2 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dd2 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dd2 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dd2 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dd3 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dd3 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dd3 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dd4 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dd4 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dd4 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dd4 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dd5 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dd5 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dd5 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dd6 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dd6 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dd6 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dd6 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dd7 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dd7 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dd7 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dd7 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dd8 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dd8 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dd8 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dd8 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dd9 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dd9 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dd9 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0dda + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0dda + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0dda + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0dda + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ddb + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0ddb + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0ddb + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0ddb + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0ddc + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0ddc + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0ddc + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0ddc + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0ddd + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0ddd + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0ddd + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0ddd + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dde + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dde + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dde + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dde + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0ddf + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0ddf + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0ddf + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0de0 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0de0 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0de0 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0de1 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0de1 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0de1 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0de1 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0de2 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0de2 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0de2 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0de2 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0de3 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0de3 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0de3 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0de3 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0de4 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0de4 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0de4 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0de5 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0de5 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0de5 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0de5 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0de6 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0de6 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0de6 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0de6 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0de7 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0de7 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0de7 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0de7 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0de8 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0de8 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0de8 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0de8 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0de9 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0de9 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0de9 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0de9 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dea + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dea + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dea + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0deb + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0deb + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0deb + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0deb + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dec + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dec + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0dec + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0ded + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0ded + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ded + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0ded + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0dee + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0dee + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0dee + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0dee + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0def + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0def + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0def + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0def + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df0 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df0 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df0 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df0 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df1 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df1 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df1 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df1 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df2 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df2 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df2 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df2 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df3 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df3 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df3 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df3 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df4 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df4 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df4 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df4 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df5 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df5 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df5 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df5 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df6 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df6 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df6 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df6 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df7 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df7 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df7 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df7 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df8 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df8 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df8 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df8 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0df9 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0df9 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0df9 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0df9 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0dfa + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0dfa + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0dfa + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0dfa + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0dfb + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0dfb + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0dfb + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0dfb + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0dfc + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0dfc + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0dfc + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0dfd + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0dfd + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0dfd + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0dfd + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0dfe + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0dfe + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0dfe + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dfe + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0dff + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0dff + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0dff + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0dff + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e00 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e00 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e00 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e00 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e01 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e01 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e01 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e01 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e02 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e02 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e02 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e03 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e03 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e03 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e03 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e04 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e04 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e04 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e05 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e05 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e05 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e05 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e06 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e06 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e06 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e06 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e07 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e07 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e07 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e07 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e08 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e08 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e08 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e09 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e09 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e09 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e09 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e0a + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e0a + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e0a + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e0a + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e0b + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e0b + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e0b + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e0b + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e0c + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e0c + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e0c + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e0c + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e0d + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e0d + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e0d + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e0d + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e0e + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e0e + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e0e + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e0f + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e0f + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e0f + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e0f + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e10 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e10 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e10 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e11 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e11 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e11 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e11 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e12 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e12 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e12 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e12 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e13 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e13 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e13 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e13 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e14 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e14 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e14 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e14 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e15 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e15 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e15 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e16 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e16 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e16 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e16 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e17 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e17 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e17 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e17 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e18 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e18 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e18 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e18 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e19 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e19 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e19 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e19 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e1a + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e1a + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e1a + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e1a + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e1b + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e1b + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e1b + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e1c + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e1c + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e1c + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e1c + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e1d + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e1d + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e1d + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e1e + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e1e + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e1e + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e1e + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e1f + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e1f + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e1f + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e1f + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e20 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e20 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e20 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e20 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e21 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e21 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e21 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e22 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e22 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e22 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e22 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e23 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e23 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e23 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e23 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e24 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e24 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e24 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e25 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e25 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e25 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e25 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e26 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e26 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e26 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e27 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e27 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e27 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e27 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e28 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e28 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e28 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e28 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e29 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e29 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e29 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e29 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e2a + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e2a + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e2a + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e2b + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e2b + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e2b + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e2b + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e2c + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e2c + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e2c + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e2c + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e2d + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e2d + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e2d + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e2d + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e2e + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e2e + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e2e + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e2e + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e2f + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e2f + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e2f + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e2f + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e30 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e30 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e30 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e31 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e31 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e31 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x0e31 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x0e32 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0e32 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x0e32 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e33 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e33 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e33 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e33 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e34 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e34 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e34 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e34 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e35 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e35 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e35 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e35 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e36 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e36 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e36 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e37 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e37 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e37 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e37 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0e38 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0e38 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0e38 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0e3b + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0e3c + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0e3e + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0e3e + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0e40 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0e40 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0e42 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0e42 + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0e44 + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0e45 + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0e47 + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0e47 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0e49 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0e49 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0e4b + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0e4b + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0e4d + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0e4e + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0e50 + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0e50 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0e52 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0e52 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0e54 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0e54 + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0e56 + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x0e57 + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0e59 + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x0e59 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0e5b + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x0e5b + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x0ed0 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0ed3 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0ed4 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ed6 + seg, 0x0000) += seg; // 4110 -> 42fd
    memory16(0x0ed7 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ed8 + seg, 0x0008) += seg; // 4110 -> 42fd
    memory16(0x0ed9 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0edb + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0edc + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0edd + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0ede + seg, 0x000b) += seg; // 1463 -> 1650
    memory16(0x0edf + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0ee1 + seg, 0x0001) += seg; // 1463 -> 1650
    memory16(0x0ee2 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ee3 + seg, 0x0007) += seg; // 1463 -> 1650
    memory16(0x0ee4 + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x0ee5 + seg, 0x000d) += seg; // 3170 -> 335d
    memory16(0x0ee7 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0ee8 + seg, 0x0003) += seg; // 3170 -> 335d
    memory16(0x0ee9 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0eea + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0eeb + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x0eeb + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0eec + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0eec + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0eed + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0eed + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0eee + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0eee + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0eef + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0eef + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef0 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef0 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef1 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef1 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef2 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef2 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef3 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef3 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef4 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef4 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef5 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef5 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef6 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef6 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef7 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef7 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef8 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef8 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0ef9 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0ef9 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0efa + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0efa + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0efb + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0efb + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0efc + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0efc + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0efd + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0efd + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0efe + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0efe + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x0eff + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x0eff + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f00 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f00 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f01 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f01 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f02 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f02 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f03 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f03 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f04 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f04 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f05 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f05 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f06 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f06 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f07 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f07 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f08 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f08 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f09 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f09 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f0a + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f0a + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f0b + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f0b + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f0c + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f0c + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f0d + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f0d + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f0e + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f0e + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f0f + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f0f + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f10 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f10 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f11 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f11 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f12 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f12 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f13 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f13 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f14 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f14 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f15 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f15 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f16 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f16 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f17 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f17 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f18 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f18 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f19 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f19 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f1a + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f1a + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f1b + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f1b + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f1c + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f1c + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f1d + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f1d + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f1e + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f1e + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f1f + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f1f + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f20 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f20 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f21 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f21 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f22 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f22 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f23 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f23 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f24 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f24 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f25 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f25 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f26 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f26 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f27 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f27 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f28 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f28 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f29 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f29 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f2a + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f2a + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f2b + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f2b + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f2c + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f2c + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f2d + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f2d + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f2e + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f2e + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f2f + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0f30 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0f30 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0f31 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0f31 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0f32 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0f32 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0f33 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0f33 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0f34 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0f34 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0f35 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x0f35 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x0f36 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x0f36 + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x0f37 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x0f37 + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x0f38 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x0f38 + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x0f39 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x0f39 + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x0f3a + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x0f3a + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x0f3b + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f3b + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f3c + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f3c + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f3d + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f3d + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f3e + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f3e + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f3f + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f3f + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f40 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f40 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f41 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f41 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f42 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f42 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f43 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f43 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f44 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f44 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f45 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f45 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f46 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f46 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f47 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f47 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f48 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f48 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f49 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f49 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f4a + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f4a + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f4b + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f4b + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f4c + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f4c + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f4d + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f4d + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f4e + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f4e + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f4f + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f4f + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f50 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f50 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f51 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f51 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f52 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f52 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f53 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f53 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f54 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f54 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f55 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f55 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f56 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f56 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f57 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f57 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f58 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f58 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f59 + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f59 + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f5a + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f5a + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f5b + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f5b + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f5c + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f5c + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f5d + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f5d + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f5e + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f5e + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f5f + seg, 0x0004) += seg; // 4110 -> 42fd
    memory16(0x0f5f + seg, 0x000c) += seg; // 4110 -> 42fd
    memory16(0x0f60 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f60 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f61 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f61 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f62 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f62 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f63 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f63 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f64 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f64 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f65 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f65 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f66 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f66 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f67 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f67 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f68 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f68 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f69 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f69 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f6a + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f6a + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f6b + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f6b + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f6c + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f6c + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f6d + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f6d + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f6e + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f6e + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f6f + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f6f + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f70 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f70 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f71 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f71 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f72 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f72 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f73 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f73 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f74 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f74 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f75 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f75 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f76 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f76 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f77 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f77 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f78 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f78 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f79 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f79 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f7a + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f7a + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f7b + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f7b + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f7c + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f7c + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f7d + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f7d + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f7e + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f7e + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f7f + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f7f + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f80 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f80 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f81 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f81 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f82 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f82 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f83 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f83 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f84 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f84 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f85 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f85 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f86 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f86 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f87 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f87 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f88 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f88 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x0f89 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x0f8a + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f8a + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f8b + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f8b + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f8c + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f8c + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f8d + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f8d + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f8e + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f8e + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f8f + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f8f + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f90 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f90 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f91 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f91 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f92 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f92 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f93 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f93 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f94 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f94 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f95 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f95 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f96 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f96 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f97 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f97 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f98 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f98 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f99 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f99 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f9a + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f9a + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f9b + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f9b + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f9c + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f9c + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f9d + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f9d + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f9e + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f9e + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0f9f + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0f9f + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa0 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa0 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa1 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa1 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa2 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa2 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa3 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa3 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa4 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa4 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa5 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa5 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa6 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa6 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa7 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa7 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa8 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa8 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fa9 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fa9 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0faa + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0faa + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fab + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fab + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fac + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fac + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fad + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fad + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fae + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fae + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0faf + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0faf + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb0 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb0 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb1 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb1 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb2 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb2 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb3 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb3 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb4 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb4 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb5 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb5 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb6 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb6 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb7 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb7 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb8 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb8 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fb9 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fb9 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fba + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fba + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fbb + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fbb + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fbc + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fbc + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fbd + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fbd + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fbe + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fbe + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fbf + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fbf + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc0 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc0 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc1 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc1 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc2 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc2 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc3 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc3 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc4 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc4 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc5 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc5 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc6 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc6 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc7 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc7 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc8 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc8 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fc9 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x0fc9 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x0fca + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fca + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fcb + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fcb + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fcc + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fcc + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fcd + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fcd + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fce + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fce + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fcf + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fcf + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd0 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd0 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd1 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd1 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd2 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd2 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd3 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd3 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd4 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd4 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd5 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd5 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd6 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd6 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd7 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd7 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd8 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd8 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fd9 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fd9 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fda + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fda + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fdb + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fdb + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fdc + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fdc + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fdd + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fdd + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fde + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fde + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fdf + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fdf + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe0 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe0 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe1 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe1 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe2 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe2 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe3 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe3 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe4 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe4 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe5 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe5 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe6 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe6 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe7 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe7 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe8 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe8 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fe9 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fe9 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fea + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fea + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0feb + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0feb + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fec + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fec + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fed + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fed + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fee + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fee + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0fef + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0fef + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff0 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff0 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff1 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff1 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff2 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff2 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff3 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff3 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff4 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff4 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff5 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff5 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff6 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff6 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff7 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff7 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff8 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff8 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ff9 + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ff9 + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ffa + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ffa + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ffb + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ffb + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ffc + seg, 0x0002) += seg; // 4110 -> 42fd
    memory16(0x0ffc + seg, 0x000a) += seg; // 4110 -> 42fd
    memory16(0x0ffd + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ffd + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0ffe + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0ffe + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x0fff + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x0fff + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1000 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1000 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1001 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1001 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1002 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1002 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1003 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1003 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1004 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1004 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1005 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1005 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1006 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1006 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1007 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1007 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1008 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1008 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1009 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1009 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x100a + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x100a + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x100b + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x100b + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x100c + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x100c + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x100d + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x100d + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x100e + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x100e + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x100f + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x100f + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1010 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1010 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1011 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1011 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1012 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1012 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1013 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1013 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1014 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1014 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1015 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1015 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1016 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1016 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1017 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1017 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1018 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1018 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1019 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1019 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x101a + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x101a + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x101b + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x101c + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x101d + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x101d + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x101d + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x101d + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x101e + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x101e + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x101e + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x101e + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x101f + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x101f + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x101f + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x101f + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1020 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1020 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1020 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1021 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1021 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1021 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1021 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1022 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1022 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1022 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1022 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1023 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1023 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1023 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1023 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1024 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1024 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1024 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1024 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1025 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1025 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1025 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1026 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1026 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1026 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1026 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1027 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1027 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1027 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1027 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1028 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1028 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1028 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1028 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1029 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1029 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1029 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x102a + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x102a + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x102a + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x102a + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x102b + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x102b + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x102b + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x102b + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x102c + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x102c + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x102c + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x102c + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x102d + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x102d + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x102d + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x102d + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x102e + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x102e + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x102e + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x102f + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x102f + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x102f + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x102f + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x1030 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x1030 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x1030 + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x1030 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x1031 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x1031 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1031 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1032 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1032 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1032 + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x1032 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x1033 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x1033 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x1033 + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x1033 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x1034 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x1034 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1034 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1035 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1035 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1035 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1035 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1036 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1036 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1036 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1036 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1037 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1037 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1037 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1037 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1038 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1038 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1038 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1039 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1039 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1039 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1039 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x103a + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x103a + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x103a + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x103a + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x103b + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x103b + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x103b + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x103b + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x103c + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x103c + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x103c + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x103d + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x103d + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x103d + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x103d + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x103e + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x103e + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x103e + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x103e + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x103f + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x103f + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x103f + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x103f + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1040 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1040 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1040 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1040 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1041 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1041 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1041 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1042 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1042 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1042 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1042 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1043 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1043 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1043 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1043 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1044 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1044 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1044 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1044 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1045 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1045 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1045 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1046 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1046 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1046 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1046 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1047 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1047 + seg, 0x0006) += seg; // 1463 -> 1650
    memory16(0x1047 + seg, 0x000a) += seg; // 1463 -> 1650
    memory16(0x1047 + seg, 0x000e) += seg; // 1463 -> 1650
    memory16(0x1048 + seg, 0x0002) += seg; // 1463 -> 1650
    memory16(0x1048 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1048 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x1049 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x1049 + seg, 0x0004) += seg; // 1463 -> 1650
    memory16(0x1049 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x1049 + seg, 0x000c) += seg; // 1463 -> 1650
    memory16(0x104a + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x104a + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x104a + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x104a + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x104b + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x104b + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x104b + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x104b + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x104c + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x104c + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x104c + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x104c + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x104d + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x104d + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x104d + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x104d + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x104e + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x104e + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x104e + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x104e + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x104f + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x104f + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x104f + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x104f + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1050 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1050 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1050 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1050 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1051 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1051 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1051 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1051 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1052 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1052 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1052 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1053 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1053 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1053 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1053 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1054 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1054 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1054 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1054 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1055 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1055 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1055 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1055 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1056 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1056 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1056 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1056 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1057 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1057 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1057 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1057 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1058 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1058 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1058 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1058 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1059 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1059 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1059 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1059 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x105a + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x105a + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x105a + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x105b + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x105b + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x105b + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x105b + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x105c + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x105c + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x105c + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x105c + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x105d + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x105d + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x105d + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x105d + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x105e + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x105e + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x105e + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x105e + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x105f + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x105f + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x105f + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x105f + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1060 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1060 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1060 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1060 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1061 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1061 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1061 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1061 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1062 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1062 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1062 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1063 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1063 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1063 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1063 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1064 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1064 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1064 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1064 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1065 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1065 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1065 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1065 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1066 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1066 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1066 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1066 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x106f + seg, 0x0004) += seg; // 50b0 -> 529d
    memory16(0x106f + seg, 0x0008) += seg; // 50b0 -> 529d
    memory16(0x106f + seg, 0x000c) += seg; // 50b0 -> 529d
    memory16(0x1070 + seg, 0x0000) += seg; // 50b0 -> 529d
    memory16(0x1070 + seg, 0x0004) += seg; // 50b0 -> 529d
    memory16(0x1070 + seg, 0x0008) += seg; // 50b0 -> 529d
    memory16(0x1070 + seg, 0x000c) += seg; // 50b0 -> 529d
    memory16(0x1071 + seg, 0x0000) += seg; // 50b0 -> 529d
    memory16(0x1071 + seg, 0x0004) += seg; // 50b0 -> 529d
    memory16(0x1071 + seg, 0x0008) += seg; // 50b0 -> 529d
    memory16(0x1071 + seg, 0x000c) += seg; // 50b0 -> 529d
    memory16(0x1072 + seg, 0x0000) += seg; // 50b0 -> 529d
    memory16(0x1072 + seg, 0x0004) += seg; // 50b0 -> 529d
    memory16(0x1072 + seg, 0x0008) += seg; // 50b0 -> 529d
    memory16(0x1072 + seg, 0x000c) += seg; // 50b0 -> 529d
    memory16(0x1072 + seg, 0x000e) += seg; // 5b9b -> 5d88
    memory16(0x1073 + seg, 0x0002) += seg; // 5b9b -> 5d88
    memory16(0x1073 + seg, 0x0006) += seg; // 5b9b -> 5d88
    memory16(0x1073 + seg, 0x000a) += seg; // 5b9b -> 5d88
    memory16(0x1073 + seg, 0x000e) += seg; // 5b9b -> 5d88
    memory16(0x1074 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1074 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1074 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1075 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1075 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1075 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1075 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1076 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1076 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1076 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1076 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1077 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1077 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1077 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1077 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1078 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1078 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1078 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1078 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1079 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1079 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1079 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1079 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x107a + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x107a + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x107a + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x107a + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x107b + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x107b + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x107b + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x107b + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x107c + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x107c + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x107c + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x107c + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x107d + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x107d + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x107d + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x107d + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x107e + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x107e + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x107e + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x107e + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x107f + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x107f + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x107f + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x107f + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1080 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1080 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1080 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1080 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1081 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1081 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1081 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1081 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1082 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1082 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1082 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1082 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1083 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1083 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1083 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1084 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1084 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1084 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1084 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1085 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1085 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1085 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1085 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1086 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1086 + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x1086 + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x1086 + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x1087 + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x1087 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1087 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1088 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1088 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1088 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1088 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x1089 + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1089 + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x1089 + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x1089 + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x108a + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x108a + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x108a + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x108a + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x108b + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x108b + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x108b + seg, 0x000a) += seg; // 3170 -> 335d
    memory16(0x108b + seg, 0x000e) += seg; // 3170 -> 335d
    memory16(0x108c + seg, 0x0002) += seg; // 3170 -> 335d
    memory16(0x108c + seg, 0x0006) += seg; // 3170 -> 335d
    memory16(0x108c + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x108d + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x108d + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x108d + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x108d + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x108e + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x108e + seg, 0x0004) += seg; // 3170 -> 335d
    memory16(0x108e + seg, 0x0008) += seg; // 3170 -> 335d
    memory16(0x108e + seg, 0x000c) += seg; // 3170 -> 335d
    memory16(0x108f + seg, 0x0000) += seg; // 3170 -> 335d
    memory16(0x1091 + seg, 0x0004) += seg; // 2403 -> 25f0
    memory16(0x1091 + seg, 0x0008) += seg; // 2403 -> 25f0
    memory16(0x1093 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x1093 + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x1096 + seg, 0x0000) += seg; // 2403 -> 25f0
    memory16(0x1096 + seg, 0x0004) += seg; // 2403 -> 25f0
    memory16(0x1098 + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x1098 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x109a + seg, 0x000c) += seg; // 2403 -> 25f0
    memory16(0x109b + seg, 0x0000) += seg; // 2403 -> 25f0
    memory16(0x109d + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x109d + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x109f + seg, 0x0008) += seg; // 2403 -> 25f0
    memory16(0x109f + seg, 0x000c) += seg; // 2403 -> 25f0
    memory16(0x10a1 + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x10a2 + seg, 0x0002) += seg; // 2403 -> 25f0
    memory16(0x10a4 + seg, 0x0004) += seg; // 2403 -> 25f0
    memory16(0x10a4 + seg, 0x0008) += seg; // 2403 -> 25f0
    memory16(0x10a6 + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x10a6 + seg, 0x000e) += seg; // 2403 -> 25f0
    memory16(0x10a9 + seg, 0x0000) += seg; // 2403 -> 25f0
    memory16(0x10a9 + seg, 0x0004) += seg; // 2403 -> 25f0
    memory16(0x10ab + seg, 0x0006) += seg; // 2403 -> 25f0
    memory16(0x10ab + seg, 0x000a) += seg; // 2403 -> 25f0
    memory16(0x10ad + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10ad + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10ae + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10ae + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10af + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10af + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b0 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b0 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b1 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b1 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b2 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b2 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b3 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b3 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b4 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b4 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b5 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b5 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b6 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b6 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b7 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b7 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b8 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b8 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10b9 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10b9 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10ba + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10ba + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10bb + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10bb + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10bc + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10bc + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10bd + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10bd + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10be + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10be + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10bf + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10bf + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10c0 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10c0 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10c1 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10c1 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10c2 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10c2 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10c3 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10c3 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10c4 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10c4 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10c5 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10c5 + seg, 0x0008) += seg; // 1463 -> 1650
    memory16(0x10c6 + seg, 0x0000) += seg; // 1463 -> 1650
    memory16(0x10c6 + seg, 0x0008) += seg; // 1463 -> 1650
}
void sub_1ed0();
void sub_1f73();
void sub_2282();
void sub_2318();
void sub_233a();
void sub_236a();
void sub_2397();
void sub_23b5();
void sub_23d3();
void sub_23ec();
void sub_2499();
void sub_24dc();
void sub_251e();
void sub_25ae();
void sub_263d();
void sub_267a();
void sub_26b6();
void sub_273a();
void sub_276b();
void sub_2782();
void sub_27d4();
void sub_2801();
void sub_281e();
void sub_286b();
void sub_2888();
void sub_28b0();
void sub_28b6();
void sub_28cd();
void sub_2922();
void sub_2952();
void sub_29dc();
void sub_2a67();
void sub_2ad4();
void sub_2bfb();
void sub_2c4d();
void sub_2c65();
void sub_2c81();
void sub_2c94();
void sub_2cb3();
void sub_2ce0();
void sub_2cf6();
void sub_2de7();
void sub_2e19();
void sub_2e42();
void sub_2e72();
void sub_2f2c();
void sub_2f35();
void sub_2f7e();
void sub_2fa7();
void sub_2fcb();
void sub_2fdd();
void sub_2fef();
void sub_305b();
void sub_30d4();
void sub_3105();
void sub_342c();
void sub_34ae();
void sub_34f3();
void sub_3503();
void sub_350c();
void sub_3522();
void sub_3650();
void sub_377e();
void sub_389e();
void sub_3a0c();
void sub_3ae1();
void sub_3de6();
void sub_3e0f();
void sub_3e5d();
void sub_3ec9();
void sub_3fa2();
void sub_3fb7();
void sub_4052();
void sub_4155();
void sub_4212();
void sub_4241();
void sub_4279();
void sub_4317();
void sub_497f();
void sub_4999();
void sub_49b3();
void sub_49bd();
void sub_4a5f();
void sub_4ac7();
void sub_4bee();
void sub_4c4a();
void sub_4c70();
void sub_4cd0();
void sub_4d17();
void sub_4e4c();
void sub_4e81();
void sub_4ef1();
void sub_4f14();
void sub_4f8b();
void sub_4ffe();
void sub_504e();
void sub_50ca();
void sub_50e9();
void sub_518d();
void sub_51b6();
void sub_51ff();
void sub_521e();
void sub_5264();
void sub_52aa();
void sub_5300();
void sub_532b();
void sub_53d1();
void sub_5429();
void sub_5444();
void sub_544d();
void sub_5476();
void sub_5494();
void sub_54c6();
void sub_54f3();
void sub_552a();
void sub_5639();
void sub_567c();
void sub_56de();
void sub_5718();
void sub_573d();
void sub_576c();
void sub_579c();
void sub_57ae();
void sub_57b4();
void sub_57d2();
void sub_57f1();
void sub_581f();
void sub_5832();
void sub_584c();
void sub_586b();
void sub_587c();
void sub_58a7();
void sub_5901();
void sub_5970();
void sub_59d8();
void sub_5a41();
void sub_5ab3();
void sub_5b29();
void sub_5c33();
void sub_5d66();
void sub_5dce();
void sub_5efa();
void sub_5f24();
void sub_5f43();
void sub_5fd7();
void sub_6037();
void sub_60b0();
void sub_614e();
void sub_6315();
void sub_638f();
void sub_65c6();
void sub_663d();
void sub_6660();
void sub_668b();
void sub_66b6();
void sub_66e1();
void sub_670c();
void sub_6767();
void sub_67c2();
void sub_681d();
void sub_6878();
void sub_68ba();
void sub_68e8();
void sub_6908();
void sub_697c();
void sub_699a();
void sub_6a43();
void sub_6bb9();
void sub_6bda();
void sub_6c50();
void sub_6d4d();
void sub_6d9c();
void sub_6e76();
void sub_6e89();
void sub_6e9c();
void sub_6ebe();
void sub_6f24();
void sub_6f9a();
void sub_701b();
void sub_703a();
void sub_708b();
void sub_7111();
void sub_7165();
void sub_71c6();
void sub_71ea();
void sub_75bc();
void sub_7690();
void sub_76bc();
void sub_76db();
void sub_770c();
void sub_77a9();
void sub_77c8();
void sub_7810();
void sub_783b();
void sub_7891();
void sub_78e1();
void sub_7912();
void sub_7a1b();
void sub_7a2f();
void sub_7a4e();
void sub_7a60();
void sub_7acd();
void sub_7b2a();
void sub_7b7f();
void sub_7bd4();
void sub_7c29();
void sub_7d6b();
void sub_7fd3();
void sub_801a();
void sub_80ca();
void sub_8211();
void sub_8309();
void sub_8428();
void sub_85ad();
void sub_8664();
void sub_86df();
void sub_8758();
void sub_8877();
void sub_893b();
void sub_8b10();
void sub_8b6a();
void sub_8b75();
void sub_8b80();
void sub_8b8b();
void sub_8bba();
void sub_8c10();
void sub_8ca1();
void sub_8d0f();
void sub_8d2a();
void sub_8d5c();
void sub_8d8e();
void sub_8ed2();
void sub_9043();
void sub_90e2();
void sub_9109();
void sub_914f();
void sub_916e();
void sub_9183();
void sub_91c4();
void sub_92d0();
void sub_92fa();
void sub_9392();
void sub_93b3();
void sub_9430();
void sub_9459();
void sub_9479();
void sub_94d5();
void sub_94de();
void sub_9504();
void sub_953a();
void sub_956a();
void sub_95bc();
void sub_95cf();
void sub_95e5();
void sub_9602();
void sub_9612();
void sub_9634();
void sub_9641();
void sub_964e();
void sub_9668();
void sub_96b0();
void sub_a070();
void sub_1ed0()
{
    ax = 0x0b52;
    ds = ax;
    goto loc_1ed8;
loc_1ed8:
    sub_54c6();
    sub_51b6();
    memory16(ds, 0x4f88) = 0x0001;
    sub_342c();
//    sub_8bba();
//    sub_3105();
    bx = 0x0bde;
    sub_23b5();
    sub_286b();
    sub_34f3();
    sub_8d2a();
    sub_8d5c();
    sub_586b();
    sub_5901();
    memory(ds, 0x0025) = 0x00;
loc_1f0b:
    memory(ds, 0x0020) = 0x00;
    si = 0x3c5e;
    memory16(ds, si + 12) = 0x0001;
    memory16(ds, si + 18) = 0x0001;
    memory16(ds, 0x3a54) = 0x0240;
    memory16(ds, 0x4f8a) = 0x0001;
    memory16(ds, 0x4f8c) = 0x0002;
    memory16(ds, 0x4f88) = 0x0001;
    memory(ds, 0x0026) = 0x00;
    sub_4317();
    memory(ds, 0x0027) = 0x00;
    if (memory16(ds, 0x4f8a) == 0x0000)
        goto loc_1f0b;
    if (memory16(ds, 0x4f88) == 0xffff)
        goto loc_1f66;
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_1f61;
    sub_71ea();
    goto loc_1f0b;
loc_1f61:
    sub_1f73();
    goto loc_1f0b;
loc_1f66:
    sub_8d0f();
    sub_34ae();
    sub_28b0();
    ah = 0x4c;
    interrupt(0x21);
}
void sub_1f73()
{
    memory16(ds, 0x4f88) = 0x0000;
    ax = 0x0000;
    sub_77c8();
    di = 0x08de;
    push(ds);
    sub_23d3();
    ds = pop();
    ax = 0x0001;
    sub_77c8();
    ax = 0x0002;
    sub_77c8();
    memory16(ds, 0x4f6e) = 0x7fff;
    memory16(ds, 0x4f92) = 0x0000;
    memory(ds, 0x0025) = 0x00;
    sub_2fcb();
    sub_2fdd();
    ax = 0x3e54;
    memory16(ds, 0x3a52) = ax;
    sub_4f14();
    ax = memory16(ds, 0x001a);
    sub_305b();
    ax = 0x000d;
    sub_8c10();
    if (memory(ds, 0x0026) == 0x00)
        goto loc_1fdc;
    memory16(ds, 0x0010) = 0x0004;
    memory16(ds, 0x0012) = 0x0000;
    memory16(ds, 0x0014) = 0x0001;
    goto loc_2000;
loc_1fdc:
    sub_377e();
    if (memory(ds, 0x0025) != 0x00)
        goto loc_1ffd;
    sub_3650();
    if (memory(ds, 0x0025) != 0x00)
        goto loc_1ffd;
    sub_3522();
    if (memory(ds, 0x0025) != 0x00)
        goto loc_1ffd;
    goto loc_2000;
loc_1ffd:
    goto loc_2223;
loc_2000:
    memory16(ds, 0x0016) = 0x0000;
    si = 0x3c5e;
    memory16(ds, si + 30) = 0x0000;
    si = 0x3c7e;
    memory16(ds, si + 30) = 0x0000;
    si = 0x3c9e;
    memory16(ds, si + 30) = 0x0000;
    si = 0x3cbe;
    memory16(ds, si + 30) = 0x0000;
    memory16(ds, 0x3a54) = 0x0300;
loc_2030:
    sub_3a0c();
    if (memory(ds, 0x0025) != 0x00)
        goto loc_1ffd;
    memory(ds, 0x0023) = 0xff;
    si = 0x002a;
    ax = memory16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    memory16(ds, 0x37ce) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, 0x37d0) = ax;
    sub_5494();
    sub_56de();
    sub_2318();
    sub_5494();
    sub_56de();
    si = 0x3c5e;
    memory16(ds, si) = 0xffff;
    memory16(ds, si + 32) = 0xffff;
    memory16(ds, si + 64) = 0xffff;
    memory16(ds, si + 96) = 0xffff;
    si = 0x3c5e;
    bx = 0x0036;
    cx = memory16(ds, 0x0010);
loc_208b:
    push(cx);
    ax = memory16(ds, bx);
    sub_57d2();
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 12) = 0x0001;
    memory16(ds, si + 14) = 0x0000;
    memory16(ds, si + 18) = 0x0002;
    memory16(ds, si + 20) = 0x0000;
    memory16(ds, si + 22) = 0x0002;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 24) = ax;
    memory16(ds, si + 26) = 0x0000;
    memory16(ds, si + 28) = 0x0000;
    memory16(ds, si + 10) = 0x0000;
    memory16(ds, si + 8) = 0x0000;
    bx += 0x0004;
    si += 0x0020;
    cx = pop();
//    sync(); // neskoro
    if (--cx)
        goto loc_208b;
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x0046;
    di = 0x0726;
    cx = 0x00c3;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    sub_50e9();
    if (memory(ds, 0x0026) == 0x00)
        goto loc_2113;
    sub_697c();
    memory16(ds, 0x000c) = 0x5748;
    sub_58a7();
    if (dx != 0xffff)
        goto loc_2113;
    goto loc_2223;
loc_2113:
    sub_4f8b();
    ax = 0x0011;
    di = 0x0000;
    sub_2c81();
//    sync();
    if (memory(ds, 0x0026) != 0x00)
        goto loc_2129;
    sub_699a();
loc_2129:
    sub_5a41();
    sub_6a43();
    sub_5494();
    sub_56de();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    ax = 0x0000;
    sub_8c10();
    memory16(ds, 0x000a) = 0x0000;
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    memory16(ds, 0x3c72) = 0x0001;
    memory16(ds, 0x3c92) = 0x0001;
    memory16(ds, 0x3cb2) = 0x0001;
    memory16(ds, 0x3cd2) = 0x0001;
    memory(ds, 0x0023) = 0x00;
    memory16(ds, 0x204c) = 0x0000;
    memory(ds, 0x0020) = 0x00;
loc_2186:
    sub_34f3();
    sub_68ba();
    sub_281e();
    if (memory(ds, 0x0026) != 0x00)
        goto loc_219b;
    sub_552a();
    goto loc_21cb;
loc_219b:
    ax = 0x25f0;
    es = ax;
    si = memory16(ds, 0x000c);
    ax = 0x0000;
    al = memory(es, si);
    if (al == 0xff)
        goto loc_21cb;
    memory16(ds, 0x3c78) = ax;
    al = memory(es, si + 1);
    memory16(ds, 0x3c98) = ax;
    al = memory(es, si + 2);
    memory16(ds, 0x3cb8) = ax;
    al = memory(es, si + 3);
    memory16(ds, 0x3cd8) = ax;
    memory16(ds, 0x000c) = memory16(ds, 0x000c) + 0x0004;
loc_21cb:
    sub_5efa();
    sub_638f();
    sub_59d8();
    sub_6315();
    sub_6a43();
    sub_5a41();
    sub_708b();
    sub_56de();
    sub_2282();
    if (dx == 0xffff)
        goto loc_2239;
    if (memory(ds, 0x0020) != 0x19)
        goto loc_21f5;
    sub_75bc();
loc_21f5:
    if (memory(ds, 0x0023) == 0x00)
        goto loc_2204;
    memory16(ds, 0x000e) = 0xffff;
    goto loc_2239;
loc_2204:
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_3503();
//    sync();
    if (memory(ds, 0x0020) != 0x01)
        goto loc_221a;
    goto loc_2223;
loc_221a:
    sub_8b8b();
    sub_350c();
    goto loc_2186;
loc_2223:
    sub_8b80();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    return;
loc_2239:
    sub_8b80();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    if (memory(ds, 0x0026) != 0x00)
        goto loc_2223;
    sub_3ae1();
    if (memory(ds, 0x0025) != 0x00)
        goto loc_2223;
    if (memory16(ds, 0x0016) != 0x0000)
        goto loc_227c;
    goto loc_2030;
loc_227c:
    sub_389e();
    goto loc_2000;
}
void sub_2282()
{
    si = 0x3c5e;
    cx = memory16(ds, 0x0010);
    memory16(ds, 0x000e) = 0xffff;
loc_228f:
    push(cx);
    if ((short)memory16(ds, si + 8) < 0)
        goto loc_2313;
    if (memory16(ds, si) == 0xffff)
        goto loc_22ac;
    if (memory16(ds, 0x000e) != 0xffff)
        goto loc_2313;
    ax = memory16(ds, si + 24);
    memory16(ds, 0x000e) = ax;
loc_22ac:
    cx = pop();
    si += 0x0020;
    if (--cx)
        goto loc_228f;
    memory16(ds, 0x3c74) = 0x0002;
    memory16(ds, 0x3c94) = 0x0002;
    memory16(ds, 0x3cb4) = 0x0002;
    memory16(ds, 0x3cd4) = 0x0002;
    cx = 0x0008;
    si = 0x3cde;
loc_22d0:
    if (memory16(ds, si) != 0xffff)
        goto loc_2307;
    si += 0x0016;
    if (--cx)
        goto loc_22d0;
    memory16(ds, 0x000a) = memory16(ds, 0x000a) + 1;
    if (memory16(ds, 0x000a) == 0x0002)
        goto loc_2308;
    if (memory16(ds, 0x000a) == 0x0009)
        goto loc_2308;
    if (memory16(ds, 0x000a) == 0x0010)
        goto loc_2308;
    if (memory16(ds, 0x000a) < 0x0012)
        goto loc_2307;
    if (memory16(ds, 0x000e) == 0xffff)
        goto loc_230f;
    dx = 0xffff;
    return;
loc_2307:
    return;
loc_2308:
    ax = 0x0003;
    sub_8ca1();
    return;
loc_230f:
    dx = 0xffff;
    return;
loc_2313:
    cx = pop();
    dx = 0x0000;
}
void sub_2318()
{
    ax = memory16(ds, 0x0018);
    dx = memory16(ds, 0x001a);
    memory16(ds, 0x0018) = dx;
    memory16(ds, 0x001a) = ax;
    ax = memory16(ds, 0x0ede);
    dx = memory16(ds, 0x0ee0);
    memory16(ds, 0x0ede) = dx;
    memory16(ds, 0x0ee0) = ax;
    memory(ds, 0x0022) = ~memory(ds, 0x0022);
}
void sub_233a()
{
loc_233a:
    sub_34f3();
    push(si);
    bx = si;
    sub_23b5();
    si = pop();
    ah = 0x00;
    bx = 0x0000;
    cx = 0x0300;
loc_234c:
    al = memory(ds, bx + si);
    if (memory(ds, bx + di) <= al)
        goto loc_235c;
    ah = 0xff;
    memory(ds, bx + si) = memory(ds, bx + si) + 1;
loc_235c:
    bx++;
    if (--cx)
        goto loc_234c;
    push(ax);
    sub_3503();
    ax = pop();
    if (ah != 0x00)
        goto loc_233a;
}
void sub_236a()
{
loc_236a:
    sub_34f3();
    push(si);
    bx = si;
    sub_23b5();
    si = pop();
    ah = 0x00;
    bx = 0x0000;
    cx = 0x0300;
loc_237c:
    if (memory(ds, bx + si) == 0x00)
        goto loc_2389;
    ah = 0xff;
    memory(ds, bx + si) = memory(ds, bx + si) - 1;
loc_2389:
    bx++;
    if (--cx)
        goto loc_237c;
    push(ax);
    sub_3503();
    ax = pop();
    if (ah != 0x00)
        goto loc_236a;
}
void sub_2397()
{
    dx = 0x03c8;
    al = al;
    out(dx, al);
loc_239d:
    lodsb<MemData, DirForward>();
    dx = 0x03c9;
    al = al;
    out(dx, al);
    lodsb<MemData, DirForward>();
    dx = 0x03c9;
    al = al;
    out(dx, al);
    lodsb<MemData, DirForward>();
    dx = 0x03c9;
    al = al;
    out(dx, al);
    if (--cx)
        goto loc_239d;
}
void sub_23b5()
{
    push(ds);
    dx = 0x03c8;
    al = 0x00;
    out(dx, al);
    ax = 0x0b52;
    ds = ax;
    si = bx;
    cx = 0x0100;
    dx = 0x03c9;
loc_23c9:
    lodsb<MemData, DirForward>();
    out(dx, al);
    lodsb<MemData, DirForward>();
    out(dx, al);
    lodsb<MemData, DirForward>();
    out(dx, al);
    if (--cx)
        goto loc_23c9;
    ds = pop();
}
void sub_23d3()
{
    ax = 0x25f0;
    ds = ax;
    si = 0x0030;
    ax = 0x0b52;
    es = ax;
    cx = 0x0300;
loc_23e3:
    lodsb<MemData, DirForward>();
    al >>= 1;
    al >>= 1;
    stosb<MemData, DirForward>();
    if (--cx)
        goto loc_23e3;
}
void sub_23ec()
{
    ax = 0x25f0;
    ds = ax;
    si = 0x0000;
loc_23f4:
    si++;
    if (memory(ds, si) != 0x42)
        goto loc_23f4;
    if (memory(ds, si + 1) != 0x4f)
        goto loc_23f4;
    if (memory(ds, si + 2) != 0x44)
        goto loc_23f4;
    if (memory(ds, si + 3) != 0x59)
        goto loc_23f4;
    si += 0x0008;
loc_2414:
    push(cx);
    push(di);
    push(es);
    ax = 0x0b52;
    es = ax;
    di = 0x16c2;
    dx = 0x0000;
loc_2422:
    ax = 0x0000;
    lodsb<MemData, DirForward>();
    if ((char)al < 0)
        goto loc_2434;
    cx = ax;
    cx++;
    dx += cx;
    rep_movsb<MemData, MemData, DirForward>();
    goto loc_243e;
loc_2434:
    al = -al;
    cx = ax;
    cx++;
    dx += cx;
    flags.carry = 0;
    lodsb<MemData, DirForward>();
    rep_stosb<MemData, DirForward>();
loc_243e:
    if (dx < 0x0140)
        goto loc_2422;
    es = pop();
    di = pop();
    push(ds);
    push(si);
    ax = 0x0b52;
    ds = ax;
    si = 0x16c2;
    cx = 0x0028;
loc_2453:
    push(cx);
    cx = 0x0008;
loc_2457:
    al = 0x00;
    memory(ds, si + 280) = rcl(memory(ds, si + 280), 1);
    al = rcl(al, 0x01);
    memory(ds, si + 240) = rcl(memory(ds, si + 240), 1);
    al = rcl(al, 0x01);
    memory(ds, si + 200) = rcl(memory(ds, si + 200), 1);
    al = rcl(al, 0x01);
    memory(ds, si + 160) = rcl(memory(ds, si + 160), 1);
    al = rcl(al, 0x01);
    memory(ds, si + 120) = rcl(memory(ds, si + 120), 1);
    al = rcl(al, 0x01);
    memory(ds, si + 80) = rcl(memory(ds, si + 80), 1);
    al = rcl(al, 0x01);
    memory(ds, si + 40) = rcl(memory(ds, si + 40), 1);
    al = rcl(al, 0x01);
    memory(ds, si) = rcl(memory(ds, si), 1);
    al = rcl(al, 0x01);
    stosb<MemData, DirForward>();
    if (--cx)
        goto loc_2457;
    cx = pop();
    si++;
    if (--cx)
        goto loc_2453;
    si = pop();
    ds = pop();
    cx = pop();
    if (--cx)
        goto loc_2496;
    return;
loc_2496:
    goto loc_2414;
}
void sub_2499()
{
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
loc_24a9:
    push(cx);
    push(si);
    al = 0x01;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al += al;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al += al;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al += al;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    si = pop();
    di += 0x0080;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_24a9;
}
void sub_24dc()
{
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
loc_24ec:
    push(cx);
    push(si);
    al = 0x01;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al += al;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al += al;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al += al;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    si = pop();
    di += 0x0040;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_24ec;
}
void sub_251e()
{
    push(cx);
    cx = ax;
    ax = 0x0011;
    ax = rol(ax, cl);
    cx = pop();
    push(ax);
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
    ax = pop();
    ah = al;
loc_253b:
    push(cx);
    push(si);
    push(di);
    al = ah;
    out(dx, al);
    ah = rol(ah, 0x01);
    cx = bx;
loc_2545:
    lodsb<MemData, DirForward>();
    if (al == 0x03)
        goto loc_254d;
    memoryVideoSet(es, di, al);
loc_254d:
    di++;
    if (--cx)
        goto loc_2545;
    di -= bx;
    if (ah != 0x11)
        goto loc_2558;
    di++;
loc_2558:
    al = ah;
    out(dx, al);
    ah = rol(ah, 0x01);
    cx = bx;
loc_255f:
    lodsb<MemData, DirForward>();
    if (al == 0x03)
        goto loc_2567;
    memoryVideoSet(es, di, al);
loc_2567:
    di++;
    if (--cx)
        goto loc_255f;
    di -= bx;
    if (ah != 0x11)
        goto loc_2572;
    di++;
loc_2572:
    al = ah;
    out(dx, al);
    ah = rol(ah, 0x01);
    cx = bx;
loc_2579:
    lodsb<MemData, DirForward>();
    if (al == 0x03)
        goto loc_2581;
    memoryVideoSet(es, di, al);
loc_2581:
    di++;
    if (--cx)
        goto loc_2579;
    di -= bx;
    if (ah != 0x11)
        goto loc_258c;
    di++;
loc_258c:
    al = ah;
    out(dx, al);
    ah = rol(ah, 0x01);
    cx = bx;
loc_2593:
    lodsb<MemData, DirForward>();
    if (al == 0x03)
        goto loc_259b;
    memoryVideoSet(es, di, al);
loc_259b:
    di++;
    if (--cx)
        goto loc_2593;
    di -= bx;
    di = pop();
    si = pop();
    di += 0x0080;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_253b;
}
void sub_25ae()
{
    push(cx);
    cx = ax;
    ax = 0x0011;
    ax = rol(ax, cl);
    cx = pop();
    push(ax);
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
    ax = pop();
    ah = al;
loc_25cb:
    push(cx);
    push(si);
    push(di);
    al = ah;
    out(dx, al);
    ah = rol(ah, 0x01);
    cx = bx;
loc_25d5:
    lodsb<MemData, DirForward>();
    if (al == 0x03)
        goto loc_25dd;
    memoryVideoSet(es, di, al);
loc_25dd:
    di++;
    if (--cx)
        goto loc_25d5;
    di -= bx;
    if (ah != 0x11)
        goto loc_25e8;
    di++;
loc_25e8:
    al = ah;
    out(dx, al);
    ah = rol(ah, 0x01);
    cx = bx;
loc_25ef:
    lodsb<MemData, DirForward>();
    if (al == 0x03)
        goto loc_25f7;
    memoryVideoSet(es, di, al);
loc_25f7:
    di++;
    if (--cx)
        goto loc_25ef;
    di -= bx;
    if (ah != 0x11)
        goto loc_2602;
    di++;
loc_2602:
    al = ah;
    out(dx, al);
    ah = rol(ah, 0x01);
    cx = bx;
loc_2609:
    lodsb<MemData, DirForward>();
    if (al == 0x03)
        goto loc_2611;
    memoryVideoSet(es, di, al);
loc_2611:
    di++;
    if (--cx)
        goto loc_2609;
    di -= bx;
    if (ah != 0x11)
        goto loc_261c;
    di++;
loc_261c:
    al = ah;
    out(dx, al);
    ah = rol(ah, 0x01);
    cx = bx;
loc_2623:
    lodsb<MemData, DirForward>();
    if (al == 0x03)
        goto loc_262b;
    memoryVideoSet(es, di, al);
loc_262b:
    di++;
    if (--cx)
        goto loc_2623;
    di -= bx;
    di = pop();
    si = pop();
    di += 0x0040;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_25cb;
}
void sub_263d()
{
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
loc_264d:
    push(cx);
    al = 0x01;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al = 0x02;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al = 0x04;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al = 0x08;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    di += 0x0080;
    cx = pop();
    if (--cx)
        goto loc_264d;
}
void sub_267a()
{
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
loc_268a:
    push(cx);
    al = 0x01;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al = 0x02;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al = 0x04;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    al = 0x08;
    out(dx, al);
    cx = bx;
    rep_movsb<MemVideo, MemData, DirForward>();
    di -= bx;
    di += 0x0040;
    cx = pop();
    if (--cx)
        goto loc_268a;
}
void sub_26b6()
{
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_26fc;
    push(ds);
    bx = dx;
    ax = 0xa000;
    ds = ax;
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx = 0x03cf;
loc_26ce:
    push(cx);
    push(si);
    al = 0x00;
    out(dx, al);
    cx = bx;
    rep_movsb<MemData, MemVideo, DirForward>();
    si -= bx;
    al = 0x01;
    out(dx, al);
    cx = bx;
    rep_movsb<MemData, MemVideo, DirForward>();
    si -= bx;
    al = 0x02;
    out(dx, al);
    cx = bx;
    rep_movsb<MemData, MemVideo, DirForward>();
    si -= bx;
    al = 0x03;
    out(dx, al);
    cx = bx;
    rep_movsb<MemData, MemVideo, DirForward>();
    si = pop();
    si += 0x0080;
    cx = pop();
    if (--cx)
        goto loc_26ce;
    ds = pop();
    return;
loc_26fc:
    push(ds);
    bx = dx;
    ax = 0xa000;
    ds = ax;
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx = 0x03cf;
loc_270d:
    push(cx);
    push(si);
    al = 0x00;
    out(dx, al);
    cx = bx;
    rep_movsb<MemData, MemVideo, DirForward>();
    si -= bx;
    al = 0x01;
    out(dx, al);
    cx = bx;
    rep_movsb<MemData, MemVideo, DirForward>();
    si -= bx;
    al = 0x02;
    out(dx, al);
    cx = bx;
    rep_movsb<MemData, MemVideo, DirForward>();
    si -= bx;
    al = 0x03;
    out(dx, al);
    cx = bx;
    rep_movsb<MemData, MemVideo, DirForward>();
    si = pop();
    si += 0x0040;
    cx = pop();
    if (--cx)
        goto loc_270d;
    ds = pop();
}
void sub_273a()
{
    push(ds);
    cl = 0x03;
    ax <<= cl;
    si = 0x0ee2;
    si += ax;
    if (si >= 0x1532)
        goto loc_2760;
    dx = memory16(ds, si + 4);
    cx = memory16(ds, si + 6);
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_2762;
    tx = si;
    si = memory16(ds, tx);
    ds = memory16(ds, tx + 2);
    sub_2499();
loc_2760:
    ds = pop();
    return;
loc_2762:
    tx = si;
    si = memory16(ds, tx);
    ds = memory16(ds, tx + 2);
    sub_24dc();
    ds = pop();
}
void sub_276b()
{
    push(cx);
    cl = 0x04;
    ax <<= cl;
    si = 0x180c;
    si += ax;
    if (si >= 0x203c)
        goto loc_2780;
    cx = pop();
    sub_2782();
    return;
loc_2780:
    cx = pop();
}
void sub_2782()
{
    push(ds);
    ax = dx;
    sub_584c();
    di += memory16(ds, 0x0018);
    push(ax);
    push(si);
    push(di);
    ax = di;
    dx = memory16(ds, si + 4);
    dx++;
    cx = memory16(ds, si + 6);
    bx = si + 0x8;
    if (memory(ds, 0x0022) != 0x00)
        goto loc_27a7;
    bx += 0x0004;
loc_27a7:
    di = memory16(ds, bx);
    es = memory16(ds, bx + 2);
    si = ax;
    sub_27d4();
    di = pop();
    si = pop();
    ax = pop();
    dx = memory16(ds, si + 4);
    cx = memory16(ds, si + 6);
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_27cb;
    tx = si;
    si = memory16(ds, tx);
    ds = memory16(ds, tx + 2);
    sub_251e();
    ds = pop();
    return;
loc_27cb:
    tx = si;
    si = memory16(ds, tx);
    ds = memory16(ds, tx + 2);
    sub_25ae();
    ds = pop();
}
void sub_27d4()
{
    bx = memory16(ds, 0x0ede);
    ax = 0x0014;
loc_27db:
    if (memory16(ds, bx) == 0xffff)
        goto loc_27e9;
    bx += 0x000a;
    ax--;
    if (ax != 0)
        goto loc_27db;
    return;
loc_27e9:
    memory16(ds, bx) = si;
    memory16(ds, bx + 2) = di;
    memory16(ds, bx + 4) = es;
    memory16(ds, bx + 6) = dx;
    memory16(ds, bx + 8) = cx;
    sub_26b6();
}
void sub_2801()
{
    si = 0x1532;
    di = 0x15fa;
    ax = 0xffff;
    cx = 0x0014;
loc_280d:
    memory16(ds, si) = ax;
    memory16(ds, di) = ax;
    si += 0x000a;
    di += 0x000a;
    if (--cx)
        goto loc_280d;
}
void sub_281e()
{
    si = memory16(ds, 0x0ede);
    si += 0x00be;
    ax = 0x0014;
loc_2829:
    if (memory16(ds, si) != 0xffff)
        goto loc_2837;
loc_2830:
    si -= 0x000a;
    ax--;
    if (ax != 0)
        goto loc_2829;
    return;
loc_2837:
    push(ax);
    push(si);
    push(ds);
    di = memory16(ds, si);
    memory16(ds, si) = 0xffff;
    dx = memory16(ds, si + 6);
    cx = memory16(ds, si + 8);
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_285f;
    tx = si;
    si = memory16(ds, tx + 2);
    ds = memory16(ds, tx + 2 + 2);
    sub_263d();
    ds = pop();
    si = pop();
    ax = pop();
    goto loc_2830;
loc_285f:
    tx = si;
    si = memory16(ds, tx + 2);
    ds = memory16(ds, tx + 2 + 2);
    sub_267a();
    ds = pop();
    si = pop();
    ax = pop();
    goto loc_2830;
}
void sub_286b()
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out(dx, al);
    ax = 0xa000;
    es = ax;
    di = 0x0000;
    cx = 0xfa00;
    ax = 0x0000;
    rep_stosb<MemVideo, DirForward>();
}
void sub_2888()
{
    push(ax);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out(dx, al);
    dx = 0xa000;
    es = dx;
    di = 0x0000;
    cx = 0xfa00;
    ax = pop();
    rep_stosb<MemVideo, DirForward>();
}
void sub_28b0()
{
    ax = 0x0003;
    interrupt(0x10);
}
void sub_28b6()
{
    push(cx);
    cl = 0x04;
    ax <<= cl;
    si = 0x180c;
    si += ax;
    if (si >= 0x203c)
        goto loc_28cb;
    cx = pop();
    sub_28cd();
    return;
loc_28cb:
    cx = pop();
}
void sub_28cd()
{
    push(ds);
    push(bx);
    ax = dx;
    sub_584c();
    di += memory16(ds, 0x0018);
    push(ax);
    push(si);
    push(di);
    ax = di;
    dx = memory16(ds, si + 4);
    dx++;
    cx = memory16(ds, si + 6);
    bx = si + 0x8;
    if (memory(ds, 0x0022) != 0x00)
        goto loc_28f3;
    bx += 0x0004;
loc_28f3:
    di = memory16(ds, bx);
    es = memory16(ds, bx + 2);
    si = ax;
    sub_27d4();
    di = pop();
    si = pop();
    ax = pop();
    dx = memory16(ds, si + 4);
    cx = memory16(ds, si + 6);
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_2918;
    tx = si;
    si = memory16(ds, tx);
    ds = memory16(ds, tx + 2);
    bx = pop();
    sub_29dc();
    ds = pop();
    return;
loc_2918:
    tx = si;
    si = memory16(ds, tx);
    ds = memory16(ds, tx + 2);
    bx = pop();
    sub_2952();
    ds = pop();
}
void sub_2922()
{
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out(dx, al);
    dx = 0x03ce;
    al = 0x05;
    out(dx, al);
    dx = 0x03cf;
    al = 0x41;
    out(dx, al);
    push(ds);
    ax = 0xa000;
    es = ax;
    ds = ax;
    rep_movsb<MemData, MemData, DirForward>();
    ds = pop();
    dx = 0x03ce;
    al = 0x05;
    out(dx, al);
    dx = 0x03cf;
    al = 0x40;
    out(dx, al);
}
void sub_2952()
{
    push(bx);
    push(cx);
    cx = ax;
    ax = 0x0011;
    ax = rol(ax, cl);
    cx = pop();
    push(ax);
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    ax = pop();
    dx = pop();
    ah = dl;
    dx = 0x03c5;
loc_2971:
    push(cx);
    push(si);
    push(di);
    out(dx, al);
    al = rol(al, 0x01);
    cx = bx;
loc_2979:
    if (memory(ds, si) == 0x03)
        goto loc_2981;
    memoryVideoSet(es, di, ah);
loc_2981:
    si++;
    di++;
    if (--cx)
        goto loc_2979;
    di -= bx;
    if (al != 0x11)
        goto loc_298c;
    di++;
loc_298c:
    out(dx, al);
    al = rol(al, 0x01);
    cx = bx;
loc_2991:
    if (memory(ds, si) == 0x03)
        goto loc_2999;
    memoryVideoSet(es, di, ah);
loc_2999:
    si++;
    di++;
    if (--cx)
        goto loc_2991;
    di -= bx;
    if (al != 0x11)
        goto loc_29a4;
    di++;
loc_29a4:
    out(dx, al);
    al = rol(al, 0x01);
    cx = bx;
loc_29a9:
    if (memory(ds, si) == 0x03)
        goto loc_29b1;
    memoryVideoSet(es, di, ah);
loc_29b1:
    si++;
    di++;
    if (--cx)
        goto loc_29a9;
    di -= bx;
    if (al != 0x11)
        goto loc_29bc;
    di++;
loc_29bc:
    out(dx, al);
    al = rol(al, 0x01);
    cx = bx;
loc_29c1:
    if (memory(ds, si) == 0x03)
        goto loc_29c9;
    memoryVideoSet(es, di, ah);
loc_29c9:
    si++;
    di++;
    if (--cx)
        goto loc_29c1;
    di -= bx;
    di = pop();
    si = pop();
    di += 0x0040;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_2971;
}
void sub_29dc()
{
    push(bx);
    push(cx);
    cx = ax;
    ax = 0x0011;
    ax = rol(ax, cl);
    cx = pop();
    push(ax);
    bx = dx;
    ax = 0xa000;
    es = ax;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    ax = pop();
    dx = pop();
    ah = dl;
    dx = 0x03c5;
loc_29fb:
    push(cx);
    push(si);
    push(di);
    out(dx, al);
    al = rol(al, 0x01);
    cx = bx;
loc_2a03:
    if (memory(ds, si) == 0x03)
        goto loc_2a0b;
    memoryVideoSet(es, di, ah);
loc_2a0b:
    si++;
    di++;
    if (--cx)
        goto loc_2a03;
    di -= bx;
    if (al != 0x11)
        goto loc_2a16;
    di++;
loc_2a16:
    out(dx, al);
    al = rol(al, 0x01);
    cx = bx;
loc_2a1b:
    if (memory(ds, si) == 0x03)
        goto loc_2a23;
    memoryVideoSet(es, di, ah);
loc_2a23:
    si++;
    di++;
    if (--cx)
        goto loc_2a1b;
    di -= bx;
    if (al != 0x11)
        goto loc_2a2e;
    di++;
loc_2a2e:
    out(dx, al);
    al = rol(al, 0x01);
    cx = bx;
loc_2a33:
    if (memory(ds, si) == 0x03)
        goto loc_2a3b;
    memoryVideoSet(es, di, ah);
loc_2a3b:
    si++;
    di++;
    if (--cx)
        goto loc_2a33;
    di -= bx;
    if (al != 0x11)
        goto loc_2a46;
    di++;
loc_2a46:
    out(dx, al);
    al = rol(al, 0x01);
    cx = bx;
loc_2a4b:
    if (memory(ds, si) == 0x03)
        goto loc_2a53;
    memoryVideoSet(es, di, ah);
loc_2a53:
    si++;
    di++;
    if (--cx)
        goto loc_2a4b;
    di -= bx;
    di = pop();
    si = pop();
    di += 0x0080;
    si += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_29fb;
}
void sub_2a67()
{
    if (memory16(ds, 0x26f2) == 0x0000)
        goto loc_2aa5;
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_2a76;
    return;
loc_2a76:
    push(ds);
    di = memory16(ds, 0x0018);
    si = 0xb908;
    ax = 0x42fd;
    ds = ax;
    dx = 0x0040;
    cx = 0x0018;
    sub_24dc();
    ds = pop();
    push(ds);
    di = memory16(ds, 0x001a);
    si = 0xb908;
    ax = 0x42fd;
    ds = ax;
    dx = 0x0040;
    cx = 0x0018;
    sub_24dc();
    ds = pop();
    return;
loc_2aa5:
    push(ds);
    di = memory16(ds, 0x0018);
    si = 0xb908;
    ax = 0x42fd;
    ds = ax;
    dx = 0x0040;
    cx = 0x0018;
    sub_2499();
    ds = pop();
    push(ds);
    di = memory16(ds, 0x001a);
    si = 0xb908;
    ax = 0x42fd;
    ds = ax;
    dx = 0x0040;
    cx = 0x0018;
    sub_2499();
    ds = pop();
}
void sub_2ad4()
{
    ax = memory16(ds, 0x203e);
    if (ax == memory16(ds, 0x1802))
        goto loc_2aef;
    if (memory16(ds, 0x26f2) == 0x0001)
        goto loc_2af2;
    if (memory16(ds, 0x26f2) != 0x0002)
        goto loc_2aee;
    goto loc_2b7e;
loc_2aee:
    return;
loc_2aef:
    memory16(ds, 0x1802) = ax;
loc_2af2:
    push(ds);
    cx = memory16(ds, 0x203e);
    cl &= 0x03;
    al = 0x11;
    al = rol(al, cl);
    push(ax);
    ax = memory16(ds, 0x203e);
    ax -= 0x0080;
    ax >>= 1;
    ax >>= 1;
    di = ax;
    di += memory16(ds, 0x0018);
    ax = 0xa000;
    es = ax;
    ds = ax;
    si = 0xfa00;
    ax = pop();
    bx = ax;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
    al = bl;
    out(dx, al);
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx = 0x03cf;
    al = 0x00;
    out(dx, al);
    sub_2c4d();
    bl = rol(bl, 0x01);
    if (bl != 0x11)
        goto loc_2b3f;
    di++;
loc_2b3f:
    dx = 0x03c5;
    al = bl;
    out(dx, al);
    dx = 0x03cf;
    al = 0x01;
    out(dx, al);
    sub_2c4d();
    bl = rol(bl, 0x01);
    if (bl != 0x11)
        goto loc_2b56;
    di++;
loc_2b56:
    dx = 0x03c5;
    al = bl;
    out(dx, al);
    dx = 0x03cf;
    al = 0x02;
    out(dx, al);
    sub_2c4d();
    bl = rol(bl, 0x01);
    if (bl != 0x11)
        goto loc_2b6d;
    di++;
loc_2b6d:
    dx = 0x03c5;
    al = bl;
    out(dx, al);
    dx = 0x03cf;
    al = 0x03;
    out(dx, al);
    sub_2c4d();
    ds = pop();
    return;
loc_2b7e:
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out(dx, al);
    dx = 0x03ce;
    al = 0x05;
    out(dx, al);
    dx = 0x03cf;
    al = 0x41;
    out(dx, al);
    si = 0x1808;
    if (memory(ds, 0x0022) == 0x00)
        goto loc_2ba3;
    si = 0x1804;
loc_2ba3:
    ax = 0xa000;
    es = ax;
    ax = memory16(ds, 0x203e);
    ax -= 0x0080;
    cl = 0x06;
    ax <<= cl;
    di = ax;
    di += memory16(ds, 0x0018);
    push(ds);
    push(di);
    memory16(ds, si) = di;
    ax = memory16(ds, si + 2);
    si = di;
    di = ax;
    ax = 0xa000;
    ds = ax;
    es = ax;
    cx = 0x0600;
    rep_movsb<MemData, MemData, DirForward>();
    di = pop();
    ds = pop();
    push(ds);
    flags.direction = true;
    si = memory16(ds, 0x0018);
    si += 0x05ff;
    di += 0x05ff;
    ax = 0xa000;
    ds = ax;
    cx = 0x0600;
    rep_movsb<MemData, MemData, DirForward>();
    flags.direction = false;
    ds = pop();
    dx = 0x03ce;
    al = 0x05;
    out(dx, al);
    dx = 0x03cf;
    al = 0x40;
    out(dx, al);
}
void sub_2bfb()
{
    if (memory16(ds, 0x26f2) != 0x0002)
        return;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out(dx, al);
    dx = 0x03ce;
    al = 0x05;
    out(dx, al);
    dx = 0x03cf;
    al = 0x41;
    out(dx, al);
    si = 0x1808;
    if (memory(ds, 0x0022) == 0x00)
        goto loc_2c27;
    si = 0x1804;
loc_2c27:
    ax = 0xa000;
    es = ax;
    push(ds);
    push(si);
    lodsw<MemData, DirForward>();
    di = ax;
    lodsw<MemData, DirForward>();
    si = ax;
    ax = 0xa000;
    ds = ax;
    cx = 0x0600;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    ds = pop();
    dx = 0x03ce;
    al = 0x05;
    out(dx, al);
    dx = 0x03cf;
    al = 0x40;
    out(dx, al);
}
void sub_2c4d()
{
    cx = 0x0018;
loc_2c50:
    push(cx);
    cx = 0x0040;
    rep_movsb<MemData, MemData, DirForward>();
    di += 0x0040;
    cx = pop();
    if (--cx)
        goto loc_2c50;
    si -= 0x0600;
    di -= 0x0c00;
}
void sub_2c65()
{
    push(ds);
    ax = 0xa000;
    es = ax;
    ax = 0x42fd;
    ds = ax;
    si = 0xb908;
    di = 0xfa00;
    cx = 0x0018;
    dx = 0x0040;
    sub_24dc();
    ds = pop();
}
void sub_2c81()
{
    push(ax);
    push(di);
    di += memory16(ds, 0x0018);
    sub_273a();
    di = pop();
    ax = pop();
    di += memory16(ds, 0x001a);
    sub_273a();
}
void sub_2c94()
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    di += memory16(ds, 0x0018);
    sub_2cb3();
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    di += memory16(ds, 0x001a);
    sub_2cb3();
}
void sub_2cb3()
{
    push(ax);
    push(dx);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx = 0x03c5;
    al = 0x0f;
    out(dx, al);
    ax = 0xa000;
    es = ax;
    dx = pop();
    ax = pop();
loc_2cc8:
    push(cx);
    push(di);
    cx = dx;
    rep_stosb<MemVideo, DirForward>();
    di = pop();
    cx = pop();
    di += 0x0040;
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_2cdd;
    di += 0x0040;
loc_2cdd:
    if (--cx)
        goto loc_2cc8;
}
void sub_2ce0()
{
loc_2ce0:
    push(cx);
    lodsw<MemData, DirForward>();
    if (ax == 0xffff)
        goto loc_2cf3;
    di = ax;
    lodsw<MemData, DirForward>();
    push(si);
    sub_2c81();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_2ce0;
    return;
loc_2cf3:
    cx = pop();
}
void sub_2cf6()
{
    si = 0x30e5;
    di = 0x2117;
    bx = 0x0000;
loc_2cff:
    lodsb<MemData, DirForward>();
    sub_2e42();
    if ((char)al < 0)
        goto loc_2d5b;
    al &= 0x0f;
    memory(ds, di) = al;
    lodsb<MemData, DirForward>();
    sub_2e42();
    if ((char)al < 0)
        goto loc_2d5b;
    cl = 0x04;
    al <<= cl;
    memory(ds, di) = memory(ds, di) | al;
    di++;
    bx++;
    if (bx != 0x0004)
        goto loc_2cff;
    si = 0x2117;
    al = memory(ds, si);
    al &= 0xe0;
    bx = 0x0003;
loc_2d30:
    //stop(/*74*/);
    flags.carry = false;
    al = rcl(al, 0x01);
    if (!flags.carry)
        goto loc_2d39;
    memory(ds, bx + si) = ~memory(ds, bx + si);
loc_2d39:
    bx--;
    if (bx != 0x0000)
        goto loc_2d30;
    al = memory(ds, si);
    al &= 0x18;
    if (al != 0x10)
        goto loc_2d5b;
    memory16(ds, 0x2162) = 0x0000;
    al = memory(ds, si);
    al &= 0x07;
    sub_2e19();
    goto loc_2d5e;
loc_2d5b:
    goto loc_2de3;
loc_2d5e:
    si = 0x20a3;
    di = 0x20b9;
    dx = 0x0004;
    sub_2de7();
    if (ax == 0x0000)
        goto loc_2d5b;
    if (ax > 0x0008)
        goto loc_2d5b;
    memory16(ds, 0x4f88) = ax;
    si = 0x20a7;
    di = 0x20bd;
    dx = 0x0004;
    sub_2de7();
    if (ax == 0x0000)
        goto loc_2d5b;
    if (ax > 0x0008)
        goto loc_2de3;
    memory16(ds, 0x4f8a) = ax;
    si = 0x20ab;
    di = 0x20c1;
    dx = 0x0004;
    sub_2de7();
    memory16(ds, 0x3c6a) = ax;
    si = 0x20af;
    di = 0x20c5;
    dx = 0x0004;
    sub_2de7();
    memory16(ds, 0x3c70) = ax;
    si = 0x20b3;
    di = 0x20c9;
    dx = 0x0001;
    sub_2de7();
    memory16(ds, 0x3a54) = 0x0300;
    if (ax != 0x0001)
        goto loc_2dcb;
    memory16(ds, 0x3a54) = 0x03c0;
loc_2dcb:
    ax = memory16(ds, 0x2162);
    si = 0x20b4;
    di = 0x20ca;
    dx = 0x0001;
    sub_2de7();
    if (ax != 0x0000)
        goto loc_2de3;
    dx = 0x0000;
    return;
loc_2de3:
    dx = 0xffff;
}
void sub_2de7()
{
    bx = 0x0000;
    ah = 0x00;
loc_2dec:
    push(bx);
    bl = memory(ds, bx + di);
    bx &= 0x0003;
    bx += 0x2117;
    al = memory(ds, bx);
    bx = pop();
    ah <<= 1;
    al &= memory(ds, bx + si);
    if (al == 0x00)
        goto loc_2e0e;
    memory16(ds, 0x2162) = memory16(ds, 0x2162) + 1;
    ah |= 0x01;
loc_2e0e:
    bx++;
    if (bx != dx)
        goto loc_2dec;
    al = ah;
    ax &= 0x00ff;
}
void sub_2e19()
{
    bx = 0x2117;
    memory(ds, 0x2164) = al;
    cx = 0x0000;
loc_2e22:
    if (memory(ds, 0x2164) == cl)
        return;
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    flags.carry = false;
    dx = rcr(dx, 0x0001);
    ax = rcr(ax, 0x0001);
    memory16(ds, bx + 2) = dx;
    memory(ds, bx + 1) = ah;
    cl++;
    goto loc_2e22;
}
void sub_2e42()
{
    push(bx);
    bx &= 0x0003;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += bx;
    cx = 0x0010;
loc_2e51:
    push(bx);
    bx += 0x20cf;
    ah = memory(ds, bx);
    bx = pop();
    if (ah == al)
        goto loc_2e68;
    cx--;
    if (cx == 0x0000)
        goto loc_2e6e;
    bx++;
    goto loc_2e51;
loc_2e68:
    al = 0x10;
    al -= cl;
    bx = pop();
    return;
loc_2e6e:
    al = 0xff;
    bx = pop();
}
void sub_2e72()
{
    si = 0x2117;
    memory16(ds, si) = 0x0000;
    memory16(ds, si + 2) = 0x0000;
    memory16(ds, 0x2162) = 0x0000;
    ax = memory16(ds, 0x4f88);
    si = 0x20a3;
    di = 0x20b9;
    bx = 0x0004;
    sub_2fa7();
    ax = memory16(ds, 0x4f8a);
    si = 0x20a7;
    di = 0x20bd;
    bx = 0x0004;
    sub_2fa7();
    ax = memory16(ds, 0x3c6a);
    si = 0x20ab;
    di = 0x20c1;
    bx = 0x0004;
    sub_2fa7();
    ax = memory16(ds, 0x3c70);
    si = 0x20af;
    di = 0x20c5;
    bx = 0x0004;
    sub_2fa7();
    ax = 0x0000;
    if (memory16(ds, 0x3a54) != 0x03c0)
        goto loc_2ed1;
    ax = 0x0001;
loc_2ed1:
    si = 0x20b3;
    di = 0x20c9;
    bx = 0x0001;
    sub_2fa7();
    ax = memory16(ds, 0x2162);
    si = 0x20b4;
    di = 0x20ca;
    bx = 0x0005;
    sub_2fa7();
    ax = 0x0002;
    sub_587c();
    memory(ds, 0x2117) = al;
    sub_2f7e();
    ax = 0x0008;
    sub_587c();
    dx = ax;
    cl = 0x05;
    al <<= cl;
    al |= 0x10;
    memory(ds, 0x2117) = memory(ds, 0x2117) | al;
    di = 0x30e5;
    memory(ds, 0x2164) = 0x00;
    al = memory(ds, 0x2117);
    sub_2f35();
    al = memory(ds, 0x2118);
    sub_2f2c();
    al = memory(ds, 0x2119);
    sub_2f2c();
    al = memory(ds, 0x211a);
    sub_2f2c();
}
void sub_2f2c()
{
    flags.carry = dx & 1;
    dx = ror(dx, 0x0001);
    if (!flags.carry)
        goto loc_2f35;
    al ^= 0xff;
    goto loc_2f35;
loc_2f35:
    push(dx);
    dh = al;
    al &= 0x0f;
    dl = al;
    al = memory(ds, 0x2164);
    cl = 0x04;
    al <<= cl;
    al += dl;
    ax &= 0x003f;
    bx = ax;
    bx += 0x20cf;
    al = memory(ds, bx);
    memory(ds, di) = al;
    di++;
    al = dh;
    al &= 0xf0;
    al >>= cl;
    dl = al;
    al = memory(ds, 0x2164);
    al <<= cl;
    al += dl;
    ax &= 0x003f;
    bx = ax;
    bx += 0x20cf;
    al = memory(ds, bx);
    memory(ds, di) = al;
    di++;
    memory(ds, 0x2164) = memory(ds, 0x2164) + 1;
    dx = pop();
}
void sub_2f35()
{
    push(dx);
    dh = al;
    al &= 0x0f;
    dl = al;
    al = memory(ds, 0x2164);
    cl = 0x04;
    al <<= cl;
    al += dl;
    ax &= 0x003f;
    bx = ax;
    bx += 0x20cf;
    al = memory(ds, bx);
    memory(ds, di) = al;
    di++;
    al = dh;
    al &= 0xf0;
    al >>= cl;
    dl = al;
    al = memory(ds, 0x2164);
    al <<= cl;
    al += dl;
    ax &= 0x003f;
    bx = ax;
    bx += 0x20cf;
    al = memory(ds, bx);
    memory(ds, di) = al;
    di++;
    memory(ds, 0x2164) = memory(ds, 0x2164) + 1;
    dx = pop();
}
void sub_2f7e()
{
    bx = 0x2117;
    memory(ds, 0x2164) = al;
    cx = 0x0000;
loc_2f87:
    if (memory(ds, 0x2164) == cl)
        return;
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
   // stop(/*74*/);
    flags.carry = false;
    ax = rcl(ax, 0x0001);
    dx = rcl(dx, 0x0001);
    memory16(ds, bx + 2) = dx;
    memory(ds, bx + 1) = ah;
    cl++;
    goto loc_2f87;
}
void sub_2fa7()
{
    bx--;
loc_2fa8:
    flags.carry = ax & 1;
    ax = ror(ax, 0x0001);
    if (!flags.carry)
        goto loc_2fc4;
    memory16(ds, 0x2162) = memory16(ds, 0x2162) + 1;
    push(bx);
    dl = memory(ds, bx + si);
    bl = memory(ds, bx + di);
    bh = 0x00;
    bx += 0x2117;
    memory(ds, bx) = memory(ds, bx) | dl;
    bx = pop();
loc_2fc4:
    bx--;
    if (bx != 0xffff)
        goto loc_2fa8;
}
void sub_2fcb()
{
    si = 0x3cde;
    cx = 0x0058;
loc_2fd1:
    memory16(ds, si) = 0xffff;
    si += 0x0002;
    if (--cx)
        goto loc_2fd1;
}
void sub_2fdd()
{
    si = 0x3d8e;
    cx = 0x0028;
loc_2fe3:
    memory16(ds, si) = 0xffff;
    si += 0x0002;
    if (--cx)
        goto loc_2fe3;
}
void sub_2fef()
{
    if (memory16(ds, 0x26f2) == 0x0000)
        goto loc_3032;
    if ((short)memory16(ds, 0x3c68) < 0)
        goto loc_3032;
    if (memory16(ds, 0x3c5e) == 0xffff)
        goto loc_3032;
    if (memory16(ds, 0x26f2) == 0x0001)
        goto loc_3033;
    si = 0x3c5e;
    bx = memory16(ds, si + 2);
    memory16(ds, 0x203e) = bx;
    if (memory16(ds, 0x203e) <= 0x0180)
        goto loc_3024;
    memory16(ds, 0x203e) = 0x0180;
loc_3024:
    if (memory16(ds, 0x203e) >= 0x0080)
        goto loc_3032;
    memory16(ds, 0x203e) = 0x0080;
loc_3032:
    return;
loc_3033:
    si = 0x3c5e;
    bx = memory16(ds, si);
    memory16(ds, 0x203e) = bx;
    if (memory16(ds, 0x203e) <= 0x0180)
        goto loc_304c;
    memory16(ds, 0x203e) = 0x0180;
loc_304c:
    if (memory16(ds, 0x203e) >= 0x0080)
        return;
    memory16(ds, 0x203e) = 0x0080;
}
void sub_305b()
{
    if (memory16(ds, 0x26f2) == 0x0000)
        goto loc_3090;
    if (memory16(ds, 0x26f2) == 0x0001)
        goto loc_30ab;
    bx = memory16(ds, 0x203e);
    bx -= 0x0080;
    cl = 0x06;
    bx <<= cl;
    bx += ax;
    dx = 0x03d4;
    al = 0x0c;
    out(dx, al);
    dx = 0x03d5;
    al = bh;
    out(dx, al);
    dx = 0x03d4;
    al = 0x0d;
    out(dx, al);
    dx = 0x03d5;
    al = bl;
    out(dx, al); // video delay
    return;
loc_3090:
    bx = ax;
    dx = 0x03d4;
    al = 0x0c;
    out(dx, al);
    dx = 0x03d5;
    al = bh;
    out(dx, al);
    dx = 0x03d4;
    al = 0x0d;
    out(dx, al);
    dx = 0x03d5;
    al = bl;
    out(dx, al); // game delay
    return;
loc_30ab:
    push(ax);
    bx = memory16(ds, 0x203e);
    bx -= 0x0080;
    bx >>= 1;
    bx >>= 1;
    ax = pop();
    bx += ax;
    dx = 0x03d4;
    al = 0x0c;
    out(dx, al);
    dx = 0x03d5;
    al = bh;
    out(dx, al);
    dx = 0x03d4;
    al = 0x0d;
    out(dx, al);
    dx = 0x03d5;
    al = bl;
    out(dx, al);
}
void sub_30d4()
{
    if (memory16(ds, 0x26f2) != 0x0001)
        return;
    dx = 0x03da;
    in(al, dx);
    dx = 0x03c0;
    al = 0x13;
    out(dx, al);
    ax = memory16(ds, 0x203e);
    ax &= 0x0003;
    if (memory(ds, 0x0024) == 0x01)
        goto loc_30f4;
    al += al;
loc_30f4:
    dx = 0x03c0;
    al = al;
    out(dx, al);
    dx = 0x03c0;
    al = 0x20;
    out(dx, al);
    dx = 0x03da;
    in(al, dx);
}
void sub_3105()
{
    ax = 0x0012;
    interrupt(0x10);
    dx = 0x03d4;
    al = 0x11;
    out(dx, al);
    dx = 0x03d5;
    in(al, dx);
    al &= 0x7f;
    dx = 0x03d5;
    al = al;
    out(dx, al);
    si = 0x2075;
    bx = 0x0000;
    cx = 0x0018;
loc_3125:
    dx = 0x03d4;
    al = bl;
    out(dx, al);
    lodsb<MemData, DirForward>();
    dx = 0x03d5;
    al = al;
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_3125;
    dx = 0x03da;
    in(al, dx);
    si = 0x208e;
    bx = 0x0000;
    cx = 0x0014;
loc_3143:
    dx = 0x03c0;
    al = bl;
    out(dx, al);
    lodsb<MemData, DirForward>();
    dx = 0x03c0;
    al = al;
    out(dx, al);
    bl++;
    if (--cx)
        goto loc_3143;
    dx = 0x03c0;
    al = 0x20;
    out(dx, al);
    dx = 0x03da;
    in(al, dx);
    dx = 0x03c4;
    al = 0x04;
    out(dx, al);
    dx = 0x03c5;
    in(al, dx);
    al &= 0xf7;
    dx = 0x03c5;
    al = al;
    out(dx, al);
    dx = 0x03d4;
    al = 0x14;
    out(dx, al);
    dx = 0x03d5;
    in(al, dx);
    al &= 0xbf;
    dx = 0x03d5;
    al = al;
    out(dx, al);
    dx = 0x03d4;
    al = 0x17;
    out(dx, al);
    dx = 0x03d5;
    in(al, dx);
    al |= 0x40;
    dx = 0x03d5;
    al = al;
    out(dx, al);
    dx = 0x03ce;
    al = 0x05;
    out(dx, al);
    dx = 0x03cf;
    al = 0x40;
    out(dx, al);
    dx = 0x03d4;
    al = 0x03;
    out(dx, al);
    dx = 0x03d5;
    al = 0x82;
    out(dx, al);
    dx = 0x03d4;
    al = 0x01;
    out(dx, al);
    dx = 0x03d5;
    al = 0x3f;
    out(dx, al);
    dx = 0x03d4;
    al = 0x04;
    out(dx, al);
    dx = 0x03d5;
    al = 0x4c;
    out(dx, al);
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out(dx, al);
    dx = 0x03d4;
    al = 0x06;
    out(dx, al);
    dx = 0x03d5;
    al = 0x0b;
    out(dx, al);
    dx = 0x03d4;
    al = 0x10;
    out(dx, al);
    dx = 0x03d5;
    al = 0xe2;
    out(dx, al);
    dx = 0x03d4;
    al = 0x11;
    out(dx, al);
    dx = 0x03d5;
    al = 0x0c;
    out(dx, al);
    dx = 0x03d4;
    al = 0x15;
    out(dx, al);
    dx = 0x03d5;
    al = 0xe7;
    out(dx, al);
    dx = 0x03d4;
    al = 0x07;
    out(dx, al);
    dx = 0x03d5;
    al = 0x3e;
    out(dx, al);
    dx = 0x03d4;
    al = 0x09;
    out(dx, al);
    dx = 0x03d5;
    al = 0x41;
    out(dx, al);
    dx = 0x03d4;
    al = 0x12;
    out(dx, al);
    dx = 0x03d5;
    al = 0xcf;
    out(dx, al);
}
void sub_342c()
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    ax = 0x351c;
    interrupt(0x21);
    memory16(ds, 0x2042) = es;
    memory16(ds, 0x2040) = bx;
    dx = es;
    ax = 0x01ed;
    es = ax;
    si = 0x13f0;
    memory16(es, si) = bx;
    memory16(es, si + 2) = dx;
    ax = 0x3509;
    interrupt(0x21);
    memory16(ds, 0x2046) = es;
    memory16(ds, 0x2044) = bx;
    dx = es;
    ax = 0x01ed;
    es = ax;
    si = 0x14de;
    memory16(es, si) = bx;
    memory16(es, si + 2) = dx;
    ax = 0x351b;
    interrupt(0x21);
    memory16(ds, 0x204a) = es;
    memory16(ds, 0x2048) = bx;
    ax = 0x01ed;
    ds = ax;
    dx = 0x1355;
    ax = 0x251c;
    interrupt(0x21);
    ax = 0x01ed;
    ds = ax;
    dx = 0x1410;
    ax = 0x2509;
    interrupt(0x21);
    ax = 0x01ed;
    ds = ax;
    dx = 0x15dd;
    ax = 0x251b;
    interrupt(0x21);
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_34ae()
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    dx = memory16(ds, 0x2040);
    ax = memory16(ds, 0x2042);
    ds = ax;
    ax = 0x251c;
    interrupt(0x21);
    ax = 0x0b52;
    ds = ax;
    dx = memory16(ds, 0x2044);
    ax = memory16(ds, 0x2046);
    ds = ax;
    ax = 0x2509;
    interrupt(0x21);
    ax = 0x0b52;
    ds = ax;
    dx = memory16(ds, 0x2048);
    ax = memory16(ds, 0x204a);
    ds = ax;
    ax = 0x251b;
    interrupt(0x21);
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_34f3()
{
   // sync(); // gameplay delay
//    push(ds);
//    ax = 0x0b52;
//    ds = ax;
//    dx = 0x03da;
//loc_34fc:
//    in(al, dx);
//    al &= 0x08;
//    if (al == 0)
//        goto loc_34fc;
//    ds = pop();
}
void sub_3503()
{
    dx = 0x03da;
loc_3506:
    in(al, dx);
    al &= 0x08;
    if (al != 0)
        goto loc_3506;
}
void sub_350c()
{
    sync(); //gameplay delay, video delay,fade delay
    return;
    if (memory(ds, 0x204f) != 0x00)
        goto loc_351a;
loc_3513:
    if (memory(ds, 0x204f) == 0x00)
        goto loc_3513;
loc_351a:
    memory(ds, 0x204f) = 0x00;
}
void sub_3522()
{
    al = 0x48;
    sub_2888();
    memory(ds, 0x236a) = 0x3a;
    memory(ds, 0x236b) = 0x3c;
    di = 0x0603;
    dx = 0x001c;
    cx = 0x0018;
    sub_3fa2();
    si = 0x23ba;
    sub_53d1();
    si = 0x26b0;
    cx = 0x000a;
    sub_2ce0();
    ax = memory16(ds, 0x0014);
    ax -= 0x0001;
    si = 0x26d8;
    sub_3de6();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
loc_357c:
    if (memory(ds, 0x0020) != 0x01)
        goto loc_358b;
    memory(ds, 0x0025) = 0xff;
    goto loc_3636;
loc_358b:
//    sync();
    sub_5476();
    ah = al;
    al &= 0x10;
    if (al != 0)
        goto loc_35fa;
    al = ah;
    al &= 0x03;
    if (al == 0)
        goto loc_35ef;
    if (memory(ds, 0x236c) != 0x00)
        goto loc_357c;
    al = ah;
    al &= 0x01;
    if (al == 0)
        goto loc_35c2;
    memory(ds, 0x236c) = 0xff;
    if (memory16(ds, 0x0014) != 0x0001)
        goto loc_35bc;
    memory16(ds, 0x0014) = 0x0005;
    goto loc_35e1;
loc_35bc:
    memory16(ds, 0x0014) = memory16(ds, 0x0014) - 1;
    goto loc_35e1;
loc_35c2:
    al = ah;
    al &= 0x02;
    if (al == 0)
        goto loc_35e1;
    memory(ds, 0x236c) = 0xff;
    if (memory16(ds, 0x0014) != 0x0005)
        goto loc_35dd;
    memory16(ds, 0x0014) = 0x0001;
    goto loc_35e1;
loc_35dd:
    memory16(ds, 0x0014) = memory16(ds, 0x0014) + 1;
loc_35e1:
    ax = memory16(ds, 0x0014);
    ax -= 0x0001;
    si = 0x26d8;
    sub_3de6();
    goto loc_357c;
loc_35ef:
    memory(ds, 0x236c) = 0x00;
    sub_8b8b();
    goto loc_357c;
loc_35fa:
    si = 0x26b0;
    ax = memory16(ds, 0x0014);
    ax -= 0x0001;
    ax += ax;
    ax += ax;
    ax += ax;
    si += ax;
    cx = 0x0003;
loc_360e:
    push(cx);
    push(si);
    lodsw<MemData, DirForward>();
    di = ax;
    dx = 0x001d;
    cx = 0x000f;
    al = 0x48;
    sub_2c94();
    cx = 0x0004;
    sub_5429();
    si = pop();
    push(si);
    cx = 0x0002;
    sub_2ce0();
    cx = 0x0006;
    sub_5429();
    si = pop();
    cx = pop();
//    sync();
    if (--cx)
        goto loc_360e;
loc_3636:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_3650()
{
    al = 0x48;
    sub_2888();
    memory(ds, 0x236a) = 0x3a;
    memory(ds, 0x236b) = 0x3c;
    di = 0x2f03;
    dx = 0x001c;
    cx = 0x000d;
    sub_3fa2();
    si = 0x23a4;
    sub_53d1();
    si = 0x2690;
    cx = 0x0006;
    sub_2ce0();
    ax = memory16(ds, 0x0010);
    ax -= 0x0002;
    si = 0x26a8;
    sub_3de6();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
loc_36aa:
//    sync();
    if (memory(ds, 0x0020) != 0x01)
        goto loc_36b9;
    memory(ds, 0x0025) = 0xff;
    goto loc_3764;
loc_36b9:
//    sync();
    sub_5476();
    ah = al;
    al &= 0x10;
    if (al != 0)
        goto loc_3728;
    al = ah;
    al &= 0x03;
    if (al == 0)
        goto loc_371d;
    if (memory(ds, 0x236c) != 0x00)
        goto loc_36aa;
    al = ah;
    al &= 0x01;
    if (al == 0)
        goto loc_36f0;
    memory(ds, 0x236c) = 0xff;
    if (memory16(ds, 0x0010) != 0x0002)
        goto loc_36ea;
    memory16(ds, 0x0010) = 0x0004;
    goto loc_370f;
loc_36ea:
    memory16(ds, 0x0010) = memory16(ds, 0x0010) - 1;
    goto loc_370f;
loc_36f0:
    al = ah;
    al &= 0x02;
    if (al == 0)
        goto loc_370f;
    memory(ds, 0x236c) = 0xff;
    if (memory16(ds, 0x0010) != 0x0004)
        goto loc_370b;
    memory16(ds, 0x0010) = 0x0002;
    goto loc_370f;
loc_370b:
    memory16(ds, 0x0010) = memory16(ds, 0x0010) + 1;
loc_370f:
    ax = memory16(ds, 0x0010);
    ax -= 0x0002;
    si = 0x26a8;
    sub_3de6();
    goto loc_36aa;
loc_371d:
    memory(ds, 0x236c) = 0x00;
    sub_8b8b();
    goto loc_36aa;
loc_3728:
    si = 0x2690;
    ax = memory16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    ax += ax;
    ax += ax;
    si += ax;
    cx = 0x0003;
loc_373c:
    push(cx);
    push(si);
    lodsw<MemData, DirForward>();
    di = ax;
    dx = 0x0029;
    cx = 0x000f;
    al = 0x48;
    sub_2c94();
    cx = 0x0004;
    sub_5429();
    si = pop();
    push(si);
    cx = 0x0002;
    sub_2ce0();
    cx = 0x0006;
    sub_5429();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_373c;
loc_3764:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_377e()
{
    al = 0x48;
    sub_2888();
    memory(ds, 0x236a) = 0x3a;
    memory(ds, 0x236b) = 0x3c;
    di = 0x2e05;
    dx = 0x001a;
    cx = 0x000c;
    sub_3fa2();
    si = 0x238a;
    sub_53d1();
    si = 0x267a;
    cx = 0x0004;
    sub_2ce0();
    ax = memory16(ds, 0x0012);
    si = 0x268a;
    sub_3de6();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    memory(ds, 0x236c) = 0x00;
loc_37db:
//    sync();
    if (memory(ds, 0x0020) != 0x01)
        goto loc_37ea;
    memory(ds, 0x0025) = 0xff;
    goto loc_3884;
loc_37ea:
    //sync();
    sub_5476();
    ah = al;
    al &= 0x10;
    if (al != 0)
        goto loc_384b;
    al = ah;
    al &= 0x03;
    if (al == 0)
        goto loc_3840;
//    sync();
    if (memory(ds, 0x236c) != 0x00)
        goto loc_383e;
    al = ah;
    al &= 0x01;
    if (al == 0)
        goto loc_3820;
    memory(ds, 0x236c) = 0xff;
    memory16(ds, 0x0012) = memory16(ds, 0x0012) - 1;
    memory16(ds, 0x0012) = memory16(ds, 0x0012) & 0x0001;
    ax = memory16(ds, 0x0012);
    si = 0x268a;
    sub_3de6();
    goto loc_383e;
loc_3820:
    al = ah;
    al &= 0x02;
    if (al == 0)
        goto loc_383e;
    memory(ds, 0x236c) = 0xff;
    memory16(ds, 0x0012) = memory16(ds, 0x0012) + 1;
    memory16(ds, 0x0012) = memory16(ds, 0x0012) & 0x0001;
    ax = memory16(ds, 0x0012);
    si = 0x268a;
    sub_3de6();
loc_383e:
    goto loc_37db;
loc_3840:
//    sync();
    memory(ds, 0x236c) = 0x00;
    sub_8b8b();
    goto loc_37db;
loc_384b:
    si = 0x267a;
    ax = memory16(ds, 0x0012);
    ax += ax;
    ax += ax;
    ax += ax;
    si += ax;
    cx = 0x0003;
loc_385c:
    push(cx);
    push(si);
    lodsw<MemData, DirForward>();
    di = ax;
    dx = 0x0020;
    cx = 0x000f;
    al = 0x48;
    sub_2c94();
    cx = 0x0004;
    sub_5429();
//    sync();
    si = pop();
    push(si);
    cx = 0x0002;
    sub_2ce0();
    cx = 0x0006;
    sub_5429();
    si = pop();
    cx = pop();
//    sync();
    if (--cx)
        goto loc_385c;
loc_3884:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_389e()
{
    al = 0x48;
    sub_2888();
    si = 0x266e;
    cx = 0x0003;
    sub_2ce0();
    di = 0x4b12;
    ax = memory16(ds, 0x000e);
    ax += 0x0058;
    sub_2c81();
    di = 0x4b2d;
    ax = memory16(ds, 0x0010);
    ax += ax;
    di -= ax;
    cx = 0x0000;
    ax = 0x005c;
loc_38c8:
    if (cx == memory16(ds, 0x000e))
        goto loc_38da;
    push(di);
    push(ax);
    push(cx);
    sub_2c81();
    cx = pop();
    ax = pop();
    di = pop();
    di += 0x0005;
loc_38da:
    ax++;
    cx++;
    if (cx == memory16(ds, 0x0010))
        goto loc_38e4;
    goto loc_38c8;
loc_38e4:
    memory(ds, 0x236a) = 0x3a;
    memory(ds, 0x236b) = 0x3c;
    di = 0x3603;
    dx = 0x001c;
    cx = 0x000c;
    sub_3fa2();
    si = 0x2476;
    memory16(ds, si) = 0x008e;
    memory16(ds, si + 2) = 0x005e;
    memory16(ds, si + 4) = 0x259a;
    memory16(ds, si + 6) = 0x0000;
    si = 0x245e;
    memory16(ds, si) = 0x0047;
    memory16(ds, si + 2) = 0x0096;
    memory16(ds, si + 4) = 0x2562;
    if (memory16(ds, 0x000e) != 0x0002)
        goto loc_3939;
    memory16(ds, si + 4) = 0x257e;
loc_3939:
    memory16(ds, si + 6) = 0x0000;
    sub_3e0f();
    sub_3e5d();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_281e();
    sub_3e0f();
    sub_3e5d();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    ax = 0x0004;
    sub_8c10();
    memory16(ds, 0x2368) = 0x0000;
loc_3985:
    memory16(ds, 0x2368) = memory16(ds, 0x2368) + 1;
    sub_34f3();
    sub_281e();
    sub_3e0f();
    sub_3e5d();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    if (memory16(ds, 0x2368) != 0x0012)
        goto loc_39ab;
    si = 0x236d;
    sub_53d1();
loc_39ab:
    if (memory16(ds, 0x2368) != 0x001f)
        goto loc_39b8;
    si = 0x2377;
    sub_53d1();
loc_39b8:
    if (memory16(ds, 0x2368) != 0x0029)
        goto loc_39d3;
    memory16(ds, 0x2368) = 0x0017;
    di = 0x6197;
    dx = 0x0020;
    cx = 0x0007;
    al = 0x48;
    sub_2c94();
loc_39d3:
    sub_8b8b();
    sub_350c();
    sub_544d();
    if (dx != 0x0000)
        goto loc_39e3;
    goto loc_3985;
loc_39e3:
    sub_8b80();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
}
void sub_3a0c()
{
    al = 0x48;
    sub_2888();
    di = 0x0f12;
    ax = memory16(ds, 0x0014);
    ax += 0x004a;
    sub_2c81();
    di = 0x0f16;
    ax = 0x0050;
    sub_2c81();
    di = 0x0f2d;
    ax = 0x0068;
    sub_2c81();
    memory(ds, 0x236a) = 0x3a;
    memory(ds, 0x236b) = 0x3c;
    di = 0x0603;
    dx = 0x001c;
    cx = 0x0018;
    sub_3fa2();
    si = 0x263e;
    ax = memory16(ds, 0x0010);
    cx = 0x0003;
    mul(cx);
    cx = ax;
    sub_2ce0();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    ax = 0x0003;
    sub_8c10();
    cx = 0x0005;
loc_3a82:
//    sync();
    if (memory(ds, 0x0020) != 0x01)
        goto loc_3a91;
    memory(ds, 0x0025) = 0xff;
    goto loc_3ac7;
loc_3a91:
    push(cx);
    sub_34f3();
    di = 0x5510;
    dx = 0x0021;
    cx = 0x0017;
    al = 0x48;
    sub_2c94();
    cx = 0x0005;
    sub_5429();
    sub_34f3();
    di = 0x5510;
    ax = 0x0052;
    sub_2c81();
    di = 0x5520;
    ax = 0x0053;
    sub_2c81();
    cx = 0x0005;
    sub_5429();
    cx = pop();
    if (--cx)
        goto loc_3a82;
loc_3ac7:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_3ae1()
{
    al = 0x48;
    sub_2888();
    if (memory16(ds, 0x000e) != 0xffff)
        goto loc_3af0;
    goto loc_3ced;
loc_3af0:
    di = 0x0792;
    ax = memory16(ds, 0x0014);
    ax += 0x004a;
    sub_2c81();
    di = 0x0796;
    ax = 0x0050;
    sub_2c81();
    di = 0x07ad;
    ax = 0x0068;
    sub_2c81();
    memory(ds, 0x236a) = 0x3a;
    memory(ds, 0x236b) = 0x3c;
    di = 0x1a03;
    dx = 0x001c;
    cx = 0x0003;
    sub_3fa2();
    memory(ds, 0x236a) = 0x40;
    memory(ds, 0x236b) = 0x41;
    di = 0x2a03;
    dx = 0x001c;
    cx = 0x0003;
    sub_3fa2();
    if (memory16(ds, 0x0010) == 0x0002)
        goto loc_3b7c;
    memory(ds, 0x236a) = 0x40;
    memory(ds, 0x236b) = 0x41;
    di = 0x3a03;
    dx = 0x001c;
    cx = 0x0003;
    sub_3fa2();
    if (memory16(ds, 0x0010) == 0x0003)
        goto loc_3b7c;
    memory(ds, 0x236a) = 0x40;
    memory(ds, 0x236b) = 0x41;
    di = 0x4a03;
    dx = 0x001c;
    cx = 0x0003;
    sub_3fa2();
loc_3b7c:
    di = 0x3c5e;
    cx = memory16(ds, 0x0010);
loc_3b83:
    push(cx);
    si = 0x25b6;
    ax = memory16(ds, di + 24);
    ax += ax;
    si += ax;
    si = memory16(ds, si);
    push(di);
    cx = memory16(ds, di + 30);
    cx += 0x0003;
loc_3b9b:
    push(cx);
    lodsw<MemData, DirForward>();
    di = ax;
    lodsw<MemData, DirForward>();
    push(si);
    sub_2c81();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_3b9b;
    di = pop();
    cx = pop();
    di += 0x0020;
    if (--cx)
        goto loc_3b83;
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    ax = 0x0002;
    sub_8c10();
    cx = 0x0026;
    sub_5429();
    if (memory(ds, 0x0025) == 0x00)
        goto loc_3be7;
    goto loc_3cd3;
loc_3be7:
    ax = memory16(ds, 0x000e);
    cx = 0x0020;
    mul(cx);
    si = 0x3c5e;
    si += ax;
    ax = memory16(ds, 0x000e);
    ax += ax;
    di = 0x25b6;
    di += ax;
    di = memory16(ds, di);
    ax = 0x0003;
    bx = memory16(ds, si + 30);
    push(bx);
    ax += bx;
    ax += ax;
    ax += ax;
    di += ax;
    si = di;
    lodsw<MemData, DirForward>();
    di = ax;
    lodsw<MemData, DirForward>();
    sub_2c81();
    ax = memory16(ds, 0x000e);
    cx = 0x0014;
    mul(cx);
    si = 0x23fe;
    si += ax;
    ax = pop();
    ax += ax;
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    dx = ax;
    lodsw<MemData, DirForward>();
    cx = ax;
    si = 0x248e;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 4) = 0x24e6;
    si = 0x24a4;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 4) = 0x24e6;
    si = 0x24ba;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 4) = 0x24e6;
    si = 0x24d0;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 4) = 0x24e6;
    ax = 0x0003;
    sub_8ca1();
loc_3c7f:
    sub_34f3();
    sub_281e();
    sub_3ec9();
    if (dx == 0xffff)
        goto loc_3ca1;
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_3503();
    sub_34f3();
    sub_3503();
    goto loc_3c7f;
loc_3ca1:
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    ax = memory16(ds, 0x000e);
    cx = 0x0020;
    mul(cx);
    si = 0x3c5e;
    si += ax;
    memory16(ds, si + 30) = memory16(ds, si + 30) + 1;
    ax = memory16(ds, 0x0014);
    if (memory16(ds, si + 30) != ax)
        goto loc_3ccd;
    memory16(ds, 0x0016) = 0x0001;
loc_3ccd:
    cx = 0x0019;
    sub_5429();
loc_3cd3:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    return;
loc_3ced:
    di = 0x1190;
    ax = 0x0051;
    sub_2c81();
    di = 0x11a1;
    ax = 0x0052;
    sub_2c81();
    memory(ds, 0x236a) = 0x3a;
    memory(ds, 0x236b) = 0x3c;
    di = 0x3d03;
    dx = 0x001c;
    cx = 0x000a;
    sub_3fa2();
    ax = memory16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    si = 0x23ce;
    si += ax;
    lodsw<MemData, DirForward>();
    si = ax;
loc_3d27:
    lodsw<MemData, DirForward>();
    if (ax == 0xffff)
        goto loc_3d37;
    di = ax;
    lodsw<MemData, DirForward>();
    push(si);
    sub_2c81();
    si = pop();
    goto loc_3d27;
loc_3d37:
    si = 0x2476;
    memory16(ds, si) = 0x0060;
    memory16(ds, si + 2) = 0x0064;
    memory16(ds, si + 4) = 0x259a;
    memory16(ds, si + 6) = 0x0000;
    memory16(ds, 0x2368) = 0x0000;
    sub_3e0f();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_3e0f();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    ax = 0x0001;
    sub_8c10();
loc_3d8f:
    sync();
    if (memory(ds, 0x0020) != 0x01)
        goto loc_3d9e;
    memory(ds, 0x0025) = 0xff;
    goto loc_3dc0;
loc_3d9e:
    memory16(ds, 0x2368) = memory16(ds, 0x2368) + 1;
    sub_34f3();
    sub_281e();
    sub_3e0f();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_350c();
    if (memory16(ds, 0x2368) == 0x0036)
        goto loc_3dc0;
    goto loc_3d8f;
loc_3dc0:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
}
void sub_3de6()
{
    push(si);
    push(ax);
loc_3de8:
    lodsw<MemData, DirForward>();
    if (ax == 0xffff)
        goto loc_3dff;
    di = ax;
    push(si);
    dx = 0x0008;
    cx = 0x0010;
    al = 0x48;
    sub_2c94();
    si = pop();
    goto loc_3de8;
loc_3dff:
    ax = pop();
    si = pop();
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    di = ax;
    ax = 0x0067;
    sub_2c81();
}
void sub_3e0f()
{
    si = 0x2476;
    memory16(ds, si + 6) = memory16(ds, si + 6) + 1;
    if (memory16(ds, si + 6) < 0x0001)
        goto loc_3e3a;
    memory16(ds, si + 6) = 0x0000;
    memory16(ds, si + 4) = memory16(ds, si + 4) + 0x0004;
    bx = memory16(ds, si + 4);
    if (memory16(ds, bx) != 0xffff)
        goto loc_3e3a;
    bx = 0x259a;
    memory16(ds, si + 4) = bx;
loc_3e3a:
    bx = memory16(ds, si + 4);
    ax = memory16(ds, bx);
    memory16(ds, si + 8) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 10) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    si += 0x0008;
    sub_2782();
}
void sub_3e5d()
{
    si = 0x245e;
    memory16(ds, si + 6) = memory16(ds, si + 6) + 1;
    if (memory16(ds, si + 6) < 0x0003)
        goto loc_3e92;
    memory16(ds, si + 6) = 0x0000;
    memory16(ds, si + 4) = memory16(ds, si + 4) + 0x0006;
    bx = memory16(ds, si + 4);
    if (memory16(ds, bx) != 0xffff)
        goto loc_3e92;
    bx = 0x2562;
    if (memory16(ds, 0x000e) != 0x0002)
        goto loc_3e8e;
    bx = 0x257e;
loc_3e8e:
    memory16(ds, si + 4) = bx;
loc_3e92:
    bx = memory16(ds, si + 4);
    ax = memory16(ds, bx);
    memory16(ds, si + 8) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 10) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx += memory16(ds, bx + 4);
    push(cx);
    push(dx);
    si += 0x0008;
    sub_2782();
    dx = pop();
    cx = pop();
    cx -= 0x0047;
    dx -= 0x0011;
    si = 0x244e;
    sub_2782();
}
void sub_3ec9()
{
    di = 0x248e;
    dx = memory16(ds, di);
    cx = memory16(ds, di + 2);
    bx = memory16(ds, di + 4);
    memory16(ds, di + 4) = memory16(ds, di + 4) + 0x0008;
    si = bx;
    lodsw<MemData, DirForward>();
    if (ax != 0xfc18)
        goto loc_3ee8;
    goto loc_3f9e;
loc_3ee8:
    memory16(ds, di + 6) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 8) = ax;
    lodsw<MemData, DirForward>();
    dx += ax;
    lodsw<MemData, DirForward>();
    cx += ax;
    si = di;
    si += 0x0006;
    sub_2782();
    di = 0x24a4;
    dx = memory16(ds, di);
    cx = memory16(ds, di + 2);
    bx = memory16(ds, di + 4);
    memory16(ds, di + 4) = memory16(ds, di + 4) + 0x0008;
    si = bx;
    lodsw<MemData, DirForward>();
    ax += 0x0010;
    memory16(ds, di + 6) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 8) = ax;
    lodsw<MemData, DirForward>();
    ax = -ax;
    dx += ax;
    lodsw<MemData, DirForward>();
    cx += ax;
    si = di;
    si += 0x0006;
    sub_2782();
    di = 0x24ba;
    dx = memory16(ds, di);
    cx = memory16(ds, di + 2);
    bx = memory16(ds, di + 4);
    memory16(ds, di + 4) = memory16(ds, di + 4) + 0x0008;
    si = bx;
    lodsw<MemData, DirForward>();
    ax += 0x0020;
    memory16(ds, di + 6) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 8) = ax;
    lodsw<MemData, DirForward>();
    dx += ax;
    lodsw<MemData, DirForward>();
    ax = -ax;
    cx += ax;
    si = di;
    si += 0x0006;
    sub_2782();
    di = 0x24d0;
    dx = memory16(ds, di);
    cx = memory16(ds, di + 2);
    bx = memory16(ds, di + 4);
    memory16(ds, di + 4) = memory16(ds, di + 4) + 0x0008;
    si = bx;
    lodsw<MemData, DirForward>();
    ax += 0x0030;
    memory16(ds, di + 6) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 8) = ax;
    lodsw<MemData, DirForward>();
    ax = -ax;
    dx += ax;
    lodsw<MemData, DirForward>();
    ax = -ax;
    cx += ax;
    si = di;
    si += 0x0006;
    sub_2782();
    dx = 0x0000;
    return;
loc_3f9e:
    dx = 0xffff;
}
void sub_3fa2()
{
    push(di);
    push(cx);
    push(dx);
    di += memory16(ds, 0x0018);
    sub_3fb7();
    dx = pop();
    cx = pop();
    di = pop();
    di += memory16(ds, 0x001a);
    sub_3fb7();
}
void sub_3fb7()
{
    push(di);
    push(cx);
    push(dx);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    ax = 0x0400;
    cx++;
    mul(cx);
    memory16(ds, 0x2368) = ax;
    push(di);
    ax = 0x0000;
    al = memory(ds, 0x236a);
    sub_273a();
    di = pop();
    di += memory16(ds, 0x2368);
    ax = 0x003e;
    sub_273a();
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    cx = dx;
loc_3fea:
    push(cx);
    di += 0x0002;
    push(di);
    ax = 0x003b;
    sub_273a();
    di = pop();
    push(di);
    di += memory16(ds, 0x2368);
    ax = 0x003b;
    sub_273a();
    di = pop();
    cx = pop();
    if (--cx)
        goto loc_3fea;
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(es);
    push(ds);
    push(di);
    ax = 0x0000;
    al = memory(ds, 0x236b);
    sub_273a();
    di = pop();
    di += memory16(ds, 0x2368);
    ax = 0x003f;
    sub_273a();
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    dx = pop();
    cx = pop();
    di = pop();
    ax = dx;
    ax += ax;
    memory16(ds, 0x2368) = ax;
loc_4034:
    push(cx);
    di += 0x0400;
    push(di);
    ax = 0x003d;
    sub_273a();
    di = pop();
    push(di);
    di += memory16(ds, 0x2368);
    ax = 0x003d;
    sub_273a();
    di = pop();
    cx = pop();
    if (--cx)
        goto loc_4034;
}
void sub_4052()
{
    memory16(ds, 0x37c6) = 0x5008;
    memory16(ds, 0x37c8) = 0x42fd;
    memory16(ds, 0x28fa) = 0x5a88;
    memory16(ds, 0x28fc) = 0x42fd;
    memory16(ds, 0x26f2) = 0x0000;
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out(dx, al);
    ax = 0x0061;
    sub_2888();
    ax = memory16(ds, 0x001a);
    sub_305b();
    di = 0x0c80;
    dx = 0x0040;
    cx = 0x00be;
    al = 0x60;
    sub_2c94();
    di = 0x4108;
    ax = 0x00c1;
    sub_2c81();
    di = 0x140c;
    ax = 0x00c2;
    sub_2c81();
    di = 0x1416;
    ax = 0x00c3;
    sub_2c81();
    si = 0x3023;
    if (memory16(ds, 0x4f8e) == 0x0003)
        goto loc_40d2;
    si = 0x3059;
    if (memory16(ds, 0x4f8e) == 0x0002)
        goto loc_40d2;
    si = 0x308f;
    if (memory16(ds, 0x4f8e) == 0x0001)
        goto loc_40d2;
    si = 0x30cb;
loc_40d2:
    sub_4ef1();
    sub_2e72();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x30e5;
    di = 0x32b5;
    cx = 0x0008;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x30df;
    sub_4ef1();
    ax = 0x0006;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    dx = 0x0002;
    if (memory16(ds, 0x4f8e) != 0x0000)
        goto loc_4126;
    dx = 0x0001;
loc_4126:
    sub_4d17();
    if (dx == 0x0000)
        goto loc_4135;
    if (memory16(ds, 0x4f8e) != 0x0000)
        goto loc_413b;
loc_4135:
    memory16(ds, 0x26fc) = 0x0001;
loc_413b:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_4155()
{
    memory16(ds, 0x26f2) = 0x0000;
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out(dx, al);
    ax = 0x0000;
    sub_2888();
    ax = memory16(ds, 0x001a);
    sub_305b();
    ax = 0x0009;
    sub_77c8();
    di = 0x08de;
    push(ds);
    sub_23d3();
    ds = pop();
    di = 0x0f00;
    ax = 0x00b7;
    sub_2c81();
    di = 0x6415;
    ax = 0x00b8;
    sub_2c81();
    di = 0x64a6;
    ax = 0x00b8;
    ax += memory16(ds, 0x4f88);
    sub_2c81();
    sub_4241();
    ax = 0x0008;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    memory(ds, 0x2700) = 0x00;
    cx = 0x006c;
loc_41d4:
    push(cx);
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_4212();
    sub_281e();
    sub_4241();
    sub_350c();
    sub_544d();
    cx = pop();
    if (dx != 0x0000)
        goto loc_41f8;
    if (--cx)
        goto loc_41d4;
loc_41f8:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_4212()
{
    ax = memory16(ds, 0x26ee);
    ax += memory16(ds, 0x001e);
    if (ax < 0x0006)
        goto loc_423c;
    ax = 0x0000;
    si = 0x32be;
    memory(ds, 0x2700) = ~memory(ds, 0x2700);
    if (memory(ds, 0x2700) != 0x00)
        goto loc_4232;
    si = 0x32c1;
loc_4232:
    push(ax);
    al = 0x20;
    cx = 0x0001;
    sub_2397();
    ax = pop();
loc_423c:
    memory16(ds, 0x26ee) = ax;
}
void sub_4241()
{
    ax = memory16(ds, 0x4f88);
    ax += ax;
    ax += ax;
    si = 0x328b;
    si += ax;
    lodsw<MemData, DirForward>();
    dx = ax;
    lodsw<MemData, DirForward>();
    cx = ax;
    ax = memory16(ds, 0x001c);
    ax <<= 1;
    ax <<= 1;
    ax &= 0x0018;
    di = 0x326b;
    di += ax;
    si = 0x325b;
    ax = memory16(ds, di);
    memory16(ds, si) = ax;
    ax = memory16(ds, di + 2);
    memory16(ds, si + 2) = ax;
    sub_2782();
}
void sub_4279()
{
    memory16(ds, 0x26f2) = 0x0000;
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out(dx, al);
    al = 0x61;
    sub_2888();
    ax = memory16(ds, 0x001a);
    sub_305b();
    di = 0x320f;
    di += memory16(ds, 0x001a);
    ax = 0x00ac;
    sub_273a();
    di = 0x3223;
    di += memory16(ds, 0x001a);
    ax = memory16(ds, 0x4f88);
    ax += 0x00ad;
    sub_273a();
    di = 0x3227;
    di += memory16(ds, 0x001a);
    ax = memory16(ds, 0x4f8a);
    ax += 0x00ad;
    sub_273a();
    ax = 0x0003;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    cx = 0x0012;
    sub_5429();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
}
void sub_4317()
{
loc_4317:
    memory(ds, 0x0027) = 0xff;
    memory16(ds, 0x37c6) = 0xe2b0;
    memory16(ds, 0x37c8) = 0x1650;
    memory16(ds, 0x28fa) = 0xe2a8;
    memory16(ds, 0x28fc) = 0x1650;
    ax = 0x0008;
    sub_77c8();
    di = 0x34bc;
    push(ds);
    sub_23d3();
    ds = pop();
    al = 0x0d;
    sub_2888();
    memory16(ds, 0x26f2) = 0x0002;
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x20;
    out(dx, al);
    memory16(ds, 0x203e) = 0x0080;
    ax = memory16(ds, 0x001a);
    sub_305b();
    ax = 0x00a1;
    di = 0x3a00;
    sub_2c81();
    bx = 0x34bc;
    sub_23b5();
    ax = 0x0007;
    sub_8c10();
    cx = 0x0095;
loc_437d:
    push(cx);
//    sub_34f3();
    memory16(ds, 0x203e) = memory16(ds, 0x203e) + 3;
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_3503();
    cx = pop();
    cx -= 3;
    if ((short)cx > 0)
        goto loc_437d;
    cx = 0x0002;
loc_4394:
    push(cx);
    push(ds);
    di = 0x2a86;
    di += memory16(ds, 0x0018);
    si = 0xb680;
    ax = 0x1650;
    ds = ax;
    dx = 0x000a;
    cx = 0x0034;
    ax = 0x0000;
    sub_25ae();
    ds = pop();
    push(ds);
    di = 0x2850;
    di += memory16(ds, 0x0018);
    si = 0xb6a8;
    ax = 0x1650;
    ds = ax;
    dx = 0x000e;
    cx = 0x0033;
    ax = 0x0000;
    sub_25ae();
    ds = pop();
    push(ds);
    di = 0x2fd4;
    di += memory16(ds, 0x0018);
    si = 0xb6e8;
    ax = 0x1650;
    ds = ax;
    dx = 0x002a;
    cx = 0x0022;
    ax = 0x0000;
    sub_25ae();
    ds = pop();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    cx = pop();
    if (--cx)
        goto loc_4394;
loc_43f8:
    sub_4e4c();
    si = 0x2928;
    sub_4ef1();
    sub_49b3();
    dx = 0x0004;
    sub_4d17();
    if (memory(ds, 0x0026) == 0x00)
        goto loc_441a;
    memory16(ds, 0x26fc) = 0x0001;
    goto loc_462c;
loc_441a:
    if (dx == 0x0000)
        goto loc_4432;
    si = 0x28d6;
    sub_4e81(); // blikanica
    if (memory16(ds, 0x26fc) != 0x0002)
        goto loc_442f;
    goto loc_4435;
loc_442f:
    goto loc_462c;
loc_4432:
    goto loc_4673;
loc_4435:
    sub_4e4c();
    si = 0x2a24;
    sub_4ef1();
    sub_49b3();
    dx = 0x0005;
    memory(ds, 0x0027) = 0x00;
    sub_4d17();
    if (dx == 0x0000)
        goto loc_4432;
    si = 0x28e6;
    sub_4e81();
    if (memory16(ds, 0x26fc) != 0x0000)
        goto loc_44d3;
    sub_4e4c();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x205d;
    di = 0x3234;
    cx = 0x0016;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    memory16(ds, 0x3232) = 0x3234;
    si = 0x205d;
    cx = 0x000b;
loc_4480:
    memory16(ds, si) = 0xffff;
    si += 0x0002;
    if (--cx)
        goto loc_4480;
    si = 0x2ac8;
    sub_4ef1();
    cx = 0x0008;
    sub_5429();
    bx = 0x205d;
    sub_4c70();
    sub_4e4c();
    si = 0x2af4;
    sub_4ef1();
    cx = 0x0008;
    sub_5429();
    memory16(ds, 0x3232) = memory16(ds, 0x3232) + 0x0002;
    bx = 0x2069;
    sub_4c70();
    sub_4e4c();
    si = 0x2ca6;
    sub_4ef1();
    cx = 0x0008;
    sub_5429();
    sub_4cd0();
    bx = 0x205d;
    memory16(ds, bx + 10) = ax;
    goto loc_4435;
loc_44d3:
    if (memory16(ds, 0x26fc) == 0x0001)
        goto loc_44dd;
    goto loc_456c;
loc_44dd:
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    sub_4e4c();
    memory(ds, 0x2701) = 0x04;
    memory(ds, 0x2702) = 0x05;
    if (memory(ds, 0x37f9) != 0x00)
        goto loc_4505;
    memory(ds, 0x2701) = 0xff;
loc_4505:
    if (memory(ds, 0x37fa) != 0x00)
        goto loc_4512;
    memory(ds, 0x2702) = 0xff;
loc_4512:
    bx = 0x37fc;
    memory(ds, bx) = 0xff;
    memory(ds, bx + 1) = 0xff;
    memory(ds, bx + 2) = 0xff;
    memory(ds, bx + 3) = 0xff;
    si = 0x2d12;
    sub_4ef1();
    si = 0x2d8e;
    sub_4a5f();
    ax = memory16(ds, 0x26fc);
    memory(ds, bx) = al;
    si = 0x2dba;
    sub_4a5f();
    ax = memory16(ds, 0x26fc);
    memory(ds, bx + 1) = al;
    si = 0x2de6;
    sub_4a5f();
    ax = memory16(ds, 0x26fc);
    memory(ds, bx + 2) = al;
    si = 0x2e12;
    sub_4a5f();
    ax = memory16(ds, 0x26fc);
    memory(ds, bx + 3) = al;
    memory16(ds, 0x26fc) = 0x0000;
    goto loc_4435;
loc_456c:
    if (memory16(ds, 0x26fc) == 0x0002)
        goto loc_4576;
    goto loc_460d;
loc_4576:
    sub_4e4c();
    si = 0x2f25;
    sub_4ef1();
    di = 0x0000;
    si = 0x39c0;
    cx = 0x2540;
    sub_2922();
    sub_34f3();
    dx = 0x03d4;
    al = 0x07;
    out(dx, al);
    dx = 0x03d5;
    in(al, dx);
    al &= 0xef;
    dx = 0x03d5;
    al = al;
    out(dx, al);
    dx = 0x03d4;
    al = 0x09;
    out(dx, al);
    dx = 0x03d5;
    in(al, dx);
    al &= 0xbf;
    dx = 0x03d5;
    al = al;
    out(dx, al);
    dx = 0x03d4;
    al = 0x18;
    out(dx, al);
    dx = 0x03d5;
    al = 0xa3;
    out(dx, al);
    dx = 0x03da;
    in(al, dx);
    dx = 0x03c0;
    al = 0x30;
    out(dx, al);
    dx = 0x03c0;
    al = 0x61;
    out(dx, al);
    sub_49bd();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    dx = 0x03d4;
    al = 0x07;
    out(dx, al);
    dx = 0x03d5;
    in(al, dx);
    al |= 0x10;
    dx = 0x03d5;
    al = al;
    out(dx, al);
    dx = 0x03d4;
    al = 0x09;
    out(dx, al);
    dx = 0x03d5;
    in(al, dx);
    al |= 0x40;
    dx = 0x03d5;
    al = al;
    out(dx, al);
    dx = 0x03d4;
    al = 0x18;
    out(dx, al);
    dx = 0x03d5;
    al = 0xff;
    out(dx, al);
    goto loc_4435;
loc_460d:
    if (memory16(ds, 0x26fc) != 0x0003)
        goto loc_4629;
    sub_4e4c();
    si = 0x2fe1;
    sub_4ef1();
    sub_5970();
    cx = 0x0007;
    sub_5429();
    goto loc_4435;
loc_4629:
    goto loc_43f8;
loc_462c:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    if (memory16(ds, 0x26fc) == 0x0003)
        goto loc_469b;
    if (memory16(ds, 0x26fc) == 0x0001)
        goto loc_467b;
    if (memory16(ds, 0x26fc) == 0x0000)
        goto loc_4688;
    memory16(ds, 0x4f88) = 0xffff;
    memory16(ds, 0x4f8a) = 0x0001;
    return;
loc_4673:
    memory16(ds, 0x26fc) = 0xffff;
    goto loc_462c;
loc_467b:
    memory16(ds, 0x4f88) = 0x0000;
    memory16(ds, 0x4f8a) = 0x0001;
    return;
loc_4688:
    memory16(ds, 0x4f88) = 0x0001;
    memory16(ds, 0x4f8a) = 0x0001;
    sub_8d8e();
    return;
loc_4698:
    goto loc_4957;
loc_469b:
    al = 0x2d;
    sub_2888();
    si = 0x30ee;
    sub_4ef1();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x34bc;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x34bc;
    sub_23b5();
    memory16(ds, 0x26ea) = 0x0000;
    memory16(ds, 0x26ec) = 0x0000;
    memory16(ds, 0x26e8) = 0x0000;
    si = 0x32af;
    sub_532b();
    sub_2318();
    si = 0x32af;
    sub_532b();
    sub_2318();
    sub_4999();
loc_46ef:
    if (memory(ds, 0x0020) == 0x01)
        goto loc_4698;
    sub_3503();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_281e();
    sub_5476();
    memory(ds, 0x2700) = memory(ds, 0x2700) + 1;
    if (al & 0x1f)
        goto loc_4719;
    memory(ds, 0x2700) = 0x00;
loc_4719:
    if ((char)memory(ds, 0x2700) >= 0)
        goto loc_4723;
    goto loc_4861;
loc_4723:
    if (!(al & 0x10))
        goto loc_4795;
    if (memory16(ds, 0x26ec) != 0x0002)
        goto loc_4743;
    if (memory16(ds, 0x26ea) == 0x0008)
        goto loc_4798;
    if (memory16(ds, 0x26ea) == 0x0007)
        goto loc_479b;
    if (memory16(ds, 0x26ea) == 0x0006)
        goto loc_47b4;
loc_4743:
    push(ax);
    di = 0x5418;
    ax = memory16(ds, 0x26e8);
    ax += ax;
    di += ax;
    dx = 0x0002;
    cx = 0x0008;
    al = 0x2d;
    sub_2c94();
    sub_497f();
    ax = memory16(ds, si + 4);
    si = 0x32b5;
    si += memory16(ds, 0x26e8);
    memory(ds, si) = al;
    si = 0x32af;
    sub_532b();
    sub_2318();
    si = 0x32af;
    sub_532b();
    sub_2318();
    memory(ds, 0x2700) = 0xf6;
    if (memory16(ds, 0x26e8) == 0x0007)
        goto loc_478e;
    memory16(ds, 0x26e8) = memory16(ds, 0x26e8) + 1;
loc_478e:
    sub_4999();
    ax = pop();
    goto loc_47cd;
loc_4795:
    goto loc_47cd;
loc_4798:
    goto loc_48b7;
loc_479b:
    if (memory16(ds, 0x26e8) == 0x0007)
        goto loc_47cd;
    memory16(ds, 0x26e8) = memory16(ds, 0x26e8) + 1;
    push(ax);
    sub_4999();
    ax = pop();
    memory(ds, 0x2700) = 0xf6;
    goto loc_47cd;
loc_47b4:
    if (memory16(ds, 0x26e8) == 0x0000)
        goto loc_47cd;
    memory16(ds, 0x26e8) = memory16(ds, 0x26e8) - 1;
    push(ax);
    sub_4999();
    ax = pop();
    memory(ds, 0x2700) = 0xf6;
    goto loc_47cd;
loc_47cd:
    if (!(al & 0x08))
        goto loc_47fc;
    if (memory16(ds, 0x26ec) != 0x0002)
        goto loc_47e5;
    if (memory16(ds, 0x26ea) != 0x0008)
        goto loc_47f2;
    memory16(ds, 0x26ea) = 0xffff;
loc_47e5:
    if (memory16(ds, 0x26ea) != 0x0009)
        goto loc_47f2;
    memory16(ds, 0x26ea) = 0xffff;
loc_47f2:
    memory16(ds, 0x26ea) = memory16(ds, 0x26ea) + 1;
    memory(ds, 0x2700) = 0xf6;
loc_47fc:
    if (!(al & 0x04))
        goto loc_4817;
    if (memory16(ds, 0x26ea) != 0x0000)
        goto loc_480d;
    memory16(ds, 0x26ea) = 0x000a;
loc_480d:
    memory16(ds, 0x26ea) = memory16(ds, 0x26ea) - 1;
    memory(ds, 0x2700) = 0xf6;
loc_4817:
    if (!(al & 0x01))
        goto loc_4832;
    if (memory16(ds, 0x26ec) != 0x0000)
        goto loc_4828;
    memory16(ds, 0x26ec) = 0x0003;
loc_4828:
    memory16(ds, 0x26ec) = memory16(ds, 0x26ec) - 1;
    memory(ds, 0x2700) = 0xf6;
loc_4832:
    if (!(al & 0x02))
        goto loc_484d;
    if (memory16(ds, 0x26ec) != 0x0002)
        goto loc_4843;
    memory16(ds, 0x26ec) = 0xffff;
loc_4843:
    memory16(ds, 0x26ec) = memory16(ds, 0x26ec) + 1;
    memory(ds, 0x2700) = 0xf6;
loc_484d:
    if (memory16(ds, 0x26ec) != 0x0002)
        goto loc_4861;
    if (memory16(ds, 0x26ea) != 0x0009)
        goto loc_4861;
    memory16(ds, 0x26ea) = 0x0008;
loc_4861:
    ax = memory16(ds, 0x001c);
    ax <<= 1;
    ax &= 0x000c;
    si = 0x315e;
    si += ax;
    di = 0x3222;
    lodsw<MemData, DirForward>();
    memory16(ds, di) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 2) = ax;
    sub_497f();
    push(si);
    lodsw<MemData, DirForward>();
    dx = ax;
    lodsw<MemData, DirForward>();
    cx = ax;
    cx -= 0x000a;
    dx -= 0x0006;
    si = 0x3222;
    sub_2782();
    si = pop();
    di = 0x3252;
    lodsw<MemData, DirForward>();
    memory16(ds, di) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 2) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 6) = ax;
    if (ax != 0x4e45)
        goto loc_48ae;
    memory16(ds, di) = memory16(ds, di) - 0x0004;
loc_48ae:
    si = 0x3252;
    sub_532b();
    goto loc_46ef;
loc_48b7:
    si = 0x32b5;
    if (memory16(ds, si) != 0x2020)
        goto loc_48e3;
    if (memory16(ds, si + 2) != 0x2020)
        goto loc_48e3;
    if (memory16(ds, si + 4) != 0x2020)
        goto loc_48e3;
    if (memory16(ds, si + 6) != 0x2020)
        goto loc_48e3;
    ax = 0x0004;
    sub_8ca1();
    goto loc_46ef;
loc_48e3:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x32b5;
    di = 0x30e5;
    cx = 0x0008;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    sub_2cf6();
    if (dx == 0x0000)
        goto loc_4931;
    memory16(ds, 0x26e8) = 0x0000;
    push(cx);
    cx = ds;
    es = cx;
    di = 0x32b5;
    cx = 0x0008;
    al = 0x20;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x5418;
    dx = 0x0010;
    cx = 0x0008;
    al = 0x2d;
    sub_2c94();
    sub_4999();
    sub_49b3();
    ax = 0x0004;
    sub_8ca1();
    goto loc_46ef;
loc_4931:
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    return;
loc_4957:
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    goto loc_4317;
}
void sub_497f()
{
    ax = memory16(ds, 0x26ec);
    cx = 0x003c;
    mul(cx);
    push(ax);
    ax = memory16(ds, 0x26ea);
    cx = 0x0006;
    mul(cx);
    si = 0x316e;
    si += ax;
    ax = pop();
    si += ax;
}
void sub_4999()
{
    di = 0x5698;
    ax = 0x00c4;
    sub_2c81();
    di = 0x5698;
    ax = memory16(ds, 0x26e8);
    ax += ax;
    di += ax;
    ax = 0x00c5;
    sub_2c81();
}
void sub_49b3()
{
loc_49b3:
    sync();
    sub_5476();
    al &= 0x10;
    if (al != 0x00)
        goto loc_49b3;
}
void sub_49bd()
{
    si = 0x2166;
loc_49c0:
    lodsw<MemData, DirForward>();
    if (ax != 0xffff)
        goto loc_49ca;
    si = 0x2166;
    lodsw<MemData, DirForward>();
loc_49ca:
    push(si);
    push(ax);
    ax >>= 1;
    ax >>= 1;
    bx = 0x2540;
    bx += ax;
    dx = 0x03d4;
    al = 0x0c;
    out(dx, al);
    dx = 0x03d5;
    al = bh;
    out(dx, al);
    dx = 0x03d4;
    al = 0x0d;
    out(dx, al);
    dx = 0x03d5;
    al = bl;
    out(dx, al);
    dx = 0x03da;
    in(al, dx);
    dx = 0x03c0;
    al = 0x33;
    out(dx, al);
    ax = pop();
    ax &= 0x0003;
    if (memory(ds, 0x0024) == 0x01)
        goto loc_4a04;
    al += al;
loc_4a04:
    dx = 0x03c0;
    al = al;
    out(dx, al);
    dx = 0x03da;
    in(al, dx);
    sub_34f3();
    sub_3503();
    sub_5476();
    ah = al;
    ah &= 0x0f;
    if (ah == 0x00)
        goto loc_4a35;
    if (memory(ds, 0x2700) == 0xff)
        goto loc_4a3b;
    memory(ds, 0x0024) = memory(ds, 0x0024) ^ 0x01;
    memory(ds, 0x2700) = 0xff;
    goto loc_4a3b;
loc_4a35:
    memory(ds, 0x2700) = 0x00;
loc_4a3b:
    sub_544d();
    si = pop();
    if (dx != 0x0000)
        goto loc_4a47;
    goto loc_49c0;
loc_4a47:
    dx = 0x03da;
    in(al, dx);
    dx = 0x03c0;
    al = 0x33;
    out(dx, al);
    ax = 0x0000;
    dx = 0x03c0;
    al = al;
    out(dx, al);
    dx = 0x03da;
    in(al, dx);
}
void sub_4a5f()
{
    push(bx);
    ax = memory16(ds, si + 2);
    push(ax);
    sub_4ef1();
    ax = pop();
    dx = ax;
    dx -= 0x0001;
    si = 0x2e3e;
    di = memory16(ds, si);
    memory16(ds, di + 2) = ax;
    memory16(ds, di + 19) = dx;
    di = memory16(ds, si + 2);
    memory16(ds, di + 2) = ax;
    memory16(ds, di + 19) = dx;
    di = memory16(ds, si + 4);
    memory16(ds, di + 2) = ax;
    memory16(ds, di + 19) = dx;
    di = memory16(ds, si + 6);
    memory16(ds, di + 2) = ax;
    memory16(ds, di + 19) = dx;
    di = memory16(ds, si + 8);
    memory16(ds, di + 2) = ax;
    memory16(ds, di + 19) = dx;
    di = memory16(ds, si + 10);
    memory16(ds, di + 2) = ax;
    memory16(ds, di + 19) = dx;
loc_4ab9:
    sub_5476();
    al &= 0x1f;
    if (al != 0x00)
        goto loc_4ab9;
    sub_4ac7();
    bx = pop();
}
void sub_4ac7()
{
    memory16(ds, 0x26fc) = 0x0000;
    ax = 0x0009;
    goto loc_4b42;
loc_4ad3:
    sub_281e();
    si = 0x2e3e;
    ax = memory16(ds, 0x26fc);
    if (ax <= 0x0005)
        goto loc_4ae9;
    if ((short)ax >= 0)
        goto loc_4ae9;
    ax = 0x0006;
loc_4ae9:
    ax += ax;
    si += ax;
    si = memory16(ds, si);
    push(si);
    ax = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx--;
    sub_584c();
    di += memory16(ds, 0x0018);
    si = di;
    ax = 0x25f0;
    es = ax;
    di = 0x1400;
    dx = 0x0016;
    cx = 0x0009;
    sub_27d4();
    si = pop();
    push(bx);
    sub_532b();
    bx = pop();
    sub_34f3();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
loc_4b27:
//    sync();
    sub_5476();
    if (al & 0x10)
        goto loc_4b7b;
    if (memory(ds, 0x2700) != 0x00)
        goto loc_4b78;
    if (!(al & 0x08))
        goto loc_4b7e;
    memory(ds, 0x2700) = 0xff;
    ax = memory16(ds, 0x26fc);
loc_4b42:
    ax++;
    if (ax < 0x0006)
        goto loc_4b4b;
    ax = 0x0000;
loc_4b4b:
    bx = 0x37fc;
    if (memory(ds, bx) == al)
        goto loc_4b42;
    if (memory(ds, bx + 1) == al)
        goto loc_4b42;
    if (memory(ds, bx + 2) == al)
        goto loc_4b42;
    if (memory(ds, bx + 3) == al)
        goto loc_4b42;
    if (memory(ds, 0x2701) == al)
        goto loc_4b42;
    if (memory(ds, 0x2702) == al)
        goto loc_4b42;
    memory16(ds, 0x26fc) = ax;
    goto loc_4ad3;
loc_4b78:
    goto loc_4bc4;
loc_4b7b:
    goto loc_4bd3;
loc_4b7e:
    if (!(al & 0x04))
        goto loc_4bc1;
    memory(ds, 0x2700) = 0xff;
    ax = memory16(ds, 0x26fc);
loc_4b8b:
    ax--;
    if ((short)ax >= 0)
        goto loc_4b94;
    ax = 0x0005;
loc_4b94:
    bx = 0x37fc;
    if (memory(ds, bx) == al)
        goto loc_4b8b;
    if (memory(ds, bx + 1) == al)
        goto loc_4b8b;
    if (memory(ds, bx + 2) == al)
        goto loc_4b8b;
    if (memory(ds, bx + 3) == al)
        goto loc_4b8b;
    if (memory(ds, 0x2701) == al)
        goto loc_4b8b;
    if (memory(ds, 0x2702) == al)
        goto loc_4b8b;
    memory16(ds, 0x26fc) = ax;
    goto loc_4ad3;
loc_4bc1:
    goto loc_4b27;
loc_4bc4:
    al &= 0x0c;
    if (al != 0x00)
        goto loc_4bd0;
    memory(ds, 0x2700) = 0x00;
loc_4bd0:
    goto loc_4b27;
loc_4bd3:
    sub_281e();
    sub_2801();
    sub_2318();
    si = 0x2e3e;
    ax = memory16(ds, 0x26fc);
    ax += ax;
    si += ax;
    si = memory16(ds, si);
    sub_4ef1();
}
void sub_4bee()
{
    push(bx);
    ax = ds;
    es = ax;
    dx = di;
    di += 0x0016;
    al = 0x20;
    cx = 0x0007;
    rep_stosb<MemData, DirForward>();
    di = dx;
    di += 0x003d;
    cx = 0x0007;
    rep_stosb<MemData, DirForward>();
    bx = memory16(ds, 0x3232);
    al = memory(ds, bx + 1);
    memory16(ds, 0x3232) = memory16(ds, 0x3232) + 0x0002;
    si = 0x32c4;
loc_4c19:
    if (memory(ds, si) == al)
        goto loc_4c2c;
    if (memory(ds, si) == 0xff)
        goto loc_4c43;
    si += 0x0008;
    goto loc_4c19;
loc_4c2c:
    si++;
    push(si);
    di = dx;
    di += 0x001e;
    cx = 0x0007;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    di = dx;
    di += 0x0045;
    cx = 0x0007;
    rep_movsb<MemData, MemData, DirForward>();
loc_4c43:
    si = dx;
    sub_4ef1();
    bx = pop();
}
void sub_4c4a()
{
    dx = di;
    ax = ds;
    es = ax;
    si = memory16(ds, 0x26e6);
    di += 0x0016;
    cx = 0x0007;
    rep_movsb<MemData, MemData, DirForward>();
    di = dx;
    si = memory16(ds, 0x26e6);
    di += 0x003d;
    cx = 0x0007;
    rep_movsb<MemData, MemData, DirForward>();
    si = dx;
    sub_4ef1();
}
void sub_4c70()
{
    di = 0x2b20;
    sub_4bee();
    sub_4cd0();
    memory16(ds, bx) = ax;
    di = 0x2b20;
    sub_4c4a();
    di = 0x2b6e;
    sub_4bee();
    sub_4cd0();
    memory16(ds, bx + 2) = ax;
    di = 0x2b6e;
    sub_4c4a();
    di = 0x2bbc;
    sub_4bee();
    sub_4cd0();
    memory16(ds, bx + 4) = ax;
    di = 0x2bbc;
    sub_4c4a();
    di = 0x2c0a;
    sub_4bee();
    sub_4cd0();
    memory16(ds, bx + 6) = ax;
    di = 0x2c0a;
    sub_4c4a();
    di = 0x2c58;
    sub_4bee();
    sub_4cd0();
    memory16(ds, bx + 8) = ax;
    di = 0x2c58;
    sub_4c4a();
}
void sub_4cd0()
{
    sync();

    return;
loc_4cd0:
    memory(ds, 0x0020) = 0xff;
loc_4cd5:
    sync();
    al = memory(ds, 0x0020);
    if ((char)al < 0)
        goto loc_4cd5;
    if (al == 0x2a)
        goto loc_4cd5;
    si = 0x205e;
    cx = 0x000b;
loc_4ce6:
    if (memory(ds, si) == al)
        goto loc_4cd0;
    si += 0x0002;
    if (--cx)
        goto loc_4ce6;
    si = 0x32c4;
loc_4cf4:
    if (memory(ds, si) == al)
        goto loc_4d07;
    if (memory(ds, si) == 0xff)
        goto loc_4cd0;
    si += 0x0008;
    goto loc_4cf4;
loc_4d07:
    si++;
    memory16(ds, 0x26e6) = si;
    ah = al;
    al += 0x80;
loc_4d10:
    if (memory(ds, 0x0020) != al)
        goto loc_4d10;
}
void sub_4d17()
{
    dx--;
    memory16(ds, 0x26fe) = dx;
    memory16(ds, 0x26fc) = 0x0000;
    memory(ds, 0x0020) = 0x00;
    memory16(ds, 0x26e4) = 0x0000;
loc_4d2d:
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_281e();
    if (memory(ds, 0x0020) == 0x01)
        goto loc_4dad;
    sub_5476();
    if (memory16(ds, 0x37e4) == 0xffff)
        goto loc_4d77;
    if (memory(ds, 0x0020) != 0x48)
        goto loc_4d5b;
    al |= 0x01;
    memory(ds, 0x0020) = 0x00;
loc_4d5b:
    if (memory(ds, 0x0020) != 0x50)
        goto loc_4d69;
    al |= 0x02;
    memory(ds, 0x0020) = 0x00;
loc_4d69:
    if (memory(ds, 0x0020) != 0x1c)
        goto loc_4d77;
    al |= 0x10;
    memory(ds, 0x0020) = 0x00;
loc_4d77:
    ah = al;
    al &= 0x10;
    if (al != 0)
        goto loc_4db6;
    al = ah;
    al &= 0x03;
    if (al == 0)
        goto loc_4db9;
    memory16(ds, 0x26e4) = 0x0000;
    if (memory(ds, 0x2700) != 0x00)
        goto loc_4dfc;
    al = ah;
    al &= 0x01;
    if (al == 0)
        goto loc_4dda;
    memory(ds, 0x2700) = 0xff;
    if (memory16(ds, 0x26fc) != 0x0000)
        goto loc_4db0;
    dx = memory16(ds, 0x26fe);
    memory16(ds, 0x26fc) = dx;
    goto loc_4dfc;
loc_4dad:
    goto loc_4e42;
loc_4db0:
    memory16(ds, 0x26fc) = memory16(ds, 0x26fc) - 1;
    goto loc_4dfc;
loc_4db6:
    goto loc_4e38;
loc_4db9:
    memory(ds, 0x2700) = 0x00;
    if (memory(ds, 0x0027) == 0x00)
        goto loc_4dfc;
    memory16(ds, 0x26e4) = memory16(ds, 0x26e4) + 1;
    if (memory16(ds, 0x26e4) < 0x021c)
        goto loc_4dfc;
    memory(ds, 0x0026) = 0xff;
    goto loc_4e42;
loc_4dda:
    al = ah;
    al &= 0x02;
    if (al == 0)
        goto loc_4dfc;
    memory(ds, 0x2700) = 0xff;
    dx = memory16(ds, 0x26fe);
    if (memory16(ds, 0x26fc) != dx)
        goto loc_4df8;
    memory16(ds, 0x26fc) = 0x0000;
    goto loc_4dfc;
loc_4df8:
    memory16(ds, 0x26fc) = memory16(ds, 0x26fc) + 1;
loc_4dfc:
    si = 0x28d6;
    if (memory16(ds, 0x26fe) != 0x0004)
        goto loc_4e09;
    si = 0x28e6;
loc_4e09:
    if (memory16(ds, 0x26fe) != 0x0001)
        goto loc_4e13;
    si = 0x324a;
loc_4e13:
    if (memory16(ds, 0x26fe) != 0x0000)
        goto loc_4e1d;
    si = 0x324e;
loc_4e1d:
    ax = memory16(ds, 0x26fc);
    ax += ax;
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    dx = ax;
    lodsw<MemData, DirForward>();
    cx = ax;
    si = 0x28fa;
    sub_2782();
    sub_350c();
    goto loc_4d2d;
loc_4e38:
    memory16(ds, 0x26e4) = 0x0000;
    dx = 0xffff;
    return;
loc_4e42:
    memory16(ds, 0x26e4) = 0x0000;
    dx = 0x0000;
}
void sub_4e4c()
{
    si = 0x1900;
    di = 0x3f00;
    push(ds);
    di += memory16(ds, 0x0018);
    ax = 0x1650;
    ds = ax;
    dx = 0x0040;
    cx = 0x0060;
    sub_24dc();
    ds = pop();
    si = 0x1900;
    di = 0x3f00;
    push(ds);
    di += memory16(ds, 0x001a);
    ax = 0x1650;
    ds = ax;
    dx = 0x0040;
    cx = 0x0060;
    sub_24dc();
    ds = pop();
}
void sub_4e81()
{
    push(si);
    ax = memory16(ds, 0x26fc);
    si += 0x0002;
    ax += ax;
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    bx = ax;
    cx = 0x0040;
    mul(cx);
    di = ax;
    ax = bx;
    ax -= 0x00e8;
    cx = 0x0140;
    mul(cx);
    si = ax;
    push(ds);
    di += memory16(ds, 0x0018);
    ax = 0x1650;
    ds = ax;
    dx = 0x0040;
    cx = 0x0008;
    sub_24dc();
    ds = pop();
    si = pop();
    cx = 0x0008;
loc_4ebc:
    push(cx);
    push(si);
    sub_34f3();
    sub_281e();
    ax = memory16(ds, 0x26fc);
    si = pop();
    push(si);
    ax += ax;
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    dx = ax;
    lodsw<MemData, DirForward>();
    cx = ax;
    si = 0x28fa;
    sub_2782();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    cx = 0x0005;
loc_4ee7:
    sub_350c();
    if (--cx)
        goto loc_4ee7;
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_4ebc;
}
void sub_4ef1()
{
    push(bx);
    push(si);
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_532b();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    si = pop();
    sub_532b();
    bx = pop();
}
void sub_4f14()
{
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_4f2f;
    memory16(ds, 0x203e) = 0x0080;
    bx = memory16(ds, 0x4f78);
    ax = memory16(ds, bx);
    memory16(ds, 0x26f2) = ax;
    goto loc_4f35;
    //   gap of 1 bytes
loc_4f2f:
    memory16(ds, 0x26f2) = 0x0000;
loc_4f35:
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_4f4a;
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out(dx, al);
    goto loc_4f56;
loc_4f4a:
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x20;
    out(dx, al);
loc_4f56:
    if (memory16(ds, 0x26f2) != 0x0000)
        goto loc_4f6a;
    memory16(ds, 0x26f4) = 0x000f;
    memory16(ds, 0x26f6) = 0x000d;
    return;
loc_4f6a:
    if (memory16(ds, 0x26f2) != 0x0001)
        goto loc_4f7e;
    memory16(ds, 0x26f4) = 0x001f;
    memory16(ds, 0x26f6) = 0x000d;
    return;
loc_4f7e:
    memory16(ds, 0x26f4) = 0x000f;
    memory16(ds, 0x26f6) = 0x001d;
}
void sub_4f8b()
{
    si = 0x271c;
    ax = memory16(ds, 0x4f88);
    ax += ax;
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    memory16(ds, 0x26f8) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, 0x26fa) = ax;
    si = 0x0726;
    di = 0x0c02;
    if (memory16(ds, 0x26f2) != 0x0002)
        goto loc_4faf;
    di = 0x0602;
loc_4faf:
    cx = memory16(ds, 0x26f6);
loc_4fb3:
    push(cx);
    push(di);
    cx = memory16(ds, 0x26f4);
loc_4fb9:
    push(cx);
    lodsb<MemData, DirForward>();
    ah = al;
    push(si);
    si = memory16(ds, 0x26f8);
    bx = 0xfffe;
loc_4fc5:
    bx += 0x0002;
    lodsb<MemData, DirForward>();
    if (al == 0xff)
        goto loc_4fd1;
    if (ah != al)
        goto loc_4fc5;
loc_4fd1:
    si = memory16(ds, 0x26fa);
    si += bx;
    lodsw<MemData, DirForward>();
    sub_4ffe();
    push(di);
    sub_2c81();
    di = pop();
    di += 0x0004;
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_4fb9;
    di = pop();
    cx = pop();
    di += 0x0400;
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_4ff8;
    di += 0x0400;
loc_4ff8:
    if (--cx)
        goto loc_4fb3;
    sub_504e();
}
void sub_4ffe()
{
    if (memory16(ds, 0x4f88) == 0x0000)
        return;
    if (ax == 0x0000)
        goto loc_500f;
    if (ax != 0x0069)
        return;
loc_500f:
    push(dx);
    push(cx);
    dx = di;
    if (memory16(ds, 0x26f2) != 0x0002)
        goto loc_5023;
    dx -= 0x0602;
    push(dx);
    cl = 0x0a;
    goto loc_502a;
loc_5023:
    dx -= 0x0c02;
    push(dx);
    cl = 0x0b;
loc_502a:
    dx >>= cl;
    if (dx == 0x0001)
        goto loc_504a;
    dx &= 0x0001;
    if (dx == 0x0000)
        goto loc_504a;
    dx = pop();
    push(dx);
    cl = 0x02;
    dx >>= cl;
    dx &= 0x0001;
    if (dx != 0x0000)
        goto loc_504a;
    ax = 0x006a;
loc_504a:
    dx = pop();
    cx = pop();
    dx = pop();
}
void sub_504e()
{
    if (memory16(ds, 0x4f88) != 0x0000)
        goto loc_5068;
    di = 0x0c00;
    ax = 0x000f;
    sub_50ca();
    di = 0x0c3e;
    ax = 0x0010;
    sub_50ca();
    return;
loc_5068:
    if (memory16(ds, 0x26f2) == 0x0001)
        goto loc_5092;
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_50ae;
    di = 0x0c00;
    ax = 0x0083;
    sub_50ca();
    di = 0x0c3e;
    ax = 0x007c;
    sub_50ca();
    si = 0x290a;
    cx = 0x0002;
    sub_2ce0();
    return;
loc_5092:
    di = 0x0c00;
    ax = 0x0083;
    sub_50ca();
    di = 0x0c7e;
    ax = 0x007c;
    sub_50ca();
    si = 0x2914;
    cx = 0x0002;
    sub_2ce0();
    return;
loc_50ae:
    di = 0x0600;
    ax = 0x0083;
    sub_50ca();
    di = 0x063e;
    ax = 0x007c;
    sub_50ca();
    si = 0x291e;
    cx = 0x0002;
    sub_2ce0();
}
void sub_50ca()
{
    cx = memory16(ds, 0x26f6);
loc_50ce:
    push(cx);
    push(di);
    push(ax);
    sub_2c81();
    ax = pop();
    di = pop();
    cx = pop();
    di += 0x0400;
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_50e6;
    di += 0x0400;
loc_50e6:
    if (--cx)
        goto loc_50ce;
}
void sub_50e9()
{
    if (memory16(ds, 0x4f88) != 0x0000)
        goto loc_5139;
    si = 0x2704;
    ax = memory16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    ax += ax;
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    cx = ax;
    push(si);
    dl = 0x2e;
    dh = 0x41;
    sub_518d();
    si = pop();
    lodsw<MemData, DirForward>();
    cx = ax;
    push(si);
    dl = 0x42;
    dh = 0x41;
    sub_518d();
    si = pop();
    lodsw<MemData, DirForward>();
    cx = ax;
    push(si);
    dl = 0x43;
    dh = 0x41;
    sub_518d();
    si = pop();
    lodsw<MemData, DirForward>();
    cx = ax;
    push(si);
    if (memory16(ds, 0x0012) == 0x0000)
        goto loc_5137;
    dl = 0x44;
    dh = 0x41;
    sub_518d();
loc_5137:
    si = pop();
    return;
loc_5139:
    bx = memory16(ds, 0x26f2);
    bx += bx;
    si = 0x34b6;
    ax = memory16(ds, bx + si);
    bx = memory16(ds, 0x4f78);
    cx = memory16(ds, bx + 2);
    ax -= cx;
    memory16(ds, 0x4f6e) = ax;
    dx = 0x452e;
    sub_518d();
    memory16(ds, 0x4f92) = 0x0000;
    cx = 0x0001;
    bx = memory16(ds, 0x4f78);
    dx = memory16(ds, bx + 4);
    if (dx == 0xffff)
        goto loc_5177;
    dh = 0x45;
    sub_518d();
    memory16(ds, 0x4f92) = ax;
loc_5177:
    cx = 0x0001;
    bx = memory16(ds, 0x4f78);
    dx = memory16(ds, bx + 6);
    if (dx == 0xffff)
        return;
    dh = 0x45;
    sub_518d();
}
void sub_518d()
{
loc_518d:
    push(cx);
    push(dx);
loc_518f:
    push(dx);
    ax = memory16(ds, 0x26f6);
    ax++;
    sub_587c();
    push(ax);
    ax = memory16(ds, 0x26f4);
    ax++;
    sub_587c();
    dx = pop();
    ah = dl;
    bx = ax;
    sub_5832();
    dx = pop();
    if (al != dh)
        goto loc_518f;
    ax = bx;
    dx = pop();
    sub_57b4();
    cx = pop();
    if (--cx)
        goto loc_518d;
}
void sub_51b6()
{
    memory(ds, 0x37f9) = 0xff;
    memory(ds, 0x37fa) = 0xff;
    ah = 0x84;
    dx = 0x0001;
    interrupt(0x15);
    if (flags.carry)
        return;
    if (ax == 0x0000)
        goto loc_51e4;
    memory(ds, 0x37f9) = 0x00;
    ax &= 0x00ff;
    cx &= 0x00ff;
    memory16(ds, 0x37bc) = ax;
    memory16(ds, 0x37be) = bx;
loc_51e4:
    if (cx == 0x0000)
        return;
    memory(ds, 0x37fa) = 0x00;
    ax &= 0x00ff;
    cx &= 0x00ff;
    memory16(ds, 0x37c0) = cx;
    memory16(ds, 0x37c2) = dx;
}
void sub_51ff()
{
    sub_521e();
    sub_5264();
    sub_52aa();
    sub_5300();
    sub_2318();
    sub_521e();
    sub_5264();
    sub_52aa();
    sub_5300();
    sub_2318();
}
void sub_521e()
{
    if (memory16(ds, 0x26f2) == 0x0000)
        goto loc_523b;
    if (memory16(ds, 0x26f2) == 0x0001)
        goto loc_5236;
    di = memory16(ds, 0x0018);
    di += 0x0248;
    goto loc_5242;
loc_5236:
    di = 0xfc48;
    goto loc_5242;
loc_523b:
    di = 0x0488;
    di += memory16(ds, 0x0018);
loc_5242:
    ax = memory16(ds, 0x3a50);
    if (ax == 0x0000)
        goto loc_525a;
    sub_5718();
    ax = 0x0000;
    sub_573d();
    di += 0x0002;
    sub_573d();
    return;
loc_525a:
    di += 0x000c;
    ax = 0x0000;
    sub_573d();
}
void sub_5264()
{
    if (memory16(ds, 0x26f2) == 0x0000)
        goto loc_5281;
    if (memory16(ds, 0x26f2) == 0x0001)
        goto loc_527c;
    di = memory16(ds, 0x0018);
    di += 0x0270;
    goto loc_5288;
loc_527c:
    di = 0xfc70;
    goto loc_5288;
loc_5281:
    di = 0x04b0;
    di += memory16(ds, 0x0018);
loc_5288:
    ax = memory16(ds, 0x4f90);
    if (ax == 0x0000)
        goto loc_52a0;
    sub_5718();
    ax = 0x0000;
    sub_573d();
    di += 0x0002;
    sub_573d();
    return;
loc_52a0:
    di += 0x000c;
    ax = 0x0000;
    sub_573d();
}
void sub_52aa()
{
    if (memory16(ds, 0x26f2) == 0x0000)
        goto loc_52c7;
    if (memory16(ds, 0x26f2) == 0x0001)
        goto loc_52c2;
    di = memory16(ds, 0x0018);
    di += 0x025a;
    goto loc_52ce;
loc_52c2:
    di = 0xfc5a;
    goto loc_52ce;
loc_52c7:
    di = 0x049a;
    di += memory16(ds, 0x0018);
loc_52ce:
    push(di);
    si = 0x37d4;
    ax = memory16(ds, 0x37ce);
    sub_57ae();
    ax = memory16(ds, 0x37d4);
    di = pop();
    push(di);
    sub_573d();
    si = 0x37d4;
    ax = memory16(ds, 0x37d0);
    sub_579c();
    ax = memory16(ds, 0x37d4);
    di = pop();
    di += 0x0004;
    push(di);
    sub_573d();
    ax = memory16(ds, 0x37d5);
    di = pop();
    di += 0x0002;
    sub_573d();
}
void sub_5300()
{
    if (memory16(ds, 0x26f2) == 0x0000)
        goto loc_531d;
    if (memory16(ds, 0x26f2) == 0x0001)
        goto loc_5318;
    di = memory16(ds, 0x0018);
    di += 0x0266;
    goto loc_5324;
loc_5318:
    di = 0xfc66;
    goto loc_5324;
loc_531d:
    di = 0x04a6;
    di += memory16(ds, 0x0018);
loc_5324:
    ax = memory16(ds, 0x4f8c);
    sub_573d();
}
void sub_532b()
{
loc_532b:
    lodsw<MemData, DirForward>();
    dx = ax;
    lodsw<MemData, DirForward>();
    cx = ax;
    ax = dx;
    sub_584c();
    dx = ax;
    lodsw<MemData, DirForward>();
    dh = al;
    memory16(ds, 0x37d2) = dx;
loc_533f:
    lodsb<MemData, DirForward>();
    if (al == 0xff)
        goto loc_53a5;
    if (al == 0x00)
        goto loc_532b;
    ah = al;
    push(si);
    si = 0x383a;
    bx = 0x0000;
loc_5351:
    lodsb<MemData, DirForward>();
    if (al == ah)
        goto loc_535b;
    bx += 0x0002;
    goto loc_5351;
loc_535b:
    bx += 0x3865;
    push(ds);
    push(di);
    ax = memory16(ds, 0x37d2);
    di += memory16(ds, 0x0018);
    si = memory16(ds, bx);
    si += memory16(ds, 0x37c6);
    dx = memory16(ds, 0x37c8);
    if (memory16(ds, 0x26f2) != 0x0002)
        goto loc_53a6;
    ds = dx;
    push(si);
    push(di);
    push(ax);
    bl = ah;
    dx = 0x0001;
    cx = 0x0007;
    sub_2952();
    ax = pop();
    di = pop();
    si = pop();
    di++;
    bl = ah;
    si += 0x0004;
    dx = 0x0001;
    cx = 0x0007;
    sub_2952();
    di = pop();
    ds = pop();
    si = pop();
    di += 0x0002;
    goto loc_533f;
loc_53a5:
    return;
loc_53a6:
    ds = dx;
    push(si);
    push(di);
    push(ax);
    bl = ah;
    dx = 0x0001;
    cx = 0x0007;
    sub_29dc();
    ax = pop();
    di = pop();
    si = pop();
    di++;
    bl = ah;
    si += 0x0004;
    dx = 0x0001;
    cx = 0x0007;
    sub_29dc();
    di = pop();
    ds = pop();
    si = pop();
    di += 0x0002;
    goto loc_533f;
}
void sub_53d1()
{
    lodsw<MemData, DirForward>();
    di = ax;
loc_53d4:
    lodsb<MemData, DirForward>();
    if (al == 0xff)
        return;
    ah = al;
    push(si);
    si = 0x383a;
    bx = 0x0000;
loc_53e2:
    lodsb<MemData, DirForward>();
    if (al == ah)
        goto loc_53ec;
    bx += 0x0002;
    goto loc_53e2;
loc_53ec:
    bx += 0x3865;
    push(ds);
    push(di);
    di += memory16(ds, 0x0018);
    ax = memory16(ds, 0x001a);
    push(ax);
    si = memory16(ds, bx);
    si += 0xc808;
    ax = 0x335d;
    ds = ax;
    push(si);
    dx = 0x0002;
    cx = 0x0007;
    sub_2499();
    si = pop();
    ax = pop();
    di = pop();
    push(di);
    di += ax;
    dx = 0x0002;
    cx = 0x0007;
    sub_2499();
    di = pop();
    ds = pop();
    si = pop();
    di += 0x0002;
    goto loc_53d4;
}
void sub_5429()
{
    sync();
    sync();
    sync();
    sync();
    return;
loc_5429:
    ax = memory16(ds, 0x001c);
loc_542c:
    if (memory(ds, 0x0020) != 0x01)
        goto loc_543b;
    memory(ds, 0x0025) = 0xff;
    return;
loc_543b:
    if (ax == memory16(ds, 0x001c))
        goto loc_542c;
    if (--cx)
        goto loc_5429;
}
void sub_5444()
{
loc_5444:
    sub_544d();
    if (dx == 0x0000)
        goto loc_5444;
}
void sub_544d()
{
    sub_552a();
    al = memory(ds, 0x37f3);
    al |= memory(ds, 0x37f4);
    al |= memory(ds, 0x37f1);
    al |= memory(ds, 0x37f2);
    if (memory(ds, 0x37f9) != 0x00)
        goto loc_546a;
    al |= memory(ds, 0x37f5);
loc_546a:
    al &= 0x10;
    if (al == 0)
        goto loc_5472;
    dx = 0xffff;
    return;
loc_5472:
    dx = 0x0000;
}
void sub_5476()
{
    sync();
    sub_552a();
    al = memory(ds, 0x37f3);
    al |= memory(ds, 0x37f4);
    al |= memory(ds, 0x37f1);
    al |= memory(ds, 0x37f2);
    if (memory(ds, 0x37f9) != 0x00)
        return;
    al |= memory(ds, 0x37f5);
}
void sub_5494()
{
    di = 0x049a;
    si = 0x3c5e;
    cx = memory16(ds, 0x0010);
loc_549e:
    push(cx);
    if (memory16(ds, si) == 0xffff)
        goto loc_54bc;
    push(di);
    di += memory16(ds, 0x0018);
    ax = memory16(ds, si + 30);
    sub_573d();
    di = pop();
    push(di);
    di += memory16(ds, 0x001a);
    sub_573d();
    di = pop();
loc_54bc:
    di += 0x0008;
    si += 0x0020;
    cx = pop();
    if (--cx)
        goto loc_549e;
}
void sub_54c6()
{
    ax = 0x0278;
    sub_54f3();
    if (dx == 0x0000)
        goto loc_54ef;
    ax = 0x0378;
    sub_54f3();
    if (dx == 0x0000)
        goto loc_54ef;
    ax = 0x03bc;
    sub_54f3();
    if (dx == 0x0000)
        goto loc_54ef;
    ax = 0xffff;
    memory16(ds, 0x37e4) = dx;
    return;
loc_54ef:
    memory16(ds, 0x37e4) = ax;
}
void sub_54f3()
{
    dx = 0;
}
void sub_552a()
{
    if (memory16(ds, 0x37e4) != 0xffff)
        goto loc_5534;
    return;
loc_5534:
    al = memory(ds, 0x37f7);
    memory(ds, 0x37f3) = al;
    al = memory(ds, 0x37f8);
    memory(ds, 0x37f4) = al;
    si = 0x37e6;
    ah = 0xff;
    bl = 0x20;
    bh = 0x00;
    sub_567c();
//    memory(ds, 0x37f1) = bh;
    si = 0x37eb;
    ah = 0x00;
    bl = 0x80;
    bh = 0x00;
//    sub_567c();
//    memory(ds, 0x37f2) = bh;
    if (memory(ds, 0x37f9) != 0x00)
        goto loc_55b4;
    memory(ds, 0x37f0) = 0x00;
    ah = 0x84;
    dx = 0x0000;
    interrupt(0x15);
    if (al & 0x10)
        goto loc_557d;
    memory(ds, 0x37f0) = memory(ds, 0x37f0) | 0x10;
loc_557d:
    if (al & 0x20)
        goto loc_5596;
    if (memory(ds, 0x37fb) != 0x00)
        goto loc_559c;
    memory(ds, 0x37fb) = 0xff;
    memory(ds, 0x204e) = 0xff;
    goto loc_559c;
loc_5596:
    memory(ds, 0x37fb) = 0x00;
loc_559c:
    al = 0x84;
    dx = 0x0001;
    interrupt(0x15);
    cx = memory16(ds, 0x37be);
    dx = memory16(ds, 0x37bc);
    sub_5639();
    al = memory(ds, 0x37f0);
    memory(ds, 0x37f5) = al;
loc_55b4:
    if (memory(ds, 0x37fa) != 0x00)
        goto loc_55f6;
    memory(ds, 0x37f0) = 0x00;
    ah = 0x84;
    dx = 0x0000;
    interrupt(0x15);
    if (al & 0x40)
        goto loc_55d1;
    memory(ds, 0x37f0) = memory(ds, 0x37f0) | 0x10;
loc_55d1:
    if (al & 0x80)
        goto loc_55da;
    memory(ds, 0x204e) = 0xff;
loc_55da:
    al = 0x84;
    dx = 0x0001;
    interrupt(0x15);
    ax = cx;
    bx = dx;
    cx = memory16(ds, 0x37c2);
    dx = memory16(ds, 0x37c0);
    sub_5639();
    al = memory(ds, 0x37f0);
    memory(ds, 0x37f6) = al;
loc_55f6:
    ax = 0x0000;
    si = 0x37fc;
    di = 0x3c5e;
    cx = 0x0004;
loc_5602:
    ax = 0x0000;
    lodsb<MemData, DirForward>();
    ax += ax;
    bx = 0x3800;
    bx += ax;
    bx = memory16(ds, bx);
    al = memory(ds, bx);
    memory16(ds, di + 26) = ax;
    di += 0x0020;
    if (--cx)
        goto loc_5602;
    si = 0x3c5e;
    al = memory(ds, 0x204e);
    if (al == 0x00)
        goto loc_5633;
    memory16(ds, si + 26) = memory16(ds, si + 26) | 0x0020;
    memory(ds, 0x204e) = 0x00;
    return;
loc_5633:
    memory16(ds, si + 26) = memory16(ds, si + 26) & 0xffdf;
}
void sub_5639()
{
    ax &= 0x00ff;
    bx &= 0x00ff;
    dx += 0x0020;
    if (ax <= dx)
        goto loc_564c;
    memory(ds, 0x37f0) = memory(ds, 0x37f0) | 0x08;
loc_564c:
    dx -= 0x0040;
    if (ax > dx)
        goto loc_5658;
    memory(ds, 0x37f0) = memory(ds, 0x37f0) | 0x04;
loc_5658:
    cx += 0x0020;
    if (bx <= cx)
        goto loc_5664;
    memory(ds, 0x37f0) = memory(ds, 0x37f0) | 0x02;
loc_5664:
    cx -= 0x0040;
    if (bx > cx)
        goto loc_5670;
    memory(ds, 0x37f0) = memory(ds, 0x37f0) | 0x01;
loc_5670:
    if (ax != 0x0000)
        return;
    memory(ds, 0x37f0) = 0x00;
}
void sub_567c()
{
    bx = 0;
}
void sub_56de()
{
    si = 0x37d4;
    ax = memory16(ds, 0x37ce);
    sub_57ae();
    ax = memory16(ds, 0x37d4);
    di = 0x0488;
    di += memory16(ds, 0x0018);
    sub_573d();
    si = 0x37d4;
    ax = memory16(ds, 0x37d0);
    sub_579c();
    ax = memory16(ds, 0x37d4);
    di = 0x048c;
    di += memory16(ds, 0x0018);
    sub_573d();
    ax = memory16(ds, 0x37d5);
    di = 0x048e;
    di += memory16(ds, 0x0018);
    sub_573d();
}
void sub_5718()
{
    si = 0x37d4;
    sub_576c();
    si = 0x37d4;
    cx = 0x0005;
loc_5724:
    lodsb<MemData, DirForward>();
    if (al != 0x00)
        goto loc_5731;
    di += 0x0002;
    if (--cx)
        goto loc_5724;
    return;
loc_5731:
    push(cx);
    sub_573d();
    di += 0x0002;
    lodsb<MemData, DirForward>();
    cx = pop();
    if (--cx)
        goto loc_5731;
}
void sub_573d()
{
    bx = memory16(ds, 0x26f2);
    push(bx);
    if (bx != 0x0001)
        goto loc_574d;
    memory16(ds, 0x26f2) = 0x0002;
loc_574d:
    push(si);
    push(di);
    push(ax);
    ax &= 0x000f;
    ax += 0x0012;
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_5760;
    ax += 0x0090;
loc_5760:
    sub_273a();
    ax = pop();
    di = pop();
    si = pop();
    bx = pop();
    memory16(ds, 0x26f2) = bx;
}
void sub_576c()
{
    cx = 0x2710;
    dx = 0x0000;
    div(cx);
    memory(ds, si) = al;
    si++;
    ax = dx;
    cx = 0x03e8;
    dx = 0x0000;
    div(cx);
    memory(ds, si) = al;
    si++;
    ax = dx;
    dx = 0x0000;
    cx = 0x0064;
    div(cx);
    memory(ds, si) = al;
    si++;
    ax = dx;
    goto loc_579c;
loc_579c:
    cx = 0x000a;
    dx = 0x0000;
    div(cx);
    memory(ds, si) = al;
    si++;
    ax = dx;
    goto loc_57ae;
loc_57ae:
    memory(ds, si) = al;
    si++;
}
void sub_579c()
{
    cx = 0x000a;
    dx = 0x0000;
    div(cx);
    memory(ds, si) = al;
    si++;
    ax = dx;
    goto loc_57ae;
loc_57ae:
    memory(ds, si) = al;
    si++;
}
void sub_57ae()
{
    memory(ds, si) = al;
    si++;
}
void sub_57b4()
{
    push(ax);
    push(si);
    push(dx);
    si = 0x0726;
    cx = 0x0000;
    cl = ah;
    ah = 0x00;
    si += ax;
    ax = memory16(ds, 0x26f4);
    mul(cx);
    si += ax;
    dx = pop();
    memory(ds, si) = dl;
    si = pop();
    ax = pop();
}
void sub_57d2()
{
    push(ax);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0008;
    dx = ax;
    ax = pop();
    al = ah;
    ah = 0x00;
    ax <<= cl;
    ax += 0x0018;
    cx = ax;
    dx += 0x0008;
    cx += 0x0008;
}
void sub_57f1()
{
    push(ax);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0002;
    di = ax;
    ax = pop();
    al = ah;
    ah = 0x00;
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_5814;
    cx = 0x0800;
    mul(cx);
    ax += 0x0c00;
    di += ax;
    return;
loc_5814:
    cx = 0x0400;
    mul(cx);
    ax += 0x0600;
    di += ax;
}
void sub_581f()
{
    push(cx);
    dx -= 0x0008;
    cl = 0x04;
    dx >>= cl;
    al = dl;
    dx = pop();
    dx -= 0x0018;
    dx >>= cl;
    ah = dl;
}
void sub_5832()
{
    push(si);
    si = 0x0726;
    cx = 0x0000;
    cl = ah;
    ah = 0x00;
    si += ax;
    ax = memory16(ds, 0x26f4);
    mul(cx);
    si += ax;
    al = memory(ds, si);
    si = pop();
}
void sub_584c()
{
    push(ax);
    ax = 0x0080;
    if (memory16(ds, 0x26f2) != 0x0002)
        goto loc_585a;
    ax = 0x0040;
loc_585a:
    mul(cx);
    di = ax;
    ax = pop();
    cx = ax;
    cx >>= 1;
    cx >>= 1;
    di += cx;
    ax &= 0x0003;
}
void sub_586b()
{
    ah = 0x2c;
    interrupt(0x21);
    dl ^= ch;
    dl ^= cl;
    dl ^= dh;
    dh = 0x00;
    memory16(ds, 0x37cc) = dx;
}
void sub_587c()
{
    push(si);
    cx = ax;
    si = 0x38bb;
    dx = memory16(ds, 0x37cc);
    si += dx;
    ax = memory16(ds, si);
    dx += ax;
    dx++;
    dx &= 0x007f;
    memory16(ds, 0x37cc) = dx;
    dx = memory16(ds, si + 1);
    memory16(ds, si) = memory16(ds, si) ^ dx;
    dx = 0x0000;
    div(cx);
    ax = dx;
    si = pop();
}
void sub_58a7()
{
    ah = 0x3d;
    al = 0x90;
    dx = 0x380c;
    interrupt(0x21);
    if (flags.carry)
        goto loc_58fd;
    memory16(ds, 0x37ca) = ax;
    push(ds);
    ah = 0x3f;
    bx = memory16(ds, 0x37ca);
    cx = 0x2710;
    dx = 0x25f0;
    ds = dx;
    dx = 0x5590;
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_58f5;
    ah = 0x3e;
    bx = memory16(ds, 0x37ca);
    interrupt(0x21);
    push(ds);
    push(es);
    push(cx);
    push(si);
    cx = 0x0b52;
    es = cx;
    cx = 0x25f0;
    ds = cx;
    si = 0x5590;
    di = 0x0726;
    cx = 0x01b8;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    es = pop();
    ds = pop();
    dx = 0x0000;
    return;
loc_58f5:
    ah = 0x3e;
    bx = memory16(ds, 0x37ca);
    interrupt(0x21);
loc_58fd:
    dx = 0xffff;
}
void sub_5901()
{
    ah = 0x3d;
    al = 0x90;
    dx = 0x3815;
    interrupt(0x21);
    if (flags.carry)
        goto loc_5966;
    memory16(ds, 0x37ca) = ax;
    ah = 0x3f;
    bx = memory16(ds, 0x37ca);
    cx = 0x001c;
    dx = 0x381e;
    interrupt(0x21);
    if (flags.carry)
        goto loc_5967;
    ah = 0x3e;
    bx = memory16(ds, 0x37ca);
    interrupt(0x21);
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x381e;
    di = 0x205d;
    cx = 0x000c;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x382a;
    di = 0x2069;
    cx = 0x000a;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x3834;
    di = 0x37fc;
    cx = 0x0004;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    al = memory(ds, 0x3838);
    memory(ds, 0x0024) = al;
loc_5966:
    return;
loc_5967:
    ah = 0x3e;
    bx = memory16(ds, 0x37ca);
    interrupt(0x21);
}
void sub_5970()
{
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x205d;
    di = 0x381e;
    cx = 0x000c;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x2069;
    di = 0x382a;
    cx = 0x000a;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x37fc;
    di = 0x3834;
    cx = 0x0004;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    al = memory(ds, 0x0024);
    memory(ds, 0x3838) = al;
    dx = 0x3815;
    cx = 0x0000;
    ah = 0x3c;
    interrupt(0x21);
    if (flags.carry)
        return;
    memory16(ds, 0x37ca) = ax;
    bx = ax;
    bx = memory16(ds, 0x37ca);
    dx = 0x381e;
    cx = 0x001c;
    ah = 0x40;
    interrupt(0x21);
    bx = memory16(ds, 0x37ca);
    ah = 0x3e;
    interrupt(0x21);
}
void sub_59d8()
{
    si = 0x3d8e;
    cx = 0x0008;
loc_59de:
    push(si);
    push(cx);
    di = memory16(ds, si);
    if (di == 0xffff)
        goto loc_5a19;
    dx = memory16(ds, 0x001e);
    ax = memory16(ds, si + 4);
    al += dl;
    if (ah > al)
        goto loc_59fe;
    al = 0x00;
    memory16(ds, si + 2) = memory16(ds, si + 2) + 0x0002;
loc_59fe:
    memory16(ds, si + 4) = ax;
    bx = memory16(ds, si + 2);
    ax = memory16(ds, bx);
    if (ax == 0xffff)
        goto loc_5a21;
    sub_4ffe();
    di += memory16(ds, 0x0018);
    sub_273a();
loc_5a19:
    cx = pop();
    si = pop();
    si += 0x000a;
    if (--cx)
        goto loc_59de;
    return;
loc_5a21:
    ax = memory16(ds, si + 8);
    ax += ax;
    ax += ax;
    bx = 0x3a80;
    bx += ax;
    dx = memory16(ds, bx);
    memory16(ds, si) = 0xffff;
    ax = memory16(ds, si + 6);
    sub_57b4();
    goto loc_5a19;
}
void sub_5a41()
{
    memory(ds, 0x3a5d) = 0xff;
    si = 0x3c5e;
    sub_5b29();
    si = 0x3c7e;
    sub_5b29();
    si = 0x3c9e;
    sub_5b29();
    si = 0x3cbe;
    sub_5b29();
    sub_5ab3();
    sub_5c33();
    if (memory16(ds, 0x4f88) != 0x0001)
        goto loc_5aab;
    if (memory16(ds, 0x4f8a) != 0x0001)
        goto loc_5aab;
    if (memory(ds, 0x3a5d) == 0xff)
        goto loc_5aac;
    memory16(ds, 0x4f6c) = memory16(ds, 0x4f6c) - 1;
    if ((short)memory16(ds, 0x4f6c) >= 0)
        goto loc_5aab;
    memory16(ds, 0x4f6c) = 0x7fff;
    push(cx);
    push(ax);
    push(si);
    sub_71c6();
    push(ax);
    dl = 0x70;
    sub_57b4();
    ax = pop();
    sub_57f1();
    ax = 0x009b;
    sub_5f24();
    di += memory16(ds, 0x0018);
    sub_273a();
    si = pop();
    ax = pop();
    cx = pop();
loc_5aab:
    return;
loc_5aac:
    memory16(ds, 0x4f6c) = 0x0ca8;
}
void sub_5ab3()
{
    if (memory16(ds, 0x0012) == 0x0000)
        return;
    si = 0x3c5e;
    cx = memory16(ds, 0x0010);
loc_5ac1:
    push(cx);
    if (memory16(ds, si) == 0xffff)
        goto loc_5b22;
    if (memory16(ds, si + 20) == 0x0000)
        goto loc_5b22;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    dx = ax;
    cx = memory16(ds, 0x0010);
    di = 0x3c5e;
loc_5ae4:
    push(cx);
    if (memory16(ds, di) == 0xffff)
        goto loc_5b1c;
    ax = memory16(ds, si + 24);
    if (ax == memory16(ds, di + 24))
        goto loc_5b1c;
    push(dx);
    dx = memory16(ds, di);
    cx = memory16(ds, di + 2);
    sub_581f();
    dx = pop();
    if (ax != dx)
        goto loc_5b1c;
    if (memory16(ds, di + 22) != 0xffff)
        goto loc_5b1c;
    ax = memory16(ds, si + 22);
    memory16(ds, di + 22) = ax;
    memory16(ds, di + 20) = 0x00b4;
loc_5b1c:
    cx = pop();
    di += 0x0020;
    if (--cx)
        goto loc_5ae4;
loc_5b22:
    cx = pop();
    si += 0x0020;
    if (--cx)
        goto loc_5ac1;
}
void sub_5b29()
{
    if (memory16(ds, si) == 0xffff)
        goto loc_5b6a;
    if ((short)memory16(ds, si + 8) < 0)
        goto loc_5b6a;
    if ((short)memory16(ds, si + 10) < 0)
        goto loc_5b67;
    sub_5d66();
    if (memory16(ds, 0x4f88) != 0x0000)
        goto loc_5b97;
    memory16(ds, 0x3a54) = 0x0300;
    ax = memory16(ds, si + 22);
    if (ax == 0xffff)
        goto loc_5b97;
    if (ax != 0x0000)
        goto loc_5b6d;
    memory16(ds, 0x3a54) = 0x0100;
    sub_6037();
    goto loc_5b9a;
loc_5b67:
    goto loc_5ba5;
loc_5b6a:
    goto loc_5ba4;
loc_5b6d:
    if (ax != 0x0001)
        goto loc_5b7d;
    memory16(ds, 0x3a54) = 0x0c00;
    sub_6037();
    goto loc_5b9a;
loc_5b7d:
    if (ax != 0x0002)
        goto loc_5b89;
    memory(ds, si + 26) = memory(ds, si + 26) & 0x0f;
    goto loc_5b97;
loc_5b89:
    if (ax != 0x0003)
        goto loc_5b97;
    ax = memory16(ds, 0x0022);
    al &= 0x10;
    memory(ds, si + 26) = memory(ds, si + 26) ^ al;
loc_5b97:
    sub_6037();
loc_5b9a:
    sub_5dce();
    if (memory16(ds, si + 10) == 0xffff)
        goto loc_5b67;
loc_5ba4:
    return;
loc_5ba5:
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    push(si);
    push(cx);
    push(dx);
    si = memory16(ds, 0x3a46);
    ax = memory16(ds, 0x001c);
    ax &= 0x0001;
    if (ax != 0x0000)
        goto loc_5bc4;
    memory16(ds, 0x3a46) = memory16(ds, 0x3a46) + 0x0004;
loc_5bc4:
    di = 0x41c9;
    lodsw<MemData, DirForward>();
    if (ax == 0xffff)
        goto loc_5c23;
    memory16(ds, di) = ax;
    ax = 0x42fd;
    memory16(ds, di + 2) = ax;
    lodsw<MemData, DirForward>();
    dx = 0x0016;
    dx -= ax;
    memory16(ds, di + 6) = dx;
    si = 0x41c9;
    dx = pop();
    cx = pop();
    cx += ax;
    push(cx);
    push(dx);
    sub_2782();
    di = 0x41d9;
    si = memory16(ds, 0x3a48);
    lodsw<MemData, DirForward>();
    if (ax != 0xffff)
        goto loc_5c03;
    si = 0x40ed;
    memory16(ds, 0x3a48) = si;
    lodsw<MemData, DirForward>();
loc_5c03:
    memory16(ds, 0x3a48) = memory16(ds, 0x3a48) + 0x0002;
    memory16(ds, di) = ax;
    ax = 0x42fd;
    memory16(ds, di + 2) = ax;
    dx = pop();
    cx = pop();
    dx -= 0x0004;
    cx -= 0x0008;
    si = 0x41d9;
    sub_2782();
    si = pop();
    return;
loc_5c23:
    dx = pop();
    cx = pop();
    si = pop();
    memory16(ds, 0x4f7c) = 0x0002;
    memory16(ds, si) = 0xffff;
}
void sub_5c33()
{
    si = 0x3c5e;
    cx = 0x0004;
loc_5c39:
    push(cx);
    if (memory16(ds, si) == 0xffff)
        goto loc_5cab;
    if ((short)memory16(ds, si + 8) < 0)
        goto loc_5ca8;
    if ((short)memory16(ds, si + 10) < 0)
        goto loc_5cab;
    push(si);
    bx = 0x3b7a;
    ax = memory16(ds, si + 8);
    ax += ax;
    bx += ax;
    ax = memory16(ds, bx);
    bx = 0x3e4c;
    dx = memory16(ds, si + 24);
    dx += dx;
    bx += dx;
    ax += memory16(ds, bx);
    ax += memory16(ds, si + 28);
    dx = memory16(ds, si);
    dx -= 0x000b;
    cx = memory16(ds, si + 2);
    cx -= 0x000d;
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_5cae;
    bx = memory16(ds, si + 22);
    bx &= 0x0008;
    if (bx == 0x0000)
        goto loc_5cae;
    bx = memory16(ds, 0x001c);
    bx &= 0x0002;
    if (bx != 0x0000)
        goto loc_5cae;
    bl = 0xfe;
    sub_28b6();
    si = pop();
    goto loc_5cf4;
loc_5ca8:
    goto loc_5d00;
loc_5cab:
    goto loc_5cfe;
loc_5cae:
    sub_276b();
    si = pop();
    if (memory16(ds, 0x4f88) != 0x0003)
        goto loc_5cf4;
    push(si);
    dx = memory16(ds, si);
    dx -= 0x0008;
    cx = memory16(ds, si + 2);
    cx += 0x0001;
    bx = 0x41a9;
    if (memory(ds, 0x3a5d) == 0x00)
        goto loc_5cd5;
    bx = 0x41b9;
loc_5cd5:
    ax = memory16(ds, 0x001c);
    ax &= 0x000c;
    bx += ax;
    si = 0x41e9;
    ax = memory16(ds, bx);
    memory16(ds, si) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 2) = ax;
    sub_2782();
    si = pop();
loc_5cf4:
    cx = pop();
    si += 0x0020;
    if (--cx)
        goto loc_5cfb;
    return;
loc_5cfb:
    goto loc_5c39;
loc_5cfe:
    goto loc_5cf4;
loc_5d00:
    ax = memory16(ds, 0x001e);
    memory16(ds, si + 10) = memory16(ds, si + 10) + ax;
    if (memory16(ds, si + 10) < 0x0009)
        goto loc_5d18;
    memory16(ds, si + 10) = 0x0000;
    memory16(ds, si + 8) = memory16(ds, si + 8) - 1;
loc_5d18:
    bx = 0x3b5e;
    ax = memory16(ds, si + 8);
    ax = -ax;
    ax += ax;
    bx += ax;
    ax = memory16(ds, bx);
    if (ax == 0xffff)
        goto loc_5d58;
    bx = 0x3e4c;
    dx = memory16(ds, si + 24);
    dx += dx;
    bx += dx;
    ax += memory16(ds, bx);
    dx = memory16(ds, si);
    dx -= 0x0008;
    dx -= 0x0003;
    cx = memory16(ds, si + 2);
    cx -= 0x0008;
    cx -= 0x0005;
    push(si);
    sub_276b();
    si = pop();
    goto loc_5cf4;
loc_5d58:
    memory16(ds, si) = 0xffff;
    memory16(ds, si + 8) = 0x0000;
    goto loc_5cf4;
}
void sub_5d66()
{
    ax = memory16(ds, si + 20);
    if (ax == 0x0000)
        goto loc_5da6;
    ax--;
    memory16(ds, si + 20) = ax;
    if (ax == 0x0000)
        goto loc_5da7;
    dx = ax;
    dx &= 0x0003;
    if (dx != 0x0000)
        goto loc_5da6;
    ax &= 0x0004;
    cl = 0x01;
    ax >>= cl;
    bx = 0x3fac;
    bx += ax;
    ax = memory16(ds, si + 24);
    ax += ax;
    ax += ax;
    bx += ax;
    push(si);
    si = memory16(ds, bx);
    lodsw<MemData, DirForward>();
    cx = ax;
    lodsw<MemData, DirForward>();
    sub_2397();
    si = pop();
loc_5da6:
    return;
loc_5da7:
    memory16(ds, si + 22) = 0xffff;
    push(si);
    bx = 0x3fac;
    ax = memory16(ds, si + 24);
    ax += ax;
    ax += ax;
    bx += ax;
    si = memory16(ds, bx);
    lodsw<MemData, DirForward>();
    cx = ax;
    lodsw<MemData, DirForward>();
    sub_2397();
    si = pop();
    memory16(ds, 0x3a54) = 0x0300;
}
void sub_5dce()
{
    memory(ds, 0x3a5e) = 0x00;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    push(ax);
    sub_5832();
    dx = pop();
    if (al < 0x61)
        goto loc_5e30;
    if (al > 0x75)
        goto loc_5e30;
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_5e24;
    if (al == 0x67)
        goto loc_5e4c;
    if (al == 0x66)
        goto loc_5e53;
    if (al == 0x6b)
        goto loc_5e34;
    if (al == 0x6a)
        goto loc_5e31;
    if (al == 0x69)
        goto loc_5e37;
    if (al == 0x6d)
        goto loc_5e40;
    if (al == 0x68)
        goto loc_5e43;
    if (al == 0x6c)
        goto loc_5e46;
    if (al == 0x75)
        goto loc_5e49;
    if (al == 0x73)
        goto loc_5e3a;
    if (al == 0x6f)
        goto loc_5e3d;
    if (al == 0x70)
        goto loc_5e3d;
    return;
loc_5e24:
    if (al == 0x61)
        goto loc_5e4c;
    if (al == 0x62)
        goto loc_5e53;
    if (al == 0x63)
        goto loc_5e5a;
loc_5e30:
    return;
loc_5e31:
    goto loc_5e99;
loc_5e34:
    goto loc_5e91;
loc_5e37:
    goto loc_5ea1;
loc_5e3a:
    goto loc_5edb;
loc_5e3d:
    goto loc_5ee4;
loc_5e40:
    goto loc_5ed4;
loc_5e43:
    goto loc_5ec4;
loc_5e46:
    goto loc_5ecc;
loc_5e49:
    goto loc_5eec;
loc_5e4c:
    push(si);
    memory16(ds, si + 12) = memory16(ds, si + 12) + 1;
    goto loc_5e6d;
loc_5e53:
    push(si);
    memory16(ds, si + 18) = memory16(ds, si + 18) + 1;
    goto loc_5e6d;
loc_5e5a:
    push(dx);
    memory16(ds, si + 20) = 0x00b4;
    ax = 0x0004;
    sub_587c();
    memory16(ds, si + 22) = ax;
    dx = pop();
    push(si);
loc_5e6d:
    ax = dx;
    push(ax);
    sub_57f1();
    ax = 0x0000;
    sub_4ffe();
    sub_5f24();
    di += memory16(ds, 0x0018);
    sub_273a();
    ax = pop();
    dl = 0x2e;
    sub_57b4();
    ax = 0x0001;
    sub_8ca1();
    si = pop();
    return;
loc_5e91:
    push(si);
    memory16(ds, si + 22) = memory16(ds, si + 22) | 0x0001;
    goto loc_5e6d;
loc_5e99:
    push(si);
    memory16(ds, si + 22) = memory16(ds, si + 22) | 0x0002;
    goto loc_5e6d;
loc_5ea1:
    push(si);
    if (memory16(ds, 0x3a54) != 0x0240)
        goto loc_5eb2;
    memory16(ds, 0x3a54) = 0x0300;
    goto loc_5e6d;
loc_5eb2:
    if (memory16(ds, 0x3a54) != 0x0300)
        goto loc_5ec2;
    memory16(ds, 0x3a54) = 0x03c0;
    goto loc_5e6d;
loc_5ec2:
    goto loc_5e6d;
loc_5ec4:
    push(si);
    memory16(ds, si + 22) = memory16(ds, si + 22) | 0x0004;
    goto loc_5e6d;
loc_5ecc:
    push(si);
    memory16(ds, si + 22) = memory16(ds, si + 22) | 0x0008;
    goto loc_5e6d;
loc_5ed4:
    push(si);
    memory16(ds, 0x4f8c) = memory16(ds, 0x4f8c) + 1;
    goto loc_5e6d;
loc_5edb:
    push(si);
    memory16(ds, 0x3a50) = memory16(ds, 0x3a50) + 0x012c;
    goto loc_5e6d;
loc_5ee4:
    push(si);
    memory16(ds, 0x3a50) = memory16(ds, 0x3a50) + 0x0064;
    goto loc_5e6d;
loc_5eec:
    if (memory16(ds, 0x4200) != 0x0000)
        return;
    memory(ds, 0x3a5e) = 0xff;
}
void sub_5efa()
{
    si = 0x3dde;
    cx = 0x0008;
loc_5f00:
    di = memory16(ds, si);
    if (di == 0xffff)
        goto loc_5f1e;
    memory16(ds, si) = 0xffff;
    di += memory16(ds, 0x0018);
    ax = memory16(ds, si + 2);
    push(cx);
    push(si);
    sub_273a();
    si = pop();
    cx = pop();
loc_5f1e:
    si += 0x0004;
    if (--cx)
        goto loc_5f00;
}
void sub_5f24()
{
    push(si);
    si = 0x3dde;
    cx = 0x0008;
loc_5f2b:
    if (memory16(ds, si) == 0xffff)
        goto loc_5f39;
    si += 0x0004;
    if (--cx)
        goto loc_5f2b;
    si = pop();
    return;
loc_5f39:
    memory16(ds, si) = di;
    memory16(ds, si + 2) = ax;
    si = pop();
}
void sub_5f43()
{
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    push(si);
    si = 0x0726;
    di = 0x3f94;
    cx = 0x0000;
    cl = ah;
    ah = 0x00;
    si += ax;
    ax = memory16(ds, 0x26f4);
    mul(cx);
    si += ax;
    bx = memory16(ds, 0x26f4);
    bx = -bx;
    al = memory(ds, (bx + si - 1) & 0xffff);
    memory(ds, di) = al;
    al = memory(ds, (bx + si) & 0xffff);
    memory(ds, di + 1) = al;
    al = memory(ds, (bx + si + 1) & 0xffff);
    memory(ds, di + 2) = al;
    al = memory(ds, si - 1);
    memory(ds, di + 7) = al;
    al = memory(ds, si + 1);
    memory(ds, di + 3) = al;
    bx = -bx;
    al = memory(ds, (bx + si - 1) & 0xffff);
    memory(ds, di + 6) = al;
    al = memory(ds, (bx + si) & 0xffff);
    memory(ds, di + 5) = al;
    al = memory(ds, (bx + si + 1) & 0xffff);
    memory(ds, di + 4) = al;
    si = pop();
    dx = memory16(ds, si);
    dx -= 0x0010;
    dx += 0x0008;
    dx &= 0x000f;
    dx -= 0x0008;
    memory16(ds, 0x3a58) = dx;
    dx = memory16(ds, si + 2);
    dx -= 0x0020;
    dx += 0x0008;
    dx &= 0x000f;
    dx -= 0x0008;
    memory16(ds, 0x3a5a) = dx;
}
void sub_5fd7()
{
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_6033;
    if (memory(ds, 0x3a5e) == 0x00)
        goto loc_6033;
    ax = memory16(ds, si);
    ax -= 0x0010;
    ax &= 0x000f;
    if (ax != 0x0000)
        goto loc_6033;
    ax = memory16(ds, si + 2);
    ax -= 0x0020;
    ax &= 0x000f;
    if (ax != 0x0000)
        goto loc_6033;
    memory16(ds, si) = memory16(ds, si) - 0x000b;
    memory16(ds, si + 2) = memory16(ds, si + 2) - 0x000d;
    memory16(ds, 0x3a46) = 0x40f7;
    memory16(ds, 0x3a48) = 0x40ed;
    memory16(ds, si + 10) = 0xffff;
    memory16(ds, si + 22) = memory16(ds, si + 22) | 0x0008;
    ax = 0x000a;
    sub_8c10();
    dx = 0xffff;
    memory(ds, 0x0023) = 0xff;
    return;
loc_6033:
    dx = 0x0000;
}
void sub_6037()
{
    bx = memory16(ds, si + 26);
    bh = bl;
    bl &= 0x10;
    if (bl == 0)
        goto loc_6049;
    push(bx);
    sub_60b0();
    bx = pop();
loc_6049:
    bl = bh;
    bl &= 0x01;
    if (bl == 0)
        goto loc_605e;
    sub_66b6();
    sub_663d();
    memory16(ds, si + 28) = 0x0009;
    return;
loc_605e:
    bl = bh;
    bl &= 0x02;
    if (bl == 0)
        goto loc_6073;
    sub_66e1();
    sub_663d();
    memory16(ds, si + 28) = 0x0000;
    return;
loc_6073:
    bl = bh;
    bl &= 0x04;
    if (bl == 0)
        goto loc_6088;
    sub_668b();
    sub_663d();
    memory16(ds, si + 28) = 0x0006;
    return;
loc_6088:
    bl = bh;
    bl &= 0x08;
    if (bl == 0)
        goto loc_609d;
    sub_6660();
    sub_663d();
    memory16(ds, si + 28) = 0x0003;
    return;
loc_609d:
    memory(ds, 0x3a5d) = 0x00;
    memory16(ds, si + 8) = 0x0000;
    memory16(ds, si + 10) = 0x0000;
}
void sub_60b0()
{
    bx = 0x3cde;
    cx = 0x0008;
loc_60b6:
    ax = memory16(ds, bx);
    if (ax == 0xffff)
        goto loc_60c7;
    bx += 0x0016;
    if (--cx)
        goto loc_60b6;
    return;
loc_60c7:
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    dx = ax;
    push(dx);
    sub_5832();
    dx = pop();
    if (al != 0x2e)
        return;
    ax = memory16(ds, si + 12);
    if (ax == memory16(ds, si + 14))
        return;
    memory16(ds, si + 14) = memory16(ds, si + 14) + 1;
    push(si);
    push(bx);
    ax = dx;
    dl = 0x2b;
    push(ax);
    sub_57b4();
    ax = pop();
    push(ax);
    sub_57d2();
    ax = dx;
    cx -= 0x0008;
    ax -= 0x0008;
    sub_584c();
    ax = pop();
    bx = pop();
    si = pop();
    memory16(ds, bx) = di;
    memory16(ds, bx + 2) = 0x0000;
    memory16(ds, bx + 4) = 0x0000;
    memory16(ds, bx + 6) = 0x00d2;
    memory16(ds, bx + 8) = ax;
    ax = memory16(ds, si + 24);
    memory16(ds, bx + 18) = ax;
    ax = memory16(ds, 0x3a4e);
    memory16(ds, bx + 20) = ax;
    memory16(ds, 0x3a4e) = memory16(ds, 0x3a4e) + 1;
    if (memory16(ds, 0x4f88) == 0x0000)
        return;
    ax = memory16(ds, 0x3c74);
    ax &= 0x0004;
    if (ax == 0x0000)
        return;
    memory16(ds, bx + 6) = 0x7fff;
}
void sub_614e()
{
    push(ax);
    ax = memory16(ds, si + 18);
    bx = 0x3f9e;
    ax += ax;
    bx += ax;
    bx = memory16(ds, bx);
    bx = memory16(ds, bx + 18);
    ax = pop();
    cx = 0x0000;
loc_6166:
    al += dl;
    ah += dh;
    push(ax);
    push(dx);
    push(cx);
    sub_5832();
    cx = pop();
    dx = pop();
    if (al != 0x2e)
        goto loc_6184;
    ax = pop();
    cx++;
    if (cx == bx)
        goto loc_617e;
    goto loc_6166;
loc_617e:
    cx = -cx;
    return;
loc_6181:
    goto loc_6220;
loc_6184:
    if (al == 0x2b)
        goto loc_6181;
    if (al < 0x41)
        goto loc_6193;
    if (al > 0x54)
        goto loc_6193;
    goto loc_623d;
loc_6193:
    if (al == 0x55)
        goto loc_61a8;
    if (al < 0x61)
        goto loc_61a2;
    if (al > 0x74)
        goto loc_61a2;
    goto loc_62d0;
loc_61a2:
    if (al == 0x75)
        goto loc_61d2;
    ax = pop();
    return;
loc_61a8:
    if (memory16(ds, 0x4f6e) != 0x0001)
        goto loc_61cf;
    push(cx);
    push(ax);
    push(si);
    sub_71c6();
    push(ax);
    dl = 0x73;
    sub_57b4();
    ax = pop();
    sub_57f1();
    ax = 0x009e;
    sub_5f24();
    di += memory16(ds, 0x0018);
    sub_273a();
    si = pop();
    ax = pop();
    cx = pop();
loc_61cf:
    goto loc_623d;
loc_61d2:
    ax = pop();
    if ((short)memory16(ds, 0x3c68) < 0)
        goto loc_621f;
    push(cx);
    push(si);
    push(ax);
    ax = 0x0004;
    sub_587c();
    dx = 0x0009;
    if (ax == 0x0000)
        goto loc_61fe;
    dx = 0x0005;
    if (ax == 0x0001)
        goto loc_61fe;
    dx = 0x0003;
    if (ax == 0x0002)
        goto loc_61fe;
    dx = 0x0004;
loc_61fe:
    ax = pop();
    cx = 0x0004;
    sub_6908();
    ax = memory16(ds, 0x4f92);
    if (ax == 0x0000)
        goto loc_621d;
    sub_57f1();
    ax = 0x006b;
    sub_5f24();
    di += memory16(ds, 0x0018);
    sub_273a();
loc_621d:
    si = pop();
    cx = pop();
loc_621f:
    return;
loc_6220:
    ax = pop();
    push(cx);
    bx = 0x3cde;
    cx = 0x0008;
loc_6228:
    if (ax != memory16(ds, bx + 8))
        goto loc_6236;
    memory16(ds, bx + 6) = 0x0004;
    goto loc_623b;
loc_6236:
    bx += 0x0016;
    if (--cx)
        goto loc_6228;
loc_623b:
    cx = pop();
    return;
loc_623d:
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_6272;
    if (memory16(ds, 0x4f6e) != 0x0002)
        goto loc_6272;
    if (memory(ds, 0x4f94) != 0x00)
        goto loc_6272;
    push(cx);
    push(ax);
    push(si);
    sub_71c6();
    push(ax);
    dl = 0x6f;
    sub_57b4();
    ax = pop();
    sub_57f1();
    ax = 0x009a;
    sub_5f24();
    di += memory16(ds, 0x0018);
    sub_273a();
    si = pop();
    ax = pop();
    cx = pop();
loc_6272:
    memory16(ds, 0x4f6e) = memory16(ds, 0x4f6e) - 1;
    dx = ax;
    ax = pop();
    if (ax != memory16(ds, 0x4f92))
        goto loc_6285;
    memory16(ds, 0x4f92) = 0x0000;
loc_6285:
    push(cx);
    cx = 0x0008;
    bx = 0x3d8e;
loc_628c:
    if (memory16(ds, bx) == 0xffff)
        goto loc_629a;
    bx += 0x000a;
    if (--cx)
        goto loc_628c;
    cx = pop();
    return;
loc_629a:
    dh = 0x00;
    dx -= 0x0041;
    memory16(ds, bx + 8) = dx;
    push(dx);
    push(ax);
    sub_57f1();
    ax = pop();
    dx = pop();
    memory16(ds, bx) = di;
    memory16(ds, bx + 4) = 0x0500;
    memory16(ds, bx + 6) = ax;
    dx += dx;
    dx += dx;
    di = 0x3a80;
    di += dx;
    dx = memory16(ds, di + 2);
    memory16(ds, bx + 2) = dx;
    dl = 0x56;
    sub_57b4();
    cx = pop();
    return;
loc_62d0:
    ax = pop();
    push(cx);
    bx = 0x3dfe;
    if (memory16(ds, bx) == 0xffff)
        goto loc_62f2;
    bx += 0x001a;
    if (memory16(ds, bx) == 0xffff)
        goto loc_62f2;
    bx += 0x001a;
    if (memory16(ds, bx) == 0xffff)
        goto loc_62f2;
    cx = pop();
    return;
loc_62f2:
    memory16(ds, bx + 8) = ax;
    sub_57d2();
    dx -= 0x000e;
    cx -= 0x0013;
    memory16(ds, bx) = dx;
    memory16(ds, bx + 2) = cx;
    memory16(ds, bx + 4) = 0x3a60;
    memory16(ds, bx + 6) = 0x0000;
    cx = pop();
}
void sub_6315()
{
    si = 0x3dfe;
    cx = 0x0003;
loc_631b:
    push(cx);
    push(si);
    if (memory16(ds, si) == 0xffff)
        goto loc_6364;
    ax = memory16(ds, 0x001e);
    memory16(ds, si + 6) = memory16(ds, si + 6) + ax;
    if (memory16(ds, si + 6) < 0x0008)
        goto loc_633d;
    memory16(ds, si + 6) = 0x0000;
    memory16(ds, si + 4) = memory16(ds, si + 4) + 0x0004;
loc_633d:
    bx = memory16(ds, si + 4);
    ax = memory16(ds, bx);
    if (ax == 0xffff)
        goto loc_636c;
    memory16(ds, si + 10) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 12) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    si += 0x000a;
    sub_2782();
loc_6364:
    si = pop();
    si += 0x001a;
    cx = pop();
    if (--cx)
        goto loc_631b;
    return;
loc_636c:
    memory16(ds, si) = 0xffff;
    ax = memory16(ds, si + 8);
    push(ax);
    sub_57f1();
    ax = 0x0000;
    sub_5f24();
    di += memory16(ds, 0x0018);
    sub_273a();
    ax = pop();
    dl = 0x2e;
    sub_57b4();
    goto loc_6364;
}
void sub_638f()
{
    memory16(ds, 0x3a4c) = 0x7fff;
    ax = 0x3e54;
    memory16(ds, 0x3a52) = ax;
    si = 0x3cde;
    cx = 0x0008;
loc_63a1:
    push(cx);
    ax = memory16(ds, si);
    if (ax != 0xffff)
        goto loc_63ae;
    goto loc_6435;
loc_63ae:
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_63dc;
    dx = memory16(ds, 0x3c74);
    dx &= 0x0004;
    if (dx == 0x0000)
        goto loc_63dc;
    dx = memory16(ds, si + 20);
    if (dx > memory16(ds, 0x3a4c))
        goto loc_63dc;
    memory16(ds, 0x3a4c) = dx;
    memory16(ds, 0x3a4a) = si;
    goto loc_63dc;
loc_63d6:
    goto loc_647c;
loc_63d9:
    goto loc_64ee;
loc_63dc:
    dx = memory16(ds, 0x001e);
    memory16(ds, si + 6) = memory16(ds, si + 6) - dx;
    if ((short)memory16(ds, si + 6) < 0)
        goto loc_63d6;
    if ((short)memory16(ds, si + 2) < 0)
        goto loc_63d9;
    memory16(ds, si + 4) = memory16(ds, si + 4) + dx;
    if (memory16(ds, si + 4) < 0x000f)
        goto loc_640c;
    memory16(ds, si + 4) = 0x0000;
    memory16(ds, si + 2) = memory16(ds, si + 2) + 1;
    memory16(ds, si + 2) = memory16(ds, si + 2) & 0x0003;
loc_640c:
    push(si);
    bx = 0x3b7a;
    ax = memory16(ds, si + 2);
    ax += ax;
    bx += ax;
    ax = memory16(ds, bx);
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_6426;
    ax += 0x0084;
loc_6426:
    ax += 0x0009;
    di = memory16(ds, si);
    di += memory16(ds, 0x0018);
    sub_273a();
    si = pop();
loc_6435:
    cx = pop();
    si += 0x0016;
    if (--cx)
        goto loc_6479;
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_6478;
    if (memory16(ds, 0x3a4c) == 0x7fff)
        goto loc_6478;
    memory16(ds, 0x3a4c) = 0x7fff;
    dx = memory16(ds, 0x3c74);
    dx &= 0x0004;
    if (dx == 0x0000)
        goto loc_6478;
    dx = memory16(ds, 0x3c78);
    dx &= 0x0020;
    if (dx == 0x0000)
        goto loc_6478;
    si = memory16(ds, 0x3a4a);
    memory16(ds, si + 6) = 0xffff;
    memory16(ds, si + 20) = 0x7fff;
loc_6478:
    return;
loc_6479:
    goto loc_63a1;
loc_647c:
    memory16(ds, si + 4) = 0x0000;
    memory16(ds, si + 2) = 0xffff;
    memory16(ds, si + 6) = 0x7fff;
    ax = memory16(ds, si + 18);
    ax += ax;
    bx = 0x3f9e;
    bx += ax;
    bx = memory16(ds, bx);
    memory16(ds, bx + 14) = memory16(ds, bx + 14) - 1;
    ax = memory16(ds, si + 8);
    dl = 0x2d;
    sub_57b4();
    ax = memory16(ds, si + 8);
    push(ax);
    dx = 0x0001;
    sub_614e();
    ax = pop();
    memory16(ds, si + 16) = cx;
    push(ax);
    dx = 0x0100;
    sub_614e();
    ax = pop();
    memory16(ds, si + 12) = cx;
    push(ax);
    dx = 0x00ff;
    sub_614e();
    ax = pop();
    memory16(ds, si + 14) = cx;
    push(ax);
    dx = 0xff00;
    sub_614e();
    ax = pop();
    memory16(ds, si + 10) = cx;
    push(ax);
    push(si);
    ax = 0x0004;
    sub_8ca1();
    si = pop();
    ax = pop();
    goto loc_6435;
loc_64eb:
    goto loc_65b4;
loc_64ee:
    dx = memory16(ds, 0x001e);
    dx = 0x0006;
    memory16(ds, si + 4) = memory16(ds, si + 4) + dx;
    if (memory16(ds, si + 4) < 0x0005)
        goto loc_6511;
    memory16(ds, si + 4) = 0x0000;
    memory16(ds, si + 2) = memory16(ds, si + 2) - 1;
    if (memory16(ds, si + 2) < 0xfff5)
        goto loc_64eb;
loc_6511:
    push(si);
    bx = 0x3b82;
    ax = memory16(ds, si + 2);
    ax = -ax;
    ax += ax;
    bx += ax;
    ax = memory16(ds, bx);
    ax += 0x0034;
    di = memory16(ds, si);
    sub_4ffe();
    di += memory16(ds, 0x0018);
    sub_273a();
    si = pop();
    ax = memory16(ds, si + 8);
    dx = 0x0001;
    cx = memory16(ds, si + 16);
    sub_68e8();
    di = memory16(ds, si);
    cx = memory16(ds, si + 16);
    dx = 0x0004;
    ax = 0x0090;
    sub_65c6();
    ax = memory16(ds, si + 8);
    dx = 0x0100;
    cx = memory16(ds, si + 12);
    sub_68e8();
    di = memory16(ds, si);
    cx = memory16(ds, si + 12);
    dx = 0x0800;
    ax = 0x0030;
    sub_65c6();
    ax = memory16(ds, si + 8);
    dx = 0xff00;
    cx = memory16(ds, si + 10);
    sub_68e8();
    di = memory16(ds, si);
    cx = memory16(ds, si + 10);
    dx = 0xf800;
    ax = 0x0000;
    sub_65c6();
    ax = memory16(ds, si + 8);
    dx = 0x00ff;
    cx = memory16(ds, si + 14);
    sub_68e8();
    di = memory16(ds, si);
    cx = memory16(ds, si + 14);
    dx = 0xfffc;
    ax = 0x0060;
    sub_65c6();
    goto loc_6435;
loc_65b4:
    memory16(ds, si) = 0xffff;
    ax = memory16(ds, si + 8);
    dl = 0x2e;
    sub_57b4();
    goto loc_6435;
}
void sub_65c6()
{
    if (memory16(ds, 0x26f2) != 0x0002)
        goto loc_65e5;
    bx = dx;
    bx &= 0x0007;
    if (bx == 0x0004)
        goto loc_65e5;
    if (dx != 0x0800)
        goto loc_65e2;
    dx = 0x0400;
    goto loc_65e5;
loc_65e2:
    dx = 0xfc00;
loc_65e5:
    bx = 0x3b9e;
    bx += ax;
    ax = memory16(ds, si + 2);
    ax = -ax;
    ax += ax;
    ax += ax;
    bx += ax;
    push(cx);
    if ((short)cx >= 0)
        goto loc_65ff;
    cx = -cx;
    cx--;
loc_65ff:
    ax = memory16(ds, bx);
    push(bx);
    if (cx == 0x0000)
        goto loc_6621;
loc_6609:
    push(cx);
    push(si);
    di += dx;
    di &= 0xffff;
    push(di);
    push(ax);
    push(dx);
    sub_4ffe();
    di += memory16(ds, 0x0018);
    sub_273a();
    dx = pop();
    ax = pop();
    di = pop();
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_6609;
loc_6621:
    bx = pop();
    cx = pop();
    if ((short)cx >= 0)
        return;
    push(si);
    di += dx;
    di &= 0xffff;
    push(di);
    ax = memory16(ds, bx + 2);
    sub_4ffe();
    di += memory16(ds, 0x0018);
    sub_273a();
    di = pop();
    si = pop();
}
void sub_663d()
{
    if ((short)memory16(ds, si + 10) < 0)
        return;
    memory16(ds, si + 10) = memory16(ds, si + 10) + 0x0001;
    if (memory16(ds, si + 10) < 0x000a)
        return;
    memory16(ds, si + 10) = 0x0000;
    memory16(ds, si + 8) = memory16(ds, si + 8) + 1;
    memory16(ds, si + 8) = memory16(ds, si + 8) & 0x0003;
}
void sub_6660()
{
    bx = memory16(ds, 0x3a54);
    memory16(ds, si + 4) = memory16(ds, si + 4) + bx;
    cl = memory(ds, si + 5);
    ch = 0x00;
    memory(ds, si + 5) = 0x00;
loc_6673:
    push(cx);
    sub_5f43();
    sub_670c();
    sub_663d();
    sub_5fd7();
    if (dx != 0x0000)
        goto loc_6689;
    cx = pop();
    if (--cx)
        goto loc_6673;
    return;
loc_6689:
    cx = pop();
}
void sub_668b()
{
    bx = memory16(ds, 0x3a54);
    memory16(ds, si + 4) = memory16(ds, si + 4) + bx;
    cl = memory(ds, si + 5);
    ch = 0x00;
    memory(ds, si + 5) = 0x00;
loc_669e:
    push(cx);
    sub_5f43();
    sub_67c2();
    sub_663d();
    sub_5fd7();
    if (dx != 0x0000)
        goto loc_66b4;
    cx = pop();
    if (--cx)
        goto loc_669e;
    return;
loc_66b4:
    cx = pop();
}
void sub_66b6()
{
    bx = memory16(ds, 0x3a54);
    memory16(ds, si + 6) = memory16(ds, si + 6) + bx;
    cl = memory(ds, si + 7);
    ch = 0x00;
    memory(ds, si + 7) = 0x00;
loc_66c9:
    push(cx);
    sub_5f43();
    sub_681d();
    sub_663d();
    sub_5fd7();
    if (dx != 0x0000)
        goto loc_66df;
    cx = pop();
    if (--cx)
        goto loc_66c9;
    return;
loc_66df:
    cx = pop();
}
void sub_66e1()
{
    bx = memory16(ds, 0x3a54);
    memory16(ds, si + 6) = memory16(ds, si + 6) + bx;
    cl = memory(ds, si + 7);
    ch = 0x00;
    memory(ds, si + 7) = 0x00;
loc_66f4:
    push(cx);
    sub_5f43();
    sub_6767();
    sub_663d();
    sub_5fd7();
    if (dx != 0x0000)
        goto loc_670a;
    cx = pop();
    if (--cx)
        goto loc_66f4;
    return;
loc_670a:
    cx = pop();
}
void sub_670c()
{
    ax = memory16(ds, 0x3a58);
    if (ax != 0x0000)
        goto loc_671e;
    al = memory(ds, 0x3f97);
    sub_6878();
    if (al != 0x2e)
        goto loc_6736;
loc_671e:
    ax = memory16(ds, 0x3a5a);
    if (ax == 0x0000)
        goto loc_6762;
    if ((short)ax >= 0)
        goto loc_672f;
    memory16(ds, si + 2) = memory16(ds, si + 2) + 1;
    goto loc_6762;
loc_672f:
    memory16(ds, si + 2) = memory16(ds, si + 2) - 1;
    goto loc_6762;
loc_6736:
    ax = memory16(ds, 0x3a5a);
    if (ax == 0x0000)
        return;
    if ((short)ax >= 0)
        goto loc_6751;
    al = memory(ds, 0x3f96);
    sub_6878();
    if (al != 0x2e)
        return;
    memory16(ds, si + 2) = memory16(ds, si + 2) - 1;
    return;
loc_6751:
    al = memory(ds, 0x3f98);
    sub_6878();
    if (al != 0x2e)
        return;
    memory16(ds, si + 2) = memory16(ds, si + 2) + 1;
    return;
loc_6762:
    memory16(ds, si) = memory16(ds, si) + 1;
}
void sub_6767()
{
    ax = memory16(ds, 0x3a5a);
    if (ax != 0x0000)
        goto loc_6779;
    al = memory(ds, 0x3f99);
    sub_6878();
    if (al != 0x2e)
        goto loc_6791;
loc_6779:
    ax = memory16(ds, 0x3a58);
    if (ax == 0x0000)
        goto loc_67bd;
    if ((short)ax >= 0)
        goto loc_678a;
    memory16(ds, si) = memory16(ds, si) + 1;
    goto loc_67bd;
loc_678a:
    memory16(ds, si) = memory16(ds, si) - 1;
    goto loc_67bd;
loc_6791:
    ax = memory16(ds, 0x3a58);
    if (ax == 0x0000)
        return;
    if ((short)ax >= 0)
        goto loc_67ac;
    al = memory(ds, 0x3f9a);
    sub_6878();
    if (al != 0x2e)
        return;
    memory16(ds, si) = memory16(ds, si) - 1;
    return;
loc_67ac:
    al = memory(ds, 0x3f98);
    sub_6878();
    if (al != 0x2e)
        return;
    memory16(ds, si) = memory16(ds, si) + 1;
    return;
loc_67bd:
    memory16(ds, si + 2) = memory16(ds, si + 2) + 1;
}
void sub_67c2()
{
    ax = memory16(ds, 0x3a58);
    if (ax != 0x0000)
        goto loc_67d4;
    al = memory(ds, 0x3f9b);
    sub_6878();
    if (al != 0x2e)
        goto loc_67ec;
loc_67d4:
    ax = memory16(ds, 0x3a5a);
    if (ax == 0x0000)
        goto loc_6818;
    if ((short)ax >= 0)
        goto loc_67e5;
    memory16(ds, si + 2) = memory16(ds, si + 2) + 1;
    goto loc_6818;
loc_67e5:
    memory16(ds, si + 2) = memory16(ds, si + 2) - 1;
    goto loc_6818;
loc_67ec:
    ax = memory16(ds, 0x3a5a);
    if (ax == 0x0000)
        return;
    if ((short)ax >= 0)
        goto loc_6807;
    al = memory(ds, 0x3f94);
    sub_6878();
    if (al != 0x2e)
        return;
    memory16(ds, si + 2) = memory16(ds, si + 2) - 1;
    return;
loc_6807:
    al = memory(ds, 0x3f9a);
    sub_6878();
    if (al != 0x2e)
        return;
    memory16(ds, si + 2) = memory16(ds, si + 2) + 1;
    return;
loc_6818:
    memory16(ds, si) = memory16(ds, si) - 1;
}
void sub_681d()
{
    ax = memory16(ds, 0x3a5a);
    if (ax != 0x0000)
        goto loc_682f;
    al = memory(ds, 0x3f95);
    sub_6878();
    if (al != 0x2e)
        goto loc_6847;
loc_682f:
    ax = memory16(ds, 0x3a58);
    if (ax == 0x0000)
        goto loc_6873;
    if ((short)ax >= 0)
        goto loc_6840;
    memory16(ds, si) = memory16(ds, si) + 1;
    goto loc_6873;
loc_6840:
    memory16(ds, si) = memory16(ds, si) - 1;
    goto loc_6873;
loc_6847:
    ax = memory16(ds, 0x3a58);
    if (ax == 0x0000)
        return;
    if ((short)ax >= 0)
        goto loc_6862;
    al = memory(ds, 0x3f94);
    sub_6878();
    if (al != 0x2e)
        return;
    memory16(ds, si) = memory16(ds, si) - 1;
    return;
loc_6862:
    al = memory(ds, 0x3f96);
    sub_6878();
    if (al != 0x2e)
        return;
    memory16(ds, si) = memory16(ds, si) + 1;
    return;
loc_6873:
    memory16(ds, si + 2) = memory16(ds, si + 2) - 1;
}
void sub_6878()
{
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_68aa;
    dx = memory16(ds, si + 22);
    dx &= 0x0001;
    if (dx == 0x0000)
        goto loc_689a;
    if (al == 0x45)
        goto loc_68b6;
    if (al < 0x41)
        goto loc_689a;
    if (al > 0x56)
        goto loc_689a;
    goto loc_68b6;
loc_689a:
    dx = memory16(ds, si + 22);
    dx &= 0x0002;
    if (dx == 0x0000)
        goto loc_68aa;
    if (al == 0x2b)
        goto loc_68b6;
loc_68aa:
    if (al == 0x2d)
        goto loc_68b6;
    if (al < 0x61)
        return;
    if (al > 0x75)
        return;
loc_68b6:
    al = 0x2e;
    return;
}
void sub_68ba()
{
    ax = memory16(ds, 0x3a56);
    ax += memory16(ds, 0x001e);
    if (ax < 0x0014)
        goto loc_68e4;
    ax = 0x0000;
    si = 0x3fa6;
    memory(ds, 0x3a5c) = ~memory(ds, 0x3a5c);
    if (memory(ds, 0x3a5c) != 0x00)
        goto loc_68da;
    si = 0x3fa9;
loc_68da:
    push(ax);
    al = 0x20;
    cx = 0x0001;
    sub_2397();
    ax = pop();
loc_68e4:
    memory16(ds, 0x3a56) = ax;
}
void sub_68e8()
{
    if ((short)cx >= 0)
        goto loc_68ef;
    cx = -cx;
loc_68ef:
    cx++;
    push(si);
    si = memory16(ds, 0x3a52);
loc_68f5:
    memory16(ds, si) = ax;
    si += 0x0002;
    al += dl;
    ah += dh;
    if (--cx)
        goto loc_68f5;
    memory16(ds, 0x3a52) = si;
    si = pop();
}
void sub_6908()
{
loc_6908:
    push(cx);
    push(ax);
    push(dx);
    si = 0x4d50;
    cx = 0x000f;
loc_6911:
    if (memory16(ds, si) == 0xffff)
        goto loc_6920;
    si += 0x0024;
    if (--cx)
        goto loc_6911;
    goto loc_6976;
loc_6920:
    push(dx);
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 10) = 0xffe7;
    ax = pop();
    memory16(ds, si + 12) = ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    di = 0x42d4;
    di += ax;
    ax = memory16(ds, di);
    memory16(ds, si + 4) = ax;
    memory16(ds, si + 6) = ax;
    ax = memory16(ds, di + 4);
    memory16(ds, si + 8) = ax;
    ax = memory16(ds, di + 6);
    memory16(ds, si + 14) = ax;
    memory16(ds, si + 18) = 0x0000;
    memory16(ds, si + 16) = 0x0000;
    memory16(ds, 0x4200) = memory16(ds, 0x4200) + 1;
loc_6976:
    dx = pop();
    ax = pop();
    cx = pop();
    if (--cx)
        goto loc_6908;
}
void sub_697c()
{
    si = 0x4d50;
    cx = 0x000f;
loc_6982:
    memory16(ds, si) = 0xffff;
    memory16(ds, si + 24) = 0x0004;
    memory16(ds, si + 26) = 0x0012;
    si += 0x0024;
    if (--cx)
        goto loc_6982;
}
void sub_699a()
{
    sub_697c();
    si = 0x4d50;
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_69b0;
    bx = memory16(ds, 0x4f78);
    bx += 0x0008;
    goto loc_69c1;
loc_69b0:
    bx = 0x42b4;
    ax = memory16(ds, 0x0010);
    ax -= 0x0002;
    ax += ax;
    bx += ax;
    bx = memory16(ds, bx);
loc_69c1:
    cx = memory16(ds, bx);
    if ((short)cx < 0)
        goto loc_6a38;
    if (cx == 0x0000)
        goto loc_6a38;
    bx += 0x0002;
loc_69cf:
    push(cx);
    push(bx);
    sub_71c6();
    bx = pop();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 10) = 0x0000;
    ax = memory16(ds, bx);
    memory16(ds, si + 12) = ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    di = 0x42d4;
    di += ax;
    ax = memory16(ds, di);
    memory16(ds, si + 4) = ax;
    memory16(ds, si + 6) = ax;
    ax = memory16(ds, di + 4);
    memory16(ds, si + 8) = ax;
    ax = memory16(ds, di + 6);
    memory16(ds, si + 14) = ax;
    memory16(ds, si + 18) = 0x0000;
    memory16(ds, si + 16) = 0x0000;
    memory16(ds, 0x4200) = memory16(ds, 0x4200) + 1;
    cx = pop();
    si += 0x0024;
    if (--cx)
        goto loc_69cf;
    bx += 0x0002;
    goto loc_69c1;
loc_6a38:
    if (memory16(ds, 0x4f8a) != 0x0008)
        return;
    sub_7912();
}
void sub_6a43()
{
    memory16(ds, 0x4202) = 0x0000;
    si = 0x4d50;
    cx = 0x000f;
loc_6a4f:
    push(cx);
    if (memory16(ds, si) != 0xffff)
        goto loc_6a5a;
    goto loc_6b1a;
loc_6a5a:
    if ((short)memory16(ds, si + 12) >= 0)
        goto loc_6a64;
    goto loc_6b2e;
loc_6a64:
    ax = 0x0100;
    cx = memory16(ds, si + 14);
    dx = cx;
    dx &= 0x0004;
    if (dx == 0x0000)
        goto loc_6a85;
    ax = 0x0200;
    dx = cx;
    cx &= 0x000c;
    if (cx != 0x000c)
        goto loc_6a85;
    ax = 0x0300;
loc_6a85:
    memory16(ds, si + 16) = memory16(ds, si + 16) + ax;
    cl = memory(ds, si + 17);
    ch = 0x00;
    memory(ds, si + 17) = 0x00;
loc_6a94:
    push(cx);
    sub_6c50();
    cx = pop();
    if (--cx)
        goto loc_6a94;
    bx = memory16(ds, si + 6);
    dx = memory16(ds, 0x001e);
    ax = memory16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_6ac5;
    ah = 0x00;
    bx += 0x0010;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_6ac5;
    bx = memory16(ds, si + 4);
    memory16(ds, si + 6) = bx;
loc_6ac5:
    memory16(ds, si + 8) = ax;
    push(si);
    ax = memory16(ds, si + 10);
    if ((short)ax < 0)
        goto loc_6adc;
    ax &= 0x0003;
    ax += ax;
    ax += ax;
    bx += ax;
loc_6adc:
    ax = memory16(ds, bx);
    memory16(ds, si + 20) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 22) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0002;
    if (memory16(ds, si + 12) != 0x0017)
        goto loc_6b01;
    cx -= 0x0004;
loc_6b01:
    sub_703a();
    if (ax != 0x0000)
        goto loc_6b0f;
    si += 0x0014;
    sub_2782();
loc_6b0f:
    si = pop();
    if (memory16(ds, si + 12) == 0x0017)
        goto loc_6b1a;
    sub_6bda();
loc_6b1a:
    cx = pop();
    si += 0x0024;
    if (--cx)
        goto loc_6b2b;
    if (memory16(ds, 0x4f8a) != 0x0008)
        goto loc_6b2a;
    sub_7d6b();
loc_6b2a:
    return;
loc_6b2b:
    goto loc_6a4f;
loc_6b2e:
    bx = memory16(ds, si + 6);
    ax = memory16(ds, 0x001e);
    memory16(ds, si + 8) = memory16(ds, si + 8) + ax;
    if (memory16(ds, si + 8) < 0x0078)
        goto loc_6b93;
    memory16(ds, si + 8) = 0x0064;
    bx += 0x0004;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_6b93;
    if (memory16(ds, si + 10) == 0xffff)
        goto loc_6b8b;
    ax = memory16(ds, si + 10);
    bx = 0x422e;
    ax += ax;
    ax += ax;
    bx += ax;
    ax = memory16(ds, bx);
    memory16(ds, 0x3a50) = memory16(ds, 0x3a50) + ax;
    bx = memory16(ds, bx + 2);
    if (bx == 0x0000)
        goto loc_6b8b;
    memory16(ds, si + 10) = 0xffff;
    memory16(ds, si + 8) = 0x0000;
    memory16(ds, si + 6) = bx;
    goto loc_6b93;
loc_6b8b:
    memory16(ds, si) = 0xffff;
    goto loc_6b1a;
loc_6b93:
    push(si);
    ax = memory16(ds, bx);
    memory16(ds, si + 20) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 22) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0014;
    sub_2782();
    si = pop();
    goto loc_6b1a;
}
void sub_6bb9()
{
    push(bx);
    bx = 0x3e54;
loc_6bbd:
    dx = memory16(ds, bx);
    bx += 0x0002;
    if (bx > memory16(ds, 0x3a52))
        goto loc_6bd0;
    if (dx == ax)
        goto loc_6bd5;
    goto loc_6bbd;
loc_6bd0:
    dx = 0x0000;
    bx = pop();
    return;
loc_6bd5:
    dx = 0xffff;
    bx = pop();
}
void sub_6bda()
{
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    dx += 0x0008;
    cx += 0x0008;
    sub_581f();
    sub_6bb9();
    if (dx == 0xffff)
        goto loc_6bf4;
    return;
loc_6bf4:
    bx = 0x42d6;
    ax = memory16(ds, si + 12);
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    bx += ax;
    ax = memory16(ds, bx);
    memory16(ds, si + 6) = ax;
    ax = memory16(ds, si + 12);
    cl = 0x04;
    ax <<= cl;
    bx = 0x42d4;
    bx += ax;
    ax = memory16(ds, bx + 8);
    if (ax == 0x0000)
        goto loc_6c27;
    ax += memory16(ds, 0x4202);
loc_6c27:
    memory16(ds, si + 10) = ax;
    if (memory16(ds, 0x4202) < 0x0006)
        goto loc_6c36;
    memory16(ds, 0x4202) = memory16(ds, 0x4202) - 1;
loc_6c36:
    memory16(ds, 0x4202) = memory16(ds, 0x4202) + 1;
    memory16(ds, si + 12) = 0xffff;
    memory16(ds, si + 8) = 0x0050;
    memory16(ds, 0x4200) = memory16(ds, 0x4200) - 1;
    memory(ds, 0x4f94) = 0xff;
}
void sub_6c50()
{
    if ((short)memory16(ds, si + 10) < 0)
        goto loc_6c85;
    ax = memory16(ds, si + 10);
    sub_6f24();
    if (dx == 0x0000)
        goto loc_6c67;
    memory16(ds, si + 10) = ax;
loc_6c67:
    ax = memory16(ds, si + 10);
    ax &= 0x0001;
    if (ax == 0x0000)
        goto loc_6c88;
    ax = memory16(ds, si);
    ax -= 0x0008;
    ax &= 0x000f;
    if (ax == 0x0000)
        goto loc_6c99;
    goto loc_6d17;
loc_6c85:
    goto loc_6d37;
loc_6c88:
    ax = memory16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0x000f;
    if (ax == 0x0000)
        goto loc_6c99;
    goto loc_6d17;
loc_6c99:
    cx = memory16(ds, si + 14);
    if (!(cx & 0x0040))
        goto loc_6ca6;
    sub_6d4d();
loc_6ca6:
    ax = memory16(ds, si + 14);
    ax &= 0x0010;
    if (ax == 0x0000)
        goto loc_6cc7;
    if (memory16(ds, si + 18) == 0x0000)
        goto loc_6cbf;
    memory16(ds, si + 18) = memory16(ds, si + 18) - 1;
    goto loc_6cc7;
loc_6cbf:
    sub_6d9c();
    if (dx == 0x0000)
        goto loc_6cf8;
loc_6cc7:
    ax = 0x0064;
    sub_587c();
    dx = memory16(ds, si + 12);
    cl = 0x04;
    dx <<= cl;
    di = 0x42d4;
    di += dx;
    dx = memory16(ds, di + 10);
    if (dx == 0x0000)
        goto loc_6cf8;
    if (dx < ax)
        goto loc_6cf8;
    sub_6f9a();
    sub_6e9c();
    memory16(ds, si + 10) = ax;
    if ((short)ax < 0)
        goto loc_6d37;
    goto loc_6d17;
loc_6cf8:
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_6d17;
    memory16(ds, si + 10) = ax;
    sub_6f9a();
    sub_6e9c();
    memory16(ds, si + 10) = ax;
    if ((short)ax < 0)
        goto loc_6d37;
loc_6d17:
    ax = memory16(ds, si + 10);
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x4444;
    bx += ax;
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    memory16(ds, si) = memory16(ds, si) + ax;
    memory16(ds, si + 2) = memory16(ds, si + 2) + dx;
loc_6d36:
    return;
loc_6d37:
    memory16(ds, si + 10) = memory16(ds, si + 10) + 1;
    if (memory16(ds, si + 10) != 0x0000)
        goto loc_6d36;
    sub_6f9a();
    sub_6e9c();
    memory16(ds, si + 10) = ax;
}
void sub_6d4d()
{
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    dx = memory16(ds, si + 10);
    bx = 0x4444;
    cl = 0x03;
    dx <<= cl;
    bx += dx;
    dx = memory16(ds, bx + 4);
    memory16(ds, 0x41fa) = ax;
    memory16(ds, 0x41fc) = dx;
loc_6d70:
    ax = memory16(ds, 0x41fa);
    dx = memory16(ds, 0x41fc);
    al += dl;
    ah += dh;
    memory16(ds, 0x41fa) = ax;
    memory16(ds, 0x41fc) = dx;
    sub_5832();
    if (al == 0x2b)
        goto loc_6d92;
    if (al == 0x2d)
        goto loc_6d92;
    if (al == 0x2e)
        goto loc_6d70;
    return;
loc_6d92:
    memory16(ds, si + 10) = memory16(ds, si + 10) + 1;
    memory16(ds, si + 10) = memory16(ds, si + 10) & 0x0003;
}
void sub_6d9c()
{
    dx = memory16(ds, 0x3c5e);
    cx = memory16(ds, 0x3c60);
    sub_581f();
    push(ax);
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    dx = pop();
    if (al == dl)
        goto loc_6e27;
    if (ah == dh)
        goto loc_6e0e;
    memory16(ds, 0x41fa) = ax;
    memory16(ds, 0x41fc) = dx;
    al -= dl;
    if ((char)al >= 0)
        goto loc_6dcb;
    al = -al;
loc_6dcb:
    ah -= dh;
    if ((char)ah >= 0)
        goto loc_6dd4;
    ah = -ah;
loc_6dd4:
    if (al > ah)
        goto loc_6e40;
    ax = memory16(ds, 0x41fa);
    dx = memory16(ds, 0x41fc);
    sub_6e89();
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_6e26;
    ax = memory16(ds, 0x41fa);
    dx = memory16(ds, 0x41fc);
    sub_6e76();
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_6e26;
    memory16(ds, si + 18) = 0x0004;
    dx = 0xffff;
    return;
loc_6e0e:
    sub_6e76();
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_6e26;
    memory16(ds, si + 18) = 0x0004;
    dx = 0xffff;
loc_6e26:
    return;
loc_6e27:
    sub_6e89();
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_6e26;
    memory16(ds, si + 18) = 0x0004;
    dx = 0xffff;
    return;
loc_6e40:
    ax = memory16(ds, 0x41fa);
    dx = memory16(ds, 0x41fc);
    sub_6e76();
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_6e26;
    ax = memory16(ds, 0x41fa);
    dx = memory16(ds, 0x41fc);
    sub_6e89();
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_6e26;
    memory16(ds, si + 18) = 0x0004;
    dx = 0xffff;
}
void sub_6e76()
{
    if (al >= dl)
        goto loc_6e82;
    memory16(ds, si + 10) = 0x0001;
    return;
loc_6e82:
    memory16(ds, si + 10) = 0x0003;
}
void sub_6e89()
{
    if (ah >= dh)
        goto loc_6e95;
    memory16(ds, si + 10) = 0x0002;
    return;
loc_6e95:
    memory16(ds, si + 10) = 0x0000;
}
void sub_6e9c()
{
    ax = memory16(ds, 0x4d4e);
    if (ax == 0x0000)
        goto loc_6eba;
    ax--;
    if (ax == 0x0000)
        goto loc_6eae;
    ax++;
    sub_587c();
loc_6eae:
    ax += ax;
    bx = 0x4d3c;
    bx += ax;
    ax = memory16(ds, bx);
    return;
loc_6eba:
    ax = 0xffff;
}
void sub_6ebe()
{
    if ((short)ax < 0)
        goto loc_6f14;
    push(ax);
    bx = 0x4444;
    ax += ax;
    ax += ax;
    ax += ax;
    bx += ax;
    ax = memory16(ds, bx + 4);
    push(ax);
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx += 0x0008;
    dx += 0x0008;
    sub_581f();
    memory16(ds, 0x41fe) = ax;
    dx = pop();
    al += dl;
    ah += dh;
    sub_5832();
    dx = pop();
    cx = memory16(ds, si + 14);
    if (cx & 0x0080)
        goto loc_6eff;
    if (al == 0x2b)
        goto loc_6f14;
loc_6eff:
    if (cx & 0x0001)
        goto loc_6f10;
    if (al < 0x41)
        goto loc_6f10;
    if (al > 0x55)
        goto loc_6f10;
    goto loc_6f14;
loc_6f10:
    if (al != 0x2a)
        goto loc_6f1e;
loc_6f14:
    ax = 0x0004;
    sub_587c();
    dx = 0xffff;
    return;
loc_6f1e:
    ax = dx;
    dx = 0x0000;
}
void sub_6f24()
{
    if ((short)ax < 0)
        goto loc_6f56;
    push(ax);
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx += 0x0008;
    dx += 0x0008;
    sub_581f();
    memory16(ds, 0x41fe) = ax;
    sub_5832();
    dx = pop();
    cx = memory16(ds, si + 14);
    if (cx & 0x0080)
        goto loc_6f50;
    if (al == 0x2b)
        goto loc_6f56;
loc_6f50:
    ax = dx;
    dx = 0x0000;
    return;
loc_6f56:
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    dx -= 0x0008;
    cx -= 0x0018;
    dx += 0x0008;
    cx += 0x0008;
    dx &= 0x000f;
    cx &= 0x000f;
    ax = memory16(ds, si + 10);
    if (!(ax & 0x0001))
        goto loc_6f87;
    ax = 0x0003;
    if (dx < 0x0008)
        goto loc_6f92;
    ax = 0x0001;
    goto loc_6f92;
loc_6f87:
    ax = 0x0000;
    if (cx < 0x0008)
        goto loc_6f92;
    ax = 0x0002;
loc_6f92:
    memory16(ds, si + 10) = ax;
    dx = 0xffff;
}
void sub_6f9a()
{
    bx = 0x4d3c;
    memory16(ds, bx + 18) = 0x0000;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx += 0x0008;
    dx += 0x0008;
    sub_581f();
    di = 0x4444;
    cx = 0x0004;
loc_6fba:
    push(cx);
    push(ax);
    dx = memory16(ds, di + 4);
    ah += dh;
    al += dl;
    sub_5832();
    if (al == 0x2a)
        goto loc_6fff;
    if (al == 0x2b)
        goto loc_6fff;
    cx = memory16(ds, si + 14);
    cx &= 0x0001;
    if (cx != 0x0000)
        goto loc_6fe5;
    if (al < 0x41)
        goto loc_6fe5;
    if (al > 0x55)
        goto loc_6fe5;
    goto loc_6fff;
loc_6fe5:
    ax = memory16(ds, di + 6);
    memory16(ds, bx) = ax;
    bx += 0x0002;
    memory16(ds, 0x4d4e) = memory16(ds, 0x4d4e) + 1;
    memory16(ds, bx) = ax;
    bx += 0x0002;
    memory16(ds, 0x4d4e) = memory16(ds, 0x4d4e) + 1;
loc_6fff:
    ax = pop();
    cx = pop();
    di += 0x0008;
    if (--cx)
        goto loc_6fba;
    cx = memory16(ds, si + 14);
    if (cx & 0x0002)
        return;
    memory16(ds, bx) = 0xfff8;
    memory16(ds, 0x4d4e) = memory16(ds, 0x4d4e) + 1;
}
void sub_701b()
{
    push(si);
    push(ax);
    dx = ax;
    si = 0x4204;
loc_7022:
    lodsw<MemData, DirForward>();
    if (ax == 0xffff)
        goto loc_702e;
    if (ax == dx)
        goto loc_7034;
    goto loc_7022;
loc_702e:
    dx = 0x0000;
    ax = pop();
    si = pop();
    return;
loc_7034:
    dx = 0xffff;
    ax = pop();
    si = pop();
}
void sub_703a()
{
    if (memory16(ds, 0x26f2) == 0x0000)
        goto loc_7065;
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_7069;
    ax = memory16(ds, 0x203e);
    bx = memory16(ds, si);
    bx += 0x0010;
    ax -= 0x0080;
    if (ax > bx)
        goto loc_7087;
    ax = memory16(ds, 0x203e);
    ax += 0x0080;
    if (ax < memory16(ds, si))
        goto loc_7087;
loc_7065:
    ax = 0x0000;
    return;
loc_7069:
    ax = memory16(ds, 0x203e);
    bx = memory16(ds, si + 2);
    ax -= 0x007c;
    if (ax > bx)
        goto loc_7087;
    ax = memory16(ds, 0x203e);
    ax += 0x006c;
    if (ax < memory16(ds, si + 2))
        goto loc_7087;
    ax = 0x0000;
    return;
loc_7087:
    ax = 0xffff;
}
void sub_708b()
{
    si = 0x3c5e;
    if (memory16(ds, si) == 0xffff)
        goto loc_70cb;
    if ((short)memory16(ds, si + 8) < 0)
        goto loc_70cb;
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_70b1;
    dx = memory16(ds, si + 22);
    dx &= 0x0008;
    if (dx == 0x0000)
        goto loc_70b1;
    goto loc_70b4;
loc_70b1:
    sub_7165();
loc_70b4:
    sub_7111();
    if (memory16(ds, 0x4f88) == 0x0000)
        goto loc_70cb;
    if ((short)memory16(ds, si + 8) >= 0)
        goto loc_70cb;
    ax = 0x0005;
    sub_8c10();
loc_70cb:
    si = 0x3c7e;
    if (memory16(ds, si) == 0xffff)
        goto loc_70e2;
    if ((short)memory16(ds, si + 8) < 0)
        goto loc_70e2;
    sub_7165();
    sub_7111();
loc_70e2:
    si = 0x3c9e;
    if (memory16(ds, si) == 0xffff)
        goto loc_70f9;
    if ((short)memory16(ds, si + 8) < 0)
        goto loc_70f9;
    sub_7165();
    sub_7111();
loc_70f9:
    si = 0x3cbe;
    if (memory16(ds, si) == 0xffff)
        return;
    if ((short)memory16(ds, si + 8) < 0)
        return;
    sub_7165();
    sub_7111();
}
void sub_7111()
{
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    dx = ax;
    bx = 0x4d50;
    cx = 0x000f;
loc_7124:
    push(cx);
    if (memory16(ds, bx) == 0xffff)
        goto loc_714a;
    if ((short)memory16(ds, bx + 12) < 0)
        goto loc_714a;
    push(dx);
    dx = memory16(ds, bx);
    dx += 0x0008;
    cx = memory16(ds, bx + 2);
    cx += 0x0008;
    sub_581f();
    dx = pop();
    if (ax == dx)
        goto loc_7151;
loc_714a:
    bx += 0x0024;
    cx = pop();
    if (--cx)
        goto loc_7124;
    return;
loc_7151:
    cx = pop();
    memory16(ds, si + 8) = 0xffff;
    memory16(ds, si + 10) = 0x0000;
    ax = 0x0000;
    sub_8ca1();
}
void sub_7165()
{
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    dx = ax;
    bx = 0x3e54;
loc_7175:
    ax = memory16(ds, bx);
    bx += 0x0002;
    if (bx > memory16(ds, 0x3a52))
        goto loc_7188;
    if (dx == ax)
        goto loc_7189;
    goto loc_7175;
loc_7188:
    return;
loc_7189:
    memory16(ds, si + 8) = 0xffff;
    memory16(ds, si + 10) = 0x0000;
    ax = 0x0000;
    sub_8ca1();
}
void sub_71c6()
{
loc_71c6:
    ax = memory16(ds, 0x26f6);
    sub_587c();
    push(ax);
    ax = memory16(ds, 0x26f4);
    sub_587c();
    dx = pop();
    ah = dl;
    bx = ax;
    sub_5832();
    if (al != 0x2e)
        goto loc_71c6;
    ax = bx;
    sub_701b();
    if (dx != 0x0000)
        goto loc_71c6;
}
void sub_71ea()
{
    memory16(ds, 0x4f8e) = 0x0003;
    memory16(ds, 0x3a50) = 0x0000;
    ax = 0x0005;
    sub_77c8();
    memory(ds, 0x4f97) = 0xff;
    ax = 0x0004;
    sub_77c8();
loc_7208:
    if (memory16(ds, 0x4f8a) != 0x0001)
        goto loc_7212;
    sub_4155();
loc_7212:
    si = 0x4fbc;
    bx = memory16(ds, 0x4f88);
    bx += bx;
    si = memory16(ds, bx + si);
    lodsw<MemData, DirForward>();
    sub_77c8();
    di = 0x08de;
    push(ds);
    sub_23d3();
    ds = pop();
    memory16(ds, 0x0012) = 0x0000;
    si = 0x3c5e;
    memory16(ds, si + 22) = 0x0000;
loc_723a:
    if (memory16(ds, 0x4f88) != 0x0008)
        goto loc_725b;
    if (memory16(ds, 0x4f8a) != 0x0008)
        goto loc_725b;
    if (memory(ds, 0x4f97) == 0x00)
        goto loc_725b;
    ax = 0x0006;
    sub_77c8();
    memory(ds, 0x4f97) = 0x00;
loc_725b:
    if (memory16(ds, 0x4f88) != 0x0008)
        goto loc_726c;
    if (memory16(ds, 0x4f8a) != 0x0008)
        goto loc_726c;
    goto loc_727f;
loc_726c:
    if (memory(ds, 0x4f97) != 0x00)
        goto loc_727f;
    ax = 0x0005;
    sub_77c8();
    memory(ds, 0x4f97) = 0xff;
loc_727f:
    ax = memory16(ds, 0x3c6a);
    memory16(ds, 0x4f72) = ax;
    ax = memory16(ds, 0x3c70);
    memory16(ds, 0x4f74) = ax;
    ax = memory16(ds, 0x3a54);
    memory16(ds, 0x4f76) = ax;
    si = 0x4fbc;
    bx = memory16(ds, 0x4f88);
    bx += bx;
    si = memory16(ds, bx + si);
    si += 0x0002;
    bx = memory16(ds, 0x4f8a);
    bx += bx;
    ax = memory16(ds, bx + si);
    memory16(ds, 0x4f78) = ax;
    sub_4279();
    sub_2fcb();
    sub_2fdd();
    ax = 0x3e54;
    memory16(ds, 0x3a52) = ax;
    sub_4f14();
    si = 0x3c5e;
    memory16(ds, si) = 0xffff;
    memory16(ds, si + 32) = 0xffff;
    memory16(ds, si + 64) = 0xffff;
    memory16(ds, si + 96) = 0xffff;
    si = 0x3c5e;
    ax = 0x0101;
    sub_57d2();
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 14) = 0x0000;
    memory16(ds, si + 24) = 0x0000;
    memory16(ds, si + 26) = 0x0000;
    memory16(ds, si + 28) = 0x0000;
    memory16(ds, si + 10) = 0x0000;
    memory16(ds, si + 8) = 0x0000;
    memory16(ds, si + 22) = memory16(ds, si + 22) & 0xfff7;
    memory16(ds, si + 20) = 0x0000;
    memory(ds, 0x0023) = 0xff;
    ax = 0x0004;
    memory16(ds, 0x37ce) = ax;
    ax = 0x0000;
    memory16(ds, 0x37d0) = ax;
    memory16(ds, 0x204c) = 0xffff;
    ax = memory16(ds, 0x26f2);
    ax += ax;
    si = 0x4fb6;
    si += ax;
    si = memory16(ds, si);
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    di = 0x0726;
    cx = 0x01b8;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    sub_50e9();
    sub_4f8b();
    sub_76bc();
    sub_2c65();
    sub_2a67();
    memory16(ds, 0x4200) = 0x0000;
    sub_699a();
    memory16(ds, 0x4f6c) = 0x0036;
    sub_5a41();
    sub_6a43();
    memory(ds, 0x4f94) = 0x00;
    sub_2ad4();
    sub_2318();
    sub_2ad4();
    sub_51ff();
    ax = memory16(ds, 0x001a);
    sub_305b();
    ax = 0x000c;
    dx = memory16(ds, 0x4f8a);
    if (dx & 0x0001)
        goto loc_73ac;
    ax = 0x000d;
    if (memory16(ds, 0x4f8a) != 0x0008)
        goto loc_73ac;
    ax = 0x000b;
    memory(ds, 0x4f94) = 0xff;
loc_73ac:
    sub_8c10();
    memory16(ds, 0x4f86) = 0x0000;
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
    memory16(ds, 0x4f80) = 0x3039;
    memory16(ds, 0x4f82) = 0x3039;
    memory16(ds, 0x4f7e) = 0x3039;
    memory16(ds, 0x4f84) = 0x3039;
    memory16(ds, 0x3a4e) = 0x0000;
    memory16(ds, 0x4f7a) = 0x0000;
    memory16(ds, 0x4f7c) = 0x0000;
    memory(ds, 0x0023) = 0x00;
    memory16(ds, 0x204c) = 0x0000;
    memory16(ds, 0x4f6c) = 0x0ca8;
    memory(ds, 0x0020) = 0x00;
loc_7407:
    sub_2bfb();
    sub_281e();
    sub_552a();
    sub_5efa();
    sub_638f();
    sub_59d8();
    sub_6315();
    sub_7690();
    si = 0x3c5e;
    sub_5dce();
    sub_6a43();
    sub_5a41();
    sub_2fef();
    sub_770c();
    sub_2ad4();
    if (memory(ds, 0x2050) != 0x00)
        goto loc_7441;
    sub_708b();
    goto loc_746d;
loc_7441:
    ax = 0x0000;
    al = memory(ds, 0x0020);
    if (al < 0x02)
        goto loc_7459;
    if (al > 0x09)
        goto loc_7459;
    ax--;
    memory16(ds, 0x4f8a) = ax;
    memory16(ds, 0x4f7c) = 0x0003;
loc_7459:
    if (al < 0x3b)
        goto loc_746d;
    if (al > 0x42)
        goto loc_746d;
    ax -= 0x003a;
    memory16(ds, 0x4f88) = ax;
    memory16(ds, 0x4f7c) = 0x0004;
loc_746d:
    if (memory16(ds, 0x4f7c) == 0x0000)
        goto loc_7477;
    goto loc_74f9;
loc_7477:
    si = 0x3c5e;
    if (memory16(ds, si) != 0xffff)
        goto loc_7492;
    memory16(ds, 0x4f7a) = memory16(ds, 0x4f7a) + 1;
    if (memory16(ds, 0x4f7a) < 0x0012)
        goto loc_7492;
    memory16(ds, 0x4f7c) = 0x0001;
loc_7492:
    if (memory16(ds, 0x37ce) != 0x0000)
        goto loc_74aa;
    if (memory16(ds, 0x37d0) != 0x0000)
        goto loc_74aa;
    if (memory16(ds, 0x204c) != 0x0011)
        goto loc_74aa;
    sub_76db();
loc_74aa:
    sub_3503();
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_30d4();
    if (memory(ds, 0x0020) != 0x19)
        goto loc_74cd;
    if (memory16(ds, 0x4f8a) == 0x0008)
        goto loc_74cd;
    sub_75bc();
loc_74cd:
    sub_68ba();
    sub_77a9();
    sub_8b8b();
    sub_350c();
//    sync();
    if (memory(ds, 0x0020) != 0x01)
        goto loc_74e3;
    goto loc_74e6;
loc_74e3:
    goto loc_7407;
loc_74e6:
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    return;
loc_74f9:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    memory16(ds, 0x203e) = 0x0080;
    sub_30d4();
    if (memory16(ds, 0x4f7c) == 0x0001)
        goto loc_754b;
    if (memory16(ds, 0x4f7c) == 0x0002)
        goto loc_7591;
    if (memory16(ds, 0x4f7c) == 0x0003)
        goto loc_7545;
    if (memory16(ds, 0x4f7c) == 0x0004)
        goto loc_7548;
    goto loc_74e6;
loc_7545:
    goto loc_723a;
loc_7548:
    goto loc_7208;
loc_754b:
    ax = memory16(ds, 0x4f72);
    memory16(ds, 0x3c6a) = ax;
    ax = memory16(ds, 0x4f74);
    memory16(ds, 0x3c70) = ax;
    ax = memory16(ds, 0x4f76);
    memory16(ds, 0x3a54) = ax;
    memory16(ds, 0x3c74) = 0x0000;
    if (memory16(ds, 0x4f8c) == 0x0000)
        goto loc_7571;
    memory16(ds, 0x4f8c) = memory16(ds, 0x4f8c) - 1;
    goto loc_723a;
loc_7571:
    sub_4052();
    if (memory16(ds, 0x26fc) == 0x0000)
        goto loc_757e;
    goto loc_74e6;
loc_757e:
    memory16(ds, 0x3a50) = 0x0000;
    memory16(ds, 0x4f8e) = memory16(ds, 0x4f8e) - 1;
    memory16(ds, 0x4f8c) = 0x0002;
    goto loc_723a;
loc_7591:
    if (memory16(ds, 0x4f8a) == 0x0008)
        goto loc_759f;
    memory16(ds, 0x4f8a) = memory16(ds, 0x4f8a) + 1;
    goto loc_723a;
loc_759f:
    if (memory16(ds, 0x4f88) == 0x0008)
        goto loc_75b6;
    memory16(ds, 0x4f88) = memory16(ds, 0x4f88) + 1;
    memory16(ds, 0x4f8a) = 0x0001;
    goto loc_7208;
    //   gap of 3 bytes
loc_75b6:
    sub_8ed2();
    goto loc_74e6;
}
void sub_75bc()
{
    memory(ds, 0x0020) = 0x00;
    memory(ds, 0x0023) = 0xff;
    sub_8b75();
    memory16(ds, 0x4f70) = 0x0000;
    if (memory16(ds, 0x26f2) == 0x0000)
        goto loc_75f9;
    if (memory16(ds, 0x26f2) == 0x0001)
        goto loc_75ec;
    ax = memory16(ds, 0x203e);
    ax -= 0x0080;
    cl = 0x06;
    ax <<= cl;
    memory16(ds, 0x4f70) = ax;
    goto loc_75f9;
loc_75ec:
    ax = memory16(ds, 0x203e);
    ax -= 0x0080;
    ax >>= 1;
    ax >>= 1;
    memory16(ds, 0x4f70) = ax;
loc_75f9:
    si = memory16(ds, 0x001a);
    si += memory16(ds, 0x4f70);
    dx = 0x0040;
    cx = 0x0018;
    ax = 0x25f0;
    es = ax;
    di = 0x5590;
    sub_26b6();
    di = memory16(ds, 0x001a);
    di += memory16(ds, 0x4f70);
    dx = 0x0040;
    cx = 0x0018;
    al = 0x00;
    sub_2cb3();
    di = memory16(ds, 0x001a);
    di += memory16(ds, 0x4f70);
    di += 0x021b;
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_763c;
    di += 0x0200;
loc_763c:
    ax = 0x00c9;
    sub_273a();
loc_7642:
    al = memory(ds, 0x0020);
    if (al == 0x01)
        return;
    if (al == 0x19)
        goto loc_764f;
    goto loc_7642;
loc_764f:
    memory(ds, 0x0020) = 0x00;
    di = memory16(ds, 0x001a);
    di += memory16(ds, 0x4f70);
    dx = 0x0040;
    cx = 0x0018;
    ax = 0x25f0;
    es = ax;
    si = 0x5590;
    if (memory16(ds, 0x26f2) == 0x0002)
        goto loc_767c;
    push(ds);
    ax = 0x25f0;
    ds = ax;
    sub_263d();
    goto loc_7685;
loc_767c:
    push(ds);
    ax = 0x25f0;
    ds = ax;
    sub_267a();
loc_7685:
    ds = pop();
    memory(ds, 0x0023) = 0x00;
    sub_8b6a();
    return;
}
void sub_7690()
{
    if (memory16(ds, 0x4200) != 0x0000)
        return;
    ax = memory16(ds, 0x4f92);
    if (ax == 0x0000)
        return;
    sub_57f1();
    di += memory16(ds, 0x0018);
    ax = 0x006b;
    dx = memory16(ds, 0x001c);
    dx &= 0x0008;
    if (dx == 0x0000)
        goto loc_76b8;
    ax = 0x0085;
loc_76b8:
    sub_273a();
}
void sub_76bc()
{
    bx = 0x0726;
    cx = 0x01b8;
loc_76c2:
    ah = memory(ds, bx);
    si = 0x4fa0;
loc_76c9:
    lodsb<MemData, DirForward>();
    if (al == 0xff)
        goto loc_76d7;
    if (ah != al)
        goto loc_76c9;
    memory(ds, bx) = 0x2a;
loc_76d7:
    bx++;
    if (--cx)
        goto loc_76c2;
}
void sub_76db()
{
    if (memory16(ds, 0x4f8a) == 0x0008)
        goto loc_76ff;
    sub_697c();
    memory16(ds, 0x4200) = 0x0000;
    cx = 0x0008;
loc_76ee:
    push(cx);
    sub_71c6();
    cx = 0x0001;
    dx = 0x0008;
    sub_6908();
    cx = pop();
    if (--cx)
        goto loc_76ee;
    return;
loc_76ff:
    memory16(ds, 0x3c66) = 0xffff;
    memory16(ds, 0x3c68) = 0x0000;
}
void sub_770c()
{
    if (memory16(ds, 0x3a50) < 0xfa00)
        goto loc_771a;
    memory16(ds, 0x3a50) = 0xfa00;
loc_771a:
    ax = memory16(ds, 0x3a50);
    if (memory16(ds, 0x4f90) >= ax)
        goto loc_7726;
    memory16(ds, 0x4f90) = ax;
loc_7726:
    if (memory(ds, 0x4f95) == 0xff)
        goto loc_773f;
    if (memory16(ds, 0x4f80) == ax)
        goto loc_7748;
    memory16(ds, 0x4f80) = ax;
    memory(ds, 0x4f95) = 0xff;
    goto loc_7745;
loc_773f:
    memory(ds, 0x4f95) = 0x00;
loc_7745:
    sub_521e();
loc_7748:
    if (memory(ds, 0x4f96) == 0xff)
        goto loc_7761;
    if (memory16(ds, 0x4f84) == ax)
        goto loc_776a;
    memory16(ds, 0x4f84) = ax;
    memory(ds, 0x4f96) = 0xff;
    goto loc_7767;
loc_7761:
    memory(ds, 0x4f96) = 0x00;
loc_7767:
    sub_5264();
loc_776a:
    ax = memory16(ds, 0x37d0);
    if (ax == memory16(ds, 0x4f7e))
        goto loc_7789;
    if (memory16(ds, 0x4f7e) == 0xffff)
        goto loc_7783;
    memory16(ds, 0x4f7e) = 0xffff;
    goto loc_7786;
loc_7783:
    memory16(ds, 0x4f7e) = ax;
loc_7786:
    sub_52aa();
loc_7789:
    ax = memory16(ds, 0x4f8c);
    if (ax == memory16(ds, 0x4f82))
        return;
    if (memory16(ds, 0x4f82) == 0xffff)
        goto loc_77a2;
    memory16(ds, 0x4f82) = 0xffff;
    goto loc_77a5;
loc_77a2:
    memory16(ds, 0x4f82) = ax;
loc_77a5:
    sub_5300();
}
void sub_77a9()
{
    si = 0x4f9a;
    if (memory16(ds, 0x4200) != 0x0000)
        goto loc_77be;
    ax = memory16(ds, 0x001c);
    if (!(ax & 0x0004))
        goto loc_77be;
    si += 0x0003;
loc_77be:
    al = 0x21;
    cx = 0x0001;
    sub_2397();
}
void sub_77c8()
{
    ax += ax;
    bx = 0x56bc;
    bx += ax;
    si = memory16(ds, bx);
    push(si);
    push(ds);
    cx = 0xd6d8;
    dx = si;
    dx += 0x0008;
    bx = 0x0000;
    ax = 0x25f0;
    ds = ax;
    sub_78e1();
    ds = pop();
    si = pop();
    push(ds);
    di = memory16(ds, si + 6);
    ax = memory16(ds, si + 4);
    es = ax;
    cx = memory16(ds, si + 2);
    push(si);
    sub_23ec();
    si = pop();
    ds = pop();
    bx = memory16(ds, si);
    if (bx == 0xffff)
        goto loc_780c;
    sub_783b();
    return;
loc_780c:
    sub_7810();
}
void sub_7810()
{
    si = 0x0008;
    cx = 0x000a;
loc_7816:
    push(cx);
    cx = 0x0014;
loc_781a:
    push(cx);
    push(si);
    bx = 0x56b0;
    memory16(ds, bx) = si;
    memory16(ds, bx + 2) = 0x335d;
    sub_783b();
    si = pop();
    cx = pop();
    si += 0x0010;
    if (--cx)
        goto loc_781a;
    cx = pop();
    si += 0x1540;
    if (--cx)
        goto loc_7816;
}
void sub_783b()
{
    push(ds);
    si = bx;
loc_783e:
    lodsw<MemData, DirForward>();
    if (ax == 0xffff)
        goto loc_7868;
    memory16(ds, 0x56aa) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, 0x56ac) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, 0x56ae) = ax;
    lodsw<MemData, DirForward>();
    if (ax == 0xffff)
        goto loc_786a;
    push(si);
    cx = ax;
loc_7858:
    push(cx);
    sub_7891();
    memory16(ds, 0x56aa) = memory16(ds, 0x56aa) + 0x0140;
    cx = pop();
    if (--cx)
        goto loc_7858;
    si = pop();
    goto loc_783e;
loc_7868:
    ds = pop();
    return;
loc_786a:
    push(si);
    bx = 0x56b0;
    ax = memory16(ds, 0x56aa);
    memory16(ds, bx) = ax;
    ax = memory16(ds, 0x56ac);
    memory16(ds, bx + 2) = ax;
    cx = 0x0014;
loc_787f:
    push(cx);
    bx = 0x56b0;
    sub_783b();
    memory16(ds, 0x56b0) = memory16(ds, 0x56b0) + 0x0010;
    cx = pop();
    if (--cx)
        goto loc_787f;
    si = pop();
    goto loc_783e;
}
void sub_7891()
{
    ax = memory16(ds, 0x56aa);
    di = ax;
    ax = memory16(ds, 0x56ac);
    es = ax;
    cx = memory16(ds, 0x56ae);
    dx = cx;
    push(ds);
    push(si);
    ax = 0x0b52;
    ds = ax;
    si = 0x16c2;
    bx = 0x0000;
    cx <<= 1;
loc_78b0:
    ax = memory16(es, bx + di);
    memory16(ds, bx + si) = ax;
    bx += 0x0002;
    if (--cx)
        goto loc_78b0;
    dx = memory16(ds, 0x56ae);
    cx = dx;
    bx = 0x0000;
loc_78c3:
    push(bx);
    lodsb<MemData, DirForward>();
    memory(es, bx + di) = al;
    bx += dx;
    lodsb<MemData, DirForward>();
    memory(es, bx + di) = al;
    bx += dx;
    lodsb<MemData, DirForward>();
    memory(es, bx + di) = al;
    bx += dx;
    lodsb<MemData, DirForward>();
    memory(es, bx + di) = al;
    bx = pop();
    bx++;
    if (--cx)
        goto loc_78c3;
    si = pop();
    ds = pop();
}
void sub_78e1()
{
    push(ds);
    ax = 0x0b52;
    ds = ax;
    memory(ds, 0x0021) = 0x00;
    ax = 0x3d00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_7907;
    ds = pop();
    push(ds);
    dx = bx;
    bx = ax;
    ax = 0x3f00;
    interrupt(0x21);
    if (flags.carry)
        goto loc_7907;
    ds = pop();
    ax = 0x3e00;
    interrupt(0x21);
    return;
loc_7907:
    ax = 0x0b52;
    ds = ax;
    memory(ds, 0x0021) = al;
    ds = pop();
}
void sub_7912()
{
    memory(ds, 0x6b79) = 0x00;
    memory(ds, 0x6b78) = 0x00;
    memory(ds, 0x6b77) = 0x00;
    ax = 0x0004;
    dx = 0x0012;
    sub_7a1b();
    sub_7a4e();
    ax = memory16(ds, 0x4f88);
    if (ax == 0x0001)
        goto loc_795f;
    if (ax == 0x0002)
        goto loc_7962;
    if (ax == 0x0003)
        goto loc_7965;
    if (ax == 0x0004)
        goto loc_79b2;
    if (ax == 0x0005)
        goto loc_795c;
    if (ax == 0x0006)
        goto loc_79c5;
    if (ax == 0x0007)
        goto loc_79a2;
    if (ax == 0x0008)
        goto loc_7968;
    return;
loc_795c:
    goto loc_79f5;
loc_795f:
    goto loc_79d8;
loc_7962:
    goto loc_79e8;
loc_7965:
    goto loc_7a02;
loc_7968:
    memory16(ds, 0x6b70) = 0x0004;
    memory16(ds, 0x7048) = 0xffff;
    memory16(ds, 0x6b72) = 0x005a;
    memory(ds, 0x6b79) = 0x00;
    memory(ds, 0x6b78) = 0xff;
    ax = 0x0004;
    dx = 0x0016;
    sub_7a1b();
    memory16(ds, 0x7460) = 0x0008;
    memory16(ds, 0x7462) = 0x0020;
    cx = 0x0005;
    sub_7a60();
    return;
loc_79a2:
    ax = 0x0008;
    dx = 0x001e;
    sub_7a1b();
    cx = 0x0004;
    sub_7acd();
    return;
loc_79b2:
    ax = 0x0018;
    sub_7a2f();
    cx = 0x0004;
    sub_7b2a();
    cx = 0x0001;
    sub_7b7f();
    return;
loc_79c5:
    ax = 0x0018;
    sub_7a2f();
    cx = 0x0008;
    sub_7b2a();
    cx = 0x0003;
    sub_7b7f();
    return;
loc_79d8:
    ax = 0x0012;
    sub_7a2f();
    ax = 0x0707;
    si = 0x72a4;
    sub_7c29();
    return;
loc_79e8:
    ax = 0x0012;
    sub_7a2f();
    cx = 0x0001;
    sub_7bd4();
    return;
loc_79f5:
    ax = 0x0012;
    sub_7a2f();
    cx = 0x0003;
    sub_7bd4();
    return;
loc_7a02:
    ax = 0x0012;
    sub_7a2f();
    si = 0x72a4;
    ax = 0x0707;
    sub_7c29();
    si = 0x7388;
    ax = 0x0701;
    sub_7c29();
}
void sub_7a1b()
{
    si = 0x7388;
    cx = 0x0006;
loc_7a21:
    memory16(ds, si + 26) = ax;
    memory16(ds, si + 28) = dx;
    si += 0x0026;
    if (--cx)
        goto loc_7a21;
}
void sub_7a2f()
{
    si = 0x7388;
    dx = 0x0004;
    memory16(ds, si + 140) = dx;
    memory16(ds, si + 178) = dx;
    memory16(ds, si + 216) = dx;
    memory16(ds, si + 142) = ax;
    memory16(ds, si + 180) = ax;
    memory16(ds, si + 218) = ax;
}
void sub_7a4e()
{
    si = 0x72a4;
    cx = 0x000c;
loc_7a54:
    memory16(ds, si) = 0xffff;
    si += 0x0026;
    if (--cx)
        goto loc_7a54;
}
void sub_7a60()
{
    ax = 0x71ea;
    memory16(ds, 0x704a) = ax;
    di = 0x7388;
    si = 0x702a;
loc_7a6c:
    push(cx);
    lodsw<MemData, DirForward>();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memory16(ds, di) = dx;
    memory16(ds, di + 2) = cx;
    memory16(ds, di + 10) = 0x0000;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 4) = ax;
    memory16(ds, di + 6) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, di + 12) = ax;
    ax = 0x000b;
    sub_587c();
    ah = al;
    al = 0x0a;
    memory16(ds, di + 8) = ax;
    memory16(ds, di + 14) = 0x0003;
    memory16(ds, di + 18) = 0x0000;
    memory16(ds, di + 16) = 0x0000;
    memory16(ds, di + 20) = 0x000e;
    if (memory16(ds, di + 12) != 0x0001)
        goto loc_7ac6;
    memory16(ds, di + 20) = 0x0019;
loc_7ac6:
    di += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_7a6c;
}
void sub_7acd()
{
    si = 0x72a4;
loc_7ad0:
    push(cx);
    sub_71c6();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 10) = 0x0000;
    memory16(ds, si + 12) = 0x0001;
    memory16(ds, si + 20) = 0x0019;
    memory16(ds, si + 4) = 0x6e24;
    memory16(ds, si + 6) = 0x6e24;
    ax = 0x000b;
    sub_587c();
    ah = al;
    al = 0x0a;
    memory16(ds, si + 8) = ax;
    memory16(ds, si + 14) = 0x0003;
    memory16(ds, si + 18) = 0x0000;
    memory16(ds, si + 16) = 0x0000;
    si += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_7ad0;
}
void sub_7b2a()
{
    si = 0x72a4;
loc_7b2d:
    push(cx);
    sub_71c6();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 10) = 0x0000;
    memory16(ds, si + 12) = 0x0001;
    memory16(ds, si + 20) = 0x000f;
    memory16(ds, si + 4) = 0x6cc6;
    memory16(ds, si + 6) = 0x6cc6;
    memory16(ds, si + 8) = 0x000a;
    memory16(ds, si + 14) = 0x0003;
    memory16(ds, si + 18) = 0x0000;
    memory16(ds, si + 16) = 0x0000;
    si += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_7b2d;
}
void sub_7b7f()
{
    si = 0x73fa;
loc_7b82:
    push(cx);
    sub_71c6();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 10) = 0x0000;
    memory16(ds, si + 12) = 0x0000;
    memory16(ds, si + 20) = 0x0028;
    memory16(ds, si + 4) = 0x6cf6;
    memory16(ds, si + 6) = 0x6cf6;
    memory16(ds, si + 8) = 0x000a;
    memory16(ds, si + 14) = 0x0003;
    memory16(ds, si + 18) = 0x0000;
    memory16(ds, si + 16) = 0x0000;
    si += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_7b82;
}
void sub_7bd4()
{
    si = 0x73fa;
loc_7bd7:
    push(cx);
    sub_71c6();
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 10) = 0x0000;
    memory16(ds, si + 12) = 0x0008;
    memory16(ds, si + 20) = 0x001e;
    memory16(ds, si + 4) = 0x6c92;
    memory16(ds, si + 6) = 0x6c92;
    memory16(ds, si + 8) = 0x000e;
    memory16(ds, si + 14) = 0x0083;
    memory16(ds, si + 18) = 0x0000;
    memory16(ds, si + 16) = 0x0000;
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_7bd7;
}
void sub_7c29()
{
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memory16(ds, si) = dx;
    memory16(ds, si + 2) = cx;
    memory16(ds, si + 38) = dx;
    memory16(ds, si + 40) = cx;
    memory16(ds, si + 76) = dx;
    memory16(ds, si + 78) = cx;
    memory16(ds, si + 114) = dx;
    memory16(ds, si + 116) = cx;
    memory16(ds, si + 152) = dx;
    memory16(ds, si + 154) = cx;
    memory16(ds, si + 190) = dx;
    memory16(ds, si + 192) = cx;
    memory16(ds, si + 10) = 0xffff;
    memory16(ds, si + 48) = 0xffff;
    memory16(ds, si + 86) = 0xffff;
    memory16(ds, si + 124) = 0xffff;
    memory16(ds, si + 162) = 0xffff;
    memory16(ds, si + 200) = 0xffff;
    memory16(ds, si + 12) = 0x0008;
    memory16(ds, si + 50) = 0x0008;
    memory16(ds, si + 88) = 0x0008;
    memory16(ds, si + 126) = 0x0008;
    memory16(ds, si + 164) = 0x0008;
    memory16(ds, si + 202) = 0x0008;
    memory16(ds, si + 20) = 0x0032;
    memory16(ds, si + 58) = 0x0032;
    memory16(ds, si + 96) = 0x0032;
    memory16(ds, si + 134) = 0x0032;
    memory16(ds, si + 172) = 0x0032;
    memory16(ds, si + 210) = 0x0032;
    memory16(ds, si + 4) = 0x6b7a;
    memory16(ds, si + 6) = 0x6b7a;
    memory16(ds, si + 42) = 0x6bbe;
    memory16(ds, si + 44) = 0x6bbe;
    memory16(ds, si + 80) = 0x6bbe;
    memory16(ds, si + 82) = 0x6bbe;
    memory16(ds, si + 118) = 0x6bbe;
    memory16(ds, si + 120) = 0x6bbe;
    memory16(ds, si + 156) = 0x6bbe;
    memory16(ds, si + 158) = 0x6bbe;
    memory16(ds, si + 194) = 0x6c02;
    memory16(ds, si + 196) = 0x6c02;
    memory16(ds, si + 8) = 0x0014;
    memory16(ds, si + 46) = 0x0014;
    memory16(ds, si + 84) = 0x1014;
    memory16(ds, si + 122) = 0x0414;
    memory16(ds, si + 160) = 0x0814;
    memory16(ds, si + 198) = 0x1014;
    memory16(ds, si + 14) = 0x8282;
    memory16(ds, si + 52) = 0x8282;
    memory16(ds, si + 90) = 0x8282;
    memory16(ds, si + 128) = 0x8282;
    memory16(ds, si + 166) = 0x8282;
    memory16(ds, si + 204) = 0x8282;
    memory16(ds, si + 18) = 0x0000;
    memory16(ds, si + 16) = 0x0000;
}
void sub_7d6b()
{
    ax = memory16(ds, 0x4f88);
    if (ax == 0x0001)
        goto loc_7de6;
    if (ax == 0x0002)
        goto loc_7d9d;
    if (ax == 0x0003)
        goto loc_7d9a;
    if (ax == 0x0004)
        goto loc_7dca;
    if (ax == 0x0005)
        goto loc_7d9d;
    if (ax == 0x0006)
        goto loc_7dca;
    if (ax == 0x0007)
        goto loc_7da0;
    if (ax == 0x0008)
        goto loc_7d97;
    return;
loc_7d97:
    goto loc_7e5b;
loc_7d9a:
    goto loc_7e09;
loc_7d9d:
    goto loc_7e48;
loc_7da0:
    sub_801a();
    ax = 0x0000;
    dx = memory16(ds, 0x001c);
    if (!(dx & 0x0020))
        goto loc_7db3;
    ax = 0xffff;
loc_7db3:
    memory(ds, 0x6b78) = al;
    if (al != 0x00)
        goto loc_7dc0;
    si = 0x72a4;
    sub_893b();
loc_7dc0:
    sub_80ca();
    sub_8b10();
    sub_86df();
    return;
loc_7dca:
    sub_801a();
    si = 0x72a4;
    sub_893b();
    si = 0x7388;
    sub_893b();
    sub_8211();
    sub_8309();
    sub_8b10();
    sub_86df();
    return;
loc_7de6:
    si = 0x72a4;
    sub_8877();
    si = 0x72a4;
    sub_8877();
    si = 0x72a4;
    sub_893b();
    memory(ds, 0x6b76) = dl;
    si = 0x72a4;
    sub_8758();
    sub_8b10();
    sub_86df();
    return;
loc_7e09:
    si = 0x72a4;
    sub_8877();
    si = 0x72a4;
    sub_8877();
    si = 0x7388;
    sub_8877();
    si = 0x7388;
    sub_8877();
    si = 0x72a4;
    sub_893b();
    memory(ds, 0x6b76) = dl;
    si = 0x72a4;
    sub_8758();
    si = 0x7388;
    sub_893b();
    memory(ds, 0x6b76) = dl;
    si = 0x7388;
    sub_8758();
    sub_8b10();
    sub_86df();
    return;
loc_7e48:
    sub_85ad();
    si = 0x7388;
    sub_893b();
    sub_80ca();
    sub_8b10();
    sub_86df();
    return;
loc_7e5b:
    if (memory16(ds, 0x6b70) != 0x0000)
        goto loc_7e6e;
    ax = memory16(ds, 0x001c);
    if (ax & 0x001f)
        goto loc_7e6e;
    memory(ds, 0x6b78) = ~memory(ds, 0x6b78);
loc_7e6e:
    sub_801a();
    sub_801a();
    sub_8428();
    si = 0x7388;
    sub_893b();
    sub_86df();
    sub_7fd3();
    memory16(ds, 0x6b72) = memory16(ds, 0x6b72) - 1;
    if (memory16(ds, 0x6b72) == 0x0000)
        goto loc_7efe;
    if (memory16(ds, 0x7048) != 0xffff)
        goto loc_7e96;
    return;
loc_7e96:
    di = 0x73ae;
    si = 0x4d50;
    bx = memory16(ds, 0x7048);
    cx = 0x0004;
loc_7ea3:
    push(cx);
    push(bx);
    push(si);
    push(di);
    dx = memory16(ds, di);
    if (dx == 0xffff)
        goto loc_7ecd;
    cx = memory16(ds, di + 2);
    cx -= 0x0006;
    si += 0x0014;
    ax = memory16(ds, bx);
    memory16(ds, si) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 2) = ax;
    sub_2782();
loc_7ecd:
    di = pop();
    si = pop();
    bx = pop();
    cx = pop();
    di += 0x0026;
    si += 0x0024;
    if (--cx)
        goto loc_7ea3;
    ax = memory16(ds, 0x001c);
    if (ax & 0x0001)
        goto loc_7efd;
    memory16(ds, 0x7048) = memory16(ds, 0x7048) + 0x0004;
    bx = memory16(ds, 0x7048);
    if (memory16(ds, bx) != 0xffff)
        goto loc_7efd;
    memory16(ds, 0x7048) = 0xffff;
    memory(ds, 0x6b79) = 0x00;
loc_7efd:
    return;
loc_7efe:
    if (memory(ds, 0x6b79) == 0x00)
        goto loc_7f50;
    memory16(ds, 0x6b72) = 0x00b4;
    di = 0x4d50;
    si = 0x73ae;
    cx = 0x0004;
loc_7f14:
    ax = memory16(ds, di);
    if (ax == 0xffff)
        goto loc_7f2c;
    memory16(ds, di) = 0xffff;
    ax -= 0x0008;
    ax &= 0xfff0;
    ax += 0x0008;
loc_7f2c:
    memory16(ds, si) = ax;
    ax = memory16(ds, di + 2);
    ax -= 0x0018;
    ax &= 0xfff0;
    ax += 0x0018;
    memory16(ds, si + 2) = ax;
    di += 0x0024;
    si += 0x0026;
    if (--cx)
        goto loc_7f14;
    memory16(ds, 0x7048) = 0x71c4;
    return;
loc_7f50:
    memory16(ds, 0x6b72) = 0x00b4;
    memory(ds, 0x6b79) = 0xff;
    si = 0x73ae;
    di = 0x4d50;
    cx = 0x0004;
loc_7f65:
    if (memory16(ds, si) == 0xffff)
        goto loc_7fca;
    if ((short)memory16(ds, si + 12) < 0)
        goto loc_7fca;
    ax = memory16(ds, si);
    if (ax == 0xffff)
        goto loc_7f85;
    ax -= 0x0008;
    ax &= 0xfff0;
    ax += 0x0008;
loc_7f85:
    memory16(ds, di) = ax;
    ax = memory16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0xfff0;
    ax += 0x0018;
    memory16(ds, di + 2) = ax;
    memory16(ds, di + 4) = 0x7182;
    memory16(ds, di + 6) = 0x70f2;
    memory16(ds, di + 10) = 0xffc0;
    memory16(ds, di + 12) = 0x0017;
    memory16(ds, di + 14) = 0x008f;
    memory16(ds, di + 16) = 0x0000;
    memory16(ds, di + 8) = 0x000a;
    memory16(ds, di + 26) = 0x0016;
loc_7fca:
    si += 0x0026;
    di += 0x0024;
    if (--cx)
        goto loc_7f65;
}
void sub_7fd3()
{
    if (memory(ds, 0x6b79) == 0x00)
        return;
    push(si);
    si = 0x4d50;
    cx = 0x0004;
loc_7fe1:
    push(cx);
    if (memory16(ds, si) == 0xffff)
        goto loc_8012;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    di = 0x3cde;
    cx = 0x0008;
loc_7ffa:
    if (memory16(ds, di + 8) != ax)
        goto loc_800d;
    if ((short)memory16(ds, di + 2) < 0)
        goto loc_800d;
    memory16(ds, di + 6) = 0xffff;
loc_800d:
    di += 0x0016;
    if (--cx)
        goto loc_7ffa;
loc_8012:
    si += 0x0024;
    cx = pop();
    if (--cx)
        goto loc_7fe1;
    si = pop();
}
void sub_801a()
{
    si = 0x72a4;
    cx = 0x000c;
    if (memory(ds, 0x6b79) == 0x00)
        goto loc_802a;
    cx = 0x0007;
loc_802a:
    push(cx);
    if (memory16(ds, si) == 0xffff)
        goto loc_8057;
    if ((short)memory16(ds, si + 12) < 0)
        goto loc_8057;
    ax = memory16(ds, si + 10);
    ax &= 0x0001;
    if (ax == 0x0000)
        goto loc_805a;
    ax = memory16(ds, si);
    ax -= 0x0008;
    ax &= 0x000f;
    if (ax == 0x0000)
        goto loc_806b;
    goto loc_809c;
loc_8057:
    goto loc_80c0;
loc_805a:
    ax = memory16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0x000f;
    if (ax == 0x0000)
        goto loc_806b;
    goto loc_809c;
loc_806b:
    ax = 0x0064;
    sub_587c();
    if (ax > 0x0014)
        goto loc_8082;
    sub_6f9a();
    sub_6e9c();
    memory16(ds, si + 10) = ax;
    goto loc_809c;
loc_8082:
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_809c;
    memory16(ds, si + 10) = ax;
    sub_6f9a();
    sub_6e9c();
    memory16(ds, si + 10) = ax;
loc_809c:
    ax = memory16(ds, si + 10);
    if (ax == 0xffff)
        goto loc_80c0;
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x4444;
    bx += ax;
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    memory16(ds, si) = memory16(ds, si) + ax;
    memory16(ds, si + 2) = memory16(ds, si + 2) + dx;
loc_80c0:
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_80c7;
    return;
loc_80c7:
    goto loc_802a;
}
void sub_80ca()
{
    si = 0x72a4;
    cx = 0x000c;
loc_80d0:
    push(cx);
    if (memory16(ds, si) != 0xffff)
        goto loc_80db;
    goto loc_81a8;
loc_80db:
    if ((short)memory16(ds, si + 12) >= 0)
        goto loc_80e5;
    goto loc_81b2;
loc_80e5:
    bx = memory16(ds, si + 6);
    dx = memory16(ds, 0x001e);
    ax = memory16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_810f;
    ah = 0x00;
    bx += 0x0004;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_810f;
    bx = memory16(ds, si + 4);
    memory16(ds, si + 6) = bx;
loc_810f:
    memory16(ds, si + 8) = ax;
    push(si);
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    if (memory16(ds, si + 20) > 0x0010)
        goto loc_8126;
    ax += 0x0040;
loc_8126:
    if (memory16(ds, si + 20) > 0x0008)
        goto loc_8130;
    ax += 0x0040;
loc_8130:
    memory16(ds, si + 22) = ax;
    memory16(ds, si + 24) = dx;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0002;
    if (memory(ds, 0x6b78) != 0x00)
        goto loc_8163;
    if (memory16(ds, si + 18) == 0x0000)
        goto loc_8163;
    ax = memory16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_8163;
    bl = 0x69;
    si += 0x0016;
    sub_28cd();
    goto loc_81a7;
loc_8163:
    si += 0x0016;
    sub_2782();
    if (memory(ds, 0x6b78) == 0x00)
        goto loc_81a7;
    si = pop();
    push(si);
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    dx -= 0x0008;
    cx -= 0x0008;
    si += 0x0146;
    memory16(ds, si) = 0xb5c0;
    memory16(ds, si + 2) = 0x1650;
    ax = memory16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_81a4;
    memory16(ds, si) = 0xb5e0;
    memory16(ds, si + 2) = 0x1650;
loc_81a4:
    sub_2782();
loc_81a7:
    si = pop();
loc_81a8:
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_81af;
    return;
loc_81af:
    goto loc_80d0;
loc_81b2:
    memory16(ds, 0x6b6e) = si;
    if (memory16(ds, si) == 0xffff)
        goto loc_820f;
    bx = memory16(ds, si + 6);
    ax = memory16(ds, 0x001e);
    memory16(ds, si + 8) = memory16(ds, si + 8) + ax;
    if (memory16(ds, si + 8) < 0x006e)
        goto loc_81ec;
    memory16(ds, si + 8) = 0x0064;
    bx += 0x0004;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_81ec;
    memory16(ds, si) = 0xffff;
    goto loc_820f;
loc_81ec:
    push(si);
    ax = memory16(ds, bx);
    memory16(ds, si + 22) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 24) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0016;
    sub_2782();
    si = pop();
loc_820f:
    goto loc_81a8;
}
void sub_8211()
{
    si = 0x72a4;
    cx = 0x0008;
loc_8217:
    push(cx);
    if (memory16(ds, si) != 0xffff)
        goto loc_8222;
    goto loc_82a0;
loc_8222:
    if ((short)memory16(ds, si + 12) >= 0)
        goto loc_822c;
    goto loc_82aa;
loc_822c:
    bx = memory16(ds, si + 6);
    dx = memory16(ds, 0x001e);
    ax = memory16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_8256;
    ah = 0x00;
    bx += 0x0004;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_8256;
    bx = memory16(ds, si + 4);
    memory16(ds, si + 6) = bx;
loc_8256:
    memory16(ds, si + 8) = ax;
    push(si);
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    if (memory16(ds, si + 20) > 0x0007)
        goto loc_826d;
    ax += 0x0030;
loc_826d:
    memory16(ds, si + 22) = ax;
    memory16(ds, si + 24) = dx;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0002;
    if (memory16(ds, si + 18) == 0x0000)
        goto loc_8299;
    ax = memory16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_8299;
    bl = 0x69;
    si += 0x0016;
    sub_28cd();
    goto loc_829f;
loc_8299:
    si += 0x0016;
    sub_2782();
loc_829f:
    si = pop();
loc_82a0:
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_82a7;
    return;
loc_82a7:
    goto loc_8217;
loc_82aa:
    memory16(ds, 0x6b6e) = si;
    if (memory16(ds, si) == 0xffff)
        goto loc_8307;
    bx = memory16(ds, si + 6);
    ax = memory16(ds, 0x001e);
    memory16(ds, si + 8) = memory16(ds, si + 8) + ax;
    if (memory16(ds, si + 8) < 0x006e)
        goto loc_82e4;
    memory16(ds, si + 8) = 0x0064;
    bx += 0x0004;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_82e4;
    memory16(ds, si) = 0xffff;
    goto loc_8307;
loc_82e4:
    push(si);
    ax = memory16(ds, bx);
    memory16(ds, si + 22) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 24) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0016;
    sub_2782();
    si = pop();
loc_8307:
    goto loc_82a0;
}
void sub_8309()
{
    si = 0x73fa;
    cx = 0x0003;
loc_830f:
    push(cx);
    if (memory16(ds, si) != 0xffff)
        goto loc_831a;
    goto loc_83bc;
loc_831a:
    if ((short)memory16(ds, si + 12) >= 0)
        goto loc_8324;
    goto loc_83c6;
loc_8324:
    bx = memory16(ds, si + 6);
    dx = memory16(ds, 0x001e);
    ax = memory16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_834e;
    ah = 0x00;
    bx += 0x0010;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_834e;
    bx = memory16(ds, si + 4);
    memory16(ds, si + 6) = bx;
loc_834e:
    memory16(ds, si + 8) = ax;
    push(si);
    ax = memory16(ds, si + 10);
    ax &= 0x0003;
    ax += ax;
    ax += ax;
    bx += ax;
    if (memory16(ds, si + 20) > 0x001e)
        goto loc_836b;
    bx += 0x0044;
loc_836b:
    if (memory16(ds, si + 20) > 0x0014)
        goto loc_8376;
    bx += 0x0044;
loc_8376:
    if (memory16(ds, si + 20) > 0x000a)
        goto loc_8381;
    bx += 0x0044;
loc_8381:
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    memory16(ds, si + 22) = ax;
    memory16(ds, si + 24) = dx;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0008;
    if (memory16(ds, si + 18) == 0x0000)
        goto loc_83b5;
    ax = memory16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_83b5;
    bl = 0x69;
    si += 0x0016;
    sub_28cd();
    goto loc_83bb;
loc_83b5:
    si += 0x0016;
    sub_2782();
loc_83bb:
    si = pop();
loc_83bc:
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_83c3;
    return;
loc_83c3:
    goto loc_830f;
loc_83c6:
    memory16(ds, 0x6b6e) = si;
    if (memory16(ds, si) == 0xffff)
        goto loc_8426;
    bx = memory16(ds, si + 6);
    ax = memory16(ds, 0x001e);
    memory16(ds, si + 8) = memory16(ds, si + 8) + ax;
    if (memory16(ds, si + 8) < 0x006e)
        goto loc_8400;
    memory16(ds, si + 8) = 0x0064;
    bx += 0x0004;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_8400;
    memory16(ds, si) = 0xffff;
    goto loc_8426;
loc_8400:
    push(si);
    ax = memory16(ds, bx);
    memory16(ds, si + 22) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 24) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0008;
    dx -= 0x0008;
    si += 0x0016;
    sub_2782();
    si = pop();
loc_8426:
    goto loc_83bc;
}
void sub_8428()
{
    si = 0x7388;
    cx = 0x0005;
loc_842e:
    push(cx);
    if (memory(ds, 0x6b79) == 0x00)
        goto loc_8447;
    if (memory16(ds, si + 12) == 0x0001)
        goto loc_8447;
    if ((short)memory16(ds, si + 12) < 0)
        goto loc_8447;
    goto loc_851b;
loc_8447:
    if (memory16(ds, si) != 0xffff)
        goto loc_8451;
    goto loc_851b;
loc_8451:
    if ((short)memory16(ds, si + 12) >= 0)
        goto loc_845b;
    goto loc_8525;
loc_845b:
    bx = memory16(ds, si + 6);
    dx = memory16(ds, 0x001e);
    ax = memory16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_8485;
    ah = 0x00;
    bx += 0x0010;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_8485;
    bx = memory16(ds, si + 4);
    memory16(ds, si + 6) = bx;
loc_8485:
    memory16(ds, si + 8) = ax;
    push(si);
    ax = memory16(ds, si + 10);
    ax &= 0x0003;
    ax += ax;
    ax += ax;
    bx += ax;
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    memory16(ds, si + 22) = ax;
    memory16(ds, si + 24) = dx;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0006;
    if (memory16(ds, si + 18) == 0x0000)
        goto loc_84cb;
    ax = memory16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_84cb;
    bl = 0x69;
    si += 0x0016;
    sub_28cd();
    goto loc_84d1;
loc_84cb:
    si += 0x0016;
    sub_2782();
loc_84d1:
    si = pop();
    if (memory16(ds, si + 12) != 0x0001)
        goto loc_851b;
    if (memory(ds, 0x6b78) == 0x00)
        goto loc_851b;
    push(si);
    dx = memory16(ds, si);
    dx -= 0x0008;
    cx = memory16(ds, si + 2);
    cx -= 0x000a;
    di = memory16(ds, 0x704a);
    si = 0x745c;
    ax = memory16(ds, di);
    memory16(ds, si) = ax;
    ax = memory16(ds, di + 2);
    memory16(ds, si + 2) = ax;
    di += 0x0004;
    if (memory16(ds, di) != 0xffff)
        goto loc_8513;
    di = 0x71ea;
loc_8513:
    memory16(ds, 0x704a) = di;
    sub_2782();
    si = pop();
loc_851b:
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_8522;
    return;
loc_8522:
    goto loc_842e;
loc_8525:
    memory16(ds, 0x6b6e) = si;
    if (memory16(ds, si) == 0xffff)
        goto loc_85aa;
    bx = memory16(ds, si + 6);
    ax = memory16(ds, 0x001e);
    memory16(ds, si + 8) = memory16(ds, si + 8) + ax;
    if (memory16(ds, si + 8) < 0x006e)
        goto loc_857d;
    memory16(ds, si + 8) = 0x0064;
    if (memory16(ds, 0x6b70) != 0x0000)
        goto loc_8555;
    memory16(ds, si + 8) = 0x0069;
loc_8555:
    bx += 0x0004;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_857d;
    memory16(ds, 0x6b70) = memory16(ds, 0x6b70) - 1;
    if (memory16(ds, 0x6b70) != 0xffff)
        goto loc_8574;
    memory16(ds, 0x4f7c) = 0x0002;
loc_8574:
    memory16(ds, si) = 0xffff;
    goto loc_85aa;
loc_857d:
    push(si);
    ax = memory16(ds, bx);
    memory16(ds, si + 22) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 24) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    if (memory16(ds, 0x6b70) == 0x0000)
        goto loc_85a3;
    cx -= 0x0005;
    dx -= 0x0003;
loc_85a3:
    si += 0x0016;
    sub_2782();
    si = pop();
loc_85aa:
    goto loc_851b;
}
void sub_85ad()
{
    si = 0x73fa;
    cx = 0x0003;
loc_85b3:
    push(cx);
    if (memory16(ds, si) == 0xffff)
        goto loc_85e0;
    if ((short)memory16(ds, si + 12) < 0)
        goto loc_85e0;
    ax = memory16(ds, si + 10);
    ax &= 0x0001;
    if (ax == 0x0000)
        goto loc_85e3;
    ax = memory16(ds, si);
    ax -= 0x0008;
    ax &= 0x000f;
    if (ax == 0x0000)
        goto loc_85f4;
    goto loc_8636;
loc_85e0:
    goto loc_865a;
loc_85e3:
    ax = memory16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0x000f;
    if (ax == 0x0000)
        goto loc_85f4;
    goto loc_8636;
loc_85f4:
    if (memory16(ds, 0x4200) < 0x0008)
        goto loc_8612;
    ax = 0x0064;
    sub_587c();
    if (ax < 0x0014)
        goto loc_8612;
    sub_6f9a();
    sub_6e9c();
    memory16(ds, si + 10) = ax;
    goto loc_862c;
loc_8612:
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_862c;
    memory16(ds, si + 10) = ax;
    sub_6f9a();
    sub_6e9c();
    memory16(ds, si + 10) = ax;
loc_862c:
    if (memory16(ds, 0x4200) >= 0x0008)
        goto loc_8636;
    sub_8664();
loc_8636:
    ax = memory16(ds, si + 10);
    if (ax == 0xffff)
        goto loc_865a;
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x4444;
    bx += ax;
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    memory16(ds, si) = memory16(ds, si) + ax;
    memory16(ds, si + 2) = memory16(ds, si + 2) + dx;
loc_865a:
    cx = pop();
    si += 0x0026;
    if (--cx)
        goto loc_8661;
    return;
loc_8661:
    goto loc_85b3;
}
void sub_8664()
{
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    di = 0x4d50;
    cx = 0x000f;
loc_8675:
    if (memory16(ds, di) == 0xffff)
        goto loc_8684;
    di += 0x0024;
    if (--cx)
        goto loc_8675;
    return;
loc_8684:
    sub_57d2();
    dx -= 0x0008;
    cx -= 0x0008;
    memory16(ds, di) = dx;
    memory16(ds, di + 2) = cx;
    memory16(ds, di + 10) = 0xffb8;
    ax = 0x000c;
    memory16(ds, di + 12) = ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x42d4;
    bx += ax;
    ax = memory16(ds, bx);
    memory16(ds, di + 6) = ax;
    ax += 0x00c0;
    memory16(ds, di + 4) = ax;
    ax = memory16(ds, bx + 4);
    memory16(ds, di + 8) = ax;
    ax = memory16(ds, bx + 6);
    memory16(ds, di + 14) = ax;
    memory16(ds, di + 18) = 0x0000;
    memory16(ds, di + 16) = 0x0000;
    memory16(ds, 0x4200) = memory16(ds, 0x4200) + 1;
}
void sub_86df()
{
    si = 0x3c5e;
    if (memory16(ds, si) == 0xffff)
        return;
    if ((short)memory16(ds, si + 8) < 0)
        return;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    sub_581f();
    dx = ax;
    bx = 0x72a4;
    cx = 0x000c;
loc_8703:
    push(cx);
    if (memory16(ds, bx) == 0xffff)
        goto loc_8729;
    if ((short)memory16(ds, bx + 12) < 0)
        goto loc_8729;
    push(dx);
    dx = memory16(ds, bx);
    dx += 0x0008;
    cx = memory16(ds, bx + 2);
    cx += 0x0008;
    sub_581f();
    dx = pop();
    if (ax == dx)
        goto loc_8730;
loc_8729:
    bx += 0x0026;
    cx = pop();
    if (--cx)
        goto loc_8703;
    return;
loc_8730:
    cx = pop();
    if (memory16(ds, bx + 12) == 0x0001)
        goto loc_8745;
    if (memory(ds, 0x6b79) == 0x00)
        goto loc_8745;
    bx += 0x0026;
    if (--cx)
        goto loc_8703;
    return;
loc_8745:
    memory16(ds, si + 8) = 0xffff;
    memory16(ds, si + 10) = 0x0000;
    ax = 0x0000;
    sub_8ca1();
}
void sub_8758()
{
    if (memory16(ds, si) != 0xffff)
        goto loc_8762;
    goto loc_8807;
loc_8762:
    if ((short)memory16(ds, si + 12) >= 0)
        goto loc_876c;
    goto loc_880b;
loc_876c:
    si += 0x00be;
    cx = 0x0006;
loc_8773:
    push(cx);
    bx = memory16(ds, si + 6);
    dx = memory16(ds, 0x001e);
    ax = memory16(ds, si + 8);
    ah += dl;
    if (ah < al)
        goto loc_879e;
    ah = 0x00;
    bx += 0x0010;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_879e;
    bx = memory16(ds, si + 4);
    memory16(ds, si + 6) = bx;
loc_879e:
    memory16(ds, si + 8) = ax;
    push(si);
    ax = memory16(ds, si + 10);
    if ((short)ax < 0)
        goto loc_87b5;
    ax &= 0x0003;
    ax += ax;
    ax += ax;
    bx += ax;
loc_87b5:
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    if (memory16(ds, si + 20) > 0x0021)
        goto loc_87c7;
    ax += 0x2d00;
loc_87c7:
    if (memory16(ds, si + 20) > 0x0010)
        goto loc_87d1;
    ax += 0x2d00;
loc_87d1:
    memory16(ds, si + 22) = ax;
    memory16(ds, si + 24) = dx;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0016;
    if (memory(ds, 0x6b76) == 0x00)
        goto loc_87fd;
    ax = memory16(ds, 0x001c);
    if (!(ax & 0x0001))
        goto loc_87fd;
    bl = 0x69;
    sub_28cd();
    goto loc_8800;
loc_87fd:
    sub_2782();
loc_8800:
    si = pop();
    cx = pop();
    si -= 0x0026;
    if (--cx)
        goto loc_8808;
loc_8807:
    return;
loc_8808:
    goto loc_8773;
loc_880b:
    memory16(ds, 0x6b6e) = si;
    si += 0x00be;
    cx = 0x0006;
loc_8816:
    push(cx);
    if (memory16(ds, si) == 0xffff)
        goto loc_8870;
    bx = memory16(ds, si + 6);
    ax = memory16(ds, 0x001e);
    memory16(ds, si + 8) = memory16(ds, si + 8) + ax;
    if (memory16(ds, si + 8) < 0x006c)
        goto loc_884d;
    memory16(ds, si + 8) = 0x0064;
    bx += 0x0004;
    memory16(ds, si + 6) = bx;
    if (memory16(ds, bx) != 0xffff)
        goto loc_884d;
    memory16(ds, si) = 0xffff;
    goto loc_8870;
loc_884d:
    push(si);
    ax = memory16(ds, bx);
    memory16(ds, si + 22) = ax;
    ax = memory16(ds, bx + 2);
    memory16(ds, si + 24) = ax;
    dx = memory16(ds, si);
    cx = memory16(ds, si + 2);
    cx -= 0x0002;
    si += 0x0016;
    sub_2782();
    si = pop();
loc_8870:
    cx = pop();
    si -= 0x0026;
    if (--cx)
        goto loc_8816;
}
void sub_8877()
{
    if (memory16(ds, si) == 0xffff)
        goto loc_88aa;
    if ((short)memory16(ds, si + 12) < 0)
        goto loc_88aa;
    ax = memory16(ds, si + 10);
    memory16(ds, 0x6b74) = ax;
    ax = memory16(ds, si + 10);
    ax &= 0x0001;
    if (ax == 0x0000)
        goto loc_88ad;
    ax = memory16(ds, si);
    ax -= 0x0008;
    ax &= 0x000f;
    if (ax == 0x0000)
        goto loc_88be;
    goto loc_890e;
loc_88aa:
    return;
loc_88ad:
    ax = memory16(ds, si + 2);
    ax -= 0x0018;
    ax &= 0x000f;
    if (ax == 0x0000)
        goto loc_88be;
    goto loc_890e;
loc_88be:
    sub_6d9c();
    if (dx == 0x0000)
        goto loc_88e0;
    ax = memory16(ds, si + 10);
    sub_6ebe();
    if (dx == 0x0000)
        goto loc_88e0;
    memory16(ds, si + 10) = ax;
    sub_6f9a();
    sub_6e9c();
    memory16(ds, si + 10) = ax;
loc_88e0:
    if ((short)memory16(ds, si + 10) < 0)
        goto loc_890e;
    ax = memory16(ds, si + 162);
    memory16(ds, si + 200) = ax;
    ax = memory16(ds, si + 124);
    memory16(ds, si + 162) = ax;
    ax = memory16(ds, si + 86);
    memory16(ds, si + 124) = ax;
    ax = memory16(ds, si + 48);
    memory16(ds, si + 86) = ax;
    ax = memory16(ds, 0x6b74);
    memory16(ds, si + 48) = ax;
loc_890e:
    cx = 0x0006;
loc_8911:
    ax = memory16(ds, si + 10);
    if ((short)ax < 0)
        goto loc_8938;
    ax += ax;
    ax += ax;
    ax += ax;
    bx = 0x4444;
    bx += ax;
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    memory16(ds, si) = memory16(ds, si) + ax;
    memory16(ds, si + 2) = memory16(ds, si + 2) + dx;
    si += 0x0026;
loc_8938:
    if (--cx)
        goto loc_8911;
}
void sub_893b()
{
    memory16(ds, 0x6b6c) = 0x0000;
    memory16(ds, 0x6b6e) = si;
    cx = 0x0006;
loc_8948:
    dx = memory16(ds, si);
    if (dx == 0xffff)
        goto loc_8975;
    if ((short)memory16(ds, si + 12) < 0)
        goto loc_8975;
    push(cx);
    memory16(ds, si + 18) = 0x0000;
    cx = memory16(ds, si + 2);
    dx += 0x0008;
    cx += 0x0008;
    sub_581f();
    sub_6bb9();
    cx = pop();
    if (dx == 0xffff)
        goto loc_897f;
loc_8975:
    si += 0x0026;
    if (--cx)
        goto loc_8948;
    dx = memory16(ds, 0x6b6c);
    return;
loc_897f:
    if (memory16(ds, 0x4f88) != 0x0008)
        goto loc_8996;
    if (memory16(ds, si + 12) != 0x0001)
        goto loc_8996;
    if (memory(ds, 0x6b78) == 0x00)
        goto loc_899d;
    goto loc_8975;
loc_8996:
    if (memory(ds, 0x6b79) != 0x00)
        goto loc_8975;
loc_899d:
    memory16(ds, si + 18) = 0xffff;
    memory16(ds, 0x6b6c) = 0xffff;
    memory16(ds, si + 20) = memory16(ds, si + 20) - 1;
    if ((short)memory16(ds, si + 20) < 0)
        goto loc_89b6;
    goto loc_8975;
loc_89b6:
    push(si);
    ax = 0x0002;
    sub_8ca1();
    si = pop();
    ax = memory16(ds, 0x4f88);
    if (ax == 0x0001)
        goto loc_89ed;
    if (ax == 0x0002)
        goto loc_8a47;
    if (ax == 0x0003)
        goto loc_89ed;
    if (ax == 0x0004)
        goto loc_8a09;
    if (ax == 0x0005)
        goto loc_8a47;
    if (ax == 0x0006)
        goto loc_8a09;
    if (ax == 0x0007)
        goto loc_89f0;
    if (ax == 0x0008)
        goto loc_89ea;
    return;
loc_89ea:
    goto loc_8ad7;
loc_89ed:
    goto loc_8a60;
loc_89f0:
    memory16(ds, si + 12) = 0xffff;
    memory16(ds, si + 6) = 0x6e36;
    memory16(ds, si + 8) = 0x0032;
    memory16(ds, 0x3a50) = memory16(ds, 0x3a50) + 0x012c;
    return;
loc_8a09:
    if (memory16(ds, si + 12) == 0x0001)
        goto loc_8a2f;
    memory16(ds, si + 12) = 0xffff;
    memory16(ds, si + 6) = 0x6e06;
    memory16(ds, si + 8) = 0x0032;
    memory16(ds, si + 26) = 0x0008;
    memory16(ds, 0x3a50) = memory16(ds, 0x3a50) + 0x012c;
    return;
loc_8a2f:
    memory16(ds, si + 12) = 0xffff;
    memory16(ds, si + 6) = 0x6cd8;
    memory16(ds, si + 8) = 0x0032;
    memory16(ds, 0x3a50) = memory16(ds, 0x3a50) + 0x000a;
    return;
loc_8a47:
    memory16(ds, si + 12) = 0xffff;
    memory16(ds, si + 6) = 0x6ca4;
    memory16(ds, si + 8) = 0x0032;
    memory16(ds, 0x3a50) = memory16(ds, 0x3a50) + 0x00c8;
    return;
loc_8a60:
    si = memory16(ds, 0x6b6e);
    memory16(ds, si + 12) = 0xffff;
    memory16(ds, si + 50) = 0xffff;
    memory16(ds, si + 88) = 0xffff;
    memory16(ds, si + 126) = 0xffff;
    memory16(ds, si + 164) = 0xffff;
    memory16(ds, si + 202) = 0xffff;
    memory16(ds, si + 6) = 0x6c46;
    memory16(ds, si + 44) = 0x6c70;
    memory16(ds, si + 82) = 0x6c70;
    memory16(ds, si + 120) = 0x6c70;
    memory16(ds, si + 158) = 0x6c70;
    memory16(ds, si + 196) = 0x6c70;
    memory16(ds, si + 8) = 0x0032;
    memory16(ds, si + 46) = 0x003c;
    memory16(ds, si + 84) = 0x0046;
    memory16(ds, si + 122) = 0x0050;
    memory16(ds, si + 160) = 0x005a;
    memory16(ds, si + 198) = 0x0064;
    memory16(ds, 0x3a50) = memory16(ds, 0x3a50) + 0x00c8;
    return;
loc_8ad7:
    ax = memory16(ds, si + 12);
    ax--;
    ax += ax;
    bx = 0x7020;
    bx += ax;
    ax = memory16(ds, bx);
    memory16(ds, si + 6) = ax;
    memory16(ds, si + 8) = 0x0032;
    if (memory16(ds, si + 12) == 0x0001)
        goto loc_8b04;
    memory16(ds, si + 26) = 0x0006;
    memory16(ds, si + 28) = 0x0016;
loc_8b04:
    memory16(ds, si + 12) = 0xffff;
    memory16(ds, 0x3a50) = memory16(ds, 0x3a50) + 0x000a;
}
void sub_8b10()
{
    if (memory(ds, 0x6b77) != 0x00)
        return;
    if (memory16(ds, 0x4200) != 0x0000)
        return;
    si = 0x72a4;
    cx = 0x000c;
loc_8b24:
    if (memory16(ds, si) != 0xffff)
        return;
    si += 0x0026;
    if (--cx)
        goto loc_8b24;
    cx = 0x0008;
    si = 0x3cde;
loc_8b36:
    if (memory16(ds, si) != 0xffff)
        return;
    si += 0x0016;
    if (--cx)
        goto loc_8b36;
    memory(ds, 0x6b77) = 0xff;
    sub_71c6();
    push(ax);
    dl = 0x75;
    sub_57b4();
    ax = pop();
    sub_57f1();
    ax = 0x00a0;
    sub_5f24();
    di += memory16(ds, 0x0018);
    sub_273a();
    ax = 0x000a;
    sub_8c10();
}
void sub_8b6a()
{
    if (memory(ds, 0x7052) == 0x00)
        return;
    sub_9641();
}
void sub_8b75()
{
    if (memory(ds, 0x7052) == 0x00)
        return;
    sub_9634();
}
void sub_8b80()
{
    if (memory(ds, 0x7052) == 0x00)
        return;
    sub_9612();
}
void sub_8b8b()
{
    push(0x7777);
    if (memory(ds, 0x7052) == 0x00)
        goto loc_8b99;
    sub_964e();
    if (al == 0x00)
        goto loc_8b9a;
loc_8b99:
    assert(pop() == 0x7777);
    return;
loc_8b9a:
    ax = memory16(ds, 0x7050);
    es = ax;
    di = memory16(ds, 0x704e);
    di += 0x0008;
    ax = memory16(es, di);
    ax += memory16(ds, 0x704e);
    dx = memory16(ds, 0x7050);
    push(dx);
    push(ax);
    sub_95bc();
    sp += 0x0004;
    assert(pop() == 0x7777);
}
void sub_8bba()
{
    memory(ds, 0x7052) = 0x00;
    memory(ds, 0x7053) = 0x00;
    sub_92d0();
    if (al == 0x00)
        return;
    sub_91c4();
    if (al == 0x00)
        return;
    sub_956a();
    if (al == 0x00)
        return;
    sub_95e5();
    memory(ds, 0x7052) = 0xff;
    sub_9479();
    if (al == 0x00)
        goto loc_8c03;
    sub_9479();
    if (al == 0x00)
        goto loc_8c03;
    sub_9479();
    if (al == 0x00)
        goto loc_8c03;
    sub_9479();
    if (al == 0x00)
        goto loc_8c03;
    return;
loc_8c03:
    memory(ds, 0x7052) = 0xff;
    memory(ds, 0x7053) = 0xff;
}
void sub_8c10()
{
    push(0x7777);
    if (memory(ds, 0x7052) == 0x00)
        goto loc_8c1a;
    goto loc_8c1d;
loc_8c1a:
    goto loc_8ca0;
loc_8c1d:
    push(si);
    push(es);
    push(ax);
    sub_9612();
    ax = pop();
    si = 0x70a2;
    ax += ax;
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    memory16(ds, 0x704e) = ax;
    lodsw<MemData, DirForward>();
    memory16(ds, 0x7050) = ax;
    es = ax;
    di = memory16(ds, 0x704e);
    di += 0x000c;
    ax = memory16(es, di);
    tl = ah;
    ah = al;
    al = tl;
    ax >>= 1;
    push(ax);
    sub_9602();
    ax = pop();
    ax = memory16(ds, 0x7050);
    es = ax;
    di = memory16(ds, 0x704e);
    di += 0x0024;
    ax = memory16(es, di);
    push(ax);
    di = memory16(ds, 0x704e);
    di += 0x0006;
    ax = memory16(es, di);
    ax += memory16(ds, 0x704e);
    dx = memory16(ds, 0x7050);
    push(dx);
    push(ax);
    sub_95cf();
    sp += 0x0006;
    ax = memory16(ds, 0x7050);
    es = ax;
    di = memory16(ds, 0x704e);
    di += 0x0008;
    ax = memory16(es, di);
    ax += memory16(ds, 0x704e);
    dx = memory16(ds, 0x7050);
    push(dx);
    push(ax);
    sub_95bc();
    sp += 0x0004;
    if (memory(ds, 0x4f98) == 0x00)
        goto loc_8c9d;
    sub_9634();
loc_8c9d:
    es = pop();
    si = pop();
    assert(pop() == 0x7777);
    return;
loc_8ca0:
    assert(pop() == 0x7777);
}
void sub_8ca1()
{
    push(0x7777);
    if (memory(ds, 0x4f99) != 0x00)
        goto loc_8cd5;
    if (memory(ds, 0x7053) == 0x00)
        goto loc_8cd6;
    push(si);
    push(es);
    push(ax);
    sub_94d5();
    ax = pop();
    si = 0x70de;
    ax += ax;
    ax += ax;
    si += ax;
    lodsw<MemData, DirForward>();
    dx = ax;
    lodsw<MemData, DirForward>();
    es = dx;
    di = ax;
    ax += memory16(es, di + 20);
    push(es);
    push(ax);
    sub_9504();
    sp += 0x0004;
    es = pop();
    si = pop();
loc_8cd5:
    assert(pop() == 0x7777);
    return;
loc_8cd6:
    if (ax == 0x0004)
        goto loc_8cf4;
    if (ax == 0x0001)
        goto loc_8ced;
    if (ax == 0x0000)
        goto loc_8ce6;
    assert(pop() == 0x7777);
    return;
loc_8ce6:
    push(si);
    si = 0x7068;
    goto loc_8cf8;
loc_8ced:
    push(si);
    si = 0x707e;
    goto loc_8cf8;
loc_8cf4:
    push(si);
    si = 0x708e;
loc_8cf8:
    al = 0xb6;
    out(0x43, al);
    lodsw<MemData, DirForward>();
    out(0x42, al);
    al = ah;
    out(0x42, al);
    in(al, 0x61);
    al |= 0x03;
    out(0x61, al);
    memory16(ds, 0x704c) = si;
    si = pop();
    assert(pop() == 0x7777);
}
void sub_8d0f()
{
    if (memory(ds, 0x7052) == 0x00)
        goto loc_8d19;
    sub_9668();
loc_8d19:
    if (memory(ds, 0x7053) == 0x00)
        goto loc_8d23;
    sub_94de();
loc_8d23:
    in(al, 0x61);
    al &= 0xfc;
    out(0x61, al);
}
void sub_8d2a()
{
    if (memory(ds, 0x7052) == 0x00)
        goto loc_8d4b;
    push(ds);
    ax = 0x529d;
    ds = ax;
    cx = 0xaf13;
    dx = 0x7054;
    bx = 0x0008;
    sub_78e1();
    ds = pop();
    if (memory(ds, 0x0021) != 0x00)
        goto loc_8d4c;
loc_8d4b:
    return;
loc_8d4c:
    sub_8d0f();
    memory(ds, 0x7053) = 0x00;
    memory(ds, 0x7052) = 0x00;
}
void sub_8d5c()
{
    if (memory(ds, 0x7053) == 0x00)
        goto loc_8d7d;
    push(ds);
    ax = 0x5d88;
    ds = ax;
    cx = 0xfe49;
    dx = 0x705e;
    bx = 0x0008;
    sub_78e1();
    ds = pop();
    if (memory(ds, 0x0021) != 0x00)
        goto loc_8d7e;
loc_8d7d:
    return;
loc_8d7e:
    sub_8d0f();
    memory(ds, 0x7053) = 0x00;
    memory(ds, 0x7052) = 0x00;
}
void sub_8d8e()
{
    ax = 0x0013;
    sub_77c8();
    ax = 0x0012;
    sub_77c8();
    di = 0x34bc;
    push(ds);
    sub_23d3();
    ds = pop();
    al = 0x00;
    sub_2888();
    memory16(ds, 0x26f2) = 0x0002;
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x20;
    out(dx, al);
    memory16(ds, 0x203e) = 0x0114;
    ax = memory16(ds, 0x001a);
    sub_305b();
    ax = 0x00c7;
    di = 0x2940;
    sub_2c81();
    ax = 0x00c8;
    di = 0x5b40;
    sub_2c81();
    memory16(ds, 0x746c) = 0x0000;
    memory16(ds, 0x746e) = 0x0094;
    memory16(ds, 0x7474) = 0xffff;
    memory16(ds, 0x7476) = 0xffff;
    memory16(ds, 0x747a) = 0x0000;
    memory(ds, 0x747c) = 0x00;
    ax = 0x7620;
    memory16(ds, 0x7478) = ax;
    sub_9043();
    sub_2318();
    sub_9043();
    ax = 0x000e;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x08de;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0911;
    cx = 0x0015;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
loc_8e55:
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_281e();
    sub_9043();
    sub_350c();
    sub_544d();
    if (dx != 0x0000)
        goto loc_8eac;
    if (memory(ds, 0x747c) != 0x00)
        goto loc_8eac;
    memory16(ds, 0x747a) = memory16(ds, 0x747a) + 1;
    if (memory16(ds, 0x747a) != 0x00ea)
        goto loc_8eaa;
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x08de;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    di = 0x08de;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x08de;
    sub_23b5();
loc_8eaa:
    goto loc_8e55;
loc_8eac:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x08de;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
}
void sub_8ed2()
{
    ax = 0x0013;
    sub_77c8();
    ax = 0x0011;
    sub_77c8();
    di = 0x34bc;
    push(ds);
    sub_23d3();
    ds = pop();
    al = 0x00;
    sub_2888();
    memory16(ds, 0x26f2) = 0x0001;
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x40;
    out(dx, al);
    memory16(ds, 0x203e) = 0x0100;
    ax = memory16(ds, 0x001a);
    sub_305b();
    memory16(ds, 0x746c) = 0x0058;
    memory16(ds, 0x746e) = 0x0000;
    memory16(ds, 0x7474) = 0xffff;
    memory16(ds, 0x7476) = 0xffff;
    memory16(ds, 0x747a) = 0x0000;
    memory(ds, 0x747c) = 0x00;
    ax = 0x86e8;
    memory16(ds, 0x7478) = ax;
    ax = 0x00c6;
    di = 0x1420;
    sub_2c81();
    sub_9043();
    sub_2318();
    sub_9043();
    ax = 0x0009;
    sub_8c10();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x34bc;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x34bc;
    sub_23b5();
loc_8f6d:
    sub_2318();
    ax = memory16(ds, 0x001a);
    sub_305b();
    sub_34f3();
    sub_281e();
    sub_9043();
    sub_350c();
    sub_8b8b();
    sub_544d();
    if (dx != 0x0000)
        goto loc_8f96;
    if (memory(ds, 0x747c) != 0x00)
        goto loc_8f96;
    goto loc_8f6d;
loc_8f96:
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
    sub_2318();
    sub_281e();
    sub_2318();
    sub_281e();
    memory16(ds, 0x37c6) = 0xe2b0;
    memory16(ds, 0x37c8) = 0x1650;
    ax = 0x0008;
    sub_77c8();
    di = 0x34bc;
    push(ds);
    sub_23d3();
    ds = pop();
    al = 0x00;
    sub_2888();
    memory16(ds, 0x26f2) = 0x0002;
    dx = 0x03d4;
    al = 0x13;
    out(dx, al);
    dx = 0x03d5;
    al = 0x20;
    out(dx, al);
    memory16(ds, 0x203e) = 0x0080;
    ax = memory16(ds, 0x001a);
    sub_305b();
    push(cx);
    cx = ds;
    es = cx;
    di = 0x0bde;
    cx = 0x0300;
    al = 0x00;
    rep_stosb<MemData, DirForward>();
    cx = pop();
    di = 0x34bc;
    si = 0x0bde;
    sub_233a();
    sub_34f3();
    bx = 0x34bc;
    sub_23b5();
    si = 0x90f8;
    sub_4ef1();
    cx = 0x00b4;
    sub_5429();
    sub_5444();
    push(cx);
    push(si);
    cx = ds;
    es = cx;
    si = 0x34bc;
    di = 0x0bde;
    cx = 0x0300;
    rep_movsb<MemData, MemData, DirForward>();
    si = pop();
    cx = pop();
    si = 0x0bde;
    sub_236a();
}
void sub_9043()
{
    si = memory16(ds, 0x7478);
    memory16(ds, 0x7472) = si;
loc_904b:
    lodsw<MemData, DirForward>();
    if (ax == 0xfffc)
        goto loc_90ae;
    if (ax == 0xfffd)
        goto loc_9080;
    if (ax == 0xfffe)
        goto loc_90d0;
    if (ax == 0xffff)
        goto loc_9075;
    dx = ax;
    dx += memory16(ds, 0x746c);
    lodsw<MemData, DirForward>();
    cx = ax;
    cx += memory16(ds, 0x746e);
    lodsw<MemData, DirForward>();
    push(si);
    sub_276b();
    si = pop();
    goto loc_904b;
loc_9075:
    ax = memory16(ds, 0x7470);
    memory16(ds, 0x7472) = ax;
    memory16(ds, 0x7478) = si;
    return;
loc_9080:
    ax = memory16(ds, 0x7474);
    if (ax == 0x0000)
        goto loc_90a3;
    if (ax == 0xffff)
        goto loc_9090;
    goto loc_9097;
loc_9090:
    ax = memory16(ds, si + 2);
    memory16(ds, 0x7474) = ax;
loc_9097:
    ax = memory16(ds, si);
    memory16(ds, 0x7478) = ax;
    memory16(ds, 0x7474) = memory16(ds, 0x7474) - 1;
    return;
loc_90a3:
    si += 0x0004;
    memory16(ds, 0x7474) = 0xffff;
    goto loc_9075;
loc_90ae:
    ax = memory16(ds, 0x7476);
    if (ax == 0x0000)
        goto loc_90d7;
    if (ax == 0xffff)
        goto loc_90be;
    goto loc_90c5;
loc_90be:
    ax = memory16(ds, si);
    memory16(ds, 0x7476) = ax;
loc_90c5:
    ax = memory16(ds, 0x7472);
    memory16(ds, 0x7478) = ax;
    memory16(ds, 0x7476) = memory16(ds, 0x7476) - 1;
    return;
loc_90d0:
    memory(ds, 0x747c) = 0xff;
    return;
loc_90d7:
    si += 0x0002;
    memory16(ds, 0x7476) = 0xffff;
    goto loc_9075;
}
void sub_90e2()
{
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    push(cx);
    push(dx);
    dx = memory16(ds, 0x0012);
    dl += 0x0e;
    cx = 0x0200;
loc_90f6:
    in(al, dx);
    if (al & 0x80)
        goto loc_9100;
    if (--cx)
        goto loc_90f6;
    flags.carry = true;
    goto loc_9105;
loc_9100:
    dl -= 0x04;
    in(al, dx);
    flags.carry = false;
loc_9105:
    dx = pop();
    cx = pop();
    ds = pop();
}
void sub_9109()
{
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    push(cx);
    push(dx);
    dx = memory16(ds, 0x0012);
    dl += 0x0c;
    cx = 0x0200;
    ah = al;
loc_911f:
    in(al, dx);
    if (!(al & 0x80))
        goto loc_9129;
    if (--cx)
        goto loc_911f;
    flags.carry = true;
    goto loc_912d;
loc_9129:
    al = ah;
    out(dx, al);
    flags.carry = false;
loc_912d:
    dx = pop();
    cx = pop();
    ds = pop();
}
void sub_914f()
{
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    push(dx);
    dx = memory16(ds, 0x0012);
    dx += 0x000c;
    ah = al;
loc_9161:
    in(al, dx);
    if (!(al & 0x80))
        goto loc_9168;
    goto loc_9161;
loc_9168:
    al = ah;
    out(dx, al);
    dx = pop();
    ds = pop();
}
void sub_916e()
{
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(ds);
    bx <<= 1;
    bx <<= 1;
    flags.interrupts = false;
    push(ax);
    ax = 0;
    ds = ax;
    ax = pop();
    memory16(ds, bx) = ax;
    memory16(ds, bx + 2) = dx;
    ds = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
}
void sub_9183()
{
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(ds);
    bx <<= 1;
    bx <<= 1;
    flags.interrupts = false;
    ax = 0;
    ds = ax;
    ax = memory16(ds, bx);
    dx = memory16(ds, bx + 2);
    ds = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
}
void sub_91c4()
{
    push(0x7777);
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    push(bp);
    sp -= 0x0012;
    bp = sp;
    bx = 0x000a;
    sub_9183();
    memory16(ss, bp + 2) = ax;
    memory16(ss, bp + 4) = dx;
    bx = 0x000a;
    ax = 0x73d9;
    dx = cs;
    sub_916e();
    bx = 0x000b;
    sub_9183();
    memory16(ss, bp + 6) = ax;
    memory16(ss, bp + 8) = dx;
    bx = 0x000b;
    ax = 0x73bb;
    dx = cs;
    sub_916e();
    bx = 0x000d;
    sub_9183();
    memory16(ss, bp + 10) = ax;
    memory16(ss, bp + 12) = dx;
    bx = 0x000d;
    ax = 0x73e6;
    dx = cs;
    sub_916e();
    bx = 0x000f;
    sub_9183();
    memory16(ss, bp + 14) = ax;
    memory16(ss, bp + 16) = dx;
    bx = 0x000f;
    ax = 0x73f3;
    dx = cs;
    sub_916e();
    in(al, 0x21);
    memory(ds, 0x000c) = al;
    al &= 0x53;
    out(0x21, al);
    ax = 0;
    memory16(ds, 0x0014) = ax;
    al = 0xf2;
    sub_914f();
    ax = 0;
    cx = ax;
loc_9245:
    if (memory16(ds, 0x0014) != ax)
        goto loc_924d;
    if (--cx)
        goto loc_9245;
loc_924d:
    al = memory(ds, 0x000c);
    out(0x21, al);
    bx = 0x000f;
    ax = memory16(ss, bp + 14);
    dx = memory16(ss, bp + 16);
    sub_916e();
    bx = 0x000d;
    ax = memory16(ss, bp + 10);
    dx = memory16(ss, bp + 12);
    sub_916e();
    bx = 0x000b;
    ax = memory16(ss, bp + 6);
    dx = memory16(ss, bp + 8);
    sub_916e();
    bx = 0x000a;
    ax = memory16(ss, bp + 2);
    dx = memory16(ss, bp + 4);
    sub_916e();
    ax = memory16(ds, 0x0014);
    sp += 0x0012;
    bp = pop();
    ds = pop();
    assert(pop() == 0x7777);
}
void sub_92d0()
{
    push(ds);
    ax = 0x0b51;
    ds = ax;
    push(si);
    si = 0x0220;
loc_92da:
    memory16(ds, 0x0012) = si;
    sub_92fa();
    if (ax)
        goto loc_92f7;
    si += 0x0010;
    if (si <= 0x0260)
        goto loc_92da;
    memory16(ds, 0x0012) = 0x0210;
    sub_92fa();
loc_92f7:
    si = pop();
    ds = pop();
}
void sub_92fa()
{
    push(ds);
    push(ax);
    ax = 0x0b51;
    ds = ax;
    ax = pop();
    bx = 0;
    dx = memory16(ds, 0x0012);
    dl += 0x06;
    al = 0xc6;
    out(dx, al);
    al = 0;
    dl += 0x04;
    out(dx, al);
    in(al, dx);
    if (al != 0xc6)
        goto loc_932f;
    dl -= 0x04;
    al = 0x39;
    out(dx, al);
    al = 0;
    dl += 0x04;
    out(dx, al);
    in(al, dx);
    if (al != 0x39)
        goto loc_932f;
    bx = 0x0001;
    goto loc_9353;
loc_932f:
    sub_953a();
    if (flags.carry)
        goto loc_9353;
    al = 0xe0;
    sub_9109();
    if (flags.carry)
        goto loc_9353;
    al = 0xc6;
    sub_9109();
    if (flags.carry)
        goto loc_9353;
    sub_90e2();
    if (flags.carry)
        goto loc_9353;
    if (al != 0x39)
        goto loc_9353;
    bx = 0x0004;
    push(bx);
    sub_93b3();
    bx = pop();
loc_9353:
    ax = 0x0100;
    sub_9430();
    ax = 0x0460;
    sub_9430();
    ax = 0x0480;
    sub_9430();
    al = 0x00;
    sub_9392();
    if (flags.carry)
        goto loc_938e;
    ax = 0x02ff;
    sub_9430();
    ax = 0x0421;
    sub_9430();
    al = 0xc0;
    sub_9392();
    if (flags.carry)
        goto loc_938e;
    ax = 0x0460;
    sub_9430();
    ax = 0x0480;
    sub_9430();
    bx += 0x0002;
loc_938e:
    ax = bx;
    ds = pop();
}
void sub_9392()
{
    push(cx);
    push(dx);
    cx = 0x0040;
    ah = al;
    ah &= 0xe0;
    dx = memory16(ds, 0x0012);
    dl += 0x08;
loc_93a3:
    in(al, dx);
    al &= 0xe0;
    if (ah == al)
        goto loc_93af;
    if (--cx)
        goto loc_93a3;
    flags.carry = true;
    goto loc_93b0;
loc_93af:
    flags.carry = false;
loc_93b0:
    dx = pop();
    cx = pop();
}
void sub_93b3()
{
    push(0x7777);
    push(bp);
    sp -= 0x0004;
    bp = sp;
    bx = 0x0008;
    sub_9183();
    memory16(ss, bp) = ax;
    memory16(ss, bp + 2) = dx;
    flags.interrupts = false;
    in(al, 0x21);
    memory16(ds, 0x0016) = ax;
    al = 0xfe;
    out(0x21, al);
    ax = 0x1b58;
    sub_9459();
    bx = 0x0008;
    dx = cs;
    ax = 0x7596;
    sub_916e();
    ax = 0;
    cx = 0;
    flags.interrupts = true;
loc_93e5:
    if (!ax)
        goto loc_93e5;
loc_93e9:
    if (ax)
        goto loc_93e9;
loc_93ed:
    cx++;
    if (!ax)
        goto loc_93ed;
    flags.interrupts = false;
    ax = memory16(ds, 0x0016);
    out(0x21, al);
    ax = 0xffff;
    sub_9459();
    flags.interrupts = true;
    bx = 0x0008;
    dx = memory16(ss, bp + 2);
    ax = memory16(ss, bp);
    sub_916e();
    ax = cx;
    cx <<= 1;
    cx <<= 1;
    cx <<= 1;
    ax += cx;
    cl = 0x0a;
    ax >>= cl;
    memory16(ds, 0x0016) = ax;
    cx = ax;
    ax <<= 1;
    cx += ax;
    ax <<= 1;
    cx += ax;
    memory16(ds, 0x0018) = cx;
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_9430()
{
    push(ax);
    push(cx);
    push(dx);
    dx = memory16(ds, 0x0012);
    dl += 0x08;
    tl = al;
    al = ah;
    ah = tl;
    out(dx, al);
    cx = memory16(ds, 0x0016);
loc_9441:
    cx--;
    if (cx)
        goto loc_9441;
    dx++;
    al = ah;
    out(dx, al);
    cx = memory16(ds, 0x0018);
loc_944f:
    cx--;
    if (cx)
        goto loc_944f;
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_9459()
{
    push(ax);
    al = 0x36;
    out(0x43, al);
    ax = pop();
    out(0x40, al);
    al = ah;
    out(0x40, al);
}
void sub_9479()
{
    push(ds);
    ax = 0x0b51;
    ds = ax;
    bx = 0x0001;
    ax = memory16(ds, 0x0012);
    push(cs);
    cs = 0x096b;
    sub_96b0();
    assert(cs == 0x01ed);
    bx = 0x0002;
    ax = memory16(ds, 0x0014);
    push(cs);
    cs = 0x096b;
    sub_96b0();
    assert(cs == 0x01ed);
    bx = 0x0003;
    push(cs);
    cs = 0x096b;
    sub_96b0();
    assert(cs == 0x01ed);
    push(es);
    ax = 0x0b51;
    es = ax;
    di = 0x000e;
    bx = 0x0005;
    push(cs);
    cs = 0x096b;
    sub_96b0();
    assert(cs == 0x01ed);
    es = pop();
    ds = pop();
}
void sub_94d5()
{
    bx = 0x0008;
    push(cs);
    cs = 0x096b;
    sub_96b0();
    assert(cs == 0x01ed);
}
void sub_94de()
{
    bx = 0x0009;
    push(cs);
    cs = 0x096b;
    sub_96b0();
    assert(cs == 0x01ed);
}
void sub_9504()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(es);
    push(di);
    bx = 0x0006;
    di = memory16(ss, bp + 4);
    es = memory16(ss, bp + 4 + 2);
    push(cs);
    cs = 0x096b;
    sub_96b0();
    assert(cs == 0x01ed);
    di = pop();
    es = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_953a()
{
    push(ds);
    ax = 0x0b51;
    ds = ax;
    dx = memory16(ds, 0x0012);
    dl += 0x06;
    al = 0x01;
    out(dx, al);
    al = 0;
loc_954c:
    al--;
    if (al != 0)
        goto loc_954c;
    out(dx, al);
    cx = 0x0020;
loc_9554:
    sub_90e2();
    if (flags.carry)
        goto loc_9561;
    if (al != 0xaa)
        goto loc_9561;
    flags.carry = ax < ax;
    ax = 0;
    goto loc_9567;
loc_9561:
    if (--cx)
        goto loc_9554;
    flags.carry = true;
    ax = 0x0001;
loc_9567:
    ds = pop();
}
void sub_956a()
{
    push(ds);
    ax = 0x0b51;
    ds = ax;
    ax = memory16(ds, 0x0012);
    bx = 0xfffd;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    bx = 0xffff;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    if (flags.carry)
        goto loc_95a1;
    dx = 0x0b51;
    ax = 0x0010;
    bx = 0x0001;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    memory16(cs, 0x76d7) = dx;
    memory16(cs, 0x76d5) = ax;
    ax = 0x0001;
    goto loc_95a3;
loc_95a1:
    ax = 0;
loc_95a3:
    ds = pop();
}
void sub_95bc()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memory16(ss, bp + 6);
    ax = memory16(ss, bp + 4);
    bx = 0x0006;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_95cf()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memory16(ss, bp + 6);
    ax = memory16(ss, bp + 4);
    cx = memory16(ss, bp + 8);
    bx = 0x0002;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_95e5()
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = 0x0008;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_9602()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memory16(ss, bp + 4);
    bx = 0x0004;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_9612()
{
    bx = 0x0007;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
}
void sub_9634()
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = 0x0009;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_9641()
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = 0x000a;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_964e()
{
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(ds);
    ax = 0x0b51;
    ds = ax;
    ax = 0;
    flags.interrupts = false;
    if (memory(ds, 0x0010) == 0x00)
        goto loc_9665;
    al = 0xff;
    tl = memory(ds, 0x0010);
    memory(ds, 0x0010) = al;
    al = tl;
loc_9665:
    ds = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
}
void sub_9668()
{
    bx = 0xfffe;
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
    bx = 0x0001;
    dx = memory16(cs, 0x76d7);
    ax = memory16(cs, 0x76d5);
    push(cs);
    cs = 0x0a07;
    sub_a070();
    assert(cs == 0x01ed);
}
void sub_96b0()
{
    push(0x7777);
    goto loc_9e04;
    //   gap of 1873 bytes
loc_9e04:
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(ds);
    push(es);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(bp);
    bp = sp;
    push(ax);
    ax = cs;
    ds = ax;
    es = ax;
    ax = pop();
    flags.direction = false;
    if (bx >= 0x000e)
        goto loc_9e35;
    if (bx < 0x0004)
        goto loc_9e2a;
    if (memory(ds, 0x00b1) == 0x00)
        goto loc_9e35;
loc_9e2a:
    bx <<= 1;
    callIndirect(cs, memory16(ds, bx + 133));
    memory16(ss, bp + 12) = ax;
    goto loc_9e3a;
loc_9e35:
    memory16(ss, bp + 12) = 0xffff;
loc_9e3a:
    bp = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    es = pop();
    ds = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_a070()
{
    push(0x7777);
    goto loc_b17f;
    //   gap of 4364 bytes
loc_b17f:
    push(ds);
    push(es);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(si);
    push(bp);
    bp = sp;
    ax = cs;
    ds = ax;
    es = ax;
    ax = memory16(ss, bp + 12);
    flags.carry = memory(ds, 0x01e4) < 0x00;
    if (memory(ds, 0x01e4) != 0x00)
        goto loc_b1ce;
    memory(ds, 0x01e4) = 0x01;
    flags.interrupts = true;
    flags.direction = false;
    memory16(ss, bp + 12) = 0xffff;
    if (bx & 0x8000)
        goto loc_b1b7;
    flags.carry = bx < 0x000f;
    if (bx >= 0x000f)
        goto loc_b1c7;
    bx <<= 1;
    callIndirect(cs, memory16(ds, bx + 609));
    goto loc_b1c4;
loc_b1b7:
    bx = ~bx;
    flags.carry = bx < 0x0003;
    if (bx >= 0x0003)
        goto loc_b1c7;
    bx <<= 1;
    callIndirect(cs, memory16(ds, bx + 639));
loc_b1c4:
    memory16(ss, bp + 12) = ax;
loc_b1c7:
    memory(ds, 0x01e4) = 0x00;
    goto loc_b1d3;
loc_b1ce:
    memory16(ss, bp + 12) = 0xfff8;
loc_b1d3:
    bp = pop();
    si = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    es = pop();
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
