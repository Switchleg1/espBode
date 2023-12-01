#include "esp_awg.h"
#include <string.h>

void espAWG::writeData(const char* data, uint8_t len)
{
  uint32_t timeout = 0;
  Serial.write((uint8_t*)data, len);
  while(0 == Serial.available()) {
    delay(1);
    if(timeout++>1000) return;
  }
  
  Serial.read();
}
