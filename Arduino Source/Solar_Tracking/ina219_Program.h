#ifndef INA219_PROGRAM_H_H_
#define INA219_PROGRAM_H_H_
#include "Program_Adaptor.h"

class INA219_Class: public Program_Adaptor_Class{
  public:
  INA219_Class(){};
  void setup();
  void loop();
  void INA219Read();
  void INA219Debug();
};

extern INA219_Class INA219_Program;

extern float shuntvoltage;
extern float busvoltage;
extern float current_mA;
extern float loadvoltage;
extern float power_mW;

#endif
