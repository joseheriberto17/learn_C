/*
 * @file    SSD1306_cmd.c
 * @author  Jose Heriberto
 * @date    2025-12-08
 * @brief   Definición y validación de comandos para el controlador SSD1306 (Directo desde la documetacion).
 *
 * @details
 * Este archivo contiene:
 * - El arreglo de comandos por defecto del controlador SSD1306.
 * - La lista completa de comandos con sus argumentos fijos y variables.
 * - Funciones para:
 *   - Validar argumentos de comandos.
 *   - Restaurar valores por defecto.
 *   - Verificar argumentos nulos.
 *   - Combinar comandos fijos con argumentos dinámicos.
 *
 * Este módulo permite estructurar de forma segura el envío de comandos
 * hacia pantallas OLED basadas en el controlador SSD1306.
 *
 * @note
 * Soporta comandos con hasta 7 bytes de argumentos.
 */


#include "SSD1306_cmd.h"



// arreglo de los comando por defecto
const uint8_t SSD1306_cmd_default[] =
    {
        Set_Display_ON_OFF,
        Set_Multiplex_Ratio,
        Set_Display_Offset,
        Set_Display_Start_Line,
        Set_Segment_Remap,
        Set_COM_Output_Scan_Direction,
        Set_COM_Pins_Hardware_Configuration,
        Set_Contrast_Control,
        Entire_Display_ON,
        Set_N_I_Display,
        Set_Display_Clock_Divide_Ratio_and_OSC_Frequency,
        Charge_Pump_Command,
        Set_Display_ON_OFF
    };

const size_t SSD1306_cmd_default_len = sizeof(SSD1306_cmd_default)/sizeof(SSD1306_cmd_default[0]);

// declaracion de meta datos de  los comados de SSD1306
SSD1306_comand SSD1306_cmd_list[] = {
    {"Set_Contrast_Control", {0x81,0x00}, 2, {0x00,0xFF}, {0x00,0x7F}, {0x00,0x01}, {{"Valor del contraste"}}, NULL}, // llamado
    {"Entire_Display_ON", {0xA4}, 1, {0x01}, {0x00}, {0x02}, {{"Restaurar contenido RAM", "Ignorar contenido RAM"}}, NULL}, // llamado
    {"Set_N_I_Display", {0xA6}, 1, {0x01}, {0x00}, {0x02}, {{"Display Normal","Display Invertido"}}, NULL}, // llamado
    {"Set_Display_ON_OFF", {0xAE}, 1, {0x01}, {0x00}, {0x02}, {{"Display Encendido","Display Apagado"}}, NULL}, // llamado
    {"Continuous_Horizontal_Scroll", {0x26,0x00,0x00,0x00,0x00,0x00,0xFF}, 7, {0x01,0x00,0x07,0x07,0x07,0x00,0x00}, {0x00,0x00,0x00,0x00,0x07,0x00,0x00}, {0x02,0x00,0x01,0x02,0x01,0x00,0x00} , {{"Null","Scroll Derecha Horizontal","Scroll Izquierda Horizontal","NULL"},{"Definir paguina inicio"},{"5 frames","64 frames","128 frames","256 frames","3 frames","4 frames","25 frames","8 frames"},{"Definir paguina final"}}, NULL },
    {"Continuous_Vertical_and_Horizontal_Scroll", {0x29,0x00,0x00,0x00,0x00,0x00}, 6, {0x03,0x00,0x07,0x07,0x07,0x3F}, {0x00,0x00,0x00,0x00,0x07,0x00}, {0x02,0x00,0x01,0x01,0x01,0x01}, {{"Null","Scroll Derecha Horizontal","Scroll Izquierda Horizontal","NULL"},{"Definir paguina inicio"},{"5 frames","64 frames","128 frames","256 frames","3 frames","4 frames","25 frames","8 frames"},{"Definir paguina final"}}, NULL},
    {"Deactivate_Scroll", {0x2E}, 1, {0x00}, {0x00}, {0x00}, {{"NULL"}}, NULL},
    {"Activate_Scroll", {0x2F}, 1, {0x00}, {0x00}, {0x00}, {{"NULL"}}, NULL},
    {"Set_Vertical_Scroll_Area", {0xA3,0x00,0x00}, 3, {0x00,0x3F,0x7F}, {0x00,0x00,0x40}, {0x00,0x01,0x01}, {{"Numero de filas en un area fija"},{"Numero de columnas en un area fija"}}, NULL},
    {"Set_Lower_Column_Start_Address_for_Page_Addressing_Mode", {0x00}, 1, {0x0F}, {0x00}, {0x01}, {{"Nibble bajo de la colmuna de direccion de inicio"}}, NULL},
    {"Set_High_Column_Start_Address_for_Page_Addressing_Mode", {0x10}, 1, {0x0F}, {0x00}, {0x01}, {{"Nibble alto de la colmuna de direccion de inicio"}}, NULL},
    {"Set_Memory_Addressing_Mode", {0x20,0x00}, 2, {0x00,0x03}, {0x00,0x02}, {0x00,0x02}, {{"Horizontal Addressing Mode","Vertical Addressing Mode","Page Addressing Mode","Invalid"}}, NULL},
    {"Set_Column_Address", {0x21,0x00,0x00}, 3, {0x00,0x7F,0x7F}, {0x00,0x00,0x7F}, {0x00,0x01,0x01}, {{"Column start address"},{"Column end address"}}, NULL},
    {"Set_Page_Address", {0x22,0x00,0x00}, 3, {0x00,0x07,0x07}, {0x00,0x00,0x07},{0x00,0x01,0x01}, {{"Page start Address"},{"Page end Address"}}, NULL},
    {"Set_Page_Start_Address_for_Page_Addressing_Mode", {0xB0}, 1, {0x07}, {0x00}, {0x01}, {{"GDDRAM Page Start Address"}}, NULL},
    {"Set_Display_Start_Line", {0x40}, 1, {0x3F}, {0x00}, {0x01}, {{"Set display RAM start line"}}, NULL}, // llamado 
    {"Set_Segment_Remap", {0xA0}, 1, {0x01}, {0x00}, {0x02}, {{"column address 0 is mapped to SEG0","column address 0 is mapped to SEG0"}}, NULL}, // llamado
    {"Set_Multiplex_Ratio", {0xA8,0x00}, 2, {0x00,0x3F}, {0x00,0x3F}, {0x01}, {{"Set MUX ratio to N+1 MUX"}}, NULL}, // llamado
    {"Set_COM_Output_Scan_Direction", {0xC0}, 1, {0x08}, {0x00}, {0x02}, {{"modo normal","modo remapeado"}}, NULL}, // llamado
    {"Set_Display_Offset", {0xD3,0x00}, 2, {0x00,0x3F}, {0x00,0x00}, {0x00,0x01}, {{"Set vertical shift by COM from 0d-63d"}}, NULL}, // llamado
    {"Set_COM_Pins_Hardware_Configuration", {0xDA,0x02}, 2, {0x00,0x30}, {0x00,0x20}, {0x00,0x02}, {{"Sequential COM","Alternative COM","Disable COM Left/Right remap","Enable COM Left/Right remap"}}, NULL}, // llamado
    {"Set_Display_Clock_Divide_Ratio_and_OSC_Frequency", {0xD5,0x00}, 2, {0x00,0xFF}, {0x00,0x80}, {0x00,0x01}, {{"A[3:0] : Define the divide ratio A[7:4] : Set the Oscillator Frequency"}}, NULL}, // llamado
    {"Set_Precharge_Period", {0xD9,0x00}, 2, {0x00,0xFF}, {0x00,0x22}, {0x00,0x01}, {{" A[3:0] : Phase 1 period clocks (1-15) A[7:4] : Phase 2 period clocks"}}, NULL},
    {"Charge_Pump_Command", {0x8D,0x10}, 2, {0x00,0x04}, {0x00,0x10}, {0x00,0x02}, {{"Disable charge pump","Enable charge pump"}}, NULL} // llamado
};

