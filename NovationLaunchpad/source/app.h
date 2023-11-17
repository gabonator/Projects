class CApp
{
public:
  enum class EApiCall {
    Name,
    Type,
    Width,
    Height,
    GetPixel,
    GetPosX,
    GetPosY
  };
  enum class EApiValue {
    TypeNone = 0,
    TypeStatic = 1,
    TypeDynamic = 2,
    TypeRowMenu = 0x10,
    TypeNavigation = 0x20,
    TypeArrows = 0x40
  };

public:
  const int32_t& ticks();
  uint32_t& pixel(int x, int y);
  const uint8_t& mode();
  int getTextWidth(const char* msg);
  void renderText(uint8_t* buffer, int x, int y, const char* msg);
  
  virtual void enter();
  virtual void leave();
  virtual void loop();
  virtual void onPress(int x, int y, int v);
  virtual void onRelease(int x, int y);
  virtual uintptr_t api(EApiCall e, int x, int y);
  void go(CApp& app);
};
