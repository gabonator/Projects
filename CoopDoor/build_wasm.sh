#!/bin/bash
mkdir -p build
cd build 

PATH=$PATH:~/Documents/git/ext/emsdk/upstream/emscripten
PATH=$PATH:~/Documents/git/ext/emsdk/upstream/bin

SOURCE="../source/wasm/wasmhost.cpp"

NAME=app
BASE=http://localhost:8084/

INCLUDES=
#EXPORTED="['_appLoop', '_appInit', '_appFinish', '_apiDebug', '_apiShow']"
EXPORTED="['_appLoop', '_appInit', '_appFinish']"
CONFIGURATION="-s TOTAL_STACK=1024 -s TOTAL_MEMORY=65536 -s MINIMAL_RUNTIME=1 -s WASM=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s WARN_ON_UNDEFINED_SYMBOLS=0"
DEFINES="-DEMULATED -DEMSCRIPTEN"
emcc $INCLUDES $SOURCE -gsource-map -O3 --std=c++11 $CONFIGURATION $DEFINES --source-map-base $BASE -s EXPORTED_FUNCTIONS="${EXPORTED}" -o $NAME.js || exit 1
node /Users/gabrielvalky/Documents/git/LA104/system/os_platform/wasm/htmllite/package.js $NAME

cp ../source/wasm/app.html app.html
