arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.3/include/ -L/opt/homebrew/Cellar/capstone/5.0.3/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/HISTORIK.EXE -load 01ed -recursive -ctx -segofscomment -stackguard -reloc start,1ed:14a,01ed:0151,01ed:0119,0ee7:010b,0ba1:0019,0a34:075a,0a34:0268,0ba1:0019,01ed:0328,01ed:0426,12f9:009c,12f9:0009,0a34:0034,0a34:0268 \
  -jumptable 19e4:02f6 19e4:02fb 40 jumpwords bx \
  -jumptable 19e4:06c3 19e4:06c8 39 jumpwords bx \
  -jumptable 1bf1:003e 1bf1:0043 39 jumpwords bx \
  -jumptable 19e4:05fb 19e4:0600 40 jumpwords bx \
  -jumptable 19e4:0afa 19e4:0aff 6 jumpwords bx \
  -jumptable 0a34:0c46 0a34:0c4b 4 jumpwords bx \
  -jumptable 0a34:0b4e 0a34:0b53 4 jumpwords bx \
  -jumptable 0a34:0d09 0a34:0d0e 4 jumpwords bx \
  -jumptable 19e4:1211 19e4:1216 6 jumpwords bx \
  -jumptable 023f:2051 023f:2056 2 jumpwords bx \
  -jumptable 023f:2c95 023f:2c9a 4 jumpwords bx \
  -jumptable 0a34:0e14 0a34:0e19 4 jumpwords bx \
  -jumptable 0a34:0f0b 0a34:0f10 4 jumpwords bx \
  -jumptable 0a34:0fc3 0a34:0fc8 4 jumpwords bx \
  -jumptable 0a34:10a4 0a34:10a9 4 jumpwords bx \
  -jumptable 0a34:11f2 0a34:11f7 4 jumpwords bx \
  -jumptable 0a34:1311 0a34:1316 4 jumpwords bx \
  -jumptable 0a34:13fe 0a34:1403 4 jumpwords bx \
  -jumptable 0a34:14f4 0a34:14f9 4 jumpwords bx \
  -jumptable 0a34:15ce 0a34:15d3 4 jumpwords bx \
  -jumptable 1162:0287 1162:028c 9 jumpwords bx \
  -jumptable 15bc:0717 15bc:071c 3 jumpwords bx \
  > prehistorik.clean

cp prehistorik.clean prehistorik.cpp
patch prehistorik.cpp prehistorik.patch

sed -E \
    -e 's/memoryASet16\(([^,]+), ([^,]+), (.+)\);/memory16(\1, \2) = \3;/' \
    -e 's/memoryAGet16\(([^,]+), ([^,]+)\)/memory16(\1, \2)/g' \
    -e 's/memoryASet\(([^,]+), ([^,]+), (.+)\);/memory(\1, \2) = \3;/' \
    -e 's/memoryAGet\(([^,]+), ([^,]+)\)/memory(\1, \2)/g' \
    -e 's/MemAuto/MemData/g' \
    -e 's/DirAuto/DirForward/g' \
  prehistorik.cpp > prehistorikopt.clean
cp prehistorikopt.clean prehistorikopt.cpp
patch prehistorikopt.cpp prehistorikopt.patch
rm cicodis
