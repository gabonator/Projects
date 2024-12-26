var fs = require("fs")
var lines = fs.readFileSync("levels").toString().split("\n").filter(x=>x.length);
var out = [];
for (var l of lines)
{
  var json = JSON.parse("{"+(l.split(": {")[1]))
  var id = json.level*15+json.room;
  if (!out[id])
    out[id] = json;
  else if (json.path[json.path.length-2] < out[id].path[out[id].path.length-2])
    out[id] = json;
}

var replays = [];
for (var i of out)
{
  if (i)
    replays.push(i);
}
console.log("replays = " + JSON.stringify(replays))
