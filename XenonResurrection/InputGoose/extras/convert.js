var palette = [0x000000, 0x0000b0, 0x00b000, 0x00b0b0, 0xb00000, 0xb000b0, 0xb0b000, 0xb0b0b0,
               0x808080, 0x0000ff, 0x00ff00, 0x00ffff, 0xff0000, 0xff00ff, 0xffff00, 0xffffff];

palette = palette.map(x=>x*256+0xff);
palette.push(0);

var fs = require("fs");
function convert(f, trans)
{
  var data = fs.readFileSync("../"+f+".x", null);

  if (!trans)
    trans = -1;

  //_cx = 16;
  var imagedata = [];
  var i = 0;
  var buf = "";
  for (var y=0; y<200; y++)
  {
    var imagedatarow = [];
    for (var x=0; x<160; x++)
    {
        var color = data[i++];
        var p1 = color>>4;
        if (p1 == trans) p1 = 16;
        imagedatarow.push(palette[p1]);
        var p2 = color&15;
        if (p2 == trans) p2 = 16;
        imagedatarow.push(palette[p2]);
    }
    imagedata.push(imagedatarow);
  }


  const Jimp = require('jimp');

  let image = new Jimp(320, 200, function (err, image) {
    if (err) throw err;

    imagedata.forEach((row, y) => {
      row.forEach((color, x) => {
        image.setPixelColor(color, x, y);
      });
    });

    image.write(f+".png", (err) => {
      if (err) throw err;
    });
  });
}

convert("newbird");
convert("podz1");
convert("bird1", 2);
convert("bird2", 2);
convert("blox");
//convert("intro");