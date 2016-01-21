Project:      output/opticalEncoder_LCD_Display
Build Number: 0
Date:         Wed Jan 20 20:23:19 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   0083 =    131. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01AF  LoadConfigTBL_opticalencoder_lcd_display_Bank0
       01FE  LoadConfigTBL_opticalencoder_lcd_display_Bank1
       0223  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0223   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0223  __func_lit_start
       0225  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0225   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0225  LoadConfigTBL_opticalencoder_lcd_display_Ordered
       032A  LoadConfigInit
       032A  _LoadConfigInit
       033A  _LoadConfig_opticalencoder_lcd_display
       033A  LoadConfig_opticalencoder_lcd_display
       0395  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   0395   01B7 =    439. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0395  _LCD_PrCString
       0395  LCD_PrCString
       03A7  LCD_HEX_STR
       03B7  LCD_PrHexByte
       03B7  _LCD_PrHexByte
       03CA  _LCD_PrHexInt
       03CA  LCD_PrHexInt
       03D1  _LCD_PrString
       03D1  LCD_PrString
       03E3  _LCD_Write_Data
       03E3  _LCD_WriteData
       03E3  LCD_WriteData
       03E3  LCD_Write_Data
       03F7  LCD_Control
       03F7  _LCD_Control
       04A7  _LCD_Start
       04A7  _LCD_Init
       04A7  LCD_Init
       04A7  LCD_Start
       0516  LCD_ROW_OFFSET
       051A  LCD_Position
       051A  _LCD_Position
       052A  LCD_Delay50uTimes
       052A  _LCD_Delay50uTimes
       0530  LCD_Delay50u_Table
       0538  _LCD_Delay50u
       0538  LCD_Delay50u
       054C  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   054C   02B4 =    692. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       054C  _main
       054C  __text_start
       0627  _PSoC_GPIO_ISR_C
       06BD  _utoa
       0800  __text_end
       0800  __xidata_start
       0808  __xidata_end

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
               virtual_registers   0003   0007 =      7. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0003  __rZ
       0004  __rY
       0005  __rX
       0006  __r3
       0007  __r2
       0008  __r1
       0009  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0003 =      3. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       000A  _prev_A
       000B  _state
       000C  _prev_B

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ psocconfigtbl.asm, psocconfig.asm, lcd.asm, rZ.asm, rY.asm, rX.asm, r3.asm, r2.asm, r1.asm, r0.asm ]
[ divmodu_16x16_16_util.asm, i_div16_block_util.asm, utoa.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x3
-Bopticalencoder_lcd_display_RAM
-rwh:SSCParmBlk:0xf7.0xff

