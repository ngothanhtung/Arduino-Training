#include <Arduino.h>
#line 1 "c:\\Working\\Github\\Arduino-Training\\dht-sample\\dht-sample.ino"
#line 1 "c:\\Working\\Github\\Arduino-Training\\dht-sample\\dht-sample.ino"
#include "DHT.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

#define DHTPIN 7 // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

#line 19 "c:\\Working\\Github\\Arduino-Training\\dht-sample\\dht-sample.ino"
void setup();
#line 37 "c:\\Working\\Github\\Arduino-Training\\dht-sample\\dht-sample.ino"
void loop();
#line 19 "c:\\Working\\Github\\Arduino-Training\\dht-sample\\dht-sample.ino"
void setup()
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();

  // LCD
  // put your setup code here, to run once:
  lcd.init(); // initialize the lcd
  // Print a message to the LCD.
  lcd.begin(16, 2);
  lcd.backlight();
  // lcd.print("Xin chao YUMI");
  // lcd.setCursor(0, 1);
  // lcd.print("Xin chao JERRY");
}

void loop()
{
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {
    // Serial.print("Humidity: ");
    // Serial.print(h);
    // Serial.print(" %\t");
    // Serial.print("Temperature: ");
    // Serial.print(t);
    // Serial.println(" *C");

    // Do am
    lcd.setCursor(0, 0);
    lcd.print("Humidity:");
    lcd.setCursor(14, 0);
    lcd.print(h);
    // Nhiet do
    lcd.setCursor(0, 1);
    lcd.print("Temperature:");
    lcd.setCursor(14, 1);
    lcd.print(t);

    delay(1000);
  }
}

