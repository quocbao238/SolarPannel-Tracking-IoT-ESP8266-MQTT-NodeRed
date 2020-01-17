#include "servo_Program.h"
#include "Program_Gpio.h"
#include "Servo.h"
#include "sensor_Program.h"

enum{
  STATE_SV_RUN = 0,
  STATE_SV_AVG1,
  STATE_SV_AVG2,
  STATE_SV_NONE,
  STATE_IDE
};


/* Construc tor */
Servo servoLR;
Servo servoBT;

/* Value */
  int avgtop;
  int avgbot;
  int avgleft;
  int avgright;
  int servoh;
  int servov;
boolean servo_enable = false;

void Servo_Class::setup(){
  servoLR.attach(SERVO_LR);
  servoBT.attach(SERVO_BT);
  servoLR.write(90);
  servoBT.write(90); 
}

void Servo_Class::loop(){
if(servo_enable == true){  
    if(ui_stateProgram == STATE_SV_RUN){
    servoh = servoLR.read();
    servov = servoBT.read();
    avgtop = (valueSensorTopL + valueSensorTopR) ; 
    avgbot = (valueSensorBotL + valueSensorBotR) ; 
    avgleft = (valueSensorTopL + valueSensorBotL) ; 
    avgright = (valueSensorTopR + valueSensorBotR) ;
    /* Debug
      Serial.println(
      "avgtop: " + String(avgtop) +
      " - avgbot: " + String(avgbot) +
      " - avgleft: " + String(avgleft) + 
      " - avgright: " + String(avgright) +
      " - ServoLR: " + String(servoh) +
      " - ServoBT: " + String(servov)
    );
    */
    ul_timeRepeat = 0 ;
    ui_stateProgram = STATE_SV_AVG1;
    }
    else if(ui_stateProgram == STATE_SV_AVG1){
        if (avgbot > avgtop && avgbot - avgtop > 50)
        { 
          if (servov < SERVO_LIMIT_HIGHT_BT) 
          { 
            servoBT.write(servov +1);
          }
          ul_timeRepeat = 10;
        }
        else if (avgtop > avgbot && avgtop - avgbot > 50)
        {
          if (servov > SERVO_LIMIT_LOW_BT)
          {
            servoBT.write(servov -1);
          }
          ul_timeRepeat = 10;
        }
        else 
        {
          servoBT.write(servov);
        }
    ul_timeRepeat =50;
    ui_stateProgram = STATE_SV_AVG2;
    }else if(ui_stateProgram == STATE_SV_AVG2){
  /* 
        avgleft < avgright --> servo tien +
        avgright > avgright ---> servo lui -
        avgright == avgright ---> server dung yen
    */
      if (avgleft > avgright && avgleft - avgright > 50 )
      {

        if (servoh < SERVO_LIMIT_HIGHT_LR)
        {
          servoLR.write(servoh +1);
        }
        ul_timeRepeat = 10;
      }
      else if (avgright > avgleft && avgright - avgleft > 50 )
      {
        if (servoh > SERVO_LIMIT_LOW_LR)
        {
        servoLR.write(servoh -1);
        }
        ul_timeRepeat = 10;
      }
      else 
      {
        servoLR.write(servoh);
      }
      ul_timeRepeat = 50;
      ui_stateProgram = STATE_SV_RUN;
    }else;
  }
}

Servo_Class Servo_Program;
