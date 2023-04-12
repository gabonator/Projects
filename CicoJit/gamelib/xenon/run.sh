arch -arm64 g++ -std=c++17 cicorun/xenon.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o xenon
./xenon