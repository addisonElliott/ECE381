Project:      output/SPI_SRAM
Build Number: 0
Date:         Mon Apr 04 23:37:04 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   0281 =    641. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       0379  LoadConfigTBL_spi_sram_Bank0
       03EA  LoadConfigTBL_spi_sram_Bank1
       0421  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0421   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0421  __func_lit_start
       0423  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0423   0167 =    359. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0423  LoadConfigTBL_spi_sram_Ordered
       0528  LoadConfigInit
       0528  _LoadConfigInit
       052F  LoadConfig_spi_sram
       052F  _LoadConfig_spi_sram
       058A  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   058A   029A =    666. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       058A  _UART_TX_ISR
       058B  _UART_RX_ISR
       058C  _UART_EnableInt
       058C  UART_EnableInt
       0593  UART_DisableInt
       0593  _UART_DisableInt
       059A  _UART_SetTxIntMode
       059A  UART_SetTxIntMode
       05AC  _UART_Start
       05AC  UART_Start
       05B3  _UART_Stop
       05B3  UART_Stop
       05BA  _UART_SendData
       05BA  UART_SendData
       05BD  _bUART_ReadTxStatus
       05BD  _UART_bReadTxStatus
       05BD  bUART_ReadTxStatus
       05BD  UART_bReadTxStatus
       05C0  bUART_ReadRxData
       05C0  _bUART_ReadRxData
       05C0  UART_bReadRxData
       05C0  _UART_bReadRxData
       05C3  _bUART_ReadRxStatus
       05C3  _UART_bReadRxStatus
       05C3  UART_bReadRxStatus
       05C3  bUART_ReadRxStatus
       05C6  UART_TxIntMode
       05C6  _UART_TxIntMode
       05D9  UART_IntCntl
       05D9  _UART_IntCntl
       0604  _UART_PutSHexByte
       0604  UART_PutSHexByte
       0617  UART_PutSHexInt
       0617  _UART_PutSHexInt
       061E  UART_PutChar
       061E  _UART_PutChar
       0626  _UART_cGetChar
       0626  UART_cGetChar
       062E  UART_cReadChar
       062E  _UART_cReadChar
       0645  UART_iReadChar
       0645  _UART_iReadChar
       065B  _UART_PutString
       065B  UART_PutString
       066D  _UART_Write
       066D  UART_Write
       0695  _UART_CWrite
       0695  UART_CWrite
       06C1  UART_CPutString
       06C1  _UART_CPutString
       06D3  UART_PutCRLF
       06D3  _UART_PutCRLF
       06DC  _SPIM_ISR
       06DD  SPIM_EnableInt
       06DD  _SPIM_EnableInt
       06E1  SPIM_DisableInt
       06E1  _SPIM_DisableInt
       06E5  _SPIM_Start
       06E5  SPIM_Start
       06EA  SPIM_Stop
       06EA  _SPIM_Stop
       06EE  SPIM_SendTxData
       06EE  _SPIM_SendTxData
       06F1  bSPIM_ReadRxData
       06F1  SPIM_bReadRxData
       06F1  _bSPIM_ReadRxData
       06F1  _SPIM_bReadRxData
       06F4  _bSPIM_ReadStatus
       06F4  SPIM_bReadStatus
       06F4  bSPIM_ReadStatus
       06F4  _SPIM_bReadStatus
       06F7  _SleepTimer_ISR
       070B  SleepTimer_EnableInt
       070B  _SleepTimer_EnableInt
       070F  _SleepTimer_DisableInt
       070F  SleepTimer_DisableInt
       0713  _SleepTimer_Start
       0713  SleepTimer_Start
       0721  SleepTimer_Stop
       0721  _SleepTimer_Stop
       0722  _SleepTimer_SetInterval
       0722  SleepTimer_SetInterval
       0738  SleepTimer_TickWait
       0738  _SleepTimer_TickWait
       074A  SleepTimer_SyncWait
       074A  _SleepTimer_SyncWait
       075B  _SleepTimer_bGetTickCntr
       075B  SleepTimer_bGetTickCntr
       0761  _SleepTimer_SetTimer
       0761  SleepTimer_SetTimer
       0767  _SleepTimer_bGetTimer
       0767  SleepTimer_bGetTimer
       076D  DAC8_SetPower
       076D  DAC8_Start
       076D  _DAC8_SetPower
       076D  _DAC8_Start
       0787  DAC8_WriteBlind
       0787  _DAC8_WriteBlind
       07C1  DAC8_WriteBlind2B
       07C1  _DAC8_WriteBlind2B
       07CC  _DAC8_WriteStall
       07CC  DAC8_WriteStall
       080C  DAC8_WriteStall2B
       080C  _DAC8_WriteStall2B
       081D  _DAC8_Stop
       081D  DAC8_Stop
       0824  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0824   0930 =   2352. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0824  __text_start
       0824  _SPIRAM_StatusRegisterTest
       091F  _SPIRAM_ByteModeTest
       0A22  _SPIRAM_SequentialModeTest
       0B6A  _GetNumber
       0BA9  _PlayBlock
       0C18  _main
       0CD7  _SPIRAM_WriteStatusRegister
       0D5C  _SPIRAM_ReadStatusRegister
       0DC8  _SPIRAM_WriteByte
       0E95  _SPIRAM_ReadByte
       0F66  _SPIRAM_WriteArray
       105A  _SPIRAM_ReadArray
       1154  __text_end
       1154  __xidata_start
       115A  __xidata_end

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

