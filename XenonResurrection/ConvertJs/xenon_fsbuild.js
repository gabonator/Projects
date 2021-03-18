const fs = require("fs");

function addFile(filename, id)
{
  if (fs.lstatSync(filename).isDirectory())
    return;
console.log(filename);
  var prefix = `Module['`+id+`'] = (() => { var code="`;
  var suffix = `"; return Uint8Array.from(atob(code), c => c.charCodeAt(0));})();
`;
  fs.appendFileSync("xenon2.resources.js", prefix + fs.readFileSync(filename).toString("base64") + suffix);
}

fs.writeFileSync("xenon2.resources.js", `Module = typeof(Module) != "undefined" ? Module : {}; 
`);

var binFolder = '../InputXenon2/';

fs.readdirSync(binFolder).forEach(file => {
  addFile(binFolder+"/"+file, file.toLowerCase());
//  console.log(file);
});

var binFolder = '../InputXenon2/s1/';

fs.readdirSync(binFolder).forEach(file => {
  addFile(binFolder+"/"+file, "s1/"+file.toLowerCase());
//  console.log(file);
});
