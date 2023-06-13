var fs = require("fs");
var code = fs.readFileSync("xenon2.cpp").toString().split("\n");
var addrs = {};
var lastbx = null;
for (var line of code)
{
  var m = line.match("bx = (0x[0-9a-f]{4});");
  if (m)
    lastbx = parseInt(m[1]);
  if (lastbx && line.includes("sub_13529();"))
    addrs[lastbx] = 1;
  var m = line.match("memoryASet16\\(ds, si \\+ [246], (0x[0-9a-f]{4})\\)");
  if (m)
  {
    var addr = parseInt(m[1]);
    if (addr >= 0x0500 && addr < 0x9000)
      addrs[addr] = 1;
  }
  var m = line.match("memoryASet16\\(ds, di \\+ [246], (0x[0-9a-f]{4})\\)");
  if (m)
  {
    var addr = parseInt(m[1]);
    if (addr >= 0x0500 && addr < 0x9000)
      addrs[addr] = 1;
  }
}
var res = Object.keys(addrs);
res.sort((a,b) => a-b);
console.log(res.map(x=>"1000:"+("000"+parseInt(x).toString(16)).substr(-4)).join(","));
