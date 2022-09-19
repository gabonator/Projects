'use strict'

const  VideoRead = 1;
const  VideoWrite = 2;
const  BiosRead = 4;
const  BiosWrite = 8;
const  OffsetOverflow = 16;
const  Blocking = 32;

var mpat = [{fname:"start", addr:0xffffffff, type:Blocking},
{fname:"sub_10010", addr:0xffffffff, type:Blocking},
{fname:"sub_100a9", addr:0xffffffff, type:Blocking},
{fname:"sub_100cf", addr:0xffffffff, type:Blocking},
{fname:"sub_10103", addr:0xffffffff, type:Blocking},
{fname:"sub_1069a", addr:0x10748, type:VideoWrite},
{fname:"sub_10c24", addr:0x10d4c, type:VideoRead | VideoWrite},
{fname:"sub_10c24", addr:0x10d61, type:VideoRead | VideoWrite},
{fname:"sub_125e3", addr:0x1261e, type:VideoRead},
{fname:"sub_125e3", addr:0x12625, type:VideoWrite},
{fname:"sub_125e3", addr:0x12628, type:VideoWrite},
{fname:"sub_12cea", addr:0x12d4d, type:VideoRead | VideoWrite},
{fname:"sub_12cea", addr:0x12d50, type:VideoRead | VideoWrite},
{fname:"sub_12cea", addr:0x12d65, type:VideoRead | VideoWrite},
{fname:"sub_12cea", addr:0x12d68, type:VideoRead | VideoWrite},
{fname:"sub_12d9a", addr:0x12dbc, type:VideoWrite},
{fname:"sub_12d9a", addr:0x12dc7, type:VideoWrite},
{fname:"sub_131a4", addr:0x131d6, type:VideoWrite},
{fname:"sub_13291", addr:0x132b4, type:VideoRead | VideoWrite},
{fname:"sub_132fe", addr:0x1332a, type:VideoRead | VideoWrite},
{fname:"sub_1333c", addr:0xffffffff, type:Blocking},
{fname:"sub_13383", addr:0xffffffff, type:Blocking},
{fname:"sub_133b3", addr:0x133cd, type:VideoWrite},
{fname:"sub_133e5", addr:0x13407, type:VideoRead | VideoWrite},
{fname:"sub_13423", addr:0xffffffff, type:Blocking},
{fname:"sub_13439", addr:0x13447, type:VideoWrite},
{fname:"sub_13439", addr:0x1344f, type:VideoWrite},
{fname:"sub_13439", addr:0x13459, type:VideoWrite},
{fname:"sub_13439", addr:0x13469, type:VideoWrite},
{fname:"sub_13472", addr:0xffffffff, type:Blocking},
{fname:"sub_136d4", addr:0x1379d, type:OffsetOverflow},
{fname:"sub_136d4", addr:0x137d0, type:OffsetOverflow},
]

