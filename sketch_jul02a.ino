#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0,0);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available())
  {
    delay(1000);
    lcd.clear();
    while(Serial.available()>0)
    {

      char c = Serial.read();
      if(isAlphaNumeric(c))
      {
        lcd.write(c);
      }
      
    }
  }

}