const size_t SSD1306_cmd_list_len = sizeof(SSD1306_cmd_list);
// ----------------------------------Constructor-----------------------------------------

// void SSD1306_comand_init()
// {
//  for (size_t i = 0; i < SSD1306_cmd_list_len; i++)
//  {
//     SSD1306_cmd_list[0].
//  }
// }



// --------------------------------- Validacion -----------------------------------------
// valida el arreglo de bytes cumple las condiciones.
uint8_t Check_Arg_variable(SSD1306_comand SSD1306_cmd,uint8_t Args_bit[7])
{
    uint8_t Check_Array[7];

    for (size_t i = 0; i < 7; i++)
    {
        Check_Array[i] = ((SSD1306_cmd.cmd_fijo[i]^Args_bit[i])| SSD1306_cmd.arg_mask[i] );

        if (Check_Array[i] != SSD1306_cmd.arg_mask[i])
        {
            return 1;
        }
    }
    return 0;
}
// ----------------------------- Funciones especiales ---------------------------------------

// bool Continuous_Horizontal_Scroll_handler (SSD1306_comand *cmd,uint8_t *args)
// {
//     if(args[2] <= args[4])
//     {
//         return true;
//     }
//     return false;
// }

// bool Continuous_Vertical_Horizontal_Scroll(SSD1306_comand *cmd,uint8_t *args)
// {
//     if(cmd->arg_current[2] <= cmd->arg_current[4])
//     {
//         return true;
//     }
//     return false;
// }

// bool Scroll(SSD1306_comand *cmd,uint8_t *args)
// {
//     for (uint8_t i = 0; i < 4; i++)
//     {
//         if (args[i] != 0x00)
//         {
//             return false;
//         }
//     }
//     return false;
// }

// bool Vertical_Scroll_Area(SSD1306_comand *cmd,uint8_t *args)
// { 
    
//     // args[1] -- Set Multiplex Ratio  0xA8    
//     if(cmd->arg_current[1] + cmd->arg_current[2] <= args[0])
//     {
//         return true;
//     }

//     // args[5] -- Continuous Vertical and Horizontal Scroll Setup 29/2A 
//     if( args[1] < cmd->arg_current[2] )
//     {
//         return true;
//     }

//     // args[0] -- Set Display Start Line
//     if( args[2] < cmd->arg_current[2] )
//     {
//         return true;
//     }
//     return false;
// }

// --------------------------------- Otras acciones -----------------------------------------

// revierte por defecto de los argumento variables de un cmd.
// void reset_Args_List_Cmd(SSD1306_comand *SSD1306_cmd)
// {
//     memcpy(SSD1306_cmd->arg_current,SSD1306_cmd->arg_default,7);      
// }

// devuelve un solo comando combinado sus argumento fijo y variables (defecto) en un array de 7 bits
void array_args_cmd_init(SSD1306_comand SSD1306_cmd,uint8_t i,uint8_t *array)
{
  for (size_t j = 0; j < 7; j++)
    {
      array[j] = SSD1306_cmd.cmd_fijo[j] | SSD1306_cmd.arg_default[j];
    }
}  