#include <LiquidCrystal.h>


const int rs= 22,en=23,d4=5,d5=18,d6=19,d7=21;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup(){
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,1);
}
void loop(){
  
  lcd.print("hello world!");
  delay(500);
}
