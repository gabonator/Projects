set -e
cat > wasmhost.cpp <<-EOF
#include <stdint.h>

extern "C" {
  uint32_t LED_BUFFER[10*10];
  uint8_t MODE;
  int32_t TICKSMS;

  void old_loop()
  {
  }

  void old_onPress(int, int)
  {
  }

  void old_onRelease(int)
  {
  }
}
EOF
em++ code.cpp wasmhost.cpp -o code.wasm -O3 -s EXPORTED_FUNCTIONS="['_new_loop', '_new_onPress', '_new_onRelease', '_LED_BUFFER', '_MODE', '_TICKSMS']" --no-entry

node <<-EOF
var fs = require("fs");
var prefix = 'wasmBinary = (() => { var wasmcode="';
var suffix = '"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();';

fs.writeFileSync("wasm.js", prefix + fs.readFileSync("code.wasm").toString("base64") + suffix);

EOF

rm wasmhost.cpp code.wasm