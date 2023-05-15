#include "cicoctx.h"
using namespace CicoContext;

int bumpyStartupLevel = 1;
const char* bumpyScene = "";

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
void sub_3d2e();
void sub_3d60();
void sub_3d92();
void sub_3dd3();
void sub_3e0e();
void sub_3e4f();
void sub_3e8e();
void sub_3f4d();
void sub_4008();
void sub_408b();
void sub_40b7();
void sub_4131();
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
void sub_61eb();
void sub_6214();
void sub_6231();
void sub_6268();
void sub_6285();
void sub_62a2();
void sub_62bf();
void sub_62dc();
void sub_6307();
void sub_6324();
void sub_635a();
void sub_6390();
void sub_63dc();
void sub_6402();
void sub_644a();
void sub_6470();
void sub_649f();
void sub_64d5();
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
void sub_6d14();
void sub_6d4f();
void sub_6d99();
void sub_6dd4();
void sub_6e1e();
void sub_6e59();
void sub_6ea3();
void sub_6ed3();
void sub_6ef5();
void sub_6f0f();
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
void sub_832d();
void sub_834e();
void sub_8391();
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
void sub_869a();
void sub_86b2();
void sub_86cb();
void sub_86e3();
void sub_8702();
void sub_871b();
void sub_873a();
void sub_8760();
void sub_878b();
void sub_87b6();
void sub_87ce();
void sub_87f2();
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
void sub_b310();
void sub_b321();
void sub_b32b();
void sub_b33e();
void sub_b358();
void sub_b3d2();
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
// INJECT: Error: cannot inject zero flag in sub_a761()!
// INJECT: Error: cannot inject flag in sub_b32b() because of being label!
// INJECT: Error: cannot inject flag in sub_c9ad() because of being label!
// INJECT: Error: cannot inject zero flag in sub_a761()!
// INJECT: Error: cannot inject flag in sub_b32b() because of being label!
// INJECT: Error: cannot inject flag in sub_c9ad() because of being label!
void sub_1ed0()
{
    push(0x7777);
    dx = 0x1228;
    memorySet16(cs, 0x01ff, dx);
    ah = 0x30;
    interrupt(0x21);
    bp = memoryBiosGet16(ds, 0x0002);
    bx = memoryBiosGet16(ds, 0x002c);
    ds = dx;
    memorySet16(ds, 0x007b, ax);
    memorySet16(ds, 0x0079, es);
    memorySet16(ds, 0x0075, bx);
    memorySet16(ds, 0x008d, bp);
    sub_1fff();
    di = memoryGet16(ds, 0x0073);
    es = memoryGet16(ds, 0x0073 + 2);
    ax = di;
    bx = ax;
    cx = 0x7fff;
    flags.direction = false;
loc_1f04:
    repne_scasb<MemBios, DirForward>(al);
    if (cx == 0)
        goto loc_1f44;
    bx++;
    if (memoryBiosGet(es, di) != al)
        goto loc_1f04;
    ch |= 0x80;
    cx = -cx;
    memorySet16(ds, 0x0073, cx);
    cx = 0x0002;
    bx <<= cl;
    bx += 0x0010;
    bx &= 0xfff0;
    memorySet16(ds, 0x0077, bx);
    dx = ss;
    bp -= dx;
    di = memoryGet16(ds, 0x6b4c);
    if (di >= 0x0200)
        goto loc_1f3b;
    di = 0x0200;
    memorySet16(ds, 0x6b4c, di);
loc_1f3b:
    cl = 0x04;
    di >>= cl;
    di++;
    if (bp >= di)
        goto loc_1f47;
loc_1f44:
    goto loc_20ba;
loc_1f47:
    bx = di;
    bx += dx;
    memorySet16(ds, 0x0085, bx);
    memorySet16(ds, 0x0089, bx);
    ax = memoryGet16(ds, 0x0079);
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
    memorySet16(ds, 0x6b4c, di);
    flags.interrupts = true;
    ax = 0;
    es = memoryGet16(cs, 0x01ff);
    di = 0x6bba;
    cx = 0xa202;
    cx -= di;
    flags.direction = false;
    rep_stosb<MemData, DirForward>();
    ah = 0x00;
    interrupt(0x1a);
    memorySet16(ds, 0x007f, dx);
    memorySet16(ds, 0x0081, cx);
    bp = 0;
    ax = 0x1227;
    ds = ax;
    si = 0x0000;
    di = 0x000c;
    sub_206f();
    ds = memoryGet16(cs, 0x01ff);
    memorySet(cs, 0x01b1, 0x72);
    memorySet(cs, 0x01a0, 0x00);
    push(memoryGet16(ds, 0x0071));
    push(memoryGet16(ds, 0x006f));
    push(memoryGet16(ds, 0x006d));
    push(memoryGet16(ds, 0x006b));
    push(memoryGet16(ds, 0x0069));
    sub_20d3();
    push(ax);
    sub_b78a();
    ax = 0x1227;
    ds = ax;
    si = 0x000c;
    di = 0x000c;
    sub_206f();
    ds = memoryGet16(cs, 0x01ff);
    callIndirect(cs*16+memoryGet16(ds, 0x6984));
    callIndirect(cs*16+memoryGet16(ds, 0x6986));
    callIndirect(cs*16+memoryGet16(ds, 0x6988));
    ds = memoryGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002d;
    goto loc_20c0;
    //   gap of 187 bytes
loc_20ba:
    cx = 0x001e;
    dx = 0x003b;
loc_20c0:
    ds = memoryGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memorySet(ds, bx + si, memoryGet(ds, bx + si) + al);
    ax += memoryGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df:
    if (memoryGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 6 + 2);
    ax = memoryGet16(es, bx + 6);
    dx = memoryGet16(es, bx + 4);
    memorySet16(ds, 0x6be4, dx);
    memorySet16(ds, 0x6be6, ax);
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
loc_2126:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1fc6()
{
    push(0x7777);
    ax = 0x1227;
    ds = ax;
    si = 0x000c;
    di = 0x000c;
    sub_206f();
    ds = memoryGet16(cs, 0x01ff);
    callIndirect(cs*16+memoryGet16(ds, 0x6984));
    callIndirect(cs*16+memoryGet16(ds, 0x6986));
    callIndirect(cs*16+memoryGet16(ds, 0x6988));
    ds = memoryGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002d;
    goto loc_20c0;
    //   gap of 193 bytes
loc_20c0:
    ds = memoryGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memorySet(ds, bx + si, memoryGet(ds, bx + si) + al);
    ax += memoryGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df:
    if (memoryGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 6 + 2);
    ax = memoryGet16(es, bx + 6);
    dx = memoryGet16(es, bx + 4);
    memorySet16(ds, 0x6be4, dx);
    memorySet16(ds, 0x6be6, ax);
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
loc_2126:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1fe5()
{
    push(0x7777);
    ds = memoryGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002d;
    goto loc_20c0;
    //   gap of 193 bytes
loc_20c0:
    ds = memoryGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memorySet(ds, bx + si, memoryGet(ds, bx + si) + al);
    ax += memoryGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df:
    if (memoryGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 6 + 2);
    ax = memoryGet16(es, bx + 6);
    dx = memoryGet16(es, bx + 4);
    memorySet16(ds, 0x6be4, dx);
    memorySet16(ds, 0x6be6, ax);
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
loc_2126:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_1fff()
{
    push(ds);
    ax = 0x3500;
    interrupt(0x21);
    memorySet16(ds, 0x0059, bx);
    memorySet16(ds, 0x005b, es);
    ax = 0x3504;
    interrupt(0x21);
    memorySet16(ds, 0x005d, bx);
    memorySet16(ds, 0x005f, es);
    ax = 0x3505;
    interrupt(0x21);
    memorySet16(ds, 0x0061, bx);
    memorySet16(ds, 0x0063, es);
    ax = 0x3506;
    interrupt(0x21);
    memorySet16(ds, 0x0065, bx);
    memorySet16(ds, 0x0067, es);
    ax = 0x2500;
    dx = cs;
    ds = dx;
    dx = 0x0126;
    interrupt(0x21);
    ds = pop();
}
void sub_2042()
{
    push(ds);
    ax = 0x2500;
    dx = memoryGet16(ds, 0x0059);
    ds = memoryGet16(ds, 0x0059 + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2504;
    dx = memoryGet16(ds, 0x005d);
    ds = memoryGet16(ds, 0x005d + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2505;
    dx = memoryGet16(ds, 0x0061);
    ds = memoryGet16(ds, 0x0061 + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    ax = 0x2506;
    dx = memoryGet16(ds, 0x0065);
    ds = memoryGet16(ds, 0x0065 + 2);
    interrupt(0x21);
    ds = pop();
}
void sub_206f()
{
    push(0x7777);
loc_206f:
    ah = 0xff;
    dx = di;
    bx = si;
loc_2075:
    if (bx == di)
        goto loc_208d;
    if (memoryGet(ds, bx) == 0xff)
        goto loc_2088;
    if (memoryGet(ds, bx + 1) > ah)
        goto loc_2088;
    ah = memoryGet(ds, bx + 1);
    dx = bx;
loc_2088:
    bx += 0x0006;
    goto loc_2075;
loc_208d:
    if (dx == di)
    {
        assert(pop() == 0x7777);
        return;
    }
    bx = dx;
    push(ds);
    es = pop();
    push(es);
    tl = memoryGet(ds, bx);
    memorySet(ds, bx, 0xff);
    ds = memoryGet16(cs, 0x01ff);
    if (tl == 0)
        goto loc_20aa;
    push(cs);
    cs = memoryGet16(es, bx + 2 + 2);
    callIndirect(memoryGet16(es, bx + 2 + 2)*16 + memoryGet16(es, bx + 2));
    assert(cs == 0x01ed);
    ds = pop();
    goto loc_206f;
loc_20aa:
    callIndirect(cs*16+memoryGet16(es, bx + 2));
    ds = pop();
    goto loc_206f;
}
void sub_20b2()
{
    ah = 0x40;
    bx = 0x0002;
    interrupt(0x21);
}
void sub_20d3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df:
    if (memoryGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 6 + 2);
    ax = memoryGet16(es, bx + 6);
    dx = memoryGet16(es, bx + 4);
    memorySet16(ds, 0x6be4, dx);
    memorySet16(ds, 0x6be6, ax);
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
loc_2126:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2128()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_2134;
    sub_ca53();
loc_2134:
    memorySet(ds, 0x79b2, bumpyStartupLevel);
    sub_722e();
    sub_8cb3();
loc_213f:
    sub_2ae8();
    if (memoryGet(ds, 0x9d30) != 0x00)
        goto loc_213f;
    if (memoryGet(ds, 0x856d) != 0x00)
        goto loc_213f;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2152()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_215e;
    sub_ca53();
loc_215e:
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
    memorySet(ds, 0x6bec, al);
    ah = 0x00;
    memorySet16(ds, 0x7310, ax);
    memorySet(ds, 0x7312, al);
    memorySet(ds, 0x6bc9, al);
    memorySet(ds, 0x7314, al);
    al = 0x00;
    memorySet(ds, 0x731b, al);
    memorySet(ds, 0x6bba, al);
    memorySet(ds, 0x75ed, al);
    memorySet(ds, 0x75ec, al);
    memorySet(ds, 0x75eb, al);
    memorySet(ds, 0x75ce, al);
    al = 0x00;
    memorySet(ds, 0x6c34, al);
    memorySet(ds, 0x6bc8, al);
    ah = 0x00;
    memorySet16(ds, 0x6bc2, ax);
    memorySet16(ds, 0x6bc0, ax);
    memorySet16(ds, 0x6c40, ax);
    memorySet16(ds, 0x6c3e, ax);
    memorySet16(ds, 0x75c8, ax);
    memorySet(ds, 0x6bc5, 0x01);
    memorySet(ds, 0x6bc4, 0x14);
    al = 0x00;
    memorySet(ds, 0x6faa, al);
    memorySet(ds, 0x75e2, al);
    al = 0x00;
    memorySet(ds, 0x75cf, al);
    memorySet(ds, 0x75c6, al);
    memorySet(ds, 0x6bdf, al);
    memorySet(ds, 0x6bc6, al);
    ax = 0;
    memorySet16(ds, 0x6bf8, ax);
    memorySet16(ds, 0x6bbe, ax);
    memorySet16(ds, 0x6bbc, ax);
    ax = 0;
    memorySet16(ds, 0x6bd6, ax);
    memorySet16(ds, 0x6bce, ax);
    ax = 0;
    memorySet16(ds, 0x6bdc, ax);
    memorySet16(ds, 0x6bd0, ax);
    ax = 0;
    memorySet16(ds, 0x6bda, ax);
    memorySet16(ds, 0x6bd8, ax);
    al = 0x01;
    memorySet(ds, 0x6bf6, al);
    memorySet(ds, 0x6c26, al);
    ax = 0;
    memorySet16(ds, 0x6be2, ax);
    memorySet16(ds, 0x6be0, ax);
    memorySet16(ds, 0x7316, 0x006c);
    al = 0x00;
    memorySet(ds, 0x6bbb, al);
    memorySet(ds, 0x6bde, al);
    memorySet(ds, 0x6bc7, 0x09);
    memorySet(ds, 0x75ea, 0x00);
    ax = memoryGet16(ds, 0x7310);
    dx = 0x032c;
    imul(dx);
    dx = memoryGet16(ds, 0x6bd4);
    bx = memoryGet16(ds, 0x6bd2);
    bx += ax;
    memorySet16(ds, 0x6bca, bx);
    memorySet16(ds, 0x6bcc, dx);
    ax = memoryGet16(ds, 0x7310);
    dx = 0x00c2;
    imul(dx);
    dx = memoryGet16(ds, 0x6bf4);
    bx = memoryGet16(ds, 0x6bf2);
    bx += ax;
    memorySet16(ds, 0x75d0, bx);
    memorySet16(ds, 0x75d2, dx);
    sub_22ba();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_22ba()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_22c6;
    sub_ca53();
loc_22c6:
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
void sub_22e6()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_22f4;
    sub_ca53();
loc_22f4:
    memorySet(ss, bp - 1, 0x00);
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x07c3;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memorySet16(ds, 0x75da, ax);
    memorySet16(ds, 0x75dc, dx);
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x0898;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memorySet16(ds, 0x6c2c, ax);
    memorySet16(ds, 0x6c2e, dx);
    al = 0x01;
    push(ax);
    ax = 0;
    dx = 0x7806;
    push(ax);
    push(dx);
    sub_9f5e();
    sp += 0x0006;
    memorySet16(ds, 0x6fa6, ax);
    memorySet16(ds, 0x6fa8, dx);
    ax |= dx;
    if (ax)
        goto loc_2345;
    memorySet(ss, bp - 1, 0xff);
loc_2345:
    al = memoryGet(ss, bp - 1);
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
    memorySet16(ds, 0xa0c6, ax);
    memorySet16(ds, 0xa0c8, dx);
    ax |= dx;
    if (ax)
        goto loc_236e;
    memorySet(ss, bp - 1, 0xff);
loc_236e:
    al = memoryGet(ss, bp - 1);
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
    memorySet16(ds, 0x6be8, ax);
    memorySet16(ds, 0x6bea, dx);
    ax |= dx;
    if (ax)
        goto loc_2398;
    memorySet(ss, bp - 1, 0xff);
    goto loc_23a8;
loc_2398:
    ax = memoryGet16(ds, 0x6bea);
    dx = memoryGet16(ds, 0x6be8);
    dx++;
    dx++;
    memorySet16(ds, 0x6bd2, dx);
    memorySet16(ds, 0x6bd4, ax);
loc_23a8:
    al = memoryGet(ss, bp - 1);
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
    memorySet16(ds, 0x6c30, ax);
    memorySet16(ds, 0x6c32, dx);
    ax |= dx;
    if (ax)
        goto loc_23d0;
    memorySet(ss, bp - 1, 0xff);
loc_23d0:
    al = memoryGet(ss, bp - 1);
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
    memorySet16(ds, 0x7926, ax);
    memorySet16(ds, 0x7928, dx);
    ax |= dx;
    if (ax)
        goto loc_23f8;
    memorySet(ss, bp - 1, 0xff);
loc_23f8:
    al = memoryGet(ss, bp - 1);
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
    memorySet16(ds, 0x75de, ax);
    memorySet16(ds, 0x75e0, dx);
    ax |= dx;
    if (ax)
        goto loc_2422;
    memorySet(ss, bp - 1, 0xff);
    goto loc_2432;
loc_2422:
    ax = memoryGet16(ds, 0x75e0);
    dx = memoryGet16(ds, 0x75de);
    dx++;
    dx++;
    memorySet16(ds, 0x6bf2, dx);
    memorySet16(ds, 0x6bf4, ax);
loc_2432:
    al = memoryGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2439()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_2445;
    sub_ca53();
loc_2445:
    push(memoryGet16(ds, 0x75e0));
    push(memoryGet16(ds, 0x75de));
    sub_9f6e();
    sp += 0x0004;
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    sub_9f6e();
    sp += 0x0004;
    push(memoryGet16(ds, 0x6c32));
    push(memoryGet16(ds, 0x6c30));
    sub_9f6e();
    sp += 0x0004;
    push(memoryGet16(ds, 0x6bea));
    push(memoryGet16(ds, 0x6be8));
    sub_9f6e();
    sp += 0x0004;
    push(memoryGet16(ds, 0xa0c8));
    push(memoryGet16(ds, 0xa0c6));
    sub_9f6e();
    sp += 0x0004;
    push(memoryGet16(ds, 0x6fa8));
    push(memoryGet16(ds, 0x6fa6));
    sub_9f6e();
    sp += 0x0004;
    push(memoryGet16(ds, 0x6c2e));
    push(memoryGet16(ds, 0x6c2c));
    sub_9f6e();
    sp += 0x0004;
    push(memoryGet16(ds, 0x75dc));
    push(memoryGet16(ds, 0x75da));
    sub_9f6e();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_24b7()
{
    sync();
    return;
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_24c8;
    sub_ca53();
    goto loc_24c8;
loc_24c5:
    sub_b734();
loc_24c8:
    al = memoryGet(ss, bp + 4);
    memorySet(ss, bp + 4, memoryGet(ss, bp + 4) - 1);
    if (al)
        goto loc_24c5;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_24d4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_24e0;
    sub_ca53();
loc_24e0:
    al = memoryGet(ds, 0x75cf);
    ah = 0x00;
    if (ax)
        goto loc_24f9;
    bx = memoryGet16(ds, 0x6bca);
    es = memoryGet16(ds, 0x6bca + 2);
    if (memoryGet16(es, bx + 28) == 0x0000)
        goto loc_24f9;
    sub_250b();
    goto loc_24fe;
loc_24f9:
    memorySet(ds, 0x75cf, 0x01);
loc_24fe:
    push(ds);
    ax = 0x0578;
    push(ax);
    sub_27a1();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_250b()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_251c;
    sub_ca53();
loc_251c:
    memorySet(ss, bp - 1, 0x00);
    goto loc_255c;
loc_2522:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = memoryGet16(ds, 0x6bca);
    es = memoryGet16(ds, 0x6bca + 2);
    bx += ax;
    si = memoryGet16(es, bx);
    ax = si;
    ax &= 0x00ff;
    cl = 0x08;
    ax <<= cl;
    memorySet16(ss, bp - 4, ax);
    ax = si;
    ax &= 0xff00;
    ax >>= cl;
    di = ax;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    dx = memoryGet16(ss, bp - 4);
    dx |= di;
    bx = ax;
    memorySet16(ds, bx + 1400, dx);
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) + 1);
loc_255c:
    if (memoryGet(ss, bp - 1) < 0x10)
        goto loc_2522;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_26c0()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_26cc;
    sub_ca53();
loc_26cc:
    push(memoryGet16(ss, bp + 10));
    push(memoryGet16(ss, bp + 8));
    sub_b707();
    sp += 0x0004;
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_b6d4();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_26e6()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_26f5;
    sub_ca53();
loc_26f5:
    if (memoryGet(ss, bp + 8) <= 0x07)
        goto loc_26fe;
    goto loc_278c;
loc_26fe:
    memorySet(ss, bp - 11, 0x00);
    goto loc_2717;
loc_2704:
    al = memoryGet(ss, bp - 11);
    memorySet(ss, bp - 11, memoryGet(ss, bp - 11) + 1);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    memorySet(ss, bx, 0x20);
loc_2717:
    al = memoryGet(ss, bp - 11);
    if (al <= memoryGet(ss, bp + 8))
        goto loc_2704;
    al = memoryGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    memorySet(ss, bx, 0x00);
    goto loc_2776;
loc_2731:
    al = memoryGet(ss, bp + 4);
    memorySet(ss, bp - 1, al);
    ax = 0;
    dx = 0x000a;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_c7be();
    memorySet16(ss, bp + 4, ax);
    bx = ax;
    memorySet16(ss, bp + 6, dx);
    cx = dx;
    dx = 0;
    ax = 0x000a;
    sub_c8e4();
    dl = memoryGet(ss, bp - 1);
    dl -= al;
    memorySet(ss, bp - 1, dl);
    al = memoryGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    dl = memoryGet(ss, bp - 1);
    dl += 0x30;
    bx = ax;
    memorySet(ss, bx, dl);
loc_2776:
    al = memoryGet(ss, bp + 8);
    memorySet(ss, bp + 8, memoryGet(ss, bp + 8) - 1);
    if (al)
        goto loc_2731;
    push(memoryGet16(ss, bp + 12));
    push(memoryGet16(ss, bp + 10));
    push(ss);
    ax = bp - 0xa;
    goto loc_2796;
loc_278c:
    push(memoryGet16(ss, bp + 12));
    push(memoryGet16(ss, bp + 10));
    push(ds);
    ax = 0x062e;
loc_2796:
    push(ax);
    sub_26c0();
    sp += 0x0008;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_27a1()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_27b1;
    sub_ca53();
loc_27b1:
    memorySet16(ss, bp - 4, 0x6c42);
    memorySet16(ss, bp - 2, ds);
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_27f6;
    memorySet16(ds, 0x9b96, 0x6c42);
    memorySet16(ds, 0x9b98, ds);
    memorySet(ss, bp - 6, 0x00);
    goto loc_27ed;
loc_27d0:
    al = memoryGet(ss, bp - 6);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 6);
    ah = 0x00;
    si = ax;
    al = memoryGet(ds, si + 1806);
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 6, memoryGet(ss, bp - 6) + 1);
loc_27ed:
    if (memoryGet(ss, bp - 6) < 0x10)
        goto loc_27d0;
    goto loc_28b9;
loc_27f6:
    memorySet(ss, bp - 5, 0x00);
    goto loc_28b0;
loc_27fd:
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    ax <<= 1;
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    bx += ax;
    ax = memoryGet16(es, bx);
    cl = 0x08;
    ax >>= cl;
    memorySet(ss, bp - 7, al);
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    ax <<= 1;
    bx = memoryGet16(ss, bp + 4);
    bx += ax;
    ax = memoryGet16(es, bx);
    dl = memoryGet(ds, 0x75eb);
    dh = 0x00;
    dx <<= cl;
    ax -= dx;
    cl = 0x04;
    ax >>= cl;
    memorySet(ss, bp - 8, al);
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    ax <<= 1;
    bx = memoryGet16(ss, bp + 4);
    bx += ax;
    al = memoryGet(es, bx);
    dl = memoryGet(ds, 0x75eb);
    cl = 0x08;
    dl <<= cl;
    bl = memoryGet(ds, 0x75ec);
    cl = 0x04;
    bl <<= cl;
    dl += bl;
    al -= dl;
    memorySet(ss, bp - 9, al);
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0003;
    imul(dx);
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 7);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memorySet(es, bx + 51, al);
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0003;
    imul(dx);
    bx = memoryGet16(ss, bp - 4);
    bx += ax;
    al = memoryGet(ss, bp - 8);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memorySet(es, bx + 52, al);
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0003;
    imul(dx);
    bx = memoryGet16(ss, bp - 4);
    bx += ax;
    al = memoryGet(ss, bp - 9);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    memorySet(es, bx + 53, al);
    memorySet(ss, bp - 5, memoryGet(ss, bp - 5) + 1);
loc_28b0:
    if (memoryGet(ss, bp - 5) >= 0x10)
        goto loc_28b9;
    goto loc_27fd;
loc_28b9:
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
void sub_28d7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_28e4;
    sub_ca53();
loc_28e4:
    ax = 0x0004;
    push(ax);
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x00c0));
    push(memoryGet16(ds, 0x00be));
    push(memoryGet16(ds, 0x75dc));
    push(memoryGet16(ds, 0x75da));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryGet16(ds, 0x75dc));
    push(memoryGet16(ds, 0x75da));
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
    push(memoryGet16(ds, 0x00f2));
    push(memoryGet16(ds, 0x00f0));
    push(memoryGet16(ds, 0x6c2e));
    push(memoryGet16(ds, 0x6c2c));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryGet16(ds, 0x6c2e));
    push(memoryGet16(ds, 0x6c2c));
    sub_b2a8();
    sp += 0x0004;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2960()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_2970;
    sub_ca53();
loc_2970:
    ax = memoryGet16(ds, 0x6fa8);
    dx = memoryGet16(ds, 0x6fa6);
    dx += 0x0006;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0018);
    ax = memoryGet16(ss, bp + 10);
    memorySet16(es, bx + 14, ax);
    memorySet16(es, bx + 28, 0x0006);
    memorySet16(es, bx + 30, 0x0001);
    if (memoryGet16(ss, bp + 8) != 0x0018)
        goto loc_29b3;
    memorySet16(es, bx + 32, 0x0001);
    goto loc_29bd;
loc_29b3:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 32, 0x0002);
loc_29bd:
    if (memoryGet(ss, bp + 4) <= 0xf0)
        goto loc_29d1;
    memorySet(ss, bp - 2, 0x01);
    al = 0xfb;
    al -= memoryGet(ss, bp + 4);
    memorySet(ss, bp - 1, al);
    goto loc_2a4a;
loc_29d1:
    memorySet(ss, bp - 2, 0x00);
    memorySet(ss, bp - 1, 0x01);
    goto loc_2a4a;
loc_29db:
    ax = memoryGet16(ss, bp + 6);
    dx = 0x0027;
    imul(dx);
    bx = memoryGet16(ds, 0x6bca);
    es = memoryGet16(ds, 0x6bca + 2);
    bx += ax;
    ax = memoryGet16(ss, bp + 8);
    ax = sar(ax, 1);
    dx = 0x0003;
    imul(dx);
    bx += ax;
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryGet(es, bx + 32);
    al += 0xff;
    memorySet(ss, bp + 4, al);
    ah = 0x00;
    bx = 0x0014;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    idiv(bx);
    ax <<= 1;
    si = ax;
    dx = 0x000a;
    imul(dx);
    dl = memoryGet(ss, bp + 4);
    dh = 0x00;
    dx -= ax;
    di = dx;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 6, di);
    memorySet16(es, bx + 8, si);
    ax = memoryGet16(ss, bp + 6);
    memorySet16(es, bx + 20, ax);
    ax = memoryGet16(ss, bp + 8);
    memorySet16(es, bx + 22, ax);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
loc_2a4a:
    al = memoryGet(ss, bp - 2);
    if (al < memoryGet(ss, bp - 1))
        goto loc_29db;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2a58()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_2a64;
    sub_ca53();
loc_2a64:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    ax = memoryGet16(ss, bp + 8);
    memorySet16(es, bx + 14, ax);
    ax = memoryGet16(ss, bp + 4);
    memorySet16(es, bx + 20, ax);
    ax = memoryGet16(ss, bp + 6);
    memorySet16(es, bx + 22, ax);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0001);
    if (memoryGet16(ss, bp + 6) != 0x0018)
        goto loc_2a97;
    memorySet16(es, bx + 32, 0x0001);
    goto loc_2aa1;
loc_2a97:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 32, 0x0002);
loc_2aa1:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet(es, bx + 34, 0x00);
    memorySet(es, bx + 35, 0x00);
    memorySet(es, bx + 36, 0x00);
    memorySet(es, bx + 37, 0x00);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2ac9()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_2ad5;
    sub_ca53();
loc_2ad5:
    sub_5180();
    sub_4948();
    sub_50ae();
    al = 0x00;
    memorySet(ds, 0x9d30, al);
    memorySet(ds, 0x856d, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2ae8()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_2af6;
    sub_ca53();
loc_2af6:
    sub_5295();
    sub_4dc8();
loc_2afc:
    memorySet(ds, 0x928d, 0x00);
    memorySet(ds, 0x791a, 0x05);
    al = 0x00;
    memorySet(ds, 0x79b5, al);
    ah = 0x00;
    memorySet16(ds, 0xa0d4, ax);
    memorySet16(ds, 0xa0d6, 0x0000);
    goto loc_2b26;
loc_2b18:
    if (memoryGet(ss, bp - 1) != 0x01)
        goto loc_2b23;
    sub_7551();
    goto loc_2b26;
loc_2b23:
    sub_2e4a();
loc_2b26:
    sub_5475();
    memorySet(ss, bp - 1, al);
    if (al)
        goto loc_2b18;
    goto loc_2c5a;
loc_2b33:
    sub_5722();
    if (memoryGet(ds, 0x928d) != 0xff)
        goto loc_2b42;
    sub_30bb();
    goto loc_2afc;
loc_2b42:
    al = memoryGet(ds, 0x854e);
    ah = 0x00;
    ax--;
    memorySet16(ds, 0x7310, ax);
    sub_5337();
    sub_2ac9();
    al = memoryGet(ds, 0x8562);
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
loc_2baa:
    bumpyScene = "game";
    sub_b281();
    memorySet(ds, 0x79b3, al);
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
loc_2c19:
    if (memoryGet(ds, 0x928d) != 0x00)
        goto loc_2c31;
    if (memoryGet(ds, 0x856d) != 0x00)
        goto loc_2c31;
    if (memoryGet(ds, 0x9d30) != 0x00)
        goto loc_2c31;
    goto loc_2baa;
loc_2c31:
    if (memoryGet(ds, 0x928d) != 0xff)
        goto loc_2c40;
    sub_30bb();
    sub_7551();
    goto loc_2c5d;
loc_2c40:
    sub_5d5a();
    if (!al)
        goto loc_2c5d;
    memorySet(ds, 0x79b2, memoryGet(ds, 0x79b2) + 1);
    if (memoryGet(ds, 0x79b2) != 0x0a)
        goto loc_2c57;
    sub_5da4();
    goto loc_2c5d;
loc_2c57:
    sub_2c6d();
loc_2c5a:
    sub_4be4();
loc_2c5d:
    al = memoryGet(ds, 0x928d);
    ah = 0x00;
    if (ax)
        goto loc_2c69;
    goto loc_2b33;
loc_2c69:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_2c6d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_2c7e;
    sub_ca53();
loc_2c7e:
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
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(ds, 0x857e, dx);
    memorySet16(ds, 0x8580, ax);
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
    push(memoryGet16(ds, 0x8580));
    push(memoryGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_2d1a;
    ax = memoryGet16(ds, 0x8580);
    dx = memoryGet16(ds, 0x857e);
    memorySet16(ds, 0x9b96, dx);
    memorySet16(ds, 0x9b98, ax);
    memorySet(ss, bp - 13, 0x00);
    goto loc_2d14;
loc_2cf7:
    al = memoryGet(ss, bp - 13);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 13);
    ah = 0x00;
    di = ax;
    al = memoryGet(ds, di + 1822);
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 13, memoryGet(ss, bp - 13) + 1);
loc_2d14:
    if (memoryGet(ss, bp - 13) < 0x10)
        goto loc_2cf7;
loc_2d1a:
    sub_5337();
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x8580));
    push(memoryGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    memorySet(ss, bp - 9, 0x04);
    memorySet(ss, bp - 10, 0x05);
    ax = memoryGet16(ss, bp - 2);
    dx = memoryGet16(ss, bp - 4);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    al = memoryGet(ss, bp - 10);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    memorySet(ss, bp - 12, 0x00);
    goto loc_2da4;
loc_2d64:
    al = memoryGet(ss, bp - 12);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ss, bp - 11, al);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memorySet16(es, bx + 4, ax);
    al = memoryGet(ss, bp - 9);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memorySet16(es, bx, ax);
    if (memoryGet(ss, bp - 11) == 0x20)
        goto loc_2d9e;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_2d9e:
    memorySet(ss, bp - 9, memoryGet(ss, bp - 9) + 1);
    memorySet(ss, bp - 12, memoryGet(ss, bp - 12) + 1);
loc_2da4:
    if (memoryGet(ss, bp - 12) < 0x0d)
        goto loc_2d64;
    memorySet(ss, bp - 9, 0x07);
    memorySet(ss, bp - 10, 0x07);
    al = memoryGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 4950);
    dx = memoryGet16(ds, bx + 4948);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    al = memoryGet(ss, bp - 10);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    memorySet(ss, bp - 12, 0x00);
    goto loc_2e1c;
loc_2de2:
    al = memoryGet(ss, bp - 12);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ss, bp - 11, al);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memorySet16(es, bx + 4, ax);
    al = memoryGet(ss, bp - 9);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memorySet16(es, bx, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memorySet(ss, bp - 9, memoryGet(ss, bp - 9) + 1);
    memorySet(ss, bp - 12, memoryGet(ss, bp - 12) + 1);
loc_2e1c:
    if (memoryGet(ss, bp - 12) < 0x06)
        goto loc_2de2;
loc_2e22:
    sync();
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
void sub_2e4a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0016;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_2e5b;
    sub_ca53();
loc_2e5b:
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
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(ds, 0x857e, dx);
    memorySet16(ds, 0x8580, ax);
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
    push(memoryGet16(ds, 0x8580));
    push(memoryGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_2f17;
    ax = memoryGet16(ds, 0x8580);
    dx = memoryGet16(ds, 0x857e);
    memorySet16(ds, 0x9b96, dx);
    memorySet16(ds, 0x9b98, ax);
    memorySet(ss, bp - 22, 0x00);
    goto loc_2f11;
loc_2ef4:
    al = memoryGet(ss, bp - 22);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 22);
    ah = 0x00;
    di = ax;
    al = memoryGet(ds, di + 1822);
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 22, memoryGet(ss, bp - 22) + 1);
loc_2f11:
    if (memoryGet(ss, bp - 22) < 0x10)
        goto loc_2ef4;
loc_2f17:
    sub_5337();
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x8580));
    push(memoryGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    memorySet(ss, bp - 17, 0x00);
    memorySet(ss, bp - 18, 0x01);
    ax = memoryGet16(ss, bp - 2);
    dx = memoryGet16(ss, bp - 4);
    memorySet16(ss, bp - 16, dx);
    memorySet16(ss, bp - 14, ax);
    al = memoryGet(ss, bp - 18);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    memorySet(ss, bp - 20, 0x00);
    goto loc_2fa1;
loc_2f61:
    al = memoryGet(ss, bp - 20);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 16);
    es = memoryGet16(ss, bp - 16 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ss, bp - 19, al);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memorySet16(es, bx + 4, ax);
    al = memoryGet(ss, bp - 17);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memorySet16(es, bx, ax);
    if (memoryGet(ss, bp - 19) == 0x20)
        goto loc_2f9b;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_2f9b:
    memorySet(ss, bp - 17, memoryGet(ss, bp - 17) + 1);
    memorySet(ss, bp - 20, memoryGet(ss, bp - 20) + 1);
loc_2fa1:
    if (memoryGet(ss, bp - 20) < 0x13)
        goto loc_2f61;
    memorySet(ss, bp - 17, 0x07);
    memorySet(ss, bp - 18, 0x0a);
    al = memoryGet(ss, bp - 18);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    memorySet(ss, bp - 20, 0x00);
    goto loc_2ff7;
loc_2fc6:
    memorySet(ss, bp - 19, 0x41);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    al = memoryGet(ss, bp - 19);
    ah = 0x00;
    ax += 0x0175;
    memorySet16(es, bx + 4, ax);
    al = memoryGet(ss, bp - 17);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memorySet16(es, bx, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memorySet(ss, bp - 17, memoryGet(ss, bp - 17) + 1);
    memorySet(ss, bp - 20, memoryGet(ss, bp - 20) + 1);
loc_2ff7:
    if (memoryGet(ss, bp - 20) < 0x06)
        goto loc_2fc6;
    al = 0x07;
    push(ax);
    al = 0x0a;
    push(ax);
    sub_7b57();
    sp += 0x0004;
    memorySet(ss, bp - 21, al);
    if (!al)
        goto loc_3024;
    ax = memoryGet16(ss, bp - 6);
    dx = memoryGet16(ss, bp - 8);
    memorySet16(ss, bp - 16, dx);
    memorySet16(ss, bp - 14, ax);
    al = memoryGet(ss, bp - 21);
    memorySet(ds, 0x79b2, al);
    goto loc_3035;
loc_3024:
    ax = memoryGet16(ss, bp - 10);
    dx = memoryGet16(ss, bp - 12);
    memorySet16(ss, bp - 16, dx);
    memorySet16(ss, bp - 14, ax);
    memorySet(ds, 0x79b2, 0x01);
loc_3035:
    memorySet(ss, bp - 17, 0x03);
    memorySet(ss, bp - 18, 0x06);
    al = memoryGet(ss, bp - 18);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    memorySet(ss, bp - 20, 0x00);
    goto loc_3094;
loc_3054:
    al = memoryGet(ss, bp - 20);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 16);
    es = memoryGet16(ss, bp - 16 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ss, bp - 19, al);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memorySet16(es, bx + 4, ax);
    al = memoryGet(ss, bp - 17);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memorySet16(es, bx, ax);
    if (memoryGet(ss, bp - 19) == 0x20)
        goto loc_308e;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_308e:
    memorySet(ss, bp - 17, memoryGet(ss, bp - 17) + 1);
    memorySet(ss, bp - 20, memoryGet(ss, bp - 20) + 1);
loc_3094:
    if (memoryGet(ss, bp - 20) < 0x0e)
        goto loc_3054;
    memorySet(ss, bp - 20, 0x00);
    goto loc_30a6;
loc_30a0:
    sub_5d44();
    memorySet(ss, bp - 20, memoryGet(ss, bp - 20) + 1);
loc_30a6:
    if (memoryGet(ss, bp - 20) < 0x03)
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
void sub_30bb()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000e;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_30cc;
    sub_ca53();
loc_30cc:
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
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(ds, 0x857e, dx);
    memorySet16(ds, 0x8580, ax);
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
    push(memoryGet16(ds, 0x8580));
    push(memoryGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_3168;
    ax = memoryGet16(ds, 0x8580);
    dx = memoryGet16(ds, 0x857e);
    memorySet16(ds, 0x9b96, dx);
    memorySet16(ds, 0x9b98, ax);
    memorySet(ss, bp - 13, 0x00);
    goto loc_3162;
loc_3145:
    al = memoryGet(ss, bp - 13);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 13);
    ah = 0x00;
    di = ax;
    al = memoryGet(ds, di + 1822);
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 13, memoryGet(ss, bp - 13) + 1);
loc_3162:
    if (memoryGet(ss, bp - 13) < 0x10)
        goto loc_3145;
loc_3168:
    sub_5337();
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x8580));
    push(memoryGet16(ds, 0x857e));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    sub_b734();
    al = 0x06;
    memorySet(ss, bp - 10, al);
    memorySet(ss, bp - 9, al);
    ax = memoryGet16(ss, bp - 2);
    dx = memoryGet16(ss, bp - 4);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    al = memoryGet(ss, bp - 10);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    memorySet(ss, bp - 12, 0x00);
    goto loc_31f2;
loc_31b2:
    al = memoryGet(ss, bp - 12);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ss, bp - 11, al);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ah = 0x00;
    ax += 0x0175;
    memorySet16(es, bx + 4, ax);
    al = memoryGet(ss, bp - 9);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memorySet16(es, bx, ax);
    if (memoryGet(ss, bp - 11) == 0x20)
        goto loc_31ec;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_31ec:
    memorySet(ss, bp - 9, memoryGet(ss, bp - 9) + 1);
    memorySet(ss, bp - 12, memoryGet(ss, bp - 12) + 1);
loc_31f2:
    if (memoryGet(ss, bp - 12) < 0x09)
        goto loc_31b2;
    memorySet(ss, bp - 12, 0x00);
    goto loc_3204;
loc_31fe:
    sub_5d44();
    memorySet(ss, bp - 12, memoryGet(ss, bp - 12) + 1);
loc_3204:
    if (memoryGet(ss, bp - 12) < 0x02)
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
void sub_3219()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3227;
    sub_ca53();
loc_3227:
    memorySet(ss, bp - 2, 0x01);
    if (!(memoryGet(ds, 0x854f) & 0x01))
        goto loc_3236;
    al = 0x80;
    goto loc_3238;
loc_3236:
    al = 0x00;
loc_3238:
    memorySet(ss, bp - 1, al);
    if (!al)
        goto loc_3242;
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
loc_3242:
    al = memoryGet(ds, 0x854f);
    ah = 0x00;
    ax = sar(ax, 1);
    al |= memoryGet(ss, bp - 1);
    memorySet(ds, 0x854f, al);
    al = memoryGet(ss, bp - 2);
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_325c()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3268;
    sub_ca53();
loc_3268:
    ax = memoryGet16(ds, 0x857a);
    memorySet16(ds, 0x8882, ax);
    ax = memoryGet16(ds, 0x857c);
    memorySet16(ds, 0x8e88, ax);
    ax = memoryGet16(ds, 0x9d36);
    memorySet16(ds, 0x857a, ax);
    ax = memoryGet16(ds, 0x9d38);
    memorySet16(ds, 0x857c, ax);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3282()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_328e;
    sub_ca53();
loc_328e:
    if (memoryGet(ds, 0x8571) == 0xff)
        goto loc_32ad;
    ax = memoryGet16(ds, 0x8558);
    memorySet16(ds, 0x928e, ax);
    ax = memoryGet16(ds, 0x855a);
    memorySet16(ds, 0x9b94, ax);
    ax = memoryGet16(ds, 0xa0ca);
    memorySet16(ds, 0x8558, ax);
    ax = memoryGet16(ds, 0xa0cc);
    memorySet16(ds, 0x855a, ax);
loc_32ad:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_32af()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_32bb;
    sub_ca53();
loc_32bb:
    al = memoryGet(ds, 0x8242);
    ah = 0x00;
    if (ax)
        goto loc_3341;
    if (memoryGet(ds, 0x824d) == 0x00)
        goto loc_3341;
    if (memoryGet(ds, 0x792c) == 0x05)
        goto loc_3341;
    if (memoryGet(ds, 0x792c) == 0x0b)
        goto loc_3341;
    if (memoryGet(ds, 0x792c) == 0x1c)
        goto loc_3341;
    bx = memoryGet16(ds, 0xa1ac);
    es = memoryGet16(ds, 0xa1ac + 2);
    ax = memoryGet16(es, bx);
    memorySet16(ds, 0x824a, ax);
    if (memoryGet(ds, 0x9bae) == 0x00)
        goto loc_3305;
    ax = memoryGet16(es, bx + 2);
    ax = -ax;
    dx = memoryGet16(ds, 0x9290);
    dx += ax;
    memorySet16(ds, 0x9290, dx);
    ax = dx;
    goto loc_3314;
loc_3305:
    bx = memoryGet16(ds, 0xa1ac);
    es = memoryGet16(ds, 0xa1ac + 2);
    ax = memoryGet16(es, bx + 2);
    memorySet16(ds, 0x9290, memoryGet16(ds, 0x9290) + ax);
    ax = memoryGet16(ds, 0x9290);
loc_3314:
    bx = memoryGet16(ds, 0xa1ac);
    es = memoryGet16(ds, 0xa1ac + 2);
    ax = memoryGet16(es, bx + 4);
    memorySet16(ds, 0x9292, memoryGet16(ds, 0x9292) + ax);
    memorySet16(ds, 0xa1ac, memoryGet16(ds, 0xa1ac) + 0x0006);
    al = memoryGet(ds, 0x824d);
    al += 0xff;
    memorySet(ds, 0x824d, al);
    ah = 0x00;
    if (ax)
        goto loc_333a;
    al = 0x00;
    memorySet(ds, 0x792a, al);
    goto loc_3341;
loc_333a:
    memorySet(ds, 0x792a, memoryGet(ds, 0x792a) + 1);
    al = memoryGet(ds, 0x792a);
loc_3341:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3343()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3351;
    sub_ca53();
loc_3351:
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    di = memoryGet16(es, bx + 20);
    si = memoryGet16(es, bx + 22);
    ax = memoryGet16(ds, 0x9290);
    ax -= di;
    cl = 0x04;
    ax = sar(ax, cl);
    ax--;
    memorySet16(ds, 0x9d36, ax);
    ax = memoryGet16(ds, 0x9292);
    ax -= si;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet16(ds, 0x9d38, ax);
    if ((short)memoryGet16(ds, 0x9d36) >= (short)0x0000)
        goto loc_3387;
    memorySet16(ds, 0x9d36, 0x0000);
    goto loc_3394;
loc_3387:
    if ((short)memoryGet16(ds, 0x9d36) <= (short)0x0012)
        goto loc_3394;
    memorySet16(ds, 0x9d36, 0x0012);
loc_3394:
    if ((short)memoryGet16(ds, 0x9d38) >= (short)0x0000)
        goto loc_33a3;
    memorySet16(ds, 0x9d38, 0x0000);
    goto loc_33b0;
loc_33a3:
    if ((short)memoryGet16(ds, 0x9d38) <= (short)0x0016)
        goto loc_33b0;
    memorySet16(ds, 0x9d38, 0x0016);
loc_33b0:
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_33b4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_33c4;
    sub_ca53();
loc_33c4:
    memorySet(ds, 0x856c, 0x00);
    cl = 0x00;
    goto loc_3464;
loc_33ce:
    al = memoryGet(ds, 0x856c);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19570);
    dx = memoryGet16(ds, bx + 19568);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    if (memoryGet(es, bx) == 0x00)
        goto loc_345e;
    ax = memoryGet16(es, bx + 4);
    dx = memoryGet16(es, bx + 2);
    memorySet16(ds, 0xa0be, dx);
    memorySet16(ds, 0xa0c0, ax);
    bx = memoryGet16(ds, 0xa0be);
    es = memoryGet16(ds, 0xa0be + 2);
    al = memoryGet(es, bx);
    memorySet(ds, 0x8578, al);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    memorySet16(es, bx + 2, memoryGet16(es, bx + 2) + 1);
    memorySet(es, bx + 6, al);
    if (memoryGet(ds, 0x8578) != 0xff)
        goto loc_3421;
    memorySet(es, bx, 0x00);
    goto loc_345e;
loc_3421:
    if (memoryGet(ds, 0x8578) == 0x00)
        goto loc_345e;
    al = memoryGet(ds, 0x8578);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 15724);
    dx = memoryGet16(ds, bx + 15722);
    memorySet16(ss, bp - 4, dx);
    memorySet16(ss, bp - 2, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    push(es);
    si = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    ax = memoryGet16(es, si);
    es = pop();
    memorySet16(es, bx + 8, ax);
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    ax = memoryGet16(es, bx + 2);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    memorySet16(es, bx + 10, ax);
loc_345e:
    memorySet(ds, 0x856c, memoryGet(ds, 0x856c) + 1);
    cl++;
loc_3464:
    if (cl >= 0x03)
        goto loc_346c;
    goto loc_33ce;
loc_346c:
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3471()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3481;
    sub_ca53();
loc_3481:
    memorySet(ds, 0x8566, 0x00);
    cl = 0x00;
    goto loc_3521;
loc_348b:
    al = memoryGet(ds, 0x8566);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19646);
    dx = memoryGet16(ds, bx + 19644);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    if (memoryGet(es, bx) == 0x00)
        goto loc_351b;
    ax = memoryGet16(es, bx + 4);
    dx = memoryGet16(es, bx + 2);
    memorySet16(ds, 0xa0c2, dx);
    memorySet16(ds, 0xa0c4, ax);
    bx = memoryGet16(ds, 0xa0c2);
    es = memoryGet16(ds, 0xa0c2 + 2);
    al = memoryGet(es, bx);
    memorySet(ds, 0x8579, al);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    memorySet16(es, bx + 2, memoryGet16(es, bx + 2) + 1);
    memorySet(es, bx + 6, al);
    if (memoryGet(ds, 0x8579) != 0xff)
        goto loc_34de;
    memorySet(es, bx, 0x00);
    goto loc_351b;
loc_34de:
    if (memoryGet(ds, 0x8579) == 0x00)
        goto loc_351b;
    al = memoryGet(ds, 0x8579);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 16552);
    dx = memoryGet16(ds, bx + 16550);
    memorySet16(ss, bp - 4, dx);
    memorySet16(ss, bp - 2, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    push(es);
    si = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    ax = memoryGet16(es, si);
    es = pop();
    memorySet16(es, bx + 8, ax);
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    ax = memoryGet16(es, bx + 2);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    memorySet16(es, bx + 10, ax);
loc_351b:
    memorySet(ds, 0x8566, memoryGet(ds, 0x8566) + 1);
    cl++;
loc_3521:
    if (cl >= 0x04)
        goto loc_3529;
    goto loc_348b;
loc_3529:
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_352e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_353f;
    sub_ca53();
loc_353f:
    memorySet(ss, bp - 2, 0x00);
loc_3543:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19570);
    dx = memoryGet16(ds, bx + 19568);
    memorySet16(ss, bp - 12, dx);
    memorySet16(ss, bp - 10, ax);
    bx = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    al = memoryGet(es, bx);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) != 0x00)
        goto loc_356e;
    goto loc_3685;
loc_356e:
    if (memoryGet(ss, bp - 1) != 0xff)
        goto loc_3577;
    goto loc_3685;
loc_3577:
    al = memoryGet(es, bx + 1);
    memorySet(ss, bp - 3, al);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    di = memoryGet16(ds, bx + 12990);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    si = memoryGet16(ds, bx + 12992);
    bx = memoryGet16(ds, 0x08d4);
    es = memoryGet16(ds, 0x08d4 + 2);
    memorySet16(es, bx + 28, 0x0000);
    if (!(memoryGet(ss, bp - 3) & 0x01))
        goto loc_35b4;
    ax = memoryGet16(es, bx + 28);
    ax |= 0x0600;
    memorySet16(es, bx + 28, ax);
loc_35b4:
    bx = memoryGet16(ds, 0x08d4);
    es = memoryGet16(ds, 0x08d4 + 2);
    ax = di;
    memorySet16(es, bx + 20, ax);
    memorySet16(es, bx + 6, ax);
    ax = si;
    memorySet16(es, bx + 22, ax);
    memorySet16(es, bx + 8, ax);
    push(memoryGet16(ds, 0x08d6));
    push(memoryGet16(ds, 0x08d4));
    sub_9f8c();
    sp += 0x0004;
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 244);
    memorySet16(ss, bp - 6, ax);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 246);
    memorySet16(ss, bp - 8, ax);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ax = memoryGet16(ss, bp - 6);
    memorySet16(es, bx, ax);
    bx = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    ax = memoryGet16(ss, bp - 8);
    ax += memoryGet16(es, bx + 8);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    bx = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    ax = memoryGet16(es, bx + 10);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 4, ax);
    bx = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    if (memoryGet16(es, bx + 10) & 0x0200)
        goto loc_363f;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_363f:
    bx = memoryGet16(ds, 0x08e0);
    es = memoryGet16(ds, 0x08e0 + 2);
    memorySet16(es, bx + 6, di);
    memorySet16(es, bx + 8, si);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    dx = 0x0180;
    imul(dx);
    ax += 0x79be;
    memorySet16(es, bx + 16, ax);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 28, 0x0000);
    if (!(memoryGet(ss, bp - 3) & 0x01))
        goto loc_3677;
    ax = memoryGet16(es, bx + 28);
    ax |= 0x0200;
    memorySet16(es, bx + 28, ax);
loc_3677:
    push(memoryGet16(ds, 0x08e2));
    push(memoryGet16(ds, 0x08e0));
    sub_b288();
    sp += 0x0004;
loc_3685:
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
    if (memoryGet(ss, bp - 1) == 0xff)
        goto loc_3691;
    goto loc_3543;
loc_3691:
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3697()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_36a8;
    sub_ca53();
loc_36a8:
    memorySet(ss, bp - 2, 0x00);
loc_36ac:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19646);
    dx = memoryGet16(ds, bx + 19644);
    memorySet16(ss, bp - 12, dx);
    memorySet16(ss, bp - 10, ax);
    bx = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    al = memoryGet(es, bx);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) != 0x00)
        goto loc_36d7;
    goto loc_385f;
loc_36d7:
    if (memoryGet(ss, bp - 1) != 0xff)
        goto loc_36e0;
    goto loc_385f;
loc_36e0:
    al = memoryGet(es, bx + 1);
    memorySet(ss, bp - 3, al);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    di = memoryGet16(ds, bx + 13374);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    si = memoryGet16(ds, bx + 13376);
    bx = memoryGet16(ds, 0x08c8);
    es = memoryGet16(ds, 0x08c8 + 2);
    memorySet16(es, bx + 6, di);
    memorySet16(es, bx + 8, si);
    push(memoryGet16(ds, 0x08ca));
    push(memoryGet16(ds, 0x08c8));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x08cc);
    es = memoryGet16(ds, 0x08cc + 2);
    memorySet16(es, bx + 10, 0x0001);
    ax = 0;
    memorySet16(es, bx + 22, ax);
    memorySet16(es, bx + 20, ax);
    memorySet16(es, bx + 28, 0x0004);
    if (!(memoryGet(ss, bp - 3) & 0x01))
        goto loc_3760;
    memorySet16(es, bx + 2, 0x9fba);
    memorySet16(es, bx + 4, ds);
    push(memoryGet16(ds, 0x08ce));
    push(memoryGet16(ds, 0x08cc));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x08cc);
    es = memoryGet16(ds, 0x08cc + 2);
    memorySet16(es, bx + 2, 0x9eba);
    goto loc_3786;
loc_3760:
    bx = memoryGet16(ds, 0x08cc);
    es = memoryGet16(ds, 0x08cc + 2);
    memorySet16(es, bx + 2, 0x9eba);
    memorySet16(es, bx + 4, ds);
    push(memoryGet16(ds, 0x08ce));
    push(memoryGet16(ds, 0x08cc));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x08cc);
    es = memoryGet16(ds, 0x08cc + 2);
    memorySet16(es, bx + 2, 0x9fba);
loc_3786:
    memorySet16(es, bx + 4, ds);
    bx = memoryGet16(ds, 0x08cc);
    es = memoryGet16(ds, 0x08cc + 2);
    memorySet16(es, bx + 20, di);
    memorySet16(es, bx + 22, si);
    push(memoryGet16(ds, 0x08ce));
    push(memoryGet16(ds, 0x08cc));
    sub_9f8c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x08cc);
    es = memoryGet16(ds, 0x08cc + 2);
    memorySet16(es, bx + 2, 0x8888);
    memorySet16(es, bx + 4, ds);
    memorySet16(es, bx + 10, 0x0003);
    memorySet16(es, bx + 28, 0x0003);
    push(memoryGet16(ds, 0x08ce));
    push(memoryGet16(ds, 0x08cc));
    sub_9f8c();
    sp += 0x0004;
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 1012);
    memorySet16(ss, bp - 6, ax);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 1014);
    memorySet16(ss, bp - 8, ax);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ax = memoryGet16(ss, bp - 6);
    memorySet16(es, bx, ax);
    bx = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    ax = memoryGet16(ss, bp - 8);
    ax += memoryGet16(es, bx + 8);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    bx = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    if (memoryGet16(es, bx + 10) & 0x0200)
        goto loc_3831;
    ax = memoryGet16(es, bx + 10);
    ax += 0x00f1;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 4, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_3831:
    bx = memoryGet16(ds, 0x08d0);
    es = memoryGet16(ds, 0x08d0 + 2);
    memorySet16(es, bx + 6, di);
    memorySet16(es, bx + 8, si);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    cl = 0x08;
    ax <<= cl;
    ax += 0x7e3e;
    memorySet16(es, bx + 16, ax);
    memorySet16(es, bx + 18, ds);
    push(memoryGet16(ds, 0x08d2));
    push(memoryGet16(ds, 0x08d0));
    sub_b288();
    sp += 0x0004;
loc_385f:
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
    if (memoryGet(ss, bp - 1) == 0xff)
        goto loc_386b;
    goto loc_36ac;
loc_386b:
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3871()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_387d;
    sub_ca53();
loc_387d:
    if (memoryGet(ds, 0x8571) == 0xff)
        goto loc_38b2;
    bx = memoryGet16(ds, 0x08e8);
    es = memoryGet16(ds, 0x08e8 + 2);
    ax = memoryGet16(ds, 0x928e);
    memorySet16(es, bx + 20, ax);
    ax = memoryGet16(ds, 0x9b94);
    memorySet16(es, bx + 22, ax);
    ax = memoryGet16(ds, 0x9d34);
    memorySet16(es, bx + 30, ax);
    ax = memoryGet16(ds, 0x9d32);
    memorySet16(es, bx + 32, ax);
    push(memoryGet16(ds, 0x08ea));
    push(memoryGet16(ds, 0x08e8));
    sub_9f8c();
    sp += 0x0004;
loc_38b2:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_38b4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_38c0;
    sub_ca53();
loc_38c0:
    bx = memoryGet16(ds, 0x08c4);
    es = memoryGet16(ds, 0x08c4 + 2);
    ax = memoryGet16(ds, 0x8882);
    memorySet16(es, bx + 20, ax);
    ax = memoryGet16(ds, 0x8e88);
    memorySet16(es, bx + 22, ax);
    ax = memoryGet16(ds, 0x9ba4);
    memorySet16(es, bx + 30, ax);
    ax = memoryGet16(ds, 0x9b9c);
    memorySet16(es, bx + 32, ax);
    push(memoryGet16(ds, 0x08c6));
    push(memoryGet16(ds, 0x08c4));
    sub_9f8c();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_38f0()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_38fc;
    sub_ca53();
loc_38fc:
    if (memoryGet(ds, 0xa1a8) == 0x00)
        goto loc_3935;
    memorySet(ds, 0xa1a8, memoryGet(ds, 0xa1a8) - 1);
    bx = memoryGet16(ds, 0x08e4);
    es = memoryGet16(ds, 0x08e4 + 2);
    ax = memoryGet16(ds, 0x9b9a);
    memorySet16(es, bx + 6, ax);
    ax = memoryGet16(ds, 0x9ba2);
    memorySet16(es, bx + 8, ax);
    ax = memoryGet16(ds, 0x9b9a);
    memorySet16(es, bx + 20, ax);
    ax = memoryGet16(ds, 0x9ba2);
    memorySet16(es, bx + 22, ax);
    push(memoryGet16(ds, 0x08e6));
    push(memoryGet16(ds, 0x08e4));
    sub_9f8c();
    sp += 0x0004;
loc_3935:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3937()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3946;
    sub_ca53();
loc_3946:
    memorySet(ss, bp - 2, 0x00);
loc_394a:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19570);
    dx = memoryGet16(ds, bx + 19568);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(es, bx);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_39eb;
    if (memoryGet(ss, bp - 1) == 0xff)
        goto loc_39eb;
    al = memoryGet(es, bx + 1);
    memorySet(ss, bp - 3, al);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    dx = 0x0180;
    imul(dx);
    ax += 0x79be;
    bx = memoryGet16(ds, 0x08c0);
    es = memoryGet16(ds, 0x08c0 + 2);
    memorySet16(es, bx + 2, ax);
    memorySet16(es, bx + 4, ds);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 12990);
    bx = memoryGet16(ds, 0x08c0);
    memorySet16(es, bx + 20, ax);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 12992);
    bx = memoryGet16(ds, 0x08c0);
    memorySet16(es, bx + 22, ax);
    memorySet16(es, bx + 28, 0x0000);
    if (!(memoryGet(ss, bp - 3) & 0x01))
        goto loc_39dd;
    ax = memoryGet16(es, bx + 28);
    ax |= 0x0400;
    memorySet16(es, bx + 28, ax);
loc_39dd:
    push(memoryGet16(ds, 0x08c2));
    push(memoryGet16(ds, 0x08c0));
    sub_9f8c();
    sp += 0x0004;
loc_39eb:
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
    if (memoryGet(ss, bp - 1) == 0xff)
        goto loc_39f7;
    goto loc_394a;
loc_39f7:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_39fb()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3a0a;
    sub_ca53();
loc_3a0a:
    memorySet(ss, bp - 2, 0x00);
loc_3a0e:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19646);
    dx = memoryGet16(ds, bx + 19644);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(es, bx);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_3a97;
    if (memoryGet(ss, bp - 1) == 0xff)
        goto loc_3a97;
    al = memoryGet(es, bx + 1);
    memorySet(ss, bp - 3, al);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    cl = 0x08;
    ax <<= cl;
    ax += 0x7e3e;
    bx = memoryGet16(ds, 0x08bc);
    es = memoryGet16(ds, 0x08bc + 2);
    memorySet16(es, bx + 2, ax);
    memorySet16(es, bx + 4, ds);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 13374);
    bx = memoryGet16(ds, 0x08bc);
    memorySet16(es, bx + 20, ax);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 13376);
    bx = memoryGet16(ds, 0x08bc);
    memorySet16(es, bx + 22, ax);
    push(memoryGet16(ds, 0x08be));
    push(memoryGet16(ds, 0x08bc));
    sub_9f8c();
    sp += 0x0004;
loc_3a97:
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
    if (memoryGet(ss, bp - 1) == 0xff)
        goto loc_3aa3;
    goto loc_3a0e;
loc_3aa3:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3aa7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3ab3;
    sub_ca53();
loc_3ab3:
    memorySet16(ds, 0x9ba4, 0x0004);
    if ((short)memoryGet16(ds, 0x857a) <= (short)0x0010)
        goto loc_3aca;
    ax = 0x0014;
    ax -= memoryGet16(ds, 0x857a);
    memorySet16(ds, 0x9ba4, ax);
loc_3aca:
    memorySet16(ds, 0x9b9c, 0x0004);
    if ((short)memoryGet16(ds, 0x857c) <= (short)0x0015)
        goto loc_3ae1;
    ax = 0x0019;
    ax -= memoryGet16(ds, 0x857c);
    memorySet16(ds, 0x9b9c, ax);
loc_3ae1:
    bx = memoryGet16(ds, 0x08b8);
    es = memoryGet16(ds, 0x08b8 + 2);
    ax = memoryGet16(ds, 0x857a);
    memorySet16(es, bx + 6, ax);
    ax = memoryGet16(ds, 0x857c);
    memorySet16(es, bx + 8, ax);
    ax = memoryGet16(ds, 0x9ba4);
    memorySet16(es, bx + 30, ax);
    ax = memoryGet16(ds, 0x9b9c);
    memorySet16(es, bx + 32, ax);
    push(memoryGet16(ds, 0x08ba));
    push(memoryGet16(ds, 0x08b8));
    sub_b288();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3b11()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3b1d;
    sub_ca53();
loc_3b1d:
    if (memoryGet(ds, 0x8571) == 0xff)
        goto loc_3b80;
    memorySet16(ds, 0x9d34, 0x0004);
    if ((short)memoryGet16(ds, 0x8558) <= (short)0x0010)
        goto loc_3b3b;
    ax = 0x0014;
    ax -= memoryGet16(ds, 0x8558);
    memorySet16(ds, 0x9d34, ax);
loc_3b3b:
    memorySet16(ds, 0x9d32, 0x0004);
    if ((short)memoryGet16(ds, 0x855a) <= (short)0x0015)
        goto loc_3b52;
    ax = 0x0019;
    ax -= memoryGet16(ds, 0x855a);
    memorySet16(ds, 0x9d32, ax);
loc_3b52:
    bx = memoryGet16(ds, 0x08ec);
    es = memoryGet16(ds, 0x08ec + 2);
    ax = memoryGet16(ds, 0x8558);
    memorySet16(es, bx + 6, ax);
    ax = memoryGet16(ds, 0x855a);
    memorySet16(es, bx + 8, ax);
    ax = memoryGet16(ds, 0x9d34);
    memorySet16(es, bx + 30, ax);
    ax = memoryGet16(ds, 0x9d32);
    memorySet16(es, bx + 32, ax);
    push(memoryGet16(ds, 0x08ee));
    push(memoryGet16(ds, 0x08ec));
    sub_b288();
    sp += 0x0004;
loc_3b80:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3b82()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3b8e;
    sub_ca53();
loc_3b8e:
    if (memoryGet16(ds, 0x824a) == 0x0064)
        goto loc_3bb8;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ax = memoryGet16(ds, 0x824a);
    memorySet16(es, bx + 4, ax);
    ax = memoryGet16(ds, 0x9290);
    memorySet16(es, bx, ax);
    ax = memoryGet16(ds, 0x9292);
    memorySet16(es, bx + 2, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_3bb8:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3bba()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3bc6;
    sub_ca53();
loc_3bc6:
    if (memoryGet(ds, 0x8571) == 0xff)
        goto loc_3bf4;
    bx = memoryGet16(ds, 0x9b9e);
    es = memoryGet16(ds, 0x9b9e + 2);
    ax = memoryGet16(ds, 0xa0de);
    ax += memoryGet16(ds, 0x8560);
    memorySet16(es, bx + 4, ax);
    ax = memoryGet16(ds, 0x79ba);
    memorySet16(es, bx, ax);
    ax = memoryGet16(ds, 0x79bc);
    memorySet16(es, bx + 2, ax);
    push(ds);
    ax = 0x795a;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_3bf4:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3bf6()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3c02;
    sub_ca53();
loc_3c02:
    al = 0x3b;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c15;
    memorySet(ds, 0x854f, 0x00);
    goto loc_3c8b;
loc_3c15:
    al = 0x3c;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c28;
    memorySet(ds, 0x854f, 0x88);
    goto loc_3c8b;
loc_3c28:
    al = 0x3d;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c3b;
    memorySet(ds, 0x854f, 0xaa);
    goto loc_3c8b;
loc_3c3b:
    al = 0x3e;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c4e;
    memorySet(ds, 0x854f, 0xee);
    goto loc_3c8b;
loc_3c4e:
    al = 0x3f;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c61;
    memorySet(ds, 0x854f, 0xff);
    goto loc_3c8b;
loc_3c61:
    al = 0x01;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c72;
    sub_41cc();
    goto loc_3c8b;
loc_3c72:
    al = 0x44;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_3c8b;
    memorySet(ds, 0x928d, 0x01);
    al = 0x00;
    memorySet(ds, 0x9d30, al);
    memorySet(ds, 0x856d, al);
loc_3c8b:
    if (memoryGet(ds, 0xa1aa) == 0x00)
        goto loc_3c97;
    sub_415d();
    goto loc_3cac;
loc_3c97:
    sub_423f();
    sub_3cae();
    if (memoryGet(ds, 0x824d) == 0x00)
        goto loc_3ca9;
    sub_425e();
    goto loc_3cac;
loc_3ca9:
    sub_3cd2();
loc_3cac:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3cae()
{
//    syncKeyb();
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3cbc;
    sub_ca53();
loc_3cbc:
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    memorySet(ss, bp - 1, al);
    if (!al)
        goto loc_3cce;
    memorySet(ds, 0x8244, al);
loc_3cce:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3cd2()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3cde;
    sub_ca53();
loc_3cde:
    memorySet(ds, 0x7923, 0x00);
    al = memoryGet(ds, 0x792c);
    memorySet(ds, 0x8552, al);
    if (memoryGet(ds, 0xa0ce) != 0x00)
        goto loc_3cf9;
    al = memoryGet(ds, 0xa1a7);
    ah = 0x00;
    if (ax)
        goto loc_3d08;
loc_3cf9:
    al = memoryGet(ds, 0x792c);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    callIndirect(cs*16+memoryGet16(ds, bx + 1994));
    goto loc_3d0b;
loc_3d08:
    sub_46ae();
loc_3d0b:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3d0d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3d19;
    sub_ca53();
loc_3d19:
    al = 0x01;
    memorySet(ds, 0x9d30, al);
    memorySet(ds, 0xa1a9, al);
    sub_5958();
    bx = memoryGet16(ds, 0x9baa);
    es = memoryGet16(ds, 0x9baa + 2);
    memorySet(es, bx, 0x01);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3d2e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3d3a;
    sub_ca53();
loc_3d3a:
    if (memoryGet(ds, 0x8551) != 0x08)
        goto loc_3d59;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_3d4c;
    al = 0x0f;
    goto loc_3d4e;
loc_3d4c:
    al = 0x2b;
loc_3d4e:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    sub_40b7();
    goto loc_3d5e;
loc_3d59:
    memorySet(ds, 0x792c, 0x24);
loc_3d5e:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3d60()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3d6c;
    sub_ca53();
loc_3d6c:
    if (memoryGet(ds, 0x8551) != 0x08)
        goto loc_3d8b;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_3d7e;
    al = 0x0f;
    goto loc_3d80;
loc_3d7e:
    al = 0x2b;
loc_3d80:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    sub_4008();
    goto loc_3d90;
loc_3d8b:
    memorySet(ds, 0x792c, 0x23);
loc_3d90:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3d92()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3da1;
    sub_ca53();
loc_3da1:
    memorySet(ss, bp - 1, 0x0b);
    memorySet(ss, bp - 2, 0x05);
    memorySet16(ss, bp - 6, 0x1ca4);
    memorySet16(ss, bp - 4, ds);
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_3dcf;
    sub_3dd3();
loc_3dcf:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3dd3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3ddf;
    sub_ca53();
loc_3ddf:
    memorySet(ds, 0x792c, 0x01);
    memorySet16(ds, 0xa1ac, 0x140c);
    memorySet16(ds, 0xa1ae, ds);
    memorySet(ds, 0x824d, 0x04);
    al = 0x09;
    memorySet(ds, 0x9bae, al);
    memorySet(ds, 0x792a, al);
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x8570, al);
    al = 0x16;
    push(ax);
    sub_8959();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3e0e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3e1d;
    sub_ca53();
loc_3e1d:
    memorySet(ss, bp - 1, 0x0b);
    memorySet(ss, bp - 2, 0x05);
    memorySet16(ss, bp - 6, 0x1cba);
    memorySet16(ss, bp - 4, ds);
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_3e4b;
    sub_3e4f();
loc_3e4b:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3e4f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3e5b;
    sub_ca53();
loc_3e5b:
    memorySet(ds, 0x792c, 0x02);
    memorySet16(ds, 0xa1ac, 0x1460);
    memorySet16(ds, 0xa1ae, ds);
    memorySet(ds, 0x824d, 0x04);
    memorySet(ds, 0x792a, 0x09);
    memorySet(ds, 0x9bae, 0x00);
    al = memoryGet(ds, 0x856e);
    al += 0xff;
    memorySet(ds, 0x8570, al);
    al = 0x16;
    push(ax);
    sub_8959();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3e8e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3e9a;
    sub_ca53();
loc_3e9a:
    memorySet(ds, 0x8551, 0x00);
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_3eaa;
    al = 0x02;
    goto loc_3eac;
loc_3eaa:
    al = 0x26;
loc_3eac:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_3ec4;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x38;
    goto loc_3f42;
loc_3ec4:
    al = memoryGet(ds, 0x856e);
    al += 0xff;
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryGet(ds, bx + 17238) != 0x38)
        goto loc_3ee4;
    al = 0x38;
    goto loc_3f42;
loc_3ee4:
    al = memoryGet(ds, 0x856e);
    al += 0xff;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_3efa;
    al = 0x3a;
    goto loc_3f42;
loc_3efa:
    if (memoryGet(ds, 0x855e) != 0x01)
        goto loc_3f0a;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x34;
    goto loc_3f42;
loc_3f0a:
    al = memoryGet(ds, 0x856e);
    al += 0xfe;
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryGet(ds, bx + 17174) != 0x34)
        goto loc_3f2a;
    al = 0x34;
    goto loc_3f42;
loc_3f2a:
    al = memoryGet(ds, 0x856e);
    al += 0xfe;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_3f40;
    al = 0x36;
    goto loc_3f42;
loc_3f40:
    al = 0x1a;
loc_3f42:
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_3f4d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_3f59;
    sub_ca53();
loc_3f59:
    memorySet(ds, 0x8551, 0x00);
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_3f69;
    al = 0x02;
    goto loc_3f6b;
loc_3f69:
    al = 0x26;
loc_3f6b:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    if (memoryGet(ds, 0x855e) != 0x07)
        goto loc_3f81;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x39;
    goto loc_3ffd;
loc_3f81:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryGet(ds, bx + 17270) != 0x39)
        goto loc_3f9f;
    al = 0x39;
    goto loc_3ffd;
loc_3f9f:
    al = memoryGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_3fb5;
    al = 0x3b;
    goto loc_3ffd;
loc_3fb5:
    if (memoryGet(ds, 0x855e) != 0x06)
        goto loc_3fc5;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x35;
    goto loc_3ffd;
loc_3fc5:
    al = memoryGet(ds, 0x856e);
    al++;
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    if (memoryGet(ds, bx + 17206) != 0x35)
        goto loc_3fe5;
    al = 0x35;
    goto loc_3ffd;
loc_3fe5:
    al = memoryGet(ds, 0x856e);
    al += 0x02;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_3ffb;
    al = 0x37;
    goto loc_3ffd;
loc_3ffb:
    al = 0x1b;
loc_3ffd:
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4008()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4016;
    sub_ca53();
loc_4016:
    memorySet(ds, 0x8551, 0x00);
    if (!(memoryGet(ds, 0x8244) & 0x12))
        goto loc_403f;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_402d;
    al = 0x15;
    goto loc_402f;
loc_402d:
    al = 0x2a;
loc_402f:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x32;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_4084;
loc_403f:
    al = memoryGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_4057;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x27;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_4084;
loc_4057:
    al = memoryGet(ds, 0x856e);
    al += 0xff;
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 17110);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x25)
        goto loc_4081;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_4084;
loc_4081:
    sub_408b();
loc_4084:
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_408b()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4097;
    sub_ca53();
loc_4097:
    al = memoryGet(ds, 0x856e);
    al += 0xff;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_40ad;
    al = 0x29;
    goto loc_40af;
loc_40ad:
    al = 0x25;
loc_40af:
    push(ax);
    sub_6133();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_40b7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_40c5;
    sub_ca53();
loc_40c5:
    if (!(memoryGet(ds, 0x8244) & 0x12))
        goto loc_40e9;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_40d7;
    al = 0x15;
    goto loc_40d9;
loc_40d7:
    al = 0x2a;
loc_40d9:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x33;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_412a;
loc_40e9:
    if (memoryGet(ds, 0x855e) != 0x07)
        goto loc_40ff;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x28;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_412a;
loc_40ff:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 17142);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x26)
        goto loc_4127;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_412a;
loc_4127:
    sub_4131();
loc_412a:
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4131()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_413d;
    sub_ca53();
loc_413d:
    al = memoryGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_4153;
    al = 0x2a;
    goto loc_4155;
loc_4153:
    al = 0x26;
loc_4155:
    push(ax);
    sub_6133();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_415d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4169;
    sub_ca53();
loc_4169:
    memorySet(ds, 0xa0ce, 0x01);
    al = 0x00;
    memorySet(ds, 0x792a, al);
    memorySet(ds, 0xa1aa, al);
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4180()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_418c;
    sub_ca53();
loc_418c:
    sub_41cc();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4191()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_419d;
    sub_ca53();
loc_419d:
    sub_41cc();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_41a2()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_41ae;
    sub_ca53();
loc_41ae:
    al = memoryGet(ds, 0xa0ce);
    al++;
    memorySet(ds, 0xa0ce, al);
    if (al != 0x03)
        goto loc_41bf;
    sub_41cc();
    goto loc_41ca;
loc_41bf:
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
loc_41ca:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_41cc()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_41d9;
    sub_ca53();
loc_41d9:
    memorySet(ds, 0xa0ce, 0x00);
    si = 0x03e8;
    goto loc_41e7;
loc_41e3:
    sub_423f();
    si--;
loc_41e7:
    if (si)
        goto loc_41e3;
    memorySet(ds, 0x856d, 0x01);
    al = memoryGet(ds, 0x791a);
    ah = 0x00;
    if (ax)
        goto loc_4200;
    al = 0xff;
    memorySet(ds, 0x928d, al);
    goto loc_4207;
loc_4200:
    memorySet(ds, 0x791a, memoryGet(ds, 0x791a) - 1);
    al = memoryGet(ds, 0x791a);
loc_4207:
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_420a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4216;
    sub_ca53();
loc_4216:
    if (memoryGet(ds, 0xa1b1) == 0x00)
        goto loc_423d;
    if (memoryGet(ds, 0x8550) == 0x09)
        goto loc_422a;
    memorySet(ds, 0x8550, memoryGet(ds, 0x8550) + 1);
    goto loc_423d;
loc_422a:
    memorySet(ds, 0x8550, 0x00);
    al = memoryGet(ds, 0x8572);
    memorySet(ds, 0x856f, al);
    al = 0x5a;
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_423d:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_423f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_424b;
    sub_ca53();
loc_424b:
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ds, 0x7924, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_425e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_426a;
    sub_ca53();
loc_426a:
    al = memoryGet(ds, 0x792c);
    ah = 0x00;
    dx = 0x0022;
    imul(dx);
    dl = memoryGet(ds, 0x792a);
    dh = 0x00;
    dx <<= 1;
    ax += dx;
    bx = ax;
    callIndirect(cs*16+memoryGet16(ds, bx + 17344));
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4286()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4292;
    sub_ca53();
loc_4292:
    if (!(memoryGet(ds, 0x8244) & 0x04))
        goto loc_429e;
    sub_4504();
    goto loc_42f1;
loc_429e:
    if (!(memoryGet(ds, 0x8244) & 0x08))
        goto loc_42aa;
    sub_4571();
    goto loc_42f1;
loc_42aa:
    if (memoryGet(ds, 0x856e) < 0x08)
        goto loc_42c9;
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    es = memoryGet16(ds, 0xa0da);
    ax += memoryGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryGet(es, bx - 8) != 0x0e)
        goto loc_42c9;
    goto loc_42ee;
loc_42c9:
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_42ee;
    sub_6617();
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_42e4;
    al = 0x14;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    goto loc_42f1;
loc_42e4:
    al = 0x2a;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    goto loc_42f1;
loc_42ee:
    sub_46ae();
loc_42f1:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_42f3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4302;
    sub_ca53();
loc_4302:
    memorySet(ss, bp - 1, 0x21);
    memorySet(ss, bp - 2, 0x04);
    memorySet16(ss, bp - 6, 0x14ea);
    memorySet16(ss, bp - 4, ds);
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryGet(ds, 0x8244) & 0x04))
        goto loc_4332;
    sub_4504();
    goto loc_433c;
loc_4332:
    if (!(memoryGet(ds, 0x8244) & 0x08))
        goto loc_433c;
    sub_4571();
loc_433c:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4340()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_434c;
    sub_ca53();
loc_434c:
    memorySet(ds, 0x824c, 0x08);
    al = 0x0b;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_435e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_436d;
    sub_ca53();
loc_436d:
    memorySet(ss, bp - 1, 0x25);
    memorySet(ss, bp - 2, 0x06);
    memorySet16(ss, bp - 6, 0x1664);
    memorySet16(ss, bp - 4, ds);
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_43a3;
    al = 0x0c;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
loc_43a3:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_43a7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_43b3;
    sub_ca53();
loc_43b3:
    if (memoryGet(ds, 0x7924) != 0x00)
        goto loc_43d0;
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    es = memoryGet16(ds, 0xa0da);
    ax += memoryGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryGet(es, bx + 8) != 0x0b)
        goto loc_43d5;
loc_43d0:
    sub_43da();
    goto loc_43d8;
loc_43d5:
    sub_47b0();
loc_43d8:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_43da()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_43e6;
    sub_ca53();
loc_43e6:
    if (!(memoryGet(ds, 0x8244) & 0x04))
        goto loc_43f2;
    sub_4504();
    goto loc_440d;
loc_43f2:
    if (!(memoryGet(ds, 0x8244) & 0x08))
        goto loc_43fe;
    sub_4571();
    goto loc_440d;
loc_43fe:
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_440a;
    sub_440f();
    goto loc_440d;
loc_440a:
    sub_46ae();
loc_440d:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_440f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_441b;
    sub_ca53();
loc_441b:
    if (memoryGet(ds, 0x7924) != 0x0f)
        goto loc_4427;
    sub_66d2();
    goto loc_443a;
loc_4427:
    if (memoryGet(ds, 0x7924) != 0x12)
        goto loc_4430;
    goto loc_4437;
loc_4430:
    if (memoryGet(ds, 0x7924) != 0x1f)
        goto loc_443a;
loc_4437:
    sub_4180();
loc_443a:
    sub_84cb();
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_4448;
    al = 0x14;
    goto loc_444a;
loc_4448:
    al = 0x09;
loc_444a:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    memorySet(ds, 0x824c, memoryGet(ds, 0x824c) + 1);
    if (memoryGet(ds, 0x824c) != 0x09)
        goto loc_4470;
    al = memoryGet(ds, 0x856e);
    al += 0xf8;
    memorySet(ds, 0x856f, al);
    al = 0x24;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    memorySet(ds, 0x824c, 0x00);
loc_4470:
    al = 0x0d;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_447d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_448b;
    sub_ca53();
loc_448b:
    memorySet(ss, bp - 2, 0x00);
    al = memoryGet(ds, 0x856e);
    memorySet(ss, bp - 1, al);
    goto loc_44f7;
loc_4497:
    al = memoryGet(ss, bp - 1);
    al++;
    memorySet(ss, bp - 1, al);
    if (al != 0x30)
        goto loc_44a7;
    memorySet(ss, bp - 1, 0x00);
loc_44a7:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryGet(es, bx) != 0x0f)
        goto loc_44f7;
    al = memoryGet(ss, bp - 1);
    memorySet(ds, 0x856f, al);
    memorySet(ds, 0x856e, al);
    sub_67d6();
    ax = memoryGet16(ds, 0x9292);
    ax += 0x000d;
    memorySet16(ds, 0x9292, ax);
    al = 0x27;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_44e0;
    al = 0x03;
    goto loc_44e2;
loc_44e0:
    al = 0x28;
loc_44e2:
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
    memorySet(ss, bp - 2, 0x01);
loc_44f7:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    if (!ax)
        goto loc_4497;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4504()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4512;
    sub_ca53();
loc_4512:
    memorySet(ds, 0x8551, 0x00);
    sub_828e();
    al = memoryGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_452c;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x12;
    goto loc_4564;
loc_452c:
    al = memoryGet(ds, 0x856e);
    al += 0xff;
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 16982);
    memorySet(ss, bp - 1, al);
    if (al == 0x01)
        goto loc_454e;
    goto loc_4564;
loc_454e:
    al = memoryGet(ds, 0x8570);
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_4562;
    al = 0x16;
    goto loc_4564;
loc_4562:
    al = 0x01;
loc_4564:
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4571()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_457f;
    sub_ca53();
loc_457f:
    memorySet(ds, 0x8551, 0x00);
    sub_828e();
    if (memoryGet(ds, 0x855e) != 0x07)
        goto loc_4597;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x13;
    goto loc_45cf;
loc_4597:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 17014);
    memorySet(ss, bp - 1, al);
    if (al == 0x02)
        goto loc_45b7;
    goto loc_45cf;
loc_45b7:
    al = memoryGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_45cd;
    al = 0x17;
    goto loc_45cf;
loc_45cd:
    al = 0x02;
loc_45cf:
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_45dc()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_45ea;
    sub_ca53();
loc_45ea:
    memorySet(ds, 0x8551, 0x00);
    al = memoryGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_4601;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x14;
    goto loc_4639;
loc_4601:
    al = memoryGet(ds, 0x856e);
    al += 0xff;
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 17046);
    memorySet(ss, bp - 1, al);
    if (al == 0x08)
        goto loc_4623;
    goto loc_4639;
loc_4623:
    al = memoryGet(ds, 0x8570);
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_4637;
    al = 0x18;
    goto loc_4639;
loc_4637:
    al = 0x08;
loc_4639:
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4646()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4654;
    sub_ca53();
loc_4654:
    memorySet(ds, 0x8551, 0x00);
    if (memoryGet(ds, 0x855e) != 0x07)
        goto loc_4669;
    memorySet(ds, 0x8551, 0x1f);
    al = 0x15;
    goto loc_46a1;
loc_4669:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x8570, al);
    push(ax);
    sub_8aa4();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 17078);
    memorySet(ss, bp - 1, al);
    if (al == 0x09)
        goto loc_4689;
    goto loc_46a1;
loc_4689:
    al = memoryGet(ds, 0x856e);
    al++;
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7921) != 0x0b)
        goto loc_469f;
    al = 0x19;
    goto loc_46a1;
loc_469f:
    al = 0x09;
loc_46a1:
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_46ae()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_46ba;
    sub_ca53();
loc_46ba:
    al = 0x00;
    memorySet(ds, 0x7923, al);
    memorySet(ds, 0xa1a7, al);
    memorySet(ds, 0x79b9, 0x0b);
    if (memoryGet(ds, 0x7924) != 0x11)
        goto loc_46d8;
    al = 0x2f;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    goto loc_46db;
loc_46d8:
    sub_46e0();
loc_46db:
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_46e0()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_46ef;
    sub_ca53();
loc_46ef:
    if (memoryGet(ds, 0x8552) == 0x03)
        goto loc_4732;
    if (memoryGet(ds, 0x8552) == 0x0d)
        goto loc_4732;
    if (memoryGet(ds, 0x8552) == 0x10)
        goto loc_4732;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_4718;
    al = memoryGet(ds, 0x7922);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 9886);
    goto loc_4723;
loc_4718:
    al = memoryGet(ds, 0x7922);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 9838);
loc_4723:
    memorySet(ss, bp - 4, al);
    if (memoryGet(ss, bp - 4) == 0x00)
        goto loc_4732;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_4732:
    if (memoryGet(ds, 0x856e) >= 0x08)
        goto loc_4741;
    al = 0x06;
    push(ax);
    sub_6133();
    goto loc_47aa;
loc_4741:
    al = memoryGet(ds, 0x856e);
    al += 0xf8;
    memorySet(ds, 0x856f, al);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ss, bp - 1, al);
    memorySet(ds, 0x79b9, al);
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryGet(ds, bx + 1898);
    memorySet(ss, bp - 2, al);
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryGet(ds, bx + 1899);
    memorySet(ss, bp - 3, al);
    al = memoryGet(ss, bp - 2);
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryGet(ds, 0x792c) != 0x0a)
        goto loc_479d;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_4795;
    al = 0x14;
    goto loc_4797;
loc_4795:
    al = 0x09;
loc_4797:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_479d:
    if (memoryGet(ss, bp - 3) == 0x00)
        goto loc_47ac;
    al = memoryGet(ss, bp - 3);
    push(ax);
    sub_887a();
loc_47aa:
    sp++;
    sp++;
loc_47ac:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_47b0()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_47bc;
    sub_ca53();
loc_47bc:
    al = 0x04;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_47c9()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_47d5;
    sub_ca53();
loc_47d5:
    memorySet(ds, 0x824c, 0x08);
    if (memoryGet(ds, 0x79b4) != 0x00)
        goto loc_47e8;
    if (memoryGet(ds, 0x7924) != 0x00)
        goto loc_47fe;
loc_47e8:
    memorySet(ds, 0x79b4, 0x00);
    if (memoryGet(ds, 0x856e) >= 0x28)
        goto loc_47f9;
    sub_47b0();
    goto loc_4833;
loc_47f9:
    sub_61a9();
    goto loc_4833;
loc_47fe:
    if (memoryGet(ds, 0x7924) != 0x20)
        goto loc_4818;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_4810;
    al = 0x03;
    goto loc_4812;
loc_4810:
    al = 0x28;
loc_4812:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_4818:
    if (memoryGet(ds, 0x7924) != 0x16)
        goto loc_4824;
    sub_61d5();
    goto loc_4833;
loc_4824:
    if (memoryGet(ds, 0x7924) != 0x03)
        goto loc_4830;
    sub_650d();
    goto loc_4833;
loc_4830:
    sub_4835();
loc_4833:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4835()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4841;
    sub_ca53();
loc_4841:
    if (!(memoryGet(ds, 0x8244) & 0x04))
        goto loc_484d;
    sub_654d();
    goto loc_4874;
loc_484d:
    if (!(memoryGet(ds, 0x8244) & 0x08))
        goto loc_4859;
    sub_656c();
    goto loc_4874;
loc_4859:
    if (memoryGet(ds, 0x7924) != 0x0a)
        goto loc_4865;
    sub_669b();
    goto loc_4874;
loc_4865:
    if (memoryGet(ds, 0x7924) != 0x0f)
        goto loc_4871;
    sub_66d2();
    goto loc_4874;
loc_4871:
    sub_4876();
loc_4874:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4876()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4882;
    sub_ca53();
loc_4882:
    if (memoryGet(ds, 0x856e) >= 0x08)
        goto loc_488e;
    sub_652e();
    goto loc_48d8;
loc_488e:
    al = memoryGet(ds, 0x856e);
    al += 0xf8;
    memorySet(ds, 0x856f, al);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryGet(es, bx) == 0x0e)
        goto loc_48a9;
    sub_652e();
    goto loc_48d8;
loc_48a9:
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_48b5;
    sub_440f();
    goto loc_48d8;
loc_48b5:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_48c0;
    al = 0x14;
    goto loc_48c2;
loc_48c0:
    al = 0x09;
loc_48c2:
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
loc_48d8:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_48da()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_48ea;
    sub_ca53();
loc_48ea:
    di = 0;
    goto loc_493d;
loc_48ee:
    si = 0;
    goto loc_4932;
loc_48f2:
    ax = 0x0001;
    push(ax);
    push(di);
    push(si);
    sub_2a58();
    sp += 0x0006;
    ax = si;
    dx = 0x0027;
    imul(dx);
    bx = memoryGet16(ds, 0x6bca);
    es = memoryGet16(ds, 0x6bca + 2);
    bx += ax;
    ax = di;
    ax = sar(ax, 1);
    dx = 0x0003;
    imul(dx);
    bx += ax;
    al = memoryGet(es, bx + 32);
    memorySet(ss, bp - 1, al);
    if (!al)
        goto loc_4931;
    ax = 0x0001;
    push(ax);
    push(di);
    push(si);
    al = memoryGet(ss, bp - 1);
    push(ax);
    sub_2960();
    sp += 0x0008;
loc_4931:
    si++;
loc_4932:
    if ((short)si < (short)0x0014)
        goto loc_48f2;
    ax = di;
    ax++;
    ax++;
    di = ax;
loc_493d:
    if ((short)di < (short)0x001a)
        goto loc_48ee;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4948()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4959;
    sub_ca53();
loc_4959:
    memorySet(ds, 0x4c40, 0x00);
    memorySet(ds, 0x4c4c, 0x00);
    memorySet(ds, 0x4c58, 0x00);
    memorySet(ds, 0x4c80, 0x00);
    memorySet(ds, 0x4c8c, 0x00);
    memorySet(ds, 0x4c98, 0x00);
    memorySet(ds, 0x4ca4, 0x00);
    ax = memoryGet16(ds, 0x4c72);
    dx = memoryGet16(ds, 0x4c70);
    memorySet16(ss, bp - 16, dx);
    memorySet16(ss, bp - 14, ax);
    ax = memoryGet16(ds, 0x4cbe);
    dx = memoryGet16(ds, 0x4cbc);
    memorySet16(ss, bp - 20, dx);
    memorySet16(ss, bp - 18, ax);
    bx = memoryGet16(ss, bp - 16);
    es = memoryGet16(ss, bp - 16 + 2);
    al = 0x01;
    memorySet(es, bx, al);
    memorySet(ds, 0x8e8b, al);
    bx = memoryGet16(ss, bp - 20);
    es = memoryGet16(ss, bp - 20 + 2);
    al = 0x01;
    memorySet(es, bx, al);
    memorySet(ds, 0x8e8c, al);
    bx = memoryGet16(ss, bp - 16);
    es = memoryGet16(ss, bp - 16 + 2);
    al = 0x01;
    memorySet(es, bx + 6, al);
    memorySet(ds, 0x8578, al);
    bx = memoryGet16(ss, bp - 20);
    es = memoryGet16(ss, bp - 20 + 2);
    al = 0x01;
    memorySet(es, bx + 6, al);
    memorySet(ds, 0x8579, al);
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    al = memoryGet(es, bx + 144);
    memorySet(ds, 0x856e, al);
    if (memoryGet(ds, 0x856e) == 0x00)
        goto loc_49db;
    memorySet(ds, 0x856e, memoryGet(ds, 0x856e) - 1);
loc_49db:
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    al = memoryGet(es, bx + 145);
    memorySet(ds, 0x8572, al);
    if (memoryGet(ds, 0x8572) == 0x00)
        goto loc_49f2;
    memorySet(ds, 0x8572, memoryGet(ds, 0x8572) - 1);
loc_49f2:
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    al = memoryGet(es, bx + 146);
    memorySet(ds, 0xa0cf, al);
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    al = memoryGet(es, bx + 147);
    al += 0xff;
    memorySet(ds, 0x8571, al);
    al = memoryGet(es, bx + 149);
    memorySet(ds, 0x7920, al);
    al = memoryGet(es, bx + 148);
    memorySet(ds, 0x8562, al);
    al = memoryGet(es, bx + 150);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 9542);
    memorySet16(ds, 0xa0de, ax);
    sub_670c();
    memorySet(ss, bp - 2, 0x00);
    goto loc_4bbd;
loc_4a38:
    memorySet(ss, bp - 1, 0x00);
    goto loc_4bb1;
loc_4a3f:
    al = memoryGet(ss, bp - 2);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    al += memoryGet(ss, bp - 1);
    memorySet(ss, bp - 3, al);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    dl = memoryGet(ss, bp - 1);
    dh = 0x00;
    ax += dx;
    es = memoryGet16(ds, 0xa0da);
    ax += memoryGet16(ds, 0xa0d8);
    bx = ax;
    al = memoryGet(es, bx);
    ah = 0x00;
    si = ax;
    if (!ax)
        goto loc_4abb;
    al = memoryGet(ds, si + 15674);
    ah = 0x00;
    si = ax;
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = memoryGet16(ds, bx + 15724);
    dx = memoryGet16(ds, bx + 15722);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ss, bp - 16);
    es = memoryGet16(ss, bp - 16 + 2);
    al = memoryGet(ss, bp - 3);
    memorySet(es, bx + 1, al);
    push(es);
    di = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    ax = memoryGet16(es, di);
    es = pop();
    memorySet16(es, bx + 8, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    ax = memoryGet16(es, bx + 2);
    bx = memoryGet16(ss, bp - 16);
    es = memoryGet16(ss, bp - 16 + 2);
    memorySet16(es, bx + 10, ax);
    sub_352e();
    sub_3937();
loc_4abb:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    bx += ax;
    al = memoryGet(es, bx + 48);
    ah = 0x00;
    si = ax;
    if (!ax)
        goto loc_4b2b;
    if (memoryGet(ss, bp - 1) == 0x07)
        goto loc_4b2b;
    al = memoryGet(ds, si + 16518);
    ah = 0x00;
    si = ax;
    bx = si;
    bx <<= 1;
    bx <<= 1;
    ax = memoryGet16(ds, bx + 16552);
    dx = memoryGet16(ds, bx + 16550);
    memorySet16(ss, bp - 12, dx);
    memorySet16(ss, bp - 10, ax);
    bx = memoryGet16(ss, bp - 20);
    es = memoryGet16(ss, bp - 20 + 2);
    al = memoryGet(ss, bp - 3);
    memorySet(es, bx + 1, al);
    push(es);
    di = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    ax = memoryGet16(es, di);
    es = pop();
    memorySet16(es, bx + 8, ax);
    bx = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    ax = memoryGet16(es, bx + 2);
    bx = memoryGet16(ss, bp - 20);
    es = memoryGet16(ss, bp - 20 + 2);
    memorySet16(es, bx + 10, ax);
    sub_3697();
    sub_39fb();
loc_4b2b:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    bx += ax;
    al = memoryGet(es, bx + 96);
    ah = 0x00;
    si = ax;
    if (!ax)
        goto loc_4bae;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    dl = memoryGet(ss, bp - 2);
    dh = 0x00;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax += dx;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 628);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx, ax);
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    dl = memoryGet(ss, bp - 2);
    dh = 0x00;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    dx <<= 1;
    ax += dx;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 630);
    bx = memoryGet16(ds, 0x8884);
    memorySet16(es, bx + 2, ax);
    ax = si;
    ax += 0x0179;
    memorySet16(es, bx + 4, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_4bae:
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) + 1);
loc_4bb1:
    if (memoryGet(ss, bp - 1) >= 0x08)
        goto loc_4bba;
    goto loc_4a3f;
loc_4bba:
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
loc_4bbd:
    if (memoryGet(ss, bp - 2) >= 0x06)
        goto loc_4bc6;
    goto loc_4a38;
loc_4bc6:
    bx = memoryGet16(ss, bp - 16);
    es = memoryGet16(ss, bp - 16 + 2);
    al = 0x00;
    memorySet(es, bx + 6, al);
    memorySet(es, bx, al);
    bx = memoryGet16(ss, bp - 20);
    es = memoryGet16(ss, bp - 20 + 2);
    al = 0x00;
    memorySet(es, bx + 6, al);
    memorySet(es, bx, al);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4be4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4bf4;
    sub_ca53();
loc_4bf4:
    memorySet(ss, bp - 5, 0x01);
    if (memoryGet(ds, 0x79b2) <= 0x01)
        goto loc_4c0b;
    al = memoryGet(ds, 0x119a);
    ah = 0x00;
    if (ax)
        goto loc_4c0b;
    //sub_5ee5(); // ask for platform number
loc_4c0b:
    if (memoryGet(ds, 0x119a) != 0xff)
        goto loc_4c17;
    memorySet(ds, 0x79b2, 0x01);
loc_4c17:
    al = memoryGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 4298);
    dx = memoryGet16(ds, bx + 4296);
    memorySet16(ds, 0x8246, dx);
    memorySet16(ds, 0x8248, ax);
    al = memoryGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 4334);
    dx = memoryGet16(ds, bx + 4332);
    memorySet16(ds, 0x8554, dx);
    memorySet16(ds, 0x8556, ax);
    memorySet(ds, 0x854e, 0x01);
    ax = 0x001f;
    memorySet16(ds, 0x791e, ax);
    memorySet16(ds, 0x791c, ax);
    if (memoryGet(ds, 0x79b2) == 0x02)
        goto loc_4c67;
    if (memoryGet(ds, 0x79b2) != 0x05)
        goto loc_4c86;
loc_4c67:
    memorySet16(ds, 0x791c, 0x006f);
    goto loc_4c86;
loc_4c6f:
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryGet16(ds, 0x8246);
    es = memoryGet16(ds, 0x8246 + 2);
    bx += ax;
    memorySet(es, bx, 0x00);
    memorySet(ss, bp - 5, memoryGet(ss, bp - 5) + 1);
loc_4c86:
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryGet16(ds, 0x8246);
    es = memoryGet16(ds, 0x8246 + 2);
    bx += ax;
    if (memoryGet(es, bx) != 0xff)
        goto loc_4c6f;
    push(ds);
    ax = 0x0090;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x0090);
    es = memoryGet16(ds, 0x0090 + 2);
    al = memoryGet(ds, 0x79b2);
    al += 0x30;
    memorySet(es, bx + 1, al);
    bx = memoryGet16(ds, 0x009a);
    es = memoryGet16(ds, 0x009a + 2);
    al = memoryGet(ds, 0x79b2);
    al += 0x30;
    memorySet(es, bx + 1, al);
    bx = memoryGet16(ds, 0x00e0);
    es = memoryGet16(ds, 0x00e0 + 2);
    al = memoryGet(ds, 0x79b2);
    al += 0x30;
    memorySet(es, bx + 1, al);
    ax = 0x0004;
    push(ax);
    ax = 0;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x0098));
    push(memoryGet16(ds, 0x0096));
    push(memoryGet16(ds, 0x6fa8));
    push(memoryGet16(ds, 0x6fa6));
    push(si);
    sub_932e();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryGet16(ds, 0x0098));
    push(memoryGet16(ds, 0x0096));
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ds, 0x6fa8));
    push(memoryGet16(ds, 0x6fa6));
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
    push(memoryGet16(ds, 0x00a2));
    push(memoryGet16(ds, 0x00a0));
    push(memoryGet16(ds, 0x6bea));
    push(memoryGet16(ds, 0x6be8));
    push(si);
    sub_932e();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryGet16(ds, 0x00a2));
    push(memoryGet16(ds, 0x00a0));
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ds, 0x6bea));
    push(memoryGet16(ds, 0x6be8));
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
    push(memoryGet16(ds, 0x00e8));
    push(memoryGet16(ds, 0x00e6));
    push(memoryGet16(ds, 0x75e0));
    push(memoryGet16(ds, 0x75de));
    push(si);
    sub_932e();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryGet16(ds, 0x00e8));
    push(memoryGet16(ds, 0x00e6));
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ds, 0x75e0));
    push(memoryGet16(ds, 0x75de));
    sub_9a2a();
    sp += 0x000c;
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4dc8()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4dd8;
    sub_ca53();
loc_4dd8:
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
    push(memoryGet16(ds, 0x0930));
    push(memoryGet16(ds, 0x092e));
    push(memoryGet16(ds, 0xa0c8));
    push(memoryGet16(ds, 0xa0c6));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    push(memoryGet16(ds, 0xa0c8));
    push(memoryGet16(ds, 0xa0c6));
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
    push(memoryGet16(ds, 0x093a));
    push(memoryGet16(ds, 0x0938));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    sub_70a8();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_4e7c()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4e8d;
    sub_ca53();
loc_4e8d:
    ax = 0x0004;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x0944));
    push(memoryGet16(ds, 0x0942));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_4f1c;
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(ds, 0x9b96, dx);
    memorySet16(ds, 0x9b98, ax);
    memorySet(ss, bp - 5, 0x00);
    goto loc_4f16;
loc_4ef9:
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    di = ax;
    al = memoryGet(ds, di + 1594);
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 5, memoryGet(ss, bp - 5) + 1);
loc_4f16:
    if (memoryGet(ss, bp - 5) < 0x10)
        goto loc_4ef9;
loc_4f1c:
    sub_5337();
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0014);
    memorySet16(es, bx + 32, 0x0019);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
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
void sub_4fad()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_4fbc;
    sub_ca53();
loc_4fbc:
    memorySet(ss, bp - 1, 0x00);
    ax = 0x0004;
    push(ax);
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x0958));
    push(memoryGet16(ds, 0x0956));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
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
    push(memoryGet16(ds, 0x0962));
    push(memoryGet16(ds, 0x0960));
    push(memoryGet16(ds, 0xa0c8));
    push(memoryGet16(ds, 0xa0c6));
    push(si);
    sub_932e();
    sp += 0x000c;
    push(si);
    sub_91e9();
    sp++;
    sp++;
    if (memoryGet16(ds, 0x689c) == 0x8000)
        goto loc_508d;
    goto loc_506c;
loc_5027:
    ax = 0x0001;
    push(ax);
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    push(memoryGet16(ds, 0xa0c8));
    push(memoryGet16(ds, 0xa0c6));
    sub_a847();
    sp += 0x000a;
    goto loc_505c;
loc_5043:
    ax = memoryGet16(ds, 0x119c);
    ax += 0x0007;
    memorySet16(ds, 0x119c, ax);
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    if (!(al & 0x10))
        goto loc_505c;
    memorySet(ss, bp - 1, 0x01);
loc_505c:
    sub_a869();
    if (!ax)
        goto loc_506c;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_5043;
loc_506c:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_5027;
    sub_a878();
    if (memoryGet16(ds, 0x689c) != 0x0000)
        goto loc_50a9;
    ax = 0x0001;
    push(ax);
    sub_9ce8();
    sp++;
    sp++;
    sub_b33e();
    goto loc_50a9;
loc_508d:
    memorySet(ds, 0x8244, 0x00);
    goto loc_50a0;
loc_5094:
    bumpyScene = "splash";
    sync();
    sub_3cae();
    ax = memoryGet16(ds, 0x119c);
    ax += 0x0007;
    memorySet16(ds, 0x119c, ax);
loc_50a0:
    al = memoryGet(ds, 0x8244);
    ah = 0x00;
    if (!ax)
        goto loc_5094;
loc_50a9:
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_50ae()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_50ba;
    sub_ca53();
loc_50ba:
    memorySet(ds, 0x8242, 0x00);
    memorySet(ds, 0x792a, 0x00);
    memorySet16(ds, 0x824a, 0x0000);
    memorySet(ds, 0xa0ce, 0x00);
    al = 0x00;
    memorySet(ds, 0x8578, al);
    memorySet(ds, 0x8e8b, al);
    al = 0x00;
    memorySet(ds, 0x8579, al);
    memorySet(ds, 0x8e8c, al);
    memorySet(ds, 0x8244, 0x00);
    memorySet(ds, 0xa1a7, 0x00);
    memorySet(ds, 0x79b4, 0x00);
    memorySet(ds, 0x7923, 0x00);
    memorySet(ds, 0x824c, 0x00);
    memorySet(ds, 0xa1a8, 0x00);
    memorySet(ds, 0xa1b1, 0x00);
    memorySet(ds, 0x8550, 0x00);
    memorySet(ds, 0x8563, 0x00);
    memorySet(ds, 0xa1b0, 0x00);
    memorySet(ds, 0x8243, 0x00);
    memorySet(ds, 0x79b7, 0x00);
    memorySet16(ds, 0x9ba6, 0x0886);
    memorySet16(ds, 0x9ba8, ds);
    bx = memoryGet16(ds, 0x9ba6);
    es = memoryGet16(ds, 0x9ba6 + 2);
    memorySet(es, bx, 0xff);
    sub_67d6();
    sub_6779();
    ax = memoryGet16(ds, 0x9292);
    ax += 0xfff4;
    memorySet16(ds, 0x9292, ax);
    memorySet(ds, 0x792c, 0x00);
    memorySet16(ds, 0xa1ac, 0x1394);
    memorySet16(ds, 0xa1ae, ds);
    memorySet(ds, 0x824d, 0x0a);
    al = 0x04;
    memorySet(ds, 0x9bae, al);
    memorySet(ds, 0x792a, al);
    memorySet(ds, 0xa1a9, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_515f()
{
    sync();
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_516b;
    sub_ca53();
loc_516b:
    memorySet(ds, 0x8244, 0x00);
    goto loc_5175;
loc_5172:
    sync();
    sub_3cae();
loc_5175:
    al = memoryGet(ds, 0x8244);
    ah = 0x00;
    if (!ax)
        goto loc_5172;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5180()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_518c;
    sub_ca53();
loc_518c:
    ax = memoryGet16(ds, 0x7310);
    dx = 0x00c2;
    imul(dx);
    dx = memoryGet16(ds, 0x6bf4);
    bx = memoryGet16(ds, 0x6bf2);
    bx += ax;
    memorySet16(ds, 0x75d0, bx);
    memorySet16(ds, 0x75d2, dx);
    ax = memoryGet16(ds, 0x7310);
    dx = 0x032c;
    imul(dx);
    dx = memoryGet16(ds, 0x6bd4);
    bx = memoryGet16(ds, 0x6bd2);
    bx += ax;
    memorySet16(ds, 0x6bca, bx);
    memorySet16(ds, 0x6bcc, dx);
    memorySet16(ds, 0xa0d8, 0xa0e4);
    memorySet16(ds, 0xa0da, ds);
    cl = 0x00;
    goto loc_5222;
loc_51ce:
    al = cl;
    ah = 0x00;
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    dl = cl;
    dh = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += dx;
    memorySet(es, bx, al);
    al = cl;
    ah = 0x00;
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    bx += ax;
    al = memoryGet(es, bx + 48);
    dl = cl;
    dh = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += dx;
    memorySet(es, bx + 48, al);
    al = cl;
    ah = 0x00;
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    bx += ax;
    al = memoryGet(es, bx + 96);
    dl = cl;
    dh = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += dx;
    memorySet(es, bx + 96, al);
    cl++;
loc_5222:
    if (cl < 0x30)
        goto loc_51ce;
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    al = memoryGet(es, bx + 144);
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    memorySet(es, bx + 144, al);
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    al = memoryGet(es, bx + 145);
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    memorySet(es, bx + 145, al);
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    al = memoryGet(es, bx + 146);
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    memorySet(es, bx + 146, al);
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    al = memoryGet(es, bx + 147);
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    memorySet(es, bx + 147, al);
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    al = memoryGet(es, bx + 148);
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    memorySet(es, bx + 148, al);
    bx = memoryGet16(ds, 0x75d0);
    es = memoryGet16(ds, 0x75d0 + 2);
    al = memoryGet(es, bx + 149);
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    memorySet(es, bx + 149, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5295()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_52a1;
    sub_ca53();
loc_52a1:
    memorySet16(ds, 0x8884, 0x792e);
    memorySet16(ds, 0x8886, ds);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ax = memoryGet16(ds, 0xa0c8);
    dx = memoryGet16(ds, 0xa0c6);
    memorySet16(es, bx + 6, dx);
    memorySet16(es, bx + 8, ax);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) | 0x80);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xbf);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xdf);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xef);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xf7);
    memorySet16(ds, 0x9b9e, 0x795a);
    memorySet16(ds, 0x9ba0, ds);
    bx = memoryGet16(ds, 0x9b9e);
    es = memoryGet16(ds, 0x9b9e + 2);
    memorySet16(es, bx + 6, dx);
    memorySet16(es, bx + 8, ax);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) | 0x80);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xbf);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xdf);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xef);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xf7);
    memorySet16(ds, 0xa0d0, 0x7986);
    memorySet16(ds, 0xa0d2, ds);
    bx = memoryGet16(ds, 0xa0d0);
    es = memoryGet16(ds, 0xa0d0 + 2);
    memorySet16(es, bx + 6, dx);
    memorySet16(es, bx + 8, ax);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) | 0x80);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xbf);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xdf);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xef);
    memorySet(es, bx + 10, memoryGet(es, bx + 10) & 0xf7);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5337()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0068;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5347;
    sub_ca53();
loc_5347:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet(es, bx + 34, 0x00);
    memorySet(es, bx + 35, 0x00);
    memorySet(es, bx + 36, 0x00);
    memorySet(es, bx + 37, 0x00);
    memorySet16(es, bx + 14, 0x0000);
    memorySet16(es, bx + 28, 0x0000);
    memorySet(ss, bp - 2, 0x14);
    memorySet(ss, bp - 3, 0x19);
    memorySet(ss, bp - 1, 0x00);
    goto loc_5436;
loc_537a:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    memorySet16(es, bx + 20, ax);
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    memorySet16(es, bx + 22, ax);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    memorySet16(es, bx + 30, ax);
    memorySet16(es, bx + 32, 0x0001);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0018;
    dx -= ax;
    memorySet16(es, bx + 22, dx);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    al = memoryGet(ss, bp - 2);
    al += 0xfe;
    memorySet(ss, bp - 2, al);
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    memorySet16(es, bx + 22, ax);
    memorySet16(es, bx + 30, 0x0001);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    memorySet16(es, bx + 32, ax);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0013;
    dx -= ax;
    memorySet16(es, bx + 20, dx);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    sub_b734();
    al = memoryGet(ss, bp - 3);
    al += 0xfe;
    memorySet(ss, bp - 3, al);
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) + 1);
loc_5436:
    if (memoryGet(ss, bp - 1) > 0x09)
        goto loc_543f;
    goto loc_537a;
loc_543f:
    si = 0;
    goto loc_5452;
loc_5443:
    bx = si;
    bx <<= 1;
    ax = bp - 0x68;
    bx += ax;
    memorySet16(ss, bx, 0x0000);
    si++;
loc_5452:
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
void sub_5475()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5486;
    sub_ca53();
loc_5486:
    memorySet(ss, bp - 5, 0x00);
    memorySet(ss, bp - 6, 0xff);
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
    push(memoryGet16(ds, 0x09e4));
    push(memoryGet16(ds, 0x09e2));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_552d;
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(ds, 0x9b96, dx);
    memorySet16(ds, 0x9b98, ax);
    memorySet(ss, bp - 11, 0x00);
    goto loc_5527;
loc_550a:
    al = memoryGet(ss, bp - 11);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 11);
    ah = 0x00;
    di = ax;
    al = memoryGet(ds, di + 1610);
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 11, memoryGet(ss, bp - 11) + 1);
loc_5527:
    if (memoryGet(ss, bp - 11) < 0x10)
        goto loc_550a;
loc_552d:
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ax = memoryGet16(ds, 0x6c2e);
    dx = memoryGet16(ds, 0x6c2c);
    memorySet16(es, bx + 6, dx);
    memorySet16(es, bx + 8, ax);
    al = 0x00;
    memorySet(ds, 0x854f, al);
    memorySet(ds, 0x8244, al);
    sub_5337();
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0014);
    memorySet16(es, bx + 32, 0x0019);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = 0;
    push(ax);
    sub_9a9a();
    sp++;
    sp++;
    goto loc_56d9;
loc_55cf:
    bumpyScene = "menu";
    al = memoryGet(ds, 0x79b5);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 1888);
    dx = memoryGet16(ds, bx + 1886);
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0006);
    memorySet16(es, bx + 12, 0x0002);
    memorySet16(es, bx + 20, 0x000b);
    memorySet16(es, bx + 22, 0x0012);
    memorySet16(es, bx + 30, 0x0006);
    memorySet16(es, bx + 32, 0x0002);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
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
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 4, 0x0000);
    memorySet16(es, bx, 0x0030);
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0070;
    memorySet16(es, bx + 2, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    sub_b734();
    sub_3cae();
    if (!(memoryGet(ds, 0x8244) & 0x01))
        goto loc_5684;
    if (memoryGet(ss, bp - 5) == 0x00)
        goto loc_5684;
    memorySet(ss, bp - 5, memoryGet(ss, bp - 5) - 1);
    goto loc_56c8;
loc_5684:
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_5696;
    if (memoryGet(ss, bp - 5) >= 0x03)
        goto loc_5696;
    memorySet(ss, bp - 5, memoryGet(ss, bp - 5) + 1);
    goto loc_56c8;
loc_5696:
    if (!(memoryGet(ds, 0x8244) & 0x10))
        goto loc_56c8;
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    bx = ax;
    if (bx > 0x0003)
        goto loc_56c8;
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_56b0;
        case 2: goto loc_56b0;
        case 4: goto loc_56b8;
        case 6: goto loc_56b0;
        default:
        assert(0);
    }
loc_56b0:
    al = memoryGet(ss, bp - 5);
    memorySet(ss, bp - 6, al);
    goto loc_56c8;
loc_56b8:
    memorySet(ds, 0x79b5, memoryGet(ds, 0x79b5) + 1);
    if (memoryGet(ds, 0x79b5) != 0x03)
        goto loc_56c8;
    memorySet(ds, 0x79b5, 0x00);
loc_56c8:
    memorySet(ds, 0x8244, 0x00);
loc_56cd:
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    if (al)
    {
        sync();
        // wait while pressed
        goto loc_56cd;
    }
loc_56d9:
    if (memoryGet(ss, bp - 6) != 0xff)
        goto loc_56e2;
    goto loc_55cf;
loc_56e2:
    al = memoryGet(ds, 0x79b5);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    al = memoryGet(ss, bx);
    memorySet(ds, 0x854f, al);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ax = memoryGet16(ds, 0xa0c8);
    dx = memoryGet16(ds, 0xa0c6);
    memorySet16(es, bx + 6, dx);
    memorySet16(es, bx + 8, ax);
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    al = memoryGet(ss, bp - 6);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5722()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5732;
    sub_ca53();
loc_5732:
    memorySet(ss, bp - 5, 0x00);
    al = memoryGet(ds, 0x854f);
    memorySet(ds, 0x8e8a, al);
    memorySet(ds, 0x854f, 0x00);
    memorySet(ds, 0x8244, 0x00);
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = 0x0004;
    push(ax);
    al = memoryGet(ds, 0x79b2);
    ah = 0x00;
    ax += 0x0007;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    al = memoryGet(ds, 0x79b2);
    ah = 0x00;
    dx = 0x000a;
    imul(dx);
    bx = ax;
    push(memoryGet16(ds, bx + 2422));
    push(memoryGet16(ds, bx + 2420));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_580c;
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(ds, 0x9b96, dx);
    memorySet16(ds, 0x9b98, ax);
    al = memoryGet(ds, 0x79b2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 1768);
    dx = memoryGet16(ds, bx + 1766);
    memorySet16(ss, bp - 10, dx);
    memorySet16(ss, bp - 8, ax);
    memorySet(ss, bp - 6, 0x00);
    goto loc_5806;
loc_57e7:
    al = memoryGet(ss, bp - 6);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 10);
    es = memoryGet16(ss, bp - 10 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    dl = memoryGet(ss, bp - 6);
    dh = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += dx;
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 6, memoryGet(ss, bp - 6) + 1);
loc_5806:
    if (memoryGet(ss, bp - 6) < 0x10)
        goto loc_57e7;
loc_580c:
    sub_5337();
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0014);
    memorySet16(es, bx + 32, 0x0019);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0x0008;
    push(ax);
    ax = 0x0001;
    push(ax);
    al = 0x07;
    push(ax);
    push(memoryGet16(ds, 0xa0d6));
    push(memoryGet16(ds, 0xa0d4));
    sub_26e6();
    sp += 0x000a;
    sub_8000();
    sub_5b1f();
    al = memoryGet(ds, 0x79b6);
    memorySet(ds, 0x854e, al);
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    sub_9a63();
    sp += 0x0006;
    ax = memoryGet16(ds, 0x791c);
    memorySet16(ds, 0x9290, ax);
    ax = memoryGet16(ds, 0x791e);
    memorySet16(ds, 0x9292, ax);
    memorySet16(ds, 0x824a, 0x0021);
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
loc_58ec:
    bumpyScene = "levels";
    sync();
    sub_3cae();
    if (!(memoryGet(ds, 0x8244) & 0x01))
        goto loc_58fb;
    sub_5982();
    goto loc_593f;
loc_58fb:
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_5907;
    sub_59df();
    goto loc_593f;
loc_5907:
    if (!(memoryGet(ds, 0x8244) & 0x04))
        goto loc_5913;
    sub_5a3c();
    goto loc_593f;
loc_5913:
    if (!(memoryGet(ds, 0x8244) & 0x08))
        goto loc_591f;
    sub_5a99();
    goto loc_593f;
loc_591f:
    if (!(memoryGet(ds, 0x8244) & 0x10))
        goto loc_592b;
    sub_5bc7();
    goto loc_593c;
loc_592b:
    al = 0x01;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (!al)
        goto loc_593f;
    al = 0xff;
    memorySet(ds, 0x928d, al);
loc_593c:
    memorySet(ss, bp - 5, al);
loc_593f:
    memorySet(ds, 0x8244, 0x00);
loc_5944:
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    if (!ax)
        goto loc_58ec;
    al = memoryGet(ds, 0x8e8a);
    memorySet(ds, 0x854f, al);
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5958()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5964;
    sub_ca53();
loc_5964:
    al = memoryGet(ds, 0x854e);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    dx = memoryGet16(ds, 0x8248);
    bx = memoryGet16(ds, 0x8246);
    bx += ax;
    memorySet16(ds, 0x9baa, bx);
    memorySet16(ds, 0x9bac, dx);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5982()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5991;
    sub_ca53();
loc_5991:
    ax = memoryGet16(ds, 0x9bac);
    dx = memoryGet16(ds, 0x9baa);
    memorySet16(ss, bp - 6, dx);
    memorySet16(ss, bp - 4, ax);
    bx = memoryGet16(ss, bp - 6);
    es = memoryGet16(ss, bp - 6 + 2);
    al = memoryGet(es, bx + 1);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_59db;
    memorySet(ds, 0x854e, al);
    sub_5958();
    bx = memoryGet16(ss, bp - 6);
    es = memoryGet16(ss, bp - 6 + 2);
    al = memoryGet(es, bx + 2);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet(ss, bp - 1, al);
    goto loc_59d5;
loc_59c6:
    ax = memoryGet16(ds, 0x9292);
    ax += 0xfffc;
    memorySet16(ds, 0x9292, ax);
    sub_5af6();
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) - 1);
loc_59d5:
    if (memoryGet(ss, bp - 1) != 0x00)
        goto loc_59c6;
loc_59db:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_59df()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_59ee;
    sub_ca53();
loc_59ee:
    ax = memoryGet16(ds, 0x9bac);
    dx = memoryGet16(ds, 0x9baa);
    memorySet16(ss, bp - 6, dx);
    memorySet16(ss, bp - 4, ax);
    bx = memoryGet16(ss, bp - 6);
    es = memoryGet16(ss, bp - 6 + 2);
    al = memoryGet(es, bx + 3);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_5a38;
    memorySet(ds, 0x854e, al);
    sub_5958();
    bx = memoryGet16(ss, bp - 6);
    es = memoryGet16(ss, bp - 6 + 2);
    al = memoryGet(es, bx + 4);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet(ss, bp - 1, al);
    goto loc_5a32;
loc_5a23:
    ax = memoryGet16(ds, 0x9292);
    ax += 0x0004;
    memorySet16(ds, 0x9292, ax);
    sub_5af6();
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) - 1);
loc_5a32:
    if (memoryGet(ss, bp - 1) != 0x00)
        goto loc_5a23;
loc_5a38:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5a3c()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5a4b;
    sub_ca53();
loc_5a4b:
    ax = memoryGet16(ds, 0x9bac);
    dx = memoryGet16(ds, 0x9baa);
    memorySet16(ss, bp - 6, dx);
    memorySet16(ss, bp - 4, ax);
    bx = memoryGet16(ss, bp - 6);
    es = memoryGet16(ss, bp - 6 + 2);
    al = memoryGet(es, bx + 5);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_5a95;
    memorySet(ds, 0x854e, al);
    sub_5958();
    bx = memoryGet16(ss, bp - 6);
    es = memoryGet16(ss, bp - 6 + 2);
    al = memoryGet(es, bx + 6);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet(ss, bp - 1, al);
    goto loc_5a8f;
loc_5a80:
    ax = memoryGet16(ds, 0x9290);
    ax += 0xfffc;
    memorySet16(ds, 0x9290, ax);
    sub_5af6();
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) - 1);
loc_5a8f:
    if (memoryGet(ss, bp - 1) != 0x00)
        goto loc_5a80;
loc_5a95:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5a99()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5aa8;
    sub_ca53();
loc_5aa8:
    ax = memoryGet16(ds, 0x9bac);
    dx = memoryGet16(ds, 0x9baa);
    memorySet16(ss, bp - 6, dx);
    memorySet16(ss, bp - 4, ax);
    bx = memoryGet16(ss, bp - 6);
    es = memoryGet16(ss, bp - 6 + 2);
    al = memoryGet(es, bx + 7);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_5af2;
    memorySet(ds, 0x854e, al);
    sub_5958();
    bx = memoryGet16(ss, bp - 6);
    es = memoryGet16(ss, bp - 6 + 2);
    al = memoryGet(es, bx + 8);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet(ss, bp - 1, al);
    goto loc_5aec;
loc_5add:
    ax = memoryGet16(ds, 0x9290);
    ax += 0x0004;
    memorySet16(ds, 0x9290, ax);
    sub_5af6();
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) - 1);
loc_5aec:
    if (memoryGet(ss, bp - 1) != 0x00)
        goto loc_5add;
loc_5af2:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5af6()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5b02;
    sub_ca53();
loc_5b02:
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
void sub_5b1f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5b2d;
    sub_ca53();
loc_5b2d:
    memorySet(ss, bp - 1, 0x00);
    al = memoryGet(ds, 0x854e);
    memorySet(ds, 0x79b6, al);
    memorySet(ds, 0x854e, 0x01);
loc_5b3c:
    sub_5958();
    bx = memoryGet16(ds, 0x9baa);
    es = memoryGet16(ds, 0x9baa + 2);
    if (memoryGet(es, bx) != 0xff)
        goto loc_5b4f;
    memorySet(ss, bp - 1, 0x01);
    goto loc_5b5c;
loc_5b4f:
    bx = memoryGet16(ds, 0x9baa);
    es = memoryGet16(ds, 0x9baa + 2);
    if (memoryGet(es, bx) == 0x00)
        goto loc_5b5c;
    sub_5b6d();
loc_5b5c:
    memorySet(ds, 0x854e, memoryGet(ds, 0x854e) + 1);
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_5b3c;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5b6d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5b79;
    sub_ca53();
loc_5b79:
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 4, 0x01da);
    al = memoryGet(ds, 0x854e);
    ah = 0x00;
    ax--;
    ax <<= 1;
    ax <<= 1;
    bx = memoryGet16(ds, 0x8554);
    es = memoryGet16(ds, 0x8554 + 2);
    bx += ax;
    ax = memoryGet16(es, bx);
    ax--;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx, ax);
    al = memoryGet(ds, 0x854e);
    ah = 0x00;
    ax--;
    ax <<= 1;
    ax++;
    ax <<= 1;
    bx = memoryGet16(ds, 0x8554);
    es = memoryGet16(ds, 0x8554 + 2);
    bx += ax;
    ax = memoryGet16(es, bx);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5bc7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5bd6;
    sub_ca53();
loc_5bd6:
    memorySet(ss, bp - 5, 0x00);
    memorySet(ds, 0x792c, 0x00);
    sub_5af6();
    sub_5af6();
    sub_5958();
    ax = memoryGet16(ds, 0x9bac);
    dx = memoryGet16(ds, 0x9baa);
    memorySet16(ss, bp - 4, dx);
    memorySet16(ss, bp - 2, ax);
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    al = memoryGet(es, bx);
    ah = 0x00;
    if (!ax)
        goto loc_5c04;
    goto loc_5cc6;
loc_5c04:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_5c0f;
    al = 0x03;
    goto loc_5c11;
loc_5c0f:
    al = 0x28;
loc_5c11:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    memorySet(ds, 0x854f, 0xaa);
    ax = memoryGet16(ds, 0x9292);
    memorySet16(ds, 0x791e, ax);
    ax = memoryGet16(ds, 0x9290);
    memorySet16(ds, 0x791c, ax);
    memorySet16(ds, 0xa1ac, 0x1114);
    memorySet16(ds, 0xa1ae, ds);
    memorySet(ds, 0x824d, 0x16);
    ax = memoryGet16(ds, 0x9290);
    ax += 0xfff1;
    memorySet16(ds, 0x9290, ax);
    ax = memoryGet16(ds, 0x9292);
    ax += 0x0003;
    memorySet16(ds, 0x9292, ax);
    memorySet16(ds, 0x824a, 0x00cb);
    sub_38b4();
    sub_3b82();
    sub_3aa7();
    ax = memoryGet16(ds, 0x9290);
    ax += 0x000f;
    memorySet16(ds, 0x9290, ax);
    ax = memoryGet16(ds, 0x9292);
    ax += 0xfffd;
    memorySet16(ds, 0x9292, ax);
    memorySet16(ds, 0x824a, 0x0000);
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
loc_5c9a:
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
    if (memoryGet(ds, 0x824d) != 0x00)
        goto loc_5c9a;
    sub_5d44();
    memorySet(ss, bp - 5, 0x01);
loc_5cc6:
    al = memoryGet(ss, bp - 5);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5ccd()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5cdb;
    sub_ca53();
loc_5cdb:
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    di = memoryGet16(es, bx + 20);
    si = memoryGet16(es, bx + 22);
    ax = memoryGet16(ds, 0x9290);
    ax -= di;
    ax += 0x000e;
    cl = 0x04;
    ax = sar(ax, cl);
    ax--;
    memorySet16(ds, 0x9d36, ax);
    ax = memoryGet16(ds, 0x9292);
    ax -= si;
    ax += 0xfff6;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet16(ds, 0x9d38, ax);
    if ((short)memoryGet16(ds, 0x9d36) >= (short)0x0000)
        goto loc_5d17;
    memorySet16(ds, 0x9d36, 0x0000);
    goto loc_5d24;
loc_5d17:
    if ((short)memoryGet16(ds, 0x9d36) <= (short)0x0012)
        goto loc_5d24;
    memorySet16(ds, 0x9d36, 0x0012);
loc_5d24:
    if ((short)memoryGet16(ds, 0x9d38) >= (short)0x0000)
        goto loc_5d33;
    memorySet16(ds, 0x9d38, 0x0000);
    goto loc_5d40;
loc_5d33:
    if ((short)memoryGet16(ds, 0x9d38) <= (short)0x0016)
        goto loc_5d40;
    memorySet16(ds, 0x9d38, 0x0016);
loc_5d40:
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5d44()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5d50;
    sub_ca53();
loc_5d50:
    al = 0x32;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5d5a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5d68;
    sub_ca53();
loc_5d68:
    al = 0x01;
    cl = al;
    memorySet(ss, bp - 1, al);
    goto loc_5d88;
loc_5d71:
    al = cl;
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryGet16(ds, 0x8246);
    es = memoryGet16(ds, 0x8246 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) & al);
    cl++;
loc_5d88:
    al = cl;
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryGet16(ds, 0x8246);
    es = memoryGet16(ds, 0x8246 + 2);
    bx += ax;
    if (memoryGet(es, bx) != 0xff)
        goto loc_5d71;
    al = memoryGet(ss, bp - 1);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5da4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5db5;
    sub_ca53();
loc_5db5:
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
    push(memoryGet16(ds, 0x09da));
    push(memoryGet16(ds, 0x09d8));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    push(si);
    sub_932e();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
    sub_9a2a();
    sp += 0x000c;
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_5e47;
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(ds, 0x9b96, dx);
    memorySet16(ds, 0x9b98, ax);
    memorySet(ss, bp - 5, 0x00);
    goto loc_5e41;
loc_5e24:
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    di = ax;
    al = memoryGet(ds, di + 1838);
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 5, memoryGet(ss, bp - 5) + 1);
loc_5e41:
    if (memoryGet(ss, bp - 5) < 0x10)
        goto loc_5e24;
loc_5e47:
    sub_5337();
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0014);
    memorySet16(es, bx + 32, 0x0019);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x7928));
    push(memoryGet16(ds, 0x7926));
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
    memorySet(ds, 0x8244, 0x00);
    sub_515f();
    al = 0x01;
    memorySet(ds, 0x79b2, al);
    memorySet(ds, 0x928d, al);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_5ee5()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0036;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_5ef6;
    sub_ca53();
loc_5ef6:
    memorySet(ss, bp - 5, 0x00);
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
    push(memoryGet16(ds, 0x119c));
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
    push(memoryGet16(ds, 0x6bea));
    push(memoryGet16(ds, 0x6be8));
    push(di);
    sub_932e();
    sp += 0x000c;
    push(di);
    sub_91e9();
    sp++;
    sp++;
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_5fad;
    ax = memoryGet16(ds, 0x6bea);
    dx = memoryGet16(ds, 0x6be8);
    memorySet16(ds, 0x9b96, dx);
    memorySet16(ds, 0x9b98, ax);
    memorySet(ss, bp - 1, 0x00);
    goto loc_5fa7;
loc_5f86:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    push(es);
    push(bx);
    bx = ax;
    al = memoryGet(ds, bx + 1626);
    bx = pop();
    es = pop();
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) + 1);
loc_5fa7:
    if (memoryGet(ss, bp - 1) < 0x10)
        goto loc_5f86;
loc_5fad:
    memorySet(ss, bp - 1, 0x00);
    goto loc_5fd3;
loc_5fb3:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 1854);
    dl = memoryGet(ss, bp - 1);
    dh = 0x00;
    dx <<= 1;
    bx = memoryGet16(ds, 0x6bca);
    es = memoryGet16(ds, 0x6bca + 2);
    bx += dx;
    memorySet16(es, bx, ax);
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) + 1);
loc_5fd3:
    if (memoryGet(ss, bp - 1) < 0x10)
        goto loc_5fb3;
    sub_250b();
    memorySet(ss, bp - 5, 0x00);
    goto loc_6112;
loc_5fe3:
    sub_b281();
    ax &= 0x000f;
    si = ax;
    if ((short)ax < (short)0x0002)
        goto loc_5fe3;
    al = memoryGet(ss, bp + si - 54);
    memorySet(ss, bp - 4, al);
    al = 0x00;
    memorySet(ss, bp - 3, al);
    memorySet(ss, bp - 2, al);
    memorySet(ds, 0x119a, 0x01);
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
    ax = memoryGet16(ss, bx);
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx, 0x0090);
    memorySet16(es, bx + 2, 0x0064);
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
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    push(dx);
    push(ax);
    sub_26e6();
    sp += 0x000a;
    goto loc_60e0;
loc_6069:
    memorySet(ds, 0x8244, 0x00);
    sub_3cae();
    if (!(memoryGet(ds, 0x8244) & 0x10))
        goto loc_607e;
    memorySet(ss, bp - 3, 0x01);
    goto loc_60bf;
loc_607e:
    if (!(memoryGet(ds, 0x8244) & 0x04))
        goto loc_609c;
    if (memoryGet(ss, bp - 2) == 0x00)
        goto loc_609c;
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) - 1);
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    push(ds);
    ax = 0x134b;
    goto loc_60b8;
loc_609c:
    if (!(memoryGet(ds, 0x8244) & 0x08))
        goto loc_60bf;
    if (memoryGet(ss, bp - 2) >= 0x63)
        goto loc_60bf;
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    push(ds);
    ax = 0x1350;
loc_60b8:
    push(ax);
    sub_26c0();
    sp += 0x0008;
loc_60bf:
    ax = 0x0096;
    push(ax);
    ax = 0x0098;
    push(ax);
    al = 0x02;
    push(ax);
    al = memoryGet(ss, bp - 2);
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
loc_60e0:
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    if (!ax)
        goto loc_6069;
    al = memoryGet(ss, bp - 2);
    memorySet(ss, bp - 4, al);
    goto loc_610e;
    //   gap of 29 bytes
loc_610e:
    memorySet(ss, bp - 5, 0xff);
loc_6112:
    if (memoryGet(ss, bp - 5) >= 0x03)
        goto loc_611b;
    goto loc_5fe3;
loc_611b:
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
void sub_6133()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6142;
    sub_ca53();
loc_6142:
    memorySet(ds, 0x8244, 0x00);
    al = memoryGet(ds, 0x8242);
    ah = 0x00;
    if (ax)
        goto loc_61a5;
    al = memoryGet(ss, bp + 4);
    memorySet(ds, 0x792c, al);
    if (memoryGet(ds, 0x792c) == 0x05)
        goto loc_61a5;
    if (memoryGet(ds, 0x792c) == 0x0b)
        goto loc_61a5;
    if (memoryGet(ds, 0x792c) == 0x1c)
        goto loc_61a5;
    memorySet(ds, 0xa0dc, 0x00);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 8788);
    dx = memoryGet16(ds, bx + 8786);
    memorySet16(ss, bp - 4, dx);
    memorySet16(ss, bp - 2, ax);
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    al = memoryGet(es, bx);
    memorySet(ds, 0x824d, al);
    al = memoryGet(es, bx + 1);
    memorySet(ds, 0x9bae, al);
    ax = memoryGet16(es, bx + 4);
    dx = memoryGet16(es, bx + 2);
    memorySet16(ds, 0xa1ac, dx);
    memorySet16(ds, 0xa1ae, ax);
loc_61a5:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_61a9()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_61b5;
    sub_ca53();
loc_61b5:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_61c0;
    al = 0x03;
    goto loc_61c2;
loc_61c0:
    al = 0x0d;
loc_61c2:
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
void sub_61d5()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_61e1;
    sub_ca53();
loc_61e1:
    memorySet(ds, 0x792c, 0x1c);
    sub_6231();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_61eb()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_61f7;
    sub_ca53();
loc_61f7:
    if (!(memoryGet(ds, 0x8244) & 0x04))
        goto loc_6203;
    sub_4504();
    goto loc_6212;
loc_6203:
    if (!(memoryGet(ds, 0x8244) & 0x08))
        goto loc_620f;
    sub_4571();
    goto loc_6212;
loc_620f:
    sub_6231();
loc_6212:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6214()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6220;
    sub_ca53();
loc_6220:
    if (!(memoryGet(ds, 0x8244) & 0x10))
        goto loc_622c;
    sub_61eb();
    goto loc_622f;
loc_622c:
    sub_6268();
loc_622f:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6231()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6240;
    sub_ca53();
loc_6240:
    memorySet(ss, bp - 1, 0x15);
    memorySet(ss, bp - 2, 0x04);
    memorySet16(ss, bp - 6, 0x1b70);
    memorySet16(ss, bp - 4, ds);
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp - 1);
    push(ax);
    sub_682c();
    sp += 0x0008;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6268()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6274;
    sub_ca53();
loc_6274:
    if (!(memoryGet(ds, 0x8244) & 0x01))
        goto loc_6280;
    sub_6324();
    goto loc_6283;
loc_6280:
    sub_6285();
loc_6283:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6285()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6291;
    sub_ca53();
loc_6291:
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_629d;
    sub_635a();
    goto loc_62a0;
loc_629d:
    sub_62a2();
loc_62a0:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_62a2()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_62ae;
    sub_ca53();
loc_62ae:
    if (!(memoryGet(ds, 0x8244) & 0x04))
        goto loc_62ba;
    sub_6390();
    goto loc_62bd;
loc_62ba:
    sub_62bf();
loc_62bd:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_62bf()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_62cb;
    sub_ca53();
loc_62cb:
    if (!(memoryGet(ds, 0x8244) & 0x08))
        goto loc_62d7;
    sub_6402();
    goto loc_62da;
loc_62d7:
    sub_62dc();
loc_62da:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_62dc()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_62e8;
    sub_ca53();
loc_62e8:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
    sub_423f();
    if (memoryGet(ds, 0x7924) != 0x16)
        goto loc_62fd;
    sub_61d5();
    goto loc_6305;
loc_62fd:
    al = 0x2f;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_6305:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6307()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6313;
    sub_ca53();
loc_6313:
    if (!(memoryGet(ds, 0x8244) & 0x10))
        goto loc_631f;
    sub_62dc();
    goto loc_6322;
loc_631f:
    sub_6268();
loc_6322:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6324()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6330;
    sub_ca53();
loc_6330:
    if (memoryGet(ds, 0x856e) >= 0x08)
        goto loc_633c;
    sub_6285();
    goto loc_6358;
loc_633c:
    al = memoryGet(ds, 0x856e);
    al += 0xf8;
    push(ax);
    sub_649f();
    sp++;
    sp++;
    if (!al)
        goto loc_6350;
    sub_6285();
    goto loc_6358;
loc_6350:
    al = 0x1d;
    push(ax);
    sub_6470();
    sp++;
    sp++;
loc_6358:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_635a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6366;
    sub_ca53();
loc_6366:
    if (memoryGet(ds, 0x856e) < 0x28)
        goto loc_6372;
    sub_62a2();
    goto loc_638e;
loc_6372:
    al = memoryGet(ds, 0x856e);
    al += 0x08;
    push(ax);
    sub_649f();
    sp++;
    sp++;
    if (!al)
        goto loc_6386;
    sub_62a2();
    goto loc_638e;
loc_6386:
    al = 0x1e;
    push(ax);
    sub_6470();
    sp++;
    sp++;
loc_638e:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6390()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_639c;
    sub_ca53();
loc_639c:
    al = memoryGet(ds, 0x855e);
    ah = 0x00;
    if (ax)
        goto loc_63aa;
    sub_62bf();
    goto loc_63da;
loc_63aa:
    al = memoryGet(ds, 0x856e);
    al += 0xff;
    push(ax);
    sub_649f();
    sp++;
    sp++;
    if (!al)
        goto loc_63be;
    sub_63dc();
    goto loc_63da;
loc_63be:
    al = memoryGet(ds, 0x856e);
    al += 0xff;
    push(ax);
    sub_64d5();
    sp++;
    sp++;
    if (!al)
        goto loc_63d2;
    sub_63dc();
    goto loc_63da;
loc_63d2:
    al = 0x1f;
    push(ax);
    sub_6470();
    sp++;
    sp++;
loc_63da:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_63dc()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_63e8;
    sub_ca53();
loc_63e8:
    if (memoryGet(ds, 0x7924) == 0x16)
        goto loc_63fd;
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
    al = 0x2f;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_63fd:
    sub_4504();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6402()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_640e;
    sub_ca53();
loc_640e:
    if (memoryGet(ds, 0x855e) != 0x07)
        goto loc_641a;
    sub_62dc();
    goto loc_6448;
loc_641a:
    al = memoryGet(ds, 0x856e);
    al++;
    push(ax);
    sub_649f();
    sp++;
    sp++;
    if (!al)
        goto loc_642e;
    sub_644a();
    goto loc_6448;
loc_642e:
    al = memoryGet(ds, 0x856e);
    push(ax);
    sub_64d5();
    sp++;
    sp++;
    if (!al)
        goto loc_6440;
    sub_644a();
    goto loc_6448;
loc_6440:
    al = 0x20;
    push(ax);
    sub_6470();
    sp++;
    sp++;
loc_6448:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_644a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6456;
    sub_ca53();
loc_6456:
    if (memoryGet(ds, 0x7924) == 0x16)
        goto loc_646b;
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
    al = 0x2f;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_646b:
    sub_4571();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6470()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_647c;
    sub_ca53();
loc_647c:
    al = memoryGet(ss, bp + 4);
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryGet(ds, 0x7924) == 0x00)
        goto loc_649a;
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
    al = 0x30;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_649a:
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_649f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_64ab;
    sub_ca53();
loc_64ab:
    dl = 0x00;
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryGet(es, bx) == 0x00)
        goto loc_64d1;
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    bx += ax;
    if (memoryGet(es, bx) == 0x19)
        goto loc_64d1;
    dl = 0x01;
loc_64d1:
    al = dl;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_64d5()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_64e1;
    sub_ca53();
loc_64e1:
    dl = 0x00;
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryGet(es, bx + 48) == 0x00)
        goto loc_6509;
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    bx += ax;
    if (memoryGet(es, bx + 48) == 0x13)
        goto loc_6509;
    dl = 0x01;
loc_6509:
    al = dl;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_650d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6519;
    sub_ca53();
loc_6519:
    memorySet(ds, 0x8242, memoryGet(ds, 0x8242) + 1);
    if (memoryGet(ds, 0x8242) != 0x03)
        goto loc_652c;
    memorySet(ds, 0x8242, 0x00);
    sub_4835();
loc_652c:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_652e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_653a;
    sub_ca53();
loc_653a:
    al = memoryGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 14014);
    push(ax);
    sub_658b();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_654d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6559;
    sub_ca53();
loc_6559:
    al = memoryGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 14062);
    push(ax);
    sub_658b();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_656c()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6578;
    sub_ca53();
loc_6578:
    al = memoryGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 14110);
    push(ax);
    sub_658b();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_658b()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6597;
    sub_ca53();
loc_6597:
    al = memoryGet(ss, bp + 4);
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
        case 0: goto loc_65c2;
        case 2: goto loc_65c7;
        case 4: goto loc_65cc;
        case 6: goto loc_65d1;
        default:
        assert(0);
    }
loc_65b1:
    if (ax == 0x0009)
        goto loc_65db;
    if (ax == 0x001a)
        goto loc_65e0;
    if (ax == 0x001b)
        goto loc_65e5;
    goto loc_65ea;
loc_65c2:
    sub_6617();
    goto loc_65f3;
loc_65c7:
    sub_4504();
    goto loc_65f3;
loc_65cc:
    sub_4571();
    goto loc_65f3;
loc_65d1:
    sub_46ae();
    goto loc_65f3;
loc_65d6:
    sub_45dc();
    goto loc_65f3;
loc_65db:
    sub_4646();
    goto loc_65f3;
loc_65e0:
    sub_3e8e();
    goto loc_65f3;
loc_65e5:
    sub_3f4d();
    goto loc_65f3;
loc_65ea:
    al = memoryGet(ss, bp + 4);
    push(ax);
    sub_65fd();
    sp++;
    sp++;
loc_65f3:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_65fd()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6609;
    sub_ca53();
loc_6609:
    al = memoryGet(ss, bp + 4);
    push(ax);
    sub_6133();
    sp++;
    sp++;
    sub_425e();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6617()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6625;
    sub_ca53();
loc_6625:
    if (memoryGet(ds, 0x856e) >= 0x08)
        goto loc_6632;
    memorySet(ss, bp - 2, 0x00);
    goto loc_6653;
loc_6632:
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    es = memoryGet16(ds, 0xa0da);
    ax += memoryGet16(ds, 0xa0d8);
    bx = ax;
    al = memoryGet(es, bx - 8);
    memorySet(ss, bp - 1, al);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 14158);
    memorySet(ss, bp - 2, al);
loc_6653:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    if (ax)
        goto loc_668e;
    if (memoryGet(ds, 0x79b3) <= 0xeb)
        goto loc_6669;
    memorySet(ss, bp - 2, 0x3c);
    goto loc_668e;
loc_6669:
    if (memoryGet(ds, 0x79b3) <= 0xd7)
        goto loc_6676;
    memorySet(ss, bp - 2, 0x3d);
    goto loc_668e;
loc_6676:
    if (memoryGet(ds, 0x79b3) <= 0xc3)
        goto loc_6683;
    memorySet(ss, bp - 2, 0x3e);
    goto loc_668e;
loc_6683:
    if (memoryGet(ds, 0x79b3) <= 0xaf)
        goto loc_668e;
    memorySet(ss, bp - 2, 0x3f);
loc_668e:
    al = memoryGet(ss, bp - 2);
    push(ax);
    sub_65fd();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_669b()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_66a7;
    sub_ca53();
loc_66a7:
    if (!(memoryGet(ds, 0x8244) & 0x04))
        goto loc_66b3;
    sub_4504();
    goto loc_66d0;
loc_66b3:
    if (!(memoryGet(ds, 0x8244) & 0x08))
        goto loc_66bf;
    sub_4571();
    goto loc_66d0;
loc_66bf:
    al = memoryGet(ds, 0x792c);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 14206);
    push(ax);
    sub_658b();
    sp++;
    sp++;
loc_66d0:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_66d2()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_66de;
    sub_ca53();
loc_66de:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_66e9;
    al = 0x03;
    goto loc_66eb;
loc_66e9:
    al = 0x28;
loc_66eb:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
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
void sub_670c()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6718;
    sub_ca53();
loc_6718:
    sub_48da();
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx, 0x0001);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(es, bx + 16, dx);
    memorySet16(es, bx + 18, ax);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 24, 0x0014);
    memorySet16(es, bx + 26, 0x0019);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0014);
    memorySet16(es, bx + 32, 0x0019);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_b288();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6779()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6785;
    sub_ca53();
loc_6785:
    if (memoryGet(ds, 0x8571) == 0xff)
        goto loc_67d4;
    al = memoryGet(ds, 0x8571);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet(ds, 0x8565, al);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    dl = memoryGet(ds, 0x8571);
    dl -= al;
    memorySet(ds, 0x8564, dl);
    al = memoryGet(ds, 0x8571);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 628);
    ax += 0x0007;
    memorySet16(ds, 0x79ba, ax);
    al = memoryGet(ds, 0x8571);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 630);
    ax += 0x0007;
    memorySet16(ds, 0x79bc, ax);
loc_67d4:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_67d6()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_67e2;
    sub_ca53();
loc_67e2:
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet(ds, 0x855c, al);
    al <<= 1;
    al <<= 1;
    al <<= 1;
    dl = memoryGet(ds, 0x856e);
    dl -= al;
    memorySet(ds, 0x855e, dl);
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 628);
    ax += 0x0007;
    memorySet16(ds, 0x9290, ax);
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 630);
    ax += 0x000f;
    memorySet16(ds, 0x9292, ax);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_682c()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6838;
    sub_ca53();
loc_6838:
    memorySet(ds, 0x855d, memoryGet(ds, 0x855d) + 1);
    al = memoryGet(ds, 0x855d);
    if (al != memoryGet(ss, bp + 6))
        goto loc_6856;
    push(memoryGet16(ss, bp + 10));
    push(memoryGet16(ss, bp + 8));
    al = memoryGet(ss, bp + 4);
    push(ax);
    sub_6865();
    sp += 0x0006;
    goto loc_6863;
loc_6856:
    al = memoryGet(ds, 0x855d);
    if (al <= memoryGet(ss, bp + 6))
        goto loc_6863;
    memorySet(ds, 0x855d, 0x00);
loc_6863:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6865()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6871;
    sub_ca53();
loc_6871:
    memorySet(ds, 0x855d, 0x00);
    al = memoryGet(ds, 0xa0dc);
    ah = 0x00;
    ax++;
    dl = memoryGet(ss, bp + 4);
    dh = 0x00;
    if ((short)ax >= (short)dx)
        goto loc_688e;
    memorySet(ds, 0xa0dc, memoryGet(ds, 0xa0dc) + 1);
    al = memoryGet(ds, 0xa0dc);
    goto loc_6893;
loc_688e:
    al = 0x00;
    memorySet(ds, 0xa0dc, al);
loc_6893:
    al = memoryGet(ds, 0xa0dc);
    ah = 0x00;
    ax <<= 1;
    bx = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 6 + 2);
    bx += ax;
    ax = memoryGet16(es, bx);
    memorySet16(ds, 0x824a, ax);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_68a7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_68b5;
    sub_ca53();
loc_68b5:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx, 0x0000);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 16, 0x9694);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 24, 0x0014);
    memorySet16(es, bx + 26, 0x0001);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0014);
    memorySet16(es, bx + 32, 0x0001);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
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
    push(memoryGet16(ds, 0xa0d6));
    push(memoryGet16(ds, 0xa0d4));
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
loc_6949:
    al = 0x19;
    push(ax);
    sub_9984();
    sp++;
    sp++;
    if (al)
        goto loc_6949;
    goto loc_69a2;
loc_6957:
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
    memorySet(ss, bp - 1, 0x01);
    goto loc_698c;
loc_6975:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryGet16(ds, 0x8246);
    es = memoryGet16(ds, 0x8246 + 2);
    bx += ax;
    memorySet(es, bx, 0x01);
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) + 1);
loc_698c:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    dx = 0x0009;
    imul(dx);
    bx = memoryGet16(ds, 0x8246);
    es = memoryGet16(ds, 0x8246 + 2);
    bx += ax;
    if (memoryGet(es, bx) != 0xff)
        goto loc_6975;
loc_69a2:
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
loc_69bc:
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
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 2, 0x9694);
    memorySet16(es, bx + 4, ds);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0001);
    memorySet16(es, bx + 14, 0x0000);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6a1e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6a2c;
    sub_ca53();
loc_6a2c:
    if (memoryGet(ds, 0x8571) == 0xff)
        goto loc_6a92;
    bx = memoryGet16(ds, 0x9b9e);
    es = memoryGet16(ds, 0x9b9e + 2);
    di = memoryGet16(es, bx + 20);
    si = memoryGet16(es, bx + 22);
    ax = memoryGet16(ds, 0x79ba);
    ax -= di;
    cl = 0x04;
    ax = sar(ax, cl);
    ax--;
    memorySet16(ds, 0xa0ca, ax);
    ax = memoryGet16(ds, 0x79bc);
    ax -= si;
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet16(ds, 0xa0cc, ax);
    if ((short)memoryGet16(ds, 0xa0ca) >= (short)0x0000)
        goto loc_6a69;
    memorySet16(ds, 0xa0ca, 0x0000);
    goto loc_6a76;
loc_6a69:
    if ((short)memoryGet16(ds, 0xa0ca) <= (short)0x0012)
        goto loc_6a76;
    memorySet16(ds, 0xa0ca, 0x0012);
loc_6a76:
    if ((short)memoryGet16(ds, 0xa0cc) >= (short)0x0000)
        goto loc_6a85;
    memorySet16(ds, 0xa0cc, 0x0000);
    goto loc_6a92;
loc_6a85:
    if ((short)memoryGet16(ds, 0xa0cc) <= (short)0x0016)
        goto loc_6a92;
    memorySet16(ds, 0xa0cc, 0x0016);
loc_6a92:
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6a96()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6aa5;
    sub_ca53();
loc_6aa5:
    al = memoryGet(ss, bp + 4);
    if (al) {
    memorySet(ds, 0x8562, al);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 9506);
    dx = memoryGet16(ds, bx + 9504);
    memorySet16(ss, bp - 4, dx);
    memorySet16(ss, bp - 2, ax);
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    al = memoryGet(es, bx);
    memorySet(ds, 0xa1b0, al);
    al = memoryGet(es, bx + 1);
    memorySet(ds, 0x9d2f, al);
    ax = memoryGet16(es, bx + 4);
    dx = memoryGet16(es, bx + 2);
    memorySet16(ds, 0xa0ba, dx);
    memorySet16(ds, 0xa0bc, ax);
    }
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6ae4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6af0;
    sub_ca53();
loc_6af0:
    al = memoryGet(ds, 0x8243);
    al ^= 0x01;
    memorySet(ds, 0x8243, al);
    if (memoryGet(ds, 0x8243) == 0x00)
        goto loc_6b67;
    if (memoryGet(ds, 0x8571) == 0xff)
        goto loc_6b67;
    bx = memoryGet16(ds, 0xa0ba);
    es = memoryGet16(ds, 0xa0ba + 2);
    ax = memoryGet16(es, bx);
    memorySet16(ds, 0x8560, ax);
    if (memoryGet(ds, 0x9d2f) == 0x00)
        goto loc_6b2b;
    ax = memoryGet16(es, bx + 2);
    ax = -ax;
    dx = memoryGet16(ds, 0x79ba);
    dx += ax;
    memorySet16(ds, 0x79ba, dx);
    ax = dx;
    goto loc_6b3a;
loc_6b2b:
    bx = memoryGet16(ds, 0xa0ba);
    es = memoryGet16(ds, 0xa0ba + 2);
    ax = memoryGet16(es, bx + 2);
    memorySet16(ds, 0x79ba, memoryGet16(ds, 0x79ba) + ax);
    ax = memoryGet16(ds, 0x79ba);
loc_6b3a:
    bx = memoryGet16(ds, 0xa0ba);
    es = memoryGet16(ds, 0xa0ba + 2);
    ax = memoryGet16(es, bx + 4);
    memorySet16(ds, 0x79bc, memoryGet16(ds, 0x79bc) + ax);
    memorySet16(ds, 0xa0ba, memoryGet16(ds, 0xa0ba) + 0x0006);
    al = memoryGet(ds, 0xa1b0);
    al += 0xff;
    memorySet(ds, 0xa1b0, al);
    ah = 0x00;
    if (ax)
        goto loc_6b60;
    al = 0x00;
    memorySet(ds, 0x8563, al);
    goto loc_6b67;
loc_6b60:
    memorySet(ds, 0x8563, memoryGet(ds, 0x8563) + 1);
    al = memoryGet(ds, 0x8563);
loc_6b67:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6b69()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6b75;
    sub_ca53();
loc_6b75:
    if (memoryGet(ds, 0x8243) != 0x00)
        goto loc_6b7f;
    goto loc_6c8d;
loc_6b7f:
    if (memoryGet(ds, 0x8571) != 0xff)
        goto loc_6b89;
    goto loc_6c8d;
loc_6b89:
    if (memoryGet(ds, 0xa1b0) == 0x00)
        goto loc_6b96;
    sub_6ed3();
    goto loc_6c8d;
loc_6b96:
    al = 0x01;
    memorySet(ds, 0xa1b2, al);
    memorySet(ds, 0xa0e2, al);
    memorySet(ds, 0xa0e1, al);
    memorySet(ds, 0xa0e0, al);
    if (memoryGet(ds, 0x8571) < 0x08)
        goto loc_6bc9;
    al = memoryGet(ds, 0x8571);
    ah = 0x00;
    es = memoryGet16(ds, 0xa0da);
    ax += memoryGet16(ds, 0xa0d8);
    bx = ax;
    al = memoryGet(es, bx - 8);
    ah = 0x00;
    if (ax)
        goto loc_6bc9;
    memorySet(ds, 0xa0e0, 0x00);
loc_6bc9:
    if (memoryGet(ds, 0x8571) >= 0x28)
        goto loc_6be9;
    al = memoryGet(ds, 0x8571);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    ah = 0x00;
    if (ax)
        goto loc_6be9;
    memorySet(ds, 0xa0e1, 0x00);
loc_6be9:
    if (memoryGet(ds, 0x8564) == 0x00)
        goto loc_6c21;
    al = memoryGet(ds, 0x8571);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx + 47);
    ah = 0x00;
    if (ax)
        goto loc_6c21;
    memorySet(ds, 0xa0e2, 0x00);
    al = memoryGet(ds, 0x8571);
    ah = 0x00;
    ax += memoryGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryGet(es, bx - 1) != 0x0b)
        goto loc_6c21;
    memorySet(ds, 0xa0e2, 0x01);
loc_6c21:
    if (memoryGet(ds, 0x8564) == 0x07)
        goto loc_6c59;
    al = memoryGet(ds, 0x8571);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx + 48);
    ah = 0x00;
    if (ax)
        goto loc_6c59;
    memorySet(ds, 0xa1b2, 0x00);
    al = memoryGet(ds, 0x8571);
    ah = 0x00;
    ax += memoryGet16(ds, 0xa0d8);
    bx = ax;
    if (memoryGet(es, bx + 1) != 0x0b)
        goto loc_6c59;
    memorySet(ds, 0xa1b2, 0x01);
loc_6c59:
    al = memoryGet(ds, 0xa0e0);
    ah = 0x00;
    dl = memoryGet(ds, 0xa0e1);
    dh = 0x00;
    ax += dx;
    dl = memoryGet(ds, 0xa0e2);
    dh = 0x00;
    ax += dx;
    dl = memoryGet(ds, 0xa1b2);
    dh = 0x00;
    ax += dx;
    if (ax != 0x0004)
        goto loc_6c80;
    sub_6ea3();
    goto loc_6c8d;
loc_6c80:
    al = memoryGet(ds, 0x8562);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    callIndirect(cs*16+memoryGet16(ds, bx + 2160));
loc_6c8d:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6c8f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6c9b;
    sub_ca53();
loc_6c9b:
    al = memoryGet(ds, 0xa0e0);
    ah = 0x00;
    if (ax)
        goto loc_6ca9;
    sub_6cca();
    goto loc_6cc8;
loc_6ca9:
    al = memoryGet(ds, 0xa1b2);
    ah = 0x00;
    if (ax)
        goto loc_6cb7;
    sub_6e59();
    goto loc_6cc8;
loc_6cb7:
    al = memoryGet(ds, 0xa0e2);
    ah = 0x00;
    if (ax)
        goto loc_6cc5;
    sub_6dd4();
    goto loc_6cc8;
loc_6cc5:
    sub_6d4f();
loc_6cc8:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6cca()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6cd6;
    sub_ca53();
loc_6cd6:
    al = memoryGet(ds, 0x79b3);
    if (al < memoryGet(ds, 0x7920))
        goto loc_6ce3;
    al = 0x01;
    goto loc_6d0c;
loc_6ce3:
    if (!(memoryGet(ds, 0x79b3) & 0x01))
        goto loc_6cff;
    if (memoryGet(ds, 0xa0e2) == 0x00)
        goto loc_6cf5;
    al = 0x01;
    goto loc_6d0c;
loc_6cf5:
    al = 0x03;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6d12;
loc_6cff:
    if (memoryGet(ds, 0xa1b2) == 0x00)
        goto loc_6d0a;
    al = 0x01;
    goto loc_6d0c;
loc_6d0a:
    al = 0x04;
loc_6d0c:
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6d12:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6d14()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6d20;
    sub_ca53();
loc_6d20:
    al = memoryGet(ds, 0xa0e1);
    ah = 0x00;
    if (ax)
        goto loc_6d2e;
    sub_6d4f();
    goto loc_6d4d;
loc_6d2e:
    al = memoryGet(ds, 0xa0e2);
    ah = 0x00;
    if (ax)
        goto loc_6d3c;
    sub_6dd4();
    goto loc_6d4d;
loc_6d3c:
    al = memoryGet(ds, 0xa1b2);
    ah = 0x00;
    if (ax)
        goto loc_6d4a;
    sub_6e59();
    goto loc_6d4d;
loc_6d4a:
    sub_6cca();
loc_6d4d:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6d4f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6d5b;
    sub_ca53();
loc_6d5b:
    al = memoryGet(ds, 0x79b3);
    if (al < memoryGet(ds, 0x7920))
        goto loc_6d68;
    al = 0x02;
    goto loc_6d91;
loc_6d68:
    if (!(memoryGet(ds, 0x79b3) & 0x01))
        goto loc_6d84;
    if (memoryGet(ds, 0xa0e2) == 0x00)
        goto loc_6d7a;
    al = 0x02;
    goto loc_6d91;
loc_6d7a:
    al = 0x03;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6d97;
loc_6d84:
    if (memoryGet(ds, 0xa1b2) == 0x00)
        goto loc_6d8f;
    al = 0x02;
    goto loc_6d91;
loc_6d8f:
    al = 0x04;
loc_6d91:
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6d97:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6d99()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6da5;
    sub_ca53();
loc_6da5:
    al = memoryGet(ds, 0xa0e2);
    ah = 0x00;
    if (ax)
        goto loc_6db3;
    sub_6dd4();
    goto loc_6dd2;
loc_6db3:
    al = memoryGet(ds, 0xa0e0);
    ah = 0x00;
    if (ax)
        goto loc_6dc1;
    sub_6cca();
    goto loc_6dd2;
loc_6dc1:
    al = memoryGet(ds, 0xa0e1);
    ah = 0x00;
    if (ax)
        goto loc_6dcf;
    sub_6d4f();
    goto loc_6dd2;
loc_6dcf:
    sub_6e59();
loc_6dd2:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6dd4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6de0;
    sub_ca53();
loc_6de0:
    al = memoryGet(ds, 0x79b3);
    if (al < memoryGet(ds, 0x7920))
        goto loc_6ded;
    al = 0x03;
    goto loc_6e16;
loc_6ded:
    if (!(memoryGet(ds, 0x79b3) & 0x01))
        goto loc_6e09;
    if (memoryGet(ds, 0xa0e0) == 0x00)
        goto loc_6dff;
    al = 0x03;
    goto loc_6e16;
loc_6dff:
    al = 0x01;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6e1c;
loc_6e09:
    if (memoryGet(ds, 0xa0e1) == 0x00)
        goto loc_6e14;
    al = 0x03;
    goto loc_6e16;
loc_6e14:
    al = 0x02;
loc_6e16:
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6e1c:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6e1e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6e2a;
    sub_ca53();
loc_6e2a:
    al = memoryGet(ds, 0xa1b2);
    ah = 0x00;
    if (ax)
        goto loc_6e38;
    sub_6e59();
    goto loc_6e57;
loc_6e38:
    al = memoryGet(ds, 0xa0e1);
    ah = 0x00;
    if (ax)
        goto loc_6e46;
    sub_6d4f();
    goto loc_6e57;
loc_6e46:
    al = memoryGet(ds, 0xa0e0);
    ah = 0x00;
    if (ax)
        goto loc_6e54;
    sub_6cca();
    goto loc_6e57;
loc_6e54:
    sub_6dd4();
loc_6e57:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6e59()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6e65;
    sub_ca53();
loc_6e65:
    al = memoryGet(ds, 0x79b3);
    if (al < memoryGet(ds, 0x7920))
        goto loc_6e72;
    al = 0x04;
    goto loc_6e9b;
loc_6e72:
    if (!(memoryGet(ds, 0x79b3) & 0x01))
        goto loc_6e8e;
    if (memoryGet(ds, 0xa0e0) == 0x00)
        goto loc_6e84;
    al = 0x04;
    goto loc_6e9b;
loc_6e84:
    al = 0x01;
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    goto loc_6ea1;
loc_6e8e:
    if (memoryGet(ds, 0xa0e1) == 0x00)
        goto loc_6e99;
    al = 0x04;
    goto loc_6e9b;
loc_6e99:
    al = 0x02;
loc_6e9b:
    push(ax);
    sub_6a96();
    sp++;
    sp++;
loc_6ea1:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6ea3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6eb1;
    sub_ca53();
loc_6eb1:
    al = memoryGet(ds, 0x79b3);
    al &= 0x03;
    memorySet(ss, bp - 2, al);
    sub_b281();
    memorySet(ds, 0x79b3, al);
    al &= 0x01;
    al += memoryGet(ss, bp - 2);
    al += 0x05;
    memorySet(ss, bp - 1, al);
    push(ax);
    sub_6a96();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6ed3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6edf;
    sub_ca53();
loc_6edf:
    if (memoryGet(ds, 0x8563) != 0x05)
        goto loc_6ef3;
    al = memoryGet(ds, 0x8562);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    callIndirect(cs*16+memoryGet16(ds, bx + 2140));
loc_6ef3:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6ef5()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6f01;
    sub_ca53();
loc_6f01:
    al = memoryGet(ds, 0x8571);
    al += 0xf8;
    memorySet(ds, 0x8571, al);
    memorySet(ds, 0x8565, memoryGet(ds, 0x8565) - 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6f0f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6f1b;
    sub_ca53();
loc_6f1b:
    al = memoryGet(ds, 0x8571);
    al += 0x08;
    memorySet(ds, 0x8571, al);
    memorySet(ds, 0x8565, memoryGet(ds, 0x8565) + 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6f29()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6f35;
    sub_ca53();
loc_6f35:
    memorySet(ds, 0x8571, memoryGet(ds, 0x8571) - 1);
    memorySet(ds, 0x8564, memoryGet(ds, 0x8564) - 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6f3f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6f4b;
    sub_ca53();
loc_6f4b:
    memorySet(ds, 0x8571, memoryGet(ds, 0x8571) + 1);
    memorySet(ds, 0x8564, memoryGet(ds, 0x8564) + 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6f55()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6f61;
    sub_ca53();
loc_6f61:
    al = memoryGet(ds, 0xa0ce);
    ah = 0x00;
    if (ax)
        goto loc_6f8e;
    ax = memoryGet16(ds, 0x9290);
    ax += 0xfffb;
    memorySet16(ds, 0x084c, ax);
    ax = memoryGet16(ds, 0x9290);
    ax += 0x0006;
    memorySet16(ds, 0x084e, ax);
    ax = memoryGet16(ds, 0x9292);
    ax += 0xfffb;
    memorySet16(ds, 0x0850, ax);
    ax = memoryGet16(ds, 0x9292);
    ax += 0x0005;
    memorySet16(ds, 0x0852, ax);
loc_6f8e:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6f90()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6f9c;
    sub_ca53();
loc_6f9c:
    al = memoryGet(ds, 0xa0ce);
    ah = 0x00;
    if (ax)
        goto loc_6fc9;
    ax = memoryGet16(ds, 0x79ba);
    ax += 0xfffb;
    memorySet16(ds, 0x0854, ax);
    ax = memoryGet16(ds, 0x79ba);
    ax += 0x0006;
    memorySet16(ds, 0x0856, ax);
    ax = memoryGet16(ds, 0x79bc);
    ax += 0xfffb;
    memorySet16(ds, 0x0858, ax);
    ax = memoryGet16(ds, 0x79bc);
    ax += 0x0005;
    memorySet16(ds, 0x085a, ax);
loc_6fc9:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_6fcb()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_6fd7;
    sub_ca53();
loc_6fd7:
    if (memoryGet(ds, 0x8571) == 0xff)
        goto loc_704f;
    al = memoryGet(ds, 0xa0ce);
    ah = 0x00;
    if (ax)
        goto loc_704f;
    al = memoryGet(ds, 0x856d);
    ah = 0x00;
    if (ax)
        goto loc_704f;
    if (memoryGet(ds, 0x792c) == 0x30)
        goto loc_704f;
    ax = memoryGet16(ds, 0x0854);
    if ((short)ax <= (short)memoryGet16(ds, 0x084e))
        goto loc_7007;
    memorySet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7007:
    ax = memoryGet16(ds, 0x084c);
    if ((short)ax <= (short)memoryGet16(ds, 0x0856))
        goto loc_7017;
    memorySet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7017:
    ax = memoryGet16(ds, 0x0858);
    if ((short)ax <= (short)memoryGet16(ds, 0x0852))
        goto loc_7027;
    memorySet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7027:
    ax = memoryGet16(ds, 0x0850);
    if ((short)ax <= (short)memoryGet16(ds, 0x085a))
        goto loc_7037;
    memorySet(ds, 0xa1aa, 0x00);
    goto loc_704f;
loc_7037:
    memorySet(ds, 0xa1aa, 0x01);
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_7047;
    al = 0x03;
    goto loc_7049;
loc_7047:
    al = 0x0d;
loc_7049:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_704f:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7051()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_705d;
    sub_ca53();
loc_705d:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    ax = memoryGet16(ss, bp + 4);
    memorySet16(es, bx, ax);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    ax = memoryGet16(ss, bp + 6);
    memorySet16(es, bx + 14, ax);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0014);
    memorySet16(es, bx + 32, 0x0019);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_b298();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_70a8()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_70b4;
    sub_ca53();
loc_70b4:
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    dx += 0x0063;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 16, 0x9d3a);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 24, 0x0003);
    memorySet16(es, bx + 26, 0x0002);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0003);
    memorySet16(es, bx + 32, 0x0002);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 6, 0x0004);
    memorySet16(es, bx + 16, 0x9baf);
    memorySet16(es, bx + 18, ds);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0008);
    memorySet16(es, bx + 16, 0x9eba);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 24, 0x0001);
    memorySet16(es, bx + 26, 0x0004);
    memorySet16(es, bx + 30, 0x0001);
    memorySet16(es, bx + 32, 0x0004);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 8, 0x0003);
    memorySet16(es, bx + 16, 0x9fba);
    memorySet16(es, bx + 18, ds);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x000d);
    memorySet16(es, bx + 16, 0x8b88);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 24, 0x0006);
    memorySet16(es, bx + 26, 0x0002);
    memorySet16(es, bx + 30, 0x0006);
    memorySet16(es, bx + 32, 0x0002);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 8, 0x0011);
    memorySet16(es, bx + 16, 0x824e);
    memorySet16(es, bx + 18, ds);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 8, 0x0015);
    memorySet16(es, bx + 16, 0x8582);
    memorySet16(es, bx + 18, ds);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f7c();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_722e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_723a;
    sub_ca53();
loc_723a:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet(es, bx + 34, 0x00);
    memorySet(es, bx + 35, 0x00);
    memorySet(es, bx + 36, 0x00);
    memorySet(es, bx + 37, 0x00);
    bx = memoryGet16(ds, 0x08b8);
    es = memoryGet16(ds, 0x08b8 + 2);
    memorySet16(es, bx, 0x0001);
    memorySet16(es, bx + 16, 0x8e8d);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 24, 0x0004);
    memorySet16(es, bx + 26, 0x0004);
    memorySet16(es, bx + 28, 0x0000);
    bx = memoryGet16(ds, 0x08ec);
    es = memoryGet16(ds, 0x08ec + 2);
    memorySet16(es, bx, 0x0001);
    memorySet16(es, bx + 16, 0x9294);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 24, 0x0004);
    memorySet16(es, bx + 26, 0x0004);
    memorySet16(es, bx + 28, 0x0000);
    bx = memoryGet16(ds, 0x08bc);
    es = memoryGet16(ds, 0x08bc + 2);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0001);
    memorySet16(es, bx + 12, 0x0004);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0001);
    memorySet16(es, bx + 32, 0x0004);
    bx = memoryGet16(ds, 0x08c0);
    es = memoryGet16(ds, 0x08c0 + 2);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0003);
    memorySet16(es, bx + 12, 0x0002);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0002);
    memorySet16(es, bx + 32, 0x0002);
    bx = memoryGet16(ds, 0x08c4);
    es = memoryGet16(ds, 0x08c4 + 2);
    memorySet16(es, bx + 2, 0x8e8d);
    memorySet16(es, bx + 4, ds);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0004);
    memorySet16(es, bx + 12, 0x0004);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 28, 0x0000);
    bx = memoryGet16(ds, 0x08e8);
    es = memoryGet16(ds, 0x08e8 + 2);
    memorySet16(es, bx + 2, 0x9294);
    memorySet16(es, bx + 4, ds);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0004);
    memorySet16(es, bx + 12, 0x0004);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 28, 0x0000);
    bx = memoryGet16(ds, 0x08c8);
    es = memoryGet16(ds, 0x08c8 + 2);
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 16, 0x8888);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 24, 0x0003);
    memorySet16(es, bx + 26, 0x0004);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0001);
    memorySet16(es, bx + 32, 0x0004);
    bx = memoryGet16(ds, 0x08cc);
    es = memoryGet16(ds, 0x08cc + 2);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 12, 0x0004);
    memorySet16(es, bx + 16, 0x8888);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 24, 0x0003);
    memorySet16(es, bx + 26, 0x0004);
    memorySet16(es, bx + 30, 0x0001);
    memorySet16(es, bx + 32, 0x0004);
    bx = memoryGet16(ds, 0x08d0);
    es = memoryGet16(ds, 0x08d0 + 2);
    memorySet16(es, bx, 0x0001);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 24, 0x0001);
    memorySet16(es, bx + 26, 0x0004);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0001);
    memorySet16(es, bx + 32, 0x0004);
    bx = memoryGet16(ds, 0x08d4);
    es = memoryGet16(ds, 0x08d4 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 30, 0x0002);
    memorySet16(es, bx + 32, 0x0002);
    bx = memoryGet16(ds, 0x08d8);
    es = memoryGet16(ds, 0x08d8 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 16, 0x8888);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 24, 0x0003);
    memorySet16(es, bx + 26, 0x0004);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0003);
    memorySet16(es, bx + 32, 0x0002);
    bx = memoryGet16(ds, 0x08dc);
    es = memoryGet16(ds, 0x08dc + 2);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0003);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 16, 0x8888);
    memorySet16(es, bx + 18, ds);
    memorySet16(es, bx + 24, 0x0003);
    memorySet16(es, bx + 26, 0x0004);
    memorySet16(es, bx + 30, 0x0003);
    memorySet16(es, bx + 32, 0x0002);
    bx = memoryGet16(ds, 0x08e0);
    es = memoryGet16(ds, 0x08e0 + 2);
    memorySet16(es, bx, 0x0001);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 24, 0x0003);
    memorySet16(es, bx + 26, 0x0002);
    memorySet16(es, bx + 30, 0x0003);
    memorySet16(es, bx + 32, 0x0002);
    bx = memoryGet16(ds, 0x08e4);
    es = memoryGet16(ds, 0x08e4 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 32, 0x0002);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7551()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    push(si);
    push(di);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_7562;
    sub_ca53();
loc_7562:
    push(ds);
    ax = 0x0928;
    push(ax);
    sub_91d7();
    sp += 0x0004;
    ax = memoryGet16(ds, 0x7928);
    dx = memoryGet16(ds, 0x7926);
    memorySet16(ds, 0x857e, dx);
    memorySet16(ds, 0x8580, ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0003;
    push(ax);
    sub_923f();
    sp += 0x0004;
    si = ax;
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x094e));
    push(memoryGet16(ds, 0x094c));
    push(memoryGet16(ds, 0x8580));
    push(memoryGet16(ds, 0x857e));
    push(si);
    sub_932e();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    push(si);
    sub_91e9();
    sp++;
    sp++;
    ax = 0;
    dx = 0x7d63;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    push(memoryGet16(ds, 0x8580));
    push(memoryGet16(ds, 0x857e));
    sub_9a2a();
    sp += 0x000c;
    if (memoryGet16(ds, 0x541d) != 0x0001)
        goto loc_760a;
    ax = memoryGet16(ds, 0x8580);
    dx = memoryGet16(ds, 0x857e);
    memorySet16(ds, 0x9b96, dx);
    memorySet16(ds, 0x9b98, ax);
    memorySet(ss, bp - 5, 0x00);
    goto loc_7604;
loc_75e7:
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9b96);
    es = memoryGet16(ds, 0x9b96 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    di = ax;
    al = memoryGet(ds, di + 1822);
    memorySet(es, bx + 35, al);
    memorySet(ss, bp - 5, memoryGet(ss, bp - 5) + 1);
loc_7604:
    if (memoryGet(ss, bp - 5) < 0x10)
        goto loc_75e7;
loc_760a:
    sub_5337();
    ax = memoryGet16(ds, 0x8580);
    dx = memoryGet16(ds, 0x857e);
    dx += 0x0063;
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet16(es, bx + 6, 0x0000);
    memorySet16(es, bx + 8, 0x0000);
    memorySet16(es, bx + 10, 0x0014);
    memorySet16(es, bx + 12, 0x0019);
    memorySet16(es, bx + 14, 0x0001);
    memorySet16(es, bx + 20, 0x0000);
    memorySet16(es, bx + 22, 0x0000);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0014);
    memorySet16(es, bx + 32, 0x0019);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9f8c();
    sp += 0x0004;
    ax = 0;
    push(ax);
    push(memoryGet16(ds, 0x8580));
    push(memoryGet16(ds, 0x857e));
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
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 14, 0x0000);
    memorySet16(es, bx + 30, 0x0001);
    memorySet16(es, bx + 32, 0x0002);
    sub_76b1();
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_76b1()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_76c0;
    sub_ca53();
loc_76c0:
    ax = 0;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    memorySet(ss, bp - 9, 0x00);
    memorySet(ss, bp - 1, 0x00);
    goto loc_7879;
loc_76d3:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x08f0;
    memorySet16(ds, 0x8574, ax);
    memorySet16(ds, 0x8576, ds);
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    ax = memoryGet16(es, bx + 6);
    dx = memoryGet16(es, bx + 4);
    if (ax <= memoryGet16(ds, 0xa0d6))
        goto loc_76fd;
    goto loc_77d1;
loc_76fd:
    if (ax < memoryGet16(ds, 0xa0d6))
        goto loc_7708;
    if (dx < memoryGet16(ds, 0xa0d4))
        goto loc_7708;
    goto loc_77d1;
loc_7708:
    al = memoryGet(ss, bp - 9);
    ah = 0x00;
    if (!ax)
        goto loc_7714;
    goto loc_77d1;
loc_7714:
    memorySet(ss, bp - 9, 0x01);
    al = memoryGet(ss, bp - 1);
    memorySet(ss, bp - 2, al);
    ax = memoryGet16(ds, 0x0922);
    dx = memoryGet16(ds, 0x0920);
    memorySet16(ss, bp - 6, dx);
    memorySet16(ss, bp - 4, ax);
    memorySet(ss, bp - 10, 0x06);
    goto loc_7784;
loc_7731:
    al = memoryGet(ss, bp - 10);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 2282);
    dx = memoryGet16(ds, bx + 2280);
    bl = memoryGet(ss, bp - 10);
    bh = 0x00;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    memorySet16(ds, bx + 2288, dx);
    memorySet16(ds, bx + 2290, ax);
    al = memoryGet(ss, bp - 10);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 2286);
    dx = memoryGet16(ds, bx + 2284);
    bl = memoryGet(ss, bp - 10);
    bh = 0x00;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    memorySet16(ds, bx + 2292, dx);
    memorySet16(ds, bx + 2294, ax);
    memorySet(ss, bp - 10, memoryGet(ss, bp - 10) - 1);
loc_7784:
    al = memoryGet(ss, bp - 10);
    if (al > memoryGet(ss, bp - 1))
        goto loc_7731;
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    ax = memoryGet16(ss, bp - 4);
    dx = memoryGet16(ss, bp - 6);
    memorySet16(es, bx, dx);
    memorySet16(es, bx + 2, ax);
    memorySet(ss, bp - 10, 0x00);
    goto loc_77b8;
loc_77a3:
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryGet16(es, tx);
    es = memoryGet16(es, tx + 2);
    al = memoryGet(ss, bp - 10);
    ah = 0x00;
    bx += ax;
    memorySet(es, bx, 0x41);
    memorySet(ss, bp - 10, memoryGet(ss, bp - 10) + 1);
loc_77b8:
    if (memoryGet(ss, bp - 10) < 0x08)
        goto loc_77a3;
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    ax = memoryGet16(ds, 0xa0d6);
    dx = memoryGet16(ds, 0xa0d4);
    memorySet16(es, bx + 4, dx);
    memorySet16(es, bx + 6, ax);
loc_77d1:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0041;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 2, ax);
    memorySet(ss, bp - 7, 0x00);
    goto loc_784a;
loc_77eb:
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryGet16(es, tx);
    es = memoryGet16(es, tx + 2);
    al = memoryGet(ss, bp - 7);
    ah = 0x00;
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ss, bp - 8, al);
    if (al != 0x2e)
        goto loc_781a;
    if (memoryGet(ss, bp - 9) == 0x00)
        goto loc_7815;
    al = memoryGet(ss, bp - 2);
    if (al != memoryGet(ss, bp - 1))
        goto loc_7815;
    al = 0x5b;
    goto loc_7817;
loc_7815:
    al = 0x20;
loc_7817:
    memorySet(ss, bp - 8, al);
loc_781a:
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    al = memoryGet(ss, bp - 8);
    ah = 0x00;
    ax += 0x0175;
    memorySet16(es, bx + 4, ax);
    al = memoryGet(ss, bp - 7);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memorySet16(es, bx, ax);
    if (memoryGet(ss, bp - 8) == 0x20)
        goto loc_7847;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_7847:
    memorySet(ss, bp - 7, memoryGet(ss, bp - 7) + 1);
loc_784a:
    if (memoryGet(ss, bp - 7) < 0x08)
        goto loc_77eb;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    ax += 0x0041;
    push(ax);
    ax = 0x00b0;
    push(ax);
    al = 0x07;
    push(ax);
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    push(memoryGet16(es, bx + 6));
    push(memoryGet16(es, bx + 4));
    sub_7f0d();
    sp += 0x000a;
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) + 1);
loc_7879:
    if (memoryGet(ss, bp - 1) >= 0x07)
        goto loc_7882;
    goto loc_76d3;
loc_7882:
    if (memoryGet(ss, bp - 9) == 0x00)
        goto loc_7893;
    al = memoryGet(ss, bp - 2);
    push(ax);
    sub_78a3();
    sp++;
    sp++;
    goto loc_7896;
loc_7893:
    sub_515f();
loc_7896:
    ax = 0x0001;
    push(ax);
    sub_b2e0();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_78a3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0006;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_78b2;
    sub_ca53();
loc_78b2:
    memorySet(ss, bp - 2, 0x00);
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x08f0;
    memorySet16(ds, 0x8574, ax);
    memorySet16(ds, 0x8576, ds);
    memorySet16(ss, bp - 6, 0x01b6);
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryGet16(es, tx);
    es = memoryGet16(es, tx + 2);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    memorySet(es, bx, 0x41);
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    memorySet16(es, bx + 20, ax);
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax += 0x0008;
    memorySet16(es, bx + 22, ax);
    al = 0x01;
    push(ax);
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_791a:
    bumpyScene = "highscores";
    if (!(memoryGet(ss, bp - 1) & 0x01))
        goto loc_7984;
    if ((short)memoryGet16(ss, bp - 6) <= (short)0x01ac)
        goto loc_7984;
    memorySet16(ss, bp - 6, memoryGet16(ss, bp - 6) - 1);
    if (memoryGet16(ss, bp - 6) != 0x01d0)
        goto loc_7936;
    memorySet16(ss, bp - 6, 0x01a3);
loc_7936:
    ax = memoryGet16(ss, bp - 6);
    ax += 0xfe8b;
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryGet16(es, tx);
    es = memoryGet16(es, tx + 2);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryGet(ss, bp - 6);
    memorySet(es, bx, al);
    if (memoryGet16(ss, bp - 6) != 0x002e)
        goto loc_795e;
    memorySet16(ss, bp - 6, 0x005b);
loc_795e:
    ax = memoryGet16(ss, bp - 6);
    ax += 0x0175;
    memorySet16(ss, bp - 6, ax);
    al = 0x01;
    push(ax);
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_7984:
    if (!(memoryGet(ss, bp - 1) & 0x02))
        goto loc_79ee;
    if ((short)memoryGet16(ss, bp - 6) >= (short)0x01d0)
        goto loc_79ee;
    memorySet16(ss, bp - 6, memoryGet16(ss, bp - 6) + 1);
    if (memoryGet16(ss, bp - 6) != 0x01d0)
        goto loc_79a0;
    memorySet16(ss, bp - 6, 0x01a3);
loc_79a0:
    ax = memoryGet16(ss, bp - 6);
    ax += 0xfe8b;
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryGet16(es, tx);
    es = memoryGet16(es, tx + 2);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryGet(ss, bp - 6);
    memorySet(es, bx, al);
    if (memoryGet16(ss, bp - 6) != 0x002e)
        goto loc_79c8;
    memorySet16(ss, bp - 6, 0x005b);
loc_79c8:
    ax = memoryGet16(ss, bp - 6);
    ax += 0x0175;
    memorySet16(ss, bp - 6, ax);
    al = 0x01;
    push(ax);
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_79ee:
    if (memoryGet(ss, bp - 1) & 0x04)
        goto loc_79f7;
    goto loc_7a7b;
loc_79f7:
    if (memoryGet(ss, bp - 2) == 0x00)
        goto loc_7a7b;
    if (memoryGet16(ss, bp - 6) != 0x01d0)
        goto loc_7a09;
    memorySet16(ss, bp - 6, 0x01a3);
loc_7a09:
    ax = memoryGet16(ss, bp - 6);
    ax += 0xfe8b;
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryGet16(es, tx);
    es = memoryGet16(es, tx + 2);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryGet(ss, bp - 6);
    memorySet(es, bx, al);
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) - 1);
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryGet16(es, tx);
    es = memoryGet16(es, tx + 2);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryGet(es, bx);
    ah = 0x00;
    memorySet16(ss, bp - 6, ax);
    if (memoryGet16(ss, bp - 6) != 0x002e)
        goto loc_7a4a;
    memorySet16(ss, bp - 6, 0x005b);
loc_7a4a:
    ax = memoryGet16(ss, bp - 6);
    ax += 0x0175;
    memorySet16(ss, bp - 6, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_7a7b:
    if (memoryGet(ss, bp - 1) & 0x08)
        goto loc_7a84;
    goto loc_7b07;
loc_7a84:
    if (memoryGet(ss, bp - 2) >= 0x07)
        goto loc_7b07;
    if (memoryGet16(ss, bp - 6) != 0x01d0)
        goto loc_7a96;
    memorySet16(ss, bp - 6, 0x01a3);
loc_7a96:
    ax = memoryGet16(ss, bp - 6);
    ax += 0xfe8b;
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryGet16(es, tx);
    es = memoryGet16(es, tx + 2);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryGet(ss, bp - 6);
    memorySet(es, bx, al);
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
    bx = memoryGet16(ds, 0x8574);
    es = memoryGet16(ds, 0x8574 + 2);
    tx = bx;
    bx = memoryGet16(es, tx);
    es = memoryGet16(es, tx + 2);
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx += ax;
    al = memoryGet(es, bx);
    ah = 0x00;
    memorySet16(ss, bp - 6, ax);
    if (memoryGet16(ss, bp - 6) != 0x002e)
        goto loc_7ad7;
    memorySet16(ss, bp - 6, 0x005b);
loc_7ad7:
    ax = memoryGet16(ss, bp - 6);
    ax += 0x0175;
    memorySet16(ss, bp - 6, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryGet16(ss, bp - 6));
    al = memoryGet(ss, bp - 2);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    al += 0x41;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7b30;
loc_7b07:
    memorySet(ss, bp - 3, memoryGet(ss, bp - 3) + 1);
    if (!(memoryGet(ss, bp - 3) & 0x08))
        goto loc_7b1d;
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9a1a();
    goto loc_7b25;
loc_7b1d:
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
loc_7b25:
    sp += 0x0004;
    al = 0x01;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
loc_7b30:
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    memorySet(ss, bp - 1, al);
    ah = 0x00;
    ax &= 0x0010;
    if (ax == 0x0010)
        goto loc_7b48;
    goto loc_791a;
loc_7b48:
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7b57()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0014;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_7b66;
    sub_ca53();
loc_7b66:
    push(ss);
    ax = bp - 0xa;
    push(ax);
    push(ds);
    ax = 0x256a;
    push(ax);
    cx = 0x0004;
    sub_c8c5();
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    memorySet16(es, bx + 14, 0x0000);
    memorySet16(es, bx + 28, 0x0000);
    memorySet16(es, bx + 30, 0x0001);
    memorySet16(es, bx + 32, 0x0002);
    al = 0x00;
    memorySet(ss, bp - 6, al);
    memorySet(ss, bp - 3, al);
    ax = memoryGet16(ss, bp - 8);
    dx = memoryGet16(ss, bp - 10);
    memorySet16(ss, bp - 14, dx);
    memorySet16(ss, bp - 12, ax);
    memorySet(ss, bp - 2, 0x00);
    goto loc_7bbd;
loc_7bac:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 14);
    es = memoryGet16(ss, bp - 14 + 2);
    bx += ax;
    memorySet(es, bx, 0x41);
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
loc_7bbd:
    if (memoryGet(ss, bp - 2) < 0x06)
        goto loc_7bac;
    memorySet16(ss, bp - 20, 0x01b6);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 14);
    es = memoryGet16(ss, bp - 14 + 2);
    bx += ax;
    memorySet(es, bx, 0x41);
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    al = memoryGet(ss, bp + 6);
    ah = 0x00;
    memorySet16(es, bx + 20, ax);
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    memorySet16(es, bx + 22, ax);
    al = 0x01;
    push(ax);
    push(memoryGet16(ss, bp - 20));
    al = memoryGet(ss, bp + 6);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7c09:
    if (!(memoryGet(ss, bp - 1) & 0x01))
        goto loc_7c6d;
    if ((short)memoryGet16(ss, bp - 20) <= (short)0x01ac)
        goto loc_7c6d;
    memorySet16(ss, bp - 20, memoryGet16(ss, bp - 20) - 1);
    if (memoryGet16(ss, bp - 20) != 0x01d0)
        goto loc_7c25;
    memorySet16(ss, bp - 20, 0x01a3);
loc_7c25:
    ax = memoryGet16(ss, bp - 20);
    ax += 0xfe8b;
    memorySet16(ss, bp - 20, ax);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 14);
    es = memoryGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 20);
    memorySet(es, bx, al);
    if (memoryGet16(ss, bp - 20) != 0x002e)
        goto loc_7c49;
    memorySet16(ss, bp - 20, 0x005b);
loc_7c49:
    ax = memoryGet16(ss, bp - 20);
    ax += 0x0175;
    memorySet16(ss, bp - 20, ax);
    al = 0x01;
    push(ax);
    push(memoryGet16(ss, bp - 20));
    al = memoryGet(ss, bp + 6);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7c6d:
    if (!(memoryGet(ss, bp - 1) & 0x02))
        goto loc_7cd1;
    if ((short)memoryGet16(ss, bp - 20) >= (short)0x01d0)
        goto loc_7cd1;
    memorySet16(ss, bp - 20, memoryGet16(ss, bp - 20) + 1);
    if (memoryGet16(ss, bp - 20) != 0x01d0)
        goto loc_7c89;
    memorySet16(ss, bp - 20, 0x01a3);
loc_7c89:
    ax = memoryGet16(ss, bp - 20);
    ax += 0xfe8b;
    memorySet16(ss, bp - 20, ax);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 14);
    es = memoryGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 20);
    memorySet(es, bx, al);
    if (memoryGet16(ss, bp - 20) != 0x002e)
        goto loc_7cad;
    memorySet16(ss, bp - 20, 0x005b);
loc_7cad:
    ax = memoryGet16(ss, bp - 20);
    ax += 0x0175;
    memorySet16(ss, bp - 20, ax);
    al = 0x01;
    push(ax);
    push(memoryGet16(ss, bp - 20));
    al = memoryGet(ss, bp + 6);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7cd1:
    if (!(memoryGet(ss, bp - 1) & 0x04))
        goto loc_7d54;
    if (memoryGet(ss, bp - 3) == 0x00)
        goto loc_7d54;
    if (memoryGet16(ss, bp - 20) != 0x01d0)
        goto loc_7ce9;
    memorySet16(ss, bp - 20, 0x01a3);
loc_7ce9:
    ax = memoryGet16(ss, bp - 20);
    ax += 0xfe8b;
    memorySet16(ss, bp - 20, ax);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 14);
    es = memoryGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 20);
    memorySet(es, bx, al);
    memorySet(ss, bp - 3, memoryGet(ss, bp - 3) - 1);
    memorySet(ss, bp + 6, memoryGet(ss, bp + 6) - 1);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 14);
    bx += ax;
    al = memoryGet(es, bx);
    ah = 0x00;
    memorySet16(ss, bp - 20, ax);
    if (memoryGet16(ss, bp - 20) != 0x002e)
        goto loc_7d25;
    memorySet16(ss, bp - 20, 0x005b);
loc_7d25:
    ax = memoryGet16(ss, bp - 20);
    ax += 0x0175;
    memorySet16(ss, bp - 20, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryGet16(ss, bp - 20));
    al = memoryGet(ss, bp + 6);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7d54:
    if (!(memoryGet(ss, bp - 1) & 0x08))
        goto loc_7dd6;
    if (memoryGet(ss, bp - 3) >= 0x05)
        goto loc_7dd6;
    if (memoryGet16(ss, bp - 20) != 0x01d0)
        goto loc_7d6c;
    memorySet16(ss, bp - 20, 0x01a3);
loc_7d6c:
    ax = memoryGet16(ss, bp - 20);
    ax += 0xfe8b;
    memorySet16(ss, bp - 20, ax);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 14);
    es = memoryGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryGet(ss, bp - 20);
    memorySet(es, bx, al);
    memorySet(ss, bp - 3, memoryGet(ss, bp - 3) + 1);
    memorySet(ss, bp + 6, memoryGet(ss, bp + 6) + 1);
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 14);
    bx += ax;
    al = memoryGet(es, bx);
    ah = 0x00;
    memorySet16(ss, bp - 20, ax);
    if (memoryGet16(ss, bp - 20) != 0x002e)
        goto loc_7da8;
    memorySet16(ss, bp - 20, 0x005b);
loc_7da8:
    ax = memoryGet16(ss, bp - 20);
    ax += 0x0175;
    memorySet16(ss, bp - 20, ax);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    push(ax);
    push(memoryGet16(ss, bp - 20));
    al = memoryGet(ss, bp + 6);
    push(ax);
    al = memoryGet(ss, bp + 4);
    cl = 0x04;
    al <<= cl;
    push(ax);
    sub_7eab();
    sp += 0x0008;
    goto loc_7dff;
loc_7dd6:
    memorySet(ss, bp - 6, memoryGet(ss, bp - 6) + 1);
    if (!(memoryGet(ss, bp - 6) & 0x08))
        goto loc_7dec;
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9a1a();
    goto loc_7df4;
loc_7dec:
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
loc_7df4:
    sp += 0x0004;
    al = 0x01;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
loc_7dff:
    al = 0x00;
    push(ax);
    sub_9472();
    sp++;
    sp++;
    memorySet(ss, bp - 1, al);
    ah = 0x00;
    ax &= 0x0010;
    if (ax == 0x0010)
        goto loc_7e17;
    goto loc_7c09;
loc_7e17:
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    al = 0x00;
    memorySet(ss, bp - 4, al);
    memorySet(ss, bp - 2, al);
    goto loc_7e95;
loc_7e2c:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 4958);
    dx = memoryGet16(ds, bx + 4956);
    memorySet16(ss, bp - 18, dx);
    memorySet16(ss, bp - 16, ax);
    al = 0x00;
    memorySet(ss, bp - 5, al);
    memorySet(ss, bp - 3, al);
    goto loc_7e72;
loc_7e4f:
    al = memoryGet(ss, bp - 3);
    ah = 0x00;
    bx = memoryGet16(ss, bp - 14);
    es = memoryGet16(ss, bp - 14 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    dl = memoryGet(ss, bp - 3);
    dh = 0x00;
    bx = memoryGet16(ss, bp - 18);
    es = memoryGet16(ss, bp - 18 + 2);
    bx += dx;
    if (al == memoryGet(es, bx))
        goto loc_7e6f;
    memorySet(ss, bp - 5, 0x01);
loc_7e6f:
    memorySet(ss, bp - 3, memoryGet(ss, bp - 3) + 1);
loc_7e72:
    if (memoryGet(ss, bp - 3) >= 0x06)
        goto loc_7e81;
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    if (!ax)
        goto loc_7e4f;
loc_7e81:
    al = memoryGet(ss, bp - 5);
    ah = 0x00;
    if (ax)
        goto loc_7e92;
    al = memoryGet(ss, bp - 2);
    al += 0x02;
    memorySet(ss, bp - 4, al);
loc_7e92:
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
loc_7e95:
    if (memoryGet(ss, bp - 2) >= 0x08)
        goto loc_7ea4;
    al = memoryGet(ss, bp - 4);
    ah = 0x00;
    if (!ax)
        goto loc_7e2c;
loc_7ea4:
    al = memoryGet(ss, bp - 4);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7eab()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_7eb7;
    sub_ca53();
loc_7eb7:
    bx = memoryGet16(ds, 0x0574);
    es = memoryGet16(ds, 0x0574 + 2);
    al = memoryGet(ss, bp + 6);
    ah = 0x00;
    memorySet16(es, bx + 20, ax);
    push(memoryGet16(ds, 0x0576));
    push(memoryGet16(ds, 0x0574));
    sub_9a1a();
    sp += 0x0004;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ax = memoryGet16(ss, bp + 8);
    memorySet16(es, bx + 4, ax);
    al = memoryGet(ss, bp + 6);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    memorySet16(es, bx, ax);
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    memorySet16(es, bx + 2, ax);
    if (memoryGet(ss, bp + 10) == 0x00)
        goto loc_7f03;
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
loc_7f03:
    al = 0x08;
    push(ax);
    sub_24b7();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_7f0d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000c;
    push(si);
    si = memoryGet16(ss, bp + 10);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_7f20;
    sub_ca53();
loc_7f20:
    al = memoryGet(ss, bp + 8);
    memorySet(ss, bp - 12, al);
    memorySet(ss, bp - 11, 0x00);
    goto loc_7f3f;
loc_7f2c:
    al = memoryGet(ss, bp - 11);
    memorySet(ss, bp - 11, memoryGet(ss, bp - 11) + 1);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    memorySet(ss, bx, 0x20);
loc_7f3f:
    al = memoryGet(ss, bp - 11);
    if (al < memoryGet(ss, bp + 8))
        goto loc_7f2c;
    al = memoryGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    memorySet(ss, bx, 0x00);
    goto loc_7f9e;
loc_7f59:
    al = memoryGet(ss, bp + 4);
    memorySet(ss, bp - 1, al);
    ax = 0;
    dx = 0x000a;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_c7be();
    memorySet16(ss, bp + 4, ax);
    bx = ax;
    memorySet16(ss, bp + 6, dx);
    cx = dx;
    dx = 0;
    ax = 0x000a;
    sub_c8e4();
    dl = memoryGet(ss, bp - 1);
    dl -= al;
    memorySet(ss, bp - 1, dl);
    al = memoryGet(ss, bp + 8);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    dl = memoryGet(ss, bp - 1);
    dl += 0x30;
    bx = ax;
    memorySet(ss, bx, dl);
loc_7f9e:
    al = memoryGet(ss, bp + 8);
    memorySet(ss, bp + 8, memoryGet(ss, bp + 8) - 1);
    if (al)
        goto loc_7f59;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    ax = memoryGet16(ss, bp + 12);
    memorySet16(es, bx + 2, ax);
    memorySet(ss, bp - 11, 0x00);
    goto loc_7ff3;
loc_7fb9:
    al = memoryGet(ss, bp - 11);
    ah = 0x00;
    dx = bp - 0xa;
    ax += dx;
    bx = ax;
    al = memoryGet(ss, bx);
    ah = 0x00;
    ax += 0x017c;
    bx = memoryGet16(ds, 0x8884);
    es = memoryGet16(ds, 0x8884 + 2);
    memorySet16(es, bx + 4, ax);
    al = memoryGet(ss, bp - 11);
    ah = 0x00;
    cl = 0x04;
    ax <<= cl;
    dx = si;
    dx += ax;
    memorySet16(es, bx, dx);
    push(ds);
    ax = 0x792e;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memorySet(ss, bp - 11, memoryGet(ss, bp - 11) + 1);
loc_7ff3:
    al = memoryGet(ss, bp - 11);
    if (al < memoryGet(ss, bp - 12))
        goto loc_7fb9;
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8000()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_800e;
    sub_ca53();
loc_800e:
    bx = memoryGet16(ds, 0xa0d0);
    es = memoryGet16(ds, 0xa0d0 + 2);
    memorySet16(es, bx + 4, 0x01aa);
    memorySet16(es, bx + 2, 0x0000);
    al = memoryGet(ds, 0x791a);
    memorySet(ss, bp - 1, al);
    goto loc_8049;
loc_8026:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax += 0x0050;
    bx = memoryGet16(ds, 0xa0d0);
    es = memoryGet16(ds, 0xa0d0 + 2);
    memorySet16(es, bx, ax);
    push(ds);
    ax = 0x7986;
    push(ax);
    sub_b2fa();
    sp += 0x0004;
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) - 1);
loc_8049:
    if (memoryGet(ss, bp - 1) != 0x00)
        goto loc_8026;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8053()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8061;
    sub_ca53();
loc_8061:
    memorySet16(ds, 0x9ba6, 0x0886);
    memorySet16(ds, 0x9ba8, ds);
    bx = memoryGet16(ds, 0x9ba6);
    es = memoryGet16(ds, 0x9ba6 + 2);
    memorySet(es, bx, 0xff);
    memorySet(ds, 0xa1a6, 0x00);
    dl = 0x00;
    goto loc_809b;
loc_807c:
    al = dl;
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx + 48);
    cl = al;
    if (cl < 0x0e)
        goto loc_8099;
    if (cl >= 0x12)
        goto loc_8099;
    memorySet(ds, 0xa1a6, al);
loc_8099:
    dl++;
loc_809b:
    if (dl >= 0x30)
        goto loc_80a9;
    al = memoryGet(ds, 0xa1a6);
    ah = 0x00;
    if (!ax)
        goto loc_807c;
loc_80a9:
    if (memoryGet(ds, 0xa1a6) != 0x00)
        goto loc_80b3;
    goto loc_8168;
loc_80b3:
    al = 0x00;
    memorySet(ss, bp - 1, al);
    dl = al;
    goto loc_80e2;
loc_80bc:
    al = dl;
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx + 48);
    cl = al;
    if (cl < 0x0e)
        goto loc_80e0;
    if (cl >= 0x12)
        goto loc_80e0;
    if (al == memoryGet(ds, 0xa1a6))
        goto loc_80e0;
    memorySet(ss, bp - 1, 0x01);
loc_80e0:
    dl++;
loc_80e2:
    if (dl >= 0x30)
        goto loc_80f0;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_80bc;
loc_80f0:
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_8168;
    al = 0x00;
    memorySet(ss, bp - 2, al);
    memorySet(ss, bp - 1, al);
    dl = 0x00;
    goto loc_812b;
loc_8105:
    al = dl;
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryGet(es, bx + 48) != 0x05)
        goto loc_8129;
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9ba6);
    es = memoryGet16(ds, 0x9ba6 + 2);
    bx += ax;
    al = dl;
    memorySet(es, bx, al);
    memorySet(ss, bp - 2, memoryGet(ss, bp - 2) + 1);
loc_8129:
    dl++;
loc_812b:
    if (dl >= 0x30)
        goto loc_8139;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    if (!ax)
        goto loc_8105;
loc_8139:
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9ba6);
    es = memoryGet16(ds, 0x9ba6 + 2);
    bx += ax;
    if (memoryGet(es, bx) == 0xff)
        goto loc_8168;
    al = memoryGet(ss, bp - 2);
    ah = 0x00;
    bx = memoryGet16(ds, 0x9ba6);
    bx += ax;
    memorySet(es, bx, 0xff);
    memorySet16(ds, 0x9ba6, 0x0886);
    memorySet16(ds, 0x9ba8, ds);
    memorySet(ds, 0x79b7, 0x00);
loc_8168:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_816c()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8178;
    sub_ca53();
loc_8178:
    bx = memoryGet16(ds, 0x9ba6);
    es = memoryGet16(ds, 0x9ba6 + 2);
    if (memoryGet(es, bx) != 0xff)
        goto loc_8196;
    memorySet16(ds, 0x9ba6, 0x0886);
    memorySet16(ds, 0x9ba8, ds);
    bx = memoryGet16(ds, 0x9ba6);
    es = memoryGet16(ds, 0x9ba6 + 2);
    memorySet(es, bx, 0xff);
    goto loc_81d3;
loc_8196:
    al = memoryGet(ds, 0x79b7);
    ah = 0x00;
    if (ax)
        goto loc_81cf;
    memorySet(ds, 0x79b7, 0x0a);
    bx = memoryGet16(ds, 0x9ba6);
    es = memoryGet16(ds, 0x9ba6 + 2);
    al = memoryGet(es, bx);
    memorySet(ds, 0x8570, al);
    al = 0x18;
    push(ax);
    sub_8959();
    sp++;
    sp++;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_81c1;
    al = 0x11;
    goto loc_81c3;
loc_81c1:
    al = 0x0e;
loc_81c3:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    memorySet16(ds, 0x9ba6, memoryGet16(ds, 0x9ba6) + 1);
    goto loc_81d3;
loc_81cf:
    memorySet(ds, 0x79b7, memoryGet(ds, 0x79b7) - 1);
loc_81d3:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_81d5()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_81e1;
    sub_ca53();
loc_81e1:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_81ec;
    al = 0x03;
    goto loc_81ee;
loc_81ec:
    al = 0x0d;
loc_81ee:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_81f6()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8202;
    sub_ca53();
loc_8202:
    if (memoryGet(ds, 0x855e) == 0x00)
        goto loc_8240;
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryGet(es, bx + 47) != 0x0c)
        goto loc_8240;
    memorySet(ds, 0x792a, 0x00);
    memorySet(ds, 0xa0ce, 0x01);
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_8238;
    al = 0x03;
    goto loc_823a;
loc_8238:
    al = 0x0d;
loc_823a:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8240:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8242()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_824e;
    sub_ca53();
loc_824e:
    if (memoryGet(ds, 0x855e) == 0x07)
        goto loc_828c;
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    if (memoryGet(es, bx + 48) != 0x0c)
        goto loc_828c;
    memorySet(ds, 0x792a, 0x00);
    memorySet(ds, 0xa0ce, 0x01);
    al = 0x2e;
    push(ax);
    sub_6133();
    sp++;
    sp++;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_8284;
    al = 0x03;
    goto loc_8286;
loc_8284:
    al = 0x0d;
loc_8286:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_828c:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_828e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_829c;
    sub_ca53();
loc_829c:
    if (memoryGet(ds, 0x8552) == 0x03)
        goto loc_82d8;
    if (memoryGet(ds, 0x8552) == 0x0f)
        goto loc_82d8;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_82be;
    al = memoryGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 9790);
    goto loc_82c9;
loc_82be:
    al = memoryGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 9742);
loc_82c9:
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_82d8;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_82d8:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_82dc()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_82ea;
    sub_ca53();
loc_82ea:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_82fe;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 10126);
    goto loc_8309;
loc_82fe:
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 10094);
loc_8309:
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_8318;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8318:
    if (memoryGet(ds, 0x8551) < 0x0e)
        goto loc_8329;
    if (memoryGet(ds, 0x8551) >= 0x12)
        goto loc_8329;
    sub_8053();
loc_8329:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_832d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8339;
    sub_ca53();
loc_8339:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_8344;
    al = 0x0b;
    goto loc_8346;
loc_8344:
    al = 0x2c;
loc_8346:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_834e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_835c;
    sub_ca53();
loc_835c:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_8370;
    al = memoryGet(ds, 0x79b9);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 9982);
    goto loc_837b;
loc_8370:
    al = memoryGet(ds, 0x79b9);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 9934);
loc_837b:
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_838a;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_838a:
    sub_841e();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8391()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_839d;
    sub_ca53();
loc_839d:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_83a8;
    al = 0x0e;
    goto loc_83aa;
loc_83a8:
    al = 0x21;
loc_83aa:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_83b2()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_83be;
    sub_ca53();
loc_83be:
    sub_84e1();
    al = memoryGet(ds, 0x856e);
    al += 0xf8;
    memorySet(ds, 0x856e, al);
    memorySet(ds, 0x855c, memoryGet(ds, 0x855c) - 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_83cf()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_83db;
    sub_ca53();
loc_83db:
    sub_84e1();
    al = memoryGet(ds, 0x856e);
    al += 0x08;
    memorySet(ds, 0x856e, al);
    memorySet(ds, 0x855c, memoryGet(ds, 0x855c) + 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_83ec()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_83f8;
    sub_ca53();
loc_83f8:
    sub_84e1();
    memorySet(ds, 0x856e, memoryGet(ds, 0x856e) - 1);
    memorySet(ds, 0x855e, memoryGet(ds, 0x855e) - 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8405()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8411;
    sub_ca53();
loc_8411:
    sub_84e1();
    memorySet(ds, 0x856e, memoryGet(ds, 0x856e) + 1);
    memorySet(ds, 0x855e, memoryGet(ds, 0x855e) + 1);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_841e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_842a;
    sub_ca53();
loc_842a:
    al = memoryGet(ds, 0x7923);
    ah = 0x00;
    if (ax)
        goto loc_8455;
    if (memoryGet(ds, 0x8244) & 0x10)
        goto loc_8441;
    if (!(memoryGet(ds, 0x8244) & 0x01))
        goto loc_8455;
loc_8441:
    al = memoryGet(ds, 0x7924);
    memorySet(ds, 0x7922, al);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 15578);
    push(ax);
    sub_882e();
    sp++;
    sp++;
loc_8455:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8457()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8463;
    sub_ca53();
loc_8463:
    al = memoryGet(ds, 0xa1a7);
    ah = 0x00;
    if (ax)
        goto loc_84a0;
    if (memoryGet(ds, 0x7924) != 0x02)
        goto loc_84a0;
    if (!(memoryGet(ds, 0x8244) & 0x02))
        goto loc_84a0;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_8485;
    al = 0x04;
    goto loc_8487;
loc_8485:
    al = 0x09;
loc_8487:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
    memorySet(ds, 0x79b4, 0x34);
    al = 0x34;
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_84a0:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84a2()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_84ae;
    sub_ca53();
loc_84ae:
    memorySet(ds, 0x8244, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84b5()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_84c1;
    sub_ca53();
loc_84c1:
    al = memoryGet(ds, 0x8244);
    al &= 0x10;
    memorySet(ds, 0x8244, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84cb()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_84d7;
    sub_ca53();
loc_84d7:
    al = memoryGet(ds, 0x8244);
    al &= 0x1d;
    memorySet(ds, 0x8244, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84e1()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_84ed;
    sub_ca53();
loc_84ed:
    al = memoryGet(ds, 0x8244);
    al &= 0x0f;
    memorySet(ds, 0x8244, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_84f7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8503;
    sub_ca53();
loc_8503:
    al = memoryGet(ds, 0x856e);
    push(ax);
    sub_8ac4();
    sp++;
    sp++;
    if (memoryGet(ds, 0x79b8) == 0x00)
        goto loc_8516;
    sub_8ae4();
loc_8516:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8518()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8526;
    sub_ca53();
loc_8526:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_853a;
    al = memoryGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 9694);
    goto loc_8545;
loc_853a:
    al = memoryGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 9646);
loc_8545:
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_8554;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8554:
    al = memoryGet(ds, 0x7924);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 15626);
    push(ax);
    sub_8857();
    sp++;
    sp++;
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8569()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8575;
    sub_ca53();
loc_8575:
    if (memoryGet(ds, 0x8552) == 0x03)
        goto loc_858e;
    if (memoryGet(ds, 0x8552) == 0x0f)
        goto loc_858e;
    push(ds);
    ax = 0x3c7a;
    push(ax);
    sub_8c3a();
    sp += 0x0004;
loc_858e:
    if (memoryGet(ds, 0x855e) == 0x00)
        goto loc_85a6;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 13758);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_85a6:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_85a8()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_85b4;
    sub_ca53();
loc_85b4:
    if (memoryGet(ds, 0x8552) == 0x03)
        goto loc_85cd;
    if (memoryGet(ds, 0x8552) == 0x0f)
        goto loc_85cd;
    push(ds);
    ax = 0x3caa;
    push(ax);
    sub_8c3a();
    sp += 0x0004;
loc_85cd:
    if (memoryGet(ds, 0x855e) == 0x07)
        goto loc_85e5;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 13790);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_85e5:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_85e7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_85f3;
    sub_ca53();
loc_85f3:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
    sub_8bf6();
    if (memoryGet(ds, 0x856c) != 0x5b)
        goto loc_8608;
    memorySet(ds, 0xa1b1, 0x00);
loc_8608:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_860a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8616;
    sub_ca53();
loc_8616:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8618()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8624;
    sub_ca53();
loc_8624:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_862f;
    al = 0x08;
    goto loc_8631;
loc_862f:
    al = 0x2f;
loc_8631:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x18;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
    if (memoryGet(ds, 0x855e) == 0x00)
        goto loc_8657;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 13822);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_8657:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8659()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8665;
    sub_ca53();
loc_8665:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_8670;
    al = 0x08;
    goto loc_8672;
loc_8670:
    al = 0x2f;
loc_8672:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = 0x19;
    push(ax);
    sub_8c64();
    sp++;
    sp++;
    if (memoryGet(ds, 0x855e) == 0x07)
        goto loc_8698;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 13854);
    push(ax);
    sub_8959();
    sp++;
    sp++;
loc_8698:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_869a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_86a6;
    sub_ca53();
loc_86a6:
    if (memoryGet(ds, 0x855e) == 0x00)
        goto loc_86b0;
    sub_86b2();
loc_86b0:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_86b2()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_86be;
    sub_ca53();
loc_86be:
    push(ds);
    ax = 0x363e;
    push(ax);
    sub_873a();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_86cb()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_86d7;
    sub_ca53();
loc_86d7:
    if (memoryGet(ds, 0x855e) == 0x07)
        goto loc_86e1;
    sub_86e3();
loc_86e1:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_86e3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_86ef;
    sub_ca53();
loc_86ef:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x8570, al);
    push(ds);
    ax = 0x365e;
    push(ax);
    sub_873a();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8702()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_870e;
    sub_ca53();
loc_870e:
    push(ds);
    ax = 0x363e;
    push(ax);
    sub_873a();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_871b()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8727;
    sub_ca53();
loc_8727:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x8570, al);
    push(ds);
    ax = 0x365e;
    push(ax);
    sub_873a();
    sp += 0x0004;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_873a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8746;
    sub_ca53();
loc_8746:
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memorySet(ds, 0x8244, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8760()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_876c;
    sub_ca53();
loc_876c:
    if (memoryGet(ds, 0x855e) == 0x00)
        goto loc_8789;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 13822);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memorySet(ds, 0x8244, 0x00);
loc_8789:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_878b()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8797;
    sub_ca53();
loc_8797:
    if (memoryGet(ds, 0x855e) == 0x07)
        goto loc_87b4;
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 13854);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memorySet(ds, 0x8244, 0x00);
loc_87b4:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_87b6()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_87c2;
    sub_ca53();
loc_87c2:
    if (memoryGet(ds, 0x855e) == 0x00)
        goto loc_87cc;
    sub_87ce();
loc_87cc:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_87ce()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_87da;
    sub_ca53();
loc_87da:
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 13950);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memorySet(ds, 0x8244, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_87f2()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_87fe;
    sub_ca53();
loc_87fe:
    if (memoryGet(ds, 0x855e) == 0x07)
        goto loc_8808;
    sub_880a();
loc_8808:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_880a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8816;
    sub_ca53();
loc_8816:
    al = memoryGet(ds, 0x8551);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 13982);
    push(ax);
    sub_8959();
    sp++;
    sp++;
    memorySet(ds, 0x8244, 0x00);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_882e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_883a;
    sub_ca53();
loc_883a:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
    if (memoryGet(ss, bp + 4) == 0x00)
        goto loc_8855;
    al = memoryGet(ss, bp + 4);
    memorySet(ds, 0xa1a7, al);
    al = memoryGet(ss, bp + 4);
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_8855:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8857()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8863;
    sub_ca53();
loc_8863:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
    if (memoryGet(ss, bp + 4) == 0x00)
        goto loc_8878;
    al = memoryGet(ss, bp + 4);
    push(ax);
    sub_887a();
    sp++;
    sp++;
loc_8878:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_887a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_888a;
    sub_ca53();
loc_888a:
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 12000);
    dx = memoryGet16(ds, bx + 11998);
    memorySet16(ss, bp - 4, dx);
    memorySet16(ss, bp - 2, ax);
    cl = 0x00;
loc_88a5:
    al = cl;
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19570);
    dx = memoryGet16(ds, bx + 19568);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(es, bx);
    memorySet(ss, bp + 4, al);
    cl++;
    ah = 0x00;
    if (!ax)
        goto loc_88a5;
    if (memoryGet(ss, bp + 4) != 0xff)
        goto loc_8910;
    cl = 0x00;
loc_88d6:
    al = cl;
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19570);
    dx = memoryGet16(ds, bx + 19568);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(es, bx);
    memorySet(ss, bp + 4, al);
    cl++;
    if (memoryGet(ss, bp + 4) == 0x00)
        goto loc_8905;
    if (memoryGet(ss, bp + 4) != 0xff)
        goto loc_88d6;
loc_8905:
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    if (ax)
        goto loc_8954;
    goto loc_891d;
loc_8910:
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(es, bx + 1);
    if (al != memoryGet(ds, 0x856f))
        goto loc_88a5;
loc_891d:
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(ds, 0x856f);
    memorySet(es, bx + 1, al);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    push(es);
    si = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    al = memoryGet(es, si);
    es = pop();
    memorySet(es, bx, al);
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    ax = memoryGet16(es, bx + 4);
    dx = memoryGet16(es, bx + 2);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet(es, bx, 0x01);
loc_8954:
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8959()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8969;
    sub_ca53();
loc_8969:
    al = memoryGet(ss, bp + 4);
    memorySet(ds, 0x8566, al);
    if (al)
        goto loc_8976;
    goto loc_8a80;
loc_8976:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_898a;
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 10062);
    goto loc_8995;
loc_898a:
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 10030);
loc_8995:
    memorySet(ss, bp - 10, al);
    if (memoryGet(ss, bp - 10) == 0x00)
        goto loc_89a4;
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_89a4:
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 12888);
    dx = memoryGet16(ds, bx + 12886);
    memorySet16(ss, bp - 4, dx);
    memorySet16(ss, bp - 2, ax);
    memorySet(ss, bp - 9, 0x00);
loc_89c1:
    al = memoryGet(ss, bp - 9);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19646);
    dx = memoryGet16(ds, bx + 19644);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(es, bx);
    memorySet(ss, bp + 4, al);
    memorySet(ss, bp - 9, memoryGet(ss, bp - 9) + 1);
    ah = 0x00;
    if (!ax)
        goto loc_89c1;
    if (memoryGet(ss, bp + 4) != 0xff)
        goto loc_8a38;
    memorySet(ss, bp - 9, 0x00);
loc_89f6:
    al = memoryGet(ss, bp - 9);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 19646);
    dx = memoryGet16(ds, bx + 19644);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(es, bx);
    memorySet(ss, bp + 4, al);
    memorySet(ss, bp - 9, memoryGet(ss, bp - 9) + 1);
    if (memoryGet(ss, bp + 4) == 0x00)
        goto loc_8a27;
    if (memoryGet(ss, bp + 4) != 0xff)
        goto loc_89f6;
loc_8a27:
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    if (!ax)
        goto loc_8a48;
    if (memoryGet(ss, bp + 4) != 0xff)
        goto loc_8a80;
    goto loc_8a80;
loc_8a38:
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(es, bx + 1);
    if (al == memoryGet(ds, 0x8570))
        goto loc_8a48;
    goto loc_89c1;
loc_8a48:
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    al = memoryGet(ds, 0x8570);
    memorySet(es, bx + 1, al);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    push(es);
    si = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    al = memoryGet(es, si);
    es = pop();
    memorySet(es, bx + 48, al);
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    ax = memoryGet16(es, bx + 4);
    dx = memoryGet16(es, bx + 2);
    bx = memoryGet16(ss, bp - 8);
    es = memoryGet16(ss, bp - 8 + 2);
    memorySet16(es, bx + 2, dx);
    memorySet16(es, bx + 4, ax);
    memorySet(es, bx, 0x01);
loc_8a80:
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8a85()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8a91;
    sub_ca53();
loc_8a91:
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    memorySet(ds, 0x7921, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8aa4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8ab0;
    sub_ca53();
loc_8ab0:
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx + 48);
    memorySet(ds, 0x8551, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8ac4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8ad0;
    sub_ca53();
loc_8ad0:
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    al = memoryGet(es, bx + 96);
    memorySet(ds, 0x79b8, al);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8ae4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8af0;
    sub_ca53();
loc_8af0:
    memorySet(ds, 0x2810, 0x0f);
    sub_8b65();
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    bx = memoryGet16(ds, 0xa0d8);
    es = memoryGet16(ds, 0xa0d8 + 2);
    bx += ax;
    memorySet(es, bx + 96, 0x00);
    if (memoryGet(ds, 0x79b8) == 0x01)
        goto loc_8b63;
    if (memoryGet(ds, 0x79b8) == 0x23)
        goto loc_8b63;
    memorySet(ds, 0xa0cf, memoryGet(ds, 0xa0cf) - 1);
    al = memoryGet(ds, 0xa0cf);
    ah = 0x00;
    if (ax)
        goto loc_8b50;
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_8b2e;
    al = 0x0b;
    goto loc_8b30;
loc_8b2e:
    al = 0x2c;
loc_8b30:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
    al = memoryGet(ds, 0x8572);
    memorySet(ds, 0x856f, al);
    al = 0x59;
    push(ax);
    sub_887a();
    sp++;
    sp++;
    memorySet(ds, 0xa1b1, 0x01);
    memorySet(ds, 0x8550, 0xf2);
    goto loc_8b63;
loc_8b50:
    if (memoryGet16(ds, 0x689c) == 0x0004)
        goto loc_8b5b;
    al = 0x0e;
    goto loc_8b5d;
loc_8b5b:
    al = 0x21;
loc_8b5d:
    push(ax);
    sub_8ce1();
    sp++;
    sp++;
loc_8b63:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8b65()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8b71;
    sub_ca53();
loc_8b71:
    memorySet(ds, 0xa1a8, 0x02);
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 628);
    cl = 0x04;
    ax = sar(ax, cl);
    memorySet16(ds, 0x9b9a, ax);
    al = memoryGet(ds, 0x856e);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax = memoryGet16(ds, bx + 630);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet16(ds, 0x9ba2, ax);
    if (!(memoryGet(ds, 0x856e) & 0x01))
        goto loc_8bb0;
    ax = 0x0001;
    goto loc_8bb3;
loc_8bb0:
    ax = 0x0002;
loc_8bb3:
    bx = memoryGet16(ds, 0x08e4);
    es = memoryGet16(ds, 0x08e4 + 2);
    memorySet16(es, bx + 30, ax);
    flags.carry = (memoryGet16(ds, 0xa0d4) + 0x00fa) >= 0x10000;
    memorySet16(ds, 0xa0d4, memoryGet16(ds, 0xa0d4) + 0x00fa);
    memorySet16(ds, 0xa0d6, memoryGet16(ds, 0xa0d6) + flags.carry);
    if (memoryGet(ds, 0x79b8) != 0x23)
        goto loc_8bd3;
    memorySet(ds, 0x791a, memoryGet(ds, 0x791a) + 1);
    goto loc_8bf4;
loc_8bd3:
    if (memoryGet(ds, 0x79b8) != 0x2f)
        goto loc_8be2;
    flags.carry = (memoryGet16(ds, 0xa0d4) + 0x2616) > 0x10000;
    memorySet16(ds, 0xa0d4, memoryGet16(ds, 0xa0d4) + 0x2616);
    goto loc_8bef;
loc_8be2:
    if (memoryGet(ds, 0x79b8) != 0x30)
        goto loc_8bf4;
    flags.carry = (memoryGet16(ds, 0xa0d4) + 0xc256) > 0x10000;
    memorySet16(ds, 0xa0d4, memoryGet16(ds, 0xa0d4) + 0xc256);
loc_8bef:
    memorySet16(ds, 0xa0d6, memoryGet16(ds, 0xa0d6) + flags.carry);
loc_8bf4:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8bf6()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8c04;
    sub_ca53();
loc_8c04:
    al = memoryGet(ds, 0x856e);
    push(ax);
    sub_8a85();
    sp++;
    sp++;
    al = memoryGet(ds, 0x7921);
    ah = 0x00;
    bx = ax;
    al = memoryGet(ds, bx + 17302);
    memorySet(ss, bp - 1, al);
    if (memoryGet(ss, bp - 1) == 0x00)
        goto loc_8c36;
    al = memoryGet(ds, 0x7924);
    memorySet(ds, 0x7922, al);
    al = memoryGet(ss, bp - 1);
    memorySet(ds, 0x7923, al);
    al = memoryGet(ss, bp - 1);
    push(ax);
    sub_8c64();
    sp++;
    sp++;
loc_8c36:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8c3a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8c46;
    sub_ca53();
loc_8c46:
    al = memoryGet(ds, 0x8242);
    ah = 0x00;
    if (ax)
        goto loc_8c62;
    al = memoryGet(ds, 0x7924);
    ah = 0x00;
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    bx += ax;
    al = memoryGet(es, bx);
    push(ax);
    sub_8857();
    sp++;
    sp++;
loc_8c62:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8c64()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8c70;
    sub_ca53();
loc_8c70:
    al = memoryGet(ds, 0x856e);
    memorySet(ds, 0x856f, al);
    al = memoryGet(ss, bp + 4);
    push(ax);
    sub_887a();
    sp++;
    sp++;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8cb3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8cc0;
    sub_ca53();
loc_8cc0:
    if (memoryGet16(ds, 0x689c) == 0x8000)
        goto loc_8cde;
    sub_a7b5();
    si = ax;
    ax = memoryGet16(ds, 0x689c);
    ax &= si;
    memorySet16(ds, 0x689c, ax);
    push(memoryGet16(ds, 0x689c));
    sub_a7ee();
    sp++;
    sp++;
loc_8cde:
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8ce1()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8ced;
    sub_ca53();
loc_8ced:
    if (memoryGet16(ds, 0x689c) == 0x8000)
        goto loc_8cfe;
    al = memoryGet(ss, bp + 4);
    push(ax);
    sub_8d00();
    sp++;
    sp++;
loc_8cfe:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8d00()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8d0c;
    sub_ca53();
loc_8d0c:
    if (memoryGet16(ds, 0x689c) != 0x0004)
        goto loc_8d3c;
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryGet(ds, bx + 10159);
    ah = 0x00;
    push(ax);
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    ax <<= 1;
    bx = ax;
    al = memoryGet(ds, bx + 10158);
    ah = 0x00;
    push(ax);
    sub_a8d7();
    sp += 0x0004;
    goto loc_8fb5;
loc_8d3c:
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    ax--;
    bx = ax;
    if (bx <= 0x0014)
        goto loc_8d4c;
    goto loc_8fb5;
loc_8d4c:
    bx <<= 1;
    switch (bx)
    {
        case 0: goto loc_8d53;
        case 2: goto loc_8d6a;
        case 4: goto loc_8d85;
        case 6: goto loc_8da3;
        case 8: goto loc_8dc1;
        case 10: goto loc_8ddf;
        case 12: goto loc_8dfd;
        case 14: goto loc_8e1b;
        case 16: goto loc_8e39;
        case 18: goto loc_8e50;
        case 20: goto loc_8e6e;
        case 22: goto loc_8e8f;
        case 24: goto loc_8ea9;
        case 26: goto loc_8ec7;
        case 28: goto loc_8ee4;
        case 30: goto loc_8f02;
        case 32: goto loc_8f1c;
        case 34: goto loc_8f3c;
        case 36: goto loc_8f5c;
        case 38: goto loc_8f76;
        default:
        assert(0);
    }
loc_8d53:
    ax = 0x0001;
    push(ax);
    push(ax);
    ax = 0x01c2;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x03e8;
    goto loc_8fa6;
loc_8d6a:
    ax = 0x0001;
    push(ax);
    push(ax);
    ax = 0x01c2;
    push(ax);
    ax = 0xfff6;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x0320;
    push(ax);
    ax = 0x0028;
    goto loc_8faa;
loc_8d85:
    ax = 0xffff;
    push(ax);
    ax = 0x0004;
    push(ax);
    ax = 0x01f3;
    push(ax);
    ax = 0xffff;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01b8;
    push(ax);
    ax = 0x0190;
    goto loc_8faa;
loc_8da3:
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x0064;
    push(ax);
    ax = 0xffff;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x00dc;
    push(ax);
    ax = 0x005a;
    goto loc_8faa;
loc_8dc1:
    ax = 0x0002;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01b8;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x03e8;
    push(ax);
    ax = 0x0019;
    goto loc_8faa;
loc_8ddf:
    ax = 0x0005;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x01b8;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x044c;
    push(ax);
    ax = 0x0014;
    goto loc_8faa;
loc_8dfd:
    ax = 0x0003;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01b8;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x04b0;
    push(ax);
    ax = 0x000f;
    goto loc_8faa;
loc_8e1b:
    ax = 0x0005;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x0064;
    push(ax);
    ax = 0xfffb;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x00dc;
    push(ax);
    ax = 0x0028;
    goto loc_8faa;
loc_8e39:
    ax = 0x0001;
    push(ax);
    push(ax);
    ax = 0x01c2;
    push(ax);
    ax = 0x0014;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x0032;
    goto loc_8fa6;
loc_8e50:
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x015d;
    push(ax);
    ax = 0x0032;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x00c8;
    push(ax);
    ax = 0x000f;
    goto loc_8faa;
loc_8e6e:
    ax = 0xfffc;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01f3;
    push(ax);
    ax = 0x0014;
    push(ax);
    ax = 0x0028;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_b3d2();
    sp += 0x000c;
    goto loc_8fb5;
loc_8e8f:
    ax = 0x0002;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01a4;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x04b0;
    goto loc_8fa6;
loc_8ea9:
    ax = 0x000f;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x015d;
    push(ax);
    ax = 0x0032;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x00c8;
    push(ax);
    ax = 0x0014;
    goto loc_8faa;
loc_8ec7:
    ax = 0;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x00c8;
    push(ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0032;
    goto loc_8faa;
loc_8ee4:
    ax = 0x0001;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x0064;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x012c;
    push(ax);
    ax = 0x0190;
    goto loc_8faa;
loc_8f02:
    ax = 0x0002;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01a4;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x04b0;
    goto loc_8fa6;
loc_8f1c:
    ax = 0xfffc;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x01f3;
    push(ax);
    ax = 0x0014;
    push(ax);
    ax = 0x0028;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_b3d2();
    sp += 0x000c;
    goto loc_8fb5;
loc_8f3c:
    ax = 0xfffc;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x01f3;
    push(ax);
    ax = 0x001e;
    push(ax);
    ax = 0x0050;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_b3d2();
    sp += 0x000c;
    goto loc_8fb5;
loc_8f5c:
    ax = 0x0001;
    push(ax);
    ax = 0x0002;
    push(ax);
    ax = 0x0064;
    push(ax);
    ax = 0x0001;
    push(ax);
    push(ax);
    ax = 0x012c;
    push(ax);
    ax = 0x0320;
    goto loc_8faa;
loc_8f76:
    ax = 0;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x00c8;
    push(ax);
    ax = 0x0004;
    push(ax);
    ax = 0x0001;
    push(ax);
    ax = 0x000a;
    push(ax);
    ax = 0x0032;
    goto loc_8faa;
    //   gap of 20 bytes
loc_8fa6:
    push(ax);
    ax = 0x001e;
loc_8faa:
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_b358();
    sp += 0x0010;
loc_8fb5:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8fe1()
{
    push(0x7777);
    push(bp);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_8fed;
    sub_ca53();
loc_8fed:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_8ff0()
{
    push(0x7777);
    push(bp);
    bp = sp;
    al = memoryGet(ss, bp + 4);
    ah = 0x00;
    interrupt(0x10);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_9105()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x000a;
    push(si);
    push(di);
    memorySet(ss, bp - 1, 0x00);
    si = 0;
    memorySet16(ss, bp - 6, 0x0000);
    memorySet16(ss, bp - 4, 0x0000);
    goto loc_919f;
loc_9120:
    if ((short)memoryGet16(ss, bp + 14) < (short)0x0000)
        goto loc_913d;
    if ((short)memoryGet16(ss, bp + 14) > (short)0x0000)
        goto loc_912f;
    if (memoryGet16(ss, bp + 12) <= 0xfa00)
        goto loc_913d;
loc_912f:
    di = 0xfa00;
    flags.carry = memoryGet16(ss, bp + 12) < 0xfa00;
    memorySet16(ss, bp + 12, memoryGet16(ss, bp + 12) - 0xfa00);
    memorySet16(ss, bp + 14, memoryGet16(ss, bp + 14) - flags.carry);
    goto loc_914a;
loc_913d:
    di = memoryGet16(ss, bp + 12);
    memorySet16(ss, bp + 12, 0x0000);
    memorySet16(ss, bp + 14, 0x0000);
loc_914a:
    push(di);
    push(memoryGet16(ss, bp + 10));
    push(memoryGet16(ss, bp + 8));
    push(memoryGet16(ss, bp + 6));
    callIndirect(cs*16+memoryGet16(ss, bp + 4));
    sp += 0x0008;
    si = ax;
    if (si == di)
        goto loc_9165;
    ax = 0x0001;
    goto loc_9167;
loc_9165:
    ax = 0;
loc_9167:
    memorySet(ss, bp - 1, al);
    flags.carry = (memoryGet16(ss, bp - 6) + si) >= 0x10000;
    memorySet16(ss, bp - 6, memoryGet16(ss, bp - 6) + si);
    memorySet16(ss, bp - 4, memoryGet16(ss, bp - 4) + flags.carry);
    ax = memoryGet16(ss, bp + 8);
    memorySet16(ss, bp - 10, ax);
    memorySet16(ss, bp - 8, 0x0000);
    flags.carry = (memoryGet16(ss, bp - 10) + si) >= 0x10000;
    memorySet16(ss, bp - 10, memoryGet16(ss, bp - 10) + si);
    memorySet16(ss, bp - 8, memoryGet16(ss, bp - 8) + flags.carry);
    ax = memoryGet16(ss, bp - 10);
    memorySet16(ss, bp + 8, ax);
    memorySet16(ss, bp - 10, 0x0000);
    ax = memoryGet16(ss, bp - 10);
    ax |= memoryGet16(ss, bp - 8);
    if (!ax)
        goto loc_919f;
    flags.carry = (memoryGet16(ss, bp + 8) + 0x0000) >= 0x10000;
    memorySet16(ss, bp + 8, memoryGet16(ss, bp + 8) + 0x0000);
    memorySet16(ss, bp + 10, memoryGet16(ss, bp + 10) + (0x1000 + flags.carry));
loc_919f:
    ax = memoryGet16(ss, bp + 12);
    ax |= memoryGet16(ss, bp + 14);
    if (!ax)
        goto loc_91b3;
    al = memoryGet(ss, bp - 1);
    ah = 0x00;
    if (ax)
        goto loc_91b3;
    goto loc_9120;
loc_91b3:
    dx = memoryGet16(ss, bp - 4);
    ax = memoryGet16(ss, bp - 6);
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_91bf()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 6);
    memorySet16(ds, 0xa1b8, ax);
    push(memoryGet16(ss, bp + 4));
    sub_bfb9();
    sp++;
    sp++;
    memorySet(ds, 0x4ce6, 0x01);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_91d7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 6);
    dx = memoryGet16(ss, bp + 4);
    memorySet16(ds, 0xa1b4, dx);
    memorySet16(ds, 0xa1b6, ax);
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_91e9()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(memoryGet16(ss, bp + 4));
    sub_b75e();
    sp++;
    sp++;
    si = ax;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_923f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    push(si);
    push(di);
    di = memoryGet16(ss, bp + 4);
    memorySet(ss, bp - 1, 0x00);
    al = memoryGet(ds, 0x4ce6);
    ah = 0x00;
    if (ax)
        goto loc_925c;
    memorySet16(ds, 0xa1b8, 0x74d4);
loc_925c:
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryGet16(ds, 0xa1b4);
    es = memoryGet16(ds, 0xa1b4 + 2);
    bx += ax;
    if (memoryGet(es, bx + 4) == 0x7a)
        goto loc_92b9;
loc_9270:
    push(memoryGet16(ss, bp + 6));
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryGet16(ds, 0xa1b4);
    es = memoryGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryGet(es, bx + 4);
    push(ax);
    sub_93a5();
    sp += 0x0004;
    si = ax;
    if (!ax)
        goto loc_92ab;
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryGet16(ds, 0xa1b4);
    es = memoryGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryGet(es, bx + 4);
    ah = 0x00;
    push(ax);
    callIndirect(cs*16+memoryGet16(ds, 0xa1b8));
    sp++;
    sp++;
loc_92ab:
    if (!si)
        goto loc_92b9;
    al = memoryGet(ss, bp - 1);
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) + 1);
    if (al < 0x0a)
        goto loc_9270;
loc_92b9:
    if (memoryGet(ss, bp - 1) > 0x0a)
        goto loc_9326;
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryGet16(ds, 0xa1b4);
    es = memoryGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryGet(es, bx + 4);
    memorySet(ds, 0x4ce7, al);
loc_92d3:
    ax = 0x0180;
    push(ax);
    ax = memoryGet16(ss, bp + 6);
    ax |= 0x8004;
    push(ax);
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryGet16(ds, 0xa1b4);
    es = memoryGet16(ds, 0xa1b4 + 2);
    bx += ax;
    push(memoryGet16(es, bx + 2));
    push(memoryGet16(es, bx));
    sub_c0ec();
    sp += 0x0008;
    si = ax;
    if ((short)ax >= 0)
        goto loc_9318;
    ax = di;
    dx = 0x000a;
    imul(dx);
    bx = memoryGet16(ds, 0xa1b4);
    es = memoryGet16(ds, 0xa1b4 + 2);
    bx += ax;
    al = memoryGet(es, bx + 4);
    ah = 0x00;
    push(ax);
    callIndirect(cs*16+memoryGet16(ds, 0xa1b8));
    sp++;
    sp++;
loc_9318:
    if ((short)si >= 0)
        goto loc_9326;
    al = memoryGet(ss, bp - 1);
    memorySet(ss, bp - 1, memoryGet(ss, bp - 1) + 1);
    if (al < 0x0a)
        goto loc_92d3;
loc_9326:
    ax = si;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_932e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(memoryGet16(ss, bp + 12));
    push(memoryGet16(ss, bp + 10));
    push(memoryGet16(ss, bp + 8));
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    ax = 0xa3ae;
    push(ax);
    sub_9105();
    sp += 0x000c;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    ax = memoryGet16(ss, bp - 4);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_93a5()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    ax = 0x0180;
    push(ax);
    ax = memoryGet16(ss, bp + 6);
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
    al = memoryGet(ds, 0xa1ba);
    ah = 0x00;
    dl = memoryGet(ss, bp + 4);
    dh = 0x00;
    ax -= dx;
    si = ax;
    if (memoryGet(ds, 0xa1ba) == 0x7a)
        goto loc_93fa;
    if (memoryGet(ss, bp + 4) != 0x7a)
        goto loc_93fc;
loc_93fa:
    si = 0;
loc_93fc:
    ax = si;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_9402()
{
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
    rep_stosw<MemData, DirForward>();
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
void sub_9433()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    push(es);
    push(si);
    push(di);
    ax = memoryGet16(ss, bp + 4);
    ah = 0;
    si = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 6 + 2);
    sub_944b();
    di = pop();
    si = pop();
    es = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_944b()
{
    push(ds);
    dx = 0x1228;
    ds = dx;
    if (al < 0x10)
        goto loc_945b;
    dx = 0x7676;
    goto loc_94fa;
loc_945b:
    ax += ax;
    ax += ax;
    bx = 0x1228;
    ds = bx;
    bx = 0x4cf2;
    bx += ax;
    memorySet16(ds, bx, si);
    ax = es;
    memorySet16(ds, bx + 2, ax);
    ds = pop();
    return;
    //   gap of 136 bytes
loc_94fa:
    ax = cs;
    ds = ax;
    ah = 0x09;
    interrupt(0x21);
loc_9502:
    goto loc_9502;
}
void sub_9472()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 4);
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
loc_948f:
    ax += ax;
    ax += ax;
    bx = 0x4cf2;
    bx += ax;
    si = memoryGet16(ds, bx);
    es = memoryGet16(ds, bx + 2);
    ax = es;
    ax |= si;
    if (ax)
        goto loc_94a5;
    dx = 0x7634;
    goto loc_94fa;
loc_94a5:
    dx = 0x0000;
loc_94a8:
    al = memoryGet(es, si);
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
loc_94bb:
    if (al == 0xff)
        goto loc_94f1;
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx = memoryGet16(ds, 0x4d42);
loc_94c9:
    al = memoryGet(es, si);
    si++;
    if (al >= 0xfd)
        goto loc_94e6;
    dh = al;
loc_94d3:
    al = memoryGet(es, si);
    si++;
    if (al >= 0xfd)
        goto loc_94e6;
    al &= 0x7f;
    al = memoryGet(ds, bx+al);
    if (al == 0)
        goto loc_94d3;
    dl |= dh;
    goto loc_94d3;
loc_94e6:
    if (al == 0xfe)
        goto loc_94f0;
    if (al != 0xff)
        goto loc_94c9;
    goto loc_94f1;
loc_94f0:
    ds = pop();
loc_94f1:
    di = pop();
    si = pop();
    es = pop();
    ds = pop();
    al = dl;
    ah = 0;
    assert(pop() == 0x7777);
    return;
loc_94fa:
    ax = cs;
    ds = ax;
    ah = 0x09;
    interrupt(0x21);
loc_9502:
    goto loc_9502;
}
void sub_960c()
{
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
    if (ah >= memoryGet(ds, 0x4d3b))
        goto loc_962e;
    ch |= 0x04;
    goto loc_9637;
loc_962e:
    if (ah < memoryGet(ds, 0x4d3d))
        goto loc_9637;
    ch |= 0x08;
loc_9637:
    if (al >= memoryGet(ds, 0x4d3a))
        goto loc_9642;
    ch |= 0x01;
    goto loc_964b;
loc_9642:
    if (al < memoryGet(ds, 0x4d3c))
        goto loc_964b;
    ch |= 0x02;
loc_964b:
    dx = 0x0201;
    in(al, dx);
    al = ~al;
    if (!(al & 0x40))
        goto loc_9658;
    ch |= 0x10;
loc_9658:
    if (!(al & 0x80))
        goto loc_965f;
    ch |= 0x20;
loc_965f:
    memorySet(ds, 0x4d35, ch);
loc_9665:
    ds = pop();
    return;
loc_9667:
    if (ah >= memoryGet(ds, 0x4d37))
        goto loc_9672;
    ch |= 0x04;
    goto loc_967b;
loc_9672:
    if (ah < memoryGet(ds, 0x4d39))
        goto loc_967b;
    ch |= 0x08;
loc_967b:
    if (al >= memoryGet(ds, 0x4d36))
        goto loc_9686;
    ch |= 0x01;
    goto loc_968f;
loc_9686:
    if (al < memoryGet(ds, 0x4d38))
        goto loc_968f;
    ch |= 0x02;
loc_968f:
    dx = 0x0201;
    in(al, dx);
    al = ~al;
    if (!(al & 0x10))
        goto loc_969c;
    ch |= 0x10;
loc_969c:
    if (!(al & 0x20))
        goto loc_96a3;
    ch |= 0x20;
loc_96a3:
    memorySet(ds, 0x4d34, ch);
    goto loc_9665;
}
void sub_96a9()
{
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = 0x4dca;
    if (ax == 0)
        goto loc_96b9;
    bx = 0x4dcb;
loc_96b9:
    cl = 0x01;
    memorySet(ds, bx, cl);
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
    memorySet(ds, 0x4d3a, dl);
    memorySet(ds, 0x4d3b, dh);
    memorySet(ds, 0x4d3c, cl);
    memorySet(ds, 0x4d3d, ch);
    goto loc_970c;
loc_96fc:
    memorySet(ds, 0x4d36, dl);
    memorySet(ds, 0x4d37, dh);
    memorySet(ds, 0x4d38, cl);
    memorySet(ds, 0x4d39, ch);
loc_970c:
    ds = pop();
    return;
loc_970e:
    push(cx);
    cx = 0x0000;
loc_9712:
    if (--cx)
        goto loc_9712;
    cx = pop();
    ax = 0xffff;
    goto loc_971c;
loc_971a:
    al = 0;
loc_971c:
    bx = 0x4dca;
    if (cx == 0)
        goto loc_9726;
    bx = 0x4dcb;
loc_9726:
    memorySet(ds, bx, al);
    goto loc_970c;
}
void sub_9731()
{
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
    al = memoryGet(ds, 0x4dcb);
    al--;
    if (al == 0)
        goto loc_9765;
    al++;
    if (al == 0)
        goto loc_974e;
    goto loc_97fe;
loc_974e:
    goto loc_9837;
loc_9751:
    bx = 0x0102;
    al = memoryGet(ds, 0x4dca);
    al--;
    if (al == 0)
        goto loc_9765;
    al++;
    if (al == 0)
        goto loc_9762;
    goto loc_97fe;
loc_9762:
    goto loc_9823;
loc_9765:
    dx = 0x0201;
    cx = 0;
loc_976a:
    in(al, dx);
    if (--cx && bl & al)
        goto loc_976a;
    if (cx == 0)
        goto loc_9775;
    if (--cx && bh & al)
        goto loc_976a;
loc_9775:
    if (cx == 0)
        goto loc_9779;
    goto loc_977c;
loc_9779:
    goto loc_97fe;
loc_977c:
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
loc_9791:
    if (--cx)
        goto loc_9791;
    cx = pop();
loc_9794:
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    ah &= 0x10;
    if (ah == 0)
        goto loc_9794;
loc_979f:
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    ah &= 0x10;
    if (ah != 0)
        goto loc_979f;
loc_97aa:
    cx = 0;
    memorySet16(ds, 0x4d32, cx);
    cx = 0x03e8;
loc_97b3:
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    ah &= 0x10;
    if (ah == 0)
        goto loc_97b3;
    memorySet16(ds, 0x4d32, memoryGet16(ds, 0x4d32) + 1);
    in(al, dx);
    if (bl == 0)
        goto loc_97cf;
    if (!(bl & al))
        goto loc_97f0;
    if (bh == 0)
        goto loc_97d3;
loc_97cf:
    if (!(bh & al))
        goto loc_97e2;
loc_97d3:
    in(al, 0x40);
    ah = al;
    in(al, 0x40);
    if (ah & 0x10)
        goto loc_97d3;
    if (--cx)
        goto loc_97b3;
    goto loc_97fe;
loc_97e2:
    ax = memoryGet16(ds, 0x4d32);
    memorySet16(ds, 0x4dc6, ax);
    bh = 0;
    if (bl == 0)
        goto loc_9803;
    goto loc_97d3;
loc_97f0:
    ax = memoryGet16(ds, 0x4d32);
    memorySet16(ds, 0x4dc8, ax);
    bl = 0;
    if (bh == 0)
        goto loc_9803;
    goto loc_97d3;
loc_97fe:
    ax = 0xffff;
    goto loc_9820;
loc_9803:
    dx = memoryGet16(ds, 0x4dc6);
    if ((short)dx >= 0)
        goto loc_980d;
    dx = 0;
loc_980d:
    cl = 0x01;
    dx >>= cl;
    ax = memoryGet16(ds, 0x4dc8);
    if ((short)ax >= 0)
        goto loc_981a;
    ax = 0;
loc_981a:
    cl = 0x01;
    ax >>= cl;
    ah = dl;
loc_9820:
    ds = pop();
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    return;
loc_9823:
    dx = 0x0201;
    in(al, dx);
    al &= 0x03;
    if (al != 0)
        goto loc_97fe;
    al = 0x01;
    memorySet(ds, 0x4dca, al);
    ax = 0x0000;
    goto loc_9847;
loc_9835:
    goto loc_97fe;
loc_9837:
    dx = 0x0201;
    in(al, dx);
    al &= 0x0c;
    if (al != 0)
        goto loc_9835;
    al = 0x01;
    memorySet(ds, 0x4dcb, al);
    ax = 0x0001;
loc_9847:
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
void sub_985a()
{
    push(si);
    push(di);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    es = ax;
    flags.direction = false;
    di = memoryGet16(ds, 0x4d42);
    cx = 0x0040;
    ax = 0x0000;
    rep_stosw<MemData, DirForward>();
    es = pop();
    sub_99d1();
    ax = memoryGet16(ds, 0x4dc4);
    if (ax != 0)
        goto loc_98b2;
    ax++;
    memorySet16(ds, 0x4dc4, ax);
    push(ds);
    push(es);
    al = 0x09;
    ah = 0x35;
    interrupt(0x21);
    dx = es;
    ax = 0x01ed;
    es = ax;
    memorySet16(ds, 0x4d3e, bx);
    memorySet16(es, 0x7a6d, bx);
    memorySet16(ds, 0x4d40, dx);
    memorySet16(es, 0x7a6f, dx);
    dx = 0x79e6;
    bx = 0x01ed;
    ds = bx;
    al = 0x09;
    ah = 0x25;
    interrupt(0x21);
    es = pop();
    ds = pop();
loc_98b2:
    ds = pop();
    di = pop();
    si = pop();
}
void sub_98b6()
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
    di = memoryGet16(ds, bx);
    si = memoryGet16(ds, bx + 2);
    bx = 0x001a;
    cx = memoryGet16(ds, bx);
    dx = memoryGet16(ds, bx + 2);
    si -= di;
    flags.carry = dx < cx;
    dx -= cx;
    if (!flags.carry)
        goto loc_98de;
    si -= dx;
    dx = si;
loc_98de:
    if (dx < 0x0010)
        goto loc_98ea;
    ax = memoryGet16(cs, 0x7a71);
    memorySet16(ds, bx + 2, ax);
loc_98ea:
    ax = memoryGet16(ds, bx + 2);
    memorySet16(cs, 0x7a71, ax);
    in(al, 0x60);
    if (al == 0xff)
        goto loc_9923;
    cl = al;
    bx = 0x1228;
    ds = bx;
    bx = memoryGet16(ds, 0x4d42);
    ah = 0x00;
    al &= 0x7f;
    di = ax;
    if (!(cl & 0x80))
        goto loc_990f;
    al = 0;
loc_990f:
    memorySet(ds, bx + di, al);
    push(cs);
    cs = memoryGet16(cs, 0x7a73 + 2);
    callIndirect(memoryGet16(cs, 0x7a73 + 2)*16 + memoryGet16(cs, 0x7a73));
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
loc_9923:
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
void sub_9947()
{
    push(si);
    push(di);
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ds, 0x4dc4);
    if (ax == 0)
        goto loc_9980;
    ax = 0;
    memorySet16(ds, 0x4dc4, ax);
    push(ds);
    push(es);
    dx = memoryGet16(ds, 0x4d3e);
    bx = memoryGet16(ds, 0x4d40);
    ds = bx;
    al = 0x09;
    ah = 0x25;
    interrupt(0x21);
    es = pop();
    ds = pop();
    sub_99d1();
loc_9972:
    ah = 0x0b;
    interrupt(0x21);
    if (al == 0)
        goto loc_9980;
    ah = 0x07;
    interrupt(0x21);
    goto loc_9972;
loc_9980:
    ds = pop();
    di = pop();
    si = pop();
}
void sub_9984()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(ds);
    push(bx);
    push(di);
    bx = 0x1228;
    ds = bx;
    di = memoryGet16(ds, 0x4d42);
    ah = 0;
    al &= 0x7f;
    di += ax;
    al = memoryGet(ds, di);
    di = pop();
    bx = pop();
    ds = pop();
    assert(pop() == 0x7777);
}
void sub_998b()
{
    push(ds);
    push(bx);
    push(di);
    bx = 0x1228;
    ds = bx;
    di = memoryGet16(ds, 0x4d42);
    ah = 0;
    al &= 0x7f;
    di += ax;
    al = memoryGet(ds, di);
    di = pop();
    bx = pop();
    ds = pop();
    flags.zero = ax == 0;
}
void sub_99d1()
{
    push(ds);
    push(ax);
    push(bx);
    ax = 0x0040;
    ds = ax;
    bx = 0x0080;
    ax = memoryBiosGet16(ds, bx);
    bx = 0x001a;
    memoryBiosSet16(ds, bx, ax);
    memoryBiosSet16(ds, bx + 2, ax);
    bx = pop();
    ax = pop();
    ds = pop();
}
void sub_9a1a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cbd9();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a2a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    di = memoryGet16(ss, bp + 6);
    si = memoryGet16(ss, bp + 4);
    bx = memoryGet16(ss, bp + 10);
    ax = memoryGet16(ss, bp + 8);
    dx = memoryGet16(ss, bp + 14);
    cx = memoryGet16(ss, bp + 12);
    bp = pop();
    push(cs);
    cs = 0x0e15;
    sub_e150();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a63()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bx = memoryGet16(ss, bp + 8);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cc41();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a77()
{
    push(cs);
    cs = 0x0ca6;
    sub_cc5f();
    assert(cs == 0x01ed);
}
void sub_9a7d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cc7b();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a8d()
{
    push(0x7777);
    push(bp);
    bp = sp;
    cl = memoryGet(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cc92();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9a9a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cd11();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9aa7()
{
    push(cs);
    cs = 0x0ca6;
    sub_cd2e();
    assert(cs == 0x01ed);
}
void sub_9aad()
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_cdb1();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9aca()
{
    sub_998b();
    cs = pop();
}
void sub_9bae()
{
    al = memoryGet(ds, 0x54d4);
    ah = 0;
    if (al == 0)
        goto loc_9bba;
    return;
loc_9bba:
    sub_9e80();
    memorySet16(ds, 0x54d6, ax);
    cx = 0x0006;
loc_9bc3:
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
loc_9bd8:
    memorySet16(ds, bx, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_9bd8;
    bx = 0x5516;
    cx = 0x0010;
    ax = 0xffff;
loc_9be8:
    memorySet16(ds, bx, ax);
    bx += 0x0002;
    if (--cx)
        goto loc_9be8;
    cx = 0x0012;
    ax = memoryGet16(ds, 0x54d6);
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
loc_9c22:
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
    memorySet16(ds, 0x54d0, bx);
    bx = es;
    memorySet16(ds, 0x54d2, bx);
    es = pop();
    ax = 0x0001;
    memorySet(ds, 0x54d4, al);
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
    memorySet16(ds, 0x54d8, bx);
    bx = es;
    memorySet16(ds, 0x54da, bx);
    es = pop();
    ax = 0x0001;
}
void sub_9c82()
{
    ax = 0x0951;
    sub_9e6a();
}
void sub_9c89()
{
    al = memoryGet(ds, 0x54d4);
    ah = 0;
    if (al == 0)
        return;
    push(ds);
    dx = memoryGet16(ds, 0x54d8);
    ds = memoryGet16(ds, 0x54d8 + 2);
    ah = 0x25;
    al = 0x0f;
    ds = pop();
    ax = memoryGet16(ds, 0x54d6);
    sub_9e6a();
    push(ds);
    dx = memoryGet16(ds, 0x54d0);
    ds = memoryGet16(ds, 0x54d0 + 2);
    ah = 0x25;
    al = 0x08;
    interrupt(0x21);
    ds = pop();
    ax = 0x0000;
    memorySet(ds, 0x54d4, al);
    ax = 0x0001;
}
void sub_9cc9()
{
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
loc_9ce5:
    ax = 0;
}
void sub_9ce8()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 4);
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
loc_9d0a:
    ax = 0;
    assert(pop() == 0x7777);
}
void sub_9cef()
{
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
loc_9d0a:
    ax = 0;
}
void sub_9d32()
{
    bx += bx;
    bx += bx;
    bx += bx;
    bx += 0x549c;
    memorySet16(ds, bx, ax);
    ax = 0;
    memorySet16(ds, bx + 2, ax);
    memorySet16(ds, bx + 6, cx);
    memorySet16(ds, bx + 4, dx);
}
void sub_9e60()
{
    sub_9e63();
    sub_9e66();
    sub_9e69();
}
void sub_9e63()
{
    sub_9e66();
    sub_9e69();
}
void sub_9e66()
{
    sub_9e69();
}
void sub_9e69()
{
}
void sub_9e6a()
{
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
void sub_9e80()
{
    push(bx);
    push(cx);
    cx = 0x0019;
    bx = 0;
    al = 0x06;
    out(0x0043, al);
    sub_9e60();
loc_9e8e:
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
loc_9ea3:
    bl = ah;
loc_9ea5:
    bh = al;
    if (--cx)
        goto loc_9e8e;
    ax = bx;
    cx = pop();
    bx = pop();
}
void sub_9f5e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ec2;
    sub_ec20();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9f6e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 6);
    bp = pop();
    push(cs);
    cs = 0x0ec2;
    sub_ec52();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9f7c()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_d4d3();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_9f8c()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_d7d7();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_a485()
{
    push(bx);
    bx = memoryGet16(cs, 0x85b3);
    if (bx != 0x0000)
        goto loc_a495;
    sub_afe5();
    goto loc_a4a9;
loc_a495:
    if (bx != 0x0004)
        goto loc_a49f;
    sub_a9a0();
    goto loc_a4a9;
loc_a49f:
    if (bx != 0x0001)
        goto loc_a4a9;
    sub_acff();
loc_a4a9:
    bx = pop();
}
void sub_a4ab()
{
    push(ax);
    ax = memoryGet16(cs, 0x85b3);
    if (ax != 0x0000)
        goto loc_a4ba;
    sub_b09f();
    goto loc_a4ce;
loc_a4ba:
    if (ax != 0x0004)
        goto loc_a4c4;
    sub_a9c6();
    goto loc_a4ce;
loc_a4c4:
    if (ax != 0x0001)
        goto loc_a4ce;
    sub_ad18();
loc_a4ce:
    ax = pop();
}
void sub_a4d0()
{
    push(cx);
    cx = memoryGet16(cs, 0x85b3);
    if (cx != 0x0000)
        goto loc_a4e0;
    sub_b0a7();
    goto loc_a4f4;
loc_a4e0:
    if (cx != 0x0004)
        goto loc_a4ea;
    sub_a9d4();
    goto loc_a4f4;
loc_a4ea:
    if (cx != 0x0001)
        goto loc_a4f4;
    sub_ad20();
loc_a4f4:
    cx = pop();
}
void sub_a4f6()
{
    push(cx);
    cx = memoryGet16(cs, 0x85b3);
    if (cx != 0x0000)
        goto loc_a506;
    sub_b0af();
    goto loc_a51a;
loc_a506:
    if (cx != 0x0004)
        goto loc_a510;
    sub_a9dd();
    goto loc_a51a;
loc_a510:
    if (cx != 0x0001)
        goto loc_a51a;
    sub_ad28();
loc_a51a:
    cx = pop();
}
void sub_a5b9()
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    ax = memoryGet16(cs, 0x85a3);
    cx = 0x0f42;
    mul(cx);
    cx = memoryGet16(cs, 0x85a5);
    bx = memoryGet16(cs, 0x85a7);
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
void sub_a5f2()
{
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
void sub_a5fe()
{
    ah = al;
    sub_a8b2();
loc_a603:
    lodsb<MemData, DirForward>();
    ah = al;
    sub_a8b2();
    if (--cx)
        goto loc_a603;
}
void sub_a60c()
{
    push(cx);
loc_a60d:
    lodsb<MemData, DirForward>();
    if (al & 0x80)
        goto loc_a615;
    lodsb<MemData, DirForward>();
    goto loc_a666;
loc_a615:
    ch = 0;
    if ((char)al < (char)0xf0)
        goto loc_a62b;
    if (al == 0xf0)
        goto loc_a626;
    if (al != 0xf7)
        goto loc_a630;
    sub_a4ab();
    goto loc_a666;
loc_a626:
    sub_a4d0();
    goto loc_a666;
loc_a62b:
    sub_a4f6();
    goto loc_a666;
loc_a630:
    lodsw<MemData, DirForward>();
    if (al != 0x51)
        goto loc_a643;
    lodsb<MemData, DirForward>();
    memorySet(cs, 0x85a7, al);
    lodsw<MemData, DirForward>();
    tl = al;
    al = ah;
    ah = tl;
    memorySet16(cs, 0x85a5, ax);
    goto loc_a666;
loc_a643:
    if (al != 0x2f)
        goto loc_a654;
    lodsw<MemData, DirForward>();
    ax = 0xffff;
    dx = ax;
    memorySet16(cs, 0x85a1, memoryGet16(cs, 0x85a1) - 1);
    goto loc_a670;
loc_a654:
    if (al != 0x20)
        goto loc_a660;
    lodsb<MemData, DirForward>();
    memorySet(cs, bx + 128, al);
    goto loc_a666;
loc_a660:
    cl = ah;
    si += cx;
loc_a666:
    sub_a761();
    if (!flags.zero)
        goto loc_a66d;
    goto loc_a60d;
loc_a66d:
    sub_a8f3();
loc_a670:
    cx = pop();
}
void sub_a672()
{
    cx = memoryGet16(cs, 0x85a1);
    bx = 0x81cc;
loc_a67a:
    si = memoryGet16(cs, bx);
    ds = memoryGet16(cs, bx + 2);
    sub_a761();
    if (!flags.zero)
        goto loc_a685;
    sub_a60c();
loc_a685:
    memorySet16(cs, bx + 64, ax);
    memorySet16(cs, bx + 66, dx);
    memorySet16(cs, bx, si);
    ax = ds;
    memorySet16(cs, bx + 2, ax);
    bx++;
    bx++;
    bx++;
    bx++;
    if (--cx)
        goto loc_a67a;
}
void sub_a6d9()
{
    if (memoryGet16(ds, si) != 0x544d)
        goto loc_a75e;
    si++;
    si++;
    if (memoryGet16(ds, si) != 0x6468)
        goto loc_a75e;
    si++;
    si++;
    if (memoryGet16(ds, si) != 0x0000)
        goto loc_a75e;
    si++;
    si++;
    if (memoryGet16(ds, si) != 0x0600)
        goto loc_a75e;
    si++;
    si++;
    if (memoryGet16(ds, si) == 0x0200)
        goto loc_a75e;
    si++;
    si++;
    lodsw<MemData, DirForward>();
    tl = al;
    al = ah;
    ah = tl;
    if (ax == 0x0000)
        goto loc_a75e;
    if ((short)ax > (short)0x0010)
        goto loc_a75e;
    memorySet16(cs, 0x85a1, ax);
    lodsw<MemData, DirForward>();
    tl = al;
    al = ah;
    ah = tl;
    if (ah & 0x80)
        goto loc_a75e;
    memorySet16(cs, 0x85a3, ax);
    cx = memoryGet16(cs, 0x85a1);
    bx = 0x81cc;
loc_a72e:
    sub_a8f3();
    lodsw<MemData, DirForward>();
    if (ax != 0x544d)
        goto loc_a75e;
    lodsw<MemData, DirForward>();
    if (ax != 0x6b72)
        goto loc_a75e;
    lodsw<MemData, DirForward>();
    if (ax != 0x0000)
        goto loc_a75e;
    lodsw<MemData, DirForward>();
    memorySet16(cs, bx, si);
    bx++;
    bx++;
    memorySet16(cs, bx, ds);
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
loc_a75e:
    ax = 0;
}
// INJECT: Error: cannot inject zero flag in sub_a761()!
void sub_a761()
{
    ax = 0;
    dx = ax;
    lodsb<MemData, DirForward>();
    if (!(al & 0x80))
        goto loc_a7ae;
    ah = al;
    lodsb<MemData, DirForward>();
    if (al & 0x80)
        goto loc_a77a;
    ax &= 0x7f7f;
    al <<= 1;
    ax >>= 1;
    goto loc_a7ae;
loc_a77a:
    tx = ax;
    ax = dx;
    dx = tx;
    lodsb<MemData, DirForward>();
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
loc_a796:
    ah = al;
    lodsb<MemData, DirForward>();
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
loc_a7ae:
    push(bx);
    bx = ax;
    bx |= dx;
    bx = pop();
    stop(/*inject ret*/);
}
void sub_a7b5()
{
    cx = 0xffff;
    ax = memoryGet16(ds, 0x557a);
    if (ax != 0)
        goto loc_a7e9;
    ax = 0x0001;
    memorySet16(ds, 0x557a, ax);
    cx = 0;
    memorySet16(ds, 0x5584, ax);
    push(cx);
    sub_a945();
    cx = pop();
    ax = 0x0004;
    if (flags.zero)
        goto loc_a7d6;
    cx |= ax;
loc_a7d6:
    push(cx);
    sub_a9fa();
    cx = pop();
    ax = 0x0001;
    if (flags.zero)
        goto loc_a7e2;
    cx |= ax;
loc_a7e2:
    memorySet16(cs, 0x85b3, ax);
    memorySet16(ds, 0x5586, ax);
loc_a7e9:
    ax = cx;
}
void sub_a7ee()
{
    push(0x7777);
    cx = 0xffff;
    ax = memoryGet16(ds, 0x557a);
    if (ax != 0x0001)
        goto loc_a827;
    ax = 0x0002;
    memorySet16(ds, 0x557a, ax);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    cx = 0x0000;
loc_a809:
    flags.carry = ax & 1;
    ax >>= 1;
    if (flags.carry)
        goto loc_a817;
    cx++;
    if (cx != 0x0010)
        goto loc_a809;
    ax = 0;
    goto loc_a82c;
loc_a817:
    ax = 0x0000;
    stop(/*carry2*/);
    ax = rcl(ax, 0x0001);
    ax <<= cl;
loc_a81e:
    memorySet16(cs, 0x85b3, ax);
    memorySet16(ds, 0x5586, ax);
    cx = ax;
loc_a827:
    ax = cx;
    assert(pop() == 0x7777);
    return;
loc_a82c:
    bx = 0x0001;
    ax = 0x0064;
    dx = 0x01ed;
    cx = 0x9136;
    sub_9cc9();
    ax = 0;
    memorySet(cs, 0x83ee, al);
    memorySet16(cs, 0x83ef, ax);
    goto loc_a81e;
}
void sub_a847()
{
    push(0x7777);
    goto loc_a847;
loc_a69d:
    push(bp);
    bp = sp;
    push(es);
    push(ds);
    push(si);
    push(di);
    ax = memoryGet16(ss, bp + 12);
    memorySet16(cs, 0x8483, ax);
    si = memoryGet16(ss, bp + 8);
    es = memoryGet16(ss, bp + 8 + 2);
    memorySet16(ds, 0x5580, si);
    si = es;
    memorySet16(ds, 0x5582, si);
    si = memoryGet16(ss, bp + 4);
    ds = memoryGet16(ss, bp + 4 + 2);
    memorySet16(cs, 0x8485, si);
    ax = ds;
    memorySet16(cs, 0x8487, ax);
    sub_a6d9();
    if (ax == 0)
        goto loc_a6d3;
    sub_a5f2();
    ax = 0x0001;
loc_a6d3:
    di = pop();
    si = pop();
    ds = pop();
    es = pop();
    bp = pop();
    assert(pop() == 0x7777);
    return;
    //   gap of 366 bytes
loc_a847:
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ds, 0x5586);
    tx = ax;
    ax = 0x0000;
    if (tx == 0)
        goto loc_a865;
    ax = 0x0000;
    sub_9cef();
    ds = pop();
    sub_a485();
    goto loc_a69d;
loc_a865:
    ds = pop();
    assert(pop() == 0x7777);
}
void sub_a869()
{
    ax = memoryGet16(cs, 0x85a1);
    if (ax != 0)
        return;
    ax = memoryGet16(cs, 0x8483);
}
void sub_a878()
{
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = 0x0000;
    sub_9cef();
    ds = pop();
    sub_a485();
}
void sub_a8b2()
{
    push(cx);
    cx = 0;
    dx = 0x0331;
loc_a8b8:
    in(al, dx);
    if (--cx && al & 0x40)
        goto loc_a8b8;
    if (stop(/*1*/))
        goto loc_a8c5;
    dx--;
    al = ah;
    out(dx, al);
loc_a8c3:
    cx = pop();
    return;
loc_a8c5:
    push(ds);
    ax = 0x1228;
    ds = ax;
    memorySet16(ds, 0x557c, cx);
    ds = pop();
    memorySet16(cs, 0x85a1, cx);
    goto loc_a8c3;
}
void sub_a8d7()
{
    push(0x7777);
    ah = 0x99;
    goto loc_a8dd;
    //   gap of 2 bytes
loc_a8dd:
    push(bp);
    bp = sp;
    push(dx);
    sub_a8b2();
    ah = memoryGet(ss, bp + 4);
    sub_a8b2();
    ah = memoryGet(ss, bp + 6);
    sub_a8b2();
    dx = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_a8f3()
{
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
void sub_a945()
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    if (memoryGet16(ds, 0x557c) == 0x0000)
        goto loc_a996;
    cx = 0x1388;
    dx = 0x0331;
loc_a956:
    in(al, dx);
    if (--cx && al & 0x40)
        goto loc_a956;
    if (stop(/*1*/))
        goto loc_a990;
    al = 0xff;
    out(dx, al);
    bx = 0x0003;
loc_a963:
    cx = 0x1388;
    dx = 0x0331;
loc_a969:
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
loc_a97e:
    in(al, dx);
    if (--cx && al & 0x40)
        goto loc_a97e;
    if (stop(/*1*/))
        goto loc_a990;
    dx = 0x0331;
    al = 0x3f;
    out(dx, al);
    goto loc_a996;
loc_a98d:
    bx--;
    if (bx != 0)
        goto loc_a963;
loc_a990:
    memorySet16(ds, 0x557c, 0x0000);
loc_a996:
    dx = pop();
    cx = pop();
    bx = pop();
    cx = pop();
    ax = memoryGet16(ds, 0x557c);
    flags.zero = ax == 0;
}
void sub_a9a0()
{
    push(dx);
    push(cx);
    push(bx);
    push(ax);
    bx = 0x9009;
loc_a9a7:
    cx = 0x007f;
loc_a9aa:
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
void sub_a9c6()
{
    push(ax);
    push(cx);
    lodsb<MemData, DirForward>();
    cl = al;
    lodsb<MemData, DirForward>();
    cl--;
    sub_a5fe();
    cx = pop();
    ax = pop();
}
void sub_a9d4()
{
    push(cx);
    cl = memoryGet(ds, si);
    si++;
    sub_a5fe();
    cx = pop();
}
void sub_a9dd()
{
    push(cx);
    if (al & 0x0f)
        goto loc_a9e7;
    al |= memoryGet(cs, bx + 128);
loc_a9e7:
    cx = 0x0002;
    ah = al;
    ah &= 0xf0;
    if (ah != 0xc0)
        goto loc_a9f5;
    cx--;
loc_a9f5:
    sub_a5fe();
    cx = pop();
}
void sub_a9fa()
{
    ax = 0x0001;
    memorySet16(ds, 0x557e, ax);
    sub_ae86();
    if (flags.zero)
        goto loc_aa0a;
    sub_adbb();
    goto loc_aa10;
loc_aa0a:
    memorySet16(ds, 0x557e, 0x0000);
loc_aa10:
    ax = memoryGet16(ds, 0x557e);
    flags.zero = ax == 0;
}
void sub_aa3b()
{
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
void sub_aa51()
{
    push(si);
    push(di);
    push(ds);
    push(es);
    si = 0x1228;
    ds = si;
    si = memoryGet16(ds, 0x5580);
    ds = memoryGet16(ds, 0x5580 + 2);
    di = memoryGet16(ds, si + 12);
    di += si;
    bx += bx;
    bx += bx;
    cx = bx;
    bx += bx;
    bx += cx;
    di += bx;
    bx = memoryGet16(ds, di);
    bx += bx;
    di = bx;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += bx;
    bx -= di;
    di = memoryGet16(ds, si + 16);
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
void sub_aa98()
{
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(ax);
    ah = 0x08;
    al = 0x00;
    sub_aed7();
    ax = pop();
    dh = memoryGet(ds, bx + di);
    if (dh == 0)
        goto loc_aaae;
    goto loc_ac56;
loc_aaae:
    dl = al;
    dl += 0xc0;
    dh = memoryGet(ds, bx + di + 4);
    dh &= 0x07;
    dh <<= 1;
    ah = memoryGet(ds, bx + di + 14);
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
    al = memoryGet(ds, di);
    di = pop();
    ds = pop();
    dl = al;
    dl += 0x40;
    dh = memoryGet(ds, bx + di + 10);
    dh &= 0x3f;
    ah = memoryGet(ds, bx + di + 2);
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
    dh = memoryGet(ds, bx + di + 5);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryGet(ds, bx + di + 8);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x80;
    dh = memoryGet(ds, bx + di + 6);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryGet(ds, bx + di + 9);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x20;
    dh = memoryGet(ds, bx + di + 3);
    dh &= 0x0f;
    ah = memoryGet(ds, bx + di + 11);
    if (ah == 0)
        goto loc_ab5e;
    dh |= 0x80;
loc_ab5e:
    ah = memoryGet(ds, bx + di + 12);
    if (ah == 0)
        goto loc_ab68;
    dh |= 0x40;
loc_ab68:
    ah = memoryGet(ds, bx + di + 7);
    if (ah == 0)
        goto loc_ab72;
    dh |= 0x20;
loc_ab72:
    ah = memoryGet(ds, bx + di + 13);
    if (ah == 0)
        goto loc_ab7c;
    dh |= 0x10;
loc_ab7c:
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x43;
    dh = memoryGet(ds, bx + di + 23);
    dh &= 0x3f;
    ah = memoryGet(ds, bx + di + 15);
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
    dh = memoryGet(ds, bx + di + 18);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryGet(ds, bx + di + 21);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x83;
    dh = memoryGet(ds, bx + di + 19);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryGet(ds, bx + di + 22);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x23;
    dh = memoryGet(ds, bx + di + 16);
    dh &= 0x0f;
    ah = memoryGet(ds, bx + di + 24);
    if (ah == 0)
        goto loc_ac02;
    dh |= 0x80;
loc_ac02:
    ah = memoryGet(ds, bx + di + 25);
    if (ah == 0)
        goto loc_ac0c;
    dh |= 0x40;
loc_ac0c:
    ah = memoryGet(ds, bx + di + 20);
    if (ah == 0)
        goto loc_ac16;
    dh |= 0x20;
loc_ac16:
    ah = memoryGet(ds, bx + di + 26);
    if (ah == 0)
        goto loc_ac20;
    dh |= 0x10;
loc_ac20:
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0xe0;
    dh = memoryGet(ds, bx + di + 28);
    dh &= 0x03;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0xe3;
    dh = memoryGet(ds, bx + di + 29);
    dh &= 0x03;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
loc_ac51:
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    return;
loc_ac56:
    al = 0x01;
    dl = al;
    dl += 0x40;
    dh = memoryGet(ds, bx + di + 10);
    dh &= 0x3f;
    ah = memoryGet(ds, bx + di + 2);
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
    dh = memoryGet(ds, bx + di + 5);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryGet(ds, bx + di + 8);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x80;
    dh = memoryGet(ds, bx + di + 6);
    dh &= 0x0f;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    dh <<= 1;
    ah = memoryGet(ds, bx + di + 9);
    ah &= 0x0f;
    dh |= ah;
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    dl = al;
    dl += 0x20;
    dh = memoryGet(ds, bx + di + 3);
    dh &= 0x0f;
    ah = memoryGet(ds, bx + di + 11);
    if (ah == 0)
        goto loc_acd5;
    dh |= 0x80;
loc_acd5:
    ah = memoryGet(ds, bx + di + 12);
    if (ah == 0)
        goto loc_acdf;
    dh |= 0x40;
loc_acdf:
    ah = memoryGet(ds, bx + di + 7);
    if (ah == 0)
        goto loc_ace9;
    dh |= 0x20;
loc_ace9:
    ah = memoryGet(ds, bx + di + 13);
    if (ah == 0)
        goto loc_acf3;
    dh |= 0x10;
loc_acf3:
    push(ax);
    ah = dl;
    al = dh;
    sub_aed7();
    ax = pop();
    goto loc_ac51;
}
void sub_acff()
{
    push(ax);
    bx = 0x0001;
loc_ad03:
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
void sub_ad18()
{
    push(ax);
    lodsb<MemData, DirForward>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_ad20()
{
    push(ax);
    lodsb<MemData, DirForward>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_ad28()
{
    push(bx);
    push(cx);
    if (al & 0x0f)
        goto loc_ad33;
    al |= memoryGet(cs, bx + 128);
loc_ad33:
    ah = al;
    ah &= 0x0f;
    if ((char)ah <= (char)0x08)
        goto loc_ad3f;
    goto loc_ad53;
loc_ad3f:
    ah = al;
    ah &= 0xf0;
    if (ah == 0xc0)
        goto loc_ad5e;
    if (ah == 0x90)
        goto loc_ad6e;
    if (ah == 0x80)
        goto loc_ad97;
loc_ad53:
    si++;
    al &= 0xf0;
    if (al == 0xc0)
        goto loc_ad5b;
    si++;
loc_ad5b:
    cx = pop();
    bx = pop();
    return;
loc_ad5e:
    sub_ad63();
    goto loc_ad5b;
    //   gap of 11 bytes
loc_ad6e:
    sub_ad73();
    goto loc_ad5b;
    //   gap of 36 bytes
loc_ad97:
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
    al = memoryGet(ds, bx);
    bx = pop();
    ds = pop();
    al &= 0xdf;
    sub_aed7();
    lodsb<MemData, DirForward>();
    lodsb<MemData, DirForward>();
    ax = pop();
    goto loc_ad5b;
}
void sub_ad63()
{
    al &= 0x0f;
    ah = al;
    al = memoryGet(ds, si);
    sub_aa3b();
    si++;
}
void sub_ad73()
{
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
    lodsb<MemData, DirForward>();
    push(ax);
    lodsb<MemData, DirForward>();
    push(ax);
    if (ax == 0)
        goto loc_ad89;
    ax = 0x0020;
loc_ad89:
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
void sub_adbb()
{
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
loc_ae61:
    sub_aed7();
    ah++;
    if (ah != 0x40)
        goto loc_ae61;
    ax = 0x6000;
loc_ae6e:
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
void sub_ae86()
{
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
loc_aea8:
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
loc_aed1:
    flags.zero = ah == 0;
    dx = pop();
    cx = pop();
    ax = pop();
}
void sub_aed7()
{
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
    memorySet(ds, bx, al);
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
void sub_af26()
{
    push(dx);
    dx = 0x0388;
    in(al, dx);
    dx = pop();
}
void sub_af2d()
{
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
    bx = memoryGet16(ss, bp + 10);
    bh = 0;
    dl = memoryGet(ds, bx + 21907);
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
    al = memoryGet(ds, bx);
    bx = pop();
    ds = pop();
    ah = 0x20;
    dh -= memoryGet(ss, bp + 6);
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
    bx = memoryGet16(ss, bp + 8);
    di = 0x55b4;
    cl = memoryGet(ds, bx + di);
    cl--;
    di = 0x5614;
    al = memoryGet(ds, bx + di);
    ah = 0;
    bx = ax;
    bx += bx;
    di = 0x559c;
    ax = memoryGet16(ds, bx + di);
    ax &= 0x03ff;
    push(ax);
    ah = al;
    al = 0xa0;
    al += memoryGet(ss, bp + 10);
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
    al += memoryGet(ss, bp + 4);
    ah = 0;
    push(ax);
    ah = al;
    al = 0xb0;
    al += memoryGet(ss, bp + 10);
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
void sub_afe5()
{
    push(ax);
    push(bx);
    push(cx);
    bx = 0x83cc;
    cx = 0x000f;
    al = 0;
loc_aff0:
    memorySet(cs, bx, al);
    bx++;
    if (--cx)
        goto loc_aff0;
    cx = pop();
    bx = pop();
    ax = pop();
    al = 0;
    memorySet(cs, 0x83ee, al);
    in(al, 0x61);
    al &= 0xfc;
    out(0x0061, al);
}
void sub_b09f()
{
    push(ax);
    lodsb<MemData, DirForward>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_b0a7()
{
    push(ax);
    lodsb<MemData, DirForward>();
    ah = 0x00;
    si += ax;
    ax = pop();
}
void sub_b0af()
{
    push(ax);
    push(bx);
    ah = al;
    ah &= 0xf0;
    if (ah == 0xc0)
        goto loc_b0f7;
    if (al & 0x0f)
        goto loc_b0c4;
    al |= memoryGet(cs, bx + 128);
loc_b0c4:
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
    lodsb<MemData, DirForward>();
    lodsb<MemData, DirForward>();
loc_b0dd:
    bx = pop();
    ax = pop();
    return;
loc_b0e0:
    lodsb<MemData, DirForward>();
    lodsb<MemData, DirForward>();
    al = 0;
loc_b0e4:
    memorySet(cs, bx, al);
    goto loc_b0dd;
loc_b0e9:
    lodsb<MemData, DirForward>();
    ah = al;
    lodsb<MemData, DirForward>();
    if (al == 0x00)
        goto loc_b0f5;
    al = ah;
    goto loc_b0e4;
loc_b0f5:
    goto loc_b0e4;
loc_b0f7:
    sub_b0fc();
    goto loc_b0dd;
}
void sub_b0fc()
{
    al &= 0x0f;
    ah = al;
    al = memoryGet(ds, si);
    push(bx);
    bx = 0x8473;
    flags.carry = (bl + ah) >= 0x100;
    bl += ah;
    bh += flags.carry;
    memorySet(cs, bx, al);
    bx = pop();
    si++;
}
void sub_b14c()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x0000;
    interrupt(0x33);
    memorySet(ds, 0x5674, al);
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
}
void sub_b274()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ed2;
    sub_ed20();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b281()
{
    push(cs);
    cs = 0x0ed2;
    sub_ed3f();
    assert(cs == 0x01ed);
}
void sub_b288()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_da88();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b298()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_dcce();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b2a8()
{
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
void sub_b2d6()
{
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
void sub_b2e0()
{
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
void sub_b2f4()
{
    push(cs);
    cs = 0x0ed9;
    sub_11ec7();
    assert(cs == 0x01ed);
}
void sub_b2fa()
{
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
void sub_b304()
{
}
void sub_b310()
{
    if (memoryGet16(ds, 0x683e) != 0x0000)
        goto loc_b321;
    in(al, 0x61);
    al |= 0x03;
    sub_b304();
    out(0x0061, al);
    return;
loc_b321:
    in(al, 0x61);
    al &= 0xfc;
    sub_b304();
    out(0x0061, al);
}
void sub_b321()
{
    in(al, 0x61);
    al &= 0xfc;
    sub_b304();
    out(0x0061, al);
}
// INJECT: Error: cannot inject flag in sub_b32b() because of being label!
void sub_b32b()
{
    if (ax == 0x00ff)
        goto loc_b337;
    if (memoryGet16(cs, 0x946c) < ax)
        goto loc_b33b;
loc_b337:
    memorySet16(cs, 0x946c, ax);
loc_b33b:
    stop(/*inject ret*/);
}
void sub_b33e()
{
    ax = memoryGet16(ds, 0x683e);
    tx = ax;
    ax = 0x00ff;
    if (tx == 0)
        goto loc_b351;
    ax = 0x0000;
    sub_b32b();
    return;
loc_b351:
    sub_b32b();
    sub_b321();
}
void sub_b358()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    ax = memoryGet16(ss, bp + 4);
    sub_b32b();
    ax = 0xffff;
    if (flags.carry)
        goto loc_b3ca;
    ax = memoryGet16(ss, bp + 6);
    memorySet16(cs, 0x9788, ax);
    ax = memoryGet16(ss, bp + 8);
    memorySet16(cs, 0x978a, ax);
    ax = memoryGet16(ss, bp + 10);
    memorySet16(cs, 0x9796, ax);
    memorySet16(cs, 0x978c, ax);
    ax = memoryGet16(ss, bp + 12);
    memorySet16(cs, 0x978e, ax);
    ax = memoryGet16(ss, bp + 14);
    memorySet16(cs, 0x9790, ax);
    ax = memoryGet16(ss, bp + 16);
    memorySet16(cs, 0x9792, ax);
    memorySet16(cs, 0x9798, ax);
    ax = memoryGet16(ss, bp + 18);
    memorySet16(cs, 0x9794, ax);
    memorySet(cs, 0x979a, 0x0f);
    cx = 0x9631;
    memorySet16(cs, 0x97a1, cx);
    dx = 0x01ed;
    memorySet16(cs, 0x979f, dx);
    ax = memoryGet16(ss, bp + 14);
    bx = 0x0002;
    sub_9cc9();
    sub_b310();
    ax = 0;
loc_b3ca:
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b3d2()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    tx = flags.carry | (flags.zero << 1);
    push(tx);
    flags.interrupts = false;
    ax = memoryGet16(ss, bp + 4);
    sub_b32b();
    ax = 0xffff;
    if (flags.carry)
        goto loc_b435;
    ax = memoryGet16(ss, bp + 6);
    memorySet16(cs, 0x9788, ax);
    ax = memoryGet16(ss, bp + 8);
    memorySet16(cs, 0x978a, ax);
    ax = memoryGet16(ss, bp + 10);
    ax = memoryGet16(ss, bp + 10);
    memorySet16(cs, 0x9790, ax);
    ax = memoryGet16(ss, bp + 12);
    memorySet16(cs, 0x9792, ax);
    memorySet16(cs, 0x9798, ax);
    ax = memoryGet16(ss, bp + 14);
    memorySet16(cs, 0x9794, ax);
    memorySet(cs, 0x979a, 0x0f);
    cx = 0x96c4;
    memorySet16(cs, 0x97a1, cx);
    dx = 0x01ed;
    memorySet16(cs, 0x979f, dx);
    ax = memoryGet16(ss, bp + 10);
    bx = 0x0002;
    sub_9cc9();
    sub_b310();
    ax = 0;
loc_b435:
    tx = pop();
    flags.carry = tx & 1;
    flags.zero = (tx << 1) & 1;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b674()
{
    push(cs);
    cs = 0x1219;
    sub_12190();
    assert(cs == 0x01ed);
}
void sub_b67a()
{
    sub_998b();
    cs = pop();
}
void sub_b695()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 4);
    dx = memoryGet16(ss, bp + 6);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_dd71();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b6a5()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_dd8b();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b6c1()
{
    push(cs);
    cs = 0x0ca6;
    sub_dddb();
    assert(cs == 0x01ed);
}
void sub_b6d4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_de4c();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b6e4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryGet16(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_de69();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b6f1()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 4);
    bx = memoryGet16(ss, bp + 6);
    cx = memoryGet16(ss, bp + 8);
    dx = memoryGet16(ss, bp + 10);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_de82();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b707()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 4);
    dx = memoryGet16(ss, bp + 6);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    sub_dea1();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
void sub_b734()
{
    push(cs);
    cs = 0x1223;
    sub_12230();
    assert(cs == 0x01ed);
}
void sub_b75e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = memoryGet16(ss, bp + 4);
    if ((short)si < 0)
        goto loc_b76e;
    if ((short)si < (short)0x0014)
        goto loc_b777;
loc_b76e:
    ax = 0x0006;
    push(ax);
    sub_c048();
    goto loc_b786;
loc_b777:
    bx = si;
    bx <<= 1;
    memorySet16(ds, bx + 27420, 0xffff);
    push(si);
    sub_be85();
    cx = pop();
loc_b786:
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b78a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    goto loc_b799;
loc_b78f:
    bx = memoryGet16(ds, 0x6982);
    bx <<= 1;
    callIndirect(cs*16+memoryGet16(ds, bx + 41406));
loc_b799:
    ax = memoryGet16(ds, 0x6982);
    memorySet16(ds, 0x6982, memoryGet16(ds, 0x6982) - 1);
    if (ax)
        goto loc_b78f;
    push(memoryGet16(ss, bp + 4));
    sub_1fc6();
    cx = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b7ad()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    ax = memoryGet16(ss, bp + 6);
    ax++;
    si = ax;
    si -= memoryGet16(ds, 0x0079);
    ax = si;
    ax += 0x003f;
    cl = 0x06;
    ax >>= cl;
    si = ax;
    if (si != memoryGet16(ds, 0x698a))
        goto loc_b7df;
loc_b7cd:
    ax = memoryGet16(ss, bp + 6);
    dx = memoryGet16(ss, bp + 4);
    memorySet16(ds, 0x0087, dx);
    memorySet16(ds, 0x0089, ax);
    ax = 0x0001;
    goto loc_b825;
loc_b7df:
    cl = 0x06;
    si <<= cl;
    di = memoryGet16(ds, 0x008d);
    ax = si;
    ax += memoryGet16(ds, 0x0079);
    if (ax <= di)
        goto loc_b7f9;
    ax = di;
    ax -= memoryGet16(ds, 0x0079);
    si = ax;
loc_b7f9:
    push(si);
    push(memoryGet16(ds, 0x0079));
    sub_c352();
    cx = pop();
    cx = pop();
    di = ax;
    if (di != 0xffff)
        goto loc_b815;
    ax = si;
    cl = 0x06;
    ax >>= cl;
    memorySet16(ds, 0x698a, ax);
    goto loc_b7cd;
loc_b815:
    ax = memoryGet16(ds, 0x0079);
    ax += di;
    memorySet16(ds, 0x008b, 0x0000);
    memorySet16(ds, 0x008d, ax);
    ax = 0;
loc_b825:
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_b82b()
{
    push(0x7777);
    push(bp);
    bp = sp;
    cx = memoryGet16(ds, 0x0085);
    bx = memoryGet16(ds, 0x0083);
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    sub_c8fb();
    if (flags.carry)
        goto loc_b861;
    cx = memoryGet16(ds, 0x008d);
    bx = memoryGet16(ds, 0x008b);
    dx = memoryGet16(ss, bp + 6);
    ax = memoryGet16(ss, bp + 4);
    sub_c8fb();
    if (!flags.zero && !flags.carry)
        goto loc_b861;
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_b7ad();
    if (ax)
        goto loc_b866;
loc_b861:
    ax = 0xffff;
    goto loc_b868;
loc_b866:
    ax = 0;
loc_b868:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b86a()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0008;
    dx = memoryGet16(ds, 0x0089);
    ax = memoryGet16(ds, 0x0087);
    cx = memoryGet16(ss, bp + 6);
    bx = memoryGet16(ss, bp + 4);
    sub_c865();
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, dx);
    cx = memoryGet16(ds, 0x0085);
    bx = memoryGet16(ds, 0x0083);
    ax = memoryGet16(ss, bp - 4);
    sub_c8fb();
    if (flags.carry)
        goto loc_b8a9;
    cx = memoryGet16(ds, 0x008d);
    bx = memoryGet16(ds, 0x008b);
    dx = memoryGet16(ss, bp - 2);
    ax = memoryGet16(ss, bp - 4);
    sub_c8fb();
    if (flags.zero || flags.carry)
        goto loc_b8b1;
loc_b8a9:
    dx = 0xffff;
    ax = 0xffff;
    goto loc_b8d3;
loc_b8b1:
    ax = memoryGet16(ds, 0x0089);
    dx = memoryGet16(ds, 0x0087);
    memorySet16(ss, bp - 8, dx);
    memorySet16(ss, bp - 6, ax);
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    sub_b7ad();
    if (ax)
        goto loc_b8cd;
    goto loc_b8a9;
loc_b8cd:
    dx = memoryGet16(ss, bp - 6);
    ax = memoryGet16(ss, bp - 8);
loc_b8d3:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b8d7()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    ax = memoryGet16(ss, bp + 4);
    ax |= memoryGet16(ss, bp + 6);
    if (ax)
        goto loc_b8e9;
    sub_b9a3();
    goto loc_b99e;
loc_b8e9:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    ax = memoryGet16(es, bx + 18);
    if (ax == memoryGet16(ss, bp + 4))
        goto loc_b8fb;
loc_b8f5:
    ax = 0xffff;
    goto loc_b9a0;
loc_b8fb:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    if ((short)memoryGet16(es, bx) < (short)0x0000)
        goto loc_b952;
    if (memoryGet16(es, bx + 2) & 0x0008)
        goto loc_b921;
    ax = memoryGet16(es, bx + 14);
    dx = memoryGet16(ss, bp + 4);
    dx += 0x0005;
    if (ax != memoryGet16(ss, bp + 6))
        goto loc_b950;
    if (memoryGet16(es, bx + 12) != dx)
        goto loc_b950;
loc_b921:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    memorySet16(es, bx, 0x0000);
    ax = memoryGet16(es, bx + 14);
    dx = memoryGet16(ss, bp + 4);
    dx += 0x0005;
    if (ax != memoryGet16(ss, bp + 6))
        goto loc_b950;
    if (memoryGet16(es, bx + 12) != dx)
        goto loc_b950;
    ax = memoryGet16(es, bx + 10);
    dx = memoryGet16(es, bx + 8);
    memorySet16(es, bx + 12, dx);
    memorySet16(es, bx + 14, ax);
    goto loc_b99e;
loc_b950:
    goto loc_b99e;
loc_b952:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    ax = memoryGet16(es, bx + 6);
    ax += memoryGet16(es, bx);
    ax++;
    si = ax;
    ax = memoryGet16(es, bx);
    ax -= si;
    memorySet16(es, bx, ax);
    push(si);
    ax = memoryGet16(es, bx + 10);
    dx = memoryGet16(es, bx + 8);
    memorySet16(es, bx + 12, dx);
    memorySet16(es, bx + 14, ax);
    push(ax);
    push(dx);
    al = memoryGet(es, bx + 4);
    cbw();
    push(ax);
    sub_bcce();
    sp += 0x0008;
    if (ax == si)
        goto loc_b99e;
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    if (memoryGet16(es, bx + 2) & 0x0200)
        goto loc_b99e;
    memorySet16(es, bx + 2, memoryGet16(es, bx + 2) | 0x0010);
    goto loc_b8f5;
loc_b99e:
    ax = 0;
loc_b9a0:
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_b9a3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    di = 0;
    si = 0x0014;
    memorySet16(ss, bp - 4, 0x698c);
    memorySet16(ss, bp - 2, ds);
    goto loc_b9d5;
loc_b9ba:
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    if (!(memoryGet16(es, bx + 2) & 0x0003))
        goto loc_b9d1;
    push(memoryGet16(ss, bp - 2));
    push(memoryGet16(ss, bp - 4));
    sub_b8d7();
    cx = pop();
    cx = pop();
    di++;
loc_b9d1:
    memorySet16(ss, bp - 4, memoryGet16(ss, bp - 4) + 0x0014);
loc_b9d5:
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
void sub_b9e4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    if ((short)memoryGet16(es, bx) >= (short)0x0000)
        goto loc_b9ff;
    ax = memoryGet16(es, bx + 6);
    ax += memoryGet16(es, bx);
    ax++;
    goto loc_ba0a;
loc_b9ff:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    ax = memoryGet16(es, bx);
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    ax ^= dx;
    ax -= dx;
loc_ba0a:
    si = ax;
    di = ax;
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    if (!(memoryGet16(es, bx + 2) & 0x0040))
        goto loc_ba1b;
    goto loc_ba5e;
loc_ba1b:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    ax = memoryGet16(es, bx + 14);
    dx = memoryGet16(es, bx + 12);
    memorySet16(ss, bp - 4, dx);
    memorySet16(ss, bp - 2, ax);
    if ((short)memoryGet16(es, bx) >= (short)0x0000)
        goto loc_ba57;
    goto loc_ba41;
loc_ba34:
    memorySet16(ss, bp - 4, memoryGet16(ss, bp - 4) - 1);
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    if (memoryGet(es, bx) != 0x0a)
        goto loc_ba41;
    di++;
loc_ba41:
    ax = si;
    si--;
    if (ax)
        goto loc_ba34;
    goto loc_ba5e;
loc_ba4a:
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    memorySet16(ss, bp - 4, memoryGet16(ss, bp - 4) + 1);
    if (memoryGet(es, bx) != 0x0a)
        goto loc_ba57;
    di++;
loc_ba57:
    ax = si;
    si--;
    if (ax)
        goto loc_ba4a;
loc_ba5e:
    ax = di;
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
    sp += 4;
}
void sub_ba68()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_b8d7();
    cx = pop();
    cx = pop();
    if (!ax)
        goto loc_ba7f;
    ax = 0xffff;
    goto loc_bae2;
loc_ba7f:
    if (memoryGet16(ss, bp + 12) != 0x0001)
        goto loc_ba9e;
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    if ((short)memoryGet16(es, bx) <= (short)0x0000)
        goto loc_ba9e;
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_b9e4();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    flags.carry = memoryGet16(ss, bp + 8) < ax;
    memorySet16(ss, bp + 8, memoryGet16(ss, bp + 8) - ax);
    memorySet16(ss, bp + 10, memoryGet16(ss, bp + 10) - (dx + flags.carry));
loc_ba9e:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    memorySet16(es, bx + 2, memoryGet16(es, bx + 2) & 0xfe5f);
    memorySet16(es, bx, 0x0000);
    ax = memoryGet16(es, bx + 10);
    dx = memoryGet16(es, bx + 8);
    memorySet16(es, bx + 12, dx);
    memorySet16(es, bx + 14, ax);
    push(memoryGet16(ss, bp + 12));
    push(memoryGet16(ss, bp + 10));
    push(memoryGet16(ss, bp + 8));
    al = memoryGet(es, bx + 4);
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
loc_bae0:
    ax = 0;
loc_bae2:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_bb32()
{
    push(0x7777);
    al = memoryGet(ds, 0x6990);
    cbw();
    push(ax);
    sub_c085();
    cx = pop();
    if (ax)
        goto loc_bb45;
    memorySet16(ds, 0x698e, memoryGet16(ds, 0x698e) & 0xfdff);
loc_bb45:
    ax = 0x0200;
    push(ax);
    if (!(memoryGet16(ds, 0x698e) & 0x0200))
        goto loc_bb56;
    ax = 0x0001;
    goto loc_bb58;
loc_bb56:
    ax = 0;
loc_bb58:
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
    al = memoryGet(ds, 0x69a4);
    cbw();
    push(ax);
    sub_c085();
    cx = pop();
    if (ax)
        goto loc_bb7d;
    memorySet16(ds, 0x69a2, memoryGet16(ds, 0x69a2) & 0xfdff);
loc_bb7d:
    ax = 0x0200;
    push(ax);
    if (!(memoryGet16(ds, 0x69a2) & 0x0200))
        goto loc_bb8e;
    ax = 0x0002;
    goto loc_bb90;
loc_bb8e:
    ax = 0;
loc_bb90:
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
void sub_bba3()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    di = memoryGet16(ss, bp + 12);
    si = memoryGet16(ss, bp + 14);
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    ax = memoryGet16(es, bx + 18);
    if (ax != memoryGet16(ss, bp + 4))
        goto loc_bbc5;
    if ((short)di > (short)0x0002)
        goto loc_bbc5;
    if (si <= 0x7fff)
        goto loc_bbcb;
loc_bbc5:
    ax = 0xffff;
    goto loc_bcb2;
loc_bbcb:
    if (memoryGet16(ds, 0x6b4a) != 0x0000)
        goto loc_bbe1;
    if (memoryGet16(ss, bp + 4) != 0x69a0)
        goto loc_bbe1;
    memorySet16(ds, 0x6b4a, 0x0001);
    goto loc_bbf5;
loc_bbe1:
    if (memoryGet16(ds, 0x6b48) != 0x0000)
        goto loc_bbf5;
    if (memoryGet16(ss, bp + 4) != 0x698c)
        goto loc_bbf5;
    memorySet16(ds, 0x6b48, 0x0001);
loc_bbf5:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    if (memoryGet16(es, bx) == 0x0000)
        goto loc_bc14;
    ax = 0x0001;
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_ba68();
    sp += 0x000a;
loc_bc14:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    if (!(memoryGet16(es, bx + 2) & 0x0004))
        goto loc_bc2c;
    push(memoryGet16(es, bx + 10));
    push(memoryGet16(es, bx + 8));
    sub_c4fe();
    cx = pop();
    cx = pop();
loc_bc2c:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    memorySet16(es, bx + 2, memoryGet16(es, bx + 2) & 0xfff3);
    memorySet16(es, bx + 6, 0x0000);
    ax = memoryGet16(ss, bp + 6);
    dx = memoryGet16(ss, bp + 4);
    dx += 0x0005;
    memorySet16(es, bx + 8, dx);
    memorySet16(es, bx + 10, ax);
    memorySet16(es, bx + 12, dx);
    memorySet16(es, bx + 14, ax);
    if (di == 0x0002)
        goto loc_bcb0;
    if (!si)
        goto loc_bcb0;
    memorySet16(ds, 0x6984, 0x9f25);
    ax = memoryGet16(ss, bp + 8);
    ax |= memoryGet16(ss, bp + 10);
    if (ax)
        goto loc_bc88;
    push(si);
    sub_c5e4();
    cx = pop();
    memorySet16(ss, bp + 8, ax);
    memorySet16(ss, bp + 10, dx);
    ax |= dx;
    if (!ax)
        goto loc_bc85;
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    memorySet16(es, bx + 2, memoryGet16(es, bx + 2) | 0x0004);
    goto loc_bc88;
loc_bc85:
    goto loc_bbc5;
loc_bc88:
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    ax = memoryGet16(ss, bp + 10);
    dx = memoryGet16(ss, bp + 8);
    memorySet16(es, bx + 12, dx);
    memorySet16(es, bx + 14, ax);
    memorySet16(es, bx + 8, dx);
    memorySet16(es, bx + 10, ax);
    memorySet16(es, bx + 6, si);
    if (di != 0x0001)
        goto loc_bcb0;
    memorySet16(es, bx + 2, memoryGet16(es, bx + 2) | 0x0008);
loc_bcb0:
    ax = 0;
loc_bcb2:
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_bcce()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x008e;
    push(si);
    push(di);
    ax = memoryGet16(ss, bp + 10);
    ax++;
    if (ax >= 0x0002)
        goto loc_bce5;
    ax = 0;
    goto loc_bdef;
loc_bce5:
    bx = memoryGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryGet16(ds, bx + 27420) & 0x8000))
        goto loc_bd07;
    push(memoryGet16(ss, bp + 10));
    push(memoryGet16(ss, bp + 8));
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_c36e();
    sp += 0x0008;
    goto loc_bdef;
loc_bd07:
    bx = memoryGet16(ss, bp + 4);
    bx <<= 1;
    memorySet16(ds, bx + 27420, memoryGet16(ds, bx + 27420) & 0xfdff);
    ax = memoryGet16(ss, bp + 8);
    dx = memoryGet16(ss, bp + 6);
    memorySet16(ss, bp - 12, dx);
    memorySet16(ss, bp - 10, ax);
    ax = memoryGet16(ss, bp + 10);
    memorySet16(ss, bp - 6, ax);
    goto loc_bd9e;
loc_bd26:
    memorySet16(ss, bp - 6, memoryGet16(ss, bp - 6) - 1);
    bx = memoryGet16(ss, bp - 12);
    es = memoryGet16(ss, bp - 12 + 2);
    memorySet16(ss, bp - 12, memoryGet16(ss, bp - 12) + 1);
    al = memoryGet(es, bx);
    memorySet(ss, bp - 7, al);
    if (al != 0x0a)
        goto loc_bd43;
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    memorySet(es, bx, 0x0d);
    memorySet16(ss, bp - 4, memoryGet16(ss, bp - 4) + 1);
loc_bd43:
    bx = memoryGet16(ss, bp - 4);
    es = memoryGet16(ss, bp - 4 + 2);
    al = memoryGet(ss, bp - 7);
    memorySet(es, bx, al);
    memorySet16(ss, bp - 4, memoryGet16(ss, bp - 4) + 1);
    ax = bp - 0x8e;
    dx = memoryGet16(ss, bp - 4);
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
loc_bd69:
    ax = bp - 0x8e;
    dx = memoryGet16(ss, bp - 4);
    bx = 0;
    flags.carry = dx < ax;
    dx -= ax;
    bx -= flags.carry;
    si = dx;
    push(si);
    push(ss);
    push(ax);
    push(memoryGet16(ss, bp + 4));
    sub_c36e();
    sp += 0x0008;
    di = ax;
    if (ax == si)
        goto loc_bd9e;
    if (stop(/*condition!*/))
        goto loc_bd94;
loc_bd8f:
    ax = 0xffff;
    goto loc_bdea;
loc_bd94:
    ax = memoryGet16(ss, bp + 10);
    ax -= memoryGet16(ss, bp - 6);
    goto loc_bde6;
    //   gap of 2 bytes
loc_bd9e:
    ax = bp - 0x8e;
    memorySet16(ss, bp - 4, ax);
    memorySet16(ss, bp - 2, ss);
loc_bda8:
    if (memoryGet16(ss, bp - 6) == 0x0000)
        goto loc_bdb1;
    goto loc_bd26;
loc_bdb1:
    ax = bp - 0x8e;
    dx = memoryGet16(ss, bp - 4);
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
    push(memoryGet16(ss, bp + 4));
    sub_c36e();
    sp += 0x0008;
    di = ax;
    if (ax == si)
        goto loc_bdec;
    if (stop(/*condition!*/))
        goto loc_bde3;
    goto loc_bd8f;
loc_bde3:
    ax = memoryGet16(ss, bp + 10);
loc_bde6:
    ax += di;
    ax -= si;
loc_bdea:
    goto loc_bdef;
loc_bdec:
    ax = memoryGet16(ss, bp + 10);
loc_bdef:
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_be68()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    cx = memoryGet16(ss, bp + 10);
    ah = 0x43;
    al = memoryGet(ss, bp + 8);
    dx = memoryGet16(ss, bp + 4);
    ds = memoryGet16(ss, bp + 4 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_be7f;
    tx = ax;
    ax = cx;
    cx = tx;
    goto loc_be83;
loc_be7f:
    push(ax);
    sub_c048();
loc_be83:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_be85()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x3e;
    bx = memoryGet16(ss, bp + 4);
    interrupt(0x21);
    if (flags.carry)
        goto loc_be9d;
    bx <<= 1;
    memorySet16(ds, bx + 27420, 0xffff);
    ax = 0;
    goto loc_bea1;
loc_be9d:
    push(ax);
    sub_c048();
loc_bea1:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_bf70()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x25;
    al = memoryGet(ss, bp + 4);
    push(ds);
    dx = memoryGet16(ss, bp + 6);
    ds = memoryGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_bfb9()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = memoryGet16(ss, bp + 4);
    memorySet16(ds, 0xa1fe, ax);
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
void sub_c01f()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x44;
    al = memoryGet(ss, bp + 6);
    bx = memoryGet16(ss, bp + 4);
    cx = memoryGet16(ss, bp + 12);
    dx = memoryGet16(ss, bp + 8);
    ds = memoryGet16(ss, bp + 8 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c042;
    if (memoryGet16(ss, bp + 6) != 0x0000)
        goto loc_c040;
    ax = dx;
    goto loc_c046;
loc_c040:
    goto loc_c046;
loc_c042:
    push(ax);
    sub_c048();
loc_c046:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c048()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    si = memoryGet16(ss, bp + 4);
    if ((short)si < 0)
        goto loc_c068;
    if ((short)si <= (short)0x0058)
        goto loc_c05b;
loc_c058:
    si = 0x0057;
loc_c05b:
    memorySet16(ds, 0x6b4e, si);
    al = memoryGet(ds, si + 27472);
    cbw();
    si = ax;
    goto loc_c079;
loc_c068:
    ax = si;
    ax = -ax;
    si = ax;
    if ((short)si > (short)0x0023)
        goto loc_c058;
    memorySet16(ds, 0x6b4e, 0xffff);
loc_c079:
    memorySet16(ds, 0x007d, si);
    ax = 0xffff;
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_c085()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ax = 0x4400;
    bx = memoryGet16(ss, bp + 4);
    interrupt(0x21);
    tx = ax;
    ax = dx;
    dx = tx;
    ax &= 0x0080;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c096()
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryGet16(ss, bp + 4);
    bx <<= 1;
    memorySet16(ds, bx + 27420, memoryGet16(ds, bx + 27420) & 0xfdff);
    ah = 0x42;
    al = memoryGet(ss, bp + 10);
    bx = memoryGet16(ss, bp + 4);
    cx = memoryGet16(ss, bp + 8);
    dx = memoryGet16(ss, bp + 6);
    interrupt(0x21);
    if (flags.carry)
        goto loc_c0b8;
    goto loc_c0bd;
loc_c0b8:
    push(ax);
    sub_c048();
    dx = ax & 0x8000 ? 0xffff : 0x0000;
loc_c0bd:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c0bf()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    cx = memoryGet16(ss, bp + 4);
    ah = 0x3c;
    dx = memoryGet16(ss, bp + 6);
    ds = memoryGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c0d2;
    goto loc_c0d6;
loc_c0d2:
    push(ax);
    sub_c048();
loc_c0d6:
    bp = pop();
    assert(pop() == 0x7777);
    sp += 6;
}
void sub_c0da()
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryGet16(ss, bp + 4);
    cx = 0;
    dx = 0;
    ah = 0x40;
    interrupt(0x21);
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
void sub_c0ec()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    si = memoryGet16(ss, bp + 8);
    if (si & 0xc000)
        goto loc_c109;
    ax = memoryGet16(ds, 0x6b44);
    ax &= 0xc000;
    dx = si;
    dx |= ax;
    si = dx;
loc_c109:
    if (si & 0x0100)
        goto loc_c112;
    goto loc_c196;
loc_c112:
    ax = memoryGet16(ds, 0x6b46);
    memorySet16(ss, bp + 10, memoryGet16(ss, bp + 10) & ax);
    ax = memoryGet16(ss, bp + 10);
    if (ax & 0x0180)
        goto loc_c127;
    ax = 0x0001;
    push(ax);
    sub_c048();
loc_c127:
    ax = 0;
    push(ax);
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_be68();
    sp += 0x0006;
    memorySet16(ss, bp - 2, ax);
    if (ax != 0xffff)
        goto loc_c16a;
    if (!(memoryGet16(ss, bp + 10) & 0x0080))
        goto loc_c149;
    ax = 0;
    goto loc_c14c;
loc_c149:
    ax = 0x0001;
loc_c14c:
    memorySet16(ss, bp - 2, ax);
    if (!(si & 0x00f0))
        goto loc_c181;
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    ax = 0;
    push(ax);
    sub_c0bf();
    di = ax;
    if ((short)ax >= 0)
        goto loc_c17a;
    goto loc_c228;
loc_c16a:
    if (!(si & 0x0400))
        goto loc_c196;
    ax = 0x0050;
    push(ax);
    sub_c048();
    goto loc_c22a;
loc_c17a:
    push(di);
    sub_be85();
    cx = pop();
    goto loc_c19b;
loc_c181:
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    push(memoryGet16(ss, bp - 2));
    sub_c0bf();
    di = ax;
    if ((short)ax >= 0)
        goto loc_c207;
    goto loc_c228;
loc_c196:
    memorySet16(ss, bp - 2, 0x0000);
loc_c19b:
    push(si);
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
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
    memorySet16(ss, bp - 4, ax);
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
loc_c1e0:
    if (!(si & 0x0200))
        goto loc_c1ea;
    push(di);
    sub_c0da();
loc_c1ea:
    if (memoryGet16(ss, bp - 2) == 0x0000)
        goto loc_c207;
    if (!(si & 0x00f0))
        goto loc_c207;
    ax = 0x0001;
    push(ax);
    push(ax);
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_be68();
    sp += 0x0008;
loc_c207:
    if ((short)di < 0)
        goto loc_c228;
    if (!(si & 0x0300))
        goto loc_c216;
    ax = 0x1000;
    goto loc_c218;
loc_c216:
    ax = 0;
loc_c218:
    dx = si;
    dx &= 0xf8ff;
    dx |= ax;
    bx = di;
    bx <<= 1;
    memorySet16(ds, bx + 27420, dx);
loc_c228:
    ax = di;
loc_c22a:
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c230()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp--;
    sp--;
    al = 0x01;
    cx = memoryGet16(ss, bp + 8);
    if (cx & 0x0002)
        goto loc_c24a;
    al = 0x02;
    if (cx & 0x0004)
        goto loc_c24a;
    al = 0x00;
loc_c24a:
    push(ds);
    dx = memoryGet16(ss, bp + 4);
    ds = memoryGet16(ss, bp + 4 + 2);
    cl = 0xf0;
    cl &= memoryGet(ss, bp + 8);
    al |= cl;
    ah = 0x3d;
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c276;
    memorySet16(ss, bp - 2, ax);
    bx = memoryGet16(ss, bp - 2);
    bx <<= 1;
    ax = memoryGet16(ss, bp + 8);
    ax &= 0xf8ff;
    ax |= 0x8000;
    memorySet16(ds, bx + 27420, ax);
    ax = memoryGet16(ss, bp - 2);
    goto loc_c27a;
loc_c276:
    push(ax);
    sub_c048();
loc_c27a:
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c27e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(si);
    push(di);
    ax = memoryGet16(ss, bp + 10);
    ax++;
    if (ax < 0x0002)
        goto loc_c29c;
    bx = memoryGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryGet16(ds, bx + 27420) & 0x0200))
        goto loc_c2a1;
loc_c29c:
    ax = 0;
    goto loc_c330;
loc_c2a1:
    push(memoryGet16(ss, bp + 10));
    push(memoryGet16(ss, bp + 8));
    push(memoryGet16(ss, bp + 6));
    push(memoryGet16(ss, bp + 4));
    sub_c336();
    sp += 0x0008;
    memorySet16(ss, bp - 2, ax);
    ax++;
    if (ax < 0x0002)
        goto loc_c2c9;
    bx = memoryGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryGet16(ds, bx + 27420) & 0x8000))
        goto loc_c2ce;
loc_c2c9:
    ax = memoryGet16(ss, bp - 2);
    goto loc_c330;
loc_c2ce:
    cx = memoryGet16(ss, bp - 2);
    si = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 6 + 2);
    di = si;
    bx = si;
    flags.direction = false;
loc_c2d9:
    lodsb_es<MemData, DirForward>();
    if (al == 0x1a)
        goto loc_c30d;
    if (al == 0x0d)
        goto loc_c2e8;
    stosb<MemData, DirForward>();
    if (--cx)
        goto loc_c2d9;
    goto loc_c305;
loc_c2e8:
    if (--cx)
        goto loc_c2d9;
    push(es);
    push(bx);
    ax = 0x0001;
    push(ax);
    ax = bp - 0x3;
    push(ss);
    push(ax);
    push(memoryGet16(ss, bp + 4));
    sub_c336();
    sp += 0x0008;
    bx = pop();
    es = pop();
    flags.direction = false;
    al = memoryGet(ss, bp - 3);
    stosb<MemData, DirForward>();
loc_c305:
    if (di != bx)
        goto loc_c30b;
    goto loc_c2a1;
loc_c30b:
    goto loc_c32d;
loc_c30d:
    push(bx);
    ax = 0x0001;
    push(ax);
    cx = -cx;
    stop(/*81*/);
    ax -= ax + flags.carry;
    push(ax);
    push(cx);
    push(memoryGet16(ss, bp + 4));
    sub_c096();
    sp += 0x0008;
    bx = memoryGet16(ss, bp + 4);
    bx <<= 1;
    memorySet16(ds, bx + 27420, memoryGet16(ds, bx + 27420) | 0x0200);
    bx = pop();
loc_c32d:
    di -= bx;
    tx = ax;
    ax = di;
    di = tx;
loc_c330:
    di = pop();
    si = pop();
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c336()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    ah = 0x3f;
    bx = memoryGet16(ss, bp + 4);
    cx = memoryGet16(ss, bp + 10);
    dx = memoryGet16(ss, bp + 6);
    ds = memoryGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c34c;
    goto loc_c350;
loc_c34c:
    push(ax);
    sub_c048();
loc_c350:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c352()
{
    push(0x7777);
    push(bp);
    bp = sp;
    ah = 0x4a;
    bx = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 4);
    interrupt(0x21);
    if (flags.carry)
        goto loc_c366;
    ax = 0xffff;
    goto loc_c36c;
loc_c366:
    push(bx);
    push(ax);
    sub_c048();
    ax = pop();
loc_c36c:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c36e()
{
    push(0x7777);
    push(bp);
    bp = sp;
    bx = memoryGet16(ss, bp + 4);
    bx <<= 1;
    if (!(memoryGet16(ds, bx + 27420) & 0x0800))
        goto loc_c391;
    ax = 0x0002;
    push(ax);
    ax = 0;
    dx = 0;
    push(ax);
    push(dx);
    push(memoryGet16(ss, bp + 4));
    sub_c096();
    sp += 0x0008;
loc_c391:
    push(ds);
    ah = 0x40;
    bx = memoryGet16(ss, bp + 4);
    cx = memoryGet16(ss, bp + 10);
    dx = memoryGet16(ss, bp + 6);
    ds = memoryGet16(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    if (flags.carry)
        goto loc_c3b1;
    push(ax);
    bx = memoryGet16(ss, bp + 4);
    bx <<= 1;
    memorySet16(ds, bx + 27420, memoryGet16(ds, bx + 27420) | 0x1000);
    ax = pop();
    goto loc_c3b5;
loc_c3b1:
    push(ax);
    sub_c048();
loc_c3b5:
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c3cc()
{
    if (dx == memoryGet16(cs, 0xa4f0))
        goto loc_c40a;
    ds = dx;
    ds = memoryGet16(ds, 0x0002);
    if (memoryGet16(ds, 0x0002) == 0x0000)
        goto loc_c3e7;
    memorySet16(cs, 0xa4f2, ds);
    goto loc_c41f;
loc_c3e7:
    ax = ds;
    if (ax == memoryGet16(cs, 0xa4f0))
        goto loc_c405;
    ax = memoryGet16(ds, 0x0008);
    memorySet16(cs, 0xa4f2, ax);
    push(ds);
    ax = 0;
    push(ax);
    sub_c49f();
    ds = memoryGet16(cs, 0xa4f6);
    goto loc_c428;
loc_c405:
    dx = memoryGet16(cs, 0xa4f0);
loc_c40a:
    memorySet16(cs, 0xa4f0, 0x0000);
    memorySet16(cs, 0xa4f2, 0x0000);
    memorySet16(cs, 0xa4f4, 0x0000);
loc_c41f:
    ds = memoryGet16(cs, 0xa4f6);
    push(dx);
    ax = 0;
    push(ax);
loc_c428:
    sub_b82b();
    ax = pop();
    ax = pop();
}
void sub_c42e()
{
    ds = dx;
    push(ds);
    es = memoryGet16(ds, 0x0002);
    memorySet16(ds, 0x0002, 0x0000);
    memorySet16(ds, 0x0008, es);
    if (dx == memoryGet16(cs, 0xa4f0))
        goto loc_c474;
    if (memoryGet16(es, 0x0002) != 0x0000)
        goto loc_c474;
    ax = memoryGet16(ds, 0x0000);
    bx = pop();
    push(es);
    memorySet16(es, 0x0000, memoryGet16(es, 0x0000) + ax);
    cx = es;
    dx += ax;
    es = dx;
    if (memoryGet16(es, 0x0002) != 0x0000)
        goto loc_c46d;
    memorySet16(es, 0x0008, cx);
    goto loc_c477;
loc_c46d:
    memorySet16(es, 0x0002, cx);
    goto loc_c477;
loc_c474:
    sub_c4c8();
loc_c477:
    es = pop();
    ax = es;
    ax += memoryGet16(es, 0x0000);
    ds = ax;
    if (memoryGet16(ds, 0x0002) == 0x0000)
        goto loc_c489;
    return;
loc_c489:
    ax = memoryGet16(ds, 0x0000);
    memorySet16(es, 0x0000, memoryGet16(es, 0x0000) + ax);
    ax = es;
    bx = ds;
    bx += memoryGet16(ds, 0x0000);
    es = bx;
    memorySet16(es, 0x0002, ax);
    bx = ds;
    if (bx == memoryGet16(ds, 0x0006))
        goto loc_c4c0;
    es = memoryGet16(ds, 0x0006);
    ds = memoryGet16(ds, 0x0004);
    memorySet16(ds, 0x0006, es);
    memorySet16(es, 0x0004, ds);
    memorySet16(cs, 0xa4f4, ds);
    ds = bx;
    return;
loc_c4c0:
    memorySet16(cs, 0xa4f4, 0x0000);
}
void sub_c49f()
{
    bx = ds;
    if (bx == memoryGet16(ds, 0x0006))
        goto loc_c4c0;
    es = memoryGet16(ds, 0x0006);
    ds = memoryGet16(ds, 0x0004);
    memorySet16(ds, 0x0006, es);
    memorySet16(es, 0x0004, ds);
    memorySet16(cs, 0xa4f4, ds);
    ds = bx;
    return;
loc_c4c0:
    memorySet16(cs, 0xa4f4, 0x0000);
}
void sub_c4c8()
{
    ax = memoryGet16(cs, 0xa4f4);
    if (!ax)
        goto loc_c4f0;
    bx = ss;
    flags.interrupts = false;
    ss = ax;
    es = memoryGet16(ss, 0x0006);
    memorySet16(ss, 0x0006, ds);
    memorySet16(ds, 0x0004, ss);
    ss = bx;
    flags.interrupts = true;
    memorySet16(es, 0x0004, ds);
    memorySet16(ds, 0x0006, es);
    return;
loc_c4f0:
    memorySet16(cs, 0xa4f4, ds);
    memorySet16(ds, 0x0004, ds);
    memorySet16(ds, 0x0006, ds);
}
void sub_c4fe()
{
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    memorySet16(cs, 0xa4f6, ds);
    dx = memoryGet16(ss, bp + 6);
    if (!dx)
        goto loc_c51e;
    if (dx != memoryGet16(cs, 0xa4f2))
        goto loc_c51b;
    sub_c3cc();
    goto loc_c51e;
loc_c51b:
    sub_c42e();
loc_c51e:
    ds = memoryGet16(cs, 0xa4f6);
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c527()
{
    push(ax);
    ds = memoryGet16(cs, 0xa4f6);
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
    ds = memoryGet16(cs, 0xa4f6);
    push(ax);
    push(dx);
    sub_b86a();
    bx = pop();
    bx = pop();
loc_c54e:
    ax = pop();
    push(ax);
    bx = 0;
    bl = ah;
    cl = 0x04;
    bx >>= cl;
    ax <<= cl;
    ds = memoryGet16(cs, 0xa4f6);
    push(bx);
    push(ax);
    sub_b86a();
    bx = pop();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_c584;
    memorySet16(cs, 0xa4f0, dx);
    memorySet16(cs, 0xa4f2, dx);
    ds = dx;
    memorySet16(ds, 0x0000, bx);
    memorySet16(ds, 0x0002, dx);
    ax = 0x0004;
    return;
loc_c584:
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
}
void sub_c588()
{
    push(ax);
    bx = 0;
    bl = ah;
    cl = 0x04;
    bx >>= cl;
    ax <<= cl;
    ds = memoryGet16(cs, 0xa4f6);
    push(bx);
    push(ax);
    sub_b86a();
    bx = pop();
    bx = pop();
    bx = pop();
    if (ax == 0xffff)
        goto loc_c5bd;
    cx = memoryGet16(cs, 0xa4f2);
    memorySet16(cs, 0xa4f2, dx);
    ds = dx;
    memorySet16(ds, 0x0000, bx);
    memorySet16(ds, 0x0002, cx);
    ax = 0x0004;
    return;
loc_c5bd:
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
}
void sub_c5c1()
{
    bx = dx;
    memorySet16(ds, 0x0000, memoryGet16(ds, 0x0000) - ax);
    dx += memoryGet16(ds, 0x0000);
    ds = dx;
    memorySet16(ds, 0x0000, ax);
    memorySet16(ds, 0x0002, bx);
    bx = dx;
    bx += memoryGet16(ds, 0x0000);
    ds = bx;
    memorySet16(ds, 0x0002, dx);
    ax = 0x0004;
}
void sub_c5e4()
{
    push(0x7777);
    push(bp);
    bp = sp;
    dx = 0;
    ax = memoryGet16(ss, bp + 4);
    goto loc_c5f7;
    //   gap of 9 bytes
loc_c5f7:
    push(si);
    push(di);
    memorySet16(cs, 0xa4f6, ds);
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
    dx = memoryGet16(cs, 0xa4f0);
    if (!dx)
        goto loc_c643;
    dx = memoryGet16(cs, 0xa4f4);
    if (!dx)
        goto loc_c63e;
    bx = dx;
loc_c62e:
    ds = dx;
    if (memoryGet16(ds, 0x0000) >= ax)
        goto loc_c652;
    dx = memoryGet16(ds, 0x0006);
    if (dx != bx)
        goto loc_c62e;
loc_c63e:
    sub_c588();
    goto loc_c662;
loc_c643:
    sub_c527();
    goto loc_c662;
loc_c648:
    sub_c5c1();
    goto loc_c662;
loc_c64d:
    ax = 0;
    dx = ax & 0x8000 ? 0xffff : 0x0000;
    goto loc_c662;
loc_c652:
    if (memoryGet16(ds, 0x0000) > ax)
        goto loc_c648;
    sub_c49f();
    bx = memoryGet16(ds, 0x0008);
    memorySet16(ds, 0x0002, bx);
    ax = 0x0004;
loc_c662:
    ds = memoryGet16(cs, 0xa4f6);
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
void sub_c7be()
{
    push(0x7777);
    cx = pop();
    push(cs);
    push(cx);
    cx = 0x0001;
    goto loc_c7d4;
    //   gap of 14 bytes
loc_c7d4:
    push(bp);
    push(si);
    push(di);
    bp = sp;
    di = cx;
    ax = memoryGet16(ss, bp + 10);
    dx = memoryGet16(ss, bp + 12);
    bx = memoryGet16(ss, bp + 14);
    cx = memoryGet16(ss, bp + 16);
    if (cx)
        goto loc_c7f3;
    if (!dx)
        goto loc_c858;
    if (!bx)
        goto loc_c858;
loc_c7f3:
    if (di & 0x0001)
        goto loc_c815;
    if (!(dx & 0x8000))
        goto loc_c807;
    dx = -dx;
    ax = -ax;
    stop(/*81*/);
    dx -= flags.carry;
    di |= 0x000c;
loc_c807:
    if (!(cx & 0x8000))
        goto loc_c815;
    cx = -cx;
    bx = -bx;
    stop(/*81*/);
    cx -= flags.carry;
    di ^= 0x0004;
loc_c815:
    bp = cx;
    cx = 0x0020;
    push(di);
    di = 0;
    si = 0;
loc_c81f:
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl(dx, 0x0001);
    si = rcl((uint16_t)si, 0x0001);
    di = rcl((uint16_t)di, 0x0001);
    if (di < bp)
        goto loc_c836;
    if (di > bp)
        goto loc_c831;
    if (si < bx)
        goto loc_c836;
loc_c831:
    flags.carry = si < bx;
    si -= bx;
    di -= bp + flags.carry;
    ax++;
loc_c836:
    if (--cx)
        goto loc_c81f;
    bx = pop();
    if (!(bx & 0x0002))
        goto loc_c845;
    ax = si;
    dx = di;
    bx >>= 1;
loc_c845:
    if (!(bx & 0x0004))
        goto loc_c852;
    dx = -dx;
    ax = -ax;
    stop(/*81*/);
    dx -= flags.carry;
loc_c852:
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    cs = pop();
    sp += 8;
    return;
loc_c858:
    div(bx);
    if (!(di & 0x0002))
        goto loc_c861;
    tx = ax;
    ax = dx;
    dx = tx;
loc_c861:
    dx = 0;
    goto loc_c852;
}
void sub_c865()
{
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
loc_c878:
    flags.carry = (ax + bx) >= 0x10000;
    ax += bx;
    if (!flags.carry)
        goto loc_c880;
    dx += 0x1000;
loc_c880:
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
loc_c8a7:
    flags.carry = ax < bx;
    ax -= bx;
    if (!flags.carry)
        goto loc_c8af;
    dx -= 0x1000;
loc_c8af:
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
}
void sub_c8c5()
{
    push(0x7777);
    es = pop();
    push(cs);
    push(es);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    si = memoryGet16(ss, bp + 6);
    ds = memoryGet16(ss, bp + 6 + 2);
    di = memoryGet16(ss, bp + 10);
    es = memoryGet16(ss, bp + 10 + 2);
    flags.direction = false;
    flags.carry = cx & 1;
    cx >>= 1;
    rep_movsw<MemData, MemData, DirForward>();
    cx += cx + flags.carry;
    rep_movsb<MemData, MemData, DirForward>();
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
//    cs = pop();
    sp += 8;
}
void sub_c8e4()
{
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
loc_c8ed:
    if (cx == 0)
        goto loc_c8f4;
    tx = ax;
    ax = cx;
    cx = tx;
    mul((uint16_t)si);
    ax += cx;
loc_c8f4:
    tx = ax;
    ax = si;
    si = tx;
    mul(bx);
    dx += si;
    si = pop();
}
void sub_c8fb()
{
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
void sub_c91e()
{
    push(0x7777);
    goto loc_c91e;
loc_20ba:
    cx = 0x001e;
    dx = 0x003b;
    ds = memoryGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memorySet(ds, bx + si, memoryGet(ds, bx + si) + al);
    ax += memoryGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df:
    if (memoryGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 6 + 2);
    ax = memoryGet16(es, bx + 6);
    dx = memoryGet16(es, bx + 4);
    memorySet16(ds, 0x6be4, dx);
    memorySet16(ds, 0x6be6, ax);
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
loc_2126:
    bp = pop();
    assert(pop() == 0x7777);
    return;
    //   gap of 42998 bytes
loc_c91e:
    memorySet16(ds, 0x6bb0, pop());
    memorySet16(ds, 0x6bb2, pop());
    memorySet16(ds, 0x6bb4, pop());
    memorySet16(cs, 0xaa4c, ds);
    memorySet16(ds, 0x6bb6, si);
    memorySet16(ds, 0x6bb8, di);
    flags.direction = false;
    es = memoryGet16(ds, 0x0079);
    si = 0x0080;
    ah = 0;
    lodsb_es<MemBios, DirForward>();
    ax++;
    bp = es;
    tx = si;
    si = dx;
    dx = tx;
    tx = ax;
    ax = bx;
    bx = tx;
    si = memoryGet16(ds, 0x0073);
    si++;
    si++;
    cx = 0x0001;
    if (memoryGet(ds, 0x007b) < 0x03)
        goto loc_c96a;
    es = memoryGet16(ds, 0x0075);
    di = si;
    cl = 0x7f;
    al = 0;
    repne_scasb<MemBios, DirForward>(al);
    if (cx == 0)
        goto loc_c9d5;
    cl ^= 0x7f;
loc_c96a:
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
    rep_movsb<MemData, MemBios, DirForward>();
    al = 0;
    stosb<MemData, DirForward>();
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
loc_c991:
    sub_c9ad();
    if (!flags.zero && !flags.carry)
        goto loc_c99d;
loc_c996:
    if (flags.carry)
        goto loc_c9d8;
    sub_c9ad();
    if (!flags.zero && !flags.carry)
        goto loc_c996;
loc_c99d:
    if (al == 0x20)
        goto loc_c9a9;
    if (al == 0x0d)
        goto loc_c9a9;
    if (al != 0x09)
        goto loc_c991;
loc_c9a9:
    al = 0;
    goto loc_c991;
    //   gap of 40 bytes
loc_c9d5:
    goto loc_20ba;
loc_c9d8:
    cx = pop();
    cx += dx;
    ds = memoryGet16(cs, 0xaa4c);
    memorySet16(ds, 0x6baa, bx);
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
    memorySet16(ds, 0x6bac, bp);
    memorySet16(ds, 0x6bae, ss);
loc_c9fb:
    if (cx == 0)
        goto loc_ca0e;
    memorySet16(ss, bp, si);
    memorySet16(ss, bp + 2, ss);
    bp += 0x0004;
loc_ca06:
    lodsb_ss<MemData, DirForward>();
    if (--cx && al)
        goto loc_ca06;
    if (false)
        goto loc_c9fb;
loc_ca0e:
    ax = 0;
    memorySet16(ss, bp, ax);
    memorySet16(ss, bp + 2, ax);
    ds = memoryGet16(cs, 0xaa4c);
    si = memoryGet16(ds, 0x6bb6);
    di = memoryGet16(ds, 0x6bb8);
    push(memoryGet16(ds, 0x6bb4));
    push(memoryGet16(ds, 0x6bb2));
    ax = memoryGet16(ds, 0x6baa);
    memorySet16(ds, 0x0069, ax);
    ax = memoryGet16(ds, 0x6bae);
    memorySet16(ds, 0x006d, ax);
    ax = memoryGet16(ds, 0x6bac);
    memorySet16(ds, 0x006b, ax);
//    stop(/*2*/); // 01ed:ab6d jmp word ptr [0x6bb0] - jump Indirect memoryGet16(ds, 0x6bb0)
}
// INJECT: Error: cannot inject flag in sub_c9ad() because of being label!
void sub_c9ad()
{
    if (!ax)
        goto loc_c9b8;
    dx++;
    stosb<MemData, DirForward>();
    if (al)
        goto loc_c9b8;
    bx++;
loc_c9b8:
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
    lodsb<MemBios, DirForward>();
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
    if (memoryGet(ds, si) != 0x22)
    {
        flags.zero = false;
        goto loc_c9d2;
    }
    lodsb<MemData, DirForward>();
    cx--;
    flags.zero = cx == 0;
loc_c9d2:
    flags.carry = false;
loc_c9d4:
    return;
}
void sub_ca53()
{
    push(0x7777);
    goto loc_ca53;
loc_1fe5:
    ds = memoryGet16(cs, 0x01ff);
    sub_2042();
    bp = sp;
    ah = 0x4c;
    al = memoryGet(ss, bp + 2);
    interrupt(0x21);
    cx = 0x000e;
    dx = 0x002d;
    goto loc_20c0;
    //   gap of 193 bytes
loc_20c0:
    ds = memoryGet16(cs, 0x01ff);
    sub_20b2();
    ax = 0x0003;
    push(ax);
    sub_1fe5();
    memorySet(ds, bx + si, memoryGet(ds, bx + si) + al);
    ax += memoryGet16(ds, bx + si + 85);
    bp = sp;
    if (memoryGet16(ds, 0x6b4c) > sp)
        goto loc_20df;
    sub_ca53();
loc_20df:
    if (memoryGet(ss, bp + 4) != 0x01)
        goto loc_2126;
    sub_22e6();
    ah = 0x00;
    if (ax)
        goto loc_2126;
    bx = memoryGet16(ss, bp + 6);
    es = memoryGet16(ss, bp + 6 + 2);
    ax = memoryGet16(es, bx + 6);
    dx = memoryGet16(es, bx + 4);
    memorySet16(ds, 0x6be4, dx);
    memorySet16(ds, 0x6be6, ax);
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
loc_2126:
    bp = pop();
    assert(pop() == 0x7777);
    return;
    //   gap of 43307 bytes
loc_ca53:
    push(cs);
    ds = pop();
    dx = 0xab71;
    ah = 0x09;
    interrupt(0x21);
    goto loc_1fe5;
}
void sub_ca60()
{
    si = 0x4de6;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    bx = memoryGet16(es, di + 28);
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
    ax = memoryGet16(ds, bx + 19916);
    ds = pop();
    callIndirect(cs*16+ax);
}
void sub_ca8b()
{
    bx = 0x0101;
loc_ca8e:
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
void sub_caa7()
{
    push(0x7777);
    push(di);
    push(ds);
    bp = 0x1228;
    ds = bp;
    bp = memoryGet16(ds, 0x5429);
    dx = memoryGet16(ds, 0x5433);
    cx = memoryGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_cabd:
    if (dl == ch)
        goto loc_cacf;
    dl--;
    cx >>= 1;
    rep_stosw<MemVideo, DirForward>();
    cl = dh;
    di -= cx;
    di += bp;
    goto loc_cabd;
loc_cacf:
    di = pop();
    assert(pop() == 0x7777);
}
void sub_cbd9()
{
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
    memorySet16(es, di + 24, 0x0014);
    memorySet16(es, di + 26, 0x0019);
    memorySet(ds, 0x541f, 0x02);
    memorySet(ds, 0x5420, 0x01);
    bx = memoryGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryGet16(ds, bx + 19930));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cc41()
{
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    es = bp;
    bp = memoryGet16(ds, 0x541d);
    bp <<= 1;
    callIndirect(cs*16+memoryGet16(ds, bp + 21557));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cc5f()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = memoryGet16(ds, 0x541d);
    bx <<= 1;
//    stop(/*2*/); // 0ca6:020a jmp word ptr [bx + 0x545d] - jump Indirect memoryGet16(ds, bx + 21597)
    assert(bx==4);
loc_cc6e:
    ax = 0x000d;
    interrupt(0x10);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cc7b()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memorySet16(ds, 0x5313, dx);
    memorySet16(ds, 0x5311, ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cc92()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    if (cl != 0x00)
        goto loc_cc9e;
    goto loc_cd0b;
loc_cc9e:
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
    rep_stosb<MemData, DirForward>();
    cx = pop();
    si = 0x5415;
    ch = 0;
    cl--;
    bx = memoryGet16(ds, 0x541d);
    bx <<= 1;
//    stop(/*2*/); // 0ca6:0264 jmp word ptr [bx + 0x5469] - jump Indirect memoryGet16(ds, bx + 21609)
loc_ccc8:
    memorySet16(ds, si + 2, 0xa000);
    memorySet16(ds, si, 0x0000);
    if (memoryGet16(ds, 0x541d) != 0x0005)
        goto loc_cce7;
    memorySet16(ds, si + 6, 0xa400);
    memorySet16(ds, si + 4, 0x0000);
    sub_d02e();
    goto loc_cd0b;
loc_cce7:
    memorySet16(ds, si + 6, 0xa200);
    memorySet16(ds, si + 4, 0x0000);
    goto loc_cd0b;
    //   gap of 24 bytes
loc_cd0b:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cd11()
{
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    es = ax;
    bp = memoryGet16(ds, 0x541d);
    bp <<= 1;
    callIndirect(cs*16+memoryGet16(ds, bp + 21569));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_cd2e()
{
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
loc_cd5d:
    if (memoryGet(ds, di) != 0x01)
        goto loc_cd70;
    ah = 0x02;
    interrupt(0x10);
    push(dx);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    dx = pop();
    dh++;
loc_cd70:
    si += 0x000f;
    di++;
    if (--cx)
        goto loc_cd5d;
loc_cd76:
    bumpyScene = "startup";
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
loc_cd8a:
    memorySet16(ds, 0x541d, 0x0001);
    memorySet16(ds, 0x530e, 0x0040);
    goto loc_cdab;
loc_cd98:
    memorySet16(ds, 0x541d, 0x0002);
    memorySet16(ds, 0x530e, 0x0040);
    goto loc_cdab;
    //   gap of 5 bytes
loc_cdab:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_cdb1()
{
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
    tl = memoryGet(ds, bx + 21263);
    memorySet(ds, bx + 21263, cl);
    cl = tl;
    si = 0x5415;
    bp = memoryGet16(ds, 0x541d);
    bp <<= 1;
    assert(bp==4);
//    stop(/*2*/); // 01ed:af04 jmp word ptr ds:[bp + 0x5475] - jump Indirect memoryGet16(ds, bp + 21621)
loc_cdd9:
    sub_d121();
loc_cdde:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ce87()
{
    ax = memoryGet16(es, di + 6);
    push(cx);
loc_ce8c:
    cx >>= 1;
    if (cx == 0)
        goto loc_ce94;
    ax <<= 1;
    goto loc_ce8c;
loc_ce94:
    cx = pop();
    if (!(memoryGet16(es, di + 28) & 0x0200))
        goto loc_cea4;
    ax++;
    memorySet16(es, di + 28, memoryGet16(es, di + 28) & 0xfdff);
loc_cea4:
    memorySet16(ds, 0x5423, ax);
    ax = 0x0014;
    if (memoryGet(ds, 0x541f) == 0x01)
        goto loc_ceb5;
    ax = memoryGet16(es, di + 10);
loc_ceb5:
    push(cx);
loc_ceb6:
    cx >>= 1;
    if (cx == 0)
        goto loc_cebe;
    ax <<= 1;
    goto loc_ceb6;
loc_cebe:
    cx = pop();
    memorySet16(ds, 0x542b, ax);
    ax = memoryGet16(es, di + 20);
    push(cx);
loc_cec7:
    cx >>= 1;
    if (cx == 0)
        goto loc_cecf;
    ax <<= 1;
    goto loc_cec7;
loc_cecf:
    cx = pop();
    if (!(memoryGet16(es, di + 28) & 0x0400))
        goto loc_cedf;
    ax++;
    memorySet16(es, di + 28, memoryGet16(es, di + 28) & 0xfbff);
loc_cedf:
    memorySet16(ds, 0x5421, ax);
    ax = 0x0014;
    if (memoryGet(ds, 0x5420) == 0x01)
        goto loc_cef0;
    ax = memoryGet16(es, di + 24);
loc_cef0:
    push(cx);
loc_cef1:
    cx >>= 1;
    if (cx == 0)
        goto loc_cef9;
    ax <<= 1;
    goto loc_cef1;
loc_cef9:
    cx = pop();
    memorySet16(ds, 0x5429, ax);
    ax = memoryGet16(es, di + 30);
    push(cx);
loc_cf02:
    cx >>= 1;
    if (cx == 0)
        goto loc_cf0a;
    ax <<= 1;
    goto loc_cf02;
loc_cf0a:
    cx = pop();
    memorySet16(ds, 0x5431, ax);
    cx = 0x0008;
    ax = memoryGet16(es, di + 8);
    push(cx);
loc_cf16:
    cx >>= 1;
    if (cx == 0)
        goto loc_cf1e;
    ax <<= 1;
    goto loc_cf16;
loc_cf1e:
    cx = pop();
    if (!(memoryGet16(es, di + 28) & 0x0100))
        goto loc_cf31;
    ax += memoryGet16(es, di + 38);
    memorySet16(es, di + 28, memoryGet16(es, di + 28) & 0x00fe);
loc_cf31:
    memorySet16(ds, 0x542f, ax);
    ax = 0x0019;
    if (memoryGet(ds, 0x541f) == 0x01)
        goto loc_cf42;
    ax = memoryGet16(es, di + 12);
loc_cf42:
    push(cx);
loc_cf43:
    cx >>= 1;
    if (cx == 0)
        goto loc_cf4b;
    ax <<= 1;
    goto loc_cf43;
loc_cf4b:
    cx = pop();
    memorySet16(ds, 0x5427, ax);
    ax = memoryGet16(es, di + 22);
    push(cx);
loc_cf54:
    cx >>= 1;
    if (cx == 0)
        goto loc_cf5c;
    ax <<= 1;
    goto loc_cf54;
loc_cf5c:
    cx = pop();
    memorySet16(ds, 0x542d, ax);
    ax = 0x0019;
    if (memoryGet(ds, 0x5420) == 0x01)
        goto loc_cf6e;
    ax = memoryGet16(es, di + 26);
loc_cf6e:
    push(cx);
loc_cf6f:
    cx >>= 1;
    if (cx == 0)
        goto loc_cf77;
    ax <<= 1;
    goto loc_cf6f;
loc_cf77:
    cx = pop();
    memorySet16(ds, 0x5425, ax);
    ax = memoryGet16(es, di + 32);
    push(cx);
loc_cf80:
    cx >>= 1;
    if (cx == 0)
        goto loc_cf88;
    ax <<= 1;
    goto loc_cf80;
loc_cf88:
    cx = pop();
    memorySet16(ds, 0x5433, ax);
}
void sub_cf8d()
{
    push(0x7777);
    push(ax);
    push(bx);
    push(cx);
    push(dx);
    push(bp);
    bx = di;
    if (memoryGet(ds, 0x541f) == 0x02)
        goto loc_cfd6;
    ax = memoryGet16(ds, 0x542f);
    mul(memoryGet16(ds, 0x542b));
    ax += memoryGet16(ds, 0x5423);
    si = ax;
    if (memoryGet(ds, 0x541f) != 0x01)
        goto loc_cfbd;
    bp = memoryGet16(es, bx);
    bp <<= 1;
    bp <<= 1;
    ax = memoryGet16(ds, bp + 21525);
    ds = memoryGet16(ds, bp + 21525 + 2);
    goto loc_cfc1;
loc_cfbd:
    ax = memoryGet16(es, bx + 2);
    ds = memoryGet16(es, bx + 2 + 2);
loc_cfc1:
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
loc_cfd6:
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ds, 0x542d);
    mul(memoryGet16(ds, 0x5429));
    ax += memoryGet16(ds, 0x5421);
    di = ax;
    if (memoryGet(ds, 0x5420) != 0x01)
        goto loc_d000;
    bp = memoryGet16(es, bx + 14);
    bp <<= 1;
    bp <<= 1;
    ax = memoryGet16(ds, bp + 21525);
    es = memoryGet16(ds, bp + 21525 + 2);
    ds = pop();
    goto loc_d010;
loc_d000:
    ax = memoryGet16(es, bx + 16);
    es = memoryGet16(es, bx + 16 + 2);
    ds = pop();
    di += ax;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0ca6);
    es = dx;
    di = ax;
loc_d010:
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
    assert(pop() == 0x7777);
}
void sub_d016()
{
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
void sub_d02e()
{
}
void sub_d02f()
{
    ax = 0;
    dl = memoryGet(ds, si + 34);
    if (!(bh & dl))
        goto loc_d03a;
    al = 0x01;
loc_d03a:
    dl = memoryGet(ds, si + 35);
    if (!(bh & dl))
        goto loc_d043;
    al |= 0x02;
loc_d043:
    dl = memoryGet(ds, si + 36);
    if (!(bh & dl))
        goto loc_d04c;
    al |= 0x04;
loc_d04c:
    dl = memoryGet(ds, si + 37);
    if (!(bh & dl))
        goto loc_d055;
    al |= 0x08;
loc_d055:
    dl = al;
    dl <<= 1;
    dl <<= 1;
    dl <<= 1;
    dl <<= 1;
    al |= dl;
    ah = al;
}
void sub_d080()
{
    di = 0x5311;
    tx = di;
    di = memoryGet16(ds, tx);
    es = memoryGet16(ds, tx + 2);
    si = ax;
    ds = dx;
    sub_d016();
    di += ax;
    di += 0x0033;
    si += 0x0033;
    push(ds);
    ax = 0x1228;
    ds = ax;
    if (memoryGet16(ds, 0x541d) != 0x0005)
        goto loc_d0a4;
    di += 0x0030;
loc_d0a4:
    ds = pop();
    cx = 0x0018;
    rep_movsw<MemData, MemData, DirForward>();
}
void sub_d0ad()
{
    dx = 0x03ce;
    cx = 0x0007;
loc_d0b3:
    lodsw<MemData, DirForward>();
    out(dx, ax);
    if (--cx)
        goto loc_d0b3;
    dx = 0x03c4;
    ax = memoryGet16(ds, si);
    out(dx, ax);
}
void sub_d0bf()
{
}
void sub_d0d7()
{
    si = 0x5311;
    tx = si;
    si = memoryGet16(ds, tx);
    es = memoryGet16(ds, tx + 2);
    sub_d016();
    si += ax;
    si += 0x0033;
    dx = 0x03c8;
    al = 0x00;
    out(dx, al);
    dx++;
    cx = 0x0008;
loc_d0ee:
    al = memoryGet(es, si);
    out(dx, al);
    al = memoryGet(es, si + 1);
    out(dx, al);
    al = memoryGet(es, si + 2);
    out(dx, al);
    si += 0x0003;
    if (--cx)
        goto loc_d0ee;
    dx--;
    al = 0x10;
    out(dx, al);
    dx++;
    cx = 0x0008;
loc_d109:
    al = memoryGet(es, si);
    out(dx, al);
    al = memoryGet(es, si + 1);
    out(dx, al);
    al = memoryGet(es, si + 2);
    out(dx, al);
    si += 0x0003;
    if (--cx)
        goto loc_d109;
}
void sub_d121()
{
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
    ax = memoryGet16(ds, si + 2);
    tx = memoryGet16(ds, bx + si + 2);
    memorySet16(ds, bx + si + 2, ax);
    ax = tx;
    memorySet16(ds, si + 2, ax);
}
void sub_d250()
{
    push(0x7777);
    cx = 0x0002;
    sub_ce87();
    ax = memoryGet16(ds, 0x542b);
    mul(memoryGet16(ds, 0x5427));
    bp = ax;
    ax = memoryGet16(ds, 0x5429);
    mul(memoryGet16(ds, 0x5425));
    bx = ax;
    ax = memoryGet16(es, di + 28);
    sub_cf8d();
    push(bx);
    push(ds);
    bx = ax;
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryGet16(ds, bx + 21814);
    ds = pop();
    bx = pop();
    callIndirect(cs*16+ax);
    assert(pop() == 0x7777);
}
void sub_d283()
{
    push(0x7777);
    flags.direction = false;
    ax = 0;
loc_d286:
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
loc_d2f1:
    assert(pop() == 0x7777);
}
void sub_d2b8()
{
    push(0x7777);
    push(bx);
    push(bp);
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryGet16(ds, 0x542b);
    bp = memoryGet16(ds, 0x5429);
    dx = memoryGet16(ds, 0x5433);
    cx = memoryGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_d2d5:
    if (dl == 0x00)
        goto loc_d2ec;
    dl--;
    cx >>= 1;
    rep_movsw<MemData, MemData, DirForward>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += bp;
    goto loc_d2d5;
loc_d2ec:
    di = pop();
    si = pop();
    bp = pop();
    bx = pop();
    assert(pop() == 0x7777);
}
void sub_d37f()
{
    push(0x7777);
    memorySet(cs, 0x0973, 0x21);
    goto loc_d395;
    //   gap of 14 bytes
loc_d395:
    ax = 0;
loc_d397:
    sub_d3a7();
    ah++;
    if ((char)ah > (char)0x03)
        goto loc_d3ef;
    si += bp;
    di += bx;
    goto loc_d397;
    //   gap of 72 bytes
loc_d3ef:
    assert(pop() == 0x7777);
}
void sub_d3a7()
{
    push(0x7777);
    push(ax);
    push(bx);
    push(bp);
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryGet16(ds, 0x542b);
    bp = memoryGet16(ds, 0x5429);
    dx = memoryGet16(ds, 0x5433);
    cx = memoryGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx == 0)
        goto loc_d3e9;
loc_d3c7:
    if (dl == 0x00)
        goto loc_d3e9;
    dl--;
    cx >>= 1;
loc_d3d0:
    ax = memoryGet16(ds, si);
    memorySet16(es, di, memoryGet16(es, di) & ax);
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
loc_d3e9:
    di = pop();
    si = pop();
    bp = pop();
    bx = pop();
    ax = pop();
    assert(pop() == 0x7777);
}
void sub_d4d3()
{
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
    memorySet(ds, 0x541f, 0x00);
    memorySet(ds, 0x5420, 0x00);
    bx = memoryGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryGet16(ds, bx + 21828));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_d500()
{
    push(0x7777);
    si = 0x556a;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    ax = memoryGet16(ds, 0x542b);
    mul(memoryGet16(ds, 0x5427));
    bp = ax;
    bx = memoryGet16(es, di + 28);
    push(bx);
    bx = di;
    sub_cf8d();
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryGet16(ds, bx + 21840);
    ds = pop();
    callIndirect(cs*16+ax);
    assert(pop() == 0x7777);
}
void sub_d530()
{
    push(0x7777);
    flags.direction = false;
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    al = 0x01;
loc_d539:
    dx = 0x03c5;
    out(dx, al);
    goto loc_d560;
loc_d53f:
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
loc_d560:
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryGet16(ds, 0x542b);
    dx = memoryGet16(ds, 0x5433);
    cx = memoryGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_d577:
    if (dl == ch)
        goto loc_d58e;
    dl--;
    cx >>= 1;
    rep_movsw<MemVideo, MemData, DirForward>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += bx;
    di += 0x0028;
    goto loc_d577;
loc_d58e:
    di = pop();
    si = pop();
    goto loc_d53f;
loc_d592:
    assert(pop() == 0x7777);
}
void sub_d593()
{
    push(0x7777);
    memorySet16(cs, 0x0b81, 0x9090);
    goto loc_d5a3;
    //   gap of 7 bytes
loc_d5a3:
    dx = 0x03c4;
    ax = 0x0002;
    out(dx, ax);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryGet16(ds, 0x542b);
    dx = memoryGet16(ds, 0x5433);
    cx = memoryGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx == 0)
        goto loc_d5c3;
    goto loc_d5c6;
loc_d5c3:
    goto loc_d65c;
loc_d5c6:
    if (dl != ch)
        goto loc_d5cd;
    goto loc_d65c;
loc_d5cd:
    dl--;
    cx >>= 1;
    push(dx);
loc_d5d2:
    ax = memoryGet16(ds, si);
    si += bp;
    ax |= memoryGet16(ds, si);
    si += bp;
    ax |= memoryGet16(ds, si);
    si += bp;
    ax |= memoryGet16(ds, si);
    push(si);
    ch = ah;
    ah = al;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    al = memoryVideoGet(es, di);
    dx = 0x03c5;
    al = 0x08;
    out(dx, al);
    ah = memoryGet(ds, si);
    memoryVideoSet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    ah = memoryGet(ds, si);
    memoryVideoSet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    ah = memoryGet(ds, si);
    memoryVideoSet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    assert(es >= 0xa000 && ds < 0xa000);
    movsb<MemVideo, MemData, DirForward>();
    ah = ch;
    si = pop();
    si++;
    dx = 0x03ce;
    al = 0x08;
    out(dx, ax);
    al = memoryVideoGet(es, di);
    dx = 0x03c5;
    al = 0x08;
    out(dx, al);
    ah = memoryGet(ds, si);
    memoryVideoSet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    ah = memoryGet(ds, si);
    memoryVideoSet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    ah = memoryGet(ds, si);
    memoryVideoSet(es, di, ah);
    al >>= 1;
    out(dx, al);
    si -= bp;
    movsb<MemVideo, MemData, DirForward>();
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
loc_d65c:
    assert(pop() == 0x7777);
}
void sub_d65d()
{
    push(0x7777);
    memorySet(cs, 0x0c63, 0x21);
    goto loc_d673;
    //   gap of 14 bytes
loc_d673:
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    al = 0x00;
    ah = 0x01;
loc_d683:
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
loc_d6de:
    assert(pop() == 0x7777);
}
void sub_d665()
{
    push(0x7777);
    memorySet(cs, 0x0c63, 0x09);
    goto loc_d673;
    //   gap of 6 bytes
loc_d673:
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    dx = 0x03c4;
    al = 0x02;
    out(dx, al);
    al = 0x00;
    ah = 0x01;
loc_d683:
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
loc_d6de:
    assert(pop() == 0x7777);
}
void sub_d69e()
{
    push(ax);
    push(si);
    push(di);
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx = memoryGet16(ds, 0x542b);
    dx = memoryGet16(ds, 0x5433);
    cx = memoryGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
    if (cx == 0)
        goto loc_d6da;
loc_d6b8:
    if (dl == ch)
        goto loc_d6da;
    dl--;
    cx >>= 1;
loc_d6c0:
    ax = memoryGet16(ds, si);
    memorySet16(es, di, memoryGet16(es, di) & ax);
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
loc_d6da:
    di = pop();
    si = pop();
    ax = pop();
}
void sub_d7d7()
{
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
    bp = memoryGet16(es, di + 14);
    if ((short)bp > (short)0x0001)
        goto loc_d802;
    memorySet(ds, 0x541f, 0x00);
    memorySet(ds, 0x5420, 0x01);
    bx = memoryGet16(ds, 0x541d);
    bx <<= 1;
    assert(bx == 4);
    callIndirect(cs*16+memoryGet16(ds, bx + 21854));
loc_d802:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_d810()
{
    push(0x7777);
    si = 0x56a4;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    ax = memoryGet16(ds, 0x5429);
    mul(memoryGet16(ds, 0x5425));
    bp = ax;
    bx = memoryGet16(es, di + 28);
    push(bx);
    bx = di;
    sub_cf8d();
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryGet16(ds, bx + 22154);
    ds = pop();
    callIndirect(cs*16+ax);
    assert(pop() == 0x7777);
}
void sub_d840()
{
    push(0x7777);
    flags.direction = false;
    dx = 0x03ce;
    al = 0x04;
    out(dx, al);
    al = 0x00;
loc_d849:
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
loc_d89b:
    assert(pop() == 0x7777);
}
void sub_d869()
{
    push(si);
    push(di);
    push(ds);
    bx = 0x1228;
    ds = bx;
    bx = memoryGet16(ds, 0x5429);
    dx = memoryGet16(ds, 0x5433);
    cx = memoryGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_d880:
    if (dl == 0x00)
        goto loc_d898;
    dl--;
    cx >>= 1;
    rep_movsw<MemData, MemVideo, DirForward>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += 0x0028;
    di += bx;
    goto loc_d880;
loc_d898:
    di = pop();
    si = pop();
}
void sub_da88()
{
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
    bp = memoryGet16(es, di);
    if ((short)bp > (short)0x0001)
        goto loc_dab2;
    memorySet(ds, 0x541f, 0x01);
    memorySet(ds, 0x5420, 0x00);
    bx = memoryGet16(ds, 0x541d);
    bx <<= 1;
    assert(bx==4);
    callIndirect(cs*16+memoryGet16(ds, bx + 22168));
loc_dab2:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_dac0()
{
    si = 0x56ce;
    sub_d0ad();
    cx = 0x0002;
    sub_ce87();
    bx = memoryGet16(es, di + 28);
    push(bx);
    bx = di;
    sub_cf8d();
    bx = pop();
    push(ds);
    ax = 0x1228;
    ds = ax;
    bx <<= 1;
    ax = memoryGet16(ds, bx + 22196);
    ds = pop();
    callIndirect(cs*16+ax);
}
void sub_dae7()
{
    flags.direction = false;
    dx = 0x03c4;
    ax = 0x0f02;
    out(dx, ax);
    push(ds);
    ax = 0x1228;
    ds = ax;
    dx = memoryGet16(ds, 0x5433);
    cx = memoryGet16(ds, 0x5431);
    dh = cl;
    ds = pop();
loc_db00:
    if (dl == 0x00)
        return;
    dl--;
    rep_movsb<MemVideo, MemVideo, DirForward>();
    cl = dh;
    si -= cx;
    di -= cx;
    si += 0x0028;
    di += 0x0028;
    goto loc_db00;
}
void sub_dcce()
{
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
    bx = memoryGet16(es, di);
    if ((short)bx > (short)0x0001)
        goto loc_dd01;
    bp = memoryGet16(es, di + 14);
    if ((short)bp > (short)0x0001)
        goto loc_dd01;
    memorySet(ds, 0x541f, 0x01);
    memorySet(ds, 0x5420, 0x01);
    si = memoryGet16(ds, 0x541d);
    si <<= 1;
    callIndirect(cs*16+memoryGet16(ds, si + 22210));
loc_dd01:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_dd71()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    bx = memoryGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryGet16(ds, bx + 26950));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_dd8b()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memorySet16(ds, 0x68a4, dx);
    memorySet16(ds, 0x68a2, ax);
    di = 0x68a2;
    bx = memoryGet16(ds, di + 2);
    es = bx;
    di = memoryGet16(ds, di);
    al = memoryGet(es, di + 3);
    al += 0x02;
    memorySet(ds, 0x693e, al);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_dddb()
{
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
    cs = pop();
}
void sub_de1c()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = false;
    bx = 0x1228;
    ds = bx;
    di = 0x68a2;
    bx = memoryGet16(ds, di + 2);
    es = bx;
    di = memoryGet16(ds, di);
    if (al < memoryGet(es, di))
        goto loc_de46;
    if (al >= memoryGet(es, di + 1))
        goto loc_de46;
    bx = memoryGet16(ds, 0x541d);
    bx <<= 1;
    callIndirect(cs*16+memoryGet16(ds, bx + 26962));
loc_de46:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_de4c()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = false;
    ds = dx;
    si = ax;
loc_de56:
    al = memoryGet(ds, si);
    if (al == 0x00)
        goto loc_de63;
    push(cs);
    sub_de1c();
    si++;
    goto loc_de56;
loc_de63:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_de69()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    if ((short)bx > (short)0x0001)
        goto loc_de7c;
    ax = 0x1228;
    ds = ax;
    memorySet16(ds, 0x6940, bx);
loc_de7c:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_de82()
{
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    memorySet16(ds, 0x6936, ax);
    memorySet16(ds, 0x6938, bx);
    memorySet16(ds, 0x693a, cx);
    memorySet16(ds, 0x693c, dx);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_dea1()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memorySet16(ds, 0x6944, dx);
    memorySet16(ds, 0x6942, ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_deb8()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memorySet(ds, 0x693e, al);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_deee()
{
    push(0x7777);
    si = 0x695e;
    memorySet16(ds, si, 0x68b6);
    memorySet16(ds, si + 2, ds);
    bp = memoryGet16(ds, 0x6940);
    bp <<= 1;
    bp <<= 1;
    ax += memoryGet16(ds, bp + 21525);
    memorySet16(ds, si + 8, ax);
    ax = memoryGet16(ds, bp + 21527);
    memorySet16(ds, si + 10, ax);
    ax = 0;
    al = bl;
    memorySet16(ds, si + 12, ax);
    al = bh;
    memorySet16(ds, si + 14, ax);
    al = cl;
    memorySet16(ds, si + 16, ax);
    al = ch;
    memorySet16(ds, si + 18, ax);
    memorySet(ds, si + 22, dl);
    dx = ds;
    ax = si;
    push(cs);
    cs = 0x0ed9;
    sub_11aa5();
    assert(cs == 0x0ca6);
    assert(pop() == 0x7777);
}
void sub_df33()
{
    al -= memoryGet(es, di);
    ah = 0;
    ax <<= 1;
    bx = es;
    ds = bx;
    si = di;
    si += 0x0006;
    si += ax;
    ax = memoryGet16(ds, si);
    tl = al;
    al = ah;
    ah = tl;
    ax += di;
    si = ax;
}
void sub_df4f()
{
    si = 0x68a6;
    sub_df5f();
    si = 0x68ae;
    ax = dx;
    sub_df5f();
    return;
    //   gap of 46 bytes
}
void sub_df5f()
{
    memorySet16(ds, si, 0x0000);
    memorySet16(ds, si + 2, 0x0000);
    if (!(ax & 0x0001))
        goto loc_df70;
    memorySet(ds, si, 0xff);
loc_df70:
    if (!(ax & 0x0002))
        goto loc_df79;
    memorySet(ds, si + 1, 0xff);
loc_df79:
    if (!(ax & 0x0004))
        goto loc_df84;
    memorySet(ds, si + 2, 0xff);
    if (!(ax & 0x0004))
        goto loc_df84;
loc_df84:
    if (!(ax & 0x0008))
        return;
    memorySet(ds, si + 3, 0xff);
}
void sub_df90()
{
    push(ax);
    push(dx);
    if ((short)ax < (short)memoryGet16(ds, 0x6936))
        goto loc_dfbb;
    flags.carry = (al + bh) >= 0x100;
    al += bh;
    if (!flags.carry)
        goto loc_df9e;
    ah++;
loc_df9e:
    ax--;
    if ((short)ax > (short)memoryGet16(ds, 0x693a))
        goto loc_dfbb;
    if ((short)dx < (short)memoryGet16(ds, 0x6938))
        goto loc_dfbb;
    flags.carry = (dl + bl) >= 0x100;
    dl += bl;
    if (!flags.carry)
        goto loc_dfb1;
    dh++;
loc_dfb1:
    dx--;
    if ((short)dx > (short)memoryGet16(ds, 0x693c))
        goto loc_dfbb;
    flags.carry = false;
    goto loc_dfbc;
loc_dfbb:
    flags.carry = true;
loc_dfbc:
    dx = pop();
    ax = pop();
}
void sub_dfbf()
{
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
loc_dfd5:
    ax = memoryGet16(ds, si);
    memorySet16(ds, di, ax);
    ax = memoryGet16(ds, si + 2);
    memorySet16(ds, di + 2, ax);
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
}
void sub_dfee()
{
    push(0x7777);
    sub_dfbf();
    sub_df33();
    al = memoryGet(es, di + 2);
    bl = memoryGet(es, di + 3);
    bh = memoryGet(ds, si);
    cl = bh;
    bh += memoryGet(es, di + 4);
    dl = memoryGet(ds, si + 1);
    dh = memoryGet(ds, si + 2);
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
void sub_e01d()
{
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
loc_e03d:
    flags.carry = true;
    al = rcr(al, 0x01);
    if (--cx)
        goto loc_e03d;
    cx = 0x0004;
loc_e045:
    if (bl == 0x00)
        goto loc_e05c;
    bl--;
loc_e04c:
    memorySet(es, di, memoryGet(es, di) & al);
    di++;
    if (--cx)
        goto loc_e04c;
    cx = 0x0004;
    di -= cx;
    di += 0x0008;
    goto loc_e045;
loc_e05c:
    es = pop();
    ds = pop();
    si = pop();
    di = pop();
    bp = pop();
    dx = pop();
    cx = pop();
    bx = pop();
    ax = pop();
}
void sub_e067()
{
    push(0x7777);
    sub_dfee();
    if (cl != 0x00)
        goto loc_e072;
    goto loc_e13d;
loc_e072:
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
loc_e08c:
    if (dl == 0x00)
        goto loc_e0ea;
    dl--;
    push(di);
    push(dx);
loc_e095:
    al = memoryGet(ds, si);
    bl = al;
    bh = al;
    ax = memoryGet16(es, bp);
    ax &= bx;
    dx = ax;
    ax = memoryGet16(es, bp + 2);
    ax &= bx;
    dx |= ax;
    dh |= dl;
    dl = dh;
    dx = ~dx;
    if (dx == 0xffff)
        goto loc_e0d2;
    ax = memoryGet16(es, bp);
    ax &= bx;
    memorySet16(es, di, memoryGet16(es, di) & dx);
    memorySet16(es, di, memoryGet16(es, di) | ax);
    ax = memoryGet16(es, bp + 2);
    ax &= bx;
    memorySet16(es, di + 2, memoryGet16(es, di + 2) & dx);
    memorySet16(es, di + 2, memoryGet16(es, di + 2) | ax);
    goto loc_e0db;
loc_e0d2:
    bx = ~bx;
    memorySet16(es, di, memoryGet16(es, di) & bx);
    memorySet16(es, di + 2, memoryGet16(es, di + 2) & bx);
loc_e0db:
    si++;
    di += 0x0004;
    if (--cx)
        goto loc_e095;
    dx = pop();
    cl = dh;
    di = pop();
    di += 0x0008;
    goto loc_e08c;
loc_e0ea:
    bx = pop();
    ax = 0x1228;
    ds = ax;
    dx = pop();
    dh = 0;
    dx = -dx;
    dx += memoryGet16(ds, 0x6944);
    ax = memoryGet16(ds, 0x6942);
    flags.carry = (memoryGet(ds, 0x6942) + bh) >= 0x100;
    memorySet(ds, 0x6942, memoryGet(ds, 0x6942) + bh);
    if (!flags.carry)
        goto loc_e108;
    memorySet16(ds, 0x6942, memoryGet16(ds, 0x6942) + 0x0100);
loc_e108:
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
loc_e13d:
    sub_d0bf();
    assert(pop() == 0x7777);
}
void sub_e150()
{
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    memorySet16(ds, 0x4e10, di);
    memorySet16(ds, 0x4e0c, di);
    memorySet16(ds, 0x4e0e, si);
    memorySet16(ds, 0x4e0a, si);
    es = di;
    di = si;
    memorySet16(ds, 0x4e14, bx);
    memorySet16(ds, 0x4e2a, bx);
    memorySet16(ds, 0x4e12, ax);
    memorySet16(ds, 0x4e28, ax);
    bx = dx;
    ax = cx;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4e0c, dx);
    memorySet16(ds, 0x4e0a, ax);
loc_e18c:
    sub_eb59();
    if (!flags.carry)
        goto loc_e196;
    ax = 0x0003;
    goto loc_e1c8;
loc_e196:
    push(si);
    push(ds);
    bp = 0x1228;
    ds = bp;
    si = memoryGet16(ds, 0x4e31);
    si &= 0x7fff;
    si--;
    si <<= 1;
    bp = memoryGet16(ds, si + 20023);
    ds = pop();
    si = pop();
    callIndirect(cs*16+bp);
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ds, 0x4e35);
    memorySet16(ds, 0x4e2a, ax);
    ax = memoryGet16(ds, 0x4e33);
    memorySet16(ds, 0x4e28, ax);
    if ((short)memoryGet16(ds, 0x4e31) > (short)0x0000)
        goto loc_e18c;
loc_e1c8:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_e1ce()
{
    dx = memoryGet16(ds, 0x4e26);
    memorySet16(ds, 0x4e14, dx);
    ax = memoryGet16(ds, 0x4e24);
    memorySet16(ds, 0x4e12, ax);
    memorySet(ds, 0x4e12, memoryGet(ds, 0x4e12) & 0xf0);
    if (dx != memoryGet16(ds, 0x4e14))
        goto loc_e1ed;
    if (ax == memoryGet16(ds, 0x4e12))
        goto loc_e1f8;
loc_e1ed:
    flags.carry = (memoryGet16(ds, 0x4e12) + 0x0010) >= 0x10000;
    memorySet16(ds, 0x4e12, memoryGet16(ds, 0x4e12) + 0x0010);
    if (!flags.carry)
        goto loc_e1f8;
    memorySet16(ds, 0x4e14, memoryGet16(ds, 0x4e14) + 1);
loc_e1f8:
    ax = memoryGet16(ds, 0x4e0c);
    memorySet16(ds, 0x4e18, ax);
    ax = memoryGet16(ds, 0x4e0a);
    memorySet16(ds, 0x4e16, ax);
    ax = memoryGet16(ds, 0x4e18);
    es = ax;
    di = memoryGet16(ds, 0x4e16);
    bx = memoryGet16(ds, 0x4e14);
    ax = memoryGet16(ds, 0x4e12);
    push(cs);
    cs = 0x0ec7;
    sub_ecb5();
    assert(cs == 0x0e15);
    al &= 0xfe;
    memorySet16(ds, 0x4e08, dx);
    memorySet16(ds, 0x4e06, ax);
    es = dx;
    di = ax;
    bx = memoryGet16(ds, 0x4e14);
    ax = memoryGet16(ds, 0x4e12);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4dfc, dx);
    memorySet16(ds, 0x4dfa, ax);
    ax = memoryGet16(ds, 0x4e10);
    es = ax;
    di = memoryGet16(ds, 0x4e0e);
    bx = memoryGet16(ds, 0x4e14);
    ax = memoryGet16(ds, 0x4e12);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4df8, dx);
    memorySet16(ds, 0x4df6, ax);
    es = dx;
    di = ax;
    bx = 0;
    ax = 0x0010;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4e00, dx);
    memorySet16(ds, 0x4dfe, ax);
    if (dx < memoryGet16(ds, 0x4dfc))
        goto loc_e285;
    if (dx != memoryGet16(ds, 0x4dfc))
        goto loc_e278;
    if (ax <= memoryGet16(ds, 0x4dfa))
        goto loc_e285;
loc_e278:
    memorySet16(ds, 0x4e14, 0x0000);
    memorySet16(ds, 0x4e12, 0x0002);
    return;
loc_e285:
    cx = memoryGet16(ds, 0x4e14);
    bx = memoryGet16(ds, 0x4e12);
    ax = memoryGet16(ds, 0x4dfc);
    es = ax;
    di = memoryGet16(ds, 0x4dfa);
    si = memoryGet16(ds, 0x4df6);
    ax = memoryGet16(ds, 0x4df8);
    ds = ax;
loc_e29f:
    flags.carry = si < 0x0002;
    si -= 0x0002;
    if (!flags.carry)
        goto loc_e2ac;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e2ac:
    flags.carry = di < 0x0002;
    di -= 0x0002;
    if (!flags.carry)
        goto loc_e2b9;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e2b9:
    ax = memoryGet16(ds, si);
    memorySet16(es, di, ax);
    flags.carry = bx < 0x0002;
    bx -= 0x0002;
    if (!flags.carry)
        goto loc_e2c7;
    bx += 0x0010;
    cx--;
loc_e2c7:
    if (cx != 0x0000)
        goto loc_e29f;
    if (bx != 0x0000)
        goto loc_e29f;
    ax = 0x1228;
    ds = ax;
    memorySet16(ds, 0x4e14, 0x0000);
    memorySet16(ds, 0x4e12, 0x0001);
}
void sub_e2e4()
{
    push(0x7777);
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ds, 0x4e10);
    es = ax;
    di = memoryGet16(ds, 0x4e0e);
    bx = 0;
    ax = 0x000c;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4e08, dx);
    memorySet16(ds, 0x4e06, ax);
    es = dx;
    di = ax;
    al = memoryGet(es, di);
    memorySet(ds, 0x4e22, al);
    memorySet16(ds, 0x4e06, memoryGet16(ds, 0x4e06) + 1);
    ax = memoryGet16(ds, 0x4e10);
    es = ax;
    di = memoryGet16(ds, 0x4e0e);
    bx = memoryGet16(ds, 0x4e26);
    ax = memoryGet16(ds, 0x4e24);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4df8, dx);
    memorySet16(ds, 0x4df6, ax);
    bx = memoryGet16(ds, 0x4e2a);
    ax = memoryGet16(ds, 0x4e28);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4dfc, dx);
    memorySet16(ds, 0x4dfa, ax);
    ax = 0x1228;
    es = ax;
    di = 0x4e97;
    bx = 0;
    ax = 0x0400;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4e04, dx);
    memorySet16(ds, 0x4e02, ax);
    es = dx;
    di = ax;
    memorySet16(ds, 0x4e2f, dx);
    memorySet16(ds, 0x4e2d, ax);
    si = memoryGet16(ds, 0x4dfa);
    ax = memoryGet16(ds, 0x4dfc);
    ds = ax;
    cx = 0x0400;
loc_e370:
    flags.carry = si < 0x0001;
    si -= 0x0001;
    if (!flags.carry)
        goto loc_e37d;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e37d:
    flags.carry = di < 0x0001;
    di -= 0x0001;
    if (!flags.carry)
        goto loc_e38a;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e38a:
    al = memoryGet(ds, si);
    memorySet(es, di, al);
    ax = ds;
    bp = cx;
    bx = 0x1228;
    ds = bx;
    dx = memoryGet16(ds, 0x4e08);
    cx = memoryGet16(ds, 0x4e06);
    ds = ax;
    if (ax != dx)
        goto loc_e3aa;
    if (si == cx)
        goto loc_e3ff;
loc_e3aa:
    cx = bp;
    if (--cx)
        goto loc_e370;
    bp = ds;
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ds, 0x4df8);
    memorySet16(ds, 0x4e04, ax);
    di = memoryGet16(ds, 0x4df6);
    memorySet16(ds, 0x4e02, di);
    es = ax;
    ds = bp;
loc_e3c7:
    flags.carry = si < 0x0001;
    si -= 0x0001;
    if (!flags.carry)
        goto loc_e3d4;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e3d4:
    flags.carry = di < 0x0001;
    di -= 0x0001;
    if (!flags.carry)
        goto loc_e3e1;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e3e1:
    al = memoryGet(ds, si);
    memorySet(es, di, al);
    ax = ds;
    bx = 0x1228;
    ds = bx;
    dx = memoryGet16(ds, 0x4e08);
    cx = memoryGet16(ds, 0x4e06);
    ds = ax;
    if (ax != dx)
        goto loc_e3c7;
    if (si != cx)
        goto loc_e3c7;
loc_e3ff:
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ds, 0x4e10);
    memorySet16(ds, 0x4e00, ax);
    ax = memoryGet16(ds, 0x4e0e);
    memorySet16(ds, 0x4dfe, ax);
    ax = es;
    ds = ax;
    si = di;
loc_e416:
    al = memoryGet(ds, si);
    bp = ds;
    bx = 0x1228;
    ds = bx;
    memorySet(ds, 0x4e2c, al);
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
    dx = memoryGet16(ds, 0x4df8);
    cx = memoryGet16(ds, 0x4df6);
    ds = bx;
    if (bx != dx)
        goto loc_e465;
    if (si != cx)
        goto loc_e465;
    ds = bp;
    ax = 0x1228;
    memorySet16(ds, 0x4e04, ax);
    si = 0x4e97;
    memorySet16(ds, 0x4e02, si);
    ds = ax;
loc_e465:
    bp = ds;
    bx = 0x1228;
    ds = bx;
    al = memoryGet(ds, 0x4e22);
    ah = memoryGet(ds, 0x4e2c);
    ds = bp;
    if (al == ah)
        goto loc_e47c;
    goto loc_e565;
loc_e47c:
    al = memoryGet(ds, si);
    ds = bx;
    memorySet(ds, 0x4e1e, al);
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
    dx = memoryGet16(ds, 0x4df8);
    cx = memoryGet16(ds, 0x4df6);
    ds = bx;
    if (bx != dx)
        goto loc_e4c6;
    if (si != cx)
        goto loc_e4c6;
    ds = bp;
    ax = 0x1228;
    memorySet16(ds, 0x4e04, ax);
    si = 0x4e97;
    memorySet16(ds, 0x4e02, si);
    ds = ax;
loc_e4c6:
    bp = ds;
    bx = 0x1228;
    ds = bx;
    al = memoryGet(ds, 0x4e22);
    ah = memoryGet(ds, 0x4e1e);
    ds = bp;
    if (al != ah)
        goto loc_e4dd;
    goto loc_e565;
loc_e4dd:
    al = memoryGet(ds, si);
    ds = bx;
    memorySet(ds, 0x4e16, al);
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
    dx = memoryGet16(ds, 0x4df8);
    cx = memoryGet16(ds, 0x4df6);
    ds = bx;
    if (bx != dx)
        goto loc_e527;
    if (si != cx)
        goto loc_e527;
    ds = bp;
    ax = 0x1228;
    memorySet16(ds, 0x4e04, ax);
    si = 0x4e97;
    memorySet16(ds, 0x4e02, si);
    ds = ax;
loc_e527:
    bp = ds;
    bx = 0x1228;
    ds = bx;
    ax = memoryGet16(ds, 0x4e00);
    es = ax;
    di = memoryGet16(ds, 0x4dfe);
    al = memoryGet(ds, 0x4e1e);
    memorySet(es, di, al);
    di += 0x0001;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    memorySet16(ds, 0x4e00, dx);
    memorySet16(ds, 0x4dfe, ax);
    if (bp != dx)
        goto loc_e55b;
    if (si != di)
        goto loc_e55b;
    goto loc_e5fe;
loc_e55b:
    memorySet(ds, 0x4e16, memoryGet(ds, 0x4e16) - 1);
    flags.zero = memoryGet(ds, 0x4e16) == 0;
    ds = bp;
    if (!flags.zero)
        goto loc_e527;
    goto loc_e590;
loc_e565:
    bp = ds;
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ds, 0x4e00);
    es = ax;
    di = memoryGet16(ds, 0x4dfe);
    al = memoryGet(ds, 0x4e2c);
    memorySet(es, di, al);
    di += 0x0001;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    memorySet16(ds, 0x4e00, dx);
    memorySet16(ds, 0x4dfe, ax);
    ds = bp;
loc_e590:
    bp = ds;
    dx = es;
    if (bp != dx)
        goto loc_e59c;
    if (si == di)
        goto loc_e5fe;
loc_e59c:
    bx = 0x1228;
    ds = bx;
    dx = memoryGet16(ds, 0x4e2f);
    cx = memoryGet16(ds, 0x4e2d);
    ds = bp;
    if (bp == dx)
        goto loc_e5b2;
    goto loc_e416;
loc_e5b2:
    if (si == cx)
        goto loc_e5b9;
    goto loc_e416;
loc_e5b9:
    ax = 0x1228;
    ds = ax;
    push(di);
    push(es);
    ax = memoryGet16(ds, 0x4e26);
    es = ax;
    di = memoryGet16(ds, 0x4e24);
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4e26, dx);
    memorySet16(ds, 0x4e24, ax);
    es = pop();
    di = pop();
    ax = memoryGet16(ds, 0x4e0e);
    flags.carry = di < ax;
    di -= ax;
    if (!flags.carry)
        goto loc_e5e6;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e5e6:
    bx = memoryGet16(ds, 0x4e10);
    ax = es;
    ax -= bx;
    if (ax != memoryGet16(ds, 0x4e26))
        goto loc_e5ff;
    if (di != memoryGet16(ds, 0x4e24))
        goto loc_e5ff;
    ax = 0x0001;
    assert(pop() == 0x7777);
    return;
loc_e5fe:
    assert(pop() == 0x7777);
    return;
loc_e5ff:
    assert(pop() == 0x7777);
}
void sub_e600()
{
    push(0x7777);
    goto loc_e600;
loc_e5fe:
    assert(pop() == 0x7777);
    return;
    //   gap of 1 bytes
loc_e600:
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ds, 0x4e10);
    es = ax;
    di = memoryGet16(ds, 0x4e0e);
    bx = memoryGet16(ds, 0x4e26);
    ax = memoryGet16(ds, 0x4e24);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    if (dx > memoryGet16(ds, 0x4e0c))
        goto loc_e5fe;
    if (dx != memoryGet16(ds, 0x4e0c))
        goto loc_e628;
    if (ax > memoryGet16(ds, 0x4e0a))
        goto loc_e5fe;
loc_e628:
    ax = memoryGet16(ds, 0x4e10);
    es = ax;
    di = memoryGet16(ds, 0x4e0e);
    bx = 0;
    ax = 0x000c;
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4df8, dx);
    memorySet16(ds, 0x4df6, ax);
    es = dx;
    di = ax;
    ax = memoryGet16(es, di);
    tl = al;
    al = ah;
    ah = tl;
    memorySet16(ds, 0x4e22, ax);
    memorySet16(ds, 0x4df6, memoryGet16(ds, 0x4df6) + 0x0002);
    dx = memoryGet16(ds, 0x4e26);
    memorySet16(ds, 0x4e20, dx);
    ax = memoryGet16(ds, 0x4e24);
    memorySet16(ds, 0x4e1e, ax);
    memorySet(ds, 0x4e1e, memoryGet(ds, 0x4e1e) & 0xe0);
    if (dx != memoryGet16(ds, 0x4e20))
        goto loc_e679;
    if (ax == memoryGet16(ds, 0x4e1e))
        goto loc_e67f;
    dx = memoryGet16(ds, 0x4e20);
    ax = memoryGet16(ds, 0x4e1e);
loc_e679:
    flags.carry = (ax + 0x0020) >= 0x10000;
    ax += 0x0020;
    if (!flags.carry)
        goto loc_e67f;
    dx++;
loc_e67f:
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    flags.carry = dx & 1;
    dx >>= 1;
    ax = rcr(ax, 0x0001);
    memorySet16(ds, 0x4e20, dx);
    memorySet16(ds, 0x4e1e, ax);
    ax = memoryGet16(ds, 0x4e0c);
    memorySet16(ds, 0x4e18, ax);
    di = memoryGet16(ds, 0x4e0a);
    memorySet16(ds, 0x4e16, di);
    es = ax;
    bx = memoryGet16(ds, 0x4e20);
    ax = memoryGet16(ds, 0x4e1e);
    push(cs);
    cs = 0x0ec7;
    sub_ecb5();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4e18, dx);
    memorySet16(ds, 0x4e16, ax);
    memorySet(ds, 0x4e16, memoryGet(ds, 0x4e16) & 0xfe);
    dx = memoryGet16(ds, 0x4e18);
    memorySet16(ds, 0x4dfc, dx);
    ax = memoryGet16(ds, 0x4e16);
    memorySet16(ds, 0x4dfa, ax);
    memorySet16(ds, 0x4e00, dx);
    memorySet16(ds, 0x4dfe, ax);
    es = dx;
    di = ax;
    ax = memoryGet16(ds, 0x4e20);
    memorySet16(ds, 0x4e18, ax);
    ax = memoryGet16(ds, 0x4e1e);
    memorySet16(ds, 0x4e16, ax);
    si = memoryGet16(ds, 0x4df6);
    ax = memoryGet16(ds, 0x4df8);
    ds = ax;
loc_e6e8:
    ax = memoryGet16(ds, si + 2);
    memorySet16(es, di + 2, ax);
    ax = memoryGet16(ds, si);
    memorySet16(es, di, ax);
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
    ax = memoryGet16(ds, 0x4e18);
    es = ax;
    di = memoryGet16(ds, 0x4e16);
    bx = 0;
    ax = 0x0004;
    push(cs);
    cs = 0x0ec7;
    sub_ecb5();
    assert(cs == 0x0e15);
    es = pop();
    di = pop();
    memorySet16(ds, 0x4e18, dx);
    memorySet16(ds, 0x4e16, ax);
    ds = bp;
    if (dx != 0x0000)
        goto loc_e6e8;
    if (ax != 0x0000)
        goto loc_e6e8;
    ax = 0x1228;
    ds = ax;
    memorySet16(ds, 0x4df8, bp);
    memorySet16(ds, 0x4df6, si);
    ax = es;
    memorySet16(ds, 0x4e00, ax);
    memorySet16(ds, 0x4dfe, di);
    ax = memoryGet16(ds, 0x4e26);
    push(ax);
    ax = memoryGet16(ds, 0x4e24);
    push(ax);
    ax = memoryGet16(ds, 0x4dfc);
    push(ax);
    ax = memoryGet16(ds, 0x4dfa);
    push(ax);
    ax = memoryGet16(ds, 0x4e0c);
    push(ax);
    ax = memoryGet16(ds, 0x4e0a);
    push(ax);
    ax = memoryGet16(ds, 0x4dfc);
    memorySet16(ds, 0x4e0c, ax);
    ax = memoryGet16(ds, 0x4dfa);
    memorySet16(ds, 0x4e0a, ax);
    ax = memoryGet16(ds, 0x4e2a);
    memorySet16(ds, 0x4e26, ax);
    ax = memoryGet16(ds, 0x4e28);
    memorySet16(ds, 0x4e24, ax);
    sub_e1ce();
    ax = pop();
    memorySet16(ds, 0x4e0a, ax);
    ax = pop();
    memorySet16(ds, 0x4e0c, ax);
    ax = pop();
    memorySet16(ds, 0x4dfa, ax);
    ax = pop();
    memorySet16(ds, 0x4dfc, ax);
    ax = pop();
    memorySet16(ds, 0x4e24, ax);
    ax = pop();
    memorySet16(ds, 0x4e26, ax);
    if (memoryGet16(ds, 0x4e14) != 0x0000)
        goto loc_e7bb;
    if (memoryGet16(ds, 0x4e12) != 0x0002)
        goto loc_e7bb;
    goto loc_e5fe;
loc_e7bb:
    ax = memoryGet16(ds, 0x4e26);
    push(ax);
    ax = memoryGet16(ds, 0x4e24);
    push(ax);
    ax = memoryGet16(ds, 0x4e2a);
    push(ax);
    ax = memoryGet16(ds, 0x4e28);
    push(ax);
    ax = memoryGet16(ds, 0x4e0c);
    push(ax);
    ax = memoryGet16(ds, 0x4e0a);
    push(ax);
    ax = memoryGet16(ds, 0x4e08);
    es = ax;
    di = memoryGet16(ds, 0x4e06);
    bx = memoryGet16(ds, 0x4e2a);
    ax = memoryGet16(ds, 0x4e28);
    push(cs);
    cs = 0x0ec7;
    sub_ec70();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4e04, dx);
    memorySet16(ds, 0x4e02, ax);
    bx = memoryGet16(ds, 0x4e20);
    ax = memoryGet16(ds, 0x4e1e);
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
    memorySet16(ds, 0x4e08, dx);
    memorySet16(ds, 0x4e06, ax);
    ax = memoryGet16(ds, 0x4e0c);
    memorySet16(ds, 0x4e00, ax);
    di = memoryGet16(ds, 0x4e0a);
    memorySet16(ds, 0x4dfe, di);
    es = ax;
    bx = 0;
    ax = 0x0400;
    push(cs);
    cs = 0x0ec7;
    sub_ecb5();
    assert(cs == 0x0e15);
    memorySet16(ds, 0x4e00, dx);
    memorySet16(ds, 0x4dfe, ax);
    ax = memoryGet16(ds, 0x4dfc);
    memorySet16(ds, 0x4e0c, ax);
    ax = memoryGet16(ds, 0x4dfa);
    memorySet16(ds, 0x4e0a, ax);
    ax = memoryGet16(ds, 0x4e10);
    memorySet16(ds, 0x4df8, ax);
    ax = memoryGet16(ds, 0x4e0e);
    memorySet16(ds, 0x4df6, ax);
    memorySet16(ds, 0x4e1c, 0x0000);
    memorySet16(ds, 0x4e1a, 0x0000);
    memorySet16(ds, 0x4e14, 0x0000);
    memorySet16(ds, 0x4e12, 0x0000);
    memorySet16(ds, 0x4e18, 0x0000);
    memorySet16(ds, 0x4e16, 0x0000);
loc_e86d:
    memorySet16(ds, 0x4e16, memoryGet16(ds, 0x4e16) - 0x0001);
    if ((short)memoryGet16(ds, 0x4e16) >= 0)
        goto loc_e8c2;
    bp = ds;
    si = memoryGet16(ds, 0x4e0a);
    ax = memoryGet16(ds, 0x4e0c);
    ds = ax;
    dx = memoryGet16(ds, si + 2);
    tl = dl;
    dl = dh;
    dh = tl;
    ax = memoryGet16(ds, si);
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
    memorySet16(ds, 0x4e0c, cx);
    memorySet16(ds, 0x4e0a, si);
    memorySet16(ds, 0x4e16, 0x001f);
    memorySet16(ds, 0x4e26, ax);
    memorySet16(ds, 0x4e24, dx);
loc_e8c2:
    dx = memoryGet16(ds, 0x4e26);
    ax = memoryGet16(ds, 0x4e24);
    flags.carry = !!(ax & 0x8000);
    ax <<= 1;
    dx = rcl(dx, 0x0001);
    memorySet16(ds, 0x4e26, dx);
    memorySet16(ds, 0x4e24, ax);
    if (!flags.carry)
        goto loc_e8d9;
    goto loc_ea27;
loc_e8d9:
    ax = memoryGet16(ds, 0x4df8);
    es = ax;
    di = memoryGet16(ds, 0x4df6);
    si = memoryGet16(ds, 0x4e06);
    ax = memoryGet16(ds, 0x4e08);
    ds = ax;
    al = memoryGet(ds, si);
    memorySet(es, di, al);
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
    memorySet16(ds, 0x4e08, bp);
    memorySet16(ds, 0x4e06, si);
    ax = es;
    memorySet16(ds, 0x4df8, ax);
    memorySet16(ds, 0x4df6, di);
    flags.carry = (memoryGet16(ds, 0x4e12) + 0x0001) >= 0x10000;
    memorySet16(ds, 0x4e12, memoryGet16(ds, 0x4e12) + 0x0001);
    if (!flags.carry)
        goto loc_e937;
    memorySet16(ds, 0x4e14, memoryGet16(ds, 0x4e14) + 1);
loc_e937:
    dx = memoryGet16(ds, 0x4e00);
    ax = memoryGet16(ds, 0x4dfe);
    if (dx != memoryGet16(ds, 0x4df8))
        goto loc_e962;
    if (ax != memoryGet16(ds, 0x4df6))
        goto loc_e962;
    ax = 0x1228;
    memorySet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memorySet16(ds, 0x4df6, ax);
    memorySet16(ds, 0x4e1c, 0x0000);
    memorySet16(ds, 0x4e1a, 0x0001);
loc_e962:
    dx = memoryGet16(ds, 0x4e08);
    ax = memoryGet16(ds, 0x4e06);
    if (dx != memoryGet16(ds, 0x4e04))
        goto loc_e978;
    if (ax != memoryGet16(ds, 0x4e02))
        goto loc_e978;
    goto loc_ea84;
loc_e978:
    dx = memoryGet16(ds, 0x4e08);
    ax = memoryGet16(ds, 0x4e06);
    if (dx <= memoryGet16(ds, 0x4df8))
        goto loc_e988;
    goto loc_e86d;
loc_e988:
    if (dx != memoryGet16(ds, 0x4df8))
        goto loc_e993;
    if (ax <= memoryGet16(ds, 0x4df6))
        goto loc_e993;
    goto loc_e86d;
loc_e993:
    if (memoryGet16(ds, 0x4e1c) == 0x0000)
        goto loc_e99d;
    goto loc_e86d;
loc_e99d:
    if (memoryGet16(ds, 0x4e1a) == 0x0000)
        goto loc_e9a7;
    goto loc_e86d;
loc_e9a7:
    ax = memoryGet16(ds, 0x4e0c);
    memorySet16(ds, 0x4dfc, ax);
    ax = memoryGet16(ds, 0x4e0a);
    memorySet16(ds, 0x4dfa, ax);
    dx = memoryGet16(ds, 0x4e08);
    cx = memoryGet16(ds, 0x4e06);
    ax = memoryGet16(ds, 0x4dfc);
    es = ax;
    di = memoryGet16(ds, 0x4dfa);
    si = memoryGet16(ds, 0x4e02);
    ax = memoryGet16(ds, 0x4e04);
    ds = ax;
loc_e9cd:
    flags.carry = si < 0x0001;
    si -= 0x0001;
    if (!flags.carry)
        goto loc_e9da;
    si += 0x0010;
    ax = ds;
    ax--;
    ds = ax;
loc_e9da:
    flags.carry = di < 0x0001;
    di -= 0x0001;
    if (!flags.carry)
        goto loc_e9e7;
    di += 0x0010;
    ax = es;
    ax--;
    es = ax;
loc_e9e7:
    al = memoryGet(ds, si);
    memorySet(es, di, al);
    ax = ds;
    if (dx != ax)
        goto loc_e9cd;
    if (cx != si)
        goto loc_e9cd;
    ax = 0x1228;
    ds = ax;
    memorySet16(ds, 0x4e04, bp);
    memorySet16(ds, 0x4e02, si);
    ax = es;
    memorySet16(ds, 0x4dfc, ax);
    memorySet16(ds, 0x4dfa, di);
    ax = memoryGet16(ds, 0x4dfc);
    memorySet16(ds, 0x4e08, ax);
    ax = memoryGet16(ds, 0x4dfa);
    memorySet16(ds, 0x4e06, ax);
    ax = memoryGet16(ds, 0x4e0c);
    memorySet16(ds, 0x4e04, ax);
    ax = memoryGet16(ds, 0x4e0a);
    memorySet16(ds, 0x4e02, ax);
    goto loc_e86d;
loc_ea27:
    ax = memoryGet16(ds, 0x4df8);
    es = ax;
    di = memoryGet16(ds, 0x4df6);
    al = memoryGet(ds, 0x4e22);
    memorySet(es, di, al);
    di += 0x0001;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    ax = es;
    memorySet16(ds, 0x4df8, ax);
    memorySet16(ds, 0x4df6, di);
    flags.carry = (memoryGet16(ds, 0x4e12) + 0x0001) >= 0x10000;
    memorySet16(ds, 0x4e12, memoryGet16(ds, 0x4e12) + 0x0001);
    if (!flags.carry)
        goto loc_ea56;
    memorySet16(ds, 0x4e14, memoryGet16(ds, 0x4e14) + 1);
loc_ea56:
    dx = memoryGet16(ds, 0x4e00);
    ax = memoryGet16(ds, 0x4dfe);
    if (dx != memoryGet16(ds, 0x4df8))
        goto loc_ea81;
    if (ax != memoryGet16(ds, 0x4df6))
        goto loc_ea81;
    ax = 0x1228;
    memorySet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memorySet16(ds, 0x4df6, ax);
    memorySet16(ds, 0x4e1c, 0x0000);
    memorySet16(ds, 0x4e1a, 0x0001);
loc_ea81:
    goto loc_e978;
loc_ea84:
    ax = pop();
    memorySet16(ds, 0x4e0a, ax);
    ax = pop();
    memorySet16(ds, 0x4e0c, ax);
    ax = pop();
    memorySet16(ds, 0x4e28, ax);
    ax = pop();
    memorySet16(ds, 0x4e2a, ax);
    ax = pop();
    memorySet16(ds, 0x4e24, ax);
    ax = pop();
    memorySet16(ds, 0x4e26, ax);
loc_ea9c:
    al = memoryGet(ds, 0x4e22);
    memorySet(es, di, al);
    di += 0x0001;
    push(cs);
    cs = 0x0ec7;
    sub_ecf9();
    assert(cs == 0x0e15);
    es = dx;
    di = ax;
    flags.carry = (memoryGet16(ds, 0x4e12) + 0x0001) >= 0x10000;
    memorySet16(ds, 0x4e12, memoryGet16(ds, 0x4e12) + 0x0001);
    if (!flags.carry)
        goto loc_eab9;
    memorySet16(ds, 0x4e14, memoryGet16(ds, 0x4e14) + 1);
loc_eab9:
    dx = memoryGet16(ds, 0x4e00);
    ax = memoryGet16(ds, 0x4dfe);
    if (dx != memoryGet16(ds, 0x4df8))
        goto loc_eae4;
    if (ax != memoryGet16(ds, 0x4df6))
        goto loc_eae4;
    ax = 0x1228;
    memorySet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memorySet16(ds, 0x4df6, ax);
    memorySet16(ds, 0x4e1c, 0x0000);
    memorySet16(ds, 0x4e1a, 0x0001);
loc_eae4:
    dx = memoryGet16(ds, 0x4e26);
    ax = memoryGet16(ds, 0x4e24);
    if (dx > memoryGet16(ds, 0x4e14))
        goto loc_ea9c;
    if (dx != memoryGet16(ds, 0x4e14))
        goto loc_eaf9;
    if (ax > memoryGet16(ds, 0x4e12))
        goto loc_ea9c;
loc_eaf9:
    ax = 0x1228;
    memorySet16(ds, 0x4df8, ax);
    ax = 0x4e97;
    memorySet16(ds, 0x4df6, ax);
    cx = 0x0400;
    cx >>= 1;
    cx >>= 1;
    ax = memoryGet16(ds, 0x4e00);
    es = ax;
    di = memoryGet16(ds, 0x4dfe);
    si = memoryGet16(ds, 0x4df6);
    ax = memoryGet16(ds, 0x4df8);
    ds = ax;
loc_eb1e:
    ax = memoryGet16(ds, si + 2);
    memorySet16(es, di + 2, ax);
    ax = memoryGet16(ds, si);
    memorySet16(es, di, ax);
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
void sub_eb59()
{
    ax = memoryGet16(ds, 0x4e2a);
    push(ax);
    ax = memoryGet16(ds, 0x4e28);
    push(ax);
    ax = memoryGet16(ds, 0x4e0c);
    push(ax);
    ax = memoryGet16(ds, 0x4e0a);
    push(ax);
    ax = memoryGet16(ds, 0x4e10);
    es = ax;
    push(ax);
    ax = memoryGet16(ds, 0x4e0e);
    di = ax;
    push(ax);
    ax = memoryGet16(es, di);
    tl = al;
    al = ah;
    ah = tl;
    bx = memoryGet16(es, di + 2);
    tl = bl;
    bl = bh;
    bh = tl;
    memorySet16(ds, 0x4e26, ax);
    memorySet16(ds, 0x4e24, bx);
    memorySet16(ds, 0x4e35, ax);
    memorySet16(ds, 0x4e33, bx);
    if (ax > 0x000f)
        goto loc_ec06;
    if (ax != 0x000f)
        goto loc_eba0;
    if (bx > 0xffff)
        goto loc_ec06;
loc_eba0:
    ax = memoryGet16(es, di + 6);
    tl = al;
    al = ah;
    ah = tl;
    bx = memoryGet16(es, di + 4);
    tl = bl;
    bl = bh;
    bh = tl;
    memorySet16(ds, 0x4e20, ax);
    memorySet16(ds, 0x4e1e, bx);
    ax = memoryGet16(es, di + 8);
    tl = al;
    al = ah;
    ah = tl;
    memorySet16(ds, 0x4e31, ax);
    si = ax;
    si &= 0x003f;
    if (si > 0x001e)
        goto loc_ec06;
    si += si;
    bx = memoryGet16(ds, si + 20059);
    tl = bl;
    bl = bh;
    bh = tl;
    if ((short)bx < (short)0x0000)
        goto loc_ec06;
    si = ax;
    si &= 0x7f00;
    if (si != 0)
        goto loc_ec06;
    bx = memoryGet16(ds, 0x4e26);
    ax = memoryGet16(ds, 0x4e24);
    si = memoryGet16(ds, 0x4e31);
    si ^= bx;
    si ^= ax;
    memorySet16(ds, 0x4e26, bx);
    memorySet16(ds, 0x4e24, ax);
    ax = memoryGet16(ds, 0x4e20);
    bx = memoryGet16(ds, 0x4e1e);
    si ^= bx;
    si ^= ax;
    ax = memoryGet16(es, di + 10);
    tl = al;
    al = ah;
    ah = tl;
    if (si == ax)
        goto loc_ec07;
loc_ec06:
    flags.carry = true;
loc_ec07:
    ax = pop();
    memorySet16(ds, 0x4e0e, ax);
    ax = pop();
    memorySet16(ds, 0x4e10, ax);
    ax = pop();
    memorySet16(ds, 0x4e0a, ax);
    ax = pop();
    memorySet16(ds, 0x4e0c, ax);
    ax = pop();
    memorySet16(ds, 0x4e28, ax);
    ax = pop();
    memorySet16(ds, 0x4e2a, ax);
}
void sub_ec20()
{
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
loc_ec2b:
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
loc_ec48:
    dx = 0;
    ax = 0;
loc_ec4c:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_ec52()
{
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
    cs = pop();
}
void sub_ec70()
{
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
loc_ecaf:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_ecb5()
{
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
loc_ecea:
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
void sub_ecf9()
{
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
    cs = pop();
}
void sub_ed20()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x1228;
    ds = bx;
    memorySet16(ds, 0x5676, ax);
    memorySet16(ds, 0x5678, 0x0000);
    memorySet16(ds, 0x567a, 0x0000);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_ed3f()
{
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    bx = memoryGet16(ds, 0x5678);
    bp = memoryGet16(ds, 0x567a);
    ax = bp;
    ax += 0x2432;
    ax ^= bx;
    ax ^= memoryGet16(ds, 0x5676);
    bp = ax;
    ax = ror(ax, 0x0001);
    ax -= memoryGet16(ds, 0x5676);
    ax ^= bx;
    ax += 0x1c12;
    ax ^= bp;
    ax = ror(ax, 0x0001);
    flags.carry = (ax + bp) >= 0x10000;
    ax += bp;
    ax = rcr(ax, 0x0001);
    bx = ax;
    ax = memoryGet16(ds, 0x5676);
    ax += bp;
    ax ^= 0x3812;
    ax ^= bx;
    memorySet16(ds, 0x5676, ax);
    memorySet16(ds, 0x5678, bx);
    memorySet16(ds, 0x567a, bp);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_f9c4()
{
loc_f9c4:
    ax = es;
    bx = memoryGet16(es, di);
    tl = bl;
    bl = bh;
    bh = tl;
    bx = ror(bx, 0x0001);
    bx = ror(bx, 0x0001);
    bx = ror(bx, 0x0001);
    bx = ror(bx, 0x0001);
    ax += bx;
    cx = bx;
    bx = memoryGet16(es, di + 2);
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
    memorySet16(es, di + 2, ax);
    memorySet16(es, di, cx);
    sub_fa07();
    di += 0x0004;
    goto loc_f9c4;
}
void sub_fa07()
{
    push(ds);
    push(di);
    push(si);
    push(ax);
    push(cx);
    ax = memoryGet16(ds, 0x541d);
    memorySet16(cs, 0x0ded, ax);
    tx = di;
    di = memoryGet16(es, tx);
    ds = memoryGet16(es, tx + 2);
    cx = memoryGet16(ds, di - 2);
    tl = cl;
    cl = ch;
    ch = tl;
    memorySet16(ds, di - 2, cx);
    if ((short)cx < 0)
        goto loc_fa26;
    if (cx == 0)
        goto loc_fa26;
    goto loc_fa29;
loc_fa26:
    goto loc_fb77;
loc_fa29:
    ax = memoryGet16(ds, di - 4);
    tl = al;
    al = ah;
    ah = tl;
    memorySet16(ds, di - 4, ax);
    ax = memoryGet16(ds, di - 6);
    tl = al;
    al = ah;
    ah = tl;
    memorySet16(ds, di - 6, ax);
    ax = memoryGet16(ds, di - 8);
    tl = al;
    al = ah;
    ah = tl;
    memorySet16(ds, di - 8, ax);
    ax = memoryGet16(ds, di - 12);
    tl = al;
    al = ah;
    ah = tl;
    memorySet16(ds, di - 12, ax);
    ax = memoryGet16(ds, di - 10);
    tl = ah;
    ah = al;
    al = tl;
    memorySet16(ds, di - 10, ax);
    al &= 0xc0;
    if (al != 0)
        goto loc_fa26;
    si = di;
    ax = memoryGet16(cs, 0x0ded);
    if (ax == 0x0000)
        goto loc_fa63;
    goto loc_fb3c;
loc_fa63:
    ax = memoryGet16(ds, di - 4);
    ax >>= 1;
    ax >>= 1;
    dx = ax;
    if ((short)dx < 0)
        goto loc_fa26;
    if (dx == 0)
        goto loc_fa26;
loc_fa72:
    al = memoryGet(ds, si + 2);
    ah = memoryGet(ds, si + 1);
    memorySet(ds, si + 1, al);
    al = memoryGet(ds, si + 4);
    memorySet(ds, si + 4, ah);
    memorySet(ds, si + 2, al);
    al = memoryGet(ds, si + 6);
    ah = memoryGet(ds, si + 3);
    memorySet(ds, si + 3, al);
    al = memoryGet(ds, si + 5);
    memorySet(ds, si + 5, ah);
    memorySet(ds, si + 6, al);
    ax = memoryGet16(ds, si);
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
    memorySet16(ds, si, bx);
    ax = memoryGet16(ds, si + 4);
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
    memorySet16(ds, si + 4, bx);
    ax = 0;
    memorySet16(ds, si + 2, ax);
    memorySet16(ds, si + 6, ax);
    si += 0x0008;
    dx--;
    if (dx != 0)
        goto loc_fb36;
    if (--cx)
        goto loc_fb39;
    goto loc_fb77;
loc_fb36:
    goto loc_fa72;
loc_fb39:
    goto loc_fa63;
loc_fb3c:
    ax = memoryGet16(ds, di - 4);
    ax >>= 1;
    ax >>= 1;
    dx = ax;
    if ((short)dx < 0)
        goto loc_fb77;
    if (dx == 0)
        goto loc_fb77;
loc_fb4b:
    al = memoryGet(ds, si + 2);
    ah = memoryGet(ds, si + 1);
    memorySet(ds, si + 1, al);
    al = memoryGet(ds, si + 4);
    memorySet(ds, si + 4, ah);
    memorySet(ds, si + 2, al);
    al = memoryGet(ds, si + 6);
    ah = memoryGet(ds, si + 3);
    memorySet(ds, si + 3, al);
    al = memoryGet(ds, si + 5);
    memorySet(ds, si + 5, ah);
    memorySet(ds, si + 6, al);
    si += 0x0008;
    dx--;
    if (dx != 0)
        goto loc_fb4b;
    if (--cx)
        goto loc_fb3c;
loc_fb77:
    cx = pop();
    ax = pop();
    si = pop();
    di = pop();
    ds = pop();
}
void sub_fb7f()
{
    push(0x7777);
    ax = memoryGet16(ss, bp + 4);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax &= 0xfffe;
    memorySet16(ds, 0x680d, ax);
    dx = memoryGet16(ss, bp + 8);
    dx++;
    dx >>= 1;
    dx >>= 1;
    dx >>= 1;
    dx &= 0xfffe;
    memorySet16(ds, 0x680f, dx);
    dx -= ax;
    memorySet16(ds, 0x6815, dx);
    ax = memoryGet16(ss, bp + 6);
    memorySet16(ds, 0x6811, ax);
    dx = memoryGet16(ss, bp + 10);
    memorySet16(ds, 0x6813, dx);
    dx -= ax;
    memorySet16(ds, 0x6817, dx);
    assert(pop() == 0x7777);
}
void sub_fbb9()
{
    push(0x7777);
    bx = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    if (!bx)
        goto loc_fbc3;
    sub_fbc4();
loc_fbc3:
    assert(pop() == 0x7777);
}
void sub_fbc4()
{
    memorySet16(ds, 0x6809, bx);
    si = es;
    memorySet16(ds, 0x680b, si);
    ax = bx;
    ax |= si;
    if (!ax)
        return;
    sub_fbd8();
}
void sub_fbd8()
{
    bx = memoryGet16(ds, 0x6809);
    es = memoryGet16(ds, 0x6809 + 2);
loc_fbdc:
    push(es);
    di = memoryGet16(es, bx);
    es = memoryGet16(es, bx + 2);
    ax = es;
    ax |= di;
    if (!ax)
        goto loc_fbe9;
    push(bx);
    goto loc_fbef;
loc_fbe9:
    goto loc_fc8f;
loc_fbec:
    goto loc_fc87;
loc_fbef:
    al = memoryGet(es, di + 10);
    if (!(al & 0x80))
        goto loc_fbec;
    ax = memoryGet16(es, di);
    if (!(memoryGet(es, di + 10) & 0x20))
        goto loc_fc11;
    bx = memoryGet16(es, di + 16);
    bx <<= 1;
    bx <<= 1;
    ax -= bx;
    ax += memoryGet16(es, di + 20);
    goto loc_fc15;
loc_fc11:
    ax -= memoryGet16(es, di + 20);
loc_fc15:
    if (!(memoryGet(es, di + 10) & 0x01))
        goto loc_fc22;
    ax += 0x0004;
    ax &= 0xfff8;
loc_fc22:
    bx = ax;
    bx &= 0x0007;
    memorySet(cs, 0x3216, bl);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    ax = sar(ax, 1);
    memorySet16(ds, 0x6821, ax);
    ax = memoryGet16(es, di + 2);
    ax -= memoryGet16(es, di + 22);
    memorySet16(ds, 0x6823, ax);
    dx = memoryGet16(ds, 0x6813);
    ax = memoryGet16(ds, 0x6823);
    if ((short)dx <= (short)ax)
        goto loc_fbec;
    dx = memoryGet16(ds, 0x680f);
    ax = memoryGet16(ds, 0x6821);
    if ((short)dx <= (short)ax)
        goto loc_fbec;
    dx = ax;
    ax = memoryGet16(es, di + 16);
    ax >>= 1;
    dx += ax;
    if ((short)dx < 0)
        goto loc_fbec;
    ax = memoryGet16(ds, 0x680d);
    if ((short)dx < (short)ax)
        goto loc_fbec;
    ax = memoryGet16(ds, 0x6823);
    dx = ax;
    ax = memoryGet16(es, di + 18);
    dx += ax;
    if ((short)dx < 0)
        goto loc_fc87;
    ax = memoryGet16(ds, 0x6811);
    if ((short)dx < (short)ax)
        goto loc_fc87;
    push(bx);
    push(di);
    sub_fdcd();
    di = pop();
    bx = pop();
    goto loc_fbec;
loc_fc87:
    bx = pop();
    es = pop();
    bx += 0x0004;
    goto loc_fbdc;
loc_fc8f:
    es = pop();
}
void sub_fce0()
{
    memorySet(ds, 0x683c, 0x00);
    memorySet16(ds, 0x6819, 0x0000);
    ax = memoryGet16(ds, 0x680d);
    ax -= memoryGet16(ds, 0x6821);
    if ((short)ax >= 0)
        goto loc_fcfb;
    ax = -ax;
    memorySet16(ds, 0x6819, ax);
    ax = 0;
loc_fcfb:
    memorySet16(ds, 0x681f, ax);
    if (ax == 0)
        goto loc_fd07;
    memorySet(ds, 0x683c, memoryGet(ds, 0x683c) | 0x02);
loc_fd07:
    ax = memoryGet16(ds, 0x680f);
    ax -= memoryGet16(ds, 0x6821);
    if ((short)ax < 0)
        goto loc_fd31;
    bx = memoryGet16(es, di + 16);
    bx >>= 1;
    bx++;
    ax -= bx;
    if ((short)ax < 0)
        goto loc_fd31;
    ax = memoryGet16(es, di + 16);
    ax >>= 1;
    ax -= memoryGet16(ds, 0x681f);
    if ((short)ax >= 0)
        goto loc_fd29;
    ax = 0;
loc_fd29:
    memorySet16(ds, 0x6835, ax);
    goto loc_fd43;
loc_fd2e:
    ax = 0;
    return;
loc_fd31:
    ax = memoryGet16(ds, 0x681f);
    ax = -ax;
    ax += memoryGet16(ds, 0x680f);
    ax -= memoryGet16(ds, 0x6821);
    memorySet(ds, 0x683c, memoryGet(ds, 0x683c) | 0x01);
loc_fd43:
    memorySet16(ds, 0x6835, ax);
    memorySet16(ds, 0x681b, 0x0000);
    ax = memoryGet16(ds, 0x6811);
    ax -= memoryGet16(ds, 0x6823);
    if ((short)ax >= 0)
        goto loc_fd5c;
    ax = -ax;
    memorySet16(ds, 0x681b, ax);
    ax = 0;
loc_fd5c:
    memorySet16(ds, 0x681d, ax);
    ax = memoryGet16(ds, 0x6811);
    ax += memoryGet16(ds, 0x6817);
    ax -= memoryGet16(ds, 0x6823);
    if ((short)ax < 0)
        goto loc_fd7d;
    ax -= memoryGet16(es, di + 18);
    if ((short)ax < 0)
        goto loc_fd7d;
    ax = memoryGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryGet16(es, di + 18);
    goto loc_fd8e;
loc_fd7d:
    ax = memoryGet16(ds, 0x681d);
    ax = -ax;
    ax += memoryGet16(ds, 0x6811);
    ax += memoryGet16(ds, 0x6817);
    ax -= memoryGet16(ds, 0x6823);
loc_fd8e:
    memorySet16(ds, 0x6837, ax);
    ax = memoryGet16(ds, 0x681b);
    ax += memoryGet16(ds, 0x6811);
    if (!(ax & ax))
        goto loc_fda0;
    bl = 0x28;
    mul(bl);
loc_fda0:
    ax += memoryGet16(ds, 0x56e2);
    ax += memoryGet16(ds, 0x6819);
    ax += memoryGet16(ds, 0x680d);
    memorySet16(ds, 0x56e8, ax);
    ax = memoryGet16(ds, 0x6835);
    if (ax == 0)
        goto loc_fdca;
    if ((short)ax < 0)
        goto loc_fdca;
    ax = memoryGet16(ds, 0x6837);
    if (ax == 0)
        goto loc_fdca;
    if ((short)ax < 0)
        goto loc_fdca;
    if ((short)ax >= (short)0x0064)
        goto loc_fdca;
    ax |= 0x0001;
    return;
loc_fdca:
    goto loc_fd2e;
}
void sub_fdcd()
{
    push(0x7777);
    sub_fce0();
    ax = memoryGet16(ds, 0x681d);
    if (!(ax & ax))
        goto loc_fddf;
    bl = memoryGet(es, di + 16);
    bl += bl;
    mul(bl);
loc_fddf:
    ax += memoryGet16(ds, 0x681f);
    ax += memoryGet16(ds, 0x681f);
    ax += memoryGet16(ds, 0x681f);
    ax += memoryGet16(ds, 0x681f);
    memorySet16(ds, 0x56e6, ax);
    ax = memoryGet16(ds, 0x6835);
    dx = memoryGet16(es, di + 16);
    dx >>= 1;
    cl = 0x28;
    cl -= al;
    ch = 0;
    dh = ch;
    memorySet(ds, 0x683a, 0x00);
    goto loc_fe36;
    //   gap of 44 bytes
loc_fe36:
    push(es);
    push(di);
    al = memoryGet(cs, 0x3216);
    memorySet(ds, 0x683b, al);
    bp = memoryGet16(es, di + 12);
    es = memoryGet16(es, di + 12 + 2);
    bp += memoryGet16(ds, 0x56e6);
    memorySet16(ds, 0x6825, bp);
    ax = es;
    memorySet16(ds, 0x6827, ax);
    si = memoryGet16(ds, 0x56e8);
    memorySet16(ds, 0x682d, si);
    ax = memoryGet16(ds, 0x56e4);
    memorySet16(ds, 0x682f, ax);
    memorySet16(ds, 0x6833, 0x0028);
    memorySet16(ds, 0x6831, dx);
    si = 0x6825;
    sub_fe71();
    di = pop();
    es = pop();
    assert(pop() == 0x7777);
}
void sub_fe71()
{
    goto loc_fe71;
loc_f9b4:
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
loc_fe71:
    push(ds);
    al = memoryGet(ds, si + 23);
    memorySet(cs, 0x3215, al);
    al = memoryGet(ds, si + 22);
    memorySet(cs, 0x3216, al);
    ax = memoryGet16(ds, si + 18);
    ax--;
    memorySet16(cs, 0x3213, ax);
    if ((short)ax >= 0)
        goto loc_fe8d;
    goto loc_10ec9;
loc_fe8d:
    bx = memoryGet16(ds, si + 16);
    ax = memoryGet16(ds, si + 14);
    ax -= bx;
    memorySet16(cs, 0x320f, ax);
    cx = memoryGet16(ds, si + 12);
    cx -= bx;
    al = memoryGet(ds, si + 21);
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
    dx = memoryGet16(cs, bp + 4);
    di = memoryGet16(cs, bp);
    ax = memoryGet16(cs, bx + di);
    memorySet16(cs, 0x25e2, ax);
    ax = memoryGet16(cs, bp + 2);
    push(ax);
    push(bx);
    al = memoryGet(cs, 0x320e);
    bx = 0x11da;
    al &= 0x40;
    if (al == 0)
        goto loc_ff0b;
    bx = 0x11e2;
loc_ff0b:
    ax = memoryGet16(cs, bx);
    memorySet16(cs, 0x11d5, ax);
    al = memoryGet(cs, bx + 2);
    memorySet(cs, 0x11d7, al);
    al = memoryGet(cs, bx + 4);
    memorySet(cs, 0x11d8, al);
    al = memoryGet(cs, bx + 6);
    memorySet(cs, 0x11d9, al);
    bx = pop();
    ax = pop();
    bp = memoryGet16(ds, si);
    es = memoryGet16(ds, si + 2);
    tx = si;
    si = memoryGet16(ds, tx + 8);
    ds = memoryGet16(ds, tx + 8 + 2);
    bl = memoryGet(cs, 0x3216);
    bh = 0;
    bx += bx;
    di = memoryGet16(cs, bx + 13093);
    if (dx == 0x0004)
        goto loc_ff5a;
    if (dx == 0x0002)
        goto loc_ff5c;
    if (dx == 0x0001)
        goto loc_ff58;
    if (dx == 0x0003)
        goto loc_ff58;
loc_ff53:
    ah = 0x01;
    goto loc_f9b4;
loc_ff58:
    goto loc_ff53;
loc_ff5a:
    cx += cx;
loc_ff5c:
    cx += cx;
    memorySet16(cs, 0x3211, cx);
    switch (ax)
    {
        case 0x210b: goto loc_10e9b;
        default: assert(0);
    }
//    stop(/*2*/); // 0ed9:11d3 jmp ax - jump Indirect ax
    //   gap of 3441 bytes
loc_10cd6:
    ax = memoryGet16(es, bp);
    dx = memoryGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryGet(cs, 0x3216);
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
    ax = memoryGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryVideoGet(ds, si);
    memoryVideoSet(ds, si, bl);
    al = memoryGet(cs, 0x11d7);
    out(dx, al);
    memoryVideoSet(ds, si, bh);
    al = memoryGet(cs, 0x11d8);
    out(dx, al);
    memoryVideoSet(ds, si, cl);
    al = memoryGet(cs, 0x11d9);
    out(dx, al);
    memoryVideoSet(ds, si, ch);
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
    ax = memoryGet16(es, bp);
    dx = memoryGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryGet(cs, 0x3216);
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
    ax = memoryGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryVideoGet(ds, si);
    memoryVideoSet(ds, si, bl);
    al = memoryGet(cs, 0x11d7);
    out(dx, al);
    memoryVideoSet(ds, si, bh);
    al = memoryGet(cs, 0x11d8);
    out(dx, al);
    memoryVideoSet(ds, si, cl);
    al = memoryGet(cs, 0x11d9);
    out(dx, al);
    memoryVideoSet(ds, si, ch);
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
loc_10d94:
    ax = memoryGet16(es, bp);
    dx = memoryGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryGet(cs, 0x3216);
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
    ax = memoryGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryVideoGet(ds, si);
    memoryVideoSet(ds, si, bl);
    al = memoryGet(cs, 0x11d7);
    out(dx, al);
    memoryVideoSet(ds, si, bh);
    al = memoryGet(cs, 0x11d8);
    out(dx, al);
    memoryVideoSet(ds, si, cl);
    al = memoryGet(cs, 0x11d9);
    out(dx, al);
    memoryVideoSet(ds, si, ch);
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
loc_10df3:
    ax = memoryGet16(es, bp);
    dx = memoryGet16(es, bp + 2);
    bp += 0x0004;
    push(cx);
    cl = memoryGet(cs, 0x3216);
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
    ax = memoryGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryVideoGet(ds, si);
    memoryVideoSet(ds, si, bl);
    al = memoryGet(cs, 0x11d7);
    out(dx, al);
    memoryVideoSet(ds, si, bh);
    al = memoryGet(cs, 0x11d8);
    out(dx, al);
    memoryVideoSet(ds, si, cl);
    al = memoryGet(cs, 0x11d9);
    out(dx, al);
    memoryVideoSet(ds, si, ch);
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
    al = memoryGet(cs, 0x3215);
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
    ax = memoryGet16(cs, 0x11d5);
    out(dx, ax);
    al = ah;
    dx++;
    ah = memoryVideoGet(ds, si);
    memoryVideoSet(ds, si, bl);
    al = memoryGet(cs, 0x11d7);
    out(dx, al);
    memoryVideoSet(ds, si, bh);
    al = memoryGet(cs, 0x11d8);
    out(dx, al);
    memoryVideoSet(ds, si, cl);
    al = memoryGet(cs, 0x11d9);
    out(dx, al);
    memoryVideoSet(ds, si, ch);
loc_10e8a:
    memorySet16(cs, 0x3213, memoryGet16(cs, 0x3213) - 1);
    if ((short)memoryGet16(cs, 0x3213) < 0)
        goto loc_10ec9;
    bp += memoryGet16(cs, 0x3211);
    si += memoryGet16(cs, 0x320f);
loc_10e9b:
    bx = 0;
    cx = 0;
    al = memoryGet(cs, 0x3215);
    al &= 0x02;
    if (al == 0)
        goto loc_10ec6;
    bx = memoryGet16(es, bp - 4);
    ax = memoryGet16(es, bp - 2);
    cl = memoryGet(cs, 0x3216);
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
loc_10ec6:
    goto loc_11371;
loc_10ec9:
    dx = 0x03ce;
    ax = 0xff08;
    out(dx, ax);
    ds = pop();
    return;
    //   gap of 1183 bytes
loc_11371:
    ax = 0x0000;
//    stop(/*2*/); // 0ed9:25e4 jmp ax - jump Indirect ax
    ax = memoryGet16(cs, 0x25e2);
    switch (ax)
    {
        case 0x2004: goto loc_10d94; break; //ed9:2004
        case 0x2063: goto loc_10df3; break;
        case 0x20fa: goto loc_10e8a; break;
        case 0x1f46: goto loc_10cd6; break; //ed9:1f46
        default:
            assert(0);
    }
}
void sub_11a7d()
{
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = 0x2d09;
    di = memoryGet16(ds, 0x541d);
    di += di;
    ax = memoryGet16(cs, bx + di);
    di = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    callIndirect(cs*16+ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11aa5()
{
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
    di = memoryGet16(ds, 0x541d);
    di += di;
    ax = memoryGet16(cs, bx + di);
    callIndirect(cs*16+ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_11afd()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    push(ds);
    si = memoryGet16(ds, 0x56de);
    ds = memoryGet16(ds, 0x56de + 2);
    tx = si;
    si = memoryGet16(ds, tx);
    ds = memoryGet16(ds, tx + 2);
    ax = ds;
    ds = pop();
    memorySet16(ds, 0x56e2, si);
    memorySet16(ds, 0x56e4, ax);
    bx = 0x2d9c;
    di = memoryGet16(ds, 0x541d);
    di += di;
    ax = memoryGet16(cs, bx + di);
    assert(di == 4);
    callIndirect(cs*16+ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_11b38()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    bx = 0x2dc6;
    di = memoryGet16(ds, 0x541d);
    di += di;
    ax = memoryGet16(cs, bx + di);
    callIndirect(cs*16+ax);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_11b62()
{
    push(0x7777);
    push(ds);
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ss, bp + 4);
    ax <<= 1;
    ax <<= 1;
    ax += 0x5415;
    memorySet16(ds, 0x56de, ax);
    ax = 0x1228;
    memorySet16(ds, 0x56e0, ax);
    ds = pop();
    assert(pop() == 0x7777);
    cs = pop();
}
void sub_11b7d()
{
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    si = memoryGet16(ss, bp + 4);
    es = memoryGet16(ss, bp + 4 + 2);
    memorySet16(ds, 0x56ee, 0x56f0);
loc_11b90:
    push(es);
    bx = memoryGet16(es, si);
    es = memoryGet16(es, si + 2);
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
loc_11ba1:
    ax = memoryGet16(es, bx + 4);
    ax <<= 1;
    ax <<= 1;
    di = 0x1228;
    ds = di;
    di = memoryGet16(es, bx + 6);
    ds = memoryGet16(es, bx + 6 + 2);
    di += ax;
    tx = di;
    di = memoryGet16(ds, tx);
    ds = memoryGet16(ds, tx + 2);
    memorySet16(es, bx + 12, di);
    ax = ds;
    memorySet16(es, bx + 14, ax);
    ax |= di;
    if (ax)
        goto loc_11bca;
    memorySet16(es, bx + 10, 0x0000);
loc_11bca:
    ax = memoryGet16(ds, di - 2);
    memorySet16(es, bx + 18, ax);
    ax = memoryGet16(ds, di - 4);
    memorySet16(es, bx + 16, ax);
    ax = memoryGet16(ds, di - 6);
    memorySet16(es, bx + 20, ax);
    ax = memoryGet16(ds, di - 8);
    memorySet16(es, bx + 22, ax);
    ax = memoryGet16(ds, di - 12);
    memorySet16(es, bx + 24, ax);
    if (ax < 0x0003)
        goto loc_11bf5;
    ax = 0x0003;
loc_11bf5:
    memorySet16(es, bx + 24, ax);
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
loc_11c0a:
    si--;
    si--;
    movsw<MemData, MemData, DirForward>();
    si--;
    si--;
    si--;
    si--;
    movsw<MemData, MemData, DirForward>();
    si--;
    si--;
    si--;
    si--;
    movsw<MemData, MemData, DirForward>();
    si--;
    si--;
    if (--cx)
        goto loc_11c0a;
    cx = pop();
    si = pop();
    es = pop();
    di = pop();
    ds = pop();
loc_11c20:
    al = memoryGet(ds, di - 10);
    memorySet(es, bx + 11, al);
    al &= 0xc0;
    if (al != 0)
        goto loc_11c32;
loc_11c2b:
    si += 0x0004;
    es = pop();
    goto loc_11b90;
loc_11c32:
    if (al & 0x40)
        goto loc_11c39;
    goto loc_11df8;
loc_11c39:
    push(si);
    push(di);
    dh = memoryGet(es, bx + 10);
    ax = memoryGet16(es, 0x56ee);
    si = di;
    si -= 0x000c;
    di = ax;
    ax += 0x000c;
    memorySet16(es, bx + 12, ax);
    ax = 0x1228;
    memorySet16(es, bx + 14, ax);
    es = ax;
    cx = 0x0006;
    rep_movsw<MemData, MemData, DirForward>();
    bx = si;
    al = memoryGet(ds, si - 4);
    al >>= 1;
    al >>= 1;
    ah = memoryGet(ds, si - 2);
    mul(ah);
    si += ax;
    cx = ax;
    if (dh & 0x20)
        goto loc_11c79;
    goto loc_11d93;
loc_11c79:
    cx = memoryGet16(ds, bx - 4);
    bp = cx;
    cx <<= 1;
    di -= cx;
    di -= 0x0008;
    cx = memoryGet16(ds, bx - 2);
loc_11c88:
    push(cx);
    cx = bp;
    cx <<= 1;
    cx <<= 1;
    di += cx;
    cx = bp;
    cx >>= 1;
    cx >>= 1;
loc_11c97:
    push(cx);
    cl = memoryGet(ds, bx);
    bx++;
    push(bx);
    ah = 0;
    al = 0;
    if (!(cl & 0x80))
        goto loc_11cb0;
    al = memoryGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryGet(es, bx);
    si++;
loc_11cb0:
    ch = al;
    al = 0;
    if (!(cl & 0x40))
        goto loc_11cc4;
    al = memoryGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryGet(es, bx);
    si++;
loc_11cc4:
    stosb<MemData, DirForward>();
    al = 0;
    if (!(cl & 0x20))
        goto loc_11cd7;
    al = memoryGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryGet(es, bx);
    si++;
loc_11cd7:
    dl = al;
    al = 0;
    if (!(cl & 0x10))
        goto loc_11ceb;
    al = memoryGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryGet(es, bx);
    si++;
loc_11ceb:
    stosb<MemData, DirForward>();
    al = 0;
    if (!(cl & 0x08))
        goto loc_11cfe;
    al = memoryGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryGet(es, bx);
    si++;
loc_11cfe:
    dh = al;
    al = 0;
    if (!(cl & 0x04))
        goto loc_11d12;
    al = memoryGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryGet(es, bx);
    si++;
loc_11d12:
    stosb<MemData, DirForward>();
    al = 0;
    if (!(cl & 0x02))
        goto loc_11d25;
    al = memoryGet(ds, si);
    bx = 0x66f0;
    bx += ax;
    al = memoryGet(es, bx);
    si++;
loc_11d25:
    ah = al;
    al = 0;
    if (!(cl & 0x01))
        goto loc_11d3c;
    al = memoryGet(ds, si);
    bx = 0x66f0;
    flags.carry = (bl + al) >= 0x100;
    bl += al;
    bh += flags.carry;
    al = memoryGet(es, bx);
    si++;
loc_11d3c:
    stosb<MemData, DirForward>();
    cl = ah;
    ax = memoryGet16(cs, 0x0ded);
    if (ax != 0x0000)
        goto loc_11d60;
    ax = memoryGet16(es, di - 2);
    tl = al;
    al = ah;
    ah = tl;
    memorySet16(es, di - 2, ax);
    ax = memoryGet16(es, di - 4);
    tl = al;
    al = ah;
    ah = tl;
    memorySet16(es, di - 4, ax);
    tl = dl;
    dl = ch;
    ch = tl;
    tl = cl;
    cl = dh;
    dh = tl;
loc_11d60:
    al = ch;
    stosb<MemData, DirForward>();
    al = dl;
    stosb<MemData, DirForward>();
    al = dh;
    stosb<MemData, DirForward>();
    al = cl;
    stosb<MemData, DirForward>();
    di -= 0x0010;
    bx = pop();
    cx = pop();
    cx--;
    if (!cx)
        goto loc_11d79;
    goto loc_11c97;
loc_11d79:
    cx = pop();
    cx--;
    if (!cx)
        goto loc_11d82;
    goto loc_11c88;
loc_11d82:
    bp <<= 1;
    di += bp;
    di += 0x0008;
    memorySet16(es, 0x56ee, di);
    di = pop();
    si = pop();
    goto loc_11c2b;
loc_11d93:
    push(cx);
    cl = memoryGet(ds, bx);
    bx++;
    ax = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11da0;
    al = memoryGet(ds, si);
    si++;
loc_11da0:
    stosb<MemData, DirForward>();
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11da8;
    ah = memoryGet(ds, si);
    si++;
loc_11da8:
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11db1;
    al = memoryGet(ds, si);
    si++;
loc_11db1:
    stosb<MemData, DirForward>();
    ch = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dbb;
    ch = memoryGet(ds, si);
    si++;
loc_11dbb:
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dc4;
    al = memoryGet(ds, si);
    si++;
loc_11dc4:
    stosb<MemData, DirForward>();
    dl = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dce;
    dl = memoryGet(ds, si);
    si++;
loc_11dce:
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dd7;
    al = memoryGet(ds, si);
    si++;
loc_11dd7:
    stosb<MemData, DirForward>();
    al = ah;
    stosb<MemData, DirForward>();
    al = ch;
    stosb<MemData, DirForward>();
    al = dl;
    stosb<MemData, DirForward>();
    al = 0;
    flags.carry = !!(cx & 0x8000);
    cx <<= 1;
    if (!flags.carry)
        goto loc_11dea;
    al = memoryGet(ds, si);
    si++;
loc_11dea:
    stosb<MemData, DirForward>();
    cx = pop();
    if (--cx)
        goto loc_11d93;
    memorySet16(es, 0x56ee, di);
    di = pop();
    si = pop();
    goto loc_11c2b;
loc_11df8:
    goto loc_11c2b;
}
void sub_11ec7()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    bx = 0x66f0;
    cx = 0x0000;
    ax = memoryGet16(ds, 0x541d);
    if (ax != 0x0000)
        goto loc_11f15;
loc_11edf:
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
    memorySet(ds, bx, ah);
    bx++;
    cx++;
    if ((short)cx <= (short)0x00ff)
        goto loc_11edf;
    goto loc_11f41;
loc_11f15:
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
    memorySet(ds, bx, al);
    bx++;
    cx++;
    if ((short)cx <= (short)0x00ff)
        goto loc_11f15;
loc_11f41:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_11f47()
{
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    ax = 0x1228;
    ds = ax;
    ax = memoryGet16(ss, bp + 4);
    memorySet16(ds, 0x67f0, ax);
    dx = memoryGet16(ss, bp + 6);
    memorySet16(ds, 0x67f2, dx);
    es = dx;
    di = ax;
    al = memoryGet(es, di + 10);
    memorySet(cs, 0x320e, al);
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
void sub_12190()
{
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
loc_121bf:
    if (memoryGet(ds, di) != 0x01)
        goto loc_121d2;
    ah = 0x02;
    interrupt(0x10);
    push(dx);
    ah = 0x09;
    dx = si;
    interrupt(0x21);
    dx = pop();
    dh++;
loc_121d2:
    si += 0x0011;
    di++;
    if (--cx)
        goto loc_121bf;
loc_121d8:
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
loc_121fe:
    memorySet16(ds, 0x689c, 0x8000);
    goto loc_12223;
loc_12206:
    memorySet16(ds, 0x689c, 0x0000);
    goto loc_12223;
loc_1220e:
    memorySet16(ds, 0x689c, 0x0001);
    goto loc_12223;
loc_12216:
    memorySet16(ds, 0x689c, 0x0004);
    goto loc_12223;
    //   gap of 5 bytes
loc_12223:
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_12230()
{
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bx = memoryGet16(ds, 0x541d);
    bx <<= 1;
    assert(bx == 4);
    callIndirect(cs*16+memoryGet16(ds, bx + 26998));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
void sub_12245()
{
    sync();
    dx = 0x03da;
loc_12248:
    in(al, dx);
    if (!(al & 0x08))
        goto loc_12248;
loc_1224d:
    in(al, dx);
    if (al & 0x08)
        goto loc_1224d;
}
