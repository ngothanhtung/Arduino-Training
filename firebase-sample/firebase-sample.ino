#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <DHT.h>

// Set these to run example.
#define FIREBASE_HOST "softech-iot.firebaseio.com"
#define FIREBASE_AUTH "7ToDsBagkqB8m8iJFw7cNLeYi1rLyBstCMqYgdmo"
#define WIFI_SSID "Softech SD"
#define WIFI_PASSWORD "softech@38yenbai"

// DHT

#define DHTPIN 10 // what pin we're connected to
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());


  // Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  // DHT
  dht.begin();

}


void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h))
  {
    return;
  }
  else
  {

    
    String message = "Humidity: " + String(h) + "%, Temperature: " + String(t) + "°C";
    Firebase.setFloat("iot/locations/softech/humidity/", h);
    Firebase.setFloat("iot/locations/softech/temperature/", t);
    // handle error
    if (Firebase.failed()) {
      Serial.print("setting  /message failed:");
      Serial.println(Firebase.error());
      return;
    }
  }

  delay(10000);
}
