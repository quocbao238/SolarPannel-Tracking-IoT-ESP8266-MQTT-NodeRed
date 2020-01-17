#include "ESP8266WiFi.h"
#include "PubSubClient.h"
const char* ssid = "MakerLabVN"; // Nhập tên WiFi 
const char* password = "makerlab03050709"; // Nhập Mật khẩu WiFi 
const char* mqttServer = "192.168.10.130"; // Nhập địa chỉ của server MQTT
String clientId = "SolarPannel";            // Client ID của mạch
const char* m_topic = "SolarPannel";   



const char* solar_temp = "Maker_Solar/Temperature"; // Topic của Sensor đọc độ ẩm
const char* solar_humi = "Maker_Solar/Humidity"; // Topic của Sensor đọc nhiet do
const char* ina_voltage = "Maker_INA/voltage"; // Topic của Sensor đọc độ ẩm
const char* ina_current = "Maker_INA/current"; // Topic của Sensor đọc nhiet do
const char* ina_power = "Maker_INA/power"; // Topic của Sensor


WiFiClient espClient;
PubSubClient client(espClient);


#define APISEND_DEMO "INAVoltage=9.05,INACurrent=-0.40,INAPower=4.00,Temperature=32.00,Humidity=64.00,"
#define mySerial Serial

extern int countdata;