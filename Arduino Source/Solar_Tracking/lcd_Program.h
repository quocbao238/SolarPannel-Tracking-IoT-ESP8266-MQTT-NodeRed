#ifndef LCD_PROGRAM_H_H_
#define LCD_PROGRAM_H_H_
#include "Program_Adaptor.h"

class LCD_Class: public Program_Adaptor_Class{
  public:
  LCD_Class(){};
  void setup();
  void loop();
};

extern LCD_Class LCD_Program;

#endif
