# 1 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino"
# 1 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino"
/*

    HTTP over TLS (HTTPS) example sketch



    This example demonstrates how to use

    WiFiClientSecure class to access HTTPS API.

    We fetch and display the status of

    esp8266/Arduino project continuous integration

    build.



    Limitations:

      only RSA certificates

      no support of Perfect Forward Secrecy (PFS)

      TLSv1.2 is supported since version 2.4.0-rc1



    Created by Ivan Grokhotkov, 2015.

    This example is in public domain.

*/
# 19 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino"
# 20 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 21 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 22 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 23 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 24 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 25 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 26 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 27 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 28 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 29 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 30 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 31 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 32 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 33 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 34 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 35 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 36 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2
# 37 "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" 2






const char *ssid = "Softech SD";
const char *password = "softech@38yenbai";

const char *host = "cloud.softech.vn";
const int httpsPort = 443;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char fingerprint[] __attribute__((section( "\".irom.text." "d:\\Working\\GitHub\\Arduino-Training\\wifi-request-sample\\wifi-request-sample.ino" "." "51" "." "0" "\""))) = "5F F1 60 31 09 04 3E F2 90 D2 B0 8A 50 38 04 E8 37 9F BC 76";

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);

  //Serial.printf("Using fingerprint '%s'\n", fingerprint);
  //client.setFingerprint(fingerprint);

  if (!client.connect(host, httpsPort))
  {
    Serial.println("connection failed");
    return;
  }

  String url = "/mobile/ames/api/vocabulary/kite";
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected())
  {
    String line = client.readStringUntil('\n');
    if (line == "\r")
    {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\""))
  {
    Serial.println("esp8266/Arduino CI successfull!");
  }
  else
  {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}

void loop()
{
}
