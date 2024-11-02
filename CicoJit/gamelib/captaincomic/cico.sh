arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis
./cicodis $PWD/dos/comic.exe -load 01ed -segofscomment -ctx -recursive start -indirect 1ed:4a3,1ed:3f5,1ed:3a2,1ed:3e3 > comic.clean
cp comic.clean comic.cpp
patch comic.cpp comic.patch
rm cicodis