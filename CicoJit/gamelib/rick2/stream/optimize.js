// removes all indirect calls
var fs = require("fs");
var bin = fs.readFileSync("../dos/MAIN.EXE")

function read16(seg, ofs)
{
  var fofs = seg*16+ofs-(0x10000-0x200);
  return bin[fofs] + bin[fofs+1]*256;
}

lines = fs.readFileSync("rick2.cpp").toString().split("\n");
for (var i=0; i<lines.length; i++)
{
  var m = lines[i].match("callIndirect\\(cs, memory16\\(ds, (0x.{4})\\)\\);")
  if (m)
  {
    var ofs = read16(0x1040, parseInt(m[1]));
    var addr = 0x1040*16+ofs;
    lines[i] = lines[i].replace(m[0], "sub_"+addr.toString(16)+"();");
  }
}
fs.writeFileSync("rick2opt.cpp", lines.join("\n"));