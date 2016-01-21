Project:      output/datasheet_lcd_display
Build Number: 0
Date:         Sun Jan 17 11:52:56 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   007D =    125. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01A9  LoadConfigTBL_datasheet_lcd_display_Bank0
       01F8  LoadConfigTBL_datasheet_lcd_display_Bank1
       021D  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   021D   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       021D  __func_lit_start
       021F  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   021F   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       021F  LoadConfigTBL_datasheet_lcd_display_Ordered
       0324  _LoadConfigInit
       0324  LoadConfigInit
       0334  _LoadConfig_datasheet_lcd_display
       0334  LoadConfig_datasheet_lcd_display
       038F  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   038F   01B7 =    439. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       038F  _LCD_PrCString
       038F  LCD_PrCString
       03A1  LCD_HEX_STR
       03B1  LCD_PrHexByte
       03B1  _LCD_PrHexByte
       03C4  _LCD_PrHexInt
       03C4  LCD_PrHexInt
       03CB  _LCD_PrString
       03CB  LCD_PrString
       03DD  _LCD_Write_Data
       03DD  _LCD_WriteData
       03DD  LCD_WriteData
       03DD  LCD_Write_Data
       03F1  LCD_Control
       03F1  _LCD_Control
       04A1  _LCD_Start
       04A1  _LCD_Init
       04A1  LCD_Init
       04A1  LCD_Start
       0510  LCD_ROW_OFFSET
       0514  LCD_Position
       0514  _LCD_Position
       0524  LCD_Delay50uTimes
       0524  _LCD_Delay50uTimes
       052A  LCD_Delay50u_Table
       0532  _LCD_Delay50u
       0532  LCD_Delay50u
       0546  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0546   0048 =     72. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0546  __text_start
       0546  _main
       058E  __xidata_start
       058E  __text_end
       0590  __xidata_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             TOP   0000   0143 =    323. bytes (abs,ovr,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0068  __Start
       0140  _bGetPowerSetting
       0140  bGetPowerSetting

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                    InterruptRAM   0000   0003 =      3. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  _NO_SHADOW
       0000  Port_2_Data_SHADE
       0000  NO_SHADOW
       0000  _Port_2_Data_SHADE
       0001  _Port_2_DriveMode_0_SHADE
       0001  Port_2_DriveMode_0_SHADE
       0002  _Port_2_DriveMode_1_SHADE
       0002  Port_2_DriveMode_1_SHADE

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0003   0004 =      4. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0003  __rX
       0004  __r3
       0005  __r1
       0006  __r0

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ psocconfigtbl.asm, psocconfig.asm, lcd.asm, rX.asm, r3.asm, r1.asm, r0.asm ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x3
-Bdatasheet_lcd_display_RAM
-rwh:SSCParmBlk:0xf7.0xff

