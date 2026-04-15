g++ --std=c++17 ./main.cpp ./nexus.cpp -o test.elf
arch --arm64 ./test.elf "res/PN Nexus Grandpiano.fxp" test.wav