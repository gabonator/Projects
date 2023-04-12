arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis dos/ARKCLONE/POPCORN.EXE -ctx -recursive start > popcorn.cpp
#diff goose.cpp cicorun/goose.cpp
rm cicodis
