arch -arm64 g++ -std=c++17 ../../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis
./cicodis $PWD/dos/CC1.EXE -load 01ed -ctx -terminator 01ed:fb8f -segofscomment -stackguard -recursive -reloc start,2da3:0cb7,2a41:0359,1f5c:10d7 > cc1.cpp
patch cc1.cpp cc15.patch
