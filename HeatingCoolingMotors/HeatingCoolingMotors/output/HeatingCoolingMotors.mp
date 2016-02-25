Project:      output/HeatingCoolingMotors
Build Number: 0
Date:         Wed Feb 24 08:46:02 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   06DC =   1756. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       064B  LoadConfigTBL_i2cram_Bank0
       06BE  LoadConfigTBL_i2cram_Bank1
       0707  __ctype
       087C  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   087C   0008 =      8. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       087C  __func_lit_start
       0884  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0884   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0884  LoadConfigTBL_i2cram_Ordered
       0989  _LoadConfigInit
       0989  LoadConfigInit
       0999  _LoadConfig_i2cram
       0999  LoadConfig_i2cram
       09F4  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   09F4   07A5 =   1957. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       09F4  _UART_TX_ISR
       09F5  _UART_RX_ISR
       09F6  UART_EnableInt
       09F6  _UART_EnableInt
       09FD  _UART_DisableInt
       09FD  UART_DisableInt
       0A04  _UART_SetTxIntMode
       0A04  UART_SetTxIntMode
       0A16  UART_Start
       0A16  _UART_Start
       0A1D  _UART_Stop
       0A1D  UART_Stop
       0A24  UART_SendData
       0A24  _UART_SendData
       0A27  _UART_bReadTxStatus
       0A27  _bUART_ReadTxStatus
       0A27  UART_bReadTxStatus
       0A27  bUART_ReadTxStatus
       0A2A  _UART_bReadRxData
       0A2A  UART_bReadRxData
       0A2A  _bUART_ReadRxData
       0A2A  bUART_ReadRxData
       0A2D  _bUART_ReadRxStatus
       0A2D  _UART_bReadRxStatus
       0A2D  UART_bReadRxStatus
       0A2D  bUART_ReadRxStatus
       0A30  _UART_TxIntMode
       0A30  UART_TxIntMode
       0A43  UART_IntCntl
       0A43  _UART_IntCntl
       0A6E  _UART_PutSHexByte
       0A6E  UART_PutSHexByte
       0A81  UART_PutSHexInt
       0A81  _UART_PutSHexInt
       0A88  _UART_PutChar
       0A88  UART_PutChar
       0A90  UART_cGetChar
       0A90  _UART_cGetChar
       0A98  UART_cReadChar
       0A98  _UART_cReadChar
       0AAF  UART_iReadChar
       0AAF  _UART_iReadChar
       0AC5  _UART_PutString
       0AC5  UART_PutString
       0AD7  UART_Write
       0AD7  _UART_Write
       0AFF  _UART_CWrite
       0AFF  UART_CWrite
       0B2B  _UART_CPutString
       0B2B  UART_CPutString
       0B3D  UART_PutCRLF
       0B3D  _UART_PutCRLF
       0B46  TempCounter_EnableInt
       0B46  _TempCounter_EnableInt
       0B4A  _TempCounter_DisableInt
       0B4A  TempCounter_DisableInt
       0B4E  _TempCounter_Start
       0B4E  TempCounter_Start
       0B52  TempCounter_Stop
       0B52  _TempCounter_Stop
       0B56  _TempCounter_WritePeriod
       0B56  TempCounter_WritePeriod
       0B5C  TempCounter_WriteCompareValue
       0B5C  _TempCounter_WriteCompareValue
       0B62  _TempCounter_wReadCompareValue
       0B62  TempCounter_wReadCompareValue
       0B62  wTempCounter_ReadCompareValue
       0B62  _wTempCounter_ReadCompareValue
       0B68  _wTempCounter_ReadCounter
       0B68  wTempCounter_ReadCounter
       0B68  TempCounter_wReadCounter
       0B68  _TempCounter_wReadCounter
       0BA6  _MotorDriver_EnableInt
       0BA6  MotorDriver_EnableInt
       0BAA  MotorDriver_DisableInt
       0BAA  _MotorDriver_DisableInt
       0BAE  MotorDriver_Start
       0BAE  _MotorDriver_Start
       0BB2  _MotorDriver_Stop
       0BB2  MotorDriver_Stop
       0BB6  _MotorDriver_WritePeriod
       0BB6  MotorDriver_WritePeriod
       0BBC  MotorDriver_WriteCompareValue
       0BBC  _MotorDriver_WriteCompareValue
       0BC2  wMotorDriver_ReadCompareValue
       0BC2  _wMotorDriver_ReadCompareValue
       0BC2  MotorDriver_wReadCompareValue
       0BC2  _MotorDriver_wReadCompareValue
       0BC8  MotorDriver_wReadCounter
       0BC8  _MotorDriver_wReadCounter
       0BC8  _wMotorDriver_ReadCounter
       0BC8  wMotorDriver_ReadCounter
       0C06  LCD_PrCString
       0C06  _LCD_PrCString
       0C18  LCD_HEX_STR
       0C28  LCD_PrHexByte
       0C28  _LCD_PrHexByte
       0C3B  _LCD_PrHexInt
       0C3B  LCD_PrHexInt
       0C42  LCD_PrString
       0C42  _LCD_PrString
       0C54  _LCD_Write_Data
       0C54  LCD_WriteData
       0C54  LCD_Write_Data
       0C54  _LCD_WriteData
       0C68  LCD_Control
       0C68  _LCD_Control
       0D18  LCD_Init
       0D18  _LCD_Init
       0D18  LCD_Start
       0D18  _LCD_Start
       0D87  LCD_ROW_OFFSET
       0D8B  _LCD_Position
       0D8B  LCD_Position
       0D9B  _LCD_Delay50uTimes
       0D9B  LCD_Delay50uTimes
       0DA1  LCD_Delay50u_Table
       0DA9  LCD_Delay50u
       0DA9  _LCD_Delay50u
       0DBD  _I2CHW_Start
       0DBD  I2CHW_Start
       0DBE  _I2CHW_ResumeInt
       0DBE  I2CHW_ResumeInt
       0DC0  _I2CHW_EnableInt
       0DC0  I2CHW_EnableInt
       0DC7  I2CHW_ClearInt
       0DC7  _I2CHW_ClearInt
       0DCB  _I2CHW_EnableMstr
       0DCB  I2CHW_EnableMstr
       0DDB  I2CHW_Stop
       0DDB  _I2CHW_Stop
       0DDB  I2CHW_DisableInt
       0DDB  _I2CHW_DisableInt
       0DDF  _I2CHW_DisableMstr
       0DDF  I2CHW_DisableMstr
       0DE3  _I2CHW_fReadBytes
       0E27  _I2CHW_bWriteBytes
       0E6B  _I2CHW_bWriteCBytes
       0ED7  _I2CHW_fSendRepeatStart
       0ED7  I2CHW_fSendRepeatStart
       0F13  I2CHW_fSendStart
       0F13  _I2CHW_fSendStart
       0F57  I2CHW_fWrite
       0F57  _I2CHW_fWrite
       0F97  _I2CHW_bRead
       0F97  I2CHW_bRead
       0FCD  _I2CHW_SendStop
       0FCD  I2CHW_SendStop
       0FD6  _I2CHW_bReadBusStatus
       0FD6  I2CHW_bReadBusStatus
       0FDC  _I2CHW_ISR
       1119  I2CHW_InitWrite
       1119  _I2CHW_InitWrite
       1157  I2CHW_InitRamRead
       1157  _I2CHW_InitRamRead
       1184  I2CHW_InitFlashRead
       1184  _I2CHW_InitFlashRead
       1185  I2CHW_bReadI2CStatus
       1185  _I2CHW_bReadI2CStatus
       118B  _I2CHW_ClrRdStatus
       118B  I2CHW_ClrRdStatus
       1192  I2CHW_ClrWrStatus
       1192  _I2CHW_ClrWrStatus
       1199  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   1199   27B3 =  10163. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       1199  _GetLine
       1199  __text_start
       123D  _WriteI2C
       12DE  _ReadI2C
       1341  _Lowercase
       13B0  _IsNumber
       140E  _CheckFan
       144D  _main
       1C9E  _PSoC_GPIO_ISR_C
       1D49  _PSoC_TempCounter_ISR_C
       1D60  _PSoC_MotorDriver_ISR_C
       1EFE  _strlenLMM
       1F09  _strlen
       1F24  __plcall
       1F30  _itoa
       2109  _strtol
       252B  _strtoul
       28C1  _utoa
       2A04  _isdigit
       2A25  _islower
       2A46  _isspace
       2A67  _isupper
       2A88  _isxdigit
       2AA9  _toupper
       2AE7  _tolower
       2B25  __csdepi
       2B57  _csprintf
       2C0E  _csscanf
       2C7A  __cprint
       3388  __cscanf
       36ED  _cstrcspn
       376F  _cstrpbrk
       37BC  _cstrspn
       3869  _cstrtok
       394C  __xidata_start
       394C  __text_end
       396B  __xidata_end

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
               virtual_registers   0075   000F =     15. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0075  __rZ
       0076  __rY
       0077  __rX
       0078  __r11
       0079  __r10
       007A  __r9
       007B  __r8
       007C  __r7
       007D  __r6
       007E  __r5
       007F  __r4
       0080  __r3
       0081  __r2
       0082  __r1
       0083  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0086 =    134. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       000C  _buf
       0084  main.c:stepperSequence
       0088  main.c:rubout
       0092  _errno
       0096  _thermostatMode
       0097  _fanSpeed
       0098  _motorStep
       0099  _tolerance
       009A  _setTemp
       009C  _curTemp
       009D  _checkTemp
       009E  _lcdUpdate
       009F  main.c:slaveAddress
       00A0  _fanMode

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ uartint.asm, uart.asm, tempcounter.asm, psocconfigtbl.asm, psocconfig.asm, motordriver.asm ]
[ lcd.asm, i2chwrsrcinits.asm, i2chwmstr.asm, i2chwint.asm, i2chwcommon.asm, rZ.asm, rY.asm, rX.asm ]
[ r11.asm, r10.asm, r9.asm, r8.asm, r7.asm, r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmodu_16x16_16_util.asm ]
[ divmodu_8x8_8_util.asm, i_div16_block_util.asm, i_div8_block_util.asm, i_mulu8_block_util.asm ]
[ mul32_util.asm, strlen.s, plcall.s, itoa.s, strtol.s, strtoul.s, utoa.s, isdigit.s, islower.s, isspace.s ]
[ isupper.s, isxdigit.s, ctype.s, toupper.s, tolower.s, sprintf.s, sscanf.s, _printf.s, _scanf.s, errno.s ]
[ strcspn.s, strpbrk.s, strspn.s, strtok.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x75
-Bi2cram_RAM
-rwh:SSCParmBlk:0xf7.0xff

