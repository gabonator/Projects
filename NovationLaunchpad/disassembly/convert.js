var fs=require("fs");
var input = fs.readFileSync("input.s").toString().split("\n");

var re = new RegExp("^ ([0-9a-f]{7}):\t(.*?)\t(.*)$")
var undef32 = new RegExp("; <UNDEFINED> instruction: 0x([0-9a-f]{8})$");
var comment = new RegExp("^(.+\t.+\t);( .*)$")

var wrong = ["vrev64.32", "stmia", "movs	r0, r0", "lsrs",
 "vshr.u32", "illegal", "UNDEFINED", "<und>", ".s", ".u", "hlt	",
 "vst2", "mrrc2", ".f", "cdp2", "bhi.n", "vtbl.8", "mrc", "mcr", "undefined",
  "vuzp", "vceq", "vmsr", "ldmia",

  "movs.w	ip, r1, lsl #29",
  "strmi.w	r2, [r0], #4",
  "lsls	r1, r1, #31",
  "and.w	ip, pc, #3284386755",
  "cpsie",
  "cr14",
  "b.n	0x800fcf4"
//  "cmp	ip, pc",
//  "bic.w	r6, sp, #2146304",
];

console.log(".syntax unified");
console.log(".thumb_func");
console.log(".text");
console.log(".align 4");
console.log(".org 0x0800c000");

function isWrong(s)
{
  return wrong.find(l=>s.includes(l));
}
function isData(a)
{
  if (a == 0x8011130 || a == 0x80143ea)
    return true;
  if (a >= 0x801c350 && a <= 0x801c4a7)
    return true;
  if (a >= 0x801009c && a <= 0x80100c0)
    return true;
  if (a >= 0x8015044 && a <= 0x8015044)
    return true;
  if (a >= 0x801ad54 && a <= 0x801ad5a)
    return true;
  if (a >= 0x801aea4 && a <= 0x801aece)
    return true;
  if (a >= 0x0801a346)
  {
    if (a >= 0x0801be88 && a <= 0x0801beb8) // systeminit
      return false;
    if (a >= 0x0801c104 && a <= 0x0801c10e) // systick
      return false;
    if (a >= 0x0801c13c && a <= 0x0801c13c) //
      return false;
    if (a >= 0x0801c1f0 && a <= 0x0801c210) // startup
      return false;
    return true;
  }
  if (a >= 0x08016904 && a <= 0x0801691c)
    return true;
  if (a >= 0x0800d276 && a <= 0x0800d300)
    return true;
  if (a >= 0x0800ea9c && a <= 0x0800eaac)
    return true;
  if (a >= 0x0800fe66 && a <= 0x0800fe6c)
    return true;
  if (a >= 0x0801445e && a <= 0x08014465)
    return true;
  if (a >= 0x080181e2 && a < 0x08018b5c)
    return true;
  if (a >= 0x0800e28a && a <= 0x0800e303)
    return true;
  if (a >= 0x080176b0 && a <= 0x080176f8)
    return true;
  if (a >= 0x080120a4 && a <= 0x080120f3)
    return true;
  if (a >= 0x0801168a && a <= 0x0801169f)
    return true;

  return false;
}
function isWrongHex(h)
{
//  if (h == "1f09") // 1c49      	adds	r1, r1, #1
//    return true;
//  if (h == "1c7f")
//    return true;
//  if (h == "1c64")
//    return true;
//  if (h == "3c04")
//    return true;
  return false;
}
for (l of input)
{
  var m = l.match(re);
  if (m)
  {
    var lab = m[1];
    if (isWrong(m[3]) || isWrongHex(m[2].trim()) || isData(parseInt("0x"+m[1])))
    {
      var words = m[2].trim().split(" ");
      for (var i=0; i<words.length; i++)
      {
//        console.log(`lab_${lab}: .hword 0x`+m[2].trim().split(" ").join(", 0x"))
        console.log(`lab_${lab}: .hword 0x`+words[i]);
        lab = (parseInt("0x"+lab)+2).toString(16).substr(-7);
      }
    } else
    {
      var ll = m[3];
      var m2 = ll.match(undef32);
      if (m2)
      {
        console.log("lab_${lab}: .hword 0x"+m2[1])
        continue;
      }
//      ll = ll.replace(".n", "");
//      ll = ll.replace(".w", "");
      var m2 = ll.match(comment);
      if (m2)
        ll = m2[1];
      var instr = ll.split("\t")[0]
      if (instr == "b.n" || instr == "bcs.n" || instr == "bne.n" || instr == "bl" ||
          instr == "b.w" || instr == "bcc.n" || instr == "beq.n" || instr == "bmi.n" ||
          instr == "bne.w" || instr == "bpl.n" || instr == "bls.n" || instr == "bleq" ||
          instr == "blpl" || instr == "bcs.w" || instr == "beq.w" || instr == "bcc.w" ||
          instr == "blt.n" || instr == "bmi.w" || instr == "blne" || instr == "bge.n" ||
          instr == "blcs" || instr == "bgt" || instr == "bgt.n" || instr == "ble.n" ||
          instr == "blmi" ||
         false
       )
      {
        args = ll.split("\t")[1];
        ll = `${instr}\tlab_${args.substr(2)}`
      }
      if (instr == "cbnz" || instr == "cbz")
      {
        args = ll.split("\t")[1].split(", 0x");
        ll = `${instr}\t${args[0]}, lab_${args[1]}`
      }
      console.log(`lab_${lab}: ${ll}`);
    }
  }
}

console.log(".byte 1")