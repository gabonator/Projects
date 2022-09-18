set -e
(
  cd ../test
  for f in *.cpp; do
    input=$f
    output=../intermediate/${f%.*}
    if [ ! -f $output ];
    then
      echo $f
      g++ -DCICOHOST $f -I ../host/ -std=c++11 -shared -o ../intermediate/${f%.*}
    fi
    if [ $input -nt $output ];
    then
      echo $f
      g++ -DCICOHOST $f -I ../host/ -std=c++11 -shared -o ../intermediate/${f%.*}
    fi
  done
)
g++ main.cpp -o main -I /opt/homebrew/Cellar/sdl2/2.24.0/include/SDL2/ -L /opt/homebrew/Cellar/sdl2/2.24.0/lib/ -lsdl2 -std=c++11
./main