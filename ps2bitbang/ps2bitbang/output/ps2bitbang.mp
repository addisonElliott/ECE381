Project:      output/ps2bitbang
Build Number: 0
Date:         Thu Mar 17 14:46:11 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   046C =   1132. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01A0  _ShiftableScancode
       01E8  _AlphabetScancode
       0239  _ControlScancode
       0279  _KeypadScancode
       0291  _PianoScancode
       04E4  LoadConfigTBL_ps2bitbang_Bank0
       058D  LoadConfigTBL_ps2bitbang_Bank1
       060C  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   060C   0030 =     48. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       060C  __func_lit_start
       063C  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   063C   0173 =    371. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       063C  LoadConfigTBL_ps2bitbang_Ordered
       0741  _LoadConfigInit
       0741  LoadConfigInit
       0754  _LoadConfig_ps2bitbang
       0754  LoadConfig_ps2bitbang
       07AF  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   07AF   054C =   1356. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       07AF  _UART_TX_ISR
       07B0  _UART_RX_ISR
       07B1  _UARTClock_ISR
       07B2  _UARTClock_EnableInt
       07B2  UARTClock_EnableInt
       07B6  UARTClock_DisableInt
       07B6  _UARTClock_DisableInt
       07BA  _UARTClock_Start
       07BA  UARTClock_Start
       07BE  _UARTClock_Stop
       07BE  UARTClock_Stop
       07C2  _UARTClock_WritePeriod
       07C2  UARTClock_WritePeriod
       07C8  UARTClock_WriteCompareValue
       07C8  _UARTClock_WriteCompareValue
       07CE  UARTClock_wReadCompareValue
       07CE  _wUARTClock_ReadCompareValue
       07CE  _UARTClock_wReadCompareValue
       07CE  wUARTClock_ReadCompareValue
       07D4  _UARTClock_wReadCounter
       07D4  wUARTClock_ReadCounter
       07D4  _wUARTClock_ReadCounter
       07D4  UARTClock_wReadCounter
       0812  _UART_EnableInt
       0812  UART_EnableInt
       0819  _UART_DisableInt
       0819  UART_DisableInt
       0820  _UART_SetTxIntMode
       0820  UART_SetTxIntMode
       0832  _UART_Start
       0832  UART_Start
       0839  _UART_Stop
       0839  UART_Stop
       0840  _UART_SendData
       0840  UART_SendData
       0843  bUART_ReadTxStatus
       0843  UART_bReadTxStatus
       0843  _UART_bReadTxStatus
       0843  _bUART_ReadTxStatus
       0846  bUART_ReadRxData
       0846  _UART_bReadRxData
       0846  UART_bReadRxData
       0846  _bUART_ReadRxData
       0849  UART_bReadRxStatus
       0849  _bUART_ReadRxStatus
       0849  _UART_bReadRxStatus
       0849  bUART_ReadRxStatus
       084C  _UART_TxIntMode
       084C  UART_TxIntMode
       085F  UART_IntCntl
       085F  _UART_IntCntl
       088A  UART_PutSHexByte
       088A  _UART_PutSHexByte
       089D  UART_PutSHexInt
       089D  _UART_PutSHexInt
       08A4  _UART_PutChar
       08A4  UART_PutChar
       08AC  UART_cGetChar
       08AC  _UART_cGetChar
       08B4  UART_cReadChar
       08B4  _UART_cReadChar
       08CB  UART_iReadChar
       08CB  _UART_iReadChar
       08E1  UART_PutString
       08E1  _UART_PutString
       08F3  _UART_Write
       08F3  UART_Write
       091B  UART_CWrite
       091B  _UART_CWrite
       0947  _UART_CPutString
       0947  UART_CPutString
       0959  UART_PutCRLF
       0959  _UART_PutCRLF
       0962  TenMicroSecTimer_EnableInt
       0962  _TenMicroSecTimer_EnableInt
       0966  _TenMicroSecTimer_DisableInt
       0966  TenMicroSecTimer_DisableInt
       096A  _TenMicroSecTimer_Start
       096A  TenMicroSecTimer_Start
       096E  _TenMicroSecTimer_Stop
       096E  TenMicroSecTimer_Stop
       0972  TenMicroSecTimer_WritePeriod
       0972  _TenMicroSecTimer_WritePeriod
       0978  TenMicroSecTimer_WriteCompareValue
       0978  _TenMicroSecTimer_WriteCompareValue
       097E  _TenMicroSecTimer_wReadCompareValue
       097E  _wTenMicroSecTimer_ReadCompareValue
       097E  TenMicroSecTimer_wReadCompareValue
       097E  wTenMicroSecTimer_ReadCompareValue
       0984  TenMicroSecTimer_wReadTimerSaveCV
       0984  wTenMicroSecTimer_ReadTimerSaveCV
       0984  _TenMicroSecTimer_wReadTimerSaveCV
       0984  _wTenMicroSecTimer_ReadTimerSaveCV
       0984  wTenMicroSecTimer_ReadCounter
       0984  _wTenMicroSecTimer_ReadCounter
       09BA  wTenMicroSecTimer_ReadTimer
       09BA  wTenMicroSecTimer_CaptureCounter
       09BA  TenMicroSecTimer_wReadTimer
       09BA  _wTenMicroSecTimer_CaptureCounter
       09BA  _TenMicroSecTimer_wReadTimer
       09BA  _wTenMicroSecTimer_ReadTimer
       09C2  _PWMPiano3_ISR
       09C3  PWMPiano3_EnableInt
       09C3  _PWMPiano3_EnableInt
       09C7  PWMPiano3_DisableInt
       09C7  _PWMPiano3_DisableInt
       09CB  PWMPiano3_Start
       09CB  _PWMPiano3_Start
       09CF  _PWMPiano3_Stop
       09CF  PWMPiano3_Stop
       09D3  _PWMPiano3_WritePeriod
       09D3  PWMPiano3_WritePeriod
       09D9  _PWMPiano3_WritePulseWidth
       09D9  PWMPiano3_WritePulseWidth
       09DF  _wPWMPiano3_ReadPulseWidth
       09DF  PWMPiano3_wReadPulseWidth
       09DF  _PWMPiano3_wReadPulseWidth
       09DF  wPWMPiano3_ReadPulseWidth
       09E5  _wPWMPiano3_ReadCounter
       09E5  _PWMPiano3_wReadCounter
       09E5  wPWMPiano3_ReadCounter
       09E5  PWMPiano3_wReadCounter
       0A1F  _PWMPiano2_ISR
       0A20  PWMPiano2_EnableInt
       0A20  _PWMPiano2_EnableInt
       0A24  PWMPiano2_DisableInt
       0A24  _PWMPiano2_DisableInt
       0A28  _PWMPiano2_Start
       0A28  PWMPiano2_Start
       0A2C  PWMPiano2_Stop
       0A2C  _PWMPiano2_Stop
       0A30  PWMPiano2_WritePeriod
       0A30  _PWMPiano2_WritePeriod
       0A36  PWMPiano2_WritePulseWidth
       0A36  _PWMPiano2_WritePulseWidth
       0A3C  PWMPiano2_wReadPulseWidth
       0A3C  _wPWMPiano2_ReadPulseWidth
       0A3C  _PWMPiano2_wReadPulseWidth
       0A3C  wPWMPiano2_ReadPulseWidth
       0A42  _wPWMPiano2_ReadCounter
       0A42  PWMPiano2_wReadCounter
       0A42  _PWMPiano2_wReadCounter
       0A42  wPWMPiano2_ReadCounter
       0A7C  _PWMPiano1_ISR
       0A7D  PWMPiano1_EnableInt
       0A7D  _PWMPiano1_EnableInt
       0A81  _PWMPiano1_DisableInt
       0A81  PWMPiano1_DisableInt
       0A85  _PWMPiano1_Start
       0A85  PWMPiano1_Start
       0A89  _PWMPiano1_Stop
       0A89  PWMPiano1_Stop
       0A8D  PWMPiano1_WritePeriod
       0A8D  _PWMPiano1_WritePeriod
       0A93  _PWMPiano1_WritePulseWidth
       0A93  PWMPiano1_WritePulseWidth
       0A99  _wPWMPiano1_ReadPulseWidth
       0A99  wPWMPiano1_ReadPulseWidth
       0A99  _PWMPiano1_wReadPulseWidth
       0A99  PWMPiano1_wReadPulseWidth
       0A9F  wPWMPiano1_ReadCounter
       0A9F  PWMPiano1_wReadCounter
       0A9F  _wPWMPiano1_ReadCounter
       0A9F  _PWMPiano1_wReadCounter
       0AD9  _PWM8LED_ISR
       0ADA  _PWM8LED_EnableInt
       0ADA  PWM8LED_EnableInt
       0ADE  PWM8LED_DisableInt
       0ADE  _PWM8LED_DisableInt
       0AE2  _PWM8LED_Start
       0AE2  PWM8LED_Start
       0AE6  PWM8LED_Stop
       0AE6  _PWM8LED_Stop
       0AEA  _PWM8LED_WritePeriod
       0AEA  PWM8LED_WritePeriod
       0AED  _PWM8LED_WritePulseWidth
       0AED  PWM8LED_WritePulseWidth
       0AF0  PWM8LED_bReadPulseWidth
       0AF0  bPWM8LED_ReadPulseWidth
       0AF0  _PWM8LED_bReadPulseWidth
       0AF0  _bPWM8LED_ReadPulseWidth
       0AF3  _bPWM8LED_ReadCounter
       0AF3  bPWM8LED_ReadCounter
       0AF3  PWM8LED_bReadCounter
       0AF3  _PWM8LED_bReadCounter
       0B20  _PS2OneShot_Start
       0B20  PS2OneShot_Start
       0B24  PS2OneShot_Stop
       0B24  _PS2OneShot_Stop
       0B28  _PS2OneShot_EnableInt
       0B28  PS2OneShot_EnableInt
       0B2C  _PS2OneShot_DisableInt
       0B2C  PS2OneShot_DisableInt
       0B30  PS2OneShot_ClearInt
       0B30  _PS2OneShot_ClearInt
       0B34  PS2DigBuf_EnableInt
       0B34  _PS2DigBuf_EnableInt
       0B38  PS2DigBuf_DisableInt
       0B38  _PS2DigBuf_DisableInt
       0B3C  PS2DigBuf_Start
       0B3C  _PS2DigBuf_Start
       0B40  PS2DigBuf_Stop
       0B40  _PS2DigBuf_Stop
       0B44  LCD_PrCString
       0B44  _LCD_PrCString
       0B56  LCD_HEX_STR
       0B66  LCD_PrHexByte
       0B66  _LCD_PrHexByte
       0B79  _LCD_PrHexInt
       0B79  LCD_PrHexInt
       0B80  LCD_PrString
       0B80  _LCD_PrString
       0B92  LCD_Write_Data
       0B92  LCD_WriteData
       0B92  _LCD_Write_Data
       0B92  _LCD_WriteData
       0BA6  LCD_Control
       0BA6  _LCD_Control
       0C56  _LCD_Start
       0C56  LCD_Init
       0C56  LCD_Start
       0C56  _LCD_Init
       0CC5  LCD_ROW_OFFSET
       0CC9  _LCD_Position
       0CC9  LCD_Position
       0CD9  _LCD_Delay50uTimes
       0CD9  LCD_Delay50uTimes
       0CDF  LCD_Delay50u_Table
       0CE7  _LCD_Delay50u
       0CE7  LCD_Delay50u
       0CFB  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0CFB   25DD =   9693. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0CFB  __text_start
       0CFB  _KeyboardDecodeData
       0E53  _KeyboardTotalPressed
       1025  _KeyboardToASCII
       1385  _KeyboardAlt
       1455  _KeyboardAction
       1E7B  _main
       2182  _MouseInit
       21BF  _MousePrintRawData
       226D  _MouseCursor
       2732  _PS2_Write_Byte
       2828  _PS2_Send_Command_Process_Response
       2943  _PS2_Detect_Device
       2AC5  _PS2DigBuf_ISR
       2F84  _PS2OneShot_ISR
       2FAD  _TenMicroSecTimer_ISR
       31B8  _floorf
       32D8  __text_end
       32D8  __xidata_start
       32EC  __xidata_end

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
       0000  NO_SHADOW
       0000  Port_1_Data_SHADE
       0000  _NO_SHADOW
       0000  _Port_1_Data_SHADE
       0001  _Port_2_Data_SHADE
       0001  Port_2_Data_SHADE
       0002  Port_2_DriveMode_0_SHADE
       0002  _Port_2_DriveMode_0_SHADE
       0003  Port_2_DriveMode_1_SHADE
       0003  _Port_2_DriveMode_1_SHADE

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0014   000F =     15. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0014  __rZ
       0015  __rY
       0016  __rX
       0017  __r11
       0018  __r10
       0019  __r9
       001A  __r8
       001B  __r7
       001C  __r6
       001D  __r5
       001E  __r4
       001F  __r3
       0020  __r2
       0021  __r1
       0022  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   005D =     93. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       0004  _PS2RxBuffer
       0056  _PS2RxBufIn
       0057  _PS2RxBufOut
       0058  _TenMicroSecTimerReps
       0059  _NumLock
       005A  _CapsLock
       005C  _ShiftDown
       005D  _CtrlDown
       005E  _AltDown
       005F  _PianoMode
       0060  _IsMouse
       0063  _PS2FrameStatus
       0064  _ScrollLock
       0069  ps2.c:PS2FrameState
       006A  ps2.c:PS2DataIn
       006B  ps2.c:PS2DataOut
       006C  ps2.c:XXXForceBadRxParity
       006D  ps2.c:XXXForceBadTxParity

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/keyboard.o	[ keyboard.c ]
obj/main.o	[ main.c ]
obj/mouse.o	[ mouse.c ]
obj/ps2.o	[ ps2.c ]
<library>	[ uartint.asm, uartclockint.asm, uartclock.asm, uart.asm, tenmicrosectimer.asm, pwmpiano3int.asm ]
[ pwmpiano3.asm, pwmpiano2int.asm, pwmpiano2.asm, pwmpiano1int.asm, pwmpiano1.asm, pwm8ledint.asm ]
[ pwm8led.asm, psocconfigtbl.asm, psocconfig.asm, ps2oneshot.asm, ps2digbuf.asm, lcd.asm, rZ.asm ]
[ rY.asm, rX.asm, r11.asm, r10.asm, r9.asm, r8.asm, r7.asm, r6.asm, r5.asm, r4.asm, r3.asm, r2.asm, r1.asm ]
[ r0.asm, divmod_16x16_16_util.asm, fp2long_util.asm, fpcmp_util.asm, i_div16_block_util.asm ]
[ i_div32_not_util.asm, long2fp_util.asm, mul16_util.asm, floorf.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x14
-Bps2bitbang_RAM	allocated at: 0
-rwh:SSCParmBlk:0xf7.0xff

