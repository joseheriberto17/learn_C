// esto es un comentario

/*
    comentarios multilinea
*/

// directiva del preprocesador
// estándar de entrada/salida
// printf
#include <stdio.h>


typedef struct 
{
    char str_cmd[64];
    __uint8_t Count_Args;
    __uint8_t Args[7];
}name_cmd;
           
name_cmd str_cmd_name[] = 
{
    {"Set_Display_ON_OFF",2},
    {"Set_Multiplex_Ratio",1},
    {"Set_Display_Offset",1},
    {"Set_Display_Start_Line",1},
    {"Set_Segment_Remap",1},
    {"Set_COM_Output_Scan_Direction",1},
    {"Set_COM_Pins_Hardware_Configuration",1},
    {"Set_Contrast_Control",1},
    {"Entire_Display_ON",1},
    {"Set_N_I_Display",1},
    {"Set_Display_Clock_Divide_Ratio_and_OSC_Frequency",1},
    {"Charge_Pump_Command",1}
};

// funcion principal
int main()
{

    
    for (size_t i = 0; i < 12; i++)
    {
        printf("%50s",str_cmd_name[i].str_cmd);

        if (str_cmd_name[i].Count_Args == 1)
        {
            printf("()\n");
        }
        
    }
    
    return 0;    
}