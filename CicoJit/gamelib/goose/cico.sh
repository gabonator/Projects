arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis
./cicodis $PWD/dos/GOOSE.EXE \
  -jumptable 1000:ffff 1000:105a 35 callwords indirect \
  -simplestack -ctx -recursive start > goose.cpp
# 1000:104e
#diff goose.cpp cicorun/goose.cpp
rm cicodis
