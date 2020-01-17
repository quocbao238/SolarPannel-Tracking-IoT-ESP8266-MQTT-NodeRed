#include "helloWorld_Program.h"
#include "Program_Gpio.h"
#include "sensor_Program.h"
#include "ina219_Program.h"
#include "dht11_Program.h"
enum{
  STATE_HELLO = 0,
  STATE_GOODBYE,
  STATE_IDE
};
void HelloWorld_Class::setup(){
    Serial.begin(115200);
  // while (!Serial) {
  // }
  // mySerial.begin(115200);
  // Serial.println("Setup Hello world"); 
}
void HelloWorld_Class::loop(){
  if(ui_stateProgram == STATE_HELLO){
    API_Send();
    ul_timeRepeat = 0;
    ui_stateProgram = STATE_GOODBYE;
  }else if(ui_stateProgram == STATE_GOODBYE){
    ul_timeRepeat = 3000;
    ui_stateProgram = STATE_HELLO;
  }else;
}

void HelloWorld_Class::API_Send(){
    if(busvoltage != 0 && current_mA != 0 && power_mW != 0 && temperature != 0 && humidity != 0)
    {
      Serial.println(
      "INAVoltage=" + String(busvoltage) + ","
      "INACurrent=" + String(current_mA) + ","
      "INAPower="   + String(power_mW) + ","
      "Temperature=" + String(temperature) + ","
      "Humidity=" + String(humidity) + ","
      );
    }
}


HelloWorld_Class HelloWorld_Program;
