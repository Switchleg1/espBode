#ifndef _ESP_JDS6600_H_
#define _ESP_JDS6600_H_

#include <ESP8266WiFi.h>
#include "esp_awg.h"

class espAWGJDS6600: public espAWG {
  public:
    void setCh1Wave(EWaveType wave);
    void setCh2Wave(EWaveType wave);
    
    /* 0 - off; 1 - on */
    void setCh1Output(uint32_t output);
    void setCh2Output(uint32_t output);
    
    /* Set frequency in Hz */
    void setCh1Freq(uint32_t frequency);
    void setCh2Freq(uint32_t frequency);
    
    /* Ampl is in mV: 12.345V = 12345 */
    void setCh1Ampl(uint32_t ampl);
    void setCh2Ampl(uint32_t ampl);
    
    /* Phase is in 0.1deg: 12.5deg = 125 */
    void setCh1Phase(uint32_t phase);
    void setCh2Phase(uint32_t phase);
    
    /* Offset is in mV: 12.345V = 12345 */
    void setCh1Offset(int32_t offset);
    void setCh2Offset(int32_t offset);
};

extern espAWGJDS6600 awg; 

#endif _ESP_JDS6600_H_