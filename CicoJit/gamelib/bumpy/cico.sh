arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -reloc -recursive start,01ed:9c62,01ed:aa4e,0ca6:0232,0ca6:14ef,0ed9:0def,0ca6:0ad0,0ca6:0aa0,0ca6:0677,0ca6:0620,1223:0015,0ca6:002b,0ca6:0000,0e15:0194,0e15:04b0,0ed9:0e29,0ca6:1087,0ca6:1060,0ca6:0823,0ca6:07f0,0ed9:2004,0ca6:01ff,01ed:a3ae,0ed9:0c34,0ed9:10e1,sub_cdb1 -labels sub_cc5f,0ca6:020e,sub_cc92,0ca6:0268,sub_fe71,0ed9:210b,sub_fe71,0ed9:210b,sub_cdb1,0ca6:0379 > bumpy.cpp
rm cicodis

exit
./cicodis $PWD/dos/B.EXE  -stackguard -load 01ed 0ed9:2004 -recursive
./cicodis $PWD/dos/B.EXE  -load 01ed 0ed9:10e1 -labels sub_fe71,0ed9:210b
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ed9:0e29
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:1087
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:1060
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:0823
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:07f0
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard sub_cdb1 -labels sub_cdb1,0ca6:0379
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:0ad0
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:0aa0
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:0677
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:0620
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 1223:0015
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:002b
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:0000
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0e15:0194
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0e15:04b0
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive 0ed9:0c34
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -reloc
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 01ed:a3ae
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:01ff -labels sub_cc5f,0ca6:020e
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard  0ed9:0def
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:14ef
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 0ca6:0232 -labels sub_cc92,0ca6:0268 -recursive -asm
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard 01ed:aa4e
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive -stackguard start,01ed:9c62 > bumpy.cpp
./cicodis $PWD/dos/B.EXE  -load 01ed -ctx -recursive start > bumpy.cpp
