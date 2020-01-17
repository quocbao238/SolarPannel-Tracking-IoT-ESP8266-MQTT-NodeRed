#ifndef SERVO_PROGRAM_H_H_
#define SERVO_PROGRAM_H_H_
#include "Program_Adaptor.h"

class Servo_Class: public Program_Adaptor_Class{
  public:
  Servo_Class(){};
  void setup();
  void loop();
};

extern Servo_Class Servo_Program;
extern boolean servo_enable;

/* Value */
extern  int avgtop;
extern  int avgbot;
extern  int avgleft;
extern  int avgright;

#endif
