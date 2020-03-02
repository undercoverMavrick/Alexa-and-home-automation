#include "Alexaheader1.h"


fauxmoESP fauxmo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
   Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());

  fauxmo.createServer(true); // not needed, this is the default value
    fauxmo.setPort(80); // This is required for gen3 devices

    // You have to call enable(true) once you have a WiFi connection
    // You can enable or disable the library at any moment
    // Disabling it will prevent the devices from being discovered and switched
    fauxmo.enable(true);
    Serial.println("fauxmo is setup tpppppp");
    fauxmo.addDevice(Device1);
    fauxmo.addDevice(Device2);
    fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
    Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);


    if (strcmp(device_name, Device1)==0) {
      Serial.println(state);
      if (state == 1)
      {
        Serial.println("ON");
        Serial.write(R1ON, sizeof(R1ON));
      }
      else if(state == 0)
      {
        Serial.println("OFF");
        Serial.write(R1OFF, sizeof(R1OFF));
      }
    }
    if (strcmp(device_name, Device2)==0) {
      Serial.println(state);
      if (state == 1)
      {
        Serial.println("ON");
        Serial.write(R2ON, sizeof(R2ON));
      }
      else if(state == 0)
      {
        Serial.println("OFF");
        Serial.write(R2OFF, sizeof(R2OFF));
      }
    }
        });
}

void loop() {
  // put your main code here, to run repeatedly:

 fauxmo.handle();

    // This is a sample code 
}
 
