#include <SoftwareSerial.h>
#define TX_PIN      6
#define RX_PIN      7

SoftwareSerial bluetooth(TX_PIN, RX_PIN);

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);

  Serial.println("Enter AT commands:");
}

void loop()
{
  if (bluetooth.available())
  {
    Serial.write(bluetooth.read());
  }

  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
}
