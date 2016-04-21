Project:      output/DataAcquisionSystem
Build Number: 0
Date:         Tue Apr 12 10:33:00 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   064E =   1614. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       05F9  LoadConfigTBL_DataAcqSystem_Bank0
       06A4  LoadConfigTBL_DataAcqSystem_Bank1
       06ED  __ctype
       07EE  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   07EE   0006 =      6. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       07EE  __func_lit_start
       07F4  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   07F4   0167 =    359. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       07F4  LoadConfigTBL_DataAcqSystem_Ordered
       08F9  LoadConfigInit
       08F9  _LoadConfigInit
       0900  _LoadConfig_DataAcqSystem
       0900  LoadConfig_DataAcqSystem
       095B  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   095B   0437 =   1079. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       095B  _UART_TX_ISR
       095C  _UART_RX_ISR
       095D  UART_EnableInt
       095D  _UART_EnableInt
       0964  _UART_DisableInt
       0964  UART_DisableInt
       096B  _UART_SetTxIntMode
       096B  UART_SetTxIntMode
       097D  _UART_Start
       097D  UART_Start
       0984  _UART_Stop
       0984  UART_Stop
       098B  _UART_SendData
       098B  UART_SendData
       098E  _bUART_ReadTxStatus
       098E  bUART_ReadTxStatus
       098E  _UART_bReadTxStatus
       098E  UART_bReadTxStatus
       0991  bUART_ReadRxData
       0991  _UART_bReadRxData
       0991  _bUART_ReadRxData
       0991  UART_bReadRxData
       0994  UART_bReadRxStatus
       0994  _bUART_ReadRxStatus
       0994  _UART_bReadRxStatus
       0994  bUART_ReadRxStatus
       0997  _UART_TxIntMode
       0997  UART_TxIntMode
       09AA  _UART_IntCntl
       09AA  UART_IntCntl
       09D5  UART_PutSHexByte
       09D5  _UART_PutSHexByte
       09E8  _UART_PutSHexInt
       09E8  UART_PutSHexInt
       09EF  _UART_PutChar
       09EF  UART_PutChar
       09F7  UART_cGetChar
       09F7  _UART_cGetChar
       09FF  _UART_cReadChar
       09FF  UART_cReadChar
       0A16  UART_iReadChar
       0A16  _UART_iReadChar
       0A2C  _UART_PutString
       0A2C  UART_PutString
       0A3E  _UART_Write
       0A3E  UART_Write
       0A66  _UART_CWrite
       0A66  UART_CWrite
       0A92  UART_CPutString
       0A92  _UART_CPutString
       0AA4  UART_PutCRLF
       0AA4  _UART_PutCRLF
       0AAD  _SPIM_ISR
       0AAE  SPIM_EnableInt
       0AAE  _SPIM_EnableInt
       0AB2  _SPIM_DisableInt
       0AB2  SPIM_DisableInt
       0AB6  _SPIM_Start
       0AB6  SPIM_Start
       0ABB  _SPIM_Stop
       0ABB  SPIM_Stop
       0ABF  _SPIM_SendTxData
       0ABF  SPIM_SendTxData
       0AC2  _bSPIM_ReadRxData
       0AC2  SPIM_bReadRxData
       0AC2  _SPIM_bReadRxData
       0AC2  bSPIM_ReadRxData
       0AC5  _SPIM_bReadStatus
       0AC5  bSPIM_ReadStatus
       0AC5  SPIM_bReadStatus
       0AC5  _bSPIM_ReadStatus
       0AC8  PGA_SetPower
       0AC8  _PGA_Start
       0AC8  _PGA_SetPower
       0AC8  PGA_Start
       0ADA  _PGA_SetGain
       0ADA  PGA_SetGain
       0B04  _PGA_Stop
       0B04  PGA_Stop
       0B08  _DelSig_ADConversion_ISR
       0B1E  _DelSigClock_ISR
       0B1F  DelSigClock_EnableInt
       0B1F  _DelSigClock_EnableInt
       0B23  _DelSigClock_DisableInt
       0B23  DelSigClock_DisableInt
       0B27  _DelSigClock_Start
       0B27  DelSigClock_Start
       0B2B  _DelSigClock_Stop
       0B2B  DelSigClock_Stop
       0B2F  DelSigClock_WritePeriod
       0B2F  _DelSigClock_WritePeriod
       0B32  DelSigClock_WriteCompareValue
       0B32  _DelSigClock_WriteCompareValue
       0B35  DelSigClock_bReadCompareValue
       0B35  bDelSigClock_ReadCompareValue
       0B35  _DelSigClock_bReadCompareValue
       0B35  _bDelSigClock_ReadCompareValue
       0B38  _DelSigClock_bReadCounter
       0B38  DelSigClock_bReadCounter
       0B38  bDelSigClock_ReadCounter
       0B38  _bDelSigClock_ReadCounter
       0B69  DelSig_SetPower
       0B69  DelSig_Start
       0B69  _DelSig_Start
       0B69  _DelSig_SetPower
       0B83  _DelSig_Stop
       0B83  DelSig_Stop
       0B8A  DelSig_StartAD
       0B8A  _DelSig_StartAD
       0B91  DelSig_StopAD
       0B91  _DelSig_StopAD
       0B98  _DelSig_fIsDataAvailable
       0B98  DelSig_fIsDataAvailable
       0B9E  _DelSig_bGetDataClearFlag
       0B9E  DelSig_cGetDataClearFlag
       0B9E  _DelSig_cGetDataClearFlag
       0B9E  DelSig_bGetDataClearFlag
       0BAD  DelSig_bGetData
       0BAD  DelSig_cGetData
       0BAD  _DelSig_cGetData
       0BAD  _DelSig_bGetData
       0BB3  DelSig_ClearFlag
       0BB3  _DelSig_ClearFlag
       0BBA  _DelSig_WritePulseWidth
       0BBA  DelSig_WritePulseWidth
       0BBD  DACUpdate_EnableInt
       0BBD  _DACUpdate_EnableInt
       0BC1  _DACUpdate_DisableInt
       0BC1  DACUpdate_DisableInt
       0BC5  _DACUpdate_Start
       0BC5  DACUpdate_Start
       0BC9  DACUpdate_Stop
       0BC9  _DACUpdate_Stop
       0BCD  _DACUpdate_WritePeriod
       0BCD  DACUpdate_WritePeriod
       0BD0  DACUpdate_WriteCompareValue
       0BD0  _DACUpdate_WriteCompareValue
       0BD3  _bDACUpdate_ReadCompareValue
       0BD3  DACUpdate_bReadCompareValue
       0BD3  bDACUpdate_ReadCompareValue
       0BD3  _DACUpdate_bReadCompareValue
       0BD6  _bDACUpdate_ReadCounter
       0BD6  bDACUpdate_ReadCounter
       0BD6  DACUpdate_bReadCounter
       0BD6  _DACUpdate_bReadCounter
       0C07  _DAC8B_SetPower
       0C07  DAC8B_SetPower
       0C07  DAC8B_Start
       0C07  _DAC8B_Start
       0C21  _DAC8B_WriteBlind
       0C21  DAC8B_WriteBlind
       0C5B  _DAC8B_WriteBlind2B
       0C5B  DAC8B_WriteBlind2B
       0C66  DAC8B_WriteStall
       0C66  _DAC8B_WriteStall
       0CA6  DAC8B_WriteStall2B
       0CA6  _DAC8B_WriteStall2B
       0CB7  DAC8B_Stop
       0CB7  _DAC8B_Stop
       0CBE  DAC8A_SetPower
       0CBE  _DAC8A_SetPower
       0CBE  _DAC8A_Start
       0CBE  DAC8A_Start
       0CD8  _DAC8A_WriteBlind
       0CD8  DAC8A_WriteBlind
       0D12  DAC8A_WriteBlind2B
       0D12  _DAC8A_WriteBlind2B
       0D1D  DAC8A_WriteStall
       0D1D  _DAC8A_WriteStall
       0D5D  _DAC8A_WriteStall2B
       0D5D  DAC8A_WriteStall2B
       0D6E  _DAC8A_Stop
       0D6E  DAC8A_Stop
       0D75  AMUX4_InputSelect
       0D75  _AMUX4_InputSelect
       0D90  AMUX4_Start
       0D90  _AMUX4_Start
       0D91  AMUX4_Stop
       0D91  _AMUX4_Stop
       0D92  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0D92   2037 =   8247. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0D92  _GetLine
       0D92  __text_start
       0E36  _Lowercase
       0EA5  _PlaySamples
       0FE6  _SampleAnalog
       10C0  _main
       1760  _DACUpdate_ISR
       1771  _SPIRAM_WriteStatusRegister
       17F6  _SPIRAM_ReadStatusRegister
       1862  _SPIRAM_WriteByte
       192F  _SPIRAM_ReadByte
       1A00  _SPIRAM_WriteArray
       1AF4  _SPIRAM_ReadArray
       1C91  _cstrcmpLMM
       1C9C  _cstrcmp
       1CC7  _strlenLMM
       1CD2  _strlen
       1CED  __plcall
       1CF9  _strtol
       211B  _strtoul
       24B1  _isdigit
       24D2  _isspace
       24F3  _isupper
       2514  _isxdigit
       2535  _tolower
       25C1  _csscanf
       2805  __cscanf
       2B6A  _cstrcspn
       2BEC  _cstrpbrk
       2C39  _cstrspn
       2CE6  _cstrtok
       2DC9  __text_end
       2DC9  __xidata_start
       2DE0  __xidata_end

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

