Project:      output/DataAcquisionSystem
Build Number: 0
Date:         Mon Apr 11 21:27:05 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   0658 =   1624. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       0603  LoadConfigTBL_DataAcqSystem_Bank0
       06AE  LoadConfigTBL_DataAcqSystem_Bank1
       06F7  __ctype
       07F8  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   07F8   0006 =      6. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       07F8  __func_lit_start
       07FE  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   07FE   0167 =    359. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       07FE  LoadConfigTBL_DataAcqSystem_Ordered
       0903  LoadConfigInit
       0903  _LoadConfigInit
       090A  _LoadConfig_DataAcqSystem
       090A  LoadConfig_DataAcqSystem
       0965  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   0965   0437 =   1079. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0965  _UART_TX_ISR
       0966  _UART_RX_ISR
       0967  UART_EnableInt
       0967  _UART_EnableInt
       096E  _UART_DisableInt
       096E  UART_DisableInt
       0975  _UART_SetTxIntMode
       0975  UART_SetTxIntMode
       0987  _UART_Start
       0987  UART_Start
       098E  _UART_Stop
       098E  UART_Stop
       0995  _UART_SendData
       0995  UART_SendData
       0998  _bUART_ReadTxStatus
       0998  bUART_ReadTxStatus
       0998  _UART_bReadTxStatus
       0998  UART_bReadTxStatus
       099B  bUART_ReadRxData
       099B  _UART_bReadRxData
       099B  _bUART_ReadRxData
       099B  UART_bReadRxData
       099E  UART_bReadRxStatus
       099E  _bUART_ReadRxStatus
       099E  _UART_bReadRxStatus
       099E  bUART_ReadRxStatus
       09A1  _UART_TxIntMode
       09A1  UART_TxIntMode
       09B4  _UART_IntCntl
       09B4  UART_IntCntl
       09DF  UART_PutSHexByte
       09DF  _UART_PutSHexByte
       09F2  _UART_PutSHexInt
       09F2  UART_PutSHexInt
       09F9  _UART_PutChar
       09F9  UART_PutChar
       0A01  UART_cGetChar
       0A01  _UART_cGetChar
       0A09  _UART_cReadChar
       0A09  UART_cReadChar
       0A20  UART_iReadChar
       0A20  _UART_iReadChar
       0A36  _UART_PutString
       0A36  UART_PutString
       0A48  _UART_Write
       0A48  UART_Write
       0A70  _UART_CWrite
       0A70  UART_CWrite
       0A9C  UART_CPutString
       0A9C  _UART_CPutString
       0AAE  UART_PutCRLF
       0AAE  _UART_PutCRLF
       0AB7  _SPIM_ISR
       0AB8  SPIM_EnableInt
       0AB8  _SPIM_EnableInt
       0ABC  _SPIM_DisableInt
       0ABC  SPIM_DisableInt
       0AC0  _SPIM_Start
       0AC0  SPIM_Start
       0AC5  _SPIM_Stop
       0AC5  SPIM_Stop
       0AC9  _SPIM_SendTxData
       0AC9  SPIM_SendTxData
       0ACC  _bSPIM_ReadRxData
       0ACC  SPIM_bReadRxData
       0ACC  _SPIM_bReadRxData
       0ACC  bSPIM_ReadRxData
       0ACF  _SPIM_bReadStatus
       0ACF  bSPIM_ReadStatus
       0ACF  SPIM_bReadStatus
       0ACF  _bSPIM_ReadStatus
       0AD2  PGA_SetPower
       0AD2  _PGA_Start
       0AD2  _PGA_SetPower
       0AD2  PGA_Start
       0AE4  _PGA_SetGain
       0AE4  PGA_SetGain
       0B0E  _PGA_Stop
       0B0E  PGA_Stop
       0B12  _DelSig_ADConversion_ISR
       0B28  _DelSigClock_ISR
       0B29  DelSigClock_EnableInt
       0B29  _DelSigClock_EnableInt
       0B2D  _DelSigClock_DisableInt
       0B2D  DelSigClock_DisableInt
       0B31  _DelSigClock_Start
       0B31  DelSigClock_Start
       0B35  _DelSigClock_Stop
       0B35  DelSigClock_Stop
       0B39  DelSigClock_WritePeriod
       0B39  _DelSigClock_WritePeriod
       0B3C  DelSigClock_WriteCompareValue
       0B3C  _DelSigClock_WriteCompareValue
       0B3F  DelSigClock_bReadCompareValue
       0B3F  bDelSigClock_ReadCompareValue
       0B3F  _DelSigClock_bReadCompareValue
       0B3F  _bDelSigClock_ReadCompareValue
       0B42  _DelSigClock_bReadCounter
       0B42  DelSigClock_bReadCounter
       0B42  bDelSigClock_ReadCounter
       0B42  _bDelSigClock_ReadCounter
       0B73  DelSig_SetPower
       0B73  DelSig_Start
       0B73  _DelSig_Start
       0B73  _DelSig_SetPower
       0B8D  _DelSig_Stop
       0B8D  DelSig_Stop
       0B94  DelSig_StartAD
       0B94  _DelSig_StartAD
       0B9B  DelSig_StopAD
       0B9B  _DelSig_StopAD
       0BA2  _DelSig_fIsDataAvailable
       0BA2  DelSig_fIsDataAvailable
       0BA8  _DelSig_bGetDataClearFlag
       0BA8  DelSig_cGetDataClearFlag
       0BA8  _DelSig_cGetDataClearFlag
       0BA8  DelSig_bGetDataClearFlag
       0BB7  DelSig_bGetData
       0BB7  DelSig_cGetData
       0BB7  _DelSig_cGetData
       0BB7  _DelSig_bGetData
       0BBD  DelSig_ClearFlag
       0BBD  _DelSig_ClearFlag
       0BC4  _DelSig_WritePulseWidth
       0BC4  DelSig_WritePulseWidth
       0BC7  DACUpdate_EnableInt
       0BC7  _DACUpdate_EnableInt
       0BCB  _DACUpdate_DisableInt
       0BCB  DACUpdate_DisableInt
       0BCF  _DACUpdate_Start
       0BCF  DACUpdate_Start
       0BD3  DACUpdate_Stop
       0BD3  _DACUpdate_Stop
       0BD7  _DACUpdate_WritePeriod
       0BD7  DACUpdate_WritePeriod
       0BDA  DACUpdate_WriteCompareValue
       0BDA  _DACUpdate_WriteCompareValue
       0BDD  _bDACUpdate_ReadCompareValue
       0BDD  DACUpdate_bReadCompareValue
       0BDD  bDACUpdate_ReadCompareValue
       0BDD  _DACUpdate_bReadCompareValue
       0BE0  _bDACUpdate_ReadCounter
       0BE0  bDACUpdate_ReadCounter
       0BE0  DACUpdate_bReadCounter
       0BE0  _DACUpdate_bReadCounter
       0C11  _DAC8B_SetPower
       0C11  DAC8B_SetPower
       0C11  DAC8B_Start
       0C11  _DAC8B_Start
       0C2B  _DAC8B_WriteBlind
       0C2B  DAC8B_WriteBlind
       0C65  _DAC8B_WriteBlind2B
       0C65  DAC8B_WriteBlind2B
       0C70  DAC8B_WriteStall
       0C70  _DAC8B_WriteStall
       0CB0  DAC8B_WriteStall2B
       0CB0  _DAC8B_WriteStall2B
       0CC1  DAC8B_Stop
       0CC1  _DAC8B_Stop
       0CC8  DAC8A_SetPower
       0CC8  _DAC8A_SetPower
       0CC8  _DAC8A_Start
       0CC8  DAC8A_Start
       0CE2  _DAC8A_WriteBlind
       0CE2  DAC8A_WriteBlind
       0D1C  DAC8A_WriteBlind2B
       0D1C  _DAC8A_WriteBlind2B
       0D27  DAC8A_WriteStall
       0D27  _DAC8A_WriteStall
       0D67  _DAC8A_WriteStall2B
       0D67  DAC8A_WriteStall2B
       0D78  _DAC8A_Stop
       0D78  DAC8A_Stop
       0D7F  AMUX4_InputSelect
       0D7F  _AMUX4_InputSelect
       0D9A  AMUX4_Start
       0D9A  _AMUX4_Start
       0D9B  AMUX4_Stop
       0D9B  _AMUX4_Stop
       0D9C  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0D9C   208E =   8334. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0D9C  _GetLine
       0D9C  __text_start
       0E40  _Lowercase
       0EAF  _GetNumber
       0EF1  _PlaySamples
       102D  _SampleAnalog
       1121  _main
       17C1  _DACUpdate_ISR
       17D2  _SPIRAM_WriteStatusRegister
       1857  _SPIRAM_ReadStatusRegister
       18C3  _SPIRAM_WriteByte
       1990  _SPIRAM_ReadByte
       1A61  _SPIRAM_WriteArray
       1B55  _SPIRAM_ReadArray
       1CF2  _cstrcmpLMM
       1CFD  _cstrcmp
       1D28  _strlenLMM
       1D33  _strlen
       1D4E  __plcall
       1D5A  _strtol
       217C  _strtoul
       2512  _isdigit
       2533  _isspace
       2554  _isupper
       2575  _isxdigit
       2596  _tolower
       2622  _csscanf
       2866  __cscanf
       2BCB  _cstrcspn
       2C4D  _cstrpbrk
       2C9A  _cstrspn
       2D47  _cstrtok
       2E2A  __text_end
       2E2A  __xidata_start
       2E41  __xidata_end

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
                    InterruptRAM   0000   0002 =      2. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  NO_SHADOW
       0000  _NO_SHADOW
       0000  DelSig_cResult
       0000  _DelSig_cResult
       0001  DelSig_bfStatus
       0001  _DelSig_bfStatus

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0052   000B =     11. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0052  __rZ
       0053  __rY
       0054  __rX
       0055  __r7
       0056  __r6
       0057  __r5
       0058  __r4
       0059  __r3
       005A  __r2
       005B  __r1
       005C  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0062 =     98. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       0002  _buf
       0061  _triggerAddress
       0067  _errno
       006B  _chBMemBlk
       006C  _DACUpdateDone
       006E  _chAMemBlk

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
obj/spi_sram.o	[ spi_sram.c ]
<library>	[ uartint.asm, uart.asm, spimint.asm, spim.asm, psocconfigtbl.asm, psocconfig.asm, pga.asm, delsigint.asm ]
[ delsigclockint.asm, delsigclock.asm, delsig.asm, dacupdate.asm, dac8b.asm, dac8a.asm, amux4.asm ]
[ rZ.asm, rY.asm, rX.asm, r7.asm, r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, i_mulu8_block_util.asm ]
[ mul32_util.asm, cstrcmp.s, strlen.s, plcall.s, strtol.s, strtoul.s, isdigit.s, isspace.s, isupper.s ]
[ isxdigit.s, ctype.s, tolower.s, sscanf.s, _scanf.s, errno.s, strcspn.s, strpbrk.s, strspn.s, strtok.s ]


Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x52
-BDataAcqSystem_RAM
-rwh:SSCParmBlk:0xf7.0xff

