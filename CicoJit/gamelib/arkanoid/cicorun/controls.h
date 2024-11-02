void onKey(int k, int p)
{
    int scancode = 0;
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
    switch (k)
    {
//case SDL_SCANCODE_UP: CicoCont.ext::ctx->memory8(0x168f, 0x488) = p; break; // up
//case SDL_SCANCODE_DOWN: CicoContext::ctx->memory8(0x168f, 0x490) = p; break; // down
//case SDL_SCANCODE_RIGHT: scancode = 0x74; break; // left
//case SDL_SCANCODE_LEFT: scancode = 0x76b; break; // right
//case SDL_SCANCODE_SPACE: scancode = 0x29; break; // enter
        case SDL_SCANCODE_1: scancode = 0x76; break; // enter
        case SDL_SCANCODE_2: scancode = 0x3b; break; // enter
        case SDL_SCANCODE_LEFT: scancode = 0x4b; break; // enter
        case SDL_SCANCODE_RIGHT: scancode = 0x4d; break; // enter
        case SDL_SCANCODE_SPACE: scancode = 0x39; break; // enter
    }
    /*
     [0]    int    0x0000004b
     [1]    int    0x0000004d
     [2]    int    0x00000039
     
     if (ah == 0x3b)
         goto loc_1c4b3;
     if (ah == 0x43)
         goto loc_1c49c;
     al = 0x01;
     if (ah == 0x3c)
         goto loc_1c44b;
     al++;
     if (ah == 0x3d)
         goto loc_1c44b;
     if (ah == 0x44)
         goto loc_1c4da;
     if (ah == 0x30)
         goto loc_1c4a2;
     if (ah == 0x19)
         goto loc_1c500;

     */
        CicoContext::ctx->memory8(0x1b0c, 0x1339) = p ? scancode : 0;// + p * 0x80;
    
    //0x1b0c, 0x1339
}

