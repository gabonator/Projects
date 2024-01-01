#include "font.h"
#include <functional>
#include <cstdio>

uint32_t buffer[240*64];
class CRenderer
{
  CRect mViewport;
  CRect mClip;
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
  void SetClipRect(const CRect& clip)
  {
    mClip = clip;
  }
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
            FillRect({pt.x, y, pt.x+mFont.widths[' '] + mFont.widths[0], y+mFont.height}, bkg);
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
          FillRect({x, y, x+mFont.widths[0], y+mFont.height}, bkg);
        x += mFont.widths[0];
    }
    return x - oldx;
  }

  void Blit(const CPoint& pt)
  {
    #define GetColorR(rgb) ((rgb) & 0xff)
    #define GetColorG(rgb) (((rgb) >> 8)&0xff)
    #define GetColorB(rgb) (((rgb) >> 16)&0xff)
    #define RGB565RGB(r, g, b) (((r)>>3)|(((g)>>2)<<5)|(((b)>>3)<<11))
    #define Convert565(rgb) RGB565RGB( GetColorR(rgb), GetColorG(rgb), GetColorB(rgb))
    uint16_t buf16[240];
    if (pt.x >= mClip.right || pt.x+mViewport.Width() < mClip.left || 
        pt.y >= mClip.bottom || pt.y+mViewport.Height() < mClip.top)
      return;
    int w = mViewport.Width();
    int bx = pt.x;
    int sx = 0;
    int bw = w;
    if (bx + bw >= mClip.right)
    {
      bw = mClip.right - bx;
    }
    if (bx < mClip.left)
    {
      int d = mClip.left - bx;
      bw -= d;
      sx += d;
      bx = mClip.left;
    }
    for (int y=0; y<mViewport.Height(); y++)
    {
      if (y+pt.y < mClip.top || y+pt.y >= mClip.bottom)
        continue;
      for (int x=0; x<w; x++)
      {
        uint32_t rgb32 = buffer[y*w+x];
        buf16[x] = Convert565(rgb32);
      }
      BSP_LCD_FillRGBRect(0, bx, pt.y+y, (uint8_t*)(buf16+sx), bw, 1);
    }
  }
};

class CWnd
{
  mutable CRect mScreen;
  mutable CWnd* mParent;

public:
  void SetScreenRect(const CRect& rect) const
  {
    mScreen = rect;
  }
  const CRect& GetScreenRect() const
  {
    return mScreen;
  }
  void SetParent(CWnd* p) const
  {
    mParent = p;
  }
  virtual CRect GetExtent(CRenderer& r) const = 0;
  virtual void Render(CRenderer& r) const = 0;
  virtual void OnPress(const CPoint& p) {}
  virtual void OnRelease(const CPoint& p) {}
};

class CWndTitle : public CWnd
{
  const char* mMsg;

public:
  CWndTitle(const char* msg) : mMsg(msg)
  {
  }
  virtual CRect GetExtent(CRenderer& r) const override
  {
    r.SetFont(fonts::arial28b);
    CRect rcFull = r.GetTextExtent(mMsg);
    return rcFull;
  }
  virtual void Render(CRenderer& r) const override
  {
    r.SetFont(fonts::arial28b);
    r.Clear(0x202020);
    r.DrawText(CPoint{0, 0}, 0xffffff, 0x202020, mMsg);
  }
};

class CWndStatic : public CWnd
{
  const char* mMsg{nullptr};
public:    
  CWndStatic() = default;
  CWndStatic(const char* msg)
  {
    this->operator()(msg);    
  }
  CWndStatic& operator()(const char* msg)
  {
    mMsg = msg;
    return *this;
  }
  virtual CRect GetExtent(CRenderer& r) const override
  {
    r.SetFont(fonts::arial15);
    CRect rcFull = r.GetTextExtent(mMsg);
    return rcFull;
  }
  virtual void Render(CRenderer& r) const override
  {
    r.SetFont(fonts::arial15);
    r.Clear(0x202020);
    r.DrawText(CPoint{0, 0}, 0xb0b0b0, 0x202020, mMsg);
  }
};

typedef std::function<void(void)> function_t;

class CWndButton : public CWnd
{
public:
  enum ButtonType_t {
    Primary,
    Secondary,
    Other
  };
  const char* mMsg{nullptr};
  uint32_t mColor{0};
  bool mPressed{false};
  function_t mHandler;

public:
  CWndButton() = default;
  CWndButton(const char* msg, ButtonType_t t, function_t f)
  {
    this->operator()(msg, t, f);
  }
  CWndButton& operator()(const char* msg, ButtonType_t t, function_t f)
  {
    mMsg = msg;
    mHandler = f;
    switch (t)
    {
      case Primary:
        mColor = 0x007bff;
      break;
      case Secondary:
        mColor = 0x6c757d;
      break;
      case Other:
        mColor = 0x17a2b8;
      break;
    }
    return *this;
  }
  void SetText(const char* msg)
  {
    mMsg = msg;
  }
  virtual CRect GetExtent(CRenderer& r) const override
  {
    r.SetFont(fonts::arial28);
    CRect rcFull = r.GetTextExtent(mMsg);
    rcFull.Inflate(24, 24);
    return rcFull;
  }

