class CAppWater : public CApp
{
public:
  virtual void enter() override
  {
    WATERDEMO = 2;
  }
  virtual void leave() override
  {
    WATERDEMO = 0;
  }
};
