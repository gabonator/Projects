arch -arm64 g++ -std=c++17 cicorun/cc1.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o cc1
./cc1