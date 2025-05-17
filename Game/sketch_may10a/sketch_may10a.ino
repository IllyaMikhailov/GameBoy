#include <Blocks.h>
#include <GameBoy.h>
GameBoy gb;
void mainRacing();
void mainSnake();
int mode;
byte ARROWS[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 0, 0, 1, 1, 1},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};
byte CAR[8][8] = {
  {0, 1, 0, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 1, 0}
};
byte SNAKE[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 1, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0}
};
int modeCount;
void setup() {
  gb.begin(13);
}
void loop() {
  mainMenu();
  if (gb.getKey() == 2 && modeSelector() == 0){
    gb.clearDisplay();
    mode = 1;
  }
  else if (gb.getKey() == 2 && modeSelector() == 1){
    gb.clearDisplay();
    mode = 2;
  }
   else if (gb.getKey() == 1){
    gb.clearDisplay();
    mode = 0;
   }
   switchMode(mode);
}
void mainMenu() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      gb.wipePoint(i, j);
      gb.setLed(i, j, ARROWS[j][i]);
    }
  }
  if (modeSelector() == 1) {
    for (int i = 0; i < 8; i++) {
      for (int j = 8; j < 16; j++) {
        gb.wipePoint(i, j);
        gb.setLed(i, j, CAR[j - 8][i]);
      }
    }
  }
  if (modeSelector() == 1) {
    for (int i = 0; i < 8; i++) {
      for (int j = 8; j < 16; j++) {
        gb.wipePoint(i, j);
        gb.setLed(i, j, SNAKE[j - 8][i]);
      }
    }
  }
}
int modeSelector() {
  if (gb.getKey() == 4) {
    modeCount++;
    delay(250);
    if (modeCount > 1) {
      modeCount = 0;
    }
  }
  else if (gb.getKey() == 5) {
    modeCount--;
    delay(250);
    if (modeCount < 0) {
      modeCount = 1;
    }
  }
  return modeCount;
}
void switchMode(int mode){
  switch(mode){
    case 0:mainMenu();
    break;
    case 1:mainRacing();
    break;
    case 2:mainSnake();
    break;
  }
}
void mainRacing(){
  //code
}
void mainSnake(){
  //code
}
