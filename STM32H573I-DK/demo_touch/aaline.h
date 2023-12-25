namespace aa {
// https://github.com/PetteriAimonen/QuadPawn/blob/master/Runtime/drawing.c

typedef int fix16_t;
void drawline_aa(fix16_t fx1, fix16_t fy1, fix16_t fx2, fix16_t fy2, int color);

// Draws antialiased lines
// Xiaolin Wu's algorithm, using x/256 fixed point values
void drawline_aa(fix16_t x1, fix16_t y1, fix16_t x2, fix16_t y2, uint32_t color)
{
    bool reverse_xy = false;

    auto blend = [](uint32_t fg, uint32_t bg, int alpha) -> uint32_t
    {
      uint8_t fgr = (fg >> 16) & 255;
      uint8_t fgg = (fg >> 8) & 255;
      uint8_t fgb = (fg >> 0) & 255;
      uint8_t bgr = (bg >> 16) & 255;
      uint8_t bgg = (bg >> 8) & 255;
      uint8_t bgb = (bg >> 0) & 255;
      bgr += ((fgr-bgr)*alpha) >> 8;
      bgg += ((fgg-bgg)*alpha) >> 8;
      bgb += ((fgb-bgb)*alpha) >> 8;
      return (bgr<<16) | (bgg<<8) | (bgb<<0);
    };
    
    auto swap = [](int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    };
    
    // plot the pixel at (x, y) with brightness c
    auto plot = [&](int x, int y, int c) {
        if (reverse_xy)
            swap(&x, &y);
        if (x < 0 || y < 0 || x >= 240 || y >= 240)
          return;
        if ((color >> 24) == 0xee)
        {
          UTIL_LCD_SetPixel(x >> 8, y >> 8, color);
        } else {
          uint32_t old;
          UTIL_LCD_GetPixel(x >> 8, y >> 8, &old);
          UTIL_LCD_SetPixel(x >> 8, y >> 8, blend(color, old, c));
        }
    };
    
    // Integer part of x
    auto ipart = [](int x) -> int {
        return x & (~0xFF);
    };
    
    auto round = [&](int x) -> int {
        return ipart(x + 128);
    };
    
    // Fractional part of x
    auto fpart = [](int x) -> int {
        return x & 0xFF;
    };
    
    // Remaining fractional part of x
    auto rfpart = [&](int x) -> int {
        return 256 - fpart(x);
    };

    int dx = x2 - x1;
    int dy = y2 - y1;
    if (abs(dx) < abs(dy))
    {
        swap(&x1, &y1);
        swap(&x2, &y2);
        swap(&dx, &dy);
        reverse_xy = true;
    }
    
    if (x2 < x1)
    {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }
    
    int gradient = dy * 256 / dx;
    
    // handle first endpoint
    int xend = round(x1);
    int yend = y1 + gradient * (xend - x1) / 256;
    int xgap = rfpart(x1 + 128);
    int xpxl1 = xend;  // this will be used in the main loop
    int ypxl1 = ipart(yend);
    plot(xpxl1, ypxl1, rfpart(yend) * xgap / 256);
    plot(xpxl1, ypxl1 + 256, fpart(yend) * xgap / 256);
    int intery = yend + gradient; // first y-intersection for the main loop
    
    // handle second endpoint
    xend = round(x2);
    yend = y2 + gradient * (xend - x2) / 256;
    xgap = fpart(x2 + 128);
    int xpxl2 = xend;  // this will be used in the main loop
    int ypxl2 = ipart(yend);
    plot(xpxl2, ypxl2, rfpart(yend) * xgap / 256);
    plot(xpxl2, ypxl2 + 256, fpart(yend) * xgap / 256);
    
    // main loop
    for (int x = xpxl1 + 1; x <= xpxl2 - 1; x += 256)
    {
        plot(x, ipart(intery), rfpart(intery));
        plot(x, ipart(intery) + 256, fpart(intery));
        intery = intery + gradient;
    }
}

}