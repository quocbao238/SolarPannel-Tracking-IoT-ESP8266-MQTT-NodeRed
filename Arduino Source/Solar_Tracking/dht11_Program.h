#ifndef DHT_PROGRAM_H_H_
#define DHT_PROGRAM_H_H_
#include "Program_Adaptor.h"

class DHT_Class: public Program_Adaptor_Class{
  public:
  DHT_Class(){};
  void setup();
  void loop();
  // void measure_environment(float temperature,float humidity);
};

extern DHT_Class DHT_Program;

extern float temperature;
extern float humidity;

#endif
