arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis $PWD/dos/game.exe -ctx -recursive  \
  -jumptable 1020:ffff 168f:6efb 30 callwords indirect \
  -jumptable 1020:ffff 168f:727d 19 callwords indirect \
  -jumptable 1020:ffff 168f:726f 26 callwords indirect \
  -jumptable 1020:ffff 168f:8eb5 38 callwords indirect \
  start > fox.cpp

patch fox.cpp fox.patch
rm cicodis