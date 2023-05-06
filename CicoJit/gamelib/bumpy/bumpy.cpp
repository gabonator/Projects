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
    headerSize = 0x1200;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x1c49;
    sp = 0x0080;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/bumpy/dos", "B.EXE", 112704);
    fixReloc(cs);
    sub_1ed0();
}
void fixReloc(uint16_t seg)
{
    memory16(0x0000 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x000b + seg, 0x000d) += seg; // 103a -> 1227
    memory16(0x000f + seg, 0x0007) += seg; // 103a -> 1227
    memory16(0x0753 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x0757 + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x0759 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x075a + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x075f + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0772 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0773 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x077d + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x0781 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0786 + seg, 0x0005) += seg; // 103b -> 1228
    memory16(0x0798 + seg, 0x000f) += seg; // 103b -> 1228
    memory16(0x079b + seg, 0x000c) += seg; // 0000 -> 01ed
    memory16(0x079d + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x07a2 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x07a7 + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x07a7 + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x07ab + seg, 0x000f) += seg; // 103b -> 1228
    memory16(0x07b2 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x07b3 + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x07b5 + seg, 0x0007) += seg; // 0ab9 -> 0ca6
    memory16(0x07b7 + seg, 0x0003) += seg; // 0c28 -> 0e15
    memory16(0x07b8 + seg, 0x0003) += seg; // 0ab9 -> 0ca6
    memory16(0x07b9 + seg, 0x0000) += seg; // 0ab9 -> 0ca6
    memory16(0x07ba + seg, 0x0003) += seg; // 0ab9 -> 0ca6
    memory16(0x07ba + seg, 0x000a) += seg; // 0ab9 -> 0ca6
    memory16(0x07bb + seg, 0x000a) += seg; // 0ab9 -> 0ca6
    memory16(0x07bc + seg, 0x0007) += seg; // 0ab9 -> 0ca6
    memory16(0x07bd + seg, 0x0004) += seg; // 0ab9 -> 0ca6
    memory16(0x07bd + seg, 0x000a) += seg; // 0ab9 -> 0ca6
    memory16(0x07be + seg, 0x0007) += seg; // 0ab9 -> 0ca6
    memory16(0x07bf + seg, 0x0007) += seg; // 0ab9 -> 0ca6
    memory16(0x07c3 + seg, 0x0005) += seg; // 103b -> 1228
    memory16(0x07c5 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x07c9 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x07ca + seg, 0x000f) += seg; // 103b -> 1228
    memory16(0x07cb + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x07d5 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x07d6 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x07d8 + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x07ff + seg, 0x0003) += seg; // 103b -> 1228
    memory16(0x0801 + seg, 0x000f) += seg; // 0000 -> 01ed
    memory16(0x0803 + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0804 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x0805 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x0806 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0807 + seg, 0x0003) += seg; // 103b -> 1228
    memory16(0x0809 + seg, 0x000b) += seg; // 0cd5 -> 0ec2
    memory16(0x080a + seg, 0x0008) += seg; // 0cd5 -> 0ec2
    memory16(0x080b + seg, 0x0009) += seg; // 0ab9 -> 0ca6
    memory16(0x080c + seg, 0x0009) += seg; // 0ab9 -> 0ca6
    memory16(0x0868 + seg, 0x000f) += seg; // 103b -> 1228
    memory16(0x0870 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0871 + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x0896 + seg, 0x0003) += seg; // 0000 -> 01ed
    memory16(0x0897 + seg, 0x0009) += seg; // 103b -> 1228
    memory16(0x089a + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x089b + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x089d + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x089f + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x08b8 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x08c0 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x08ed + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x0900 + seg, 0x000e) += seg; // 0000 -> 01ed
    memory16(0x0907 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0908 + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x090c + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x0924 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x0925 + seg, 0x0007) += seg; // 0000 -> 01ed
    memory16(0x0937 + seg, 0x0001) += seg; // 0cda -> 0ec7
    memory16(0x0938 + seg, 0x000b) += seg; // 0cda -> 0ec7
    memory16(0x0939 + seg, 0x000f) += seg; // 0cda -> 0ec7
    memory16(0x093a + seg, 0x000e) += seg; // 0ce5 -> 0ed2
    memory16(0x093b + seg, 0x0004) += seg; // 0ce5 -> 0ed2
    memory16(0x093c + seg, 0x0005) += seg; // 0ab9 -> 0ca6
    memory16(0x093d + seg, 0x0005) += seg; // 0ab9 -> 0ca6
    memory16(0x093d + seg, 0x000e) += seg; // 0cec -> 0ed9
    memory16(0x093e + seg, 0x000f) += seg; // 0cec -> 0ed9
    memory16(0x093f + seg, 0x0008) += seg; // 0cec -> 0ed9
    memory16(0x0940 + seg, 0x0002) += seg; // 0cec -> 0ed9
    memory16(0x0940 + seg, 0x000c) += seg; // 0cec -> 0ed9
    memory16(0x0941 + seg, 0x0006) += seg; // 0cec -> 0ed9
    memory16(0x0942 + seg, 0x0000) += seg; // 0cec -> 0ed9
    memory16(0x0942 + seg, 0x0007) += seg; // 0cec -> 0ed9
    memory16(0x0943 + seg, 0x0000) += seg; // 0cec -> 0ed9
    memory16(0x094e + seg, 0x0005) += seg; // 0000 -> 01ed
    memory16(0x0955 + seg, 0x0000) += seg; // 0000 -> 01ed
    memory16(0x0959 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x097a + seg, 0x0007) += seg; // 102c -> 1219
    memory16(0x097b + seg, 0x000c) += seg; // 0ab9 -> 0ca6
    memory16(0x097c + seg, 0x0002) += seg; // 0ab9 -> 0ca6
    memory16(0x097d + seg, 0x0002) += seg; // 0ab9 -> 0ca6
    memory16(0x097e + seg, 0x0002) += seg; // 0ab9 -> 0ca6
    memory16(0x097e + seg, 0x0008) += seg; // 0ab9 -> 0ca6
    memory16(0x097e + seg, 0x000e) += seg; // 0ab9 -> 0ca6
    memory16(0x097f + seg, 0x0004) += seg; // 0ab9 -> 0ca6
    memory16(0x0980 + seg, 0x0001) += seg; // 0ab9 -> 0ca6
    memory16(0x0981 + seg, 0x0001) += seg; // 0ab9 -> 0ca6
    memory16(0x0981 + seg, 0x000e) += seg; // 0ab9 -> 0ca6
    memory16(0x0983 + seg, 0x0004) += seg; // 0ab9 -> 0ca6
    memory16(0x0984 + seg, 0x0004) += seg; // 0ab9 -> 0ca6
    memory16(0x0985 + seg, 0x0001) += seg; // 0ab9 -> 0ca6
    memory16(0x0986 + seg, 0x0001) += seg; // 0ab9 -> 0ca6
    memory16(0x0986 + seg, 0x0007) += seg; // 1036 -> 1223
    memory16(0x0a0b + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x0aba + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x0abd + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0ac2 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x0ac7 + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0acd + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0ad1 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x0ad6 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0ad7 + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0adb + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0add + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0ae2 + seg, 0x000d) += seg; // 0cd5 -> 0ec2
    memory16(0x0ae4 + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0ae6 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0aea + seg, 0x000b) += seg; // 0000 -> 01ed
    memory16(0x0aeb + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x0aed + seg, 0x0009) += seg; // 0000 -> 01ed
    memory16(0x0aef + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0af1 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0b0f + seg, 0x000e) += seg; // 0cda -> 0ec7
    memory16(0x0b10 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x0b13 + seg, 0x000a) += seg; // 0cda -> 0ec7
    memory16(0x0b1c + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x0b3a + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0b3d + seg, 0x0002) += seg; // 0cda -> 0ec7
    memory16(0x0b3d + seg, 0x000d) += seg; // 0cda -> 0ec7
    memory16(0x0b3e + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x0b42 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0b4d + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x0b54 + seg, 0x0008) += seg; // 0cda -> 0ec7
    memory16(0x0b55 + seg, 0x0003) += seg; // 0cda -> 0ec7
    memory16(0x0b56 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0b5b + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0b60 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0b65 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x0b68 + seg, 0x0004) += seg; // 0cda -> 0ec7
    memory16(0x0b69 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0b6d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x0b7d + seg, 0x0003) += seg; // 103b -> 1228
    memory16(0x0b83 + seg, 0x000d) += seg; // 0cda -> 0ec7
    memory16(0x0b84 + seg, 0x000f) += seg; // 103b -> 1228
    memory16(0x0b8b + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x0b90 + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x0b96 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x0b98 + seg, 0x000e) += seg; // 0cda -> 0ec7
    memory16(0x0b99 + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x0b9c + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x0ba8 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x0bae + seg, 0x000c) += seg; // 0cda -> 0ec7
    memory16(0x0baf + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x0bb5 + seg, 0x0007) += seg; // 0cda -> 0ec7
    memory16(0x0bb6 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x0bbb + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x0bc0 + seg, 0x0009) += seg; // 103b -> 1228
    memory16(0x0bc2 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0bc4 + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x0bd2 + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x0bd7 + seg, 0x0009) += seg; // 103b -> 1228
    memory16(0x0bdc + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0be0 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0be4 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x0be6 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x0bea + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0bec + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0bee + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x0bef + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x0bf1 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0bf5 + seg, 0x0003) += seg; // 103b -> 1228
    memory16(0x0bfa + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0bfb + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x0bfd + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0bfe + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x0c06 + seg, 0x0000) += seg; // 0cec -> 0ed9
    memory16(0x0c13 + seg, 0x000f) += seg; // 103b -> 1228
    memory16(0x0c21 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x0c28 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x0c2b + seg, 0x0003) += seg; // 0cda -> 0ec7
    memory16(0x0c2c + seg, 0x0009) += seg; // 103b -> 1228
    memory16(0x0c2e + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0c34 + seg, 0x0007) += seg; // 0cda -> 0ec7
    memory16(0x0c36 + seg, 0x0000) += seg; // 0cda -> 0ec7
    memory16(0x0c37 + seg, 0x000c) += seg; // 0cda -> 0ec7
    memory16(0x0c39 + seg, 0x0001) += seg; // 0cda -> 0ec7
    memory16(0x0c40 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x0c41 + seg, 0x0005) += seg; // 103b -> 1228
    memory16(0x0c42 + seg, 0x000a) += seg; // 0cda -> 0ec7
    memory16(0x0c45 + seg, 0x0004) += seg; // 0cda -> 0ec7
    memory16(0x0c46 + seg, 0x0007) += seg; // 0cda -> 0ec7
    memory16(0x0c47 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0c48 + seg, 0x0000) += seg; // 0cda -> 0ec7
    memory16(0x0c4c + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0c4e + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0c51 + seg, 0x0009) += seg; // 103b -> 1228
    memory16(0x0c53 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x0c54 + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x0c56 + seg, 0x0005) += seg; // 0cda -> 0ec7
    memory16(0x0c58 + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0c59 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x0c5c + seg, 0x0006) += seg; // 0cda -> 0ec7
    memory16(0x0c5e + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x0c5f + seg, 0x0009) += seg; // 103b -> 1228
    memory16(0x0c62 + seg, 0x0007) += seg; // 0cda -> 0ec7
    memory16(0x0c64 + seg, 0x0009) += seg; // 103b -> 1228
    memory16(0x0c65 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0c67 + seg, 0x0003) += seg; // 0cda -> 0ec7
    memory16(0x0c69 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x0c6b + seg, 0x0001) += seg; // 0cda -> 0ec7
    memory16(0x0c6c + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x0c6e + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0c6f + seg, 0x000c) += seg; // 0cda -> 0ec7
    memory16(0x0c73 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0c74 + seg, 0x0008) += seg; // 0cda -> 0ec7
    memory16(0x0c76 + seg, 0x0009) += seg; // 0cda -> 0ec7
    memory16(0x0c7d + seg, 0x000c) += seg; // 0cda -> 0ec7
    memory16(0x0c83 + seg, 0x0003) += seg; // 0cda -> 0ec7
    memory16(0x0c84 + seg, 0x0004) += seg; // 0cda -> 0ec7
    memory16(0x0c84 + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x0c86 + seg, 0x0002) += seg; // 0cda -> 0ec7
    memory16(0x0c87 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0c91 + seg, 0x0006) += seg; // 0cda -> 0ec7
    memory16(0x0c92 + seg, 0x0009) += seg; // 0cda -> 0ec7
    memory16(0x0c93 + seg, 0x0007) += seg; // 0cda -> 0ec7
    memory16(0x0c95 + seg, 0x0008) += seg; // 0cda -> 0ec7
    memory16(0x0c9c + seg, 0x000e) += seg; // 0cda -> 0ec7
    memory16(0x0ca2 + seg, 0x000f) += seg; // 0cda -> 0ec7
    memory16(0x0ca4 + seg, 0x0000) += seg; // 0cda -> 0ec7
    memory16(0x0ca4 + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0ca7 + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x0cb2 + seg, 0x0007) += seg; // 103b -> 1228
    memory16(0x0cb6 + seg, 0x000c) += seg; // 0cda -> 0ec7
    memory16(0x0cb9 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0cbd + seg, 0x0008) += seg; // 0cda -> 0ec7
    memory16(0x0cbf + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x0cc2 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0cc6 + seg, 0x0009) += seg; // 0cda -> 0ec7
    memory16(0x0cc7 + seg, 0x0008) += seg; // 0cda -> 0ec7
    memory16(0x0cc8 + seg, 0x0001) += seg; // 103b -> 1228
    memory16(0x0cda + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x0cde + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x0ce5 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x0ce7 + seg, 0x0005) += seg; // 103b -> 1228
    memory16(0x0f99 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x0fbd + seg, 0x000b) += seg; // 103b -> 1228
    memory16(0x0fc0 + seg, 0x0009) += seg; // 103b -> 1228
    memory16(0x0fc3 + seg, 0x0003) += seg; // 103b -> 1228
    memory16(0x0fc6 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x0fc9 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x0fca + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x0fcb + seg, 0x0003) += seg; // 103b -> 1228
    memory16(0x0fcd + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x0fd8 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x0ff4 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x0fff + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x1007 + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x1009 + seg, 0x000d) += seg; // 103b -> 1228
    memory16(0x100b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x102c + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1030 + seg, 0x000d) += seg; // 0000 -> 01ed
    memory16(0x1031 + seg, 0x0006) += seg; // 0000 -> 01ed
    memory16(0x1031 + seg, 0x000f) += seg; // 0000 -> 01ed
    memory16(0x1032 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x1035 + seg, 0x0001) += seg; // 0000 -> 01ed
    memory16(0x1044 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1044 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1045 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1046 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1046 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1047 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1047 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1048 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1049 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1049 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1092 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x10a9 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x10aa + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x10aa + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x10aa + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x10aa + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x10ab + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x10ab + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x10ab + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x10ab + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x10b1 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x10b1 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x10b1 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x10c6 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10c6 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x10c7 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x10c7 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x10c7 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10c7 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x10c8 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x10c8 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x10c8 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10c8 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x10c9 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x10c9 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x10c9 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10c9 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x10ca + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x10ca + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10cb + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x10cb + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10cc + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x10cc + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10cd + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x10cd + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10ce + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x10ce + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x10cf + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x10d0 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x10d0 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x10d1 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x10d2 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x10d2 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10d3 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x10d3 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x10d4 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x10d5 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x10d5 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x10d6 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x10d7 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x10d7 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x10d8 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x10d8 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1147 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1148 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1148 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1148 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1148 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1149 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1149 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1149 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1149 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x114a + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x114a + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x114a + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x114a + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x114b + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x114b + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x114b + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x114b + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x114c + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1155 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1155 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1155 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1155 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1156 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1170 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1171 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1171 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1171 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1171 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1172 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1172 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1172 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1178 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x117d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1182 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1186 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1189 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1191 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1196 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x119a + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x119b + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x11a1 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x11a7 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x11a8 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x11b0 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x11b4 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x11bb + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x11c0 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x11c4 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x11c9 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x11cd + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x11d2 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x11d9 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x11df + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x11e5 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x11ec + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x11f1 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x11f1 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x11f8 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x11fb + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x11ff + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x11ff + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1204 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1205 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x120a + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x120a + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x120e + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x120f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1214 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1214 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1218 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1220 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x122a + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x122d + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1231 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1231 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1237 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1237 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x123e + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x123f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1243 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1243 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1249 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1249 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x124f + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1254 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x125a + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1260 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1260 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1260 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1260 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1261 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1261 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1261 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1262 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1262 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1262 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1262 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1263 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1263 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1263 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1264 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1264 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1264 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1264 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1265 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1265 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1265 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1265 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1266 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1266 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1266 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1266 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1267 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1267 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1267 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1268 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1268 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1268 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1268 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1269 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1269 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x126a + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x126a + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x126a + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x126a + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x126b + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x126b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x126b + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x126b + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x126c + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x126c + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x126c + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x126c + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x126d + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x126d + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x126d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x126d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x126e + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x126e + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x126e + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x126e + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x126f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x126f + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x126f + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x126f + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1270 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1273 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1276 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x127a + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x127b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x127f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1282 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1286 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1287 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x128c + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x128d + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x128d + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x128d + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x128e + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x128e + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x128e + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x128e + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x128f + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x128f + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1291 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x12bc + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12bd + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x12bf + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x12bf + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x12c0 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x12c1 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x12c2 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x12c4 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x12c5 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x12c7 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x12c8 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12c9 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x12cb + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x12cc + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12ce + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x12d0 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12d1 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12d2 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12d3 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x12d4 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x12d5 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x12d6 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x12d7 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x12d8 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x12d9 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x12da + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x12db + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x12dc + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12dd + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x12de + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x12df + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12e0 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12e1 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x12e2 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12e4 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12e5 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12e6 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x12e8 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x12e9 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x12ea + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x12eb + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12ec + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12ed + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12ee + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12f0 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x12f1 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x12f1 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12f3 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x12f3 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12f5 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x12f6 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x12f6 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12f8 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x12f8 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12f9 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12fa + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x12fc + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x12fd + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x12fe + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1300 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1302 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1302 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1303 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1304 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1305 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1306 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1307 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1309 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x130a + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x130b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x130c + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x130d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x130e + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1310 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1311 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1313 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1314 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1315 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1316 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1317 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1319 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x131a + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x131b + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x131c + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x131d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x131e + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1320 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1321 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1323 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1324 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1324 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1325 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1326 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1327 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1328 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1329 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1329 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1329 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x132a + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x132a + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x132a + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x132a + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x132b + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x132b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x132b + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x132b + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x132c + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x132c + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x132c + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x132c + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x132d + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x132d + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x132d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x132d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x132e + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x132e + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x132e + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x132e + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x132f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x132f + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x132f + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x132f + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1330 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1330 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1330 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1330 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1331 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1331 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1331 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1331 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1332 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1332 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1332 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1332 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1333 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1333 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1333 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1333 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1334 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1334 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1334 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1334 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1335 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1335 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1335 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1335 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1336 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1336 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1336 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1336 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1337 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1337 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1337 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1337 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1338 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1338 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1338 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1338 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1339 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1339 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1339 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1339 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x133a + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x133a + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x133a + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x133a + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x133b + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x133b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x133b + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x133b + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x133c + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x133c + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x133c + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x133c + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x133d + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x133d + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x133d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x133d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x133e + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x133e + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x133e + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x133e + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x133f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x133f + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x133f + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x133f + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1340 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1340 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1340 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1340 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1341 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1343 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1344 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1346 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1347 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1348 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x134a + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x134b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x134c + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x134d + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x134e + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1350 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1351 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1352 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1353 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1354 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1356 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1357 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1358 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x135a + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x135b + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x135d + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x135f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1360 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1360 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1361 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1361 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1361 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1361 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1362 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1362 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1362 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1362 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1363 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1363 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1363 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1363 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1364 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1364 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1364 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1364 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1365 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1365 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1365 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1365 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1366 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1366 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1366 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1412 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1412 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1412 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1412 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1413 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1413 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1413 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1413 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1414 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1414 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1414 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1414 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1415 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1415 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1415 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1415 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1416 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1416 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1416 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1416 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1417 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1417 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1417 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1417 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1418 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1418 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1418 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1418 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1419 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1419 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1419 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1419 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x141a + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x141a + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x141a + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x141a + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x141b + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x141b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x141b + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x141b + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x141c + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x141c + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x141c + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x141c + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x141d + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x141d + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x141d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x141d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x141e + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x141e + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x141e + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x141e + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x141f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x141f + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x141f + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x141f + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1420 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1420 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1420 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1420 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1421 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1421 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1421 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1421 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1422 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1422 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1422 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1422 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1423 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1423 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1423 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1423 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1424 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1424 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1424 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1424 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1425 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1425 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1425 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1425 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1426 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1426 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1426 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1426 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1427 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1427 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1427 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1427 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1428 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1428 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1428 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1428 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1429 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1429 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1429 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1429 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x142a + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x142a + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x142a + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x142a + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x142b + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x142b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x142b + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x142b + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x142c + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x142c + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x142c + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x142c + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x142d + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x142d + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x142d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x142d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x142e + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x142e + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x142e + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x142e + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x142f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x142f + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x142f + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x142f + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1430 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1430 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1430 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1430 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1431 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1431 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1431 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1431 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1432 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1432 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1432 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1432 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1433 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1433 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1433 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1433 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1434 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1434 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1434 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1434 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1435 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1435 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1435 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1435 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1436 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1436 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1436 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1436 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1437 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1437 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1437 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1437 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1438 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1438 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1438 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1438 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1439 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1439 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1439 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1439 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x143a + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x143a + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x143a + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x143a + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x143b + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x143b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x143b + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x143b + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x143c + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x143c + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x143c + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x143c + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x143d + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x143d + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x143d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x143d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x143e + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x143e + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x143e + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x143e + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x143f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x143f + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x143f + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x143f + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1440 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1440 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1440 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1440 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1441 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1441 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1441 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1441 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1442 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1442 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1442 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1442 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1443 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1445 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1446 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1446 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1446 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1446 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1447 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1447 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1447 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1447 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1448 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1448 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1448 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1448 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1449 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1449 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1449 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1449 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x144a + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x144a + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x144a + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x144a + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x144b + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x144b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x144b + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x144b + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x144c + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x144c + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x144c + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x144c + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x144d + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x144d + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x144d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x144d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x144e + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x144e + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x144e + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x144e + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x144f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x144f + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x144f + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x144f + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1450 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1450 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1450 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1450 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1451 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1451 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1451 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1451 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1452 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1452 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1452 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1452 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1453 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1453 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1453 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1453 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1454 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1454 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1454 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1454 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1455 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1455 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1455 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1455 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1456 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1456 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1456 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1456 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1457 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1457 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1457 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1457 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1458 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1458 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1458 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1458 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1459 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1459 + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x1459 + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x1459 + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x145a + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x145a + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x145a + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x145a + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x145b + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x145b + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x145b + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x145b + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x145c + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x145c + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x145c + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x145c + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x145d + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x145d + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x145d + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x145d + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x145e + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x145e + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x145e + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x145e + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x145f + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x145f + seg, 0x0004) += seg; // 103b -> 1228
    memory16(0x145f + seg, 0x0008) += seg; // 103b -> 1228
    memory16(0x145f + seg, 0x000c) += seg; // 103b -> 1228
    memory16(0x1460 + seg, 0x0000) += seg; // 103b -> 1228
    memory16(0x1502 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1502 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1502 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1502 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1506 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1507 + seg, 0x0002) += seg; // 103b -> 1228
    memory16(0x1507 + seg, 0x0006) += seg; // 103b -> 1228
    memory16(0x1507 + seg, 0x000a) += seg; // 103b -> 1228
    memory16(0x1507 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x1584 + seg, 0x0004) += seg; // 0000 -> 01ed
    memory16(0x1584 + seg, 0x0008) += seg; // 0000 -> 01ed
    memory16(0x1587 + seg, 0x000e) += seg; // 103b -> 1228
    memory16(0x15a9 + seg, 0x0000) += seg; // 103b -> 1228
}
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
// skipping indirect call
void sub_1ed0();
void sub_1fc6();
void sub_1fe5();
void sub_1fff();
void sub_2042();
void sub_206f();
void sub_20b2();
void sub_20d3();
void sub_2128();
void sub_2152();
void sub_22ba();
void sub_22e6();
void sub_2439();
void sub_24b7();
void sub_24d4();
void sub_250b();
void sub_26c0();
void sub_26e6();
void sub_27a1();
void sub_28d7();
void sub_2960();
void sub_2a58();
void sub_2ac9();
void sub_2ae8();
void sub_2c6d();
void sub_2e4a();
void sub_30bb();
void sub_3219();
void sub_325c();
void sub_3282();
void sub_32af();
void sub_3343();
void sub_33b4();
void sub_3471();
void sub_352e();
void sub_3697();
void sub_3871();
void sub_38b4();
void sub_38f0();
void sub_3937();
void sub_39fb();
void sub_3aa7();
void sub_3b11();
void sub_3b82();
void sub_3bba();
void sub_3bf6();
void sub_3cae();
void sub_3cd2();
void sub_3d0d();
void sub_3e8e();
void sub_3f4d();
void sub_415d();
void sub_4180();
void sub_4191();
void sub_41a2();
void sub_41cc();
void sub_420a();
void sub_423f();
void sub_425e();
void sub_4286();
void sub_42f3();
void sub_4340();
void sub_435e();
void sub_43a7();
void sub_43da();
void sub_440f();
void sub_447d();
void sub_4504();
void sub_4571();
void sub_45dc();
void sub_4646();
void sub_46ae();
void sub_46e0();
void sub_47b0();
void sub_47c9();
void sub_4835();
void sub_4876();
void sub_48da();
void sub_4948();
void sub_4be4();
void sub_4dc8();
void sub_4e7c();
void sub_4fad();
void sub_50ae();
void sub_515f();
void sub_5180();
void sub_5295();
void sub_5337();
void sub_5475();
void sub_5722();
void sub_5958();
void sub_5982();
void sub_59df();
void sub_5a3c();
void sub_5a99();
void sub_5af6();
void sub_5b1f();
void sub_5b6d();
void sub_5bc7();
void sub_5ccd();
void sub_5d44();
void sub_5d5a();
void sub_5da4();
void sub_5ee5();
void sub_6133();
void sub_61a9();
void sub_61d5();
void sub_6231();
void sub_650d();
void sub_652e();
void sub_654d();
void sub_656c();
void sub_658b();
void sub_65fd();
void sub_6617();
void sub_669b();
void sub_66d2();
void sub_670c();
void sub_6779();
void sub_67d6();
void sub_682c();
void sub_6865();
void sub_68a7();
void sub_6a1e();
void sub_6a96();
void sub_6ae4();
void sub_6b69();
void sub_6c8f();
void sub_6cca();
void sub_6d4f();
void sub_6d99();
void sub_6dd4();
void sub_6e1e();
void sub_6e59();
void sub_6ea3();
void sub_6ed3();
void sub_6f29();
void sub_6f3f();
void sub_6f55();
void sub_6f90();
void sub_6fcb();
void sub_7051();
void sub_70a8();
void sub_722e();
void sub_7551();
void sub_76b1();
void sub_78a3();
void sub_7b57();
void sub_7eab();
void sub_7f0d();
void sub_8000();
void sub_8053();
void sub_816c();
void sub_81d5();
void sub_81f6();
void sub_8242();
void sub_828e();
void sub_82dc();
void sub_834e();
void sub_83b2();
void sub_83cf();
void sub_83ec();
void sub_8405();
void sub_841e();
void sub_8457();
void sub_84a2();
void sub_84b5();
void sub_84cb();
void sub_84e1();
void sub_84f7();
void sub_8518();
void sub_8569();
void sub_85a8();
void sub_85e7();
void sub_860a();
void sub_8618();
void sub_8659();
void sub_87ce();
void sub_880a();
void sub_882e();
void sub_8857();
void sub_887a();
void sub_8959();
void sub_8a85();
void sub_8aa4();
void sub_8ac4();
void sub_8ae4();
void sub_8b65();
void sub_8bf6();
void sub_8c3a();
void sub_8c64();
void sub_8cb3();
void sub_8ce1();
void sub_8d00();
void sub_8fe1();
void sub_8ff0();
void sub_9105();
void sub_91bf();
void sub_91d7();
void sub_91e9();
void sub_923f();
void sub_932e();
void sub_93a5();
void sub_9402();
void sub_9433();
void sub_944b();
void sub_9472();
void sub_960c();
void sub_96a9();
void sub_9731();
void sub_985a();
void sub_98b6();
void sub_9947();
void sub_9984();
void sub_998b();
void sub_99d1();
void sub_9a1a();
void sub_9a2a();
void sub_9a63();
void sub_9a77();
void sub_9a7d();
void sub_9a8d();
void sub_9a9a();
void sub_9aa7();
void sub_9aad();
void sub_9aca();
void sub_9bae();
void sub_9c82();
void sub_9c89();
void sub_9cc9();
void sub_9ce8();
void sub_9cef();
void sub_9d32();
void sub_9e60();
void sub_9e63();
void sub_9e66();
void sub_9e69();
void sub_9e6a();
void sub_9e80();
void sub_9f5e();
void sub_9f6e();
void sub_9f7c();
void sub_9f8c();
void sub_a485();
void sub_a4ab();
void sub_a4d0();
void sub_a4f6();
void sub_a5b9();
void sub_a5f2();
void sub_a5fe();
void sub_a60c();
void sub_a672();
void sub_a6d9();
void sub_a761();
void sub_a7b5();
void sub_a7ee();
void sub_a847();
void sub_a869();
void sub_a878();
void sub_a8b2();
void sub_a8d7();
void sub_a8f3();
void sub_a945();
void sub_a9a0();
void sub_a9c6();
void sub_a9d4();
void sub_a9dd();
void sub_a9fa();
void sub_aa3b();
void sub_aa51();
void sub_aa98();
void sub_acff();
void sub_ad18();
void sub_ad20();
void sub_ad28();
void sub_ad63();
void sub_ad73();
void sub_adbb();
void sub_ae86();
void sub_aed7();
void sub_af26();
void sub_af2d();
void sub_afe5();
void sub_b09f();
void sub_b0a7();
void sub_b0af();
void sub_b0fc();
void sub_b14c();
void sub_b274();
void sub_b281();
void sub_b288();
void sub_b298();
void sub_b2a8();
void sub_b2d6();
void sub_b2e0();
void sub_b2f4();
void sub_b2fa();
void sub_b304();
void sub_b321();
void sub_b32b();
void sub_b33e();
void sub_b674();
void sub_b67a();
void sub_b695();
void sub_b6a5();
void sub_b6c1();
void sub_b6d4();
void sub_b6e4();
void sub_b6f1();
void sub_b707();
void sub_b734();
void sub_b75e();
void sub_b78a();
void sub_b7ad();
void sub_b82b();
void sub_b86a();
void sub_b8d7();
void sub_b9a3();
void sub_b9e4();
void sub_ba68();
void sub_bb32();
void sub_bba3();
void sub_bcce();
void sub_be68();
void sub_be85();
void sub_bf70();
void sub_bfb9();
void sub_c01f();
void sub_c048();
void sub_c085();
void sub_c096();
void sub_c0bf();
void sub_c0da();
void sub_c0ec();
void sub_c230();
void sub_c27e();
void sub_c336();
void sub_c352();
void sub_c36e();
void sub_c3cc();
void sub_c42e();
void sub_c49f();
void sub_c4c8();
void sub_c4fe();
void sub_c527();
void sub_c588();
void sub_c5c1();
void sub_c5e4();
void sub_c7be();
void sub_c865();
void sub_c8c5();
void sub_c8e4();
void sub_c8fb();
void sub_c91e();
void sub_c9ad();
void sub_ca53();
void sub_ca60();
void sub_ca8b();
void sub_caa7();
void sub_cbd9();
void sub_cc41();
void sub_cc5f();
void sub_cc7b();
void sub_cc92();
void sub_cd11();
void sub_cd2e();
void sub_cdb1();
void sub_ce87();
void sub_cf8d();
void sub_d016();
void sub_d02e();
void sub_d02f();
void sub_d080();
void sub_d0ad();
void sub_d0bf();
void sub_d0d7();
void sub_d121();
void sub_d250();
void sub_d283();
void sub_d2b8();
void sub_d37f();
void sub_d3a7();
void sub_d4d3();
void sub_d500();
void sub_d530();
void sub_d593();
void sub_d65d();
void sub_d665();
void sub_d69e();
void sub_d7d7();
void sub_d810();
void sub_d840();
void sub_d869();
void sub_da88();
void sub_dac0();
void sub_dae7();
void sub_dcce();
void sub_dd71();
void sub_dd8b();
void sub_dddb();
void sub_de1c();
void sub_de4c();
void sub_de69();
void sub_de82();
void sub_dea1();
void sub_deb8();
void sub_deee();
void sub_df33();
void sub_df4f();
void sub_df5f();
void sub_df90();
void sub_dfbf();
void sub_dfee();
void sub_e01d();
void sub_e067();
void sub_e150();
void sub_e1ce();
void sub_e2e4();
void sub_e600();
void sub_eb59();
void sub_ec20();
void sub_ec52();
void sub_ec70();
void sub_ecb5();
void sub_ecf9();
void sub_ed20();
void sub_ed3f();
void sub_f9c4();
void sub_fa07();
void sub_fb7f();
void sub_fbb9();
void sub_fbc4();
void sub_fbd8();
void sub_fce0();
void sub_fdcd();
void sub_fe71();
void sub_11a7d();
void sub_11aa5();
void sub_11afd();
void sub_11b38();
void sub_11b62();
void sub_11b7d();
void sub_11ec7();
void sub_11f47();
void sub_12190();
void sub_12230();
void sub_12245();
void sub_1ed0() // 01ed:0000
{
    CStackGuard sg(0, true);
    push(0x7777);
    dx = 0x1228;
    memoryASet16(cs, 0x01ff, dx);
    ah = 0x30;
    interrupt(0x21);
    bp = memoryAGet16(ds, 0x0002);
    bx = memoryAGet16(ds, 0x002c);
    ds = dx;
    memoryASet16(ds, 0x007b, ax);
    memoryASet16(ds, 0x0079, es);
    memoryASet16(ds, 0x0075, bx);
    memoryASet16(ds, 0x008d, bp);
    sub_1fff();
    di = memoryAGet16(ds, 0x0073);
    es = memoryAGet16(ds, 0x0073 + 2);
    ax = di;
    bx = ax;
    cx = 0x7fff;
    flags.direction = false;
loc_1f04: // 01ed:0034
    repne_scasb<MemAuto, DirAuto>(al);
    if (cx == 0)
        goto loc_1f44;
    bx++;
    if (memoryAGet(es, di) != al)
        goto loc_1f04;
    ch |= 0x80;
    cx = -cx;
    memoryASet16(ds, 0x0073, cx);
    cx = 0x0002;
    bx <<= cl;
    bx += 0x0010;
    bx &= 0xfff0;
    memoryASet16(ds, 0x0077, bx);
    dx = ss;
    bp -= dx;
    di = memoryAGet16(ds, 0x6b4c);
    if (di >= 0x0200)
        goto loc_1f3b;
    di = 0x0200;
    memoryASet16(ds, 0x6b4c, di);
loc_1f3b: // 01ed:006b
    cl = 0x04;
    di >>= cl;
    di++;
    if (bp >= di)
        goto loc_1f47;
loc_1f44: // 01ed:0074
    goto loc_20ba;
loc_1f47: // 01ed:0077
    bx = di;
    bx += dx;
    memoryASet16(ds, 0x0085, bx);
    memoryASet16(ds, 0x0089, bx);
    ax = memoryAGet16(ds, 0x0079);
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
    memoryASet16(ds, 0x6b4c, di);
    flags.interrupts = true;
    ax = 0;
    es = memoryAGet16(cs, 0x01ff);
    di = 0x6bba;
    cx = 0xa202;
    cx -= di;
    flags.direction = false;
    rep_stosb<MemAuto, DirAuto>();
    ah = 0x00;
    interrupt(0x1a);
    memoryASet16(ds, 0x007f, dx);
    memoryASet16(ds, 0x0081, cx);
    bp = 0;
    ax = 0x1227;
    ds = ax;
    si = 0x0000;
    di = 0x000c;
    sub_206f();
    ds = memoryAGet16(cs, 0x01ff);
    memoryASet(cs, 0x01b1, 0x72);
    memoryASet(cs, 0x01a0, 0x00);
    push(memoryAGet16(ds, 0x0071));
    push(memoryAGet16(ds, 0x006f));
    push(memoryAGet16(ds, 0x006d));
    push(memoryAGet16(ds, 0x006b));
    push(memoryAGet16(ds, 0x0069));
    sub_20d3();
    push(ax);
    sub_b78a();
    ax = 0x1227;
    ds = ax;
    si = 0x000c;
    di = 0x000c;
    sub_206f();
    ds = memoryAGet16(cs, 0x01ff);
    callIndirect(cs*16+memoryAGet16(ds, 0x6984));
    callIndirect(cs*16+memoryAGet16(ds, 0x6986));
    callIndirect(cs*16+memoryAGet16(ds, 0x6988));
    ds = memoryAGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002d;
    goto loc_20c0;
    //   gap of 187 bytes
loc_20ba: // 01ed:01ea
    cx = 0x001e;
    dx = 0x003b;
loc_20c0: // 01ed:01f0
    ds = memoryAGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    ax += memoryAGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df: // 01ed:020f
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x6be4, dx);
    memoryASet16(ds, 0x6be6, ax);
    sub_2152();
    sub_9a77();
    sub_28d7();
    sub_2128();
    sub_2439();
    sub_9947();
    sub_9c89();
    ax = 0x0003;
    push(ax);
    sub_8ff0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b78a();
    sp++;
    sp++;
loc_2126: // 01ed:0256
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1fc6() // 01ed:00f6
{
    CStackGuard sg(0, true);
    push(0x7777);
    ax = 0x1227;
    ds = ax;
    si = 0x000c;
    di = 0x000c;
    sub_206f();
    ds = memoryAGet16(cs, 0x01ff);
    callIndirect(cs*16+memoryAGet16(ds, 0x6984));
    callIndirect(cs*16+memoryAGet16(ds, 0x6986));
    callIndirect(cs*16+memoryAGet16(ds, 0x6988));
    ds = memoryAGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002d;
    goto loc_20c0;
    //   gap of 193 bytes
loc_20c0: // 01ed:01f0
    ds = memoryAGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    ax += memoryAGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df: // 01ed:020f
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x6be4, dx);
    memoryASet16(ds, 0x6be6, ax);
    sub_2152();
    sub_9a77();
    sub_28d7();
    sub_2128();
    sub_2439();
    sub_9947();
    sub_9c89();
    ax = 0x0003;
    push(ax);
    sub_8ff0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b78a();
    sp++;
    sp++;
loc_2126: // 01ed:0256
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1fe5() // 01ed:0115
{
    CStackGuard sg(0, true);
    push(0x7777);
    ds = memoryAGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002d;
    goto loc_20c0;
    //   gap of 193 bytes
loc_20c0: // 01ed:01f0
    ds = memoryAGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    ax += memoryAGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df: // 01ed:020f
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x6be4, dx);
    memoryASet16(ds, 0x6be6, ax);
    sub_2152();
    sub_9a77();
    sub_28d7();
    sub_2128();
    sub_2439();
    sub_9947();
    sub_9c89();
    ax = 0x0003;
    push(ax);
    sub_8ff0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b78a();
    sp++;
    sp++;
loc_2126: // 01ed:0256
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1fff() // 01ed:012f
{
    CStackGuard sg(0, false);
    push(ds);
    ax = 0x3500;
    interrupt(0x21);
    memoryASet16(ds, 0x0059, bx);
    memoryASet16(ds, 0x005b, es);
    ax = 0x3504;
    interrupt(0x21);
    memoryASet16(ds, 0x005d, bx);
    memoryASet16(ds, 0x005f, es);
    ax = 0x3505;
    interrupt(0x21);
    memoryASet16(ds, 0x0061, bx);
    memoryASet16(ds, 0x0063, es);
    ax = 0x3506;
    interrupt(0x21);
    memoryASet16(ds, 0x0065, bx);
    memoryASet16(ds, 0x0067, es);
    ax = 0x2500;
    dx = cs;
    ds = dx;
    dx = 0x0126;
    interrupt(0x21);
    ds = pop();
}
void sub_2042() // 01ed:0172
{
    CStackGuard sg(0, false);
    push(ds);
    ax = 0x2500;
    dx = memoryAGet16(ds, 0x0059);
    ds = memoryAGet16(ds, 0x0059 + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2504;
    dx = memoryAGet16(ds, 0x005d);
    ds = memoryAGet16(ds, 0x005d + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2505;
    dx = memoryAGet16(ds, 0x0061);
    ds = memoryAGet16(ds, 0x0061 + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2506;
    dx = memoryAGet16(ds, 0x0065);
    ds = memoryAGet16(ds, 0x0065 + 2);
    interrupt(0x21);
    ds = pop();
}
void sub_206f() // 01ed:019f
{
//    CStackGuard sg(0, false);
    push(0x7777);
loc_206f: // 01ed:019f
    ah = 0xff;
    dx = di;
    bx = si;
loc_2075: // 01ed:01a5
    if (bx == di)
        goto loc_208d;
    if (memoryAGet(ds, bx) == 0xff)
        goto loc_2088;
    if (memoryAGet(ds, bx + 1) > ah)
        goto loc_2088;
    ah = memoryAGet(ds, bx + 1);
    dx = bx;
loc_2088: // 01ed:01b8
    bx += 0x0006;
    goto loc_2075;
loc_208d: // 01ed:01bd
    if (dx == di)
    {
        assert(pop() == 0x7777);
        return;
    }
    bx = dx;
    push(ds);
    es = pop();
    push(es);
    tl = memoryAGet(ds, bx);
    memoryASet(ds, bx, 0xff);
    ds = memoryAGet16(cs, 0x01ff);
    if (tl == 0)
        goto loc_20aa;
    push(cs);
    cs = memoryAGet16(es, bx + 2 + 2);
    callIndirect(memoryAGet16(es, bx + 2 + 2)*16 + memoryAGet16(es, bx + 2));
    assert(cs == 0x01ed);
    ds = pop();
    goto loc_206f;
loc_20aa: // 01ed:01da
    callIndirect(cs*16+memoryAGet16(es, bx + 2));
    ds = pop();
    goto loc_206f;
}
void sub_20b2() // 01ed:01e2
{
    CStackGuard sg(0, false);
    ah = 0x40;
    bx = 0x0002;
    interrupt(0x21);
}
void sub_20d3() // 01ed:0203
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df: // 01ed:020f
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x6be4, dx);
    memoryASet16(ds, 0x6be6, ax);
    sub_2152();
    sub_9a77();
    sub_28d7();
    sub_2128();
    sub_2439();
    sub_9947();
    sub_9c89();
    ax = 0x0003;
    push(ax);
    sub_8ff0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b78a();
    sp++;
    sp++;
loc_2126: // 01ed:0256
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2128() // 01ed:0258
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2134;
    sub_ca53();
loc_2134: // 01ed:0264
    memoryASet(ds, 0x79b2, 0x01);
    sub_722e();
    sub_8cb3();
loc_213f: // 01ed:026f
    sub_2ae8();
    if (memoryAGet(ds, 0x9d30) != 0x00)
        goto loc_213f;
    if (memoryAGet(ds, 0x856d) != 0x00)
        goto loc_213f;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2152() // 01ed:0282
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_215e;
    sub_ca53();
loc_215e: // 01ed:028e
    ax = 0x06a9;
    push(ax);
    ax = 0x0698;
    push(ax);
    sub_91bf();
    sp += 0x0004;
    push(ds);
    ax = 0x6fac;
    push(ax);
    sub_9a7d();
    sp += 0x0004;
    sub_9bae();
    sub_985a();
    sub_9402();
    sub_b14c();
    push(ds);
    ax = 0x4cd0;
    push(ax);
    al = 0x00;
    push(ax);
    sub_9433();
    sp += 0x0006;
    sub_9aa7();
    sub_b674();
    al = 0x02;
    push(ax);
    sub_9a8d();
    sp++;
    sp++;
    sub_b6c1();
    ax = 0x00c7;
    push(ax);
    ax = 0x013f;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    sub_b6f1();
    sp += 0x0008;
    ax = 0x0001;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    ax = 0x000e;
    push(ax);
    sub_b695();
    sp += 0x0004;
    push(ds);
    ax = 0x0090;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    al = 0x00;
    memoryASet(ds, 0x6bec, al);
    ah = 0x00;
    memoryASet16(ds, 0x7310, ax);
    memoryASet(ds, 0x7312, al);
    memoryASet(ds, 0x6bc9, al);
    memoryASet(ds, 0x7314, al);
    al = 0x00;
    memoryASet(ds, 0x731b, al);
    memoryASet(ds, 0x6bba, al);
    memoryASet(ds, 0x75ed, al);
    memoryASet(ds, 0x75ec, al);
    memoryASet(ds, 0x75eb, al);
    memoryASet(ds, 0x75ce, al);
    al = 0x00;
    memoryASet(ds, 0x6c34, al);
    memoryASet(ds, 0x6bc8, al);
    ah = 0x00;
    memoryASet16(ds, 0x6bc2, ax);
    memoryASet16(ds, 0x6bc0, ax);
    memoryASet16(ds, 0x6c40, ax);
    memoryASet16(ds, 0x6c3e, ax);
    memoryASet16(ds, 0x75c8, ax);
    memoryASet(ds, 0x6bc5, 0x01);
    memoryASet(ds, 0x6bc4, 0x14);
    al = 0x00;
    memoryASet(ds, 0x6faa, al);
    memoryASet(ds, 0x75e2, al);
    al = 0x00;
    memoryASet(ds, 0x75cf, al);
    memoryASet(ds, 0x75c6, al);
    memoryASet(ds, 0x6bdf, al);
    memoryASet(ds, 0x6bc6, al);
    ax = 0;
    memoryASet16(ds, 0x6bf8, ax);
    memoryASet16(ds, 0x6bbe, ax);
    memoryASet16(ds, 0x6bbc, ax);
    ax = 0;
    memoryASet16(ds, 0x6bd6, ax);
    memoryASet16(ds, 0x6bce, ax);
    ax = 0;
    memoryASet16(ds, 0x6bdc, ax);
    memoryASet16(ds, 0x6bd0, ax);
    ax = 0;
    memoryASet16(ds, 0x6bda, ax);
    memoryASet16(ds, 0x6bd8, ax);
    al = 0x01;
    memoryASet(ds, 0x6bf6, al);
    memoryASet(ds, 0x6c26, al);
    ax = 0;
    memoryASet16(ds, 0x6be2, ax);
    memoryASet16(ds, 0x6be0, ax);
    memoryASet16(ds, 0x7316, 0x006c);
    al = 0x00;
    memoryASet(ds, 0x6bbb, al);
    memoryASet(ds, 0x6bde, al);
    memoryASet(ds, 0x6bc7, 0x09);
    memoryASet(ds, 0x75ea, 0x00);
    ax = memoryAGet16(ds, 0x7310);
    dx = 0x032c;
    imul(dx);
    dx = memoryAGet16(ds, 0x6bd4);
    bx = memoryAGet16(ds, 0x6bd2);
    bx += ax;
    memoryASet16(ds, 0x6bca, bx);
    memoryASet16(ds, 0x6bcc, dx);
    ax = memoryAGet16(ds, 0x7310);
    dx = 0x00c2;
    imul(dx);
    dx = memoryAGet16(ds, 0x6bf4);
    bx = memoryAGet16(ds, 0x6bf2);
    bx += ax;
    memoryASet16(ds, 0x75d0, bx);
    memoryASet16(ds, 0x75d2, dx);
    sub_22ba();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_22ba() // 01ed:03ea
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_22c6;
    sub_ca53();
loc_22c6: // 01ed:03f6
    sub_b2f4();
    ax = 0x00c7;
    push(ax);
    ax = 0x013f;
    push(ax);
    ax = 0;
    push(ax);
    push(ax);
    sub_b2d6();
    sp += 0x0008;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_22e6() // 01ed:0416
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_22f4;
    sub_ca53();
loc_22f4: // 01ed:0424
    memoryASet(ss, bp - 1, 0x00);
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x07c3;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x75da, ax);
    memoryASet16(ds, 0x75dc, dx);
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x0898;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x6c2c, ax);
    memoryASet16(ds, 0x6c2e, dx);
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x7806;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x6fa6, ax);
    memoryASet16(ds, 0x6fa8, dx);
    ax |= dx;
    if (ax)
        goto loc_2345;
    memoryASet(ss, bp - 1, 0xff);
loc_2345: // 01ed:0475
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_236e;
    al = 0x01;
    push(ax);
    ax = 0x0001;
    dx = 0x5c70;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0xa0c6, ax);
    memoryASet16(ds, 0xa0c8, dx);
    ax |= dx;
    if (ax)
        goto loc_236e;
    memoryASet(ss, bp - 1, 0xff);
loc_236e: // 01ed:049e
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_23a8;
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x2f96;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x6be8, ax);
    memoryASet16(ds, 0x6bea, dx);
    ax |= dx;
    if (ax)
        goto loc_2398;
    memoryASet(ss, bp - 1, 0xff);
    goto loc_23a8;
loc_2398: // 01ed:04c8
    ax = memoryAGet16(ds, 0x6bea);
    dx = memoryAGet16(ds, 0x6be8);
    dx++;
    dx++;
    memoryASet16(ds, 0x6bd2, dx);
    memoryASet16(ds, 0x6bd4, ax);
loc_23a8: // 01ed:04d8
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_23d0;
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x0500;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x6c30, ax);
    memoryASet16(ds, 0x6c32, dx);
    ax |= dx;
    if (ax)
        goto loc_23d0;
    memoryASet(ss, bp - 1, 0xff);
loc_23d0: // 01ed:0500
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_23f8;
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x7926, ax);
    memoryASet16(ds, 0x7928, dx);
    ax |= dx;
    if (ax)
        goto loc_23f8;
    memoryASet(ss, bp - 1, 0xff);
loc_23f8: // 01ed:0528
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_2432;
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x0b60;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memoryASet16(ds, 0x75de, ax);
    memoryASet16(ds, 0x75e0, dx);
    ax |= dx;
    if (ax)
        goto loc_2422;
    memoryASet(ss, bp - 1, 0xff);
    goto loc_2432;
loc_2422: // 01ed:0552
    ax = memoryAGet16(ds, 0x75e0);
    dx = memoryAGet16(ds, 0x75de);
    dx++;
    dx++;
    memoryASet16(ds, 0x6bf2, dx);
    memoryASet16(ds, 0x6bf4, ax);
loc_2432: // 01ed:0562
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2439() // 01ed:0569
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2445;
    sub_ca53();
loc_2445: // 01ed:0575
    push(memoryAGet16(ds, 0x75e0));
    push(memoryAGet16(ds, 0x75de));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x6c32));
    push(memoryAGet16(ds, 0x6c30));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x6bea));
    push(memoryAGet16(ds, 0x6be8));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x6fa8));
    push(memoryAGet16(ds, 0x6fa6));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x6c2e));
    push(memoryAGet16(ds, 0x6c2c));
    sub_9f6e();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x75dc));
    push(memoryAGet16(ds, 0x75da));
    sub_9f6e();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_24b7() // 01ed:05e7
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_24c8;
    sub_ca53();
    goto loc_24c8;
loc_24c5: // 01ed:05f5
    sub_b734();
loc_24c8: // 01ed:05f8
    al = memoryAGet(ss, bp + 4);
    memoryASet(ss, bp + 4, memoryAGet(ss, bp + 4) - 1);
    if (al)
        goto loc_24c5;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_24d4() // 01ed:0604
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_24e0;
    sub_ca53();
loc_24e0: // 01ed:0610
    al = memoryAGet(ds, 0x75cf);
    ah = 0x00;
    if (ax)
        goto loc_24f9;
    bx = memoryAGet16(ds, 0x6bca);
    es = memoryAGet16(ds, 0x6bca + 2);
    if (memoryAGet16(es, bx + 28) == 0x0000)
        goto loc_24f9;
    sub_250b();
    goto loc_24fe;
loc_24f9: // 01ed:0629
    memoryASet(ds, 0x75cf, 0x01);
loc_24fe: // 01ed:062e
    push(ds);
    ax = 0x0578;
    push(ax);
    sub_27a1();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_250b() // 01ed:063b
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_251c;
    sub_ca53();
loc_251c: // 01ed:064c
    memoryASet(ss, bp - 1, 0x00);
    goto loc_255c;
loc_2522: // 01ed:0652
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x6bca);
    es = memoryAGet16(ds, 0x6bca + 2);
    bx += ax;
    si = memoryAGet16(es, bx);
    ax = si;
    ax &= 0x00ff;
    cl = 0x08;
    ax <<= cl;
    memoryASet16(ss, bp - 4, ax);
    ax = si;
    ax &= 0xff00;
    ax >>= cl;
    di = ax;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    dx = memoryAGet16(ss, bp - 4);
    dx |= di;
    bx = ax;
    memoryASet16(ds, bx + 1400, dx);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_255c: // 01ed:068c
    if (memoryAGet(ss, bp - 1) < 0x10)
        goto loc_2522;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_26c0() // 01ed:07f0
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_26cc;
    sub_ca53();
loc_26cc: // 01ed:07fc
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    sub_b707();
    sp += 0x0004;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_b6d4();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_26e6() // 01ed:0816
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_26f5;
    sub_ca53();
loc_26f5: // 01ed:0825
    if (memoryAGet(ss, bp + 8) <= 0x07)
        goto loc_26fe;
    goto loc_278c;
loc_26fe: // 01ed:082e
    memoryASet(ss, bp - 11, 0x00);
    goto loc_2717;
loc_2704: // 01ed:0834
    al = memoryAGet(ss, bp - 11);
    memoryASet(ss, bp - 11, memoryAGet(ss, bp - 11) + 1);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    memoryASet(ss, bx, 0x20);
loc_2717: // 01ed:0847
    al = memoryAGet(ss, bp - 11);
    if (al <= memoryAGet(ss, bp + 8))
        goto loc_2704;
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    memoryASet(ss, bx, 0x00);
    goto loc_2776;
loc_2731: // 01ed:0861
    al = memoryAGet(ss, bp + 4);
    memoryASet(ss, bp - 1, al);
    ax = 0;
    dx = 0x000a;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c7be();
    memoryASet16(ss, bp + 4, ax);
    bx = ax;
    memoryASet16(ss, bp + 6, dx);
    cx = dx;
    dx = 0;
    ax = 0x000a;
    sub_c8e4();
    dl = memoryAGet(ss, bp - 1);
    dl -= al;
    memoryASet(ss, bp - 1, dl);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    dl = memoryAGet(ss, bp - 1);
    dl += 0x30;
    bx = ax;
    memoryASet(ss, bx, dl);
loc_2776: // 01ed:08a6
    al = memoryAGet(ss, bp + 8);
    memoryASet(ss, bp + 8, memoryAGet(ss, bp + 8) - 1);
    if (al) // dec, or, ja
        goto loc_2731;
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(ss);
    ax = bp - 0xa;
    goto loc_2796;
loc_278c: // 01ed:08bc
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(ds);
    ax = 0x062e;
loc_2796: // 01ed:08c6
    push(ax);
    sub_26c0();
    sp += 0x0008;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_27a1() // 01ed:08d1
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_27b1;
    sub_ca53();
loc_27b1: // 01ed:08e1
    memoryASet16(ss, bp - 4, 0x6c42);
    memoryASet16(ss, bp - 2, ds);
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_27f6;
    memoryASet16(ds, 0x9b96, 0x6c42);
    memoryASet16(ds, 0x9b98, ds);
    memoryASet(ss, bp - 6, 0x00);
    goto loc_27ed;
loc_27d0: // 01ed:0900
    al = memoryAGet(ss, bp - 6);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    ah = 0x00;
    si = ax;
    al = memoryAGet(ds, si + 1806);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 6, memoryAGet(ss, bp - 6) + 1);
loc_27ed: // 01ed:091d
    if (memoryAGet(ss, bp - 6) < 0x10)
        goto loc_27d0;
    goto loc_28b9;
loc_27f6: // 01ed:0926
    memoryASet(ss, bp - 5, 0x00);
    goto loc_28b0;
loc_27fd: // 01ed:092d
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    cl = 0x08;
    ax >>= cl;
    memoryASet(ss, bp - 7, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 4);
    bx += ax;
    ax = memoryAGet16(es, bx);
    dl = memoryAGet(ds, 0x75eb);
    dh = 0x00;
    dx <<= cl;
    ax -= dx;
    cl = 0x04;
    ax >>= cl;
    memoryASet(ss, bp - 8, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 4);
    bx += ax;
    al = memoryAGet(es, bx);
    dl = memoryAGet(ds, 0x75eb);
    cl = 0x08;
    dl <<= cl;
    bl = memoryAGet(ds, 0x75ec);
    cl = 0x04;
    bl <<= cl;
    dl += bl;
    al -= dl;
    memoryASet(ss, bp - 9, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0003;
    imul(dx);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 7);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memoryASet(es, bx + 51, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0003;
    imul(dx);
    bx = memoryAGet16(ss, bp - 4);
    bx += ax;
    al = memoryAGet(ss, bp - 8);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memoryASet(es, bx + 52, al);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0003;
    imul(dx);
    bx = memoryAGet16(ss, bp - 4);
    bx += ax;
    al = memoryAGet(ss, bp - 9);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memoryASet(es, bx + 53, al);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_28b0: // 01ed:09e0
    if (memoryAGet(ss, bp - 5) >= 0x10)
        goto loc_28b9;
    goto loc_27fd;
loc_28b9: // 01ed:09e9
    ax = 0;
    push(ax);
    push(ds);
    ax = 0x6c42;
    push(ax);
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_28d7() // 01ed:0a07
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_28e4;
    sub_ca53();
loc_28e4: // 01ed:0a14
    ax = 0x0004;
    push(ax);
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x00c0));
    push(memoryAGet16(ds, 0x00be));
    push(memoryAGet16(ds, 0x75dc));
    push(memoryAGet16(ds, 0x75da));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x75dc));
    push(memoryAGet16(ds, 0x75da));
    sub_b6a5();
    sp += 0x0004;
    ax = 0x0004;
    push(ax);
    ax = 0x0009;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x00f2));
    push(memoryAGet16(ds, 0x00f0));
    push(memoryAGet16(ds, 0x6c2e));
    push(memoryAGet16(ds, 0x6c2c));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x6c2e));
    push(memoryAGet16(ds, 0x6c2c));
    sub_b2a8();
    sp += 0x0004;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2960() // 01ed:0a90
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2970;
    sub_ca53();
loc_2970: // 01ed:0aa0
    ax = memoryAGet16(ds, 0x6fa8);
    dx = memoryAGet16(ds, 0x6fa6);
    dx += 0x0006;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0018);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(es, bx + 14, ax);
    memoryASet16(es, bx + 28, 0x0006);
    memoryASet16(es, bx + 30, 0x0001);
    if (memoryAGet16(ss, bp + 8) != 0x0018)
        goto loc_29b3;
    memoryASet16(es, bx + 32, 0x0001);
    goto loc_29bd;
loc_29b3: // 01ed:0ae3
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 32, 0x0002);
loc_29bd: // 01ed:0aed
    if (memoryAGet(ss, bp + 4) <= 0xf0)
        goto loc_29d1;
    memoryASet(ss, bp - 2, 0x01);
    al = 0xfb;
    al -= memoryAGet(ss, bp + 4);
    memoryASet(ss, bp - 1, al);
    goto loc_2a4a;
loc_29d1: // 01ed:0b01
    memoryASet(ss, bp - 2, 0x00);
    memoryASet(ss, bp - 1, 0x01);
    goto loc_2a4a;
loc_29db: // 01ed:0b0b
    ax = memoryAGet16(ss, bp + 6);
    dx = 0x0027;
    imul(dx);
    bx = memoryAGet16(ds, 0x6bca);
    es = memoryAGet16(ds, 0x6bca + 2);
    bx += ax;
    ax = memoryAGet16(ss, bp + 8);
    ax = sar(ax, 1);
    dx = 0x0003;
    imul(dx);
    bx += ax;
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx + 32);
    al += 0xff;
    memoryASet(ss, bp + 4, al);
    ah = 0x00;
    bx = 0x0014;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    ax <<= 1;
    si = ax;
    dx = 0x000a;
    imul(dx);
    dl = memoryAGet(ss, bp + 4);
    dh = 0x00;
    dx -= ax;
    di = dx;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 6, di);
    memoryASet16(es, bx + 8, si);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(es, bx + 22, ax);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_2a4a: // 01ed:0b7a
    al = memoryAGet(ss, bp - 2);
    if (al < memoryAGet(ss, bp - 1))
        goto loc_29db;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2a58() // 01ed:0b88
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2a64;
    sub_ca53();
loc_2a64: // 01ed:0b94
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(es, bx + 14, ax);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    if (memoryAGet16(ss, bp + 6) != 0x0018)
        goto loc_2a97;
    memoryASet16(es, bx + 32, 0x0001);
    goto loc_2aa1;
loc_2a97: // 01ed:0bc7
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 32, 0x0002);
loc_2aa1: // 01ed:0bd1
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet(es, bx + 34, 0x00);
    memoryASet(es, bx + 35, 0x00);
    memoryASet(es, bx + 36, 0x00);
    memoryASet(es, bx + 37, 0x00);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2ac9() // 01ed:0bf9
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2ad5;
    sub_ca53();
loc_2ad5: // 01ed:0c05
    sub_5180();
    sub_4948();
    sub_50ae();
    al = 0x00;
    memoryASet(ds, 0x9d30, al);
    memoryASet(ds, 0x856d, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2ae8() // 01ed:0c18
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2af6;
    sub_ca53();
loc_2af6: // 01ed:0c26
    sub_5295();
    sub_4dc8();
loc_2afc: // 01ed:0c2c
    memoryASet(ds, 0x928d, 0x00);
    memoryASet(ds, 0x791a, 0x05);
    al = 0x00;
    memoryASet(ds, 0x79b5, al);
    ah = 0x00;
    memoryASet16(ds, 0xa0d4, ax);
    memoryASet16(ds, 0xa0d6, 0x0000);
    goto loc_2b26;
loc_2b18: // 01ed:0c48
    if (memoryAGet(ss, bp - 1) != 0x01)
        goto loc_2b23;
    sub_7551();
    goto loc_2b26;
loc_2b23: // 01ed:0c53
    sub_2e4a();
loc_2b26: // 01ed:0c56
    sub_5475();
    memoryASet(ss, bp - 1, al);
    if (al)
        goto loc_2b18;
    goto loc_2c5a;
loc_2b33: // 01ed:0c63
    sub_5722();
    if (memoryAGet(ds, 0x928d) != 0xff)
        goto loc_2b42;
    sub_30bb();
    goto loc_2afc;
loc_2b42: // 01ed:0c72
    al = memoryAGet(ds, 0x854e);
    ah = 0x00;
    ax--;
    memoryASet16(ds, 0x7310, ax);
    sub_5337();
    sub_2ac9();
    al = memoryAGet(ds, 0x8562);
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_7051();
    sp += 0x0004;
    sub_3b82();
    sub_3bba();
    sub_24d4();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    al = 0x01;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    sub_515f();
    sub_3343();
    sub_6a1e();
    sub_325c();
    sub_3282();
    sub_3aa7();
    sub_3b11();
    sub_325c();
    sub_3282();
    sub_3871();
    sub_38b4();
    sub_3343();
    sub_6a1e();
    goto loc_2c19;
loc_2baa: // 01ed:0cda
    sub_b281();
    memoryASet(ds, 0x79b3, al);
    sub_325c();
    sub_3282();
    sub_32af();
    sub_6ae4();
    sub_3343();
    sub_6a1e();
    sub_33b4();
    sub_3471();
    sub_3871();
    sub_38b4();
    sub_38f0();
    sub_352e();
    sub_3697();
    sub_6f55();
    sub_6f90();
    sub_3937();
    sub_39fb();
    sub_3aa7();
    sub_3b11();
    sub_3b82();
    sub_3bba();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
    sub_816c();
    sub_3bf6();
    sub_6b69();
    sub_6fcb();
    sub_420a();
    al = 0x19;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_2c19;
    sub_68a7();
loc_2c19: // 01ed:0d49
    if (memoryAGet(ds, 0x928d) != 0x00)
        goto loc_2c31;
    if (memoryAGet(ds, 0x856d) != 0x00)
        goto loc_2c31;
    if (memoryAGet(ds, 0x9d30) != 0x00)
        goto loc_2c31;
    goto loc_2baa;
loc_2c31: // 01ed:0d61
    if (memoryAGet(ds, 0x928d) != 0xff)
        goto loc_2c40;
    sub_30bb();
    sub_7551();
    goto loc_2c5d;
loc_2c40: // 01ed:0d70
    sub_5d5a();
    if (!al)
        goto loc_2c5d;
    memoryASet(ds, 0x79b2, memoryAGet(ds, 0x79b2) + 1);
    if (memoryAGet(ds, 0x79b2) != 0x0a)
        goto loc_2c57;
    sub_5da4();
    goto loc_2c5d;
loc_2c57: // 01ed:0d87
    sub_2c6d();
loc_2c5a: // 01ed:0d8a
    sub_4be4();
loc_2c5d: // 01ed:0d8d
    al = memoryAGet(ds, 0x928d);
    ah = 0x00;
    if (ax)
        goto loc_2c69;
    goto loc_2b33;
loc_2c69: // 01ed:0d99
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2c6d() // 01ed:0d9d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2c7e;
    sub_ca53();
loc_2c7e: // 01ed:0dae
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(ds);
    ax = 0x119e;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x857e, dx);
    memoryASet16(ds, 0x8580, ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0003;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    dx = 0x0063;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_2d1a;
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 13, 0x00);
    goto loc_2d14;
loc_2cf7: // 01ed:0e27
    al = memoryAGet(ss, bp - 13);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 13);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1822);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 13, memoryAGet(ss, bp - 13) + 1);
loc_2d14: // 01ed:0e44
    if (memoryAGet(ss, bp - 13) < 0x10)
        goto loc_2cf7;
loc_2d1a: // 01ed:0e4a
    sub_5337();
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    memoryASet(ss, bp - 9, 0x04);
    memoryASet(ss, bp - 10, 0x05);
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 12, 0x00);
    goto loc_2da4;
loc_2d64: // 01ed:0e94
    al = memoryAGet(ss, bp - 12);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 11, al);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 11) == 0x20)
        goto loc_2d9e;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_2d9e: // 01ed:0ece
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    memoryASet(ss, bp - 12, memoryAGet(ss, bp - 12) + 1);
loc_2da4: // 01ed:0ed4
    if (memoryAGet(ss, bp - 12) < 0x0d)
        goto loc_2d64;
    memoryASet(ss, bp - 9, 0x07);
    memoryASet(ss, bp - 10, 0x07);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 4950);
    dx = memoryAGet16(ds, bx + 4948);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 12, 0x00);
    goto loc_2e1c;
loc_2de2: // 01ed:0f12
    al = memoryAGet(ss, bp - 12);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 11, al);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    memoryASet(ss, bp - 12, memoryAGet(ss, bp - 12) + 1);
loc_2e1c: // 01ed:0f4c
    if (memoryAGet(ss, bp - 12) < 0x06)
        goto loc_2de2;
loc_2e22: // 01ed:0f52
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    cbw();
    if (!(ax & 0x0010))
        goto loc_2e22;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    push(ds);
    ax = 0x0090;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2e4a() // 01ed:0f7a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0016;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_2e5b;
    sub_ca53();
loc_2e5b: // 01ed:0f8b
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(ds);
    ax = 0x11a2;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ss);
    ax = bp - 0x8;
    push(ax);
    push(ds);
    ax = 0x11a6;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ss);
    ax = bp - 0xc;
    push(ax);
    push(ds);
    ax = 0x11aa;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x857e, dx);
    memoryASet16(ds, 0x8580, ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0003;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    dx = 0x0063;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_2f17;
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 22, 0x00);
    goto loc_2f11;
loc_2ef4: // 01ed:1024
    al = memoryAGet(ss, bp - 22);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 22);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1822);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 22, memoryAGet(ss, bp - 22) + 1);
loc_2f11: // 01ed:1041
    if (memoryAGet(ss, bp - 22) < 0x10)
        goto loc_2ef4;
loc_2f17: // 01ed:1047
    sub_5337();
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    memoryASet(ss, bp - 17, 0x00);
    memoryASet(ss, bp - 18, 0x01);
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 16, dx);
    memoryASet16(ss, bp - 14, ax);
    al = memoryAGet(ss, bp - 18);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 20, 0x00);
    goto loc_2fa1;
loc_2f61: // 01ed:1091
    al = memoryAGet(ss, bp - 20);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 19, al);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 17);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 19) == 0x20)
        goto loc_2f9b;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_2f9b: // 01ed:10cb
    memoryASet(ss, bp - 17, memoryAGet(ss, bp - 17) + 1);
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) + 1);
loc_2fa1: // 01ed:10d1
    if (memoryAGet(ss, bp - 20) < 0x13)
        goto loc_2f61;
    memoryASet(ss, bp - 17, 0x07);
    memoryASet(ss, bp - 18, 0x0a);
    al = memoryAGet(ss, bp - 18);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 20, 0x00);
    goto loc_2ff7;
loc_2fc6: // 01ed:10f6
    memoryASet(ss, bp - 19, 0x41);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    al = memoryAGet(ss, bp - 19);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 17);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memoryASet(ss, bp - 17, memoryAGet(ss, bp - 17) + 1);
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) + 1);
loc_2ff7: // 01ed:1127
    if (memoryAGet(ss, bp - 20) < 0x06)
        goto loc_2fc6;
    al = 0x07;
    push(ax);
    al = 0x0a;
    push(ax);
    sub_7b57();
    sp += 0x0004;
    memoryASet(ss, bp - 21, al);
    if (!al)
        goto loc_3024;
    ax = memoryAGet16(ss, bp - 6);
    dx = memoryAGet16(ss, bp - 8);
    memoryASet16(ss, bp - 16, dx);
    memoryASet16(ss, bp - 14, ax);
    al = memoryAGet(ss, bp - 21);
    memoryASet(ds, 0x79b2, al);
    goto loc_3035;
loc_3024: // 01ed:1154
    ax = memoryAGet16(ss, bp - 10);
    dx = memoryAGet16(ss, bp - 12);
    memoryASet16(ss, bp - 16, dx);
    memoryASet16(ss, bp - 14, ax);
    memoryASet(ds, 0x79b2, 0x01);
loc_3035: // 01ed:1165
    memoryASet(ss, bp - 17, 0x03);
    memoryASet(ss, bp - 18, 0x06);
    al = memoryAGet(ss, bp - 18);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 20, 0x00);
    goto loc_3094;
loc_3054: // 01ed:1184
    al = memoryAGet(ss, bp - 20);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 19, al);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 17);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 19) == 0x20)
        goto loc_308e;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_308e: // 01ed:11be
    memoryASet(ss, bp - 17, memoryAGet(ss, bp - 17) + 1);
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) + 1);
loc_3094: // 01ed:11c4
    if (memoryAGet(ss, bp - 20) < 0x0e)
        goto loc_3054;
    memoryASet(ss, bp - 20, 0x00);
    goto loc_30a6;
loc_30a0: // 01ed:11d0
    sub_5d44();
    memoryASet(ss, bp - 20, memoryAGet(ss, bp - 20) + 1);
loc_30a6: // 01ed:11d6
    if (memoryAGet(ss, bp - 20) < 0x03)
        goto loc_30a0;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_30bb() // 01ed:11eb
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_30cc;
    sub_ca53();
loc_30cc: // 01ed:11fc
    push(ss);
    ax = bp - 0x4;
    push(ax);
    push(ds);
    ax = 0x11ae;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x857e, dx);
    memoryASet16(ds, 0x8580, ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0003;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    dx = 0x0063;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_3168;
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 13, 0x00);
    goto loc_3162;
loc_3145: // 01ed:1275
    al = memoryAGet(ss, bp - 13);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 13);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1822);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 13, memoryAGet(ss, bp - 13) + 1);
loc_3162: // 01ed:1292
    if (memoryAGet(ss, bp - 13) < 0x10)
        goto loc_3145;
loc_3168: // 01ed:1298
    sub_5337();
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    al = 0x06;
    memoryASet(ss, bp - 10, al);
    memoryASet(ss, bp - 9, al);
    ax = memoryAGet16(ss, bp - 2);
    dx = memoryAGet16(ss, bp - 4);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 12, 0x00);
    goto loc_31f2;
loc_31b2: // 01ed:12e2
    al = memoryAGet(ss, bp - 12);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 11, al);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 11) == 0x20)
        goto loc_31ec;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_31ec: // 01ed:131c
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    memoryASet(ss, bp - 12, memoryAGet(ss, bp - 12) + 1);
loc_31f2: // 01ed:1322
    if (memoryAGet(ss, bp - 12) < 0x09)
        goto loc_31b2;
    memoryASet(ss, bp - 12, 0x00);
    goto loc_3204;
loc_31fe: // 01ed:132e
    sub_5d44();
    memoryASet(ss, bp - 12, memoryAGet(ss, bp - 12) + 1);
loc_3204: // 01ed:1334
    if (memoryAGet(ss, bp - 12) < 0x02)
        goto loc_31fe;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3219() // 01ed:1349
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3227;
    sub_ca53();
loc_3227: // 01ed:1357
    memoryASet(ss, bp - 2, 0x01);
    if (!(memoryAGet(ds, 0x854f) & 0x01))
        goto loc_3236;
    al = 0x80;
    goto loc_3238;
loc_3236: // 01ed:1366
    al = 0x00;
loc_3238: // 01ed:1368
    memoryASet(ss, bp - 1, al);
    if (!al)
        goto loc_3242;
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_3242: // 01ed:1372
    al = memoryAGet(ds, 0x854f);
    ah = 0x00;
    ax = sar(ax, 1);
    al |= memoryAGet(ss, bp - 1);
    memoryASet(ds, 0x854f, al);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_325c() // 01ed:138c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3268;
    sub_ca53();
loc_3268: // 01ed:1398
    ax = memoryAGet16(ds, 0x857a);
    memoryASet16(ds, 0x8882, ax);
    ax = memoryAGet16(ds, 0x857c);
    memoryASet16(ds, 0x8e88, ax);
    ax = memoryAGet16(ds, 0x9d36);
    memoryASet16(ds, 0x857a, ax);
    ax = memoryAGet16(ds, 0x9d38);
    memoryASet16(ds, 0x857c, ax);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3282() // 01ed:13b2
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_328e;
    sub_ca53();
loc_328e: // 01ed:13be
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_32ad;
    ax = memoryAGet16(ds, 0x8558);
    memoryASet16(ds, 0x928e, ax);
    ax = memoryAGet16(ds, 0x855a);
    memoryASet16(ds, 0x9b94, ax);
    ax = memoryAGet16(ds, 0xa0ca);
    memoryASet16(ds, 0x8558, ax);
    ax = memoryAGet16(ds, 0xa0cc);
    memoryASet16(ds, 0x855a, ax);
loc_32ad: // 01ed:13dd
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_32af() // 01ed:13df
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_32bb;
    sub_ca53();
loc_32bb: // 01ed:13eb
    al = memoryAGet(ds, 0x8242);
    ah = 0x00;
    if (ax)
        goto loc_3341;
    if (memoryAGet(ds, 0x824d) == 0x00)
        goto loc_3341;
    if (memoryAGet(ds, 0x792c) == 0x05)
        goto loc_3341;
    if (memoryAGet(ds, 0x792c) == 0x0b)
        goto loc_3341;
    if (memoryAGet(ds, 0x792c) == 0x1c)
        goto loc_3341;
    bx = memoryAGet16(ds, 0xa1ac);
    es = memoryAGet16(ds, 0xa1ac + 2);
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x824a, ax);
    if (memoryAGet(ds, 0x9bae) == 0x00)
        goto loc_3305;
    ax = memoryAGet16(es, bx + 2);
    ax = -ax;
    dx = memoryAGet16(ds, 0x9290);
    dx += ax;
    memoryASet16(ds, 0x9290, dx);
    ax = dx;
    goto loc_3314;
loc_3305: // 01ed:1435
    bx = memoryAGet16(ds, 0xa1ac);
    es = memoryAGet16(ds, 0xa1ac + 2);
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0x9290, memoryAGet16(ds, 0x9290) + ax);
    ax = memoryAGet16(ds, 0x9290);
loc_3314: // 01ed:1444
    bx = memoryAGet16(ds, 0xa1ac);
    es = memoryAGet16(ds, 0xa1ac + 2);
    ax = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x9292, memoryAGet16(ds, 0x9292) + ax);
    memoryASet16(ds, 0xa1ac, memoryAGet16(ds, 0xa1ac) + 0x0006);
    al = memoryAGet(ds, 0x824d);
    al += 0xff;
    memoryASet(ds, 0x824d, al);
    ah = 0x00;
    if (ax)
        goto loc_333a;
    al = 0x00;
    memoryASet(ds, 0x792a, al);
    goto loc_3341;
loc_333a: // 01ed:146a
    memoryASet(ds, 0x792a, memoryAGet(ds, 0x792a) + 1);
    al = memoryAGet(ds, 0x792a);
loc_3341: // 01ed:1471
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3343() // 01ed:1473
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3351;
    sub_ca53();
loc_3351: // 01ed:1481
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    di = memoryAGet16(es, bx + 20);
    si = memoryAGet16(es, bx + 22);
    ax = memoryAGet16(ds, 0x9290);
    ax -= di;
    cl = 0x04;
    ax = sar(ax, cl);
    ax--;
    memoryASet16(ds, 0x9d36, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax -= si;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet16(ds, 0x9d38, ax);
    if ((short)memoryAGet16(ds, 0x9d36) >= (short)0x0000)
        goto loc_3387;
    memoryASet16(ds, 0x9d36, 0x0000);
    goto loc_3394;
loc_3387: // 01ed:14b7
    if ((short)memoryAGet16(ds, 0x9d36) <= (short)0x0012)
        goto loc_3394;
    memoryASet16(ds, 0x9d36, 0x0012);
loc_3394: // 01ed:14c4
    if ((short)memoryAGet16(ds, 0x9d38) >= (short)0x0000)
        goto loc_33a3;
    memoryASet16(ds, 0x9d38, 0x0000);
    goto loc_33b0;
loc_33a3: // 01ed:14d3
    if ((short)memoryAGet16(ds, 0x9d38) <= (short)0x0016)
        goto loc_33b0;
    memoryASet16(ds, 0x9d38, 0x0016);
loc_33b0: // 01ed:14e0
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_33b4() // 01ed:14e4
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_33c4;
    sub_ca53();
loc_33c4: // 01ed:14f4
    memoryASet(ds, 0x856c, 0x00);
    cl = 0x00;
    goto loc_3464;
loc_33ce: // 01ed:14fe
    al = memoryAGet(ds, 0x856c);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    if (memoryAGet(es, bx) == 0x00)
        goto loc_345e;
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0xa0be, dx);
    memoryASet16(ds, 0xa0c0, ax);
    bx = memoryAGet16(ds, 0xa0be);
    es = memoryAGet16(ds, 0xa0be + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x8578, al);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + 1);
    memoryASet(es, bx + 6, al);
    if (memoryAGet(ds, 0x8578) != 0xff)
        goto loc_3421;
    memoryASet(es, bx, 0x00);
    goto loc_345e;
loc_3421: // 01ed:1551
    if (memoryAGet(ds, 0x8578) == 0x00)
        goto loc_345e;
    al = memoryAGet(ds, 0x8578);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 15724);
    dx = memoryAGet16(ds, bx + 15722);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    push(es);
    si = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, si);
    es = pop();
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 10, ax);
loc_345e: // 01ed:158e
    memoryASet(ds, 0x856c, memoryAGet(ds, 0x856c) + 1);
    cl++;
loc_3464: // 01ed:1594
    if (cl >= 0x03)
        goto loc_346c;
    goto loc_33ce;
loc_346c: // 01ed:159c
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3471() // 01ed:15a1
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3481;
    sub_ca53();
loc_3481: // 01ed:15b1
    memoryASet(ds, 0x8566, 0x00);
    cl = 0x00;
    goto loc_3521;
loc_348b: // 01ed:15bb
    al = memoryAGet(ds, 0x8566);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    if (memoryAGet(es, bx) == 0x00)
        goto loc_351b;
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0xa0c2, dx);
    memoryASet16(ds, 0xa0c4, ax);
    bx = memoryAGet16(ds, 0xa0c2);
    es = memoryAGet16(ds, 0xa0c2 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x8579, al);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) + 1);
    memoryASet(es, bx + 6, al);
    if (memoryAGet(ds, 0x8579) != 0xff)
        goto loc_34de;
    memoryASet(es, bx, 0x00);
    goto loc_351b;
loc_34de: // 01ed:160e
    if (memoryAGet(ds, 0x8579) == 0x00)
        goto loc_351b;
    al = memoryAGet(ds, 0x8579);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 16552);
    dx = memoryAGet16(ds, bx + 16550);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    push(es);
    si = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, si);
    es = pop();
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 10, ax);
loc_351b: // 01ed:164b
    memoryASet(ds, 0x8566, memoryAGet(ds, 0x8566) + 1);
    cl++;
loc_3521: // 01ed:1651
    if (cl >= 0x04)
        goto loc_3529;
    goto loc_348b;
loc_3529: // 01ed:1659
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_352e() // 01ed:165e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_353f;
    sub_ca53();
loc_353f: // 01ed:166f
    memoryASet(ss, bp - 2, 0x00);
loc_3543: // 01ed:1673
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 12, dx);
    memoryASet16(ss, bp - 10, ax);
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_356e;
    goto loc_3685;
loc_356e: // 01ed:169e
    if (memoryAGet(ss, bp - 1) != 0xff)
        goto loc_3577;
    goto loc_3685;
loc_3577: // 01ed:16a7
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 3, al);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    di = memoryAGet16(ds, bx + 12990);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    si = memoryAGet16(ds, bx + 12992);
    bx = memoryAGet16(ds, 0x08d4);
    es = memoryAGet16(ds, 0x08d4 + 2);
    memoryASet16(es, bx + 28, 0x0000);
    if (!(memoryAGet(ss, bp - 3) & 0x01))
        goto loc_35b4;
    ax = memoryAGet16(es, bx + 28);
    ax |= 0x0600;
    memoryASet16(es, bx + 28, ax);
loc_35b4: // 01ed:16e4
    bx = memoryAGet16(ds, 0x08d4);
    es = memoryAGet16(ds, 0x08d4 + 2);
    ax = di;
    memoryASet16(es, bx + 20, ax);
    memoryASet16(es, bx + 6, ax);
    ax = si;
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 8, ax);
    push(memoryAGet16(ds, 0x08d6));
    push(memoryAGet16(ds, 0x08d4));
    sub_9f8c();
    sp += 0x0004;
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 244);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 246);
    memoryASet16(ss, bp - 8, ax);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(es, bx, ax);
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(ss, bp - 8);
    ax += memoryAGet16(es, bx + 8);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(es, bx + 10);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, ax);
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    if (memoryAGet16(es, bx + 10) & 0x0200)
        goto loc_363f;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_363f: // 01ed:176f
    bx = memoryAGet16(ds, 0x08e0);
    es = memoryAGet16(ds, 0x08e0 + 2);
    memoryASet16(es, bx + 6, di);
    memoryASet16(es, bx + 8, si);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    dx = 0x0180;
    imul(dx);
    ax += 0x79be;
    memoryASet16(es, bx + 16, ax);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 28, 0x0000);
    if (!(memoryAGet(ss, bp - 3) & 0x01))
        goto loc_3677;
    ax = memoryAGet16(es, bx + 28);
    ax |= 0x0200;
    memoryASet16(es, bx + 28, ax);
loc_3677: // 01ed:17a7
    push(memoryAGet16(ds, 0x08e2));
    push(memoryAGet16(ds, 0x08e0));
    sub_b288();
    sp += 0x0004;
loc_3685: // 01ed:17b5
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_3691;
    goto loc_3543;
loc_3691: // 01ed:17c1
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3697() // 01ed:17c7
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_36a8;
    sub_ca53();
loc_36a8: // 01ed:17d8
    memoryASet(ss, bp - 2, 0x00);
loc_36ac: // 01ed:17dc
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 12, dx);
    memoryASet16(ss, bp - 10, ax);
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_36d7;
    goto loc_385f;
loc_36d7: // 01ed:1807
    if (memoryAGet(ss, bp - 1) != 0xff)
        goto loc_36e0;
    goto loc_385f;
loc_36e0: // 01ed:1810
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 3, al);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    di = memoryAGet16(ds, bx + 13374);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    si = memoryAGet16(ds, bx + 13376);
    bx = memoryAGet16(ds, 0x08c8);
    es = memoryAGet16(ds, 0x08c8 + 2);
    memoryASet16(es, bx + 6, di);
    memoryASet16(es, bx + 8, si);
    push(memoryAGet16(ds, 0x08ca));
    push(memoryAGet16(ds, 0x08c8));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x08cc);
    es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 10, 0x0001);
    ax = 0;
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 20, ax);
    memoryASet16(es, bx + 28, 0x0004);
    if (!(memoryAGet(ss, bp - 3) & 0x01))
        goto loc_3760;
    memoryASet16(es, bx + 2, 0x9fba);
    memoryASet16(es, bx + 4, ds);
    push(memoryAGet16(ds, 0x08ce));
    push(memoryAGet16(ds, 0x08cc));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x08cc);
    es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 2, 0x9eba);
    goto loc_3786;
loc_3760: // 01ed:1890
    bx = memoryAGet16(ds, 0x08cc);
    es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 2, 0x9eba);
    memoryASet16(es, bx + 4, ds);
    push(memoryAGet16(ds, 0x08ce));
    push(memoryAGet16(ds, 0x08cc));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x08cc);
    es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 2, 0x9fba);
loc_3786: // 01ed:18b6
    memoryASet16(es, bx + 4, ds);
    bx = memoryAGet16(ds, 0x08cc);
    es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 20, di);
    memoryASet16(es, bx + 22, si);
    push(memoryAGet16(ds, 0x08ce));
    push(memoryAGet16(ds, 0x08cc));
    sub_9f8c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x08cc);
    es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 2, 0x8888);
    memoryASet16(es, bx + 4, ds);
    memoryASet16(es, bx + 10, 0x0003);
    memoryASet16(es, bx + 28, 0x0003);
    push(memoryAGet16(ds, 0x08ce));
    push(memoryAGet16(ds, 0x08cc));
    sub_9f8c();
    sp += 0x0004;
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1012);
    memoryASet16(ss, bp - 6, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1014);
    memoryASet16(ss, bp - 8, ax);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ss, bp - 6);
    memoryASet16(es, bx, ax);
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(ss, bp - 8);
    ax += memoryAGet16(es, bx + 8);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    if (memoryAGet16(es, bx + 10) & 0x0200)
        goto loc_3831;
    ax = memoryAGet16(es, bx + 10);
    ax += 0x00f1;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_3831: // 01ed:1961
    bx = memoryAGet16(ds, 0x08d0);
    es = memoryAGet16(ds, 0x08d0 + 2);
    memoryASet16(es, bx + 6, di);
    memoryASet16(es, bx + 8, si);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    cl = 0x08;
    ax <<= cl;
    ax += 0x7e3e;
    memoryASet16(es, bx + 16, ax);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x08d2));
    push(memoryAGet16(ds, 0x08d0));
    sub_b288();
    sp += 0x0004;
loc_385f: // 01ed:198f
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_386b;
    goto loc_36ac;
loc_386b: // 01ed:199b
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3871() // 01ed:19a1
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_387d;
    sub_ca53();
loc_387d: // 01ed:19ad
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_38b2;
    bx = memoryAGet16(ds, 0x08e8);
    es = memoryAGet16(ds, 0x08e8 + 2);
    ax = memoryAGet16(ds, 0x928e);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ds, 0x9b94);
    memoryASet16(es, bx + 22, ax);
    ax = memoryAGet16(ds, 0x9d34);
    memoryASet16(es, bx + 30, ax);
    ax = memoryAGet16(ds, 0x9d32);
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x08ea));
    push(memoryAGet16(ds, 0x08e8));
    sub_9f8c();
    sp += 0x0004;
loc_38b2: // 01ed:19e2
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_38b4() // 01ed:19e4
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_38c0;
    sub_ca53();
loc_38c0: // 01ed:19f0
    bx = memoryAGet16(ds, 0x08c4);
    es = memoryAGet16(ds, 0x08c4 + 2);
    ax = memoryAGet16(ds, 0x8882);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ds, 0x8e88);
    memoryASet16(es, bx + 22, ax);
    ax = memoryAGet16(ds, 0x9ba4);
    memoryASet16(es, bx + 30, ax);
    ax = memoryAGet16(ds, 0x9b9c);
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x08c6));
    push(memoryAGet16(ds, 0x08c4));
    sub_9f8c();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_38f0() // 01ed:1a20
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_38fc;
    sub_ca53();
loc_38fc: // 01ed:1a2c
    if (memoryAGet(ds, 0xa1a8) == 0x00)
        goto loc_3935;
    memoryASet(ds, 0xa1a8, memoryAGet(ds, 0xa1a8) - 1);
    bx = memoryAGet16(ds, 0x08e4);
    es = memoryAGet16(ds, 0x08e4 + 2);
    ax = memoryAGet16(ds, 0x9b9a);
    memoryASet16(es, bx + 6, ax);
    ax = memoryAGet16(ds, 0x9ba2);
    memoryASet16(es, bx + 8, ax);
    ax = memoryAGet16(ds, 0x9b9a);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ds, 0x9ba2);
    memoryASet16(es, bx + 22, ax);
    push(memoryAGet16(ds, 0x08e6));
    push(memoryAGet16(ds, 0x08e4));
    sub_9f8c();
    sp += 0x0004;
loc_3935: // 01ed:1a65
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3937() // 01ed:1a67
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3946;
    sub_ca53();
loc_3946: // 01ed:1a76
    memoryASet(ss, bp - 2, 0x00);
loc_394a: // 01ed:1a7a
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_39eb;
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_39eb;
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 3, al);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    dx = 0x0180;
    imul(dx);
    ax += 0x79be;
    bx = memoryAGet16(ds, 0x08c0);
    es = memoryAGet16(ds, 0x08c0 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet16(es, bx + 4, ds);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 12990);
    bx = memoryAGet16(ds, 0x08c0);
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 12992);
    bx = memoryAGet16(ds, 0x08c0);
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 28, 0x0000);
    if (!(memoryAGet(ss, bp - 3) & 0x01))
        goto loc_39dd;
    ax = memoryAGet16(es, bx + 28);
    ax |= 0x0400;
    memoryASet16(es, bx + 28, ax);
loc_39dd: // 01ed:1b0d
    push(memoryAGet16(ds, 0x08c2));
    push(memoryAGet16(ds, 0x08c0));
    sub_9f8c();
    sp += 0x0004;
loc_39eb: // 01ed:1b1b
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_39f7;
    goto loc_394a;
loc_39f7: // 01ed:1b27
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_39fb() // 01ed:1b2b
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3a0a;
    sub_ca53();
loc_3a0a: // 01ed:1b3a
    memoryASet(ss, bp - 2, 0x00);
loc_3a0e: // 01ed:1b3e
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_3a97;
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_3a97;
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 3, al);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    cl = 0x08;
    ax <<= cl;
    ax += 0x7e3e;
    bx = memoryAGet16(ds, 0x08bc);
    es = memoryAGet16(ds, 0x08bc + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet16(es, bx + 4, ds);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 13374);
    bx = memoryAGet16(ds, 0x08bc);
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 13376);
    bx = memoryAGet16(ds, 0x08bc);
    memoryASet16(es, bx + 22, ax);
    push(memoryAGet16(ds, 0x08be));
    push(memoryAGet16(ds, 0x08bc));
    sub_9f8c();
    sp += 0x0004;
loc_3a97: // 01ed:1bc7
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    if (memoryAGet(ss, bp - 1) == 0xff)
        goto loc_3aa3;
    goto loc_3a0e;
loc_3aa3: // 01ed:1bd3
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3aa7() // 01ed:1bd7
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3ab3;
    sub_ca53();
loc_3ab3: // 01ed:1be3
    memoryASet16(ds, 0x9ba4, 0x0004);
    if ((short)memoryAGet16(ds, 0x857a) <= (short)0x0010)
        goto loc_3aca;
    ax = 0x0014;
    ax -= memoryAGet16(ds, 0x857a);
    memoryASet16(ds, 0x9ba4, ax);
loc_3aca: // 01ed:1bfa
    memoryASet16(ds, 0x9b9c, 0x0004);
    if ((short)memoryAGet16(ds, 0x857c) <= (short)0x0015)
        goto loc_3ae1;
    ax = 0x0019;
    ax -= memoryAGet16(ds, 0x857c);
    memoryASet16(ds, 0x9b9c, ax);
loc_3ae1: // 01ed:1c11
    bx = memoryAGet16(ds, 0x08b8);
    es = memoryAGet16(ds, 0x08b8 + 2);
    ax = memoryAGet16(ds, 0x857a);
    memoryASet16(es, bx + 6, ax);
    ax = memoryAGet16(ds, 0x857c);
    memoryASet16(es, bx + 8, ax);
    ax = memoryAGet16(ds, 0x9ba4);
    memoryASet16(es, bx + 30, ax);
    ax = memoryAGet16(ds, 0x9b9c);
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x08ba));
    push(memoryAGet16(ds, 0x08b8));
    sub_b288();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3b11() // 01ed:1c41
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3b1d;
    sub_ca53();
loc_3b1d: // 01ed:1c4d
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_3b80;
    memoryASet16(ds, 0x9d34, 0x0004);
    if ((short)memoryAGet16(ds, 0x8558) <= (short)0x0010)
        goto loc_3b3b;
    ax = 0x0014;
    ax -= memoryAGet16(ds, 0x8558);
    memoryASet16(ds, 0x9d34, ax);
loc_3b3b: // 01ed:1c6b
    memoryASet16(ds, 0x9d32, 0x0004);
    if ((short)memoryAGet16(ds, 0x855a) <= (short)0x0015)
        goto loc_3b52;
    ax = 0x0019;
    ax -= memoryAGet16(ds, 0x855a);
    memoryASet16(ds, 0x9d32, ax);
loc_3b52: // 01ed:1c82
    bx = memoryAGet16(ds, 0x08ec);
    es = memoryAGet16(ds, 0x08ec + 2);
    ax = memoryAGet16(ds, 0x8558);
    memoryASet16(es, bx + 6, ax);
    ax = memoryAGet16(ds, 0x855a);
    memoryASet16(es, bx + 8, ax);
    ax = memoryAGet16(ds, 0x9d34);
    memoryASet16(es, bx + 30, ax);
    ax = memoryAGet16(ds, 0x9d32);
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x08ee));
    push(memoryAGet16(ds, 0x08ec));
    sub_b288();
    sp += 0x0004;
loc_3b80: // 01ed:1cb0
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3b82() // 01ed:1cb2
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3b8e;
    sub_ca53();
loc_3b8e: // 01ed:1cbe
    if (memoryAGet16(ds, 0x824a) == 0x0064)
        goto loc_3bb8;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ds, 0x824a);
    memoryASet16(es, bx + 4, ax);
    ax = memoryAGet16(ds, 0x9290);
    memoryASet16(es, bx, ax);
    ax = memoryAGet16(ds, 0x9292);
    memoryASet16(es, bx + 2, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_3bb8: // 01ed:1ce8
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3bba() // 01ed:1cea
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3bc6;
    sub_ca53();
loc_3bc6: // 01ed:1cf6
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_3bf4;
    bx = memoryAGet16(ds, 0x9b9e);
    es = memoryAGet16(ds, 0x9b9e + 2);
    ax = memoryAGet16(ds, 0xa0de);
    ax += memoryAGet16(ds, 0x8560);
    memoryASet16(es, bx + 4, ax);
    ax = memoryAGet16(ds, 0x79ba);
    memoryASet16(es, bx, ax);
    ax = memoryAGet16(ds, 0x79bc);
    memoryASet16(es, bx + 2, ax);
    push(ds);
    ax = 0x795a;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_3bf4: // 01ed:1d24
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3bf6() // 01ed:1d26
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3c02;
    sub_ca53();
loc_3c02: // 01ed:1d32
    al = 0x3b;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c15;
    memoryASet(ds, 0x854f, 0x00);
    goto loc_3c8b;
loc_3c15: // 01ed:1d45
    al = 0x3c;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c28;
    memoryASet(ds, 0x854f, 0x88);
    goto loc_3c8b;
loc_3c28: // 01ed:1d58
    al = 0x3d;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c3b;
    memoryASet(ds, 0x854f, 0xaa);
    goto loc_3c8b;
loc_3c3b: // 01ed:1d6b
    al = 0x3e;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c4e;
    memoryASet(ds, 0x854f, 0xee);
    goto loc_3c8b;
loc_3c4e: // 01ed:1d7e
    al = 0x3f;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c61;
    memoryASet(ds, 0x854f, 0xff);
    goto loc_3c8b;
loc_3c61: // 01ed:1d91
    al = 0x01;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c72;
    sub_41cc();
    goto loc_3c8b;
loc_3c72: // 01ed:1da2
    al = 0x44;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c8b;
    memoryASet(ds, 0x928d, 0x01);
    al = 0x00;
    memoryASet(ds, 0x9d30, al);
    memoryASet(ds, 0x856d, al);
loc_3c8b: // 01ed:1dbb
    if (memoryAGet(ds, 0xa1aa) == 0x00)
        goto loc_3c97;
    sub_415d();
    goto loc_3cac;
loc_3c97: // 01ed:1dc7
    sub_423f();
    sub_3cae();
    if (memoryAGet(ds, 0x824d) == 0x00)
        goto loc_3ca9;
    sub_425e();
    goto loc_3cac;
loc_3ca9: // 01ed:1dd9
    sub_3cd2();
loc_3cac: // 01ed:1ddc
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3cae() // 01ed:1dde
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3cbc;
    sub_ca53();
loc_3cbc: // 01ed:1dec
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    memoryASet(ss, bp - 1, al);
    if (!al)
        goto loc_3cce;
    memoryASet(ds, 0x8244, al);
loc_3cce: // 01ed:1dfe
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3cd2() // 01ed:1e02
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3cde;
    sub_ca53();
loc_3cde: // 01ed:1e0e
    memoryASet(ds, 0x7923, 0x00);
    al = memoryAGet(ds, 0x792c);
    memoryASet(ds, 0x8552, al);
    if (memoryAGet(ds, 0xa0ce) != 0x00)
        goto loc_3cf9;
    al = memoryAGet(ds, 0xa1a7);
    ah = 0x00;
    if (ax)
        goto loc_3d08;
loc_3cf9: // 01ed:1e29
    al = memoryAGet(ds, 0x792c);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    callIndirect(cs*16+memoryAGet16(ds, bx + 1994));
    goto loc_3d0b;
loc_3d08: // 01ed:1e38
    sub_46ae();
loc_3d0b: // 01ed:1e3b
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3d0d() // 01ed:1e3d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3d19;
    sub_ca53();
loc_3d19: // 01ed:1e49
    al = 0x01;
    memoryASet(ds, 0x9d30, al);
    memoryASet(ds, 0xa1a9, al);
    sub_5958();
    bx = memoryAGet16(ds, 0x9baa);
    es = memoryAGet16(ds, 0x9baa + 2);
    memoryASet(es, bx, 0x01);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3e8e() // 01ed:1fbe
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3e9a;
    sub_ca53();
loc_3e9a: // 01ed:1fca
    memoryASet(ds, 0x8551, 0x00);
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_3eaa;
    al = 0x02;
    goto loc_3eac;
loc_3eaa: // 01ed:1fda
    al = 0x26;
loc_3eac: // 01ed:1fdc
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_3ec4;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x38;
    goto loc_3f42;
loc_3ec4: // 01ed:1ff4
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryAGet(ds, bx + 17238) != 0x38)
        goto loc_3ee4;
    al = 0x38;
    goto loc_3f42;
loc_3ee4: // 01ed:2014
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_3efa;
    al = 0x3a;
    goto loc_3f42;
loc_3efa: // 01ed:202a
    if (memoryAGet(ds, 0x855e) != 0x01)
        goto loc_3f0a;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x34;
    goto loc_3f42;
loc_3f0a: // 01ed:203a
    al = memoryAGet(ds, 0x856e);
    al += 0xfe;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryAGet(ds, bx + 17174) != 0x34)
        goto loc_3f2a;
    al = 0x34;
    goto loc_3f42;
loc_3f2a: // 01ed:205a
    al = memoryAGet(ds, 0x856e);
    al += 0xfe;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_3f40;
    al = 0x36;
    goto loc_3f42;
loc_3f40: // 01ed:2070
    al = 0x1a;
loc_3f42: // 01ed:2072
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3f4d() // 01ed:207d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_3f59;
    sub_ca53();
loc_3f59: // 01ed:2089
    memoryASet(ds, 0x8551, 0x00);
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_3f69;
    al = 0x02;
    goto loc_3f6b;
loc_3f69: // 01ed:2099
    al = 0x26;
loc_3f6b: // 01ed:209b
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x855e) != 0x07)
        goto loc_3f81;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x39;
    goto loc_3ffd;
loc_3f81: // 01ed:20b1
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryAGet(ds, bx + 17270) != 0x39)
        goto loc_3f9f;
    al = 0x39;
    goto loc_3ffd;
loc_3f9f: // 01ed:20cf
    al = memoryAGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_3fb5;
    al = 0x3b;
    goto loc_3ffd;
loc_3fb5: // 01ed:20e5
    if (memoryAGet(ds, 0x855e) != 0x06)
        goto loc_3fc5;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x35;
    goto loc_3ffd;
loc_3fc5: // 01ed:20f5
    al = memoryAGet(ds, 0x856e);
    al++;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryAGet(ds, bx + 17206) != 0x35)
        goto loc_3fe5;
    al = 0x35;
    goto loc_3ffd;
loc_3fe5: // 01ed:2115
    al = memoryAGet(ds, 0x856e);
    al += 0x02;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_3ffb;
    al = 0x37;
    goto loc_3ffd;
loc_3ffb: // 01ed:212b
    al = 0x1b;
loc_3ffd: // 01ed:212d
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_415d() // 01ed:228d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4169;
    sub_ca53();
loc_4169: // 01ed:2299
    memoryASet(ds, 0xa0ce, 0x01);
    al = 0x00;
    memoryASet(ds, 0x792a, al);
    memoryASet(ds, 0xa1aa, al);
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4180() // 01ed:22b0
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_418c;
    sub_ca53();
loc_418c: // 01ed:22bc
    sub_41cc();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4191() // 01ed:22c1
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_419d;
    sub_ca53();
loc_419d: // 01ed:22cd
    sub_41cc();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_41a2() // 01ed:22d2
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_41ae;
    sub_ca53();
loc_41ae: // 01ed:22de
    al = memoryAGet(ds, 0xa0ce);
    al++;
    memoryASet(ds, 0xa0ce, al);
    if (al != 0x03)
        goto loc_41bf;
    sub_41cc();
    goto loc_41ca;
loc_41bf: // 01ed:22ef
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
loc_41ca: // 01ed:22fa
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_41cc() // 01ed:22fc
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_41d9;
    sub_ca53();
loc_41d9: // 01ed:2309
    memoryASet(ds, 0xa0ce, 0x00);
    si = 0x03e8;
    goto loc_41e7;
loc_41e3: // 01ed:2313
    sub_423f();
    si--;
loc_41e7: // 01ed:2317
    if (si)
        goto loc_41e3;
    memoryASet(ds, 0x856d, 0x01);
    al = memoryAGet(ds, 0x791a);
    ah = 0x00;
    if (ax)
        goto loc_4200;
    al = 0xff;
    memoryASet(ds, 0x928d, al);
    goto loc_4207;
loc_4200: // 01ed:2330
    memoryASet(ds, 0x791a, memoryAGet(ds, 0x791a) - 1);
    al = memoryAGet(ds, 0x791a);
loc_4207: // 01ed:2337
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_420a() // 01ed:233a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4216;
    sub_ca53();
loc_4216: // 01ed:2346
    if (memoryAGet(ds, 0xa1b1) == 0x00)
        goto loc_423d;
    if (memoryAGet(ds, 0x8550) == 0x09)
        goto loc_422a;
    memoryASet(ds, 0x8550, memoryAGet(ds, 0x8550) + 1);
    goto loc_423d;
loc_422a: // 01ed:235a
    memoryASet(ds, 0x8550, 0x00);
    al = memoryAGet(ds, 0x8572);
    memoryASet(ds, 0x856f, al);
    al = 0x5a;
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_423d: // 01ed:236d
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_423f() // 01ed:236f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_424b;
    sub_ca53();
loc_424b: // 01ed:237b
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x7924, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_425e() // 01ed:238e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_426a;
    sub_ca53();
loc_426a: // 01ed:239a
    al = memoryAGet(ds, 0x792c);
    ah = 0x00;
    dx = 0x0022;
    imul(dx);
    dl = memoryAGet(ds, 0x792a);
    dh = 0x00;
    dx <<= 1;
    ax += dx;
    bx = ax;
    callIndirect(cs*16+memoryAGet16(ds, bx + 17344));
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4286() // 01ed:23b6
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4292;
    sub_ca53();
loc_4292: // 01ed:23c2
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_429e;
    sub_4504();
    goto loc_42f1;
loc_429e: // 01ed:23ce
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_42aa;
    sub_4571();
    goto loc_42f1;
loc_42aa: // 01ed:23da
    if (memoryAGet(ds, 0x856e) < 0x08)
        goto loc_42c9;
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryAGet(es, bx + 65528) != 0x0e)
        goto loc_42c9;
    goto loc_42ee;
loc_42c9: // 01ed:23f9
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_42ee;
    sub_6617();
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_42e4;
    al = 0x14;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    goto loc_42f1;
loc_42e4: // 01ed:2414
    al = 0x2a;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    goto loc_42f1;
loc_42ee: // 01ed:241e
    sub_46ae();
loc_42f1: // 01ed:2421
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_42f3() // 01ed:2423
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4302;
    sub_ca53();
loc_4302: // 01ed:2432
    memoryASet(ss, bp - 1, 0x21);
    memoryASet(ss, bp - 2, 0x04);
    memoryASet16(ss, bp - 6, 0x14ea);
    memoryASet16(ss, bp - 4, ds);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_4332;
    sub_4504();
    goto loc_433c;
loc_4332: // 01ed:2462
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_433c;
    sub_4571();
loc_433c: // 01ed:246c
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4340() // 01ed:2470
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_434c;
    sub_ca53();
loc_434c: // 01ed:247c
    memoryASet(ds, 0x824c, 0x08);
    al = 0x0b;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_435e() // 01ed:248e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_436d;
    sub_ca53();
loc_436d: // 01ed:249d
    memoryASet(ss, bp - 1, 0x25);
    memoryASet(ss, bp - 2, 0x06);
    memoryASet16(ss, bp - 6, 0x1664);
    memoryASet16(ss, bp - 4, ds);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_43a3;
    al = 0x0c;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
loc_43a3: // 01ed:24d3
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_43a7() // 01ed:24d7
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_43b3;
    sub_ca53();
loc_43b3: // 01ed:24e3
    if (memoryAGet(ds, 0x7924) != 0x00)
        goto loc_43d0;
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryAGet(es, bx + 8) != 0x0b)
        goto loc_43d5;
loc_43d0: // 01ed:2500
    sub_43da();
    goto loc_43d8;
loc_43d5: // 01ed:2505
    sub_47b0();
loc_43d8: // 01ed:2508
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_43da() // 01ed:250a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_43e6;
    sub_ca53();
loc_43e6: // 01ed:2516
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_43f2;
    sub_4504();
    goto loc_440d;
loc_43f2: // 01ed:2522
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_43fe;
    sub_4571();
    goto loc_440d;
loc_43fe: // 01ed:252e
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_440a;
    sub_440f();
    goto loc_440d;
loc_440a: // 01ed:253a
    sub_46ae();
loc_440d: // 01ed:253d
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_440f() // 01ed:253f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_441b;
    sub_ca53();
loc_441b: // 01ed:254b
    if (memoryAGet(ds, 0x7924) != 0x0f)
        goto loc_4427;
    sub_66d2();
    goto loc_443a;
loc_4427: // 01ed:2557
    if (memoryAGet(ds, 0x7924) != 0x12)
        goto loc_4430;
    goto loc_4437;
loc_4430: // 01ed:2560
    if (memoryAGet(ds, 0x7924) != 0x1f)
        goto loc_443a;
loc_4437: // 01ed:2567
    sub_4180();
loc_443a: // 01ed:256a
    sub_84cb();
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_4448;
    al = 0x14;
    goto loc_444a;
loc_4448: // 01ed:2578
    al = 0x09;
loc_444a: // 01ed:257a
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    memoryASet(ds, 0x824c, memoryAGet(ds, 0x824c) + 1);
    if (memoryAGet(ds, 0x824c) != 0x09)
        goto loc_4470;
    al = memoryAGet(ds, 0x856e);
    al += 0xf8;
    memoryASet(ds, 0x856f, al);
    al = 0x24;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    memoryASet(ds, 0x824c, 0x00);
loc_4470: // 01ed:25a0
    al = 0x0d;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_447d() // 01ed:25ad
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_448b;
    sub_ca53();
loc_448b: // 01ed:25bb
    memoryASet(ss, bp - 2, 0x00);
    al = memoryAGet(ds, 0x856e);
    memoryASet(ss, bp - 1, al);
    goto loc_44f7;
loc_4497: // 01ed:25c7
    al = memoryAGet(ss, bp - 1);
    al++;
    memoryASet(ss, bp - 1, al);
    if (al != 0x30)
        goto loc_44a7;
    memoryASet(ss, bp - 1, 0x00);
loc_44a7: // 01ed:25d7
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx) != 0x0f)
        goto loc_44f7;
    al = memoryAGet(ss, bp - 1);
    memoryASet(ds, 0x856f, al);
    memoryASet(ds, 0x856e, al);
    sub_67d6();
    ax = memoryAGet16(ds, 0x9292);
    ax += 0x000d;
    memoryASet16(ds, 0x9292, ax);
    al = 0x27;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_44e0;
    al = 0x03;
    goto loc_44e2;
loc_44e0: // 01ed:2610
    al = 0x28;
loc_44e2: // 01ed:2612
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x0f;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    memoryASet(ss, bp - 2, 0x01);
loc_44f7: // 01ed:2627
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    if (!ax)
        goto loc_4497;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4504() // 01ed:2634
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4512;
    sub_ca53();
loc_4512: // 01ed:2642
    memoryASet(ds, 0x8551, 0x00);
    sub_828e();
    al = memoryAGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_452c;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x12;
    goto loc_4564;
loc_452c: // 01ed:265c
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 16982);
    memoryASet(ss, bp - 1, al);
    if (al == 0x01)
        goto loc_454e;
    goto loc_4564;
loc_454e: // 01ed:267e
    al = memoryAGet(ds, 0x8570);
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_4562;
    al = 0x16;
    goto loc_4564;
loc_4562: // 01ed:2692
    al = 0x01;
loc_4564: // 01ed:2694
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4571() // 01ed:26a1
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_457f;
    sub_ca53();
loc_457f: // 01ed:26af
    memoryASet(ds, 0x8551, 0x00);
    sub_828e();
    if (memoryAGet(ds, 0x855e) != 0x07)
        goto loc_4597;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x13;
    goto loc_45cf;
loc_4597: // 01ed:26c7
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17014);
    memoryASet(ss, bp - 1, al);
    if (al == 0x02)
        goto loc_45b7;
    goto loc_45cf;
loc_45b7: // 01ed:26e7
    al = memoryAGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_45cd;
    al = 0x17;
    goto loc_45cf;
loc_45cd: // 01ed:26fd
    al = 0x02;
loc_45cf: // 01ed:26ff
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_45dc() // 01ed:270c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_45ea;
    sub_ca53();
loc_45ea: // 01ed:271a
    memoryASet(ds, 0x8551, 0x00);
    al = memoryAGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_4601;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x14;
    goto loc_4639;
loc_4601: // 01ed:2731
    al = memoryAGet(ds, 0x856e);
    al += 0xff;
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17046);
    memoryASet(ss, bp - 1, al);
    if (al == 0x08)
        goto loc_4623;
    goto loc_4639;
loc_4623: // 01ed:2753
    al = memoryAGet(ds, 0x8570);
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_4637;
    al = 0x18;
    goto loc_4639;
loc_4637: // 01ed:2767
    al = 0x08;
loc_4639: // 01ed:2769
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4646() // 01ed:2776
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4654;
    sub_ca53();
loc_4654: // 01ed:2784
    memoryASet(ds, 0x8551, 0x00);
    if (memoryAGet(ds, 0x855e) != 0x07)
        goto loc_4669;
    memoryASet(ds, 0x8551, 0x1f);
    al = 0x15;
    goto loc_46a1;
loc_4669: // 01ed:2799
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17078);
    memoryASet(ss, bp - 1, al);
    if (al == 0x09)
        goto loc_4689;
    goto loc_46a1;
loc_4689: // 01ed:27b9
    al = memoryAGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x7921) != 0x0b)
        goto loc_469f;
    al = 0x19;
    goto loc_46a1;
loc_469f: // 01ed:27cf
    al = 0x09;
loc_46a1: // 01ed:27d1
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_46ae() // 01ed:27de
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_46ba;
    sub_ca53();
loc_46ba: // 01ed:27ea
    al = 0x00;
    memoryASet(ds, 0x7923, al);
    memoryASet(ds, 0xa1a7, al);
    memoryASet(ds, 0x79b9, 0x0b);
    if (memoryAGet(ds, 0x7924) != 0x11)
        goto loc_46d8;
    al = 0x2f;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_46db;
loc_46d8: // 01ed:2808
    sub_46e0();
loc_46db: // 01ed:280b
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_46e0() // 01ed:2810
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_46ef;
    sub_ca53();
loc_46ef: // 01ed:281f
    if (memoryAGet(ds, 0x8552) == 0x03)
        goto loc_4732;
    if (memoryAGet(ds, 0x8552) == 0x0d)
        goto loc_4732;
    if (memoryAGet(ds, 0x8552) == 0x10)
        goto loc_4732;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_4718;
    al = memoryAGet(ds, 0x7922);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9886);
    goto loc_4723;
loc_4718: // 01ed:2848
    al = memoryAGet(ds, 0x7922);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9838);
loc_4723: // 01ed:2853
    memoryASet(ss, bp - 4, al);
    if (memoryAGet(ss, bp - 4) == 0x00)
        goto loc_4732;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_4732: // 01ed:2862
    if (memoryAGet(ds, 0x856e) >= 0x08)
        goto loc_4741;
    al = 0x06;
    push(ax);
    sub_6133();
    goto loc_47aa;
loc_4741: // 01ed:2871
    al = memoryAGet(ds, 0x856e);
    al += 0xf8;
    memoryASet(ds, 0x856f, al);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, al);
    memoryASet(ds, 0x79b9, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryAGet(ds, bx + 1898);
    memoryASet(ss, bp - 2, al);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryAGet(ds, bx + 1899);
    memoryASet(ss, bp - 3, al);
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x792c) != 0x0a)
        goto loc_479d;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_4795;
    al = 0x14;
    goto loc_4797;
loc_4795: // 01ed:28c5
    al = 0x09;
loc_4797: // 01ed:28c7
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_479d: // 01ed:28cd
    if (memoryAGet(ss, bp - 3) == 0x00)
        goto loc_47ac;
    al = memoryAGet(ss, bp - 3);
    push(ax);
    sub_887a();
loc_47aa: // 01ed:28da
    sp++;
    sp++;
loc_47ac: // 01ed:28dc
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_47b0() // 01ed:28e0
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_47bc;
    sub_ca53();
loc_47bc: // 01ed:28ec
    al = 0x04;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_47c9() // 01ed:28f9
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_47d5;
    sub_ca53();
loc_47d5: // 01ed:2905
    memoryASet(ds, 0x824c, 0x08);
    if (memoryAGet(ds, 0x79b4) != 0x00)
        goto loc_47e8;
    if (memoryAGet(ds, 0x7924) != 0x00)
        goto loc_47fe;
loc_47e8: // 01ed:2918
    memoryASet(ds, 0x79b4, 0x00);
    if (memoryAGet(ds, 0x856e) >= 0x28)
        goto loc_47f9;
    sub_47b0();
    goto loc_4833;
loc_47f9: // 01ed:2929
    sub_61a9();
    goto loc_4833;
loc_47fe: // 01ed:292e
    if (memoryAGet(ds, 0x7924) != 0x20)
        goto loc_4818;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_4810;
    al = 0x03;
    goto loc_4812;
loc_4810: // 01ed:2940
    al = 0x28;
loc_4812: // 01ed:2942
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_4818: // 01ed:2948
    if (memoryAGet(ds, 0x7924) != 0x16)
        goto loc_4824;
    sub_61d5();
    goto loc_4833;
loc_4824: // 01ed:2954
    if (memoryAGet(ds, 0x7924) != 0x03)
        goto loc_4830;
    sub_650d();
    goto loc_4833;
loc_4830: // 01ed:2960
    sub_4835();
loc_4833: // 01ed:2963
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4835() // 01ed:2965
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4841;
    sub_ca53();
loc_4841: // 01ed:2971
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_484d;
    sub_654d();
    goto loc_4874;
loc_484d: // 01ed:297d
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_4859;
    sub_656c();
    goto loc_4874;
loc_4859: // 01ed:2989
    if (memoryAGet(ds, 0x7924) != 0x0a)
        goto loc_4865;
    sub_669b();
    goto loc_4874;
loc_4865: // 01ed:2995
    if (memoryAGet(ds, 0x7924) != 0x0f)
        goto loc_4871;
    sub_66d2();
    goto loc_4874;
loc_4871: // 01ed:29a1
    sub_4876();
loc_4874: // 01ed:29a4
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4876() // 01ed:29a6
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4882;
    sub_ca53();
loc_4882: // 01ed:29b2
    if (memoryAGet(ds, 0x856e) >= 0x08)
        goto loc_488e;
    sub_652e();
    goto loc_48d8;
loc_488e: // 01ed:29be
    al = memoryAGet(ds, 0x856e);
    al += 0xf8;
    memoryASet(ds, 0x856f, al);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx) == 0x0e)
        goto loc_48a9;
    sub_652e();
    goto loc_48d8;
loc_48a9: // 01ed:29d9
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_48b5;
    sub_440f();
    goto loc_48d8;
loc_48b5: // 01ed:29e5
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_48c0;
    al = 0x14;
    goto loc_48c2;
loc_48c0: // 01ed:29f0
    al = 0x09;
loc_48c2: // 01ed:29f2
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x24;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    al = 0x0a;
    push(ax);
    sub_6133();
    sp++;
    sp++;
loc_48d8: // 01ed:2a08
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_48da() // 01ed:2a0a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_48ea;
    sub_ca53();
loc_48ea: // 01ed:2a1a
    di = 0;
    goto loc_493d;
loc_48ee: // 01ed:2a1e
    si = 0;
    goto loc_4932;
loc_48f2: // 01ed:2a22
    ax = 0x0001;
    push(ax);
    push(di);
    push(si);
    sub_2a58();
    sp += 0x0006;
    ax = si;
    dx = 0x0027;
    imul(dx);
    bx = memoryAGet16(ds, 0x6bca);
    es = memoryAGet16(ds, 0x6bca + 2);
    bx += ax;
    ax = di;
    ax = sar(ax, 1);
    dx = 0x0003;
    imul(dx);
    bx += ax;
    al = memoryAGet(es, bx + 32);
    memoryASet(ss, bp - 1, al);
    if (!al)
        goto loc_4931;
    ax = 0x0001;
    push(ax);
    push(di);
    push(si);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_2960();
    sp += 0x0008;
loc_4931: // 01ed:2a61
    si++;
loc_4932: // 01ed:2a62
    if ((short)si < (short)0x0014)
        goto loc_48f2;
    ax = di;
    ax++;
    ax++;
    di = ax;
loc_493d: // 01ed:2a6d
    if ((short)di < (short)0x001a)
        goto loc_48ee;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4948() // 01ed:2a78
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4959;
    sub_ca53();
loc_4959: // 01ed:2a89
    memoryASet(ds, 0x4c40, 0x00);
    memoryASet(ds, 0x4c4c, 0x00);
    memoryASet(ds, 0x4c58, 0x00);
    memoryASet(ds, 0x4c80, 0x00);
    memoryASet(ds, 0x4c8c, 0x00);
    memoryASet(ds, 0x4c98, 0x00);
    memoryASet(ds, 0x4ca4, 0x00);
    ax = memoryAGet16(ds, 0x4c72);
    dx = memoryAGet16(ds, 0x4c70);
    memoryASet16(ss, bp - 16, dx);
    memoryASet16(ss, bp - 14, ax);
    ax = memoryAGet16(ds, 0x4cbe);
    dx = memoryAGet16(ds, 0x4cbc);
    memoryASet16(ss, bp - 20, dx);
    memoryASet16(ss, bp - 18, ax);
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    al = 0x01;
    memoryASet(es, bx, al);
    memoryASet(ds, 0x8e8b, al);
    bx = memoryAGet16(ss, bp - 20);
    es = memoryAGet16(ss, bp - 20 + 2);
    al = 0x01;
    memoryASet(es, bx, al);
    memoryASet(ds, 0x8e8c, al);
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    al = 0x01;
    memoryASet(es, bx + 6, al);
    memoryASet(ds, 0x8578, al);
    bx = memoryAGet16(ss, bp - 20);
    es = memoryAGet16(ss, bp - 20 + 2);
    al = 0x01;
    memoryASet(es, bx + 6, al);
    memoryASet(ds, 0x8579, al);
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    al = memoryAGet(es, bx + 144);
    memoryASet(ds, 0x856e, al);
    if (memoryAGet(ds, 0x856e) == 0x00)
        goto loc_49db;
    memoryASet(ds, 0x856e, memoryAGet(ds, 0x856e) - 1);
loc_49db: // 01ed:2b0b
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    al = memoryAGet(es, bx + 145);
    memoryASet(ds, 0x8572, al);
    if (memoryAGet(ds, 0x8572) == 0x00)
        goto loc_49f2;
    memoryASet(ds, 0x8572, memoryAGet(ds, 0x8572) - 1);
loc_49f2: // 01ed:2b22
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    al = memoryAGet(es, bx + 146);
    memoryASet(ds, 0xa0cf, al);
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 147);
    al += 0xff;
    memoryASet(ds, 0x8571, al);
    al = memoryAGet(es, bx + 149);
    memoryASet(ds, 0x7920, al);
    al = memoryAGet(es, bx + 148);
    memoryASet(ds, 0x8562, al);
    al = memoryAGet(es, bx + 150);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 9542);
    memoryASet16(ds, 0xa0de, ax);
    sub_670c();
    memoryASet(ss, bp - 2, 0x00);
    goto loc_4bbd;
loc_4a38: // 01ed:2b68
    memoryASet(ss, bp - 1, 0x00);
    goto loc_4bb1;
loc_4a3f: // 01ed:2b6f
    al = memoryAGet(ss, bp - 2);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al += memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 3, al);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dl = memoryAGet(ss, bp - 1);
    dh = 0x00;
    ax += dx;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    si = ax;
    if (!ax)
        goto loc_4abb;
    al = memoryAGet(ds, si + 15674);
    ah = 0x00;
    si = ax;
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 15724);
    dx = memoryAGet16(ds, bx + 15722);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    al = memoryAGet(ss, bp - 3);
    memoryASet(es, bx + 1, al);
    push(es);
    di = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    ax = memoryAGet16(es, di);
    es = pop();
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    ax = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    memoryASet16(es, bx + 10, ax);
    sub_352e();
    sub_3937();
loc_4abb: // 01ed:2beb
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx + 48);
    ah = 0x00;
    si = ax;
    if (!ax)
        goto loc_4b2b;
    if (memoryAGet(ss, bp - 1) == 0x07)
        goto loc_4b2b;
    al = memoryAGet(ds, si + 16518);
    ah = 0x00;
    si = ax;
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 16552);
    dx = memoryAGet16(ds, bx + 16550);
    memoryASet16(ss, bp - 12, dx);
    memoryASet16(ss, bp - 10, ax);
    bx = memoryAGet16(ss, bp - 20);
    es = memoryAGet16(ss, bp - 20 + 2);
    al = memoryAGet(ss, bp - 3);
    memoryASet(es, bx + 1, al);
    push(es);
    di = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(es, di);
    es = pop();
    memoryASet16(es, bx + 8, ax);
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    ax = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 20);
    es = memoryAGet16(ss, bp - 20 + 2);
    memoryASet16(es, bx + 10, ax);
    sub_3697();
    sub_39fb();
loc_4b2b: // 01ed:2c5b
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx + 96);
    ah = 0x00;
    si = ax;
    if (!ax)
        goto loc_4bae;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    dl = memoryAGet(ss, bp - 2);
    dh = 0x00;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax += dx;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 628);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx, ax);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    dl = memoryAGet(ss, bp - 2);
    dh = 0x00;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax += dx;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 630);
    bx = memoryAGet16(ds, 0x8884);
    memoryASet16(es, bx + 2, ax);
    ax = si;
    ax += 0x0179;
    memoryASet16(es, bx + 4, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_4bae: // 01ed:2cde
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_4bb1: // 01ed:2ce1
    if (memoryAGet(ss, bp - 1) >= 0x08)
        goto loc_4bba;
    goto loc_4a3f;
loc_4bba: // 01ed:2cea
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_4bbd: // 01ed:2ced
    if (memoryAGet(ss, bp - 2) >= 0x06)
        goto loc_4bc6;
    goto loc_4a38;
loc_4bc6: // 01ed:2cf6
    bx = memoryAGet16(ss, bp - 16);
    es = memoryAGet16(ss, bp - 16 + 2);
    al = 0x00;
    memoryASet(es, bx + 6, al);
    memoryASet(es, bx, al);
    bx = memoryAGet16(ss, bp - 20);
    es = memoryAGet16(ss, bp - 20 + 2);
    al = 0x00;
    memoryASet(es, bx + 6, al);
    memoryASet(es, bx, al);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4be4() // 01ed:2d14
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4bf4;
    sub_ca53();
loc_4bf4: // 01ed:2d24
    memoryASet(ss, bp - 5, 0x01);
    if (memoryAGet(ds, 0x79b2) <= 0x01)
        goto loc_4c0b;
    al = memoryAGet(ds, 0x119a);
    ah = 0x00;
    if (ax)
        goto loc_4c0b;
    sub_5ee5();
loc_4c0b: // 01ed:2d3b
    if (memoryAGet(ds, 0x119a) != 0xff)
        goto loc_4c17;
    memoryASet(ds, 0x79b2, 0x01);
loc_4c17: // 01ed:2d47
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 4298);
    dx = memoryAGet16(ds, bx + 4296);
    memoryASet16(ds, 0x8246, dx);
    memoryASet16(ds, 0x8248, ax);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 4334);
    dx = memoryAGet16(ds, bx + 4332);
    memoryASet16(ds, 0x8554, dx);
    memoryASet16(ds, 0x8556, ax);
    memoryASet(ds, 0x854e, 0x01);
    ax = 0x001f;
    memoryASet16(ds, 0x791e, ax);
    memoryASet16(ds, 0x791c, ax);
    if (memoryAGet(ds, 0x79b2) == 0x02)
        goto loc_4c67;
    if (memoryAGet(ds, 0x79b2) != 0x05)
        goto loc_4c86;
loc_4c67: // 01ed:2d97
    memoryASet16(ds, 0x791c, 0x006f);
    goto loc_4c86;
loc_4c6f: // 01ed:2d9f
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryAGet16(ds, 0x8246);
    es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    memoryASet(es, bx, 0x00);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_4c86: // 01ed:2db6
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryAGet16(ds, 0x8246);
    es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    if (memoryAGet(es, bx) != 0xff)
        goto loc_4c6f;
    push(ds);
    ax = 0x0090;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0090);
    es = memoryAGet16(ds, 0x0090 + 2);
    al = memoryAGet(ds, 0x79b2);
    al += 0x30;
    memoryASet(es, bx + 1, al);
    bx = memoryAGet16(ds, 0x009a);
    es = memoryAGet16(ds, 0x009a + 2);
    al = memoryAGet(ds, 0x79b2);
    al += 0x30;
    memoryASet(es, bx + 1, al);
    bx = memoryAGet16(ds, 0x00e0);
    es = memoryAGet16(ds, 0x00e0 + 2);
    al = memoryAGet(ds, 0x79b2);
    al += 0x30;
    memoryASet(es, bx + 1, al);
    ax = 0x0004;
    push(ax);
    ax = 0;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0098));
    push(memoryAGet16(ds, 0x0096));
    push(memoryAGet16(ds, 0x6fa8));
    push(memoryAGet16(ds, 0x6fa6));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x0098));
    push(memoryAGet16(ds, 0x0096));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x6fa8));
    push(memoryAGet16(ds, 0x6fa6));
    sub_9a2a();
    sp += 0x000c;
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x00a2));
    push(memoryAGet16(ds, 0x00a0));
    push(memoryAGet16(ds, 0x6bea));
    push(memoryAGet16(ds, 0x6be8));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x00a2));
    push(memoryAGet16(ds, 0x00a0));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x6bea));
    push(memoryAGet16(ds, 0x6be8));
    sub_9a2a();
    sp += 0x000c;
    ax = 0x0004;
    push(ax);
    ax = 0x0008;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x00e8));
    push(memoryAGet16(ds, 0x00e6));
    push(memoryAGet16(ds, 0x75e0));
    push(memoryAGet16(ds, 0x75de));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0x00e8));
    push(memoryAGet16(ds, 0x00e6));
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x75e0));
    push(memoryAGet16(ds, 0x75de));
    sub_9a2a();
    sp += 0x000c;
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4dc8() // 01ed:2ef8
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4dd8;
    sub_ca53();
loc_4dd8: // 01ed:2f08
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    sub_4e7c();
    ax = 0x0004;
    push(ax);
    ax = 0;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0930));
    push(memoryAGet16(ds, 0x092e));
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    sub_b2a8();
    sp += 0x0004;
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x093a));
    push(memoryAGet16(ds, 0x0938));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    sub_70a8();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4e7c() // 01ed:2fac
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4e8d;
    sub_ca53();
loc_4e8d: // 01ed:2fbd
    ax = 0x0004;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0944));
    push(memoryAGet16(ds, 0x0942));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_4f1c;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 5, 0x00);
    goto loc_4f16;
loc_4ef9: // 01ed:3029
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1594);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_4f16: // 01ed:3046
    if (memoryAGet(ss, bp - 5) < 0x10)
        goto loc_4ef9;
loc_4f1c: // 01ed:304c
    sub_5337();
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_b734();
    sub_4fad();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4fad() // 01ed:30dd
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_4fbc;
    sub_ca53();
loc_4fbc: // 01ed:30ec
    memoryASet(ss, bp - 1, 0x00);
    ax = 0x0004;
    push(ax);
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0958));
    push(memoryAGet16(ds, 0x0956));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0x0004;
    push(ax);
    ax = 0x0005;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x0962));
    push(memoryAGet16(ds, 0x0960));
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x8000)
        goto loc_508d;
    goto loc_506c;
loc_5027: // 01ed:3157
    ax = 0x0001;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(memoryAGet16(ds, 0xa0c8));
    push(memoryAGet16(ds, 0xa0c6));
    sub_a847();
    sp += 0x000a;
    goto loc_505c;
loc_5043: // 01ed:3173
    ax = memoryAGet16(ds, 0x119c);
    ax += 0x0007;
    memoryASet16(ds, 0x119c, ax);
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    if (!(al & 0x10))
        goto loc_505c;
    memoryASet(ss, bp - 1, 0x01);
loc_505c: // 01ed:318c
    sub_a869();
    if (!ax)
        goto loc_506c;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_5043;
loc_506c: // 01ed:319c
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_5027;
    sub_a878();
    if (memoryAGet16(ds, 0x689c) != 0x0000)
        goto loc_50a9;
    ax = 0x0001;
    push(ax);
    sub_9ce8();
    sp++;
    sp++;
    sub_b33e();
    goto loc_50a9;
loc_508d: // 01ed:31bd
    memoryASet(ds, 0x8244, 0x00);
    goto loc_50a0;
loc_5094: // 01ed:31c4
    sync();
    sub_3cae();
    ax = memoryAGet16(ds, 0x119c);
    ax += 0x0007;
    memoryASet16(ds, 0x119c, ax);
loc_50a0: // 01ed:31d0
    al = memoryAGet(ds, 0x8244);
    ah = 0x00;
    if (!ax)
        goto loc_5094;
loc_50a9: // 01ed:31d9
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_50ae() // 01ed:31de
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_50ba;
    sub_ca53();
loc_50ba: // 01ed:31ea
    memoryASet(ds, 0x8242, 0x00);
    memoryASet(ds, 0x792a, 0x00);
    memoryASet16(ds, 0x824a, 0x0000);
    memoryASet(ds, 0xa0ce, 0x00);
    al = 0x00;
    memoryASet(ds, 0x8578, al);
    memoryASet(ds, 0x8e8b, al);
    al = 0x00;
    memoryASet(ds, 0x8579, al);
    memoryASet(ds, 0x8e8c, al);
    memoryASet(ds, 0x8244, 0x00);
    memoryASet(ds, 0xa1a7, 0x00);
    memoryASet(ds, 0x79b4, 0x00);
    memoryASet(ds, 0x7923, 0x00);
    memoryASet(ds, 0x824c, 0x00);
    memoryASet(ds, 0xa1a8, 0x00);
    memoryASet(ds, 0xa1b1, 0x00);
    memoryASet(ds, 0x8550, 0x00);
    memoryASet(ds, 0x8563, 0x00);
    memoryASet(ds, 0xa1b0, 0x00);
    memoryASet(ds, 0x8243, 0x00);
    memoryASet(ds, 0x79b7, 0x00);
    memoryASet16(ds, 0x9ba6, 0x0886);
    memoryASet16(ds, 0x9ba8, ds);
    bx = memoryAGet16(ds, 0x9ba6);
    es = memoryAGet16(ds, 0x9ba6 + 2);
    memoryASet(es, bx, 0xff);
    sub_67d6();
    sub_6779();
    ax = memoryAGet16(ds, 0x9292);
    ax += 0xfff4;
    memoryASet16(ds, 0x9292, ax);
    memoryASet(ds, 0x792c, 0x00);
    memoryASet16(ds, 0xa1ac, 0x1394);
    memoryASet16(ds, 0xa1ae, ds);
    memoryASet(ds, 0x824d, 0x0a);
    al = 0x04;
    memoryASet(ds, 0x9bae, al);
    memoryASet(ds, 0x792a, al);
    memoryASet(ds, 0xa1a9, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_515f() // 01ed:328f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_516b;
    sub_ca53();
loc_516b: // 01ed:329b
    memoryASet(ds, 0x8244, 0x00);
    goto loc_5175;
loc_5172: // 01ed:32a2
    sync();
    sub_3cae();
loc_5175: // 01ed:32a5
    al = memoryAGet(ds, 0x8244);
    ah = 0x00;
    if (!ax)
        goto loc_5172;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5180() // 01ed:32b0
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_518c;
    sub_ca53();
loc_518c: // 01ed:32bc
    ax = memoryAGet16(ds, 0x7310);
    dx = 0x00c2;
    imul(dx);
    dx = memoryAGet16(ds, 0x6bf4);
    bx = memoryAGet16(ds, 0x6bf2);
    bx += ax;
    memoryASet16(ds, 0x75d0, bx);
    memoryASet16(ds, 0x75d2, dx);
    ax = memoryAGet16(ds, 0x7310);
    dx = 0x032c;
    imul(dx);
    dx = memoryAGet16(ds, 0x6bd4);
    bx = memoryAGet16(ds, 0x6bd2);
    bx += ax;
    memoryASet16(ds, 0x6bca, bx);
    memoryASet16(ds, 0x6bcc, dx);
    memoryASet16(ds, 0xa0d8, 0xa0e4);
    memoryASet16(ds, 0xa0da, ds);
    cl = 0x00;
    goto loc_5222;
loc_51ce: // 01ed:32fe
    al = cl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    dl = cl;
    dh = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += dx;
    memoryASet(es, bx, al);
    al = cl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    dl = cl;
    dh = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += dx;
    memoryASet(es, bx + 48, al);
    al = cl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 96);
    dl = cl;
    dh = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += dx;
    memoryASet(es, bx + 96, al);
    cl++;
loc_5222: // 01ed:3352
    if (cl < 0x30)
        goto loc_51ce;
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 144);
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 144, al);
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 145);
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 145, al);
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 146);
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 146, al);
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 147);
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 147, al);
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 148);
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 148, al);
    bx = memoryAGet16(ds, 0x75d0);
    es = memoryAGet16(ds, 0x75d0 + 2);
    al = memoryAGet(es, bx + 149);
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    memoryASet(es, bx + 149, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5295() // 01ed:33c5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_52a1;
    sub_ca53();
loc_52a1: // 01ed:33d1
    memoryASet16(ds, 0x8884, 0x792e);
    memoryASet16(ds, 0x8886, ds);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ds, 0xa0c8);
    dx = memoryAGet16(ds, 0xa0c6);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) | 0x80);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xbf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xdf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xef);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xf7);
    memoryASet16(ds, 0x9b9e, 0x795a);
    memoryASet16(ds, 0x9ba0, ds);
    bx = memoryAGet16(ds, 0x9b9e);
    es = memoryAGet16(ds, 0x9b9e + 2);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) | 0x80);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xbf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xdf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xef);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xf7);
    memoryASet16(ds, 0xa0d0, 0x7986);
    memoryASet16(ds, 0xa0d2, ds);
    bx = memoryAGet16(ds, 0xa0d0);
    es = memoryAGet16(ds, 0xa0d0 + 2);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) | 0x80);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xbf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xdf);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xef);
    memoryASet(es, bx + 10, memoryAGet(es, bx + 10) & 0xf7);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5337() // 01ed:3467
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0068;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5347;
    sub_ca53();
loc_5347: // 01ed:3477
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet(es, bx + 34, 0x00);
    memoryASet(es, bx + 35, 0x00);
    memoryASet(es, bx + 36, 0x00);
    memoryASet(es, bx + 37, 0x00);
    memoryASet16(es, bx + 14, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet(ss, bp - 2, 0x14);
    memoryASet(ss, bp - 3, 0x19);
    memoryASet(ss, bp - 1, 0x00);
    goto loc_5436;
loc_537a: // 01ed:34aa
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    memoryASet16(es, bx + 22, ax);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    memoryASet16(es, bx + 30, ax);
    memoryASet16(es, bx + 32, 0x0001);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0018;
    dx -= ax;
    memoryASet16(es, bx + 22, dx);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    al = memoryAGet(ss, bp - 2);
    al += 0xfe;
    memoryASet(ss, bp - 2, al);
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    memoryASet16(es, bx + 22, ax);
    memoryASet16(es, bx + 30, 0x0001);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    memoryASet16(es, bx + 32, ax);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0013;
    dx -= ax;
    memoryASet16(es, bx + 20, dx);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    al = memoryAGet(ss, bp - 3);
    al += 0xfe;
    memoryASet(ss, bp - 3, al);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_5436: // 01ed:3566
    if (memoryAGet(ss, bp - 1) > 0x09)
        goto loc_543f;
    goto loc_537a;
loc_543f: // 01ed:356f
    si = 0;
    goto loc_5452;
loc_5443: // 01ed:3573
    bx = si;
    bx <<= 1;
    ax = bp - 0x68;
    bx += ax;
    memoryASet16(ss, bx, 0x0000);
    si++;
loc_5452: // 01ed:3582
    if (si < 0x0032)
        goto loc_5443;
    ax = 0;
    push(ax);
    push(ss);
    ax = bp - 0x68;
    push(ax);
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5475() // 01ed:35a5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5486;
    sub_ca53();
loc_5486: // 01ed:35b6
    memoryASet(ss, bp - 5, 0x00);
    memoryASet(ss, bp - 6, 0xff);
    push(ss);
    ax = bp - 0xa;
    push(ax);
    push(ds);
    ax = 0x11b2;
    push(ax);
    cx = 0x0003;
    sub_c8c5();
    ax = 0x0004;
    push(ax);
    ax = 0x0012;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x09e4));
    push(memoryAGet16(ds, 0x09e2));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_552d;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 11, 0x00);
    goto loc_5527;
loc_550a: // 01ed:363a
    al = memoryAGet(ss, bp - 11);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 11);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1610);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 11, memoryAGet(ss, bp - 11) + 1);
loc_5527: // 01ed:3657
    if (memoryAGet(ss, bp - 11) < 0x10)
        goto loc_550a;
loc_552d: // 01ed:365d
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ds, 0x6c2e);
    dx = memoryAGet16(ds, 0x6c2c);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    al = 0x00;
    memoryASet(ds, 0x854f, al);
    memoryASet(ds, 0x8244, al);
    sub_5337();
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    goto loc_56d9;
loc_55cf: // 01ed:36ff
    al = memoryAGet(ds, 0x79b5);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1888);
    dx = memoryAGet16(ds, bx + 1886);
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0006);
    memoryASet16(es, bx + 12, 0x0002);
    memoryASet16(es, bx + 20, 0x000b);
    memoryASet16(es, bx + 22, 0x0012);
    memoryASet16(es, bx + 30, 0x0006);
    memoryASet16(es, bx + 32, 0x0002);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    ax = 0;
    push(ax);
    sub_7051();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, 0x0000);
    memoryASet16(es, bx, 0x0030);
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0070;
    memoryASet16(es, bx + 2, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    sub_b734();
    sub_3cae();
    if (!(memoryAGet(ds, 0x8244) & 0x01))
        goto loc_5684;
    if (memoryAGet(ss, bp - 5) == 0x00)
        goto loc_5684;
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) - 1);
    goto loc_56c8;
loc_5684: // 01ed:37b4
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_5696;
    if (memoryAGet(ss, bp - 5) >= 0x03)
        goto loc_5696;
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
    goto loc_56c8;
loc_5696: // 01ed:37c6
    if (!(memoryAGet(ds, 0x8244) & 0x10))
        goto loc_56c8;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    bx = ax;
    if (bx > 0x0003)
        goto loc_56c8;
    bx <<= 1;
    // go to menu?
    assert(bx == 0);
    goto loc_56b0;
//    printf("indirect call: %04x:  %04x %04x %04x %04x\n", memory16(cs, 0+0x384a),
//           memory16(cs, 2+0x384a), memory16(cs, 4+0x384a), memory16(cs, 6+0x384a));
    
//    stop(/*2*/); // (jmp word ptr cs:[bx + 0x384a]) jump Indirect memoryAGet16(cs, bx + 14410)
loc_56b0: // 01ed:37e0
    al = memoryAGet(ss, bp - 5);
    memoryASet(ss, bp - 6, al);
    goto loc_56c8;
loc_56b8: // 01ed:37e8
    memoryASet(ds, 0x79b5, memoryAGet(ds, 0x79b5) + 1);
    if (memoryAGet(ds, 0x79b5) != 0x03)
        goto loc_56c8;
    memoryASet(ds, 0x79b5, 0x00);
loc_56c8: // 01ed:37f8
    memoryASet(ds, 0x8244, 0x00);
loc_56cd: // 01ed:37fd
    sync();
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    if (al)
        goto loc_56cd;
loc_56d9: // 01ed:3809
    if (memoryAGet(ss, bp - 6) != 0xff)
        goto loc_56e2;
    goto loc_55cf;
loc_56e2: // 01ed:3812
    al = memoryAGet(ds, 0x79b5);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    al = memoryAGet(ss, bx);
    memoryASet(ds, 0x854f, al);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ds, 0xa0c8);
    dx = memoryAGet16(ds, 0xa0c6);
    memoryASet16(es, bx + 6, dx);
    memoryASet16(es, bx + 8, ax);
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    al = memoryAGet(ss, bp - 6);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5722() // 01ed:3852
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5732;
    sub_ca53();
loc_5732: // 01ed:3862
    memoryASet(ss, bp - 5, 0x00);
    al = memoryAGet(ds, 0x854f);
    memoryASet(ds, 0x8e8a, al);
    memoryASet(ds, 0x854f, 0x00);
    memoryASet(ds, 0x8244, 0x00);
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = 0x0004;
    push(ax);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax += 0x0007;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    dx = 0x000a;
    imul(dx);
    bx = ax;
    push(memoryAGet16(ds, bx + 2422));
    push(memoryAGet16(ds, bx + 2420));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_580c;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    al = memoryAGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1768);
    dx = memoryAGet16(ds, bx + 1766);
    memoryASet16(ss, bp - 10, dx);
    memoryASet16(ss, bp - 8, ax);
    memoryASet(ss, bp - 6, 0x00);
    goto loc_5806;
loc_57e7: // 01ed:3917
    al = memoryAGet(ss, bp - 6);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 10);
    es = memoryAGet16(ss, bp - 10 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    dl = memoryAGet(ss, bp - 6);
    dh = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += dx;
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 6, memoryAGet(ss, bp - 6) + 1);
loc_5806: // 01ed:3936
    if (memoryAGet(ss, bp - 6) < 0x10)
        goto loc_57e7;
loc_580c: // 01ed:393c
    sub_5337();
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0x0008;
    push(ax);
    ax = 0x0001;
    push(ax);
    al = 0x07;
    push(ax);
    push(memoryAGet16(ds, 0xa0d6));
    push(memoryAGet16(ds, 0xa0d4));
    sub_26e6();
    sp += 0x000a;
    sub_8000();
    sub_5b1f();
    al = memoryAGet(ds, 0x79b6);
    memoryASet(ds, 0x854e, al);
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = memoryAGet16(ds, 0x791c);
    memoryASet16(ds, 0x9290, ax);
    ax = memoryAGet16(ds, 0x791e);
    memoryASet16(ds, 0x9292, ax);
    memoryASet16(ds, 0x824a, 0x0021);
    ax = 0;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_7051();
    sp += 0x0004;
    sub_3b82();
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_b734();
    sub_3343();
    sub_325c();
    sub_3aa7();
    sub_325c();
    sub_5958();
    goto loc_5944;
loc_58ec: // 01ed:3a1c
    sync();
    sub_3cae();
    if (!(memoryAGet(ds, 0x8244) & 0x01))
        goto loc_58fb;
    sub_5982();
    goto loc_593f;
loc_58fb: // 01ed:3a2b
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_5907;
    sub_59df();
    goto loc_593f;
loc_5907: // 01ed:3a37
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_5913;
    sub_5a3c();
    goto loc_593f;
loc_5913: // 01ed:3a43
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_591f;
    sub_5a99();
    goto loc_593f;
loc_591f: // 01ed:3a4f
    if (!(memoryAGet(ds, 0x8244) & 0x10))
        goto loc_592b;
    sub_5bc7();
    goto loc_593c;
loc_592b: // 01ed:3a5b
    al = 0x01;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_593f;
    al = 0xff;
    memoryASet(ds, 0x928d, al);
loc_593c: // 01ed:3a6c
    memoryASet(ss, bp - 5, al);
loc_593f: // 01ed:3a6f
    memoryASet(ds, 0x8244, 0x00);
loc_5944: // 01ed:3a74
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    if (!ax)
        goto loc_58ec;
    al = memoryAGet(ds, 0x8e8a);
    memoryASet(ds, 0x854f, al);
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5958() // 01ed:3a88
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5964;
    sub_ca53();
loc_5964: // 01ed:3a94
    al = memoryAGet(ds, 0x854e);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    dx = memoryAGet16(ds, 0x8248);
    bx = memoryAGet16(ds, 0x8246);
    bx += ax;
    memoryASet16(ds, 0x9baa, bx);
    memoryASet16(ds, 0x9bac, dx);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5982() // 01ed:3ab2
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5991;
    sub_ca53();
loc_5991: // 01ed:3ac1
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 1);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_59db;
    memoryASet(ds, 0x854e, al);
    sub_5958();
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 2);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet(ss, bp - 1, al);
    goto loc_59d5;
loc_59c6: // 01ed:3af6
    ax = memoryAGet16(ds, 0x9292);
    ax += 0xfffc;
    memoryASet16(ds, 0x9292, ax);
    sub_5af6();
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_59d5: // 01ed:3b05
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_59c6;
loc_59db: // 01ed:3b0b
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_59df() // 01ed:3b0f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_59ee;
    sub_ca53();
loc_59ee: // 01ed:3b1e
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 3);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_5a38;
    memoryASet(ds, 0x854e, al);
    sub_5958();
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 4);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet(ss, bp - 1, al);
    goto loc_5a32;
loc_5a23: // 01ed:3b53
    ax = memoryAGet16(ds, 0x9292);
    ax += 0x0004;
    memoryASet16(ds, 0x9292, ax);
    sub_5af6();
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_5a32: // 01ed:3b62
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_5a23;
loc_5a38: // 01ed:3b68
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5a3c() // 01ed:3b6c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5a4b;
    sub_ca53();
loc_5a4b: // 01ed:3b7b
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 5);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_5a95;
    memoryASet(ds, 0x854e, al);
    sub_5958();
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 6);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet(ss, bp - 1, al);
    goto loc_5a8f;
loc_5a80: // 01ed:3bb0
    ax = memoryAGet16(ds, 0x9290);
    ax += 0xfffc;
    memoryASet16(ds, 0x9290, ax);
    sub_5af6();
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_5a8f: // 01ed:3bbf
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_5a80;
loc_5a95: // 01ed:3bc5
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5a99() // 01ed:3bc9
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5aa8;
    sub_ca53();
loc_5aa8: // 01ed:3bd8
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 7);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_5af2;
    memoryASet(ds, 0x854e, al);
    sub_5958();
    bx = memoryAGet16(ss, bp - 6);
    es = memoryAGet16(ss, bp - 6 + 2);
    al = memoryAGet(es, bx + 8);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet(ss, bp - 1, al);
    goto loc_5aec;
loc_5add: // 01ed:3c0d
    ax = memoryAGet16(ds, 0x9290);
    ax += 0x0004;
    memoryASet16(ds, 0x9290, ax);
    sub_5af6();
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_5aec: // 01ed:3c1c
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_5add;
loc_5af2: // 01ed:3c22
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5af6() // 01ed:3c26
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5b02;
    sub_ca53();
loc_5b02: // 01ed:3c32
    sub_325c();
    sub_3343();
    sub_38b4();
    sub_3aa7();
    sub_3b82();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5b1f() // 01ed:3c4f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5b2d;
    sub_ca53();
loc_5b2d: // 01ed:3c5d
    memoryASet(ss, bp - 1, 0x00);
    al = memoryAGet(ds, 0x854e);
    memoryASet(ds, 0x79b6, al);
    memoryASet(ds, 0x854e, 0x01);
loc_5b3c: // 01ed:3c6c
    sub_5958();
    bx = memoryAGet16(ds, 0x9baa);
    es = memoryAGet16(ds, 0x9baa + 2);
    if (memoryAGet(es, bx) != 0xff)
        goto loc_5b4f;
    memoryASet(ss, bp - 1, 0x01);
    goto loc_5b5c;
loc_5b4f: // 01ed:3c7f
    bx = memoryAGet16(ds, 0x9baa);
    es = memoryAGet16(ds, 0x9baa + 2);
    if (memoryAGet(es, bx) == 0x00)
        goto loc_5b5c;
    sub_5b6d();
loc_5b5c: // 01ed:3c8c
    memoryASet(ds, 0x854e, memoryAGet(ds, 0x854e) + 1);
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_5b3c;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5b6d() // 01ed:3c9d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5b79;
    sub_ca53();
loc_5b79: // 01ed:3ca9
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, 0x01da);
    al = memoryAGet(ds, 0x854e);
    ah = 0x00;
    ax--;
    ax <<= 1;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x8554);
    es = memoryAGet16(ds, 0x8554 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    ax--;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx, ax);
    al = memoryAGet(ds, 0x854e);
    ah = 0x00;
    ax--;
    ax <<= 1;
    ax++;
    ax <<= 1;
    bx = memoryAGet16(ds, 0x8554);
    es = memoryAGet16(ds, 0x8554 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5bc7() // 01ed:3cf7
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5bd6;
    sub_ca53();
loc_5bd6: // 01ed:3d06
    memoryASet(ss, bp - 5, 0x00);
    memoryASet(ds, 0x792c, 0x00);
    sub_5af6();
    sub_5af6();
    sub_5958();
    ax = memoryAGet16(ds, 0x9bac);
    dx = memoryAGet16(ds, 0x9baa);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, bx);
    ah = 0x00;
    if (!ax)
        goto loc_5c04;
    goto loc_5cc6;
loc_5c04: // 01ed:3d34
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_5c0f;
    al = 0x03;
    goto loc_5c11;
loc_5c0f: // 01ed:3d3f
    al = 0x28;
loc_5c11: // 01ed:3d41
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    memoryASet(ds, 0x854f, 0xaa);
    ax = memoryAGet16(ds, 0x9292);
    memoryASet16(ds, 0x791e, ax);
    ax = memoryAGet16(ds, 0x9290);
    memoryASet16(ds, 0x791c, ax);
    memoryASet16(ds, 0xa1ac, 0x1114);
    memoryASet16(ds, 0xa1ae, ds);
    memoryASet(ds, 0x824d, 0x16);
    ax = memoryAGet16(ds, 0x9290);
    ax += 0xfff1;
    memoryASet16(ds, 0x9290, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax += 0x0003;
    memoryASet16(ds, 0x9292, ax);
    memoryASet16(ds, 0x824a, 0x00cb);
    sub_38b4();
    sub_3b82();
    sub_3aa7();
    ax = memoryAGet16(ds, 0x9290);
    ax += 0x000f;
    memoryASet16(ds, 0x9290, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax += 0xfffd;
    memoryASet16(ds, 0x9292, ax);
    memoryASet16(ds, 0x824a, 0x0000);
    sub_325c();
    sub_5ccd();
    sub_3b82();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
    sub_38b4();
    sub_3aa7();
    sub_3b82();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
loc_5c9a: // 01ed:3dca
    sub_325c();
    sub_32af();
    sub_3343();
    sub_38b4();
    sub_3aa7();
    sub_3b82();
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_3219();
    if (memoryAGet(ds, 0x824d) != 0x00)
        goto loc_5c9a;
    sub_5d44();
    memoryASet(ss, bp - 5, 0x01);
loc_5cc6: // 01ed:3df6
    al = memoryAGet(ss, bp - 5);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5ccd() // 01ed:3dfd
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5cdb;
    sub_ca53();
loc_5cdb: // 01ed:3e0b
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    di = memoryAGet16(es, bx + 20);
    si = memoryAGet16(es, bx + 22);
    ax = memoryAGet16(ds, 0x9290);
    ax -= di;
    ax += 0x000e;
    cl = 0x04;
    ax = sar(ax, cl);
    ax--;
    memoryASet16(ds, 0x9d36, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax -= si;
    ax += 0xfff6;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet16(ds, 0x9d38, ax);
    if ((short)memoryAGet16(ds, 0x9d36) >= (short)0x0000)
        goto loc_5d17;
    memoryASet16(ds, 0x9d36, 0x0000);
    goto loc_5d24;
loc_5d17: // 01ed:3e47
    if ((short)memoryAGet16(ds, 0x9d36) <= (short)0x0012)
        goto loc_5d24;
    memoryASet16(ds, 0x9d36, 0x0012);
loc_5d24: // 01ed:3e54
    if ((short)memoryAGet16(ds, 0x9d38) >= (short)0x0000)
        goto loc_5d33;
    memoryASet16(ds, 0x9d38, 0x0000);
    goto loc_5d40;
loc_5d33: // 01ed:3e63
    if ((short)memoryAGet16(ds, 0x9d38) <= (short)0x0016)
        goto loc_5d40;
    memoryASet16(ds, 0x9d38, 0x0016);
loc_5d40: // 01ed:3e70
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5d44() // 01ed:3e74
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5d50;
    sub_ca53();
loc_5d50: // 01ed:3e80
    al = 0x32;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5d5a() // 01ed:3e8a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5d68;
    sub_ca53();
loc_5d68: // 01ed:3e98
    al = 0x01;
    cl = al;
    memoryASet(ss, bp - 1, al);
    goto loc_5d88;
loc_5d71: // 01ed:3ea1
    al = cl;
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryAGet16(ds, 0x8246);
    es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) & al);
    cl++;
loc_5d88: // 01ed:3eb8
    al = cl;
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryAGet16(ds, 0x8246);
    es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    if (memoryAGet(es, bx) != 0xff)
        goto loc_5d71;
    al = memoryAGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5da4() // 01ed:3ed4
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5db5;
    sub_ca53();
loc_5db5: // 01ed:3ee5
    sub_7551();
    ax = 0x0004;
    push(ax);
    ax = 0x0011;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x09da));
    push(memoryAGet16(ds, 0x09d8));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_5e47;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 5, 0x00);
    goto loc_5e41;
loc_5e24: // 01ed:3f54
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1838);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_5e41: // 01ed:3f71
    if (memoryAGet(ss, bp - 5) < 0x10)
        goto loc_5e24;
loc_5e47: // 01ed:3f77
    sub_5337();
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x7928));
    push(memoryAGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_b734();
    memoryASet(ds, 0x8244, 0x00);
    sub_515f();
    al = 0x01;
    memoryASet(ds, 0x79b2, al);
    memoryASet(ds, 0x928d, al);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5ee5() // 01ed:4015
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0036;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_5ef6;
    sub_ca53();
loc_5ef6: // 01ed:4026
    memoryASet(ss, bp - 5, 0x00);
    push(ss);
    ax = bp - 0x26;
    push(ax);
    push(ds);
    ax = 0x11b6;
    push(ax);
    cx = 0x0020;
    sub_c8c5();
    push(ss);
    ax = bp - 0x36;
    push(ax);
    push(ds);
    ax = 0x11d6;
    push(ax);
    cx = 0x0010;
    sub_c8c5();
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
    push(ds);
    ax = 0x0090;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    push(memoryAGet16(ds, 0x119c));
    sub_b274();
    sp++;
    sp++;
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    sub_923f();
    sp += 0x0004;
    di = ax;
    ax = 0;
    push(ax);
    dx = 0x0063;
    push(ax);
    push(dx);
    push(memoryAGet16(ds, 0x6bea));
    push(memoryAGet16(ds, 0x6be8));
    push(di);
    sub_932e();
    sp += 0x000c;
    push(di);
    sub_91e9();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_5fad;
    ax = memoryAGet16(ds, 0x6bea);
    dx = memoryAGet16(ds, 0x6be8);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 1, 0x00);
    goto loc_5fa7;
loc_5f86: // 01ed:40b6
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    push(es);
    push(bx);
    bx = ax;
    al = memoryAGet(ds, bx + 1626);
    bx = pop();
    es = pop();
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_5fa7: // 01ed:40d7
    if (memoryAGet(ss, bp - 1) < 0x10)
        goto loc_5f86;
loc_5fad: // 01ed:40dd
    memoryASet(ss, bp - 1, 0x00);
    goto loc_5fd3;
loc_5fb3: // 01ed:40e3
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 1854);
    dl = memoryAGet(ss, bp - 1);
    dh = 0x00;
    dx <<= 1;
    bx = memoryAGet16(ds, 0x6bca);
    es = memoryAGet16(ds, 0x6bca + 2);
    bx += dx;
    memoryASet16(es, bx, ax);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_5fd3: // 01ed:4103
    if (memoryAGet(ss, bp - 1) < 0x10)
        goto loc_5fb3;
    sub_250b();
    memoryASet(ss, bp - 5, 0x00);
    goto loc_6112;
loc_5fe3: // 01ed:4113
    sub_b281();
    ax &= 0x000f;
    si = ax;
    if ((short)ax < (short)0x0002)
        goto loc_5fe3;
    al = memoryAGet(ss, bp + si + 65482);
    memoryASet(ss, bp - 4, al);
    al = 0x00;
    memoryASet(ss, bp - 3, al);
    memoryASet(ss, bp - 2, al);
    memoryASet(ds, 0x119a, 0x01);
    sub_5337();
    push(ds);
    ax = 0x0578;
    push(ax);
    sub_27a1();
    sp += 0x0004;
    bx = si;
    bx <<= 1;
    ax = bp - 0x26;
    bx += ax;
    ax = memoryAGet16(ss, bx);
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx, 0x0090);
    memoryASet16(es, bx + 2, 0x0064);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    ax = 0x0087;
    push(ax);
    ax = 0x0054;
    push(ax);
    push(ds);
    ax = 0x1331;
    push(ax);
    sub_26c0();
    sp += 0x0008;
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    al = 0x02;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    sub_26e6();
    sp += 0x000a;
    goto loc_60e0;
loc_6069: // 01ed:4199
    memoryASet(ds, 0x8244, 0x00);
    sub_3cae();
    if (!(memoryAGet(ds, 0x8244) & 0x10))
        goto loc_607e;
    memoryASet(ss, bp - 3, 0x01);
    goto loc_60bf;
loc_607e: // 01ed:41ae
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_609c;
    if (memoryAGet(ss, bp - 2) == 0x00)
        goto loc_609c;
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) - 1);
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    push(ds);
    ax = 0x134b;
    goto loc_60b8;
loc_609c: // 01ed:41cc
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_60bf;
    if (memoryAGet(ss, bp - 2) >= 0x63)
        goto loc_60bf;
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    push(ds);
    ax = 0x1350;
loc_60b8: // 01ed:41e8
    push(ax);
    sub_26c0();
    sp += 0x0008;
loc_60bf: // 01ed:41ef
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    al = 0x02;
    push(ax);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    sub_26e6();
    sp += 0x000a;
    al = 0x04;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
loc_60e0: // 01ed:4210
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    if (!ax)
        goto loc_6069;
    al = memoryAGet(ss, bp - 2);
    memoryASet(ss, bp - 4, al);
    goto loc_610e;
    //   gap of 29 bytes
loc_610e: // 01ed:423e
    memoryASet(ss, bp - 5, 0xff);
loc_6112: // 01ed:4242
    if (memoryAGet(ss, bp - 5) >= 0x03)
        goto loc_611b;
    goto loc_5fe3;
loc_611b: // 01ed:424b
    ax = 0x0001;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6133() // 01ed:4263
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6142;
    sub_ca53();
loc_6142: // 01ed:4272
    memoryASet(ds, 0x8244, 0x00);
    al = memoryAGet(ds, 0x8242);
    ah = 0x00;
    if (ax)
        goto loc_61a5;
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0x792c, al);
    if (memoryAGet(ds, 0x792c) == 0x05)
        goto loc_61a5;
    if (memoryAGet(ds, 0x792c) == 0x0b)
        goto loc_61a5;
    if (memoryAGet(ds, 0x792c) == 0x1c)
        goto loc_61a5;
    memoryASet(ds, 0xa0dc, 0x00);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 8788);
    dx = memoryAGet16(ds, bx + 8786);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x824d, al);
    al = memoryAGet(es, bx + 1);
    memoryASet(ds, 0x9bae, al);
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0xa1ac, dx);
    memoryASet16(ds, 0xa1ae, ax);
loc_61a5: // 01ed:42d5
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_61a9() // 01ed:42d9
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_61b5;
    sub_ca53();
loc_61b5: // 01ed:42e5
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_61c0;
    al = 0x03;
    goto loc_61c2;
loc_61c0: // 01ed:42f0
    al = 0x0d;
loc_61c2: // 01ed:42f2
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x2d;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_61d5() // 01ed:4305
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_61e1;
    sub_ca53();
loc_61e1: // 01ed:4311
    memoryASet(ds, 0x792c, 0x1c);
    sub_6231();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6231() // 01ed:4361
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6240;
    sub_ca53();
loc_6240: // 01ed:4370
    memoryASet(ss, bp - 1, 0x15);
    memoryASet(ss, bp - 2, 0x04);
    memoryASet16(ss, bp - 6, 0x1b70);
    memoryASet16(ss, bp - 4, ds);
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_650d() // 01ed:463d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6519;
    sub_ca53();
loc_6519: // 01ed:4649
    memoryASet(ds, 0x8242, memoryAGet(ds, 0x8242) + 1);
    if (memoryAGet(ds, 0x8242) != 0x03)
        goto loc_652c;
    memoryASet(ds, 0x8242, 0x00);
    sub_4835();
loc_652c: // 01ed:465c
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_652e() // 01ed:465e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_653a;
    sub_ca53();
loc_653a: // 01ed:466a
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14014);
    push(ax);
    sub_658b();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_654d() // 01ed:467d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6559;
    sub_ca53();
loc_6559: // 01ed:4689
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14062);
    push(ax);
    sub_658b();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_656c() // 01ed:469c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6578;
    sub_ca53();
loc_6578: // 01ed:46a8
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14110);
    push(ax);
    sub_658b();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_658b() // 01ed:46bb
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6597;
    sub_ca53();
loc_6597: // 01ed:46c7
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    if (ax == 0x0008)
        goto loc_65d6;
    if ((short)ax > (short)0x0008)
        goto loc_65b1;
    bx = ax;
    if (bx > 0x0003)
        goto loc_65ea;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_65c2; //loc 01ed:46f2 01ed:46f7 01ed:46fc 01ed:4701
        case 2: goto loc_65c7;
        case 4: goto loc_65cc;
        case 6: goto loc_65d1;
        default:
            assert(0);
    }
//    printf("indirect jump bx=%02x, %04x:%04x\n", bx, cs, memory16(cs, bx+0x4725));
//    printf("%04x:%04x %04x:%04x %04x:%04x %04x:%04x\n",
//           cs, memory16(cs, 0+0x4725),
//           cs, memory16(cs, 2+0x4725),
//           cs, memory16(cs, 4+0x4725),
//           cs, memory16(cs, 6+0x4725));
    
    stop(/*2*/); // (jmp word ptr cs:[bx + 0x4725]) jump Indirect memoryAGet16(cs, bx + 18213)
loc_65b1: // 01ed:46e1
    if (ax == 0x0009)
        goto loc_65db;
    if (ax == 0x001a)
        goto loc_65e0;
    if (ax == 0x001b)
        goto loc_65e5;
    goto loc_65ea;
loc_65c2: // 01ed:46f2
    sub_6617();
    goto loc_65f3;
loc_65c7: // 01ed:46f7
    sub_4504();
    goto loc_65f3;
loc_65cc: // 01ed:46fc
    sub_4571();
    goto loc_65f3;
loc_65d1: // 01ed:4701
    sub_46ae();
    goto loc_65f3;
loc_65d6: // 01ed:4706
    sub_45dc();
    goto loc_65f3;
loc_65db: // 01ed:470b
    sub_4646();
    goto loc_65f3;
loc_65e0: // 01ed:4710
    sub_3e8e();
    goto loc_65f3;
loc_65e5: // 01ed:4715
    sub_3f4d();
    goto loc_65f3;
loc_65ea: // 01ed:471a
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_65fd();
    sp++;
    sp++;
loc_65f3: // 01ed:4723
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_65fd() // 01ed:472d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6609;
    sub_ca53();
loc_6609: // 01ed:4739
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6617() // 01ed:4747
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6625;
    sub_ca53();
loc_6625: // 01ed:4755
    if (memoryAGet(ds, 0x856e) >= 0x08)
        goto loc_6632;
    memoryASet(ss, bp - 2, 0x00);
    goto loc_6653;
loc_6632: // 01ed:4762
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    al = memoryAGet(es, bx + 65528);
    memoryASet(ss, bp - 1, al);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14158);
    memoryASet(ss, bp - 2, al);
loc_6653: // 01ed:4783
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    if (ax)
        goto loc_668e;
    if (memoryAGet(ds, 0x79b3) <= 0xeb)
        goto loc_6669;
    memoryASet(ss, bp - 2, 0x3c);
    goto loc_668e;
loc_6669: // 01ed:4799
    if (memoryAGet(ds, 0x79b3) <= 0xd7)
        goto loc_6676;
    memoryASet(ss, bp - 2, 0x3d);
    goto loc_668e;
loc_6676: // 01ed:47a6
    if (memoryAGet(ds, 0x79b3) <= 0xc3)
        goto loc_6683;
    memoryASet(ss, bp - 2, 0x3e);
    goto loc_668e;
loc_6683: // 01ed:47b3
    if (memoryAGet(ds, 0x79b3) <= 0xaf)
        goto loc_668e;
    memoryASet(ss, bp - 2, 0x3f);
loc_668e: // 01ed:47be
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_65fd();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_669b() // 01ed:47cb
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_66a7;
    sub_ca53();
loc_66a7: // 01ed:47d7
    if (!(memoryAGet(ds, 0x8244) & 0x04))
        goto loc_66b3;
    sub_4504();
    goto loc_66d0;
loc_66b3: // 01ed:47e3
    if (!(memoryAGet(ds, 0x8244) & 0x08))
        goto loc_66bf;
    sub_4571();
    goto loc_66d0;
loc_66bf: // 01ed:47ef
    al = memoryAGet(ds, 0x792c);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 14206);
    push(ax);
    sub_658b();
    sp++;
    sp++;
loc_66d0: // 01ed:4800
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_66d2() // 01ed:4802
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_66de;
    sub_ca53();
loc_66de: // 01ed:480e
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_66e9;
    al = 0x03;
    goto loc_66eb;
loc_66e9: // 01ed:4819
    al = 0x28;
loc_66eb: // 01ed:481b
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    al = 0x27;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    al = 0x0e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_670c() // 01ed:483c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6718;
    sub_ca53();
loc_6718: // 01ed:4848
    sub_48da();
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(es, bx + 16, dx);
    memoryASet16(es, bx + 18, ax);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0014);
    memoryASet16(es, bx + 26, 0x0019);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_b288();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6779() // 01ed:48a9
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6785;
    sub_ca53();
loc_6785: // 01ed:48b5
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_67d4;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet(ds, 0x8565, al);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    dl = memoryAGet(ds, 0x8571);
    dl -= al;
    memoryASet(ds, 0x8564, dl);
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 628);
    ax += 0x0007;
    memoryASet16(ds, 0x79ba, ax);
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 630);
    ax += 0x0007;
    memoryASet16(ds, 0x79bc, ax);
loc_67d4: // 01ed:4904
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_67d6() // 01ed:4906
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_67e2;
    sub_ca53();
loc_67e2: // 01ed:4912
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet(ds, 0x855c, al);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    dl = memoryAGet(ds, 0x856e);
    dl -= al;
    memoryASet(ds, 0x855e, dl);
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 628);
    ax += 0x0007;
    memoryASet16(ds, 0x9290, ax);
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 630);
    ax += 0x000f;
    memoryASet16(ds, 0x9292, ax);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_682c() // 01ed:495c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6838;
    sub_ca53();
loc_6838: // 01ed:4968
    memoryASet(ds, 0x855d, memoryAGet(ds, 0x855d) + 1);
    al = memoryAGet(ds, 0x855d);
    if (al != memoryAGet(ss, bp + 6))
        goto loc_6856;
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_6865();
    sp += 0x0006;
    goto loc_6863;
loc_6856: // 01ed:4986
    al = memoryAGet(ds, 0x855d);
    if (al <= memoryAGet(ss, bp + 6))
        goto loc_6863;
    memoryASet(ds, 0x855d, 0x00);
loc_6863: // 01ed:4993
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6865() // 01ed:4995
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6871;
    sub_ca53();
loc_6871: // 01ed:49a1
    memoryASet(ds, 0x855d, 0x00);
    al = memoryAGet(ds, 0xa0dc);
    ah = 0x00;
    ax++;
    dl = memoryAGet(ss, bp + 4);
    dh = 0x00;
    if ((short)ax >= (short)dx)
        goto loc_688e;
    memoryASet(ds, 0xa0dc, memoryAGet(ds, 0xa0dc) + 1);
    al = memoryAGet(ds, 0xa0dc);
    goto loc_6893;
loc_688e: // 01ed:49be
    al = 0x00;
    memoryASet(ds, 0xa0dc, al);
loc_6893: // 01ed:49c3
    al = memoryAGet(ds, 0xa0dc);
    ah = 0x00;
    ax <<= 1;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    bx += ax;
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x824a, ax);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_68a7() // 01ed:49d7
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_68b5;
    sub_ca53();
loc_68b5: // 01ed:49e5
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx, 0x0000);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 16, 0x9694);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0014);
    memoryASet16(es, bx + 26, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0001);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_b288();
    sp += 0x0004;
    ax = 0;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = 0x0007;
    push(ax);
    ax = 0;
    push(ax);
    al = 0x07;
    push(ax);
    push(memoryAGet16(ds, 0xa0d6));
    push(memoryAGet16(ds, 0xa0d4));
    sub_26e6();
    sp += 0x000a;
    sub_8000();
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_b6e4();
    sp++;
    sp++;
loc_6949: // 01ed:4a79
    al = 0x19;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (al)
        goto loc_6949;
    goto loc_69a2;
loc_6957: // 01ed:4a87
    al = 0x1d;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_69a2;
    al = 0x21;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_69a2;
    memoryASet(ss, bp - 1, 0x01);
    goto loc_698c;
loc_6975: // 01ed:4aa5
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryAGet16(ds, 0x8246);
    es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    memoryASet(es, bx, 0x01);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_698c: // 01ed:4abc
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryAGet16(ds, 0x8246);
    es = memoryAGet16(ds, 0x8246 + 2);
    bx += ax;
    if (memoryAGet(es, bx) != 0xff)
        goto loc_6975;
loc_69a2: // 01ed:4ad2
    al = 0x19;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    cbw();
    if (ax)
        goto loc_69bc;
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    cbw();
    if (!ax)
        goto loc_6957;
loc_69bc: // 01ed:4aec
    al = 0x19;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (al)
        goto loc_69bc;
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    if (al)
        goto loc_69bc;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, 0x9694);
    memoryASet16(es, bx + 4, ds);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0001);
    memoryASet16(es, bx + 14, 0x0000);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6a1e() // 01ed:4b4e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6a2c;
    sub_ca53();
loc_6a2c: // 01ed:4b5c
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_6a92;
    bx = memoryAGet16(ds, 0x9b9e);
    es = memoryAGet16(ds, 0x9b9e + 2);
    di = memoryAGet16(es, bx + 20);
    si = memoryAGet16(es, bx + 22);
    ax = memoryAGet16(ds, 0x79ba);
    ax -= di;
    cl = 0x04;
    ax = sar(ax, cl);
    ax--;
    memoryASet16(ds, 0xa0ca, ax);
    ax = memoryAGet16(ds, 0x79bc);
    ax -= si;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet16(ds, 0xa0cc, ax);
    if ((short)memoryAGet16(ds, 0xa0ca) >= (short)0x0000)
        goto loc_6a69;
    memoryASet16(ds, 0xa0ca, 0x0000);
    goto loc_6a76;
loc_6a69: // 01ed:4b99
    if ((short)memoryAGet16(ds, 0xa0ca) <= (short)0x0012)
        goto loc_6a76;
    memoryASet16(ds, 0xa0ca, 0x0012);
loc_6a76: // 01ed:4ba6
    if ((short)memoryAGet16(ds, 0xa0cc) >= (short)0x0000)
        goto loc_6a85;
    memoryASet16(ds, 0xa0cc, 0x0000);
    goto loc_6a92;
loc_6a85: // 01ed:4bb5
    if ((short)memoryAGet16(ds, 0xa0cc) <= (short)0x0016)
        goto loc_6a92;
    memoryASet16(ds, 0xa0cc, 0x0016);
loc_6a92: // 01ed:4bc2
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6a96() // 01ed:4bc6
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6aa5;
    sub_ca53();
loc_6aa5: // 01ed:4bd5
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0x8562, al);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 9506);
    dx = memoryAGet16(ds, bx + 9504);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0xa1b0, al);
    al = memoryAGet(es, bx + 1);
    memoryASet(ds, 0x9d2f, al);
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0xa0ba, dx);
    memoryASet16(ds, 0xa0bc, ax);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6ae4() // 01ed:4c14
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6af0;
    sub_ca53();
loc_6af0: // 01ed:4c20
    al = memoryAGet(ds, 0x8243);
    al ^= 0x01;
    memoryASet(ds, 0x8243, al);
    if (memoryAGet(ds, 0x8243) == 0x00)
        goto loc_6b67;
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_6b67;
    bx = memoryAGet16(ds, 0xa0ba);
    es = memoryAGet16(ds, 0xa0ba + 2);
    ax = memoryAGet16(es, bx);
    memoryASet16(ds, 0x8560, ax);
    if (memoryAGet(ds, 0x9d2f) == 0x00)
        goto loc_6b2b;
    ax = memoryAGet16(es, bx + 2);
    ax = -ax;
    dx = memoryAGet16(ds, 0x79ba);
    dx += ax;
    memoryASet16(ds, 0x79ba, dx);
    ax = dx;
    goto loc_6b3a;
loc_6b2b: // 01ed:4c5b
    bx = memoryAGet16(ds, 0xa0ba);
    es = memoryAGet16(ds, 0xa0ba + 2);
    ax = memoryAGet16(es, bx + 2);
    memoryASet16(ds, 0x79ba, memoryAGet16(ds, 0x79ba) + ax);
    ax = memoryAGet16(ds, 0x79ba);
loc_6b3a: // 01ed:4c6a
    bx = memoryAGet16(ds, 0xa0ba);
    es = memoryAGet16(ds, 0xa0ba + 2);
    ax = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x79bc, memoryAGet16(ds, 0x79bc) + ax);
    memoryASet16(ds, 0xa0ba, memoryAGet16(ds, 0xa0ba) + 0x0006);
    al = memoryAGet(ds, 0xa1b0);
    al += 0xff;
    memoryASet(ds, 0xa1b0, al);
    ah = 0x00;
    if (ax)
        goto loc_6b60;
    al = 0x00;
    memoryASet(ds, 0x8563, al);
    goto loc_6b67;
loc_6b60: // 01ed:4c90
    memoryASet(ds, 0x8563, memoryAGet(ds, 0x8563) + 1);
    al = memoryAGet(ds, 0x8563);
loc_6b67: // 01ed:4c97
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6b69() // 01ed:4c99
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6b75;
    sub_ca53();
loc_6b75: // 01ed:4ca5
    if (memoryAGet(ds, 0x8243) != 0x00)
        goto loc_6b7f;
    goto loc_6c8d;
loc_6b7f: // 01ed:4caf
    if (memoryAGet(ds, 0x8571) != 0xff)
        goto loc_6b89;
    goto loc_6c8d;
loc_6b89: // 01ed:4cb9
    if (memoryAGet(ds, 0xa1b0) == 0x00)
        goto loc_6b96;
    sub_6ed3();
    goto loc_6c8d;
loc_6b96: // 01ed:4cc6
    al = 0x01;
    memoryASet(ds, 0xa1b2, al);
    memoryASet(ds, 0xa0e2, al);
    memoryASet(ds, 0xa0e1, al);
    memoryASet(ds, 0xa0e0, al);
    if (memoryAGet(ds, 0x8571) < 0x08)
        goto loc_6bc9;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    es = memoryAGet16(ds, 0xa0da);
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    al = memoryAGet(es, bx + 65528);
    ah = 0x00;
    if (ax)
        goto loc_6bc9;
    memoryASet(ds, 0xa0e0, 0x00);
loc_6bc9: // 01ed:4cf9
    if (memoryAGet(ds, 0x8571) >= 0x28)
        goto loc_6be9;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    if (ax)
        goto loc_6be9;
    memoryASet(ds, 0xa0e1, 0x00);
loc_6be9: // 01ed:4d19
    if (memoryAGet(ds, 0x8564) == 0x00)
        goto loc_6c21;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 47);
    ah = 0x00;
    if (ax)
        goto loc_6c21;
    memoryASet(ds, 0xa0e2, 0x00);
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryAGet(es, bx + 65535) != 0x0b)
        goto loc_6c21;
    memoryASet(ds, 0xa0e2, 0x01);
loc_6c21: // 01ed:4d51
    if (memoryAGet(ds, 0x8564) == 0x07)
        goto loc_6c59;
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    ah = 0x00;
    if (ax)
        goto loc_6c59;
    memoryASet(ds, 0xa1b2, 0x00);
    al = memoryAGet(ds, 0x8571);
    ah = 0x00;
    ax += memoryAGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryAGet(es, bx + 1) != 0x0b)
        goto loc_6c59;
    memoryASet(ds, 0xa1b2, 0x01);
loc_6c59: // 01ed:4d89
    al = memoryAGet(ds, 0xa0e0);
    ah = 0x00;
    dl = memoryAGet(ds, 0xa0e1);
    dh = 0x00;
    ax += dx;
    dl = memoryAGet(ds, 0xa0e2);
    dh = 0x00;
    ax += dx;
    dl = memoryAGet(ds, 0xa1b2);
    dh = 0x00;
    ax += dx;
    if (ax != 0x0004)
        goto loc_6c80;
    sub_6ea3();
    goto loc_6c8d;
loc_6c80: // 01ed:4db0
    al = memoryAGet(ds, 0x8562);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    callIndirect(cs*16+memoryAGet16(ds, bx + 2160));
loc_6c8d: // 01ed:4dbd
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6c8f() // 01ed:4dbf
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6c9b;
    sub_ca53();
loc_6c9b: // 01ed:4dcb
    al = memoryAGet(ds, 0xa0e0);
    ah = 0x00;
    if (ax)
        goto loc_6ca9;
    sub_6cca();
    goto loc_6cc8;
loc_6ca9: // 01ed:4dd9
    al = memoryAGet(ds, 0xa1b2);
    ah = 0x00;
    if (ax)
        goto loc_6cb7;
    sub_6e59();
    goto loc_6cc8;
loc_6cb7: // 01ed:4de7
    al = memoryAGet(ds, 0xa0e2);
    ah = 0x00;
    if (ax)
        goto loc_6cc5;
    sub_6dd4();
    goto loc_6cc8;
loc_6cc5: // 01ed:4df5
    sub_6d4f();
loc_6cc8: // 01ed:4df8
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6cca() // 01ed:4dfa
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6cd6;
    sub_ca53();
loc_6cd6: // 01ed:4e06
    al = memoryAGet(ds, 0x79b3);
    if (al < memoryAGet(ds, 0x7920))
        goto loc_6ce3;
    al = 0x01;
    goto loc_6d0c;
loc_6ce3: // 01ed:4e13
    if (!(memoryAGet(ds, 0x79b3) & 0x01))
        goto loc_6cff;
    if (memoryAGet(ds, 0xa0e2) == 0x00)
        goto loc_6cf5;
    al = 0x01;
    goto loc_6d0c;
loc_6cf5: // 01ed:4e25
    al = 0x03;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6d12;
loc_6cff: // 01ed:4e2f
    if (memoryAGet(ds, 0xa1b2) == 0x00)
        goto loc_6d0a;
    al = 0x01;
    goto loc_6d0c;
loc_6d0a: // 01ed:4e3a
    al = 0x04;
loc_6d0c: // 01ed:4e3c
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6d12: // 01ed:4e42
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6d4f() // 01ed:4e7f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6d5b;
    sub_ca53();
loc_6d5b: // 01ed:4e8b
    al = memoryAGet(ds, 0x79b3);
    if (al < memoryAGet(ds, 0x7920))
        goto loc_6d68;
    al = 0x02;
    goto loc_6d91;
loc_6d68: // 01ed:4e98
    if (!(memoryAGet(ds, 0x79b3) & 0x01))
        goto loc_6d84;
    if (memoryAGet(ds, 0xa0e2) == 0x00)
        goto loc_6d7a;
    al = 0x02;
    goto loc_6d91;
loc_6d7a: // 01ed:4eaa
    al = 0x03;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6d97;
loc_6d84: // 01ed:4eb4
    if (memoryAGet(ds, 0xa1b2) == 0x00)
        goto loc_6d8f;
    al = 0x02;
    goto loc_6d91;
loc_6d8f: // 01ed:4ebf
    al = 0x04;
loc_6d91: // 01ed:4ec1
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6d97: // 01ed:4ec7
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6d99() // 01ed:4ec9
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6da5;
    sub_ca53();
loc_6da5: // 01ed:4ed5
    al = memoryAGet(ds, 0xa0e2);
    ah = 0x00;
    if (ax)
        goto loc_6db3;
    sub_6dd4();
    goto loc_6dd2;
loc_6db3: // 01ed:4ee3
    al = memoryAGet(ds, 0xa0e0);
    ah = 0x00;
    if (ax)
        goto loc_6dc1;
    sub_6cca();
    goto loc_6dd2;
loc_6dc1: // 01ed:4ef1
    al = memoryAGet(ds, 0xa0e1);
    ah = 0x00;
    if (ax)
        goto loc_6dcf;
    sub_6d4f();
    goto loc_6dd2;
loc_6dcf: // 01ed:4eff
    sub_6e59();
loc_6dd2: // 01ed:4f02
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6dd4() // 01ed:4f04
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6de0;
    sub_ca53();
loc_6de0: // 01ed:4f10
    al = memoryAGet(ds, 0x79b3);
    if (al < memoryAGet(ds, 0x7920))
        goto loc_6ded;
    al = 0x03;
    goto loc_6e16;
loc_6ded: // 01ed:4f1d
    if (!(memoryAGet(ds, 0x79b3) & 0x01))
        goto loc_6e09;
    if (memoryAGet(ds, 0xa0e0) == 0x00)
        goto loc_6dff;
    al = 0x03;
    goto loc_6e16;
loc_6dff: // 01ed:4f2f
    al = 0x01;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6e1c;
loc_6e09: // 01ed:4f39
    if (memoryAGet(ds, 0xa0e1) == 0x00)
        goto loc_6e14;
    al = 0x03;
    goto loc_6e16;
loc_6e14: // 01ed:4f44
    al = 0x02;
loc_6e16: // 01ed:4f46
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6e1c: // 01ed:4f4c
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6e1e() // 01ed:4f4e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6e2a;
    sub_ca53();
loc_6e2a: // 01ed:4f5a
    al = memoryAGet(ds, 0xa1b2);
    ah = 0x00;
    if (ax)
        goto loc_6e38;
    sub_6e59();
    goto loc_6e57;
loc_6e38: // 01ed:4f68
    al = memoryAGet(ds, 0xa0e1);
    ah = 0x00;
    if (ax)
        goto loc_6e46;
    sub_6d4f();
    goto loc_6e57;
loc_6e46: // 01ed:4f76
    al = memoryAGet(ds, 0xa0e0);
    ah = 0x00;
    if (ax)
        goto loc_6e54;
    sub_6cca();
    goto loc_6e57;
loc_6e54: // 01ed:4f84
    sub_6dd4();
loc_6e57: // 01ed:4f87
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6e59() // 01ed:4f89
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6e65;
    sub_ca53();
loc_6e65: // 01ed:4f95
    al = memoryAGet(ds, 0x79b3);
    if (al < memoryAGet(ds, 0x7920))
        goto loc_6e72;
    al = 0x04;
    goto loc_6e9b;
loc_6e72: // 01ed:4fa2
    if (!(memoryAGet(ds, 0x79b3) & 0x01))
        goto loc_6e8e;
    if (memoryAGet(ds, 0xa0e0) == 0x00)
        goto loc_6e84;
    al = 0x04;
    goto loc_6e9b;
loc_6e84: // 01ed:4fb4
    al = 0x01;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6ea1;
loc_6e8e: // 01ed:4fbe
    if (memoryAGet(ds, 0xa0e1) == 0x00)
        goto loc_6e99;
    al = 0x04;
    goto loc_6e9b;
loc_6e99: // 01ed:4fc9
    al = 0x02;
loc_6e9b: // 01ed:4fcb
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6ea1: // 01ed:4fd1
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6ea3() // 01ed:4fd3
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6eb1;
    sub_ca53();
loc_6eb1: // 01ed:4fe1
    al = memoryAGet(ds, 0x79b3);
    al &= 0x03;
    memoryASet(ss, bp - 2, al);
    sub_b281();
    memoryASet(ds, 0x79b3, al);
    al &= 0x01;
    al += memoryAGet(ss, bp - 2);
    al += 0x05;
    memoryASet(ss, bp - 1, al);
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6ed3() // 01ed:5003
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6edf;
    sub_ca53();
loc_6edf: // 01ed:500f
    if (memoryAGet(ds, 0x8563) != 0x05)
        goto loc_6ef3;
    al = memoryAGet(ds, 0x8562);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    callIndirect(cs*16+memoryAGet16(ds, bx + 2140));
loc_6ef3: // 01ed:5023
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6f29() // 01ed:5059
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f35;
    sub_ca53();
loc_6f35: // 01ed:5065
    memoryASet(ds, 0x8571, memoryAGet(ds, 0x8571) - 1);
    memoryASet(ds, 0x8564, memoryAGet(ds, 0x8564) - 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6f3f() // 01ed:506f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f4b;
    sub_ca53();
loc_6f4b: // 01ed:507b
    memoryASet(ds, 0x8571, memoryAGet(ds, 0x8571) + 1);
    memoryASet(ds, 0x8564, memoryAGet(ds, 0x8564) + 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6f55() // 01ed:5085
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f61;
    sub_ca53();
loc_6f61: // 01ed:5091
    al = memoryAGet(ds, 0xa0ce);
    ah = 0x00;
    if (ax)
        goto loc_6f8e;
    ax = memoryAGet16(ds, 0x9290);
    ax += 0xfffb;
    memoryASet16(ds, 0x084c, ax);
    ax = memoryAGet16(ds, 0x9290);
    ax += 0x0006;
    memoryASet16(ds, 0x084e, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax += 0xfffb;
    memoryASet16(ds, 0x0850, ax);
    ax = memoryAGet16(ds, 0x9292);
    ax += 0x0005;
    memoryASet16(ds, 0x0852, ax);
loc_6f8e: // 01ed:50be
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6f90() // 01ed:50c0
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6f9c;
    sub_ca53();
loc_6f9c: // 01ed:50cc
    al = memoryAGet(ds, 0xa0ce);
    ah = 0x00;
    if (ax)
        goto loc_6fc9;
    ax = memoryAGet16(ds, 0x79ba);
    ax += 0xfffb;
    memoryASet16(ds, 0x0854, ax);
    ax = memoryAGet16(ds, 0x79ba);
    ax += 0x0006;
    memoryASet16(ds, 0x0856, ax);
    ax = memoryAGet16(ds, 0x79bc);
    ax += 0xfffb;
    memoryASet16(ds, 0x0858, ax);
    ax = memoryAGet16(ds, 0x79bc);
    ax += 0x0005;
    memoryASet16(ds, 0x085a, ax);
loc_6fc9: // 01ed:50f9
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6fcb() // 01ed:50fb
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_6fd7;
    sub_ca53();
loc_6fd7: // 01ed:5107
    if (memoryAGet(ds, 0x8571) == 0xff)
        goto loc_704f;
    al = memoryAGet(ds, 0xa0ce);
    ah = 0x00;
    if (ax)
        goto loc_704f;
    al = memoryAGet(ds, 0x856d);
    ah = 0x00;
    if (ax)
        goto loc_704f;
    if (memoryAGet(ds, 0x792c) == 0x30)
        goto loc_704f;
    ax = memoryAGet16(ds, 0x0854);
    if ((short)ax <= (short)memoryAGet16(ds, 0x084e))
        goto loc_7007;
    memoryASet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7007: // 01ed:5137
    ax = memoryAGet16(ds, 0x084c);
    if ((short)ax <= (short)memoryAGet16(ds, 0x0856))
        goto loc_7017;
    memoryASet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7017: // 01ed:5147
    ax = memoryAGet16(ds, 0x0858);
    if ((short)ax <= (short)memoryAGet16(ds, 0x0852))
        goto loc_7027;
    memoryASet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7027: // 01ed:5157
    ax = memoryAGet16(ds, 0x0850);
    if ((short)ax <= (short)memoryAGet16(ds, 0x085a))
        goto loc_7037;
    memoryASet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7037: // 01ed:5167
    memoryASet(ds, 0xa1aa, 0x01);
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_7047;
    al = 0x03;
    goto loc_7049;
loc_7047: // 01ed:5177
    al = 0x0d;
loc_7049: // 01ed:5179
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_704f: // 01ed:517f
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7051() // 01ed:5181
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_705d;
    sub_ca53();
loc_705d: // 01ed:518d
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(es, bx, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(es, bx + 14, ax);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_b298();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_70a8() // 01ed:51d8
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_70b4;
    sub_ca53();
loc_70b4: // 01ed:51e4
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 16, 0x9d3a);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0002);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0003);
    memoryASet16(es, bx + 32, 0x0002);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 6, 0x0004);
    memoryASet16(es, bx + 16, 0x9baf);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0008);
    memoryASet16(es, bx + 16, 0x9eba);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 24, 0x0001);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 8, 0x0003);
    memoryASet16(es, bx + 16, 0x9fba);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x000d);
    memoryASet16(es, bx + 16, 0x8b88);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 24, 0x0006);
    memoryASet16(es, bx + 26, 0x0002);
    memoryASet16(es, bx + 30, 0x0006);
    memoryASet16(es, bx + 32, 0x0002);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 8, 0x0011);
    memoryASet16(es, bx + 16, 0x824e);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 8, 0x0015);
    memoryASet16(es, bx + 16, 0x8582);
    memoryASet16(es, bx + 18, ds);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_722e() // 01ed:535e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_723a;
    sub_ca53();
loc_723a: // 01ed:536a
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet(es, bx + 34, 0x00);
    memoryASet(es, bx + 35, 0x00);
    memoryASet(es, bx + 36, 0x00);
    memoryASet(es, bx + 37, 0x00);
    bx = memoryAGet16(ds, 0x08b8);
    es = memoryAGet16(ds, 0x08b8 + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 16, 0x8e8d);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0004);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    bx = memoryAGet16(ds, 0x08ec);
    es = memoryAGet16(ds, 0x08ec + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 16, 0x9294);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0004);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    bx = memoryAGet16(ds, 0x08bc);
    es = memoryAGet16(ds, 0x08bc + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0001);
    memoryASet16(es, bx + 12, 0x0004);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    bx = memoryAGet16(ds, 0x08c0);
    es = memoryAGet16(ds, 0x08c0 + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0003);
    memoryASet16(es, bx + 12, 0x0002);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0002);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08c4);
    es = memoryAGet16(ds, 0x08c4 + 2);
    memoryASet16(es, bx + 2, 0x8e8d);
    memoryASet16(es, bx + 4, ds);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0004);
    memoryASet16(es, bx + 12, 0x0004);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    bx = memoryAGet16(ds, 0x08e8);
    es = memoryAGet16(ds, 0x08e8 + 2);
    memoryASet16(es, bx + 2, 0x9294);
    memoryASet16(es, bx + 4, ds);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0004);
    memoryASet16(es, bx + 12, 0x0004);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    bx = memoryAGet16(ds, 0x08c8);
    es = memoryAGet16(ds, 0x08c8 + 2);
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 16, 0x8888);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    bx = memoryAGet16(ds, 0x08cc);
    es = memoryAGet16(ds, 0x08cc + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 12, 0x0004);
    memoryASet16(es, bx + 16, 0x8888);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    bx = memoryAGet16(ds, 0x08d0);
    es = memoryAGet16(ds, 0x08d0 + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0001);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0004);
    bx = memoryAGet16(ds, 0x08d4);
    es = memoryAGet16(ds, 0x08d4 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 30, 0x0002);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08d8);
    es = memoryAGet16(ds, 0x08d8 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 16, 0x8888);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0003);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08dc);
    es = memoryAGet16(ds, 0x08dc + 2);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0003);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 16, 0x8888);
    memoryASet16(es, bx + 18, ds);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0004);
    memoryASet16(es, bx + 30, 0x0003);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08e0);
    es = memoryAGet16(ds, 0x08e0 + 2);
    memoryASet16(es, bx, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 24, 0x0003);
    memoryASet16(es, bx + 26, 0x0002);
    memoryASet16(es, bx + 30, 0x0003);
    memoryASet16(es, bx + 32, 0x0002);
    bx = memoryAGet16(ds, 0x08e4);
    es = memoryAGet16(ds, 0x08e4 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 32, 0x0002);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7551() // 01ed:5681
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_7562;
    sub_ca53();
loc_7562: // 01ed:5692
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = memoryAGet16(ds, 0x7928);
    dx = memoryAGet16(ds, 0x7926);
    memoryASet16(ds, 0x857e, dx);
    memoryASet16(ds, 0x8580, ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0003;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x094e));
    push(memoryAGet16(ds, 0x094c));
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a2a();
    sp += 0x000c;
    if (memoryAGet16(ds, 0x541d) != 0x0001)
        goto loc_760a;
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    memoryASet16(ds, 0x9b96, dx);
    memoryASet16(ds, 0x9b98, ax);
    memoryASet(ss, bp - 5, 0x00);
    goto loc_7604;
loc_75e7: // 01ed:5717
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9b96);
    es = memoryAGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, di + 1822);
    memoryASet(es, bx + 35, al);
    memoryASet(ss, bp - 5, memoryAGet(ss, bp - 5) + 1);
loc_7604: // 01ed:5734
    if (memoryAGet(ss, bp - 5) < 0x10)
        goto loc_75e7;
loc_760a: // 01ed:573a
    sub_5337();
    ax = memoryAGet16(ds, 0x8580);
    dx = memoryAGet16(ds, 0x857e);
    dx += 0x0063;
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet16(es, bx + 6, 0x0000);
    memoryASet16(es, bx + 8, 0x0000);
    memoryASet16(es, bx + 10, 0x0014);
    memoryASet16(es, bx + 12, 0x0019);
    memoryASet16(es, bx + 14, 0x0001);
    memoryASet16(es, bx + 20, 0x0000);
    memoryASet16(es, bx + 22, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0014);
    memoryASet16(es, bx + 32, 0x0019);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryAGet16(ds, 0x8580));
    push(memoryAGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    ax = 0x0001;
    push(ax);
    sub_9aad();
    sp++;
    sp++;
    sub_b734();
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 14, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0002);
    sub_76b1();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_76b1() // 01ed:57e1
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_76c0;
    sub_ca53();
loc_76c0: // 01ed:57f0
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    memoryASet(ss, bp - 9, 0x00);
    memoryASet(ss, bp - 1, 0x00);
    goto loc_7879;
loc_76d3: // 01ed:5803
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x08f0;
    memoryASet16(ds, 0x8574, ax);
    memoryASet16(ds, 0x8576, ds);
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    if (ax <= memoryAGet16(ds, 0xa0d6))
        goto loc_76fd;
    goto loc_77d1;
loc_76fd: // 01ed:582d
    if (ax < memoryAGet16(ds, 0xa0d6))
        goto loc_7708;
    if (dx < memoryAGet16(ds, 0xa0d4))
        goto loc_7708;
    goto loc_77d1;
loc_7708: // 01ed:5838
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    if (!ax)
        goto loc_7714;
    goto loc_77d1;
loc_7714: // 01ed:5844
    memoryASet(ss, bp - 9, 0x01);
    al = memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 2, al);
    ax = memoryAGet16(ds, 0x0922);
    dx = memoryAGet16(ds, 0x0920);
    memoryASet16(ss, bp - 6, dx);
    memoryASet16(ss, bp - 4, ax);
    memoryASet(ss, bp - 10, 0x06);
    goto loc_7784;
loc_7731: // 01ed:5861
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 2282);
    dx = memoryAGet16(ds, bx + 2280);
    bl = memoryAGet(ss, bp - 10);
    bh = 0x00;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    memoryASet16(ds, bx + 2288, dx);
    memoryASet16(ds, bx + 2290, ax);
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 2286);
    dx = memoryAGet16(ds, bx + 2284);
    bl = memoryAGet(ss, bp - 10);
    bh = 0x00;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    memoryASet16(ds, bx + 2292, dx);
    memoryASet16(ds, bx + 2294, ax);
    memoryASet(ss, bp - 10, memoryAGet(ss, bp - 10) - 1);
loc_7784: // 01ed:58b4
    al = memoryAGet(ss, bp - 10);
    if (al > memoryAGet(ss, bp - 1))
        goto loc_7731;
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    ax = memoryAGet16(ss, bp - 4);
    dx = memoryAGet16(ss, bp - 6);
    memoryASet16(es, bx, dx);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 10, 0x00);
    goto loc_77b8;
loc_77a3: // 01ed:58d3
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    al = memoryAGet(ss, bp - 10);
    ah = 0x00;
    bx += ax;
    memoryASet(es, bx, 0x41);
    memoryASet(ss, bp - 10, memoryAGet(ss, bp - 10) + 1);
loc_77b8: // 01ed:58e8
    if (memoryAGet(ss, bp - 10) < 0x08)
        goto loc_77a3;
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    ax = memoryAGet16(ds, 0xa0d6);
    dx = memoryAGet16(ds, 0xa0d4);
    memoryASet16(es, bx + 4, dx);
    memoryASet16(es, bx + 6, ax);
loc_77d1: // 01ed:5901
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0041;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 7, 0x00);
    goto loc_784a;
loc_77eb: // 01ed:591b
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    al = memoryAGet(ss, bp - 7);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 8, al);
    if (al != 0x2e)
        goto loc_781a;
    if (memoryAGet(ss, bp - 9) == 0x00)
        goto loc_7815;
    al = memoryAGet(ss, bp - 2);
    if (al != memoryAGet(ss, bp - 1))
        goto loc_7815;
    al = 0x5b;
    goto loc_7817;
loc_7815: // 01ed:5945
    al = 0x20;
loc_7817: // 01ed:5947
    memoryASet(ss, bp - 8, al);
loc_781a: // 01ed:594a
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    al = memoryAGet(ss, bp - 8);
    ah = 0x00;
    ax += 0x0175;
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 7);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    if (memoryAGet(ss, bp - 8) == 0x20)
        goto loc_7847;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_7847: // 01ed:5977
    memoryASet(ss, bp - 7, memoryAGet(ss, bp - 7) + 1);
loc_784a: // 01ed:597a
    if (memoryAGet(ss, bp - 7) < 0x08)
        goto loc_77eb;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0041;
    push(ax);
    ax = 0x00b0;
    push(ax);
    al = 0x07;
    push(ax);
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    push(memoryAGet16(es, bx + 6));
    push(memoryAGet16(es, bx + 4));
    sub_7f0d();
    sp += 0x000a;
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
loc_7879: // 01ed:59a9
    if (memoryAGet(ss, bp - 1) >= 0x07)
        goto loc_7882;
    goto loc_76d3;
loc_7882: // 01ed:59b2
    if (memoryAGet(ss, bp - 9) == 0x00)
        goto loc_7893;
    al = memoryAGet(ss, bp - 2);
    push(ax);
    sub_78a3();
    sp++;
    sp++;
    goto loc_7896;
loc_7893: // 01ed:59c3
    sub_515f();
loc_7896: // 01ed:59c6
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_78a3() // 01ed:59d3
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_78b2;
    sub_ca53();
loc_78b2: // 01ed:59e2
    memoryASet(ss, bp - 2, 0x00);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x08f0;
    memoryASet16(ds, 0x8574, ax);
    memoryASet16(ds, 0x8576, ds);
    memoryASet16(ss, bp - 6, 0x01b6);
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    memoryASet(es, bx, 0x41);
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax += 0x0008;
    memoryASet16(es, bx + 22, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_791a: // 01ed:5a4a
    if (!(memoryAGet(ss, bp - 1) & 0x01))
        goto loc_7984;
    if ((short)memoryAGet16(ss, bp - 6) <= (short)0x01ac)
        goto loc_7984;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) - 1);
    if (memoryAGet16(ss, bp - 6) != 0x01d0)
        goto loc_7936;
    memoryASet16(ss, bp - 6, 0x01a3);
loc_7936: // 01ed:5a66
    ax = memoryAGet16(ss, bp - 6);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    memoryASet(es, bx, al);
    if (memoryAGet16(ss, bp - 6) != 0x002e)
        goto loc_795e;
    memoryASet16(ss, bp - 6, 0x005b);
loc_795e: // 01ed:5a8e
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0175;
    memoryASet16(ss, bp - 6, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_7984: // 01ed:5ab4
    if (!(memoryAGet(ss, bp - 1) & 0x02))
        goto loc_79ee;
    if ((short)memoryAGet16(ss, bp - 6) >= (short)0x01d0)
        goto loc_79ee;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + 1);
    if (memoryAGet16(ss, bp - 6) != 0x01d0)
        goto loc_79a0;
    memoryASet16(ss, bp - 6, 0x01a3);
loc_79a0: // 01ed:5ad0
    ax = memoryAGet16(ss, bp - 6);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    memoryASet(es, bx, al);
    if (memoryAGet16(ss, bp - 6) != 0x002e)
        goto loc_79c8;
    memoryASet16(ss, bp - 6, 0x005b);
loc_79c8: // 01ed:5af8
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0175;
    memoryASet16(ss, bp - 6, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_79ee: // 01ed:5b1e
    if (memoryAGet(ss, bp - 1) & 0x04)
        goto loc_79f7;
    goto loc_7a7b;
loc_79f7: // 01ed:5b27
    if (memoryAGet(ss, bp - 2) == 0x00)
        goto loc_7a7b;
    if (memoryAGet16(ss, bp - 6) != 0x01d0)
        goto loc_7a09;
    memoryASet16(ss, bp - 6, 0x01a3);
loc_7a09: // 01ed:5b39
    ax = memoryAGet16(ss, bp - 6);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) - 1);
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    memoryASet16(ss, bp - 6, ax);
    if (memoryAGet16(ss, bp - 6) != 0x002e)
        goto loc_7a4a;
    memoryASet16(ss, bp - 6, 0x005b);
loc_7a4a: // 01ed:5b7a
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0175;
    memoryASet16(ss, bp - 6, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_7a7b: // 01ed:5bab
    if (memoryAGet(ss, bp - 1) & 0x08)
        goto loc_7a84;
    goto loc_7b07;
loc_7a84: // 01ed:5bb4
    if (memoryAGet(ss, bp - 2) >= 0x07)
        goto loc_7b07;
    if (memoryAGet16(ss, bp - 6) != 0x01d0)
        goto loc_7a96;
    memoryASet16(ss, bp - 6, 0x01a3);
loc_7a96: // 01ed:5bc6
    ax = memoryAGet16(ss, bp - 6);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(ss, bp - 6);
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
    bx = memoryAGet16(ds, 0x8574);
    es = memoryAGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryAGet16(es, tx);
    es = memoryAGet16(es, tx + 2);
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    memoryASet16(ss, bp - 6, ax);
    if (memoryAGet16(ss, bp - 6) != 0x002e)
        goto loc_7ad7;
    memoryASet16(ss, bp - 6, 0x005b);
loc_7ad7: // 01ed:5c07
    ax = memoryAGet16(ss, bp - 6);
    ax += 0x0175;
    memoryASet16(ss, bp - 6, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryAGet16(ss, bp - 6));
    al = memoryAGet(ss, bp - 2);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_7b07: // 01ed:5c37
    memoryASet(ss, bp - 3, memoryAGet(ss, bp - 3) + 1);
    if (!(memoryAGet(ss, bp - 3) & 0x08))
        goto loc_7b1d;
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    goto loc_7b25;
loc_7b1d: // 01ed:5c4d
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
loc_7b25: // 01ed:5c55
    sp += 0x0004;
    al = 0x01;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
loc_7b30: // 01ed:5c60
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    memoryASet(ss, bp - 1, al);
    ah = 0x00;
    ax &= 0x0010;
    if (ax == 0x0010)
        goto loc_7b48;
    goto loc_791a;
loc_7b48: // 01ed:5c78
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7b57() // 01ed:5c87
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_7b66;
    sub_ca53();
loc_7b66: // 01ed:5c96
    push(ss);
    ax = bp - 0xa;
    push(ax);
    push(ds);
    ax = 0x256a;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    memoryASet16(es, bx + 14, 0x0000);
    memoryASet16(es, bx + 28, 0x0000);
    memoryASet16(es, bx + 30, 0x0001);
    memoryASet16(es, bx + 32, 0x0002);
    al = 0x00;
    memoryASet(ss, bp - 6, al);
    memoryASet(ss, bp - 3, al);
    ax = memoryAGet16(ss, bp - 8);
    dx = memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp - 14, dx);
    memoryASet16(ss, bp - 12, ax);
    memoryASet(ss, bp - 2, 0x00);
    goto loc_7bbd;
loc_7bac: // 01ed:5cdc
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    memoryASet(es, bx, 0x41);
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_7bbd: // 01ed:5ced
    if (memoryAGet(ss, bp - 2) < 0x06)
        goto loc_7bac;
    memoryASet16(ss, bp - 20, 0x01b6);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    memoryASet(es, bx, 0x41);
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    memoryASet16(es, bx + 20, ax);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    memoryASet16(es, bx + 22, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7c09: // 01ed:5d39
    if (!(memoryAGet(ss, bp - 1) & 0x01))
        goto loc_7c6d;
    if ((short)memoryAGet16(ss, bp - 20) <= (short)0x01ac)
        goto loc_7c6d;
    memoryASet16(ss, bp - 20, memoryAGet16(ss, bp - 20) - 1);
    if (memoryAGet16(ss, bp - 20) != 0x01d0)
        goto loc_7c25;
    memoryASet16(ss, bp - 20, 0x01a3);
loc_7c25: // 01ed:5d55
    ax = memoryAGet16(ss, bp - 20);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 20);
    memoryASet(es, bx, al);
    if (memoryAGet16(ss, bp - 20) != 0x002e)
        goto loc_7c49;
    memoryASet16(ss, bp - 20, 0x005b);
loc_7c49: // 01ed:5d79
    ax = memoryAGet16(ss, bp - 20);
    ax += 0x0175;
    memoryASet16(ss, bp - 20, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7c6d: // 01ed:5d9d
    if (!(memoryAGet(ss, bp - 1) & 0x02))
        goto loc_7cd1;
    if ((short)memoryAGet16(ss, bp - 20) >= (short)0x01d0)
        goto loc_7cd1;
    memoryASet16(ss, bp - 20, memoryAGet16(ss, bp - 20) + 1);
    if (memoryAGet16(ss, bp - 20) != 0x01d0)
        goto loc_7c89;
    memoryASet16(ss, bp - 20, 0x01a3);
loc_7c89: // 01ed:5db9
    ax = memoryAGet16(ss, bp - 20);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 20);
    memoryASet(es, bx, al);
    if (memoryAGet16(ss, bp - 20) != 0x002e)
        goto loc_7cad;
    memoryASet16(ss, bp - 20, 0x005b);
loc_7cad: // 01ed:5ddd
    ax = memoryAGet16(ss, bp - 20);
    ax += 0x0175;
    memoryASet16(ss, bp - 20, ax);
    al = 0x01;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7cd1: // 01ed:5e01
    if (!(memoryAGet(ss, bp - 1) & 0x04))
        goto loc_7d54;
    if (memoryAGet(ss, bp - 3) == 0x00)
        goto loc_7d54;
    if (memoryAGet16(ss, bp - 20) != 0x01d0)
        goto loc_7ce9;
    memoryASet16(ss, bp - 20, 0x01a3);
loc_7ce9: // 01ed:5e19
    ax = memoryAGet16(ss, bp - 20);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 20);
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 3, memoryAGet(ss, bp - 3) - 1);
    memoryASet(ss, bp + 6, memoryAGet(ss, bp + 6) - 1);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    memoryASet16(ss, bp - 20, ax);
    if (memoryAGet16(ss, bp - 20) != 0x002e)
        goto loc_7d25;
    memoryASet16(ss, bp - 20, 0x005b);
loc_7d25: // 01ed:5e55
    ax = memoryAGet16(ss, bp - 20);
    ax += 0x0175;
    memoryASet16(ss, bp - 20, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7d54: // 01ed:5e84
    if (!(memoryAGet(ss, bp - 1) & 0x08))
        goto loc_7dd6;
    if (memoryAGet(ss, bp - 3) >= 0x05)
        goto loc_7dd6;
    if (memoryAGet16(ss, bp - 20) != 0x01d0)
        goto loc_7d6c;
    memoryASet16(ss, bp - 20, 0x01a3);
loc_7d6c: // 01ed:5e9c
    ax = memoryAGet16(ss, bp - 20);
    ax += 0xfe8b;
    memoryASet16(ss, bp - 20, ax);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(ss, bp - 20);
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 3, memoryAGet(ss, bp - 3) + 1);
    memoryASet(ss, bp + 6, memoryAGet(ss, bp + 6) + 1);
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    bx += ax;
    al = memoryAGet(es, bx);
    ah = 0x00;
    memoryASet16(ss, bp - 20, ax);
    if (memoryAGet16(ss, bp - 20) != 0x002e)
        goto loc_7da8;
    memoryASet16(ss, bp - 20, 0x005b);
loc_7da8: // 01ed:5ed8
    ax = memoryAGet16(ss, bp - 20);
    ax += 0x0175;
    memoryASet16(ss, bp - 20, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryAGet16(ss, bp - 20));
    al = memoryAGet(ss, bp + 6);
    push(ax);
    al = memoryAGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7dd6: // 01ed:5f06
    memoryASet(ss, bp - 6, memoryAGet(ss, bp - 6) + 1);
    if (!(memoryAGet(ss, bp - 6) & 0x08))
        goto loc_7dec;
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    goto loc_7df4;
loc_7dec: // 01ed:5f1c
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
loc_7df4: // 01ed:5f24
    sp += 0x0004;
    al = 0x01;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
loc_7dff: // 01ed:5f2f
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    memoryASet(ss, bp - 1, al);
    ah = 0x00;
    ax &= 0x0010;
    if (ax == 0x0010)
        goto loc_7e17;
    goto loc_7c09;
loc_7e17: // 01ed:5f47
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    memoryASet(ss, bp - 4, al);
    memoryASet(ss, bp - 2, al);
    goto loc_7e95;
loc_7e2c: // 01ed:5f5c
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 4958);
    dx = memoryAGet16(ds, bx + 4956);
    memoryASet16(ss, bp - 18, dx);
    memoryASet16(ss, bp - 16, ax);
    al = 0x00;
    memoryASet(ss, bp - 5, al);
    memoryASet(ss, bp - 3, al);
    goto loc_7e72;
loc_7e4f: // 01ed:5f7f
    al = memoryAGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryAGet16(ss, bp - 14);
    es = memoryAGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    dl = memoryAGet(ss, bp - 3);
    dh = 0x00;
    bx = memoryAGet16(ss, bp - 18);
    es = memoryAGet16(ss, bp - 18 + 2);
    bx += dx;
    if (al == memoryAGet(es, bx))
        goto loc_7e6f;
    memoryASet(ss, bp - 5, 0x01);
loc_7e6f: // 01ed:5f9f
    memoryASet(ss, bp - 3, memoryAGet(ss, bp - 3) + 1);
loc_7e72: // 01ed:5fa2
    if (memoryAGet(ss, bp - 3) >= 0x06)
        goto loc_7e81;
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    if (!ax)
        goto loc_7e4f;
loc_7e81: // 01ed:5fb1
    al = memoryAGet(ss, bp - 5);
    ah = 0x00;
    if (ax)
        goto loc_7e92;
    al = memoryAGet(ss, bp - 2);
    al += 0x02;
    memoryASet(ss, bp - 4, al);
loc_7e92: // 01ed:5fc2
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_7e95: // 01ed:5fc5
    if (memoryAGet(ss, bp - 2) >= 0x08)
        goto loc_7ea4;
    al = memoryAGet(ss, bp - 4);
    ah = 0x00;
    if (!ax)
        goto loc_7e2c;
loc_7ea4: // 01ed:5fd4
    al = memoryAGet(ss, bp - 4);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7eab() // 01ed:5fdb
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_7eb7;
    sub_ca53();
loc_7eb7: // 01ed:5fe7
    bx = memoryAGet16(ds, 0x0574);
    es = memoryAGet16(ds, 0x0574 + 2);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    memoryASet16(es, bx + 20, ax);
    push(memoryAGet16(ds, 0x0576));
    push(memoryAGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp + 6);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memoryASet16(es, bx, ax);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    memoryASet16(es, bx + 2, ax);
    if (memoryAGet(ss, bp + 10) == 0x00)
        goto loc_7f03;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_7f03: // 01ed:6033
    al = 0x08;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7f0d() // 01ed:603d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    si = memoryAGet16(ss, bp + 10);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_7f20;
    sub_ca53();
loc_7f20: // 01ed:6050
    al = memoryAGet(ss, bp + 8);
    memoryASet(ss, bp - 12, al);
    memoryASet(ss, bp - 11, 0x00);
    goto loc_7f3f;
loc_7f2c: // 01ed:605c
    al = memoryAGet(ss, bp - 11);
    memoryASet(ss, bp - 11, memoryAGet(ss, bp - 11) + 1);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    memoryASet(ss, bx, 0x20);
loc_7f3f: // 01ed:606f
    al = memoryAGet(ss, bp - 11);
    if (al < memoryAGet(ss, bp + 8))
        goto loc_7f2c;
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    memoryASet(ss, bx, 0x00);
    goto loc_7f9e;
loc_7f59: // 01ed:6089
    al = memoryAGet(ss, bp + 4);
    memoryASet(ss, bp - 1, al);
    ax = 0;
    dx = 0x000a;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c7be();
    memoryASet16(ss, bp + 4, ax);
    bx = ax;
    memoryASet16(ss, bp + 6, dx);
    cx = dx;
    dx = 0;
    ax = 0x000a;
    sub_c8e4();
    dl = memoryAGet(ss, bp - 1);
    dl -= al;
    memoryASet(ss, bp - 1, dl);
    al = memoryAGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    dl = memoryAGet(ss, bp - 1);
    dl += 0x30;
    bx = ax;
    memoryASet(ss, bx, dl);
loc_7f9e: // 01ed:60ce
    al = memoryAGet(ss, bp + 8);
    memoryASet(ss, bp + 8, memoryAGet(ss, bp + 8) - 1);
    if (stop(/*condition!*/))
        goto loc_7f59;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(es, bx + 2, ax);
    memoryASet(ss, bp - 11, 0x00);
    goto loc_7ff3;
loc_7fb9: // 01ed:60e9
    al = memoryAGet(ss, bp - 11);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    al = memoryAGet(ss, bx);
    ah = 0x00;
    ax += 0x017c;
    bx = memoryAGet16(ds, 0x8884);
    es = memoryAGet16(ds, 0x8884 + 2);
    memoryASet16(es, bx + 4, ax);
    al = memoryAGet(ss, bp - 11);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    dx = si;
    dx += ax;
    memoryASet16(es, bx, dx);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memoryASet(ss, bp - 11, memoryAGet(ss, bp - 11) + 1);
loc_7ff3: // 01ed:6123
    al = memoryAGet(ss, bp - 11);
    if (al < memoryAGet(ss, bp - 12))
        goto loc_7fb9;
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8000() // 01ed:6130
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_800e;
    sub_ca53();
loc_800e: // 01ed:613e
    bx = memoryAGet16(ds, 0xa0d0);
    es = memoryAGet16(ds, 0xa0d0 + 2);
    memoryASet16(es, bx + 4, 0x01aa);
    memoryASet16(es, bx + 2, 0x0000);
    al = memoryAGet(ds, 0x791a);
    memoryASet(ss, bp - 1, al);
    goto loc_8049;
loc_8026: // 01ed:6156
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0050;
    bx = memoryAGet16(ds, 0xa0d0);
    es = memoryAGet16(ds, 0xa0d0 + 2);
    memoryASet16(es, bx, ax);
    push(ds);
    ax = 0x7986;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) - 1);
loc_8049: // 01ed:6179
    if (memoryAGet(ss, bp - 1) != 0x00)
        goto loc_8026;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8053() // 01ed:6183
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8061;
    sub_ca53();
loc_8061: // 01ed:6191
    memoryASet16(ds, 0x9ba6, 0x0886);
    memoryASet16(ds, 0x9ba8, ds);
    bx = memoryAGet16(ds, 0x9ba6);
    es = memoryAGet16(ds, 0x9ba6 + 2);
    memoryASet(es, bx, 0xff);
    memoryASet(ds, 0xa1a6, 0x00);
    dl = 0x00;
    goto loc_809b;
loc_807c: // 01ed:61ac
    al = dl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    cl = al;
    if (cl < 0x0e)
        goto loc_8099;
    if (cl >= 0x12)
        goto loc_8099;
    memoryASet(ds, 0xa1a6, al);
loc_8099: // 01ed:61c9
    dl++;
loc_809b: // 01ed:61cb
    if (dl >= 0x30)
        goto loc_80a9;
    al = memoryAGet(ds, 0xa1a6);
    ah = 0x00;
    if (!ax)
        goto loc_807c;
loc_80a9: // 01ed:61d9
    if (memoryAGet(ds, 0xa1a6) != 0x00)
        goto loc_80b3;
    goto loc_8168;
loc_80b3: // 01ed:61e3
    al = 0x00;
    memoryASet(ss, bp - 1, al);
    dl = al;
    goto loc_80e2;
loc_80bc: // 01ed:61ec
    al = dl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    cl = al;
    if (cl < 0x0e)
        goto loc_80e0;
    if (cl >= 0x12)
        goto loc_80e0;
    if (al == memoryAGet(ds, 0xa1a6))
        goto loc_80e0;
    memoryASet(ss, bp - 1, 0x01);
loc_80e0: // 01ed:6210
    dl++;
loc_80e2: // 01ed:6212
    if (dl >= 0x30)
        goto loc_80f0;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_80bc;
loc_80f0: // 01ed:6220
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_8168;
    al = 0x00;
    memoryASet(ss, bp - 2, al);
    memoryASet(ss, bp - 1, al);
    dl = 0x00;
    goto loc_812b;
loc_8105: // 01ed:6235
    al = dl;
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx + 48) != 0x05)
        goto loc_8129;
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9ba6);
    es = memoryAGet16(ds, 0x9ba6 + 2);
    bx += ax;
    al = dl;
    memoryASet(es, bx, al);
    memoryASet(ss, bp - 2, memoryAGet(ss, bp - 2) + 1);
loc_8129: // 01ed:6259
    dl++;
loc_812b: // 01ed:625b
    if (dl >= 0x30)
        goto loc_8139;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_8105;
loc_8139: // 01ed:6269
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9ba6);
    es = memoryAGet16(ds, 0x9ba6 + 2);
    bx += ax;
    if (memoryAGet(es, bx) == 0xff)
        goto loc_8168;
    al = memoryAGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x9ba6);
    bx += ax;
    memoryASet(es, bx, 0xff);
    memoryASet16(ds, 0x9ba6, 0x0886);
    memoryASet16(ds, 0x9ba8, ds);
    memoryASet(ds, 0x79b7, 0x00);
loc_8168: // 01ed:6298
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_816c() // 01ed:629c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8178;
    sub_ca53();
loc_8178: // 01ed:62a8
    bx = memoryAGet16(ds, 0x9ba6);
    es = memoryAGet16(ds, 0x9ba6 + 2);
    if (memoryAGet(es, bx) != 0xff)
        goto loc_8196;
    memoryASet16(ds, 0x9ba6, 0x0886);
    memoryASet16(ds, 0x9ba8, ds);
    bx = memoryAGet16(ds, 0x9ba6);
    es = memoryAGet16(ds, 0x9ba6 + 2);
    memoryASet(es, bx, 0xff);
    goto loc_81d3;
loc_8196: // 01ed:62c6
    al = memoryAGet(ds, 0x79b7);
    ah = 0x00;
    if (ax)
        goto loc_81cf;
    memoryASet(ds, 0x79b7, 0x0a);
    bx = memoryAGet16(ds, 0x9ba6);
    es = memoryAGet16(ds, 0x9ba6 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x8570, al);
    al = 0x18;
    push(ax);
    sub_8959();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_81c1;
    al = 0x11;
    goto loc_81c3;
loc_81c1: // 01ed:62f1
    al = 0x0e;
loc_81c3: // 01ed:62f3
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    memoryASet16(ds, 0x9ba6, memoryAGet16(ds, 0x9ba6) + 1);
    goto loc_81d3;
loc_81cf: // 01ed:62ff
    memoryASet(ds, 0x79b7, memoryAGet(ds, 0x79b7) - 1);
loc_81d3: // 01ed:6303
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_81d5() // 01ed:6305
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_81e1;
    sub_ca53();
loc_81e1: // 01ed:6311
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_81ec;
    al = 0x03;
    goto loc_81ee;
loc_81ec: // 01ed:631c
    al = 0x0d;
loc_81ee: // 01ed:631e
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_81f6() // 01ed:6326
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8202;
    sub_ca53();
loc_8202: // 01ed:6332
    if (memoryAGet(ds, 0x855e) == 0x00)
        goto loc_8240;
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx + 47) != 0x0c)
        goto loc_8240;
    memoryASet(ds, 0x792a, 0x00);
    memoryASet(ds, 0xa0ce, 0x01);
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8238;
    al = 0x03;
    goto loc_823a;
loc_8238: // 01ed:6368
    al = 0x0d;
loc_823a: // 01ed:636a
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8240: // 01ed:6370
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8242() // 01ed:6372
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_824e;
    sub_ca53();
loc_824e: // 01ed:637e
    if (memoryAGet(ds, 0x855e) == 0x07)
        goto loc_828c;
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryAGet(es, bx + 48) != 0x0c)
        goto loc_828c;
    memoryASet(ds, 0x792a, 0x00);
    memoryASet(ds, 0xa0ce, 0x01);
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8284;
    al = 0x03;
    goto loc_8286;
loc_8284: // 01ed:63b4
    al = 0x0d;
loc_8286: // 01ed:63b6
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_828c: // 01ed:63bc
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_828e() // 01ed:63be
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_829c;
    sub_ca53();
loc_829c: // 01ed:63cc
    if (memoryAGet(ds, 0x8552) == 0x03)
        goto loc_82d8;
    if (memoryAGet(ds, 0x8552) == 0x0f)
        goto loc_82d8;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_82be;
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9790);
    goto loc_82c9;
loc_82be: // 01ed:63ee
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9742);
loc_82c9: // 01ed:63f9
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_82d8;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_82d8: // 01ed:6408
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_82dc() // 01ed:640c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_82ea;
    sub_ca53();
loc_82ea: // 01ed:641a
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_82fe;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 10126);
    goto loc_8309;
loc_82fe: // 01ed:642e
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 10094);
loc_8309: // 01ed:6439
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_8318;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8318: // 01ed:6448
    if (memoryAGet(ds, 0x8551) < 0x0e)
        goto loc_8329;
    if (memoryAGet(ds, 0x8551) >= 0x12)
        goto loc_8329;
    sub_8053();
loc_8329: // 01ed:6459
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_834e() // 01ed:647e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_835c;
    sub_ca53();
loc_835c: // 01ed:648c
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8370;
    al = memoryAGet(ds, 0x79b9);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9982);
    goto loc_837b;
loc_8370: // 01ed:64a0
    al = memoryAGet(ds, 0x79b9);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9934);
loc_837b: // 01ed:64ab
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_838a;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_838a: // 01ed:64ba
    sub_841e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_83b2() // 01ed:64e2
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_83be;
    sub_ca53();
loc_83be: // 01ed:64ee
    sub_84e1();
    al = memoryAGet(ds, 0x856e);
    al += 0xf8;
    memoryASet(ds, 0x856e, al);
    memoryASet(ds, 0x855c, memoryAGet(ds, 0x855c) - 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_83cf() // 01ed:64ff
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_83db;
    sub_ca53();
loc_83db: // 01ed:650b
    sub_84e1();
    al = memoryAGet(ds, 0x856e);
    al += 0x08;
    memoryASet(ds, 0x856e, al);
    memoryASet(ds, 0x855c, memoryAGet(ds, 0x855c) + 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_83ec() // 01ed:651c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_83f8;
    sub_ca53();
loc_83f8: // 01ed:6528
    sub_84e1();
    memoryASet(ds, 0x856e, memoryAGet(ds, 0x856e) - 1);
    memoryASet(ds, 0x855e, memoryAGet(ds, 0x855e) - 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8405() // 01ed:6535
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8411;
    sub_ca53();
loc_8411: // 01ed:6541
    sub_84e1();
    memoryASet(ds, 0x856e, memoryAGet(ds, 0x856e) + 1);
    memoryASet(ds, 0x855e, memoryAGet(ds, 0x855e) + 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_841e() // 01ed:654e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_842a;
    sub_ca53();
loc_842a: // 01ed:655a
    al = memoryAGet(ds, 0x7923);
    ah = 0x00;
    if (ax)
        goto loc_8455;
    if (memoryAGet(ds, 0x8244) & 0x10)
        goto loc_8441;
    if (!(memoryAGet(ds, 0x8244) & 0x01))
        goto loc_8455;
loc_8441: // 01ed:6571
    al = memoryAGet(ds, 0x7924);
    memoryASet(ds, 0x7922, al);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 15578);
    push(ax);
    sub_882e();
    sp++;
    sp++;
loc_8455: // 01ed:6585
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8457() // 01ed:6587
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8463;
    sub_ca53();
loc_8463: // 01ed:6593
    al = memoryAGet(ds, 0xa1a7);
    ah = 0x00;
    if (ax)
        goto loc_84a0;
    if (memoryAGet(ds, 0x7924) != 0x02)
        goto loc_84a0;
    if (!(memoryAGet(ds, 0x8244) & 0x02))
        goto loc_84a0;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8485;
    al = 0x04;
    goto loc_8487;
loc_8485: // 01ed:65b5
    al = 0x09;
loc_8487: // 01ed:65b7
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    memoryASet(ds, 0x79b4, 0x34);
    al = 0x34;
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_84a0: // 01ed:65d0
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84a2() // 01ed:65d2
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_84ae;
    sub_ca53();
loc_84ae: // 01ed:65de
    memoryASet(ds, 0x8244, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84b5() // 01ed:65e5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_84c1;
    sub_ca53();
loc_84c1: // 01ed:65f1
    al = memoryAGet(ds, 0x8244);
    al &= 0x10;
    memoryASet(ds, 0x8244, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84cb() // 01ed:65fb
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_84d7;
    sub_ca53();
loc_84d7: // 01ed:6607
    al = memoryAGet(ds, 0x8244);
    al &= 0x1d;
    memoryASet(ds, 0x8244, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84e1() // 01ed:6611
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_84ed;
    sub_ca53();
loc_84ed: // 01ed:661d
    al = memoryAGet(ds, 0x8244);
    al &= 0x0f;
    memoryASet(ds, 0x8244, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84f7() // 01ed:6627
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8503;
    sub_ca53();
loc_8503: // 01ed:6633
    al = memoryAGet(ds, 0x856e);
    push(ax);
    sub_8ac4();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x79b8) == 0x00)
        goto loc_8516;
    sub_8ae4();
loc_8516: // 01ed:6646
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8518() // 01ed:6648
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8526;
    sub_ca53();
loc_8526: // 01ed:6656
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_853a;
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9694);
    goto loc_8545;
loc_853a: // 01ed:666a
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 9646);
loc_8545: // 01ed:6675
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_8554;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8554: // 01ed:6684
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 15626);
    push(ax);
    sub_8857();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8569() // 01ed:6699
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8575;
    sub_ca53();
loc_8575: // 01ed:66a5
    if (memoryAGet(ds, 0x8552) == 0x03)
        goto loc_858e;
    if (memoryAGet(ds, 0x8552) == 0x0f)
        goto loc_858e;
    push(ds);
    ax = 0x3c7a;
    push(ax);
    sub_8c3a();
    sp += 0x0004;
loc_858e: // 01ed:66be
    if (memoryAGet(ds, 0x855e) == 0x00)
        goto loc_85a6;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13758);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_85a6: // 01ed:66d6
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_85a8() // 01ed:66d8
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_85b4;
    sub_ca53();
loc_85b4: // 01ed:66e4
    if (memoryAGet(ds, 0x8552) == 0x03)
        goto loc_85cd;
    if (memoryAGet(ds, 0x8552) == 0x0f)
        goto loc_85cd;
    push(ds);
    ax = 0x3caa;
    push(ax);
    sub_8c3a();
    sp += 0x0004;
loc_85cd: // 01ed:66fd
    if (memoryAGet(ds, 0x855e) == 0x07)
        goto loc_85e5;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13790);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_85e5: // 01ed:6715
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_85e7() // 01ed:6717
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_85f3;
    sub_ca53();
loc_85f3: // 01ed:6723
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    sub_8bf6();
    if (memoryAGet(ds, 0x856c) != 0x5b)
        goto loc_8608;
    memoryASet(ds, 0xa1b1, 0x00);
loc_8608: // 01ed:6738
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_860a() // 01ed:673a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8616;
    sub_ca53();
loc_8616: // 01ed:6746
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8618() // 01ed:6748
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8624;
    sub_ca53();
loc_8624: // 01ed:6754
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_862f;
    al = 0x08;
    goto loc_8631;
loc_862f: // 01ed:675f
    al = 0x2f;
loc_8631: // 01ed:6761
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x18;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x855e) == 0x00)
        goto loc_8657;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13822);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_8657: // 01ed:6787
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8659() // 01ed:6789
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8665;
    sub_ca53();
loc_8665: // 01ed:6795
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8670;
    al = 0x08;
    goto loc_8672;
loc_8670: // 01ed:67a0
    al = 0x2f;
loc_8672: // 01ed:67a2
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x19;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
    if (memoryAGet(ds, 0x855e) == 0x07)
        goto loc_8698;
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13854);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_8698: // 01ed:67c8
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_87ce() // 01ed:68fe
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_87da;
    sub_ca53();
loc_87da: // 01ed:690a
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13950);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memoryASet(ds, 0x8244, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_880a() // 01ed:693a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8816;
    sub_ca53();
loc_8816: // 01ed:6946
    al = memoryAGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 13982);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memoryASet(ds, 0x8244, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_882e() // 01ed:695e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_883a;
    sub_ca53();
loc_883a: // 01ed:696a
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    if (memoryAGet(ss, bp + 4) == 0x00)
        goto loc_8855;
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0xa1a7, al);
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_8855: // 01ed:6985
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8857() // 01ed:6987
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8863;
    sub_ca53();
loc_8863: // 01ed:6993
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    if (memoryAGet(ss, bp + 4) == 0x00)
        goto loc_8878;
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_8878: // 01ed:69a8
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_887a() // 01ed:69aa
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_888a;
    sub_ca53();
loc_888a: // 01ed:69ba
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 12000);
    dx = memoryAGet16(ds, bx + 11998);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    cl = 0x00;
loc_88a5: // 01ed:69d5
    al = cl;
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp + 4, al);
    cl++;
    ah = 0x00;
    if (!ax)
        goto loc_88a5;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_8910;
    cl = 0x00;
loc_88d6: // 01ed:6a06
    al = cl;
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19570);
    dx = memoryAGet16(ds, bx + 19568);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp + 4, al);
    cl++;
    if (memoryAGet(ss, bp + 4) == 0x00)
        goto loc_8905;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_88d6;
loc_8905: // 01ed:6a35
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    if (ax)
        goto loc_8954;
    goto loc_891d;
loc_8910: // 01ed:6a40
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx + 1);
    if (al != memoryAGet(ds, 0x856f))
        goto loc_88a5;
loc_891d: // 01ed:6a4d
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(ds, 0x856f);
    memoryASet(es, bx + 1, al);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    push(es);
    si = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, si);
    es = pop();
    memoryASet(es, bx, al);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet(es, bx, 0x01);
loc_8954: // 01ed:6a84
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8959() // 01ed:6a89
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8969;
    sub_ca53();
loc_8969: // 01ed:6a99
    al = memoryAGet(ss, bp + 4);
    memoryASet(ds, 0x8566, al);
    if (al)
        goto loc_8976;
    goto loc_8a80;
loc_8976: // 01ed:6aa6
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_898a;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 10062);
    goto loc_8995;
loc_898a: // 01ed:6aba
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 10030);
loc_8995: // 01ed:6ac5
    memoryASet(ss, bp - 10, al);
    if (memoryAGet(ss, bp - 10) == 0x00)
        goto loc_89a4;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_89a4: // 01ed:6ad4
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 12888);
    dx = memoryAGet16(ds, bx + 12886);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    memoryASet(ss, bp - 9, 0x00);
loc_89c1: // 01ed:6af1
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp + 4, al);
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    ah = 0x00;
    if (!ax)
        goto loc_89c1;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_8a38;
    memoryASet(ss, bp - 9, 0x00);
loc_89f6: // 01ed:6b26
    al = memoryAGet(ss, bp - 9);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 19646);
    dx = memoryAGet16(ds, bx + 19644);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp + 4, al);
    memoryASet(ss, bp - 9, memoryAGet(ss, bp - 9) + 1);
    if (memoryAGet(ss, bp + 4) == 0x00)
        goto loc_8a27;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_89f6;
loc_8a27: // 01ed:6b57
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    if (!ax)
        goto loc_8a48;
    if (memoryAGet(ss, bp + 4) != 0xff)
        goto loc_8a80;
    goto loc_8a80;
loc_8a38: // 01ed:6b68
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(es, bx + 1);
    if (al == memoryAGet(ds, 0x8570))
        goto loc_8a48;
    goto loc_89c1;
loc_8a48: // 01ed:6b78
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    al = memoryAGet(ds, 0x8570);
    memoryASet(es, bx + 1, al);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    push(es);
    si = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(es, si);
    es = pop();
    memoryASet(es, bx + 48, al);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    ax = memoryAGet16(es, bx + 4);
    dx = memoryAGet16(es, bx + 2);
    bx = memoryAGet16(ss, bp - 8);
    es = memoryAGet16(ss, bp - 8 + 2);
    memoryASet16(es, bx + 2, dx);
    memoryASet16(es, bx + 4, ax);
    memoryASet(es, bx, 0x01);
loc_8a80: // 01ed:6bb0
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8a85() // 01ed:6bb5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8a91;
    sub_ca53();
loc_8a91: // 01ed:6bc1
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    memoryASet(ds, 0x7921, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8aa4() // 01ed:6bd4
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8ab0;
    sub_ca53();
loc_8ab0: // 01ed:6be0
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 48);
    memoryASet(ds, 0x8551, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8ac4() // 01ed:6bf4
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8ad0;
    sub_ca53();
loc_8ad0: // 01ed:6c00
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 96);
    memoryASet(ds, 0x79b8, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8ae4() // 01ed:6c14
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8af0;
    sub_ca53();
loc_8af0: // 01ed:6c20
    memoryASet(ds, 0x2810, 0x0f);
    sub_8b65();
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryAGet16(ds, 0xa0d8);
    es = memoryAGet16(ds, 0xa0d8 + 2);
    bx += ax;
    memoryASet(es, bx + 96, 0x00);
    if (memoryAGet(ds, 0x79b8) == 0x01)
        goto loc_8b63;
    if (memoryAGet(ds, 0x79b8) == 0x23)
        goto loc_8b63;
    memoryASet(ds, 0xa0cf, memoryAGet(ds, 0xa0cf) - 1);
    al = memoryAGet(ds, 0xa0cf);
    ah = 0x00;
    if (ax)
        goto loc_8b50;
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8b2e;
    al = 0x0b;
    goto loc_8b30;
loc_8b2e: // 01ed:6c5e
    al = 0x2c;
loc_8b30: // 01ed:6c60
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x8572);
    memoryASet(ds, 0x856f, al);
    al = 0x59;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    memoryASet(ds, 0xa1b1, 0x01);
    memoryASet(ds, 0x8550, 0xf2);
    goto loc_8b63;
loc_8b50: // 01ed:6c80
    if (memoryAGet16(ds, 0x689c) == 0x0004)
        goto loc_8b5b;
    al = 0x0e;
    goto loc_8b5d;
loc_8b5b: // 01ed:6c8b
    al = 0x21;
loc_8b5d: // 01ed:6c8d
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8b63: // 01ed:6c93
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8b65() // 01ed:6c95
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8b71;
    sub_ca53();
loc_8b71: // 01ed:6ca1
    memoryASet(ds, 0xa1a8, 0x02);
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 628);
    cl = 0x04;
    ax = sar(ax, cl);
    memoryASet16(ds, 0x9b9a, ax);
    al = memoryAGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryAGet16(ds, bx + 630);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet16(ds, 0x9ba2, ax);
    if (!(memoryAGet(ds, 0x856e) & 0x01))
        goto loc_8bb0;
    ax = 0x0001;
    goto loc_8bb3;
loc_8bb0: // 01ed:6ce0
    ax = 0x0002;
loc_8bb3: // 01ed:6ce3
    bx = memoryAGet16(ds, 0x08e4);
    es = memoryAGet16(ds, 0x08e4 + 2);
    memoryASet16(es, bx + 30, ax);
    flags.carry = (memoryAGet16(ds, 0xa0d4) + 0x00fa) >= 0x10000;
    memoryASet16(ds, 0xa0d4, memoryAGet16(ds, 0xa0d4) + 0x00fa);
    memoryASet16(ds, 0xa0d6, memoryAGet16(ds, 0xa0d6) + flags.carry);
    if (memoryAGet(ds, 0x79b8) != 0x23)
        goto loc_8bd3;
    memoryASet(ds, 0x791a, memoryAGet(ds, 0x791a) + 1);
    goto loc_8bf4;
loc_8bd3: // 01ed:6d03
    if (memoryAGet(ds, 0x79b8) != 0x2f)
        goto loc_8be2;
    flags.carry = (memoryAGet16(ds, 0xa0d4) + 0x2616) > 0x10000;
    memoryASet16(ds, 0xa0d4, memoryAGet16(ds, 0xa0d4) + 0x2616);
    goto loc_8bef;
loc_8be2: // 01ed:6d12
    if (memoryAGet(ds, 0x79b8) != 0x30)
        goto loc_8bf4;
    flags.carry = (memoryAGet16(ds, 0xa0d4) + 0xc256) > 0x10000;
    memoryASet16(ds, 0xa0d4, memoryAGet16(ds, 0xa0d4) + 0xc256);
loc_8bef: // 01ed:6d1f
    memoryASet16(ds, 0xa0d6, memoryAGet16(ds, 0xa0d6) + flags.carry);
loc_8bf4: // 01ed:6d24
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8bf6() // 01ed:6d26
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8c04;
    sub_ca53();
loc_8c04: // 01ed:6d34
    al = memoryAGet(ds, 0x856e);
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    al = memoryAGet(ds, 0x7921);
    ah = 0x00;
    bx = ax;
    al = memoryAGet(ds, bx + 17302);
    memoryASet(ss, bp - 1, al);
    if (memoryAGet(ss, bp - 1) == 0x00)
        goto loc_8c36;
    al = memoryAGet(ds, 0x7924);
    memoryASet(ds, 0x7922, al);
    al = memoryAGet(ss, bp - 1);
    memoryASet(ds, 0x7923, al);
    al = memoryAGet(ss, bp - 1);
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_8c36: // 01ed:6d66
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8c3a() // 01ed:6d6a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8c46;
    sub_ca53();
loc_8c46: // 01ed:6d76
    al = memoryAGet(ds, 0x8242);
    ah = 0x00;
    if (ax)
        goto loc_8c62;
    al = memoryAGet(ds, 0x7924);
    ah = 0x00;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    bx += ax;
    al = memoryAGet(es, bx);
    push(ax);
    sub_8857();
    sp++;
    sp++;
loc_8c62: // 01ed:6d92
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8c64() // 01ed:6d94
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8c70;
    sub_ca53();
loc_8c70: // 01ed:6da0
    al = memoryAGet(ds, 0x856e);
    memoryASet(ds, 0x856f, al);
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_887a();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8cb3() // 01ed:6de3
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8cc0;
    sub_ca53();
loc_8cc0: // 01ed:6df0
    if (memoryAGet16(ds, 0x689c) == 0x8000)
        goto loc_8cde;
    sub_a7b5();
    si = ax;
    ax = memoryAGet16(ds, 0x689c);
    ax &= si;
    memoryASet16(ds, 0x689c, ax);
    push(memoryAGet16(ds, 0x689c));
    sub_a7ee();
    sp++;
    sp++;
loc_8cde: // 01ed:6e0e
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8ce1() // 01ed:6e11
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8ced;
    sub_ca53();
loc_8ced: // 01ed:6e1d
    if (memoryAGet16(ds, 0x689c) == 0x8000)
        goto loc_8cfe;
    al = memoryAGet(ss, bp + 4);
    push(ax);
    sub_8d00();
    sp++;
    sp++;
loc_8cfe: // 01ed:6e2e
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8d00() // 01ed:6e30
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8d0c;
    sub_ca53();
loc_8d0c: // 01ed:6e3c
    if (memoryAGet16(ds, 0x689c) != 0x0004)
        goto loc_8d3c;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryAGet(ds, bx + 10159);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryAGet(ds, bx + 10158);
    ah = 0x00;
    push(ax);
    sub_a8d7();
    sp += 0x0004;
    goto loc_8fb5;
loc_8d3c: // 01ed:6e6c
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    ax--;
    bx = ax;
    if (bx <= 0x0014)
        goto loc_8d4c;
    goto loc_8fb5;
loc_8d4c: // 01ed:6e7c
    bx <<= 1;
    stop(/*2*/); // (jmp word ptr cs:[bx + 0x70e7]) jump Indirect memoryAGet16(cs, bx + 28903)
    //   gap of 610 bytes
loc_8fb5: // 01ed:70e5
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8fe1() // 01ed:7111
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_8fed;
    sub_ca53();
loc_8fed: // 01ed:711d
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8ff0() // 01ed:7120
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryAGet(ss, bp + 4);
    ah = 0x00;
    interrupt(0x10);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_9105() // 01ed:7235
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    push(di);
    memoryASet(ss, bp - 1, 0x00);
    si = 0;
    memoryASet16(ss, bp - 6, 0x0000);
    memoryASet16(ss, bp - 4, 0x0000);
    goto loc_919f;
loc_9120: // 01ed:7250
    if ((short)memoryAGet16(ss, bp + 14) < (short)0x0000)
        goto loc_913d;
    if ((short)memoryAGet16(ss, bp + 14) > (short)0x0000)
        goto loc_912f;
    if (memoryAGet16(ss, bp + 12) <= 0xfa00)
        goto loc_913d;
loc_912f: // 01ed:725f
    di = 0xfa00;
    flags.carry = memoryAGet16(ss, bp + 12) < 0xfa00;
    memoryASet16(ss, bp + 12, memoryAGet16(ss, bp + 12) - 0xfa00);
    memoryASet16(ss, bp + 14, memoryAGet16(ss, bp + 14) - flags.carry);
    goto loc_914a;
loc_913d: // 01ed:726d
    di = memoryAGet16(ss, bp + 12);
    memoryASet16(ss, bp + 12, 0x0000);
    memoryASet16(ss, bp + 14, 0x0000);
loc_914a: // 01ed:727a
    push(di);
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    callIndirect(cs*16+memoryAGet16(ss, bp + 4));
    sp += 0x0008;
    si = ax;
    if (si == di)
        goto loc_9165;
    ax = 0x0001;
    goto loc_9167;
loc_9165: // 01ed:7295
    ax = 0;
loc_9167: // 01ed:7297
    memoryASet(ss, bp - 1, al);
    flags.carry = (memoryAGet16(ss, bp - 6) + si) >= 0x10000;
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) + si);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + flags.carry);
    ax = memoryAGet16(ss, bp + 8);
    memoryASet16(ss, bp - 10, ax);
    memoryASet16(ss, bp - 8, 0x0000);
    flags.carry = (memoryAGet16(ss, bp - 10) + si) >= 0x10000;
    memoryASet16(ss, bp - 10, memoryAGet16(ss, bp - 10) + si);
    memoryASet16(ss, bp - 8, memoryAGet16(ss, bp - 8) + flags.carry);
    ax = memoryAGet16(ss, bp - 10);
    memoryASet16(ss, bp + 8, ax);
    memoryASet16(ss, bp - 10, 0x0000);
    ax = memoryAGet16(ss, bp - 10);
    ax |= memoryAGet16(ss, bp - 8);
    if (!ax)
        goto loc_919f;
    flags.carry = (memoryAGet16(ss, bp + 8) + 0x0000) >= 0x10000;
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) + 0x0000);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) + (0x1000 + flags.carry));
loc_919f: // 01ed:72cf
    ax = memoryAGet16(ss, bp + 12);
    ax |= memoryAGet16(ss, bp + 14);
    if (!ax)
        goto loc_91b3;
    al = memoryAGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_91b3;
    goto loc_9120;
loc_91b3: // 01ed:72e3
    dx = memoryAGet16(ss, bp - 4);
    ax = memoryAGet16(ss, bp - 6);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_91bf() // 01ed:72ef
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0xa1b8, ax);
    push(memoryAGet16(ss, bp + 4));
    sub_bfb9();
    sp++;
    sp++;
    memoryASet(ds, 0x4ce6, 0x01);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_91d7() // 01ed:7307
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0xa1b4, dx);
    memoryASet16(ds, 0xa1b6, ax);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_91e9() // 01ed:7319
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(memoryAGet16(ss, bp + 4));
    sub_b75e();
    sp++;
    sp++;
    si = ax;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_923f() // 01ed:736f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 4);
    memoryASet(ss, bp - 1, 0x00);
    al = memoryAGet(ds, 0x4ce6);
    ah = 0x00;
    if (ax)
        goto loc_925c;
    memoryASet16(ds, 0xa1b8, 0x74d4);
loc_925c: // 01ed:738c
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryAGet16(ds, 0xa1b4);
    es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    if (memoryAGet(es, bx + 4) == 0x7a)
        goto loc_92b9;
loc_9270: // 01ed:73a0
    push(memoryAGet16(ss, bp + 6));
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryAGet16(ds, 0xa1b4);
    es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 4);
    push(ax);
    sub_93a5();
    sp += 0x0004;
    si = ax;
    if (!ax)
        goto loc_92ab;
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryAGet16(ds, 0xa1b4);
    es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 4);
    ah = 0x00;
    push(ax);
    callIndirect(cs*16+memoryAGet16(ds, 0xa1b8));
    sp++;
    sp++;
loc_92ab: // 01ed:73db
    if (!si)
        goto loc_92b9;
    al = memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
    if (al < 0x0a)
        goto loc_9270;
loc_92b9: // 01ed:73e9
    if (memoryAGet(ss, bp - 1) > 0x0a)
        goto loc_9326;
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryAGet16(ds, 0xa1b4);
    es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 4);
    memoryASet(ds, 0x4ce7, al);
loc_92d3: // 01ed:7403
    ax = 0x0180;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    ax |= 0x8004;
    push(ax);
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryAGet16(ds, 0xa1b4);
    es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    push(memoryAGet16(es, bx + 2));
    push(memoryAGet16(es, bx));
    sub_c0ec();
    sp += 0x0008;
    si = ax;
    if ((short)ax >= 0)
        goto loc_9318;
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryAGet16(ds, 0xa1b4);
    es = memoryAGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryAGet(es, bx + 4);
    ah = 0x00;
    push(ax);
    callIndirect(cs*16+memoryAGet16(ds, 0xa1b8));
    sp++;
    sp++;
loc_9318: // 01ed:7448
    if ((short)si >= 0)
        goto loc_9326;
    al = memoryAGet(ss, bp - 1);
    memoryASet(ss, bp - 1, memoryAGet(ss, bp - 1) + 1);
    if (al < 0x0a)
        goto loc_92d3;
loc_9326: // 01ed:7456
    ax = si;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_932e() // 01ed:745e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = 0xa3ae;
    push(ax);
    sub_9105();
    sp += 0x000c;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    ax = memoryAGet16(ss, bp - 4);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_93a5() // 01ed:74d5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    ax = 0x0180;
    push(ax);
    ax = memoryAGet16(ss, bp + 6);
    ax |= 0x8004;
    push(ax);
    push(ds);
    ax = 0x4ce8;
    push(ax);
    sub_c0ec();
    sp += 0x0008;
    si = ax;
    if ((short)si <= 0)
        goto loc_93fc;
    ax = 0;
    push(ax);
    dx = 0x0004;
    push(ax);
    push(dx);
    push(ds);
    ax = 0xa1ba;
    push(ax);
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    al = memoryAGet(ds, 0xa1ba);
    ah = 0x00;
    dl = memoryAGet(ss, bp + 4);
    dh = 0x00;
    ax -= dx;
    si = ax;
    if (memoryAGet(ds, 0xa1ba) == 0x7a)
        goto loc_93fa;
    if (memoryAGet(ss, bp + 4) != 0x7a)
        goto loc_93fc;
loc_93fa: // 01ed:752a
    si = 0;
loc_93fc: // 01ed:752c
    ax = si;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_9402() // 01ed:7532
{
    CStackGuard sg(0, false);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(si);
    push(di);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    es = ax;
    flags.direction = false;
    di = 0x4cf2;
    cx = 0x0020;
    ax = 0;
    rep_stosw<MemAuto, DirAuto>();
    ax = 0x0000;
    sub_96a9();
    ax = 0x0001;
    sub_96a9();
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
}
void sub_9433() // 01ed:7563
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    push(es);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 4);
    ah = 0;
    si = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    sub_944b();
    di = pop();
    si = pop();
    es = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_944b() // 01ed:757b
{
    CStackGuard sg(0, false);
    push(ds);
    dx = 0x1228;
    ds = dx;
    if (al < 0x10)
        goto loc_945b;
    dx = 0x7676;
    goto loc_94fa;
loc_945b: // 01ed:758b
    ax += ax;
    ax += ax;
    bx = 0x1228;
    ds = bx;
    bx = 0x4cf2;
    bx += ax;
    memoryASet16(ds, bx, si);
    ax = es;
    memoryASet16(ds, bx + 2, ax);
    ds = pop();
    return;
    //   gap of 136 bytes
loc_94fa: // 01ed:762a
    ax = cs;
    ds = ax;
    ah = 0x09;
    interrupt(0x21);
loc_9502: // 01ed:7632
    goto loc_9502;
}
void sub_9472() // 01ed:75a2
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(ds);
    push(es);
    push(si);
    push(di);
    dx = 0x1228;
    ds = dx;
    ah = 0;
    if (ax < 0x0010)
        goto loc_948f;
    dx = 0x76c8;
    goto loc_94fa;
    stop(/*7*/); //   
loc_948f: // 01ed:75bf
    ax += ax;
    ax += ax;
    bx = 0x4cf2;
    bx += ax;
    si = memoryAGet16(ds, bx);
    es = memoryAGet16(ds, bx + 2);
    ax = es;
    ax |= si;
    if (ax)
        goto loc_94a5;
    dx = 0x7634;
    goto loc_94fa;
loc_94a5: // 01ed:75d5
    dx = 0x0000;
loc_94a8: // 01ed:75d8
    al = memoryAGet(es, si);
    si++;
    if (al >= 0xfd)
        goto loc_94bb;
    push(dx);
    push(si);
    sub_960c();
    si = pop();
    dx = pop();
    dl |= ch;
    goto loc_94a8;
loc_94bb: // 01ed:75eb
    if (al == 0xff)
        goto loc_94f1;
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx = memoryAGet16(ds, 0x4d42);
loc_94c9: // 01ed:75f9
    al = memoryAGet(es, si);
    si++;
    if (al >= 0xfd)
        goto loc_94e6;
    dh = al;
loc_94d3: // 01ed:7603
    al = memoryAGet(es, si);
    si++;
    if (al >= 0xfd)
        goto loc_94e6;
    al &= 0x7f;
    al = memory(ds, bx+al);
    if (al == 0)
        goto loc_94d3;
    dl |= dh;
    goto loc_94d3;
loc_94e6: // 01ed:7616
    if (al == 0xfe)
        goto loc_94f0;
    if (al != 0xff)
        goto loc_94c9;
    goto loc_94f1;
loc_94f0: // 01ed:7620
    ds = pop();
loc_94f1: // 01ed:7621
    di = pop();
    si = pop();
    es = pop();
    ds = pop();
    al = dl;
    ah = 0;
    assert(pop() == 0x7777);
    return;
loc_94fa: // 01ed:762a
    ax = cs;
    ds = ax;
    ah = 0x09;
    interrupt(0x21);
loc_9502: // 01ed:7632
    goto loc_9502;
}
void sub_960c() // 01ed:773c
{
    CStackGuard sg(0, false);
    push(ds);
    bx = 0x1228;
    ds = bx;
    push(ax);
    sub_9731();
    bx = pop();
    ch = 0;
    if (ax == 0xffff)
        goto loc_9665;
    bx &= 0x0001;
    if (bx == 0)
        goto loc_9667;
    if (ah >= memoryAGet(ds, 0x4d3b))
        goto loc_962e;
    ch |= 0x04;
    goto loc_9637;
loc_962e: // 01ed:775e
    if (ah < memoryAGet(ds, 0x4d3d))
        goto loc_9637;
    ch |= 0x08;
loc_9637: // 01ed:7767
    if (al >= memoryAGet(ds, 0x4d3a))
        goto loc_9642;
    ch |= 0x01;
    goto loc_964b;
loc_9642: // 01ed:7772
    if (al < memoryAGet(ds, 0x4d3c))
        goto loc_964b;
    ch |= 0x02;
loc_964b: // 01ed:777b
    dx = 0x0201;
    in(al, dx);
    al = ~al;
    if (!(al & 0x40))
        goto loc_9658;
    ch |= 0x10;
loc_9658: // 01ed:7788
    if (!(al & 0x80))
        goto loc_965f;
    ch |= 0x20;
loc_965f: // 01ed:778f
    memoryASet(ds, 0x4d35, ch);
loc_9665: // 01ed:7795
    ds = pop();
    return;
loc_9667: // 01ed:7797
    if (ah >= memoryAGet(ds, 0x4d37))
        goto loc_9672;
    ch |= 0x04;
    goto loc_967b;
loc_9672: // 01ed:77a2
    if (ah < memoryAGet(ds, 0x4d39))
        goto loc_967b;
    ch |= 0x08;
loc_967b: // 01ed:77ab
    if (al >= memoryAGet(ds, 0x4d36))
        goto loc_9686;
    ch |= 0x01;
    goto loc_968f;
loc_9686: // 01ed:77b6
    if (al < memoryAGet(ds, 0x4d38))
        goto loc_968f;
    ch |= 0x02;
loc_968f: // 01ed:77bf
    dx = 0x0201;
    in(al, dx);
    al = ~al;
    if (!(al & 0x10))
        goto loc_969c;
    ch |= 0x10;
loc_969c: // 01ed:77cc
    if (!(al & 0x20))
        goto loc_96a3;
    ch |= 0x20;
loc_96a3: // 01ed:77d3
    memoryASet(ds, 0x4d34, ch);
    goto loc_9665;
}
void sub_96a9() // 01ed:77d9
{
    CStackGuard sg(0, false);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = 0x4dca;
    if (ax == 0)
        goto loc_96b9;
    bx = 0x4dcb;
loc_96b9: // 01ed:77e9
    cl = 0x01;
    memoryASet(ds, bx, cl);
    bx = ax;
    push(ax);
    push(bx);
    sub_9731();
    bx = pop();
    cx = pop();
    if (ax == 0xffff)
        goto loc_971a;
    if (ah < 0x02)
        goto loc_970e;
    if (al < 0x02)
        goto loc_970e;
    cx = ax;
    al >>= 1;
    ah >>= 1;
    dx = ax;
    cx += cx;
    cx -= dx;
    ax = 0x1228;
    ds = ax;
    bx &= 0x0001;
    if (bx == 0)
        goto loc_96fc;
    memoryASet(ds, 0x4d3a, dl);
    memoryASet(ds, 0x4d3b, dh);
    memoryASet(ds, 0x4d3c, cl);
    memoryASet(ds, 0x4d3d, ch);
    goto loc_970c;
loc_96fc: // 01ed:782c
    memoryASet(ds, 0x4d36, dl);
    memoryASet(ds, 0x4d37, dh);
    memoryASet(ds, 0x4d38, cl);
    memoryASet(ds, 0x4d39, ch);
loc_970c: // 01ed:783c
    ds = pop();
    return;
loc_970e: // 01ed:783e
    push(cx);
    cx = 0x0000;
loc_9712: // 01ed:7842
    if (--cx)
        goto loc_9712;
    cx = pop();
    ax = 0xffff;
    goto loc_971c;
loc_971a: // 01ed:784a
    al = 0;
loc_971c: // 01ed:784c
    bx = 0x4dca;
    if (cx == 0)
        goto loc_9726;
    bx = 0x4dcb;
loc_9726: // 01ed:7856
    memoryASet(ds, bx, al);
    goto loc_970c;
}
void sub_9731() // 01ed:7861
{
    CStackGuard sg(0, false);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    push(ds);
    bx = 0x1228;
    ds = bx;
    al &= 0x01;
    if (al == 0)
        goto loc_9751;
    bx = 0x0408;
    al = memoryAGet(ds, 0x4dcb);
    al--;
    if (al == 0)
        goto loc_9765;
    al++;
    if (al == 0)
        goto loc_974e;
    goto loc_97fe;
loc_974e: // 01ed:787e
    goto loc_9837;
loc_9751: // 01ed:7881
    bx = 0x0102;
    al = memoryAGet(ds, 0x4dca);
    al--;
    if (al == 0)
        goto loc_9765;
    al++;
    if (al == 0)
        goto loc_9762;
    goto loc_97fe;
loc_9762: // 01ed:7892
    goto loc_9823;
loc_9765: // 01ed:7895
    dx = 0x0201;
    cx = 0;
loc_976a: // 01ed:789a
    in(al, dx);
    if (--cx && bl & al)
        goto loc_976a;
    if (cx == 0)
        goto loc_9775;
    if (--cx && bh & al)
        goto loc_976a;
loc_9775: // 01ed:78a5
    if (cx == 0)
        goto loc_9779;
    goto loc_977c;
loc_9779: // 01ed:78a9
    goto loc_97fe;
loc_977c: // 01ed:78ac
    dx = 0x0201;
    out(dx, al);
    in(al, dx);
    if (bh & al)
        goto loc_97aa;
    if (bl & al)
        goto loc_97aa;
    al = 0x06;
    out(0x0043, al);
    push(cx);
    cx = 0x0064;
loc_9791: // 01ed:78c1
    if (--cx)
        goto loc_9791;
    cx = pop();
loc_9794: // 01ed:78c4
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    ah &= 0x10;
    if (ah == 0)
        goto loc_9794;
loc_979f: // 01ed:78cf
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    ah &= 0x10;
    if (ah != 0)
        goto loc_979f;
loc_97aa: // 01ed:78da
    cx = 0;
    memoryASet16(ds, 0x4d32, cx);
    cx = 0x03e8;
loc_97b3: // 01ed:78e3
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    ah &= 0x10;
    if (ah == 0)
        goto loc_97b3;
    memoryASet16(ds, 0x4d32, memoryAGet16(ds, 0x4d32) + 1);
    in(al, dx);
    if (bl == 0)
        goto loc_97cf;
    if (!(bl & al))
        goto loc_97f0;
    if (bh == 0)
        goto loc_97d3;
loc_97cf: // 01ed:78ff
    if (!(bh & al))
        goto loc_97e2;
loc_97d3: // 01ed:7903
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    if (ah & 0x10)
        goto loc_97d3;
    if (--cx)
        goto loc_97b3;
    goto loc_97fe;
loc_97e2: // 01ed:7912
    ax = memoryAGet16(ds, 0x4d32);
    memoryASet16(ds, 0x4dc6, ax);
    bh = 0;
    if (bl == 0)
        goto loc_9803;
    goto loc_97d3;
loc_97f0: // 01ed:7920
    ax = memoryAGet16(ds, 0x4d32);
    memoryASet16(ds, 0x4dc8, ax);
    bl = 0;
    if (bh == 0)
        goto loc_9803;
    goto loc_97d3;
loc_97fe: // 01ed:792e
    ax = 0xffff;
    goto loc_9820;
loc_9803: // 01ed:7933
    dx = memoryAGet16(ds, 0x4dc6);
    if ((short)dx >= 0)
        goto loc_980d;
    dx = 0;
loc_980d: // 01ed:793d
    cl = 0x01;
    dx >>= cl;
    ax = memoryAGet16(ds, 0x4dc8);
    if ((short)ax >= 0)
        goto loc_981a;
    ax = 0;
loc_981a: // 01ed:794a
    cl = 0x01;
    ax >>= cl;
    ah = dl;
loc_9820: // 01ed:7950
    ds = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    return;
loc_9823: // 01ed:7953
    dx = 0x0201;
    in(al, dx);
    al &= 0x03;
    if (al != 0)
        goto loc_97fe;
    al = 0x01;
    memoryASet(ds, 0x4dca, al);
    ax = 0x0000;
    goto loc_9847;
loc_9835: // 01ed:7965
    goto loc_97fe;
loc_9837: // 01ed:7967
    dx = 0x0201;
    in(al, dx);
    al &= 0x0c;
    if (al != 0)
        goto loc_9835;
    al = 0x01;
    memoryASet(ds, 0x4dcb, al);
    ax = 0x0001;
loc_9847: // 01ed:7977
    push(bx);
    push(ax);
    ax = 0xffff;
    ax = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_9835;
    push(bx);
    sub_9731();
    bx = pop();
    goto loc_9820;
}
void sub_985a() // 01ed:798a
{
    CStackGuard sg(0, false);
    push(si);
    push(di);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    es = ax;
    flags.direction = false;
    di = memoryAGet16(ds, 0x4d42);
    cx = 0x0040;
    ax = 0x0000;
    rep_stosw<MemAuto, DirAuto>();
    es = pop();
    sub_99d1();
    ax = memoryAGet16(ds, 0x4dc4);
    if (ax != 0)
        goto loc_98b2;
    ax++;
    memoryASet16(ds, 0x4dc4, ax);
    push(ds);
    push(es);
    al = 0x09;
    ah = 0x35;
    interrupt(0x21);
    dx = es;
    ax = 0x01ed;
    es = ax;
    memoryASet16(ds, 0x4d3e, bx);
    memoryASet16(es, 0x7a6d, bx);
    memoryASet16(ds, 0x4d40, dx);
    memoryASet16(es, 0x7a6f, dx);
    dx = 0x79e6;
    bx = 0x01ed;
    ds = bx;
    al = 0x09;
    ah = 0x25;
    interrupt(0x21);
    es = pop();
    ds = pop();
loc_98b2: // 01ed:79e2
    ds = pop();
    di = pop();
    si = pop();
}
void sub_98b6() // 01ed:79e6
{
    stop(/*unk call conv*/);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    push(ax);
    push(bx);
    push(cx);
    push(ds);
    push(di);
    push(si);
    push(dx);
    ax = 0x0040;
    ds = ax;
    bx = 0x0080;
    di = memoryAGet16(ds, bx);
    si = memoryAGet16(ds, bx + 2);
    bx = 0x001a;
    cx = memoryAGet16(ds, bx);
    dx = memoryAGet16(ds, bx + 2);
    si -= di;
    flags.carry = dx < cx;
    dx -= cx;
    if (!flags.carry)
        goto loc_98de;
    si -= dx;
    dx = si;
loc_98de: // 01ed:7a0e
    if (dx < 0x0010)
        goto loc_98ea;
    ax = memoryAGet16(cs, 0x7a71);
    memoryASet16(ds, bx + 2, ax);
loc_98ea: // 01ed:7a1a
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(cs, 0x7a71, ax);
    in(al, 0x60);
    if (al == 0xff)
        goto loc_9923;
    cl = al;
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x4d42);
    ah = 0x00;
    al &= 0x7f;
    di = ax;
    if (!(cl & 0x80))
        goto loc_990f;
    al = 0;
loc_990f: // 01ed:7a3f
    memoryASet(ds, bx + di, al);
    push(cs);
    cs = memoryAGet16(cs, 0x7a73 + 2);
    callIndirect(memoryAGet16(cs, 0x7a73 + 2)*16 + memoryAGet16(cs, 0x7a73));
    assert(cs == 0x01ed);
    dx = pop();
    si = pop();
    di = pop();
    ds = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    stop(); // ljmp cs:[0x7a6d]
loc_9923: // 01ed:7a53
    in(al, 0x61);
    ah = al;
    al |= 0x80;
    out(0x0061, al);
    al = ah;
    out(0x0061, al);
    dx = pop();
    si = pop();
    di = pop();
    ds = pop();
    cx = pop();
    bx = pop();
    al = 0x20;
    out(0x0020, al);
    ax = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    stop(); // iret 
}
void sub_9947() // 01ed:7a77
{
    CStackGuard sg(0, false);
    push(si);
    push(di);
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4dc4);
    if (ax == 0)
        goto loc_9980;
    ax = 0;
    memoryASet16(ds, 0x4dc4, ax);
    push(ds);
    push(es);
    dx = memoryAGet16(ds, 0x4d3e);
    bx = memoryAGet16(ds, 0x4d40);
    ds = bx;
    al = 0x09;
    ah = 0x25;
    interrupt(0x21);
    es = pop();
    ds = pop();
    sub_99d1();
loc_9972: // 01ed:7aa2
    ah = 0x0b;
    interrupt(0x21);
    if (al == 0)
        goto loc_9980;
    ah = 0x07;
    interrupt(0x21);
    goto loc_9972;
loc_9980: // 01ed:7ab0
    ds = pop();
    di = pop();
    si = pop();
}
void sub_9984() // 01ed:7ab4
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(ds);
    push(bx);
    push(di);
    bx = 0x1228;
    ds = bx;
    di = memoryAGet16(ds, 0x4d42);
    ah = 0;
    al &= 0x7f;
    di += ax;
    al = memoryAGet(ds, di);
    di = pop();
    bx = pop();
    ds = pop();
    assert(pop() == 0x7777);
}
void sub_998b() // 01ed:7abb
{
    CStackGuard sg(0, false);
    push(ds);
    push(bx);
    push(di);
    bx = 0x1228;
    ds = bx;
    di = memoryAGet16(ds, 0x4d42);
    ah = 0;
    al &= 0x7f;
    di += ax;
    al = memoryAGet(ds, di);
    di = pop();
    bx = pop();
    ds = pop();
    flags.zero = ax == 0; // todo CICO skipped instruction before end
}
void sub_99d1() // 01ed:7b01
{
    CStackGuard sg(0, false);
    push(ds);
    push(ax);
    push(bx);
    ax = 0x0040;
    ds = ax;
    bx = 0x0080;
    ax = memoryAGet16(ds, bx);
    bx = 0x001a;
    memoryASet16(ds, bx, ax);
    memoryASet16(ds, bx + 2, ax);
    bx = pop();
    ax = pop();
    ds = pop();
}
void sub_9a1a() // 01ed:7b4a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cbd9();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a2a() // 01ed:7b5a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryAGet16(ss, bp + 6);
    si = memoryAGet16(ss, bp + 4);
    bx = memoryAGet16(ss, bp + 10);
    ax = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 14);
    cx = memoryAGet16(ss, bp + 12);
    bp = pop();
    push(cs);
    cs = 0x0e15;
    sub_e150();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a63() // 01ed:7b93
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bx = memoryAGet16(ss, bp + 8);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cc41();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a77() // 01ed:7ba7
{
    CStackGuard sg(0, false);
    push(cs);
    cs = 0x0ca6;
    sub_cc5f();
    assert(cs == 0x01ed);
}
void sub_9a7d() // 01ed:7bad
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cc7b();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a8d() // 01ed:7bbd
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    cl = memoryAGet(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cc92();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a9a() // 01ed:7bca
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cd11();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9aa7() // 01ed:7bd7
{
    CStackGuard sg(0, false);
    push(cs);
    cs = 0x0ca6;
    sub_cd2e();
    assert(cs == 0x01ed);
}
void sub_9aad() // 01ed:7bdd
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cdb1();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9aca() // 01ed:7bfa
{
    CStackGuardFar sg(0, false);
    sub_998b();
    cs = pop();
}
void sub_9bae() // 01ed:7cde
{
    CStackGuard sg(0, false);
    al = memoryAGet(ds, 0x54d4);
    ah = 0;
    if (al == 0)
        goto loc_9bba;
    return;
loc_9bba: // 01ed:7cea
    sub_9e80();
    memoryASet16(ds, 0x54d6, ax);
    cx = 0x0006;
loc_9bc3: // 01ed:7cf3
    push(cx);
    ax = 0x0000;
    bx = cx;
    bx--;
    sub_9d32();
    cx = pop();
    if (--cx)
        goto loc_9bc3;
    bx = 0x54f6;
    cx = 0x0010;
    ax = 0;
loc_9bd8: // 01ed:7d08
    memoryASet16(ds, bx, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_9bd8;
    bx = 0x5516;
    cx = 0x0010;
    ax = 0xffff;
loc_9be8: // 01ed:7d18
    memoryASet16(ds, bx, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_9be8;
    cx = 0x0012;
    ax = memoryAGet16(ds, 0x54d6);
    if (ax == 0)
        goto loc_9c22;
    if (ax >= 0xf800)
        goto loc_9c22;
    if (ax < 0x0951)
        goto loc_9c22;
    cx = ax;
    cx >>= 1;
    cx >>= 1;
    ax = 0xffff;
    dx = 0;
    div(cx);
    ax += ax;
    cx = ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += cx;
    ax >>= 1;
    ax >>= 1;
    cx = ax;
loc_9c22: // 01ed:7d52
    ax = cx;
    bx = 0x0000;
    dx = 0x01ed;
    cx = 0x7e7a;
    sub_9d32();
    ax = 0x0032;
    bx = 0x0001;
    dx = 0x01ed;
    cx = 0x7e80;
    sub_9d32();
    push(es);
    ah = 0x35;
    al = 0x08;
    interrupt(0x21);
    memoryASet16(ds, 0x54d0, bx);
    bx = es;
    memoryASet16(ds, 0x54d2, bx);
    es = pop();
    ax = 0x0001;
    memoryASet(ds, 0x54d4, al);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    push(ds);
    ax = 0x01ed;
    ds = ax;
    dx = 0x7c02;
    ah = 0x25;
    al = 0x08;
    interrupt(0x21);
    ds = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    sub_9c82();
    push(es);
    ax = 0x350f;
    interrupt(0x21);
    memoryASet16(ds, 0x54d8, bx);
    bx = es;
    memoryASet16(ds, 0x54da, bx);
    es = pop();
    ax = 0x0001;
}
void sub_9c82() // 01ed:7db2
{
    CStackGuard sg(0, false);
    ax = 0x0951;
    sub_9e6a();
}
void sub_9c89() // 01ed:7db9
{
    CStackGuard sg(0, false);
    al = memoryAGet(ds, 0x54d4);
    ah = 0;
    if (al == 0)
        return;
    push(ds);
    dx = memoryAGet16(ds, 0x54d8);
    ds = memoryAGet16(ds, 0x54d8 + 2);
    ah = 0x25;
    al = 0x0f;
    ds = pop();
    ax = memoryAGet16(ds, 0x54d6);
    sub_9e6a();
    push(ds);
    dx = memoryAGet16(ds, 0x54d0);
    ds = memoryAGet16(ds, 0x54d0 + 2);
    ah = 0x25;
    al = 0x08;
    interrupt(0x21);
    ds = pop();
    ax = 0x0000;
    memoryASet(ds, 0x54d4, al);
    ax = 0x0001;
}
void sub_9cc9() // 01ed:7df9
{
    CStackGuard sg(0, false);
    if ((short)bx < 0)
        goto loc_9ce5;
    if ((short)bx >= (short)0x0004)
        goto loc_9ce5;
    bx += 0x0002;
    if ((short)ax < 0)
        goto loc_9ce5;
    if ((short)ax >= (short)0x01f4)
        goto loc_9ce5;
    sub_9d32();
    ax = 0x0001;
    return;
loc_9ce5: // 01ed:7e15
    ax = 0;
}
void sub_9ce8() // 01ed:7e18
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    bx = ax;
    if ((short)bx < 0)
        goto loc_9d0a;
    if ((short)bx >= (short)0x0004)
        goto loc_9d0a;
    bx += 0x0002;
    ax = 0;
    cx = ax;
    dx = ax;
    sub_9d32();
    ax = 0x0001;
    assert(pop() == 0x7777);
    return;
loc_9d0a: // 01ed:7e3a
    ax = 0;
    assert(pop() == 0x7777);
}
void sub_9cef() // 01ed:7e1f
{
    CStackGuard sg(0, false);
    bx = ax;
    if ((short)bx < 0)
        goto loc_9d0a;
    if ((short)bx >= (short)0x0004)
        goto loc_9d0a;
    bx += 0x0002;
    ax = 0;
    cx = ax;
    dx = ax;
    sub_9d32();
    ax = 0x0001;
    return;
loc_9d0a: // 01ed:7e3a
    ax = 0;
}
void sub_9d32() // 01ed:7e62
{
    CStackGuard sg(0, false);
    bx += bx;
    bx += bx;
    bx += bx;
    bx += 0x549c;
    memoryASet16(ds, bx, ax);
    ax = 0;
    memoryASet16(ds, bx + 2, ax);
    memoryASet16(ds, bx + 6, cx);
    memoryASet16(ds, bx + 4, dx);
}
void sub_9e60() // 01ed:7f90
{
    CStackGuard sg(0, false);
    sub_9e63();
    sub_9e66();
    sub_9e69();
}
void sub_9e63() // 01ed:7f93
{
    CStackGuard sg(0, false);
    sub_9e66();
    sub_9e69();
}
void sub_9e66() // 01ed:7f96
{
    CStackGuard sg(0, false);
    sub_9e69();
}
void sub_9e69() // 01ed:7f99
{
    CStackGuard sg(0, false);
}
void sub_9e6a() // 01ed:7f9a
{
    CStackGuard sg(0, false);
    push(ax);
    al = 0x36;
    out(0x0043, al);
    sub_9e60();
    ax = pop();
    out(0x0040, al);
    sub_9e60();
    al = ah;
    out(0x0040, al);
    sub_9e60();
}
void sub_9e80() // 01ed:7fb0
{
    CStackGuard sg(0, false);
    push(bx);
    push(cx);
    cx = 0x0019;
    bx = 0;
    al = 0x06;
    out(0x0043, al);
    sub_9e60();
loc_9e8e: // 01ed:7fbe
    flags.interrupts = false;
    in(al, 0x40);
    ah = al;
    sub_9e60();
    in(al, 0x40);
    flags.interrupts = true;
    if (al < bh)
        goto loc_9e8e;
    if (al != bh)
        goto loc_9ea3;
    if (bl >= ah)
        goto loc_9ea5;
loc_9ea3: // 01ed:7fd3
    bl = ah;
loc_9ea5: // 01ed:7fd5
    bh = al;
    if (--cx)
        goto loc_9e8e;
    ax = bx;
    cx = pop();
    bx = pop();
}
void sub_9f5e() // 01ed:808e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ec2;
    sub_ec20();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9f6e() // 01ed:809e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 6);
    bp = pop();
    push(cs);
    cs = 0x0ec2;
    sub_ec52();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9f7c() // 01ed:80ac
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_d4d3();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9f8c() // 01ed:80bc
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_d7d7();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_a485() // 01ed:85b5
{
    CStackGuard sg(0, false);
    push(bx);
    bx = memoryAGet16(cs, 0x85b3);
    if (bx != 0x0000)
        goto loc_a495;
    sub_afe5();
    goto loc_a4a9;
loc_a495: // 01ed:85c5
    if (bx != 0x0004)
        goto loc_a49f;
    sub_a9a0();
    goto loc_a4a9;
loc_a49f: // 01ed:85cf
    if (bx != 0x0001)
        goto loc_a4a9;
    sub_acff();
loc_a4a9: // 01ed:85d9
    bx = pop();
}
void sub_a4ab() // 01ed:85db
{
    CStackGuard sg(0, false);
    push(ax);
    ax = memoryAGet16(cs, 0x85b3);
    if (ax != 0x0000)
        goto loc_a4ba;
    sub_b09f();
    goto loc_a4ce;
loc_a4ba: // 01ed:85ea
    if (ax != 0x0004)
        goto loc_a4c4;
    sub_a9c6();
    goto loc_a4ce;
loc_a4c4: // 01ed:85f4
    if (ax != 0x0001)
        goto loc_a4ce;
    sub_ad18();
loc_a4ce: // 01ed:85fe
    ax = pop();
}
void sub_a4d0() // 01ed:8600
{
    CStackGuard sg(0, false);
    push(cx);
    cx = memoryAGet16(cs, 0x85b3);
    if (cx != 0x0000)
        goto loc_a4e0;
    sub_b0a7();
    goto loc_a4f4;
loc_a4e0: // 01ed:8610
    if (cx != 0x0004)
        goto loc_a4ea;
    sub_a9d4();
    goto loc_a4f4;
loc_a4ea: // 01ed:861a
    if (cx != 0x0001)
        goto loc_a4f4;
    sub_ad20();
loc_a4f4: // 01ed:8624
    cx = pop();
}
void sub_a4f6() // 01ed:8626
{
    CStackGuard sg(0, false);
    push(cx);
    cx = memoryAGet16(cs, 0x85b3);
    if (cx != 0x0000)
        goto loc_a506;
    sub_b0af();
    goto loc_a51a;
loc_a506: // 01ed:8636
    if (cx != 0x0004)
        goto loc_a510;
    sub_a9dd();
    goto loc_a51a;
loc_a510: // 01ed:8640
    if (cx != 0x0001)
        goto loc_a51a;
    sub_ad28();
loc_a51a: // 01ed:864a
    cx = pop();
}
void sub_a5b9() // 01ed:86e9
{
    CStackGuard sg(0, false);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    ax = memoryAGet16(cs, 0x85a3);
    cx = 0x0f42;
    mul(cx);
    cx = memoryAGet16(cs, 0x85a5);
    bx = memoryAGet16(cs, 0x85a7);
    cl = ch;
    ch = bl;
    div(cx);
    cx = ax;
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = cx;
    dx = 0x01ed;
    cx = 0x864c;
    bx = 0x0000;
    sub_9cc9();
    ds = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_a5f2() // 01ed:8722
{
    CStackGuard sg(0, false);
    push(bx);
    push(dx);
    push(ds);
    push(es);
    sub_a5b9();
    es = pop();
    ds = pop();
    dx = pop();
    bx = pop();
}
void sub_a5fe() // 01ed:872e
{
    CStackGuard sg(0, false);
    ah = al;
    sub_a8b2();
loc_a603: // 01ed:8733
    lodsb<MemAuto, DirAuto>();
    ah = al;
    sub_a8b2();
    if (--cx)
        goto loc_a603;
}
void sub_a60c() // 01ed:873c
{
    CStackGuard sg(0, false);
    push(cx);
loc_a60d: // 01ed:873d
    lodsb<MemAuto, DirAuto>();
    if (al & 0x80)
        goto loc_a615;
    lodsb<MemAuto, DirAuto>();
    goto loc_a666;
loc_a615: // 01ed:8745
    ch = 0;
    if ((char)al < (char)0xf0)
        goto loc_a62b;
    if (al == 0xf0)
        goto loc_a626;
    if (al != 0xf7)
        goto loc_a630;
    sub_a4ab();
    goto loc_a666;
loc_a626: // 01ed:8756
    sub_a4d0();
    goto loc_a666;
loc_a62b: // 01ed:875b
    sub_a4f6();
    goto loc_a666;
loc_a630: // 01ed:8760
    lodsw<MemAuto, DirAuto>();
    if (al != 0x51)
        goto loc_a643;
    lodsb<MemAuto, DirAuto>();
    memoryASet(cs, 0x85a7, al);
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(cs, 0x85a5, ax);
    goto loc_a666;
loc_a643: // 01ed:8773
    if (al != 0x2f)
        goto loc_a654;
    lodsw<MemAuto, DirAuto>();
    ax = 0xffff;
    dx = ax;
    memoryASet16(cs, 0x85a1, memoryAGet16(cs, 0x85a1) - 1);
    goto loc_a670;
loc_a654: // 01ed:8784
    if (al != 0x20)
        goto loc_a660;
    lodsb<MemAuto, DirAuto>();
    memoryASet(cs, bx + 128, al);
    goto loc_a666;
loc_a660: // 01ed:8790
    cl = ah;
    si += cx;
loc_a666: // 01ed:8796
    sub_a761();
    if (!flags.zero)
        goto loc_a66d;
    goto loc_a60d;
loc_a66d: // 01ed:879d
    sub_a8f3();
loc_a670: // 01ed:87a0
    cx = pop();
}
void sub_a672() // 01ed:87a2
{
    CStackGuard sg(0, false);
    cx = memoryAGet16(cs, 0x85a1);
    bx = 0x81cc;
loc_a67a: // 01ed:87aa
    si = memoryAGet16(cs, bx);
    ds = memoryAGet16(cs, bx + 2);
    sub_a761();
    if (!flags.zero)
        goto loc_a685;
    sub_a60c();
loc_a685: // 01ed:87b5
    memoryASet16(cs, bx + 64, ax);
    memoryASet16(cs, bx + 66, dx);
    memoryASet16(cs, bx, si);
    ax = ds;
    memoryASet16(cs, bx + 2, ax);
    bx++;
    bx++;
    bx++;
    bx++;
    if (--cx)
        goto loc_a67a;
}
void sub_a6d9() // 01ed:8809
{
    CStackGuard sg(0, false);
    if (memoryAGet16(ds, si) != 0x544d)
        goto loc_a75e;
    si++;
    si++;
    if (memoryAGet16(ds, si) != 0x6468)
        goto loc_a75e;
    si++;
    si++;
    if (memoryAGet16(ds, si) != 0x0000)
        goto loc_a75e;
    si++;
    si++;
    if (memoryAGet16(ds, si) != 0x0600)
        goto loc_a75e;
    si++;
    si++;
    if (memoryAGet16(ds, si) == 0x0200)
        goto loc_a75e;
    si++;
    si++;
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    if (ax == 0x0000)
        goto loc_a75e;
    if ((short)ax > (short)0x0010)
        goto loc_a75e;
    memoryASet16(cs, 0x85a1, ax);
    lodsw<MemAuto, DirAuto>();
    tl = al;
    al = ah;
    ah = tl;
    if (ah & 0x80)
        goto loc_a75e;
    memoryASet16(cs, 0x85a3, ax);
    cx = memoryAGet16(cs, 0x85a1);
    bx = 0x81cc;
loc_a72e: // 01ed:885e
    sub_a8f3();
    lodsw<MemAuto, DirAuto>();
    if (ax != 0x544d)
        goto loc_a75e;
    lodsw<MemAuto, DirAuto>();
    if (ax != 0x6b72)
        goto loc_a75e;
    lodsw<MemAuto, DirAuto>();
    if (ax != 0x0000)
        goto loc_a75e;
    lodsw<MemAuto, DirAuto>();
    memoryASet16(cs, bx, si);
    bx++;
    bx++;
    memoryASet16(cs, bx, ds);
    bx++;
    bx++;
    tl = al;
    al = ah;
    ah = tl;
    flags.carry = (si + ax) >= 0x10000;
    si += ax;
    if (flags.carry)
        goto loc_a75e;
    if (--cx)
        goto loc_a72e;
    sub_a672();
    ax = 0xffff;
    return;
loc_a75e: // 01ed:888e
    ax = 0;
}
// INJECT: Error: cannot inject zero flag in sub_a761()!
void sub_a761() // 01ed:8891
{
    CStackGuard sg(0, false);
    ax = 0;
    dx = ax;
    lodsb<MemAuto, DirAuto>();
    if (!(al & 0x80))
        goto loc_a7ae;
    ah = al;
    lodsb<MemAuto, DirAuto>();
    if (al & 0x80)
        goto loc_a77a;
    ax &= 0x7f7f;
    al <<= 1;
    ax >>= 1;
    goto loc_a7ae;
loc_a77a: // 01ed:88aa
    tx = ax;
    ax = dx;
    dx = tx;
    lodsb<MemAuto, DirAuto>();
    if (al & 0x80)
        goto loc_a796;
    tl = ah;
    ah = dl;
    dl = tl;
    tl = dl;
    dl = dh;
    dh = tl;
    dx &= 0x7f7f;
    ax <<= 1;
    al <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = dl & 1;
    dl >>= 1;
    ax = rcr(ax, 0x0001);
    goto loc_a7ae;
loc_a796: // 01ed:88c6
    ah = al;
    lodsb<MemAuto, DirAuto>();
    tx = ax;
    ax = dx;
    dx = tx;
    dx &= 0x7f7f;
    dl <<= 1;
    dx >>= 1;
    ax <<= 1;
    al <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = dl & 1;
    dl >>= 1;
    ax = rcr(ax, 0x0001);
loc_a7ae: // 01ed:88de
    push(bx);
    bx = ax;
    bx |= dx;
    bx = pop();
    stop(/*inject ret*/);
}
void sub_a7b5() // 01ed:88e5
{
    CStackGuard sg(0, false);
    cx = 0xffff;
    ax = memoryAGet16(ds, 0x557a);
    if (ax != 0)
        goto loc_a7e9;
    ax = 0x0001;
    memoryASet16(ds, 0x557a, ax);
    cx = 0;
    memoryASet16(ds, 0x5584, ax);
    push(cx);
    sub_a945();
    cx = pop();
    ax = 0x0004;
    if (flags.zero)
        goto loc_a7d6;
    cx |= ax;
loc_a7d6: // 01ed:8906
    push(cx);
    sub_a9fa();
    cx = pop();
    ax = 0x0001;
    if (flags.zero)
        goto loc_a7e2;
    cx |= ax;
loc_a7e2: // 01ed:8912
    memoryASet16(cs, 0x85b3, ax);
    memoryASet16(ds, 0x5586, ax);
loc_a7e9: // 01ed:8919
    ax = cx;
}
void sub_a7ee() // 01ed:891e
{
    CStackGuard sg(0, true);
    push(0x7777);
    cx = 0xffff;
    ax = memoryAGet16(ds, 0x557a);
    if (ax != 0x0001)
        goto loc_a827;
    ax = 0x0002;
    memoryASet16(ds, 0x557a, ax);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    cx = 0x0000;
loc_a809: // 01ed:8939
    flags.carry = ax & 1;
    ax >>= 1;
    if (flags.carry)
        goto loc_a817;
    cx++;
    if (cx != 0x0010)
        goto loc_a809;
    ax = 0;
    goto loc_a82c;
loc_a817: // 01ed:8947
    ax = 0x0000;
    stop(/*carry2*/);
    ax = rcl(ax, 0x0001);
    ax <<= cl;
loc_a81e: // 01ed:894e
    memoryASet16(cs, 0x85b3, ax);
    memoryASet16(ds, 0x5586, ax);
    cx = ax;
loc_a827: // 01ed:8957
    ax = cx;
    assert(pop() == 0x7777);
    return;
loc_a82c: // 01ed:895c
    bx = 0x0001;
    ax = 0x0064;
    dx = 0x01ed;
    cx = 0x9136;
    sub_9cc9();
    ax = 0;
    memoryASet(cs, 0x83ee, al);
    memoryASet16(cs, 0x83ef, ax);
    goto loc_a81e;
}
void sub_a847() // 01ed:8977
{
    CStackGuard sg(0, true);
    push(0x7777);
    goto loc_a847;
loc_a69d: // 01ed:87cd
    push(bp);
    bp = sp;
    push(es);
    push(ds);
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 12);
    memoryASet16(cs, 0x8483, ax);
    si = memoryAGet16(ss, bp + 8);
    es = memoryAGet16(ss, bp + 8 + 2);
    memoryASet16(ds, 0x5580, si);
    si = es;
    memoryASet16(ds, 0x5582, si);
    si = memoryAGet16(ss, bp + 4);
    ds = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(cs, 0x8485, si);
    ax = ds;
    memoryASet16(cs, 0x8487, ax);
    sub_a6d9();
    if (ax == 0)
        goto loc_a6d3;
    sub_a5f2();
    ax = 0x0001;
loc_a6d3: // 01ed:8803
    di = pop();
    si = pop();
    ds = pop();
    es = pop();
    bp = pop();
    assert(pop() == 0x7777);
    return;
    //   gap of 366 bytes
loc_a847: // 01ed:8977
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x5586);
    tx = ax;
    ax = 0x0000;
    if (tx == 0)
        goto loc_a865;
    ax = 0x0000;
    sub_9cef();
    ds = pop();
    sub_a485();
    goto loc_a69d;
loc_a865: // 01ed:8995
    ds = pop();
    assert(pop() == 0x7777);
}
void sub_a869() // 01ed:8999
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(cs, 0x85a1);
    if (ax != 0)
        return;
    ax = memoryAGet16(cs, 0x8483);
}
void sub_a878() // 01ed:89a8
{
    CStackGuard sg(0, false);
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = 0x0000;
    sub_9cef();
    ds = pop();
    sub_a485();
}
void sub_a8b2() // 01ed:89e2
{
    CStackGuard sg(0, false);
    push(cx);
    cx = 0;
    dx = 0x0331;
loc_a8b8: // 01ed:89e8
    in(al, dx);
    if (--cx && al & 0x40)
        goto loc_a8b8;
    if (stop(/*1*/))
        goto loc_a8c5;
    dx--;
    al = ah;
    out(dx, al);
loc_a8c3: // 01ed:89f3
    cx = pop();
    return;
loc_a8c5: // 01ed:89f5
    push(ds);
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x557c, cx);
    ds = pop();
    memoryASet16(cs, 0x85a1, cx);
    goto loc_a8c3;
}
void sub_a8d7() // 01ed:8a07
{
    CStackGuard sg(0, true);
    push(0x7777);
    ah = 0x99;
    goto loc_a8dd;
    //   gap of 2 bytes
loc_a8dd: // 01ed:8a0d
    push(bp);
    bp = sp;
    push(dx);
    sub_a8b2();
    ah = memoryAGet(ss, bp + 4);
    sub_a8b2();
    ah = memoryAGet(ss, bp + 6);
    sub_a8b2();
    dx = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_a8f3() // 01ed:8a23
{
    CStackGuard sg(0, false);
    push(ax);
    push(bx);
    ax = si;
    si &= 0x000f;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    bx = ds;
    ax += bx;
    ds = ax;
    bx = pop();
    ax = pop();
}
void sub_a945() // 01ed:8a75
{
    CStackGuard sg(0, false);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    if (memoryAGet16(ds, 0x557c) == 0x0000)
        goto loc_a996;
    cx = 0x1388;
    dx = 0x0331;
loc_a956: // 01ed:8a86
    in(al, dx);
    if (--cx && al & 0x40)
        goto loc_a956;
    if (stop(/*1*/))
        goto loc_a990;
    al = 0xff;
    out(dx, al);
    bx = 0x0003;
loc_a963: // 01ed:8a93
    cx = 0x1388;
    dx = 0x0331;
loc_a969: // 01ed:8a99
    in(al, dx);
    if (--cx && al & 0x80)
        goto loc_a969;
    if (stop(/*1*/))
        goto loc_a98d;
    dx = 0x0330;
    in(al, dx);
    if (al != 0xfe)
        goto loc_a98d;
    cx = 0x1388;
    dx = 0x0331;
loc_a97e: // 01ed:8aae
    in(al, dx);
    if (--cx && al & 0x40)
        goto loc_a97e;
    if (stop(/*1*/))
        goto loc_a990;
    dx = 0x0331;
    al = 0x3f;
    out(dx, al);
    goto loc_a996;
loc_a98d: // 01ed:8abd
    bx--;
    if (bx != 0)
        goto loc_a963;
loc_a990: // 01ed:8ac0
    memoryASet16(ds, 0x557c, 0x0000);
loc_a996: // 01ed:8ac6
    dx = pop();
    cx = pop();
    bx = pop();
    cx = pop();
    ax = memoryAGet16(ds, 0x557c);
    flags.zero = ax == 0;
}
void sub_a9a0() // 01ed:8ad0
{
    CStackGuard sg(0, false);
    push(dx);
    push(cx);
    push(bx);
    push(ax);
    bx = 0x9009;
loc_a9a7: // 01ed:8ad7
    cx = 0x007f;
loc_a9aa: // 01ed:8ada
    ah = bh;
    ah += bl;
    sub_a8b2();
    ah = cl;
    sub_a8b2();
    ah = 0;
    sub_a8b2();
    if (--cx)
        goto loc_a9aa;
    bl--;
    if (bl != 0)
        goto loc_a9a7;
    ax = pop();
    bx = pop();
    cx = pop();
    dx = pop();
}
void sub_a9c6() // 01ed:8af6
{
    CStackGuard sg(0, false);
    push(ax);
    push(cx);
    lodsb<MemAuto, DirAuto>();
    cl = al;
    lodsb<MemAuto, DirAuto>();
    cl--;
    sub_a5fe();
    cx = pop();
    ax = pop();
}
void sub_a9d4() // 01ed:8b04
{
    CStackGuard sg(0, false);
    push(cx);
    cl = memoryAGet(ds, si);
    si++;
    sub_a5fe();
    cx = pop();
}
void sub_a9dd() // 01ed:8b0d
{
    CStackGuard sg(0, false);
    push(cx);
    if (al & 0x0f)
        goto loc_a9e7;
    al |= memoryAGet(cs, bx + 128);
loc_a9e7: // 01ed:8b17
    cx = 0x0002;
    ah = al;
    ah &= 0xf0;
    if (ah != 0xc0)
        goto loc_a9f5;
    cx--;
loc_a9f5: // 01ed:8b25
    sub_a5fe();
    cx = pop();
}
void sub_a9fa() // 01ed:8b2a
{
    CStackGuard sg(0, false);
    ax = 0x0001;
    memoryASet16(ds, 0x557e, ax);
    sub_ae86();
    if (flags.zero)
        goto loc_aa0a;
    sub_adbb();
    goto loc_aa10;
loc_aa0a: // 01ed:8b3a
    memoryASet16(ds, 0x557e, 0x0000);
loc_aa10: // 01ed:8b40
    ax = memoryAGet16(ds, 0x557e);
    flags.zero = ax == 0;
}
void sub_aa3b() // 01ed:8b6b
{
    CStackGuard sg(0, false);
    push(ax);
    push(di);
    push(si);
    push(cx);
    push(ds);
    push(bx);
    push(es);
    bl = al;
    bh = 0;
    sub_aa51();
    es = pop();
    bx = pop();
    ds = pop();
    cx = pop();
    si = pop();
    di = pop();
    ax = pop();
}
void sub_aa51() // 01ed:8b81
{
    CStackGuard sg(0, false);
    push(si);
    push(di);
    push(ds);
    push(es);
    si = 0x1228;
    ds = si;
    si = memoryAGet16(ds, 0x5580);
    ds = memoryAGet16(ds, 0x5580 + 2);
    di = memoryAGet16(ds, si + 12);
    di += si;
    bx += bx;
    bx += bx;
    cx = bx;
    bx += bx;
    bx += cx;
    di += bx;
    bx = memoryAGet16(ds, di);
    bx += bx;
    di = bx;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += bx;
    bx -= di;
    di = memoryAGet16(ds, si + 16);
    di += si;
    di += bx;
    bx = 0;
    push(ds);
    push(di);
    al = ah;
    di = pop();
    ds = pop();
    ah = 0;
    sub_aa98();
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
}
void sub_aa98() // 01ed:8bc8
{
    CStackGuard sg(0, false);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(ax);
    ah = 0x08;
    al = 0x00;
    sub_aed7();
    ax = pop();
    dh = memoryAGet(ds, bx + di);
    if (dh == 0)
        goto loc_aaae;
    goto loc_ac56;
loc_aaae: // 01ed:8bde
    dl = al;
    dl += 0xc0;
    dh = memoryAGet(ds, bx + di + 4);
    dh &= 0x07;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 14);
    ah &= 0x01;
    ah ^= 0x01;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    ah = 0;
    push(ds);
    push(di);
    cx = 0x1228;
    ds = cx;
    di = 0x5593;
    di += ax;
    al = memoryAGet(ds, di);
    di = pop();
    ds = pop();
    dl = al;
    dl += 0x40;
    dh = memoryAGet(ds, bx + di + 10);
    dh &= 0x3f;
    ah = memoryAGet(ds, bx + di + 2);
    ah >>= 1;
    ah >>= 1;
    ah &= 0xc0;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x60;
    dh = memoryAGet(ds, bx + di + 5);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 8);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x80;
    dh = memoryAGet(ds, bx + di + 6);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 9);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x20;
    dh = memoryAGet(ds, bx + di + 3);
    dh &= 0x0f;
    ah = memoryAGet(ds, bx + di + 11);
    if (ah == 0)
        goto loc_ab5e;
    dh |= 0x80;
loc_ab5e: // 01ed:8c8e
    ah = memoryAGet(ds, bx + di + 12);
    if (ah == 0)
        goto loc_ab68;
    dh |= 0x40;
loc_ab68: // 01ed:8c98
    ah = memoryAGet(ds, bx + di + 7);
    if (ah == 0)
        goto loc_ab72;
    dh |= 0x20;
loc_ab72: // 01ed:8ca2
    ah = memoryAGet(ds, bx + di + 13);
    if (ah == 0)
        goto loc_ab7c;
    dh |= 0x10;
loc_ab7c: // 01ed:8cac
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x43;
    dh = memoryAGet(ds, bx + di + 23);
    dh &= 0x3f;
    ah = memoryAGet(ds, bx + di + 15);
    ah >>= 1;
    ah >>= 1;
    ah &= 0xc0;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x63;
    dh = memoryAGet(ds, bx + di + 18);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 21);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x83;
    dh = memoryAGet(ds, bx + di + 19);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 22);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x23;
    dh = memoryAGet(ds, bx + di + 16);
    dh &= 0x0f;
    ah = memoryAGet(ds, bx + di + 24);
    if (ah == 0)
        goto loc_ac02;
    dh |= 0x80;
loc_ac02: // 01ed:8d32
    ah = memoryAGet(ds, bx + di + 25);
    if (ah == 0)
        goto loc_ac0c;
    dh |= 0x40;
loc_ac0c: // 01ed:8d3c
    ah = memoryAGet(ds, bx + di + 20);
    if (ah == 0)
        goto loc_ac16;
    dh |= 0x20;
loc_ac16: // 01ed:8d46
    ah = memoryAGet(ds, bx + di + 26);
    if (ah == 0)
        goto loc_ac20;
    dh |= 0x10;
loc_ac20: // 01ed:8d50
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0xe0;
    dh = memoryAGet(ds, bx + di + 28);
    dh &= 0x03;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0xe3;
    dh = memoryAGet(ds, bx + di + 29);
    dh &= 0x03;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
loc_ac51: // 01ed:8d81
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return;
loc_ac56: // 01ed:8d86
    al = 0x01;
    dl = al;
    dl += 0x40;
    dh = memoryAGet(ds, bx + di + 10);
    dh &= 0x3f;
    ah = memoryAGet(ds, bx + di + 2);
    ah >>= 1;
    ah >>= 1;
    ah &= 0xc0;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x60;
    dh = memoryAGet(ds, bx + di + 5);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 8);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x80;
    dh = memoryAGet(ds, bx + di + 6);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryAGet(ds, bx + di + 9);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x20;
    dh = memoryAGet(ds, bx + di + 3);
    dh &= 0x0f;
    ah = memoryAGet(ds, bx + di + 11);
    if (ah == 0)
        goto loc_acd5;
    dh |= 0x80;
loc_acd5: // 01ed:8e05
    ah = memoryAGet(ds, bx + di + 12);
    if (ah == 0)
        goto loc_acdf;
    dh |= 0x40;
loc_acdf: // 01ed:8e0f
    ah = memoryAGet(ds, bx + di + 7);
    if (ah == 0)
        goto loc_ace9;
    dh |= 0x20;
loc_ace9: // 01ed:8e19
    ah = memoryAGet(ds, bx + di + 13);
    if (ah == 0)
        goto loc_acf3;
    dh |= 0x10;
loc_acf3: // 01ed:8e23
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    goto loc_ac51;
}
void sub_acff() // 01ed:8e2f
{
    CStackGuard sg(0, false);
    push(ax);
    bx = 0x0001;
loc_ad03: // 01ed:8e33
    push(bx);
    ax = 0;
    push(ax);
    push(ax);
    push(ax);
    sub_af2d();
    ax = pop();
    ax = pop();
    ax = pop();
    bx = pop();
    bx++;
    if ((short)bx <= (short)0x0009)
        goto loc_ad03;
    ax = pop();
}
void sub_ad18() // 01ed:8e48
{
    CStackGuard sg(0, false);
    push(ax);
    lodsb<MemAuto, DirAuto>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_ad20() // 01ed:8e50
{
    CStackGuard sg(0, false);
    push(ax);
    lodsb<MemAuto, DirAuto>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_ad28() // 01ed:8e58
{
    CStackGuard sg(0, false);
    push(bx);
    push(cx);
    if (al & 0x0f)
        goto loc_ad33;
    al |= memoryAGet(cs, bx + 128);
loc_ad33: // 01ed:8e63
    ah = al;
    ah &= 0x0f;
    if ((char)ah <= (char)0x08)
        goto loc_ad3f;
    goto loc_ad53;
loc_ad3f: // 01ed:8e6f
    ah = al;
    ah &= 0xf0;
    if (ah == 0xc0)
        goto loc_ad5e;
    if (ah == 0x90)
        goto loc_ad6e;
    if (ah == 0x80)
        goto loc_ad97;
loc_ad53: // 01ed:8e83
    si++;
    al &= 0xf0;
    if (al == 0xc0)
        goto loc_ad5b;
    si++;
loc_ad5b: // 01ed:8e8b
    cx = pop();
    bx = pop();
    return;
loc_ad5e: // 01ed:8e8e
    sub_ad63();
    goto loc_ad5b;
    //   gap of 11 bytes
loc_ad6e: // 01ed:8e9e
    sub_ad73();
    goto loc_ad5b;
    //   gap of 36 bytes
loc_ad97: // 01ed:8ec7
    push(ax);
    al &= 0x0f;
    al += 0xb0;
    ah = al;
    push(ds);
    push(bx);
    bx = 0x01ed;
    ds = bx;
    bx = 0x80cc;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += flags.carry;
    al = memoryAGet(ds, bx);
    bx = pop();
    ds = pop();
    al &= 0xdf;
    sub_aed7();
    lodsb<MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
    ax = pop();
    goto loc_ad5b;
}
void sub_ad63() // 01ed:8e93
{
    CStackGuard sg(0, false);
    al &= 0x0f;
    ah = al;
    al = memoryAGet(ds, si);
    sub_aa3b();
    si++;
}
void sub_ad73() // 01ed:8ea3
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(di);
    push(es);
    al &= 0x0f;
    ah = 0;
    push(ax);
    lodsb<MemAuto, DirAuto>();
    push(ax);
    lodsb<MemAuto, DirAuto>();
    push(ax);
    if (ax == 0)
        goto loc_ad89;
    ax = 0x0020;
loc_ad89: // 01ed:8eb9
    push(ax);
    sub_af2d();
    sp += 0x0008;
    es = pop();
    di = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    assert(pop() == 0x7777);
}
void sub_adbb() // 01ed:8eeb
{
    CStackGuard sg(0, false);
    push(ax);
    push(ax);
    ah = 0x40;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x41;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x42;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x48;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x49;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x4a;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x50;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x51;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x52;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x43;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x44;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x45;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x4b;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x4c;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x4d;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x53;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x54;
    al = 0xff;
    sub_aed7();
    ax = pop();
    push(ax);
    ah = 0x55;
    al = 0xff;
    sub_aed7();
    ax = pop();
    ax = 0x0100;
loc_ae61: // 01ed:8f91
    sub_aed7();
    ah++;
    if (ah != 0x40)
        goto loc_ae61;
    ax = 0x6000;
loc_ae6e: // 01ed:8f9e
    sub_aed7();
    ah++;
    if (ah != 0xf6)
        goto loc_ae6e;
    ax = 0x0406;
    sub_aed7();
    ax = 0xbd00;
    sub_aed7();
    ax = pop();
}
void sub_ae86() // 01ed:8fb6
{
    CStackGuard sg(0, false);
    push(ax);
    push(cx);
    push(dx);
    ax = 0x0460;
    sub_aed7();
    ax = 0x0480;
    sub_aed7();
    sub_af26();
    push(ax);
    ax = 0x02ff;
    sub_aed7();
    ax = 0x0421;
    sub_aed7();
    cx = 0x00c7;
loc_aea8: // 01ed:8fd8
    sub_af26();
    if (--cx)
        goto loc_aea8;
    sub_af26();
    push(ax);
    ax = 0x0460;
    sub_aed7();
    ax = 0x0480;
    sub_aed7();
    ax = pop();
    dx = pop();
    ah = 0x00;
    al &= 0xe0;
    dl &= 0xe0;
    if (al != 0xc0)
        goto loc_aed1;
    if (dl != 0x00)
        goto loc_aed1;
    ah = 0x01;
loc_aed1: // 01ed:9001
    flags.zero = ah == 0;
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_aed7() // 01ed:9007
{
    CStackGuard sg(0, false);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    push(ax);
    push(dx);
    push(ds);
    push(bx);
    bx = 0x01ed;
    ds = bx;
    bx = 0x80cc;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += flags.carry;
    memoryASet(ds, bx, al);
    bx = pop();
    ds = pop();
    dx = 0x0388;
    tl = ah;
    ah = al;
    al = tl;
    out(dx, al);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    in(al, dx);
    dx++;
    tl = ah;
    ah = al;
    al = tl;
    out(dx, al);
    dx--;
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
    dx = pop();
    ax = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
}
void sub_af26() // 01ed:9056
{
    CStackGuard sg(0, false);
    push(dx);
    dx = 0x0388;
    in(al, dx);
    dx = pop();
}
void sub_af2d() // 01ed:905d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(bx);
    push(cx);
    push(dx);
    push(ds);
    push(ax);
    ah = 0x08;
    al = 0x00;
    sub_aed7();
    ax = pop();
    push(bx);
    push(ds);
    push(ax);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ss, bp + 10);
    bh = 0;
    dl = memoryAGet(ds, bx + 21907);
    dl += 0x43;
    ah = dl;
    push(ds);
    push(bx);
    bx = 0x01ed;
    ds = bx;
    bx = 0x80cc;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += flags.carry;
    al = memoryAGet(ds, bx);
    bx = pop();
    ds = pop();
    ah = 0x20;
    dh -= memoryAGet(ss, bp + 6);
    dh >>= 1;
    dh >>= 1;
    dh >>= 1;
    dh >>= 1;
    dh &= 0x3f;
    ah -= dh;
    dh = ah;
    dh &= 0x3f;
    al &= 0xc0;
    dh |= al;
    push(dx);
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dx = pop();
    ax = pop();
    ds = pop();
    bx = pop();
    ax = 0x1228;
    ds = ax;
    bx = memoryAGet16(ss, bp + 8);
    di = 0x55b4;
    cl = memoryAGet(ds, bx + di);
    cl--;
    di = 0x5614;
    al = memoryAGet(ds, bx + di);
    ah = 0;
    bx = ax;
    bx += bx;
    di = 0x559c;
    ax = memoryAGet16(ds, bx + di);
    ax &= 0x03ff;
    push(ax);
    ah = al;
    al = 0xa0;
    al += memoryAGet(ss, bp + 10);
    tl = al;
    al = ah;
    ah = tl;
    sub_aed7();
    ax = pop();
    ds = pop();
    al = ah;
    al &= 0x03;
    cl &= 0x07;
    cl <<= 1;
    cl <<= 1;
    al += cl;
    al += memoryAGet(ss, bp + 4);
    ah = 0;
    push(ax);
    ah = al;
    al = 0xb0;
    al += memoryAGet(ss, bp + 10);
    tl = ah;
    ah = al;
    al = tl;
    sub_aed7();
    ax = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_afe5() // 01ed:9115
{
    CStackGuard sg(0, false);
    push(ax);
    push(bx);
    push(cx);
    bx = 0x83cc;
    cx = 0x000f;
    al = 0;
loc_aff0: // 01ed:9120
    memoryASet(cs, bx, al);
    bx++;
    if (--cx)
        goto loc_aff0;
    cx = pop();
    bx = pop();
    ax = pop();
    al = 0;
    memoryASet(cs, 0x83ee, al);
    in(al, 0x61);
    al &= 0xfc;
    out(0x0061, al);
}
void sub_b09f() // 01ed:91cf
{
    CStackGuard sg(0, false);
    push(ax);
    lodsb<MemAuto, DirAuto>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_b0a7() // 01ed:91d7
{
    CStackGuard sg(0, false);
    push(ax);
    lodsb<MemAuto, DirAuto>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_b0af() // 01ed:91df
{
    CStackGuard sg(0, false);
    push(ax);
    push(bx);
    ah = al;
    ah &= 0xf0;
    if (ah == 0xc0)
        goto loc_b0f7;
    if (al & 0x0f)
        goto loc_b0c4;
    al |= memoryAGet(cs, bx + 128);
loc_b0c4: // 01ed:91f4
    bx = 0x83cc;
    ah = al;
    ah &= 0x0f;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += flags.carry;
    al &= 0xf0;
    if (al == 0x90)
        goto loc_b0e9;
    if (al == 0x80)
        goto loc_b0e0;
    lodsb<MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
loc_b0dd: // 01ed:920d
    bx = pop();
    ax = pop();
    return;
loc_b0e0: // 01ed:9210
    lodsb<MemAuto, DirAuto>();
    lodsb<MemAuto, DirAuto>();
    al = 0;
loc_b0e4: // 01ed:9214
    memoryASet(cs, bx, al);
    goto loc_b0dd;
loc_b0e9: // 01ed:9219
    lodsb<MemAuto, DirAuto>();
    ah = al;
    lodsb<MemAuto, DirAuto>();
    if (al == 0x00)
        goto loc_b0f5;
    al = ah;
    goto loc_b0e4;
loc_b0f5: // 01ed:9225
    goto loc_b0e4;
loc_b0f7: // 01ed:9227
    sub_b0fc();
    goto loc_b0dd;
}
void sub_b0fc() // 01ed:922c
{
    CStackGuard sg(0, false);
    al &= 0x0f;
    ah = al;
    al = memoryAGet(ds, si);
    push(bx);
    bx = 0x8473;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += flags.carry;
    memoryASet(cs, bx, al);
    bx = pop();
    si++;
}
void sub_b14c() // 01ed:927c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x0000;
    interrupt(0x33);
    memoryASet(ds, 0x5674, al);
    ax ^= 0xffff;
    push(ax);
    ax = 0x0004;
    cx = 0x0000;
    dx = cx;
    interrupt(0x33);
    ax = 0x0007;
    cx = 0x0000;
    dx = 0x0280;
    interrupt(0x33);
    ax = 0x0008;
    cx = 0x0000;
    dx = 0x00c8;
    interrupt(0x33);
    ax = pop();
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
}
void sub_b274() // 01ed:93a4
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ed2;
    sub_ed20();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b281() // 01ed:93b1
{
    CStackGuard sg(0, false);
    push(cs);
    cs = 0x0ed2;
    sub_ed3f();
    assert(cs == 0x01ed);
}
void sub_b288() // 01ed:93b8
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_da88();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b298() // 01ed:93c8
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_dcce();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b2a8() // 01ed:93d8
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    cs = 0x0ed9;
    sub_11a7d();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b2d6() // 01ed:9406
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    cs = 0x0ed9;
    sub_11b38();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b2e0() // 01ed:9410
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    cs = 0x0ed9;
    sub_11b62();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b2f4() // 01ed:9424
{
    CStackGuard sg(0, false);
    push(cs);
    cs = 0x0ed9;
    sub_11ec7();
    assert(cs == 0x01ed);
}
void sub_b2fa() // 01ed:942a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    cs = 0x0ed9;
    sub_11f47();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b304() // 01ed:9434
{
    CStackGuard sg(0, false);
}
void sub_b321() // 01ed:9451
{
    CStackGuard sg(0, false);
    in(al, 0x61);
    al &= 0xfc;
    sub_b304();
    out(0x0061, al);
}
void sub_b32b() // 01ed:945b
{
    CStackGuard sg(0, false);
    if (ax == 0x00ff)
        goto loc_b337;
    if (memoryAGet16(cs, 0x946c) < ax)
        return;
loc_b337: // 01ed:9467
    memoryASet16(cs, 0x946c, ax);
}
void sub_b33e() // 01ed:946e
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(ds, 0x683e);
    tx = ax;
    ax = 0x00ff;
    if (tx == 0)
        goto loc_b351;
    ax = 0x0000;
    sub_b32b();
    return;
loc_b351: // 01ed:9481
    sub_b32b();
    sub_b321();
}
void sub_b674() // 01ed:97a4
{
    CStackGuard sg(0, false);
    push(cs);
    cs = 0x1219;
    sub_12190();
    assert(cs == 0x01ed);
}
void sub_b67a() // 01ed:97aa
{
    CStackGuardFar sg(0, false);
    sub_998b();
    cs = pop();
}
void sub_b695() // 01ed:97c5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = memoryAGet16(ss, bp + 6);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_dd71();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b6a5() // 01ed:97d5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_dd8b();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b6c1() // 01ed:97f1
{
    CStackGuard sg(0, false);
    push(cs);
    cs = 0x0ca6;
    sub_dddb();
    assert(cs == 0x01ed);
}
void sub_b6d4() // 01ed:9804
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_de4c();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b6e4() // 01ed:9814
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_de69();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b6f1() // 01ed:9821
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    bx = memoryAGet16(ss, bp + 6);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 10);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_de82();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b707() // 01ed:9837
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    dx = memoryAGet16(ss, bp + 6);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_dea1();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b734() // 01ed:9864
{
    CStackGuard sg(0, false);
    push(cs);
    cs = 0x1223;
    sub_12230();
    assert(cs == 0x01ed);
}
void sub_b75e() // 01ed:988e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    if ((short)si < 0)
        goto loc_b76e;
    if ((short)si < (short)0x0014)
        goto loc_b777;
loc_b76e: // 01ed:989e
    ax = 0x0006;
    push(ax);
    sub_c048();
    goto loc_b786;
loc_b777: // 01ed:98a7
    bx = si;
    bx <<= 1;
    memoryASet16(ds, bx + 27420, 0xffff);
    push(si);
    sub_be85();
    cx = pop();
loc_b786: // 01ed:98b6
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b78a() // 01ed:98ba
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    goto loc_b799;
loc_b78f: // 01ed:98bf
    bx = memoryAGet16(ds, 0x6982);
    bx <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bx + 41406));
loc_b799: // 01ed:98c9
    ax = memoryAGet16(ds, 0x6982);
    memoryASet16(ds, 0x6982, memoryAGet16(ds, 0x6982) - 1);
    if (ax)
        goto loc_b78f;
    push(memoryAGet16(ss, bp + 4));
    sub_1fc6();
    cx = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b7ad() // 01ed:98dd
{
    CStackGuard sg(4, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 6);
    ax++;
    si = ax;
    si -= memoryAGet16(ds, 0x0079);
    ax = si;
    ax += 0x003f;
    cl = 0x06;
    ax >>= cl;
    si = ax;
    if (si != memoryAGet16(ds, 0x698a))
        goto loc_b7df;
loc_b7cd: // 01ed:98fd
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x0087, dx);
    memoryASet16(ds, 0x0089, ax);
    ax = 0x0001;
    goto loc_b825;
loc_b7df: // 01ed:990f
    cl = 0x06;
    si <<= cl;
    di = memoryAGet16(ds, 0x008d);
    ax = si;
    ax += memoryAGet16(ds, 0x0079);
    if (ax <= di)
        goto loc_b7f9;
    ax = di;
    ax -= memoryAGet16(ds, 0x0079);
    si = ax;
loc_b7f9: // 01ed:9929
    push(si);
    push(memoryAGet16(ds, 0x0079));
    sub_c352();
    cx = pop();
    cx = pop();
    di = ax;
    if (di != 0xffff)
        goto loc_b815;
    ax = si;
    cl = 0x06;
    ax >>= cl;
    memoryASet16(ds, 0x698a, ax);
    goto loc_b7cd;
loc_b815: // 01ed:9945
    ax = memoryAGet16(ds, 0x0079);
    ax += di;
    memoryASet16(ds, 0x008b, 0x0000);
    memoryASet16(ds, 0x008d, ax);
    ax = 0;
loc_b825: // 01ed:9955
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_b82b() // 01ed:995b
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    cx = memoryAGet16(ds, 0x0085);
    bx = memoryAGet16(ds, 0x0083);
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_c8fb();
    if (flags.carry)
        goto loc_b861;
    cx = memoryAGet16(ds, 0x008d);
    bx = memoryAGet16(ds, 0x008b);
    dx = memoryAGet16(ss, bp + 6);
    ax = memoryAGet16(ss, bp + 4);
    sub_c8fb();
    if (!flags.zero && !flags.carry)
        goto loc_b861;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_b7ad();
    if (ax)
        goto loc_b866;
loc_b861: // 01ed:9991
    ax = 0xffff;
    goto loc_b868;
loc_b866: // 01ed:9996
    ax = 0;
loc_b868: // 01ed:9998
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b86a() // 01ed:999a
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    dx = memoryAGet16(ds, 0x0089);
    ax = memoryAGet16(ds, 0x0087);
    cx = memoryAGet16(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 4);
    sub_c865();
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, dx);
    cx = memoryAGet16(ds, 0x0085);
    bx = memoryAGet16(ds, 0x0083);
    ax = memoryAGet16(ss, bp - 4);
    sub_c8fb();
    if (flags.carry)
        goto loc_b8a9;
    cx = memoryAGet16(ds, 0x008d);
    bx = memoryAGet16(ds, 0x008b);
    dx = memoryAGet16(ss, bp - 2);
    ax = memoryAGet16(ss, bp - 4);
    sub_c8fb();
    if (flags.zero || flags.carry)
        goto loc_b8b1;
loc_b8a9: // 01ed:99d9
    dx = 0xffff;
    ax = 0xffff;
    goto loc_b8d3;
loc_b8b1: // 01ed:99e1
    ax = memoryAGet16(ds, 0x0089);
    dx = memoryAGet16(ds, 0x0087);
    memoryASet16(ss, bp - 8, dx);
    memoryASet16(ss, bp - 6, ax);
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_b7ad();
    if (ax)
        goto loc_b8cd;
    goto loc_b8a9;
loc_b8cd: // 01ed:99fd
    dx = memoryAGet16(ss, bp - 6);
    ax = memoryAGet16(ss, bp - 8);
loc_b8d3: // 01ed:9a03
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b8d7() // 01ed:9a07
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    ax = memoryAGet16(ss, bp + 4);
    ax |= memoryAGet16(ss, bp + 6);
    if (ax)
        goto loc_b8e9;
    sub_b9a3();
    goto loc_b99e;
loc_b8e9: // 01ed:9a19
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 18);
    if (ax == memoryAGet16(ss, bp + 4))
        goto loc_b8fb;
loc_b8f5: // 01ed:9a25
    ax = 0xffff;
    goto loc_b9a0;
loc_b8fb: // 01ed:9a2b
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if ((short)memoryAGet16(es, bx) < (short)0x0000)
        goto loc_b952;
    if (memoryAGet16(es, bx + 2) & 0x0008)
        goto loc_b921;
    ax = memoryAGet16(es, bx + 14);
    dx = memoryAGet16(ss, bp + 4);
    dx += 0x0005;
    if (ax != memoryAGet16(ss, bp + 6))
        goto loc_b950;
    if (memoryAGet16(es, bx + 12) != dx)
        goto loc_b950;
loc_b921: // 01ed:9a51
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx, 0x0000);
    ax = memoryAGet16(es, bx + 14);
    dx = memoryAGet16(ss, bp + 4);
    dx += 0x0005;
    if (ax != memoryAGet16(ss, bp + 6))
        goto loc_b950;
    if (memoryAGet16(es, bx + 12) != dx)
        goto loc_b950;
    ax = memoryAGet16(es, bx + 10);
    dx = memoryAGet16(es, bx + 8);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    goto loc_b99e;
loc_b950: // 01ed:9a80
    goto loc_b99e;
loc_b952: // 01ed:9a82
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 6);
    ax += memoryAGet16(es, bx);
    ax++;
    si = ax;
    ax = memoryAGet16(es, bx);
    ax -= si;
    memoryASet16(es, bx, ax);
    push(si);
    ax = memoryAGet16(es, bx + 10);
    dx = memoryAGet16(es, bx + 8);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    push(ax);
    push(dx);
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    sub_bcce();
    sp += 0x0008;
    if (ax == si)
        goto loc_b99e;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet16(es, bx + 2) & 0x0200)
        goto loc_b99e;
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0010);
    goto loc_b8f5;
loc_b99e: // 01ed:9ace
    ax = 0;
loc_b9a0: // 01ed:9ad0
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b9a3() // 01ed:9ad3
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    di = 0;
    si = 0x0014;
    memoryASet16(ss, bp - 4, 0x698c);
    memoryASet16(ss, bp - 2, ds);
    goto loc_b9d5;
loc_b9ba: // 01ed:9aea
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0003))
        goto loc_b9d1;
    push(memoryAGet16(ss, bp - 2));
    push(memoryAGet16(ss, bp - 4));
    sub_b8d7();
    cx = pop();
    cx = pop();
    di++;
loc_b9d1: // 01ed:9b01
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 0x0014);
loc_b9d5: // 01ed:9b05
    ax = si;
    si--;
    if (ax)
        goto loc_b9ba;
    ax = di;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b9e4() // 01ed:9b14
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
    if ((short)memoryAGet16(es, bx) >= (short)0x0000)
        goto loc_b9ff;
    ax = memoryAGet16(es, bx + 6);
    ax += memoryAGet16(es, bx);
    ax++;
    goto loc_ba0a;
loc_b9ff: // 01ed:9b2f
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    ax ^= dx;
    ax -= dx;
loc_ba0a: // 01ed:9b3a
    si = ax;
    di = ax;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0040))
        goto loc_ba1b;
    goto loc_ba5e;
loc_ba1b: // 01ed:9b4b
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 14);
    dx = memoryAGet16(es, bx + 12);
    memoryASet16(ss, bp - 4, dx);
    memoryASet16(ss, bp - 2, ax);
    if ((short)memoryAGet16(es, bx) >= (short)0x0000)
        goto loc_ba57;
    goto loc_ba41;
loc_ba34: // 01ed:9b64
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) - 1);
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    if (memoryAGet(es, bx) != 0x0a)
        goto loc_ba41;
    di++;
loc_ba41: // 01ed:9b71
    ax = si;
    si--;
    if (ax)
        goto loc_ba34;
    goto loc_ba5e;
loc_ba4a: // 01ed:9b7a
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    if (memoryAGet(es, bx) != 0x0a)
        goto loc_ba57;
    di++;
loc_ba57: // 01ed:9b87
    ax = si;
    si--;
    if (ax)
        goto loc_ba4a;
loc_ba5e: // 01ed:9b8e
    ax = di;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_ba68() // 01ed:9b98
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_b8d7();
    cx = pop();
    cx = pop();
    if (!ax)
        goto loc_ba7f;
    ax = 0xffff;
    goto loc_bae2;
loc_ba7f: // 01ed:9baf
    if (memoryAGet16(ss, bp + 12) != 0x0001)
        goto loc_ba9e;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if ((short)memoryAGet16(es, bx) <= (short)0x0000)
        goto loc_ba9e;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_b9e4();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryAGet16(ss, bp + 8) < ax;
    memoryASet16(ss, bp + 8, memoryAGet16(ss, bp + 8) - ax);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) - (dx + flags.carry));
loc_ba9e: // 01ed:9bce
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xfe5f);
    memoryASet16(es, bx, 0x0000);
    ax = memoryAGet16(es, bx + 10);
    dx = memoryAGet16(es, bx + 8);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    push(memoryAGet16(ss, bp + 12));
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    al = memoryAGet(es, bx + 4);
    cbw();
    push(ax);
    sub_c096();
    sp += 0x0008;
    if (dx != 0xffff)
        goto loc_bae0;
    if (ax != 0xffff)
        goto loc_bae0;
    ax = 0xffff;
    goto loc_bae2;
loc_bae0: // 01ed:9c10
    ax = 0;
loc_bae2: // 01ed:9c12
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_bb32() // 01ed:9c62
{
    CStackGuard sg(0, true);
    push(0x7777);
    al = memoryAGet(ds, 0x6990);
    cbw();
    push(ax);
    sub_c085();
    cx = pop();
    if (ax)
        goto loc_bb45;
    memoryASet16(ds, 0x698e, memoryAGet16(ds, 0x698e) & 0xfdff);
loc_bb45: // 01ed:9c75
    ax = 0x0200;
    push(ax);
    if (!(memoryAGet16(ds, 0x698e) & 0x0200))
        goto loc_bb56;
    ax = 0x0001;
    goto loc_bb58;
loc_bb56: // 01ed:9c86
    ax = 0;
loc_bb58: // 01ed:9c88
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(ds);
    ax = 0x698c;
    push(ax);
    sub_bba3();
    sp += 0x000c;
    al = memoryAGet(ds, 0x69a4);
    cbw();
    push(ax);
    sub_c085();
    cx = pop();
    if (ax)
        goto loc_bb7d;
    memoryASet16(ds, 0x69a2, memoryAGet16(ds, 0x69a2) & 0xfdff);
loc_bb7d: // 01ed:9cad
    ax = 0x0200;
    push(ax);
    if (!(memoryAGet16(ds, 0x69a2) & 0x0200))
        goto loc_bb8e;
    ax = 0x0002;
    goto loc_bb90;
loc_bb8e: // 01ed:9cbe
    ax = 0;
loc_bb90: // 01ed:9cc0
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(ds);
    ax = 0x69a0;
    push(ax);
    sub_bba3();
    sp += 0x000c;
    assert(pop() == 0x7777);
}
void sub_bba3() // 01ed:9cd3
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryAGet16(ss, bp + 12);
    si = memoryAGet16(ss, bp + 14);
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(es, bx + 18);
    if (ax != memoryAGet16(ss, bp + 4))
        goto loc_bbc5;
    if ((short)di > (short)0x0002)
        goto loc_bbc5;
    if (si <= 0x7fff)
        goto loc_bbcb;
loc_bbc5: // 01ed:9cf5
    ax = 0xffff;
    goto loc_bcb2;
loc_bbcb: // 01ed:9cfb
    if (memoryAGet16(ds, 0x6b4a) != 0x0000)
        goto loc_bbe1;
    if (memoryAGet16(ss, bp + 4) != 0x69a0)
        goto loc_bbe1;
    memoryASet16(ds, 0x6b4a, 0x0001);
    goto loc_bbf5;
loc_bbe1: // 01ed:9d11
    if (memoryAGet16(ds, 0x6b48) != 0x0000)
        goto loc_bbf5;
    if (memoryAGet16(ss, bp + 4) != 0x698c)
        goto loc_bbf5;
    memoryASet16(ds, 0x6b48, 0x0001);
loc_bbf5: // 01ed:9d25
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (memoryAGet16(es, bx) == 0x0000)
        goto loc_bc14;
    ax = 0x0001;
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_ba68();
    sp += 0x000a;
loc_bc14: // 01ed:9d44
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (!(memoryAGet16(es, bx + 2) & 0x0004))
        goto loc_bc2c;
    push(memoryAGet16(es, bx + 10));
    push(memoryAGet16(es, bx + 8));
    sub_c4fe();
    cx = pop();
    cx = pop();
loc_bc2c: // 01ed:9d5c
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) & 0xfff3);
    memoryASet16(es, bx + 6, 0x0000);
    ax = memoryAGet16(ss, bp + 6);
    dx = memoryAGet16(ss, bp + 4);
    dx += 0x0005;
    memoryASet16(es, bx + 8, dx);
    memoryASet16(es, bx + 10, ax);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    if (di == 0x0002)
        goto loc_bcb0;
    if (!si)
        goto loc_bcb0;
    memoryASet16(ds, 0x6984, 0x9f25);
    ax = memoryAGet16(ss, bp + 8);
    ax |= memoryAGet16(ss, bp + 10);
    if (ax)
        goto loc_bc88;
    push(si);
    sub_c5e4();
    cx = pop();
    memoryASet16(ss, bp + 8, ax);
    memoryASet16(ss, bp + 10, dx);
    ax |= dx;
    if (!ax)
        goto loc_bc85;
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0004);
    goto loc_bc88;
loc_bc85: // 01ed:9db5
    goto loc_bbc5;
loc_bc88: // 01ed:9db8
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    ax = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 8);
    memoryASet16(es, bx + 12, dx);
    memoryASet16(es, bx + 14, ax);
    memoryASet16(es, bx + 8, dx);
    memoryASet16(es, bx + 10, ax);
    memoryASet16(es, bx + 6, si);
    if (di != 0x0001)
        goto loc_bcb0;
    memoryASet16(es, bx + 2, memoryAGet16(es, bx + 2) | 0x0008);
loc_bcb0: // 01ed:9de0
    ax = 0;
loc_bcb2: // 01ed:9de2
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_bcce() // 01ed:9dfe
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x008e;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 10);
    ax++;
    if (ax >= 0x0002)
        goto loc_bce5;
    ax = 0;
    goto loc_bdef;
loc_bce5: // 01ed:9e15
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 27420) & 0x8000))
        goto loc_bd07;
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c36e();
    sp += 0x0008;
    goto loc_bdef;
loc_bd07: // 01ed:9e37
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 27420, memoryAGet16(ds, bx + 27420) & 0xfdff);
    ax = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    memoryASet16(ss, bp - 12, dx);
    memoryASet16(ss, bp - 10, ax);
    ax = memoryAGet16(ss, bp + 10);
    memoryASet16(ss, bp - 6, ax);
    goto loc_bd9e;
loc_bd26: // 01ed:9e56
    memoryASet16(ss, bp - 6, memoryAGet16(ss, bp - 6) - 1);
    bx = memoryAGet16(ss, bp - 12);
    es = memoryAGet16(ss, bp - 12 + 2);
    memoryASet16(ss, bp - 12, memoryAGet16(ss, bp - 12) + 1);
    al = memoryAGet(es, bx);
    memoryASet(ss, bp - 7, al);
    if (al != 0x0a)
        goto loc_bd43;
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    memoryASet(es, bx, 0x0d);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
loc_bd43: // 01ed:9e73
    bx = memoryAGet16(ss, bp - 4);
    es = memoryAGet16(ss, bp - 4 + 2);
    al = memoryAGet(ss, bp - 7);
    memoryASet(es, bx, al);
    memoryASet16(ss, bp - 4, memoryAGet16(ss, bp - 4) + 1);
    ax = bp - 0x8e;
    dx = memoryAGet16(ss, bp - 4);
    bx = 0;
    flags.carry = dx < ax;
    dx -= ax;
    bx -= flags.carry;
    if ((short)bx < 0)
        goto loc_bda8;
    if (bx)
        goto loc_bd69;
    if (dx < 0x0080)
        goto loc_bda8;
loc_bd69: // 01ed:9e99
    ax = bp - 0x8e;
    dx = memoryAGet16(ss, bp - 4);
    bx = 0;
    flags.carry = dx < ax;
    dx -= ax;
    bx -= flags.carry;
    si = dx;
    push(si);
    push(ss);
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_c36e();
    sp += 0x0008;
    di = ax;
    if (ax == si)
        goto loc_bd9e;
    if (stop(/*condition!*/))
        goto loc_bd94;
loc_bd8f: // 01ed:9ebf
    ax = 0xffff;
    goto loc_bdea;
loc_bd94: // 01ed:9ec4
    ax = memoryAGet16(ss, bp + 10);
    ax -= memoryAGet16(ss, bp - 6);
    goto loc_bde6;
    //   gap of 2 bytes
loc_bd9e: // 01ed:9ece
    ax = bp - 0x8e;
    memoryASet16(ss, bp - 4, ax);
    memoryASet16(ss, bp - 2, ss);
loc_bda8: // 01ed:9ed8
    if (memoryAGet16(ss, bp - 6) == 0x0000)
        goto loc_bdb1;
    goto loc_bd26;
loc_bdb1: // 01ed:9ee1
    ax = bp - 0x8e;
    dx = memoryAGet16(ss, bp - 4);
    bx = 0;
    flags.carry = dx < ax;
    dx -= ax;
    bx -= flags.carry;
    si = dx;
    ax = dx;
    if (stop(/*condition!*/))
        goto loc_bdec;
    push(si);
    push(ss);
    ax = bp - 0x8e;
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_c36e();
    sp += 0x0008;
    di = ax;
    if (ax == si)
        goto loc_bdec;
    if (stop(/*condition!*/))
        goto loc_bde3;
    goto loc_bd8f;
loc_bde3: // 01ed:9f13
    ax = memoryAGet16(ss, bp + 10);
loc_bde6: // 01ed:9f16
    ax += di;
    ax -= si;
loc_bdea: // 01ed:9f1a
    goto loc_bdef;
loc_bdec: // 01ed:9f1c
    ax = memoryAGet16(ss, bp + 10);
loc_bdef: // 01ed:9f1f
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_be68() // 01ed:9f98
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    cx = memoryAGet16(ss, bp + 10);
    ah = 0x43;
    al = memoryAGet(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 4);
    ds = memoryAGet16(ss, bp + 4 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_be7f;
    tx = ax;
    ax = cx;
    cx = tx;
    goto loc_be83;
loc_be7f: // 01ed:9faf
    push(ax);
    sub_c048();
loc_be83: // 01ed:9fb3
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_be85() // 01ed:9fb5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x3e;
    bx = memoryAGet16(ss, bp + 4);
    interrupt(0x21);
    if (flags.carry)
        goto loc_be9d;
    bx <<= 1;
    memoryASet16(ds, bx + 27420, 0xffff);
    ax = 0;
    goto loc_bea1;
loc_be9d: // 01ed:9fcd
    push(ax);
    sub_c048();
loc_bea1: // 01ed:9fd1
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_bf70() // 01ed:a0a0
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x25;
    al = memoryAGet(ss, bp + 4);
    push(ds);
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_bfb9() // 01ed:a0e9
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0xa1fe, ax);
    push(cs);
    ax = 0xa0b1;
    push(ax);
    ax = 0x0024;
    push(ax);
    sub_bf70();
    sp += 0x0006;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c01f() // 01ed:a14f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x44;
    al = memoryAGet(ss, bp + 6);
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 12);
    dx = memoryAGet16(ss, bp + 8);
    ds = memoryAGet16(ss, bp + 8 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c042;
    if (memoryAGet16(ss, bp + 6) != 0x0000)
        goto loc_c040;
    ax = dx;
    goto loc_c046;
loc_c040: // 01ed:a170
    goto loc_c046;
loc_c042: // 01ed:a172
    push(ax);
    sub_c048();
loc_c046: // 01ed:a176
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c048() // 01ed:a178
{
    CStackGuard sg(2, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = memoryAGet16(ss, bp + 4);
    if ((short)si < 0)
        goto loc_c068;
    if ((short)si <= (short)0x0058)
        goto loc_c05b;
loc_c058: // 01ed:a188
    si = 0x0057;
loc_c05b: // 01ed:a18b
    memoryASet16(ds, 0x6b4e, si);
    al = memoryAGet(ds, si + 27472);
    cbw();
    si = ax;
    goto loc_c079;
loc_c068: // 01ed:a198
    ax = si;
    ax = -ax;
    si = ax;
    if ((short)si > (short)0x0023)
        goto loc_c058;
    memoryASet16(ds, 0x6b4e, 0xffff);
loc_c079: // 01ed:a1a9
    memoryASet16(ds, 0x007d, si);
    ax = 0xffff;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_c085() // 01ed:a1b5
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x4400;
    bx = memoryAGet16(ss, bp + 4);
    interrupt(0x21);
    tx = ax;
    ax = dx;
    dx = tx;
    ax &= 0x0080;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c096() // 01ed:a1c6
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 27420, memoryAGet16(ds, bx + 27420) & 0xfdff);
    ah = 0x42;
    al = memoryAGet(ss, bp + 10);
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 8);
    dx = memoryAGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_c0b8;
    goto loc_c0bd;
loc_c0b8: // 01ed:a1e8
    push(ax);
    sub_c048();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
loc_c0bd: // 01ed:a1ed
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c0bf() // 01ed:a1ef
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
        goto loc_c0d2;
    goto loc_c0d6;
loc_c0d2: // 01ed:a202
    push(ax);
    sub_c048();
loc_c0d6: // 01ed:a206
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_c0da() // 01ed:a20a
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
void sub_c0ec() // 01ed:a21c
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    si = memoryAGet16(ss, bp + 8);
    if (si & 0xc000)
        goto loc_c109;
    ax = memoryAGet16(ds, 0x6b44);
    ax &= 0xc000;
    dx = si;
    dx |= ax;
    si = dx;
loc_c109: // 01ed:a239
    if (si & 0x0100)
        goto loc_c112;
    goto loc_c196;
loc_c112: // 01ed:a242
    ax = memoryAGet16(ds, 0x6b46);
    memoryASet16(ss, bp + 10, memoryAGet16(ss, bp + 10) & ax);
    ax = memoryAGet16(ss, bp + 10);
    if (ax & 0x0180)
        goto loc_c127;
    ax = 0x0001;
    push(ax);
    sub_c048();
loc_c127: // 01ed:a257
    ax = 0;
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_be68();
    sp += 0x0006;
    memoryASet16(ss, bp - 2, ax);
    if (ax != 0xffff)
        goto loc_c16a;
    if (!(memoryAGet16(ss, bp + 10) & 0x0080))
        goto loc_c149;
    ax = 0;
    goto loc_c14c;
loc_c149: // 01ed:a279
    ax = 0x0001;
loc_c14c: // 01ed:a27c
    memoryASet16(ss, bp - 2, ax);
    if (!(si & 0x00f0))
        goto loc_c181;
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    ax = 0;
    push(ax);
    sub_c0bf();
    di = ax;
    if ((short)ax >= 0)
        goto loc_c17a;
    goto loc_c228;
loc_c16a: // 01ed:a29a
    if (!(si & 0x0400))
        goto loc_c196;
    ax = 0x0050;
    push(ax);
    sub_c048();
    goto loc_c22a;
loc_c17a: // 01ed:a2aa
    push(di);
    sub_be85();
    cx = pop();
    goto loc_c19b;
loc_c181: // 01ed:a2b1
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    push(memoryAGet16(ss, bp - 2));
    sub_c0bf();
    di = ax;
    if ((short)ax >= 0)
        goto loc_c207;
    goto loc_c228;
loc_c196: // 01ed:a2c6
    memoryASet16(ss, bp - 2, 0x0000);
loc_c19b: // 01ed:a2cb
    push(si);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c230();
    sp += 0x0006;
    di = ax;
    if ((short)ax < 0)
        goto loc_c207;
    ax = 0;
    push(ax);
    push(di);
    sub_c01f();
    cx = pop();
    cx = pop();
    memoryASet16(ss, bp - 4, ax);
    if (!(ax & 0x0080))
        goto loc_c1e0;
    si |= 0x2000;
    if (!(si & 0x8000))
        goto loc_c1ea;
    ax &= 0x00ff;
    ax |= 0x0020;
    dx = 0;
    push(dx);
    push(ax);
    ax = 0x0001;
    push(ax);
    push(di);
    sub_c01f();
    sp += 0x0008;
    goto loc_c1ea;
loc_c1e0: // 01ed:a310
    if (!(si & 0x0200))
        goto loc_c1ea;
    push(di);
    sub_c0da();
loc_c1ea: // 01ed:a31a
    if (memoryAGet16(ss, bp - 2) == 0x0000)
        goto loc_c207;
    if (!(si & 0x00f0))
        goto loc_c207;
    ax = 0x0001;
    push(ax);
    push(ax);
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_be68();
    sp += 0x0008;
loc_c207: // 01ed:a337
    if ((short)di < 0)
        goto loc_c228;
    if (!(si & 0x0300))
        goto loc_c216;
    ax = 0x1000;
    goto loc_c218;
loc_c216: // 01ed:a346
    ax = 0;
loc_c218: // 01ed:a348
    dx = si;
    dx &= 0xf8ff;
    dx |= ax;
    bx = di;
    bx <<= 1;
    memoryASet16(ds, bx + 27420, dx);
loc_c228: // 01ed:a358
    ax = di;
loc_c22a: // 01ed:a35a
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c230() // 01ed:a360
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    al = 0x01;
    cx = memoryAGet16(ss, bp + 8);
    if (cx & 0x0002)
        goto loc_c24a;
    al = 0x02;
    if (cx & 0x0004)
        goto loc_c24a;
    al = 0x00;
loc_c24a: // 01ed:a37a
    push(ds);
    dx = memoryAGet16(ss, bp + 4);
    ds = memoryAGet16(ss, bp + 4 + 2);
    cl = 0xf0;
    cl &= memoryAGet(ss, bp + 8);
    al |= cl;
    ah = 0x3d;
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c276;
    memoryASet16(ss, bp - 2, ax);
    bx = memoryAGet16(ss, bp - 2);
    bx <<= 1;
    ax = memoryAGet16(ss, bp + 8);
    ax &= 0xf8ff;
    ax |= 0x8000;
    memoryASet16(ds, bx + 27420, ax);
    ax = memoryAGet16(ss, bp - 2);
    goto loc_c27a;
loc_c276: // 01ed:a3a6
    push(ax);
    sub_c048();
loc_c27a: // 01ed:a3aa
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c27e() // 01ed:a3ae
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    ax = memoryAGet16(ss, bp + 10);
    ax++;
    if (ax < 0x0002)
        goto loc_c29c;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 27420) & 0x0200))
        goto loc_c2a1;
loc_c29c: // 01ed:a3cc
    ax = 0;
    goto loc_c330;
loc_c2a1: // 01ed:a3d1
    push(memoryAGet16(ss, bp + 10));
    push(memoryAGet16(ss, bp + 8));
    push(memoryAGet16(ss, bp + 6));
    push(memoryAGet16(ss, bp + 4));
    sub_c336();
    sp += 0x0008;
    memoryASet16(ss, bp - 2, ax);
    ax++;
    if (ax < 0x0002)
        goto loc_c2c9;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 27420) & 0x8000))
        goto loc_c2ce;
loc_c2c9: // 01ed:a3f9
    ax = memoryAGet16(ss, bp - 2);
    goto loc_c330;
loc_c2ce: // 01ed:a3fe
    cx = memoryAGet16(ss, bp - 2);
    si = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    di = si;
    bx = si;
    flags.direction = false;
loc_c2d9: // 01ed:a409
    lodsb_es<MemAuto, DirAuto>();
    if (al == 0x1a)
        goto loc_c30d;
    if (al == 0x0d)
        goto loc_c2e8;
    stosb<MemAuto, DirAuto>();
    if (--cx)
        goto loc_c2d9;
    goto loc_c305;
loc_c2e8: // 01ed:a418
    if (--cx)
        goto loc_c2d9;
    push(es);
    push(bx);
    ax = 0x0001;
    push(ax);
    ax = bp - 0x3;
    push(ss);
    push(ax);
    push(memoryAGet16(ss, bp + 4));
    sub_c336();
    sp += 0x0008;
    bx = pop();
    es = pop();
    flags.direction = false;
    al = memoryAGet(ss, bp - 3);
    stosb<MemAuto, DirAuto>();
loc_c305: // 01ed:a435
    if (di != bx)
        goto loc_c30b;
    goto loc_c2a1;
loc_c30b: // 01ed:a43b
    goto loc_c32d;
loc_c30d: // 01ed:a43d
    push(bx);
    ax = 0x0001;
    push(ax);
    cx = -cx;
    stop(/*81*/);
    ax -= ax + flags.carry;
    push(ax);
    push(cx);
    push(memoryAGet16(ss, bp + 4));
    sub_c096();
    sp += 0x0008;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 27420, memoryAGet16(ds, bx + 27420) | 0x0200);
    bx = pop();
loc_c32d: // 01ed:a45d
    di -= bx;
    tx = ax;
    ax = di;
    di = tx;
loc_c330: // 01ed:a460
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c336() // 01ed:a466
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x3f;
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c34c;
    goto loc_c350;
loc_c34c: // 01ed:a47c
    push(ax);
    sub_c048();
loc_c350: // 01ed:a480
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c352() // 01ed:a482
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x4a;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 4);
    interrupt(0x21);
    if (flags.carry)
        goto loc_c366;
    ax = 0xffff;
    goto loc_c36c;
loc_c366: // 01ed:a496
    push(bx);
    push(ax);
    sub_c048();
    ax = pop();
loc_c36c: // 01ed:a49c
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c36e() // 01ed:a49e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryAGet16(ds, bx + 27420) & 0x0800))
        goto loc_c391;
    ax = 0x0002;
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(memoryAGet16(ss, bp + 4));
    sub_c096();
    sp += 0x0008;
loc_c391: // 01ed:a4c1
    push(ds);
    ah = 0x40;
    bx = memoryAGet16(ss, bp + 4);
    cx = memoryAGet16(ss, bp + 10);
    dx = memoryAGet16(ss, bp + 6);
    ds = memoryAGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c3b1;
    push(ax);
    bx = memoryAGet16(ss, bp + 4);
    bx <<= 1;
    memoryASet16(ds, bx + 27420, memoryAGet16(ds, bx + 27420) | 0x1000);
    ax = pop();
    goto loc_c3b5;
loc_c3b1: // 01ed:a4e1
    push(ax);
    sub_c048();
loc_c3b5: // 01ed:a4e5
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c3cc() // 01ed:a4fc
{
    CStackGuard sg(0, false);
    if (dx == memoryAGet16(cs, 0xa4f0))
        goto loc_c40a;
    ds = dx;
    ds = memoryAGet16(ds, 0x0002);
    if (memoryAGet16(ds, 0x0002) == 0x0000)
        goto loc_c3e7;
    memoryASet16(cs, 0xa4f2, ds);
    goto loc_c41f;
loc_c3e7: // 01ed:a517
    ax = ds;
    if (ax == memoryAGet16(cs, 0xa4f0))
        goto loc_c405;
    ax = memoryAGet16(ds, 0x0008);
    memoryASet16(cs, 0xa4f2, ax);
    push(ds);
    ax = 0;
    push(ax);
    sub_c49f();
    ds = memoryAGet16(cs, 0xa4f6);
    goto loc_c428;
loc_c405: // 01ed:a535
    dx = memoryAGet16(cs, 0xa4f0);
loc_c40a: // 01ed:a53a
    memoryASet16(cs, 0xa4f0, 0x0000);
    memoryASet16(cs, 0xa4f2, 0x0000);
    memoryASet16(cs, 0xa4f4, 0x0000);
loc_c41f: // 01ed:a54f
    ds = memoryAGet16(cs, 0xa4f6);
    push(dx);
    ax = 0;
    push(ax);
loc_c428: // 01ed:a558
    sub_b82b();
    ax = pop();
    ax = pop();
}
void sub_c42e() // 01ed:a55e
{
    CStackGuard sg(0, false);
    ds = dx;
    push(ds);
    es = memoryAGet16(ds, 0x0002);
    memoryASet16(ds, 0x0002, 0x0000);
    memoryASet16(ds, 0x0008, es);
    if (dx == memoryAGet16(cs, 0xa4f0))
        goto loc_c474;
    if (memoryAGet16(es, 0x0002) != 0x0000)
        goto loc_c474;
    ax = memoryAGet16(ds, 0x0000);
    bx = pop();
    push(es);
    memoryASet16(es, 0x0000, memoryAGet16(es, 0x0000) + ax);
    cx = es;
    dx += ax;
    es = dx;
    if (memoryAGet16(es, 0x0002) != 0x0000)
        goto loc_c46d;
    memoryASet16(es, 0x0008, cx);
    goto loc_c477;
loc_c46d: // 01ed:a59d
    memoryASet16(es, 0x0002, cx);
    goto loc_c477;
loc_c474: // 01ed:a5a4
    sub_c4c8();
loc_c477: // 01ed:a5a7
    es = pop();
    ax = es;
    ax += memoryAGet16(es, 0x0000);
    ds = ax;
    if (memoryAGet16(ds, 0x0002) == 0x0000)
        goto loc_c489;
    return;
loc_c489: // 01ed:a5b9
    ax = memoryAGet16(ds, 0x0000);
    memoryASet16(es, 0x0000, memoryAGet16(es, 0x0000) + ax);
    ax = es;
    bx = ds;
    bx += memoryAGet16(ds, 0x0000);
    es = bx;
    memoryASet16(es, 0x0002, ax);
    bx = ds;
    if (bx == memoryAGet16(ds, 0x0006))
        goto loc_c4c0;
    es = memoryAGet16(ds, 0x0006);
    ds = memoryAGet16(ds, 0x0004);
    memoryASet16(ds, 0x0006, es);
    memoryASet16(es, 0x0004, ds);
    memoryASet16(cs, 0xa4f4, ds);
    ds = bx;
    return;
loc_c4c0: // 01ed:a5f0
    memoryASet16(cs, 0xa4f4, 0x0000);
}
void sub_c49f() // 01ed:a5cf
{
    CStackGuard sg(0, false);
    bx = ds;
    if (bx == memoryAGet16(ds, 0x0006))
        goto loc_c4c0;
    es = memoryAGet16(ds, 0x0006);
    ds = memoryAGet16(ds, 0x0004);
    memoryASet16(ds, 0x0006, es);
    memoryASet16(es, 0x0004, ds);
    memoryASet16(cs, 0xa4f4, ds);
    ds = bx;
    return;
loc_c4c0: // 01ed:a5f0
    memoryASet16(cs, 0xa4f4, 0x0000);
}
void sub_c4c8() // 01ed:a5f8
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(cs, 0xa4f4);
    if (!ax)
        goto loc_c4f0;
    bx = ss;
    flags.interrupts = false;
    ss = ax;
    es = memoryAGet16(ss, 0x0006);
    memoryASet16(ss, 0x0006, ds);
    memoryASet16(ds, 0x0004, ss);
    ss = bx;
    flags.interrupts = true;
    memoryASet16(es, 0x0004, ds);
    memoryASet16(ds, 0x0006, es);
    return;
loc_c4f0: // 01ed:a620
    memoryASet16(cs, 0xa4f4, ds);
    memoryASet16(ds, 0x0004, ds);
    memoryASet16(ds, 0x0006, ds);
}
void sub_c4fe() // 01ed:a62e
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    memoryASet16(cs, 0xa4f6, ds);
    dx = memoryAGet16(ss, bp + 6);
    if (!dx)
        goto loc_c51e;
    if (dx != memoryAGet16(cs, 0xa4f2))
        goto loc_c51b;
    sub_c3cc();
    goto loc_c51e;
loc_c51b: // 01ed:a64b
    sub_c42e();
loc_c51e: // 01ed:a64e
    ds = memoryAGet16(cs, 0xa4f6);
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c527() // 01ed:a657
{
    CStackGuard sg(0, false);
    push(ax);
    ds = memoryAGet16(cs, 0xa4f6);
    ax = 0;
    push(ax);
    push(ax);
    sub_b86a();
    bx = pop();
    bx = pop();
    ax &= 0x000f;
    if (ax == 0)
        goto loc_c54e;
    dx = 0x0010;
    dx -= ax;
    ax = 0;
    ds = memoryAGet16(cs, 0xa4f6);
    push(ax);
    push(dx);
    sub_b86a();
    bx = pop();
    bx = pop();
loc_c54e: // 01ed:a67e
    ax = pop();
    push(ax);
    bx = 0;
    bl = ah;
    cl = 0x04;
    bx >>= cl;
    ax <<= cl;
    ds = memoryAGet16(cs, 0xa4f6);
    push(bx);
    push(ax);
    sub_b86a();
    bx = pop();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_c584;
    memoryASet16(cs, 0xa4f0, dx);
    memoryASet16(cs, 0xa4f2, dx);
    ds = dx;
    memoryASet16(ds, 0x0000, bx);
    memoryASet16(ds, 0x0002, dx);
    ax = 0x0004;
    return;
loc_c584: // 01ed:a6b4
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
}
void sub_c588() // 01ed:a6b8
{
    CStackGuard sg(0, false);
    push(ax);
    bx = 0;
    bl = ah;
    cl = 0x04;
    bx >>= cl;
    ax <<= cl;
    ds = memoryAGet16(cs, 0xa4f6);
    push(bx);
    push(ax);
    sub_b86a();
    bx = pop();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_c5bd;
    cx = memoryAGet16(cs, 0xa4f2);
    memoryASet16(cs, 0xa4f2, dx);
    ds = dx;
    memoryASet16(ds, 0x0000, bx);
    memoryASet16(ds, 0x0002, cx);
    ax = 0x0004;
    return;
loc_c5bd: // 01ed:a6ed
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
}
void sub_c5c1() // 01ed:a6f1
{
    CStackGuard sg(0, false);
    bx = dx;
    memoryASet16(ds, 0x0000, memoryAGet16(ds, 0x0000) - ax);
    dx += memoryAGet16(ds, 0x0000);
    ds = dx;
    memoryASet16(ds, 0x0000, ax);
    memoryASet16(ds, 0x0002, bx);
    bx = dx;
    bx += memoryAGet16(ds, 0x0000);
    ds = bx;
    memoryASet16(ds, 0x0002, dx);
    ax = 0x0004;
}
void sub_c5e4() // 01ed:a714
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bp);
    bp = sp;
    dx = 0;
    ax = memoryAGet16(ss, bp + 4);
    goto loc_c5f7;
    //   gap of 9 bytes
loc_c5f7: // 01ed:a727
    push(si);
    push(di);
    memoryASet16(cs, 0xa4f6, ds);
    cx = ax;
    cx |= dx;
    if (!cx)
        goto loc_c662;
    flags.carry = (ax + 0x0013) >= 0x10000;
    ax += 0x0013;
    tl = flags.carry;
    flags.carry = (dx + 0x0000 + tl) >= 0x10000;
    dx += tl;
    if (flags.carry)
        goto loc_c64d;
    if (dx & 0xfff0)
        goto loc_c64d;
    cl = 0x04;
    ax >>= cl;
    dx <<= cl;
    ah |= dl;
    dx = memoryAGet16(cs, 0xa4f0);
    if (!dx)
        goto loc_c643;
    dx = memoryAGet16(cs, 0xa4f4);
    if (!dx)
        goto loc_c63e;
    bx = dx;
loc_c62e: // 01ed:a75e
    ds = dx;
    if (memoryAGet16(ds, 0x0000) >= ax)
        goto loc_c652;
    dx = memoryAGet16(ds, 0x0006);
    if (dx != bx)
        goto loc_c62e;
loc_c63e: // 01ed:a76e
    sub_c588();
    goto loc_c662;
loc_c643: // 01ed:a773
    sub_c527();
    goto loc_c662;
loc_c648: // 01ed:a778
    sub_c5c1();
    goto loc_c662;
loc_c64d: // 01ed:a77d
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    goto loc_c662;
loc_c652: // 01ed:a782
    if (memoryAGet16(ds, 0x0000) > ax)
        goto loc_c648;
    sub_c49f();
    bx = memoryAGet16(ds, 0x0008);
    memoryASet16(ds, 0x0002, bx);
    ax = 0x0004;
loc_c662: // 01ed:a792
    ds = memoryAGet16(cs, 0xa4f6);
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c7be() // 01ed:a8ee
{
//    CStackGuardFar sg(8, true);
    push(0x7777);
    cx = pop();
    push(cs);
    push(cx);
    cx = 0x0001;
    goto loc_c7d4;
    //   gap of 14 bytes
loc_c7d4: // 01ed:a904
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
        goto loc_c7f3;
    if (!dx)
        goto loc_c858;
    if (!bx)
        goto loc_c858;
loc_c7f3: // 01ed:a923
    if (di & 0x0001)
        goto loc_c815;
    if (!(dx & 0x8000))
        goto loc_c807;
    dx = -dx;
    ax = -ax;
    stop(/*81*/);
    dx -= flags.carry;
    di |= 0x000c;
loc_c807: // 01ed:a937
    if (!(cx & 0x8000))
        goto loc_c815;
    cx = -cx;
    bx = -bx;
    stop(/*81*/);
    cx -= flags.carry;
    di ^= 0x0004;
loc_c815: // 01ed:a945
    bp = cx;
    cx = 0x0020;
    push(di);
    di = 0;
    si = 0;
loc_c81f: // 01ed:a94f
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl(dx, 0x0001);
    si = rcl(si, 0x0001);
    di = rcl(di, 0x0001);
    if (di < bp)
        goto loc_c836;
    if (di > bp)
        goto loc_c831;
    if (si < bx)
        goto loc_c836;
loc_c831: // 01ed:a961
    flags.carry = si < bx;
    si -= bx;
    di -= bp + flags.carry;
    ax++;
loc_c836: // 01ed:a966
    if (--cx)
        goto loc_c81f;
    bx = pop();
    if (!(bx & 0x0002))
        goto loc_c845;
    ax = si;
    dx = di;
    bx >>= 1;
loc_c845: // 01ed:a975
    if (!(bx & 0x0004))
        goto loc_c852;
    dx = -dx;
    ax = -ax;
    stop(/*81*/);
    dx -= flags.carry;
loc_c852: // 01ed:a982
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
    return;
loc_c858: // 01ed:a988
    div(bx);
    if (!(di & 0x0002))
        goto loc_c861;
    tx = ax;
    ax = dx;
    dx = tx;
loc_c861: // 01ed:a991
    dx = 0;
    goto loc_c852;
}
void sub_c865() // 01ed:a995
{
//    CStackGuardFar sg(0, false);
    push(0x7777);
    es = pop();
    push(cs);
    push(es);
    if ((short)cx >= 0)
        goto loc_c878;
    bx = ~bx;
    cx = ~cx;
    flags.carry = (bx + 0x0001) >= 0x10000;
    bx += 0x0001;
    cx += flags.carry;
    goto loc_c8a7;
loc_c878: // 01ed:a9a8
    flags.carry = (ax + bx) >= 0x10000;
    ax += bx;
    if (!flags.carry)
        goto loc_c880;
    dx += 0x1000;
loc_c880: // 01ed:a9b0
    ch = cl;
    cl = 0x04;
    ch <<= cl;
    dh += ch;
    ch = al;
    ax >>= cl;
    dx += ax;
    al = ch;
    ax &= 0x000f;
//    cs = pop();
    es = 0x99b0; pop(); pop(); // wtf?
    return;
    //   gap of 19 bytes
loc_c8a7: // 01ed:a9d7
    flags.carry = ax < bx;
    ax -= bx;
    if (!flags.carry)
        goto loc_c8af;
    dx -= 0x1000;
loc_c8af: // 01ed:a9df
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
//    cs = pop();
    assert(pop() == 0x7777);
}
void sub_c8c5() // 01ed:a9f5
{
    CStackGuardFar sg(8-2, true);
    push(0x7777);
    es = pop();
    push(cs);
    push(es);
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
void sub_c8e4() // 01ed:aa14
{
    CStackGuard sg(0, false);
    push(si);
    tx = ax;
    ax = si;
    si = tx;
    tx = ax;
    ax = dx;
    dx = tx;
    if (!(ax & ax))
        goto loc_c8ed;
    mul(bx);
loc_c8ed: // 01ed:aa1d
    if (cx == 0)
        goto loc_c8f4;
    tx = ax;
    ax = cx;
    cx = tx;
    mul(si);
    ax += cx;
loc_c8f4: // 01ed:aa24
    tx = ax;
    ax = si;
    si = tx;
    mul(bx);
    dx += si;
    si = pop();
}
void sub_c8fb() // 01ed:aa2b
{
    CStackGuard sg(0, false);
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
        return;
    flags.carry = ax < bx;
    flags.zero = ax == bx;
}
void sub_c91e() // 01ed:aa4e
{
//    CStackGuard sg(0, true);
    push(0x7777);
    goto loc_c91e;
loc_20ba: // 01ed:01ea
    cx = 0x001e;
    dx = 0x003b;
    ds = memoryAGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    ax += memoryAGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df: // 01ed:020f
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x6be4, dx);
    memoryASet16(ds, 0x6be6, ax);
    sub_2152();
    sub_9a77();
    sub_28d7();
    sub_2128();
    sub_2439();
    sub_9947();
    sub_9c89();
    ax = 0x0003;
    push(ax);
    sub_8ff0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b78a();
    sp++;
    sp++;
loc_2126: // 01ed:0256
    bp = pop();
    assert(pop() == 0x7777);
    return;
    //   gap of 42998 bytes
loc_c91e: // 01ed:aa4e
    memoryASet16(ds, 0x6bb0, pop());
    memoryASet16(ds, 0x6bb2, pop());
    memoryASet16(ds, 0x6bb4, pop());
    memoryASet16(cs, 0xaa4c, ds);
    memoryASet16(ds, 0x6bb6, si);
    memoryASet16(ds, 0x6bb8, di);
    flags.direction = false;
    es = memoryAGet16(ds, 0x0079);
    si = 0x0080;
    ah = 0;
    lodsb_es<MemAuto, DirAuto>();
    ax++;
    bp = es;
    tx = si;
    si = dx;
    dx = tx;
    tx = ax;
    ax = bx;
    bx = tx;
    si = memoryAGet16(ds, 0x0073);
    si++;
    si++;
    cx = 0x0001;
    if (memoryAGet(ds, 0x007b) < 0x03)
        goto loc_c96a;
    es = memoryAGet16(ds, 0x0075);
    di = si;
    cl = 0x7f;
    al = 0;
    repne_scasb<MemAuto, DirAuto>(al);
    if (cx == 0)
        goto loc_c9d5;
    cl ^= 0x7f;
loc_c96a: // 01ed:aa9a
    push(ax);
    ax = cx;
    ax += bx;
    ax++;
    ax &= 0xfffe;
    di = sp;
    flags.carry = di < ax;
    di -= ax;
    if (flags.carry)
        goto loc_c9d5;
    sp = di;
    push(es);
    ds = pop();
    push(ss);
    es = pop();
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
loc_c991: // 01ed:aac1
    sub_c9ad();
    if (!flags.zero && !flags.carry)
        goto loc_c99d;
loc_c996: // 01ed:aac6
    if (flags.carry)
        goto loc_c9d8;
    sub_c9ad();
    if (!flags.zero && !flags.carry)
        goto loc_c996;
loc_c99d: // 01ed:aacd
    if (al == 0x20)
        goto loc_c9a9;
    if (al == 0x0d)
        goto loc_c9a9;
    if (al != 0x09)
        goto loc_c991;
loc_c9a9: // 01ed:aad9
    al = 0;
    goto loc_c991;
    //   gap of 40 bytes
loc_c9d5: // 01ed:ab05
    goto loc_20ba;
loc_c9d8: // 01ed:ab08
    cx = pop();
    cx += dx;
    ds = memoryAGet16(cs, 0xaa4c);
    memoryASet16(ds, 0x6baa, bx);
    bx++;
    bx += bx;
    bx += bx;
    si = sp;
    bp = sp;
    flags.carry = bp < bx;
    bp -= bx;
    if (flags.carry)
        goto loc_c9d5;
    sp = bp;
    memoryASet16(ds, 0x6bac, bp);
    memoryASet16(ds, 0x6bae, ss);
loc_c9fb: // 01ed:ab2b
    if (cx == 0)
        goto loc_ca0e;
    memoryASet16(ss, bp, si);
    memoryASet16(ss, bp + 2, ss);
    bp += 0x0004;
loc_ca06: // 01ed:ab36
    lodsb_ss<MemAuto, DirAuto>();
    if (--cx && al)
        goto loc_ca06;
    if (false)
        goto loc_c9fb;
loc_ca0e: // 01ed:ab3e
    ax = 0;
    memoryASet16(ss, bp, ax);
    memoryASet16(ss, bp + 2, ax);
    ds = memoryAGet16(cs, 0xaa4c);
    si = memoryAGet16(ds, 0x6bb6);
    di = memoryAGet16(ds, 0x6bb8);
    push(memoryAGet16(ds, 0x6bb4));
    push(memoryAGet16(ds, 0x6bb2));
    ax = memoryAGet16(ds, 0x6baa);
    memoryASet16(ds, 0x0069, ax);
    ax = memoryAGet16(ds, 0x6bae);
    memoryASet16(ds, 0x006d, ax);
    ax = memoryAGet16(ds, 0x6bac);
    memoryASet16(ds, 0x006b, ax);
//    stop(/*2*/); // (jmp word ptr [0x6bb0]) jump Indirect memoryAGet16(ds, 0x6bb0)
}
// INJECT: Error: cannot inject flag in sub_c9ad() because of being label!
void sub_c9ad() // 01ed:aadd
{
    CStackGuard sg(0, false);
    if (!ax)
        goto loc_c9b8;
    dx++;
    stosb<MemAuto, DirAuto>();
    if (al)
        goto loc_c9b8;
    bx++;
loc_c9b8: // 01ed:aae8
    tl = al;
    al = ah;
    ah = tl;
    al = 0;
    flags.carry = true;
    if (cx == 0)
    {
        flags.zero = true;
        goto loc_c9d4;
    }
    lodsb<MemAuto, DirAuto>();
    cx--;
    al -= 0x22;
    if (al == 0)
    {
        flags.zero = true;
        goto loc_c9d4;
    }
    al += 0x22;
    if (al != 0x5c)
    {
        flags.zero = false;
        goto loc_c9d2;
    }
    if (memoryAGet(ds, si) != 0x22)
    {
        flags.zero = false;
        goto loc_c9d2;
    }
    lodsb<MemAuto, DirAuto>();
    cx--;
    flags.zero = cx == 0;
loc_c9d2: // 01ed:ab02
    flags.carry = false;
loc_c9d4: // 01ed:ab04
    return;
}
void sub_ca53() // 01ed:ab83
{
    CStackGuard sg(0, true);
    push(0x7777);
    goto loc_ca53;
loc_1fe5: // 01ed:0115
    ds = memoryAGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryAGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002d;
    goto loc_20c0;
    //   gap of 193 bytes
loc_20c0: // 01ed:01f0
    ds = memoryAGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memoryASet(ds, bx + si, memoryAGet(ds, bx + si) + al);
    ax += memoryAGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryAGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df: // 01ed:020f
    if (memoryAGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryAGet16(ss, bp + 6);
    es = memoryAGet16(ss, bp + 6 + 2);
    ax = memoryAGet16(es, bx + 6);
    dx = memoryAGet16(es, bx + 4);
    memoryASet16(ds, 0x6be4, dx);
    memoryASet16(ds, 0x6be6, ax);
    sub_2152();
    sub_9a77();
    sub_28d7();
    sub_2128();
    sub_2439();
    sub_9947();
    sub_9c89();
    ax = 0x0003;
    push(ax);
    sub_8ff0();
    sp++;
    sp++;
    ax = 0;
    push(ax);
    sub_b78a();
    sp++;
    sp++;
loc_2126: // 01ed:0256
    bp = pop();
    assert(pop() == 0x7777);
    return;
    //   gap of 43307 bytes
loc_ca53: // 01ed:ab83
    push(cs);
    ds = pop();
    dx = 0xab71;
    ah = 0x09;
    interrupt(0x21);
    goto loc_1fe5;
}
void sub_ca60() // 0ca6:0000
{
    CStackGuard sg(0, false);
    si = 0x4de6;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    bx = memoryAGet16(es, di + 28);
    push(bx);
    bx = di;
    push(es);
    sub_cf8d();
    ds = pop();
    si = bx;
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 19916);
    ds = pop();
    callIndirect(cs*16+ax);
}
void sub_ca8b() // 0ca6:002b
{
    CStackGuard sg(0, false);
    bx = 0x0101;
loc_ca8e: // 0ca6:002e
    dx = 0x03c4;
    ah = bh;
    al = 0x02;
    out(dx, ax);
    sub_d02f();
    sub_caa7();
    bl++;
    bh <<= 1;
    if ((char)bh > (char)0x08)
        return;
    goto loc_ca8e;
    //   gap of 42 bytes
}
void sub_caa7() // 0ca6:0047
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(di);
    push(ds);
    bp = 0x1228;
    ds = bp;
    bp = memoryAGet16(ds, 0x5429);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_cabd: // 0ca6:005d
    if (dl == ch)
        goto loc_cacf;
    dl--;
    cx >>= 1;
    rep_stosw<MemAuto, DirAuto>();
    cl = dh;
    di -= cx;
    di += bp;
    goto loc_cabd;
loc_cacf: // 0ca6:006f
    di = pop();
    assert(pop() == 0x7777);
}
void sub_cbd9() // 0ca6:0179
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = false;
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    memoryASet16(es, di + 24, 0x0014);
    memoryASet16(es, di + 26, 0x0019);
    memoryASet(ds, 0x541f, 0x02);
    memoryASet(ds, 0x5420, 0x01);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bx + 19930));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cc41() // 0ca6:01e1
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    es = bp;
    bp = memoryAGet16(ds, 0x541d);
    bp <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bp + 21557));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cc5f() // 0ca6:01ff
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    assert(bx == 4);
    //stop(/*2*/); // (jmp word ptr [bx + 0x545d]) jump Indirect memoryAGet16(ds, bx + 21597)
loc_cc6e: // 0ca6:020e
    ax = 0x000d;
    interrupt(0x10);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cc7b() // 0ca6:021b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet16(ds, 0x5313, dx);
    memoryASet16(ds, 0x5311, ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cc92() // 0ca6:0232
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    if (cl != 0x00)
        goto loc_cc9e;
    goto loc_cd0b;
loc_cc9e: // 0ca6:023e
    if ((char)cl > (char)0x02)
        goto loc_cd0b;
    ax = 0x1228;
    ds = ax;
    es = ax;
    push(cx);
    di = 0x5310;
    cx = 0x0001;
    flags.direction = false;
    al = 0;
    rep_stosb<MemAuto, DirAuto>();
    cx = pop();
    si = 0x5415;
    ch = 0;
    cl--;
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    assert(bx == 4);
    goto loc_ccc8;
    //stop(/*2*/); // (jmp word ptr [bx + 0x5469]) jump Indirect memoryAGet16(ds, bx + 21609)
loc_ccc8: // 0ca6:0268
    memoryASet16(ds, si + 2, 0xa000);
    memoryASet16(ds, si, 0x0000);
    if (memoryAGet16(ds, 0x541d) != 0x0005)
        goto loc_cce7;
    memoryASet16(ds, si + 6, 0xa400);
    memoryASet16(ds, si + 4, 0x0000);
    sub_d02e();
    goto loc_cd0b;
loc_cce7: // 0ca6:0287
    memoryASet16(ds, si + 6, 0xa200);
    memoryASet16(ds, si + 4, 0x0000);
    goto loc_cd0b;
    //   gap of 24 bytes
loc_cd0b: // 0ca6:02ab
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cd11() // 0ca6:02b1
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    es = ax;
    bp = memoryAGet16(ds, 0x541d);
    bp <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bp + 21569));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cd2e() // 0ca6:02ce
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    ax = 0x0002;
    interrupt(0x10);
    si = 0x529c;
    bh = 0;
    dx = 0x0101;
    ah = 0x02;
    interrupt(0x10);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    si = 0x52b4;
    di = 0x548b;
    bh = 0x00;
    cx = 0x0006;
    dx = 0x0a21;
loc_cd5d: // 0ca6:02fd
    if (memoryAGet(ds, di) != 0x01)
        goto loc_cd70;
    ah = 0x02;
    interrupt(0x10);
    push(dx);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    dx = pop();
    dh++;
loc_cd70: // 0ca6:0310
    si += 0x000f;
    di++;
    if (--cx)
        goto loc_cd5d;
loc_cd76: // 0ca6:0316
    sync();
    al = 0x3c;
    push(cs);
    cs = 0x01ed;
    sub_9aca();
    assert(cs == 0x0ca6);
    if (!flags.zero)
        goto loc_cd8a;
    al = 0x3d;
    push(cs);
    cs = 0x01ed;
    sub_9aca();
    assert(cs == 0x0ca6);
    if (!flags.zero)
        goto loc_cd98;
    goto loc_cd76;
loc_cd8a: // 0ca6:032a
    memoryASet16(ds, 0x541d, 0x0001);
    memoryASet16(ds, 0x530e, 0x0040);
    goto loc_cdab;
loc_cd98: // 0ca6:0338
    memoryASet16(ds, 0x541d, 0x0002);
    memoryASet16(ds, 0x530e, 0x0040);
    goto loc_cdab;
    //   gap of 5 bytes
loc_cdab: // 0ca6:034b
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cdb1() // 01ed:aee1
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    if (bx == 0x0000)
        goto loc_cdde;
    if ((short)bx > (short)0x0001)
        goto loc_cdde;
    ax = 0x1228;
    ds = ax;
    cx = 0;
    tl = memoryAGet(ds, bx + 21263);
    memoryASet(ds, bx + 21263, cl);
    cl = tl;
    si = 0x5415;
    bp = memoryAGet16(ds, 0x541d);
    bp <<= 1;
    assert(bp == 4);
//    stop(/*2*/); // (jmp word ptr ds:[bp + 0x5475]) jump Indirect memoryAGet16(ds, bp + 21621)
loc_cdd9: // 0ca6:0379
    sub_d121();
loc_cdde: // 0ca6:037e
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ce87() // 0ca6:0427
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(es, di + 6);
    push(cx);
loc_ce8c: // 0ca6:042c
    cx >>= 1;
    if (cx == 0)
        goto loc_ce94;
    ax <<= 1;
    goto loc_ce8c;
loc_ce94: // 0ca6:0434
    cx = pop();
    if (!(memoryAGet16(es, di + 28) & 0x0200))
        goto loc_cea4;
    ax++;
    memoryASet16(es, di + 28, memoryAGet16(es, di + 28) & 0xfdff);
loc_cea4: // 0ca6:0444
    memoryASet16(ds, 0x5423, ax);
    ax = 0x0014;
    if (memoryAGet(ds, 0x541f) == 0x01)
        goto loc_ceb5;
    ax = memoryAGet16(es, di + 10);
loc_ceb5: // 0ca6:0455
    push(cx);
loc_ceb6: // 0ca6:0456
    cx >>= 1;
    if (cx == 0)
        goto loc_cebe;
    ax <<= 1;
    goto loc_ceb6;
loc_cebe: // 0ca6:045e
    cx = pop();
    memoryASet16(ds, 0x542b, ax);
    ax = memoryAGet16(es, di + 20);
    push(cx);
loc_cec7: // 0ca6:0467
    cx >>= 1;
    if (cx == 0)
        goto loc_cecf;
    ax <<= 1;
    goto loc_cec7;
loc_cecf: // 0ca6:046f
    cx = pop();
    if (!(memoryAGet16(es, di + 28) & 0x0400))
        goto loc_cedf;
    ax++;
    memoryASet16(es, di + 28, memoryAGet16(es, di + 28) & 0xfbff);
loc_cedf: // 0ca6:047f
    memoryASet16(ds, 0x5421, ax);
    ax = 0x0014;
    if (memoryAGet(ds, 0x5420) == 0x01)
        goto loc_cef0;
    ax = memoryAGet16(es, di + 24);
loc_cef0: // 0ca6:0490
    push(cx);
loc_cef1: // 0ca6:0491
    cx >>= 1;
    if (cx == 0)
        goto loc_cef9;
    ax <<= 1;
    goto loc_cef1;
loc_cef9: // 0ca6:0499
    cx = pop();
    memoryASet16(ds, 0x5429, ax);
    ax = memoryAGet16(es, di + 30);
    push(cx);
loc_cf02: // 0ca6:04a2
    cx >>= 1;
    if (cx == 0)
        goto loc_cf0a;
    ax <<= 1;
    goto loc_cf02;
loc_cf0a: // 0ca6:04aa
    cx = pop();
    memoryASet16(ds, 0x5431, ax);
    cx = 0x0008;
    ax = memoryAGet16(es, di + 8);
    push(cx);
loc_cf16: // 0ca6:04b6
    cx >>= 1;
    if (cx == 0)
        goto loc_cf1e;
    ax <<= 1;
    goto loc_cf16;
loc_cf1e: // 0ca6:04be
    cx = pop();
    if (!(memoryAGet16(es, di + 28) & 0x0100))
        goto loc_cf31;
    ax += memoryAGet16(es, di + 38);
    memoryASet16(es, di + 28, memoryAGet16(es, di + 28) & 0x00fe);
loc_cf31: // 0ca6:04d1
    memoryASet16(ds, 0x542f, ax);
    ax = 0x0019;
    if (memoryAGet(ds, 0x541f) == 0x01)
        goto loc_cf42;
    ax = memoryAGet16(es, di + 12);
loc_cf42: // 0ca6:04e2
    push(cx);
loc_cf43: // 0ca6:04e3
    cx >>= 1;
    if (cx == 0)
        goto loc_cf4b;
    ax <<= 1;
    goto loc_cf43;
loc_cf4b: // 0ca6:04eb
    cx = pop();
    memoryASet16(ds, 0x5427, ax);
    ax = memoryAGet16(es, di + 22);
    push(cx);
loc_cf54: // 0ca6:04f4
    cx >>= 1;
    if (cx == 0)
        goto loc_cf5c;
    ax <<= 1;
    goto loc_cf54;
loc_cf5c: // 0ca6:04fc
    cx = pop();
    memoryASet16(ds, 0x542d, ax);
    ax = 0x0019;
    if (memoryAGet(ds, 0x5420) == 0x01)
        goto loc_cf6e;
    ax = memoryAGet16(es, di + 26);
loc_cf6e: // 0ca6:050e
    push(cx);
loc_cf6f: // 0ca6:050f
    cx >>= 1;
    if (cx == 0)
        goto loc_cf77;
    ax <<= 1;
    goto loc_cf6f;
loc_cf77: // 0ca6:0517
    cx = pop();
    memoryASet16(ds, 0x5425, ax);
    ax = memoryAGet16(es, di + 32);
    push(cx);
loc_cf80: // 0ca6:0520
    cx >>= 1;
    if (cx == 0)
        goto loc_cf88;
    ax <<= 1;
    goto loc_cf80;
loc_cf88: // 0ca6:0528
    cx = pop();
    memoryASet16(ds, 0x5433, ax);
}
void sub_cf8d() // 0ca6:052d
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(bp);
    bx = di;
    if (memoryAGet(ds, 0x541f) == 0x02)
        goto loc_cfd6;
    ax = memoryAGet16(ds, 0x542f);
    mul(memoryAGet16(ds, 0x542b));
    ax += memoryAGet16(ds, 0x5423);
    si = ax;
    if (memoryAGet(ds, 0x541f) != 0x01)
        goto loc_cfbd;
    bp = memoryAGet16(es, bx);
    bp <<= 1;
    bp <<= 1;
    ax = memoryAGet16(ds, bp + 21525);
    ds = memoryAGet16(ds, bp + 21525 + 2);
    goto loc_cfc1;
loc_cfbd: // 0ca6:055d
    ax = memoryAGet16(es, bx + 2);
    ds = memoryAGet16(es, bx + 2 + 2);
loc_cfc1: // 0ca6:0561
    si += ax;
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(bx);
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0ca6);
    bx = pop();
    ds = dx;
    si = ax;
    es = pop();
loc_cfd6: // 0ca6:0576
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x542d);
    mul(memoryAGet16(ds, 0x5429));
    ax += memoryAGet16(ds, 0x5421);
    di = ax;
    if (memoryAGet(ds, 0x5420) != 0x01)
        goto loc_d000;
    bp = memoryAGet16(es, bx + 14);
    bp <<= 1;
    bp <<= 1;
    ax = memoryAGet16(ds, bp + 21525);
    es = memoryAGet16(ds, bp + 21525 + 2);
    ds = pop();
    goto loc_d010;
loc_d000: // 0ca6:05a0
    ax = memoryAGet16(es, bx + 16);
    es = memoryAGet16(es, bx + 16 + 2);
    ds = pop();
    di += ax;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0ca6);
    es = dx;
    di = ax;
loc_d010: // 0ca6:05b0
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    assert(pop() == 0x7777);
}
void sub_d016() // 0ca6:05b6
{
    CStackGuard sg(0, false);
    dx = bx;
    dx <<= 1;
    dx <<= 1;
    ax = dx;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dx += ax;
    ax <<= 1;
    ax += dx;
    ax -= bx;
}
void sub_d02e() // 0ca6:05ce
{
    CStackGuard sg(0, false);
}
void sub_d02f() // 0ca6:05cf
{
    CStackGuard sg(0, false);
    ax = 0;
    dl = memoryAGet(ds, si + 34);
    if (!(bh & dl))
        goto loc_d03a;
    al = 0x01;
loc_d03a: // 0ca6:05da
    dl = memoryAGet(ds, si + 35);
    if (!(bh & dl))
        goto loc_d043;
    al |= 0x02;
loc_d043: // 0ca6:05e3
    dl = memoryAGet(ds, si + 36);
    if (!(bh & dl))
        goto loc_d04c;
    al |= 0x04;
loc_d04c: // 0ca6:05ec
    dl = memoryAGet(ds, si + 37);
    if (!(bh & dl))
        goto loc_d055;
    al |= 0x08;
loc_d055: // 0ca6:05f5
    dl = al;
    dl <<= 1;
    dl <<= 1;
    dl <<= 1;
    dl <<= 1;
    al |= dl;
    ah = al;
}
void sub_d080() // 0ca6:0620
{
    CStackGuard sg(0, false);
    di = 0x5311;
    tx = di;
    di = memoryAGet16(ds, tx);
    es = memoryAGet16(ds, tx + 2);
    si = ax;
    ds = dx;
    sub_d016();
    di += ax;
    di += 0x0033;
    si += 0x0033;
    push(ds);
    ax = 0x1228;
    ds = ax;
    if (memoryAGet16(ds, 0x541d) != 0x0005)
        goto loc_d0a4;
    di += 0x0030;
loc_d0a4: // 0ca6:0644
    ds = pop();
    cx = 0x0018;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
}
void sub_d0ad() // 0ca6:064d
{
    CStackGuard sg(0, false);
    dx = 0x03ce;
    cx = 0x0007;
loc_d0b3: // 0ca6:0653
    lodsw<MemAuto, DirAuto>();
    out(dx, ax);
    if (--cx)
        goto loc_d0b3;
    dx = 0x03c4;
    ax = memoryAGet16(ds, si);
    out(dx, ax);
}
void sub_d0bf() // 0ca6:065f
{
    CStackGuard sg(0, false);
}
void sub_d0d7() // 0ca6:0677
{
    CStackGuard sg(0, false);
    si = 0x5311;
    tx = si;
    si = memoryAGet16(ds, tx);
    es = memoryAGet16(ds, tx + 2);
    sub_d016();
    si += ax;
    si += 0x0033;
    dx = 0x03c8;
    al = 0x00;
    out(dx, al);
    dx++;
    cx = 0x0008;
loc_d0ee: // 0ca6:068e
    al = memoryAGet(es, si);
    out(dx, al);
    al = memoryAGet(es, si + 1);
    out(dx, al);
    al = memoryAGet(es, si + 2);
    out(dx, al);
    si += 0x0003;
    if (--cx)
        goto loc_d0ee;
    dx--;
    al = 0x10;
    out(dx, al);
    dx++;
    cx = 0x0008;
loc_d109: // 0ca6:06a9
    al = memoryAGet(es, si);
    out(dx, al);
    al = memoryAGet(es, si + 1);
    out(dx, al);
    al = memoryAGet(es, si + 2);
    out(dx, al);
    si += 0x0003;
    if (--cx)
        goto loc_d109;
}
void sub_d121() // 0ca6:06c1
{
    CStackGuard sg(0, false);
    flags.interrupts = false;
    dx = 0x03d4;
    al = 0x0c;
    out(dx, al);
    dx++;
    in(al, dx);
    ah = 0x20;
    al ^= ah;
    out(dx, al);
    flags.interrupts = true;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, si + 2);
    tx = memoryAGet16(ds, bx + si + 2);
    memoryASet16(ds, bx + si + 2, ax);
    ax = tx;
    memoryASet16(ds, si + 2, ax);
}
void sub_d250() // 0ca6:07f0
{
    CStackGuard sg(0, true);
    push(0x7777);
    cx = 0x0002;
    sub_ce87();
    ax = memoryAGet16(ds, 0x542b);
    mul(memoryAGet16(ds, 0x5427));
    bp = ax;
    ax = memoryAGet16(ds, 0x5429);
    mul(memoryAGet16(ds, 0x5425));
    bx = ax;
    ax = memoryAGet16(es, di + 28);
    sub_cf8d();
    push(bx);
    push(ds);
    bx = ax;
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 21814);
    ds = pop();
    bx = pop();
    callIndirect(cs*16+ax);
    assert(pop() == 0x7777);
}
void sub_d283() // 0ca6:0823
{
    CStackGuard sg(0, true);
    push(0x7777);
    flags.direction = false;
    ax = 0;
loc_d286: // 0ca6:0826
    sub_d2b8();
    ah++;
    if ((char)ah > (char)0x03)
        goto loc_d2f1;
    si += bp;
    di += bx;
    push(ax);
    push(bx);
    push(dx);
    push(di);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0ca6);
    ds = dx;
    si = ax;
    es = pop();
    di = pop();
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0ca6);
    es = dx;
    di = ax;
    dx = pop();
    bx = pop();
    ax = pop();
    goto loc_d286;
    //   gap of 57 bytes
loc_d2f1: // 0ca6:0891
    assert(pop() == 0x7777);
}
void sub_d2b8() // 0ca6:0858
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(bx);
    push(bp);
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x542b);
    bp = memoryAGet16(ds, 0x5429);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_d2d5: // 0ca6:0875
    if (dl == 0x00)
        goto loc_d2ec;
    dl--;
    cx >>= 1;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += bp;
    goto loc_d2d5;
loc_d2ec: // 0ca6:088c
    di = pop();
    si = pop();
    bp = pop();
    bx = pop();
    assert(pop() == 0x7777);
}
void sub_d37f() // 0ca6:091f
{
    CStackGuard sg(0, true);
    push(0x7777);
    memoryASet(cs, 0x0973, 0x21);
    goto loc_d395;
    //   gap of 14 bytes
loc_d395: // 0ca6:0935
    ax = 0;
loc_d397: // 0ca6:0937
    sub_d3a7();
    ah++;
    if ((char)ah > (char)0x03)
        goto loc_d3ef;
    si += bp;
    di += bx;
    goto loc_d397;
    //   gap of 72 bytes
loc_d3ef: // 0ca6:098f
    assert(pop() == 0x7777);
}
void sub_d3a7() // 0ca6:0947
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(ax);
    push(bx);
    push(bp);
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x542b);
    bp = memoryAGet16(ds, 0x5429);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx == 0)
        goto loc_d3e9;
loc_d3c7: // 0ca6:0967
    if (dl == 0x00)
        goto loc_d3e9;
    dl--;
    cx >>= 1;
loc_d3d0: // 0ca6:0970
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, memoryAGet16(es, di) & ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_d3d0;
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += bp;
    goto loc_d3c7;
loc_d3e9: // 0ca6:0989
    di = pop();
    si = pop();
    bp = pop();
    bx = pop();
    ax = pop();
    assert(pop() == 0x7777);
}
void sub_d4d3() // 0ca6:0a73
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = false;
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    memoryASet(ds, 0x541f, 0x00);
    memoryASet(ds, 0x5420, 0x00);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bx + 21828));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d500() // 0ca6:0aa0
{
    CStackGuard sg(0, true);
    push(0x7777);
    si = 0x556a;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    ax = memoryAGet16(ds, 0x542b);
    mul(memoryAGet16(ds, 0x5427));
    bp = ax;
    bx = memoryAGet16(es, di + 28);
    push(bx);
    bx = di;
    sub_cf8d();
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 21840);
    ds = pop();
    callIndirect(cs*16+ax);
    assert(pop() == 0x7777);
}
void sub_d530() // 0ca6:0ad0
{
    CStackGuard sg(0, true);
    push(0x7777);
    flags.direction = false;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    al = 0x01;
loc_d539: // 0ca6:0ad9
    dx = 0x03c5;
    out(dx, al);
    goto loc_d560;
loc_d53f: // 0ca6:0adf
    al <<= 1;
    if ((char)al > (char)0x08)
        goto loc_d592;
    si += bp;
    push(ax);
    push(bx);
    push(di);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0ca6);
    ds = dx;
    si = ax;
    es = pop();
    di = pop();
    bx = pop();
    ax = pop();
    goto loc_d539;
loc_d560: // 0ca6:0b00
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x542b);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_d577: // 0ca6:0b17
    if (dl == ch)
        goto loc_d58e;
    dl--;
    cx >>= 1;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += 0x0028;
    goto loc_d577;
loc_d58e: // 0ca6:0b2e
    di = pop();
    si = pop();
    goto loc_d53f;
loc_d592: // 0ca6:0b32
    assert(pop() == 0x7777);
}
void sub_d593() // 0ca6:0b33
{
    CStackGuard sg(0, true);
    push(0x7777);
    memoryASet16(cs, 0x0b81, 0x9090);
    goto loc_d5a3;
    //   gap of 7 bytes
loc_d5a3: // 0ca6:0b43
    dx = 0x03c4;
    ax = 0x0002;
    out(dx, ax);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x542b);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx == 0)
        goto loc_d5c3;
    goto loc_d5c6;
loc_d5c3: // 0ca6:0b63
    goto loc_d65c;
loc_d5c6: // 0ca6:0b66
    if (dl != ch)
        goto loc_d5cd;
    goto loc_d65c;
loc_d5cd: // 0ca6:0b6d
    dl--;
    cx >>= 1;
    push(dx);
loc_d5d2: // 0ca6:0b72
    ax = memoryAGet16(ds, si);
    si += bp;
    ax |= memoryAGet16(ds, si);
    si += bp;
    ax |= memoryAGet16(ds, si);
    si += bp;
    ax |= memoryAGet16(ds, si);
    push(si);
    ch = ah;
    ah = al;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    dx = 0x03c5;
    al = 0x08;
    out(dx, al);
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    movsb<MemAuto, MemAuto, DirAuto>();
    ah = ch;
    si = pop();
    si++;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    al = memoryAGet(es, di);
    dx = 0x03c5;
    al = 0x08;
    out(dx, al);
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    ah = memoryAGet(ds, si);
    memoryASet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    movsb<MemAuto, MemAuto, DirAuto>();
    cl--;
    if (cl != 0)
        goto loc_d5d2;
    dx = pop();
    ch = 0;
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += 0x0028;
    goto loc_d5c6;
loc_d65c: // 0ca6:0bfc
    assert(pop() == 0x7777);
}
void sub_d65d() // 0ca6:0bfd
{
    CStackGuard sg(0, true);
    push(0x7777);
    memoryASet(cs, 0x0c63, 0x21);
    goto loc_d673;
    //   gap of 14 bytes
loc_d673: // 0ca6:0c13
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    al = 0x00;
    ah = 0x01;
loc_d683: // 0ca6:0c23
    dx = 0x03cf;
    out(dx, al);
    tl = ah;
    ah = al;
    al = tl;
    dx = 0x03c5;
    out(dx, al);
    tl = al;
    al = ah;
    ah = tl;
    sub_d69e();
    al++;
    ah <<= 1;
    if ((char)al > (char)0x03)
        goto loc_d6de;
    si += bp;
    goto loc_d683;
    //   gap of 64 bytes
loc_d6de: // 0ca6:0c7e
    assert(pop() == 0x7777);
}
void sub_d665() // 0ca6:0c05
{
    CStackGuard sg(0, true);
    push(0x7777);
    memoryASet(cs, 0x0c63, 0x09);
    goto loc_d673;
    //   gap of 6 bytes
loc_d673: // 0ca6:0c13
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    al = 0x00;
    ah = 0x01;
loc_d683: // 0ca6:0c23
    dx = 0x03cf;
    out(dx, al);
    tl = ah;
    ah = al;
    al = tl;
    dx = 0x03c5;
    out(dx, al);
    tl = al;
    al = ah;
    ah = tl;
    sub_d69e();
    al++;
    ah <<= 1;
    if ((char)al > (char)0x03)
        goto loc_d6de;
    si += bp;
    goto loc_d683;
    //   gap of 64 bytes
loc_d6de: // 0ca6:0c7e
    assert(pop() == 0x7777);
}
void sub_d69e() // 0ca6:0c3e
{
    CStackGuard sg(0, false);
    push(ax);
    push(si);
    push(di);
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx = memoryAGet16(ds, 0x542b);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx == 0)
        goto loc_d6da;
loc_d6b8: // 0ca6:0c58
    if (dl == ch)
        goto loc_d6da;
    dl--;
    cx >>= 1;
loc_d6c0: // 0ca6:0c60
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, memoryAGet16(es, di) & ax);
    si += 0x0002;
    di += 0x0002;
    if (--cx)
        goto loc_d6c0;
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += 0x0028;
    goto loc_d6b8;
loc_d6da: // 0ca6:0c7a
    di = pop();
    si = pop();
    ax = pop();
}
void sub_d7d7() // 0ca6:0d77
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    bp = memoryAGet16(es, di + 14);
    if ((short)bp > (short)0x0001)
        goto loc_d802;
    memoryASet(ds, 0x541f, 0x00);
    memoryASet(ds, 0x5420, 0x01);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bx + 21854));
loc_d802: // 0ca6:0da2
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d810() // 0ca6:0db0
{
    CStackGuard sg(0, true);
    push(0x7777);
    si = 0x56a4;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    ax = memoryAGet16(ds, 0x5429);
    mul(memoryAGet16(ds, 0x5425));
    bp = ax;
    bx = memoryAGet16(es, di + 28);
    push(bx);
    bx = di;
    sub_cf8d();
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 22154);
    ds = pop();
    callIndirect(cs*16+ax);
    assert(pop() == 0x7777);
}
void sub_d840() // 0ca6:0de0
{
    CStackGuard sg(0, true);
    push(0x7777);
    flags.direction = false;
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    al = 0x00;
loc_d849: // 0ca6:0de9
    dx = 0x03cf;
    out(dx, al);
    sub_d869();
    al++;
    if ((char)al > (char)0x03)
        goto loc_d89b;
    di += bp;
    push(ax);
    push(bx);
    push(dx);
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0ca6);
    es = dx;
    di = ax;
    dx = pop();
    bx = pop();
    ax = pop();
    goto loc_d849;
    //   gap of 50 bytes
loc_d89b: // 0ca6:0e3b
    assert(pop() == 0x7777);
}
void sub_d869() // 0ca6:0e09
{
    CStackGuard sg(0, false);
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x5429);
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_d880: // 0ca6:0e20
    if (dl == 0x00)
        goto loc_d898;
    dl--;
    cx >>= 1;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += 0x0028;
    di += bx;
    goto loc_d880;
loc_d898: // 0ca6:0e38
    di = pop();
    si = pop();
}
void sub_da88() // 0ca6:1028
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    bp = memoryAGet16(es, di);
    if ((short)bp > (short)0x0001)
        goto loc_dab2;
    memoryASet(ds, 0x541f, 0x01);
    memoryASet(ds, 0x5420, 0x00);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bx + 22168));
loc_dab2: // 0ca6:1052
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_dac0() // 0ca6:1060
{
    CStackGuard sg(0, false);
    si = 0x56ce;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    bx = memoryAGet16(es, di + 28);
    push(bx);
    bx = di;
    sub_cf8d();
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 22196);
    ds = pop();
    callIndirect(cs*16+ax);
}
void sub_dae7() // 0ca6:1087
{
    CStackGuard sg(0, false);
    flags.direction = false;
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    push(ds);
    ax = 0x1228;
    ds = ax;
    dx = memoryAGet16(ds, 0x5433);
    cx = memoryAGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_db00: // 0ca6:10a0
    if (dl == 0x00)
        return;
    dl--;
    rep_movsb<MemAuto, MemAuto, DirAuto>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += 0x0028;
    di += 0x0028;
    goto loc_db00;
}
void sub_dcce() // 0ca6:126e
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    es = dx;
    di = ax;
    bx = memoryAGet16(es, di);
    if ((short)bx > (short)0x0001)
        goto loc_dd01;
    bp = memoryAGet16(es, di + 14);
    if ((short)bp > (short)0x0001)
        goto loc_dd01;
    memoryASet(ds, 0x541f, 0x01);
    memoryASet(ds, 0x5420, 0x01);
    si = memoryAGet16(ds, 0x541d);
    si <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, si + 22210));
loc_dd01: // 0ca6:12a1
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_dd71() // 0ca6:1311
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bx + 26950));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_dd8b() // 0ca6:132b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet16(ds, 0x68a4, dx);
    memoryASet16(ds, 0x68a2, ax);
    di = 0x68a2;
    bx = memoryAGet16(ds, di + 2);
    es = bx;
    di = memoryAGet16(ds, di);
    al = memoryAGet(es, di + 3);
    al += 0x02;
    memoryASet(ds, 0x693e, al);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_dddb() // 0ca6:137b
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    ax = 0x000a;
    dx = 0x000a;
    push(cs);
    sub_dea1();
    ax = 0x0000;
    bx = 0x0000;
    cx = 0x013f;
    dx = 0x00c7;
    push(cs);
    sub_de82();
    bx = 0x0000;
    push(cs);
    sub_de69();
    al = 0x08;
    push(cs);
    sub_deb8();
    ax = 0x000f;
    dx = 0x0000;
    push(cs);
    sub_dd71();
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_de1c() // 0ca6:13bc
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = false;
    bx = 0x1228;
    ds = bx;
    di = 0x68a2;
    bx = memoryAGet16(ds, di + 2);
    es = bx;
    di = memoryAGet16(ds, di);
    if (al < memoryAGet(es, di))
        goto loc_de46;
    if (al >= memoryAGet(es, di + 1))
        goto loc_de46;
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bx + 26962));
loc_de46: // 0ca6:13e6
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_de4c() // 0ca6:13ec
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = false;
    ds = dx;
    si = ax;
loc_de56: // 0ca6:13f6
    al = memoryAGet(ds, si);
    if (al == 0x00)
        goto loc_de63;
    push(cs);
    sub_de1c();
    si++;
    goto loc_de56;
loc_de63: // 0ca6:1403
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_de69() // 0ca6:1409
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    if ((short)bx > (short)0x0001)
        goto loc_de7c;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x6940, bx);
loc_de7c: // 0ca6:141c
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_de82() // 0ca6:1422
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    memoryASet16(ds, 0x6936, ax);
    memoryASet16(ds, 0x6938, bx);
    memoryASet16(ds, 0x693a, cx);
    memoryASet16(ds, 0x693c, dx);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_dea1() // 0ca6:1441
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet16(ds, 0x6944, dx);
    memoryASet16(ds, 0x6942, ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_deb8() // 0ca6:1458
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet(ds, 0x693e, al);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_deee() // 0ca6:148e
{
    CStackGuard sg(0, true);
    push(0x7777);
    si = 0x695e;
    memoryASet16(ds, si, 0x68b6);
    memoryASet16(ds, si + 2, ds);
    bp = memoryAGet16(ds, 0x6940);
    bp <<= 1;
    bp <<= 1;
    ax += memoryAGet16(ds, bp + 21525);
    memoryASet16(ds, si + 8, ax);
    ax = memoryAGet16(ds, bp + 21527);
    memoryASet16(ds, si + 10, ax);
    ax = 0;
    al = bl;
    memoryASet16(ds, si + 12, ax);
    al = bh;
    memoryASet16(ds, si + 14, ax);
    al = cl;
    memoryASet16(ds, si + 16, ax);
    al = ch;
    memoryASet16(ds, si + 18, ax);
    memoryASet(ds, si + 22, dl);
    dx = ds;
    ax = si;
    push(cs);
    cs = 0x0ed9;
    sub_11aa5();
    assert(cs == 0x0ca6);
    assert(pop() == 0x7777);
}
void sub_df33() // 0ca6:14d3
{
    CStackGuard sg(0, false);
    al -= memoryAGet(es, di);
    ah = 0;
    ax <<= 1;
    bx = es;
    ds = bx;
    si = di;
    si += 0x0006;
    si += ax;
    ax = memoryAGet16(ds, si);
    tl = al;
    al = ah;
    ah = tl;
    ax += di;
    si = ax;
}
void sub_df4f() // 0ca6:14ef
{
    CStackGuard sg(0, false);
    si = 0x68a6;
    sub_df5f();
    si = 0x68ae;
    ax = dx;
    sub_df5f();
    return;
    //   gap of 46 bytes
}
void sub_df5f() // 0ca6:14ff
{
    CStackGuard sg(0, false);
    memoryASet16(ds, si, 0x0000);
    memoryASet16(ds, si + 2, 0x0000);
    if (!(ax & 0x0001))
        goto loc_df70;
    memoryASet(ds, si, 0xff);
loc_df70: // 0ca6:1510
    if (!(ax & 0x0002))
        goto loc_df79;
    memoryASet(ds, si + 1, 0xff);
loc_df79: // 0ca6:1519
    if (!(ax & 0x0004))
        goto loc_df84;
    memoryASet(ds, si + 2, 0xff);
    if (!(ax & 0x0004))
        goto loc_df84;
loc_df84: // 0ca6:1524
    if (!(ax & 0x0008))
        return;
    memoryASet(ds, si + 3, 0xff);
}
void sub_df90() // 0ca6:1530
{
    CStackGuard sg(0, false);
    push(ax);
    push(dx);
    if ((short)ax < (short)memoryAGet16(ds, 0x6936))
        goto loc_dfbb;
    flags.carry = (al + bh) >= 0x100;
    al += bh;
    if (!flags.carry)
        goto loc_df9e;
    ah++;
loc_df9e: // 0ca6:153e
    ax--;
    if ((short)ax > (short)memoryAGet16(ds, 0x693a))
        goto loc_dfbb;
    if ((short)dx < (short)memoryAGet16(ds, 0x6938))
        goto loc_dfbb;
    flags.carry = (dl + bl) >= 0x100;
    dl += bl;
    if (!flags.carry)
        goto loc_dfb1;
    dh++;
loc_dfb1: // 0ca6:1551
    dx--;
    if ((short)dx > (short)memoryAGet16(ds, 0x693c))
        goto loc_dfbb;
    flags.carry = false;
    goto loc_dfbc;
loc_dfbb: // 0ca6:155b
    flags.carry = true;
loc_dfbc: // 0ca6:155c
    dx = pop();
    ax = pop();
}
void sub_dfbf() // 0ca6:155f
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(bp);
    push(di);
    push(si);
    push(ds);
    push(es);
    si = 0x68ae;
    di = 0x68b6;
    cx = 0x0080;
    cx >>= 1;
    cx >>= 1;
loc_dfd5: // 0ca6:1575
    ax = memoryAGet16(ds, si);
    memoryASet16(ds, di, ax);
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(ds, di + 2, ax);
    di += 0x0004;
    if (--cx)
        goto loc_dfd5;
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    assert(pop() == 0x7777);
}
void sub_dfee() // 0ca6:158e
{
    CStackGuard sg(0, true);
    push(0x7777);
    sub_dfbf();
    sub_df33();
    al = memoryAGet(es, di + 2);
    bl = memoryAGet(es, di + 3);
    bh = memoryAGet(ds, si);
    cl = bh;
    bh += memoryAGet(es, di + 4);
    dl = memoryAGet(ds, si + 1);
    dh = memoryAGet(ds, si + 2);
    si += 0x0003;
    push(ds);
    bp = 0x1228;
    ds = bp;
    es = bp;
    bp = 0x68a6;
    di = 0x68b6;
    ds = pop();
    assert(pop() == 0x7777);
}
void sub_e01d() // 0ca6:15bd
{
    CStackGuard sg(0, true);
    push(0x7777);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(bp);
    push(di);
    push(si);
    push(ds);
    push(es);
    ch = 0;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx <<= 1;
    cx <<= 1;
    di += cx;
    cl = bh;
    cl &= 0x07;
    al = 0;
    if (cx == 0)
        goto loc_e05c;
loc_e03d: // 0ca6:15dd
    flags.carry = true;
    al = rcr(al, 0x01);
    if (--cx)
        goto loc_e03d;
    cx = 0x0004;
loc_e045: // 0ca6:15e5
    if (bl == 0x00)
        goto loc_e05c;
    bl--;
loc_e04c: // 0ca6:15ec
    memoryASet(es, di, memoryAGet(es, di) & al);
    di++;
    if (--cx)
        goto loc_e04c;
    cx = 0x0004;
    di -= cx;
    di += 0x0008;
    goto loc_e045;
loc_e05c: // 0ca6:15fc
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    assert(pop() == 0x7777);
}
void sub_e067() // 0ca6:1607
{
    CStackGuard sg(0, true);
    push(0x7777);
    sub_dfee();
    if (cl != 0x00)
        goto loc_e072;
    goto loc_e13d;
loc_e072: // 0ca6:1612
    push(ax);
    sub_e01d();
    al = 0x08;
    mul(dh);
    ah = 0;
    di += ax;
    ch = 0;
    cl--;
    cx >>= 1;
    cx >>= 1;
    cx >>= 1;
    cx++;
    dh = cl;
    push(bx);
loc_e08c: // 0ca6:162c
    if (dl == 0x00)
        goto loc_e0ea;
    dl--;
    push(di);
    push(dx);
loc_e095: // 0ca6:1635
    al = memoryAGet(ds, si);
    bl = al;
    bh = al;
    ax = memoryAGet16(es, bp);
    ax &= bx;
    dx = ax;
    ax = memoryAGet16(es, bp + 2);
    ax &= bx;
    dx |= ax;
    dh |= dl;
    dl = dh;
    dx = ~dx;
    if (dx == 0xffff)
        goto loc_e0d2;
    ax = memoryAGet16(es, bp);
    ax &= bx;
    memoryASet16(es, di, memoryAGet16(es, di) & dx);
    memoryASet16(es, di, memoryAGet16(es, di) | ax);
    ax = memoryAGet16(es, bp + 2);
    ax &= bx;
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) & dx);
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) | ax);
    goto loc_e0db;
loc_e0d2: // 0ca6:1672
    bx = ~bx;
    memoryASet16(es, di, memoryAGet16(es, di) & bx);
    memoryASet16(es, di + 2, memoryAGet16(es, di + 2) & bx);
loc_e0db: // 0ca6:167b
    si++;
    di += 0x0004;
    if (--cx)
        goto loc_e095;
    dx = pop();
    cl = dh;
    di = pop();
    di += 0x0008;
    goto loc_e08c;
loc_e0ea: // 0ca6:168a
    bx = pop();
    ax = 0x1228;
    ds = ax;
    dx = pop();
    dh = 0;
    dx = -dx;
    dx += memoryAGet16(ds, 0x6944);
    ax = memoryAGet16(ds, 0x6942);
    flags.carry = (memoryAGet(ds, 0x6942) + bh) >= 0x100;
    memoryASet(ds, 0x6942, memoryAGet(ds, 0x6942) + bh);
    if (!flags.carry)
        goto loc_e108;
    memoryASet16(ds, 0x6942, memoryAGet16(ds, 0x6942) + 0x0100);
loc_e108: // 0ca6:16a8
    sub_df90();
    if (flags.carry)
        goto loc_e13d;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    cx = dx;
    cx <<= 1;
    cx <<= 1;
    cx += dx;
    dx = ax;
    dx &= 0x0007;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax += cx;
    bh--;
    bh >>= 1;
    bh >>= 1;
    bh >>= 1;
    bh++;
    cl = bh;
    ch = bl;
    bl = 0x02;
    bh = 0x28;
    sub_deee();
loc_e13d: // 0ca6:16dd
    sub_d0bf();
    assert(pop() == 0x7777);
}
void sub_e150() // 0e15:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    memoryASet16(ds, 0x4e10, di);
    memoryASet16(ds, 0x4e0c, di);
    memoryASet16(ds, 0x4e0e, si);
    memoryASet16(ds, 0x4e0a, si);
    es = di;
    di = si;
    memoryASet16(ds, 0x4e14, bx);
    memoryASet16(ds, 0x4e2a, bx);
    memoryASet16(ds, 0x4e12, ax);
    memoryASet16(ds, 0x4e28, ax);
    bx = dx;
    ax = cx;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e0c, dx);
    memoryASet16(ds, 0x4e0a, ax);
loc_e18c: // 0e15:003c
    sub_eb59();
    if (!flags.carry)
        goto loc_e196;
    ax = 0x0003;
    goto loc_e1c8;
loc_e196: // 0e15:0046
    push(si);
    push(ds);
    bp = 0x1228;
    ds = bp;
    si = memoryAGet16(ds, 0x4e31);
    si &= 0x7fff;
    si--;
    si <<= 1;
    bp = memoryAGet16(ds, si + 20023);
    ds = pop();
    si = pop();
    callIndirect(cs*16+bp);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e35);
    memoryASet16(ds, 0x4e2a, ax);
    ax = memoryAGet16(ds, 0x4e33);
    memoryASet16(ds, 0x4e28, ax);
    if ((short)memoryAGet16(ds, 0x4e31) > (short)0x0000)
        goto loc_e18c;
loc_e1c8: // 0e15:0078
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_e1ce() // 0e15:007e
{
    CStackGuard sg(0, false);
    dx = memoryAGet16(ds, 0x4e26);
    memoryASet16(ds, 0x4e14, dx);
    ax = memoryAGet16(ds, 0x4e24);
    memoryASet16(ds, 0x4e12, ax);
    memoryASet(ds, 0x4e12, memoryAGet(ds, 0x4e12) & 0xf0);
    if (dx != memoryAGet16(ds, 0x4e14))
        goto loc_e1ed;
    if (ax == memoryAGet16(ds, 0x4e12))
        goto loc_e1f8;
loc_e1ed: // 0e15:009d
    flags.carry = (memoryAGet16(ds, 0x4e12) + 0x0010) >= 0x10000;
    memoryASet16(ds, 0x4e12, memoryAGet16(ds, 0x4e12) + 0x0010);
    if (!flags.carry)
        goto loc_e1f8;
    memoryASet16(ds, 0x4e14, memoryAGet16(ds, 0x4e14) + 1);
loc_e1f8: // 0e15:00a8
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4e18, ax);
    ax = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4e16, ax);
    ax = memoryAGet16(ds, 0x4e18);
    es = ax;
    di = memoryAGet16(ds, 0x4e16);
    bx = memoryAGet16(ds, 0x4e14);
    ax = memoryAGet16(ds, 0x4e12);
    push(cs);
    cs = 0x0ec7;
    sub_ecb5();
    assert(cs == 0x0e15);
    al &= 0xfe;
    memoryASet16(ds, 0x4e08, dx);
    memoryASet16(ds, 0x4e06, ax);
    es = dx;
    di = ax;
    bx = memoryAGet16(ds, 0x4e14);
    ax = memoryAGet16(ds, 0x4e12);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4dfc, dx);
    memoryASet16(ds, 0x4dfa, ax);
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = memoryAGet16(ds, 0x4e14);
    ax = memoryAGet16(ds, 0x4e12);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4df8, dx);
    memoryASet16(ds, 0x4df6, ax);
    es = dx;
    di = ax;
    bx = 0;
    ax = 0x0010;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    if (dx < memoryAGet16(ds, 0x4dfc))
        goto loc_e285;
    if (dx != memoryAGet16(ds, 0x4dfc))
        goto loc_e278;
    if (ax <= memoryAGet16(ds, 0x4dfa))
        goto loc_e285;
loc_e278: // 0e15:0128
    memoryASet16(ds, 0x4e14, 0x0000);
    memoryASet16(ds, 0x4e12, 0x0002);
    return;
loc_e285: // 0e15:0135
    cx = memoryAGet16(ds, 0x4e14);
    bx = memoryAGet16(ds, 0x4e12);
    ax = memoryAGet16(ds, 0x4dfc);
    es = ax;
    di = memoryAGet16(ds, 0x4dfa);
    si = memoryAGet16(ds, 0x4df6);
    ax = memoryAGet16(ds, 0x4df8);
    ds = ax;
loc_e29f: // 0e15:014f
    flags.carry = si < 0x0002;
    si -= 0x0002;
    if (!flags.carry)
        goto loc_e2ac;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e2ac: // 0e15:015c
    flags.carry = di < 0x0002;
    di -= 0x0002;
    if (!flags.carry)
        goto loc_e2b9;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e2b9: // 0e15:0169
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    flags.carry = bx < 0x0002;
    bx -= 0x0002;
    if (!flags.carry)
        goto loc_e2c7;
    bx += 0x0010;
    cx--;
loc_e2c7: // 0e15:0177
    if (cx != 0x0000)
        goto loc_e29f;
    if (bx != 0x0000)
        goto loc_e29f;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x4e14, 0x0000);
    memoryASet16(ds, 0x4e12, 0x0001);
}
void sub_e2e4() // 0e15:0194
{
    CStackGuard sg(0, true);
    push(0x7777);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = 0;
    ax = 0x000c;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e08, dx);
    memoryASet16(ds, 0x4e06, ax);
    es = dx;
    di = ax;
    al = memoryAGet(es, di);
    memoryASet(ds, 0x4e22, al);
    memoryASet16(ds, 0x4e06, memoryAGet16(ds, 0x4e06) + 1);
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4df8, dx);
    memoryASet16(ds, 0x4df6, ax);
    bx = memoryAGet16(ds, 0x4e2a);
    ax = memoryAGet16(ds, 0x4e28);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4dfc, dx);
    memoryASet16(ds, 0x4dfa, ax);
    ax = 0x1228;
    es = ax;
    di = 0x4e97;
    bx = 0;
    ax = 0x0400;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e04, dx);
    memoryASet16(ds, 0x4e02, ax);
    es = dx;
    di = ax;
    memoryASet16(ds, 0x4e2f, dx);
    memoryASet16(ds, 0x4e2d, ax);
    si = memoryAGet16(ds, 0x4dfa);
    ax = memoryAGet16(ds, 0x4dfc);
    ds = ax;
    cx = 0x0400;
loc_e370: // 0e15:0220
    flags.carry = si < 0x0001;
    si -= 0x0001;
    if (!flags.carry)
        goto loc_e37d;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e37d: // 0e15:022d
    flags.carry = di < 0x0001;
    di -= 0x0001;
    if (!flags.carry)
        goto loc_e38a;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e38a: // 0e15:023a
    al = memoryAGet(ds, si);
    memoryASet(es, di, al);
    ax = ds;
    bp = cx;
    bx = 0x1228;
    ds = bx;
    dx = memoryAGet16(ds, 0x4e08);
    cx = memoryAGet16(ds, 0x4e06);
    ds = ax;
    if (ax != dx)
        goto loc_e3aa;
    if (si == cx)
        goto loc_e3ff;
loc_e3aa: // 0e15:025a
    cx = bp;
    if (--cx)
        goto loc_e370;
    bp = ds;
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4df8);
    memoryASet16(ds, 0x4e04, ax);
    di = memoryAGet16(ds, 0x4df6);
    memoryASet16(ds, 0x4e02, di);
    es = ax;
    ds = bp;
loc_e3c7: // 0e15:0277
    flags.carry = si < 0x0001;
    si -= 0x0001;
    if (!flags.carry)
        goto loc_e3d4;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e3d4: // 0e15:0284
    flags.carry = di < 0x0001;
    di -= 0x0001;
    if (!flags.carry)
        goto loc_e3e1;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e3e1: // 0e15:0291
    al = memoryAGet(ds, si);
    memoryASet(es, di, al);
    ax = ds;
    bx = 0x1228;
    ds = bx;
    dx = memoryAGet16(ds, 0x4e08);
    cx = memoryAGet16(ds, 0x4e06);
    ds = ax;
    if (ax != dx)
        goto loc_e3c7;
    if (si != cx)
        goto loc_e3c7;
loc_e3ff: // 0e15:02af
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e10);
    memoryASet16(ds, 0x4e00, ax);
    ax = memoryAGet16(ds, 0x4e0e);
    memoryASet16(ds, 0x4dfe, ax);
    ax = es;
    ds = ax;
    si = di;
loc_e416: // 0e15:02c6
    al = memoryAGet(ds, si);
    bp = ds;
    bx = 0x1228;
    ds = bx;
    memoryASet(ds, 0x4e2c, al);
    ds = bp;
    bp = bx;
    si += 0x0001;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bx = ds;
    ds = bp;
    dx = memoryAGet16(ds, 0x4df8);
    cx = memoryAGet16(ds, 0x4df6);
    ds = bx;
    if (bx != dx)
        goto loc_e465;
    if (si != cx)
        goto loc_e465;
    ds = bp;
    ax = 0x1228;
    memoryASet16(ds, 0x4e04, ax);
    si = 0x4e97;
    memoryASet16(ds, 0x4e02, si);
    ds = ax;
loc_e465: // 0e15:0315
    bp = ds;
    bx = 0x1228;
    ds = bx;
    al = memoryAGet(ds, 0x4e22);
    ah = memoryAGet(ds, 0x4e2c);
    ds = bp;
    if (al == ah)
        goto loc_e47c;
    goto loc_e565;
loc_e47c: // 0e15:032c
    al = memoryAGet(ds, si);
    ds = bx;
    memoryASet(ds, 0x4e1e, al);
    ds = bp;
    bp = bx;
    si += 0x0001;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bx = ds;
    ds = bp;
    dx = memoryAGet16(ds, 0x4df8);
    cx = memoryAGet16(ds, 0x4df6);
    ds = bx;
    if (bx != dx)
        goto loc_e4c6;
    if (si != cx)
        goto loc_e4c6;
    ds = bp;
    ax = 0x1228;
    memoryASet16(ds, 0x4e04, ax);
    si = 0x4e97;
    memoryASet16(ds, 0x4e02, si);
    ds = ax;
loc_e4c6: // 0e15:0376
    bp = ds;
    bx = 0x1228;
    ds = bx;
    al = memoryAGet(ds, 0x4e22);
    ah = memoryAGet(ds, 0x4e1e);
    ds = bp;
    if (al != ah)
        goto loc_e4dd;
    goto loc_e565;
loc_e4dd: // 0e15:038d
    al = memoryAGet(ds, si);
    ds = bx;
    memoryASet(ds, 0x4e16, al);
    ds = bp;
    bp = bx;
    si += 0x0001;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bx = ds;
    ds = bp;
    dx = memoryAGet16(ds, 0x4df8);
    cx = memoryAGet16(ds, 0x4df6);
    ds = bx;
    if (bx != dx)
        goto loc_e527;
    if (si != cx)
        goto loc_e527;
    ds = bp;
    ax = 0x1228;
    memoryASet16(ds, 0x4e04, ax);
    si = 0x4e97;
    memoryASet16(ds, 0x4e02, si);
    ds = ax;
loc_e527: // 0e15:03d7
    bp = ds;
    bx = 0x1228;
    ds = bx;
    ax = memoryAGet16(ds, 0x4e00);
    es = ax;
    di = memoryAGet16(ds, 0x4dfe);
    al = memoryAGet(ds, 0x4e1e);
    memoryASet(es, di, al);
    di += 0x0001;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    if (bp != dx)
        goto loc_e55b;
    if (si != di)
        goto loc_e55b;
    goto loc_e5fe;
loc_e55b: // 0e15:040b
    memoryASet(ds, 0x4e16, memoryAGet(ds, 0x4e16) - 1);
    flags.zero = memoryAGet(ds, 0x4e16) == 0;
    ds = bp;
    if (!flags.zero)
        goto loc_e527;
    goto loc_e590;
loc_e565: // 0e15:0415
    bp = ds;
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e00);
    es = ax;
    di = memoryAGet16(ds, 0x4dfe);
    al = memoryAGet(ds, 0x4e2c);
    memoryASet(es, di, al);
    di += 0x0001;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    ds = bp;
loc_e590: // 0e15:0440
    bp = ds;
    dx = es;
    if (bp != dx)
        goto loc_e59c;
    if (si == di)
        goto loc_e5fe;
loc_e59c: // 0e15:044c
    bx = 0x1228;
    ds = bx;
    dx = memoryAGet16(ds, 0x4e2f);
    cx = memoryAGet16(ds, 0x4e2d);
    ds = bp;
    if (bp == dx)
        goto loc_e5b2;
    goto loc_e416;
loc_e5b2: // 0e15:0462
    if (si == cx)
        goto loc_e5b9;
    goto loc_e416;
loc_e5b9: // 0e15:0469
    ax = 0x1228;
    ds = ax;
    push(di);
    push(es);
    ax = memoryAGet16(ds, 0x4e26);
    es = ax;
    di = memoryAGet16(ds, 0x4e24);
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e26, dx);
    memoryASet16(ds, 0x4e24, ax);
    es = pop();
    di = pop();
    ax = memoryAGet16(ds, 0x4e0e);
    flags.carry = di < ax;
    di -= ax;
    if (!flags.carry)
        goto loc_e5e6;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e5e6: // 0e15:0496
    bx = memoryAGet16(ds, 0x4e10);
    ax = es;
    ax -= bx;
    if (ax != memoryAGet16(ds, 0x4e26))
        goto loc_e5ff;
    if (di != memoryAGet16(ds, 0x4e24))
        goto loc_e5ff;
    ax = 0x0001;
    assert(pop() == 0x7777);
    return;
loc_e5fe: // 0e15:04ae
    assert(pop() == 0x7777);
    return;
loc_e5ff: // 0e15:04af
    assert(pop() == 0x7777);
}
void sub_e600() // 0e15:04b0
{
    CStackGuard sg(0, true);
    push(0x7777);
    goto loc_e600;
loc_e5fe: // 0e15:04ae
    assert(pop() == 0x7777);
    return;
    //   gap of 1 bytes
loc_e600: // 0e15:04b0
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    if (dx > memoryAGet16(ds, 0x4e0c))
        goto loc_e5fe;
    if (dx != memoryAGet16(ds, 0x4e0c))
        goto loc_e628;
    if (ax > memoryAGet16(ds, 0x4e0a))
        goto loc_e5fe;
loc_e628: // 0e15:04d8
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    di = memoryAGet16(ds, 0x4e0e);
    bx = 0;
    ax = 0x000c;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4df8, dx);
    memoryASet16(ds, 0x4df6, ax);
    es = dx;
    di = ax;
    ax = memoryAGet16(es, di);
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(ds, 0x4e22, ax);
    memoryASet16(ds, 0x4df6, memoryAGet16(ds, 0x4df6) + 0x0002);
    dx = memoryAGet16(ds, 0x4e26);
    memoryASet16(ds, 0x4e20, dx);
    ax = memoryAGet16(ds, 0x4e24);
    memoryASet16(ds, 0x4e1e, ax);
    memoryASet(ds, 0x4e1e, memoryAGet(ds, 0x4e1e) & 0xe0);
    if (dx != memoryAGet16(ds, 0x4e20))
        goto loc_e679;
    if (ax == memoryAGet16(ds, 0x4e1e))
        goto loc_e67f;
    dx = memoryAGet16(ds, 0x4e20);
    ax = memoryAGet16(ds, 0x4e1e);
loc_e679: // 0e15:0529
    flags.carry = (ax + 0x0020) >= 0x10000;
    ax += 0x0020;
    if (!flags.carry)
        goto loc_e67f;
    dx++;
loc_e67f: // 0e15:052f
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    memoryASet16(ds, 0x4e20, dx);
    memoryASet16(ds, 0x4e1e, ax);
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4e18, ax);
    di = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4e16, di);
    es = ax;
    bx = memoryAGet16(ds, 0x4e20);
    ax = memoryAGet16(ds, 0x4e1e);
    push(cs);
    cs = 0x0ec7;
    sub_ecb5();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e18, dx);
    memoryASet16(ds, 0x4e16, ax);
    memoryASet(ds, 0x4e16, memoryAGet(ds, 0x4e16) & 0xfe);
    dx = memoryAGet16(ds, 0x4e18);
    memoryASet16(ds, 0x4dfc, dx);
    ax = memoryAGet16(ds, 0x4e16);
    memoryASet16(ds, 0x4dfa, ax);
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    es = dx;
    di = ax;
    ax = memoryAGet16(ds, 0x4e20);
    memoryASet16(ds, 0x4e18, ax);
    ax = memoryAGet16(ds, 0x4e1e);
    memoryASet16(ds, 0x4e16, ax);
    si = memoryAGet16(ds, 0x4df6);
    ax = memoryAGet16(ds, 0x4df8);
    ds = ax;
loc_e6e8: // 0e15:0598
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(es, di + 2, ax);
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    si += 0x0004;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bp = ds;
    di += 0x0004;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    ax = 0x1228;
    ds = ax;
    push(di);
    push(es);
    ax = memoryAGet16(ds, 0x4e18);
    es = ax;
    di = memoryAGet16(ds, 0x4e16);
    bx = 0;
    ax = 0x0004;
    push(cs);
    cs = 0x0ec7;
    sub_ecb5();
    assert(cs == 0x0e15);
    es = pop();
    di = pop();
    memoryASet16(ds, 0x4e18, dx);
    memoryASet16(ds, 0x4e16, ax);
    ds = bp;
    if (dx != 0x0000)
        goto loc_e6e8;
    if (ax != 0x0000)
        goto loc_e6e8;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x4df8, bp);
    memoryASet16(ds, 0x4df6, si);
    ax = es;
    memoryASet16(ds, 0x4e00, ax);
    memoryASet16(ds, 0x4dfe, di);
    ax = memoryAGet16(ds, 0x4e26);
    push(ax);
    ax = memoryAGet16(ds, 0x4e24);
    push(ax);
    ax = memoryAGet16(ds, 0x4dfc);
    push(ax);
    ax = memoryAGet16(ds, 0x4dfa);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0c);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0a);
    push(ax);
    ax = memoryAGet16(ds, 0x4dfc);
    memoryASet16(ds, 0x4e0c, ax);
    ax = memoryAGet16(ds, 0x4dfa);
    memoryASet16(ds, 0x4e0a, ax);
    ax = memoryAGet16(ds, 0x4e2a);
    memoryASet16(ds, 0x4e26, ax);
    ax = memoryAGet16(ds, 0x4e28);
    memoryASet16(ds, 0x4e24, ax);
    sub_e1ce();
    ax = pop();
    memoryASet16(ds, 0x4e0a, ax);
    ax = pop();
    memoryASet16(ds, 0x4e0c, ax);
    ax = pop();
    memoryASet16(ds, 0x4dfa, ax);
    ax = pop();
    memoryASet16(ds, 0x4dfc, ax);
    ax = pop();
    memoryASet16(ds, 0x4e24, ax);
    ax = pop();
    memoryASet16(ds, 0x4e26, ax);
    if (memoryAGet16(ds, 0x4e14) != 0x0000)
        goto loc_e7bb;
    if (memoryAGet16(ds, 0x4e12) != 0x0002)
        goto loc_e7bb;
    goto loc_e5fe;
loc_e7bb: // 0e15:066b
    ax = memoryAGet16(ds, 0x4e26);
    push(ax);
    ax = memoryAGet16(ds, 0x4e24);
    push(ax);
    ax = memoryAGet16(ds, 0x4e2a);
    push(ax);
    ax = memoryAGet16(ds, 0x4e28);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0c);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0a);
    push(ax);
    ax = memoryAGet16(ds, 0x4e08);
    es = ax;
    di = memoryAGet16(ds, 0x4e06);
    bx = memoryAGet16(ds, 0x4e2a);
    ax = memoryAGet16(ds, 0x4e28);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e04, dx);
    memoryASet16(ds, 0x4e02, ax);
    bx = memoryAGet16(ds, 0x4e20);
    ax = memoryAGet16(ds, 0x4e1e);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    bx = 0;
    ax = 0x000e;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e08, dx);
    memoryASet16(ds, 0x4e06, ax);
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4e00, ax);
    di = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4dfe, di);
    es = ax;
    bx = 0;
    ax = 0x0400;
    push(cs);
    cs = 0x0ec7;
    sub_ecb5();
    assert(cs == 0x0e15);
    memoryASet16(ds, 0x4e00, dx);
    memoryASet16(ds, 0x4dfe, ax);
    ax = memoryAGet16(ds, 0x4dfc);
    memoryASet16(ds, 0x4e0c, ax);
    ax = memoryAGet16(ds, 0x4dfa);
    memoryASet16(ds, 0x4e0a, ax);
    ax = memoryAGet16(ds, 0x4e10);
    memoryASet16(ds, 0x4df8, ax);
    ax = memoryAGet16(ds, 0x4e0e);
    memoryASet16(ds, 0x4df6, ax);
    memoryASet16(ds, 0x4e1c, 0x0000);
    memoryASet16(ds, 0x4e1a, 0x0000);
    memoryASet16(ds, 0x4e14, 0x0000);
    memoryASet16(ds, 0x4e12, 0x0000);
    memoryASet16(ds, 0x4e18, 0x0000);
    memoryASet16(ds, 0x4e16, 0x0000);
loc_e86d: // 0e15:071d
    memoryASet16(ds, 0x4e16, memoryAGet16(ds, 0x4e16) - 0x0001);
    if ((short)memoryAGet16(ds, 0x4e16) >= 0)
        goto loc_e8c2;
    bp = ds;
    si = memoryAGet16(ds, 0x4e0a);
    ax = memoryAGet16(ds, 0x4e0c);
    ds = ax;
    dx = memoryAGet16(ds, si + 2);
    tl = dl;
    dl = dh;
    dh = tl;
    ax = memoryAGet16(ds, si);
    tl = al;
    al = ah;
    ah = tl;
    push(ax);
    push(dx);
    si += 0x0004;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    dx = pop();
    ax = pop();
    cx = ds;
    ds = bp;
    memoryASet16(ds, 0x4e0c, cx);
    memoryASet16(ds, 0x4e0a, si);
    memoryASet16(ds, 0x4e16, 0x001f);
    memoryASet16(ds, 0x4e26, ax);
    memoryASet16(ds, 0x4e24, dx);
loc_e8c2: // 0e15:0772
    dx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl(dx, 0x0001);
    memoryASet16(ds, 0x4e26, dx);
    memoryASet16(ds, 0x4e24, ax);
    if (!flags.carry)
        goto loc_e8d9;
    goto loc_ea27;
loc_e8d9: // 0e15:0789
    ax = memoryAGet16(ds, 0x4df8);
    es = ax;
    di = memoryAGet16(ds, 0x4df6);
    si = memoryAGet16(ds, 0x4e06);
    ax = memoryAGet16(ds, 0x4e08);
    ds = ax;
    al = memoryAGet(ds, si);
    memoryASet(es, di, al);
    si += 0x0001;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    bp = ds;
    di += 0x0001;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x4e08, bp);
    memoryASet16(ds, 0x4e06, si);
    ax = es;
    memoryASet16(ds, 0x4df8, ax);
    memoryASet16(ds, 0x4df6, di);
    flags.carry = (memoryAGet16(ds, 0x4e12) + 0x0001) >= 0x10000;
    memoryASet16(ds, 0x4e12, memoryAGet16(ds, 0x4e12) + 0x0001);
    if (!flags.carry)
        goto loc_e937;
    memoryASet16(ds, 0x4e14, memoryAGet16(ds, 0x4e14) + 1);
loc_e937: // 0e15:07e7
    dx = memoryAGet16(ds, 0x4e00);
    ax = memoryAGet16(ds, 0x4dfe);
    if (dx != memoryAGet16(ds, 0x4df8))
        goto loc_e962;
    if (ax != memoryAGet16(ds, 0x4df6))
        goto loc_e962;
    ax = 0x1228;
    memoryASet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memoryASet16(ds, 0x4df6, ax);
    memoryASet16(ds, 0x4e1c, 0x0000);
    memoryASet16(ds, 0x4e1a, 0x0001);
loc_e962: // 0e15:0812
    dx = memoryAGet16(ds, 0x4e08);
    ax = memoryAGet16(ds, 0x4e06);
    if (dx != memoryAGet16(ds, 0x4e04))
        goto loc_e978;
    if (ax != memoryAGet16(ds, 0x4e02))
        goto loc_e978;
    goto loc_ea84;
loc_e978: // 0e15:0828
    dx = memoryAGet16(ds, 0x4e08);
    ax = memoryAGet16(ds, 0x4e06);
    if (dx <= memoryAGet16(ds, 0x4df8))
        goto loc_e988;
    goto loc_e86d;
loc_e988: // 0e15:0838
    if (dx != memoryAGet16(ds, 0x4df8))
        goto loc_e993;
    if (ax <= memoryAGet16(ds, 0x4df6))
        goto loc_e993;
    goto loc_e86d;
loc_e993: // 0e15:0843
    if (memoryAGet16(ds, 0x4e1c) == 0x0000)
        goto loc_e99d;
    goto loc_e86d;
loc_e99d: // 0e15:084d
    if (memoryAGet16(ds, 0x4e1a) == 0x0000)
        goto loc_e9a7;
    goto loc_e86d;
loc_e9a7: // 0e15:0857
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4dfc, ax);
    ax = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4dfa, ax);
    dx = memoryAGet16(ds, 0x4e08);
    cx = memoryAGet16(ds, 0x4e06);
    ax = memoryAGet16(ds, 0x4dfc);
    es = ax;
    di = memoryAGet16(ds, 0x4dfa);
    si = memoryAGet16(ds, 0x4e02);
    ax = memoryAGet16(ds, 0x4e04);
    ds = ax;
loc_e9cd: // 0e15:087d
    flags.carry = si < 0x0001;
    si -= 0x0001;
    if (!flags.carry)
        goto loc_e9da;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e9da: // 0e15:088a
    flags.carry = di < 0x0001;
    di -= 0x0001;
    if (!flags.carry)
        goto loc_e9e7;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e9e7: // 0e15:0897
    al = memoryAGet(ds, si);
    memoryASet(es, di, al);
    ax = ds;
    if (dx != ax)
        goto loc_e9cd;
    if (cx != si)
        goto loc_e9cd;
    ax = 0x1228;
    ds = ax;
    memoryASet16(ds, 0x4e04, bp);
    memoryASet16(ds, 0x4e02, si);
    ax = es;
    memoryASet16(ds, 0x4dfc, ax);
    memoryASet16(ds, 0x4dfa, di);
    ax = memoryAGet16(ds, 0x4dfc);
    memoryASet16(ds, 0x4e08, ax);
    ax = memoryAGet16(ds, 0x4dfa);
    memoryASet16(ds, 0x4e06, ax);
    ax = memoryAGet16(ds, 0x4e0c);
    memoryASet16(ds, 0x4e04, ax);
    ax = memoryAGet16(ds, 0x4e0a);
    memoryASet16(ds, 0x4e02, ax);
    goto loc_e86d;
loc_ea27: // 0e15:08d7
    ax = memoryAGet16(ds, 0x4df8);
    es = ax;
    di = memoryAGet16(ds, 0x4df6);
    al = memoryAGet(ds, 0x4e22);
    memoryASet(es, di, al);
    di += 0x0001;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    ax = es;
    memoryASet16(ds, 0x4df8, ax);
    memoryASet16(ds, 0x4df6, di);
    flags.carry = (memoryAGet16(ds, 0x4e12) + 0x0001) >= 0x10000;
    memoryASet16(ds, 0x4e12, memoryAGet16(ds, 0x4e12) + 0x0001);
    if (!flags.carry)
        goto loc_ea56;
    memoryASet16(ds, 0x4e14, memoryAGet16(ds, 0x4e14) + 1);
loc_ea56: // 0e15:0906
    dx = memoryAGet16(ds, 0x4e00);
    ax = memoryAGet16(ds, 0x4dfe);
    if (dx != memoryAGet16(ds, 0x4df8))
        goto loc_ea81;
    if (ax != memoryAGet16(ds, 0x4df6))
        goto loc_ea81;
    ax = 0x1228;
    memoryASet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memoryASet16(ds, 0x4df6, ax);
    memoryASet16(ds, 0x4e1c, 0x0000);
    memoryASet16(ds, 0x4e1a, 0x0001);
loc_ea81: // 0e15:0931
    goto loc_e978;
loc_ea84: // 0e15:0934
    ax = pop();
    memoryASet16(ds, 0x4e0a, ax);
    ax = pop();
    memoryASet16(ds, 0x4e0c, ax);
    ax = pop();
    memoryASet16(ds, 0x4e28, ax);
    ax = pop();
    memoryASet16(ds, 0x4e2a, ax);
    ax = pop();
    memoryASet16(ds, 0x4e24, ax);
    ax = pop();
    memoryASet16(ds, 0x4e26, ax);
loc_ea9c: // 0e15:094c
    al = memoryAGet(ds, 0x4e22);
    memoryASet(es, di, al);
    di += 0x0001;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    flags.carry = (memoryAGet16(ds, 0x4e12) + 0x0001) >= 0x10000;
    memoryASet16(ds, 0x4e12, memoryAGet16(ds, 0x4e12) + 0x0001);
    if (!flags.carry)
        goto loc_eab9;
    memoryASet16(ds, 0x4e14, memoryAGet16(ds, 0x4e14) + 1);
loc_eab9: // 0e15:0969
    dx = memoryAGet16(ds, 0x4e00);
    ax = memoryAGet16(ds, 0x4dfe);
    if (dx != memoryAGet16(ds, 0x4df8))
        goto loc_eae4;
    if (ax != memoryAGet16(ds, 0x4df6))
        goto loc_eae4;
    ax = 0x1228;
    memoryASet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memoryASet16(ds, 0x4df6, ax);
    memoryASet16(ds, 0x4e1c, 0x0000);
    memoryASet16(ds, 0x4e1a, 0x0001);
loc_eae4: // 0e15:0994
    dx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    if (dx > memoryAGet16(ds, 0x4e14))
        goto loc_ea9c;
    if (dx != memoryAGet16(ds, 0x4e14))
        goto loc_eaf9;
    if (ax > memoryAGet16(ds, 0x4e12))
        goto loc_ea9c;
loc_eaf9: // 0e15:09a9
    ax = 0x1228;
    memoryASet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memoryASet16(ds, 0x4df6, ax);
    cx = 0x0400;
    cx >>= 1;
    cx >>= 1;
    ax = memoryAGet16(ds, 0x4e00);
    es = ax;
    di = memoryAGet16(ds, 0x4dfe);
    si = memoryAGet16(ds, 0x4df6);
    ax = memoryAGet16(ds, 0x4df8);
    ds = ax;
loc_eb1e: // 0e15:09ce
    ax = memoryAGet16(ds, si + 2);
    memoryASet16(es, di + 2, ax);
    ax = memoryAGet16(ds, si);
    memoryASet16(es, di, ax);
    si += 0x0004;
    push(di);
    push(bp);
    push(es);
    ax = ds;
    es = ax;
    di = si;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    ds = dx;
    si = ax;
    es = pop();
    bp = pop();
    di = pop();
    di += 0x0004;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    if (--cx)
        goto loc_eb1e;
    ax = 0x1228;
    ds = ax;
    ax = 0x0001;
    assert(pop() == 0x7777);
}
void sub_eb59() // 0e15:0a09
{
    CStackGuard sg(0, false);
    ax = memoryAGet16(ds, 0x4e2a);
    push(ax);
    ax = memoryAGet16(ds, 0x4e28);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0c);
    push(ax);
    ax = memoryAGet16(ds, 0x4e0a);
    push(ax);
    ax = memoryAGet16(ds, 0x4e10);
    es = ax;
    push(ax);
    ax = memoryAGet16(ds, 0x4e0e);
    di = ax;
    push(ax);
    ax = memoryAGet16(es, di);
    tl = al;
    al = ah;
    ah = tl;
    bx = memoryAGet16(es, di + 2);
    tl = bl;
    bl = bh;
    bh = tl;
    memoryASet16(ds, 0x4e26, ax);
    memoryASet16(ds, 0x4e24, bx);
    memoryASet16(ds, 0x4e35, ax);
    memoryASet16(ds, 0x4e33, bx);
    if (ax > 0x000f)
        goto loc_ec06;
    if (ax != 0x000f)
        goto loc_eba0;
    if (bx > 0xffff)
        goto loc_ec06;
loc_eba0: // 0e15:0a50
    ax = memoryAGet16(es, di + 6);
    tl = al;
    al = ah;
    ah = tl;
    bx = memoryAGet16(es, di + 4);
    tl = bl;
    bl = bh;
    bh = tl;
    memoryASet16(ds, 0x4e20, ax);
    memoryASet16(ds, 0x4e1e, bx);
    ax = memoryAGet16(es, di + 8);
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(ds, 0x4e31, ax);
    si = ax;
    si &= 0x003f;
    if (si > 0x001e)
        goto loc_ec06;
    si += si;
    bx = memoryAGet16(ds, si + 20059);
    tl = bl;
    bl = bh;
    bh = tl;
    if ((short)bx < (short)0x0000)
        goto loc_ec06;
    si = ax;
    si &= 0x7f00;
    if (si != 0)
        goto loc_ec06;
    bx = memoryAGet16(ds, 0x4e26);
    ax = memoryAGet16(ds, 0x4e24);
    si = memoryAGet16(ds, 0x4e31);
    si ^= bx;
    si ^= ax;
    memoryASet16(ds, 0x4e26, bx);
    memoryASet16(ds, 0x4e24, ax);
    ax = memoryAGet16(ds, 0x4e20);
    bx = memoryAGet16(ds, 0x4e1e);
    si ^= bx;
    si ^= ax;
    ax = memoryAGet16(es, di + 10);
    tl = al;
    al = ah;
    ah = tl;
    if (si == ax)
        goto loc_ec07;
loc_ec06: // 0e15:0ab6
    flags.carry = true;
loc_ec07: // 0e15:0ab7
    ax = pop();
    memoryASet16(ds, 0x4e0e, ax);
    ax = pop();
    memoryASet16(ds, 0x4e10, ax);
    ax = pop();
    memoryASet16(ds, 0x4e0a, ax);
    ax = pop();
    memoryASet16(ds, 0x4e0c, ax);
    ax = pop();
    memoryASet16(ds, 0x4e28, ax);
    ax = pop();
    memoryASet16(ds, 0x4e2a, ax);
}
void sub_ec20() // 0ec2:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.carry = (ax + 0x000f) >= 0x10000;
    ax += 0x000f;
    if (!flags.carry)
        goto loc_ec2b;
    dx++;
loc_ec2b: // 0ec2:000b
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    bx = ax;
    ah = 0x48;
    interrupt(0x21);
    if (flags.carry)
        goto loc_ec48;
    dx = 0;
    tx = ax;
    ax = dx;
    dx = tx;
    goto loc_ec4c;
loc_ec48: // 0ec2:0028
    dx = 0;
    ax = 0;
loc_ec4c: // 0ec2:002c
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ec52() // 0ec2:0032
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    es = ax;
    ah = 0x49;
    interrupt(0x21);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ec70() // 0ec7:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    push(ax);
    push(bx);
    push(cs);
    sub_ecf9();
    es = dx;
    di = ax;
    bx = pop();
    ax = pop();
    cx = ax;
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr(ax, 0x0001);
    bx = cx;
    bx &= 0x000f;
    bx += di;
    dx = bx;
    bx = es;
    ax += bx;
    tx = ax;
    ax = dx;
    dx = tx;
    if ((short)ax <= (short)0x000f)
        goto loc_ecaf;
    ax &= 0x000f;
    dx++;
loc_ecaf: // 0ec7:003f
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ecb5() // 0ec7:0045
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    push(ax);
    push(bx);
    push(cs);
    sub_ecf9();
    es = dx;
    di = ax;
    bx = pop();
    ax = pop();
    cx = ax;
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = bx & 1;
    bx >>= 1;
    ax = rcr(ax, 0x0001);
    bx = cx;
    bx &= 0x000f;
    flags.carry = di < bx;
    di -= bx;
    if (!flags.carry)
        goto loc_ecea;
    di += 0x0010;
    ax++;
loc_ecea: // 0ec7:007a
    dx = di;
    bx = es;
    bx -= ax;
    ax = bx;
    tx = ax;
    ax = dx;
    dx = tx;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ecf9() // 0ec7:0089
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = di;
    di &= 0x000f;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    bx = es;
    ax += bx;
    dx = ax;
    ax = di;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ed20() // 0ed2:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memoryASet16(ds, 0x5676, ax);
    memoryASet16(ds, 0x5678, 0x0000);
    memoryASet16(ds, 0x567a, 0x0000);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ed3f() // 0ed2:001f
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    bx = memoryAGet16(ds, 0x5678);
    bp = memoryAGet16(ds, 0x567a);
    ax = bp;
    ax += 0x2432;
    ax ^= bx;
    ax ^= memoryAGet16(ds, 0x5676);
    bp = ax;
    ax = ror(ax, 0x0001);
    ax -= memoryAGet16(ds, 0x5676);
    ax ^= bx;
    ax += 0x1c12;
    ax ^= bp;
    ax = ror(ax, 0x0001);
    flags.carry = (ax + bp) >= 0x10000;
    ax += bp;
    ax = rcr(ax, 0x0001);
    bx = ax;
    ax = memoryAGet16(ds, 0x5676);
    ax += bp;
    ax ^= 0x3812;
    ax ^= bx;
    memoryASet16(ds, 0x5676, ax);
    memoryASet16(ds, 0x5678, bx);
    memoryASet16(ds, 0x567a, bp);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_f9c4() // 0ed9:0c34
{
    CStackGuard sg(0, false);
loc_f9c4: // 0ed9:0c34
    ax = es;
    bx = memoryAGet16(es, di);
    tl = bl;
    bl = bh;
    bh = tl;
    bx = ror(bx, 0x0001);
    bx = ror(bx, 0x0001);
    bx = ror(bx, 0x0001);
    bx = ror(bx, 0x0001);
    ax += bx;
    cx = bx;
    bx = memoryAGet16(es, di + 2);
    cx |= bx;
    if (!cx)
        return;
    tl = bl;
    bl = bh;
    bh = tl;
    cx = bx;
    cx &= 0x000f;
    cx += 0x0800;
    bx &= 0xfff0;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    ax += bx;
    memoryASet16(es, di + 2, ax);
    memoryASet16(es, di, cx);
    sub_fa07();
    di += 0x0004;
    goto loc_f9c4;
}
void sub_fa07() // 0ed9:0c77
{
    CStackGuard sg(0, false);
    push(ds);
    push(di);
    push(si);
    push(ax);
    push(cx);
    ax = memoryAGet16(ds, 0x541d);
    memoryASet16(cs, 0x0ded, ax);
    tx = di;
    di = memoryAGet16(es, tx);
    ds = memoryAGet16(es, tx + 2);
    cx = memoryAGet16(ds, di + 65534);
    tl = cl;
    cl = ch;
    ch = tl;
    memoryASet16(ds, di + 65534, cx);
    if ((short)cx < 0)
        goto loc_fa26;
    if (cx == 0)
        goto loc_fa26;
    goto loc_fa29;
loc_fa26: // 0ed9:0c96
    goto loc_fb77;
loc_fa29: // 0ed9:0c99
    ax = memoryAGet16(ds, di + 65532);
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(ds, di + 65532, ax);
    ax = memoryAGet16(ds, di + 65530);
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(ds, di + 65530, ax);
    ax = memoryAGet16(ds, di + 65528);
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(ds, di + 65528, ax);
    ax = memoryAGet16(ds, di + 65524);
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(ds, di + 65524, ax);
    ax = memoryAGet16(ds, di + 65526);
    tl = ah;
    ah = al;
    al = tl;
    memoryASet16(ds, di + 65526, ax);
    al &= 0xc0;
    if (al != 0)
        goto loc_fa26;
    si = di;
    ax = memoryAGet16(cs, 0x0ded);
    if (ax == 0x0000)
        goto loc_fa63;
    goto loc_fb3c;
loc_fa63: // 0ed9:0cd3
    ax = memoryAGet16(ds, di + 65532);
    ax >>= 1;
    ax >>= 1;
    dx = ax;
    if ((short)dx < 0)
        goto loc_fa26;
    if (dx == 0)
        goto loc_fa26;
loc_fa72: // 0ed9:0ce2
    al = memoryAGet(ds, si + 2);
    ah = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 1, al);
    al = memoryAGet(ds, si + 4);
    memoryASet(ds, si + 4, ah);
    memoryASet(ds, si + 2, al);
    al = memoryAGet(ds, si + 6);
    ah = memoryAGet(ds, si + 3);
    memoryASet(ds, si + 3, al);
    al = memoryAGet(ds, si + 5);
    memoryASet(ds, si + 5, ah);
    memoryASet(ds, si + 6, al);
    ax = memoryAGet16(ds, si);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    tl = bl;
    bl = bh;
    bh = tl;
    memoryASet16(ds, si, bx);
    ax = memoryAGet16(ds, si + 4);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(al & 0x80);
    al <<= 1;
    bx = rcl(bx, 0x0001);
    flags.carry = !!(ah & 0x80);
    ah <<= 1;
    bx = rcl(bx, 0x0001);
    tl = bl;
    bl = bh;
    bh = tl;
    memoryASet16(ds, si + 4, bx);
    ax = 0;
    memoryASet16(ds, si + 2, ax);
    memoryASet16(ds, si + 6, ax);
    si += 0x0008;
    dx--;
    if (dx != 0)
        goto loc_fb36;
    if (--cx)
        goto loc_fb39;
    goto loc_fb77;
loc_fb36: // 0ed9:0da6
    goto loc_fa72;
loc_fb39: // 0ed9:0da9
    goto loc_fa63;
loc_fb3c: // 0ed9:0dac
    ax = memoryAGet16(ds, di + 65532);
    ax >>= 1;
    ax >>= 1;
    dx = ax;
    if ((short)dx < 0)
        goto loc_fb77;
    if (dx == 0)
        goto loc_fb77;
loc_fb4b: // 0ed9:0dbb
    al = memoryAGet(ds, si + 2);
    ah = memoryAGet(ds, si + 1);
    memoryASet(ds, si + 1, al);
    al = memoryAGet(ds, si + 4);
    memoryASet(ds, si + 4, ah);
    memoryASet(ds, si + 2, al);
    al = memoryAGet(ds, si + 6);
    ah = memoryAGet(ds, si + 3);
    memoryASet(ds, si + 3, al);
    al = memoryAGet(ds, si + 5);
    memoryASet(ds, si + 5, ah);
    memoryASet(ds, si + 6, al);
    si += 0x0008;
    dx--;
    if (dx != 0)
        goto loc_fb4b;
    if (--cx)
        goto loc_fb3c;
loc_fb77: // 0ed9:0de7
    cx = pop();
    ax = pop();
    si = pop();
    di = pop();
    ds = pop();
}
void sub_fb7f() // 0ed9:0def
{
    CStackGuard sg(0, true);
    push(0x7777);
    ax = memoryAGet16(ss, bp + 4);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax &= 0xfffe;
    memoryASet16(ds, 0x680d, ax);
    dx = memoryAGet16(ss, bp + 8);
    dx++;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    dx &= 0xfffe;
    memoryASet16(ds, 0x680f, dx);
    dx -= ax;
    memoryASet16(ds, 0x6815, dx);
    ax = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x6811, ax);
    dx = memoryAGet16(ss, bp + 10);
    memoryASet16(ds, 0x6813, dx);
    dx -= ax;
    memoryASet16(ds, 0x6817, dx);
    assert(pop() == 0x7777);
}
void sub_fbb9() // 0ed9:0e29
{
    CStackGuard sg(0, true);
    push(0x7777);
    bx = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    if (!bx)
        goto loc_fbc3;
    sub_fbc4();
loc_fbc3: // 0ed9:0e33
    assert(pop() == 0x7777);
}
void sub_fbc4() // 0ed9:0e34
{
    CStackGuard sg(0, false);
    memoryASet16(ds, 0x6809, bx);
    si = es;
    memoryASet16(ds, 0x680b, si);
    ax = bx;
    ax |= si;
    if (!ax)
        return;
    sub_fbd8();
}
void sub_fbd8() // 0ed9:0e48
{
    CStackGuard sg(0, false);
    bx = memoryAGet16(ds, 0x6809);
    es = memoryAGet16(ds, 0x6809 + 2);
loc_fbdc: // 0ed9:0e4c
    push(es);
    di = memoryAGet16(es, bx);
    es = memoryAGet16(es, bx + 2);
    ax = es;
    ax |= di;
    if (!ax)
        goto loc_fbe9;
    push(bx);
    goto loc_fbef;
loc_fbe9: // 0ed9:0e59
    goto loc_fc8f;
loc_fbec: // 0ed9:0e5c
    goto loc_fc87;
loc_fbef: // 0ed9:0e5f
    al = memoryAGet(es, di + 10);
    if (!(al & 0x80))
        goto loc_fbec;
    ax = memoryAGet16(es, di);
    if (!(memoryAGet(es, di + 10) & 0x20))
        goto loc_fc11;
    bx = memoryAGet16(es, di + 16);
    bx <<= 1;
    bx <<= 1;
    ax -= bx;
    ax += memoryAGet16(es, di + 20);
    goto loc_fc15;
loc_fc11: // 0ed9:0e81
    ax -= memoryAGet16(es, di + 20);
loc_fc15: // 0ed9:0e85
    if (!(memoryAGet(es, di + 10) & 0x01))
        goto loc_fc22;
    ax += 0x0004;
    ax &= 0xfff8;
loc_fc22: // 0ed9:0e92
    bx = ax;
    bx &= 0x0007;
    memoryASet(cs, 0x3216, bl);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memoryASet16(ds, 0x6821, ax);
    ax = memoryAGet16(es, di + 2);
    ax -= memoryAGet16(es, di + 22);
    memoryASet16(ds, 0x6823, ax);
    dx = memoryAGet16(ds, 0x6813);
    ax = memoryAGet16(ds, 0x6823);
    if ((short)dx <= (short)ax)
        goto loc_fbec;
    dx = memoryAGet16(ds, 0x680f);
    ax = memoryAGet16(ds, 0x6821);
    if ((short)dx <= (short)ax)
        goto loc_fbec;
    dx = ax;
    ax = memoryAGet16(es, di + 16);
    ax >>= 1;
    dx += ax;
    if ((short)dx < 0)
        goto loc_fbec;
    ax = memoryAGet16(ds, 0x680d);
    if ((short)dx < (short)ax)
        goto loc_fbec;
    ax = memoryAGet16(ds, 0x6823);
    dx = ax;
    ax = memoryAGet16(es, di + 18);
    dx += ax;
    if ((short)dx < 0)
        goto loc_fc87;
    ax = memoryAGet16(ds, 0x6811);
    if ((short)dx < (short)ax)
        goto loc_fc87;
    push(bx);
    push(di);
    sub_fdcd();
    di = pop();
    bx = pop();
    goto loc_fbec;
loc_fc87: // 0ed9:0ef7
    bx = pop();
    es = pop();
    bx += 0x0004;
    goto loc_fbdc;
loc_fc8f: // 0ed9:0eff
    es = pop();
}
void sub_fce0() // 0ed9:0f50
{
    CStackGuard sg(0, false);
    memoryASet(ds, 0x683c, 0x00);
    memoryASet16(ds, 0x6819, 0x0000);
    ax = memoryAGet16(ds, 0x680d);
    ax -= memoryAGet16(ds, 0x6821);
    if ((short)ax >= 0)
        goto loc_fcfb;
    ax = -ax;
    memoryASet16(ds, 0x6819, ax);
    ax = 0;
loc_fcfb: // 0ed9:0f6b
    memoryASet16(ds, 0x681f, ax);
    if (ax == 0)
        goto loc_fd07;
    memoryASet(ds, 0x683c, memoryAGet(ds, 0x683c) | 0x02);
loc_fd07: // 0ed9:0f77
    ax = memoryAGet16(ds, 0x680f);
    ax -= memoryAGet16(ds, 0x6821);
    if ((short)ax < 0)
        goto loc_fd31;
    bx = memoryAGet16(es, di + 16);
    bx >>= 1;
    bx++;
    ax -= bx;
    if ((short)ax < 0)
        goto loc_fd31;
    ax = memoryAGet16(es, di + 16);
    ax >>= 1;
    ax -= memoryAGet16(ds, 0x681f);
    if ((short)ax >= 0)
        goto loc_fd29;
    ax = 0;
loc_fd29: // 0ed9:0f99
    memoryASet16(ds, 0x6835, ax);
    goto loc_fd43;
loc_fd2e: // 0ed9:0f9e
    ax = 0;
    return;
loc_fd31: // 0ed9:0fa1
    ax = memoryAGet16(ds, 0x681f);
    ax = -ax;
    ax += memoryAGet16(ds, 0x680f);
    ax -= memoryAGet16(ds, 0x6821);
    memoryASet(ds, 0x683c, memoryAGet(ds, 0x683c) | 0x01);
loc_fd43: // 0ed9:0fb3
    memoryASet16(ds, 0x6835, ax);
    memoryASet16(ds, 0x681b, 0x0000);
    ax = memoryAGet16(ds, 0x6811);
    ax -= memoryAGet16(ds, 0x6823);
    if ((short)ax >= 0)
        goto loc_fd5c;
    ax = -ax;
    memoryASet16(ds, 0x681b, ax);
    ax = 0;
loc_fd5c: // 0ed9:0fcc
    memoryASet16(ds, 0x681d, ax);
    ax = memoryAGet16(ds, 0x6811);
    ax += memoryAGet16(ds, 0x6817);
    ax -= memoryAGet16(ds, 0x6823);
    if ((short)ax < 0)
        goto loc_fd7d;
    ax -= memoryAGet16(es, di + 18);
    if ((short)ax < 0)
        goto loc_fd7d;
    ax = memoryAGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryAGet16(es, di + 18);
    goto loc_fd8e;
loc_fd7d: // 0ed9:0fed
    ax = memoryAGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryAGet16(ds, 0x6811);
    ax += memoryAGet16(ds, 0x6817);
    ax -= memoryAGet16(ds, 0x6823);
loc_fd8e: // 0ed9:0ffe
    memoryASet16(ds, 0x6837, ax);
    ax = memoryAGet16(ds, 0x681b);
    ax += memoryAGet16(ds, 0x6811);
    if (!(ax & ax))
        goto loc_fda0;
    bl = 0x28;
    mul(bl);
loc_fda0: // 0ed9:1010
    ax += memoryAGet16(ds, 0x56e2);
    ax += memoryAGet16(ds, 0x6819);
    ax += memoryAGet16(ds, 0x680d);
    memoryASet16(ds, 0x56e8, ax);
    ax = memoryAGet16(ds, 0x6835);
    if (ax == 0)
        goto loc_fdca;
    if ((short)ax < 0)
        goto loc_fdca;
    ax = memoryAGet16(ds, 0x6837);
    if (ax == 0)
        goto loc_fdca;
    if ((short)ax < 0)
        goto loc_fdca;
    if ((short)ax >= (short)0x0064)
        goto loc_fdca;
    ax |= 0x0001;
    return;
loc_fdca: // 0ed9:103a
    goto loc_fd2e;
}
void sub_fdcd() // 0ed9:103d
{
    CStackGuard sg(0, true);
    push(0x7777);
    sub_fce0();
    ax = memoryAGet16(ds, 0x681d);
    if (!(ax & ax))
        goto loc_fddf;
    bl = memoryAGet(es, di + 16);
    bl += bl;
    mul(bl);
loc_fddf: // 0ed9:104f
    ax += memoryAGet16(ds, 0x681f);
    ax += memoryAGet16(ds, 0x681f);
    ax += memoryAGet16(ds, 0x681f);
    ax += memoryAGet16(ds, 0x681f);
    memoryASet16(ds, 0x56e6, ax);
    ax = memoryAGet16(ds, 0x6835);
    dx = memoryAGet16(es, di + 16);
    dx >>= 1;
    cl = 0x28;
    cl -= al;
    ch = 0;
    dh = ch;
    memoryASet(ds, 0x683a, 0x00);
    goto loc_fe36;
    //   gap of 44 bytes
loc_fe36: // 0ed9:10a6
    push(es);
    push(di);
    al = memoryAGet(cs, 0x3216);
    memoryASet(ds, 0x683b, al);
    bp = memoryAGet16(es, di + 12);
    es = memoryAGet16(es, di + 12 + 2);
    bp += memoryAGet16(ds, 0x56e6);
    memoryASet16(ds, 0x6825, bp);
    ax = es;
    memoryASet16(ds, 0x6827, ax);
    si = memoryAGet16(ds, 0x56e8);
    memoryASet16(ds, 0x682d, si);
    ax = memoryAGet16(ds, 0x56e4);
    memoryASet16(ds, 0x682f, ax);
    memoryASet16(ds, 0x6833, 0x0028);
    memoryASet16(ds, 0x6831, dx);
    si = 0x6825;
    sub_fe71();
    di = pop();
    es = pop();
    assert(pop() == 0x7777);
}
void sub_fe71() // 0ed9:10e1
{
    CStackGuard sg(0, true);
//    push(0x7777);
    goto loc_fe71;
loc_f9b4: // 0ed9:0c24
    push(ax);
    ax = 0x0003;
    interrupt(0x10);
    ax = pop();
    dl = al;
    ah = 0x02;
    interrupt(0x21);
    interrupt(0x20);
    assert(pop() == 0x7777);
    return;
    //   gap of 1197 bytes
loc_fe71: // 0ed9:10e1
    push(ds);
    al = memoryAGet(ds, si + 23);
    memoryASet(cs, 0x3215, al);
    al = memoryAGet(ds, si + 22);
    memoryASet(cs, 0x3216, al);
    ax = memoryAGet16(ds, si + 18);
    ax--;
    memoryASet16(cs, 0x3213, ax);
    if ((short)ax >= 0)
        goto loc_fe8d;
    goto loc_10ec9;
loc_fe8d: // 0ed9:10fd
    bx = memoryAGet16(ds, si + 16);
    ax = memoryAGet16(ds, si + 14);
    ax -= bx;
    memoryASet16(cs, 0x320f, ax);
    cx = memoryAGet16(ds, si + 12);
    cx -= bx;
    al = memoryAGet(ds, si + 21);
    push(dx);
    push(ax);
    dx = 0x03ce;
    al = 0x05;
    out(dx, al);
    dx++;
    al = 0x00;
    out(dx, al);
    ax = pop();
    dx = pop();
    push(dx);
    push(ax);
    dx = 0x03ce;
    al = 0x03;
    out(dx, al);
    dx++;
    al = 0x00;
    out(dx, al);
    ax = pop();
    dx = pop();
    push(dx);
    push(ax);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    dx++;
    al = 0x0f;
    out(dx, al);
    ax = pop();
    dx = pop();
    bx += bx;
    ah = 0;
    ax += ax;
    dx = ax;
    ax += ax;
    ax += dx;
    bp = 0x328f;
    bp += ax;
    dx = memoryAGet16(cs, bp + 4);
    di = memoryAGet16(cs, bp);
    ax = memoryAGet16(cs, bx + di);
    memoryASet16(cs, 0x25e2, ax);
    ax = memoryAGet16(cs, bp + 2);
    push(ax);
    push(bx);
    al = memoryAGet(cs, 0x320e);
    bx = 0x11da;
    al &= 0x40;
    if (al == 0)
        goto loc_ff0b;
    bx = 0x11e2;
loc_ff0b: // 0ed9:117b
    ax = memoryAGet16(cs, bx);
    memoryASet16(cs, 0x11d5, ax);
    al = memoryAGet(cs, bx + 2);
    memoryASet(cs, 0x11d7, al);
    al = memoryAGet(cs, bx + 4);
    memoryASet(cs, 0x11d8, al);
    al = memoryAGet(cs, bx + 6);
    memoryASet(cs, 0x11d9, al);
    bx = pop();
    ax = pop();
    bp = memoryAGet16(ds, si);
    es = memoryAGet16(ds, si + 2);
    tx = si;
    si = memoryAGet16(ds, tx + 8);
    ds = memoryAGet16(ds, tx + 8 + 2);
    bl = memoryAGet(cs, 0x3216);
    bh = 0;
    bx += bx;
    di = memoryAGet16(cs, bx + 13093);
    if (dx == 0x0004)
        goto loc_ff5a;
    if (dx == 0x0002)
        goto loc_ff5c;
    if (dx == 0x0001)
        goto loc_ff58;
    if (dx == 0x0003)
        goto loc_ff58;
loc_ff53: // 0ed9:11c3
    ah = 0x01;
    goto loc_f9b4;
loc_ff58: // 0ed9:11c8
    goto loc_ff53;
loc_ff5a: // 0ed9:11ca
    cx += cx;
loc_ff5c: // 0ed9:11cc
    cx += cx;
    memoryASet16(cs, 0x3211, cx);
    switch (ax)
    {
        case 0x210b: goto loc_10e9b;
        default: assert(0);
    }
    //stop(/*2*/); // (jmp ax) jump Indirect ax
    //   gap of 3631 bytes
loc_10cd6: // 0ed9:1f46
    ax = memoryAGet16(es, bp);
    dx = memoryAGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryAGet(cs, 0x3216);
    ax = ror(ax, cl);
    dx = ror(dx, cl);
    cx = pop();
    push(ax);
    push(dx);
    ax &= di;
    dx &= di;
    bx |= ax;
    cx |= dx;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out(dx, al);
    memoryASet(ds, si, ch);
    si++;
    cx = pop();
    bx = pop();
    di = ~di;
    tl = bl;
    bl = bh;
    bh = tl;
    tl = cl;
    cl = ch;
    ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
    ax = memoryAGet16(es, bp);
    dx = memoryAGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryAGet(cs, 0x3216);
    ax = ror(ax, cl);
    dx = ror(dx, cl);
    cx = pop();
    push(ax);
    push(dx);
    ax &= di;
    dx &= di;
    bx |= ax;
    cx |= dx;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out(dx, al);
    memoryASet(ds, si, ch);
    si++;
    cx = pop();
    bx = pop();
    di = ~di;
    tl = bl;
    bl = bh;
    bh = tl;
    tl = cl;
    cl = ch;
    ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
loc_10d94: // 0ed9:2004
    ax = memoryAGet16(es, bp);
    dx = memoryAGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryAGet(cs, 0x3216);
    ax = ror(ax, cl);
    dx = ror(dx, cl);
    cx = pop();
    push(ax);
    push(dx);
    ax &= di;
    dx &= di;
    bx |= ax;
    cx |= dx;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out(dx, al);
    memoryASet(ds, si, ch);
    si++;
    cx = pop();
    bx = pop();
    di = ~di;
    tl = bl;
    bl = bh;
    bh = tl;
    tl = cl;
    cl = ch;
    ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
loc_10df3: // 0ed9:2063
    ax = memoryAGet16(es, bp);
    dx = memoryAGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryAGet(cs, 0x3216);
    ax = ror(ax, cl);
    dx = ror(dx, cl);
    cx = pop();
    push(ax);
    push(dx);
    ax &= di;
    dx &= di;
    bx |= ax;
    cx |= dx;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out(dx, al);
    memoryASet(ds, si, ch);
    si++;
    cx = pop();
    bx = pop();
    di = ~di;
    tl = bl;
    bl = bh;
    bh = tl;
    tl = cl;
    cl = ch;
    ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
    al = memoryAGet(cs, 0x3215);
    al &= 0x01;
    if (al != 0)
        goto loc_10e8a;
    ax = bx;
    ax |= cx;
    ah |= al;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    dx = 0x03c4;
    ax = memoryAGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryAGet(ds, si);
    memoryASet(ds, si, bl);
    al = memoryAGet(cs, 0x11d7);
    out(dx, al);
    memoryASet(ds, si, bh);
    al = memoryAGet(cs, 0x11d8);
    out(dx, al);
    memoryASet(ds, si, cl);
    al = memoryAGet(cs, 0x11d9);
    out(dx, al);
    memoryASet(ds, si, ch);
loc_10e8a: // 0ed9:20fa
    memoryASet16(cs, 0x3213, memoryAGet16(cs, 0x3213) - 1);
    if ((short)memoryAGet16(cs, 0x3213) < 0)
        goto loc_10ec9;
    bp += memoryAGet16(cs, 0x3211);
    si += memoryAGet16(cs, 0x320f);
loc_10e9b: // 0ed9:210b
    bx = 0;
    cx = 0;
    al = memoryAGet(cs, 0x3215);
    al &= 0x02;
    if (al == 0)
        goto loc_10ec6;
    bx = memoryAGet16(es, bp - 4);
    ax = memoryAGet16(es, bp - 2);
    cl = memoryAGet(cs, 0x3216);
    bx = ror(bx, cl);
    ax = ror(ax, cl);
    cx = ax;
    di = ~di;
    tl = bl;
    bl = bh;
    bh = tl;
    tl = cl;
    cl = ch;
    ch = tl;
    bx &= di;
    cx &= di;
    di = ~di;
loc_10ec6: // 0ed9:2136
    goto loc_11371;
loc_10ec9: // 0ed9:2139
    dx = 0x03ce;
    ax = 0xff08;
    out(dx, ax);
    ds = pop();
    return;
    //   gap of 1183 bytes
loc_11371: // 0ed9:25e1
    ax = 0x0000;
//    stop(/*2*/); // (jmp ax) jump Indirect ax
    ax = memoryAGet16(cs, 0x25e2);
    switch (ax)
    {
        case 0x2004: goto loc_10d94; break; //ed9:2004
        case 0x2063: goto loc_10df3; break;
        case 0x1f46: goto loc_10cd6; break; //ed9:1f46
        default:
            assert(0);

            
    }    //stop();
}

void sub_11a7d() // 0ed9:2ced
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x2d09;
    di = memoryAGet16(ds, 0x541d);
    di += di;
    ax = memoryAGet16(cs, bx + di);
    di = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    callIndirect(cs*16+ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11aa5() // 0ed9:2d15
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    ds = dx;
    si = ax;
    bx = 0x2d37;
    di = memoryAGet16(ds, 0x541d);
    di += di;
    ax = memoryAGet16(cs, bx + di);
    callIndirect(cs*16+ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11afd() // 0ed9:2d6d
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    push(ds);
    si = memoryAGet16(ds, 0x56de);
    ds = memoryAGet16(ds, 0x56de + 2);
    tx = si;
    si = memoryAGet16(ds, tx);
    ds = memoryAGet16(ds, tx + 2);
    ax = ds;
    ds = pop();
    memoryASet16(ds, 0x56e2, si);
    memoryASet16(ds, 0x56e4, ax);
    bx = 0x2d9c;
    di = memoryAGet16(ds, 0x541d);
    di += di;
    ax = memoryAGet16(cs, bx + di);
    callIndirect(cs*16+ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11b38() // 0ed9:2da8
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    bx = 0x2dc6;
    di = memoryAGet16(ds, 0x541d);
    di += di;
    ax = memoryAGet16(cs, bx + di);
    callIndirect(cs*16+ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11b62() // 0ed9:2dd2
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ss, bp + 4);
    ax <<= 1;
    ax <<= 1;
    ax += 0x5415;
    memoryASet16(ds, 0x56de, ax);
    ax = 0x1228;
    memoryASet16(ds, 0x56e0, ax);
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11b7d() // 0ed9:2ded
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    si = memoryAGet16(ss, bp + 4);
    es = memoryAGet16(ss, bp + 4 + 2);
    memoryASet16(ds, 0x56ee, 0x56f0);
loc_11b90: // 0ed9:2e00
    push(es);
    bx = memoryAGet16(es, si);
    es = memoryAGet16(es, si + 2);
    ax = es;
    ax |= bx;
    if (ax)
        goto loc_11ba1;
    es = pop();
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
    return;
loc_11ba1: // 0ed9:2e11
    ax = memoryAGet16(es, bx + 4);
    ax <<= 1;
    ax <<= 1;
    di = 0x1228;
    ds = di;
    di = memoryAGet16(es, bx + 6);
    ds = memoryAGet16(es, bx + 6 + 2);
    di += ax;
    tx = di;
    di = memoryAGet16(ds, tx);
    ds = memoryAGet16(ds, tx + 2);
    memoryASet16(es, bx + 12, di);
    ax = ds;
    memoryASet16(es, bx + 14, ax);
    ax |= di;
    if (ax)
        goto loc_11bca;
    memoryASet16(es, bx + 10, 0x0000);
loc_11bca: // 0ed9:2e3a
    ax = memoryAGet16(ds, di + 65534);
    memoryASet16(es, bx + 18, ax);
    ax = memoryAGet16(ds, di + 65532);
    memoryASet16(es, bx + 16, ax);
    ax = memoryAGet16(ds, di + 65530);
    memoryASet16(es, bx + 20, ax);
    ax = memoryAGet16(ds, di + 65528);
    memoryASet16(es, bx + 22, ax);
    ax = memoryAGet16(ds, di + 65524);
    memoryASet16(es, bx + 24, ax);
    if (ax < 0x0003)
        goto loc_11bf5;
    ax = 0x0003;
loc_11bf5: // 0ed9:2e65
    memoryASet16(es, bx + 24, ax);
    if (!ax)
        goto loc_11c20;
    push(ds);
    push(di);
    push(es);
    push(si);
    push(cx);
    cx = ax;
    si = di + 0xfffffff4;
    di = bx + 0x1a;
loc_11c0a: // 0ed9:2e7a
    si--;
    si--;
    movsw<MemAuto, MemAuto, DirAuto>();
    si--;
    si--;
    si--;
    si--;
    movsw<MemAuto, MemAuto, DirAuto>();
    si--;
    si--;
    si--;
    si--;
    movsw<MemAuto, MemAuto, DirAuto>();
    si--;
    si--;
    if (--cx)
        goto loc_11c0a;
    cx = pop();
    si = pop();
    es = pop();
    di = pop();
    ds = pop();
loc_11c20: // 0ed9:2e90
    al = memoryAGet(ds, di + 65526);
    memoryASet(es, bx + 11, al);
    al &= 0xc0;
    if (al != 0)
        goto loc_11c32;
loc_11c2b: // 0ed9:2e9b
    si += 0x0004;
    es = pop();
    goto loc_11b90;
loc_11c32: // 0ed9:2ea2
    if (al & 0x40)
        goto loc_11c39;
    goto loc_11df8;
loc_11c39: // 0ed9:2ea9
    push(si);
    push(di);
    dh = memoryAGet(es, bx + 10);
    ax = memoryAGet16(es, 0x56ee);
    si = di;
    si -= 0x000c;
    di = ax;
    ax += 0x000c;
    memoryASet16(es, bx + 12, ax);
    ax = 0x1228;
    memoryASet16(es, bx + 14, ax);
    es = ax;
    cx = 0x0006;
    rep_movsw<MemAuto, MemAuto, DirAuto>();
    bx = si;
    al = memoryAGet(ds, si + 65532);
    al >>= 1;
    al >>= 1;
    ah = memoryAGet(ds, si + 65534);
    mul(ah);
    si += ax;
    cx = ax;
    if (dh & 0x20)
        goto loc_11c79;
    goto loc_11d93;
loc_11c79: // 0ed9:2ee9
    cx = memoryAGet16(ds, bx + 65532);
    bp = cx;
    cx <<= 1;
    di -= cx;
    di -= 0x0008;
    cx = memoryAGet16(ds, bx + 65534);
loc_11c88: // 0ed9:2ef8
    push(cx);
    cx = bp;
    cx <<= 1;
    cx <<= 1;
    di += cx;
    cx = bp;
    cx >>= 1;
    cx >>= 1;
loc_11c97: // 0ed9:2f07
    push(cx);
    cl = memoryAGet(ds, bx);
    bx++;
    push(bx);
    ah = 0;
    al = 0;
    if (!(cl & 0x80))
        goto loc_11cb0;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11cb0: // 0ed9:2f20
    ch = al;
    al = 0;
    if (!(cl & 0x40))
        goto loc_11cc4;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11cc4: // 0ed9:2f34
    stosb<MemAuto, DirAuto>();
    al = 0;
    if (!(cl & 0x20))
        goto loc_11cd7;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11cd7: // 0ed9:2f47
    dl = al;
    al = 0;
    if (!(cl & 0x10))
        goto loc_11ceb;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11ceb: // 0ed9:2f5b
    stosb<MemAuto, DirAuto>();
    al = 0;
    if (!(cl & 0x08))
        goto loc_11cfe;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11cfe: // 0ed9:2f6e
    dh = al;
    al = 0;
    if (!(cl & 0x04))
        goto loc_11d12;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11d12: // 0ed9:2f82
    stosb<MemAuto, DirAuto>();
    al = 0;
    if (!(cl & 0x02))
        goto loc_11d25;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryAGet(es, bx);
    si++;
loc_11d25: // 0ed9:2f95
    ah = al;
    al = 0;
    if (!(cl & 0x01))
        goto loc_11d3c;
    al = memoryAGet(ds, si);
    bx = 0x66f0;
    flags.carry = (bl + al) >= 0x100;
    bl += al;
    bh += flags.carry;
    al = memoryAGet(es, bx);
    si++;
loc_11d3c: // 0ed9:2fac
    stosb<MemAuto, DirAuto>();
    cl = ah;
    ax = memoryAGet16(cs, 0x0ded);
    if (ax != 0x0000)
        goto loc_11d60;
    ax = memoryAGet16(es, di + 65534);
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(es, di + 65534, ax);
    ax = memoryAGet16(es, di + 65532);
    tl = al;
    al = ah;
    ah = tl;
    memoryASet16(es, di + 65532, ax);
    tl = dl;
    dl = ch;
    ch = tl;
    tl = cl;
    cl = dh;
    dh = tl;
loc_11d60: // 0ed9:2fd0
    al = ch;
    stosb<MemAuto, DirAuto>();
    al = dl;
    stosb<MemAuto, DirAuto>();
    al = dh;
    stosb<MemAuto, DirAuto>();
    al = cl;
    stosb<MemAuto, DirAuto>();
    di -= 0x0010;
    bx = pop();
    cx = pop();
    cx--;
    if (!cx)
        goto loc_11d79;
    goto loc_11c97;
loc_11d79: // 0ed9:2fe9
    cx = pop();
    cx--;
    if (!cx)
        goto loc_11d82;
    goto loc_11c88;
loc_11d82: // 0ed9:2ff2
    bp <<= 1;
    di += bp;
    di += 0x0008;
    memoryASet16(es, 0x56ee, di);
    di = pop();
    si = pop();
    goto loc_11c2b;
loc_11d93: // 0ed9:3003
    push(cx);
    cl = memoryAGet(ds, bx);
    bx++;
    ax = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11da0;
    al = memoryAGet(ds, si);
    si++;
loc_11da0: // 0ed9:3010
    stosb<MemAuto, DirAuto>();
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11da8;
    ah = memoryAGet(ds, si);
    si++;
loc_11da8: // 0ed9:3018
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11db1;
    al = memoryAGet(ds, si);
    si++;
loc_11db1: // 0ed9:3021
    stosb<MemAuto, DirAuto>();
    ch = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dbb;
    ch = memoryAGet(ds, si);
    si++;
loc_11dbb: // 0ed9:302b
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dc4;
    al = memoryAGet(ds, si);
    si++;
loc_11dc4: // 0ed9:3034
    stosb<MemAuto, DirAuto>();
    dl = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dce;
    dl = memoryAGet(ds, si);
    si++;
loc_11dce: // 0ed9:303e
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dd7;
    al = memoryAGet(ds, si);
    si++;
loc_11dd7: // 0ed9:3047
    stosb<MemAuto, DirAuto>();
    al = ah;
    stosb<MemAuto, DirAuto>();
    al = ch;
    stosb<MemAuto, DirAuto>();
    al = dl;
    stosb<MemAuto, DirAuto>();
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dea;
    al = memoryAGet(ds, si);
    si++;
loc_11dea: // 0ed9:305a
    stosb<MemAuto, DirAuto>();
    cx = pop();
    if (--cx)
        goto loc_11d93;
    memoryASet16(es, 0x56ee, di);
    di = pop();
    si = pop();
    goto loc_11c2b;
loc_11df8: // 0ed9:3068
    goto loc_11c2b;
}
void sub_11ec7() // 0ed9:3137
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    bx = 0x66f0;
    cx = 0x0000;
    ax = memoryAGet16(ds, 0x541d);
    if (ax != 0x0000)
        goto loc_11f15;
loc_11edf: // 0ed9:314f
    dl = cl;
    flags.carry = dl & 1;
    dl >>= 1;
    al = rcr(al, 0x01);
    flags.carry = dl & 1;
    dl >>= 1;
    ah = rcl(ah, 0x01);
    ax <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    al = rcr(al, 0x01);
    flags.carry = dl & 1;
    dl >>= 1;
    ah = rcl(ah, 0x01);
    ax <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    al = rcr(al, 0x01);
    flags.carry = dl & 1;
    dl >>= 1;
    ah = rcl(ah, 0x01);
    ax <<= 1;
    flags.carry = dl & 1;
    dl >>= 1;
    al = rcr(al, 0x01);
    flags.carry = dl & 1;
    dl >>= 1;
    ah = rcl(ah, 0x01);
    ax <<= 1;
    memoryASet(ds, bx, ah);
    bx++;
    cx++;
    if ((short)cx <= (short)0x00ff)
        goto loc_11edf;
    goto loc_11f41;
loc_11f15: // 0ed9:3185
    ah = cl;
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl(al, 0x01);
    flags.carry = ah & 1;
    ah >>= 1;
    al = rcl(al, 0x01);
    memoryASet(ds, bx, al);
    bx++;
    cx++;
    if ((short)cx <= (short)0x00ff)
        goto loc_11f15;
loc_11f41: // 0ed9:31b1
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11f47() // 0ed9:31b7
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    ax = memoryAGet16(ss, bp + 4);
    memoryASet16(ds, 0x67f0, ax);
    dx = memoryAGet16(ss, bp + 6);
    memoryASet16(ds, 0x67f2, dx);
    es = dx;
    di = ax;
    al = memoryAGet(es, di + 10);
    memoryASet(cs, 0x320e, al);
    bp = sp;
    ax = 0x1228;
    push(ax);
    ax = 0x67f0;
    push(ax);
    push(bp);
    bp = sp;
    bp -= 0x0002;
    push(cs);
    sub_11b7d();
    bp = pop();
    sp = bp;
    bp = sp;
    ax = 0x1228;
    push(ax);
    ax = 0x67f0;
    push(ax);
    push(bp);
    bp = sp;
    bp -= 0x0002;
    push(cs);
    sub_11afd();
    bp = pop();
    sp = bp;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12190() // 1219:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    ax = 0x0002;
    interrupt(0x10);
    si = 0x6840;
    bh = 0;
    dx = 0x0101;
    ah = 0x02;
    interrupt(0x10);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    si = 0x6858;
    di = 0x689e;
    bh = 0x00;
    cx = 0x0004;
    dx = 0x0a21;
loc_121bf: // 1219:002f
    if (memoryAGet(ds, di) != 0x01)
        goto loc_121d2;
    ah = 0x02;
    interrupt(0x10);
    push(dx);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    dx = pop();
    dh++;
loc_121d2: // 1219:0042
    si += 0x0011;
    di++;
    if (--cx)
        goto loc_121bf;
loc_121d8: // 1219:0048
    sync();
    al = 0x3f;
    push(cs);
    cs = 0x01ed;
    sub_b67a();
    assert(cs == 0x1219);
    if (!flags.zero)
        goto loc_121fe;
    al = 0x40;
    push(cs);
    cs = 0x01ed;
    sub_b67a();
    assert(cs == 0x1219);
    if (!flags.zero)
        goto loc_12206;
    al = 0x41;
    push(cs);
    cs = 0x01ed;
    sub_b67a();
    assert(cs == 0x1219);
    if (!flags.zero)
        goto loc_1220e;
    al = 0x42;
    push(cs);
    cs = 0x01ed;
    sub_b67a();
    assert(cs == 0x1219);
    if (!flags.zero)
        goto loc_12216;
    goto loc_121d8;
loc_121fe: // 1219:006e
    memoryASet16(ds, 0x689c, 0x8000);
    goto loc_12223;
loc_12206: // 1219:0076
    memoryASet16(ds, 0x689c, 0x0000);
    goto loc_12223;
loc_1220e: // 1219:007e
    memoryASet16(ds, 0x689c, 0x0001);
    goto loc_12223;
loc_12216: // 1219:0086
    memoryASet16(ds, 0x689c, 0x0004);
    goto loc_12223;
    //   gap of 5 bytes
loc_12223: // 1219:0093
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12230() // 1223:0000
{
    CStackGuardFar sg(0, true);
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = memoryAGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryAGet16(ds, bx + 26998));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_12245() // 1223:0015
{
    CStackGuard sg(0, false);
    dx = 0x03da;
loc_12248: // 1223:0018
    in(al, dx);
    if (!(al & 0x08))
        goto loc_12248;
loc_1224d: // 1223:001d
    in(al, dx);
    if (al & 0x08)
        goto loc_1224d;
}
