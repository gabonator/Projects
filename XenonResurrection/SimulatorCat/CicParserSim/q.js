var fs=require("fs");
l = fs.readFileSync("q").toString().split("\n");
var vars = {}
for (var i in l)
{
  var g = l[i].match("memory\\(.*\\)");
  if (g)
    vars[g[0]] = 1;
}

console.log(vars);