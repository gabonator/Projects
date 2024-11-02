extern int lastKey;
void onKey(int k, int p)
{
    if (k == SDL_SCANCODE_ESCAPE) exit(1);
      //if (p)
          switch (k)
          {
                  
//              case SDL_SCANCODE_ESCAPE: keyBuffer.push_back(27); break;
//              case SDL_SCANCODE_RETURN: keyBuffer.push_back(13); break;

              case SDL_SCANCODE_SPACE: lastKey = 57;
                  CicoContext::ctx->memory8(0x1ed, 0x03a1) = p;
                  break;
//              case SDL_SCANCODE_LEFT:
//                 //a57:9c8 = 2|0xfffe, a57:9ca = 0/2
//                  keyBuffer.push_back(0);
//                  keyBuffer.push_back('M'); break;
//              case SDL_SCANCODE_RIGHT:
//                  keyBuffer.push_back(0);
//                  keyBuffer.push_back('K'); break;
//              case SDL_SCANCODE_UP:
//                  keyBuffer.push_back(0);
//                  keyBuffer.push_back('H'); break;
//              case SDL_SCANCODE_DOWN:
//                  keyBuffer.push_back(0);
//                  keyBuffer.push_back('P'); break;
                   
                  //0x0386 pause
              case SDL_SCANCODE_LEFT: CicoContext::ctx->memory8(0x1ed, 0x39a) = p; break;
              case SDL_SCANCODE_RIGHT: CicoContext::ctx->memory8(0x1ed, 0x39c) = p; break;
              case SDL_SCANCODE_UP: CicoContext::ctx->memory8(0x1ed, 0x388) = p; break;
              case SDL_SCANCODE_DOWN: CicoContext::ctx->memory8(0x1ed, 0x39e) = p; break;
                  //case SDL_SCANCODE
                  /*
              case SDL_SCANCODE_1:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x2) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x3) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x4) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x5) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x6) = p;
                  break;
              case SDL_SCANCODE_2:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x7) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x8) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x9) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xa) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xb) = p;
                  break;
              case SDL_SCANCODE_3:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xc) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xd) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xe) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0xf) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x10) = p;
                  break;
              case SDL_SCANCODE_4:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x11) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x12) = p;
//                  CicoContext::ctx->memory16(0x1ed, 0x387+0x13) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x14) = p;
//                  CicoContext::ctx->memory16(0x1ed, 0x387+0x15) = p;
                  break;
              case SDL_SCANCODE_5:
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x16) = p;
                  CicoContext::ctx->memory16(0x1ed, 0x387+0x17) = p;

                  break;
              case SDL_SCANCODE_6: CicoContext::ctx->memory16(0x1ed, 0x387+0x0) = p; break;
*/
          }
    
    
    
/*
    switch (k)
    {
        case SDL_SCANCODE_LEFT:
            CicoContext::ctx->memory16(0xa57, 0x9c8) = p ? -2 : 0;
            break;
        case SDL_SCANCODE_RIGHT:
            CicoContext::ctx->memory16(0xa57, 0x9c8) = p ? 2 : 0;
            break;
        case SDL_SCANCODE_UP:
            CicoContext::ctx->memory16(0xa57, 0x9c8+4) = p ? 1 : 0;
            break;
    }*/
}
