#include <SoftwareSerial.h>
#define TX_PIN      6
#define RX_PIN      7

SoftwareSerial bluetooth(TX_PIN, RX_PIN);

#define RELAY 8

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  bluetooth.begin(9600);

  Serial.println("Enter AT commands:");

  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, LOW);

}


void loop() {
  // put your main code here, to run repeatedly:

  if (bluetooth.available())
  {
    int status  = bluetooth.read();
    String s = String(status);
    Serial.println(s);

    if (s == "48")
    {
      digitalWrite(RELAY, LOW);   //Relay 3 switches to NC
      delay(1000);
    }
    else
    {
      digitalWrite(RELAY, HIGH);  //Relay 3 switches to NO
      delay(1000);
    }

  }

  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }


}
