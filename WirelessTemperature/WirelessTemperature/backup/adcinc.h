//*****************************************************************************
//*****************************************************************************
//  FILENAME: ADCINC.h
//  Version: 1.20, Updated on 2015/3/4 at 22:21:26
//	Generated by PSoC Designer 5.4.3191
//
//  DESCRIPTION:  C declarations for theADCINCPWM User Module with
//                a 1st-order modulator.
//-----------------------------------------------------------------------------
//      Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef ADCINC_INCLUDE
#define ADCINC_INCLUDE

#include <m8c.h>

#pragma fastcall16 ADCINC_Start
#pragma fastcall16 ADCINC_SetPower
#pragma fastcall16 ADCINC_Stop
#pragma fastcall16 ADCINC_GetSamples
#pragma fastcall16 ADCINC_StopADC
#pragma fastcall16 ADCINC_fIsDataAvailable
#pragma fastcall16 ADCINC_iClearFlagGetData
#pragma fastcall16 ADCINC_wClearFlagGetData
#pragma fastcall16 ADCINC_cClearFlagGetData
#pragma fastcall16 ADCINC_bClearFlagGetData
#pragma fastcall16 ADCINC_iGetData
#pragma fastcall16 ADCINC_wGetData
#pragma fastcall16 ADCINC_cGetData
#pragma fastcall16 ADCINC_bGetData
#pragma fastcall16 ADCINC_fClearFlag
#pragma fastcall16 ADCINC_WritePulseWidth

//-------------------------------------------------
// Prototypes of the ADCINC API.
//-------------------------------------------------
extern void  ADCINC_Start(BYTE bPower);
extern void  ADCINC_SetPower(BYTE bPower);
extern void  ADCINC_Stop(void);
extern void  ADCINC_GetSamples(BYTE bNumSamples);
extern void  ADCINC_StopADC(void);
extern BYTE  ADCINC_fIsDataAvailable(void);
extern INT   ADCINC_iClearFlagGetData(void);
extern WORD  ADCINC_wClearFlagGetData(void);
extern CHAR  ADCINC_cClearFlagGetData(void);
extern BYTE  ADCINC_bClearFlagGetData(void);
extern INT   ADCINC_iGetData(void);
extern WORD  ADCINC_wGetData(void);
extern CHAR  ADCINC_cGetData(void);
extern BYTE  ADCINC_bGetData(void);
extern BYTE  ADCINC_fClearFlag(void);
extern void  ADCINC_WritePulseWidth(BYTE bPulseWidthValue);


//-------------------------------------------------
// Defines for ADCINC API's.
//-------------------------------------------------
#define ADCINC_OFF         0
#define ADCINC_LOWPOWER    1
#define ADCINC_MEDPOWER    2
#define ADCINC_HIGHPOWER   3


//-------------------------------------------------
// Hardware Register Definitions
//-------------------------------------------------
#pragma ioport  ADCINC_PWMdr0:  0x020                 //Period reg
BYTE            ADCINC_PWMdr0;
#pragma ioport  ADCINC_PWMdr1:  0x021                 //1_ADDRh   ; Down count reg
BYTE            ADCINC_PWMdr1;               
#pragma ioport  ADCINC_PWMdr2:  0x022                 //Compare reg
BYTE            ADCINC_PWMdr2;
#pragma ioport  ADCINC_PWMcr0:  0x023                 //Control reg
BYTE            ADCINC_PWMcr0;
#pragma ioport  ADCINC_PWMfn:   0x120                  //Function reg
BYTE            ADCINC_PWMfn;
#pragma ioport  ADCINC_PWMsl:   0x121                  //Input select reg
BYTE            ADCINC_PWMsl;
#pragma ioport  ADCINC_PWMos:   0x122                  //Output select reg
BYTE            ADCINC_PWMos;
#pragma ioport  ADCINC_AtoD1cr0:    0x080              //Analog block 1 control register 0
BYTE            ADCINC_AtoD1cr0;
#pragma ioport  ADCINC_AtoD1cr1:    0x081              //Analog block 1 control register 1
BYTE            ADCINC_AtoD1cr1;
#pragma ioport  ADCINC_AtoD1cr2:    0x082              //Analog block 1 control register 2
BYTE            ADCINC_AtoD1cr2;
#pragma ioport  ADCINC_AtoD1cr3:    0x083              //Analog block 1 control register 3
BYTE            ADCINC_AtoD1cr3;
#pragma ioport  ADCINC_AtoD2cr0:    0x090              //Analog block 2 control register 0
BYTE            ADCINC_AtoD2cr0;
#pragma ioport  ADCINC_AtoD2cr1:    0x091              //Analog block 2 control register 1
BYTE            ADCINC_AtoD2cr1;
#pragma ioport  ADCINC_AtoD2cr2:    0x092              //Analog block 2 control register 2
BYTE            ADCINC_AtoD2cr2;
#pragma ioport  ADCINC_AtoD2cr3:    0x093              //Analog block 2 control register 3
BYTE            ADCINC_AtoD2cr3;

#endif
// end of file ADCINC.h
