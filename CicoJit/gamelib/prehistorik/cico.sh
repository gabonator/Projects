arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis $PWD/dos/HISTORIK.EXE -load 01ed -recursive -ctx -segofscomment -stackguard -reloc start,1ed:14a,01ed:0151 > historik.cpp
rm cicodis
