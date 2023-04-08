arch -arm64 g++ -std=c++17 cicorun/rick2.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o rick2
./rick2