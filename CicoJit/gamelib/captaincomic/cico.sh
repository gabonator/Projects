#arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
#./cicodis dos/comic.exe -ctx -recursive start > comic.cpp
./cicodis dos/comic.exe -asm sub_11327
#rm cicodis
