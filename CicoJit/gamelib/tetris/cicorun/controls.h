extern int lastKey;

void onKey(int k, int p)
{
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
    if (p)
        switch (k)
        {
            case SDL_SCANCODE_ESCAPE: lastKey = 28<<8; break;
            case SDL_SCANCODE_RETURN: lastKey = 28<<8; break;

//            case SDL_SCANCODE_SPACE: lastKey = 57; break;
            case SDL_SCANCODE_LEFT: lastKey = 75<<8; break;
            case SDL_SCANCODE_RIGHT: lastKey = 77<<8; break;
            case SDL_SCANCODE_UP: lastKey = 72<<8; break;
            case SDL_SCANCODE_DOWN: lastKey = 80<<8; break;
            case SDL_SCANCODE_TAB: lastKey = 'L'<<8; break;
            case SDL_SCANCODE_A: lastKey = 0x1f<<8; break;
            case SDL_SCANCODE_B: lastKey = 0x10<<8; break;
            case SDL_SCANCODE_C: lastKey = 0x13<<8; break; // reset high scores
            case SDL_SCANCODE_D: lastKey = 0x01<<8; break;
            
            case SDL_SCANCODE_N: lastKey = 0x31<<8; break;
            case SDL_SCANCODE_Y: lastKey = 0x15<<8; break;
        }
}

