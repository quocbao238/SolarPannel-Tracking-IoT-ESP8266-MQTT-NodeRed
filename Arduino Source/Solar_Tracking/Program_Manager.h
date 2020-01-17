#ifndef _PROGRAME_MANAGER_H_H_
#define _PROGRAME_MANAGER_H_H_

#include "Program_Adaptor.h"

enum
{
  HELLO_WORLD_PROGRAM = 0,
  BLINK_PROGRAM,
  SENSOR_PROGRAM,
  SERVO_PROGRAM,
  INA219_PROGRAM,
  BUTTON_PROGRAM,
  BUZZER_PROGRAM,
  DHT_PROGRAM,
  LCD_PROGRAM,
      LAST_PROGRAM_ID
};

extern Program_Adaptor_Class * p_ListProgram[LAST_PROGRAM_ID];

extern void programManager_setup();
extern void programManager_loop();
#endif
