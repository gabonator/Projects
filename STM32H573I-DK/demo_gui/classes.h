template <typename T>
class CArray
{
public:
    T* data{nullptr};
    int capacity{0};
  int size{0};
    CArray() = default;
    CArray(T* _data, int _capacity, int _size = 0) : data{_data}, capacity{_capacity}, size{_size}
    {
    }
    void operator =(const CArray& o)
    {
        data = o.data;
        capacity = o.capacity;
        size = o.size;
    }
  T& operator [](int i)
  {
    assert(i>=0 && i<size);
    return data[i];
  }
    const T& operator [](int i) const
    {
      assert(i>=0 && i<size);
      return data[i];
    }
  void push(const T& element)
  {
    assert(size < capacity);
    data[size++] = element;
  }
  T shift()
  {
    assert(size > 0);
    T temp = data[0];
    for (int i=0; i<size-1; i++)
      data[i] = data[i+1];
    size--;
    return temp;
  }
  const T& last()
  {
    assert(size > 0);
    return data[size-1];
  }
};

struct CPoint
{
  int x, y;
  bool operator ==(const CPoint& p)
  {
    return x == p.x && y == p.y;
  }
  bool operator !=(const CPoint& p)
  {
    return x != p.x || y != p.y;
  }
  CPoint operator+ (const CPoint& p) const
  {
    return CPoint{x + p.x, y + p.y};
  }
    CPoint operator- (const CPoint& p) const
    {
      return CPoint{x - p.x, y - p.y};
    }
};

struct CRect
{
  int left, top, right, bottom;
  void Deflate(int x, int y)
  {
    left += x;
    top += y;
    right -= x;
    bottom -= y;
  }
  void Deflate(int l, int t, int r, int b)
  {
    left += l;
    top += t;
    right -= r;
    bottom -= b;
  }
  void Inflate(int x, int y)
  {
    left -= x;
    top -= y;
    right += x;
    bottom += y;
  }
  void Offset(int x, int y)
  {
    left += x;
    top += y;
    right += x;
    bottom += y;
  }
  int Width() const
  {
    return right - left;
  }
  int Height() const
  {
    return bottom - top;
  }
  bool IsPointInside(const CPoint& p) const
  {
    return p.x >= left && p.y >= top && p.x < right && p.y < bottom;
  }
  CPoint TopLeft()
  {
    return {left, top};
  }
  bool Intersects(const CRect& r)
  {
    if (left > r.right ||
        right < r.left ||
        top > r.bottom ||
        bottom < r.top)
      return false;
    else
      return true;
  }
    bool ClipTo(const CRect& rc)
    {
        left = std::max(left, rc.left);
        right = std::min(right, rc.right);
        top = std::max(top, rc.top);
        bottom = std::min(bottom, rc.bottom);
        return right > left && bottom > top;
    }
    CRect operator +(const CPoint& p)
    {
        return {left + p.x, top + p.y, right + p.x, bottom + p.y};
    }
};
