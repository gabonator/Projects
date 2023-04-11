arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis dos/CAT.EXE -ctx -recursive -labels sub_17230,loc_17612,loc_17689,loc_175c4,loc_17579,loc_1752e,loc_174da,loc_17490 start > cat.cpp
patch cat.cpp cat.patch 
diff cat.cpp cicorun/cat.cpp
rm cicodis
