document.onkeydown = evt => {
  setInteracted();
  if (onKey(evt.keyCode, 1))
    evt.preventDefault();
}
document.onkeyup = evt => {
  if (onKey(evt.keyCode, 0))
    evt.preventDefault();
}
document.onclick = () => setInteracted();

function onKey(code, pressed)
{
  var cbit = (seg, ofs, e) => game.memoryBuffer[seg*16+ofs] = e;

  if (curintro && pressed)
    return;
  if (curintro)
  {
    curintro = false;
    document.querySelector("#intro").style.display = "none";
    playSong("music/info.mp3");
  }

  switch (code)                     
  {
    case 38: cbit(0x168f, 0x488, pressed); break;
    case 40: cbit(0x168f, 0x490, pressed); break;
    case 37: cbit(0x168f, 0x48b, pressed); break;
    case 39: cbit(0x168f, 0x48d, pressed); break;
    case 32: cbit(0x168f, 0x45c, pressed); 
             cbit(0x168f, 0x042b, pressed); 
    break;
    case 65: 
      document.querySelectorAll('.layer').forEach(div => {
        div.classList.replace('layer', 'animatedLayer');
      });
    break;
    case 66: 
      document.querySelector("#viewport").style.left = "+200px";
      document.querySelector("#viewport").style.top = "+200px";
      document.querySelector("#viewport").style.overflow = "";
      document.body.style.background = "black";
    break;
    default:
      return false;
  }
  return true;   
}
