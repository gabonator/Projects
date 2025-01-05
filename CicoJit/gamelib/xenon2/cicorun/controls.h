void sub_12b22();
void sub_14f96();
void sub_12e84();
void sub_14e78();
void sub_14a69();
void powerup(int n);
extern int xenonPowerup;
void onKey(int k, int p)
{
//    if (p && k == SDL_SCANCODE_RETURN)
//        keyboardBuffer.push_back(0x1c0d);
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
        
    int code = 0;
    switch (k)
    {
        case SDL_SCANCODE_UP: code = 1; break;
        case SDL_SCANCODE_DOWN: code = 2; break;
        case SDL_SCANCODE_LEFT: code = 4; break;
        case SDL_SCANCODE_RIGHT: code = 8; break;
        case SDL_SCANCODE_SPACE: code = 0x80;
            if (p && !(CicoContext::ctx->memory8(0x2853, 0x8f59) & 0x80))
                CicoContext::ctx->memory8(0x2853, 0x8F5B) = 0xff;
            break;
        //case SDL_SCANCODE_A: xenonPowerup = 100; break;
        case SDL_SCANCODE_0: xenonPowerup = 0; break;
        case SDL_SCANCODE_1: xenonPowerup = 1; break;
        case SDL_SCANCODE_2: xenonPowerup = 2; break;
        case SDL_SCANCODE_3: xenonPowerup = 3; break;
        case SDL_SCANCODE_4: xenonPowerup = 4; break;
        case SDL_SCANCODE_5: xenonPowerup = 5; break;
        case SDL_SCANCODE_6: xenonPowerup = 6; break;
        case SDL_SCANCODE_7: xenonPowerup = 7; break;
        case SDL_SCANCODE_8: xenonPowerup = 8; break;
        case SDL_SCANCODE_9: xenonPowerup = 9; break;
        case SDL_SCANCODE_A: xenonPowerup = 10; break;
        case SDL_SCANCODE_B: xenonPowerup = 11; break;
        case SDL_SCANCODE_C: xenonPowerup = 12; break;
        case SDL_SCANCODE_D: xenonPowerup = 13; break;
        case SDL_SCANCODE_E: xenonPowerup = 14; break;
        case SDL_SCANCODE_F: xenonPowerup = 15; break;
        case SDL_SCANCODE_G: xenonPowerup = 16; break;
        case SDL_SCANCODE_H: xenonPowerup = 17; break;
        case SDL_SCANCODE_I: xenonPowerup = 18; break;
        case SDL_SCANCODE_Z: xenonPowerup = 100; break;
        case SDL_SCANCODE_X: {
            int prevcs = CicoContext::ctx->_cs;
            CicoContext::ctx->_cs = 0x1000;
            CicoContext::ctx->memory16(0x2853, 0x4257) = CicoContext::ctx->memoryAGet16(0x0040, 0x0063);
            sub_14a69();
            CicoContext::ctx->_cs = prevcs;
        }
        break;

        case SDL_SCANCODE_RETURN: code = 0x80;
            CicoContext::ctx->memory8(0x2853, 0x8f5b) = 0xff; break;
    }
    if (p)
        CicoContext::ctx->memory8(0x2853, 0x8f59) |= code;
    else
        CicoContext::ctx->memory8(0x2853, 0x8f59) &= ~code;    
}
