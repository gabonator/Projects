if (window.location.search.includes("cats"))
{
  var c1 = 0;
  var c2 = 0;
  var ofs0 = 0;
  var ofs1 = 406;
  var frame = 0;
  var all = 150; //153;
  var ofsh = 406;

  var insert = `<div style="width:640px; height:400px; overflow:hidden; position:absolute; background:red; z-index:-20;">
  <img id="img0" style="position: absolute; width:640px; height:406px;">
  <img id="img1" style="position: absolute; width:640px; height:406px;">
  </div>`

  var div = document.createElement('div');
  div.innerHTML = insert;
  document.querySelector("canvas").parentNode.insertBefore(div, document.querySelector("canvas"));
  document.body.style.background = "#000000"
  document.querySelector("canvas").style.border = ""
  setInterval(()=>{
    if (!game.HEAP32)
      return;
    game.HEAP32[game.HEAP32[(game.symbols.egaPalette.value>>2)]>>2] = 0x80000000;
    frame++;
    var fr1 = Math.floor(all/2+frame*0.4)%(all*2);
    if (fr1 >= all)
      fr1 = all*2-1-fr1;

    var fr2 = Math.floor(frame*0.4)%(all*2);
    if (fr2 >= all)
      fr2 = all*2-1-fr2;

    var img0 = document.getElementById("img0");
    var img1 = document.getElementById("img1");
    img0.src = "../floatcat/top"+ ("00"+(fr1+1)).substr(-3) + ".png";
    img1.src = "../floatcat/btm"+ ("00"+(fr2+1)).substr(-3) + ".png";
    img0.style.top = ofs0 + "px";
    img1.style.top = ofs1 + "px";
    var dir = game.memoryBuffer[0x2853*16+0x9198] == 1 ? 1 : -1;
    ofs0 += dir;
    ofs1 += dir;
    if (ofs0 < -ofsh) {ofs0 += ofsh*2; c1 = 0;}
    if (ofs1 < -ofsh) {ofs1 += ofsh*2; c2 = 0;}
    if (ofs0 >= ofsh) {ofs0 -= ofsh*2; c1 = 0;}
    if (ofs1 >= ofsh) {ofs1 -= ofsh*2; c2 = 0;}
    c1 += 0.2;
    c2 += 0.2;
  }, 50)
}