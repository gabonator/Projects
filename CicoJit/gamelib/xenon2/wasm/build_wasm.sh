#!/bin/bash
mkdir -p build
cd build 

cp ../*.cpp .
cp ../*.h .

PATH=$PATH:~/Documents/git/ext/emsdk/upstream/emscripten
PATH=$PATH:~/Documents/git/ext/emsdk/upstream/bin

SOURCE="*.cpp"

NAME=app
BASE=http://localhost:8084/

INCLUDES=
EXPORTED_EXTRAS="'_xenonInfiniteEnergy', '_xenonStartLevel', '_xenonPowerup', '_xenonSkipIntro', '_xenonInfiniteLives', '_egaPalette'"
EXPORTED="['_appLoop', '_appInit', '_appFinish', '_appMemory', '_appBlit', '_appVideo', '_asyncifyBuffer', '_seed', ${EXPORTED_EXTRAS}]"
CONFIGURATION="-s TOTAL_STACK=1024 -s TOTAL_MEMORY=2097152 -s MINIMAL_RUNTIME=1 -s WASM=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 -s WARN_ON_UNDEFINED_SYMBOLS=0 -s ASSERTIONS=1 -sASYNCIFY "
#DEFINES=-DNDEBUG
emcc $INCLUDES $SOURCE -gsource-map -O3 --std=c++11 $CONFIGURATION $DEFINES --source-map-base $BASE -s EXPORTED_FUNCTIONS="${EXPORTED}" -o $NAME.js || exit 1

cat > pack.js <<- EOM

var app = process.argv.length == 3 ? process.argv[2] : "app";
var fs = require("fs");
var prefix = 'Module = typeof(Module) != "undefined" ? Module : {}; Module["wasmBinary"] = (() => { var wasmcode="';
var suffix = '"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();';

fs.writeFileSync(app+"_inline.js", prefix + fs.readFileSync(app + ".wasm").toString("base64") + suffix);
EOM

node pack app
rm pack.js
#cp ../app.js app.js
rm app.js
cp ../*.html .
cp ../*.js .
cp ../../resources.js .

# release
rm *.cpp *.h *.map app.wasm