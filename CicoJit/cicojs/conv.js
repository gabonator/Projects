if (process.argv.length != 4)
  throw "no arguments";

String.prototype.trim = function() { return this.toString().replace(/^\s+|\s+$/g, ''); };
String.prototype.countOf = function(c) { var cnt = 0; for(var i=0;i<this.length;i++)if(this[i]==c)cnt++; return cnt; };
String.prototype.replacem = function(c, n) { return this.substr(0, c.index) + n + this.substr(c.index + c[1].length) };

function cleanup(l)
{
  if (l && l.indexOf("//") != -1)
    l = l.substr(0, l.indexOf("//"));
  l = l.trim();
  if (l=="")
    return;

  let re1 = new RegExp("\\s*(\\S.*)\\s*//.*")
  let re2 = new RegExp("\\s*(\\S.*)\\s*")
  var p = l.match(re1)  
  if (p)
    return p[1].trim();

  var p = l.match(re2)  
  if (p)
    return p[1].trim();

console.log("problem: '" + l + "'");
  throw "error"
}

function replaceTemplate(arg)
{
  if (arg == "MemAuto")
    arg = "auto";
  if (arg == "MemVideo")
    arg = "video";
  if (arg == "MemData")
    arg = "data";
  if (arg == "MemBios")
    arg = "bios";
  if (arg == "DirAuto")
    arg = "auto";
  if (arg == "DirForward")
    arg = "forward";
  if (arg == "DirBackward")
    arg = "backward";
  return arg;
}

