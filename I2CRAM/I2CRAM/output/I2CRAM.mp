Project:      output/I2CRAM
Build Number: 0
Date:         Mon Feb 15 22:33:30 2016
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
                     psoc_config   0727   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0727  LoadConfigTBL_i2cram_Ordered
       082C  _LoadConfigInit
       082C  LoadConfigInit
       083C  _LoadConfig_i2cram
       083C  LoadConfig_i2cram
       0897  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   0897   0746 =   1862. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0897  _UART_TX_ISR
       0898  _UART_RX_ISR
       0899  UART_EnableInt
       0899  _UART_EnableInt
       08A0  UART_DisableInt
       08A0  _UART_DisableInt
       08A7  UART_SetTxIntMode
       08A7  _UART_SetTxIntMode
       08B9  UART_Start
       08B9  _UART_Start
       08C0  _UART_Stop
       08C0  UART_Stop
       08C7  _UART_SendData
       08C7  UART_SendData
       08CA  _bUART_ReadTxStatus
       08CA  UART_bReadTxStatus
       08CA  _UART_bReadTxStatus
       08CA  bUART_ReadTxStatus
       08CD  bUART_ReadRxData
       08CD  _bUART_ReadRxData
       08CD  _UART_bReadRxData
       08CD  UART_bReadRxData
       08D0  _UART_bReadRxStatus
       08D0  bUART_ReadRxStatus
       08D0  _bUART_ReadRxStatus
       08D0  UART_bReadRxStatus
       08D3  _UART_TxIntMode
       08D3  UART_TxIntMode
       08E6  _UART_IntCntl
       08E6  UART_IntCntl
       0911  UART_PutSHexByte
       0911  _UART_PutSHexByte
       0924  _UART_PutSHexInt
       0924  UART_PutSHexInt
       092B  _UART_PutChar
       092B  UART_PutChar
       0933  _UART_cGetChar
       0933  UART_cGetChar
       093B  _UART_cReadChar
       093B  UART_cReadChar
       0952  _UART_iReadChar
       0952  UART_iReadChar
       0968  _UART_PutString
       0968  UART_PutString
       097A  _UART_Write
       097A  UART_Write
       09A2  _UART_CWrite
       09A2  UART_CWrite
       09CE  UART_CPutString
       09CE  _UART_CPutString
       09E0  UART_PutCRLF
       09E0  _UART_PutCRLF
       09E9  LCD_PrCString
       09E9  _LCD_PrCString
       09FB  LCD_HEX_STR
       0A0B  _LCD_PrHexByte
       0A0B  LCD_PrHexByte
       0A1E  LCD_PrHexInt
       0A1E  _LCD_PrHexInt
       0A25  LCD_PrString
       0A25  _LCD_PrString
       0A37  LCD_WriteData
       0A37  LCD_Write_Data
       0A37  _LCD_Write_Data
       0A37  _LCD_WriteData
       0A4B  LCD_Control
       0A4B  _LCD_Control
       0AFB  LCD_Init
       0AFB  LCD_Start
       0AFB  _LCD_Init
       0AFB  _LCD_Start
       0B6A  LCD_ROW_OFFSET
       0B6E  _LCD_Position
       0B6E  LCD_Position
       0B7E  _LCD_Delay50uTimes
       0B7E  LCD_Delay50uTimes
       0B84  LCD_Delay50u_Table
       0B8C  LCD_Delay50u
       0B8C  _LCD_Delay50u
       0BA0  I2CHW_Start
       0BA0  _I2CHW_Start
       0BA1  _I2CHW_ResumeInt
       0BA1  I2CHW_ResumeInt
       0BA3  _I2CHW_EnableInt
       0BA3  I2CHW_EnableInt
       0BAA  _I2CHW_ClearInt
       0BAA  I2CHW_ClearInt
       0BAE  _I2CHW_EnableMstr
       0BAE  I2CHW_EnableMstr
       0BBE  _I2CHW_Stop
       0BBE  I2CHW_Stop
       0BBE  _I2CHW_DisableInt
       0BBE  I2CHW_DisableInt
       0BC2  I2CHW_DisableMstr
       0BC2  _I2CHW_DisableMstr
       0BC6  _I2CHW_fReadBytes
       0C0A  _I2CHW_bWriteBytes
       0C4E  _I2CHW_bWriteCBytes
       0CBA  I2CHW_fSendRepeatStart
       0CBA  _I2CHW_fSendRepeatStart
       0CF6  I2CHW_fSendStart
       0CF6  _I2CHW_fSendStart
       0D3A  _I2CHW_fWrite
       0D3A  I2CHW_fWrite
       0D7A  _I2CHW_bRead
       0D7A  I2CHW_bRead
       0DB0  I2CHW_SendStop
       0DB0  _I2CHW_SendStop
       0DB9  I2CHW_bReadBusStatus
       0DB9  _I2CHW_bReadBusStatus
       0DBF  _I2CHW_ISR
       0EFC  I2CHW_InitWrite
       0EFC  _I2CHW_InitWrite
       0F3A  _I2CHW_InitRamRead
       0F3A  I2CHW_InitRamRead
       0F67  _I2CHW_InitFlashRead
       0F67  I2CHW_InitFlashRead
       0F68  _I2CHW_bReadI2CStatus
       0F68  I2CHW_bReadI2CStatus
       0F6E  I2CHW_ClrRdStatus
       0F6E  _I2CHW_ClrRdStatus
       0F75  _I2CHW_ClrWrStatus
       0F75  I2CHW_ClrWrStatus
       0F7C  _Counter16_ISR
       0F7D  _Counter16_EnableInt
       0F7D  Counter16_EnableInt
       0F81  Counter16_DisableInt
       0F81  _Counter16_DisableInt
       0F85  Counter16_Start
       0F85  _Counter16_Start
       0F89  Counter16_Stop
       0F89  _Counter16_Stop
       0F8D  _Counter16_WritePeriod
       0F8D  Counter16_WritePeriod
       0F93  _Counter16_WriteCompareValue
       0F93  Counter16_WriteCompareValue
       0F99  Counter16_wReadCompareValue
       0F99  _Counter16_wReadCompareValue
       0F99  _wCounter16_ReadCompareValue
       0F99  wCounter16_ReadCompareValue
       0F9F  _wCounter16_ReadCounter
       0F9F  wCounter16_ReadCounter
       0F9F  _Counter16_wReadCounter
       0F9F  Counter16_wReadCounter
       0FDD  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0FDD   24A8 =   9384. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0FDD  _GetNumber
       0FDD  __text_start
       101C  _GetLine
       10C5  _HexConversion
       11EA  _Lowercase
       1259  _main
       19E0  _memsetLMM
       19EB  _memset
       1A0E  _strcpyLMM
       1A1D  _strcpy
       1A37  _strlenLMM
       1A42  _strlen
       1A5D  __plcall
       1A69  _itoa
       1C42  _strtol
       2064  _strtoul
       23FA  _utoa
       253D  _isdigit
       255E  _islower
       257F  _isspace
       25A0  _isupper
       25C1  _isxdigit
       25E2  _toupper
       2620  _tolower
       265E  __csdepi
       2690  _csprintf
       2747  _csscanf
       27B3  __cprint
       2EC1  __cscanf
       3226  _cstrcspn
       32A8  _cstrpbrk
       32F5  _cstrspn
       33A2  _cstrtok
       3485  __xidata_start
       3485  __text_end
       349D  __xidata_end

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
                    InterruptRAM   0000   000C =     12. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  _NO_SHADOW
       0000  Port_2_Data_SHADE
       0000  _Port_2_Data_SHADE
       0000  NO_SHADOW
       0001  Port_2_DriveMode_0_SHADE
       0001  _Port_2_DriveMode_0_SHADE
       0002  _Port_2_DriveMode_1_SHADE
       0002  Port_2_DriveMode_1_SHADE
       0003  _I2CHW_bStatus
       0003  I2CHW_bStatus
       0004  I2CHW_SlaveAddr
       0004  _I2CHW_SlaveAddr
       0005  I2CHW_RsrcStatus
       0005  _I2CHW_RsrcStatus
       0006  _I2CHW_Write_Count
       0006  I2CHW_Write_Count
       0007  _pI2CHW_Write_BufHI
       0007  pI2CHW_Write_BufHI
       0008  pI2CHW_Write_Buf
       0008  pI2CHW_Write_BufLO
       0008  _pI2CHW_Write_BufLO
       0008  _pI2CHW_Write_Buf
       0009  _pI2CHW_Read_BufHI
       0009  pI2CHW_Read_BufHI
       000A  pI2CHW_Read_Buf
       000A  pI2CHW_Read_BufLO
       000A  _pI2CHW_Read_BufLO
       000A  _pI2CHW_Read_Buf
       000B  _I2CHW_Read_Count
       000B  I2CHW_Read_Count

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0075   000B =     11. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0075  __rZ
       0076  __rY
       0077  __rX
       0078  __r7
       0079  __r6
       007A  __r5
       007B  __r4
       007C  __r3
       007D  __r2
       007E  __r1
       007F  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0178 =    376. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       000C  _buf
       0080  main.c:rubout
       008C  _errno
       0100  _data

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ uartint.asm, uart.asm, psocconfigtbl.asm, psocconfig.asm, lcd.asm, i2chwrsrcinits.asm, i2chwmstr.asm ]
[ i2chwint.asm, i2chwcommon.asm, counter16int.asm, counter16.asm, rZ.asm, rY.asm, rX.asm, r7.asm ]
[ r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmodu_16x16_16_util.asm, i_div16_block_util.asm ]
[ i_mulu8_block_util.asm, mul32_util.asm, memset.s, strcpy.s, strlen.s, plcall.s, itoa.s, strtol.s ]
[ strtoul.s, utoa.s, isdigit.s, islower.s, isspace.s, isupper.s, isxdigit.s, ctype.s, toupper.s, tolower.s ]
[ sprintf.s, sscanf.s, _printf.s, _scanf.s, errno.s, strcspn.s, strpbrk.s, strspn.s, strtok.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x75
-Bi2cram_RAM
-rwh:SSCParmBlk:0xf7.0xff

