#include "renderer.h"

class CWnd;

class CPresenter
{
public:
    virtual void Push(CWnd* pWnd) = 0;
    virtual void Pop() = 0;
};

class CWnd
{
protected:
  mutable CRect mScreen;
protected:
  mutable CWnd* mParent;
    static CWnd* mCapture;
    CWnd* mFirst{nullptr};
    CWnd* mNext{nullptr};
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

    virtual void OnShow() {}
    virtual void OnHide() {}
    //virtual void Create(CPresenter* p) {}
    virtual void Loop() {}
    CWnd* GetCapture() { return mCapture; }
    void SetCapture(CWnd* p) { mCapture = p; }
    void Invalidate() { mNeedRedraw = true; };
    bool NeedsRedraw() { if (!mNeedRedraw) return false; mNeedRedraw = false; return true; }
    CWnd* GetLast()
    {
        CWnd *p = mFirst;
        while (p && p->mNext)
            p = p->mNext;
        return p;
    }
    void Create(CWnd* parent)
    {
        mParent = parent;
        assert(mParent);
        if (!mParent->GetLast())
            mParent->mFirst = this;
        else
            mParent->GetLast()->mNext = this;
    }
    void ForEach(std::function<void(CWnd*)> f)
    {
        CWnd* p = mFirst;
        while (p)
        {
            f(p);
            p = p->mNext;
        }
    }

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

class CTextArea : public CWnd
{
    char* mText;
    int mRows{0};
    int mCols{0};
    
public:
    CTextArea() = default;
    CTextArea(char* text, int cols, int rows)
  {
        mText = text;
        mRows = rows;
        mCols = cols;
  }
  virtual CRect GetExtent(CRenderer& r) const override
  {
      return {0, 0, mCols*8, mRows*14};
  }

  virtual void Render(CRenderer& r) const override
  {
    r.Clear(0x202020);
      char *c = mText;
      for (int y=0; y<mRows; y++)
          for (int x=0; x<mCols; x++)
              r.DrawFixedChar(x*8, y*14, *c++, 0xb0b0b0, 0x202020);
  }

  virtual void OnPress(const CPoint& p) override
  {
      SetCapture(nullptr);
  }
};

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
    void Create(CWnd* parent, const CArray<const char*>& items, int selected)
    {
        CWnd::Create(parent);
        mItems = items;
        mCurrent = selected;
    }
    
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
    CPoint mAnchor{0, 0};
    CRect mClip{0, 0, 0, 0};
    CPoint mPoint{0, 0};
  int mMaxHeight{0};

public:
  enum LayoutControl_t {
    Nl = 1,
    Pad = 2
  };

public:
    CLayout() : mClip{0, 0, 0, 1024}
    {
        // used for layout height calculation
    }
    
  CLayout(CPoint anchor, CRect clip) : mAnchor(anchor), mClip(clip), mPoint{anchor}, mMaxHeight{0}
  {
    if (anchor.y > clip.top)
        lcd::FillRect({clip.left, clip.top, clip.right, anchor.y}, 0x202020);
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
      CRect padLeft{0, mPoint.y, mAnchor.x, mPoint.y + mMaxHeight};
        if (padLeft.ClipTo(mClip))
      lcd::FillRect(padLeft, 0x202020);
        mPoint.x = mAnchor.x;
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

class CForm : public CWnd
{
protected:
    CRenderer mRender;

public:
    CPoint mDragStart;
    CPoint mDragVector{0, 0};
    CPoint ptCurrent{0, 0};
    CRect mInner{0, 0, 0, 0};

    void Create(const CRect& inner)
    {
        mInner = inner;
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
        mDragVector = {0, 0};
        ForEach([&](CWnd* child){
            if (child->GetScreenRect().IsPointInside(point))
            {
              SetCapture(child);
              GetCapture()->OnPress(point);
              Redraw(*GetCapture());
              return;
            }
        });
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
        mDragVector = point - mDragStart;
        mDragVector.x = 0;
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
        ptCurrent = ptCurrent + mDragVector;
        mDragVector = {0, 0};
    }
    void Redraw(const CWnd& w)
    {
        assert(mInner.Width());
      const CRect rc = w.GetExtent(mRender);
      CRect screen = w.GetScreenRect();
        CPoint anchor = {screen.left, screen.top};
        if (screen.ClipTo(mInner))
        {
            mRender.Viewport(rc);
            w.Render(mRender);
            mRender.Blit(anchor, screen);
        }
    }
    CRect DrawFrame(const CRect& rc, const char* title)
    {
        mRender.Viewport({rc.left, rc.top, rc.right, rc.top + 64});
        mRender.FillRect({rc.left, rc.top, rc.right, rc.top + 64}, 0x202020);
        mRender.RoundRectangle({rc.left, rc.top, rc.right, rc.top+64}, 4, 0x808080);
        mRender.RoundRectangle({rc.left+2, rc.top+20, rc.right-2, rc.top+64-2}, 4, 0x202020);
        mRender.SetFont(fonts::arial15b);
        mRender.DrawText({rc.left+6, rc.top+6}, 0xffffff, 0x808080, title);
        mRender.Blit({rc.left, rc.top}, {rc.left, rc.top, rc.right, rc.top+24});
        for (int i=rc.top+24; i<rc.bottom-6; i+=32)
            mRender.Blit({rc.left, i-24}, CRect{rc.left, i, rc.right, std::min(rc.bottom-6, i+32)});
        mRender.Blit({rc.left, rc.bottom-64}, CRect{rc.left, rc.bottom-6, rc.right, rc.bottom});

        CRect inner = rc;
        inner.Deflate(6, 20, 6, 3);
        return inner;
    }
};
