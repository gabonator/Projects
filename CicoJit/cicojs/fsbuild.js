const fs = require("fs");

function addFile(filename, id)
{
  var prefix = `Module['`+id+`'] = (() => { var code="`;
  var suffix = `"; return Uint8Array.from(atob(code), c => c.charCodeAt(0));})();
`;
  fs.appendFileSync("resources.js", prefix + fs.readFileSync(filename).toString("base64") + suffix);
}

fs.writeFileSync("resources.js", `Module = typeof(Module) != "undefined" ? Module : {}; 
`);


var path = "/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/bumpy/dos/"
fs.readdirSync(path).forEach(file => {
  console.log(file);
  addFile(path+"/"+file, file);
});

//return;
//addFile("../InputRick2/rick2.data", "rick2.data");
/*
const binFolder = '../InputRick2/binary';

fs.readdirSync(binFolder).forEach(file => {
  addFile(binFolder+"/"+file, file.toLowerCase());
//  console.log(file);
});
*/