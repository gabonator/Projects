#include "font.h"
#include <functional>
#include <cstdio>

uint32_t buffer[240*72];
class CRenderer
{
public:
  CRect mViewport;
  fonts::font_t mFont{fonts::arial28b};

public:
  void SetFont(fonts::font_t f)
  {
    mFont = f;
  }
  CRect GetTextExtent(const char* text)
  {
    int w = 0;
    if (!text)
      return CRect{0, 0, 0, 0};
    while (*text)
    {
      uint8_t ch = *text++;
      if (w != 0)
        w += mFont.widths[0];
      w += mFont.widths[ch];
    }
    return CRect{0, 0, w, mFont.height};
  }
  void Viewport(CRect rc)
  {
    assert((size_t)rc.Width() * (size_t)rc.Height() * 4 < sizeof(buffer));
    mViewport = rc;
  }
//  void SetClipRect(const CRect& clip)
//  {
//    mClip = clip;
//  }
  const CRect& Viewport() const
  {
    return mViewport;
  }
  void Clear(uint32_t color)
  {
    int32_t n = mViewport.Width() * mViewport.Height();
    for (int i=0; i<n; i++)
      buffer[i] = color;
  }
  void SetPixel(int x, int y, uint32_t c)
  {
    buffer[(y-mViewport.top)*mViewport.Width() + x - mViewport.left] = c;
  }
  void BlendPixel(int x, int y, uint32_t c, int a)
  {
    uint8_t* old = (uint8_t*)&buffer[(y-mViewport.top)*mViewport.Width() + x - mViewport.left];
    uint8_t* clr = (uint8_t*)&c;
    old[0] += (clr[0] - old[0])*a/256;
    old[1] += (clr[1] - old[1])*a/256;
    old[2] += (clr[2] - old[2])*a/256;
  }
  void BlendPixel(int x, int y, uint32_t c)
  {
    uint8_t* old = (uint8_t*)&buffer[(y-mViewport.top)*mViewport.Width() + x - mViewport.left];
    uint8_t* clr = (uint8_t*)&c;
    int a = clr[3];
    old[0] += (clr[0] - old[0])*a/256;
    old[1] += (clr[1] - old[1])*a/256;
    old[2] += (clr[2] - old[2])*a/256;
  }
  void RoundRectangle(const CRect& rc, int corner, uint32_t color)
  {
    CRect inner{rc};
    inner.Deflate(corner+1, 1);
    FillRect(inner, color);
    inner = CRect{rc.left+1, rc.top + corner+1, rc.left + corner+1, rc.bottom - corner-1};
    FillRect(inner, color);
    inner = CRect{rc.right - corner-1, rc.top + corner+1, rc.right-1, rc.bottom - corner-1};
    FillRect(inner, color);

    int radiusSquared = corner * corner;
    for (int ii = 0; ii <= corner; ii++) 
      for (int jj = 0; jj <= corner; jj++) 
      {
        int i = ii;
        int j = jj;
        
        int distanceSquared = i*i + j*j;
        if (distanceSquared <= radiusSquared) 
        {
          int intensity = 255 - ((distanceSquared - (radiusSquared - corner)) * 255) / (2 * corner);
          if (intensity > 0 && intensity <= 255)
          {
            uint32_t ncolor = color;
            ncolor = (ncolor & 0xffffff) | (((ncolor >> 24)*intensity/256)<<24);
            BlendPixel(rc.left + corner - i, rc.top + corner - j, ncolor);
            BlendPixel(rc.right - 1 - corner + i, rc.top + corner - j, ncolor);
            BlendPixel(rc.left + corner - i, rc.bottom - 1 - corner + j, ncolor);
            BlendPixel(rc.right - 1 - corner + i, rc.bottom - 1 - corner + j, ncolor);
          } else {
            SetPixel(rc.left + corner - i, rc.top + corner - j, color);
            SetPixel(rc.right - 1 - corner + i, rc.top + corner - j, color);
            SetPixel(rc.left + corner - i, rc.bottom - 1 - corner + j, color);
            SetPixel(rc.right - 1 - corner + i, rc.bottom - 1 - corner + j, color);
          }
        }
      }
  
  }
  void FillRect(const CRect& rc, uint32_t color)
  {
    uint32_t* p = &buffer[(rc.top-mViewport.top)*mViewport.Width() + rc.left - mViewport.left];
//    int w = mViewport.Width();
    int g = mViewport.Width() - rc.Width();

    for (int y=rc.top; y<rc.bottom; y++)
    {
      for (int x=rc.left; x<rc.right; x++)
        *p ++ = color;
        //SetPixel(x, y, color); //buffer[(y-mViewport.top)*mViewport.Width() + x - mViewport.left] = color;
      p += g;
    }
  }
  int DrawText(const CPoint& point, uint32_t clr, uint32_t bkg, const char* text)
  {
      return DrawText(point, clr, bkg, text, mViewport);
  }
  int DrawText(const CPoint& point, uint32_t clr, uint32_t bkg, const char* text, const CRect& clip)

