#ifndef _ESP_FY6800_H_
#define _ESP_FY6800_H_

#include "esp_awg.h"

#ifdef AWG_TYPE_FY6800
typedef enum {
  EWaveType_Sine          = 0,
  EWaveType_Square        = 1,
  EWaveType_CMOS          = 2,
  EWaveType_AdjPulse      = 3,
  EWaveType_DC            = 4,
  EWaveType_Triangle      = 5,
  EWaveType_PosRamp       = 6,
  EWaveType_NegRamp       = 7,
  EWaveType_StairTrng     = 8,
  EWaveType_PosStair      = 9,
  EWaveType_NegStair      = 10,
  EWaveType_PosExp        = 11,
  EWaveType_NegExp        = 12,
  EWaveType_PosFallExp    = 13,
  EWaveType_NegFallExp    = 14,
  EWaveType_PosLog        = 15,
  EWaveType_NegLog        = 16,
  EWaveType_PosFallLog    = 17,
  EWaveType_NegFallLog    = 18,
  EWaveType_PosFullSin    = 19,
  EWaveType_NegFullSin    = 20,
  EWaveType_PosHalfSin    = 21,
  EWaveType_NegHalfSin    = 22,
  EWaveType_Lorentz       = 23,
  EWaveType_Multitone     = 24,
  EWaveType_Noise         = 25,
  EWaveType_ECG           = 26,
  EWaveType_Trapezoid     = 27,
  EWaveType_SincPulse     = 28,
  EWaveType_Impulse       = 29,
  EWaveType_AWGN          = 30,
  EWaveType_AM            = 31,
  EWaveType_FM            = 32,
  EWaveType_Chirp         = 33,
  
  EWaveType_Last
} EWaveType;
#endif

class espAWGFY6800: public espAWG {
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

#endif _ESP_FY6800_H_
