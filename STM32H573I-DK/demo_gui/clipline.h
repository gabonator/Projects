bool ClipLine(CPoint& p1, CPoint& p2, const CRect& viewport)
{
  enum {INSIDE, LEFT=1, RIGHT=2, BOTTOM=4, TOP=8};

  auto computeCode = [viewport](int x, int y) {
      int code = INSIDE;
      if (x < viewport.left)
          code |= LEFT;
      else if (x > viewport.right)
          code |= RIGHT;
      if (y < viewport.top)
          code |= BOTTOM;
      else if (y > viewport.bottom)
          code |= TOP;
      return code;
  };

  auto cohenSutherlandClip = [computeCode, viewport](int& x1, int& y1, int& x2, int& y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;
    while (true) {
        if (!(code1 | code2)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int codeOut = code1 ? code1 : code2;
            int x, y;
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (viewport.bottom - y1) / (y2 - y1);
                y = viewport.bottom;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (viewport.top - y1) / (y2 - y1);
                y = viewport.top;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (viewport.right - x1) / (x2 - x1);
                x = viewport.right;
            } else {
                y = y1 + (y2 - y1) * (viewport.left - x1) / (x2 - x1);
                x = viewport.left;
            }
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    return accept;
  };

  return cohenSutherlandClip(p1.x, p1.y, p2.x, p2.y);
};
