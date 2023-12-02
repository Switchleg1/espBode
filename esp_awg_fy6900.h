#ifndef _ESP_FY6900_H_
#define _ESP_FY6900_H_

#include "esp_awg.h"
#include "esp_config.h"

#ifdef AWG_TYPE_FY6900
typedef enum {
  EWaveType_Sine          = 0,
  EWaveType_Square        = 1,
  EWaveType_Rectangle     = 2,
  EWaveType_Trapezoid     = 3,
  EWaveType_CMOS          = 4,
  EWaveType_AdjPulse      = 5,
  EWaveType_DC            = 6,
  EWaveType_Triangle      = 7,
  EWaveType_PosRamp       = 8,
  EWaveType_NegRamp       = 9,
  EWaveType_StairTrng     = 10,
  EWaveType_PosStair      = 11,
  EWaveType_NegStair      = 12,
  EWaveType_PosExp        = 13,
  EWaveType_NegExp        = 14,
  EWaveType_PosFallExp    = 15,
  EWaveType_NegFallExp    = 16,
  EWaveType_PosLog        = 17,
  EWaveType_NegLog        = 18,
  EWaveType_PosFallLog    = 19,
  EWaveType_NegFallLog    = 20,
  EWaveType_PosFullSin    = 21,
  EWaveType_NegFullSin    = 22,
  EWaveType_PosHalfSin    = 23,
  EWaveType_NegHalfSin    = 24,
  EWaveType_Lorentz       = 25,
  EWaveType_Multitone     = 26,
  EWaveType_Noise         = 27,
  EWaveType_ECG           = 28,
  //EWaveType_Trapezoid     = 29,
  EWaveType_SincPulse     = 30,
  EWaveType_Impulse       = 31,
  EWaveType_AWGN          = 32,
  EWaveType_AM            = 33,
  EWaveType_FM            = 34,
  EWaveType_Chirp         = 35,
  //EWaveType_Impulse       = 36

  EWaveType_Last
} EWaveType;
#endif

class espAWGFY6900: public espAWG {
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

#endif //_ESP_FY6900_H_