function convert(l)
{
  if (!l)
    return l;

  var r;
  var delim = " !()-+;],=";
  var r = [...l.matchAll(new RegExp("([abcdt][hl])", "g"))].reverse();
  for (var m of r)
    if (m.index == 0 || l.length == 2 || (delim.includes(l[m.index-1]) && delim.includes(l[m.index+2]))) // char!
//      if (m.index == 0 || l[m.index-1] == " " || l[m.index-1] == "!" || l[m.index-1] == "(" || l[m.index-1] == ")" || l[m.index-1] == "-")
//      if (m.index == 0 || l[m.index-1] != "[")
        l = l.replacem(m, `r8[${m[1]}]`);

  var r = [...l.matchAll(new RegExp("([abcdt][x])", "g"))].reverse();
  for (var m of r)
    if (m.index == 0 || l.length == 2 || (delim.includes(l[m.index-1]) && delim.includes(l[m.index+2]))) // char!
      l = l.replacem(m, `r16[${m[1]}]`);
//  while (r = l.match(new RegExp("_(si|di)")))
//    l = l.replace(r[0], "r16["+r[1]+"]");
//  while (r = l.match(new RegExp("_(si|di|ds|es|bp|sp|cs|flags)")))
//    l = l.replace(r[0], r[1]);

  if (r = l.match(new RegExp("memory\\((.*?), (.*?)\\)")))
  {
    var repl = "memory[" + r[1] + "*16+" + r[2] + "]";
    l = l.replace(r[0], repl);
    //console.log(l);
  }

  if (r = l.match(new RegExp("memory16\\((.*), (.*)\\) ([\\+\\-\\|\\^\\&])= (.*);")))
  {
    var repl = `memory16set(${r[1]}, ${r[2]}, memory16get(${r[1]}, ${r[2]}) ${r[3]} ${r[4]});`;
    l = l.replace(r[0], repl);
//console.log(l);
  }

  if (r = l.match(new RegExp("memory16\\((.*), (.*)\\) = (.*);")))
  {
    var repl = "memory16set(" + r[1] + "*16+" + r[2] + ", " + r[3] + ");";
    l = l.replace(r[0], repl);
  }
  if (r = l.match(new RegExp("memory16\\((.*), (.*)\\) -= (.*);")))
  {
    var repl = "memory16set(" + r[1] + "*16+" + r[2] + ", memory16get(" + r[1] + "*16+" + r[2] + ") - " + r[3] + ");";
    l = l.replace(r[0], repl);
  }
  if (r = l.match(new RegExp("memory16\\((.*), (.*)\\) += (.*);")))
  {
    var repl = "memory16set(" + r[1] + "*16+" + r[2] + ", memory16get(" + r[1] + "*16+" + r[2] + ") + " + r[3] + ");";
    l = l.replace(r[0], repl);
  }

  if (r = l.match(new RegExp("memory16\\((.*?), (.*?)\\)")))
  {
    var repl = "memory16get(" + r[1] + "*16+" + r[2] + ")";
    l = l.replace(r[0], repl);
  }

  if (r = l.match(new RegExp("(.*)\\<(.*), (.*), (.*)\\>\\(\\);")))
  {
    r = r.map(replaceTemplate);
    var repl = r[1]+"_"+r[2]+"_"+r[3]+"_"+r[4]+"();";
    l = l.replace(r[0], repl);
  }

  if (r = l.match(new RegExp("(.*)\\<(.*), (.*)\\>\\((.*)\\);")))
  {
    r = r.map(replaceTemplate);
    var repl = r[1]+"_"+r[2]+"_"+r[3]+"("+r[4]+");";
    l = l.replace(r[0], repl);
  }

  if (r = l.match(new RegExp("memoryVideo")))
    l = l.replace(r[0], "video");
  if (r = l.match(new RegExp("_push")))
    l = l.replace(r[0], "push");
  if (r = l.match(new RegExp("_pop")))
    l = l.replace(r[0], "pop");
  if (r = l.match(new RegExp("imul\\((r16.*)\\)")))
    l = l.replace(r[0], "imul16("+r[1]+")");
  if (r = l.match(new RegExp("out\\((.*), (r16.*)\\)")))
    l = l.replace(r[0], `out16(${r[1]}, ${r[2]})`);
  if (r = l.match(new RegExp("out\\((.*), (r8.*)\\)")))
    l = l.replace(r[0], `out8(${r[1]}, ${r[2]})`);
//in(r8[al], 0x40);
/*
  if (r = l.match(new RegExp("(r8.*) in\\((.*)\\)")))
    l = l.replace(r[0], r[1] + " = in8("+r[2]+")");
  if (r = l.match(new RegExp("(r16.*) in\\((.*)\\)")))
    l = l.replace(r[0], r[1] + " = in16("+r[2]+")");
*/
  if (r = l.match(new RegExp("in\\((r8.*), (.*)\\)")))
    l = l.replace(r[0], r[1] + " = in8("+r[2]+")");
  if (r = l.match(new RegExp("in\\((r16.*), (.*)\\)")))
    l = l.replace(r[0], r[1] + " = in16("+r[2]+")");

  if (r = l.match(new RegExp("callIndirect")))
    l = l.replace(r[0], "yield* callIndirect");

  while (r = l.match(new RegExp("\\(short\\)r16")))
    l = l.replace(r[0], "r16s");
  while (r = l.match(new RegExp("\\(char\\)r8")))
    l = l.replace(r[0], "r8s");

  while (r = l.match(new RegExp("\\(short\\)memory16get")))
    l = l.replace(r[0], "memory16gets");
  while (r = l.match(new RegExp("\\(char\\)memory")))
    l = l.replace(r[0], "memorys");

  while (r = l.match(new RegExp("\\(short\\)memoryAGet16")))
    l = l.replace(r[0], "memory16gets");
  while (r = l.match(new RegExp("\\(char\\)memoryAGet")))
    l = l.replace(r[0], "memorys");

  while (r = l.match(new RegExp("\\(short\\)memoryGet16")))
    l = l.replace(r[0], "memory16gets");
  while (r = l.match(new RegExp("\\(char\\)memoryGet")))
    l = l.replace(r[0], "memorys");

  while (r = l.match(new RegExp("= \\(short\\)(.*) \\<")))
    l = l.replace(r[0], "signed16"+r[1]+" <");
  while (r = l.match(new RegExp("= \\(char\\)(.*) \\<")))
    l = l.replace(r[0], "signed8"+r[1]+" <");

  while (r = l.match(new RegExp("\\(short\\)([0-9a-z]+)")))
    l = l.replace(r[0], "signed16("+r[1]+")");
  while (r = l.match(new RegExp("\\(char\\)\([0-9a-fx]+)"))) // tuto!
    l = l.replace(r[0], "signed8("+r[1]+")");
//!!! signed16bp


  if (r = l.match(new RegExp("(rcl|mul)\\(\\(uint16_t\\)si")))
    l = l.replace(r[0], `${r[1]}16(si`);
  if (r = l.match(new RegExp("(rcl|mul)\\(\\(uint16_t\\)di")))
    l = l.replace(r[0], `${r[1]}16(di`);

  if (r = l.match(new RegExp("(rcr|rcl|sar|rol|ror)\\((r8\\[.*\\]), (.*)\\)")))
    l = l.replace(r[0], `${r[1]}8(${r[2]}, ${r[3]})`);
  if (r = l.match(new RegExp("(rcr|rcl|sar|rol|ror)\\((r16\\[.*\\]), (.*)\\)")))
    l = l.replace(r[0], `${r[1]}16(${r[2]}, ${r[3]})`);
  if (r = l.match(new RegExp("(idiv|div|imul|mul)\\((r8\\[.*\\])\\)")))
    l = l.replace(r[0], `${r[1]}8(${r[2]})`);
  if (r = l.match(new RegExp("(idiv|div|imul|mul)\\((r16\\[.*\\])\\)")))
    l = l.replace(r[0], `${r[1]}16(${r[2]})`);
  if (r = l.match(new RegExp("(idiv|div|imul|mul)\\((memory\\w*16\\(.*)\\)")))
    l = l.replace(r[0], `${r[1]}16(${r[2]})`);

/*
  if (r = l.match(new RegExp("rcr\\(r16\\[(.*)\\], (.*)\\)")))
    l = l.replace(r[0], "rcr16("+r[1]+", "+r[2]+")");
  if (r = l.match(new RegExp("sar\\(r8\\[(.*)\\], (.*)\\)")))
    l = l.replace(r[0], "sar8("+r[1]+", "+r[2]+")");
  if (r = l.match(new RegExp("sar\\(r16\\[(.*)\\], (.*)\\)")))
    l = l.replace(r[0], "sar16("+r[1]+", "+r[2]+")");
//  if (r = l.match(new RegExp("xchg\\(r16\\[(.*)\\], r16\\[(.*)\\]\\)")))
//    l = l.replace(r[0], "xchg16("+r[1]+", "+r[2]+")");
//  if (r = l.match(new RegExp("xchg\\(r8\\[(.*)\\], r8\\[(.*)\\]\\)")))
//    l = l.replace(r[0], "xchg8("+r[1]+", "+r[2]+")");
  if (r = l.match(new RegExp("rol\\(r16\\[(.*)\\], (.*)\\)")))
    l = l.replace(r[0], "rol16("+r[1]+", "+r[2]+")");
  if (r = l.match(new RegExp("ror\\(r16\\[(.*)\\], (.*)\\)")))
    l = l.replace(r[0], "ror16("+r[1]+", "+r[2]+")");
  if (r = l.match(new RegExp("rol\\(r8\\[(.*)\\], (.*)\\)")))
    l = l.replace(r[0], "rol8("+r[1]+", "+r[2]+")");
  if (r = l.match(new RegExp("ror\\(r8\\[(.*)\\], (.*)\\)")))
    l = l.replace(r[0], "ror8("+r[1]+", "+r[2]+")");
*/

  while (r = l.match(new RegExp("memoryAGet16")))
    l = l.replace(r[0], "memory16get");
  while (r = l.match(new RegExp("memoryAGet")))
    l = l.replace(r[0], "memoryget");

  while (r = l.match(new RegExp("memoryASet16")))
    l = l.replace(r[0], "memory16set");
  while (r = l.match(new RegExp("memoryASet")))
    l = l.replace(r[0], "memoryset");

  while (r = l.match(new RegExp("memoryGet16")))
    l = l.replace(r[0], "memory16get");
  while (r = l.match(new RegExp("memoryGet")))
    l = l.replace(r[0], "memoryget");

  while (r = l.match(new RegExp("memorySet16")))
    l = l.replace(r[0], "memory16set");
  while (r = l.match(new RegExp("memorySet")))
    l = l.replace(r[0], "memoryset");

  while (r = l.match(new RegExp("memoryset\\((.*?), (.*?), (.*\\(.*\\).*)\\)")))
    l = l.replace(r[0], `memory[${r[1]}*16 + ${r[2]}] = ${r[3]}`);

  while (r = l.match(new RegExp("memoryset\\((.*?), (.*?), (.*?)\\)")))
    l = l.replace(r[0], `memory[${r[1]}*16 + ${r[2]}] = ${r[3]}`);

  while (r = l.match(new RegExp("memoryget\\((.*?), (.*?)\\)")))
    l = l.replace(r[0], `memory[${r[1]}*16 + ${r[2]}]`);

  while (r = l.match(new RegExp("memory\\[(.*)\\] = memory\\[(.*)\\] \\+ (.*)")))
  {
    if (r[1] == r[2])
      l = l.replace(r[0], `memory[${r[1]}] += ${r[3]}`);
    else
      break;
  }
  while (r = l.match(new RegExp("memory\\[(.*)\\] = memory\\[(.*)\\] - (.*)")))
    if (r[1] == r[2])
      l = l.replace(r[0], `memory[${r[1]}] -= ${r[3]}`);
    else
      break;

  if (r = l.match(new RegExp("(nullsub|sub|loc|off)_.*\\(\\);")))
    l = l.replace(r[0], "yield* "+r[0]);
  if (r = l.match(new RegExp("sync\\(\\);")))
    l = l.replace(r[0], "yield* "+r[0]);
  if (r = l.match(new RegExp("syncKeyb\\(\\);")))
    l = l.replace(r[0], "yield* "+r[0]);
  if (r = l.match(new RegExp("fixReloc\\(.*\\);")))
    l = l.replace(r[0], "yield* "+r[0]);

  if (r = l.match(new RegExp("std::")))
    l = "// "+l;

if (l.indexOf("flags.sign = ") != -1)
  console.log(l);
//  if (r = l.match(new RegExp("\\{(.*\\(\\)); return; \\}.*")))
//  {
    
//  }
//    l = l.replace(r[0], "indirectCall");
//{loc_1C3B0(); return; };

  return l;  
}

