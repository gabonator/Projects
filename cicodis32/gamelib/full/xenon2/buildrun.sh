set -e
arch -arm64 g++ -std=c++20 host/xenon2.cpp host/main.cpp -o xenon2 `pkg-config --libs --cflags sdl2` 
./xenon2
