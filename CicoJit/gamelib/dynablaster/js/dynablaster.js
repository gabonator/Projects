function* start() {
    headerSize = 0x26d0;
    loadAddress = 0x01ed;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x1490;
    sp = 0x1c00;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/dynablaster/dos", "DYNA.EXE", 93440);
    fixReloc(cs);
    yield* sub_1ed0();
}
function fixReloc(seg) {
    memory16set(0x0000 + seg, 0x0001, memory16get(0x0000 + seg, 0x0001) + seg);
    memory16set(0x002c + seg, 0x000c, memory16get(0x002c + seg, 0x000c) + seg);
    memory16set(0x004e + seg, 0x000d, memory16get(0x004e + seg, 0x000d) + seg);
    memory16set(0x0050 + seg, 0x0004, memory16get(0x0050 + seg, 0x0004) + seg);
    memory16set(0x0050 + seg, 0x000c, memory16get(0x0050 + seg, 0x000c) + seg);
    memory16set(0x0051 + seg, 0x000d, memory16get(0x0051 + seg, 0x000d) + seg);
    memory16set(0x0054 + seg, 0x0008, memory16get(0x0054 + seg, 0x0008) + seg);
    memory16set(0x0057 + seg, 0x0009, memory16get(0x0057 + seg, 0x0009) + seg);
    memory16set(0x00ba + seg, 0x000f, memory16get(0x00ba + seg, 0x000f) + seg);
    memory16set(0x00bc + seg, 0x0006, memory16get(0x00bc + seg, 0x0006) + seg);
    memory16set(0x00bd + seg, 0x000e, memory16get(0x00bd + seg, 0x000e) + seg);
    memory16set(0x00bf + seg, 0x0005, memory16get(0x00bf + seg, 0x0005) + seg);
    memory16set(0x00d9 + seg, 0x000c, memory16get(0x00d9 + seg, 0x000c) + seg);
    memory16set(0x0135 + seg, 0x000e, memory16get(0x0135 + seg, 0x000e) + seg);
    memory16set(0x013f + seg, 0x0002, memory16get(0x013f + seg, 0x0002) + seg);
    memory16set(0x013f + seg, 0x000b, memory16get(0x013f + seg, 0x000b) + seg);
    memory16set(0x0140 + seg, 0x0001, memory16get(0x0140 + seg, 0x0001) + seg);
    memory16set(0x0141 + seg, 0x0009, memory16get(0x0141 + seg, 0x0009) + seg);
    memory16set(0x014e + seg, 0x0000, memory16get(0x014e + seg, 0x0000) + seg);
    memory16set(0x014e + seg, 0x0009, memory16get(0x014e + seg, 0x0009) + seg);
    memory16set(0x014e + seg, 0x000f, memory16get(0x014e + seg, 0x000f) + seg);
    memory16set(0x0157 + seg, 0x0004, memory16get(0x0157 + seg, 0x0004) + seg);
    memory16set(0x0159 + seg, 0x0002, memory16get(0x0159 + seg, 0x0002) + seg);
    memory16set(0x015a + seg, 0x000e, memory16get(0x015a + seg, 0x000e) + seg);
    memory16set(0x015b + seg, 0x000b, memory16get(0x015b + seg, 0x000b) + seg);
    memory16set(0x015c + seg, 0x0008, memory16get(0x015c + seg, 0x0008) + seg);
    memory16set(0x015f + seg, 0x0005, memory16get(0x015f + seg, 0x0005) + seg);
    memory16set(0x0160 + seg, 0x0008, memory16get(0x0160 + seg, 0x0008) + seg);
    memory16set(0x0162 + seg, 0x0005, memory16get(0x0162 + seg, 0x0005) + seg);
    memory16set(0x0218 + seg, 0x000c, memory16get(0x0218 + seg, 0x000c) + seg);
    memory16set(0x0219 + seg, 0x0008, memory16get(0x0219 + seg, 0x0008) + seg);
    memory16set(0x0245 + seg, 0x0006, memory16get(0x0245 + seg, 0x0006) + seg);
    memory16set(0x0246 + seg, 0x0002, memory16get(0x0246 + seg, 0x0002) + seg);
    memory16set(0x024d + seg, 0x0001, memory16get(0x024d + seg, 0x0001) + seg);
    memory16set(0x024e + seg, 0x000e, memory16get(0x024e + seg, 0x000e) + seg);
    memory16set(0x0250 + seg, 0x000b, memory16get(0x0250 + seg, 0x000b) + seg);
    memory16set(0x02c3 + seg, 0x0005, memory16get(0x02c3 + seg, 0x0005) + seg);
    memory16set(0x02f8 + seg, 0x0008, memory16get(0x02f8 + seg, 0x0008) + seg);
    memory16set(0x02fa + seg, 0x0002, memory16get(0x02fa + seg, 0x0002) + seg);
    memory16set(0x02fd + seg, 0x000a, memory16get(0x02fd + seg, 0x000a) + seg);
    memory16set(0x0353 + seg, 0x0003, memory16get(0x0353 + seg, 0x0003) + seg);
    memory16set(0x039f + seg, 0x0000, memory16get(0x039f + seg, 0x0000) + seg);
    memory16set(0x03a0 + seg, 0x0009, memory16get(0x03a0 + seg, 0x0009) + seg);
    memory16set(0x03a0 + seg, 0x000e, memory16get(0x03a0 + seg, 0x000e) + seg);
    memory16set(0x03d0 + seg, 0x0002, memory16get(0x03d0 + seg, 0x0002) + seg);
    memory16set(0x03d3 + seg, 0x000d, memory16get(0x03d3 + seg, 0x000d) + seg);
    memory16set(0x0573 + seg, 0x0008, memory16get(0x0573 + seg, 0x0008) + seg);
    memory16set(0x0579 + seg, 0x0003, memory16get(0x0579 + seg, 0x0003) + seg);
    memory16set(0x057a + seg, 0x0003, memory16get(0x057a + seg, 0x0003) + seg);
    memory16set(0x057a + seg, 0x000e, memory16get(0x057a + seg, 0x000e) + seg);
    memory16set(0x0591 + seg, 0x0001, memory16get(0x0591 + seg, 0x0001) + seg);
    memory16set(0x0595 + seg, 0x0006, memory16get(0x0595 + seg, 0x0006) + seg);
    memory16set(0x059d + seg, 0x0004, memory16get(0x059d + seg, 0x0004) + seg);
    memory16set(0x05a1 + seg, 0x0003, memory16get(0x05a1 + seg, 0x0003) + seg);
    memory16set(0x05a3 + seg, 0x0008, memory16get(0x05a3 + seg, 0x0008) + seg);
    memory16set(0x062b + seg, 0x000d, memory16get(0x062b + seg, 0x000d) + seg);
    memory16set(0x062d + seg, 0x0001, memory16get(0x062d + seg, 0x0001) + seg);
    memory16set(0x06e6 + seg, 0x0003, memory16get(0x06e6 + seg, 0x0003) + seg);
    memory16set(0x06e9 + seg, 0x0005, memory16get(0x06e9 + seg, 0x0005) + seg);
    memory16set(0x070f + seg, 0x0005, memory16get(0x070f + seg, 0x0005) + seg);
    memory16set(0x0721 + seg, 0x0005, memory16get(0x0721 + seg, 0x0005) + seg);
    memory16set(0x0723 + seg, 0x000c, memory16get(0x0723 + seg, 0x000c) + seg);
    memory16set(0x0726 + seg, 0x0004, memory16get(0x0726 + seg, 0x0004) + seg);
    memory16set(0x0728 + seg, 0x0002, memory16get(0x0728 + seg, 0x0002) + seg);
    memory16set(0x072f + seg, 0x0007, memory16get(0x072f + seg, 0x0007) + seg);
    memory16set(0x073b + seg, 0x000f, memory16get(0x073b + seg, 0x000f) + seg);
    memory16set(0x073d + seg, 0x000d, memory16get(0x073d + seg, 0x000d) + seg);
    memory16set(0x073e + seg, 0x000a, memory16get(0x073e + seg, 0x000a) + seg);
    memory16set(0x073f + seg, 0x0007, memory16get(0x073f + seg, 0x0007) + seg);
    memory16set(0x0740 + seg, 0x0002, memory16get(0x0740 + seg, 0x0002) + seg);
    memory16set(0x0742 + seg, 0x000d, memory16get(0x0742 + seg, 0x000d) + seg);
    memory16set(0x075a + seg, 0x0006, memory16get(0x075a + seg, 0x0006) + seg);
    memory16set(0x075a + seg, 0x000b, memory16get(0x075a + seg, 0x000b) + seg);
    memory16set(0x075b + seg, 0x0008, memory16get(0x075b + seg, 0x0008) + seg);
    memory16set(0x075c + seg, 0x0003, memory16get(0x075c + seg, 0x0003) + seg);
    memory16set(0x075c + seg, 0x000b, memory16get(0x075c + seg, 0x000b) + seg);
    memory16set(0x075c + seg, 0x000f, memory16get(0x075c + seg, 0x000f) + seg);
    memory16set(0x075d + seg, 0x000c, memory16get(0x075d + seg, 0x000c) + seg);
    memory16set(0x075e + seg, 0x000d, memory16get(0x075e + seg, 0x000d) + seg);
    memory16set(0x075f + seg, 0x000f, memory16get(0x075f + seg, 0x000f) + seg);
    memory16set(0x0760 + seg, 0x000b, memory16get(0x0760 + seg, 0x000b) + seg);
    memory16set(0x0761 + seg, 0x0004, memory16get(0x0761 + seg, 0x0004) + seg);
    memory16set(0x0762 + seg, 0x000e, memory16get(0x0762 + seg, 0x000e) + seg);
    memory16set(0x0764 + seg, 0x0002, memory16get(0x0764 + seg, 0x0002) + seg);
    memory16set(0x0764 + seg, 0x000e, memory16get(0x0764 + seg, 0x000e) + seg);
    memory16set(0x0765 + seg, 0x0007, memory16get(0x0765 + seg, 0x0007) + seg);
    memory16set(0x0766 + seg, 0x0006, memory16get(0x0766 + seg, 0x0006) + seg);
    memory16set(0x0766 + seg, 0x000c, memory16get(0x0766 + seg, 0x000c) + seg);
    memory16set(0x0769 + seg, 0x000c, memory16get(0x0769 + seg, 0x000c) + seg);
    memory16set(0x076a + seg, 0x0009, memory16get(0x076a + seg, 0x0009) + seg);
    memory16set(0x076b + seg, 0x0001, memory16get(0x076b + seg, 0x0001) + seg);
    memory16set(0x076b + seg, 0x0006, memory16get(0x076b + seg, 0x0006) + seg);
    memory16set(0x076c + seg, 0x0001, memory16get(0x076c + seg, 0x0001) + seg);
    memory16set(0x076e + seg, 0x0008, memory16get(0x076e + seg, 0x0008) + seg);
    memory16set(0x076f + seg, 0x000b, memory16get(0x076f + seg, 0x000b) + seg);
    memory16set(0x0771 + seg, 0x0001, memory16get(0x0771 + seg, 0x0001) + seg);
    memory16set(0x0771 + seg, 0x000e, memory16get(0x0771 + seg, 0x000e) + seg);
    memory16set(0x0772 + seg, 0x000e, memory16get(0x0772 + seg, 0x000e) + seg);
    memory16set(0x0773 + seg, 0x000e, memory16get(0x0773 + seg, 0x000e) + seg);
    memory16set(0x0774 + seg, 0x0008, memory16get(0x0774 + seg, 0x0008) + seg);
    memory16set(0x0775 + seg, 0x0001, memory16get(0x0775 + seg, 0x0001) + seg);
    memory16set(0x0776 + seg, 0x0000, memory16get(0x0776 + seg, 0x0000) + seg);
    memory16set(0x0776 + seg, 0x000d, memory16get(0x0776 + seg, 0x000d) + seg);
    memory16set(0x0777 + seg, 0x000a, memory16get(0x0777 + seg, 0x000a) + seg);
    memory16set(0x0778 + seg, 0x0001, memory16get(0x0778 + seg, 0x0001) + seg);
    memory16set(0x0779 + seg, 0x000e, memory16get(0x0779 + seg, 0x000e) + seg);
    memory16set(0x077a + seg, 0x000f, memory16get(0x077a + seg, 0x000f) + seg);
    memory16set(0x077b + seg, 0x0008, memory16get(0x077b + seg, 0x0008) + seg);
    memory16set(0x077c + seg, 0x0002, memory16get(0x077c + seg, 0x0002) + seg);
    memory16set(0x077d + seg, 0x000b, memory16get(0x077d + seg, 0x000b) + seg);
    memory16set(0x0a53 + seg, 0x0004, memory16get(0x0a53 + seg, 0x0004) + seg);
    memory16set(0x0a53 + seg, 0x000c, memory16get(0x0a53 + seg, 0x000c) + seg);
    memory16set(0x0a54 + seg, 0x0004, memory16get(0x0a54 + seg, 0x0004) + seg);
    memory16set(0x0a54 + seg, 0x000c, memory16get(0x0a54 + seg, 0x000c) + seg);
    memory16set(0x0a55 + seg, 0x0004, memory16get(0x0a55 + seg, 0x0004) + seg);
    memory16set(0x0a55 + seg, 0x000c, memory16get(0x0a55 + seg, 0x000c) + seg);
    memory16set(0x0a56 + seg, 0x0004, memory16get(0x0a56 + seg, 0x0004) + seg);
    memory16set(0x0a56 + seg, 0x000c, memory16get(0x0a56 + seg, 0x000c) + seg);
    memory16set(0x0a57 + seg, 0x0004, memory16get(0x0a57 + seg, 0x0004) + seg);
    memory16set(0x0a57 + seg, 0x000c, memory16get(0x0a57 + seg, 0x000c) + seg);
    memory16set(0x0a58 + seg, 0x0004, memory16get(0x0a58 + seg, 0x0004) + seg);
    memory16set(0x0a58 + seg, 0x000c, memory16get(0x0a58 + seg, 0x000c) + seg);
    memory16set(0x0a59 + seg, 0x0004, memory16get(0x0a59 + seg, 0x0004) + seg);
    memory16set(0x0a59 + seg, 0x000c, memory16get(0x0a59 + seg, 0x000c) + seg);
    memory16set(0x0a5a + seg, 0x0004, memory16get(0x0a5a + seg, 0x0004) + seg);
    memory16set(0x0a5a + seg, 0x000c, memory16get(0x0a5a + seg, 0x000c) + seg);
    memory16set(0x0a5b + seg, 0x0004, memory16get(0x0a5b + seg, 0x0004) + seg);
    memory16set(0x0a5b + seg, 0x000c, memory16get(0x0a5b + seg, 0x000c) + seg);
    memory16set(0x0a5c + seg, 0x0004, memory16get(0x0a5c + seg, 0x0004) + seg);
    memory16set(0x0a5c + seg, 0x000c, memory16get(0x0a5c + seg, 0x000c) + seg);
    memory16set(0x0a5d + seg, 0x0004, memory16get(0x0a5d + seg, 0x0004) + seg);
    memory16set(0x0a5d + seg, 0x000c, memory16get(0x0a5d + seg, 0x000c) + seg);
    memory16set(0x0a5e + seg, 0x0004, memory16get(0x0a5e + seg, 0x0004) + seg);
    memory16set(0x0a5e + seg, 0x000c, memory16get(0x0a5e + seg, 0x000c) + seg);
    memory16set(0x0a5f + seg, 0x0004, memory16get(0x0a5f + seg, 0x0004) + seg);
    memory16set(0x0a5f + seg, 0x000c, memory16get(0x0a5f + seg, 0x000c) + seg);
    memory16set(0x0a60 + seg, 0x0004, memory16get(0x0a60 + seg, 0x0004) + seg);
    memory16set(0x0a60 + seg, 0x000c, memory16get(0x0a60 + seg, 0x000c) + seg);
    memory16set(0x0a61 + seg, 0x0004, memory16get(0x0a61 + seg, 0x0004) + seg);
    memory16set(0x0a61 + seg, 0x000c, memory16get(0x0a61 + seg, 0x000c) + seg);
    memory16set(0x0a62 + seg, 0x0004, memory16get(0x0a62 + seg, 0x0004) + seg);
    memory16set(0x0a62 + seg, 0x000c, memory16get(0x0a62 + seg, 0x000c) + seg);
    memory16set(0x0a63 + seg, 0x0004, memory16get(0x0a63 + seg, 0x0004) + seg);
    memory16set(0x0a63 + seg, 0x000c, memory16get(0x0a63 + seg, 0x000c) + seg);
    memory16set(0x0a64 + seg, 0x0004, memory16get(0x0a64 + seg, 0x0004) + seg);
    memory16set(0x0a64 + seg, 0x000c, memory16get(0x0a64 + seg, 0x000c) + seg);
    memory16set(0x0a65 + seg, 0x0004, memory16get(0x0a65 + seg, 0x0004) + seg);
    memory16set(0x0a65 + seg, 0x000c, memory16get(0x0a65 + seg, 0x000c) + seg);
    memory16set(0x0a66 + seg, 0x0004, memory16get(0x0a66 + seg, 0x0004) + seg);
    memory16set(0x0a66 + seg, 0x000c, memory16get(0x0a66 + seg, 0x000c) + seg);
    memory16set(0x0a67 + seg, 0x0004, memory16get(0x0a67 + seg, 0x0004) + seg);
    memory16set(0x0a67 + seg, 0x000c, memory16get(0x0a67 + seg, 0x000c) + seg);
    memory16set(0x0a68 + seg, 0x0004, memory16get(0x0a68 + seg, 0x0004) + seg);
    memory16set(0x0a68 + seg, 0x000c, memory16get(0x0a68 + seg, 0x000c) + seg);
    memory16set(0x0a69 + seg, 0x0004, memory16get(0x0a69 + seg, 0x0004) + seg);
    memory16set(0x0a69 + seg, 0x000c, memory16get(0x0a69 + seg, 0x000c) + seg);
    memory16set(0x0a6a + seg, 0x0004, memory16get(0x0a6a + seg, 0x0004) + seg);
    memory16set(0x0a6a + seg, 0x000c, memory16get(0x0a6a + seg, 0x000c) + seg);
    memory16set(0x0a6b + seg, 0x0004, memory16get(0x0a6b + seg, 0x0004) + seg);
    memory16set(0x0a6b + seg, 0x000c, memory16get(0x0a6b + seg, 0x000c) + seg);
    memory16set(0x0a6c + seg, 0x0004, memory16get(0x0a6c + seg, 0x0004) + seg);
    memory16set(0x0a6c + seg, 0x000c, memory16get(0x0a6c + seg, 0x000c) + seg);
    memory16set(0x0a6d + seg, 0x0004, memory16get(0x0a6d + seg, 0x0004) + seg);
    memory16set(0x0a6d + seg, 0x000c, memory16get(0x0a6d + seg, 0x000c) + seg);
    memory16set(0x0a6e + seg, 0x0004, memory16get(0x0a6e + seg, 0x0004) + seg);
    memory16set(0x0a6e + seg, 0x000c, memory16get(0x0a6e + seg, 0x000c) + seg);
    memory16set(0x0a6f + seg, 0x0004, memory16get(0x0a6f + seg, 0x0004) + seg);
    memory16set(0x0a6f + seg, 0x000c, memory16get(0x0a6f + seg, 0x000c) + seg);
    memory16set(0x0a70 + seg, 0x0004, memory16get(0x0a70 + seg, 0x0004) + seg);
    memory16set(0x0a70 + seg, 0x000c, memory16get(0x0a70 + seg, 0x000c) + seg);
    memory16set(0x0a71 + seg, 0x0004, memory16get(0x0a71 + seg, 0x0004) + seg);
    memory16set(0x0a71 + seg, 0x000c, memory16get(0x0a71 + seg, 0x000c) + seg);
    memory16set(0x0a72 + seg, 0x0004, memory16get(0x0a72 + seg, 0x0004) + seg);
    memory16set(0x0a72 + seg, 0x000c, memory16get(0x0a72 + seg, 0x000c) + seg);
    memory16set(0x0a73 + seg, 0x0004, memory16get(0x0a73 + seg, 0x0004) + seg);
    memory16set(0x0a73 + seg, 0x000c, memory16get(0x0a73 + seg, 0x000c) + seg);
    memory16set(0x0a74 + seg, 0x0004, memory16get(0x0a74 + seg, 0x0004) + seg);
    memory16set(0x0a74 + seg, 0x000c, memory16get(0x0a74 + seg, 0x000c) + seg);
    memory16set(0x0a75 + seg, 0x0004, memory16get(0x0a75 + seg, 0x0004) + seg);
    memory16set(0x0a75 + seg, 0x000c, memory16get(0x0a75 + seg, 0x000c) + seg);
    memory16set(0x0a76 + seg, 0x0004, memory16get(0x0a76 + seg, 0x0004) + seg);
    memory16set(0x0a76 + seg, 0x000c, memory16get(0x0a76 + seg, 0x000c) + seg);
    memory16set(0x0a77 + seg, 0x0004, memory16get(0x0a77 + seg, 0x0004) + seg);
    memory16set(0x0a77 + seg, 0x000c, memory16get(0x0a77 + seg, 0x000c) + seg);
    memory16set(0x0a78 + seg, 0x0004, memory16get(0x0a78 + seg, 0x0004) + seg);
    memory16set(0x0a78 + seg, 0x000c, memory16get(0x0a78 + seg, 0x000c) + seg);
    memory16set(0x0a79 + seg, 0x0004, memory16get(0x0a79 + seg, 0x0004) + seg);
    memory16set(0x0a79 + seg, 0x000c, memory16get(0x0a79 + seg, 0x000c) + seg);
    memory16set(0x0a7a + seg, 0x0004, memory16get(0x0a7a + seg, 0x0004) + seg);
    memory16set(0x0a7a + seg, 0x000c, memory16get(0x0a7a + seg, 0x000c) + seg);
    memory16set(0x0a7b + seg, 0x0004, memory16get(0x0a7b + seg, 0x0004) + seg);
    memory16set(0x0a7b + seg, 0x000c, memory16get(0x0a7b + seg, 0x000c) + seg);
    memory16set(0x0a7c + seg, 0x0004, memory16get(0x0a7c + seg, 0x0004) + seg);
    memory16set(0x0a7c + seg, 0x000c, memory16get(0x0a7c + seg, 0x000c) + seg);
    memory16set(0x0a7d + seg, 0x0004, memory16get(0x0a7d + seg, 0x0004) + seg);
    memory16set(0x0a7d + seg, 0x000c, memory16get(0x0a7d + seg, 0x000c) + seg);
    memory16set(0x0a7e + seg, 0x0004, memory16get(0x0a7e + seg, 0x0004) + seg);
    memory16set(0x0a7e + seg, 0x000c, memory16get(0x0a7e + seg, 0x000c) + seg);
    memory16set(0x0a7f + seg, 0x0004, memory16get(0x0a7f + seg, 0x0004) + seg);
    memory16set(0x0a7f + seg, 0x000c, memory16get(0x0a7f + seg, 0x000c) + seg);
    memory16set(0x0a80 + seg, 0x0004, memory16get(0x0a80 + seg, 0x0004) + seg);
    memory16set(0x0a80 + seg, 0x000c, memory16get(0x0a80 + seg, 0x000c) + seg);
    memory16set(0x0a81 + seg, 0x0004, memory16get(0x0a81 + seg, 0x0004) + seg);
    memory16set(0x0a81 + seg, 0x000c, memory16get(0x0a81 + seg, 0x000c) + seg);
    memory16set(0x0a82 + seg, 0x0004, memory16get(0x0a82 + seg, 0x0004) + seg);
    memory16set(0x0a82 + seg, 0x000c, memory16get(0x0a82 + seg, 0x000c) + seg);
    memory16set(0x0a83 + seg, 0x0004, memory16get(0x0a83 + seg, 0x0004) + seg);
    memory16set(0x0a83 + seg, 0x000c, memory16get(0x0a83 + seg, 0x000c) + seg);
    memory16set(0x0a84 + seg, 0x0004, memory16get(0x0a84 + seg, 0x0004) + seg);
    memory16set(0x0a84 + seg, 0x000c, memory16get(0x0a84 + seg, 0x000c) + seg);
    memory16set(0x0a85 + seg, 0x0004, memory16get(0x0a85 + seg, 0x0004) + seg);
    memory16set(0x0a85 + seg, 0x000c, memory16get(0x0a85 + seg, 0x000c) + seg);
    memory16set(0x0a86 + seg, 0x0004, memory16get(0x0a86 + seg, 0x0004) + seg);
    memory16set(0x0a86 + seg, 0x000c, memory16get(0x0a86 + seg, 0x000c) + seg);
    memory16set(0x0a87 + seg, 0x0004, memory16get(0x0a87 + seg, 0x0004) + seg);
    memory16set(0x0a87 + seg, 0x000c, memory16get(0x0a87 + seg, 0x000c) + seg);
    memory16set(0x0a88 + seg, 0x0004, memory16get(0x0a88 + seg, 0x0004) + seg);
    memory16set(0x0a88 + seg, 0x000c, memory16get(0x0a88 + seg, 0x000c) + seg);
    memory16set(0x0a89 + seg, 0x0004, memory16get(0x0a89 + seg, 0x0004) + seg);
    memory16set(0x0a89 + seg, 0x000c, memory16get(0x0a89 + seg, 0x000c) + seg);
    memory16set(0x0a8a + seg, 0x0004, memory16get(0x0a8a + seg, 0x0004) + seg);
    memory16set(0x0a8a + seg, 0x000c, memory16get(0x0a8a + seg, 0x000c) + seg);
    memory16set(0x0a8b + seg, 0x0004, memory16get(0x0a8b + seg, 0x0004) + seg);
    memory16set(0x0a8b + seg, 0x000c, memory16get(0x0a8b + seg, 0x000c) + seg);
    memory16set(0x0a8c + seg, 0x0004, memory16get(0x0a8c + seg, 0x0004) + seg);
    memory16set(0x0a8c + seg, 0x000c, memory16get(0x0a8c + seg, 0x000c) + seg);
    memory16set(0x0a8d + seg, 0x0004, memory16get(0x0a8d + seg, 0x0004) + seg);
    memory16set(0x0a8d + seg, 0x000c, memory16get(0x0a8d + seg, 0x000c) + seg);
    memory16set(0x0a8e + seg, 0x0004, memory16get(0x0a8e + seg, 0x0004) + seg);
    memory16set(0x0a8e + seg, 0x000c, memory16get(0x0a8e + seg, 0x000c) + seg);
    memory16set(0x0a8f + seg, 0x0004, memory16get(0x0a8f + seg, 0x0004) + seg);
    memory16set(0x0a8f + seg, 0x000c, memory16get(0x0a8f + seg, 0x000c) + seg);
    memory16set(0x0a90 + seg, 0x0004, memory16get(0x0a90 + seg, 0x0004) + seg);
    memory16set(0x0a90 + seg, 0x000c, memory16get(0x0a90 + seg, 0x000c) + seg);
    memory16set(0x0a91 + seg, 0x0004, memory16get(0x0a91 + seg, 0x0004) + seg);
    memory16set(0x0a91 + seg, 0x000c, memory16get(0x0a91 + seg, 0x000c) + seg);
    memory16set(0x0a92 + seg, 0x0004, memory16get(0x0a92 + seg, 0x0004) + seg);
    memory16set(0x0a92 + seg, 0x000c, memory16get(0x0a92 + seg, 0x000c) + seg);
    memory16set(0x0a93 + seg, 0x0004, memory16get(0x0a93 + seg, 0x0004) + seg);
    memory16set(0x0a93 + seg, 0x000c, memory16get(0x0a93 + seg, 0x000c) + seg);
    memory16set(0x0a94 + seg, 0x0004, memory16get(0x0a94 + seg, 0x0004) + seg);
    memory16set(0x0a94 + seg, 0x000c, memory16get(0x0a94 + seg, 0x000c) + seg);
    memory16set(0x0a95 + seg, 0x0004, memory16get(0x0a95 + seg, 0x0004) + seg);
    memory16set(0x0a95 + seg, 0x000c, memory16get(0x0a95 + seg, 0x000c) + seg);
    memory16set(0x0a96 + seg, 0x0004, memory16get(0x0a96 + seg, 0x0004) + seg);
    memory16set(0x0a96 + seg, 0x000c, memory16get(0x0a96 + seg, 0x000c) + seg);
    memory16set(0x0a97 + seg, 0x0004, memory16get(0x0a97 + seg, 0x0004) + seg);
    memory16set(0x0a97 + seg, 0x000c, memory16get(0x0a97 + seg, 0x000c) + seg);
    memory16set(0x0a98 + seg, 0x0004, memory16get(0x0a98 + seg, 0x0004) + seg);
    memory16set(0x0a98 + seg, 0x000c, memory16get(0x0a98 + seg, 0x000c) + seg);
    memory16set(0x0a99 + seg, 0x0004, memory16get(0x0a99 + seg, 0x0004) + seg);
    memory16set(0x0a99 + seg, 0x000c, memory16get(0x0a99 + seg, 0x000c) + seg);
    memory16set(0x0a9a + seg, 0x0004, memory16get(0x0a9a + seg, 0x0004) + seg);
    memory16set(0x0a9a + seg, 0x000c, memory16get(0x0a9a + seg, 0x000c) + seg);
    memory16set(0x0a9b + seg, 0x0004, memory16get(0x0a9b + seg, 0x0004) + seg);
    memory16set(0x0a9b + seg, 0x000c, memory16get(0x0a9b + seg, 0x000c) + seg);
    memory16set(0x0a9c + seg, 0x0004, memory16get(0x0a9c + seg, 0x0004) + seg);
    memory16set(0x0a9c + seg, 0x000c, memory16get(0x0a9c + seg, 0x000c) + seg);
    memory16set(0x0a9d + seg, 0x0004, memory16get(0x0a9d + seg, 0x0004) + seg);
    memory16set(0x0a9d + seg, 0x000c, memory16get(0x0a9d + seg, 0x000c) + seg);
    memory16set(0x0a9e + seg, 0x0004, memory16get(0x0a9e + seg, 0x0004) + seg);
    memory16set(0x0a9e + seg, 0x000c, memory16get(0x0a9e + seg, 0x000c) + seg);
    memory16set(0x0a9f + seg, 0x0004, memory16get(0x0a9f + seg, 0x0004) + seg);
    memory16set(0x0a9f + seg, 0x000c, memory16get(0x0a9f + seg, 0x000c) + seg);
    memory16set(0x0aa0 + seg, 0x0004, memory16get(0x0aa0 + seg, 0x0004) + seg);
    memory16set(0x0aa0 + seg, 0x000c, memory16get(0x0aa0 + seg, 0x000c) + seg);
    memory16set(0x0aa1 + seg, 0x0004, memory16get(0x0aa1 + seg, 0x0004) + seg);
    memory16set(0x0aa1 + seg, 0x000c, memory16get(0x0aa1 + seg, 0x000c) + seg);
    memory16set(0x0aa2 + seg, 0x0004, memory16get(0x0aa2 + seg, 0x0004) + seg);
    memory16set(0x0aa2 + seg, 0x000c, memory16get(0x0aa2 + seg, 0x000c) + seg);
    memory16set(0x0aa3 + seg, 0x0004, memory16get(0x0aa3 + seg, 0x0004) + seg);
    memory16set(0x0aa3 + seg, 0x000c, memory16get(0x0aa3 + seg, 0x000c) + seg);
    memory16set(0x0aa4 + seg, 0x0004, memory16get(0x0aa4 + seg, 0x0004) + seg);
    memory16set(0x0aa4 + seg, 0x000c, memory16get(0x0aa4 + seg, 0x000c) + seg);
    memory16set(0x0aa5 + seg, 0x0004, memory16get(0x0aa5 + seg, 0x0004) + seg);
    memory16set(0x0aa5 + seg, 0x000c, memory16get(0x0aa5 + seg, 0x000c) + seg);
    memory16set(0x0aa6 + seg, 0x0004, memory16get(0x0aa6 + seg, 0x0004) + seg);
    memory16set(0x0aa6 + seg, 0x000c, memory16get(0x0aa6 + seg, 0x000c) + seg);
    memory16set(0x0aa7 + seg, 0x0004, memory16get(0x0aa7 + seg, 0x0004) + seg);
    memory16set(0x0aa7 + seg, 0x000c, memory16get(0x0aa7 + seg, 0x000c) + seg);
    memory16set(0x0aa8 + seg, 0x0004, memory16get(0x0aa8 + seg, 0x0004) + seg);
    memory16set(0x0aa8 + seg, 0x000c, memory16get(0x0aa8 + seg, 0x000c) + seg);
    memory16set(0x0aa9 + seg, 0x0004, memory16get(0x0aa9 + seg, 0x0004) + seg);
    memory16set(0x0aa9 + seg, 0x000c, memory16get(0x0aa9 + seg, 0x000c) + seg);
    memory16set(0x0aaa + seg, 0x0004, memory16get(0x0aaa + seg, 0x0004) + seg);
    memory16set(0x0aaa + seg, 0x000c, memory16get(0x0aaa + seg, 0x000c) + seg);
    memory16set(0x0aab + seg, 0x0004, memory16get(0x0aab + seg, 0x0004) + seg);
    memory16set(0x0aab + seg, 0x000c, memory16get(0x0aab + seg, 0x000c) + seg);
    memory16set(0x0aac + seg, 0x0004, memory16get(0x0aac + seg, 0x0004) + seg);
    memory16set(0x0aac + seg, 0x000c, memory16get(0x0aac + seg, 0x000c) + seg);
    memory16set(0x0aad + seg, 0x0004, memory16get(0x0aad + seg, 0x0004) + seg);
    memory16set(0x0aad + seg, 0x000c, memory16get(0x0aad + seg, 0x000c) + seg);
    memory16set(0x0aae + seg, 0x0004, memory16get(0x0aae + seg, 0x0004) + seg);
    memory16set(0x0aae + seg, 0x000c, memory16get(0x0aae + seg, 0x000c) + seg);
    memory16set(0x0aaf + seg, 0x0004, memory16get(0x0aaf + seg, 0x0004) + seg);
    memory16set(0x0aaf + seg, 0x000c, memory16get(0x0aaf + seg, 0x000c) + seg);
    memory16set(0x0ab0 + seg, 0x0004, memory16get(0x0ab0 + seg, 0x0004) + seg);
    memory16set(0x0ab0 + seg, 0x000c, memory16get(0x0ab0 + seg, 0x000c) + seg);
    memory16set(0x0ab1 + seg, 0x0004, memory16get(0x0ab1 + seg, 0x0004) + seg);
    memory16set(0x0ab1 + seg, 0x000c, memory16get(0x0ab1 + seg, 0x000c) + seg);
    memory16set(0x0ab2 + seg, 0x0004, memory16get(0x0ab2 + seg, 0x0004) + seg);
    memory16set(0x0ab2 + seg, 0x000c, memory16get(0x0ab2 + seg, 0x000c) + seg);
    memory16set(0x0ab3 + seg, 0x0004, memory16get(0x0ab3 + seg, 0x0004) + seg);
    memory16set(0x0ab3 + seg, 0x000c, memory16get(0x0ab3 + seg, 0x000c) + seg);
    memory16set(0x0ab4 + seg, 0x0004, memory16get(0x0ab4 + seg, 0x0004) + seg);
    memory16set(0x0ab4 + seg, 0x000c, memory16get(0x0ab4 + seg, 0x000c) + seg);
    memory16set(0x0ab5 + seg, 0x0004, memory16get(0x0ab5 + seg, 0x0004) + seg);
    memory16set(0x0ab5 + seg, 0x000c, memory16get(0x0ab5 + seg, 0x000c) + seg);
    memory16set(0x0ab6 + seg, 0x0004, memory16get(0x0ab6 + seg, 0x0004) + seg);
    memory16set(0x0ab6 + seg, 0x000c, memory16get(0x0ab6 + seg, 0x000c) + seg);
    memory16set(0x0ab7 + seg, 0x0004, memory16get(0x0ab7 + seg, 0x0004) + seg);
    memory16set(0x0ab7 + seg, 0x000c, memory16get(0x0ab7 + seg, 0x000c) + seg);
    memory16set(0x0ae5 + seg, 0x000e, memory16get(0x0ae5 + seg, 0x000e) + seg);
    memory16set(0x0ae6 + seg, 0x0006, memory16get(0x0ae6 + seg, 0x0006) + seg);
    memory16set(0x0ae6 + seg, 0x000a, memory16get(0x0ae6 + seg, 0x000a) + seg);
    memory16set(0x0ae6 + seg, 0x000e, memory16get(0x0ae6 + seg, 0x000e) + seg);
    memory16set(0x0ae7 + seg, 0x0006, memory16get(0x0ae7 + seg, 0x0006) + seg);
    memory16set(0x0ae7 + seg, 0x000a, memory16get(0x0ae7 + seg, 0x000a) + seg);
    memory16set(0x0ae7 + seg, 0x000e, memory16get(0x0ae7 + seg, 0x000e) + seg);
    memory16set(0x0ae8 + seg, 0x0006, memory16get(0x0ae8 + seg, 0x0006) + seg);
    memory16set(0x0ae8 + seg, 0x000a, memory16get(0x0ae8 + seg, 0x000a) + seg);
    memory16set(0x0ae8 + seg, 0x000e, memory16get(0x0ae8 + seg, 0x000e) + seg);
    memory16set(0x0ae9 + seg, 0x0006, memory16get(0x0ae9 + seg, 0x0006) + seg);
    memory16set(0x0ae9 + seg, 0x000a, memory16get(0x0ae9 + seg, 0x000a) + seg);
    memory16set(0x0ae9 + seg, 0x000e, memory16get(0x0ae9 + seg, 0x000e) + seg);
    memory16set(0x0aea + seg, 0x0006, memory16get(0x0aea + seg, 0x0006) + seg);
    memory16set(0x0aea + seg, 0x000a, memory16get(0x0aea + seg, 0x000a) + seg);
    memory16set(0x0aea + seg, 0x000e, memory16get(0x0aea + seg, 0x000e) + seg);
    memory16set(0x0aeb + seg, 0x0006, memory16get(0x0aeb + seg, 0x0006) + seg);
    memory16set(0x0aeb + seg, 0x000a, memory16get(0x0aeb + seg, 0x000a) + seg);
    memory16set(0x0aeb + seg, 0x000e, memory16get(0x0aeb + seg, 0x000e) + seg);
    memory16set(0x0aec + seg, 0x0006, memory16get(0x0aec + seg, 0x0006) + seg);
    memory16set(0x0aec + seg, 0x000a, memory16get(0x0aec + seg, 0x000a) + seg);
    memory16set(0x0aec + seg, 0x000e, memory16get(0x0aec + seg, 0x000e) + seg);
    memory16set(0x0aed + seg, 0x0006, memory16get(0x0aed + seg, 0x0006) + seg);
    memory16set(0x0aed + seg, 0x000a, memory16get(0x0aed + seg, 0x000a) + seg);
    memory16set(0x0aed + seg, 0x000e, memory16get(0x0aed + seg, 0x000e) + seg);
    memory16set(0x0aee + seg, 0x0006, memory16get(0x0aee + seg, 0x0006) + seg);
    memory16set(0x0aee + seg, 0x000a, memory16get(0x0aee + seg, 0x000a) + seg);
    memory16set(0x0aee + seg, 0x000e, memory16get(0x0aee + seg, 0x000e) + seg);
    memory16set(0x0aef + seg, 0x0006, memory16get(0x0aef + seg, 0x0006) + seg);
    memory16set(0x0aef + seg, 0x000a, memory16get(0x0aef + seg, 0x000a) + seg);
    memory16set(0x0aef + seg, 0x000e, memory16get(0x0aef + seg, 0x000e) + seg);
    memory16set(0x0af0 + seg, 0x0006, memory16get(0x0af0 + seg, 0x0006) + seg);
    memory16set(0x0af0 + seg, 0x000a, memory16get(0x0af0 + seg, 0x000a) + seg);
    memory16set(0x0af0 + seg, 0x000e, memory16get(0x0af0 + seg, 0x000e) + seg);
    memory16set(0x0af1 + seg, 0x0006, memory16get(0x0af1 + seg, 0x0006) + seg);
    memory16set(0x0af1 + seg, 0x000a, memory16get(0x0af1 + seg, 0x000a) + seg);
    memory16set(0x0af1 + seg, 0x000e, memory16get(0x0af1 + seg, 0x000e) + seg);
    memory16set(0x0af2 + seg, 0x0006, memory16get(0x0af2 + seg, 0x0006) + seg);
    memory16set(0x0af2 + seg, 0x000a, memory16get(0x0af2 + seg, 0x000a) + seg);
    memory16set(0x0af2 + seg, 0x000e, memory16get(0x0af2 + seg, 0x000e) + seg);
    memory16set(0x0af3 + seg, 0x0006, memory16get(0x0af3 + seg, 0x0006) + seg);
    memory16set(0x0af3 + seg, 0x000a, memory16get(0x0af3 + seg, 0x000a) + seg);
    memory16set(0x0af3 + seg, 0x000e, memory16get(0x0af3 + seg, 0x000e) + seg);
    memory16set(0x0af4 + seg, 0x0006, memory16get(0x0af4 + seg, 0x0006) + seg);
    memory16set(0x0af4 + seg, 0x000a, memory16get(0x0af4 + seg, 0x000a) + seg);
    memory16set(0x0af4 + seg, 0x000e, memory16get(0x0af4 + seg, 0x000e) + seg);
    memory16set(0x0af5 + seg, 0x0006, memory16get(0x0af5 + seg, 0x0006) + seg);
    memory16set(0x0af5 + seg, 0x000a, memory16get(0x0af5 + seg, 0x000a) + seg);
    memory16set(0x0af5 + seg, 0x000e, memory16get(0x0af5 + seg, 0x000e) + seg);
    memory16set(0x0af6 + seg, 0x0006, memory16get(0x0af6 + seg, 0x0006) + seg);
    memory16set(0x0af6 + seg, 0x000a, memory16get(0x0af6 + seg, 0x000a) + seg);
    memory16set(0x0af6 + seg, 0x000e, memory16get(0x0af6 + seg, 0x000e) + seg);
    memory16set(0x0af7 + seg, 0x0006, memory16get(0x0af7 + seg, 0x0006) + seg);
    memory16set(0x0af7 + seg, 0x000a, memory16get(0x0af7 + seg, 0x000a) + seg);
    memory16set(0x0af7 + seg, 0x000e, memory16get(0x0af7 + seg, 0x000e) + seg);
    memory16set(0x0af8 + seg, 0x0006, memory16get(0x0af8 + seg, 0x0006) + seg);
    memory16set(0x0af8 + seg, 0x000a, memory16get(0x0af8 + seg, 0x000a) + seg);
    memory16set(0x0af8 + seg, 0x000e, memory16get(0x0af8 + seg, 0x000e) + seg);
    memory16set(0x0af9 + seg, 0x0006, memory16get(0x0af9 + seg, 0x0006) + seg);
    memory16set(0x0af9 + seg, 0x000a, memory16get(0x0af9 + seg, 0x000a) + seg);
    memory16set(0x0af9 + seg, 0x000e, memory16get(0x0af9 + seg, 0x000e) + seg);
    memory16set(0x0afa + seg, 0x0006, memory16get(0x0afa + seg, 0x0006) + seg);
    memory16set(0x0afa + seg, 0x000a, memory16get(0x0afa + seg, 0x000a) + seg);
    memory16set(0x0afa + seg, 0x000e, memory16get(0x0afa + seg, 0x000e) + seg);
    memory16set(0x0afb + seg, 0x0006, memory16get(0x0afb + seg, 0x0006) + seg);
    memory16set(0x0afb + seg, 0x000a, memory16get(0x0afb + seg, 0x000a) + seg);
    memory16set(0x0afb + seg, 0x000e, memory16get(0x0afb + seg, 0x000e) + seg);
    memory16set(0x0afc + seg, 0x0006, memory16get(0x0afc + seg, 0x0006) + seg);
    memory16set(0x0afc + seg, 0x000a, memory16get(0x0afc + seg, 0x000a) + seg);
    memory16set(0x0afc + seg, 0x000e, memory16get(0x0afc + seg, 0x000e) + seg);
    memory16set(0x0afd + seg, 0x0006, memory16get(0x0afd + seg, 0x0006) + seg);
    memory16set(0x0afd + seg, 0x000a, memory16get(0x0afd + seg, 0x000a) + seg);
    memory16set(0x0afd + seg, 0x000e, memory16get(0x0afd + seg, 0x000e) + seg);
    memory16set(0x0afe + seg, 0x0006, memory16get(0x0afe + seg, 0x0006) + seg);
    memory16set(0x0afe + seg, 0x000a, memory16get(0x0afe + seg, 0x000a) + seg);
    memory16set(0x0afe + seg, 0x000e, memory16get(0x0afe + seg, 0x000e) + seg);
    memory16set(0x0aff + seg, 0x0006, memory16get(0x0aff + seg, 0x0006) + seg);
    memory16set(0x0aff + seg, 0x000a, memory16get(0x0aff + seg, 0x000a) + seg);
    memory16set(0x0aff + seg, 0x000e, memory16get(0x0aff + seg, 0x000e) + seg);
    memory16set(0x0b00 + seg, 0x0006, memory16get(0x0b00 + seg, 0x0006) + seg);
    memory16set(0x0b00 + seg, 0x000a, memory16get(0x0b00 + seg, 0x000a) + seg);
    memory16set(0x0b00 + seg, 0x000e, memory16get(0x0b00 + seg, 0x000e) + seg);
    memory16set(0x0b01 + seg, 0x0006, memory16get(0x0b01 + seg, 0x0006) + seg);
    memory16set(0x0b01 + seg, 0x000a, memory16get(0x0b01 + seg, 0x000a) + seg);
    memory16set(0x0b01 + seg, 0x000e, memory16get(0x0b01 + seg, 0x000e) + seg);
    memory16set(0x0b02 + seg, 0x0006, memory16get(0x0b02 + seg, 0x0006) + seg);
    memory16set(0x0b02 + seg, 0x000a, memory16get(0x0b02 + seg, 0x000a) + seg);
    memory16set(0x0b02 + seg, 0x000e, memory16get(0x0b02 + seg, 0x000e) + seg);
    memory16set(0x0b03 + seg, 0x0006, memory16get(0x0b03 + seg, 0x0006) + seg);
    memory16set(0x0b03 + seg, 0x000a, memory16get(0x0b03 + seg, 0x000a) + seg);
    memory16set(0x0b03 + seg, 0x000e, memory16get(0x0b03 + seg, 0x000e) + seg);
    memory16set(0x0b04 + seg, 0x0006, memory16get(0x0b04 + seg, 0x0006) + seg);
    memory16set(0x0b04 + seg, 0x000a, memory16get(0x0b04 + seg, 0x000a) + seg);
    memory16set(0x0b04 + seg, 0x000e, memory16get(0x0b04 + seg, 0x000e) + seg);
    memory16set(0x0b05 + seg, 0x0006, memory16get(0x0b05 + seg, 0x0006) + seg);
    memory16set(0x0b05 + seg, 0x000a, memory16get(0x0b05 + seg, 0x000a) + seg);
    memory16set(0x0b05 + seg, 0x000e, memory16get(0x0b05 + seg, 0x000e) + seg);
    memory16set(0x0b06 + seg, 0x0006, memory16get(0x0b06 + seg, 0x0006) + seg);
    memory16set(0x0b06 + seg, 0x000a, memory16get(0x0b06 + seg, 0x000a) + seg);
    memory16set(0x0b06 + seg, 0x000e, memory16get(0x0b06 + seg, 0x000e) + seg);
    memory16set(0x0b07 + seg, 0x0006, memory16get(0x0b07 + seg, 0x0006) + seg);
    memory16set(0x0b07 + seg, 0x000a, memory16get(0x0b07 + seg, 0x000a) + seg);
    memory16set(0x0b07 + seg, 0x000e, memory16get(0x0b07 + seg, 0x000e) + seg);
    memory16set(0x0b08 + seg, 0x0006, memory16get(0x0b08 + seg, 0x0006) + seg);
    memory16set(0x0b08 + seg, 0x000a, memory16get(0x0b08 + seg, 0x000a) + seg);
    memory16set(0x0b08 + seg, 0x000e, memory16get(0x0b08 + seg, 0x000e) + seg);
    memory16set(0x0b09 + seg, 0x0006, memory16get(0x0b09 + seg, 0x0006) + seg);
    memory16set(0x0b09 + seg, 0x000a, memory16get(0x0b09 + seg, 0x000a) + seg);
    memory16set(0x0b09 + seg, 0x000e, memory16get(0x0b09 + seg, 0x000e) + seg);
    memory16set(0x0b0a + seg, 0x0006, memory16get(0x0b0a + seg, 0x0006) + seg);
    memory16set(0x0b0a + seg, 0x000a, memory16get(0x0b0a + seg, 0x000a) + seg);
    memory16set(0x0b0a + seg, 0x000e, memory16get(0x0b0a + seg, 0x000e) + seg);
    memory16set(0x0b0b + seg, 0x0006, memory16get(0x0b0b + seg, 0x0006) + seg);
    memory16set(0x0b0b + seg, 0x000a, memory16get(0x0b0b + seg, 0x000a) + seg);
    memory16set(0x0b0b + seg, 0x000e, memory16get(0x0b0b + seg, 0x000e) + seg);
    memory16set(0x0b0c + seg, 0x0006, memory16get(0x0b0c + seg, 0x0006) + seg);
    memory16set(0x0b0c + seg, 0x000a, memory16get(0x0b0c + seg, 0x000a) + seg);
    memory16set(0x0b0c + seg, 0x000e, memory16get(0x0b0c + seg, 0x000e) + seg);
    memory16set(0x0b0d + seg, 0x0006, memory16get(0x0b0d + seg, 0x0006) + seg);
    memory16set(0x0b0d + seg, 0x000a, memory16get(0x0b0d + seg, 0x000a) + seg);
    memory16set(0x0b0d + seg, 0x000e, memory16get(0x0b0d + seg, 0x000e) + seg);
    memory16set(0x0b0e + seg, 0x0006, memory16get(0x0b0e + seg, 0x0006) + seg);
    memory16set(0x0b0e + seg, 0x000a, memory16get(0x0b0e + seg, 0x000a) + seg);
    memory16set(0x0b0e + seg, 0x000e, memory16get(0x0b0e + seg, 0x000e) + seg);
    memory16set(0x0b0f + seg, 0x0006, memory16get(0x0b0f + seg, 0x0006) + seg);
    memory16set(0x0b0f + seg, 0x000a, memory16get(0x0b0f + seg, 0x000a) + seg);
    memory16set(0x0b0f + seg, 0x000e, memory16get(0x0b0f + seg, 0x000e) + seg);
    memory16set(0x0b10 + seg, 0x0006, memory16get(0x0b10 + seg, 0x0006) + seg);
    memory16set(0x0b10 + seg, 0x000a, memory16get(0x0b10 + seg, 0x000a) + seg);
    memory16set(0x0b10 + seg, 0x000e, memory16get(0x0b10 + seg, 0x000e) + seg);
    memory16set(0x0b11 + seg, 0x0006, memory16get(0x0b11 + seg, 0x0006) + seg);
    memory16set(0x0b11 + seg, 0x000a, memory16get(0x0b11 + seg, 0x000a) + seg);
    memory16set(0x0b11 + seg, 0x000e, memory16get(0x0b11 + seg, 0x000e) + seg);
    memory16set(0x0b12 + seg, 0x0006, memory16get(0x0b12 + seg, 0x0006) + seg);
    memory16set(0x0b12 + seg, 0x000a, memory16get(0x0b12 + seg, 0x000a) + seg);
    memory16set(0x0b12 + seg, 0x000e, memory16get(0x0b12 + seg, 0x000e) + seg);
    memory16set(0x0b13 + seg, 0x0006, memory16get(0x0b13 + seg, 0x0006) + seg);
    memory16set(0x0b13 + seg, 0x000a, memory16get(0x0b13 + seg, 0x000a) + seg);
    memory16set(0x0b13 + seg, 0x000e, memory16get(0x0b13 + seg, 0x000e) + seg);
    memory16set(0x0b14 + seg, 0x0006, memory16get(0x0b14 + seg, 0x0006) + seg);
    memory16set(0x0b14 + seg, 0x000a, memory16get(0x0b14 + seg, 0x000a) + seg);
    memory16set(0x0b14 + seg, 0x000e, memory16get(0x0b14 + seg, 0x000e) + seg);
    memory16set(0x0b15 + seg, 0x0006, memory16get(0x0b15 + seg, 0x0006) + seg);
    memory16set(0x0b15 + seg, 0x000a, memory16get(0x0b15 + seg, 0x000a) + seg);
    memory16set(0x0b15 + seg, 0x000e, memory16get(0x0b15 + seg, 0x000e) + seg);
    memory16set(0x0b16 + seg, 0x0006, memory16get(0x0b16 + seg, 0x0006) + seg);
    memory16set(0x0b16 + seg, 0x000a, memory16get(0x0b16 + seg, 0x000a) + seg);
    memory16set(0x0b16 + seg, 0x000e, memory16get(0x0b16 + seg, 0x000e) + seg);
    memory16set(0x0b17 + seg, 0x0006, memory16get(0x0b17 + seg, 0x0006) + seg);
    memory16set(0x0b17 + seg, 0x000a, memory16get(0x0b17 + seg, 0x000a) + seg);
    memory16set(0x0b17 + seg, 0x000e, memory16get(0x0b17 + seg, 0x000e) + seg);
    memory16set(0x0b18 + seg, 0x0006, memory16get(0x0b18 + seg, 0x0006) + seg);
    memory16set(0x0b18 + seg, 0x000a, memory16get(0x0b18 + seg, 0x000a) + seg);
    memory16set(0x0b18 + seg, 0x000e, memory16get(0x0b18 + seg, 0x000e) + seg);
    memory16set(0x0b19 + seg, 0x0006, memory16get(0x0b19 + seg, 0x0006) + seg);
    memory16set(0x0b19 + seg, 0x000a, memory16get(0x0b19 + seg, 0x000a) + seg);
    memory16set(0x0b19 + seg, 0x000e, memory16get(0x0b19 + seg, 0x000e) + seg);
    memory16set(0x0b1a + seg, 0x0006, memory16get(0x0b1a + seg, 0x0006) + seg);
    memory16set(0x0b1a + seg, 0x000a, memory16get(0x0b1a + seg, 0x000a) + seg);
    memory16set(0x0b1a + seg, 0x000e, memory16get(0x0b1a + seg, 0x000e) + seg);
    memory16set(0x0b1b + seg, 0x0006, memory16get(0x0b1b + seg, 0x0006) + seg);
    memory16set(0x0b1b + seg, 0x000a, memory16get(0x0b1b + seg, 0x000a) + seg);
    memory16set(0x0b1b + seg, 0x000e, memory16get(0x0b1b + seg, 0x000e) + seg);
    memory16set(0x0b1c + seg, 0x0006, memory16get(0x0b1c + seg, 0x0006) + seg);
    memory16set(0x0b1c + seg, 0x000a, memory16get(0x0b1c + seg, 0x000a) + seg);
    memory16set(0x0b1c + seg, 0x000e, memory16get(0x0b1c + seg, 0x000e) + seg);
    memory16set(0x0b1d + seg, 0x0006, memory16get(0x0b1d + seg, 0x0006) + seg);
    memory16set(0x0b1d + seg, 0x000a, memory16get(0x0b1d + seg, 0x000a) + seg);
    memory16set(0x0b1d + seg, 0x000e, memory16get(0x0b1d + seg, 0x000e) + seg);
    memory16set(0x0b1e + seg, 0x0006, memory16get(0x0b1e + seg, 0x0006) + seg);
    memory16set(0x0b1e + seg, 0x000a, memory16get(0x0b1e + seg, 0x000a) + seg);
    memory16set(0x0b1e + seg, 0x000e, memory16get(0x0b1e + seg, 0x000e) + seg);
    memory16set(0x0b1f + seg, 0x0006, memory16get(0x0b1f + seg, 0x0006) + seg);
    memory16set(0x0b1f + seg, 0x000a, memory16get(0x0b1f + seg, 0x000a) + seg);
    memory16set(0x0b1f + seg, 0x000e, memory16get(0x0b1f + seg, 0x000e) + seg);
    memory16set(0x0b20 + seg, 0x0006, memory16get(0x0b20 + seg, 0x0006) + seg);
    memory16set(0x0b20 + seg, 0x000a, memory16get(0x0b20 + seg, 0x000a) + seg);
    memory16set(0x0b20 + seg, 0x000e, memory16get(0x0b20 + seg, 0x000e) + seg);
    memory16set(0x0b21 + seg, 0x0006, memory16get(0x0b21 + seg, 0x0006) + seg);
    memory16set(0x0b21 + seg, 0x000a, memory16get(0x0b21 + seg, 0x000a) + seg);
    memory16set(0x0b21 + seg, 0x000e, memory16get(0x0b21 + seg, 0x000e) + seg);
    memory16set(0x0b22 + seg, 0x0006, memory16get(0x0b22 + seg, 0x0006) + seg);
    memory16set(0x0b22 + seg, 0x000a, memory16get(0x0b22 + seg, 0x000a) + seg);
    memory16set(0x0b22 + seg, 0x000e, memory16get(0x0b22 + seg, 0x000e) + seg);
    memory16set(0x0b23 + seg, 0x0006, memory16get(0x0b23 + seg, 0x0006) + seg);
    memory16set(0x0b23 + seg, 0x000a, memory16get(0x0b23 + seg, 0x000a) + seg);
    memory16set(0x0b23 + seg, 0x000e, memory16get(0x0b23 + seg, 0x000e) + seg);
    memory16set(0x0b24 + seg, 0x0006, memory16get(0x0b24 + seg, 0x0006) + seg);
    memory16set(0x0b24 + seg, 0x000a, memory16get(0x0b24 + seg, 0x000a) + seg);
    memory16set(0x0b24 + seg, 0x000e, memory16get(0x0b24 + seg, 0x000e) + seg);
    memory16set(0x0b25 + seg, 0x0006, memory16get(0x0b25 + seg, 0x0006) + seg);
    memory16set(0x0b25 + seg, 0x000a, memory16get(0x0b25 + seg, 0x000a) + seg);
    memory16set(0x0b25 + seg, 0x000e, memory16get(0x0b25 + seg, 0x000e) + seg);
    memory16set(0x0b26 + seg, 0x0006, memory16get(0x0b26 + seg, 0x0006) + seg);
    memory16set(0x0b26 + seg, 0x000a, memory16get(0x0b26 + seg, 0x000a) + seg);
    memory16set(0x0b26 + seg, 0x000e, memory16get(0x0b26 + seg, 0x000e) + seg);
    memory16set(0x0b27 + seg, 0x0006, memory16get(0x0b27 + seg, 0x0006) + seg);
    memory16set(0x0b27 + seg, 0x000a, memory16get(0x0b27 + seg, 0x000a) + seg);
    memory16set(0x0b27 + seg, 0x000e, memory16get(0x0b27 + seg, 0x000e) + seg);
    memory16set(0x0b28 + seg, 0x0006, memory16get(0x0b28 + seg, 0x0006) + seg);
    memory16set(0x0b28 + seg, 0x000a, memory16get(0x0b28 + seg, 0x000a) + seg);
    memory16set(0x0b28 + seg, 0x000e, memory16get(0x0b28 + seg, 0x000e) + seg);
    memory16set(0x0b29 + seg, 0x0006, memory16get(0x0b29 + seg, 0x0006) + seg);
    memory16set(0x0b29 + seg, 0x000a, memory16get(0x0b29 + seg, 0x000a) + seg);
    memory16set(0x0b29 + seg, 0x000e, memory16get(0x0b29 + seg, 0x000e) + seg);
    memory16set(0x0b2a + seg, 0x0006, memory16get(0x0b2a + seg, 0x0006) + seg);
    memory16set(0x0b2a + seg, 0x000a, memory16get(0x0b2a + seg, 0x000a) + seg);
    memory16set(0x0b2a + seg, 0x000e, memory16get(0x0b2a + seg, 0x000e) + seg);
    memory16set(0x0b2b + seg, 0x0006, memory16get(0x0b2b + seg, 0x0006) + seg);
    memory16set(0x0b2b + seg, 0x000a, memory16get(0x0b2b + seg, 0x000a) + seg);
    memory16set(0x0b2b + seg, 0x000e, memory16get(0x0b2b + seg, 0x000e) + seg);
    memory16set(0x0b2c + seg, 0x0006, memory16get(0x0b2c + seg, 0x0006) + seg);
    memory16set(0x0b2c + seg, 0x000a, memory16get(0x0b2c + seg, 0x000a) + seg);
    memory16set(0x0b2c + seg, 0x000e, memory16get(0x0b2c + seg, 0x000e) + seg);
    memory16set(0x0b2d + seg, 0x0006, memory16get(0x0b2d + seg, 0x0006) + seg);
    memory16set(0x0b2d + seg, 0x000a, memory16get(0x0b2d + seg, 0x000a) + seg);
    memory16set(0x0b2d + seg, 0x000e, memory16get(0x0b2d + seg, 0x000e) + seg);
    memory16set(0x0b2e + seg, 0x0006, memory16get(0x0b2e + seg, 0x0006) + seg);
    memory16set(0x0b2e + seg, 0x000a, memory16get(0x0b2e + seg, 0x000a) + seg);
    memory16set(0x0b2e + seg, 0x000e, memory16get(0x0b2e + seg, 0x000e) + seg);
    memory16set(0x0b2f + seg, 0x0006, memory16get(0x0b2f + seg, 0x0006) + seg);
    memory16set(0x0b2f + seg, 0x000a, memory16get(0x0b2f + seg, 0x000a) + seg);
    memory16set(0x0b2f + seg, 0x000e, memory16get(0x0b2f + seg, 0x000e) + seg);
    memory16set(0x0b30 + seg, 0x0006, memory16get(0x0b30 + seg, 0x0006) + seg);
    memory16set(0x0b30 + seg, 0x000a, memory16get(0x0b30 + seg, 0x000a) + seg);
    memory16set(0x0b30 + seg, 0x000e, memory16get(0x0b30 + seg, 0x000e) + seg);
    memory16set(0x0b31 + seg, 0x0006, memory16get(0x0b31 + seg, 0x0006) + seg);
    memory16set(0x0b31 + seg, 0x000a, memory16get(0x0b31 + seg, 0x000a) + seg);
    memory16set(0x0b31 + seg, 0x000e, memory16get(0x0b31 + seg, 0x000e) + seg);
    memory16set(0x0b32 + seg, 0x0006, memory16get(0x0b32 + seg, 0x0006) + seg);
    memory16set(0x0b32 + seg, 0x000a, memory16get(0x0b32 + seg, 0x000a) + seg);
    memory16set(0x0b32 + seg, 0x000e, memory16get(0x0b32 + seg, 0x000e) + seg);
    memory16set(0x0b33 + seg, 0x0006, memory16get(0x0b33 + seg, 0x0006) + seg);
    memory16set(0x0b33 + seg, 0x000a, memory16get(0x0b33 + seg, 0x000a) + seg);
    memory16set(0x0b33 + seg, 0x000e, memory16get(0x0b33 + seg, 0x000e) + seg);
    memory16set(0x0b34 + seg, 0x0006, memory16get(0x0b34 + seg, 0x0006) + seg);
    memory16set(0x0b34 + seg, 0x000a, memory16get(0x0b34 + seg, 0x000a) + seg);
    memory16set(0x0b34 + seg, 0x000e, memory16get(0x0b34 + seg, 0x000e) + seg);
    memory16set(0x0b35 + seg, 0x0006, memory16get(0x0b35 + seg, 0x0006) + seg);
    memory16set(0x0b35 + seg, 0x000a, memory16get(0x0b35 + seg, 0x000a) + seg);
    memory16set(0x0b35 + seg, 0x000e, memory16get(0x0b35 + seg, 0x000e) + seg);
    memory16set(0x0b36 + seg, 0x0006, memory16get(0x0b36 + seg, 0x0006) + seg);
    memory16set(0x0b36 + seg, 0x000a, memory16get(0x0b36 + seg, 0x000a) + seg);
    memory16set(0x0b36 + seg, 0x000e, memory16get(0x0b36 + seg, 0x000e) + seg);
    memory16set(0x0b37 + seg, 0x0006, memory16get(0x0b37 + seg, 0x0006) + seg);
    memory16set(0x0b37 + seg, 0x000a, memory16get(0x0b37 + seg, 0x000a) + seg);
    memory16set(0x0b37 + seg, 0x000e, memory16get(0x0b37 + seg, 0x000e) + seg);
    memory16set(0x0b38 + seg, 0x0006, memory16get(0x0b38 + seg, 0x0006) + seg);
    memory16set(0x0b38 + seg, 0x000a, memory16get(0x0b38 + seg, 0x000a) + seg);
    memory16set(0x0b38 + seg, 0x000e, memory16get(0x0b38 + seg, 0x000e) + seg);
    memory16set(0x0b39 + seg, 0x0006, memory16get(0x0b39 + seg, 0x0006) + seg);
    memory16set(0x0b39 + seg, 0x000a, memory16get(0x0b39 + seg, 0x000a) + seg);
    memory16set(0x0b39 + seg, 0x000e, memory16get(0x0b39 + seg, 0x000e) + seg);
    memory16set(0x0b3a + seg, 0x0006, memory16get(0x0b3a + seg, 0x0006) + seg);
    memory16set(0x0b3a + seg, 0x000a, memory16get(0x0b3a + seg, 0x000a) + seg);
    memory16set(0x0b3a + seg, 0x000e, memory16get(0x0b3a + seg, 0x000e) + seg);
    memory16set(0x0b3b + seg, 0x0006, memory16get(0x0b3b + seg, 0x0006) + seg);
    memory16set(0x0b3b + seg, 0x000a, memory16get(0x0b3b + seg, 0x000a) + seg);
    memory16set(0x0b3b + seg, 0x000e, memory16get(0x0b3b + seg, 0x000e) + seg);
    memory16set(0x0b3c + seg, 0x0006, memory16get(0x0b3c + seg, 0x0006) + seg);
    memory16set(0x0b3c + seg, 0x000a, memory16get(0x0b3c + seg, 0x000a) + seg);
    memory16set(0x0b3c + seg, 0x000e, memory16get(0x0b3c + seg, 0x000e) + seg);
    memory16set(0x0b3d + seg, 0x0006, memory16get(0x0b3d + seg, 0x0006) + seg);
    memory16set(0x0b3d + seg, 0x000a, memory16get(0x0b3d + seg, 0x000a) + seg);
    memory16set(0x0b3d + seg, 0x000e, memory16get(0x0b3d + seg, 0x000e) + seg);
    memory16set(0x0b3e + seg, 0x0006, memory16get(0x0b3e + seg, 0x0006) + seg);
    memory16set(0x0b3e + seg, 0x000a, memory16get(0x0b3e + seg, 0x000a) + seg);
    memory16set(0x0b3e + seg, 0x000e, memory16get(0x0b3e + seg, 0x000e) + seg);
    memory16set(0x0b3f + seg, 0x0006, memory16get(0x0b3f + seg, 0x0006) + seg);
    memory16set(0x0b3f + seg, 0x000a, memory16get(0x0b3f + seg, 0x000a) + seg);
    memory16set(0x0b3f + seg, 0x000e, memory16get(0x0b3f + seg, 0x000e) + seg);
    memory16set(0x0b40 + seg, 0x0006, memory16get(0x0b40 + seg, 0x0006) + seg);
    memory16set(0x0b40 + seg, 0x000a, memory16get(0x0b40 + seg, 0x000a) + seg);
    memory16set(0x0b40 + seg, 0x000e, memory16get(0x0b40 + seg, 0x000e) + seg);
    memory16set(0x0b41 + seg, 0x0006, memory16get(0x0b41 + seg, 0x0006) + seg);
    memory16set(0x0b41 + seg, 0x000a, memory16get(0x0b41 + seg, 0x000a) + seg);
    memory16set(0x0b41 + seg, 0x000e, memory16get(0x0b41 + seg, 0x000e) + seg);
    memory16set(0x0b42 + seg, 0x0006, memory16get(0x0b42 + seg, 0x0006) + seg);
    memory16set(0x0b42 + seg, 0x000a, memory16get(0x0b42 + seg, 0x000a) + seg);
    memory16set(0x0b42 + seg, 0x000e, memory16get(0x0b42 + seg, 0x000e) + seg);
    memory16set(0x0b43 + seg, 0x0006, memory16get(0x0b43 + seg, 0x0006) + seg);
    memory16set(0x0b43 + seg, 0x000a, memory16get(0x0b43 + seg, 0x000a) + seg);
    memory16set(0x0b43 + seg, 0x000e, memory16get(0x0b43 + seg, 0x000e) + seg);
    memory16set(0x0b44 + seg, 0x0006, memory16get(0x0b44 + seg, 0x0006) + seg);
    memory16set(0x0b44 + seg, 0x000a, memory16get(0x0b44 + seg, 0x000a) + seg);
    memory16set(0x0b44 + seg, 0x000e, memory16get(0x0b44 + seg, 0x000e) + seg);
    memory16set(0x0b45 + seg, 0x0006, memory16get(0x0b45 + seg, 0x0006) + seg);
    memory16set(0x0b45 + seg, 0x000a, memory16get(0x0b45 + seg, 0x000a) + seg);
    memory16set(0x0b45 + seg, 0x000e, memory16get(0x0b45 + seg, 0x000e) + seg);
    memory16set(0x0b46 + seg, 0x0006, memory16get(0x0b46 + seg, 0x0006) + seg);
    memory16set(0x0b46 + seg, 0x000a, memory16get(0x0b46 + seg, 0x000a) + seg);
    memory16set(0x0b46 + seg, 0x000e, memory16get(0x0b46 + seg, 0x000e) + seg);
    memory16set(0x0b47 + seg, 0x0006, memory16get(0x0b47 + seg, 0x0006) + seg);
    memory16set(0x0b47 + seg, 0x000a, memory16get(0x0b47 + seg, 0x000a) + seg);
    memory16set(0x0b47 + seg, 0x000e, memory16get(0x0b47 + seg, 0x000e) + seg);
    memory16set(0x0b48 + seg, 0x0006, memory16get(0x0b48 + seg, 0x0006) + seg);
    memory16set(0x0b48 + seg, 0x000a, memory16get(0x0b48 + seg, 0x000a) + seg);
    memory16set(0x0b48 + seg, 0x000e, memory16get(0x0b48 + seg, 0x000e) + seg);
    memory16set(0x0b49 + seg, 0x0006, memory16get(0x0b49 + seg, 0x0006) + seg);
    memory16set(0x0b49 + seg, 0x000a, memory16get(0x0b49 + seg, 0x000a) + seg);
    memory16set(0x0b49 + seg, 0x000e, memory16get(0x0b49 + seg, 0x000e) + seg);
    memory16set(0x0b4a + seg, 0x0006, memory16get(0x0b4a + seg, 0x0006) + seg);
    memory16set(0x0b4a + seg, 0x000a, memory16get(0x0b4a + seg, 0x000a) + seg);
    memory16set(0x0b4a + seg, 0x000e, memory16get(0x0b4a + seg, 0x000e) + seg);
    memory16set(0x0b4b + seg, 0x0006, memory16get(0x0b4b + seg, 0x0006) + seg);
    memory16set(0x0b4b + seg, 0x000a, memory16get(0x0b4b + seg, 0x000a) + seg);
    memory16set(0x0b4b + seg, 0x000e, memory16get(0x0b4b + seg, 0x000e) + seg);
    memory16set(0x0b4c + seg, 0x0006, memory16get(0x0b4c + seg, 0x0006) + seg);
    memory16set(0x0b4c + seg, 0x000a, memory16get(0x0b4c + seg, 0x000a) + seg);
    memory16set(0x0b4c + seg, 0x000e, memory16get(0x0b4c + seg, 0x000e) + seg);
    memory16set(0x0b4d + seg, 0x0006, memory16get(0x0b4d + seg, 0x0006) + seg);
    memory16set(0x0b4d + seg, 0x000a, memory16get(0x0b4d + seg, 0x000a) + seg);
    memory16set(0x0b4d + seg, 0x000e, memory16get(0x0b4d + seg, 0x000e) + seg);
    memory16set(0x0b4e + seg, 0x0006, memory16get(0x0b4e + seg, 0x0006) + seg);
    memory16set(0x0b4e + seg, 0x000a, memory16get(0x0b4e + seg, 0x000a) + seg);
    memory16set(0x0b4e + seg, 0x000e, memory16get(0x0b4e + seg, 0x000e) + seg);
    memory16set(0x0b4f + seg, 0x0006, memory16get(0x0b4f + seg, 0x0006) + seg);
    memory16set(0x0b4f + seg, 0x000a, memory16get(0x0b4f + seg, 0x000a) + seg);
    memory16set(0x0b4f + seg, 0x000e, memory16get(0x0b4f + seg, 0x000e) + seg);
    memory16set(0x0b50 + seg, 0x0006, memory16get(0x0b50 + seg, 0x0006) + seg);
    memory16set(0x0b50 + seg, 0x000a, memory16get(0x0b50 + seg, 0x000a) + seg);
    memory16set(0x0b50 + seg, 0x000e, memory16get(0x0b50 + seg, 0x000e) + seg);
    memory16set(0x0b51 + seg, 0x0006, memory16get(0x0b51 + seg, 0x0006) + seg);
    memory16set(0x0b51 + seg, 0x000a, memory16get(0x0b51 + seg, 0x000a) + seg);
    memory16set(0x0b51 + seg, 0x000e, memory16get(0x0b51 + seg, 0x000e) + seg);
    memory16set(0x0b52 + seg, 0x0006, memory16get(0x0b52 + seg, 0x0006) + seg);
    memory16set(0x0b52 + seg, 0x000a, memory16get(0x0b52 + seg, 0x000a) + seg);
    memory16set(0x0b52 + seg, 0x000e, memory16get(0x0b52 + seg, 0x000e) + seg);
    memory16set(0x0b53 + seg, 0x0006, memory16get(0x0b53 + seg, 0x0006) + seg);
    memory16set(0x0b53 + seg, 0x000a, memory16get(0x0b53 + seg, 0x000a) + seg);
    memory16set(0x0b53 + seg, 0x000e, memory16get(0x0b53 + seg, 0x000e) + seg);
    memory16set(0x0b54 + seg, 0x0006, memory16get(0x0b54 + seg, 0x0006) + seg);
    memory16set(0x0b54 + seg, 0x000a, memory16get(0x0b54 + seg, 0x000a) + seg);
    memory16set(0x0b54 + seg, 0x000e, memory16get(0x0b54 + seg, 0x000e) + seg);
    memory16set(0x0b55 + seg, 0x0006, memory16get(0x0b55 + seg, 0x0006) + seg);
    memory16set(0x0b55 + seg, 0x000a, memory16get(0x0b55 + seg, 0x000a) + seg);
    memory16set(0x0b55 + seg, 0x000e, memory16get(0x0b55 + seg, 0x000e) + seg);
    memory16set(0x0b56 + seg, 0x0006, memory16get(0x0b56 + seg, 0x0006) + seg);
    memory16set(0x0b56 + seg, 0x000a, memory16get(0x0b56 + seg, 0x000a) + seg);
    memory16set(0x0b56 + seg, 0x000e, memory16get(0x0b56 + seg, 0x000e) + seg);
    memory16set(0x0b57 + seg, 0x0006, memory16get(0x0b57 + seg, 0x0006) + seg);
    memory16set(0x0b57 + seg, 0x000a, memory16get(0x0b57 + seg, 0x000a) + seg);
    memory16set(0x0b57 + seg, 0x000e, memory16get(0x0b57 + seg, 0x000e) + seg);
    memory16set(0x0b58 + seg, 0x0006, memory16get(0x0b58 + seg, 0x0006) + seg);
    memory16set(0x0b58 + seg, 0x000a, memory16get(0x0b58 + seg, 0x000a) + seg);
    memory16set(0x0b58 + seg, 0x000e, memory16get(0x0b58 + seg, 0x000e) + seg);
    memory16set(0x0b59 + seg, 0x0006, memory16get(0x0b59 + seg, 0x0006) + seg);
    memory16set(0x0b59 + seg, 0x000a, memory16get(0x0b59 + seg, 0x000a) + seg);
    memory16set(0x0b59 + seg, 0x000e, memory16get(0x0b59 + seg, 0x000e) + seg);
    memory16set(0x0b5a + seg, 0x0006, memory16get(0x0b5a + seg, 0x0006) + seg);
    memory16set(0x0b5a + seg, 0x000a, memory16get(0x0b5a + seg, 0x000a) + seg);
    memory16set(0x0b5a + seg, 0x000e, memory16get(0x0b5a + seg, 0x000e) + seg);
    memory16set(0x0b5b + seg, 0x0006, memory16get(0x0b5b + seg, 0x0006) + seg);
    memory16set(0x0b5b + seg, 0x000a, memory16get(0x0b5b + seg, 0x000a) + seg);
    memory16set(0x0b5b + seg, 0x000e, memory16get(0x0b5b + seg, 0x000e) + seg);
    memory16set(0x0b5c + seg, 0x0006, memory16get(0x0b5c + seg, 0x0006) + seg);
    memory16set(0x0b5c + seg, 0x000a, memory16get(0x0b5c + seg, 0x000a) + seg);
    memory16set(0x0b5c + seg, 0x000e, memory16get(0x0b5c + seg, 0x000e) + seg);
    memory16set(0x0b5d + seg, 0x0006, memory16get(0x0b5d + seg, 0x0006) + seg);
    memory16set(0x0b5d + seg, 0x000a, memory16get(0x0b5d + seg, 0x000a) + seg);
    memory16set(0x0b5d + seg, 0x000e, memory16get(0x0b5d + seg, 0x000e) + seg);
    memory16set(0x0b5e + seg, 0x0006, memory16get(0x0b5e + seg, 0x0006) + seg);
    memory16set(0x0b5e + seg, 0x000a, memory16get(0x0b5e + seg, 0x000a) + seg);
    memory16set(0x0b5e + seg, 0x000e, memory16get(0x0b5e + seg, 0x000e) + seg);
    memory16set(0x0b5f + seg, 0x0006, memory16get(0x0b5f + seg, 0x0006) + seg);
    memory16set(0x0b5f + seg, 0x000a, memory16get(0x0b5f + seg, 0x000a) + seg);
    memory16set(0x0b5f + seg, 0x000e, memory16get(0x0b5f + seg, 0x000e) + seg);
    memory16set(0x0b60 + seg, 0x0006, memory16get(0x0b60 + seg, 0x0006) + seg);
    memory16set(0x0b60 + seg, 0x000a, memory16get(0x0b60 + seg, 0x000a) + seg);
    memory16set(0x0b60 + seg, 0x000e, memory16get(0x0b60 + seg, 0x000e) + seg);
    memory16set(0x0b61 + seg, 0x0006, memory16get(0x0b61 + seg, 0x0006) + seg);
    memory16set(0x0b61 + seg, 0x000a, memory16get(0x0b61 + seg, 0x000a) + seg);
    memory16set(0x0b61 + seg, 0x000e, memory16get(0x0b61 + seg, 0x000e) + seg);
    memory16set(0x0b62 + seg, 0x0006, memory16get(0x0b62 + seg, 0x0006) + seg);
    memory16set(0x0b62 + seg, 0x000a, memory16get(0x0b62 + seg, 0x000a) + seg);
    memory16set(0x0b62 + seg, 0x000e, memory16get(0x0b62 + seg, 0x000e) + seg);
    memory16set(0x0b63 + seg, 0x0006, memory16get(0x0b63 + seg, 0x0006) + seg);
    memory16set(0x0b63 + seg, 0x000a, memory16get(0x0b63 + seg, 0x000a) + seg);
    memory16set(0x0b63 + seg, 0x000e, memory16get(0x0b63 + seg, 0x000e) + seg);
    memory16set(0x0b64 + seg, 0x0006, memory16get(0x0b64 + seg, 0x0006) + seg);
    memory16set(0x0b64 + seg, 0x000a, memory16get(0x0b64 + seg, 0x000a) + seg);
    memory16set(0x0b64 + seg, 0x000e, memory16get(0x0b64 + seg, 0x000e) + seg);
    memory16set(0x0b65 + seg, 0x0006, memory16get(0x0b65 + seg, 0x0006) + seg);
    memory16set(0x0b65 + seg, 0x000a, memory16get(0x0b65 + seg, 0x000a) + seg);
    memory16set(0x0b65 + seg, 0x000e, memory16get(0x0b65 + seg, 0x000e) + seg);
    memory16set(0x0b66 + seg, 0x0006, memory16get(0x0b66 + seg, 0x0006) + seg);
    memory16set(0x0b66 + seg, 0x000a, memory16get(0x0b66 + seg, 0x000a) + seg);
    memory16set(0x0b66 + seg, 0x000e, memory16get(0x0b66 + seg, 0x000e) + seg);
    memory16set(0x0b67 + seg, 0x0006, memory16get(0x0b67 + seg, 0x0006) + seg);
    memory16set(0x0b67 + seg, 0x000a, memory16get(0x0b67 + seg, 0x000a) + seg);
    memory16set(0x0b67 + seg, 0x000e, memory16get(0x0b67 + seg, 0x000e) + seg);
    memory16set(0x0b68 + seg, 0x0006, memory16get(0x0b68 + seg, 0x0006) + seg);
    memory16set(0x0b68 + seg, 0x000a, memory16get(0x0b68 + seg, 0x000a) + seg);
    memory16set(0x0baa + seg, 0x0000, memory16get(0x0baa + seg, 0x0000) + seg);
    memory16set(0x0baa + seg, 0x0008, memory16get(0x0baa + seg, 0x0008) + seg);
    memory16set(0x0baa + seg, 0x000c, memory16get(0x0baa + seg, 0x000c) + seg);
    memory16set(0x0bac + seg, 0x0000, memory16get(0x0bac + seg, 0x0000) + seg);
    memory16set(0x0bac + seg, 0x0004, memory16get(0x0bac + seg, 0x0004) + seg);
    memory16set(0x0bad + seg, 0x0008, memory16get(0x0bad + seg, 0x0008) + seg);
    memory16set(0x0bad + seg, 0x000c, memory16get(0x0bad + seg, 0x000c) + seg);
    memory16set(0x0bae + seg, 0x000e, memory16get(0x0bae + seg, 0x000e) + seg);
    memory16set(0x0baf + seg, 0x0002, memory16get(0x0baf + seg, 0x0002) + seg);
    memory16set(0x0bb0 + seg, 0x0004, memory16get(0x0bb0 + seg, 0x0004) + seg);
    memory16set(0x0bb0 + seg, 0x0008, memory16get(0x0bb0 + seg, 0x0008) + seg);
    memory16set(0x0bb1 + seg, 0x000a, memory16get(0x0bb1 + seg, 0x000a) + seg);
    memory16set(0x0bb1 + seg, 0x000e, memory16get(0x0bb1 + seg, 0x000e) + seg);
    memory16set(0x0bb3 + seg, 0x0000, memory16get(0x0bb3 + seg, 0x0000) + seg);
    memory16set(0x0bb3 + seg, 0x0004, memory16get(0x0bb3 + seg, 0x0004) + seg);
    memory16set(0x0bb3 + seg, 0x0008, memory16get(0x0bb3 + seg, 0x0008) + seg);
    memory16set(0x0bb4 + seg, 0x0000, memory16get(0x0bb4 + seg, 0x0000) + seg);
    memory16set(0x0bb4 + seg, 0x0008, memory16get(0x0bb4 + seg, 0x0008) + seg);
    memory16set(0x0bb5 + seg, 0x0000, memory16get(0x0bb5 + seg, 0x0000) + seg);
    memory16set(0x0bb5 + seg, 0x0008, memory16get(0x0bb5 + seg, 0x0008) + seg);
    memory16set(0x0bb6 + seg, 0x0000, memory16get(0x0bb6 + seg, 0x0000) + seg);
    memory16set(0x0bb6 + seg, 0x0008, memory16get(0x0bb6 + seg, 0x0008) + seg);
    memory16set(0x0bb7 + seg, 0x0000, memory16get(0x0bb7 + seg, 0x0000) + seg);
    memory16set(0x0bb7 + seg, 0x0008, memory16get(0x0bb7 + seg, 0x0008) + seg);
    memory16set(0x0bb8 + seg, 0x0000, memory16get(0x0bb8 + seg, 0x0000) + seg);
    memory16set(0x0bb8 + seg, 0x0008, memory16get(0x0bb8 + seg, 0x0008) + seg);
    memory16set(0x0bb9 + seg, 0x0000, memory16get(0x0bb9 + seg, 0x0000) + seg);
    memory16set(0x0bb9 + seg, 0x0008, memory16get(0x0bb9 + seg, 0x0008) + seg);
    memory16set(0x0bba + seg, 0x0000, memory16get(0x0bba + seg, 0x0000) + seg);
    memory16set(0x0bba + seg, 0x0008, memory16get(0x0bba + seg, 0x0008) + seg);
    memory16set(0x0bbb + seg, 0x0004, memory16get(0x0bbb + seg, 0x0004) + seg);
    memory16set(0x0bbb + seg, 0x000a, memory16get(0x0bbb + seg, 0x000a) + seg);
    memory16set(0x0bbc + seg, 0x0000, memory16get(0x0bbc + seg, 0x0000) + seg);
    memory16set(0x0bbc + seg, 0x0006, memory16get(0x0bbc + seg, 0x0006) + seg);
    memory16set(0x0bbd + seg, 0x0000, memory16get(0x0bbd + seg, 0x0000) + seg);
    memory16set(0x0bbd + seg, 0x0006, memory16get(0x0bbd + seg, 0x0006) + seg);
    memory16set(0x0bbd + seg, 0x000c, memory16get(0x0bbd + seg, 0x000c) + seg);
    memory16set(0x0bbe + seg, 0x0002, memory16get(0x0bbe + seg, 0x0002) + seg);
    memory16set(0x0bbe + seg, 0x000c, memory16get(0x0bbe + seg, 0x000c) + seg);
    memory16set(0x0bbf + seg, 0x0000, memory16get(0x0bbf + seg, 0x0000) + seg);
    memory16set(0x0bbf + seg, 0x0004, memory16get(0x0bbf + seg, 0x0004) + seg);
    memory16set(0x0bbf + seg, 0x0008, memory16get(0x0bbf + seg, 0x0008) + seg);
    memory16set(0x0bbf + seg, 0x000c, memory16get(0x0bbf + seg, 0x000c) + seg);
    memory16set(0x0bc0 + seg, 0x0000, memory16get(0x0bc0 + seg, 0x0000) + seg);
    memory16set(0x0bf5 + seg, 0x0004, memory16get(0x0bf5 + seg, 0x0004) + seg);
    memory16set(0x0bf5 + seg, 0x0008, memory16get(0x0bf5 + seg, 0x0008) + seg);
    memory16set(0x0c7b + seg, 0x0000, memory16get(0x0c7b + seg, 0x0000) + seg);
    memory16set(0x0c7b + seg, 0x0004, memory16get(0x0c7b + seg, 0x0004) + seg);
    memory16set(0x0c7b + seg, 0x0008, memory16get(0x0c7b + seg, 0x0008) + seg);
    memory16set(0x0c7b + seg, 0x000c, memory16get(0x0c7b + seg, 0x000c) + seg);
    memory16set(0x0c87 + seg, 0x000c, memory16get(0x0c87 + seg, 0x000c) + seg);
    memory16set(0x0c88 + seg, 0x0000, memory16get(0x0c88 + seg, 0x0000) + seg);
    memory16set(0x0c8b + seg, 0x0005, memory16get(0x0c8b + seg, 0x0005) + seg);
    memory16set(0x0c8b + seg, 0x0009, memory16get(0x0c8b + seg, 0x0009) + seg);
    memory16set(0x0c8b + seg, 0x000d, memory16get(0x0c8b + seg, 0x000d) + seg);
    memory16set(0x0c8c + seg, 0x0005, memory16get(0x0c8c + seg, 0x0005) + seg);
    memory16set(0x0c8c + seg, 0x000d, memory16get(0x0c8c + seg, 0x000d) + seg);
    memory16set(0x0c8d + seg, 0x0005, memory16get(0x0c8d + seg, 0x0005) + seg);
    memory16set(0x0d0b + seg, 0x0002, memory16get(0x0d0b + seg, 0x0002) + seg);
    memory16set(0x0d0b + seg, 0x0006, memory16get(0x0d0b + seg, 0x0006) + seg);
    memory16set(0x0d0b + seg, 0x000a, memory16get(0x0d0b + seg, 0x000a) + seg);
    memory16set(0x0d0b + seg, 0x000e, memory16get(0x0d0b + seg, 0x000e) + seg);
    memory16set(0x0d0c + seg, 0x0002, memory16get(0x0d0c + seg, 0x0002) + seg);
    memory16set(0x0d0c + seg, 0x0006, memory16get(0x0d0c + seg, 0x0006) + seg);
    memory16set(0x0d0c + seg, 0x000a, memory16get(0x0d0c + seg, 0x000a) + seg);
    memory16set(0x0d46 + seg, 0x0002, memory16get(0x0d46 + seg, 0x0002) + seg);
    memory16set(0x0d46 + seg, 0x0006, memory16get(0x0d46 + seg, 0x0006) + seg);
    memory16set(0x0d47 + seg, 0x000c, memory16get(0x0d47 + seg, 0x000c) + seg);
    memory16set(0x0d48 + seg, 0x0000, memory16get(0x0d48 + seg, 0x0000) + seg);
    memory16set(0x0d49 + seg, 0x0006, memory16get(0x0d49 + seg, 0x0006) + seg);
    memory16set(0x0d49 + seg, 0x000a, memory16get(0x0d49 + seg, 0x000a) + seg);
    memory16set(0x0d7f + seg, 0x000b, memory16get(0x0d7f + seg, 0x000b) + seg);
    memory16set(0x0d7f + seg, 0x000f, memory16get(0x0d7f + seg, 0x000f) + seg);
    memory16set(0x0d80 + seg, 0x0003, memory16get(0x0d80 + seg, 0x0003) + seg);
    memory16set(0x0d80 + seg, 0x0007, memory16get(0x0d80 + seg, 0x0007) + seg);
    memory16set(0x0d80 + seg, 0x000b, memory16get(0x0d80 + seg, 0x000b) + seg);
    memory16set(0x0d80 + seg, 0x000f, memory16get(0x0d80 + seg, 0x000f) + seg);
    memory16set(0x0d81 + seg, 0x0003, memory16get(0x0d81 + seg, 0x0003) + seg);
    memory16set(0x0d81 + seg, 0x0007, memory16get(0x0d81 + seg, 0x0007) + seg);
    memory16set(0x0d82 + seg, 0x0003, memory16get(0x0d82 + seg, 0x0003) + seg);
    memory16set(0x0d82 + seg, 0x0007, memory16get(0x0d82 + seg, 0x0007) + seg);
    memory16set(0x0d83 + seg, 0x0003, memory16get(0x0d83 + seg, 0x0003) + seg);
    memory16set(0x0d83 + seg, 0x0007, memory16get(0x0d83 + seg, 0x0007) + seg);
    memory16set(0x0d84 + seg, 0x0003, memory16get(0x0d84 + seg, 0x0003) + seg);
    memory16set(0x0d84 + seg, 0x0007, memory16get(0x0d84 + seg, 0x0007) + seg);
    memory16set(0x0d8c + seg, 0x0004, memory16get(0x0d8c + seg, 0x0004) + seg);
    memory16set(0x0d8c + seg, 0x000a, memory16get(0x0d8c + seg, 0x000a) + seg);
    memory16set(0x0d8d + seg, 0x0000, memory16get(0x0d8d + seg, 0x0000) + seg);
    memory16set(0x0d8d + seg, 0x0006, memory16get(0x0d8d + seg, 0x0006) + seg);
    memory16set(0x0d8d + seg, 0x000c, memory16get(0x0d8d + seg, 0x000c) + seg);
    memory16set(0x0d8e + seg, 0x0002, memory16get(0x0d8e + seg, 0x0002) + seg);
    memory16set(0x0d8e + seg, 0x0008, memory16get(0x0d8e + seg, 0x0008) + seg);
    memory16set(0x0d8e + seg, 0x000e, memory16get(0x0d8e + seg, 0x000e) + seg);
    memory16set(0x0d8f + seg, 0x0004, memory16get(0x0d8f + seg, 0x0004) + seg);
    memory16set(0x0d8f + seg, 0x000a, memory16get(0x0d8f + seg, 0x000a) + seg);
    memory16set(0x0d90 + seg, 0x0000, memory16get(0x0d90 + seg, 0x0000) + seg);
    memory16set(0x0dab + seg, 0x0006, memory16get(0x0dab + seg, 0x0006) + seg);
    memory16set(0x0dab + seg, 0x000a, memory16get(0x0dab + seg, 0x000a) + seg);
    memory16set(0x0dab + seg, 0x000e, memory16get(0x0dab + seg, 0x000e) + seg);
    memory16set(0x0dac + seg, 0x0002, memory16get(0x0dac + seg, 0x0002) + seg);
    memory16set(0x0dac + seg, 0x0006, memory16get(0x0dac + seg, 0x0006) + seg);
    memory16set(0x0dac + seg, 0x000a, memory16get(0x0dac + seg, 0x000a) + seg);
    memory16set(0x0dac + seg, 0x000e, memory16get(0x0dac + seg, 0x000e) + seg);
    memory16set(0x0dad + seg, 0x0002, memory16get(0x0dad + seg, 0x0002) + seg);
    memory16set(0x0dad + seg, 0x0006, memory16get(0x0dad + seg, 0x0006) + seg);
    memory16set(0x0dad + seg, 0x000a, memory16get(0x0dad + seg, 0x000a) + seg);
    memory16set(0x0dad + seg, 0x000e, memory16get(0x0dad + seg, 0x000e) + seg);
    memory16set(0x0dae + seg, 0x0002, memory16get(0x0dae + seg, 0x0002) + seg);
    memory16set(0x0dae + seg, 0x0006, memory16get(0x0dae + seg, 0x0006) + seg);
    memory16set(0x0dae + seg, 0x000a, memory16get(0x0dae + seg, 0x000a) + seg);
    memory16set(0x0dae + seg, 0x000e, memory16get(0x0dae + seg, 0x000e) + seg);
    memory16set(0x0daf + seg, 0x0002, memory16get(0x0daf + seg, 0x0002) + seg);
    memory16set(0x0daf + seg, 0x000a, memory16get(0x0daf + seg, 0x000a) + seg);
    memory16set(0x0daf + seg, 0x000e, memory16get(0x0daf + seg, 0x000e) + seg);
    memory16set(0x0db0 + seg, 0x0002, memory16get(0x0db0 + seg, 0x0002) + seg);
    memory16set(0x0db0 + seg, 0x0006, memory16get(0x0db0 + seg, 0x0006) + seg);
    memory16set(0x0db0 + seg, 0x000a, memory16get(0x0db0 + seg, 0x000a) + seg);
    memory16set(0x0db0 + seg, 0x000e, memory16get(0x0db0 + seg, 0x000e) + seg);
    memory16set(0x0db1 + seg, 0x0002, memory16get(0x0db1 + seg, 0x0002) + seg);
    memory16set(0x0db1 + seg, 0x0006, memory16get(0x0db1 + seg, 0x0006) + seg);
    memory16set(0x0db1 + seg, 0x000a, memory16get(0x0db1 + seg, 0x000a) + seg);
    memory16set(0x0db1 + seg, 0x000e, memory16get(0x0db1 + seg, 0x000e) + seg);
    memory16set(0x0db2 + seg, 0x0002, memory16get(0x0db2 + seg, 0x0002) + seg);
    memory16set(0x0db2 + seg, 0x0006, memory16get(0x0db2 + seg, 0x0006) + seg);
    memory16set(0x0db2 + seg, 0x000a, memory16get(0x0db2 + seg, 0x000a) + seg);
    memory16set(0x0db2 + seg, 0x000e, memory16get(0x0db2 + seg, 0x000e) + seg);
    memory16set(0x0db3 + seg, 0x0002, memory16get(0x0db3 + seg, 0x0002) + seg);
    memory16set(0x0db3 + seg, 0x0006, memory16get(0x0db3 + seg, 0x0006) + seg);
    memory16set(0x0db3 + seg, 0x000e, memory16get(0x0db3 + seg, 0x000e) + seg);
    memory16set(0x0db4 + seg, 0x0002, memory16get(0x0db4 + seg, 0x0002) + seg);
    memory16set(0x0db4 + seg, 0x0006, memory16get(0x0db4 + seg, 0x0006) + seg);
    memory16set(0x0db4 + seg, 0x000a, memory16get(0x0db4 + seg, 0x000a) + seg);
    memory16set(0x0db4 + seg, 0x000e, memory16get(0x0db4 + seg, 0x000e) + seg);
    memory16set(0x0db5 + seg, 0x0002, memory16get(0x0db5 + seg, 0x0002) + seg);
    memory16set(0x0db5 + seg, 0x000a, memory16get(0x0db5 + seg, 0x000a) + seg);
    memory16set(0x0db5 + seg, 0x000e, memory16get(0x0db5 + seg, 0x000e) + seg);
    memory16set(0x0db6 + seg, 0x0002, memory16get(0x0db6 + seg, 0x0002) + seg);
    memory16set(0x0db6 + seg, 0x0006, memory16get(0x0db6 + seg, 0x0006) + seg);
    memory16set(0x0db6 + seg, 0x000a, memory16get(0x0db6 + seg, 0x000a) + seg);
    memory16set(0x0db6 + seg, 0x000e, memory16get(0x0db6 + seg, 0x000e) + seg);
    memory16set(0x0db7 + seg, 0x0006, memory16get(0x0db7 + seg, 0x0006) + seg);
    memory16set(0x0db7 + seg, 0x000a, memory16get(0x0db7 + seg, 0x000a) + seg);
    memory16set(0x0db7 + seg, 0x000e, memory16get(0x0db7 + seg, 0x000e) + seg);
    memory16set(0x0db8 + seg, 0x0002, memory16get(0x0db8 + seg, 0x0002) + seg);
    memory16set(0x0db8 + seg, 0x0006, memory16get(0x0db8 + seg, 0x0006) + seg);
    memory16set(0x0db8 + seg, 0x000a, memory16get(0x0db8 + seg, 0x000a) + seg);
    memory16set(0x0db8 + seg, 0x000e, memory16get(0x0db8 + seg, 0x000e) + seg);
    memory16set(0x0db9 + seg, 0x0002, memory16get(0x0db9 + seg, 0x0002) + seg);
    memory16set(0x0db9 + seg, 0x0006, memory16get(0x0db9 + seg, 0x0006) + seg);
    memory16set(0x0db9 + seg, 0x000a, memory16get(0x0db9 + seg, 0x000a) + seg);
    memory16set(0x0db9 + seg, 0x000e, memory16get(0x0db9 + seg, 0x000e) + seg);
    memory16set(0x0dba + seg, 0x0002, memory16get(0x0dba + seg, 0x0002) + seg);
    memory16set(0x0dba + seg, 0x0006, memory16get(0x0dba + seg, 0x0006) + seg);
    memory16set(0x0dba + seg, 0x000a, memory16get(0x0dba + seg, 0x000a) + seg);
    memory16set(0x0dba + seg, 0x000e, memory16get(0x0dba + seg, 0x000e) + seg);
    memory16set(0x0dbb + seg, 0x0002, memory16get(0x0dbb + seg, 0x0002) + seg);
    memory16set(0x0dbb + seg, 0x000a, memory16get(0x0dbb + seg, 0x000a) + seg);
    memory16set(0x0dbb + seg, 0x000e, memory16get(0x0dbb + seg, 0x000e) + seg);
    memory16set(0x0dbc + seg, 0x0002, memory16get(0x0dbc + seg, 0x0002) + seg);
    memory16set(0x0dbc + seg, 0x0006, memory16get(0x0dbc + seg, 0x0006) + seg);
    memory16set(0x0dbc + seg, 0x000a, memory16get(0x0dbc + seg, 0x000a) + seg);
    memory16set(0x0dbd + seg, 0x0000, memory16get(0x0dbd + seg, 0x0000) + seg);
    memory16set(0x0dbd + seg, 0x0004, memory16get(0x0dbd + seg, 0x0004) + seg);
    memory16set(0x0dbd + seg, 0x0008, memory16get(0x0dbd + seg, 0x0008) + seg);
    memory16set(0x0dbd + seg, 0x000c, memory16get(0x0dbd + seg, 0x000c) + seg);
    memory16set(0x0dbe + seg, 0x0000, memory16get(0x0dbe + seg, 0x0000) + seg);
    memory16set(0x0dbe + seg, 0x0004, memory16get(0x0dbe + seg, 0x0004) + seg);
    memory16set(0x0dbe + seg, 0x0008, memory16get(0x0dbe + seg, 0x0008) + seg);
    memory16set(0x0dbe + seg, 0x000c, memory16get(0x0dbe + seg, 0x000c) + seg);
    memory16set(0x0dbf + seg, 0x0000, memory16get(0x0dbf + seg, 0x0000) + seg);
    memory16set(0x0dbf + seg, 0x0004, memory16get(0x0dbf + seg, 0x0004) + seg);
    memory16set(0x0dbf + seg, 0x0008, memory16get(0x0dbf + seg, 0x0008) + seg);
    memory16set(0x0dbf + seg, 0x000c, memory16get(0x0dbf + seg, 0x000c) + seg);
    memory16set(0x0dc0 + seg, 0x0000, memory16get(0x0dc0 + seg, 0x0000) + seg);
    memory16set(0x0dc0 + seg, 0x0004, memory16get(0x0dc0 + seg, 0x0004) + seg);
    memory16set(0x0dc0 + seg, 0x0008, memory16get(0x0dc0 + seg, 0x0008) + seg);
    memory16set(0x0dc0 + seg, 0x000c, memory16get(0x0dc0 + seg, 0x000c) + seg);
    memory16set(0x0dc1 + seg, 0x0004, memory16get(0x0dc1 + seg, 0x0004) + seg);
    memory16set(0x0dc1 + seg, 0x0008, memory16get(0x0dc1 + seg, 0x0008) + seg);
    memory16set(0x0dc1 + seg, 0x000c, memory16get(0x0dc1 + seg, 0x000c) + seg);
    memory16set(0x0dc2 + seg, 0x0000, memory16get(0x0dc2 + seg, 0x0000) + seg);
    memory16set(0x0dc2 + seg, 0x0004, memory16get(0x0dc2 + seg, 0x0004) + seg);
    memory16set(0x0dc2 + seg, 0x0008, memory16get(0x0dc2 + seg, 0x0008) + seg);
    memory16set(0x0dc2 + seg, 0x000c, memory16get(0x0dc2 + seg, 0x000c) + seg);
    memory16set(0x0dc3 + seg, 0x0002, memory16get(0x0dc3 + seg, 0x0002) + seg);
    memory16set(0x0dc3 + seg, 0x0006, memory16get(0x0dc3 + seg, 0x0006) + seg);
    memory16set(0x0dc3 + seg, 0x000a, memory16get(0x0dc3 + seg, 0x000a) + seg);
    memory16set(0x0dc3 + seg, 0x000e, memory16get(0x0dc3 + seg, 0x000e) + seg);
    memory16set(0x0dc4 + seg, 0x0002, memory16get(0x0dc4 + seg, 0x0002) + seg);
    memory16set(0x0dc4 + seg, 0x0006, memory16get(0x0dc4 + seg, 0x0006) + seg);
    memory16set(0x0dc4 + seg, 0x000a, memory16get(0x0dc4 + seg, 0x000a) + seg);
    memory16set(0x0dc4 + seg, 0x000e, memory16get(0x0dc4 + seg, 0x000e) + seg);
    memory16set(0x0dc5 + seg, 0x0002, memory16get(0x0dc5 + seg, 0x0002) + seg);
    memory16set(0x0dc5 + seg, 0x0006, memory16get(0x0dc5 + seg, 0x0006) + seg);
    memory16set(0x0dc5 + seg, 0x000a, memory16get(0x0dc5 + seg, 0x000a) + seg);
    memory16set(0x0dc5 + seg, 0x000e, memory16get(0x0dc5 + seg, 0x000e) + seg);
    memory16set(0x0dc6 + seg, 0x0002, memory16get(0x0dc6 + seg, 0x0002) + seg);
    memory16set(0x0dc6 + seg, 0x0006, memory16get(0x0dc6 + seg, 0x0006) + seg);
    memory16set(0x0dc6 + seg, 0x000a, memory16get(0x0dc6 + seg, 0x000a) + seg);
    memory16set(0x0dc6 + seg, 0x000e, memory16get(0x0dc6 + seg, 0x000e) + seg);
    memory16set(0x0dc7 + seg, 0x0006, memory16get(0x0dc7 + seg, 0x0006) + seg);
    memory16set(0x0dc7 + seg, 0x000a, memory16get(0x0dc7 + seg, 0x000a) + seg);
    memory16set(0x0dc7 + seg, 0x000e, memory16get(0x0dc7 + seg, 0x000e) + seg);
    memory16set(0x0dc8 + seg, 0x0002, memory16get(0x0dc8 + seg, 0x0002) + seg);
    memory16set(0x0dc8 + seg, 0x0006, memory16get(0x0dc8 + seg, 0x0006) + seg);
    memory16set(0x0dc8 + seg, 0x000a, memory16get(0x0dc8 + seg, 0x000a) + seg);
    memory16set(0x0dc8 + seg, 0x000e, memory16get(0x0dc8 + seg, 0x000e) + seg);
    memory16set(0x0dc9 + seg, 0x0004, memory16get(0x0dc9 + seg, 0x0004) + seg);
    memory16set(0x0dc9 + seg, 0x0008, memory16get(0x0dc9 + seg, 0x0008) + seg);
    memory16set(0x0dc9 + seg, 0x000c, memory16get(0x0dc9 + seg, 0x000c) + seg);
    memory16set(0x0dca + seg, 0x0000, memory16get(0x0dca + seg, 0x0000) + seg);
    memory16set(0x0dca + seg, 0x0004, memory16get(0x0dca + seg, 0x0004) + seg);
    memory16set(0x0dca + seg, 0x0008, memory16get(0x0dca + seg, 0x0008) + seg);
    memory16set(0x0dca + seg, 0x000c, memory16get(0x0dca + seg, 0x000c) + seg);
    memory16set(0x0dcb + seg, 0x0000, memory16get(0x0dcb + seg, 0x0000) + seg);
    memory16set(0x0dcb + seg, 0x0004, memory16get(0x0dcb + seg, 0x0004) + seg);
    memory16set(0x0dcb + seg, 0x0008, memory16get(0x0dcb + seg, 0x0008) + seg);
    memory16set(0x0dcb + seg, 0x000c, memory16get(0x0dcb + seg, 0x000c) + seg);
    memory16set(0x0dcc + seg, 0x0000, memory16get(0x0dcc + seg, 0x0000) + seg);
    memory16set(0x0dcc + seg, 0x0004, memory16get(0x0dcc + seg, 0x0004) + seg);
    memory16set(0x0dcc + seg, 0x0008, memory16get(0x0dcc + seg, 0x0008) + seg);
    memory16set(0x0dcc + seg, 0x000c, memory16get(0x0dcc + seg, 0x000c) + seg);
    memory16set(0x0dcd + seg, 0x0000, memory16get(0x0dcd + seg, 0x0000) + seg);
    memory16set(0x0dcd + seg, 0x0008, memory16get(0x0dcd + seg, 0x0008) + seg);
    memory16set(0x0dcd + seg, 0x000c, memory16get(0x0dcd + seg, 0x000c) + seg);
    memory16set(0x0dce + seg, 0x0000, memory16get(0x0dce + seg, 0x0000) + seg);
    memory16set(0x0dce + seg, 0x0004, memory16get(0x0dce + seg, 0x0004) + seg);
    memory16set(0x0dce + seg, 0x0008, memory16get(0x0dce + seg, 0x0008) + seg);
    memory16set(0x0dce + seg, 0x000c, memory16get(0x0dce + seg, 0x000c) + seg);
    memory16set(0x0dcf + seg, 0x0000, memory16get(0x0dcf + seg, 0x0000) + seg);
    memory16set(0x0dcf + seg, 0x0006, memory16get(0x0dcf + seg, 0x0006) + seg);
    memory16set(0x0dcf + seg, 0x000a, memory16get(0x0dcf + seg, 0x000a) + seg);
    memory16set(0x0dcf + seg, 0x000e, memory16get(0x0dcf + seg, 0x000e) + seg);
    memory16set(0x0dd0 + seg, 0x0002, memory16get(0x0dd0 + seg, 0x0002) + seg);
    memory16set(0x0dd0 + seg, 0x0006, memory16get(0x0dd0 + seg, 0x0006) + seg);
    memory16set(0x0dd0 + seg, 0x000a, memory16get(0x0dd0 + seg, 0x000a) + seg);
    memory16set(0x0dd0 + seg, 0x000e, memory16get(0x0dd0 + seg, 0x000e) + seg);
    memory16set(0x0dd1 + seg, 0x0002, memory16get(0x0dd1 + seg, 0x0002) + seg);
    memory16set(0x0dd1 + seg, 0x0006, memory16get(0x0dd1 + seg, 0x0006) + seg);
    memory16set(0x0dd1 + seg, 0x000a, memory16get(0x0dd1 + seg, 0x000a) + seg);
    memory16set(0x0dd1 + seg, 0x000e, memory16get(0x0dd1 + seg, 0x000e) + seg);
    memory16set(0x0dd2 + seg, 0x0002, memory16get(0x0dd2 + seg, 0x0002) + seg);
    memory16set(0x0dd2 + seg, 0x0006, memory16get(0x0dd2 + seg, 0x0006) + seg);
    memory16set(0x0dd2 + seg, 0x000a, memory16get(0x0dd2 + seg, 0x000a) + seg);
    memory16set(0x0dd2 + seg, 0x000e, memory16get(0x0dd2 + seg, 0x000e) + seg);
    memory16set(0x0dd3 + seg, 0x0002, memory16get(0x0dd3 + seg, 0x0002) + seg);
    memory16set(0x0dd3 + seg, 0x000a, memory16get(0x0dd3 + seg, 0x000a) + seg);
    memory16set(0x0dd3 + seg, 0x000e, memory16get(0x0dd3 + seg, 0x000e) + seg);
    memory16set(0x0dd4 + seg, 0x0002, memory16get(0x0dd4 + seg, 0x0002) + seg);
    memory16set(0x0dd4 + seg, 0x0006, memory16get(0x0dd4 + seg, 0x0006) + seg);
    memory16set(0x0dd4 + seg, 0x000a, memory16get(0x0dd4 + seg, 0x000a) + seg);
    memory16set(0x0dd4 + seg, 0x000e, memory16get(0x0dd4 + seg, 0x000e) + seg);
    memory16set(0x0dd5 + seg, 0x0002, memory16get(0x0dd5 + seg, 0x0002) + seg);
    memory16set(0x0dd5 + seg, 0x0008, memory16get(0x0dd5 + seg, 0x0008) + seg);
    memory16set(0x0dd5 + seg, 0x000c, memory16get(0x0dd5 + seg, 0x000c) + seg);
    memory16set(0x0dd6 + seg, 0x0000, memory16get(0x0dd6 + seg, 0x0000) + seg);
    memory16set(0x0dd6 + seg, 0x0004, memory16get(0x0dd6 + seg, 0x0004) + seg);
    memory16set(0x0dd6 + seg, 0x0008, memory16get(0x0dd6 + seg, 0x0008) + seg);
    memory16set(0x0dd6 + seg, 0x000c, memory16get(0x0dd6 + seg, 0x000c) + seg);
    memory16set(0x0dd7 + seg, 0x0000, memory16get(0x0dd7 + seg, 0x0000) + seg);
    memory16set(0x0dd7 + seg, 0x0004, memory16get(0x0dd7 + seg, 0x0004) + seg);
    memory16set(0x0dd7 + seg, 0x0008, memory16get(0x0dd7 + seg, 0x0008) + seg);
    memory16set(0x0dd7 + seg, 0x000c, memory16get(0x0dd7 + seg, 0x000c) + seg);
    memory16set(0x0dd8 + seg, 0x0000, memory16get(0x0dd8 + seg, 0x0000) + seg);
    memory16set(0x0dd8 + seg, 0x0004, memory16get(0x0dd8 + seg, 0x0004) + seg);
    memory16set(0x0dd8 + seg, 0x0008, memory16get(0x0dd8 + seg, 0x0008) + seg);
    memory16set(0x0dd8 + seg, 0x000c, memory16get(0x0dd8 + seg, 0x000c) + seg);
    memory16set(0x0dd9 + seg, 0x0000, memory16get(0x0dd9 + seg, 0x0000) + seg);
    memory16set(0x0dd9 + seg, 0x0004, memory16get(0x0dd9 + seg, 0x0004) + seg);
    memory16set(0x0dd9 + seg, 0x000c, memory16get(0x0dd9 + seg, 0x000c) + seg);
    memory16set(0x0dda + seg, 0x0000, memory16get(0x0dda + seg, 0x0000) + seg);
    memory16set(0x0dda + seg, 0x0004, memory16get(0x0dda + seg, 0x0004) + seg);
    memory16set(0x0dda + seg, 0x0008, memory16get(0x0dda + seg, 0x0008) + seg);
    memory16set(0x0dda + seg, 0x000c, memory16get(0x0dda + seg, 0x000c) + seg);
    memory16set(0x0ddb + seg, 0x0002, memory16get(0x0ddb + seg, 0x0002) + seg);
    memory16set(0x0ddb + seg, 0x0006, memory16get(0x0ddb + seg, 0x0006) + seg);
    memory16set(0x0ddb + seg, 0x000a, memory16get(0x0ddb + seg, 0x000a) + seg);
    memory16set(0x0ddb + seg, 0x000e, memory16get(0x0ddb + seg, 0x000e) + seg);
    memory16set(0x0ddc + seg, 0x0002, memory16get(0x0ddc + seg, 0x0002) + seg);
    memory16set(0x0ddc + seg, 0x0006, memory16get(0x0ddc + seg, 0x0006) + seg);
    memory16set(0x0ddc + seg, 0x000a, memory16get(0x0ddc + seg, 0x000a) + seg);
    memory16set(0x0ddc + seg, 0x000e, memory16get(0x0ddc + seg, 0x000e) + seg);
    memory16set(0x0ddd + seg, 0x0002, memory16get(0x0ddd + seg, 0x0002) + seg);
    memory16set(0x0ddd + seg, 0x0006, memory16get(0x0ddd + seg, 0x0006) + seg);
    memory16set(0x0ddd + seg, 0x000a, memory16get(0x0ddd + seg, 0x000a) + seg);
    memory16set(0x0ddd + seg, 0x000e, memory16get(0x0ddd + seg, 0x000e) + seg);
    memory16set(0x0dde + seg, 0x0002, memory16get(0x0dde + seg, 0x0002) + seg);
    memory16set(0x0dde + seg, 0x0006, memory16get(0x0dde + seg, 0x0006) + seg);
    memory16set(0x0dde + seg, 0x000a, memory16get(0x0dde + seg, 0x000a) + seg);
    memory16set(0x0dde + seg, 0x000e, memory16get(0x0dde + seg, 0x000e) + seg);
    memory16set(0x0ddf + seg, 0x0006, memory16get(0x0ddf + seg, 0x0006) + seg);
    memory16set(0x0ddf + seg, 0x000a, memory16get(0x0ddf + seg, 0x000a) + seg);
    memory16set(0x0ddf + seg, 0x000e, memory16get(0x0ddf + seg, 0x000e) + seg);
    memory16set(0x0de0 + seg, 0x0002, memory16get(0x0de0 + seg, 0x0002) + seg);
    memory16set(0x0de0 + seg, 0x0006, memory16get(0x0de0 + seg, 0x0006) + seg);
    memory16set(0x0de0 + seg, 0x000c, memory16get(0x0de0 + seg, 0x000c) + seg);
    memory16set(0x0de1 + seg, 0x0000, memory16get(0x0de1 + seg, 0x0000) + seg);
    memory16set(0x0de1 + seg, 0x0004, memory16get(0x0de1 + seg, 0x0004) + seg);
    memory16set(0x0de1 + seg, 0x0008, memory16get(0x0de1 + seg, 0x0008) + seg);
    memory16set(0x0de1 + seg, 0x000c, memory16get(0x0de1 + seg, 0x000c) + seg);
    memory16set(0x0de2 + seg, 0x0000, memory16get(0x0de2 + seg, 0x0000) + seg);
    memory16set(0x0de2 + seg, 0x0004, memory16get(0x0de2 + seg, 0x0004) + seg);
    memory16set(0x0de2 + seg, 0x0008, memory16get(0x0de2 + seg, 0x0008) + seg);
    memory16set(0x0de2 + seg, 0x000c, memory16get(0x0de2 + seg, 0x000c) + seg);
    memory16set(0x0de3 + seg, 0x0000, memory16get(0x0de3 + seg, 0x0000) + seg);
    memory16set(0x0de3 + seg, 0x0004, memory16get(0x0de3 + seg, 0x0004) + seg);
    memory16set(0x0de3 + seg, 0x0008, memory16get(0x0de3 + seg, 0x0008) + seg);
    memory16set(0x0de3 + seg, 0x000c, memory16get(0x0de3 + seg, 0x000c) + seg);
    memory16set(0x0de4 + seg, 0x0000, memory16get(0x0de4 + seg, 0x0000) + seg);
    memory16set(0x0de4 + seg, 0x0004, memory16get(0x0de4 + seg, 0x0004) + seg);
    memory16set(0x0de4 + seg, 0x0008, memory16get(0x0de4 + seg, 0x0008) + seg);
    memory16set(0x0de5 + seg, 0x0000, memory16get(0x0de5 + seg, 0x0000) + seg);
    memory16set(0x0de5 + seg, 0x0004, memory16get(0x0de5 + seg, 0x0004) + seg);
    memory16set(0x0de5 + seg, 0x0008, memory16get(0x0de5 + seg, 0x0008) + seg);
    memory16set(0x0de5 + seg, 0x000c, memory16get(0x0de5 + seg, 0x000c) + seg);
    memory16set(0x0de6 + seg, 0x0000, memory16get(0x0de6 + seg, 0x0000) + seg);
    memory16set(0x0de6 + seg, 0x0004, memory16get(0x0de6 + seg, 0x0004) + seg);
    memory16set(0x0de6 + seg, 0x0008, memory16get(0x0de6 + seg, 0x0008) + seg);
    memory16set(0x0de6 + seg, 0x000e, memory16get(0x0de6 + seg, 0x000e) + seg);
    memory16set(0x0de7 + seg, 0x0002, memory16get(0x0de7 + seg, 0x0002) + seg);
    memory16set(0x0de7 + seg, 0x0006, memory16get(0x0de7 + seg, 0x0006) + seg);
    memory16set(0x0de7 + seg, 0x000a, memory16get(0x0de7 + seg, 0x000a) + seg);
    memory16set(0x0de7 + seg, 0x000e, memory16get(0x0de7 + seg, 0x000e) + seg);
    memory16set(0x0de8 + seg, 0x0002, memory16get(0x0de8 + seg, 0x0002) + seg);
    memory16set(0x0de8 + seg, 0x0006, memory16get(0x0de8 + seg, 0x0006) + seg);
    memory16set(0x0de8 + seg, 0x000a, memory16get(0x0de8 + seg, 0x000a) + seg);
    memory16set(0x0de8 + seg, 0x000e, memory16get(0x0de8 + seg, 0x000e) + seg);
    memory16set(0x0de9 + seg, 0x0002, memory16get(0x0de9 + seg, 0x0002) + seg);
    memory16set(0x0de9 + seg, 0x0006, memory16get(0x0de9 + seg, 0x0006) + seg);
    memory16set(0x0de9 + seg, 0x000a, memory16get(0x0de9 + seg, 0x000a) + seg);
    memory16set(0x0de9 + seg, 0x000e, memory16get(0x0de9 + seg, 0x000e) + seg);
    memory16set(0x0dea + seg, 0x0002, memory16get(0x0dea + seg, 0x0002) + seg);
    memory16set(0x0dea + seg, 0x0006, memory16get(0x0dea + seg, 0x0006) + seg);
    memory16set(0x0dea + seg, 0x000a, memory16get(0x0dea + seg, 0x000a) + seg);
    memory16set(0x0deb + seg, 0x0002, memory16get(0x0deb + seg, 0x0002) + seg);
    memory16set(0x0deb + seg, 0x0006, memory16get(0x0deb + seg, 0x0006) + seg);
    memory16set(0x0deb + seg, 0x000a, memory16get(0x0deb + seg, 0x000a) + seg);
    memory16set(0x0deb + seg, 0x000e, memory16get(0x0deb + seg, 0x000e) + seg);
    memory16set(0x0dec + seg, 0x0002, memory16get(0x0dec + seg, 0x0002) + seg);
    memory16set(0x0dec + seg, 0x0008, memory16get(0x0dec + seg, 0x0008) + seg);
    memory16set(0x0dec + seg, 0x000c, memory16get(0x0dec + seg, 0x000c) + seg);
    memory16set(0x0ded + seg, 0x0000, memory16get(0x0ded + seg, 0x0000) + seg);
    memory16set(0x0ded + seg, 0x0004, memory16get(0x0ded + seg, 0x0004) + seg);
    memory16set(0x0ded + seg, 0x0008, memory16get(0x0ded + seg, 0x0008) + seg);
    memory16set(0x0ded + seg, 0x000c, memory16get(0x0ded + seg, 0x000c) + seg);
    memory16set(0x0dee + seg, 0x0000, memory16get(0x0dee + seg, 0x0000) + seg);
    memory16set(0x0dee + seg, 0x0004, memory16get(0x0dee + seg, 0x0004) + seg);
    memory16set(0x0dee + seg, 0x0008, memory16get(0x0dee + seg, 0x0008) + seg);
    memory16set(0x0dee + seg, 0x000c, memory16get(0x0dee + seg, 0x000c) + seg);
    memory16set(0x0def + seg, 0x0000, memory16get(0x0def + seg, 0x0000) + seg);
    memory16set(0x0def + seg, 0x0004, memory16get(0x0def + seg, 0x0004) + seg);
    memory16set(0x0def + seg, 0x0008, memory16get(0x0def + seg, 0x0008) + seg);
    memory16set(0x0def + seg, 0x000c, memory16get(0x0def + seg, 0x000c) + seg);
    memory16set(0x0df0 + seg, 0x0000, memory16get(0x0df0 + seg, 0x0000) + seg);
    memory16set(0x0df0 + seg, 0x0004, memory16get(0x0df0 + seg, 0x0004) + seg);
    memory16set(0x0df0 + seg, 0x0008, memory16get(0x0df0 + seg, 0x0008) + seg);
    memory16set(0x0df0 + seg, 0x000c, memory16get(0x0df0 + seg, 0x000c) + seg);
    memory16set(0x0df1 + seg, 0x0000, memory16get(0x0df1 + seg, 0x0000) + seg);
    memory16set(0x0df1 + seg, 0x0004, memory16get(0x0df1 + seg, 0x0004) + seg);
    memory16set(0x0df1 + seg, 0x0008, memory16get(0x0df1 + seg, 0x0008) + seg);
    memory16set(0x0df1 + seg, 0x000c, memory16get(0x0df1 + seg, 0x000c) + seg);
    memory16set(0x0df2 + seg, 0x0000, memory16get(0x0df2 + seg, 0x0000) + seg);
    memory16set(0x0df2 + seg, 0x0004, memory16get(0x0df2 + seg, 0x0004) + seg);
    memory16set(0x0df2 + seg, 0x0008, memory16get(0x0df2 + seg, 0x0008) + seg);
    memory16set(0x0df2 + seg, 0x000c, memory16get(0x0df2 + seg, 0x000c) + seg);
    memory16set(0x0df3 + seg, 0x0000, memory16get(0x0df3 + seg, 0x0000) + seg);
    memory16set(0x0df3 + seg, 0x0004, memory16get(0x0df3 + seg, 0x0004) + seg);
    memory16set(0x0df3 + seg, 0x0008, memory16get(0x0df3 + seg, 0x0008) + seg);
    memory16set(0x0df3 + seg, 0x000c, memory16get(0x0df3 + seg, 0x000c) + seg);
    memory16set(0x0df4 + seg, 0x0000, memory16get(0x0df4 + seg, 0x0000) + seg);
    memory16set(0x0df4 + seg, 0x0004, memory16get(0x0df4 + seg, 0x0004) + seg);
    memory16set(0x0df4 + seg, 0x0008, memory16get(0x0df4 + seg, 0x0008) + seg);
    memory16set(0x0df4 + seg, 0x000c, memory16get(0x0df4 + seg, 0x000c) + seg);
    memory16set(0x0df5 + seg, 0x0000, memory16get(0x0df5 + seg, 0x0000) + seg);
    memory16set(0x0df5 + seg, 0x0004, memory16get(0x0df5 + seg, 0x0004) + seg);
    memory16set(0x0df5 + seg, 0x0008, memory16get(0x0df5 + seg, 0x0008) + seg);
    memory16set(0x0df5 + seg, 0x000c, memory16get(0x0df5 + seg, 0x000c) + seg);
    memory16set(0x0df6 + seg, 0x0000, memory16get(0x0df6 + seg, 0x0000) + seg);
    memory16set(0x0df6 + seg, 0x0004, memory16get(0x0df6 + seg, 0x0004) + seg);
    memory16set(0x0df6 + seg, 0x0008, memory16get(0x0df6 + seg, 0x0008) + seg);
    memory16set(0x0df6 + seg, 0x000c, memory16get(0x0df6 + seg, 0x000c) + seg);
    memory16set(0x0df7 + seg, 0x0000, memory16get(0x0df7 + seg, 0x0000) + seg);
    memory16set(0x0df7 + seg, 0x0004, memory16get(0x0df7 + seg, 0x0004) + seg);
    memory16set(0x0df7 + seg, 0x0008, memory16get(0x0df7 + seg, 0x0008) + seg);
    memory16set(0x0df7 + seg, 0x000c, memory16get(0x0df7 + seg, 0x000c) + seg);
    memory16set(0x0df8 + seg, 0x0000, memory16get(0x0df8 + seg, 0x0000) + seg);
    memory16set(0x0df8 + seg, 0x0004, memory16get(0x0df8 + seg, 0x0004) + seg);
    memory16set(0x0df8 + seg, 0x0008, memory16get(0x0df8 + seg, 0x0008) + seg);
    memory16set(0x0df8 + seg, 0x000c, memory16get(0x0df8 + seg, 0x000c) + seg);
    memory16set(0x0df9 + seg, 0x0000, memory16get(0x0df9 + seg, 0x0000) + seg);
    memory16set(0x0df9 + seg, 0x0004, memory16get(0x0df9 + seg, 0x0004) + seg);
    memory16set(0x0df9 + seg, 0x0008, memory16get(0x0df9 + seg, 0x0008) + seg);
    memory16set(0x0df9 + seg, 0x000c, memory16get(0x0df9 + seg, 0x000c) + seg);
    memory16set(0x0dfa + seg, 0x0000, memory16get(0x0dfa + seg, 0x0000) + seg);
    memory16set(0x0dfa + seg, 0x0004, memory16get(0x0dfa + seg, 0x0004) + seg);
    memory16set(0x0dfa + seg, 0x0008, memory16get(0x0dfa + seg, 0x0008) + seg);
    memory16set(0x0dfa + seg, 0x000c, memory16get(0x0dfa + seg, 0x000c) + seg);
    memory16set(0x0dfb + seg, 0x0000, memory16get(0x0dfb + seg, 0x0000) + seg);
    memory16set(0x0dfb + seg, 0x0004, memory16get(0x0dfb + seg, 0x0004) + seg);
    memory16set(0x0dfb + seg, 0x0008, memory16get(0x0dfb + seg, 0x0008) + seg);
    memory16set(0x0dfb + seg, 0x000c, memory16get(0x0dfb + seg, 0x000c) + seg);
    memory16set(0x0dfc + seg, 0x0000, memory16get(0x0dfc + seg, 0x0000) + seg);
    memory16set(0x0dfc + seg, 0x0004, memory16get(0x0dfc + seg, 0x0004) + seg);
    memory16set(0x0dfc + seg, 0x000c, memory16get(0x0dfc + seg, 0x000c) + seg);
    memory16set(0x0dfd + seg, 0x0000, memory16get(0x0dfd + seg, 0x0000) + seg);
    memory16set(0x0dfd + seg, 0x0004, memory16get(0x0dfd + seg, 0x0004) + seg);
    memory16set(0x0dfd + seg, 0x0008, memory16get(0x0dfd + seg, 0x0008) + seg);
    memory16set(0x0dfd + seg, 0x000c, memory16get(0x0dfd + seg, 0x000c) + seg);
    memory16set(0x0dfe + seg, 0x0000, memory16get(0x0dfe + seg, 0x0000) + seg);
    memory16set(0x0dfe + seg, 0x0004, memory16get(0x0dfe + seg, 0x0004) + seg);
    memory16set(0x0dfe + seg, 0x000a, memory16get(0x0dfe + seg, 0x000a) + seg);
    memory16set(0x0dfe + seg, 0x000e, memory16get(0x0dfe + seg, 0x000e) + seg);
    memory16set(0x0dff + seg, 0x0002, memory16get(0x0dff + seg, 0x0002) + seg);
    memory16set(0x0dff + seg, 0x0006, memory16get(0x0dff + seg, 0x0006) + seg);
    memory16set(0x0dff + seg, 0x000a, memory16get(0x0dff + seg, 0x000a) + seg);
    memory16set(0x0dff + seg, 0x000e, memory16get(0x0dff + seg, 0x000e) + seg);
    memory16set(0x0e00 + seg, 0x0002, memory16get(0x0e00 + seg, 0x0002) + seg);
    memory16set(0x0e00 + seg, 0x0006, memory16get(0x0e00 + seg, 0x0006) + seg);
    memory16set(0x0e00 + seg, 0x000a, memory16get(0x0e00 + seg, 0x000a) + seg);
    memory16set(0x0e00 + seg, 0x000e, memory16get(0x0e00 + seg, 0x000e) + seg);
    memory16set(0x0e01 + seg, 0x0002, memory16get(0x0e01 + seg, 0x0002) + seg);
    memory16set(0x0e01 + seg, 0x0006, memory16get(0x0e01 + seg, 0x0006) + seg);
    memory16set(0x0e01 + seg, 0x000a, memory16get(0x0e01 + seg, 0x000a) + seg);
    memory16set(0x0e01 + seg, 0x000e, memory16get(0x0e01 + seg, 0x000e) + seg);
    memory16set(0x0e02 + seg, 0x0002, memory16get(0x0e02 + seg, 0x0002) + seg);
    memory16set(0x0e02 + seg, 0x0006, memory16get(0x0e02 + seg, 0x0006) + seg);
    memory16set(0x0e02 + seg, 0x000e, memory16get(0x0e02 + seg, 0x000e) + seg);
    memory16set(0x0e03 + seg, 0x0002, memory16get(0x0e03 + seg, 0x0002) + seg);
    memory16set(0x0e03 + seg, 0x0006, memory16get(0x0e03 + seg, 0x0006) + seg);
    memory16set(0x0e03 + seg, 0x000a, memory16get(0x0e03 + seg, 0x000a) + seg);
    memory16set(0x0e03 + seg, 0x000e, memory16get(0x0e03 + seg, 0x000e) + seg);
    memory16set(0x0e04 + seg, 0x0002, memory16get(0x0e04 + seg, 0x0002) + seg);
    memory16set(0x0e04 + seg, 0x0006, memory16get(0x0e04 + seg, 0x0006) + seg);
    memory16set(0x0e04 + seg, 0x000c, memory16get(0x0e04 + seg, 0x000c) + seg);
    memory16set(0x0e05 + seg, 0x0000, memory16get(0x0e05 + seg, 0x0000) + seg);
    memory16set(0x0e05 + seg, 0x0004, memory16get(0x0e05 + seg, 0x0004) + seg);
    memory16set(0x0e05 + seg, 0x0008, memory16get(0x0e05 + seg, 0x0008) + seg);
    memory16set(0x0e05 + seg, 0x000c, memory16get(0x0e05 + seg, 0x000c) + seg);
    memory16set(0x0e06 + seg, 0x0000, memory16get(0x0e06 + seg, 0x0000) + seg);
    memory16set(0x0e06 + seg, 0x0004, memory16get(0x0e06 + seg, 0x0004) + seg);
    memory16set(0x0e06 + seg, 0x0008, memory16get(0x0e06 + seg, 0x0008) + seg);
    memory16set(0x0e06 + seg, 0x000c, memory16get(0x0e06 + seg, 0x000c) + seg);
    memory16set(0x0e07 + seg, 0x0000, memory16get(0x0e07 + seg, 0x0000) + seg);
    memory16set(0x0e07 + seg, 0x0004, memory16get(0x0e07 + seg, 0x0004) + seg);
    memory16set(0x0e07 + seg, 0x0008, memory16get(0x0e07 + seg, 0x0008) + seg);
    memory16set(0x0e07 + seg, 0x000c, memory16get(0x0e07 + seg, 0x000c) + seg);
    memory16set(0x0e08 + seg, 0x0000, memory16get(0x0e08 + seg, 0x0000) + seg);
    memory16set(0x0e08 + seg, 0x0004, memory16get(0x0e08 + seg, 0x0004) + seg);
    memory16set(0x0e08 + seg, 0x0008, memory16get(0x0e08 + seg, 0x0008) + seg);
    memory16set(0x0e09 + seg, 0x0000, memory16get(0x0e09 + seg, 0x0000) + seg);
    memory16set(0x0e09 + seg, 0x0004, memory16get(0x0e09 + seg, 0x0004) + seg);
    memory16set(0x0e09 + seg, 0x0008, memory16get(0x0e09 + seg, 0x0008) + seg);
    memory16set(0x0e09 + seg, 0x000c, memory16get(0x0e09 + seg, 0x000c) + seg);
    memory16set(0x0e0a + seg, 0x0000, memory16get(0x0e0a + seg, 0x0000) + seg);
    memory16set(0x0e0a + seg, 0x0004, memory16get(0x0e0a + seg, 0x0004) + seg);
    memory16set(0x0e0a + seg, 0x0008, memory16get(0x0e0a + seg, 0x0008) + seg);
    memory16set(0x0e0a + seg, 0x000e, memory16get(0x0e0a + seg, 0x000e) + seg);
    memory16set(0x0e0b + seg, 0x0002, memory16get(0x0e0b + seg, 0x0002) + seg);
    memory16set(0x0e0b + seg, 0x0006, memory16get(0x0e0b + seg, 0x0006) + seg);
    memory16set(0x0e0b + seg, 0x000a, memory16get(0x0e0b + seg, 0x000a) + seg);
    memory16set(0x0e0b + seg, 0x000e, memory16get(0x0e0b + seg, 0x000e) + seg);
    memory16set(0x0e0c + seg, 0x0002, memory16get(0x0e0c + seg, 0x0002) + seg);
    memory16set(0x0e0c + seg, 0x0006, memory16get(0x0e0c + seg, 0x0006) + seg);
    memory16set(0x0e0c + seg, 0x000a, memory16get(0x0e0c + seg, 0x000a) + seg);
    memory16set(0x0e0c + seg, 0x000e, memory16get(0x0e0c + seg, 0x000e) + seg);
    memory16set(0x0e0d + seg, 0x0002, memory16get(0x0e0d + seg, 0x0002) + seg);
    memory16set(0x0e0d + seg, 0x0006, memory16get(0x0e0d + seg, 0x0006) + seg);
    memory16set(0x0e0d + seg, 0x000a, memory16get(0x0e0d + seg, 0x000a) + seg);
    memory16set(0x0e0d + seg, 0x000e, memory16get(0x0e0d + seg, 0x000e) + seg);
    memory16set(0x0e0e + seg, 0x0002, memory16get(0x0e0e + seg, 0x0002) + seg);
    memory16set(0x0e0e + seg, 0x0006, memory16get(0x0e0e + seg, 0x0006) + seg);
    memory16set(0x0e0e + seg, 0x000a, memory16get(0x0e0e + seg, 0x000a) + seg);
    memory16set(0x0e0f + seg, 0x0002, memory16get(0x0e0f + seg, 0x0002) + seg);
    memory16set(0x0e0f + seg, 0x0006, memory16get(0x0e0f + seg, 0x0006) + seg);
    memory16set(0x0e0f + seg, 0x000a, memory16get(0x0e0f + seg, 0x000a) + seg);
    memory16set(0x0e0f + seg, 0x000e, memory16get(0x0e0f + seg, 0x000e) + seg);
    memory16set(0x0e10 + seg, 0x0002, memory16get(0x0e10 + seg, 0x0002) + seg);
    memory16set(0x0e10 + seg, 0x0006, memory16get(0x0e10 + seg, 0x0006) + seg);
    memory16set(0x0e10 + seg, 0x000a, memory16get(0x0e10 + seg, 0x000a) + seg);
    memory16set(0x0e11 + seg, 0x0000, memory16get(0x0e11 + seg, 0x0000) + seg);
    memory16set(0x0e11 + seg, 0x0004, memory16get(0x0e11 + seg, 0x0004) + seg);
    memory16set(0x0e11 + seg, 0x0008, memory16get(0x0e11 + seg, 0x0008) + seg);
    memory16set(0x0e11 + seg, 0x000c, memory16get(0x0e11 + seg, 0x000c) + seg);
    memory16set(0x0e12 + seg, 0x0000, memory16get(0x0e12 + seg, 0x0000) + seg);
    memory16set(0x0e12 + seg, 0x0004, memory16get(0x0e12 + seg, 0x0004) + seg);
    memory16set(0x0e12 + seg, 0x0008, memory16get(0x0e12 + seg, 0x0008) + seg);
    memory16set(0x0e12 + seg, 0x000c, memory16get(0x0e12 + seg, 0x000c) + seg);
    memory16set(0x0e13 + seg, 0x0000, memory16get(0x0e13 + seg, 0x0000) + seg);
    memory16set(0x0e13 + seg, 0x0004, memory16get(0x0e13 + seg, 0x0004) + seg);
    memory16set(0x0e13 + seg, 0x0008, memory16get(0x0e13 + seg, 0x0008) + seg);
    memory16set(0x0e13 + seg, 0x000c, memory16get(0x0e13 + seg, 0x000c) + seg);
    memory16set(0x0e14 + seg, 0x0000, memory16get(0x0e14 + seg, 0x0000) + seg);
    memory16set(0x0e14 + seg, 0x0004, memory16get(0x0e14 + seg, 0x0004) + seg);
    memory16set(0x0e14 + seg, 0x0008, memory16get(0x0e14 + seg, 0x0008) + seg);
    memory16set(0x0e14 + seg, 0x000c, memory16get(0x0e14 + seg, 0x000c) + seg);
    memory16set(0x0e15 + seg, 0x0004, memory16get(0x0e15 + seg, 0x0004) + seg);
    memory16set(0x0e15 + seg, 0x0008, memory16get(0x0e15 + seg, 0x0008) + seg);
    memory16set(0x0e15 + seg, 0x000c, memory16get(0x0e15 + seg, 0x000c) + seg);
    memory16set(0x0e16 + seg, 0x0000, memory16get(0x0e16 + seg, 0x0000) + seg);
    memory16set(0x0e16 + seg, 0x0004, memory16get(0x0e16 + seg, 0x0004) + seg);
    memory16set(0x0e16 + seg, 0x0008, memory16get(0x0e16 + seg, 0x0008) + seg);
    memory16set(0x0e16 + seg, 0x000c, memory16get(0x0e16 + seg, 0x000c) + seg);
    memory16set(0x0e17 + seg, 0x0002, memory16get(0x0e17 + seg, 0x0002) + seg);
    memory16set(0x0e17 + seg, 0x0006, memory16get(0x0e17 + seg, 0x0006) + seg);
    memory16set(0x0e17 + seg, 0x000a, memory16get(0x0e17 + seg, 0x000a) + seg);
    memory16set(0x0e17 + seg, 0x000e, memory16get(0x0e17 + seg, 0x000e) + seg);
    memory16set(0x0e18 + seg, 0x0002, memory16get(0x0e18 + seg, 0x0002) + seg);
    memory16set(0x0e18 + seg, 0x0006, memory16get(0x0e18 + seg, 0x0006) + seg);
    memory16set(0x0e18 + seg, 0x000a, memory16get(0x0e18 + seg, 0x000a) + seg);
    memory16set(0x0e18 + seg, 0x000e, memory16get(0x0e18 + seg, 0x000e) + seg);
    memory16set(0x0e19 + seg, 0x0002, memory16get(0x0e19 + seg, 0x0002) + seg);
    memory16set(0x0e19 + seg, 0x0006, memory16get(0x0e19 + seg, 0x0006) + seg);
    memory16set(0x0e19 + seg, 0x000a, memory16get(0x0e19 + seg, 0x000a) + seg);
    memory16set(0x0e19 + seg, 0x000e, memory16get(0x0e19 + seg, 0x000e) + seg);
    memory16set(0x0e1a + seg, 0x0002, memory16get(0x0e1a + seg, 0x0002) + seg);
    memory16set(0x0e1a + seg, 0x0006, memory16get(0x0e1a + seg, 0x0006) + seg);
    memory16set(0x0e1a + seg, 0x000a, memory16get(0x0e1a + seg, 0x000a) + seg);
    memory16set(0x0e1a + seg, 0x000e, memory16get(0x0e1a + seg, 0x000e) + seg);
    memory16set(0x0e1b + seg, 0x0006, memory16get(0x0e1b + seg, 0x0006) + seg);
    memory16set(0x0e1b + seg, 0x000a, memory16get(0x0e1b + seg, 0x000a) + seg);
    memory16set(0x0e1b + seg, 0x000e, memory16get(0x0e1b + seg, 0x000e) + seg);
    memory16set(0x0e1c + seg, 0x0002, memory16get(0x0e1c + seg, 0x0002) + seg);
    memory16set(0x0e1c + seg, 0x0006, memory16get(0x0e1c + seg, 0x0006) + seg);
    memory16set(0x0e1c + seg, 0x000a, memory16get(0x0e1c + seg, 0x000a) + seg);
    memory16set(0x0e1c + seg, 0x000e, memory16get(0x0e1c + seg, 0x000e) + seg);
    memory16set(0x0e1d + seg, 0x0004, memory16get(0x0e1d + seg, 0x0004) + seg);
    memory16set(0x0e1d + seg, 0x0008, memory16get(0x0e1d + seg, 0x0008) + seg);
    memory16set(0x0e1d + seg, 0x000c, memory16get(0x0e1d + seg, 0x000c) + seg);
    memory16set(0x0e1e + seg, 0x0000, memory16get(0x0e1e + seg, 0x0000) + seg);
    memory16set(0x0e1e + seg, 0x0004, memory16get(0x0e1e + seg, 0x0004) + seg);
    memory16set(0x0e1e + seg, 0x0008, memory16get(0x0e1e + seg, 0x0008) + seg);
    memory16set(0x0e1e + seg, 0x000c, memory16get(0x0e1e + seg, 0x000c) + seg);
    memory16set(0x0e1f + seg, 0x0000, memory16get(0x0e1f + seg, 0x0000) + seg);
    memory16set(0x0e1f + seg, 0x0004, memory16get(0x0e1f + seg, 0x0004) + seg);
    memory16set(0x0e1f + seg, 0x0008, memory16get(0x0e1f + seg, 0x0008) + seg);
    memory16set(0x0e1f + seg, 0x000c, memory16get(0x0e1f + seg, 0x000c) + seg);
    memory16set(0x0e20 + seg, 0x0000, memory16get(0x0e20 + seg, 0x0000) + seg);
    memory16set(0x0e20 + seg, 0x0004, memory16get(0x0e20 + seg, 0x0004) + seg);
    memory16set(0x0e20 + seg, 0x0008, memory16get(0x0e20 + seg, 0x0008) + seg);
    memory16set(0x0e20 + seg, 0x000c, memory16get(0x0e20 + seg, 0x000c) + seg);
    memory16set(0x0e21 + seg, 0x0000, memory16get(0x0e21 + seg, 0x0000) + seg);
    memory16set(0x0e21 + seg, 0x0008, memory16get(0x0e21 + seg, 0x0008) + seg);
    memory16set(0x0e21 + seg, 0x000c, memory16get(0x0e21 + seg, 0x000c) + seg);
    memory16set(0x0e22 + seg, 0x0000, memory16get(0x0e22 + seg, 0x0000) + seg);
    memory16set(0x0e22 + seg, 0x0004, memory16get(0x0e22 + seg, 0x0004) + seg);
    memory16set(0x0e22 + seg, 0x0008, memory16get(0x0e22 + seg, 0x0008) + seg);
    memory16set(0x0e22 + seg, 0x000c, memory16get(0x0e22 + seg, 0x000c) + seg);
    memory16set(0x0e23 + seg, 0x0000, memory16get(0x0e23 + seg, 0x0000) + seg);
    memory16set(0x0e23 + seg, 0x0006, memory16get(0x0e23 + seg, 0x0006) + seg);
    memory16set(0x0e23 + seg, 0x000a, memory16get(0x0e23 + seg, 0x000a) + seg);
    memory16set(0x0e23 + seg, 0x000e, memory16get(0x0e23 + seg, 0x000e) + seg);
    memory16set(0x0e24 + seg, 0x0002, memory16get(0x0e24 + seg, 0x0002) + seg);
    memory16set(0x0e24 + seg, 0x000a, memory16get(0x0e24 + seg, 0x000a) + seg);
    memory16set(0x0e24 + seg, 0x000e, memory16get(0x0e24 + seg, 0x000e) + seg);
    memory16set(0x0e25 + seg, 0x0002, memory16get(0x0e25 + seg, 0x0002) + seg);
    memory16set(0x0e25 + seg, 0x0006, memory16get(0x0e25 + seg, 0x0006) + seg);
    memory16set(0x0e25 + seg, 0x000a, memory16get(0x0e25 + seg, 0x000a) + seg);
    memory16set(0x0e25 + seg, 0x000e, memory16get(0x0e25 + seg, 0x000e) + seg);
    memory16set(0x0e26 + seg, 0x0002, memory16get(0x0e26 + seg, 0x0002) + seg);
    memory16set(0x0e26 + seg, 0x0008, memory16get(0x0e26 + seg, 0x0008) + seg);
    memory16set(0x0e26 + seg, 0x000c, memory16get(0x0e26 + seg, 0x000c) + seg);
    memory16set(0x0e27 + seg, 0x0000, memory16get(0x0e27 + seg, 0x0000) + seg);
    memory16set(0x0e27 + seg, 0x0004, memory16get(0x0e27 + seg, 0x0004) + seg);
    memory16set(0x0e27 + seg, 0x0008, memory16get(0x0e27 + seg, 0x0008) + seg);
    memory16set(0x0e27 + seg, 0x000c, memory16get(0x0e27 + seg, 0x000c) + seg);
    memory16set(0x0e28 + seg, 0x0000, memory16get(0x0e28 + seg, 0x0000) + seg);
    memory16set(0x0e28 + seg, 0x0004, memory16get(0x0e28 + seg, 0x0004) + seg);
    memory16set(0x0e28 + seg, 0x0008, memory16get(0x0e28 + seg, 0x0008) + seg);
    memory16set(0x0e28 + seg, 0x000c, memory16get(0x0e28 + seg, 0x000c) + seg);
    memory16set(0x0e29 + seg, 0x0000, memory16get(0x0e29 + seg, 0x0000) + seg);
    memory16set(0x0e29 + seg, 0x0004, memory16get(0x0e29 + seg, 0x0004) + seg);
    memory16set(0x0e29 + seg, 0x0008, memory16get(0x0e29 + seg, 0x0008) + seg);
    memory16set(0x0e29 + seg, 0x000c, memory16get(0x0e29 + seg, 0x000c) + seg);
    memory16set(0x0e2a + seg, 0x0000, memory16get(0x0e2a + seg, 0x0000) + seg);
    memory16set(0x0e2a + seg, 0x0004, memory16get(0x0e2a + seg, 0x0004) + seg);
    memory16set(0x0e2a + seg, 0x000c, memory16get(0x0e2a + seg, 0x000c) + seg);
    memory16set(0x0e2b + seg, 0x0000, memory16get(0x0e2b + seg, 0x0000) + seg);
    memory16set(0x0e2b + seg, 0x0004, memory16get(0x0e2b + seg, 0x0004) + seg);
    memory16set(0x0e2b + seg, 0x0008, memory16get(0x0e2b + seg, 0x0008) + seg);
    memory16set(0x0e2b + seg, 0x000c, memory16get(0x0e2b + seg, 0x000c) + seg);
    memory16set(0x0e2c + seg, 0x0000, memory16get(0x0e2c + seg, 0x0000) + seg);
    memory16set(0x0e2c + seg, 0x0004, memory16get(0x0e2c + seg, 0x0004) + seg);
    memory16set(0x0e2c + seg, 0x000a, memory16get(0x0e2c + seg, 0x000a) + seg);
    memory16set(0x0e2c + seg, 0x000e, memory16get(0x0e2c + seg, 0x000e) + seg);
    memory16set(0x0e2d + seg, 0x0002, memory16get(0x0e2d + seg, 0x0002) + seg);
    memory16set(0x0e2d + seg, 0x0006, memory16get(0x0e2d + seg, 0x0006) + seg);
    memory16set(0x0e2d + seg, 0x000a, memory16get(0x0e2d + seg, 0x000a) + seg);
    memory16set(0x0e2d + seg, 0x000e, memory16get(0x0e2d + seg, 0x000e) + seg);
    memory16set(0x0e2e + seg, 0x0002, memory16get(0x0e2e + seg, 0x0002) + seg);
    memory16set(0x0e2e + seg, 0x0006, memory16get(0x0e2e + seg, 0x0006) + seg);
    memory16set(0x0e2e + seg, 0x000a, memory16get(0x0e2e + seg, 0x000a) + seg);
    memory16set(0x0e2e + seg, 0x000e, memory16get(0x0e2e + seg, 0x000e) + seg);
    memory16set(0x0e2f + seg, 0x0002, memory16get(0x0e2f + seg, 0x0002) + seg);
    memory16set(0x0e2f + seg, 0x0006, memory16get(0x0e2f + seg, 0x0006) + seg);
    memory16set(0x0e2f + seg, 0x000a, memory16get(0x0e2f + seg, 0x000a) + seg);
    memory16set(0x0e2f + seg, 0x000e, memory16get(0x0e2f + seg, 0x000e) + seg);
    memory16set(0x0e30 + seg, 0x0002, memory16get(0x0e30 + seg, 0x0002) + seg);
    memory16set(0x0e30 + seg, 0x0006, memory16get(0x0e30 + seg, 0x0006) + seg);
    memory16set(0x0e30 + seg, 0x000e, memory16get(0x0e30 + seg, 0x000e) + seg);
    memory16set(0x0e31 + seg, 0x0002, memory16get(0x0e31 + seg, 0x0002) + seg);
    memory16set(0x0e31 + seg, 0x0006, memory16get(0x0e31 + seg, 0x0006) + seg);
    memory16set(0x0e31 + seg, 0x000a, memory16get(0x0e31 + seg, 0x000a) + seg);
    memory16set(0x0e31 + seg, 0x000e, memory16get(0x0e31 + seg, 0x000e) + seg);
    memory16set(0x0e32 + seg, 0x0002, memory16get(0x0e32 + seg, 0x0002) + seg);
    memory16set(0x0e32 + seg, 0x0006, memory16get(0x0e32 + seg, 0x0006) + seg);
    memory16set(0x0e32 + seg, 0x000c, memory16get(0x0e32 + seg, 0x000c) + seg);
    memory16set(0x0e33 + seg, 0x0000, memory16get(0x0e33 + seg, 0x0000) + seg);
    memory16set(0x0e33 + seg, 0x0004, memory16get(0x0e33 + seg, 0x0004) + seg);
    memory16set(0x0e33 + seg, 0x0008, memory16get(0x0e33 + seg, 0x0008) + seg);
    memory16set(0x0e33 + seg, 0x000c, memory16get(0x0e33 + seg, 0x000c) + seg);
    memory16set(0x0e34 + seg, 0x0000, memory16get(0x0e34 + seg, 0x0000) + seg);
    memory16set(0x0e34 + seg, 0x0004, memory16get(0x0e34 + seg, 0x0004) + seg);
    memory16set(0x0e34 + seg, 0x0008, memory16get(0x0e34 + seg, 0x0008) + seg);
    memory16set(0x0e34 + seg, 0x000c, memory16get(0x0e34 + seg, 0x000c) + seg);
    memory16set(0x0e35 + seg, 0x0000, memory16get(0x0e35 + seg, 0x0000) + seg);
    memory16set(0x0e35 + seg, 0x0004, memory16get(0x0e35 + seg, 0x0004) + seg);
    memory16set(0x0e35 + seg, 0x0008, memory16get(0x0e35 + seg, 0x0008) + seg);
    memory16set(0x0e35 + seg, 0x000c, memory16get(0x0e35 + seg, 0x000c) + seg);
    memory16set(0x0e36 + seg, 0x0000, memory16get(0x0e36 + seg, 0x0000) + seg);
    memory16set(0x0e36 + seg, 0x0004, memory16get(0x0e36 + seg, 0x0004) + seg);
    memory16set(0x0e36 + seg, 0x0008, memory16get(0x0e36 + seg, 0x0008) + seg);
    memory16set(0x0e37 + seg, 0x0000, memory16get(0x0e37 + seg, 0x0000) + seg);
    memory16set(0x0e37 + seg, 0x0004, memory16get(0x0e37 + seg, 0x0004) + seg);
    memory16set(0x0e37 + seg, 0x0008, memory16get(0x0e37 + seg, 0x0008) + seg);
    memory16set(0x0e37 + seg, 0x000c, memory16get(0x0e37 + seg, 0x000c) + seg);
    memory16set(0x0e38 + seg, 0x0000, memory16get(0x0e38 + seg, 0x0000) + seg);
    memory16set(0x0e38 + seg, 0x0004, memory16get(0x0e38 + seg, 0x0004) + seg);
    memory16set(0x0e38 + seg, 0x0008, memory16get(0x0e38 + seg, 0x0008) + seg);
    memory16set(0x0e3b + seg, 0x000e, memory16get(0x0e3b + seg, 0x000e) + seg);
    memory16set(0x0e3c + seg, 0x0002, memory16get(0x0e3c + seg, 0x0002) + seg);
    memory16set(0x0e3e + seg, 0x0002, memory16get(0x0e3e + seg, 0x0002) + seg);
    memory16set(0x0e3e + seg, 0x0006, memory16get(0x0e3e + seg, 0x0006) + seg);
    memory16set(0x0e40 + seg, 0x0006, memory16get(0x0e40 + seg, 0x0006) + seg);
    memory16set(0x0e40 + seg, 0x000a, memory16get(0x0e40 + seg, 0x000a) + seg);
    memory16set(0x0e42 + seg, 0x000a, memory16get(0x0e42 + seg, 0x000a) + seg);
    memory16set(0x0e42 + seg, 0x000e, memory16get(0x0e42 + seg, 0x000e) + seg);
    memory16set(0x0e44 + seg, 0x000e, memory16get(0x0e44 + seg, 0x000e) + seg);
    memory16set(0x0e45 + seg, 0x0002, memory16get(0x0e45 + seg, 0x0002) + seg);
    memory16set(0x0e47 + seg, 0x0002, memory16get(0x0e47 + seg, 0x0002) + seg);
    memory16set(0x0e47 + seg, 0x0006, memory16get(0x0e47 + seg, 0x0006) + seg);
    memory16set(0x0e49 + seg, 0x0006, memory16get(0x0e49 + seg, 0x0006) + seg);
    memory16set(0x0e49 + seg, 0x000a, memory16get(0x0e49 + seg, 0x000a) + seg);
    memory16set(0x0e4b + seg, 0x000a, memory16get(0x0e4b + seg, 0x000a) + seg);
    memory16set(0x0e4b + seg, 0x000e, memory16get(0x0e4b + seg, 0x000e) + seg);
    memory16set(0x0e4d + seg, 0x000e, memory16get(0x0e4d + seg, 0x000e) + seg);
    memory16set(0x0e4e + seg, 0x0002, memory16get(0x0e4e + seg, 0x0002) + seg);
    memory16set(0x0e50 + seg, 0x0002, memory16get(0x0e50 + seg, 0x0002) + seg);
    memory16set(0x0e50 + seg, 0x0006, memory16get(0x0e50 + seg, 0x0006) + seg);
    memory16set(0x0e52 + seg, 0x0006, memory16get(0x0e52 + seg, 0x0006) + seg);
    memory16set(0x0e52 + seg, 0x000a, memory16get(0x0e52 + seg, 0x000a) + seg);
    memory16set(0x0e54 + seg, 0x000a, memory16get(0x0e54 + seg, 0x000a) + seg);
    memory16set(0x0e54 + seg, 0x000e, memory16get(0x0e54 + seg, 0x000e) + seg);
    memory16set(0x0e56 + seg, 0x000e, memory16get(0x0e56 + seg, 0x000e) + seg);
    memory16set(0x0e57 + seg, 0x0002, memory16get(0x0e57 + seg, 0x0002) + seg);
    memory16set(0x0e59 + seg, 0x0002, memory16get(0x0e59 + seg, 0x0002) + seg);
    memory16set(0x0e59 + seg, 0x0006, memory16get(0x0e59 + seg, 0x0006) + seg);
    memory16set(0x0e5b + seg, 0x0006, memory16get(0x0e5b + seg, 0x0006) + seg);
    memory16set(0x0e5b + seg, 0x000a, memory16get(0x0e5b + seg, 0x000a) + seg);
    memory16set(0x0ed0 + seg, 0x0002, memory16get(0x0ed0 + seg, 0x0002) + seg);
    memory16set(0x0ed3 + seg, 0x0008, memory16get(0x0ed3 + seg, 0x0008) + seg);
    memory16set(0x0ed4 + seg, 0x000c, memory16get(0x0ed4 + seg, 0x000c) + seg);
    memory16set(0x0ed6 + seg, 0x0000, memory16get(0x0ed6 + seg, 0x0000) + seg);
    memory16set(0x0ed7 + seg, 0x0004, memory16get(0x0ed7 + seg, 0x0004) + seg);
    memory16set(0x0ed8 + seg, 0x0008, memory16get(0x0ed8 + seg, 0x0008) + seg);
    memory16set(0x0ed9 + seg, 0x000c, memory16get(0x0ed9 + seg, 0x000c) + seg);
    memory16set(0x0edb + seg, 0x0000, memory16get(0x0edb + seg, 0x0000) + seg);
    memory16set(0x0edc + seg, 0x0004, memory16get(0x0edc + seg, 0x0004) + seg);
    memory16set(0x0edd + seg, 0x0008, memory16get(0x0edd + seg, 0x0008) + seg);
    memory16set(0x0ede + seg, 0x000b, memory16get(0x0ede + seg, 0x000b) + seg);
    memory16set(0x0edf + seg, 0x000e, memory16get(0x0edf + seg, 0x000e) + seg);
    memory16set(0x0ee1 + seg, 0x0001, memory16get(0x0ee1 + seg, 0x0001) + seg);
    memory16set(0x0ee2 + seg, 0x0004, memory16get(0x0ee2 + seg, 0x0004) + seg);
    memory16set(0x0ee3 + seg, 0x0007, memory16get(0x0ee3 + seg, 0x0007) + seg);
    memory16set(0x0ee4 + seg, 0x000a, memory16get(0x0ee4 + seg, 0x000a) + seg);
    memory16set(0x0ee5 + seg, 0x000d, memory16get(0x0ee5 + seg, 0x000d) + seg);
    memory16set(0x0ee7 + seg, 0x0000, memory16get(0x0ee7 + seg, 0x0000) + seg);
    memory16set(0x0ee8 + seg, 0x0003, memory16get(0x0ee8 + seg, 0x0003) + seg);
    memory16set(0x0ee9 + seg, 0x0006, memory16get(0x0ee9 + seg, 0x0006) + seg);
    memory16set(0x0eea + seg, 0x0008, memory16get(0x0eea + seg, 0x0008) + seg);
    memory16set(0x0eeb + seg, 0x0002, memory16get(0x0eeb + seg, 0x0002) + seg);
    memory16set(0x0eeb + seg, 0x000c, memory16get(0x0eeb + seg, 0x000c) + seg);
    memory16set(0x0eec + seg, 0x0004, memory16get(0x0eec + seg, 0x0004) + seg);
    memory16set(0x0eec + seg, 0x000c, memory16get(0x0eec + seg, 0x000c) + seg);
    memory16set(0x0eed + seg, 0x0004, memory16get(0x0eed + seg, 0x0004) + seg);
    memory16set(0x0eed + seg, 0x000c, memory16get(0x0eed + seg, 0x000c) + seg);
    memory16set(0x0eee + seg, 0x0004, memory16get(0x0eee + seg, 0x0004) + seg);
    memory16set(0x0eee + seg, 0x000c, memory16get(0x0eee + seg, 0x000c) + seg);
    memory16set(0x0eef + seg, 0x0004, memory16get(0x0eef + seg, 0x0004) + seg);
    memory16set(0x0eef + seg, 0x000c, memory16get(0x0eef + seg, 0x000c) + seg);
    memory16set(0x0ef0 + seg, 0x0004, memory16get(0x0ef0 + seg, 0x0004) + seg);
    memory16set(0x0ef0 + seg, 0x000c, memory16get(0x0ef0 + seg, 0x000c) + seg);
    memory16set(0x0ef1 + seg, 0x0004, memory16get(0x0ef1 + seg, 0x0004) + seg);
    memory16set(0x0ef1 + seg, 0x000c, memory16get(0x0ef1 + seg, 0x000c) + seg);
    memory16set(0x0ef2 + seg, 0x0004, memory16get(0x0ef2 + seg, 0x0004) + seg);
    memory16set(0x0ef2 + seg, 0x000c, memory16get(0x0ef2 + seg, 0x000c) + seg);
    memory16set(0x0ef3 + seg, 0x0004, memory16get(0x0ef3 + seg, 0x0004) + seg);
    memory16set(0x0ef3 + seg, 0x000c, memory16get(0x0ef3 + seg, 0x000c) + seg);
    memory16set(0x0ef4 + seg, 0x0004, memory16get(0x0ef4 + seg, 0x0004) + seg);
    memory16set(0x0ef4 + seg, 0x000c, memory16get(0x0ef4 + seg, 0x000c) + seg);
    memory16set(0x0ef5 + seg, 0x0004, memory16get(0x0ef5 + seg, 0x0004) + seg);
    memory16set(0x0ef5 + seg, 0x000c, memory16get(0x0ef5 + seg, 0x000c) + seg);
    memory16set(0x0ef6 + seg, 0x0004, memory16get(0x0ef6 + seg, 0x0004) + seg);
    memory16set(0x0ef6 + seg, 0x000c, memory16get(0x0ef6 + seg, 0x000c) + seg);
    memory16set(0x0ef7 + seg, 0x0004, memory16get(0x0ef7 + seg, 0x0004) + seg);
    memory16set(0x0ef7 + seg, 0x000c, memory16get(0x0ef7 + seg, 0x000c) + seg);
    memory16set(0x0ef8 + seg, 0x0004, memory16get(0x0ef8 + seg, 0x0004) + seg);
    memory16set(0x0ef8 + seg, 0x000c, memory16get(0x0ef8 + seg, 0x000c) + seg);
    memory16set(0x0ef9 + seg, 0x0004, memory16get(0x0ef9 + seg, 0x0004) + seg);
    memory16set(0x0ef9 + seg, 0x000c, memory16get(0x0ef9 + seg, 0x000c) + seg);
    memory16set(0x0efa + seg, 0x0004, memory16get(0x0efa + seg, 0x0004) + seg);
    memory16set(0x0efa + seg, 0x000c, memory16get(0x0efa + seg, 0x000c) + seg);
    memory16set(0x0efb + seg, 0x0004, memory16get(0x0efb + seg, 0x0004) + seg);
    memory16set(0x0efb + seg, 0x000c, memory16get(0x0efb + seg, 0x000c) + seg);
    memory16set(0x0efc + seg, 0x0004, memory16get(0x0efc + seg, 0x0004) + seg);
    memory16set(0x0efc + seg, 0x000c, memory16get(0x0efc + seg, 0x000c) + seg);
    memory16set(0x0efd + seg, 0x0004, memory16get(0x0efd + seg, 0x0004) + seg);
    memory16set(0x0efd + seg, 0x000c, memory16get(0x0efd + seg, 0x000c) + seg);
    memory16set(0x0efe + seg, 0x0004, memory16get(0x0efe + seg, 0x0004) + seg);
    memory16set(0x0efe + seg, 0x000c, memory16get(0x0efe + seg, 0x000c) + seg);
    memory16set(0x0eff + seg, 0x0004, memory16get(0x0eff + seg, 0x0004) + seg);
    memory16set(0x0eff + seg, 0x000e, memory16get(0x0eff + seg, 0x000e) + seg);
    memory16set(0x0f00 + seg, 0x0006, memory16get(0x0f00 + seg, 0x0006) + seg);
    memory16set(0x0f00 + seg, 0x000e, memory16get(0x0f00 + seg, 0x000e) + seg);
    memory16set(0x0f01 + seg, 0x0006, memory16get(0x0f01 + seg, 0x0006) + seg);
    memory16set(0x0f01 + seg, 0x000e, memory16get(0x0f01 + seg, 0x000e) + seg);
    memory16set(0x0f02 + seg, 0x0006, memory16get(0x0f02 + seg, 0x0006) + seg);
    memory16set(0x0f02 + seg, 0x000e, memory16get(0x0f02 + seg, 0x000e) + seg);
    memory16set(0x0f03 + seg, 0x0006, memory16get(0x0f03 + seg, 0x0006) + seg);
    memory16set(0x0f03 + seg, 0x000e, memory16get(0x0f03 + seg, 0x000e) + seg);
    memory16set(0x0f04 + seg, 0x0006, memory16get(0x0f04 + seg, 0x0006) + seg);
    memory16set(0x0f04 + seg, 0x000e, memory16get(0x0f04 + seg, 0x000e) + seg);
    memory16set(0x0f05 + seg, 0x0006, memory16get(0x0f05 + seg, 0x0006) + seg);
    memory16set(0x0f05 + seg, 0x000e, memory16get(0x0f05 + seg, 0x000e) + seg);
    memory16set(0x0f06 + seg, 0x0006, memory16get(0x0f06 + seg, 0x0006) + seg);
    memory16set(0x0f06 + seg, 0x000e, memory16get(0x0f06 + seg, 0x000e) + seg);
    memory16set(0x0f07 + seg, 0x0006, memory16get(0x0f07 + seg, 0x0006) + seg);
    memory16set(0x0f07 + seg, 0x000e, memory16get(0x0f07 + seg, 0x000e) + seg);
    memory16set(0x0f08 + seg, 0x0006, memory16get(0x0f08 + seg, 0x0006) + seg);
    memory16set(0x0f08 + seg, 0x000e, memory16get(0x0f08 + seg, 0x000e) + seg);
    memory16set(0x0f09 + seg, 0x0006, memory16get(0x0f09 + seg, 0x0006) + seg);
    memory16set(0x0f09 + seg, 0x000e, memory16get(0x0f09 + seg, 0x000e) + seg);
    memory16set(0x0f0a + seg, 0x0006, memory16get(0x0f0a + seg, 0x0006) + seg);
    memory16set(0x0f0a + seg, 0x000e, memory16get(0x0f0a + seg, 0x000e) + seg);
    memory16set(0x0f0b + seg, 0x0006, memory16get(0x0f0b + seg, 0x0006) + seg);
    memory16set(0x0f0b + seg, 0x000e, memory16get(0x0f0b + seg, 0x000e) + seg);
    memory16set(0x0f0c + seg, 0x0006, memory16get(0x0f0c + seg, 0x0006) + seg);
    memory16set(0x0f0c + seg, 0x000e, memory16get(0x0f0c + seg, 0x000e) + seg);
    memory16set(0x0f0d + seg, 0x0006, memory16get(0x0f0d + seg, 0x0006) + seg);
    memory16set(0x0f0d + seg, 0x000e, memory16get(0x0f0d + seg, 0x000e) + seg);
    memory16set(0x0f0e + seg, 0x0006, memory16get(0x0f0e + seg, 0x0006) + seg);
    memory16set(0x0f0e + seg, 0x000e, memory16get(0x0f0e + seg, 0x000e) + seg);
    memory16set(0x0f0f + seg, 0x0006, memory16get(0x0f0f + seg, 0x0006) + seg);
    memory16set(0x0f0f + seg, 0x000e, memory16get(0x0f0f + seg, 0x000e) + seg);
    memory16set(0x0f10 + seg, 0x0006, memory16get(0x0f10 + seg, 0x0006) + seg);
    memory16set(0x0f10 + seg, 0x000e, memory16get(0x0f10 + seg, 0x000e) + seg);
    memory16set(0x0f11 + seg, 0x0006, memory16get(0x0f11 + seg, 0x0006) + seg);
    memory16set(0x0f11 + seg, 0x000e, memory16get(0x0f11 + seg, 0x000e) + seg);
    memory16set(0x0f12 + seg, 0x0006, memory16get(0x0f12 + seg, 0x0006) + seg);
    memory16set(0x0f12 + seg, 0x000e, memory16get(0x0f12 + seg, 0x000e) + seg);
    memory16set(0x0f13 + seg, 0x0006, memory16get(0x0f13 + seg, 0x0006) + seg);
    memory16set(0x0f13 + seg, 0x000e, memory16get(0x0f13 + seg, 0x000e) + seg);
    memory16set(0x0f14 + seg, 0x0006, memory16get(0x0f14 + seg, 0x0006) + seg);
    memory16set(0x0f14 + seg, 0x000e, memory16get(0x0f14 + seg, 0x000e) + seg);
    memory16set(0x0f15 + seg, 0x0006, memory16get(0x0f15 + seg, 0x0006) + seg);
    memory16set(0x0f15 + seg, 0x000e, memory16get(0x0f15 + seg, 0x000e) + seg);
    memory16set(0x0f16 + seg, 0x0006, memory16get(0x0f16 + seg, 0x0006) + seg);
    memory16set(0x0f16 + seg, 0x000e, memory16get(0x0f16 + seg, 0x000e) + seg);
    memory16set(0x0f17 + seg, 0x0006, memory16get(0x0f17 + seg, 0x0006) + seg);
    memory16set(0x0f17 + seg, 0x000e, memory16get(0x0f17 + seg, 0x000e) + seg);
    memory16set(0x0f18 + seg, 0x0006, memory16get(0x0f18 + seg, 0x0006) + seg);
    memory16set(0x0f18 + seg, 0x000e, memory16get(0x0f18 + seg, 0x000e) + seg);
    memory16set(0x0f19 + seg, 0x0006, memory16get(0x0f19 + seg, 0x0006) + seg);
    memory16set(0x0f19 + seg, 0x000e, memory16get(0x0f19 + seg, 0x000e) + seg);
    memory16set(0x0f1a + seg, 0x0006, memory16get(0x0f1a + seg, 0x0006) + seg);
    memory16set(0x0f1a + seg, 0x000e, memory16get(0x0f1a + seg, 0x000e) + seg);
    memory16set(0x0f1b + seg, 0x0006, memory16get(0x0f1b + seg, 0x0006) + seg);
    memory16set(0x0f1b + seg, 0x000e, memory16get(0x0f1b + seg, 0x000e) + seg);
    memory16set(0x0f1c + seg, 0x0006, memory16get(0x0f1c + seg, 0x0006) + seg);
    memory16set(0x0f1c + seg, 0x000e, memory16get(0x0f1c + seg, 0x000e) + seg);
    memory16set(0x0f1d + seg, 0x0006, memory16get(0x0f1d + seg, 0x0006) + seg);
    memory16set(0x0f1d + seg, 0x000e, memory16get(0x0f1d + seg, 0x000e) + seg);
    memory16set(0x0f1e + seg, 0x0006, memory16get(0x0f1e + seg, 0x0006) + seg);
    memory16set(0x0f1e + seg, 0x000e, memory16get(0x0f1e + seg, 0x000e) + seg);
    memory16set(0x0f1f + seg, 0x0006, memory16get(0x0f1f + seg, 0x0006) + seg);
    memory16set(0x0f1f + seg, 0x000e, memory16get(0x0f1f + seg, 0x000e) + seg);
    memory16set(0x0f20 + seg, 0x0006, memory16get(0x0f20 + seg, 0x0006) + seg);
    memory16set(0x0f20 + seg, 0x000e, memory16get(0x0f20 + seg, 0x000e) + seg);
    memory16set(0x0f21 + seg, 0x0006, memory16get(0x0f21 + seg, 0x0006) + seg);
    memory16set(0x0f21 + seg, 0x000e, memory16get(0x0f21 + seg, 0x000e) + seg);
    memory16set(0x0f22 + seg, 0x0006, memory16get(0x0f22 + seg, 0x0006) + seg);
    memory16set(0x0f22 + seg, 0x000e, memory16get(0x0f22 + seg, 0x000e) + seg);
    memory16set(0x0f23 + seg, 0x0006, memory16get(0x0f23 + seg, 0x0006) + seg);
    memory16set(0x0f23 + seg, 0x000e, memory16get(0x0f23 + seg, 0x000e) + seg);
    memory16set(0x0f24 + seg, 0x0006, memory16get(0x0f24 + seg, 0x0006) + seg);
    memory16set(0x0f24 + seg, 0x000e, memory16get(0x0f24 + seg, 0x000e) + seg);
    memory16set(0x0f25 + seg, 0x0006, memory16get(0x0f25 + seg, 0x0006) + seg);
    memory16set(0x0f25 + seg, 0x000e, memory16get(0x0f25 + seg, 0x000e) + seg);
    memory16set(0x0f26 + seg, 0x0006, memory16get(0x0f26 + seg, 0x0006) + seg);
    memory16set(0x0f26 + seg, 0x000e, memory16get(0x0f26 + seg, 0x000e) + seg);
    memory16set(0x0f27 + seg, 0x0006, memory16get(0x0f27 + seg, 0x0006) + seg);
    memory16set(0x0f27 + seg, 0x000e, memory16get(0x0f27 + seg, 0x000e) + seg);
    memory16set(0x0f28 + seg, 0x0006, memory16get(0x0f28 + seg, 0x0006) + seg);
    memory16set(0x0f28 + seg, 0x000e, memory16get(0x0f28 + seg, 0x000e) + seg);
    memory16set(0x0f29 + seg, 0x0006, memory16get(0x0f29 + seg, 0x0006) + seg);
    memory16set(0x0f29 + seg, 0x000e, memory16get(0x0f29 + seg, 0x000e) + seg);
    memory16set(0x0f2a + seg, 0x0006, memory16get(0x0f2a + seg, 0x0006) + seg);
    memory16set(0x0f2a + seg, 0x000e, memory16get(0x0f2a + seg, 0x000e) + seg);
    memory16set(0x0f2b + seg, 0x0006, memory16get(0x0f2b + seg, 0x0006) + seg);
    memory16set(0x0f2b + seg, 0x000e, memory16get(0x0f2b + seg, 0x000e) + seg);
    memory16set(0x0f2c + seg, 0x0006, memory16get(0x0f2c + seg, 0x0006) + seg);
    memory16set(0x0f2c + seg, 0x000e, memory16get(0x0f2c + seg, 0x000e) + seg);
    memory16set(0x0f2d + seg, 0x0006, memory16get(0x0f2d + seg, 0x0006) + seg);
    memory16set(0x0f2d + seg, 0x000e, memory16get(0x0f2d + seg, 0x000e) + seg);
    memory16set(0x0f2e + seg, 0x0006, memory16get(0x0f2e + seg, 0x0006) + seg);
    memory16set(0x0f2e + seg, 0x000e, memory16get(0x0f2e + seg, 0x000e) + seg);
    memory16set(0x0f2f + seg, 0x0008, memory16get(0x0f2f + seg, 0x0008) + seg);
    memory16set(0x0f30 + seg, 0x0000, memory16get(0x0f30 + seg, 0x0000) + seg);
    memory16set(0x0f30 + seg, 0x0008, memory16get(0x0f30 + seg, 0x0008) + seg);
    memory16set(0x0f31 + seg, 0x0000, memory16get(0x0f31 + seg, 0x0000) + seg);
    memory16set(0x0f31 + seg, 0x0008, memory16get(0x0f31 + seg, 0x0008) + seg);
    memory16set(0x0f32 + seg, 0x0000, memory16get(0x0f32 + seg, 0x0000) + seg);
    memory16set(0x0f32 + seg, 0x0008, memory16get(0x0f32 + seg, 0x0008) + seg);
    memory16set(0x0f33 + seg, 0x0000, memory16get(0x0f33 + seg, 0x0000) + seg);
    memory16set(0x0f33 + seg, 0x0008, memory16get(0x0f33 + seg, 0x0008) + seg);
    memory16set(0x0f34 + seg, 0x0000, memory16get(0x0f34 + seg, 0x0000) + seg);
    memory16set(0x0f34 + seg, 0x0008, memory16get(0x0f34 + seg, 0x0008) + seg);
    memory16set(0x0f35 + seg, 0x0000, memory16get(0x0f35 + seg, 0x0000) + seg);
    memory16set(0x0f35 + seg, 0x0008, memory16get(0x0f35 + seg, 0x0008) + seg);
    memory16set(0x0f36 + seg, 0x0002, memory16get(0x0f36 + seg, 0x0002) + seg);
    memory16set(0x0f36 + seg, 0x000a, memory16get(0x0f36 + seg, 0x000a) + seg);
    memory16set(0x0f37 + seg, 0x0002, memory16get(0x0f37 + seg, 0x0002) + seg);
    memory16set(0x0f37 + seg, 0x000a, memory16get(0x0f37 + seg, 0x000a) + seg);
    memory16set(0x0f38 + seg, 0x0002, memory16get(0x0f38 + seg, 0x0002) + seg);
    memory16set(0x0f38 + seg, 0x000a, memory16get(0x0f38 + seg, 0x000a) + seg);
    memory16set(0x0f39 + seg, 0x0002, memory16get(0x0f39 + seg, 0x0002) + seg);
    memory16set(0x0f39 + seg, 0x000a, memory16get(0x0f39 + seg, 0x000a) + seg);
    memory16set(0x0f3a + seg, 0x0002, memory16get(0x0f3a + seg, 0x0002) + seg);
    memory16set(0x0f3a + seg, 0x000a, memory16get(0x0f3a + seg, 0x000a) + seg);
    memory16set(0x0f3b + seg, 0x0004, memory16get(0x0f3b + seg, 0x0004) + seg);
    memory16set(0x0f3b + seg, 0x000c, memory16get(0x0f3b + seg, 0x000c) + seg);
    memory16set(0x0f3c + seg, 0x0004, memory16get(0x0f3c + seg, 0x0004) + seg);
    memory16set(0x0f3c + seg, 0x000c, memory16get(0x0f3c + seg, 0x000c) + seg);
    memory16set(0x0f3d + seg, 0x0004, memory16get(0x0f3d + seg, 0x0004) + seg);
    memory16set(0x0f3d + seg, 0x000c, memory16get(0x0f3d + seg, 0x000c) + seg);
    memory16set(0x0f3e + seg, 0x0004, memory16get(0x0f3e + seg, 0x0004) + seg);
    memory16set(0x0f3e + seg, 0x000c, memory16get(0x0f3e + seg, 0x000c) + seg);
    memory16set(0x0f3f + seg, 0x0004, memory16get(0x0f3f + seg, 0x0004) + seg);
    memory16set(0x0f3f + seg, 0x000c, memory16get(0x0f3f + seg, 0x000c) + seg);
    memory16set(0x0f40 + seg, 0x0004, memory16get(0x0f40 + seg, 0x0004) + seg);
    memory16set(0x0f40 + seg, 0x000c, memory16get(0x0f40 + seg, 0x000c) + seg);
    memory16set(0x0f41 + seg, 0x0004, memory16get(0x0f41 + seg, 0x0004) + seg);
    memory16set(0x0f41 + seg, 0x000c, memory16get(0x0f41 + seg, 0x000c) + seg);
    memory16set(0x0f42 + seg, 0x0004, memory16get(0x0f42 + seg, 0x0004) + seg);
    memory16set(0x0f42 + seg, 0x000c, memory16get(0x0f42 + seg, 0x000c) + seg);
    memory16set(0x0f43 + seg, 0x0004, memory16get(0x0f43 + seg, 0x0004) + seg);
    memory16set(0x0f43 + seg, 0x000c, memory16get(0x0f43 + seg, 0x000c) + seg);
    memory16set(0x0f44 + seg, 0x0004, memory16get(0x0f44 + seg, 0x0004) + seg);
    memory16set(0x0f44 + seg, 0x000c, memory16get(0x0f44 + seg, 0x000c) + seg);
    memory16set(0x0f45 + seg, 0x0004, memory16get(0x0f45 + seg, 0x0004) + seg);
    memory16set(0x0f45 + seg, 0x000c, memory16get(0x0f45 + seg, 0x000c) + seg);
    memory16set(0x0f46 + seg, 0x0004, memory16get(0x0f46 + seg, 0x0004) + seg);
    memory16set(0x0f46 + seg, 0x000c, memory16get(0x0f46 + seg, 0x000c) + seg);
    memory16set(0x0f47 + seg, 0x0004, memory16get(0x0f47 + seg, 0x0004) + seg);
    memory16set(0x0f47 + seg, 0x000c, memory16get(0x0f47 + seg, 0x000c) + seg);
    memory16set(0x0f48 + seg, 0x0004, memory16get(0x0f48 + seg, 0x0004) + seg);
    memory16set(0x0f48 + seg, 0x000c, memory16get(0x0f48 + seg, 0x000c) + seg);
    memory16set(0x0f49 + seg, 0x0004, memory16get(0x0f49 + seg, 0x0004) + seg);
    memory16set(0x0f49 + seg, 0x000c, memory16get(0x0f49 + seg, 0x000c) + seg);
    memory16set(0x0f4a + seg, 0x0004, memory16get(0x0f4a + seg, 0x0004) + seg);
    memory16set(0x0f4a + seg, 0x000c, memory16get(0x0f4a + seg, 0x000c) + seg);
    memory16set(0x0f4b + seg, 0x0004, memory16get(0x0f4b + seg, 0x0004) + seg);
    memory16set(0x0f4b + seg, 0x000c, memory16get(0x0f4b + seg, 0x000c) + seg);
    memory16set(0x0f4c + seg, 0x0004, memory16get(0x0f4c + seg, 0x0004) + seg);
    memory16set(0x0f4c + seg, 0x000c, memory16get(0x0f4c + seg, 0x000c) + seg);
    memory16set(0x0f4d + seg, 0x0004, memory16get(0x0f4d + seg, 0x0004) + seg);
    memory16set(0x0f4d + seg, 0x000c, memory16get(0x0f4d + seg, 0x000c) + seg);
    memory16set(0x0f4e + seg, 0x0004, memory16get(0x0f4e + seg, 0x0004) + seg);
    memory16set(0x0f4e + seg, 0x000c, memory16get(0x0f4e + seg, 0x000c) + seg);
    memory16set(0x0f4f + seg, 0x0004, memory16get(0x0f4f + seg, 0x0004) + seg);
    memory16set(0x0f4f + seg, 0x000c, memory16get(0x0f4f + seg, 0x000c) + seg);
    memory16set(0x0f50 + seg, 0x0004, memory16get(0x0f50 + seg, 0x0004) + seg);
    memory16set(0x0f50 + seg, 0x000c, memory16get(0x0f50 + seg, 0x000c) + seg);
    memory16set(0x0f51 + seg, 0x0004, memory16get(0x0f51 + seg, 0x0004) + seg);
    memory16set(0x0f51 + seg, 0x000c, memory16get(0x0f51 + seg, 0x000c) + seg);
    memory16set(0x0f52 + seg, 0x0004, memory16get(0x0f52 + seg, 0x0004) + seg);
    memory16set(0x0f52 + seg, 0x000c, memory16get(0x0f52 + seg, 0x000c) + seg);
    memory16set(0x0f53 + seg, 0x0004, memory16get(0x0f53 + seg, 0x0004) + seg);
    memory16set(0x0f53 + seg, 0x000c, memory16get(0x0f53 + seg, 0x000c) + seg);
    memory16set(0x0f54 + seg, 0x0004, memory16get(0x0f54 + seg, 0x0004) + seg);
    memory16set(0x0f54 + seg, 0x000c, memory16get(0x0f54 + seg, 0x000c) + seg);
    memory16set(0x0f55 + seg, 0x0004, memory16get(0x0f55 + seg, 0x0004) + seg);
    memory16set(0x0f55 + seg, 0x000c, memory16get(0x0f55 + seg, 0x000c) + seg);
    memory16set(0x0f56 + seg, 0x0004, memory16get(0x0f56 + seg, 0x0004) + seg);
    memory16set(0x0f56 + seg, 0x000c, memory16get(0x0f56 + seg, 0x000c) + seg);
    memory16set(0x0f57 + seg, 0x0004, memory16get(0x0f57 + seg, 0x0004) + seg);
    memory16set(0x0f57 + seg, 0x000c, memory16get(0x0f57 + seg, 0x000c) + seg);
    memory16set(0x0f58 + seg, 0x0004, memory16get(0x0f58 + seg, 0x0004) + seg);
    memory16set(0x0f58 + seg, 0x000c, memory16get(0x0f58 + seg, 0x000c) + seg);
    memory16set(0x0f59 + seg, 0x0004, memory16get(0x0f59 + seg, 0x0004) + seg);
    memory16set(0x0f59 + seg, 0x000c, memory16get(0x0f59 + seg, 0x000c) + seg);
    memory16set(0x0f5a + seg, 0x0004, memory16get(0x0f5a + seg, 0x0004) + seg);
    memory16set(0x0f5a + seg, 0x000c, memory16get(0x0f5a + seg, 0x000c) + seg);
    memory16set(0x0f5b + seg, 0x0004, memory16get(0x0f5b + seg, 0x0004) + seg);
    memory16set(0x0f5b + seg, 0x000c, memory16get(0x0f5b + seg, 0x000c) + seg);
    memory16set(0x0f5c + seg, 0x0004, memory16get(0x0f5c + seg, 0x0004) + seg);
    memory16set(0x0f5c + seg, 0x000c, memory16get(0x0f5c + seg, 0x000c) + seg);
    memory16set(0x0f5d + seg, 0x0004, memory16get(0x0f5d + seg, 0x0004) + seg);
    memory16set(0x0f5d + seg, 0x000c, memory16get(0x0f5d + seg, 0x000c) + seg);
    memory16set(0x0f5e + seg, 0x0004, memory16get(0x0f5e + seg, 0x0004) + seg);
    memory16set(0x0f5e + seg, 0x000c, memory16get(0x0f5e + seg, 0x000c) + seg);
    memory16set(0x0f5f + seg, 0x0004, memory16get(0x0f5f + seg, 0x0004) + seg);
    memory16set(0x0f5f + seg, 0x000c, memory16get(0x0f5f + seg, 0x000c) + seg);
    memory16set(0x0f60 + seg, 0x0006, memory16get(0x0f60 + seg, 0x0006) + seg);
    memory16set(0x0f60 + seg, 0x000e, memory16get(0x0f60 + seg, 0x000e) + seg);
    memory16set(0x0f61 + seg, 0x0006, memory16get(0x0f61 + seg, 0x0006) + seg);
    memory16set(0x0f61 + seg, 0x000e, memory16get(0x0f61 + seg, 0x000e) + seg);
    memory16set(0x0f62 + seg, 0x0006, memory16get(0x0f62 + seg, 0x0006) + seg);
    memory16set(0x0f62 + seg, 0x000e, memory16get(0x0f62 + seg, 0x000e) + seg);
    memory16set(0x0f63 + seg, 0x0006, memory16get(0x0f63 + seg, 0x0006) + seg);
    memory16set(0x0f63 + seg, 0x000e, memory16get(0x0f63 + seg, 0x000e) + seg);
    memory16set(0x0f64 + seg, 0x0006, memory16get(0x0f64 + seg, 0x0006) + seg);
    memory16set(0x0f64 + seg, 0x000e, memory16get(0x0f64 + seg, 0x000e) + seg);
    memory16set(0x0f65 + seg, 0x0006, memory16get(0x0f65 + seg, 0x0006) + seg);
    memory16set(0x0f65 + seg, 0x000e, memory16get(0x0f65 + seg, 0x000e) + seg);
    memory16set(0x0f66 + seg, 0x0006, memory16get(0x0f66 + seg, 0x0006) + seg);
    memory16set(0x0f66 + seg, 0x000e, memory16get(0x0f66 + seg, 0x000e) + seg);
    memory16set(0x0f67 + seg, 0x0006, memory16get(0x0f67 + seg, 0x0006) + seg);
    memory16set(0x0f67 + seg, 0x000e, memory16get(0x0f67 + seg, 0x000e) + seg);
    memory16set(0x0f68 + seg, 0x0006, memory16get(0x0f68 + seg, 0x0006) + seg);
    memory16set(0x0f68 + seg, 0x000e, memory16get(0x0f68 + seg, 0x000e) + seg);
    memory16set(0x0f69 + seg, 0x0006, memory16get(0x0f69 + seg, 0x0006) + seg);
    memory16set(0x0f69 + seg, 0x000e, memory16get(0x0f69 + seg, 0x000e) + seg);
    memory16set(0x0f6a + seg, 0x0006, memory16get(0x0f6a + seg, 0x0006) + seg);
    memory16set(0x0f6a + seg, 0x000e, memory16get(0x0f6a + seg, 0x000e) + seg);
    memory16set(0x0f6b + seg, 0x0006, memory16get(0x0f6b + seg, 0x0006) + seg);
    memory16set(0x0f6b + seg, 0x000e, memory16get(0x0f6b + seg, 0x000e) + seg);
    memory16set(0x0f6c + seg, 0x0006, memory16get(0x0f6c + seg, 0x0006) + seg);
    memory16set(0x0f6c + seg, 0x000e, memory16get(0x0f6c + seg, 0x000e) + seg);
    memory16set(0x0f6d + seg, 0x0006, memory16get(0x0f6d + seg, 0x0006) + seg);
    memory16set(0x0f6d + seg, 0x000e, memory16get(0x0f6d + seg, 0x000e) + seg);
    memory16set(0x0f6e + seg, 0x0006, memory16get(0x0f6e + seg, 0x0006) + seg);
    memory16set(0x0f6e + seg, 0x000e, memory16get(0x0f6e + seg, 0x000e) + seg);
    memory16set(0x0f6f + seg, 0x0006, memory16get(0x0f6f + seg, 0x0006) + seg);
    memory16set(0x0f6f + seg, 0x000e, memory16get(0x0f6f + seg, 0x000e) + seg);
    memory16set(0x0f70 + seg, 0x0006, memory16get(0x0f70 + seg, 0x0006) + seg);
    memory16set(0x0f70 + seg, 0x000e, memory16get(0x0f70 + seg, 0x000e) + seg);
    memory16set(0x0f71 + seg, 0x0006, memory16get(0x0f71 + seg, 0x0006) + seg);
    memory16set(0x0f71 + seg, 0x000e, memory16get(0x0f71 + seg, 0x000e) + seg);
    memory16set(0x0f72 + seg, 0x0006, memory16get(0x0f72 + seg, 0x0006) + seg);
    memory16set(0x0f72 + seg, 0x000e, memory16get(0x0f72 + seg, 0x000e) + seg);
    memory16set(0x0f73 + seg, 0x0006, memory16get(0x0f73 + seg, 0x0006) + seg);
    memory16set(0x0f73 + seg, 0x000e, memory16get(0x0f73 + seg, 0x000e) + seg);
    memory16set(0x0f74 + seg, 0x0006, memory16get(0x0f74 + seg, 0x0006) + seg);
    memory16set(0x0f74 + seg, 0x000e, memory16get(0x0f74 + seg, 0x000e) + seg);
    memory16set(0x0f75 + seg, 0x0006, memory16get(0x0f75 + seg, 0x0006) + seg);
    memory16set(0x0f75 + seg, 0x000e, memory16get(0x0f75 + seg, 0x000e) + seg);
    memory16set(0x0f76 + seg, 0x0006, memory16get(0x0f76 + seg, 0x0006) + seg);
    memory16set(0x0f76 + seg, 0x000e, memory16get(0x0f76 + seg, 0x000e) + seg);
    memory16set(0x0f77 + seg, 0x0006, memory16get(0x0f77 + seg, 0x0006) + seg);
    memory16set(0x0f77 + seg, 0x000e, memory16get(0x0f77 + seg, 0x000e) + seg);
    memory16set(0x0f78 + seg, 0x0006, memory16get(0x0f78 + seg, 0x0006) + seg);
    memory16set(0x0f78 + seg, 0x000e, memory16get(0x0f78 + seg, 0x000e) + seg);
    memory16set(0x0f79 + seg, 0x0006, memory16get(0x0f79 + seg, 0x0006) + seg);
    memory16set(0x0f79 + seg, 0x000e, memory16get(0x0f79 + seg, 0x000e) + seg);
    memory16set(0x0f7a + seg, 0x0006, memory16get(0x0f7a + seg, 0x0006) + seg);
    memory16set(0x0f7a + seg, 0x000e, memory16get(0x0f7a + seg, 0x000e) + seg);
    memory16set(0x0f7b + seg, 0x0006, memory16get(0x0f7b + seg, 0x0006) + seg);
    memory16set(0x0f7b + seg, 0x000e, memory16get(0x0f7b + seg, 0x000e) + seg);
    memory16set(0x0f7c + seg, 0x0006, memory16get(0x0f7c + seg, 0x0006) + seg);
    memory16set(0x0f7c + seg, 0x000e, memory16get(0x0f7c + seg, 0x000e) + seg);
    memory16set(0x0f7d + seg, 0x0006, memory16get(0x0f7d + seg, 0x0006) + seg);
    memory16set(0x0f7d + seg, 0x000e, memory16get(0x0f7d + seg, 0x000e) + seg);
    memory16set(0x0f7e + seg, 0x0006, memory16get(0x0f7e + seg, 0x0006) + seg);
    memory16set(0x0f7e + seg, 0x000e, memory16get(0x0f7e + seg, 0x000e) + seg);
    memory16set(0x0f7f + seg, 0x0006, memory16get(0x0f7f + seg, 0x0006) + seg);
    memory16set(0x0f7f + seg, 0x000e, memory16get(0x0f7f + seg, 0x000e) + seg);
    memory16set(0x0f80 + seg, 0x0006, memory16get(0x0f80 + seg, 0x0006) + seg);
    memory16set(0x0f80 + seg, 0x000e, memory16get(0x0f80 + seg, 0x000e) + seg);
    memory16set(0x0f81 + seg, 0x0006, memory16get(0x0f81 + seg, 0x0006) + seg);
    memory16set(0x0f81 + seg, 0x000e, memory16get(0x0f81 + seg, 0x000e) + seg);
    memory16set(0x0f82 + seg, 0x0006, memory16get(0x0f82 + seg, 0x0006) + seg);
    memory16set(0x0f82 + seg, 0x000e, memory16get(0x0f82 + seg, 0x000e) + seg);
    memory16set(0x0f83 + seg, 0x0006, memory16get(0x0f83 + seg, 0x0006) + seg);
    memory16set(0x0f83 + seg, 0x000e, memory16get(0x0f83 + seg, 0x000e) + seg);
    memory16set(0x0f84 + seg, 0x0006, memory16get(0x0f84 + seg, 0x0006) + seg);
    memory16set(0x0f84 + seg, 0x000e, memory16get(0x0f84 + seg, 0x000e) + seg);
    memory16set(0x0f85 + seg, 0x0006, memory16get(0x0f85 + seg, 0x0006) + seg);
    memory16set(0x0f85 + seg, 0x000e, memory16get(0x0f85 + seg, 0x000e) + seg);
    memory16set(0x0f86 + seg, 0x0006, memory16get(0x0f86 + seg, 0x0006) + seg);
    memory16set(0x0f86 + seg, 0x000e, memory16get(0x0f86 + seg, 0x000e) + seg);
    memory16set(0x0f87 + seg, 0x0006, memory16get(0x0f87 + seg, 0x0006) + seg);
    memory16set(0x0f87 + seg, 0x000e, memory16get(0x0f87 + seg, 0x000e) + seg);
    memory16set(0x0f88 + seg, 0x0006, memory16get(0x0f88 + seg, 0x0006) + seg);
    memory16set(0x0f88 + seg, 0x000e, memory16get(0x0f88 + seg, 0x000e) + seg);
    memory16set(0x0f89 + seg, 0x0006, memory16get(0x0f89 + seg, 0x0006) + seg);
    memory16set(0x0f8a + seg, 0x0000, memory16get(0x0f8a + seg, 0x0000) + seg);
    memory16set(0x0f8a + seg, 0x0008, memory16get(0x0f8a + seg, 0x0008) + seg);
    memory16set(0x0f8b + seg, 0x0000, memory16get(0x0f8b + seg, 0x0000) + seg);
    memory16set(0x0f8b + seg, 0x0008, memory16get(0x0f8b + seg, 0x0008) + seg);
    memory16set(0x0f8c + seg, 0x0000, memory16get(0x0f8c + seg, 0x0000) + seg);
    memory16set(0x0f8c + seg, 0x0008, memory16get(0x0f8c + seg, 0x0008) + seg);
    memory16set(0x0f8d + seg, 0x0000, memory16get(0x0f8d + seg, 0x0000) + seg);
    memory16set(0x0f8d + seg, 0x0008, memory16get(0x0f8d + seg, 0x0008) + seg);
    memory16set(0x0f8e + seg, 0x0000, memory16get(0x0f8e + seg, 0x0000) + seg);
    memory16set(0x0f8e + seg, 0x0008, memory16get(0x0f8e + seg, 0x0008) + seg);
    memory16set(0x0f8f + seg, 0x0000, memory16get(0x0f8f + seg, 0x0000) + seg);
    memory16set(0x0f8f + seg, 0x0008, memory16get(0x0f8f + seg, 0x0008) + seg);
    memory16set(0x0f90 + seg, 0x0000, memory16get(0x0f90 + seg, 0x0000) + seg);
    memory16set(0x0f90 + seg, 0x0008, memory16get(0x0f90 + seg, 0x0008) + seg);
    memory16set(0x0f91 + seg, 0x0000, memory16get(0x0f91 + seg, 0x0000) + seg);
    memory16set(0x0f91 + seg, 0x0008, memory16get(0x0f91 + seg, 0x0008) + seg);
    memory16set(0x0f92 + seg, 0x0000, memory16get(0x0f92 + seg, 0x0000) + seg);
    memory16set(0x0f92 + seg, 0x0008, memory16get(0x0f92 + seg, 0x0008) + seg);
    memory16set(0x0f93 + seg, 0x0000, memory16get(0x0f93 + seg, 0x0000) + seg);
    memory16set(0x0f93 + seg, 0x0008, memory16get(0x0f93 + seg, 0x0008) + seg);
    memory16set(0x0f94 + seg, 0x0000, memory16get(0x0f94 + seg, 0x0000) + seg);
    memory16set(0x0f94 + seg, 0x0008, memory16get(0x0f94 + seg, 0x0008) + seg);
    memory16set(0x0f95 + seg, 0x0000, memory16get(0x0f95 + seg, 0x0000) + seg);
    memory16set(0x0f95 + seg, 0x0008, memory16get(0x0f95 + seg, 0x0008) + seg);
    memory16set(0x0f96 + seg, 0x0000, memory16get(0x0f96 + seg, 0x0000) + seg);
    memory16set(0x0f96 + seg, 0x0008, memory16get(0x0f96 + seg, 0x0008) + seg);
    memory16set(0x0f97 + seg, 0x0000, memory16get(0x0f97 + seg, 0x0000) + seg);
    memory16set(0x0f97 + seg, 0x0008, memory16get(0x0f97 + seg, 0x0008) + seg);
    memory16set(0x0f98 + seg, 0x0000, memory16get(0x0f98 + seg, 0x0000) + seg);
    memory16set(0x0f98 + seg, 0x0008, memory16get(0x0f98 + seg, 0x0008) + seg);
    memory16set(0x0f99 + seg, 0x0000, memory16get(0x0f99 + seg, 0x0000) + seg);
    memory16set(0x0f99 + seg, 0x0008, memory16get(0x0f99 + seg, 0x0008) + seg);
    memory16set(0x0f9a + seg, 0x0000, memory16get(0x0f9a + seg, 0x0000) + seg);
    memory16set(0x0f9a + seg, 0x0008, memory16get(0x0f9a + seg, 0x0008) + seg);
    memory16set(0x0f9b + seg, 0x0000, memory16get(0x0f9b + seg, 0x0000) + seg);
    memory16set(0x0f9b + seg, 0x0008, memory16get(0x0f9b + seg, 0x0008) + seg);
    memory16set(0x0f9c + seg, 0x0000, memory16get(0x0f9c + seg, 0x0000) + seg);
    memory16set(0x0f9c + seg, 0x0008, memory16get(0x0f9c + seg, 0x0008) + seg);
    memory16set(0x0f9d + seg, 0x0000, memory16get(0x0f9d + seg, 0x0000) + seg);
    memory16set(0x0f9d + seg, 0x0008, memory16get(0x0f9d + seg, 0x0008) + seg);
    memory16set(0x0f9e + seg, 0x0000, memory16get(0x0f9e + seg, 0x0000) + seg);
    memory16set(0x0f9e + seg, 0x0008, memory16get(0x0f9e + seg, 0x0008) + seg);
    memory16set(0x0f9f + seg, 0x0000, memory16get(0x0f9f + seg, 0x0000) + seg);
    memory16set(0x0f9f + seg, 0x0008, memory16get(0x0f9f + seg, 0x0008) + seg);
    memory16set(0x0fa0 + seg, 0x0000, memory16get(0x0fa0 + seg, 0x0000) + seg);
    memory16set(0x0fa0 + seg, 0x0008, memory16get(0x0fa0 + seg, 0x0008) + seg);
    memory16set(0x0fa1 + seg, 0x0000, memory16get(0x0fa1 + seg, 0x0000) + seg);
    memory16set(0x0fa1 + seg, 0x0008, memory16get(0x0fa1 + seg, 0x0008) + seg);
    memory16set(0x0fa2 + seg, 0x0000, memory16get(0x0fa2 + seg, 0x0000) + seg);
    memory16set(0x0fa2 + seg, 0x0008, memory16get(0x0fa2 + seg, 0x0008) + seg);
    memory16set(0x0fa3 + seg, 0x0000, memory16get(0x0fa3 + seg, 0x0000) + seg);
    memory16set(0x0fa3 + seg, 0x0008, memory16get(0x0fa3 + seg, 0x0008) + seg);
    memory16set(0x0fa4 + seg, 0x0000, memory16get(0x0fa4 + seg, 0x0000) + seg);
    memory16set(0x0fa4 + seg, 0x0008, memory16get(0x0fa4 + seg, 0x0008) + seg);
    memory16set(0x0fa5 + seg, 0x0000, memory16get(0x0fa5 + seg, 0x0000) + seg);
    memory16set(0x0fa5 + seg, 0x0008, memory16get(0x0fa5 + seg, 0x0008) + seg);
    memory16set(0x0fa6 + seg, 0x0000, memory16get(0x0fa6 + seg, 0x0000) + seg);
    memory16set(0x0fa6 + seg, 0x0008, memory16get(0x0fa6 + seg, 0x0008) + seg);
    memory16set(0x0fa7 + seg, 0x0000, memory16get(0x0fa7 + seg, 0x0000) + seg);
    memory16set(0x0fa7 + seg, 0x0008, memory16get(0x0fa7 + seg, 0x0008) + seg);
    memory16set(0x0fa8 + seg, 0x0000, memory16get(0x0fa8 + seg, 0x0000) + seg);
    memory16set(0x0fa8 + seg, 0x0008, memory16get(0x0fa8 + seg, 0x0008) + seg);
    memory16set(0x0fa9 + seg, 0x0000, memory16get(0x0fa9 + seg, 0x0000) + seg);
    memory16set(0x0fa9 + seg, 0x0008, memory16get(0x0fa9 + seg, 0x0008) + seg);
    memory16set(0x0faa + seg, 0x0000, memory16get(0x0faa + seg, 0x0000) + seg);
    memory16set(0x0faa + seg, 0x0008, memory16get(0x0faa + seg, 0x0008) + seg);
    memory16set(0x0fab + seg, 0x0000, memory16get(0x0fab + seg, 0x0000) + seg);
    memory16set(0x0fab + seg, 0x0008, memory16get(0x0fab + seg, 0x0008) + seg);
    memory16set(0x0fac + seg, 0x0000, memory16get(0x0fac + seg, 0x0000) + seg);
    memory16set(0x0fac + seg, 0x0008, memory16get(0x0fac + seg, 0x0008) + seg);
    memory16set(0x0fad + seg, 0x0000, memory16get(0x0fad + seg, 0x0000) + seg);
    memory16set(0x0fad + seg, 0x0008, memory16get(0x0fad + seg, 0x0008) + seg);
    memory16set(0x0fae + seg, 0x0000, memory16get(0x0fae + seg, 0x0000) + seg);
    memory16set(0x0fae + seg, 0x0008, memory16get(0x0fae + seg, 0x0008) + seg);
    memory16set(0x0faf + seg, 0x0000, memory16get(0x0faf + seg, 0x0000) + seg);
    memory16set(0x0faf + seg, 0x0008, memory16get(0x0faf + seg, 0x0008) + seg);
    memory16set(0x0fb0 + seg, 0x0000, memory16get(0x0fb0 + seg, 0x0000) + seg);
    memory16set(0x0fb0 + seg, 0x0008, memory16get(0x0fb0 + seg, 0x0008) + seg);
    memory16set(0x0fb1 + seg, 0x0000, memory16get(0x0fb1 + seg, 0x0000) + seg);
    memory16set(0x0fb1 + seg, 0x0008, memory16get(0x0fb1 + seg, 0x0008) + seg);
    memory16set(0x0fb2 + seg, 0x0000, memory16get(0x0fb2 + seg, 0x0000) + seg);
    memory16set(0x0fb2 + seg, 0x0008, memory16get(0x0fb2 + seg, 0x0008) + seg);
    memory16set(0x0fb3 + seg, 0x0000, memory16get(0x0fb3 + seg, 0x0000) + seg);
    memory16set(0x0fb3 + seg, 0x0008, memory16get(0x0fb3 + seg, 0x0008) + seg);
    memory16set(0x0fb4 + seg, 0x0000, memory16get(0x0fb4 + seg, 0x0000) + seg);
    memory16set(0x0fb4 + seg, 0x0008, memory16get(0x0fb4 + seg, 0x0008) + seg);
    memory16set(0x0fb5 + seg, 0x0000, memory16get(0x0fb5 + seg, 0x0000) + seg);
    memory16set(0x0fb5 + seg, 0x0008, memory16get(0x0fb5 + seg, 0x0008) + seg);
    memory16set(0x0fb6 + seg, 0x0000, memory16get(0x0fb6 + seg, 0x0000) + seg);
    memory16set(0x0fb6 + seg, 0x0008, memory16get(0x0fb6 + seg, 0x0008) + seg);
    memory16set(0x0fb7 + seg, 0x0000, memory16get(0x0fb7 + seg, 0x0000) + seg);
    memory16set(0x0fb7 + seg, 0x0008, memory16get(0x0fb7 + seg, 0x0008) + seg);
    memory16set(0x0fb8 + seg, 0x0000, memory16get(0x0fb8 + seg, 0x0000) + seg);
    memory16set(0x0fb8 + seg, 0x0008, memory16get(0x0fb8 + seg, 0x0008) + seg);
    memory16set(0x0fb9 + seg, 0x0000, memory16get(0x0fb9 + seg, 0x0000) + seg);
    memory16set(0x0fb9 + seg, 0x0008, memory16get(0x0fb9 + seg, 0x0008) + seg);
    memory16set(0x0fba + seg, 0x0000, memory16get(0x0fba + seg, 0x0000) + seg);
    memory16set(0x0fba + seg, 0x0008, memory16get(0x0fba + seg, 0x0008) + seg);
    memory16set(0x0fbb + seg, 0x0000, memory16get(0x0fbb + seg, 0x0000) + seg);
    memory16set(0x0fbb + seg, 0x0008, memory16get(0x0fbb + seg, 0x0008) + seg);
    memory16set(0x0fbc + seg, 0x0000, memory16get(0x0fbc + seg, 0x0000) + seg);
    memory16set(0x0fbc + seg, 0x0008, memory16get(0x0fbc + seg, 0x0008) + seg);
    memory16set(0x0fbd + seg, 0x0000, memory16get(0x0fbd + seg, 0x0000) + seg);
    memory16set(0x0fbd + seg, 0x0008, memory16get(0x0fbd + seg, 0x0008) + seg);
    memory16set(0x0fbe + seg, 0x0000, memory16get(0x0fbe + seg, 0x0000) + seg);
    memory16set(0x0fbe + seg, 0x0008, memory16get(0x0fbe + seg, 0x0008) + seg);
    memory16set(0x0fbf + seg, 0x0000, memory16get(0x0fbf + seg, 0x0000) + seg);
    memory16set(0x0fbf + seg, 0x0008, memory16get(0x0fbf + seg, 0x0008) + seg);
    memory16set(0x0fc0 + seg, 0x0000, memory16get(0x0fc0 + seg, 0x0000) + seg);
    memory16set(0x0fc0 + seg, 0x0008, memory16get(0x0fc0 + seg, 0x0008) + seg);
    memory16set(0x0fc1 + seg, 0x0000, memory16get(0x0fc1 + seg, 0x0000) + seg);
    memory16set(0x0fc1 + seg, 0x0008, memory16get(0x0fc1 + seg, 0x0008) + seg);
    memory16set(0x0fc2 + seg, 0x0000, memory16get(0x0fc2 + seg, 0x0000) + seg);
    memory16set(0x0fc2 + seg, 0x0008, memory16get(0x0fc2 + seg, 0x0008) + seg);
    memory16set(0x0fc3 + seg, 0x0000, memory16get(0x0fc3 + seg, 0x0000) + seg);
    memory16set(0x0fc3 + seg, 0x0008, memory16get(0x0fc3 + seg, 0x0008) + seg);
    memory16set(0x0fc4 + seg, 0x0000, memory16get(0x0fc4 + seg, 0x0000) + seg);
    memory16set(0x0fc4 + seg, 0x0008, memory16get(0x0fc4 + seg, 0x0008) + seg);
    memory16set(0x0fc5 + seg, 0x0000, memory16get(0x0fc5 + seg, 0x0000) + seg);
    memory16set(0x0fc5 + seg, 0x0008, memory16get(0x0fc5 + seg, 0x0008) + seg);
    memory16set(0x0fc6 + seg, 0x0000, memory16get(0x0fc6 + seg, 0x0000) + seg);
    memory16set(0x0fc6 + seg, 0x0008, memory16get(0x0fc6 + seg, 0x0008) + seg);
    memory16set(0x0fc7 + seg, 0x0000, memory16get(0x0fc7 + seg, 0x0000) + seg);
    memory16set(0x0fc7 + seg, 0x0008, memory16get(0x0fc7 + seg, 0x0008) + seg);
    memory16set(0x0fc8 + seg, 0x0000, memory16get(0x0fc8 + seg, 0x0000) + seg);
    memory16set(0x0fc8 + seg, 0x0008, memory16get(0x0fc8 + seg, 0x0008) + seg);
    memory16set(0x0fc9 + seg, 0x0000, memory16get(0x0fc9 + seg, 0x0000) + seg);
    memory16set(0x0fc9 + seg, 0x0008, memory16get(0x0fc9 + seg, 0x0008) + seg);
    memory16set(0x0fca + seg, 0x0002, memory16get(0x0fca + seg, 0x0002) + seg);
    memory16set(0x0fca + seg, 0x000a, memory16get(0x0fca + seg, 0x000a) + seg);
    memory16set(0x0fcb + seg, 0x0002, memory16get(0x0fcb + seg, 0x0002) + seg);
    memory16set(0x0fcb + seg, 0x000a, memory16get(0x0fcb + seg, 0x000a) + seg);
    memory16set(0x0fcc + seg, 0x0002, memory16get(0x0fcc + seg, 0x0002) + seg);
    memory16set(0x0fcc + seg, 0x000a, memory16get(0x0fcc + seg, 0x000a) + seg);
    memory16set(0x0fcd + seg, 0x0002, memory16get(0x0fcd + seg, 0x0002) + seg);
    memory16set(0x0fcd + seg, 0x000a, memory16get(0x0fcd + seg, 0x000a) + seg);
    memory16set(0x0fce + seg, 0x0002, memory16get(0x0fce + seg, 0x0002) + seg);
    memory16set(0x0fce + seg, 0x000a, memory16get(0x0fce + seg, 0x000a) + seg);
    memory16set(0x0fcf + seg, 0x0002, memory16get(0x0fcf + seg, 0x0002) + seg);
    memory16set(0x0fcf + seg, 0x000a, memory16get(0x0fcf + seg, 0x000a) + seg);
    memory16set(0x0fd0 + seg, 0x0002, memory16get(0x0fd0 + seg, 0x0002) + seg);
    memory16set(0x0fd0 + seg, 0x000a, memory16get(0x0fd0 + seg, 0x000a) + seg);
    memory16set(0x0fd1 + seg, 0x0002, memory16get(0x0fd1 + seg, 0x0002) + seg);
    memory16set(0x0fd1 + seg, 0x000a, memory16get(0x0fd1 + seg, 0x000a) + seg);
    memory16set(0x0fd2 + seg, 0x0002, memory16get(0x0fd2 + seg, 0x0002) + seg);
    memory16set(0x0fd2 + seg, 0x000a, memory16get(0x0fd2 + seg, 0x000a) + seg);
    memory16set(0x0fd3 + seg, 0x0002, memory16get(0x0fd3 + seg, 0x0002) + seg);
    memory16set(0x0fd3 + seg, 0x000a, memory16get(0x0fd3 + seg, 0x000a) + seg);
    memory16set(0x0fd4 + seg, 0x0002, memory16get(0x0fd4 + seg, 0x0002) + seg);
    memory16set(0x0fd4 + seg, 0x000a, memory16get(0x0fd4 + seg, 0x000a) + seg);
    memory16set(0x0fd5 + seg, 0x0002, memory16get(0x0fd5 + seg, 0x0002) + seg);
    memory16set(0x0fd5 + seg, 0x000a, memory16get(0x0fd5 + seg, 0x000a) + seg);
    memory16set(0x0fd6 + seg, 0x0002, memory16get(0x0fd6 + seg, 0x0002) + seg);
    memory16set(0x0fd6 + seg, 0x000a, memory16get(0x0fd6 + seg, 0x000a) + seg);
    memory16set(0x0fd7 + seg, 0x0002, memory16get(0x0fd7 + seg, 0x0002) + seg);
    memory16set(0x0fd7 + seg, 0x000a, memory16get(0x0fd7 + seg, 0x000a) + seg);
    memory16set(0x0fd8 + seg, 0x0002, memory16get(0x0fd8 + seg, 0x0002) + seg);
    memory16set(0x0fd8 + seg, 0x000a, memory16get(0x0fd8 + seg, 0x000a) + seg);
    memory16set(0x0fd9 + seg, 0x0002, memory16get(0x0fd9 + seg, 0x0002) + seg);
    memory16set(0x0fd9 + seg, 0x000a, memory16get(0x0fd9 + seg, 0x000a) + seg);
    memory16set(0x0fda + seg, 0x0002, memory16get(0x0fda + seg, 0x0002) + seg);
    memory16set(0x0fda + seg, 0x000a, memory16get(0x0fda + seg, 0x000a) + seg);
    memory16set(0x0fdb + seg, 0x0002, memory16get(0x0fdb + seg, 0x0002) + seg);
    memory16set(0x0fdb + seg, 0x000a, memory16get(0x0fdb + seg, 0x000a) + seg);
    memory16set(0x0fdc + seg, 0x0002, memory16get(0x0fdc + seg, 0x0002) + seg);
    memory16set(0x0fdc + seg, 0x000a, memory16get(0x0fdc + seg, 0x000a) + seg);
    memory16set(0x0fdd + seg, 0x0002, memory16get(0x0fdd + seg, 0x0002) + seg);
    memory16set(0x0fdd + seg, 0x000a, memory16get(0x0fdd + seg, 0x000a) + seg);
    memory16set(0x0fde + seg, 0x0002, memory16get(0x0fde + seg, 0x0002) + seg);
    memory16set(0x0fde + seg, 0x000a, memory16get(0x0fde + seg, 0x000a) + seg);
    memory16set(0x0fdf + seg, 0x0002, memory16get(0x0fdf + seg, 0x0002) + seg);
    memory16set(0x0fdf + seg, 0x000a, memory16get(0x0fdf + seg, 0x000a) + seg);
    memory16set(0x0fe0 + seg, 0x0002, memory16get(0x0fe0 + seg, 0x0002) + seg);
    memory16set(0x0fe0 + seg, 0x000a, memory16get(0x0fe0 + seg, 0x000a) + seg);
    memory16set(0x0fe1 + seg, 0x0002, memory16get(0x0fe1 + seg, 0x0002) + seg);
    memory16set(0x0fe1 + seg, 0x000a, memory16get(0x0fe1 + seg, 0x000a) + seg);
    memory16set(0x0fe2 + seg, 0x0002, memory16get(0x0fe2 + seg, 0x0002) + seg);
    memory16set(0x0fe2 + seg, 0x000a, memory16get(0x0fe2 + seg, 0x000a) + seg);
    memory16set(0x0fe3 + seg, 0x0002, memory16get(0x0fe3 + seg, 0x0002) + seg);
    memory16set(0x0fe3 + seg, 0x000a, memory16get(0x0fe3 + seg, 0x000a) + seg);
    memory16set(0x0fe4 + seg, 0x0002, memory16get(0x0fe4 + seg, 0x0002) + seg);
    memory16set(0x0fe4 + seg, 0x000a, memory16get(0x0fe4 + seg, 0x000a) + seg);
    memory16set(0x0fe5 + seg, 0x0002, memory16get(0x0fe5 + seg, 0x0002) + seg);
    memory16set(0x0fe5 + seg, 0x000a, memory16get(0x0fe5 + seg, 0x000a) + seg);
    memory16set(0x0fe6 + seg, 0x0002, memory16get(0x0fe6 + seg, 0x0002) + seg);
    memory16set(0x0fe6 + seg, 0x000a, memory16get(0x0fe6 + seg, 0x000a) + seg);
    memory16set(0x0fe7 + seg, 0x0002, memory16get(0x0fe7 + seg, 0x0002) + seg);
    memory16set(0x0fe7 + seg, 0x000a, memory16get(0x0fe7 + seg, 0x000a) + seg);
    memory16set(0x0fe8 + seg, 0x0002, memory16get(0x0fe8 + seg, 0x0002) + seg);
    memory16set(0x0fe8 + seg, 0x000a, memory16get(0x0fe8 + seg, 0x000a) + seg);
    memory16set(0x0fe9 + seg, 0x0002, memory16get(0x0fe9 + seg, 0x0002) + seg);
    memory16set(0x0fe9 + seg, 0x000a, memory16get(0x0fe9 + seg, 0x000a) + seg);
    memory16set(0x0fea + seg, 0x0002, memory16get(0x0fea + seg, 0x0002) + seg);
    memory16set(0x0fea + seg, 0x000a, memory16get(0x0fea + seg, 0x000a) + seg);
    memory16set(0x0feb + seg, 0x0002, memory16get(0x0feb + seg, 0x0002) + seg);
    memory16set(0x0feb + seg, 0x000a, memory16get(0x0feb + seg, 0x000a) + seg);
    memory16set(0x0fec + seg, 0x0002, memory16get(0x0fec + seg, 0x0002) + seg);
    memory16set(0x0fec + seg, 0x000a, memory16get(0x0fec + seg, 0x000a) + seg);
    memory16set(0x0fed + seg, 0x0002, memory16get(0x0fed + seg, 0x0002) + seg);
    memory16set(0x0fed + seg, 0x000a, memory16get(0x0fed + seg, 0x000a) + seg);
    memory16set(0x0fee + seg, 0x0002, memory16get(0x0fee + seg, 0x0002) + seg);
    memory16set(0x0fee + seg, 0x000a, memory16get(0x0fee + seg, 0x000a) + seg);
    memory16set(0x0fef + seg, 0x0002, memory16get(0x0fef + seg, 0x0002) + seg);
    memory16set(0x0fef + seg, 0x000a, memory16get(0x0fef + seg, 0x000a) + seg);
    memory16set(0x0ff0 + seg, 0x0002, memory16get(0x0ff0 + seg, 0x0002) + seg);
    memory16set(0x0ff0 + seg, 0x000a, memory16get(0x0ff0 + seg, 0x000a) + seg);
    memory16set(0x0ff1 + seg, 0x0002, memory16get(0x0ff1 + seg, 0x0002) + seg);
    memory16set(0x0ff1 + seg, 0x000a, memory16get(0x0ff1 + seg, 0x000a) + seg);
    memory16set(0x0ff2 + seg, 0x0002, memory16get(0x0ff2 + seg, 0x0002) + seg);
    memory16set(0x0ff2 + seg, 0x000a, memory16get(0x0ff2 + seg, 0x000a) + seg);
    memory16set(0x0ff3 + seg, 0x0002, memory16get(0x0ff3 + seg, 0x0002) + seg);
    memory16set(0x0ff3 + seg, 0x000a, memory16get(0x0ff3 + seg, 0x000a) + seg);
    memory16set(0x0ff4 + seg, 0x0002, memory16get(0x0ff4 + seg, 0x0002) + seg);
    memory16set(0x0ff4 + seg, 0x000a, memory16get(0x0ff4 + seg, 0x000a) + seg);
    memory16set(0x0ff5 + seg, 0x0002, memory16get(0x0ff5 + seg, 0x0002) + seg);
    memory16set(0x0ff5 + seg, 0x000a, memory16get(0x0ff5 + seg, 0x000a) + seg);
    memory16set(0x0ff6 + seg, 0x0002, memory16get(0x0ff6 + seg, 0x0002) + seg);
    memory16set(0x0ff6 + seg, 0x000a, memory16get(0x0ff6 + seg, 0x000a) + seg);
    memory16set(0x0ff7 + seg, 0x0002, memory16get(0x0ff7 + seg, 0x0002) + seg);
    memory16set(0x0ff7 + seg, 0x000a, memory16get(0x0ff7 + seg, 0x000a) + seg);
    memory16set(0x0ff8 + seg, 0x0002, memory16get(0x0ff8 + seg, 0x0002) + seg);
    memory16set(0x0ff8 + seg, 0x000a, memory16get(0x0ff8 + seg, 0x000a) + seg);
    memory16set(0x0ff9 + seg, 0x0002, memory16get(0x0ff9 + seg, 0x0002) + seg);
    memory16set(0x0ff9 + seg, 0x000a, memory16get(0x0ff9 + seg, 0x000a) + seg);
    memory16set(0x0ffa + seg, 0x0002, memory16get(0x0ffa + seg, 0x0002) + seg);
    memory16set(0x0ffa + seg, 0x000a, memory16get(0x0ffa + seg, 0x000a) + seg);
    memory16set(0x0ffb + seg, 0x0002, memory16get(0x0ffb + seg, 0x0002) + seg);
    memory16set(0x0ffb + seg, 0x000a, memory16get(0x0ffb + seg, 0x000a) + seg);
    memory16set(0x0ffc + seg, 0x0002, memory16get(0x0ffc + seg, 0x0002) + seg);
    memory16set(0x0ffc + seg, 0x000a, memory16get(0x0ffc + seg, 0x000a) + seg);
    memory16set(0x0ffd + seg, 0x0004, memory16get(0x0ffd + seg, 0x0004) + seg);
    memory16set(0x0ffd + seg, 0x000c, memory16get(0x0ffd + seg, 0x000c) + seg);
    memory16set(0x0ffe + seg, 0x0004, memory16get(0x0ffe + seg, 0x0004) + seg);
    memory16set(0x0ffe + seg, 0x000c, memory16get(0x0ffe + seg, 0x000c) + seg);
    memory16set(0x0fff + seg, 0x0004, memory16get(0x0fff + seg, 0x0004) + seg);
    memory16set(0x0fff + seg, 0x000c, memory16get(0x0fff + seg, 0x000c) + seg);
    memory16set(0x1000 + seg, 0x0004, memory16get(0x1000 + seg, 0x0004) + seg);
    memory16set(0x1000 + seg, 0x000c, memory16get(0x1000 + seg, 0x000c) + seg);
    memory16set(0x1001 + seg, 0x0004, memory16get(0x1001 + seg, 0x0004) + seg);
    memory16set(0x1001 + seg, 0x000c, memory16get(0x1001 + seg, 0x000c) + seg);
    memory16set(0x1002 + seg, 0x0004, memory16get(0x1002 + seg, 0x0004) + seg);
    memory16set(0x1002 + seg, 0x000c, memory16get(0x1002 + seg, 0x000c) + seg);
    memory16set(0x1003 + seg, 0x0004, memory16get(0x1003 + seg, 0x0004) + seg);
    memory16set(0x1003 + seg, 0x000c, memory16get(0x1003 + seg, 0x000c) + seg);
    memory16set(0x1004 + seg, 0x0004, memory16get(0x1004 + seg, 0x0004) + seg);
    memory16set(0x1004 + seg, 0x000c, memory16get(0x1004 + seg, 0x000c) + seg);
    memory16set(0x1005 + seg, 0x0004, memory16get(0x1005 + seg, 0x0004) + seg);
    memory16set(0x1005 + seg, 0x000c, memory16get(0x1005 + seg, 0x000c) + seg);
    memory16set(0x1006 + seg, 0x0004, memory16get(0x1006 + seg, 0x0004) + seg);
    memory16set(0x1006 + seg, 0x000c, memory16get(0x1006 + seg, 0x000c) + seg);
    memory16set(0x1007 + seg, 0x0004, memory16get(0x1007 + seg, 0x0004) + seg);
    memory16set(0x1007 + seg, 0x000c, memory16get(0x1007 + seg, 0x000c) + seg);
    memory16set(0x1008 + seg, 0x0004, memory16get(0x1008 + seg, 0x0004) + seg);
    memory16set(0x1008 + seg, 0x000c, memory16get(0x1008 + seg, 0x000c) + seg);
    memory16set(0x1009 + seg, 0x0004, memory16get(0x1009 + seg, 0x0004) + seg);
    memory16set(0x1009 + seg, 0x000c, memory16get(0x1009 + seg, 0x000c) + seg);
    memory16set(0x100a + seg, 0x0004, memory16get(0x100a + seg, 0x0004) + seg);
    memory16set(0x100a + seg, 0x000c, memory16get(0x100a + seg, 0x000c) + seg);
    memory16set(0x100b + seg, 0x0004, memory16get(0x100b + seg, 0x0004) + seg);
    memory16set(0x100b + seg, 0x000c, memory16get(0x100b + seg, 0x000c) + seg);
    memory16set(0x100c + seg, 0x0004, memory16get(0x100c + seg, 0x0004) + seg);
    memory16set(0x100c + seg, 0x000c, memory16get(0x100c + seg, 0x000c) + seg);
    memory16set(0x100d + seg, 0x0004, memory16get(0x100d + seg, 0x0004) + seg);
    memory16set(0x100d + seg, 0x000c, memory16get(0x100d + seg, 0x000c) + seg);
    memory16set(0x100e + seg, 0x0004, memory16get(0x100e + seg, 0x0004) + seg);
    memory16set(0x100e + seg, 0x000c, memory16get(0x100e + seg, 0x000c) + seg);
    memory16set(0x100f + seg, 0x0004, memory16get(0x100f + seg, 0x0004) + seg);
    memory16set(0x100f + seg, 0x000c, memory16get(0x100f + seg, 0x000c) + seg);
    memory16set(0x1010 + seg, 0x0004, memory16get(0x1010 + seg, 0x0004) + seg);
    memory16set(0x1010 + seg, 0x000c, memory16get(0x1010 + seg, 0x000c) + seg);
    memory16set(0x1011 + seg, 0x0004, memory16get(0x1011 + seg, 0x0004) + seg);
    memory16set(0x1011 + seg, 0x000c, memory16get(0x1011 + seg, 0x000c) + seg);
    memory16set(0x1012 + seg, 0x0004, memory16get(0x1012 + seg, 0x0004) + seg);
    memory16set(0x1012 + seg, 0x000c, memory16get(0x1012 + seg, 0x000c) + seg);
    memory16set(0x1013 + seg, 0x0004, memory16get(0x1013 + seg, 0x0004) + seg);
    memory16set(0x1013 + seg, 0x000c, memory16get(0x1013 + seg, 0x000c) + seg);
    memory16set(0x1014 + seg, 0x0004, memory16get(0x1014 + seg, 0x0004) + seg);
    memory16set(0x1014 + seg, 0x000c, memory16get(0x1014 + seg, 0x000c) + seg);
    memory16set(0x1015 + seg, 0x0004, memory16get(0x1015 + seg, 0x0004) + seg);
    memory16set(0x1015 + seg, 0x000c, memory16get(0x1015 + seg, 0x000c) + seg);
    memory16set(0x1016 + seg, 0x0004, memory16get(0x1016 + seg, 0x0004) + seg);
    memory16set(0x1016 + seg, 0x000c, memory16get(0x1016 + seg, 0x000c) + seg);
    memory16set(0x1017 + seg, 0x0004, memory16get(0x1017 + seg, 0x0004) + seg);
    memory16set(0x1017 + seg, 0x000c, memory16get(0x1017 + seg, 0x000c) + seg);
    memory16set(0x1018 + seg, 0x0004, memory16get(0x1018 + seg, 0x0004) + seg);
    memory16set(0x1018 + seg, 0x000c, memory16get(0x1018 + seg, 0x000c) + seg);
    memory16set(0x1019 + seg, 0x0004, memory16get(0x1019 + seg, 0x0004) + seg);
    memory16set(0x1019 + seg, 0x000c, memory16get(0x1019 + seg, 0x000c) + seg);
    memory16set(0x101a + seg, 0x0004, memory16get(0x101a + seg, 0x0004) + seg);
    memory16set(0x101a + seg, 0x000c, memory16get(0x101a + seg, 0x000c) + seg);
    memory16set(0x101b + seg, 0x0004, memory16get(0x101b + seg, 0x0004) + seg);
    memory16set(0x101c + seg, 0x000c, memory16get(0x101c + seg, 0x000c) + seg);
    memory16set(0x101d + seg, 0x0000, memory16get(0x101d + seg, 0x0000) + seg);
    memory16set(0x101d + seg, 0x0004, memory16get(0x101d + seg, 0x0004) + seg);
    memory16set(0x101d + seg, 0x0008, memory16get(0x101d + seg, 0x0008) + seg);
    memory16set(0x101d + seg, 0x000c, memory16get(0x101d + seg, 0x000c) + seg);
    memory16set(0x101e + seg, 0x0000, memory16get(0x101e + seg, 0x0000) + seg);
    memory16set(0x101e + seg, 0x0004, memory16get(0x101e + seg, 0x0004) + seg);
    memory16set(0x101e + seg, 0x0008, memory16get(0x101e + seg, 0x0008) + seg);
    memory16set(0x101e + seg, 0x000c, memory16get(0x101e + seg, 0x000c) + seg);
    memory16set(0x101f + seg, 0x0000, memory16get(0x101f + seg, 0x0000) + seg);
    memory16set(0x101f + seg, 0x0004, memory16get(0x101f + seg, 0x0004) + seg);
    memory16set(0x101f + seg, 0x0008, memory16get(0x101f + seg, 0x0008) + seg);
    memory16set(0x101f + seg, 0x000c, memory16get(0x101f + seg, 0x000c) + seg);
    memory16set(0x1020 + seg, 0x0000, memory16get(0x1020 + seg, 0x0000) + seg);
    memory16set(0x1020 + seg, 0x0004, memory16get(0x1020 + seg, 0x0004) + seg);
    memory16set(0x1020 + seg, 0x0008, memory16get(0x1020 + seg, 0x0008) + seg);
    memory16set(0x1021 + seg, 0x0000, memory16get(0x1021 + seg, 0x0000) + seg);
    memory16set(0x1021 + seg, 0x0004, memory16get(0x1021 + seg, 0x0004) + seg);
    memory16set(0x1021 + seg, 0x0008, memory16get(0x1021 + seg, 0x0008) + seg);
    memory16set(0x1021 + seg, 0x000c, memory16get(0x1021 + seg, 0x000c) + seg);
    memory16set(0x1022 + seg, 0x0000, memory16get(0x1022 + seg, 0x0000) + seg);
    memory16set(0x1022 + seg, 0x0004, memory16get(0x1022 + seg, 0x0004) + seg);
    memory16set(0x1022 + seg, 0x0008, memory16get(0x1022 + seg, 0x0008) + seg);
    memory16set(0x1022 + seg, 0x000c, memory16get(0x1022 + seg, 0x000c) + seg);
    memory16set(0x1023 + seg, 0x0000, memory16get(0x1023 + seg, 0x0000) + seg);
    memory16set(0x1023 + seg, 0x0004, memory16get(0x1023 + seg, 0x0004) + seg);
    memory16set(0x1023 + seg, 0x0008, memory16get(0x1023 + seg, 0x0008) + seg);
    memory16set(0x1023 + seg, 0x000c, memory16get(0x1023 + seg, 0x000c) + seg);
    memory16set(0x1024 + seg, 0x0000, memory16get(0x1024 + seg, 0x0000) + seg);
    memory16set(0x1024 + seg, 0x0004, memory16get(0x1024 + seg, 0x0004) + seg);
    memory16set(0x1024 + seg, 0x0008, memory16get(0x1024 + seg, 0x0008) + seg);
    memory16set(0x1024 + seg, 0x000c, memory16get(0x1024 + seg, 0x000c) + seg);
    memory16set(0x1025 + seg, 0x0004, memory16get(0x1025 + seg, 0x0004) + seg);
    memory16set(0x1025 + seg, 0x0008, memory16get(0x1025 + seg, 0x0008) + seg);
    memory16set(0x1025 + seg, 0x000c, memory16get(0x1025 + seg, 0x000c) + seg);
    memory16set(0x1026 + seg, 0x0000, memory16get(0x1026 + seg, 0x0000) + seg);
    memory16set(0x1026 + seg, 0x0004, memory16get(0x1026 + seg, 0x0004) + seg);
    memory16set(0x1026 + seg, 0x0008, memory16get(0x1026 + seg, 0x0008) + seg);
    memory16set(0x1026 + seg, 0x000c, memory16get(0x1026 + seg, 0x000c) + seg);
    memory16set(0x1027 + seg, 0x0000, memory16get(0x1027 + seg, 0x0000) + seg);
    memory16set(0x1027 + seg, 0x0004, memory16get(0x1027 + seg, 0x0004) + seg);
    memory16set(0x1027 + seg, 0x0008, memory16get(0x1027 + seg, 0x0008) + seg);
    memory16set(0x1027 + seg, 0x000c, memory16get(0x1027 + seg, 0x000c) + seg);
    memory16set(0x1028 + seg, 0x0000, memory16get(0x1028 + seg, 0x0000) + seg);
    memory16set(0x1028 + seg, 0x0004, memory16get(0x1028 + seg, 0x0004) + seg);
    memory16set(0x1028 + seg, 0x0008, memory16get(0x1028 + seg, 0x0008) + seg);
    memory16set(0x1028 + seg, 0x000c, memory16get(0x1028 + seg, 0x000c) + seg);
    memory16set(0x1029 + seg, 0x0000, memory16get(0x1029 + seg, 0x0000) + seg);
    memory16set(0x1029 + seg, 0x0008, memory16get(0x1029 + seg, 0x0008) + seg);
    memory16set(0x1029 + seg, 0x000c, memory16get(0x1029 + seg, 0x000c) + seg);
    memory16set(0x102a + seg, 0x0000, memory16get(0x102a + seg, 0x0000) + seg);
    memory16set(0x102a + seg, 0x0004, memory16get(0x102a + seg, 0x0004) + seg);
    memory16set(0x102a + seg, 0x0008, memory16get(0x102a + seg, 0x0008) + seg);
    memory16set(0x102a + seg, 0x000c, memory16get(0x102a + seg, 0x000c) + seg);
    memory16set(0x102b + seg, 0x0000, memory16get(0x102b + seg, 0x0000) + seg);
    memory16set(0x102b + seg, 0x0004, memory16get(0x102b + seg, 0x0004) + seg);
    memory16set(0x102b + seg, 0x0008, memory16get(0x102b + seg, 0x0008) + seg);
    memory16set(0x102b + seg, 0x000c, memory16get(0x102b + seg, 0x000c) + seg);
    memory16set(0x102c + seg, 0x0002, memory16get(0x102c + seg, 0x0002) + seg);
    memory16set(0x102c + seg, 0x0006, memory16get(0x102c + seg, 0x0006) + seg);
    memory16set(0x102c + seg, 0x000a, memory16get(0x102c + seg, 0x000a) + seg);
    memory16set(0x102c + seg, 0x000e, memory16get(0x102c + seg, 0x000e) + seg);
    memory16set(0x102d + seg, 0x0002, memory16get(0x102d + seg, 0x0002) + seg);
    memory16set(0x102d + seg, 0x0006, memory16get(0x102d + seg, 0x0006) + seg);
    memory16set(0x102d + seg, 0x000a, memory16get(0x102d + seg, 0x000a) + seg);
    memory16set(0x102d + seg, 0x000e, memory16get(0x102d + seg, 0x000e) + seg);
    memory16set(0x102e + seg, 0x0004, memory16get(0x102e + seg, 0x0004) + seg);
    memory16set(0x102e + seg, 0x0008, memory16get(0x102e + seg, 0x0008) + seg);
    memory16set(0x102e + seg, 0x000c, memory16get(0x102e + seg, 0x000c) + seg);
    memory16set(0x102f + seg, 0x0000, memory16get(0x102f + seg, 0x0000) + seg);
    memory16set(0x102f + seg, 0x0006, memory16get(0x102f + seg, 0x0006) + seg);
    memory16set(0x102f + seg, 0x000a, memory16get(0x102f + seg, 0x000a) + seg);
    memory16set(0x102f + seg, 0x000e, memory16get(0x102f + seg, 0x000e) + seg);
    memory16set(0x1030 + seg, 0x0002, memory16get(0x1030 + seg, 0x0002) + seg);
    memory16set(0x1030 + seg, 0x0006, memory16get(0x1030 + seg, 0x0006) + seg);
    memory16set(0x1030 + seg, 0x000a, memory16get(0x1030 + seg, 0x000a) + seg);
    memory16set(0x1030 + seg, 0x000e, memory16get(0x1030 + seg, 0x000e) + seg);
    memory16set(0x1031 + seg, 0x0002, memory16get(0x1031 + seg, 0x0002) + seg);
    memory16set(0x1031 + seg, 0x0008, memory16get(0x1031 + seg, 0x0008) + seg);
    memory16set(0x1031 + seg, 0x000c, memory16get(0x1031 + seg, 0x000c) + seg);
    memory16set(0x1032 + seg, 0x0000, memory16get(0x1032 + seg, 0x0000) + seg);
    memory16set(0x1032 + seg, 0x0004, memory16get(0x1032 + seg, 0x0004) + seg);
    memory16set(0x1032 + seg, 0x000a, memory16get(0x1032 + seg, 0x000a) + seg);
    memory16set(0x1032 + seg, 0x000e, memory16get(0x1032 + seg, 0x000e) + seg);
    memory16set(0x1033 + seg, 0x0002, memory16get(0x1033 + seg, 0x0002) + seg);
    memory16set(0x1033 + seg, 0x0006, memory16get(0x1033 + seg, 0x0006) + seg);
    memory16set(0x1033 + seg, 0x000a, memory16get(0x1033 + seg, 0x000a) + seg);
    memory16set(0x1033 + seg, 0x000e, memory16get(0x1033 + seg, 0x000e) + seg);
    memory16set(0x1034 + seg, 0x0002, memory16get(0x1034 + seg, 0x0002) + seg);
    memory16set(0x1034 + seg, 0x0008, memory16get(0x1034 + seg, 0x0008) + seg);
    memory16set(0x1034 + seg, 0x000c, memory16get(0x1034 + seg, 0x000c) + seg);
    memory16set(0x1035 + seg, 0x0000, memory16get(0x1035 + seg, 0x0000) + seg);
    memory16set(0x1035 + seg, 0x0004, memory16get(0x1035 + seg, 0x0004) + seg);
    memory16set(0x1035 + seg, 0x0008, memory16get(0x1035 + seg, 0x0008) + seg);
    memory16set(0x1035 + seg, 0x000c, memory16get(0x1035 + seg, 0x000c) + seg);
    memory16set(0x1036 + seg, 0x0000, memory16get(0x1036 + seg, 0x0000) + seg);
    memory16set(0x1036 + seg, 0x0004, memory16get(0x1036 + seg, 0x0004) + seg);
    memory16set(0x1036 + seg, 0x0008, memory16get(0x1036 + seg, 0x0008) + seg);
    memory16set(0x1036 + seg, 0x000c, memory16get(0x1036 + seg, 0x000c) + seg);
    memory16set(0x1037 + seg, 0x0000, memory16get(0x1037 + seg, 0x0000) + seg);
    memory16set(0x1037 + seg, 0x0004, memory16get(0x1037 + seg, 0x0004) + seg);
    memory16set(0x1037 + seg, 0x0008, memory16get(0x1037 + seg, 0x0008) + seg);
    memory16set(0x1037 + seg, 0x000c, memory16get(0x1037 + seg, 0x000c) + seg);
    memory16set(0x1038 + seg, 0x0000, memory16get(0x1038 + seg, 0x0000) + seg);
    memory16set(0x1038 + seg, 0x0004, memory16get(0x1038 + seg, 0x0004) + seg);
    memory16set(0x1038 + seg, 0x000c, memory16get(0x1038 + seg, 0x000c) + seg);
    memory16set(0x1039 + seg, 0x0000, memory16get(0x1039 + seg, 0x0000) + seg);
    memory16set(0x1039 + seg, 0x0004, memory16get(0x1039 + seg, 0x0004) + seg);
    memory16set(0x1039 + seg, 0x0008, memory16get(0x1039 + seg, 0x0008) + seg);
    memory16set(0x1039 + seg, 0x000c, memory16get(0x1039 + seg, 0x000c) + seg);
    memory16set(0x103a + seg, 0x0000, memory16get(0x103a + seg, 0x0000) + seg);
    memory16set(0x103a + seg, 0x0004, memory16get(0x103a + seg, 0x0004) + seg);
    memory16set(0x103a + seg, 0x0008, memory16get(0x103a + seg, 0x0008) + seg);
    memory16set(0x103a + seg, 0x000c, memory16get(0x103a + seg, 0x000c) + seg);
    memory16set(0x103b + seg, 0x0000, memory16get(0x103b + seg, 0x0000) + seg);
    memory16set(0x103b + seg, 0x0004, memory16get(0x103b + seg, 0x0004) + seg);
    memory16set(0x103b + seg, 0x0008, memory16get(0x103b + seg, 0x0008) + seg);
    memory16set(0x103b + seg, 0x000c, memory16get(0x103b + seg, 0x000c) + seg);
    memory16set(0x103c + seg, 0x0000, memory16get(0x103c + seg, 0x0000) + seg);
    memory16set(0x103c + seg, 0x0004, memory16get(0x103c + seg, 0x0004) + seg);
    memory16set(0x103c + seg, 0x0008, memory16get(0x103c + seg, 0x0008) + seg);
    memory16set(0x103d + seg, 0x0000, memory16get(0x103d + seg, 0x0000) + seg);
    memory16set(0x103d + seg, 0x0004, memory16get(0x103d + seg, 0x0004) + seg);
    memory16set(0x103d + seg, 0x0008, memory16get(0x103d + seg, 0x0008) + seg);
    memory16set(0x103d + seg, 0x000c, memory16get(0x103d + seg, 0x000c) + seg);
    memory16set(0x103e + seg, 0x0000, memory16get(0x103e + seg, 0x0000) + seg);
    memory16set(0x103e + seg, 0x0004, memory16get(0x103e + seg, 0x0004) + seg);
    memory16set(0x103e + seg, 0x0008, memory16get(0x103e + seg, 0x0008) + seg);
    memory16set(0x103e + seg, 0x000c, memory16get(0x103e + seg, 0x000c) + seg);
    memory16set(0x103f + seg, 0x0000, memory16get(0x103f + seg, 0x0000) + seg);
    memory16set(0x103f + seg, 0x0004, memory16get(0x103f + seg, 0x0004) + seg);
    memory16set(0x103f + seg, 0x0008, memory16get(0x103f + seg, 0x0008) + seg);
    memory16set(0x103f + seg, 0x000c, memory16get(0x103f + seg, 0x000c) + seg);
    memory16set(0x1040 + seg, 0x0000, memory16get(0x1040 + seg, 0x0000) + seg);
    memory16set(0x1040 + seg, 0x0004, memory16get(0x1040 + seg, 0x0004) + seg);
    memory16set(0x1040 + seg, 0x0008, memory16get(0x1040 + seg, 0x0008) + seg);
    memory16set(0x1040 + seg, 0x000c, memory16get(0x1040 + seg, 0x000c) + seg);
    memory16set(0x1041 + seg, 0x0004, memory16get(0x1041 + seg, 0x0004) + seg);
    memory16set(0x1041 + seg, 0x0008, memory16get(0x1041 + seg, 0x0008) + seg);
    memory16set(0x1041 + seg, 0x000c, memory16get(0x1041 + seg, 0x000c) + seg);
    memory16set(0x1042 + seg, 0x0000, memory16get(0x1042 + seg, 0x0000) + seg);
    memory16set(0x1042 + seg, 0x0004, memory16get(0x1042 + seg, 0x0004) + seg);
    memory16set(0x1042 + seg, 0x0008, memory16get(0x1042 + seg, 0x0008) + seg);
    memory16set(0x1042 + seg, 0x000c, memory16get(0x1042 + seg, 0x000c) + seg);
    memory16set(0x1043 + seg, 0x0000, memory16get(0x1043 + seg, 0x0000) + seg);
    memory16set(0x1043 + seg, 0x0004, memory16get(0x1043 + seg, 0x0004) + seg);
    memory16set(0x1043 + seg, 0x0008, memory16get(0x1043 + seg, 0x0008) + seg);
    memory16set(0x1043 + seg, 0x000c, memory16get(0x1043 + seg, 0x000c) + seg);
    memory16set(0x1044 + seg, 0x0000, memory16get(0x1044 + seg, 0x0000) + seg);
    memory16set(0x1044 + seg, 0x0004, memory16get(0x1044 + seg, 0x0004) + seg);
    memory16set(0x1044 + seg, 0x0008, memory16get(0x1044 + seg, 0x0008) + seg);
    memory16set(0x1044 + seg, 0x000c, memory16get(0x1044 + seg, 0x000c) + seg);
    memory16set(0x1045 + seg, 0x0000, memory16get(0x1045 + seg, 0x0000) + seg);
    memory16set(0x1045 + seg, 0x0008, memory16get(0x1045 + seg, 0x0008) + seg);
    memory16set(0x1045 + seg, 0x000c, memory16get(0x1045 + seg, 0x000c) + seg);
    memory16set(0x1046 + seg, 0x0000, memory16get(0x1046 + seg, 0x0000) + seg);
    memory16set(0x1046 + seg, 0x0004, memory16get(0x1046 + seg, 0x0004) + seg);
    memory16set(0x1046 + seg, 0x0008, memory16get(0x1046 + seg, 0x0008) + seg);
    memory16set(0x1046 + seg, 0x000c, memory16get(0x1046 + seg, 0x000c) + seg);
    memory16set(0x1047 + seg, 0x0000, memory16get(0x1047 + seg, 0x0000) + seg);
    memory16set(0x1047 + seg, 0x0006, memory16get(0x1047 + seg, 0x0006) + seg);
    memory16set(0x1047 + seg, 0x000a, memory16get(0x1047 + seg, 0x000a) + seg);
    memory16set(0x1047 + seg, 0x000e, memory16get(0x1047 + seg, 0x000e) + seg);
    memory16set(0x1048 + seg, 0x0002, memory16get(0x1048 + seg, 0x0002) + seg);
    memory16set(0x1048 + seg, 0x0008, memory16get(0x1048 + seg, 0x0008) + seg);
    memory16set(0x1048 + seg, 0x000c, memory16get(0x1048 + seg, 0x000c) + seg);
    memory16set(0x1049 + seg, 0x0000, memory16get(0x1049 + seg, 0x0000) + seg);
    memory16set(0x1049 + seg, 0x0004, memory16get(0x1049 + seg, 0x0004) + seg);
    memory16set(0x1049 + seg, 0x0008, memory16get(0x1049 + seg, 0x0008) + seg);
    memory16set(0x1049 + seg, 0x000c, memory16get(0x1049 + seg, 0x000c) + seg);
    memory16set(0x104a + seg, 0x0000, memory16get(0x104a + seg, 0x0000) + seg);
    memory16set(0x104a + seg, 0x0006, memory16get(0x104a + seg, 0x0006) + seg);
    memory16set(0x104a + seg, 0x000a, memory16get(0x104a + seg, 0x000a) + seg);
    memory16set(0x104a + seg, 0x000e, memory16get(0x104a + seg, 0x000e) + seg);
    memory16set(0x104b + seg, 0x0002, memory16get(0x104b + seg, 0x0002) + seg);
    memory16set(0x104b + seg, 0x0006, memory16get(0x104b + seg, 0x0006) + seg);
    memory16set(0x104b + seg, 0x000a, memory16get(0x104b + seg, 0x000a) + seg);
    memory16set(0x104b + seg, 0x000e, memory16get(0x104b + seg, 0x000e) + seg);
    memory16set(0x104c + seg, 0x0002, memory16get(0x104c + seg, 0x0002) + seg);
    memory16set(0x104c + seg, 0x0006, memory16get(0x104c + seg, 0x0006) + seg);
    memory16set(0x104c + seg, 0x000a, memory16get(0x104c + seg, 0x000a) + seg);
    memory16set(0x104c + seg, 0x000e, memory16get(0x104c + seg, 0x000e) + seg);
    memory16set(0x104d + seg, 0x0002, memory16get(0x104d + seg, 0x0002) + seg);
    memory16set(0x104d + seg, 0x0006, memory16get(0x104d + seg, 0x0006) + seg);
    memory16set(0x104d + seg, 0x000a, memory16get(0x104d + seg, 0x000a) + seg);
    memory16set(0x104d + seg, 0x000e, memory16get(0x104d + seg, 0x000e) + seg);
    memory16set(0x104e + seg, 0x0002, memory16get(0x104e + seg, 0x0002) + seg);
    memory16set(0x104e + seg, 0x0006, memory16get(0x104e + seg, 0x0006) + seg);
    memory16set(0x104e + seg, 0x000a, memory16get(0x104e + seg, 0x000a) + seg);
    memory16set(0x104e + seg, 0x000e, memory16get(0x104e + seg, 0x000e) + seg);
    memory16set(0x104f + seg, 0x0002, memory16get(0x104f + seg, 0x0002) + seg);
    memory16set(0x104f + seg, 0x0006, memory16get(0x104f + seg, 0x0006) + seg);
    memory16set(0x104f + seg, 0x000a, memory16get(0x104f + seg, 0x000a) + seg);
    memory16set(0x104f + seg, 0x000e, memory16get(0x104f + seg, 0x000e) + seg);
    memory16set(0x1050 + seg, 0x0002, memory16get(0x1050 + seg, 0x0002) + seg);
    memory16set(0x1050 + seg, 0x0006, memory16get(0x1050 + seg, 0x0006) + seg);
    memory16set(0x1050 + seg, 0x000a, memory16get(0x1050 + seg, 0x000a) + seg);
    memory16set(0x1050 + seg, 0x000e, memory16get(0x1050 + seg, 0x000e) + seg);
    memory16set(0x1051 + seg, 0x0002, memory16get(0x1051 + seg, 0x0002) + seg);
    memory16set(0x1051 + seg, 0x0006, memory16get(0x1051 + seg, 0x0006) + seg);
    memory16set(0x1051 + seg, 0x000a, memory16get(0x1051 + seg, 0x000a) + seg);
    memory16set(0x1051 + seg, 0x000e, memory16get(0x1051 + seg, 0x000e) + seg);
    memory16set(0x1052 + seg, 0x0002, memory16get(0x1052 + seg, 0x0002) + seg);
    memory16set(0x1052 + seg, 0x0008, memory16get(0x1052 + seg, 0x0008) + seg);
    memory16set(0x1052 + seg, 0x000c, memory16get(0x1052 + seg, 0x000c) + seg);
    memory16set(0x1053 + seg, 0x0000, memory16get(0x1053 + seg, 0x0000) + seg);
    memory16set(0x1053 + seg, 0x0004, memory16get(0x1053 + seg, 0x0004) + seg);
    memory16set(0x1053 + seg, 0x0008, memory16get(0x1053 + seg, 0x0008) + seg);
    memory16set(0x1053 + seg, 0x000c, memory16get(0x1053 + seg, 0x000c) + seg);
    memory16set(0x1054 + seg, 0x0000, memory16get(0x1054 + seg, 0x0000) + seg);
    memory16set(0x1054 + seg, 0x0004, memory16get(0x1054 + seg, 0x0004) + seg);
    memory16set(0x1054 + seg, 0x0008, memory16get(0x1054 + seg, 0x0008) + seg);
    memory16set(0x1054 + seg, 0x000c, memory16get(0x1054 + seg, 0x000c) + seg);
    memory16set(0x1055 + seg, 0x0000, memory16get(0x1055 + seg, 0x0000) + seg);
    memory16set(0x1055 + seg, 0x0004, memory16get(0x1055 + seg, 0x0004) + seg);
    memory16set(0x1055 + seg, 0x0008, memory16get(0x1055 + seg, 0x0008) + seg);
    memory16set(0x1055 + seg, 0x000c, memory16get(0x1055 + seg, 0x000c) + seg);
    memory16set(0x1056 + seg, 0x0000, memory16get(0x1056 + seg, 0x0000) + seg);
    memory16set(0x1056 + seg, 0x0004, memory16get(0x1056 + seg, 0x0004) + seg);
    memory16set(0x1056 + seg, 0x000a, memory16get(0x1056 + seg, 0x000a) + seg);
    memory16set(0x1056 + seg, 0x000e, memory16get(0x1056 + seg, 0x000e) + seg);
    memory16set(0x1057 + seg, 0x0002, memory16get(0x1057 + seg, 0x0002) + seg);
    memory16set(0x1057 + seg, 0x0006, memory16get(0x1057 + seg, 0x0006) + seg);
    memory16set(0x1057 + seg, 0x000a, memory16get(0x1057 + seg, 0x000a) + seg);
    memory16set(0x1057 + seg, 0x000e, memory16get(0x1057 + seg, 0x000e) + seg);
    memory16set(0x1058 + seg, 0x0002, memory16get(0x1058 + seg, 0x0002) + seg);
    memory16set(0x1058 + seg, 0x0006, memory16get(0x1058 + seg, 0x0006) + seg);
    memory16set(0x1058 + seg, 0x000a, memory16get(0x1058 + seg, 0x000a) + seg);
    memory16set(0x1058 + seg, 0x000e, memory16get(0x1058 + seg, 0x000e) + seg);
    memory16set(0x1059 + seg, 0x0002, memory16get(0x1059 + seg, 0x0002) + seg);
    memory16set(0x1059 + seg, 0x0006, memory16get(0x1059 + seg, 0x0006) + seg);
    memory16set(0x1059 + seg, 0x000a, memory16get(0x1059 + seg, 0x000a) + seg);
    memory16set(0x1059 + seg, 0x000e, memory16get(0x1059 + seg, 0x000e) + seg);
    memory16set(0x105a + seg, 0x0002, memory16get(0x105a + seg, 0x0002) + seg);
    memory16set(0x105a + seg, 0x0006, memory16get(0x105a + seg, 0x0006) + seg);
    memory16set(0x105a + seg, 0x000c, memory16get(0x105a + seg, 0x000c) + seg);
    memory16set(0x105b + seg, 0x0000, memory16get(0x105b + seg, 0x0000) + seg);
    memory16set(0x105b + seg, 0x0004, memory16get(0x105b + seg, 0x0004) + seg);
    memory16set(0x105b + seg, 0x0008, memory16get(0x105b + seg, 0x0008) + seg);
    memory16set(0x105b + seg, 0x000c, memory16get(0x105b + seg, 0x000c) + seg);
    memory16set(0x105c + seg, 0x0000, memory16get(0x105c + seg, 0x0000) + seg);
    memory16set(0x105c + seg, 0x0004, memory16get(0x105c + seg, 0x0004) + seg);
    memory16set(0x105c + seg, 0x0008, memory16get(0x105c + seg, 0x0008) + seg);
    memory16set(0x105c + seg, 0x000c, memory16get(0x105c + seg, 0x000c) + seg);
    memory16set(0x105d + seg, 0x0000, memory16get(0x105d + seg, 0x0000) + seg);
    memory16set(0x105d + seg, 0x0004, memory16get(0x105d + seg, 0x0004) + seg);
    memory16set(0x105d + seg, 0x0008, memory16get(0x105d + seg, 0x0008) + seg);
    memory16set(0x105d + seg, 0x000c, memory16get(0x105d + seg, 0x000c) + seg);
    memory16set(0x105e + seg, 0x0000, memory16get(0x105e + seg, 0x0000) + seg);
    memory16set(0x105e + seg, 0x0004, memory16get(0x105e + seg, 0x0004) + seg);
    memory16set(0x105e + seg, 0x0008, memory16get(0x105e + seg, 0x0008) + seg);
    memory16set(0x105e + seg, 0x000e, memory16get(0x105e + seg, 0x000e) + seg);
    memory16set(0x105f + seg, 0x0002, memory16get(0x105f + seg, 0x0002) + seg);
    memory16set(0x105f + seg, 0x0006, memory16get(0x105f + seg, 0x0006) + seg);
    memory16set(0x105f + seg, 0x000a, memory16get(0x105f + seg, 0x000a) + seg);
    memory16set(0x105f + seg, 0x000e, memory16get(0x105f + seg, 0x000e) + seg);
    memory16set(0x1060 + seg, 0x0002, memory16get(0x1060 + seg, 0x0002) + seg);
    memory16set(0x1060 + seg, 0x0006, memory16get(0x1060 + seg, 0x0006) + seg);
    memory16set(0x1060 + seg, 0x000a, memory16get(0x1060 + seg, 0x000a) + seg);
    memory16set(0x1060 + seg, 0x000e, memory16get(0x1060 + seg, 0x000e) + seg);
    memory16set(0x1061 + seg, 0x0002, memory16get(0x1061 + seg, 0x0002) + seg);
    memory16set(0x1061 + seg, 0x0006, memory16get(0x1061 + seg, 0x0006) + seg);
    memory16set(0x1061 + seg, 0x000a, memory16get(0x1061 + seg, 0x000a) + seg);
    memory16set(0x1061 + seg, 0x000e, memory16get(0x1061 + seg, 0x000e) + seg);
    memory16set(0x1062 + seg, 0x0002, memory16get(0x1062 + seg, 0x0002) + seg);
    memory16set(0x1062 + seg, 0x0006, memory16get(0x1062 + seg, 0x0006) + seg);
    memory16set(0x1062 + seg, 0x000a, memory16get(0x1062 + seg, 0x000a) + seg);
    memory16set(0x1063 + seg, 0x0000, memory16get(0x1063 + seg, 0x0000) + seg);
    memory16set(0x1063 + seg, 0x0004, memory16get(0x1063 + seg, 0x0004) + seg);
    memory16set(0x1063 + seg, 0x0008, memory16get(0x1063 + seg, 0x0008) + seg);
    memory16set(0x1063 + seg, 0x000c, memory16get(0x1063 + seg, 0x000c) + seg);
    memory16set(0x1064 + seg, 0x0000, memory16get(0x1064 + seg, 0x0000) + seg);
    memory16set(0x1064 + seg, 0x0004, memory16get(0x1064 + seg, 0x0004) + seg);
    memory16set(0x1064 + seg, 0x0008, memory16get(0x1064 + seg, 0x0008) + seg);
    memory16set(0x1064 + seg, 0x000c, memory16get(0x1064 + seg, 0x000c) + seg);
    memory16set(0x1065 + seg, 0x0000, memory16get(0x1065 + seg, 0x0000) + seg);
    memory16set(0x1065 + seg, 0x0004, memory16get(0x1065 + seg, 0x0004) + seg);
    memory16set(0x1065 + seg, 0x0008, memory16get(0x1065 + seg, 0x0008) + seg);
    memory16set(0x1065 + seg, 0x000c, memory16get(0x1065 + seg, 0x000c) + seg);
    memory16set(0x1066 + seg, 0x0000, memory16get(0x1066 + seg, 0x0000) + seg);
    memory16set(0x1066 + seg, 0x0004, memory16get(0x1066 + seg, 0x0004) + seg);
    memory16set(0x1066 + seg, 0x0008, memory16get(0x1066 + seg, 0x0008) + seg);
    memory16set(0x1066 + seg, 0x000c, memory16get(0x1066 + seg, 0x000c) + seg);
    memory16set(0x106f + seg, 0x0004, memory16get(0x106f + seg, 0x0004) + seg);
    memory16set(0x106f + seg, 0x0008, memory16get(0x106f + seg, 0x0008) + seg);
    memory16set(0x106f + seg, 0x000c, memory16get(0x106f + seg, 0x000c) + seg);
    memory16set(0x1070 + seg, 0x0000, memory16get(0x1070 + seg, 0x0000) + seg);
    memory16set(0x1070 + seg, 0x0004, memory16get(0x1070 + seg, 0x0004) + seg);
    memory16set(0x1070 + seg, 0x0008, memory16get(0x1070 + seg, 0x0008) + seg);
    memory16set(0x1070 + seg, 0x000c, memory16get(0x1070 + seg, 0x000c) + seg);
    memory16set(0x1071 + seg, 0x0000, memory16get(0x1071 + seg, 0x0000) + seg);
    memory16set(0x1071 + seg, 0x0004, memory16get(0x1071 + seg, 0x0004) + seg);
    memory16set(0x1071 + seg, 0x0008, memory16get(0x1071 + seg, 0x0008) + seg);
    memory16set(0x1071 + seg, 0x000c, memory16get(0x1071 + seg, 0x000c) + seg);
    memory16set(0x1072 + seg, 0x0000, memory16get(0x1072 + seg, 0x0000) + seg);
    memory16set(0x1072 + seg, 0x0004, memory16get(0x1072 + seg, 0x0004) + seg);
    memory16set(0x1072 + seg, 0x0008, memory16get(0x1072 + seg, 0x0008) + seg);
    memory16set(0x1072 + seg, 0x000c, memory16get(0x1072 + seg, 0x000c) + seg);
    memory16set(0x1072 + seg, 0x000e, memory16get(0x1072 + seg, 0x000e) + seg);
    memory16set(0x1073 + seg, 0x0002, memory16get(0x1073 + seg, 0x0002) + seg);
    memory16set(0x1073 + seg, 0x0006, memory16get(0x1073 + seg, 0x0006) + seg);
    memory16set(0x1073 + seg, 0x000a, memory16get(0x1073 + seg, 0x000a) + seg);
    memory16set(0x1073 + seg, 0x000e, memory16get(0x1073 + seg, 0x000e) + seg);
    memory16set(0x1074 + seg, 0x0004, memory16get(0x1074 + seg, 0x0004) + seg);
    memory16set(0x1074 + seg, 0x0008, memory16get(0x1074 + seg, 0x0008) + seg);
    memory16set(0x1074 + seg, 0x000c, memory16get(0x1074 + seg, 0x000c) + seg);
    memory16set(0x1075 + seg, 0x0000, memory16get(0x1075 + seg, 0x0000) + seg);
    memory16set(0x1075 + seg, 0x0004, memory16get(0x1075 + seg, 0x0004) + seg);
    memory16set(0x1075 + seg, 0x0008, memory16get(0x1075 + seg, 0x0008) + seg);
    memory16set(0x1075 + seg, 0x000c, memory16get(0x1075 + seg, 0x000c) + seg);
    memory16set(0x1076 + seg, 0x0000, memory16get(0x1076 + seg, 0x0000) + seg);
    memory16set(0x1076 + seg, 0x0004, memory16get(0x1076 + seg, 0x0004) + seg);
    memory16set(0x1076 + seg, 0x0008, memory16get(0x1076 + seg, 0x0008) + seg);
    memory16set(0x1076 + seg, 0x000c, memory16get(0x1076 + seg, 0x000c) + seg);
    memory16set(0x1077 + seg, 0x0000, memory16get(0x1077 + seg, 0x0000) + seg);
    memory16set(0x1077 + seg, 0x0004, memory16get(0x1077 + seg, 0x0004) + seg);
    memory16set(0x1077 + seg, 0x0008, memory16get(0x1077 + seg, 0x0008) + seg);
    memory16set(0x1077 + seg, 0x000c, memory16get(0x1077 + seg, 0x000c) + seg);
    memory16set(0x1078 + seg, 0x0000, memory16get(0x1078 + seg, 0x0000) + seg);
    memory16set(0x1078 + seg, 0x0004, memory16get(0x1078 + seg, 0x0004) + seg);
    memory16set(0x1078 + seg, 0x0008, memory16get(0x1078 + seg, 0x0008) + seg);
    memory16set(0x1078 + seg, 0x000c, memory16get(0x1078 + seg, 0x000c) + seg);
    memory16set(0x1079 + seg, 0x0000, memory16get(0x1079 + seg, 0x0000) + seg);
    memory16set(0x1079 + seg, 0x0004, memory16get(0x1079 + seg, 0x0004) + seg);
    memory16set(0x1079 + seg, 0x0008, memory16get(0x1079 + seg, 0x0008) + seg);
    memory16set(0x1079 + seg, 0x000c, memory16get(0x1079 + seg, 0x000c) + seg);
    memory16set(0x107a + seg, 0x0000, memory16get(0x107a + seg, 0x0000) + seg);
    memory16set(0x107a + seg, 0x0004, memory16get(0x107a + seg, 0x0004) + seg);
    memory16set(0x107a + seg, 0x0008, memory16get(0x107a + seg, 0x0008) + seg);
    memory16set(0x107a + seg, 0x000c, memory16get(0x107a + seg, 0x000c) + seg);
    memory16set(0x107b + seg, 0x0000, memory16get(0x107b + seg, 0x0000) + seg);
    memory16set(0x107b + seg, 0x0004, memory16get(0x107b + seg, 0x0004) + seg);
    memory16set(0x107b + seg, 0x0008, memory16get(0x107b + seg, 0x0008) + seg);
    memory16set(0x107b + seg, 0x000c, memory16get(0x107b + seg, 0x000c) + seg);
    memory16set(0x107c + seg, 0x0000, memory16get(0x107c + seg, 0x0000) + seg);
    memory16set(0x107c + seg, 0x0004, memory16get(0x107c + seg, 0x0004) + seg);
    memory16set(0x107c + seg, 0x0008, memory16get(0x107c + seg, 0x0008) + seg);
    memory16set(0x107c + seg, 0x000c, memory16get(0x107c + seg, 0x000c) + seg);
    memory16set(0x107d + seg, 0x0000, memory16get(0x107d + seg, 0x0000) + seg);
    memory16set(0x107d + seg, 0x0004, memory16get(0x107d + seg, 0x0004) + seg);
    memory16set(0x107d + seg, 0x0008, memory16get(0x107d + seg, 0x0008) + seg);
    memory16set(0x107d + seg, 0x000c, memory16get(0x107d + seg, 0x000c) + seg);
    memory16set(0x107e + seg, 0x0000, memory16get(0x107e + seg, 0x0000) + seg);
    memory16set(0x107e + seg, 0x0004, memory16get(0x107e + seg, 0x0004) + seg);
    memory16set(0x107e + seg, 0x0008, memory16get(0x107e + seg, 0x0008) + seg);
    memory16set(0x107e + seg, 0x000c, memory16get(0x107e + seg, 0x000c) + seg);
    memory16set(0x107f + seg, 0x0000, memory16get(0x107f + seg, 0x0000) + seg);
    memory16set(0x107f + seg, 0x0004, memory16get(0x107f + seg, 0x0004) + seg);
    memory16set(0x107f + seg, 0x0008, memory16get(0x107f + seg, 0x0008) + seg);
    memory16set(0x107f + seg, 0x000c, memory16get(0x107f + seg, 0x000c) + seg);
    memory16set(0x1080 + seg, 0x0000, memory16get(0x1080 + seg, 0x0000) + seg);
    memory16set(0x1080 + seg, 0x0004, memory16get(0x1080 + seg, 0x0004) + seg);
    memory16set(0x1080 + seg, 0x0008, memory16get(0x1080 + seg, 0x0008) + seg);
    memory16set(0x1080 + seg, 0x000c, memory16get(0x1080 + seg, 0x000c) + seg);
    memory16set(0x1081 + seg, 0x0000, memory16get(0x1081 + seg, 0x0000) + seg);
    memory16set(0x1081 + seg, 0x0006, memory16get(0x1081 + seg, 0x0006) + seg);
    memory16set(0x1081 + seg, 0x000a, memory16get(0x1081 + seg, 0x000a) + seg);
    memory16set(0x1081 + seg, 0x000e, memory16get(0x1081 + seg, 0x000e) + seg);
    memory16set(0x1082 + seg, 0x0002, memory16get(0x1082 + seg, 0x0002) + seg);
    memory16set(0x1082 + seg, 0x0006, memory16get(0x1082 + seg, 0x0006) + seg);
    memory16set(0x1082 + seg, 0x000a, memory16get(0x1082 + seg, 0x000a) + seg);
    memory16set(0x1082 + seg, 0x000e, memory16get(0x1082 + seg, 0x000e) + seg);
    memory16set(0x1083 + seg, 0x0002, memory16get(0x1083 + seg, 0x0002) + seg);
    memory16set(0x1083 + seg, 0x0006, memory16get(0x1083 + seg, 0x0006) + seg);
    memory16set(0x1083 + seg, 0x000c, memory16get(0x1083 + seg, 0x000c) + seg);
    memory16set(0x1084 + seg, 0x0000, memory16get(0x1084 + seg, 0x0000) + seg);
    memory16set(0x1084 + seg, 0x0004, memory16get(0x1084 + seg, 0x0004) + seg);
    memory16set(0x1084 + seg, 0x0008, memory16get(0x1084 + seg, 0x0008) + seg);
    memory16set(0x1084 + seg, 0x000e, memory16get(0x1084 + seg, 0x000e) + seg);
    memory16set(0x1085 + seg, 0x0002, memory16get(0x1085 + seg, 0x0002) + seg);
    memory16set(0x1085 + seg, 0x0006, memory16get(0x1085 + seg, 0x0006) + seg);
    memory16set(0x1085 + seg, 0x000a, memory16get(0x1085 + seg, 0x000a) + seg);
    memory16set(0x1085 + seg, 0x000e, memory16get(0x1085 + seg, 0x000e) + seg);
    memory16set(0x1086 + seg, 0x0002, memory16get(0x1086 + seg, 0x0002) + seg);
    memory16set(0x1086 + seg, 0x0006, memory16get(0x1086 + seg, 0x0006) + seg);
    memory16set(0x1086 + seg, 0x000a, memory16get(0x1086 + seg, 0x000a) + seg);
    memory16set(0x1086 + seg, 0x000e, memory16get(0x1086 + seg, 0x000e) + seg);
    memory16set(0x1087 + seg, 0x0002, memory16get(0x1087 + seg, 0x0002) + seg);
    memory16set(0x1087 + seg, 0x0008, memory16get(0x1087 + seg, 0x0008) + seg);
    memory16set(0x1087 + seg, 0x000c, memory16get(0x1087 + seg, 0x000c) + seg);
    memory16set(0x1088 + seg, 0x0000, memory16get(0x1088 + seg, 0x0000) + seg);
    memory16set(0x1088 + seg, 0x0004, memory16get(0x1088 + seg, 0x0004) + seg);
    memory16set(0x1088 + seg, 0x0008, memory16get(0x1088 + seg, 0x0008) + seg);
    memory16set(0x1088 + seg, 0x000c, memory16get(0x1088 + seg, 0x000c) + seg);
    memory16set(0x1089 + seg, 0x0000, memory16get(0x1089 + seg, 0x0000) + seg);
    memory16set(0x1089 + seg, 0x0004, memory16get(0x1089 + seg, 0x0004) + seg);
    memory16set(0x1089 + seg, 0x0008, memory16get(0x1089 + seg, 0x0008) + seg);
    memory16set(0x1089 + seg, 0x000c, memory16get(0x1089 + seg, 0x000c) + seg);
    memory16set(0x108a + seg, 0x0002, memory16get(0x108a + seg, 0x0002) + seg);
    memory16set(0x108a + seg, 0x0006, memory16get(0x108a + seg, 0x0006) + seg);
    memory16set(0x108a + seg, 0x000a, memory16get(0x108a + seg, 0x000a) + seg);
    memory16set(0x108a + seg, 0x000e, memory16get(0x108a + seg, 0x000e) + seg);
    memory16set(0x108b + seg, 0x0002, memory16get(0x108b + seg, 0x0002) + seg);
    memory16set(0x108b + seg, 0x0006, memory16get(0x108b + seg, 0x0006) + seg);
    memory16set(0x108b + seg, 0x000a, memory16get(0x108b + seg, 0x000a) + seg);
    memory16set(0x108b + seg, 0x000e, memory16get(0x108b + seg, 0x000e) + seg);
    memory16set(0x108c + seg, 0x0002, memory16get(0x108c + seg, 0x0002) + seg);
    memory16set(0x108c + seg, 0x0006, memory16get(0x108c + seg, 0x0006) + seg);
    memory16set(0x108c + seg, 0x000c, memory16get(0x108c + seg, 0x000c) + seg);
    memory16set(0x108d + seg, 0x0000, memory16get(0x108d + seg, 0x0000) + seg);
    memory16set(0x108d + seg, 0x0004, memory16get(0x108d + seg, 0x0004) + seg);
    memory16set(0x108d + seg, 0x0008, memory16get(0x108d + seg, 0x0008) + seg);
    memory16set(0x108d + seg, 0x000c, memory16get(0x108d + seg, 0x000c) + seg);
    memory16set(0x108e + seg, 0x0000, memory16get(0x108e + seg, 0x0000) + seg);
    memory16set(0x108e + seg, 0x0004, memory16get(0x108e + seg, 0x0004) + seg);
    memory16set(0x108e + seg, 0x0008, memory16get(0x108e + seg, 0x0008) + seg);
    memory16set(0x108e + seg, 0x000c, memory16get(0x108e + seg, 0x000c) + seg);
    memory16set(0x108f + seg, 0x0000, memory16get(0x108f + seg, 0x0000) + seg);
    memory16set(0x1091 + seg, 0x0004, memory16get(0x1091 + seg, 0x0004) + seg);
    memory16set(0x1091 + seg, 0x0008, memory16get(0x1091 + seg, 0x0008) + seg);
    memory16set(0x1093 + seg, 0x000a, memory16get(0x1093 + seg, 0x000a) + seg);
    memory16set(0x1093 + seg, 0x000e, memory16get(0x1093 + seg, 0x000e) + seg);
    memory16set(0x1096 + seg, 0x0000, memory16get(0x1096 + seg, 0x0000) + seg);
    memory16set(0x1096 + seg, 0x0004, memory16get(0x1096 + seg, 0x0004) + seg);
    memory16set(0x1098 + seg, 0x0006, memory16get(0x1098 + seg, 0x0006) + seg);
    memory16set(0x1098 + seg, 0x000a, memory16get(0x1098 + seg, 0x000a) + seg);
    memory16set(0x109a + seg, 0x000c, memory16get(0x109a + seg, 0x000c) + seg);
    memory16set(0x109b + seg, 0x0000, memory16get(0x109b + seg, 0x0000) + seg);
    memory16set(0x109d + seg, 0x0002, memory16get(0x109d + seg, 0x0002) + seg);
    memory16set(0x109d + seg, 0x0006, memory16get(0x109d + seg, 0x0006) + seg);
    memory16set(0x109f + seg, 0x0008, memory16get(0x109f + seg, 0x0008) + seg);
    memory16set(0x109f + seg, 0x000c, memory16get(0x109f + seg, 0x000c) + seg);
    memory16set(0x10a1 + seg, 0x000e, memory16get(0x10a1 + seg, 0x000e) + seg);
    memory16set(0x10a2 + seg, 0x0002, memory16get(0x10a2 + seg, 0x0002) + seg);
    memory16set(0x10a4 + seg, 0x0004, memory16get(0x10a4 + seg, 0x0004) + seg);
    memory16set(0x10a4 + seg, 0x0008, memory16get(0x10a4 + seg, 0x0008) + seg);
    memory16set(0x10a6 + seg, 0x000a, memory16get(0x10a6 + seg, 0x000a) + seg);
    memory16set(0x10a6 + seg, 0x000e, memory16get(0x10a6 + seg, 0x000e) + seg);
    memory16set(0x10a9 + seg, 0x0000, memory16get(0x10a9 + seg, 0x0000) + seg);
    memory16set(0x10a9 + seg, 0x0004, memory16get(0x10a9 + seg, 0x0004) + seg);
    memory16set(0x10ab + seg, 0x0006, memory16get(0x10ab + seg, 0x0006) + seg);
    memory16set(0x10ab + seg, 0x000a, memory16get(0x10ab + seg, 0x000a) + seg);
    memory16set(0x10ad + seg, 0x0000, memory16get(0x10ad + seg, 0x0000) + seg);
    memory16set(0x10ad + seg, 0x0008, memory16get(0x10ad + seg, 0x0008) + seg);
    memory16set(0x10ae + seg, 0x0000, memory16get(0x10ae + seg, 0x0000) + seg);
    memory16set(0x10ae + seg, 0x0008, memory16get(0x10ae + seg, 0x0008) + seg);
    memory16set(0x10af + seg, 0x0000, memory16get(0x10af + seg, 0x0000) + seg);
    memory16set(0x10af + seg, 0x0008, memory16get(0x10af + seg, 0x0008) + seg);
    memory16set(0x10b0 + seg, 0x0000, memory16get(0x10b0 + seg, 0x0000) + seg);
    memory16set(0x10b0 + seg, 0x0008, memory16get(0x10b0 + seg, 0x0008) + seg);
    memory16set(0x10b1 + seg, 0x0000, memory16get(0x10b1 + seg, 0x0000) + seg);
    memory16set(0x10b1 + seg, 0x0008, memory16get(0x10b1 + seg, 0x0008) + seg);
    memory16set(0x10b2 + seg, 0x0000, memory16get(0x10b2 + seg, 0x0000) + seg);
    memory16set(0x10b2 + seg, 0x0008, memory16get(0x10b2 + seg, 0x0008) + seg);
    memory16set(0x10b3 + seg, 0x0000, memory16get(0x10b3 + seg, 0x0000) + seg);
    memory16set(0x10b3 + seg, 0x0008, memory16get(0x10b3 + seg, 0x0008) + seg);
    memory16set(0x10b4 + seg, 0x0000, memory16get(0x10b4 + seg, 0x0000) + seg);
    memory16set(0x10b4 + seg, 0x0008, memory16get(0x10b4 + seg, 0x0008) + seg);
    memory16set(0x10b5 + seg, 0x0000, memory16get(0x10b5 + seg, 0x0000) + seg);
    memory16set(0x10b5 + seg, 0x0008, memory16get(0x10b5 + seg, 0x0008) + seg);
    memory16set(0x10b6 + seg, 0x0000, memory16get(0x10b6 + seg, 0x0000) + seg);
    memory16set(0x10b6 + seg, 0x0008, memory16get(0x10b6 + seg, 0x0008) + seg);
    memory16set(0x10b7 + seg, 0x0000, memory16get(0x10b7 + seg, 0x0000) + seg);
    memory16set(0x10b7 + seg, 0x0008, memory16get(0x10b7 + seg, 0x0008) + seg);
    memory16set(0x10b8 + seg, 0x0000, memory16get(0x10b8 + seg, 0x0000) + seg);
    memory16set(0x10b8 + seg, 0x0008, memory16get(0x10b8 + seg, 0x0008) + seg);
    memory16set(0x10b9 + seg, 0x0000, memory16get(0x10b9 + seg, 0x0000) + seg);
    memory16set(0x10b9 + seg, 0x0008, memory16get(0x10b9 + seg, 0x0008) + seg);
    memory16set(0x10ba + seg, 0x0000, memory16get(0x10ba + seg, 0x0000) + seg);
    memory16set(0x10ba + seg, 0x0008, memory16get(0x10ba + seg, 0x0008) + seg);
    memory16set(0x10bb + seg, 0x0000, memory16get(0x10bb + seg, 0x0000) + seg);
    memory16set(0x10bb + seg, 0x0008, memory16get(0x10bb + seg, 0x0008) + seg);
    memory16set(0x10bc + seg, 0x0000, memory16get(0x10bc + seg, 0x0000) + seg);
    memory16set(0x10bc + seg, 0x0008, memory16get(0x10bc + seg, 0x0008) + seg);
    memory16set(0x10bd + seg, 0x0000, memory16get(0x10bd + seg, 0x0000) + seg);
    memory16set(0x10bd + seg, 0x0008, memory16get(0x10bd + seg, 0x0008) + seg);
    memory16set(0x10be + seg, 0x0000, memory16get(0x10be + seg, 0x0000) + seg);
    memory16set(0x10be + seg, 0x0008, memory16get(0x10be + seg, 0x0008) + seg);
    memory16set(0x10bf + seg, 0x0000, memory16get(0x10bf + seg, 0x0000) + seg);
    memory16set(0x10bf + seg, 0x0008, memory16get(0x10bf + seg, 0x0008) + seg);
    memory16set(0x10c0 + seg, 0x0000, memory16get(0x10c0 + seg, 0x0000) + seg);
    memory16set(0x10c0 + seg, 0x0008, memory16get(0x10c0 + seg, 0x0008) + seg);
    memory16set(0x10c1 + seg, 0x0000, memory16get(0x10c1 + seg, 0x0000) + seg);
    memory16set(0x10c1 + seg, 0x0008, memory16get(0x10c1 + seg, 0x0008) + seg);
    memory16set(0x10c2 + seg, 0x0000, memory16get(0x10c2 + seg, 0x0000) + seg);
    memory16set(0x10c2 + seg, 0x0008, memory16get(0x10c2 + seg, 0x0008) + seg);
    memory16set(0x10c3 + seg, 0x0000, memory16get(0x10c3 + seg, 0x0000) + seg);
    memory16set(0x10c3 + seg, 0x0008, memory16get(0x10c3 + seg, 0x0008) + seg);
    memory16set(0x10c4 + seg, 0x0000, memory16get(0x10c4 + seg, 0x0000) + seg);
    memory16set(0x10c4 + seg, 0x0008, memory16get(0x10c4 + seg, 0x0008) + seg);
    memory16set(0x10c5 + seg, 0x0000, memory16get(0x10c5 + seg, 0x0000) + seg);
    memory16set(0x10c5 + seg, 0x0008, memory16get(0x10c5 + seg, 0x0008) + seg);
    memory16set(0x10c6 + seg, 0x0000, memory16get(0x10c6 + seg, 0x0000) + seg);
    memory16set(0x10c6 + seg, 0x0008, memory16get(0x10c6 + seg, 0x0008) + seg);
}
function* sub_1ed0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0b52;
        ds = r16[ax];
        pc = 0x1ed8;
        break;
    case 0x1ed8:
        yield* sub_54c6();
        yield* sub_51b6();
        memory16set(ds, 0x4f88, 0x0001);
        yield* sub_342c();
        r16[bx] = 0x0bde;
        yield* sub_23b5();
        yield* sub_286b();
        yield* sub_34f3();
        yield* sub_8d2a();
        yield* sub_8d5c();
        yield* sub_586b();
        yield* sub_5901();
        memory[ds*16 + 0x0025] = 0x00;
    case 0x1f0b:
        memory[ds*16 + 0x0020] = 0x00;
        si = 0x3c5e;
        memory16set(ds, si + 12, 0x0001);
        memory16set(ds, si + 18, 0x0001);
        memory16set(ds, 0x3a54, 0x0240);
        memory16set(ds, 0x4f8a, 0x0001);
        memory16set(ds, 0x4f8c, 0x0002);
        memory16set(ds, 0x4f88, 0x0001);
        memory[ds*16 + 0x0026] = 0x00;
        yield* sub_4317();
        memory[ds*16 + 0x0027] = 0x00;
        if (memory16get(ds, 0x4f8a) == 0x0000) {
            pc = 0x1f0b;
            break;
        }
        if (memory16get(ds, 0x4f88) == 0xffff) {
            pc = 0x1f66;
            break;
        }
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x1f61;
            break;
        }
        yield* sub_71ea();
        pc = 0x1f0b;
        break;
    case 0x1f61:
        yield* sub_1f73();
        pc = 0x1f0b;
        break;
    case 0x1f66:
        yield* sub_8d0f();
        yield* sub_34ae();
        yield* sub_28b0();
        r8[ah] = 0x4c;
        interrupt(0x21);
        return;
    } while (1);
}
function* sub_1f73() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x4f88, 0x0000);
        r16[ax] = 0x0000;
        yield* sub_77c8();
        di = 0x08de;
        push(ds);
        yield* sub_23d3();
        ds = pop();
        r16[ax] = 0x0001;
        yield* sub_77c8();
        r16[ax] = 0x0002;
        yield* sub_77c8();
        memory16set(ds, 0x4f6e, 0x7fff);
        memory16set(ds, 0x4f92, 0x0000);
        memory[ds*16 + 0x0025] = 0x00;
        yield* sub_2fcb();
        yield* sub_2fdd();
        r16[ax] = 0x3e54;
        memory16set(ds, 0x3a52, r16[ax]);
        yield* sub_4f14();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        r16[ax] = 0x000d;
        yield* sub_8c10();
        if (memory[ds*16 + 0x0026] == 0x00) {
            pc = 0x1fdc;
            break;
        }
        memory16set(ds, 0x0010, 0x0004);
        memory16set(ds, 0x0012, 0x0000);
        memory16set(ds, 0x0014, 0x0001);
        pc = 0x2000;
        break;
    case 0x1fdc:
        yield* sub_377e();
        if (memory[ds*16 + 0x0025] != 0x00) {
            pc = 0x1ffd;
            break;
        }
        yield* sub_3650();
        if (memory[ds*16 + 0x0025] != 0x00) {
            pc = 0x1ffd;
            break;
        }
        yield* sub_3522();
        if (memory[ds*16 + 0x0025] != 0x00) {
            pc = 0x1ffd;
            break;
        }
        pc = 0x2000;
        break;
    case 0x1ffd:
        pc = 0x2223;
        break;
    case 0x2000:
        memory16set(ds, 0x0016, 0x0000);
        si = 0x3c5e;
        memory16set(ds, si + 30, 0x0000);
        si = 0x3c7e;
        memory16set(ds, si + 30, 0x0000);
        si = 0x3c9e;
        memory16set(ds, si + 30, 0x0000);
        si = 0x3cbe;
        memory16set(ds, si + 30, 0x0000);
        memory16set(ds, 0x3a54, 0x0300);
    case 0x2030:
        yield* sub_3a0c();
        if (memory[ds*16 + 0x0025] != 0x00) {
            pc = 0x1ffd;
            break;
        }
        memory[ds*16 + 0x0023] = 0xff;
        si = 0x002a;
        r16[ax] = memory16get(ds, 0x0010);
        r16[ax] -= 0x0002;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        memory16set(ds, 0x37ce, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, 0x37d0, r16[ax]);
        yield* sub_5494();
        yield* sub_56de();
        yield* sub_2318();
        yield* sub_5494();
        yield* sub_56de();
        si = 0x3c5e;
        memory16set(ds, si, 0xffff);
        memory16set(ds, si + 32, 0xffff);
        memory16set(ds, si + 64, 0xffff);
        memory16set(ds, si + 96, 0xffff);
        si = 0x3c5e;
        r16[bx] = 0x0036;
        r16[cx] = memory16get(ds, 0x0010);
    case 0x208b:
        push(r16[cx]);
        r16[ax] = memory16get(ds, r16[bx]);
        yield* sub_57d2();
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 12, 0x0001);
        memory16set(ds, si + 14, 0x0000);
        memory16set(ds, si + 18, 0x0002);
        memory16set(ds, si + 20, 0x0000);
        memory16set(ds, si + 22, 0x0002);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 24, r16[ax]);
        memory16set(ds, si + 26, 0x0000);
        memory16set(ds, si + 28, 0x0000);
        memory16set(ds, si + 10, 0x0000);
        memory16set(ds, si + 8, 0x0000);
        r16[bx] += 0x0004;
        si += 0x0020;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x208b;
            break;
        }
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x0046;
        di = 0x0726;
        r16[cx] = 0x00c3;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        yield* sub_50e9();
        if (memory[ds*16 + 0x0026] == 0x00) {
            pc = 0x2113;
            break;
        }
        yield* sub_697c();
        memory16set(ds, 0x000c, 0x5748);
        yield* sub_58a7();
        if (r16[dx] != 0xffff) {
            pc = 0x2113;
            break;
        }
        pc = 0x2223;
        break;
    case 0x2113:
        yield* sub_4f8b();
        r16[ax] = 0x0011;
        di = 0x0000;
        yield* sub_2c81();
        if (memory[ds*16 + 0x0026] != 0x00) {
            pc = 0x2129;
            break;
        }
        yield* sub_699a();
    case 0x2129:
        yield* sub_5a41();
        yield* sub_6a43();
        yield* sub_5494();
        yield* sub_56de();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        r16[ax] = 0x0000;
        yield* sub_8c10();
        memory16set(ds, 0x000a, 0x0000);
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
        memory16set(ds, 0x3c72, 0x0001);
        memory16set(ds, 0x3c92, 0x0001);
        memory16set(ds, 0x3cb2, 0x0001);
        memory16set(ds, 0x3cd2, 0x0001);
        memory[ds*16 + 0x0023] = 0x00;
        memory16set(ds, 0x204c, 0x0000);
        memory[ds*16 + 0x0020] = 0x00;
    case 0x2186:
        yield* sub_34f3();
        yield* sub_68ba();
        yield* sub_281e();
        if (memory[ds*16 + 0x0026] != 0x00) {
            pc = 0x219b;
            break;
        }
        yield* sub_552a();
        pc = 0x21cb;
        break;
    case 0x219b:
        r16[ax] = 0x25f0;
        es = r16[ax];
        si = memory16get(ds, 0x000c);
        r16[ax] = 0x0000;
        r8[al] = memory[es*16 + si];
        if (r8[al] == 0xff) {
            pc = 0x21cb;
            break;
        }
        memory16set(ds, 0x3c78, r16[ax]);
        r8[al] = memory[es*16 + si + 1];
        memory16set(ds, 0x3c98, r16[ax]);
        r8[al] = memory[es*16 + si + 2];
        memory16set(ds, 0x3cb8, r16[ax]);
        r8[al] = memory[es*16 + si + 3];
        memory16set(ds, 0x3cd8, r16[ax]);
        memory16set(ds, 0x000c, memory16get(ds, 0x000c) + 0x0004);
    case 0x21cb:
        yield* sub_5efa();
        yield* sub_638f();
        yield* sub_59d8();
        yield* sub_6315();
        yield* sub_6a43();
        yield* sub_5a41();
        yield* sub_708b();
        yield* sub_56de();
        yield* sub_2282();
        if (r16[dx] == 0xffff) {
            pc = 0x2239;
            break;
        }
        if (memory[ds*16 + 0x0020] != 0x19) {
            pc = 0x21f5;
            break;
        }
        yield* sub_75bc();
    case 0x21f5:
        if (memory[ds*16 + 0x0023] == 0x00) {
            pc = 0x2204;
            break;
        }
        memory16set(ds, 0x000e, 0xffff);
        pc = 0x2239;
        break;
    case 0x2204:
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_3503();
//        yield* sync();
        if (memory[ds*16 + 0x0020] != 0x01) {
            pc = 0x221a;
            break;
        }
        pc = 0x2223;
        break;
    case 0x221a:
        yield* sub_8b8b();
        yield* sub_350c();
        pc = 0x2186;
        break;
    case 0x2223:
        yield* sub_8b80();
        si = 0x0bde;
        yield* sub_236a();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        return;
    case 0x2239:
        yield* sub_8b80();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        if (memory[ds*16 + 0x0026] != 0x00) {
            pc = 0x2223;
            break;
        }
        yield* sub_3ae1();
        if (memory[ds*16 + 0x0025] != 0x00) {
            pc = 0x2223;
            break;
        }
        if (memory16get(ds, 0x0016) != 0x0000) {
            pc = 0x227c;
            break;
        }
        pc = 0x2030;
        break;
    case 0x227c:
        yield* sub_389e();
        pc = 0x2000;
        break;
        return;
    } while (1);
}
function* sub_2282() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x3c5e;
        r16[cx] = memory16get(ds, 0x0010);
        memory16set(ds, 0x000e, 0xffff);
    case 0x228f:
        push(r16[cx]);
        if (memory16gets(ds, si + 8) < 0) {
            pc = 0x2313;
            break;
        }
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x22ac;
            break;
        }
        if (memory16get(ds, 0x000e) != 0xffff) {
            pc = 0x2313;
            break;
        }
        r16[ax] = memory16get(ds, si + 24);
        memory16set(ds, 0x000e, r16[ax]);
    case 0x22ac:
        r16[cx] = pop();
        si += 0x0020;
        if (--r16[cx]) {
            pc = 0x228f;
            break;
        }
        memory16set(ds, 0x3c74, 0x0002);
        memory16set(ds, 0x3c94, 0x0002);
        memory16set(ds, 0x3cb4, 0x0002);
        memory16set(ds, 0x3cd4, 0x0002);
        r16[cx] = 0x0008;
        si = 0x3cde;
    case 0x22d0:
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x2307;
            break;
        }
        si += 0x0016;
        if (--r16[cx]) {
            pc = 0x22d0;
            break;
        }
        memory16set(ds, 0x000a, memory16get(ds, 0x000a) + 1);
        if (memory16get(ds, 0x000a) == 0x0002) {
            pc = 0x2308;
            break;
        }
        if (memory16get(ds, 0x000a) == 0x0009) {
            pc = 0x2308;
            break;
        }
        if (memory16get(ds, 0x000a) == 0x0010) {
            pc = 0x2308;
            break;
        }
        if (memory16get(ds, 0x000a) < 0x0012) {
            pc = 0x2307;
            break;
        }
        if (memory16get(ds, 0x000e) == 0xffff) {
            pc = 0x230f;
            break;
        }
        r16[dx] = 0xffff;
        return;
    case 0x2307:
        return;
    case 0x2308:
        r16[ax] = 0x0003;
        yield* sub_8ca1();
        return;
    case 0x230f:
        r16[dx] = 0xffff;
        return;
    case 0x2313:
        r16[cx] = pop();
        r16[dx] = 0x0000;
        return;
    } while (1);
}
function* sub_2318() {
    r16[ax] = memory16get(ds, 0x0018);
    r16[dx] = memory16get(ds, 0x001a);
    memory16set(ds, 0x0018, r16[dx]);
    memory16set(ds, 0x001a, r16[ax]);
    r16[ax] = memory16get(ds, 0x0ede);
    r16[dx] = memory16get(ds, 0x0ee0);
    memory16set(ds, 0x0ede, r16[dx]);
    memory16set(ds, 0x0ee0, r16[ax]);
    memory[ds*16 + 0x0022] = ~memory[ds*16 + 0x0022];
}
function* sub_233a() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x233a:
        yield* sub_34f3();
        push(si);
        r16[bx] = si;
        yield* sub_23b5();
        si = pop();
        r8[ah] = 0x00;
        r16[bx] = 0x0000;
        r16[cx] = 0x0300;
    case 0x234c:
        r8[al] = memory[ds*16 + r16[bx] + si];
        if (memory[ds*16 + r16[bx] + di] <= r8[al]) {
            pc = 0x235c;
            break;
        }
        r8[ah] = 0xff;
        memory[ds*16 + r16[bx] + si] += 1;
    case 0x235c:
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x234c;
            break;
        }
        push(r16[ax]);
        yield* sub_3503();
        r16[ax] = pop();
        if (r8[ah] != 0x00) {
            pc = 0x233a;
            break;
        }
        return;
    } while (1);
}
function* sub_236a() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x236a:
        yield* sub_34f3();
        push(si);
        r16[bx] = si;
        yield* sub_23b5();
        si = pop();
        r8[ah] = 0x00;
        r16[bx] = 0x0000;
        r16[cx] = 0x0300;
    case 0x237c:
        if (memory[ds*16 + r16[bx] + si] == 0x00) {
            pc = 0x2389;
            break;
        }
        r8[ah] = 0xff;
        memory[ds*16 + r16[bx] + si] -= 1;
    case 0x2389:
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x237c;
            break;
        }
        push(r16[ax]);
        yield* sub_3503();
        r16[ax] = pop();
        if (r8[ah] != 0x00) {
            pc = 0x236a;
            break;
        }
        return;
    } while (1);
}
function* sub_2397() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03c8;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
    case 0x239d:
        lodsb_data_forward();
        r16[dx] = 0x03c9;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        lodsb_data_forward();
        r16[dx] = 0x03c9;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        lodsb_data_forward();
        r16[dx] = 0x03c9;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        if (--r16[cx]) {
            pc = 0x239d;
            break;
        }
        return;
    } while (1);
}
function* sub_23b5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[dx] = 0x03c8;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[ax] = 0x0b52;
        ds = r16[ax];
        si = r16[bx];
        r16[cx] = 0x0100;
        r16[dx] = 0x03c9;
    case 0x23c9:
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        lodsb_data_forward();
        out8(r16[dx], r8[al]);
        if (--r16[cx]) {
            pc = 0x23c9;
            break;
        }
        ds = pop();
        return;
    } while (1);
}
function* sub_23d3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x25f0;
        ds = r16[ax];
        si = 0x0030;
        r16[ax] = 0x0b52;
        es = r16[ax];
        r16[cx] = 0x0300;
    case 0x23e3:
        lodsb_data_forward();
        r8[al] >>= 1;
        r8[al] >>= 1;
        stosb_data_forward();
        if (--r16[cx]) {
            pc = 0x23e3;
            break;
        }
        return;
    } while (1);
}
function* sub_23ec() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x25f0;
        ds = r16[ax];
        si = 0x0000;
    case 0x23f4:
//console.log(memory[ds*16 + si]); throw "problem"
        si++;
        if (memory[ds*16 + si] != 0x42) {
            pc = 0x23f4;
            break;
        }
        if (memory[ds*16 + si + 1] != 0x4f) {
            pc = 0x23f4;
            break;
        }
        if (memory[ds*16 + si + 2] != 0x44) {
            pc = 0x23f4;
            break;
        }
        if (memory[ds*16 + si + 3] != 0x59) {
            pc = 0x23f4;
            break;
        }
        si += 0x0008;
    case 0x2414:
        push(r16[cx]);
        push(di);
        push(es);
        r16[ax] = 0x0b52;
        es = r16[ax];
        di = 0x16c2;
        r16[dx] = 0x0000;
    case 0x2422:
        r16[ax] = 0x0000;
        lodsb_data_forward();
        if (r8s[al] < 0) {
            pc = 0x2434;
            break;
        }
        r16[cx] = r16[ax];
        r16[cx]++;
        r16[dx] += r16[cx];
        rep_movsb_data_data_forward();
        pc = 0x243e;
        break;
    case 0x2434:
        r8[al] = -r8[al];
        r16[cx] = r16[ax];
        r16[cx]++;
        r16[dx] += r16[cx];
        flags.carry = 0;
        lodsb_data_forward();
        rep_stosb_data_forward();
    case 0x243e:
        if (r16[dx] < 0x0140) {
            pc = 0x2422;
            break;
        }
        es = pop();
        di = pop();
        push(ds);
        push(si);
        r16[ax] = 0x0b52;
        ds = r16[ax];
        si = 0x16c2;
        r16[cx] = 0x0028;
    case 0x2453:
        push(r16[cx]);
        r16[cx] = 0x0008;
    case 0x2457:
        r8[al] = 0x00;
        memory[ds*16 + si + 280] = rcl8(memory[ds*16 + si + 280], 1);
        r8[al] = rcl8(r8[al], 0x01);
        memory[ds*16 + si + 240] = rcl8(memory[ds*16 + si + 240], 1);
        r8[al] = rcl8(r8[al], 0x01);
        memory[ds*16 + si + 200] = rcl8(memory[ds*16 + si + 200], 1);
        r8[al] = rcl8(r8[al], 0x01);
        memory[ds*16 + si + 160] = rcl8(memory[ds*16 + si + 160], 1);
        r8[al] = rcl8(r8[al], 0x01);
        memory[ds*16 + si + 120] = rcl8(memory[ds*16 + si + 120], 1);
        r8[al] = rcl8(r8[al], 0x01);
        memory[ds*16 + si + 80] = rcl8(memory[ds*16 + si + 80], 1);
        r8[al] = rcl8(r8[al], 0x01);
        memory[ds*16 + si + 40] = rcl8(memory[ds*16 + si + 40], 1);
        r8[al] = rcl8(r8[al], 0x01);
        memory[ds*16 + si] = rcl8(memory[ds*16 + si], 1);
        r8[al] = rcl8(r8[al], 0x01);
        stosb_data_forward();
        if (--r16[cx]) {
            pc = 0x2457;
            break;
        }
        r16[cx] = pop();
        si++;
        if (--r16[cx]) {
            pc = 0x2453;
            break;
        }
        si = pop();
        ds = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x2496;
            break;
        }
        return;
    case 0x2496:
        pc = 0x2414;
        break;
        return;
    } while (1);
}
function* sub_2499() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
    case 0x24a9:
        push(r16[cx]);
        push(si);
        r8[al] = 0x01;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] += r8[al];
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] += r8[al];
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] += r8[al];
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        si = pop();
        di += 0x0080;
        si += 0x0140;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x24a9;
            break;
        }
        return;
    } while (1);
}
function* sub_24dc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
    case 0x24ec:
        push(r16[cx]);
        push(si);
        r8[al] = 0x01;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] += r8[al];
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] += r8[al];
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] += r8[al];
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        si = pop();
        di += 0x0040;
        si += 0x0140;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x24ec;
            break;
        }
        return;
    } while (1);
}
function* sub_251e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r16[cx] = r16[ax];
        r16[ax] = 0x0011;
        r16[ax] = rol16(r16[ax], r8[cl]);
        r16[cx] = pop();
        push(r16[ax]);
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
        r16[ax] = pop();
        r8[ah] = r8[al];
    case 0x253b:
        push(r16[cx]);
        push(si);
        push(di);
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r8[ah] = rol8(r8[ah], 0x01);
        r16[cx] = r16[bx];
    case 0x2545:
        lodsb_data_forward();
        if (r8[al] == 0x03) {
            pc = 0x254d;
            break;
        }
        videoSet(es, di, r8[al]);
    case 0x254d:
        di++;
        if (--r16[cx]) {
            pc = 0x2545;
            break;
        }
        di -= r16[bx];
        if (r8[ah] != 0x11) {
            pc = 0x2558;
            break;
        }
        di++;
    case 0x2558:
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r8[ah] = rol8(r8[ah], 0x01);
        r16[cx] = r16[bx];
    case 0x255f:
        lodsb_data_forward();
        if (r8[al] == 0x03) {
            pc = 0x2567;
            break;
        }
        videoSet(es, di, r8[al]);
    case 0x2567:
        di++;
        if (--r16[cx]) {
            pc = 0x255f;
            break;
        }
        di -= r16[bx];
        if (r8[ah] != 0x11) {
            pc = 0x2572;
            break;
        }
        di++;
    case 0x2572:
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r8[ah] = rol8(r8[ah], 0x01);
        r16[cx] = r16[bx];
    case 0x2579:
        lodsb_data_forward();
        if (r8[al] == 0x03) {
            pc = 0x2581;
            break;
        }
        videoSet(es, di, r8[al]);
    case 0x2581:
        di++;
        if (--r16[cx]) {
            pc = 0x2579;
            break;
        }
        di -= r16[bx];
        if (r8[ah] != 0x11) {
            pc = 0x258c;
            break;
        }
        di++;
    case 0x258c:
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r8[ah] = rol8(r8[ah], 0x01);
        r16[cx] = r16[bx];
    case 0x2593:
        lodsb_data_forward();
        if (r8[al] == 0x03) {
            pc = 0x259b;
            break;
        }
        videoSet(es, di, r8[al]);
    case 0x259b:
        di++;
        if (--r16[cx]) {
            pc = 0x2593;
            break;
        }
        di -= r16[bx];
        di = pop();
        si = pop();
        di += 0x0080;
        si += 0x0140;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x253b;
            break;
        }
        return;
    } while (1);
}
function* sub_25ae() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r16[cx] = r16[ax];
        r16[ax] = 0x0011;
        r16[ax] = rol16(r16[ax], r8[cl]);
        r16[cx] = pop();
        push(r16[ax]);
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
        r16[ax] = pop();
        r8[ah] = r8[al];
    case 0x25cb:
        push(r16[cx]);
        push(si);
        push(di);
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r8[ah] = rol8(r8[ah], 0x01);
        r16[cx] = r16[bx];
    case 0x25d5:
        lodsb_data_forward();
        if (r8[al] == 0x03) {
            pc = 0x25dd;
            break;
        }
        videoSet(es, di, r8[al]);
    case 0x25dd:
        di++;
        if (--r16[cx]) {
            pc = 0x25d5;
            break;
        }
        di -= r16[bx];
        if (r8[ah] != 0x11) {
            pc = 0x25e8;
            break;
        }
        di++;
    case 0x25e8:
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r8[ah] = rol8(r8[ah], 0x01);
        r16[cx] = r16[bx];
    case 0x25ef:
        lodsb_data_forward();
        if (r8[al] == 0x03) {
            pc = 0x25f7;
            break;
        }
        videoSet(es, di, r8[al]);
    case 0x25f7:
        di++;
        if (--r16[cx]) {
            pc = 0x25ef;
            break;
        }
        di -= r16[bx];
        if (r8[ah] != 0x11) {
            pc = 0x2602;
            break;
        }
        di++;
    case 0x2602:
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r8[ah] = rol8(r8[ah], 0x01);
        r16[cx] = r16[bx];
    case 0x2609:
        lodsb_data_forward();
        if (r8[al] == 0x03) {
            pc = 0x2611;
            break;
        }
        videoSet(es, di, r8[al]);
    case 0x2611:
        di++;
        if (--r16[cx]) {
            pc = 0x2609;
            break;
        }
        di -= r16[bx];
        if (r8[ah] != 0x11) {
            pc = 0x261c;
            break;
        }
        di++;
    case 0x261c:
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r8[ah] = rol8(r8[ah], 0x01);
        r16[cx] = r16[bx];
    case 0x2623:
        lodsb_data_forward();
        if (r8[al] == 0x03) {
            pc = 0x262b;
            break;
        }
        videoSet(es, di, r8[al]);
    case 0x262b:
        di++;
        if (--r16[cx]) {
            pc = 0x2623;
            break;
        }
        di -= r16[bx];
        di = pop();
        si = pop();
        di += 0x0040;
        si += 0x0140;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x25cb;
            break;
        }
        return;
    } while (1);
}
function* sub_263d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
    case 0x264d:
        push(r16[cx]);
        r8[al] = 0x01;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        di += 0x0080;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x264d;
            break;
        }
        return;
    } while (1);
}
function* sub_267a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
    case 0x268a:
        push(r16[cx]);
        r8[al] = 0x01;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_video_data_forward();
        di -= r16[bx];
        di += 0x0040;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x268a;
            break;
        }
        return;
    } while (1);
}
function* sub_26b6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x26fc;
            break;
        }
        push(ds);
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        ds = r16[ax];
        r16[dx] = 0x03ce;
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
    case 0x26ce:
        push(r16[cx]);
        push(si);
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_data_video_forward();
        si -= r16[bx];
        r8[al] = 0x01;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_data_video_forward();
        si -= r16[bx];
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_data_video_forward();
        si -= r16[bx];
        r8[al] = 0x03;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_data_video_forward();
        si = pop();
        si += 0x0080;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x26ce;
            break;
        }
        ds = pop();
        return;
    case 0x26fc:
        push(ds);
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        ds = r16[ax];
        r16[dx] = 0x03ce;
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
    case 0x270d:
        push(r16[cx]);
        push(si);
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_data_video_forward();
        si -= r16[bx];
        r8[al] = 0x01;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_data_video_forward();
        si -= r16[bx];
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_data_video_forward();
        si -= r16[bx];
        r8[al] = 0x03;
        out8(r16[dx], r8[al]);
        r16[cx] = r16[bx];
        rep_movsb_data_video_forward();
        si = pop();
        si += 0x0040;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x270d;
            break;
        }
        ds = pop();
        return;
    } while (1);
}
function* sub_273a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r8[cl] = 0x03;
        r16[ax] <<= r8[cl];
        si = 0x0ee2;
        si += r16[ax];
        if (si >= 0x1532) {
            pc = 0x2760;
            break;
        }
        r16[dx] = memory16get(ds, si + 4);
        r16[cx] = memory16get(ds, si + 6);
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x2762;
            break;
        }
        r16[tx] = si;
        si = memory16get(ds, r16[tx]);
        ds = memory16get(ds, r16[tx] + 2);
        yield* sub_2499();
    case 0x2760:
        ds = pop();
        return;
    case 0x2762:
        r16[tx] = si;
        si = memory16get(ds, r16[tx]);
        ds = memory16get(ds, r16[tx] + 2);
        yield* sub_24dc();
        ds = pop();
        return;
    } while (1);
}
function* sub_276b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        si = 0x180c;
        si += r16[ax];
        if (si >= 0x203c) {
            pc = 0x2780;
            break;
        }
        r16[cx] = pop();
        yield* sub_2782();
        return;
    case 0x2780:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_2782() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = r16[dx];
        yield* sub_584c();
        di += memory16get(ds, 0x0018);
        push(r16[ax]);
        push(si);
        push(di);
        r16[ax] = di;
        r16[dx] = memory16get(ds, si + 4);
        r16[dx]++;
        r16[cx] = memory16get(ds, si + 6);
        r16[bx] = si + 0x8;
        if (memory[ds*16 + 0x0022] != 0x00) {
            pc = 0x27a7;
            break;
        }
        r16[bx] += 0x0004;
    case 0x27a7:
        di = memory16get(ds, r16[bx]);
        es = memory16get(ds, r16[bx] + 2);
        si = r16[ax];
        yield* sub_27d4();
        di = pop();
        si = pop();
        r16[ax] = pop();
        r16[dx] = memory16get(ds, si + 4);
        r16[cx] = memory16get(ds, si + 6);
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x27cb;
            break;
        }
        r16[tx] = si;
        si = memory16get(ds, r16[tx]);
        ds = memory16get(ds, r16[tx] + 2);
        yield* sub_251e();
        ds = pop();
        return;
    case 0x27cb:
        r16[tx] = si;
        si = memory16get(ds, r16[tx]);
        ds = memory16get(ds, r16[tx] + 2);
        yield* sub_25ae();
        ds = pop();
        return;
    } while (1);
}
function* sub_27d4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x0ede);
        r16[ax] = 0x0014;
    case 0x27db:
        if (memory16get(ds, r16[bx]) == 0xffff) {
            pc = 0x27e9;
            break;
        }
        r16[bx] += 0x000a;
        r16[ax]--;
        if (r16[ax] != 0) {
            pc = 0x27db;
            break;
        }
        return;
    case 0x27e9:
        memory16set(ds, r16[bx], si);
        memory16set(ds, r16[bx] + 2, di);
        memory16set(ds, r16[bx] + 4, es);
        memory16set(ds, r16[bx] + 6, r16[dx]);
        memory16set(ds, r16[bx] + 8, r16[cx]);
        yield* sub_26b6();
        return;
    } while (1);
}
function* sub_2801() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x1532;
        di = 0x15fa;
        r16[ax] = 0xffff;
        r16[cx] = 0x0014;
    case 0x280d:
        memory16set(ds, si, r16[ax]);
        memory16set(ds, di, r16[ax]);
        si += 0x000a;
        di += 0x000a;
        if (--r16[cx]) {
            pc = 0x280d;
            break;
        }
        return;
    } while (1);
}
function* sub_281e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = memory16get(ds, 0x0ede);
        si += 0x00be;
        r16[ax] = 0x0014;
    case 0x2829:
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x2837;
            break;
        }
    case 0x2830:
        si -= 0x000a;
        r16[ax]--;
        if (r16[ax] != 0) {
            pc = 0x2829;
            break;
        }
        return;
    case 0x2837:
        push(r16[ax]);
        push(si);
        push(ds);
        di = memory16get(ds, si);
        memory16set(ds, si, 0xffff);
        r16[dx] = memory16get(ds, si + 6);
        r16[cx] = memory16get(ds, si + 8);
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x285f;
            break;
        }
        r16[tx] = si;
        si = memory16get(ds, r16[tx] + 2);
        ds = memory16get(ds, r16[tx] + 2 + 2);
        yield* sub_263d();
        ds = pop();
        si = pop();
        r16[ax] = pop();
        pc = 0x2830;
        break;
    case 0x285f:
        r16[tx] = si;
        si = memory16get(ds, r16[tx] + 2);
        ds = memory16get(ds, r16[tx] + 2 + 2);
        yield* sub_267a();
        ds = pop();
        si = pop();
        r16[ax] = pop();
        pc = 0x2830;
        break;
        return;
    } while (1);
}
function* sub_286b() {
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r16[dx] = 0x03c5;
    r8[al] = 0x0f;
    out8(r16[dx], r8[al]);
    r16[ax] = 0xa000;
    es = r16[ax];
    di = 0x0000;
    r16[cx] = 0xfa00;
    r16[ax] = 0x0000;
    rep_stosb_video_forward();
}
function* sub_2888() {
    push(r16[ax]);
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r16[dx] = 0x03c5;
    r8[al] = 0x0f;
    out8(r16[dx], r8[al]);
    r16[dx] = 0xa000;
    es = r16[dx];
    di = 0x0000;
    r16[cx] = 0xfa00;
    r16[ax] = pop();
    rep_stosb_video_forward();
}
function* sub_28b0() {
    r16[ax] = 0x0003;
    interrupt(0x10);
}
function* sub_28b6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        si = 0x180c;
        si += r16[ax];
        if (si >= 0x203c) {
            pc = 0x28cb;
            break;
        }
        r16[cx] = pop();
        yield* sub_28cd();
        return;
    case 0x28cb:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_28cd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(r16[bx]);
        r16[ax] = r16[dx];
        yield* sub_584c();
        di += memory16get(ds, 0x0018);
        push(r16[ax]);
        push(si);
        push(di);
        r16[ax] = di;
        r16[dx] = memory16get(ds, si + 4);
        r16[dx]++;
        r16[cx] = memory16get(ds, si + 6);
        r16[bx] = si + 0x8;
        if (memory[ds*16 + 0x0022] != 0x00) {
            pc = 0x28f3;
            break;
        }
        r16[bx] += 0x0004;
    case 0x28f3:
        di = memory16get(ds, r16[bx]);
        es = memory16get(ds, r16[bx] + 2);
        si = r16[ax];
        yield* sub_27d4();
        di = pop();
        si = pop();
        r16[ax] = pop();
        r16[dx] = memory16get(ds, si + 4);
        r16[cx] = memory16get(ds, si + 6);
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x2918;
            break;
        }
        r16[tx] = si;
        si = memory16get(ds, r16[tx]);
        ds = memory16get(ds, r16[tx] + 2);
        r16[bx] = pop();
        yield* sub_29dc();
        ds = pop();
        return;
    case 0x2918:
        r16[tx] = si;
        si = memory16get(ds, r16[tx]);
        ds = memory16get(ds, r16[tx] + 2);
        r16[bx] = pop();
        yield* sub_2952();
        ds = pop();
        return;
    } while (1);
}
function* sub_2922() {
    r16[dx] = 0x03c4;
    r8[al] = 0x02;
    out8(r16[dx], r8[al]);
    r16[dx] = 0x03c5;
    r8[al] = 0x0f;
    out8(r16[dx], r8[al]);
    r16[dx] = 0x03ce;
    r8[al] = 0x05;
    out8(r16[dx], r8[al]);
    r16[dx] = 0x03cf;
    r8[al] = 0x41;
    out8(r16[dx], r8[al]);
    push(ds);
    r16[ax] = 0xa000;
    es = r16[ax];
    ds = r16[ax];
    rep_movsb_data_data_forward();
    ds = pop();
    r16[dx] = 0x03ce;
    r8[al] = 0x05;
    out8(r16[dx], r8[al]);
    r16[dx] = 0x03cf;
    r8[al] = 0x40;
    out8(r16[dx], r8[al]);
}
function* sub_2952() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        r16[cx] = r16[ax];
        r16[ax] = 0x0011;
        r16[ax] = rol16(r16[ax], r8[cl]);
        r16[cx] = pop();
        push(r16[ax]);
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[ax] = pop();
        r16[dx] = pop();
        r8[ah] = r8[dl];
        r16[dx] = 0x03c5;
    case 0x2971:
        push(r16[cx]);
        push(si);
        push(di);
        out8(r16[dx], r8[al]);
        r8[al] = rol8(r8[al], 0x01);
        r16[cx] = r16[bx];
    case 0x2979:
        if (memory[ds*16 + si] == 0x03) {
            pc = 0x2981;
            break;
        }
        videoSet(es, di, r8[ah]);
    case 0x2981:
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x2979;
            break;
        }
        di -= r16[bx];
        if (r8[al] != 0x11) {
            pc = 0x298c;
            break;
        }
        di++;
    case 0x298c:
        out8(r16[dx], r8[al]);
        r8[al] = rol8(r8[al], 0x01);
        r16[cx] = r16[bx];
    case 0x2991:
        if (memory[ds*16 + si] == 0x03) {
            pc = 0x2999;
            break;
        }
        videoSet(es, di, r8[ah]);
    case 0x2999:
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x2991;
            break;
        }
        di -= r16[bx];
        if (r8[al] != 0x11) {
            pc = 0x29a4;
            break;
        }
        di++;
    case 0x29a4:
        out8(r16[dx], r8[al]);
        r8[al] = rol8(r8[al], 0x01);
        r16[cx] = r16[bx];
    case 0x29a9:
        if (memory[ds*16 + si] == 0x03) {
            pc = 0x29b1;
            break;
        }
        videoSet(es, di, r8[ah]);
    case 0x29b1:
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x29a9;
            break;
        }
        di -= r16[bx];
        if (r8[al] != 0x11) {
            pc = 0x29bc;
            break;
        }
        di++;
    case 0x29bc:
        out8(r16[dx], r8[al]);
        r8[al] = rol8(r8[al], 0x01);
        r16[cx] = r16[bx];
    case 0x29c1:
        if (memory[ds*16 + si] == 0x03) {
            pc = 0x29c9;
            break;
        }
        videoSet(es, di, r8[ah]);
    case 0x29c9:
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x29c1;
            break;
        }
        di -= r16[bx];
        di = pop();
        si = pop();
        di += 0x0040;
        si += 0x0140;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x2971;
            break;
        }
        return;
    } while (1);
}
function* sub_29dc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        r16[cx] = r16[ax];
        r16[ax] = 0x0011;
        r16[ax] = rol16(r16[ax], r8[cl]);
        r16[cx] = pop();
        push(r16[ax]);
        r16[bx] = r16[dx];
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[ax] = pop();
        r16[dx] = pop();
        r8[ah] = r8[dl];
        r16[dx] = 0x03c5;
    case 0x29fb:
        push(r16[cx]);
        push(si);
        push(di);
        out8(r16[dx], r8[al]);
        r8[al] = rol8(r8[al], 0x01);
        r16[cx] = r16[bx];
    case 0x2a03:
        if (memory[ds*16 + si] == 0x03) {
            pc = 0x2a0b;
            break;
        }
        videoSet(es, di, r8[ah]);
    case 0x2a0b:
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x2a03;
            break;
        }
        di -= r16[bx];
        if (r8[al] != 0x11) {
            pc = 0x2a16;
            break;
        }
        di++;
    case 0x2a16:
        out8(r16[dx], r8[al]);
        r8[al] = rol8(r8[al], 0x01);
        r16[cx] = r16[bx];
    case 0x2a1b:
        if (memory[ds*16 + si] == 0x03) {
            pc = 0x2a23;
            break;
        }
        videoSet(es, di, r8[ah]);
    case 0x2a23:
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x2a1b;
            break;
        }
        di -= r16[bx];
        if (r8[al] != 0x11) {
            pc = 0x2a2e;
            break;
        }
        di++;
    case 0x2a2e:
        out8(r16[dx], r8[al]);
        r8[al] = rol8(r8[al], 0x01);
        r16[cx] = r16[bx];
    case 0x2a33:
        if (memory[ds*16 + si] == 0x03) {
            pc = 0x2a3b;
            break;
        }
        videoSet(es, di, r8[ah]);
    case 0x2a3b:
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x2a33;
            break;
        }
        di -= r16[bx];
        if (r8[al] != 0x11) {
            pc = 0x2a46;
            break;
        }
        di++;
    case 0x2a46:
        out8(r16[dx], r8[al]);
        r8[al] = rol8(r8[al], 0x01);
        r16[cx] = r16[bx];
    case 0x2a4b:
        if (memory[ds*16 + si] == 0x03) {
            pc = 0x2a53;
            break;
        }
        videoSet(es, di, r8[ah]);
    case 0x2a53:
        si++;
        di++;
        if (--r16[cx]) {
            pc = 0x2a4b;
            break;
        }
        di -= r16[bx];
        di = pop();
        si = pop();
        di += 0x0080;
        si += 0x0140;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x29fb;
            break;
        }
        return;
    } while (1);
}
function* sub_2a67() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) == 0x0000) {
            pc = 0x2aa5;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x2a76;
            break;
        }
        return;
    case 0x2a76:
        push(ds);
        di = memory16get(ds, 0x0018);
        si = 0xb908;
        r16[ax] = 0x42fd;
        ds = r16[ax];
        r16[dx] = 0x0040;
        r16[cx] = 0x0018;
        yield* sub_24dc();
        ds = pop();
        push(ds);
        di = memory16get(ds, 0x001a);
        si = 0xb908;
        r16[ax] = 0x42fd;
        ds = r16[ax];
        r16[dx] = 0x0040;
        r16[cx] = 0x0018;
        yield* sub_24dc();
        ds = pop();
        return;
    case 0x2aa5:
        push(ds);
        di = memory16get(ds, 0x0018);
        si = 0xb908;
        r16[ax] = 0x42fd;
        ds = r16[ax];
        r16[dx] = 0x0040;
        r16[cx] = 0x0018;
        yield* sub_2499();
        ds = pop();
        push(ds);
        di = memory16get(ds, 0x001a);
        si = 0xb908;
        r16[ax] = 0x42fd;
        ds = r16[ax];
        r16[dx] = 0x0040;
        r16[cx] = 0x0018;
        yield* sub_2499();
        ds = pop();
        return;
    } while (1);
}
function* sub_2ad4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x203e);
        if (r16[ax] == memory16get(ds, 0x1802)) {
            pc = 0x2aef;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0001) {
            pc = 0x2af2;
            break;
        }
        if (memory16get(ds, 0x26f2) != 0x0002) {
            pc = 0x2aee;
            break;
        }
        pc = 0x2b7e;
        break;
    case 0x2aee:
        return;
    case 0x2aef:
        memory16set(ds, 0x1802, r16[ax]);
    case 0x2af2:
        push(ds);
        r16[cx] = memory16get(ds, 0x203e);
        r8[cl] &= 0x03;
        r8[al] = 0x11;
        r8[al] = rol8(r8[al], r8[cl]);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x203e);
        r16[ax] -= 0x0080;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        di = r16[ax];
        di += memory16get(ds, 0x0018);
        r16[ax] = 0xa000;
        es = r16[ax];
        ds = r16[ax];
        si = 0xfa00;
        r16[ax] = pop();
        r16[bx] = r16[ax];
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03ce;
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        yield* sub_2c4d();
        r8[bl] = rol8(r8[bl], 0x01);
        if (r8[bl] != 0x11) {
            pc = 0x2b3f;
            break;
        }
        di++;
    case 0x2b3f:
        r16[dx] = 0x03c5;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
        r8[al] = 0x01;
        out8(r16[dx], r8[al]);
        yield* sub_2c4d();
        r8[bl] = rol8(r8[bl], 0x01);
        if (r8[bl] != 0x11) {
            pc = 0x2b56;
            break;
        }
        di++;
    case 0x2b56:
        r16[dx] = 0x03c5;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        yield* sub_2c4d();
        r8[bl] = rol8(r8[bl], 0x01);
        if (r8[bl] != 0x11) {
            pc = 0x2b6d;
            break;
        }
        di++;
    case 0x2b6d:
        r16[dx] = 0x03c5;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
        r8[al] = 0x03;
        out8(r16[dx], r8[al]);
        yield* sub_2c4d();
        ds = pop();
        return;
    case 0x2b7e:
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
        r8[al] = 0x0f;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03ce;
        r8[al] = 0x05;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
        r8[al] = 0x41;
        out8(r16[dx], r8[al]);
        si = 0x1808;
        if (memory[ds*16 + 0x0022] == 0x00) {
            pc = 0x2ba3;
            break;
        }
        si = 0x1804;
    case 0x2ba3:
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[ax] = memory16get(ds, 0x203e);
        r16[ax] -= 0x0080;
        r8[cl] = 0x06;
        r16[ax] <<= r8[cl];
        di = r16[ax];
        di += memory16get(ds, 0x0018);
        push(ds);
        push(di);
        memory16set(ds, si, di);
        r16[ax] = memory16get(ds, si + 2);
        si = di;
        di = r16[ax];
        r16[ax] = 0xa000;
        ds = r16[ax];
        es = r16[ax];
        r16[cx] = 0x0600;
        rep_movsb_video_video_forward();
        di = pop();
        ds = pop();
        push(ds);
        flags.direction = true;
        si = memory16get(ds, 0x0018);
        si += 0x05ff;
        di += 0x05ff;
        r16[ax] = 0xa000;
        ds = r16[ax];
        r16[cx] = 0x0600;
        rep_movsb_data_data_forward();
        flags.direction = false;
        ds = pop();
        r16[dx] = 0x03ce;
        r8[al] = 0x05;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
        r8[al] = 0x40;
        out8(r16[dx], r8[al]);
        return;
    } while (1);
}
function* sub_2bfb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) != 0x0002)
            return;
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
        r8[al] = 0x0f;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03ce;
        r8[al] = 0x05;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
        r8[al] = 0x41;
        out8(r16[dx], r8[al]);
        si = 0x1808;
        if (memory[ds*16 + 0x0022] == 0x00) {
            pc = 0x2c27;
            break;
        }
        si = 0x1804;
    case 0x2c27:
        r16[ax] = 0xa000;
        es = r16[ax];
        push(ds);
        push(si);
        lodsw_data_forward();
        di = r16[ax];
        lodsw_data_forward();
        si = r16[ax];
        r16[ax] = 0xa000;
        ds = r16[ax];
        r16[cx] = 0x0600;
        rep_movsb_data_data_forward();
        si = pop();
        ds = pop();
        r16[dx] = 0x03ce;
        r8[al] = 0x05;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
        r8[al] = 0x40;
        out8(r16[dx], r8[al]);
        return;
    } while (1);
}
function* sub_2c4d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x0018;
    case 0x2c50:
        push(r16[cx]);
        r16[cx] = 0x0040;
        rep_movsb_data_data_forward();
        di += 0x0040;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x2c50;
            break;
        }
        si -= 0x0600;
        di -= 0x0c00;
        return;
    } while (1);
}
function* sub_2c65() {
    push(ds);
    r16[ax] = 0xa000;
    es = r16[ax];
    r16[ax] = 0x42fd;
    ds = r16[ax];
    si = 0xb908;
    di = 0xfa00;
    r16[cx] = 0x0018;
    r16[dx] = 0x0040;
    yield* sub_24dc();
    ds = pop();
}
function* sub_2c81() {
    push(r16[ax]);
    push(di);
    di += memory16get(ds, 0x0018);
    yield* sub_273a();
    di = pop();
    r16[ax] = pop();
    di += memory16get(ds, 0x001a);
    yield* sub_273a();
}
function* sub_2c94() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(di);
    push(si);
    push(es);
    push(ds);
    di += memory16get(ds, 0x0018);
    yield* sub_2cb3();
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    di += memory16get(ds, 0x001a);
    yield* sub_2cb3();
}
function* sub_2cb3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[dx]);
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
        r8[al] = 0x0f;
        out8(r16[dx], r8[al]);
        r16[ax] = 0xa000;
        es = r16[ax];
        r16[dx] = pop();
        r16[ax] = pop();
    case 0x2cc8:
        push(r16[cx]);
        push(di);
        r16[cx] = r16[dx];
        rep_stosb_video_forward();
        di = pop();
        r16[cx] = pop();
        di += 0x0040;
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x2cdd;
            break;
        }
        di += 0x0040;
    case 0x2cdd:
        if (--r16[cx]) {
            pc = 0x2cc8;
            break;
        }
        return;
    } while (1);
}
function* sub_2ce0() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x2ce0:
        push(r16[cx]);
        lodsw_data_forward();
        if (r16[ax] == 0xffff) {
            pc = 0x2cf3;
            break;
        }
        di = r16[ax];
        lodsw_data_forward();
        push(si);
        yield* sub_2c81();
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x2ce0;
            break;
        }
        return;
    case 0x2cf3:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_2cf6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x30e5;
        di = 0x2117;
        r16[bx] = 0x0000;
    case 0x2cff:
        lodsb_data_forward();
        yield* sub_2e42();
        if (r8s[al] < 0) {
            pc = 0x2d5b;
            break;
        }
        r8[al] &= 0x0f;
        memory[ds*16 + di] = r8[al];
        lodsb_data_forward();
        yield* sub_2e42();
        if (r8s[al] < 0) {
            pc = 0x2d5b;
            break;
        }
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        memory[ds*16 + di] = memory[ds*16 + di] | r8[al];
        di++;
        r16[bx]++;
        if (r16[bx] != 0x0004) {
            pc = 0x2cff;
            break;
        }
        si = 0x2117;
        r8[al] = memory[ds*16 + si];
        r8[al] &= 0xe0;
        r16[bx] = 0x0003;
    case 0x2d30:
        flags.carry = false;
        r8[al] = rcl8(r8[al], 0x01);
        if (!flags.carry) {
            pc = 0x2d39;
            break;
        }
        memory[ds*16 + r16[bx] + si] = ~memory[ds*16 + r16[bx] + si];
    case 0x2d39:
        r16[bx]--;
        if (r16[bx] != 0x0000) {
            pc = 0x2d30;
            break;
        }
        r8[al] = memory[ds*16 + si];
        r8[al] &= 0x18;
        if (r8[al] != 0x10) {
            pc = 0x2d5b;
            break;
        }
        memory16set(ds, 0x2162, 0x0000);
        r8[al] = memory[ds*16 + si];
        r8[al] &= 0x07;
        yield* sub_2e19();
        pc = 0x2d5e;
        break;
    case 0x2d5b:
        pc = 0x2de3;
        break;
    case 0x2d5e:
        si = 0x20a3;
        di = 0x20b9;
        r16[dx] = 0x0004;
        yield* sub_2de7();
        if (r16[ax] == 0x0000) {
            pc = 0x2d5b;
            break;
        }
        if (r16[ax] > 0x0008) {
            pc = 0x2d5b;
            break;
        }
        memory16set(ds, 0x4f88, r16[ax]);
        si = 0x20a7;
        di = 0x20bd;
        r16[dx] = 0x0004;
        yield* sub_2de7();
        if (r16[ax] == 0x0000) {
            pc = 0x2d5b;
            break;
        }
        if (r16[ax] > 0x0008) {
            pc = 0x2de3;
            break;
        }
        memory16set(ds, 0x4f8a, r16[ax]);
        si = 0x20ab;
        di = 0x20c1;
        r16[dx] = 0x0004;
        yield* sub_2de7();
        memory16set(ds, 0x3c6a, r16[ax]);
        si = 0x20af;
        di = 0x20c5;
        r16[dx] = 0x0004;
        yield* sub_2de7();
        memory16set(ds, 0x3c70, r16[ax]);
        si = 0x20b3;
        di = 0x20c9;
        r16[dx] = 0x0001;
        yield* sub_2de7();
        memory16set(ds, 0x3a54, 0x0300);
        if (r16[ax] != 0x0001) {
            pc = 0x2dcb;
            break;
        }
        memory16set(ds, 0x3a54, 0x03c0);
    case 0x2dcb:
        r16[ax] = memory16get(ds, 0x2162);
        si = 0x20b4;
        di = 0x20ca;
        r16[dx] = 0x0001;
        yield* sub_2de7();
        if (r16[ax] != 0x0000) {
            pc = 0x2de3;
            break;
        }
        r16[dx] = 0x0000;
        return;
    case 0x2de3:
        r16[dx] = 0xffff;
        return;
    } while (1);
}
function* sub_2de7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0000;
        r8[ah] = 0x00;
    case 0x2dec:
        push(r16[bx]);
        r8[bl] = memory[ds*16 + r16[bx] + di];
        r16[bx] &= 0x0003;
        r16[bx] += 0x2117;
        r8[al] = memory[ds*16 + r16[bx]];
        r16[bx] = pop();
        r8[ah] <<= 1;
        r8[al] &= memory[ds*16 + r16[bx] + si];
        if (r8[al] == 0x00) {
            pc = 0x2e0e;
            break;
        }
        memory16set(ds, 0x2162, memory16get(ds, 0x2162) + 1);
        r8[ah] |= 0x01;
    case 0x2e0e:
        r16[bx]++;
        if (r16[bx] != r16[dx]) {
            pc = 0x2dec;
            break;
        }
        r8[al] = r8[ah];
        r16[ax] &= 0x00ff;
        return;
    } while (1);
}
function* sub_2e19() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x2117;
        memory[ds*16 + 0x2164] = r8[al];
        r16[cx] = 0x0000;
    case 0x2e22:
        if (memory[ds*16 + 0x2164] == r8[cl])
            return;
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        flags.carry = false;
        r16[dx] = rcr16(r16[dx], 0x0001);
        r16[ax] = rcr16(r16[ax], 0x0001);
        memory16set(ds, r16[bx] + 2, r16[dx]);
        memory[ds*16 + r16[bx] + 1] = r8[ah];
        r8[cl]++;
        pc = 0x2e22;
        break;
        return;
    } while (1);
}
function* sub_2e42() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        r16[bx] &= 0x0003;
        r16[bx] += r16[bx];
        r16[bx] += r16[bx];
        r16[bx] += r16[bx];
        r16[bx] += r16[bx];
        r16[cx] = 0x0010;
    case 0x2e51:
        push(r16[bx]);
        r16[bx] += 0x20cf;
        r8[ah] = memory[ds*16 + r16[bx]];
        r16[bx] = pop();
        if (r8[ah] == r8[al]) {
            pc = 0x2e68;
            break;
        }
        r16[cx]--;
        if (r16[cx] == 0x0000) {
            pc = 0x2e6e;
            break;
        }
        r16[bx]++;
        pc = 0x2e51;
        break;
    case 0x2e68:
        r8[al] = 0x10;
        r8[al] -= r8[cl];
        r16[bx] = pop();
        return;
    case 0x2e6e:
        r8[al] = 0xff;
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_2e72() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x2117;
        memory16set(ds, si, 0x0000);
        memory16set(ds, si + 2, 0x0000);
        memory16set(ds, 0x2162, 0x0000);
        r16[ax] = memory16get(ds, 0x4f88);
        si = 0x20a3;
        di = 0x20b9;
        r16[bx] = 0x0004;
        yield* sub_2fa7();
        r16[ax] = memory16get(ds, 0x4f8a);
        si = 0x20a7;
        di = 0x20bd;
        r16[bx] = 0x0004;
        yield* sub_2fa7();
        r16[ax] = memory16get(ds, 0x3c6a);
        si = 0x20ab;
        di = 0x20c1;
        r16[bx] = 0x0004;
        yield* sub_2fa7();
        r16[ax] = memory16get(ds, 0x3c70);
        si = 0x20af;
        di = 0x20c5;
        r16[bx] = 0x0004;
        yield* sub_2fa7();
        r16[ax] = 0x0000;
        if (memory16get(ds, 0x3a54) != 0x03c0) {
            pc = 0x2ed1;
            break;
        }
        r16[ax] = 0x0001;
    case 0x2ed1:
        si = 0x20b3;
        di = 0x20c9;
        r16[bx] = 0x0001;
        yield* sub_2fa7();
        r16[ax] = memory16get(ds, 0x2162);
        si = 0x20b4;
        di = 0x20ca;
        r16[bx] = 0x0005;
        yield* sub_2fa7();
        r16[ax] = 0x0002;
        yield* sub_587c();
        memory[ds*16 + 0x2117] = r8[al];
        yield* sub_2f7e();
        r16[ax] = 0x0008;
        yield* sub_587c();
        r16[dx] = r16[ax];
        r8[cl] = 0x05;
        r8[al] <<= r8[cl];
        r8[al] |= 0x10;
        memory[ds*16 + 0x2117] = memory[ds*16 + 0x2117] | r8[al];
        di = 0x30e5;
        memory[ds*16 + 0x2164] = 0x00;
        r8[al] = memory[ds*16 + 0x2117];
        yield* sub_2f35();
        r8[al] = memory[ds*16 + 0x2118];
        yield* sub_2f2c();
        r8[al] = memory[ds*16 + 0x2119];
        yield* sub_2f2c();
        r8[al] = memory[ds*16 + 0x211a];
        yield* sub_2f2c();
        return;
    } while (1);
}
function* sub_2f2c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.carry = r16[dx] & 1;
        r16[dx] = ror16(r16[dx], 0x0001);
        if (!flags.carry) {
            pc = 0x2f35;
            break;
        }
        r8[al] ^= 0xff;
        pc = 0x2f35;
        break;
    case 0x2f35:
        push(r16[dx]);
        r8[dh] = r8[al];
        r8[al] &= 0x0f;
        r8[dl] = r8[al];
        r8[al] = memory[ds*16 + 0x2164];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        r8[al] += r8[dl];
        r16[ax] &= 0x003f;
        r16[bx] = r16[ax];
        r16[bx] += 0x20cf;
        r8[al] = memory[ds*16 + r16[bx]];
        memory[ds*16 + di] = r8[al];
        di++;
        r8[al] = r8[dh];
        r8[al] &= 0xf0;
        r8[al] >>= r8[cl];
        r8[dl] = r8[al];
        r8[al] = memory[ds*16 + 0x2164];
        r8[al] <<= r8[cl];
        r8[al] += r8[dl];
        r16[ax] &= 0x003f;
        r16[bx] = r16[ax];
        r16[bx] += 0x20cf;
        r8[al] = memory[ds*16 + r16[bx]];
        memory[ds*16 + di] = r8[al];
        di++;
        memory[ds*16 + 0x2164] += 1;
        r16[dx] = pop();
        return;
    } while (1);
}
function* sub_2f35() {
    push(r16[dx]);
    r8[dh] = r8[al];
    r8[al] &= 0x0f;
    r8[dl] = r8[al];
    r8[al] = memory[ds*16 + 0x2164];
    r8[cl] = 0x04;
    r8[al] <<= r8[cl];
    r8[al] += r8[dl];
    r16[ax] &= 0x003f;
    r16[bx] = r16[ax];
    r16[bx] += 0x20cf;
    r8[al] = memory[ds*16 + r16[bx]];
    memory[ds*16 + di] = r8[al];
    di++;
    r8[al] = r8[dh];
    r8[al] &= 0xf0;
    r8[al] >>= r8[cl];
    r8[dl] = r8[al];
    r8[al] = memory[ds*16 + 0x2164];
    r8[al] <<= r8[cl];
    r8[al] += r8[dl];
    r16[ax] &= 0x003f;
    r16[bx] = r16[ax];
    r16[bx] += 0x20cf;
    r8[al] = memory[ds*16 + r16[bx]];
    memory[ds*16 + di] = r8[al];
    di++;
    memory[ds*16 + 0x2164] += 1;
    r16[dx] = pop();
}
function* sub_2f7e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x2117;
        memory[ds*16 + 0x2164] = r8[al];
        r16[cx] = 0x0000;
    case 0x2f87:
        if (memory[ds*16 + 0x2164] == r8[cl])
            return;
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        flags.carry = false;
        r16[ax] = rcl16(r16[ax], 0x0001);
        r16[dx] = rcl16(r16[dx], 0x0001);
        memory16set(ds, r16[bx] + 2, r16[dx]);
        memory[ds*16 + r16[bx] + 1] = r8[ah];
        r8[cl]++;
        pc = 0x2f87;
        break;
        return;
    } while (1);
}
function* sub_2fa7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx]--;
    case 0x2fa8:
        flags.carry = r16[ax] & 1;
        r16[ax] = ror16(r16[ax], 0x0001);
        if (!flags.carry) {
            pc = 0x2fc4;
            break;
        }
        memory16set(ds, 0x2162, memory16get(ds, 0x2162) + 1);
        push(r16[bx]);
        r8[dl] = memory[ds*16 + r16[bx] + si];
        r8[bl] = memory[ds*16 + r16[bx] + di];
        r8[bh] = 0x00;
        r16[bx] += 0x2117;
        memory[ds*16 + r16[bx]] = memory[ds*16 + r16[bx]] | r8[dl];
        r16[bx] = pop();
    case 0x2fc4:
        r16[bx]--;
        if (r16[bx] != 0xffff) {
            pc = 0x2fa8;
            break;
        }
        return;
    } while (1);
}
function* sub_2fcb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x3cde;
        r16[cx] = 0x0058;
    case 0x2fd1:
        memory16set(ds, si, 0xffff);
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x2fd1;
            break;
        }
        return;
    } while (1);
}
function* sub_2fdd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x3d8e;
        r16[cx] = 0x0028;
    case 0x2fe3:
        memory16set(ds, si, 0xffff);
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x2fe3;
            break;
        }
        return;
    } while (1);
}
function* sub_2fef() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) == 0x0000) {
            pc = 0x3032;
            break;
        }
        if (memory16gets(ds, 0x3c68) < 0) {
            pc = 0x3032;
            break;
        }
        if (memory16get(ds, 0x3c5e) == 0xffff) {
            pc = 0x3032;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0001) {
            pc = 0x3033;
            break;
        }
        si = 0x3c5e;
        r16[bx] = memory16get(ds, si + 2);
        memory16set(ds, 0x203e, r16[bx]);
        if (memory16get(ds, 0x203e) <= 0x0180) {
            pc = 0x3024;
            break;
        }
        memory16set(ds, 0x203e, 0x0180);
    case 0x3024:
        if (memory16get(ds, 0x203e) >= 0x0080) {
            pc = 0x3032;
            break;
        }
        memory16set(ds, 0x203e, 0x0080);
    case 0x3032:
        return;
    case 0x3033:
        si = 0x3c5e;
        r16[bx] = memory16get(ds, si);
        memory16set(ds, 0x203e, r16[bx]);
        if (memory16get(ds, 0x203e) <= 0x0180) {
            pc = 0x304c;
            break;
        }
        memory16set(ds, 0x203e, 0x0180);
    case 0x304c:
        if (memory16get(ds, 0x203e) >= 0x0080)
            return;
        memory16set(ds, 0x203e, 0x0080);
        return;
    } while (1);
}
function* sub_305b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) == 0x0000) {
            pc = 0x3090;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0001) {
            pc = 0x30ab;
            break;
        }
        r16[bx] = memory16get(ds, 0x203e);
        r16[bx] -= 0x0080;
        r8[cl] = 0x06;
        r16[bx] <<= r8[cl];
        r16[bx] += r16[ax];
        r16[dx] = 0x03d4;
        r8[al] = 0x0c;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = r8[bh];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x0d;
        out8(r16[dx], r8[al] | 0xd0);
        r16[dx] = 0x03d5;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        yield* sync();
        return;
    case 0x3090:
        r16[bx] = r16[ax];
        r16[dx] = 0x03d4;
        r8[al] = 0x0c;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = r8[bh];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x0d;
        out8(r16[dx], r8[al] | 0xd0);
        r16[dx] = 0x03d5;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        yield* sync();
        return;
    case 0x30ab:
        push(r16[ax]);
        r16[bx] = memory16get(ds, 0x203e);
        r16[bx] -= 0x0080;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[ax] = pop();
        r16[bx] += r16[ax];
        r16[dx] = 0x03d4;
        r8[al] = 0x0c;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = r8[bh];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x0d;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        return;
    } while (1);
}
function* sub_30d4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) != 0x0001)
            return;
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        r16[dx] = 0x03c0;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[ax] = memory16get(ds, 0x203e);
        r16[ax] &= 0x0003;
        if (memory[ds*16 + 0x0024] == 0x01) {
            pc = 0x30f4;
            break;
        }
        r8[al] += r8[al];
    case 0x30f4:
        r16[dx] = 0x03c0;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c0;
        r8[al] = 0x20;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        return;
    } while (1);
}
function* sub_3105() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0012;
        interrupt(0x10);
        r16[dx] = 0x03d4;
        r8[al] = 0x11;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x7f;
        r16[dx] = 0x03d5;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        si = 0x2075;
        r16[bx] = 0x0000;
        r16[cx] = 0x0018;
    case 0x3125:
        r16[dx] = 0x03d4;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        lodsb_data_forward();
        r16[dx] = 0x03d5;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r8[bl]++;
        if (--r16[cx]) {
            pc = 0x3125;
            break;
        }
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        si = 0x208e;
        r16[bx] = 0x0000;
        r16[cx] = 0x0014;
    case 0x3143:
        r16[dx] = 0x03c0;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        lodsb_data_forward();
        r16[dx] = 0x03c0;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r8[bl]++;
        if (--r16[cx]) {
            pc = 0x3143;
            break;
        }
        r16[dx] = 0x03c0;
        r8[al] = 0x20;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        r16[dx] = 0x03c4;
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c5;
        r8[al] = in8(r16[dx]);
        r8[al] &= 0xf7;
        r16[dx] = 0x03c5;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x14;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = in8(r16[dx]);
        r8[al] &= 0xbf;
        r16[dx] = 0x03d5;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x17;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = in8(r16[dx]);
        r8[al] |= 0x40;
        r16[dx] = 0x03d5;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03ce;
        r8[al] = 0x05;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03cf;
        r8[al] = 0x40;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x03;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x82;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x01;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x3f;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x4c;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x40;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x06;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x0b;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x10;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0xe2;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x11;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x0c;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x15;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0xe7;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x07;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x3e;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x09;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x41;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x12;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0xcf;
        out8(r16[dx], r8[al]);
        return;
    } while (1);
}
function* sub_342c() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(di);
    push(si);
    push(es);
    push(ds);
    r16[ax] = 0x351c;
    interrupt(0x21);
    memory16set(ds, 0x2042, es);
    memory16set(ds, 0x2040, r16[bx]);
    r16[dx] = es;
    r16[ax] = 0x01ed;
    es = r16[ax];
    si = 0x13f0;
    memory16set(es, si, r16[bx]);
    memory16set(es, si + 2, r16[dx]);
    r16[ax] = 0x3509;
    interrupt(0x21);
    memory16set(ds, 0x2046, es);
    memory16set(ds, 0x2044, r16[bx]);
    r16[dx] = es;
    r16[ax] = 0x01ed;
    es = r16[ax];
    si = 0x14de;
    memory16set(es, si, r16[bx]);
    memory16set(es, si + 2, r16[dx]);
    r16[ax] = 0x351b;
    interrupt(0x21);
    memory16set(ds, 0x204a, es);
    memory16set(ds, 0x2048, r16[bx]);
    r16[ax] = 0x01ed;
    ds = r16[ax];
    r16[dx] = 0x1355;
    r16[ax] = 0x251c;
    interrupt(0x21);
    r16[ax] = 0x01ed;
    ds = r16[ax];
    r16[dx] = 0x1410;
    r16[ax] = 0x2509;
    interrupt(0x21);
    r16[ax] = 0x01ed;
    ds = r16[ax];
    r16[dx] = 0x15dd;
    r16[ax] = 0x251b;
    interrupt(0x21);
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_34ae() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(di);
    push(si);
    push(es);
    push(ds);
    r16[dx] = memory16get(ds, 0x2040);
    r16[ax] = memory16get(ds, 0x2042);
    ds = r16[ax];
    r16[ax] = 0x251c;
    interrupt(0x21);
    r16[ax] = 0x0b52;
    ds = r16[ax];
    r16[dx] = memory16get(ds, 0x2044);
    r16[ax] = memory16get(ds, 0x2046);
    ds = r16[ax];
    r16[ax] = 0x2509;
    interrupt(0x21);
    r16[ax] = 0x0b52;
    ds = r16[ax];
    r16[dx] = memory16get(ds, 0x2048);
    r16[ax] = memory16get(ds, 0x204a);
    ds = r16[ax];
    r16[ax] = 0x251b;
    interrupt(0x21);
    ds = pop();
    es = pop();
    si = pop();
    di = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_34f3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0x0b52;
        ds = r16[ax];
        r16[dx] = 0x03da;
    case 0x34fc:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] == 0) {
            pc = 0x34fc;
            break;
        }
        ds = pop();
        return;
    } while (1);
}
function* sub_3503() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03da;
    case 0x3506:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x08;
        if (r8[al] != 0) {
            pc = 0x3506;
            break;
        }
        return;
    } while (1);
}
function* sub_350c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        return;
        if (memory[ds*16 + 0x204f] != 0x00) {
            pc = 0x351a;
            break;
        }
    case 0x3513:
        if (memory[ds*16 + 0x204f] == 0x00) {
            pc = 0x3513;
            break;
        }
    case 0x351a:
        memory[ds*16 + 0x204f] = 0x00;
        return;
    } while (1);
}
function* sub_3522() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x48;
        yield* sub_2888();
        memory[ds*16 + 0x236a] = 0x3a;
        memory[ds*16 + 0x236b] = 0x3c;
        di = 0x0603;
        r16[dx] = 0x001c;
        r16[cx] = 0x0018;
        yield* sub_3fa2();
        si = 0x23ba;
        yield* sub_53d1();
        si = 0x26b0;
        r16[cx] = 0x000a;
        yield* sub_2ce0();
        r16[ax] = memory16get(ds, 0x0014);
        r16[ax] -= 0x0001;
        si = 0x26d8;
        yield* sub_3de6();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
    case 0x357c:
        //yield* sync();
        if (memory[ds*16 + 0x0020] != 0x01) {
            pc = 0x358b;
            break;
        }
        memory[ds*16 + 0x0025] = 0xff;
        pc = 0x3636;
        break;
    case 0x358b:
        yield* sub_5476();
        r8[ah] = r8[al];
        r8[al] &= 0x10;
        if (r8[al] != 0) {
            pc = 0x35fa;
            break;
        }
        r8[al] = r8[ah];
        r8[al] &= 0x03;
        if (r8[al] == 0) {
            pc = 0x35ef;
            break;
        }
        if (memory[ds*16 + 0x236c] != 0x00) {
            pc = 0x357c;
            break;
        }
        r8[al] = r8[ah];
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x35c2;
            break;
        }
        memory[ds*16 + 0x236c] = 0xff;
        if (memory16get(ds, 0x0014) != 0x0001) {
            pc = 0x35bc;
            break;
        }
        memory16set(ds, 0x0014, 0x0005);
        pc = 0x35e1;
        break;
    case 0x35bc:
        memory16set(ds, 0x0014, memory16get(ds, 0x0014) - 1);
        pc = 0x35e1;
        break;
    case 0x35c2:
        r8[al] = r8[ah];
        r8[al] &= 0x02;
        if (r8[al] == 0) {
            pc = 0x35e1;
            break;
        }
        memory[ds*16 + 0x236c] = 0xff;
        if (memory16get(ds, 0x0014) != 0x0005) {
            pc = 0x35dd;
            break;
        }
        memory16set(ds, 0x0014, 0x0001);
        pc = 0x35e1;
        break;
    case 0x35dd:
        memory16set(ds, 0x0014, memory16get(ds, 0x0014) + 1);
    case 0x35e1:
        r16[ax] = memory16get(ds, 0x0014);
        r16[ax] -= 0x0001;
        si = 0x26d8;
        yield* sub_3de6();
        pc = 0x357c;
        break;
    case 0x35ef:
        memory[ds*16 + 0x236c] = 0x00;
        yield* sub_8b8b();
        pc = 0x357c;
        break;
    case 0x35fa:
        si = 0x26b0;
        r16[ax] = memory16get(ds, 0x0014);
        r16[ax] -= 0x0001;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        r16[cx] = 0x0003;
    case 0x360e:
        push(r16[cx]);
        push(si);
        lodsw_data_forward();
        di = r16[ax];
        r16[dx] = 0x001d;
        r16[cx] = 0x000f;
        r8[al] = 0x48;
        yield* sub_2c94();
        r16[cx] = 0x0004;
        yield* sub_5429();
        si = pop();
        push(si);
        r16[cx] = 0x0002;
        yield* sub_2ce0();
        r16[cx] = 0x0006;
        yield* sub_5429();
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x360e;
            break;
        }
    case 0x3636:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        return;
    } while (1);
}
function* sub_3650() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x48;
        yield* sub_2888();
        memory[ds*16 + 0x236a] = 0x3a;
        memory[ds*16 + 0x236b] = 0x3c;
        di = 0x2f03;
        r16[dx] = 0x001c;
        r16[cx] = 0x000d;
        yield* sub_3fa2();
        si = 0x23a4;
        yield* sub_53d1();
        si = 0x2690;
        r16[cx] = 0x0006;
        yield* sub_2ce0();
        r16[ax] = memory16get(ds, 0x0010);
        r16[ax] -= 0x0002;
        si = 0x26a8;
        yield* sub_3de6();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
    case 0x36aa:
        //yield* sync();
        if (memory[ds*16 + 0x0020] != 0x01) {
            pc = 0x36b9;
            break;
        }
        memory[ds*16 + 0x0025] = 0xff;
        pc = 0x3764;
        break;
    case 0x36b9:
        yield* sub_5476();
        r8[ah] = r8[al];
        r8[al] &= 0x10;
        if (r8[al] != 0) {
            pc = 0x3728;
            break;
        }
        r8[al] = r8[ah];
        r8[al] &= 0x03;
        if (r8[al] == 0) {
            pc = 0x371d;
            break;
        }
        if (memory[ds*16 + 0x236c] != 0x00) {
            pc = 0x36aa;
            break;
        }
        r8[al] = r8[ah];
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x36f0;
            break;
        }
        memory[ds*16 + 0x236c] = 0xff;
        if (memory16get(ds, 0x0010) != 0x0002) {
            pc = 0x36ea;
            break;
        }
        memory16set(ds, 0x0010, 0x0004);
        pc = 0x370f;
        break;
    case 0x36ea:
        memory16set(ds, 0x0010, memory16get(ds, 0x0010) - 1);
        pc = 0x370f;
        break;
    case 0x36f0:
        r8[al] = r8[ah];
        r8[al] &= 0x02;
        if (r8[al] == 0) {
            pc = 0x370f;
            break;
        }
        memory[ds*16 + 0x236c] = 0xff;
        if (memory16get(ds, 0x0010) != 0x0004) {
            pc = 0x370b;
            break;
        }
        memory16set(ds, 0x0010, 0x0002);
        pc = 0x370f;
        break;
    case 0x370b:
        memory16set(ds, 0x0010, memory16get(ds, 0x0010) + 1);
    case 0x370f:
        r16[ax] = memory16get(ds, 0x0010);
        r16[ax] -= 0x0002;
        si = 0x26a8;
        yield* sub_3de6();
        pc = 0x36aa;
        break;
    case 0x371d:
        memory[ds*16 + 0x236c] = 0x00;
        yield* sub_8b8b();
        pc = 0x36aa;
        break;
    case 0x3728:
        si = 0x2690;
        r16[ax] = memory16get(ds, 0x0010);
        r16[ax] -= 0x0002;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        r16[cx] = 0x0003;
    case 0x373c:
        push(r16[cx]);
        push(si);
        lodsw_data_forward();
        di = r16[ax];
        r16[dx] = 0x0029;
        r16[cx] = 0x000f;
        r8[al] = 0x48;
        yield* sub_2c94();
        r16[cx] = 0x0004;
        yield* sub_5429();
        si = pop();
        push(si);
        r16[cx] = 0x0002;
        yield* sub_2ce0();
        r16[cx] = 0x0006;
        yield* sub_5429();
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x373c;
            break;
        }
    case 0x3764:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        return;
    } while (1);
}
function* sub_377e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x48;
        yield* sub_2888();
        memory[ds*16 + 0x236a] = 0x3a;
        memory[ds*16 + 0x236b] = 0x3c;
        di = 0x2e05;
        r16[dx] = 0x001a;
        r16[cx] = 0x000c;
        yield* sub_3fa2();
        si = 0x238a;
        yield* sub_53d1();
        si = 0x267a;
        r16[cx] = 0x0004;
        yield* sub_2ce0();
        r16[ax] = memory16get(ds, 0x0012);
        si = 0x268a;
        yield* sub_3de6();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
        memory[ds*16 + 0x236c] = 0x00;
    case 0x37db:
        //yield* sync();
        if (memory[ds*16 + 0x0020] != 0x01) {
            pc = 0x37ea;
            break;
        }
        memory[ds*16 + 0x0025] = 0xff;
        pc = 0x3884;
        break;
    case 0x37ea:
        //yield* sync();
        yield* sub_5476();
        r8[ah] = r8[al];
        r8[al] &= 0x10;
        if (r8[al] != 0) {
            pc = 0x384b;
            break;
        }
        r8[al] = r8[ah];
        r8[al] &= 0x03;
        if (r8[al] == 0) {
            pc = 0x3840;
            break;
        }
        if (memory[ds*16 + 0x236c] != 0x00) {
            pc = 0x383e;
            break;
        }
        r8[al] = r8[ah];
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x3820;
            break;
        }
        memory[ds*16 + 0x236c] = 0xff;
        memory16set(ds, 0x0012, memory16get(ds, 0x0012) - 1);
        memory16set(ds, 0x0012, memory16get(ds, 0x0012) & 0x0001);
        r16[ax] = memory16get(ds, 0x0012);
        si = 0x268a;
        yield* sub_3de6();
        pc = 0x383e;
        break;
    case 0x3820:
        r8[al] = r8[ah];
        r8[al] &= 0x02;
        if (r8[al] == 0) {
            pc = 0x383e;
            break;
        }
        memory[ds*16 + 0x236c] = 0xff;
        memory16set(ds, 0x0012, memory16get(ds, 0x0012) + 1);
        memory16set(ds, 0x0012, memory16get(ds, 0x0012) & 0x0001);
        r16[ax] = memory16get(ds, 0x0012);
        si = 0x268a;
        yield* sub_3de6();
    case 0x383e:
        pc = 0x37db;
        break;
    case 0x3840:
        //yield* sync();
        memory[ds*16 + 0x236c] = 0x00;
        yield* sub_8b8b();
        pc = 0x37db;
        break;
    case 0x384b:
        si = 0x267a;
        r16[ax] = memory16get(ds, 0x0012);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        r16[cx] = 0x0003;
    case 0x385c:
        push(r16[cx]);
        push(si);
        lodsw_data_forward();
        di = r16[ax];
        r16[dx] = 0x0020;
        r16[cx] = 0x000f;
        r8[al] = 0x48;
        yield* sub_2c94();
        r16[cx] = 0x0004;
        yield* sub_5429();
        si = pop();
        push(si);
        r16[cx] = 0x0002;
        yield* sub_2ce0();
        r16[cx] = 0x0006;
        yield* sub_5429();
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x385c;
            break;
        }
    case 0x3884:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        return;
    } while (1);
}
function* sub_389e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x48;
        yield* sub_2888();
        si = 0x266e;
        r16[cx] = 0x0003;
        yield* sub_2ce0();
        di = 0x4b12;
        r16[ax] = memory16get(ds, 0x000e);
        r16[ax] += 0x0058;
        yield* sub_2c81();
        di = 0x4b2d;
        r16[ax] = memory16get(ds, 0x0010);
        r16[ax] += r16[ax];
        di -= r16[ax];
        r16[cx] = 0x0000;
        r16[ax] = 0x005c;
    case 0x38c8:
        if (r16[cx] == memory16get(ds, 0x000e)) {
            pc = 0x38da;
            break;
        }
        push(di);
        push(r16[ax]);
        push(r16[cx]);
        yield* sub_2c81();
        r16[cx] = pop();
        r16[ax] = pop();
        di = pop();
        di += 0x0005;
    case 0x38da:
        r16[ax]++;
        r16[cx]++;
        if (r16[cx] == memory16get(ds, 0x0010)) {
            pc = 0x38e4;
            break;
        }
        pc = 0x38c8;
        break;
    case 0x38e4:
        memory[ds*16 + 0x236a] = 0x3a;
        memory[ds*16 + 0x236b] = 0x3c;
        di = 0x3603;
        r16[dx] = 0x001c;
        r16[cx] = 0x000c;
        yield* sub_3fa2();
        si = 0x2476;
        memory16set(ds, si, 0x008e);
        memory16set(ds, si + 2, 0x005e);
        memory16set(ds, si + 4, 0x259a);
        memory16set(ds, si + 6, 0x0000);
        si = 0x245e;
        memory16set(ds, si, 0x0047);
        memory16set(ds, si + 2, 0x0096);
        memory16set(ds, si + 4, 0x2562);
        if (memory16get(ds, 0x000e) != 0x0002) {
            pc = 0x3939;
            break;
        }
        memory16set(ds, si + 4, 0x257e);
    case 0x3939:
        memory16set(ds, si + 6, 0x0000);
        yield* sub_3e0f();
        yield* sub_3e5d();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_281e();
        yield* sub_3e0f();
        yield* sub_3e5d();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
        r16[ax] = 0x0004;
        yield* sub_8c10();
        memory16set(ds, 0x2368, 0x0000);
    case 0x3985:
        memory16set(ds, 0x2368, memory16get(ds, 0x2368) + 1);
        yield* sub_34f3();
        yield* sub_281e();
        yield* sub_3e0f();
        yield* sub_3e5d();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        if (memory16get(ds, 0x2368) != 0x0012) {
            pc = 0x39ab;
            break;
        }
        si = 0x236d;
        yield* sub_53d1();
    case 0x39ab:
        if (memory16get(ds, 0x2368) != 0x001f) {
            pc = 0x39b8;
            break;
        }
        si = 0x2377;
        yield* sub_53d1();
    case 0x39b8:
        if (memory16get(ds, 0x2368) != 0x0029) {
            pc = 0x39d3;
            break;
        }
        memory16set(ds, 0x2368, 0x0017);
        di = 0x6197;
        r16[dx] = 0x0020;
        r16[cx] = 0x0007;
        r8[al] = 0x48;
        yield* sub_2c94();
    case 0x39d3:
        yield* sub_8b8b();
        yield* sub_350c();
        yield* sub_544d();
        if (r16[dx] != 0x0000) {
            pc = 0x39e3;
            break;
        }
        pc = 0x3985;
        break;
    case 0x39e3:
        yield* sub_8b80();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        return;
    } while (1);
}
function* sub_3a0c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x48;
        yield* sub_2888();
        di = 0x0f12;
        r16[ax] = memory16get(ds, 0x0014);
        r16[ax] += 0x004a;
        yield* sub_2c81();
        di = 0x0f16;
        r16[ax] = 0x0050;
        yield* sub_2c81();
        di = 0x0f2d;
        r16[ax] = 0x0068;
        yield* sub_2c81();
        memory[ds*16 + 0x236a] = 0x3a;
        memory[ds*16 + 0x236b] = 0x3c;
        di = 0x0603;
        r16[dx] = 0x001c;
        r16[cx] = 0x0018;
        yield* sub_3fa2();
        si = 0x263e;
        r16[ax] = memory16get(ds, 0x0010);
        r16[cx] = 0x0003;
        mul16(r16[cx]);
        r16[cx] = r16[ax];
        yield* sub_2ce0();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
        r16[ax] = 0x0003;
        yield* sub_8c10();
        r16[cx] = 0x0005;
    case 0x3a82:
        //yield* sync();
        if (memory[ds*16 + 0x0020] != 0x01) {
            pc = 0x3a91;
            break;
        }
        memory[ds*16 + 0x0025] = 0xff;
        pc = 0x3ac7;
        break;
    case 0x3a91:
        push(r16[cx]);
        yield* sub_34f3();
        di = 0x5510;
        r16[dx] = 0x0021;
        r16[cx] = 0x0017;
        r8[al] = 0x48;
        yield* sub_2c94();
        r16[cx] = 0x0005;
        yield* sub_5429();
        yield* sub_34f3();
        di = 0x5510;
        r16[ax] = 0x0052;
        yield* sub_2c81();
        di = 0x5520;
        r16[ax] = 0x0053;
        yield* sub_2c81();
        r16[cx] = 0x0005;
        yield* sub_5429();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x3a82;
            break;
        }
    case 0x3ac7:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        return;
    } while (1);
}
function* sub_3ae1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = 0x48;
        yield* sub_2888();
        if (memory16get(ds, 0x000e) != 0xffff) {
            pc = 0x3af0;
            break;
        }
        pc = 0x3ced;
        break;
    case 0x3af0:
        di = 0x0792;
        r16[ax] = memory16get(ds, 0x0014);
        r16[ax] += 0x004a;
        yield* sub_2c81();
        di = 0x0796;
        r16[ax] = 0x0050;
        yield* sub_2c81();
        di = 0x07ad;
        r16[ax] = 0x0068;
        yield* sub_2c81();
        memory[ds*16 + 0x236a] = 0x3a;
        memory[ds*16 + 0x236b] = 0x3c;
        di = 0x1a03;
        r16[dx] = 0x001c;
        r16[cx] = 0x0003;
        yield* sub_3fa2();
        memory[ds*16 + 0x236a] = 0x40;
        memory[ds*16 + 0x236b] = 0x41;
        di = 0x2a03;
        r16[dx] = 0x001c;
        r16[cx] = 0x0003;
        yield* sub_3fa2();
        if (memory16get(ds, 0x0010) == 0x0002) {
            pc = 0x3b7c;
            break;
        }
        memory[ds*16 + 0x236a] = 0x40;
        memory[ds*16 + 0x236b] = 0x41;
        di = 0x3a03;
        r16[dx] = 0x001c;
        r16[cx] = 0x0003;
        yield* sub_3fa2();
        if (memory16get(ds, 0x0010) == 0x0003) {
            pc = 0x3b7c;
            break;
        }
        memory[ds*16 + 0x236a] = 0x40;
        memory[ds*16 + 0x236b] = 0x41;
        di = 0x4a03;
        r16[dx] = 0x001c;
        r16[cx] = 0x0003;
        yield* sub_3fa2();
    case 0x3b7c:
        di = 0x3c5e;
        r16[cx] = memory16get(ds, 0x0010);
    case 0x3b83:
        push(r16[cx]);
        si = 0x25b6;
        r16[ax] = memory16get(ds, di + 24);
        r16[ax] += r16[ax];
        si += r16[ax];
        si = memory16get(ds, si);
        push(di);
        r16[cx] = memory16get(ds, di + 30);
        r16[cx] += 0x0003;
    case 0x3b9b:
        push(r16[cx]);
        lodsw_data_forward();
        di = r16[ax];
        lodsw_data_forward();
        push(si);
        yield* sub_2c81();
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x3b9b;
            break;
        }
        di = pop();
        r16[cx] = pop();
        di += 0x0020;
        if (--r16[cx]) {
            pc = 0x3b83;
            break;
        }
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
        r16[ax] = 0x0002;
        yield* sub_8c10();
        r16[cx] = 0x0026;
        yield* sub_5429();
        if (memory[ds*16 + 0x0025] == 0x00) {
            pc = 0x3be7;
            break;
        }
        pc = 0x3cd3;
        break;
    case 0x3be7:
        r16[ax] = memory16get(ds, 0x000e);
        r16[cx] = 0x0020;
        mul16(r16[cx]);
        si = 0x3c5e;
        si += r16[ax];
        r16[ax] = memory16get(ds, 0x000e);
        r16[ax] += r16[ax];
        di = 0x25b6;
        di += r16[ax];
        di = memory16get(ds, di);
        r16[ax] = 0x0003;
        r16[bx] = memory16get(ds, si + 30);
        push(r16[bx]);
        r16[ax] += r16[bx];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        di += r16[ax];
        si = di;
        lodsw_data_forward();
        di = r16[ax];
        lodsw_data_forward();
        yield* sub_2c81();
        r16[ax] = memory16get(ds, 0x000e);
        r16[cx] = 0x0014;
        mul16(r16[cx]);
        si = 0x23fe;
        si += r16[ax];
        r16[ax] = pop();
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[cx] = r16[ax];
        si = 0x248e;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 4, 0x24e6);
        si = 0x24a4;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 4, 0x24e6);
        si = 0x24ba;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 4, 0x24e6);
        si = 0x24d0;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 4, 0x24e6);
        r16[ax] = 0x0003;
        yield* sub_8ca1();
    case 0x3c7f:
        yield* sub_34f3();
        yield* sub_281e();
        yield* sub_3ec9();
        if (r16[dx] == 0xffff) {
            pc = 0x3ca1;
            break;
        }
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_3503();
        yield* sub_34f3();
        yield* sub_3503();
        pc = 0x3c7f;
        break;
    case 0x3ca1:
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        r16[ax] = memory16get(ds, 0x000e);
        r16[cx] = 0x0020;
        mul16(r16[cx]);
        si = 0x3c5e;
        si += r16[ax];
        memory16set(ds, si + 30, memory16get(ds, si + 30) + 1);
        r16[ax] = memory16get(ds, 0x0014);
        if (memory16get(ds, si + 30) != r16[ax]) {
            pc = 0x3ccd;
            break;
        }
        memory16set(ds, 0x0016, 0x0001);
    case 0x3ccd:
        r16[cx] = 0x0019;
        yield* sub_5429();
    case 0x3cd3:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        return;
    case 0x3ced:
        di = 0x1190;
        r16[ax] = 0x0051;
        yield* sub_2c81();
        di = 0x11a1;
        r16[ax] = 0x0052;
        yield* sub_2c81();
        memory[ds*16 + 0x236a] = 0x3a;
        memory[ds*16 + 0x236b] = 0x3c;
        di = 0x3d03;
        r16[dx] = 0x001c;
        r16[cx] = 0x000a;
        yield* sub_3fa2();
        r16[ax] = memory16get(ds, 0x0010);
        r16[ax] -= 0x0002;
        r16[ax] += r16[ax];
        si = 0x23ce;
        si += r16[ax];
        lodsw_data_forward();
        si = r16[ax];
    case 0x3d27:
        lodsw_data_forward();
        if (r16[ax] == 0xffff) {
            pc = 0x3d37;
            break;
        }
        di = r16[ax];
        lodsw_data_forward();
        push(si);
        yield* sub_2c81();
        si = pop();
        pc = 0x3d27;
        break;
    case 0x3d37:
        si = 0x2476;
        memory16set(ds, si, 0x0060);
        memory16set(ds, si + 2, 0x0064);
        memory16set(ds, si + 4, 0x259a);
        memory16set(ds, si + 6, 0x0000);
        memory16set(ds, 0x2368, 0x0000);
        yield* sub_3e0f();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_3e0f();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
        r16[ax] = 0x0001;
        yield* sub_8c10();
    case 0x3d8f:
        //yield* sync();
        if (memory[ds*16 + 0x0020] != 0x01) {
            pc = 0x3d9e;
            break;
        }
        memory[ds*16 + 0x0025] = 0xff;
        pc = 0x3dc0;
        break;
    case 0x3d9e:
        memory16set(ds, 0x2368, memory16get(ds, 0x2368) + 1);
        yield* sub_34f3();
        yield* sub_281e();
        yield* sub_3e0f();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_350c();
        if (memory16get(ds, 0x2368) == 0x0036) {
            pc = 0x3dc0;
            break;
        }
        pc = 0x3d8f;
        break;
    case 0x3dc0:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        return;
    } while (1);
}
function* sub_3de6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(r16[ax]);
    case 0x3de8:
        lodsw_data_forward();
        if (r16[ax] == 0xffff) {
            pc = 0x3dff;
            break;
        }
        di = r16[ax];
        push(si);
        r16[dx] = 0x0008;
        r16[cx] = 0x0010;
        r8[al] = 0x48;
        yield* sub_2c94();
        si = pop();
        pc = 0x3de8;
        break;
    case 0x3dff:
        r16[ax] = pop();
        si = pop();
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        di = r16[ax];
        r16[ax] = 0x0067;
        yield* sub_2c81();
        return;
    } while (1);
}
function* sub_3e0f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x2476;
        memory16set(ds, si + 6, memory16get(ds, si + 6) + 1);
        if (memory16get(ds, si + 6) < 0x0001) {
            pc = 0x3e3a;
            break;
        }
        memory16set(ds, si + 6, 0x0000);
        memory16set(ds, si + 4, memory16get(ds, si + 4) + 0x0004);
        r16[bx] = memory16get(ds, si + 4);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x3e3a;
            break;
        }
        r16[bx] = 0x259a;
        memory16set(ds, si + 4, r16[bx]);
    case 0x3e3a:
        r16[bx] = memory16get(ds, si + 4);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 8, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 10, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        si += 0x0008;
        yield* sub_2782();
        return;
    } while (1);
}
function* sub_3e5d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x245e;
        memory16set(ds, si + 6, memory16get(ds, si + 6) + 1);
        if (memory16get(ds, si + 6) < 0x0003) {
            pc = 0x3e92;
            break;
        }
        memory16set(ds, si + 6, 0x0000);
        memory16set(ds, si + 4, memory16get(ds, si + 4) + 0x0006);
        r16[bx] = memory16get(ds, si + 4);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x3e92;
            break;
        }
        r16[bx] = 0x2562;
        if (memory16get(ds, 0x000e) != 0x0002) {
            pc = 0x3e8e;
            break;
        }
        r16[bx] = 0x257e;
    case 0x3e8e:
        memory16set(ds, si + 4, r16[bx]);
    case 0x3e92:
        r16[bx] = memory16get(ds, si + 4);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 8, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 10, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] += memory16get(ds, r16[bx] + 4);
        push(r16[cx]);
        push(r16[dx]);
        si += 0x0008;
        yield* sub_2782();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[cx] -= 0x0047;
        r16[dx] -= 0x0011;
        si = 0x244e;
        yield* sub_2782();
        return;
    } while (1);
}
function* sub_3ec9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x248e;
        r16[dx] = memory16get(ds, di);
        r16[cx] = memory16get(ds, di + 2);
        r16[bx] = memory16get(ds, di + 4);
        memory16set(ds, di + 4, memory16get(ds, di + 4) + 0x0008);
        si = r16[bx];
        lodsw_data_forward();
        if (r16[ax] != 0xfc18) {
            pc = 0x3ee8;
            break;
        }
        pc = 0x3f9e;
        break;
    case 0x3ee8:
        memory16set(ds, di + 6, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, di + 8, r16[ax]);
        lodsw_data_forward();
        r16[dx] += r16[ax];
        lodsw_data_forward();
        r16[cx] += r16[ax];
        si = di;
        si += 0x0006;
        yield* sub_2782();
        di = 0x24a4;
        r16[dx] = memory16get(ds, di);
        r16[cx] = memory16get(ds, di + 2);
        r16[bx] = memory16get(ds, di + 4);
        memory16set(ds, di + 4, memory16get(ds, di + 4) + 0x0008);
        si = r16[bx];
        lodsw_data_forward();
        r16[ax] += 0x0010;
        memory16set(ds, di + 6, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, di + 8, r16[ax]);
        lodsw_data_forward();
        r16[ax] = -r16[ax];
        r16[dx] += r16[ax];
        lodsw_data_forward();
        r16[cx] += r16[ax];
        si = di;
        si += 0x0006;
        yield* sub_2782();
        di = 0x24ba;
        r16[dx] = memory16get(ds, di);
        r16[cx] = memory16get(ds, di + 2);
        r16[bx] = memory16get(ds, di + 4);
        memory16set(ds, di + 4, memory16get(ds, di + 4) + 0x0008);
        si = r16[bx];
        lodsw_data_forward();
        r16[ax] += 0x0020;
        memory16set(ds, di + 6, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, di + 8, r16[ax]);
        lodsw_data_forward();
        r16[dx] += r16[ax];
        lodsw_data_forward();
        r16[ax] = -r16[ax];
        r16[cx] += r16[ax];
        si = di;
        si += 0x0006;
        yield* sub_2782();
        di = 0x24d0;
        r16[dx] = memory16get(ds, di);
        r16[cx] = memory16get(ds, di + 2);
        r16[bx] = memory16get(ds, di + 4);
        memory16set(ds, di + 4, memory16get(ds, di + 4) + 0x0008);
        si = r16[bx];
        lodsw_data_forward();
        r16[ax] += 0x0030;
        memory16set(ds, di + 6, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, di + 8, r16[ax]);
        lodsw_data_forward();
        r16[ax] = -r16[ax];
        r16[dx] += r16[ax];
        lodsw_data_forward();
        r16[ax] = -r16[ax];
        r16[cx] += r16[ax];
        si = di;
        si += 0x0006;
        yield* sub_2782();
        r16[dx] = 0x0000;
        return;
    case 0x3f9e:
        r16[dx] = 0xffff;
        return;
    } while (1);
}
function* sub_3fa2() {
    push(di);
    push(r16[cx]);
    push(r16[dx]);
    di += memory16get(ds, 0x0018);
    yield* sub_3fb7();
    r16[dx] = pop();
    r16[cx] = pop();
    di = pop();
    di += memory16get(ds, 0x001a);
    yield* sub_3fb7();
}
function* sub_3fb7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        push(si);
        push(es);
        push(ds);
        r16[ax] = 0x0400;
        r16[cx]++;
        mul16(r16[cx]);
        memory16set(ds, 0x2368, r16[ax]);
        push(di);
        r16[ax] = 0x0000;
        r8[al] = memory[ds*16 + 0x236a];
        yield* sub_273a();
        di = pop();
        di += memory16get(ds, 0x2368);
        r16[ax] = 0x003e;
        yield* sub_273a();
        ds = pop();
        es = pop();
        si = pop();
        di = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        r16[cx] = r16[dx];
    case 0x3fea:
        push(r16[cx]);
        di += 0x0002;
        push(di);
        r16[ax] = 0x003b;
        yield* sub_273a();
        di = pop();
        push(di);
        di += memory16get(ds, 0x2368);
        r16[ax] = 0x003b;
        yield* sub_273a();
        di = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x3fea;
            break;
        }
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        push(si);
        push(es);
        push(ds);
        push(di);
        r16[ax] = 0x0000;
        r8[al] = memory[ds*16 + 0x236b];
        yield* sub_273a();
        di = pop();
        di += memory16get(ds, 0x2368);
        r16[ax] = 0x003f;
        yield* sub_273a();
        ds = pop();
        es = pop();
        si = pop();
        di = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        di = pop();
        r16[ax] = r16[dx];
        r16[ax] += r16[ax];
        memory16set(ds, 0x2368, r16[ax]);
    case 0x4034:
        push(r16[cx]);
        di += 0x0400;
        push(di);
        r16[ax] = 0x003d;
        yield* sub_273a();
        di = pop();
        push(di);
        di += memory16get(ds, 0x2368);
        r16[ax] = 0x003d;
        yield* sub_273a();
        di = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x4034;
            break;
        }
        return;
    } while (1);
}
function* sub_4052() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x37c6, 0x5008);
        memory16set(ds, 0x37c8, 0x42fd);
        memory16set(ds, 0x28fa, 0x5a88);
        memory16set(ds, 0x28fc, 0x42fd);
        memory16set(ds, 0x26f2, 0x0000);
        r16[dx] = 0x03d4;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x40;
        out8(r16[dx], r8[al]);
        r16[ax] = 0x0061;
        yield* sub_2888();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        di = 0x0c80;
        r16[dx] = 0x0040;
        r16[cx] = 0x00be;
        r8[al] = 0x60;
        yield* sub_2c94();
        di = 0x4108;
        r16[ax] = 0x00c1;
        yield* sub_2c81();
        di = 0x140c;
        r16[ax] = 0x00c2;
        yield* sub_2c81();
        di = 0x1416;
        r16[ax] = 0x00c3;
        yield* sub_2c81();
        si = 0x3023;
        if (memory16get(ds, 0x4f8e) == 0x0003) {
            pc = 0x40d2;
            break;
        }
        si = 0x3059;
        if (memory16get(ds, 0x4f8e) == 0x0002) {
            pc = 0x40d2;
            break;
        }
        si = 0x308f;
        if (memory16get(ds, 0x4f8e) == 0x0001) {
            pc = 0x40d2;
            break;
        }
        si = 0x30cb;
    case 0x40d2:
        yield* sub_4ef1();
        yield* sub_2e72();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x30e5;
        di = 0x32b5;
        r16[cx] = 0x0008;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x30df;
        yield* sub_4ef1();
        r16[ax] = 0x0006;
        yield* sub_8c10();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
        r16[dx] = 0x0002;
        if (memory16get(ds, 0x4f8e) != 0x0000) {
            pc = 0x4126;
            break;
        }
        r16[dx] = 0x0001;
    case 0x4126:
        yield* sub_4d17();
        if (r16[dx] == 0x0000) {
            pc = 0x4135;
            break;
        }
        if (memory16get(ds, 0x4f8e) != 0x0000) {
            pc = 0x413b;
            break;
        }
    case 0x4135:
        memory16set(ds, 0x26fc, 0x0001);
    case 0x413b:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        return;
    } while (1);
}
function* sub_4155() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x26f2, 0x0000);
        r16[dx] = 0x03d4;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x40;
        out8(r16[dx], r8[al]);
        r16[ax] = 0x0000;
        yield* sub_2888();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        r16[ax] = 0x0009;
        yield* sub_77c8();
        di = 0x08de;
        push(ds);
        yield* sub_23d3();
        ds = pop();
        di = 0x0f00;
        r16[ax] = 0x00b7;
        yield* sub_2c81();
        di = 0x6415;
        r16[ax] = 0x00b8;
        yield* sub_2c81();
        di = 0x64a6;
        r16[ax] = 0x00b8;
        r16[ax] += memory16get(ds, 0x4f88);
        yield* sub_2c81();
        yield* sub_4241();
        r16[ax] = 0x0008;
        yield* sub_8c10();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
        memory[ds*16 + 0x2700] = 0x00;
        r16[cx] = 0x006c;
    case 0x41d4:
        push(r16[cx]);
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_34f3();
        yield* sub_4212();
        yield* sub_281e();
        yield* sub_4241();
        yield* sub_350c();
        yield* sub_544d();
        r16[cx] = pop();
        if (r16[dx] != 0x0000) {
            pc = 0x41f8;
            break;
        }
        if (--r16[cx]) {
            pc = 0x41d4;
            break;
        }
    case 0x41f8:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        return;
    } while (1);
}
function* sub_4212() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x26ee);
        r16[ax] += memory16get(ds, 0x001e);
        if (r16[ax] < 0x0006) {
            pc = 0x423c;
            break;
        }
        r16[ax] = 0x0000;
        si = 0x32be;
        memory[ds*16 + 0x2700] = ~memory[ds*16 + 0x2700];
        if (memory[ds*16 + 0x2700] != 0x00) {
            pc = 0x4232;
            break;
        }
        si = 0x32c1;
    case 0x4232:
        push(r16[ax]);
        r8[al] = 0x20;
        r16[cx] = 0x0001;
        yield* sub_2397();
        r16[ax] = pop();
    case 0x423c:
        memory16set(ds, 0x26ee, r16[ax]);
        return;
    } while (1);
}
function* sub_4241() {
    r16[ax] = memory16get(ds, 0x4f88);
    r16[ax] += r16[ax];
    r16[ax] += r16[ax];
    si = 0x328b;
    si += r16[ax];
    lodsw_data_forward();
    r16[dx] = r16[ax];
    lodsw_data_forward();
    r16[cx] = r16[ax];
    r16[ax] = memory16get(ds, 0x001c);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] &= 0x0018;
    di = 0x326b;
    di += r16[ax];
    si = 0x325b;
    r16[ax] = memory16get(ds, di);
    memory16set(ds, si, r16[ax]);
    r16[ax] = memory16get(ds, di + 2);
    memory16set(ds, si + 2, r16[ax]);
    yield* sub_2782();
}
function* sub_4279() {
    memory16set(ds, 0x26f2, 0x0000);
    r16[dx] = 0x03d4;
    r8[al] = 0x13;
    out8(r16[dx], r8[al]);
    r16[dx] = 0x03d5;
    r8[al] = 0x40;
    out8(r16[dx], r8[al]);
    r8[al] = 0x61;
    yield* sub_2888();
    r16[ax] = memory16get(ds, 0x001a);
    yield* sub_305b();
    di = 0x320f;
    di += memory16get(ds, 0x001a);
    r16[ax] = 0x00ac;
    yield* sub_273a();
    di = 0x3223;
    di += memory16get(ds, 0x001a);
    r16[ax] = memory16get(ds, 0x4f88);
    r16[ax] += 0x00ad;
    yield* sub_273a();
    di = 0x3227;
    di += memory16get(ds, 0x001a);
    r16[ax] = memory16get(ds, 0x4f8a);
    r16[ax] += 0x00ad;
    yield* sub_273a();
    r16[ax] = 0x0003;
    yield* sub_8c10();
    push(r16[cx]);
    r16[cx] = ds;
    es = r16[cx];
    di = 0x0bde;
    r16[cx] = 0x0300;
    r8[al] = 0x00;
    rep_stosb_data_forward();
    r16[cx] = pop();
    di = 0x08de;
    si = 0x0bde;
    yield* sub_233a();
    yield* sub_34f3();
    r16[bx] = 0x08de;
    yield* sub_23b5();
    r16[cx] = 0x0012;
    yield* sub_5429();
    push(r16[cx]);
    push(si);
    r16[cx] = ds;
    es = r16[cx];
    si = 0x08de;
    di = 0x0bde;
    r16[cx] = 0x0300;
    rep_movsb_data_data_forward();
    si = pop();
    r16[cx] = pop();
    si = 0x0bde;
    yield* sub_236a();
    yield* sub_2318();
    yield* sub_281e();
    yield* sub_2318();
    yield* sub_281e();
}
function* sub_4317() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x4317:
        memory[ds*16 + 0x0027] = 0xff;
        memory16set(ds, 0x37c6, 0xe2b0);
        memory16set(ds, 0x37c8, 0x1650);
        memory16set(ds, 0x28fa, 0xe2a8);
        memory16set(ds, 0x28fc, 0x1650);
        r16[ax] = 0x0008;
        yield* sub_77c8();
        di = 0x34bc;
        push(ds);
        yield* sub_23d3();
        ds = pop();
        r8[al] = 0x0d;
        yield* sub_2888();
        memory16set(ds, 0x26f2, 0x0002);
        r16[dx] = 0x03d4;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x20;
        out8(r16[dx], r8[al]);
        memory16set(ds, 0x203e, 0x0080);
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        r16[ax] = 0x00a1;
        di = 0x3a00;
        yield* sub_2c81();
        r16[bx] = 0x34bc;
        yield* sub_23b5();
        r16[ax] = 0x0007;
        yield* sub_8c10();
        r16[cx] = 0x0095;
    case 0x437d:
        push(r16[cx]);
        yield* sub_34f3();
        memory16set(ds, 0x203e, memory16get(ds, 0x203e) + 1);
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_3503();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x437d;
            break;
        }
        r16[cx] = 0x0002;
    case 0x4394:
        push(r16[cx]);
        push(ds);
        di = 0x2a86;
        di += memory16get(ds, 0x0018);
        si = 0xb680;
        r16[ax] = 0x1650;
        ds = r16[ax];
        r16[dx] = 0x000a;
        r16[cx] = 0x0034;
        r16[ax] = 0x0000;
        yield* sub_25ae();
        ds = pop();
        push(ds);
        di = 0x2850;
        di += memory16get(ds, 0x0018);
        si = 0xb6a8;
        r16[ax] = 0x1650;
        ds = r16[ax];
        r16[dx] = 0x000e;
        r16[cx] = 0x0033;
        r16[ax] = 0x0000;
        yield* sub_25ae();
        ds = pop();
        push(ds);
        di = 0x2fd4;
        di += memory16get(ds, 0x0018);
        si = 0xb6e8;
        r16[ax] = 0x1650;
        ds = r16[ax];
        r16[dx] = 0x002a;
        r16[cx] = 0x0022;
        r16[ax] = 0x0000;
        yield* sub_25ae();
        ds = pop();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x4394;
            break;
        }
    case 0x43f8:
        yield* sub_4e4c();
        si = 0x2928;
        yield* sub_4ef1();
        yield* sub_49b3();
        r16[dx] = 0x0004;
        yield* sub_4d17();
        if (memory[ds*16 + 0x0026] == 0x00) {
            pc = 0x441a;
            break;
        }
        memory16set(ds, 0x26fc, 0x0001);
        pc = 0x462c;
        break;
    case 0x441a:
        if (r16[dx] == 0x0000) {
            pc = 0x4432;
            break;
        }
        si = 0x28d6;
        yield* sub_4e81();
        if (memory16get(ds, 0x26fc) != 0x0002) {
            pc = 0x442f;
            break;
        }
        pc = 0x4435;
        break;
    case 0x442f:
        pc = 0x462c;
        break;
    case 0x4432:
        pc = 0x4673;
        break;
    case 0x4435:
        yield* sub_4e4c();
        si = 0x2a24;
        yield* sub_4ef1();
        yield* sub_49b3();
        r16[dx] = 0x0005;
        memory[ds*16 + 0x0027] = 0x00;
        yield* sub_4d17();
        if (r16[dx] == 0x0000) {
            pc = 0x4432;
            break;
        }
        si = 0x28e6;
        yield* sub_4e81();
        if (memory16get(ds, 0x26fc) != 0x0000) {
            pc = 0x44d3;
            break;
        }
        yield* sub_4e4c();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x205d;
        di = 0x3234;
        r16[cx] = 0x0016;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        memory16set(ds, 0x3232, 0x3234);
        si = 0x205d;
        r16[cx] = 0x000b;
    case 0x4480:
        memory16set(ds, si, 0xffff);
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x4480;
            break;
        }
        si = 0x2ac8;
        yield* sub_4ef1();
        r16[cx] = 0x0008;
        yield* sub_5429();
        r16[bx] = 0x205d;
        yield* sub_4c70();
        yield* sub_4e4c();
        si = 0x2af4;
        yield* sub_4ef1();
        r16[cx] = 0x0008;
        yield* sub_5429();
        memory16set(ds, 0x3232, memory16get(ds, 0x3232) + 0x0002);
        r16[bx] = 0x2069;
        yield* sub_4c70();
        yield* sub_4e4c();
        si = 0x2ca6;
        yield* sub_4ef1();
        r16[cx] = 0x0008;
        yield* sub_5429();
        yield* sub_4cd0();
        r16[bx] = 0x205d;
        memory16set(ds, r16[bx] + 10, r16[ax]);
        pc = 0x4435;
        break;
    case 0x44d3:
        if (memory16get(ds, 0x26fc) == 0x0001) {
            pc = 0x44dd;
            break;
        }
        pc = 0x456c;
        break;
    case 0x44dd:
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_4e4c();
        memory[ds*16 + 0x2701] = 0x04;
        memory[ds*16 + 0x2702] = 0x05;
        if (memory[ds*16 + 0x37f9] != 0x00) {
            pc = 0x4505;
            break;
        }
        memory[ds*16 + 0x2701] = 0xff;
    case 0x4505:
        if (memory[ds*16 + 0x37fa] != 0x00) {
            pc = 0x4512;
            break;
        }
        memory[ds*16 + 0x2702] = 0xff;
    case 0x4512:
        r16[bx] = 0x37fc;
        memory[ds*16 + r16[bx]] = 0xff;
        memory[ds*16 + r16[bx] + 1] = 0xff;
        memory[ds*16 + r16[bx] + 2] = 0xff;
        memory[ds*16 + r16[bx] + 3] = 0xff;
        si = 0x2d12;
        yield* sub_4ef1();
        si = 0x2d8e;
        yield* sub_4a5f();
        r16[ax] = memory16get(ds, 0x26fc);
        memory[ds*16 + r16[bx]] = r8[al];
        si = 0x2dba;
        yield* sub_4a5f();
        r16[ax] = memory16get(ds, 0x26fc);
        memory[ds*16 + r16[bx] + 1] = r8[al];
        si = 0x2de6;
        yield* sub_4a5f();
        r16[ax] = memory16get(ds, 0x26fc);
        memory[ds*16 + r16[bx] + 2] = r8[al];
        si = 0x2e12;
        yield* sub_4a5f();
        r16[ax] = memory16get(ds, 0x26fc);
        memory[ds*16 + r16[bx] + 3] = r8[al];
        memory16set(ds, 0x26fc, 0x0000);
        pc = 0x4435;
        break;
    case 0x456c:
        if (memory16get(ds, 0x26fc) == 0x0002) {
            pc = 0x4576;
            break;
        }
        pc = 0x460d;
        break;
    case 0x4576:
        yield* sub_4e4c();
        si = 0x2f25;
        yield* sub_4ef1();
        di = 0x0000;
        si = 0x39c0;
        r16[cx] = 0x2540;
        yield* sub_2922();
        yield* sub_34f3();
        r16[dx] = 0x03d4;
        r8[al] = 0x07;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = in8(r16[dx]);
        r8[al] &= 0xef;
        r16[dx] = 0x03d5;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x09;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = in8(r16[dx]);
        r8[al] &= 0xbf;
        r16[dx] = 0x03d5;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x18;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0xa3;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        r16[dx] = 0x03c0;
        r8[al] = 0x30;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c0;
        r8[al] = 0x61;
        out8(r16[dx], r8[al]);
        yield* sub_49bd();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_34f3();
        r16[dx] = 0x03d4;
        r8[al] = 0x07;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = in8(r16[dx]);
        r8[al] |= 0x10;
        r16[dx] = 0x03d5;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x09;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = in8(r16[dx]);
        r8[al] |= 0x40;
        r16[dx] = 0x03d5;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x18;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0xff;
        out8(r16[dx], r8[al]);
        pc = 0x4435;
        break;
    case 0x460d:
        if (memory16get(ds, 0x26fc) != 0x0003) {
            pc = 0x4629;
            break;
        }
        yield* sub_4e4c();
        si = 0x2fe1;
        yield* sub_4ef1();
        yield* sub_5970();
        r16[cx] = 0x0007;
        yield* sub_5429();
        pc = 0x4435;
        break;
    case 0x4629:
        pc = 0x43f8;
        break;
    case 0x462c:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x34bc;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        if (memory16get(ds, 0x26fc) == 0x0003) {
            pc = 0x469b;
            break;
        }
        if (memory16get(ds, 0x26fc) == 0x0001) {
            pc = 0x467b;
            break;
        }
        if (memory16get(ds, 0x26fc) == 0x0000) {
            pc = 0x4688;
            break;
        }
        memory16set(ds, 0x4f88, 0xffff);
        memory16set(ds, 0x4f8a, 0x0001);
        return;
    case 0x4673:
        memory16set(ds, 0x26fc, 0xffff);
        pc = 0x462c;
        break;
    case 0x467b:
        memory16set(ds, 0x4f88, 0x0000);
        memory16set(ds, 0x4f8a, 0x0001);
        return;
    case 0x4688:
        memory16set(ds, 0x4f88, 0x0001);
        memory16set(ds, 0x4f8a, 0x0001);
        yield* sub_8d8e();
        return;
    case 0x4698:
        pc = 0x4957;
        break;
    case 0x469b:
        r8[al] = 0x2d;
        yield* sub_2888();
        si = 0x30ee;
        yield* sub_4ef1();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x34bc;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x34bc;
        yield* sub_23b5();
        memory16set(ds, 0x26ea, 0x0000);
        memory16set(ds, 0x26ec, 0x0000);
        memory16set(ds, 0x26e8, 0x0000);
        si = 0x32af;
        yield* sub_532b();
        yield* sub_2318();
        si = 0x32af;
        yield* sub_532b();
        yield* sub_2318();
        yield* sub_4999();
    case 0x46ef:
        if (memory[ds*16 + 0x0020] == 0x01) {
            pc = 0x4698;
            break;
        }
        yield* sub_3503();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_34f3();
        yield* sub_281e();
        yield* sub_5476();
        memory[ds*16 + 0x2700] += 1;
        if (r8[al] & 0x1f) {
            pc = 0x4719;
            break;
        }
        memory[ds*16 + 0x2700] = 0x00;
    case 0x4719:
        if (memorys[ds*16 + 0x2700] >= 0) {
            pc = 0x4723;
            break;
        }
        pc = 0x4861;
        break;
    case 0x4723:
        if (!(r8[al] & 0x10)) {
            pc = 0x4795;
            break;
        }
        if (memory16get(ds, 0x26ec) != 0x0002) {
            pc = 0x4743;
            break;
        }
        if (memory16get(ds, 0x26ea) == 0x0008) {
            pc = 0x4798;
            break;
        }
        if (memory16get(ds, 0x26ea) == 0x0007) {
            pc = 0x479b;
            break;
        }
        if (memory16get(ds, 0x26ea) == 0x0006) {
            pc = 0x47b4;
            break;
        }
    case 0x4743:
        push(r16[ax]);
        di = 0x5418;
        r16[ax] = memory16get(ds, 0x26e8);
        r16[ax] += r16[ax];
        di += r16[ax];
        r16[dx] = 0x0002;
        r16[cx] = 0x0008;
        r8[al] = 0x2d;
        yield* sub_2c94();
        yield* sub_497f();
        r16[ax] = memory16get(ds, si + 4);
        si = 0x32b5;
        si += memory16get(ds, 0x26e8);
        memory[ds*16 + si] = r8[al];
        si = 0x32af;
        yield* sub_532b();
        yield* sub_2318();
        si = 0x32af;
        yield* sub_532b();
        yield* sub_2318();
        memory[ds*16 + 0x2700] = 0xf6;
        if (memory16get(ds, 0x26e8) == 0x0007) {
            pc = 0x478e;
            break;
        }
        memory16set(ds, 0x26e8, memory16get(ds, 0x26e8) + 1);
    case 0x478e:
        yield* sub_4999();
        r16[ax] = pop();
        pc = 0x47cd;
        break;
    case 0x4795:
        pc = 0x47cd;
        break;
    case 0x4798:
        pc = 0x48b7;
        break;
    case 0x479b:
        if (memory16get(ds, 0x26e8) == 0x0007) {
            pc = 0x47cd;
            break;
        }
        memory16set(ds, 0x26e8, memory16get(ds, 0x26e8) + 1);
        push(r16[ax]);
        yield* sub_4999();
        r16[ax] = pop();
        memory[ds*16 + 0x2700] = 0xf6;
        pc = 0x47cd;
        break;
    case 0x47b4:
        if (memory16get(ds, 0x26e8) == 0x0000) {
            pc = 0x47cd;
            break;
        }
        memory16set(ds, 0x26e8, memory16get(ds, 0x26e8) - 1);
        push(r16[ax]);
        yield* sub_4999();
        r16[ax] = pop();
        memory[ds*16 + 0x2700] = 0xf6;
        pc = 0x47cd;
        break;
    case 0x47cd:
        if (!(r8[al] & 0x08)) {
            pc = 0x47fc;
            break;
        }
        if (memory16get(ds, 0x26ec) != 0x0002) {
            pc = 0x47e5;
            break;
        }
        if (memory16get(ds, 0x26ea) != 0x0008) {
            pc = 0x47f2;
            break;
        }
        memory16set(ds, 0x26ea, 0xffff);
    case 0x47e5:
        if (memory16get(ds, 0x26ea) != 0x0009) {
            pc = 0x47f2;
            break;
        }
        memory16set(ds, 0x26ea, 0xffff);
    case 0x47f2:
        memory16set(ds, 0x26ea, memory16get(ds, 0x26ea) + 1);
        memory[ds*16 + 0x2700] = 0xf6;
    case 0x47fc:
        if (!(r8[al] & 0x04)) {
            pc = 0x4817;
            break;
        }
        if (memory16get(ds, 0x26ea) != 0x0000) {
            pc = 0x480d;
            break;
        }
        memory16set(ds, 0x26ea, 0x000a);
    case 0x480d:
        memory16set(ds, 0x26ea, memory16get(ds, 0x26ea) - 1);
        memory[ds*16 + 0x2700] = 0xf6;
    case 0x4817:
        if (!(r8[al] & 0x01)) {
            pc = 0x4832;
            break;
        }
        if (memory16get(ds, 0x26ec) != 0x0000) {
            pc = 0x4828;
            break;
        }
        memory16set(ds, 0x26ec, 0x0003);
    case 0x4828:
        memory16set(ds, 0x26ec, memory16get(ds, 0x26ec) - 1);
        memory[ds*16 + 0x2700] = 0xf6;
    case 0x4832:
        if (!(r8[al] & 0x02)) {
            pc = 0x484d;
            break;
        }
        if (memory16get(ds, 0x26ec) != 0x0002) {
            pc = 0x4843;
            break;
        }
        memory16set(ds, 0x26ec, 0xffff);
    case 0x4843:
        memory16set(ds, 0x26ec, memory16get(ds, 0x26ec) + 1);
        memory[ds*16 + 0x2700] = 0xf6;
    case 0x484d:
        if (memory16get(ds, 0x26ec) != 0x0002) {
            pc = 0x4861;
            break;
        }
        if (memory16get(ds, 0x26ea) != 0x0009) {
            pc = 0x4861;
            break;
        }
        memory16set(ds, 0x26ea, 0x0008);
    case 0x4861:
        r16[ax] = memory16get(ds, 0x001c);
        r16[ax] <<= 1;
        r16[ax] &= 0x000c;
        si = 0x315e;
        si += r16[ax];
        di = 0x3222;
        lodsw_data_forward();
        memory16set(ds, di, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, di + 2, r16[ax]);
        yield* sub_497f();
        push(si);
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[cx] = r16[ax];
        r16[cx] -= 0x000a;
        r16[dx] -= 0x0006;
        si = 0x3222;
        yield* sub_2782();
        si = pop();
        di = 0x3252;
        lodsw_data_forward();
        memory16set(ds, di, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, di + 2, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, di + 6, r16[ax]);
        if (r16[ax] != 0x4e45) {
            pc = 0x48ae;
            break;
        }
        memory16set(ds, di, memory16get(ds, di) - 0x0004);
    case 0x48ae:
        si = 0x3252;
        yield* sub_532b();
        pc = 0x46ef;
        break;
    case 0x48b7:
        si = 0x32b5;
        if (memory16get(ds, si) != 0x2020) {
            pc = 0x48e3;
            break;
        }
        if (memory16get(ds, si + 2) != 0x2020) {
            pc = 0x48e3;
            break;
        }
        if (memory16get(ds, si + 4) != 0x2020) {
            pc = 0x48e3;
            break;
        }
        if (memory16get(ds, si + 6) != 0x2020) {
            pc = 0x48e3;
            break;
        }
        r16[ax] = 0x0004;
        yield* sub_8ca1();
        pc = 0x46ef;
        break;
    case 0x48e3:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x32b5;
        di = 0x30e5;
        r16[cx] = 0x0008;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        yield* sub_2cf6();
        if (r16[dx] == 0x0000) {
            pc = 0x4931;
            break;
        }
        memory16set(ds, 0x26e8, 0x0000);
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x32b5;
        r16[cx] = 0x0008;
        r8[al] = 0x20;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x5418;
        r16[dx] = 0x0010;
        r16[cx] = 0x0008;
        r8[al] = 0x2d;
        yield* sub_2c94();
        yield* sub_4999();
        yield* sub_49b3();
        r16[ax] = 0x0004;
        yield* sub_8ca1();
        pc = 0x46ef;
        break;
    case 0x4931:
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x34bc;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        return;
    case 0x4957:
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x34bc;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        pc = 0x4317;
        break;
        return;
    } while (1);
}
function* sub_497f() {
    r16[ax] = memory16get(ds, 0x26ec);
    r16[cx] = 0x003c;
    mul16(r16[cx]);
    push(r16[ax]);
    r16[ax] = memory16get(ds, 0x26ea);
    r16[cx] = 0x0006;
    mul16(r16[cx]);
    si = 0x316e;
    si += r16[ax];
    r16[ax] = pop();
    si += r16[ax];
}
function* sub_4999() {
    di = 0x5698;
    r16[ax] = 0x00c4;
    yield* sub_2c81();
    di = 0x5698;
    r16[ax] = memory16get(ds, 0x26e8);
    r16[ax] += r16[ax];
    di += r16[ax];
    r16[ax] = 0x00c5;
    yield* sub_2c81();
}
function* sub_49b3() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x49b3:
        yield* sync();
        yield* sub_5476();
        r8[al] &= 0x10;
        if (r8[al] != 0x00) {
            pc = 0x49b3;
            break;
        }
        return;
    } while (1);
}
function* sub_49bd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x2166;
    case 0x49c0:
        lodsw_data_forward();
        if (r16[ax] != 0xffff) {
            pc = 0x49ca;
            break;
        }
        si = 0x2166;
        lodsw_data_forward();
    case 0x49ca:
        push(si);
        push(r16[ax]);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[bx] = 0x2540;
        r16[bx] += r16[ax];
        r16[dx] = 0x03d4;
        r8[al] = 0x0c;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = r8[bh];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d4;
        r8[al] = 0x0d;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = r8[bl];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        r16[dx] = 0x03c0;
        r8[al] = 0x33;
        out8(r16[dx], r8[al]);
        r16[ax] = pop();
        r16[ax] &= 0x0003;
        if (memory[ds*16 + 0x0024] == 0x01) {
            pc = 0x4a04;
            break;
        }
        r8[al] += r8[al];
    case 0x4a04:
        r16[dx] = 0x03c0;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        yield* sub_34f3();
        yield* sub_3503();
        yield* sub_5476();
        r8[ah] = r8[al];
        r8[ah] &= 0x0f;
        if (r8[ah] == 0x00) {
            pc = 0x4a35;
            break;
        }
        if (memory[ds*16 + 0x2700] == 0xff) {
            pc = 0x4a3b;
            break;
        }
        memory[ds*16 + 0x0024] = memory[ds*16 + 0x0024] ^ 0x01;
        memory[ds*16 + 0x2700] = 0xff;
        pc = 0x4a3b;
        break;
    case 0x4a35:
        memory[ds*16 + 0x2700] = 0x00;
    case 0x4a3b:
        yield* sub_544d();
        si = pop();
        if (r16[dx] != 0x0000) {
            pc = 0x4a47;
            break;
        }
        pc = 0x49c0;
        break;
    case 0x4a47:
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        r16[dx] = 0x03c0;
        r8[al] = 0x33;
        out8(r16[dx], r8[al]);
        r16[ax] = 0x0000;
        r16[dx] = 0x03c0;
        r8[al] = r8[al];
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03da;
        r8[al] = in8(r16[dx]);
        return;
    } while (1);
}
function* sub_4a5f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        r16[ax] = memory16get(ds, si + 2);
        push(r16[ax]);
        yield* sub_4ef1();
        r16[ax] = pop();
        r16[dx] = r16[ax];
        r16[dx] -= 0x0001;
        si = 0x2e3e;
        di = memory16get(ds, si);
        memory16set(ds, di + 2, r16[ax]);
        memory16set(ds, di + 19, r16[dx]);
        di = memory16get(ds, si + 2);
        memory16set(ds, di + 2, r16[ax]);
        memory16set(ds, di + 19, r16[dx]);
        di = memory16get(ds, si + 4);
        memory16set(ds, di + 2, r16[ax]);
        memory16set(ds, di + 19, r16[dx]);
        di = memory16get(ds, si + 6);
        memory16set(ds, di + 2, r16[ax]);
        memory16set(ds, di + 19, r16[dx]);
        di = memory16get(ds, si + 8);
        memory16set(ds, di + 2, r16[ax]);
        memory16set(ds, di + 19, r16[dx]);
        di = memory16get(ds, si + 10);
        memory16set(ds, di + 2, r16[ax]);
        memory16set(ds, di + 19, r16[dx]);
    case 0x4ab9:
        yield* sub_5476();
        r8[al] &= 0x1f;
        if (r8[al] != 0x00) {
            pc = 0x4ab9;
            break;
        }
        yield* sub_4ac7();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_4ac7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x26fc, 0x0000);
        r16[ax] = 0x0009;
        pc = 0x4b42;
        break;
    case 0x4ad3:
        yield* sub_281e();
        si = 0x2e3e;
        r16[ax] = memory16get(ds, 0x26fc);
        if (r16[ax] <= 0x0005) {
            pc = 0x4ae9;
            break;
        }
        if (r16s[ax] >= 0) {
            pc = 0x4ae9;
            break;
        }
        r16[ax] = 0x0006;
    case 0x4ae9:
        r16[ax] += r16[ax];
        si += r16[ax];
        si = memory16get(ds, si);
        push(si);
        r16[ax] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx]--;
        yield* sub_584c();
        di += memory16get(ds, 0x0018);
        si = di;
        r16[ax] = 0x25f0;
        es = r16[ax];
        di = 0x1400;
        r16[dx] = 0x0016;
        r16[cx] = 0x0009;
        yield* sub_27d4();
        si = pop();
        push(r16[bx]);
        yield* sub_532b();
        r16[bx] = pop();
        yield* sub_34f3();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
    case 0x4b27:
        yield* sub_5476();
        if (r8[al] & 0x10) {
            pc = 0x4b7b;
            break;
        }
        if (memory[ds*16 + 0x2700] != 0x00) {
            pc = 0x4b78;
            break;
        }
        if (!(r8[al] & 0x08)) {
            pc = 0x4b7e;
            break;
        }
        memory[ds*16 + 0x2700] = 0xff;
        r16[ax] = memory16get(ds, 0x26fc);
    case 0x4b42:
        r16[ax]++;
        if (r16[ax] < 0x0006) {
            pc = 0x4b4b;
            break;
        }
        r16[ax] = 0x0000;
    case 0x4b4b:
        r16[bx] = 0x37fc;
        if (memory[ds*16 + r16[bx]] == r8[al]) {
            pc = 0x4b42;
            break;
        }
        if (memory[ds*16 + r16[bx] + 1] == r8[al]) {
            pc = 0x4b42;
            break;
        }
        if (memory[ds*16 + r16[bx] + 2] == r8[al]) {
            pc = 0x4b42;
            break;
        }
        if (memory[ds*16 + r16[bx] + 3] == r8[al]) {
            pc = 0x4b42;
            break;
        }
        if (memory[ds*16 + 0x2701] == r8[al]) {
            pc = 0x4b42;
            break;
        }
        if (memory[ds*16 + 0x2702] == r8[al]) {
            pc = 0x4b42;
            break;
        }
        memory16set(ds, 0x26fc, r16[ax]);
        pc = 0x4ad3;
        break;
    case 0x4b78:
        pc = 0x4bc4;
        break;
    case 0x4b7b:
        pc = 0x4bd3;
        break;
    case 0x4b7e:
        if (!(r8[al] & 0x04)) {
            pc = 0x4bc1;
            break;
        }
        memory[ds*16 + 0x2700] = 0xff;
        r16[ax] = memory16get(ds, 0x26fc);
    case 0x4b8b:
        r16[ax]--;
        if (r16s[ax] >= 0) {
            pc = 0x4b94;
            break;
        }
        r16[ax] = 0x0005;
    case 0x4b94:
        r16[bx] = 0x37fc;
        if (memory[ds*16 + r16[bx]] == r8[al]) {
            pc = 0x4b8b;
            break;
        }
        if (memory[ds*16 + r16[bx] + 1] == r8[al]) {
            pc = 0x4b8b;
            break;
        }
        if (memory[ds*16 + r16[bx] + 2] == r8[al]) {
            pc = 0x4b8b;
            break;
        }
        if (memory[ds*16 + r16[bx] + 3] == r8[al]) {
            pc = 0x4b8b;
            break;
        }
        if (memory[ds*16 + 0x2701] == r8[al]) {
            pc = 0x4b8b;
            break;
        }
        if (memory[ds*16 + 0x2702] == r8[al]) {
            pc = 0x4b8b;
            break;
        }
        memory16set(ds, 0x26fc, r16[ax]);
        pc = 0x4ad3;
        break;
    case 0x4bc1:
        pc = 0x4b27;
        break;
    case 0x4bc4:
        r8[al] &= 0x0c;
        if (r8[al] != 0x00) {
            pc = 0x4bd0;
            break;
        }
        memory[ds*16 + 0x2700] = 0x00;
    case 0x4bd0:
        pc = 0x4b27;
        break;
    case 0x4bd3:
        yield* sub_281e();
        yield* sub_2801();
        yield* sub_2318();
        si = 0x2e3e;
        r16[ax] = memory16get(ds, 0x26fc);
        r16[ax] += r16[ax];
        si += r16[ax];
        si = memory16get(ds, si);
        yield* sub_4ef1();
        return;
    } while (1);
}
function* sub_4bee() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        r16[ax] = ds;
        es = r16[ax];
        r16[dx] = di;
        di += 0x0016;
        r8[al] = 0x20;
        r16[cx] = 0x0007;
        rep_stosb_data_forward();
        di = r16[dx];
        di += 0x003d;
        r16[cx] = 0x0007;
        rep_stosb_data_forward();
        r16[bx] = memory16get(ds, 0x3232);
        r8[al] = memory[ds*16 + r16[bx] + 1];
        memory16set(ds, 0x3232, memory16get(ds, 0x3232) + 0x0002);
        si = 0x32c4;
    case 0x4c19:
        if (memory[ds*16 + si] == r8[al]) {
            pc = 0x4c2c;
            break;
        }
        if (memory[ds*16 + si] == 0xff) {
            pc = 0x4c43;
            break;
        }
        si += 0x0008;
        pc = 0x4c19;
        break;
    case 0x4c2c:
        si++;
        push(si);
        di = r16[dx];
        di += 0x001e;
        r16[cx] = 0x0007;
        rep_movsb_data_data_forward();
        si = pop();
        di = r16[dx];
        di += 0x0045;
        r16[cx] = 0x0007;
        rep_movsb_data_data_forward();
    case 0x4c43:
        si = r16[dx];
        yield* sub_4ef1();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_4c4a() {
    r16[dx] = di;
    r16[ax] = ds;
    es = r16[ax];
    si = memory16get(ds, 0x26e6);
    di += 0x0016;
    r16[cx] = 0x0007;
    rep_movsb_data_data_forward();
    di = r16[dx];
    si = memory16get(ds, 0x26e6);
    di += 0x003d;
    r16[cx] = 0x0007;
    rep_movsb_data_data_forward();
    si = r16[dx];
    yield* sub_4ef1();
}
function* sub_4c70() {
    di = 0x2b20;
    yield* sub_4bee();
    yield* sub_4cd0();
    memory16set(ds, r16[bx], r16[ax]);
    di = 0x2b20;
    yield* sub_4c4a();
    di = 0x2b6e;
    yield* sub_4bee();
    yield* sub_4cd0();
    memory16set(ds, r16[bx] + 2, r16[ax]);
    di = 0x2b6e;
    yield* sub_4c4a();
    di = 0x2bbc;
    yield* sub_4bee();
    yield* sub_4cd0();
    memory16set(ds, r16[bx] + 4, r16[ax]);
    di = 0x2bbc;
    yield* sub_4c4a();
    di = 0x2c0a;
    yield* sub_4bee();
    yield* sub_4cd0();
    memory16set(ds, r16[bx] + 6, r16[ax]);
    di = 0x2c0a;
    yield* sub_4c4a();
    di = 0x2c58;
    yield* sub_4bee();
    yield* sub_4cd0();
    memory16set(ds, r16[bx] + 8, r16[ax]);
    di = 0x2c58;
    yield* sub_4c4a();
}
function* sub_4cd0() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x4cd0:
        memory[ds*16 + 0x0020] = 0xff;
    case 0x4cd5:
        r8[al] = memory[ds*16 + 0x0020];
        if (r8s[al] < 0) {
            pc = 0x4cd5;
            break;
        }
        if (r8[al] == 0x2a) {
            pc = 0x4cd5;
            break;
        }
        si = 0x205e;
        r16[cx] = 0x000b;
    case 0x4ce6:
        if (memory[ds*16 + si] == r8[al]) {
            pc = 0x4cd0;
            break;
        }
        si += 0x0002;
        if (--r16[cx]) {
            pc = 0x4ce6;
            break;
        }
        si = 0x32c4;
    case 0x4cf4:
        if (memory[ds*16 + si] == r8[al]) {
            pc = 0x4d07;
            break;
        }
        if (memory[ds*16 + si] == 0xff) {
            pc = 0x4cd0;
            break;
        }
        si += 0x0008;
        pc = 0x4cf4;
        break;
    case 0x4d07:
        si++;
        memory16set(ds, 0x26e6, si);
        r8[ah] = r8[al];
        r8[al] += 0x80;
    case 0x4d10:
        yield* sync();
        if (memory[ds*16 + 0x0020] != r8[al]) {
            pc = 0x4d10;
            break;
        }
        return;
    } while (1);
}
function* sub_4d17() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx]--;
        memory16set(ds, 0x26fe, r16[dx]);
        memory16set(ds, 0x26fc, 0x0000);
        memory[ds*16 + 0x0020] = 0x00;
        memory16set(ds, 0x26e4, 0x0000);
    case 0x4d2d:
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_34f3();
        yield* sub_281e();
        if (memory[ds*16 + 0x0020] == 0x01) {
            pc = 0x4dad;
            break;
        }
        yield* sub_5476();
        if (memory16get(ds, 0x37e4) == 0xffff) {
            pc = 0x4d77;
            break;
        }
        if (memory[ds*16 + 0x0020] != 0x48) {
            pc = 0x4d5b;
            break;
        }
        r8[al] |= 0x01;
        memory[ds*16 + 0x0020] = 0x00;
    case 0x4d5b:
        if (memory[ds*16 + 0x0020] != 0x50) {
            pc = 0x4d69;
            break;
        }
        r8[al] |= 0x02;
        memory[ds*16 + 0x0020] = 0x00;
    case 0x4d69:
        if (memory[ds*16 + 0x0020] != 0x1c) {
            pc = 0x4d77;
            break;
        }
        r8[al] |= 0x10;
        memory[ds*16 + 0x0020] = 0x00;
    case 0x4d77:
        r8[ah] = r8[al];
        r8[al] &= 0x10;
        if (r8[al] != 0) {
            pc = 0x4db6;
            break;
        }
        r8[al] = r8[ah];
        r8[al] &= 0x03;
        if (r8[al] == 0) {
            pc = 0x4db9;
            break;
        }
        memory16set(ds, 0x26e4, 0x0000);
        if (memory[ds*16 + 0x2700] != 0x00) {
            pc = 0x4dfc;
            break;
        }
        r8[al] = r8[ah];
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x4dda;
            break;
        }
        memory[ds*16 + 0x2700] = 0xff;
        if (memory16get(ds, 0x26fc) != 0x0000) {
            pc = 0x4db0;
            break;
        }
        r16[dx] = memory16get(ds, 0x26fe);
        memory16set(ds, 0x26fc, r16[dx]);
        pc = 0x4dfc;
        break;
    case 0x4dad:
        pc = 0x4e42;
        break;
    case 0x4db0:
        memory16set(ds, 0x26fc, memory16get(ds, 0x26fc) - 1);
        pc = 0x4dfc;
        break;
    case 0x4db6:
        pc = 0x4e38;
        break;
    case 0x4db9:
        memory[ds*16 + 0x2700] = 0x00;
        if (memory[ds*16 + 0x0027] == 0x00) {
            pc = 0x4dfc;
            break;
        }
        memory16set(ds, 0x26e4, memory16get(ds, 0x26e4) + 1);
        if (memory16get(ds, 0x26e4) < 0x021c) {
            pc = 0x4dfc;
            break;
        }
        memory[ds*16 + 0x0026] = 0xff;
        pc = 0x4e42;
        break;
    case 0x4dda:
        r8[al] = r8[ah];
        r8[al] &= 0x02;
        if (r8[al] == 0) {
            pc = 0x4dfc;
            break;
        }
        memory[ds*16 + 0x2700] = 0xff;
        r16[dx] = memory16get(ds, 0x26fe);
        if (memory16get(ds, 0x26fc) != r16[dx]) {
            pc = 0x4df8;
            break;
        }
        memory16set(ds, 0x26fc, 0x0000);
        pc = 0x4dfc;
        break;
    case 0x4df8:
        memory16set(ds, 0x26fc, memory16get(ds, 0x26fc) + 1);
    case 0x4dfc:
        si = 0x28d6;
        if (memory16get(ds, 0x26fe) != 0x0004) {
            pc = 0x4e09;
            break;
        }
        si = 0x28e6;
    case 0x4e09:
        if (memory16get(ds, 0x26fe) != 0x0001) {
            pc = 0x4e13;
            break;
        }
        si = 0x324a;
    case 0x4e13:
        if (memory16get(ds, 0x26fe) != 0x0000) {
            pc = 0x4e1d;
            break;
        }
        si = 0x324e;
    case 0x4e1d:
        r16[ax] = memory16get(ds, 0x26fc);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[cx] = r16[ax];
        si = 0x28fa;
        yield* sub_2782();
        yield* sub_350c();
        pc = 0x4d2d;
        break;
    case 0x4e38:
        memory16set(ds, 0x26e4, 0x0000);
        r16[dx] = 0xffff;
        return;
    case 0x4e42:
        memory16set(ds, 0x26e4, 0x0000);
        r16[dx] = 0x0000;
        return;
    } while (1);
}
function* sub_4e4c() {
    si = 0x1900;
    di = 0x3f00;
    push(ds);
    di += memory16get(ds, 0x0018);
    r16[ax] = 0x1650;
    ds = r16[ax];
    r16[dx] = 0x0040;
    r16[cx] = 0x0060;
    yield* sub_24dc();
    ds = pop();
    si = 0x1900;
    di = 0x3f00;
    push(ds);
    di += memory16get(ds, 0x001a);
    r16[ax] = 0x1650;
    ds = r16[ax];
    r16[dx] = 0x0040;
    r16[cx] = 0x0060;
    yield* sub_24dc();
    ds = pop();
}
function* sub_4e81() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        r16[ax] = memory16get(ds, 0x26fc);
        si += 0x0002;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        r16[bx] = r16[ax];
        r16[cx] = 0x0040;
        mul16(r16[cx]);
        di = r16[ax];
        r16[ax] = r16[bx];
        r16[ax] -= 0x00e8;
        r16[cx] = 0x0140;
        mul16(r16[cx]);
        si = r16[ax];
        push(ds);
        di += memory16get(ds, 0x0018);
        r16[ax] = 0x1650;
        ds = r16[ax];
        r16[dx] = 0x0040;
        r16[cx] = 0x0008;
        yield* sub_24dc();
        ds = pop();
        si = pop();
        r16[cx] = 0x0008;
    case 0x4ebc:
        push(r16[cx]);
        push(si);
        yield* sub_34f3();
        yield* sub_281e();
        r16[ax] = memory16get(ds, 0x26fc);
        si = pop();
        push(si);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[cx] = r16[ax];
        si = 0x28fa;
        yield* sub_2782();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        r16[cx] = 0x0005;
    case 0x4ee7:
        yield* sub_350c();
        if (--r16[cx]) {
            pc = 0x4ee7;
            break;
        }
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x4ebc;
            break;
        }
        return;
    } while (1);
}
function* sub_4ef1() {
    push(r16[bx]);
    push(si);
    yield* sub_2318();
    r16[ax] = memory16get(ds, 0x001a);
    yield* sub_305b();
    yield* sub_34f3();
    yield* sub_532b();
    yield* sub_2318();
    r16[ax] = memory16get(ds, 0x001a);
    yield* sub_305b();
    yield* sub_34f3();
    si = pop();
    yield* sub_532b();
    r16[bx] = pop();
}
function* sub_4f14() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x4f2f;
            break;
        }
        memory16set(ds, 0x203e, 0x0080);
        r16[bx] = memory16get(ds, 0x4f78);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, 0x26f2, r16[ax]);
        pc = 0x4f35;
        break;
    case 0x4f2f:
        memory16set(ds, 0x26f2, 0x0000);
    case 0x4f35:
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x4f4a;
            break;
        }
        r16[dx] = 0x03d4;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x40;
        out8(r16[dx], r8[al]);
        pc = 0x4f56;
        break;
    case 0x4f4a:
        r16[dx] = 0x03d4;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x20;
        out8(r16[dx], r8[al]);
    case 0x4f56:
        if (memory16get(ds, 0x26f2) != 0x0000) {
            pc = 0x4f6a;
            break;
        }
        memory16set(ds, 0x26f4, 0x000f);
        memory16set(ds, 0x26f6, 0x000d);
        return;
    case 0x4f6a:
        if (memory16get(ds, 0x26f2) != 0x0001) {
            pc = 0x4f7e;
            break;
        }
        memory16set(ds, 0x26f4, 0x001f);
        memory16set(ds, 0x26f6, 0x000d);
        return;
    case 0x4f7e:
        memory16set(ds, 0x26f4, 0x000f);
        memory16set(ds, 0x26f6, 0x001d);
        return;
    } while (1);
}
function* sub_4f8b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x271c;
        r16[ax] = memory16get(ds, 0x4f88);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        memory16set(ds, 0x26f8, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, 0x26fa, r16[ax]);
        si = 0x0726;
        di = 0x0c02;
        if (memory16get(ds, 0x26f2) != 0x0002) {
            pc = 0x4faf;
            break;
        }
        di = 0x0602;
    case 0x4faf:
        r16[cx] = memory16get(ds, 0x26f6);
    case 0x4fb3:
        push(r16[cx]);
        push(di);
        r16[cx] = memory16get(ds, 0x26f4);
    case 0x4fb9:
        push(r16[cx]);
        lodsb_data_forward();
        r8[ah] = r8[al];
        push(si);
        si = memory16get(ds, 0x26f8);
        r16[bx] = 0xfffe;
    case 0x4fc5:
        r16[bx] += 0x0002;
        lodsb_data_forward();
        if (r8[al] == 0xff) {
            pc = 0x4fd1;
            break;
        }
        if (r8[ah] != r8[al]) {
            pc = 0x4fc5;
            break;
        }
    case 0x4fd1:
        si = memory16get(ds, 0x26fa);
        si += r16[bx];
        lodsw_data_forward();
        yield* sub_4ffe();
        push(di);
        yield* sub_2c81();
        di = pop();
        di += 0x0004;
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x4fb9;
            break;
        }
        di = pop();
        r16[cx] = pop();
        di += 0x0400;
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x4ff8;
            break;
        }
        di += 0x0400;
    case 0x4ff8:
        if (--r16[cx]) {
            pc = 0x4fb3;
            break;
        }
        yield* sub_504e();
        return;
    } while (1);
}
function* sub_4ffe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x4f88) == 0x0000)
            return;
        if (r16[ax] == 0x0000) {
            pc = 0x500f;
            break;
        }
        if (r16[ax] != 0x0069)
            return;
    case 0x500f:
        push(r16[dx]);
        push(r16[cx]);
        r16[dx] = di;
        if (memory16get(ds, 0x26f2) != 0x0002) {
            pc = 0x5023;
            break;
        }
        r16[dx] -= 0x0602;
        push(r16[dx]);
        r8[cl] = 0x0a;
        pc = 0x502a;
        break;
    case 0x5023:
        r16[dx] -= 0x0c02;
        push(r16[dx]);
        r8[cl] = 0x0b;
    case 0x502a:
        r16[dx] >>= r8[cl];
        if (r16[dx] == 0x0001) {
            pc = 0x504a;
            break;
        }
        r16[dx] &= 0x0001;
        if (r16[dx] == 0x0000) {
            pc = 0x504a;
            break;
        }
        r16[dx] = pop();
        push(r16[dx]);
        r8[cl] = 0x02;
        r16[dx] >>= r8[cl];
        r16[dx] &= 0x0001;
        if (r16[dx] != 0x0000) {
            pc = 0x504a;
            break;
        }
        r16[ax] = 0x006a;
    case 0x504a:
        r16[dx] = pop();
        r16[cx] = pop();
        r16[dx] = pop();
        return;
    } while (1);
}
function* sub_504e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x4f88) != 0x0000) {
            pc = 0x5068;
            break;
        }
        di = 0x0c00;
        r16[ax] = 0x000f;
        yield* sub_50ca();
        di = 0x0c3e;
        r16[ax] = 0x0010;
        yield* sub_50ca();
        return;
    case 0x5068:
        if (memory16get(ds, 0x26f2) == 0x0001) {
            pc = 0x5092;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x50ae;
            break;
        }
        di = 0x0c00;
        r16[ax] = 0x0083;
        yield* sub_50ca();
        di = 0x0c3e;
        r16[ax] = 0x007c;
        yield* sub_50ca();
        si = 0x290a;
        r16[cx] = 0x0002;
        yield* sub_2ce0();
        return;
    case 0x5092:
        di = 0x0c00;
        r16[ax] = 0x0083;
        yield* sub_50ca();
        di = 0x0c7e;
        r16[ax] = 0x007c;
        yield* sub_50ca();
        si = 0x2914;
        r16[cx] = 0x0002;
        yield* sub_2ce0();
        return;
    case 0x50ae:
        di = 0x0600;
        r16[ax] = 0x0083;
        yield* sub_50ca();
        di = 0x063e;
        r16[ax] = 0x007c;
        yield* sub_50ca();
        si = 0x291e;
        r16[cx] = 0x0002;
        yield* sub_2ce0();
        return;
    } while (1);
}
function* sub_50ca() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = memory16get(ds, 0x26f6);
    case 0x50ce:
        push(r16[cx]);
        push(di);
        push(r16[ax]);
        yield* sub_2c81();
        r16[ax] = pop();
        di = pop();
        r16[cx] = pop();
        di += 0x0400;
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x50e6;
            break;
        }
        di += 0x0400;
    case 0x50e6:
        if (--r16[cx]) {
            pc = 0x50ce;
            break;
        }
        return;
    } while (1);
}
function* sub_50e9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x4f88) != 0x0000) {
            pc = 0x5139;
            break;
        }
        si = 0x2704;
        r16[ax] = memory16get(ds, 0x0010);
        r16[ax] -= 0x0002;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        r16[cx] = r16[ax];
        push(si);
        r8[dl] = 0x2e;
        r8[dh] = 0x41;
        yield* sub_518d();
        si = pop();
        lodsw_data_forward();
        r16[cx] = r16[ax];
        push(si);
        r8[dl] = 0x42;
        r8[dh] = 0x41;
        yield* sub_518d();
        si = pop();
        lodsw_data_forward();
        r16[cx] = r16[ax];
        push(si);
        r8[dl] = 0x43;
        r8[dh] = 0x41;
        yield* sub_518d();
        si = pop();
        lodsw_data_forward();
        r16[cx] = r16[ax];
        push(si);
        if (memory16get(ds, 0x0012) == 0x0000) {
            pc = 0x5137;
            break;
        }
        r8[dl] = 0x44;
        r8[dh] = 0x41;
        yield* sub_518d();
    case 0x5137:
        si = pop();
        return;
    case 0x5139:
        r16[bx] = memory16get(ds, 0x26f2);
        r16[bx] += r16[bx];
        si = 0x34b6;
        r16[ax] = memory16get(ds, r16[bx] + si);
        r16[bx] = memory16get(ds, 0x4f78);
        r16[cx] = memory16get(ds, r16[bx] + 2);
        r16[ax] -= r16[cx];
        memory16set(ds, 0x4f6e, r16[ax]);
        r16[dx] = 0x452e;
        yield* sub_518d();
        memory16set(ds, 0x4f92, 0x0000);
        r16[cx] = 0x0001;
        r16[bx] = memory16get(ds, 0x4f78);
        r16[dx] = memory16get(ds, r16[bx] + 4);
        if (r16[dx] == 0xffff) {
            pc = 0x5177;
            break;
        }
        r8[dh] = 0x45;
        yield* sub_518d();
        memory16set(ds, 0x4f92, r16[ax]);
    case 0x5177:
        r16[cx] = 0x0001;
        r16[bx] = memory16get(ds, 0x4f78);
        r16[dx] = memory16get(ds, r16[bx] + 6);
        if (r16[dx] == 0xffff)
            return;
        r8[dh] = 0x45;
        yield* sub_518d();
        return;
    } while (1);
}
function* sub_518d() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x518d:
        push(r16[cx]);
        push(r16[dx]);
    case 0x518f:
        push(r16[dx]);
        r16[ax] = memory16get(ds, 0x26f6);
        r16[ax]++;
        yield* sub_587c();
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x26f4);
        r16[ax]++;
        yield* sub_587c();
        r16[dx] = pop();
        r8[ah] = r8[dl];
        r16[bx] = r16[ax];
        yield* sub_5832();
        r16[dx] = pop();
        if (r8[al] != r8[dh]) {
            pc = 0x518f;
            break;
        }
        r16[ax] = r16[bx];
        r16[dx] = pop();
        yield* sub_57b4();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x518d;
            break;
        }
        return;
    } while (1);
}
function* sub_51b6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x37f9] = 0xff;
        memory[ds*16 + 0x37fa] = 0xff;
        r8[ah] = 0x84;
        r16[dx] = 0x0001;
        interrupt(0x15);
        if (flags.carry)
            return;
        if (r16[ax] == 0x0000) {
            pc = 0x51e4;
            break;
        }
        memory[ds*16 + 0x37f9] = 0x00;
        r16[ax] &= 0x00ff;
        r16[cx] &= 0x00ff;
        memory16set(ds, 0x37bc, r16[ax]);
        memory16set(ds, 0x37be, r16[bx]);
    case 0x51e4:
        if (r16[cx] == 0x0000)
            return;
        memory[ds*16 + 0x37fa] = 0x00;
        r16[ax] &= 0x00ff;
        r16[cx] &= 0x00ff;
        memory16set(ds, 0x37c0, r16[cx]);
        memory16set(ds, 0x37c2, r16[dx]);
        return;
    } while (1);
}
function* sub_51ff() {
    yield* sub_521e();
    yield* sub_5264();
    yield* sub_52aa();
    yield* sub_5300();
    yield* sub_2318();
    yield* sub_521e();
    yield* sub_5264();
    yield* sub_52aa();
    yield* sub_5300();
    yield* sub_2318();
}
function* sub_521e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) == 0x0000) {
            pc = 0x523b;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0001) {
            pc = 0x5236;
            break;
        }
        di = memory16get(ds, 0x0018);
        di += 0x0248;
        pc = 0x5242;
        break;
    case 0x5236:
        di = 0xfc48;
        pc = 0x5242;
        break;
    case 0x523b:
        di = 0x0488;
        di += memory16get(ds, 0x0018);
    case 0x5242:
        r16[ax] = memory16get(ds, 0x3a50);
        if (r16[ax] == 0x0000) {
            pc = 0x525a;
            break;
        }
        yield* sub_5718();
        r16[ax] = 0x0000;
        yield* sub_573d();
        di += 0x0002;
        yield* sub_573d();
        return;
    case 0x525a:
        di += 0x000c;
        r16[ax] = 0x0000;
        yield* sub_573d();
        return;
    } while (1);
}
function* sub_5264() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) == 0x0000) {
            pc = 0x5281;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0001) {
            pc = 0x527c;
            break;
        }
        di = memory16get(ds, 0x0018);
        di += 0x0270;
        pc = 0x5288;
        break;
    case 0x527c:
        di = 0xfc70;
        pc = 0x5288;
        break;
    case 0x5281:
        di = 0x04b0;
        di += memory16get(ds, 0x0018);
    case 0x5288:
        r16[ax] = memory16get(ds, 0x4f90);
        if (r16[ax] == 0x0000) {
            pc = 0x52a0;
            break;
        }
        yield* sub_5718();
        r16[ax] = 0x0000;
        yield* sub_573d();
        di += 0x0002;
        yield* sub_573d();
        return;
    case 0x52a0:
        di += 0x000c;
        r16[ax] = 0x0000;
        yield* sub_573d();
        return;
    } while (1);
}
function* sub_52aa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) == 0x0000) {
            pc = 0x52c7;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0001) {
            pc = 0x52c2;
            break;
        }
        di = memory16get(ds, 0x0018);
        di += 0x025a;
        pc = 0x52ce;
        break;
    case 0x52c2:
        di = 0xfc5a;
        pc = 0x52ce;
        break;
    case 0x52c7:
        di = 0x049a;
        di += memory16get(ds, 0x0018);
    case 0x52ce:
        push(di);
        si = 0x37d4;
        r16[ax] = memory16get(ds, 0x37ce);
        yield* sub_57ae();
        r16[ax] = memory16get(ds, 0x37d4);
        di = pop();
        push(di);
        yield* sub_573d();
        si = 0x37d4;
        r16[ax] = memory16get(ds, 0x37d0);
        yield* sub_579c();
        r16[ax] = memory16get(ds, 0x37d4);
        di = pop();
        di += 0x0004;
        push(di);
        yield* sub_573d();
        r16[ax] = memory16get(ds, 0x37d5);
        di = pop();
        di += 0x0002;
        yield* sub_573d();
        return;
    } while (1);
}
function* sub_5300() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) == 0x0000) {
            pc = 0x531d;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0001) {
            pc = 0x5318;
            break;
        }
        di = memory16get(ds, 0x0018);
        di += 0x0266;
        pc = 0x5324;
        break;
    case 0x5318:
        di = 0xfc66;
        pc = 0x5324;
        break;
    case 0x531d:
        di = 0x04a6;
        di += memory16get(ds, 0x0018);
    case 0x5324:
        r16[ax] = memory16get(ds, 0x4f8c);
        yield* sub_573d();
        return;
    } while (1);
}
function* sub_532b() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x532b:
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r16[cx] = r16[ax];
        r16[ax] = r16[dx];
        yield* sub_584c();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        r8[dh] = r8[al];
        memory16set(ds, 0x37d2, r16[dx]);
    case 0x533f:
        lodsb_data_forward();
        if (r8[al] == 0xff) {
            pc = 0x53a5;
            break;
        }
        if (r8[al] == 0x00) {
            pc = 0x532b;
            break;
        }
        r8[ah] = r8[al];
        push(si);
        si = 0x383a;
        r16[bx] = 0x0000;
    case 0x5351:
        lodsb_data_forward();
        if (r8[al] == r8[ah]) {
            pc = 0x535b;
            break;
        }
        r16[bx] += 0x0002;
        pc = 0x5351;
        break;
    case 0x535b:
        r16[bx] += 0x3865;
        push(ds);
        push(di);
        r16[ax] = memory16get(ds, 0x37d2);
        di += memory16get(ds, 0x0018);
        si = memory16get(ds, r16[bx]);
        si += memory16get(ds, 0x37c6);
        r16[dx] = memory16get(ds, 0x37c8);
        if (memory16get(ds, 0x26f2) != 0x0002) {
            pc = 0x53a6;
            break;
        }
        ds = r16[dx];
        push(si);
        push(di);
        push(r16[ax]);
        r8[bl] = r8[ah];
        r16[dx] = 0x0001;
        r16[cx] = 0x0007;
        yield* sub_2952();
        r16[ax] = pop();
        di = pop();
        si = pop();
        di++;
        r8[bl] = r8[ah];
        si += 0x0004;
        r16[dx] = 0x0001;
        r16[cx] = 0x0007;
        yield* sub_2952();
        di = pop();
        ds = pop();
        si = pop();
        di += 0x0002;
        pc = 0x533f;
        break;
    case 0x53a5:
        return;
    case 0x53a6:
        ds = r16[dx];
        push(si);
        push(di);
        push(r16[ax]);
        r8[bl] = r8[ah];
        r16[dx] = 0x0001;
        r16[cx] = 0x0007;
        yield* sub_29dc();
        r16[ax] = pop();
        di = pop();
        si = pop();
        di++;
        r8[bl] = r8[ah];
        si += 0x0004;
        r16[dx] = 0x0001;
        r16[cx] = 0x0007;
        yield* sub_29dc();
        di = pop();
        ds = pop();
        si = pop();
        di += 0x0002;
        pc = 0x533f;
        break;
        return;
    } while (1);
}
function* sub_53d1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        lodsw_data_forward();
        di = r16[ax];
    case 0x53d4:
        lodsb_data_forward();
        if (r8[al] == 0xff)
            return;
        r8[ah] = r8[al];
        push(si);
        si = 0x383a;
        r16[bx] = 0x0000;
    case 0x53e2:
        lodsb_data_forward();
        if (r8[al] == r8[ah]) {
            pc = 0x53ec;
            break;
        }
        r16[bx] += 0x0002;
        pc = 0x53e2;
        break;
    case 0x53ec:
        r16[bx] += 0x3865;
        push(ds);
        push(di);
        di += memory16get(ds, 0x0018);
        r16[ax] = memory16get(ds, 0x001a);
        push(r16[ax]);
        si = memory16get(ds, r16[bx]);
        si += 0xc808;
        r16[ax] = 0x335d;
        ds = r16[ax];
        push(si);
        r16[dx] = 0x0002;
        r16[cx] = 0x0007;
        yield* sub_2499();
        si = pop();
        r16[ax] = pop();
        di = pop();
        push(di);
        di += r16[ax];
        r16[dx] = 0x0002;
        r16[cx] = 0x0007;
        yield* sub_2499();
        di = pop();
        ds = pop();
        si = pop();
        di += 0x0002;
        pc = 0x53d4;
        break;
        return;
    } while (1);
}
function* sub_5429() {
    yield* sync();
    yield* sync();
    yield* sync();
    yield* sync();
}
function* sub_5444() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x5444:
        yield* sub_544d();
        if (r16[dx] == 0x0000) {
            pc = 0x5444;
            break;
        }
        return;
    } while (1);
}
function* sub_544d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_552a();
        r8[al] = memory[ds*16 + 0x37f3];
        r8[al] |= memory[ds*16 + 0x37f4];
        r8[al] |= memory[ds*16 + 0x37f1];
        r8[al] |= memory[ds*16 + 0x37f2];
        if (memory[ds*16 + 0x37f9] != 0x00) {
            pc = 0x546a;
            break;
        }
        r8[al] |= memory[ds*16 + 0x37f5];
    case 0x546a:
        r8[al] &= 0x10;
        if (r8[al] == 0) {
            pc = 0x5472;
            break;
        }
        r16[dx] = 0xffff;
        return;
    case 0x5472:
        r16[dx] = 0x0000;
        return;
    } while (1);
}
function* sub_5476() {
    yield* sync();
    yield* sub_552a();
    r8[al] = memory[ds*16 + 0x37f3];
    r8[al] |= memory[ds*16 + 0x37f4];
    r8[al] |= memory[ds*16 + 0x37f1];
    r8[al] |= memory[ds*16 + 0x37f2];
    if (memory[ds*16 + 0x37f9] != 0x00)
        return;
    r8[al] |= memory[ds*16 + 0x37f5];
}
function* sub_5494() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x049a;
        si = 0x3c5e;
        r16[cx] = memory16get(ds, 0x0010);
    case 0x549e:
        push(r16[cx]);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x54bc;
            break;
        }
        push(di);
        di += memory16get(ds, 0x0018);
        r16[ax] = memory16get(ds, si + 30);
        yield* sub_573d();
        di = pop();
        push(di);
        di += memory16get(ds, 0x001a);
        yield* sub_573d();
        di = pop();
    case 0x54bc:
        di += 0x0008;
        si += 0x0020;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x549e;
            break;
        }
        return;
    } while (1);
}
function* sub_54c6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0278;
        yield* sub_54f3();
        if (r16[dx] == 0x0000) {
            pc = 0x54ef;
            break;
        }
        r16[ax] = 0x0378;
        yield* sub_54f3();
        if (r16[dx] == 0x0000) {
            pc = 0x54ef;
            break;
        }
        r16[ax] = 0x03bc;
        yield* sub_54f3();
        if (r16[dx] == 0x0000) {
            pc = 0x54ef;
            break;
        }
        r16[ax] = 0xffff;
        memory16set(ds, 0x37e4, r16[dx]);
        return;
    case 0x54ef:
        memory16set(ds, 0x37e4, r16[ax]);
        return;
    } while (1);
}
function* sub_54f3() {
    r16[dx] = 0;
}
function* sub_552a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x37e4) != 0xffff) {
            pc = 0x5534;
            break;
        }
        return;
    case 0x5534:
        r8[al] = memory[ds*16 + 0x37f7];
        memory[ds*16 + 0x37f3] = r8[al];
        r8[al] = memory[ds*16 + 0x37f8];
        memory[ds*16 + 0x37f4] = r8[al];
        si = 0x37e6;
        r8[ah] = 0xff;
        r8[bl] = 0x20;
        r8[bh] = 0x00;
        yield* sub_567c();
        //memory[ds*16 + 0x37f1] = r8[bh];
        si = 0x37eb;
        r8[ah] = 0x00;
        r8[bl] = 0x80;
        r8[bh] = 0x00;
        yield* sub_567c();
        //memory[ds*16 + 0x37f2] = r8[bh];
        if (memory[ds*16 + 0x37f9] != 0x00) {
            pc = 0x55b4;
            break;
        }
        memory[ds*16 + 0x37f0] = 0x00;
        r8[ah] = 0x84;
        r16[dx] = 0x0000;
        interrupt(0x15);
        if (r8[al] & 0x10) {
            pc = 0x557d;
            break;
        }
        memory[ds*16 + 0x37f0] = memory[ds*16 + 0x37f0] | 0x10;
    case 0x557d:
        if (r8[al] & 0x20) {
            pc = 0x5596;
            break;
        }
        if (memory[ds*16 + 0x37fb] != 0x00) {
            pc = 0x559c;
            break;
        }
        memory[ds*16 + 0x37fb] = 0xff;
        memory[ds*16 + 0x204e] = 0xff;
        pc = 0x559c;
        break;
    case 0x5596:
        memory[ds*16 + 0x37fb] = 0x00;
    case 0x559c:
        r8[al] = 0x84;
        r16[dx] = 0x0001;
        interrupt(0x15);
        r16[cx] = memory16get(ds, 0x37be);
        r16[dx] = memory16get(ds, 0x37bc);
        yield* sub_5639();
        r8[al] = memory[ds*16 + 0x37f0];
        memory[ds*16 + 0x37f5] = r8[al];
    case 0x55b4:
        if (memory[ds*16 + 0x37fa] != 0x00) {
            pc = 0x55f6;
            break;
        }
        memory[ds*16 + 0x37f0] = 0x00;
        r8[ah] = 0x84;
        r16[dx] = 0x0000;
        interrupt(0x15);
        if (r8[al] & 0x40) {
            pc = 0x55d1;
            break;
        }
        memory[ds*16 + 0x37f0] = memory[ds*16 + 0x37f0] | 0x10;
    case 0x55d1:
        if (r8[al] & 0x80) {
            pc = 0x55da;
            break;
        }
        memory[ds*16 + 0x204e] = 0xff;
    case 0x55da:
        r8[al] = 0x84;
        r16[dx] = 0x0001;
        interrupt(0x15);
        r16[ax] = r16[cx];
        r16[bx] = r16[dx];
        r16[cx] = memory16get(ds, 0x37c2);
        r16[dx] = memory16get(ds, 0x37c0);
        yield* sub_5639();
        r8[al] = memory[ds*16 + 0x37f0];
        memory[ds*16 + 0x37f6] = r8[al];
    case 0x55f6:
        r16[ax] = 0x0000;
        si = 0x37fc;
        di = 0x3c5e;
        r16[cx] = 0x0004;
    case 0x5602:
        r16[ax] = 0x0000;
        lodsb_data_forward();
        r16[ax] += r16[ax];
        r16[bx] = 0x3800;
        r16[bx] += r16[ax];
        r16[bx] = memory16get(ds, r16[bx]);
        r8[al] = memory[ds*16 + r16[bx]];
        memory16set(ds, di + 26, r16[ax]);
        di += 0x0020;
        if (--r16[cx]) {
            pc = 0x5602;
            break;
        }
        si = 0x3c5e;
        r8[al] = memory[ds*16 + 0x204e];
        if (r8[al] == 0x00) {
            pc = 0x5633;
            break;
        }
        memory16set(ds, si + 26, memory16get(ds, si + 26) | 0x0020);
        memory[ds*16 + 0x204e] = 0x00;
        return;
    case 0x5633:
        memory16set(ds, si + 26, memory16get(ds, si + 26) & 0xffdf);
        return;
    } while (1);
}
function* sub_5639() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] &= 0x00ff;
        r16[bx] &= 0x00ff;
        r16[dx] += 0x0020;
        if (r16[ax] <= r16[dx]) {
            pc = 0x564c;
            break;
        }
        memory[ds*16 + 0x37f0] = memory[ds*16 + 0x37f0] | 0x08;
    case 0x564c:
        r16[dx] -= 0x0040;
        if (r16[ax] > r16[dx]) {
            pc = 0x5658;
            break;
        }
        memory[ds*16 + 0x37f0] = memory[ds*16 + 0x37f0] | 0x04;
    case 0x5658:
        r16[cx] += 0x0020;
        if (r16[bx] <= r16[cx]) {
            pc = 0x5664;
            break;
        }
        memory[ds*16 + 0x37f0] = memory[ds*16 + 0x37f0] | 0x02;
    case 0x5664:
        r16[cx] -= 0x0040;
        if (r16[bx] > r16[cx]) {
            pc = 0x5670;
            break;
        }
        memory[ds*16 + 0x37f0] = memory[ds*16 + 0x37f0] | 0x01;
    case 0x5670:
        if (r16[ax] != 0x0000)
            return;
        memory[ds*16 + 0x37f0] = 0x00;
        return;
    } while (1);
}
function* sub_567c() {
    r16[bx] = 0;
}
function* sub_56de() {
    si = 0x37d4;
    r16[ax] = memory16get(ds, 0x37ce);
    yield* sub_57ae();
    r16[ax] = memory16get(ds, 0x37d4);
    di = 0x0488;
    di += memory16get(ds, 0x0018);
    yield* sub_573d();
    si = 0x37d4;
    r16[ax] = memory16get(ds, 0x37d0);
    yield* sub_579c();
    r16[ax] = memory16get(ds, 0x37d4);
    di = 0x048c;
    di += memory16get(ds, 0x0018);
    yield* sub_573d();
    r16[ax] = memory16get(ds, 0x37d5);
    di = 0x048e;
    di += memory16get(ds, 0x0018);
    yield* sub_573d();
}
function* sub_5718() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x37d4;
        yield* sub_576c();
        si = 0x37d4;
        r16[cx] = 0x0005;
    case 0x5724:
        lodsb_data_forward();
        if (r8[al] != 0x00) {
            pc = 0x5731;
            break;
        }
        di += 0x0002;
        if (--r16[cx]) {
            pc = 0x5724;
            break;
        }
        return;
    case 0x5731:
        push(r16[cx]);
        yield* sub_573d();
        di += 0x0002;
        lodsb_data_forward();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x5731;
            break;
        }
        return;
    } while (1);
}
function* sub_573d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x26f2);
        push(r16[bx]);
        if (r16[bx] != 0x0001) {
            pc = 0x574d;
            break;
        }
        memory16set(ds, 0x26f2, 0x0002);
    case 0x574d:
        push(si);
        push(di);
        push(r16[ax]);
        r16[ax] &= 0x000f;
        r16[ax] += 0x0012;
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x5760;
            break;
        }
        r16[ax] += 0x0090;
    case 0x5760:
        yield* sub_273a();
        r16[ax] = pop();
        di = pop();
        si = pop();
        r16[bx] = pop();
        memory16set(ds, 0x26f2, r16[bx]);
        return;
    } while (1);
}
function* sub_576c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x2710;
        r16[dx] = 0x0000;
        div16(r16[cx]);
        memory[ds*16 + si] = r8[al];
        si++;
        r16[ax] = r16[dx];
        r16[cx] = 0x03e8;
        r16[dx] = 0x0000;
        div16(r16[cx]);
        memory[ds*16 + si] = r8[al];
        si++;
        r16[ax] = r16[dx];
        r16[dx] = 0x0000;
        r16[cx] = 0x0064;
        div16(r16[cx]);
        memory[ds*16 + si] = r8[al];
        si++;
        r16[ax] = r16[dx];
        pc = 0x579c;
        break;
    case 0x579c:
        r16[cx] = 0x000a;
        r16[dx] = 0x0000;
        div16(r16[cx]);
        memory[ds*16 + si] = r8[al];
        si++;
        r16[ax] = r16[dx];
        pc = 0x57ae;
        break;
    case 0x57ae:
        memory[ds*16 + si] = r8[al];
        si++;
        return;
    } while (1);
}
function* sub_579c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0x000a;
        r16[dx] = 0x0000;
        div16(r16[cx]);
        memory[ds*16 + si] = r8[al];
        si++;
        r16[ax] = r16[dx];
        pc = 0x57ae;
        break;
    case 0x57ae:
        memory[ds*16 + si] = r8[al];
        si++;
        return;
    } while (1);
}
function* sub_57ae() {
    memory[ds*16 + si] = r8[al];
    si++;
}
function* sub_57b4() {
    push(r16[ax]);
    push(si);
    push(r16[dx]);
    si = 0x0726;
    r16[cx] = 0x0000;
    r8[cl] = r8[ah];
    r8[ah] = 0x00;
    si += r16[ax];
    r16[ax] = memory16get(ds, 0x26f4);
    mul16(r16[cx]);
    si += r16[ax];
    r16[dx] = pop();
    memory[ds*16 + si] = r8[dl];
    si = pop();
    r16[ax] = pop();
}
function* sub_57d2() {
    push(r16[ax]);
    r8[ah] = 0x00;
    r8[cl] = 0x04;
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0008;
    r16[dx] = r16[ax];
    r16[ax] = pop();
    r8[al] = r8[ah];
    r8[ah] = 0x00;
    r16[ax] <<= r8[cl];
    r16[ax] += 0x0018;
    r16[cx] = r16[ax];
    r16[dx] += 0x0008;
    r16[cx] += 0x0008;
}
function* sub_57f1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += 0x0002;
        di = r16[ax];
        r16[ax] = pop();
        r8[al] = r8[ah];
        r8[ah] = 0x00;
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x5814;
            break;
        }
        r16[cx] = 0x0800;
        mul16(r16[cx]);
        r16[ax] += 0x0c00;
        di += r16[ax];
        return;
    case 0x5814:
        r16[cx] = 0x0400;
        mul16(r16[cx]);
        r16[ax] += 0x0600;
        di += r16[ax];
        return;
    } while (1);
}
function* sub_581f() {
    push(r16[cx]);
    r16[dx] -= 0x0008;
    r8[cl] = 0x04;
    r16[dx] >>= r8[cl];
    r8[al] = r8[dl];
    r16[dx] = pop();
    r16[dx] -= 0x0018;
    r16[dx] >>= r8[cl];
    r8[ah] = r8[dl];
}
function* sub_5832() {
    push(si);
    si = 0x0726;
    r16[cx] = 0x0000;
    r8[cl] = r8[ah];
    r8[ah] = 0x00;
    si += r16[ax];
    r16[ax] = memory16get(ds, 0x26f4);
    mul16(r16[cx]);
    si += r16[ax];
    r8[al] = memory[ds*16 + si];
    si = pop();
}
function* sub_584c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = 0x0080;
        if (memory16get(ds, 0x26f2) != 0x0002) {
            pc = 0x585a;
            break;
        }
        r16[ax] = 0x0040;
    case 0x585a:
        mul16(r16[cx]);
        di = r16[ax];
        r16[ax] = pop();
        r16[cx] = r16[ax];
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        di += r16[cx];
        r16[ax] &= 0x0003;
        return;
    } while (1);
}
function* sub_586b() {
    r8[ah] = 0x2c;
    interrupt(0x21);
    r8[dl] ^= r8[ch];
    r8[dl] ^= r8[cl];
    r8[dl] ^= r8[dh];
    r8[dh] = 0x00;
    memory16set(ds, 0x37cc, r16[dx]);
}
function* sub_587c() {
    push(si);
    r16[cx] = r16[ax];
    si = 0x38bb;
    r16[dx] = memory16get(ds, 0x37cc);
    si += r16[dx];
    r16[ax] = memory16get(ds, si);
    r16[dx] += r16[ax];
    r16[dx]++;
    r16[dx] &= 0x007f;
    memory16set(ds, 0x37cc, r16[dx]);
    r16[dx] = memory16get(ds, si + 1);
    memory16set(ds, si, memory16get(ds, si) ^ r16[dx]);
    r16[dx] = 0x0000;
    div16(r16[cx]);
    r16[ax] = r16[dx];
    si = pop();
}
function* sub_58a7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x3d;
        r8[al] = 0x90;
        r16[dx] = 0x380c;
        interrupt(0x21);
        if (flags.carry) {
            pc = 0x58fd;
            break;
        }
        memory16set(ds, 0x37ca, r16[ax]);
        push(ds);
        r8[ah] = 0x3f;
        r16[bx] = memory16get(ds, 0x37ca);
        r16[cx] = 0x2710;
        r16[dx] = 0x25f0;
        ds = r16[dx];
        r16[dx] = 0x5590;
        interrupt(0x21);
        ds = pop();
        if (flags.carry) {
            pc = 0x58f5;
            break;
        }
        r8[ah] = 0x3e;
        r16[bx] = memory16get(ds, 0x37ca);
        interrupt(0x21);
        push(ds);
        push(es);
        push(r16[cx]);
        push(si);
        r16[cx] = 0x0b52;
        es = r16[cx];
        r16[cx] = 0x25f0;
        ds = r16[cx];
        si = 0x5590;
        di = 0x0726;
        r16[cx] = 0x01b8;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        es = pop();
        ds = pop();
        r16[dx] = 0x0000;
        return;
    case 0x58f5:
        r8[ah] = 0x3e;
        r16[bx] = memory16get(ds, 0x37ca);
        interrupt(0x21);
    case 0x58fd:
        r16[dx] = 0xffff;
        return;
    } while (1);
}
function* sub_5901() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = 0x3d;
        r8[al] = 0x90;
        r16[dx] = 0x3815;
        interrupt(0x21);
        if (flags.carry) {
            pc = 0x5966;
            break;
        }
        memory16set(ds, 0x37ca, r16[ax]);
        r8[ah] = 0x3f;
        r16[bx] = memory16get(ds, 0x37ca);
        r16[cx] = 0x001c;
        r16[dx] = 0x381e;
        interrupt(0x21);
        if (flags.carry) {
            pc = 0x5967;
            break;
        }
        r8[ah] = 0x3e;
        r16[bx] = memory16get(ds, 0x37ca);
        interrupt(0x21);
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x381e;
        di = 0x205d;
        r16[cx] = 0x000c;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x382a;
        di = 0x2069;
        r16[cx] = 0x000a;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x3834;
        di = 0x37fc;
        r16[cx] = 0x0004;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        r8[al] = memory[ds*16 + 0x3838];
        memory[ds*16 + 0x0024] = r8[al];
    case 0x5966:
        return;
    case 0x5967:
        r8[ah] = 0x3e;
        r16[bx] = memory16get(ds, 0x37ca);
        interrupt(0x21);
        return;
    } while (1);
}
function* sub_5970() {
    push(r16[cx]);
    push(si);
    r16[cx] = ds;
    es = r16[cx];
    si = 0x205d;
    di = 0x381e;
    r16[cx] = 0x000c;
    rep_movsb_data_data_forward();
    si = pop();
    r16[cx] = pop();
    push(r16[cx]);
    push(si);
    r16[cx] = ds;
    es = r16[cx];
    si = 0x2069;
    di = 0x382a;
    r16[cx] = 0x000a;
    rep_movsb_data_data_forward();
    si = pop();
    r16[cx] = pop();
    push(r16[cx]);
    push(si);
    r16[cx] = ds;
    es = r16[cx];
    si = 0x37fc;
    di = 0x3834;
    r16[cx] = 0x0004;
    rep_movsb_data_data_forward();
    si = pop();
    r16[cx] = pop();
    r8[al] = memory[ds*16 + 0x0024];
    memory[ds*16 + 0x3838] = r8[al];
    r16[dx] = 0x3815;
    r16[cx] = 0x0000;
    r8[ah] = 0x3c;
    interrupt(0x21);
    if (flags.carry)
        return;
    memory16set(ds, 0x37ca, r16[ax]);
    r16[bx] = r16[ax];
    r16[bx] = memory16get(ds, 0x37ca);
    r16[dx] = 0x381e;
    r16[cx] = 0x001c;
    r8[ah] = 0x40;
    interrupt(0x21);
    r16[bx] = memory16get(ds, 0x37ca);
    r8[ah] = 0x3e;
    interrupt(0x21);
}
function* sub_59d8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x3d8e;
        r16[cx] = 0x0008;
    case 0x59de:
        push(si);
        push(r16[cx]);
        di = memory16get(ds, si);
        if (di == 0xffff) {
            pc = 0x5a19;
            break;
        }
        r16[dx] = memory16get(ds, 0x001e);
        r16[ax] = memory16get(ds, si + 4);
        r8[al] += r8[dl];
        if (r8[ah] > r8[al]) {
            pc = 0x59fe;
            break;
        }
        r8[al] = 0x00;
        memory16set(ds, si + 2, memory16get(ds, si + 2) + 0x0002);
    case 0x59fe:
        memory16set(ds, si + 4, r16[ax]);
        r16[bx] = memory16get(ds, si + 2);
        r16[ax] = memory16get(ds, r16[bx]);
        if (r16[ax] == 0xffff) {
            pc = 0x5a21;
            break;
        }
        yield* sub_4ffe();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
    case 0x5a19:
        r16[cx] = pop();
        si = pop();
        si += 0x000a;
        if (--r16[cx]) {
            pc = 0x59de;
            break;
        }
        return;
    case 0x5a21:
        r16[ax] = memory16get(ds, si + 8);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] = 0x3a80;
        r16[bx] += r16[ax];
        r16[dx] = memory16get(ds, r16[bx]);
        memory16set(ds, si, 0xffff);
        r16[ax] = memory16get(ds, si + 6);
        yield* sub_57b4();
        pc = 0x5a19;
        break;
        return;
    } while (1);
}
function* sub_5a41() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x3a5d] = 0xff;
        si = 0x3c5e;
        yield* sub_5b29();
        si = 0x3c7e;
        yield* sub_5b29();
        si = 0x3c9e;
        yield* sub_5b29();
        si = 0x3cbe;
        yield* sub_5b29();
        yield* sub_5ab3();
        yield* sub_5c33();
        if (memory16get(ds, 0x4f88) != 0x0001) {
            pc = 0x5aab;
            break;
        }
        if (memory16get(ds, 0x4f8a) != 0x0001) {
            pc = 0x5aab;
            break;
        }
        if (memory[ds*16 + 0x3a5d] == 0xff) {
            pc = 0x5aac;
            break;
        }
        memory16set(ds, 0x4f6c, memory16get(ds, 0x4f6c) - 1);
        if (memory16gets(ds, 0x4f6c) >= 0) {
            pc = 0x5aab;
            break;
        }
        memory16set(ds, 0x4f6c, 0x7fff);
        push(r16[cx]);
        push(r16[ax]);
        push(si);
        yield* sub_71c6();
        push(r16[ax]);
        r8[dl] = 0x70;
        yield* sub_57b4();
        r16[ax] = pop();
        yield* sub_57f1();
        r16[ax] = 0x009b;
        yield* sub_5f24();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        si = pop();
        r16[ax] = pop();
        r16[cx] = pop();
    case 0x5aab:
        return;
    case 0x5aac:
        memory16set(ds, 0x4f6c, 0x0ca8);
        return;
    } while (1);
}
function* sub_5ab3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x0012) == 0x0000)
            return;
        si = 0x3c5e;
        r16[cx] = memory16get(ds, 0x0010);
    case 0x5ac1:
        push(r16[cx]);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x5b22;
            break;
        }
        if (memory16get(ds, si + 20) == 0x0000) {
            pc = 0x5b22;
            break;
        }
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        r16[dx] = r16[ax];
        r16[cx] = memory16get(ds, 0x0010);
        di = 0x3c5e;
    case 0x5ae4:
        push(r16[cx]);
        if (memory16get(ds, di) == 0xffff) {
            pc = 0x5b1c;
            break;
        }
        r16[ax] = memory16get(ds, si + 24);
        if (r16[ax] == memory16get(ds, di + 24)) {
            pc = 0x5b1c;
            break;
        }
        push(r16[dx]);
        r16[dx] = memory16get(ds, di);
        r16[cx] = memory16get(ds, di + 2);
        yield* sub_581f();
        r16[dx] = pop();
        if (r16[ax] != r16[dx]) {
            pc = 0x5b1c;
            break;
        }
        if (memory16get(ds, di + 22) != 0xffff) {
            pc = 0x5b1c;
            break;
        }
        r16[ax] = memory16get(ds, si + 22);
        memory16set(ds, di + 22, r16[ax]);
        memory16set(ds, di + 20, 0x00b4);
    case 0x5b1c:
        r16[cx] = pop();
        di += 0x0020;
        if (--r16[cx]) {
            pc = 0x5ae4;
            break;
        }
    case 0x5b22:
        r16[cx] = pop();
        si += 0x0020;
        if (--r16[cx]) {
            pc = 0x5ac1;
            break;
        }
        return;
    } while (1);
}
function* sub_5b29() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x5b6a;
            break;
        }
        if (memory16gets(ds, si + 8) < 0) {
            pc = 0x5b6a;
            break;
        }
        if (memory16gets(ds, si + 10) < 0) {
            pc = 0x5b67;
            break;
        }
        yield* sub_5d66();
        if (memory16get(ds, 0x4f88) != 0x0000) {
            pc = 0x5b97;
            break;
        }
        memory16set(ds, 0x3a54, 0x0300);
        r16[ax] = memory16get(ds, si + 22);
        if (r16[ax] == 0xffff) {
            pc = 0x5b97;
            break;
        }
        if (r16[ax] != 0x0000) {
            pc = 0x5b6d;
            break;
        }
        memory16set(ds, 0x3a54, 0x0100);
        yield* sub_6037();
        pc = 0x5b9a;
        break;
    case 0x5b67:
        pc = 0x5ba5;
        break;
    case 0x5b6a:
        pc = 0x5ba4;
        break;
    case 0x5b6d:
        if (r16[ax] != 0x0001) {
            pc = 0x5b7d;
            break;
        }
        memory16set(ds, 0x3a54, 0x0c00);
        yield* sub_6037();
        pc = 0x5b9a;
        break;
    case 0x5b7d:
        if (r16[ax] != 0x0002) {
            pc = 0x5b89;
            break;
        }
        memory[ds*16 + si + 26] = memory[ds*16 + si + 26] & 0x0f;
        pc = 0x5b97;
        break;
    case 0x5b89:
        if (r16[ax] != 0x0003) {
            pc = 0x5b97;
            break;
        }
        r16[ax] = memory16get(ds, 0x0022);
        r8[al] &= 0x10;
        memory[ds*16 + si + 26] = memory[ds*16 + si + 26] ^ r8[al];
    case 0x5b97:
        yield* sub_6037();
    case 0x5b9a:
        yield* sub_5dce();
        if (memory16get(ds, si + 10) == 0xffff) {
            pc = 0x5b67;
            break;
        }
    case 0x5ba4:
        return;
    case 0x5ba5:
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        push(si);
        push(r16[cx]);
        push(r16[dx]);
        si = memory16get(ds, 0x3a46);
        r16[ax] = memory16get(ds, 0x001c);
        r16[ax] &= 0x0001;
        if (r16[ax] != 0x0000) {
            pc = 0x5bc4;
            break;
        }
        memory16set(ds, 0x3a46, memory16get(ds, 0x3a46) + 0x0004);
    case 0x5bc4:
        di = 0x41c9;
        lodsw_data_forward();
        if (r16[ax] == 0xffff) {
            pc = 0x5c23;
            break;
        }
        memory16set(ds, di, r16[ax]);
        r16[ax] = 0x42fd;
        memory16set(ds, di + 2, r16[ax]);
        lodsw_data_forward();
        r16[dx] = 0x0016;
        r16[dx] -= r16[ax];
        memory16set(ds, di + 6, r16[dx]);
        si = 0x41c9;
        r16[dx] = pop();
        r16[cx] = pop();
        r16[cx] += r16[ax];
        push(r16[cx]);
        push(r16[dx]);
        yield* sub_2782();
        di = 0x41d9;
        si = memory16get(ds, 0x3a48);
        lodsw_data_forward();
        if (r16[ax] != 0xffff) {
            pc = 0x5c03;
            break;
        }
        si = 0x40ed;
        memory16set(ds, 0x3a48, si);
        lodsw_data_forward();
    case 0x5c03:
        memory16set(ds, 0x3a48, memory16get(ds, 0x3a48) + 0x0002);
        memory16set(ds, di, r16[ax]);
        r16[ax] = 0x42fd;
        memory16set(ds, di + 2, r16[ax]);
        r16[dx] = pop();
        r16[cx] = pop();
        r16[dx] -= 0x0004;
        r16[cx] -= 0x0008;
        si = 0x41d9;
        yield* sub_2782();
        si = pop();
        return;
    case 0x5c23:
        r16[dx] = pop();
        r16[cx] = pop();
        si = pop();
        memory16set(ds, 0x4f7c, 0x0002);
        memory16set(ds, si, 0xffff);
        return;
    } while (1);
}
function* sub_5c33() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x3c5e;
        r16[cx] = 0x0004;
    case 0x5c39:
        push(r16[cx]);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x5cab;
            break;
        }
        if (memory16gets(ds, si + 8) < 0) {
            pc = 0x5ca8;
            break;
        }
        if (memory16gets(ds, si + 10) < 0) {
            pc = 0x5cab;
            break;
        }
        push(si);
        r16[bx] = 0x3b7a;
        r16[ax] = memory16get(ds, si + 8);
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        r16[bx] = 0x3e4c;
        r16[dx] = memory16get(ds, si + 24);
        r16[dx] += r16[dx];
        r16[bx] += r16[dx];
        r16[ax] += memory16get(ds, r16[bx]);
        r16[ax] += memory16get(ds, si + 28);
        r16[dx] = memory16get(ds, si);
        r16[dx] -= 0x000b;
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x000d;
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x5cae;
            break;
        }
        r16[bx] = memory16get(ds, si + 22);
        r16[bx] &= 0x0008;
        if (r16[bx] == 0x0000) {
            pc = 0x5cae;
            break;
        }
        r16[bx] = memory16get(ds, 0x001c);
        r16[bx] &= 0x0002;
        if (r16[bx] != 0x0000) {
            pc = 0x5cae;
            break;
        }
        r8[bl] = 0xfe;
        yield* sub_28b6();
        si = pop();
        pc = 0x5cf4;
        break;
    case 0x5ca8:
        pc = 0x5d00;
        break;
    case 0x5cab:
        pc = 0x5cfe;
        break;
    case 0x5cae:
        yield* sub_276b();
        si = pop();
        if (memory16get(ds, 0x4f88) != 0x0003) {
            pc = 0x5cf4;
            break;
        }
        push(si);
        r16[dx] = memory16get(ds, si);
        r16[dx] -= 0x0008;
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] += 0x0001;
        r16[bx] = 0x41a9;
        if (memory[ds*16 + 0x3a5d] == 0x00) {
            pc = 0x5cd5;
            break;
        }
        r16[bx] = 0x41b9;
    case 0x5cd5:
        r16[ax] = memory16get(ds, 0x001c);
        r16[ax] &= 0x000c;
        r16[bx] += r16[ax];
        si = 0x41e9;
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 2, r16[ax]);
        yield* sub_2782();
        si = pop();
    case 0x5cf4:
        r16[cx] = pop();
        si += 0x0020;
        if (--r16[cx]) {
            pc = 0x5cfb;
            break;
        }
        return;
    case 0x5cfb:
        pc = 0x5c39;
        break;
    case 0x5cfe:
        pc = 0x5cf4;
        break;
    case 0x5d00:
        r16[ax] = memory16get(ds, 0x001e);
        memory16set(ds, si + 10, memory16get(ds, si + 10) + r16[ax]);
        if (memory16get(ds, si + 10) < 0x0009) {
            pc = 0x5d18;
            break;
        }
        memory16set(ds, si + 10, 0x0000);
        memory16set(ds, si + 8, memory16get(ds, si + 8) - 1);
    case 0x5d18:
        r16[bx] = 0x3b5e;
        r16[ax] = memory16get(ds, si + 8);
        r16[ax] = -r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        if (r16[ax] == 0xffff) {
            pc = 0x5d58;
            break;
        }
        r16[bx] = 0x3e4c;
        r16[dx] = memory16get(ds, si + 24);
        r16[dx] += r16[dx];
        r16[bx] += r16[dx];
        r16[ax] += memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, si);
        r16[dx] -= 0x0008;
        r16[dx] -= 0x0003;
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0008;
        r16[cx] -= 0x0005;
        push(si);
        yield* sub_276b();
        si = pop();
        pc = 0x5cf4;
        break;
    case 0x5d58:
        memory16set(ds, si, 0xffff);
        memory16set(ds, si + 8, 0x0000);
        pc = 0x5cf4;
        break;
        return;
    } while (1);
}
function* sub_5d66() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, si + 20);
        if (r16[ax] == 0x0000) {
            pc = 0x5da6;
            break;
        }
        r16[ax]--;
        memory16set(ds, si + 20, r16[ax]);
        if (r16[ax] == 0x0000) {
            pc = 0x5da7;
            break;
        }
        r16[dx] = r16[ax];
        r16[dx] &= 0x0003;
        if (r16[dx] != 0x0000) {
            pc = 0x5da6;
            break;
        }
        r16[ax] &= 0x0004;
        r8[cl] = 0x01;
        r16[ax] >>= r8[cl];
        r16[bx] = 0x3fac;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, si + 24);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        push(si);
        si = memory16get(ds, r16[bx]);
        lodsw_data_forward();
        r16[cx] = r16[ax];
        lodsw_data_forward();
        yield* sub_2397();
        si = pop();
    case 0x5da6:
        return;
    case 0x5da7:
        memory16set(ds, si + 22, 0xffff);
        push(si);
        r16[bx] = 0x3fac;
        r16[ax] = memory16get(ds, si + 24);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        si = memory16get(ds, r16[bx]);
        lodsw_data_forward();
        r16[cx] = r16[ax];
        lodsw_data_forward();
        yield* sub_2397();
        si = pop();
        memory16set(ds, 0x3a54, 0x0300);
        return;
    } while (1);
}
function* sub_5dce() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x3a5e] = 0x00;
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        push(r16[ax]);
        yield* sub_5832();
        r16[dx] = pop();
        if (r8[al] < 0x61) {
            pc = 0x5e30;
            break;
        }
        if (r8[al] > 0x75) {
            pc = 0x5e30;
            break;
        }
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x5e24;
            break;
        }
        if (r8[al] == 0x67) {
            pc = 0x5e4c;
            break;
        }
        if (r8[al] == 0x66) {
            pc = 0x5e53;
            break;
        }
        if (r8[al] == 0x6b) {
            pc = 0x5e34;
            break;
        }
        if (r8[al] == 0x6a) {
            pc = 0x5e31;
            break;
        }
        if (r8[al] == 0x69) {
            pc = 0x5e37;
            break;
        }
        if (r8[al] == 0x6d) {
            pc = 0x5e40;
            break;
        }
        if (r8[al] == 0x68) {
            pc = 0x5e43;
            break;
        }
        if (r8[al] == 0x6c) {
            pc = 0x5e46;
            break;
        }
        if (r8[al] == 0x75) {
            pc = 0x5e49;
            break;
        }
        if (r8[al] == 0x73) {
            pc = 0x5e3a;
            break;
        }
        if (r8[al] == 0x6f) {
            pc = 0x5e3d;
            break;
        }
        if (r8[al] == 0x70) {
            pc = 0x5e3d;
            break;
        }
        return;
    case 0x5e24:
        if (r8[al] == 0x61) {
            pc = 0x5e4c;
            break;
        }
        if (r8[al] == 0x62) {
            pc = 0x5e53;
            break;
        }
        if (r8[al] == 0x63) {
            pc = 0x5e5a;
            break;
        }
    case 0x5e30:
        return;
    case 0x5e31:
        pc = 0x5e99;
        break;
    case 0x5e34:
        pc = 0x5e91;
        break;
    case 0x5e37:
        pc = 0x5ea1;
        break;
    case 0x5e3a:
        pc = 0x5edb;
        break;
    case 0x5e3d:
        pc = 0x5ee4;
        break;
    case 0x5e40:
        pc = 0x5ed4;
        break;
    case 0x5e43:
        pc = 0x5ec4;
        break;
    case 0x5e46:
        pc = 0x5ecc;
        break;
    case 0x5e49:
        pc = 0x5eec;
        break;
    case 0x5e4c:
        push(si);
        memory16set(ds, si + 12, memory16get(ds, si + 12) + 1);
        pc = 0x5e6d;
        break;
    case 0x5e53:
        push(si);
        memory16set(ds, si + 18, memory16get(ds, si + 18) + 1);
        pc = 0x5e6d;
        break;
    case 0x5e5a:
        push(r16[dx]);
        memory16set(ds, si + 20, 0x00b4);
        r16[ax] = 0x0004;
        yield* sub_587c();
        memory16set(ds, si + 22, r16[ax]);
        r16[dx] = pop();
        push(si);
    case 0x5e6d:
        r16[ax] = r16[dx];
        push(r16[ax]);
        yield* sub_57f1();
        r16[ax] = 0x0000;
        yield* sub_4ffe();
        yield* sub_5f24();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        r16[ax] = pop();
        r8[dl] = 0x2e;
        yield* sub_57b4();
        r16[ax] = 0x0001;
        yield* sub_8ca1();
        si = pop();
        return;
    case 0x5e91:
        push(si);
        memory16set(ds, si + 22, memory16get(ds, si + 22) | 0x0001);
        pc = 0x5e6d;
        break;
    case 0x5e99:
        push(si);
        memory16set(ds, si + 22, memory16get(ds, si + 22) | 0x0002);
        pc = 0x5e6d;
        break;
    case 0x5ea1:
        push(si);
        if (memory16get(ds, 0x3a54) != 0x0240) {
            pc = 0x5eb2;
            break;
        }
        memory16set(ds, 0x3a54, 0x0300);
        pc = 0x5e6d;
        break;
    case 0x5eb2:
        if (memory16get(ds, 0x3a54) != 0x0300) {
            pc = 0x5ec2;
            break;
        }
        memory16set(ds, 0x3a54, 0x03c0);
        pc = 0x5e6d;
        break;
    case 0x5ec2:
        pc = 0x5e6d;
        break;
    case 0x5ec4:
        push(si);
        memory16set(ds, si + 22, memory16get(ds, si + 22) | 0x0004);
        pc = 0x5e6d;
        break;
    case 0x5ecc:
        push(si);
        memory16set(ds, si + 22, memory16get(ds, si + 22) | 0x0008);
        pc = 0x5e6d;
        break;
    case 0x5ed4:
        push(si);
        memory16set(ds, 0x4f8c, memory16get(ds, 0x4f8c) + 1);
        pc = 0x5e6d;
        break;
    case 0x5edb:
        push(si);
        memory16set(ds, 0x3a50, memory16get(ds, 0x3a50) + 0x012c);
        pc = 0x5e6d;
        break;
    case 0x5ee4:
        push(si);
        memory16set(ds, 0x3a50, memory16get(ds, 0x3a50) + 0x0064);
        pc = 0x5e6d;
        break;
    case 0x5eec:
        if (memory16get(ds, 0x4200) != 0x0000)
            return;
        memory[ds*16 + 0x3a5e] = 0xff;
        return;
    } while (1);
}
function* sub_5efa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x3dde;
        r16[cx] = 0x0008;
    case 0x5f00:
        di = memory16get(ds, si);
        if (di == 0xffff) {
            pc = 0x5f1e;
            break;
        }
        memory16set(ds, si, 0xffff);
        di += memory16get(ds, 0x0018);
        r16[ax] = memory16get(ds, si + 2);
        push(r16[cx]);
        push(si);
        yield* sub_273a();
        si = pop();
        r16[cx] = pop();
    case 0x5f1e:
        si += 0x0004;
        if (--r16[cx]) {
            pc = 0x5f00;
            break;
        }
        return;
    } while (1);
}
function* sub_5f24() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        si = 0x3dde;
        r16[cx] = 0x0008;
    case 0x5f2b:
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x5f39;
            break;
        }
        si += 0x0004;
        if (--r16[cx]) {
            pc = 0x5f2b;
            break;
        }
        si = pop();
        return;
    case 0x5f39:
        memory16set(ds, si, di);
        memory16set(ds, si + 2, r16[ax]);
        si = pop();
        return;
    } while (1);
}
function* sub_5f43() {
    r16[dx] = memory16get(ds, si);
    r16[cx] = memory16get(ds, si + 2);
    yield* sub_581f();
    push(si);
    si = 0x0726;
    di = 0x3f94;
    r16[cx] = 0x0000;
    r8[cl] = r8[ah];
    r8[ah] = 0x00;
    si += r16[ax];
    r16[ax] = memory16get(ds, 0x26f4);
    mul16(r16[cx]);
    si += r16[ax];
    r16[bx] = memory16get(ds, 0x26f4);
    r16[bx] = -r16[bx];
    r8[al] = memory[ds*16 + (r16[bx] + si - 1 & 0xffff)];
    memory[ds*16 + di] = r8[al];
    r8[al] = memory[ds*16 + (r16[bx] + si & 0xffff)];
    memory[ds*16 + di + 1] = r8[al];
    r8[al] = memory[ds*16 + (r16[bx] + si + 1 & 0xffff)];
    memory[ds*16 + di + 2] = r8[al];
    r8[al] = memory[ds*16 + si - 1];
    memory[ds*16 + di + 7] = r8[al];
    r8[al] = memory[ds*16 + si + 1];
    memory[ds*16 + di + 3] = r8[al];
    r16[bx] = -r16[bx];
    r8[al] = memory[ds*16 + (r16[bx] + si - 1 & 0xffff)];
    memory[ds*16 + di + 6] = r8[al];
    r8[al] = memory[ds*16 + (r16[bx] + si & 0xffff)];
    memory[ds*16 + di + 5] = r8[al];
    r8[al] = memory[ds*16 + (r16[bx] + si + 1 & 0xffff)];
    memory[ds*16 + di + 4] = r8[al];
    si = pop();
    r16[dx] = memory16get(ds, si);
    r16[dx] -= 0x0010;
    r16[dx] += 0x0008;
    r16[dx] &= 0x000f;
    r16[dx] -= 0x0008;
    memory16set(ds, 0x3a58, r16[dx]);
    r16[dx] = memory16get(ds, si + 2);
    r16[dx] -= 0x0020;
    r16[dx] += 0x0008;
    r16[dx] &= 0x000f;
    r16[dx] -= 0x0008;
    memory16set(ds, 0x3a5a, r16[dx]);
}
function* sub_5fd7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x6033;
            break;
        }
        if (memory[ds*16 + 0x3a5e] == 0x00) {
            pc = 0x6033;
            break;
        }
        r16[ax] = memory16get(ds, si);
        r16[ax] -= 0x0010;
        r16[ax] &= 0x000f;
        if (r16[ax] != 0x0000) {
            pc = 0x6033;
            break;
        }
        r16[ax] = memory16get(ds, si + 2);
        r16[ax] -= 0x0020;
        r16[ax] &= 0x000f;
        if (r16[ax] != 0x0000) {
            pc = 0x6033;
            break;
        }
        memory16set(ds, si, memory16get(ds, si) - 0x000b);
        memory16set(ds, si + 2, memory16get(ds, si + 2) - 0x000d);
        memory16set(ds, 0x3a46, 0x40f7);
        memory16set(ds, 0x3a48, 0x40ed);
        memory16set(ds, si + 10, 0xffff);
        memory16set(ds, si + 22, memory16get(ds, si + 22) | 0x0008);
        r16[ax] = 0x000a;
        yield* sub_8c10();
        r16[dx] = 0xffff;
        memory[ds*16 + 0x0023] = 0xff;
        return;
    case 0x6033:
        r16[dx] = 0x0000;
        return;
    } while (1);
}
function* sub_6037() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, si + 26);
        r8[bh] = r8[bl];
        r8[bl] &= 0x10;
        if (r8[bl] == 0) {
            pc = 0x6049;
            break;
        }
        push(r16[bx]);
        yield* sub_60b0();
        r16[bx] = pop();
    case 0x6049:
        r8[bl] = r8[bh];
        r8[bl] &= 0x01;
        if (r8[bl] == 0) {
            pc = 0x605e;
            break;
        }
        yield* sub_66b6();
        yield* sub_663d();
        memory16set(ds, si + 28, 0x0009);
        return;
    case 0x605e:
        r8[bl] = r8[bh];
        r8[bl] &= 0x02;
        if (r8[bl] == 0) {
            pc = 0x6073;
            break;
        }
        yield* sub_66e1();
        yield* sub_663d();
        memory16set(ds, si + 28, 0x0000);
        return;
    case 0x6073:
        r8[bl] = r8[bh];
        r8[bl] &= 0x04;
        if (r8[bl] == 0) {
            pc = 0x6088;
            break;
        }
        yield* sub_668b();
        yield* sub_663d();
        memory16set(ds, si + 28, 0x0006);
        return;
    case 0x6088:
        r8[bl] = r8[bh];
        r8[bl] &= 0x08;
        if (r8[bl] == 0) {
            pc = 0x609d;
            break;
        }
        yield* sub_6660();
        yield* sub_663d();
        memory16set(ds, si + 28, 0x0003);
        return;
    case 0x609d:
        memory[ds*16 + 0x3a5d] = 0x00;
        memory16set(ds, si + 8, 0x0000);
        memory16set(ds, si + 10, 0x0000);
        return;
    } while (1);
}
function* sub_60b0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x3cde;
        r16[cx] = 0x0008;
    case 0x60b6:
        r16[ax] = memory16get(ds, r16[bx]);
        if (r16[ax] == 0xffff) {
            pc = 0x60c7;
            break;
        }
        r16[bx] += 0x0016;
        if (--r16[cx]) {
            pc = 0x60b6;
            break;
        }
        return;
    case 0x60c7:
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        r16[dx] = r16[ax];
        push(r16[dx]);
        yield* sub_5832();
        r16[dx] = pop();
        if (r8[al] != 0x2e)
            return;
        r16[ax] = memory16get(ds, si + 12);
        if (r16[ax] == memory16get(ds, si + 14))
            return;
        memory16set(ds, si + 14, memory16get(ds, si + 14) + 1);
        push(si);
        push(r16[bx]);
        r16[ax] = r16[dx];
        r8[dl] = 0x2b;
        push(r16[ax]);
        yield* sub_57b4();
        r16[ax] = pop();
        push(r16[ax]);
        yield* sub_57d2();
        r16[ax] = r16[dx];
        r16[cx] -= 0x0008;
        r16[ax] -= 0x0008;
        yield* sub_584c();
        r16[ax] = pop();
        r16[bx] = pop();
        si = pop();
        memory16set(ds, r16[bx], di);
        memory16set(ds, r16[bx] + 2, 0x0000);
        memory16set(ds, r16[bx] + 4, 0x0000);
        memory16set(ds, r16[bx] + 6, 0x00d2);
        memory16set(ds, r16[bx] + 8, r16[ax]);
        r16[ax] = memory16get(ds, si + 24);
        memory16set(ds, r16[bx] + 18, r16[ax]);
        r16[ax] = memory16get(ds, 0x3a4e);
        memory16set(ds, r16[bx] + 20, r16[ax]);
        memory16set(ds, 0x3a4e, memory16get(ds, 0x3a4e) + 1);
        if (memory16get(ds, 0x4f88) == 0x0000)
            return;
        r16[ax] = memory16get(ds, 0x3c74);
        r16[ax] &= 0x0004;
        if (r16[ax] == 0x0000)
            return;
        memory16set(ds, r16[bx] + 6, 0x7fff);
        return;
    } while (1);
}
function* sub_614e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = memory16get(ds, si + 18);
        r16[bx] = 0x3f9e;
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[bx] = memory16get(ds, r16[bx]);
        r16[bx] = memory16get(ds, r16[bx] + 18);
        r16[ax] = pop();
        r16[cx] = 0x0000;
    case 0x6166:
        r8[al] += r8[dl];
        r8[ah] += r8[dh];
        push(r16[ax]);
        push(r16[dx]);
        push(r16[cx]);
        yield* sub_5832();
        r16[cx] = pop();
        r16[dx] = pop();
        if (r8[al] != 0x2e) {
            pc = 0x6184;
            break;
        }
        r16[ax] = pop();
        r16[cx]++;
        if (r16[cx] == r16[bx]) {
            pc = 0x617e;
            break;
        }
        pc = 0x6166;
        break;
    case 0x617e:
        r16[cx] = -r16[cx];
        return;
    case 0x6181:
        pc = 0x6220;
        break;
    case 0x6184:
        if (r8[al] == 0x2b) {
            pc = 0x6181;
            break;
        }
        if (r8[al] < 0x41) {
            pc = 0x6193;
            break;
        }
        if (r8[al] > 0x54) {
            pc = 0x6193;
            break;
        }
        pc = 0x623d;
        break;
    case 0x6193:
        if (r8[al] == 0x55) {
            pc = 0x61a8;
            break;
        }
        if (r8[al] < 0x61) {
            pc = 0x61a2;
            break;
        }
        if (r8[al] > 0x74) {
            pc = 0x61a2;
            break;
        }
        pc = 0x62d0;
        break;
    case 0x61a2:
        if (r8[al] == 0x75) {
            pc = 0x61d2;
            break;
        }
        r16[ax] = pop();
        return;
    case 0x61a8:
        if (memory16get(ds, 0x4f6e) != 0x0001) {
            pc = 0x61cf;
            break;
        }
        push(r16[cx]);
        push(r16[ax]);
        push(si);
        yield* sub_71c6();
        push(r16[ax]);
        r8[dl] = 0x73;
        yield* sub_57b4();
        r16[ax] = pop();
        yield* sub_57f1();
        r16[ax] = 0x009e;
        yield* sub_5f24();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        si = pop();
        r16[ax] = pop();
        r16[cx] = pop();
    case 0x61cf:
        pc = 0x623d;
        break;
    case 0x61d2:
        r16[ax] = pop();
        if (memory16gets(ds, 0x3c68) < 0) {
            pc = 0x621f;
            break;
        }
        push(r16[cx]);
        push(si);
        push(r16[ax]);
        r16[ax] = 0x0004;
        yield* sub_587c();
        r16[dx] = 0x0009;
        if (r16[ax] == 0x0000) {
            pc = 0x61fe;
            break;
        }
        r16[dx] = 0x0005;
        if (r16[ax] == 0x0001) {
            pc = 0x61fe;
            break;
        }
        r16[dx] = 0x0003;
        if (r16[ax] == 0x0002) {
            pc = 0x61fe;
            break;
        }
        r16[dx] = 0x0004;
    case 0x61fe:
        r16[ax] = pop();
        r16[cx] = 0x0004;
        yield* sub_6908();
        r16[ax] = memory16get(ds, 0x4f92);
        if (r16[ax] == 0x0000) {
            pc = 0x621d;
            break;
        }
        yield* sub_57f1();
        r16[ax] = 0x006b;
        yield* sub_5f24();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
    case 0x621d:
        si = pop();
        r16[cx] = pop();
    case 0x621f:
        return;
    case 0x6220:
        r16[ax] = pop();
        push(r16[cx]);
        r16[bx] = 0x3cde;
        r16[cx] = 0x0008;
    case 0x6228:
        if (r16[ax] != memory16get(ds, r16[bx] + 8)) {
            pc = 0x6236;
            break;
        }
        memory16set(ds, r16[bx] + 6, 0x0004);
        pc = 0x623b;
        break;
    case 0x6236:
        r16[bx] += 0x0016;
        if (--r16[cx]) {
            pc = 0x6228;
            break;
        }
    case 0x623b:
        r16[cx] = pop();
        return;
    case 0x623d:
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x6272;
            break;
        }
        if (memory16get(ds, 0x4f6e) != 0x0002) {
            pc = 0x6272;
            break;
        }
        if (memory[ds*16 + 0x4f94] != 0x00) {
            pc = 0x6272;
            break;
        }
        push(r16[cx]);
        push(r16[ax]);
        push(si);
        yield* sub_71c6();
        push(r16[ax]);
        r8[dl] = 0x6f;
        yield* sub_57b4();
        r16[ax] = pop();
        yield* sub_57f1();
        r16[ax] = 0x009a;
        yield* sub_5f24();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        si = pop();
        r16[ax] = pop();
        r16[cx] = pop();
    case 0x6272:
        memory16set(ds, 0x4f6e, memory16get(ds, 0x4f6e) - 1);
        r16[dx] = r16[ax];
        r16[ax] = pop();
        if (r16[ax] != memory16get(ds, 0x4f92)) {
            pc = 0x6285;
            break;
        }
        memory16set(ds, 0x4f92, 0x0000);
    case 0x6285:
        push(r16[cx]);
        r16[cx] = 0x0008;
        r16[bx] = 0x3d8e;
    case 0x628c:
        if (memory16get(ds, r16[bx]) == 0xffff) {
            pc = 0x629a;
            break;
        }
        r16[bx] += 0x000a;
        if (--r16[cx]) {
            pc = 0x628c;
            break;
        }
        r16[cx] = pop();
        return;
    case 0x629a:
        r8[dh] = 0x00;
        r16[dx] -= 0x0041;
        memory16set(ds, r16[bx] + 8, r16[dx]);
        push(r16[dx]);
        push(r16[ax]);
        yield* sub_57f1();
        r16[ax] = pop();
        r16[dx] = pop();
        memory16set(ds, r16[bx], di);
        memory16set(ds, r16[bx] + 4, 0x0500);
        memory16set(ds, r16[bx] + 6, r16[ax]);
        r16[dx] += r16[dx];
        r16[dx] += r16[dx];
        di = 0x3a80;
        di += r16[dx];
        r16[dx] = memory16get(ds, di + 2);
        memory16set(ds, r16[bx] + 2, r16[dx]);
        r8[dl] = 0x56;
        yield* sub_57b4();
        r16[cx] = pop();
        return;
    case 0x62d0:
        r16[ax] = pop();
        push(r16[cx]);
        r16[bx] = 0x3dfe;
        if (memory16get(ds, r16[bx]) == 0xffff) {
            pc = 0x62f2;
            break;
        }
        r16[bx] += 0x001a;
        if (memory16get(ds, r16[bx]) == 0xffff) {
            pc = 0x62f2;
            break;
        }
        r16[bx] += 0x001a;
        if (memory16get(ds, r16[bx]) == 0xffff) {
            pc = 0x62f2;
            break;
        }
        r16[cx] = pop();
        return;
    case 0x62f2:
        memory16set(ds, r16[bx] + 8, r16[ax]);
        yield* sub_57d2();
        r16[dx] -= 0x000e;
        r16[cx] -= 0x0013;
        memory16set(ds, r16[bx], r16[dx]);
        memory16set(ds, r16[bx] + 2, r16[cx]);
        memory16set(ds, r16[bx] + 4, 0x3a60);
        memory16set(ds, r16[bx] + 6, 0x0000);
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_6315() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x3dfe;
        r16[cx] = 0x0003;
    case 0x631b:
        push(r16[cx]);
        push(si);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x6364;
            break;
        }
        r16[ax] = memory16get(ds, 0x001e);
        memory16set(ds, si + 6, memory16get(ds, si + 6) + r16[ax]);
        if (memory16get(ds, si + 6) < 0x0008) {
            pc = 0x633d;
            break;
        }
        memory16set(ds, si + 6, 0x0000);
        memory16set(ds, si + 4, memory16get(ds, si + 4) + 0x0004);
    case 0x633d:
        r16[bx] = memory16get(ds, si + 4);
        r16[ax] = memory16get(ds, r16[bx]);
        if (r16[ax] == 0xffff) {
            pc = 0x636c;
            break;
        }
        memory16set(ds, si + 10, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 12, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        si += 0x000a;
        yield* sub_2782();
    case 0x6364:
        si = pop();
        si += 0x001a;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x631b;
            break;
        }
        return;
    case 0x636c:
        memory16set(ds, si, 0xffff);
        r16[ax] = memory16get(ds, si + 8);
        push(r16[ax]);
        yield* sub_57f1();
        r16[ax] = 0x0000;
        yield* sub_5f24();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        r16[ax] = pop();
        r8[dl] = 0x2e;
        yield* sub_57b4();
        pc = 0x6364;
        break;
        return;
    } while (1);
}
function* sub_638f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x3a4c, 0x7fff);
        r16[ax] = 0x3e54;
        memory16set(ds, 0x3a52, r16[ax]);
        si = 0x3cde;
        r16[cx] = 0x0008;
    case 0x63a1:
        push(r16[cx]);
        r16[ax] = memory16get(ds, si);
        if (r16[ax] != 0xffff) {
            pc = 0x63ae;
            break;
        }
        pc = 0x6435;
        break;
    case 0x63ae:
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x63dc;
            break;
        }
        r16[dx] = memory16get(ds, 0x3c74);
        r16[dx] &= 0x0004;
        if (r16[dx] == 0x0000) {
            pc = 0x63dc;
            break;
        }
        r16[dx] = memory16get(ds, si + 20);
        if (r16[dx] > memory16get(ds, 0x3a4c)) {
            pc = 0x63dc;
            break;
        }
        memory16set(ds, 0x3a4c, r16[dx]);
        memory16set(ds, 0x3a4a, si);
        pc = 0x63dc;
        break;
    case 0x63d6:
        pc = 0x647c;
        break;
    case 0x63d9:
        pc = 0x64ee;
        break;
    case 0x63dc:
        r16[dx] = memory16get(ds, 0x001e);
        memory16set(ds, si + 6, memory16get(ds, si + 6) - r16[dx]);
        if (memory16gets(ds, si + 6) < 0) {
            pc = 0x63d6;
            break;
        }
        if (memory16gets(ds, si + 2) < 0) {
            pc = 0x63d9;
            break;
        }
        memory16set(ds, si + 4, memory16get(ds, si + 4) + r16[dx]);
        if (memory16get(ds, si + 4) < 0x000f) {
            pc = 0x640c;
            break;
        }
        memory16set(ds, si + 4, 0x0000);
        memory16set(ds, si + 2, memory16get(ds, si + 2) + 1);
        memory16set(ds, si + 2, memory16get(ds, si + 2) & 0x0003);
    case 0x640c:
        push(si);
        r16[bx] = 0x3b7a;
        r16[ax] = memory16get(ds, si + 2);
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x6426;
            break;
        }
        r16[ax] += 0x0084;
    case 0x6426:
        r16[ax] += 0x0009;
        di = memory16get(ds, si);
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        si = pop();
    case 0x6435:
        r16[cx] = pop();
        si += 0x0016;
        if (--r16[cx]) {
            pc = 0x6479;
            break;
        }
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x6478;
            break;
        }
        if (memory16get(ds, 0x3a4c) == 0x7fff) {
            pc = 0x6478;
            break;
        }
        memory16set(ds, 0x3a4c, 0x7fff);
        r16[dx] = memory16get(ds, 0x3c74);
        r16[dx] &= 0x0004;
        if (r16[dx] == 0x0000) {
            pc = 0x6478;
            break;
        }
        r16[dx] = memory16get(ds, 0x3c78);
        r16[dx] &= 0x0020;
        if (r16[dx] == 0x0000) {
            pc = 0x6478;
            break;
        }
        si = memory16get(ds, 0x3a4a);
        memory16set(ds, si + 6, 0xffff);
        memory16set(ds, si + 20, 0x7fff);
    case 0x6478:
        return;
    case 0x6479:
        pc = 0x63a1;
        break;
    case 0x647c:
        memory16set(ds, si + 4, 0x0000);
        memory16set(ds, si + 2, 0xffff);
        memory16set(ds, si + 6, 0x7fff);
        r16[ax] = memory16get(ds, si + 18);
        r16[ax] += r16[ax];
        r16[bx] = 0x3f9e;
        r16[bx] += r16[ax];
        r16[bx] = memory16get(ds, r16[bx]);
        memory16set(ds, r16[bx] + 14, memory16get(ds, r16[bx] + 14) - 1);
        r16[ax] = memory16get(ds, si + 8);
        r8[dl] = 0x2d;
        yield* sub_57b4();
        r16[ax] = memory16get(ds, si + 8);
        push(r16[ax]);
        r16[dx] = 0x0001;
        yield* sub_614e();
        r16[ax] = pop();
        memory16set(ds, si + 16, r16[cx]);
        push(r16[ax]);
        r16[dx] = 0x0100;
        yield* sub_614e();
        r16[ax] = pop();
        memory16set(ds, si + 12, r16[cx]);
        push(r16[ax]);
        r16[dx] = 0x00ff;
        yield* sub_614e();
        r16[ax] = pop();
        memory16set(ds, si + 14, r16[cx]);
        push(r16[ax]);
        r16[dx] = 0xff00;
        yield* sub_614e();
        r16[ax] = pop();
        memory16set(ds, si + 10, r16[cx]);
        push(r16[ax]);
        push(si);
        r16[ax] = 0x0004;
        yield* sub_8ca1();
        si = pop();
        r16[ax] = pop();
        pc = 0x6435;
        break;
    case 0x64eb:
        pc = 0x65b4;
        break;
    case 0x64ee:
        r16[dx] = memory16get(ds, 0x001e);
        r16[dx] = 0x0006;
        memory16set(ds, si + 4, memory16get(ds, si + 4) + r16[dx]);
        if (memory16get(ds, si + 4) < 0x0005) {
            pc = 0x6511;
            break;
        }
        memory16set(ds, si + 4, 0x0000);
        memory16set(ds, si + 2, memory16get(ds, si + 2) - 1);
        if (memory16get(ds, si + 2) < 0xfff5) {
            pc = 0x64eb;
            break;
        }
    case 0x6511:
        push(si);
        r16[bx] = 0x3b82;
        r16[ax] = memory16get(ds, si + 2);
        r16[ax] = -r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        r16[ax] += 0x0034;
        di = memory16get(ds, si);
        yield* sub_4ffe();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        si = pop();
        r16[ax] = memory16get(ds, si + 8);
        r16[dx] = 0x0001;
        r16[cx] = memory16get(ds, si + 16);
        yield* sub_68e8();
        di = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 16);
        r16[dx] = 0x0004;
        r16[ax] = 0x0090;
        yield* sub_65c6();
        r16[ax] = memory16get(ds, si + 8);
        r16[dx] = 0x0100;
        r16[cx] = memory16get(ds, si + 12);
        yield* sub_68e8();
        di = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 12);
        r16[dx] = 0x0800;
        r16[ax] = 0x0030;
        yield* sub_65c6();
        r16[ax] = memory16get(ds, si + 8);
        r16[dx] = 0xff00;
        r16[cx] = memory16get(ds, si + 10);
        yield* sub_68e8();
        di = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 10);
        r16[dx] = 0xf800;
        r16[ax] = 0x0000;
        yield* sub_65c6();
        r16[ax] = memory16get(ds, si + 8);
        r16[dx] = 0x00ff;
        r16[cx] = memory16get(ds, si + 14);
        yield* sub_68e8();
        di = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 14);
        r16[dx] = 0xfffc;
        r16[ax] = 0x0060;
        yield* sub_65c6();
        pc = 0x6435;
        break;
    case 0x65b4:
        memory16set(ds, si, 0xffff);
        r16[ax] = memory16get(ds, si + 8);
        r8[dl] = 0x2e;
        yield* sub_57b4();
        pc = 0x6435;
        break;
        return;
    } while (1);
}
function* sub_65c6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) != 0x0002) {
            pc = 0x65e5;
            break;
        }
        r16[bx] = r16[dx];
        r16[bx] &= 0x0007;
        if (r16[bx] == 0x0004) {
            pc = 0x65e5;
            break;
        }
        if (r16[dx] != 0x0800) {
            pc = 0x65e2;
            break;
        }
        r16[dx] = 0x0400;
        pc = 0x65e5;
        break;
    case 0x65e2:
        r16[dx] = 0xfc00;
    case 0x65e5:
        r16[bx] = 0x3b9e;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, si + 2);
        r16[ax] = -r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        push(r16[cx]);
        if (r16s[cx] >= 0) {
            pc = 0x65ff;
            break;
        }
        r16[cx] = -r16[cx];
        r16[cx]--;
    case 0x65ff:
        r16[ax] = memory16get(ds, r16[bx]);
        push(r16[bx]);
        if (r16[cx] == 0x0000) {
            pc = 0x6621;
            break;
        }
    case 0x6609:
        push(r16[cx]);
        push(si);
        di += r16[dx];
        di &= 0xffff;
        push(di);
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_4ffe();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        r16[dx] = pop();
        r16[ax] = pop();
        di = pop();
        si = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x6609;
            break;
        }
    case 0x6621:
        r16[bx] = pop();
        r16[cx] = pop();
        if (r16s[cx] >= 0)
            return;
        push(si);
        di += r16[dx];
        di &= 0xffff;
        push(di);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        yield* sub_4ffe();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        di = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_663d() {
    if (memory16gets(ds, si + 10) < 0)
        return;
    memory16set(ds, si + 10, memory16get(ds, si + 10) + 0x0001);
    if (memory16get(ds, si + 10) < 0x000a)
        return;
    memory16set(ds, si + 10, 0x0000);
    memory16set(ds, si + 8, memory16get(ds, si + 8) + 1);
    memory16set(ds, si + 8, memory16get(ds, si + 8) & 0x0003);
}
function* sub_6660() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x3a54);
        memory16set(ds, si + 4, memory16get(ds, si + 4) + r16[bx]);
        r8[cl] = memory[ds*16 + si + 5];
        r8[ch] = 0x00;
        memory[ds*16 + si + 5] = 0x00;
    case 0x6673:
        push(r16[cx]);
        yield* sub_5f43();
        yield* sub_670c();
        yield* sub_663d();
        yield* sub_5fd7();
        if (r16[dx] != 0x0000) {
            pc = 0x6689;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x6673;
            break;
        }
        return;
    case 0x6689:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_668b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x3a54);
        memory16set(ds, si + 4, memory16get(ds, si + 4) + r16[bx]);
        r8[cl] = memory[ds*16 + si + 5];
        r8[ch] = 0x00;
        memory[ds*16 + si + 5] = 0x00;
    case 0x669e:
        push(r16[cx]);
        yield* sub_5f43();
        yield* sub_67c2();
        yield* sub_663d();
        yield* sub_5fd7();
        if (r16[dx] != 0x0000) {
            pc = 0x66b4;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x669e;
            break;
        }
        return;
    case 0x66b4:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_66b6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x3a54);
        memory16set(ds, si + 6, memory16get(ds, si + 6) + r16[bx]);
        r8[cl] = memory[ds*16 + si + 7];
        r8[ch] = 0x00;
        memory[ds*16 + si + 7] = 0x00;
    case 0x66c9:
        push(r16[cx]);
        yield* sub_5f43();
        yield* sub_681d();
        yield* sub_663d();
        yield* sub_5fd7();
        if (r16[dx] != 0x0000) {
            pc = 0x66df;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x66c9;
            break;
        }
        return;
    case 0x66df:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_66e1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x3a54);
        memory16set(ds, si + 6, memory16get(ds, si + 6) + r16[bx]);
        r8[cl] = memory[ds*16 + si + 7];
        r8[ch] = 0x00;
        memory[ds*16 + si + 7] = 0x00;
    case 0x66f4:
        push(r16[cx]);
        yield* sub_5f43();
        yield* sub_6767();
        yield* sub_663d();
        yield* sub_5fd7();
        if (r16[dx] != 0x0000) {
            pc = 0x670a;
            break;
        }
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x66f4;
            break;
        }
        return;
    case 0x670a:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_670c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x3a58);
        if (r16[ax] != 0x0000) {
            pc = 0x671e;
            break;
        }
        r8[al] = memory[ds*16 + 0x3f97];
        yield* sub_6878();
        if (r8[al] != 0x2e) {
            pc = 0x6736;
            break;
        }
    case 0x671e:
        r16[ax] = memory16get(ds, 0x3a5a);
        if (r16[ax] == 0x0000) {
            pc = 0x6762;
            break;
        }
        if (r16s[ax] >= 0) {
            pc = 0x672f;
            break;
        }
        memory16set(ds, si + 2, memory16get(ds, si + 2) + 1);
        pc = 0x6762;
        break;
    case 0x672f:
        memory16set(ds, si + 2, memory16get(ds, si + 2) - 1);
        pc = 0x6762;
        break;
    case 0x6736:
        r16[ax] = memory16get(ds, 0x3a5a);
        if (r16[ax] == 0x0000)
            return;
        if (r16s[ax] >= 0) {
            pc = 0x6751;
            break;
        }
        r8[al] = memory[ds*16 + 0x3f96];
        yield* sub_6878();
        if (r8[al] != 0x2e)
            return;
        memory16set(ds, si + 2, memory16get(ds, si + 2) - 1);
        return;
    case 0x6751:
        r8[al] = memory[ds*16 + 0x3f98];
        yield* sub_6878();
        if (r8[al] != 0x2e)
            return;
        memory16set(ds, si + 2, memory16get(ds, si + 2) + 1);
        return;
    case 0x6762:
        memory16set(ds, si, memory16get(ds, si) + 1);
        return;
    } while (1);
}
function* sub_6767() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x3a5a);
        if (r16[ax] != 0x0000) {
            pc = 0x6779;
            break;
        }
        r8[al] = memory[ds*16 + 0x3f99];
        yield* sub_6878();
        if (r8[al] != 0x2e) {
            pc = 0x6791;
            break;
        }
    case 0x6779:
        r16[ax] = memory16get(ds, 0x3a58);
        if (r16[ax] == 0x0000) {
            pc = 0x67bd;
            break;
        }
        if (r16s[ax] >= 0) {
            pc = 0x678a;
            break;
        }
        memory16set(ds, si, memory16get(ds, si) + 1);
        pc = 0x67bd;
        break;
    case 0x678a:
        memory16set(ds, si, memory16get(ds, si) - 1);
        pc = 0x67bd;
        break;
    case 0x6791:
        r16[ax] = memory16get(ds, 0x3a58);
        if (r16[ax] == 0x0000)
            return;
        if (r16s[ax] >= 0) {
            pc = 0x67ac;
            break;
        }
        r8[al] = memory[ds*16 + 0x3f9a];
        yield* sub_6878();
        if (r8[al] != 0x2e)
            return;
        memory16set(ds, si, memory16get(ds, si) - 1);
        return;
    case 0x67ac:
        r8[al] = memory[ds*16 + 0x3f98];
        yield* sub_6878();
        if (r8[al] != 0x2e)
            return;
        memory16set(ds, si, memory16get(ds, si) + 1);
        return;
    case 0x67bd:
        memory16set(ds, si + 2, memory16get(ds, si + 2) + 1);
        return;
    } while (1);
}
function* sub_67c2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x3a58);
        if (r16[ax] != 0x0000) {
            pc = 0x67d4;
            break;
        }
        r8[al] = memory[ds*16 + 0x3f9b];
        yield* sub_6878();
        if (r8[al] != 0x2e) {
            pc = 0x67ec;
            break;
        }
    case 0x67d4:
        r16[ax] = memory16get(ds, 0x3a5a);
        if (r16[ax] == 0x0000) {
            pc = 0x6818;
            break;
        }
        if (r16s[ax] >= 0) {
            pc = 0x67e5;
            break;
        }
        memory16set(ds, si + 2, memory16get(ds, si + 2) + 1);
        pc = 0x6818;
        break;
    case 0x67e5:
        memory16set(ds, si + 2, memory16get(ds, si + 2) - 1);
        pc = 0x6818;
        break;
    case 0x67ec:
        r16[ax] = memory16get(ds, 0x3a5a);
        if (r16[ax] == 0x0000)
            return;
        if (r16s[ax] >= 0) {
            pc = 0x6807;
            break;
        }
        r8[al] = memory[ds*16 + 0x3f94];
        yield* sub_6878();
        if (r8[al] != 0x2e)
            return;
        memory16set(ds, si + 2, memory16get(ds, si + 2) - 1);
        return;
    case 0x6807:
        r8[al] = memory[ds*16 + 0x3f9a];
        yield* sub_6878();
        if (r8[al] != 0x2e)
            return;
        memory16set(ds, si + 2, memory16get(ds, si + 2) + 1);
        return;
    case 0x6818:
        memory16set(ds, si, memory16get(ds, si) - 1);
        return;
    } while (1);
}
function* sub_681d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x3a5a);
        if (r16[ax] != 0x0000) {
            pc = 0x682f;
            break;
        }
        r8[al] = memory[ds*16 + 0x3f95];
        yield* sub_6878();
        if (r8[al] != 0x2e) {
            pc = 0x6847;
            break;
        }
    case 0x682f:
        r16[ax] = memory16get(ds, 0x3a58);
        if (r16[ax] == 0x0000) {
            pc = 0x6873;
            break;
        }
        if (r16s[ax] >= 0) {
            pc = 0x6840;
            break;
        }
        memory16set(ds, si, memory16get(ds, si) + 1);
        pc = 0x6873;
        break;
    case 0x6840:
        memory16set(ds, si, memory16get(ds, si) - 1);
        pc = 0x6873;
        break;
    case 0x6847:
        r16[ax] = memory16get(ds, 0x3a58);
        if (r16[ax] == 0x0000)
            return;
        if (r16s[ax] >= 0) {
            pc = 0x6862;
            break;
        }
        r8[al] = memory[ds*16 + 0x3f94];
        yield* sub_6878();
        if (r8[al] != 0x2e)
            return;
        memory16set(ds, si, memory16get(ds, si) - 1);
        return;
    case 0x6862:
        r8[al] = memory[ds*16 + 0x3f96];
        yield* sub_6878();
        if (r8[al] != 0x2e)
            return;
        memory16set(ds, si, memory16get(ds, si) + 1);
        return;
    case 0x6873:
        memory16set(ds, si + 2, memory16get(ds, si + 2) - 1);
        return;
    } while (1);
}
function* sub_6878() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x68aa;
            break;
        }
        r16[dx] = memory16get(ds, si + 22);
        r16[dx] &= 0x0001;
        if (r16[dx] == 0x0000) {
            pc = 0x689a;
            break;
        }
        if (r8[al] == 0x45) {
            pc = 0x68b6;
            break;
        }
        if (r8[al] < 0x41) {
            pc = 0x689a;
            break;
        }
        if (r8[al] > 0x56) {
            pc = 0x689a;
            break;
        }
        pc = 0x68b6;
        break;
    case 0x689a:
        r16[dx] = memory16get(ds, si + 22);
        r16[dx] &= 0x0002;
        if (r16[dx] == 0x0000) {
            pc = 0x68aa;
            break;
        }
        if (r8[al] == 0x2b) {
            pc = 0x68b6;
            break;
        }
    case 0x68aa:
        if (r8[al] == 0x2d) {
            pc = 0x68b6;
            break;
        }
        if (r8[al] < 0x61)
            return;
        if (r8[al] > 0x75)
            return;
    case 0x68b6:
        r8[al] = 0x2e;
        return;
    } while (1);
}
function* sub_68ba() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x3a56);
        r16[ax] += memory16get(ds, 0x001e);
        if (r16[ax] < 0x0014) {
            pc = 0x68e4;
            break;
        }
        r16[ax] = 0x0000;
        si = 0x3fa6;
        memory[ds*16 + 0x3a5c] = ~memory[ds*16 + 0x3a5c];
        if (memory[ds*16 + 0x3a5c] != 0x00) {
            pc = 0x68da;
            break;
        }
        si = 0x3fa9;
    case 0x68da:
        push(r16[ax]);
        r8[al] = 0x20;
        r16[cx] = 0x0001;
        yield* sub_2397();
        r16[ax] = pop();
    case 0x68e4:
        memory16set(ds, 0x3a56, r16[ax]);
        return;
    } while (1);
}
function* sub_68e8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16s[cx] >= 0) {
            pc = 0x68ef;
            break;
        }
        r16[cx] = -r16[cx];
    case 0x68ef:
        r16[cx]++;
        push(si);
        si = memory16get(ds, 0x3a52);
    case 0x68f5:
        memory16set(ds, si, r16[ax]);
        si += 0x0002;
        r8[al] += r8[dl];
        r8[ah] += r8[dh];
        if (--r16[cx]) {
            pc = 0x68f5;
            break;
        }
        memory16set(ds, 0x3a52, si);
        si = pop();
        return;
    } while (1);
}
function* sub_6908() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x6908:
        push(r16[cx]);
        push(r16[ax]);
        push(r16[dx]);
        si = 0x4d50;
        r16[cx] = 0x000f;
    case 0x6911:
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x6920;
            break;
        }
        si += 0x0024;
        if (--r16[cx]) {
            pc = 0x6911;
            break;
        }
        pc = 0x6976;
        break;
    case 0x6920:
        push(r16[dx]);
        yield* sub_57d2();
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0008;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 10, 0xffe7);
        r16[ax] = pop();
        memory16set(ds, si + 12, r16[ax]);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        di = 0x42d4;
        di += r16[ax];
        r16[ax] = memory16get(ds, di);
        memory16set(ds, si + 4, r16[ax]);
        memory16set(ds, si + 6, r16[ax]);
        r16[ax] = memory16get(ds, di + 4);
        memory16set(ds, si + 8, r16[ax]);
        r16[ax] = memory16get(ds, di + 6);
        memory16set(ds, si + 14, r16[ax]);
        memory16set(ds, si + 18, 0x0000);
        memory16set(ds, si + 16, 0x0000);
        memory16set(ds, 0x4200, memory16get(ds, 0x4200) + 1);
    case 0x6976:
        r16[dx] = pop();
        r16[ax] = pop();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x6908;
            break;
        }
        return;
    } while (1);
}
function* sub_697c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x4d50;
        r16[cx] = 0x000f;
    case 0x6982:
        memory16set(ds, si, 0xffff);
        memory16set(ds, si + 24, 0x0004);
        memory16set(ds, si + 26, 0x0012);
        si += 0x0024;
        if (--r16[cx]) {
            pc = 0x6982;
            break;
        }
        return;
    } while (1);
}
function* sub_699a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_697c();
        si = 0x4d50;
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x69b0;
            break;
        }
        r16[bx] = memory16get(ds, 0x4f78);
        r16[bx] += 0x0008;
        pc = 0x69c1;
        break;
    case 0x69b0:
        r16[bx] = 0x42b4;
        r16[ax] = memory16get(ds, 0x0010);
        r16[ax] -= 0x0002;
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[bx] = memory16get(ds, r16[bx]);
    case 0x69c1:
        r16[cx] = memory16get(ds, r16[bx]);
        if (r16s[cx] < 0) {
            pc = 0x6a38;
            break;
        }
        if (r16[cx] == 0x0000) {
            pc = 0x6a38;
            break;
        }
        r16[bx] += 0x0002;
    case 0x69cf:
        push(r16[cx]);
        push(r16[bx]);
        yield* sub_71c6();
        r16[bx] = pop();
        yield* sub_57d2();
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0008;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 10, 0x0000);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 12, r16[ax]);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        di = 0x42d4;
        di += r16[ax];
        r16[ax] = memory16get(ds, di);
        memory16set(ds, si + 4, r16[ax]);
        memory16set(ds, si + 6, r16[ax]);
        r16[ax] = memory16get(ds, di + 4);
        memory16set(ds, si + 8, r16[ax]);
        r16[ax] = memory16get(ds, di + 6);
        memory16set(ds, si + 14, r16[ax]);
        memory16set(ds, si + 18, 0x0000);
        memory16set(ds, si + 16, 0x0000);
        memory16set(ds, 0x4200, memory16get(ds, 0x4200) + 1);
        r16[cx] = pop();
        si += 0x0024;
        if (--r16[cx]) {
            pc = 0x69cf;
            break;
        }
        r16[bx] += 0x0002;
        pc = 0x69c1;
        break;
    case 0x6a38:
        if (memory16get(ds, 0x4f8a) != 0x0008)
            return;
        yield* sub_7912();
        return;
    } while (1);
}
function* sub_6a43() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x4202, 0x0000);
        si = 0x4d50;
        r16[cx] = 0x000f;
    case 0x6a4f:
        push(r16[cx]);
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x6a5a;
            break;
        }
        pc = 0x6b1a;
        break;
    case 0x6a5a:
        if (memory16gets(ds, si + 12) >= 0) {
            pc = 0x6a64;
            break;
        }
        pc = 0x6b2e;
        break;
    case 0x6a64:
        r16[ax] = 0x0100;
        r16[cx] = memory16get(ds, si + 14);
        r16[dx] = r16[cx];
        r16[dx] &= 0x0004;
        if (r16[dx] == 0x0000) {
            pc = 0x6a85;
            break;
        }
        r16[ax] = 0x0200;
        r16[dx] = r16[cx];
        r16[cx] &= 0x000c;
        if (r16[cx] != 0x000c) {
            pc = 0x6a85;
            break;
        }
        r16[ax] = 0x0300;
    case 0x6a85:
        memory16set(ds, si + 16, memory16get(ds, si + 16) + r16[ax]);
        r8[cl] = memory[ds*16 + si + 17];
        r8[ch] = 0x00;
        memory[ds*16 + si + 17] = 0x00;
    case 0x6a94:
        push(r16[cx]);
        yield* sub_6c50();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x6a94;
            break;
        }
        r16[bx] = memory16get(ds, si + 6);
        r16[dx] = memory16get(ds, 0x001e);
        r16[ax] = memory16get(ds, si + 8);
        r8[ah] += r8[dl];
        if (r8[ah] < r8[al]) {
            pc = 0x6ac5;
            break;
        }
        r8[ah] = 0x00;
        r16[bx] += 0x0010;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x6ac5;
            break;
        }
        r16[bx] = memory16get(ds, si + 4);
        memory16set(ds, si + 6, r16[bx]);
    case 0x6ac5:
        memory16set(ds, si + 8, r16[ax]);
        push(si);
        r16[ax] = memory16get(ds, si + 10);
        if (r16s[ax] < 0) {
            pc = 0x6adc;
            break;
        }
        r16[ax] &= 0x0003;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
    case 0x6adc:
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 20, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 22, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0002;
        if (memory16get(ds, si + 12) != 0x0017) {
            pc = 0x6b01;
            break;
        }
        r16[cx] -= 0x0004;
    case 0x6b01:
        yield* sub_703a();
        if (r16[ax] != 0x0000) {
            pc = 0x6b0f;
            break;
        }
        si += 0x0014;
        yield* sub_2782();
    case 0x6b0f:
        si = pop();
        if (memory16get(ds, si + 12) == 0x0017) {
            pc = 0x6b1a;
            break;
        }
        yield* sub_6bda();
    case 0x6b1a:
        r16[cx] = pop();
        si += 0x0024;
        if (--r16[cx]) {
            pc = 0x6b2b;
            break;
        }
        if (memory16get(ds, 0x4f8a) != 0x0008) {
            pc = 0x6b2a;
            break;
        }
        yield* sub_7d6b();
    case 0x6b2a:
        return;
    case 0x6b2b:
        pc = 0x6a4f;
        break;
    case 0x6b2e:
        r16[bx] = memory16get(ds, si + 6);
        r16[ax] = memory16get(ds, 0x001e);
        memory16set(ds, si + 8, memory16get(ds, si + 8) + r16[ax]);
        if (memory16get(ds, si + 8) < 0x0078) {
            pc = 0x6b93;
            break;
        }
        memory16set(ds, si + 8, 0x0064);
        r16[bx] += 0x0004;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x6b93;
            break;
        }
        if (memory16get(ds, si + 10) == 0xffff) {
            pc = 0x6b8b;
            break;
        }
        r16[ax] = memory16get(ds, si + 10);
        r16[bx] = 0x422e;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, 0x3a50, memory16get(ds, 0x3a50) + r16[ax]);
        r16[bx] = memory16get(ds, r16[bx] + 2);
        if (r16[bx] == 0x0000) {
            pc = 0x6b8b;
            break;
        }
        memory16set(ds, si + 10, 0xffff);
        memory16set(ds, si + 8, 0x0000);
        memory16set(ds, si + 6, r16[bx]);
        pc = 0x6b93;
        break;
    case 0x6b8b:
        memory16set(ds, si, 0xffff);
        pc = 0x6b1a;
        break;
    case 0x6b93:
        push(si);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 20, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 22, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0002;
        si += 0x0014;
        yield* sub_2782();
        si = pop();
        pc = 0x6b1a;
        break;
        return;
    } while (1);
}
function* sub_6bb9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        r16[bx] = 0x3e54;
    case 0x6bbd:
        r16[dx] = memory16get(ds, r16[bx]);
        r16[bx] += 0x0002;
        if (r16[bx] > memory16get(ds, 0x3a52)) {
            pc = 0x6bd0;
            break;
        }
        if (r16[dx] == r16[ax]) {
            pc = 0x6bd5;
            break;
        }
        pc = 0x6bbd;
        break;
    case 0x6bd0:
        r16[dx] = 0x0000;
        r16[bx] = pop();
        return;
    case 0x6bd5:
        r16[dx] = 0xffff;
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_6bda() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[dx] += 0x0008;
        r16[cx] += 0x0008;
        yield* sub_581f();
        yield* sub_6bb9();
        if (r16[dx] == 0xffff) {
            pc = 0x6bf4;
            break;
        }
        return;
    case 0x6bf4:
        r16[bx] = 0x42d6;
        r16[ax] = memory16get(ds, si + 12);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 6, r16[ax]);
        r16[ax] = memory16get(ds, si + 12);
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[bx] = 0x42d4;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 8);
        if (r16[ax] == 0x0000) {
            pc = 0x6c27;
            break;
        }
        r16[ax] += memory16get(ds, 0x4202);
    case 0x6c27:
        memory16set(ds, si + 10, r16[ax]);
        if (memory16get(ds, 0x4202) < 0x0006) {
            pc = 0x6c36;
            break;
        }
        memory16set(ds, 0x4202, memory16get(ds, 0x4202) - 1);
    case 0x6c36:
        memory16set(ds, 0x4202, memory16get(ds, 0x4202) + 1);
        memory16set(ds, si + 12, 0xffff);
        memory16set(ds, si + 8, 0x0050);
        memory16set(ds, 0x4200, memory16get(ds, 0x4200) - 1);
        memory[ds*16 + 0x4f94] = 0xff;
        return;
    } while (1);
}
function* sub_6c50() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16gets(ds, si + 10) < 0) {
            pc = 0x6c85;
            break;
        }
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6f24();
        if (r16[dx] == 0x0000) {
            pc = 0x6c67;
            break;
        }
        memory16set(ds, si + 10, r16[ax]);
    case 0x6c67:
        r16[ax] = memory16get(ds, si + 10);
        r16[ax] &= 0x0001;
        if (r16[ax] == 0x0000) {
            pc = 0x6c88;
            break;
        }
        r16[ax] = memory16get(ds, si);
        r16[ax] -= 0x0008;
        r16[ax] &= 0x000f;
        if (r16[ax] == 0x0000) {
            pc = 0x6c99;
            break;
        }
        pc = 0x6d17;
        break;
    case 0x6c85:
        pc = 0x6d37;
        break;
    case 0x6c88:
        r16[ax] = memory16get(ds, si + 2);
        r16[ax] -= 0x0018;
        r16[ax] &= 0x000f;
        if (r16[ax] == 0x0000) {
            pc = 0x6c99;
            break;
        }
        pc = 0x6d17;
        break;
    case 0x6c99:
        r16[cx] = memory16get(ds, si + 14);
        if (!(r16[cx] & 0x0040)) {
            pc = 0x6ca6;
            break;
        }
        yield* sub_6d4d();
    case 0x6ca6:
        r16[ax] = memory16get(ds, si + 14);
        r16[ax] &= 0x0010;
        if (r16[ax] == 0x0000) {
            pc = 0x6cc7;
            break;
        }
        if (memory16get(ds, si + 18) == 0x0000) {
            pc = 0x6cbf;
            break;
        }
        memory16set(ds, si + 18, memory16get(ds, si + 18) - 1);
        pc = 0x6cc7;
        break;
    case 0x6cbf:
        yield* sub_6d9c();
        if (r16[dx] == 0x0000) {
            pc = 0x6cf8;
            break;
        }
    case 0x6cc7:
        r16[ax] = 0x0064;
        yield* sub_587c();
        r16[dx] = memory16get(ds, si + 12);
        r8[cl] = 0x04;
        r16[dx] <<= r8[cl];
        di = 0x42d4;
        di += r16[dx];
        r16[dx] = memory16get(ds, di + 10);
        if (r16[dx] == 0x0000) {
            pc = 0x6cf8;
            break;
        }
        if (r16[dx] < r16[ax]) {
            pc = 0x6cf8;
            break;
        }
        yield* sub_6f9a();
        yield* sub_6e9c();
        memory16set(ds, si + 10, r16[ax]);
        if (r16s[ax] < 0) {
            pc = 0x6d37;
            break;
        }
        pc = 0x6d17;
        break;
    case 0x6cf8:
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x6d17;
            break;
        }
        memory16set(ds, si + 10, r16[ax]);
        yield* sub_6f9a();
        yield* sub_6e9c();
        memory16set(ds, si + 10, r16[ax]);
        if (r16s[ax] < 0) {
            pc = 0x6d37;
            break;
        }
    case 0x6d17:
        r16[ax] = memory16get(ds, si + 10);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] = 0x4444;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si, memory16get(ds, si) + r16[ax]);
        memory16set(ds, si + 2, memory16get(ds, si + 2) + r16[dx]);
    case 0x6d36:
        return;
    case 0x6d37:
        memory16set(ds, si + 10, memory16get(ds, si + 10) + 1);
        if (memory16get(ds, si + 10) != 0x0000) {
            pc = 0x6d36;
            break;
        }
        yield* sub_6f9a();
        yield* sub_6e9c();
        memory16set(ds, si + 10, r16[ax]);
        return;
    } while (1);
}
function* sub_6d4d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        r16[dx] = memory16get(ds, si + 10);
        r16[bx] = 0x4444;
        r8[cl] = 0x03;
        r16[dx] <<= r8[cl];
        r16[bx] += r16[dx];
        r16[dx] = memory16get(ds, r16[bx] + 4);
        memory16set(ds, 0x41fa, r16[ax]);
        memory16set(ds, 0x41fc, r16[dx]);
    case 0x6d70:
        r16[ax] = memory16get(ds, 0x41fa);
        r16[dx] = memory16get(ds, 0x41fc);
        r8[al] += r8[dl];
        r8[ah] += r8[dh];
        memory16set(ds, 0x41fa, r16[ax]);
        memory16set(ds, 0x41fc, r16[dx]);
        yield* sub_5832();
        if (r8[al] == 0x2b) {
            pc = 0x6d92;
            break;
        }
        if (r8[al] == 0x2d) {
            pc = 0x6d92;
            break;
        }
        if (r8[al] == 0x2e) {
            pc = 0x6d70;
            break;
        }
        return;
    case 0x6d92:
        memory16set(ds, si + 10, memory16get(ds, si + 10) + 1);
        memory16set(ds, si + 10, memory16get(ds, si + 10) & 0x0003);
        return;
    } while (1);
}
function* sub_6d9c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds, 0x3c5e);
        r16[cx] = memory16get(ds, 0x3c60);
        yield* sub_581f();
        push(r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        r16[dx] = pop();
        if (r8[al] == r8[dl]) {
            pc = 0x6e27;
            break;
        }
        if (r8[ah] == r8[dh]) {
            pc = 0x6e0e;
            break;
        }
        memory16set(ds, 0x41fa, r16[ax]);
        memory16set(ds, 0x41fc, r16[dx]);
        r8[al] -= r8[dl];
        if (r8s[al] >= 0) {
            pc = 0x6dcb;
            break;
        }
        r8[al] = -r8[al];
    case 0x6dcb:
        r8[ah] -= r8[dh];
        if (r8s[ah] >= 0) {
            pc = 0x6dd4;
            break;
        }
        r8[ah] = -r8[ah];
    case 0x6dd4:
        if (r8[al] > r8[ah]) {
            pc = 0x6e40;
            break;
        }
        r16[ax] = memory16get(ds, 0x41fa);
        r16[dx] = memory16get(ds, 0x41fc);
        yield* sub_6e89();
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x6e26;
            break;
        }
        r16[ax] = memory16get(ds, 0x41fa);
        r16[dx] = memory16get(ds, 0x41fc);
        yield* sub_6e76();
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x6e26;
            break;
        }
        memory16set(ds, si + 18, 0x0004);
        r16[dx] = 0xffff;
        return;
    case 0x6e0e:
        yield* sub_6e76();
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x6e26;
            break;
        }
        memory16set(ds, si + 18, 0x0004);
        r16[dx] = 0xffff;
    case 0x6e26:
        return;
    case 0x6e27:
        yield* sub_6e89();
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x6e26;
            break;
        }
        memory16set(ds, si + 18, 0x0004);
        r16[dx] = 0xffff;
        return;
    case 0x6e40:
        r16[ax] = memory16get(ds, 0x41fa);
        r16[dx] = memory16get(ds, 0x41fc);
        yield* sub_6e76();
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x6e26;
            break;
        }
        r16[ax] = memory16get(ds, 0x41fa);
        r16[dx] = memory16get(ds, 0x41fc);
        yield* sub_6e89();
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x6e26;
            break;
        }
        memory16set(ds, si + 18, 0x0004);
        r16[dx] = 0xffff;
        return;
    } while (1);
}
function* sub_6e76() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[al] >= r8[dl]) {
            pc = 0x6e82;
            break;
        }
        memory16set(ds, si + 10, 0x0001);
        return;
    case 0x6e82:
        memory16set(ds, si + 10, 0x0003);
        return;
    } while (1);
}
function* sub_6e89() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r8[ah] >= r8[dh]) {
            pc = 0x6e95;
            break;
        }
        memory16set(ds, si + 10, 0x0002);
        return;
    case 0x6e95:
        memory16set(ds, si + 10, 0x0000);
        return;
    } while (1);
}
function* sub_6e9c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x4d4e);
        if (r16[ax] == 0x0000) {
            pc = 0x6eba;
            break;
        }
        r16[ax]--;
        if (r16[ax] == 0x0000) {
            pc = 0x6eae;
            break;
        }
        r16[ax]++;
        yield* sub_587c();
    case 0x6eae:
        r16[ax] += r16[ax];
        r16[bx] = 0x4d3c;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        return;
    case 0x6eba:
        r16[ax] = 0xffff;
        return;
    } while (1);
}
function* sub_6ebe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16s[ax] < 0) {
            pc = 0x6f14;
            break;
        }
        push(r16[ax]);
        r16[bx] = 0x4444;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 4);
        push(r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] += 0x0008;
        r16[dx] += 0x0008;
        yield* sub_581f();
        memory16set(ds, 0x41fe, r16[ax]);
        r16[dx] = pop();
        r8[al] += r8[dl];
        r8[ah] += r8[dh];
        yield* sub_5832();
        r16[dx] = pop();
        r16[cx] = memory16get(ds, si + 14);
        if (r16[cx] & 0x0080) {
            pc = 0x6eff;
            break;
        }
        if (r8[al] == 0x2b) {
            pc = 0x6f14;
            break;
        }
    case 0x6eff:
        if (r16[cx] & 0x0001) {
            pc = 0x6f10;
            break;
        }
        if (r8[al] < 0x41) {
            pc = 0x6f10;
            break;
        }
        if (r8[al] > 0x55) {
            pc = 0x6f10;
            break;
        }
        pc = 0x6f14;
        break;
    case 0x6f10:
        if (r8[al] != 0x2a) {
            pc = 0x6f1e;
            break;
        }
    case 0x6f14:
        r16[ax] = 0x0004;
        yield* sub_587c();
        r16[dx] = 0xffff;
        return;
    case 0x6f1e:
        r16[ax] = r16[dx];
        r16[dx] = 0x0000;
        return;
    } while (1);
}
function* sub_6f24() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16s[ax] < 0) {
            pc = 0x6f56;
            break;
        }
        push(r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] += 0x0008;
        r16[dx] += 0x0008;
        yield* sub_581f();
        memory16set(ds, 0x41fe, r16[ax]);
        yield* sub_5832();
        r16[dx] = pop();
        r16[cx] = memory16get(ds, si + 14);
        if (r16[cx] & 0x0080) {
            pc = 0x6f50;
            break;
        }
        if (r8[al] == 0x2b) {
            pc = 0x6f56;
            break;
        }
    case 0x6f50:
        r16[ax] = r16[dx];
        r16[dx] = 0x0000;
        return;
    case 0x6f56:
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0018;
        r16[dx] += 0x0008;
        r16[cx] += 0x0008;
        r16[dx] &= 0x000f;
        r16[cx] &= 0x000f;
        r16[ax] = memory16get(ds, si + 10);
        if (!(r16[ax] & 0x0001)) {
            pc = 0x6f87;
            break;
        }
        r16[ax] = 0x0003;
        if (r16[dx] < 0x0008) {
            pc = 0x6f92;
            break;
        }
        r16[ax] = 0x0001;
        pc = 0x6f92;
        break;
    case 0x6f87:
        r16[ax] = 0x0000;
        if (r16[cx] < 0x0008) {
            pc = 0x6f92;
            break;
        }
        r16[ax] = 0x0002;
    case 0x6f92:
        memory16set(ds, si + 10, r16[ax]);
        r16[dx] = 0xffff;
        return;
    } while (1);
}
function* sub_6f9a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x4d3c;
        memory16set(ds, r16[bx] + 18, 0x0000);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] += 0x0008;
        r16[dx] += 0x0008;
        yield* sub_581f();
        di = 0x4444;
        r16[cx] = 0x0004;
    case 0x6fba:
        push(r16[cx]);
        push(r16[ax]);
        r16[dx] = memory16get(ds, di + 4);
        r8[ah] += r8[dh];
        r8[al] += r8[dl];
        yield* sub_5832();
        if (r8[al] == 0x2a) {
            pc = 0x6fff;
            break;
        }
        if (r8[al] == 0x2b) {
            pc = 0x6fff;
            break;
        }
        r16[cx] = memory16get(ds, si + 14);
        r16[cx] &= 0x0001;
        if (r16[cx] != 0x0000) {
            pc = 0x6fe5;
            break;
        }
        if (r8[al] < 0x41) {
            pc = 0x6fe5;
            break;
        }
        if (r8[al] > 0x55) {
            pc = 0x6fe5;
            break;
        }
        pc = 0x6fff;
        break;
    case 0x6fe5:
        r16[ax] = memory16get(ds, di + 6);
        memory16set(ds, r16[bx], r16[ax]);
        r16[bx] += 0x0002;
        memory16set(ds, 0x4d4e, memory16get(ds, 0x4d4e) + 1);
        memory16set(ds, r16[bx], r16[ax]);
        r16[bx] += 0x0002;
        memory16set(ds, 0x4d4e, memory16get(ds, 0x4d4e) + 1);
    case 0x6fff:
        r16[ax] = pop();
        r16[cx] = pop();
        di += 0x0008;
        if (--r16[cx]) {
            pc = 0x6fba;
            break;
        }
        r16[cx] = memory16get(ds, si + 14);
        if (r16[cx] & 0x0002)
            return;
        memory16set(ds, r16[bx], 0xfff8);
        memory16set(ds, 0x4d4e, memory16get(ds, 0x4d4e) + 1);
        return;
    } while (1);
}
function* sub_701b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(r16[ax]);
        r16[dx] = r16[ax];
        si = 0x4204;
    case 0x7022:
        lodsw_data_forward();
        if (r16[ax] == 0xffff) {
            pc = 0x702e;
            break;
        }
        if (r16[ax] == r16[dx]) {
            pc = 0x7034;
            break;
        }
        pc = 0x7022;
        break;
    case 0x702e:
        r16[dx] = 0x0000;
        r16[ax] = pop();
        si = pop();
        return;
    case 0x7034:
        r16[dx] = 0xffff;
        r16[ax] = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_703a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x26f2) == 0x0000) {
            pc = 0x7065;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x7069;
            break;
        }
        r16[ax] = memory16get(ds, 0x203e);
        r16[bx] = memory16get(ds, si);
        r16[bx] += 0x0010;
        r16[ax] -= 0x0080;
        if (r16[ax] > r16[bx]) {
            pc = 0x7087;
            break;
        }
        r16[ax] = memory16get(ds, 0x203e);
        r16[ax] += 0x0080;
        if (r16[ax] < memory16get(ds, si)) {
            pc = 0x7087;
            break;
        }
    case 0x7065:
        r16[ax] = 0x0000;
        return;
    case 0x7069:
        r16[ax] = memory16get(ds, 0x203e);
        r16[bx] = memory16get(ds, si + 2);
        r16[ax] -= 0x007c;
        if (r16[ax] > r16[bx]) {
            pc = 0x7087;
            break;
        }
        r16[ax] = memory16get(ds, 0x203e);
        r16[ax] += 0x006c;
        if (r16[ax] < memory16get(ds, si + 2)) {
            pc = 0x7087;
            break;
        }
        r16[ax] = 0x0000;
        return;
    case 0x7087:
        r16[ax] = 0xffff;
        return;
    } while (1);
}
function* sub_708b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x3c5e;
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x70cb;
            break;
        }
        if (memory16gets(ds, si + 8) < 0) {
            pc = 0x70cb;
            break;
        }
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x70b1;
            break;
        }
        r16[dx] = memory16get(ds, si + 22);
        r16[dx] &= 0x0008;
        if (r16[dx] == 0x0000) {
            pc = 0x70b1;
            break;
        }
        pc = 0x70b4;
        break;
    case 0x70b1:
        yield* sub_7165();
    case 0x70b4:
        yield* sub_7111();
        if (memory16get(ds, 0x4f88) == 0x0000) {
            pc = 0x70cb;
            break;
        }
        if (memory16gets(ds, si + 8) >= 0) {
            pc = 0x70cb;
            break;
        }
        r16[ax] = 0x0005;
        yield* sub_8c10();
    case 0x70cb:
        si = 0x3c7e;
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x70e2;
            break;
        }
        if (memory16gets(ds, si + 8) < 0) {
            pc = 0x70e2;
            break;
        }
        yield* sub_7165();
        yield* sub_7111();
    case 0x70e2:
        si = 0x3c9e;
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x70f9;
            break;
        }
        if (memory16gets(ds, si + 8) < 0) {
            pc = 0x70f9;
            break;
        }
        yield* sub_7165();
        yield* sub_7111();
    case 0x70f9:
        si = 0x3cbe;
        if (memory16get(ds, si) == 0xffff)
            return;
        if (memory16gets(ds, si + 8) < 0)
            return;
        yield* sub_7165();
        yield* sub_7111();
        return;
    } while (1);
}
function* sub_7111() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        r16[dx] = r16[ax];
        r16[bx] = 0x4d50;
        r16[cx] = 0x000f;
    case 0x7124:
        push(r16[cx]);
        if (memory16get(ds, r16[bx]) == 0xffff) {
            pc = 0x714a;
            break;
        }
        if (memory16gets(ds, r16[bx] + 12) < 0) {
            pc = 0x714a;
            break;
        }
        push(r16[dx]);
        r16[dx] = memory16get(ds, r16[bx]);
        r16[dx] += 0x0008;
        r16[cx] = memory16get(ds, r16[bx] + 2);
        r16[cx] += 0x0008;
        yield* sub_581f();
        r16[dx] = pop();
        if (r16[ax] == r16[dx]) {
            pc = 0x7151;
            break;
        }
    case 0x714a:
        r16[bx] += 0x0024;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x7124;
            break;
        }
        return;
    case 0x7151:
        r16[cx] = pop();
        memory16set(ds, si + 8, 0xffff);
        memory16set(ds, si + 10, 0x0000);
        r16[ax] = 0x0000;
        yield* sub_8ca1();
        return;
    } while (1);
}
function* sub_7165() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        r16[dx] = r16[ax];
        r16[bx] = 0x3e54;
    case 0x7175:
        r16[ax] = memory16get(ds, r16[bx]);
        r16[bx] += 0x0002;
        if (r16[bx] > memory16get(ds, 0x3a52)) {
            pc = 0x7188;
            break;
        }
        if (r16[dx] == r16[ax]) {
            pc = 0x7189;
            break;
        }
        pc = 0x7175;
        break;
    case 0x7188:
        return;
    case 0x7189:
        memory16set(ds, si + 8, 0xffff);
        memory16set(ds, si + 10, 0x0000);
        r16[ax] = 0x0000;
        yield* sub_8ca1();
        return;
    } while (1);
}
function* sub_71c6() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0x71c6:
        r16[ax] = memory16get(ds, 0x26f6);
        yield* sub_587c();
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x26f4);
        yield* sub_587c();
        r16[dx] = pop();
        r8[ah] = r8[dl];
        r16[bx] = r16[ax];
        yield* sub_5832();
        if (r8[al] != 0x2e) {
            pc = 0x71c6;
            break;
        }
        r16[ax] = r16[bx];
        yield* sub_701b();
        if (r16[dx] != 0x0000) {
            pc = 0x71c6;
            break;
        }
        return;
    } while (1);
}
function* sub_71ea() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x4f8e, 0x0003);
        memory16set(ds, 0x3a50, 0x0000);
        r16[ax] = 0x0005;
        yield* sub_77c8();
        memory[ds*16 + 0x4f97] = 0xff;
        r16[ax] = 0x0004;
        yield* sub_77c8();
    case 0x7208:
        if (memory16get(ds, 0x4f8a) != 0x0001) {
            pc = 0x7212;
            break;
        }
        yield* sub_4155();
    case 0x7212:
        si = 0x4fbc;
        r16[bx] = memory16get(ds, 0x4f88);
        r16[bx] += r16[bx];
        si = memory16get(ds, r16[bx] + si);
        lodsw_data_forward();
        yield* sub_77c8();
        di = 0x08de;
        push(ds);
        yield* sub_23d3();
        ds = pop();
        memory16set(ds, 0x0012, 0x0000);
        si = 0x3c5e;
        memory16set(ds, si + 22, 0x0000);
    case 0x723a:
        if (memory16get(ds, 0x4f88) != 0x0008) {
            pc = 0x725b;
            break;
        }
        if (memory16get(ds, 0x4f8a) != 0x0008) {
            pc = 0x725b;
            break;
        }
        if (memory[ds*16 + 0x4f97] == 0x00) {
            pc = 0x725b;
            break;
        }
        r16[ax] = 0x0006;
        yield* sub_77c8();
        memory[ds*16 + 0x4f97] = 0x00;
    case 0x725b:
        if (memory16get(ds, 0x4f88) != 0x0008) {
            pc = 0x726c;
            break;
        }
        if (memory16get(ds, 0x4f8a) != 0x0008) {
            pc = 0x726c;
            break;
        }
        pc = 0x727f;
        break;
    case 0x726c:
        if (memory[ds*16 + 0x4f97] != 0x00) {
            pc = 0x727f;
            break;
        }
        r16[ax] = 0x0005;
        yield* sub_77c8();
        memory[ds*16 + 0x4f97] = 0xff;
    case 0x727f:
        r16[ax] = memory16get(ds, 0x3c6a);
        memory16set(ds, 0x4f72, r16[ax]);
        r16[ax] = memory16get(ds, 0x3c70);
        memory16set(ds, 0x4f74, r16[ax]);
        r16[ax] = memory16get(ds, 0x3a54);
        memory16set(ds, 0x4f76, r16[ax]);
        si = 0x4fbc;
        r16[bx] = memory16get(ds, 0x4f88);
        r16[bx] += r16[bx];
        si = memory16get(ds, r16[bx] + si);
        si += 0x0002;
        r16[bx] = memory16get(ds, 0x4f8a);
        r16[bx] += r16[bx];
        r16[ax] = memory16get(ds, r16[bx] + si);
        memory16set(ds, 0x4f78, r16[ax]);
        yield* sub_4279();
        yield* sub_2fcb();
        yield* sub_2fdd();
        r16[ax] = 0x3e54;
        memory16set(ds, 0x3a52, r16[ax]);
        yield* sub_4f14();
        si = 0x3c5e;
        memory16set(ds, si, 0xffff);
        memory16set(ds, si + 32, 0xffff);
        memory16set(ds, si + 64, 0xffff);
        memory16set(ds, si + 96, 0xffff);
        si = 0x3c5e;
        r16[ax] = 0x0101;
        yield* sub_57d2();
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 14, 0x0000);
        memory16set(ds, si + 24, 0x0000);
        memory16set(ds, si + 26, 0x0000);
        memory16set(ds, si + 28, 0x0000);
        memory16set(ds, si + 10, 0x0000);
        memory16set(ds, si + 8, 0x0000);
        memory16set(ds, si + 22, memory16get(ds, si + 22) & 0xfff7);
        memory16set(ds, si + 20, 0x0000);
        memory[ds*16 + 0x0023] = 0xff;
        r16[ax] = 0x0004;
        memory16set(ds, 0x37ce, r16[ax]);
        r16[ax] = 0x0000;
        memory16set(ds, 0x37d0, r16[ax]);
        memory16set(ds, 0x204c, 0xffff);
        r16[ax] = memory16get(ds, 0x26f2);
        r16[ax] += r16[ax];
        si = 0x4fb6;
        si += r16[ax];
        si = memory16get(ds, si);
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0726;
        r16[cx] = 0x01b8;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        yield* sub_50e9();
        yield* sub_4f8b();
        yield* sub_76bc();
        yield* sub_2c65();
        yield* sub_2a67();
        memory16set(ds, 0x4200, 0x0000);
        yield* sub_699a();
        memory16set(ds, 0x4f6c, 0x0036);
        yield* sub_5a41();
        yield* sub_6a43();
        memory[ds*16 + 0x4f94] = 0x00;
        yield* sub_2ad4();
        yield* sub_2318();
        yield* sub_2ad4();
        yield* sub_51ff();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        r16[ax] = 0x000c;
        r16[dx] = memory16get(ds, 0x4f8a);
        if (r16[dx] & 0x0001) {
            pc = 0x73ac;
            break;
        }
        r16[ax] = 0x000d;
        if (memory16get(ds, 0x4f8a) != 0x0008) {
            pc = 0x73ac;
            break;
        }
        r16[ax] = 0x000b;
        memory[ds*16 + 0x4f94] = 0xff;
    case 0x73ac:
        yield* sub_8c10();
        memory16set(ds, 0x4f86, 0x0000);
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
        memory16set(ds, 0x4f80, 0x3039);
        memory16set(ds, 0x4f82, 0x3039);
        memory16set(ds, 0x4f7e, 0x3039);
        memory16set(ds, 0x4f84, 0x3039);
        memory16set(ds, 0x3a4e, 0x0000);
        memory16set(ds, 0x4f7a, 0x0000);
        memory16set(ds, 0x4f7c, 0x0000);
        memory[ds*16 + 0x0023] = 0x00;
        memory16set(ds, 0x204c, 0x0000);
        memory16set(ds, 0x4f6c, 0x0ca8);
        memory[ds*16 + 0x0020] = 0x00;
    case 0x7407:
        yield* sub_2bfb();
        yield* sub_281e();
        yield* sub_552a();
        yield* sub_5efa();
        yield* sub_638f();
        yield* sub_59d8();
        yield* sub_6315();
        yield* sub_7690();
        si = 0x3c5e;
        yield* sub_5dce();
        yield* sub_6a43();
        yield* sub_5a41();
        yield* sub_2fef();
        yield* sub_770c();
        yield* sub_2ad4();
        if (memory[ds*16 + 0x2050] != 0x00) {
            pc = 0x7441;
            break;
        }
        yield* sub_708b();
        pc = 0x746d;
        break;
    case 0x7441:
        r16[ax] = 0x0000;
        r8[al] = memory[ds*16 + 0x0020];
        if (r8[al] < 0x02) {
            pc = 0x7459;
            break;
        }
        if (r8[al] > 0x09) {
            pc = 0x7459;
            break;
        }
        r16[ax]--;
        memory16set(ds, 0x4f8a, r16[ax]);
        memory16set(ds, 0x4f7c, 0x0003);
    case 0x7459:
        if (r8[al] < 0x3b) {
            pc = 0x746d;
            break;
        }
        if (r8[al] > 0x42) {
            pc = 0x746d;
            break;
        }
        r16[ax] -= 0x003a;
        memory16set(ds, 0x4f88, r16[ax]);
        memory16set(ds, 0x4f7c, 0x0004);
    case 0x746d:
        if (memory16get(ds, 0x4f7c) == 0x0000) {
            pc = 0x7477;
            break;
        }
        pc = 0x74f9;
        break;
    case 0x7477:
        si = 0x3c5e;
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x7492;
            break;
        }
        memory16set(ds, 0x4f7a, memory16get(ds, 0x4f7a) + 1);
        if (memory16get(ds, 0x4f7a) < 0x0012) {
            pc = 0x7492;
            break;
        }
        memory16set(ds, 0x4f7c, 0x0001);
    case 0x7492:
        if (memory16get(ds, 0x37ce) != 0x0000) {
            pc = 0x74aa;
            break;
        }
        if (memory16get(ds, 0x37d0) != 0x0000) {
            pc = 0x74aa;
            break;
        }
        if (memory16get(ds, 0x204c) != 0x0011) {
            pc = 0x74aa;
            break;
        }
        yield* sub_76db();
    case 0x74aa:
        yield* sub_3503();
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_34f3();
        yield* sub_30d4();
        if (memory[ds*16 + 0x0020] != 0x19) {
            pc = 0x74cd;
            break;
        }
        if (memory16get(ds, 0x4f8a) == 0x0008) {
            pc = 0x74cd;
            break;
        }
        yield* sub_75bc();
    case 0x74cd:
        yield* sub_68ba();
        yield* sub_77a9();
        yield* sub_8b8b();
        yield* sub_350c();
        if (memory[ds*16 + 0x0020] != 0x01) {
            pc = 0x74e3;
            break;
        }
        pc = 0x74e6;
        break;
    case 0x74e3:
        pc = 0x7407;
        break;
    case 0x74e6:
        si = 0x0bde;
        yield* sub_236a();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        return;
    case 0x74f9:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        memory16set(ds, 0x203e, 0x0080);
        yield* sub_30d4();
        if (memory16get(ds, 0x4f7c) == 0x0001) {
            pc = 0x754b;
            break;
        }
        if (memory16get(ds, 0x4f7c) == 0x0002) {
            pc = 0x7591;
            break;
        }
        if (memory16get(ds, 0x4f7c) == 0x0003) {
            pc = 0x7545;
            break;
        }
        if (memory16get(ds, 0x4f7c) == 0x0004) {
            pc = 0x7548;
            break;
        }
        pc = 0x74e6;
        break;
    case 0x7545:
        pc = 0x723a;
        break;
    case 0x7548:
        pc = 0x7208;
        break;
    case 0x754b:
        r16[ax] = memory16get(ds, 0x4f72);
        memory16set(ds, 0x3c6a, r16[ax]);
        r16[ax] = memory16get(ds, 0x4f74);
        memory16set(ds, 0x3c70, r16[ax]);
        r16[ax] = memory16get(ds, 0x4f76);
        memory16set(ds, 0x3a54, r16[ax]);
        memory16set(ds, 0x3c74, 0x0000);
        if (memory16get(ds, 0x4f8c) == 0x0000) {
            pc = 0x7571;
            break;
        }
        memory16set(ds, 0x4f8c, memory16get(ds, 0x4f8c) - 1);
        pc = 0x723a;
        break;
    case 0x7571:
        yield* sub_4052();
        if (memory16get(ds, 0x26fc) == 0x0000) {
            pc = 0x757e;
            break;
        }
        pc = 0x74e6;
        break;
    case 0x757e:
        memory16set(ds, 0x3a50, 0x0000);
        memory16set(ds, 0x4f8e, memory16get(ds, 0x4f8e) - 1);
        memory16set(ds, 0x4f8c, 0x0002);
        pc = 0x723a;
        break;
    case 0x7591:
        if (memory16get(ds, 0x4f8a) == 0x0008) {
            pc = 0x759f;
            break;
        }
        memory16set(ds, 0x4f8a, memory16get(ds, 0x4f8a) + 1);
        pc = 0x723a;
        break;
    case 0x759f:
        if (memory16get(ds, 0x4f88) == 0x0008) {
            pc = 0x75b6;
            break;
        }
        memory16set(ds, 0x4f88, memory16get(ds, 0x4f88) + 1);
        memory16set(ds, 0x4f8a, 0x0001);
        pc = 0x7208;
        break;
    case 0x75b6:
        yield* sub_8ed2();
        pc = 0x74e6;
        break;
        return;
    } while (1);
}
function* sub_75bc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x0020] = 0x00;
        memory[ds*16 + 0x0023] = 0xff;
        yield* sub_8b75();
        memory16set(ds, 0x4f70, 0x0000);
        if (memory16get(ds, 0x26f2) == 0x0000) {
            pc = 0x75f9;
            break;
        }
        if (memory16get(ds, 0x26f2) == 0x0001) {
            pc = 0x75ec;
            break;
        }
        r16[ax] = memory16get(ds, 0x203e);
        r16[ax] -= 0x0080;
        r8[cl] = 0x06;
        r16[ax] <<= r8[cl];
        memory16set(ds, 0x4f70, r16[ax]);
        pc = 0x75f9;
        break;
    case 0x75ec:
        r16[ax] = memory16get(ds, 0x203e);
        r16[ax] -= 0x0080;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        memory16set(ds, 0x4f70, r16[ax]);
    case 0x75f9:
        si = memory16get(ds, 0x001a);
        si += memory16get(ds, 0x4f70);
        r16[dx] = 0x0040;
        r16[cx] = 0x0018;
        r16[ax] = 0x25f0;
        es = r16[ax];
        di = 0x5590;
        yield* sub_26b6();
        di = memory16get(ds, 0x001a);
        di += memory16get(ds, 0x4f70);
        r16[dx] = 0x0040;
        r16[cx] = 0x0018;
        r8[al] = 0x00;
        yield* sub_2cb3();
        di = memory16get(ds, 0x001a);
        di += memory16get(ds, 0x4f70);
        di += 0x021b;
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x763c;
            break;
        }
        di += 0x0200;
    case 0x763c:
        r16[ax] = 0x00c9;
        yield* sub_273a();
    case 0x7642:
        r8[al] = memory[ds*16 + 0x0020];
        if (r8[al] == 0x01)
            return;
        if (r8[al] == 0x19) {
            pc = 0x764f;
            break;
        }
        pc = 0x7642;
        break;
    case 0x764f:
        memory[ds*16 + 0x0020] = 0x00;
        di = memory16get(ds, 0x001a);
        di += memory16get(ds, 0x4f70);
        r16[dx] = 0x0040;
        r16[cx] = 0x0018;
        r16[ax] = 0x25f0;
        es = r16[ax];
        si = 0x5590;
        if (memory16get(ds, 0x26f2) == 0x0002) {
            pc = 0x767c;
            break;
        }
        push(ds);
        r16[ax] = 0x25f0;
        ds = r16[ax];
        yield* sub_263d();
        pc = 0x7685;
        break;
    case 0x767c:
        push(ds);
        r16[ax] = 0x25f0;
        ds = r16[ax];
        yield* sub_267a();
    case 0x7685:
        ds = pop();
        memory[ds*16 + 0x0023] = 0x00;
        yield* sub_8b6a();
        return;
    } while (1);
}
function* sub_7690() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x4200) != 0x0000)
            return;
        r16[ax] = memory16get(ds, 0x4f92);
        if (r16[ax] == 0x0000)
            return;
        yield* sub_57f1();
        di += memory16get(ds, 0x0018);
        r16[ax] = 0x006b;
        r16[dx] = memory16get(ds, 0x001c);
        r16[dx] &= 0x0008;
        if (r16[dx] == 0x0000) {
            pc = 0x76b8;
            break;
        }
        r16[ax] = 0x0085;
    case 0x76b8:
        yield* sub_273a();
        return;
    } while (1);
}
function* sub_76bc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0726;
        r16[cx] = 0x01b8;
    case 0x76c2:
        r8[ah] = memory[ds*16 + r16[bx]];
        si = 0x4fa0;
    case 0x76c9:
        lodsb_data_forward();
        if (r8[al] == 0xff) {
            pc = 0x76d7;
            break;
        }
        if (r8[ah] != r8[al]) {
            pc = 0x76c9;
            break;
        }
        memory[ds*16 + r16[bx]] = 0x2a;
    case 0x76d7:
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x76c2;
            break;
        }
        return;
    } while (1);
}
function* sub_76db() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x4f8a) == 0x0008) {
            pc = 0x76ff;
            break;
        }
        yield* sub_697c();
        memory16set(ds, 0x4200, 0x0000);
        r16[cx] = 0x0008;
    case 0x76ee:
        push(r16[cx]);
        yield* sub_71c6();
        r16[cx] = 0x0001;
        r16[dx] = 0x0008;
        yield* sub_6908();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x76ee;
            break;
        }
        return;
    case 0x76ff:
        memory16set(ds, 0x3c66, 0xffff);
        memory16set(ds, 0x3c68, 0x0000);
        return;
    } while (1);
}
function* sub_770c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x3a50) < 0xfa00) {
            pc = 0x771a;
            break;
        }
        memory16set(ds, 0x3a50, 0xfa00);
    case 0x771a:
        r16[ax] = memory16get(ds, 0x3a50);
        if (memory16get(ds, 0x4f90) >= r16[ax]) {
            pc = 0x7726;
            break;
        }
        memory16set(ds, 0x4f90, r16[ax]);
    case 0x7726:
        if (memory[ds*16 + 0x4f95] == 0xff) {
            pc = 0x773f;
            break;
        }
        if (memory16get(ds, 0x4f80) == r16[ax]) {
            pc = 0x7748;
            break;
        }
        memory16set(ds, 0x4f80, r16[ax]);
        memory[ds*16 + 0x4f95] = 0xff;
        pc = 0x7745;
        break;
    case 0x773f:
        memory[ds*16 + 0x4f95] = 0x00;
    case 0x7745:
        yield* sub_521e();
    case 0x7748:
        if (memory[ds*16 + 0x4f96] == 0xff) {
            pc = 0x7761;
            break;
        }
        if (memory16get(ds, 0x4f84) == r16[ax]) {
            pc = 0x776a;
            break;
        }
        memory16set(ds, 0x4f84, r16[ax]);
        memory[ds*16 + 0x4f96] = 0xff;
        pc = 0x7767;
        break;
    case 0x7761:
        memory[ds*16 + 0x4f96] = 0x00;
    case 0x7767:
        yield* sub_5264();
    case 0x776a:
        r16[ax] = memory16get(ds, 0x37d0);
        if (r16[ax] == memory16get(ds, 0x4f7e)) {
            pc = 0x7789;
            break;
        }
        if (memory16get(ds, 0x4f7e) == 0xffff) {
            pc = 0x7783;
            break;
        }
        memory16set(ds, 0x4f7e, 0xffff);
        pc = 0x7786;
        break;
    case 0x7783:
        memory16set(ds, 0x4f7e, r16[ax]);
    case 0x7786:
        yield* sub_52aa();
    case 0x7789:
        r16[ax] = memory16get(ds, 0x4f8c);
        if (r16[ax] == memory16get(ds, 0x4f82))
            return;
        if (memory16get(ds, 0x4f82) == 0xffff) {
            pc = 0x77a2;
            break;
        }
        memory16set(ds, 0x4f82, 0xffff);
        pc = 0x77a5;
        break;
    case 0x77a2:
        memory16set(ds, 0x4f82, r16[ax]);
    case 0x77a5:
        yield* sub_5300();
        return;
    } while (1);
}
function* sub_77a9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x4f9a;
        if (memory16get(ds, 0x4200) != 0x0000) {
            pc = 0x77be;
            break;
        }
        r16[ax] = memory16get(ds, 0x001c);
        if (!(r16[ax] & 0x0004)) {
            pc = 0x77be;
            break;
        }
        si += 0x0003;
    case 0x77be:
        r8[al] = 0x21;
        r16[cx] = 0x0001;
        yield* sub_2397();
        return;
    } while (1);
}
function* sub_77c8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] += r16[ax];
        r16[bx] = 0x56bc;
        r16[bx] += r16[ax];
        si = memory16get(ds, r16[bx]);
        push(si);
        push(ds);
        r16[cx] = 0xd6d8;
        r16[dx] = si;
        r16[dx] += 0x0008;
        r16[bx] = 0x0000;
        r16[ax] = 0x25f0;
        ds = r16[ax];
        yield* sub_78e1();
        ds = pop();
        si = pop();
        push(ds);
        di = memory16get(ds, si + 6);
        r16[ax] = memory16get(ds, si + 4);
        es = r16[ax];
        r16[cx] = memory16get(ds, si + 2);
        push(si);
        yield* sub_23ec();
        si = pop();
        ds = pop();
        r16[bx] = memory16get(ds, si);
        if (r16[bx] == 0xffff) {
            pc = 0x780c;
            break;
        }
        yield* sub_783b();
        return;
    case 0x780c:
        yield* sub_7810();
        return;
    } while (1);
}
function* sub_7810() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x0008;
        r16[cx] = 0x000a;
    case 0x7816:
        push(r16[cx]);
        r16[cx] = 0x0014;
    case 0x781a:
        push(r16[cx]);
        push(si);
        r16[bx] = 0x56b0;
        memory16set(ds, r16[bx], si);
        memory16set(ds, r16[bx] + 2, 0x335d);
        yield* sub_783b();
        si = pop();
        r16[cx] = pop();
        si += 0x0010;
        if (--r16[cx]) {
            pc = 0x781a;
            break;
        }
        r16[cx] = pop();
        si += 0x1540;
        if (--r16[cx]) {
            pc = 0x7816;
            break;
        }
        return;
    } while (1);
}
function* sub_783b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        si = r16[bx];
    case 0x783e:
        lodsw_data_forward();
        if (r16[ax] == 0xffff) {
            pc = 0x7868;
            break;
        }
        memory16set(ds, 0x56aa, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, 0x56ac, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, 0x56ae, r16[ax]);
        lodsw_data_forward();
        if (r16[ax] == 0xffff) {
            pc = 0x786a;
            break;
        }
        push(si);
        r16[cx] = r16[ax];
    case 0x7858:
        push(r16[cx]);
        yield* sub_7891();
        memory16set(ds, 0x56aa, memory16get(ds, 0x56aa) + 0x0140);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x7858;
            break;
        }
        si = pop();
        pc = 0x783e;
        break;
    case 0x7868:
        ds = pop();
        return;
    case 0x786a:
        push(si);
        r16[bx] = 0x56b0;
        r16[ax] = memory16get(ds, 0x56aa);
        memory16set(ds, r16[bx], r16[ax]);
        r16[ax] = memory16get(ds, 0x56ac);
        memory16set(ds, r16[bx] + 2, r16[ax]);
        r16[cx] = 0x0014;
    case 0x787f:
        push(r16[cx]);
        r16[bx] = 0x56b0;
        yield* sub_783b();
        memory16set(ds, 0x56b0, memory16get(ds, 0x56b0) + 0x0010);
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x787f;
            break;
        }
        si = pop();
        pc = 0x783e;
        break;
        return;
    } while (1);
}
function* sub_7891() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x56aa);
        di = r16[ax];
        r16[ax] = memory16get(ds, 0x56ac);
        es = r16[ax];
        r16[cx] = memory16get(ds, 0x56ae);
        r16[dx] = r16[cx];
        push(ds);
        push(si);
        r16[ax] = 0x0b52;
        ds = r16[ax];
        si = 0x16c2;
        r16[bx] = 0x0000;
        r16[cx] <<= 1;
    case 0x78b0:
        r16[ax] = memory16get(es, r16[bx] + di);
        memory16set(ds, r16[bx] + si, r16[ax]);
        r16[bx] += 0x0002;
        if (--r16[cx]) {
            pc = 0x78b0;
            break;
        }
        r16[dx] = memory16get(ds, 0x56ae);
        r16[cx] = r16[dx];
        r16[bx] = 0x0000;
    case 0x78c3:
        push(r16[bx]);
        lodsb_data_forward();
        memory[es*16 + r16[bx] + di] = r8[al];
        r16[bx] += r16[dx];
        lodsb_data_forward();
        memory[es*16 + r16[bx] + di] = r8[al];
        r16[bx] += r16[dx];
        lodsb_data_forward();
        memory[es*16 + r16[bx] + di] = r8[al];
        r16[bx] += r16[dx];
        lodsb_data_forward();
        memory[es*16 + r16[bx] + di] = r8[al];
        r16[bx] = pop();
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0x78c3;
            break;
        }
        si = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_78e1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0x0b52;
        ds = r16[ax];
        memory[ds*16 + 0x0021] = 0x00;
        r16[ax] = 0x3d00;
        interrupt(0x21);
        if (flags.carry) {
            pc = 0x7907;
            break;
        }
        ds = pop();
        push(ds);
        r16[dx] = r16[bx];
        r16[bx] = r16[ax];
        r16[ax] = 0x3f00;
        interrupt(0x21);
        if (flags.carry) {
            pc = 0x7907;
            break;
        }
        ds = pop();
        r16[ax] = 0x3e00;
        interrupt(0x21);
        return;
    case 0x7907:
        r16[ax] = 0x0b52;
        ds = r16[ax];
        memory[ds*16 + 0x0021] = r8[al];
        ds = pop();
        return;
    } while (1);
}
function* sub_7912() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x6b79] = 0x00;
        memory[ds*16 + 0x6b78] = 0x00;
        memory[ds*16 + 0x6b77] = 0x00;
        r16[ax] = 0x0004;
        r16[dx] = 0x0012;
        yield* sub_7a1b();
        yield* sub_7a4e();
        r16[ax] = memory16get(ds, 0x4f88);
        if (r16[ax] == 0x0001) {
            pc = 0x795f;
            break;
        }
        if (r16[ax] == 0x0002) {
            pc = 0x7962;
            break;
        }
        if (r16[ax] == 0x0003) {
            pc = 0x7965;
            break;
        }
        if (r16[ax] == 0x0004) {
            pc = 0x79b2;
            break;
        }
        if (r16[ax] == 0x0005) {
            pc = 0x795c;
            break;
        }
        if (r16[ax] == 0x0006) {
            pc = 0x79c5;
            break;
        }
        if (r16[ax] == 0x0007) {
            pc = 0x79a2;
            break;
        }
        if (r16[ax] == 0x0008) {
            pc = 0x7968;
            break;
        }
        return;
    case 0x795c:
        pc = 0x79f5;
        break;
    case 0x795f:
        pc = 0x79d8;
        break;
    case 0x7962:
        pc = 0x79e8;
        break;
    case 0x7965:
        pc = 0x7a02;
        break;
    case 0x7968:
        memory16set(ds, 0x6b70, 0x0004);
        memory16set(ds, 0x7048, 0xffff);
        memory16set(ds, 0x6b72, 0x005a);
        memory[ds*16 + 0x6b79] = 0x00;
        memory[ds*16 + 0x6b78] = 0xff;
        r16[ax] = 0x0004;
        r16[dx] = 0x0016;
        yield* sub_7a1b();
        memory16set(ds, 0x7460, 0x0008);
        memory16set(ds, 0x7462, 0x0020);
        r16[cx] = 0x0005;
        yield* sub_7a60();
        return;
    case 0x79a2:
        r16[ax] = 0x0008;
        r16[dx] = 0x001e;
        yield* sub_7a1b();
        r16[cx] = 0x0004;
        yield* sub_7acd();
        return;
    case 0x79b2:
        r16[ax] = 0x0018;
        yield* sub_7a2f();
        r16[cx] = 0x0004;
        yield* sub_7b2a();
        r16[cx] = 0x0001;
        yield* sub_7b7f();
        return;
    case 0x79c5:
        r16[ax] = 0x0018;
        yield* sub_7a2f();
        r16[cx] = 0x0008;
        yield* sub_7b2a();
        r16[cx] = 0x0003;
        yield* sub_7b7f();
        return;
    case 0x79d8:
        r16[ax] = 0x0012;
        yield* sub_7a2f();
        r16[ax] = 0x0707;
        si = 0x72a4;
        yield* sub_7c29();
        return;
    case 0x79e8:
        r16[ax] = 0x0012;
        yield* sub_7a2f();
        r16[cx] = 0x0001;
        yield* sub_7bd4();
        return;
    case 0x79f5:
        r16[ax] = 0x0012;
        yield* sub_7a2f();
        r16[cx] = 0x0003;
        yield* sub_7bd4();
        return;
    case 0x7a02:
        r16[ax] = 0x0012;
        yield* sub_7a2f();
        si = 0x72a4;
        r16[ax] = 0x0707;
        yield* sub_7c29();
        si = 0x7388;
        r16[ax] = 0x0701;
        yield* sub_7c29();
        return;
    } while (1);
}
function* sub_7a1b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x7388;
        r16[cx] = 0x0006;
    case 0x7a21:
        memory16set(ds, si + 26, r16[ax]);
        memory16set(ds, si + 28, r16[dx]);
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x7a21;
            break;
        }
        return;
    } while (1);
}
function* sub_7a2f() {
    si = 0x7388;
    r16[dx] = 0x0004;
    memory16set(ds, si + 140, r16[dx]);
    memory16set(ds, si + 178, r16[dx]);
    memory16set(ds, si + 216, r16[dx]);
    memory16set(ds, si + 142, r16[ax]);
    memory16set(ds, si + 180, r16[ax]);
    memory16set(ds, si + 218, r16[ax]);
}
function* sub_7a4e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x72a4;
        r16[cx] = 0x000c;
    case 0x7a54:
        memory16set(ds, si, 0xffff);
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x7a54;
            break;
        }
        return;
    } while (1);
}
function* sub_7a60() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x71ea;
        memory16set(ds, 0x704a, r16[ax]);
        di = 0x7388;
        si = 0x702a;
    case 0x7a6c:
        push(r16[cx]);
        lodsw_data_forward();
        yield* sub_57d2();
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0008;
        memory16set(ds, di, r16[dx]);
        memory16set(ds, di + 2, r16[cx]);
        memory16set(ds, di + 10, 0x0000);
        lodsw_data_forward();
        memory16set(ds, di + 4, r16[ax]);
        memory16set(ds, di + 6, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, di + 12, r16[ax]);
        r16[ax] = 0x000b;
        yield* sub_587c();
        r8[ah] = r8[al];
        r8[al] = 0x0a;
        memory16set(ds, di + 8, r16[ax]);
        memory16set(ds, di + 14, 0x0003);
        memory16set(ds, di + 18, 0x0000);
        memory16set(ds, di + 16, 0x0000);
        memory16set(ds, di + 20, 0x000e);
        if (memory16get(ds, di + 12) != 0x0001) {
            pc = 0x7ac6;
            break;
        }
        memory16set(ds, di + 20, 0x0019);
    case 0x7ac6:
        di += 0x0026;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x7a6c;
            break;
        }
        return;
    } while (1);
}
function* sub_7acd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x72a4;
    case 0x7ad0:
        push(r16[cx]);
        yield* sub_71c6();
        yield* sub_57d2();
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0008;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 10, 0x0000);
        memory16set(ds, si + 12, 0x0001);
        memory16set(ds, si + 20, 0x0019);
        memory16set(ds, si + 4, 0x6e24);
        memory16set(ds, si + 6, 0x6e24);
        r16[ax] = 0x000b;
        yield* sub_587c();
        r8[ah] = r8[al];
        r8[al] = 0x0a;
        memory16set(ds, si + 8, r16[ax]);
        memory16set(ds, si + 14, 0x0003);
        memory16set(ds, si + 18, 0x0000);
        memory16set(ds, si + 16, 0x0000);
        si += 0x0026;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x7ad0;
            break;
        }
        return;
    } while (1);
}
function* sub_7b2a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x72a4;
    case 0x7b2d:
        push(r16[cx]);
        yield* sub_71c6();
        yield* sub_57d2();
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0008;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 10, 0x0000);
        memory16set(ds, si + 12, 0x0001);
        memory16set(ds, si + 20, 0x000f);
        memory16set(ds, si + 4, 0x6cc6);
        memory16set(ds, si + 6, 0x6cc6);
        memory16set(ds, si + 8, 0x000a);
        memory16set(ds, si + 14, 0x0003);
        memory16set(ds, si + 18, 0x0000);
        memory16set(ds, si + 16, 0x0000);
        si += 0x0026;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x7b2d;
            break;
        }
        return;
    } while (1);
}
function* sub_7b7f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x73fa;
    case 0x7b82:
        push(r16[cx]);
        yield* sub_71c6();
        yield* sub_57d2();
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0008;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 10, 0x0000);
        memory16set(ds, si + 12, 0x0000);
        memory16set(ds, si + 20, 0x0028);
        memory16set(ds, si + 4, 0x6cf6);
        memory16set(ds, si + 6, 0x6cf6);
        memory16set(ds, si + 8, 0x000a);
        memory16set(ds, si + 14, 0x0003);
        memory16set(ds, si + 18, 0x0000);
        memory16set(ds, si + 16, 0x0000);
        si += 0x0026;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x7b82;
            break;
        }
        return;
    } while (1);
}
function* sub_7bd4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x73fa;
    case 0x7bd7:
        push(r16[cx]);
        yield* sub_71c6();
        yield* sub_57d2();
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0008;
        memory16set(ds, si, r16[dx]);
        memory16set(ds, si + 2, r16[cx]);
        memory16set(ds, si + 10, 0x0000);
        memory16set(ds, si + 12, 0x0008);
        memory16set(ds, si + 20, 0x001e);
        memory16set(ds, si + 4, 0x6c92);
        memory16set(ds, si + 6, 0x6c92);
        memory16set(ds, si + 8, 0x000e);
        memory16set(ds, si + 14, 0x0083);
        memory16set(ds, si + 18, 0x0000);
        memory16set(ds, si + 16, 0x0000);
        r16[cx] = pop();
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x7bd7;
            break;
        }
        return;
    } while (1);
}
function* sub_7c29() {
    yield* sub_57d2();
    r16[dx] -= 0x0008;
    r16[cx] -= 0x0008;
    memory16set(ds, si, r16[dx]);
    memory16set(ds, si + 2, r16[cx]);
    memory16set(ds, si + 38, r16[dx]);
    memory16set(ds, si + 40, r16[cx]);
    memory16set(ds, si + 76, r16[dx]);
    memory16set(ds, si + 78, r16[cx]);
    memory16set(ds, si + 114, r16[dx]);
    memory16set(ds, si + 116, r16[cx]);
    memory16set(ds, si + 152, r16[dx]);
    memory16set(ds, si + 154, r16[cx]);
    memory16set(ds, si + 190, r16[dx]);
    memory16set(ds, si + 192, r16[cx]);
    memory16set(ds, si + 10, 0xffff);
    memory16set(ds, si + 48, 0xffff);
    memory16set(ds, si + 86, 0xffff);
    memory16set(ds, si + 124, 0xffff);
    memory16set(ds, si + 162, 0xffff);
    memory16set(ds, si + 200, 0xffff);
    memory16set(ds, si + 12, 0x0008);
    memory16set(ds, si + 50, 0x0008);
    memory16set(ds, si + 88, 0x0008);
    memory16set(ds, si + 126, 0x0008);
    memory16set(ds, si + 164, 0x0008);
    memory16set(ds, si + 202, 0x0008);
    memory16set(ds, si + 20, 0x0032);
    memory16set(ds, si + 58, 0x0032);
    memory16set(ds, si + 96, 0x0032);
    memory16set(ds, si + 134, 0x0032);
    memory16set(ds, si + 172, 0x0032);
    memory16set(ds, si + 210, 0x0032);
    memory16set(ds, si + 4, 0x6b7a);
    memory16set(ds, si + 6, 0x6b7a);
    memory16set(ds, si + 42, 0x6bbe);
    memory16set(ds, si + 44, 0x6bbe);
    memory16set(ds, si + 80, 0x6bbe);
    memory16set(ds, si + 82, 0x6bbe);
    memory16set(ds, si + 118, 0x6bbe);
    memory16set(ds, si + 120, 0x6bbe);
    memory16set(ds, si + 156, 0x6bbe);
    memory16set(ds, si + 158, 0x6bbe);
    memory16set(ds, si + 194, 0x6c02);
    memory16set(ds, si + 196, 0x6c02);
    memory16set(ds, si + 8, 0x0014);
    memory16set(ds, si + 46, 0x0014);
    memory16set(ds, si + 84, 0x1014);
    memory16set(ds, si + 122, 0x0414);
    memory16set(ds, si + 160, 0x0814);
    memory16set(ds, si + 198, 0x1014);
    memory16set(ds, si + 14, 0x8282);
    memory16set(ds, si + 52, 0x8282);
    memory16set(ds, si + 90, 0x8282);
    memory16set(ds, si + 128, 0x8282);
    memory16set(ds, si + 166, 0x8282);
    memory16set(ds, si + 204, 0x8282);
    memory16set(ds, si + 18, 0x0000);
    memory16set(ds, si + 16, 0x0000);
}
function* sub_7d6b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x4f88);
        if (r16[ax] == 0x0001) {
            pc = 0x7de6;
            break;
        }
        if (r16[ax] == 0x0002) {
            pc = 0x7d9d;
            break;
        }
        if (r16[ax] == 0x0003) {
            pc = 0x7d9a;
            break;
        }
        if (r16[ax] == 0x0004) {
            pc = 0x7dca;
            break;
        }
        if (r16[ax] == 0x0005) {
            pc = 0x7d9d;
            break;
        }
        if (r16[ax] == 0x0006) {
            pc = 0x7dca;
            break;
        }
        if (r16[ax] == 0x0007) {
            pc = 0x7da0;
            break;
        }
        if (r16[ax] == 0x0008) {
            pc = 0x7d97;
            break;
        }
        return;
    case 0x7d97:
        pc = 0x7e5b;
        break;
    case 0x7d9a:
        pc = 0x7e09;
        break;
    case 0x7d9d:
        pc = 0x7e48;
        break;
    case 0x7da0:
        yield* sub_801a();
        r16[ax] = 0x0000;
        r16[dx] = memory16get(ds, 0x001c);
        if (!(r16[dx] & 0x0020)) {
            pc = 0x7db3;
            break;
        }
        r16[ax] = 0xffff;
    case 0x7db3:
        memory[ds*16 + 0x6b78] = r8[al];
        if (r8[al] != 0x00) {
            pc = 0x7dc0;
            break;
        }
        si = 0x72a4;
        yield* sub_893b();
    case 0x7dc0:
        yield* sub_80ca();
        yield* sub_8b10();
        yield* sub_86df();
        return;
    case 0x7dca:
        yield* sub_801a();
        si = 0x72a4;
        yield* sub_893b();
        si = 0x7388;
        yield* sub_893b();
        yield* sub_8211();
        yield* sub_8309();
        yield* sub_8b10();
        yield* sub_86df();
        return;
    case 0x7de6:
        si = 0x72a4;
        yield* sub_8877();
        si = 0x72a4;
        yield* sub_8877();
        si = 0x72a4;
        yield* sub_893b();
        memory[ds*16 + 0x6b76] = r8[dl];
        si = 0x72a4;
        yield* sub_8758();
        yield* sub_8b10();
        yield* sub_86df();
        return;
    case 0x7e09:
        si = 0x72a4;
        yield* sub_8877();
        si = 0x72a4;
        yield* sub_8877();
        si = 0x7388;
        yield* sub_8877();
        si = 0x7388;
        yield* sub_8877();
        si = 0x72a4;
        yield* sub_893b();
        memory[ds*16 + 0x6b76] = r8[dl];
        si = 0x72a4;
        yield* sub_8758();
        si = 0x7388;
        yield* sub_893b();
        memory[ds*16 + 0x6b76] = r8[dl];
        si = 0x7388;
        yield* sub_8758();
        yield* sub_8b10();
        yield* sub_86df();
        return;
    case 0x7e48:
        yield* sub_85ad();
        si = 0x7388;
        yield* sub_893b();
        yield* sub_80ca();
        yield* sub_8b10();
        yield* sub_86df();
        return;
    case 0x7e5b:
        if (memory16get(ds, 0x6b70) != 0x0000) {
            pc = 0x7e6e;
            break;
        }
        r16[ax] = memory16get(ds, 0x001c);
        if (r16[ax] & 0x001f) {
            pc = 0x7e6e;
            break;
        }
        memory[ds*16 + 0x6b78] = ~memory[ds*16 + 0x6b78];
    case 0x7e6e:
        yield* sub_801a();
        yield* sub_801a();
        yield* sub_8428();
        si = 0x7388;
        yield* sub_893b();
        yield* sub_86df();
        yield* sub_7fd3();
        memory16set(ds, 0x6b72, memory16get(ds, 0x6b72) - 1);
        if (memory16get(ds, 0x6b72) == 0x0000) {
            pc = 0x7efe;
            break;
        }
        if (memory16get(ds, 0x7048) != 0xffff) {
            pc = 0x7e96;
            break;
        }
        return;
    case 0x7e96:
        di = 0x73ae;
        si = 0x4d50;
        r16[bx] = memory16get(ds, 0x7048);
        r16[cx] = 0x0004;
    case 0x7ea3:
        push(r16[cx]);
        push(r16[bx]);
        push(si);
        push(di);
        r16[dx] = memory16get(ds, di);
        if (r16[dx] == 0xffff) {
            pc = 0x7ecd;
            break;
        }
        r16[cx] = memory16get(ds, di + 2);
        r16[cx] -= 0x0006;
        si += 0x0014;
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 2, r16[ax]);
        yield* sub_2782();
    case 0x7ecd:
        di = pop();
        si = pop();
        r16[bx] = pop();
        r16[cx] = pop();
        di += 0x0026;
        si += 0x0024;
        if (--r16[cx]) {
            pc = 0x7ea3;
            break;
        }
        r16[ax] = memory16get(ds, 0x001c);
        if (r16[ax] & 0x0001) {
            pc = 0x7efd;
            break;
        }
        memory16set(ds, 0x7048, memory16get(ds, 0x7048) + 0x0004);
        r16[bx] = memory16get(ds, 0x7048);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x7efd;
            break;
        }
        memory16set(ds, 0x7048, 0xffff);
        memory[ds*16 + 0x6b79] = 0x00;
    case 0x7efd:
        return;
    case 0x7efe:
        if (memory[ds*16 + 0x6b79] == 0x00) {
            pc = 0x7f50;
            break;
        }
        memory16set(ds, 0x6b72, 0x00b4);
        di = 0x4d50;
        si = 0x73ae;
        r16[cx] = 0x0004;
    case 0x7f14:
        r16[ax] = memory16get(ds, di);
        if (r16[ax] == 0xffff) {
            pc = 0x7f2c;
            break;
        }
        memory16set(ds, di, 0xffff);
        r16[ax] -= 0x0008;
        r16[ax] &= 0xfff0;
        r16[ax] += 0x0008;
    case 0x7f2c:
        memory16set(ds, si, r16[ax]);
        r16[ax] = memory16get(ds, di + 2);
        r16[ax] -= 0x0018;
        r16[ax] &= 0xfff0;
        r16[ax] += 0x0018;
        memory16set(ds, si + 2, r16[ax]);
        di += 0x0024;
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x7f14;
            break;
        }
        memory16set(ds, 0x7048, 0x71c4);
        return;
    case 0x7f50:
        memory16set(ds, 0x6b72, 0x00b4);
        memory[ds*16 + 0x6b79] = 0xff;
        si = 0x73ae;
        di = 0x4d50;
        r16[cx] = 0x0004;
    case 0x7f65:
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x7fca;
            break;
        }
        if (memory16gets(ds, si + 12) < 0) {
            pc = 0x7fca;
            break;
        }
        r16[ax] = memory16get(ds, si);
        if (r16[ax] == 0xffff) {
            pc = 0x7f85;
            break;
        }
        r16[ax] -= 0x0008;
        r16[ax] &= 0xfff0;
        r16[ax] += 0x0008;
    case 0x7f85:
        memory16set(ds, di, r16[ax]);
        r16[ax] = memory16get(ds, si + 2);
        r16[ax] -= 0x0018;
        r16[ax] &= 0xfff0;
        r16[ax] += 0x0018;
        memory16set(ds, di + 2, r16[ax]);
        memory16set(ds, di + 4, 0x7182);
        memory16set(ds, di + 6, 0x70f2);
        memory16set(ds, di + 10, 0xffc0);
        memory16set(ds, di + 12, 0x0017);
        memory16set(ds, di + 14, 0x008f);
        memory16set(ds, di + 16, 0x0000);
        memory16set(ds, di + 8, 0x000a);
        memory16set(ds, di + 26, 0x0016);
    case 0x7fca:
        si += 0x0026;
        di += 0x0024;
        if (--r16[cx]) {
            pc = 0x7f65;
            break;
        }
        return;
    } while (1);
}
function* sub_7fd3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x6b79] == 0x00)
            return;
        push(si);
        si = 0x4d50;
        r16[cx] = 0x0004;
    case 0x7fe1:
        push(r16[cx]);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x8012;
            break;
        }
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        di = 0x3cde;
        r16[cx] = 0x0008;
    case 0x7ffa:
        if (memory16get(ds, di + 8) != r16[ax]) {
            pc = 0x800d;
            break;
        }
        if (memory16gets(ds, di + 2) < 0) {
            pc = 0x800d;
            break;
        }
        memory16set(ds, di + 6, 0xffff);
    case 0x800d:
        di += 0x0016;
        if (--r16[cx]) {
            pc = 0x7ffa;
            break;
        }
    case 0x8012:
        si += 0x0024;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x7fe1;
            break;
        }
        si = pop();
        return;
    } while (1);
}
function* sub_801a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x72a4;
        r16[cx] = 0x000c;
        if (memory[ds*16 + 0x6b79] == 0x00) {
            pc = 0x802a;
            break;
        }
        r16[cx] = 0x0007;
    case 0x802a:
        push(r16[cx]);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x8057;
            break;
        }
        if (memory16gets(ds, si + 12) < 0) {
            pc = 0x8057;
            break;
        }
        r16[ax] = memory16get(ds, si + 10);
        r16[ax] &= 0x0001;
        if (r16[ax] == 0x0000) {
            pc = 0x805a;
            break;
        }
        r16[ax] = memory16get(ds, si);
        r16[ax] -= 0x0008;
        r16[ax] &= 0x000f;
        if (r16[ax] == 0x0000) {
            pc = 0x806b;
            break;
        }
        pc = 0x809c;
        break;
    case 0x8057:
        pc = 0x80c0;
        break;
    case 0x805a:
        r16[ax] = memory16get(ds, si + 2);
        r16[ax] -= 0x0018;
        r16[ax] &= 0x000f;
        if (r16[ax] == 0x0000) {
            pc = 0x806b;
            break;
        }
        pc = 0x809c;
        break;
    case 0x806b:
        r16[ax] = 0x0064;
        yield* sub_587c();
        if (r16[ax] > 0x0014) {
            pc = 0x8082;
            break;
        }
        yield* sub_6f9a();
        yield* sub_6e9c();
        memory16set(ds, si + 10, r16[ax]);
        pc = 0x809c;
        break;
    case 0x8082:
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x809c;
            break;
        }
        memory16set(ds, si + 10, r16[ax]);
        yield* sub_6f9a();
        yield* sub_6e9c();
        memory16set(ds, si + 10, r16[ax]);
    case 0x809c:
        r16[ax] = memory16get(ds, si + 10);
        if (r16[ax] == 0xffff) {
            pc = 0x80c0;
            break;
        }
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] = 0x4444;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si, memory16get(ds, si) + r16[ax]);
        memory16set(ds, si + 2, memory16get(ds, si + 2) + r16[dx]);
    case 0x80c0:
        r16[cx] = pop();
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x80c7;
            break;
        }
        return;
    case 0x80c7:
        pc = 0x802a;
        break;
        return;
    } while (1);
}
function* sub_80ca() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x72a4;
        r16[cx] = 0x000c;
    case 0x80d0:
        push(r16[cx]);
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x80db;
            break;
        }
        pc = 0x81a8;
        break;
    case 0x80db:
        if (memory16gets(ds, si + 12) >= 0) {
            pc = 0x80e5;
            break;
        }
        pc = 0x81b2;
        break;
    case 0x80e5:
        r16[bx] = memory16get(ds, si + 6);
        r16[dx] = memory16get(ds, 0x001e);
        r16[ax] = memory16get(ds, si + 8);
        r8[ah] += r8[dl];
        if (r8[ah] < r8[al]) {
            pc = 0x810f;
            break;
        }
        r8[ah] = 0x00;
        r16[bx] += 0x0004;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x810f;
            break;
        }
        r16[bx] = memory16get(ds, si + 4);
        memory16set(ds, si + 6, r16[bx]);
    case 0x810f:
        memory16set(ds, si + 8, r16[ax]);
        push(si);
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        if (memory16get(ds, si + 20) > 0x0010) {
            pc = 0x8126;
            break;
        }
        r16[ax] += 0x0040;
    case 0x8126:
        if (memory16get(ds, si + 20) > 0x0008) {
            pc = 0x8130;
            break;
        }
        r16[ax] += 0x0040;
    case 0x8130:
        memory16set(ds, si + 22, r16[ax]);
        memory16set(ds, si + 24, r16[dx]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0002;
        if (memory[ds*16 + 0x6b78] != 0x00) {
            pc = 0x8163;
            break;
        }
        if (memory16get(ds, si + 18) == 0x0000) {
            pc = 0x8163;
            break;
        }
        r16[ax] = memory16get(ds, 0x001c);
        if (!(r16[ax] & 0x0001)) {
            pc = 0x8163;
            break;
        }
        r8[bl] = 0x69;
        si += 0x0016;
        yield* sub_28cd();
        pc = 0x81a7;
        break;
    case 0x8163:
        si += 0x0016;
        yield* sub_2782();
        if (memory[ds*16 + 0x6b78] == 0x00) {
            pc = 0x81a7;
            break;
        }
        si = pop();
        push(si);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0008;
        si += 0x0146;
        memory16set(ds, si, 0xb5c0);
        memory16set(ds, si + 2, 0x1650);
        r16[ax] = memory16get(ds, 0x001c);
        if (!(r16[ax] & 0x0001)) {
            pc = 0x81a4;
            break;
        }
        memory16set(ds, si, 0xb5e0);
        memory16set(ds, si + 2, 0x1650);
    case 0x81a4:
        yield* sub_2782();
    case 0x81a7:
        si = pop();
    case 0x81a8:
        r16[cx] = pop();
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x81af;
            break;
        }
        return;
    case 0x81af:
        pc = 0x80d0;
        break;
    case 0x81b2:
        memory16set(ds, 0x6b6e, si);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x820f;
            break;
        }
        r16[bx] = memory16get(ds, si + 6);
        r16[ax] = memory16get(ds, 0x001e);
        memory16set(ds, si + 8, memory16get(ds, si + 8) + r16[ax]);
        if (memory16get(ds, si + 8) < 0x006e) {
            pc = 0x81ec;
            break;
        }
        memory16set(ds, si + 8, 0x0064);
        r16[bx] += 0x0004;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x81ec;
            break;
        }
        memory16set(ds, si, 0xffff);
        pc = 0x820f;
        break;
    case 0x81ec:
        push(si);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 22, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 24, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0002;
        si += 0x0016;
        yield* sub_2782();
        si = pop();
    case 0x820f:
        pc = 0x81a8;
        break;
        return;
    } while (1);
}
function* sub_8211() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x72a4;
        r16[cx] = 0x0008;
    case 0x8217:
        push(r16[cx]);
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x8222;
            break;
        }
        pc = 0x82a0;
        break;
    case 0x8222:
        if (memory16gets(ds, si + 12) >= 0) {
            pc = 0x822c;
            break;
        }
        pc = 0x82aa;
        break;
    case 0x822c:
        r16[bx] = memory16get(ds, si + 6);
        r16[dx] = memory16get(ds, 0x001e);
        r16[ax] = memory16get(ds, si + 8);
        r8[ah] += r8[dl];
        if (r8[ah] < r8[al]) {
            pc = 0x8256;
            break;
        }
        r8[ah] = 0x00;
        r16[bx] += 0x0004;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x8256;
            break;
        }
        r16[bx] = memory16get(ds, si + 4);
        memory16set(ds, si + 6, r16[bx]);
    case 0x8256:
        memory16set(ds, si + 8, r16[ax]);
        push(si);
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        if (memory16get(ds, si + 20) > 0x0007) {
            pc = 0x826d;
            break;
        }
        r16[ax] += 0x0030;
    case 0x826d:
        memory16set(ds, si + 22, r16[ax]);
        memory16set(ds, si + 24, r16[dx]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0002;
        if (memory16get(ds, si + 18) == 0x0000) {
            pc = 0x8299;
            break;
        }
        r16[ax] = memory16get(ds, 0x001c);
        if (!(r16[ax] & 0x0001)) {
            pc = 0x8299;
            break;
        }
        r8[bl] = 0x69;
        si += 0x0016;
        yield* sub_28cd();
        pc = 0x829f;
        break;
    case 0x8299:
        si += 0x0016;
        yield* sub_2782();
    case 0x829f:
        si = pop();
    case 0x82a0:
        r16[cx] = pop();
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x82a7;
            break;
        }
        return;
    case 0x82a7:
        pc = 0x8217;
        break;
    case 0x82aa:
        memory16set(ds, 0x6b6e, si);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x8307;
            break;
        }
        r16[bx] = memory16get(ds, si + 6);
        r16[ax] = memory16get(ds, 0x001e);
        memory16set(ds, si + 8, memory16get(ds, si + 8) + r16[ax]);
        if (memory16get(ds, si + 8) < 0x006e) {
            pc = 0x82e4;
            break;
        }
        memory16set(ds, si + 8, 0x0064);
        r16[bx] += 0x0004;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x82e4;
            break;
        }
        memory16set(ds, si, 0xffff);
        pc = 0x8307;
        break;
    case 0x82e4:
        push(si);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 22, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 24, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0002;
        si += 0x0016;
        yield* sub_2782();
        si = pop();
    case 0x8307:
        pc = 0x82a0;
        break;
        return;
    } while (1);
}
function* sub_8309() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x73fa;
        r16[cx] = 0x0003;
    case 0x830f:
        push(r16[cx]);
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x831a;
            break;
        }
        pc = 0x83bc;
        break;
    case 0x831a:
        if (memory16gets(ds, si + 12) >= 0) {
            pc = 0x8324;
            break;
        }
        pc = 0x83c6;
        break;
    case 0x8324:
        r16[bx] = memory16get(ds, si + 6);
        r16[dx] = memory16get(ds, 0x001e);
        r16[ax] = memory16get(ds, si + 8);
        r8[ah] += r8[dl];
        if (r8[ah] < r8[al]) {
            pc = 0x834e;
            break;
        }
        r8[ah] = 0x00;
        r16[bx] += 0x0010;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x834e;
            break;
        }
        r16[bx] = memory16get(ds, si + 4);
        memory16set(ds, si + 6, r16[bx]);
    case 0x834e:
        memory16set(ds, si + 8, r16[ax]);
        push(si);
        r16[ax] = memory16get(ds, si + 10);
        r16[ax] &= 0x0003;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        if (memory16get(ds, si + 20) > 0x001e) {
            pc = 0x836b;
            break;
        }
        r16[bx] += 0x0044;
    case 0x836b:
        if (memory16get(ds, si + 20) > 0x0014) {
            pc = 0x8376;
            break;
        }
        r16[bx] += 0x0044;
    case 0x8376:
        if (memory16get(ds, si + 20) > 0x000a) {
            pc = 0x8381;
            break;
        }
        r16[bx] += 0x0044;
    case 0x8381:
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 22, r16[ax]);
        memory16set(ds, si + 24, r16[dx]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0008;
        if (memory16get(ds, si + 18) == 0x0000) {
            pc = 0x83b5;
            break;
        }
        r16[ax] = memory16get(ds, 0x001c);
        if (!(r16[ax] & 0x0001)) {
            pc = 0x83b5;
            break;
        }
        r8[bl] = 0x69;
        si += 0x0016;
        yield* sub_28cd();
        pc = 0x83bb;
        break;
    case 0x83b5:
        si += 0x0016;
        yield* sub_2782();
    case 0x83bb:
        si = pop();
    case 0x83bc:
        r16[cx] = pop();
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x83c3;
            break;
        }
        return;
    case 0x83c3:
        pc = 0x830f;
        break;
    case 0x83c6:
        memory16set(ds, 0x6b6e, si);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x8426;
            break;
        }
        r16[bx] = memory16get(ds, si + 6);
        r16[ax] = memory16get(ds, 0x001e);
        memory16set(ds, si + 8, memory16get(ds, si + 8) + r16[ax]);
        if (memory16get(ds, si + 8) < 0x006e) {
            pc = 0x8400;
            break;
        }
        memory16set(ds, si + 8, 0x0064);
        r16[bx] += 0x0004;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x8400;
            break;
        }
        memory16set(ds, si, 0xffff);
        pc = 0x8426;
        break;
    case 0x8400:
        push(si);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 22, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 24, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0008;
        r16[dx] -= 0x0008;
        si += 0x0016;
        yield* sub_2782();
        si = pop();
    case 0x8426:
        pc = 0x83bc;
        break;
        return;
    } while (1);
}
function* sub_8428() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x7388;
        r16[cx] = 0x0005;
    case 0x842e:
        push(r16[cx]);
        if (memory[ds*16 + 0x6b79] == 0x00) {
            pc = 0x8447;
            break;
        }
        if (memory16get(ds, si + 12) == 0x0001) {
            pc = 0x8447;
            break;
        }
        if (memory16gets(ds, si + 12) < 0) {
            pc = 0x8447;
            break;
        }
        pc = 0x851b;
        break;
    case 0x8447:
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x8451;
            break;
        }
        pc = 0x851b;
        break;
    case 0x8451:
        if (memory16gets(ds, si + 12) >= 0) {
            pc = 0x845b;
            break;
        }
        pc = 0x8525;
        break;
    case 0x845b:
        r16[bx] = memory16get(ds, si + 6);
        r16[dx] = memory16get(ds, 0x001e);
        r16[ax] = memory16get(ds, si + 8);
        r8[ah] += r8[dl];
        if (r8[ah] < r8[al]) {
            pc = 0x8485;
            break;
        }
        r8[ah] = 0x00;
        r16[bx] += 0x0010;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x8485;
            break;
        }
        r16[bx] = memory16get(ds, si + 4);
        memory16set(ds, si + 6, r16[bx]);
    case 0x8485:
        memory16set(ds, si + 8, r16[ax]);
        push(si);
        r16[ax] = memory16get(ds, si + 10);
        r16[ax] &= 0x0003;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 22, r16[ax]);
        memory16set(ds, si + 24, r16[dx]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0006;
        if (memory16get(ds, si + 18) == 0x0000) {
            pc = 0x84cb;
            break;
        }
        r16[ax] = memory16get(ds, 0x001c);
        if (!(r16[ax] & 0x0001)) {
            pc = 0x84cb;
            break;
        }
        r8[bl] = 0x69;
        si += 0x0016;
        yield* sub_28cd();
        pc = 0x84d1;
        break;
    case 0x84cb:
        si += 0x0016;
        yield* sub_2782();
    case 0x84d1:
        si = pop();
        if (memory16get(ds, si + 12) != 0x0001) {
            pc = 0x851b;
            break;
        }
        if (memory[ds*16 + 0x6b78] == 0x00) {
            pc = 0x851b;
            break;
        }
        push(si);
        r16[dx] = memory16get(ds, si);
        r16[dx] -= 0x0008;
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x000a;
        di = memory16get(ds, 0x704a);
        si = 0x745c;
        r16[ax] = memory16get(ds, di);
        memory16set(ds, si, r16[ax]);
        r16[ax] = memory16get(ds, di + 2);
        memory16set(ds, si + 2, r16[ax]);
        di += 0x0004;
        if (memory16get(ds, di) != 0xffff) {
            pc = 0x8513;
            break;
        }
        di = 0x71ea;
    case 0x8513:
        memory16set(ds, 0x704a, di);
        yield* sub_2782();
        si = pop();
    case 0x851b:
        r16[cx] = pop();
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x8522;
            break;
        }
        return;
    case 0x8522:
        pc = 0x842e;
        break;
    case 0x8525:
        memory16set(ds, 0x6b6e, si);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x85aa;
            break;
        }
        r16[bx] = memory16get(ds, si + 6);
        r16[ax] = memory16get(ds, 0x001e);
        memory16set(ds, si + 8, memory16get(ds, si + 8) + r16[ax]);
        if (memory16get(ds, si + 8) < 0x006e) {
            pc = 0x857d;
            break;
        }
        memory16set(ds, si + 8, 0x0064);
        if (memory16get(ds, 0x6b70) != 0x0000) {
            pc = 0x8555;
            break;
        }
        memory16set(ds, si + 8, 0x0069);
    case 0x8555:
        r16[bx] += 0x0004;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x857d;
            break;
        }
        memory16set(ds, 0x6b70, memory16get(ds, 0x6b70) - 1);
        if (memory16get(ds, 0x6b70) != 0xffff) {
            pc = 0x8574;
            break;
        }
        memory16set(ds, 0x4f7c, 0x0002);
    case 0x8574:
        memory16set(ds, si, 0xffff);
        pc = 0x85aa;
        break;
    case 0x857d:
        push(si);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 22, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 24, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        if (memory16get(ds, 0x6b70) == 0x0000) {
            pc = 0x85a3;
            break;
        }
        r16[cx] -= 0x0005;
        r16[dx] -= 0x0003;
    case 0x85a3:
        si += 0x0016;
        yield* sub_2782();
        si = pop();
    case 0x85aa:
        pc = 0x851b;
        break;
        return;
    } while (1);
}
function* sub_85ad() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x73fa;
        r16[cx] = 0x0003;
    case 0x85b3:
        push(r16[cx]);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x85e0;
            break;
        }
        if (memory16gets(ds, si + 12) < 0) {
            pc = 0x85e0;
            break;
        }
        r16[ax] = memory16get(ds, si + 10);
        r16[ax] &= 0x0001;
        if (r16[ax] == 0x0000) {
            pc = 0x85e3;
            break;
        }
        r16[ax] = memory16get(ds, si);
        r16[ax] -= 0x0008;
        r16[ax] &= 0x000f;
        if (r16[ax] == 0x0000) {
            pc = 0x85f4;
            break;
        }
        pc = 0x8636;
        break;
    case 0x85e0:
        pc = 0x865a;
        break;
    case 0x85e3:
        r16[ax] = memory16get(ds, si + 2);
        r16[ax] -= 0x0018;
        r16[ax] &= 0x000f;
        if (r16[ax] == 0x0000) {
            pc = 0x85f4;
            break;
        }
        pc = 0x8636;
        break;
    case 0x85f4:
        if (memory16get(ds, 0x4200) < 0x0008) {
            pc = 0x8612;
            break;
        }
        r16[ax] = 0x0064;
        yield* sub_587c();
        if (r16[ax] < 0x0014) {
            pc = 0x8612;
            break;
        }
        yield* sub_6f9a();
        yield* sub_6e9c();
        memory16set(ds, si + 10, r16[ax]);
        pc = 0x862c;
        break;
    case 0x8612:
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x862c;
            break;
        }
        memory16set(ds, si + 10, r16[ax]);
        yield* sub_6f9a();
        yield* sub_6e9c();
        memory16set(ds, si + 10, r16[ax]);
    case 0x862c:
        if (memory16get(ds, 0x4200) >= 0x0008) {
            pc = 0x8636;
            break;
        }
        yield* sub_8664();
    case 0x8636:
        r16[ax] = memory16get(ds, si + 10);
        if (r16[ax] == 0xffff) {
            pc = 0x865a;
            break;
        }
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] = 0x4444;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si, memory16get(ds, si) + r16[ax]);
        memory16set(ds, si + 2, memory16get(ds, si + 2) + r16[dx]);
    case 0x865a:
        r16[cx] = pop();
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x8661;
            break;
        }
        return;
    case 0x8661:
        pc = 0x85b3;
        break;
        return;
    } while (1);
}
function* sub_8664() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        di = 0x4d50;
        r16[cx] = 0x000f;
    case 0x8675:
        if (memory16get(ds, di) == 0xffff) {
            pc = 0x8684;
            break;
        }
        di += 0x0024;
        if (--r16[cx]) {
            pc = 0x8675;
            break;
        }
        return;
    case 0x8684:
        yield* sub_57d2();
        r16[dx] -= 0x0008;
        r16[cx] -= 0x0008;
        memory16set(ds, di, r16[dx]);
        memory16set(ds, di + 2, r16[cx]);
        memory16set(ds, di + 10, 0xffb8);
        r16[ax] = 0x000c;
        memory16set(ds, di + 12, r16[ax]);
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] = 0x42d4;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, di + 6, r16[ax]);
        r16[ax] += 0x00c0;
        memory16set(ds, di + 4, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 4);
        memory16set(ds, di + 8, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 6);
        memory16set(ds, di + 14, r16[ax]);
        memory16set(ds, di + 18, 0x0000);
        memory16set(ds, di + 16, 0x0000);
        memory16set(ds, 0x4200, memory16get(ds, 0x4200) + 1);
        return;
    } while (1);
}
function* sub_86df() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x3c5e;
        if (memory16get(ds, si) == 0xffff)
            return;
        if (memory16gets(ds, si + 8) < 0)
            return;
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        yield* sub_581f();
        r16[dx] = r16[ax];
        r16[bx] = 0x72a4;
        r16[cx] = 0x000c;
    case 0x8703:
        push(r16[cx]);
        if (memory16get(ds, r16[bx]) == 0xffff) {
            pc = 0x8729;
            break;
        }
        if (memory16gets(ds, r16[bx] + 12) < 0) {
            pc = 0x8729;
            break;
        }
        push(r16[dx]);
        r16[dx] = memory16get(ds, r16[bx]);
        r16[dx] += 0x0008;
        r16[cx] = memory16get(ds, r16[bx] + 2);
        r16[cx] += 0x0008;
        yield* sub_581f();
        r16[dx] = pop();
        if (r16[ax] == r16[dx]) {
            pc = 0x8730;
            break;
        }
    case 0x8729:
        r16[bx] += 0x0026;
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x8703;
            break;
        }
        return;
    case 0x8730:
        r16[cx] = pop();
        if (memory16get(ds, r16[bx] + 12) == 0x0001) {
            pc = 0x8745;
            break;
        }
        if (memory[ds*16 + 0x6b79] == 0x00) {
            pc = 0x8745;
            break;
        }
        r16[bx] += 0x0026;
        if (--r16[cx]) {
            pc = 0x8703;
            break;
        }
        return;
    case 0x8745:
        memory16set(ds, si + 8, 0xffff);
        memory16set(ds, si + 10, 0x0000);
        r16[ax] = 0x0000;
        yield* sub_8ca1();
        return;
    } while (1);
}
function* sub_8758() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, si) != 0xffff) {
            pc = 0x8762;
            break;
        }
        pc = 0x8807;
        break;
    case 0x8762:
        if (memory16gets(ds, si + 12) >= 0) {
            pc = 0x876c;
            break;
        }
        pc = 0x880b;
        break;
    case 0x876c:
        si += 0x00be;
        r16[cx] = 0x0006;
    case 0x8773:
        push(r16[cx]);
        r16[bx] = memory16get(ds, si + 6);
        r16[dx] = memory16get(ds, 0x001e);
        r16[ax] = memory16get(ds, si + 8);
        r8[ah] += r8[dl];
        if (r8[ah] < r8[al]) {
            pc = 0x879e;
            break;
        }
        r8[ah] = 0x00;
        r16[bx] += 0x0010;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x879e;
            break;
        }
        r16[bx] = memory16get(ds, si + 4);
        memory16set(ds, si + 6, r16[bx]);
    case 0x879e:
        memory16set(ds, si + 8, r16[ax]);
        push(si);
        r16[ax] = memory16get(ds, si + 10);
        if (r16s[ax] < 0) {
            pc = 0x87b5;
            break;
        }
        r16[ax] &= 0x0003;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] += r16[ax];
    case 0x87b5:
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        if (memory16get(ds, si + 20) > 0x0021) {
            pc = 0x87c7;
            break;
        }
        r16[ax] += 0x2d00;
    case 0x87c7:
        if (memory16get(ds, si + 20) > 0x0010) {
            pc = 0x87d1;
            break;
        }
        r16[ax] += 0x2d00;
    case 0x87d1:
        memory16set(ds, si + 22, r16[ax]);
        memory16set(ds, si + 24, r16[dx]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0002;
        si += 0x0016;
        if (memory[ds*16 + 0x6b76] == 0x00) {
            pc = 0x87fd;
            break;
        }
        r16[ax] = memory16get(ds, 0x001c);
        if (!(r16[ax] & 0x0001)) {
            pc = 0x87fd;
            break;
        }
        r8[bl] = 0x69;
        yield* sub_28cd();
        pc = 0x8800;
        break;
    case 0x87fd:
        yield* sub_2782();
    case 0x8800:
        si = pop();
        r16[cx] = pop();
        si -= 0x0026;
        if (--r16[cx]) {
            pc = 0x8808;
            break;
        }
    case 0x8807:
        return;
    case 0x8808:
        pc = 0x8773;
        break;
    case 0x880b:
        memory16set(ds, 0x6b6e, si);
        si += 0x00be;
        r16[cx] = 0x0006;
    case 0x8816:
        push(r16[cx]);
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x8870;
            break;
        }
        r16[bx] = memory16get(ds, si + 6);
        r16[ax] = memory16get(ds, 0x001e);
        memory16set(ds, si + 8, memory16get(ds, si + 8) + r16[ax]);
        if (memory16get(ds, si + 8) < 0x006c) {
            pc = 0x884d;
            break;
        }
        memory16set(ds, si + 8, 0x0064);
        r16[bx] += 0x0004;
        memory16set(ds, si + 6, r16[bx]);
        if (memory16get(ds, r16[bx]) != 0xffff) {
            pc = 0x884d;
            break;
        }
        memory16set(ds, si, 0xffff);
        pc = 0x8870;
        break;
    case 0x884d:
        push(si);
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 22, r16[ax]);
        r16[ax] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si + 24, r16[ax]);
        r16[dx] = memory16get(ds, si);
        r16[cx] = memory16get(ds, si + 2);
        r16[cx] -= 0x0002;
        si += 0x0016;
        yield* sub_2782();
        si = pop();
    case 0x8870:
        r16[cx] = pop();
        si -= 0x0026;
        if (--r16[cx]) {
            pc = 0x8816;
            break;
        }
        return;
    } while (1);
}
function* sub_8877() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, si) == 0xffff) {
            pc = 0x88aa;
            break;
        }
        if (memory16gets(ds, si + 12) < 0) {
            pc = 0x88aa;
            break;
        }
        r16[ax] = memory16get(ds, si + 10);
        memory16set(ds, 0x6b74, r16[ax]);
        r16[ax] = memory16get(ds, si + 10);
        r16[ax] &= 0x0001;
        if (r16[ax] == 0x0000) {
            pc = 0x88ad;
            break;
        }
        r16[ax] = memory16get(ds, si);
        r16[ax] -= 0x0008;
        r16[ax] &= 0x000f;
        if (r16[ax] == 0x0000) {
            pc = 0x88be;
            break;
        }
        pc = 0x890e;
        break;
    case 0x88aa:
        return;
    case 0x88ad:
        r16[ax] = memory16get(ds, si + 2);
        r16[ax] -= 0x0018;
        r16[ax] &= 0x000f;
        if (r16[ax] == 0x0000) {
            pc = 0x88be;
            break;
        }
        pc = 0x890e;
        break;
    case 0x88be:
        yield* sub_6d9c();
        if (r16[dx] == 0x0000) {
            pc = 0x88e0;
            break;
        }
        r16[ax] = memory16get(ds, si + 10);
        yield* sub_6ebe();
        if (r16[dx] == 0x0000) {
            pc = 0x88e0;
            break;
        }
        memory16set(ds, si + 10, r16[ax]);
        yield* sub_6f9a();
        yield* sub_6e9c();
        memory16set(ds, si + 10, r16[ax]);
    case 0x88e0:
        if (memory16gets(ds, si + 10) < 0) {
            pc = 0x890e;
            break;
        }
        r16[ax] = memory16get(ds, si + 162);
        memory16set(ds, si + 200, r16[ax]);
        r16[ax] = memory16get(ds, si + 124);
        memory16set(ds, si + 162, r16[ax]);
        r16[ax] = memory16get(ds, si + 86);
        memory16set(ds, si + 124, r16[ax]);
        r16[ax] = memory16get(ds, si + 48);
        memory16set(ds, si + 86, r16[ax]);
        r16[ax] = memory16get(ds, 0x6b74);
        memory16set(ds, si + 48, r16[ax]);
    case 0x890e:
        r16[cx] = 0x0006;
    case 0x8911:
        r16[ax] = memory16get(ds, si + 10);
        if (r16s[ax] < 0) {
            pc = 0x8938;
            break;
        }
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] = 0x4444;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        r16[dx] = memory16get(ds, r16[bx] + 2);
        memory16set(ds, si, memory16get(ds, si) + r16[ax]);
        memory16set(ds, si + 2, memory16get(ds, si + 2) + r16[dx]);
        si += 0x0026;
    case 0x8938:
        if (--r16[cx]) {
            pc = 0x8911;
            break;
        }
        return;
    } while (1);
}
function* sub_893b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, 0x6b6c, 0x0000);
        memory16set(ds, 0x6b6e, si);
        r16[cx] = 0x0006;
    case 0x8948:
        r16[dx] = memory16get(ds, si);
        if (r16[dx] == 0xffff) {
            pc = 0x8975;
            break;
        }
        if (memory16gets(ds, si + 12) < 0) {
            pc = 0x8975;
            break;
        }
        push(r16[cx]);
        memory16set(ds, si + 18, 0x0000);
        r16[cx] = memory16get(ds, si + 2);
        r16[dx] += 0x0008;
        r16[cx] += 0x0008;
        yield* sub_581f();
        yield* sub_6bb9();
        r16[cx] = pop();
        if (r16[dx] == 0xffff) {
            pc = 0x897f;
            break;
        }
    case 0x8975:
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x8948;
            break;
        }
        r16[dx] = memory16get(ds, 0x6b6c);
        return;
    case 0x897f:
        if (memory16get(ds, 0x4f88) != 0x0008) {
            pc = 0x8996;
            break;
        }
        if (memory16get(ds, si + 12) != 0x0001) {
            pc = 0x8996;
            break;
        }
        if (memory[ds*16 + 0x6b78] == 0x00) {
            pc = 0x899d;
            break;
        }
        pc = 0x8975;
        break;
    case 0x8996:
        if (memory[ds*16 + 0x6b79] != 0x00) {
            pc = 0x8975;
            break;
        }
    case 0x899d:
        memory16set(ds, si + 18, 0xffff);
        memory16set(ds, 0x6b6c, 0xffff);
        memory16set(ds, si + 20, memory16get(ds, si + 20) - 1);
        if (memory16gets(ds, si + 20) < 0) {
            pc = 0x89b6;
            break;
        }
        pc = 0x8975;
        break;
    case 0x89b6:
        push(si);
        r16[ax] = 0x0002;
        yield* sub_8ca1();
        si = pop();
        r16[ax] = memory16get(ds, 0x4f88);
        if (r16[ax] == 0x0001) {
            pc = 0x89ed;
            break;
        }
        if (r16[ax] == 0x0002) {
            pc = 0x8a47;
            break;
        }
        if (r16[ax] == 0x0003) {
            pc = 0x89ed;
            break;
        }
        if (r16[ax] == 0x0004) {
            pc = 0x8a09;
            break;
        }
        if (r16[ax] == 0x0005) {
            pc = 0x8a47;
            break;
        }
        if (r16[ax] == 0x0006) {
            pc = 0x8a09;
            break;
        }
        if (r16[ax] == 0x0007) {
            pc = 0x89f0;
            break;
        }
        if (r16[ax] == 0x0008) {
            pc = 0x89ea;
            break;
        }
        return;
    case 0x89ea:
        pc = 0x8ad7;
        break;
    case 0x89ed:
        pc = 0x8a60;
        break;
    case 0x89f0:
        memory16set(ds, si + 12, 0xffff);
        memory16set(ds, si + 6, 0x6e36);
        memory16set(ds, si + 8, 0x0032);
        memory16set(ds, 0x3a50, memory16get(ds, 0x3a50) + 0x012c);
        return;
    case 0x8a09:
        if (memory16get(ds, si + 12) == 0x0001) {
            pc = 0x8a2f;
            break;
        }
        memory16set(ds, si + 12, 0xffff);
        memory16set(ds, si + 6, 0x6e06);
        memory16set(ds, si + 8, 0x0032);
        memory16set(ds, si + 26, 0x0008);
        memory16set(ds, 0x3a50, memory16get(ds, 0x3a50) + 0x012c);
        return;
    case 0x8a2f:
        memory16set(ds, si + 12, 0xffff);
        memory16set(ds, si + 6, 0x6cd8);
        memory16set(ds, si + 8, 0x0032);
        memory16set(ds, 0x3a50, memory16get(ds, 0x3a50) + 0x000a);
        return;
    case 0x8a47:
        memory16set(ds, si + 12, 0xffff);
        memory16set(ds, si + 6, 0x6ca4);
        memory16set(ds, si + 8, 0x0032);
        memory16set(ds, 0x3a50, memory16get(ds, 0x3a50) + 0x00c8);
        return;
    case 0x8a60:
        si = memory16get(ds, 0x6b6e);
        memory16set(ds, si + 12, 0xffff);
        memory16set(ds, si + 50, 0xffff);
        memory16set(ds, si + 88, 0xffff);
        memory16set(ds, si + 126, 0xffff);
        memory16set(ds, si + 164, 0xffff);
        memory16set(ds, si + 202, 0xffff);
        memory16set(ds, si + 6, 0x6c46);
        memory16set(ds, si + 44, 0x6c70);
        memory16set(ds, si + 82, 0x6c70);
        memory16set(ds, si + 120, 0x6c70);
        memory16set(ds, si + 158, 0x6c70);
        memory16set(ds, si + 196, 0x6c70);
        memory16set(ds, si + 8, 0x0032);
        memory16set(ds, si + 46, 0x003c);
        memory16set(ds, si + 84, 0x0046);
        memory16set(ds, si + 122, 0x0050);
        memory16set(ds, si + 160, 0x005a);
        memory16set(ds, si + 198, 0x0064);
        memory16set(ds, 0x3a50, memory16get(ds, 0x3a50) + 0x00c8);
        return;
    case 0x8ad7:
        r16[ax] = memory16get(ds, si + 12);
        r16[ax]--;
        r16[ax] += r16[ax];
        r16[bx] = 0x7020;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ds, r16[bx]);
        memory16set(ds, si + 6, r16[ax]);
        memory16set(ds, si + 8, 0x0032);
        if (memory16get(ds, si + 12) == 0x0001) {
            pc = 0x8b04;
            break;
        }
        memory16set(ds, si + 26, 0x0006);
        memory16set(ds, si + 28, 0x0016);
    case 0x8b04:
        memory16set(ds, si + 12, 0xffff);
        memory16set(ds, 0x3a50, memory16get(ds, 0x3a50) + 0x000a);
        return;
    } while (1);
}
function* sub_8b10() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x6b77] != 0x00)
            return;
        if (memory16get(ds, 0x4200) != 0x0000)
            return;
        si = 0x72a4;
        r16[cx] = 0x000c;
    case 0x8b24:
        if (memory16get(ds, si) != 0xffff)
            return;
        si += 0x0026;
        if (--r16[cx]) {
            pc = 0x8b24;
            break;
        }
        r16[cx] = 0x0008;
        si = 0x3cde;
    case 0x8b36:
        if (memory16get(ds, si) != 0xffff)
            return;
        si += 0x0016;
        if (--r16[cx]) {
            pc = 0x8b36;
            break;
        }
        memory[ds*16 + 0x6b77] = 0xff;
        yield* sub_71c6();
        push(r16[ax]);
        r8[dl] = 0x75;
        yield* sub_57b4();
        r16[ax] = pop();
        yield* sub_57f1();
        r16[ax] = 0x00a0;
        yield* sub_5f24();
        di += memory16get(ds, 0x0018);
        yield* sub_273a();
        r16[ax] = 0x000a;
        yield* sub_8c10();
        return;
    } while (1);
}
function* sub_8b6a() {
    if (memory[ds*16 + 0x7052] == 0x00)
        return;
    yield* sub_9641();
}
function* sub_8b75() {
    if (memory[ds*16 + 0x7052] == 0x00)
        return;
    yield* sub_9634();
}
function* sub_8b80() {
    if (memory[ds*16 + 0x7052] == 0x00)
        return;
    yield* sub_9612();
}
function* sub_8b8b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        if (memory[ds*16 + 0x7052] == 0x00) {
            pc = 0x8b99;
            break;
        }
        yield* sub_964e();
        if (r8[al] == 0x00) {
            pc = 0x8b9a;
            break;
        }
    case 0x8b99:
        assert(pop() == 0x7777);
        return;
    case 0x8b9a:
        r16[ax] = memory16get(ds, 0x7050);
        es = r16[ax];
        di = memory16get(ds, 0x704e);
        di += 0x0008;
        r16[ax] = memory16get(es, di);
        r16[ax] += memory16get(ds, 0x704e);
        r16[dx] = memory16get(ds, 0x7050);
        push(r16[dx]);
        push(r16[ax]);
        yield* sub_95bc();
        sp += 0x0004;
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8bba() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x7052] = 0x00;
        memory[ds*16 + 0x7053] = 0x00;
        yield* sub_92d0();
        if (r8[al] == 0x00)
            return;
        yield* sub_91c4();
        if (r8[al] == 0x00)
            return;
        yield* sub_956a();
        if (r8[al] == 0x00)
            return;
        yield* sub_95e5();
        memory[ds*16 + 0x7052] = 0xff;
        yield* sub_9479();
        if (r8[al] == 0x00) {
            pc = 0x8c03;
            break;
        }
        yield* sub_9479();
        if (r8[al] == 0x00) {
            pc = 0x8c03;
            break;
        }
        yield* sub_9479();
        if (r8[al] == 0x00) {
            pc = 0x8c03;
            break;
        }
        yield* sub_9479();
        if (r8[al] == 0x00) {
            pc = 0x8c03;
            break;
        }
        return;
    case 0x8c03:
        memory[ds*16 + 0x7052] = 0xff;
        memory[ds*16 + 0x7053] = 0xff;
        return;
    } while (1);
}
function* sub_8c10() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        if (memory[ds*16 + 0x7052] == 0x00) {
            pc = 0x8c1a;
            break;
        }
        pc = 0x8c1d;
        break;
    case 0x8c1a:
        pc = 0x8ca0;
        break;
    case 0x8c1d:
        push(si);
        push(es);
        push(r16[ax]);
        yield* sub_9612();
        r16[ax] = pop();
        si = 0x70a2;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        memory16set(ds, 0x704e, r16[ax]);
        lodsw_data_forward();
        memory16set(ds, 0x7050, r16[ax]);
        es = r16[ax];
        di = memory16get(ds, 0x704e);
        di += 0x000c;
        r16[ax] = memory16get(es, di);
        r8[tl] = r8[ah];
        r8[ah] = r8[al];
        r8[al] = r8[tl];
        r16[ax] >>= 1;
        push(r16[ax]);
        yield* sub_9602();
        r16[ax] = pop();
        r16[ax] = memory16get(ds, 0x7050);
        es = r16[ax];
        di = memory16get(ds, 0x704e);
        di += 0x0024;
        r16[ax] = memory16get(es, di);
        push(r16[ax]);
        di = memory16get(ds, 0x704e);
        di += 0x0006;
        r16[ax] = memory16get(es, di);
        r16[ax] += memory16get(ds, 0x704e);
        r16[dx] = memory16get(ds, 0x7050);
        push(r16[dx]);
        push(r16[ax]);
        yield* sub_95cf();
        sp += 0x0006;
        r16[ax] = memory16get(ds, 0x7050);
        es = r16[ax];
        di = memory16get(ds, 0x704e);
        di += 0x0008;
        r16[ax] = memory16get(es, di);
        r16[ax] += memory16get(ds, 0x704e);
        r16[dx] = memory16get(ds, 0x7050);
        push(r16[dx]);
        push(r16[ax]);
        yield* sub_95bc();
        sp += 0x0004;
        if (memory[ds*16 + 0x4f98] == 0x00) {
            pc = 0x8c9d;
            break;
        }
        yield* sub_9634();
    case 0x8c9d:
        es = pop();
        si = pop();
        assert(pop() == 0x7777);
        return;
    case 0x8ca0:
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8ca1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        if (memory[ds*16 + 0x4f99] != 0x00) {
            pc = 0x8cd5;
            break;
        }
        if (memory[ds*16 + 0x7053] == 0x00) {
            pc = 0x8cd6;
            break;
        }
        push(si);
        push(es);
        push(r16[ax]);
        yield* sub_94d5();
        r16[ax] = pop();
        si = 0x70de;
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        si += r16[ax];
        lodsw_data_forward();
        r16[dx] = r16[ax];
        lodsw_data_forward();
        es = r16[dx];
        di = r16[ax];
        r16[ax] += memory16get(es, di + 20);
        push(es);
        push(r16[ax]);
        yield* sub_9504();
        sp += 0x0004;
        es = pop();
        si = pop();
    case 0x8cd5:
        assert(pop() == 0x7777);
        return;
    case 0x8cd6:
        if (r16[ax] == 0x0004) {
            pc = 0x8cf4;
            break;
        }
        if (r16[ax] == 0x0001) {
            pc = 0x8ced;
            break;
        }
        if (r16[ax] == 0x0000) {
            pc = 0x8ce6;
            break;
        }
        assert(pop() == 0x7777);
        return;
    case 0x8ce6:
        push(si);
        si = 0x7068;
        pc = 0x8cf8;
        break;
    case 0x8ced:
        push(si);
        si = 0x707e;
        pc = 0x8cf8;
        break;
    case 0x8cf4:
        push(si);
        si = 0x708e;
    case 0x8cf8:
        r8[al] = 0xb6;
        out8(0x43, r8[al]);
        lodsw_data_forward();
        out8(0x42, r8[al]);
        r8[al] = r8[ah];
        out8(0x42, r8[al]);
        r8[al] = in8(0x61);
        r8[al] |= 0x03;
        out8(0x61, r8[al]);
        memory16set(ds, 0x704c, si);
        si = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8d0f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x7052] == 0x00) {
            pc = 0x8d19;
            break;
        }
        yield* sub_9668();
    case 0x8d19:
        if (memory[ds*16 + 0x7053] == 0x00) {
            pc = 0x8d23;
            break;
        }
        yield* sub_94de();
    case 0x8d23:
        r8[al] = in8(0x61);
        r8[al] &= 0xfc;
        out8(0x61, r8[al]);
        return;
    } while (1);
}
function* sub_8d2a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x7052] == 0x00) {
            pc = 0x8d4b;
            break;
        }
        push(ds);
        r16[ax] = 0x529d;
        ds = r16[ax];
        r16[cx] = 0xaf13;
        r16[dx] = 0x7054;
        r16[bx] = 0x0008;
        yield* sub_78e1();
        ds = pop();
        if (memory[ds*16 + 0x0021] != 0x00) {
            pc = 0x8d4c;
            break;
        }
    case 0x8d4b:
        return;
    case 0x8d4c:
        yield* sub_8d0f();
        memory[ds*16 + 0x7053] = 0x00;
        memory[ds*16 + 0x7052] = 0x00;
        return;
    } while (1);
}
function* sub_8d5c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory[ds*16 + 0x7053] == 0x00) {
            pc = 0x8d7d;
            break;
        }
        push(ds);
        r16[ax] = 0x5d88;
        ds = r16[ax];
        r16[cx] = 0xfe49;
        r16[dx] = 0x705e;
        r16[bx] = 0x0008;
        yield* sub_78e1();
        ds = pop();
        if (memory[ds*16 + 0x0021] != 0x00) {
            pc = 0x8d7e;
            break;
        }
    case 0x8d7d:
        return;
    case 0x8d7e:
        yield* sub_8d0f();
        memory[ds*16 + 0x7053] = 0x00;
        memory[ds*16 + 0x7052] = 0x00;
        return;
    } while (1);
}
function* sub_8d8e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0013;
        yield* sub_77c8();
        r16[ax] = 0x0012;
        yield* sub_77c8();
        di = 0x34bc;
        push(ds);
        yield* sub_23d3();
        ds = pop();
        r8[al] = 0x00;
        yield* sub_2888();
        memory16set(ds, 0x26f2, 0x0002);
        r16[dx] = 0x03d4;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x20;
        out8(r16[dx], r8[al]);
        memory16set(ds, 0x203e, 0x0114);
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        r16[ax] = 0x00c7;
        di = 0x2940;
        yield* sub_2c81();
        r16[ax] = 0x00c8;
        di = 0x5b40;
        yield* sub_2c81();
        memory16set(ds, 0x746c, 0x0000);
        memory16set(ds, 0x746e, 0x0094);
        memory16set(ds, 0x7474, 0xffff);
        memory16set(ds, 0x7476, 0xffff);
        memory16set(ds, 0x747a, 0x0000);
        memory[ds*16 + 0x747c] = 0x00;
        r16[ax] = 0x7620;
        memory16set(ds, 0x7478, r16[ax]);
        yield* sub_9043();
        yield* sub_2318();
        yield* sub_9043();
        r16[ax] = 0x000e;
        yield* sub_8c10();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x34bc;
        di = 0x08de;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0911;
        r16[cx] = 0x0015;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
    case 0x8e55:
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_34f3();
        yield* sub_281e();
        yield* sub_9043();
        yield* sub_350c();
        yield* sub_544d();
        if (r16[dx] != 0x0000) {
            pc = 0x8eac;
            break;
        }
        if (memory[ds*16 + 0x747c] != 0x00) {
            pc = 0x8eac;
            break;
        }
        memory16set(ds, 0x747a, memory16get(ds, 0x747a) + 1);
        if (memory16get(ds, 0x747a) != 0x00ea) {
            pc = 0x8eaa;
            break;
        }
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x34bc;
        di = 0x08de;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        di = 0x08de;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x08de;
        yield* sub_23b5();
    case 0x8eaa:
        pc = 0x8e55;
        break;
    case 0x8eac:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x08de;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        return;
    } while (1);
}
function* sub_8ed2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0013;
        yield* sub_77c8();
        r16[ax] = 0x0011;
        yield* sub_77c8();
        di = 0x34bc;
        push(ds);
        yield* sub_23d3();
        ds = pop();
        r8[al] = 0x00;
        yield* sub_2888();
        memory16set(ds, 0x26f2, 0x0001);
        r16[dx] = 0x03d4;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x40;
        out8(r16[dx], r8[al]);
        memory16set(ds, 0x203e, 0x0100);
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        memory16set(ds, 0x746c, 0x0058);
        memory16set(ds, 0x746e, 0x0000);
        memory16set(ds, 0x7474, 0xffff);
        memory16set(ds, 0x7476, 0xffff);
        memory16set(ds, 0x747a, 0x0000);
        memory[ds*16 + 0x747c] = 0x00;
        r16[ax] = 0x86e8;
        memory16set(ds, 0x7478, r16[ax]);
        r16[ax] = 0x00c6;
        di = 0x1420;
        yield* sub_2c81();
        yield* sub_9043();
        yield* sub_2318();
        yield* sub_9043();
        r16[ax] = 0x0009;
        yield* sub_8c10();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x34bc;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x34bc;
        yield* sub_23b5();
    case 0x8f6d:
        yield* sub_2318();
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        yield* sub_34f3();
        yield* sub_281e();
        yield* sub_9043();
        yield* sub_350c();
        yield* sub_8b8b();
        yield* sub_544d();
        if (r16[dx] != 0x0000) {
            pc = 0x8f96;
            break;
        }
        if (memory[ds*16 + 0x747c] != 0x00) {
            pc = 0x8f96;
            break;
        }
        pc = 0x8f6d;
        break;
    case 0x8f96:
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x34bc;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        yield* sub_2318();
        yield* sub_281e();
        yield* sub_2318();
        yield* sub_281e();
        memory16set(ds, 0x37c6, 0xe2b0);
        memory16set(ds, 0x37c8, 0x1650);
        r16[ax] = 0x0008;
        yield* sub_77c8();
        di = 0x34bc;
        push(ds);
        yield* sub_23d3();
        ds = pop();
        r8[al] = 0x00;
        yield* sub_2888();
        memory16set(ds, 0x26f2, 0x0002);
        r16[dx] = 0x03d4;
        r8[al] = 0x13;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03d5;
        r8[al] = 0x20;
        out8(r16[dx], r8[al]);
        memory16set(ds, 0x203e, 0x0080);
        r16[ax] = memory16get(ds, 0x001a);
        yield* sub_305b();
        push(r16[cx]);
        r16[cx] = ds;
        es = r16[cx];
        di = 0x0bde;
        r16[cx] = 0x0300;
        r8[al] = 0x00;
        rep_stosb_data_forward();
        r16[cx] = pop();
        di = 0x34bc;
        si = 0x0bde;
        yield* sub_233a();
        yield* sub_34f3();
        r16[bx] = 0x34bc;
        yield* sub_23b5();
        si = 0x90f8;
        yield* sub_4ef1();
        r16[cx] = 0x00b4;
        yield* sub_5429();
        yield* sub_5444();
        push(r16[cx]);
        push(si);
        r16[cx] = ds;
        es = r16[cx];
        si = 0x34bc;
        di = 0x0bde;
        r16[cx] = 0x0300;
        rep_movsb_data_data_forward();
        si = pop();
        r16[cx] = pop();
        si = 0x0bde;
        yield* sub_236a();
        return;
    } while (1);
}
function* sub_9043() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = memory16get(ds, 0x7478);
        memory16set(ds, 0x7472, si);
    case 0x904b:
        lodsw_data_forward();
        if (r16[ax] == 0xfffc) {
            pc = 0x90ae;
            break;
        }
        if (r16[ax] == 0xfffd) {
            pc = 0x9080;
            break;
        }
        if (r16[ax] == 0xfffe) {
            pc = 0x90d0;
            break;
        }
        if (r16[ax] == 0xffff) {
            pc = 0x9075;
            break;
        }
        r16[dx] = r16[ax];
        r16[dx] += memory16get(ds, 0x746c);
        lodsw_data_forward();
        r16[cx] = r16[ax];
        r16[cx] += memory16get(ds, 0x746e);
        lodsw_data_forward();
        push(si);
        yield* sub_276b();
        si = pop();
        pc = 0x904b;
        break;
    case 0x9075:
        r16[ax] = memory16get(ds, 0x7470);
        memory16set(ds, 0x7472, r16[ax]);
        memory16set(ds, 0x7478, si);
        return;
    case 0x9080:
        r16[ax] = memory16get(ds, 0x7474);
        if (r16[ax] == 0x0000) {
            pc = 0x90a3;
            break;
        }
        if (r16[ax] == 0xffff) {
            pc = 0x9090;
            break;
        }
        pc = 0x9097;
        break;
    case 0x9090:
        r16[ax] = memory16get(ds, si + 2);
        memory16set(ds, 0x7474, r16[ax]);
    case 0x9097:
        r16[ax] = memory16get(ds, si);
        memory16set(ds, 0x7478, r16[ax]);
        memory16set(ds, 0x7474, memory16get(ds, 0x7474) - 1);
        return;
    case 0x90a3:
        si += 0x0004;
        memory16set(ds, 0x7474, 0xffff);
        pc = 0x9075;
        break;
    case 0x90ae:
        r16[ax] = memory16get(ds, 0x7476);
        if (r16[ax] == 0x0000) {
            pc = 0x90d7;
            break;
        }
        if (r16[ax] == 0xffff) {
            pc = 0x90be;
            break;
        }
        pc = 0x90c5;
        break;
    case 0x90be:
        r16[ax] = memory16get(ds, si);
        memory16set(ds, 0x7476, r16[ax]);
    case 0x90c5:
        r16[ax] = memory16get(ds, 0x7472);
        memory16set(ds, 0x7478, r16[ax]);
        memory16set(ds, 0x7476, memory16get(ds, 0x7476) - 1);
        return;
    case 0x90d0:
        memory[ds*16 + 0x747c] = 0xff;
        return;
    case 0x90d7:
        si += 0x0002;
        memory16set(ds, 0x7476, 0xffff);
        pc = 0x9075;
        break;
        return;
    } while (1);
}
function* sub_90e2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(r16[ax]);
        r16[ax] = 0x0b51;
        ds = r16[ax];
        r16[ax] = pop();
        push(r16[cx]);
        push(r16[dx]);
        r16[dx] = memory16get(ds, 0x0012);
        r8[dl] += 0x0e;
        r16[cx] = 0x0200;
    case 0x90f6:
        r8[al] = in8(r16[dx]);
        if (r8[al] & 0x80) {
            pc = 0x9100;
            break;
        }
        if (--r16[cx]) {
            pc = 0x90f6;
            break;
        }
        flags.carry = true;
        pc = 0x9105;
        break;
    case 0x9100:
        r8[dl] -= 0x04;
        r8[al] = in8(r16[dx]);
        flags.carry = false;
    case 0x9105:
        r16[dx] = pop();
        r16[cx] = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_9109() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(r16[ax]);
        r16[ax] = 0x0b51;
        ds = r16[ax];
        r16[ax] = pop();
        push(r16[cx]);
        push(r16[dx]);
        r16[dx] = memory16get(ds, 0x0012);
        r8[dl] += 0x0c;
        r16[cx] = 0x0200;
        r8[ah] = r8[al];
    case 0x911f:
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x80)) {
            pc = 0x9129;
            break;
        }
        if (--r16[cx]) {
            pc = 0x911f;
            break;
        }
        flags.carry = true;
        pc = 0x912d;
        break;
    case 0x9129:
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        flags.carry = false;
    case 0x912d:
        r16[dx] = pop();
        r16[cx] = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_914f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(r16[ax]);
        r16[ax] = 0x0b51;
        ds = r16[ax];
        r16[ax] = pop();
        push(r16[dx]);
        r16[dx] = memory16get(ds, 0x0012);
        r16[dx] += 0x000c;
        r8[ah] = r8[al];
    case 0x9161:
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x80)) {
            pc = 0x9168;
            break;
        }
        pc = 0x9161;
        break;
    case 0x9168:
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r16[dx] = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_916e() {
    r16[tx] = flags.carry | (flags.zero << 1);
    push(r16[tx]);
    push(ds);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    flags.interrupts = false;
    push(r16[ax]);
    r16[ax] = 0;
    ds = r16[ax];
    r16[ax] = pop();
    memory16set(ds, r16[bx], r16[ax]);
    memory16set(ds, r16[bx] + 2, r16[dx]);
    ds = pop();
    r16[tx] = pop();
    flags.carry = r16[tx] & 1;
    flags.zero = (r16[tx] << 1) & 1;
}
function* sub_9183() {
    r16[tx] = flags.carry | (flags.zero << 1);
    push(r16[tx]);
    push(ds);
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    flags.interrupts = false;
    r16[ax] = 0;
    ds = r16[ax];
    r16[ax] = memory16get(ds, r16[bx]);
    r16[dx] = memory16get(ds, r16[bx] + 2);
    ds = pop();
    r16[tx] = pop();
    flags.carry = r16[tx] & 1;
    flags.zero = (r16[tx] << 1) & 1;
}
function* sub_91c4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(ds);
        push(r16[ax]);
        r16[ax] = 0x0b51;
        ds = r16[ax];
        r16[ax] = pop();
        push(bp);
        sp -= 0x0012;
        bp = sp;
        r16[bx] = 0x000a;
        yield* sub_9183();
        memory16set(ss, bp + 2, r16[ax]);
        memory16set(ss, bp + 4, r16[dx]);
        r16[bx] = 0x000a;
        r16[ax] = 0x73d9;
        r16[dx] = cs;
        yield* sub_916e();
        r16[bx] = 0x000b;
        yield* sub_9183();
        memory16set(ss, bp + 6, r16[ax]);
        memory16set(ss, bp + 8, r16[dx]);
        r16[bx] = 0x000b;
        r16[ax] = 0x73bb;
        r16[dx] = cs;
        yield* sub_916e();
        r16[bx] = 0x000d;
        yield* sub_9183();
        memory16set(ss, bp + 10, r16[ax]);
        memory16set(ss, bp + 12, r16[dx]);
        r16[bx] = 0x000d;
        r16[ax] = 0x73e6;
        r16[dx] = cs;
        yield* sub_916e();
        r16[bx] = 0x000f;
        yield* sub_9183();
        memory16set(ss, bp + 14, r16[ax]);
        memory16set(ss, bp + 16, r16[dx]);
        r16[bx] = 0x000f;
        r16[ax] = 0x73f3;
        r16[dx] = cs;
        yield* sub_916e();
        r8[al] = in8(0x21);
        memory[ds*16 + 0x000c] = r8[al];
        r8[al] &= 0x53;
        out8(0x21, r8[al]);
        r16[ax] = 0;
        memory16set(ds, 0x0014, r16[ax]);
        r8[al] = 0xf2;
        yield* sub_914f();
        r16[ax] = 0;
        r16[cx] = r16[ax];
    case 0x9245:
        if (memory16get(ds, 0x0014) != r16[ax]) {
            pc = 0x924d;
            break;
        }
        if (--r16[cx]) {
            pc = 0x9245;
            break;
        }
    case 0x924d:
        r8[al] = memory[ds*16 + 0x000c];
        out8(0x21, r8[al]);
        r16[bx] = 0x000f;
        r16[ax] = memory16get(ss, bp + 14);
        r16[dx] = memory16get(ss, bp + 16);
        yield* sub_916e();
        r16[bx] = 0x000d;
        r16[ax] = memory16get(ss, bp + 10);
        r16[dx] = memory16get(ss, bp + 12);
        yield* sub_916e();
        r16[bx] = 0x000b;
        r16[ax] = memory16get(ss, bp + 6);
        r16[dx] = memory16get(ss, bp + 8);
        yield* sub_916e();
        r16[bx] = 0x000a;
        r16[ax] = memory16get(ss, bp + 2);
        r16[dx] = memory16get(ss, bp + 4);
        yield* sub_916e();
        r16[ax] = memory16get(ds, 0x0014);
        sp += 0x0012;
        bp = pop();
        ds = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_92d0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0x0b51;
        ds = r16[ax];
        push(si);
        si = 0x0220;
    case 0x92da:
        memory16set(ds, 0x0012, si);
        yield* sub_92fa();
        if (r16[ax]) {
            pc = 0x92f7;
            break;
        }
        si += 0x0010;
        if (si <= 0x0260) {
            pc = 0x92da;
            break;
        }
        memory16set(ds, 0x0012, 0x0210);
        yield* sub_92fa();
    case 0x92f7:
        si = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_92fa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(r16[ax]);
        r16[ax] = 0x0b51;
        ds = r16[ax];
        r16[ax] = pop();
        r16[bx] = 0;
        r16[dx] = memory16get(ds, 0x0012);
        r8[dl] += 0x06;
        r8[al] = 0xc6;
        out8(r16[dx], r8[al]);
        r8[al] = 0;
        r8[dl] += 0x04;
        out8(r16[dx], r8[al]);
        r8[al] = in8(r16[dx]);
        if (r8[al] != 0xc6) {
            pc = 0x932f;
            break;
        }
        r8[dl] -= 0x04;
        r8[al] = 0x39;
        out8(r16[dx], r8[al]);
        r8[al] = 0;
        r8[dl] += 0x04;
        out8(r16[dx], r8[al]);
        r8[al] = in8(r16[dx]);
        if (r8[al] != 0x39) {
            pc = 0x932f;
            break;
        }
        r16[bx] = 0x0001;
        pc = 0x9353;
        break;
    case 0x932f:
        yield* sub_953a();
        if (flags.carry) {
            pc = 0x9353;
            break;
        }
        r8[al] = 0xe0;
        yield* sub_9109();
        if (flags.carry) {
            pc = 0x9353;
            break;
        }
        r8[al] = 0xc6;
        yield* sub_9109();
        if (flags.carry) {
            pc = 0x9353;
            break;
        }
        yield* sub_90e2();
        if (flags.carry) {
            pc = 0x9353;
            break;
        }
        if (r8[al] != 0x39) {
            pc = 0x9353;
            break;
        }
        r16[bx] = 0x0004;
        push(r16[bx]);
        yield* sub_93b3();
        r16[bx] = pop();
    case 0x9353:
        r16[ax] = 0x0100;
        yield* sub_9430();
        r16[ax] = 0x0460;
        yield* sub_9430();
        r16[ax] = 0x0480;
        yield* sub_9430();
        r8[al] = 0x00;
        yield* sub_9392();
        if (flags.carry) {
            pc = 0x938e;
            break;
        }
        r16[ax] = 0x02ff;
        yield* sub_9430();
        r16[ax] = 0x0421;
        yield* sub_9430();
        r8[al] = 0xc0;
        yield* sub_9392();
        if (flags.carry) {
            pc = 0x938e;
            break;
        }
        r16[ax] = 0x0460;
        yield* sub_9430();
        r16[ax] = 0x0480;
        yield* sub_9430();
        r16[bx] += 0x0002;
    case 0x938e:
        r16[ax] = r16[bx];
        ds = pop();
        return;
    } while (1);
}
function* sub_9392() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        push(r16[dx]);
        r16[cx] = 0x0040;
        r8[ah] = r8[al];
        r8[ah] &= 0xe0;
        r16[dx] = memory16get(ds, 0x0012);
        r8[dl] += 0x08;
    case 0x93a3:
        r8[al] = in8(r16[dx]);
        r8[al] &= 0xe0;
        if (r8[ah] == r8[al]) {
            pc = 0x93af;
            break;
        }
        if (--r16[cx]) {
            pc = 0x93a3;
            break;
        }
        flags.carry = true;
        pc = 0x93b0;
        break;
    case 0x93af:
        flags.carry = false;
    case 0x93b0:
        r16[dx] = pop();
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_93b3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        sp -= 0x0004;
        bp = sp;
        r16[bx] = 0x0008;
        yield* sub_9183();
        memory16set(ss, bp, r16[ax]);
        memory16set(ss, bp + 2, r16[dx]);
        flags.interrupts = false;
        r8[al] = in8(0x21);
        memory16set(ds, 0x0016, r16[ax]);
        r8[al] = 0xfe;
        out8(0x21, r8[al]);
        r16[ax] = 0x1b58;
        yield* sub_9459();
        r16[bx] = 0x0008;
        r16[dx] = cs;
        r16[ax] = 0x7596;
        yield* sub_916e();
        r16[ax] = 0;
        r16[cx] = 0;
        flags.interrupts = true;
    case 0x93e5:
        if (!r16[ax]) {
            pc = 0x93e5;
            break;
        }
    case 0x93e9:
        if (r16[ax]) {
            pc = 0x93e9;
            break;
        }
    case 0x93ed:
        r16[cx]++;
        if (!r16[ax]) {
            pc = 0x93ed;
            break;
        }
        flags.interrupts = false;
        r16[ax] = memory16get(ds, 0x0016);
        out8(0x21, r8[al]);
        r16[ax] = 0xffff;
        yield* sub_9459();
        flags.interrupts = true;
        r16[bx] = 0x0008;
        r16[dx] = memory16get(ss, bp + 2);
        r16[ax] = memory16get(ss, bp);
        yield* sub_916e();
        r16[ax] = r16[cx];
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[ax] += r16[cx];
        r8[cl] = 0x0a;
        r16[ax] >>= r8[cl];
        memory16set(ds, 0x0016, r16[ax]);
        r16[cx] = r16[ax];
        r16[ax] <<= 1;
        r16[cx] += r16[ax];
        r16[ax] <<= 1;
        r16[cx] += r16[ax];
        memory16set(ds, 0x0018, r16[cx]);
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_9430() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        r16[dx] = memory16get(ds, 0x0012);
        r8[dl] += 0x08;
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        out8(r16[dx], r8[al]);
        r16[cx] = memory16get(ds, 0x0016);
    case 0x9441:
        r16[cx]--;
        if (r16[cx]) {
            pc = 0x9441;
            break;
        }
        r16[dx]++;
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
        r16[cx] = memory16get(ds, 0x0018);
    case 0x944f:
        r16[cx]--;
        if (r16[cx]) {
            pc = 0x944f;
            break;
        }
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_9459() {
    push(r16[ax]);
    r8[al] = 0x36;
    out8(0x43, r8[al]);
    r16[ax] = pop();
    out8(0x40, r8[al]);
    r8[al] = r8[ah];
    out8(0x40, r8[al]);
}
function* sub_9479() {
    push(ds);
    r16[ax] = 0x0b51;
    ds = r16[ax];
    r16[bx] = 0x0001;
    r16[ax] = memory16get(ds, 0x0012);
    push(cs);
    cs = 0x096b;
    yield* sub_96b0();
    assert(cs == 0x01ed);
    r16[bx] = 0x0002;
    r16[ax] = memory16get(ds, 0x0014);
    push(cs);
    cs = 0x096b;
    yield* sub_96b0();
    assert(cs == 0x01ed);
    r16[bx] = 0x0003;
    push(cs);
    cs = 0x096b;
    yield* sub_96b0();
    assert(cs == 0x01ed);
    push(es);
    r16[ax] = 0x0b51;
    es = r16[ax];
    di = 0x000e;
    r16[bx] = 0x0005;
    push(cs);
    cs = 0x096b;
    yield* sub_96b0();
    assert(cs == 0x01ed);
    es = pop();
    ds = pop();
}
function* sub_94d5() {
    r16[bx] = 0x0008;
    push(cs);
    cs = 0x096b;
    yield* sub_96b0();
    assert(cs == 0x01ed);
}
function* sub_94de() {
    r16[bx] = 0x0009;
    push(cs);
    cs = 0x096b;
    yield* sub_96b0();
    assert(cs == 0x01ed);
}
function* sub_9504() {
    push(0x7777);
    push(bp);
    bp = sp;
    push(es);
    push(di);
    r16[bx] = 0x0006;
    di = memory16get(ss, bp + 4);
    es = memory16get(ss, bp + 4 + 2);
    push(cs);
    cs = 0x096b;
    yield* sub_96b0();
    assert(cs == 0x01ed);
    di = pop();
    es = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_953a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0x0b51;
        ds = r16[ax];
        r16[dx] = memory16get(ds, 0x0012);
        r8[dl] += 0x06;
        r8[al] = 0x01;
        out8(r16[dx], r8[al]);
        r8[al] = 0;
    case 0x954c:
        r8[al]--;
        if (r8[al] != 0) {
            pc = 0x954c;
            break;
        }
        out8(r16[dx], r8[al]);
        r16[cx] = 0x0020;
    case 0x9554:
        yield* sub_90e2();
        if (flags.carry) {
            pc = 0x9561;
            break;
        }
        if (r8[al] != 0xaa) {
            pc = 0x9561;
            break;
        }
        flags.carry = r16[ax] < r16[ax];
        r16[ax] = 0;
        pc = 0x9567;
        break;
    case 0x9561:
        if (--r16[cx]) {
            pc = 0x9554;
            break;
        }
        flags.carry = true;
        r16[ax] = 0x0001;
    case 0x9567:
        ds = pop();
        return;
    } while (1);
}
function* sub_956a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0x0b51;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x0012);
        r16[bx] = 0xfffd;
        push(cs);
        cs = 0x0a07;
        yield* sub_a070();
        assert(cs == 0x01ed);
        r16[bx] = 0xffff;
        push(cs);
        cs = 0x0a07;
        yield* sub_a070();
        assert(cs == 0x01ed);
        if (flags.carry) {
            pc = 0x95a1;
            break;
        }
        r16[dx] = 0x0b51;
        r16[ax] = 0x0010;
        r16[bx] = 0x0001;
        push(cs);
        cs = 0x0a07;
        yield* sub_a070();
        assert(cs == 0x01ed);
        memory16set(cs, 0x76d7, r16[dx]);
        memory16set(cs, 0x76d5, r16[ax]);
        r16[ax] = 0x0001;
        pc = 0x95a3;
        break;
    case 0x95a1:
        r16[ax] = 0;
    case 0x95a3:
        ds = pop();
        return;
    } while (1);
}
function* sub_95bc() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    r16[bx] = 0x0006;
    push(cs);
    cs = 0x0a07;
    yield* sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_95cf() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    r16[cx] = memory16get(ss, bp + 8);
    r16[bx] = 0x0002;
    push(cs);
    cs = 0x0a07;
    yield* sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_95e5() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[bx] = 0x0008;
    push(cs);
    cs = 0x0a07;
    yield* sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_9602() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 4);
    r16[bx] = 0x0004;
    push(cs);
    cs = 0x0a07;
    yield* sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_9612() {
    r16[bx] = 0x0007;
    push(cs);
    cs = 0x0a07;
    yield* sub_a070();
    assert(cs == 0x01ed);
}
function* sub_9634() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[bx] = 0x0009;
    push(cs);
    cs = 0x0a07;
    yield* sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_9641() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[bx] = 0x000a;
    push(cs);
    cs = 0x0a07;
    yield* sub_a070();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_964e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[tx] = flags.carry | (flags.zero << 1);
        push(r16[tx]);
        push(ds);
        r16[ax] = 0x0b51;
        ds = r16[ax];
        r16[ax] = 0;
        flags.interrupts = false;
        if (memory[ds*16 + 0x0010] == 0x00) {
            pc = 0x9665;
            break;
        }
        r8[al] = 0xff;
        r8[tl] = memory[ds*16 + 0x0010];
        memory[ds*16 + 0x0010] = r8[al];
        r8[al] = r8[tl];
    case 0x9665:
        ds = pop();
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        return;
    } while (1);
}
function* sub_9668() {
    r16[bx] = 0xfffe;
    push(cs);
    cs = 0x0a07;
    yield* sub_a070();
    assert(cs == 0x01ed);
    r16[bx] = 0x0001;
    r16[dx] = memory16get(cs, 0x76d7);
    r16[ax] = memory16get(cs, 0x76d5);
    push(cs);
    cs = 0x0a07;
    yield* sub_a070();
    assert(cs == 0x01ed);
}
function* sub_96b0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        pc = 0x9e04;
        break;
    case 0x9e04:
        r16[tx] = flags.carry | (flags.zero << 1);
        push(r16[tx]);
        push(ds);
        push(es);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        push(si);
        push(bp);
        bp = sp;
        push(r16[ax]);
        r16[ax] = cs;
        ds = r16[ax];
        es = r16[ax];
        r16[ax] = pop();
        flags.direction = false;
        if (r16[bx] >= 0x000e) {
            pc = 0x9e35;
            break;
        }
        if (r16[bx] < 0x0004) {
            pc = 0x9e2a;
            break;
        }
        if (memory[ds*16 + 0x00b1] == 0x00) {
            pc = 0x9e35;
            break;
        }
    case 0x9e2a:
        r16[bx] <<= 1;
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 133));
        memory16set(ss, bp + 12, r16[ax]);
        pc = 0x9e3a;
        break;
    case 0x9e35:
        memory16set(ss, bp + 12, 0xffff);
    case 0x9e3a:
        bp = pop();
        si = pop();
        di = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        es = pop();
        ds = pop();
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}
function* sub_a070() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        pc = 0xb17f;
        break;
    case 0xb17f:
        push(ds);
        push(es);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        push(si);
        push(bp);
        bp = sp;
        r16[ax] = cs;
        ds = r16[ax];
        es = r16[ax];
        r16[ax] = memory16get(ss, bp + 12);
        flags.carry = memory[ds*16 + 0x01e4] < 0x00;
        if (memory[ds*16 + 0x01e4] != 0x00) {
            pc = 0xb1ce;
            break;
        }
        memory[ds*16 + 0x01e4] = 0x01;
        flags.interrupts = true;
        flags.direction = false;
        memory16set(ss, bp + 12, 0xffff);
        if (r16[bx] & 0x8000) {
            pc = 0xb1b7;
            break;
        }
        flags.carry = r16[bx] < 0x000f;
        if (r16[bx] >= 0x000f) {
            pc = 0xb1c7;
            break;
        }
        r16[bx] <<= 1;
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 609));
        pc = 0xb1c4;
        break;
    case 0xb1b7:
        r16[bx] = ~r16[bx];
        flags.carry = r16[bx] < 0x0003;
        if (r16[bx] >= 0x0003) {
            pc = 0xb1c7;
            break;
        }
        r16[bx] <<= 1;
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 639));
    case 0xb1c4:
        memory16set(ss, bp + 12, r16[ax]);
    case 0xb1c7:
        memory[ds*16 + 0x01e4] = 0x00;
        pc = 0xb1d3;
        break;
    case 0xb1ce:
        memory16set(ss, bp + 12, 0xfff8);
    case 0xb1d3:
        bp = pop();
        si = pop();
        di = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        es = pop();
        ds = pop();
        assert(pop() == 0x7777);
        cs = pop();
        return;
    } while (1);
}