/******************************************************************************
*  Generated by PSoC Designer 5.4.3191
******************************************************************************/
#include <m8c.h>
/*
*   PSoCGPIOINT.h
*   Data: 04 June, 2002
*   Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
*
*  This file is generated by the Device Editor on Application Generation.
*  It contains equates that are useful in writing code relating to GPIO
*  related values.
*  
*  DO NOT EDIT THIS FILE MANUALLY, AS IT IS OVERWRITTEN!!!
*  Edits to this file will not be preserved.
*/
// OpEncB address and mask defines
#pragma	ioport	OpEncB_Data_ADDR:	0x4
BYTE			OpEncB_Data_ADDR;
#pragma	ioport	OpEncB_DriveMode_0_ADDR:	0x104
BYTE			OpEncB_DriveMode_0_ADDR;
#pragma	ioport	OpEncB_DriveMode_1_ADDR:	0x105
BYTE			OpEncB_DriveMode_1_ADDR;
#pragma	ioport	OpEncB_DriveMode_2_ADDR:	0x7
BYTE			OpEncB_DriveMode_2_ADDR;
#pragma	ioport	OpEncB_GlobalSelect_ADDR:	0x6
BYTE			OpEncB_GlobalSelect_ADDR;
#pragma	ioport	OpEncB_IntCtrl_0_ADDR:	0x106
BYTE			OpEncB_IntCtrl_0_ADDR;
#pragma	ioport	OpEncB_IntCtrl_1_ADDR:	0x107
BYTE			OpEncB_IntCtrl_1_ADDR;
#pragma	ioport	OpEncB_IntEn_ADDR:	0x5
BYTE			OpEncB_IntEn_ADDR;
#define OpEncB_MASK 0x80
// OpEncA address and mask defines
#pragma	ioport	OpEncA_Data_ADDR:	0x4
BYTE			OpEncA_Data_ADDR;
#pragma	ioport	OpEncA_DriveMode_0_ADDR:	0x104
BYTE			OpEncA_DriveMode_0_ADDR;
#pragma	ioport	OpEncA_DriveMode_1_ADDR:	0x105
BYTE			OpEncA_DriveMode_1_ADDR;
#pragma	ioport	OpEncA_DriveMode_2_ADDR:	0x7
BYTE			OpEncA_DriveMode_2_ADDR;
#pragma	ioport	OpEncA_GlobalSelect_ADDR:	0x6
BYTE			OpEncA_GlobalSelect_ADDR;
#pragma	ioport	OpEncA_IntCtrl_0_ADDR:	0x106
BYTE			OpEncA_IntCtrl_0_ADDR;
#pragma	ioport	OpEncA_IntCtrl_1_ADDR:	0x107
BYTE			OpEncA_IntCtrl_1_ADDR;
#pragma	ioport	OpEncA_IntEn_ADDR:	0x5
BYTE			OpEncA_IntEn_ADDR;
#define OpEncA_MASK 0x40
// Out address and mask defines
#pragma	ioport	Out_Data_ADDR:	0x0
BYTE			Out_Data_ADDR;
#pragma	ioport	Out_DriveMode_0_ADDR:	0x100
BYTE			Out_DriveMode_0_ADDR;
#pragma	ioport	Out_DriveMode_1_ADDR:	0x101
BYTE			Out_DriveMode_1_ADDR;
#pragma	ioport	Out_DriveMode_2_ADDR:	0x3
BYTE			Out_DriveMode_2_ADDR;
#pragma	ioport	Out_GlobalSelect_ADDR:	0x2
BYTE			Out_GlobalSelect_ADDR;
#pragma	ioport	Out_IntCtrl_0_ADDR:	0x102
BYTE			Out_IntCtrl_0_ADDR;
#pragma	ioport	Out_IntCtrl_1_ADDR:	0x103
BYTE			Out_IntCtrl_1_ADDR;
#pragma	ioport	Out_IntEn_ADDR:	0x1
BYTE			Out_IntEn_ADDR;
#define Out_MASK 0x1
// Clk address and mask defines
#pragma	ioport	Clk_Data_ADDR:	0x0
BYTE			Clk_Data_ADDR;
#pragma	ioport	Clk_DriveMode_0_ADDR:	0x100
BYTE			Clk_DriveMode_0_ADDR;
#pragma	ioport	Clk_DriveMode_1_ADDR:	0x101
BYTE			Clk_DriveMode_1_ADDR;
#pragma	ioport	Clk_DriveMode_2_ADDR:	0x3
BYTE			Clk_DriveMode_2_ADDR;
#pragma	ioport	Clk_GlobalSelect_ADDR:	0x2
BYTE			Clk_GlobalSelect_ADDR;
#pragma	ioport	Clk_IntCtrl_0_ADDR:	0x102
BYTE			Clk_IntCtrl_0_ADDR;
#pragma	ioport	Clk_IntCtrl_1_ADDR:	0x103
BYTE			Clk_IntCtrl_1_ADDR;
#pragma	ioport	Clk_IntEn_ADDR:	0x1
BYTE			Clk_IntEn_ADDR;
#define Clk_MASK 0x4
// SWFREQ address and mask defines
#pragma	ioport	SWFREQ_Data_ADDR:	0x4
BYTE			SWFREQ_Data_ADDR;
#pragma	ioport	SWFREQ_DriveMode_0_ADDR:	0x104
BYTE			SWFREQ_DriveMode_0_ADDR;
#pragma	ioport	SWFREQ_DriveMode_1_ADDR:	0x105
BYTE			SWFREQ_DriveMode_1_ADDR;
#pragma	ioport	SWFREQ_DriveMode_2_ADDR:	0x7
BYTE			SWFREQ_DriveMode_2_ADDR;
#pragma	ioport	SWFREQ_GlobalSelect_ADDR:	0x6
BYTE			SWFREQ_GlobalSelect_ADDR;
#pragma	ioport	SWFREQ_IntCtrl_0_ADDR:	0x106
BYTE			SWFREQ_IntCtrl_0_ADDR;
#pragma	ioport	SWFREQ_IntCtrl_1_ADDR:	0x107
BYTE			SWFREQ_IntCtrl_1_ADDR;
#pragma	ioport	SWFREQ_IntEn_ADDR:	0x5
BYTE			SWFREQ_IntEn_ADDR;
#define SWFREQ_MASK 0x10
// SWEN address and mask defines
#pragma	ioport	SWEN_Data_ADDR:	0x4
BYTE			SWEN_Data_ADDR;
#pragma	ioport	SWEN_DriveMode_0_ADDR:	0x104
BYTE			SWEN_DriveMode_0_ADDR;
#pragma	ioport	SWEN_DriveMode_1_ADDR:	0x105
BYTE			SWEN_DriveMode_1_ADDR;
#pragma	ioport	SWEN_DriveMode_2_ADDR:	0x7
BYTE			SWEN_DriveMode_2_ADDR;
#pragma	ioport	SWEN_GlobalSelect_ADDR:	0x6
BYTE			SWEN_GlobalSelect_ADDR;
#pragma	ioport	SWEN_IntCtrl_0_ADDR:	0x106
BYTE			SWEN_IntCtrl_0_ADDR;
#pragma	ioport	SWEN_IntCtrl_1_ADDR:	0x107
BYTE			SWEN_IntCtrl_1_ADDR;
#pragma	ioport	SWEN_IntEn_ADDR:	0x5
BYTE			SWEN_IntEn_ADDR;
#define SWEN_MASK 0x20
// LCDD4 address and mask defines
#pragma	ioport	LCDD4_Data_ADDR:	0x8
BYTE			LCDD4_Data_ADDR;
#pragma	ioport	LCDD4_DriveMode_0_ADDR:	0x108
BYTE			LCDD4_DriveMode_0_ADDR;
#pragma	ioport	LCDD4_DriveMode_1_ADDR:	0x109
BYTE			LCDD4_DriveMode_1_ADDR;
#pragma	ioport	LCDD4_DriveMode_2_ADDR:	0xb
BYTE			LCDD4_DriveMode_2_ADDR;
#pragma	ioport	LCDD4_GlobalSelect_ADDR:	0xa
BYTE			LCDD4_GlobalSelect_ADDR;
#pragma	ioport	LCDD4_IntCtrl_0_ADDR:	0x10a
BYTE			LCDD4_IntCtrl_0_ADDR;
#pragma	ioport	LCDD4_IntCtrl_1_ADDR:	0x10b
BYTE			LCDD4_IntCtrl_1_ADDR;
#pragma	ioport	LCDD4_IntEn_ADDR:	0x9
BYTE			LCDD4_IntEn_ADDR;
#define LCDD4_MASK 0x1
// LCDD4 Shadow defines
//   LCDD4_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCDD4_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCDD4_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCDD4_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCDD4_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCDD4_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCDD5 address and mask defines
#pragma	ioport	LCDD5_Data_ADDR:	0x8
BYTE			LCDD5_Data_ADDR;
#pragma	ioport	LCDD5_DriveMode_0_ADDR:	0x108
BYTE			LCDD5_DriveMode_0_ADDR;
#pragma	ioport	LCDD5_DriveMode_1_ADDR:	0x109
BYTE			LCDD5_DriveMode_1_ADDR;
#pragma	ioport	LCDD5_DriveMode_2_ADDR:	0xb
BYTE			LCDD5_DriveMode_2_ADDR;
#pragma	ioport	LCDD5_GlobalSelect_ADDR:	0xa
BYTE			LCDD5_GlobalSelect_ADDR;
#pragma	ioport	LCDD5_IntCtrl_0_ADDR:	0x10a
BYTE			LCDD5_IntCtrl_0_ADDR;
#pragma	ioport	LCDD5_IntCtrl_1_ADDR:	0x10b
BYTE			LCDD5_IntCtrl_1_ADDR;
#pragma	ioport	LCDD5_IntEn_ADDR:	0x9
BYTE			LCDD5_IntEn_ADDR;
#define LCDD5_MASK 0x2
// LCDD5 Shadow defines
//   LCDD5_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCDD5_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCDD5_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCDD5_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCDD5_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCDD5_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCDD6 address and mask defines
#pragma	ioport	LCDD6_Data_ADDR:	0x8
BYTE			LCDD6_Data_ADDR;
#pragma	ioport	LCDD6_DriveMode_0_ADDR:	0x108
BYTE			LCDD6_DriveMode_0_ADDR;
#pragma	ioport	LCDD6_DriveMode_1_ADDR:	0x109
BYTE			LCDD6_DriveMode_1_ADDR;
#pragma	ioport	LCDD6_DriveMode_2_ADDR:	0xb
BYTE			LCDD6_DriveMode_2_ADDR;
#pragma	ioport	LCDD6_GlobalSelect_ADDR:	0xa
BYTE			LCDD6_GlobalSelect_ADDR;
#pragma	ioport	LCDD6_IntCtrl_0_ADDR:	0x10a
BYTE			LCDD6_IntCtrl_0_ADDR;
#pragma	ioport	LCDD6_IntCtrl_1_ADDR:	0x10b
BYTE			LCDD6_IntCtrl_1_ADDR;
#pragma	ioport	LCDD6_IntEn_ADDR:	0x9
BYTE			LCDD6_IntEn_ADDR;
#define LCDD6_MASK 0x4
// LCDD6 Shadow defines
//   LCDD6_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCDD6_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCDD6_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCDD6_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCDD6_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCDD6_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCDD7 address and mask defines
#pragma	ioport	LCDD7_Data_ADDR:	0x8
BYTE			LCDD7_Data_ADDR;
#pragma	ioport	LCDD7_DriveMode_0_ADDR:	0x108
BYTE			LCDD7_DriveMode_0_ADDR;
#pragma	ioport	LCDD7_DriveMode_1_ADDR:	0x109
BYTE			LCDD7_DriveMode_1_ADDR;
#pragma	ioport	LCDD7_DriveMode_2_ADDR:	0xb
BYTE			LCDD7_DriveMode_2_ADDR;
#pragma	ioport	LCDD7_GlobalSelect_ADDR:	0xa
BYTE			LCDD7_GlobalSelect_ADDR;
#pragma	ioport	LCDD7_IntCtrl_0_ADDR:	0x10a
BYTE			LCDD7_IntCtrl_0_ADDR;
#pragma	ioport	LCDD7_IntCtrl_1_ADDR:	0x10b
BYTE			LCDD7_IntCtrl_1_ADDR;
#pragma	ioport	LCDD7_IntEn_ADDR:	0x9
BYTE			LCDD7_IntEn_ADDR;
#define LCDD7_MASK 0x8
// LCDD7 Shadow defines
//   LCDD7_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCDD7_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCDD7_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCDD7_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCDD7_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCDD7_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCDE address and mask defines
#pragma	ioport	LCDE_Data_ADDR:	0x8
BYTE			LCDE_Data_ADDR;
#pragma	ioport	LCDE_DriveMode_0_ADDR:	0x108
BYTE			LCDE_DriveMode_0_ADDR;
#pragma	ioport	LCDE_DriveMode_1_ADDR:	0x109
BYTE			LCDE_DriveMode_1_ADDR;
#pragma	ioport	LCDE_DriveMode_2_ADDR:	0xb
BYTE			LCDE_DriveMode_2_ADDR;
#pragma	ioport	LCDE_GlobalSelect_ADDR:	0xa
BYTE			LCDE_GlobalSelect_ADDR;
#pragma	ioport	LCDE_IntCtrl_0_ADDR:	0x10a
BYTE			LCDE_IntCtrl_0_ADDR;
#pragma	ioport	LCDE_IntCtrl_1_ADDR:	0x10b
BYTE			LCDE_IntCtrl_1_ADDR;
#pragma	ioport	LCDE_IntEn_ADDR:	0x9
BYTE			LCDE_IntEn_ADDR;
#define LCDE_MASK 0x10
// LCDE Shadow defines
//   LCDE_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCDE_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCDE_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCDE_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCDE_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCDE_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCDRS address and mask defines
#pragma	ioport	LCDRS_Data_ADDR:	0x8
BYTE			LCDRS_Data_ADDR;
#pragma	ioport	LCDRS_DriveMode_0_ADDR:	0x108
BYTE			LCDRS_DriveMode_0_ADDR;
#pragma	ioport	LCDRS_DriveMode_1_ADDR:	0x109
BYTE			LCDRS_DriveMode_1_ADDR;
#pragma	ioport	LCDRS_DriveMode_2_ADDR:	0xb
BYTE			LCDRS_DriveMode_2_ADDR;
#pragma	ioport	LCDRS_GlobalSelect_ADDR:	0xa
BYTE			LCDRS_GlobalSelect_ADDR;
#pragma	ioport	LCDRS_IntCtrl_0_ADDR:	0x10a
BYTE			LCDRS_IntCtrl_0_ADDR;
#pragma	ioport	LCDRS_IntCtrl_1_ADDR:	0x10b
BYTE			LCDRS_IntCtrl_1_ADDR;
#pragma	ioport	LCDRS_IntEn_ADDR:	0x9
BYTE			LCDRS_IntEn_ADDR;
#define LCDRS_MASK 0x20
// LCDRS Shadow defines
//   LCDRS_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCDRS_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCDRS_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCDRS_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCDRS_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCDRS_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
// LCDRW address and mask defines
#pragma	ioport	LCDRW_Data_ADDR:	0x8
BYTE			LCDRW_Data_ADDR;
#pragma	ioport	LCDRW_DriveMode_0_ADDR:	0x108
BYTE			LCDRW_DriveMode_0_ADDR;
#pragma	ioport	LCDRW_DriveMode_1_ADDR:	0x109
BYTE			LCDRW_DriveMode_1_ADDR;
#pragma	ioport	LCDRW_DriveMode_2_ADDR:	0xb
BYTE			LCDRW_DriveMode_2_ADDR;
#pragma	ioport	LCDRW_GlobalSelect_ADDR:	0xa
BYTE			LCDRW_GlobalSelect_ADDR;
#pragma	ioport	LCDRW_IntCtrl_0_ADDR:	0x10a
BYTE			LCDRW_IntCtrl_0_ADDR;
#pragma	ioport	LCDRW_IntCtrl_1_ADDR:	0x10b
BYTE			LCDRW_IntCtrl_1_ADDR;
#pragma	ioport	LCDRW_IntEn_ADDR:	0x9
BYTE			LCDRW_IntEn_ADDR;
#define LCDRW_MASK 0x40
// LCDRW Shadow defines
//   LCDRW_DataShadow define
extern BYTE Port_2_Data_SHADE;
#define LCDRW_DataShadow (*(unsigned char*)&Port_2_Data_SHADE)
//   LCDRW_DriveMode_0Shadow define
extern BYTE Port_2_DriveMode_0_SHADE;
#define LCDRW_DriveMode_0Shadow (*(unsigned char*)&Port_2_DriveMode_0_SHADE)
//   LCDRW_DriveMode_1Shadow define
extern BYTE Port_2_DriveMode_1_SHADE;
#define LCDRW_DriveMode_1Shadow (*(unsigned char*)&Port_2_DriveMode_1_SHADE)
