if (process.argv.length != 4)
  throw "no arguments";

const fs = require("fs");

function addFile(filename, id)
{
  console.log(filename);
  var prefix = `Module['`+id+`'] = (() => { var code="`;
  var suffix = `"; return Uint8Array.from(atob(code), c => c.charCodeAt(0));})();
`;
  fs.appendFileSync(process.argv[3], prefix + fs.readFileSync(filename).toString("base64") + suffix);
}

fs.writeFileSync(process.argv[3], `Module = typeof(Module) != "undefined" ? Module : {}; 
`);


function add(path, group)
{
  fs.readdirSync(path).forEach(file => {
    if (fs.lstatSync(path+"/"+file).isDirectory())
      add(path+"/"+file, group+file+"/")
    else
      addFile(path+"/"+file, group+file);
  });
}
//var path = process.argv[2]
add(process.argv[2], "");
//return;
//addFile("../InputRick2/rick2.data", "rick2.data");
/*
const binFolder = '../InputRick2/binary';

fs.readdirSync(binFolder).forEach(file => {
  addFile(binFolder+"/"+file, file.toLowerCase());
//  console.log(file);
});
*/