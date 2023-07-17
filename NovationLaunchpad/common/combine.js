var fs = require("fs");
var buf1 = fs.readFileSync("LPMiniMK3-407.bin");
var buf2 = fs.readFileSync("code.bin");
var buf3 = fs.readFileSync("code.dat");
var pad = Buffer.from([0, 0, 0, 0, 0, 0, 0, 0, 0])
if (buf1.length + pad.length != 0x104b0)
  throw "error"
var buf = Buffer.concat([buf1, pad, buf2, buf3]);
var symbols = fs.readFileSync("code.txt").toString().split("\n").map(x=>x.split(" "));

function getSymbol(name)
{
  var addr = symbols.find(x=>x[2] == name)[0];
  console.log(name, addr);
  if (!addr)
    throw "no symbol"
  var sym = parseInt("0x"+addr);
  console.log(`${name} at 0x${sym.toString(16)}`);
  return sym;
}

var firmwareBase = getSymbol("fw_base");

var vectorPtr = getSymbol("ptr_onPress");
var vectorOrg = getSymbol("old_onPress");
var vectorNew = getSymbol("new_onPress");
swizzle(vectorPtr, vectorOrg, vectorNew | 1);

var vectorPtr = getSymbol("ptr_onRelease");
var vectorOrg = getSymbol("old_onRelease");
var vectorNew = getSymbol("new_onRelease");
swizzle(vectorPtr, vectorOrg, vectorNew | 1);

redirect(getSymbol("ptr_startup"), getSymbol("old_startup"), getSymbol("new_startup"));
redirect(getSymbol("ptr_loop"), getSymbol("old_loop"), getSymbol("new_loop"));
redirect(getSymbol("ptr_updateScreen"), getSymbol("old_updateScreen"), getSymbol("new_updateScreen"));
redirect(getSymbol("ptr_usbStatus"), getSymbol("old_usbStatus"), getSymbol("new_usbStatus"));
redirect(getSymbol("ptr_introGradient"), getSymbol("old_introGradient"), getSymbol("new_introGradient"));
string(0x0801c0a0, "pub.valky.eu/2023/novation/?method=usb&ver=23a&upn=");
function string(ptr, str)
{
  for (var i=0; i<str.length; i++)
    buf[ptr+i-firmwareBase] = str.charCodeAt(i);
  buf[ptr+str.length-firmwareBase] = 0;
}

function swizzle(ptr, pold, pnew)
{
  console.log(`swizzling at ${ptr.toString(16)} from ${pold.toString(16)} to ${pnew.toString(16)}`);
  ptr -= firmwareBase;
  if (buf[ptr+0] != ((pold>>0)&0xff) ||
      buf[ptr+1] != ((pold>>8)&0xff) ||
      buf[ptr+2] != ((pold>>16)&0xff) ||
      buf[ptr+3] != ((pold>>24)&0xff))
  {
    throw "error";
  }

  buf[ptr+0] = (pnew>>0)&0xff;
  buf[ptr+1] = (pnew>>8)&0xff;
  buf[ptr+2] = (pnew>>16)&0xff;
  buf[ptr+3] = (pnew>>24)&0xff;
}

function instr(base, i)
{
    buf[base-firmwareBase] = i >> 8;
    buf[base+1-firmwareBase] = i & 255;
}
function instr4(base, i)
{
    buf[base-firmwareBase] = (i >> 24) & 255;
    buf[base+1-firmwareBase] = (i >> 16) & 255;
    buf[base+2-firmwareBase] = (i >> 8) & 255;
    buf[base+3-firmwareBase] = (i >> 0) & 255;
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
  var newbytes = thumbBlAssembly(address, newtarget);
  if ((thumbBlDisassembly(newbytes, address)|1) != (newtarget|1))
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

// 1 - usb connected, 2 - screensaver, 0-screensaver
//buf[0x08011aa8-firmwareBase] = 0;
//buf[0x08011aac-firmwareBase] = 0; 
//buf[0x08011ab0-firmwareBase] = 0;

//nop(0x0800ce02, 2) // intro?

fs.writeFileSync("final.bin", buf)
