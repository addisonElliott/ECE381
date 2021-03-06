//*****************************************************************************
//*****************************************************************************
//  FILENAME: Counter16.h
//   Version: 2.5, Updated on 2015/3/4 at 22:23:43
//  Generated by PSoC Designer 5.4.3191
//
//  DESCRIPTION: Counter16 User Module C Language interface file
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef Counter16_INCLUDE
#define Counter16_INCLUDE

#include <m8c.h>

#pragma fastcall16 Counter16_EnableInt
#pragma fastcall16 Counter16_DisableInt
#pragma fastcall16 Counter16_Start
#pragma fastcall16 Counter16_Stop
#pragma fastcall16 Counter16_wReadCounter              // Read  DR0
#pragma fastcall16 Counter16_WritePeriod               // Write DR1
#pragma fastcall16 Counter16_wReadCompareValue         // Read  DR2
#pragma fastcall16 Counter16_WriteCompareValue         // Write DR2

// The following symbols are deprecated.
// They may be omitted in future releases
//
#pragma fastcall16 wCounter16_ReadCounter              // Read  DR0 (Deprecated)
#pragma fastcall16 wCounter16_ReadCompareValue         // Read  DR2 (Deprecated)

//-------------------------------------------------
// Prototypes of the Counter16 API.
//-------------------------------------------------
extern void Counter16_EnableInt(void);                           // Proxy Class 1
extern void Counter16_DisableInt(void);                          // Proxy Class 1
extern void Counter16_Start(void);                               // Proxy Class 1
extern void Counter16_Stop(void);                                // Proxy Class 1
extern WORD Counter16_wReadCounter(void);                        // Proxy Class 2
extern void Counter16_WritePeriod(WORD wPeriod);                 // Proxy Class 1
extern WORD Counter16_wReadCompareValue(void);                   // Proxy Class 1
extern void Counter16_WriteCompareValue(WORD wCompareValue);     // Proxy Class 1

// The following functions are deprecated.
// They may be omitted in future releases
//
extern WORD wCounter16_ReadCounter(void);            // Deprecated
extern WORD wCounter16_ReadCompareValue(void);       // Deprecated


//--------------------------------------------------
// Constants for Counter16 API's.
//--------------------------------------------------

#define Counter16_CONTROL_REG_START_BIT        ( 0x01 )
#define Counter16_INT_REG_ADDR                 ( 0x0e1 )
#define Counter16_INT_MASK                     ( 0x02 )


//--------------------------------------------------
// Constants for Counter16 user defined values
//--------------------------------------------------

#define Counter16_PERIOD                       ( 0x9e )
#define Counter16_COMPARE_VALUE                ( 0x4f )


//-------------------------------------------------
// Register Addresses for Counter16
//-------------------------------------------------

#pragma ioport  Counter16_COUNTER_LSB_REG:  0x020          //DR0 Counter register LSB
BYTE            Counter16_COUNTER_LSB_REG;
#pragma ioport  Counter16_COUNTER_MSB_REG:  0x024          //DR0 Counter register MSB
BYTE            Counter16_COUNTER_MSB_REG;
#pragma ioport  Counter16_PERIOD_LSB_REG:   0x021          //DR1 Period register LSB
BYTE            Counter16_PERIOD_LSB_REG;
#pragma ioport  Counter16_PERIOD_MSB_REG:   0x025          //DR1 Period register MSB
BYTE            Counter16_PERIOD_MSB_REG;
#pragma ioport  Counter16_COMPARE_LSB_REG:  0x022          //DR2 Compare register LSB
BYTE            Counter16_COMPARE_LSB_REG;
#pragma ioport  Counter16_COMPARE_MSB_REG:  0x026          //DR2 Compare register MSB
BYTE            Counter16_COMPARE_MSB_REG;
#pragma ioport  Counter16_CONTROL_LSB_REG:  0x023          //Control register LSB
BYTE            Counter16_CONTROL_LSB_REG;
#pragma ioport  Counter16_CONTROL_MSB_REG:  0x027          //Control register MSB
BYTE            Counter16_CONTROL_MSB_REG;
#pragma ioport  Counter16_FUNC_LSB_REG: 0x120              //Function register LSB
BYTE            Counter16_FUNC_LSB_REG;
#pragma ioport  Counter16_FUNC_MSB_REG: 0x124              //Function register MSB
BYTE            Counter16_FUNC_MSB_REG;
#pragma ioport  Counter16_INPUT_LSB_REG:    0x121          //Input register LSB
BYTE            Counter16_INPUT_LSB_REG;
#pragma ioport  Counter16_INPUT_MSB_REG:    0x125          //Input register MSB
BYTE            Counter16_INPUT_MSB_REG;
#pragma ioport  Counter16_OUTPUT_LSB_REG:   0x122          //Output register LSB
BYTE            Counter16_OUTPUT_LSB_REG;
#pragma ioport  Counter16_OUTPUT_MSB_REG:   0x126          //Output register MSB
BYTE            Counter16_OUTPUT_MSB_REG;
#pragma ioport  Counter16_INT_REG:       0x0e1             //Interrupt Mask Register
BYTE            Counter16_INT_REG;


//-------------------------------------------------
// Counter16 Macro 'Functions'
//-------------------------------------------------

#define Counter16_Start_M \
   ( Counter16_CONTROL_LSB_REG |=  Counter16_CONTROL_REG_START_BIT )

#define Counter16_Stop_M  \
   ( Counter16_CONTROL_LSB_REG &= ~Counter16_CONTROL_REG_START_BIT )

#define Counter16_EnableInt_M   \
   M8C_EnableIntMask(  Counter16_INT_REG, Counter16_INT_MASK )

#define Counter16_DisableInt_M  \
   M8C_DisableIntMask( Counter16_INT_REG, Counter16_INT_MASK )

#endif
// end of file Counter16.h
