set -e
mkdir -p bin
INDIRECTS=$(tr '\n' ' ' < indirects.txt)
./cicodis $INDIRECTS > keen4.clean
cp keen4.clean keen4.cpp
patch keen4.cpp ck4.patch
cd bin

if [ ! -e "miniz.o" ]; then
  arch -arm64 clang -c ../host/lib/miniz.c
fi
if [ ! -e "main.o" ]; then
  arch -arm64 clang++ -std=c++20 -c ../host/main.cpp `pkg-config --libs --cflags sdl2`
fi
arch -arm64 clang++ -g -std=c++20 -c ../keen4.cpp -I ../host
arch -arm64 clang++ keen4.o miniz.o main.o -o app `pkg-config --libs --cflags sdl2`
cd ..
bin/app | tee /dev/tty | tail -n 1 > tmp
echo CODE: $?
last_line=$(< tmp)
rm tmp
if [[ "$last_line" == *"MISSING INDIRECT"* ]]; then
  addr=${last_line##* }
  echo $addr >> indirects.txt
fi
