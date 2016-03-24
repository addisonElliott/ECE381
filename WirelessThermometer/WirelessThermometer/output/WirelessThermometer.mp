Project:      output/WirelessThermometer
Build Number: 0
Date:         Tue Mar 22 15:13:53 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   00B5 =    181. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01BD  LoadConfigTBL_wirelessthermometer_Bank0
       022A  LoadConfigTBL_wirelessthermometer_Bank1
       0255  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0255   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0255  __func_lit_start
       0257  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0257   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0257  LoadConfigTBL_wirelessthermometer_Ordered
       035C  _LoadConfigInit
       035C  LoadConfigInit
       036C  _LoadConfig_wirelessthermometer
       036C  LoadConfig_wirelessthermometer
       03C7  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   03C7   0357 =    855. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03C7  _SleepTimer_ISR
       03E7  _PGA_SetPower
       03E7  PGA_Start
       03E7  PGA_SetPower
       03E7  _PGA_Start
       03F9  PGA_SetGain
       03F9  _PGA_SetGain
       0423  PGA_Stop
       0423  _PGA_Stop
       0427  _LCD_PrCString
       0427  LCD_PrCString
       0439  LCD_HEX_STR
       0449  LCD_PrHexByte
       0449  _LCD_PrHexByte
       045C  _LCD_PrHexInt
       045C  LCD_PrHexInt
       0463  LCD_PrString
       0463  _LCD_PrString
       0475  _LCD_WriteData
       0475  LCD_Write_Data
       0475  _LCD_Write_Data
       0475  LCD_WriteData
       0489  _LCD_Control
       0489  LCD_Control
       0539  _LCD_Init
       0539  _LCD_Start
       0539  LCD_Init
       0539  LCD_Start
       05A8  LCD_ROW_OFFSET
       05AC  LCD_Position
       05AC  _LCD_Position
       05BC  _LCD_Delay50uTimes
       05BC  LCD_Delay50uTimes
       05C2  LCD_Delay50u_Table
       05CA  LCD_Delay50u
       05CA  _LCD_Delay50u
       05DE  _ADCINC_ADConversion_ISR
       065E  _ADCINC_Start
       065E  ADCINC_Start
       0673  ADCINC_SetPower
       0673  _ADCINC_SetPower
       068F  ADCINC_Stop
       068F  _ADCINC_Stop
       069C  ADCINC_GetSamples
       069C  _ADCINC_GetSamples
       06CB  ADCINC_StopADC
       06CB  _ADCINC_StopADC
       06E5  ADCINC_fIsDataAvailable
       06E5  _ADCINC_fIsDataAvailable
       06EB  _ADCINC_iClearFlagGetData
       06EB  _ADCINC_wClearFlagGetData
       06EB  ADCINC_iClearFlagGetData
       06EB  ADCINC_wClearFlagGetData
       06FB  _ADCINC_cClearFlagGetData
       06FB  ADCINC_cClearFlagGetData
       06FB  _ADCINC_bClearFlagGetData
       06FB  ADCINC_bClearFlagGetData
       0704  ADCINC_iGetData
       0704  _ADCINC_iGetData
       0704  _ADCINC_wGetData
       0704  ADCINC_wGetData
       070C  _ADCINC_cGetData
       070C  _ADCINC_bGetData
       070C  ADCINC_bGetData
       070C  ADCINC_cGetData
       0712  ADCINC_fClearFlag
       0712  _ADCINC_fClearFlag
       071B  _ADCINC_WritePulseWidth
       071B  ADCINC_WritePulseWidth
       071E  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   071E   08F5 =   2293. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       071E  __text_start
       071E  _main
       094B  _ltoa
       0BC4  _ftoa
       1013  __text_end
       1013  __xidata_start
       1019  __xidata_end

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
<library>	[ sleeptimerint.asm, psocconfigtbl.asm, psocconfig.asm, pga.asm, lcd.asm, adcincint.asm, adcinc.asm ]
[ rZ.asm, rY.asm, rX.asm, r7.asm, r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmodu_32x32_32_util.asm ]
[ fpcmp_util.asm, i_div32_block_util.asm, i_div32_not_util.asm, long2fp_util.asm, ltoa.s, ftoa.s ]


Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x21
-Bwirelessthermometer_RAM
-rwh:SSCParmBlk:0xf7.0xff

