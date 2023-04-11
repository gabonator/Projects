arch -arm64 g++ -std=c++17 cicorun/fox.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o fox
./fox