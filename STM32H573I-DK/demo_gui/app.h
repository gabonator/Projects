#include "renderer.h"

class CWnd
{
  mutable CRect mScreen;
  mutable CWnd* mParent;
    static CWnd* mCapture;
    bool mNeedRedraw{false};
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
  virtual void OnMove(const CPoint& p) {}

    virtual void Create() {}
    virtual void Loop() {}
    CWnd* GetCapture() { return mCapture; }
    void SetCapture(CWnd* p) { mCapture = p; }
    void Invalidate() { mNeedRedraw = true; };
    bool NeedsRedraw() { if (!mNeedRedraw) return false; mNeedRedraw = false; return true; }
};

CWnd* CWnd::mCapture{nullptr};

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
      Invalidate();
  }
  virtual void OnRelease(const CPoint& p) override
  {
    mHandler();
    mPressed = false;
      Invalidate();
  }
    virtual void OnMove(const CPoint& p) override
    {
        if (GetScreenRect().IsPointInside(p))
            return;
        mPressed = false;
        Invalidate();
            SetCapture(nullptr);
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

class CWndRadio : public CWnd
{
    bool mPressed{false};
    uint32_t mColor{0x17a2b8};
    mutable CPoint mDrag;
    mutable CPoint mOfs;
    CArray<const char*> mItems;
    mutable int mCurrent{0};
    
public:
    CWndRadio() = default;
    CWndRadio(const CArray<const char*>& items, int selected, function_t f)
  {
    this->operator()(items, selected, f);
  }

  CWndRadio& operator()(const CArray<const char*>& items, int selected, function_t f)
  {
      mItems = items;
      mCurrent = selected;
    return *this;
  }

    virtual CRect GetExtent(CRenderer& r) const override
    {
        assert(mItems.size > 0);
      r.SetFont(fonts::arial28);
      CRect rcFull = r.GetTextExtent(mItems[mItems.size-1]);
      rcFull.Inflate(24+20, 24);
      return rcFull;
    }

    virtual void Render(CRenderer& r) const override
    {
      r.Clear(0x202020);
      r.SetFont(fonts::arial28);
      CRect rcFull = r.GetTextExtent(mItems[mItems.size-1]);
      rcFull.Inflate(24+20, 24);
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
        CRect innerRect = r.mViewport; //{0, 0, r.mViewport.Width(), r.mViewport.Height()};
        r.DrawText(CPoint{innerRect.left+17, 0}, 0xd0d0d0, mColor, "\x85");
        innerRect.Deflate(11, 11);
        const int h = fonts::arial28.height+14;

        if (mCurrent == 0 && mOfs.y < 0)
            mOfs.y = 0;
        if (mCurrent >= mItems.size-1 && mOfs.y > 0)
            mOfs.y = 0;
        if (mOfs.y <= -h/2)
        {
            mDrag.y += h;
            mOfs.y += h;
            mCurrent--;
        }
        if (mOfs.y >= h/2)
        {
            mDrag.y -= h;
            mOfs.y -= h;
            mCurrent++;
        }
        
      r.DrawText(CPoint{0, 0} - mOfs, 0xffffff, mColor, mItems[mCurrent], innerRect);
        if (mCurrent < mItems.size -1)
            r.DrawText(CPoint{0, h} - mOfs, 0xffffff, mColor, mItems[mCurrent+1], innerRect);
        if (mCurrent > 0)
            r.DrawText(CPoint{0, -h} - mOfs, 0xffffff, mColor, mItems[mCurrent-1], innerRect);
    }
    virtual void OnPress(const CPoint& p) override
    {
        mDrag = p;
      mPressed = true;
        Invalidate();
    }
    virtual void OnRelease(const CPoint& p) override
    {
      mPressed = false;
        mOfs.y = 0;
        Invalidate();
    }

    virtual void OnMove(const CPoint& p) override
    {
        mOfs = mDrag-p;
        mOfs.x = 0;
        Invalidate();
    }
};

class CWndSpacer : public CWnd
{
  int mWidth;
    int mHeight;

public:
  CWndSpacer(int width, int height = 0) : mWidth(width), mHeight(height)
  {
  }
  virtual CRect GetExtent(CRenderer& r) const override
  {
    return {0, 0, mWidth, mHeight};
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
    lcd::FillRect({clip.left, clip.top, clip.right, draw.top}, 0x202020);
  }

  CLayout& operator << (const CWnd& e)
  {
    if (mPoint.y > mClip.bottom)
      return *this;

    const CRect rc = e.GetExtent(mRender);
    if (mClip.Width())
    {
        if (rc.Height() == 0)
        {
          CRect pad{mPoint.x, mPoint.y, mPoint.x + rc.Width(), mPoint.y + mMaxHeight};
            if (pad.ClipTo(mClip))
                lcd::FillRect(pad, 0x202020);
        } else
        {
          mRender.Viewport(rc);
          CRect screen{mPoint.x, mPoint.y, mPoint.x + rc.Width(), mPoint.y + rc.Height()};
          e.SetScreenRect(screen);
          if (screen.ClipTo(mClip))
          {
            e.Render(mRender);
            mRender.Blit(mPoint, screen);
          }
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
        if (padRight.ClipTo(mClip))
            lcd::FillRect(padRight, 0x202020);
      CRect padLeft{0, mPoint.y, mView.left, mPoint.y + mMaxHeight};
        if (padLeft.ClipTo(mClip))
      lcd::FillRect(padLeft, 0x202020);
      mPoint.x = mView.left;
      mPoint.y += mMaxHeight;
      mMaxHeight = 0;
    }
    if (c == Pad)
    {
        if (mPoint.y >= 0 && mPoint.y < mClip.bottom)
            lcd::FillRect({mClip.left, mPoint.y, mClip.right, mClip.bottom}, 0x202020);
    }
    return *this;
  }
    int Height()
    {
        return mPoint.y;
    }
};

CRenderer render;

class CDemoForm : public CWnd
{
    CPoint mTouchLast;
    CRect viewport;
    CPoint ptCurrent{0, 0};
    CPoint ptRel{0, 0};
    CPoint ptLast{-1, 0};
    CPoint mAnchor{0, 0};
    CWnd* mChildrenData[10];
    CArray<CWnd*> mChildren;
    //CWnd* mCapture{nullptr};
    CWndStatic mStatic;
    CWndButton mBtnOk;
    CWndButton mBtnCancel;
    CWndCheckbox mBtnCheck1;
    CWndCheckbox mBtnCheck2;
    CWndCheckbox mBtnCheck3;
    CWndCheckbox mBtnCheck4;
    CWndRadio mBtnRadio;
    CRenderer mRender;
    
    CPoint mDragStart;
    int mTotalHeight{0};
public:
    
    void Layout(CLayout& visitor)
    {
        auto onOk = [&]() {
          mStatic("Pressed ok");
          Redraw();
        };
        auto onCancel = [&]() {
          mStatic("Pressed cancel");
          Redraw();
        };
        auto onLed = [&](int i, bool checked)
        {
          gpio::digitalWrite(i, checked);
        };
                
        visitor << CWndSpacer(0, 4) << CLayout::Nl
          << CWndTitle("Demo form") << CLayout::Nl
          << CWndStatic("Hello this is a static message,") << CLayout::Nl
          << CWndStatic("second line goes here!") << CLayout::Nl
          << mStatic << CLayout::Nl
          << mBtnOk("Ok", CWndButton::Primary, onOk) << CWndSpacer(20) << mBtnCancel("Cancel", CWndButton::Secondary, onCancel) << CLayout::Nl
          << mBtnCheck1("LED 1", [&](){ onLed(1, mBtnCheck1.Toggle()); Redraw(mBtnCheck1); })
          << mBtnCheck2("LED 2", [&](){ onLed(2, mBtnCheck2.Toggle()); Redraw(mBtnCheck2); }) << CLayout::Nl
          << mBtnCheck3("LED 3", [&](){ onLed(3, mBtnCheck3.Toggle()); Redraw(mBtnCheck3); })
          << mBtnCheck4("LED 4", [&](){ onLed(4, mBtnCheck4.Toggle()); Redraw(mBtnCheck4); }) << CLayout::Nl
          << CWndStatic("Uart baudrate") << CLayout::Nl
          << mBtnRadio << CLayout::Nl
          << CWndSpacer(0, 30) << CLayout::Nl
          << CLayout::Pad;
    }
    
    void Redraw()
    {
        //lcd::FillRect({0, 0, lcd::width, lcd::height}, 0x800000);
        CLayout layout(CRect{6, 20, lcd::width-6, lcd::height-3} + mAnchor, {6, 20, lcd::width-6, lcd::height-3});
        Layout(layout);
    }
    void Redraw(const CWnd& w)
    {
      const CRect rc = w.GetExtent(mRender);
      CRect screen = w.GetScreenRect();
        CPoint anchor = {screen.left, screen.top};
        if (screen.ClipTo({6, 20, lcd::width-6, lcd::height-3}))
        {
            mRender.Viewport(rc);
            w.Render(mRender);
            mRender.Blit(anchor, screen);
        }
    }
    virtual void Create() override
    {
      CRect screen{0, 0, lcd::width, lcd::height};
      lcd::FillRect(screen, 0xff101010);
        mChildren = CArray(mChildrenData, sizeof(mChildrenData)/sizeof(mChildrenData[0]));
      mChildren.push(&mBtnOk);
      mChildren.push(&mBtnCancel);
      mChildren.push(&mBtnCheck1);
      mChildren.push(&mBtnCheck2);
      mChildren.push(&mBtnCheck3);
      mChildren.push(&mBtnCheck4);
        mChildren.push(&mBtnRadio);
        
        static const char* radioValues[] = {"2400", "4800", "9600", "19600", "38400", "57600", "115200"};
        mBtnRadio({radioValues, std::size(radioValues), std::size(radioValues)}, 3, [](){});
        
        CLayout layout(CRect{0, 0, 0, 1024}, {0, 0, 0, 1024});
        Layout(layout);
        mTotalHeight = layout.Height();
        
        //mRender.FillRect({0, 0, lcd::width, lcd::height}, 0xff00ff); // TODO: first line
        mRender.FillRect({0, 0, lcd::width, lcd::height}, 0x000000);
        mRender.Viewport({0, 0, lcd::width, 64});
        mRender.RoundRectangle({0, 0, lcd::width, 64}, 4, 0x808080);
        mRender.RoundRectangle({2, 19, lcd::width-2, 64-2}, 4, 0x101010);
        mRender.SetFont(fonts::arial15b);
        mRender.DrawText({6, 6}, 0xffffff, 0x808080, "Window title");
        mRender.Blit({0, 0}, {0, 0, lcd::width, 24});
        mRender.Blit({0, 2}, CRect{0, 24, lcd::width, 60});
        mRender.Blit({0, 36+2}, CRect{0, 60, lcd::width, 60+36});
        mRender.Blit({0, 36*2+2}, CRect{0, 60+36, lcd::width, 60+36+36});
        mRender.Blit({0, 36*3+2}, CRect{0, 60+36*2, lcd::width, 60+36+36*2});
        mRender.Blit({0, 36*4+2}, CRect{0, 60+36*3, lcd::width, 60+36+36*3});
        mRender.Blit({0, 36*5-4}, CRect{0, 60+36*4, lcd::width, lcd::height});
//        mRender.Blit({0, 82}, CRect{0, 22, lcd::width, 60} + CPoint{0, 82});
//        mRender.Blit({0, 142}, {0, 22, lcd::width, 60});
//        mRender.Blit({0, 202}, {0, 22, lcd::width, 60});
    }
    virtual void Loop() override
    {
        if (ptRel == CPoint{0, 0})
        {
            if (ptCurrent.y > 0)
                ptCurrent.y = (ptCurrent.y + 0)/2;
            if (mTotalHeight > lcd::height && ptCurrent.y < -(mTotalHeight - lcd::height))
                ptCurrent.y = (ptCurrent.y - (mTotalHeight - lcd::height))/2;
        }
      if (ptLast != ptCurrent + ptRel)
      {
        ptLast = ptCurrent + ptRel;
          mAnchor = ptLast;
        Redraw();
      }
    }
    virtual CRect GetExtent(CRenderer& r) const override
    {
        assert(0);
        return {0, 0, 0, 0};
    }
    virtual void Render(CRenderer& r) const override
    {
        assert(0);
    }

    virtual void OnPress(const CPoint& point) override
    {
        mDragStart = point;
        ptRel = {0, 0};
        for (int i=0; i<mChildren.size; i++)
          if (mChildren[i]->GetScreenRect().IsPointInside(point))
          {
            SetCapture(mChildren[i]);
            GetCapture()->OnPress(point);
            Redraw(*GetCapture());
            return;
          }
    }
    virtual void OnMove(const CPoint& point) override
    {
        CWnd* pCapture = GetCapture();
        if (pCapture)
        {
            pCapture->OnMove(point);
            // may release GetCapture pointer
            if (pCapture->NeedsRedraw())
                Redraw(*pCapture);
            if (!GetCapture())
                mDragStart = point;
            return;
        }
        ptRel = point - mDragStart;
        ptRel.x = 0;
    }
    virtual void OnRelease(const CPoint& point) override
    {
        if (GetCapture())
        {
            GetCapture()->OnRelease(point);
          Redraw(*GetCapture());
            SetCapture(nullptr);
            return;
        }
        ptCurrent = ptCurrent + ptRel;
        ptRel = {0, 0};
    }
};

class CApp
{
    CDemoForm mWnd;

public:
    void Init()
    {
        mWnd.Create();
    }
    void Do()
    {
        mWnd.Loop();
    }
  virtual void OnTouchBegin(const CPoint& point)
  {
          mWnd.OnPress(point);
  }
  virtual void OnTouchMove(const CPoint& point)
  {
          mWnd.OnMove(point);
  }
  virtual void OnTouchEnd(const CPoint& point)
  {
          mWnd.OnRelease(point);
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
