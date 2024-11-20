arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/POPCORN.EXE -ctx -recursive \
  -jumptable 2ac2:ffff 1000:3046 12 callwords indirect \
  -jumptable 2ac2:ffff 1000:33bc 12 callwords indirect \
  -jumptable 2ac2:3c0f 1000:3447 4 callwordsbyofs indirect \
  start \
  -indirect 2ac2:16d2,2ac2:3b2a,2ac2:3561,2ac2:3273,2ac2:365e,2ac2:366f,2ac2:3696,2ac2:36f6,2ac2:36a1,2ac2:37e0,2ac2:3717,2ac2:39fa,2ac2:390d,2ac2:2def,2ac2:3386,2ac2:1785,2ac2:3aee \
  > popcorn.clean

cp popcorn.clean popcorn.cpp
patch popcorn.cpp popcorn.patch
rm cicodis
#  indirect 2ac2:1b5e - 2ac2:3aee
#  -jumptable 2ac2:ffff 1000:3447 4 callwords indirect \
#  -jumptable 2ac2:3c0f 2ac2:3c66 1 call indirect \
#./cicodis $PWD/dos/ARKCLONE/POPCORN.EXE -ctx -recursive start > popcorn.cpp
#./cicodis $PWD/dos/ARKCLONE/POPCORN.EXE -asm sub_2d4a1
#exit 0
