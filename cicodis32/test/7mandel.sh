arch -arm64 g++ -std=c++17 ./6mandel.cpp -o 8mandel.elf
#./8mandel.elf
#exit 0
arch -arm64 ./8mandel.elf > 9mandel.pgm
magick 9mandel.pgm 9mandel.png