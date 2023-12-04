#include "esp_awg_fy6900.h"
#include <string.h>

void espAWGFY6900::setCh1Wave(uint8_t wave)
{
  espAWG::setCh1Wave(wave);

  snprintf(command, CMD_LEN, "WMW%02u\n", wave);
  writeData();
}

void espAWGFY6900::setCh2Wave(uint8_t wave)
{
  espAWG::setCh2Wave(wave);

  snprintf(command, CMD_LEN, "WFW%02u\n", wave);
  writeData();
}

void espAWGFY6900::setCh1Output(uint32_t output)
{
  espAWG::setCh1Output(output);

  snprintf(command, CMD_LEN, "%s\n", (output ? "WMN1" : "WMN0"));
  writeData();
}

void espAWGFY6900::setCh2Output(uint32_t output)
{
  espAWG::setCh2Output(output);
  
  snprintf(command, CMD_LEN, "%s\n", (output ? "WFN1" : "WFN0"));
  writeData();
}

/* Set frequency in Hz */
void espAWGFY6900::setCh1Freq(uint32_t frequency)
{
  espAWG::setCh1Freq(frequency);

  snprintf(command, CMD_LEN, "WMF%08lu000000\n", frequency);
  writeData();
}

/* Set frequency in Hz */
void espAWGFY6900::setCh2Freq(uint32_t frequency)
{
  espAWG::setCh2Freq(frequency);

  snprintf(command, CMD_LEN, "WFF%08lu000000\n", frequency);
  writeData();
}

/* Ampl is in mV: 12.345V = 12345 */
void espAWGFY6900::setCh1Ampl(uint32_t ampl)
{
  espAWG::setCh1Ampl(ampl);

  snprintf(command, CMD_LEN, "WMA%02u.%03u\n", ampl / 1000, ampl % 1000);
  writeData();
}

void espAWGFY6900::setCh2Ampl(uint32_t ampl)
{
  espAWG::setCh2Ampl(ampl);

  snprintf(command, CMD_LEN, "WFA%02u.%03u\n", ampl / 1000, ampl % 1000);
  writeData();
}

/* Phase is in 0.1deg: 12.5deg = 125 */
void espAWGFY6900::setCh1Phase(uint32_t phase)
{
  espAWG::setCh1Phase(phase);

  snprintf(command, CMD_LEN, "WMP%03u.%01u\n", phase / 1000, (phase % 1000) / 100);
  writeData();
}

void espAWGFY6900::setCh2Phase(uint32_t phase)
{
  espAWG::setCh2Phase(phase);

  snprintf(command, CMD_LEN, "WFP%03u.%01u\n", phase / 1000, (phase % 1000) / 100);
  writeData();
}

void espAWGFY6900::setCh1Offset(int32_t offset)
{
  espAWG::setCh1Offset(offset);

  if(offset < 0) {
    snprintf(command, CMD_LEN, "WMO-%02u.%02u\n", -offset / 1000, (-offset % 1000) / 10);
  } else {
    snprintf(command, CMD_LEN, "WMO%02u.%02u\n", offset / 1000, (offset % 1000) / 10);
  }

  writeData();
}

void espAWGFY6900::setCh2Offset(int32_t offset)
{
  espAWG::setCh2Offset(offset);

  if(offset < 0) {
    snprintf(command, CMD_LEN, "WFO-%02u.%02u\n", -offset / 1000, (-offset % 1000) / 10);
  } else {
    snprintf(command, CMD_LEN, "WFO%02u.%02u\n", offset / 1000, (offset % 1000) / 10);
  }

  writeData();
}