function optim(l)
{
  var m = l.match("^(memory\\(.*\\)) = (memory\\(.*\\)) ([\\&\\|><\\+\\-]+) (.+)$")
  if (m && m[1] == m[2])
    return m[1] + " " + m[3] + "= " + m[4];

  var m = l.match("^(memoryVideoSet|memoryVideoSet16)\\((.*?,.*?), (memoryVideoGet|memoryVideoGet16)\\((.*?,.*?)\\)(.+?)\\);$")
  if (m && m[2] == m[4])
  {
    var suffix = m[5].trim();
    var ops = m[1] == "memoryVideoSet" ? "" : "16";
    if (suffix[0] == "&")
      return `memoryVideoAnd${ops}(${m[4]}, ${suffix.substr(1).trim()});`;
    if (suffix[0] == "|")
      return `memoryVideoOr${ops}(${m[4]}, ${suffix.substr(1).trim()});`;
  }
  return l;
}
function process(l, modif)
{
  l = l.trim();
  var m = l.match("^(memoryASet|memoryASet16)\\(([^,]+),([^,]+),(.+)\\);$")
  if (m)
  {
    if (modif & VideoWrite)
    {
      var mop = m[1] == "memoryASet" ? "memoryVideoSet" : "memoryVideoSet16";
      return optim(mop + "("+process(m[2])+", "+process(m[3])+", "+process(m[4], modif)+");");
    }
    var mop = m[1] == "memoryASet" ? "memory" : "memory16";
    return (mop + "("+process(m[2])+", " + process(m[3])+") = "+process(m[4], modif)+";");
  }

  var m = l.match("^(memoryAGet|memoryAGet16)\\(([^,]+),([^,]+)\\)(.*)$")
  if (m)
  {
    if (modif & VideoRead)
    {
      var mop = m[1] == "memoryAGet" ? "memoryVideoGet" : "memoryVideoGet16";
      return mop + "("+process(m[2])+", "+process(m[3])+")" + m[4];
    }
    var mop = m[1] == "memoryAGet" ? "memory" : "memory16";
    return mop + "("+process(m[2])+", " + process(m[3])+")" + m[4];
  }
   
  var m = l.match("^(.*) = (.*)$")
  if (m)
    return process(m[1]) + " = " + process(m[2]);

  return l;
}

