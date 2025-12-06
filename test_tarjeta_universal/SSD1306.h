#ifndef SSD1306_H
#define SSD1306_H

#include <stdint.h>
#include <stdio.h>
#include <memory.h>
#include "SSD1306_cmd.h"


// void list_cmd(uint8_t *buf_tx, uint8_t *buf_arg);
void CreateArrayCmdDefault(uint8_t (*buf)[8], uint8_t buf_size);
void FrameCmdToI2C(uint8_t *buf_tx, uint16_t *buf_size);

#endif