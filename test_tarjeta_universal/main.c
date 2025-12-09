#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "SSD1306.h"

int main(void)
{
    
    uint8_t buffer_full_tx[256];
    uint16_t buffer_full_tx_len = 256;

    memset(buffer_full_tx, 0, sizeof(buffer_full_tx));

    FrameCmdAddBitContinue(buffer_full_tx, &buffer_full_tx_len);

    for (size_t i = 0; i < buffer_full_tx_len; i++)
    {
        printf("%02x ",buffer_full_tx[i] );
    }

    uint8_t Args_bit[7] = {0xAE};
    
    
    printf("\n\n\n%d",Check_Arg_variable(SSD1306_cmd_list[3],Args_bit));


    return 0;
}