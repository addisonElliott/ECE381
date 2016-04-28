/*******************************************************************************
* File Name: mainClock.h
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

#if !defined(CY_CLOCK_mainClock_H)
#define CY_CLOCK_mainClock_H

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

void mainClock_Start(void) ;
void mainClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void mainClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void mainClock_StandbyPower(uint8 state) ;
void mainClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 mainClock_GetDividerRegister(void) ;
void mainClock_SetModeRegister(uint8 modeBitMask) ;
void mainClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 mainClock_GetModeRegister(void) ;
void mainClock_SetSourceRegister(uint8 clkSource) ;
uint8 mainClock_GetSourceRegister(void) ;
#if defined(mainClock__CFG3)
void mainClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 mainClock_GetPhaseRegister(void) ;
#endif /* defined(mainClock__CFG3) */

#define mainClock_Enable()                       mainClock_Start()
#define mainClock_Disable()                      mainClock_Stop()
#define mainClock_SetDivider(clkDivider)         mainClock_SetDividerRegister(clkDivider, 1u)
#define mainClock_SetDividerValue(clkDivider)    mainClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define mainClock_SetMode(clkMode)               mainClock_SetModeRegister(clkMode)
#define mainClock_SetSource(clkSource)           mainClock_SetSourceRegister(clkSource)
#if defined(mainClock__CFG3)
#define mainClock_SetPhase(clkPhase)             mainClock_SetPhaseRegister(clkPhase)
#define mainClock_SetPhaseValue(clkPhase)        mainClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(mainClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define mainClock_CLKEN              (* (reg8 *) mainClock__PM_ACT_CFG)
#define mainClock_CLKEN_PTR          ((reg8 *) mainClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define mainClock_CLKSTBY            (* (reg8 *) mainClock__PM_STBY_CFG)
#define mainClock_CLKSTBY_PTR        ((reg8 *) mainClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define mainClock_DIV_LSB            (* (reg8 *) mainClock__CFG0)
#define mainClock_DIV_LSB_PTR        ((reg8 *) mainClock__CFG0)
#define mainClock_DIV_PTR            ((reg16 *) mainClock__CFG0)

/* Clock MSB divider configuration register. */
#define mainClock_DIV_MSB            (* (reg8 *) mainClock__CFG1)
#define mainClock_DIV_MSB_PTR        ((reg8 *) mainClock__CFG1)

/* Mode and source configuration register */
#define mainClock_MOD_SRC            (* (reg8 *) mainClock__CFG2)
#define mainClock_MOD_SRC_PTR        ((reg8 *) mainClock__CFG2)

#if defined(mainClock__CFG3)
/* Analog clock phase configuration register */
#define mainClock_PHASE              (* (reg8 *) mainClock__CFG3)
#define mainClock_PHASE_PTR          ((reg8 *) mainClock__CFG3)
#endif /* defined(mainClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define mainClock_CLKEN_MASK         mainClock__PM_ACT_MSK
#define mainClock_CLKSTBY_MASK       mainClock__PM_STBY_MSK

/* CFG2 field masks */
#define mainClock_SRC_SEL_MSK        mainClock__CFG2_SRC_SEL_MASK
#define mainClock_MODE_MASK          (~(mainClock_SRC_SEL_MSK))

#if defined(mainClock__CFG3)
/* CFG3 phase mask */
#define mainClock_PHASE_MASK         mainClock__CFG3_PHASE_DLY_MASK
#endif /* defined(mainClock__CFG3) */

#endif /* CY_CLOCK_mainClock_H */


/* [] END OF FILE */
