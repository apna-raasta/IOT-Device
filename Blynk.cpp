#include <ESP8266WiFi.h>

#define BLYNK_PRINT Serial


#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "90b68651e1a040c787f6a6b01517c593";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "raunak";
char pass[] = "raunak1907";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  int val = 420;
  Blynk.virtualWrite(V1,val);
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
