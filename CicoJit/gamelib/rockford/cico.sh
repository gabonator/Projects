arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/ROCKFORD.EXE -ctx -reloc -recursive start,2cfb:548b \
  -jumptable 2cfb:ffff 2cfb:5018 188 callwords indirect \
  -jumptable 2cfb:ffff 2cfb:4f90 255 callwords indirect \
  > rockford.cpp

patch rockford.cpp rockford.patch
rm cicodis
