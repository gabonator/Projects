arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/CC1.EXE -load 01ed -ctx -terminator 01ed:fb8f -segofscomment -stackguard -recursive -reloc start,1f5c:10d7,01ed:0727 \
  -indirect 2da3:0cb7,2a41:0359,2188:3f13,2188:1fb9,2188:2850,2188:2877,2188:6ff6,2188:70e4,2188:3d23,2188:1fb9,2188:3f13,2188:6afa,2188:6d31 > cc1.clean
cp cc1.clean cc1.cpp
patch cc1.cpp cc1.patch
rm cicodis
