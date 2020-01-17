#ifndef SENSOR_PROGRAM_H_H_
#define SENSOR_PROGRAM_H_H_
#include "Program_Adaptor.h"

class Sensor_Class: public Program_Adaptor_Class{
  public:
  Sensor_Class(){};
  void setup();
  void loop();
  void readValue();
  void debugValue();
};

extern Sensor_Class Sensor_Program;

extern int valueSensorBotL;
extern int valueSensorTopR;
extern int valueSensorBotR;
extern int valueSensorTopL;
extern unsigned long db_timeRead;
extern unsigned long db_timeRepeat;


#endif
