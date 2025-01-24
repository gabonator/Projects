extern "C" uint8_t* appMemory;

void onKey(int k, int p)
{
  if (k == SDL_SCANCODE_ESCAPE) 
    exit(0);

  #define MAPKEY( c, v ) if (k==c) appMemory[0x13a5*16+0x8e8a+v] = p
  // http://www.ee.bgu.ac.il/~microlab/MicroLab/Labs/ScanCodes.htm
  MAPKEY( SDL_SCANCODE_LEFT, 75 );
  MAPKEY( SDL_SCANCODE_RIGHT, 77 );
  MAPKEY( SDL_SCANCODE_DOWN, 80 );
  MAPKEY( SDL_SCANCODE_UP, 72 );
  MAPKEY( SDL_SCANCODE_SPACE, 57 );
  MAPKEY( SDL_SCANCODE_N, 49 );
  MAPKEY( SDL_SCANCODE_M, 50 );
  //MAPKEY( SDL_SCANCODE_Q, 16 );
  //MAPKEY( SDL_SCANCODE_Y, 21 );
}
