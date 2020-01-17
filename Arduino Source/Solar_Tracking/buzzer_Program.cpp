#include "buzzer_Program.h"
#include "Program_Gpio.h"

enum{
  STATE_ON = 0,
  STATE_OFF,
  STATE_IDE
};

boolean Bz_enable;

void Buzzer_Class::setup(){
  pinMode(BUZZER_PIN,OUTPUT);
  Bz_enable = false;
}

void Buzzer_Class::loop(){
  if(Bz_enable == true){
    if(ui_stateProgram == STATE_ON){
      digitalWrite(BUZZER_PIN,HIGH);
      ul_timeRepeat = 50;
      ui_stateProgram = STATE_OFF;
    }else if(ui_stateProgram == STATE_OFF){
      digitalWrite(BUZZER_PIN,LOW);
      ul_timeRepeat = 0;
      Bz_enable = false;
      ui_stateProgram = STATE_ON;
    }else;
  }
}
Buzzer_Class Buzzer_Program;
