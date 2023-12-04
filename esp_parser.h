#ifndef _ESP_PARSER_H_
#define _ESP_PARSER_H_

#include "esp_config.h"
#ifdef AWG_TYPE_JDS6600
  #include "esp_awg_jds6600.h"
  extern espAWGJDS6600 awg;
#endif
#ifdef AWG_TYPE_FY6800
  #include "esp_awg_fy6800.h"
  extern espAWGFY6800 awg;
#endif
#ifdef AWG_TYPE_FY6900
  #include "esp_awg_fy6900.h"
  extern espAWGFY6900 awg;
#endif

extern volatile char *gReadBuffer;

void handleWriteMsg(char *msg, uint8_t len);

#endif
