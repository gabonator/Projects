set -e
arch -arm64 g++ -O3 -D NDEBUG -D NORENDER main.cpp rick2.cpp wasmhost.cpp -std=c++17 -o rick2
time ./rick2
time ./rick2
time ./rick2

# iterating 42739 frames on Macbook air M1, 2020 (approx 30000 frames per second)
#
#real    0m1.598s
#user    0m1.407s
#sys     0m0.006s
#
#real    0m1.374s
#user    0m1.368s
#sys     0m0.004s
#
#real    0m1.375s
#user    0m1.368s
#sys     0m0.004s

g++ -O3 main.cpp rick2.cpp wasmhost.cpp -std=c++17 -o rick2
./rick2 | ffmpeg -f rawvideo -pixel_format rgba -video_size 320x200 -framerate 40 -y -i - -c:v h264 output.mp4
