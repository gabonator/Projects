arch -arm64 g++ -std=c++17 cicorun/popcorn.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o popcorn
./popcorn