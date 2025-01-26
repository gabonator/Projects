FROM ubuntu
WORKDIR /app
RUN apt-get update && apt-get install -y curl build-essential cmake unzip

RUN cd /app && \
  mkdir download

RUN cd /app && \
  curl -L https://github.com/capstone-engine/capstone/archive/refs/tags/5.0.1.zip -o download/capstone.zip && \
  unzip download/capstone.zip && \
  cd capstone-5.0.1 && \
  mkdir build && \
  cd build && \
  cmake -DCAPSTONE_BUILD_TESTS=OFF -DCAPSTONE_ARCHITECTURE_DEFAULT=OFF -DCAPSTONE_X86_SUPPORT=ON .. && \
  cmake --build .

RUN cd /app && \
  curl -L https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/cicodis/cicodis/main.cpp -o download/cicodis.cpp

RUN cd /app && \
  mkdir bin && \
  cd bin && \
  c++ -static -I ../capstone-5.0.1/include ../download/cicodis.cpp -L ../capstone-5.0.1/build -lcapstone -o cicodis

RUN cd /app && \
  curl https://online.oldgames.sk/api/getrom/8807 -H "sec-fetch-site: same-origin" -o download/goose.zip && \
  unzip -o -d dos -j download/goose.zip \
    "Goose/GOOSE.EXE" \
    "Goose/BIRD1.X" \
    "Goose/BIRD2.X" \
    "Goose/BLOX.X" \
    "Goose/INTRO.X" \
    "Goose/NEWBIRD.X" \
    "Goose/PODZ1.X" 

RUN cd /app && \
  mkdir port && \
  cd port && \
  ../bin/cicodis ../dos/GOOSE.EXE -jumptable 1000:104e 1000:105a 35 callwords indirect -simplestack -ctx -recursive start > goose.cpp && \
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/main.cpp -o main.cpp && \
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/wasmhost.cpp -o wasmhost.cpp && \
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/cicoctx.h -o cicoctx.h && \
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/controls.h -o controls.h && \
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/ega.h -o ega.h && \
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/sdl.h -o sdl.h

RUN cd /app && \
  curl -L https://github.com/libsdl-org/SDL/releases/download/release-2.30.11/SDL2-2.30.11.tar.gz -o download/SDL2-2.30.11.tar.gz && \
  tar --exclude="android-project-ant" -xf download/SDL2-2.30.11.tar.gz && \
  cd SDL2-2.30.11 && \
  mkdir build && \
  cd build && \
  cmake .. && \
  make

RUN cd /app && \
  cd port && \
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/main.cpp -o main.cpp && \
  g++ -std=c++17 -I ../SDL2-2.30.11/include -c *.cpp && \
  g++ -std=c++17 -L ../SDL2-2.30.11/build *.o -lSDL2 -o ../bin/goose
