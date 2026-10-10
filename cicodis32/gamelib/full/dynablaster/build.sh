#!/bin/bash
cd "$(dirname "$0")"
arch -arm64 g++ -std=c++20 host/dynablaster.cpp host/main.cpp -o dynablaster `pkg-config --libs --cflags sdl2`
./dynablaster
