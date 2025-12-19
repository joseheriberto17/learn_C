#ifndef SSD1306_CMD_H
#define SSD1306_CMD_H


#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <memory.h> 

//
#define SSD1306_MAX_ARGS 7
#define SSD1306_MAX_INFO 8

typedef struct SSD1306_comand SSD1306_comand;

/* Handler de comandos */
typedef bool (*ssd1306_handler_t)(SSD1306_comand *cmd,uint8_t *args);

struct SSD1306_comand
{
  char *cmd_name;
  // array de valores de argumento fijos.
  uint8_t cmd_fijo[SSD1306_MAX_ARGS];
  uint8_t size_cmd;
  // array de valores de argumento variable, bit a bit validos que ses puede disponer a variar.
  uint8_t arg_mask[SSD1306_MAX_ARGS];
  // array de valores de argumento variable, por defecto.
  uint8_t arg_default[SSD1306_MAX_ARGS];
  // array de valores de argumento variable, por actual.
  uint8_t arg_current[SSD1306_MAX_ARGS];
  // Tipo de intepretacion (select "2" o range "1").
  uint8_t arg_type[SSD1306_MAX_ARGS];
  // arreglo de cadena.
  char *arg_info[SSD1306_MAX_ARGS][SSD1306_MAX_INFO];
  // funcion para validaciones especiales.
  ssd1306_handler_t handler;
} ;

//es posible que nesecite un inizialize o contructro para validar la lista de SSD1306_comand;


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
extern const size_t SSD1306_cmd_list_len;

// metodo de structs
// crea un array de comando con los argumento fijo y variable juntos
// se superpone el array fijo y variables
void array_combinado_fijo_args(SSD1306_comand SSD1306_cmd, uint8_t i, uint8_t *array);

uint8_t Check_Arg_variable(SSD1306_comand SSD1306_cmd,uint8_t Args_bit[7]);

void reset_Args_List_Cmd(SSD1306_comand *SSD1306_cmd);

#endif /* SSD1306_CMD_H */