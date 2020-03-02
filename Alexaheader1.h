#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <fauxmoESP.h>

#define ssid      "Infiniteact"
#define password       "infiniterohan"

#define Device1  "Tube Light"

#define Device2  "Balcony Light"


const byte R1ON[] = {0xA0, 0x01, 0x01, 0xA2};
const byte R1OFF[] = {0xA0, 0x01, 0x00, 0xA1};

const byte R2ON[] = {0xA0, 0x02, 0x01, 0xA3};
const byte R2OFF[] = {0xA0, 0x02, 0x00, 0xA2};
