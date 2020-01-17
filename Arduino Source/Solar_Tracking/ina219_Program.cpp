#include "ina219_Program.h"
#include "Program_Gpio.h"
#include "Adafruit_INA219.h"

enum{
  INASTATE_READ = 0,
  INASTATE_NONE,
  STATE_IDE
};

float shuntvoltage = 0;
float busvoltage = 0;
float current_mA = 0;
float loadvoltage = 0;
float power_mW = 0;
Adafruit_INA219 ina219;


void INA219_Class::setup(){
  ina219.begin();
}

void INA219_Class::loop(){
  if(ui_stateProgram == INASTATE_READ){
    INA219Read();
    ul_timeRepeat = 0;
    ui_stateProgram = INASTATE_NONE;
  }else if(ui_stateProgram == INASTATE_NONE){    
    ul_timeRepeat = 2000;   
    ui_stateProgram = INASTATE_READ;
  }else;
}

void INA219_Class::INA219Read(){
  // shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
}

void INA219_Class::INA219Debug(){
  Serial.print("Voltage: " + String(busvoltage) + " V - ");
  Serial.print("Current: " + String(current_mA) + " mA - ");
  Serial.print("Power: " + String(power_mW) + " mW");
  Serial.println("");
}



INA219_Class INA219_Program;
