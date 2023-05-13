arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis

./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -reloc -recursive \
  -jumptable 01ed:46dc 01ed:4725 4 jumpwords bx \
  -jumptable 01ed:37db 01ed:384a 4 jumpwords bx \
  -jumptable 01ed:6e7e 01ed:70e7 20 jumpwords bx \
  start,01ed:9c62,01ed:aa4e,0ca6:0232,0ca6:14ef,0ed9:0def,0ca6:0ad0,0ca6:0aa0,0ca6:0677,0ca6:0620,1223:0015,0ca6:002b,0ca6:0000,0e15:0194,0e15:04b0,0ed9:0e29,0ca6:1087,0ca6:1060,0ca6:0823,0ca6:07f0,0ca6:01ff,01ed:a3ae,0ed9:0c34,0ed9:10e1,sub_cdb1,01ed:79e6,0ca6:1607,0ed9:10e1,0ca6:0db0,0ca6:0de0,0ca6:0b33,01ed:7111,01ed:6717,01ed:654e,01ed:6648,01ed:6587,01ed:65fb,01ed:28f9,01ed:23b6,01ed:2423,01ed:2470,01ed:248e,01ed:24d7,01ed:250a,01ed:25ad,01ed:23b6,01ed:22b0,01ed:6648,01ed:66d8,01ed:6372,01ed:6535,01ed:65e5,01ed:6627,01ed:6699,01ed:640c,01ed:65e5,01ed:6699,01ed:6648,01ed:6699,01ed:640c,01ed:65e5,01ed:6372,01ed:6535,01ed:6326,01ed:651c,01ed:6326,01ed:673a,01ed:64e2,01ed:64ff,01ed:1e3d,01ed:6789,01ed:647e,01ed:6748,01ed:65d2,01ed:693a,01ed:640c,01ed:68fe,0ca6:091f,0ca6:0bfd,0ca6:0c05,01ed:22c1,01ed:6305,01ed:4dbf,01ed:5059,01ed:4ec9,01ed:506f,01ed:4f4e,01ed:22d2,01ed:1e90,01ed:64c1,01ed:1e5e,01ed:4344,01ed:5025,01ed:503f,01ed:4e44,01ed:6813,01ed:67fb,01ed:4344,01ed:4437,01ed:67e2,01ed:2138,01ed:645d,01ed:67ca,01ed:6832,01ed:684b,01ed:68e6,01ed:6922,01ed:6890,01ed:68bb,01ed:1ec2,01ed:1f3e \
  -labels sub_658b,01ed:46f2,01ed:46f7,01ed:46fc,01ed:4701,sub_fe71,ed9:2004,0ed9:2063,0ed9:1f46,sub_cc5f,0ca6:020e,sub_cc92,0ca6:0268,sub_fe71,0ed9:210b,sub_fe71,0ed9:210b,sub_cdb1,0ca6:0379,sub_5475,01ed:37e0,01ed:37e8 > bumpy.cpp
patch bumpy.cpp bumpy.patch
cp bumpy.cpp bumpyopt.cpp
patch bumpyopt.cpp bumpyopt.patch
sed -i -e 's/MemAuto/MemData/g' ./bumpyopt.cpp 
sed -i -e 's/DirAuto/DirForward/g' ./bumpyopt.cpp 
sed -i -e 's/memoryA/memory/g' ./bumpyopt.cpp 
rm bumpyopt.cpp-e 
rm bumpyopt.cpp.orig
rm cicodis