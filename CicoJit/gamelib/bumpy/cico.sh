arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.3/include/ -L/opt/homebrew/Cellar/capstone/5.0.3/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/B.EXE -load 01ed -ctx -reloc -recursive -negative 65500 \
  -jumptable 01ed:46dc 01ed:4725 4 jumpwords bx \
  -jumptable 01ed:37db 01ed:384a 4 jumpwords bx \
  -jumptable 01ed:6e7e 01ed:70e7 20 jumpwords bx \
  start \
  -jumptable 01ed:ffff 1228:43c0 1085 callwords indirect \
  -jumptable 01ed:ffff 1227:0002 1 callwords indirect \
  -jumptable 01ed:ffff 1227:0008 1 callwords indirect \
  -jumptable 0ca6:ffff 1228:694a 1 callwords indirect \
  -jumptable 0ca6:0264 1228:5469 3 jumpwords bx \
  -jumptable 0ca6:020a 1228:545d 6 jumpwords bx \
  -jumptable 0e15:ffff 1228:4e37 12 callwords indirect \
  -jumptable 0ca6:ffff 1228:4dda 7 callwords indirect \
  -jumptable 0ca6:ffff 1228:4dcc 7 callwords indirect \
  -jumptable 0ca6:ffff 1228:5435 14 callwords indirect \
  -jumptable 0ca6:ffff 1228:5451 2 callwords indirect \
  -jumptable 0ca6:ffff 1228:5544 19 callwords indirect \
  -jumptable 0ca6:ffff 1228:5550 13 callwords indirect \
  -jumptable 0ca6:ffff 1228:56c2 6 callwords indirect \
  -jumptable 0ca6:0374 1228:5475 3 jumpwords bp \
  -jumptable 0ed9:11d3 0ed9:210b 1 jumpfix ax \
  -jumptable 0ed9:25e4 0ed9:2004 1 jumpfix ax \
  -jumptable 0ed9:25e4 0ed9:2063 1 jumpfix ax \
  -jumptable 0ed9:25e4 0ed9:1f46 1 jumpfix ax \
  -jumptable 0ed9:25e4 0ed9:20fa 1 jumpfix ax \
  -jumptable 0ca6:ffff 1228:6952 5 callwords indirect \
  -jumptable 0ca6:ffff 1228:568a 3 callwords indirect \
  -jumptable 01ed:ffff 1228:07ca 64 callwords indirect \
  -jumptable 01ed:ffff 1228:0870 11 callwords indirect \
  -jumptable 01ed:ffff 1228:085c 21 callwords indirect \
  -jumptable 0ca6:ffff 1228:5536 26 callwords indirect \
  -indirect 0ed9:0def,01ed:a3ae,0ed9:0c34,1223:0015,0ca6:0aa0,0ca6:0823,0ca6:1087,0ed9:0e29,0ed9:10e1,0ca6:0db0 \
\
   > bumpy.clean
#  -sync sub_24b7,sub_2c6d,sub_4fad,sub_515f,sub_5475,sub_5722,sub_cd2e,sub_12190,sub_12245 

cp bumpy.clean bumpy.cpp
patch bumpy.cpp bumpy.patch
patch bumpy.cpp bumpyextras2.patch

sed -E \
    -e 's/memoryASet16\(([^,]+), ([^,]+), (.+)\);/memory16(\1, \2) = \3;/' \
    -e 's/memoryAGet16\(([^,]+), ([^,]+)\)/memory16(\1, \2)/g' \
    -e 's/memoryASet\(([^,]+), ([^,]+), (.+)\);/memory(\1, \2) = \3;/' \
    -e 's/memoryAGet\(([^,]+), ([^,]+)\)/memory(\1, \2)/g' \
    -e 's/MemAuto/MemData/g' \
    -e 's/DirAuto/DirForward/g' \
  bumpy.cpp > bumpyopt.clean
cp bumpyopt.clean bumpyopt.cpp
patch bumpyopt.cpp bumpyopt.patch
rm cicodis
