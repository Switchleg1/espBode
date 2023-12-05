#include "esp_awg.h"
#include <string.h>

#include "esp_config.h"

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

void espAWG::writeData()
{
  //send command to awg
  Serial.write((uint8_t*)command, strlen(command));

  //echo via serial esp32
#if defined(ESP32)
  Serial2.write((uint8_t*)command, strlen(command));
#endif

  //echo via telnet
#if defined(DEBUG_TELNET) && !defined(DEBUG_UART) && !defined(ESP32)
  telnet.print(command);
#endif

  //get response
  uint16_t  timeout = 0;
  char      responseString[256] = {0,};
  uint8_t   responsePos = 0;
  while(timeout++ < 1000) {
#if defined(ESP32)
    if(Serial2.available() > 0) {
      char c = Serial2.read();
#else
    if(Serial.available() > 0) {
      char c = Serial.read();
#endif
      if(c == '\n') {
        responseString[responsePos++] = 0;
        timeout = 0xFFFF;
        break;
      } else {
        responseString[responsePos++] = c;
      }
    }
    delay(1);
  }
  responseString[responsePos] = 0;

  //write response
  DEBUG(responseString);

  if(timeout != 0xFFFF) {
    DEBUG("TIMEOUT");
  }
}
