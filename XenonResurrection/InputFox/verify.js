var fs = require("fs");
var lines = fs.readFileSync("fox.c").toString().split("\n");

for (var i=0; i<lines.length; i++)
{
  if (lines[i].indexOf(";") != -1)
    lines[i] = lines[i].substr(0,lines[i].indexOf(";")).trim();
}

for (var i=0; i<lines.length-1; i++)
{
  if (lines[i].indexOf("0xfffff") != -1)
    console.log("Wrong number at " + i + " (" + lines[i] + ")");
  if (lines[i].substr(-1) == ":" && lines[i+1].substr(-1) == ":" )
    console.log("Problem at " + i + " (" + lines[i] + ")");
}