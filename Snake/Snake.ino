#include <GameBoy.h>

GameBoy gb;

#define btnUP 3
#define btnLeft 4
#define btnRight 5
#define btnDown 6

#define dirUP 0
#define dirRight 1
#define dirLeft 2
#define dirDown 3

int dirX, dirY;
int XfoodX, YfoodY;
int snakeX[10];
int snakeY[10];
int x = 1;
int y = 0;
int direction = dirRight;
int lenSnake = 5;
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
  if (btnUP == key)
  {
    y--;
    x = 0;
    direction = dirUP;
  }
  if (btnLeft == key)
  {
    x--;
    y = 0;
    direction = dirLeft;
  }
  if (btnRight == key)
  {
    x++;
    y = 0;
    direction = dirRight;
  }
  if (btnDown == key)
  {
    y++;
    x = 0;
    direction = dirDown;
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
void move() {
  for (int i = lenSnake - 1; i > 0; i--) {
snakeX[i] = snakeX[i - 1];
snakeY[1] = snakeY[i - 1];
  }
  if(direction == dirUP){
    if(snakeY[0] == 0){
      snakeY[0] = 15;
    }else{
      snakeY[0]--;
    }
  }else if(direction == dirDown){
    if(snakeY[0] == 15){
      snakeY[0] = 0;
    }else{
      snakeY[0]++;
    }
  }else if (direction == dirLeft){
    if (snakeX[0] == 0){
      snakeX[0] = 7;
    }else{
      snakeX[0]--;
    }
  }else if(direction == dirRight){
    if(snakeX[0] == 7){
      snakeX[0] = 0;
    }else{
      snakeX[0]++;
    }
  }
}
void randFood()
{
  XfoodX = random(0, 8);
  YfoodY = random(0, 16);
}
