#include "lcd_Program.h"
#include "Program_Gpio.h"
#include "Wire.h"
#include "LiquidCrystal_I2C.h"
#include "ina219_Program.h"
#include "dht11_Program.h"
LiquidCrystal_I2C lcd(0x27,16,2);

enum{
  STATE_ON = 0,
  STATE_OFF,
  STATE_IDE
};

void LCD_Class::setup(){
  lcd.init();
  lcd.backlight();
}

void LCD_Class::loop(){
  if(ui_stateProgram == STATE_ON){
    lcd.clear();
    lcd.setCursor(0,0);lcd.print("INA219 Vol:" + String(busvoltage));
    lcd.setCursor(9,1);lcd.print("A:" + String(current_mA));
    lcd.setCursor(0,1);lcd.print("P:" + String(power_mW));
    ul_timeRepeat = 2000;
    ui_stateProgram = STATE_OFF;
  }else if(ui_stateProgram == STATE_OFF){
    lcd.clear();
    lcd.setCursor(2,0); lcd.print("Solar Pannel");
    lcd.setCursor(0,1);lcd.print(temperature);lcd.print(char(223));lcd.print("C");
    lcd.setCursor(10,1);lcd.print(humidity);lcd.setCursor(15,1);lcd.print("%");
    ul_timeRepeat = 2000;
    ui_stateProgram = STATE_ON;
  }else;
}

LCD_Class LCD_Program;
