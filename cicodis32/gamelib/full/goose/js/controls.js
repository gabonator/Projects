function onKey(keyCode, down)
{
  switch (keyCode)
  {
    case 38: memory[0x13a5 * 16 + 0x8e8a+72] = down; break; // up
    case 39: memory[0x13a5 * 16 + 0x8e8a+77] = down; break; // right
    case 40: memory[0x13a5 * 16 + 0x8e8a+80] = down; break; // down
    case 37: memory[0x13a5 * 16 + 0x8e8a+75] = down; break; // left
    case 32: memory[0x13a5 * 16 + 0x8e8a+57] = down; break; // space -> enter
    case "N".charCodeAt(0): memory[0x13a5 * 16 + 0x8e8a+49] = down; break; // space -> enter
    case "M".charCodeAt(0): memory[0x13a5 * 16 + 0x8e8a+50] = down; break; // space -> enter
    //          case "Q".charCodeAt(0): memory[0x13a5 * 16 + 0x8e8a+16] = down; break; // space -> enter
    //          case "Y".charCodeAt(0): memory[0x13a5 * 16 + 0x8e8a+21] = down; break; // space -> enter
    //          case 27: memory[0x1228 * 16 + 0x4d44 + 1] = 1; break; // esc
  }
}

document.onkeydown = function(evt) {
  evt = evt || window.event;
  onKey(evt.keyCode, 1);
}

document.onkeyup = function(evt) {
  evt = evt || window.event;
  onKey(evt.keyCode, 0);
}
