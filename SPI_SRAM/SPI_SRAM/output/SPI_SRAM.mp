Project:      output/SPI_SRAM
Build Number: 0
Date:         Thu Apr 07 15:08:51 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   02B4 =    692. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       03AC  LoadConfigTBL_spi_sram_Bank0
       041D  LoadConfigTBL_spi_sram_Bank1
       0454  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0454   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0454  __func_lit_start
       0456  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0456   0167 =    359. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0456  LoadConfigTBL_spi_sram_Ordered
       055B  LoadConfigInit
       055B  _LoadConfigInit
       0562  LoadConfig_spi_sram
       0562  _LoadConfig_spi_sram
       05BD  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   05BD   029A =    666. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       05BD  _UART_TX_ISR
       05BE  _UART_RX_ISR
       05BF  _UART_EnableInt
       05BF  UART_EnableInt
       05C6  UART_DisableInt
       05C6  _UART_DisableInt
       05CD  _UART_SetTxIntMode
       05CD  UART_SetTxIntMode
       05DF  _UART_Start
       05DF  UART_Start
       05E6  _UART_Stop
       05E6  UART_Stop
       05ED  _UART_SendData
       05ED  UART_SendData
       05F0  _bUART_ReadTxStatus
       05F0  _UART_bReadTxStatus
       05F0  bUART_ReadTxStatus
       05F0  UART_bReadTxStatus
       05F3  bUART_ReadRxData
       05F3  _bUART_ReadRxData
       05F3  UART_bReadRxData
       05F3  _UART_bReadRxData
       05F6  _bUART_ReadRxStatus
       05F6  _UART_bReadRxStatus
       05F6  UART_bReadRxStatus
       05F6  bUART_ReadRxStatus
       05F9  UART_TxIntMode
       05F9  _UART_TxIntMode
       060C  UART_IntCntl
       060C  _UART_IntCntl
       0637  _UART_PutSHexByte
       0637  UART_PutSHexByte
       064A  UART_PutSHexInt
       064A  _UART_PutSHexInt
       0651  UART_PutChar
       0651  _UART_PutChar
       0659  _UART_cGetChar
       0659  UART_cGetChar
       0661  UART_cReadChar
       0661  _UART_cReadChar
       0678  UART_iReadChar
       0678  _UART_iReadChar
       068E  _UART_PutString
       068E  UART_PutString
       06A0  _UART_Write
       06A0  UART_Write
       06C8  _UART_CWrite
       06C8  UART_CWrite
       06F4  UART_CPutString
       06F4  _UART_CPutString
       0706  UART_PutCRLF
       0706  _UART_PutCRLF
       070F  _SPIM_ISR
       0710  SPIM_EnableInt
       0710  _SPIM_EnableInt
       0714  SPIM_DisableInt
       0714  _SPIM_DisableInt
       0718  _SPIM_Start
       0718  SPIM_Start
       071D  SPIM_Stop
       071D  _SPIM_Stop
       0721  SPIM_SendTxData
       0721  _SPIM_SendTxData
       0724  bSPIM_ReadRxData
       0724  SPIM_bReadRxData
       0724  _bSPIM_ReadRxData
       0724  _SPIM_bReadRxData
       0727  _bSPIM_ReadStatus
       0727  SPIM_bReadStatus
       0727  bSPIM_ReadStatus
       0727  _SPIM_bReadStatus
       072A  _SleepTimer_ISR
       073E  SleepTimer_EnableInt
       073E  _SleepTimer_EnableInt
       0742  _SleepTimer_DisableInt
       0742  SleepTimer_DisableInt
       0746  _SleepTimer_Start
       0746  SleepTimer_Start
       0754  SleepTimer_Stop
       0754  _SleepTimer_Stop
       0755  _SleepTimer_SetInterval
       0755  SleepTimer_SetInterval
       076B  SleepTimer_TickWait
       076B  _SleepTimer_TickWait
       077D  SleepTimer_SyncWait
       077D  _SleepTimer_SyncWait
       078E  _SleepTimer_bGetTickCntr
       078E  SleepTimer_bGetTickCntr
       0794  _SleepTimer_SetTimer
       0794  SleepTimer_SetTimer
       079A  _SleepTimer_bGetTimer
       079A  SleepTimer_bGetTimer
       07A0  DAC8_SetPower
       07A0  DAC8_Start
       07A0  _DAC8_SetPower
       07A0  _DAC8_Start
       07BA  DAC8_WriteBlind
       07BA  _DAC8_WriteBlind
       07F4  DAC8_WriteBlind2B
       07F4  _DAC8_WriteBlind2B
       07FF  _DAC8_WriteStall
       07FF  DAC8_WriteStall
       083F  DAC8_WriteStall2B
       083F  _DAC8_WriteStall2B
       0850  _DAC8_Stop
       0850  DAC8_Stop
       0857  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0857   2463 =   9315. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0857  _SPIRAM_StatusRegisterTest
       0857  __text_start
       0952  _SPIRAM_ByteModeTest
       0A55  _SPIRAM_SequentialModeTest
       0B9D  _GetNumber
       0BDF  _PlayBlock
       0C80  _WriteBlock
       1CE7  _main
       1DD1  _SPIRAM_WriteStatusRegister
       1E56  _SPIRAM_ReadStatusRegister
       1EC2  _SPIRAM_WriteByte
       1F8F  _SPIRAM_ReadByte
       2060  _SPIRAM_WriteArray
       2154  _SPIRAM_ReadArray
       27F9  _floorf
       2919  _sinus
       2C54  _sinf
       2CBA  __xidata_start
       2CBA  __text_end
       2CC0  __xidata_end

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

