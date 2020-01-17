#include "button_Program.h"
#include "Program_Gpio.h"
#include "buzzer_Program.h"
#include "OneButton.h"
#include "servo_Program.h"

enum{
  STATE_ON = 0,
  STATE_OFF,
  STATE_IDE
};



int checking = 0;      
int buttonState = LOW;      
int lastButtonState = LOW;   
boolean relayState = 0;
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;  
unsigned long lastTime =0;

OneButton myButton(BUTTON_PIN, true);

void oneClick();
void longCLick();
void duringlongClick();

void Button_Class::setup(){
  pinMode(RELAY_PIN,OUTPUT);
  myButton.attachClick(oneClick); 
  myButton.attachLongPressStop(longCLick);
  myButton.attachDuringLongPress(duringlongClick);

  // pinMode(BUTTON_PIN,INPUT_PULLUP);
}

void Button_Class::loop(){
  if(ui_stateProgram == STATE_ON){
      myButton.tick();
    // readStatusButton();
    ul_timeRepeat = 0;
    ui_stateProgram = STATE_OFF;
  }else if(ui_stateProgram == STATE_OFF){
    ul_timeRepeat = 0;
    ui_stateProgram = STATE_ON;
  }else;
}


void oneClick() {
  Bz_enable = true;
  digitalWrite(RELAY_PIN,!digitalRead(RELAY_PIN));
} 

void longCLick(){
  digitalWrite(BUZZER_PIN,!ACTIVE);
  servo_enable = !servo_enable;
}

void duringlongClick(){
  if(millis() - lastTime > 50){
    lastTime = millis();
    digitalWrite(BUZZER_PIN,!digitalRead(BUZZER_PIN));
  }
}

// void Button_Class::readStatusButton(){
//    checking = digitalRead(BUTTON_PIN);
//   if (checking != lastButtonState) {
//     lastDebounceTime = millis();
//   }
//   if ((millis() - lastDebounceTime) > debounceDelay) {
//     if (checking != buttonState) {
//       buttonState = checking;
//       if (buttonState == ACTIVE) {
//         relayState = !relayState;
//         Bz_enable = true;
//       }
//     }
//   }
//   digitalWrite(RELAY_PIN,relayState);
//   lastButtonState = checking;
// }


Button_Class Button_Program;

