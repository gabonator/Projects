  _si = 0xaf80;                                   //mov si, 0AF80h
  _di = 0x0786;                                   //mov di, 786h
  _dx = 0x0d;                                     //mov dx, 0Dh
  _cx = 0x36;                                     //mov cx, 36h
//  sub_20CBB();                                    //call sub_20CBB
var palette = [0x000000, 0xfcb46c, 0xfc9048, 0xd86c48, 0x48486c, 0x6c6c90, 0x9090b4, 0xfcd8fc, 0xb4b4d8, 0x242448, 0x000024, 0x480000, 0x6c0000, 0x902400, 0xfcb400, 0xb44824];



var fs = require("fs");
var data = fs.readFileSync("seg5.out", null);

//_cx = 16;
var pixels = [];
var imagedata = [];
var i = 0;
  var buf = "";
  for (var y=0; y<_cx; y++)
  {
    var imagedatarow = [];
    for (var x=0; x<_dx*16; x++, i++)
    {
        var base = 0xaf80+y*_dx*8;
        // AA AA BB BB CC CC DD DD
        var blk = Math.floor(x/16);
        var bit = 15-(x%16);
        var plane1 = data[base+blk*8]*256   + data[base+blk*8+1]*1;
        var plane2 = data[base+blk*8+2]*256 + data[base+blk*8+3]*1; 
        var plane3 = data[base+blk*8+4]*256 + data[base+blk*8+5]*1;
        var plane4 = data[base+blk*8+6]*256 + data[base+blk*8+7]*1;

        plane1 = (plane1>>bit) & 1;
        plane2 = (plane2>>bit) & 1;
        plane3 = (plane3>>bit) & 1;
        plane4 = (plane4>>bit) & 1;
        var color = plane1 + plane2 * 2 + plane3 * 4 + plane4 * 8;
        imagedatarow.push(palette[color]);
        buf += color.toString(16);
    }
    pixels.push(buf);
    imagedata.push(imagedatarow);
    buf = "";
  }
console.log(pixels.map(s=>s.substr(0, 140)));


const Jimp = require('jimp');

let image = new Jimp(_dx*16, _cx, function (err, image) {
  if (err) throw err;

  imagedata.forEach((row, y) => {
    row.forEach((color, x) => {
      image.setPixelColor(color*256+0xff, x, y);
    });
  });

  image.write('test.png', (err) => {
    if (err) throw err;
  });
});