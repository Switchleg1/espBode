#ifndef _ESP_AWG_H_
#define _ESP_AWG_H_

#include "esp_config.h"

#define CMD_LEN 128

typedef struct {
    uint8_t     ch1Output;
    uint8_t     ch2Output;
    uint8_t     ch1Wave;
    uint8_t     ch2Wave;
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
    virtual void setCh1Wave(uint8_t wave);
    virtual void setCh2Wave(uint8_t wave);
    
    /* 0 - off; 1 - on */
    virtual void setCh1Output(uint32_t output);
    virtual void setCh2Output(uint32_t output);
    
    /* Set frequency in Hz */
    virtual void setCh1Freq(uint32_t frequency);
    virtual void setCh2Freq(uint32_t frequency);
    
    /* Ampl is in mV: 12.345V = 12345 */
    virtual void setCh1Ampl(uint32_t ampl);
    virtual void setCh2Ampl(uint32_t ampl);
    
    /* Phase is in 0.1deg: 12.5deg = 125 */
    virtual void setCh1Phase(uint32_t phase);
    virtual void setCh2Phase(uint32_t phase);
    
    /* Offset is in mV: 12.345V = 12345 */
    virtual void setCh1Offset(int32_t offset);
    virtual void setCh2Offset(int32_t offset);

  protected:
    void          writeData();

    SDeviceState  gDeviceState;
    char          command[CMD_LEN];
};

#endif _ESP_AWG_H_
