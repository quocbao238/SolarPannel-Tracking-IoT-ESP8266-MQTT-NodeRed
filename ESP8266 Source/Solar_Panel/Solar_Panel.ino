#include "Program_gpio.h"

long lastMsg = 0;
char msg[50];
int value = 0;
int countdata = 0;
String strvoltage,strcurrent,strpower;
String strtemp,strhumi;
double voltage,current,power;
double temp,humi;
unsigned long lastTime = 0;
void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  while (!Serial) {
  }
  mySerial.begin(115200);
  setup_wifi();
}
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqttServer, 1883);
  client.setCallback(callback);
}
/* Ham call back nhan lai du lieu */
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message read [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println(topic);
  dataprocess(payload);
}

void dataprocess(byte* data){

}

void sentData(){
  if(countdata == 0){
  static char stc_voltage[7];
  dtostrf(voltage, 6, 2, stc_voltage);
  client.publish(ina_voltage, stc_voltage);
  countdata++;
  }else if(countdata == 1){
  static char stc_currnet[7];
  dtostrf(current, 6, 2, stc_currnet);
  client.publish(ina_current, stc_currnet);
  countdata++;
  }else if(countdata == 2){
  static char stc_power[7];
  dtostrf(power, 6, 2, stc_power);
  client.publish(ina_power, stc_power);
  countdata++;
  }else if(countdata == 3){
  static char stc_temp[7];
  dtostrf(temp, 6, 2, stc_temp);
  client.publish(solar_temp, stc_temp);
  countdata++;
  }else if(countdata == 4){
  static char stc_humi[7];
  dtostrf(humi, 6, 2, stc_humi);
  client.publish(solar_humi, stc_humi);
  countdata = 0;
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.publish(m_topic, "Reconnect");               // Gửi dữ liệu
      client.subscribe(m_topic);                          // Theo dõi dữ liệu
    } else {
      Serial.println("failed, rc=");
      Serial.print(client.state());
      // Doi 1s
      delay(1000);
    }
  }
}


void handlingdata(String datas)
{
   strvoltage = splitString(datas, "INAVoltage", "=", ",", 1);
   strcurrent = splitString(datas, "INACurrent", "=", ",", 1);
   strpower = splitString(datas, "INAPower", "=", ",", 1);
   strtemp = splitString(datas, "Temperature", "=", ",", 1);
   strhumi = splitString(datas, "Humidity", "=", ",", 1);
   humi = atof(strhumi.c_str());
   temp = atof(strtemp.c_str());
   voltage = atof(strvoltage.c_str());
   current = atof(strcurrent.c_str());
   power = atof(strpower.c_str());
   Serial.print("V: "+String(voltage) + " - C: " + String(current) + " - P: " + String(power));
   Serial.println("T: "+String(temp) + " - H: " + String(humi));
}

String splitString(String v_G_motherString, String v_G_Command, String v_G_Start_symbol, String v_G_Stop_symbol, unsigned char v_G_Offset)
{
  unsigned char tem_Offset = v_G_Offset - 1;
  unsigned char lenOfCommand = v_G_Command.length();

  int posOfCommand = v_G_motherString.indexOf(v_G_Command);
  int PosOfStartSymbol = v_G_motherString.indexOf(v_G_Start_symbol, posOfCommand + lenOfCommand);
  if (posOfCommand < 0)
    return "";

  // Xu ly Dau Command
  //  DB_SPLIT(v_G_Command + " posOfCommand " + (String)posOfCommand);
  if (posOfCommand > 0)
  {
    String tem__ = v_G_motherString.substring(posOfCommand - 1, posOfCommand);
    //    DB_SPLIT("posOfCommand at Start " + tem__);
    if ((tem__ != " ") && (tem__ != v_G_Stop_symbol))
    {
      return "";
    }
  }

  // Xu ly cuoi Command
  unsigned int temPosOfLastCommand = posOfCommand + lenOfCommand;
  if (temPosOfLastCommand)
  {
    String tem__ = v_G_motherString.substring(temPosOfLastCommand, temPosOfLastCommand + 1);
    //    DB_SPLIT("posOfCommand at Last " + tem__);
    if ((tem__ != " ") && (tem__ != v_G_Start_symbol))
    {
      return "";
    }
  }

  if (v_G_Offset == 0)
  {
    String tem__ = v_G_motherString.substring(posOfCommand, PosOfStartSymbol);
    if (tem__ == v_G_Command)
    {
      return tem__;
    }
    return "";
  }

  while (tem_Offset > 0)
  {
    tem_Offset--;
    PosOfStartSymbol = v_G_motherString.indexOf(v_G_Start_symbol, PosOfStartSymbol + 1);
  }

  if (v_G_Stop_symbol != "")
  {
    int PosOfStopSymbol = v_G_motherString.indexOf(v_G_Stop_symbol, PosOfStartSymbol + 1);
    if (PosOfStopSymbol == -1)
    {
      return "";
    }
    else
      ;
    return v_G_motherString.substring(PosOfStartSymbol + 1, PosOfStopSymbol);
  }
  else
  {
    return v_G_motherString.substring(PosOfStartSymbol + 1);
  }
}

void loop() { // run over and over

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (mySerial.available()) {
    String command = mySerial.readStringUntil('\n');
    Serial.println(command);
    handlingdata(command);
  }
  
  if(millis() - lastTime > 500){
    digitalWrite(2,!digitalRead(2));
    sentData();
    lastTime = millis();
  }

}
