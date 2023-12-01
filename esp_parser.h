#ifndef _ESP_PARSER_H_
#define _ESP_PARSER_H_

#include <ESP8266WiFi.h>
#include "esp_config.h"
#ifdef AWG_TYPE_JDS6600
  #include "esp_awg_jds6600.h"
#endif
#ifdef AWG_TYPE_FY6800
  #include "esp_awg_fy6800.h"
#endif

extern volatile char *gReadBuffer;

void handleWriteMsg(char *msg, uint8_t len);

#endif
