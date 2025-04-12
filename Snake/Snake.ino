#include <GameBoy.h>

GameBoy gb;
#define forward 3
#define left 4
#define right 5
#define backward 6

int dirX, dirY;
int XfoodX, YfoodY;
int snakeX[10];
int snakeY[10];
int x = 1;
int y = 0;

void setup()
{
  gb.begin(13);
  randomSeed(150);
  snakeX[0] = 4;
  snakeY[0] = 7;
  randFood();  // Corrected from randomFood() to randFood()
}

void loop()
{
  makeMove();
  dirX = dirX + x;
  dirY = dirY + y;
  if (dirY > 15)
  {
    dirY = 0;
  }
  if (dirX > 7)
  {
    dirX = 0;
  }
  if (dirY < 0)
  {
    dirY = 15;
  }
  if (dirX < 0)
  {
    dirX = 7;
  }

  // Corrected variable names to XfoodX and YfoodY
  if (collision(dirX, dirY, XfoodX, YfoodY)) {
    randFood();
  }

  gb.clearDisplay();
  gb.drawPoint(dirX, dirY);
  gb.drawPoint(XfoodX, YfoodY); // Corrected to XfoodX and YfoodY
  delay(300);
}

void makeMove()
{
  int key = gb.getKey();
  Serial.println(key);
  if (forward == key)
  {
    y--;
    x = 0;
  }
  if (left == key)
  {
    x--;
    y = 0;
  }
  if (right == key)
  {
    x++;
    y = 0;
  }
  if (backward == key)
  {
    y++;
    x = 0;
  }
}

bool collision(int dirX, int dirY, int XfoodX, int YfoodY)
{
  if (dirY == YfoodY && dirX == XfoodX)  // Fixed logic to match the variable names
  {
    return true;
  }
  else
  {
    return false;
  }
}

void randFood()
{
  XfoodX = random(0, 8);
  YfoodY = random(0, 16);
}
