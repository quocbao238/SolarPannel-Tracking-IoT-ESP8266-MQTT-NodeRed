#ifndef BUTTON_PROGRAM_H_H_
#define BUTTON_PROGRAM_H_H_
#include "Program_Adaptor.h"


class Button_Class: public Program_Adaptor_Class{
  public:
  Button_Class(){};
  void setup();
  void loop();
  // void readStatusButton();
};

extern Button_Class Button_Program;
extern int buttonState; 
extern int lastButtonState;   
extern boolean relayState ;
extern unsigned long lastDebounceTime;  
extern unsigned long debounceDelay; 
extern unsigned long lastbuzzerTime; 


#endif
