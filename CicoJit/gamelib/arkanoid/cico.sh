arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/REVOFDOH.DAT -ctx -recursive -load 10df -segofscomment start,\
19ee:0b84,19ee:0c92,19ee:0a09,19ee:02f7,19ee:095d,19ee:0418,19ee:0450,19ee:0a09,\
19ee:095d,\
1b0c:4221,1b0c:1135,1b0c:4069,1b0c:4efb,1b0c:4f2c,1b0c:43f3,1b0c:4221,1b0c:42a4,1b0c:42af \
  -jumptable 1b0c:ffff 1118:63ef 42 callwords indirect \
  -jumptable 1b0c:ffff 1118:498b 48 callwords indirect \
  -jumptable 1b0c:ffff 1118:49eb 48 callwords indirect \
  > arkanoid.clean

cp arkanoid.clean arkanoid.cpp
patch arkanoid.cpp arkanoid.patch
rm cicodis