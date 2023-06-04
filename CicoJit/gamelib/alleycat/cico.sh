arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis $PWD/dos/CAT.EXE -ctx -recursive start -jumptable 1723:024b 1723:0250 8 jumpwords bx > cat.cpp
patch cat.cpp cat.patch 
rm cicodis