  virtual void Render(CRenderer& r) const override
  {
    r.Clear(0x202020);
    r.SetFont(fonts::arial28);
    CRect rcFull = r.GetTextExtent(mMsg);
    rcFull.Inflate(24, 24);
    if (mPressed)
    {
      rcFull.Deflate(2, 2);
      r.RoundRectangle(rcFull, 12, 0xffffff);
      rcFull.Deflate(8, 8);
      r.RoundRectangle(rcFull, 10, mColor);
      rcFull.Deflate(14, 14);
    } else {
      rcFull.Deflate(8, 8);
      r.RoundRectangle(rcFull, 10, mColor);
      rcFull.Deflate(16, 16);
    }
    r.DrawText(CPoint{0, 0}, 0xffffff, mColor, mMsg);
  }

  virtual void OnPress(const CPoint& p) override
  {
    mPressed = true;
  }
  virtual void OnRelease(const CPoint& p) override
  {
    mHandler();
    mPressed = false;
  }
};

class CWndCheckbox : public CWndButton
{
  bool mChecked{false};
  const char* mMsg;
  char mFormattedMsg[128];

public:
  CWndCheckbox() = default;
  CWndCheckbox(const char* msg, bool checked, function_t f)
  {
    mChecked = checked;
    this->operator()(msg, f);
  }

  CWndCheckbox& operator()(const char* msg, function_t f)
  {
    mMsg = msg;
    assert(strlen(mMsg)+4 < sizeof(mFormattedMsg));
    sprintf(mFormattedMsg, "%c %s", mChecked ? 0x80 : 0x81, mMsg);
    CWndButton::operator()((const char*)mFormattedMsg, CWndButton::Other, f);
    return *this;
  }

  bool Toggle()
  {
    mChecked = !mChecked;
    sprintf(mFormattedMsg, "%c %s", mChecked ? 0x80 : 0x81, mMsg);
    CWndButton::SetText((const char*)mFormattedMsg);
    return mChecked;
  }

  bool Checked()
  {
    return mChecked;
  }
};

class CWndSpacer : public CWnd
{
  int mWidth;

public:
  CWndSpacer(int width) : mWidth(width)
  {
  }
  virtual CRect GetExtent(CRenderer& r) const override
  {
    return {0, 0, mWidth, 0};
  }
  virtual void Render(CRenderer& r) const override
  {
  }
};

class CLayout
{
  CRenderer mRender;
  CRect mView;
  CRect mClip;
  CPoint mPoint;
  int mMaxHeight{0};

public:
  enum LayoutControl_t {
    Nl = 1,
    Pad = 2
  };

public:
  CLayout(CRect draw, CRect clip) : mView(draw), mClip(clip), mPoint{draw.left, draw.top}, mMaxHeight{0}
  {
    mRender.SetClipRect(clip);
    lcd::FillRect({clip.left, clip.top, clip.right, draw.top}, 0x202020);
  }

  CLayout& operator << (const CWnd& e)
  {
    if (mPoint.y > mClip.bottom)
      return *this;

    const CRect rc = e.GetExtent(mRender);
    if (rc.Height() == 0)
    {
      CRect pad{mPoint.x, mPoint.y, mPoint.x + rc.Width(), mPoint.y + mMaxHeight};
      lcd::FillRect(pad, 0x202020);
    } else
    {
      mRender.Viewport(rc);
      CRect screen{mPoint.x, mPoint.y, mPoint.x + rc.Width(), mPoint.y + rc.Height()};
      if (screen.Intersects(mClip))
      {
        e.SetScreenRect(screen);
        e.Render(mRender);
        mRender.Blit(mPoint);
      }
    }
    mPoint.x += rc.Width();
    mMaxHeight = std::max(mMaxHeight, rc.Height());
    return *this;
  }

  CLayout& operator << (LayoutControl_t c)
  {
    if (c == Nl)
    {
      CRect padRight{mPoint.x, mPoint.y, lcd::width, mPoint.y + mMaxHeight};
      lcd::FillRect(padRight, 0x202020);
      CRect padLeft{0, mPoint.y, mView.left, mPoint.y + mMaxHeight};
      lcd::FillRect(padLeft, 0x202020);
      mPoint.x = mView.left;
      mPoint.y += mMaxHeight;
      mMaxHeight = 0;
    }
    if (c == Pad)
    {
      lcd::FillRect({mClip.left, mPoint.y, mClip.right, mClip.bottom}, 0x202020);
    }
    return *this;
  }
};

CRenderer render;

