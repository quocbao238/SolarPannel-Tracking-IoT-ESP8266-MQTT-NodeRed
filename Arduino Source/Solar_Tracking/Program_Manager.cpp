#include "Program_Manager.h"

/* Khai bao thu vien */
#include "helloWorld_Program.h"
#include "blink_Program.h"
#include "sensor_Program.h"
#include "servo_Program.h"
#include "ina219_Program.h"
#include "button_Program.h"
#include "buzzer_Program.h"
#include "dht11_Program.h"
#include "lcd_Program.h"
/* 
List STATE
*/
Program_Adaptor_Class *p_ListProgram[LAST_PROGRAM_ID] = {
    &HelloWorld_Program,
    &Blink_Program,
    &Sensor_Program,
    &Servo_Program,
    &INA219_Program,
    &Buzzer_Program,
    &Button_Program,
    &DHT_Program,
    &LCD_Program,
  
};

void programManager_setup(){
  for(int cf = 0; cf < LAST_PROGRAM_ID; cf++){
      p_ListProgram[cf]->setup();
      
  }
}

void programManager_loop(){
  ul_currentMililis = millis();
  for(int cf = 0; cf < LAST_PROGRAM_ID; cf++){
    if(ul_currentMililis - p_ListProgram[cf]->ul_lastMillis >= p_ListProgram[cf]->ul_timeRepeat){
      p_ListProgram[cf]->ul_lastMillis = ul_currentMililis;
      p_ListProgram[cf]->loop();
    }
  }
}
