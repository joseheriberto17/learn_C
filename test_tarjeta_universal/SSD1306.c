/*
 * @file    SSD1306.c
 * @author  Jose Heriberto
 * @date    2025-12-08
 * @brief   Definición y validación de comandos para el controlador SSD1306 (Directo desde la documetacion).
 *
 * @details
 * Este archivo contiene:
 *  - funcion de comando por defecto que se puedad modificar
 *  - funcion adicional despues  inicializar el comando
 * 
 *
 * @note
 * Soporta comandos con hasta 7 bytes de argumentos.
 */

#include "SSD1306.h"

// inicializa una lista de los comando por defecto mediante una lista de arreglo.
// donde son 7 bytes de argumento cmd, el octavo define el tamaño de cmd.
void list_array_args_cmd_init(uint8_t (*buf_tx)[8], uint8_t buf_size)
{
  for (size_t i = 0; i < SSD1306_cmd_default_len; i++)
  {
    uint8_t array[7];
    // comando combinado sus argumento fijo y variables (defecto) en un array de 7 bits 
    array_args_cmd_init(SSD1306_cmd_list[SSD1306_cmd_default[i]], i, array);

    memcpy(buf_tx[i], array, 7);
    // se adiciiona columan adicional que define el size de cada comando.
    buf_tx[i][7] = SSD1306_cmd_list[SSD1306_cmd_default[i]].size_cmd;
    memset(array, 0, sizeof(array));
  }
}

// alistamiento de los comando via I2C
void FrameCmdAddBitContinue(uint8_t *buf_tx, uint16_t *buf_size)
{
  uint8_t buffer_full_tx[32][8];
  uint8_t buffer_full_tx_len_rows = 32;
  uint8_t buffer_full_tx_len_cols = 8;
  uint16_t Counter = 0;

  memset(buffer_full_tx, 0, sizeof(buffer_full_tx));
  list_array_args_cmd_init(buffer_full_tx, buffer_full_tx_len_rows);

  // debug arreglo de comandos
  //----------------------------------------------------
  for (size_t i = 0; i < SSD1306_cmd_default_len; i++)
  {
    for (size_t j = 0; j < buffer_full_tx[i][7]; j++)
    {
      printf("%02x ", buffer_full_tx[i][j]);
    }

    for (size_t j = 0; j < buffer_full_tx[i][7]; j++)
    {
      // string (comando llamado)
    }
    // ejemplo
    // valor
    // 1 1 1 1 1 x x x

    printf("\n");
  }
  printf("\n");
  printf("\n");
  //----------------------------------------------------

  // tramos de comandos i2c con el byte de continuacion.
  for (size_t i = 0; i < SSD1306_cmd_default_len; i++)
  {
    for (size_t j = 0; j < buffer_full_tx[i][buffer_full_tx_len_cols - 1]; j++)
    {
      buf_tx[Counter++] = 0x80;
      buf_tx[Counter++] = buffer_full_tx[i][j];
    }
    // printf("\n");
  }
  buf_tx[Counter++] = 0x00;
  *buf_size = Counter;
}