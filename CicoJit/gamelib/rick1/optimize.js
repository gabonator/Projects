var fs = require("fs")
var inlines = fs.readFileSync("rick1.cpp").toString().split("\n");
var outlines = []

function replaceFunc(str, f, templ)
{
  var left = f[f.length-2]
  var right = f[f.length-1]
  f = f.substr(0, f.length-2);
  while (str.includes(f+left))
  {
    var args = [];
    var ofs = str.indexOf(f+left);
    var balance = 1;
    var begin = ofs + f.length + 1;
    var replBegin = ofs;
    var replEnd;
    var argbegin = begin;
    for (var i=begin; i<str.length; i++)
    {
      if (balance == 1 && str[i] == ',')
      {
        args.push(l.substr(argbegin, i-argbegin).trim())
        argbegin = i+1;
      }
      if (str[i] == left)
        balance++;
      if (str[i] == right)
      {
        balance--;
        if (balance == 0)
        {
          args.push(l.substr(argbegin, i-argbegin).trim())
          replEnd = i+1;
          break;
        }
      }
    }
    if (!args.length)
      throw "noargs"

    var repl = templ;
    for (var i=0; i<args.length; i++)
      repl = repl.split("$"+(i+1)).join(args[i]);

    str = str.substr(0, replBegin) + repl + str.substr(replEnd);
  }
  return str;
}

function replaceTemp(str, find, repl)
{
  return str.split(find).join(repl);
}

for (var l of inlines)
{
  if (l.substr(0, 9) == "void sub_")
    method = l.substr(5, l.length-7);
  if (l.includes("memory"))
  {
    if (method == "sub_35f97" || method == "sub_3680a") // ds
    {
      l = replaceFunc(l, "memoryASet()", "memoryVideoSet($1, $2, $3)");
      l = replaceFunc(l, "memoryASet16()", "memoryVideoSet16($1, $2, $3)");
      l = replaceFunc(l, "memoryAGet16()", "memoryVideoGet16($1, $2)");
    }
    if (method == "sub_35dc5") // es
    {
      l = replaceFunc(l, "memoryASet()", "memoryVideoSet($1, $2, $3)");
      l = replaceFunc(l, "memoryAGet()", "memoryVideoGet($1, $2)");
    }

    l = replaceFunc(l, "memoryAGet16()", "memory16($1, $2)");
    l = replaceFunc(l, "memoryASet16()", "memory16($1, $2) = $3");
    l = replaceFunc(l, "memoryAGet()", "memory($1, $2)");
    l = replaceFunc(l, "memoryASet()", "memory($1, $2) = $3");
  }
  if (l.includes("MemAuto"))
  {
    var dir = "DirForward";
    var src = "MemData";
    var dst = "MemData";

    if (["sub_34811", "sub_34947", "sub_36161", "sub_35f4e", "sub_35dc5", "sub_34e4c", "sub_34986", "sub_34dc8", "sub_34dc8"].indexOf(method) != -1) dst = "MemVideo";
    if (["sub_36161", "sub_35f97", "sub_35f4e", "sub_34e4c", "sub_34dc8", "sub_34dc8"].indexOf(method) != -1) src = "MemVideo";
    if (["sub_3520a"].indexOf(method) != -1) dir = "DirAuto";

    l = replaceTemp(l, "rep_movsb<MemAuto, MemAuto, DirAuto>", `rep_movsb<${dst}, ${src}, ${dir}>`);
    l = replaceTemp(l, "rep_stosw<MemAuto, DirAuto>", `rep_stosw<${dst}, ${dir}>`);
    l = replaceTemp(l, "rep_stosb<MemAuto, DirAuto>", `rep_stosb<${dst}, ${dir}>`);
    l = replaceTemp(l, "movsw<MemAuto, MemAuto, DirAuto>", `movsw<${dst}, ${src}, ${dir}>`);
    l = replaceTemp(l, "movsb<MemAuto, MemAuto, DirAuto>", `movsb<${dst}, ${src}, ${dir}>`);
    l = replaceTemp(l, "lodsw<MemAuto, DirAuto>", `lodsw<${src}, ${dir}>`);
    l = replaceTemp(l, "lodsb<MemAuto, DirAuto>", `lodsb<${src}, ${dir}>`);
    l = replaceTemp(l, "stosb<MemAuto, DirAuto>", `stosb<${dst}, ${dir}>`);
    l = replaceTemp(l, "stosw<MemAuto, DirAuto>", `stosw<${dst}, ${dir}>`);
  }
  outlines.push(l)
}

fs.writeFileSync("cicorun/rick1.cpp", outlines.join("\n"));
