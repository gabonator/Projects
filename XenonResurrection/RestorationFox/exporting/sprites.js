var fs=require("fs");
var lines = fs.readFileSync("sprites.txt").toString().split("\n");
lines.pop();
var palette = lines.pop().split(" ").filter(x=>x.length).map(x=>parseInt("0x"+x));

var tiles = fs.readFileSync("map.txt").toString().split("\n");
tiles = tiles.map(l => l.split(" ").map(x=>parseInt("0x"+x)));
//console.log(palette);


const Jimp = require('jimp');


let image = new Jimp(256, 256, function (err, image) {
  if (err) throw err;

  for (var y=0; y<lines.length; y++)
  {
    for (var x=0; x<lines[y].length; x++)
    {
      var p = parseInt("0x"+lines[y][x]);
//console.log(p);
      var rgb = palette[p];
      var c = Jimp.rgbaToInt((rgb>>16) &0xff, (rgb>>8)&0xff, (rgb)&0xff, 0xff);
      image.setPixelColor(c, x, y);
    }
  }

  image.write('sprites.png', (err) => {
    if (err) throw err;
  });
});

let image2 = new Jimp(16*256, 37*16, function (err, image) {
  if (err) throw err;

  for (var y=0; y<37; y++)
  {
    for (var x=0; x<256; x++)
    {
      var tileId = tiles[y][x];
      var _bx = (tileId%16)*16;
      var _by = Math.floor(tileId/16)*16;
      for (var _x=0; _x<16; _x++)
        for (var _y=0; _y<16; _y++)
        {
          var p = parseInt("0x"+lines[_by+_y][_bx+_x]);
          var rgb = palette[p];
          var c = Jimp.rgbaToInt((rgb>>16) &0xff, (rgb>>8)&0xff, (rgb)&0xff, 0xff);
          image.setPixelColor(c, x*16+_x, y*16+_y);
        }
    }
  }

  image.write('level.png', (err) => {
    if (err) throw err;
  });
});
