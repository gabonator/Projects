set -x
node optimize
arch -arm64 g++ -std=c++17 cicorun/rick1.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o rick1
./rick1