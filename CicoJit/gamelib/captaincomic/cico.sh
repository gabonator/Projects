arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis $PWD/dos/comic.exe -load 01ed -segofscomment -ctx -recursive start,1ed:4a3,1ed:3f5,1ed:3a2,1ed:3e3,1ed:4a3 > comic.cpp
patch comic.cpp comic.patch
rm cicodis