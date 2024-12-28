arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.3/include/ -L/opt/homebrew/Cellar/capstone/5.0.3/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/rick1.exe -assume_ds 1040 -ctx -recursive start \
   -jumptable 341b:228a 1040:80bf 24 jumpwords di > rick1.clean
cp rick1.clean rick1.cpp
patch rick1.cpp rick1.patch
rm cicodis
