var fs = require("fs");
var prefix = `Module = typeof(Module) != "undefined" ? Module : {}; Module['wasmBinary'] = (() => { var wasmcode="`;
var suffix = `"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();`;

fs.writeFileSync("fs.cdman.wasm.js", prefix + fs.readFileSync("../build/cdman.wasm").toString("base64") + suffix);


var prefix = `Module = typeof(Module) != "undefined" ? Module : {}; Module['cdman.data'] = (() => { var wasmcode="`;
var suffix = `"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();`;
fs.writeFileSync("fs.cdman.data.js", prefix + Buffer.from(fs.readFileSync("../../InputCdman/cdman.data").buffer, 0x200, 0x3ce0-0x200).toString("base64") + suffix);


var prefix = `Module = typeof(Module) != "undefined" ? Module : {}; Module['TITLE.CDM'] = (() => { var wasmcode="`;
var suffix = `"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();`;
fs.writeFileSync("fs.title.cdm.js", prefix + fs.readFileSync("../../InputCdman/title.cdm").toString("base64") + suffix);

var prefix = `Module = typeof(Module) != "undefined" ? Module : {}; Module['GRAPHIC3.CDM'] = (() => { var wasmcode="`;
var suffix = `"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();`;
fs.writeFileSync("fs.graphic3.cdm.js", prefix + fs.readFileSync("../../InputCdman/graphic3.cdm").toString("base64") + suffix);


var prefix = `Module = typeof(Module) != "undefined" ? Module : {}; Module['SCREEN3.CDM'] = (() => { var wasmcode="`;
var suffix = `"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();`;
fs.writeFileSync("fs.screen3.cdm.js", prefix + fs.readFileSync("../../InputCdman/screen3.cdm").toString("base64") + suffix);

var prefix = `Module = typeof(Module) != "undefined" ? Module : {}; Module['GRAPHIC1.CDM'] = (() => { var wasmcode="`;
var suffix = `"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();`;
fs.writeFileSync("fs.graphic1.cdm.js", prefix + fs.readFileSync("../../InputCdman/graphic1.cdm").toString("base64") + suffix);

var prefix = `Module = typeof(Module) != "undefined" ? Module : {}; Module['SCREEN1.CDM'] = (() => { var wasmcode="`;
var suffix = `"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();`;
fs.writeFileSync("fs.screen1.cdm.js", prefix + fs.readFileSync("../../InputCdman/screen1.cdm").toString("base64") + suffix);

var prefix = `Module = typeof(Module) != "undefined" ? Module : {}; Module['GRAPHIC2.CDM'] = (() => { var wasmcode="`;
var suffix = `"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();`;
fs.writeFileSync("fs.graphic2.cdm.js", prefix + fs.readFileSync("../../InputCdman/graphic2.cdm").toString("base64") + suffix);

var prefix = `Module = typeof(Module) != "undefined" ? Module : {}; Module['SCREEN2.CDM'] = (() => { var wasmcode="`;
var suffix = `"; return Uint8Array.from(atob(wasmcode), c => c.charCodeAt(0));})();`;
fs.writeFileSync("fs.screen2.cdm.js", prefix + fs.readFileSync("../../InputCdman/screen2.cdm").toString("base64") + suffix);

