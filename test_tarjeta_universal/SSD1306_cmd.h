#ifndef SSD1306_CMD_H
#define SSD1306_CMD_H

#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"
#include "memory.h" 

//
typedef struct
{
  char str_cmd[64];
  // array de valores de argumento fijos
  uint8_t cmd_fijo[7];
  uint8_t size_cmd;
  // array de valores de argumento variable, bit a bit validos que ses puede disponer a variar
  uint8_t cmd_Args_bit[7];
  // array de valores de argumento variable, por defecto
  uint8_t cmd_Args[7];
  // array de valores de argumento variable, por actual
  uint8_t cmd_Args_current[7];
} SSD1306_comand;

// enum de todos los comando en orden del  datasheet
typedef enum SSD1306_cmd_enum
{
  Set_Contrast_Control,
  Entire_Display_ON,
  Set_N_I_Display,
  Set_Display_ON_OFF,
  Continuous_Horizontal_Scroll,
  Continuous_Vertical_and_Horizontal_Scroll,
  Deactivate_Scroll,
  Activate_Scroll,
  Set_Vertical_Scroll_Area,
  Set_Lower_Column_Start_Address_for_Page_Addressing_Mode,
  Set_High_Column_Start_Address_for_Page_Addressing_Mode,
  Set_Memory_Addressing_Mode,
  Set_Column_Address,
  Set_Page_Address,
  Set_Page_Start_Address_for_Page_Addressing_Mode,
  Set_Display_Start_Line,
  Set_Segment_Remap,
  Set_Multiplex_Ratio,
  Set_COM_Output_Scan_Direction,
  Set_Display_Offset,
  Set_COM_Pins_Hardware_Configuration,
  Set_Display_Clock_Divide_Ratio_and_OSC_Frequency,
  Set_Precharge_Period,
  Charge_Pump_Command
} SSD1306_cmd_enum;

extern const uint8_t SSD1306_cmd_default[];
extern const size_t  SSD1306_cmd_default_len;

extern SSD1306_comand SSD1306_cmd_list[];
extern const size_t        SSD1306_cmd_list_len;

// metodo de structs
// crea un array de comando con los argumento fijo y variable juntos
// se superpone el array fijo y variables
void array_combinado_fijo_args(SSD1306_comand SSD1306_cmd, uint8_t i, uint8_t *array);

uint8_t Check_Arg_variable(SSD1306_comand SSD1306_cmd,uint8_t Args_bit[7]);

void reset_Args_List_Cmd(SSD1306_comand *SSD1306_cmd);

#endif /* SSD1306_CMD_H */