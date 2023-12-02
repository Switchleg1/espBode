#include "esp_awg_fy6900.h"
#include <string.h>

void espAWGFY6900::setCh1Wave(uint8_t wave)
{
  char command[] = "WMW00\n";
  snprintf(command, 7, "WMW%02u\n", wave);
  gDeviceState.ch1Wave = wave;
  writeData(command, 6);
}

void espAWGFY6900::setCh2Wave(uint8_t wave)
{
  char command[] = "WFW00\n";
  snprintf(command, 7, "WFW%02u\n", wave);
  gDeviceState.ch2Wave = wave;
  writeData(command, 6);
}

void espAWGFY6900::setCh1Output(uint32_t output)
{
  gDeviceState.ch1Output = output;
  writeData((char*)(output ? "WMN1\n" : "WMN0\n"), 5);
}

void espAWGFY6900::setCh2Output(uint32_t output)
{
  gDeviceState.ch2Output = output;
  writeData((char*)(output ? "WFN1\n" : "WFN0\n"), 5);
}

/* Set frequency in Hz */
void espAWGFY6900::setCh1Freq(uint32_t frequency)
{
  char command[] = "WMF00000000000000\n";
  snprintf(command, 19, "WMF%08lu000000\n", frequency);
  gDeviceState.ch1Freq = frequency;
  writeData(command, 18);
}

/* Set frequency in Hz */
void espAWGFY6900::setCh2Freq(uint32_t frequency)
{
  char command[] = "WFF00000000000000\n";
  snprintf(command, 19, "WFF%08lu000000\n", frequency);
  gDeviceState.ch2Freq = frequency;
  writeData(command, 18);
}

/* Ampl is in mV: 12.345V = 12345 */
void espAWGFY6900::setCh1Ampl(uint32_t ampl)
{
  char command[] = "WMA00.000\n";
  snprintf(command, 11, "WMA%02u.%03u\n", ampl/1000, ampl%1000);
  gDeviceState.ch1Ampl = ampl;
  writeData(command, 10);
}

void espAWGFY6900::setCh2Ampl(uint32_t ampl)
{
  char command[] = "WFA00.000\n";
  snprintf(command, 11, "WFA%02u.%03u\n", ampl/1000, ampl%1000);
  gDeviceState.ch2Ampl = ampl;
  writeData(command, 10);
}

/* Phase is in 0.1deg: 12.5deg = 125 */
void espAWGFY6900::setCh1Phase(uint32_t phase)
{
  char command[] = "WMP000.000\n";
  snprintf(command, 12, "WMP%03u.%03u\n", phase/1000, (phase%1000)/100);
  gDeviceState.ch1Phase = phase;
  writeData(command, 11);
}

void espAWGFY6900::setCh2Phase(uint32_t phase)
{
  char command[] = "WFP000.000\n";
  snprintf(command, 12, "WFP%03u.%03u\n", phase/1000, (phase%1000)/100);
  gDeviceState.ch2Phase = phase;
  writeData(command, 11);
}

void espAWGFY6900::setCh1Offset(int32_t offset)
{
  char command[] = "WMO00.00\n";
  gDeviceState.ch1Offset = offset;
  if(offset>=0) {
    snprintf(command, 10, "WMO%02u.%02u\n", offset/1000, offset%1000);
    writeData(command, 9);
  } else {
    snprintf(command, 11, "WMO-%02u.%02u\n", -offset/1000, -offset%1000);
    writeData(command, 10);
  }
}

void espAWGFY6900::setCh2Offset(int32_t offset)
{
  char command[] = "WFO00.00\n";
  gDeviceState.ch2Offset = offset;
  if(offset>=0) {
    snprintf(command, 10, "WFO%02u.%02u\n", offset/1000, offset%1000);
    writeData(command, 9);
  } else {
   snprintf(command, 11, "WFO-%02u.%02u\n", -offset/1000, -offset%1000);
   writeData(command, 10);
 }
}
