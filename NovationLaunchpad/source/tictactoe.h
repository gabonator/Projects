#include <stdlib.h>

class CAppTictactoe : public CApp
{
  uint8_t game[8][8];
  char curPlayer;
  char winpl;
  int winbx, winby, windx, windy;

public:
  virtual void enter() override
  {
    for (int y=0; y<8; y++)
      for (int x=0; x<8; x++)
      {
        game[x][y] = 0;
        pixel(x, y+1) = 0;
      }

    curPlayer = 'x';
    winpl = 0;
  }

  int triangle(char player, int ofs)
  {
    int anim = (ofs + (ticks()>>2))&511;
    if (anim >= 256)
      anim = 511-anim;
    if (curPlayer == 'x')
      return anim << 16; // #xx0000
    else
      return anim; // #0000xx
  }

  virtual void loop() override
  {
    if (!winpl)
    {
      for (int i=0; i<9; i++)
        pixel(8, i) = triangle(curPlayer, i*20);
    } else 
    {
      for (int i=0; i<9; i++)
        pixel(8, i) = 0;
      for (int i=0; i<4; i++)
        pixel(winbx+windx*i, winby+windy*i+1) = triangle(curPlayer, i*10);
    }
  }

  virtual void onPress(int x, int y, int v) override
  {
    if (winpl)
    {
      appTransition.chain(this);
      go(appTransition);
      return;
    }
    if (x>=0 && x<=7 && y >= 1 && y <= 8)
    {
      y--;
      if (game[x][y] != 0)
        return;
      game[x][y] = curPlayer;
      pixel(x, y+1) = curPlayer == 'x' ? 0xff0000 : 0x0000ff;
      if (!checkWinner())
      {
        curPlayer = curPlayer == 'x' ? 'o' : 'x';
      } else 
      {
        // game done
        return;
      }
    }
  }
  char checkWinner()
  {
    for (int y=0; y<8; y++)
      for (int x=0; x<8; x++)
      {
        if (checkLine(x, y, 0, 1, 'o') == 4 ||
            checkLine(x, y, 1, 0, 'o') == 4 ||
            checkLine(x, y, 1, 1, 'o') == 4 ||
            checkLine(x+3, y, -1, 1, 'o') == 4)
          return 'o';
        if (checkLine(x, y, 0, 1, 'x') == 4 ||
            checkLine(x, y, 1, 0, 'x') == 4 ||
            checkLine(x, y, 1, 1, 'x') == 4 ||
            checkLine(x+3, y, -1, 1, 'x') == 4)
          return 'x';
      }
    return 0;
  }
  int checkLine(int bx, int by, int dx, int dy, char c)
  {
    int aux = 0;
    char op = opposite(c);
    winbx = bx;
    winby = by;
    windx = dx;
    windy = dy;
    for (int i=0; i<4; i++)
    {
      if (bx >= 0 && by >= 0 && bx < 8 && by < 8)
      {
        if (game[bx][by] == c)
          aux++;
        if (game[bx][by] == op)
          return 0;
      }
      bx += dx;
      by += dy;
    }
    if (aux == 4)
      winpl = c;
    return aux;
  }
  char opposite(char c)
  {
    return c == 'o' ? 'x' : 'o';
  }
};
