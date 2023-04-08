arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis etetris.exe -ctx -assume_ds 100d -recursive start > etetris.cpp
patch etetris.cpp tetris.patch 
diff etetris.cpp cicorun/etetris.cpp
rm cicodis
