#include "esp_awg.h"
#include <string.h>

void espAWG::writeData(const char* data, uint8_t len)
{
  uint32_t timeout = 0;
  Serial.write((uint8_t*)data, len);
  
#if defined(ESP32)
  Serial2.write((uint8_t*)data, len);
  while(0 == Serial2.available()) {
#else
  while(0 == Serial.available()) {
#endif
    delay(1);
    if(timeout++>1000) return;
  }

#if defined(ESP32)
  Serial2.read();
#else
  Serial.read();
#endif
}