function formatCode(code)
{
  var out = [];
  var prefix = "";
  var prevIf = false;
  for (var l of code)
  {
    if (l.includes("{") && prevIf)
    {
      prefix = prefix.substr(0, prefix.length-4);
      prevIf = false;
    }
    if (l.includes("}"))
      prefix = prefix.substr(0, prefix.length-4);
    if (l[l.length-1] == ":")
      out.push(l);
    else if (l.length > 0)
      out.push(prefix+l);
    if (l.includes("{"))
      prefix += "    ";
    if (prevIf)
    { 
      prefix = prefix.substr(0, prefix.length-4);
      prevIf = false;
    }
    if (l.substr(0, 2) == "if")
    {
      prefix += "    ";
      prevIf = true;
    }
  }
  return out;
}
function invertCondition(cond)
{
  var m = cond.match("^(.+) == (.+)$");
  if (m)
    return `${m[1]} != ${m[2]}`;

  var m = cond.match("^(.+) != (.+)$");
  if (m)
    return `${m[1]} == ${m[2]}`;

  var m = cond.match("^(.+) >= (.+)$");
  if (m)
    return `${m[1]} < ${m[2]}`;

  var m = cond.match("^(.+) <= (.+)$");
  if (m)
    return `${m[1]} > ${m[2]}`;

  var m = cond.match("^(.+) > (.+)$");
  if (m)
    return `${m[1]} <= ${m[2]}`;

  var m = cond.match("^(.+) < (.+)$");
  if (m)
    return `${m[1]} >= ${m[2]}`;

  var m = cond.match("^!([a-z.]+)$");
  if (m)
    return `${m[1]}`;

  return "!("+cond+")";
}
function optimize1(code)
{
  let mymatch1 = (text, pattern, dict) =>
  {
    var identifiers = [];
    for (var i=0; i<pattern.length; i++)
    {
      if (pattern[i] == "+" || pattern[i] == "|" || pattern[i] == "(" || pattern[i] == ")")
      {
        pattern = pattern.substr(0, i)+"\\"+pattern.substr(i);
        i++;      
      }
      if (pattern[i] == "%")
      {
         var token = "";
         for (var j=i+1; j<i+10; j++)
           if ((pattern[j] >= '0' && pattern[j] <= '9') ||
               (pattern[j] == "_") ||
               (pattern[j] >= 'a' && pattern[j] <= 'z'))
             token += pattern[j];
           else
             break;
        identifiers.push(token);
        var newtoken = "(.+)";
        if (token == "reg_16")
          newtoken = "(ax|bx|cx|dx|si|di)";
        if (token == "reg_8")
          newtoken = "(ah|al|bh|bl|ch|cl|dh|dl)";
        pattern = pattern.substr(0, i) + newtoken + pattern.substr(i+token.length+1);
        i += newtoken.length-1;
      }
    }
    pattern = "^" + pattern + "$";
    var matches = text.match(pattern);
    if (!matches)
      return false;
    for (var i=0; i<identifiers.length; i++)
    {
      if (typeof(dict[identifiers[i]]) == "undefined")
        dict[identifiers[i]] = matches[i+1];
      else if (dict[identifiers[i]] != matches[i+1])
        return false;
    }
    return true;
  };
  let mymatch = (text, index, match, dict) => {
    if (index + match.length > text.length)
      return false;
    var newdict = {...dict};
    for (var i=0; i<match.length; i++)
      if (!mymatch1(text[index+i], match[i], newdict))
        return false;
    for (var i in newdict)
      dict[i] = newdict[i];
    return true;
  };

  let mycond = (condition, dict) => {
    for (var i=0; i<condition.length; i++)
    {
      if (condition[i] == "%")
      {
        var token = condition.substr(i+1).match("(reg1|reg2|reg3|reg4|reg)")[1];
        if (!token) 
          throw "wrong token";
        var newtoken = null;
        if (token == "reg" || token == "reg1" || token == "reg2" || token == "reg3")
          newtoken = `"${dict[token]}"`;
        if (!newtoken)
          throw "bad";
        condition = condition.substr(0, i) + newtoken + condition.substr(i+token.length+1);      
      }
    }
    return eval(condition);
  };
  let myapply1 = (pattern, dict) =>
  {
    var identifiers = [];
    for (var i=0; i<pattern.length; i++)
    {
      if (pattern[i] == "%")
      {
        var token = pattern.substr(i+1).match("(reg_16|reg_8|reg1|reg2|d1|d2|str1|str2|reg3|reg4|reg|label1|label2|label|cond)")[1];
        if (!token) 
          throw "wrong token";
        identifiers.push(token);
        var newtoken = dict[token];
        pattern = pattern.substr(0, i) + newtoken + pattern.substr(i+token.length+1);
      }
    }
    return eval("`"+pattern+"`");// todo multi!
  };
  let myapply = (pattern, dict) => {
    if (typeof(pattern) == "string")
      pattern = [pattern];
    var out = [];
    for (let p of pattern)
      out.push(myapply1(p, dict));
    return out;
  };

  var patterns0 = [
   {match:["%reg >>= %d1;", "%reg >>= %d2;"],     replace:"%reg >>= ${%d1+%d2};"},
   {match:["%reg <<= %d1;", "%reg <<= %d2;"],     replace:"%reg <<= ${%d1+%d2};"},
  ]

  var patterns1 = [
   {match:["%reg = %str1;", "%reg += %str2;"],    replace:"%reg = (%str1) + %str2;"},
   {match:["%reg = %str1;", "%reg &= %str2;"],    replace:"%reg = (%str1) & %str2;"},
   {match:["%reg = %str1;", "%reg >>= %str2;"],   replace:"%reg = (%str1) >> %str2;"},
   {match:["%reg += %d1;",  "%reg &= %d2;"],      replace:"%reg = (%reg + %d1) & %d2;"},
   {match:["%reg += %d1;",  "%reg += %d2;"],      replace:"%reg += %d1 + %d2;"},
   {match:["%reg_16 = %d1;",   "out(%reg1, %reg);", "%reg_16 = %d2;"], 
    replace:["out(%reg1, (uint16_t)%d1);", "%reg_16 = %d2;"]},
   {match:["%reg_8 = %d1;",   "out(%reg1, %reg);", "%reg_8 = %d2;"], 
    replace:["out(%reg1, (uint16_t)%d1);", "%reg_8 = %d2;"]},
   {match:["%reg = %d1;", "push(%reg);", "%reg = %d2;"],
    replace:["push(%d1);", "%reg = %d2;"]},
   {match:["%reg--;", "if (%reg != 0)"],          replace:"if (--%reg != 0)"},
   {match:["if (!(%cond))","goto %label;","return;","%label:"],
    replace:["if (%cond)", "return;", "%label:"]},
  ]

  var patternsBetween = [
  {match_begin:["if (%cond)", "goto %label;"],
   match_end:["%label:"],
   replace_begin:["if (${invertCondition('%cond')})", "{"],
   replace_end:["}", "%label:"]}
  ];

  var patternsBetween3 = [

  {match_begin:["if (%cond)", "goto %label1;"],
   match_mid:["goto %label2;", "%label1:"],
   match_end:["%label2:"],
   replace_begin:["if (${invertCondition('%cond')})", "{", "%label1:"],
   replace_mid:["} else", "{"],
   replace_end:["}", "%label2:"]},

  {match_begin:["%label1:"],
   match_mid:["if (%cond)", "goto %label2;", "goto %label1;"],
   match_end:["%label2:"],

   replace_begin:["do {", "%label1:"],
   replace_mid:["} while (${invertCondition('%cond')});"],
   replace_end:["%label2:"]},

  {match_begin:["%label1:"],
   match_mid:["if (%cond)", "goto %label2;"],
   match_end:["goto %label1;", "%label2:"],

   replace_begin:["do {", "%label1:"],
   replace_mid:["if (%cond)", "break;"],
   replace_end:["} while (1);"]}
  ];

/*
void sub_10b7c()
{
    si = 0x1b8a;
loc_10b7f:
    al = memory(ds, si);
    if (al & 0x80)
        goto loc_10b8d;
    memory(ds, si) = 0x00;
    si += 0x0017;
    goto loc_10b7f;
loc_10b8d:
}

*/
  for (var i=0; i<code.length; i++)
    for (let pat of patterns0)
    {
      var dict = {}
      if (!mymatch(code, i, pat.match, dict))
        continue;
      if (!pat.if || mycond(pat.if, dict))
      {
        var apply = myapply(pat.replace, dict);
        code = code.slice(0, i).concat(apply).concat(code.slice(i+pat.match.length))
        i--;
      }
    }
  
  for (var i=0; i<code.length; i++)
    for (let pat of patterns1)
    {
      var dict = {}
      if (!mymatch(code, i, pat.match, dict))
        continue;
      if (!pat.if || mycond(pat.if, dict))
      {
        var apply = myapply(pat.replace, dict);
        code = code.slice(0, i).concat(apply).concat(code.slice(i+pat.match.length))
        i--;
      }
    }

  // todo: remove stray labels!
  var changed=true;
  while (changed)
  {
    changed = false;

    // collect labels
    var labels = {};
    for (let l of code)
    {
      if (l.substr(0, 5) == "goto ")
        labels[l.substr(5, l.length-5-1)] = 1;
    }
    // remove stray labels
    for (var i=0; i<code.length; i++)
    {
      var l = code[i];
      if (l[l.length-1] == ":")
      {
        if (typeof(labels[l.substr(0, l.length-1)]) == "undefined")
          code.splice(i--, 1);
      }
    }

    // optimize 
    for (var i=0; i<code.length; i++)
    {
      for (let pat of patternsBetween)
      {
        var dict = {debug:1}
        if (mymatch(code, i, pat.match_begin, dict))
        {
          for (var j=i+pat.match_begin.length; j<code.length; j++)
          {
            if (mymatch(code, j, pat.match_end, dict))
            {
              var apply_begin = myapply(pat.replace_begin, dict);
              var apply_end = myapply(pat.replace_end, dict);
              code = code.slice(0, j).concat(apply_end).concat(code.slice(j+pat.match_end.length))
              code = code.slice(0, i).concat(apply_begin).concat(code.slice(i+pat.match_begin.length))
              changed = true;
              break;
            }
            if (code[j].substr(0,2) == "if" || code[j].substr(0,4) == "goto" || code[j][code[j].length-1] == ":")
            {
              break;
            }
          }
        }
      }
    }

    // collect labels
    var labels = {};
    for (let l of code)
    {
      if (l.substr(0, 5) == "goto ")
        labels[l.substr(5, l.length-5-1)] = 1;
    }
    // remove stray labels
    for (var i=0; i<code.length; i++)
    {
      var l = code[i];
      if (l[l.length-1] == ":")
      {
        if (typeof(labels[l.substr(0, l.length-1)]) == "undefined")
          code.splice(i--, 1);
      }
    }
    // optimize triplets
    for (var i=0; i<code.length; i++)
    {
      for (let pat of patternsBetween3)
      {
        var dict = {}
        if (mymatch(code, i, pat.match_begin, dict))
        {
          for (var j=i+pat.match_begin.length; j<code.length; j++)
          {
            if (mymatch(code, j, pat.match_mid, dict))
            {
              for (var k=j+pat.match_mid.length; k<code.length; k++)
              {
                if (mymatch(code, k, pat.match_end, dict))
                {
                  var apply_begin = myapply(pat.replace_begin, dict);
                  var apply_mid = myapply(pat.replace_mid, dict);
                  var apply_end = myapply(pat.replace_end, dict);
                  code = code.slice(0, k).concat(apply_end).concat(code.slice(k+pat.match_end.length))
                  code = code.slice(0, j).concat(apply_mid).concat(code.slice(j+pat.match_mid.length))
                  code = code.slice(0, i).concat(apply_begin).concat(code.slice(i+pat.match_begin.length))
                  changed = true;
                  break;
                }
                if (code[k].substr(0,2) == "if" || code[k].substr(0,4) == "goto" || code[k][code[k].length-1] == ":")
                {
                  break;
                }
              }
            }

            if (code[j].substr(0,2) == "if" || code[j].substr(0,4) == "goto" || code[j][code[j].length-1] == ":")
            {
              break;
            }

          }
        }
      }
    }
  }

  if (code[code.length-2].substr(-1) == ":")
  {
    code.splice(code.length-1, 0, "return;")
  }
  return code;
}

