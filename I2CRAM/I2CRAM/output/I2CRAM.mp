Project:      output/I2CRAM
Build Number: 0
Date:         Mon Feb 29 10:44:18 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   057F =   1407. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       0506  LoadConfigTBL_i2cram_Bank0
       056D  LoadConfigTBL_i2cram_Bank1
       05AA  __ctype
       071F  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   071F   0008 =      8. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       071F  __func_lit_start
       0727  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0727   0167 =    359. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0727  LoadConfigTBL_i2cram_Ordered
       082C  _LoadConfigInit
       082C  LoadConfigInit
       0833  _LoadConfig_i2cram
       0833  LoadConfig_i2cram
       088E  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   088E   058F =   1423. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       088E  _UART_TX_ISR
       088F  _UART_RX_ISR
       0890  _UART_EnableInt
       0890  UART_EnableInt
       0897  _UART_DisableInt
       0897  UART_DisableInt
       089E  UART_SetTxIntMode
       089E  _UART_SetTxIntMode
       08B0  _UART_Start
       08B0  UART_Start
       08B7  _UART_Stop
       08B7  UART_Stop
       08BE  _UART_SendData
       08BE  UART_SendData
       08C1  UART_bReadTxStatus
       08C1  _UART_bReadTxStatus
       08C1  bUART_ReadTxStatus
       08C1  _bUART_ReadTxStatus
       08C4  UART_bReadRxData
       08C4  _bUART_ReadRxData
       08C4  _UART_bReadRxData
       08C4  bUART_ReadRxData
       08C7  UART_bReadRxStatus
       08C7  _bUART_ReadRxStatus
       08C7  bUART_ReadRxStatus
       08C7  _UART_bReadRxStatus
       08CA  UART_TxIntMode
       08CA  _UART_TxIntMode
       08DD  UART_IntCntl
       08DD  _UART_IntCntl
       0908  _UART_PutSHexByte
       0908  UART_PutSHexByte
       091B  UART_PutSHexInt
       091B  _UART_PutSHexInt
       0922  _UART_PutChar
       0922  UART_PutChar
       092A  _UART_cGetChar
       092A  UART_cGetChar
       0932  _UART_cReadChar
       0932  UART_cReadChar
       0949  _UART_iReadChar
       0949  UART_iReadChar
       095F  UART_PutString
       095F  _UART_PutString
       0971  _UART_Write
       0971  UART_Write
       0999  UART_CWrite
       0999  _UART_CWrite
       09C5  UART_CPutString
       09C5  _UART_CPutString
       09D7  _UART_PutCRLF
       09D7  UART_PutCRLF
       09E0  I2CHW_Start
       09E0  _I2CHW_Start
       09E1  I2CHW_ResumeInt
       09E1  _I2CHW_ResumeInt
       09E3  I2CHW_EnableInt
       09E3  _I2CHW_EnableInt
       09EA  _I2CHW_ClearInt
       09EA  I2CHW_ClearInt
       09EE  I2CHW_EnableMstr
       09EE  _I2CHW_EnableMstr
       09FE  I2CHW_Stop
       09FE  _I2CHW_Stop
       09FE  I2CHW_DisableInt
       09FE  _I2CHW_DisableInt
       0A02  _I2CHW_DisableMstr
       0A02  I2CHW_DisableMstr
       0A06  _I2CHW_fReadBytes
       0A4A  _I2CHW_bWriteBytes
       0A8E  _I2CHW_bWriteCBytes
       0AFA  I2CHW_fSendRepeatStart
       0AFA  _I2CHW_fSendRepeatStart
       0B36  I2CHW_fSendStart
       0B36  _I2CHW_fSendStart
       0B7A  _I2CHW_fWrite
       0B7A  I2CHW_fWrite
       0BBA  I2CHW_bRead
       0BBA  _I2CHW_bRead
       0BF0  _I2CHW_SendStop
       0BF0  I2CHW_SendStop
       0BF9  _I2CHW_bReadBusStatus
       0BF9  I2CHW_bReadBusStatus
       0BFF  _I2CHW_ISR
       0D3C  _I2CHW_InitWrite
       0D3C  I2CHW_InitWrite
       0D7A  _I2CHW_InitRamRead
       0D7A  I2CHW_InitRamRead
       0DA7  _I2CHW_InitFlashRead
       0DA7  I2CHW_InitFlashRead
       0DA8  I2CHW_bReadI2CStatus
       0DA8  _I2CHW_bReadI2CStatus
       0DAE  _I2CHW_ClrRdStatus
       0DAE  I2CHW_ClrRdStatus
       0DB5  _I2CHW_ClrWrStatus
       0DB5  I2CHW_ClrWrStatus
       0DBC  _Counter16_ISR
       0DBD  Counter16_EnableInt
       0DBD  _Counter16_EnableInt
       0DC1  _Counter16_DisableInt
       0DC1  Counter16_DisableInt
       0DC5  _Counter16_Start
       0DC5  Counter16_Start
       0DC9  _Counter16_Stop
       0DC9  Counter16_Stop
       0DCD  Counter16_WritePeriod
       0DCD  _Counter16_WritePeriod
       0DD3  Counter16_WriteCompareValue
       0DD3  _Counter16_WriteCompareValue
       0DD9  _Counter16_wReadCompareValue
       0DD9  _wCounter16_ReadCompareValue
       0DD9  Counter16_wReadCompareValue
       0DD9  wCounter16_ReadCompareValue
       0DDF  Counter16_wReadCounter
       0DDF  wCounter16_ReadCounter
       0DDF  _Counter16_wReadCounter
       0DDF  _wCounter16_ReadCounter
       0E1D  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0E1D   2425 =   9253. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0E1D  _GetNumber
       0E1D  __text_start
       0E5C  _GetLine
       0F00  _HexConversion
       1025  _Lowercase
       1094  _main
       179D  _memsetLMM
       17A8  _memset
       17CB  _strcpyLMM
       17DA  _strcpy
       17F4  _strlenLMM
       17FF  _strlen
       181A  __plcall
       1826  _itoa
       19FF  _strtol
       1E21  _strtoul
       21B7  _utoa
       22FA  _isdigit
       231B  _islower
       233C  _isspace
       235D  _isupper
       237E  _isxdigit
       239F  _toupper
       23DD  _tolower
       241B  __csdepi
       244D  _csprintf
       2504  _csscanf
       2570  __cprint
       2C7E  __cscanf
       2FE3  _cstrcspn
       3065  _cstrpbrk
       30B2  _cstrspn
       315F  _cstrtok
       3242  __xidata_start
       3242  __text_end
       325A  __xidata_end

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
                    InterruptRAM   0000   0009 =      9. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  _I2CHW_bStatus
       0000  _NO_SHADOW
       0000  NO_SHADOW
       0000  I2CHW_bStatus
       0001  _I2CHW_SlaveAddr
       0001  I2CHW_SlaveAddr
       0002  I2CHW_RsrcStatus
       0002  _I2CHW_RsrcStatus
       0003  _I2CHW_Write_Count
       0003  I2CHW_Write_Count
       0004  pI2CHW_Write_BufHI
       0004  _pI2CHW_Write_BufHI
       0005  pI2CHW_Write_BufLO
       0005  _pI2CHW_Write_Buf
       0005  _pI2CHW_Write_BufLO
       0005  pI2CHW_Write_Buf
       0006  _pI2CHW_Read_BufHI
       0006  pI2CHW_Read_BufHI
       0007  _pI2CHW_Read_BufLO
       0007  pI2CHW_Read_Buf
       0007  pI2CHW_Read_BufLO
       0007  _pI2CHW_Read_Buf
       0008  _I2CHW_Read_Count
       0008  I2CHW_Read_Count

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0072   000B =     11. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0072  __rZ
       0073  __rY
       0074  __rX
       0075  __r7
       0076  __r6
       0077  __r5
       0078  __r4
       0079  __r3
       007A  __r2
       007B  __r1
       007C  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0178 =    376. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       0009  _buf
       007D  main.c:rubout
       0089  _errno
       0100  _data

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ uartint.asm, uart.asm, psocconfigtbl.asm, psocconfig.asm, i2chwrsrcinits.asm, i2chwmstr.asm ]
[ i2chwint.asm, i2chwcommon.asm, counter16int.asm, counter16.asm, rZ.asm, rY.asm, rX.asm, r7.asm ]
[ r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmodu_16x16_16_util.asm, i_div16_block_util.asm ]
[ i_mulu8_block_util.asm, mul32_util.asm, memset.s, strcpy.s, strlen.s, plcall.s, itoa.s, strtol.s ]
[ strtoul.s, utoa.s, isdigit.s, islower.s, isspace.s, isupper.s, isxdigit.s, ctype.s, toupper.s, tolower.s ]
[ sprintf.s, sscanf.s, _printf.s, _scanf.s, errno.s, strcspn.s, strpbrk.s, strspn.s, strtok.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x72
-Bi2cram_RAM
-rwh:SSCParmBlk:0xf7.0xff