function flow(input)
{
  var inSwitch = false;
  var r;
  var output = [];
  output.push("var pc = 0;");
  output.push("do switch (pc) {");
  output.push("case 0:");
  for (var i in input)
  {
    var l = input[i];
    if (!l)
      continue;

    if (r = l.match(new RegExp("WORD _?cs = (.*);")))
    {
      output.unshift("var cs = "+r[1]+";");
      continue;
    }
//    if (r = l.match(new RegExp("if \\(pc ==")))
//    {
//      output.unshift("var cs = "+r[1]+";");
//      continue;
//    }
    if (l.indexOf("_STOP_") != -1)
    {
      output.push(l);
      continue;
    }
    if (r = l.match(new RegExp("loc_(.*):")))
    {
      output.push(l.replace(r[0], "case 0x"+r[1]+":"));
      continue;
    }
    if (r = l.match(new RegExp("locret_(.*):")))
    {
      continue;
    }
    if (r = l.match(new RegExp("switch (.*)")))
      inSwitch = true;
    if (r = l.match(new RegExp("case (.*): goto loc_(.*);")))
    {
      output.push(`case ${r[1]}: pc = 0x${r[2]}; break;`);
      continue;
    }
    if (r = l.match(new RegExp("goto loc_(.*);")))
    {
      var ifclause = output[output.length-1].indexOf("if ") != -1;
      if (ifclause)
        output[output.length - 1] += " {"; 
      output.push("pc = 0x" + r[1] + ";");
      output.push("break;");
      if (ifclause)
        output.push("}");
      continue;
    }
    if (r = l.match(new RegExp("goto locret_.*;")))
    {
      output.push("return;");
      continue;
    }
    output.push(l);

    if (inSwitch && l.trim() == "}")
    {
      output.push("break;");
      inSwitch = false;
    }
  }
  if (output[output.length-1] != "return;")
    output.push("return;");
  output.push("} while (1);");
  return output;
}