function convert(fname, f)
{
  var code = [];
  for (var l of f)
  {
    var m = l.match("^\\s*L\\((0x[0-9a-f]+)\\);(.*)$");
    if (m)             
    {
      var tok = mpat.filter(x=>x.fname == fname && x.addr == parseInt(m[1]));
      if (tok.length > 1)
        throw "err";
      var modif = tok.length ? tok[0].type : 0
      var line = process(m[2], modif);
      if (line)
        code.push(line);
      continue;
    }
    code.push(l.trim());
  }

  code = optimize1(code);
  code = formatCode(code);
  return code;
}

var fs = require("fs")
var basepath = "/Users/gabrielvalky/Documents/git/Projects/CicoJit/cicojit/test/";
var flist = fs.readdirSync(basepath);
flist = flist.filter(x=>x.substr(-4) == ".cpp");
//flist = ["sub_1220d.cpp"];
// colect headers
var decls = [];
for (let fname of flist)
{
  var fcont = fs.readFileSync(basepath + fname).toString().split("\n");
  for (let fline of fcont)
  {
    var m = fline.match("^void (.*)\\(\\)$");
    if (m)
      decls.push(m[1]);
  }
}

decls.sort();
console.log("#include \"cicoemu.h\"");
console.log("using namespace CicoContext;");
console.log();
decls.forEach(d=>console.log(`void ${d}();`));
console.log();


for (let fname of flist)
{
  var fcont = fs.readFileSync(basepath + fname).toString().split("\n");
  for (var i=0; i<fcont.length; i++)
  {
    var m = fcont[i].match("^void (.*)\\(\\)$");
    if (m)
    {
      if (fcont[i+1] != "{")
        throw "no func begin";
      var depth = 1;
      for (var j=i+2; j<fcont.length; j++)
      {
        if (fcont[j].indexOf("{") != -1)
          depth++;
        if (fcont[j].indexOf("}") != -1)
          depth--;
        if (depth == 0)
        {
          var code = fcont.slice(i, j+1);
//console.log(code.join("\n"))
          console.log(convert(m[1], code).join("\n"));
          i = j+1;
          break;
        }
      }
    }
  }
}
