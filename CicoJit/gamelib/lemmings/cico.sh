arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.3/include/ -L/opt/homebrew/Cellar/capstone/5.0.3/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/VGALEMMI.EXE -indirect 1000:503b,1000:6170,1000:0f6f,1000:6957,1000:65d8,1000:64d9,1000:66d7,1000:6817,1000:6957,1000:6a97,1000:6bdb,1000:6cfc -recursive -ctxemu -reloc start > lemmi.cpp
