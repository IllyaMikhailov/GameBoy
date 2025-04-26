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
unsigned int lenSnake = 2;
bool state;
int dirX, dirY;
int XfoodX, YfoodY;
int snakeX[15];
int snakeY[15];
int x = 1;
int y = 0;
int direction = dirRight;

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
  move();

  // Corrected variable names to XfoodX and YfoodY
  if (collision(snakeX[0], snakeY[0], XfoodX, YfoodY)) {
    lenSnake++;
    randFood();
  }

  gb.clearDisplay();
  drawSnake();
  drawFruit();
  delay(300);
}

void makeMove()
{
  int key = gb.getKey();
  Serial.println(key);
  if (btnUP == key && direction != dirDown)
  {

    direction = dirUP;
  }
  if (btnLeft == key && direction != dirRight)
  {

    direction = dirLeft;
  }
  if (btnRight == key && direction != dirLeft)
  {

    direction = dirRight;
  }
  if (btnDown == key && direction != dirUP)
  {

    direction = dirDown;
  }
}
void drawFruit() {
  state = !state;
  if ( state == true) {
    gb.drawPoint(XfoodX, YfoodY);
  }
  else {
    gb.wipePoint(XfoodX, YfoodY);
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
  if ((snakeX[0] == XfoodX) and (snakeY[0] == YfoodY)) {
    lenSnake++;
    randFood();
    gb.sound(SCORE);
  }
  for (int i = lenSnake - 1; i > 0; i--) {
    if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
      gb.sound(COLLISION);
    }
  }
  for (int i = lenSnake - 1; i > 0; i--) {
    snakeX[i] = snakeX[i - 1];
    snakeY[1] = snakeY[i - 1];
  }
  if (direction == dirUP) {
    if (snakeY[0] == 0) {
      snakeY[0] = 15;
    } else {
      snakeY[0]--;
    }
  } else if (direction == dirDown) {
    if (snakeY[0] == 15) {
      snakeY[0] = 0;
    } else {
      snakeY[0]++;
    }
  } else if (direction == dirLeft) {
    if (snakeX[0] == 0) {
      snakeX[0] = 7;
    } else {
      snakeX[0]--;
    }
  } else if (direction == dirRight) {
    if (snakeX[0] == 7) {
      snakeX[0] = 0;
    } else {
      snakeX[0]++;
    }
  }
}
void randFood() {
  XfoodX = random(0, 8);
  YfoodY = random(0, 16);
  while (isPartOfSnake(YfoodY, YfoodY)) {
    XfoodX = random(0, 8);
    YfoodY = random(0, 16);
  }
}
void drawSnake() {
  for (int i = 0; i < lenSnake; i++) {
    gb.drawPoint(snakeX[i], snakeY[i]);
  }
}
boolean isPartOfSnake(int x, int y) {
  for (int i = 0; i < lenSnake - 1; i++) {
    if ((x == snakeX[i]) && (y == snakeY[i])) {
      return true;
    }
  }
  return false;
}
