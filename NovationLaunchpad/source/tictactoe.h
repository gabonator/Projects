#include <stdlib.h>

class CAppTictactoe : public CApp
{
  uint8_t game[8][8];
  int maxLine = 0;
public:

  virtual void enter() override
  {
    for (int y=0; y<8; y++)
      for (int x=0; x<8; x++)
        game[x][y] = 0;
  }

  virtual void onPress(int x, int y, int v) override
  {
    if (x>=0 && x<=7 && y >= 1 && y <= 8)
    {
      y--;
      if (game[x][y] != 0)
        return;
      game[x][y] = 'x';
      pixel(x, y+1) = 0xff0000;
      if (!checkWinner())
      {
        if (playAi(x, y, 'o'))
        {
          game[x][y] = 'o';
          pixel(x, y+1) = 0x0000ff;

          if (checkWinner())
          {
            for (int y=0; y<8; y++)
              for (int x=0; x<8; x++)
                if (pixel(x, y+1) == 0) 
                  pixel(x, y+1) = 0x00ff00;
            return;
          }
        }
      } else 
      {
        for (int y=0; y<8; y++)
          for (int x=0; x<8; x++)
            if (pixel(x, y+1) == 0) 
              pixel(x, y+1) = 0x00ffff;
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
    maxLine = max(aux, maxLine);
    return aux;
  }
  bool playAi(int &resx, int& resy, char id)
  {
    resx = -1;
    resy = -1;
    int bestScore = 0;
    for (int i=0; i<64; i++)
    {
      for (int j=i+1; j<64; j++)
      {
        int score = calcScore(i%8, i/8, j%8, j/8, id);
        if (score > bestScore)
        {
          resx = i%8;
          resy = i/8;
          bestScore = score;
        }
     }
    }
    return resx != -1;
  }
  char opposite(char c)
  {
    return c == 'o' ? 'x' : 'o';
  }
  bool checkTurn(int x, int y, char id)
  {
    game[x][y] = id;
    bool aux = checkWinner() != 0;
    game[x][y] = 0;
    return aux;
  }

  bool checkTurn(int x1, int y1, int x2, int y2, char id)
  {           
    game[x1][y1] = id;
    game[x2][y2] = id;
    bool aux = checkWinner() != 0;
    game[x1][y1] = 0;
    game[x2][y2] = 0;

    game[x1][y1] = id;
    game[x2][y2] = opposite(id);
    aux |= checkWinner() != 0;

    game[x1][y1] = opposite(id);
    game[x2][y2] = opposite(id);
    aux |= checkWinner() != 0;

    game[x1][y1] = id;
    game[x2][y2] = opposite(id);
    aux |= checkWinner() != 0;

    game[x1][y1] = 0;
    game[x2][y2] = 0;

    return aux;
  }
  int calcScore(int x1, int y1, int x2, int y2, char id)
  {                  
    if (game[x1][y1] || game[x2][y2])
      return 0;
    maxLine = 0;
    return checkTurn(x1, y1, x2, y2, id) ? 1000 : maxLine;
/*
    // winning turn?
    maxLine = 0;
    if (checkTurn(x1, y1, id))
      return 1000;
    if (checkTurn(x1, y1, x2, y2, id))
      return 100;
    int maxOurs = maxLine; 
    
    // opponent winning turn?
    maxLine = 0;
    if (checkTurn(x1, y1, opposite(id)))
      return 900;
    if (checkTurn(x1, y1, x2, y2, opposite(id)))
      return 90;
    int maxTheirs = maxLine; 

    return max(maxOurs+1, maxTheirs);
*/
  }
};
