#arch -arm64 g++ -std=c++20 ../cicodis32/main.cpp ../cicodis32/miniz.cpp -I/opt/homebrew/Cellar/capstone/5.0.5/include -L/opt/homebrew/Cellar/capstone/5.0.5/lib -lcapstone.5 -o cicodis
#P=/Users/gabrielvalky/Documents/git/CleanRoom/cicodis/cicodis-clean/cicodis-clean/
P=../cicodis32/
arch -arm64 g++ -std=c++20 ${P}/*.cpp ${P}/lib/miniz.cpp -I/opt/homebrew/Cellar/capstone/5.0.5/include -L/opt/homebrew/Cellar/capstone/5.0.5/lib -lcapstone.5 -o cicodis

