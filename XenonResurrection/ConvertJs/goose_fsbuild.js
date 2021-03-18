const fs = require("fs");

function addFile(filename, id)
{
  if (fs.lstatSync(filename).isDirectory())
    return;
console.log(filename);
  var prefix = `Module['`+id+`'] = (() => { var code="`;
  var suffix = `"; return Uint8Array.from(atob(code), c => c.charCodeAt(0));})();
`;
  fs.appendFileSync("goose.resources.js", prefix + fs.readFileSync(filename).toString("base64") + suffix);
}

fs.writeFileSync("goose.resources.js", `Module = typeof(Module) != "undefined" ? Module : {}; 
`);

var binFolder = '../InputGoose/';

fs.readdirSync(binFolder).forEach(file => {
  if (file.indexOf(".X") == -1 && file.indexOf(".dseg") == -1 )
    return;
  addFile(binFolder+"/"+file, file.toLowerCase());
});
