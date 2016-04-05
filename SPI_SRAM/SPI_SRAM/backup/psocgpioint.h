/******************************************************************************
*  Generated by PSoC Designer 5.4.3191
******************************************************************************/
#include <m8c.h>
// nCS address and mask defines
#pragma	ioport	nCS_Data_ADDR:	0x4
BYTE			nCS_Data_ADDR;
#pragma	ioport	nCS_DriveMode_0_ADDR:	0x104
BYTE			nCS_DriveMode_0_ADDR;
#pragma	ioport	nCS_DriveMode_1_ADDR:	0x105
BYTE			nCS_DriveMode_1_ADDR;
#pragma	ioport	nCS_DriveMode_2_ADDR:	0x7
BYTE			nCS_DriveMode_2_ADDR;
#pragma	ioport	nCS_GlobalSelect_ADDR:	0x6
BYTE			nCS_GlobalSelect_ADDR;
#pragma	ioport	nCS_IntCtrl_0_ADDR:	0x106
BYTE			nCS_IntCtrl_0_ADDR;
#pragma	ioport	nCS_IntCtrl_1_ADDR:	0x107
BYTE			nCS_IntCtrl_1_ADDR;
#pragma	ioport	nCS_IntEn_ADDR:	0x5
BYTE			nCS_IntEn_ADDR;
#define nCS_MASK 0x4
// SCLK address and mask defines
#pragma	ioport	SCLK_Data_ADDR:	0x4
BYTE			SCLK_Data_ADDR;
#pragma	ioport	SCLK_DriveMode_0_ADDR:	0x104
BYTE			SCLK_DriveMode_0_ADDR;
#pragma	ioport	SCLK_DriveMode_1_ADDR:	0x105
BYTE			SCLK_DriveMode_1_ADDR;
#pragma	ioport	SCLK_DriveMode_2_ADDR:	0x7
BYTE			SCLK_DriveMode_2_ADDR;
#pragma	ioport	SCLK_GlobalSelect_ADDR:	0x6
BYTE			SCLK_GlobalSelect_ADDR;
#pragma	ioport	SCLK_IntCtrl_0_ADDR:	0x106
BYTE			SCLK_IntCtrl_0_ADDR;
#pragma	ioport	SCLK_IntCtrl_1_ADDR:	0x107
BYTE			SCLK_IntCtrl_1_ADDR;
#pragma	ioport	SCLK_IntEn_ADDR:	0x5
BYTE			SCLK_IntEn_ADDR;
#define SCLK_MASK 0x8
// MOSI address and mask defines
#pragma	ioport	MOSI_Data_ADDR:	0x4
BYTE			MOSI_Data_ADDR;
#pragma	ioport	MOSI_DriveMode_0_ADDR:	0x104
BYTE			MOSI_DriveMode_0_ADDR;
#pragma	ioport	MOSI_DriveMode_1_ADDR:	0x105
BYTE			MOSI_DriveMode_1_ADDR;
#pragma	ioport	MOSI_DriveMode_2_ADDR:	0x7
BYTE			MOSI_DriveMode_2_ADDR;
#pragma	ioport	MOSI_GlobalSelect_ADDR:	0x6
BYTE			MOSI_GlobalSelect_ADDR;
#pragma	ioport	MOSI_IntCtrl_0_ADDR:	0x106
BYTE			MOSI_IntCtrl_0_ADDR;
#pragma	ioport	MOSI_IntCtrl_1_ADDR:	0x107
BYTE			MOSI_IntCtrl_1_ADDR;
#pragma	ioport	MOSI_IntEn_ADDR:	0x5
BYTE			MOSI_IntEn_ADDR;
#define MOSI_MASK 0x10
// MISO address and mask defines
#pragma	ioport	MISO_Data_ADDR:	0x4
BYTE			MISO_Data_ADDR;
#pragma	ioport	MISO_DriveMode_0_ADDR:	0x104
BYTE			MISO_DriveMode_0_ADDR;
#pragma	ioport	MISO_DriveMode_1_ADDR:	0x105
BYTE			MISO_DriveMode_1_ADDR;
#pragma	ioport	MISO_DriveMode_2_ADDR:	0x7
BYTE			MISO_DriveMode_2_ADDR;
#pragma	ioport	MISO_GlobalSelect_ADDR:	0x6
BYTE			MISO_GlobalSelect_ADDR;
#pragma	ioport	MISO_IntCtrl_0_ADDR:	0x106
BYTE			MISO_IntCtrl_0_ADDR;
#pragma	ioport	MISO_IntCtrl_1_ADDR:	0x107
BYTE			MISO_IntCtrl_1_ADDR;
#pragma	ioport	MISO_IntEn_ADDR:	0x5
BYTE			MISO_IntEn_ADDR;
#define MISO_MASK 0x20
// RX_IN address and mask defines
#pragma	ioport	RX_IN_Data_ADDR:	0x4
BYTE			RX_IN_Data_ADDR;
#pragma	ioport	RX_IN_DriveMode_0_ADDR:	0x104
BYTE			RX_IN_DriveMode_0_ADDR;
#pragma	ioport	RX_IN_DriveMode_1_ADDR:	0x105
BYTE			RX_IN_DriveMode_1_ADDR;
#pragma	ioport	RX_IN_DriveMode_2_ADDR:	0x7
BYTE			RX_IN_DriveMode_2_ADDR;
#pragma	ioport	RX_IN_GlobalSelect_ADDR:	0x6
BYTE			RX_IN_GlobalSelect_ADDR;
#pragma	ioport	RX_IN_IntCtrl_0_ADDR:	0x106
BYTE			RX_IN_IntCtrl_0_ADDR;
#pragma	ioport	RX_IN_IntCtrl_1_ADDR:	0x107
BYTE			RX_IN_IntCtrl_1_ADDR;
#pragma	ioport	RX_IN_IntEn_ADDR:	0x5
BYTE			RX_IN_IntEn_ADDR;
#define RX_IN_MASK 0x40
// TX_OUT address and mask defines
#pragma	ioport	TX_OUT_Data_ADDR:	0x8
BYTE			TX_OUT_Data_ADDR;
#pragma	ioport	TX_OUT_DriveMode_0_ADDR:	0x108
BYTE			TX_OUT_DriveMode_0_ADDR;
#pragma	ioport	TX_OUT_DriveMode_1_ADDR:	0x109
BYTE			TX_OUT_DriveMode_1_ADDR;
#pragma	ioport	TX_OUT_DriveMode_2_ADDR:	0xb
BYTE			TX_OUT_DriveMode_2_ADDR;
#pragma	ioport	TX_OUT_GlobalSelect_ADDR:	0xa
BYTE			TX_OUT_GlobalSelect_ADDR;
#pragma	ioport	TX_OUT_IntCtrl_0_ADDR:	0x10a
BYTE			TX_OUT_IntCtrl_0_ADDR;
#pragma	ioport	TX_OUT_IntCtrl_1_ADDR:	0x10b
BYTE			TX_OUT_IntCtrl_1_ADDR;
#pragma	ioport	TX_OUT_IntEn_ADDR:	0x9
BYTE			TX_OUT_IntEn_ADDR;
#define TX_OUT_MASK 0x80
