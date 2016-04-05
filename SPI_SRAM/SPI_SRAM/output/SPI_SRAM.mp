Project:      output/SPI_SRAM
Build Number: 0
Date:         Mon Apr 04 20:09:15 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   0283 =    643. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       037B  LoadConfigTBL_spi_sram_Bank0
       03EC  LoadConfigTBL_spi_sram_Bank1
       0423  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0423   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0423  __func_lit_start
       0425  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0425   0167 =    359. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0425  LoadConfigTBL_spi_sram_Ordered
       052A  LoadConfigInit
       052A  _LoadConfigInit
       0531  LoadConfig_spi_sram
       0531  _LoadConfig_spi_sram
       058C  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   058C   029A =    666. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       058C  _UART_TX_ISR
       058D  _UART_RX_ISR
       058E  _UART_EnableInt
       058E  UART_EnableInt
       0595  UART_DisableInt
       0595  _UART_DisableInt
       059C  _UART_SetTxIntMode
       059C  UART_SetTxIntMode
       05AE  _UART_Start
       05AE  UART_Start
       05B5  _UART_Stop
       05B5  UART_Stop
       05BC  _UART_SendData
       05BC  UART_SendData
       05BF  _bUART_ReadTxStatus
       05BF  _UART_bReadTxStatus
       05BF  bUART_ReadTxStatus
       05BF  UART_bReadTxStatus
       05C2  bUART_ReadRxData
       05C2  _bUART_ReadRxData
       05C2  UART_bReadRxData
       05C2  _UART_bReadRxData
       05C5  _bUART_ReadRxStatus
       05C5  _UART_bReadRxStatus
       05C5  UART_bReadRxStatus
       05C5  bUART_ReadRxStatus
       05C8  UART_TxIntMode
       05C8  _UART_TxIntMode
       05DB  UART_IntCntl
       05DB  _UART_IntCntl
       0606  _UART_PutSHexByte
       0606  UART_PutSHexByte
       0619  UART_PutSHexInt
       0619  _UART_PutSHexInt
       0620  UART_PutChar
       0620  _UART_PutChar
       0628  _UART_cGetChar
       0628  UART_cGetChar
       0630  UART_cReadChar
       0630  _UART_cReadChar
       0647  UART_iReadChar
       0647  _UART_iReadChar
       065D  _UART_PutString
       065D  UART_PutString
       066F  _UART_Write
       066F  UART_Write
       0697  _UART_CWrite
       0697  UART_CWrite
       06C3  UART_CPutString
       06C3  _UART_CPutString
       06D5  UART_PutCRLF
       06D5  _UART_PutCRLF
       06DE  _SPIM_ISR
       06DF  SPIM_EnableInt
       06DF  _SPIM_EnableInt
       06E3  SPIM_DisableInt
       06E3  _SPIM_DisableInt
       06E7  _SPIM_Start
       06E7  SPIM_Start
       06EC  SPIM_Stop
       06EC  _SPIM_Stop
       06F0  SPIM_SendTxData
       06F0  _SPIM_SendTxData
       06F3  bSPIM_ReadRxData
       06F3  SPIM_bReadRxData
       06F3  _bSPIM_ReadRxData
       06F3  _SPIM_bReadRxData
       06F6  _bSPIM_ReadStatus
       06F6  SPIM_bReadStatus
       06F6  bSPIM_ReadStatus
       06F6  _SPIM_bReadStatus
       06F9  _SleepTimer_ISR
       070D  SleepTimer_EnableInt
       070D  _SleepTimer_EnableInt
       0711  _SleepTimer_DisableInt
       0711  SleepTimer_DisableInt
       0715  _SleepTimer_Start
       0715  SleepTimer_Start
       0723  SleepTimer_Stop
       0723  _SleepTimer_Stop
       0724  _SleepTimer_SetInterval
       0724  SleepTimer_SetInterval
       073A  SleepTimer_TickWait
       073A  _SleepTimer_TickWait
       074C  SleepTimer_SyncWait
       074C  _SleepTimer_SyncWait
       075D  _SleepTimer_bGetTickCntr
       075D  SleepTimer_bGetTickCntr
       0763  _SleepTimer_SetTimer
       0763  SleepTimer_SetTimer
       0769  _SleepTimer_bGetTimer
       0769  SleepTimer_bGetTimer
       076F  DAC8_SetPower
       076F  DAC8_Start
       076F  _DAC8_SetPower
       076F  _DAC8_Start
       0789  DAC8_WriteBlind
       0789  _DAC8_WriteBlind
       07C3  DAC8_WriteBlind2B
       07C3  _DAC8_WriteBlind2B
       07CE  _DAC8_WriteStall
       07CE  DAC8_WriteStall
       080E  DAC8_WriteStall2B
       080E  _DAC8_WriteStall2B
       081F  _DAC8_Stop
       081F  DAC8_Stop
       0826  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0826   08C4 =   2244. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0826  __text_start
       0826  _SPIRAM_StatusRegisterTest
       0921  _SPIRAM_ByteModeTest
       0A24  _SPIRAM_SequentialModeTest
       0B6C  _GetNumber
       0BB7  _main
       0C6D  _SPIRAM_WriteStatusRegister
       0CF2  _SPIRAM_ReadStatusRegister
       0D5E  _SPIRAM_WriteByte
       0E2B  _SPIRAM_ReadByte
       0EFC  _SPIRAM_WriteArray
       0FF0  _SPIRAM_ReadArray
       10EA  __text_end
       10EA  __xidata_start
       10F0  __xidata_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             TOP   0000   0146 =    326. bytes (abs,ovr,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0068  __Start
       0143  _bGetPowerSetting
       0143  bGetPowerSetting

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                    InterruptRAM   0000   0004 =      4. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  _SleepTimer_fTick
       0000  SleepTimer_fTick
       0001  SleepTimer_bTimerValue
       0001  _SleepTimer_bTimerValue
       0002  SleepTimer_bCountDown
       0002  _SleepTimer_bCountDown
       0003  _SleepTimer_TickCount
       0003  SleepTimer_TickCount
       0004  _NO_SHADOW
       0004  NO_SHADOW

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0084   0005 =      5. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0084  __rX
       0085  __r3
       0086  __r2
       0087  __r1
       0088  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0080 =    128. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       0004  _DataOut
       0044  _DataIn

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
obj/spi_sram.o	[ spi_sram.c ]
<library>	[ uartint.asm, uart.asm, spimint.asm, spim.asm, sleeptimerint.asm, sleeptimer.asm, psocconfigtbl.asm ]
[ psocconfig.asm, dac8.asm, rX.asm, r3.asm, r2.asm, r1.asm, r0.asm ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x84
-Bspi_sram_RAM
-rwh:SSCParmBlk:0xf7.0xff

