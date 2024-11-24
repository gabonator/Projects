var bumpyStartupLevel = 4;
var bumpyScene = "";

function* start() {
    headerSize = 0x1200;
    loadAddress = 0x01ed;
    cs = 0x01ed;
    ds = 0x01dd;
    es = 0x01dd;
    ss = 0x1c49;
    sp = 0x0080;
    load("/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/bumpy/dos", "B.EXE", 112704);
    yield* fixReloc(cs);
    yield* sub_1ed0();
}
function* fixReloc(seg) {
    memory16set(0x0000 + seg, 0x0001, memory16get(0x0000 + seg, 0x0001) + seg);
    memory16set(0x000b + seg, 0x000d, memory16get(0x000b + seg, 0x000d) + seg);
    memory16set(0x000f + seg, 0x0007, memory16get(0x000f + seg, 0x0007) + seg);
    memory16set(0x0753 + seg, 0x000c, memory16get(0x0753 + seg, 0x000c) + seg);
    memory16set(0x0757 + seg, 0x000d, memory16get(0x0757 + seg, 0x000d) + seg);
    memory16set(0x0759 + seg, 0x0000, memory16get(0x0759 + seg, 0x0000) + seg);
    memory16set(0x075a + seg, 0x000e, memory16get(0x075a + seg, 0x000e) + seg);
    memory16set(0x075f + seg, 0x0001, memory16get(0x075f + seg, 0x0001) + seg);
    memory16set(0x0772 + seg, 0x0001, memory16get(0x0772 + seg, 0x0001) + seg);
    memory16set(0x0773 + seg, 0x000e, memory16get(0x0773 + seg, 0x000e) + seg);
    memory16set(0x077d + seg, 0x000b, memory16get(0x077d + seg, 0x000b) + seg);
    memory16set(0x0781 + seg, 0x0001, memory16get(0x0781 + seg, 0x0001) + seg);
    memory16set(0x0786 + seg, 0x0005, memory16get(0x0786 + seg, 0x0005) + seg);
    memory16set(0x0798 + seg, 0x000f, memory16get(0x0798 + seg, 0x000f) + seg);
    memory16set(0x079b + seg, 0x000c, memory16get(0x079b + seg, 0x000c) + seg);
    memory16set(0x079d + seg, 0x0006, memory16get(0x079d + seg, 0x0006) + seg);
    memory16set(0x07a2 + seg, 0x000a, memory16get(0x07a2 + seg, 0x000a) + seg);
    memory16set(0x07a7 + seg, 0x0005, memory16get(0x07a7 + seg, 0x0005) + seg);
    memory16set(0x07a7 + seg, 0x000b, memory16get(0x07a7 + seg, 0x000b) + seg);
    memory16set(0x07ab + seg, 0x000f, memory16get(0x07ab + seg, 0x000f) + seg);
    memory16set(0x07b2 + seg, 0x0000, memory16get(0x07b2 + seg, 0x0000) + seg);
    memory16set(0x07b3 + seg, 0x0009, memory16get(0x07b3 + seg, 0x0009) + seg);
    memory16set(0x07b5 + seg, 0x0007, memory16get(0x07b5 + seg, 0x0007) + seg);
    memory16set(0x07b7 + seg, 0x0003, memory16get(0x07b7 + seg, 0x0003) + seg);
    memory16set(0x07b8 + seg, 0x0003, memory16get(0x07b8 + seg, 0x0003) + seg);
    memory16set(0x07b9 + seg, 0x0000, memory16get(0x07b9 + seg, 0x0000) + seg);
    memory16set(0x07ba + seg, 0x0003, memory16get(0x07ba + seg, 0x0003) + seg);
    memory16set(0x07ba + seg, 0x000a, memory16get(0x07ba + seg, 0x000a) + seg);
    memory16set(0x07bb + seg, 0x000a, memory16get(0x07bb + seg, 0x000a) + seg);
    memory16set(0x07bc + seg, 0x0007, memory16get(0x07bc + seg, 0x0007) + seg);
    memory16set(0x07bd + seg, 0x0004, memory16get(0x07bd + seg, 0x0004) + seg);
    memory16set(0x07bd + seg, 0x000a, memory16get(0x07bd + seg, 0x000a) + seg);
    memory16set(0x07be + seg, 0x0007, memory16get(0x07be + seg, 0x0007) + seg);
    memory16set(0x07bf + seg, 0x0007, memory16get(0x07bf + seg, 0x0007) + seg);
    memory16set(0x07c3 + seg, 0x0005, memory16get(0x07c3 + seg, 0x0005) + seg);
    memory16set(0x07c5 + seg, 0x0004, memory16get(0x07c5 + seg, 0x0004) + seg);
    memory16set(0x07c9 + seg, 0x000d, memory16get(0x07c9 + seg, 0x000d) + seg);
    memory16set(0x07ca + seg, 0x000f, memory16get(0x07ca + seg, 0x000f) + seg);
    memory16set(0x07cb + seg, 0x000a, memory16get(0x07cb + seg, 0x000a) + seg);
    memory16set(0x07d5 + seg, 0x0008, memory16get(0x07d5 + seg, 0x0008) + seg);
    memory16set(0x07d6 + seg, 0x0007, memory16get(0x07d6 + seg, 0x0007) + seg);
    memory16set(0x07d8 + seg, 0x000b, memory16get(0x07d8 + seg, 0x000b) + seg);
    memory16set(0x07ff + seg, 0x0003, memory16get(0x07ff + seg, 0x0003) + seg);
    memory16set(0x0801 + seg, 0x000f, memory16get(0x0801 + seg, 0x000f) + seg);
    memory16set(0x0803 + seg, 0x0007, memory16get(0x0803 + seg, 0x0007) + seg);
    memory16set(0x0804 + seg, 0x000c, memory16get(0x0804 + seg, 0x000c) + seg);
    memory16set(0x0805 + seg, 0x0008, memory16get(0x0805 + seg, 0x0008) + seg);
    memory16set(0x0806 + seg, 0x0004, memory16get(0x0806 + seg, 0x0004) + seg);
    memory16set(0x0807 + seg, 0x0003, memory16get(0x0807 + seg, 0x0003) + seg);
    memory16set(0x0809 + seg, 0x000b, memory16get(0x0809 + seg, 0x000b) + seg);
    memory16set(0x080a + seg, 0x0008, memory16get(0x080a + seg, 0x0008) + seg);
    memory16set(0x080b + seg, 0x0009, memory16get(0x080b + seg, 0x0009) + seg);
    memory16set(0x080c + seg, 0x0009, memory16get(0x080c + seg, 0x0009) + seg);
    memory16set(0x0868 + seg, 0x000f, memory16get(0x0868 + seg, 0x000f) + seg);
    memory16set(0x0870 + seg, 0x000a, memory16get(0x0870 + seg, 0x000a) + seg);
    memory16set(0x0871 + seg, 0x0001, memory16get(0x0871 + seg, 0x0001) + seg);
    memory16set(0x0896 + seg, 0x0003, memory16get(0x0896 + seg, 0x0003) + seg);
    memory16set(0x0897 + seg, 0x0009, memory16get(0x0897 + seg, 0x0009) + seg);
    memory16set(0x089a + seg, 0x000a, memory16get(0x089a + seg, 0x000a) + seg);
    memory16set(0x089b + seg, 0x000b, memory16get(0x089b + seg, 0x000b) + seg);
    memory16set(0x089d + seg, 0x0002, memory16get(0x089d + seg, 0x0002) + seg);
    memory16set(0x089f + seg, 0x0007, memory16get(0x089f + seg, 0x0007) + seg);
    memory16set(0x08b8 + seg, 0x0006, memory16get(0x08b8 + seg, 0x0006) + seg);
    memory16set(0x08c0 + seg, 0x0004, memory16get(0x08c0 + seg, 0x0004) + seg);
    memory16set(0x08ed + seg, 0x0001, memory16get(0x08ed + seg, 0x0001) + seg);
    memory16set(0x0900 + seg, 0x000e, memory16get(0x0900 + seg, 0x000e) + seg);
    memory16set(0x0907 + seg, 0x0001, memory16get(0x0907 + seg, 0x0001) + seg);
    memory16set(0x0908 + seg, 0x0006, memory16get(0x0908 + seg, 0x0006) + seg);
    memory16set(0x090c + seg, 0x0000, memory16get(0x090c + seg, 0x0000) + seg);
    memory16set(0x0924 + seg, 0x0007, memory16get(0x0924 + seg, 0x0007) + seg);
    memory16set(0x0925 + seg, 0x0007, memory16get(0x0925 + seg, 0x0007) + seg);
    memory16set(0x0937 + seg, 0x0001, memory16get(0x0937 + seg, 0x0001) + seg);
    memory16set(0x0938 + seg, 0x000b, memory16get(0x0938 + seg, 0x000b) + seg);
    memory16set(0x0939 + seg, 0x000f, memory16get(0x0939 + seg, 0x000f) + seg);
    memory16set(0x093a + seg, 0x000e, memory16get(0x093a + seg, 0x000e) + seg);
    memory16set(0x093b + seg, 0x0004, memory16get(0x093b + seg, 0x0004) + seg);
    memory16set(0x093c + seg, 0x0005, memory16get(0x093c + seg, 0x0005) + seg);
    memory16set(0x093d + seg, 0x0005, memory16get(0x093d + seg, 0x0005) + seg);
    memory16set(0x093d + seg, 0x000e, memory16get(0x093d + seg, 0x000e) + seg);
    memory16set(0x093e + seg, 0x000f, memory16get(0x093e + seg, 0x000f) + seg);
    memory16set(0x093f + seg, 0x0008, memory16get(0x093f + seg, 0x0008) + seg);
    memory16set(0x0940 + seg, 0x0002, memory16get(0x0940 + seg, 0x0002) + seg);
    memory16set(0x0940 + seg, 0x000c, memory16get(0x0940 + seg, 0x000c) + seg);
    memory16set(0x0941 + seg, 0x0006, memory16get(0x0941 + seg, 0x0006) + seg);
    memory16set(0x0942 + seg, 0x0000, memory16get(0x0942 + seg, 0x0000) + seg);
    memory16set(0x0942 + seg, 0x0007, memory16get(0x0942 + seg, 0x0007) + seg);
    memory16set(0x0943 + seg, 0x0000, memory16get(0x0943 + seg, 0x0000) + seg);
    memory16set(0x094e + seg, 0x0005, memory16get(0x094e + seg, 0x0005) + seg);
    memory16set(0x0955 + seg, 0x0000, memory16get(0x0955 + seg, 0x0000) + seg);
    memory16set(0x0959 + seg, 0x0008, memory16get(0x0959 + seg, 0x0008) + seg);
    memory16set(0x097a + seg, 0x0007, memory16get(0x097a + seg, 0x0007) + seg);
    memory16set(0x097b + seg, 0x000c, memory16get(0x097b + seg, 0x000c) + seg);
    memory16set(0x097c + seg, 0x0002, memory16get(0x097c + seg, 0x0002) + seg);
    memory16set(0x097d + seg, 0x0002, memory16get(0x097d + seg, 0x0002) + seg);
    memory16set(0x097e + seg, 0x0002, memory16get(0x097e + seg, 0x0002) + seg);
    memory16set(0x097e + seg, 0x0008, memory16get(0x097e + seg, 0x0008) + seg);
    memory16set(0x097e + seg, 0x000e, memory16get(0x097e + seg, 0x000e) + seg);
    memory16set(0x097f + seg, 0x0004, memory16get(0x097f + seg, 0x0004) + seg);
    memory16set(0x0980 + seg, 0x0001, memory16get(0x0980 + seg, 0x0001) + seg);
    memory16set(0x0981 + seg, 0x0001, memory16get(0x0981 + seg, 0x0001) + seg);
    memory16set(0x0981 + seg, 0x000e, memory16get(0x0981 + seg, 0x000e) + seg);
    memory16set(0x0983 + seg, 0x0004, memory16get(0x0983 + seg, 0x0004) + seg);
    memory16set(0x0984 + seg, 0x0004, memory16get(0x0984 + seg, 0x0004) + seg);
    memory16set(0x0985 + seg, 0x0001, memory16get(0x0985 + seg, 0x0001) + seg);
    memory16set(0x0986 + seg, 0x0001, memory16get(0x0986 + seg, 0x0001) + seg);
    memory16set(0x0986 + seg, 0x0007, memory16get(0x0986 + seg, 0x0007) + seg);
    memory16set(0x0a0b + seg, 0x000b, memory16get(0x0a0b + seg, 0x000b) + seg);
    memory16set(0x0aba + seg, 0x000d, memory16get(0x0aba + seg, 0x000d) + seg);
    memory16set(0x0abd + seg, 0x000a, memory16get(0x0abd + seg, 0x000a) + seg);
    memory16set(0x0ac2 + seg, 0x0000, memory16get(0x0ac2 + seg, 0x0000) + seg);
    memory16set(0x0ac7 + seg, 0x0007, memory16get(0x0ac7 + seg, 0x0007) + seg);
    memory16set(0x0acd + seg, 0x000a, memory16get(0x0acd + seg, 0x000a) + seg);
    memory16set(0x0ad1 + seg, 0x0000, memory16get(0x0ad1 + seg, 0x0000) + seg);
    memory16set(0x0ad6 + seg, 0x0001, memory16get(0x0ad6 + seg, 0x0001) + seg);
    memory16set(0x0ad7 + seg, 0x0007, memory16get(0x0ad7 + seg, 0x0007) + seg);
    memory16set(0x0adb + seg, 0x0001, memory16get(0x0adb + seg, 0x0001) + seg);
    memory16set(0x0add + seg, 0x0004, memory16get(0x0add + seg, 0x0004) + seg);
    memory16set(0x0ae2 + seg, 0x000d, memory16get(0x0ae2 + seg, 0x000d) + seg);
    memory16set(0x0ae4 + seg, 0x0007, memory16get(0x0ae4 + seg, 0x0007) + seg);
    memory16set(0x0ae6 + seg, 0x0004, memory16get(0x0ae6 + seg, 0x0004) + seg);
    memory16set(0x0aea + seg, 0x000b, memory16get(0x0aea + seg, 0x000b) + seg);
    memory16set(0x0aeb + seg, 0x0004, memory16get(0x0aeb + seg, 0x0004) + seg);
    memory16set(0x0aed + seg, 0x0009, memory16get(0x0aed + seg, 0x0009) + seg);
    memory16set(0x0aef + seg, 0x0001, memory16get(0x0aef + seg, 0x0001) + seg);
    memory16set(0x0af1 + seg, 0x000a, memory16get(0x0af1 + seg, 0x000a) + seg);
    memory16set(0x0b0f + seg, 0x000e, memory16get(0x0b0f + seg, 0x000e) + seg);
    memory16set(0x0b10 + seg, 0x0008, memory16get(0x0b10 + seg, 0x0008) + seg);
    memory16set(0x0b13 + seg, 0x000a, memory16get(0x0b13 + seg, 0x000a) + seg);
    memory16set(0x0b1c + seg, 0x0006, memory16get(0x0b1c + seg, 0x0006) + seg);
    memory16set(0x0b3a + seg, 0x0004, memory16get(0x0b3a + seg, 0x0004) + seg);
    memory16set(0x0b3d + seg, 0x0002, memory16get(0x0b3d + seg, 0x0002) + seg);
    memory16set(0x0b3d + seg, 0x000d, memory16get(0x0b3d + seg, 0x000d) + seg);
    memory16set(0x0b3e + seg, 0x000e, memory16get(0x0b3e + seg, 0x000e) + seg);
    memory16set(0x0b42 + seg, 0x0004, memory16get(0x0b42 + seg, 0x0004) + seg);
    memory16set(0x0b4d + seg, 0x000e, memory16get(0x0b4d + seg, 0x000e) + seg);
    memory16set(0x0b54 + seg, 0x0008, memory16get(0x0b54 + seg, 0x0008) + seg);
    memory16set(0x0b55 + seg, 0x0003, memory16get(0x0b55 + seg, 0x0003) + seg);
    memory16set(0x0b56 + seg, 0x0004, memory16get(0x0b56 + seg, 0x0004) + seg);
    memory16set(0x0b5b + seg, 0x0001, memory16get(0x0b5b + seg, 0x0001) + seg);
    memory16set(0x0b60 + seg, 0x000a, memory16get(0x0b60 + seg, 0x000a) + seg);
    memory16set(0x0b65 + seg, 0x0002, memory16get(0x0b65 + seg, 0x0002) + seg);
    memory16set(0x0b68 + seg, 0x0004, memory16get(0x0b68 + seg, 0x0004) + seg);
    memory16set(0x0b69 + seg, 0x0004, memory16get(0x0b69 + seg, 0x0004) + seg);
    memory16set(0x0b6d + seg, 0x000c, memory16get(0x0b6d + seg, 0x000c) + seg);
    memory16set(0x0b7d + seg, 0x0003, memory16get(0x0b7d + seg, 0x0003) + seg);
    memory16set(0x0b83 + seg, 0x000d, memory16get(0x0b83 + seg, 0x000d) + seg);
    memory16set(0x0b84 + seg, 0x000f, memory16get(0x0b84 + seg, 0x000f) + seg);
    memory16set(0x0b8b + seg, 0x0000, memory16get(0x0b8b + seg, 0x0000) + seg);
    memory16set(0x0b90 + seg, 0x000d, memory16get(0x0b90 + seg, 0x000d) + seg);
    memory16set(0x0b96 + seg, 0x0002, memory16get(0x0b96 + seg, 0x0002) + seg);
    memory16set(0x0b98 + seg, 0x000e, memory16get(0x0b98 + seg, 0x000e) + seg);
    memory16set(0x0b99 + seg, 0x000d, memory16get(0x0b99 + seg, 0x000d) + seg);
    memory16set(0x0b9c + seg, 0x000e, memory16get(0x0b9c + seg, 0x000e) + seg);
    memory16set(0x0ba8 + seg, 0x0008, memory16get(0x0ba8 + seg, 0x0008) + seg);
    memory16set(0x0bae + seg, 0x000c, memory16get(0x0bae + seg, 0x000c) + seg);
    memory16set(0x0baf + seg, 0x000d, memory16get(0x0baf + seg, 0x000d) + seg);
    memory16set(0x0bb5 + seg, 0x0007, memory16get(0x0bb5 + seg, 0x0007) + seg);
    memory16set(0x0bb6 + seg, 0x0008, memory16get(0x0bb6 + seg, 0x0008) + seg);
    memory16set(0x0bbb + seg, 0x000e, memory16get(0x0bbb + seg, 0x000e) + seg);
    memory16set(0x0bc0 + seg, 0x0009, memory16get(0x0bc0 + seg, 0x0009) + seg);
    memory16set(0x0bc2 + seg, 0x0001, memory16get(0x0bc2 + seg, 0x0001) + seg);
    memory16set(0x0bc4 + seg, 0x000d, memory16get(0x0bc4 + seg, 0x000d) + seg);
    memory16set(0x0bd2 + seg, 0x000b, memory16get(0x0bd2 + seg, 0x000b) + seg);
    memory16set(0x0bd7 + seg, 0x0009, memory16get(0x0bd7 + seg, 0x0009) + seg);
    memory16set(0x0bdc + seg, 0x0007, memory16get(0x0bdc + seg, 0x0007) + seg);
    memory16set(0x0be0 + seg, 0x0004, memory16get(0x0be0 + seg, 0x0004) + seg);
    memory16set(0x0be4 + seg, 0x0006, memory16get(0x0be4 + seg, 0x0006) + seg);
    memory16set(0x0be6 + seg, 0x000c, memory16get(0x0be6 + seg, 0x000c) + seg);
    memory16set(0x0bea + seg, 0x0007, memory16get(0x0bea + seg, 0x0007) + seg);
    memory16set(0x0bec + seg, 0x0001, memory16get(0x0bec + seg, 0x0001) + seg);
    memory16set(0x0bee + seg, 0x000b, memory16get(0x0bee + seg, 0x000b) + seg);
    memory16set(0x0bef + seg, 0x000e, memory16get(0x0bef + seg, 0x000e) + seg);
    memory16set(0x0bf1 + seg, 0x0001, memory16get(0x0bf1 + seg, 0x0001) + seg);
    memory16set(0x0bf5 + seg, 0x0003, memory16get(0x0bf5 + seg, 0x0003) + seg);
    memory16set(0x0bfa + seg, 0x0004, memory16get(0x0bfa + seg, 0x0004) + seg);
    memory16set(0x0bfb + seg, 0x0008, memory16get(0x0bfb + seg, 0x0008) + seg);
    memory16set(0x0bfd + seg, 0x0007, memory16get(0x0bfd + seg, 0x0007) + seg);
    memory16set(0x0bfe + seg, 0x000e, memory16get(0x0bfe + seg, 0x000e) + seg);
    memory16set(0x0c06 + seg, 0x0000, memory16get(0x0c06 + seg, 0x0000) + seg);
    memory16set(0x0c13 + seg, 0x000f, memory16get(0x0c13 + seg, 0x000f) + seg);
    memory16set(0x0c21 + seg, 0x000c, memory16get(0x0c21 + seg, 0x000c) + seg);
    memory16set(0x0c28 + seg, 0x0006, memory16get(0x0c28 + seg, 0x0006) + seg);
    memory16set(0x0c2b + seg, 0x0003, memory16get(0x0c2b + seg, 0x0003) + seg);
    memory16set(0x0c2c + seg, 0x0009, memory16get(0x0c2c + seg, 0x0009) + seg);
    memory16set(0x0c2e + seg, 0x0001, memory16get(0x0c2e + seg, 0x0001) + seg);
    memory16set(0x0c34 + seg, 0x0007, memory16get(0x0c34 + seg, 0x0007) + seg);
    memory16set(0x0c36 + seg, 0x0000, memory16get(0x0c36 + seg, 0x0000) + seg);
    memory16set(0x0c37 + seg, 0x000c, memory16get(0x0c37 + seg, 0x000c) + seg);
    memory16set(0x0c39 + seg, 0x0001, memory16get(0x0c39 + seg, 0x0001) + seg);
    memory16set(0x0c40 + seg, 0x0002, memory16get(0x0c40 + seg, 0x0002) + seg);
    memory16set(0x0c41 + seg, 0x0005, memory16get(0x0c41 + seg, 0x0005) + seg);
    memory16set(0x0c42 + seg, 0x000a, memory16get(0x0c42 + seg, 0x000a) + seg);
    memory16set(0x0c45 + seg, 0x0004, memory16get(0x0c45 + seg, 0x0004) + seg);
    memory16set(0x0c46 + seg, 0x0007, memory16get(0x0c46 + seg, 0x0007) + seg);
    memory16set(0x0c47 + seg, 0x0001, memory16get(0x0c47 + seg, 0x0001) + seg);
    memory16set(0x0c48 + seg, 0x0000, memory16get(0x0c48 + seg, 0x0000) + seg);
    memory16set(0x0c4c + seg, 0x0004, memory16get(0x0c4c + seg, 0x0004) + seg);
    memory16set(0x0c4e + seg, 0x0001, memory16get(0x0c4e + seg, 0x0001) + seg);
    memory16set(0x0c51 + seg, 0x0009, memory16get(0x0c51 + seg, 0x0009) + seg);
    memory16set(0x0c53 + seg, 0x0000, memory16get(0x0c53 + seg, 0x0000) + seg);
    memory16set(0x0c54 + seg, 0x000b, memory16get(0x0c54 + seg, 0x000b) + seg);
    memory16set(0x0c56 + seg, 0x0005, memory16get(0x0c56 + seg, 0x0005) + seg);
    memory16set(0x0c58 + seg, 0x0007, memory16get(0x0c58 + seg, 0x0007) + seg);
    memory16set(0x0c59 + seg, 0x0008, memory16get(0x0c59 + seg, 0x0008) + seg);
    memory16set(0x0c5c + seg, 0x0006, memory16get(0x0c5c + seg, 0x0006) + seg);
    memory16set(0x0c5e + seg, 0x0008, memory16get(0x0c5e + seg, 0x0008) + seg);
    memory16set(0x0c5f + seg, 0x0009, memory16get(0x0c5f + seg, 0x0009) + seg);
    memory16set(0x0c62 + seg, 0x0007, memory16get(0x0c62 + seg, 0x0007) + seg);
    memory16set(0x0c64 + seg, 0x0009, memory16get(0x0c64 + seg, 0x0009) + seg);
    memory16set(0x0c65 + seg, 0x000a, memory16get(0x0c65 + seg, 0x000a) + seg);
    memory16set(0x0c67 + seg, 0x0003, memory16get(0x0c67 + seg, 0x0003) + seg);
    memory16set(0x0c69 + seg, 0x0008, memory16get(0x0c69 + seg, 0x0008) + seg);
    memory16set(0x0c6b + seg, 0x0001, memory16get(0x0c6b + seg, 0x0001) + seg);
    memory16set(0x0c6c + seg, 0x000d, memory16get(0x0c6c + seg, 0x000d) + seg);
    memory16set(0x0c6e + seg, 0x000a, memory16get(0x0c6e + seg, 0x000a) + seg);
    memory16set(0x0c6f + seg, 0x000c, memory16get(0x0c6f + seg, 0x000c) + seg);
    memory16set(0x0c73 + seg, 0x0001, memory16get(0x0c73 + seg, 0x0001) + seg);
    memory16set(0x0c74 + seg, 0x0008, memory16get(0x0c74 + seg, 0x0008) + seg);
    memory16set(0x0c76 + seg, 0x0009, memory16get(0x0c76 + seg, 0x0009) + seg);
    memory16set(0x0c7d + seg, 0x000c, memory16get(0x0c7d + seg, 0x000c) + seg);
    memory16set(0x0c83 + seg, 0x0003, memory16get(0x0c83 + seg, 0x0003) + seg);
    memory16set(0x0c84 + seg, 0x0004, memory16get(0x0c84 + seg, 0x0004) + seg);
    memory16set(0x0c84 + seg, 0x000b, memory16get(0x0c84 + seg, 0x000b) + seg);
    memory16set(0x0c86 + seg, 0x0002, memory16get(0x0c86 + seg, 0x0002) + seg);
    memory16set(0x0c87 + seg, 0x000a, memory16get(0x0c87 + seg, 0x000a) + seg);
    memory16set(0x0c91 + seg, 0x0006, memory16get(0x0c91 + seg, 0x0006) + seg);
    memory16set(0x0c92 + seg, 0x0009, memory16get(0x0c92 + seg, 0x0009) + seg);
    memory16set(0x0c93 + seg, 0x0007, memory16get(0x0c93 + seg, 0x0007) + seg);
    memory16set(0x0c95 + seg, 0x0008, memory16get(0x0c95 + seg, 0x0008) + seg);
    memory16set(0x0c9c + seg, 0x000e, memory16get(0x0c9c + seg, 0x000e) + seg);
    memory16set(0x0ca2 + seg, 0x000f, memory16get(0x0ca2 + seg, 0x000f) + seg);
    memory16set(0x0ca4 + seg, 0x0000, memory16get(0x0ca4 + seg, 0x0000) + seg);
    memory16set(0x0ca4 + seg, 0x0007, memory16get(0x0ca4 + seg, 0x0007) + seg);
    memory16set(0x0ca7 + seg, 0x000b, memory16get(0x0ca7 + seg, 0x000b) + seg);
    memory16set(0x0cb2 + seg, 0x0007, memory16get(0x0cb2 + seg, 0x0007) + seg);
    memory16set(0x0cb6 + seg, 0x000c, memory16get(0x0cb6 + seg, 0x000c) + seg);
    memory16set(0x0cb9 + seg, 0x000a, memory16get(0x0cb9 + seg, 0x000a) + seg);
    memory16set(0x0cbd + seg, 0x0008, memory16get(0x0cbd + seg, 0x0008) + seg);
    memory16set(0x0cbf + seg, 0x000d, memory16get(0x0cbf + seg, 0x000d) + seg);
    memory16set(0x0cc2 + seg, 0x000a, memory16get(0x0cc2 + seg, 0x000a) + seg);
    memory16set(0x0cc6 + seg, 0x0009, memory16get(0x0cc6 + seg, 0x0009) + seg);
    memory16set(0x0cc7 + seg, 0x0008, memory16get(0x0cc7 + seg, 0x0008) + seg);
    memory16set(0x0cc8 + seg, 0x0001, memory16get(0x0cc8 + seg, 0x0001) + seg);
    memory16set(0x0cda + seg, 0x0006, memory16get(0x0cda + seg, 0x0006) + seg);
    memory16set(0x0cde + seg, 0x000b, memory16get(0x0cde + seg, 0x000b) + seg);
    memory16set(0x0ce5 + seg, 0x0006, memory16get(0x0ce5 + seg, 0x0006) + seg);
    memory16set(0x0ce7 + seg, 0x0005, memory16get(0x0ce7 + seg, 0x0005) + seg);
    memory16set(0x0f99 + seg, 0x0008, memory16get(0x0f99 + seg, 0x0008) + seg);
    memory16set(0x0fbd + seg, 0x000b, memory16get(0x0fbd + seg, 0x000b) + seg);
    memory16set(0x0fc0 + seg, 0x0009, memory16get(0x0fc0 + seg, 0x0009) + seg);
    memory16set(0x0fc3 + seg, 0x0003, memory16get(0x0fc3 + seg, 0x0003) + seg);
    memory16set(0x0fc6 + seg, 0x000e, memory16get(0x0fc6 + seg, 0x000e) + seg);
    memory16set(0x0fc9 + seg, 0x0004, memory16get(0x0fc9 + seg, 0x0004) + seg);
    memory16set(0x0fca + seg, 0x0006, memory16get(0x0fca + seg, 0x0006) + seg);
    memory16set(0x0fcb + seg, 0x0003, memory16get(0x0fcb + seg, 0x0003) + seg);
    memory16set(0x0fcd + seg, 0x000a, memory16get(0x0fcd + seg, 0x000a) + seg);
    memory16set(0x0fd8 + seg, 0x0002, memory16get(0x0fd8 + seg, 0x0002) + seg);
    memory16set(0x0ff4 + seg, 0x0000, memory16get(0x0ff4 + seg, 0x0000) + seg);
    memory16set(0x0fff + seg, 0x000d, memory16get(0x0fff + seg, 0x000d) + seg);
    memory16set(0x1007 + seg, 0x000d, memory16get(0x1007 + seg, 0x000d) + seg);
    memory16set(0x1009 + seg, 0x000d, memory16get(0x1009 + seg, 0x000d) + seg);
    memory16set(0x100b + seg, 0x0004, memory16get(0x100b + seg, 0x0004) + seg);
    memory16set(0x102c + seg, 0x0006, memory16get(0x102c + seg, 0x0006) + seg);
    memory16set(0x1030 + seg, 0x000d, memory16get(0x1030 + seg, 0x000d) + seg);
    memory16set(0x1031 + seg, 0x0006, memory16get(0x1031 + seg, 0x0006) + seg);
    memory16set(0x1031 + seg, 0x000f, memory16get(0x1031 + seg, 0x000f) + seg);
    memory16set(0x1032 + seg, 0x0008, memory16get(0x1032 + seg, 0x0008) + seg);
    memory16set(0x1035 + seg, 0x0001, memory16get(0x1035 + seg, 0x0001) + seg);
    memory16set(0x1044 + seg, 0x0002, memory16get(0x1044 + seg, 0x0002) + seg);
    memory16set(0x1044 + seg, 0x000c, memory16get(0x1044 + seg, 0x000c) + seg);
    memory16set(0x1045 + seg, 0x0006, memory16get(0x1045 + seg, 0x0006) + seg);
    memory16set(0x1046 + seg, 0x0000, memory16get(0x1046 + seg, 0x0000) + seg);
    memory16set(0x1046 + seg, 0x000a, memory16get(0x1046 + seg, 0x000a) + seg);
    memory16set(0x1047 + seg, 0x0004, memory16get(0x1047 + seg, 0x0004) + seg);
    memory16set(0x1047 + seg, 0x000e, memory16get(0x1047 + seg, 0x000e) + seg);
    memory16set(0x1048 + seg, 0x0008, memory16get(0x1048 + seg, 0x0008) + seg);
    memory16set(0x1049 + seg, 0x0002, memory16get(0x1049 + seg, 0x0002) + seg);
    memory16set(0x1049 + seg, 0x000c, memory16get(0x1049 + seg, 0x000c) + seg);
    memory16set(0x1092 + seg, 0x0006, memory16get(0x1092 + seg, 0x0006) + seg);
    memory16set(0x10a9 + seg, 0x000c, memory16get(0x10a9 + seg, 0x000c) + seg);
    memory16set(0x10aa + seg, 0x0000, memory16get(0x10aa + seg, 0x0000) + seg);
    memory16set(0x10aa + seg, 0x0004, memory16get(0x10aa + seg, 0x0004) + seg);
    memory16set(0x10aa + seg, 0x0008, memory16get(0x10aa + seg, 0x0008) + seg);
    memory16set(0x10aa + seg, 0x000c, memory16get(0x10aa + seg, 0x000c) + seg);
    memory16set(0x10ab + seg, 0x0000, memory16get(0x10ab + seg, 0x0000) + seg);
    memory16set(0x10ab + seg, 0x0004, memory16get(0x10ab + seg, 0x0004) + seg);
    memory16set(0x10ab + seg, 0x0008, memory16get(0x10ab + seg, 0x0008) + seg);
    memory16set(0x10ab + seg, 0x000c, memory16get(0x10ab + seg, 0x000c) + seg);
    memory16set(0x10b1 + seg, 0x0000, memory16get(0x10b1 + seg, 0x0000) + seg);
    memory16set(0x10b1 + seg, 0x0004, memory16get(0x10b1 + seg, 0x0004) + seg);
    memory16set(0x10b1 + seg, 0x0008, memory16get(0x10b1 + seg, 0x0008) + seg);
    memory16set(0x10c6 + seg, 0x000a, memory16get(0x10c6 + seg, 0x000a) + seg);
    memory16set(0x10c6 + seg, 0x000e, memory16get(0x10c6 + seg, 0x000e) + seg);
    memory16set(0x10c7 + seg, 0x0002, memory16get(0x10c7 + seg, 0x0002) + seg);
    memory16set(0x10c7 + seg, 0x0006, memory16get(0x10c7 + seg, 0x0006) + seg);
    memory16set(0x10c7 + seg, 0x000a, memory16get(0x10c7 + seg, 0x000a) + seg);
    memory16set(0x10c7 + seg, 0x000e, memory16get(0x10c7 + seg, 0x000e) + seg);
    memory16set(0x10c8 + seg, 0x0002, memory16get(0x10c8 + seg, 0x0002) + seg);
    memory16set(0x10c8 + seg, 0x0006, memory16get(0x10c8 + seg, 0x0006) + seg);
    memory16set(0x10c8 + seg, 0x000a, memory16get(0x10c8 + seg, 0x000a) + seg);
    memory16set(0x10c8 + seg, 0x000e, memory16get(0x10c8 + seg, 0x000e) + seg);
    memory16set(0x10c9 + seg, 0x0002, memory16get(0x10c9 + seg, 0x0002) + seg);
    memory16set(0x10c9 + seg, 0x0006, memory16get(0x10c9 + seg, 0x0006) + seg);
    memory16set(0x10c9 + seg, 0x000a, memory16get(0x10c9 + seg, 0x000a) + seg);
    memory16set(0x10c9 + seg, 0x000e, memory16get(0x10c9 + seg, 0x000e) + seg);
    memory16set(0x10ca + seg, 0x0002, memory16get(0x10ca + seg, 0x0002) + seg);
    memory16set(0x10ca + seg, 0x000a, memory16get(0x10ca + seg, 0x000a) + seg);
    memory16set(0x10cb + seg, 0x0002, memory16get(0x10cb + seg, 0x0002) + seg);
    memory16set(0x10cb + seg, 0x000a, memory16get(0x10cb + seg, 0x000a) + seg);
    memory16set(0x10cc + seg, 0x0002, memory16get(0x10cc + seg, 0x0002) + seg);
    memory16set(0x10cc + seg, 0x000a, memory16get(0x10cc + seg, 0x000a) + seg);
    memory16set(0x10cd + seg, 0x0002, memory16get(0x10cd + seg, 0x0002) + seg);
    memory16set(0x10cd + seg, 0x000a, memory16get(0x10cd + seg, 0x000a) + seg);
    memory16set(0x10ce + seg, 0x0004, memory16get(0x10ce + seg, 0x0004) + seg);
    memory16set(0x10ce + seg, 0x000e, memory16get(0x10ce + seg, 0x000e) + seg);
    memory16set(0x10cf + seg, 0x0008, memory16get(0x10cf + seg, 0x0008) + seg);
    memory16set(0x10d0 + seg, 0x0002, memory16get(0x10d0 + seg, 0x0002) + seg);
    memory16set(0x10d0 + seg, 0x000c, memory16get(0x10d0 + seg, 0x000c) + seg);
    memory16set(0x10d1 + seg, 0x0006, memory16get(0x10d1 + seg, 0x0006) + seg);
    memory16set(0x10d2 + seg, 0x0000, memory16get(0x10d2 + seg, 0x0000) + seg);
    memory16set(0x10d2 + seg, 0x000a, memory16get(0x10d2 + seg, 0x000a) + seg);
    memory16set(0x10d3 + seg, 0x0004, memory16get(0x10d3 + seg, 0x0004) + seg);
    memory16set(0x10d3 + seg, 0x000e, memory16get(0x10d3 + seg, 0x000e) + seg);
    memory16set(0x10d4 + seg, 0x0008, memory16get(0x10d4 + seg, 0x0008) + seg);
    memory16set(0x10d5 + seg, 0x0002, memory16get(0x10d5 + seg, 0x0002) + seg);
    memory16set(0x10d5 + seg, 0x000c, memory16get(0x10d5 + seg, 0x000c) + seg);
    memory16set(0x10d6 + seg, 0x0006, memory16get(0x10d6 + seg, 0x0006) + seg);
    memory16set(0x10d7 + seg, 0x0000, memory16get(0x10d7 + seg, 0x0000) + seg);
    memory16set(0x10d7 + seg, 0x000a, memory16get(0x10d7 + seg, 0x000a) + seg);
    memory16set(0x10d8 + seg, 0x0004, memory16get(0x10d8 + seg, 0x0004) + seg);
    memory16set(0x10d8 + seg, 0x000e, memory16get(0x10d8 + seg, 0x000e) + seg);
    memory16set(0x1147 + seg, 0x000e, memory16get(0x1147 + seg, 0x000e) + seg);
    memory16set(0x1148 + seg, 0x0002, memory16get(0x1148 + seg, 0x0002) + seg);
    memory16set(0x1148 + seg, 0x0006, memory16get(0x1148 + seg, 0x0006) + seg);
    memory16set(0x1148 + seg, 0x000a, memory16get(0x1148 + seg, 0x000a) + seg);
    memory16set(0x1148 + seg, 0x000e, memory16get(0x1148 + seg, 0x000e) + seg);
    memory16set(0x1149 + seg, 0x0002, memory16get(0x1149 + seg, 0x0002) + seg);
    memory16set(0x1149 + seg, 0x0006, memory16get(0x1149 + seg, 0x0006) + seg);
    memory16set(0x1149 + seg, 0x000a, memory16get(0x1149 + seg, 0x000a) + seg);
    memory16set(0x1149 + seg, 0x000e, memory16get(0x1149 + seg, 0x000e) + seg);
    memory16set(0x114a + seg, 0x0002, memory16get(0x114a + seg, 0x0002) + seg);
    memory16set(0x114a + seg, 0x0006, memory16get(0x114a + seg, 0x0006) + seg);
    memory16set(0x114a + seg, 0x000a, memory16get(0x114a + seg, 0x000a) + seg);
    memory16set(0x114a + seg, 0x000e, memory16get(0x114a + seg, 0x000e) + seg);
    memory16set(0x114b + seg, 0x0002, memory16get(0x114b + seg, 0x0002) + seg);
    memory16set(0x114b + seg, 0x0006, memory16get(0x114b + seg, 0x0006) + seg);
    memory16set(0x114b + seg, 0x000a, memory16get(0x114b + seg, 0x000a) + seg);
    memory16set(0x114b + seg, 0x000e, memory16get(0x114b + seg, 0x000e) + seg);
    memory16set(0x114c + seg, 0x0002, memory16get(0x114c + seg, 0x0002) + seg);
    memory16set(0x1155 + seg, 0x0000, memory16get(0x1155 + seg, 0x0000) + seg);
    memory16set(0x1155 + seg, 0x0004, memory16get(0x1155 + seg, 0x0004) + seg);
    memory16set(0x1155 + seg, 0x0008, memory16get(0x1155 + seg, 0x0008) + seg);
    memory16set(0x1155 + seg, 0x000c, memory16get(0x1155 + seg, 0x000c) + seg);
    memory16set(0x1156 + seg, 0x0000, memory16get(0x1156 + seg, 0x0000) + seg);
    memory16set(0x1170 + seg, 0x000e, memory16get(0x1170 + seg, 0x000e) + seg);
    memory16set(0x1171 + seg, 0x0002, memory16get(0x1171 + seg, 0x0002) + seg);
    memory16set(0x1171 + seg, 0x0006, memory16get(0x1171 + seg, 0x0006) + seg);
    memory16set(0x1171 + seg, 0x000a, memory16get(0x1171 + seg, 0x000a) + seg);
    memory16set(0x1171 + seg, 0x000e, memory16get(0x1171 + seg, 0x000e) + seg);
    memory16set(0x1172 + seg, 0x0002, memory16get(0x1172 + seg, 0x0002) + seg);
    memory16set(0x1172 + seg, 0x0006, memory16get(0x1172 + seg, 0x0006) + seg);
    memory16set(0x1172 + seg, 0x000a, memory16get(0x1172 + seg, 0x000a) + seg);
    memory16set(0x1178 + seg, 0x0004, memory16get(0x1178 + seg, 0x0004) + seg);
    memory16set(0x117d + seg, 0x0008, memory16get(0x117d + seg, 0x0008) + seg);
    memory16set(0x1182 + seg, 0x000c, memory16get(0x1182 + seg, 0x000c) + seg);
    memory16set(0x1186 + seg, 0x0002, memory16get(0x1186 + seg, 0x0002) + seg);
    memory16set(0x1189 + seg, 0x0008, memory16get(0x1189 + seg, 0x0008) + seg);
    memory16set(0x1191 + seg, 0x000c, memory16get(0x1191 + seg, 0x000c) + seg);
    memory16set(0x1196 + seg, 0x0004, memory16get(0x1196 + seg, 0x0004) + seg);
    memory16set(0x119a + seg, 0x000c, memory16get(0x119a + seg, 0x000c) + seg);
    memory16set(0x119b + seg, 0x0002, memory16get(0x119b + seg, 0x0002) + seg);
    memory16set(0x11a1 + seg, 0x0002, memory16get(0x11a1 + seg, 0x0002) + seg);
    memory16set(0x11a7 + seg, 0x000a, memory16get(0x11a7 + seg, 0x000a) + seg);
    memory16set(0x11a8 + seg, 0x000c, memory16get(0x11a8 + seg, 0x000c) + seg);
    memory16set(0x11b0 + seg, 0x000a, memory16get(0x11b0 + seg, 0x000a) + seg);
    memory16set(0x11b4 + seg, 0x0006, memory16get(0x11b4 + seg, 0x0006) + seg);
    memory16set(0x11bb + seg, 0x0002, memory16get(0x11bb + seg, 0x0002) + seg);
    memory16set(0x11c0 + seg, 0x0000, memory16get(0x11c0 + seg, 0x0000) + seg);
    memory16set(0x11c4 + seg, 0x0008, memory16get(0x11c4 + seg, 0x0008) + seg);
    memory16set(0x11c9 + seg, 0x0000, memory16get(0x11c9 + seg, 0x0000) + seg);
    memory16set(0x11cd + seg, 0x000e, memory16get(0x11cd + seg, 0x000e) + seg);
    memory16set(0x11d2 + seg, 0x000c, memory16get(0x11d2 + seg, 0x000c) + seg);
    memory16set(0x11d9 + seg, 0x0002, memory16get(0x11d9 + seg, 0x0002) + seg);
    memory16set(0x11df + seg, 0x0008, memory16get(0x11df + seg, 0x0008) + seg);
    memory16set(0x11e5 + seg, 0x000e, memory16get(0x11e5 + seg, 0x000e) + seg);
    memory16set(0x11ec + seg, 0x0004, memory16get(0x11ec + seg, 0x0004) + seg);
    memory16set(0x11f1 + seg, 0x0008, memory16get(0x11f1 + seg, 0x0008) + seg);
    memory16set(0x11f1 + seg, 0x000e, memory16get(0x11f1 + seg, 0x000e) + seg);
    memory16set(0x11f8 + seg, 0x0000, memory16get(0x11f8 + seg, 0x0000) + seg);
    memory16set(0x11fb + seg, 0x0006, memory16get(0x11fb + seg, 0x0006) + seg);
    memory16set(0x11ff + seg, 0x0008, memory16get(0x11ff + seg, 0x0008) + seg);
    memory16set(0x11ff + seg, 0x000e, memory16get(0x11ff + seg, 0x000e) + seg);
    memory16set(0x1204 + seg, 0x000c, memory16get(0x1204 + seg, 0x000c) + seg);
    memory16set(0x1205 + seg, 0x0002, memory16get(0x1205 + seg, 0x0002) + seg);
    memory16set(0x120a + seg, 0x0002, memory16get(0x120a + seg, 0x0002) + seg);
    memory16set(0x120a + seg, 0x0008, memory16get(0x120a + seg, 0x0008) + seg);
    memory16set(0x120e + seg, 0x000a, memory16get(0x120e + seg, 0x000a) + seg);
    memory16set(0x120f + seg, 0x0000, memory16get(0x120f + seg, 0x0000) + seg);
    memory16set(0x1214 + seg, 0x0004, memory16get(0x1214 + seg, 0x0004) + seg);
    memory16set(0x1214 + seg, 0x000a, memory16get(0x1214 + seg, 0x000a) + seg);
    memory16set(0x1218 + seg, 0x000c, memory16get(0x1218 + seg, 0x000c) + seg);
    memory16set(0x1220 + seg, 0x0004, memory16get(0x1220 + seg, 0x0004) + seg);
    memory16set(0x122a + seg, 0x0006, memory16get(0x122a + seg, 0x0006) + seg);
    memory16set(0x122d + seg, 0x0000, memory16get(0x122d + seg, 0x0000) + seg);
    memory16set(0x1231 + seg, 0x0002, memory16get(0x1231 + seg, 0x0002) + seg);
    memory16set(0x1231 + seg, 0x0008, memory16get(0x1231 + seg, 0x0008) + seg);
    memory16set(0x1237 + seg, 0x0008, memory16get(0x1237 + seg, 0x0008) + seg);
    memory16set(0x1237 + seg, 0x000e, memory16get(0x1237 + seg, 0x000e) + seg);
    memory16set(0x123e + seg, 0x000a, memory16get(0x123e + seg, 0x000a) + seg);
    memory16set(0x123f + seg, 0x0000, memory16get(0x123f + seg, 0x0000) + seg);
    memory16set(0x1243 + seg, 0x0008, memory16get(0x1243 + seg, 0x0008) + seg);
    memory16set(0x1243 + seg, 0x000e, memory16get(0x1243 + seg, 0x000e) + seg);
    memory16set(0x1249 + seg, 0x0002, memory16get(0x1249 + seg, 0x0002) + seg);
    memory16set(0x1249 + seg, 0x0008, memory16get(0x1249 + seg, 0x0008) + seg);
    memory16set(0x124f + seg, 0x0002, memory16get(0x124f + seg, 0x0002) + seg);
    memory16set(0x1254 + seg, 0x000c, memory16get(0x1254 + seg, 0x000c) + seg);
    memory16set(0x125a + seg, 0x0006, memory16get(0x125a + seg, 0x0006) + seg);
    memory16set(0x1260 + seg, 0x0000, memory16get(0x1260 + seg, 0x0000) + seg);
    memory16set(0x1260 + seg, 0x0004, memory16get(0x1260 + seg, 0x0004) + seg);
    memory16set(0x1260 + seg, 0x0008, memory16get(0x1260 + seg, 0x0008) + seg);
    memory16set(0x1260 + seg, 0x000c, memory16get(0x1260 + seg, 0x000c) + seg);
    memory16set(0x1261 + seg, 0x0000, memory16get(0x1261 + seg, 0x0000) + seg);
    memory16set(0x1261 + seg, 0x0004, memory16get(0x1261 + seg, 0x0004) + seg);
    memory16set(0x1261 + seg, 0x000c, memory16get(0x1261 + seg, 0x000c) + seg);
    memory16set(0x1262 + seg, 0x0000, memory16get(0x1262 + seg, 0x0000) + seg);
    memory16set(0x1262 + seg, 0x0004, memory16get(0x1262 + seg, 0x0004) + seg);
    memory16set(0x1262 + seg, 0x0008, memory16get(0x1262 + seg, 0x0008) + seg);
    memory16set(0x1262 + seg, 0x000c, memory16get(0x1262 + seg, 0x000c) + seg);
    memory16set(0x1263 + seg, 0x0004, memory16get(0x1263 + seg, 0x0004) + seg);
    memory16set(0x1263 + seg, 0x0008, memory16get(0x1263 + seg, 0x0008) + seg);
    memory16set(0x1263 + seg, 0x000c, memory16get(0x1263 + seg, 0x000c) + seg);
    memory16set(0x1264 + seg, 0x0000, memory16get(0x1264 + seg, 0x0000) + seg);
    memory16set(0x1264 + seg, 0x0004, memory16get(0x1264 + seg, 0x0004) + seg);
    memory16set(0x1264 + seg, 0x0008, memory16get(0x1264 + seg, 0x0008) + seg);
    memory16set(0x1264 + seg, 0x000c, memory16get(0x1264 + seg, 0x000c) + seg);
    memory16set(0x1265 + seg, 0x0000, memory16get(0x1265 + seg, 0x0000) + seg);
    memory16set(0x1265 + seg, 0x0004, memory16get(0x1265 + seg, 0x0004) + seg);
    memory16set(0x1265 + seg, 0x0008, memory16get(0x1265 + seg, 0x0008) + seg);
    memory16set(0x1265 + seg, 0x000c, memory16get(0x1265 + seg, 0x000c) + seg);
    memory16set(0x1266 + seg, 0x0000, memory16get(0x1266 + seg, 0x0000) + seg);
    memory16set(0x1266 + seg, 0x0004, memory16get(0x1266 + seg, 0x0004) + seg);
    memory16set(0x1266 + seg, 0x0008, memory16get(0x1266 + seg, 0x0008) + seg);
    memory16set(0x1266 + seg, 0x000c, memory16get(0x1266 + seg, 0x000c) + seg);
    memory16set(0x1267 + seg, 0x0000, memory16get(0x1267 + seg, 0x0000) + seg);
    memory16set(0x1267 + seg, 0x0008, memory16get(0x1267 + seg, 0x0008) + seg);
    memory16set(0x1267 + seg, 0x000c, memory16get(0x1267 + seg, 0x000c) + seg);
    memory16set(0x1268 + seg, 0x0000, memory16get(0x1268 + seg, 0x0000) + seg);
    memory16set(0x1268 + seg, 0x0004, memory16get(0x1268 + seg, 0x0004) + seg);
    memory16set(0x1268 + seg, 0x0008, memory16get(0x1268 + seg, 0x0008) + seg);
    memory16set(0x1268 + seg, 0x000c, memory16get(0x1268 + seg, 0x000c) + seg);
    memory16set(0x1269 + seg, 0x0008, memory16get(0x1269 + seg, 0x0008) + seg);
    memory16set(0x1269 + seg, 0x000c, memory16get(0x1269 + seg, 0x000c) + seg);
    memory16set(0x126a + seg, 0x0000, memory16get(0x126a + seg, 0x0000) + seg);
    memory16set(0x126a + seg, 0x0004, memory16get(0x126a + seg, 0x0004) + seg);
    memory16set(0x126a + seg, 0x0008, memory16get(0x126a + seg, 0x0008) + seg);
    memory16set(0x126a + seg, 0x000c, memory16get(0x126a + seg, 0x000c) + seg);
    memory16set(0x126b + seg, 0x0000, memory16get(0x126b + seg, 0x0000) + seg);
    memory16set(0x126b + seg, 0x0004, memory16get(0x126b + seg, 0x0004) + seg);
    memory16set(0x126b + seg, 0x0008, memory16get(0x126b + seg, 0x0008) + seg);
    memory16set(0x126b + seg, 0x000c, memory16get(0x126b + seg, 0x000c) + seg);
    memory16set(0x126c + seg, 0x0000, memory16get(0x126c + seg, 0x0000) + seg);
    memory16set(0x126c + seg, 0x0004, memory16get(0x126c + seg, 0x0004) + seg);
    memory16set(0x126c + seg, 0x0008, memory16get(0x126c + seg, 0x0008) + seg);
    memory16set(0x126c + seg, 0x000c, memory16get(0x126c + seg, 0x000c) + seg);
    memory16set(0x126d + seg, 0x0000, memory16get(0x126d + seg, 0x0000) + seg);
    memory16set(0x126d + seg, 0x0004, memory16get(0x126d + seg, 0x0004) + seg);
    memory16set(0x126d + seg, 0x0008, memory16get(0x126d + seg, 0x0008) + seg);
    memory16set(0x126d + seg, 0x000c, memory16get(0x126d + seg, 0x000c) + seg);
    memory16set(0x126e + seg, 0x0000, memory16get(0x126e + seg, 0x0000) + seg);
    memory16set(0x126e + seg, 0x0004, memory16get(0x126e + seg, 0x0004) + seg);
    memory16set(0x126e + seg, 0x0008, memory16get(0x126e + seg, 0x0008) + seg);
    memory16set(0x126e + seg, 0x000c, memory16get(0x126e + seg, 0x000c) + seg);
    memory16set(0x126f + seg, 0x0000, memory16get(0x126f + seg, 0x0000) + seg);
    memory16set(0x126f + seg, 0x0004, memory16get(0x126f + seg, 0x0004) + seg);
    memory16set(0x126f + seg, 0x0008, memory16get(0x126f + seg, 0x0008) + seg);
    memory16set(0x126f + seg, 0x000c, memory16get(0x126f + seg, 0x000c) + seg);
    memory16set(0x1270 + seg, 0x0000, memory16get(0x1270 + seg, 0x0000) + seg);
    memory16set(0x1273 + seg, 0x0006, memory16get(0x1273 + seg, 0x0006) + seg);
    memory16set(0x1276 + seg, 0x000c, memory16get(0x1276 + seg, 0x000c) + seg);
    memory16set(0x127a + seg, 0x000e, memory16get(0x127a + seg, 0x000e) + seg);
    memory16set(0x127b + seg, 0x0004, memory16get(0x127b + seg, 0x0004) + seg);
    memory16set(0x127f + seg, 0x0000, memory16get(0x127f + seg, 0x0000) + seg);
    memory16set(0x1282 + seg, 0x000c, memory16get(0x1282 + seg, 0x000c) + seg);
    memory16set(0x1286 + seg, 0x000e, memory16get(0x1286 + seg, 0x000e) + seg);
    memory16set(0x1287 + seg, 0x0004, memory16get(0x1287 + seg, 0x0004) + seg);
    memory16set(0x128c + seg, 0x000e, memory16get(0x128c + seg, 0x000e) + seg);
    memory16set(0x128d + seg, 0x0006, memory16get(0x128d + seg, 0x0006) + seg);
    memory16set(0x128d + seg, 0x000a, memory16get(0x128d + seg, 0x000a) + seg);
    memory16set(0x128d + seg, 0x000e, memory16get(0x128d + seg, 0x000e) + seg);
    memory16set(0x128e + seg, 0x0002, memory16get(0x128e + seg, 0x0002) + seg);
    memory16set(0x128e + seg, 0x0006, memory16get(0x128e + seg, 0x0006) + seg);
    memory16set(0x128e + seg, 0x000a, memory16get(0x128e + seg, 0x000a) + seg);
    memory16set(0x128e + seg, 0x000e, memory16get(0x128e + seg, 0x000e) + seg);
    memory16set(0x128f + seg, 0x0002, memory16get(0x128f + seg, 0x0002) + seg);
    memory16set(0x128f + seg, 0x0006, memory16get(0x128f + seg, 0x0006) + seg);
    memory16set(0x1291 + seg, 0x000c, memory16get(0x1291 + seg, 0x000c) + seg);
    memory16set(0x12bc + seg, 0x000e, memory16get(0x12bc + seg, 0x000e) + seg);
    memory16set(0x12bd + seg, 0x000c, memory16get(0x12bd + seg, 0x000c) + seg);
    memory16set(0x12bf + seg, 0x0000, memory16get(0x12bf + seg, 0x0000) + seg);
    memory16set(0x12bf + seg, 0x000c, memory16get(0x12bf + seg, 0x000c) + seg);
    memory16set(0x12c0 + seg, 0x000a, memory16get(0x12c0 + seg, 0x000a) + seg);
    memory16set(0x12c1 + seg, 0x0008, memory16get(0x12c1 + seg, 0x0008) + seg);
    memory16set(0x12c2 + seg, 0x000c, memory16get(0x12c2 + seg, 0x000c) + seg);
    memory16set(0x12c4 + seg, 0x0002, memory16get(0x12c4 + seg, 0x0002) + seg);
    memory16set(0x12c5 + seg, 0x0008, memory16get(0x12c5 + seg, 0x0008) + seg);
    memory16set(0x12c7 + seg, 0x0000, memory16get(0x12c7 + seg, 0x0000) + seg);
    memory16set(0x12c8 + seg, 0x0006, memory16get(0x12c8 + seg, 0x0006) + seg);
    memory16set(0x12c9 + seg, 0x000c, memory16get(0x12c9 + seg, 0x000c) + seg);
    memory16set(0x12cb + seg, 0x0004, memory16get(0x12cb + seg, 0x0004) + seg);
    memory16set(0x12cc + seg, 0x000e, memory16get(0x12cc + seg, 0x000e) + seg);
    memory16set(0x12ce + seg, 0x0008, memory16get(0x12ce + seg, 0x0008) + seg);
    memory16set(0x12d0 + seg, 0x0006, memory16get(0x12d0 + seg, 0x0006) + seg);
    memory16set(0x12d1 + seg, 0x0006, memory16get(0x12d1 + seg, 0x0006) + seg);
    memory16set(0x12d2 + seg, 0x0006, memory16get(0x12d2 + seg, 0x0006) + seg);
    memory16set(0x12d3 + seg, 0x000c, memory16get(0x12d3 + seg, 0x000c) + seg);
    memory16set(0x12d4 + seg, 0x0008, memory16get(0x12d4 + seg, 0x0008) + seg);
    memory16set(0x12d5 + seg, 0x0004, memory16get(0x12d5 + seg, 0x0004) + seg);
    memory16set(0x12d6 + seg, 0x0002, memory16get(0x12d6 + seg, 0x0002) + seg);
    memory16set(0x12d7 + seg, 0x0000, memory16get(0x12d7 + seg, 0x0000) + seg);
    memory16set(0x12d8 + seg, 0x0004, memory16get(0x12d8 + seg, 0x0004) + seg);
    memory16set(0x12d9 + seg, 0x0008, memory16get(0x12d9 + seg, 0x0008) + seg);
    memory16set(0x12da + seg, 0x000a, memory16get(0x12da + seg, 0x000a) + seg);
    memory16set(0x12db + seg, 0x000c, memory16get(0x12db + seg, 0x000c) + seg);
    memory16set(0x12dc + seg, 0x0006, memory16get(0x12dc + seg, 0x0006) + seg);
    memory16set(0x12dd + seg, 0x0000, memory16get(0x12dd + seg, 0x0000) + seg);
    memory16set(0x12de + seg, 0x0004, memory16get(0x12de + seg, 0x0004) + seg);
    memory16set(0x12df + seg, 0x0006, memory16get(0x12df + seg, 0x0006) + seg);
    memory16set(0x12e0 + seg, 0x0006, memory16get(0x12e0 + seg, 0x0006) + seg);
    memory16set(0x12e1 + seg, 0x000a, memory16get(0x12e1 + seg, 0x000a) + seg);
    memory16set(0x12e2 + seg, 0x000e, memory16get(0x12e2 + seg, 0x000e) + seg);
    memory16set(0x12e4 + seg, 0x0006, memory16get(0x12e4 + seg, 0x0006) + seg);
    memory16set(0x12e5 + seg, 0x0006, memory16get(0x12e5 + seg, 0x0006) + seg);
    memory16set(0x12e6 + seg, 0x0004, memory16get(0x12e6 + seg, 0x0004) + seg);
    memory16set(0x12e8 + seg, 0x0000, memory16get(0x12e8 + seg, 0x0000) + seg);
    memory16set(0x12e9 + seg, 0x0002, memory16get(0x12e9 + seg, 0x0002) + seg);
    memory16set(0x12ea + seg, 0x0004, memory16get(0x12ea + seg, 0x0004) + seg);
    memory16set(0x12eb + seg, 0x0006, memory16get(0x12eb + seg, 0x0006) + seg);
    memory16set(0x12ec + seg, 0x0006, memory16get(0x12ec + seg, 0x0006) + seg);
    memory16set(0x12ed + seg, 0x0006, memory16get(0x12ed + seg, 0x0006) + seg);
    memory16set(0x12ee + seg, 0x000e, memory16get(0x12ee + seg, 0x000e) + seg);
    memory16set(0x12f0 + seg, 0x0002, memory16get(0x12f0 + seg, 0x0002) + seg);
    memory16set(0x12f1 + seg, 0x0000, memory16get(0x12f1 + seg, 0x0000) + seg);
    memory16set(0x12f1 + seg, 0x000e, memory16get(0x12f1 + seg, 0x000e) + seg);
    memory16set(0x12f3 + seg, 0x0002, memory16get(0x12f3 + seg, 0x0002) + seg);
    memory16set(0x12f3 + seg, 0x000e, memory16get(0x12f3 + seg, 0x000e) + seg);
    memory16set(0x12f5 + seg, 0x0002, memory16get(0x12f5 + seg, 0x0002) + seg);
    memory16set(0x12f6 + seg, 0x0000, memory16get(0x12f6 + seg, 0x0000) + seg);
    memory16set(0x12f6 + seg, 0x000e, memory16get(0x12f6 + seg, 0x000e) + seg);
    memory16set(0x12f8 + seg, 0x0002, memory16get(0x12f8 + seg, 0x0002) + seg);
    memory16set(0x12f8 + seg, 0x000e, memory16get(0x12f8 + seg, 0x000e) + seg);
    memory16set(0x12f9 + seg, 0x000e, memory16get(0x12f9 + seg, 0x000e) + seg);
    memory16set(0x12fa + seg, 0x000e, memory16get(0x12fa + seg, 0x000e) + seg);
    memory16set(0x12fc + seg, 0x0006, memory16get(0x12fc + seg, 0x0006) + seg);
    memory16set(0x12fd + seg, 0x0008, memory16get(0x12fd + seg, 0x0008) + seg);
    memory16set(0x12fe + seg, 0x000e, memory16get(0x12fe + seg, 0x000e) + seg);
    memory16set(0x1300 + seg, 0x0008, memory16get(0x1300 + seg, 0x0008) + seg);
    memory16set(0x1302 + seg, 0x0002, memory16get(0x1302 + seg, 0x0002) + seg);
    memory16set(0x1302 + seg, 0x000c, memory16get(0x1302 + seg, 0x000c) + seg);
    memory16set(0x1303 + seg, 0x0006, memory16get(0x1303 + seg, 0x0006) + seg);
    memory16set(0x1304 + seg, 0x0008, memory16get(0x1304 + seg, 0x0008) + seg);
    memory16set(0x1305 + seg, 0x000a, memory16get(0x1305 + seg, 0x000a) + seg);
    memory16set(0x1306 + seg, 0x000c, memory16get(0x1306 + seg, 0x000c) + seg);
    memory16set(0x1307 + seg, 0x000e, memory16get(0x1307 + seg, 0x000e) + seg);
    memory16set(0x1309 + seg, 0x0000, memory16get(0x1309 + seg, 0x0000) + seg);
    memory16set(0x130a + seg, 0x0002, memory16get(0x130a + seg, 0x0002) + seg);
    memory16set(0x130b + seg, 0x0004, memory16get(0x130b + seg, 0x0004) + seg);
    memory16set(0x130c + seg, 0x0006, memory16get(0x130c + seg, 0x0006) + seg);
    memory16set(0x130d + seg, 0x0008, memory16get(0x130d + seg, 0x0008) + seg);
    memory16set(0x130e + seg, 0x000a, memory16get(0x130e + seg, 0x000a) + seg);
    memory16set(0x1310 + seg, 0x0000, memory16get(0x1310 + seg, 0x0000) + seg);
    memory16set(0x1311 + seg, 0x000a, memory16get(0x1311 + seg, 0x000a) + seg);
    memory16set(0x1313 + seg, 0x0002, memory16get(0x1313 + seg, 0x0002) + seg);
    memory16set(0x1314 + seg, 0x0004, memory16get(0x1314 + seg, 0x0004) + seg);
    memory16set(0x1315 + seg, 0x0008, memory16get(0x1315 + seg, 0x0008) + seg);
    memory16set(0x1316 + seg, 0x000c, memory16get(0x1316 + seg, 0x000c) + seg);
    memory16set(0x1317 + seg, 0x000e, memory16get(0x1317 + seg, 0x000e) + seg);
    memory16set(0x1319 + seg, 0x0000, memory16get(0x1319 + seg, 0x0000) + seg);
    memory16set(0x131a + seg, 0x0002, memory16get(0x131a + seg, 0x0002) + seg);
    memory16set(0x131b + seg, 0x0008, memory16get(0x131b + seg, 0x0008) + seg);
    memory16set(0x131c + seg, 0x000a, memory16get(0x131c + seg, 0x000a) + seg);
    memory16set(0x131d + seg, 0x000c, memory16get(0x131d + seg, 0x000c) + seg);
    memory16set(0x131e + seg, 0x000e, memory16get(0x131e + seg, 0x000e) + seg);
    memory16set(0x1320 + seg, 0x0004, memory16get(0x1320 + seg, 0x0004) + seg);
    memory16set(0x1321 + seg, 0x000a, memory16get(0x1321 + seg, 0x000a) + seg);
    memory16set(0x1323 + seg, 0x0008, memory16get(0x1323 + seg, 0x0008) + seg);
    memory16set(0x1324 + seg, 0x0004, memory16get(0x1324 + seg, 0x0004) + seg);
    memory16set(0x1324 + seg, 0x000e, memory16get(0x1324 + seg, 0x000e) + seg);
    memory16set(0x1325 + seg, 0x000c, memory16get(0x1325 + seg, 0x000c) + seg);
    memory16set(0x1326 + seg, 0x000a, memory16get(0x1326 + seg, 0x000a) + seg);
    memory16set(0x1327 + seg, 0x000e, memory16get(0x1327 + seg, 0x000e) + seg);
    memory16set(0x1328 + seg, 0x000c, memory16get(0x1328 + seg, 0x000c) + seg);
    memory16set(0x1329 + seg, 0x0004, memory16get(0x1329 + seg, 0x0004) + seg);
    memory16set(0x1329 + seg, 0x0008, memory16get(0x1329 + seg, 0x0008) + seg);
    memory16set(0x1329 + seg, 0x000c, memory16get(0x1329 + seg, 0x000c) + seg);
    memory16set(0x132a + seg, 0x0000, memory16get(0x132a + seg, 0x0000) + seg);
    memory16set(0x132a + seg, 0x0004, memory16get(0x132a + seg, 0x0004) + seg);
    memory16set(0x132a + seg, 0x0008, memory16get(0x132a + seg, 0x0008) + seg);
    memory16set(0x132a + seg, 0x000c, memory16get(0x132a + seg, 0x000c) + seg);
    memory16set(0x132b + seg, 0x0000, memory16get(0x132b + seg, 0x0000) + seg);
    memory16set(0x132b + seg, 0x0004, memory16get(0x132b + seg, 0x0004) + seg);
    memory16set(0x132b + seg, 0x0008, memory16get(0x132b + seg, 0x0008) + seg);
    memory16set(0x132b + seg, 0x000c, memory16get(0x132b + seg, 0x000c) + seg);
    memory16set(0x132c + seg, 0x0000, memory16get(0x132c + seg, 0x0000) + seg);
    memory16set(0x132c + seg, 0x0004, memory16get(0x132c + seg, 0x0004) + seg);
    memory16set(0x132c + seg, 0x0008, memory16get(0x132c + seg, 0x0008) + seg);
    memory16set(0x132c + seg, 0x000c, memory16get(0x132c + seg, 0x000c) + seg);
    memory16set(0x132d + seg, 0x0000, memory16get(0x132d + seg, 0x0000) + seg);
    memory16set(0x132d + seg, 0x0004, memory16get(0x132d + seg, 0x0004) + seg);
    memory16set(0x132d + seg, 0x0008, memory16get(0x132d + seg, 0x0008) + seg);
    memory16set(0x132d + seg, 0x000c, memory16get(0x132d + seg, 0x000c) + seg);
    memory16set(0x132e + seg, 0x0000, memory16get(0x132e + seg, 0x0000) + seg);
    memory16set(0x132e + seg, 0x0004, memory16get(0x132e + seg, 0x0004) + seg);
    memory16set(0x132e + seg, 0x0008, memory16get(0x132e + seg, 0x0008) + seg);
    memory16set(0x132e + seg, 0x000c, memory16get(0x132e + seg, 0x000c) + seg);
    memory16set(0x132f + seg, 0x0000, memory16get(0x132f + seg, 0x0000) + seg);
    memory16set(0x132f + seg, 0x0004, memory16get(0x132f + seg, 0x0004) + seg);
    memory16set(0x132f + seg, 0x0008, memory16get(0x132f + seg, 0x0008) + seg);
    memory16set(0x132f + seg, 0x000c, memory16get(0x132f + seg, 0x000c) + seg);
    memory16set(0x1330 + seg, 0x0000, memory16get(0x1330 + seg, 0x0000) + seg);
    memory16set(0x1330 + seg, 0x0004, memory16get(0x1330 + seg, 0x0004) + seg);
    memory16set(0x1330 + seg, 0x0008, memory16get(0x1330 + seg, 0x0008) + seg);
    memory16set(0x1330 + seg, 0x000c, memory16get(0x1330 + seg, 0x000c) + seg);
    memory16set(0x1331 + seg, 0x0000, memory16get(0x1331 + seg, 0x0000) + seg);
    memory16set(0x1331 + seg, 0x0004, memory16get(0x1331 + seg, 0x0004) + seg);
    memory16set(0x1331 + seg, 0x0008, memory16get(0x1331 + seg, 0x0008) + seg);
    memory16set(0x1331 + seg, 0x000c, memory16get(0x1331 + seg, 0x000c) + seg);
    memory16set(0x1332 + seg, 0x0000, memory16get(0x1332 + seg, 0x0000) + seg);
    memory16set(0x1332 + seg, 0x0004, memory16get(0x1332 + seg, 0x0004) + seg);
    memory16set(0x1332 + seg, 0x0008, memory16get(0x1332 + seg, 0x0008) + seg);
    memory16set(0x1332 + seg, 0x000c, memory16get(0x1332 + seg, 0x000c) + seg);
    memory16set(0x1333 + seg, 0x0000, memory16get(0x1333 + seg, 0x0000) + seg);
    memory16set(0x1333 + seg, 0x0004, memory16get(0x1333 + seg, 0x0004) + seg);
    memory16set(0x1333 + seg, 0x0008, memory16get(0x1333 + seg, 0x0008) + seg);
    memory16set(0x1333 + seg, 0x000c, memory16get(0x1333 + seg, 0x000c) + seg);
    memory16set(0x1334 + seg, 0x0000, memory16get(0x1334 + seg, 0x0000) + seg);
    memory16set(0x1334 + seg, 0x0004, memory16get(0x1334 + seg, 0x0004) + seg);
    memory16set(0x1334 + seg, 0x0008, memory16get(0x1334 + seg, 0x0008) + seg);
    memory16set(0x1334 + seg, 0x000c, memory16get(0x1334 + seg, 0x000c) + seg);
    memory16set(0x1335 + seg, 0x0000, memory16get(0x1335 + seg, 0x0000) + seg);
    memory16set(0x1335 + seg, 0x0004, memory16get(0x1335 + seg, 0x0004) + seg);
    memory16set(0x1335 + seg, 0x0008, memory16get(0x1335 + seg, 0x0008) + seg);
    memory16set(0x1335 + seg, 0x000c, memory16get(0x1335 + seg, 0x000c) + seg);
    memory16set(0x1336 + seg, 0x0000, memory16get(0x1336 + seg, 0x0000) + seg);
    memory16set(0x1336 + seg, 0x0004, memory16get(0x1336 + seg, 0x0004) + seg);
    memory16set(0x1336 + seg, 0x0008, memory16get(0x1336 + seg, 0x0008) + seg);
    memory16set(0x1336 + seg, 0x000c, memory16get(0x1336 + seg, 0x000c) + seg);
    memory16set(0x1337 + seg, 0x0000, memory16get(0x1337 + seg, 0x0000) + seg);
    memory16set(0x1337 + seg, 0x0004, memory16get(0x1337 + seg, 0x0004) + seg);
    memory16set(0x1337 + seg, 0x0008, memory16get(0x1337 + seg, 0x0008) + seg);
    memory16set(0x1337 + seg, 0x000c, memory16get(0x1337 + seg, 0x000c) + seg);
    memory16set(0x1338 + seg, 0x0000, memory16get(0x1338 + seg, 0x0000) + seg);
    memory16set(0x1338 + seg, 0x0004, memory16get(0x1338 + seg, 0x0004) + seg);
    memory16set(0x1338 + seg, 0x0008, memory16get(0x1338 + seg, 0x0008) + seg);
    memory16set(0x1338 + seg, 0x000c, memory16get(0x1338 + seg, 0x000c) + seg);
    memory16set(0x1339 + seg, 0x0000, memory16get(0x1339 + seg, 0x0000) + seg);
    memory16set(0x1339 + seg, 0x0004, memory16get(0x1339 + seg, 0x0004) + seg);
    memory16set(0x1339 + seg, 0x0008, memory16get(0x1339 + seg, 0x0008) + seg);
    memory16set(0x1339 + seg, 0x000c, memory16get(0x1339 + seg, 0x000c) + seg);
    memory16set(0x133a + seg, 0x0000, memory16get(0x133a + seg, 0x0000) + seg);
    memory16set(0x133a + seg, 0x0004, memory16get(0x133a + seg, 0x0004) + seg);
    memory16set(0x133a + seg, 0x0008, memory16get(0x133a + seg, 0x0008) + seg);
    memory16set(0x133a + seg, 0x000c, memory16get(0x133a + seg, 0x000c) + seg);
    memory16set(0x133b + seg, 0x0000, memory16get(0x133b + seg, 0x0000) + seg);
    memory16set(0x133b + seg, 0x0004, memory16get(0x133b + seg, 0x0004) + seg);
    memory16set(0x133b + seg, 0x0008, memory16get(0x133b + seg, 0x0008) + seg);
    memory16set(0x133b + seg, 0x000c, memory16get(0x133b + seg, 0x000c) + seg);
    memory16set(0x133c + seg, 0x0000, memory16get(0x133c + seg, 0x0000) + seg);
    memory16set(0x133c + seg, 0x0004, memory16get(0x133c + seg, 0x0004) + seg);
    memory16set(0x133c + seg, 0x0008, memory16get(0x133c + seg, 0x0008) + seg);
    memory16set(0x133c + seg, 0x000c, memory16get(0x133c + seg, 0x000c) + seg);
    memory16set(0x133d + seg, 0x0000, memory16get(0x133d + seg, 0x0000) + seg);
    memory16set(0x133d + seg, 0x0004, memory16get(0x133d + seg, 0x0004) + seg);
    memory16set(0x133d + seg, 0x0008, memory16get(0x133d + seg, 0x0008) + seg);
    memory16set(0x133d + seg, 0x000c, memory16get(0x133d + seg, 0x000c) + seg);
    memory16set(0x133e + seg, 0x0000, memory16get(0x133e + seg, 0x0000) + seg);
    memory16set(0x133e + seg, 0x0004, memory16get(0x133e + seg, 0x0004) + seg);
    memory16set(0x133e + seg, 0x0008, memory16get(0x133e + seg, 0x0008) + seg);
    memory16set(0x133e + seg, 0x000c, memory16get(0x133e + seg, 0x000c) + seg);
    memory16set(0x133f + seg, 0x0000, memory16get(0x133f + seg, 0x0000) + seg);
    memory16set(0x133f + seg, 0x0004, memory16get(0x133f + seg, 0x0004) + seg);
    memory16set(0x133f + seg, 0x0008, memory16get(0x133f + seg, 0x0008) + seg);
    memory16set(0x133f + seg, 0x000c, memory16get(0x133f + seg, 0x000c) + seg);
    memory16set(0x1340 + seg, 0x0000, memory16get(0x1340 + seg, 0x0000) + seg);
    memory16set(0x1340 + seg, 0x0004, memory16get(0x1340 + seg, 0x0004) + seg);
    memory16set(0x1340 + seg, 0x0008, memory16get(0x1340 + seg, 0x0008) + seg);
    memory16set(0x1340 + seg, 0x000c, memory16get(0x1340 + seg, 0x000c) + seg);
    memory16set(0x1341 + seg, 0x000e, memory16get(0x1341 + seg, 0x000e) + seg);
    memory16set(0x1343 + seg, 0x0006, memory16get(0x1343 + seg, 0x0006) + seg);
    memory16set(0x1344 + seg, 0x000e, memory16get(0x1344 + seg, 0x000e) + seg);
    memory16set(0x1346 + seg, 0x0006, memory16get(0x1346 + seg, 0x0006) + seg);
    memory16set(0x1347 + seg, 0x000a, memory16get(0x1347 + seg, 0x000a) + seg);
    memory16set(0x1348 + seg, 0x000e, memory16get(0x1348 + seg, 0x000e) + seg);
    memory16set(0x134a + seg, 0x0006, memory16get(0x134a + seg, 0x0006) + seg);
    memory16set(0x134b + seg, 0x0004, memory16get(0x134b + seg, 0x0004) + seg);
    memory16set(0x134c + seg, 0x0002, memory16get(0x134c + seg, 0x0002) + seg);
    memory16set(0x134d + seg, 0x000a, memory16get(0x134d + seg, 0x000a) + seg);
    memory16set(0x134e + seg, 0x000e, memory16get(0x134e + seg, 0x000e) + seg);
    memory16set(0x1350 + seg, 0x0002, memory16get(0x1350 + seg, 0x0002) + seg);
    memory16set(0x1351 + seg, 0x0006, memory16get(0x1351 + seg, 0x0006) + seg);
    memory16set(0x1352 + seg, 0x000a, memory16get(0x1352 + seg, 0x000a) + seg);
    memory16set(0x1353 + seg, 0x000e, memory16get(0x1353 + seg, 0x000e) + seg);
    memory16set(0x1354 + seg, 0x000c, memory16get(0x1354 + seg, 0x000c) + seg);
    memory16set(0x1356 + seg, 0x0002, memory16get(0x1356 + seg, 0x0002) + seg);
    memory16set(0x1357 + seg, 0x0008, memory16get(0x1357 + seg, 0x0008) + seg);
    memory16set(0x1358 + seg, 0x000e, memory16get(0x1358 + seg, 0x000e) + seg);
    memory16set(0x135a + seg, 0x0002, memory16get(0x135a + seg, 0x0002) + seg);
    memory16set(0x135b + seg, 0x0006, memory16get(0x135b + seg, 0x0006) + seg);
    memory16set(0x135d + seg, 0x000a, memory16get(0x135d + seg, 0x000a) + seg);
    memory16set(0x135f + seg, 0x0000, memory16get(0x135f + seg, 0x0000) + seg);
    memory16set(0x1360 + seg, 0x0004, memory16get(0x1360 + seg, 0x0004) + seg);
    memory16set(0x1360 + seg, 0x000c, memory16get(0x1360 + seg, 0x000c) + seg);
    memory16set(0x1361 + seg, 0x0000, memory16get(0x1361 + seg, 0x0000) + seg);
    memory16set(0x1361 + seg, 0x0004, memory16get(0x1361 + seg, 0x0004) + seg);
    memory16set(0x1361 + seg, 0x0008, memory16get(0x1361 + seg, 0x0008) + seg);
    memory16set(0x1361 + seg, 0x000c, memory16get(0x1361 + seg, 0x000c) + seg);
    memory16set(0x1362 + seg, 0x0000, memory16get(0x1362 + seg, 0x0000) + seg);
    memory16set(0x1362 + seg, 0x0004, memory16get(0x1362 + seg, 0x0004) + seg);
    memory16set(0x1362 + seg, 0x0008, memory16get(0x1362 + seg, 0x0008) + seg);
    memory16set(0x1362 + seg, 0x000c, memory16get(0x1362 + seg, 0x000c) + seg);
    memory16set(0x1363 + seg, 0x0000, memory16get(0x1363 + seg, 0x0000) + seg);
    memory16set(0x1363 + seg, 0x0004, memory16get(0x1363 + seg, 0x0004) + seg);
    memory16set(0x1363 + seg, 0x0008, memory16get(0x1363 + seg, 0x0008) + seg);
    memory16set(0x1363 + seg, 0x000c, memory16get(0x1363 + seg, 0x000c) + seg);
    memory16set(0x1364 + seg, 0x0000, memory16get(0x1364 + seg, 0x0000) + seg);
    memory16set(0x1364 + seg, 0x0004, memory16get(0x1364 + seg, 0x0004) + seg);
    memory16set(0x1364 + seg, 0x0008, memory16get(0x1364 + seg, 0x0008) + seg);
    memory16set(0x1364 + seg, 0x000c, memory16get(0x1364 + seg, 0x000c) + seg);
    memory16set(0x1365 + seg, 0x0000, memory16get(0x1365 + seg, 0x0000) + seg);
    memory16set(0x1365 + seg, 0x0004, memory16get(0x1365 + seg, 0x0004) + seg);
    memory16set(0x1365 + seg, 0x0008, memory16get(0x1365 + seg, 0x0008) + seg);
    memory16set(0x1365 + seg, 0x000c, memory16get(0x1365 + seg, 0x000c) + seg);
    memory16set(0x1366 + seg, 0x0000, memory16get(0x1366 + seg, 0x0000) + seg);
    memory16set(0x1366 + seg, 0x0004, memory16get(0x1366 + seg, 0x0004) + seg);
    memory16set(0x1366 + seg, 0x0008, memory16get(0x1366 + seg, 0x0008) + seg);
    memory16set(0x1412 + seg, 0x0000, memory16get(0x1412 + seg, 0x0000) + seg);
    memory16set(0x1412 + seg, 0x0004, memory16get(0x1412 + seg, 0x0004) + seg);
    memory16set(0x1412 + seg, 0x0008, memory16get(0x1412 + seg, 0x0008) + seg);
    memory16set(0x1412 + seg, 0x000c, memory16get(0x1412 + seg, 0x000c) + seg);
    memory16set(0x1413 + seg, 0x0000, memory16get(0x1413 + seg, 0x0000) + seg);
    memory16set(0x1413 + seg, 0x0004, memory16get(0x1413 + seg, 0x0004) + seg);
    memory16set(0x1413 + seg, 0x0008, memory16get(0x1413 + seg, 0x0008) + seg);
    memory16set(0x1413 + seg, 0x000c, memory16get(0x1413 + seg, 0x000c) + seg);
    memory16set(0x1414 + seg, 0x0000, memory16get(0x1414 + seg, 0x0000) + seg);
    memory16set(0x1414 + seg, 0x0004, memory16get(0x1414 + seg, 0x0004) + seg);
    memory16set(0x1414 + seg, 0x0008, memory16get(0x1414 + seg, 0x0008) + seg);
    memory16set(0x1414 + seg, 0x000c, memory16get(0x1414 + seg, 0x000c) + seg);
    memory16set(0x1415 + seg, 0x0000, memory16get(0x1415 + seg, 0x0000) + seg);
    memory16set(0x1415 + seg, 0x0004, memory16get(0x1415 + seg, 0x0004) + seg);
    memory16set(0x1415 + seg, 0x0008, memory16get(0x1415 + seg, 0x0008) + seg);
    memory16set(0x1415 + seg, 0x000c, memory16get(0x1415 + seg, 0x000c) + seg);
    memory16set(0x1416 + seg, 0x0000, memory16get(0x1416 + seg, 0x0000) + seg);
    memory16set(0x1416 + seg, 0x0004, memory16get(0x1416 + seg, 0x0004) + seg);
    memory16set(0x1416 + seg, 0x0008, memory16get(0x1416 + seg, 0x0008) + seg);
    memory16set(0x1416 + seg, 0x000c, memory16get(0x1416 + seg, 0x000c) + seg);
    memory16set(0x1417 + seg, 0x0000, memory16get(0x1417 + seg, 0x0000) + seg);
    memory16set(0x1417 + seg, 0x0004, memory16get(0x1417 + seg, 0x0004) + seg);
    memory16set(0x1417 + seg, 0x0008, memory16get(0x1417 + seg, 0x0008) + seg);
    memory16set(0x1417 + seg, 0x000c, memory16get(0x1417 + seg, 0x000c) + seg);
    memory16set(0x1418 + seg, 0x0000, memory16get(0x1418 + seg, 0x0000) + seg);
    memory16set(0x1418 + seg, 0x0004, memory16get(0x1418 + seg, 0x0004) + seg);
    memory16set(0x1418 + seg, 0x0008, memory16get(0x1418 + seg, 0x0008) + seg);
    memory16set(0x1418 + seg, 0x000c, memory16get(0x1418 + seg, 0x000c) + seg);
    memory16set(0x1419 + seg, 0x0000, memory16get(0x1419 + seg, 0x0000) + seg);
    memory16set(0x1419 + seg, 0x0004, memory16get(0x1419 + seg, 0x0004) + seg);
    memory16set(0x1419 + seg, 0x0008, memory16get(0x1419 + seg, 0x0008) + seg);
    memory16set(0x1419 + seg, 0x000c, memory16get(0x1419 + seg, 0x000c) + seg);
    memory16set(0x141a + seg, 0x0000, memory16get(0x141a + seg, 0x0000) + seg);
    memory16set(0x141a + seg, 0x0004, memory16get(0x141a + seg, 0x0004) + seg);
    memory16set(0x141a + seg, 0x0008, memory16get(0x141a + seg, 0x0008) + seg);
    memory16set(0x141a + seg, 0x000c, memory16get(0x141a + seg, 0x000c) + seg);
    memory16set(0x141b + seg, 0x0000, memory16get(0x141b + seg, 0x0000) + seg);
    memory16set(0x141b + seg, 0x0004, memory16get(0x141b + seg, 0x0004) + seg);
    memory16set(0x141b + seg, 0x0008, memory16get(0x141b + seg, 0x0008) + seg);
    memory16set(0x141b + seg, 0x000c, memory16get(0x141b + seg, 0x000c) + seg);
    memory16set(0x141c + seg, 0x0000, memory16get(0x141c + seg, 0x0000) + seg);
    memory16set(0x141c + seg, 0x0004, memory16get(0x141c + seg, 0x0004) + seg);
    memory16set(0x141c + seg, 0x0008, memory16get(0x141c + seg, 0x0008) + seg);
    memory16set(0x141c + seg, 0x000c, memory16get(0x141c + seg, 0x000c) + seg);
    memory16set(0x141d + seg, 0x0000, memory16get(0x141d + seg, 0x0000) + seg);
    memory16set(0x141d + seg, 0x0004, memory16get(0x141d + seg, 0x0004) + seg);
    memory16set(0x141d + seg, 0x0008, memory16get(0x141d + seg, 0x0008) + seg);
    memory16set(0x141d + seg, 0x000c, memory16get(0x141d + seg, 0x000c) + seg);
    memory16set(0x141e + seg, 0x0000, memory16get(0x141e + seg, 0x0000) + seg);
    memory16set(0x141e + seg, 0x0004, memory16get(0x141e + seg, 0x0004) + seg);
    memory16set(0x141e + seg, 0x0008, memory16get(0x141e + seg, 0x0008) + seg);
    memory16set(0x141e + seg, 0x000c, memory16get(0x141e + seg, 0x000c) + seg);
    memory16set(0x141f + seg, 0x0000, memory16get(0x141f + seg, 0x0000) + seg);
    memory16set(0x141f + seg, 0x0004, memory16get(0x141f + seg, 0x0004) + seg);
    memory16set(0x141f + seg, 0x0008, memory16get(0x141f + seg, 0x0008) + seg);
    memory16set(0x141f + seg, 0x000c, memory16get(0x141f + seg, 0x000c) + seg);
    memory16set(0x1420 + seg, 0x0000, memory16get(0x1420 + seg, 0x0000) + seg);
    memory16set(0x1420 + seg, 0x0004, memory16get(0x1420 + seg, 0x0004) + seg);
    memory16set(0x1420 + seg, 0x0008, memory16get(0x1420 + seg, 0x0008) + seg);
    memory16set(0x1420 + seg, 0x000c, memory16get(0x1420 + seg, 0x000c) + seg);
    memory16set(0x1421 + seg, 0x0000, memory16get(0x1421 + seg, 0x0000) + seg);
    memory16set(0x1421 + seg, 0x0004, memory16get(0x1421 + seg, 0x0004) + seg);
    memory16set(0x1421 + seg, 0x0008, memory16get(0x1421 + seg, 0x0008) + seg);
    memory16set(0x1421 + seg, 0x000c, memory16get(0x1421 + seg, 0x000c) + seg);
    memory16set(0x1422 + seg, 0x0000, memory16get(0x1422 + seg, 0x0000) + seg);
    memory16set(0x1422 + seg, 0x0004, memory16get(0x1422 + seg, 0x0004) + seg);
    memory16set(0x1422 + seg, 0x0008, memory16get(0x1422 + seg, 0x0008) + seg);
    memory16set(0x1422 + seg, 0x000c, memory16get(0x1422 + seg, 0x000c) + seg);
    memory16set(0x1423 + seg, 0x0000, memory16get(0x1423 + seg, 0x0000) + seg);
    memory16set(0x1423 + seg, 0x0004, memory16get(0x1423 + seg, 0x0004) + seg);
    memory16set(0x1423 + seg, 0x0008, memory16get(0x1423 + seg, 0x0008) + seg);
    memory16set(0x1423 + seg, 0x000c, memory16get(0x1423 + seg, 0x000c) + seg);
    memory16set(0x1424 + seg, 0x0000, memory16get(0x1424 + seg, 0x0000) + seg);
    memory16set(0x1424 + seg, 0x0004, memory16get(0x1424 + seg, 0x0004) + seg);
    memory16set(0x1424 + seg, 0x0008, memory16get(0x1424 + seg, 0x0008) + seg);
    memory16set(0x1424 + seg, 0x000c, memory16get(0x1424 + seg, 0x000c) + seg);
    memory16set(0x1425 + seg, 0x0000, memory16get(0x1425 + seg, 0x0000) + seg);
    memory16set(0x1425 + seg, 0x0004, memory16get(0x1425 + seg, 0x0004) + seg);
    memory16set(0x1425 + seg, 0x0008, memory16get(0x1425 + seg, 0x0008) + seg);
    memory16set(0x1425 + seg, 0x000c, memory16get(0x1425 + seg, 0x000c) + seg);
    memory16set(0x1426 + seg, 0x0000, memory16get(0x1426 + seg, 0x0000) + seg);
    memory16set(0x1426 + seg, 0x0004, memory16get(0x1426 + seg, 0x0004) + seg);
    memory16set(0x1426 + seg, 0x0008, memory16get(0x1426 + seg, 0x0008) + seg);
    memory16set(0x1426 + seg, 0x000c, memory16get(0x1426 + seg, 0x000c) + seg);
    memory16set(0x1427 + seg, 0x0000, memory16get(0x1427 + seg, 0x0000) + seg);
    memory16set(0x1427 + seg, 0x0004, memory16get(0x1427 + seg, 0x0004) + seg);
    memory16set(0x1427 + seg, 0x0008, memory16get(0x1427 + seg, 0x0008) + seg);
    memory16set(0x1427 + seg, 0x000c, memory16get(0x1427 + seg, 0x000c) + seg);
    memory16set(0x1428 + seg, 0x0000, memory16get(0x1428 + seg, 0x0000) + seg);
    memory16set(0x1428 + seg, 0x0004, memory16get(0x1428 + seg, 0x0004) + seg);
    memory16set(0x1428 + seg, 0x0008, memory16get(0x1428 + seg, 0x0008) + seg);
    memory16set(0x1428 + seg, 0x000c, memory16get(0x1428 + seg, 0x000c) + seg);
    memory16set(0x1429 + seg, 0x0000, memory16get(0x1429 + seg, 0x0000) + seg);
    memory16set(0x1429 + seg, 0x0004, memory16get(0x1429 + seg, 0x0004) + seg);
    memory16set(0x1429 + seg, 0x0008, memory16get(0x1429 + seg, 0x0008) + seg);
    memory16set(0x1429 + seg, 0x000c, memory16get(0x1429 + seg, 0x000c) + seg);
    memory16set(0x142a + seg, 0x0000, memory16get(0x142a + seg, 0x0000) + seg);
    memory16set(0x142a + seg, 0x0004, memory16get(0x142a + seg, 0x0004) + seg);
    memory16set(0x142a + seg, 0x0008, memory16get(0x142a + seg, 0x0008) + seg);
    memory16set(0x142a + seg, 0x000c, memory16get(0x142a + seg, 0x000c) + seg);
    memory16set(0x142b + seg, 0x0000, memory16get(0x142b + seg, 0x0000) + seg);
    memory16set(0x142b + seg, 0x0004, memory16get(0x142b + seg, 0x0004) + seg);
    memory16set(0x142b + seg, 0x0008, memory16get(0x142b + seg, 0x0008) + seg);
    memory16set(0x142b + seg, 0x000c, memory16get(0x142b + seg, 0x000c) + seg);
    memory16set(0x142c + seg, 0x0000, memory16get(0x142c + seg, 0x0000) + seg);
    memory16set(0x142c + seg, 0x0004, memory16get(0x142c + seg, 0x0004) + seg);
    memory16set(0x142c + seg, 0x0008, memory16get(0x142c + seg, 0x0008) + seg);
    memory16set(0x142c + seg, 0x000c, memory16get(0x142c + seg, 0x000c) + seg);
    memory16set(0x142d + seg, 0x0000, memory16get(0x142d + seg, 0x0000) + seg);
    memory16set(0x142d + seg, 0x0004, memory16get(0x142d + seg, 0x0004) + seg);
    memory16set(0x142d + seg, 0x0008, memory16get(0x142d + seg, 0x0008) + seg);
    memory16set(0x142d + seg, 0x000c, memory16get(0x142d + seg, 0x000c) + seg);
    memory16set(0x142e + seg, 0x0000, memory16get(0x142e + seg, 0x0000) + seg);
    memory16set(0x142e + seg, 0x0004, memory16get(0x142e + seg, 0x0004) + seg);
    memory16set(0x142e + seg, 0x0008, memory16get(0x142e + seg, 0x0008) + seg);
    memory16set(0x142e + seg, 0x000c, memory16get(0x142e + seg, 0x000c) + seg);
    memory16set(0x142f + seg, 0x0000, memory16get(0x142f + seg, 0x0000) + seg);
    memory16set(0x142f + seg, 0x0004, memory16get(0x142f + seg, 0x0004) + seg);
    memory16set(0x142f + seg, 0x0008, memory16get(0x142f + seg, 0x0008) + seg);
    memory16set(0x142f + seg, 0x000c, memory16get(0x142f + seg, 0x000c) + seg);
    memory16set(0x1430 + seg, 0x0000, memory16get(0x1430 + seg, 0x0000) + seg);
    memory16set(0x1430 + seg, 0x0004, memory16get(0x1430 + seg, 0x0004) + seg);
    memory16set(0x1430 + seg, 0x0008, memory16get(0x1430 + seg, 0x0008) + seg);
    memory16set(0x1430 + seg, 0x000c, memory16get(0x1430 + seg, 0x000c) + seg);
    memory16set(0x1431 + seg, 0x0000, memory16get(0x1431 + seg, 0x0000) + seg);
    memory16set(0x1431 + seg, 0x0004, memory16get(0x1431 + seg, 0x0004) + seg);
    memory16set(0x1431 + seg, 0x0008, memory16get(0x1431 + seg, 0x0008) + seg);
    memory16set(0x1431 + seg, 0x000c, memory16get(0x1431 + seg, 0x000c) + seg);
    memory16set(0x1432 + seg, 0x0000, memory16get(0x1432 + seg, 0x0000) + seg);
    memory16set(0x1432 + seg, 0x0004, memory16get(0x1432 + seg, 0x0004) + seg);
    memory16set(0x1432 + seg, 0x0008, memory16get(0x1432 + seg, 0x0008) + seg);
    memory16set(0x1432 + seg, 0x000c, memory16get(0x1432 + seg, 0x000c) + seg);
    memory16set(0x1433 + seg, 0x0000, memory16get(0x1433 + seg, 0x0000) + seg);
    memory16set(0x1433 + seg, 0x0004, memory16get(0x1433 + seg, 0x0004) + seg);
    memory16set(0x1433 + seg, 0x0008, memory16get(0x1433 + seg, 0x0008) + seg);
    memory16set(0x1433 + seg, 0x000c, memory16get(0x1433 + seg, 0x000c) + seg);
    memory16set(0x1434 + seg, 0x0000, memory16get(0x1434 + seg, 0x0000) + seg);
    memory16set(0x1434 + seg, 0x0004, memory16get(0x1434 + seg, 0x0004) + seg);
    memory16set(0x1434 + seg, 0x0008, memory16get(0x1434 + seg, 0x0008) + seg);
    memory16set(0x1434 + seg, 0x000c, memory16get(0x1434 + seg, 0x000c) + seg);
    memory16set(0x1435 + seg, 0x0000, memory16get(0x1435 + seg, 0x0000) + seg);
    memory16set(0x1435 + seg, 0x0004, memory16get(0x1435 + seg, 0x0004) + seg);
    memory16set(0x1435 + seg, 0x0008, memory16get(0x1435 + seg, 0x0008) + seg);
    memory16set(0x1435 + seg, 0x000c, memory16get(0x1435 + seg, 0x000c) + seg);
    memory16set(0x1436 + seg, 0x0000, memory16get(0x1436 + seg, 0x0000) + seg);
    memory16set(0x1436 + seg, 0x0004, memory16get(0x1436 + seg, 0x0004) + seg);
    memory16set(0x1436 + seg, 0x0008, memory16get(0x1436 + seg, 0x0008) + seg);
    memory16set(0x1436 + seg, 0x000c, memory16get(0x1436 + seg, 0x000c) + seg);
    memory16set(0x1437 + seg, 0x0000, memory16get(0x1437 + seg, 0x0000) + seg);
    memory16set(0x1437 + seg, 0x0004, memory16get(0x1437 + seg, 0x0004) + seg);
    memory16set(0x1437 + seg, 0x0008, memory16get(0x1437 + seg, 0x0008) + seg);
    memory16set(0x1437 + seg, 0x000c, memory16get(0x1437 + seg, 0x000c) + seg);
    memory16set(0x1438 + seg, 0x0000, memory16get(0x1438 + seg, 0x0000) + seg);
    memory16set(0x1438 + seg, 0x0004, memory16get(0x1438 + seg, 0x0004) + seg);
    memory16set(0x1438 + seg, 0x0008, memory16get(0x1438 + seg, 0x0008) + seg);
    memory16set(0x1438 + seg, 0x000c, memory16get(0x1438 + seg, 0x000c) + seg);
    memory16set(0x1439 + seg, 0x0000, memory16get(0x1439 + seg, 0x0000) + seg);
    memory16set(0x1439 + seg, 0x0004, memory16get(0x1439 + seg, 0x0004) + seg);
    memory16set(0x1439 + seg, 0x0008, memory16get(0x1439 + seg, 0x0008) + seg);
    memory16set(0x1439 + seg, 0x000c, memory16get(0x1439 + seg, 0x000c) + seg);
    memory16set(0x143a + seg, 0x0000, memory16get(0x143a + seg, 0x0000) + seg);
    memory16set(0x143a + seg, 0x0004, memory16get(0x143a + seg, 0x0004) + seg);
    memory16set(0x143a + seg, 0x0008, memory16get(0x143a + seg, 0x0008) + seg);
    memory16set(0x143a + seg, 0x000c, memory16get(0x143a + seg, 0x000c) + seg);
    memory16set(0x143b + seg, 0x0000, memory16get(0x143b + seg, 0x0000) + seg);
    memory16set(0x143b + seg, 0x0004, memory16get(0x143b + seg, 0x0004) + seg);
    memory16set(0x143b + seg, 0x0008, memory16get(0x143b + seg, 0x0008) + seg);
    memory16set(0x143b + seg, 0x000c, memory16get(0x143b + seg, 0x000c) + seg);
    memory16set(0x143c + seg, 0x0000, memory16get(0x143c + seg, 0x0000) + seg);
    memory16set(0x143c + seg, 0x0004, memory16get(0x143c + seg, 0x0004) + seg);
    memory16set(0x143c + seg, 0x0008, memory16get(0x143c + seg, 0x0008) + seg);
    memory16set(0x143c + seg, 0x000c, memory16get(0x143c + seg, 0x000c) + seg);
    memory16set(0x143d + seg, 0x0000, memory16get(0x143d + seg, 0x0000) + seg);
    memory16set(0x143d + seg, 0x0004, memory16get(0x143d + seg, 0x0004) + seg);
    memory16set(0x143d + seg, 0x0008, memory16get(0x143d + seg, 0x0008) + seg);
    memory16set(0x143d + seg, 0x000c, memory16get(0x143d + seg, 0x000c) + seg);
    memory16set(0x143e + seg, 0x0000, memory16get(0x143e + seg, 0x0000) + seg);
    memory16set(0x143e + seg, 0x0004, memory16get(0x143e + seg, 0x0004) + seg);
    memory16set(0x143e + seg, 0x0008, memory16get(0x143e + seg, 0x0008) + seg);
    memory16set(0x143e + seg, 0x000c, memory16get(0x143e + seg, 0x000c) + seg);
    memory16set(0x143f + seg, 0x0000, memory16get(0x143f + seg, 0x0000) + seg);
    memory16set(0x143f + seg, 0x0004, memory16get(0x143f + seg, 0x0004) + seg);
    memory16set(0x143f + seg, 0x0008, memory16get(0x143f + seg, 0x0008) + seg);
    memory16set(0x143f + seg, 0x000c, memory16get(0x143f + seg, 0x000c) + seg);
    memory16set(0x1440 + seg, 0x0000, memory16get(0x1440 + seg, 0x0000) + seg);
    memory16set(0x1440 + seg, 0x0004, memory16get(0x1440 + seg, 0x0004) + seg);
    memory16set(0x1440 + seg, 0x0008, memory16get(0x1440 + seg, 0x0008) + seg);
    memory16set(0x1440 + seg, 0x000c, memory16get(0x1440 + seg, 0x000c) + seg);
    memory16set(0x1441 + seg, 0x0000, memory16get(0x1441 + seg, 0x0000) + seg);
    memory16set(0x1441 + seg, 0x0004, memory16get(0x1441 + seg, 0x0004) + seg);
    memory16set(0x1441 + seg, 0x0008, memory16get(0x1441 + seg, 0x0008) + seg);
    memory16set(0x1441 + seg, 0x000c, memory16get(0x1441 + seg, 0x000c) + seg);
    memory16set(0x1442 + seg, 0x0000, memory16get(0x1442 + seg, 0x0000) + seg);
    memory16set(0x1442 + seg, 0x0004, memory16get(0x1442 + seg, 0x0004) + seg);
    memory16set(0x1442 + seg, 0x0008, memory16get(0x1442 + seg, 0x0008) + seg);
    memory16set(0x1442 + seg, 0x000c, memory16get(0x1442 + seg, 0x000c) + seg);
    memory16set(0x1443 + seg, 0x0000, memory16get(0x1443 + seg, 0x0000) + seg);
    memory16set(0x1445 + seg, 0x000c, memory16get(0x1445 + seg, 0x000c) + seg);
    memory16set(0x1446 + seg, 0x0000, memory16get(0x1446 + seg, 0x0000) + seg);
    memory16set(0x1446 + seg, 0x0004, memory16get(0x1446 + seg, 0x0004) + seg);
    memory16set(0x1446 + seg, 0x0008, memory16get(0x1446 + seg, 0x0008) + seg);
    memory16set(0x1446 + seg, 0x000c, memory16get(0x1446 + seg, 0x000c) + seg);
    memory16set(0x1447 + seg, 0x0000, memory16get(0x1447 + seg, 0x0000) + seg);
    memory16set(0x1447 + seg, 0x0004, memory16get(0x1447 + seg, 0x0004) + seg);
    memory16set(0x1447 + seg, 0x0008, memory16get(0x1447 + seg, 0x0008) + seg);
    memory16set(0x1447 + seg, 0x000c, memory16get(0x1447 + seg, 0x000c) + seg);
    memory16set(0x1448 + seg, 0x0000, memory16get(0x1448 + seg, 0x0000) + seg);
    memory16set(0x1448 + seg, 0x0004, memory16get(0x1448 + seg, 0x0004) + seg);
    memory16set(0x1448 + seg, 0x0008, memory16get(0x1448 + seg, 0x0008) + seg);
    memory16set(0x1448 + seg, 0x000c, memory16get(0x1448 + seg, 0x000c) + seg);
    memory16set(0x1449 + seg, 0x0000, memory16get(0x1449 + seg, 0x0000) + seg);
    memory16set(0x1449 + seg, 0x0004, memory16get(0x1449 + seg, 0x0004) + seg);
    memory16set(0x1449 + seg, 0x0008, memory16get(0x1449 + seg, 0x0008) + seg);
    memory16set(0x1449 + seg, 0x000c, memory16get(0x1449 + seg, 0x000c) + seg);
    memory16set(0x144a + seg, 0x0000, memory16get(0x144a + seg, 0x0000) + seg);
    memory16set(0x144a + seg, 0x0004, memory16get(0x144a + seg, 0x0004) + seg);
    memory16set(0x144a + seg, 0x0008, memory16get(0x144a + seg, 0x0008) + seg);
    memory16set(0x144a + seg, 0x000c, memory16get(0x144a + seg, 0x000c) + seg);
    memory16set(0x144b + seg, 0x0000, memory16get(0x144b + seg, 0x0000) + seg);
    memory16set(0x144b + seg, 0x0004, memory16get(0x144b + seg, 0x0004) + seg);
    memory16set(0x144b + seg, 0x0008, memory16get(0x144b + seg, 0x0008) + seg);
    memory16set(0x144b + seg, 0x000c, memory16get(0x144b + seg, 0x000c) + seg);
    memory16set(0x144c + seg, 0x0000, memory16get(0x144c + seg, 0x0000) + seg);
    memory16set(0x144c + seg, 0x0004, memory16get(0x144c + seg, 0x0004) + seg);
    memory16set(0x144c + seg, 0x0008, memory16get(0x144c + seg, 0x0008) + seg);
    memory16set(0x144c + seg, 0x000c, memory16get(0x144c + seg, 0x000c) + seg);
    memory16set(0x144d + seg, 0x0000, memory16get(0x144d + seg, 0x0000) + seg);
    memory16set(0x144d + seg, 0x0004, memory16get(0x144d + seg, 0x0004) + seg);
    memory16set(0x144d + seg, 0x0008, memory16get(0x144d + seg, 0x0008) + seg);
    memory16set(0x144d + seg, 0x000c, memory16get(0x144d + seg, 0x000c) + seg);
    memory16set(0x144e + seg, 0x0000, memory16get(0x144e + seg, 0x0000) + seg);
    memory16set(0x144e + seg, 0x0004, memory16get(0x144e + seg, 0x0004) + seg);
    memory16set(0x144e + seg, 0x0008, memory16get(0x144e + seg, 0x0008) + seg);
    memory16set(0x144e + seg, 0x000c, memory16get(0x144e + seg, 0x000c) + seg);
    memory16set(0x144f + seg, 0x0000, memory16get(0x144f + seg, 0x0000) + seg);
    memory16set(0x144f + seg, 0x0004, memory16get(0x144f + seg, 0x0004) + seg);
    memory16set(0x144f + seg, 0x0008, memory16get(0x144f + seg, 0x0008) + seg);
    memory16set(0x144f + seg, 0x000c, memory16get(0x144f + seg, 0x000c) + seg);
    memory16set(0x1450 + seg, 0x0000, memory16get(0x1450 + seg, 0x0000) + seg);
    memory16set(0x1450 + seg, 0x0004, memory16get(0x1450 + seg, 0x0004) + seg);
    memory16set(0x1450 + seg, 0x0008, memory16get(0x1450 + seg, 0x0008) + seg);
    memory16set(0x1450 + seg, 0x000c, memory16get(0x1450 + seg, 0x000c) + seg);
    memory16set(0x1451 + seg, 0x0000, memory16get(0x1451 + seg, 0x0000) + seg);
    memory16set(0x1451 + seg, 0x0004, memory16get(0x1451 + seg, 0x0004) + seg);
    memory16set(0x1451 + seg, 0x0008, memory16get(0x1451 + seg, 0x0008) + seg);
    memory16set(0x1451 + seg, 0x000c, memory16get(0x1451 + seg, 0x000c) + seg);
    memory16set(0x1452 + seg, 0x0000, memory16get(0x1452 + seg, 0x0000) + seg);
    memory16set(0x1452 + seg, 0x0004, memory16get(0x1452 + seg, 0x0004) + seg);
    memory16set(0x1452 + seg, 0x0008, memory16get(0x1452 + seg, 0x0008) + seg);
    memory16set(0x1452 + seg, 0x000c, memory16get(0x1452 + seg, 0x000c) + seg);
    memory16set(0x1453 + seg, 0x0000, memory16get(0x1453 + seg, 0x0000) + seg);
    memory16set(0x1453 + seg, 0x0004, memory16get(0x1453 + seg, 0x0004) + seg);
    memory16set(0x1453 + seg, 0x0008, memory16get(0x1453 + seg, 0x0008) + seg);
    memory16set(0x1453 + seg, 0x000c, memory16get(0x1453 + seg, 0x000c) + seg);
    memory16set(0x1454 + seg, 0x0000, memory16get(0x1454 + seg, 0x0000) + seg);
    memory16set(0x1454 + seg, 0x0004, memory16get(0x1454 + seg, 0x0004) + seg);
    memory16set(0x1454 + seg, 0x0008, memory16get(0x1454 + seg, 0x0008) + seg);
    memory16set(0x1454 + seg, 0x000c, memory16get(0x1454 + seg, 0x000c) + seg);
    memory16set(0x1455 + seg, 0x0000, memory16get(0x1455 + seg, 0x0000) + seg);
    memory16set(0x1455 + seg, 0x0004, memory16get(0x1455 + seg, 0x0004) + seg);
    memory16set(0x1455 + seg, 0x0008, memory16get(0x1455 + seg, 0x0008) + seg);
    memory16set(0x1455 + seg, 0x000c, memory16get(0x1455 + seg, 0x000c) + seg);
    memory16set(0x1456 + seg, 0x0000, memory16get(0x1456 + seg, 0x0000) + seg);
    memory16set(0x1456 + seg, 0x0004, memory16get(0x1456 + seg, 0x0004) + seg);
    memory16set(0x1456 + seg, 0x0008, memory16get(0x1456 + seg, 0x0008) + seg);
    memory16set(0x1456 + seg, 0x000c, memory16get(0x1456 + seg, 0x000c) + seg);
    memory16set(0x1457 + seg, 0x0000, memory16get(0x1457 + seg, 0x0000) + seg);
    memory16set(0x1457 + seg, 0x0004, memory16get(0x1457 + seg, 0x0004) + seg);
    memory16set(0x1457 + seg, 0x0008, memory16get(0x1457 + seg, 0x0008) + seg);
    memory16set(0x1457 + seg, 0x000c, memory16get(0x1457 + seg, 0x000c) + seg);
    memory16set(0x1458 + seg, 0x0000, memory16get(0x1458 + seg, 0x0000) + seg);
    memory16set(0x1458 + seg, 0x0004, memory16get(0x1458 + seg, 0x0004) + seg);
    memory16set(0x1458 + seg, 0x0008, memory16get(0x1458 + seg, 0x0008) + seg);
    memory16set(0x1458 + seg, 0x000c, memory16get(0x1458 + seg, 0x000c) + seg);
    memory16set(0x1459 + seg, 0x0000, memory16get(0x1459 + seg, 0x0000) + seg);
    memory16set(0x1459 + seg, 0x0004, memory16get(0x1459 + seg, 0x0004) + seg);
    memory16set(0x1459 + seg, 0x0008, memory16get(0x1459 + seg, 0x0008) + seg);
    memory16set(0x1459 + seg, 0x000c, memory16get(0x1459 + seg, 0x000c) + seg);
    memory16set(0x145a + seg, 0x0000, memory16get(0x145a + seg, 0x0000) + seg);
    memory16set(0x145a + seg, 0x0004, memory16get(0x145a + seg, 0x0004) + seg);
    memory16set(0x145a + seg, 0x0008, memory16get(0x145a + seg, 0x0008) + seg);
    memory16set(0x145a + seg, 0x000c, memory16get(0x145a + seg, 0x000c) + seg);
    memory16set(0x145b + seg, 0x0000, memory16get(0x145b + seg, 0x0000) + seg);
    memory16set(0x145b + seg, 0x0004, memory16get(0x145b + seg, 0x0004) + seg);
    memory16set(0x145b + seg, 0x0008, memory16get(0x145b + seg, 0x0008) + seg);
    memory16set(0x145b + seg, 0x000c, memory16get(0x145b + seg, 0x000c) + seg);
    memory16set(0x145c + seg, 0x0000, memory16get(0x145c + seg, 0x0000) + seg);
    memory16set(0x145c + seg, 0x0004, memory16get(0x145c + seg, 0x0004) + seg);
    memory16set(0x145c + seg, 0x0008, memory16get(0x145c + seg, 0x0008) + seg);
    memory16set(0x145c + seg, 0x000c, memory16get(0x145c + seg, 0x000c) + seg);
    memory16set(0x145d + seg, 0x0000, memory16get(0x145d + seg, 0x0000) + seg);
    memory16set(0x145d + seg, 0x0004, memory16get(0x145d + seg, 0x0004) + seg);
    memory16set(0x145d + seg, 0x0008, memory16get(0x145d + seg, 0x0008) + seg);
    memory16set(0x145d + seg, 0x000c, memory16get(0x145d + seg, 0x000c) + seg);
    memory16set(0x145e + seg, 0x0000, memory16get(0x145e + seg, 0x0000) + seg);
    memory16set(0x145e + seg, 0x0004, memory16get(0x145e + seg, 0x0004) + seg);
    memory16set(0x145e + seg, 0x0008, memory16get(0x145e + seg, 0x0008) + seg);
    memory16set(0x145e + seg, 0x000c, memory16get(0x145e + seg, 0x000c) + seg);
    memory16set(0x145f + seg, 0x0000, memory16get(0x145f + seg, 0x0000) + seg);
    memory16set(0x145f + seg, 0x0004, memory16get(0x145f + seg, 0x0004) + seg);
    memory16set(0x145f + seg, 0x0008, memory16get(0x145f + seg, 0x0008) + seg);
    memory16set(0x145f + seg, 0x000c, memory16get(0x145f + seg, 0x000c) + seg);
    memory16set(0x1460 + seg, 0x0000, memory16get(0x1460 + seg, 0x0000) + seg);
    memory16set(0x1502 + seg, 0x0002, memory16get(0x1502 + seg, 0x0002) + seg);
    memory16set(0x1502 + seg, 0x0006, memory16get(0x1502 + seg, 0x0006) + seg);
    memory16set(0x1502 + seg, 0x000a, memory16get(0x1502 + seg, 0x000a) + seg);
    memory16set(0x1502 + seg, 0x000e, memory16get(0x1502 + seg, 0x000e) + seg);
    memory16set(0x1506 + seg, 0x000e, memory16get(0x1506 + seg, 0x000e) + seg);
    memory16set(0x1507 + seg, 0x0002, memory16get(0x1507 + seg, 0x0002) + seg);
    memory16set(0x1507 + seg, 0x0006, memory16get(0x1507 + seg, 0x0006) + seg);
    memory16set(0x1507 + seg, 0x000a, memory16get(0x1507 + seg, 0x000a) + seg);
    memory16set(0x1507 + seg, 0x000e, memory16get(0x1507 + seg, 0x000e) + seg);
    memory16set(0x1584 + seg, 0x0004, memory16get(0x1584 + seg, 0x0004) + seg);
    memory16set(0x1584 + seg, 0x0008, memory16get(0x1584 + seg, 0x0008) + seg);
    memory16set(0x1587 + seg, 0x000e, memory16get(0x1587 + seg, 0x000e) + seg);
    memory16set(0x15a9 + seg, 0x0000, memory16get(0x15a9 + seg, 0x0000) + seg);
}
function* callIndirect(seg, ofs) {
    if(seg == 0x01ed)
        switch (ofs)
    {
    case 0x6648: yield* sub_8518(); return;
    case 0x7111: yield* sub_8fe1(); return;
    case 0x6717: yield* sub_85e7(); return;
    case 0x654e: yield* sub_841e(); return;
    case 0x6587: yield* sub_8457(); return;
    case 0x65fb: yield* sub_84cb(); return;
    case 0x0: yield* sub_1ed0(); return;
    case 0x6699: yield* sub_8569(); return;
    case 0x6326: yield* sub_81f6(); return;
    case 0x651c: yield* sub_83ec(); return;
    case 0x65e5: yield* sub_84b5(); return;
    case 0x6627: yield* sub_84f7(); return;
    case 0x66d8: yield* sub_85a8(); return;
    case 0x6372: yield* sub_8242(); return;
    case 0x6535: yield* sub_8405(); return;
    case 0x673a: yield* sub_860a(); return;
    case 0x64e2: yield* sub_83b2(); return;
    case 0x6611: yield* sub_84e1(); return;
    case 0x64ff: yield* sub_83cf(); return;
    case 0x647e: yield* sub_834e(); return;
    case 0x6748: yield* sub_8618(); return;
    case 0x6789: yield* sub_8659(); return;
    case 0x6305: yield* sub_81d5(); return;
    case 0x640c: yield* sub_82dc(); return;
    case 0x645d: yield* sub_832d(); return;
    case 0x65d2: yield* sub_84a2(); return;
    case 0x68fe: yield* sub_87ce(); return;
    case 0x693a: yield* sub_880a(); return;
    case 0x64c1: yield* sub_8391(); return;
    case 0x67e2: yield* sub_86b2(); return;
    case 0x6813: yield* sub_86e3(); return;
    case 0x67ca: yield* sub_869a(); return;
    case 0x67fb: yield* sub_86cb(); return;
    case 0x6832: yield* sub_8702(); return;
    case 0x684b: yield* sub_871b(); return;
    case 0x68e6: yield* sub_87b6(); return;
    case 0x6922: yield* sub_87f2(); return;
    case 0x6890: yield* sub_8760(); return;
    case 0x68bb: yield* sub_878b(); return;
        default:
        break;
    }
    if(seg == 0x01ed)
        switch (ofs)
    {
    case 0x9c62: yield* sub_bb32(); return;
        default:
        break;
    }
    if(seg == 0x01ed)
        switch (ofs)
    {
    case 0xaa4e: yield* sub_c91e(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0x14ef: yield* sub_df4f(); return;
        default:
        break;
    }
    if(seg == 0x0e15)
        switch (ofs)
    {
    case 0x193: yield* sub_e2e3(); return;
    case 0x194: yield* sub_e2e4(); return;
    case 0x4b0: yield* sub_e600(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0x1ae: yield* sub_cc0e(); return;
    case 0x0: yield* sub_ca60(); return;
    case 0x1af: yield* sub_cc0f(); return;
    case 0x1b0: yield* sub_cc10(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0x2b: yield* sub_ca8b(); return;
    case 0x178: yield* sub_cbd8(); return;
    case 0xc6: yield* sub_cb26(); return;
    case 0x11d: yield* sub_cb7d(); return;
    case 0x115: yield* sub_cb75(); return;
    case 0x125: yield* sub_cb85(); return;
    case 0x72: yield* sub_cad2(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0x605: yield* sub_d065(); return;
    case 0x606: yield* sub_d066(); return;
    case 0x620: yield* sub_d080(); return;
    case 0x64b: yield* sub_d0ab(); return;
    case 0x64c: yield* sub_d0ac(); return;
    case 0x661: yield* sub_d0c1(); return;
    case 0x662: yield* sub_d0c2(); return;
    case 0x677: yield* sub_d0d7(); return;
    case 0x6bd: yield* sub_d11d(); return;
    case 0x6be: yield* sub_d11e(); return;
    case 0x6bf: yield* sub_d11f(); return;
    case 0x0: yield* sub_ca60(); return;
    case 0x1: yield* sub_ca61(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0x2: yield* sub_ca62(); return;
    case 0x3: yield* sub_ca63(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0x991: yield* sub_d3f1(); return;
    case 0x7f0: yield* sub_d250(); return;
    case 0x997: yield* sub_d3f7(); return;
    case 0x998: yield* sub_d3f8(); return;
    case 0x999: yield* sub_d3f9(); return;
    case 0xad0: yield* sub_d530(); return;
    case 0xc7f: yield* sub_d6df(); return;
    case 0xb3c: yield* sub_d59c(); return;
    case 0xc05: yield* sub_d665(); return;
    case 0xbfd: yield* sub_d65d(); return;
    case 0xc0d: yield* sub_d66d(); return;
    case 0xb33: yield* sub_d593(); return;
    case 0xc80: yield* sub_d6e0(); return;
    case 0xaa0: yield* sub_d500(); return;
    case 0xc86: yield* sub_d6e6(); return;
    case 0xc87: yield* sub_d6e7(); return;
    case 0xc88: yield* sub_d6e8(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0xad0: yield* sub_d530(); return;
    case 0xc7f: yield* sub_d6df(); return;
    case 0xb3c: yield* sub_d59c(); return;
    case 0xc05: yield* sub_d665(); return;
    case 0xbfd: yield* sub_d65d(); return;
    case 0xc0d: yield* sub_d66d(); return;
    case 0xb33: yield* sub_d593(); return;
    case 0xc80: yield* sub_d6e0(); return;
    case 0xaa0: yield* sub_d500(); return;
    case 0xc86: yield* sub_d6e6(); return;
    case 0xc87: yield* sub_d6e7(); return;
    case 0xc88: yield* sub_d6e8(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0x11d6: yield* sub_dc36(); return;
    case 0x1060: yield* sub_dac0(); return;
    case 0x11dc: yield* sub_dc3c(); return;
    case 0x11dd: yield* sub_dc3d(); return;
    case 0x11de: yield* sub_dc3e(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0x1606: yield* sub_e066(); return;
    case 0x1607: yield* sub_e067(); return;
    case 0x16e2: yield* sub_e142(); return;
    case 0x16e1: yield* sub_e141(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0xde0: yield* sub_d840(); return;
    case 0xf35: yield* sub_d995(); return;
    case 0xec3: yield* sub_d923(); return;
        default:
        break;
    }
    if(seg == 0x01ed)
        switch (ofs)
    {
    case 0x28f9: yield* sub_47c9(); return;
    case 0x23b6: yield* sub_4286(); return;
    case 0x2423: yield* sub_42f3(); return;
    case 0x2470: yield* sub_4340(); return;
    case 0x248e: yield* sub_435e(); return;
    case 0x24d7: yield* sub_43a7(); return;
    case 0x250a: yield* sub_43da(); return;
    case 0x25ad: yield* sub_447d(); return;
    case 0x22b0: yield* sub_4180(); return;
    case 0x4344: yield* sub_6214(); return;
    case 0x4437: yield* sub_6307(); return;
    case 0x1e5e: yield* sub_3d2e(); return;
    case 0x1e90: yield* sub_3d60(); return;
    case 0x1ec2: yield* sub_3d92(); return;
    case 0x1f3e: yield* sub_3e0e(); return;
    case 0x2138: yield* sub_4008(); return;
    case 0x21e7: yield* sub_40b7(); return;
    case 0x22c1: yield* sub_4191(); return;
    case 0x22d2: yield* sub_41a2(); return;
    case 0x2810: yield* sub_46e0(); return;
    case 0x1e3d: yield* sub_3d0d(); return;
        default:
        break;
    }
    if(seg == 0x01ed)
        switch (ofs)
    {
    case 0x7111: yield* sub_8fe1(); return;
    case 0x4dbf: yield* sub_6c8f(); return;
    case 0x4e44: yield* sub_6d14(); return;
    case 0x4ec9: yield* sub_6d99(); return;
    case 0x4f4e: yield* sub_6e1e(); return;
        default:
        break;
    }
    if(seg == 0x01ed)
        switch (ofs)
    {
    case 0x7111: yield* sub_8fe1(); return;
    case 0x5025: yield* sub_6ef5(); return;
    case 0x503f: yield* sub_6f0f(); return;
    case 0x5059: yield* sub_6f29(); return;
    case 0x506f: yield* sub_6f3f(); return;
    case 0x4dbf: yield* sub_6c8f(); return;
    case 0x4e44: yield* sub_6d14(); return;
    case 0x4ec9: yield* sub_6d99(); return;
    case 0x4f4e: yield* sub_6e1e(); return;
        default:
        break;
    }
    if(seg == 0x0ca6)
        switch (ofs)
    {
    case 0x823: yield* sub_d283(); return;
    case 0x990: yield* sub_d3f0(); return;
    case 0x91e: yield* sub_d37e(); return;
    case 0x927: yield* sub_d387(); return;
    case 0x91f: yield* sub_d37f(); return;
    case 0x92f: yield* sub_d38f(); return;
    case 0x892: yield* sub_d2f2(); return;
    case 0x991: yield* sub_d3f1(); return;
    case 0x7f0: yield* sub_d250(); return;
    case 0x997: yield* sub_d3f7(); return;
    case 0x998: yield* sub_d3f8(); return;
    case 0x999: yield* sub_d3f9(); return;
    case 0xad0: yield* sub_d530(); return;
    case 0xc7f: yield* sub_d6df(); return;
    case 0xb3c: yield* sub_d59c(); return;
    case 0xc05: yield* sub_d665(); return;
    case 0xbfd: yield* sub_d65d(); return;
    case 0xc0d: yield* sub_d66d(); return;
    case 0xb33: yield* sub_d593(); return;
    case 0xc80: yield* sub_d6e0(); return;
    case 0xaa0: yield* sub_d500(); return;
    case 0xc86: yield* sub_d6e6(); return;
    case 0xc87: yield* sub_d6e7(); return;
    case 0xc88: yield* sub_d6e8(); return;
        default:
        break;
    }
    switch (seg*0x10000+ofs)
    {
    case 0x1eda3ae: yield* sub_c27e(); return;
    case 0xca60823: yield* sub_d283(); return;
    case 0xca60aa0: yield* sub_d500(); return;
    case 0xca60db0: yield* sub_d810(); return;
    case 0xca61087: yield* sub_dae7(); return;
    case 0xed90c34: yield* sub_f9c4(); return;
    case 0xed90def: yield* sub_fb7f(); return;
    case 0xed90e29: yield* sub_fbb9(); return;
    case 0xed910e1: yield* sub_fe71(); return;
    case 0x12230015: yield* sub_12245(); return;
        default:
        break;
    }
    assert(0);
}
function* sub_1ed0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[dx] = 0x1228;
        memory16set(cs, 0x01ff, r16[dx]);
        r8[ah] = 0x30;
        interrupt(0x21);
        bp = memoryPspGet16(ds, 0x0002);
        r16[bx] = memoryPspGet16(ds, 0x002c);
        ds = r16[dx];
        memory16set(ds, 0x007b, r16[ax]);
        memory16set(ds, 0x0079, es);
        memory16set(ds, 0x0075, r16[bx]);
        memory16set(ds, 0x008d, bp);
        yield* sub_1fff();
        di = memory16get(ds, 0x0073);
        es = memory16get(ds, 0x0073 + 2);
        r16[ax] = di;
        r16[bx] = r16[ax];
        r16[cx] = 0x7fff;
        flags.direction = false;
    case 0x1f04:
        repne_scasb_MemPsp_forward(r8[al]);
        if (r16[cx] == 0) {
            pc = 0x1f44;
            break;
        }
        r16[bx]++;
        if (memoryPspGet(es, di) != r8[al]) {
            pc = 0x1f04;
            break;
        }
        r8[ch] |= 0x80;
        r16[cx] = -r16[cx];
        memory16set(ds, 0x0073, r16[cx]);
        r16[cx] = 0x0002;
        r16[bx] <<= r8[cl];
        r16[bx] += 0x0010;
        r16[bx] &= 0xfff0;
        memory16set(ds, 0x0077, r16[bx]);
        r16[dx] = ss;
        bp -= r16[dx];
        di = memory16get(ds, 0x6b4c);
        if (di >= 0x0200) {
            pc = 0x1f3b;
            break;
        }
        di = 0x0200;
        memory16set(ds, 0x6b4c, di);
    case 0x1f3b:
        r8[cl] = 0x04;
        di >>= r8[cl];
        di++;
        if (bp >= di) {
            pc = 0x1f47;
            break;
        }
    case 0x1f44:
        pc = 0x20ba;
        break;
    case 0x1f47:
        r16[bx] = di;
        r16[bx] += r16[dx];
        memory16set(ds, 0x0085, r16[bx]);
        memory16set(ds, 0x0089, r16[bx]);
        r16[ax] = memory16get(ds, 0x0079);
        r16[bx] -= r16[ax];
        es = r16[ax];
        r8[ah] = 0x4a;
        push(di);
        interrupt(0x21);
        di = pop();
        di <<= r8[cl];
        flags.interrupts = false;
        ss = r16[dx];
        sp = di;
        memory16set(ds, 0x6b4c, di);
        flags.interrupts = true;
        r16[ax] = 0;
        es = memory16get(cs, 0x01ff);
        di = 0x6bba;
        r16[cx] = 0xa202;
        r16[cx] -= di;
        flags.direction = false;
        rep_stosb_data_forward();
        r8[ah] = 0x00;
        interrupt(0x1a);
        memory16set(ds, 0x007f, r16[dx]);
        memory16set(ds, 0x0081, r16[cx]);
        bp = 0;
        r16[ax] = 0x1227;
        ds = r16[ax];
        si = 0x0000;
        di = 0x000c;
        yield* sub_206f();
        ds = memory16get(cs, 0x01ff);
        memory[cs*16 + 0x01b1] = 0x72;
        memory[cs*16 + 0x01a0] = 0x00;
        push(memory16get(ds, 0x0071));
        push(memory16get(ds, 0x006f));
        push(memory16get(ds, 0x006d));
        push(memory16get(ds, 0x006b));
        push(memory16get(ds, 0x0069));
        yield* sub_20d3();
        push(r16[ax]);
        yield* sub_b78a();
        r16[ax] = 0x1227;
        ds = r16[ax];
        si = 0x000c;
        di = 0x000c;
        yield* sub_206f();
        ds = memory16get(cs, 0x01ff);
        yield* callIndirect(cs, memory16get(ds, 0x6984));
        yield* callIndirect(cs, memory16get(ds, 0x6986));
        yield* callIndirect(cs, memory16get(ds, 0x6988));
        ds = memory16get(cs, 0x01ff);
        yield* sub_2042();
        bp = sp;
        r8[ah] = 0x4c;
        r8[al] = memory[ss*16 + bp + 2];
        interrupt(0x21);
        r16[cx] = 0x000e;
        r16[dx] = 0x002d;
        pc = 0x20c0;
        break;
    case 0x20ba:
        r16[cx] = 0x001e;
        r16[dx] = 0x003b;
    case 0x20c0:
        ds = memory16get(cs, 0x01ff);
        yield* sub_20b2();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_1fe5();
        memory[ds*16 + r16[bx] + si] += r8[al];
        r16[ax] += memory16get(ds, r16[bx] + si + 85);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x20df;
            break;
        }
        yield* sub_ca53();
    case 0x20df:
        if (memory[ss*16 + bp + 4] != 0x01) {
            pc = 0x2126;
            break;
        }
        yield* sub_22e6();
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x2126;
            break;
        }
        r16[bx] = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        r16[ax] = memory16get(es, r16[bx] + 6);
        r16[dx] = memory16get(es, r16[bx] + 4);
        memory16set(ds, 0x6be4, r16[dx]);
        memory16set(ds, 0x6be6, r16[ax]);
        yield* sub_2152();
        yield* sub_9a77();
        yield* sub_28d7();
        yield* sub_2128();
        yield* sub_2439();
        yield* sub_9947();
        yield* sub_9c89();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_8ff0();
        sp++;
        sp++;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b78a();
        sp++;
        sp++;
    case 0x2126:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_1fc6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[ax] = 0x1227;
        ds = r16[ax];
        si = 0x000c;
        di = 0x000c;
        yield* sub_206f();
        ds = memory16get(cs, 0x01ff);
        yield* callIndirect(cs, memory16get(ds, 0x6984));
        yield* callIndirect(cs, memory16get(ds, 0x6986));
        yield* callIndirect(cs, memory16get(ds, 0x6988));
        ds = memory16get(cs, 0x01ff);
        yield* sub_2042();
        bp = sp;
        r8[ah] = 0x4c;
        r8[al] = memory[ss*16 + bp + 2];
        interrupt(0x21);
        r16[cx] = 0x000e;
        r16[dx] = 0x002d;
        pc = 0x20c0;
        break;
    case 0x20c0:
        ds = memory16get(cs, 0x01ff);
        yield* sub_20b2();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_1fe5();
        memory[ds*16 + r16[bx] + si] += r8[al];
        r16[ax] += memory16get(ds, r16[bx] + si + 85);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x20df;
            break;
        }
        yield* sub_ca53();
    case 0x20df:
        if (memory[ss*16 + bp + 4] != 0x01) {
            pc = 0x2126;
            break;
        }
        yield* sub_22e6();
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x2126;
            break;
        }
        r16[bx] = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        r16[ax] = memory16get(es, r16[bx] + 6);
        r16[dx] = memory16get(es, r16[bx] + 4);
        memory16set(ds, 0x6be4, r16[dx]);
        memory16set(ds, 0x6be6, r16[ax]);
        yield* sub_2152();
        yield* sub_9a77();
        yield* sub_28d7();
        yield* sub_2128();
        yield* sub_2439();
        yield* sub_9947();
        yield* sub_9c89();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_8ff0();
        sp++;
        sp++;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b78a();
        sp++;
        sp++;
    case 0x2126:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_1fe5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        ds = memory16get(cs, 0x01ff);
        yield* sub_2042();
        bp = sp;
        r8[ah] = 0x4c;
        r8[al] = memory[ss*16 + bp + 2];
        interrupt(0x21);
        r16[cx] = 0x000e;
        r16[dx] = 0x002d;
        pc = 0x20c0;
        break;
    case 0x20c0:
        ds = memory16get(cs, 0x01ff);
        yield* sub_20b2();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_1fe5();
        memory[ds*16 + r16[bx] + si] += r8[al];
        r16[ax] += memory16get(ds, r16[bx] + si + 85);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x20df;
            break;
        }
        yield* sub_ca53();
    case 0x20df:
        if (memory[ss*16 + bp + 4] != 0x01) {
            pc = 0x2126;
            break;
        }
        yield* sub_22e6();
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x2126;
            break;
        }
        r16[bx] = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        r16[ax] = memory16get(es, r16[bx] + 6);
        r16[dx] = memory16get(es, r16[bx] + 4);
        memory16set(ds, 0x6be4, r16[dx]);
        memory16set(ds, 0x6be6, r16[ax]);
        yield* sub_2152();
        yield* sub_9a77();
        yield* sub_28d7();
        yield* sub_2128();
        yield* sub_2439();
        yield* sub_9947();
        yield* sub_9c89();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_8ff0();
        sp++;
        sp++;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b78a();
        sp++;
        sp++;
    case 0x2126:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_1fff() {
    push(ds);
    r16[ax] = 0x3500;
    interrupt(0x21);
    memory16set(ds, 0x0059, r16[bx]);
    memory16set(ds, 0x005b, es);
    r16[ax] = 0x3504;
    interrupt(0x21);
    memory16set(ds, 0x005d, r16[bx]);
    memory16set(ds, 0x005f, es);
    r16[ax] = 0x3505;
    interrupt(0x21);
    memory16set(ds, 0x0061, r16[bx]);
    memory16set(ds, 0x0063, es);
    r16[ax] = 0x3506;
    interrupt(0x21);
    memory16set(ds, 0x0065, r16[bx]);
    memory16set(ds, 0x0067, es);
    r16[ax] = 0x2500;
    r16[dx] = cs;
    ds = r16[dx];
    r16[dx] = 0x0126;
    interrupt(0x21);
    ds = pop();
}
function* sub_2042() {
    push(ds);
    r16[ax] = 0x2500;
    r16[dx] = memory16get(ds, 0x0059);
    ds = memory16get(ds, 0x0059 + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    r16[ax] = 0x2504;
    r16[dx] = memory16get(ds, 0x005d);
    ds = memory16get(ds, 0x005d + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    r16[ax] = 0x2505;
    r16[dx] = memory16get(ds, 0x0061);
    ds = memory16get(ds, 0x0061 + 2);
    interrupt(0x21);
    ds = pop();
    push(ds);
    r16[ax] = 0x2506;
    r16[dx] = memory16get(ds, 0x0065);
    ds = memory16get(ds, 0x0065 + 2);
    interrupt(0x21);
    ds = pop();
}
function* sub_206f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
    case 0x206f:
        r8[ah] = 0xff;
        r16[dx] = di;
        r16[bx] = si;
    case 0x2075:
        if (r16[bx] == di) {
            pc = 0x208d;
            break;
        }
        if (memory[ds*16 + r16[bx]] == 0xff) {
            pc = 0x2088;
            break;
        }
        if (memory[ds*16 + r16[bx] + 1] > r8[ah]) {
            pc = 0x2088;
            break;
        }
        r8[ah] = memory[ds*16 + r16[bx] + 1];
        r16[dx] = r16[bx];
    case 0x2088:
        r16[bx] += 0x0006;
        pc = 0x2075;
        break;
    case 0x208d:
        if (r16[dx] == di)
            {
            assert(pop() == 0x7777);
            return;
        }
        r16[bx] = r16[dx];
        push(ds);
        es = pop();
        push(es);
        r8[tl] = memory[ds*16 + r16[bx]];
        memory[ds*16 + r16[bx]] = 0xff;
        ds = memory16get(cs, 0x01ff);
        if (r8[tl] == 0x00) {
            pc = 0x20aa;
            break;
        }
        push(cs);
        cs = memory16get(es, r16[bx] + 2 + 2);
        yield* callIndirect(memory16get(es, r16[bx] + 2 + 2), memory16get(es, r16[bx] + 2));
        assert(cs == 0x01ed);
        ds = pop();
        pc = 0x206f;
        break;
    case 0x20aa:
        yield* callIndirect(cs, memory16get(es, r16[bx] + 2));
        ds = pop();
        pc = 0x206f;
        break;
        return;
    } while (1);
}
function* sub_20b2() {
    r8[ah] = 0x40;
    r16[bx] = 0x0002;
    interrupt(0x21);
}
function* sub_20d3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x20df;
            break;
        }
        yield* sub_ca53();
    case 0x20df:
        if (memory[ss*16 + bp + 4] != 0x01) {
            pc = 0x2126;
            break;
        }
        yield* sub_22e6();
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x2126;
            break;
        }
        r16[bx] = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        r16[ax] = memory16get(es, r16[bx] + 6);
        r16[dx] = memory16get(es, r16[bx] + 4);
        memory16set(ds, 0x6be4, r16[dx]);
        memory16set(ds, 0x6be6, r16[ax]);
        yield* sub_2152();
        yield* sub_9a77();
        yield* sub_28d7();
        yield* sub_2128();
        yield* sub_2439();
        yield* sub_9947();
        yield* sub_9c89();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_8ff0();
        sp++;
        sp++;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b78a();
        sp++;
        sp++;
    case 0x2126:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_2128() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x2134;
            break;
        }
        yield* sub_ca53();
    case 0x2134:
        memory[ds*16 + 0x79b2] = bumpyStartupLevel;
        yield* sub_722e();
        yield* sub_8cb3();
    case 0x213f:
        yield* sub_2ae8();
        if (memory[ds*16 + 0x9d30] != 0x00) {
            pc = 0x213f;
            break;
        }
        if (memory[ds*16 + 0x856d] != 0x00) {
            pc = 0x213f;
            break;
        }
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_2152() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x215e;
            break;
        }
        yield* sub_ca53();
    case 0x215e:
        r16[ax] = 0x06a9;
        push(r16[ax]);
        r16[ax] = 0x0698;
        push(r16[ax]);
        yield* sub_91bf();
        sp += 0x0004;
        push(ds);
        r16[ax] = 0x6fac;
        push(r16[ax]);
        yield* sub_9a7d();
        sp += 0x0004;
        yield* sub_9bae();
        yield* sub_985a();
        yield* sub_9402();
        yield* sub_b14c();
        push(ds);
        r16[ax] = 0x4cd0;
        push(r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        yield* sub_9433();
        sp += 0x0006;
        yield* sub_9aa7();
        yield* sub_b674();
        r8[al] = 0x02;
        push(r16[ax]);
        yield* sub_9a8d();
        sp++;
        sp++;
        yield* sub_b6c1();
        r16[ax] = 0x00c7;
        push(r16[ax]);
        r16[ax] = 0x013f;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(r16[ax]);
        yield* sub_b6f1();
        sp += 0x0008;
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b6e4();
        sp++;
        sp++;
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x000e;
        push(r16[ax]);
        yield* sub_b695();
        sp += 0x0004;
        push(ds);
        r16[ax] = 0x0090;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        r8[al] = 0x00;
        memory[ds*16 + 0x6bec] = r8[al];
        r8[ah] = 0x00;
        memory16set(ds, 0x7310, r16[ax]);
        memory[ds*16 + 0x7312] = r8[al];
        memory[ds*16 + 0x6bc9] = r8[al];
        memory[ds*16 + 0x7314] = r8[al];
        r8[al] = 0x00;
        memory[ds*16 + 0x731b] = r8[al];
        memory[ds*16 + 0x6bba] = r8[al];
        memory[ds*16 + 0x75ed] = r8[al];
        memory[ds*16 + 0x75ec] = r8[al];
        memory[ds*16 + 0x75eb] = r8[al];
        memory[ds*16 + 0x75ce] = r8[al];
        r8[al] = 0x00;
        memory[ds*16 + 0x6c34] = r8[al];
        memory[ds*16 + 0x6bc8] = r8[al];
        r8[ah] = 0x00;
        memory16set(ds, 0x6bc2, r16[ax]);
        memory16set(ds, 0x6bc0, r16[ax]);
        memory16set(ds, 0x6c40, r16[ax]);
        memory16set(ds, 0x6c3e, r16[ax]);
        memory16set(ds, 0x75c8, r16[ax]);
        memory[ds*16 + 0x6bc5] = 0x01;
        memory[ds*16 + 0x6bc4] = 0x14;
        r8[al] = 0x00;
        memory[ds*16 + 0x6faa] = r8[al];
        memory[ds*16 + 0x75e2] = r8[al];
        r8[al] = 0x00;
        memory[ds*16 + 0x75cf] = r8[al];
        memory[ds*16 + 0x75c6] = r8[al];
        memory[ds*16 + 0x6bdf] = r8[al];
        memory[ds*16 + 0x6bc6] = r8[al];
        r16[ax] = 0;
        memory16set(ds, 0x6bf8, r16[ax]);
        memory16set(ds, 0x6bbe, r16[ax]);
        memory16set(ds, 0x6bbc, r16[ax]);
        r16[ax] = 0;
        memory16set(ds, 0x6bd6, r16[ax]);
        memory16set(ds, 0x6bce, r16[ax]);
        r16[ax] = 0;
        memory16set(ds, 0x6bdc, r16[ax]);
        memory16set(ds, 0x6bd0, r16[ax]);
        r16[ax] = 0;
        memory16set(ds, 0x6bda, r16[ax]);
        memory16set(ds, 0x6bd8, r16[ax]);
        r8[al] = 0x01;
        memory[ds*16 + 0x6bf6] = r8[al];
        memory[ds*16 + 0x6c26] = r8[al];
        r16[ax] = 0;
        memory16set(ds, 0x6be2, r16[ax]);
        memory16set(ds, 0x6be0, r16[ax]);
        memory16set(ds, 0x7316, 0x006c);
        r8[al] = 0x00;
        memory[ds*16 + 0x6bbb] = r8[al];
        memory[ds*16 + 0x6bde] = r8[al];
        memory[ds*16 + 0x6bc7] = 0x09;
        memory[ds*16 + 0x75ea] = 0x00;
        r16[ax] = memory16get(ds, 0x7310);
        r16[dx] = 0x032c;
        imul16(r16[dx]);
        r16[dx] = memory16get(ds, 0x6bd4);
        r16[bx] = memory16get(ds, 0x6bd2);
        r16[bx] += r16[ax];
        memory16set(ds, 0x6bca, r16[bx]);
        memory16set(ds, 0x6bcc, r16[dx]);
        r16[ax] = memory16get(ds, 0x7310);
        r16[dx] = 0x00c2;
        imul16(r16[dx]);
        r16[dx] = memory16get(ds, 0x6bf4);
        r16[bx] = memory16get(ds, 0x6bf2);
        r16[bx] += r16[ax];
        memory16set(ds, 0x75d0, r16[bx]);
        memory16set(ds, 0x75d2, r16[dx]);
        yield* sub_22ba();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_22ba() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x22c6;
            break;
        }
        yield* sub_ca53();
    case 0x22c6:
        yield* sub_b2f4();
        r16[ax] = 0x00c7;
        push(r16[ax]);
        r16[ax] = 0x013f;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        push(r16[ax]);
        yield* sub_b2d6();
        sp += 0x0008;
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_22e6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x22f4;
            break;
        }
        yield* sub_ca53();
    case 0x22f4:
        memory[ss*16 + bp - 1] = 0x00;
        r8[al] = 0x01;
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0x07c3;
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_9f5e();
        sp += 0x0006;
        memory16set(ds, 0x75da, r16[ax]);
        memory16set(ds, 0x75dc, r16[dx]);
        r8[al] = 0x01;
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0x0898;
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_9f5e();
        sp += 0x0006;
        memory16set(ds, 0x6c2c, r16[ax]);
        memory16set(ds, 0x6c2e, r16[dx]);
        r8[al] = 0x01;
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0x7806;
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_9f5e();
        sp += 0x0006;
        memory16set(ds, 0x6fa6, r16[ax]);
        memory16set(ds, 0x6fa8, r16[dx]);
        r16[ax] |= r16[dx];
        if (r16[ax]) {
            pc = 0x2345;
            break;
        }
        memory[ss*16 + bp - 1] = 0xff;
    case 0x2345:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x236e;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        r16[ax] = 0x0001;
        r16[dx] = 0x5c70;
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_9f5e();
        sp += 0x0006;
        memory16set(ds, 0xa0c6, r16[ax]);
        memory16set(ds, 0xa0c8, r16[dx]);
        r16[ax] |= r16[dx];
        if (r16[ax]) {
            pc = 0x236e;
            break;
        }
        memory[ss*16 + bp - 1] = 0xff;
    case 0x236e:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x23a8;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0x2f96;
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_9f5e();
        sp += 0x0006;
        memory16set(ds, 0x6be8, r16[ax]);
        memory16set(ds, 0x6bea, r16[dx]);
        r16[ax] |= r16[dx];
        if (r16[ax]) {
            pc = 0x2398;
            break;
        }
        memory[ss*16 + bp - 1] = 0xff;
        pc = 0x23a8;
        break;
    case 0x2398:
        r16[ax] = memory16get(ds, 0x6bea);
        r16[dx] = memory16get(ds, 0x6be8);
        r16[dx]++;
        r16[dx]++;
        memory16set(ds, 0x6bd2, r16[dx]);
        memory16set(ds, 0x6bd4, r16[ax]);
    case 0x23a8:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x23d0;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0x0500;
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_9f5e();
        sp += 0x0006;
        memory16set(ds, 0x6c30, r16[ax]);
        memory16set(ds, 0x6c32, r16[dx]);
        r16[ax] |= r16[dx];
        if (r16[ax]) {
            pc = 0x23d0;
            break;
        }
        memory[ss*16 + bp - 1] = 0xff;
    case 0x23d0:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x23f8;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0x7d63;
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_9f5e();
        sp += 0x0006;
        memory16set(ds, 0x7926, r16[ax]);
        memory16set(ds, 0x7928, r16[dx]);
        r16[ax] |= r16[dx];
        if (r16[ax]) {
            pc = 0x23f8;
            break;
        }
        memory[ss*16 + bp - 1] = 0xff;
    case 0x23f8:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x2432;
            break;
        }
        r8[al] = 0x01;
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0x0b60;
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_9f5e();
        sp += 0x0006;
        memory16set(ds, 0x75de, r16[ax]);
        memory16set(ds, 0x75e0, r16[dx]);
        r16[ax] |= r16[dx];
        if (r16[ax]) {
            pc = 0x2422;
            break;
        }
        memory[ss*16 + bp - 1] = 0xff;
        pc = 0x2432;
        break;
    case 0x2422:
        r16[ax] = memory16get(ds, 0x75e0);
        r16[dx] = memory16get(ds, 0x75de);
        r16[dx]++;
        r16[dx]++;
        memory16set(ds, 0x6bf2, r16[dx]);
        memory16set(ds, 0x6bf4, r16[ax]);
    case 0x2432:
        r8[al] = memory[ss*16 + bp - 1];
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_2439() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x2445;
            break;
        }
        yield* sub_ca53();
    case 0x2445:
        push(memory16get(ds, 0x75e0));
        push(memory16get(ds, 0x75de));
        yield* sub_9f6e();
        sp += 0x0004;
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9f6e();
        sp += 0x0004;
        push(memory16get(ds, 0x6c32));
        push(memory16get(ds, 0x6c30));
        yield* sub_9f6e();
        sp += 0x0004;
        push(memory16get(ds, 0x6bea));
        push(memory16get(ds, 0x6be8));
        yield* sub_9f6e();
        sp += 0x0004;
        push(memory16get(ds, 0xa0c8));
        push(memory16get(ds, 0xa0c6));
        yield* sub_9f6e();
        sp += 0x0004;
        push(memory16get(ds, 0x6fa8));
        push(memory16get(ds, 0x6fa6));
        yield* sub_9f6e();
        sp += 0x0004;
        push(memory16get(ds, 0x6c2e));
        push(memory16get(ds, 0x6c2c));
        yield* sub_9f6e();
        sp += 0x0004;
        push(memory16get(ds, 0x75dc));
        push(memory16get(ds, 0x75da));
        yield* sub_9f6e();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_24b7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sync();
        return;
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x24c8;
            break;
        }
        yield* sub_ca53();
        pc = 0x24c8;
        break;
    case 0x24c5:
        yield* sub_b734();
    case 0x24c8:
        r8[al] = memory[ss*16 + bp + 4];
        memory[ss*16 + bp + 4] -= 1;
        if (r8[al]) {
            pc = 0x24c5;
            break;
        }
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_24d4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x24e0;
            break;
        }
        yield* sub_ca53();
    case 0x24e0:
        r8[al] = memory[ds*16 + 0x75cf];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x24f9;
            break;
        }
        r16[bx] = memory16get(ds, 0x6bca);
        es = memory16get(ds, 0x6bca + 2);
        if (memory16get(es, r16[bx] + 28) == 0x0000) {
            pc = 0x24f9;
            break;
        }
        yield* sub_250b();
        pc = 0x24fe;
        break;
    case 0x24f9:
        memory[ds*16 + 0x75cf] = 0x01;
    case 0x24fe:
        push(ds);
        r16[ax] = 0x0578;
        push(r16[ax]);
        yield* sub_27a1();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_250b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x251c;
            break;
        }
        yield* sub_ca53();
    case 0x251c:
        memory[ss*16 + bp - 1] = 0x00;
        pc = 0x255c;
        break;
    case 0x2522:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = memory16get(ds, 0x6bca);
        es = memory16get(ds, 0x6bca + 2);
        r16[bx] += r16[ax];
        si = memory16get(es, r16[bx]);
        r16[ax] = si;
        r16[ax] &= 0x00ff;
        r8[cl] = 0x08;
        r16[ax] <<= r8[cl];
        memory16set(ss, bp - 4, r16[ax]);
        r16[ax] = si;
        r16[ax] &= 0xff00;
        r16[ax] >>= r8[cl];
        di = r16[ax];
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[dx] = memory16get(ss, bp - 4);
        r16[dx] |= di;
        r16[bx] = r16[ax];
        memory16set(ds, r16[bx] + 1400, r16[dx]);
        memory[ss*16 + bp - 1] += 1;
    case 0x255c:
        if (memory[ss*16 + bp - 1] < 0x10) {
            pc = 0x2522;
            break;
        }
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_26c0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x26cc;
            break;
        }
        yield* sub_ca53();
    case 0x26cc:
        push(memory16get(ss, bp + 10));
        push(memory16get(ss, bp + 8));
        yield* sub_b707();
        sp += 0x0004;
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_b6d4();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_26e6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000c;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x26f5;
            break;
        }
        yield* sub_ca53();
    case 0x26f5:
        if (memory[ss*16 + bp + 8] <= 0x07) {
            pc = 0x26fe;
            break;
        }
        pc = 0x278c;
        break;
    case 0x26fe:
        memory[ss*16 + bp - 11] = 0x00;
        pc = 0x2717;
        break;
    case 0x2704:
        r8[al] = memory[ss*16 + bp - 11];
        memory[ss*16 + bp - 11] += 1;
        r8[ah] = 0x00;
        r16[dx] = bp - 0xa;
        r16[ax] += r16[dx];
        r16[bx] = r16[ax];
        memory[ss*16 + r16[bx]] = 0x20;
    case 0x2717:
        r8[al] = memory[ss*16 + bp - 11];
        if (r8[al] <= memory[ss*16 + bp + 8]) {
            pc = 0x2704;
            break;
        }
        r8[al] = memory[ss*16 + bp + 8];
        r8[ah] = 0x00;
        r16[dx] = bp - 0xa;
        r16[ax] += r16[dx];
        r16[bx] = r16[ax];
        memory[ss*16 + r16[bx]] = 0x00;
        pc = 0x2776;
        break;
    case 0x2731:
        r8[al] = memory[ss*16 + bp + 4];
        memory[ss*16 + bp - 1] = r8[al];
        r16[ax] = 0;
        r16[dx] = 0x000a;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_c7be();
        memory16set(ss, bp + 4, r16[ax]);
        r16[bx] = r16[ax];
        memory16set(ss, bp + 6, r16[dx]);
        r16[cx] = r16[dx];
        r16[dx] = 0;
        r16[ax] = 0x000a;
        yield* sub_c8e4();
        r8[dl] = memory[ss*16 + bp - 1];
        r8[dl] -= r8[al];
        memory[ss*16 + bp - 1] = r8[dl];
        r8[al] = memory[ss*16 + bp + 8];
        r8[ah] = 0x00;
        r16[dx] = bp - 0xa;
        r16[ax] += r16[dx];
        r8[dl] = memory[ss*16 + bp - 1];
        r8[dl] += 0x30;
        r16[bx] = r16[ax];
        memory[ss*16 + r16[bx]] = r8[dl];
    case 0x2776:
        r8[al] = memory[ss*16 + bp + 8];
        memory[ss*16 + bp + 8] -= 1;
        if (r8[al]) {
            pc = 0x2731;
            break;
        }
        push(memory16get(ss, bp + 12));
        push(memory16get(ss, bp + 10));
        push(ss);
        r16[ax] = bp - 0xa;
        pc = 0x2796;
        break;
    case 0x278c:
        push(memory16get(ss, bp + 12));
        push(memory16get(ss, bp + 10));
        push(ds);
        r16[ax] = 0x062e;
    case 0x2796:
        push(r16[ax]);
        yield* sub_26c0();
        sp += 0x0008;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_27a1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000a;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x27b1;
            break;
        }
        yield* sub_ca53();
    case 0x27b1:
        memory16set(ss, bp - 4, 0x6c42);
        memory16set(ss, bp - 2, ds);
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x27f6;
            break;
        }
        memory16set(ds, 0x9b96, 0x6c42);
        memory16set(ds, 0x9b98, ds);
        memory[ss*16 + bp - 6] = 0x00;
        pc = 0x27ed;
        break;
    case 0x27d0:
        r8[al] = memory[ss*16 + bp - 6];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 6];
        r8[ah] = 0x00;
        si = r16[ax];
        r8[al] = memory[ds*16 + si + 1806];
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 6] += 1;
    case 0x27ed:
        if (memory[ss*16 + bp - 6] < 0x10) {
            pc = 0x27d0;
            break;
        }
        pc = 0x28b9;
        break;
    case 0x27f6:
        memory[ss*16 + bp - 5] = 0x00;
        pc = 0x28b0;
        break;
    case 0x27fd:
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        r16[bx] += r16[ax];
        r16[ax] = memory16get(es, r16[bx]);
        r8[cl] = 0x08;
        r16[ax] >>= r8[cl];
        memory[ss*16 + bp - 7] = r8[al];
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] += r16[ax];
        r16[ax] = memory16get(es, r16[bx]);
        r8[dl] = memory[ds*16 + 0x75eb];
        r8[dh] = 0x00;
        r16[dx] <<= r8[cl];
        r16[ax] -= r16[dx];
        r8[cl] = 0x04;
        r16[ax] >>= r8[cl];
        memory[ss*16 + bp - 8] = r8[al];
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[dl] = memory[ds*16 + 0x75eb];
        r8[cl] = 0x08;
        r8[dl] <<= r8[cl];
        r8[bl] = memory[ds*16 + 0x75ec];
        r8[cl] = 0x04;
        r8[bl] <<= r8[cl];
        r8[dl] += r8[bl];
        r8[al] -= r8[dl];
        memory[ss*16 + bp - 9] = r8[al];
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[dx] = 0x0003;
        imul16(r16[dx]);
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 7];
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[al] <<= 1;
        memory[es*16 + r16[bx] + 51] = r8[al];
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[dx] = 0x0003;
        imul16(r16[dx]);
        r16[bx] = memory16get(ss, bp - 4);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 8];
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[al] <<= 1;
        memory[es*16 + r16[bx] + 52] = r8[al];
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[dx] = 0x0003;
        imul16(r16[dx]);
        r16[bx] = memory16get(ss, bp - 4);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 9];
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[al] <<= 1;
        memory[es*16 + r16[bx] + 53] = r8[al];
        memory[ss*16 + bp - 5] += 1;
    case 0x28b0:
        if (memory[ss*16 + bp - 5] >= 0x10) {
            pc = 0x28b9;
            break;
        }
        pc = 0x27fd;
        break;
    case 0x28b9:
        r16[ax] = 0;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x6c42;
        push(r16[ax]);
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        yield* sub_b734();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_28d7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x28e4;
            break;
        }
        yield* sub_ca53();
    case 0x28e4:
        r16[ax] = 0x0004;
        push(r16[ax]);
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x00c0));
        push(memory16get(ds, 0x00be));
        push(memory16get(ds, 0x75dc));
        push(memory16get(ds, 0x75da));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        push(memory16get(ds, 0x75dc));
        push(memory16get(ds, 0x75da));
        yield* sub_b6a5();
        sp += 0x0004;
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0009;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x00f2));
        push(memory16get(ds, 0x00f0));
        push(memory16get(ds, 0x6c2e));
        push(memory16get(ds, 0x6c2c));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        push(memory16get(ds, 0x6c2e));
        push(memory16get(ds, 0x6c2c));
        yield* sub_b2a8();
        sp += 0x0004;
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_2960() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x2970;
            break;
        }
        yield* sub_ca53();
    case 0x2970:
        r16[ax] = memory16get(ds, 0x6fa8);
        r16[dx] = memory16get(ds, 0x6fa6);
        r16[dx] += 0x0006;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0018);
        r16[ax] = memory16get(ss, bp + 10);
        memory16set(es, r16[bx] + 14, r16[ax]);
        memory16set(es, r16[bx] + 28, 0x0006);
        memory16set(es, r16[bx] + 30, 0x0001);
        if (memory16get(ss, bp + 8) != 0x0018) {
            pc = 0x29b3;
            break;
        }
        memory16set(es, r16[bx] + 32, 0x0001);
        pc = 0x29bd;
        break;
    case 0x29b3:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 32, 0x0002);
    case 0x29bd:
        if (memory[ss*16 + bp + 4] <= 0xf0) {
            pc = 0x29d1;
            break;
        }
        memory[ss*16 + bp - 2] = 0x01;
        r8[al] = 0xfb;
        r8[al] -= memory[ss*16 + bp + 4];
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x2a4a;
        break;
    case 0x29d1:
        memory[ss*16 + bp - 2] = 0x00;
        memory[ss*16 + bp - 1] = 0x01;
        pc = 0x2a4a;
        break;
    case 0x29db:
        r16[ax] = memory16get(ss, bp + 6);
        r16[dx] = 0x0027;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0x6bca);
        es = memory16get(ds, 0x6bca + 2);
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] = sar16(r16[ax], 1);
        r16[dx] = 0x0003;
        imul16(r16[dx]);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 32];
        r8[al] += 0xff;
        memory[ss*16 + bp + 4] = r8[al];
        r8[ah] = 0x00;
        r16[bx] = 0x0014;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        idiv16(r16[bx]);
        r16[ax] <<= 1;
        si = r16[ax];
        r16[dx] = 0x000a;
        imul16(r16[dx]);
        r8[dl] = memory[ss*16 + bp + 4];
        r8[dh] = 0x00;
        r16[dx] -= r16[ax];
        di = r16[dx];
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 6, di);
        memory16set(es, r16[bx] + 8, si);
        r16[ax] = memory16get(ss, bp + 6);
        memory16set(es, r16[bx] + 20, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        memory16set(es, r16[bx] + 22, r16[ax]);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f8c();
        sp += 0x0004;
        memory[ss*16 + bp - 2] += 1;
    case 0x2a4a:
        r8[al] = memory[ss*16 + bp - 2];
        if (r8[al] < memory[ss*16 + bp - 1]) {
            pc = 0x29db;
            break;
        }
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_2a58() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x2a64;
            break;
        }
        yield* sub_ca53();
    case 0x2a64:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        r16[ax] = memory16get(ss, bp + 8);
        memory16set(es, r16[bx] + 14, r16[ax]);
        r16[ax] = memory16get(ss, bp + 4);
        memory16set(es, r16[bx] + 20, r16[ax]);
        r16[ax] = memory16get(ss, bp + 6);
        memory16set(es, r16[bx] + 22, r16[ax]);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0001);
        if (memory16get(ss, bp + 6) != 0x0018) {
            pc = 0x2a97;
            break;
        }
        memory16set(es, r16[bx] + 32, 0x0001);
        pc = 0x2aa1;
        break;
    case 0x2a97:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 32, 0x0002);
    case 0x2aa1:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory[es*16 + r16[bx] + 34] = 0x00;
        memory[es*16 + r16[bx] + 35] = 0x00;
        memory[es*16 + r16[bx] + 36] = 0x00;
        memory[es*16 + r16[bx] + 37] = 0x00;
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9a1a();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_2ac9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x2ad5;
            break;
        }
        yield* sub_ca53();
    case 0x2ad5:
        yield* sub_5180();
        yield* sub_4948();
        yield* sub_50ae();
        r8[al] = 0x00;
        memory[ds*16 + 0x9d30] = r8[al];
        memory[ds*16 + 0x856d] = r8[al];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_2ae8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x2af6;
            break;
        }
        yield* sub_ca53();
    case 0x2af6:
        yield* sub_5295();
        yield* sub_4dc8();
    case 0x2afc:
        memory[ds*16 + 0x928d] = 0x00;
        memory[ds*16 + 0x791a] = 0x05;
        r8[al] = 0x00;
        memory[ds*16 + 0x79b5] = r8[al];
        r8[ah] = 0x00;
        memory16set(ds, 0xa0d4, r16[ax]);
        memory16set(ds, 0xa0d6, 0x0000);
        pc = 0x2b26;
        break;
    case 0x2b18:
        if (memory[ss*16 + bp - 1] != 0x01) {
            pc = 0x2b23;
            break;
        }
        yield* sub_7551();
        pc = 0x2b26;
        break;
    case 0x2b23:
        yield* sub_2e4a();
    case 0x2b26:
        yield* sub_5475();
        memory[ss*16 + bp - 1] = r8[al];
        if (r8[al]) {
            pc = 0x2b18;
            break;
        }
        pc = 0x2c5a;
        break;
    case 0x2b33:
        yield* sub_5722();
        if (memory[ds*16 + 0x928d] != 0xff) {
            pc = 0x2b42;
            break;
        }
        yield* sub_30bb();
        pc = 0x2afc;
        break;
    case 0x2b42:
        r8[al] = memory[ds*16 + 0x854e];
        r8[ah] = 0x00;
        r16[ax]--;
        memory16set(ds, 0x7310, r16[ax]);
        yield* sub_5337();
        yield* sub_2ac9();
        r8[al] = memory[ds*16 + 0x8562];
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
        r16[ax] = 0;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_7051();
        sp += 0x0004;
        yield* sub_3b82();
        yield* sub_3bba();
        yield* sub_24d4();
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        r8[al] = 0x01;
        push(r16[ax]);
        yield* sub_24b7();
        sp++;
        sp++;
        yield* sub_515f();
        yield* sub_3343();
        yield* sub_6a1e();
        yield* sub_325c();
        yield* sub_3282();
        yield* sub_3aa7();
        yield* sub_3b11();
        yield* sub_325c();
        yield* sub_3282();
        yield* sub_3871();
        yield* sub_38b4();
        yield* sub_3343();
        yield* sub_6a1e();
        pc = 0x2c19;
        break;
    case 0x2baa:
        bumpyScene = "game";
        yield* sub_b281();
        memory[ds*16 + 0x79b3] = r8[al];
        yield* sub_325c();
        yield* sub_3282();
        yield* sub_32af();
        yield* sub_6ae4();
        yield* sub_3343();
        yield* sub_6a1e();
        yield* sub_33b4();
        yield* sub_3471();
        yield* sub_3871();
        yield* sub_38b4();
        yield* sub_38f0();
        yield* sub_352e();
        yield* sub_3697();
        yield* sub_6f55();
        yield* sub_6f90();
        yield* sub_3937();
        yield* sub_39fb();
        yield* sub_3aa7();
        yield* sub_3b11();
        yield* sub_3b82();
        yield* sub_3bba();
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        yield* sub_3219();
        yield* sub_816c();
        yield* sub_3bf6();
        yield* sub_6b69();
        yield* sub_6fcb();
        yield* sub_420a();
        r8[al] = 0x19;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x2c19;
            break;
        }
        yield* sub_68a7();
    case 0x2c19:
        if (memory[ds*16 + 0x928d] != 0x00) {
            pc = 0x2c31;
            break;
        }
        if (memory[ds*16 + 0x856d] != 0x00) {
            pc = 0x2c31;
            break;
        }
        if (memory[ds*16 + 0x9d30] != 0x00) {
            pc = 0x2c31;
            break;
        }
        pc = 0x2baa;
        break;
    case 0x2c31:
        if (memory[ds*16 + 0x928d] != 0xff) {
            pc = 0x2c40;
            break;
        }
        yield* sub_30bb();
        yield* sub_7551();
        pc = 0x2c5d;
        break;
    case 0x2c40:
        yield* sub_5d5a();
        if (!r8[al]) {
            pc = 0x2c5d;
            break;
        }
        memory[ds*16 + 0x79b2] += 1;
        if (memory[ds*16 + 0x79b2] != 0x0a) {
            pc = 0x2c57;
            break;
        }
        yield* sub_5da4();
        pc = 0x2c5d;
        break;
    case 0x2c57:
        yield* sub_2c6d();
    case 0x2c5a:
        yield* sub_4be4();
    case 0x2c5d:
        r8[al] = memory[ds*16 + 0x928d];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x2c69;
            break;
        }
        pc = 0x2b33;
        break;
    case 0x2c69:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_2c6d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000e;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x2c7e;
            break;
        }
        yield* sub_ca53();
    case 0x2c7e:
        push(ss);
        r16[ax] = bp - 0x4;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x119e;
        push(r16[ax]);
        r16[cx] = 0x0004;
        yield* sub_c8c5();
        push(ds);
        r16[ax] = 0x0928;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(ds, 0x857e, r16[dx]);
        memory16set(ds, 0x8580, r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        r16[dx] = 0x0063;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ds, 0x8580));
        push(memory16get(ds, 0x857e));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x2d1a;
            break;
        }
        r16[ax] = memory16get(ds, 0x8580);
        r16[dx] = memory16get(ds, 0x857e);
        memory16set(ds, 0x9b96, r16[dx]);
        memory16set(ds, 0x9b98, r16[ax]);
        memory[ss*16 + bp - 13] = 0x00;
        pc = 0x2d14;
        break;
    case 0x2cf7:
        r8[al] = memory[ss*16 + bp - 13];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 13];
        r8[ah] = 0x00;
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 1822];
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 13] += 1;
    case 0x2d14:
        if (memory[ss*16 + bp - 13] < 0x10) {
            pc = 0x2cf7;
            break;
        }
    case 0x2d1a:
        yield* sub_5337();
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x8580));
        push(memory16get(ds, 0x857e));
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        yield* sub_b734();
        memory[ss*16 + bp - 9] = 0x04;
        memory[ss*16 + bp - 10] = 0x05;
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = memory16get(ss, bp - 4);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r8[al] = memory[ss*16 + bp - 10];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory[ss*16 + bp - 12] = 0x00;
        pc = 0x2da4;
        break;
    case 0x2d64:
        r8[al] = memory[ss*16 + bp - 12];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 11] = r8[al];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r8[ah] = 0x00;
        r16[ax] += 0x0175;
        memory16set(es, r16[bx] + 4, r16[ax]);
        r8[al] = memory[ss*16 + bp - 9];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        memory16set(es, r16[bx], r16[ax]);
        if (memory[ss*16 + bp - 11] == 0x20) {
            pc = 0x2d9e;
            break;
        }
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x2d9e:
        memory[ss*16 + bp - 9] += 1;
        memory[ss*16 + bp - 12] += 1;
    case 0x2da4:
        if (memory[ss*16 + bp - 12] < 0x0d) {
            pc = 0x2d64;
            break;
        }
        memory[ss*16 + bp - 9] = 0x07;
        memory[ss*16 + bp - 10] = 0x07;
        r8[al] = memory[ds*16 + 0x79b2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 4950);
        r16[dx] = memory16get(ds, r16[bx] + 4948);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r8[al] = memory[ss*16 + bp - 10];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory[ss*16 + bp - 12] = 0x00;
        pc = 0x2e1c;
        break;
    case 0x2de2:
        r8[al] = memory[ss*16 + bp - 12];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 11] = r8[al];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r8[ah] = 0x00;
        r16[ax] += 0x0175;
        memory16set(es, r16[bx] + 4, r16[ax]);
        r8[al] = memory[ss*16 + bp - 9];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        memory16set(es, r16[bx], r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        memory[ss*16 + bp - 9] += 1;
        memory[ss*16 + bp - 12] += 1;
    case 0x2e1c:
        if (memory[ss*16 + bp - 12] < 0x06) {
            pc = 0x2de2;
            break;
        }
    case 0x2e22:
        yield* sync();
        r8[al] = 0x00;
        push(r16[ax]);
        yield* sub_9472();
        sp++;
        sp++;
        cbw();
        if (!(r16[ax] & 0x0010)) {
            pc = 0x2e22;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        push(ds);
        r16[ax] = 0x0090;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_2e4a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0016;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x2e5b;
            break;
        }
        yield* sub_ca53();
    case 0x2e5b:
        push(ss);
        r16[ax] = bp - 0x4;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x11a2;
        push(r16[ax]);
        r16[cx] = 0x0004;
        yield* sub_c8c5();
        push(ss);
        r16[ax] = bp - 0x8;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x11a6;
        push(r16[ax]);
        r16[cx] = 0x0004;
        yield* sub_c8c5();
        push(ss);
        r16[ax] = bp - 0xc;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x11aa;
        push(r16[ax]);
        r16[cx] = 0x0004;
        yield* sub_c8c5();
        push(ds);
        r16[ax] = 0x0928;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(ds, 0x857e, r16[dx]);
        memory16set(ds, 0x8580, r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        r16[dx] = 0x0063;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ds, 0x8580));
        push(memory16get(ds, 0x857e));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x2f17;
            break;
        }
        r16[ax] = memory16get(ds, 0x8580);
        r16[dx] = memory16get(ds, 0x857e);
        memory16set(ds, 0x9b96, r16[dx]);
        memory16set(ds, 0x9b98, r16[ax]);
        memory[ss*16 + bp - 22] = 0x00;
        pc = 0x2f11;
        break;
    case 0x2ef4:
        r8[al] = memory[ss*16 + bp - 22];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 22];
        r8[ah] = 0x00;
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 1822];
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 22] += 1;
    case 0x2f11:
        if (memory[ss*16 + bp - 22] < 0x10) {
            pc = 0x2ef4;
            break;
        }
    case 0x2f17:
        yield* sub_5337();
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x8580));
        push(memory16get(ds, 0x857e));
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        yield* sub_b734();
        memory[ss*16 + bp - 17] = 0x00;
        memory[ss*16 + bp - 18] = 0x01;
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = memory16get(ss, bp - 4);
        memory16set(ss, bp - 16, r16[dx]);
        memory16set(ss, bp - 14, r16[ax]);
        r8[al] = memory[ss*16 + bp - 18];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory[ss*16 + bp - 20] = 0x00;
        pc = 0x2fa1;
        break;
    case 0x2f61:
        r8[al] = memory[ss*16 + bp - 20];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 16);
        es = memory16get(ss, bp - 16 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 19] = r8[al];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r8[ah] = 0x00;
        r16[ax] += 0x0175;
        memory16set(es, r16[bx] + 4, r16[ax]);
        r8[al] = memory[ss*16 + bp - 17];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        memory16set(es, r16[bx], r16[ax]);
        if (memory[ss*16 + bp - 19] == 0x20) {
            pc = 0x2f9b;
            break;
        }
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x2f9b:
        memory[ss*16 + bp - 17] += 1;
        memory[ss*16 + bp - 20] += 1;
    case 0x2fa1:
        if (memory[ss*16 + bp - 20] < 0x13) {
            pc = 0x2f61;
            break;
        }
        memory[ss*16 + bp - 17] = 0x07;
        memory[ss*16 + bp - 18] = 0x0a;
        r8[al] = memory[ss*16 + bp - 18];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory[ss*16 + bp - 20] = 0x00;
        pc = 0x2ff7;
        break;
    case 0x2fc6:
        memory[ss*16 + bp - 19] = 0x41;
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r8[al] = memory[ss*16 + bp - 19];
        r8[ah] = 0x00;
        r16[ax] += 0x0175;
        memory16set(es, r16[bx] + 4, r16[ax]);
        r8[al] = memory[ss*16 + bp - 17];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        memory16set(es, r16[bx], r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        memory[ss*16 + bp - 17] += 1;
        memory[ss*16 + bp - 20] += 1;
    case 0x2ff7:
        if (memory[ss*16 + bp - 20] < 0x06) {
            pc = 0x2fc6;
            break;
        }
        r8[al] = 0x07;
        push(r16[ax]);
        r8[al] = 0x0a;
        push(r16[ax]);
        yield* sub_7b57();
        sp += 0x0004;
        memory[ss*16 + bp - 21] = r8[al];
        if (!r8[al]) {
            pc = 0x3024;
            break;
        }
        r16[ax] = memory16get(ss, bp - 6);
        r16[dx] = memory16get(ss, bp - 8);
        memory16set(ss, bp - 16, r16[dx]);
        memory16set(ss, bp - 14, r16[ax]);
        r8[al] = memory[ss*16 + bp - 21];
        memory[ds*16 + 0x79b2] = r8[al];
        pc = 0x3035;
        break;
    case 0x3024:
        r16[ax] = memory16get(ss, bp - 10);
        r16[dx] = memory16get(ss, bp - 12);
        memory16set(ss, bp - 16, r16[dx]);
        memory16set(ss, bp - 14, r16[ax]);
        memory[ds*16 + 0x79b2] = 0x01;
    case 0x3035:
        memory[ss*16 + bp - 17] = 0x03;
        memory[ss*16 + bp - 18] = 0x06;
        r8[al] = memory[ss*16 + bp - 18];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory[ss*16 + bp - 20] = 0x00;
        pc = 0x3094;
        break;
    case 0x3054:
        r8[al] = memory[ss*16 + bp - 20];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 16);
        es = memory16get(ss, bp - 16 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 19] = r8[al];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r8[ah] = 0x00;
        r16[ax] += 0x0175;
        memory16set(es, r16[bx] + 4, r16[ax]);
        r8[al] = memory[ss*16 + bp - 17];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        memory16set(es, r16[bx], r16[ax]);
        if (memory[ss*16 + bp - 19] == 0x20) {
            pc = 0x308e;
            break;
        }
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x308e:
        memory[ss*16 + bp - 17] += 1;
        memory[ss*16 + bp - 20] += 1;
    case 0x3094:
        if (memory[ss*16 + bp - 20] < 0x0e) {
            pc = 0x3054;
            break;
        }
        memory[ss*16 + bp - 20] = 0x00;
        pc = 0x30a6;
        break;
    case 0x30a0:
        yield* sub_5d44();
        memory[ss*16 + bp - 20] += 1;
    case 0x30a6:
        if (memory[ss*16 + bp - 20] < 0x03) {
            pc = 0x30a0;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_30bb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000e;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x30cc;
            break;
        }
        yield* sub_ca53();
    case 0x30cc:
        push(ss);
        r16[ax] = bp - 0x4;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x11ae;
        push(r16[ax]);
        r16[cx] = 0x0004;
        yield* sub_c8c5();
        push(ds);
        r16[ax] = 0x0928;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(ds, 0x857e, r16[dx]);
        memory16set(ds, 0x8580, r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        r16[dx] = 0x0063;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ds, 0x8580));
        push(memory16get(ds, 0x857e));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x3168;
            break;
        }
        r16[ax] = memory16get(ds, 0x8580);
        r16[dx] = memory16get(ds, 0x857e);
        memory16set(ds, 0x9b96, r16[dx]);
        memory16set(ds, 0x9b98, r16[ax]);
        memory[ss*16 + bp - 13] = 0x00;
        pc = 0x3162;
        break;
    case 0x3145:
        r8[al] = memory[ss*16 + bp - 13];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 13];
        r8[ah] = 0x00;
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 1822];
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 13] += 1;
    case 0x3162:
        if (memory[ss*16 + bp - 13] < 0x10) {
            pc = 0x3145;
            break;
        }
    case 0x3168:
        yield* sub_5337();
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x8580));
        push(memory16get(ds, 0x857e));
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        yield* sub_b734();
        r8[al] = 0x06;
        memory[ss*16 + bp - 10] = r8[al];
        memory[ss*16 + bp - 9] = r8[al];
        r16[ax] = memory16get(ss, bp - 2);
        r16[dx] = memory16get(ss, bp - 4);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r8[al] = memory[ss*16 + bp - 10];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory[ss*16 + bp - 12] = 0x00;
        pc = 0x31f2;
        break;
    case 0x31b2:
        r8[al] = memory[ss*16 + bp - 12];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 11] = r8[al];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r8[ah] = 0x00;
        r16[ax] += 0x0175;
        memory16set(es, r16[bx] + 4, r16[ax]);
        r8[al] = memory[ss*16 + bp - 9];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        memory16set(es, r16[bx], r16[ax]);
        if (memory[ss*16 + bp - 11] == 0x20) {
            pc = 0x31ec;
            break;
        }
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x31ec:
        memory[ss*16 + bp - 9] += 1;
        memory[ss*16 + bp - 12] += 1;
    case 0x31f2:
        if (memory[ss*16 + bp - 12] < 0x09) {
            pc = 0x31b2;
            break;
        }
        memory[ss*16 + bp - 12] = 0x00;
        pc = 0x3204;
        break;
    case 0x31fe:
        yield* sub_5d44();
        memory[ss*16 + bp - 12] += 1;
    case 0x3204:
        if (memory[ss*16 + bp - 12] < 0x02) {
            pc = 0x31fe;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3219() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3227;
            break;
        }
        yield* sub_ca53();
    case 0x3227:
        memory[ss*16 + bp - 2] = 0x01;
        if (!(memory[ds*16 + 0x854f] & 0x01)) {
            pc = 0x3236;
            break;
        }
        r8[al] = 0x80;
        pc = 0x3238;
        break;
    case 0x3236:
        r8[al] = 0x00;
    case 0x3238:
        memory[ss*16 + bp - 1] = r8[al];
        if (!r8[al]) {
            pc = 0x3242;
            break;
        }
        memory[ss*16 + bp - 2] += 1;
    case 0x3242:
        r8[al] = memory[ds*16 + 0x854f];
        r8[ah] = 0x00;
        r16[ax] = sar16(r16[ax], 1);
        r8[al] |= memory[ss*16 + bp - 1];
        memory[ds*16 + 0x854f] = r8[al];
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        yield* sub_24b7();
        sp++;
        sp++;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_325c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3268;
            break;
        }
        yield* sub_ca53();
    case 0x3268:
        r16[ax] = memory16get(ds, 0x857a);
        memory16set(ds, 0x8882, r16[ax]);
        r16[ax] = memory16get(ds, 0x857c);
        memory16set(ds, 0x8e88, r16[ax]);
        r16[ax] = memory16get(ds, 0x9d36);
        memory16set(ds, 0x857a, r16[ax]);
        r16[ax] = memory16get(ds, 0x9d38);
        memory16set(ds, 0x857c, r16[ax]);
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3282() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x328e;
            break;
        }
        yield* sub_ca53();
    case 0x328e:
        if (memory[ds*16 + 0x8571] == 0xff) {
            pc = 0x32ad;
            break;
        }
        r16[ax] = memory16get(ds, 0x8558);
        memory16set(ds, 0x928e, r16[ax]);
        r16[ax] = memory16get(ds, 0x855a);
        memory16set(ds, 0x9b94, r16[ax]);
        r16[ax] = memory16get(ds, 0xa0ca);
        memory16set(ds, 0x8558, r16[ax]);
        r16[ax] = memory16get(ds, 0xa0cc);
        memory16set(ds, 0x855a, r16[ax]);
    case 0x32ad:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_32af() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x32bb;
            break;
        }
        yield* sub_ca53();
    case 0x32bb:
        r8[al] = memory[ds*16 + 0x8242];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x3341;
            break;
        }
        if (memory[ds*16 + 0x824d] == 0x00) {
            pc = 0x3341;
            break;
        }
        if (memory[ds*16 + 0x792c] == 0x05) {
            pc = 0x3341;
            break;
        }
        if (memory[ds*16 + 0x792c] == 0x0b) {
            pc = 0x3341;
            break;
        }
        if (memory[ds*16 + 0x792c] == 0x1c) {
            pc = 0x3341;
            break;
        }
        r16[bx] = memory16get(ds, 0xa1ac);
        es = memory16get(ds, 0xa1ac + 2);
        r16[ax] = memory16get(es, r16[bx]);
        memory16set(ds, 0x824a, r16[ax]);
        if (memory[ds*16 + 0x9bae] == 0x00) {
            pc = 0x3305;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 2);
        r16[ax] = -r16[ax];
        r16[dx] = memory16get(ds, 0x9290);
        r16[dx] += r16[ax];
        memory16set(ds, 0x9290, r16[dx]);
        r16[ax] = r16[dx];
        pc = 0x3314;
        break;
    case 0x3305:
        r16[bx] = memory16get(ds, 0xa1ac);
        es = memory16get(ds, 0xa1ac + 2);
        r16[ax] = memory16get(es, r16[bx] + 2);
        memory16set(ds, 0x9290, memory16get(ds, 0x9290) + r16[ax]);
        r16[ax] = memory16get(ds, 0x9290);
    case 0x3314:
        r16[bx] = memory16get(ds, 0xa1ac);
        es = memory16get(ds, 0xa1ac + 2);
        r16[ax] = memory16get(es, r16[bx] + 4);
        memory16set(ds, 0x9292, memory16get(ds, 0x9292) + r16[ax]);
        memory16set(ds, 0xa1ac, memory16get(ds, 0xa1ac) + 0x0006);
        r8[al] = memory[ds*16 + 0x824d];
        r8[al] += 0xff;
        memory[ds*16 + 0x824d] = r8[al];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x333a;
            break;
        }
        r8[al] = 0x00;
        memory[ds*16 + 0x792a] = r8[al];
        pc = 0x3341;
        break;
    case 0x333a:
        memory[ds*16 + 0x792a] += 1;
        r8[al] = memory[ds*16 + 0x792a];
    case 0x3341:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3343() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3351;
            break;
        }
        yield* sub_ca53();
    case 0x3351:
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        di = memory16get(es, r16[bx] + 20);
        si = memory16get(es, r16[bx] + 22);
        r16[ax] = memory16get(ds, 0x9290);
        r16[ax] -= di;
        r8[cl] = 0x04;
        r16[ax] = sar16(r16[ax], r8[cl]);
        r16[ax]--;
        memory16set(ds, 0x9d36, r16[ax]);
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] -= si;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory16set(ds, 0x9d38, r16[ax]);
        if (memory16gets(ds, 0x9d36) >= signed16(0x0000)) {
            pc = 0x3387;
            break;
        }
        memory16set(ds, 0x9d36, 0x0000);
        pc = 0x3394;
        break;
    case 0x3387:
        if (memory16gets(ds, 0x9d36) <= signed16(0x0012)) {
            pc = 0x3394;
            break;
        }
        memory16set(ds, 0x9d36, 0x0012);
    case 0x3394:
        if (memory16gets(ds, 0x9d38) >= signed16(0x0000)) {
            pc = 0x33a3;
            break;
        }
        memory16set(ds, 0x9d38, 0x0000);
        pc = 0x33b0;
        break;
    case 0x33a3:
        if (memory16gets(ds, 0x9d38) <= signed16(0x0016)) {
            pc = 0x33b0;
            break;
        }
        memory16set(ds, 0x9d38, 0x0016);
    case 0x33b0:
        di = pop();
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_33b4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0008;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x33c4;
            break;
        }
        yield* sub_ca53();
    case 0x33c4:
        memory[ds*16 + 0x856c] = 0x00;
        r8[cl] = 0x00;
        pc = 0x3464;
        break;
    case 0x33ce:
        r8[al] = memory[ds*16 + 0x856c];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19570);
        r16[dx] = memory16get(ds, r16[bx] + 19568);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        if (memory[es*16 + r16[bx]] == 0x00) {
            pc = 0x345e;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 4);
        r16[dx] = memory16get(es, r16[bx] + 2);
        memory16set(ds, 0xa0be, r16[dx]);
        memory16set(ds, 0xa0c0, r16[ax]);
        r16[bx] = memory16get(ds, 0xa0be);
        es = memory16get(ds, 0xa0be + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ds*16 + 0x8578] = r8[al];
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        memory16set(es, r16[bx] + 2, memory16get(es, r16[bx] + 2) + 1);
        memory[es*16 + r16[bx] + 6] = r8[al];
        if (memory[ds*16 + 0x8578] != 0xff) {
            pc = 0x3421;
            break;
        }
        memory[es*16 + r16[bx]] = 0x00;
        pc = 0x345e;
        break;
    case 0x3421:
        if (memory[ds*16 + 0x8578] == 0x00) {
            pc = 0x345e;
            break;
        }
        r8[al] = memory[ds*16 + 0x8578];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 15724);
        r16[dx] = memory16get(ds, r16[bx] + 15722);
        memory16set(ss, bp - 4, r16[dx]);
        memory16set(ss, bp - 2, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        push(es);
        si = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r16[ax] = memory16get(es, si);
        es = pop();
        memory16set(es, r16[bx] + 8, r16[ax]);
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r16[ax] = memory16get(es, r16[bx] + 2);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        memory16set(es, r16[bx] + 10, r16[ax]);
    case 0x345e:
        memory[ds*16 + 0x856c] += 1;
        r8[cl]++;
    case 0x3464:
        if (r8[cl] >= 0x03) {
            pc = 0x346c;
            break;
        }
        pc = 0x33ce;
        break;
    case 0x346c:
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3471() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0008;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3481;
            break;
        }
        yield* sub_ca53();
    case 0x3481:
        memory[ds*16 + 0x8566] = 0x00;
        r8[cl] = 0x00;
        pc = 0x3521;
        break;
    case 0x348b:
        r8[al] = memory[ds*16 + 0x8566];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19646);
        r16[dx] = memory16get(ds, r16[bx] + 19644);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        if (memory[es*16 + r16[bx]] == 0x00) {
            pc = 0x351b;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 4);
        r16[dx] = memory16get(es, r16[bx] + 2);
        memory16set(ds, 0xa0c2, r16[dx]);
        memory16set(ds, 0xa0c4, r16[ax]);
        r16[bx] = memory16get(ds, 0xa0c2);
        es = memory16get(ds, 0xa0c2 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ds*16 + 0x8579] = r8[al];
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        memory16set(es, r16[bx] + 2, memory16get(es, r16[bx] + 2) + 1);
        memory[es*16 + r16[bx] + 6] = r8[al];
        if (memory[ds*16 + 0x8579] != 0xff) {
            pc = 0x34de;
            break;
        }
        memory[es*16 + r16[bx]] = 0x00;
        pc = 0x351b;
        break;
    case 0x34de:
        if (memory[ds*16 + 0x8579] == 0x00) {
            pc = 0x351b;
            break;
        }
        r8[al] = memory[ds*16 + 0x8579];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 16552);
        r16[dx] = memory16get(ds, r16[bx] + 16550);
        memory16set(ss, bp - 4, r16[dx]);
        memory16set(ss, bp - 2, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        push(es);
        si = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r16[ax] = memory16get(es, si);
        es = pop();
        memory16set(es, r16[bx] + 8, r16[ax]);
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r16[ax] = memory16get(es, r16[bx] + 2);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        memory16set(es, r16[bx] + 10, r16[ax]);
    case 0x351b:
        memory[ds*16 + 0x8566] += 1;
        r8[cl]++;
    case 0x3521:
        if (r8[cl] >= 0x04) {
            pc = 0x3529;
            break;
        }
        pc = 0x348b;
        break;
    case 0x3529:
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_352e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000c;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x353f;
            break;
        }
        yield* sub_ca53();
    case 0x353f:
        memory[ss*16 + bp - 2] = 0x00;
    case 0x3543:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19570);
        r16[dx] = memory16get(ds, r16[bx] + 19568);
        memory16set(ss, bp - 12, r16[dx]);
        memory16set(ss, bp - 10, r16[ax]);
        r16[bx] = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] != 0x00) {
            pc = 0x356e;
            break;
        }
        pc = 0x3685;
        break;
    case 0x356e:
        if (memory[ss*16 + bp - 1] != 0xff) {
            pc = 0x3577;
            break;
        }
        pc = 0x3685;
        break;
    case 0x3577:
        r8[al] = memory[es*16 + r16[bx] + 1];
        memory[ss*16 + bp - 3] = r8[al];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        di = memory16get(ds, r16[bx] + 12990);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        si = memory16get(ds, r16[bx] + 12992);
        r16[bx] = memory16get(ds, 0x08d4);
        es = memory16get(ds, 0x08d4 + 2);
        memory16set(es, r16[bx] + 28, 0x0000);
        if (!(memory[ss*16 + bp - 3] & 0x01)) {
            pc = 0x35b4;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 28);
        r16[ax] |= 0x0600;
        memory16set(es, r16[bx] + 28, r16[ax]);
    case 0x35b4:
        r16[bx] = memory16get(ds, 0x08d4);
        es = memory16get(ds, 0x08d4 + 2);
        r16[ax] = di;
        memory16set(es, r16[bx] + 20, r16[ax]);
        memory16set(es, r16[bx] + 6, r16[ax]);
        r16[ax] = si;
        memory16set(es, r16[bx] + 22, r16[ax]);
        memory16set(es, r16[bx] + 8, r16[ax]);
        push(memory16get(ds, 0x08d6));
        push(memory16get(ds, 0x08d4));
        yield* sub_9f8c();
        sp += 0x0004;
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 244);
        memory16set(ss, bp - 6, r16[ax]);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 246);
        memory16set(ss, bp - 8, r16[ax]);
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r16[ax] = memory16get(ss, bp - 6);
        memory16set(es, r16[bx], r16[ax]);
        r16[bx] = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] += memory16get(es, r16[bx] + 8);
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        r16[bx] = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r16[ax] = memory16get(es, r16[bx] + 10);
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 4, r16[ax]);
        r16[bx] = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        if (memory16get(es, r16[bx] + 10) & 0x0200) {
            pc = 0x363f;
            break;
        }
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x363f:
        r16[bx] = memory16get(ds, 0x08e0);
        es = memory16get(ds, 0x08e0 + 2);
        memory16set(es, r16[bx] + 6, di);
        memory16set(es, r16[bx] + 8, si);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[dx] = 0x0180;
        imul16(r16[dx]);
        r16[ax] += 0x79be;
        memory16set(es, r16[bx] + 16, r16[ax]);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 28, 0x0000);
        if (!(memory[ss*16 + bp - 3] & 0x01)) {
            pc = 0x3677;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 28);
        r16[ax] |= 0x0200;
        memory16set(es, r16[bx] + 28, r16[ax]);
    case 0x3677:
        push(memory16get(ds, 0x08e2));
        push(memory16get(ds, 0x08e0));
        yield* sub_b288();
        sp += 0x0004;
    case 0x3685:
        memory[ss*16 + bp - 2] += 1;
        if (memory[ss*16 + bp - 1] == 0xff) {
            pc = 0x3691;
            break;
        }
        pc = 0x3543;
        break;
    case 0x3691:
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3697() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000c;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x36a8;
            break;
        }
        yield* sub_ca53();
    case 0x36a8:
        memory[ss*16 + bp - 2] = 0x00;
    case 0x36ac:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19646);
        r16[dx] = memory16get(ds, r16[bx] + 19644);
        memory16set(ss, bp - 12, r16[dx]);
        memory16set(ss, bp - 10, r16[ax]);
        r16[bx] = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] != 0x00) {
            pc = 0x36d7;
            break;
        }
        pc = 0x385f;
        break;
    case 0x36d7:
        if (memory[ss*16 + bp - 1] != 0xff) {
            pc = 0x36e0;
            break;
        }
        pc = 0x385f;
        break;
    case 0x36e0:
        r8[al] = memory[es*16 + r16[bx] + 1];
        memory[ss*16 + bp - 3] = r8[al];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        di = memory16get(ds, r16[bx] + 13374);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        si = memory16get(ds, r16[bx] + 13376);
        r16[bx] = memory16get(ds, 0x08c8);
        es = memory16get(ds, 0x08c8 + 2);
        memory16set(es, r16[bx] + 6, di);
        memory16set(es, r16[bx] + 8, si);
        push(memory16get(ds, 0x08ca));
        push(memory16get(ds, 0x08c8));
        yield* sub_9f7c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x08cc);
        es = memory16get(ds, 0x08cc + 2);
        memory16set(es, r16[bx] + 10, 0x0001);
        r16[ax] = 0;
        memory16set(es, r16[bx] + 22, r16[ax]);
        memory16set(es, r16[bx] + 20, r16[ax]);
        memory16set(es, r16[bx] + 28, 0x0004);
        if (!(memory[ss*16 + bp - 3] & 0x01)) {
            pc = 0x3760;
            break;
        }
        memory16set(es, r16[bx] + 2, 0x9fba);
        memory16set(es, r16[bx] + 4, ds);
        push(memory16get(ds, 0x08ce));
        push(memory16get(ds, 0x08cc));
        yield* sub_9f7c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x08cc);
        es = memory16get(ds, 0x08cc + 2);
        memory16set(es, r16[bx] + 2, 0x9eba);
        pc = 0x3786;
        break;
    case 0x3760:
        r16[bx] = memory16get(ds, 0x08cc);
        es = memory16get(ds, 0x08cc + 2);
        memory16set(es, r16[bx] + 2, 0x9eba);
        memory16set(es, r16[bx] + 4, ds);
        push(memory16get(ds, 0x08ce));
        push(memory16get(ds, 0x08cc));
        yield* sub_9f7c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x08cc);
        es = memory16get(ds, 0x08cc + 2);
        memory16set(es, r16[bx] + 2, 0x9fba);
    case 0x3786:
        memory16set(es, r16[bx] + 4, ds);
        r16[bx] = memory16get(ds, 0x08cc);
        es = memory16get(ds, 0x08cc + 2);
        memory16set(es, r16[bx] + 20, di);
        memory16set(es, r16[bx] + 22, si);
        push(memory16get(ds, 0x08ce));
        push(memory16get(ds, 0x08cc));
        yield* sub_9f8c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x08cc);
        es = memory16get(ds, 0x08cc + 2);
        memory16set(es, r16[bx] + 2, 0x8888);
        memory16set(es, r16[bx] + 4, ds);
        memory16set(es, r16[bx] + 10, 0x0003);
        memory16set(es, r16[bx] + 28, 0x0003);
        push(memory16get(ds, 0x08ce));
        push(memory16get(ds, 0x08cc));
        yield* sub_9f8c();
        sp += 0x0004;
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 1012);
        memory16set(ss, bp - 6, r16[ax]);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 1014);
        memory16set(ss, bp - 8, r16[ax]);
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r16[ax] = memory16get(ss, bp - 6);
        memory16set(es, r16[bx], r16[ax]);
        r16[bx] = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r16[ax] = memory16get(ss, bp - 8);
        r16[ax] += memory16get(es, r16[bx] + 8);
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        r16[bx] = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        if (memory16get(es, r16[bx] + 10) & 0x0200) {
            pc = 0x3831;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 10);
        r16[ax] += 0x00f1;
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 4, r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x3831:
        r16[bx] = memory16get(ds, 0x08d0);
        es = memory16get(ds, 0x08d0 + 2);
        memory16set(es, r16[bx] + 6, di);
        memory16set(es, r16[bx] + 8, si);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r8[cl] = 0x08;
        r16[ax] <<= r8[cl];
        r16[ax] += 0x7e3e;
        memory16set(es, r16[bx] + 16, r16[ax]);
        memory16set(es, r16[bx] + 18, ds);
        push(memory16get(ds, 0x08d2));
        push(memory16get(ds, 0x08d0));
        yield* sub_b288();
        sp += 0x0004;
    case 0x385f:
        memory[ss*16 + bp - 2] += 1;
        if (memory[ss*16 + bp - 1] == 0xff) {
            pc = 0x386b;
            break;
        }
        pc = 0x36ac;
        break;
    case 0x386b:
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3871() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x387d;
            break;
        }
        yield* sub_ca53();
    case 0x387d:
        if (memory[ds*16 + 0x8571] == 0xff) {
            pc = 0x38b2;
            break;
        }
        r16[bx] = memory16get(ds, 0x08e8);
        es = memory16get(ds, 0x08e8 + 2);
        r16[ax] = memory16get(ds, 0x928e);
        memory16set(es, r16[bx] + 20, r16[ax]);
        r16[ax] = memory16get(ds, 0x9b94);
        memory16set(es, r16[bx] + 22, r16[ax]);
        r16[ax] = memory16get(ds, 0x9d34);
        memory16set(es, r16[bx] + 30, r16[ax]);
        r16[ax] = memory16get(ds, 0x9d32);
        memory16set(es, r16[bx] + 32, r16[ax]);
        push(memory16get(ds, 0x08ea));
        push(memory16get(ds, 0x08e8));
        yield* sub_9f8c();
        sp += 0x0004;
    case 0x38b2:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_38b4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x38c0;
            break;
        }
        yield* sub_ca53();
    case 0x38c0:
        r16[bx] = memory16get(ds, 0x08c4);
        es = memory16get(ds, 0x08c4 + 2);
        r16[ax] = memory16get(ds, 0x8882);
        memory16set(es, r16[bx] + 20, r16[ax]);
        r16[ax] = memory16get(ds, 0x8e88);
        memory16set(es, r16[bx] + 22, r16[ax]);
        r16[ax] = memory16get(ds, 0x9ba4);
        memory16set(es, r16[bx] + 30, r16[ax]);
        r16[ax] = memory16get(ds, 0x9b9c);
        memory16set(es, r16[bx] + 32, r16[ax]);
        push(memory16get(ds, 0x08c6));
        push(memory16get(ds, 0x08c4));
        yield* sub_9f8c();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_38f0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x38fc;
            break;
        }
        yield* sub_ca53();
    case 0x38fc:
        if (memory[ds*16 + 0xa1a8] == 0x00) {
            pc = 0x3935;
            break;
        }
        memory[ds*16 + 0xa1a8] -= 1;
        r16[bx] = memory16get(ds, 0x08e4);
        es = memory16get(ds, 0x08e4 + 2);
        r16[ax] = memory16get(ds, 0x9b9a);
        memory16set(es, r16[bx] + 6, r16[ax]);
        r16[ax] = memory16get(ds, 0x9ba2);
        memory16set(es, r16[bx] + 8, r16[ax]);
        r16[ax] = memory16get(ds, 0x9b9a);
        memory16set(es, r16[bx] + 20, r16[ax]);
        r16[ax] = memory16get(ds, 0x9ba2);
        memory16set(es, r16[bx] + 22, r16[ax]);
        push(memory16get(ds, 0x08e6));
        push(memory16get(ds, 0x08e4));
        yield* sub_9f8c();
        sp += 0x0004;
    case 0x3935:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3937() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0008;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3946;
            break;
        }
        yield* sub_ca53();
    case 0x3946:
        memory[ss*16 + bp - 2] = 0x00;
    case 0x394a:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19570);
        r16[dx] = memory16get(ds, r16[bx] + 19568);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x39eb;
            break;
        }
        if (memory[ss*16 + bp - 1] == 0xff) {
            pc = 0x39eb;
            break;
        }
        r8[al] = memory[es*16 + r16[bx] + 1];
        memory[ss*16 + bp - 3] = r8[al];
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[dx] = 0x0180;
        imul16(r16[dx]);
        r16[ax] += 0x79be;
        r16[bx] = memory16get(ds, 0x08c0);
        es = memory16get(ds, 0x08c0 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory16set(es, r16[bx] + 4, ds);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 12990);
        r16[bx] = memory16get(ds, 0x08c0);
        memory16set(es, r16[bx] + 20, r16[ax]);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 12992);
        r16[bx] = memory16get(ds, 0x08c0);
        memory16set(es, r16[bx] + 22, r16[ax]);
        memory16set(es, r16[bx] + 28, 0x0000);
        if (!(memory[ss*16 + bp - 3] & 0x01)) {
            pc = 0x39dd;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 28);
        r16[ax] |= 0x0400;
        memory16set(es, r16[bx] + 28, r16[ax]);
    case 0x39dd:
        push(memory16get(ds, 0x08c2));
        push(memory16get(ds, 0x08c0));
        yield* sub_9f8c();
        sp += 0x0004;
    case 0x39eb:
        memory[ss*16 + bp - 2] += 1;
        if (memory[ss*16 + bp - 1] == 0xff) {
            pc = 0x39f7;
            break;
        }
        pc = 0x394a;
        break;
    case 0x39f7:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_39fb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0008;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3a0a;
            break;
        }
        yield* sub_ca53();
    case 0x3a0a:
        memory[ss*16 + bp - 2] = 0x00;
    case 0x3a0e:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19646);
        r16[dx] = memory16get(ds, r16[bx] + 19644);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x3a97;
            break;
        }
        if (memory[ss*16 + bp - 1] == 0xff) {
            pc = 0x3a97;
            break;
        }
        r8[al] = memory[es*16 + r16[bx] + 1];
        memory[ss*16 + bp - 3] = r8[al];
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r8[cl] = 0x08;
        r16[ax] <<= r8[cl];
        r16[ax] += 0x7e3e;
        r16[bx] = memory16get(ds, 0x08bc);
        es = memory16get(ds, 0x08bc + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory16set(es, r16[bx] + 4, ds);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 13374);
        r16[bx] = memory16get(ds, 0x08bc);
        memory16set(es, r16[bx] + 20, r16[ax]);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 13376);
        r16[bx] = memory16get(ds, 0x08bc);
        memory16set(es, r16[bx] + 22, r16[ax]);
        push(memory16get(ds, 0x08be));
        push(memory16get(ds, 0x08bc));
        yield* sub_9f8c();
        sp += 0x0004;
    case 0x3a97:
        memory[ss*16 + bp - 2] += 1;
        if (memory[ss*16 + bp - 1] == 0xff) {
            pc = 0x3aa3;
            break;
        }
        pc = 0x3a0e;
        break;
    case 0x3aa3:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3aa7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3ab3;
            break;
        }
        yield* sub_ca53();
    case 0x3ab3:
        memory16set(ds, 0x9ba4, 0x0004);
        if (memory16gets(ds, 0x857a) <= signed16(0x0010)) {
            pc = 0x3aca;
            break;
        }
        r16[ax] = 0x0014;
        r16[ax] -= memory16get(ds, 0x857a);
        memory16set(ds, 0x9ba4, r16[ax]);
    case 0x3aca:
        memory16set(ds, 0x9b9c, 0x0004);
        if (memory16gets(ds, 0x857c) <= signed16(0x0015)) {
            pc = 0x3ae1;
            break;
        }
        r16[ax] = 0x0019;
        r16[ax] -= memory16get(ds, 0x857c);
        memory16set(ds, 0x9b9c, r16[ax]);
    case 0x3ae1:
        r16[bx] = memory16get(ds, 0x08b8);
        es = memory16get(ds, 0x08b8 + 2);
        r16[ax] = memory16get(ds, 0x857a);
        memory16set(es, r16[bx] + 6, r16[ax]);
        r16[ax] = memory16get(ds, 0x857c);
        memory16set(es, r16[bx] + 8, r16[ax]);
        r16[ax] = memory16get(ds, 0x9ba4);
        memory16set(es, r16[bx] + 30, r16[ax]);
        r16[ax] = memory16get(ds, 0x9b9c);
        memory16set(es, r16[bx] + 32, r16[ax]);
        push(memory16get(ds, 0x08ba));
        push(memory16get(ds, 0x08b8));
        yield* sub_b288();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3b11() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3b1d;
            break;
        }
        yield* sub_ca53();
    case 0x3b1d:
        if (memory[ds*16 + 0x8571] == 0xff) {
            pc = 0x3b80;
            break;
        }
        memory16set(ds, 0x9d34, 0x0004);
        if (memory16gets(ds, 0x8558) <= signed16(0x0010)) {
            pc = 0x3b3b;
            break;
        }
        r16[ax] = 0x0014;
        r16[ax] -= memory16get(ds, 0x8558);
        memory16set(ds, 0x9d34, r16[ax]);
    case 0x3b3b:
        memory16set(ds, 0x9d32, 0x0004);
        if (memory16gets(ds, 0x855a) <= signed16(0x0015)) {
            pc = 0x3b52;
            break;
        }
        r16[ax] = 0x0019;
        r16[ax] -= memory16get(ds, 0x855a);
        memory16set(ds, 0x9d32, r16[ax]);
    case 0x3b52:
        r16[bx] = memory16get(ds, 0x08ec);
        es = memory16get(ds, 0x08ec + 2);
        r16[ax] = memory16get(ds, 0x8558);
        memory16set(es, r16[bx] + 6, r16[ax]);
        r16[ax] = memory16get(ds, 0x855a);
        memory16set(es, r16[bx] + 8, r16[ax]);
        r16[ax] = memory16get(ds, 0x9d34);
        memory16set(es, r16[bx] + 30, r16[ax]);
        r16[ax] = memory16get(ds, 0x9d32);
        memory16set(es, r16[bx] + 32, r16[ax]);
        push(memory16get(ds, 0x08ee));
        push(memory16get(ds, 0x08ec));
        yield* sub_b288();
        sp += 0x0004;
    case 0x3b80:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3b82() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3b8e;
            break;
        }
        yield* sub_ca53();
    case 0x3b8e:
        if (memory16get(ds, 0x824a) == 0x0064) {
            pc = 0x3bb8;
            break;
        }
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r16[ax] = memory16get(ds, 0x824a);
        memory16set(es, r16[bx] + 4, r16[ax]);
        r16[ax] = memory16get(ds, 0x9290);
        memory16set(es, r16[bx], r16[ax]);
        r16[ax] = memory16get(ds, 0x9292);
        memory16set(es, r16[bx] + 2, r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x3bb8:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3bba() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3bc6;
            break;
        }
        yield* sub_ca53();
    case 0x3bc6:
        if (memory[ds*16 + 0x8571] == 0xff) {
            pc = 0x3bf4;
            break;
        }
        r16[bx] = memory16get(ds, 0x9b9e);
        es = memory16get(ds, 0x9b9e + 2);
        r16[ax] = memory16get(ds, 0xa0de);
        r16[ax] += memory16get(ds, 0x8560);
        memory16set(es, r16[bx] + 4, r16[ax]);
        r16[ax] = memory16get(ds, 0x79ba);
        memory16set(es, r16[bx], r16[ax]);
        r16[ax] = memory16get(ds, 0x79bc);
        memory16set(es, r16[bx] + 2, r16[ax]);
        push(ds);
        r16[ax] = 0x795a;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x3bf4:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3bf6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3c02;
            break;
        }
        yield* sub_ca53();
    case 0x3c02:
        r8[al] = 0x3b;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x3c15;
            break;
        }
        memory[ds*16 + 0x854f] = 0x00;
        pc = 0x3c8b;
        break;
    case 0x3c15:
        r8[al] = 0x3c;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x3c28;
            break;
        }
        memory[ds*16 + 0x854f] = 0x88;
        pc = 0x3c8b;
        break;
    case 0x3c28:
        r8[al] = 0x3d;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x3c3b;
            break;
        }
        memory[ds*16 + 0x854f] = 0xaa;
        pc = 0x3c8b;
        break;
    case 0x3c3b:
        r8[al] = 0x3e;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x3c4e;
            break;
        }
        memory[ds*16 + 0x854f] = 0xee;
        pc = 0x3c8b;
        break;
    case 0x3c4e:
        r8[al] = 0x3f;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x3c61;
            break;
        }
        memory[ds*16 + 0x854f] = 0xff;
        pc = 0x3c8b;
        break;
    case 0x3c61:
        r8[al] = 0x01;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x3c72;
            break;
        }
        yield* sub_41cc();
        pc = 0x3c8b;
        break;
    case 0x3c72:
        r8[al] = 0x44;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x3c8b;
            break;
        }
        memory[ds*16 + 0x928d] = 0x01;
        r8[al] = 0x00;
        memory[ds*16 + 0x9d30] = r8[al];
        memory[ds*16 + 0x856d] = r8[al];
    case 0x3c8b:
        if (memory[ds*16 + 0xa1aa] == 0x00) {
            pc = 0x3c97;
            break;
        }
        yield* sub_415d();
        pc = 0x3cac;
        break;
    case 0x3c97:
        yield* sub_423f();
        yield* sub_3cae();
        if (memory[ds*16 + 0x824d] == 0x00) {
            pc = 0x3ca9;
            break;
        }
        yield* sub_425e();
        pc = 0x3cac;
        break;
    case 0x3ca9:
        yield* sub_3cd2();
    case 0x3cac:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3cae() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3cbc;
            break;
        }
        yield* sub_ca53();
    case 0x3cbc:
        r8[al] = 0x00;
        push(r16[ax]);
        yield* sub_9472();
        sp++;
        sp++;
        memory[ss*16 + bp - 1] = r8[al];
        if (!r8[al]) {
            pc = 0x3cce;
            break;
        }
        memory[ds*16 + 0x8244] = r8[al];
    case 0x3cce:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3cd2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3cde;
            break;
        }
        yield* sub_ca53();
    case 0x3cde:
        memory[ds*16 + 0x7923] = 0x00;
        r8[al] = memory[ds*16 + 0x792c];
        memory[ds*16 + 0x8552] = r8[al];
        if (memory[ds*16 + 0xa0ce] != 0x00) {
            pc = 0x3cf9;
            break;
        }
        r8[al] = memory[ds*16 + 0xa1a7];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x3d08;
            break;
        }
    case 0x3cf9:
        r8[al] = memory[ds*16 + 0x792c];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 1994));
        pc = 0x3d0b;
        break;
    case 0x3d08:
        yield* sub_46ae();
    case 0x3d0b:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3d0d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3d19;
            break;
        }
        yield* sub_ca53();
    case 0x3d19:
        r8[al] = 0x01;
        memory[ds*16 + 0x9d30] = r8[al];
        memory[ds*16 + 0xa1a9] = r8[al];
        yield* sub_5958();
        r16[bx] = memory16get(ds, 0x9baa);
        es = memory16get(ds, 0x9baa + 2);
        memory[es*16 + r16[bx]] = 0x01;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3d2e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3d3a;
            break;
        }
        yield* sub_ca53();
    case 0x3d3a:
        if (memory[ds*16 + 0x8551] != 0x08) {
            pc = 0x3d59;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x3d4c;
            break;
        }
        r8[al] = 0x0f;
        pc = 0x3d4e;
        break;
    case 0x3d4c:
        r8[al] = 0x2b;
    case 0x3d4e:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        yield* sub_40b7();
        pc = 0x3d5e;
        break;
    case 0x3d59:
        memory[ds*16 + 0x792c] = 0x24;
    case 0x3d5e:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3d60() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3d6c;
            break;
        }
        yield* sub_ca53();
    case 0x3d6c:
        if (memory[ds*16 + 0x8551] != 0x08) {
            pc = 0x3d8b;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x3d7e;
            break;
        }
        r8[al] = 0x0f;
        pc = 0x3d80;
        break;
    case 0x3d7e:
        r8[al] = 0x2b;
    case 0x3d80:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        yield* sub_4008();
        pc = 0x3d90;
        break;
    case 0x3d8b:
        memory[ds*16 + 0x792c] = 0x23;
    case 0x3d90:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3d92() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3da1;
            break;
        }
        yield* sub_ca53();
    case 0x3da1:
        memory[ss*16 + bp - 1] = 0x0b;
        memory[ss*16 + bp - 2] = 0x05;
        memory16set(ss, bp - 6, 0x1ca4);
        memory16set(ss, bp - 4, ds);
        push(memory16get(ss, bp - 4));
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 1];
        push(r16[ax]);
        yield* sub_682c();
        sp += 0x0008;
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x3dcf;
            break;
        }
        yield* sub_3dd3();
    case 0x3dcf:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3dd3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3ddf;
            break;
        }
        yield* sub_ca53();
    case 0x3ddf:
        memory[ds*16 + 0x792c] = 0x01;
        memory16set(ds, 0xa1ac, 0x140c);
        memory16set(ds, 0xa1ae, ds);
        memory[ds*16 + 0x824d] = 0x04;
        r8[al] = 0x09;
        memory[ds*16 + 0x9bae] = r8[al];
        memory[ds*16 + 0x792a] = r8[al];
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x8570] = r8[al];
        r8[al] = 0x16;
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3e0e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3e1d;
            break;
        }
        yield* sub_ca53();
    case 0x3e1d:
        memory[ss*16 + bp - 1] = 0x0b;
        memory[ss*16 + bp - 2] = 0x05;
        memory16set(ss, bp - 6, 0x1cba);
        memory16set(ss, bp - 4, ds);
        push(memory16get(ss, bp - 4));
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 1];
        push(r16[ax]);
        yield* sub_682c();
        sp += 0x0008;
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x3e4b;
            break;
        }
        yield* sub_3e4f();
    case 0x3e4b:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3e4f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3e5b;
            break;
        }
        yield* sub_ca53();
    case 0x3e5b:
        memory[ds*16 + 0x792c] = 0x02;
        memory16set(ds, 0xa1ac, 0x1460);
        memory16set(ds, 0xa1ae, ds);
        memory[ds*16 + 0x824d] = 0x04;
        memory[ds*16 + 0x792a] = 0x09;
        memory[ds*16 + 0x9bae] = 0x00;
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xff;
        memory[ds*16 + 0x8570] = r8[al];
        r8[al] = 0x16;
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3e8e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3e9a;
            break;
        }
        yield* sub_ca53();
    case 0x3e9a:
        memory[ds*16 + 0x8551] = 0x00;
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x3eaa;
            break;
        }
        r8[al] = 0x02;
        pc = 0x3eac;
        break;
    case 0x3eaa:
        r8[al] = 0x26;
    case 0x3eac:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x855e];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x3ec4;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x38;
        pc = 0x3f42;
        break;
    case 0x3ec4:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xff;
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        if (memory[ds*16 + r16[bx] + 17238] != 0x38) {
            pc = 0x3ee4;
            break;
        }
        r8[al] = 0x38;
        pc = 0x3f42;
        break;
    case 0x3ee4:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xff;
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x3efa;
            break;
        }
        r8[al] = 0x3a;
        pc = 0x3f42;
        break;
    case 0x3efa:
        if (memory[ds*16 + 0x855e] != 0x01) {
            pc = 0x3f0a;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x34;
        pc = 0x3f42;
        break;
    case 0x3f0a:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xfe;
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        if (memory[ds*16 + r16[bx] + 17174] != 0x34) {
            pc = 0x3f2a;
            break;
        }
        r8[al] = 0x34;
        pc = 0x3f42;
        break;
    case 0x3f2a:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xfe;
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x3f40;
            break;
        }
        r8[al] = 0x36;
        pc = 0x3f42;
        break;
    case 0x3f40:
        r8[al] = 0x1a;
    case 0x3f42:
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_3f4d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x3f59;
            break;
        }
        yield* sub_ca53();
    case 0x3f59:
        memory[ds*16 + 0x8551] = 0x00;
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x3f69;
            break;
        }
        r8[al] = 0x02;
        pc = 0x3f6b;
        break;
    case 0x3f69:
        r8[al] = 0x26;
    case 0x3f6b:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        if (memory[ds*16 + 0x855e] != 0x07) {
            pc = 0x3f81;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x39;
        pc = 0x3ffd;
        break;
    case 0x3f81:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        if (memory[ds*16 + r16[bx] + 17270] != 0x39) {
            pc = 0x3f9f;
            break;
        }
        r8[al] = 0x39;
        pc = 0x3ffd;
        break;
    case 0x3f9f:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al]++;
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x3fb5;
            break;
        }
        r8[al] = 0x3b;
        pc = 0x3ffd;
        break;
    case 0x3fb5:
        if (memory[ds*16 + 0x855e] != 0x06) {
            pc = 0x3fc5;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x35;
        pc = 0x3ffd;
        break;
    case 0x3fc5:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al]++;
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        if (memory[ds*16 + r16[bx] + 17206] != 0x35) {
            pc = 0x3fe5;
            break;
        }
        r8[al] = 0x35;
        pc = 0x3ffd;
        break;
    case 0x3fe5:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0x02;
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x3ffb;
            break;
        }
        r8[al] = 0x37;
        pc = 0x3ffd;
        break;
    case 0x3ffb:
        r8[al] = 0x1b;
    case 0x3ffd:
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4008() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4016;
            break;
        }
        yield* sub_ca53();
    case 0x4016:
        memory[ds*16 + 0x8551] = 0x00;
        if (!(memory[ds*16 + 0x8244] & 0x12)) {
            pc = 0x403f;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x402d;
            break;
        }
        r8[al] = 0x15;
        pc = 0x402f;
        break;
    case 0x402d:
        r8[al] = 0x2a;
    case 0x402f:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = 0x32;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        pc = 0x4084;
        break;
    case 0x403f:
        r8[al] = memory[ds*16 + 0x855e];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x4057;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x27;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        pc = 0x4084;
        break;
    case 0x4057:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xff;
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 17110];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x25) {
            pc = 0x4081;
            break;
        }
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        pc = 0x4084;
        break;
    case 0x4081:
        yield* sub_408b();
    case 0x4084:
        yield* sub_425e();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_408b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4097;
            break;
        }
        yield* sub_ca53();
    case 0x4097:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xff;
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x40ad;
            break;
        }
        r8[al] = 0x29;
        pc = 0x40af;
        break;
    case 0x40ad:
        r8[al] = 0x25;
    case 0x40af:
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_40b7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x40c5;
            break;
        }
        yield* sub_ca53();
    case 0x40c5:
        if (!(memory[ds*16 + 0x8244] & 0x12)) {
            pc = 0x40e9;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x40d7;
            break;
        }
        r8[al] = 0x15;
        pc = 0x40d9;
        break;
    case 0x40d7:
        r8[al] = 0x2a;
    case 0x40d9:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = 0x33;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        pc = 0x412a;
        break;
    case 0x40e9:
        if (memory[ds*16 + 0x855e] != 0x07) {
            pc = 0x40ff;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x28;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        pc = 0x412a;
        break;
    case 0x40ff:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 17142];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x26) {
            pc = 0x4127;
            break;
        }
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        pc = 0x412a;
        break;
    case 0x4127:
        yield* sub_4131();
    case 0x412a:
        yield* sub_425e();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4131() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x413d;
            break;
        }
        yield* sub_ca53();
    case 0x413d:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al]++;
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x4153;
            break;
        }
        r8[al] = 0x2a;
        pc = 0x4155;
        break;
    case 0x4153:
        r8[al] = 0x26;
    case 0x4155:
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_415d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4169;
            break;
        }
        yield* sub_ca53();
    case 0x4169:
        memory[ds*16 + 0xa0ce] = 0x01;
        r8[al] = 0x00;
        memory[ds*16 + 0x792a] = r8[al];
        memory[ds*16 + 0xa1aa] = r8[al];
        r8[al] = 0x2e;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4180() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x418c;
            break;
        }
        yield* sub_ca53();
    case 0x418c:
        yield* sub_41cc();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4191() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x419d;
            break;
        }
        yield* sub_ca53();
    case 0x419d:
        yield* sub_41cc();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_41a2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x41ae;
            break;
        }
        yield* sub_ca53();
    case 0x41ae:
        r8[al] = memory[ds*16 + 0xa0ce];
        r8[al]++;
        memory[ds*16 + 0xa0ce] = r8[al];
        if (r8[al] != 0x03) {
            pc = 0x41bf;
            break;
        }
        yield* sub_41cc();
        pc = 0x41ca;
        break;
    case 0x41bf:
        r8[al] = 0x2e;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
    case 0x41ca:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_41cc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x41d9;
            break;
        }
        yield* sub_ca53();
    case 0x41d9:
        memory[ds*16 + 0xa0ce] = 0x00;
        si = 0x03e8;
        pc = 0x41e7;
        break;
    case 0x41e3:
        yield* sub_423f();
        si--;
    case 0x41e7:
        if (si) {
            pc = 0x41e3;
            break;
        }
        memory[ds*16 + 0x856d] = 0x01;
        r8[al] = memory[ds*16 + 0x791a];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x4200;
            break;
        }
        r8[al] = 0xff;
        memory[ds*16 + 0x928d] = r8[al];
        pc = 0x4207;
        break;
    case 0x4200:
        memory[ds*16 + 0x791a] -= 1;
        r8[al] = memory[ds*16 + 0x791a];
    case 0x4207:
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_420a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4216;
            break;
        }
        yield* sub_ca53();
    case 0x4216:
        if (memory[ds*16 + 0xa1b1] == 0x00) {
            pc = 0x423d;
            break;
        }
        if (memory[ds*16 + 0x8550] == 0x09) {
            pc = 0x422a;
            break;
        }
        memory[ds*16 + 0x8550] += 1;
        pc = 0x423d;
        break;
    case 0x422a:
        memory[ds*16 + 0x8550] = 0x00;
        r8[al] = memory[ds*16 + 0x8572];
        memory[ds*16 + 0x856f] = r8[al];
        r8[al] = 0x5a;
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
    case 0x423d:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_423f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x424b;
            break;
        }
        yield* sub_ca53();
    case 0x424b:
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ds*16 + 0x7924] = r8[al];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_425e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x426a;
            break;
        }
        yield* sub_ca53();
    case 0x426a:
        r8[al] = memory[ds*16 + 0x792c];
        r8[ah] = 0x00;
        r16[dx] = 0x0022;
        imul16(r16[dx]);
        r8[dl] = memory[ds*16 + 0x792a];
        r8[dh] = 0x00;
        r16[dx] <<= 1;
        r16[ax] += r16[dx];
        r16[bx] = r16[ax];
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 17344));
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4286() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4292;
            break;
        }
        yield* sub_ca53();
    case 0x4292:
        if (!(memory[ds*16 + 0x8244] & 0x04)) {
            pc = 0x429e;
            break;
        }
        yield* sub_4504();
        pc = 0x42f1;
        break;
    case 0x429e:
        if (!(memory[ds*16 + 0x8244] & 0x08)) {
            pc = 0x42aa;
            break;
        }
        yield* sub_4571();
        pc = 0x42f1;
        break;
    case 0x42aa:
        if (memory[ds*16 + 0x856e] < 0x08) {
            pc = 0x42c9;
            break;
        }
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        es = memory16get(ds, 0xa0da);
        r16[ax] += memory16get(ds, 0xa0d8);
        r16[bx] = r16[ax];
        if (memory[es*16 + r16[bx] - 8] != 0x0e) {
            pc = 0x42c9;
            break;
        }
        pc = 0x42ee;
        break;
    case 0x42c9:
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x42ee;
            break;
        }
        yield* sub_6617();
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x42e4;
            break;
        }
        r8[al] = 0x14;
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        pc = 0x42f1;
        break;
    case 0x42e4:
        r8[al] = 0x2a;
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        pc = 0x42f1;
        break;
    case 0x42ee:
        yield* sub_46ae();
    case 0x42f1:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_42f3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4302;
            break;
        }
        yield* sub_ca53();
    case 0x4302:
        memory[ss*16 + bp - 1] = 0x21;
        memory[ss*16 + bp - 2] = 0x04;
        memory16set(ss, bp - 6, 0x14ea);
        memory16set(ss, bp - 4, ds);
        push(memory16get(ss, bp - 4));
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 1];
        push(r16[ax]);
        yield* sub_682c();
        sp += 0x0008;
        if (!(memory[ds*16 + 0x8244] & 0x04)) {
            pc = 0x4332;
            break;
        }
        yield* sub_4504();
        pc = 0x433c;
        break;
    case 0x4332:
        if (!(memory[ds*16 + 0x8244] & 0x08)) {
            pc = 0x433c;
            break;
        }
        yield* sub_4571();
    case 0x433c:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4340() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x434c;
            break;
        }
        yield* sub_ca53();
    case 0x434c:
        memory[ds*16 + 0x824c] = 0x08;
        r8[al] = 0x0b;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_435e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x436d;
            break;
        }
        yield* sub_ca53();
    case 0x436d:
        memory[ss*16 + bp - 1] = 0x25;
        memory[ss*16 + bp - 2] = 0x06;
        memory16set(ss, bp - 6, 0x1664);
        memory16set(ss, bp - 4, ds);
        push(memory16get(ss, bp - 4));
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 1];
        push(r16[ax]);
        yield* sub_682c();
        sp += 0x0008;
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x43a3;
            break;
        }
        r8[al] = 0x0c;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
    case 0x43a3:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_43a7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x43b3;
            break;
        }
        yield* sub_ca53();
    case 0x43b3:
        if (memory[ds*16 + 0x7924] != 0x00) {
            pc = 0x43d0;
            break;
        }
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        es = memory16get(ds, 0xa0da);
        r16[ax] += memory16get(ds, 0xa0d8);
        r16[bx] = r16[ax];
        if (memory[es*16 + r16[bx] + 8] != 0x0b) {
            pc = 0x43d5;
            break;
        }
    case 0x43d0:
        yield* sub_43da();
        pc = 0x43d8;
        break;
    case 0x43d5:
        yield* sub_47b0();
    case 0x43d8:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_43da() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x43e6;
            break;
        }
        yield* sub_ca53();
    case 0x43e6:
        if (!(memory[ds*16 + 0x8244] & 0x04)) {
            pc = 0x43f2;
            break;
        }
        yield* sub_4504();
        pc = 0x440d;
        break;
    case 0x43f2:
        if (!(memory[ds*16 + 0x8244] & 0x08)) {
            pc = 0x43fe;
            break;
        }
        yield* sub_4571();
        pc = 0x440d;
        break;
    case 0x43fe:
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x440a;
            break;
        }
        yield* sub_440f();
        pc = 0x440d;
        break;
    case 0x440a:
        yield* sub_46ae();
    case 0x440d:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_440f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x441b;
            break;
        }
        yield* sub_ca53();
    case 0x441b:
        if (memory[ds*16 + 0x7924] != 0x0f) {
            pc = 0x4427;
            break;
        }
        yield* sub_66d2();
        pc = 0x443a;
        break;
    case 0x4427:
        if (memory[ds*16 + 0x7924] != 0x12) {
            pc = 0x4430;
            break;
        }
        pc = 0x4437;
        break;
    case 0x4430:
        if (memory[ds*16 + 0x7924] != 0x1f) {
            pc = 0x443a;
            break;
        }
    case 0x4437:
        yield* sub_4180();
    case 0x443a:
        yield* sub_84cb();
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x4448;
            break;
        }
        r8[al] = 0x14;
        pc = 0x444a;
        break;
    case 0x4448:
        r8[al] = 0x09;
    case 0x444a:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        memory[ds*16 + 0x824c] += 1;
        if (memory[ds*16 + 0x824c] != 0x09) {
            pc = 0x4470;
            break;
        }
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xf8;
        memory[ds*16 + 0x856f] = r8[al];
        r8[al] = 0x24;
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
        memory[ds*16 + 0x824c] = 0x00;
    case 0x4470:
        r8[al] = 0x0d;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_447d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x448b;
            break;
        }
        yield* sub_ca53();
    case 0x448b:
        memory[ss*16 + bp - 2] = 0x00;
        r8[al] = memory[ds*16 + 0x856e];
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x44f7;
        break;
    case 0x4497:
        r8[al] = memory[ss*16 + bp - 1];
        r8[al]++;
        memory[ss*16 + bp - 1] = r8[al];
        if (r8[al] != 0x30) {
            pc = 0x44a7;
            break;
        }
        memory[ss*16 + bp - 1] = 0x00;
    case 0x44a7:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx]] != 0x0f) {
            pc = 0x44f7;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        memory[ds*16 + 0x856f] = r8[al];
        memory[ds*16 + 0x856e] = r8[al];
        yield* sub_67d6();
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] += 0x000d;
        memory16set(ds, 0x9292, r16[ax]);
        r8[al] = 0x27;
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x44e0;
            break;
        }
        r8[al] = 0x03;
        pc = 0x44e2;
        break;
    case 0x44e0:
        r8[al] = 0x28;
    case 0x44e2:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = 0x0f;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        memory[ss*16 + bp - 2] = 0x01;
    case 0x44f7:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x4497;
            break;
        }
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4504() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4512;
            break;
        }
        yield* sub_ca53();
    case 0x4512:
        memory[ds*16 + 0x8551] = 0x00;
        yield* sub_828e();
        r8[al] = memory[ds*16 + 0x855e];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x452c;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x12;
        pc = 0x4564;
        break;
    case 0x452c:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xff;
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 16982];
        memory[ss*16 + bp - 1] = r8[al];
        if (r8[al] == 0x01) {
            pc = 0x454e;
            break;
        }
        pc = 0x4564;
        break;
    case 0x454e:
        r8[al] = memory[ds*16 + 0x8570];
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x4562;
            break;
        }
        r8[al] = 0x16;
        pc = 0x4564;
        break;
    case 0x4562:
        r8[al] = 0x01;
    case 0x4564:
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4571() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x457f;
            break;
        }
        yield* sub_ca53();
    case 0x457f:
        memory[ds*16 + 0x8551] = 0x00;
        yield* sub_828e();
        if (memory[ds*16 + 0x855e] != 0x07) {
            pc = 0x4597;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x13;
        pc = 0x45cf;
        break;
    case 0x4597:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 17014];
        memory[ss*16 + bp - 1] = r8[al];
        if (r8[al] == 0x02) {
            pc = 0x45b7;
            break;
        }
        pc = 0x45cf;
        break;
    case 0x45b7:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al]++;
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x45cd;
            break;
        }
        r8[al] = 0x17;
        pc = 0x45cf;
        break;
    case 0x45cd:
        r8[al] = 0x02;
    case 0x45cf:
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_45dc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x45ea;
            break;
        }
        yield* sub_ca53();
    case 0x45ea:
        memory[ds*16 + 0x8551] = 0x00;
        r8[al] = memory[ds*16 + 0x855e];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x4601;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x14;
        pc = 0x4639;
        break;
    case 0x4601:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xff;
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 17046];
        memory[ss*16 + bp - 1] = r8[al];
        if (r8[al] == 0x08) {
            pc = 0x4623;
            break;
        }
        pc = 0x4639;
        break;
    case 0x4623:
        r8[al] = memory[ds*16 + 0x8570];
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x4637;
            break;
        }
        r8[al] = 0x18;
        pc = 0x4639;
        break;
    case 0x4637:
        r8[al] = 0x08;
    case 0x4639:
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4646() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4654;
            break;
        }
        yield* sub_ca53();
    case 0x4654:
        memory[ds*16 + 0x8551] = 0x00;
        if (memory[ds*16 + 0x855e] != 0x07) {
            pc = 0x4669;
            break;
        }
        memory[ds*16 + 0x8551] = 0x1f;
        r8[al] = 0x15;
        pc = 0x46a1;
        break;
    case 0x4669:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x8570] = r8[al];
        push(r16[ax]);
        yield* sub_8aa4();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 17078];
        memory[ss*16 + bp - 1] = r8[al];
        if (r8[al] == 0x09) {
            pc = 0x4689;
            break;
        }
        pc = 0x46a1;
        break;
    case 0x4689:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al]++;
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7921] != 0x0b) {
            pc = 0x469f;
            break;
        }
        r8[al] = 0x19;
        pc = 0x46a1;
        break;
    case 0x469f:
        r8[al] = 0x09;
    case 0x46a1:
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_46ae() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x46ba;
            break;
        }
        yield* sub_ca53();
    case 0x46ba:
        r8[al] = 0x00;
        memory[ds*16 + 0x7923] = r8[al];
        memory[ds*16 + 0xa1a7] = r8[al];
        memory[ds*16 + 0x79b9] = 0x0b;
        if (memory[ds*16 + 0x7924] != 0x11) {
            pc = 0x46d8;
            break;
        }
        r8[al] = 0x2f;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        pc = 0x46db;
        break;
    case 0x46d8:
        yield* sub_46e0();
    case 0x46db:
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_46e0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x46ef;
            break;
        }
        yield* sub_ca53();
    case 0x46ef:
        if (memory[ds*16 + 0x8552] == 0x03) {
            pc = 0x4732;
            break;
        }
        if (memory[ds*16 + 0x8552] == 0x0d) {
            pc = 0x4732;
            break;
        }
        if (memory[ds*16 + 0x8552] == 0x10) {
            pc = 0x4732;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x4718;
            break;
        }
        r8[al] = memory[ds*16 + 0x7922];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 9886];
        pc = 0x4723;
        break;
    case 0x4718:
        r8[al] = memory[ds*16 + 0x7922];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 9838];
    case 0x4723:
        memory[ss*16 + bp - 4] = r8[al];
        if (memory[ss*16 + bp - 4] == 0x00) {
            pc = 0x4732;
            break;
        }
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x4732:
        if (memory[ds*16 + 0x856e] >= 0x08) {
            pc = 0x4741;
            break;
        }
        r8[al] = 0x06;
        push(r16[ax]);
        yield* sub_6133();
        pc = 0x47aa;
        break;
    case 0x4741:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xf8;
        memory[ds*16 + 0x856f] = r8[al];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 1] = r8[al];
        memory[ds*16 + 0x79b9] = r8[al];
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 1898];
        memory[ss*16 + bp - 2] = r8[al];
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 1899];
        memory[ss*16 + bp - 3] = r8[al];
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        if (memory[ds*16 + 0x792c] != 0x0a) {
            pc = 0x479d;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x4795;
            break;
        }
        r8[al] = 0x14;
        pc = 0x4797;
        break;
    case 0x4795:
        r8[al] = 0x09;
    case 0x4797:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x479d:
        if (memory[ss*16 + bp - 3] == 0x00) {
            pc = 0x47ac;
            break;
        }
        r8[al] = memory[ss*16 + bp - 3];
        push(r16[ax]);
        yield* sub_887a();
    case 0x47aa:
        sp++;
        sp++;
    case 0x47ac:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_47b0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x47bc;
            break;
        }
        yield* sub_ca53();
    case 0x47bc:
        r8[al] = 0x04;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_47c9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x47d5;
            break;
        }
        yield* sub_ca53();
    case 0x47d5:
        memory[ds*16 + 0x824c] = 0x08;
        if (memory[ds*16 + 0x79b4] != 0x00) {
            pc = 0x47e8;
            break;
        }
        if (memory[ds*16 + 0x7924] != 0x00) {
            pc = 0x47fe;
            break;
        }
    case 0x47e8:
        memory[ds*16 + 0x79b4] = 0x00;
        if (memory[ds*16 + 0x856e] >= 0x28) {
            pc = 0x47f9;
            break;
        }
        yield* sub_47b0();
        pc = 0x4833;
        break;
    case 0x47f9:
        yield* sub_61a9();
        pc = 0x4833;
        break;
    case 0x47fe:
        if (memory[ds*16 + 0x7924] != 0x20) {
            pc = 0x4818;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x4810;
            break;
        }
        r8[al] = 0x03;
        pc = 0x4812;
        break;
    case 0x4810:
        r8[al] = 0x28;
    case 0x4812:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x4818:
        if (memory[ds*16 + 0x7924] != 0x16) {
            pc = 0x4824;
            break;
        }
        yield* sub_61d5();
        pc = 0x4833;
        break;
    case 0x4824:
        if (memory[ds*16 + 0x7924] != 0x03) {
            pc = 0x4830;
            break;
        }
        yield* sub_650d();
        pc = 0x4833;
        break;
    case 0x4830:
        yield* sub_4835();
    case 0x4833:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4835() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4841;
            break;
        }
        yield* sub_ca53();
    case 0x4841:
        if (!(memory[ds*16 + 0x8244] & 0x04)) {
            pc = 0x484d;
            break;
        }
        yield* sub_654d();
        pc = 0x4874;
        break;
    case 0x484d:
        if (!(memory[ds*16 + 0x8244] & 0x08)) {
            pc = 0x4859;
            break;
        }
        yield* sub_656c();
        pc = 0x4874;
        break;
    case 0x4859:
        if (memory[ds*16 + 0x7924] != 0x0a) {
            pc = 0x4865;
            break;
        }
        yield* sub_669b();
        pc = 0x4874;
        break;
    case 0x4865:
        if (memory[ds*16 + 0x7924] != 0x0f) {
            pc = 0x4871;
            break;
        }
        yield* sub_66d2();
        pc = 0x4874;
        break;
    case 0x4871:
        yield* sub_4876();
    case 0x4874:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4876() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4882;
            break;
        }
        yield* sub_ca53();
    case 0x4882:
        if (memory[ds*16 + 0x856e] >= 0x08) {
            pc = 0x488e;
            break;
        }
        yield* sub_652e();
        pc = 0x48d8;
        break;
    case 0x488e:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xf8;
        memory[ds*16 + 0x856f] = r8[al];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx]] == 0x0e) {
            pc = 0x48a9;
            break;
        }
        yield* sub_652e();
        pc = 0x48d8;
        break;
    case 0x48a9:
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x48b5;
            break;
        }
        yield* sub_440f();
        pc = 0x48d8;
        break;
    case 0x48b5:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x48c0;
            break;
        }
        r8[al] = 0x14;
        pc = 0x48c2;
        break;
    case 0x48c0:
        r8[al] = 0x09;
    case 0x48c2:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = 0x24;
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
        r8[al] = 0x0a;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
    case 0x48d8:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_48da() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x48ea;
            break;
        }
        yield* sub_ca53();
    case 0x48ea:
        di = 0;
        pc = 0x493d;
        break;
    case 0x48ee:
        si = 0;
        pc = 0x4932;
        break;
    case 0x48f2:
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(di);
        push(si);
        yield* sub_2a58();
        sp += 0x0006;
        r16[ax] = si;
        r16[dx] = 0x0027;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0x6bca);
        es = memory16get(ds, 0x6bca + 2);
        r16[bx] += r16[ax];
        r16[ax] = di;
        r16[ax] = sar16(r16[ax], 1);
        r16[dx] = 0x0003;
        imul16(r16[dx]);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 32];
        memory[ss*16 + bp - 1] = r8[al];
        if (!r8[al]) {
            pc = 0x4931;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(di);
        push(si);
        r8[al] = memory[ss*16 + bp - 1];
        push(r16[ax]);
        yield* sub_2960();
        sp += 0x0008;
    case 0x4931:
        si++;
    case 0x4932:
        if (signed16(si) < signed16(0x0014)) {
            pc = 0x48f2;
            break;
        }
        r16[ax] = di;
        r16[ax]++;
        r16[ax]++;
        di = r16[ax];
    case 0x493d:
        if (signed16(di) < signed16(0x001a)) {
            pc = 0x48ee;
            break;
        }
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4948() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0014;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4959;
            break;
        }
        yield* sub_ca53();
    case 0x4959:
        memory[ds*16 + 0x4c40] = 0x00;
        memory[ds*16 + 0x4c4c] = 0x00;
        memory[ds*16 + 0x4c58] = 0x00;
        memory[ds*16 + 0x4c80] = 0x00;
        memory[ds*16 + 0x4c8c] = 0x00;
        memory[ds*16 + 0x4c98] = 0x00;
        memory[ds*16 + 0x4ca4] = 0x00;
        r16[ax] = memory16get(ds, 0x4c72);
        r16[dx] = memory16get(ds, 0x4c70);
        memory16set(ss, bp - 16, r16[dx]);
        memory16set(ss, bp - 14, r16[ax]);
        r16[ax] = memory16get(ds, 0x4cbe);
        r16[dx] = memory16get(ds, 0x4cbc);
        memory16set(ss, bp - 20, r16[dx]);
        memory16set(ss, bp - 18, r16[ax]);
        r16[bx] = memory16get(ss, bp - 16);
        es = memory16get(ss, bp - 16 + 2);
        r8[al] = 0x01;
        memory[es*16 + r16[bx]] = r8[al];
        memory[ds*16 + 0x8e8b] = r8[al];
        r16[bx] = memory16get(ss, bp - 20);
        es = memory16get(ss, bp - 20 + 2);
        r8[al] = 0x01;
        memory[es*16 + r16[bx]] = r8[al];
        memory[ds*16 + 0x8e8c] = r8[al];
        r16[bx] = memory16get(ss, bp - 16);
        es = memory16get(ss, bp - 16 + 2);
        r8[al] = 0x01;
        memory[es*16 + r16[bx] + 6] = r8[al];
        memory[ds*16 + 0x8578] = r8[al];
        r16[bx] = memory16get(ss, bp - 20);
        es = memory16get(ss, bp - 20 + 2);
        r8[al] = 0x01;
        memory[es*16 + r16[bx] + 6] = r8[al];
        memory[ds*16 + 0x8579] = r8[al];
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r8[al] = memory[es*16 + r16[bx] + 144];
        memory[ds*16 + 0x856e] = r8[al];
        if (memory[ds*16 + 0x856e] == 0x00) {
            pc = 0x49db;
            break;
        }
        memory[ds*16 + 0x856e] -= 1;
    case 0x49db:
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r8[al] = memory[es*16 + r16[bx] + 145];
        memory[ds*16 + 0x8572] = r8[al];
        if (memory[ds*16 + 0x8572] == 0x00) {
            pc = 0x49f2;
            break;
        }
        memory[ds*16 + 0x8572] -= 1;
    case 0x49f2:
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r8[al] = memory[es*16 + r16[bx] + 146];
        memory[ds*16 + 0xa0cf] = r8[al];
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r8[al] = memory[es*16 + r16[bx] + 147];
        r8[al] += 0xff;
        memory[ds*16 + 0x8571] = r8[al];
        r8[al] = memory[es*16 + r16[bx] + 149];
        memory[ds*16 + 0x7920] = r8[al];
        r8[al] = memory[es*16 + r16[bx] + 148];
        memory[ds*16 + 0x8562] = r8[al];
        r8[al] = memory[es*16 + r16[bx] + 150];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 9542);
        memory16set(ds, 0xa0de, r16[ax]);
        yield* sub_670c();
        memory[ss*16 + bp - 2] = 0x00;
        pc = 0x4bbd;
        break;
    case 0x4a38:
        memory[ss*16 + bp - 1] = 0x00;
        pc = 0x4bb1;
        break;
    case 0x4a3f:
        r8[al] = memory[ss*16 + bp - 2];
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[al] += memory[ss*16 + bp - 1];
        memory[ss*16 + bp - 3] = r8[al];
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r8[dl] = memory[ss*16 + bp - 1];
        r8[dh] = 0x00;
        r16[ax] += r16[dx];
        es = memory16get(ds, 0xa0da);
        r16[ax] += memory16get(ds, 0xa0d8);
        r16[bx] = r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[ah] = 0x00;
        si = r16[ax];
        if (!r16[ax]) {
            pc = 0x4abb;
            break;
        }
        r8[al] = memory[ds*16 + si + 15674];
        r8[ah] = 0x00;
        si = r16[ax];
        r16[bx] = si;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 15724);
        r16[dx] = memory16get(ds, r16[bx] + 15722);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ss, bp - 16);
        es = memory16get(ss, bp - 16 + 2);
        r8[al] = memory[ss*16 + bp - 3];
        memory[es*16 + r16[bx] + 1] = r8[al];
        push(es);
        di = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r16[ax] = memory16get(es, di);
        es = pop();
        memory16set(es, r16[bx] + 8, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r16[ax] = memory16get(es, r16[bx] + 2);
        r16[bx] = memory16get(ss, bp - 16);
        es = memory16get(ss, bp - 16 + 2);
        memory16set(es, r16[bx] + 10, r16[ax]);
        yield* sub_352e();
        yield* sub_3937();
    case 0x4abb:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 48];
        r8[ah] = 0x00;
        si = r16[ax];
        if (!r16[ax]) {
            pc = 0x4b2b;
            break;
        }
        if (memory[ss*16 + bp - 1] == 0x07) {
            pc = 0x4b2b;
            break;
        }
        r8[al] = memory[ds*16 + si + 16518];
        r8[ah] = 0x00;
        si = r16[ax];
        r16[bx] = si;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[ax] = memory16get(ds, r16[bx] + 16552);
        r16[dx] = memory16get(ds, r16[bx] + 16550);
        memory16set(ss, bp - 12, r16[dx]);
        memory16set(ss, bp - 10, r16[ax]);
        r16[bx] = memory16get(ss, bp - 20);
        es = memory16get(ss, bp - 20 + 2);
        r8[al] = memory[ss*16 + bp - 3];
        memory[es*16 + r16[bx] + 1] = r8[al];
        push(es);
        di = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r16[ax] = memory16get(es, di);
        es = pop();
        memory16set(es, r16[bx] + 8, r16[ax]);
        r16[bx] = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        r16[ax] = memory16get(es, r16[bx] + 2);
        r16[bx] = memory16get(ss, bp - 20);
        es = memory16get(ss, bp - 20 + 2);
        memory16set(es, r16[bx] + 10, r16[ax]);
        yield* sub_3697();
        yield* sub_39fb();
    case 0x4b2b:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 96];
        r8[ah] = 0x00;
        si = r16[ax];
        if (!r16[ax]) {
            pc = 0x4bae;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r8[dl] = memory[ss*16 + bp - 2];
        r8[dh] = 0x00;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[ax] += r16[dx];
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 628);
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx], r16[ax]);
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r8[dl] = memory[ss*16 + bp - 2];
        r8[dh] = 0x00;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[ax] += r16[dx];
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 630);
        r16[bx] = memory16get(ds, 0x8884);
        memory16set(es, r16[bx] + 2, r16[ax]);
        r16[ax] = si;
        r16[ax] += 0x0179;
        memory16set(es, r16[bx] + 4, r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x4bae:
        memory[ss*16 + bp - 1] += 1;
    case 0x4bb1:
        if (memory[ss*16 + bp - 1] >= 0x08) {
            pc = 0x4bba;
            break;
        }
        pc = 0x4a3f;
        break;
    case 0x4bba:
        memory[ss*16 + bp - 2] += 1;
    case 0x4bbd:
        if (memory[ss*16 + bp - 2] >= 0x06) {
            pc = 0x4bc6;
            break;
        }
        pc = 0x4a38;
        break;
    case 0x4bc6:
        r16[bx] = memory16get(ss, bp - 16);
        es = memory16get(ss, bp - 16 + 2);
        r8[al] = 0x00;
        memory[es*16 + r16[bx] + 6] = r8[al];
        memory[es*16 + r16[bx]] = r8[al];
        r16[bx] = memory16get(ss, bp - 20);
        es = memory16get(ss, bp - 20 + 2);
        r8[al] = 0x00;
        memory[es*16 + r16[bx] + 6] = r8[al];
        memory[es*16 + r16[bx]] = r8[al];
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4be4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4bf4;
            break;
        }
        yield* sub_ca53();
    case 0x4bf4:
        memory[ss*16 + bp - 5] = 0x01;
        if (memory[ds*16 + 0x79b2] <= 0x01) {
            pc = 0x4c0b;
            break;
        }
        r8[al] = memory[ds*16 + 0x119a];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x4c0b;
            break;
        }
    case 0x4c0b:
        if (memory[ds*16 + 0x119a] != 0xff) {
            pc = 0x4c17;
            break;
        }
        memory[ds*16 + 0x79b2] = 0x01;
    case 0x4c17:
        r8[al] = memory[ds*16 + 0x79b2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 4298);
        r16[dx] = memory16get(ds, r16[bx] + 4296);
        memory16set(ds, 0x8246, r16[dx]);
        memory16set(ds, 0x8248, r16[ax]);
        r8[al] = memory[ds*16 + 0x79b2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 4334);
        r16[dx] = memory16get(ds, r16[bx] + 4332);
        memory16set(ds, 0x8554, r16[dx]);
        memory16set(ds, 0x8556, r16[ax]);
        memory[ds*16 + 0x854e] = 0x01;
        r16[ax] = 0x001f;
        memory16set(ds, 0x791e, r16[ax]);
        memory16set(ds, 0x791c, r16[ax]);
        if (memory[ds*16 + 0x79b2] == 0x02) {
            pc = 0x4c67;
            break;
        }
        if (memory[ds*16 + 0x79b2] != 0x05) {
            pc = 0x4c86;
            break;
        }
    case 0x4c67:
        memory16set(ds, 0x791c, 0x006f);
        pc = 0x4c86;
        break;
    case 0x4c6f:
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[dx] = 0x0009;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0x8246);
        es = memory16get(ds, 0x8246 + 2);
        r16[bx] += r16[ax];
        memory[es*16 + r16[bx]] = 0x00;
        memory[ss*16 + bp - 5] += 1;
    case 0x4c86:
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[dx] = 0x0009;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0x8246);
        es = memory16get(ds, 0x8246 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx]] != 0xff) {
            pc = 0x4c6f;
            break;
        }
        push(ds);
        r16[ax] = 0x0090;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x0090);
        es = memory16get(ds, 0x0090 + 2);
        r8[al] = memory[ds*16 + 0x79b2];
        r8[al] += 0x30;
        memory[es*16 + r16[bx] + 1] = r8[al];
        r16[bx] = memory16get(ds, 0x009a);
        es = memory16get(ds, 0x009a + 2);
        r8[al] = memory[ds*16 + 0x79b2];
        r8[al] += 0x30;
        memory[es*16 + r16[bx] + 1] = r8[al];
        r16[bx] = memory16get(ds, 0x00e0);
        es = memory16get(ds, 0x00e0 + 2);
        r8[al] = memory[ds*16 + 0x79b2];
        r8[al] += 0x30;
        memory[es*16 + r16[bx] + 1] = r8[al];
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x0098));
        push(memory16get(ds, 0x0096));
        push(memory16get(ds, 0x6fa8));
        push(memory16get(ds, 0x6fa6));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        push(memory16get(ds, 0x0098));
        push(memory16get(ds, 0x0096));
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        push(memory16get(ds, 0x6fa8));
        push(memory16get(ds, 0x6fa6));
        yield* sub_9a2a();
        sp += 0x000c;
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x00a2));
        push(memory16get(ds, 0x00a0));
        push(memory16get(ds, 0x6bea));
        push(memory16get(ds, 0x6be8));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        push(memory16get(ds, 0x00a2));
        push(memory16get(ds, 0x00a0));
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        push(memory16get(ds, 0x6bea));
        push(memory16get(ds, 0x6be8));
        yield* sub_9a2a();
        sp += 0x000c;
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0008;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x00e8));
        push(memory16get(ds, 0x00e6));
        push(memory16get(ds, 0x75e0));
        push(memory16get(ds, 0x75de));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        push(memory16get(ds, 0x00e8));
        push(memory16get(ds, 0x00e6));
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        push(memory16get(ds, 0x75e0));
        push(memory16get(ds, 0x75de));
        yield* sub_9a2a();
        sp += 0x000c;
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4dc8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4dd8;
            break;
        }
        yield* sub_ca53();
    case 0x4dd8:
        push(ds);
        r16[ax] = 0x0928;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        yield* sub_4e7c();
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x0930));
        push(memory16get(ds, 0x092e));
        push(memory16get(ds, 0xa0c8));
        push(memory16get(ds, 0xa0c6));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        push(memory16get(ds, 0xa0c8));
        push(memory16get(ds, 0xa0c6));
        yield* sub_b2a8();
        sp += 0x0004;
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x093a));
        push(memory16get(ds, 0x0938));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        r16[ax] = 0;
        r16[dx] = 0x7d63;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9a2a();
        sp += 0x000c;
        yield* sub_70a8();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4e7c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4e8d;
            break;
        }
        yield* sub_ca53();
    case 0x4e8d:
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x0944));
        push(memory16get(ds, 0x0942));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        r16[ax] = 0;
        r16[dx] = 0x7d63;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9a2a();
        sp += 0x000c;
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x4f1c;
            break;
        }
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(ds, 0x9b96, r16[dx]);
        memory16set(ds, 0x9b98, r16[ax]);
        memory[ss*16 + bp - 5] = 0x00;
        pc = 0x4f16;
        break;
    case 0x4ef9:
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 1594];
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 5] += 1;
    case 0x4f16:
        if (memory[ss*16 + bp - 5] < 0x10) {
            pc = 0x4ef9;
            break;
        }
    case 0x4f1c:
        yield* sub_5337();
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        r16[dx] += 0x0063;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0014);
        memory16set(es, r16[bx] + 32, 0x0019);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f8c();
        sp += 0x0004;
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        yield* sub_b734();
        yield* sub_4fad();
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_4fad() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x4fbc;
            break;
        }
        yield* sub_ca53();
    case 0x4fbc:
        memory[ss*16 + bp - 1] = 0x00;
        r16[ax] = 0x0004;
        push(r16[ax]);
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x0958));
        push(memory16get(ds, 0x0956));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0005;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x0962));
        push(memory16get(ds, 0x0960));
        push(memory16get(ds, 0xa0c8));
        push(memory16get(ds, 0xa0c6));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        if (memory16get(ds, 0x689c) == 0x8000) {
            pc = 0x508d;
            break;
        }
        pc = 0x506c;
        break;
    case 0x5027:
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        push(memory16get(ds, 0xa0c8));
        push(memory16get(ds, 0xa0c6));
        yield* sub_a847();
        sp += 0x000a;
        pc = 0x505c;
        break;
    case 0x5043:
        r16[ax] = memory16get(ds, 0x119c);
        r16[ax] += 0x0007;
        memory16set(ds, 0x119c, r16[ax]);
        r8[al] = 0x00;
        push(r16[ax]);
        yield* sub_9472();
        sp++;
        sp++;
        if (!(r8[al] & 0x10)) {
            pc = 0x505c;
            break;
        }
        memory[ss*16 + bp - 1] = 0x01;
    case 0x505c:
        yield* sub_a869();
        if (!r16[ax]) {
            pc = 0x506c;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x5043;
            break;
        }
    case 0x506c:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x5027;
            break;
        }
        yield* sub_a878();
        if (memory16get(ds, 0x689c) != 0x0000) {
            pc = 0x50a9;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9ce8();
        sp++;
        sp++;
        yield* sub_b33e();
        pc = 0x50a9;
        break;
    case 0x508d:
        memory[ds*16 + 0x8244] = 0x00;
        pc = 0x50a0;
        break;
    case 0x5094:
        bumpyScene = "splash";
        yield* sync();
        yield* sub_3cae();
        r16[ax] = memory16get(ds, 0x119c);
        r16[ax] += 0x0007;
        memory16set(ds, 0x119c, r16[ax]);
    case 0x50a0:
        r8[al] = memory[ds*16 + 0x8244];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x5094;
            break;
        }
    case 0x50a9:
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_50ae() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x50ba;
            break;
        }
        yield* sub_ca53();
    case 0x50ba:
        memory[ds*16 + 0x8242] = 0x00;
        memory[ds*16 + 0x792a] = 0x00;
        memory16set(ds, 0x824a, 0x0000);
        memory[ds*16 + 0xa0ce] = 0x00;
        r8[al] = 0x00;
        memory[ds*16 + 0x8578] = r8[al];
        memory[ds*16 + 0x8e8b] = r8[al];
        r8[al] = 0x00;
        memory[ds*16 + 0x8579] = r8[al];
        memory[ds*16 + 0x8e8c] = r8[al];
        memory[ds*16 + 0x8244] = 0x00;
        memory[ds*16 + 0xa1a7] = 0x00;
        memory[ds*16 + 0x79b4] = 0x00;
        memory[ds*16 + 0x7923] = 0x00;
        memory[ds*16 + 0x824c] = 0x00;
        memory[ds*16 + 0xa1a8] = 0x00;
        memory[ds*16 + 0xa1b1] = 0x00;
        memory[ds*16 + 0x8550] = 0x00;
        memory[ds*16 + 0x8563] = 0x00;
        memory[ds*16 + 0xa1b0] = 0x00;
        memory[ds*16 + 0x8243] = 0x00;
        memory[ds*16 + 0x79b7] = 0x00;
        memory16set(ds, 0x9ba6, 0x0886);
        memory16set(ds, 0x9ba8, ds);
        r16[bx] = memory16get(ds, 0x9ba6);
        es = memory16get(ds, 0x9ba6 + 2);
        memory[es*16 + r16[bx]] = 0xff;
        yield* sub_67d6();
        yield* sub_6779();
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] += 0xfff4;
        memory16set(ds, 0x9292, r16[ax]);
        memory[ds*16 + 0x792c] = 0x00;
        memory16set(ds, 0xa1ac, 0x1394);
        memory16set(ds, 0xa1ae, ds);
        memory[ds*16 + 0x824d] = 0x0a;
        r8[al] = 0x04;
        memory[ds*16 + 0x9bae] = r8[al];
        memory[ds*16 + 0x792a] = r8[al];
        memory[ds*16 + 0xa1a9] = 0x00;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_515f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sync();
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x516b;
            break;
        }
        yield* sub_ca53();
    case 0x516b:
        memory[ds*16 + 0x8244] = 0x00;
        pc = 0x5175;
        break;
    case 0x5172:
        yield* sync();
        yield* sub_3cae();
    case 0x5175:
        r8[al] = memory[ds*16 + 0x8244];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x5172;
            break;
        }
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5180() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x518c;
            break;
        }
        yield* sub_ca53();
    case 0x518c:
        r16[ax] = memory16get(ds, 0x7310);
        r16[dx] = 0x00c2;
        imul16(r16[dx]);
        r16[dx] = memory16get(ds, 0x6bf4);
        r16[bx] = memory16get(ds, 0x6bf2);
        r16[bx] += r16[ax];
        memory16set(ds, 0x75d0, r16[bx]);
        memory16set(ds, 0x75d2, r16[dx]);
        r16[ax] = memory16get(ds, 0x7310);
        r16[dx] = 0x032c;
        imul16(r16[dx]);
        r16[dx] = memory16get(ds, 0x6bd4);
        r16[bx] = memory16get(ds, 0x6bd2);
        r16[bx] += r16[ax];
        memory16set(ds, 0x6bca, r16[bx]);
        memory16set(ds, 0x6bcc, r16[dx]);
        memory16set(ds, 0xa0d8, 0xa0e4);
        memory16set(ds, 0xa0da, ds);
        r8[cl] = 0x00;
        pc = 0x5222;
        break;
    case 0x51ce:
        r8[al] = r8[cl];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[dl] = r8[cl];
        r8[dh] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[dx];
        memory[es*16 + r16[bx]] = r8[al];
        r8[al] = r8[cl];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 48];
        r8[dl] = r8[cl];
        r8[dh] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[dx];
        memory[es*16 + r16[bx] + 48] = r8[al];
        r8[al] = r8[cl];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 96];
        r8[dl] = r8[cl];
        r8[dh] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[dx];
        memory[es*16 + r16[bx] + 96] = r8[al];
        r8[cl]++;
    case 0x5222:
        if (r8[cl] < 0x30) {
            pc = 0x51ce;
            break;
        }
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r8[al] = memory[es*16 + r16[bx] + 144];
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        memory[es*16 + r16[bx] + 144] = r8[al];
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r8[al] = memory[es*16 + r16[bx] + 145];
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        memory[es*16 + r16[bx] + 145] = r8[al];
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r8[al] = memory[es*16 + r16[bx] + 146];
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        memory[es*16 + r16[bx] + 146] = r8[al];
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r8[al] = memory[es*16 + r16[bx] + 147];
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        memory[es*16 + r16[bx] + 147] = r8[al];
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r8[al] = memory[es*16 + r16[bx] + 148];
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        memory[es*16 + r16[bx] + 148] = r8[al];
        r16[bx] = memory16get(ds, 0x75d0);
        es = memory16get(ds, 0x75d0 + 2);
        r8[al] = memory[es*16 + r16[bx] + 149];
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        memory[es*16 + r16[bx] + 149] = r8[al];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5295() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x52a1;
            break;
        }
        yield* sub_ca53();
    case 0x52a1:
        memory16set(ds, 0x8884, 0x792e);
        memory16set(ds, 0x8886, ds);
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r16[ax] = memory16get(ds, 0xa0c8);
        r16[dx] = memory16get(ds, 0xa0c6);
        memory16set(es, r16[bx] + 6, r16[dx]);
        memory16set(es, r16[bx] + 8, r16[ax]);
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] | 0x80;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xbf;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xdf;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xef;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xf7;
        memory16set(ds, 0x9b9e, 0x795a);
        memory16set(ds, 0x9ba0, ds);
        r16[bx] = memory16get(ds, 0x9b9e);
        es = memory16get(ds, 0x9b9e + 2);
        memory16set(es, r16[bx] + 6, r16[dx]);
        memory16set(es, r16[bx] + 8, r16[ax]);
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] | 0x80;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xbf;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xdf;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xef;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xf7;
        memory16set(ds, 0xa0d0, 0x7986);
        memory16set(ds, 0xa0d2, ds);
        r16[bx] = memory16get(ds, 0xa0d0);
        es = memory16get(ds, 0xa0d0 + 2);
        memory16set(es, r16[bx] + 6, r16[dx]);
        memory16set(es, r16[bx] + 8, r16[ax]);
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] | 0x80;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xbf;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xdf;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xef;
        memory[es*16 + r16[bx] + 10] = memory[es*16 + r16[bx] + 10] & 0xf7;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5337() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0068;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5347;
            break;
        }
        yield* sub_ca53();
    case 0x5347:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory[es*16 + r16[bx] + 34] = 0x00;
        memory[es*16 + r16[bx] + 35] = 0x00;
        memory[es*16 + r16[bx] + 36] = 0x00;
        memory[es*16 + r16[bx] + 37] = 0x00;
        memory16set(es, r16[bx] + 14, 0x0000);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory[ss*16 + bp - 2] = 0x14;
        memory[ss*16 + bp - 3] = 0x19;
        memory[ss*16 + bp - 1] = 0x00;
        pc = 0x5436;
        break;
    case 0x537a:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        memory16set(es, r16[bx] + 20, r16[ax]);
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        memory16set(es, r16[bx] + 22, r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        memory16set(es, r16[bx] + 30, r16[ax]);
        memory16set(es, r16[bx] + 32, 0x0001);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9a1a();
        sp += 0x0004;
        yield* sub_b734();
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[dx] = 0x0018;
        r16[dx] -= r16[ax];
        memory16set(es, r16[bx] + 22, r16[dx]);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9a1a();
        sp += 0x0004;
        yield* sub_b734();
        r8[al] = memory[ss*16 + bp - 2];
        r8[al] += 0xfe;
        memory[ss*16 + bp - 2] = r8[al];
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        memory16set(es, r16[bx] + 22, r16[ax]);
        memory16set(es, r16[bx] + 30, 0x0001);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        memory16set(es, r16[bx] + 32, r16[ax]);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9a1a();
        sp += 0x0004;
        yield* sub_b734();
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[dx] = 0x0013;
        r16[dx] -= r16[ax];
        memory16set(es, r16[bx] + 20, r16[dx]);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9a1a();
        sp += 0x0004;
        yield* sub_b734();
        r8[al] = memory[ss*16 + bp - 3];
        r8[al] += 0xfe;
        memory[ss*16 + bp - 3] = r8[al];
        memory[ss*16 + bp - 1] += 1;
    case 0x5436:
        if (memory[ss*16 + bp - 1] > 0x09) {
            pc = 0x543f;
            break;
        }
        pc = 0x537a;
        break;
    case 0x543f:
        si = 0;
        pc = 0x5452;
        break;
    case 0x5443:
        r16[bx] = si;
        r16[bx] <<= 1;
        r16[ax] = bp - 0x68;
        r16[bx] += r16[ax];
        memory16set(ss, r16[bx], 0x0000);
        si++;
    case 0x5452:
        if (si < 0x0032) {
            pc = 0x5443;
            break;
        }
        r16[ax] = 0;
        push(r16[ax]);
        push(ss);
        r16[ax] = bp - 0x68;
        push(r16[ax]);
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        yield* sub_b734();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5475() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000c;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5486;
            break;
        }
        yield* sub_ca53();
    case 0x5486:
        memory[ss*16 + bp - 5] = 0x00;
        memory[ss*16 + bp - 6] = 0xff;
        push(ss);
        r16[ax] = bp - 0xa;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x11b2;
        push(r16[ax]);
        r16[cx] = 0x0003;
        yield* sub_c8c5();
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0012;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x09e4));
        push(memory16get(ds, 0x09e2));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        r16[ax] = 0;
        r16[dx] = 0x7d63;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9a2a();
        sp += 0x000c;
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x552d;
            break;
        }
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(ds, 0x9b96, r16[dx]);
        memory16set(ds, 0x9b98, r16[ax]);
        memory[ss*16 + bp - 11] = 0x00;
        pc = 0x5527;
        break;
    case 0x550a:
        r8[al] = memory[ss*16 + bp - 11];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 11];
        r8[ah] = 0x00;
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 1610];
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 11] += 1;
    case 0x5527:
        if (memory[ss*16 + bp - 11] < 0x10) {
            pc = 0x550a;
            break;
        }
    case 0x552d:
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r16[ax] = memory16get(ds, 0x6c2e);
        r16[dx] = memory16get(ds, 0x6c2c);
        memory16set(es, r16[bx] + 6, r16[dx]);
        memory16set(es, r16[bx] + 8, r16[ax]);
        r8[al] = 0x00;
        memory[ds*16 + 0x854f] = r8[al];
        memory[ds*16 + 0x8244] = r8[al];
        yield* sub_5337();
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        r16[dx] += 0x0063;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0014);
        memory16set(es, r16[bx] + 32, 0x0019);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f8c();
        sp += 0x0004;
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        pc = 0x56d9;
        break;
    case 0x55cf:
        bumpyScene = "menu";
        r8[al] = memory[ds*16 + 0x79b5];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 1888);
        r16[dx] = memory16get(ds, r16[bx] + 1886);
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0006);
        memory16set(es, r16[bx] + 12, 0x0002);
        memory16set(es, r16[bx] + 20, 0x000b);
        memory16set(es, r16[bx] + 22, 0x0012);
        memory16set(es, r16[bx] + 30, 0x0006);
        memory16set(es, r16[bx] + 32, 0x0002);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f8c();
        sp += 0x0004;
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_7051();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 4, 0x0000);
        memory16set(es, r16[bx], 0x0030);
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[ax] += 0x0070;
        memory16set(es, r16[bx] + 2, r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        yield* sub_b734();
        yield* sub_3cae();
        if (!(memory[ds*16 + 0x8244] & 0x01)) {
            pc = 0x5684;
            break;
        }
        if (memory[ss*16 + bp - 5] == 0x00) {
            pc = 0x5684;
            break;
        }
        memory[ss*16 + bp - 5] -= 1;
        pc = 0x56c8;
        break;
    case 0x5684:
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x5696;
            break;
        }
        if (memory[ss*16 + bp - 5] >= 0x03) {
            pc = 0x5696;
            break;
        }
        memory[ss*16 + bp - 5] += 1;
        pc = 0x56c8;
        break;
    case 0x5696:
        if (!(memory[ds*16 + 0x8244] & 0x10)) {
            pc = 0x56c8;
            break;
        }
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        if (r16[bx] > 0x0003) {
            pc = 0x56c8;
            break;
        }
        r16[bx] <<= 1;
        switch (r16[bx])
        {
        case 0: pc = 0x56b0; break;
        case 2: pc = 0x56b0; break;
        case 4: pc = 0x56b8; break;
        case 6: pc = 0x56b0; break;
            default:
            assert(0);
        }
        break;
    case 0x56b0:
        r8[al] = memory[ss*16 + bp - 5];
        memory[ss*16 + bp - 6] = r8[al];
        pc = 0x56c8;
        break;
    case 0x56b8:
        memory[ds*16 + 0x79b5] += 1;
        if (memory[ds*16 + 0x79b5] != 0x03) {
            pc = 0x56c8;
            break;
        }
        memory[ds*16 + 0x79b5] = 0x00;
    case 0x56c8:
        memory[ds*16 + 0x8244] = 0x00;
    case 0x56cd:
        r8[al] = 0x00;
        push(r16[ax]);
        yield* sub_9472();
        sp++;
        sp++;
        if (r8[al])
            {
            yield* sync();
            pc = 0x56cd;
            break;
        }
    case 0x56d9:
        if (memory[ss*16 + bp - 6] != 0xff) {
            pc = 0x56e2;
            break;
        }
        pc = 0x55cf;
        break;
    case 0x56e2:
        r8[al] = memory[ds*16 + 0x79b5];
        r8[ah] = 0x00;
        r16[dx] = bp - 0xa;
        r16[ax] += r16[dx];
        r16[bx] = r16[ax];
        r8[al] = memory[ss*16 + r16[bx]];
        memory[ds*16 + 0x854f] = r8[al];
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r16[ax] = memory16get(ds, 0xa0c8);
        r16[dx] = memory16get(ds, 0xa0c6);
        memory16set(es, r16[bx] + 6, r16[dx]);
        memory16set(es, r16[bx] + 8, r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        r8[al] = memory[ss*16 + bp - 6];
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5722() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000a;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5732;
            break;
        }
        yield* sub_ca53();
    case 0x5732:
        memory[ss*16 + bp - 5] = 0x00;
        r8[al] = memory[ds*16 + 0x854f];
        memory[ds*16 + 0x8e8a] = r8[al];
        memory[ds*16 + 0x854f] = 0x00;
        memory[ds*16 + 0x8244] = 0x00;
        push(ds);
        r16[ax] = 0x0928;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        r16[ax] = 0x0004;
        push(r16[ax]);
        r8[al] = memory[ds*16 + 0x79b2];
        r8[ah] = 0x00;
        r16[ax] += 0x0007;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        r8[al] = memory[ds*16 + 0x79b2];
        r8[ah] = 0x00;
        r16[dx] = 0x000a;
        imul16(r16[dx]);
        r16[bx] = r16[ax];
        push(memory16get(ds, r16[bx] + 2422));
        push(memory16get(ds, r16[bx] + 2420));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        r16[ax] = 0;
        r16[dx] = 0x7d63;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9a2a();
        sp += 0x000c;
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x580c;
            break;
        }
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(ds, 0x9b96, r16[dx]);
        memory16set(ds, 0x9b98, r16[ax]);
        r8[al] = memory[ds*16 + 0x79b2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 1768);
        r16[dx] = memory16get(ds, r16[bx] + 1766);
        memory16set(ss, bp - 10, r16[dx]);
        memory16set(ss, bp - 8, r16[ax]);
        memory[ss*16 + bp - 6] = 0x00;
        pc = 0x5806;
        break;
    case 0x57e7:
        r8[al] = memory[ss*16 + bp - 6];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 10);
        es = memory16get(ss, bp - 10 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[dl] = memory[ss*16 + bp - 6];
        r8[dh] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[dx];
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 6] += 1;
    case 0x5806:
        if (memory[ss*16 + bp - 6] < 0x10) {
            pc = 0x57e7;
            break;
        }
    case 0x580c:
        yield* sub_5337();
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        r16[dx] += 0x0063;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0014);
        memory16set(es, r16[bx] + 32, 0x0019);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f8c();
        sp += 0x0004;
        r16[ax] = 0x0008;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r8[al] = 0x07;
        push(r16[ax]);
        push(memory16get(ds, 0xa0d6));
        push(memory16get(ds, 0xa0d4));
        yield* sub_26e6();
        sp += 0x000a;
        yield* sub_8000();
        yield* sub_5b1f();
        r8[al] = memory[ds*16 + 0x79b6];
        memory[ds*16 + 0x854e] = r8[al];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = memory16get(ds, 0x791c);
        memory16set(ds, 0x9290, r16[ax]);
        r16[ax] = memory16get(ds, 0x791e);
        memory16set(ds, 0x9292, r16[ax]);
        memory16set(ds, 0x824a, 0x0021);
        r16[ax] = 0;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_7051();
        sp += 0x0004;
        yield* sub_3b82();
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        yield* sub_b734();
        yield* sub_3343();
        yield* sub_325c();
        yield* sub_3aa7();
        yield* sub_325c();
        yield* sub_5958();
        pc = 0x5944;
        break;
    case 0x58ec:
        bumpyScene = "levels";
        yield* sync();
        yield* sub_3cae();
        if (!(memory[ds*16 + 0x8244] & 0x01)) {
            pc = 0x58fb;
            break;
        }
        yield* sub_5982();
        pc = 0x593f;
        break;
    case 0x58fb:
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x5907;
            break;
        }
        yield* sub_59df();
        pc = 0x593f;
        break;
    case 0x5907:
        if (!(memory[ds*16 + 0x8244] & 0x04)) {
            pc = 0x5913;
            break;
        }
        yield* sub_5a3c();
        pc = 0x593f;
        break;
    case 0x5913:
        if (!(memory[ds*16 + 0x8244] & 0x08)) {
            pc = 0x591f;
            break;
        }
        yield* sub_5a99();
        pc = 0x593f;
        break;
    case 0x591f:
        if (!(memory[ds*16 + 0x8244] & 0x10)) {
            pc = 0x592b;
            break;
        }
        yield* sub_5bc7();
        pc = 0x593c;
        break;
    case 0x592b:
        r8[al] = 0x01;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x593f;
            break;
        }
        r8[al] = 0xff;
        memory[ds*16 + 0x928d] = r8[al];
    case 0x593c:
        memory[ss*16 + bp - 5] = r8[al];
    case 0x593f:
        memory[ds*16 + 0x8244] = 0x00;
    case 0x5944:
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x58ec;
            break;
        }
        r8[al] = memory[ds*16 + 0x8e8a];
        memory[ds*16 + 0x854f] = r8[al];
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5958() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5964;
            break;
        }
        yield* sub_ca53();
    case 0x5964:
        r8[al] = memory[ds*16 + 0x854e];
        r8[ah] = 0x00;
        r16[dx] = 0x0009;
        imul16(r16[dx]);
        r16[dx] = memory16get(ds, 0x8248);
        r16[bx] = memory16get(ds, 0x8246);
        r16[bx] += r16[ax];
        memory16set(ds, 0x9baa, r16[bx]);
        memory16set(ds, 0x9bac, r16[dx]);
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5982() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5991;
            break;
        }
        yield* sub_ca53();
    case 0x5991:
        r16[ax] = memory16get(ds, 0x9bac);
        r16[dx] = memory16get(ds, 0x9baa);
        memory16set(ss, bp - 6, r16[dx]);
        memory16set(ss, bp - 4, r16[ax]);
        r16[bx] = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r8[al] = memory[es*16 + r16[bx] + 1];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x59db;
            break;
        }
        memory[ds*16 + 0x854e] = r8[al];
        yield* sub_5958();
        r16[bx] = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r8[al] = memory[es*16 + r16[bx] + 2];
        r8[ah] = 0x00;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x59d5;
        break;
    case 0x59c6:
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] += 0xfffc;
        memory16set(ds, 0x9292, r16[ax]);
        yield* sub_5af6();
        memory[ss*16 + bp - 1] -= 1;
    case 0x59d5:
        if (memory[ss*16 + bp - 1] != 0x00) {
            pc = 0x59c6;
            break;
        }
    case 0x59db:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_59df() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x59ee;
            break;
        }
        yield* sub_ca53();
    case 0x59ee:
        r16[ax] = memory16get(ds, 0x9bac);
        r16[dx] = memory16get(ds, 0x9baa);
        memory16set(ss, bp - 6, r16[dx]);
        memory16set(ss, bp - 4, r16[ax]);
        r16[bx] = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r8[al] = memory[es*16 + r16[bx] + 3];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x5a38;
            break;
        }
        memory[ds*16 + 0x854e] = r8[al];
        yield* sub_5958();
        r16[bx] = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r8[al] = memory[es*16 + r16[bx] + 4];
        r8[ah] = 0x00;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x5a32;
        break;
    case 0x5a23:
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] += 0x0004;
        memory16set(ds, 0x9292, r16[ax]);
        yield* sub_5af6();
        memory[ss*16 + bp - 1] -= 1;
    case 0x5a32:
        if (memory[ss*16 + bp - 1] != 0x00) {
            pc = 0x5a23;
            break;
        }
    case 0x5a38:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5a3c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5a4b;
            break;
        }
        yield* sub_ca53();
    case 0x5a4b:
        r16[ax] = memory16get(ds, 0x9bac);
        r16[dx] = memory16get(ds, 0x9baa);
        memory16set(ss, bp - 6, r16[dx]);
        memory16set(ss, bp - 4, r16[ax]);
        r16[bx] = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r8[al] = memory[es*16 + r16[bx] + 5];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x5a95;
            break;
        }
        memory[ds*16 + 0x854e] = r8[al];
        yield* sub_5958();
        r16[bx] = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r8[al] = memory[es*16 + r16[bx] + 6];
        r8[ah] = 0x00;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x5a8f;
        break;
    case 0x5a80:
        r16[ax] = memory16get(ds, 0x9290);
        r16[ax] += 0xfffc;
        memory16set(ds, 0x9290, r16[ax]);
        yield* sub_5af6();
        memory[ss*16 + bp - 1] -= 1;
    case 0x5a8f:
        if (memory[ss*16 + bp - 1] != 0x00) {
            pc = 0x5a80;
            break;
        }
    case 0x5a95:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5a99() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5aa8;
            break;
        }
        yield* sub_ca53();
    case 0x5aa8:
        r16[ax] = memory16get(ds, 0x9bac);
        r16[dx] = memory16get(ds, 0x9baa);
        memory16set(ss, bp - 6, r16[dx]);
        memory16set(ss, bp - 4, r16[ax]);
        r16[bx] = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r8[al] = memory[es*16 + r16[bx] + 7];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x5af2;
            break;
        }
        memory[ds*16 + 0x854e] = r8[al];
        yield* sub_5958();
        r16[bx] = memory16get(ss, bp - 6);
        es = memory16get(ss, bp - 6 + 2);
        r8[al] = memory[es*16 + r16[bx] + 8];
        r8[ah] = 0x00;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x5aec;
        break;
    case 0x5add:
        r16[ax] = memory16get(ds, 0x9290);
        r16[ax] += 0x0004;
        memory16set(ds, 0x9290, r16[ax]);
        yield* sub_5af6();
        memory[ss*16 + bp - 1] -= 1;
    case 0x5aec:
        if (memory[ss*16 + bp - 1] != 0x00) {
            pc = 0x5add;
            break;
        }
    case 0x5af2:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5af6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5b02;
            break;
        }
        yield* sub_ca53();
    case 0x5b02:
        yield* sub_325c();
        yield* sub_3343();
        yield* sub_38b4();
        yield* sub_3aa7();
        yield* sub_3b82();
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        yield* sub_3219();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5b1f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5b2d;
            break;
        }
        yield* sub_ca53();
    case 0x5b2d:
        memory[ss*16 + bp - 1] = 0x00;
        r8[al] = memory[ds*16 + 0x854e];
        memory[ds*16 + 0x79b6] = r8[al];
        memory[ds*16 + 0x854e] = 0x01;
    case 0x5b3c:
        yield* sub_5958();
        r16[bx] = memory16get(ds, 0x9baa);
        es = memory16get(ds, 0x9baa + 2);
        if (memory[es*16 + r16[bx]] != 0xff) {
            pc = 0x5b4f;
            break;
        }
        memory[ss*16 + bp - 1] = 0x01;
        pc = 0x5b5c;
        break;
    case 0x5b4f:
        r16[bx] = memory16get(ds, 0x9baa);
        es = memory16get(ds, 0x9baa + 2);
        if (memory[es*16 + r16[bx]] == 0x00) {
            pc = 0x5b5c;
            break;
        }
        yield* sub_5b6d();
    case 0x5b5c:
        memory[ds*16 + 0x854e] += 1;
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x5b3c;
            break;
        }
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5b6d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5b79;
            break;
        }
        yield* sub_ca53();
    case 0x5b79:
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 4, 0x01da);
        r8[al] = memory[ds*16 + 0x854e];
        r8[ah] = 0x00;
        r16[ax]--;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = memory16get(ds, 0x8554);
        es = memory16get(ds, 0x8554 + 2);
        r16[bx] += r16[ax];
        r16[ax] = memory16get(es, r16[bx]);
        r16[ax]--;
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx], r16[ax]);
        r8[al] = memory[ds*16 + 0x854e];
        r8[ah] = 0x00;
        r16[ax]--;
        r16[ax] <<= 1;
        r16[ax]++;
        r16[ax] <<= 1;
        r16[bx] = memory16get(ds, 0x8554);
        es = memory16get(ds, 0x8554 + 2);
        r16[bx] += r16[ax];
        r16[ax] = memory16get(es, r16[bx]);
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5bc7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5bd6;
            break;
        }
        yield* sub_ca53();
    case 0x5bd6:
        memory[ss*16 + bp - 5] = 0x00;
        memory[ds*16 + 0x792c] = 0x00;
        yield* sub_5af6();
        yield* sub_5af6();
        yield* sub_5958();
        r16[ax] = memory16get(ds, 0x9bac);
        r16[dx] = memory16get(ds, 0x9baa);
        memory16set(ss, bp - 4, r16[dx]);
        memory16set(ss, bp - 2, r16[ax]);
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x5c04;
            break;
        }
        pc = 0x5cc6;
        break;
    case 0x5c04:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x5c0f;
            break;
        }
        r8[al] = 0x03;
        pc = 0x5c11;
        break;
    case 0x5c0f:
        r8[al] = 0x28;
    case 0x5c11:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        memory[ds*16 + 0x854f] = 0xaa;
        r16[ax] = memory16get(ds, 0x9292);
        memory16set(ds, 0x791e, r16[ax]);
        r16[ax] = memory16get(ds, 0x9290);
        memory16set(ds, 0x791c, r16[ax]);
        memory16set(ds, 0xa1ac, 0x1114);
        memory16set(ds, 0xa1ae, ds);
        memory[ds*16 + 0x824d] = 0x16;
        r16[ax] = memory16get(ds, 0x9290);
        r16[ax] += 0xfff1;
        memory16set(ds, 0x9290, r16[ax]);
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] += 0x0003;
        memory16set(ds, 0x9292, r16[ax]);
        memory16set(ds, 0x824a, 0x00cb);
        yield* sub_38b4();
        yield* sub_3b82();
        yield* sub_3aa7();
        r16[ax] = memory16get(ds, 0x9290);
        r16[ax] += 0x000f;
        memory16set(ds, 0x9290, r16[ax]);
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] += 0xfffd;
        memory16set(ds, 0x9292, r16[ax]);
        memory16set(ds, 0x824a, 0x0000);
        yield* sub_325c();
        yield* sub_5ccd();
        yield* sub_3b82();
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        yield* sub_3219();
        yield* sub_38b4();
        yield* sub_3aa7();
        yield* sub_3b82();
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        yield* sub_3219();
    case 0x5c9a:
        yield* sub_325c();
        yield* sub_32af();
        yield* sub_3343();
        yield* sub_38b4();
        yield* sub_3aa7();
        yield* sub_3b82();
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        yield* sub_3219();
        if (memory[ds*16 + 0x824d] != 0x00) {
            pc = 0x5c9a;
            break;
        }
        yield* sub_5d44();
        memory[ss*16 + bp - 5] = 0x01;
    case 0x5cc6:
        r8[al] = memory[ss*16 + bp - 5];
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5ccd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5cdb;
            break;
        }
        yield* sub_ca53();
    case 0x5cdb:
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        di = memory16get(es, r16[bx] + 20);
        si = memory16get(es, r16[bx] + 22);
        r16[ax] = memory16get(ds, 0x9290);
        r16[ax] -= di;
        r16[ax] += 0x000e;
        r8[cl] = 0x04;
        r16[ax] = sar16(r16[ax], r8[cl]);
        r16[ax]--;
        memory16set(ds, 0x9d36, r16[ax]);
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] -= si;
        r16[ax] += 0xfff6;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory16set(ds, 0x9d38, r16[ax]);
        if (memory16gets(ds, 0x9d36) >= signed16(0x0000)) {
            pc = 0x5d17;
            break;
        }
        memory16set(ds, 0x9d36, 0x0000);
        pc = 0x5d24;
        break;
    case 0x5d17:
        if (memory16gets(ds, 0x9d36) <= signed16(0x0012)) {
            pc = 0x5d24;
            break;
        }
        memory16set(ds, 0x9d36, 0x0012);
    case 0x5d24:
        if (memory16gets(ds, 0x9d38) >= signed16(0x0000)) {
            pc = 0x5d33;
            break;
        }
        memory16set(ds, 0x9d38, 0x0000);
        pc = 0x5d40;
        break;
    case 0x5d33:
        if (memory16gets(ds, 0x9d38) <= signed16(0x0016)) {
            pc = 0x5d40;
            break;
        }
        memory16set(ds, 0x9d38, 0x0016);
    case 0x5d40:
        di = pop();
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5d44() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5d50;
            break;
        }
        yield* sub_ca53();
    case 0x5d50:
        r8[al] = 0x32;
        push(r16[ax]);
        yield* sub_24b7();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5d5a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5d68;
            break;
        }
        yield* sub_ca53();
    case 0x5d68:
        r8[al] = 0x01;
        r8[cl] = r8[al];
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x5d88;
        break;
    case 0x5d71:
        r8[al] = r8[cl];
        r8[ah] = 0x00;
        r16[dx] = 0x0009;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0x8246);
        es = memory16get(ds, 0x8246 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 1] = memory[ss*16 + bp - 1] & r8[al];
        r8[cl]++;
    case 0x5d88:
        r8[al] = r8[cl];
        r8[ah] = 0x00;
        r16[dx] = 0x0009;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0x8246);
        es = memory16get(ds, 0x8246 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx]] != 0xff) {
            pc = 0x5d71;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5da4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5db5;
            break;
        }
        yield* sub_ca53();
    case 0x5db5:
        yield* sub_7551();
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0011;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x09da));
        push(memory16get(ds, 0x09d8));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        r16[ax] = 0;
        r16[dx] = 0x7d63;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9a2a();
        sp += 0x000c;
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x5e47;
            break;
        }
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(ds, 0x9b96, r16[dx]);
        memory16set(ds, 0x9b98, r16[ax]);
        memory[ss*16 + bp - 5] = 0x00;
        pc = 0x5e41;
        break;
    case 0x5e24:
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 1838];
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 5] += 1;
    case 0x5e41:
        if (memory[ss*16 + bp - 5] < 0x10) {
            pc = 0x5e24;
            break;
        }
    case 0x5e47:
        yield* sub_5337();
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        r16[dx] += 0x0063;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0014);
        memory16set(es, r16[bx] + 32, 0x0019);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f8c();
        sp += 0x0004;
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x7928));
        push(memory16get(ds, 0x7926));
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        yield* sub_b734();
        memory[ds*16 + 0x8244] = 0x00;
        yield* sub_515f();
        r8[al] = 0x01;
        memory[ds*16 + 0x79b2] = r8[al];
        memory[ds*16 + 0x928d] = r8[al];
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_5ee5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0036;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x5ef6;
            break;
        }
        yield* sub_ca53();
    case 0x5ef6:
        memory[ss*16 + bp - 5] = 0x00;
        push(ss);
        r16[ax] = bp - 0x26;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x11b6;
        push(r16[ax]);
        r16[cx] = 0x0020;
        yield* sub_c8c5();
        push(ss);
        r16[ax] = bp - 0x36;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x11d6;
        push(r16[ax]);
        r16[cx] = 0x0010;
        yield* sub_c8c5();
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b6e4();
        sp++;
        sp++;
        push(ds);
        r16[ax] = 0x0090;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        push(memory16get(ds, 0x119c));
        yield* sub_b274();
        sp++;
        sp++;
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        di = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        r16[dx] = 0x0063;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ds, 0x6bea));
        push(memory16get(ds, 0x6be8));
        push(di);
        yield* sub_932e();
        sp += 0x000c;
        push(di);
        yield* sub_91e9();
        sp++;
        sp++;
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x5fad;
            break;
        }
        r16[ax] = memory16get(ds, 0x6bea);
        r16[dx] = memory16get(ds, 0x6be8);
        memory16set(ds, 0x9b96, r16[dx]);
        memory16set(ds, 0x9b98, r16[ax]);
        memory[ss*16 + bp - 1] = 0x00;
        pc = 0x5fa7;
        break;
    case 0x5f86:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        push(es);
        push(r16[bx]);
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 1626];
        r16[bx] = pop();
        es = pop();
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 1] += 1;
    case 0x5fa7:
        if (memory[ss*16 + bp - 1] < 0x10) {
            pc = 0x5f86;
            break;
        }
    case 0x5fad:
        memory[ss*16 + bp - 1] = 0x00;
        pc = 0x5fd3;
        break;
    case 0x5fb3:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 1854);
        r8[dl] = memory[ss*16 + bp - 1];
        r8[dh] = 0x00;
        r16[dx] <<= 1;
        r16[bx] = memory16get(ds, 0x6bca);
        es = memory16get(ds, 0x6bca + 2);
        r16[bx] += r16[dx];
        memory16set(es, r16[bx], r16[ax]);
        memory[ss*16 + bp - 1] += 1;
    case 0x5fd3:
        if (memory[ss*16 + bp - 1] < 0x10) {
            pc = 0x5fb3;
            break;
        }
        yield* sub_250b();
        memory[ss*16 + bp - 5] = 0x00;
        pc = 0x6112;
        break;
    case 0x5fe3:
        yield* sub_b281();
        r16[ax] &= 0x000f;
        si = r16[ax];
        if (r16s[ax] < signed16(0x0002)) {
            pc = 0x5fe3;
            break;
        }
        r8[al] = memory[ss*16 + bp + si - 54];
        memory[ss*16 + bp - 4] = r8[al];
        r8[al] = 0x00;
        memory[ss*16 + bp - 3] = r8[al];
        memory[ss*16 + bp - 2] = r8[al];
        memory[ds*16 + 0x119a] = 0x01;
        yield* sub_5337();
        push(ds);
        r16[ax] = 0x0578;
        push(r16[ax]);
        yield* sub_27a1();
        sp += 0x0004;
        r16[bx] = si;
        r16[bx] <<= 1;
        r16[ax] = bp - 0x26;
        r16[bx] += r16[ax];
        r16[ax] = memory16get(ss, r16[bx]);
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx], 0x0090);
        memory16set(es, r16[bx] + 2, 0x0064);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        r16[ax] = 0x0087;
        push(r16[ax]);
        r16[ax] = 0x0054;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x1331;
        push(r16[ax]);
        yield* sub_26c0();
        sp += 0x0008;
        r16[ax] = 0x0096;
        push(r16[ax]);
        r16[ax] = 0x0098;
        push(r16[ax]);
        r8[al] = 0x02;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        yield* sub_26e6();
        sp += 0x000a;
        pc = 0x60e0;
        break;
    case 0x6069:
        memory[ds*16 + 0x8244] = 0x00;
        yield* sub_3cae();
        if (!(memory[ds*16 + 0x8244] & 0x10)) {
            pc = 0x607e;
            break;
        }
        memory[ss*16 + bp - 3] = 0x01;
        pc = 0x60bf;
        break;
    case 0x607e:
        if (!(memory[ds*16 + 0x8244] & 0x04)) {
            pc = 0x609c;
            break;
        }
        if (memory[ss*16 + bp - 2] == 0x00) {
            pc = 0x609c;
            break;
        }
        memory[ss*16 + bp - 2] -= 1;
        r16[ax] = 0x0096;
        push(r16[ax]);
        r16[ax] = 0x0098;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x134b;
        pc = 0x60b8;
        break;
    case 0x609c:
        if (!(memory[ds*16 + 0x8244] & 0x08)) {
            pc = 0x60bf;
            break;
        }
        if (memory[ss*16 + bp - 2] >= 0x63) {
            pc = 0x60bf;
            break;
        }
        memory[ss*16 + bp - 2] += 1;
        r16[ax] = 0x0096;
        push(r16[ax]);
        r16[ax] = 0x0098;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x1350;
    case 0x60b8:
        push(r16[ax]);
        yield* sub_26c0();
        sp += 0x0008;
    case 0x60bf:
        r16[ax] = 0x0096;
        push(r16[ax]);
        r16[ax] = 0x0098;
        push(r16[ax]);
        r8[al] = 0x02;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        push(r16[dx]);
        push(r16[ax]);
        yield* sub_26e6();
        sp += 0x000a;
        r8[al] = 0x04;
        push(r16[ax]);
        yield* sub_24b7();
        sp++;
        sp++;
    case 0x60e0:
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x6069;
            break;
        }
        r8[al] = memory[ss*16 + bp - 2];
        memory[ss*16 + bp - 4] = r8[al];
        pc = 0x610e;
        break;
    case 0x610e:
        memory[ss*16 + bp - 5] = 0xff;
    case 0x6112:
        if (memory[ss*16 + bp - 5] >= 0x03) {
            pc = 0x611b;
            break;
        }
        pc = 0x5fe3;
        break;
    case 0x611b:
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b6e4();
        sp++;
        sp++;
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6133() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6142;
            break;
        }
        yield* sub_ca53();
    case 0x6142:
        memory[ds*16 + 0x8244] = 0x00;
        r8[al] = memory[ds*16 + 0x8242];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x61a5;
            break;
        }
        r8[al] = memory[ss*16 + bp + 4];
        memory[ds*16 + 0x792c] = r8[al];
        if (memory[ds*16 + 0x792c] == 0x05) {
            pc = 0x61a5;
            break;
        }
        if (memory[ds*16 + 0x792c] == 0x0b) {
            pc = 0x61a5;
            break;
        }
        if (memory[ds*16 + 0x792c] == 0x1c) {
            pc = 0x61a5;
            break;
        }
        memory[ds*16 + 0xa0dc] = 0x00;
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 8788);
        r16[dx] = memory16get(ds, r16[bx] + 8786);
        memory16set(ss, bp - 4, r16[dx]);
        memory16set(ss, bp - 2, r16[ax]);
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ds*16 + 0x824d] = r8[al];
        r8[al] = memory[es*16 + r16[bx] + 1];
        memory[ds*16 + 0x9bae] = r8[al];
        r16[ax] = memory16get(es, r16[bx] + 4);
        r16[dx] = memory16get(es, r16[bx] + 2);
        memory16set(ds, 0xa1ac, r16[dx]);
        memory16set(ds, 0xa1ae, r16[ax]);
    case 0x61a5:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_61a9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x61b5;
            break;
        }
        yield* sub_ca53();
    case 0x61b5:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x61c0;
            break;
        }
        r8[al] = 0x03;
        pc = 0x61c2;
        break;
    case 0x61c0:
        r8[al] = 0x0d;
    case 0x61c2:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = 0x2d;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_61d5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x61e1;
            break;
        }
        yield* sub_ca53();
    case 0x61e1:
        memory[ds*16 + 0x792c] = 0x1c;
        yield* sub_6231();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_61eb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x61f7;
            break;
        }
        yield* sub_ca53();
    case 0x61f7:
        if (!(memory[ds*16 + 0x8244] & 0x04)) {
            pc = 0x6203;
            break;
        }
        yield* sub_4504();
        pc = 0x6212;
        break;
    case 0x6203:
        if (!(memory[ds*16 + 0x8244] & 0x08)) {
            pc = 0x620f;
            break;
        }
        yield* sub_4571();
        pc = 0x6212;
        break;
    case 0x620f:
        yield* sub_6231();
    case 0x6212:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6214() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6220;
            break;
        }
        yield* sub_ca53();
    case 0x6220:
        if (!(memory[ds*16 + 0x8244] & 0x10)) {
            pc = 0x622c;
            break;
        }
        yield* sub_61eb();
        pc = 0x622f;
        break;
    case 0x622c:
        yield* sub_6268();
    case 0x622f:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6231() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6240;
            break;
        }
        yield* sub_ca53();
    case 0x6240:
        memory[ss*16 + bp - 1] = 0x15;
        memory[ss*16 + bp - 2] = 0x04;
        memory16set(ss, bp - 6, 0x1b70);
        memory16set(ss, bp - 4, ds);
        push(memory16get(ss, bp - 4));
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp - 1];
        push(r16[ax]);
        yield* sub_682c();
        sp += 0x0008;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6268() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6274;
            break;
        }
        yield* sub_ca53();
    case 0x6274:
        if (!(memory[ds*16 + 0x8244] & 0x01)) {
            pc = 0x6280;
            break;
        }
        yield* sub_6324();
        pc = 0x6283;
        break;
    case 0x6280:
        yield* sub_6285();
    case 0x6283:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6285() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6291;
            break;
        }
        yield* sub_ca53();
    case 0x6291:
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x629d;
            break;
        }
        yield* sub_635a();
        pc = 0x62a0;
        break;
    case 0x629d:
        yield* sub_62a2();
    case 0x62a0:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_62a2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x62ae;
            break;
        }
        yield* sub_ca53();
    case 0x62ae:
        if (!(memory[ds*16 + 0x8244] & 0x04)) {
            pc = 0x62ba;
            break;
        }
        yield* sub_6390();
        pc = 0x62bd;
        break;
    case 0x62ba:
        yield* sub_62bf();
    case 0x62bd:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_62bf() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x62cb;
            break;
        }
        yield* sub_ca53();
    case 0x62cb:
        if (!(memory[ds*16 + 0x8244] & 0x08)) {
            pc = 0x62d7;
            break;
        }
        yield* sub_6402();
        pc = 0x62da;
        break;
    case 0x62d7:
        yield* sub_62dc();
    case 0x62da:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_62dc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x62e8;
            break;
        }
        yield* sub_ca53();
    case 0x62e8:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        yield* sub_423f();
        if (memory[ds*16 + 0x7924] != 0x16) {
            pc = 0x62fd;
            break;
        }
        yield* sub_61d5();
        pc = 0x6305;
        break;
    case 0x62fd:
        r8[al] = 0x2f;
        push(r16[ax]);
        yield* sub_8c64();
        sp++;
        sp++;
    case 0x6305:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6307() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6313;
            break;
        }
        yield* sub_ca53();
    case 0x6313:
        if (!(memory[ds*16 + 0x8244] & 0x10)) {
            pc = 0x631f;
            break;
        }
        yield* sub_62dc();
        pc = 0x6322;
        break;
    case 0x631f:
        yield* sub_6268();
    case 0x6322:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6324() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6330;
            break;
        }
        yield* sub_ca53();
    case 0x6330:
        if (memory[ds*16 + 0x856e] >= 0x08) {
            pc = 0x633c;
            break;
        }
        yield* sub_6285();
        pc = 0x6358;
        break;
    case 0x633c:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xf8;
        push(r16[ax]);
        yield* sub_649f();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x6350;
            break;
        }
        yield* sub_6285();
        pc = 0x6358;
        break;
    case 0x6350:
        r8[al] = 0x1d;
        push(r16[ax]);
        yield* sub_6470();
        sp++;
        sp++;
    case 0x6358:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_635a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6366;
            break;
        }
        yield* sub_ca53();
    case 0x6366:
        if (memory[ds*16 + 0x856e] < 0x28) {
            pc = 0x6372;
            break;
        }
        yield* sub_62a2();
        pc = 0x638e;
        break;
    case 0x6372:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0x08;
        push(r16[ax]);
        yield* sub_649f();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x6386;
            break;
        }
        yield* sub_62a2();
        pc = 0x638e;
        break;
    case 0x6386:
        r8[al] = 0x1e;
        push(r16[ax]);
        yield* sub_6470();
        sp++;
        sp++;
    case 0x638e:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6390() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x639c;
            break;
        }
        yield* sub_ca53();
    case 0x639c:
        r8[al] = memory[ds*16 + 0x855e];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x63aa;
            break;
        }
        yield* sub_62bf();
        pc = 0x63da;
        break;
    case 0x63aa:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xff;
        push(r16[ax]);
        yield* sub_649f();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x63be;
            break;
        }
        yield* sub_63dc();
        pc = 0x63da;
        break;
    case 0x63be:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xff;
        push(r16[ax]);
        yield* sub_64d5();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x63d2;
            break;
        }
        yield* sub_63dc();
        pc = 0x63da;
        break;
    case 0x63d2:
        r8[al] = 0x1f;
        push(r16[ax]);
        yield* sub_6470();
        sp++;
        sp++;
    case 0x63da:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_63dc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x63e8;
            break;
        }
        yield* sub_ca53();
    case 0x63e8:
        if (memory[ds*16 + 0x7924] == 0x16) {
            pc = 0x63fd;
            break;
        }
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        r8[al] = 0x2f;
        push(r16[ax]);
        yield* sub_8c64();
        sp++;
        sp++;
    case 0x63fd:
        yield* sub_4504();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6402() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x640e;
            break;
        }
        yield* sub_ca53();
    case 0x640e:
        if (memory[ds*16 + 0x855e] != 0x07) {
            pc = 0x641a;
            break;
        }
        yield* sub_62dc();
        pc = 0x6448;
        break;
    case 0x641a:
        r8[al] = memory[ds*16 + 0x856e];
        r8[al]++;
        push(r16[ax]);
        yield* sub_649f();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x642e;
            break;
        }
        yield* sub_644a();
        pc = 0x6448;
        break;
    case 0x642e:
        r8[al] = memory[ds*16 + 0x856e];
        push(r16[ax]);
        yield* sub_64d5();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x6440;
            break;
        }
        yield* sub_644a();
        pc = 0x6448;
        break;
    case 0x6440:
        r8[al] = 0x20;
        push(r16[ax]);
        yield* sub_6470();
        sp++;
        sp++;
    case 0x6448:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_644a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6456;
            break;
        }
        yield* sub_ca53();
    case 0x6456:
        if (memory[ds*16 + 0x7924] == 0x16) {
            pc = 0x646b;
            break;
        }
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        r8[al] = 0x2f;
        push(r16[ax]);
        yield* sub_8c64();
        sp++;
        sp++;
    case 0x646b:
        yield* sub_4571();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6470() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x647c;
            break;
        }
        yield* sub_ca53();
    case 0x647c:
        r8[al] = memory[ss*16 + bp + 4];
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        if (memory[ds*16 + 0x7924] == 0x00) {
            pc = 0x649a;
            break;
        }
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        r8[al] = 0x30;
        push(r16[ax]);
        yield* sub_8c64();
        sp++;
        sp++;
    case 0x649a:
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_649f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x64ab;
            break;
        }
        yield* sub_ca53();
    case 0x64ab:
        r8[dl] = 0x00;
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx]] == 0x00) {
            pc = 0x64d1;
            break;
        }
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx]] == 0x19) {
            pc = 0x64d1;
            break;
        }
        r8[dl] = 0x01;
    case 0x64d1:
        r8[al] = r8[dl];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_64d5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x64e1;
            break;
        }
        yield* sub_ca53();
    case 0x64e1:
        r8[dl] = 0x00;
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx] + 48] == 0x00) {
            pc = 0x6509;
            break;
        }
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx] + 48] == 0x13) {
            pc = 0x6509;
            break;
        }
        r8[dl] = 0x01;
    case 0x6509:
        r8[al] = r8[dl];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_650d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6519;
            break;
        }
        yield* sub_ca53();
    case 0x6519:
        memory[ds*16 + 0x8242] += 1;
        if (memory[ds*16 + 0x8242] != 0x03) {
            pc = 0x652c;
            break;
        }
        memory[ds*16 + 0x8242] = 0x00;
        yield* sub_4835();
    case 0x652c:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_652e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x653a;
            break;
        }
        yield* sub_ca53();
    case 0x653a:
        r8[al] = memory[ds*16 + 0x7924];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 14014];
        push(r16[ax]);
        yield* sub_658b();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_654d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6559;
            break;
        }
        yield* sub_ca53();
    case 0x6559:
        r8[al] = memory[ds*16 + 0x7924];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 14062];
        push(r16[ax]);
        yield* sub_658b();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_656c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6578;
            break;
        }
        yield* sub_ca53();
    case 0x6578:
        r8[al] = memory[ds*16 + 0x7924];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 14110];
        push(r16[ax]);
        yield* sub_658b();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_658b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6597;
            break;
        }
        yield* sub_ca53();
    case 0x6597:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        if (r16[ax] == 0x0008) {
            pc = 0x65d6;
            break;
        }
        if (r16s[ax] > signed16(0x0008)) {
            pc = 0x65b1;
            break;
        }
        r16[bx] = r16[ax];
        if (r16[bx] > 0x0003) {
            pc = 0x65ea;
            break;
        }
        r16[bx] <<= 1;
        switch (r16[bx])
        {
        case 0: pc = 0x65c2; break;
        case 2: pc = 0x65c7; break;
        case 4: pc = 0x65cc; break;
        case 6: pc = 0x65d1; break;
            default:
            assert(0);
        }
        break;
    case 0x65b1:
        if (r16[ax] == 0x0009) {
            pc = 0x65db;
            break;
        }
        if (r16[ax] == 0x001a) {
            pc = 0x65e0;
            break;
        }
        if (r16[ax] == 0x001b) {
            pc = 0x65e5;
            break;
        }
        pc = 0x65ea;
        break;
    case 0x65c2:
        yield* sub_6617();
        pc = 0x65f3;
        break;
    case 0x65c7:
        yield* sub_4504();
        pc = 0x65f3;
        break;
    case 0x65cc:
        yield* sub_4571();
        pc = 0x65f3;
        break;
    case 0x65d1:
        yield* sub_46ae();
        pc = 0x65f3;
        break;
    case 0x65d6:
        yield* sub_45dc();
        pc = 0x65f3;
        break;
    case 0x65db:
        yield* sub_4646();
        pc = 0x65f3;
        break;
    case 0x65e0:
        yield* sub_3e8e();
        pc = 0x65f3;
        break;
    case 0x65e5:
        yield* sub_3f4d();
        pc = 0x65f3;
        break;
    case 0x65ea:
        r8[al] = memory[ss*16 + bp + 4];
        push(r16[ax]);
        yield* sub_65fd();
        sp++;
        sp++;
    case 0x65f3:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_65fd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6609;
            break;
        }
        yield* sub_ca53();
    case 0x6609:
        r8[al] = memory[ss*16 + bp + 4];
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6617() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6625;
            break;
        }
        yield* sub_ca53();
    case 0x6625:
        if (memory[ds*16 + 0x856e] >= 0x08) {
            pc = 0x6632;
            break;
        }
        memory[ss*16 + bp - 2] = 0x00;
        pc = 0x6653;
        break;
    case 0x6632:
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        es = memory16get(ds, 0xa0da);
        r16[ax] += memory16get(ds, 0xa0d8);
        r16[bx] = r16[ax];
        r8[al] = memory[es*16 + r16[bx] - 8];
        memory[ss*16 + bp - 1] = r8[al];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 14158];
        memory[ss*16 + bp - 2] = r8[al];
    case 0x6653:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x668e;
            break;
        }
        if (memory[ds*16 + 0x79b3] <= 0xeb) {
            pc = 0x6669;
            break;
        }
        memory[ss*16 + bp - 2] = 0x3c;
        pc = 0x668e;
        break;
    case 0x6669:
        if (memory[ds*16 + 0x79b3] <= 0xd7) {
            pc = 0x6676;
            break;
        }
        memory[ss*16 + bp - 2] = 0x3d;
        pc = 0x668e;
        break;
    case 0x6676:
        if (memory[ds*16 + 0x79b3] <= 0xc3) {
            pc = 0x6683;
            break;
        }
        memory[ss*16 + bp - 2] = 0x3e;
        pc = 0x668e;
        break;
    case 0x6683:
        if (memory[ds*16 + 0x79b3] <= 0xaf) {
            pc = 0x668e;
            break;
        }
        memory[ss*16 + bp - 2] = 0x3f;
    case 0x668e:
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        yield* sub_65fd();
        sp++;
        sp++;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_669b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x66a7;
            break;
        }
        yield* sub_ca53();
    case 0x66a7:
        if (!(memory[ds*16 + 0x8244] & 0x04)) {
            pc = 0x66b3;
            break;
        }
        yield* sub_4504();
        pc = 0x66d0;
        break;
    case 0x66b3:
        if (!(memory[ds*16 + 0x8244] & 0x08)) {
            pc = 0x66bf;
            break;
        }
        yield* sub_4571();
        pc = 0x66d0;
        break;
    case 0x66bf:
        r8[al] = memory[ds*16 + 0x792c];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 14206];
        push(r16[ax]);
        yield* sub_658b();
        sp++;
        sp++;
    case 0x66d0:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_66d2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x66de;
            break;
        }
        yield* sub_ca53();
    case 0x66de:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x66e9;
            break;
        }
        r8[al] = 0x03;
        pc = 0x66eb;
        break;
    case 0x66e9:
        r8[al] = 0x28;
    case 0x66eb:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        r8[al] = 0x27;
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
        r8[al] = 0x0e;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        yield* sub_425e();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_670c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6718;
            break;
        }
        yield* sub_ca53();
    case 0x6718:
        yield* sub_48da();
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx], 0x0001);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(es, r16[bx] + 16, r16[dx]);
        memory16set(es, r16[bx] + 18, r16[ax]);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 24, 0x0014);
        memory16set(es, r16[bx] + 26, 0x0019);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0014);
        memory16set(es, r16[bx] + 32, 0x0019);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_b288();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6779() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6785;
            break;
        }
        yield* sub_ca53();
    case 0x6785:
        if (memory[ds*16 + 0x8571] == 0xff) {
            pc = 0x67d4;
            break;
        }
        r8[al] = memory[ds*16 + 0x8571];
        r8[ah] = 0x00;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory[ds*16 + 0x8565] = r8[al];
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[dl] = memory[ds*16 + 0x8571];
        r8[dl] -= r8[al];
        memory[ds*16 + 0x8564] = r8[dl];
        r8[al] = memory[ds*16 + 0x8571];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 628);
        r16[ax] += 0x0007;
        memory16set(ds, 0x79ba, r16[ax]);
        r8[al] = memory[ds*16 + 0x8571];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 630);
        r16[ax] += 0x0007;
        memory16set(ds, 0x79bc, r16[ax]);
    case 0x67d4:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_67d6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x67e2;
            break;
        }
        yield* sub_ca53();
    case 0x67e2:
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory[ds*16 + 0x855c] = r8[al];
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[al] <<= 1;
        r8[dl] = memory[ds*16 + 0x856e];
        r8[dl] -= r8[al];
        memory[ds*16 + 0x855e] = r8[dl];
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 628);
        r16[ax] += 0x0007;
        memory16set(ds, 0x9290, r16[ax]);
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 630);
        r16[ax] += 0x000f;
        memory16set(ds, 0x9292, r16[ax]);
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_682c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6838;
            break;
        }
        yield* sub_ca53();
    case 0x6838:
        memory[ds*16 + 0x855d] += 1;
        r8[al] = memory[ds*16 + 0x855d];
        if (r8[al] != memory[ss*16 + bp + 6]) {
            pc = 0x6856;
            break;
        }
        push(memory16get(ss, bp + 10));
        push(memory16get(ss, bp + 8));
        r8[al] = memory[ss*16 + bp + 4];
        push(r16[ax]);
        yield* sub_6865();
        sp += 0x0006;
        pc = 0x6863;
        break;
    case 0x6856:
        r8[al] = memory[ds*16 + 0x855d];
        if (r8[al] <= memory[ss*16 + bp + 6]) {
            pc = 0x6863;
            break;
        }
        memory[ds*16 + 0x855d] = 0x00;
    case 0x6863:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6865() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6871;
            break;
        }
        yield* sub_ca53();
    case 0x6871:
        memory[ds*16 + 0x855d] = 0x00;
        r8[al] = memory[ds*16 + 0xa0dc];
        r8[ah] = 0x00;
        r16[ax]++;
        r8[dl] = memory[ss*16 + bp + 4];
        r8[dh] = 0x00;
        if (r16s[ax] >= r16s[dx]) {
            pc = 0x688e;
            break;
        }
        memory[ds*16 + 0xa0dc] += 1;
        r8[al] = memory[ds*16 + 0xa0dc];
        pc = 0x6893;
        break;
    case 0x688e:
        r8[al] = 0x00;
        memory[ds*16 + 0xa0dc] = r8[al];
    case 0x6893:
        r8[al] = memory[ds*16 + 0xa0dc];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        r16[bx] += r16[ax];
        r16[ax] = memory16get(es, r16[bx]);
        memory16set(ds, 0x824a, r16[ax]);
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_68a7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x68b5;
            break;
        }
        yield* sub_ca53();
    case 0x68b5:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx], 0x0000);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 16, 0x9694);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 24, 0x0014);
        memory16set(es, r16[bx] + 26, 0x0001);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0014);
        memory16set(es, r16[bx] + 32, 0x0001);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_b288();
        sp += 0x0004;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b6e4();
        sp++;
        sp++;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        r16[ax] = 0x0007;
        push(r16[ax]);
        r16[ax] = 0;
        push(r16[ax]);
        r8[al] = 0x07;
        push(r16[ax]);
        push(memory16get(ds, 0xa0d6));
        push(memory16get(ds, 0xa0d4));
        yield* sub_26e6();
        sp += 0x000a;
        yield* sub_8000();
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b6e4();
        sp++;
        sp++;
    case 0x6949:
        r8[al] = 0x19;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (r8[al]) {
            pc = 0x6949;
            break;
        }
        pc = 0x69a2;
        break;
    case 0x6957:
        r8[al] = 0x1d;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x69a2;
            break;
        }
        r8[al] = 0x21;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (!r8[al]) {
            pc = 0x69a2;
            break;
        }
        memory[ss*16 + bp - 1] = 0x01;
        pc = 0x698c;
        break;
    case 0x6975:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[dx] = 0x0009;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0x8246);
        es = memory16get(ds, 0x8246 + 2);
        r16[bx] += r16[ax];
        memory[es*16 + r16[bx]] = 0x01;
        memory[ss*16 + bp - 1] += 1;
    case 0x698c:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[dx] = 0x0009;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0x8246);
        es = memory16get(ds, 0x8246 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx]] != 0xff) {
            pc = 0x6975;
            break;
        }
    case 0x69a2:
        r8[al] = 0x19;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        cbw();
        if (r16[ax]) {
            pc = 0x69bc;
            break;
        }
        r8[al] = 0x00;
        push(r16[ax]);
        yield* sub_9472();
        sp++;
        sp++;
        cbw();
        if (!r16[ax]) {
            pc = 0x6957;
            break;
        }
    case 0x69bc:
        r8[al] = 0x19;
        push(r16[ax]);
        yield* sub_9984();
        sp++;
        sp++;
        if (r8[al]) {
            pc = 0x69bc;
            break;
        }
        r8[al] = 0x00;
        push(r16[ax]);
        yield* sub_9472();
        sp++;
        sp++;
        if (r8[al]) {
            pc = 0x69bc;
            break;
        }
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 2, 0x9694);
        memory16set(es, r16[bx] + 4, ds);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0001);
        memory16set(es, r16[bx] + 14, 0x0000);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f8c();
        sp += 0x0004;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6a1e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6a2c;
            break;
        }
        yield* sub_ca53();
    case 0x6a2c:
        if (memory[ds*16 + 0x8571] == 0xff) {
            pc = 0x6a92;
            break;
        }
        r16[bx] = memory16get(ds, 0x9b9e);
        es = memory16get(ds, 0x9b9e + 2);
        di = memory16get(es, r16[bx] + 20);
        si = memory16get(es, r16[bx] + 22);
        r16[ax] = memory16get(ds, 0x79ba);
        r16[ax] -= di;
        r8[cl] = 0x04;
        r16[ax] = sar16(r16[ax], r8[cl]);
        r16[ax]--;
        memory16set(ds, 0xa0ca, r16[ax]);
        r16[ax] = memory16get(ds, 0x79bc);
        r16[ax] -= si;
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory16set(ds, 0xa0cc, r16[ax]);
        if (memory16gets(ds, 0xa0ca) >= signed16(0x0000)) {
            pc = 0x6a69;
            break;
        }
        memory16set(ds, 0xa0ca, 0x0000);
        pc = 0x6a76;
        break;
    case 0x6a69:
        if (memory16gets(ds, 0xa0ca) <= signed16(0x0012)) {
            pc = 0x6a76;
            break;
        }
        memory16set(ds, 0xa0ca, 0x0012);
    case 0x6a76:
        if (memory16gets(ds, 0xa0cc) >= signed16(0x0000)) {
            pc = 0x6a85;
            break;
        }
        memory16set(ds, 0xa0cc, 0x0000);
        pc = 0x6a92;
        break;
    case 0x6a85:
        if (memory16gets(ds, 0xa0cc) <= signed16(0x0016)) {
            pc = 0x6a92;
            break;
        }
        memory16set(ds, 0xa0cc, 0x0016);
    case 0x6a92:
        di = pop();
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6a96() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6aa5;
            break;
        }
        yield* sub_ca53();
    case 0x6aa5:
        r8[al] = memory[ss*16 + bp + 4];
        if (r8[al]) {
            memory[ds*16 + 0x8562] = r8[al];
            r8[ah] = 0x00;
            r16[ax] <<= 1;
            r16[ax] <<= 1;
            r16[bx] = r16[ax];
            r16[ax] = memory16get(ds, r16[bx] + 9506);
            r16[dx] = memory16get(ds, r16[bx] + 9504);
            memory16set(ss, bp - 4, r16[dx]);
            memory16set(ss, bp - 2, r16[ax]);
            r16[bx] = memory16get(ss, bp - 4);
            es = memory16get(ss, bp - 4 + 2);
            r8[al] = memory[es*16 + r16[bx]];
            memory[ds*16 + 0xa1b0] = r8[al];
            r8[al] = memory[es*16 + r16[bx] + 1];
            memory[ds*16 + 0x9d2f] = r8[al];
            r16[ax] = memory16get(es, r16[bx] + 4);
            r16[dx] = memory16get(es, r16[bx] + 2);
            memory16set(ds, 0xa0ba, r16[dx]);
            memory16set(ds, 0xa0bc, r16[ax]);
        }
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6ae4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6af0;
            break;
        }
        yield* sub_ca53();
    case 0x6af0:
        r8[al] = memory[ds*16 + 0x8243];
        r8[al] ^= 0x01;
        memory[ds*16 + 0x8243] = r8[al];
        if (memory[ds*16 + 0x8243] == 0x00) {
            pc = 0x6b67;
            break;
        }
        if (memory[ds*16 + 0x8571] == 0xff) {
            pc = 0x6b67;
            break;
        }
        r16[bx] = memory16get(ds, 0xa0ba);
        es = memory16get(ds, 0xa0ba + 2);
        r16[ax] = memory16get(es, r16[bx]);
        memory16set(ds, 0x8560, r16[ax]);
        if (memory[ds*16 + 0x9d2f] == 0x00) {
            pc = 0x6b2b;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 2);
        r16[ax] = -r16[ax];
        r16[dx] = memory16get(ds, 0x79ba);
        r16[dx] += r16[ax];
        memory16set(ds, 0x79ba, r16[dx]);
        r16[ax] = r16[dx];
        pc = 0x6b3a;
        break;
    case 0x6b2b:
        r16[bx] = memory16get(ds, 0xa0ba);
        es = memory16get(ds, 0xa0ba + 2);
        r16[ax] = memory16get(es, r16[bx] + 2);
        memory16set(ds, 0x79ba, memory16get(ds, 0x79ba) + r16[ax]);
        r16[ax] = memory16get(ds, 0x79ba);
    case 0x6b3a:
        r16[bx] = memory16get(ds, 0xa0ba);
        es = memory16get(ds, 0xa0ba + 2);
        r16[ax] = memory16get(es, r16[bx] + 4);
        memory16set(ds, 0x79bc, memory16get(ds, 0x79bc) + r16[ax]);
        memory16set(ds, 0xa0ba, memory16get(ds, 0xa0ba) + 0x0006);
        r8[al] = memory[ds*16 + 0xa1b0];
        r8[al] += 0xff;
        memory[ds*16 + 0xa1b0] = r8[al];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6b60;
            break;
        }
        r8[al] = 0x00;
        memory[ds*16 + 0x8563] = r8[al];
        pc = 0x6b67;
        break;
    case 0x6b60:
        memory[ds*16 + 0x8563] += 1;
        r8[al] = memory[ds*16 + 0x8563];
    case 0x6b67:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6b69() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6b75;
            break;
        }
        yield* sub_ca53();
    case 0x6b75:
        if (memory[ds*16 + 0x8243] != 0x00) {
            pc = 0x6b7f;
            break;
        }
        pc = 0x6c8d;
        break;
    case 0x6b7f:
        if (memory[ds*16 + 0x8571] != 0xff) {
            pc = 0x6b89;
            break;
        }
        pc = 0x6c8d;
        break;
    case 0x6b89:
        if (memory[ds*16 + 0xa1b0] == 0x00) {
            pc = 0x6b96;
            break;
        }
        yield* sub_6ed3();
        pc = 0x6c8d;
        break;
    case 0x6b96:
        r8[al] = 0x01;
        memory[ds*16 + 0xa1b2] = r8[al];
        memory[ds*16 + 0xa0e2] = r8[al];
        memory[ds*16 + 0xa0e1] = r8[al];
        memory[ds*16 + 0xa0e0] = r8[al];
        if (memory[ds*16 + 0x8571] < 0x08) {
            pc = 0x6bc9;
            break;
        }
        r8[al] = memory[ds*16 + 0x8571];
        r8[ah] = 0x00;
        es = memory16get(ds, 0xa0da);
        r16[ax] += memory16get(ds, 0xa0d8);
        r16[bx] = r16[ax];
        r8[al] = memory[es*16 + r16[bx] - 8];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6bc9;
            break;
        }
        memory[ds*16 + 0xa0e0] = 0x00;
    case 0x6bc9:
        if (memory[ds*16 + 0x8571] >= 0x28) {
            pc = 0x6be9;
            break;
        }
        r8[al] = memory[ds*16 + 0x8571];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6be9;
            break;
        }
        memory[ds*16 + 0xa0e1] = 0x00;
    case 0x6be9:
        if (memory[ds*16 + 0x8564] == 0x00) {
            pc = 0x6c21;
            break;
        }
        r8[al] = memory[ds*16 + 0x8571];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 47];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6c21;
            break;
        }
        memory[ds*16 + 0xa0e2] = 0x00;
        r8[al] = memory[ds*16 + 0x8571];
        r8[ah] = 0x00;
        r16[ax] += memory16get(ds, 0xa0d8);
        r16[bx] = r16[ax];
        if (memory[es*16 + r16[bx] - 1] != 0x0b) {
            pc = 0x6c21;
            break;
        }
        memory[ds*16 + 0xa0e2] = 0x01;
    case 0x6c21:
        if (memory[ds*16 + 0x8564] == 0x07) {
            pc = 0x6c59;
            break;
        }
        r8[al] = memory[ds*16 + 0x8571];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 48];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6c59;
            break;
        }
        memory[ds*16 + 0xa1b2] = 0x00;
        r8[al] = memory[ds*16 + 0x8571];
        r8[ah] = 0x00;
        r16[ax] += memory16get(ds, 0xa0d8);
        r16[bx] = r16[ax];
        if (memory[es*16 + r16[bx] + 1] != 0x0b) {
            pc = 0x6c59;
            break;
        }
        memory[ds*16 + 0xa1b2] = 0x01;
    case 0x6c59:
        r8[al] = memory[ds*16 + 0xa0e0];
        r8[ah] = 0x00;
        r8[dl] = memory[ds*16 + 0xa0e1];
        r8[dh] = 0x00;
        r16[ax] += r16[dx];
        r8[dl] = memory[ds*16 + 0xa0e2];
        r8[dh] = 0x00;
        r16[ax] += r16[dx];
        r8[dl] = memory[ds*16 + 0xa1b2];
        r8[dh] = 0x00;
        r16[ax] += r16[dx];
        if (r16[ax] != 0x0004) {
            pc = 0x6c80;
            break;
        }
        yield* sub_6ea3();
        pc = 0x6c8d;
        break;
    case 0x6c80:
        r8[al] = memory[ds*16 + 0x8562];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 2160));
    case 0x6c8d:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6c8f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6c9b;
            break;
        }
        yield* sub_ca53();
    case 0x6c9b:
        r8[al] = memory[ds*16 + 0xa0e0];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6ca9;
            break;
        }
        yield* sub_6cca();
        pc = 0x6cc8;
        break;
    case 0x6ca9:
        r8[al] = memory[ds*16 + 0xa1b2];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6cb7;
            break;
        }
        yield* sub_6e59();
        pc = 0x6cc8;
        break;
    case 0x6cb7:
        r8[al] = memory[ds*16 + 0xa0e2];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6cc5;
            break;
        }
        yield* sub_6dd4();
        pc = 0x6cc8;
        break;
    case 0x6cc5:
        yield* sub_6d4f();
    case 0x6cc8:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6cca() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6cd6;
            break;
        }
        yield* sub_ca53();
    case 0x6cd6:
        r8[al] = memory[ds*16 + 0x79b3];
        if (r8[al] < memory[ds*16 + 0x7920]) {
            pc = 0x6ce3;
            break;
        }
        r8[al] = 0x01;
        pc = 0x6d0c;
        break;
    case 0x6ce3:
        if (!(memory[ds*16 + 0x79b3] & 0x01)) {
            pc = 0x6cff;
            break;
        }
        if (memory[ds*16 + 0xa0e2] == 0x00) {
            pc = 0x6cf5;
            break;
        }
        r8[al] = 0x01;
        pc = 0x6d0c;
        break;
    case 0x6cf5:
        r8[al] = 0x03;
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
        pc = 0x6d12;
        break;
    case 0x6cff:
        if (memory[ds*16 + 0xa1b2] == 0x00) {
            pc = 0x6d0a;
            break;
        }
        r8[al] = 0x01;
        pc = 0x6d0c;
        break;
    case 0x6d0a:
        r8[al] = 0x04;
    case 0x6d0c:
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
    case 0x6d12:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6d14() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6d20;
            break;
        }
        yield* sub_ca53();
    case 0x6d20:
        r8[al] = memory[ds*16 + 0xa0e1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6d2e;
            break;
        }
        yield* sub_6d4f();
        pc = 0x6d4d;
        break;
    case 0x6d2e:
        r8[al] = memory[ds*16 + 0xa0e2];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6d3c;
            break;
        }
        yield* sub_6dd4();
        pc = 0x6d4d;
        break;
    case 0x6d3c:
        r8[al] = memory[ds*16 + 0xa1b2];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6d4a;
            break;
        }
        yield* sub_6e59();
        pc = 0x6d4d;
        break;
    case 0x6d4a:
        yield* sub_6cca();
    case 0x6d4d:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6d4f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6d5b;
            break;
        }
        yield* sub_ca53();
    case 0x6d5b:
        r8[al] = memory[ds*16 + 0x79b3];
        if (r8[al] < memory[ds*16 + 0x7920]) {
            pc = 0x6d68;
            break;
        }
        r8[al] = 0x02;
        pc = 0x6d91;
        break;
    case 0x6d68:
        if (!(memory[ds*16 + 0x79b3] & 0x01)) {
            pc = 0x6d84;
            break;
        }
        if (memory[ds*16 + 0xa0e2] == 0x00) {
            pc = 0x6d7a;
            break;
        }
        r8[al] = 0x02;
        pc = 0x6d91;
        break;
    case 0x6d7a:
        r8[al] = 0x03;
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
        pc = 0x6d97;
        break;
    case 0x6d84:
        if (memory[ds*16 + 0xa1b2] == 0x00) {
            pc = 0x6d8f;
            break;
        }
        r8[al] = 0x02;
        pc = 0x6d91;
        break;
    case 0x6d8f:
        r8[al] = 0x04;
    case 0x6d91:
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
    case 0x6d97:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6d99() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6da5;
            break;
        }
        yield* sub_ca53();
    case 0x6da5:
        r8[al] = memory[ds*16 + 0xa0e2];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6db3;
            break;
        }
        yield* sub_6dd4();
        pc = 0x6dd2;
        break;
    case 0x6db3:
        r8[al] = memory[ds*16 + 0xa0e0];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6dc1;
            break;
        }
        yield* sub_6cca();
        pc = 0x6dd2;
        break;
    case 0x6dc1:
        r8[al] = memory[ds*16 + 0xa0e1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6dcf;
            break;
        }
        yield* sub_6d4f();
        pc = 0x6dd2;
        break;
    case 0x6dcf:
        yield* sub_6e59();
    case 0x6dd2:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6dd4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6de0;
            break;
        }
        yield* sub_ca53();
    case 0x6de0:
        r8[al] = memory[ds*16 + 0x79b3];
        if (r8[al] < memory[ds*16 + 0x7920]) {
            pc = 0x6ded;
            break;
        }
        r8[al] = 0x03;
        pc = 0x6e16;
        break;
    case 0x6ded:
        if (!(memory[ds*16 + 0x79b3] & 0x01)) {
            pc = 0x6e09;
            break;
        }
        if (memory[ds*16 + 0xa0e0] == 0x00) {
            pc = 0x6dff;
            break;
        }
        r8[al] = 0x03;
        pc = 0x6e16;
        break;
    case 0x6dff:
        r8[al] = 0x01;
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
        pc = 0x6e1c;
        break;
    case 0x6e09:
        if (memory[ds*16 + 0xa0e1] == 0x00) {
            pc = 0x6e14;
            break;
        }
        r8[al] = 0x03;
        pc = 0x6e16;
        break;
    case 0x6e14:
        r8[al] = 0x02;
    case 0x6e16:
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
    case 0x6e1c:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6e1e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6e2a;
            break;
        }
        yield* sub_ca53();
    case 0x6e2a:
        r8[al] = memory[ds*16 + 0xa1b2];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6e38;
            break;
        }
        yield* sub_6e59();
        pc = 0x6e57;
        break;
    case 0x6e38:
        r8[al] = memory[ds*16 + 0xa0e1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6e46;
            break;
        }
        yield* sub_6d4f();
        pc = 0x6e57;
        break;
    case 0x6e46:
        r8[al] = memory[ds*16 + 0xa0e0];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6e54;
            break;
        }
        yield* sub_6cca();
        pc = 0x6e57;
        break;
    case 0x6e54:
        yield* sub_6dd4();
    case 0x6e57:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6e59() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6e65;
            break;
        }
        yield* sub_ca53();
    case 0x6e65:
        r8[al] = memory[ds*16 + 0x79b3];
        if (r8[al] < memory[ds*16 + 0x7920]) {
            pc = 0x6e72;
            break;
        }
        r8[al] = 0x04;
        pc = 0x6e9b;
        break;
    case 0x6e72:
        if (!(memory[ds*16 + 0x79b3] & 0x01)) {
            pc = 0x6e8e;
            break;
        }
        if (memory[ds*16 + 0xa0e0] == 0x00) {
            pc = 0x6e84;
            break;
        }
        r8[al] = 0x04;
        pc = 0x6e9b;
        break;
    case 0x6e84:
        r8[al] = 0x01;
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
        pc = 0x6ea1;
        break;
    case 0x6e8e:
        if (memory[ds*16 + 0xa0e1] == 0x00) {
            pc = 0x6e99;
            break;
        }
        r8[al] = 0x04;
        pc = 0x6e9b;
        break;
    case 0x6e99:
        r8[al] = 0x02;
    case 0x6e9b:
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
    case 0x6ea1:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6ea3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6eb1;
            break;
        }
        yield* sub_ca53();
    case 0x6eb1:
        r8[al] = memory[ds*16 + 0x79b3];
        r8[al] &= 0x03;
        memory[ss*16 + bp - 2] = r8[al];
        yield* sub_b281();
        memory[ds*16 + 0x79b3] = r8[al];
        r8[al] &= 0x01;
        r8[al] += memory[ss*16 + bp - 2];
        r8[al] += 0x05;
        memory[ss*16 + bp - 1] = r8[al];
        push(r16[ax]);
        yield* sub_6a96();
        sp++;
        sp++;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6ed3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6edf;
            break;
        }
        yield* sub_ca53();
    case 0x6edf:
        if (memory[ds*16 + 0x8563] != 0x05) {
            pc = 0x6ef3;
            break;
        }
        r8[al] = memory[ds*16 + 0x8562];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 2140));
    case 0x6ef3:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6ef5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6f01;
            break;
        }
        yield* sub_ca53();
    case 0x6f01:
        r8[al] = memory[ds*16 + 0x8571];
        r8[al] += 0xf8;
        memory[ds*16 + 0x8571] = r8[al];
        memory[ds*16 + 0x8565] -= 1;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6f0f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6f1b;
            break;
        }
        yield* sub_ca53();
    case 0x6f1b:
        r8[al] = memory[ds*16 + 0x8571];
        r8[al] += 0x08;
        memory[ds*16 + 0x8571] = r8[al];
        memory[ds*16 + 0x8565] += 1;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6f29() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6f35;
            break;
        }
        yield* sub_ca53();
    case 0x6f35:
        memory[ds*16 + 0x8571] -= 1;
        memory[ds*16 + 0x8564] -= 1;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6f3f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6f4b;
            break;
        }
        yield* sub_ca53();
    case 0x6f4b:
        memory[ds*16 + 0x8571] += 1;
        memory[ds*16 + 0x8564] += 1;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6f55() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6f61;
            break;
        }
        yield* sub_ca53();
    case 0x6f61:
        r8[al] = memory[ds*16 + 0xa0ce];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6f8e;
            break;
        }
        r16[ax] = memory16get(ds, 0x9290);
        r16[ax] += 0xfffb;
        memory16set(ds, 0x084c, r16[ax]);
        r16[ax] = memory16get(ds, 0x9290);
        r16[ax] += 0x0006;
        memory16set(ds, 0x084e, r16[ax]);
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] += 0xfffb;
        memory16set(ds, 0x0850, r16[ax]);
        r16[ax] = memory16get(ds, 0x9292);
        r16[ax] += 0x0005;
        memory16set(ds, 0x0852, r16[ax]);
    case 0x6f8e:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6f90() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6f9c;
            break;
        }
        yield* sub_ca53();
    case 0x6f9c:
        r8[al] = memory[ds*16 + 0xa0ce];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x6fc9;
            break;
        }
        r16[ax] = memory16get(ds, 0x79ba);
        r16[ax] += 0xfffb;
        memory16set(ds, 0x0854, r16[ax]);
        r16[ax] = memory16get(ds, 0x79ba);
        r16[ax] += 0x0006;
        memory16set(ds, 0x0856, r16[ax]);
        r16[ax] = memory16get(ds, 0x79bc);
        r16[ax] += 0xfffb;
        memory16set(ds, 0x0858, r16[ax]);
        r16[ax] = memory16get(ds, 0x79bc);
        r16[ax] += 0x0005;
        memory16set(ds, 0x085a, r16[ax]);
    case 0x6fc9:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_6fcb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x6fd7;
            break;
        }
        yield* sub_ca53();
    case 0x6fd7:
        if (memory[ds*16 + 0x8571] == 0xff) {
            pc = 0x704f;
            break;
        }
        r8[al] = memory[ds*16 + 0xa0ce];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x704f;
            break;
        }
        r8[al] = memory[ds*16 + 0x856d];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x704f;
            break;
        }
        if (memory[ds*16 + 0x792c] == 0x30) {
            pc = 0x704f;
            break;
        }
        r16[ax] = memory16get(ds, 0x0854);
        if (r16s[ax] <= memory16gets(ds, 0x084e)) {
            pc = 0x7007;
            break;
        }
        memory[ds*16 + 0xa1aa] = 0x00;
        pc = 0x704f;
        break;
    case 0x7007:
        r16[ax] = memory16get(ds, 0x084c);
        if (r16s[ax] <= memory16gets(ds, 0x0856)) {
            pc = 0x7017;
            break;
        }
        memory[ds*16 + 0xa1aa] = 0x00;
        pc = 0x704f;
        break;
    case 0x7017:
        r16[ax] = memory16get(ds, 0x0858);
        if (r16s[ax] <= memory16gets(ds, 0x0852)) {
            pc = 0x7027;
            break;
        }
        memory[ds*16 + 0xa1aa] = 0x00;
        pc = 0x704f;
        break;
    case 0x7027:
        r16[ax] = memory16get(ds, 0x0850);
        if (r16s[ax] <= memory16gets(ds, 0x085a)) {
            pc = 0x7037;
            break;
        }
        memory[ds*16 + 0xa1aa] = 0x00;
        pc = 0x704f;
        break;
    case 0x7037:
        memory[ds*16 + 0xa1aa] = 0x01;
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x7047;
            break;
        }
        r8[al] = 0x03;
        pc = 0x7049;
        break;
    case 0x7047:
        r8[al] = 0x0d;
    case 0x7049:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x704f:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_7051() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x705d;
            break;
        }
        yield* sub_ca53();
    case 0x705d:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        r16[ax] = memory16get(ss, bp + 4);
        memory16set(es, r16[bx], r16[ax]);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        r16[ax] = memory16get(ss, bp + 6);
        memory16set(es, r16[bx] + 14, r16[ax]);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0014);
        memory16set(es, r16[bx] + 32, 0x0019);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_b298();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_70a8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x70b4;
            break;
        }
        yield* sub_ca53();
    case 0x70b4:
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        r16[dx] += 0x0063;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 16, 0x9d3a);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 24, 0x0003);
        memory16set(es, r16[bx] + 26, 0x0002);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0003);
        memory16set(es, r16[bx] + 32, 0x0002);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f7c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 6, 0x0004);
        memory16set(es, r16[bx] + 16, 0x9baf);
        memory16set(es, r16[bx] + 18, ds);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f7c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0008);
        memory16set(es, r16[bx] + 16, 0x9eba);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 24, 0x0001);
        memory16set(es, r16[bx] + 26, 0x0004);
        memory16set(es, r16[bx] + 30, 0x0001);
        memory16set(es, r16[bx] + 32, 0x0004);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f7c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 8, 0x0003);
        memory16set(es, r16[bx] + 16, 0x9fba);
        memory16set(es, r16[bx] + 18, ds);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f7c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x000d);
        memory16set(es, r16[bx] + 16, 0x8b88);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 24, 0x0006);
        memory16set(es, r16[bx] + 26, 0x0002);
        memory16set(es, r16[bx] + 30, 0x0006);
        memory16set(es, r16[bx] + 32, 0x0002);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f7c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 8, 0x0011);
        memory16set(es, r16[bx] + 16, 0x824e);
        memory16set(es, r16[bx] + 18, ds);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f7c();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 8, 0x0015);
        memory16set(es, r16[bx] + 16, 0x8582);
        memory16set(es, r16[bx] + 18, ds);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f7c();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_722e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x723a;
            break;
        }
        yield* sub_ca53();
    case 0x723a:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory[es*16 + r16[bx] + 34] = 0x00;
        memory[es*16 + r16[bx] + 35] = 0x00;
        memory[es*16 + r16[bx] + 36] = 0x00;
        memory[es*16 + r16[bx] + 37] = 0x00;
        r16[bx] = memory16get(ds, 0x08b8);
        es = memory16get(ds, 0x08b8 + 2);
        memory16set(es, r16[bx], 0x0001);
        memory16set(es, r16[bx] + 16, 0x8e8d);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 24, 0x0004);
        memory16set(es, r16[bx] + 26, 0x0004);
        memory16set(es, r16[bx] + 28, 0x0000);
        r16[bx] = memory16get(ds, 0x08ec);
        es = memory16get(ds, 0x08ec + 2);
        memory16set(es, r16[bx], 0x0001);
        memory16set(es, r16[bx] + 16, 0x9294);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 24, 0x0004);
        memory16set(es, r16[bx] + 26, 0x0004);
        memory16set(es, r16[bx] + 28, 0x0000);
        r16[bx] = memory16get(ds, 0x08bc);
        es = memory16get(ds, 0x08bc + 2);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0001);
        memory16set(es, r16[bx] + 12, 0x0004);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0001);
        memory16set(es, r16[bx] + 32, 0x0004);
        r16[bx] = memory16get(ds, 0x08c0);
        es = memory16get(ds, 0x08c0 + 2);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0003);
        memory16set(es, r16[bx] + 12, 0x0002);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0002);
        memory16set(es, r16[bx] + 32, 0x0002);
        r16[bx] = memory16get(ds, 0x08c4);
        es = memory16get(ds, 0x08c4 + 2);
        memory16set(es, r16[bx] + 2, 0x8e8d);
        memory16set(es, r16[bx] + 4, ds);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0004);
        memory16set(es, r16[bx] + 12, 0x0004);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 28, 0x0000);
        r16[bx] = memory16get(ds, 0x08e8);
        es = memory16get(ds, 0x08e8 + 2);
        memory16set(es, r16[bx] + 2, 0x9294);
        memory16set(es, r16[bx] + 4, ds);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0004);
        memory16set(es, r16[bx] + 12, 0x0004);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 28, 0x0000);
        r16[bx] = memory16get(ds, 0x08c8);
        es = memory16get(ds, 0x08c8 + 2);
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 16, 0x8888);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 24, 0x0003);
        memory16set(es, r16[bx] + 26, 0x0004);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0001);
        memory16set(es, r16[bx] + 32, 0x0004);
        r16[bx] = memory16get(ds, 0x08cc);
        es = memory16get(ds, 0x08cc + 2);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 12, 0x0004);
        memory16set(es, r16[bx] + 16, 0x8888);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 24, 0x0003);
        memory16set(es, r16[bx] + 26, 0x0004);
        memory16set(es, r16[bx] + 30, 0x0001);
        memory16set(es, r16[bx] + 32, 0x0004);
        r16[bx] = memory16get(ds, 0x08d0);
        es = memory16get(ds, 0x08d0 + 2);
        memory16set(es, r16[bx], 0x0001);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 24, 0x0001);
        memory16set(es, r16[bx] + 26, 0x0004);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0001);
        memory16set(es, r16[bx] + 32, 0x0004);
        r16[bx] = memory16get(ds, 0x08d4);
        es = memory16get(ds, 0x08d4 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 30, 0x0002);
        memory16set(es, r16[bx] + 32, 0x0002);
        r16[bx] = memory16get(ds, 0x08d8);
        es = memory16get(ds, 0x08d8 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 16, 0x8888);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 24, 0x0003);
        memory16set(es, r16[bx] + 26, 0x0004);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0003);
        memory16set(es, r16[bx] + 32, 0x0002);
        r16[bx] = memory16get(ds, 0x08dc);
        es = memory16get(ds, 0x08dc + 2);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0003);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 16, 0x8888);
        memory16set(es, r16[bx] + 18, ds);
        memory16set(es, r16[bx] + 24, 0x0003);
        memory16set(es, r16[bx] + 26, 0x0004);
        memory16set(es, r16[bx] + 30, 0x0003);
        memory16set(es, r16[bx] + 32, 0x0002);
        r16[bx] = memory16get(ds, 0x08e0);
        es = memory16get(ds, 0x08e0 + 2);
        memory16set(es, r16[bx], 0x0001);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 24, 0x0003);
        memory16set(es, r16[bx] + 26, 0x0002);
        memory16set(es, r16[bx] + 30, 0x0003);
        memory16set(es, r16[bx] + 32, 0x0002);
        r16[bx] = memory16get(ds, 0x08e4);
        es = memory16get(ds, 0x08e4 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 32, 0x0002);
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_7551() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        push(si);
        push(di);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x7562;
            break;
        }
        yield* sub_ca53();
    case 0x7562:
        push(ds);
        r16[ax] = 0x0928;
        push(r16[ax]);
        yield* sub_91d7();
        sp += 0x0004;
        r16[ax] = memory16get(ds, 0x7928);
        r16[dx] = memory16get(ds, 0x7926);
        memory16set(ds, 0x857e, r16[dx]);
        memory16set(ds, 0x8580, r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_923f();
        sp += 0x0004;
        si = r16[ax];
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x094e));
        push(memory16get(ds, 0x094c));
        push(memory16get(ds, 0x8580));
        push(memory16get(ds, 0x857e));
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        r16[ax] = 0;
        r16[dx] = 0x7d63;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        push(memory16get(ds, 0x8580));
        push(memory16get(ds, 0x857e));
        yield* sub_9a2a();
        sp += 0x000c;
        if (memory16get(ds, 0x541d) != 0x0001) {
            pc = 0x760a;
            break;
        }
        r16[ax] = memory16get(ds, 0x8580);
        r16[dx] = memory16get(ds, 0x857e);
        memory16set(ds, 0x9b96, r16[dx]);
        memory16set(ds, 0x9b98, r16[ax]);
        memory[ss*16 + bp - 5] = 0x00;
        pc = 0x7604;
        break;
    case 0x75e7:
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9b96);
        es = memory16get(ds, 0x9b96 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        di = r16[ax];
        r8[al] = memory[ds*16 + di + 1822];
        memory[es*16 + r16[bx] + 35] = r8[al];
        memory[ss*16 + bp - 5] += 1;
    case 0x7604:
        if (memory[ss*16 + bp - 5] < 0x10) {
            pc = 0x75e7;
            break;
        }
    case 0x760a:
        yield* sub_5337();
        r16[ax] = memory16get(ds, 0x8580);
        r16[dx] = memory16get(ds, 0x857e);
        r16[dx] += 0x0063;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory16set(es, r16[bx] + 6, 0x0000);
        memory16set(es, r16[bx] + 8, 0x0000);
        memory16set(es, r16[bx] + 10, 0x0014);
        memory16set(es, r16[bx] + 12, 0x0019);
        memory16set(es, r16[bx] + 14, 0x0001);
        memory16set(es, r16[bx] + 20, 0x0000);
        memory16set(es, r16[bx] + 22, 0x0000);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0014);
        memory16set(es, r16[bx] + 32, 0x0019);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9f8c();
        sp += 0x0004;
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ds, 0x8580));
        push(memory16get(ds, 0x857e));
        yield* sub_9a63();
        sp += 0x0006;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_9a9a();
        sp++;
        sp++;
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_9aad();
        sp++;
        sp++;
        yield* sub_b734();
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 14, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0001);
        memory16set(es, r16[bx] + 32, 0x0002);
        yield* sub_76b1();
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_76b1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000a;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x76c0;
            break;
        }
        yield* sub_ca53();
    case 0x76c0:
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        memory[ss*16 + bp - 9] = 0x00;
        memory[ss*16 + bp - 1] = 0x00;
        pc = 0x7879;
        break;
    case 0x76d3:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += 0x08f0;
        memory16set(ds, 0x8574, r16[ax]);
        memory16set(ds, 0x8576, ds);
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[ax] = memory16get(es, r16[bx] + 6);
        r16[dx] = memory16get(es, r16[bx] + 4);
        if (r16[ax] <= memory16get(ds, 0xa0d6)) {
            pc = 0x76fd;
            break;
        }
        pc = 0x77d1;
        break;
    case 0x76fd:
        if (r16[ax] < memory16get(ds, 0xa0d6)) {
            pc = 0x7708;
            break;
        }
        if (r16[dx] < memory16get(ds, 0xa0d4)) {
            pc = 0x7708;
            break;
        }
        pc = 0x77d1;
        break;
    case 0x7708:
        r8[al] = memory[ss*16 + bp - 9];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x7714;
            break;
        }
        pc = 0x77d1;
        break;
    case 0x7714:
        memory[ss*16 + bp - 9] = 0x01;
        r8[al] = memory[ss*16 + bp - 1];
        memory[ss*16 + bp - 2] = r8[al];
        r16[ax] = memory16get(ds, 0x0922);
        r16[dx] = memory16get(ds, 0x0920);
        memory16set(ss, bp - 6, r16[dx]);
        memory16set(ss, bp - 4, r16[ax]);
        memory[ss*16 + bp - 10] = 0x06;
        pc = 0x7784;
        break;
    case 0x7731:
        r8[al] = memory[ss*16 + bp - 10];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 2282);
        r16[dx] = memory16get(ds, r16[bx] + 2280);
        r8[bl] = memory[ss*16 + bp - 10];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        memory16set(ds, r16[bx] + 2288, r16[dx]);
        memory16set(ds, r16[bx] + 2290, r16[ax]);
        r8[al] = memory[ss*16 + bp - 10];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 2286);
        r16[dx] = memory16get(ds, r16[bx] + 2284);
        r8[bl] = memory[ss*16 + bp - 10];
        r8[bh] = 0x00;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        memory16set(ds, r16[bx] + 2292, r16[dx]);
        memory16set(ds, r16[bx] + 2294, r16[ax]);
        memory[ss*16 + bp - 10] -= 1;
    case 0x7784:
        r8[al] = memory[ss*16 + bp - 10];
        if (r8[al] > memory[ss*16 + bp - 1]) {
            pc = 0x7731;
            break;
        }
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[ax] = memory16get(ss, bp - 4);
        r16[dx] = memory16get(ss, bp - 6);
        memory16set(es, r16[bx], r16[dx]);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory[ss*16 + bp - 10] = 0x00;
        pc = 0x77b8;
        break;
    case 0x77a3:
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[tx] = r16[bx];
        r16[bx] = memory16get(es, r16[tx]);
        es = memory16get(es, r16[tx] + 2);
        r8[al] = memory[ss*16 + bp - 10];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        memory[es*16 + r16[bx]] = 0x41;
        memory[ss*16 + bp - 10] += 1;
    case 0x77b8:
        if (memory[ss*16 + bp - 10] < 0x08) {
            pc = 0x77a3;
            break;
        }
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[ax] = memory16get(ds, 0xa0d6);
        r16[dx] = memory16get(ds, 0xa0d4);
        memory16set(es, r16[bx] + 4, r16[dx]);
        memory16set(es, r16[bx] + 6, r16[ax]);
    case 0x77d1:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[ax] += 0x0041;
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory[ss*16 + bp - 7] = 0x00;
        pc = 0x784a;
        break;
    case 0x77eb:
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[tx] = r16[bx];
        r16[bx] = memory16get(es, r16[tx]);
        es = memory16get(es, r16[tx] + 2);
        r8[al] = memory[ss*16 + bp - 7];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 8] = r8[al];
        if (r8[al] != 0x2e) {
            pc = 0x781a;
            break;
        }
        if (memory[ss*16 + bp - 9] == 0x00) {
            pc = 0x7815;
            break;
        }
        r8[al] = memory[ss*16 + bp - 2];
        if (r8[al] != memory[ss*16 + bp - 1]) {
            pc = 0x7815;
            break;
        }
        r8[al] = 0x5b;
        pc = 0x7817;
        break;
    case 0x7815:
        r8[al] = 0x20;
    case 0x7817:
        memory[ss*16 + bp - 8] = r8[al];
    case 0x781a:
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r8[al] = memory[ss*16 + bp - 8];
        r8[ah] = 0x00;
        r16[ax] += 0x0175;
        memory16set(es, r16[bx] + 4, r16[ax]);
        r8[al] = memory[ss*16 + bp - 7];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        memory16set(es, r16[bx], r16[ax]);
        if (memory[ss*16 + bp - 8] == 0x20) {
            pc = 0x7847;
            break;
        }
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x7847:
        memory[ss*16 + bp - 7] += 1;
    case 0x784a:
        if (memory[ss*16 + bp - 7] < 0x08) {
            pc = 0x77eb;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[ax] += 0x0041;
        push(r16[ax]);
        r16[ax] = 0x00b0;
        push(r16[ax]);
        r8[al] = 0x07;
        push(r16[ax]);
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        push(memory16get(es, r16[bx] + 6));
        push(memory16get(es, r16[bx] + 4));
        yield* sub_7f0d();
        sp += 0x000a;
        memory[ss*16 + bp - 1] += 1;
    case 0x7879:
        if (memory[ss*16 + bp - 1] >= 0x07) {
            pc = 0x7882;
            break;
        }
        pc = 0x76d3;
        break;
    case 0x7882:
        if (memory[ss*16 + bp - 9] == 0x00) {
            pc = 0x7893;
            break;
        }
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        yield* sub_78a3();
        sp++;
        sp++;
        pc = 0x7896;
        break;
    case 0x7893:
        yield* sub_515f();
    case 0x7896:
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_b2e0();
        sp++;
        sp++;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_78a3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0006;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x78b2;
            break;
        }
        yield* sub_ca53();
    case 0x78b2:
        memory[ss*16 + bp - 2] = 0x00;
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += 0x08f0;
        memory16set(ds, 0x8574, r16[ax]);
        memory16set(ds, 0x8576, ds);
        memory16set(ss, bp - 6, 0x01b6);
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[tx] = r16[bx];
        r16[bx] = memory16get(es, r16[tx]);
        es = memory16get(es, r16[tx] + 2);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        memory[es*16 + r16[bx]] = 0x41;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        memory16set(es, r16[bx] + 20, r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] += 0x0008;
        memory16set(es, r16[bx] + 22, r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        r8[al] += 0x41;
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7b30;
        break;
    case 0x791a:
        bumpyScene = "highscores";
        if (!(memory[ss*16 + bp - 1] & 0x01)) {
            pc = 0x7984;
            break;
        }
        if (memory16gets(ss, bp - 6) <= signed16(0x01ac)) {
            pc = 0x7984;
            break;
        }
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) - 1);
        if (memory16get(ss, bp - 6) != 0x01d0) {
            pc = 0x7936;
            break;
        }
        memory16set(ss, bp - 6, 0x01a3);
    case 0x7936:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0xfe8b;
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[tx] = r16[bx];
        r16[bx] = memory16get(es, r16[tx]);
        es = memory16get(es, r16[tx] + 2);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 6];
        memory[es*16 + r16[bx]] = r8[al];
        if (memory16get(ss, bp - 6) != 0x002e) {
            pc = 0x795e;
            break;
        }
        memory16set(ss, bp - 6, 0x005b);
    case 0x795e:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0175;
        memory16set(ss, bp - 6, r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        r8[al] += 0x41;
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7b30;
        break;
    case 0x7984:
        if (!(memory[ss*16 + bp - 1] & 0x02)) {
            pc = 0x79ee;
            break;
        }
        if (memory16gets(ss, bp - 6) >= signed16(0x01d0)) {
            pc = 0x79ee;
            break;
        }
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + 1);
        if (memory16get(ss, bp - 6) != 0x01d0) {
            pc = 0x79a0;
            break;
        }
        memory16set(ss, bp - 6, 0x01a3);
    case 0x79a0:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0xfe8b;
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[tx] = r16[bx];
        r16[bx] = memory16get(es, r16[tx]);
        es = memory16get(es, r16[tx] + 2);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 6];
        memory[es*16 + r16[bx]] = r8[al];
        if (memory16get(ss, bp - 6) != 0x002e) {
            pc = 0x79c8;
            break;
        }
        memory16set(ss, bp - 6, 0x005b);
    case 0x79c8:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0175;
        memory16set(ss, bp - 6, r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        r8[al] += 0x41;
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7b30;
        break;
    case 0x79ee:
        if (memory[ss*16 + bp - 1] & 0x04) {
            pc = 0x79f7;
            break;
        }
        pc = 0x7a7b;
        break;
    case 0x79f7:
        if (memory[ss*16 + bp - 2] == 0x00) {
            pc = 0x7a7b;
            break;
        }
        if (memory16get(ss, bp - 6) != 0x01d0) {
            pc = 0x7a09;
            break;
        }
        memory16set(ss, bp - 6, 0x01a3);
    case 0x7a09:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0xfe8b;
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[tx] = r16[bx];
        r16[bx] = memory16get(es, r16[tx]);
        es = memory16get(es, r16[tx] + 2);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 6];
        memory[es*16 + r16[bx]] = r8[al];
        memory[ss*16 + bp - 2] -= 1;
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[tx] = r16[bx];
        r16[bx] = memory16get(es, r16[tx]);
        es = memory16get(es, r16[tx] + 2);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[ah] = 0x00;
        memory16set(ss, bp - 6, r16[ax]);
        if (memory16get(ss, bp - 6) != 0x002e) {
            pc = 0x7a4a;
            break;
        }
        memory16set(ss, bp - 6, 0x005b);
    case 0x7a4a:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0175;
        memory16set(ss, bp - 6, r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        r8[al] = 0x00;
        push(r16[ax]);
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        r8[al] += 0x41;
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7b30;
        break;
    case 0x7a7b:
        if (memory[ss*16 + bp - 1] & 0x08) {
            pc = 0x7a84;
            break;
        }
        pc = 0x7b07;
        break;
    case 0x7a84:
        if (memory[ss*16 + bp - 2] >= 0x07) {
            pc = 0x7b07;
            break;
        }
        if (memory16get(ss, bp - 6) != 0x01d0) {
            pc = 0x7a96;
            break;
        }
        memory16set(ss, bp - 6, 0x01a3);
    case 0x7a96:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0xfe8b;
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[tx] = r16[bx];
        r16[bx] = memory16get(es, r16[tx]);
        es = memory16get(es, r16[tx] + 2);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 6];
        memory[es*16 + r16[bx]] = r8[al];
        memory[ss*16 + bp - 2] += 1;
        r16[bx] = memory16get(ds, 0x8574);
        es = memory16get(ds, 0x8574 + 2);
        r16[tx] = r16[bx];
        r16[bx] = memory16get(es, r16[tx]);
        es = memory16get(es, r16[tx] + 2);
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[ah] = 0x00;
        memory16set(ss, bp - 6, r16[ax]);
        if (memory16get(ss, bp - 6) != 0x002e) {
            pc = 0x7ad7;
            break;
        }
        memory16set(ss, bp - 6, 0x005b);
    case 0x7ad7:
        r16[ax] = memory16get(ss, bp - 6);
        r16[ax] += 0x0175;
        memory16set(ss, bp - 6, r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        r8[al] = 0x00;
        push(r16[ax]);
        push(memory16get(ss, bp - 6));
        r8[al] = memory[ss*16 + bp - 2];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        r8[al] += 0x41;
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7b30;
        break;
    case 0x7b07:
        memory[ss*16 + bp - 3] += 1;
        if (!(memory[ss*16 + bp - 3] & 0x08)) {
            pc = 0x7b1d;
            break;
        }
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9a1a();
        pc = 0x7b25;
        break;
    case 0x7b1d:
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
    case 0x7b25:
        sp += 0x0004;
        r8[al] = 0x01;
        push(r16[ax]);
        yield* sub_24b7();
        sp++;
        sp++;
    case 0x7b30:
        r8[al] = 0x00;
        push(r16[ax]);
        yield* sub_9472();
        sp++;
        sp++;
        memory[ss*16 + bp - 1] = r8[al];
        r8[ah] = 0x00;
        r16[ax] &= 0x0010;
        if (r16[ax] == 0x0010) {
            pc = 0x7b48;
            break;
        }
        pc = 0x791a;
        break;
    case 0x7b48:
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_7b57() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0014;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x7b66;
            break;
        }
        yield* sub_ca53();
    case 0x7b66:
        push(ss);
        r16[ax] = bp - 0xa;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x256a;
        push(r16[ax]);
        r16[cx] = 0x0004;
        yield* sub_c8c5();
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        memory16set(es, r16[bx] + 14, 0x0000);
        memory16set(es, r16[bx] + 28, 0x0000);
        memory16set(es, r16[bx] + 30, 0x0001);
        memory16set(es, r16[bx] + 32, 0x0002);
        r8[al] = 0x00;
        memory[ss*16 + bp - 6] = r8[al];
        memory[ss*16 + bp - 3] = r8[al];
        r16[ax] = memory16get(ss, bp - 8);
        r16[dx] = memory16get(ss, bp - 10);
        memory16set(ss, bp - 14, r16[dx]);
        memory16set(ss, bp - 12, r16[ax]);
        memory[ss*16 + bp - 2] = 0x00;
        pc = 0x7bbd;
        break;
    case 0x7bac:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 14);
        es = memory16get(ss, bp - 14 + 2);
        r16[bx] += r16[ax];
        memory[es*16 + r16[bx]] = 0x41;
        memory[ss*16 + bp - 2] += 1;
    case 0x7bbd:
        if (memory[ss*16 + bp - 2] < 0x06) {
            pc = 0x7bac;
            break;
        }
        memory16set(ss, bp - 20, 0x01b6);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 14);
        es = memory16get(ss, bp - 14 + 2);
        r16[bx] += r16[ax];
        memory[es*16 + r16[bx]] = 0x41;
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0x00;
        memory16set(es, r16[bx] + 20, r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        memory16set(es, r16[bx] + 22, r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        push(memory16get(ss, bp - 20));
        r8[al] = memory[ss*16 + bp + 6];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7dff;
        break;
    case 0x7c09:
        if (!(memory[ss*16 + bp - 1] & 0x01)) {
            pc = 0x7c6d;
            break;
        }
        if (memory16gets(ss, bp - 20) <= signed16(0x01ac)) {
            pc = 0x7c6d;
            break;
        }
        memory16set(ss, bp - 20, memory16get(ss, bp - 20) - 1);
        if (memory16get(ss, bp - 20) != 0x01d0) {
            pc = 0x7c25;
            break;
        }
        memory16set(ss, bp - 20, 0x01a3);
    case 0x7c25:
        r16[ax] = memory16get(ss, bp - 20);
        r16[ax] += 0xfe8b;
        memory16set(ss, bp - 20, r16[ax]);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 14);
        es = memory16get(ss, bp - 14 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 20];
        memory[es*16 + r16[bx]] = r8[al];
        if (memory16get(ss, bp - 20) != 0x002e) {
            pc = 0x7c49;
            break;
        }
        memory16set(ss, bp - 20, 0x005b);
    case 0x7c49:
        r16[ax] = memory16get(ss, bp - 20);
        r16[ax] += 0x0175;
        memory16set(ss, bp - 20, r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        push(memory16get(ss, bp - 20));
        r8[al] = memory[ss*16 + bp + 6];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7dff;
        break;
    case 0x7c6d:
        if (!(memory[ss*16 + bp - 1] & 0x02)) {
            pc = 0x7cd1;
            break;
        }
        if (memory16gets(ss, bp - 20) >= signed16(0x01d0)) {
            pc = 0x7cd1;
            break;
        }
        memory16set(ss, bp - 20, memory16get(ss, bp - 20) + 1);
        if (memory16get(ss, bp - 20) != 0x01d0) {
            pc = 0x7c89;
            break;
        }
        memory16set(ss, bp - 20, 0x01a3);
    case 0x7c89:
        r16[ax] = memory16get(ss, bp - 20);
        r16[ax] += 0xfe8b;
        memory16set(ss, bp - 20, r16[ax]);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 14);
        es = memory16get(ss, bp - 14 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 20];
        memory[es*16 + r16[bx]] = r8[al];
        if (memory16get(ss, bp - 20) != 0x002e) {
            pc = 0x7cad;
            break;
        }
        memory16set(ss, bp - 20, 0x005b);
    case 0x7cad:
        r16[ax] = memory16get(ss, bp - 20);
        r16[ax] += 0x0175;
        memory16set(ss, bp - 20, r16[ax]);
        r8[al] = 0x01;
        push(r16[ax]);
        push(memory16get(ss, bp - 20));
        r8[al] = memory[ss*16 + bp + 6];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7dff;
        break;
    case 0x7cd1:
        if (!(memory[ss*16 + bp - 1] & 0x04)) {
            pc = 0x7d54;
            break;
        }
        if (memory[ss*16 + bp - 3] == 0x00) {
            pc = 0x7d54;
            break;
        }
        if (memory16get(ss, bp - 20) != 0x01d0) {
            pc = 0x7ce9;
            break;
        }
        memory16set(ss, bp - 20, 0x01a3);
    case 0x7ce9:
        r16[ax] = memory16get(ss, bp - 20);
        r16[ax] += 0xfe8b;
        memory16set(ss, bp - 20, r16[ax]);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 14);
        es = memory16get(ss, bp - 14 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 20];
        memory[es*16 + r16[bx]] = r8[al];
        memory[ss*16 + bp - 3] -= 1;
        memory[ss*16 + bp + 6] -= 1;
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 14);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[ah] = 0x00;
        memory16set(ss, bp - 20, r16[ax]);
        if (memory16get(ss, bp - 20) != 0x002e) {
            pc = 0x7d25;
            break;
        }
        memory16set(ss, bp - 20, 0x005b);
    case 0x7d25:
        r16[ax] = memory16get(ss, bp - 20);
        r16[ax] += 0x0175;
        memory16set(ss, bp - 20, r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        r8[al] = 0x00;
        push(r16[ax]);
        push(memory16get(ss, bp - 20));
        r8[al] = memory[ss*16 + bp + 6];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7dff;
        break;
    case 0x7d54:
        if (!(memory[ss*16 + bp - 1] & 0x08)) {
            pc = 0x7dd6;
            break;
        }
        if (memory[ss*16 + bp - 3] >= 0x05) {
            pc = 0x7dd6;
            break;
        }
        if (memory16get(ss, bp - 20) != 0x01d0) {
            pc = 0x7d6c;
            break;
        }
        memory16set(ss, bp - 20, 0x01a3);
    case 0x7d6c:
        r16[ax] = memory16get(ss, bp - 20);
        r16[ax] += 0xfe8b;
        memory16set(ss, bp - 20, r16[ax]);
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 14);
        es = memory16get(ss, bp - 14 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[ss*16 + bp - 20];
        memory[es*16 + r16[bx]] = r8[al];
        memory[ss*16 + bp - 3] += 1;
        memory[ss*16 + bp + 6] += 1;
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 14);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[ah] = 0x00;
        memory16set(ss, bp - 20, r16[ax]);
        if (memory16get(ss, bp - 20) != 0x002e) {
            pc = 0x7da8;
            break;
        }
        memory16set(ss, bp - 20, 0x005b);
    case 0x7da8:
        r16[ax] = memory16get(ss, bp - 20);
        r16[ax] += 0x0175;
        memory16set(ss, bp - 20, r16[ax]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        r8[al] = 0x00;
        push(r16[ax]);
        push(memory16get(ss, bp - 20));
        r8[al] = memory[ss*16 + bp + 6];
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[cl] = 0x04;
        r8[al] <<= r8[cl];
        push(r16[ax]);
        yield* sub_7eab();
        sp += 0x0008;
        pc = 0x7dff;
        break;
    case 0x7dd6:
        memory[ss*16 + bp - 6] += 1;
        if (!(memory[ss*16 + bp - 6] & 0x08)) {
            pc = 0x7dec;
            break;
        }
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9a1a();
        pc = 0x7df4;
        break;
    case 0x7dec:
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
    case 0x7df4:
        sp += 0x0004;
        r8[al] = 0x01;
        push(r16[ax]);
        yield* sub_24b7();
        sp++;
        sp++;
    case 0x7dff:
        r8[al] = 0x00;
        push(r16[ax]);
        yield* sub_9472();
        sp++;
        sp++;
        memory[ss*16 + bp - 1] = r8[al];
        r8[ah] = 0x00;
        r16[ax] &= 0x0010;
        if (r16[ax] == 0x0010) {
            pc = 0x7e17;
            break;
        }
        pc = 0x7c09;
        break;
    case 0x7e17:
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        r8[al] = 0x00;
        memory[ss*16 + bp - 4] = r8[al];
        memory[ss*16 + bp - 2] = r8[al];
        pc = 0x7e95;
        break;
    case 0x7e2c:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 4958);
        r16[dx] = memory16get(ds, r16[bx] + 4956);
        memory16set(ss, bp - 18, r16[dx]);
        memory16set(ss, bp - 16, r16[ax]);
        r8[al] = 0x00;
        memory[ss*16 + bp - 5] = r8[al];
        memory[ss*16 + bp - 3] = r8[al];
        pc = 0x7e72;
        break;
    case 0x7e4f:
        r8[al] = memory[ss*16 + bp - 3];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp - 14);
        es = memory16get(ss, bp - 14 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        r8[dl] = memory[ss*16 + bp - 3];
        r8[dh] = 0x00;
        r16[bx] = memory16get(ss, bp - 18);
        es = memory16get(ss, bp - 18 + 2);
        r16[bx] += r16[dx];
        if (r8[al] == memory[es*16 + r16[bx]]) {
            pc = 0x7e6f;
            break;
        }
        memory[ss*16 + bp - 5] = 0x01;
    case 0x7e6f:
        memory[ss*16 + bp - 3] += 1;
    case 0x7e72:
        if (memory[ss*16 + bp - 3] >= 0x06) {
            pc = 0x7e81;
            break;
        }
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x7e4f;
            break;
        }
    case 0x7e81:
        r8[al] = memory[ss*16 + bp - 5];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x7e92;
            break;
        }
        r8[al] = memory[ss*16 + bp - 2];
        r8[al] += 0x02;
        memory[ss*16 + bp - 4] = r8[al];
    case 0x7e92:
        memory[ss*16 + bp - 2] += 1;
    case 0x7e95:
        if (memory[ss*16 + bp - 2] >= 0x08) {
            pc = 0x7ea4;
            break;
        }
        r8[al] = memory[ss*16 + bp - 4];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x7e2c;
            break;
        }
    case 0x7ea4:
        r8[al] = memory[ss*16 + bp - 4];
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_7eab() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x7eb7;
            break;
        }
        yield* sub_ca53();
    case 0x7eb7:
        r16[bx] = memory16get(ds, 0x0574);
        es = memory16get(ds, 0x0574 + 2);
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0x00;
        memory16set(es, r16[bx] + 20, r16[ax]);
        push(memory16get(ds, 0x0576));
        push(memory16get(ds, 0x0574));
        yield* sub_9a1a();
        sp += 0x0004;
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r16[ax] = memory16get(ss, bp + 8);
        memory16set(es, r16[bx] + 4, r16[ax]);
        r8[al] = memory[ss*16 + bp + 6];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        memory16set(es, r16[bx], r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        memory16set(es, r16[bx] + 2, r16[ax]);
        if (memory[ss*16 + bp + 10] == 0x00) {
            pc = 0x7f03;
            break;
        }
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
    case 0x7f03:
        r8[al] = 0x08;
        push(r16[ax]);
        yield* sub_24b7();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_7f0d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000c;
        push(si);
        si = memory16get(ss, bp + 10);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x7f20;
            break;
        }
        yield* sub_ca53();
    case 0x7f20:
        r8[al] = memory[ss*16 + bp + 8];
        memory[ss*16 + bp - 12] = r8[al];
        memory[ss*16 + bp - 11] = 0x00;
        pc = 0x7f3f;
        break;
    case 0x7f2c:
        r8[al] = memory[ss*16 + bp - 11];
        memory[ss*16 + bp - 11] += 1;
        r8[ah] = 0x00;
        r16[dx] = bp - 0xa;
        r16[ax] += r16[dx];
        r16[bx] = r16[ax];
        memory[ss*16 + r16[bx]] = 0x20;
    case 0x7f3f:
        r8[al] = memory[ss*16 + bp - 11];
        if (r8[al] < memory[ss*16 + bp + 8]) {
            pc = 0x7f2c;
            break;
        }
        r8[al] = memory[ss*16 + bp + 8];
        r8[ah] = 0x00;
        r16[dx] = bp - 0xa;
        r16[ax] += r16[dx];
        r16[bx] = r16[ax];
        memory[ss*16 + r16[bx]] = 0x00;
        pc = 0x7f9e;
        break;
    case 0x7f59:
        r8[al] = memory[ss*16 + bp + 4];
        memory[ss*16 + bp - 1] = r8[al];
        r16[ax] = 0;
        r16[dx] = 0x000a;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_c7be();
        memory16set(ss, bp + 4, r16[ax]);
        r16[bx] = r16[ax];
        memory16set(ss, bp + 6, r16[dx]);
        r16[cx] = r16[dx];
        r16[dx] = 0;
        r16[ax] = 0x000a;
        yield* sub_c8e4();
        r8[dl] = memory[ss*16 + bp - 1];
        r8[dl] -= r8[al];
        memory[ss*16 + bp - 1] = r8[dl];
        r8[al] = memory[ss*16 + bp + 8];
        r8[ah] = 0x00;
        r16[dx] = bp - 0xa;
        r16[ax] += r16[dx];
        r8[dl] = memory[ss*16 + bp - 1];
        r8[dl] += 0x30;
        r16[bx] = r16[ax];
        memory[ss*16 + r16[bx]] = r8[dl];
    case 0x7f9e:
        r8[al] = memory[ss*16 + bp + 8];
        memory[ss*16 + bp + 8] -= 1;
        if (r8[al]) {
            pc = 0x7f59;
            break;
        }
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        r16[ax] = memory16get(ss, bp + 12);
        memory16set(es, r16[bx] + 2, r16[ax]);
        memory[ss*16 + bp - 11] = 0x00;
        pc = 0x7ff3;
        break;
    case 0x7fb9:
        r8[al] = memory[ss*16 + bp - 11];
        r8[ah] = 0x00;
        r16[dx] = bp - 0xa;
        r16[ax] += r16[dx];
        r16[bx] = r16[ax];
        r8[al] = memory[ss*16 + r16[bx]];
        r8[ah] = 0x00;
        r16[ax] += 0x017c;
        r16[bx] = memory16get(ds, 0x8884);
        es = memory16get(ds, 0x8884 + 2);
        memory16set(es, r16[bx] + 4, r16[ax]);
        r8[al] = memory[ss*16 + bp - 11];
        r8[ah] = 0x00;
        r8[cl] = 0x04;
        r16[ax] <<= r8[cl];
        r16[dx] = si;
        r16[dx] += r16[ax];
        memory16set(es, r16[bx], r16[dx]);
        push(ds);
        r16[ax] = 0x792e;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        memory[ss*16 + bp - 11] += 1;
    case 0x7ff3:
        r8[al] = memory[ss*16 + bp - 11];
        if (r8[al] < memory[ss*16 + bp - 12]) {
            pc = 0x7fb9;
            break;
        }
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8000() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x800e;
            break;
        }
        yield* sub_ca53();
    case 0x800e:
        r16[bx] = memory16get(ds, 0xa0d0);
        es = memory16get(ds, 0xa0d0 + 2);
        memory16set(es, r16[bx] + 4, 0x01aa);
        memory16set(es, r16[bx] + 2, 0x0000);
        r8[al] = memory[ds*16 + 0x791a];
        memory[ss*16 + bp - 1] = r8[al];
        pc = 0x8049;
        break;
    case 0x8026:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[ax] += 0x0050;
        r16[bx] = memory16get(ds, 0xa0d0);
        es = memory16get(ds, 0xa0d0 + 2);
        memory16set(es, r16[bx], r16[ax]);
        push(ds);
        r16[ax] = 0x7986;
        push(r16[ax]);
        yield* sub_b2fa();
        sp += 0x0004;
        memory[ss*16 + bp - 1] -= 1;
    case 0x8049:
        if (memory[ss*16 + bp - 1] != 0x00) {
            pc = 0x8026;
            break;
        }
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8053() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8061;
            break;
        }
        yield* sub_ca53();
    case 0x8061:
        memory16set(ds, 0x9ba6, 0x0886);
        memory16set(ds, 0x9ba8, ds);
        r16[bx] = memory16get(ds, 0x9ba6);
        es = memory16get(ds, 0x9ba6 + 2);
        memory[es*16 + r16[bx]] = 0xff;
        memory[ds*16 + 0xa1a6] = 0x00;
        r8[dl] = 0x00;
        pc = 0x809b;
        break;
    case 0x807c:
        r8[al] = r8[dl];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 48];
        r8[cl] = r8[al];
        if (r8[cl] < 0x0e) {
            pc = 0x8099;
            break;
        }
        if (r8[cl] >= 0x12) {
            pc = 0x8099;
            break;
        }
        memory[ds*16 + 0xa1a6] = r8[al];
    case 0x8099:
        r8[dl]++;
    case 0x809b:
        if (r8[dl] >= 0x30) {
            pc = 0x80a9;
            break;
        }
        r8[al] = memory[ds*16 + 0xa1a6];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x807c;
            break;
        }
    case 0x80a9:
        if (memory[ds*16 + 0xa1a6] != 0x00) {
            pc = 0x80b3;
            break;
        }
        pc = 0x8168;
        break;
    case 0x80b3:
        r8[al] = 0x00;
        memory[ss*16 + bp - 1] = r8[al];
        r8[dl] = r8[al];
        pc = 0x80e2;
        break;
    case 0x80bc:
        r8[al] = r8[dl];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 48];
        r8[cl] = r8[al];
        if (r8[cl] < 0x0e) {
            pc = 0x80e0;
            break;
        }
        if (r8[cl] >= 0x12) {
            pc = 0x80e0;
            break;
        }
        if (r8[al] == memory[ds*16 + 0xa1a6]) {
            pc = 0x80e0;
            break;
        }
        memory[ss*16 + bp - 1] = 0x01;
    case 0x80e0:
        r8[dl]++;
    case 0x80e2:
        if (r8[dl] >= 0x30) {
            pc = 0x80f0;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x80bc;
            break;
        }
    case 0x80f0:
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x8168;
            break;
        }
        r8[al] = 0x00;
        memory[ss*16 + bp - 2] = r8[al];
        memory[ss*16 + bp - 1] = r8[al];
        r8[dl] = 0x00;
        pc = 0x812b;
        break;
    case 0x8105:
        r8[al] = r8[dl];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx] + 48] != 0x05) {
            pc = 0x8129;
            break;
        }
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9ba6);
        es = memory16get(ds, 0x9ba6 + 2);
        r16[bx] += r16[ax];
        r8[al] = r8[dl];
        memory[es*16 + r16[bx]] = r8[al];
        memory[ss*16 + bp - 2] += 1;
    case 0x8129:
        r8[dl]++;
    case 0x812b:
        if (r8[dl] >= 0x30) {
            pc = 0x8139;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x8105;
            break;
        }
    case 0x8139:
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9ba6);
        es = memory16get(ds, 0x9ba6 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx]] == 0xff) {
            pc = 0x8168;
            break;
        }
        r8[al] = memory[ss*16 + bp - 2];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0x9ba6);
        r16[bx] += r16[ax];
        memory[es*16 + r16[bx]] = 0xff;
        memory16set(ds, 0x9ba6, 0x0886);
        memory16set(ds, 0x9ba8, ds);
        memory[ds*16 + 0x79b7] = 0x00;
    case 0x8168:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_816c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8178;
            break;
        }
        yield* sub_ca53();
    case 0x8178:
        r16[bx] = memory16get(ds, 0x9ba6);
        es = memory16get(ds, 0x9ba6 + 2);
        if (memory[es*16 + r16[bx]] != 0xff) {
            pc = 0x8196;
            break;
        }
        memory16set(ds, 0x9ba6, 0x0886);
        memory16set(ds, 0x9ba8, ds);
        r16[bx] = memory16get(ds, 0x9ba6);
        es = memory16get(ds, 0x9ba6 + 2);
        memory[es*16 + r16[bx]] = 0xff;
        pc = 0x81d3;
        break;
    case 0x8196:
        r8[al] = memory[ds*16 + 0x79b7];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x81cf;
            break;
        }
        memory[ds*16 + 0x79b7] = 0x0a;
        r16[bx] = memory16get(ds, 0x9ba6);
        es = memory16get(ds, 0x9ba6 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ds*16 + 0x8570] = r8[al];
        r8[al] = 0x18;
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x81c1;
            break;
        }
        r8[al] = 0x11;
        pc = 0x81c3;
        break;
    case 0x81c1:
        r8[al] = 0x0e;
    case 0x81c3:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        memory16set(ds, 0x9ba6, memory16get(ds, 0x9ba6) + 1);
        pc = 0x81d3;
        break;
    case 0x81cf:
        memory[ds*16 + 0x79b7] -= 1;
    case 0x81d3:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_81d5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x81e1;
            break;
        }
        yield* sub_ca53();
    case 0x81e1:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x81ec;
            break;
        }
        r8[al] = 0x03;
        pc = 0x81ee;
        break;
    case 0x81ec:
        r8[al] = 0x0d;
    case 0x81ee:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_81f6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8202;
            break;
        }
        yield* sub_ca53();
    case 0x8202:
        if (memory[ds*16 + 0x855e] == 0x00) {
            pc = 0x8240;
            break;
        }
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx] + 47] != 0x0c) {
            pc = 0x8240;
            break;
        }
        memory[ds*16 + 0x792a] = 0x00;
        memory[ds*16 + 0xa0ce] = 0x01;
        r8[al] = 0x2e;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x8238;
            break;
        }
        r8[al] = 0x03;
        pc = 0x823a;
        break;
    case 0x8238:
        r8[al] = 0x0d;
    case 0x823a:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x8240:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8242() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x824e;
            break;
        }
        yield* sub_ca53();
    case 0x824e:
        if (memory[ds*16 + 0x855e] == 0x07) {
            pc = 0x828c;
            break;
        }
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx] + 48] != 0x0c) {
            pc = 0x828c;
            break;
        }
        memory[ds*16 + 0x792a] = 0x00;
        memory[ds*16 + 0xa0ce] = 0x01;
        r8[al] = 0x2e;
        push(r16[ax]);
        yield* sub_6133();
        sp++;
        sp++;
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x8284;
            break;
        }
        r8[al] = 0x03;
        pc = 0x8286;
        break;
    case 0x8284:
        r8[al] = 0x0d;
    case 0x8286:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x828c:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_828e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x829c;
            break;
        }
        yield* sub_ca53();
    case 0x829c:
        if (memory[ds*16 + 0x8552] == 0x03) {
            pc = 0x82d8;
            break;
        }
        if (memory[ds*16 + 0x8552] == 0x0f) {
            pc = 0x82d8;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x82be;
            break;
        }
        r8[al] = memory[ds*16 + 0x7924];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 9790];
        pc = 0x82c9;
        break;
    case 0x82be:
        r8[al] = memory[ds*16 + 0x7924];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 9742];
    case 0x82c9:
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x82d8;
            break;
        }
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x82d8:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_82dc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x82ea;
            break;
        }
        yield* sub_ca53();
    case 0x82ea:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x82fe;
            break;
        }
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 10126];
        pc = 0x8309;
        break;
    case 0x82fe:
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 10094];
    case 0x8309:
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x8318;
            break;
        }
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x8318:
        if (memory[ds*16 + 0x8551] < 0x0e) {
            pc = 0x8329;
            break;
        }
        if (memory[ds*16 + 0x8551] >= 0x12) {
            pc = 0x8329;
            break;
        }
        yield* sub_8053();
    case 0x8329:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_832d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8339;
            break;
        }
        yield* sub_ca53();
    case 0x8339:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x8344;
            break;
        }
        r8[al] = 0x0b;
        pc = 0x8346;
        break;
    case 0x8344:
        r8[al] = 0x2c;
    case 0x8346:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_834e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x835c;
            break;
        }
        yield* sub_ca53();
    case 0x835c:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x8370;
            break;
        }
        r8[al] = memory[ds*16 + 0x79b9];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 9982];
        pc = 0x837b;
        break;
    case 0x8370:
        r8[al] = memory[ds*16 + 0x79b9];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 9934];
    case 0x837b:
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x838a;
            break;
        }
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x838a:
        yield* sub_841e();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8391() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x839d;
            break;
        }
        yield* sub_ca53();
    case 0x839d:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x83a8;
            break;
        }
        r8[al] = 0x0e;
        pc = 0x83aa;
        break;
    case 0x83a8:
        r8[al] = 0x21;
    case 0x83aa:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_83b2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x83be;
            break;
        }
        yield* sub_ca53();
    case 0x83be:
        yield* sub_84e1();
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0xf8;
        memory[ds*16 + 0x856e] = r8[al];
        memory[ds*16 + 0x855c] -= 1;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_83cf() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x83db;
            break;
        }
        yield* sub_ca53();
    case 0x83db:
        yield* sub_84e1();
        r8[al] = memory[ds*16 + 0x856e];
        r8[al] += 0x08;
        memory[ds*16 + 0x856e] = r8[al];
        memory[ds*16 + 0x855c] += 1;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_83ec() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x83f8;
            break;
        }
        yield* sub_ca53();
    case 0x83f8:
        yield* sub_84e1();
        memory[ds*16 + 0x856e] -= 1;
        memory[ds*16 + 0x855e] -= 1;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8405() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8411;
            break;
        }
        yield* sub_ca53();
    case 0x8411:
        yield* sub_84e1();
        memory[ds*16 + 0x856e] += 1;
        memory[ds*16 + 0x855e] += 1;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_841e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x842a;
            break;
        }
        yield* sub_ca53();
    case 0x842a:
        r8[al] = memory[ds*16 + 0x7923];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x8455;
            break;
        }
        if (memory[ds*16 + 0x8244] & 0x10) {
            pc = 0x8441;
            break;
        }
        if (!(memory[ds*16 + 0x8244] & 0x01)) {
            pc = 0x8455;
            break;
        }
    case 0x8441:
        r8[al] = memory[ds*16 + 0x7924];
        memory[ds*16 + 0x7922] = r8[al];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 15578];
        push(r16[ax]);
        yield* sub_882e();
        sp++;
        sp++;
    case 0x8455:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8457() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8463;
            break;
        }
        yield* sub_ca53();
    case 0x8463:
        r8[al] = memory[ds*16 + 0xa1a7];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x84a0;
            break;
        }
        if (memory[ds*16 + 0x7924] != 0x02) {
            pc = 0x84a0;
            break;
        }
        if (!(memory[ds*16 + 0x8244] & 0x02)) {
            pc = 0x84a0;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x8485;
            break;
        }
        r8[al] = 0x04;
        pc = 0x8487;
        break;
    case 0x8485:
        r8[al] = 0x09;
    case 0x8487:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        memory[ds*16 + 0x79b4] = 0x34;
        r8[al] = 0x34;
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
    case 0x84a0:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_84a2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x84ae;
            break;
        }
        yield* sub_ca53();
    case 0x84ae:
        memory[ds*16 + 0x8244] = 0x00;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_84b5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x84c1;
            break;
        }
        yield* sub_ca53();
    case 0x84c1:
        r8[al] = memory[ds*16 + 0x8244];
        r8[al] &= 0x10;
        memory[ds*16 + 0x8244] = r8[al];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_84cb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x84d7;
            break;
        }
        yield* sub_ca53();
    case 0x84d7:
        r8[al] = memory[ds*16 + 0x8244];
        r8[al] &= 0x1d;
        memory[ds*16 + 0x8244] = r8[al];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_84e1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x84ed;
            break;
        }
        yield* sub_ca53();
    case 0x84ed:
        r8[al] = memory[ds*16 + 0x8244];
        r8[al] &= 0x0f;
        memory[ds*16 + 0x8244] = r8[al];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_84f7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8503;
            break;
        }
        yield* sub_ca53();
    case 0x8503:
        r8[al] = memory[ds*16 + 0x856e];
        push(r16[ax]);
        yield* sub_8ac4();
        sp++;
        sp++;
        if (memory[ds*16 + 0x79b8] == 0x00) {
            pc = 0x8516;
            break;
        }
        yield* sub_8ae4();
    case 0x8516:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8518() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8526;
            break;
        }
        yield* sub_ca53();
    case 0x8526:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x853a;
            break;
        }
        r8[al] = memory[ds*16 + 0x7924];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 9694];
        pc = 0x8545;
        break;
    case 0x853a:
        r8[al] = memory[ds*16 + 0x7924];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 9646];
    case 0x8545:
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x8554;
            break;
        }
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x8554:
        r8[al] = memory[ds*16 + 0x7924];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 15626];
        push(r16[ax]);
        yield* sub_8857();
        sp++;
        sp++;
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8569() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8575;
            break;
        }
        yield* sub_ca53();
    case 0x8575:
        if (memory[ds*16 + 0x8552] == 0x03) {
            pc = 0x858e;
            break;
        }
        if (memory[ds*16 + 0x8552] == 0x0f) {
            pc = 0x858e;
            break;
        }
        push(ds);
        r16[ax] = 0x3c7a;
        push(r16[ax]);
        yield* sub_8c3a();
        sp += 0x0004;
    case 0x858e:
        if (memory[ds*16 + 0x855e] == 0x00) {
            pc = 0x85a6;
            break;
        }
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 13758];
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
    case 0x85a6:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_85a8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x85b4;
            break;
        }
        yield* sub_ca53();
    case 0x85b4:
        if (memory[ds*16 + 0x8552] == 0x03) {
            pc = 0x85cd;
            break;
        }
        if (memory[ds*16 + 0x8552] == 0x0f) {
            pc = 0x85cd;
            break;
        }
        push(ds);
        r16[ax] = 0x3caa;
        push(r16[ax]);
        yield* sub_8c3a();
        sp += 0x0004;
    case 0x85cd:
        if (memory[ds*16 + 0x855e] == 0x07) {
            pc = 0x85e5;
            break;
        }
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 13790];
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
    case 0x85e5:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_85e7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x85f3;
            break;
        }
        yield* sub_ca53();
    case 0x85f3:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        yield* sub_8bf6();
        if (memory[ds*16 + 0x856c] != 0x5b) {
            pc = 0x8608;
            break;
        }
        memory[ds*16 + 0xa1b1] = 0x00;
    case 0x8608:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_860a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8616;
            break;
        }
        yield* sub_ca53();
    case 0x8616:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8618() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8624;
            break;
        }
        yield* sub_ca53();
    case 0x8624:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x862f;
            break;
        }
        r8[al] = 0x08;
        pc = 0x8631;
        break;
    case 0x862f:
        r8[al] = 0x2f;
    case 0x8631:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = 0x18;
        push(r16[ax]);
        yield* sub_8c64();
        sp++;
        sp++;
        if (memory[ds*16 + 0x855e] == 0x00) {
            pc = 0x8657;
            break;
        }
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 13822];
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
    case 0x8657:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8659() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8665;
            break;
        }
        yield* sub_ca53();
    case 0x8665:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x8670;
            break;
        }
        r8[al] = 0x08;
        pc = 0x8672;
        break;
    case 0x8670:
        r8[al] = 0x2f;
    case 0x8672:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = 0x19;
        push(r16[ax]);
        yield* sub_8c64();
        sp++;
        sp++;
        if (memory[ds*16 + 0x855e] == 0x07) {
            pc = 0x8698;
            break;
        }
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 13854];
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
    case 0x8698:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_869a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x86a6;
            break;
        }
        yield* sub_ca53();
    case 0x86a6:
        if (memory[ds*16 + 0x855e] == 0x00) {
            pc = 0x86b0;
            break;
        }
        yield* sub_86b2();
    case 0x86b0:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_86b2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x86be;
            break;
        }
        yield* sub_ca53();
    case 0x86be:
        push(ds);
        r16[ax] = 0x363e;
        push(r16[ax]);
        yield* sub_873a();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_86cb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x86d7;
            break;
        }
        yield* sub_ca53();
    case 0x86d7:
        if (memory[ds*16 + 0x855e] == 0x07) {
            pc = 0x86e1;
            break;
        }
        yield* sub_86e3();
    case 0x86e1:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_86e3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x86ef;
            break;
        }
        yield* sub_ca53();
    case 0x86ef:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x8570] = r8[al];
        push(ds);
        r16[ax] = 0x365e;
        push(r16[ax]);
        yield* sub_873a();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8702() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x870e;
            break;
        }
        yield* sub_ca53();
    case 0x870e:
        push(ds);
        r16[ax] = 0x363e;
        push(r16[ax]);
        yield* sub_873a();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_871b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8727;
            break;
        }
        yield* sub_ca53();
    case 0x8727:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x8570] = r8[al];
        push(ds);
        r16[ax] = 0x365e;
        push(r16[ax]);
        yield* sub_873a();
        sp += 0x0004;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_873a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8746;
            break;
        }
        yield* sub_ca53();
    case 0x8746:
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
        memory[ds*16 + 0x8244] = 0x00;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8760() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x876c;
            break;
        }
        yield* sub_ca53();
    case 0x876c:
        if (memory[ds*16 + 0x855e] == 0x00) {
            pc = 0x8789;
            break;
        }
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 13822];
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
        memory[ds*16 + 0x8244] = 0x00;
    case 0x8789:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_878b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8797;
            break;
        }
        yield* sub_ca53();
    case 0x8797:
        if (memory[ds*16 + 0x855e] == 0x07) {
            pc = 0x87b4;
            break;
        }
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 13854];
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
        memory[ds*16 + 0x8244] = 0x00;
    case 0x87b4:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_87b6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x87c2;
            break;
        }
        yield* sub_ca53();
    case 0x87c2:
        if (memory[ds*16 + 0x855e] == 0x00) {
            pc = 0x87cc;
            break;
        }
        yield* sub_87ce();
    case 0x87cc:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_87ce() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x87da;
            break;
        }
        yield* sub_ca53();
    case 0x87da:
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 13950];
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
        memory[ds*16 + 0x8244] = 0x00;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_87f2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x87fe;
            break;
        }
        yield* sub_ca53();
    case 0x87fe:
        if (memory[ds*16 + 0x855e] == 0x07) {
            pc = 0x8808;
            break;
        }
        yield* sub_880a();
    case 0x8808:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_880a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8816;
            break;
        }
        yield* sub_ca53();
    case 0x8816:
        r8[al] = memory[ds*16 + 0x8551];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 13982];
        push(r16[ax]);
        yield* sub_8959();
        sp++;
        sp++;
        memory[ds*16 + 0x8244] = 0x00;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_882e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x883a;
            break;
        }
        yield* sub_ca53();
    case 0x883a:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        if (memory[ss*16 + bp + 4] == 0x00) {
            pc = 0x8855;
            break;
        }
        r8[al] = memory[ss*16 + bp + 4];
        memory[ds*16 + 0xa1a7] = r8[al];
        r8[al] = memory[ss*16 + bp + 4];
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
    case 0x8855:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8857() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8863;
            break;
        }
        yield* sub_ca53();
    case 0x8863:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        if (memory[ss*16 + bp + 4] == 0x00) {
            pc = 0x8878;
            break;
        }
        r8[al] = memory[ss*16 + bp + 4];
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
    case 0x8878:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_887a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0008;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x888a;
            break;
        }
        yield* sub_ca53();
    case 0x888a:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 12000);
        r16[dx] = memory16get(ds, r16[bx] + 11998);
        memory16set(ss, bp - 4, r16[dx]);
        memory16set(ss, bp - 2, r16[ax]);
        r8[cl] = 0x00;
    case 0x88a5:
        r8[al] = r8[cl];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19570);
        r16[dx] = memory16get(ds, r16[bx] + 19568);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp + 4] = r8[al];
        r8[cl]++;
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x88a5;
            break;
        }
        if (memory[ss*16 + bp + 4] != 0xff) {
            pc = 0x8910;
            break;
        }
        r8[cl] = 0x00;
    case 0x88d6:
        r8[al] = r8[cl];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19570);
        r16[dx] = memory16get(ds, r16[bx] + 19568);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp + 4] = r8[al];
        r8[cl]++;
        if (memory[ss*16 + bp + 4] == 0x00) {
            pc = 0x8905;
            break;
        }
        if (memory[ss*16 + bp + 4] != 0xff) {
            pc = 0x88d6;
            break;
        }
    case 0x8905:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x8954;
            break;
        }
        pc = 0x891d;
        break;
    case 0x8910:
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[es*16 + r16[bx] + 1];
        if (r8[al] != memory[ds*16 + 0x856f]) {
            pc = 0x88a5;
            break;
        }
    case 0x891d:
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[ds*16 + 0x856f];
        memory[es*16 + r16[bx] + 1] = r8[al];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        push(es);
        si = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r8[al] = memory[es*16 + si];
        es = pop();
        memory[es*16 + r16[bx]] = r8[al];
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r16[ax] = memory16get(es, r16[bx] + 4);
        r16[dx] = memory16get(es, r16[bx] + 2);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory[es*16 + r16[bx]] = 0x01;
    case 0x8954:
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8959() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000a;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8969;
            break;
        }
        yield* sub_ca53();
    case 0x8969:
        r8[al] = memory[ss*16 + bp + 4];
        memory[ds*16 + 0x8566] = r8[al];
        if (r8[al]) {
            pc = 0x8976;
            break;
        }
        pc = 0x8a80;
        break;
    case 0x8976:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x898a;
            break;
        }
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 10062];
        pc = 0x8995;
        break;
    case 0x898a:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 10030];
    case 0x8995:
        memory[ss*16 + bp - 10] = r8[al];
        if (memory[ss*16 + bp - 10] == 0x00) {
            pc = 0x89a4;
            break;
        }
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x89a4:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 12888);
        r16[dx] = memory16get(ds, r16[bx] + 12886);
        memory16set(ss, bp - 4, r16[dx]);
        memory16set(ss, bp - 2, r16[ax]);
        memory[ss*16 + bp - 9] = 0x00;
    case 0x89c1:
        r8[al] = memory[ss*16 + bp - 9];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19646);
        r16[dx] = memory16get(ds, r16[bx] + 19644);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp + 4] = r8[al];
        memory[ss*16 + bp - 9] += 1;
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x89c1;
            break;
        }
        if (memory[ss*16 + bp + 4] != 0xff) {
            pc = 0x8a38;
            break;
        }
        memory[ss*16 + bp - 9] = 0x00;
    case 0x89f6:
        r8[al] = memory[ss*16 + bp - 9];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 19646);
        r16[dx] = memory16get(ds, r16[bx] + 19644);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp + 4] = r8[al];
        memory[ss*16 + bp - 9] += 1;
        if (memory[ss*16 + bp + 4] == 0x00) {
            pc = 0x8a27;
            break;
        }
        if (memory[ss*16 + bp + 4] != 0xff) {
            pc = 0x89f6;
            break;
        }
    case 0x8a27:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        if (!r16[ax]) {
            pc = 0x8a48;
            break;
        }
        if (memory[ss*16 + bp + 4] != 0xff) {
            pc = 0x8a80;
            break;
        }
        pc = 0x8a80;
        break;
    case 0x8a38:
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[es*16 + r16[bx] + 1];
        if (r8[al] == memory[ds*16 + 0x8570]) {
            pc = 0x8a48;
            break;
        }
        pc = 0x89c1;
        break;
    case 0x8a48:
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        r8[al] = memory[ds*16 + 0x8570];
        memory[es*16 + r16[bx] + 1] = r8[al];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        push(es);
        si = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r8[al] = memory[es*16 + si];
        es = pop();
        memory[es*16 + r16[bx] + 48] = r8[al];
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r16[ax] = memory16get(es, r16[bx] + 4);
        r16[dx] = memory16get(es, r16[bx] + 2);
        r16[bx] = memory16get(ss, bp - 8);
        es = memory16get(ss, bp - 8 + 2);
        memory16set(es, r16[bx] + 2, r16[dx]);
        memory16set(es, r16[bx] + 4, r16[ax]);
        memory[es*16 + r16[bx]] = 0x01;
    case 0x8a80:
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8a85() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8a91;
            break;
        }
        yield* sub_ca53();
    case 0x8a91:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        memory[ds*16 + 0x7921] = r8[al];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8aa4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8ab0;
            break;
        }
        yield* sub_ca53();
    case 0x8ab0:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 48];
        memory[ds*16 + 0x8551] = r8[al];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8ac4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8ad0;
            break;
        }
        yield* sub_ca53();
    case 0x8ad0:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 96];
        memory[ds*16 + 0x79b8] = r8[al];
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8ae4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8af0;
            break;
        }
        yield* sub_ca53();
    case 0x8af0:
        memory[ds*16 + 0x2810] = 0x0f;
        yield* sub_8b65();
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ds, 0xa0d8);
        es = memory16get(ds, 0xa0d8 + 2);
        r16[bx] += r16[ax];
        memory[es*16 + r16[bx] + 96] = 0x00;
        if (memory[ds*16 + 0x79b8] == 0x01) {
            pc = 0x8b63;
            break;
        }
        if (memory[ds*16 + 0x79b8] == 0x23) {
            pc = 0x8b63;
            break;
        }
        memory[ds*16 + 0xa0cf] -= 1;
        r8[al] = memory[ds*16 + 0xa0cf];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x8b50;
            break;
        }
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x8b2e;
            break;
        }
        r8[al] = 0x0b;
        pc = 0x8b30;
        break;
    case 0x8b2e:
        r8[al] = 0x2c;
    case 0x8b30:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x8572];
        memory[ds*16 + 0x856f] = r8[al];
        r8[al] = 0x59;
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
        memory[ds*16 + 0xa1b1] = 0x01;
        memory[ds*16 + 0x8550] = 0xf2;
        pc = 0x8b63;
        break;
    case 0x8b50:
        if (memory16get(ds, 0x689c) == 0x0004) {
            pc = 0x8b5b;
            break;
        }
        r8[al] = 0x0e;
        pc = 0x8b5d;
        break;
    case 0x8b5b:
        r8[al] = 0x21;
    case 0x8b5d:
        push(r16[ax]);
        yield* sub_8ce1();
        sp++;
        sp++;
    case 0x8b63:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8b65() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8b71;
            break;
        }
        yield* sub_ca53();
    case 0x8b71:
        memory[ds*16 + 0xa1a8] = 0x02;
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 628);
        r8[cl] = 0x04;
        r16[ax] = sar16(r16[ax], r8[cl]);
        memory16set(ds, 0x9b9a, r16[ax]);
        r8[al] = memory[ds*16 + 0x856e];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r16[ax] = memory16get(ds, r16[bx] + 630);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory16set(ds, 0x9ba2, r16[ax]);
        if (!(memory[ds*16 + 0x856e] & 0x01)) {
            pc = 0x8bb0;
            break;
        }
        r16[ax] = 0x0001;
        pc = 0x8bb3;
        break;
    case 0x8bb0:
        r16[ax] = 0x0002;
    case 0x8bb3:
        r16[bx] = memory16get(ds, 0x08e4);
        es = memory16get(ds, 0x08e4 + 2);
        memory16set(es, r16[bx] + 30, r16[ax]);
        flags.carry = (memory16get(ds, 0xa0d4) + 0x00fa) >= 0x10000;
        memory16set(ds, 0xa0d4, memory16get(ds, 0xa0d4) + 0x00fa);
        memory16set(ds, 0xa0d6, memory16get(ds, 0xa0d6) + flags.carry);
        if (memory[ds*16 + 0x79b8] != 0x23) {
            pc = 0x8bd3;
            break;
        }
        memory[ds*16 + 0x791a] += 1;
        pc = 0x8bf4;
        break;
    case 0x8bd3:
        if (memory[ds*16 + 0x79b8] != 0x2f) {
            pc = 0x8be2;
            break;
        }
        flags.carry = (memory16get(ds, 0xa0d4) + 0x2616) > 0x10000;
        memory16set(ds, 0xa0d4, memory16get(ds, 0xa0d4) + 0x2616);
        pc = 0x8bef;
        break;
    case 0x8be2:
        if (memory[ds*16 + 0x79b8] != 0x30) {
            pc = 0x8bf4;
            break;
        }
        flags.carry = (memory16get(ds, 0xa0d4) + 0xc256) > 0x10000;
        memory16set(ds, 0xa0d4, memory16get(ds, 0xa0d4) + 0xc256);
    case 0x8bef:
        memory16set(ds, 0xa0d6, memory16get(ds, 0xa0d6) + flags.carry);
    case 0x8bf4:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8bf6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8c04;
            break;
        }
        yield* sub_ca53();
    case 0x8c04:
        r8[al] = memory[ds*16 + 0x856e];
        push(r16[ax]);
        yield* sub_8a85();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0x7921];
        r8[ah] = 0x00;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 17302];
        memory[ss*16 + bp - 1] = r8[al];
        if (memory[ss*16 + bp - 1] == 0x00) {
            pc = 0x8c36;
            break;
        }
        r8[al] = memory[ds*16 + 0x7924];
        memory[ds*16 + 0x7922] = r8[al];
        r8[al] = memory[ss*16 + bp - 1];
        memory[ds*16 + 0x7923] = r8[al];
        r8[al] = memory[ss*16 + bp - 1];
        push(r16[ax]);
        yield* sub_8c64();
        sp++;
        sp++;
    case 0x8c36:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8c3a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8c46;
            break;
        }
        yield* sub_ca53();
    case 0x8c46:
        r8[al] = memory[ds*16 + 0x8242];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x8c62;
            break;
        }
        r8[al] = memory[ds*16 + 0x7924];
        r8[ah] = 0x00;
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        push(r16[ax]);
        yield* sub_8857();
        sp++;
        sp++;
    case 0x8c62:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8c64() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8c70;
            break;
        }
        yield* sub_ca53();
    case 0x8c70:
        r8[al] = memory[ds*16 + 0x856e];
        memory[ds*16 + 0x856f] = r8[al];
        r8[al] = memory[ss*16 + bp + 4];
        push(r16[ax]);
        yield* sub_887a();
        sp++;
        sp++;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8cb3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8cc0;
            break;
        }
        yield* sub_ca53();
    case 0x8cc0:
        if (memory16get(ds, 0x689c) == 0x8000) {
            pc = 0x8cde;
            break;
        }
        yield* sub_a7b5();
        si = r16[ax];
        r16[ax] = memory16get(ds, 0x689c);
        r16[ax] &= si;
        memory16set(ds, 0x689c, r16[ax]);
        push(memory16get(ds, 0x689c));
        yield* sub_a7ee();
        sp++;
        sp++;
    case 0x8cde:
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8ce1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8ced;
            break;
        }
        yield* sub_ca53();
    case 0x8ced:
        if (memory16get(ds, 0x689c) == 0x8000) {
            pc = 0x8cfe;
            break;
        }
        r8[al] = memory[ss*16 + bp + 4];
        push(r16[ax]);
        yield* sub_8d00();
        sp++;
        sp++;
    case 0x8cfe:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8d00() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8d0c;
            break;
        }
        yield* sub_ca53();
    case 0x8d0c:
        if (memory16get(ds, 0x689c) != 0x0004) {
            pc = 0x8d3c;
            break;
        }
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 10159];
        r8[ah] = 0x00;
        push(r16[ax]);
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[ax] <<= 1;
        r16[bx] = r16[ax];
        r8[al] = memory[ds*16 + r16[bx] + 10158];
        r8[ah] = 0x00;
        push(r16[ax]);
        yield* sub_a8d7();
        sp += 0x0004;
        pc = 0x8fb5;
        break;
    case 0x8d3c:
        r8[al] = memory[ss*16 + bp + 4];
        r8[ah] = 0x00;
        r16[ax]--;
        r16[bx] = r16[ax];
        if (r16[bx] <= 0x0014) {
            pc = 0x8d4c;
            break;
        }
        pc = 0x8fb5;
        break;
    case 0x8d4c:
        r16[bx] <<= 1;
        switch (r16[bx])
        {
        case 0: pc = 0x8d53; break;
        case 2: pc = 0x8d6a; break;
        case 4: pc = 0x8d85; break;
        case 6: pc = 0x8da3; break;
        case 8: pc = 0x8dc1; break;
        case 10: pc = 0x8ddf; break;
        case 12: pc = 0x8dfd; break;
        case 14: pc = 0x8e1b; break;
        case 16: pc = 0x8e39; break;
        case 18: pc = 0x8e50; break;
        case 20: pc = 0x8e6e; break;
        case 22: pc = 0x8e8f; break;
        case 24: pc = 0x8ea9; break;
        case 26: pc = 0x8ec7; break;
        case 28: pc = 0x8ee4; break;
        case 30: pc = 0x8f02; break;
        case 32: pc = 0x8f1c; break;
        case 34: pc = 0x8f3c; break;
        case 36: pc = 0x8f5c; break;
        case 38: pc = 0x8f76; break;
            default:
            assert(0);
        }
        break;
    case 0x8d53:
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(r16[ax]);
        r16[ax] = 0x01c2;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x03e8;
        pc = 0x8fa6;
        break;
    case 0x8d6a:
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(r16[ax]);
        r16[ax] = 0x01c2;
        push(r16[ax]);
        r16[ax] = 0xfff6;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0320;
        push(r16[ax]);
        r16[ax] = 0x0028;
        pc = 0x8faa;
        break;
    case 0x8d85:
        r16[ax] = 0xffff;
        push(r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x01f3;
        push(r16[ax]);
        r16[ax] = 0xffff;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x01b8;
        push(r16[ax]);
        r16[ax] = 0x0190;
        pc = 0x8faa;
        break;
    case 0x8da3:
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0064;
        push(r16[ax]);
        r16[ax] = 0xffff;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x00dc;
        push(r16[ax]);
        r16[ax] = 0x005a;
        pc = 0x8faa;
        break;
    case 0x8dc1:
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x01b8;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x03e8;
        push(r16[ax]);
        r16[ax] = 0x0019;
        pc = 0x8faa;
        break;
    case 0x8ddf:
        r16[ax] = 0x0005;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x01b8;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x044c;
        push(r16[ax]);
        r16[ax] = 0x0014;
        pc = 0x8faa;
        break;
    case 0x8dfd:
        r16[ax] = 0x0003;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x01b8;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x04b0;
        push(r16[ax]);
        r16[ax] = 0x000f;
        pc = 0x8faa;
        break;
    case 0x8e1b:
        r16[ax] = 0x0005;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0064;
        push(r16[ax]);
        r16[ax] = 0xfffb;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x00dc;
        push(r16[ax]);
        r16[ax] = 0x0028;
        pc = 0x8faa;
        break;
    case 0x8e39:
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(r16[ax]);
        r16[ax] = 0x01c2;
        push(r16[ax]);
        r16[ax] = 0x0014;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0032;
        pc = 0x8fa6;
        break;
    case 0x8e50:
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x015d;
        push(r16[ax]);
        r16[ax] = 0x0032;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x00c8;
        push(r16[ax]);
        r16[ax] = 0x000f;
        pc = 0x8faa;
        break;
    case 0x8e6e:
        r16[ax] = 0xfffc;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x01f3;
        push(r16[ax]);
        r16[ax] = 0x0014;
        push(r16[ax]);
        r16[ax] = 0x0028;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        yield* sub_b3d2();
        sp += 0x000c;
        pc = 0x8fb5;
        break;
    case 0x8e8f:
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x01a4;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x04b0;
        pc = 0x8fa6;
        break;
    case 0x8ea9:
        r16[ax] = 0x000f;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x015d;
        push(r16[ax]);
        r16[ax] = 0x0032;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x00c8;
        push(r16[ax]);
        r16[ax] = 0x0014;
        pc = 0x8faa;
        break;
    case 0x8ec7:
        r16[ax] = 0;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x00c8;
        push(r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x0032;
        pc = 0x8faa;
        break;
    case 0x8ee4:
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x0064;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x012c;
        push(r16[ax]);
        r16[ax] = 0x0190;
        pc = 0x8faa;
        break;
    case 0x8f02:
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x01a4;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x04b0;
        pc = 0x8fa6;
        break;
    case 0x8f1c:
        r16[ax] = 0xfffc;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x01f3;
        push(r16[ax]);
        r16[ax] = 0x0014;
        push(r16[ax]);
        r16[ax] = 0x0028;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        yield* sub_b3d2();
        sp += 0x000c;
        pc = 0x8fb5;
        break;
    case 0x8f3c:
        r16[ax] = 0xfffc;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x01f3;
        push(r16[ax]);
        r16[ax] = 0x001e;
        push(r16[ax]);
        r16[ax] = 0x0050;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        yield* sub_b3d2();
        sp += 0x000c;
        pc = 0x8fb5;
        break;
    case 0x8f5c:
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0x0064;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(r16[ax]);
        r16[ax] = 0x012c;
        push(r16[ax]);
        r16[ax] = 0x0320;
        pc = 0x8faa;
        break;
    case 0x8f76:
        r16[ax] = 0;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x00c8;
        push(r16[ax]);
        r16[ax] = 0x0004;
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0x000a;
        push(r16[ax]);
        r16[ax] = 0x0032;
        pc = 0x8faa;
        break;
    case 0x8fa6:
        push(r16[ax]);
        r16[ax] = 0x001e;
    case 0x8faa:
        push(r16[ax]);
        r16[ax] = 0x0002;
        push(r16[ax]);
        yield* sub_b358();
        sp += 0x0010;
    case 0x8fb5:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8fe1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x8fed;
            break;
        }
        yield* sub_ca53();
    case 0x8fed:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_8ff0() {
    push(0x7777);
    push(bp);
    bp = sp;
    r8[al] = memory[ss*16 + bp + 4];
    r8[ah] = 0x00;
    interrupt(0x10);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_9105() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x000a;
        push(si);
        push(di);
        memory[ss*16 + bp - 1] = 0x00;
        si = 0;
        memory16set(ss, bp - 6, 0x0000);
        memory16set(ss, bp - 4, 0x0000);
        pc = 0x919f;
        break;
    case 0x9120:
        if (memory16gets(ss, bp + 14) < signed16(0x0000)) {
            pc = 0x913d;
            break;
        }
        if (memory16gets(ss, bp + 14) > signed16(0x0000)) {
            pc = 0x912f;
            break;
        }
        if (memory16get(ss, bp + 12) <= 0xfa00) {
            pc = 0x913d;
            break;
        }
    case 0x912f:
        di = 0xfa00;
        flags.carry = memory16get(ss, bp + 12) < 0xfa00;
        memory16set(ss, bp + 12, memory16get(ss, bp + 12) - 0xfa00);
        memory16set(ss, bp + 14, memory16get(ss, bp + 14) - flags.carry);
        pc = 0x914a;
        break;
    case 0x913d:
        di = memory16get(ss, bp + 12);
        memory16set(ss, bp + 12, 0x0000);
        memory16set(ss, bp + 14, 0x0000);
    case 0x914a:
        push(di);
        push(memory16get(ss, bp + 10));
        push(memory16get(ss, bp + 8));
        push(memory16get(ss, bp + 6));
        yield* callIndirect(cs, memory16get(ss, bp + 4));
        sp += 0x0008;
        si = r16[ax];
        if (si == di) {
            pc = 0x9165;
            break;
        }
        r16[ax] = 0x0001;
        pc = 0x9167;
        break;
    case 0x9165:
        r16[ax] = 0;
    case 0x9167:
        memory[ss*16 + bp - 1] = r8[al];
        flags.carry = (memory16get(ss, bp - 6) + si) >= 0x10000;
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) + si);
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + flags.carry);
        r16[ax] = memory16get(ss, bp + 8);
        memory16set(ss, bp - 10, r16[ax]);
        memory16set(ss, bp - 8, 0x0000);
        flags.carry = (memory16get(ss, bp - 10) + si) >= 0x10000;
        memory16set(ss, bp - 10, memory16get(ss, bp - 10) + si);
        memory16set(ss, bp - 8, memory16get(ss, bp - 8) + flags.carry);
        r16[ax] = memory16get(ss, bp - 10);
        memory16set(ss, bp + 8, r16[ax]);
        memory16set(ss, bp - 10, 0x0000);
        r16[ax] = memory16get(ss, bp - 10);
        r16[ax] |= memory16get(ss, bp - 8);
        if (!r16[ax]) {
            pc = 0x919f;
            break;
        }
        flags.carry = (memory16get(ss, bp + 8) + 0x0000) >= 0x10000;
        memory16set(ss, bp + 8, memory16get(ss, bp + 8) + 0x0000);
        memory16set(ss, bp + 10, memory16get(ss, bp + 10) + (0x1000 + flags.carry));
    case 0x919f:
        r16[ax] = memory16get(ss, bp + 12);
        r16[ax] |= memory16get(ss, bp + 14);
        if (!r16[ax]) {
            pc = 0x91b3;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x91b3;
            break;
        }
        pc = 0x9120;
        break;
    case 0x91b3:
        r16[dx] = memory16get(ss, bp - 4);
        r16[ax] = memory16get(ss, bp - 6);
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_91bf() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 6);
    memory16set(ds, 0xa1b8, r16[ax]);
    push(memory16get(ss, bp + 4));
    yield* sub_bfb9();
    sp++;
    sp++;
    memory[ds*16 + 0x4ce6] = 0x01;
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_91d7() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 6);
    r16[dx] = memory16get(ss, bp + 4);
    memory16set(ds, 0xa1b4, r16[dx]);
    memory16set(ds, 0xa1b6, r16[ax]);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_91e9() {
    push(0x7777);
    push(bp);
    bp = sp;
    push(si);
    push(memory16get(ss, bp + 4));
    yield* sub_b75e();
    sp++;
    sp++;
    si = r16[ax];
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_923f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        push(si);
        push(di);
        di = memory16get(ss, bp + 4);
        memory[ss*16 + bp - 1] = 0x00;
        r8[al] = memory[ds*16 + 0x4ce6];
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x925c;
            break;
        }
        memory16set(ds, 0xa1b8, 0x74d4);
    case 0x925c:
        r16[ax] = di;
        r16[dx] = 0x000a;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0xa1b4);
        es = memory16get(ds, 0xa1b4 + 2);
        r16[bx] += r16[ax];
        if (memory[es*16 + r16[bx] + 4] == 0x7a) {
            pc = 0x92b9;
            break;
        }
    case 0x9270:
        push(memory16get(ss, bp + 6));
        r16[ax] = di;
        r16[dx] = 0x000a;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0xa1b4);
        es = memory16get(ds, 0xa1b4 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 4];
        push(r16[ax]);
        yield* sub_93a5();
        sp += 0x0004;
        si = r16[ax];
        if (!r16[ax]) {
            pc = 0x92ab;
            break;
        }
        r16[ax] = di;
        r16[dx] = 0x000a;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0xa1b4);
        es = memory16get(ds, 0xa1b4 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 4];
        r8[ah] = 0x00;
        push(r16[ax]);
        yield* callIndirect(cs, memory16get(ds, 0xa1b8));
        sp++;
        sp++;
    case 0x92ab:
        if (!si) {
            pc = 0x92b9;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        memory[ss*16 + bp - 1] += 1;
        if (r8[al] < 0x0a) {
            pc = 0x9270;
            break;
        }
    case 0x92b9:
        if (memory[ss*16 + bp - 1] > 0x0a) {
            pc = 0x9326;
            break;
        }
        r16[ax] = di;
        r16[dx] = 0x000a;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0xa1b4);
        es = memory16get(ds, 0xa1b4 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 4];
        memory[ds*16 + 0x4ce7] = r8[al];
    case 0x92d3:
        r16[ax] = 0x0180;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax] |= 0x8004;
        push(r16[ax]);
        r16[ax] = di;
        r16[dx] = 0x000a;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0xa1b4);
        es = memory16get(ds, 0xa1b4 + 2);
        r16[bx] += r16[ax];
        push(memory16get(es, r16[bx] + 2));
        push(memory16get(es, r16[bx]));
        yield* sub_c0ec();
        sp += 0x0008;
        si = r16[ax];
        if (r16s[ax] >= 0) {
            pc = 0x9318;
            break;
        }
        r16[ax] = di;
        r16[dx] = 0x000a;
        imul16(r16[dx]);
        r16[bx] = memory16get(ds, 0xa1b4);
        es = memory16get(ds, 0xa1b4 + 2);
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx] + 4];
        r8[ah] = 0x00;
        push(r16[ax]);
        yield* callIndirect(cs, memory16get(ds, 0xa1b8));
        sp++;
        sp++;
    case 0x9318:
        if (signed16(si) >= 0) {
            pc = 0x9326;
            break;
        }
        r8[al] = memory[ss*16 + bp - 1];
        memory[ss*16 + bp - 1] += 1;
        if (r8[al] < 0x0a) {
            pc = 0x92d3;
            break;
        }
    case 0x9326:
        r16[ax] = si;
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_932e() {
    push(0x7777);
    push(bp);
    bp = sp;
    sp -= 0x0004;
    push(memory16get(ss, bp + 12));
    push(memory16get(ss, bp + 10));
    push(memory16get(ss, bp + 8));
    push(memory16get(ss, bp + 6));
    push(memory16get(ss, bp + 4));
    r16[ax] = 0xa3ae;
    push(r16[ax]);
    yield* sub_9105();
    sp += 0x000c;
    memory16set(ss, bp - 4, r16[ax]);
    memory16set(ss, bp - 2, r16[dx]);
    r16[ax] = memory16get(ss, bp - 4);
    sp = bp;
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_93a5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        r16[ax] = 0x0180;
        push(r16[ax]);
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax] |= 0x8004;
        push(r16[ax]);
        push(ds);
        r16[ax] = 0x4ce8;
        push(r16[ax]);
        yield* sub_c0ec();
        sp += 0x0008;
        si = r16[ax];
        if (signed16(si) <= 0) {
            pc = 0x93fc;
            break;
        }
        r16[ax] = 0;
        push(r16[ax]);
        r16[dx] = 0x0004;
        push(r16[ax]);
        push(r16[dx]);
        push(ds);
        r16[ax] = 0xa1ba;
        push(r16[ax]);
        push(si);
        yield* sub_932e();
        sp += 0x000c;
        push(si);
        yield* sub_91e9();
        sp++;
        sp++;
        r8[al] = memory[ds*16 + 0xa1ba];
        r8[ah] = 0x00;
        r8[dl] = memory[ss*16 + bp + 4];
        r8[dh] = 0x00;
        r16[ax] -= r16[dx];
        si = r16[ax];
        if (memory[ds*16 + 0xa1ba] == 0x7a) {
            pc = 0x93fa;
            break;
        }
        if (memory[ss*16 + bp + 4] != 0x7a) {
            pc = 0x93fc;
            break;
        }
    case 0x93fa:
        si = 0;
    case 0x93fc:
        r16[ax] = si;
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_9402() {
    r16[tx] = flags.carry | (flags.zero << 1);
    push(r16[tx]);
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(si);
    push(di);
    push(ds);
    push(es);
    r16[ax] = 0x1228;
    ds = r16[ax];
    es = r16[ax];
    flags.direction = false;
    di = 0x4cf2;
    r16[cx] = 0x0020;
    r16[ax] = 0;
    rep_stosw_data_forward();
    r16[ax] = 0x0000;
    yield* sub_96a9();
    r16[ax] = 0x0001;
    yield* sub_96a9();
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
    r16[tx] = pop();
    flags.carry = r16[tx] & 1;
    flags.zero = (r16[tx] << 1) & 1;
}
function* sub_9433() {
    push(0x7777);
    push(bp);
    bp = sp;
    push(ds);
    push(es);
    push(si);
    push(di);
    r16[ax] = memory16get(ss, bp + 4);
    r8[ah] = 0;
    si = memory16get(ss, bp + 6);
    es = memory16get(ss, bp + 6 + 2);
    yield* sub_944b();
    di = pop();
    si = pop();
    es = pop();
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_944b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[dx] = 0x1228;
        ds = r16[dx];
        if (r8[al] < 0x10) {
            pc = 0x945b;
            break;
        }
        r16[dx] = 0x7676;
        pc = 0x94fa;
        break;
    case 0x945b:
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[bx] = 0x4cf2;
        r16[bx] += r16[ax];
        memory16set(ds, r16[bx], si);
        r16[ax] = es;
        memory16set(ds, r16[bx] + 2, r16[ax]);
        ds = pop();
        return;
    case 0x94fa:
        r16[ax] = cs;
        ds = r16[ax];
        r8[ah] = 0x09;
        interrupt(0x21);
    case 0x9502:
        pc = 0x9502;
        break;
        return;
    } while (1);
}
function* sub_9472() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ss, bp + 4);
        bp = pop();
        push(ds);
        push(es);
        push(si);
        push(di);
        r16[dx] = 0x1228;
        ds = r16[dx];
        r8[ah] = 0;
        if (r16[ax] < 0x0010) {
            pc = 0x948f;
            break;
        }
        r16[dx] = 0x76c8;
        pc = 0x94fa;
        break;
    case 0x948f:
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[bx] = 0x4cf2;
        r16[bx] += r16[ax];
        si = memory16get(ds, r16[bx]);
        es = memory16get(ds, r16[bx] + 2);
        r16[ax] = es;
        r16[ax] |= si;
        if (r16[ax]) {
            pc = 0x94a5;
            break;
        }
        r16[dx] = 0x7634;
        pc = 0x94fa;
        break;
    case 0x94a5:
        r16[dx] = 0x0000;
    case 0x94a8:
        r8[al] = memory[es*16 + si];
        si++;
        if (r8[al] >= 0xfd) {
            pc = 0x94bb;
            break;
        }
        push(r16[dx]);
        push(si);
        yield* sub_960c();
        si = pop();
        r16[dx] = pop();
        r8[dl] |= r8[ch];
        pc = 0x94a8;
        break;
    case 0x94bb:
        if (r8[al] == 0xff) {
            pc = 0x94f1;
            break;
        }
        push(ds);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[bx] = memory16get(ds, 0x4d42);
    case 0x94c9:
        r8[al] = memory[es*16 + si];
        si++;
        if (r8[al] >= 0xfd) {
            pc = 0x94e6;
            break;
        }
        r8[dh] = r8[al];
    case 0x94d3:
        r8[al] = memory[es*16 + si];
        si++;
        if (r8[al] >= 0xfd) {
            pc = 0x94e6;
            break;
        }
        r8[al] &= 0x7f;
        r8[al] = memory[ds*16 + r16[bx]+r8[al]];
        if (r8[al] == 0) {
            pc = 0x94d3;
            break;
        }
        r8[dl] |= r8[dh];
        pc = 0x94d3;
        break;
    case 0x94e6:
        if (r8[al] == 0xfe) {
            pc = 0x94f0;
            break;
        }
        if (r8[al] != 0xff) {
            pc = 0x94c9;
            break;
        }
        pc = 0x94f1;
        break;
    case 0x94f0:
        ds = pop();
    case 0x94f1:
        di = pop();
        si = pop();
        es = pop();
        ds = pop();
        r8[al] = r8[dl];
        r8[ah] = 0;
        assert(pop() == 0x7777);
        return;
    case 0x94fa:
        r16[ax] = cs;
        ds = r16[ax];
        r8[ah] = 0x09;
        interrupt(0x21);
    case 0x9502:
        pc = 0x9502;
        break;
        return;
    } while (1);
}
function* sub_960c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[bx] = 0x1228;
        ds = r16[bx];
        push(r16[ax]);
        yield* sub_9731();
        r16[bx] = pop();
        r8[ch] = 0;
        if (r16[ax] == 0xffff) {
            pc = 0x9665;
            break;
        }
        r16[bx] &= 0x0001;
        if (r16[bx] == 0) {
            pc = 0x9667;
            break;
        }
        if (r8[ah] >= memory[ds*16 + 0x4d3b]) {
            pc = 0x962e;
            break;
        }
        r8[ch] |= 0x04;
        pc = 0x9637;
        break;
    case 0x962e:
        if (r8[ah] < memory[ds*16 + 0x4d3d]) {
            pc = 0x9637;
            break;
        }
        r8[ch] |= 0x08;
    case 0x9637:
        if (r8[al] >= memory[ds*16 + 0x4d3a]) {
            pc = 0x9642;
            break;
        }
        r8[ch] |= 0x01;
        pc = 0x964b;
        break;
    case 0x9642:
        if (r8[al] < memory[ds*16 + 0x4d3c]) {
            pc = 0x964b;
            break;
        }
        r8[ch] |= 0x02;
    case 0x964b:
        r16[dx] = 0x0201;
        r8[al] = in8(r16[dx]);
        r8[al] = ~al;
        if (!(r8[al] & 0x40)) {
            pc = 0x9658;
            break;
        }
        r8[ch] |= 0x10;
    case 0x9658:
        if (!(r8[al] & 0x80)) {
            pc = 0x965f;
            break;
        }
        r8[ch] |= 0x20;
    case 0x965f:
        memory[ds*16 + 0x4d35] = r8[ch];
    case 0x9665:
        ds = pop();
        return;
    case 0x9667:
        if (r8[ah] >= memory[ds*16 + 0x4d37]) {
            pc = 0x9672;
            break;
        }
        r8[ch] |= 0x04;
        pc = 0x967b;
        break;
    case 0x9672:
        if (r8[ah] < memory[ds*16 + 0x4d39]) {
            pc = 0x967b;
            break;
        }
        r8[ch] |= 0x08;
    case 0x967b:
        if (r8[al] >= memory[ds*16 + 0x4d36]) {
            pc = 0x9686;
            break;
        }
        r8[ch] |= 0x01;
        pc = 0x968f;
        break;
    case 0x9686:
        if (r8[al] < memory[ds*16 + 0x4d38]) {
            pc = 0x968f;
            break;
        }
        r8[ch] |= 0x02;
    case 0x968f:
        r16[dx] = 0x0201;
        r8[al] = in8(r16[dx]);
        r8[al] = ~al;
        if (!(r8[al] & 0x10)) {
            pc = 0x969c;
            break;
        }
        r8[ch] |= 0x10;
    case 0x969c:
        if (!(r8[al] & 0x20)) {
            pc = 0x96a3;
            break;
        }
        r8[ch] |= 0x20;
    case 0x96a3:
        memory[ds*16 + 0x4d34] = r8[ch];
        pc = 0x9665;
        break;
        return;
    } while (1);
}
function* sub_96a9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[bx] = 0x4dca;
        if (r16[ax] == 0) {
            pc = 0x96b9;
            break;
        }
        r16[bx] = 0x4dcb;
    case 0x96b9:
        r8[cl] = 0x01;
        memory[ds*16 + r16[bx]] = r8[cl];
        r16[bx] = r16[ax];
        push(r16[ax]);
        push(r16[bx]);
        yield* sub_9731();
        r16[bx] = pop();
        r16[cx] = pop();
        if (r16[ax] == 0xffff) {
            pc = 0x971a;
            break;
        }
        if (r8[ah] < 0x02) {
            pc = 0x970e;
            break;
        }
        if (r8[al] < 0x02) {
            pc = 0x970e;
            break;
        }
        r16[cx] = r16[ax];
        r8[al] >>= 1;
        r8[ah] >>= 1;
        r16[dx] = r16[ax];
        r16[cx] += r16[cx];
        r16[cx] -= r16[dx];
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[bx] &= 0x0001;
        if (r16[bx] == 0) {
            pc = 0x96fc;
            break;
        }
        memory[ds*16 + 0x4d3a] = r8[dl];
        memory[ds*16 + 0x4d3b] = r8[dh];
        memory[ds*16 + 0x4d3c] = r8[cl];
        memory[ds*16 + 0x4d3d] = r8[ch];
        pc = 0x970c;
        break;
    case 0x96fc:
        memory[ds*16 + 0x4d36] = r8[dl];
        memory[ds*16 + 0x4d37] = r8[dh];
        memory[ds*16 + 0x4d38] = r8[cl];
        memory[ds*16 + 0x4d39] = r8[ch];
    case 0x970c:
        ds = pop();
        return;
    case 0x970e:
        push(r16[cx]);
        r16[cx] = 0x0000;
    case 0x9712:
        if (--r16[cx]) {
            pc = 0x9712;
            break;
        }
        r16[cx] = pop();
        r16[ax] = 0xffff;
        pc = 0x971c;
        break;
    case 0x971a:
        r8[al] = 0;
    case 0x971c:
        r16[bx] = 0x4dca;
        if (r16[cx] == 0) {
            pc = 0x9726;
            break;
        }
        r16[bx] = 0x4dcb;
    case 0x9726:
        memory[ds*16 + r16[bx]] = r8[al];
        pc = 0x970c;
        break;
        return;
    } while (1);
}
function* sub_9731() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[tx] = flags.carry | (flags.zero << 1);
        push(r16[tx]);
        flags.interrupts = false;
        push(ds);
        r16[bx] = 0x1228;
        ds = r16[bx];
        r8[al] &= 0x01;
        if (r8[al] == 0) {
            pc = 0x9751;
            break;
        }
        r16[bx] = 0x0408;
        r8[al] = memory[ds*16 + 0x4dcb];
        r8[al]--;
        if (r8[al] == 0) {
            pc = 0x9765;
            break;
        }
        r8[al]++;
        if (r8[al] == 0) {
            pc = 0x974e;
            break;
        }
        pc = 0x97fe;
        break;
    case 0x974e:
        pc = 0x9837;
        break;
    case 0x9751:
        r16[bx] = 0x0102;
        r8[al] = memory[ds*16 + 0x4dca];
        r8[al]--;
        if (r8[al] == 0) {
            pc = 0x9765;
            break;
        }
        r8[al]++;
        if (r8[al] == 0) {
            pc = 0x9762;
            break;
        }
        pc = 0x97fe;
        break;
    case 0x9762:
        pc = 0x9823;
        break;
    case 0x9765:
        r16[dx] = 0x0201;
        r16[cx] = 0;
    case 0x976a:
        r8[al] = in8(r16[dx]);
        if (--r16[cx] && r8[bl] & r8[al]) {
            pc = 0x976a;
            break;
        }
        if (r16[cx] == 0) {
            pc = 0x9775;
            break;
        }
        if (--r16[cx] && r8[bh] & r8[al]) {
            pc = 0x976a;
            break;
        }
    case 0x9775:
        if (r16[cx] == 0) {
            pc = 0x9779;
            break;
        }
        pc = 0x977c;
        break;
    case 0x9779:
        pc = 0x97fe;
        break;
    case 0x977c:
        r16[dx] = 0x0201;
        out8(r16[dx], r8[al]);
        r8[al] = in8(r16[dx]);
        if (r8[bh] & r8[al]) {
            pc = 0x97aa;
            break;
        }
        if (r8[bl] & r8[al]) {
            pc = 0x97aa;
            break;
        }
        r8[al] = 0x06;
        out8(0x43, r8[al]);
        push(r16[cx]);
        r16[cx] = 0x0064;
    case 0x9791:
        if (--r16[cx]) {
            pc = 0x9791;
            break;
        }
        r16[cx] = pop();
    case 0x9794:
        r8[al] = in8(0x40);
        r8[ah] = r8[al];
        r8[al] = in8(0x40);
        r8[ah] &= 0x10;
        if (r8[ah] == 0) {
            pc = 0x9794;
            break;
        }
    case 0x979f:
        r8[al] = in8(0x40);
        r8[ah] = r8[al];
        r8[al] = in8(0x40);
        r8[ah] &= 0x10;
        if (r8[ah] != 0) {
            pc = 0x979f;
            break;
        }
    case 0x97aa:
        r16[cx] = 0;
        memory16set(ds, 0x4d32, r16[cx]);
        r16[cx] = 0x03e8;
    case 0x97b3:
        r8[al] = in8(0x40);
        r8[ah] = r8[al];
        r8[al] = in8(0x40);
        r8[ah] &= 0x10;
        if (r8[ah] == 0) {
            pc = 0x97b3;
            break;
        }
        memory16set(ds, 0x4d32, memory16get(ds, 0x4d32) + 1);
        r8[al] = in8(r16[dx]);
        if (r8[bl] == 0) {
            pc = 0x97cf;
            break;
        }
        if (!(r8[bl] & r8[al])) {
            pc = 0x97f0;
            break;
        }
        if (r8[bh] == 0) {
            pc = 0x97d3;
            break;
        }
    case 0x97cf:
        if (!(r8[bh] & r8[al])) {
            pc = 0x97e2;
            break;
        }
    case 0x97d3:
        r8[al] = in8(0x40);
        r8[ah] = r8[al];
        r8[al] = in8(0x40);
        if (r8[ah] & 0x10) {
            pc = 0x97d3;
            break;
        }
        if (--r16[cx]) {
            pc = 0x97b3;
            break;
        }
        pc = 0x97fe;
        break;
    case 0x97e2:
        r16[ax] = memory16get(ds, 0x4d32);
        memory16set(ds, 0x4dc6, r16[ax]);
        r8[bh] = 0;
        if (r8[bl] == 0) {
            pc = 0x9803;
            break;
        }
        pc = 0x97d3;
        break;
    case 0x97f0:
        r16[ax] = memory16get(ds, 0x4d32);
        memory16set(ds, 0x4dc8, r16[ax]);
        r8[bl] = 0;
        if (r8[bh] == 0) {
            pc = 0x9803;
            break;
        }
        pc = 0x97d3;
        break;
    case 0x97fe:
        r16[ax] = 0xffff;
        pc = 0x9820;
        break;
    case 0x9803:
        r16[dx] = memory16get(ds, 0x4dc6);
        if (r16s[dx] >= 0) {
            pc = 0x980d;
            break;
        }
        r16[dx] = 0;
    case 0x980d:
        r8[cl] = 0x01;
        r16[dx] >>= r8[cl];
        r16[ax] = memory16get(ds, 0x4dc8);
        if (r16s[ax] >= 0) {
            pc = 0x981a;
            break;
        }
        r16[ax] = 0;
    case 0x981a:
        r8[cl] = 0x01;
        r16[ax] >>= r8[cl];
        r8[ah] = r8[dl];
    case 0x9820:
        ds = pop();
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        return;
    case 0x9823:
        r16[dx] = 0x0201;
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x03;
        if (r8[al] != 0) {
            pc = 0x97fe;
            break;
        }
        r8[al] = 0x01;
        memory[ds*16 + 0x4dca] = r8[al];
        r16[ax] = 0x0000;
        pc = 0x9847;
        break;
    case 0x9835:
        pc = 0x97fe;
        break;
    case 0x9837:
        r16[dx] = 0x0201;
        r8[al] = in8(r16[dx]);
        r8[al] &= 0x0c;
        if (r8[al] != 0) {
            pc = 0x9835;
            break;
        }
        r8[al] = 0x01;
        memory[ds*16 + 0x4dcb] = r8[al];
        r16[ax] = 0x0001;
    case 0x9847:
        push(r16[bx]);
        push(r16[ax]);
        r16[ax] = 0xffff;
        r16[ax] = pop();
        r16[bx] = pop();
        if (r16[ax] == 0xffff) {
            pc = 0x9835;
            break;
        }
        push(r16[bx]);
        yield* sub_9731();
        r16[bx] = pop();
        pc = 0x9820;
        break;
        return;
    } while (1);
}
function* sub_985a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(di);
        push(ds);
        push(es);
        r16[ax] = 0x1228;
        ds = r16[ax];
        es = r16[ax];
        flags.direction = false;
        di = memory16get(ds, 0x4d42);
        r16[cx] = 0x0040;
        r16[ax] = 0x0000;
        rep_stosw_data_forward();
        es = pop();
        yield* sub_99d1();
        r16[ax] = memory16get(ds, 0x4dc4);
        if (r16[ax] != 0) {
            pc = 0x98b2;
            break;
        }
        r16[ax]++;
        memory16set(ds, 0x4dc4, r16[ax]);
        push(ds);
        push(es);
        r8[al] = 0x09;
        r8[ah] = 0x35;
        interrupt(0x21);
        r16[dx] = es;
        r16[ax] = 0x01ed;
        es = r16[ax];
        memory16set(ds, 0x4d3e, r16[bx]);
        memory16set(es, 0x7a6d, r16[bx]);
        memory16set(ds, 0x4d40, r16[dx]);
        memory16set(es, 0x7a6f, r16[dx]);
        r16[dx] = 0x79e6;
        r16[bx] = 0x01ed;
        ds = r16[bx];
        r8[al] = 0x09;
        r8[ah] = 0x25;
        interrupt(0x21);
        es = pop();
        ds = pop();
    case 0x98b2:
        ds = pop();
        di = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_9947() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(di);
        push(ds);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x4dc4);
        if (r16[ax] == 0) {
            pc = 0x9980;
            break;
        }
        r16[ax] = 0;
        memory16set(ds, 0x4dc4, r16[ax]);
        push(ds);
        push(es);
        r16[dx] = memory16get(ds, 0x4d3e);
        r16[bx] = memory16get(ds, 0x4d40);
        ds = r16[bx];
        r8[al] = 0x09;
        r8[ah] = 0x25;
        interrupt(0x21);
        es = pop();
        ds = pop();
        yield* sub_99d1();
    case 0x9972:
        r8[ah] = 0x0b;
        interrupt(0x21);
        if (r8[al] == 0) {
            pc = 0x9980;
            break;
        }
        r8[ah] = 0x07;
        interrupt(0x21);
        pc = 0x9972;
        break;
    case 0x9980:
        ds = pop();
        di = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_9984() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(ds);
    push(r16[bx]);
    push(di);
    r16[bx] = 0x1228;
    ds = r16[bx];
    di = memory16get(ds, 0x4d42);
    r8[ah] = 0;
    r8[al] &= 0x7f;
    di += r16[ax];
    r8[al] = memory[ds*16 + di];
    di = pop();
    r16[bx] = pop();
    ds = pop();
    assert(pop() == 0x7777);
}
function* sub_998b() {
    push(ds);
    push(r16[bx]);
    push(di);
    r16[bx] = 0x1228;
    ds = r16[bx];
    di = memory16get(ds, 0x4d42);
    r8[ah] = 0;
    r8[al] &= 0x7f;
    di += r16[ax];
    r8[al] = memory[ds*16 + di];
    di = pop();
    r16[bx] = pop();
    ds = pop();
    flags.zero = r16[ax] == 0;
}
function* sub_99d1() {
    push(ds);
    push(r16[ax]);
    push(r16[bx]);
    r16[ax] = 0x0040;
    ds = r16[ax];
    r16[bx] = 0x0080;
    r16[ax] = memoryBiosGet16(ds, r16[bx]);
    r16[bx] = 0x001a;
    memoryBiosSet16(ds, r16[bx], r16[ax]);
    memoryBiosSet16(ds, r16[bx]+2, r16[ax]);
    r16[bx] = pop();
    r16[ax] = pop();
    ds = pop();
    flags.zero = r16[ax] == 0;
}
function* sub_9a1a() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_cbd9();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9a2a() {
    push(0x7777);
    push(bp);
    bp = sp;
    di = memory16get(ss, bp + 6);
    si = memory16get(ss, bp + 4);
    r16[bx] = memory16get(ss, bp + 10);
    r16[ax] = memory16get(ss, bp + 8);
    r16[dx] = memory16get(ss, bp + 14);
    r16[cx] = memory16get(ss, bp + 12);
    bp = pop();
    push(cs);
    cs = 0x0e15;
    yield* sub_e150();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9a63() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    r16[bx] = memory16get(ss, bp + 8);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_cc41();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9a77() {
    push(cs);
    cs = 0x0ca6;
    yield* sub_cc5f();
    assert(cs == 0x01ed);
}
function* sub_9a7d() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_cc7b();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9a8d() {
    push(0x7777);
    push(bp);
    bp = sp;
    r8[cl] = memory[ss*16 + bp + 4];
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_cc92();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9a9a() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[bx] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_cd11();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9aa7() {
    push(cs);
    cs = 0x0ca6;
    yield* sub_cd2e();
    assert(cs == 0x01ed);
}
function* sub_9aad() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[bx] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_cdb1();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9aca() {
    yield* sub_998b();
    cs = pop();
}
function* sub_9bae() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[al] = memory[ds*16 + 0x54d4];
        r8[ah] = 0;
        if (r8[al] == 0) {
            pc = 0x9bba;
            break;
        }
        return;
    case 0x9bba:
        yield* sub_9e80();
        memory16set(ds, 0x54d6, r16[ax]);
        r16[cx] = 0x0006;
    case 0x9bc3:
        push(r16[cx]);
        r16[ax] = 0x0000;
        r16[bx] = r16[cx];
        r16[bx]--;
        yield* sub_9d32();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x9bc3;
            break;
        }
        r16[bx] = 0x54f6;
        r16[cx] = 0x0010;
        r16[ax] = 0;
    case 0x9bd8:
        memory16set(ds, r16[bx], r16[ax]);
        r16[bx] += 0x0002;
        if (--r16[cx]) {
            pc = 0x9bd8;
            break;
        }
        r16[bx] = 0x5516;
        r16[cx] = 0x0010;
        r16[ax] = 0xffff;
    case 0x9be8:
        memory16set(ds, r16[bx], r16[ax]);
        r16[bx] += 0x0002;
        if (--r16[cx]) {
            pc = 0x9be8;
            break;
        }
        r16[cx] = 0x0012;
        r16[ax] = memory16get(ds, 0x54d6);
        if (r16[ax] == 0) {
            pc = 0x9c22;
            break;
        }
        if (r16[ax] >= 0xf800) {
            pc = 0x9c22;
            break;
        }
        if (r16[ax] < 0x0951) {
            pc = 0x9c22;
            break;
        }
        r16[cx] = r16[ax];
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[ax] = 0xffff;
        r16[dx] = 0;
        div16(r16[cx]);
        r16[ax] += r16[ax];
        r16[cx] = r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[cx];
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[cx] = r16[ax];
    case 0x9c22:
        r16[ax] = r16[cx];
        r16[bx] = 0x0000;
        r16[dx] = 0x01ed;
        r16[cx] = 0x7e7a;
        yield* sub_9d32();
        r16[ax] = 0x0032;
        r16[bx] = 0x0001;
        r16[dx] = 0x01ed;
        r16[cx] = 0x7e80;
        yield* sub_9d32();
        push(es);
        r8[ah] = 0x35;
        r8[al] = 0x08;
        interrupt(0x21);
        memory16set(ds, 0x54d0, r16[bx]);
        r16[bx] = es;
        memory16set(ds, 0x54d2, r16[bx]);
        es = pop();
        r16[ax] = 0x0001;
        memory[ds*16 + 0x54d4] = r8[al];
        r16[tx] = flags.carry | (flags.zero << 1);
        push(r16[tx]);
        flags.interrupts = false;
        push(ds);
        r16[ax] = 0x01ed;
        ds = r16[ax];
        r16[dx] = 0x7c02;
        r8[ah] = 0x25;
        r8[al] = 0x08;
        interrupt(0x21);
        ds = pop();
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        yield* sub_9c82();
        push(es);
        r16[ax] = 0x350f;
        interrupt(0x21);
        memory16set(ds, 0x54d8, r16[bx]);
        r16[bx] = es;
        memory16set(ds, 0x54da, r16[bx]);
        es = pop();
        r16[ax] = 0x0001;
        return;
    } while (1);
}
function* sub_9c82() {
    r16[ax] = 0x0951;
    yield* sub_9e6a();
}
function* sub_9c89() {
    r8[al] = memory[ds*16 + 0x54d4];
    r8[ah] = 0;
    if (r8[al] == 0)
        return;
    push(ds);
    r16[dx] = memory16get(ds, 0x54d8);
    ds = memory16get(ds, 0x54d8 + 2);
    r8[ah] = 0x25;
    r8[al] = 0x0f;
    ds = pop();
    r16[ax] = memory16get(ds, 0x54d6);
    yield* sub_9e6a();
    push(ds);
    r16[dx] = memory16get(ds, 0x54d0);
    ds = memory16get(ds, 0x54d0 + 2);
    r8[ah] = 0x25;
    r8[al] = 0x08;
    interrupt(0x21);
    ds = pop();
    r16[ax] = 0x0000;
    memory[ds*16 + 0x54d4] = r8[al];
    r16[ax] = 0x0001;
}
function* sub_9cc9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16s[bx] < 0) {
            pc = 0x9ce5;
            break;
        }
        if (r16s[bx] >= signed16(0x0004)) {
            pc = 0x9ce5;
            break;
        }
        r16[bx] += 0x0002;
        if (r16s[ax] < 0) {
            pc = 0x9ce5;
            break;
        }
        if (r16s[ax] >= signed16(0x01f4)) {
            pc = 0x9ce5;
            break;
        }
        yield* sub_9d32();
        r16[ax] = 0x0001;
        return;
    case 0x9ce5:
        r16[ax] = 0;
        return;
    } while (1);
}
function* sub_9ce8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ss, bp + 4);
        bp = pop();
        r16[bx] = r16[ax];
        if (r16s[bx] < 0) {
            pc = 0x9d0a;
            break;
        }
        if (r16s[bx] >= signed16(0x0004)) {
            pc = 0x9d0a;
            break;
        }
        r16[bx] += 0x0002;
        r16[ax] = 0;
        r16[cx] = r16[ax];
        r16[dx] = r16[ax];
        yield* sub_9d32();
        r16[ax] = 0x0001;
        assert(pop() == 0x7777);
        return;
    case 0x9d0a:
        r16[ax] = 0;
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_9cef() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = r16[ax];
        if (r16s[bx] < 0) {
            pc = 0x9d0a;
            break;
        }
        if (r16s[bx] >= signed16(0x0004)) {
            pc = 0x9d0a;
            break;
        }
        r16[bx] += 0x0002;
        r16[ax] = 0;
        r16[cx] = r16[ax];
        r16[dx] = r16[ax];
        yield* sub_9d32();
        r16[ax] = 0x0001;
        return;
    case 0x9d0a:
        r16[ax] = 0;
        return;
    } while (1);
}
function* sub_9d32() {
    r16[bx] += r16[bx];
    r16[bx] += r16[bx];
    r16[bx] += r16[bx];
    r16[bx] += 0x549c;
    memory16set(ds, r16[bx], r16[ax]);
    r16[ax] = 0;
    memory16set(ds, r16[bx] + 2, r16[ax]);
    memory16set(ds, r16[bx] + 6, r16[cx]);
    memory16set(ds, r16[bx] + 4, r16[dx]);
}
function* sub_9e60() {
    yield* sub_9e63();
    yield* sub_9e66();
    yield* sub_9e69();
}
function* sub_9e63() {
    yield* sub_9e66();
    yield* sub_9e69();
}
function* sub_9e66() {
    yield* sub_9e69();
}
function* sub_9e69() {
}
function* sub_9e6a() {
    push(r16[ax]);
    r8[al] = 0x36;
    out8(0x43, r8[al]);
    yield* sub_9e60();
    r16[ax] = pop();
    out8(0x40, r8[al]);
    yield* sub_9e60();
    r8[al] = r8[ah];
    out8(0x40, r8[al]);
    yield* sub_9e60();
}
function* sub_9e80() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        r16[cx] = 0x0019;
        r16[bx] = 0;
        r8[al] = 0x06;
        out8(0x43, r8[al]);
        yield* sub_9e60();
    case 0x9e8e:
        flags.interrupts = false;
        r8[al] = in8(0x40);
        r8[ah] = r8[al];
        yield* sub_9e60();
        r8[al] = in8(0x40);
        flags.interrupts = true;
        if (r8[al] < r8[bh]) {
            pc = 0x9e8e;
            break;
        }
        if (r8[al] != r8[bh]) {
            pc = 0x9ea3;
            break;
        }
        if (r8[bl] >= r8[ah]) {
            pc = 0x9ea5;
            break;
        }
    case 0x9ea3:
        r8[bl] = r8[ah];
    case 0x9ea5:
        r8[bh] = r8[al];
        if (--r16[cx]) {
            pc = 0x9e8e;
            break;
        }
        r16[ax] = r16[bx];
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_9f5e() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ec2;
    yield* sub_ec20();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9f6e() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 6);
    bp = pop();
    push(cs);
    cs = 0x0ec2;
    yield* sub_ec52();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9f7c() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_d4d3();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_9f8c() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_d7d7();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_a485() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        r16[bx] = memory16get(cs, 0x85b3);
        if (r16[bx] != 0x0000) {
            pc = 0xa495;
            break;
        }
        yield* sub_afe5();
        pc = 0xa4a9;
        break;
    case 0xa495:
        if (r16[bx] != 0x0004) {
            pc = 0xa49f;
            break;
        }
        yield* sub_a9a0();
        pc = 0xa4a9;
        break;
    case 0xa49f:
        if (r16[bx] != 0x0001) {
            pc = 0xa4a9;
            break;
        }
        yield* sub_acff();
    case 0xa4a9:
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_a4ab() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[ax] = memory16get(cs, 0x85b3);
        if (r16[ax] != 0x0000) {
            pc = 0xa4ba;
            break;
        }
        yield* sub_b09f();
        pc = 0xa4ce;
        break;
    case 0xa4ba:
        if (r16[ax] != 0x0004) {
            pc = 0xa4c4;
            break;
        }
        yield* sub_a9c6();
        pc = 0xa4ce;
        break;
    case 0xa4c4:
        if (r16[ax] != 0x0001) {
            pc = 0xa4ce;
            break;
        }
        yield* sub_ad18();
    case 0xa4ce:
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_a4d0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r16[cx] = memory16get(cs, 0x85b3);
        if (r16[cx] != 0x0000) {
            pc = 0xa4e0;
            break;
        }
        yield* sub_b0a7();
        pc = 0xa4f4;
        break;
    case 0xa4e0:
        if (r16[cx] != 0x0004) {
            pc = 0xa4ea;
            break;
        }
        yield* sub_a9d4();
        pc = 0xa4f4;
        break;
    case 0xa4ea:
        if (r16[cx] != 0x0001) {
            pc = 0xa4f4;
            break;
        }
        yield* sub_ad20();
    case 0xa4f4:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_a4f6() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r16[cx] = memory16get(cs, 0x85b3);
        if (r16[cx] != 0x0000) {
            pc = 0xa506;
            break;
        }
        yield* sub_b0af();
        pc = 0xa51a;
        break;
    case 0xa506:
        if (r16[cx] != 0x0004) {
            pc = 0xa510;
            break;
        }
        yield* sub_a9dd();
        pc = 0xa51a;
        break;
    case 0xa510:
        if (r16[cx] != 0x0001) {
            pc = 0xa51a;
            break;
        }
        yield* sub_ad28();
    case 0xa51a:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_a5b9() {
    push(r16[ax]);
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    r16[ax] = memory16get(cs, 0x85a3);
    r16[cx] = 0x0f42;
    mul16(r16[cx]);
    r16[cx] = memory16get(cs, 0x85a5);
    r16[bx] = memory16get(cs, 0x85a7);
    r8[cl] = r8[ch];
    r8[ch] = r8[bl];
    div16(r16[cx]);
    r16[cx] = r16[ax];
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[ax] = r16[cx];
    r16[dx] = 0x01ed;
    r16[cx] = 0x864c;
    r16[bx] = 0x0000;
    yield* sub_9cc9();
    ds = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_a5f2() {
    push(r16[bx]);
    push(r16[dx]);
    push(ds);
    push(es);
    yield* sub_a5b9();
    es = pop();
    ds = pop();
    r16[dx] = pop();
    r16[bx] = pop();
}
function* sub_a5fe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r8[ah] = r8[al];
        yield* sub_a8b2();
    case 0xa603:
        lodsb_data_forward();
        r8[ah] = r8[al];
        yield* sub_a8b2();
        if (--r16[cx]) {
            pc = 0xa603;
            break;
        }
        return;
    } while (1);
}
function* sub_a60c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
    case 0xa60d:
        lodsb_data_forward();
        if (r8[al] & 0x80) {
            pc = 0xa615;
            break;
        }
        lodsb_data_forward();
        pc = 0xa666;
        break;
    case 0xa615:
        r8[ch] = 0;
        if (r8s[al] < signed8(0xf0)) {
            pc = 0xa62b;
            break;
        }
        if (r8[al] == 0xf0) {
            pc = 0xa626;
            break;
        }
        if (r8[al] != 0xf7) {
            pc = 0xa630;
            break;
        }
        yield* sub_a4ab();
        pc = 0xa666;
        break;
    case 0xa626:
        yield* sub_a4d0();
        pc = 0xa666;
        break;
    case 0xa62b:
        yield* sub_a4f6();
        pc = 0xa666;
        break;
    case 0xa630:
        lodsw_data_forward();
        if (r8[al] != 0x51) {
            pc = 0xa643;
            break;
        }
        lodsb_data_forward();
        memory[cs*16 + 0x85a7] = r8[al];
        lodsw_data_forward();
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        memory16set(cs, 0x85a5, r16[ax]);
        pc = 0xa666;
        break;
    case 0xa643:
        if (r8[al] != 0x2f) {
            pc = 0xa654;
            break;
        }
        lodsw_data_forward();
        r16[ax] = 0xffff;
        r16[dx] = r16[ax];
        memory16set(cs, 0x85a1, memory16get(cs, 0x85a1) - 1);
        pc = 0xa670;
        break;
    case 0xa654:
        if (r8[al] != 0x20) {
            pc = 0xa660;
            break;
        }
        lodsb_data_forward();
        memory[cs*16 + r16[bx] + 128] = r8[al];
        pc = 0xa666;
        break;
    case 0xa660:
        r8[cl] = r8[ah];
        si += r16[cx];
    case 0xa666:
        yield* sub_a761();
        if (!flags.zero) {
            pc = 0xa66d;
            break;
        }
        pc = 0xa60d;
        break;
    case 0xa66d:
        yield* sub_a8f3();
    case 0xa670:
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_a672() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = memory16get(cs, 0x85a1);
        r16[bx] = 0x81cc;
    case 0xa67a:
        si = memory16get(cs, r16[bx]);
        ds = memory16get(cs, r16[bx] + 2);
        yield* sub_a761();
        if (!flags.zero) {
            pc = 0xa685;
            break;
        }
        yield* sub_a60c();
    case 0xa685:
        memory16set(cs, r16[bx] + 64, r16[ax]);
        memory16set(cs, r16[bx] + 66, r16[dx]);
        memory16set(cs, r16[bx], si);
        r16[ax] = ds;
        memory16set(cs, r16[bx] + 2, r16[ax]);
        r16[bx]++;
        r16[bx]++;
        r16[bx]++;
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0xa67a;
            break;
        }
        return;
    } while (1);
}
function* sub_a6d9() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, si) != 0x544d) {
            pc = 0xa75e;
            break;
        }
        si++;
        si++;
        if (memory16get(ds, si) != 0x6468) {
            pc = 0xa75e;
            break;
        }
        si++;
        si++;
        if (memory16get(ds, si) != 0x0000) {
            pc = 0xa75e;
            break;
        }
        si++;
        si++;
        if (memory16get(ds, si) != 0x0600) {
            pc = 0xa75e;
            break;
        }
        si++;
        si++;
        if (memory16get(ds, si) == 0x0200) {
            pc = 0xa75e;
            break;
        }
        si++;
        si++;
        lodsw_data_forward();
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        if (r16[ax] == 0x0000) {
            pc = 0xa75e;
            break;
        }
        if (r16s[ax] > signed16(0x0010)) {
            pc = 0xa75e;
            break;
        }
        memory16set(cs, 0x85a1, r16[ax]);
        lodsw_data_forward();
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        if (r8[ah] & 0x80) {
            pc = 0xa75e;
            break;
        }
        memory16set(cs, 0x85a3, r16[ax]);
        r16[cx] = memory16get(cs, 0x85a1);
        r16[bx] = 0x81cc;
    case 0xa72e:
        yield* sub_a8f3();
        lodsw_data_forward();
        if (r16[ax] != 0x544d) {
            pc = 0xa75e;
            break;
        }
        lodsw_data_forward();
        if (r16[ax] != 0x6b72) {
            pc = 0xa75e;
            break;
        }
        lodsw_data_forward();
        if (r16[ax] != 0x0000) {
            pc = 0xa75e;
            break;
        }
        lodsw_data_forward();
        memory16set(cs, r16[bx], si);
        r16[bx]++;
        r16[bx]++;
        memory16set(cs, r16[bx], ds);
        r16[bx]++;
        r16[bx]++;
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        flags.carry = (si + r16[ax]) >= 0x10000;
        si += r16[ax];
        if (flags.carry) {
            pc = 0xa75e;
            break;
        }
        if (--r16[cx]) {
            pc = 0xa72e;
            break;
        }
        yield* sub_a672();
        r16[ax] = 0xffff;
        return;
    case 0xa75e:
        r16[ax] = 0;
        return;
    } while (1);
}
function* sub_a761() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0;
        r16[dx] = r16[ax];
        lodsb_data_forward();
        if (!(r8[al] & 0x80)) {
            pc = 0xa7ae;
            break;
        }
        r8[ah] = r8[al];
        lodsb_data_forward();
        if (r8[al] & 0x80) {
            pc = 0xa77a;
            break;
        }
        r16[ax] &= 0x7f7f;
        r8[al] <<= 1;
        r16[ax] >>= 1;
        pc = 0xa7ae;
        break;
    case 0xa77a:
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
        lodsb_data_forward();
        if (r8[al] & 0x80) {
            pc = 0xa796;
            break;
        }
        r8[tl] = r8[ah];
        r8[ah] = r8[dl];
        r8[dl] = r8[tl];
        r8[tl] = r8[dl];
        r8[dl] = r8[dh];
        r8[dh] = r8[tl];
        r16[dx] &= 0x7f7f;
        r16[ax] <<= 1;
        r8[al] <<= 1;
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        pc = 0xa7ae;
        break;
    case 0xa796:
        r8[ah] = r8[al];
        lodsb_data_forward();
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
        r16[dx] &= 0x7f7f;
        r8[dl] <<= 1;
        r16[dx] >>= 1;
        r16[ax] <<= 1;
        r8[al] <<= 1;
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
    case 0xa7ae:
        push(r16[bx]);
        r16[bx] = r16[ax];
        r16[bx] |= r16[dx];
        flags.zero = r16[bx] == 0;
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_a7b5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[cx] = 0xffff;
        r16[ax] = memory16get(ds, 0x557a);
        if (r16[ax] != 0) {
            pc = 0xa7e9;
            break;
        }
        r16[ax] = 0x0001;
        memory16set(ds, 0x557a, r16[ax]);
        r16[cx] = 0;
        memory16set(ds, 0x5584, r16[ax]);
        push(r16[cx]);
        yield* sub_a945();
        r16[cx] = pop();
        r16[ax] = 0x0004;
        if (flags.zero) {
            pc = 0xa7d6;
            break;
        }
        r16[cx] |= r16[ax];
    case 0xa7d6:
        push(r16[cx]);
        yield* sub_a9fa();
        r16[cx] = pop();
        r16[ax] = 0x0001;
        if (flags.zero) {
            pc = 0xa7e2;
            break;
        }
        r16[cx] |= r16[ax];
    case 0xa7e2:
        memory16set(cs, 0x85b3, r16[ax]);
        memory16set(ds, 0x5586, r16[ax]);
    case 0xa7e9:
        r16[ax] = r16[cx];
        return;
    } while (1);
}
function* sub_a7ee() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[cx] = 0xffff;
        r16[ax] = memory16get(ds, 0x557a);
        if (r16[ax] != 0x0001) {
            pc = 0xa827;
            break;
        }
        r16[ax] = 0x0002;
        memory16set(ds, 0x557a, r16[ax]);
        push(bp);
        bp = sp;
        r16[ax] = memory16get(ss, bp + 4);
        bp = pop();
        r16[cx] = 0x0000;
    case 0xa809:
        flags.carry = r16[ax] & 1;
        r16[ax] >>= 1;
        if (flags.carry) {
            pc = 0xa817;
            break;
        }
        r16[cx]++;
        if (r16[cx] != 0x0010) {
            pc = 0xa809;
            break;
        }
        r16[ax] = 0;
        pc = 0xa82c;
        break;
    case 0xa817:
        r16[ax] = 0x0000;
        stop(/*carry2*/);
        r16[ax] = rcl16(r16[ax], 0x0001);
        r16[ax] <<= r8[cl];
    case 0xa81e:
        memory16set(cs, 0x85b3, r16[ax]);
        memory16set(ds, 0x5586, r16[ax]);
        r16[cx] = r16[ax];
    case 0xa827:
        r16[ax] = r16[cx];
        assert(pop() == 0x7777);
        return;
    case 0xa82c:
        r16[bx] = 0x0001;
        r16[ax] = 0x0064;
        r16[dx] = 0x01ed;
        r16[cx] = 0x9136;
        yield* sub_9cc9();
        r16[ax] = 0;
        memory[cs*16 + 0x83ee] = r8[al];
        memory16set(cs, 0x83ef, r16[ax]);
        pc = 0xa81e;
        break;
        return;
    } while (1);
}
function* sub_a847() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        pc = 0xa847;
        break;
    case 0xa69d:
        push(bp);
        bp = sp;
        push(es);
        push(ds);
        push(si);
        push(di);
        r16[ax] = memory16get(ss, bp + 12);
        memory16set(cs, 0x8483, r16[ax]);
        si = memory16get(ss, bp + 8);
        es = memory16get(ss, bp + 8 + 2);
        memory16set(ds, 0x5580, si);
        si = es;
        memory16set(ds, 0x5582, si);
        si = memory16get(ss, bp + 4);
        ds = memory16get(ss, bp + 4 + 2);
        memory16set(cs, 0x8485, si);
        r16[ax] = ds;
        memory16set(cs, 0x8487, r16[ax]);
        yield* sub_a6d9();
        if (r16[ax] == 0) {
            pc = 0xa6d3;
            break;
        }
        yield* sub_a5f2();
        r16[ax] = 0x0001;
    case 0xa6d3:
        di = pop();
        si = pop();
        ds = pop();
        es = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    case 0xa847:
        push(ds);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x5586);
        r16[tx] = r16[ax];
        r16[ax] = 0x0000;
        if (stop("check inject: cmp r16[ax], 0x8000") && r16[tx] == 0x8000) {
            pc = 0xa865;
            break;
        }
        r16[ax] = 0x0000;
        yield* sub_9cef();
        ds = pop();
        yield* sub_a485();
        pc = 0xa69d;
        break;
    case 0xa865:
        ds = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_a869() {
    r16[ax] = memory16get(cs, 0x85a1);
    if (r16[ax] != 0)
        return;
    r16[ax] = memory16get(cs, 0x8483);
}
function* sub_a878() {
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[ax] = 0x0000;
    yield* sub_9cef();
    ds = pop();
    yield* sub_a485();
}
function* sub_a8b2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        r16[cx] = 0;
        r16[dx] = 0x0331;
    case 0xa8b8:
        r8[al] = in8(r16[dx]);
        if (--r16[cx] && r8[al] & 0x40) {
            pc = 0xa8b8;
            break;
        }
        if (r8[al] & 0x40) {
            pc = 0xa8c5;
            break;
        }
        r16[dx]--;
        r8[al] = r8[ah];
        out8(r16[dx], r8[al]);
    case 0xa8c3:
        r16[cx] = pop();
        return;
    case 0xa8c5:
        push(ds);
        r16[ax] = 0x1228;
        ds = r16[ax];
        memory16set(ds, 0x557c, r16[cx]);
        ds = pop();
        memory16set(cs, 0x85a1, r16[cx]);
        pc = 0xa8c3;
        break;
        return;
    } while (1);
}
function* sub_a8d7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r8[ah] = 0x99;
        pc = 0xa8dd;
        break;
    case 0xa8dd:
        push(bp);
        bp = sp;
        push(r16[dx]);
        yield* sub_a8b2();
        r8[ah] = memory[ss*16 + bp + 4];
        yield* sub_a8b2();
        r8[ah] = memory[ss*16 + bp + 6];
        yield* sub_a8b2();
        r16[dx] = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_a8f3() {
    push(r16[ax]);
    push(r16[bx]);
    r16[ax] = si;
    si &= 0x000f;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[bx] = ds;
    r16[ax] += r16[bx];
    ds = r16[ax];
    r16[bx] = pop();
    r16[ax] = pop();
}
function* sub_a945() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        if (memory16get(ds, 0x557c) == 0x0000) {
            pc = 0xa996;
            break;
        }
        r16[cx] = 0x1388;
        r16[dx] = 0x0331;
    case 0xa956:
        r8[al] = in8(r16[dx]);
        if (--r16[cx] && r8[al] & 0x40) {
            pc = 0xa956;
            break;
        }
        if (r8[al] & 0x40) {
            pc = 0xa990;
            break;
        }
        r8[al] = 0xff;
        out8(r16[dx], r8[al]);
        r16[bx] = 0x0003;
    case 0xa963:
        r16[cx] = 0x1388;
        r16[dx] = 0x0331;
    case 0xa969:
        r8[al] = in8(r16[dx]);
        if (--r16[cx] && r8[al] & 0x80) {
            pc = 0xa969;
            break;
        }
        if (r8[al] & 0x80) {
            pc = 0xa98d;
            break;
        }
        r16[dx] = 0x0330;
        r8[al] = in8(r16[dx]);
        if (r8[al] != 0xfe) {
            pc = 0xa98d;
            break;
        }
        r16[cx] = 0x1388;
        r16[dx] = 0x0331;
    case 0xa97e:
        r8[al] = in8(r16[dx]);
        if (--r16[cx] && r8[al] & 0x40) {
            pc = 0xa97e;
            break;
        }
        if (r8[al] & 0x40) {
            pc = 0xa990;
            break;
        }
        r16[dx] = 0x0331;
        r8[al] = 0x3f;
        out8(r16[dx], r8[al]);
        pc = 0xa996;
        break;
    case 0xa98d:
        r16[bx]--;
        if (r16[bx] != 0) {
            pc = 0xa963;
            break;
        }
    case 0xa990:
        memory16set(ds, 0x557c, 0x0000);
    case 0xa996:
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[cx] = pop();
        r16[ax] = memory16get(ds, 0x557c);
        flags.zero = r16[ax] == 0;
        return;
    } while (1);
}
function* sub_a9a0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[dx]);
        push(r16[cx]);
        push(r16[bx]);
        push(r16[ax]);
        r16[bx] = 0x9009;
    case 0xa9a7:
        r16[cx] = 0x007f;
    case 0xa9aa:
        r8[ah] = r8[bh];
        r8[ah] += r8[bl];
        yield* sub_a8b2();
        r8[ah] = r8[cl];
        yield* sub_a8b2();
        r8[ah] = 0;
        yield* sub_a8b2();
        if (--r16[cx]) {
            pc = 0xa9aa;
            break;
        }
        r8[bl]--;
        if (r8[bl] != 0) {
            pc = 0xa9a7;
            break;
        }
        r16[ax] = pop();
        r16[bx] = pop();
        r16[cx] = pop();
        r16[dx] = pop();
        return;
    } while (1);
}
function* sub_a9c6() {
    push(r16[ax]);
    push(r16[cx]);
    lodsb_data_forward();
    r8[cl] = r8[al];
    lodsb_data_forward();
    r8[cl]--;
    yield* sub_a5fe();
    r16[cx] = pop();
    r16[ax] = pop();
}
function* sub_a9d4() {
    push(r16[cx]);
    r8[cl] = memory[ds*16 + si];
    si++;
    yield* sub_a5fe();
    r16[cx] = pop();
}
function* sub_a9dd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[cx]);
        if (r8[al] & 0x0f) {
            pc = 0xa9e7;
            break;
        }
        r8[al] |= memory[cs*16 + r16[bx] + 128];
    case 0xa9e7:
        r16[cx] = 0x0002;
        r8[ah] = r8[al];
        r8[ah] &= 0xf0;
        if (r8[ah] != 0xc0) {
            pc = 0xa9f5;
            break;
        }
        r16[cx]--;
    case 0xa9f5:
        yield* sub_a5fe();
        r16[cx] = pop();
        return;
    } while (1);
}
function* sub_a9fa() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x0001;
        memory16set(ds, 0x557e, r16[ax]);
        yield* sub_ae86();
        if (flags.zero) {
            pc = 0xaa0a;
            break;
        }
        yield* sub_adbb();
        pc = 0xaa10;
        break;
    case 0xaa0a:
        memory16set(ds, 0x557e, 0x0000);
    case 0xaa10:
        r16[ax] = memory16get(ds, 0x557e);
        flags.zero = r16[ax] == 0;
        return;
    } while (1);
}
function* sub_aa3b() {
    push(r16[ax]);
    push(di);
    push(si);
    push(r16[cx]);
    push(ds);
    push(r16[bx]);
    push(es);
    r8[bl] = r8[al];
    r8[bh] = 0;
    yield* sub_aa51();
    es = pop();
    r16[bx] = pop();
    ds = pop();
    r16[cx] = pop();
    si = pop();
    di = pop();
    r16[ax] = pop();
}
function* sub_aa51() {
    push(si);
    push(di);
    push(ds);
    push(es);
    si = 0x1228;
    ds = si;
    si = memory16get(ds, 0x5580);
    ds = memory16get(ds, 0x5580 + 2);
    di = memory16get(ds, si + 12);
    di += si;
    r16[bx] += r16[bx];
    r16[bx] += r16[bx];
    r16[cx] = r16[bx];
    r16[bx] += r16[bx];
    r16[bx] += r16[cx];
    di += r16[bx];
    r16[bx] = memory16get(ds, di);
    r16[bx] += r16[bx];
    di = r16[bx];
    r16[bx] += r16[bx];
    r16[bx] += r16[bx];
    r16[bx] += r16[bx];
    r16[bx] += r16[bx];
    r16[bx] -= di;
    di = memory16get(ds, si + 16);
    di += si;
    di += r16[bx];
    r16[bx] = 0;
    push(ds);
    push(di);
    r8[al] = r8[ah];
    di = pop();
    ds = pop();
    r8[ah] = 0;
    yield* sub_aa98();
    es = pop();
    ds = pop();
    di = pop();
    si = pop();
}
function* sub_aa98() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(r16[ax]);
        r8[ah] = 0x08;
        r8[al] = 0x00;
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dh] = memory[ds*16 + r16[bx] + di];
        if (r8[dh] == 0) {
            pc = 0xaaae;
            break;
        }
        pc = 0xac56;
        break;
    case 0xaaae:
        r8[dl] = r8[al];
        r8[dl] += 0xc0;
        r8[dh] = memory[ds*16 + r16[bx] + di + 4];
        r8[dh] &= 0x07;
        r8[dh] <<= 1;
        r8[ah] = memory[ds*16 + r16[bx] + di + 14];
        r8[ah] &= 0x01;
        r8[ah] ^= 0x01;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[ah] = 0;
        push(ds);
        push(di);
        r16[cx] = 0x1228;
        ds = r16[cx];
        di = 0x5593;
        di += r16[ax];
        r8[al] = memory[ds*16 + di];
        di = pop();
        ds = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x40;
        r8[dh] = memory[ds*16 + r16[bx] + di + 10];
        r8[dh] &= 0x3f;
        r8[ah] = memory[ds*16 + r16[bx] + di + 2];
        r8[ah] >>= 1;
        r8[ah] >>= 1;
        r8[ah] &= 0xc0;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x60;
        r8[dh] = memory[ds*16 + r16[bx] + di + 5];
        r8[dh] &= 0x0f;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[ah] = memory[ds*16 + r16[bx] + di + 8];
        r8[ah] &= 0x0f;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x80;
        r8[dh] = memory[ds*16 + r16[bx] + di + 6];
        r8[dh] &= 0x0f;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[ah] = memory[ds*16 + r16[bx] + di + 9];
        r8[ah] &= 0x0f;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x20;
        r8[dh] = memory[ds*16 + r16[bx] + di + 3];
        r8[dh] &= 0x0f;
        r8[ah] = memory[ds*16 + r16[bx] + di + 11];
        if (r8[ah] == 0) {
            pc = 0xab5e;
            break;
        }
        r8[dh] |= 0x80;
    case 0xab5e:
        r8[ah] = memory[ds*16 + r16[bx] + di + 12];
        if (r8[ah] == 0) {
            pc = 0xab68;
            break;
        }
        r8[dh] |= 0x40;
    case 0xab68:
        r8[ah] = memory[ds*16 + r16[bx] + di + 7];
        if (r8[ah] == 0) {
            pc = 0xab72;
            break;
        }
        r8[dh] |= 0x20;
    case 0xab72:
        r8[ah] = memory[ds*16 + r16[bx] + di + 13];
        if (r8[ah] == 0) {
            pc = 0xab7c;
            break;
        }
        r8[dh] |= 0x10;
    case 0xab7c:
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x43;
        r8[dh] = memory[ds*16 + r16[bx] + di + 23];
        r8[dh] &= 0x3f;
        r8[ah] = memory[ds*16 + r16[bx] + di + 15];
        r8[ah] >>= 1;
        r8[ah] >>= 1;
        r8[ah] &= 0xc0;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x63;
        r8[dh] = memory[ds*16 + r16[bx] + di + 18];
        r8[dh] &= 0x0f;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[ah] = memory[ds*16 + r16[bx] + di + 21];
        r8[ah] &= 0x0f;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x83;
        r8[dh] = memory[ds*16 + r16[bx] + di + 19];
        r8[dh] &= 0x0f;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[ah] = memory[ds*16 + r16[bx] + di + 22];
        r8[ah] &= 0x0f;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x23;
        r8[dh] = memory[ds*16 + r16[bx] + di + 16];
        r8[dh] &= 0x0f;
        r8[ah] = memory[ds*16 + r16[bx] + di + 24];
        if (r8[ah] == 0) {
            pc = 0xac02;
            break;
        }
        r8[dh] |= 0x80;
    case 0xac02:
        r8[ah] = memory[ds*16 + r16[bx] + di + 25];
        if (r8[ah] == 0) {
            pc = 0xac0c;
            break;
        }
        r8[dh] |= 0x40;
    case 0xac0c:
        r8[ah] = memory[ds*16 + r16[bx] + di + 20];
        if (r8[ah] == 0) {
            pc = 0xac16;
            break;
        }
        r8[dh] |= 0x20;
    case 0xac16:
        r8[ah] = memory[ds*16 + r16[bx] + di + 26];
        if (r8[ah] == 0) {
            pc = 0xac20;
            break;
        }
        r8[dh] |= 0x10;
    case 0xac20:
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0xe0;
        r8[dh] = memory[ds*16 + r16[bx] + di + 28];
        r8[dh] &= 0x03;
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0xe3;
        r8[dh] = memory[ds*16 + r16[bx] + di + 29];
        r8[dh] &= 0x03;
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
    case 0xac51:
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    case 0xac56:
        r8[al] = 0x01;
        r8[dl] = r8[al];
        r8[dl] += 0x40;
        r8[dh] = memory[ds*16 + r16[bx] + di + 10];
        r8[dh] &= 0x3f;
        r8[ah] = memory[ds*16 + r16[bx] + di + 2];
        r8[ah] >>= 1;
        r8[ah] >>= 1;
        r8[ah] &= 0xc0;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x60;
        r8[dh] = memory[ds*16 + r16[bx] + di + 5];
        r8[dh] &= 0x0f;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[ah] = memory[ds*16 + r16[bx] + di + 8];
        r8[ah] &= 0x0f;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x80;
        r8[dh] = memory[ds*16 + r16[bx] + di + 6];
        r8[dh] &= 0x0f;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[dh] <<= 1;
        r8[ah] = memory[ds*16 + r16[bx] + di + 9];
        r8[ah] &= 0x0f;
        r8[dh] |= r8[ah];
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[dl] += 0x20;
        r8[dh] = memory[ds*16 + r16[bx] + di + 3];
        r8[dh] &= 0x0f;
        r8[ah] = memory[ds*16 + r16[bx] + di + 11];
        if (r8[ah] == 0) {
            pc = 0xacd5;
            break;
        }
        r8[dh] |= 0x80;
    case 0xacd5:
        r8[ah] = memory[ds*16 + r16[bx] + di + 12];
        if (r8[ah] == 0) {
            pc = 0xacdf;
            break;
        }
        r8[dh] |= 0x40;
    case 0xacdf:
        r8[ah] = memory[ds*16 + r16[bx] + di + 7];
        if (r8[ah] == 0) {
            pc = 0xace9;
            break;
        }
        r8[dh] |= 0x20;
    case 0xace9:
        r8[ah] = memory[ds*16 + r16[bx] + di + 13];
        if (r8[ah] == 0) {
            pc = 0xacf3;
            break;
        }
        r8[dh] |= 0x10;
    case 0xacf3:
        push(r16[ax]);
        r8[ah] = r8[dl];
        r8[al] = r8[dh];
        yield* sub_aed7();
        r16[ax] = pop();
        pc = 0xac51;
        break;
        return;
    } while (1);
}
function* sub_acff() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[bx] = 0x0001;
    case 0xad03:
        push(r16[bx]);
        r16[ax] = 0;
        push(r16[ax]);
        push(r16[ax]);
        push(r16[ax]);
        yield* sub_af2d();
        r16[ax] = pop();
        r16[ax] = pop();
        r16[ax] = pop();
        r16[bx] = pop();
        r16[bx]++;
        if (r16s[bx] <= signed16(0x0009)) {
            pc = 0xad03;
            break;
        }
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_ad18() {
    push(r16[ax]);
    lodsb_data_forward();
    r8[ah] = 0x00;
    si += r16[ax];
    r16[ax] = pop();
}
function* sub_ad20() {
    push(r16[ax]);
    lodsb_data_forward();
    r8[ah] = 0x00;
    si += r16[ax];
    r16[ax] = pop();
}
function* sub_ad28() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(r16[cx]);
        if (r8[al] & 0x0f) {
            pc = 0xad33;
            break;
        }
        r8[al] |= memory[cs*16 + r16[bx] + 128];
    case 0xad33:
        r8[ah] = r8[al];
        r8[ah] &= 0x0f;
        if (r8s[ah] <= signed8(0x08)) {
            pc = 0xad3f;
            break;
        }
        pc = 0xad53;
        break;
    case 0xad3f:
        r8[ah] = r8[al];
        r8[ah] &= 0xf0;
        if (r8[ah] == 0xc0) {
            pc = 0xad5e;
            break;
        }
        if (r8[ah] == 0x90) {
            pc = 0xad6e;
            break;
        }
        if (r8[ah] == 0x80) {
            pc = 0xad97;
            break;
        }
    case 0xad53:
        si++;
        r8[al] &= 0xf0;
        if (r8[al] == 0xc0) {
            pc = 0xad5b;
            break;
        }
        si++;
    case 0xad5b:
        r16[cx] = pop();
        r16[bx] = pop();
        return;
    case 0xad5e:
        yield* sub_ad63();
        pc = 0xad5b;
        break;
    case 0xad6e:
        yield* sub_ad73();
        pc = 0xad5b;
        break;
    case 0xad97:
        push(r16[ax]);
        r8[al] &= 0x0f;
        r8[al] += 0xb0;
        r8[ah] = r8[al];
        push(ds);
        push(r16[bx]);
        r16[bx] = 0x01ed;
        ds = r16[bx];
        r16[bx] = 0x80cc;
        flags.carry = (r8[bl] + r8[ah]) >= 0x100;
        r8[bl] += r8[ah];
        r8[bh] += flags.carry;
        r8[al] = memory[ds*16 + r16[bx]];
        r16[bx] = pop();
        ds = pop();
        r8[al] &= 0xdf;
        yield* sub_aed7();
        lodsb_data_forward();
        lodsb_data_forward();
        r16[ax] = pop();
        pc = 0xad5b;
        break;
        return;
    } while (1);
}
function* sub_ad63() {
    r8[al] &= 0x0f;
    r8[ah] = r8[al];
    r8[al] = memory[ds*16 + si];
    yield* sub_aa3b();
    si++;
}
function* sub_ad73() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(di);
        push(es);
        r8[al] &= 0x0f;
        r8[ah] = 0;
        push(r16[ax]);
        lodsb_data_forward();
        push(r16[ax]);
        lodsb_data_forward();
        push(r16[ax]);
        if (r16[ax] == 0) {
            pc = 0xad89;
            break;
        }
        r16[ax] = 0x0020;
    case 0xad89:
        push(r16[ax]);
        yield* sub_af2d();
        sp += 0x0008;
        es = pop();
        di = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_adbb() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[ax]);
        r8[ah] = 0x40;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x41;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x42;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x48;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x49;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x4a;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x50;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x51;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x52;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x43;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x44;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x45;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x4b;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x4c;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x4d;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x53;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x54;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        push(r16[ax]);
        r8[ah] = 0x55;
        r8[al] = 0xff;
        yield* sub_aed7();
        r16[ax] = pop();
        r16[ax] = 0x0100;
    case 0xae61:
        yield* sub_aed7();
        r8[ah]++;
        if (r8[ah] != 0x40) {
            pc = 0xae61;
            break;
        }
        r16[ax] = 0x6000;
    case 0xae6e:
        yield* sub_aed7();
        r8[ah]++;
        if (r8[ah] != 0xf6) {
            pc = 0xae6e;
            break;
        }
        r16[ax] = 0x0406;
        yield* sub_aed7();
        r16[ax] = 0xbd00;
        yield* sub_aed7();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_ae86() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[cx]);
        push(r16[dx]);
        r16[ax] = 0x0460;
        yield* sub_aed7();
        r16[ax] = 0x0480;
        yield* sub_aed7();
        yield* sub_af26();
        push(r16[ax]);
        r16[ax] = 0x02ff;
        yield* sub_aed7();
        r16[ax] = 0x0421;
        yield* sub_aed7();
        r16[cx] = 0x00c7;
    case 0xaea8:
        yield* sub_af26();
        if (--r16[cx]) {
            pc = 0xaea8;
            break;
        }
        yield* sub_af26();
        push(r16[ax]);
        r16[ax] = 0x0460;
        yield* sub_aed7();
        r16[ax] = 0x0480;
        yield* sub_aed7();
        r16[ax] = pop();
        r16[dx] = pop();
        r8[ah] = 0x00;
        r8[al] &= 0xe0;
        r8[dl] &= 0xe0;
        if (r8[al] != 0xc0) {
            pc = 0xaed1;
            break;
        }
        if (r8[dl] != 0x00) {
            pc = 0xaed1;
            break;
        }
        r8[ah] = 0x01;
    case 0xaed1:
        flags.zero = r8[ah] == 0;
        r16[dx] = pop();
        r16[cx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_aed7() {
    r16[tx] = flags.carry | (flags.zero << 1);
    push(r16[tx]);
    flags.interrupts = false;
    push(r16[ax]);
    push(r16[dx]);
    push(ds);
    push(r16[bx]);
    r16[bx] = 0x01ed;
    ds = r16[bx];
    r16[bx] = 0x80cc;
    flags.carry = (r8[bl] + r8[ah]) >= 0x100;
    r8[bl] += r8[ah];
    r8[bh] += flags.carry;
    memory[ds*16 + r16[bx]] = r8[al];
    r16[bx] = pop();
    ds = pop();
    r16[dx] = 0x0388;
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    out8(r16[dx], r8[al]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r16[dx]++;
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    out8(r16[dx], r8[al]);
    r16[dx]--;
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r8[al] = in8(r16[dx]);
    r16[dx] = pop();
    r16[ax] = pop();
    r16[tx] = pop();
    flags.carry = r16[tx] & 1;
    flags.zero = (r16[tx] << 1) & 1;
}
function* sub_af26() {
    push(r16[dx]);
    r16[dx] = 0x0388;
    r8[al] = in8(r16[dx]);
    r16[dx] = pop();
}
function* sub_af2d() {
    push(0x7777);
    push(bp);
    bp = sp;
    push(r16[bx]);
    push(r16[cx]);
    push(r16[dx]);
    push(ds);
    push(r16[ax]);
    r8[ah] = 0x08;
    r8[al] = 0x00;
    yield* sub_aed7();
    r16[ax] = pop();
    push(r16[bx]);
    push(ds);
    push(r16[ax]);
    r16[bx] = 0x1228;
    ds = r16[bx];
    r16[bx] = memory16get(ss, bp + 10);
    r8[bh] = 0;
    r8[dl] = memory[ds*16 + r16[bx] + 21907];
    r8[dl] += 0x43;
    r8[ah] = r8[dl];
    push(ds);
    push(r16[bx]);
    r16[bx] = 0x01ed;
    ds = r16[bx];
    r16[bx] = 0x80cc;
    flags.carry = (r8[bl] + r8[ah]) >= 0x100;
    r8[bl] += r8[ah];
    r8[bh] += flags.carry;
    r8[al] = memory[ds*16 + r16[bx]];
    r16[bx] = pop();
    ds = pop();
    r8[ah] = 0x20;
    r8[dh] -= memory[ss*16 + bp + 6];
    r8[dh] >>= 1;
    r8[dh] >>= 1;
    r8[dh] >>= 1;
    r8[dh] >>= 1;
    r8[dh] &= 0x3f;
    r8[ah] -= r8[dh];
    r8[dh] = r8[ah];
    r8[dh] &= 0x3f;
    r8[al] &= 0xc0;
    r8[dh] |= r8[al];
    push(r16[dx]);
    push(r16[ax]);
    r8[ah] = r8[dl];
    r8[al] = r8[dh];
    yield* sub_aed7();
    r16[ax] = pop();
    r16[dx] = pop();
    r16[ax] = pop();
    ds = pop();
    r16[bx] = pop();
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] = memory16get(ss, bp + 8);
    di = 0x55b4;
    r8[cl] = memory[ds*16 + r16[bx] + di];
    r8[cl]--;
    di = 0x5614;
    r8[al] = memory[ds*16 + r16[bx] + di];
    r8[ah] = 0;
    r16[bx] = r16[ax];
    r16[bx] += r16[bx];
    di = 0x559c;
    r16[ax] = memory16get(ds, r16[bx] + di);
    r16[ax] &= 0x03ff;
    push(r16[ax]);
    r8[ah] = r8[al];
    r8[al] = 0xa0;
    r8[al] += memory[ss*16 + bp + 10];
    r8[tl] = r8[al];
    r8[al] = r8[ah];
    r8[ah] = r8[tl];
    yield* sub_aed7();
    r16[ax] = pop();
    ds = pop();
    r8[al] = r8[ah];
    r8[al] &= 0x03;
    r8[cl] &= 0x07;
    r8[cl] <<= 1;
    r8[cl] <<= 1;
    r8[al] += r8[cl];
    r8[al] += memory[ss*16 + bp + 4];
    r8[ah] = 0;
    push(r16[ax]);
    r8[ah] = r8[al];
    r8[al] = 0xb0;
    r8[al] += memory[ss*16 + bp + 10];
    r8[tl] = r8[ah];
    r8[ah] = r8[al];
    r8[al] = r8[tl];
    yield* sub_aed7();
    r16[ax] = pop();
    r16[dx] = pop();
    r16[cx] = pop();
    r16[bx] = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_afe5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        r16[bx] = 0x83cc;
        r16[cx] = 0x000f;
        r8[al] = 0;
    case 0xaff0:
        memory[cs*16 + r16[bx]] = r8[al];
        r16[bx]++;
        if (--r16[cx]) {
            pc = 0xaff0;
            break;
        }
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        r8[al] = 0;
        memory[cs*16 + 0x83ee] = r8[al];
        r8[al] = in8(0x61);
        r8[al] &= 0xfc;
        out8(0x61, r8[al]);
        return;
    } while (1);
}
function* sub_b09f() {
    push(r16[ax]);
    lodsb_data_forward();
    r8[ah] = 0x00;
    si += r16[ax];
    r16[ax] = pop();
}
function* sub_b0a7() {
    push(r16[ax]);
    lodsb_data_forward();
    r8[ah] = 0x00;
    si += r16[ax];
    r16[ax] = pop();
}
function* sub_b0af() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        r8[ah] = r8[al];
        r8[ah] &= 0xf0;
        if (r8[ah] == 0xc0) {
            pc = 0xb0f7;
            break;
        }
        if (r8[al] & 0x0f) {
            pc = 0xb0c4;
            break;
        }
        r8[al] |= memory[cs*16 + r16[bx] + 128];
    case 0xb0c4:
        r16[bx] = 0x83cc;
        r8[ah] = r8[al];
        r8[ah] &= 0x0f;
        flags.carry = (r8[bl] + r8[ah]) >= 0x100;
        r8[bl] += r8[ah];
        r8[bh] += flags.carry;
        r8[al] &= 0xf0;
        if (r8[al] == 0x90) {
            pc = 0xb0e9;
            break;
        }
        if (r8[al] == 0x80) {
            pc = 0xb0e0;
            break;
        }
        lodsb_data_forward();
        lodsb_data_forward();
    case 0xb0dd:
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    case 0xb0e0:
        lodsb_data_forward();
        lodsb_data_forward();
        r8[al] = 0;
    case 0xb0e4:
        memory[cs*16 + r16[bx]] = r8[al];
        pc = 0xb0dd;
        break;
    case 0xb0e9:
        lodsb_data_forward();
        r8[ah] = r8[al];
        lodsb_data_forward();
        if (r8[al] == 0x00) {
            pc = 0xb0f5;
            break;
        }
        r8[al] = r8[ah];
        pc = 0xb0e4;
        break;
    case 0xb0f5:
        pc = 0xb0e4;
        break;
    case 0xb0f7:
        yield* sub_b0fc();
        pc = 0xb0dd;
        break;
        return;
    } while (1);
}
function* sub_b0fc() {
    r8[al] &= 0x0f;
    r8[ah] = r8[al];
    r8[al] = memory[ds*16 + si];
    push(r16[bx]);
    r16[bx] = 0x8473;
    flags.carry = (r8[bl] + r8[ah]) >= 0x100;
    r8[bl] += r8[ah];
    r8[bh] += flags.carry;
    memory[cs*16 + r16[bx]] = r8[al];
    r16[bx] = pop();
    si++;
}
function* sub_b14c() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[ax] = 0x0000;
    interrupt(0x33);
    memory[ds*16 + 0x5674] = r8[al];
    r16[ax] ^= 0xffff;
    push(r16[ax]);
    r16[ax] = 0x0004;
    r16[cx] = 0x0000;
    r16[dx] = r16[cx];
    interrupt(0x33);
    r16[ax] = 0x0007;
    r16[cx] = 0x0000;
    r16[dx] = 0x0280;
    interrupt(0x33);
    r16[ax] = 0x0008;
    r16[cx] = 0x0000;
    r16[dx] = 0x00c8;
    interrupt(0x33);
    r16[ax] = pop();
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
}
function* sub_b274() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ed2;
    yield* sub_ed20();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_b281() {
    push(cs);
    cs = 0x0ed2;
    yield* sub_ed3f();
    assert(cs == 0x01ed);
}
function* sub_b288() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_da88();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_b298() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_dcce();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_b2a8() {
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    cs = 0x0ed9;
    yield* sub_11a7d();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_b2d6() {
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    cs = 0x0ed9;
    yield* sub_11b38();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_b2e0() {
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    cs = 0x0ed9;
    yield* sub_11b62();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_b2f4() {
    push(cs);
    cs = 0x0ed9;
    yield* sub_11ec7();
    assert(cs == 0x01ed);
}
function* sub_b2fa() {
    push(0x7777);
    push(bp);
    bp = sp;
    push(cs);
    cs = 0x0ed9;
    yield* sub_11f47();
    assert(cs == 0x01ed);
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_b304() {
}
function* sub_b310() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (memory16get(ds, 0x683e) != 0x0000) {
            pc = 0xb321;
            break;
        }
        r8[al] = in8(0x61);
        r8[al] |= 0x03;
        yield* sub_b304();
        out8(0x61, r8[al]);
        return;
    case 0xb321:
        r8[al] = in8(0x61);
        r8[al] &= 0xfc;
        yield* sub_b304();
        out8(0x61, r8[al]);
        return;
    } while (1);
}
function* sub_b321() {
    r8[al] = in8(0x61);
    r8[al] &= 0xfc;
    yield* sub_b304();
    out8(0x61, r8[al]);
}
function* sub_b32b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.carry = r16[ax] < 0x00ff;
        if (r16[ax] == 0x00ff) {
            pc = 0xb337;
            break;
        }
        flags.carry = memory16get(cs, 0x946c) < r16[ax];
        if (memory16get(cs, 0x946c) < r16[ax])
            return;
    case 0xb337:
        memory16set(cs, 0x946c, r16[ax]);
        return;
    } while (1);
}
function* sub_b33e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x683e);
        r16[tx] = r16[ax];
        r16[ax] = 0x00ff;
        if (stop("check inject: cmp r16[ax], 0") && r16[tx] == 0x0000) {
            pc = 0xb351;
            break;
        }
        r16[ax] = 0x0000;
        yield* sub_b32b();
        return;
    case 0xb351:
        yield* sub_b32b();
        yield* sub_b321();
        return;
    } while (1);
}
function* sub_b358() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[tx] = flags.carry | (flags.zero << 1);
        push(r16[tx]);
        flags.interrupts = false;
        r16[ax] = memory16get(ss, bp + 4);
        yield* sub_b32b();
        r16[ax] = 0xffff;
        if (flags.carry) {
            pc = 0xb3ca;
            break;
        }
        r16[ax] = memory16get(ss, bp + 6);
        memory16set(cs, 0x9788, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        memory16set(cs, 0x978a, r16[ax]);
        r16[ax] = memory16get(ss, bp + 10);
        memory16set(cs, 0x9796, r16[ax]);
        memory16set(cs, 0x978c, r16[ax]);
        r16[ax] = memory16get(ss, bp + 12);
        memory16set(cs, 0x978e, r16[ax]);
        r16[ax] = memory16get(ss, bp + 14);
        memory16set(cs, 0x9790, r16[ax]);
        r16[ax] = memory16get(ss, bp + 16);
        memory16set(cs, 0x9792, r16[ax]);
        memory16set(cs, 0x9798, r16[ax]);
        r16[ax] = memory16get(ss, bp + 18);
        memory16set(cs, 0x9794, r16[ax]);
        memory[cs*16 + 0x979a] = 0x0f;
        r16[cx] = 0x9631;
        memory16set(cs, 0x97a1, r16[cx]);
        r16[dx] = 0x01ed;
        memory16set(cs, 0x979f, r16[dx]);
        r16[ax] = memory16get(ss, bp + 14);
        r16[bx] = 0x0002;
        yield* sub_9cc9();
        yield* sub_b310();
        r16[ax] = 0;
    case 0xb3ca:
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_b3d2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[tx] = flags.carry | (flags.zero << 1);
        push(r16[tx]);
        flags.interrupts = false;
        r16[ax] = memory16get(ss, bp + 4);
        yield* sub_b32b();
        r16[ax] = 0xffff;
        if (flags.carry) {
            pc = 0xb435;
            break;
        }
        r16[ax] = memory16get(ss, bp + 6);
        memory16set(cs, 0x9788, r16[ax]);
        r16[ax] = memory16get(ss, bp + 8);
        memory16set(cs, 0x978a, r16[ax]);
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax] = memory16get(ss, bp + 10);
        memory16set(cs, 0x9790, r16[ax]);
        r16[ax] = memory16get(ss, bp + 12);
        memory16set(cs, 0x9792, r16[ax]);
        memory16set(cs, 0x9798, r16[ax]);
        r16[ax] = memory16get(ss, bp + 14);
        memory16set(cs, 0x9794, r16[ax]);
        memory[cs*16 + 0x979a] = 0x0f;
        r16[cx] = 0x96c4;
        memory16set(cs, 0x97a1, r16[cx]);
        r16[dx] = 0x01ed;
        memory16set(cs, 0x979f, r16[dx]);
        r16[ax] = memory16get(ss, bp + 10);
        r16[bx] = 0x0002;
        yield* sub_9cc9();
        yield* sub_b310();
        r16[ax] = 0;
    case 0xb435:
        r16[tx] = pop();
        flags.carry = r16[tx] & 1;
        flags.zero = (r16[tx] << 1) & 1;
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_b674() {
    push(cs);
    cs = 0x1219;
    yield* sub_12190();
    assert(cs == 0x01ed);
}
function* sub_b67a() {
    yield* sub_998b();
    cs = pop();
}
function* sub_b695() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 4);
    r16[dx] = memory16get(ss, bp + 6);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_dd71();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_b6a5() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_dd8b();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_b6c1() {
    push(cs);
    cs = 0x0ca6;
    yield* sub_dddb();
    assert(cs == 0x01ed);
}
function* sub_b6d4() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[dx] = memory16get(ss, bp + 6);
    r16[ax] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_de4c();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_b6e4() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[bx] = memory16get(ss, bp + 4);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_de69();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_b6f1() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 4);
    r16[bx] = memory16get(ss, bp + 6);
    r16[cx] = memory16get(ss, bp + 8);
    r16[dx] = memory16get(ss, bp + 10);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_de82();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_b707() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 4);
    r16[dx] = memory16get(ss, bp + 6);
    bp = pop();
    push(cs);
    cs = 0x0ca6;
    yield* sub_dea1();
    assert(cs == 0x01ed);
    assert(pop() == 0x7777);
}
function* sub_b734() {
    push(cs);
    cs = 0x1223;
    yield* sub_12230();
    assert(cs == 0x01ed);
}
function* sub_b75e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        si = memory16get(ss, bp + 4);
        if (signed16(si) < 0) {
            pc = 0xb76e;
            break;
        }
        if (signed16(si) < signed16(0x0014)) {
            pc = 0xb777;
            break;
        }
    case 0xb76e:
        r16[ax] = 0x0006;
        push(r16[ax]);
        yield* sub_c048();
        pc = 0xb786;
        break;
    case 0xb777:
        r16[bx] = si;
        r16[bx] <<= 1;
        memory16set(ds, r16[bx] + 27420, 0xffff);
        push(si);
        yield* sub_be85();
        r16[cx] = pop();
    case 0xb786:
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_b78a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        pc = 0xb799;
        break;
    case 0xb78f:
        r16[bx] = memory16get(ds, 0x6982);
        r16[bx] <<= 1;
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 41406));
    case 0xb799:
        r16[ax] = memory16get(ds, 0x6982);
        memory16set(ds, 0x6982, memory16get(ds, 0x6982) - 1);
        if (r16[ax]) {
            pc = 0xb78f;
            break;
        }
        push(memory16get(ss, bp + 4));
        yield* sub_1fc6();
        r16[cx] = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_b7ad() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        push(di);
        r16[ax] = memory16get(ss, bp + 6);
        r16[ax]++;
        si = r16[ax];
        si -= memory16get(ds, 0x0079);
        r16[ax] = si;
        r16[ax] += 0x003f;
        r8[cl] = 0x06;
        r16[ax] >>= r8[cl];
        si = r16[ax];
        if (si != memory16get(ds, 0x698a)) {
            pc = 0xb7df;
            break;
        }
    case 0xb7cd:
        r16[ax] = memory16get(ss, bp + 6);
        r16[dx] = memory16get(ss, bp + 4);
        memory16set(ds, 0x0087, r16[dx]);
        memory16set(ds, 0x0089, r16[ax]);
        r16[ax] = 0x0001;
        pc = 0xb825;
        break;
    case 0xb7df:
        r8[cl] = 0x06;
        si <<= r8[cl];
        di = memory16get(ds, 0x008d);
        r16[ax] = si;
        r16[ax] += memory16get(ds, 0x0079);
        if (r16[ax] <= di) {
            pc = 0xb7f9;
            break;
        }
        r16[ax] = di;
        r16[ax] -= memory16get(ds, 0x0079);
        si = r16[ax];
    case 0xb7f9:
        push(si);
        push(memory16get(ds, 0x0079));
        yield* sub_c352();
        r16[cx] = pop();
        r16[cx] = pop();
        di = r16[ax];
        if (di != 0xffff) {
            pc = 0xb815;
            break;
        }
        r16[ax] = si;
        r8[cl] = 0x06;
        r16[ax] >>= r8[cl];
        memory16set(ds, 0x698a, r16[ax]);
        pc = 0xb7cd;
        break;
    case 0xb815:
        r16[ax] = memory16get(ds, 0x0079);
        r16[ax] += di;
        memory16set(ds, 0x008b, 0x0000);
        memory16set(ds, 0x008d, r16[ax]);
        r16[ax] = 0;
    case 0xb825:
        di = pop();
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        sp += 4;
        return;
    } while (1);
}
function* sub_b82b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[cx] = memory16get(ds, 0x0085);
        r16[bx] = memory16get(ds, 0x0083);
        r16[dx] = memory16get(ss, bp + 6);
        r16[ax] = memory16get(ss, bp + 4);
        yield* sub_c8fb();
        if (flags.carry) {
            pc = 0xb861;
            break;
        }
        r16[cx] = memory16get(ds, 0x008d);
        r16[bx] = memory16get(ds, 0x008b);
        r16[dx] = memory16get(ss, bp + 6);
        r16[ax] = memory16get(ss, bp + 4);
        yield* sub_c8fb();
        if (!flags.zero && !flags.carry) {
            pc = 0xb861;
            break;
        }
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_b7ad();
        if (r16[ax]) {
            pc = 0xb866;
            break;
        }
    case 0xb861:
        r16[ax] = 0xffff;
        pc = 0xb868;
        break;
    case 0xb866:
        r16[ax] = 0;
    case 0xb868:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_b86a() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0008;
        r16[dx] = memory16get(ds, 0x0089);
        r16[ax] = memory16get(ds, 0x0087);
        r16[cx] = memory16get(ss, bp + 6);
        r16[bx] = memory16get(ss, bp + 4);
        yield* sub_c865();
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, r16[dx]);
        r16[cx] = memory16get(ds, 0x0085);
        r16[bx] = memory16get(ds, 0x0083);
        r16[ax] = memory16get(ss, bp - 4);
        yield* sub_c8fb();
        if (flags.carry) {
            pc = 0xb8a9;
            break;
        }
        r16[cx] = memory16get(ds, 0x008d);
        r16[bx] = memory16get(ds, 0x008b);
        r16[dx] = memory16get(ss, bp - 2);
        r16[ax] = memory16get(ss, bp - 4);
        yield* sub_c8fb();
        if (flags.zero || flags.carry) {
            pc = 0xb8b1;
            break;
        }
    case 0xb8a9:
        r16[dx] = 0xffff;
        r16[ax] = 0xffff;
        pc = 0xb8d3;
        break;
    case 0xb8b1:
        r16[ax] = memory16get(ds, 0x0089);
        r16[dx] = memory16get(ds, 0x0087);
        memory16set(ss, bp - 8, r16[dx]);
        memory16set(ss, bp - 6, r16[ax]);
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        yield* sub_b7ad();
        if (r16[ax]) {
            pc = 0xb8cd;
            break;
        }
        pc = 0xb8a9;
        break;
    case 0xb8cd:
        r16[dx] = memory16get(ss, bp - 6);
        r16[ax] = memory16get(ss, bp - 8);
    case 0xb8d3:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_b8d7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        r16[ax] = memory16get(ss, bp + 4);
        r16[ax] |= memory16get(ss, bp + 6);
        if (r16[ax]) {
            pc = 0xb8e9;
            break;
        }
        yield* sub_b9a3();
        pc = 0xb99e;
        break;
    case 0xb8e9:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        r16[ax] = memory16get(es, r16[bx] + 18);
        if (r16[ax] == memory16get(ss, bp + 4)) {
            pc = 0xb8fb;
            break;
        }
    case 0xb8f5:
        r16[ax] = 0xffff;
        pc = 0xb9a0;
        break;
    case 0xb8fb:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        if (memory16gets(es, r16[bx]) < signed16(0x0000)) {
            pc = 0xb952;
            break;
        }
        if (memory16get(es, r16[bx] + 2) & 0x0008) {
            pc = 0xb921;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 14);
        r16[dx] = memory16get(ss, bp + 4);
        r16[dx] += 0x0005;
        if (r16[ax] != memory16get(ss, bp + 6)) {
            pc = 0xb950;
            break;
        }
        if (memory16get(es, r16[bx] + 12) != r16[dx]) {
            pc = 0xb950;
            break;
        }
    case 0xb921:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        memory16set(es, r16[bx], 0x0000);
        r16[ax] = memory16get(es, r16[bx] + 14);
        r16[dx] = memory16get(ss, bp + 4);
        r16[dx] += 0x0005;
        if (r16[ax] != memory16get(ss, bp + 6)) {
            pc = 0xb950;
            break;
        }
        if (memory16get(es, r16[bx] + 12) != r16[dx]) {
            pc = 0xb950;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 10);
        r16[dx] = memory16get(es, r16[bx] + 8);
        memory16set(es, r16[bx] + 12, r16[dx]);
        memory16set(es, r16[bx] + 14, r16[ax]);
        pc = 0xb99e;
        break;
    case 0xb950:
        pc = 0xb99e;
        break;
    case 0xb952:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        r16[ax] = memory16get(es, r16[bx] + 6);
        r16[ax] += memory16get(es, r16[bx]);
        r16[ax]++;
        si = r16[ax];
        r16[ax] = memory16get(es, r16[bx]);
        r16[ax] -= si;
        memory16set(es, r16[bx], r16[ax]);
        push(si);
        r16[ax] = memory16get(es, r16[bx] + 10);
        r16[dx] = memory16get(es, r16[bx] + 8);
        memory16set(es, r16[bx] + 12, r16[dx]);
        memory16set(es, r16[bx] + 14, r16[ax]);
        push(r16[ax]);
        push(r16[dx]);
        r8[al] = memory[es*16 + r16[bx] + 4];
        cbw();
        push(r16[ax]);
        yield* sub_bcce();
        sp += 0x0008;
        if (r16[ax] == si) {
            pc = 0xb99e;
            break;
        }
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        if (memory16get(es, r16[bx] + 2) & 0x0200) {
            pc = 0xb99e;
            break;
        }
        memory16set(es, r16[bx] + 2, memory16get(es, r16[bx] + 2) | 0x0010);
        pc = 0xb8f5;
        break;
    case 0xb99e:
        r16[ax] = 0;
    case 0xb9a0:
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_b9a3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        push(si);
        push(di);
        di = 0;
        si = 0x0014;
        memory16set(ss, bp - 4, 0x698c);
        memory16set(ss, bp - 2, ds);
        pc = 0xb9d5;
        break;
    case 0xb9ba:
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        if (!(memory16get(es, r16[bx] + 2) & 0x0003)) {
            pc = 0xb9d1;
            break;
        }
        push(memory16get(ss, bp - 2));
        push(memory16get(ss, bp - 4));
        yield* sub_b8d7();
        r16[cx] = pop();
        r16[cx] = pop();
        di++;
    case 0xb9d1:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 0x0014);
    case 0xb9d5:
        r16[ax] = si;
        si--;
        if (r16[ax]) {
            pc = 0xb9ba;
            break;
        }
        r16[ax] = di;
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_b9e4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        push(si);
        push(di);
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        if (memory16gets(es, r16[bx]) >= signed16(0x0000)) {
            pc = 0xb9ff;
            break;
        }
        r16[ax] = memory16get(es, r16[bx] + 6);
        r16[ax] += memory16get(es, r16[bx]);
        r16[ax]++;
        pc = 0xba0a;
        break;
    case 0xb9ff:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        r16[ax] = memory16get(es, r16[bx]);
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        r16[ax] ^= r16[dx];
        r16[ax] -= r16[dx];
    case 0xba0a:
        si = r16[ax];
        di = r16[ax];
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        if (!(memory16get(es, r16[bx] + 2) & 0x0040)) {
            pc = 0xba1b;
            break;
        }
        pc = 0xba5e;
        break;
    case 0xba1b:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        r16[ax] = memory16get(es, r16[bx] + 14);
        r16[dx] = memory16get(es, r16[bx] + 12);
        memory16set(ss, bp - 4, r16[dx]);
        memory16set(ss, bp - 2, r16[ax]);
        if (memory16gets(es, r16[bx]) >= signed16(0x0000)) {
            pc = 0xba57;
            break;
        }
        pc = 0xba41;
        break;
    case 0xba34:
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) - 1);
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        if (memory[es*16 + r16[bx]] != 0x0a) {
            pc = 0xba41;
            break;
        }
        di++;
    case 0xba41:
        r16[ax] = si;
        si--;
        if (r16[ax]) {
            pc = 0xba34;
            break;
        }
        pc = 0xba5e;
        break;
    case 0xba4a:
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
        if (memory[es*16 + r16[bx]] != 0x0a) {
            pc = 0xba57;
            break;
        }
        di++;
    case 0xba57:
        r16[ax] = si;
        si--;
        if (r16[ax]) {
            pc = 0xba4a;
            break;
        }
    case 0xba5e:
        r16[ax] = di;
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        sp += 4;
        return;
    } while (1);
}
function* sub_ba68() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_b8d7();
        r16[cx] = pop();
        r16[cx] = pop();
        if (!r16[ax]) {
            pc = 0xba7f;
            break;
        }
        r16[ax] = 0xffff;
        pc = 0xbae2;
        break;
    case 0xba7f:
        if (memory16get(ss, bp + 12) != 0x0001) {
            pc = 0xba9e;
            break;
        }
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        if (memory16gets(es, r16[bx]) <= signed16(0x0000)) {
            pc = 0xba9e;
            break;
        }
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_b9e4();
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        flags.carry = memory16get(ss, bp + 8) < r16[ax];
        memory16set(ss, bp + 8, memory16get(ss, bp + 8) - r16[ax]);
        memory16set(ss, bp + 10, memory16get(ss, bp + 10) - (r16[dx] + flags.carry));
    case 0xba9e:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        memory16set(es, r16[bx] + 2, memory16get(es, r16[bx] + 2) & 0xfe5f);
        memory16set(es, r16[bx], 0x0000);
        r16[ax] = memory16get(es, r16[bx] + 10);
        r16[dx] = memory16get(es, r16[bx] + 8);
        memory16set(es, r16[bx] + 12, r16[dx]);
        memory16set(es, r16[bx] + 14, r16[ax]);
        push(memory16get(ss, bp + 12));
        push(memory16get(ss, bp + 10));
        push(memory16get(ss, bp + 8));
        r8[al] = memory[es*16 + r16[bx] + 4];
        cbw();
        push(r16[ax]);
        yield* sub_c096();
        sp += 0x0008;
        if (r16[dx] != 0xffff) {
            pc = 0xbae0;
            break;
        }
        if (r16[ax] != 0xffff) {
            pc = 0xbae0;
            break;
        }
        r16[ax] = 0xffff;
        pc = 0xbae2;
        break;
    case 0xbae0:
        r16[ax] = 0;
    case 0xbae2:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_bb32() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r8[al] = memory[ds*16 + 0x6990];
        cbw();
        push(r16[ax]);
        yield* sub_c085();
        r16[cx] = pop();
        if (r16[ax]) {
            pc = 0xbb45;
            break;
        }
        memory16set(ds, 0x698e, memory16get(ds, 0x698e) & 0xfdff);
    case 0xbb45:
        r16[ax] = 0x0200;
        push(r16[ax]);
        if (!(memory16get(ds, 0x698e) & 0x0200)) {
            pc = 0xbb56;
            break;
        }
        r16[ax] = 0x0001;
        pc = 0xbb58;
        break;
    case 0xbb56:
        r16[ax] = 0;
    case 0xbb58:
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0;
        push(r16[ax]);
        push(r16[dx]);
        push(ds);
        r16[ax] = 0x698c;
        push(r16[ax]);
        yield* sub_bba3();
        sp += 0x000c;
        r8[al] = memory[ds*16 + 0x69a4];
        cbw();
        push(r16[ax]);
        yield* sub_c085();
        r16[cx] = pop();
        if (r16[ax]) {
            pc = 0xbb7d;
            break;
        }
        memory16set(ds, 0x69a2, memory16get(ds, 0x69a2) & 0xfdff);
    case 0xbb7d:
        r16[ax] = 0x0200;
        push(r16[ax]);
        if (!(memory16get(ds, 0x69a2) & 0x0200)) {
            pc = 0xbb8e;
            break;
        }
        r16[ax] = 0x0002;
        pc = 0xbb90;
        break;
    case 0xbb8e:
        r16[ax] = 0;
    case 0xbb90:
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0;
        push(r16[ax]);
        push(r16[dx]);
        push(ds);
        r16[ax] = 0x69a0;
        push(r16[ax]);
        yield* sub_bba3();
        sp += 0x000c;
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_bba3() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        push(di);
        di = memory16get(ss, bp + 12);
        si = memory16get(ss, bp + 14);
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        r16[ax] = memory16get(es, r16[bx] + 18);
        if (r16[ax] != memory16get(ss, bp + 4)) {
            pc = 0xbbc5;
            break;
        }
        if (signed16(di) > signed16(0x0002)) {
            pc = 0xbbc5;
            break;
        }
        if (si <= 0x7fff) {
            pc = 0xbbcb;
            break;
        }
    case 0xbbc5:
        r16[ax] = 0xffff;
        pc = 0xbcb2;
        break;
    case 0xbbcb:
        if (memory16get(ds, 0x6b4a) != 0x0000) {
            pc = 0xbbe1;
            break;
        }
        if (memory16get(ss, bp + 4) != 0x69a0) {
            pc = 0xbbe1;
            break;
        }
        memory16set(ds, 0x6b4a, 0x0001);
        pc = 0xbbf5;
        break;
    case 0xbbe1:
        if (memory16get(ds, 0x6b48) != 0x0000) {
            pc = 0xbbf5;
            break;
        }
        if (memory16get(ss, bp + 4) != 0x698c) {
            pc = 0xbbf5;
            break;
        }
        memory16set(ds, 0x6b48, 0x0001);
    case 0xbbf5:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        if (memory16get(es, r16[bx]) == 0x0000) {
            pc = 0xbc14;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_ba68();
        sp += 0x000a;
    case 0xbc14:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        if (!(memory16get(es, r16[bx] + 2) & 0x0004)) {
            pc = 0xbc2c;
            break;
        }
        push(memory16get(es, r16[bx] + 10));
        push(memory16get(es, r16[bx] + 8));
        yield* sub_c4fe();
        r16[cx] = pop();
        r16[cx] = pop();
    case 0xbc2c:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        memory16set(es, r16[bx] + 2, memory16get(es, r16[bx] + 2) & 0xfff3);
        memory16set(es, r16[bx] + 6, 0x0000);
        r16[ax] = memory16get(ss, bp + 6);
        r16[dx] = memory16get(ss, bp + 4);
        r16[dx] += 0x0005;
        memory16set(es, r16[bx] + 8, r16[dx]);
        memory16set(es, r16[bx] + 10, r16[ax]);
        memory16set(es, r16[bx] + 12, r16[dx]);
        memory16set(es, r16[bx] + 14, r16[ax]);
        if (di == 0x0002) {
            pc = 0xbcb0;
            break;
        }
        if (!si) {
            pc = 0xbcb0;
            break;
        }
        memory16set(ds, 0x6984, 0x9f25);
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] |= memory16get(ss, bp + 10);
        if (r16[ax]) {
            pc = 0xbc88;
            break;
        }
        push(si);
        yield* sub_c5e4();
        r16[cx] = pop();
        memory16set(ss, bp + 8, r16[ax]);
        memory16set(ss, bp + 10, r16[dx]);
        r16[ax] |= r16[dx];
        if (!r16[ax]) {
            pc = 0xbc85;
            break;
        }
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        memory16set(es, r16[bx] + 2, memory16get(es, r16[bx] + 2) | 0x0004);
        pc = 0xbc88;
        break;
    case 0xbc85:
        pc = 0xbbc5;
        break;
    case 0xbc88:
        r16[bx] = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        r16[ax] = memory16get(ss, bp + 10);
        r16[dx] = memory16get(ss, bp + 8);
        memory16set(es, r16[bx] + 12, r16[dx]);
        memory16set(es, r16[bx] + 14, r16[ax]);
        memory16set(es, r16[bx] + 8, r16[dx]);
        memory16set(es, r16[bx] + 10, r16[ax]);
        memory16set(es, r16[bx] + 6, si);
        if (di != 0x0001) {
            pc = 0xbcb0;
            break;
        }
        memory16set(es, r16[bx] + 2, memory16get(es, r16[bx] + 2) | 0x0008);
    case 0xbcb0:
        r16[ax] = 0;
    case 0xbcb2:
        di = pop();
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_bcce() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x008e;
        push(si);
        push(di);
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax]++;
        if (r16[ax] >= 0x0002) {
            pc = 0xbce5;
            break;
        }
        r16[ax] = 0;
        pc = 0xbdef;
        break;
    case 0xbce5:
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] <<= 1;
        if (!(memory16get(ds, r16[bx] + 27420) & 0x8000)) {
            pc = 0xbd07;
            break;
        }
        push(memory16get(ss, bp + 10));
        push(memory16get(ss, bp + 8));
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_c36e();
        sp += 0x0008;
        pc = 0xbdef;
        break;
    case 0xbd07:
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] <<= 1;
        memory16set(ds, r16[bx] + 27420, memory16get(ds, r16[bx] + 27420) & 0xfdff);
        r16[ax] = memory16get(ss, bp + 8);
        r16[dx] = memory16get(ss, bp + 6);
        memory16set(ss, bp - 12, r16[dx]);
        memory16set(ss, bp - 10, r16[ax]);
        r16[ax] = memory16get(ss, bp + 10);
        memory16set(ss, bp - 6, r16[ax]);
        pc = 0xbd9e;
        break;
    case 0xbd26:
        memory16set(ss, bp - 6, memory16get(ss, bp - 6) - 1);
        r16[bx] = memory16get(ss, bp - 12);
        es = memory16get(ss, bp - 12 + 2);
        memory16set(ss, bp - 12, memory16get(ss, bp - 12) + 1);
        r8[al] = memory[es*16 + r16[bx]];
        memory[ss*16 + bp - 7] = r8[al];
        if (r8[al] != 0x0a) {
            pc = 0xbd43;
            break;
        }
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        memory[es*16 + r16[bx]] = 0x0d;
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
    case 0xbd43:
        r16[bx] = memory16get(ss, bp - 4);
        es = memory16get(ss, bp - 4 + 2);
        r8[al] = memory[ss*16 + bp - 7];
        memory[es*16 + r16[bx]] = r8[al];
        memory16set(ss, bp - 4, memory16get(ss, bp - 4) + 1);
        r16[ax] = bp - 0x8e;
        r16[dx] = memory16get(ss, bp - 4);
        r16[bx] = 0;
        flags.carry = r16[dx] < r16[ax];
        r16[dx] -= r16[ax];
        r16[bx] -= flags.carry;
        if (r16s[bx] < 0) {
            pc = 0xbda8;
            break;
        }
        if (r16[bx]) {
            pc = 0xbd69;
            break;
        }
        if (r16[dx] < 0x0080) {
            pc = 0xbda8;
            break;
        }
    case 0xbd69:
        r16[ax] = bp - 0x8e;
        r16[dx] = memory16get(ss, bp - 4);
        r16[bx] = 0;
        flags.carry = r16[dx] < r16[ax];
        r16[dx] -= r16[ax];
        r16[bx] -= flags.carry;
        si = r16[dx];
        push(si);
        push(ss);
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        yield* sub_c36e();
        sp += 0x0008;
        di = r16[ax];
        if (r16[ax] == si) {
            pc = 0xbd9e;
            break;
        }
        if (stop(/*condition!*/)) {
            pc = 0xbd94;
            break;
        }
    case 0xbd8f:
        r16[ax] = 0xffff;
        pc = 0xbdea;
        break;
    case 0xbd94:
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax] -= memory16get(ss, bp - 6);
        pc = 0xbde6;
        break;
    case 0xbd9e:
        r16[ax] = bp - 0x8e;
        memory16set(ss, bp - 4, r16[ax]);
        memory16set(ss, bp - 2, ss);
    case 0xbda8:
        if (memory16get(ss, bp - 6) == 0x0000) {
            pc = 0xbdb1;
            break;
        }
        pc = 0xbd26;
        break;
    case 0xbdb1:
        r16[ax] = bp - 0x8e;
        r16[dx] = memory16get(ss, bp - 4);
        r16[bx] = 0;
        flags.carry = r16[dx] < r16[ax];
        r16[dx] -= r16[ax];
        r16[bx] -= flags.carry;
        si = r16[dx];
        r16[ax] = r16[dx];
        if (stop(/*condition!*/)) {
            pc = 0xbdec;
            break;
        }
        push(si);
        push(ss);
        r16[ax] = bp - 0x8e;
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        yield* sub_c36e();
        sp += 0x0008;
        di = r16[ax];
        if (r16[ax] == si) {
            pc = 0xbdec;
            break;
        }
        if (stop(/*condition!*/)) {
            pc = 0xbde3;
            break;
        }
        pc = 0xbd8f;
        break;
    case 0xbde3:
        r16[ax] = memory16get(ss, bp + 10);
    case 0xbde6:
        r16[ax] += di;
        r16[ax] -= si;
    case 0xbdea:
        pc = 0xbdef;
        break;
    case 0xbdec:
        r16[ax] = memory16get(ss, bp + 10);
    case 0xbdef:
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_be68() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(ds);
        r16[cx] = memory16get(ss, bp + 10);
        r8[ah] = 0x43;
        r8[al] = memory[ss*16 + bp + 8];
        r16[dx] = memory16get(ss, bp + 4);
        ds = memory16get(ss, bp + 4 + 2);
        interrupt(0x21);
        ds = pop();
        if (flags.carry) {
            pc = 0xbe7f;
            break;
        }
        r16[tx] = r16[cx];
        r16[cx] = r16[ax];
        r16[ax] = r16[tx];
        pc = 0xbe83;
        break;
    case 0xbe7f:
        push(r16[ax]);
        yield* sub_c048();
    case 0xbe83:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_be85() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r8[ah] = 0x3e;
        r16[bx] = memory16get(ss, bp + 4);
        interrupt(0x21);
        if (flags.carry) {
            pc = 0xbe9d;
            break;
        }
        r16[bx] <<= 1;
        memory16set(ds, r16[bx] + 27420, 0xffff);
        r16[ax] = 0;
        pc = 0xbea1;
        break;
    case 0xbe9d:
        push(r16[ax]);
        yield* sub_c048();
    case 0xbea1:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_bf70() {
    push(0x7777);
    push(bp);
    bp = sp;
    r8[ah] = 0x25;
    r8[al] = memory[ss*16 + bp + 4];
    push(ds);
    r16[dx] = memory16get(ss, bp + 6);
    ds = memory16get(ss, bp + 6 + 2);
    interrupt(0x21);
    ds = pop();
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_bfb9() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = memory16get(ss, bp + 4);
    memory16set(ds, 0xa1fe, r16[ax]);
    push(cs);
    r16[ax] = 0xa0b1;
    push(r16[ax]);
    r16[ax] = 0x0024;
    push(r16[ax]);
    yield* sub_bf70();
    sp += 0x0006;
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_c01f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(ds);
        r8[ah] = 0x44;
        r8[al] = memory[ss*16 + bp + 6];
        r16[bx] = memory16get(ss, bp + 4);
        r16[cx] = memory16get(ss, bp + 12);
        r16[dx] = memory16get(ss, bp + 8);
        ds = memory16get(ss, bp + 8 + 2);
        interrupt(0x21);
        ds = pop();
        if (flags.carry) {
            pc = 0xc042;
            break;
        }
        if (memory16get(ss, bp + 6) != 0x0000) {
            pc = 0xc040;
            break;
        }
        r16[ax] = r16[dx];
        pc = 0xc046;
        break;
    case 0xc040:
        pc = 0xc046;
        break;
    case 0xc042:
        push(r16[ax]);
        yield* sub_c048();
    case 0xc046:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c048() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        si = memory16get(ss, bp + 4);
        if (signed16(si) < 0) {
            pc = 0xc068;
            break;
        }
        if (signed16(si) <= signed16(0x0058)) {
            pc = 0xc05b;
            break;
        }
    case 0xc058:
        si = 0x0057;
    case 0xc05b:
        memory16set(ds, 0x6b4e, si);
        r8[al] = memory[ds*16 + si + 27472];
        cbw();
        si = r16[ax];
        pc = 0xc079;
        break;
    case 0xc068:
        r16[ax] = si;
        r16[ax] = -r16[ax];
        si = r16[ax];
        if (signed16(si) > signed16(0x0023)) {
            pc = 0xc058;
            break;
        }
        memory16set(ds, 0x6b4e, 0xffff);
    case 0xc079:
        memory16set(ds, 0x007d, si);
        r16[ax] = 0xffff;
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        sp += 2;
        return;
    } while (1);
}
function* sub_c085() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[ax] = 0x4400;
    r16[bx] = memory16get(ss, bp + 4);
    interrupt(0x21);
    r16[tx] = r16[dx];
    r16[dx] = r16[ax];
    r16[ax] = r16[tx];
    r16[ax] &= 0x0080;
    bp = pop();
    assert(pop() == 0x7777);
}
function* sub_c096() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] <<= 1;
        memory16set(ds, r16[bx] + 27420, memory16get(ds, r16[bx] + 27420) & 0xfdff);
        r8[ah] = 0x42;
        r8[al] = memory[ss*16 + bp + 10];
        r16[bx] = memory16get(ss, bp + 4);
        r16[cx] = memory16get(ss, bp + 8);
        r16[dx] = memory16get(ss, bp + 6);
        interrupt(0x21);
        if (flags.carry) {
            pc = 0xc0b8;
            break;
        }
        pc = 0xc0bd;
        break;
    case 0xc0b8:
        push(r16[ax]);
        yield* sub_c048();
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
    case 0xc0bd:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c0bf() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(ds);
        r16[cx] = memory16get(ss, bp + 4);
        r8[ah] = 0x3c;
        r16[dx] = memory16get(ss, bp + 6);
        ds = memory16get(ss, bp + 6 + 2);
        interrupt(0x21);
        ds = pop();
        if (flags.carry) {
            pc = 0xc0d2;
            break;
        }
        pc = 0xc0d6;
        break;
    case 0xc0d2:
        push(r16[ax]);
        yield* sub_c048();
    case 0xc0d6:
        bp = pop();
        assert(pop() == 0x7777);
        sp += 6;
        return;
    } while (1);
}
function* sub_c0da() {
    push(0x7777);
    push(bp);
    bp = sp;
    r16[bx] = memory16get(ss, bp + 4);
    r16[cx] = 0;
    r16[dx] = 0;
    r8[ah] = 0x40;
    interrupt(0x21);
    bp = pop();
    assert(pop() == 0x7777);
    sp += 2;
}
function* sub_c0ec() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        push(si);
        push(di);
        si = memory16get(ss, bp + 8);
        if (si & 0xc000) {
            pc = 0xc109;
            break;
        }
        r16[ax] = memory16get(ds, 0x6b44);
        r16[ax] &= 0xc000;
        r16[dx] = si;
        r16[dx] |= r16[ax];
        si = r16[dx];
    case 0xc109:
        if (si & 0x0100) {
            pc = 0xc112;
            break;
        }
        pc = 0xc196;
        break;
    case 0xc112:
        r16[ax] = memory16get(ds, 0x6b46);
        memory16set(ss, bp + 10, memory16get(ss, bp + 10) & r16[ax]);
        r16[ax] = memory16get(ss, bp + 10);
        if (r16[ax] & 0x0180) {
            pc = 0xc127;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        yield* sub_c048();
    case 0xc127:
        r16[ax] = 0;
        push(r16[ax]);
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_be68();
        sp += 0x0006;
        memory16set(ss, bp - 2, r16[ax]);
        if (r16[ax] != 0xffff) {
            pc = 0xc16a;
            break;
        }
        if (!(memory16get(ss, bp + 10) & 0x0080)) {
            pc = 0xc149;
            break;
        }
        r16[ax] = 0;
        pc = 0xc14c;
        break;
    case 0xc149:
        r16[ax] = 0x0001;
    case 0xc14c:
        memory16set(ss, bp - 2, r16[ax]);
        if (!(si & 0x00f0)) {
            pc = 0xc181;
            break;
        }
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_c0bf();
        di = r16[ax];
        if (r16s[ax] >= 0) {
            pc = 0xc17a;
            break;
        }
        pc = 0xc228;
        break;
    case 0xc16a:
        if (!(si & 0x0400)) {
            pc = 0xc196;
            break;
        }
        r16[ax] = 0x0050;
        push(r16[ax]);
        yield* sub_c048();
        pc = 0xc22a;
        break;
    case 0xc17a:
        push(di);
        yield* sub_be85();
        r16[cx] = pop();
        pc = 0xc19b;
        break;
    case 0xc181:
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        push(memory16get(ss, bp - 2));
        yield* sub_c0bf();
        di = r16[ax];
        if (r16s[ax] >= 0) {
            pc = 0xc207;
            break;
        }
        pc = 0xc228;
        break;
    case 0xc196:
        memory16set(ss, bp - 2, 0x0000);
    case 0xc19b:
        push(si);
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_c230();
        sp += 0x0006;
        di = r16[ax];
        if (r16s[ax] < 0) {
            pc = 0xc207;
            break;
        }
        r16[ax] = 0;
        push(r16[ax]);
        push(di);
        yield* sub_c01f();
        r16[cx] = pop();
        r16[cx] = pop();
        memory16set(ss, bp - 4, r16[ax]);
        if (!(r16[ax] & 0x0080)) {
            pc = 0xc1e0;
            break;
        }
        si |= 0x2000;
        if (!(si & 0x8000)) {
            pc = 0xc1ea;
            break;
        }
        r16[ax] &= 0x00ff;
        r16[ax] |= 0x0020;
        r16[dx] = 0;
        push(r16[dx]);
        push(r16[ax]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(di);
        yield* sub_c01f();
        sp += 0x0008;
        pc = 0xc1ea;
        break;
    case 0xc1e0:
        if (!(si & 0x0200)) {
            pc = 0xc1ea;
            break;
        }
        push(di);
        yield* sub_c0da();
    case 0xc1ea:
        if (memory16get(ss, bp - 2) == 0x0000) {
            pc = 0xc207;
            break;
        }
        if (!(si & 0x00f0)) {
            pc = 0xc207;
            break;
        }
        r16[ax] = 0x0001;
        push(r16[ax]);
        push(r16[ax]);
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_be68();
        sp += 0x0008;
    case 0xc207:
        if (signed16(di) < 0) {
            pc = 0xc228;
            break;
        }
        if (!(si & 0x0300)) {
            pc = 0xc216;
            break;
        }
        r16[ax] = 0x1000;
        pc = 0xc218;
        break;
    case 0xc216:
        r16[ax] = 0;
    case 0xc218:
        r16[dx] = si;
        r16[dx] &= 0xf8ff;
        r16[dx] |= r16[ax];
        r16[bx] = di;
        r16[bx] <<= 1;
        memory16set(ds, r16[bx] + 27420, r16[dx]);
    case 0xc228:
        r16[ax] = di;
    case 0xc22a:
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c230() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp--;
        sp--;
        r8[al] = 0x01;
        r16[cx] = memory16get(ss, bp + 8);
        if (r16[cx] & 0x0002) {
            pc = 0xc24a;
            break;
        }
        r8[al] = 0x02;
        if (r16[cx] & 0x0004) {
            pc = 0xc24a;
            break;
        }
        r8[al] = 0x00;
    case 0xc24a:
        push(ds);
        r16[dx] = memory16get(ss, bp + 4);
        ds = memory16get(ss, bp + 4 + 2);
        r8[cl] = 0xf0;
        r8[cl] &= memory[ss*16 + bp + 8];
        r8[al] |= r8[cl];
        r8[ah] = 0x3d;
        interrupt(0x21);
        ds = pop();
        if (flags.carry) {
            pc = 0xc276;
            break;
        }
        memory16set(ss, bp - 2, r16[ax]);
        r16[bx] = memory16get(ss, bp - 2);
        r16[bx] <<= 1;
        r16[ax] = memory16get(ss, bp + 8);
        r16[ax] &= 0xf8ff;
        r16[ax] |= 0x8000;
        memory16set(ds, r16[bx] + 27420, r16[ax]);
        r16[ax] = memory16get(ss, bp - 2);
        pc = 0xc27a;
        break;
    case 0xc276:
        push(r16[ax]);
        yield* sub_c048();
    case 0xc27a:
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c27e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        sp -= 0x0004;
        push(si);
        push(di);
        r16[ax] = memory16get(ss, bp + 10);
        r16[ax]++;
        if (r16[ax] < 0x0002) {
            pc = 0xc29c;
            break;
        }
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] <<= 1;
        if (!(memory16get(ds, r16[bx] + 27420) & 0x0200)) {
            pc = 0xc2a1;
            break;
        }
    case 0xc29c:
        r16[ax] = 0;
        pc = 0xc330;
        break;
    case 0xc2a1:
        push(memory16get(ss, bp + 10));
        push(memory16get(ss, bp + 8));
        push(memory16get(ss, bp + 6));
        push(memory16get(ss, bp + 4));
        yield* sub_c336();
        sp += 0x0008;
        memory16set(ss, bp - 2, r16[ax]);
        r16[ax]++;
        if (r16[ax] < 0x0002) {
            pc = 0xc2c9;
            break;
        }
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] <<= 1;
        if (!(memory16get(ds, r16[bx] + 27420) & 0x8000)) {
            pc = 0xc2ce;
            break;
        }
    case 0xc2c9:
        r16[ax] = memory16get(ss, bp - 2);
        pc = 0xc330;
        break;
    case 0xc2ce:
        r16[cx] = memory16get(ss, bp - 2);
        si = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        di = si;
        r16[bx] = si;
        flags.direction = false;
    case 0xc2d9:
        lodsb_es_data_forward();
        if (r8[al] == 0x1a) {
            pc = 0xc30d;
            break;
        }
        if (r8[al] == 0x0d) {
            pc = 0xc2e8;
            break;
        }
        stosb_data_forward();
        if (--r16[cx]) {
            pc = 0xc2d9;
            break;
        }
        pc = 0xc305;
        break;
    case 0xc2e8:
        if (--r16[cx]) {
            pc = 0xc2d9;
            break;
        }
        push(es);
        push(r16[bx]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        r16[ax] = bp - 0x3;
        push(ss);
        push(r16[ax]);
        push(memory16get(ss, bp + 4));
        yield* sub_c336();
        sp += 0x0008;
        r16[bx] = pop();
        es = pop();
        flags.direction = false;
        r8[al] = memory[ss*16 + bp - 3];
        stosb_data_forward();
    case 0xc305:
        if (di != r16[bx]) {
            pc = 0xc30b;
            break;
        }
        pc = 0xc2a1;
        break;
    case 0xc30b:
        pc = 0xc32d;
        break;
    case 0xc30d:
        push(r16[bx]);
        r16[ax] = 0x0001;
        push(r16[ax]);
        stop(/*74*/);
        r16[cx] = -r16[cx];
        r16[ax] -= r16[ax] + flags.carry;
        push(r16[ax]);
        push(r16[cx]);
        push(memory16get(ss, bp + 4));
        yield* sub_c096();
        sp += 0x0008;
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] <<= 1;
        memory16set(ds, r16[bx] + 27420, memory16get(ds, r16[bx] + 27420) | 0x0200);
        r16[bx] = pop();
    case 0xc32d:
        di -= r16[bx];
        r16[tx] = di;
        di = r16[ax];
        r16[ax] = r16[tx];
    case 0xc330:
        di = pop();
        si = pop();
        sp = bp;
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c336() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(ds);
        r8[ah] = 0x3f;
        r16[bx] = memory16get(ss, bp + 4);
        r16[cx] = memory16get(ss, bp + 10);
        r16[dx] = memory16get(ss, bp + 6);
        ds = memory16get(ss, bp + 6 + 2);
        interrupt(0x21);
        ds = pop();
        if (flags.carry) {
            pc = 0xc34c;
            break;
        }
        pc = 0xc350;
        break;
    case 0xc34c:
        push(r16[ax]);
        yield* sub_c048();
    case 0xc350:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c352() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r8[ah] = 0x4a;
        r16[bx] = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 4);
        interrupt(0x21);
        if (flags.carry) {
            pc = 0xc366;
            break;
        }
        r16[ax] = 0xffff;
        pc = 0xc36c;
        break;
    case 0xc366:
        push(r16[bx]);
        push(r16[ax]);
        yield* sub_c048();
        r16[ax] = pop();
    case 0xc36c:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c36e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] <<= 1;
        if (!(memory16get(ds, r16[bx] + 27420) & 0x0800)) {
            pc = 0xc391;
            break;
        }
        r16[ax] = 0x0002;
        push(r16[ax]);
        r16[ax] = 0;
        r16[dx] = 0;
        push(r16[ax]);
        push(r16[dx]);
        push(memory16get(ss, bp + 4));
        yield* sub_c096();
        sp += 0x0008;
    case 0xc391:
        push(ds);
        r8[ah] = 0x40;
        r16[bx] = memory16get(ss, bp + 4);
        r16[cx] = memory16get(ss, bp + 10);
        r16[dx] = memory16get(ss, bp + 6);
        ds = memory16get(ss, bp + 6 + 2);
        interrupt(0x21);
        ds = pop();
        if (flags.carry) {
            pc = 0xc3b1;
            break;
        }
        push(r16[ax]);
        r16[bx] = memory16get(ss, bp + 4);
        r16[bx] <<= 1;
        memory16set(ds, r16[bx] + 27420, memory16get(ds, r16[bx] + 27420) | 0x1000);
        r16[ax] = pop();
        pc = 0xc3b5;
        break;
    case 0xc3b1:
        push(r16[ax]);
        yield* sub_c048();
    case 0xc3b5:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c3cc() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (r16[dx] == memory16get(cs, 0xa4f0)) {
            pc = 0xc40a;
            break;
        }
        ds = r16[dx];
        ds = memory16get(ds, 0x0002);
        if (memory16get(ds, 0x0002) == 0x0000) {
            pc = 0xc3e7;
            break;
        }
        memory16set(cs, 0xa4f2, ds);
        pc = 0xc41f;
        break;
    case 0xc3e7:
        r16[ax] = ds;
        if (r16[ax] == memory16get(cs, 0xa4f0)) {
            pc = 0xc405;
            break;
        }
        r16[ax] = memory16get(ds, 0x0008);
        memory16set(cs, 0xa4f2, r16[ax]);
        push(ds);
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_c49f();
        ds = memory16get(cs, 0xa4f6);
        pc = 0xc428;
        break;
    case 0xc405:
        r16[dx] = memory16get(cs, 0xa4f0);
    case 0xc40a:
        memory16set(cs, 0xa4f0, 0x0000);
        memory16set(cs, 0xa4f2, 0x0000);
        memory16set(cs, 0xa4f4, 0x0000);
    case 0xc41f:
        ds = memory16get(cs, 0xa4f6);
        push(r16[dx]);
        r16[ax] = 0;
        push(r16[ax]);
    case 0xc428:
        yield* sub_b82b();
        r16[ax] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_c42e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        ds = r16[dx];
        push(ds);
        es = memory16get(ds, 0x0002);
        memory16set(ds, 0x0002, 0x0000);
        memory16set(ds, 0x0008, es);
        if (r16[dx] == memory16get(cs, 0xa4f0)) {
            pc = 0xc474;
            break;
        }
        if (memory16get(es, 0x0002) != 0x0000) {
            pc = 0xc474;
            break;
        }
        r16[ax] = memory16get(ds, 0x0000);
        r16[bx] = pop();
        push(es);
        memory16set(es, 0x0000, memory16get(es, 0x0000) + r16[ax]);
        r16[cx] = es;
        r16[dx] += r16[ax];
        es = r16[dx];
        if (memory16get(es, 0x0002) != 0x0000) {
            pc = 0xc46d;
            break;
        }
        memory16set(es, 0x0008, r16[cx]);
        pc = 0xc477;
        break;
    case 0xc46d:
        memory16set(es, 0x0002, r16[cx]);
        pc = 0xc477;
        break;
    case 0xc474:
        yield* sub_c4c8();
    case 0xc477:
        es = pop();
        r16[ax] = es;
        r16[ax] += memory16get(es, 0x0000);
        ds = r16[ax];
        if (memory16get(ds, 0x0002) == 0x0000) {
            pc = 0xc489;
            break;
        }
        return;
    case 0xc489:
        r16[ax] = memory16get(ds, 0x0000);
        memory16set(es, 0x0000, memory16get(es, 0x0000) + r16[ax]);
        r16[ax] = es;
        r16[bx] = ds;
        r16[bx] += memory16get(ds, 0x0000);
        es = r16[bx];
        memory16set(es, 0x0002, r16[ax]);
        r16[bx] = ds;
        if (r16[bx] == memory16get(ds, 0x0006)) {
            pc = 0xc4c0;
            break;
        }
        es = memory16get(ds, 0x0006);
        ds = memory16get(ds, 0x0004);
        memory16set(ds, 0x0006, es);
        memory16set(es, 0x0004, ds);
        memory16set(cs, 0xa4f4, ds);
        ds = r16[bx];
        return;
    case 0xc4c0:
        memory16set(cs, 0xa4f4, 0x0000);
        return;
    } while (1);
}
function* sub_c49f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = ds;
        if (r16[bx] == memory16get(ds, 0x0006)) {
            pc = 0xc4c0;
            break;
        }
        es = memory16get(ds, 0x0006);
        ds = memory16get(ds, 0x0004);
        memory16set(ds, 0x0006, es);
        memory16set(es, 0x0004, ds);
        memory16set(cs, 0xa4f4, ds);
        ds = r16[bx];
        return;
    case 0xc4c0:
        memory16set(cs, 0xa4f4, 0x0000);
        return;
    } while (1);
}
function* sub_c4c8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(cs, 0xa4f4);
        if (!r16[ax]) {
            pc = 0xc4f0;
            break;
        }
        r16[bx] = ss;
        flags.interrupts = false;
        ss = r16[ax];
        es = memory16get(ss, 0x0006);
        memory16set(ss, 0x0006, ds);
        memory16set(ds, 0x0004, ss);
        ss = r16[bx];
        flags.interrupts = true;
        memory16set(es, 0x0004, ds);
        memory16set(ds, 0x0006, es);
        return;
    case 0xc4f0:
        memory16set(cs, 0xa4f4, ds);
        memory16set(ds, 0x0004, ds);
        memory16set(ds, 0x0006, ds);
        return;
    } while (1);
}
function* sub_c4fe() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        push(si);
        push(di);
        memory16set(cs, 0xa4f6, ds);
        r16[dx] = memory16get(ss, bp + 6);
        if (!r16[dx]) {
            pc = 0xc51e;
            break;
        }
        if (r16[dx] != memory16get(cs, 0xa4f2)) {
            pc = 0xc51b;
            break;
        }
        yield* sub_c3cc();
        pc = 0xc51e;
        break;
    case 0xc51b:
        yield* sub_c42e();
    case 0xc51e:
        ds = memory16get(cs, 0xa4f6);
        di = pop();
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c527() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        ds = memory16get(cs, 0xa4f6);
        r16[ax] = 0;
        push(r16[ax]);
        push(r16[ax]);
        yield* sub_b86a();
        r16[bx] = pop();
        r16[bx] = pop();
        r16[ax] &= 0x000f;
        if (r16[ax] == 0) {
            pc = 0xc54e;
            break;
        }
        r16[dx] = 0x0010;
        r16[dx] -= r16[ax];
        r16[ax] = 0;
        ds = memory16get(cs, 0xa4f6);
        push(r16[ax]);
        push(r16[dx]);
        yield* sub_b86a();
        r16[bx] = pop();
        r16[bx] = pop();
    case 0xc54e:
        r16[ax] = pop();
        push(r16[ax]);
        r16[bx] = 0;
        r8[bl] = r8[ah];
        r8[cl] = 0x04;
        r16[bx] >>= r8[cl];
        r16[ax] <<= r8[cl];
        ds = memory16get(cs, 0xa4f6);
        push(r16[bx]);
        push(r16[ax]);
        yield* sub_b86a();
        r16[bx] = pop();
        r16[bx] = pop();
        r16[bx] = pop();
        if (r16[ax] == 0xffff) {
            pc = 0xc584;
            break;
        }
        memory16set(cs, 0xa4f0, r16[dx]);
        memory16set(cs, 0xa4f2, r16[dx]);
        ds = r16[dx];
        memory16set(ds, 0x0000, r16[bx]);
        memory16set(ds, 0x0002, r16[dx]);
        r16[ax] = 0x0004;
        return;
    case 0xc584:
        r16[ax] = 0;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        return;
    } while (1);
}
function* sub_c588() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        r16[bx] = 0;
        r8[bl] = r8[ah];
        r8[cl] = 0x04;
        r16[bx] >>= r8[cl];
        r16[ax] <<= r8[cl];
        ds = memory16get(cs, 0xa4f6);
        push(r16[bx]);
        push(r16[ax]);
        yield* sub_b86a();
        r16[bx] = pop();
        r16[bx] = pop();
        r16[bx] = pop();
        if (r16[ax] == 0xffff) {
            pc = 0xc5bd;
            break;
        }
        r16[cx] = memory16get(cs, 0xa4f2);
        memory16set(cs, 0xa4f2, r16[dx]);
        ds = r16[dx];
        memory16set(ds, 0x0000, r16[bx]);
        memory16set(ds, 0x0002, r16[cx]);
        r16[ax] = 0x0004;
        return;
    case 0xc5bd:
        r16[ax] = 0;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        return;
    } while (1);
}
function* sub_c5c1() {
    r16[bx] = r16[dx];
    memory16set(ds, 0x0000, memory16get(ds, 0x0000) - r16[ax]);
    r16[dx] += memory16get(ds, 0x0000);
    ds = r16[dx];
    memory16set(ds, 0x0000, r16[ax]);
    memory16set(ds, 0x0002, r16[bx]);
    r16[bx] = r16[dx];
    r16[bx] += memory16get(ds, 0x0000);
    ds = r16[bx];
    memory16set(ds, 0x0002, r16[dx]);
    r16[ax] = 0x0004;
}
function* sub_c5e4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        push(bp);
        bp = sp;
        r16[dx] = 0;
        r16[ax] = memory16get(ss, bp + 4);
        pc = 0xc5f7;
        break;
    case 0xc5f7:
        push(si);
        push(di);
        memory16set(cs, 0xa4f6, ds);
        r16[cx] = r16[ax];
        r16[cx] |= r16[dx];
        if (!r16[cx]) {
            pc = 0xc662;
            break;
        }
        flags.carry = (r16[ax] + 0x0013) >= 0x10000;
        r16[ax] += 0x0013;
        r8[tl] = flags.carry;
        flags.carry = (r16[dx] + 0x0000 + r8[tl]) >= 0x10000;
        r16[dx] += r8[tl];
        if (flags.carry) {
            pc = 0xc64d;
            break;
        }
        if (r16[dx] & 0xfff0) {
            pc = 0xc64d;
            break;
        }
        r8[cl] = 0x04;
        r16[ax] >>= r8[cl];
        r16[dx] <<= r8[cl];
        r8[ah] |= r8[dl];
        r16[dx] = memory16get(cs, 0xa4f0);
        if (!r16[dx]) {
            pc = 0xc643;
            break;
        }
        r16[dx] = memory16get(cs, 0xa4f4);
        if (!r16[dx]) {
            pc = 0xc63e;
            break;
        }
        r16[bx] = r16[dx];
    case 0xc62e:
        ds = r16[dx];
        if (memory16get(ds, 0x0000) >= r16[ax]) {
            pc = 0xc652;
            break;
        }
        r16[dx] = memory16get(ds, 0x0006);
        if (r16[dx] != r16[bx]) {
            pc = 0xc62e;
            break;
        }
    case 0xc63e:
        yield* sub_c588();
        pc = 0xc662;
        break;
    case 0xc643:
        yield* sub_c527();
        pc = 0xc662;
        break;
    case 0xc648:
        yield* sub_c5c1();
        pc = 0xc662;
        break;
    case 0xc64d:
        r16[ax] = 0;
        r16[dx] = r16[ax] & 0x8000 ? 0xffff : 0x0000;
        pc = 0xc662;
        break;
    case 0xc652:
        if (memory16get(ds, 0x0000) > r16[ax]) {
            pc = 0xc648;
            break;
        }
        yield* sub_c49f();
        r16[bx] = memory16get(ds, 0x0008);
        memory16set(ds, 0x0002, r16[bx]);
        r16[ax] = 0x0004;
    case 0xc662:
        ds = memory16get(cs, 0xa4f6);
        di = pop();
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        return;
    } while (1);
}
function* sub_c7be() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        r16[cx] = pop();
        push(cs);
        push(r16[cx]);
        r16[cx] = 0x0001;
        pc = 0xc7d4;
        break;
    case 0xc7d4:
        push(bp);
        push(si);
        push(di);
        bp = sp;
        di = r16[cx];
        r16[ax] = memory16get(ss, bp + 10);
        r16[dx] = memory16get(ss, bp + 12);
        r16[bx] = memory16get(ss, bp + 14);
        r16[cx] = memory16get(ss, bp + 16);
        if (r16[cx]) {
            pc = 0xc7f3;
            break;
        }
        if (!r16[dx]) {
            pc = 0xc858;
            break;
        }
        if (!r16[bx]) {
            pc = 0xc858;
            break;
        }
    case 0xc7f3:
        if (di & 0x0001) {
            pc = 0xc815;
            break;
        }
        if (!(r16[dx] & 0x8000)) {
            pc = 0xc807;
            break;
        }
        r16[dx] = -r16[dx];
        stop(/*74*/);
        r16[ax] = -r16[ax];
        r16[dx] -= flags.carry;
        di |= 0x000c;
    case 0xc807:
        if (!(r16[cx] & 0x8000)) {
            pc = 0xc815;
            break;
        }
        r16[cx] = -r16[cx];
        stop(/*74*/);
        r16[bx] = -r16[bx];
        r16[cx] -= flags.carry;
        di ^= 0x0004;
    case 0xc815:
        bp = r16[cx];
        r16[cx] = 0x0020;
        push(di);
        di = 0;
        si = 0;
    case 0xc81f:
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        r16[dx] = rcl16(r16[dx], 0x0001);
        si = rcl16(si, 0x0001);
        di = rcl16(di, 0x0001);
        if (di < bp) {
            pc = 0xc836;
            break;
        }
        if (di > bp) {
            pc = 0xc831;
            break;
        }
        if (si < r16[bx]) {
            pc = 0xc836;
            break;
        }
    case 0xc831:
        flags.carry = si < r16[bx];
        si -= r16[bx];
        di -= bp + flags.carry;
        r16[ax]++;
    case 0xc836:
        if (--r16[cx]) {
            pc = 0xc81f;
            break;
        }
        r16[bx] = pop();
        if (!(r16[bx] & 0x0002)) {
            pc = 0xc845;
            break;
        }
        r16[ax] = si;
        r16[dx] = di;
        r16[bx] >>= 1;
    case 0xc845:
        if (!(r16[bx] & 0x0004)) {
            pc = 0xc852;
            break;
        }
        r16[dx] = -r16[dx];
        stop(/*74*/);
        r16[ax] = -r16[ax];
        r16[dx] -= flags.carry;
    case 0xc852:
        di = pop();
        si = pop();
        bp = pop();
        assert(pop() == 0x7777);
        cs = pop();
        sp += 8;
        return;
    case 0xc858:
        div16(r16[bx]);
        if (!(di & 0x0002)) {
            pc = 0xc861;
            break;
        }
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
    case 0xc861:
        r16[dx] = 0;
        pc = 0xc852;
        break;
        return;
    } while (1);
}
function* sub_c865() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        es = pop();
        push(cs);
        push(es);
        if (r16s[cx] >= 0) {
            pc = 0xc878;
            break;
        }
        r16[bx] = ~bx;
        r16[cx] = ~cx;
        flags.carry = (r16[bx] + 0x0001) >= 0x10000;
        r16[bx] += 0x0001;
        r16[cx] += flags.carry;
        pc = 0xc8a7;
        break;
    case 0xc878:
        flags.carry = (r16[ax] + r16[bx]) >= 0x10000;
        r16[ax] += r16[bx];
        if (!flags.carry) {
            pc = 0xc880;
            break;
        }
        r16[dx] += 0x1000;
    case 0xc880:
        r8[ch] = r8[cl];
        r8[cl] = 0x04;
        r8[ch] <<= r8[cl];
        r8[dh] += r8[ch];
        r8[ch] = r8[al];
        r16[ax] >>= r8[cl];
        r16[dx] += r16[ax];
        r8[al] = r8[ch];
        r16[ax] &= 0x000f;
        es = 0x99b0; pop(); pop();
        return;
    case 0xc8a7:
        flags.carry = r16[ax] < r16[bx];
        r16[ax] -= r16[bx];
        if (!flags.carry) {
            pc = 0xc8af;
            break;
        }
        r16[dx] -= 0x1000;
    case 0xc8af:
        r8[bh] = r8[cl];
        r8[cl] = 0x04;
        r8[bh] <<= r8[cl];
        r8[bl] = 0;
        r16[dx] -= r16[bx];
        r8[ch] = r8[al];
        r16[ax] >>= r8[cl];
        r16[dx] += r16[ax];
        r8[al] = r8[ch];
        r16[ax] &= 0x000f;
        return;
    } while (1);
}
function* sub_c8c5() {
    push(0x7777);
    es = pop();
    push(cs);
    push(es);
    push(bp);
    bp = sp;
    push(si);
    push(di);
    push(ds);
    si = memory16get(ss, bp + 6);
    ds = memory16get(ss, bp + 6 + 2);
    di = memory16get(ss, bp + 10);
    es = memory16get(ss, bp + 10 + 2);
    flags.direction = false;
    flags.carry = r16[cx] & 1;
    r16[cx] >>= 1;
    rep_movsw_data_data_forward();
    r16[cx] += r16[cx] + flags.carry;
    rep_movsb_data_data_forward();
    ds = pop();
    di = pop();
    si = pop();
    bp = pop();
    assert(pop() == 0x7777);
    sp += 8;
}
function* sub_c8e4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        r16[tx] = si;
        si = r16[ax];
        r16[ax] = r16[tx];
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
        if (!r16[ax]) {
            pc = 0xc8ed;
            break;
        }
        mul16(r16[bx]);
    case 0xc8ed:
        if (r16[cx] == 0) {
            pc = 0xc8f4;
            break;
        }
        r16[tx] = r16[cx];
        r16[cx] = r16[ax];
        r16[ax] = r16[tx];
        mul16(si);
        r16[ax] += r16[cx];
    case 0xc8f4:
        r16[tx] = si;
        si = r16[ax];
        r16[ax] = r16[tx];
        mul16(r16[bx]);
        r16[dx] += si;
        si = pop();
        return;
    } while (1);
}
function* sub_c8fb() {
    push(r16[cx]);
    r8[ch] = r8[al];
    r8[cl] = 0x04;
    r16[ax] >>= r8[cl];
    r16[dx] += r16[ax];
    r8[al] = r8[ch];
    r8[ah] = r8[bl];
    r16[bx] >>= r8[cl];
    r16[cx] = pop();
    r16[cx] += r16[bx];
    r8[bl] = r8[ah];
    r16[ax] &= 0x000f;
    r16[bx] &= 0x000f;
    flags.carry = r16[dx] < r16[cx];
    flags.zero = r16[dx] == r16[cx];
    if (r16[dx] != r16[cx])
        return;
    flags.carry = r16[ax] < r16[bx];
    flags.zero = r16[ax] == r16[bx];
}
function* sub_c91e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        pc = 0xc91e;
        break;
    case 0x20ba:
        r16[cx] = 0x001e;
        r16[dx] = 0x003b;
        ds = memory16get(cs, 0x01ff);
        yield* sub_20b2();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_1fe5();
        memory[ds*16 + r16[bx] + si] += r8[al];
        r16[ax] += memory16get(ds, r16[bx] + si + 85);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x20df;
            break;
        }
        yield* sub_ca53();
    case 0x20df:
        if (memory[ss*16 + bp + 4] != 0x01) {
            pc = 0x2126;
            break;
        }
        yield* sub_22e6();
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x2126;
            break;
        }
        r16[bx] = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        r16[ax] = memory16get(es, r16[bx] + 6);
        r16[dx] = memory16get(es, r16[bx] + 4);
        memory16set(ds, 0x6be4, r16[dx]);
        memory16set(ds, 0x6be6, r16[ax]);
        yield* sub_2152();
        yield* sub_9a77();
        yield* sub_28d7();
        yield* sub_2128();
        yield* sub_2439();
        yield* sub_9947();
        yield* sub_9c89();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_8ff0();
        sp++;
        sp++;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b78a();
        sp++;
        sp++;
    case 0x2126:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    case 0xc91e:
        memory16set(ds, 0x6bb0, pop());
        memory16set(ds, 0x6bb2, pop());
        memory16set(ds, 0x6bb4, pop());
        memory16set(cs, 0xaa4c, ds);
        memory16set(ds, 0x6bb6, si);
        memory16set(ds, 0x6bb8, di);
        flags.direction = false;
        es = memory16get(ds, 0x0079);
        si = 0x0080;
        r8[ah] = 0;
        lodsb_es_MemPsp_forward();
        r16[ax]++;
        bp = es;
        r16[tx] = si;
        si = r16[dx];
        r16[dx] = r16[tx];
        r16[tx] = r16[bx];
        r16[bx] = r16[ax];
        r16[ax] = r16[tx];
        si = memory16get(ds, 0x0073);
        si++;
        si++;
        r16[cx] = 0x0001;
        if (memory[ds*16 + 0x007b] < 0x03) {
            pc = 0xc96a;
            break;
        }
        es = memory16get(ds, 0x0075);
        di = si;
        r8[cl] = 0x7f;
        r8[al] = 0;
        repne_scasb_MemPsp_forward(r8[al]);
        if (r16[cx] == 0) {
            pc = 0xc9d5;
            break;
        }
        r8[cl] ^= 0x7f;
    case 0xc96a:
        push(r16[ax]);
        r16[ax] = r16[cx];
        r16[ax] += r16[bx];
        r16[ax]++;
        r16[ax] &= 0xfffe;
        di = sp;
        r16[tx] = di;
        di -= r16[ax];
        if (r16[tx] < r16[ax]) {
            pc = 0xc9d5;
            break;
        }
        sp = di;
        push(es);
        ds = pop();
        push(ss);
        es = pop();
        push(r16[cx]);
        r16[cx]--;
        rep_movsb_data_MemPsp_forward();
        r8[al] = 0;
        stosb_data_forward();
        ds = bp;
        r16[tx] = r16[dx];
        r16[dx] = si;
        si = r16[tx];
        r16[tx] = r16[cx];
        r16[cx] = r16[bx];
        r16[bx] = r16[tx];
        r16[ax] = r16[bx];
        r16[dx] = r16[ax];
        r16[bx]++;
    case 0xc991:
        yield* sub_c9ad();
        if (!flags.zero && !flags.carry) {
            pc = 0xc99d;
            break;
        }
    case 0xc996:
        if (flags.carry) {
            pc = 0xc9d8;
            break;
        }
        yield* sub_c9ad();
        if (!flags.zero && !flags.carry) {
            pc = 0xc996;
            break;
        }
    case 0xc99d:
        if (r8[al] == 0x20) {
            pc = 0xc9a9;
            break;
        }
        if (r8[al] == 0x0d) {
            pc = 0xc9a9;
            break;
        }
        if (r8[al] != 0x09) {
            pc = 0xc991;
            break;
        }
    case 0xc9a9:
        r8[al] = 0;
        pc = 0xc991;
        break;
    case 0xc9d5:
        pc = 0x20ba;
        break;
    case 0xc9d8:
        r16[cx] = pop();
        r16[cx] += r16[dx];
        ds = memory16get(cs, 0xaa4c);
        memory16set(ds, 0x6baa, r16[bx]);
        r16[bx]++;
        r16[bx] += r16[bx];
        r16[bx] += r16[bx];
        si = sp;
        bp = sp;
        r16[tx] = bp;
        bp -= r16[bx];
        if (r16[tx] < r16[bx]) {
            pc = 0xc9d5;
            break;
        }
        sp = bp;
        memory16set(ds, 0x6bac, bp);
        memory16set(ds, 0x6bae, ss);
    case 0xc9fb:
        if (r16[cx] == 0) {
            pc = 0xca0e;
            break;
        }
        memory16set(ss, bp, si);
        memory16set(ss, bp + 2, ss);
        bp += 0x0004;
    case 0xca06:
        lodsb_ss_data_forward();
        if (--r16[cx] && r8[al]) {
            pc = 0xca06;
            break;
        }
        if (!r8[al]) {
            pc = 0xc9fb;
            break;
        }
    case 0xca0e:
        r16[ax] = 0;
        memory16set(ss, bp, r16[ax]);
        memory16set(ss, bp + 2, r16[ax]);
        ds = memory16get(cs, 0xaa4c);
        si = memory16get(ds, 0x6bb6);
        di = memory16get(ds, 0x6bb8);
        push(memory16get(ds, 0x6bb4));
        push(memory16get(ds, 0x6bb2));
        r16[ax] = memory16get(ds, 0x6baa);
        memory16set(ds, 0x0069, r16[ax]);
        r16[ax] = memory16get(ds, 0x6bae);
        memory16set(ds, 0x006d, r16[ax]);
        r16[ax] = memory16get(ds, 0x6bac);
        memory16set(ds, 0x006b, r16[ax]);
        return;
    } while (1);
}
function* sub_c9ad() {
    var pc = 0;
    do switch (pc) {
    case 0:
        if (!r16[ax]) {
            pc = 0xc9b8;
            break;
        }
        r16[dx]++;
        stosb_data_forward();
        if (r8[al]) {
            pc = 0xc9b8;
            break;
        }
        r16[bx]++;
    case 0xc9b8:
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        r8[al] = 0;
        flags.carry = true;
        if (r16[cx] == 0)
            {
            flags.zero = true;
            pc = 0xc9d4;
            break;
        }
        lodsb_MemPsp_forward();
        r16[cx]--;
        r8[al] -= 0x22;
        if (r8[al] == 0)
            {
            flags.zero = true;
            pc = 0xc9d4;
            break;
        }
        r8[al] += 0x22;
        if (r8[al] != 0x5c)
            {
            flags.zero = false;
            pc = 0xc9d2;
            break;
        }
        if (memory[ds*16 + si] != 0x22)
            {
            flags.zero = false;
            pc = 0xc9d2;
            break;
        }
        lodsb_data_forward();
        r16[cx]--;
        flags.zero = r16[cx] == 0;
    case 0xc9d2:
        flags.carry = false;
    case 0xc9d4:
        return;
    } while (1);
}
function* sub_ca53() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(0x7777);
        pc = 0xca53;
        break;
    case 0x1fe5:
        ds = memory16get(cs, 0x01ff);
        yield* sub_2042();
        bp = sp;
        r8[ah] = 0x4c;
        r8[al] = memory[ss*16 + bp + 2];
        interrupt(0x21);
        r16[cx] = 0x000e;
        r16[dx] = 0x002d;
        pc = 0x20c0;
        break;
    case 0x20c0:
        ds = memory16get(cs, 0x01ff);
        yield* sub_20b2();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_1fe5();
        memory[ds*16 + r16[bx] + si] += r8[al];
        r16[ax] += memory16get(ds, r16[bx] + si + 85);
        bp = sp;
        if (memory16get(ds, 0x6b4c) > sp) {
            pc = 0x20df;
            break;
        }
        yield* sub_ca53();
    case 0x20df:
        if (memory[ss*16 + bp + 4] != 0x01) {
            pc = 0x2126;
            break;
        }
        yield* sub_22e6();
        r8[ah] = 0x00;
        if (r16[ax]) {
            pc = 0x2126;
            break;
        }
        r16[bx] = memory16get(ss, bp + 6);
        es = memory16get(ss, bp + 6 + 2);
        r16[ax] = memory16get(es, r16[bx] + 6);
        r16[dx] = memory16get(es, r16[bx] + 4);
        memory16set(ds, 0x6be4, r16[dx]);
        memory16set(ds, 0x6be6, r16[ax]);
        yield* sub_2152();
        yield* sub_9a77();
        yield* sub_28d7();
        yield* sub_2128();
        yield* sub_2439();
        yield* sub_9947();
        yield* sub_9c89();
        r16[ax] = 0x0003;
        push(r16[ax]);
        yield* sub_8ff0();
        sp++;
        sp++;
        r16[ax] = 0;
        push(r16[ax]);
        yield* sub_b78a();
        sp++;
        sp++;
    case 0x2126:
        bp = pop();
        assert(pop() == 0x7777);
        return;
    case 0xca53:
        push(cs);
        ds = pop();
        r16[dx] = 0xab71;
        r8[ah] = 0x09;
        interrupt(0x21);
        pc = 0x1fe5;
        break;
        return;
    } while (1);
}
function* sub_ca60() {
    si = 0x4de6;
    yield* sub_d0ad();
    r16[cx] = 0x0002;
    yield* sub_ce87();
    r16[bx] = memory16get(es, di + 28);
    push(r16[bx]);
    r16[bx] = di;
    push(es);
    yield* sub_cf8d();
    ds = pop();
    si = r16[bx];
    r16[bx] = pop();
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 19916);
    ds = pop();
    yield* callIndirect(cs, r16[ax]);
}
function* sub_ca61() {
    out8(0x4d, r8[al]);
    yield* sub_d0ad();
    r16[cx] = 0x0002;
    yield* sub_ce87();
    r16[bx] = memory16get(es, di + 28);
    push(r16[bx]);
    r16[bx] = di;
    push(es);
    yield* sub_cf8d();
    ds = pop();
    si = r16[bx];
    r16[bx] = pop();
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 19916);
    ds = pop();
    yield* callIndirect(cs, r16[ax]);
}
function* sub_ca62() {
    bp--;
    yield* sub_d0ad();
    r16[cx] = 0x0002;
    yield* sub_ce87();
    r16[bx] = memory16get(es, di + 28);
    push(r16[bx]);
    r16[bx] = di;
    push(es);
    yield* sub_cf8d();
    ds = pop();
    si = r16[bx];
    r16[bx] = pop();
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 19916);
    ds = pop();
    yield* callIndirect(cs, r16[ax]);
}
function* sub_ca63() {
    yield* sub_d0ad();
    r16[cx] = 0x0002;
    yield* sub_ce87();
    r16[bx] = memory16get(es, di + 28);
    push(r16[bx]);
    r16[bx] = di;
    push(es);
    yield* sub_cf8d();
    ds = pop();
    si = r16[bx];
    r16[bx] = pop();
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 19916);
    ds = pop();
    yield* callIndirect(cs, r16[ax]);
}
function* sub_ca8b() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0101;
    case 0xca8e:
        r16[dx] = 0x03c4;
        r8[ah] = r8[bh];
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        yield* sub_d02f();
        yield* sub_caa7();
        r8[bl]++;
        r8[bh] <<= 1;
        if (r8s[bh] > signed8(0x08))
            return;
        pc = 0xca8e;
        break;
        return;
    } while (1);
}
function* sub_caa7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(ds);
        bp = 0x1228;
        ds = bp;
        bp = memory16get(ds, 0x5429);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
    case 0xcabd:
        if (r8[dl] == r8[ch]) {
            pc = 0xcacf;
            break;
        }
        r8[dl]--;
        r16[cx] >>= 1;
        rep_stosw_video_forward();
        r8[cl] = r8[dh];
        di -= r16[cx];
        di += bp;
        pc = 0xcabd;
        break;
    case 0xcacf:
        di = pop();
        return;
    } while (1);
}
function* sub_cad2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0101;
    case 0xcad5:
        r16[dx] = 0x03c4;
        r8[ah] = r8[bh];
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        yield* sub_d02f();
        pc = 0xcaed;
        break;
    case 0xcae2:
        r8[bl]++;
        r8[bh] <<= 1;
        if (r8s[bh] > signed8(0x08))
            return;
        pc = 0xcad5;
        break;
    case 0xcaed:
        push(di);
        push(ds);
        bp = 0x1228;
        ds = bp;
        bp = memory16get(ds, 0x5429);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
        si = r16[ax];
        si = ~si;
    case 0xcb07:
        if (r8[dl] == r8[ch]) {
            pc = 0xcb22;
            break;
        }
        r8[dl]--;
        r16[cx] >>= 1;
    case 0xcb0f:
        memory16set(es, di, memory16get(es, di) & si);
        memory16set(es, di, memory16get(es, di) | r16[ax]);
        di += 0x0002;
        if (--r16[cx]) {
            pc = 0xcb0f;
            break;
        }
        r8[cl] = r8[dh];
        di -= r16[cx];
        di += bp;
        pc = 0xcb07;
        break;
    case 0xcb22:
        di = pop();
        pc = 0xcae2;
        break;
        return;
    } while (1);
}
function* sub_cb26() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = 0x0101;
    case 0xcb29:
        r16[dx] = 0x03c4;
        r8[ah] = r8[bh];
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        yield* sub_d02f();
        r16[ax] = ~ax;
        yield* sub_cb44();
        r8[bl]++;
        r8[bh] <<= 1;
        if (r8s[bh] > signed8(0x08))
            return;
        pc = 0xcb29;
        break;
        return;
    } while (1);
}
function* sub_cb44() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(ds);
        bp = 0x1228;
        ds = bp;
        bp = memory16get(ds, 0x5429);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
    case 0xcb5a:
        if (r8[dl] == r8[ch]) {
            pc = 0xcb72;
            break;
        }
        r8[dl]--;
        r16[cx] >>= 1;
    case 0xcb62:
        memory16set(es, di, memory16get(es, di) & r16[ax]);
        di += 0x0002;
        if (--r16[cx]) {
            pc = 0xcb62;
            break;
        }
        r8[cl] = r8[dh];
        di -= r16[cx];
        di += bp;
        pc = 0xcb5a;
        break;
    case 0xcb72:
        di = pop();
        return;
    } while (1);
}
function* sub_cb75() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[cs*16 + 0x0166] = 0x21;
        pc = 0xcb8b;
        break;
    case 0xcb8b:
        r16[bx] = 0x0101;
    case 0xcb8e:
        r16[dx] = 0x03c4;
        r8[ah] = r8[bh];
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        yield* sub_d02f();
        yield* sub_cba7();
        r8[bl]++;
        r8[bh] <<= 1;
        if (r8s[bh] > signed8(0x08))
            return;
        pc = 0xcb8e;
        break;
        return;
    } while (1);
}
function* sub_cb7d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[cs*16 + 0x0166] = 0x09;
        pc = 0xcb8b;
        break;
    case 0xcb8b:
        r16[bx] = 0x0101;
    case 0xcb8e:
        r16[dx] = 0x03c4;
        r8[ah] = r8[bh];
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        yield* sub_d02f();
        yield* sub_cba7();
        r8[bl]++;
        r8[bh] <<= 1;
        if (r8s[bh] > signed8(0x08))
            return;
        pc = 0xcb8e;
        break;
        return;
    } while (1);
}
function* sub_cb85() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[cs*16 + 0x0166] = 0x31;
        r16[bx] = 0x0101;
    case 0xcb8e:
        r16[dx] = 0x03c4;
        r8[ah] = r8[bh];
        r8[al] = 0x02;
        out16(r16[dx], r16[ax]);
        yield* sub_d02f();
        yield* sub_cba7();
        r8[bl]++;
        r8[bh] <<= 1;
        if (r8s[bh] > signed8(0x08))
            return;
        pc = 0xcb8e;
        break;
        return;
    } while (1);
}
function* sub_cba7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(ds);
        bp = 0x1228;
        ds = bp;
        bp = memory16get(ds, 0x5429);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
    case 0xcbbd:
        if (r8[dl] == r8[ch]) {
            pc = 0xcbd5;
            break;
        }
        r8[dl]--;
        r16[cx] >>= 1;
    case 0xcbc5:
        memory16set(es, di, memory16get(es, di) & r16[ax]);
        di += 0x0002;
        if (--r16[cx]) {
            pc = 0xcbc5;
            break;
        }
        r8[cl] = r8[dh];
        di -= r16[cx];
        di += bp;
        pc = 0xcbbd;
        break;
    case 0xcbd5:
        di = pop();
        return;
    } while (1);
}
function* sub_cbd8() {
}
function* sub_cbd9() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = false;
    r16[bx] = 0x1228;
    ds = r16[bx];
    es = r16[dx];
    di = r16[ax];
    memory16set(es, di + 24, 0x0014);
    memory16set(es, di + 26, 0x0019);
    memory[ds*16 + 0x541f] = 0x02;
    memory[ds*16 + 0x5420] = 0x01;
    r16[bx] = memory16get(ds, 0x541d);
    r16[bx] <<= 1;
    yield* callIndirect(cs, memory16get(ds, r16[bx] + 19930));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_cc0e() {
}
function* sub_cc0f() {
}
function* sub_cc10() {
}
function* sub_cc41() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    es = bp;
    bp = memory16get(ds, 0x541d);
    bp <<= 1;
    yield* callIndirect(cs, memory16get(ds, bp + 21557));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_cc5f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[bx] = memory16get(ds, 0x541d);
        r16[bx] <<= 1;
        switch (r16[bx])
        {
        case 0: pc = 0xcc6e; break;
        case 2: pc = 0xcc6e; break;
        case 4: pc = 0xcc6e; break;
        case 6: pc = 0xcc75; break;
        case 8: pc = 0xcc75; break;
        case 10: pc = 0xcc75; break;
            default:
            assert(0);
        }
        break;
    case 0xcc6e:
        r16[ax] = 0x000d;
        interrupt(0x10);
    case 0xcc75:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_cc7b() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = 0x1228;
    ds = r16[bx];
    memory16set(ds, 0x5313, r16[dx]);
    memory16set(ds, 0x5311, r16[ax]);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_cc92() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        if (r8[cl] != 0x00) {
            pc = 0xcc9e;
            break;
        }
        pc = 0xcd0b;
        break;
    case 0xcc9e:
        if (r8s[cl] > signed8(0x02)) {
            pc = 0xcd0b;
            break;
        }
        r16[ax] = 0x1228;
        ds = r16[ax];
        es = r16[ax];
        push(r16[cx]);
        di = 0x5310;
        r16[cx] = 0x0001;
        flags.direction = false;
        r8[al] = 0;
        rep_stosb_data_forward();
        r16[cx] = pop();
        si = 0x5415;
        r8[ch] = 0;
        r8[cl]--;
        r16[bx] = memory16get(ds, 0x541d);
        r16[bx] <<= 1;
        switch (r16[bx])
        {
        case 0: pc = 0xccc8; break;
        case 2: pc = 0xccc8; break;
        case 4: pc = 0xccc8; break;
            default:
            assert(0);
        }
        break;
    case 0xccc8:
        memory16set(ds, si + 2, 0xa000);
        memory16set(ds, si, 0x0000);
        if (memory16get(ds, 0x541d) != 0x0005) {
            pc = 0xcce7;
            break;
        }
        memory16set(ds, si + 6, 0xa400);
        memory16set(ds, si + 4, 0x0000);
        yield* sub_d02e();
        pc = 0xcd0b;
        break;
    case 0xcce7:
        memory16set(ds, si + 6, 0xa200);
        memory16set(ds, si + 4, 0x0000);
        pc = 0xcd0b;
        break;
    case 0xcd0b:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_cd11() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[ax] = 0x1228;
    ds = r16[ax];
    es = r16[ax];
    bp = memory16get(ds, 0x541d);
    bp <<= 1;
    yield* callIndirect(cs, memory16get(ds, bp + 21569));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_cd2e() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = 0x0002;
        interrupt(0x10);
        si = 0x529c;
        r8[bh] = 0;
        r16[dx] = 0x0101;
        r8[ah] = 0x02;
        interrupt(0x10);
        r8[ah] = 0x09;
        r16[dx] = si;
        interrupt(0x21);
        si = 0x52b4;
        di = 0x548b;
        r8[bh] = 0x00;
        r16[cx] = 0x0006;
        r16[dx] = 0x0a21;
    case 0xcd5d:
        if (memory[ds*16 + di] != 0x01) {
            pc = 0xcd70;
            break;
        }
        r8[ah] = 0x02;
        interrupt(0x10);
        push(r16[dx]);
        r8[ah] = 0x09;
        r16[dx] = si;
        interrupt(0x21);
        r16[dx] = pop();
        r8[dh]++;
    case 0xcd70:
        si += 0x000f;
        di++;
        if (--r16[cx]) {
            pc = 0xcd5d;
            break;
        }
    case 0xcd76:
        bumpyScene = "startup";
        yield* sync();
        r8[al] = 0x3c;
        push(cs);
        cs = 0x01ed;
        yield* sub_9aca();
        assert(cs == 0x0ca6);
        if (!flags.zero) {
            pc = 0xcd8a;
            break;
        }
        r8[al] = 0x3d;
        push(cs);
        cs = 0x01ed;
        yield* sub_9aca();
        assert(cs == 0x0ca6);
        if (!flags.zero) {
            pc = 0xcd98;
            break;
        }
        pc = 0xcd76;
        break;
    case 0xcd8a:
        memory16set(ds, 0x541d, 0x0001);
        memory16set(ds, 0x530e, 0x0040);
        pc = 0xcdab;
        break;
    case 0xcd98:
        memory16set(ds, 0x541d, 0x0002);
        memory16set(ds, 0x530e, 0x0040);
        pc = 0xcdab;
        break;
    case 0xcdab:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_cdb1() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        if (r16[bx] == 0x0000) {
            pc = 0xcdde;
            break;
        }
        if (r16s[bx] > signed16(0x0001)) {
            pc = 0xcdde;
            break;
        }
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[cx] = 0;
        r8[tl] = memory[ds*16 + r16[bx] + 21263];
        memory[ds*16 + r16[bx] + 21263] = r8[cl];
        r8[cl] = r8[tl];
        si = 0x5415;
        bp = memory16get(ds, 0x541d);
        bp <<= 1;
        switch (bp)
        {
        case 0: pc = 0xcdd9; break;
        case 2: pc = 0xcdd9; break;
        case 4: pc = 0xcdd9; break;
            default:
            assert(0);
        }
        break;
    case 0xcdd9:
        yield* sub_d121();
    case 0xcdde:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_ce87() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(es, di + 6);
        push(r16[cx]);
    case 0xce8c:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xce94;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xce8c;
        break;
    case 0xce94:
        r16[cx] = pop();
        if (!(memory16get(es, di + 28) & 0x0200)) {
            pc = 0xcea4;
            break;
        }
        r16[ax]++;
        memory16set(es, di + 28, memory16get(es, di + 28) & 0xfdff);
    case 0xcea4:
        memory16set(ds, 0x5423, r16[ax]);
        r16[ax] = 0x0014;
        if (memory[ds*16 + 0x541f] == 0x01) {
            pc = 0xceb5;
            break;
        }
        r16[ax] = memory16get(es, di + 10);
    case 0xceb5:
        push(r16[cx]);
    case 0xceb6:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xcebe;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xceb6;
        break;
    case 0xcebe:
        r16[cx] = pop();
        memory16set(ds, 0x542b, r16[ax]);
        r16[ax] = memory16get(es, di + 20);
        push(r16[cx]);
    case 0xcec7:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xcecf;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xcec7;
        break;
    case 0xcecf:
        r16[cx] = pop();
        if (!(memory16get(es, di + 28) & 0x0400)) {
            pc = 0xcedf;
            break;
        }
        r16[ax]++;
        memory16set(es, di + 28, memory16get(es, di + 28) & 0xfbff);
    case 0xcedf:
        memory16set(ds, 0x5421, r16[ax]);
        r16[ax] = 0x0014;
        if (memory[ds*16 + 0x5420] == 0x01) {
            pc = 0xcef0;
            break;
        }
        r16[ax] = memory16get(es, di + 24);
    case 0xcef0:
        push(r16[cx]);
    case 0xcef1:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xcef9;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xcef1;
        break;
    case 0xcef9:
        r16[cx] = pop();
        memory16set(ds, 0x5429, r16[ax]);
        r16[ax] = memory16get(es, di + 30);
        push(r16[cx]);
    case 0xcf02:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xcf0a;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xcf02;
        break;
    case 0xcf0a:
        r16[cx] = pop();
        memory16set(ds, 0x5431, r16[ax]);
        r16[cx] = 0x0008;
        r16[ax] = memory16get(es, di + 8);
        push(r16[cx]);
    case 0xcf16:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xcf1e;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xcf16;
        break;
    case 0xcf1e:
        r16[cx] = pop();
        if (!(memory16get(es, di + 28) & 0x0100)) {
            pc = 0xcf31;
            break;
        }
        r16[ax] += memory16get(es, di + 38);
        memory16set(es, di + 28, memory16get(es, di + 28) & 0x00fe);
    case 0xcf31:
        memory16set(ds, 0x542f, r16[ax]);
        r16[ax] = 0x0019;
        if (memory[ds*16 + 0x541f] == 0x01) {
            pc = 0xcf42;
            break;
        }
        r16[ax] = memory16get(es, di + 12);
    case 0xcf42:
        push(r16[cx]);
    case 0xcf43:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xcf4b;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xcf43;
        break;
    case 0xcf4b:
        r16[cx] = pop();
        memory16set(ds, 0x5427, r16[ax]);
        r16[ax] = memory16get(es, di + 22);
        push(r16[cx]);
    case 0xcf54:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xcf5c;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xcf54;
        break;
    case 0xcf5c:
        r16[cx] = pop();
        memory16set(ds, 0x542d, r16[ax]);
        r16[ax] = 0x0019;
        if (memory[ds*16 + 0x5420] == 0x01) {
            pc = 0xcf6e;
            break;
        }
        r16[ax] = memory16get(es, di + 26);
    case 0xcf6e:
        push(r16[cx]);
    case 0xcf6f:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xcf77;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xcf6f;
        break;
    case 0xcf77:
        r16[cx] = pop();
        memory16set(ds, 0x5425, r16[ax]);
        r16[ax] = memory16get(es, di + 32);
        push(r16[cx]);
    case 0xcf80:
        r16[cx] >>= 1;
        if (r16[cx] == 0) {
            pc = 0xcf88;
            break;
        }
        r16[ax] <<= 1;
        pc = 0xcf80;
        break;
    case 0xcf88:
        r16[cx] = pop();
        memory16set(ds, 0x5433, r16[ax]);
        return;
    } while (1);
}
function* sub_cf8d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(bp);
        r16[bx] = di;
        if (memory[ds*16 + 0x541f] == 0x02) {
            pc = 0xcfd6;
            break;
        }
        r16[ax] = memory16get(ds, 0x542f);
        mul16(memory16get(ds, 0x542b));
        r16[ax] += memory16get(ds, 0x5423);
        si = r16[ax];
        if (memory[ds*16 + 0x541f] != 0x01) {
            pc = 0xcfbd;
            break;
        }
        bp = memory16get(es, r16[bx]);
        bp <<= 1;
        bp <<= 1;
        r16[ax] = memory16get(ds, bp + 21525);
        ds = memory16get(ds, bp + 21525 + 2);
        pc = 0xcfc1;
        break;
    case 0xcfbd:
        r16[ax] = memory16get(es, r16[bx] + 2);
        ds = memory16get(es, r16[bx] + 2 + 2);
    case 0xcfc1:
        si += r16[ax];
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(r16[bx]);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0ca6);
        r16[bx] = pop();
        ds = r16[dx];
        si = r16[ax];
        es = pop();
    case 0xcfd6:
        push(ds);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x542d);
        mul16(memory16get(ds, 0x5429));
        r16[ax] += memory16get(ds, 0x5421);
        di = r16[ax];
        if (memory[ds*16 + 0x5420] != 0x01) {
            pc = 0xd000;
            break;
        }
        bp = memory16get(es, r16[bx] + 14);
        bp <<= 1;
        bp <<= 1;
        r16[ax] = memory16get(ds, bp + 21525);
        es = memory16get(ds, bp + 21525 + 2);
        ds = pop();
        pc = 0xd010;
        break;
    case 0xd000:
        r16[ax] = memory16get(es, r16[bx] + 16);
        es = memory16get(es, r16[bx] + 16 + 2);
        ds = pop();
        di += r16[ax];
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0ca6);
        es = r16[dx];
        di = r16[ax];
    case 0xd010:
        bp = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_d016() {
    r16[dx] = r16[bx];
    r16[dx] <<= 1;
    r16[dx] <<= 1;
    r16[ax] = r16[dx];
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[dx] += r16[ax];
    r16[ax] <<= 1;
    r16[ax] += r16[dx];
    r16[ax] -= r16[bx];
}
function* sub_d02e() {
}
function* sub_d02f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0;
        r8[dl] = memory[ds*16 + si + 34];
        if (!(r8[bh] & r8[dl])) {
            pc = 0xd03a;
            break;
        }
        r8[al] = 0x01;
    case 0xd03a:
        r8[dl] = memory[ds*16 + si + 35];
        if (!(r8[bh] & r8[dl])) {
            pc = 0xd043;
            break;
        }
        r8[al] |= 0x02;
    case 0xd043:
        r8[dl] = memory[ds*16 + si + 36];
        if (!(r8[bh] & r8[dl])) {
            pc = 0xd04c;
            break;
        }
        r8[al] |= 0x04;
    case 0xd04c:
        r8[dl] = memory[ds*16 + si + 37];
        if (!(r8[bh] & r8[dl])) {
            pc = 0xd055;
            break;
        }
        r8[al] |= 0x08;
    case 0xd055:
        r8[dl] = r8[al];
        r8[dl] <<= 1;
        r8[dl] <<= 1;
        r8[dl] <<= 1;
        r8[dl] <<= 1;
        r8[al] |= r8[dl];
        r8[ah] = r8[al];
        return;
    } while (1);
}
function* sub_d065() {
}
function* sub_d066() {
    di = 0x5311;
    r16[tx] = di;
    di = memory16get(ds, r16[tx]);
    es = memory16get(ds, r16[tx] + 2);
    si = r16[ax];
    ds = r16[dx];
    yield* sub_d016();
    di += r16[ax];
    di += 0x0023;
    si += 0x0023;
    r16[cx] = 0x0008;
    rep_movsw_data_data_forward();
}
function* sub_d080() {
    var pc = 0;
    do switch (pc) {
    case 0:
        di = 0x5311;
        r16[tx] = di;
        di = memory16get(ds, r16[tx]);
        es = memory16get(ds, r16[tx] + 2);
        si = r16[ax];
        ds = r16[dx];
        yield* sub_d016();
        di += r16[ax];
        di += 0x0033;
        si += 0x0033;
        push(ds);
        r16[ax] = 0x1228;
        ds = r16[ax];
        if (memory16get(ds, 0x541d) != 0x0005) {
            pc = 0xd0a4;
            break;
        }
        di += 0x0030;
    case 0xd0a4:
        ds = pop();
        r16[cx] = 0x0018;
        rep_movsw_data_data_forward();
        return;
    } while (1);
}
function* sub_d0ab() {
}
function* sub_d0ac() {
}
function* sub_d0ad() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r16[cx] = 0x0007;
    case 0xd0b3:
        lodsw_data_forward();
        out16(r16[dx], r16[ax]);
        if (--r16[cx]) {
            pc = 0xd0b3;
            break;
        }
        r16[dx] = 0x03c4;
        r16[ax] = memory16get(ds, si);
        out16(r16[dx], r16[ax]);
        return;
    } while (1);
}
function* sub_d0bf() {
}
function* sub_d0c1() {
}
function* sub_d0c2() {
    si = 0x5311;
    r16[tx] = si;
    si = memory16get(ds, r16[tx]);
    es = memory16get(ds, r16[tx] + 2);
    yield* sub_d016();
    si += r16[ax];
    si += 0x0023;
    r16[dx] = si;
    r16[ax] = 0x1002;
    interrupt(0x10);
}
function* sub_d0d7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        si = 0x5311;
        r16[tx] = si;
        si = memory16get(ds, r16[tx]);
        es = memory16get(ds, r16[tx] + 2);
        yield* sub_d016();
        si += r16[ax];
        si += 0x0033;
        r16[dx] = 0x03c8;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[dx]++;
        r16[cx] = 0x0008;
    case 0xd0ee:
        r8[al] = memory[es*16 + si];
        out8(r16[dx], r8[al]);
        r8[al] = memory[es*16 + si + 1];
        out8(r16[dx], r8[al]);
        r8[al] = memory[es*16 + si + 2];
        out8(r16[dx], r8[al]);
        si += 0x0003;
        if (--r16[cx]) {
            pc = 0xd0ee;
            break;
        }
        r16[dx]--;
        r8[al] = 0x10;
        out8(r16[dx], r8[al]);
        r16[dx]++;
        r16[cx] = 0x0008;
    case 0xd109:
        r8[al] = memory[es*16 + si];
        out8(r16[dx], r8[al]);
        r8[al] = memory[es*16 + si + 1];
        out8(r16[dx], r8[al]);
        r8[al] = memory[es*16 + si + 2];
        out8(r16[dx], r8[al]);
        si += 0x0003;
        if (--r16[cx]) {
            pc = 0xd109;
            break;
        }
        return;
    } while (1);
}
function* sub_d11d() {
}
function* sub_d11e() {
}
function* sub_d11f() {
}
function* sub_d121() {
    flags.interrupts = false;
    r16[dx] = 0x03d4;
    r8[al] = 0x0c;
    out8(r16[dx], r8[al]);
    r16[dx]++;
    r8[al] = in8(r16[dx]);
    r8[ah] = 0x20;
    r8[al] ^= r8[ah];
    out8(r16[dx], r8[al]);
    flags.interrupts = true;
    r16[bx] <<= 1;
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, si + 2);
    r16[tx] = memory16get(ds, r16[bx] + si + 2);
    memory16set(ds, r16[bx] + si + 2, r16[ax]);
    r16[ax] = r16[tx];
    memory16set(ds, si + 2, r16[ax]);
}
function* sub_d250() {
    r16[cx] = 0x0002;
    yield* sub_ce87();
    r16[ax] = memory16get(ds, 0x542b);
    mul16(memory16get(ds, 0x5427));
    bp = r16[ax];
    r16[ax] = memory16get(ds, 0x5429);
    mul16(memory16get(ds, 0x5425));
    r16[bx] = r16[ax];
    r16[ax] = memory16get(es, di + 28);
    yield* sub_cf8d();
    push(r16[bx]);
    push(ds);
    r16[bx] = r16[ax];
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 21814);
    ds = pop();
    r16[bx] = pop();
    yield* callIndirect(cs, r16[ax]);
}
function* sub_d283() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.direction = false;
        r16[ax] = 0;
    case 0xd286:
        yield* sub_d2b8();
        r8[ah]++;
        if (r8s[ah] > signed8(0x03))
            return;
        si += bp;
        di += r16[bx];
        push(r16[ax]);
        push(r16[bx]);
        push(r16[dx]);
        push(di);
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0ca6);
        ds = r16[dx];
        si = r16[ax];
        es = pop();
        di = pop();
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0ca6);
        es = r16[dx];
        di = r16[ax];
        r16[dx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        pc = 0xd286;
        break;
        return;
    } while (1);
}
function* sub_d2b8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[bx]);
        push(bp);
        push(si);
        push(di);
        push(ds);
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[bx] = memory16get(ds, 0x542b);
        bp = memory16get(ds, 0x5429);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
    case 0xd2d5:
        if (r8[dl] == 0x00) {
            pc = 0xd2ec;
            break;
        }
        r8[dl]--;
        r16[cx] >>= 1;
        rep_movsw_data_data_forward();
        r8[cl] = r8[dh];
        si -= r16[cx];
        di -= r16[cx];
        si += r16[bx];
        di += bp;
        pc = 0xd2d5;
        break;
    case 0xd2ec:
        di = pop();
        si = pop();
        bp = pop();
        r16[bx] = pop();
        return;
    } while (1);
}
function* sub_d2f2() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x5429);
        memory16set(cs, 0x0a9c, r16[ax]);
        r16[ax] = memory16get(ds, 0x542b);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
        if (r16[cx] == 0)
            return;
    case 0xd30f:
        if (r8[dl] == 0x00)
            return;
        r8[dl]--;
        r16[cx] >>= 1;
        push(r16[ax]);
        push(r16[dx]);
    case 0xd31a:
        r16[dx] = memory16get(ds, si);
        si += bp;
        di += r16[bx];
        r16[dx] |= memory16get(ds, si);
        si += bp;
        di += r16[bx];
        r16[dx] |= memory16get(ds, si);
        si += bp;
        di += r16[bx];
        r16[dx] |= memory16get(ds, si);
        r16[dx] = ~dx;
        r16[ax] = memory16get(es, di);
        r16[ax] &= r16[dx];
        r16[ax] |= memory16get(ds, si);
        memory16set(es, di, r16[ax]);
        si -= bp;
        di -= r16[bx];
        r16[ax] = memory16get(es, di);
        r16[ax] &= r16[dx];
        r16[ax] |= memory16get(ds, si);
        memory16set(es, di, r16[ax]);
        si -= bp;
        di -= r16[bx];
        r16[ax] = memory16get(es, di);
        r16[ax] &= r16[dx];
        r16[ax] |= memory16get(ds, si);
        memory16set(es, di, r16[ax]);
        si -= bp;
        di -= r16[bx];
        r16[ax] = memory16get(es, di);
        r16[ax] &= r16[dx];
        r16[ax] |= memory16get(ds, si);
        memory16set(es, di, r16[ax]);
        si += 0x0002;
        di += 0x0002;
        if (--r16[cx]) {
            pc = 0xd31a;
            break;
        }
        r16[dx] = pop();
        r16[ax] = pop();
        r8[cl] = r8[dh];
        si -= r16[cx];
        di -= r16[cx];
        si += r16[ax];
        di += memory16get(cs, 0x0a9c);
        pc = 0xd30f;
        break;
        return;
    } while (1);
}
function* sub_d37e() {
}
function* sub_d37f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[cs*16 + 0x0973] = 0x21;
        pc = 0xd395;
        break;
    case 0xd395:
        r16[ax] = 0;
    case 0xd397:
        yield* sub_d3a7();
        r8[ah]++;
        if (r8s[ah] > signed8(0x03))
            return;
        si += bp;
        di += r16[bx];
        pc = 0xd397;
        break;
        return;
    } while (1);
}
function* sub_d387() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[cs*16 + 0x0973] = 0x09;
        pc = 0xd395;
        break;
    case 0xd395:
        r16[ax] = 0;
    case 0xd397:
        yield* sub_d3a7();
        r8[ah]++;
        if (r8s[ah] > signed8(0x03))
            return;
        si += bp;
        di += r16[bx];
        pc = 0xd397;
        break;
        return;
    } while (1);
}
function* sub_d38f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[cs*16 + 0x0973] = 0x31;
        r16[ax] = 0;
    case 0xd397:
        yield* sub_d3a7();
        r8[ah]++;
        if (r8s[ah] > signed8(0x03))
            return;
        si += bp;
        di += r16[bx];
        pc = 0xd397;
        break;
        return;
    } while (1);
}
function* sub_d3a7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(bp);
        push(si);
        push(di);
        push(ds);
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[bx] = memory16get(ds, 0x542b);
        bp = memory16get(ds, 0x5429);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
        if (r16[cx] == 0) {
            pc = 0xd3e9;
            break;
        }
    case 0xd3c7:
        if (r8[dl] == 0x00) {
            pc = 0xd3e9;
            break;
        }
        r8[dl]--;
        r16[cx] >>= 1;
    case 0xd3d0:
        r16[ax] = memory16get(ds, si);
        memory16set(es, di, memory16get(es, di) & r16[ax]);
        si += 0x0002;
        di += 0x0002;
        if (--r16[cx]) {
            pc = 0xd3d0;
            break;
        }
        r8[cl] = r8[dh];
        si -= r16[cx];
        di -= r16[cx];
        si += r16[bx];
        di += bp;
        pc = 0xd3c7;
        break;
    case 0xd3e9:
        di = pop();
        si = pop();
        bp = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_d3f0() {
}
function* sub_d3f1() {
}
function* sub_d3f7() {
}
function* sub_d3f8() {
}
function* sub_d3f9() {
}
function* sub_d4d3() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    flags.direction = false;
    r16[bx] = 0x1228;
    ds = r16[bx];
    es = r16[dx];
    di = r16[ax];
    memory[ds*16 + 0x541f] = 0x00;
    memory[ds*16 + 0x5420] = 0x00;
    r16[bx] = memory16get(ds, 0x541d);
    r16[bx] <<= 1;
    yield* callIndirect(cs, memory16get(ds, r16[bx] + 21828));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_d500() {
    si = 0x556a;
    yield* sub_d0ad();
    r16[cx] = 0x0002;
    yield* sub_ce87();
    r16[ax] = memory16get(ds, 0x542b);
    mul16(memory16get(ds, 0x5427));
    bp = r16[ax];
    r16[bx] = memory16get(es, di + 28);
    push(r16[bx]);
    r16[bx] = di;
    yield* sub_cf8d();
    r16[bx] = pop();
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 21840);
    ds = pop();
    yield* callIndirect(cs, r16[ax]);
}
function* sub_d530() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.direction = false;
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = 0x01;
    case 0xd539:
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        pc = 0xd560;
        break;
    case 0xd53f:
        r8[al] <<= 1;
        if (r8s[al] > signed8(0x08))
            return;
        si += bp;
        push(r16[ax]);
        push(r16[bx]);
        push(di);
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0ca6);
        ds = r16[dx];
        si = r16[ax];
        es = pop();
        di = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        pc = 0xd539;
        break;
    case 0xd560:
        push(si);
        push(di);
        push(ds);
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[bx] = memory16get(ds, 0x542b);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
    case 0xd577:
        if (r8[dl] == r8[ch]) {
            pc = 0xd58e;
            break;
        }
        r8[dl]--;
        r16[cx] >>= 1;
        rep_movsw_video_data_forward();
        r8[cl] = r8[dh];
        si -= r16[cx];
        di -= r16[cx];
        si += r16[bx];
        di += 0x0028;
        pc = 0xd577;
        break;
    case 0xd58e:
        di = pop();
        si = pop();
        pc = 0xd53f;
        break;
        return;
    } while (1);
}
function* sub_d593() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(cs, 0x0b81, 0x9090);
        pc = 0xd5a3;
        break;
    case 0xd5a3:
        r16[dx] = 0x03c4;
        r16[ax] = 0x0002;
        out16(r16[dx], r16[ax]);
        push(ds);
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[bx] = memory16get(ds, 0x542b);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
        if (r16[cx] == 0) {
            pc = 0xd5c3;
            break;
        }
        pc = 0xd5c6;
        break;
    case 0xd5c3:
        return;
    case 0xd5c6:
        if (r8[dl] != r8[ch]) {
            pc = 0xd5cd;
            break;
        }
        return;
    case 0xd5cd:
        r8[dl]--;
        r16[cx] >>= 1;
        push(r16[dx]);
    case 0xd5d2:
        r16[ax] = memory16get(ds, si);
        si += bp;
        r16[ax] |= memory16get(ds, si);
        si += bp;
        r16[ax] |= memory16get(ds, si);
        si += bp;
        r16[ax] |= memory16get(ds, si);
        push(si);
        r8[ch] = r8[ah];
        r8[ah] = r8[al];
        r16[dx] = 0x03ce;
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r8[al] = videoGet(es, di);
        r16[dx] = 0x03c5;
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r8[ah] = memory[ds*16 + si];
        videoSet(es, di, r8[ah]);
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        r8[ah] = memory[ds*16 + si];
        videoSet(es, di, r8[ah]);
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        r8[ah] = memory[ds*16 + si];
        videoSet(es, di, r8[ah]);
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        movsb_video_data_forward();
        r8[ah] = r8[ch];
        si = pop();
        si++;
        r16[dx] = 0x03ce;
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r8[al] = videoGet(es, di);
        r16[dx] = 0x03c5;
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r8[ah] = memory[ds*16 + si];
        videoSet(es, di, r8[ah]);
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        r8[ah] = memory[ds*16 + si];
        videoSet(es, di, r8[ah]);
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        r8[ah] = memory[ds*16 + si];
        videoSet(es, di, r8[ah]);
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        movsb_video_data_forward();
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0xd5d2;
            break;
        }
        r16[dx] = pop();
        r8[ch] = 0;
        r8[cl] = r8[dh];
        si -= r16[cx];
        di -= r16[cx];
        si += r16[bx];
        di += 0x0028;
        pc = 0xd5c6;
        break;
        return;
    } while (1);
}
function* sub_d59c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(cs, 0x0b81, 0xd0f7);
        r16[dx] = 0x03c4;
        r16[ax] = 0x0002;
        out16(r16[dx], r16[ax]);
        push(ds);
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[bx] = memory16get(ds, 0x542b);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
        if (r16[cx] == 0) {
            pc = 0xd5c3;
            break;
        }
        pc = 0xd5c6;
        break;
    case 0xd5c3:
        return;
    case 0xd5c6:
        if (r8[dl] != r8[ch]) {
            pc = 0xd5cd;
            break;
        }
        return;
    case 0xd5cd:
        r8[dl]--;
        r16[cx] >>= 1;
        push(r16[dx]);
    case 0xd5d2:
        r16[ax] = memory16get(ds, si);
        si += bp;
        r16[ax] |= memory16get(ds, si);
        si += bp;
        r16[ax] |= memory16get(ds, si);
        si += bp;
        r16[ax] |= memory16get(ds, si);
        push(si);
        r8[ch] = r8[ah];
        r8[ah] = r8[al];
        r16[dx] = 0x03ce;
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r8[al] = memory[es*16 + di];
        r16[dx] = 0x03c5;
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r8[ah] = memory[ds*16 + si];
        memory[es*16 + di] = r8[ah];
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        r8[ah] = memory[ds*16 + si];
        memory[es*16 + di] = r8[ah];
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        r8[ah] = memory[ds*16 + si];
        memory[es*16 + di] = r8[ah];
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        movsb_data_data_forward();
        r8[ah] = r8[ch];
        si = pop();
        si++;
        r16[dx] = 0x03ce;
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r8[al] = memory[es*16 + di];
        r16[dx] = 0x03c5;
        r8[al] = 0x08;
        out8(r16[dx], r8[al]);
        r8[ah] = memory[ds*16 + si];
        memory[es*16 + di] = r8[ah];
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        r8[ah] = memory[ds*16 + si];
        memory[es*16 + di] = r8[ah];
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        r8[ah] = memory[ds*16 + si];
        memory[es*16 + di] = r8[ah];
        r8[al] >>= 1;
        out8(r16[dx], r8[al]);
        si -= bp;
        movsb_data_data_forward();
        r8[cl]--;
        if (r8[cl] != 0) {
            pc = 0xd5d2;
            break;
        }
        r16[dx] = pop();
        r8[ch] = 0;
        r8[cl] = r8[dh];
        si -= r16[cx];
        di -= r16[cx];
        si += r16[bx];
        di += 0x0028;
        pc = 0xd5c6;
        break;
        return;
    } while (1);
}
function* sub_d65d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = 0x00;
        r8[ah] = 0x01;
    case 0xd683:
        r16[dx] = 0x03cf;
        out8(r16[dx], r8[al]);
        r8[tl] = r8[ah];
        r8[ah] = r8[al];
        r8[al] = r8[tl];
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        sub_d69e(0x21);
        r8[al]++;
        r8[ah] <<= 1;
        if (r8s[al] > signed8(0x03))
            return;
        si += bp;
        pc = 0xd683;
        break;
        return;
    } while (1);
}
function* sub_d665() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = 0x00;
        r8[ah] = 0x01;
    case 0xd683:
        r16[dx] = 0x03cf;
        out8(r16[dx], r8[al]);
        r8[tl] = r8[ah];
        r8[ah] = r8[al];
        r8[al] = r8[tl];
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        sub_d69e(0x09);
        r8[al]++;
        r8[ah] <<= 1;
        if (r8s[al] > signed8(0x03))
            return;
        si += bp;
        pc = 0xd683;
        break;
        return;
    } while (1);
}
function* sub_d66d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = 0x03ce;
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r8[al] = 0x00;
        r8[ah] = 0x01;
    case 0xd683:
        r16[dx] = 0x03cf;
        out8(r16[dx], r8[al]);
        r8[tl] = r8[ah];
        r8[ah] = r8[al];
        r8[al] = r8[tl];
        r16[dx] = 0x03c5;
        out8(r16[dx], r8[al]);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        sub_d69e(0x31);
        r8[al]++;
        r8[ah] <<= 1;
        if (r8s[al] > signed8(0x03))
            return;
        si += bp;
        pc = 0xd683;
        break;
        return;
    } while (1);
}
function* sub_d69e(opcode) {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(si);
        push(di);
        push(ds);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[bx] = memory16get(ds, 0x542b);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
        if (r16[cx] == 0) {
            pc = 0xd6da;
            break;
        }
    case 0xd6b8:
        if (r8[dl] == r8[ch]) {
            pc = 0xd6da;
            break;
        }
        r8[dl]--;
        r16[cx] >>= 1;
    case 0xd6c0:
        r16[ax] = memory16get(ds, si);
        switch (opcode)
        {
        case 0x21: memoryAAnd16(es, di, r16[ax]); break;
        case 0x09: memoryAOr16(es, di, r16[ax]); break;
        case 0x31: memoryAXor16(es, di, r16[ax]); break;
        }
        break;
        si += 0x0002;
        di += 0x0002;
        if (--r16[cx]) {
            pc = 0xd6c0;
            break;
        }
        r8[cl] = r8[dh];
        si -= r16[cx];
        di -= r16[cx];
        si += r16[bx];
        di += 0x0028;
        pc = 0xd6b8;
        break;
    case 0xd6da:
        di = pop();
        si = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_d6df() {
}
function* sub_d6e0() {
}
function* sub_d6e6() {
}
function* sub_d6e7() {
}
function* sub_d6e8() {
}
function* sub_d7d7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[bx] = 0x1228;
        ds = r16[bx];
        es = r16[dx];
        di = r16[ax];
        bp = memory16get(es, di + 14);
        if (signed16(bp) > signed16(0x0001)) {
            pc = 0xd802;
            break;
        }
        memory[ds*16 + 0x541f] = 0x00;
        memory[ds*16 + 0x5420] = 0x01;
        r16[bx] = memory16get(ds, 0x541d);
        r16[bx] <<= 1;
        assert(r16[bx] == 4);
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 21854));
    case 0xd802:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_d810() {
    si = 0x56a4;
    yield* sub_d0ad();
    r16[cx] = 0x0002;
    yield* sub_ce87();
    r16[ax] = memory16get(ds, 0x5429);
    mul16(memory16get(ds, 0x5425));
    bp = r16[ax];
    r16[bx] = memory16get(es, di + 28);
    push(r16[bx]);
    r16[bx] = di;
    yield* sub_cf8d();
    r16[bx] = pop();
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 22154);
    ds = pop();
    yield* callIndirect(cs, r16[ax]);
}
function* sub_d840() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.direction = false;
        r16[dx] = 0x03ce;
        r8[al] = 0x04;
        out8(r16[dx], r8[al]);
        r8[al] = 0x00;
    case 0xd849:
        r16[dx] = 0x03cf;
        out8(r16[dx], r8[al]);
        yield* sub_d869();
        r8[al]++;
        if (r8s[al] > signed8(0x03))
            return;
        di += bp;
        push(r16[ax]);
        push(r16[bx]);
        push(r16[dx]);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0ca6);
        es = r16[dx];
        di = r16[ax];
        r16[dx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        pc = 0xd849;
        break;
        return;
    } while (1);
}
function* sub_d869() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(si);
        push(di);
        push(ds);
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[bx] = memory16get(ds, 0x5429);
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
    case 0xd880:
        if (r8[dl] == 0x00) {
            pc = 0xd898;
            break;
        }
        r8[dl]--;
        r16[cx] >>= 1;
        rep_movsw_data_video_forward();
        r8[cl] = r8[dh];
        si -= r16[cx];
        di -= r16[cx];
        si += 0x0028;
        di += r16[bx];
        pc = 0xd880;
        break;
    case 0xd898:
        di = pop();
        si = pop();
        return;
    } while (1);
}
function* sub_d923() {
}
function* sub_d995() {
}
function* sub_da88() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[bx] = 0x1228;
        ds = r16[bx];
        es = r16[dx];
        di = r16[ax];
        bp = memory16get(es, di);
        if (signed16(bp) > signed16(0x0001)) {
            pc = 0xdab2;
            break;
        }
        memory[ds*16 + 0x541f] = 0x01;
        memory[ds*16 + 0x5420] = 0x00;
        r16[bx] = memory16get(ds, 0x541d);
        r16[bx] <<= 1;
        assert(r16[bx]==4);
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 22168));
    case 0xdab2:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_dac0() {
    si = 0x56ce;
    yield* sub_d0ad();
    r16[cx] = 0x0002;
    yield* sub_ce87();
    r16[bx] = memory16get(es, di + 28);
    push(r16[bx]);
    r16[bx] = di;
    yield* sub_cf8d();
    r16[bx] = pop();
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] <<= 1;
    r16[ax] = memory16get(ds, r16[bx] + 22196);
    ds = pop();
    yield* callIndirect(cs, r16[ax]);
}
function* sub_dae7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        flags.direction = false;
        r16[dx] = 0x03c4;
        r16[ax] = 0x0f02;
        out16(r16[dx], r16[ax]);
        push(ds);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[dx] = memory16get(ds, 0x5433);
        r16[cx] = memory16get(ds, 0x5431);
        r8[dh] = r8[cl];
        ds = pop();
    case 0xdb00:
        if (r8[dl] == 0x00)
            return;
        r8[dl]--;
        rep_movsb_video_video_forward();
        r8[cl] = r8[dh];
        si -= r16[cx];
        di -= r16[cx];
        si += 0x0028;
        di += 0x0028;
        pc = 0xdb00;
        break;
        return;
    } while (1);
}
function* sub_dc36() {
}
function* sub_dc3c() {
}
function* sub_dc3d() {
}
function* sub_dc3e() {
}
function* sub_dcce() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[bx] = 0x1228;
        ds = r16[bx];
        es = r16[dx];
        di = r16[ax];
        r16[bx] = memory16get(es, di);
        if (r16s[bx] > signed16(0x0001)) {
            pc = 0xdd01;
            break;
        }
        bp = memory16get(es, di + 14);
        if (signed16(bp) > signed16(0x0001)) {
            pc = 0xdd01;
            break;
        }
        memory[ds*16 + 0x541f] = 0x01;
        memory[ds*16 + 0x5420] = 0x01;
        si = memory16get(ds, 0x541d);
        si <<= 1;
        yield* callIndirect(cs, memory16get(ds, si + 22210));
    case 0xdd01:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_dd71() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = 0x1228;
    ds = r16[bx];
    r16[bx] = memory16get(ds, 0x541d);
    r16[bx] <<= 1;
    yield* callIndirect(cs, memory16get(ds, r16[bx] + 26950));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_dd8b() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = 0x1228;
    ds = r16[bx];
    memory16set(ds, 0x68a4, r16[dx]);
    memory16set(ds, 0x68a2, r16[ax]);
    di = 0x68a2;
    r16[bx] = memory16get(ds, di + 2);
    es = r16[bx];
    di = memory16get(ds, di);
    r8[al] = memory[es*16 + di + 3];
    r8[al] += 0x02;
    memory[ds*16 + 0x693e] = r8[al];
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_dddb() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[ax] = 0x000a;
    r16[dx] = 0x000a;
    push(cs);
    yield* sub_dea1();
    r16[ax] = 0x0000;
    r16[bx] = 0x0000;
    r16[cx] = 0x013f;
    r16[dx] = 0x00c7;
    push(cs);
    yield* sub_de82();
    r16[bx] = 0x0000;
    push(cs);
    yield* sub_de69();
    r8[al] = 0x08;
    push(cs);
    yield* sub_deb8();
    r16[ax] = 0x000f;
    r16[dx] = 0x0000;
    push(cs);
    yield* sub_dd71();
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_de1c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        flags.direction = false;
        r16[bx] = 0x1228;
        ds = r16[bx];
        di = 0x68a2;
        r16[bx] = memory16get(ds, di + 2);
        es = r16[bx];
        di = memory16get(ds, di);
        if (r8[al] < memory[es*16 + di]) {
            pc = 0xde46;
            break;
        }
        if (r8[al] >= memory[es*16 + di + 1]) {
            pc = 0xde46;
            break;
        }
        r16[bx] = memory16get(ds, 0x541d);
        r16[bx] <<= 1;
        yield* callIndirect(cs, memory16get(ds, r16[bx] + 26962));
    case 0xde46:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_de4c() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        flags.direction = false;
        ds = r16[dx];
        si = r16[ax];
    case 0xde56:
        r8[al] = memory[ds*16 + si];
        if (r8[al] == 0x00) {
            pc = 0xde63;
            break;
        }
        push(cs);
        yield* sub_de1c();
        si++;
        pc = 0xde56;
        break;
    case 0xde63:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_de69() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        if (r16s[bx] > signed16(0x0001)) {
            pc = 0xde7c;
            break;
        }
        r16[ax] = 0x1228;
        ds = r16[ax];
        memory16set(ds, 0x6940, r16[bx]);
    case 0xde7c:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_de82() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    bp = 0x1228;
    ds = bp;
    memory16set(ds, 0x6936, r16[ax]);
    memory16set(ds, 0x6938, r16[bx]);
    memory16set(ds, 0x693a, r16[cx]);
    memory16set(ds, 0x693c, r16[dx]);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_dea1() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = 0x1228;
    ds = r16[bx];
    memory16set(ds, 0x6944, r16[dx]);
    memory16set(ds, 0x6942, r16[ax]);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_deb8() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = 0x1228;
    ds = r16[bx];
    memory[ds*16 + 0x693e] = r8[al];
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_deee() {
    si = 0x695e;
    memory16set(ds, si, 0x68b6);
    memory16set(ds, si + 2, ds);
    bp = memory16get(ds, 0x6940);
    bp <<= 1;
    bp <<= 1;
    r16[ax] += memory16get(ds, bp + 21525);
    memory16set(ds, si + 8, r16[ax]);
    r16[ax] = memory16get(ds, bp + 21527);
    memory16set(ds, si + 10, r16[ax]);
    r16[ax] = 0;
    r8[al] = r8[bl];
    memory16set(ds, si + 12, r16[ax]);
    r8[al] = r8[bh];
    memory16set(ds, si + 14, r16[ax]);
    r8[al] = r8[cl];
    memory16set(ds, si + 16, r16[ax]);
    r8[al] = r8[ch];
    memory16set(ds, si + 18, r16[ax]);
    memory[ds*16 + si + 22] = r8[dl];
    r16[dx] = ds;
    r16[ax] = si;
    push(cs);
    cs = 0x0ed9;
    yield* sub_11aa5();
    assert(cs == 0x0ca6);
}
function* sub_df33() {
    r8[al] -= memory[es*16 + di];
    r8[ah] = 0;
    r16[ax] <<= 1;
    r16[bx] = es;
    ds = r16[bx];
    si = di;
    si += 0x0006;
    si += r16[ax];
    r16[ax] = memory16get(ds, si);
    r8[tl] = r8[al];
    r8[al] = r8[ah];
    r8[ah] = r8[tl];
    r16[ax] += di;
    si = r16[ax];
}
function* sub_df4f() {
    si = 0x68a6;
    yield* sub_df5f();
    si = 0x68ae;
    r16[ax] = r16[dx];
    yield* sub_df5f();
    return;
}
function* sub_df5f() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory16set(ds, si, 0x0000);
        memory16set(ds, si + 2, 0x0000);
        if (!(r16[ax] & 0x0001)) {
            pc = 0xdf70;
            break;
        }
        memory[ds*16 + si] = 0xff;
    case 0xdf70:
        if (!(r16[ax] & 0x0002)) {
            pc = 0xdf79;
            break;
        }
        memory[ds*16 + si + 1] = 0xff;
    case 0xdf79:
        if (!(r16[ax] & 0x0004)) {
            pc = 0xdf84;
            break;
        }
        memory[ds*16 + si + 2] = 0xff;
        if (!(r16[ax] & 0x0004)) {
            pc = 0xdf84;
            break;
        }
    case 0xdf84:
        if (!(r16[ax] & 0x0008))
            return;
        memory[ds*16 + si + 3] = 0xff;
        return;
    } while (1);
}
function* sub_df90() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[dx]);
        if (r16s[ax] < memory16gets(ds, 0x6936)) {
            pc = 0xdfbb;
            break;
        }
        flags.carry = (r8[al] + r8[bh]) >= 0x100;
        r8[al] += r8[bh];
        if (!flags.carry) {
            pc = 0xdf9e;
            break;
        }
        r8[ah]++;
    case 0xdf9e:
        r16[ax]--;
        if (r16s[ax] > memory16gets(ds, 0x693a)) {
            pc = 0xdfbb;
            break;
        }
        if (r16s[dx] < memory16gets(ds, 0x6938)) {
            pc = 0xdfbb;
            break;
        }
        flags.carry = (r8[dl] + r8[bl]) >= 0x100;
        r8[dl] += r8[bl];
        if (!flags.carry) {
            pc = 0xdfb1;
            break;
        }
        r8[dh]++;
    case 0xdfb1:
        r16[dx]--;
        if (r16s[dx] > memory16gets(ds, 0x693c)) {
            pc = 0xdfbb;
            break;
        }
        flags.carry = false;
        pc = 0xdfbc;
        break;
    case 0xdfbb:
        flags.carry = true;
    case 0xdfbc:
        r16[dx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_dfbf() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(bp);
        push(di);
        push(si);
        push(ds);
        push(es);
        si = 0x68ae;
        di = 0x68b6;
        r16[cx] = 0x0080;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
    case 0xdfd5:
        r16[ax] = memory16get(ds, si);
        memory16set(ds, di, r16[ax]);
        r16[ax] = memory16get(ds, si + 2);
        memory16set(ds, di + 2, r16[ax]);
        di += 0x0004;
        if (--r16[cx]) {
            pc = 0xdfd5;
            break;
        }
        es = pop();
        ds = pop();
        si = pop();
        di = pop();
        bp = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_dfee() {
    yield* sub_dfbf();
    yield* sub_df33();
    r8[al] = memory[es*16 + di + 2];
    r8[bl] = memory[es*16 + di + 3];
    r8[bh] = memory[ds*16 + si];
    r8[cl] = r8[bh];
    r8[bh] += memory[es*16 + di + 4];
    r8[dl] = memory[ds*16 + si + 1];
    r8[dh] = memory[ds*16 + si + 2];
    si += 0x0003;
    push(ds);
    bp = 0x1228;
    ds = bp;
    es = bp;
    bp = 0x68a6;
    di = 0x68b6;
    ds = pop();
}
function* sub_e01d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(r16[ax]);
        push(r16[bx]);
        push(r16[cx]);
        push(r16[dx]);
        push(bp);
        push(di);
        push(si);
        push(ds);
        push(es);
        r8[ch] = 0;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        di += r16[cx];
        r8[cl] = r8[bh];
        r8[cl] &= 0x07;
        r8[al] = 0;
        if (r16[cx] == 0) {
            pc = 0xe05c;
            break;
        }
    case 0xe03d:
        flags.carry = true;
        r8[al] = rcr8(r8[al], 0x01);
        if (--r16[cx]) {
            pc = 0xe03d;
            break;
        }
        r16[cx] = 0x0004;
    case 0xe045:
        if (r8[bl] == 0x00) {
            pc = 0xe05c;
            break;
        }
        r8[bl]--;
    case 0xe04c:
        memory[es*16 + di] = memory[es*16 + di] & r8[al];
        di++;
        if (--r16[cx]) {
            pc = 0xe04c;
            break;
        }
        r16[cx] = 0x0004;
        di -= r16[cx];
        di += 0x0008;
        pc = 0xe045;
        break;
    case 0xe05c:
        es = pop();
        ds = pop();
        si = pop();
        di = pop();
        bp = pop();
        r16[dx] = pop();
        r16[cx] = pop();
        r16[bx] = pop();
        r16[ax] = pop();
        return;
    } while (1);
}
function* sub_e066() {
}
function* sub_e067() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_dfee();
        if (r8[cl] != 0x00) {
            pc = 0xe072;
            break;
        }
        pc = 0xe13d;
        break;
    case 0xe072:
        push(r16[ax]);
        yield* sub_e01d();
        r8[al] = 0x08;
        mul8(r8[dh]);
        r8[ah] = 0;
        di += r16[ax];
        r8[ch] = 0;
        r8[cl]--;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[cx]++;
        r8[dh] = r8[cl];
        push(r16[bx]);
    case 0xe08c:
        if (r8[dl] == 0x00) {
            pc = 0xe0ea;
            break;
        }
        r8[dl]--;
        push(di);
        push(r16[dx]);
    case 0xe095:
        r8[al] = memory[ds*16 + si];
        r8[bl] = r8[al];
        r8[bh] = r8[al];
        r16[ax] = memory16get(es, bp);
        r16[ax] &= r16[bx];
        r16[dx] = r16[ax];
        r16[ax] = memory16get(es, bp + 2);
        r16[ax] &= r16[bx];
        r16[dx] |= r16[ax];
        r8[dh] |= r8[dl];
        r8[dl] = r8[dh];
        r16[dx] = ~dx;
        if (r16[dx] == 0xffff) {
            pc = 0xe0d2;
            break;
        }
        r16[ax] = memory16get(es, bp);
        r16[ax] &= r16[bx];
        memory16set(es, di, memory16get(es, di) & r16[dx]);
        memory16set(es, di, memory16get(es, di) | r16[ax]);
        r16[ax] = memory16get(es, bp + 2);
        r16[ax] &= r16[bx];
        memory16set(es, di + 2, memory16get(es, di + 2) & r16[dx]);
        memory16set(es, di + 2, memory16get(es, di + 2) | r16[ax]);
        pc = 0xe0db;
        break;
    case 0xe0d2:
        r16[bx] = ~bx;
        memory16set(es, di, memory16get(es, di) & r16[bx]);
        memory16set(es, di + 2, memory16get(es, di + 2) & r16[bx]);
    case 0xe0db:
        si++;
        di += 0x0004;
        if (--r16[cx]) {
            pc = 0xe095;
            break;
        }
        r16[dx] = pop();
        r8[cl] = r8[dh];
        di = pop();
        di += 0x0008;
        pc = 0xe08c;
        break;
    case 0xe0ea:
        r16[bx] = pop();
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[dx] = pop();
        r8[dh] = 0;
        r16[dx] = -r16[dx];
        r16[dx] += memory16get(ds, 0x6944);
        r16[ax] = memory16get(ds, 0x6942);
        flags.carry = (memory[ds*16 + 0x6942] + r8[bh]) >= 0x100;
        memory[ds*16 + 0x6942] += r8[bh];
        if (!flags.carry) {
            pc = 0xe108;
            break;
        }
        memory16set(ds, 0x6942, memory16get(ds, 0x6942) + 0x0100);
    case 0xe108:
        yield* sub_df90();
        if (flags.carry) {
            pc = 0xe13d;
            break;
        }
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[dx] <<= 1;
        r16[cx] = r16[dx];
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        r16[cx] += r16[dx];
        r16[dx] = r16[ax];
        r16[dx] &= 0x0007;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[ax] += r16[cx];
        r8[bh]--;
        r8[bh] >>= 1;
        r8[bh] >>= 1;
        r8[bh] >>= 1;
        r8[bh]++;
        r8[cl] = r8[bh];
        r8[ch] = r8[bl];
        r8[bl] = 0x02;
        r8[bh] = 0x28;
        yield* sub_deee();
    case 0xe13d:
        yield* sub_d0bf();
        return;
    } while (1);
}
function* sub_e141() {
}
function* sub_e142() {
}
function* sub_e150() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        bp = 0x1228;
        ds = bp;
        memory16set(ds, 0x4e10, di);
        memory16set(ds, 0x4e0c, di);
        memory16set(ds, 0x4e0e, si);
        memory16set(ds, 0x4e0a, si);
        es = di;
        di = si;
        memory16set(ds, 0x4e14, r16[bx]);
        memory16set(ds, 0x4e2a, r16[bx]);
        memory16set(ds, 0x4e12, r16[ax]);
        memory16set(ds, 0x4e28, r16[ax]);
        r16[bx] = r16[dx];
        r16[ax] = r16[cx];
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4e0c, r16[dx]);
        memory16set(ds, 0x4e0a, r16[ax]);
    case 0xe18c:
        yield* sub_eb59();
        if (!flags.carry) {
            pc = 0xe196;
            break;
        }
        r16[ax] = 0x0003;
        pc = 0xe1c8;
        break;
    case 0xe196:
        push(si);
        push(ds);
        bp = 0x1228;
        ds = bp;
        si = memory16get(ds, 0x4e31);
        si &= 0x7fff;
        si--;
        si <<= 1;
        bp = memory16get(ds, si + 20023);
        ds = pop();
        si = pop();
        yield* callIndirect(cs, bp);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x4e35);
        memory16set(ds, 0x4e2a, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e33);
        memory16set(ds, 0x4e28, r16[ax]);
        if (memory16gets(ds, 0x4e31) > signed16(0x0000)) {
            pc = 0xe18c;
            break;
        }
    case 0xe1c8:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_e1ce() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[dx] = memory16get(ds, 0x4e26);
        memory16set(ds, 0x4e14, r16[dx]);
        r16[ax] = memory16get(ds, 0x4e24);
        memory16set(ds, 0x4e12, r16[ax]);
        memory[ds*16 + 0x4e12] = memory[ds*16 + 0x4e12] & 0xf0;
        if (r16[dx] != memory16get(ds, 0x4e14)) {
            pc = 0xe1ed;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x4e12)) {
            pc = 0xe1f8;
            break;
        }
    case 0xe1ed:
        flags.carry = (memory16get(ds, 0x4e12) + 0x0010) >= 0x10000;
        memory16set(ds, 0x4e12, memory16get(ds, 0x4e12) + 0x0010);
        if (!flags.carry) {
            pc = 0xe1f8;
            break;
        }
        memory16set(ds, 0x4e14, memory16get(ds, 0x4e14) + 1);
    case 0xe1f8:
        r16[ax] = memory16get(ds, 0x4e0c);
        memory16set(ds, 0x4e18, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0a);
        memory16set(ds, 0x4e16, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e18);
        es = r16[ax];
        di = memory16get(ds, 0x4e16);
        r16[bx] = memory16get(ds, 0x4e14);
        r16[ax] = memory16get(ds, 0x4e12);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecb5();
        assert(cs == 0x0e15);
        r8[al] &= 0xfe;
        memory16set(ds, 0x4e08, r16[dx]);
        memory16set(ds, 0x4e06, r16[ax]);
        es = r16[dx];
        di = r16[ax];
        r16[bx] = memory16get(ds, 0x4e14);
        r16[ax] = memory16get(ds, 0x4e12);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4dfc, r16[dx]);
        memory16set(ds, 0x4dfa, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e10);
        es = r16[ax];
        di = memory16get(ds, 0x4e0e);
        r16[bx] = memory16get(ds, 0x4e14);
        r16[ax] = memory16get(ds, 0x4e12);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4df8, r16[dx]);
        memory16set(ds, 0x4df6, r16[ax]);
        es = r16[dx];
        di = r16[ax];
        r16[bx] = 0;
        r16[ax] = 0x0010;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4e00, r16[dx]);
        memory16set(ds, 0x4dfe, r16[ax]);
        if (r16[dx] < memory16get(ds, 0x4dfc)) {
            pc = 0xe285;
            break;
        }
        if (r16[dx] != memory16get(ds, 0x4dfc)) {
            pc = 0xe278;
            break;
        }
        if (r16[ax] <= memory16get(ds, 0x4dfa)) {
            pc = 0xe285;
            break;
        }
    case 0xe278:
        memory16set(ds, 0x4e14, 0x0000);
        memory16set(ds, 0x4e12, 0x0002);
        return;
    case 0xe285:
        r16[cx] = memory16get(ds, 0x4e14);
        r16[bx] = memory16get(ds, 0x4e12);
        r16[ax] = memory16get(ds, 0x4dfc);
        es = r16[ax];
        di = memory16get(ds, 0x4dfa);
        si = memory16get(ds, 0x4df6);
        r16[ax] = memory16get(ds, 0x4df8);
        ds = r16[ax];
    case 0xe29f:
        flags.carry = si < 0x0002;
        si -= 0x0002;
        if (!flags.carry) {
            pc = 0xe2ac;
            break;
        }
        si += 0x0010;
        r16[ax] = ds;
        r16[ax]--;
        ds = r16[ax];
    case 0xe2ac:
        flags.carry = di < 0x0002;
        di -= 0x0002;
        if (!flags.carry) {
            pc = 0xe2b9;
            break;
        }
        di += 0x0010;
        r16[ax] = es;
        r16[ax]--;
        es = r16[ax];
    case 0xe2b9:
        r16[ax] = memory16get(ds, si);
        memory16set(es, di, r16[ax]);
        flags.carry = r16[bx] < 0x0002;
        r16[bx] -= 0x0002;
        if (!flags.carry) {
            pc = 0xe2c7;
            break;
        }
        r16[bx] += 0x0010;
        r16[cx]--;
    case 0xe2c7:
        if (r16[cx] != 0x0000) {
            pc = 0xe29f;
            break;
        }
        if (r16[bx] != 0x0000) {
            pc = 0xe29f;
            break;
        }
        r16[ax] = 0x1228;
        ds = r16[ax];
        memory16set(ds, 0x4e14, 0x0000);
        memory16set(ds, 0x4e12, 0x0001);
        return;
    } while (1);
}
function* sub_e2e3() {
}
function* sub_e2e4() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x4e10);
        es = r16[ax];
        di = memory16get(ds, 0x4e0e);
        r16[bx] = 0;
        r16[ax] = 0x000c;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4e08, r16[dx]);
        memory16set(ds, 0x4e06, r16[ax]);
        es = r16[dx];
        di = r16[ax];
        r8[al] = memory[es*16 + di];
        memory[ds*16 + 0x4e22] = r8[al];
        memory16set(ds, 0x4e06, memory16get(ds, 0x4e06) + 1);
        r16[ax] = memory16get(ds, 0x4e10);
        es = r16[ax];
        di = memory16get(ds, 0x4e0e);
        r16[bx] = memory16get(ds, 0x4e26);
        r16[ax] = memory16get(ds, 0x4e24);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4df8, r16[dx]);
        memory16set(ds, 0x4df6, r16[ax]);
        r16[bx] = memory16get(ds, 0x4e2a);
        r16[ax] = memory16get(ds, 0x4e28);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4dfc, r16[dx]);
        memory16set(ds, 0x4dfa, r16[ax]);
        r16[ax] = 0x1228;
        es = r16[ax];
        di = 0x4e97;
        r16[bx] = 0;
        r16[ax] = 0x0400;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4e04, r16[dx]);
        memory16set(ds, 0x4e02, r16[ax]);
        es = r16[dx];
        di = r16[ax];
        memory16set(ds, 0x4e2f, r16[dx]);
        memory16set(ds, 0x4e2d, r16[ax]);
        si = memory16get(ds, 0x4dfa);
        r16[ax] = memory16get(ds, 0x4dfc);
        ds = r16[ax];
        r16[cx] = 0x0400;
    case 0xe370:
        flags.carry = si < 0x0001;
        si -= 0x0001;
        if (!flags.carry) {
            pc = 0xe37d;
            break;
        }
        si += 0x0010;
        r16[ax] = ds;
        r16[ax]--;
        ds = r16[ax];
    case 0xe37d:
        flags.carry = di < 0x0001;
        di -= 0x0001;
        if (!flags.carry) {
            pc = 0xe38a;
            break;
        }
        di += 0x0010;
        r16[ax] = es;
        r16[ax]--;
        es = r16[ax];
    case 0xe38a:
        r8[al] = memory[ds*16 + si];
        memory[es*16 + di] = r8[al];
        r16[ax] = ds;
        bp = r16[cx];
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[dx] = memory16get(ds, 0x4e08);
        r16[cx] = memory16get(ds, 0x4e06);
        ds = r16[ax];
        if (r16[ax] != r16[dx]) {
            pc = 0xe3aa;
            break;
        }
        if (si == r16[cx]) {
            pc = 0xe3ff;
            break;
        }
    case 0xe3aa:
        r16[cx] = bp;
        if (--r16[cx]) {
            pc = 0xe370;
            break;
        }
        bp = ds;
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x4df8);
        memory16set(ds, 0x4e04, r16[ax]);
        di = memory16get(ds, 0x4df6);
        memory16set(ds, 0x4e02, di);
        es = r16[ax];
        ds = bp;
    case 0xe3c7:
        flags.carry = si < 0x0001;
        si -= 0x0001;
        if (!flags.carry) {
            pc = 0xe3d4;
            break;
        }
        si += 0x0010;
        r16[ax] = ds;
        r16[ax]--;
        ds = r16[ax];
    case 0xe3d4:
        flags.carry = di < 0x0001;
        di -= 0x0001;
        if (!flags.carry) {
            pc = 0xe3e1;
            break;
        }
        di += 0x0010;
        r16[ax] = es;
        r16[ax]--;
        es = r16[ax];
    case 0xe3e1:
        r8[al] = memory[ds*16 + si];
        memory[es*16 + di] = r8[al];
        r16[ax] = ds;
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[dx] = memory16get(ds, 0x4e08);
        r16[cx] = memory16get(ds, 0x4e06);
        ds = r16[ax];
        if (r16[ax] != r16[dx]) {
            pc = 0xe3c7;
            break;
        }
        if (si != r16[cx]) {
            pc = 0xe3c7;
            break;
        }
    case 0xe3ff:
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x4e10);
        memory16set(ds, 0x4e00, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0e);
        memory16set(ds, 0x4dfe, r16[ax]);
        r16[ax] = es;
        ds = r16[ax];
        si = di;
    case 0xe416:
        r8[al] = memory[ds*16 + si];
        bp = ds;
        r16[bx] = 0x1228;
        ds = r16[bx];
        memory[ds*16 + 0x4e2c] = r8[al];
        ds = bp;
        bp = r16[bx];
        si += 0x0001;
        push(di);
        push(bp);
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        ds = r16[dx];
        si = r16[ax];
        es = pop();
        bp = pop();
        di = pop();
        r16[bx] = ds;
        ds = bp;
        r16[dx] = memory16get(ds, 0x4df8);
        r16[cx] = memory16get(ds, 0x4df6);
        ds = r16[bx];
        if (r16[bx] != r16[dx]) {
            pc = 0xe465;
            break;
        }
        if (si != r16[cx]) {
            pc = 0xe465;
            break;
        }
        ds = bp;
        r16[ax] = 0x1228;
        memory16set(ds, 0x4e04, r16[ax]);
        si = 0x4e97;
        memory16set(ds, 0x4e02, si);
        ds = r16[ax];
    case 0xe465:
        bp = ds;
        r16[bx] = 0x1228;
        ds = r16[bx];
        r8[al] = memory[ds*16 + 0x4e22];
        r8[ah] = memory[ds*16 + 0x4e2c];
        ds = bp;
        if (r8[al] == r8[ah]) {
            pc = 0xe47c;
            break;
        }
        pc = 0xe565;
        break;
    case 0xe47c:
        r8[al] = memory[ds*16 + si];
        ds = r16[bx];
        memory[ds*16 + 0x4e1e] = r8[al];
        ds = bp;
        bp = r16[bx];
        si += 0x0001;
        push(di);
        push(bp);
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        ds = r16[dx];
        si = r16[ax];
        es = pop();
        bp = pop();
        di = pop();
        r16[bx] = ds;
        ds = bp;
        r16[dx] = memory16get(ds, 0x4df8);
        r16[cx] = memory16get(ds, 0x4df6);
        ds = r16[bx];
        if (r16[bx] != r16[dx]) {
            pc = 0xe4c6;
            break;
        }
        if (si != r16[cx]) {
            pc = 0xe4c6;
            break;
        }
        ds = bp;
        r16[ax] = 0x1228;
        memory16set(ds, 0x4e04, r16[ax]);
        si = 0x4e97;
        memory16set(ds, 0x4e02, si);
        ds = r16[ax];
    case 0xe4c6:
        bp = ds;
        r16[bx] = 0x1228;
        ds = r16[bx];
        r8[al] = memory[ds*16 + 0x4e22];
        r8[ah] = memory[ds*16 + 0x4e1e];
        ds = bp;
        if (r8[al] != r8[ah]) {
            pc = 0xe4dd;
            break;
        }
        pc = 0xe565;
        break;
    case 0xe4dd:
        r8[al] = memory[ds*16 + si];
        ds = r16[bx];
        memory[ds*16 + 0x4e16] = r8[al];
        ds = bp;
        bp = r16[bx];
        si += 0x0001;
        push(di);
        push(bp);
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        ds = r16[dx];
        si = r16[ax];
        es = pop();
        bp = pop();
        di = pop();
        r16[bx] = ds;
        ds = bp;
        r16[dx] = memory16get(ds, 0x4df8);
        r16[cx] = memory16get(ds, 0x4df6);
        ds = r16[bx];
        if (r16[bx] != r16[dx]) {
            pc = 0xe527;
            break;
        }
        if (si != r16[cx]) {
            pc = 0xe527;
            break;
        }
        ds = bp;
        r16[ax] = 0x1228;
        memory16set(ds, 0x4e04, r16[ax]);
        si = 0x4e97;
        memory16set(ds, 0x4e02, si);
        ds = r16[ax];
    case 0xe527:
        bp = ds;
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[ax] = memory16get(ds, 0x4e00);
        es = r16[ax];
        di = memory16get(ds, 0x4dfe);
        r8[al] = memory[ds*16 + 0x4e1e];
        memory[es*16 + di] = r8[al];
        di += 0x0001;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        es = r16[dx];
        di = r16[ax];
        memory16set(ds, 0x4e00, r16[dx]);
        memory16set(ds, 0x4dfe, r16[ax]);
        if (bp != r16[dx]) {
            pc = 0xe55b;
            break;
        }
        if (si != di) {
            pc = 0xe55b;
            break;
        }
        pc = 0xe5fe;
        break;
    case 0xe55b:
        memory[ds*16 + 0x4e16] -= 1;
        r8[tl] = memory[ds*16 + 0x4e16];
        ds = bp;
        if (r8[tl] != 0) {
            pc = 0xe527;
            break;
        }
        pc = 0xe590;
        break;
    case 0xe565:
        bp = ds;
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x4e00);
        es = r16[ax];
        di = memory16get(ds, 0x4dfe);
        r8[al] = memory[ds*16 + 0x4e2c];
        memory[es*16 + di] = r8[al];
        di += 0x0001;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        es = r16[dx];
        di = r16[ax];
        memory16set(ds, 0x4e00, r16[dx]);
        memory16set(ds, 0x4dfe, r16[ax]);
        ds = bp;
    case 0xe590:
        bp = ds;
        r16[dx] = es;
        if (bp != r16[dx]) {
            pc = 0xe59c;
            break;
        }
        if (si == di) {
            pc = 0xe5fe;
            break;
        }
    case 0xe59c:
        r16[bx] = 0x1228;
        ds = r16[bx];
        r16[dx] = memory16get(ds, 0x4e2f);
        r16[cx] = memory16get(ds, 0x4e2d);
        ds = bp;
        if (bp == r16[dx]) {
            pc = 0xe5b2;
            break;
        }
        pc = 0xe416;
        break;
    case 0xe5b2:
        if (si == r16[cx]) {
            pc = 0xe5b9;
            break;
        }
        pc = 0xe416;
        break;
    case 0xe5b9:
        r16[ax] = 0x1228;
        ds = r16[ax];
        push(di);
        push(es);
        r16[ax] = memory16get(ds, 0x4e26);
        es = r16[ax];
        di = memory16get(ds, 0x4e24);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4e26, r16[dx]);
        memory16set(ds, 0x4e24, r16[ax]);
        es = pop();
        di = pop();
        r16[ax] = memory16get(ds, 0x4e0e);
        flags.carry = di < r16[ax];
        di -= r16[ax];
        if (!flags.carry) {
            pc = 0xe5e6;
            break;
        }
        di += 0x0010;
        r16[ax] = es;
        r16[ax]--;
        es = r16[ax];
    case 0xe5e6:
        r16[bx] = memory16get(ds, 0x4e10);
        r16[ax] = es;
        r16[ax] -= r16[bx];
        if (r16[ax] != memory16get(ds, 0x4e26))
            return;
        if (di != memory16get(ds, 0x4e24))
            return;
        r16[ax] = 0x0001;
        return;
    case 0xe5fe:
        return;
    } while (1);
}
function* sub_e600() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0xe600;
        break;
    case 0xe5fe:
        return;
    case 0xe600:
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = memory16get(ds, 0x4e10);
        es = r16[ax];
        di = memory16get(ds, 0x4e0e);
        r16[bx] = memory16get(ds, 0x4e26);
        r16[ax] = memory16get(ds, 0x4e24);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        if (r16[dx] > memory16get(ds, 0x4e0c)) {
            pc = 0xe5fe;
            break;
        }
        if (r16[dx] != memory16get(ds, 0x4e0c)) {
            pc = 0xe628;
            break;
        }
        if (r16[ax] > memory16get(ds, 0x4e0a)) {
            pc = 0xe5fe;
            break;
        }
    case 0xe628:
        r16[ax] = memory16get(ds, 0x4e10);
        es = r16[ax];
        di = memory16get(ds, 0x4e0e);
        r16[bx] = 0;
        r16[ax] = 0x000c;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4df8, r16[dx]);
        memory16set(ds, 0x4df6, r16[ax]);
        es = r16[dx];
        di = r16[ax];
        r16[ax] = memory16get(es, di);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        memory16set(ds, 0x4e22, r16[ax]);
        memory16set(ds, 0x4df6, memory16get(ds, 0x4df6) + 0x0002);
        r16[dx] = memory16get(ds, 0x4e26);
        memory16set(ds, 0x4e20, r16[dx]);
        r16[ax] = memory16get(ds, 0x4e24);
        memory16set(ds, 0x4e1e, r16[ax]);
        memory[ds*16 + 0x4e1e] = memory[ds*16 + 0x4e1e] & 0xe0;
        if (r16[dx] != memory16get(ds, 0x4e20)) {
            pc = 0xe679;
            break;
        }
        if (r16[ax] == memory16get(ds, 0x4e1e)) {
            pc = 0xe67f;
            break;
        }
        r16[dx] = memory16get(ds, 0x4e20);
        r16[ax] = memory16get(ds, 0x4e1e);
    case 0xe679:
        flags.carry = (r16[ax] + 0x0020) >= 0x10000;
        r16[ax] += 0x0020;
        if (!flags.carry) {
            pc = 0xe67f;
            break;
        }
        r16[dx]++;
    case 0xe67f:
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        memory16set(ds, 0x4e20, r16[dx]);
        memory16set(ds, 0x4e1e, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0c);
        memory16set(ds, 0x4e18, r16[ax]);
        di = memory16get(ds, 0x4e0a);
        memory16set(ds, 0x4e16, di);
        es = r16[ax];
        r16[bx] = memory16get(ds, 0x4e20);
        r16[ax] = memory16get(ds, 0x4e1e);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecb5();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4e18, r16[dx]);
        memory16set(ds, 0x4e16, r16[ax]);
        memory[ds*16 + 0x4e16] = memory[ds*16 + 0x4e16] & 0xfe;
        r16[dx] = memory16get(ds, 0x4e18);
        memory16set(ds, 0x4dfc, r16[dx]);
        r16[ax] = memory16get(ds, 0x4e16);
        memory16set(ds, 0x4dfa, r16[ax]);
        memory16set(ds, 0x4e00, r16[dx]);
        memory16set(ds, 0x4dfe, r16[ax]);
        es = r16[dx];
        di = r16[ax];
        r16[ax] = memory16get(ds, 0x4e20);
        memory16set(ds, 0x4e18, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e1e);
        memory16set(ds, 0x4e16, r16[ax]);
        si = memory16get(ds, 0x4df6);
        r16[ax] = memory16get(ds, 0x4df8);
        ds = r16[ax];
    case 0xe6e8:
        r16[ax] = memory16get(ds, si + 2);
        memory16set(es, di + 2, r16[ax]);
        r16[ax] = memory16get(ds, si);
        memory16set(es, di, r16[ax]);
        si += 0x0004;
        push(di);
        push(bp);
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        ds = r16[dx];
        si = r16[ax];
        es = pop();
        bp = pop();
        di = pop();
        bp = ds;
        di += 0x0004;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        es = r16[dx];
        di = r16[ax];
        r16[ax] = 0x1228;
        ds = r16[ax];
        push(di);
        push(es);
        r16[ax] = memory16get(ds, 0x4e18);
        es = r16[ax];
        di = memory16get(ds, 0x4e16);
        r16[bx] = 0;
        r16[ax] = 0x0004;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecb5();
        assert(cs == 0x0e15);
        es = pop();
        di = pop();
        memory16set(ds, 0x4e18, r16[dx]);
        memory16set(ds, 0x4e16, r16[ax]);
        ds = bp;
        if (r16[dx] != 0x0000) {
            pc = 0xe6e8;
            break;
        }
        if (r16[ax] != 0x0000) {
            pc = 0xe6e8;
            break;
        }
        r16[ax] = 0x1228;
        ds = r16[ax];
        memory16set(ds, 0x4df8, bp);
        memory16set(ds, 0x4df6, si);
        r16[ax] = es;
        memory16set(ds, 0x4e00, r16[ax]);
        memory16set(ds, 0x4dfe, di);
        r16[ax] = memory16get(ds, 0x4e26);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e24);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4dfc);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4dfa);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0c);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0a);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4dfc);
        memory16set(ds, 0x4e0c, r16[ax]);
        r16[ax] = memory16get(ds, 0x4dfa);
        memory16set(ds, 0x4e0a, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e2a);
        memory16set(ds, 0x4e26, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e28);
        memory16set(ds, 0x4e24, r16[ax]);
        yield* sub_e1ce();
        r16[ax] = pop();
        memory16set(ds, 0x4e0a, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e0c, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4dfa, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4dfc, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e24, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e26, r16[ax]);
        if (memory16get(ds, 0x4e14) != 0x0000) {
            pc = 0xe7bb;
            break;
        }
        if (memory16get(ds, 0x4e12) != 0x0002) {
            pc = 0xe7bb;
            break;
        }
        pc = 0xe5fe;
        break;
    case 0xe7bb:
        r16[ax] = memory16get(ds, 0x4e26);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e24);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e2a);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e28);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0c);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0a);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e08);
        es = r16[ax];
        di = memory16get(ds, 0x4e06);
        r16[bx] = memory16get(ds, 0x4e2a);
        r16[ax] = memory16get(ds, 0x4e28);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4e04, r16[dx]);
        memory16set(ds, 0x4e02, r16[ax]);
        r16[bx] = memory16get(ds, 0x4e20);
        r16[ax] = memory16get(ds, 0x4e1e);
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        es = r16[dx];
        di = r16[ax];
        r16[bx] = 0;
        r16[ax] = 0x000e;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ec70();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4e08, r16[dx]);
        memory16set(ds, 0x4e06, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0c);
        memory16set(ds, 0x4e00, r16[ax]);
        di = memory16get(ds, 0x4e0a);
        memory16set(ds, 0x4dfe, di);
        es = r16[ax];
        r16[bx] = 0;
        r16[ax] = 0x0400;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecb5();
        assert(cs == 0x0e15);
        memory16set(ds, 0x4e00, r16[dx]);
        memory16set(ds, 0x4dfe, r16[ax]);
        r16[ax] = memory16get(ds, 0x4dfc);
        memory16set(ds, 0x4e0c, r16[ax]);
        r16[ax] = memory16get(ds, 0x4dfa);
        memory16set(ds, 0x4e0a, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e10);
        memory16set(ds, 0x4df8, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0e);
        memory16set(ds, 0x4df6, r16[ax]);
        memory16set(ds, 0x4e1c, 0x0000);
        memory16set(ds, 0x4e1a, 0x0000);
        memory16set(ds, 0x4e14, 0x0000);
        memory16set(ds, 0x4e12, 0x0000);
        memory16set(ds, 0x4e18, 0x0000);
        memory16set(ds, 0x4e16, 0x0000);
    case 0xe86d:
        memory16set(ds, 0x4e16, memory16get(ds, 0x4e16) - 0x0001);
        if (memory16gets(ds, 0x4e16) >= 0) {
            pc = 0xe8c2;
            break;
        }
        bp = ds;
        si = memory16get(ds, 0x4e0a);
        r16[ax] = memory16get(ds, 0x4e0c);
        ds = r16[ax];
        r16[dx] = memory16get(ds, si + 2);
        r8[tl] = r8[dl];
        r8[dl] = r8[dh];
        r8[dh] = r8[tl];
        r16[ax] = memory16get(ds, si);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        push(r16[ax]);
        push(r16[dx]);
        si += 0x0004;
        push(di);
        push(bp);
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        ds = r16[dx];
        si = r16[ax];
        es = pop();
        bp = pop();
        di = pop();
        r16[dx] = pop();
        r16[ax] = pop();
        r16[cx] = ds;
        ds = bp;
        memory16set(ds, 0x4e0c, r16[cx]);
        memory16set(ds, 0x4e0a, si);
        memory16set(ds, 0x4e16, 0x001f);
        memory16set(ds, 0x4e26, r16[ax]);
        memory16set(ds, 0x4e24, r16[dx]);
    case 0xe8c2:
        r16[dx] = memory16get(ds, 0x4e26);
        r16[ax] = memory16get(ds, 0x4e24);
        flags.carry = !!(r16[ax] & 0x8000);
        r16[ax] <<= 1;
        r16[dx] = rcl16(r16[dx], 0x0001);
        memory16set(ds, 0x4e26, r16[dx]);
        memory16set(ds, 0x4e24, r16[ax]);
        if (!flags.carry) {
            pc = 0xe8d9;
            break;
        }
        pc = 0xea27;
        break;
    case 0xe8d9:
        r16[ax] = memory16get(ds, 0x4df8);
        es = r16[ax];
        di = memory16get(ds, 0x4df6);
        si = memory16get(ds, 0x4e06);
        r16[ax] = memory16get(ds, 0x4e08);
        ds = r16[ax];
        r8[al] = memory[ds*16 + si];
        memory[es*16 + di] = r8[al];
        si += 0x0001;
        push(di);
        push(bp);
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        ds = r16[dx];
        si = r16[ax];
        es = pop();
        bp = pop();
        di = pop();
        bp = ds;
        di += 0x0001;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        es = r16[dx];
        di = r16[ax];
        r16[ax] = 0x1228;
        ds = r16[ax];
        memory16set(ds, 0x4e08, bp);
        memory16set(ds, 0x4e06, si);
        r16[ax] = es;
        memory16set(ds, 0x4df8, r16[ax]);
        memory16set(ds, 0x4df6, di);
        flags.carry = (memory16get(ds, 0x4e12) + 0x0001) >= 0x10000;
        memory16set(ds, 0x4e12, memory16get(ds, 0x4e12) + 0x0001);
        if (!flags.carry) {
            pc = 0xe937;
            break;
        }
        memory16set(ds, 0x4e14, memory16get(ds, 0x4e14) + 1);
    case 0xe937:
        r16[dx] = memory16get(ds, 0x4e00);
        r16[ax] = memory16get(ds, 0x4dfe);
        if (r16[dx] != memory16get(ds, 0x4df8)) {
            pc = 0xe962;
            break;
        }
        if (r16[ax] != memory16get(ds, 0x4df6)) {
            pc = 0xe962;
            break;
        }
        r16[ax] = 0x1228;
        memory16set(ds, 0x4df8, r16[ax]);
        r16[ax] = 0x4e97;
        memory16set(ds, 0x4df6, r16[ax]);
        memory16set(ds, 0x4e1c, 0x0000);
        memory16set(ds, 0x4e1a, 0x0001);
    case 0xe962:
        r16[dx] = memory16get(ds, 0x4e08);
        r16[ax] = memory16get(ds, 0x4e06);
        if (r16[dx] != memory16get(ds, 0x4e04)) {
            pc = 0xe978;
            break;
        }
        if (r16[ax] != memory16get(ds, 0x4e02)) {
            pc = 0xe978;
            break;
        }
        pc = 0xea84;
        break;
    case 0xe978:
        r16[dx] = memory16get(ds, 0x4e08);
        r16[ax] = memory16get(ds, 0x4e06);
        if (r16[dx] <= memory16get(ds, 0x4df8)) {
            pc = 0xe988;
            break;
        }
        pc = 0xe86d;
        break;
    case 0xe988:
        if (r16[dx] != memory16get(ds, 0x4df8)) {
            pc = 0xe993;
            break;
        }
        if (r16[ax] <= memory16get(ds, 0x4df6)) {
            pc = 0xe993;
            break;
        }
        pc = 0xe86d;
        break;
    case 0xe993:
        if (memory16get(ds, 0x4e1c) == 0x0000) {
            pc = 0xe99d;
            break;
        }
        pc = 0xe86d;
        break;
    case 0xe99d:
        if (memory16get(ds, 0x4e1a) == 0x0000) {
            pc = 0xe9a7;
            break;
        }
        pc = 0xe86d;
        break;
    case 0xe9a7:
        r16[ax] = memory16get(ds, 0x4e0c);
        memory16set(ds, 0x4dfc, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0a);
        memory16set(ds, 0x4dfa, r16[ax]);
        r16[dx] = memory16get(ds, 0x4e08);
        r16[cx] = memory16get(ds, 0x4e06);
        r16[ax] = memory16get(ds, 0x4dfc);
        es = r16[ax];
        di = memory16get(ds, 0x4dfa);
        si = memory16get(ds, 0x4e02);
        r16[ax] = memory16get(ds, 0x4e04);
        ds = r16[ax];
    case 0xe9cd:
        flags.carry = si < 0x0001;
        si -= 0x0001;
        if (!flags.carry) {
            pc = 0xe9da;
            break;
        }
        si += 0x0010;
        r16[ax] = ds;
        r16[ax]--;
        ds = r16[ax];
    case 0xe9da:
        flags.carry = di < 0x0001;
        di -= 0x0001;
        if (!flags.carry) {
            pc = 0xe9e7;
            break;
        }
        di += 0x0010;
        r16[ax] = es;
        r16[ax]--;
        es = r16[ax];
    case 0xe9e7:
        r8[al] = memory[ds*16 + si];
        memory[es*16 + di] = r8[al];
        r16[ax] = ds;
        if (r16[dx] != r16[ax]) {
            pc = 0xe9cd;
            break;
        }
        if (r16[cx] != si) {
            pc = 0xe9cd;
            break;
        }
        r16[ax] = 0x1228;
        ds = r16[ax];
        memory16set(ds, 0x4e04, bp);
        memory16set(ds, 0x4e02, si);
        r16[ax] = es;
        memory16set(ds, 0x4dfc, r16[ax]);
        memory16set(ds, 0x4dfa, di);
        r16[ax] = memory16get(ds, 0x4dfc);
        memory16set(ds, 0x4e08, r16[ax]);
        r16[ax] = memory16get(ds, 0x4dfa);
        memory16set(ds, 0x4e06, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0c);
        memory16set(ds, 0x4e04, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0a);
        memory16set(ds, 0x4e02, r16[ax]);
        pc = 0xe86d;
        break;
    case 0xea27:
        r16[ax] = memory16get(ds, 0x4df8);
        es = r16[ax];
        di = memory16get(ds, 0x4df6);
        r8[al] = memory[ds*16 + 0x4e22];
        memory[es*16 + di] = r8[al];
        di += 0x0001;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        es = r16[dx];
        di = r16[ax];
        r16[ax] = es;
        memory16set(ds, 0x4df8, r16[ax]);
        memory16set(ds, 0x4df6, di);
        flags.carry = (memory16get(ds, 0x4e12) + 0x0001) >= 0x10000;
        memory16set(ds, 0x4e12, memory16get(ds, 0x4e12) + 0x0001);
        if (!flags.carry) {
            pc = 0xea56;
            break;
        }
        memory16set(ds, 0x4e14, memory16get(ds, 0x4e14) + 1);
    case 0xea56:
        r16[dx] = memory16get(ds, 0x4e00);
        r16[ax] = memory16get(ds, 0x4dfe);
        if (r16[dx] != memory16get(ds, 0x4df8)) {
            pc = 0xea81;
            break;
        }
        if (r16[ax] != memory16get(ds, 0x4df6)) {
            pc = 0xea81;
            break;
        }
        r16[ax] = 0x1228;
        memory16set(ds, 0x4df8, r16[ax]);
        r16[ax] = 0x4e97;
        memory16set(ds, 0x4df6, r16[ax]);
        memory16set(ds, 0x4e1c, 0x0000);
        memory16set(ds, 0x4e1a, 0x0001);
    case 0xea81:
        pc = 0xe978;
        break;
    case 0xea84:
        r16[ax] = pop();
        memory16set(ds, 0x4e0a, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e0c, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e28, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e2a, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e24, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e26, r16[ax]);
    case 0xea9c:
        r8[al] = memory[ds*16 + 0x4e22];
        memory[es*16 + di] = r8[al];
        di += 0x0001;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        es = r16[dx];
        di = r16[ax];
        flags.carry = (memory16get(ds, 0x4e12) + 0x0001) >= 0x10000;
        memory16set(ds, 0x4e12, memory16get(ds, 0x4e12) + 0x0001);
        if (!flags.carry) {
            pc = 0xeab9;
            break;
        }
        memory16set(ds, 0x4e14, memory16get(ds, 0x4e14) + 1);
    case 0xeab9:
        r16[dx] = memory16get(ds, 0x4e00);
        r16[ax] = memory16get(ds, 0x4dfe);
        if (r16[dx] != memory16get(ds, 0x4df8)) {
            pc = 0xeae4;
            break;
        }
        if (r16[ax] != memory16get(ds, 0x4df6)) {
            pc = 0xeae4;
            break;
        }
        r16[ax] = 0x1228;
        memory16set(ds, 0x4df8, r16[ax]);
        r16[ax] = 0x4e97;
        memory16set(ds, 0x4df6, r16[ax]);
        memory16set(ds, 0x4e1c, 0x0000);
        memory16set(ds, 0x4e1a, 0x0001);
    case 0xeae4:
        r16[dx] = memory16get(ds, 0x4e26);
        r16[ax] = memory16get(ds, 0x4e24);
        if (r16[dx] > memory16get(ds, 0x4e14)) {
            pc = 0xea9c;
            break;
        }
        if (r16[dx] != memory16get(ds, 0x4e14)) {
            pc = 0xeaf9;
            break;
        }
        if (r16[ax] > memory16get(ds, 0x4e12)) {
            pc = 0xea9c;
            break;
        }
    case 0xeaf9:
        r16[ax] = 0x1228;
        memory16set(ds, 0x4df8, r16[ax]);
        r16[ax] = 0x4e97;
        memory16set(ds, 0x4df6, r16[ax]);
        r16[cx] = 0x0400;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
        r16[ax] = memory16get(ds, 0x4e00);
        es = r16[ax];
        di = memory16get(ds, 0x4dfe);
        si = memory16get(ds, 0x4df6);
        r16[ax] = memory16get(ds, 0x4df8);
        ds = r16[ax];
    case 0xeb1e:
        r16[ax] = memory16get(ds, si + 2);
        memory16set(es, di + 2, r16[ax]);
        r16[ax] = memory16get(ds, si);
        memory16set(es, di, r16[ax]);
        si += 0x0004;
        push(di);
        push(bp);
        push(es);
        r16[ax] = ds;
        es = r16[ax];
        di = si;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        ds = r16[dx];
        si = r16[ax];
        es = pop();
        bp = pop();
        di = pop();
        di += 0x0004;
        push(cs);
        cs = 0x0ec7;
        yield* sub_ecf9();
        assert(cs == 0x0e15);
        es = r16[dx];
        di = r16[ax];
        if (--r16[cx]) {
            pc = 0xeb1e;
            break;
        }
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = 0x0001;
        return;
    } while (1);
}
function* sub_eb59() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[ax] = memory16get(ds, 0x4e2a);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e28);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0c);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0a);
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e10);
        es = r16[ax];
        push(r16[ax]);
        r16[ax] = memory16get(ds, 0x4e0e);
        di = r16[ax];
        push(r16[ax]);
        r16[ax] = memory16get(es, di);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        r16[bx] = memory16get(es, di + 2);
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        memory16set(ds, 0x4e26, r16[ax]);
        memory16set(ds, 0x4e24, r16[bx]);
        memory16set(ds, 0x4e35, r16[ax]);
        memory16set(ds, 0x4e33, r16[bx]);
        if (r16[ax] > 0x000f) {
            pc = 0xec06;
            break;
        }
        if (r16[ax] != 0x000f) {
            pc = 0xeba0;
            break;
        }
        if (r16[bx] > 0xffff) {
            pc = 0xec06;
            break;
        }
    case 0xeba0:
        r16[ax] = memory16get(es, di + 6);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        r16[bx] = memory16get(es, di + 4);
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        memory16set(ds, 0x4e20, r16[ax]);
        memory16set(ds, 0x4e1e, r16[bx]);
        r16[ax] = memory16get(es, di + 8);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        memory16set(ds, 0x4e31, r16[ax]);
        si = r16[ax];
        si &= 0x003f;
        if (si > 0x001e) {
            pc = 0xec06;
            break;
        }
        si += si;
        r16[bx] = memory16get(ds, si + 20059);
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        if (r16s[bx] < signed16(0x0000)) {
            pc = 0xec06;
            break;
        }
        si = r16[ax];
        si &= 0x7f00;
        if (si != 0) {
            pc = 0xec06;
            break;
        }
        r16[bx] = memory16get(ds, 0x4e26);
        r16[ax] = memory16get(ds, 0x4e24);
        si = memory16get(ds, 0x4e31);
        si ^= r16[bx];
        si ^= r16[ax];
        memory16set(ds, 0x4e26, r16[bx]);
        memory16set(ds, 0x4e24, r16[ax]);
        r16[ax] = memory16get(ds, 0x4e20);
        r16[bx] = memory16get(ds, 0x4e1e);
        si ^= r16[bx];
        si ^= r16[ax];
        r16[ax] = memory16get(es, di + 10);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        flags.carry = si < r16[ax];
        if (si == r16[ax]) {
            pc = 0xec07;
            break;
        }
    case 0xec06:
        flags.carry = true;
    case 0xec07:
        r16[ax] = pop();
        memory16set(ds, 0x4e0e, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e10, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e0a, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e0c, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e28, r16[ax]);
        r16[ax] = pop();
        memory16set(ds, 0x4e2a, r16[ax]);
        return;
    } while (1);
}
function* sub_ec20() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        flags.carry = (r16[ax] + 0x000f) >= 0x10000;
        r16[ax] += 0x000f;
        if (!flags.carry) {
            pc = 0xec2b;
            break;
        }
        r16[dx]++;
    case 0xec2b:
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[dx] & 1;
        r16[dx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        r16[bx] = r16[ax];
        r8[ah] = 0x48;
        interrupt(0x21);
        if (flags.carry) {
            pc = 0xec48;
            break;
        }
        r16[dx] = 0;
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
        pc = 0xec4c;
        break;
    case 0xec48:
        r16[dx] = 0;
        r16[ax] = 0;
    case 0xec4c:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_ec52() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    es = r16[ax];
    r8[ah] = 0x49;
    interrupt(0x21);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_ec70() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        bp = 0x1228;
        ds = bp;
        push(r16[ax]);
        push(r16[bx]);
        push(cs);
        yield* sub_ecf9();
        es = r16[dx];
        di = r16[ax];
        r16[bx] = pop();
        r16[ax] = pop();
        r16[cx] = r16[ax];
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        r16[bx] = r16[cx];
        r16[bx] &= 0x000f;
        r16[bx] += di;
        r16[dx] = r16[bx];
        r16[bx] = es;
        r16[ax] += r16[bx];
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
        if (r16s[ax] <= signed16(0x000f)) {
            pc = 0xecaf;
            break;
        }
        r16[ax] &= 0x000f;
        r16[dx]++;
    case 0xecaf:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_ecb5() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        bp = 0x1228;
        ds = bp;
        push(r16[ax]);
        push(r16[bx]);
        push(cs);
        yield* sub_ecf9();
        es = r16[dx];
        di = r16[ax];
        r16[bx] = pop();
        r16[ax] = pop();
        r16[cx] = r16[ax];
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        flags.carry = r16[bx] & 1;
        r16[bx] >>= 1;
        r16[ax] = rcr16(r16[ax], 0x0001);
        r16[bx] = r16[cx];
        r16[bx] &= 0x000f;
        flags.carry = di < r16[bx];
        di -= r16[bx];
        if (!flags.carry) {
            pc = 0xecea;
            break;
        }
        di += 0x0010;
        r16[ax]++;
    case 0xecea:
        r16[dx] = di;
        r16[bx] = es;
        r16[bx] -= r16[ax];
        r16[ax] = r16[bx];
        r16[tx] = r16[dx];
        r16[dx] = r16[ax];
        r16[ax] = r16[tx];
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_ecf9() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[ax] = di;
    di &= 0x000f;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[bx] = es;
    r16[ax] += r16[bx];
    r16[dx] = r16[ax];
    r16[ax] = di;
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_ed20() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = 0x1228;
    ds = r16[bx];
    memory16set(ds, 0x5676, r16[ax]);
    memory16set(ds, 0x5678, 0x0000);
    memory16set(ds, 0x567a, 0x0000);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_ed3f() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] = memory16get(ds, 0x5678);
    bp = memory16get(ds, 0x567a);
    r16[ax] = bp;
    r16[ax] += 0x2432;
    r16[ax] ^= r16[bx];
    r16[ax] ^= memory16get(ds, 0x5676);
    bp = r16[ax];
    r16[ax] = ror16(r16[ax], 0x0001);
    r16[ax] -= memory16get(ds, 0x5676);
    r16[ax] ^= r16[bx];
    r16[ax] += 0x1c12;
    r16[ax] ^= bp;
    r16[ax] = ror16(r16[ax], 0x0001);
    flags.carry = (r16[ax] + bp) >= 0x10000;
    r16[ax] += bp;
    r16[ax] = rcr16(r16[ax], 0x0001);
    r16[bx] = r16[ax];
    r16[ax] = memory16get(ds, 0x5676);
    r16[ax] += bp;
    r16[ax] ^= 0x3812;
    r16[ax] ^= r16[bx];
    memory16set(ds, 0x5676, r16[ax]);
    memory16set(ds, 0x5678, r16[bx]);
    memory16set(ds, 0x567a, bp);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_f9c4() {
    var pc = 0;
    do switch (pc) {
    case 0:
    case 0xf9c4:
        r16[ax] = es;
        r16[bx] = memory16get(es, di);
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        r16[bx] = ror16(r16[bx], 0x0001);
        r16[bx] = ror16(r16[bx], 0x0001);
        r16[bx] = ror16(r16[bx], 0x0001);
        r16[bx] = ror16(r16[bx], 0x0001);
        r16[ax] += r16[bx];
        r16[cx] = r16[bx];
        r16[bx] = memory16get(es, di + 2);
        r16[cx] |= r16[bx];
        if (!r16[cx])
            return;
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        r16[cx] = r16[bx];
        r16[cx] &= 0x000f;
        r16[cx] += 0x0800;
        r16[bx] &= 0xfff0;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[bx] >>= 1;
        r16[ax] += r16[bx];
        memory16set(es, di + 2, r16[ax]);
        memory16set(es, di, r16[cx]);
        yield* sub_fa07();
        di += 0x0004;
        pc = 0xf9c4;
        break;
        return;
    } while (1);
}
function* sub_fa07() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(ds);
        push(di);
        push(si);
        push(r16[ax]);
        push(r16[cx]);
        r16[ax] = memory16get(ds, 0x541d);
        memory16set(cs, 0x0ded, r16[ax]);
        r16[tx] = di;
        di = memory16get(es, r16[tx]);
        ds = memory16get(es, r16[tx] + 2);
        r16[cx] = memory16get(ds, di - 2);
        r8[tl] = r8[cl];
        r8[cl] = r8[ch];
        r8[ch] = r8[tl];
        memory16set(ds, di - 2, r16[cx]);
        if (r16s[cx] < 0) {
            pc = 0xfa26;
            break;
        }
        if (r16[cx] == 0) {
            pc = 0xfa26;
            break;
        }
        pc = 0xfa29;
        break;
    case 0xfa26:
        pc = 0xfb77;
        break;
    case 0xfa29:
        r16[ax] = memory16get(ds, di - 4);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        memory16set(ds, di - 4, r16[ax]);
        r16[ax] = memory16get(ds, di - 6);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        memory16set(ds, di - 6, r16[ax]);
        r16[ax] = memory16get(ds, di - 8);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        memory16set(ds, di - 8, r16[ax]);
        r16[ax] = memory16get(ds, di - 12);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        memory16set(ds, di - 12, r16[ax]);
        r16[ax] = memory16get(ds, di - 10);
        r8[tl] = r8[ah];
        r8[ah] = r8[al];
        r8[al] = r8[tl];
        memory16set(ds, di - 10, r16[ax]);
        r8[al] &= 0xc0;
        if (r8[al] != 0) {
            pc = 0xfa26;
            break;
        }
        si = di;
        r16[ax] = memory16get(cs, 0x0ded);
        if (r16[ax] == 0x0000) {
            pc = 0xfa63;
            break;
        }
        pc = 0xfb3c;
        break;
    case 0xfa63:
        r16[ax] = memory16get(ds, di - 4);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[dx] = r16[ax];
        if (r16s[dx] < 0) {
            pc = 0xfa26;
            break;
        }
        if (r16[dx] == 0) {
            pc = 0xfa26;
            break;
        }
    case 0xfa72:
        r8[al] = memory[ds*16 + si + 2];
        r8[ah] = memory[ds*16 + si + 1];
        memory[ds*16 + si + 1] = r8[al];
        r8[al] = memory[ds*16 + si + 4];
        memory[ds*16 + si + 4] = r8[ah];
        memory[ds*16 + si + 2] = r8[al];
        r8[al] = memory[ds*16 + si + 6];
        r8[ah] = memory[ds*16 + si + 3];
        memory[ds*16 + si + 3] = r8[al];
        r8[al] = memory[ds*16 + si + 5];
        memory[ds*16 + si + 5] = r8[ah];
        memory[ds*16 + si + 6] = r8[al];
        r16[ax] = memory16get(ds, si);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        memory16set(ds, si, r16[bx]);
        r16[ax] = memory16get(ds, si + 4);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[al] & 0x80);
        r8[al] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        flags.carry = !!(r8[ah] & 0x80);
        r8[ah] <<= 1;
        r16[bx] = rcl16(r16[bx], 0x0001);
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        memory16set(ds, si + 4, r16[bx]);
        r16[ax] = 0;
        memory16set(ds, si + 2, r16[ax]);
        memory16set(ds, si + 6, r16[ax]);
        si += 0x0008;
        r16[dx]--;
        if (r16[dx] != 0) {
            pc = 0xfb36;
            break;
        }
        if (--r16[cx]) {
            pc = 0xfb39;
            break;
        }
        pc = 0xfb77;
        break;
    case 0xfb36:
        pc = 0xfa72;
        break;
    case 0xfb39:
        pc = 0xfa63;
        break;
    case 0xfb3c:
        r16[ax] = memory16get(ds, di - 4);
        r16[ax] >>= 1;
        r16[ax] >>= 1;
        r16[dx] = r16[ax];
        if (r16s[dx] < 0) {
            pc = 0xfb77;
            break;
        }
        if (r16[dx] == 0) {
            pc = 0xfb77;
            break;
        }
    case 0xfb4b:
        r8[al] = memory[ds*16 + si + 2];
        r8[ah] = memory[ds*16 + si + 1];
        memory[ds*16 + si + 1] = r8[al];
        r8[al] = memory[ds*16 + si + 4];
        memory[ds*16 + si + 4] = r8[ah];
        memory[ds*16 + si + 2] = r8[al];
        r8[al] = memory[ds*16 + si + 6];
        r8[ah] = memory[ds*16 + si + 3];
        memory[ds*16 + si + 3] = r8[al];
        r8[al] = memory[ds*16 + si + 5];
        memory[ds*16 + si + 5] = r8[ah];
        memory[ds*16 + si + 6] = r8[al];
        si += 0x0008;
        r16[dx]--;
        if (r16[dx] != 0) {
            pc = 0xfb4b;
            break;
        }
        if (--r16[cx]) {
            pc = 0xfb3c;
            break;
        }
    case 0xfb77:
        r16[cx] = pop();
        r16[ax] = pop();
        si = pop();
        di = pop();
        ds = pop();
        return;
    } while (1);
}
function* sub_fb7f() {
    r16[ax] = memory16get(ss, bp + 4);
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] >>= 1;
    r16[ax] &= 0xfffe;
    memory16set(ds, 0x680d, r16[ax]);
    r16[dx] = memory16get(ss, bp + 8);
    r16[dx]++;
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[dx] >>= 1;
    r16[dx] &= 0xfffe;
    memory16set(ds, 0x680f, r16[dx]);
    r16[dx] -= r16[ax];
    memory16set(ds, 0x6815, r16[dx]);
    r16[ax] = memory16get(ss, bp + 6);
    memory16set(ds, 0x6811, r16[ax]);
    r16[dx] = memory16get(ss, bp + 10);
    memory16set(ds, 0x6813, r16[dx]);
    r16[dx] -= r16[ax];
    memory16set(ds, 0x6817, r16[dx]);
}
function* sub_fbb9() {
    r16[bx] = memory16get(ss, bp + 4);
    es = memory16get(ss, bp + 4 + 2);
    if (!r16[bx])
        return;
    yield* sub_fbc4();
}
function* sub_fbc4() {
    memory16set(ds, 0x6809, r16[bx]);
    si = es;
    memory16set(ds, 0x680b, si);
    r16[ax] = r16[bx];
    r16[ax] |= si;
    if (!r16[ax])
        return;
    yield* sub_fbd8();
}
function* sub_fbd8() {
    var pc = 0;
    do switch (pc) {
    case 0:
        r16[bx] = memory16get(ds, 0x6809);
        es = memory16get(ds, 0x6809 + 2);
    case 0xfbdc:
        push(es);
        di = memory16get(es, r16[bx]);
        es = memory16get(es, r16[bx] + 2);
        r16[ax] = es;
        r16[ax] |= di;
        if (!r16[ax]) {
            pc = 0xfbe9;
            break;
        }
        push(r16[bx]);
        pc = 0xfbef;
        break;
    case 0xfbe9:
        pc = 0xfc8f;
        break;
    case 0xfbec:
        pc = 0xfc87;
        break;
    case 0xfbef:
        r8[al] = memory[es*16 + di + 10];
        if (!(r8[al] & 0x80)) {
            pc = 0xfbec;
            break;
        }
        r16[ax] = memory16get(es, di);
        if (!(memory[es*16 + di + 10] & 0x20)) {
            pc = 0xfc11;
            break;
        }
        r16[bx] = memory16get(es, di + 16);
        r16[bx] <<= 1;
        r16[bx] <<= 1;
        r16[ax] -= r16[bx];
        r16[ax] += memory16get(es, di + 20);
        pc = 0xfc15;
        break;
    case 0xfc11:
        r16[ax] -= memory16get(es, di + 20);
    case 0xfc15:
        if (!(memory[es*16 + di + 10] & 0x01)) {
            pc = 0xfc22;
            break;
        }
        r16[ax] += 0x0004;
        r16[ax] &= 0xfff8;
    case 0xfc22:
        r16[bx] = r16[ax];
        r16[bx] &= 0x0007;
        memory[cs*16 + 0x3216] = r8[bl];
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        r16[ax] = sar16(r16[ax], 1);
        memory16set(ds, 0x6821, r16[ax]);
        r16[ax] = memory16get(es, di + 2);
        r16[ax] -= memory16get(es, di + 22);
        memory16set(ds, 0x6823, r16[ax]);
        r16[dx] = memory16get(ds, 0x6813);
        r16[ax] = memory16get(ds, 0x6823);
        if (r16s[dx] <= r16s[ax]) {
            pc = 0xfbec;
            break;
        }
        r16[dx] = memory16get(ds, 0x680f);
        r16[ax] = memory16get(ds, 0x6821);
        if (r16s[dx] <= r16s[ax]) {
            pc = 0xfbec;
            break;
        }
        r16[dx] = r16[ax];
        r16[ax] = memory16get(es, di + 16);
        r16[ax] >>= 1;
        r16[dx] += r16[ax];
        if (r16s[dx] < 0) {
            pc = 0xfbec;
            break;
        }
        r16[ax] = memory16get(ds, 0x680d);
        if (r16s[dx] < r16s[ax]) {
            pc = 0xfbec;
            break;
        }
        r16[ax] = memory16get(ds, 0x6823);
        r16[dx] = r16[ax];
        r16[ax] = memory16get(es, di + 18);
        r16[dx] += r16[ax];
        if (r16s[dx] < 0) {
            pc = 0xfc87;
            break;
        }
        r16[ax] = memory16get(ds, 0x6811);
        if (r16s[dx] < r16s[ax]) {
            pc = 0xfc87;
            break;
        }
        push(r16[bx]);
        push(di);
        yield* sub_fdcd();
        di = pop();
        r16[bx] = pop();
        pc = 0xfbec;
        break;
    case 0xfc87:
        r16[bx] = pop();
        es = pop();
        r16[bx] += 0x0004;
        pc = 0xfbdc;
        break;
    case 0xfc8f:
        es = pop();
        return;
    } while (1);
}
function* sub_fce0() {
    var pc = 0;
    do switch (pc) {
    case 0:
        memory[ds*16 + 0x683c] = 0x00;
        memory16set(ds, 0x6819, 0x0000);
        r16[ax] = memory16get(ds, 0x680d);
        r16[ax] -= memory16get(ds, 0x6821);
        if (r16s[ax] >= 0) {
            pc = 0xfcfb;
            break;
        }
        r16[ax] = -r16[ax];
        memory16set(ds, 0x6819, r16[ax]);
        r16[ax] = 0;
    case 0xfcfb:
        memory16set(ds, 0x681f, r16[ax]);
        if (r16[ax] == 0) {
            pc = 0xfd07;
            break;
        }
        memory[ds*16 + 0x683c] = memory[ds*16 + 0x683c] | 0x02;
    case 0xfd07:
        r16[ax] = memory16get(ds, 0x680f);
        r16[ax] -= memory16get(ds, 0x6821);
        if (r16s[ax] < 0) {
            pc = 0xfd31;
            break;
        }
        r16[bx] = memory16get(es, di + 16);
        r16[bx] >>= 1;
        r16[bx]++;
        r16[ax] -= r16[bx];
        if (r16s[ax] < 0) {
            pc = 0xfd31;
            break;
        }
        r16[ax] = memory16get(es, di + 16);
        r16[ax] >>= 1;
        r16[ax] -= memory16get(ds, 0x681f);
        if (r16s[ax] >= 0) {
            pc = 0xfd29;
            break;
        }
        r16[ax] = 0;
    case 0xfd29:
        memory16set(ds, 0x6835, r16[ax]);
        pc = 0xfd43;
        break;
    case 0xfd2e:
        r16[ax] = 0;
        return;
    case 0xfd31:
        r16[ax] = memory16get(ds, 0x681f);
        r16[ax] = -r16[ax];
        r16[ax] += memory16get(ds, 0x680f);
        r16[ax] -= memory16get(ds, 0x6821);
        memory[ds*16 + 0x683c] = memory[ds*16 + 0x683c] | 0x01;
    case 0xfd43:
        memory16set(ds, 0x6835, r16[ax]);
        memory16set(ds, 0x681b, 0x0000);
        r16[ax] = memory16get(ds, 0x6811);
        r16[ax] -= memory16get(ds, 0x6823);
        if (r16s[ax] >= 0) {
            pc = 0xfd5c;
            break;
        }
        r16[ax] = -r16[ax];
        memory16set(ds, 0x681b, r16[ax]);
        r16[ax] = 0;
    case 0xfd5c:
        memory16set(ds, 0x681d, r16[ax]);
        r16[ax] = memory16get(ds, 0x6811);
        r16[ax] += memory16get(ds, 0x6817);
        r16[ax] -= memory16get(ds, 0x6823);
        if (r16s[ax] < 0) {
            pc = 0xfd7d;
            break;
        }
        r16[ax] -= memory16get(es, di + 18);
        if (r16s[ax] < 0) {
            pc = 0xfd7d;
            break;
        }
        r16[ax] = memory16get(ds, 0x681d);
        r16[ax] = -r16[ax];
        r16[ax] += memory16get(es, di + 18);
        pc = 0xfd8e;
        break;
    case 0xfd7d:
        r16[ax] = memory16get(ds, 0x681d);
        r16[ax] = -r16[ax];
        r16[ax] += memory16get(ds, 0x6811);
        r16[ax] += memory16get(ds, 0x6817);
        r16[ax] -= memory16get(ds, 0x6823);
    case 0xfd8e:
        memory16set(ds, 0x6837, r16[ax]);
        r16[ax] = memory16get(ds, 0x681b);
        r16[ax] += memory16get(ds, 0x6811);
        if (!r16[ax]) {
            pc = 0xfda0;
            break;
        }
        r8[bl] = 0x28;
        mul8(r8[bl]);
    case 0xfda0:
        r16[ax] += memory16get(ds, 0x56e2);
        r16[ax] += memory16get(ds, 0x6819);
        r16[ax] += memory16get(ds, 0x680d);
        memory16set(ds, 0x56e8, r16[ax]);
        r16[ax] = memory16get(ds, 0x6835);
        if (r16[ax] == 0) {
            pc = 0xfdca;
            break;
        }
        if (r16s[ax] < 0) {
            pc = 0xfdca;
            break;
        }
        r16[ax] = memory16get(ds, 0x6837);
        if (r16[ax] == 0) {
            pc = 0xfdca;
            break;
        }
        if (r16s[ax] < 0) {
            pc = 0xfdca;
            break;
        }
        if (r16s[ax] >= signed16(0x0064)) {
            pc = 0xfdca;
            break;
        }
        r16[ax] |= 0x0001;
        return;
    case 0xfdca:
        pc = 0xfd2e;
        break;
        return;
    } while (1);
}
function* sub_fdcd() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sub_fce0();
        r16[ax] = memory16get(ds, 0x681d);
        if (!r16[ax]) {
            pc = 0xfddf;
            break;
        }
        r8[bl] = memory[es*16 + di + 16];
        r8[bl] += r8[bl];
        mul8(r8[bl]);
    case 0xfddf:
        r16[ax] += memory16get(ds, 0x681f);
        r16[ax] += memory16get(ds, 0x681f);
        r16[ax] += memory16get(ds, 0x681f);
        r16[ax] += memory16get(ds, 0x681f);
        memory16set(ds, 0x56e6, r16[ax]);
        r16[ax] = memory16get(ds, 0x6835);
        r16[dx] = memory16get(es, di + 16);
        r16[dx] >>= 1;
        r8[cl] = 0x28;
        r8[cl] -= r8[al];
        r8[ch] = 0;
        r8[dh] = r8[ch];
        memory[ds*16 + 0x683a] = 0x00;
        pc = 0xfe36;
        break;
    case 0xfe36:
        push(es);
        push(di);
        r8[al] = memory[cs*16 + 0x3216];
        memory[ds*16 + 0x683b] = r8[al];
        bp = memory16get(es, di + 12);
        es = memory16get(es, di + 12 + 2);
        bp += memory16get(ds, 0x56e6);
        memory16set(ds, 0x6825, bp);
        r16[ax] = es;
        memory16set(ds, 0x6827, r16[ax]);
        si = memory16get(ds, 0x56e8);
        memory16set(ds, 0x682d, si);
        r16[ax] = memory16get(ds, 0x56e4);
        memory16set(ds, 0x682f, r16[ax]);
        memory16set(ds, 0x6833, 0x0028);
        memory16set(ds, 0x6831, r16[dx]);
        si = 0x6825;
        yield* sub_fe71();
        di = pop();
        es = pop();
        return;
    } while (1);
}
function* sub_fe71() {
    var pc = 0;
    do switch (pc) {
    case 0:
        pc = 0xfe71;
        break;
    case 0xf9b4:
        push(r16[ax]);
        r16[ax] = 0x0003;
        interrupt(0x10);
        r16[ax] = pop();
        r8[dl] = r8[al];
        r8[ah] = 0x02;
        interrupt(0x21);
        interrupt(0x20);
        return;
    case 0xfe71:
        push(ds);
        r8[al] = memory[ds*16 + si + 23];
        memory[cs*16 + 0x3215] = r8[al];
        r8[al] = memory[ds*16 + si + 22];
        memory[cs*16 + 0x3216] = r8[al];
        r16[ax] = memory16get(ds, si + 18);
        r16[ax]--;
        memory16set(cs, 0x3213, r16[ax]);
        if (r16s[ax] >= 0) {
            pc = 0xfe8d;
            break;
        }
        pc = 0x10ec9;
        break;
    case 0xfe8d:
        r16[bx] = memory16get(ds, si + 16);
        r16[ax] = memory16get(ds, si + 14);
        r16[ax] -= r16[bx];
        memory16set(cs, 0x320f, r16[ax]);
        r16[cx] = memory16get(ds, si + 12);
        r16[cx] -= r16[bx];
        r8[al] = memory[ds*16 + si + 21];
        push(r16[dx]);
        push(r16[ax]);
        r16[dx] = 0x03ce;
        r8[al] = 0x05;
        out8(r16[dx], r8[al]);
        r16[dx]++;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[ax] = pop();
        r16[dx] = pop();
        push(r16[dx]);
        push(r16[ax]);
        r16[dx] = 0x03ce;
        r8[al] = 0x03;
        out8(r16[dx], r8[al]);
        r16[dx]++;
        r8[al] = 0x00;
        out8(r16[dx], r8[al]);
        r16[ax] = pop();
        r16[dx] = pop();
        push(r16[dx]);
        push(r16[ax]);
        r16[dx] = 0x03c4;
        r8[al] = 0x02;
        out8(r16[dx], r8[al]);
        r16[dx]++;
        r8[al] = 0x0f;
        out8(r16[dx], r8[al]);
        r16[ax] = pop();
        r16[dx] = pop();
        r16[bx] += r16[bx];
        r8[ah] = 0;
        r16[ax] += r16[ax];
        r16[dx] = r16[ax];
        r16[ax] += r16[ax];
        r16[ax] += r16[dx];
        bp = 0x328f;
        bp += r16[ax];
        r16[dx] = memory16get(cs, bp + 4);
        di = memory16get(cs, bp);
        r16[ax] = memory16get(cs, r16[bx] + di);
        memory16set(cs, 0x25e2, r16[ax]);
        r16[ax] = memory16get(cs, bp + 2);
        push(r16[ax]);
        push(r16[bx]);
        r8[al] = memory[cs*16 + 0x320e];
        r16[bx] = 0x11da;
        r8[al] &= 0x40;
        if (r8[al] == 0) {
            pc = 0xff0b;
            break;
        }
        r16[bx] = 0x11e2;
    case 0xff0b:
        r16[ax] = memory16get(cs, r16[bx]);
        memory16set(cs, 0x11d5, r16[ax]);
        r8[al] = memory[cs*16 + r16[bx] + 2];
        memory[cs*16 + 0x11d7] = r8[al];
        r8[al] = memory[cs*16 + r16[bx] + 4];
        memory[cs*16 + 0x11d8] = r8[al];
        r8[al] = memory[cs*16 + r16[bx] + 6];
        memory[cs*16 + 0x11d9] = r8[al];
        r16[bx] = pop();
        r16[ax] = pop();
        bp = memory16get(ds, si);
        es = memory16get(ds, si + 2);
        r16[tx] = si;
        si = memory16get(ds, r16[tx] + 8);
        ds = memory16get(ds, r16[tx] + 8 + 2);
        r8[bl] = memory[cs*16 + 0x3216];
        r8[bh] = 0;
        r16[bx] += r16[bx];
        di = memory16get(cs, r16[bx] + 13093);
        if (r16[dx] == 0x0004) {
            pc = 0xff5a;
            break;
        }
        if (r16[dx] == 0x0002) {
            pc = 0xff5c;
            break;
        }
        if (r16[dx] == 0x0001) {
            pc = 0xff58;
            break;
        }
        if (r16[dx] == 0x0003) {
            pc = 0xff58;
            break;
        }
    case 0xff53:
        r8[ah] = 0x01;
        pc = 0xf9b4;
        break;
    case 0xff58:
        pc = 0xff53;
        break;
    case 0xff5a:
        r16[cx] += r16[cx];
    case 0xff5c:
        r16[cx] += r16[cx];
        memory16set(cs, 0x3211, r16[cx]);
        switch (r16[ax])
        {
        case 0x210b: pc = 0x10e9b; break;
            default:
            assert(0);
        }
        break;
    case 0x10cd6:
        r16[ax] = memory16get(es, bp);
        r16[dx] = memory16get(es, bp + 2);
        bp += 0x0004;
        push(r16[cx]);
        r8[cl] = memory[cs*16 + 0x3216];
        r16[ax] = ror16(r16[ax], r8[cl]);
        r16[dx] = ror16(r16[dx], r8[cl]);
        r16[cx] = pop();
        push(r16[ax]);
        push(r16[dx]);
        r16[ax] &= di;
        r16[dx] &= di;
        r16[bx] |= r16[ax];
        r16[cx] |= r16[dx];
        r16[ax] = r16[bx];
        r16[ax] |= r16[cx];
        r8[ah] |= r8[al];
        r16[dx] = 0x03ce;
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03c4;
        r16[ax] = memory16get(cs, 0x11d5);
        out16(r16[dx], r16[ax]);
        r8[al] = r8[ah];
        r16[dx]++;
        r8[ah] = videoGet(ds, si);
        videoSet(ds, si, r8[bl]);
        r8[al] = memory[cs*16 + 0x11d7];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[bh]);
        r8[al] = memory[cs*16 + 0x11d8];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[cl]);
        r8[al] = memory[cs*16 + 0x11d9];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[ch]);
        si++;
        r16[cx] = pop();
        r16[bx] = pop();
        di = ~di;
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        r8[tl] = r8[cl];
        r8[cl] = r8[ch];
        r8[ch] = r8[tl];
        r16[bx] &= di;
        r16[cx] &= di;
        di = ~di;
        r16[ax] = memory16get(es, bp);
        r16[dx] = memory16get(es, bp + 2);
        bp += 0x0004;
        push(r16[cx]);
        r8[cl] = memory[cs*16 + 0x3216];
        r16[ax] = ror16(r16[ax], r8[cl]);
        r16[dx] = ror16(r16[dx], r8[cl]);
        r16[cx] = pop();
        push(r16[ax]);
        push(r16[dx]);
        r16[ax] &= di;
        r16[dx] &= di;
        r16[bx] |= r16[ax];
        r16[cx] |= r16[dx];
        r16[ax] = r16[bx];
        r16[ax] |= r16[cx];
        r8[ah] |= r8[al];
        r16[dx] = 0x03ce;
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03c4;
        r16[ax] = memory16get(cs, 0x11d5);
        out16(r16[dx], r16[ax]);
        r8[al] = r8[ah];
        r16[dx]++;
        r8[ah] = videoGet(ds, si);
        videoSet(ds, si, r8[bl]);
        r8[al] = memory[cs*16 + 0x11d7];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[bh]);
        r8[al] = memory[cs*16 + 0x11d8];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[cl]);
        r8[al] = memory[cs*16 + 0x11d9];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[ch]);
        si++;
        r16[cx] = pop();
        r16[bx] = pop();
        di = ~di;
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        r8[tl] = r8[cl];
        r8[cl] = r8[ch];
        r8[ch] = r8[tl];
        r16[bx] &= di;
        r16[cx] &= di;
        di = ~di;
    case 0x10d94:
        r16[ax] = memory16get(es, bp);
        r16[dx] = memory16get(es, bp + 2);
        bp += 0x0004;
        push(r16[cx]);
        r8[cl] = memory[cs*16 + 0x3216];
        r16[ax] = ror16(r16[ax], r8[cl]);
        r16[dx] = ror16(r16[dx], r8[cl]);
        r16[cx] = pop();
        push(r16[ax]);
        push(r16[dx]);
        r16[ax] &= di;
        r16[dx] &= di;
        r16[bx] |= r16[ax];
        r16[cx] |= r16[dx];
        r16[ax] = r16[bx];
        r16[ax] |= r16[cx];
        r8[ah] |= r8[al];
        r16[dx] = 0x03ce;
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03c4;
        r16[ax] = memory16get(cs, 0x11d5);
        out16(r16[dx], r16[ax]);
        r8[al] = r8[ah];
        r16[dx]++;
        r8[ah] = videoGet(ds, si);
        videoSet(ds, si, r8[bl]);
        r8[al] = memory[cs*16 + 0x11d7];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[bh]);
        r8[al] = memory[cs*16 + 0x11d8];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[cl]);
        r8[al] = memory[cs*16 + 0x11d9];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[ch]);
        si++;
        r16[cx] = pop();
        r16[bx] = pop();
        di = ~di;
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        r8[tl] = r8[cl];
        r8[cl] = r8[ch];
        r8[ch] = r8[tl];
        r16[bx] &= di;
        r16[cx] &= di;
        di = ~di;
    case 0x10df3:
        r16[ax] = memory16get(es, bp);
        r16[dx] = memory16get(es, bp + 2);
        bp += 0x0004;
        push(r16[cx]);
        r8[cl] = memory[cs*16 + 0x3216];
        r16[ax] = ror16(r16[ax], r8[cl]);
        r16[dx] = ror16(r16[dx], r8[cl]);
        r16[cx] = pop();
        push(r16[ax]);
        push(r16[dx]);
        r16[ax] &= di;
        r16[dx] &= di;
        r16[bx] |= r16[ax];
        r16[cx] |= r16[dx];
        r16[ax] = r16[bx];
        r16[ax] |= r16[cx];
        r8[ah] |= r8[al];
        r16[dx] = 0x03ce;
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03c4;
        r16[ax] = memory16get(cs, 0x11d5);
        out16(r16[dx], r16[ax]);
        r8[al] = r8[ah];
        r16[dx]++;
        r8[ah] = videoGet(ds, si);
        videoSet(ds, si, r8[bl]);
        r8[al] = memory[cs*16 + 0x11d7];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[bh]);
        r8[al] = memory[cs*16 + 0x11d8];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[cl]);
        r8[al] = memory[cs*16 + 0x11d9];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[ch]);
        si++;
        r16[cx] = pop();
        r16[bx] = pop();
        di = ~di;
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        r8[tl] = r8[cl];
        r8[cl] = r8[ch];
        r8[ch] = r8[tl];
        r16[bx] &= di;
        r16[cx] &= di;
        di = ~di;
        r8[al] = memory[cs*16 + 0x3215];
        r8[al] &= 0x01;
        if (r8[al] != 0) {
            pc = 0x10e8a;
            break;
        }
        r16[ax] = r16[bx];
        r16[ax] |= r16[cx];
        r8[ah] |= r8[al];
        r16[dx] = 0x03ce;
        r8[al] = 0x08;
        out16(r16[dx], r16[ax]);
        r16[dx] = 0x03c4;
        r16[ax] = memory16get(cs, 0x11d5);
        out16(r16[dx], r16[ax]);
        r8[al] = r8[ah];
        r16[dx]++;
        r8[ah] = videoGet(ds, si);
        videoSet(ds, si, r8[bl]);
        r8[al] = memory[cs*16 + 0x11d7];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[bh]);
        r8[al] = memory[cs*16 + 0x11d8];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[cl]);
        r8[al] = memory[cs*16 + 0x11d9];
        out8(r16[dx], r8[al]);
        videoSet(ds, si, r8[ch]);
    case 0x10e8a:
        memory16set(cs, 0x3213, memory16get(cs, 0x3213) - 1);
        if (memory16gets(cs, 0x3213) < 0) {
            pc = 0x10ec9;
            break;
        }
        bp += memory16get(cs, 0x3211);
        si += memory16get(cs, 0x320f);
    case 0x10e9b:
        r16[bx] = 0;
        r16[cx] = 0;
        r8[al] = memory[cs*16 + 0x3215];
        r8[al] &= 0x02;
        if (r8[al] == 0) {
            pc = 0x10ec6;
            break;
        }
        r16[bx] = memory16get(es, bp - 4);
        r16[ax] = memory16get(es, bp - 2);
        r8[cl] = memory[cs*16 + 0x3216];
        r16[bx] = ror16(r16[bx], r8[cl]);
        r16[ax] = ror16(r16[ax], r8[cl]);
        r16[cx] = r16[ax];
        di = ~di;
        r8[tl] = r8[bl];
        r8[bl] = r8[bh];
        r8[bh] = r8[tl];
        r8[tl] = r8[cl];
        r8[cl] = r8[ch];
        r8[ch] = r8[tl];
        r16[bx] &= di;
        r16[cx] &= di;
        di = ~di;
    case 0x10ec6:
        pc = 0x11371;
        break;
    case 0x10ec9:
        r16[dx] = 0x03ce;
        r16[ax] = 0xff08;
        out16(r16[dx], r16[ax]);
        ds = pop();
        return;
    case 0x11371:
        r16[ax] = 0x0000;
        r16[ax] = memory16get(cs, 0x25e2);
        switch (r16[ax])
        {
        case 0x2004: pc = 0x10d94; break;
        case 0x2063: pc = 0x10df3; break;
        case 0x1f46: pc = 0x10cd6; break;
        case 0x20fa: pc = 0x10e8a; break;
            default:
            assert(0);
        }
        break;
        return;
    } while (1);
}
function* sub_11a7d() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = 0x2d09;
    di = memory16get(ds, 0x541d);
    di += di;
    r16[ax] = memory16get(cs, r16[bx] + di);
    di = memory16get(ss, bp + 4);
    es = memory16get(ss, bp + 4 + 2);
    yield* callIndirect(cs, r16[ax]);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_11aa5() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = 0x1228;
    ds = r16[bx];
    ds = r16[dx];
    si = r16[ax];
    r16[bx] = 0x2d37;
    di = memory16get(ds, 0x541d);
    di += di;
    r16[ax] = memory16get(cs, r16[bx] + di);
    yield* callIndirect(cs, r16[ax]);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_11afd() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[ax] = 0x1228;
    ds = r16[ax];
    push(ds);
    si = memory16get(ds, 0x56de);
    ds = memory16get(ds, 0x56de + 2);
    r16[tx] = si;
    si = memory16get(ds, r16[tx]);
    ds = memory16get(ds, r16[tx] + 2);
    r16[ax] = ds;
    ds = pop();
    memory16set(ds, 0x56e2, si);
    memory16set(ds, 0x56e4, r16[ax]);
    r16[bx] = 0x2d9c;
    di = memory16get(ds, 0x541d);
    di += di;
    r16[ax] = memory16get(cs, r16[bx] + di);
    assert(di == 4);
    yield* callIndirect(cs, r16[ax]);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_11b38() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[bx] = 0x2dc6;
    di = memory16get(ds, 0x541d);
    di += di;
    r16[ax] = memory16get(cs, r16[bx] + di);
    yield* callIndirect(cs, r16[ax]);
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_11b62() {
    push(ds);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[ax] = memory16get(ss, bp + 4);
    r16[ax] <<= 1;
    r16[ax] <<= 1;
    r16[ax] += 0x5415;
    memory16set(ds, 0x56de, r16[ax]);
    r16[ax] = 0x1228;
    memory16set(ds, 0x56e0, r16[ax]);
    ds = pop();
    cs = pop();
}
function* sub_11b7d() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[ax] = 0x1228;
        ds = r16[ax];
        si = memory16get(ss, bp + 4);
        es = memory16get(ss, bp + 4 + 2);
        memory16set(ds, 0x56ee, 0x56f0);
    case 0x11b90:
        push(es);
        r16[bx] = memory16get(es, si);
        es = memory16get(es, si + 2);
        r16[ax] = es;
        r16[ax] |= r16[bx];
        if (r16[ax]) {
            pc = 0x11ba1;
            break;
        }
        es = pop();
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    case 0x11ba1:
        r16[ax] = memory16get(es, r16[bx] + 4);
        r16[ax] <<= 1;
        r16[ax] <<= 1;
        di = 0x1228;
        ds = di;
        di = memory16get(es, r16[bx] + 6);
        ds = memory16get(es, r16[bx] + 6 + 2);
        di += r16[ax];
        r16[tx] = di;
        di = memory16get(ds, r16[tx]);
        ds = memory16get(ds, r16[tx] + 2);
        memory16set(es, r16[bx] + 12, di);
        r16[ax] = ds;
        memory16set(es, r16[bx] + 14, r16[ax]);
        r16[ax] |= di;
        if (r16[ax]) {
            pc = 0x11bca;
            break;
        }
        memory16set(es, r16[bx] + 10, 0x0000);
    case 0x11bca:
        r16[ax] = memory16get(ds, di - 2);
        memory16set(es, r16[bx] + 18, r16[ax]);
        r16[ax] = memory16get(ds, di - 4);
        memory16set(es, r16[bx] + 16, r16[ax]);
        r16[ax] = memory16get(ds, di - 6);
        memory16set(es, r16[bx] + 20, r16[ax]);
        r16[ax] = memory16get(ds, di - 8);
        memory16set(es, r16[bx] + 22, r16[ax]);
        r16[ax] = memory16get(ds, di - 12);
        memory16set(es, r16[bx] + 24, r16[ax]);
        if (r16[ax] < 0x0003) {
            pc = 0x11bf5;
            break;
        }
        r16[ax] = 0x0003;
    case 0x11bf5:
        memory16set(es, r16[bx] + 24, r16[ax]);
        if (!r16[ax]) {
            pc = 0x11c20;
            break;
        }
        push(ds);
        push(di);
        push(es);
        push(si);
        push(r16[cx]);
        r16[cx] = r16[ax];
        si = di + 0xfffffff4;
        di = r16[bx] + 0x1a;
    case 0x11c0a:
        si--;
        si--;
        movsw_data_data_forward();
        si--;
        si--;
        si--;
        si--;
        movsw_data_data_forward();
        si--;
        si--;
        si--;
        si--;
        movsw_data_data_forward();
        si--;
        si--;
        if (--r16[cx]) {
            pc = 0x11c0a;
            break;
        }
        r16[cx] = pop();
        si = pop();
        es = pop();
        di = pop();
        ds = pop();
    case 0x11c20:
        r8[al] = memory[ds*16 + di - 10];
        memory[es*16 + r16[bx] + 11] = r8[al];
        r8[al] &= 0xc0;
        if (r8[al] != 0) {
            pc = 0x11c32;
            break;
        }
    case 0x11c2b:
        si += 0x0004;
        es = pop();
        pc = 0x11b90;
        break;
    case 0x11c32:
        if (r8[al] & 0x40) {
            pc = 0x11c39;
            break;
        }
        pc = 0x11df8;
        break;
    case 0x11c39:
        push(si);
        push(di);
        r8[dh] = memory[es*16 + r16[bx] + 10];
        r16[ax] = memory16get(es, 0x56ee);
        si = di;
        si -= 0x000c;
        di = r16[ax];
        r16[ax] += 0x000c;
        memory16set(es, r16[bx] + 12, r16[ax]);
        r16[ax] = 0x1228;
        memory16set(es, r16[bx] + 14, r16[ax]);
        es = r16[ax];
        r16[cx] = 0x0006;
        rep_movsw_data_data_forward();
        r16[bx] = si;
        r8[al] = memory[ds*16 + si - 4];
        r8[al] >>= 1;
        r8[al] >>= 1;
        r8[ah] = memory[ds*16 + si - 2];
        mul8(r8[ah]);
        si += r16[ax];
        r16[cx] = r16[ax];
        if (r8[dh] & 0x20) {
            pc = 0x11c79;
            break;
        }
        pc = 0x11d93;
        break;
    case 0x11c79:
        r16[cx] = memory16get(ds, r16[bx] - 4);
        bp = r16[cx];
        r16[cx] <<= 1;
        di -= r16[cx];
        di -= 0x0008;
        r16[cx] = memory16get(ds, r16[bx] - 2);
    case 0x11c88:
        push(r16[cx]);
        r16[cx] = bp;
        r16[cx] <<= 1;
        r16[cx] <<= 1;
        di += r16[cx];
        r16[cx] = bp;
        r16[cx] >>= 1;
        r16[cx] >>= 1;
    case 0x11c97:
        push(r16[cx]);
        r8[cl] = memory[ds*16 + r16[bx]];
        r16[bx]++;
        push(r16[bx]);
        r8[ah] = 0;
        r8[al] = 0;
        if (!(r8[cl] & 0x80)) {
            pc = 0x11cb0;
            break;
        }
        r8[al] = memory[ds*16 + si];
        r16[bx] = 0x66f0;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        si++;
    case 0x11cb0:
        r8[ch] = r8[al];
        r8[al] = 0;
        if (!(r8[cl] & 0x40)) {
            pc = 0x11cc4;
            break;
        }
        r8[al] = memory[ds*16 + si];
        r16[bx] = 0x66f0;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        si++;
    case 0x11cc4:
        stosb_data_forward();
        r8[al] = 0;
        if (!(r8[cl] & 0x20)) {
            pc = 0x11cd7;
            break;
        }
        r8[al] = memory[ds*16 + si];
        r16[bx] = 0x66f0;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        si++;
    case 0x11cd7:
        r8[dl] = r8[al];
        r8[al] = 0;
        if (!(r8[cl] & 0x10)) {
            pc = 0x11ceb;
            break;
        }
        r8[al] = memory[ds*16 + si];
        r16[bx] = 0x66f0;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        si++;
    case 0x11ceb:
        stosb_data_forward();
        r8[al] = 0;
        if (!(r8[cl] & 0x08)) {
            pc = 0x11cfe;
            break;
        }
        r8[al] = memory[ds*16 + si];
        r16[bx] = 0x66f0;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        si++;
    case 0x11cfe:
        r8[dh] = r8[al];
        r8[al] = 0;
        if (!(r8[cl] & 0x04)) {
            pc = 0x11d12;
            break;
        }
        r8[al] = memory[ds*16 + si];
        r16[bx] = 0x66f0;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        si++;
    case 0x11d12:
        stosb_data_forward();
        r8[al] = 0;
        if (!(r8[cl] & 0x02)) {
            pc = 0x11d25;
            break;
        }
        r8[al] = memory[ds*16 + si];
        r16[bx] = 0x66f0;
        r16[bx] += r16[ax];
        r8[al] = memory[es*16 + r16[bx]];
        si++;
    case 0x11d25:
        r8[ah] = r8[al];
        r8[al] = 0;
        if (!(r8[cl] & 0x01)) {
            pc = 0x11d3c;
            break;
        }
        r8[al] = memory[ds*16 + si];
        r16[bx] = 0x66f0;
        flags.carry = (r8[bl] + r8[al]) >= 0x100;
        r8[bl] += r8[al];
        r8[bh] += flags.carry;
        r8[al] = memory[es*16 + r16[bx]];
        si++;
    case 0x11d3c:
        stosb_data_forward();
        r8[cl] = r8[ah];
        r16[ax] = memory16get(cs, 0x0ded);
        if (r16[ax] != 0x0000) {
            pc = 0x11d60;
            break;
        }
        r16[ax] = memory16get(es, di - 2);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        memory16set(es, di - 2, r16[ax]);
        r16[ax] = memory16get(es, di - 4);
        r8[tl] = r8[al];
        r8[al] = r8[ah];
        r8[ah] = r8[tl];
        memory16set(es, di - 4, r16[ax]);
        r8[tl] = r8[dl];
        r8[dl] = r8[ch];
        r8[ch] = r8[tl];
        r8[tl] = r8[cl];
        r8[cl] = r8[dh];
        r8[dh] = r8[tl];
    case 0x11d60:
        r8[al] = r8[ch];
        stosb_data_forward();
        r8[al] = r8[dl];
        stosb_data_forward();
        r8[al] = r8[dh];
        stosb_data_forward();
        r8[al] = r8[cl];
        stosb_data_forward();
        di -= 0x0010;
        r16[bx] = pop();
        r16[cx] = pop();
        r16[cx]--;
        if (!r16[cx]) {
            pc = 0x11d79;
            break;
        }
        pc = 0x11c97;
        break;
    case 0x11d79:
        r16[cx] = pop();
        r16[cx]--;
        if (!r16[cx]) {
            pc = 0x11d82;
            break;
        }
        pc = 0x11c88;
        break;
    case 0x11d82:
        bp <<= 1;
        di += bp;
        di += 0x0008;
        memory16set(es, 0x56ee, di);
        di = pop();
        si = pop();
        pc = 0x11c2b;
        break;
    case 0x11d93:
        push(r16[cx]);
        r8[cl] = memory[ds*16 + r16[bx]];
        r16[bx]++;
        r16[ax] = 0;
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        if (!flags.carry) {
            pc = 0x11da0;
            break;
        }
        r8[al] = memory[ds*16 + si];
        si++;
    case 0x11da0:
        stosb_data_forward();
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        if (!flags.carry) {
            pc = 0x11da8;
            break;
        }
        r8[ah] = memory[ds*16 + si];
        si++;
    case 0x11da8:
        r8[al] = 0;
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        if (!flags.carry) {
            pc = 0x11db1;
            break;
        }
        r8[al] = memory[ds*16 + si];
        si++;
    case 0x11db1:
        stosb_data_forward();
        r8[ch] = 0;
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        if (!flags.carry) {
            pc = 0x11dbb;
            break;
        }
        r8[ch] = memory[ds*16 + si];
        si++;
    case 0x11dbb:
        r8[al] = 0;
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        if (!flags.carry) {
            pc = 0x11dc4;
            break;
        }
        r8[al] = memory[ds*16 + si];
        si++;
    case 0x11dc4:
        stosb_data_forward();
        r8[dl] = 0;
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        if (!flags.carry) {
            pc = 0x11dce;
            break;
        }
        r8[dl] = memory[ds*16 + si];
        si++;
    case 0x11dce:
        r8[al] = 0;
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        if (!flags.carry) {
            pc = 0x11dd7;
            break;
        }
        r8[al] = memory[ds*16 + si];
        si++;
    case 0x11dd7:
        stosb_data_forward();
        r8[al] = r8[ah];
        stosb_data_forward();
        r8[al] = r8[ch];
        stosb_data_forward();
        r8[al] = r8[dl];
        stosb_data_forward();
        r8[al] = 0;
        flags.carry = !!(r16[cx] & 0x8000);
        r16[cx] <<= 1;
        if (!flags.carry) {
            pc = 0x11dea;
            break;
        }
        r8[al] = memory[ds*16 + si];
        si++;
    case 0x11dea:
        stosb_data_forward();
        r16[cx] = pop();
        if (--r16[cx]) {
            pc = 0x11d93;
            break;
        }
        memory16set(es, 0x56ee, di);
        di = pop();
        si = pop();
        pc = 0x11c2b;
        break;
    case 0x11df8:
        pc = 0x11c2b;
        break;
        return;
    } while (1);
}
function* sub_11ec7() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[bx] = 0x66f0;
        r16[cx] = 0x0000;
        r16[ax] = memory16get(ds, 0x541d);
        if (r16[ax] != 0x0000) {
            pc = 0x11f15;
            break;
        }
    case 0x11edf:
        r8[dl] = r8[cl];
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r8[al] = rcr8(r8[al], 0x01);
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r8[ah] = rcl8(r8[ah], 0x01);
        r16[ax] <<= 1;
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r8[al] = rcr8(r8[al], 0x01);
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r8[ah] = rcl8(r8[ah], 0x01);
        r16[ax] <<= 1;
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r8[al] = rcr8(r8[al], 0x01);
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r8[ah] = rcl8(r8[ah], 0x01);
        r16[ax] <<= 1;
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r8[al] = rcr8(r8[al], 0x01);
        flags.carry = r8[dl] & 1;
        r8[dl] >>= 1;
        r8[ah] = rcl8(r8[ah], 0x01);
        r16[ax] <<= 1;
        memory[ds*16 + r16[bx]] = r8[ah];
        r16[bx]++;
        r16[cx]++;
        if (r16s[cx] <= signed16(0x00ff)) {
            pc = 0x11edf;
            break;
        }
        pc = 0x11f41;
        break;
    case 0x11f15:
        r8[ah] = r8[cl];
        flags.carry = r8[ah] & 1;
        r8[ah] >>= 1;
        r8[al] = rcl8(r8[al], 0x01);
        flags.carry = r8[ah] & 1;
        r8[ah] >>= 1;
        r8[al] = rcl8(r8[al], 0x01);
        flags.carry = r8[ah] & 1;
        r8[ah] >>= 1;
        r8[al] = rcl8(r8[al], 0x01);
        flags.carry = r8[ah] & 1;
        r8[ah] >>= 1;
        r8[al] = rcl8(r8[al], 0x01);
        flags.carry = r8[ah] & 1;
        r8[ah] >>= 1;
        r8[al] = rcl8(r8[al], 0x01);
        flags.carry = r8[ah] & 1;
        r8[ah] >>= 1;
        r8[al] = rcl8(r8[al], 0x01);
        flags.carry = r8[ah] & 1;
        r8[ah] >>= 1;
        r8[al] = rcl8(r8[al], 0x01);
        flags.carry = r8[ah] & 1;
        r8[ah] >>= 1;
        r8[al] = rcl8(r8[al], 0x01);
        memory[ds*16 + r16[bx]] = r8[al];
        r16[bx]++;
        r16[cx]++;
        if (r16s[cx] <= signed16(0x00ff)) {
            pc = 0x11f15;
            break;
        }
    case 0x11f41:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_11f47() {
    push(0x7777);
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[ax] = 0x1228;
    ds = r16[ax];
    r16[ax] = memory16get(ss, bp + 4);
    memory16set(ds, 0x67f0, r16[ax]);
    r16[dx] = memory16get(ss, bp + 6);
    memory16set(ds, 0x67f2, r16[dx]);
    es = r16[dx];
    di = r16[ax];
    r8[al] = memory[es*16 + di + 10];
    memory[cs*16 + 0x320e] = r8[al];
    bp = sp;
    r16[ax] = 0x1228;
    push(r16[ax]);
    r16[ax] = 0x67f0;
    push(r16[ax]);
    push(bp);
    bp = sp;
    bp -= 0x0002;
    push(cs);
    yield* sub_11b7d();
    bp = pop();
    sp = bp;
    bp = sp;
    r16[ax] = 0x1228;
    push(r16[ax]);
    r16[ax] = 0x67f0;
    push(r16[ax]);
    push(bp);
    bp = sp;
    bp -= 0x0002;
    push(cs);
    yield* sub_11afd();
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
function* sub_12190() {
    var pc = 0;
    do switch (pc) {
    case 0:
        push(di);
        push(si);
        push(bp);
        push(ds);
        push(es);
        r16[ax] = 0x1228;
        ds = r16[ax];
        r16[ax] = 0x0002;
        interrupt(0x10);
        si = 0x6840;
        r8[bh] = 0;
        r16[dx] = 0x0101;
        r8[ah] = 0x02;
        interrupt(0x10);
        r8[ah] = 0x09;
        r16[dx] = si;
        interrupt(0x21);
        si = 0x6858;
        di = 0x689e;
        r8[bh] = 0x00;
        r16[cx] = 0x0004;
        r16[dx] = 0x0a21;
    case 0x121bf:
        if (memory[ds*16 + di] != 0x01) {
            pc = 0x121d2;
            break;
        }
        r8[ah] = 0x02;
        interrupt(0x10);
        push(r16[dx]);
        r8[ah] = 0x09;
        r16[dx] = si;
        interrupt(0x21);
        r16[dx] = pop();
        r8[dh]++;
    case 0x121d2:
        si += 0x0011;
        di++;
        if (--r16[cx]) {
            pc = 0x121bf;
            break;
        }
    case 0x121d8:
        yield* sync();
        r8[al] = 0x3f;
        push(cs);
        cs = 0x01ed;
        yield* sub_b67a();
        assert(cs == 0x1219);
        if (!flags.zero) {
            pc = 0x121fe;
            break;
        }
        r8[al] = 0x40;
        push(cs);
        cs = 0x01ed;
        yield* sub_b67a();
        assert(cs == 0x1219);
        if (!flags.zero) {
            pc = 0x12206;
            break;
        }
        r8[al] = 0x41;
        push(cs);
        cs = 0x01ed;
        yield* sub_b67a();
        assert(cs == 0x1219);
        if (!flags.zero) {
            pc = 0x1220e;
            break;
        }
        r8[al] = 0x42;
        push(cs);
        cs = 0x01ed;
        yield* sub_b67a();
        assert(cs == 0x1219);
        if (!flags.zero) {
            pc = 0x12216;
            break;
        }
        pc = 0x121d8;
        break;
    case 0x121fe:
        memory16set(ds, 0x689c, 0x8000);
        pc = 0x12223;
        break;
    case 0x12206:
        memory16set(ds, 0x689c, 0x0000);
        pc = 0x12223;
        break;
    case 0x1220e:
        memory16set(ds, 0x689c, 0x0001);
        pc = 0x12223;
        break;
    case 0x12216:
        memory16set(ds, 0x689c, 0x0004);
        pc = 0x12223;
        break;
    case 0x12223:
        es = pop();
        ds = pop();
        bp = pop();
        si = pop();
        di = pop();
        cs = pop();
        return;
    } while (1);
}
function* sub_12230() {
    push(di);
    push(si);
    push(bp);
    push(ds);
    push(es);
    r16[bx] = memory16get(ds, 0x541d);
    r16[bx] <<= 1;
    assert(r16[bx] == 4);
    yield* callIndirect(cs, memory16get(ds, r16[bx] + 26998));
    es = pop();
    ds = pop();
    bp = pop();
    si = pop();
    di = pop();
    cs = pop();
}
function* sub_12245() {
    var pc = 0;
    do switch (pc) {
    case 0:
        yield* sync();
        r16[dx] = 0x03da;
    case 0x12248:
        r8[al] = in8(r16[dx]);
        if (!(r8[al] & 0x08)) {
            pc = 0x12248;
            break;
        }
    case 0x1224d:
        r8[al] = in8(r16[dx]);
        if (r8[al] & 0x08) {
            pc = 0x1224d;
            break;
        }
        return;
    } while (1);
}