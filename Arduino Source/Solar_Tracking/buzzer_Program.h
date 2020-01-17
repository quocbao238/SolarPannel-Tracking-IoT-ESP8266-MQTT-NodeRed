#ifndef BUZZER_PROGRAM_H_H_
#define BUZZER_PROGRAM_H_H_
#include "Program_Adaptor.h"

class Buzzer_Class: public Program_Adaptor_Class{
  public:
  Buzzer_Class(){};
  void setup();
  void loop();
};

extern Buzzer_Class Buzzer_Program;
extern boolean Bz_enable;

#endif
