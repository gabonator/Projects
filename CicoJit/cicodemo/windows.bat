@echo off
echo Cicojit Disassembler demo - Gabriel Valky 2025

if not exist download mkdir download
if not exist bin mkdir bin

if not exist mingw32 (
  curl -L https://github.com/brechtsanders/winlibs_mingw/releases/download/14.2.0posix-19.1.1-12.0.0-msvcrt-r2/winlibs-i686-posix-dwarf-gcc-14.2.0-mingw-w64msvcrt-12.0.0-r2.zip -o download\mingw32.zip
  tar -xvzf download\mingw32.zip
)

if not exist capstone-5.0.1 (
  curl -L https://github.com/capstone-engine/capstone/archive/refs/tags/5.0.1.zip -o download\capstone.zip
  tar -xvzf download\capstone.zip
)

set PATH=%PATH%;%~dp0\mingw32\bin

if not exist capstone-5.0.1\build\libcapstone.a (
  cd capstone-5.0.1
  mkdir build
  cd build
  cmake -DCAPSTONE_BUILD_TESTS=OFF -DCAPSTONE_ARCHITECTURE_DEFAULT=OFF -DCAPSTONE_X86_SUPPORT=ON ..
  cmake --build .
  cd ..\..
)

if not exist bin\cicodis.exe (
  curl -L https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/cicodis/cicodis/main.cpp -o download\cicodis.cpp
  cd bin
  c++ -static -I ../capstone-5.0.1/include ../download/cicodis.cpp -L ../capstone-5.0.1/build -lcapstone -o cicodis.exe
  cd ..
)

if not exist dos (
  curl https://online.oldgames.sk/api/getrom/8807 -H "sec-fetch-site: same-origin" -o download\goose.zip
  mkdir temp
  tar -xvzf download\goose.zip -C temp
  mkdir dos
  move temp\Goose\*.EXE dos
  move temp\Goose\*.X dos
  rmdir /s /q temp
)

if not exist port (
  mkdir port
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/main.cpp -o port/main.cpp
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/wasmhost.cpp -o port/wasmhost.cpp
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/sdl.h -o port/sdl.h
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/ega.h -o port/ega.h
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/controls.h -o port/controls.h
  curl https://raw.githubusercontent.com/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/sdl/cicoctx.h -o port/cicoctx.h
)

if not exist port\goose.cpp (
  bin\cicodis dos\GOOSE.EXE -jumptable 1000:104e 1000:105a 35 callwords indirect -simplestack -ctx -recursive start > port\goose.cpp
)

if not exist sdl2-2.30.11 (
  curl -L https://github.com/libsdl-org/SDL/releases/download/release-2.30.11/SDL2-devel-2.30.11-mingw.zip -o download/sdl2.zip
  tar -xvzf download/sdl2.zip
)

if not exist bin/goose.exe (
  cd port
  g++ main.cpp goose.cpp wasmhost.cpp -I ../SDL2-2.30.11/i686-w64-mingw32/include/SDL2 -L ../SDL2-2.30.11/i686-w64-mingw32/lib -lmingw32 -lSDL2main -lSDL2 -o ../bin/goose
  copy ..\mingw32\bin\libgcc_s_dw2-1.dll ..\bin
  copy "..\mingw32\bin\libstdc++-6.dll" ..\bin
  copy ..\mingw32\bin\libwinpthread-1.dll ..\bin
  copy ..\SDL2-2.30.11\i686-w64-mingw32\bin\SDL2.dll ..\bin
  cd ..
)

cd bin
goose.exe
