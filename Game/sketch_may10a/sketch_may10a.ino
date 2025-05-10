#include <Blocks.h>
#include <GameBoy.h>
GameBoy gb;
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
void setup() {
gb.begin(13); 

}

void loop() {
mainMenu(); 
Car();
}
void mainMenu(){
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      gb.wipePoint(i,j);
      gb.setLed(i,j,ARROWS[j][i]);
    }
  }
}
void Car(){
   for (int i = 0; i < 8; i++){
    for (int j = 8; j < 16; j++){
      gb.wipePoint(i,j);
      gb.setLed(i,j,CAR[j-8][i]);
    }
  }
}
void Snake(){
  for (int i = 0; i < 8; i++){
    for (int j = 8; j < 16; j++){
      gb.wipePoint(i,j);
      gb.setLed(i,j,CAR[j-8][i]);
}
int modeSelector(){
  if (gb.getKey()==4){
    modeCount++;
    delay(250);
    if (modeCount > 1){
      modeCount = 0;
    }
  }
  else if (gb.getKey() == 5){
    modeCount--;
    delay(250);
    if (modeCount < 0){
      modeCount = 1;
    }
  }
  return modeCount;
}
