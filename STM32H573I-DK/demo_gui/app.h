#include "engine.h"

class CModalForm : public CForm
{
    CPresenter* mPresenter{nullptr};
    CWndButton mBtnOk;
    CWndButton mBtnCancel;
    CRenderer mRender;

public:
    void Layout(CLayout& visitor)
    {
        auto onOk = [&]() {
            mPresenter->Pop();
        };
        auto onCancel = [&]() {
            mPresenter->Pop();
        };

        visitor
          << CWndSpacer(0, 8) << CLayout::Nl
          << CWndStatic("This is a modal window") << CLayout::Nl
            << mBtnOk("Ok", CWndButton::Primary, onOk) << mBtnCancel("Cancel", CWndButton::Secondary, onCancel) << CLayout::Nl << CLayout::Pad;
    }
        
    void Create(CWnd* parent, CPresenter* presenter, CRect screen)
    {
        mScreen = screen;
        mPresenter = presenter;
        if (parent)
            CWnd::Create(parent);
        mBtnOk.Create(this);
        mBtnCancel.Create(this);
    }
    
    void OnShow() override
    {
        CForm::Create(DrawFrame(mScreen, "Modal test"));
        CLayout layout(mInner.TopLeft(), mInner);
        Layout(layout);
    }
};

class CDemoForm : public CForm
{
    CPoint mTouchLast;
    CRect viewport;
    CPoint ptLast{-1, 0};
    CPoint mAnchor{0, 0};
    
    CWndStatic mStatic;
    CWndButton mBtnOk;
    CWndButton mBtnCancel;
    CWndCheckbox mBtnCheck1;
    CWndCheckbox mBtnCheck2;
    CWndCheckbox mBtnCheck3;
    CWndCheckbox mBtnCheck4;
    CWndRadio mBtnRadio;
    
    int mTotalHeight{0};
    CPresenter* mPresenter{nullptr};
    CModalForm mFormModal;
    
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
        auto onModal = [&]() {
            mPresenter->Push(&mFormModal);
        };

        visitor << CWndSpacer(0, 4) << CLayout::Nl
          << CWndTitle("Demo form") << CLayout::Nl
          << CWndStatic("Hello this is a static message,") << CLayout::Nl
          << CWndStatic("second line goes here!") << CLayout::Nl
          << mStatic << CLayout::Nl
        << mBtnOk("Open modal", CWndButton::Primary, onModal) << CLayout::Nl
          //<< mBtnOk("Ok", CWndButton::Primary, onOk) << CWndSpacer(20) << mBtnCancel("Cancel", CWndButton::Secondary, onCancel) << CLayout::Nl
        << mBtnCheck1("LED 1", [&](){ onLed(1, mBtnCheck1.Toggle()); CForm::Redraw(mBtnCheck1); })
          << mBtnCheck2("LED 2", [&](){ onLed(2, mBtnCheck2.Toggle()); CForm::Redraw(mBtnCheck2); }) << CLayout::Nl
          << mBtnCheck3("LED 3", [&](){ onLed(3, mBtnCheck3.Toggle()); CForm::Redraw(mBtnCheck3); })
          << mBtnCheck4("LED 4", [&](){ onLed(4, mBtnCheck4.Toggle()); CForm::Redraw(mBtnCheck4); }) << CLayout::Nl
          << CWndStatic("Uart baudrate") << CLayout::Nl
          << mBtnRadio << CLayout::Nl
          << CWndSpacer(0, 30) << CLayout::Nl
          << CLayout::Pad;
    }
    
    void Redraw()
    {
        CLayout layout(mInner.TopLeft() + mAnchor, mInner);
        Layout(layout);
    }
    virtual void Create(CWnd* parent, CPresenter* presenter, const CRect& client)
    {
        mScreen = client;
        if (parent)
            CWnd::Create(parent);
        mBtnOk.Create(this);
        mBtnCancel.Create(this);
        mBtnCheck1.Create(this);
        mBtnCheck2.Create(this);
        mBtnCheck3.Create(this);
        mBtnCheck4.Create(this);
        mPresenter = presenter;
        
        static const char* radioValues[] = {"2400", "4800", "9600", "19600", "38400", "57600", "115200"};
        mBtnRadio.Create(this, {radioValues, std::size(radioValues), std::size(radioValues)}, 3);
        
        CLayout layout;
        Layout(layout);
        mTotalHeight = layout.Height();
        
        mFormModal.Create(nullptr, presenter, {20, 60, lcd::width-20, lcd::height-60});
    }
    void OnShow() override
    {
        CForm::Create(DrawFrame(mScreen, "Main window"));
        ptLast.x = -1;
    }
    virtual void Loop() override
    {
        if (mDragVector == CPoint{0, 0})
        {
            if (ptCurrent.y > 0)
                ptCurrent.y = (ptCurrent.y + 0)/2;
            if (mTotalHeight > lcd::height && ptCurrent.y < -(mTotalHeight - lcd::height))
                ptCurrent.y = (ptCurrent.y - (mTotalHeight - lcd::height))/2;
        }
      if (ptLast != ptCurrent + mDragVector)
      {
        ptLast = ptCurrent + mDragVector;
          mAnchor = ptLast;
        Redraw();
      }
    }
};

class CApp : public CPresenter
{
    CWnd* mWnd{nullptr};
    CDemoForm mMain;
    CWnd* mStackData[10];
    CArray<CWnd*> mStack;

public:
    void Init()
    {
        mMain.Create(nullptr, this, {0, 0, lcd::width, lcd::height});

        mStack = {mStackData, (int)std::size(mStackData)};
        mStack.push(&mMain);
    }
    void Do()
    {
        if (mWnd != mStack.last())
        {
            if (mWnd)
                mWnd->OnHide();
            mWnd = mStack.last();
            assert(mWnd);
            mWnd->OnShow();
        }
        mWnd->Loop();
    }
  virtual void OnTouchBegin(const CPoint& point)
  {
          mWnd->OnPress(point);
  }
  virtual void OnTouchMove(const CPoint& point)
  {
          mWnd->OnMove(point);
  }
  virtual void OnTouchEnd(const CPoint& point)
  {
          mWnd->OnRelease(point);
  }
    virtual void Push(CWnd* pWnd) override
    {
        mStack.push(pWnd);
    }
    virtual void Pop() override
    {
        assert(mStack.size > 0);
        mStack.pop();
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
