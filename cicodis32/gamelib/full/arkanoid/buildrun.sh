set -e
arch -arm64 g++ -g -std=c++20 run/*.cpp -o app.elf `pkg-config --libs --cflags sdl2`
./app.elf
#./app.elf 16 0 # boss