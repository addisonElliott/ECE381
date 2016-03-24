Project:      output/WirelessTemperature
Build Number: 0
Date:         Wed Mar 23 10:30:36 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   00A9 =    169. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01B1  LoadConfigTBL_wirelesstemperature_Bank0
       021E  LoadConfigTBL_wirelesstemperature_Bank1
       0249  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0249   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0249  __func_lit_start
       024B  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   024B   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       024B  LoadConfigTBL_wirelesstemperature_Ordered
       0350  _LoadConfigInit
       0350  LoadConfigInit
       0360  _LoadConfig_wirelesstemperature
       0360  LoadConfig_wirelesstemperature
       03BB  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   03BB   03F1 =   1009. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03BB  _SleepTimer_ISR
       03DB  SleepTimer_EnableInt
       03DB  _SleepTimer_EnableInt
       03DF  SleepTimer_DisableInt
       03DF  _SleepTimer_DisableInt
       03E3  _SleepTimer_Start
       03E3  SleepTimer_Start
       03F7  SleepTimer_Stop
       03F7  _SleepTimer_Stop
       03F8  _SleepTimer_SetInterval
       03F8  SleepTimer_SetInterval
       040E  SleepTimer_TickWait
       040E  _SleepTimer_TickWait
       0420  SleepTimer_SyncWait
       0420  _SleepTimer_SyncWait
       0431  SleepTimer_bGetTickCntr
       0431  _SleepTimer_bGetTickCntr
       0437  _SleepTimer_SetTimer
       0437  SleepTimer_SetTimer
       043D  _SleepTimer_bGetTimer
       043D  SleepTimer_bGetTimer
       0443  SleepTimer_iGetTickCntr
       0443  _SleepTimer_iGetTickCntr
       0451  SleepTimer_lGetTickCntr
       0451  _SleepTimer_lGetTickCntr
       0475  _PGA_Start
       0475  _PGA_SetPower
       0475  PGA_Start
       0475  PGA_SetPower
       0487  _PGA_SetGain
       0487  PGA_SetGain
       04B1  PGA_Stop
       04B1  _PGA_Stop
       04B5  LCD_PrCString
       04B5  _LCD_PrCString
       04C7  LCD_HEX_STR
       04D7  _LCD_PrHexByte
       04D7  LCD_PrHexByte
       04EA  _LCD_PrHexInt
       04EA  LCD_PrHexInt
       04F1  LCD_PrString
       04F1  _LCD_PrString
       0503  _LCD_WriteData
       0503  LCD_Write_Data
       0503  LCD_WriteData
       0503  _LCD_Write_Data
       0517  LCD_Control
       0517  _LCD_Control
       05C7  _LCD_Start
       05C7  LCD_Start
       05C7  LCD_Init
       05C7  _LCD_Init
       0636  LCD_ROW_OFFSET
       063A  _LCD_Position
       063A  LCD_Position
       064A  LCD_Delay50uTimes
       064A  _LCD_Delay50uTimes
       0650  LCD_Delay50u_Table
       0658  LCD_Delay50u
       0658  _LCD_Delay50u
       066C  _ADCINC_ADConversion_ISR
       06EC  _ADCINC_Start
       06EC  ADCINC_Start
       0701  _ADCINC_SetPower
       0701  ADCINC_SetPower
       071D  _ADCINC_Stop
       071D  ADCINC_Stop
       072A  ADCINC_GetSamples
       072A  _ADCINC_GetSamples
       0759  ADCINC_StopADC
       0759  _ADCINC_StopADC
       0773  ADCINC_fIsDataAvailable
       0773  _ADCINC_fIsDataAvailable
       0779  ADCINC_iClearFlagGetData
       0779  _ADCINC_wClearFlagGetData
       0779  _ADCINC_iClearFlagGetData
       0779  ADCINC_wClearFlagGetData
       0789  ADCINC_cClearFlagGetData
       0789  ADCINC_bClearFlagGetData
       0789  _ADCINC_bClearFlagGetData
       0789  _ADCINC_cClearFlagGetData
       0792  ADCINC_wGetData
       0792  ADCINC_iGetData
       0792  _ADCINC_wGetData
       0792  _ADCINC_iGetData
       079A  ADCINC_bGetData
       079A  _ADCINC_bGetData
       079A  ADCINC_cGetData
       079A  _ADCINC_cGetData
       07A0  ADCINC_fClearFlag
       07A0  _ADCINC_fClearFlag
       07A9  _ADCINC_WritePulseWidth
       07A9  ADCINC_WritePulseWidth
       07AC  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   07AC   0B39 =   2873. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       07AC  _main
       07AC  __text_start
       0C1D  _ltoa
       0E96  _ftoa
       12E5  __xidata_start
       12E5  __text_end
       12EB  __xidata_end

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
                    InterruptRAM   0000   0012 =     18. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  SleepTimer_fTick
       0000  _SleepTimer_fTick
       0001  SleepTimer_bTimerValue
       0001  _SleepTimer_bTimerValue
       0002  SleepTimer_bCountDown
       0002  _SleepTimer_bCountDown
       0003  _SleepTimer_TickCount
       0003  SleepTimer_TickCount
       0007  NO_SHADOW
       0007  Port_2_Data_SHADE
       0007  _Port_2_Data_SHADE
       0007  _NO_SHADOW
       0008  _Port_2_DriveMode_0_SHADE
       0008  Port_2_DriveMode_0_SHADE
       0009  Port_2_DriveMode_1_SHADE
       0009  _Port_2_DriveMode_1_SHADE
       000A  ADCINC_iResult
       000A  _ADCINC_iResult
       000E  _ADCINC_fStatus
       000E  ADCINC_fStatus
       000F  ADCINC_bState
       000F  _ADCINC_bState
       0010  _ADCINC_fMode
       0010  ADCINC_fMode
       0011  _ADCINC_bNumSamples
       0011  ADCINC_bNumSamples

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0021   000B =     11. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0021  __rZ
       0022  __rY
       0023  __rX
       0024  __r7
       0025  __r6
       0026  __r5
       0027  __r4
       0028  __r3
       0029  __r2
       002A  __r1
       002B  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   000F =     15. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ sleeptimerint.asm, sleeptimer.asm, psocconfigtbl.asm, psocconfig.asm, pga.asm, lcd.asm, adcincint.asm ]
[ adcinc.asm, rZ.asm, rY.asm, rX.asm, r7.asm, r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmodu_32x32_32_util.asm ]
[ fp_analysiseject_util.asm, fp_clrreg_util.asm, fp_nan_res_util.asm, fp_saveres_util.asm ]
[ fp_sendtoreg_util.asm, fp_sinf_res_util.asm, fp_szero_res_util.asm, fp_type_oprnd_util.asm ]
[ fp_unnormal_util.asm, fpcmp_util.asm, fpmul_util.asm, i_div32_block_util.asm, i_div32_not_util.asm ]
[ i_mulu8_block_util.asm, long2fp_util.asm, ltoa.s, ftoa.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x21
-Bwirelesstemperature_RAM
-rwh:SSCParmBlk:0xf7.0xff

