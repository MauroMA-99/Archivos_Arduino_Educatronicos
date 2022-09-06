#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(34, 16, 2); 

void setup()
{ 
  //lcd.begin(9600);
  lcd.init(); 
  lcd.backlight();
} 

void loop()
{ 
  lcd.setCursor(0,0); 
  lcd.print("Educatronicos"); 
  lcd.setCursor(0,1); 
  lcd.print("LCD I2C"); 
  delay(500); 
}
