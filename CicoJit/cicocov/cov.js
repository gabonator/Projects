var fs = require("fs");
var cov = fs.readFileSync("bumpy.coverage").toString().split("\n").map(x=>x.trim()).filter(x=>x.includes("coverage:"))
var con = fs.openSync("dos/B.EXE", "r");
var blocks = []
function blockSize()
{
  return 128;
}
function toBlock(ofs)
{
  return ofs >> 7;
}
function blockBegin(bid)
{
  return bid*128;
}
function blockEnd(bid)
{
  return bid*128+128;
}
for (var c of cov)
{
  var tokens = c.split(" ");
  tokens.shift();
  tokens.shift();
  var range = tokens[0].split("-").map(x=>parseInt(x))
  var type = tokens[1];
  var opt = tokens[2];
  var begin = toBlock(range[0]);
  var end = toBlock(range[1]);
//  if (type == "reloc") continue;
  for (var i=begin; i<=end; i++)
  {
    var ofsBegin = blockBegin(i);
    var ofsEnd = blockEnd(i);

    var info = 0;
    if (i==begin)
      info |= 1;
    if (i==end)
      info |= 2;
    if (!blocks[i])
      blocks[i] = [];
    if (opt)
      blocks[i].push([info, Math.max(ofsBegin, range[0]), Math.min(ofsEnd, range[1]), type, opt]);  
    else
      blocks[i].push([info, Math.max(ofsBegin, range[0]), Math.min(ofsEnd, range[1]), type]);  
  }
}

var contentsData = "";
var pos = 0;
const buffer = Buffer.alloc(blockSize());
while (fs.readSync(con, buffer, 0, blockSize(), pos))
{
  pos += buffer.length;
  var maxval = 0;
  var minval = 255;
  for (var i=0; i<buffer.length; i++)
  {
    maxval = Math.max(maxval, buffer[i]);
    minval = Math.min(minval, buffer[i]);
  }
  if (maxval == 0)
    contentsData += "0";
  else if (maxval-minval < 128)
    contentsData += "1";
  else if (maxval-minval < 255)
    contentsData += "2";
  else
    contentsData += "3";
}
fs.writeFileSync("bumpy.covjson", "coverageData="+JSON.stringify(blocks)+"\ncontentsData='"+contentsData+"'")
