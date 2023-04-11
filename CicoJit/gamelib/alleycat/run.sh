arch -arm64 g++ -std=c++17 cicorun/cat.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o cat
./cat