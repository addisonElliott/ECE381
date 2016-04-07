Project:      output/SPI_SRAM
Build Number: 0
Date:         Wed Apr 06 18:49:29 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   02C3 =    707. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       03BB  LoadConfigTBL_spi_sram_Bank0
       042C  LoadConfigTBL_spi_sram_Bank1
       0463  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0463   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0463  __func_lit_start
       0465  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0465   0167 =    359. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0465  LoadConfigTBL_spi_sram_Ordered
       056A  LoadConfigInit
       056A  _LoadConfigInit
       0571  LoadConfig_spi_sram
       0571  _LoadConfig_spi_sram
       05CC  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   05CC   029A =    666. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       05CC  _UART_TX_ISR
       05CD  _UART_RX_ISR
       05CE  _UART_EnableInt
       05CE  UART_EnableInt
       05D5  UART_DisableInt
       05D5  _UART_DisableInt
       05DC  _UART_SetTxIntMode
       05DC  UART_SetTxIntMode
       05EE  _UART_Start
       05EE  UART_Start
       05F5  _UART_Stop
       05F5  UART_Stop
       05FC  _UART_SendData
       05FC  UART_SendData
       05FF  _bUART_ReadTxStatus
       05FF  _UART_bReadTxStatus
       05FF  bUART_ReadTxStatus
       05FF  UART_bReadTxStatus
       0602  bUART_ReadRxData
       0602  _bUART_ReadRxData
       0602  UART_bReadRxData
       0602  _UART_bReadRxData
       0605  _bUART_ReadRxStatus
       0605  _UART_bReadRxStatus
       0605  UART_bReadRxStatus
       0605  bUART_ReadRxStatus
       0608  UART_TxIntMode
       0608  _UART_TxIntMode
       061B  UART_IntCntl
       061B  _UART_IntCntl
       0646  _UART_PutSHexByte
       0646  UART_PutSHexByte
       0659  UART_PutSHexInt
       0659  _UART_PutSHexInt
       0660  UART_PutChar
       0660  _UART_PutChar
       0668  _UART_cGetChar
       0668  UART_cGetChar
       0670  UART_cReadChar
       0670  _UART_cReadChar
       0687  UART_iReadChar
       0687  _UART_iReadChar
       069D  _UART_PutString
       069D  UART_PutString
       06AF  _UART_Write
       06AF  UART_Write
       06D7  _UART_CWrite
       06D7  UART_CWrite
       0703  UART_CPutString
       0703  _UART_CPutString
       0715  UART_PutCRLF
       0715  _UART_PutCRLF
       071E  _SPIM_ISR
       071F  SPIM_EnableInt
       071F  _SPIM_EnableInt
       0723  SPIM_DisableInt
       0723  _SPIM_DisableInt
       0727  _SPIM_Start
       0727  SPIM_Start
       072C  SPIM_Stop
       072C  _SPIM_Stop
       0730  SPIM_SendTxData
       0730  _SPIM_SendTxData
       0733  bSPIM_ReadRxData
       0733  SPIM_bReadRxData
       0733  _bSPIM_ReadRxData
       0733  _SPIM_bReadRxData
       0736  _bSPIM_ReadStatus
       0736  SPIM_bReadStatus
       0736  bSPIM_ReadStatus
       0736  _SPIM_bReadStatus
       0739  _SleepTimer_ISR
       074D  SleepTimer_EnableInt
       074D  _SleepTimer_EnableInt
       0751  _SleepTimer_DisableInt
       0751  SleepTimer_DisableInt
       0755  _SleepTimer_Start
       0755  SleepTimer_Start
       0763  SleepTimer_Stop
       0763  _SleepTimer_Stop
       0764  _SleepTimer_SetInterval
       0764  SleepTimer_SetInterval
       077A  SleepTimer_TickWait
       077A  _SleepTimer_TickWait
       078C  SleepTimer_SyncWait
       078C  _SleepTimer_SyncWait
       079D  _SleepTimer_bGetTickCntr
       079D  SleepTimer_bGetTickCntr
       07A3  _SleepTimer_SetTimer
       07A3  SleepTimer_SetTimer
       07A9  _SleepTimer_bGetTimer
       07A9  SleepTimer_bGetTimer
       07AF  DAC8_SetPower
       07AF  DAC8_Start
       07AF  _DAC8_SetPower
       07AF  _DAC8_Start
       07C9  DAC8_WriteBlind
       07C9  _DAC8_WriteBlind
       0803  DAC8_WriteBlind2B
       0803  _DAC8_WriteBlind2B
       080E  _DAC8_WriteStall
       080E  DAC8_WriteStall
       084E  DAC8_WriteStall2B
       084E  _DAC8_WriteStall2B
       085F  _DAC8_Stop
       085F  DAC8_Stop
       0866  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0866   2484 =   9348. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0866  _SPIRAM_StatusRegisterTest
       0866  __text_start
       0961  _SPIRAM_ByteModeTest
       0A64  _SPIRAM_SequentialModeTest
       0BAC  _GetNumber
       0BEE  _PlayBlock
       0C8F  _WriteBlock
       1D17  _main
       1E01  _SPIRAM_WriteStatusRegister
       1E86  _SPIRAM_ReadStatusRegister
       1EF2  _SPIRAM_WriteByte
       1FBF  _SPIRAM_ReadByte
       2090  _SPIRAM_WriteArray
       2184  _SPIRAM_ReadArray
       2829  _floorf
       2949  _sinus
       2C84  _sinf
       2CEA  __xidata_start
       2CEA  __text_end
       2CF0  __xidata_end

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
               virtual_registers   0084   000F =     15. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0084  __rZ
       0085  __rY
       0086  __rX
       0087  __r11
       0088  __r10
       0089  __r9
       008A  __r8
       008B  __r7
       008C  __r6
       008D  __r5
       008E  __r4
       008F  __r3
       0090  __r2
       0091  __r1
       0092  __r0

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
[ psocconfig.asm, dac8.asm, rZ.asm, rY.asm, rX.asm, r11.asm, r10.asm, r9.asm, r8.asm, r7.asm, r6.asm, r5.asm ]
[ r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmod_16x16_16_util.asm, fp2long_util.asm, fp_analysiseject_util.asm ]
[ fp_clrreg_util.asm, fp_nan_res_util.asm, fp_saveres_util.asm, fp_sendtoreg_util.asm, fp_sinf_res_util.asm ]
[ fp_szero_res_util.asm, fp_type_oprnd_util.asm, fp_unnormal_util.asm, fpadd_util.asm, fpcmp_util.asm ]
[ fpdiv_util.asm, fpmul_util.asm, fpsub_util.asm, i_div16_block_util.asm, i_div32_not_util.asm ]
[ i_mulu8_block_util.asm, long2fp_util.asm, floorf.s, sinf.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x84
-Bspi_sram_RAM
-rwh:SSCParmBlk:0xf7.0xff

