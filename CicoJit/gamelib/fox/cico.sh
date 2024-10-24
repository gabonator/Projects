arch -arm64 clang++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/game.exe -ctx -recursive \
  -jumptable 1020:ffff 168f:6efb 30 callwords indirect \
  -jumptable 1020:ffff 168f:727d 19 callwords indirect \
  -jumptable 1020:ffff 168f:726f 26 callwords indirect \
  -jumptable 1020:ffff 168f:8eb5 38 callwords indirect \
  start > fox.cpp

#cp fox.cpp fox.clean
patch fox.cpp fox.patch
rm cicodis