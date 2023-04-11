arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis dos/game.exe -ctx -recursive start,1020:5dce,1020:476c,1020:4dfd,1020:4e87,1020:63f1,1020:63bf,1020:4d0b,1020:4748,1020:47b7,1020:47fa,1020:4df9,1020:47b7,1020:47d3,1020:5a04,1020:4e88,1020:4d0c,1020:4dc9,1020:4d10,1020:4db1,1020:4826,1020:4f03,1020:4e2e,1020:495b,1020:48cc,1020:48d6,1020:622e,1020:4833,1020:14e5,1020:157c,1020:147a,1020:147d,1020:1585,1020:14dd,1020:158c,1020:1591 > fox.cpp
patch fox.cpp fox.patch 
diff fox.cpp cicorun/fox.cpp
rm cicodis
