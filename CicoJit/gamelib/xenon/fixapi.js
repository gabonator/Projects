var fs = require("fs");
var bin = fs.readFileSync("dos/XENON2/XENON2.EXE")
var code = fs.readFileSync("xenon.cpp").toString().split("\n").join("@");
m = `void sub_$fname()
{
  bp = memoryAGet16(ds, 0x3044);
  bp <<= 1;
  bp <<= 1;
  callIndirect(cs, memoryAGet(cs, bp + $ofs));
}`
var r = `void sub_$fname()
{
  assert(memoryAGet16(ds, 0x3044) == 3);
  sub_$newfname();
}`
function makeRegex(pat)
{
  pat = pat.split("\n").join("@");
  pat = pat.split("(").join("\\(");
  pat = pat.split(")").join("\\)");
  pat = pat.split("+").join("\\+");
  pat = pat.split("$fname").join("(\\w+)");
  pat = pat.split("$ofs").join("([x0-9a-f]+)");
  return pat;
}

function read16(seg, ofs)
{
  var fofs = seg*16+ofs-(0x10000-0x800);
  return bin[fofs] + bin[fofs+1]*256;
}

var extraFunc = [];
function makeReplacement(m)
{
  cs = 0x1000; //0x1f29;
  var pairofs = parseInt(m[2])+12;
  var newofs = read16(cs, pairofs);
  var newseg = read16(cs, pairofs+2)+0x1000; // relocate?
  var newr = ""+r;
  var newfname = newseg*16 + newofs;
//  console.log(m[1], "Read ",cs.toString(16),":",pairofs.toString(16), " = ", 
//    newseg.toString(16)+":"+newofs.toString(16), "   =", newfname.toString(16))
  extraFunc.push(newseg.toString(16)+":"+newofs.toString(16));
  newr = newr.split("$fname").join(m[1]);
  newr = newr.split("$newfname").join(newfname.toString(16));
  return newr;
}

var pat = new RegExp(makeRegex(m), "g");
const array = [...code.matchAll(pat)];
console.log("Found", array.length, "matches\n");
if (array.length == 0)
  return;

for (var i=array.length-1; i--; i>=0)
{
  var m = array[i];
  var n = makeReplacement(m);
  code = code.substr(0, m.index) + n + code.substr(m.index + m[0].length);
}
code = code.split("@").join("\n");
fs.writeFileSync("xenon.cpp", code);
console.log(extraFunc.join(","));
//console.log("pokus");
//console.log(code.substr(array[0].index, array[0][0].length))
//console.log(array.length);