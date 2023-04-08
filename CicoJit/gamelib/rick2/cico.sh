arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis rd2.exe -ctx -recursive start,10524,10533,10594,105a1,105cc,10702,107f1,10836,1087b,109c4,109d3,109ee,10a67,1091b,10d03,10df8,10d3d,10e23,10e40,11162,112d6,11376,107ac,108dd,111f1,10bc4,10c2e,10ee8,109a5,10986,10ea6,10ec0,10e7f,1a168,1a121,1a155,1a137,1a1bc,1a1e4,1a2f6,1a23e,1a1e6,1a13f,10ee7,10ee6,10ee5,10ee4 > rick2.cpp
patch rick2.cpp rick2.patch 
diff rick2.cpp cicorun/rick2.cpp
rm cicodis
