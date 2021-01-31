/*
var input = `
void sub_10661()
{
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
}

void sub_10702()
{
    memory(_ds, 0x279) = 0x00;                  //mov byte ptr ds:279h, 0
    _si = 0x029a;                               //mov si, 29Ah
    _di = 0x02ce;                               //mov di, 2CEh
    _cx = 0x0033;                               //mov cx, 33h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ax = 0x1a00;                               //mov ax, 1A00h
    _interrupt(16);                             //int 10h
    if ((char)_bl <= (char)0x05)                //jle short loc_10731
      goto loc_10731;
    if ((char)_bl < (char)0x07)                 //jl short loc_10731
      goto loc_10731;
    if ((char)_bl > (char)0x08)                 //jg short loc_10731
      goto loc_10731;
    _si = 0x028a;                               //mov si, 28Ah
    memory(_ds, 0x279) = 0x01;                  //mov byte ptr ds:279h, 1
    goto loc_1073E;                             //jmp short loc_1073E
    _STOP_("db 90h");                           //db 90h
loc_10731:                                      //loc_10731:
    _si = 0x027a;                               //mov si, 27Ah
    memory(_ds, 0x279) = 0x00;                  //mov byte ptr ds:279h, 0
    memory(_ds, 0x278) = 0x01;                  //mov byte ptr ds:278h, 1
loc_1073E:                                      //loc_1073E:
    memory(_ds, 0x301) = 0x00;                  //mov byte ptr ds:301h, 0
    _cx = 0x0010;                               //mov cx, 10h
loc_10746:                                      //loc_10746:
    _ah = 0x10;                                 //mov ah, 10h
    _al = 0x00;                                 //mov al, 0
    _bh = memory(_ds, _si);                     //mov bh, [si]
    _si += 1;                                   //inc si
    _bl = memory(_ds, 0x301);                   //mov bl, ds:301h
    memory(_ds, 0x301) += 1;                    //inc byte ptr ds:301h
    _push(_si);                                 //push si
    _push(_cx);                                 //push cx
    _interrupt(16);                             //int 10h
    _cx = _pop();                               //pop cx
    _si = _pop();                               //pop si
    if (--_cx)                                  //loop loc_10746
      goto loc_10746;
    if (memory(_ds, 0x279) != 0x01)             //jnz short loc_1076A
      goto loc_1076A;
    sub_10776();                                //call sub_10776
    sub_1079D();                                //call sub_1079D
loc_1076A:                                      //loc_1076A:
    _di = 0x029a;                               //mov di, 29Ah
    _si = 0x02ce;                               //mov si, 2CEh
    _cx = 0x0033;                               //mov cx, 33h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
}

void sub_10776()
{
    _si = 0x029a;                               //mov si, 29Ah
    memory(_ds, 0x301) = 0x00;                  //mov byte ptr ds:301h, 0
    _cx = 0x0010;                               //mov cx, 10h
loc_10781:                                      //loc_10781:
    _push(_cx);                                 //push cx
    _bh = 0x09;                                 //mov bh, 9
    _al = memory(_ds, _si);                     //mov al, [si]
    _ax = _bh * _al;                            //imul bh
    memory(_ds, _si) = _al;                     //mov [si], al
    _si += 1;                                   //inc si
    _al = memory(_ds, _si);                     //mov al, [si]
    _ax = _bh * _al;                            //imul bh
    memory(_ds, _si) = _al;                     //mov [si], al
    _si += 1;                                   //inc si
    _al = memory(_ds, _si);                     //mov al, [si]
    _ax = _bh * _al;                            //imul bh
    memory(_ds, _si) = _al;                     //mov [si], al
    _si += 1;                                   //inc si
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_10781
      goto loc_10781;
}

void sub_1079D()
{
    _bx = _bx ^ _bx;                            //xor bx, bx
    _cx = 0x0010;                               //mov cx, 10h
    _dx = 0x029a;                               //mov dx, 29Ah
    _al = 0x12;                                 //mov al, 12h
    _ah = 0x10;                                 //mov ah, 10h
    _interrupt(16);                             //int 10h
}
`;
*/
String.prototype.trim = function() { return this.toString().replace(/^\s+|\s+$/g, ''); };
String.prototype.countOf = function(c) { var cnt = 0; for(var i=0;i<this.length;i++)if(this[i]==c)cnt++; return cnt; };

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

  while (r = l.match(new RegExp("_([abcd][hl])")))
    l = l.replace(r[0], "r8["+r[1]+"]");
  while (r = l.match(new RegExp("_([abcd]x)")))
    l = l.replace(r[0], "r16["+r[1]+"]");
  while (r = l.match(new RegExp("_(si|di|ds|es|bp|sp|cs|flags)")))
    l = l.replace(r[0], r[1]);

  if (r = l.match(new RegExp("memory\\((.*?), (.*?)\\)")))
  {
    var repl = "memory[" + r[1] + "*16+" + r[2] + "]";
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

  if (r = l.match(new RegExp("_(.*)\\<(.*), (.*), (.*)\\>\\(\\);")))
  {
    r = r.map(replaceTemplate);
    var repl = r[1]+"_"+r[2]+"_"+r[3]+"_"+r[4]+"();";
    l = l.replace(r[0], repl);
  }

  if (r = l.match(new RegExp("_(.*)\\<(.*), (.*)\\>\\(\\);")))
  {
    r = r.map(replaceTemplate);
    var repl = r[1]+"_"+r[2]+"_"+r[3]+"();";
    l = l.replace(r[0], repl);
  }

  if (r = l.match(new RegExp("_push")))
    l = l.replace(r[0], "push");
  if (r = l.match(new RegExp("_pop")))
    l = l.replace(r[0], "pop");
  if (r = l.match(new RegExp("_interrupt")))
    l = l.replace(r[0], "interrupt");
  if (r = l.match(new RegExp("_out\\((.*, r16.*)\\)")))
    l = l.replace(r[0], "out16("+r[1]+")");
  if (r = l.match(new RegExp("_out\\((.*, r8.*)\\)")))
    l = l.replace(r[0], "out8("+r[1]+")");
  if (r = l.match(new RegExp("_in\\((.*), (r16.*)\\)")))
    l = l.replace(r[0], r[1] + " = in8("+r[2]+")");
  if (r = l.match(new RegExp("_indirectCall")))
    l = l.replace(r[0], "indirectCall");

  while (r = l.match(new RegExp("\\(short\\)r16")))
    l = l.replace(r[0], "r16s");
  while (r = l.match(new RegExp("\\(char\\)r8")))
    l = l.replace(r[0], "r8s");

  while (r = l.match(new RegExp("\\(short\\)memory16get")))
    l = l.replace(r[0], "memory16gets");
  while (r = l.match(new RegExp("\\(char\\)memory")))
    l = l.replace(r[0], "memorys");

  while (r = l.match(new RegExp("\\(short\\)([0-9a-z]*)")))
    l = l.replace(r[0], "signed16("+r[1]+")");
  while (r = l.match(new RegExp("\\(char\\)\([0-9a-fx]*)")))
    l = l.replace(r[0], "signed8("+r[1]+")");

//  if (r = l.match(new RegExp("\\{(.*\\(\\)); return; \\}.*")))
//  {
    
//  }
//    l = l.replace(r[0], "indirectCall");
//{loc_1C3B0(); return; };

  return l;  
}

function flow(input)
{
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
      console.log(l);
      throw "problem";
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
  var fname;
  var result = [];

  for (var i in input)
  {
    var l = input[i];
    if (!l)
      continue;

    if (r = l.match(new RegExp("void (.*)\\(.*\\);")))
      continue;

    if (r = l.match(new RegExp("void (.*)\\(.*\\)")))
    {
      balance = -1;
      lines = [];
      fname = r[1];
    }
    if (l.countOf("}") == l.countOf("{"))
    {
      if (balance >= 0)
        lines.push(l);
    } else
    {
      balance -= l.countOf("}");
      if (balance >= 0)
        lines.push(l);
      balance += l.countOf("{");
    }
    if (balance < 0 && lines.length > 0)
    {
//       console.log(fname);
//       console.log(lines.join("\n"));
       result = result.concat(handler(fname, lines));
       lines = [];
    }
  }
  return result;
}

var fs = require("fs");
var input = fs.readFileSync("rick2.h");
var input = input.toString().split("\n");
input = findFunctions(input, (name, body) => {
  return ["function "+name+"() {", ...processFunctionBody(body), "}"];
});

input = format(input);
fs.writeFileSync("rick2.js", input.join("\n"));
//console.log(input.join("\n"));
