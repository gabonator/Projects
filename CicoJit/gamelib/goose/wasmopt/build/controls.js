document.onkeydown = evt => {
  if (onKey(evt.keyCode, 1))
    evt.preventDefault();
}
document.onkeyup = evt => {
  if (onKey(evt.keyCode, 0))
    evt.preventDefault();
}

function onKey(code, pressed)
{
  var cbit = (seg, ofs, e) => game.memoryBuffer[seg*16+ofs] = e;
  switch (code)                     
  {
    case 38: cbit(0x13a5, 0x8e8a+72, pressed); break;
    case 40: cbit(0x13a5, 0x8e8a+80, pressed); break;
    case 37: cbit(0x13a5, 0x8e8a+75, pressed); break;
    case 39: cbit(0x13a5, 0x8e8a+77, pressed); break;
    case 32: cbit(0x13a5, 0x8e8a+57, pressed); break;
    case "N".charCodeAt(0): cbit(0x13a5, 0x8e8a+49, pressed); break;
    case "M".charCodeAt(0): cbit(0x13a5, 0x8e8a+50, pressed); break;
    default:
      return false;
  }
  return true;   
}


/*
void onKey(int k, int p)
{
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
#define MAPKEY( c, v ) if (k==c) CicoContext::ctx->memory8(0x13a5, 0x8e8a+v) = p
// http://www.ee.bgu.ac.il/~microlab/MicroLab/Labs/ScanCodes.htm
MAPKEY( SDL_SCANCODE_LEFT, 75 );
MAPKEY( SDL_SCANCODE_RIGHT, 77 );
MAPKEY( SDL_SCANCODE_DOWN, 80 );
MAPKEY( SDL_SCANCODE_UP, 72 );
MAPKEY( SDL_SCANCODE_SPACE, 57 );
MAPKEY( SDL_SCANCODE_N, 49 );
MAPKEY( SDL_SCANCODE_M, 50 );
MAPKEY( SDL_SCANCODE_Q, 16 );
MAPKEY( SDL_SCANCODE_Y, 21 );
}
*/