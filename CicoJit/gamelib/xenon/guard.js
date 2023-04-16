var fs = require("fs");
var code = fs.readFileSync("xenon.cpp").toString().split("\n").join("@");
m = `void sub_$fname()
{`
var r = `void sub_$fname()
{
  stackguard sg(sp);
`
function makeRegex(pat)
{
  pat = pat.split("\n").join("@");
  pat = pat.split("(").join("\\(");
  pat = pat.split(")").join("\\)");
  pat = pat.split("+").join("\\+");
  pat = pat.split("$fname").join("(\\w+)");
  return pat;
}

function makeReplacement(m)
{
  return r.split("$fname").join(m[1]);
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

/*
class stackguard
{
    uint16_t* ms;
    uint16_t minit;
public:
    stackguard(uint16_t& s):ms(&s),minit(s) {}
    ~stackguard() { assert(minit == *ms); }
};

*/