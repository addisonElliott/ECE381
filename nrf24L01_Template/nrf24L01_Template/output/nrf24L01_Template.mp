Project:      output/nrf24L01_Template
Build Number: 0
Date:         Wed Mar 23 21:15:38 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   0208 =    520. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01B3  LoadConfigTBL_nrf24l01_template_Bank0
       0208  LoadConfigTBL_nrf24l01_template_Bank1
       0233  __ctype
       03A8  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   03A8   0004 =      4. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       03A8  __func_lit_start
       03AC  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   03AC   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03AC  LoadConfigTBL_nrf24l01_template_Ordered
       04B1  _LoadConfigInit
       04B1  LoadConfigInit
       04C1  _LoadConfig_nrf24l01_template
       04C1  LoadConfig_nrf24l01_template
       051C  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   051C   0248 =    584. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       051C  _SPIM_ISR
       051D  _SPIM_EnableInt
       051D  SPIM_EnableInt
       0521  SPIM_DisableInt
       0521  _SPIM_DisableInt
       0525  _SPIM_Start
       0525  SPIM_Start
       052A  SPIM_Stop
       052A  _SPIM_Stop
       052E  _SPIM_SendTxData
       052E  SPIM_SendTxData
       0531  SPIM_bReadRxData
       0531  bSPIM_ReadRxData
       0531  _bSPIM_ReadRxData
       0531  _SPIM_bReadRxData
       0534  SPIM_bReadStatus
       0534  _bSPIM_ReadStatus
       0534  _SPIM_bReadStatus
       0534  bSPIM_ReadStatus
       0537  _SleepTimer_ISR
       054B  SleepTimer_EnableInt
       054B  _SleepTimer_EnableInt
       054F  _SleepTimer_DisableInt
       054F  SleepTimer_DisableInt
       0553  SleepTimer_Start
       0553  _SleepTimer_Start
       0561  _SleepTimer_Stop
       0561  SleepTimer_Stop
       0562  _SleepTimer_SetInterval
       0562  SleepTimer_SetInterval
       0578  _SleepTimer_TickWait
       0578  SleepTimer_TickWait
       058A  SleepTimer_SyncWait
       058A  _SleepTimer_SyncWait
       059B  _SleepTimer_bGetTickCntr
       059B  SleepTimer_bGetTickCntr
       05A1  _SleepTimer_SetTimer
       05A1  SleepTimer_SetTimer
       05A7  SleepTimer_bGetTimer
       05A7  _SleepTimer_bGetTimer
       05AD  LCD_PrCString
       05AD  _LCD_PrCString
       05BF  LCD_HEX_STR
       05CF  _LCD_PrHexByte
       05CF  LCD_PrHexByte
       05E2  LCD_PrHexInt
       05E2  _LCD_PrHexInt
       05E9  _LCD_PrString
       05E9  LCD_PrString
       05FB  LCD_WriteData
       05FB  _LCD_WriteData
       05FB  LCD_Write_Data
       05FB  _LCD_Write_Data
       060F  _LCD_Control
       060F  LCD_Control
       06BF  LCD_Init
       06BF  _LCD_Start
       06BF  LCD_Start
       06BF  _LCD_Init
       072E  LCD_ROW_OFFSET
       0732  _LCD_Position
       0732  LCD_Position
       0742  LCD_Delay50uTimes
       0742  _LCD_Delay50uTimes
       0748  LCD_Delay50u_Table
       0750  LCD_Delay50u
       0750  _LCD_Delay50u
       0764  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0764   0D84 =   3460. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0764  _main
       0764  __text_start
       08B6  _nrfWriteRegister
       0935  _nrfReadRegister
       09B8  _nrfWriteAddress
       0A68  _nrfSendData
       0B4E  __plcall
       0B5A  _itoa
       0D33  _utoa
       0E76  _isdigit
       0E97  _islower
       0EB8  _isspace
       0ED9  _toupper
       0F17  __csdepi
       0F49  _csprintf
       0FB2  __cprint
       14E8  __xidata_start
       14E8  __text_end
       14F3  __xidata_end

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
                    InterruptRAM   0000   0007 =      7. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  SleepTimer_fTick
       0000  _SleepTimer_fTick
       0001  _SleepTimer_bTimerValue
       0001  SleepTimer_bTimerValue
       0002  SleepTimer_bCountDown
       0002  _SleepTimer_bCountDown
       0003  SleepTimer_TickCount
       0003  _SleepTimer_TickCount
       0004  NO_SHADOW
       0004  _NO_SHADOW
       0004  Port_2_Data_SHADE
       0004  _Port_2_Data_SHADE
       0005  Port_2_DriveMode_0_SHADE
       0005  _Port_2_DriveMode_0_SHADE
       0006  _Port_2_DriveMode_1_SHADE
       0006  Port_2_DriveMode_1_SHADE

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0020   0009 =      9. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0020  __rZ
       0021  __rY
       0022  __rX
       0023  __r5
       0024  __r4
       0025  __r3
       0026  __r2
       0027  __r1
       0028  __r0

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
[ lcd.asm, rZ.asm, rY.asm, rX.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmodu_16x16_16_util.asm ]
[ i_div16_block_util.asm, plcall.s, itoa.s, utoa.s, isdigit.s, islower.s, isspace.s, ctype.s, toupper.s ]
[ sprintf.s, _printf.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x20
-Bnrf24l01_template_RAM
-rwh:SSCParmBlk:0xf7.0xff

