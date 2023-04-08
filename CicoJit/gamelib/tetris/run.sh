arch -arm64 g++ -std=c++17 cicorun/etetris.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o tetris
./tetris