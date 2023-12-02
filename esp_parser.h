#ifndef _ESP_PARSER_H_
#define _ESP_PARSER_H_

#include <arduino.h>

extern volatile char *gReadBuffer;

void handleWriteMsg(char *msg, uint8_t len);

#endif
