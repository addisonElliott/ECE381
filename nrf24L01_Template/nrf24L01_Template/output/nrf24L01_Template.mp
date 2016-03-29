Project:      output/nrf24L01_Template
Build Number: 0
Date:         Mon Mar 28 19:08:55 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   0228 =    552. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01AF  LoadConfigTBL_nrf24l01_template_Bank0
       0222  LoadConfigTBL_nrf24l01_template_Bank1
       0253  __ctype
       03C8  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   03C8   0004 =      4. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       03C8  __func_lit_start
       03CC  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   03CC   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03CC  LoadConfigTBL_nrf24l01_template_Ordered
       04D1  _LoadConfigInit
       04D1  LoadConfigInit
       04E1  _LoadConfig_nrf24l01_template
       04E1  LoadConfig_nrf24l01_template
       053C  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   053C   03C8 =    968. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       053C  _SPIM_ISR
       053D  _SPIM_EnableInt
       053D  SPIM_EnableInt
       0541  _SPIM_DisableInt
       0541  SPIM_DisableInt
       0545  SPIM_Start
       0545  _SPIM_Start
       054A  _SPIM_Stop
       054A  SPIM_Stop
       054E  _SPIM_SendTxData
       054E  SPIM_SendTxData
       0551  _SPIM_bReadRxData
       0551  _bSPIM_ReadRxData
       0551  SPIM_bReadRxData
       0551  bSPIM_ReadRxData
       0554  _bSPIM_ReadStatus
       0554  _SPIM_bReadStatus
       0554  bSPIM_ReadStatus
       0554  SPIM_bReadStatus
       0557  _SleepTimer_ISR
       056B  _SleepTimer_EnableInt
       056B  SleepTimer_EnableInt
       056F  SleepTimer_DisableInt
       056F  _SleepTimer_DisableInt
       0573  SleepTimer_Start
       0573  _SleepTimer_Start
       0581  SleepTimer_Stop
       0581  _SleepTimer_Stop
       0582  _SleepTimer_SetInterval
       0582  SleepTimer_SetInterval
       0598  _SleepTimer_TickWait
       0598  SleepTimer_TickWait
       05AA  _SleepTimer_SyncWait
       05AA  SleepTimer_SyncWait
       05BB  _SleepTimer_bGetTickCntr
       05BB  SleepTimer_bGetTickCntr
       05C1  _SleepTimer_SetTimer
       05C1  SleepTimer_SetTimer
       05C7  _SleepTimer_bGetTimer
       05C7  SleepTimer_bGetTimer
       05CD  _PGA_SetPower
       05CD  _PGA_Start
       05CD  PGA_SetPower
       05CD  PGA_Start
       05DF  _PGA_SetGain
       05DF  PGA_SetGain
       0609  _PGA_Stop
       0609  PGA_Stop
       060D  _LCD_PrCString
       060D  LCD_PrCString
       061F  LCD_HEX_STR
       062F  LCD_PrHexByte
       062F  _LCD_PrHexByte
       0642  LCD_PrHexInt
       0642  _LCD_PrHexInt
       0649  LCD_PrString
       0649  _LCD_PrString
       065B  LCD_WriteData
       065B  _LCD_Write_Data
       065B  LCD_Write_Data
       065B  _LCD_WriteData
       066F  LCD_Control
       066F  _LCD_Control
       071F  _LCD_Init
       071F  _LCD_Start
       071F  LCD_Init
       071F  LCD_Start
       078E  LCD_ROW_OFFSET
       0792  LCD_Position
       0792  _LCD_Position
       07A2  _LCD_Delay50uTimes
       07A2  LCD_Delay50uTimes
       07A8  LCD_Delay50u_Table
       07B0  _LCD_Delay50u
       07B0  LCD_Delay50u
       07C4  _ADCINC_ADConversion_ISR
       0844  _ADCINC_Start
       0844  ADCINC_Start
       0859  _ADCINC_SetPower
       0859  ADCINC_SetPower
       0875  ADCINC_Stop
       0875  _ADCINC_Stop
       0882  ADCINC_GetSamples
       0882  _ADCINC_GetSamples
       08B1  ADCINC_StopADC
       08B1  _ADCINC_StopADC
       08CB  ADCINC_fIsDataAvailable
       08CB  _ADCINC_fIsDataAvailable
       08D1  _ADCINC_wClearFlagGetData
       08D1  ADCINC_wClearFlagGetData
       08D1  ADCINC_iClearFlagGetData
       08D1  _ADCINC_iClearFlagGetData
       08E1  ADCINC_bClearFlagGetData
       08E1  _ADCINC_cClearFlagGetData
       08E1  ADCINC_cClearFlagGetData
       08E1  _ADCINC_bClearFlagGetData
       08EA  _ADCINC_iGetData
       08EA  ADCINC_wGetData
       08EA  ADCINC_iGetData
       08EA  _ADCINC_wGetData
       08F2  ADCINC_cGetData
       08F2  _ADCINC_bGetData
       08F2  _ADCINC_cGetData
       08F2  ADCINC_bGetData
       08F8  ADCINC_fClearFlag
       08F8  _ADCINC_fClearFlag
       0901  _ADCINC_WritePulseWidth
       0901  ADCINC_WritePulseWidth
       0904  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0904   1B9B =   7067. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0904  __text_start
       0904  _main
       0BD4  _nrfWriteRegister
       0C53  _nrfReadRegister
       0CD6  _nrfWriteAddress
       0D78  _nrfReadAddress
       0E20  _nrfSendData
       143D  __plcall
       1449  _itoa
       1622  _ltoa
       189B  _utoa
       19DE  _ftoa
       1E2D  _isdigit
       1E4E  _islower
       1E6F  _isspace
       1E90  _toupper
       1ECE  __csdepi
       1F00  _csprintf
       1F69  __cprint
       249F  __xidata_start
       249F  __text_end
       24AA  __xidata_end

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
               virtual_registers   0037   000B =     11. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0037  __rZ
       0038  __rY
       0039  __rX
       003A  __r7
       003B  __r6
       003C  __r5
       003D  __r4
       003E  __r3
       003F  __r2
       0040  __r1
       0041  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   002A =     42. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
obj/nrf24l01_api.o	[ nrf24l01_api.c ]
<library>	[ spimint.asm, spim.asm, sleeptimerint.asm, sleeptimer.asm, psocconfigtbl.asm, psocconfig.asm ]
[ pga.asm, lcd.asm, adcincint.asm, adcinc.asm, rZ.asm, rY.asm, rX.asm, r7.asm, r6.asm, r5.asm, r4.asm, r3.asm ]
[ r2.asm, r1.asm, r0.asm, divmodu_16x16_16_util.asm, divmodu_32x32_32_util.asm, fp_analysiseject_util.asm ]
[ fp_clrreg_util.asm, fp_nan_res_util.asm, fp_saveres_util.asm, fp_sendtoreg_util.asm, fp_sinf_res_util.asm ]
[ fp_szero_res_util.asm, fp_type_oprnd_util.asm, fp_unnormal_util.asm, fpadd_util.asm, fpcmp_util.asm ]
[ fpdiv_util.asm, fpmul_util.asm, i_div16_block_util.asm, i_div32_block_util.asm, i_div32_not_util.asm ]
[ i_mulu8_block_util.asm, long2fp_util.asm, plcall.s, itoa.s, ltoa.s, utoa.s, ftoa.s, isdigit.s, islower.s ]
[ isspace.s, ctype.s, toupper.s, sprintf.s, _printf.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x37
-Bnrf24l01_template_RAM
-rwh:SSCParmBlk:0xf7.0xff