class CApp
{
  CPoint mTouchLast;
  struct CTimedPoint : CPoint {
    int32_t timestamp; 
    bool valid;
  };
  CArray<CTimedPoint, 100> mLine;
  CRect viewport;
  CPoint pt{0, 0};
  CPoint ptLast{0, 0};
  CArray<CWnd*, 10> mChildren;
  CWnd* mCapture{nullptr};
  CWndStatic mStatic;
  CWndButton mBtnOk;
  CWndButton mBtnCancel;
  CWndCheckbox mBtnCheck1;
  CWndCheckbox mBtnCheck2;
  CWndCheckbox mBtnCheck3;
  CWndCheckbox mBtnCheck4;
  CRenderer mRender;

public:
  void Redraw(const CPoint& pt)
  {
    auto onOk = [&]() {
      mStatic("Pressed ok");
      Redraw(pt);
    };
    auto onCancel = [&]() {
      mStatic("Pressed cancel");
      Redraw(pt);
    };
    auto onLed = [&](int i, bool checked)
    {
      gpio::digitalWrite(i, checked);
    };
    CLayout layout({pt.x, pt.y, pt.x+lcd::width, pt.y+lcd::height}, {0, 0, lcd::width, lcd::height});
    layout << CWndTitle("Demo form") << CLayout::Nl
      << CWndStatic("Hello this is a static message,") << CLayout::Nl
      << CWndStatic("second line goes here!") << CLayout::Nl
      << mStatic << CLayout::Nl
      << mBtnOk("Ok", CWndButton::Primary, onOk) << CWndSpacer(20) << mBtnCancel("Cancel", CWndButton::Secondary, onCancel) << CLayout::Nl
      << mBtnCheck1("LED 1", [&](){ onLed(1, mBtnCheck1.Toggle()); Redraw(mBtnCheck1); }) << CWndSpacer(8)
      << mBtnCheck2("LED 2", [&](){ onLed(2, mBtnCheck2.Toggle()); Redraw(mBtnCheck2); }) << CLayout::Nl
      << mBtnCheck3("LED 3", [&](){ onLed(3, mBtnCheck3.Toggle()); Redraw(mBtnCheck3); }) << CWndSpacer(8)
      << mBtnCheck4("LED 4", [&](){ onLed(4, mBtnCheck4.Toggle()); Redraw(mBtnCheck4); }) << CLayout::Nl
      << CLayout::Pad;
  }
  void Redraw(const CWnd& w)
  {
    const CRect rc = w.GetExtent(mRender);
    CRect screen = w.GetScreenRect();
    mRender.Viewport(rc);
    w.Render(mRender);
    mRender.Blit({screen.left, screen.top});
  }
  virtual void Init()
  {
    CRect screen{0, 0, lcd::width, lcd::height};
    lcd::FillRect(screen, 0xff101010);
    mChildren.push(&mBtnOk);
    mChildren.push(&mBtnCancel);
    mChildren.push(&mBtnCheck1);
    mChildren.push(&mBtnCheck2);
    mChildren.push(&mBtnCheck3);
    mChildren.push(&mBtnCheck4);
    mRender.SetClipRect({0, 0, lcd::width, lcd::height});
//    mRender.SetClipRect({20, 20, lcd::width-20, lcd::height-20});
    Redraw(pt);
  }
  virtual void Do()
  {
    if (ptLast != pt)
    {
      Redraw(pt);
      ptLast = pt;     
    }
  }
  virtual void OnTouchBegin(const CPoint& point)
  {
    for (int i=0; i<mChildren.size; i++)
      if (mChildren[i]->GetScreenRect().IsPointInside(point))
      {
        mCapture = mChildren[i];
        mCapture->OnPress(point); 
        Redraw(*mCapture);
        break;
      }
    mTouchLast = point;
  }
  virtual void OnTouchMove(const CPoint& point)
  {
    pt.x += point.x - mTouchLast.x;
    pt.y += point.y - mTouchLast.y;
    mTouchLast = point;
  }
  virtual void OnTouchEnd(const CPoint& point)
  {
    if (mCapture)
    {
      mCapture->OnRelease(point);
      Redraw(*mCapture);
      mCapture = nullptr;
    }
  }
};

namespace std {
void __throw_bad_function_call() { while (1); }
}

extern "C" {
  void __assert_func (const char *file, int line, const char* func, const char* cond)
  {
    CRect screen{0, 240-58, 240, 240};
    lcd::SetFontSize(12);
    lcd::FillRect(screen, 0xff0000);
    lcd::DrawText(screen.TopLeft() + CPoint{0, 8}, 0xffffff, 0xff0000, "Assertion failed");
    char strLine[128];
    sprintf(strLine, "in %s: %d", file, line);
    lcd::DrawText(screen.TopLeft() + CPoint{120, 8}, 0xffffff, 0xff0000, strLine);
    lcd::DrawText(screen.TopLeft() + CPoint{0, 24}, 0xffffff, 0xff0000, func);
    sprintf(strLine, "condition: %s", cond);
    lcd::DrawText(screen.TopLeft() + CPoint{0, 40}, 0xffffff, 0xff0000, strLine);
    while(1);
  }
}
