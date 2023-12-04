#ifndef _ESP_JDS6600_H_
#define _ESP_JDS6600_H_

#include "esp_awg.h"

#ifdef AWG_TYPE_JDS6600
typedef enum {
  EWaveType_Sine          = 0,
  EWaveType_Square        = 1,
  EWaveType_AdjPulse      = 2,
  EWaveType_Triangle      = 3,
  EWaveType_PosHalfSin    = 4,
  EWaveType_CMOS          = 5,
  EWaveType_DC            = 6,
  
  EWaveType_PosFullSin    = 8,
  EWaveType_PosStair      = 9,
  EWaveType_NegStair      = 10,
  EWaveType_Noise         = 11,
  EWaveType_PosExp        = 12,
  EWaveType_NegExp        = 13,
  EWaveType_Multitone     = 14,
  EWaveType_SincPulse     = 15,
  EWaveType_Lorentz       = 16,


  EWaveType_Last
} EWaveType;
#endif

class espAWGJDS6600: public espAWG {
  public:
    void setCh1Wave(uint8_t wave);
    void setCh2Wave(uint8_t wave);
    
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

#endif _ESP_JDS6600_H_
