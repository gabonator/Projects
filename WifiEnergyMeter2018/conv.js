
var fs = require("fs");
var data = fs.readFileSync('eco-green-energy-icon-64-182129.png', "binary");
console.log("const char buffer["+data.length+"] = {");
for (var i=0; i<data.length; i++)
{
//if ( data.charCodeAt(i)==0)
//  process.stdout.write("0, ");
//else
  process.stdout.write("0x" + ("0" + data.charCodeAt(i).toString(16)).substr(-2)+",")
if (i%32==31)
  process.stdout.write("\n");
};
console.log("};");
