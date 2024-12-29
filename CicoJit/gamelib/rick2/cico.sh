arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.3/include/ -L/opt/homebrew/Cellar/capstone/5.0.3/lib -lcapstone.5 -o cicodis

./cicodis $PWD/dos/MAIN.EXE -asm -coverage -ctx -recursive start \
  -jumptable 1040:ffff 1040:0000 38 callwords indirect \
  -jumptable 1040:ffff 1040:9bb8 15 callwords indirect \
  > rick2.cpp

../../cicocov/coverage.sh rick2.cpp
echo '<script src="rick2.cov"></script>' > coverage.html
cat ../../cicocov/coverage.html >> coverage.html

./cicodis $PWD/dos/MAIN.EXE -ctx -recursive start \
  -jumptable 1040:ffff 1040:0000 38 callwords indirect \
  -jumptable 1040:ffff 1040:9bb8 15 callwords indirect \
  > rick2.clean
cp rick2.clean rick2.cpp
patch rick2.cpp rick2.patch
rm cicodis

sed -E \
    -e 's/memoryASet16\(([^,]+), ([^,]+), (.+)\);/memory16(\1, \2) = \3;/' \
    -e 's/memoryAGet16\(([^,]+), ([^,]+)\)/memory16(\1, \2)/g' \
    -e 's/memoryASet\(([^,]+), ([^,]+), (.+)\);/memory(\1, \2) = \3;/' \
    -e 's/memoryAGet\(([^,]+), ([^,]+)\)/memory(\1, \2)/g' \
    -e 's/MemAuto/MemData/g' \
    -e 's/DirAuto/DirForward/g' \
  rick2.cpp > rick2opt.clean
cp rick2opt.clean rick2opt.cpp
