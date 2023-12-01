#include "esp_awg_fy6800.h"
#include <string.h>

#include "esp_config.h"
#ifdef AWG_TYPE_FY6800
  espAWGFY6800 awg;
#endif

void espAWGFY6800::setCh1Wave(EWaveType wave)
{
    char command[] = "WMW00\n";
    snprintf(command, 7, "WMW%02u\n", wave);
    gDeviceState.ch1Wave = wave;
    writeData(command, 6);
}

void espAWGFY6800::setCh2Wave(EWaveType wave)
{
    char command[] = "WFW00\n";
    snprintf(command, 7, "WFW%02u\n", wave);
    gDeviceState.ch2Wave = wave;
    writeData(command, 6);
}

void espAWGFY6800::setCh1Output(uint32_t output)
{
    if(output)
    {
        gDeviceState.ch1Output = 1;
        writeData("WMN1\n", 5);
    }
    else
    {
        gDeviceState.ch1Output = 0;
        writeData("WMN0\n", 5);
    }
}

void espAWGFY6800::setCh2Output(uint32_t output)
{
    if(output)
    {
        gDeviceState.ch2Output = 1;
        writeData("WFN1\n", 5);
    }
    else
    {
        gDeviceState.ch2Output = 0;
        writeData("WFN0\n", 5);
    }
}

/* Set frequency in Hz */
void espAWGFY6800::setCh1Freq(uint32_t frequency)
{
    char command[] = "WMF00000000000000\n";
    snprintf(command, 19, "WMF%08lu000000\n", frequency);
    gDeviceState.ch1Freq = frequency;
    writeData(command, 18);
}

/* Set frequency in Hz */
void espAWGFY6800::setCh2Freq(uint32_t frequency)
{
    char command[] = "WFF00000000000000\n";
    snprintf(command, 19, "WFF%08lu000000\n", frequency);
    gDeviceState.ch2Freq = frequency;
    writeData(command, 18);
}

/* Ampl is in mV: 12.345V = 12345 */
void espAWGFY6800::setCh1Ampl(uint32_t ampl)
{
    char command[] = "WMA00.000\n";
    snprintf(command, 11, "WMA%02u.%03u\n", ampl/1000, ampl%1000);
    gDeviceState.ch1Ampl = ampl;
    writeData(command, 10);
}

void espAWGFY6800::setCh2Ampl(uint32_t ampl)
{
    char command[] = "WFA00.000\n";
    snprintf(command, 11, "WFA%02u.%03u\n", ampl/1000, ampl%1000);
    gDeviceState.ch2Ampl = ampl;
    writeData(command, 10);
}

/* Phase is in 0.1deg: 12.5deg = 125 */
void espAWGFY6800::setCh1Phase(uint32_t phase)
{
    char command[] = "WMA00.000\n";
    snprintf(command, 11, "WMP%02u.%01u\n", phase/1000, (phase%1000)/100);
    gDeviceState.ch1Phase = phase;
    writeData(command, 10);
}

void espAWGFY6800::setCh2Phase(uint32_t phase)
{
    char command[] = "WFA00.000\n";
    snprintf(command, 11, "WFP%02u.%01u\n", phase/1000, (phase%1000)/100);
    gDeviceState.ch2Phase = phase;
    writeData(command, 10);
}

void espAWGFY6800::setCh1Offset(int32_t offset)
{
    char command[] = "WMO00.000\n";
    gDeviceState.ch1Offset = offset;
    if(offset>=0)
    {
        snprintf(command, 11, "WMO%02u.%03u\n", offset/1000, offset%1000);
        writeData(command, 10);
    }
    else
    {
        snprintf(command, 12, "WMO-%02u.%03u\n", -offset/1000, -offset%1000);
        writeData(command, 11);
    }
}

void espAWGFY6800::setCh2Offset(int32_t offset)
{
    char command[] = "WFO00.000\n";
    gDeviceState.ch2Offset = offset;
    if(offset>=0)
    {
        snprintf(command, 11, "WFO%02u.%03u\n", offset/1000, offset%1000);
        writeData(command, 10);
    }
    else
    {
       snprintf(command, 12, "WFO-%02u.%03u\n", -offset/1000, -offset%1000);
       writeData(command, 11);
   }
}
