arch -arm64 g++ -std=c++17 cicorun/xenon2.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o xenon2
./xenon2