set -e
mkdir -p build
cd build
em++ -I ../ ../source/main.cpp -o code.wasm -O3 -s EXPORTED_FUNCTIONS="['_new_loop', '_new_onPress', '_new_onRelease', '_LED_BUFFER', '_MODE', '_TICKSMS']" --no-entry

node <<-EOF
var fs = require("fs");
var prefix = 'wasmBinary = (() => { var wasmcode="';
var suffix = '"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();';

fs.writeFileSync("wasm.js", prefix + fs.readFileSync("code.wasm").toString("base64") + suffix);

EOF
cp ../common/wasm.html .
