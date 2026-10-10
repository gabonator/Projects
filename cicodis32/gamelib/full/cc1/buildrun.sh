set -e
arch -arm64 g++ -g -std=c++20 cpp/cc1.cpp cpp/main.cpp -o cc1 `pkg-config --libs --cflags sdl2` 
./cc1
