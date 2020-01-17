#ifndef _PROGRAM_GPIO_H_H_  
#define _PROGRAM_GPIO_H_H_

#define LED_STATUS      (13)

#define SERVO_LR        (9) 
#define SERVO_BT        (10)

#define SENSOR_B     (A0)
#define SENSOR_T     (A1)
#define SENSOR_D     (A2)
#define SENSOR_N     (A3)       


//   valueSensorBotL = analogRead(SENSOR_B);
//   valueSensorTopR = analogRead(SENSOR_N);
//   valueSensorBotR = analogRead(SENSOR_D);
//   valueSensorTopL = analogRead(SENSOR_T);

#define RELAY_PIN         (12)
#define BUTTON_PIN        (2)
#define DHT_PIN            (11)
#define BUZZER_PIN        (5)

#define DHT_SENSOR_TYPE DHT_TYPE_11

#define ACTIVE          (HIGH)

/* 
Servo Config Servo Limite
*/
#define SERVO_LIMIT_HIGHT_LR    170   
#define SERVO_LIMIT_LOW_LR      30


#define SERVO_LIMIT_HIGHT_BT    140   
#define SERVO_LIMIT_LOW_BT      45

#define mySerial Serial

/* 
    Send Database
*/

#define APISEND_DEMO "INAVoltage=12.6,INACurrent=0.50,INAPower=6"

#endif