function cleanupReturn(input)
{
  var r;
  var output = [];
  for (var i in input)
  {
    var l = input[i];
    if (!l)
      continue;

    if (r = l.match(new RegExp("WORD _?cs = (.*);")))
    {
      output.unshift("var cs = "+r[1]+";");
      continue;
    }

    if (l.indexOf("_STOP_") != -1)
    {
      output.push(l);
      continue;
    }

    if (r = l.match(new RegExp("goto locret_.*;")))
    {
      output.push("return;");
      continue;
    }
    if (r = l.match(new RegExp("loc_(.*):")))
    {
      console.log("Should not use labels: " + l);
      //throw "problem";
    }
    if (r = l.match(new RegExp("locret_(.*):")))
    {
      continue;
    }
    if (r = l.match(new RegExp("goto loc_(.*);")))
    {
      throw "problem"
    }
    output.push(l);
  }
  return output;
}

function format(code)
{
  var indent = 0;
  var plind = 0;
  for (var i in code)
  {
    var l = code[i];
    if (!l)
      continue;
    indent -= l.countOf("}");
    var lind = l.indexOf("case") != -1 ? -1 : 0; 
    lind += plind;
    plind = (l.indexOf("if") != -1 && l.indexOf("{") == -1) ? +1 : 0;
       
    for (var ind=0; ind<indent+lind; ind++)
      l = "    " + l;
    indent += l.countOf("{");    
    code[i] = l;
  }
  return code;
}

