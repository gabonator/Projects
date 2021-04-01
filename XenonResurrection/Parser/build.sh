set -e
mkdir -p build
cd build
#gcc -Wall -std=c++17 ../CicParser2021/main.cpp -o cicoparser
g++ -std=c++17 ../CicParser2021/main.cpp -o cicoparser -stdlib=libc++
