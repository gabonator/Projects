arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis

./cicodis $PWD/dos/HISTORIK.EXE -load 01ed -recursive -ctx -segofscomment -stackguard -reloc start,1ed:14a,01ed:0151,01ed:0119,0ee7:010b,0ba1:0019,0a34:075a,0a34:0268,0ba1:0019 \
  -jumptable 19e4:02f6 19e4:02fb 39 jumpwords bx \
  -jumptable 19e4:06c3 19e4:06c8 38 jumpwords bx \
  -jumptable 1bf1:003e 1bf1:0043 38 jumpwords bx \
  -jumptable 19e4:05fb 19e4:0600 38 jumpwords bx \
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
  -jumptable 19e4:1211 19e4:1216 6 jumpwords bx \
  > historik.cpp

patch historik.cpp historik.patch

rm cicodis
