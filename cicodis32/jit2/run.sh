set -e
mkdir -p bin
#INDIRECTS=$(tr '\n' ' ' < indirects.txt)
./cicodis commands.txt > keen4.cpp
#cp keen4.clean keen4.cpp
#patch keen4.cpp ck4.patch
cd bin

if [ ! -e "miniz.o" ]; then
  arch -arm64 clang -g -c ../host/lib/miniz.c
fi
if [ ! -e "main.o" ]; then
  arch -arm64 clang++ -g -std=c++20 -c ../host/main.cpp `pkg-config --libs --cflags sdl2`
fi
arch -arm64 clang++ -g -std=c++20 -c ../keen4.cpp -I ../host
arch -arm64 clang++ -g keen4.o miniz.o main.o -o app `pkg-config --libs --cflags sdl2`
cd ..
bin/app | tee /dev/tty | tail -n 1 > tmp
echo CODE: $?
last_line=$(< tmp)
rm tmp
if [[ "$last_line" == *"MISSING INDIRECT CALL"* ]]; then
  #addr=${last_line##* }
  addresses=($(grep -oE '[0-9a-fA-F]{4}:[0-9a-fA-F]{4}' <<< "$last_line"))
  #echo '{"id": "indirectCall", "proc": "'"$addr"'"}' >> commands.txt
  echo '{"id": "indirectCall", "target": "'"${addresses[0]}"'", "origin": "'"${addresses[1]}"'"}' >> commands.txt
fi
if [[ "$last_line" == *"MISSING INDIRECT JUMP"* ]]; then
  #addr=${last_line##* }
  #echo '{"id": "indirectJump", "proc": "'"$addr"'"}' >> commands.txt
  addresses=($(grep -oE '[0-9a-fA-F]{4}:[0-9a-fA-F]{4}' <<< "$last_line"))
  echo '{"id": "indirectJump", "target": "'"${addresses[0]}"'", "origin": "'"${addresses[1]}"'", "parent": "'"${addresses[2]}"'"}' >> commands.txt
  #echo '{"id": "indirectJump", "target": "'"${addresses[0]}"'", "origin": "'"${addresses[1]}"'"}' >> commands.txt
fi
