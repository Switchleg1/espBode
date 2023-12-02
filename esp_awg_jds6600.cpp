#include "esp_awg_jds6600.h"
#include <string.h>

void espAWGJDS6600::setCh1Wave(uint8_t wave)
{
  espAWG::setCh1Wave(wave);
  
  char command[13];
  snprintf(command, 13, ":w21=%01u.\r\n", wave);
  writeData(command, 12);
}

void espAWGJDS6600::setCh2Wave(uint8_t wave)
{
  espAWG::setCh2Wave(wave);
  
  char command[13];
  snprintf(command, 13, ":w21=%01u.\r\n", wave);
  writeData(command, 12);
}

void espAWGJDS6600::setCh1Output(uint32_t output)
{
  espAWG::setCh1Output(output);
  
  char command[12];
  snprintf(command, 12, ":w20=%01u,%01u.\r\n", gDeviceState.ch1Output, gDeviceState.ch2Output);
  writeData(command, 11);
}

void espAWGJDS6600::setCh2Output(uint32_t output)
{
  espAWG::setCh2Output(output);
  
  char command[12];
  snprintf(command, 12, ":w20=%01u,%01u.\r\n", gDeviceState.ch1Output, gDeviceState.ch2Output);
  writeData(command, 11);
}

/* Set frequency in Hz */
void espAWGJDS6600::setCh1Freq(uint32_t frequency)
{
  espAWG::setCh1Freq(frequency);
  
  char command[64];
  snprintf(command, 64, ":w23=%lu,0.\r\n", frequency);
  writeData(command, strlen(command));
}

/* Set frequency in Hz */
void espAWGJDS6600::setCh2Freq(uint32_t frequency)
{
  espAWG::setCh2Freq(frequency);
  
  char command[64];
  snprintf(command, 64, ":w24=%lu,0.\r\n", frequency);
  writeData(command, strlen(command));
}

/* Ampl is in mV: 12.345V = 12345 */
void espAWGJDS6600::setCh1Ampl(uint32_t ampl)
{
  espAWG::setCh1Ampl(ampl);
  
  char command[64];
  snprintf(command, 64, ":w25=%lu.\r\n", ampl);
  writeData(command, strlen(command));
}

void espAWGJDS6600::setCh2Ampl(uint32_t ampl)
{
  espAWG::setCh2Ampl(ampl);
  
  char command[64];
  snprintf(command, 64, ":w26=%lu.\r\n", ampl);
  writeData(command, strlen(command));
}

/* Phase is in 0.1deg: 12.5deg = 125 */
void espAWGJDS6600::setCh1Phase(uint32_t phase)
{
  espAWG::setCh1Phase(phase);
  
  char command[64];
  snprintf(command, 64, ":w31=%lu.\r\n", phase / 100);
  writeData(command, strlen(command));
}

void espAWGJDS6600::setCh2Phase(uint32_t phase)
{
  espAWG::setCh2Phase(phase);
  
  char command[64];
  snprintf(command, 64, ":w31=%lu.\r\n", phase / 100);
  writeData(command, strlen(command));
}

void espAWGJDS6600::setCh1Offset(int32_t offset)
{
  if(offset > 9999) offset = 9999;
  if(offset < -9999) offset = -9999;

  espAWG::setCh1Offset(offset);
  
  char command[64];
  snprintf(command, 64, ":w27=%l.\r\n", offset / 10 + 1000);
  writeData(command, strlen(command));
}

void espAWGJDS6600::setCh2Offset(int32_t offset)
{
  if(offset > 9999) offset = 9999;
  if(offset < -9999) offset = -9999;

  espAWG::setCh2Offset(offset);
  
  char command[64];
  snprintf(command, 64, ":w28=%l.\r\n", offset / 10 + 1000);
  writeData(command, strlen(command));
}
