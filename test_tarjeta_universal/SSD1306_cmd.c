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
    {"Set_Contrast_Control", {0x81,0x00}, 2, {0x00,0xFF}, {0x00,0x7F}},
    {"Entire_Display_ON", {0xA4}, 1, {0x01}, {0xA4}},
    {"Set_N_I_Display", {0xA6}, 1, {0x01}, {0xA6}},
    {"Set_Display_ON_OFF", {0xAE}, 1, {0x01}, {0xAE}},
    {"Continuous_Horizontal_Scroll", {0x26,0x00,0x00,0x00,0x00,0x00,0xFF}, 7,
        {0x01,0x00,0x07,0x07,0x07,0x00,0x00},
        {0x00,0x00,0x00,0x00,0x07,0x00,0x00}},
    {"Continuous_Vertical_and_Horizontal_Scroll", {0x29,0x00,0x00,0x00,0x00,0x00,0x00}, 7,
        {0x03,0x00,0x03,0x03,0x03,0x07,0x00},
        {0x00,0x00,0x00,0x00,0x07,0x00,0x00}},
    {"Deactivate_Scroll", {0x2E}, 1, {0x00}, {0x00}},
    {"Activate_Scroll", {0x2F}, 1, {0x00}, {0x00}},
    {"Set_Vertical_Scroll_Area", {0xA3,0x00,0x00}, 3, {0x00,0x3F,0x7F}, {0x00,0x00,0x00}},
    {"Set_Lower_Column_Start_Address_for_Page_Addressing_Mode", {0x00}, 1, {0x0F}, {0x00}},
    {"Set_High_Column_Start_Address_for_Page_Addressing_Mode", {0x10}, 1, {0x1F}, {0x10}},
    {"Set_Memory_Addressing_Mode", {0x20,0x00}, 2, {0x00,0x03}, {0x00,0x02}},
    {"Set_Column_Address", {0x21,0x00,0x00}, 3, {0x00,0x7F,0x7F}, {0x00,0x00,0x7F}},
    {"Set_Page_Address", {0x22,0x00,0x00}, 3, {0x00,0x07,0x07}, {0x00,0x00,0x07}},
    {"Set_Page_Start_Address_for_Page_Addressing_Mode", {0xB0}, 1, {0x07}, {0x00}},
    {"Set_Display_Start_Line", {0x40}, 1, {0x3F}, {0x00}},
    {"Set_Segment_Remap", {0xA0}, 1, {0x01}, {0x00}},
    {"Set_Multiplex_Ratio", {0xA8,0x00}, 2, {0x00,0x3F}, {0x00,0x3F}},
    {"Set_COM_Output_Scan_Direction", {0xC0}, 1, {0x08}, {0x00}},
    {"Set_Display_Offset", {0xD3,0x00}, 2, {0x00,0x3F}, {0x00,0x00}},
    {"Set_COM_Pins_Hardware_Configuration", {0xDA,0x00}, 2, {0x00,0xFF}, {0x00,0x18}},
    {"Set_Display_Clock_Divide_Ratio_and_OSC_Frequency", {0xD5,0x00}, 2, {0x00,0xFF}, {0x00,0x80}},
    {"Set_Precharge_Period", {0xD9,0x00}, 2, {0x00,0xFF}, {0x00,0x22}},
    {"Charge_Pump_Command", {0x8D,0x10}, 2, {0x00,0x04}, {0x00,0x10}}
};

const size_t SSD1306_cmd_list_len = sizeof(SSD1306_cmd_list)/sizeof(SSD1306_cmd_list[0]);

// --------------------------------- Validacion -----------------------------------------
// determina si todo el arreglo de  comando actual son 0x00
bool check_Args_Current_zeros(SSD1306_comand SSD1306_cmd)
{
    uint8_t Counter = 0;
    for (uint8_t i = 0; i < 7; i++)
    {
        if(SSD1306_cmd.cmd_Args_current[i] == 0)
        {
            Counter++;
        }
        if(Counter == 7)
        {
            return false;
        }
    }
    return true;
}

// valida el arreglo de bytes cumple las condiciones.
uint8_t Check_Arg_variable(SSD1306_comand SSD1306_cmd,uint8_t Args_bit[7])
{
    uint8_t Check_Array[7];

    for (size_t i = 0; i < 7; i++)
    {
        Check_Array[i] = ((SSD1306_cmd.cmd_fijo[i]^Args_bit[i])| SSD1306_cmd.cmd_Args_bit[i] );

        if (Check_Array[i] != SSD1306_cmd.cmd_Args_bit[i])
        {
            return 1;
        }
    }
    return 0;
}

// --------------------------------- Otras acciones -----------------------------------------

// revierte por defecto de los argumento variables de un cmd.
void reset_Args_List_Cmd(SSD1306_comand *SSD1306_cmd)
{
    memcpy(SSD1306_cmd->cmd_Args_current,SSD1306_cmd->cmd_Args,7);      
}

// devuelve un solo comando combinado sus argumento fijo y variables en un array de 7 bits
void array_combinado_fijo_args(SSD1306_comand SSD1306_cmd,uint8_t i,uint8_t *array)
{
  for (size_t j = 0; j < 7; j++)
    {
      array[j] = SSD1306_cmd.cmd_fijo[j] | SSD1306_cmd.cmd_Args[j];
    }
}  