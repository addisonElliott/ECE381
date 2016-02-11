Project:      output/I2CRAM
Build Number: 0
Date:         Tue Feb 09 08:45:57 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   0335 =    821. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       02BC  LoadConfigTBL_i2cram_Bank0
       0323  LoadConfigTBL_i2cram_Bank1
       0360  __ctype
       04D5  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   04D5   0008 =      8. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       04D5  __func_lit_start
       04DD  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   04DD   0167 =    359. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       04DD  LoadConfigTBL_i2cram_Ordered
       05E2  _LoadConfigInit
       05E2  LoadConfigInit
       05E9  _LoadConfig_i2cram
       05E9  LoadConfig_i2cram
       0644  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   0644   058F =   1423. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0644  _UART_TX_ISR
       0645  _UART_RX_ISR
       0646  _UART_EnableInt
       0646  UART_EnableInt
       064D  _UART_DisableInt
       064D  UART_DisableInt
       0654  UART_SetTxIntMode
       0654  _UART_SetTxIntMode
       0666  _UART_Start
       0666  UART_Start
       066D  _UART_Stop
       066D  UART_Stop
       0674  _UART_SendData
       0674  UART_SendData
       0677  UART_bReadTxStatus
       0677  _UART_bReadTxStatus
       0677  bUART_ReadTxStatus
       0677  _bUART_ReadTxStatus
       067A  UART_bReadRxData
       067A  _bUART_ReadRxData
       067A  _UART_bReadRxData
       067A  bUART_ReadRxData
       067D  UART_bReadRxStatus
       067D  _bUART_ReadRxStatus
       067D  bUART_ReadRxStatus
       067D  _UART_bReadRxStatus
       0680  UART_TxIntMode
       0680  _UART_TxIntMode
       0693  UART_IntCntl
       0693  _UART_IntCntl
       06BE  _UART_PutSHexByte
       06BE  UART_PutSHexByte
       06D1  UART_PutSHexInt
       06D1  _UART_PutSHexInt
       06D8  _UART_PutChar
       06D8  UART_PutChar
       06E0  _UART_cGetChar
       06E0  UART_cGetChar
       06E8  _UART_cReadChar
       06E8  UART_cReadChar
       06FF  _UART_iReadChar
       06FF  UART_iReadChar
       0715  UART_PutString
       0715  _UART_PutString
       0727  _UART_Write
       0727  UART_Write
       074F  UART_CWrite
       074F  _UART_CWrite
       077B  UART_CPutString
       077B  _UART_CPutString
       078D  _UART_PutCRLF
       078D  UART_PutCRLF
       0796  I2CHW_Start
       0796  _I2CHW_Start
       0797  I2CHW_ResumeInt
       0797  _I2CHW_ResumeInt
       0799  I2CHW_EnableInt
       0799  _I2CHW_EnableInt
       07A0  _I2CHW_ClearInt
       07A0  I2CHW_ClearInt
       07A4  I2CHW_EnableMstr
       07A4  _I2CHW_EnableMstr
       07B4  I2CHW_Stop
       07B4  _I2CHW_Stop
       07B4  I2CHW_DisableInt
       07B4  _I2CHW_DisableInt
       07B8  _I2CHW_DisableMstr
       07B8  I2CHW_DisableMstr
       07BC  _I2CHW_fReadBytes
       0800  _I2CHW_bWriteBytes
       0844  _I2CHW_bWriteCBytes
       08B0  I2CHW_fSendRepeatStart
       08B0  _I2CHW_fSendRepeatStart
       08EC  I2CHW_fSendStart
       08EC  _I2CHW_fSendStart
       0930  _I2CHW_fWrite
       0930  I2CHW_fWrite
       0970  I2CHW_bRead
       0970  _I2CHW_bRead
       09A6  _I2CHW_SendStop
       09A6  I2CHW_SendStop
       09AF  _I2CHW_bReadBusStatus
       09AF  I2CHW_bReadBusStatus
       09B5  _I2CHW_ISR
       0AF2  _I2CHW_InitWrite
       0AF2  I2CHW_InitWrite
       0B30  _I2CHW_InitRamRead
       0B30  I2CHW_InitRamRead
       0B5D  _I2CHW_InitFlashRead
       0B5D  I2CHW_InitFlashRead
       0B5E  I2CHW_bReadI2CStatus
       0B5E  _I2CHW_bReadI2CStatus
       0B64  _I2CHW_ClrRdStatus
       0B64  I2CHW_ClrRdStatus
       0B6B  _I2CHW_ClrWrStatus
       0B6B  I2CHW_ClrWrStatus
       0B72  _Counter16_ISR
       0B73  Counter16_EnableInt
       0B73  _Counter16_EnableInt
       0B77  _Counter16_DisableInt
       0B77  Counter16_DisableInt
       0B7B  _Counter16_Start
       0B7B  Counter16_Start
       0B7F  _Counter16_Stop
       0B7F  Counter16_Stop
       0B83  Counter16_WritePeriod
       0B83  _Counter16_WritePeriod
       0B89  Counter16_WriteCompareValue
       0B89  _Counter16_WriteCompareValue
       0B8F  _Counter16_wReadCompareValue
       0B8F  _wCounter16_ReadCompareValue
       0B8F  Counter16_wReadCompareValue
       0B8F  wCounter16_ReadCompareValue
       0B95  Counter16_wReadCounter
       0B95  wCounter16_ReadCounter
       0B95  _Counter16_wReadCounter
       0B95  _wCounter16_ReadCounter
       0BD3  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0BD3   2251 =   8785. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0BD3  _GetNumber
       0BD3  __text_start
       0C12  _GetLine
       0CBB  _HexConversion
       0DCC  _Lowercase
       0E3B  _main
       13AD  _strcpyLMM
       13BC  _strcpy
       13D6  _strlenLMM
       13E1  _strlen
       13FC  __plcall
       1408  _itoa
       15E1  _strtol
       1A03  _strtoul
       1D99  _utoa
       1EDC  _isdigit
       1EFD  _islower
       1F1E  _isspace
       1F3F  _isupper
       1F60  _isxdigit
       1F81  _toupper
       1FBF  _tolower
       1FFD  __csdepi
       202F  _csprintf
       20E6  _csscanf
       2152  __cprint
       2860  __cscanf
       2BC5  _cstrcspn
       2C47  _cstrpbrk
       2C94  _cstrspn
       2D41  _cstrtok
       2E24  __xidata_start
       2E24  __text_end
       2E34  __xidata_end

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
               virtual_registers   0073   000B =     11. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0073  __rZ
       0074  __rY
       0075  __rX
       0076  __r7
       0077  __r6
       0078  __r5
       0079  __r4
       007A  __r3
       007B  __r2
       007C  __r1
       007D  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0079 =    121. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       0009  _buf
       007E  main.c:rubout
       0084  _errno

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ uartint.asm, uart.asm, psocconfigtbl.asm, psocconfig.asm, i2chwrsrcinits.asm, i2chwmstr.asm ]
[ i2chwint.asm, i2chwcommon.asm, counter16int.asm, counter16.asm, rZ.asm, rY.asm, rX.asm, r7.asm ]
[ r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmodu_16x16_16_util.asm, i_div16_block_util.asm ]
[ i_mulu8_block_util.asm, mul32_util.asm, strcpy.s, strlen.s, plcall.s, itoa.s, strtol.s, strtoul.s ]
[ utoa.s, isdigit.s, islower.s, isspace.s, isupper.s, isxdigit.s, ctype.s, toupper.s, tolower.s, sprintf.s ]
[ sscanf.s, _printf.s, _scanf.s, errno.s, strcspn.s, strpbrk.s, strspn.s, strtok.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x73
-Bi2cram_RAM
-rwh:SSCParmBlk:0xf7.0xff

