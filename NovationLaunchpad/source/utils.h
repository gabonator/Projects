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

CPRNG gRandom;

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

void strcpy(char *dst, const char *src)
{
  while((*dst++ = *src++) != 0);
}

int strlen(const char *str)
{
  const char *s;
  for (s = str; *s; ++s);
  return (s - str);
}

#if 1
extern "C" char* itoa(int value, char* result, int base) 
{
    if (base != 10) 
    { 
      *result = '\0'; 
      return result; 
    }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "0123456789" [tmp_value - value * 10];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}
#endif