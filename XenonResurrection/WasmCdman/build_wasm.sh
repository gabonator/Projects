mkdir build
cd build 

PATH=$PATH:~/Documents/git/ext/emsdk/upstream/emscripten
PATH=$PATH:~/Documents/git/ext/emsdk/upstream/bin

INCLUDES=""

SOURCE="\
  ../source/main.cpp \
"

NAME=cdman
BASE=http://localhost:8080/apps/

EXPORTED="['_appLoop', '_appInit', '_appFinish']"
CONFIGURATION="-s TOTAL_STACK=1024 -s TOTAL_MEMORY=65536 -s MINIMAL_RUNTIME=1 -s WASM=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s WARN_ON_UNDEFINED_SYMBOLS=1"
DEFINES="-DEMSCRIPTEN"
emcc $INCLUDES $SOURCE -g4 -O3 --std=c++11 $CONFIGURATION $DEFINES --source-map-base $BASE -s EXPORTED_FUNCTIONS="${EXPORTED}" -o $NAME.js || exit 1
#node ../../../os_platform/wasm/htmllite/package.js $NAME


