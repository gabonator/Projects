arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
# fromRelative: return address_t{segment, (int)offset - 0x41b0};
./cicodis dos/rick1.exe -assume_ds 1040 -ctx -recursive start,341b:1448,341b:22cb,341b:228c,341b:259b,341b:2575,341b:1a01,341b:1a48,341b:2313,341b:2861,341b:25a3 > rick1.cpp
#./cicodis /Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/rick1/dos/rick1.exe -assume_ds 1040 -ctx -recursive start,sub_355f8,sub_3647b,sub_3643c,sub_3674b,sub_36725,sub_35bb1,sub_15658,sub_364c3,sub_36a11,sub_36753 > rick1.cpp
#diff goose.cpp cicorun/goose.cpp
#rm cicodis


#341b:1448,341b:22cb,341b:228c,341b:259b,341b:2575,341b:1a01,341b:1a48,341b:2313,341b:2861,341b:25a3