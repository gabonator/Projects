const API = require("./shared.js");
const fs = require("fs");
const util = require('util');
const readFile = util.promisify(fs.readFile);

const apiOptions = {
  async readBuffer(filename) {
    const response = await readFile(filename);
    return response;
  },

  async compileStreaming(filename) {
    const response = await readFile(filename);
    return WebAssembly.compile(await response);
  },

  hostWrite(s) { console.log(s) }
};

async function test()
{
  var api = new API(apiOptions);
  output =  await api.compileLink("#include <stdio.h>\nint main(void) { printf(\"Ahoj!\"); return 7; }");
  console.log("done: " + new TextDecoder().decode(output));
}

test();

