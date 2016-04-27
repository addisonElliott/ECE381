//*****************************************************************************
//*****************************************************************************
//  FILENAME: DACUpdate.h
//   Version: 2.60, Updated on 2015/3/4 at 22:23:47
//  Generated by PSoC Designer 5.4.3191
//
//  DESCRIPTION: Counter8 User Module C Language interface file
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef DACUpdate_INCLUDE
#define DACUpdate_INCLUDE

#include <m8c.h>

#pragma fastcall16 DACUpdate_EnableInt
#pragma fastcall16 DACUpdate_DisableInt
#pragma fastcall16 DACUpdate_Start
#pragma fastcall16 DACUpdate_Stop
#pragma fastcall16 DACUpdate_bReadCounter              // Read  DR0
#pragma fastcall16 DACUpdate_WritePeriod               // Write DR1
#pragma fastcall16 DACUpdate_bReadCompareValue         // Read  DR2
#pragma fastcall16 DACUpdate_WriteCompareValue         // Write DR2

// The following symbols are deprecated.
// They may be omitted in future releases
//
#pragma fastcall16 bDACUpdate_ReadCounter              // Read  DR0 (Deprecated)
#pragma fastcall16 bDACUpdate_ReadCompareValue         // Read  DR2 (Deprecated)


//-------------------------------------------------
// Prototypes of the DACUpdate API.
//-------------------------------------------------

extern void DACUpdate_EnableInt(void);                           // Proxy Class 1
extern void DACUpdate_DisableInt(void);                          // Proxy Class 1
extern void DACUpdate_Start(void);                               // Proxy Class 1
extern void DACUpdate_Stop(void);                                // Proxy Class 1
extern BYTE DACUpdate_bReadCounter(void);                        // Proxy Class 1
extern void DACUpdate_WritePeriod(BYTE bPeriod);                 // Proxy Class 1
extern BYTE DACUpdate_bReadCompareValue(void);                   // Proxy Class 2
extern void DACUpdate_WriteCompareValue(BYTE bCompareValue);     // Proxy Class 1

// The following functions are deprecated.
// They may be omitted in future releases
//
extern BYTE bDACUpdate_ReadCounter(void);            // Deprecated
extern BYTE bDACUpdate_ReadCompareValue(void);       // Deprecated


//--------------------------------------------------
// Constants for DACUpdate API's.
//--------------------------------------------------

#define DACUpdate_CONTROL_REG_START_BIT        ( 0x01 )
#define DACUpdate_INT_REG_ADDR                 ( 0x0e1 )
#define DACUpdate_INT_MASK                     ( 0x02 )


//--------------------------------------------------
// Constants for DACUpdate user defined values
//--------------------------------------------------

#define DACUpdate_PERIOD                       ( 0x7f )
#define DACUpdate_COMPARE_VALUE                ( 0x04 )


//-------------------------------------------------
// Register Addresses for DACUpdate
//-------------------------------------------------

#pragma ioport  DACUpdate_COUNTER_REG:  0x024              //DR0 Count register
BYTE            DACUpdate_COUNTER_REG;
#pragma ioport  DACUpdate_PERIOD_REG:   0x025              //DR1 Period register
BYTE            DACUpdate_PERIOD_REG;
#pragma ioport  DACUpdate_COMPARE_REG:  0x026              //DR2 Compare register
BYTE            DACUpdate_COMPARE_REG;
#pragma ioport  DACUpdate_CONTROL_REG:  0x027              //Control register
BYTE            DACUpdate_CONTROL_REG;
#pragma ioport  DACUpdate_FUNC_REG: 0x124                  //Function register
BYTE            DACUpdate_FUNC_REG;
#pragma ioport  DACUpdate_INPUT_REG:    0x125              //Input register
BYTE            DACUpdate_INPUT_REG;
#pragma ioport  DACUpdate_OUTPUT_REG:   0x126              //Output register
BYTE            DACUpdate_OUTPUT_REG;
#pragma ioport  DACUpdate_INT_REG:       0x0e1             //Interrupt Mask Register
BYTE            DACUpdate_INT_REG;


//-------------------------------------------------
// DACUpdate Macro 'Functions'
//-------------------------------------------------

#define DACUpdate_Start_M \
   DACUpdate_CONTROL_REG |=  DACUpdate_CONTROL_REG_START_BIT

#define DACUpdate_Stop_M  \
   DACUpdate_CONTROL_REG &= ~DACUpdate_CONTROL_REG_START_BIT

#define DACUpdate_EnableInt_M   \
   M8C_EnableIntMask(DACUpdate_INT_REG, DACUpdate_INT_MASK)

#define DACUpdate_DisableInt_M  \
   M8C_DisableIntMask(DACUpdate_INT_REG, DACUpdate_INT_MASK)

#endif
// end of file DACUpdate.h