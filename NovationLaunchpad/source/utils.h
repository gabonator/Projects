#define assert(x)

class CPRNG
{
private:
  unsigned int nSeed;
  unsigned int nX;

public:
  CPRNG() : nSeed(5323), nX(0)
  {
  }
  void addEntropy(int s)
  {
    nSeed += s; 
  }
  unsigned int get()
  {
    nSeed = (8253729 * nSeed + 2396403);
    nSeed += nX++;
    return nSeed & 32767;
  }
};

CPRNG random;

template <typename T> T min(T a, T b)
{
  return a < b ? a : b;
}
template <typename T> T max(T a, T b)
{
  return a > b ? a : b;
}

template <typename T, int N>
class CArray 
{
public:
  T data[N];
  int count{0};
  T& operator [](int i)
  {
    assert(i>=0 && i<count);
    return data[i];
  }
  void push(const T& element)
  {
    assert(count < N-1);
    data[count++] = element;
  }
  const T& last()
  {
    assert(count > 0);
    return data[count-1];
  }
};
