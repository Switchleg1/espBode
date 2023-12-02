#include "esp_awg_fy6800.h"
#include <string.h>

void espAWGFY6800::setCh1Wave(uint8_t wave)
{
  espAWG::setCh1Wave(wave);
  
  char command[7];
  snprintf(command, 7, "WMW%02u\n", wave);
  writeData(command, 6);
}

void espAWGFY6800::setCh2Wave(uint8_t wave)
{
  espAWG::setCh2Wave(wave);
  
  char command[7];
  snprintf(command, 7, "WFW%02u\n", wave);
  writeData(command, 6);
}

void espAWGFY6800::setCh1Output(uint32_t output)
{
  espAWG::setCh1Output(output);
  
  writeData((char*)(output ? "WMN1\n" : "WMN0\n"), 5);
}

void espAWGFY6800::setCh2Output(uint32_t output)
{
  espAWG::setCh2Output(output);
  
  writeData((char*)(output ? "WFN1\n" : "WFN0\n"), 5);
}

/* Set frequency in Hz */
void espAWGFY6800::setCh1Freq(uint32_t frequency)
{
  espAWG::setCh1Freq(frequency);
  
  char command[19];
  snprintf(command, 19, "WMF%08lu000000\n", frequency);
  writeData(command, 18);
}

/* Set frequency in Hz */
void espAWGFY6800::setCh2Freq(uint32_t frequency)
{
  espAWG::setCh2Freq(frequency);
  
  char command[19];
  snprintf(command, 19, "WFF%08lu000000\n", frequency);
  writeData(command, 18);
}

/* Ampl is in mV: 12.345V = 12345 */
void espAWGFY6800::setCh1Ampl(uint32_t ampl)
{
  espAWG::setCh1Ampl(ampl);
  
  char command[11];
  snprintf(command, 11, "WMA%02u.%03u\n", ampl/1000, ampl%1000);
  writeData(command, 10);
}

void espAWGFY6800::setCh2Ampl(uint32_t ampl)
{
  espAWG::setCh2Ampl(ampl);
  
  char command[11];
  snprintf(command, 11, "WFA%02u.%03u\n", ampl/1000, ampl%1000);
  writeData(command, 10);
}

/* Phase is in 0.1deg: 12.5deg = 125 */
void espAWGFY6800::setCh1Phase(uint32_t phase)
{
  espAWG::setCh1Phase(phase);
  
  char command[11];
  snprintf(command, 11, "WMP%02u.%01u\n", phase/1000, (phase%1000)/100);
  writeData(command, 10);
}

void espAWGFY6800::setCh2Phase(uint32_t phase)
{
  espAWG::setCh2Phase(phase);
  
  char command[11];
  snprintf(command, 11, "WFP%02u.%01u\n", phase/1000, (phase%1000)/100);
  writeData(command, 10);
}

void espAWGFY6800::setCh1Offset(int32_t offset)
{
  espAWG::setCh1Offset(offset);
  
  char command[12];
  if(offset < 0) {
    snprintf(command, 12, "WMO-%02u.%03u\n", -offset/1000, -offset%1000);
    writeData(command, 11);
  } else {
    snprintf(command, 11, "WMO%02u.%03u\n", offset/1000, offset%1000);
    writeData(command, 10);
  }
}

void espAWGFY6800::setCh2Offset(int32_t offset)
{
  espAWG::setCh2Offset(offset);
  
  char command[12];
  if(offset < 0) {
    snprintf(command, 12, "WFO-%02u.%03u\n", -offset/1000, -offset%1000);
    writeData(command, 11);
  } else {
    snprintf(command, 12, "WFO%02u.%03u\n", offset/1000, offset%1000);
    writeData(command, 10);
  }
}
