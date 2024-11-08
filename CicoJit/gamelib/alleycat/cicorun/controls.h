void onKey(int k, int p)
{    int index = -1;
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
    switch (k)
    {
      case SDL_SCANCODE_UP: index = 1; break;
      case SDL_SCANCODE_RIGHT: index = 2; break;
      case SDL_SCANCODE_DOWN: index = 3; break;
      case SDL_SCANCODE_LEFT: index = 4; break;
      case SDL_SCANCODE_P: index = 5+4; break; // pause
    }
    switch (k)
    {
      case SDL_SCANCODE_Y: index = 5+5; break;
      case SDL_SCANCODE_N: index = 5+6; break;
      case SDL_SCANCODE_K: index = 5+7; break;
      case SDL_SCANCODE_H: index = 5+8; break;
      case SDL_SCANCODE_T: index = 5+9; break;
      case SDL_SCANCODE_A: index = 5+10; break;
      case SDL_SCANCODE_S: index = 5+11; break;
      case SDL_SCANCODE_E: index = 5+12; break;
    }
    
    if (index != -1)
        CicoContext::ctx->memory8(0x1010, 0x6B7+index) = p ? 0x00 : 0x80;

    if (p)
        CicoContext::ctx->memory16(0x1010, 0x0693)++;
}
