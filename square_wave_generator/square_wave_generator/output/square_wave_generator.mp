Project:      output/square_wave_generator
Build Number: 0
Date:         Thu Jan 28 14:11:03 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   00B2 =    178. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01BA  LoadConfigTBL_opticalencoder_lcd_display_Bank0
       021B  LoadConfigTBL_opticalencoder_lcd_display_Bank1
       0252  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0252   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0252  __func_lit_start
       0254  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0254   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0254  LoadConfigTBL_opticalencoder_lcd_display_Ordered
       0359  LoadConfigInit
       0359  _LoadConfigInit
       0369  _LoadConfig_opticalencoder_lcd_display
       0369  LoadConfig_opticalencoder_lcd_display
       03C4  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   03C4   0218 =    536. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03C4  LCD_PrCString
       03C4  _LCD_PrCString
       03D6  LCD_HEX_STR
       03E6  _LCD_PrHexByte
       03E6  LCD_PrHexByte
       03F9  _LCD_PrHexInt
       03F9  LCD_PrHexInt
       0400  _LCD_PrString
       0400  LCD_PrString
       0412  _LCD_WriteData
       0412  _LCD_Write_Data
       0412  LCD_Write_Data
       0412  LCD_WriteData
       0426  LCD_Control
       0426  _LCD_Control
       04D6  _LCD_Init
       04D6  LCD_Init
       04D6  _LCD_Start
       04D6  LCD_Start
       0545  LCD_ROW_OFFSET
       0549  LCD_Position
       0549  _LCD_Position
       0559  LCD_Delay50uTimes
       0559  _LCD_Delay50uTimes
       055F  LCD_Delay50u_Table
       0567  _LCD_Delay50u
       0567  LCD_Delay50u
       057B  _Counter16_ISR
       057C  Counter16_EnableInt
       057C  _Counter16_EnableInt
       0580  _Counter16_DisableInt
       0580  Counter16_DisableInt
       0584  Counter16_Start
       0584  _Counter16_Start
       0588  Counter16_Stop
       0588  _Counter16_Stop
       058C  Counter16_WritePeriod
       058C  _Counter16_WritePeriod
       0592  Counter16_WriteCompareValue
       0592  _Counter16_WriteCompareValue
       0598  wCounter16_ReadCompareValue
       0598  Counter16_wReadCompareValue
       0598  _wCounter16_ReadCompareValue
       0598  _Counter16_wReadCompareValue
       059E  Counter16_wReadCounter
       059E  wCounter16_ReadCounter
       059E  _Counter16_wReadCounter
       059E  _wCounter16_ReadCounter
       05DC  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   05DC   1526 =   5414. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       05DC  _main
       05DC  __text_start
       0A7C  _PSoC_GPIO_ISR_C
       0AEE  _PSoC_DigBuf_ISR_C
       10B5  _ltoa
       132E  _ftoa
       177D  _frexpf
       1853  _logf
       1B02  __xidata_start
       1B02  __text_end
       1B0C  __xidata_end

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
               virtual_registers   0012   000B =     11. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0012  __rZ
       0013  __rY
       0014  __rX
       0015  __r7
       0016  __r6
       0017  __r5
       0018  __r4
       0019  __r3
       001A  __r2
       001B  __r1
       001C  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0015 =     21. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       001D  _state
       001F  _errno
       0021  _prev_A
       0022  _prev_B

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ psocconfigtbl.asm, psocconfig.asm, lcd.asm, counter16int.asm, counter16.asm, rZ.asm, rY.asm, rX.asm ]
[ r7.asm, r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmodu_32x32_32_util.asm, fp2long_util.asm ]
[ fp_analysiseject_util.asm, fp_clrreg_util.asm, fp_nan_res_util.asm, fp_saveres_util.asm ]
[ fp_sendtoreg_util.asm, fp_sinf_res_util.asm, fp_szero_res_util.asm, fp_type_oprnd_util.asm ]
[ fp_unnormal_util.asm, fpadd_util.asm, fpcmp_util.asm, fpdiv_util.asm, fpmul_util.asm, fpsub_util.asm ]
[ i_div32_block_util.asm, i_div32_not_util.asm, i_mulu8_block_util.asm, long2fp_util.asm ]
[ ltoa.s, ftoa.s, frexpf.s, logf.s, errno.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x12
-Bopticalencoder_lcd_display_RAM
-rwh:SSCParmBlk:0xf7.0xff

