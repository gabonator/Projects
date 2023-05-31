arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis $PWD/dos/MAIN.EXE -ctx -recursive start \
  -jumptable 1040:ffff 1040:0000 38 callwords indirect \
  -jumptable 1040:ffff 1040:9bb8 15 callwords indirect \
  > rick2.cpp
patch rick2.cpp rick2.patch
rm cicodis
