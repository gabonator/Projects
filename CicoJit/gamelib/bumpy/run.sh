arch -arm64 g++ -std=c++17 cicorun/bumpy.cpp cicorun/main.cpp `pkg-config --libs --cflags sdl2` -o bumpy
./bumpy

exit 0
level=9
for room in {1..12}; do
    rm res/temp.bmp
    ./bumpy res/temp.bmp $level $room
    convert res/temp.bmp  -resize 200% res/$(printf "%02d" $level)$(printf "%02d" $room)bkg.png
done
