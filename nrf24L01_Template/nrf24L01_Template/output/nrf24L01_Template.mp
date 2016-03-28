Project:      output/nrf24L01_Template
Build Number: 0
Date:         Thu Mar 24 14:28:58 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   022C =    556. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01B3  LoadConfigTBL_nrf24l01_template_Bank0
       0226  LoadConfigTBL_nrf24l01_template_Bank1
       0257  __ctype
       03CC  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   03CC   0004 =      4. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       03CC  __func_lit_start
       03D0  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   03D0   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03D0  LoadConfigTBL_nrf24l01_template_Ordered
       04D5  _LoadConfigInit
       04D5  LoadConfigInit
       04E5  _LoadConfig_nrf24l01_template
       04E5  LoadConfig_nrf24l01_template
       0540  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   0540   03C8 =    968. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0540  _SPIM_ISR
       0541  _SPIM_EnableInt
       0541  SPIM_EnableInt
       0545  _SPIM_DisableInt
       0545  SPIM_DisableInt
       0549  SPIM_Start
       0549  _SPIM_Start
       054E  _SPIM_Stop
       054E  SPIM_Stop
       0552  _SPIM_SendTxData
       0552  SPIM_SendTxData
       0555  _SPIM_bReadRxData
       0555  _bSPIM_ReadRxData
       0555  SPIM_bReadRxData
       0555  bSPIM_ReadRxData
       0558  _bSPIM_ReadStatus
       0558  _SPIM_bReadStatus
       0558  bSPIM_ReadStatus
       0558  SPIM_bReadStatus
       055B  _SleepTimer_ISR
       056F  _SleepTimer_EnableInt
       056F  SleepTimer_EnableInt
       0573  SleepTimer_DisableInt
       0573  _SleepTimer_DisableInt
       0577  SleepTimer_Start
       0577  _SleepTimer_Start
       0585  SleepTimer_Stop
       0585  _SleepTimer_Stop
       0586  _SleepTimer_SetInterval
       0586  SleepTimer_SetInterval
       059C  _SleepTimer_TickWait
       059C  SleepTimer_TickWait
       05AE  _SleepTimer_SyncWait
       05AE  SleepTimer_SyncWait
       05BF  _SleepTimer_bGetTickCntr
       05BF  SleepTimer_bGetTickCntr
       05C5  _SleepTimer_SetTimer
       05C5  SleepTimer_SetTimer
       05CB  _SleepTimer_bGetTimer
       05CB  SleepTimer_bGetTimer
       05D1  _PGA_SetPower
       05D1  _PGA_Start
       05D1  PGA_SetPower
       05D1  PGA_Start
       05E3  _PGA_SetGain
       05E3  PGA_SetGain
       060D  _PGA_Stop
       060D  PGA_Stop
       0611  _LCD_PrCString
       0611  LCD_PrCString
       0623  LCD_HEX_STR
       0633  LCD_PrHexByte
       0633  _LCD_PrHexByte
       0646  LCD_PrHexInt
       0646  _LCD_PrHexInt
       064D  LCD_PrString
       064D  _LCD_PrString
       065F  LCD_WriteData
       065F  _LCD_Write_Data
       065F  _LCD_WriteData
       065F  LCD_Write_Data
       0673  LCD_Control
       0673  _LCD_Control
       0723  _LCD_Init
       0723  _LCD_Start
       0723  LCD_Init
       0723  LCD_Start
       0792  LCD_ROW_OFFSET
       0796  LCD_Position
       0796  _LCD_Position
       07A6  _LCD_Delay50uTimes
       07A6  LCD_Delay50uTimes
       07AC  LCD_Delay50u_Table
       07B4  _LCD_Delay50u
       07B4  LCD_Delay50u
       07C8  _ADCINC_ADConversion_ISR
       0848  _ADCINC_Start
       0848  ADCINC_Start
       085D  _ADCINC_SetPower
       085D  ADCINC_SetPower
       0879  ADCINC_Stop
       0879  _ADCINC_Stop
       0886  ADCINC_GetSamples
       0886  _ADCINC_GetSamples
       08B5  ADCINC_StopADC
       08B5  _ADCINC_StopADC
       08CF  ADCINC_fIsDataAvailable
       08CF  _ADCINC_fIsDataAvailable
       08D5  _ADCINC_wClearFlagGetData
       08D5  ADCINC_iClearFlagGetData
       08D5  ADCINC_wClearFlagGetData
       08D5  _ADCINC_iClearFlagGetData
       08E5  _ADCINC_bClearFlagGetData
       08E5  ADCINC_bClearFlagGetData
       08E5  ADCINC_cClearFlagGetData
       08E5  _ADCINC_cClearFlagGetData
       08EE  ADCINC_wGetData
       08EE  ADCINC_iGetData
       08EE  _ADCINC_iGetData
       08EE  _ADCINC_wGetData
       08F6  _ADCINC_cGetData
       08F6  ADCINC_bGetData
       08F6  ADCINC_cGetData
       08F6  _ADCINC_bGetData
       08FC  ADCINC_fClearFlag
       08FC  _ADCINC_fClearFlag
       0905  _ADCINC_WritePulseWidth
       0905  ADCINC_WritePulseWidth
       0908  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0908   0F45 =   3909. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0908  _main
       0908  __text_start
       0B81  _nrfWriteRegister
       0C00  _nrfReadRegister
       0C83  _nrfWriteAddress
       0D25  _nrfReadAddress
       0DCD  _nrfSendData
       0EB3  __plcall
       0EBF  _itoa
       1098  _utoa
       11DB  _isdigit
       11FC  _islower
       121D  _isspace
       123E  _toupper
       127C  __csdepi
       12AE  _csprintf
       1317  __cprint
       184D  __xidata_start
       184D  __text_end
       1858  __xidata_end

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
                    InterruptRAM   0000   000F =     15. bytes (rel,con,ram)

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
       0004  NO_SHADOW
       0004  Port_2_Data_SHADE
       0004  _Port_2_Data_SHADE
       0004  _NO_SHADOW
       0005  _Port_2_DriveMode_0_SHADE
       0005  Port_2_DriveMode_0_SHADE
       0006  Port_2_DriveMode_1_SHADE
       0006  _Port_2_DriveMode_1_SHADE
       0007  ADCINC_iResult
       0007  _ADCINC_iResult
       000B  _ADCINC_fStatus
       000B  ADCINC_fStatus
       000C  ADCINC_bState
       000C  _ADCINC_bState
       000D  _ADCINC_fMode
       000D  ADCINC_fMode
       000E  _ADCINC_bNumSamples
       000E  ADCINC_bNumSamples

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0028   0009 =      9. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0028  __rZ
       0029  __rY
       002A  __rX
       002B  __r5
       002C  __r4
       002D  __r3
       002E  __r2
       002F  __r1
       0030  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   001B =     27. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
obj/nrf24l01_api.o	[ nrf24l01_api.c ]
<library>	[ spimint.asm, spim.asm, sleeptimerint.asm, sleeptimer.asm, psocconfigtbl.asm, psocconfig.asm ]
[ pga.asm, lcd.asm, adcincint.asm, adcinc.asm, rZ.asm, rY.asm, rX.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm ]
[ r0.asm, divmodu_16x16_16_util.asm, i_div16_block_util.asm, plcall.s, itoa.s, utoa.s, isdigit.s ]
[ islower.s, isspace.s, ctype.s, toupper.s, sprintf.s, _printf.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x28
-Bnrf24l01_template_RAM
-rwh:SSCParmBlk:0xf7.0xff

