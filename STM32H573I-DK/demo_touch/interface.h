namespace sys
{
  int32_t GetTick()
  {
    return HAL_GetTick();
  }
  void DelayMs(int n)
  {
    HAL_Delay(n);
  }
}

namespace lcd 
{
  constexpr int width = 240;
  constexpr int height = 240;
  int fontSize = 17;

  void FillRect(class CRect& rc, uint32_t color)
  {
    UTIL_LCD_FillRect(rc.left, rc.top, rc.Width(), rc.Height(), color);
  }

  void Rectangle(class CRect& rc, uint32_t color)
  {
    UTIL_LCD_DrawRect(rc.left, rc.top, rc.Width(), rc.Height(), color);
  }

  void SetFontSize(int size)
  {
    fontSize = size;
    switch (size)
    {
      case 24: 
        UTIL_LCD_SetFont(&Font24);
        break; 
      case 20: 
        UTIL_LCD_SetFont(&Font20);
        break; 
      case 16: 
        UTIL_LCD_SetFont(&Font16);
        break; 
      case 12: 
        UTIL_LCD_SetFont(&Font12);
        break; 
    }
  }
  void DrawText(const CPoint& point, uint32_t front, uint32_t back, const char* msg)
  {
    UTIL_LCD_SetTextColor(front);
    UTIL_LCD_SetBackColor(back);
    UTIL_LCD_DisplayStringAt(point.x, point.y, (uint8_t *)msg, LEFT_MODE);
  }
  void SetPixel(const CPoint& point, uint32_t color)
  {
    UTIL_LCD_SetPixel(point.x, point.y, color);
  }
  uint32_t GetPixel(const CPoint& point)
  {
    uint32_t color;
    UTIL_LCD_GetPixel(point.x, point.y, &color);
    return color;
  }
  void DrawLine(const CPoint& pt1, const CPoint& pt2, uint32_t color)
  {
    UTIL_LCD_DrawLine(pt1.x, pt1.y, pt2.x, pt2.y, color);
  }
  void DrawLineAntialias(const CPoint& pt1, const CPoint& pt2, uint32_t color)
  {
    aa::drawline_aa(pt1.x<<8, pt1.y<<8, pt2.x<<8, pt2.y<<8, color);
  }
  CRect GetTextExtent(const char* msg)
  {
    switch (fontSize)
    {
      case 24: 
        return CRect{0, 0, (int)strlen(msg)*17, 24}; 
      case 20: 
        return CRect{0, 0, (int)strlen(msg)*14, 20};
      case 16: 
        return CRect{0, 0, (int)strlen(msg)*11, 16};
      case 12: 
        return CRect{0, 0, (int)strlen(msg)*7, 12};
    }
    return CRect{0, 0, 0, 0};
  }
}

