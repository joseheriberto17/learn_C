classDiagram
    class SSD1306_comand {
        +char str_cmd[64]
        +uint8_t cmd_fijo[7]
        +uint8_t size_cmd
        +uint8_t cmd_Args_bit[7]
        +uint8_t cmd_Args[7]
        +uint8_t cmd_Args_current[7]
        +array_combinado_fijo_args()
        +Check_Arg_variable()
        +reset_Args_List_Cmd()
        +check_Args_Current_zeros()
    }

    class SSD1306_cmd_enum {
        <<enumeration>>
        Set_Contrast_Control
        Entire_Display_ON
        Set_N_I_Display
        Set_Display_ON_OFF
        Continuous_Horizontal_Scroll
        Continuous_Vertical_and_Horizontal_Scroll
        Deactivate_Scroll
        Activate_Scroll
        Set_Vertical_Scroll_Area
        Set_Lower_Column_Start_Address_for_Page_Addressing_Mode
        Set_High_Column_Start_Address_for_Page_Addressing_Mode
        Set_Memory_Addressing_Mode
        Set_Column_Address
        Set_Page_Address
        Set_Page_Start_Address_for_Page_Addressing_Mode
        Set_Display_Start_Line
        Set_Segment_Remap
        Set_Multiplex_Ratio
        Set_COM_Output_Scan_Direction
        Set_Display_Offset
        Set_COM_Pins_Hardware_Configuration
        Set_Display_Clock_Divide_Ratio_and_OSC_Frequency
        Set_Precharge_Period
        Charge_Pump_Command
    }

    SSD1306_comand --> SSD1306_cmd_enum : usa
    SSD1306_comand --> "lista[]" SSD1306_comand : contiene
