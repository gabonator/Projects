arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.1/include/ -L/opt/homebrew/Cellar/capstone/5.0.1/lib -lcapstone.5 -o cicodis
./cicodis $PWD/dos/GOOSE.EXE -asm -coverage \
  -jumptable 1000:104e 1000:105a 35 callwords indirect \
  -simplestack -ctx -recursive start,1000:05fc,1000:04b7,1000:05ce > goose.cpp

../../cicocov/coverage.sh goose.cpp
echo '<script src="goose.cov"></script>' > coverage.html
cat ../../cicocov/coverage.html >> coverage.html

./cicodis $PWD/dos/GOOSE.EXE \
  -jumptable 1000:104e 1000:105a 35 callwords indirect \
  -simplestack -ctx -recursive start > goose.cpp

rm cicodis
