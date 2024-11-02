arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis

#./cicodis $PWD/dos/REVOFDOH.DAT -ctx -load 10df -asm 1b0c:29cd -jumptable 1b0c:28e1 1118:4901 1-26 jumpwords indirect -jumptable 1b0c:29e7 1118:491b 14 jumpwords bx
#./cicodis $PWD/dos/REVOFDOH.DAT -ctx -recursive -load 10df -raw words 1118:491b 50
#./cicodis $PWD/dos/REVOFDOH.DAT -ctx -recursive -load 10df 1b0c:40ac
#exit 0
if false; then
./cicodis $PWD/dos/REVOFDOH.DAT -segofscomment -asm -ctx -coverage -recursive -load 10df -segofscomment start,1b0c:1309 \
 -indirect \
19ee:0b84,19ee:0c92,19ee:0a09,19ee:02f7,19ee:095d,19ee:0418,19ee:0450,19ee:0a09,\
19ee:095d,\
1b0c:4221,1b0c:1135,1b0c:4069,1b0c:4efb,1b0c:4f2c,1b0c:43f3,1b0c:4221,1b0c:42a4,1b0c:42af,1b0c:4f43 \
  -jumptable 1b0c:ffff 1118:63ef 42 callwords indirect \
  -jumptable 1b0c:ffff 1118:498b 48 callwords indirect \
  -jumptable 1b0c:ffff 1118:49eb 48 callwords indirect \
  -jumptable 1b0c:ffff 1118:49bb 49 callwords indirect \
> arkanoid.cov
fi

./cicodis $PWD/dos/REVOFDOH.DAT -ctx -recursive -load 10df -segofscomment start,1b0c:1309,1b0c:40ac \
 -indirect \
19ee:0b84,19ee:0c92,19ee:0a09,19ee:02f7,19ee:095d,19ee:0418,19ee:0450,19ee:0a09,\
19ee:095d,\
1b0c:4221,1b0c:1135,1b0c:4069,1b0c:4efb,1b0c:4f2c,1b0c:43f3,1b0c:4221,1b0c:42a4,1b0c:42af,1b0c:4f43 \
  -jumptable 1b0c:ffff 1118:63ef 42 callwords indirect \
  -jumptable 1b0c:ffff 1118:498b 48 callwords indirect \
  -jumptable 1b0c:ffff 1118:49eb 48 callwords indirect \
  -jumptable 1b0c:ffff 1118:49bb 49 callwords indirect \
  -jumptable 1b0c:28e1 1118:4901 1-26 jumpwords bx \
  -jumptable 1b0c:29e7 1118:491b 14 jumpwords bx \
  > arkanoid.clean


cp arkanoid.clean arkanoid.cpp
patch arkanoid.cpp arkanoid.patch
rm cicodis
