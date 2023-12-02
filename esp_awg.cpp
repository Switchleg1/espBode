#include "esp_awg.h"
#include <string.h>

void espAWG::setCh1Wave(uint8_t wave)
{
  gDeviceState.ch1Wave = wave;
}

void espAWG::setCh2Wave(uint8_t wave)
{
  gDeviceState.ch2Wave = wave;
}

/* 0 - off; 1 - on */
void espAWG::setCh1Output(uint32_t output)
{
  gDeviceState.ch1Output = output;
}

void espAWG::setCh2Output(uint32_t output)
{
  gDeviceState.ch2Output = output;
}

/* Set frequency in Hz */
void espAWG::setCh1Freq(uint32_t frequency)
{
  gDeviceState.ch1Freq = frequency;
}

void espAWG::setCh2Freq(uint32_t frequency)
{
  gDeviceState.ch2Freq = frequency;
}

/* Ampl is in mV: 12.345V = 12345 */
void espAWG::setCh1Ampl(uint32_t ampl)
{
  gDeviceState.ch1Ampl = ampl;
}

void espAWG::setCh2Ampl(uint32_t ampl)
{
  gDeviceState.ch2Ampl = ampl;
}

/* Phase is in 0.1deg: 12.5deg = 125 */
void espAWG::setCh1Phase(uint32_t phase)
{
  gDeviceState.ch1Phase = phase;
}

void espAWG::setCh2Phase(uint32_t phase)
{
  gDeviceState.ch2Phase = phase;
}

/* Offset is in mV: 12.345V = 12345 */
void espAWG::setCh1Offset(int32_t offset)
{
  gDeviceState.ch1Offset = offset;
}

void espAWG::setCh2Offset(int32_t offset)
{
  gDeviceState.ch2Offset = offset;
}

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
