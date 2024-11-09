arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/av.exe -segofscomment -stackguard -load 01ed -ctx -recursive \
  start -recursive \
  -jumptable 01ed:1a43 01ed:1a48 6 jumpwords bx \
  -jumptable 01ed:1d3c 01ed:1d41 5 jumpwords bx \
  -jumptable 01ed:21fe 01ed:2203 3 jumpwords bx \
  -jumptable 01ed:2231 01ed:2236 3 jumpwords bx \
  -jumptable 08e6:0004 08e6:000f 0-28 callwords si \
  -jumptable 043e:0005 043e:0016 0-28 callwords si \
  -indirect 043e:0000,08e6:0000,01ed:017d,01ed:3e92,08e6:0000,043e:0000,043e:0482,043e:07f1,043e:0538,043e:0548,043e:0072 \
  > av.clean

cp av.clean av.cpp
patch av.cpp av.patch
rm cicodis