function isUsingLabels(input)
{
  for (var i in input)
    if (input[i] && input[i].indexOf("goto loc_") != -1)
      return true;
  return false;
}

function processFunctionBody(input)
{
  //var input = input.split("\n");
  //console.log(cleanup(input[0]));
  input = input.map(line => cleanup(line))
  input = input.map(line => convert(line))  
  if (isUsingLabels(input))    
    input = flow(input);
  else
    input = cleanupReturn(input);
  return input;
}

function findFunctions(input, handler)
{
  var r;
  var balance = 0;
  var lines = [];
  var fname, fargs;
  var result = [];

  for (var i in input)
  {
    var closing = false;
    var l = input[i];
    if (!l)
      continue;

    if (r = l.match(new RegExp("void (.*)\\(.*\\);")))
      continue;

    if (r = l.match(new RegExp("void (.*)\\((.*)\\)")))
    {
      balance = -1;
      lines = [];
      fname = r[1];
      fargs = r[2];
    }
    if (l.countOf("}") == l.countOf("{"))
    {
      if (balance >= 0)
        lines.push(l);
    } else
    {
      closing = l.countOf("}") > 0;
      balance -= l.countOf("}");
      if (balance >= 0)
        lines.push(l);
      balance += l.countOf("{");
    }
    if (balance < 0 && /*lines.length > 0*/ closing)
    {
//       console.log(fname);
//       console.log(lines.join("\n"));
       result = result.concat(handler(fname, lines, fargs));
       lines = [];
    }
  }
  return result;
}

function findGlobals(input, handler)
{
  var result = [];
  for (var l of input)
  {
    if (r = l.match(new RegExp("(int|const char\\*) (.*) = (.*);")))
      result = result.concat(handler(r[1], r[2], r[3]));
  }
  if (result.length)
    result.push("");
  return result;
}
var fs = require("fs");
var input = fs.readFileSync(process.argv[2]);
var input = input.toString().split("\n");

input = findGlobals(input, (type, name, val) => {
  return [`var ${name} = ${val};`];
}).concat(findFunctions(input, (name, body, args) => {
  if (r = args.match(new RegExp("uint16_t ")))
    args = args.replace(r[0], ``);
  return ["function* "+name+"("+(args?args:"")+") {", ...processFunctionBody(body), "}"];
}));

input = format(input);
fs.writeFileSync(process.argv[3], input.join("\n"));
