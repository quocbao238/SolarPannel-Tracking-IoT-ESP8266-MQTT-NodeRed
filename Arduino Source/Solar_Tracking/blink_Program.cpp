#include "blink_Program.h"
#include "Program_Gpio.h"

enum{
  STATE_ON = 0,
  STATE_OFF,
  STATE_IDE
};

void Blink_Class::setup(){
  pinMode(LED_STATUS,OUTPUT);

}

void Blink_Class::loop(){
  if(ui_stateProgram == STATE_ON){
    digitalWrite(LED_STATUS,ACTIVE);
    ul_timeRepeat = 100;
    ui_stateProgram = STATE_OFF;
  }else if(ui_stateProgram == STATE_OFF){
    digitalWrite(LED_STATUS,!ACTIVE);
    ul_timeRepeat = 3000;
    ui_stateProgram = STATE_ON;
  }else;
}

Blink_Class Blink_Program;
