#include "dht11_Program.h"
#include "Program_Gpio.h"
#include "dht_nonblocking.h"

DHT_nonblocking dht_sensor( DHT_PIN, DHT_SENSOR_TYPE );

enum{
  STATE_ON = 0,
  STATE_OFF,
  STATE_IDE
};

float temperature;
float humidity;
unsigned long measurement_timestamp = millis( );

void DHT_Class::setup(){

}


static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 3000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return( true );
    }
  }
  return( false );
}


void DHT_Class::loop(){
  if(ui_stateProgram == STATE_ON){
  
  if( measure_environment( &temperature, &humidity ) == true )
    {
      
    }

    ul_timeRepeat = 0;
    ui_stateProgram = STATE_OFF;
  }else if(ui_stateProgram == STATE_OFF){
    // temperature = read_temperature(); 
    ul_timeRepeat = 0;
    ui_stateProgram = STATE_ON;
  }else;
}



DHT_Class DHT_Program;
