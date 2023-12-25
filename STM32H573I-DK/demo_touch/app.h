class CApp
{
  CPoint mTouchLast;
  struct CTimedPoint : CPoint {
    int32_t timestamp; 
    bool valid;
  };
  CArray<CTimedPoint, 100> mLine;
  CRect viewport;
public:
  virtual void Init()
  {
    CRect screen{0, 0, lcd::width, lcd::height};
    lcd::FillRect(screen, 0xff101010);
    viewport = screen;
    viewport.Deflate(16, 32, 16, 16);
    lcd::Rectangle(viewport, 0xff0000);
    viewport.Deflate(1, 1);
    lcd::SetFontSize(24);
    lcd::DrawText(CPoint{lcd::width/2 - lcd::GetTextExtent("Ahoj!").right/2, 0}, 0xffffff, 0x000000, "Ahoj!");
  }
  virtual void Do()
  {
    int32_t ts = sys::GetTick();
    auto Transform = [ts](const CTimedPoint& p)
    {
      int passed = ts - p.timestamp;
      return CPoint{
        (p.x - lcd::width/2)*(300+passed)/300 + lcd::width/2,
        (p.y - lcd::height/2)*(300+passed)/300 + lcd::height/2,
      };
    };

    while (mLine.size && ts - mLine[0].timestamp >= 2000)
    {
      mLine.shift();
    }
    lcd::FillRect(viewport, 0xff101010);
    CRect inner(viewport);
    inner.Deflate(0, 0, 1, 1);
    CTimedPoint prev{0, 0, 0, false};
    for (int i=0; i<mLine.size-1; i++)
    {
      if (!mLine[i].valid)
      {
        prev.valid = false;
        continue;
      }
      CTimedPoint transformed{Transform(mLine[i]), 0, true};
      if (prev.valid && transformed.valid)
      {
        if (ClipLine(prev, transformed, inner))
          lcd::DrawLine(prev, transformed, 0x00ff00);
        else
          transformed.valid = false;
      }
      prev = transformed;
    }
    sys::DelayMs(10);
  }
  virtual void OnTouchBegin(const CPoint& point)
  {
    mTouchLast = point;
  }
  virtual void OnTouchMove(const CPoint& point)
  {
    mTouchLast = point;
    if (mLine.size == mLine.capacity)
      mLine.shift();
    mLine.push({point, sys::GetTick(), true});
  }
  virtual void OnTouchEnd(const CPoint& point)
  {
    if (mLine.size == mLine.capacity)
      mLine.shift();
    mLine.push({point, sys::GetTick(), false});
  }
};
