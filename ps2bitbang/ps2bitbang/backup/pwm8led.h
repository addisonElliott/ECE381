//*****************************************************************************
//*****************************************************************************
//  FILENAME: PWM8LED.h
//   Version: 2.60, Updated on 2015/3/4 at 22:26:52
//  Generated by PSoC Designer 5.4.3191
//
//  DESCRIPTION: PWM8 User Module C Language interface file
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef PWM8LED_INCLUDE
#define PWM8LED_INCLUDE

#include <m8c.h>

#pragma fastcall16 PWM8LED_EnableInt
#pragma fastcall16 PWM8LED_DisableInt
#pragma fastcall16 PWM8LED_Start
#pragma fastcall16 PWM8LED_Stop
#pragma fastcall16 PWM8LED_bReadCounter              // Read  DR0
#pragma fastcall16 PWM8LED_WritePeriod               // Write DR1
#pragma fastcall16 PWM8LED_bReadPulseWidth           // Read  DR2
#pragma fastcall16 PWM8LED_WritePulseWidth           // Write DR2

// The following symbols are deprecated.
// They may be omitted in future releases
//
#pragma fastcall16 bPWM8LED_ReadCounter              // Read  DR0 (Deprecated)
#pragma fastcall16 bPWM8LED_ReadPulseWidth           // Read  DR2 (Deprecated)


//-------------------------------------------------
// Prototypes of the PWM8LED API.
//-------------------------------------------------

extern void PWM8LED_EnableInt(void);                        // Proxy Class 1
extern void PWM8LED_DisableInt(void);                       // Proxy Class 1
extern void PWM8LED_Start(void);                            // Proxy Class 1
extern void PWM8LED_Stop(void);                             // Proxy Class 1
extern BYTE PWM8LED_bReadCounter(void);                     // Proxy Class 2
extern void PWM8LED_WritePeriod(BYTE bPeriod);              // Proxy Class 1
extern BYTE PWM8LED_bReadPulseWidth(void);                  // Proxy Class 1
extern void PWM8LED_WritePulseWidth(BYTE bPulseWidth);      // Proxy Class 1

// The following functions are deprecated.
// They may be omitted in future releases
//
extern BYTE bPWM8LED_ReadCounter(void);            // Deprecated
extern BYTE bPWM8LED_ReadPulseWidth(void);         // Deprecated


//--------------------------------------------------
// Constants for PWM8LED API's.
//--------------------------------------------------

#define PWM8LED_CONTROL_REG_START_BIT          ( 0x01 )
#define PWM8LED_INT_REG_ADDR                   ( 0x0df )
#define PWM8LED_INT_MASK                       ( 0x01 )


//--------------------------------------------------
// Constants for PWM8LED user defined values
//--------------------------------------------------

#define PWM8LED_PERIOD                         ( 0xff )
#define PWM8LED_PULSE_WIDTH                    ( 0x7f )


//-------------------------------------------------
// Register Addresses for PWM8LED
//-------------------------------------------------

#pragma ioport  PWM8LED_COUNTER_REG:    0x040              //DR0 Count register
BYTE            PWM8LED_COUNTER_REG;
#pragma ioport  PWM8LED_PERIOD_REG: 0x041                  //DR1 Period register
BYTE            PWM8LED_PERIOD_REG;
#pragma ioport  PWM8LED_COMPARE_REG:    0x042              //DR2 Compare register
BYTE            PWM8LED_COMPARE_REG;
#pragma ioport  PWM8LED_CONTROL_REG:    0x043              //Control register
BYTE            PWM8LED_CONTROL_REG;
#pragma ioport  PWM8LED_FUNC_REG:   0x140                  //Function register
BYTE            PWM8LED_FUNC_REG;
#pragma ioport  PWM8LED_INPUT_REG:  0x141                  //Input register
BYTE            PWM8LED_INPUT_REG;
#pragma ioport  PWM8LED_OUTPUT_REG: 0x142                  //Output register
BYTE            PWM8LED_OUTPUT_REG;
#pragma ioport  PWM8LED_INT_REG:       0x0df               //Interrupt Mask Register
BYTE            PWM8LED_INT_REG;


//-------------------------------------------------
// PWM8LED Macro 'Functions'
//-------------------------------------------------

#define PWM8LED_Start_M \
   PWM8LED_CONTROL_REG |=  PWM8LED_CONTROL_REG_START_BIT

#define PWM8LED_Stop_M  \
   PWM8LED_CONTROL_REG &= ~PWM8LED_CONTROL_REG_START_BIT

#define PWM8LED_EnableInt_M   \
   M8C_EnableIntMask(PWM8LED_INT_REG, PWM8LED_INT_MASK)

#define PWM8LED_DisableInt_M  \
   M8C_DisableIntMask(PWM8LED_INT_REG, PWM8LED_INT_MASK)

#endif
// end of file PWM8LED.h
