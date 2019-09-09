// HC-SR04
// https://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/

#define trigPin 3
#define echoPin 2

int L1 = 13; // LED connected to digital pin 4

void setup ()
{
  Serial.begin(9600);
  //
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(L1, OUTPUT);
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

  //  Serial.print("distance: ");
  //  Serial.println(distance);
  if (distance <= 6)
  {
    digitalWrite(L1, HIGH); // set the LED on
  }
  else
  {
    digitalWrite(L1, LOW); // set the LED on
  }
  delay(100);
}
