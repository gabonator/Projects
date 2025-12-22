set -e
#sdl2 play
arch -arm64 g++ -std=c++20 -DUSE_REPLAY=0 -DUSE_SDL=1 -DUSE_STREAM=0 main.cpp wasmhost.cpp rick2.cpp -o app.elf `pkg-config --libs --cflags sdl2`
arch -arm64 ./app.elf

#sdl2 replay
#arch -arm64 g++ -std=c++20 -DUSE_REPLAY=1 -DUSE_SDL=1 -DUSE_STREAM=0 main.cpp wasmhost.cpp rick2.cpp -o app.elf `pkg-config --libs --cflags sdl2`
#arch -arm64 ./app.elf

#video stream
#arch -arm64 g++ -std=c++20 -DUSE_REPLAY=1 -DUSE_SDL=0 -DUSE_STREAM=1 main.cpp wasmhost.cpp rick2.cpp -o app.elf `pkg-config --libs --cflags sdl2`
#arch -arm64 ./app.elf | ffmpeg -f rawvideo -pixel_format bgra -video_size 320x200 -framerate 40 -y -i - -c:v h264 output.mp4
