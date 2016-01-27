Project:      output/SquareWaveGenerator
Build Number: 0
Date:         Tue Jan 26 22:04:53 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   00B3 =    179. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01BB  LoadConfigTBL_opticalencoder_lcd_display_Bank0
       021C  LoadConfigTBL_opticalencoder_lcd_display_Bank1
       0253  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0253   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0253  __func_lit_start
       0255  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0255   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0255  LoadConfigTBL_opticalencoder_lcd_display_Ordered
       035A  LoadConfigInit
       035A  _LoadConfigInit
       036A  _LoadConfig_opticalencoder_lcd_display
       036A  LoadConfig_opticalencoder_lcd_display
       03C5  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   03C5   0218 =    536. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03C5  LCD_PrCString
       03C5  _LCD_PrCString
       03D7  LCD_HEX_STR
       03E7  _LCD_PrHexByte
       03E7  LCD_PrHexByte
       03FA  _LCD_PrHexInt
       03FA  LCD_PrHexInt
       0401  _LCD_PrString
       0401  LCD_PrString
       0413  _LCD_WriteData
       0413  _LCD_Write_Data
       0413  LCD_Write_Data
       0413  LCD_WriteData
       0427  LCD_Control
       0427  _LCD_Control
       04D7  _LCD_Init
       04D7  LCD_Init
       04D7  _LCD_Start
       04D7  LCD_Start
       0546  LCD_ROW_OFFSET
       054A  LCD_Position
       054A  _LCD_Position
       055A  LCD_Delay50uTimes
       055A  _LCD_Delay50uTimes
       0560  LCD_Delay50u_Table
       0568  _LCD_Delay50u
       0568  LCD_Delay50u
       057C  _Counter16_ISR
       057D  Counter16_EnableInt
       057D  _Counter16_EnableInt
       0581  _Counter16_DisableInt
       0581  Counter16_DisableInt
       0585  Counter16_Start
       0585  _Counter16_Start
       0589  Counter16_Stop
       0589  _Counter16_Stop
       058D  Counter16_WritePeriod
       058D  _Counter16_WritePeriod
       0593  Counter16_WriteCompareValue
       0593  _Counter16_WriteCompareValue
       0599  wCounter16_ReadCompareValue
       0599  Counter16_wReadCompareValue
       0599  _wCounter16_ReadCompareValue
       0599  _Counter16_wReadCompareValue
       059F  Counter16_wReadCounter
       059F  wCounter16_ReadCounter
       059F  _Counter16_wReadCounter
       059F  _wCounter16_ReadCounter
       05DD  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   05DD   1489 =   5257. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       05DD  _main
       05DD  __text_start
       097D  _PSoC_GPIO_ISR_C
       0A25  _PSoC_DigBuf_ISR_C
       0FF3  _strlenLMM
       0FFE  _strlen
       1019  _ltoa
       1292  _ftoa
       16E1  _frexpf
       17B7  _logf
       1A66  __xidata_start
       1A66  __text_end
       1A70  __xidata_end

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
                            data   0000   0014 =     20. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       001D  _errno
       001F  _state
       0020  _prev_A
       0021  _prev_B

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ psocconfigtbl.asm, psocconfig.asm, lcd.asm, counter16int.asm, counter16.asm, rZ.asm, rY.asm, rX.asm ]
[ r7.asm, r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmodu_32x32_32_util.asm, fp2long_util.asm ]
[ fp_analysiseject_util.asm, fp_clrreg_util.asm, fp_nan_res_util.asm, fp_saveres_util.asm ]
[ fp_sendtoreg_util.asm, fp_sinf_res_util.asm, fp_szero_res_util.asm, fp_type_oprnd_util.asm ]
[ fp_unnormal_util.asm, fpadd_util.asm, fpcmp_util.asm, fpdiv_util.asm, fpmul_util.asm, fpsub_util.asm ]
[ i_div32_block_util.asm, i_div32_not_util.asm, i_mulu8_block_util.asm, long2fp_util.asm ]
[ strlen.s, ltoa.s, ftoa.s, frexpf.s, logf.s, errno.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x12
-Bopticalencoder_lcd_display_RAM
-rwh:SSCParmBlk:0xf7.0xff

