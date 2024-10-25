arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis
./cicodis $PWD/dos/ETETRIS.EXE -ctx -assume_ds 100d -recursive start \
  -jumptable 1839:1aab 100d:5ce2 22 jumpwords di \
  > etetris.cpp

patch etetris.cpp tetris.patch 
rm cicodis
