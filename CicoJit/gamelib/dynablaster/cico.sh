arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis
./cicodis $PWD/dos/dyna.exe -load 01ed -ctx -reloc -recursive start > dynablaster.cpp
rm cicodis

#./cicodis $PWD/dos/dyna.exe -load 01ed -segofscomment 01ed:1410,01ed:1501
# timer 01ed:1355,01ed:13f8,01ed:140d

