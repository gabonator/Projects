#!/bin/bash
mkdir -p build
cd build 

cp ../*.cpp ../*.h ../*.html ../*.js ../*.zip .

PATH=$PATH:~/Documents/git/ext/emsdk/upstream/emscripten
PATH=$PATH:~/Documents/git/ext/emsdk/upstream/bin

SOURCE="*.cpp"

NAME=app
BASE=http://localhost:8123/

INCLUDES=""
EXPORTED="['_appMain', '_asyncifyBuffer', '_appFrameBuffer', '_mouseX', '_mouseY', '_mouseB']"
CONFIGURATION="-s TOTAL_STACK=1024 -s TOTAL_MEMORY=5242880 -s MINIMAL_RUNTIME=1 -s WASM=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s WARN_ON_UNDEFINED_SYMBOLS=0 -s ASSERTIONS=1 -s ASYNCIFY"
DEFINES=-DNDEBUG
emcc $INCLUDES $SOURCE -gsource-map -O0 --std=c++11 $CONFIGURATION $DEFINES --source-map-base $BASE -s EXPORTED_FUNCTIONS="${EXPORTED}" -o $NAME.js || exit 1

rm app.js

# release
rm *.cpp *.h *.map