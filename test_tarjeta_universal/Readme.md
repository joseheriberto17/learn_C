### Archivo SSD1306_cmd
* ofrece una lista de todo los comandos disponibles con la misma clase, al estilo de metadatos.
* describe a bajo nivel, directamente desde el datasheet el compotamiento de un comando dado.
* contiene funciones que permite validar si un comando dado es valido (revisa argumentos fijo y variables).

```c

// enum de todos los comando en orden del  datasheet
typedef enum SSD1306_cmd_enum

// arreglo de los comando por defecto
const uint8_t SSD1306_cmd_default[]
const size_t SSD1306_cmd_default_len 

// declaracion de meta datos de  los comados de SSD1306
SSD1306_comand SSD1306_cmd_list[]
const size_t SSD1306_cmd_list_len

// STRUCTS
typedef struct SSD1306_comand;

// METODOS
// --------------------------------- Validacion -----------------------------------------
// determina si todo el arreglo de  comando actual son 0x00
bool check_Args_Current_zeros(SSD1306_comand SSD1306_cmd)
// valida el arreglo de bytes cumple las condiciones.
uint8_t Check_Arg_variable(SSD1306_comand SSD1306_cmd,uint8_t Args_bit[7])
// --------------------------------- Otras acciones -----------------------------------------
// revierte por defecto de los argumento variables de un cmd.
void reset_Args_List_Cmd(SSD1306_comand *SSD1306_cmd)
void array_combinado_fijo_args(SSD1306_comand SSD1306_cmd,uint8_t i,uint8_t *array)


//--------------------------------------- SSD1306----------------------------------------------------------
// --------------------------------------------------------------------------------------------------------

void CreateArrayCmdDefault(uint8_t (*buf_tx)[8], uint8_t buf_size)
// alistamiento de los comando via I2C
void FrameCmdAddBitContinue(uint8_t *buf_tx, uint16_t *buf_size)

```

hay dos caminos
* struct SSD1306_comand tenga un atributo Args_currrent o si ella 


### Archivo SSD1306
<!-- Interpretacion de los comando de las acciones que realiza. -->
* construccion de los comando para el tramos

```C

void CreateArrayCmdDefault(uint8_t (*buf_tx)[8], uint8_t buf_size)
// alistamiento de los comando via I2C
void FrameCmdAddBitContinue(uint8_t *buf_tx, uint16_t *buf_size)

```