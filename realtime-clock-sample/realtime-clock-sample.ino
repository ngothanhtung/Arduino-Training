// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

// HC-SR04
#define trigPin 3
#define echoPin 2

void setup ()
{
  //
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init(); // initialize the lcd
  // Print a message to the LCD.
  lcd.begin(16, 2);
  lcd.backlight();

  Serial.begin(9600);



  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }



  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop () {
  //
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print("distance: ");
  Serial.println(distance);
  delay(500);

  return;
  DateTime now = rtc.now();


  lcd.setCursor(0, 0);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);

  char day[4];
  if (now.day() < 10)
  {
    sprintf(day, "0%1d", now.day());
  }
  else
  {
    sprintf(day, "%2d", now.day());
  }

  char month[4];
  if (now.month() < 10)
  {
    sprintf(month, "0%1d", now.month());
  }
  else
  {
    sprintf(month, "%2d", now.month());
  }



  // SECOND
  char second[4];

  if (now.second() < 10)
  {
    sprintf(second, "0%1d", now.second());
  }
  else
  {
    sprintf(second, "%2d", now.second());
  }

  // MINUTE
  char minute[4];
  if (now.minute() < 10)
  {
    sprintf(minute, "0%1d", now.minute());
  }
  else
  {
    sprintf(minute, "%2d", now.minute());
  }

  // HOUR
  char hour[4];
  if (now.hour() < 10)
  {
    sprintf(hour, "0%1d", now.hour());
  }
  else
  {
    sprintf(hour, "%2d", now.hour());
  }


  lcd.setCursor(0, 1);
  lcd.print(String(hour) + ":");
  lcd.setCursor(3, 1);
  lcd.print(String(minute) + ":");
  lcd.setCursor(6, 1);
  lcd.print(String(second));

  lcd.setCursor(6, 0);
  lcd.print(String(day) + "/");
  lcd.setCursor(9, 0);
  lcd.print(String(month) + "/");
  lcd.setCursor(12, 0);
  lcd.print(now.year());

  // Temperature
  lcd.setCursor(11, 1);
  lcd.print(rtc.getTemperature());

  /*
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");

    // calculate a date which is 7 days and 30 seconds into the future
    DateTime future (now + TimeSpan(7, 12, 30, 6));

    Serial.print(" now + 7d + 30s: ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();

    Serial.print("Temperature: ");
    Serial.print(rtc.getTemperature());
    Serial.println(" C");

    Serial.println();
  */
  delay(1000);
}
