Project:      output/LCD_Mod_lab2pt2
Build Number: 0
Date:         Sat Jan 16 19:39:14 2016
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   00A8 =    168. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01D4  LoadConfigTBL_lcd_mod_lab2pt2_Bank0
       0223  LoadConfigTBL_lcd_mod_lab2pt2_Bank1
       0248  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   0248   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       0248  __func_lit_start
       024A  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   024A   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       024A  LoadConfigTBL_lcd_mod_lab2pt2_Ordered
       034F  LoadConfigInit
       034F  _LoadConfigInit
       035F  LoadConfig_lcd_mod_lab2pt2
       035F  _LoadConfig_lcd_mod_lab2pt2
       03BA  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   03BA   01B7 =    439. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03BA  _LCD_PrCString
       03BA  LCD_PrCString
       03CC  LCD_HEX_STR
       03DC  LCD_PrHexByte
       03DC  _LCD_PrHexByte
       03EF  _LCD_PrHexInt
       03EF  LCD_PrHexInt
       03F6  _LCD_PrString
       03F6  LCD_PrString
       0408  _LCD_Write_Data
       0408  _LCD_WriteData
       0408  LCD_WriteData
       0408  LCD_Write_Data
       041C  LCD_Control
       041C  _LCD_Control
       04CC  _LCD_Start
       04CC  _LCD_Init
       04CC  LCD_Init
       04CC  LCD_Start
       053B  LCD_ROW_OFFSET
       053F  LCD_Position
       053F  _LCD_Position
       054F  LCD_Delay50uTimes
       054F  _LCD_Delay50uTimes
       0555  LCD_Delay50u_Table
       055D  _LCD_Delay50u
       055D  LCD_Delay50u
       0571  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0571   031A =    794. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0571  _main
       0571  __text_start
       0748  _utoa
       088B  __text_end
       088B  __xidata_start
       088D  __xidata_end

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
               virtual_registers   0003   0007 =      7. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0003  __rZ
       0004  __rY
       0005  __rX
       0006  __r3
       0007  __r2
       0008  __r1
       0009  __r0

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ psocconfigtbl.asm, psocconfig.asm, lcd.asm, rZ.asm, rY.asm, rX.asm, r3.asm, r2.asm, r1.asm, r0.asm ]
[ divmodu_16x16_16_util.asm, i_div16_block_util.asm, utoa.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x3
-Blcd_mod_lab2pt2_RAM
-rwh:SSCParmBlk:0xf7.0xff

