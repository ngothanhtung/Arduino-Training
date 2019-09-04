#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.init(); // initialize the lcd
  // Print a message to the LCD.
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("Xin chao YUMI");
  lcd.setCursor(0, 1);
  lcd.print("Xin chao JERRY");
}

void loop()
{
  // put your main code here, to run repeatedly:
}
