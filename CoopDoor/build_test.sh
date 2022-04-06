mkdir -p build
cd build
g++ ../source/tests/test.cpp  -std=c++11 -o test
./test
