var fs = require("fs");
var buf1 = fs.readFileSync("LPMiniMK3-407.bin");
var buf2 = fs.readFileSync("code.bin");
var pad = Buffer.from([0, 0, 0, 0, 0, 0, 0, 0, 0])
if (buf1.length + pad.length != 0x104b0)
  throw "error"
var buf = Buffer.concat([buf1, pad, buf2]);

function getSymbol(name)
{
  var symbols = fs.readFileSync("code.txt").toString().split("\n").map(x=>x.split(" "));
  var sym = parseInt("0x"+symbols.find(x=>x[2] == name)[0]);
  console.log(`${name} at 0x${sym.toString(16)}`);
  return sym;
}

var firmwareBase = getSymbol("fw_base");
var vectorPtr = getSymbol("ptr_timer");
var vectorOrg = getSymbol("old_timer");
var vectorNew = getSymbol("new_timer") | 1;

swizzle(vectorPtr, vectorOrg, vectorNew);

var vectorPtr = getSymbol("ptr_onKeyDown");
var vectorOrg = getSymbol("old_onKeyDown");
var vectorNew = getSymbol("new_onKeyDown") | 1;

swizzle(vectorPtr, vectorOrg, vectorNew);

redirect(getSymbol("ptr_loop"), getSymbol("old_loop"), getSymbol("new_loop"));

redirect(getSymbol("ptr_updateScreen"), getSymbol("old_updateScreen"), getSymbol("new_updateScreen"));

function swizzle(ptr, pold, pnew)
{
  console.log(`swizzling at ${ptr.toString(16)} from ${pold.toString(16)} to ${pnew.toString(16)}`);
  ptr -= firmwareBase;
  if (buf[ptr+0] != ((pold>>0)&0xff) ||
      buf[ptr+1] != ((pold>>8)&0xff) ||
      buf[ptr+2] != ((pold>>16)&0xff) ||
      buf[ptr+3] != ((pold>>24)&0xff))
    throw "error";

  buf[ptr+0] = (pnew>>0)&0xff;
  buf[ptr+1] = (pnew>>8)&0xff;
  buf[ptr+2] = (pnew>>16)&0xff;
  buf[ptr+3] = (pnew>>24)&0xff;
}
function nop(base, pairs)
{
  for (var i=0; i<pairs; i++)
  {
    buf[base+i*2-firmwareBase] = 0x00;
    buf[base+i*2+1-firmwareBase] = 0xbf;
  }
}

function redirect(address, oldtarget, newtarget)
{
  console.log(`swizzling at ${address.toString(16)} from ${oldtarget.toString(16)} to ${newtarget.toString(16)}`);
  baddr = address - firmwareBase;
  var bytes = [buf[baddr], buf[baddr+1], buf[baddr+2], buf[baddr+3]]
  var curtarget = thumbBlDisassembly(bytes, address);
  if (oldtarget != curtarget)
    throw "error";
  console.log("target", oldtarget.toString(16), curtarget.toString(16));
  var newbytes = thumbBlAssembly(address, newtarget);
  if (thumbBlDisassembly(newbytes, address) != newtarget)
    throw "error";
  buf[baddr+0] = newbytes[0];
  buf[baddr+1] = newbytes[1];
  buf[baddr+2] = newbytes[2];
  buf[baddr+3] = newbytes[3];
}

function thumbBlAssembly(origin, target)
{
  var offset = target - (origin + 4);
  if (offset < 0)
    throw "error";
  offset >>= 1;
  offset &= 0x00FFFFFF;
  var words = [0xF000 | ((offset >> 11) & 0x7FF),
    0xF800 | (offset & 0x7FF)];
  return [words[0] & 255, words[0] >> 8, words[1] & 255, words[1] >> 8];
}

function thumbBlDisassembly(bytes, address)
{ 
  var words = [bytes[0] | (bytes[1] << 8), bytes[2] | (bytes[3] << 8)]
  console.log(address.toString(16), words[0].toString(16), words[1].toString(16));
  if ((words[0] & 0xf800) != 0xf000 || (words[1] & 0xf800) != 0xf800)
    throw "error";
  var offset = (words[1] & 0x7ff) | ((words[0] & 0x7ff)<<11)
  if (offset & 0x200000)
    offset |= 0xfff00000
  console.log("ofs", offset.toString(16));
  offset <<= 1;
  return address+offset+4;
}
/*
nop(0x0800cde6+8, 2*2);
//nop(0x0800cdfa, 4*2);
//nop(0x0800ce06, 2); // black
nop(0x0800ce14, 6); 
nop(0x0800ce24, 2);

nop(0x0800ce28, 2);
nop(0x0800ce3c, 2);
//nop(0x0800ce44, 2); // black
nop(0x0800ce4c, 2);
*/
fs.writeFileSync("final.bin", buf)
