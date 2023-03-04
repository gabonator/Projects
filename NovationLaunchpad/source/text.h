extern "C" {
  extern uint16_t fontOffsets[95];
  extern uint8_t fontData[425];
}

int CApp::getTextWidth(const char* msg)
{
  int w = 0;
  while (*msg)
  {
    int c = *msg++ - 0x20;
    w += fontOffsets[c+1] - fontOffsets[c];
  }
  return w;
}

void CApp::renderText(uint8_t* buffer, int x, int y, const char* msg)
{
  if (x >= 8 || y < -8 || y >= 8)
    return;
  for (int i=0; msg[i]; i++)
  {
    int c = msg[i] - 0x20;
    int w = fontOffsets[c+1] - fontOffsets[c];
    if (x >= -w && x < 9)
    {
      for (int px=0; px<w; px++)
      {
        uint8_t line = fontData[fontOffsets[c]+px];
        for (int py=0; py<8; py++)
        {
          int xx = x+px;
          int yy = y+py;
          if (xx >= 0 && xx < 9 && yy >= 0 && yy < 8)
            if (line & (1<<py))
            buffer[xx] |= 128>>yy;
        }
      }
    }
    x += w;
  }
}
