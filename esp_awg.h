#ifndef _ESP_AWG_H_
#define _ESP_AWG_H_

#include <ESP8266WiFi.h>

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

typedef struct {
    uint8_t     ch1Output;
    uint8_t     ch2Output;
    EWaveType   ch1Wave;
    EWaveType   ch2Wave;
    uint32_t    ch1Freq;
    uint32_t    ch2Freq;
    uint32_t    ch1Ampl;
    uint32_t    ch2Ampl;
    uint32_t    ch1Phase;
    uint32_t    ch2Phase;
    uint32_t    ch1Offset;
    uint32_t    ch2Offset;
} SDeviceState;

class espAWG {
  public:
    virtual void setCh1Wave(EWaveType wave) {};
    virtual void setCh2Wave(EWaveType wave) {};
    
    /* 0 - off; 1 - on */
    virtual void setCh1Output(uint32_t output) {};
    virtual void setCh2Output(uint32_t output) {};
    
    /* Set frequency in Hz */
    virtual void setCh1Freq(uint32_t frequency) {};
    virtual void setCh2Freq(uint32_t frequency) {};
    
    /* Ampl is in mV: 12.345V = 12345 */
    virtual void setCh1Ampl(uint32_t ampl) {};
    virtual void setCh2Ampl(uint32_t ampl) {};
    
    /* Phase is in 0.1deg: 12.5deg = 125 */
    virtual void setCh1Phase(uint32_t phase) {};
    virtual void setCh2Phase(uint32_t phase) {};
    
    /* Offset is in mV: 12.345V = 12345 */
    virtual void setCh1Offset(int32_t offset) {};
    virtual void setCh2Offset(int32_t offset) {};

    SDeviceState gDeviceState;

  protected:
    void writeData(const char* data, uint8_t len);
};

#endif _ESP_AWG_H_