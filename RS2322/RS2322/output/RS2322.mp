Project:      output/RS2322
Build Number: 0
Date:         Thu Feb 04 14:46:12 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   015F =    351. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       025B  LoadConfigTBL_rs2322_Bank0
       02C2  LoadConfigTBL_rs2322_Bank1
       02FF  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   02FF   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       02FF  __func_lit_start
       0301  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0301   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0301  LoadConfigTBL_rs2322_Ordered
       0406  LoadConfigInit
       0406  _LoadConfigInit
       0416  LoadConfig_rs2322
       0416  _LoadConfig_rs2322
       0471  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   0471   036A =    874. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0471  _UART_TX_ISR
       0472  _UART_RX_ISR
       0473  _UART_EnableInt
       0473  UART_EnableInt
       047A  _UART_DisableInt
       047A  UART_DisableInt
       0481  UART_SetTxIntMode
       0481  _UART_SetTxIntMode
       0493  _UART_Start
       0493  UART_Start
       049A  _UART_Stop
       049A  UART_Stop
       04A1  UART_SendData
       04A1  _UART_SendData
       04A4  bUART_ReadTxStatus
       04A4  UART_bReadTxStatus
       04A4  _UART_bReadTxStatus
       04A4  _bUART_ReadTxStatus
       04A7  UART_bReadRxData
       04A7  bUART_ReadRxData
       04A7  _bUART_ReadRxData
       04A7  _UART_bReadRxData
       04AA  bUART_ReadRxStatus
       04AA  UART_bReadRxStatus
       04AA  _bUART_ReadRxStatus
       04AA  _UART_bReadRxStatus
       04AD  UART_TxIntMode
       04AD  _UART_TxIntMode
       04C0  UART_IntCntl
       04C0  _UART_IntCntl
       04EB  _UART_PutSHexByte
       04EB  UART_PutSHexByte
       04FE  _UART_PutSHexInt
       04FE  UART_PutSHexInt
       0505  UART_PutChar
       0505  _UART_PutChar
       050D  _UART_cGetChar
       050D  UART_cGetChar
       0515  UART_cReadChar
       0515  _UART_cReadChar
       052C  UART_iReadChar
       052C  _UART_iReadChar
       0542  UART_PutString
       0542  _UART_PutString
       0554  _UART_Write
       0554  UART_Write
       057C  UART_CWrite
       057C  _UART_CWrite
       05A8  UART_CPutString
       05A8  _UART_CPutString
       05BA  _UART_PutCRLF
       05BA  UART_PutCRLF
       05C3  _LCD_PrCString
       05C3  LCD_PrCString
       05D5  LCD_HEX_STR
       05E5  _LCD_PrHexByte
       05E5  LCD_PrHexByte
       05F8  _LCD_PrHexInt
       05F8  LCD_PrHexInt
       05FF  _LCD_PrString
       05FF  LCD_PrString
       0611  _LCD_Write_Data
       0611  LCD_Write_Data
       0611  LCD_WriteData
       0611  _LCD_WriteData
       0625  LCD_Control
       0625  _LCD_Control
       06D5  _LCD_Init
       06D5  LCD_Init
       06D5  LCD_Start
       06D5  _LCD_Start
       0744  LCD_ROW_OFFSET
       0748  LCD_Position
       0748  _LCD_Position
       0758  _LCD_Delay50uTimes
       0758  LCD_Delay50uTimes
       075E  LCD_Delay50u_Table
       0766  LCD_Delay50u
       0766  _LCD_Delay50u
       077A  _Counter16_ISR
       077B  Counter16_EnableInt
       077B  _Counter16_EnableInt
       077F  Counter16_DisableInt
       077F  _Counter16_DisableInt
       0783  Counter16_Start
       0783  _Counter16_Start
       0787  Counter16_Stop
       0787  _Counter16_Stop
       078B  Counter16_WritePeriod
       078B  _Counter16_WritePeriod
       0791  _Counter16_WriteCompareValue
       0791  Counter16_WriteCompareValue
       0797  _wCounter16_ReadCompareValue
       0797  wCounter16_ReadCompareValue
       0797  _Counter16_wReadCompareValue
       0797  Counter16_wReadCompareValue
       079D  Counter16_wReadCounter
       079D  _wCounter16_ReadCounter
       079D  _Counter16_wReadCounter
       079D  wCounter16_ReadCounter
       07DB  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   07DB   02DC =    732. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       07DB  __text_start
       07DB  _GetNumber
       081A  _GetLine
       08B7  _main
       0A89  _memsetLMM
       0A94  _memset
       0AB7  __xidata_start
       0AB7  __text_end
       0AC4  __xidata_end

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
                    InterruptRAM   0000   0003 =      3. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  _NO_SHADOW
       0000  Port_2_Data_SHADE
       0000  NO_SHADOW
       0000  _Port_2_Data_SHADE
       0001  _Port_2_DriveMode_0_SHADE
       0001  Port_2_DriveMode_0_SHADE
       0002  _Port_2_DriveMode_1_SHADE
       0002  Port_2_DriveMode_1_SHADE

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0047   0005 =      5. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0047  __rY
       0048  __rX
       0049  __r2
       004A  __r1
       004B  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0048 =     72. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       0003  _str
       004C  main.c:rubout

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ uartint.asm, uart.asm, psocconfigtbl.asm, psocconfig.asm, lcd.asm, counter16int.asm, counter16.asm ]
[ rY.asm, rX.asm, r2.asm, r1.asm, r0.asm, mul16_util.asm, memset.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x47
-Brs2322_RAM
-rwh:SSCParmBlk:0xf7.0xff

