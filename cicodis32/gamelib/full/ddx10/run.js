const fs = require('fs');
const path = require('path');

let allCode = "";
function loadScript(file) {
  allCode += fs.readFileSync(path.resolve(__dirname, file), 'utf8');
}

archive = {}
archive["ddx10_data.bin"] = fs.readFileSync("res/ddx10_data.bin");
archive["ddx10_rdata.bin"] = fs.readFileSync("res/ddx10_rdata.bin");
archive["ddx10_reloc.bin"] = fs.readFileSync("res/ddx10_reloc.bin");
archive["ddx10_rsrc.bin"] = fs.readFileSync("res/ddx10_rsrc.bin");
archive["ddx10_text.bin"] = fs.readFileSync("res/ddx10_text.bin");

loadScript('./cpu.js');
loadScript('./crt.js');
loadScript('./fpu.js');
loadScript('./ddx10.js');
loadScript('./ddx10gui.js');
loadScript('./ddx10handlers.js');
loadScript('./main.js');

eval(allCode)