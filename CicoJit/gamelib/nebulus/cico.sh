arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis NEBEGA.EXE -ctx -recursive start,152d:003e > nebulus.cpp
diff nebulus.cpp cicorun/nebulus.cpp
rm cicodis
