#include "esp_awg_jds6600.h"
#include <string.h>

void espAWGJDS6600::setCh1Wave(uint8_t wave)
{
  char command[13];
  snprintf(command, 13, ":w21=%01u.\r\n", wave);
  gDeviceState.ch1Wave = wave;
  writeData(command, 12);
}

void espAWGJDS6600::setCh2Wave(uint8_t wave)
{
  char command[13];
  snprintf(command, 13, ":w21=%01u.\r\n", wave);
  gDeviceState.ch2Wave = wave;
  writeData(command, 12);
}

void espAWGJDS6600::setCh1Output(uint32_t output)
{
  char command[12];
  snprintf(command, 12, ":w20=%01u,%01u.\r\n", gDeviceState.ch1Output, gDeviceState.ch2Output);
  gDeviceState.ch1Output = output;
  writeData(command, 11);
}

void espAWGJDS6600::setCh2Output(uint32_t output)
{
  char command[12];
  snprintf(command, 12, ":w20=%01u,%01u.\r\n", gDeviceState.ch1Output, gDeviceState.ch2Output);
  gDeviceState.ch2Output = output;
  writeData(command, 11);
}

/* Set frequency in Hz */
void espAWGJDS6600::setCh1Freq(uint32_t frequency)
{
  char command[64];
  snprintf(command, 64, ":w23=%lu,0.\r\n", frequency);
  gDeviceState.ch1Freq = frequency;
  writeData(command, strlen(command));
}

/* Set frequency in Hz */
void espAWGJDS6600::setCh2Freq(uint32_t frequency)
{
  char command[64];
  snprintf(command, 64, ":w24=%lu,0.\r\n", frequency);
  gDeviceState.ch1Freq = frequency;
  writeData(command, strlen(command));
}

/* Ampl is in mV: 12.345V = 12345 */
void espAWGJDS6600::setCh1Ampl(uint32_t ampl)
{
  char command[64];
  snprintf(command, 64, ":w25=%lu.\r\n", ampl);
  gDeviceState.ch1Ampl = ampl;
  writeData(command, strlen(command));
}

void espAWGJDS6600::setCh2Ampl(uint32_t ampl)
{
  char command[64];
  snprintf(command, 64, ":w26=%lu.\r\n", ampl);
  gDeviceState.ch2Ampl = ampl;
  writeData(command, strlen(command));
}

/* Phase is in 0.1deg: 12.5deg = 125 */
void espAWGJDS6600::setCh1Phase(uint32_t phase)
{
  char command[64];
  snprintf(command, 64, ":w31=%lu.\r\n", phase / 100);
  gDeviceState.ch2Phase = phase;
  writeData(command, strlen(command));
}

void espAWGJDS6600::setCh2Phase(uint32_t phase)
{
  char command[64];
  snprintf(command, 64, ":w31=%lu.\r\n", phase / 100);
  gDeviceState.ch2Phase = phase;
  writeData(command, strlen(command));
}

void espAWGJDS6600::setCh1Offset(int32_t offset)
{
  if(offset > 9999) offset = 9999;
  if(offset < -9999) offset = -9999;
  
  char command[64];
  snprintf(command, 64, ":w27=%l.\r\n", offset / 10 + 1000);
  gDeviceState.ch1Offset = offset;
  writeData(command, strlen(command));
}

void espAWGJDS6600::setCh2Offset(int32_t offset)
{
  if(offset > 9999) offset = 9999;
  if(offset < -9999) offset = -9999;
  
  char command[64];
  snprintf(command, 64, ":w28=%l.\r\n", offset / 10 + 1000);
  gDeviceState.ch2Offset = offset;
  writeData(command, strlen(command));
}
