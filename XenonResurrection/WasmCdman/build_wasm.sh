mkdir -p build
cd build 

PATH=$PATH:~/Documents/git/ext/emsdk/upstream/emscripten
PATH=$PATH:~/Documents/git/ext/emsdk/upstream/bin

INCLUDES=""

SOURCE="\
  ../source/main.cpp \
  ../source/app/cdman.cpp \
  ../source/app/indirect.cpp \
  ../source/cpu.cpp \
  ../source/machine.cpp \
  ../source/interface.cpp \
"

NAME=cdman
BASE=http://localhost:8080/build/
#BASE=/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/WasmCdman/build

EXPORTED="['_appLoop', '_appInit', '_appFinish', '_appMemory', '_appVideoBuffer', '_appKeyboardBuffer']"
CONFIGURATION="-s TOTAL_STACK=1024 -s TOTAL_MEMORY=2359296 -s MINIMAL_RUNTIME=1 -s WASM=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s WARN_ON_UNDEFINED_SYMBOLS=1 -DEMSCRIPTEN_HAS_UNBOUND_TYPE_NAMES=0 -fno-rtti"
#  -DEMSCRIPTEN_HAS_UNBOUND_TYPE_NAMES=0 -fno-rtti
DEFINES="-DEMSCRIPTEN"
emcc -s ASSERTIONS=1 $INCLUDES $SOURCE -g4 -O3 --std=c++11 $CONFIGURATION $DEFINES --source-map-base $BASE -s EXPORTED_FUNCTIONS="${EXPORTED}" -o $NAME.js || exit 1
#node ../../../os_platform/wasm/htmllite/package.js $NAME

cd ../web
node fsbuild
cd ..
http-server .