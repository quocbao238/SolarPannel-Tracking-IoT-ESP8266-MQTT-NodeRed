#include "sensor_Program.h"
#include "Program_Gpio.h"

enum{
  STATE_READ = 0,
  STATE_NONE,
  STATE_IDE
};

int valueSensorBotL,valueSensorTopR,valueSensorBotR,valueSensorTopL;
unsigned long db_timeRead = 0;
unsigned long db_timeRepeat = 100;


void Sensor_Class::setup(){
  pinMode(SENSOR_B,INPUT);
  pinMode(SENSOR_D,INPUT);
  pinMode(SENSOR_N,INPUT);
  pinMode(SENSOR_T,INPUT);
}

void Sensor_Class::loop(){
  if(ui_stateProgram == STATE_READ){
    readValue();
    ul_timeRepeat = 0;
    ui_stateProgram = STATE_NONE;
  }else if(ui_stateProgram == STATE_NONE){
    // debugValue();
    ul_timeRepeat = 0;   
    ui_stateProgram = STATE_READ;
  }else;
}

void Sensor_Class::readValue(){
  valueSensorBotL = analogRead(SENSOR_B);
  valueSensorTopR = analogRead(SENSOR_N);
  valueSensorBotR = analogRead(SENSOR_D);
  valueSensorTopL = analogRead(SENSOR_T);
}

void Sensor_Class::debugValue(){
  Serial.println(
    "BotL: " + String(valueSensorBotL) +
    " - TopR: " + String(valueSensorTopR) +
    " - BotR: " + String(valueSensorBotR) + 
    " - TopL: " + String(valueSensorTopL)
  );
}


Sensor_Class Sensor_Program;
