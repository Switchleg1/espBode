#include "esp_awg_jds6600.h"
#include <string.h>

void espAWGJDS6600::setCh1Wave(uint8_t wave)
{
  espAWG::setCh1Wave(wave);
  
  snprintf(command, CMD_LEN, ":w21=%01u.\r\n", wave);
  writeData();
}

void espAWGJDS6600::setCh2Wave(uint8_t wave)
{
  espAWG::setCh2Wave(wave);

  snprintf(command, CMD_LEN, ":w21=%01u.\r\n", wave);
  writeData();
}

void espAWGJDS6600::setCh1Output(uint32_t output)
{
  espAWG::setCh1Output(output);

  snprintf(command, CMD_LEN, ":w20=%01u,%01u.\r\n", gDeviceState.ch1Output, gDeviceState.ch2Output);
  writeData();
}

void espAWGJDS6600::setCh2Output(uint32_t output)
{
  espAWG::setCh2Output(output);

  snprintf(command, CMD_LEN, ":w20=%01u,%01u.\r\n", gDeviceState.ch1Output, gDeviceState.ch2Output);
  writeData();
}

/* Set frequency in Hz */
void espAWGJDS6600::setCh1Freq(uint32_t frequency)
{
  espAWG::setCh1Freq(frequency);

  do {
    snprintf(command, CMD_LEN, ":w23=%u,0.\r\n", frequency);
    writeData();
    snprintf(command, CMD_LEN, ":r23=0.\r\n");
    writeData();
  } while(strstr(command, ":r23=0,0.") == command);
}

/* Set frequency in Hz */
void espAWGJDS6600::setCh2Freq(uint32_t frequency)
{
  espAWG::setCh2Freq(frequency);

  do {
    snprintf(command, CMD_LEN, ":w24=%u,0.\r\n", frequency);
    writeData();
    snprintf(command, CMD_LEN, ":r24=0.\r\n");
    writeData();
  } while(strstr(command, ":r24=0,0.") == command);
}

/* Ampl is in mV: 12.345V = 12345 */
void espAWGJDS6600::setCh1Ampl(uint32_t ampl)
{
  espAWG::setCh1Ampl(ampl);

  snprintf(command, CMD_LEN, ":w25=%u.\r\n", ampl);
  writeData();
}

void espAWGJDS6600::setCh2Ampl(uint32_t ampl)
{
  espAWG::setCh2Ampl(ampl);

  snprintf(command, CMD_LEN, ":w26=%u.\r\n", ampl);
  writeData();
}

/* Phase is in 0.1deg: 12.5deg = 125 */
void espAWGJDS6600::setCh1Phase(uint32_t phase)
{
  espAWG::setCh1Phase(phase);

  snprintf(command, CMD_LEN, ":w31=%u.\r\n", phase / 100);
  writeData();
}

void espAWGJDS6600::setCh2Phase(uint32_t phase)
{
  espAWG::setCh2Phase(phase);

  snprintf(command, CMD_LEN, ":w31=%u.\r\n", phase / 100);
  writeData();
}

void espAWGJDS6600::setCh1Offset(int32_t offset)
{
  if(offset > 9999) offset = 9999;
  if(offset < -9999) offset = -9999;

  espAWG::setCh1Offset(offset);
  
  snprintf(command, CMD_LEN, ":w27=%d.\r\n", offset / 10 + 1000);
  writeData();
}

void espAWGJDS6600::setCh2Offset(int32_t offset)
{
  if(offset > 9999) offset = 9999;
  if(offset < -9999) offset = -9999;

  espAWG::setCh2Offset(offset);
  
  snprintf(command, CMD_LEN, ":w28=%d.\r\n", offset / 10 + 1000);
  writeData();
}
