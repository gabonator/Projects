const fs = require('fs');
const path = require('path');

let allCode = "";
function loadScript(file) {
  allCode += fs.readFileSync(path.resolve(__dirname, file), 'utf8');
}

archive = {}
archive["Delay Lama_data.bin"] = fs.readFileSync("../res/Delay Lama_data.bin");
archive["Delay Lama_rdata.bin"] = fs.readFileSync("../res/Delay Lama_rdata.bin");
//archive["Delay Lama_reloc.bin"] = fs.readFileSync("../res/Delay Lama_reloc.bin");
//archive["Delay Lama_rsrc.bin"] = fs.readFileSync("../res/Delay Lama_rsrc.bin");
//archive["Delay Lama_text.bin"] = fs.readFileSync("../res/Delay Lama_text.bin");

loadScript('./cpu.js');
loadScript('./crt.js');
loadScript('./fpu.js');
loadScript('./delaylama.js');
loadScript('./main.js');

eval(allCode)