  {
    if (!text)
      return 0;

    CRect rect;
    CPoint pt;

    uint32_t pal[8];
    pal[0] = bkg;
    pal[7] = clr;
    uint8_t* pc = (uint8_t*)&clr;
    uint8_t* pb = (uint8_t*)&bkg;
    for (int i=1; i<7; i++)
    {
      uint8_t* p = (uint8_t*)&pal[i];
      p[0] = pb[0] + (pc[0] - pb[0])*i/7;
      p[1] = pb[1] + (pc[1] - pb[1])*i/7;
      p[2] = pb[2] + (pc[2] - pb[2])*i/7;
    }

    auto BufferWrite = [&](int a)
    {
      //Blend(buffer[(pt.y-mViewport.top)*mViewport.Width() + pt.x - mViewport.left], clr, a);
        if (clip.IsPointInside(pt))
            SetPixel(pt.x, pt.y, pal[a]);
      if (++pt.y >= rect.bottom)
      {
        pt.x++;
        pt.y = rect.top;
      }
    };
    int x = point.x;
    const int y = point.y;
    int oldx = x;
    while (*text)
    {
        uint8_t ch = *text++;

        rect = CRect{x, y, x, y + mFont.height};
        pt = CPoint{x, y};
        const uint8_t* buf = mFont.faces[ch];
        if (!buf)
        {
            CRect space{pt.x, y, pt.x+mFont.widths[' '] + mFont.widths[0], y+mFont.height};
            if (space.ClipTo(clip))
                FillRect(space, bkg);
            x += mFont.widths[' '] + mFont.widths[0];
            continue;
        }
        const uint8_t* bufend = buf + buf[0] + 1;
        buf++;
        do {
            uint8_t dr = *buf++;
            for (int i=0; i<(dr&31); i++)
                BufferWrite(dr>>5);
            if (buf >= bufend)
                break;
            uint8_t ds = *buf++;
            BufferWrite(ds&7);
            if (buf >= bufend)
                break;
            ds >>= 3;
            BufferWrite(ds&7);
        } while (buf < bufend);
        x += mFont.widths[ch];
        if (*text)
        {
            CRect space{x, y, x+mFont.widths[0], y+mFont.height};
            if (space.ClipTo(clip))
                FillRect(space, bkg);
        }
        x += mFont.widths[0];
    }
    return x - oldx;
  }

  void Blit(const CPoint& pt, const CRect& clipRect)
  {
    #define GetColorR(rgb) ((rgb) & 0xff)
    #define GetColorG(rgb) (((rgb) >> 8)&0xff)
    #define GetColorB(rgb) (((rgb) >> 16)&0xff)
    #define RGB565RGB(r, g, b) (((r)>>3)|(((g)>>2)<<5)|(((b)>>3)<<11))
    #define Convert565(rgb) RGB565RGB( GetColorR(rgb), GetColorG(rgb), GetColorB(rgb))
    uint16_t buf16[240];
    if (pt.x >= clipRect.right || pt.x+mViewport.Width() < clipRect.left ||
        pt.y >= clipRect.bottom || pt.y+mViewport.Height() < clipRect.top)
      return;
    int w = mViewport.Width();
    int bx = pt.x;
    int sx = 0;
    int bw = w;
    if (bx + bw > clipRect.right)
    {
      bw = clipRect.right - bx;
    }
    if (bx < clipRect.left)
    {
      int d = clipRect.left - bx;
      bw -= d;
      sx += d;
      bx = clipRect.left;
    }
    for (int y=0; y<mViewport.Height(); y++)
    {
      if (y+pt.y < clipRect.top || y+pt.y >= clipRect.bottom)
        continue;
      for (int x=0; x<w; x++)
      {
          //uint32_t p = (((x>>1)+(y>>1)) & 1) ? 0x808080 : 0;
        uint32_t rgb32 = buffer[y*w+x];
        buf16[x] = Convert565(rgb32);
      }
      lcd::Blit(bx, pt.y+y, bw, 1, buf16+sx);
      //BSP_LCD_FillRGBRect(0, bx, pt.y+y, (uint8_t*)(buf16+sx), bw, 1);
    }
  }
};
