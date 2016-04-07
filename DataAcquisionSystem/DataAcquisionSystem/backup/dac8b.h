//*****************************************************************************
//*****************************************************************************
//  FILENAME: DAC8B.h
//   Version: 2.2, Updated on 2015/3/4 at 22:25:12
//  Generated by PSoC Designer 5.4.3191
//
//  DESCRIPTION:  DAC8 User Module C language interface file.
//-----------------------------------------------------------------------------
//      Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef DAC8B_INCLUDE
#define DAC8B_INCLUDE

#include <m8c.h>

//-------------------------------------------------
// Defines for DAC8B API's.
//-------------------------------------------------
// Power Setting Defines
#define DAC8B_OFF                 0
#define DAC8B_LOWPOWER            1
#define DAC8B_MEDPOWER            2
#define DAC8B_HIGHPOWER           3
#define DAC8B_FULLPOWER           3

// Define constants for declaring function prototypes based on DataFormat parameter
#define DAC8B_OffsetBinary            0x04
#define DAC8B_TwosComplement          0x02
#define DAC8B_SignAndMagnitude        0x01
#define DAC8B_RawRegister             0x00
#define DAC8B_DATAFORMAT          0x3
#define DAC8B_OFFSETBINARY        DAC8B_DATAFORMAT & DAC8B_OffsetBinary
#define DAC8B_TWOSCOMPLEMENT      DAC8B_DATAFORMAT & DAC8B_TwosComplement
#define DAC8B_SIGNANDMAGNITUDE    DAC8B_DATAFORMAT & DAC8B_SignAndMagnitude

// Declare function fastcall16 pragmas
#pragma fastcall16 DAC8B_Start
#pragma fastcall16 DAC8B_SetPower
#pragma fastcall16 DAC8B_Stop

//-------------------------------------------------
// Prototypes of the DAC8B API.
//-------------------------------------------------
extern void  DAC8B_Start(BYTE bPowerSetting);
extern void  DAC8B_SetPower(BYTE bPowerSetting);
extern void  DAC8B_Stop(void);

// Declare overloaded functions based on DataForamt parameter selected
#if DAC8B_OFFSETBINARY
   #pragma fastcall16 DAC8B_WriteBlind
   #pragma fastcall16 DAC8B_WriteStall
   extern void  DAC8B_WriteBlind(BYTE bOutputValue);
   extern void  DAC8B_WriteStall(BYTE bOutputValue);
#else
   #if DAC8B_TWOSCOMPLEMENT
      #pragma fastcall16 DAC8B_WriteBlind
      #pragma fastcall16 DAC8B_WriteStall
      extern void  DAC8B_WriteBlind(CHAR cOutputValue);
      extern void  DAC8B_WriteStall(CHAR cOutputValue);
   #else    //DAC8B_SIGNANDMAGNITUDE
      #pragma fastcall16 DAC8B_WriteBlind2B
      #pragma fastcall16 DAC8B_WriteStall2B
      extern void  DAC8B_WriteBlind2B(BYTE bLSB, BYTE bMSB);
      extern void  DAC8B_WriteStall2B(BYTE bLSB, BYTE bMSB);
   #endif
#endif

//-------------------------------------------------
// Hardware Register Definitions
//-------------------------------------------------

#pragma ioport  DAC8B_LSB_CR0:  0x098                      // LSB Analog control register 0
BYTE            DAC8B_LSB_CR0;
#pragma ioport  DAC8B_LSB_CR1:  0x099                      // LSB Analog control register 1
BYTE            DAC8B_LSB_CR1;
#pragma ioport  DAC8B_LSB_CR2:  0x09a                      // LSB Analog control register 2
BYTE            DAC8B_LSB_CR2;
#pragma ioport  DAC8B_LSB_CR3:  0x09b                      // LSB Analog control register 3
BYTE            DAC8B_LSB_CR3;

#pragma ioport  DAC8B_MSB_CR0:  0x088                      // MSB Analog control register 0
BYTE            DAC8B_MSB_CR0;
#pragma ioport  DAC8B_MSB_CR1:  0x089                      // MSB Analog control register 1
BYTE            DAC8B_MSB_CR1;
#pragma ioport  DAC8B_MSB_CR2:  0x08a                      // MSB Analog control register 2
BYTE            DAC8B_MSB_CR2;
#pragma ioport  DAC8B_MSB_CR3:  0x08b                      // MSB Analog control register 3
BYTE            DAC8B_MSB_CR3;

#endif
// end of file DAC8B.h
