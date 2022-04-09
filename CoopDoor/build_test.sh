mkdir -p build
cd build
g++ ../source/tests/astro.cpp  -std=c++11 -o astro
./astro

g++ ../source/tests/app.cpp  -std=c++11 -o app
./app
