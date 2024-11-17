arch -arm64 clang++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/game.exe -ctx -recursive \
  -jumptable 1020:42e6 168f:6efb 30 callwords bx \
  -jumptable 1020:45a0 168f:727d 19 callwords bx \
  -jumptable 1020:45cf 168f:7299 59 callwords bx \
  -jumptable 1020:4629 168f:726f 14 callwords bx \
  -jumptable 1020:5961 168f:8eb5 38 callwords bx \
  -jumptable 1020:464b 168f:726F 26 callwords bx \
  -jumptable 1020:57e4 168f:8EDB 19 callwords bx \
  start > fox.clean

cp fox.clean fox.cpp
patch fox.cpp fox.patch
rm cicodis
