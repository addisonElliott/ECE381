/*******************************************************************************
* File Name: clock10us.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_clock10us_H)
#define CY_CLOCK_clock10us_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void clock10us_Start(void) ;
void clock10us_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void clock10us_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void clock10us_StandbyPower(uint8 state) ;
void clock10us_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 clock10us_GetDividerRegister(void) ;
void clock10us_SetModeRegister(uint8 modeBitMask) ;
void clock10us_ClearModeRegister(uint8 modeBitMask) ;
uint8 clock10us_GetModeRegister(void) ;
void clock10us_SetSourceRegister(uint8 clkSource) ;
uint8 clock10us_GetSourceRegister(void) ;
#if defined(clock10us__CFG3)
void clock10us_SetPhaseRegister(uint8 clkPhase) ;
uint8 clock10us_GetPhaseRegister(void) ;
#endif /* defined(clock10us__CFG3) */

#define clock10us_Enable()                       clock10us_Start()
#define clock10us_Disable()                      clock10us_Stop()
#define clock10us_SetDivider(clkDivider)         clock10us_SetDividerRegister(clkDivider, 1u)
#define clock10us_SetDividerValue(clkDivider)    clock10us_SetDividerRegister((clkDivider) - 1u, 1u)
#define clock10us_SetMode(clkMode)               clock10us_SetModeRegister(clkMode)
#define clock10us_SetSource(clkSource)           clock10us_SetSourceRegister(clkSource)
#if defined(clock10us__CFG3)
#define clock10us_SetPhase(clkPhase)             clock10us_SetPhaseRegister(clkPhase)
#define clock10us_SetPhaseValue(clkPhase)        clock10us_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(clock10us__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define clock10us_CLKEN              (* (reg8 *) clock10us__PM_ACT_CFG)
#define clock10us_CLKEN_PTR          ((reg8 *) clock10us__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define clock10us_CLKSTBY            (* (reg8 *) clock10us__PM_STBY_CFG)
#define clock10us_CLKSTBY_PTR        ((reg8 *) clock10us__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define clock10us_DIV_LSB            (* (reg8 *) clock10us__CFG0)
#define clock10us_DIV_LSB_PTR        ((reg8 *) clock10us__CFG0)
#define clock10us_DIV_PTR            ((reg16 *) clock10us__CFG0)

/* Clock MSB divider configuration register. */
#define clock10us_DIV_MSB            (* (reg8 *) clock10us__CFG1)
#define clock10us_DIV_MSB_PTR        ((reg8 *) clock10us__CFG1)

/* Mode and source configuration register */
#define clock10us_MOD_SRC            (* (reg8 *) clock10us__CFG2)
#define clock10us_MOD_SRC_PTR        ((reg8 *) clock10us__CFG2)

#if defined(clock10us__CFG3)
/* Analog clock phase configuration register */
#define clock10us_PHASE              (* (reg8 *) clock10us__CFG3)
#define clock10us_PHASE_PTR          ((reg8 *) clock10us__CFG3)
#endif /* defined(clock10us__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define clock10us_CLKEN_MASK         clock10us__PM_ACT_MSK
#define clock10us_CLKSTBY_MASK       clock10us__PM_STBY_MSK

/* CFG2 field masks */
#define clock10us_SRC_SEL_MSK        clock10us__CFG2_SRC_SEL_MASK
#define clock10us_MODE_MASK          (~(clock10us_SRC_SEL_MSK))

#if defined(clock10us__CFG3)
/* CFG3 phase mask */
#define clock10us_PHASE_MASK         clock10us__CFG3_PHASE_DLY_MASK
#endif /* defined(clock10us__CFG3) */

#endif /* CY_CLOCK_clock10us_H */


/* [] END OF FILE */
