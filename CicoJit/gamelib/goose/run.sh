arch -arm64 g++ -std=c++17 cicorun/goose.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o goose
./goose