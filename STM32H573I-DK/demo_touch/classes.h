template <typename T, int N>
class CArray 
{
public:
  T data[N];
  int size{0};
  const int capacity{N};

  T& operator [](int i)
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
  int Width()
  {
    return right - left;
  }
  int Height()
  {
    return bottom - top;
  }
};

struct CPoint
{
  int x, y;
};
