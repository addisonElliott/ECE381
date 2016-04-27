/*******************************************************************************
* File Name: PS2_dataAttr.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "PS2_dataAttr.h"

#if !defined(PS2_dataAttr_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: PS2_dataAttr_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 PS2_dataAttr_Read(void) 
{ 
    return PS2_dataAttr_Status;
}


/*******************************************************************************
* Function Name: PS2_dataAttr_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void PS2_dataAttr_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    PS2_dataAttr_Status_Aux_Ctrl |= PS2_dataAttr_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: PS2_dataAttr_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void PS2_dataAttr_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    PS2_dataAttr_Status_Aux_Ctrl &= (uint8)(~PS2_dataAttr_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: PS2_dataAttr_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void PS2_dataAttr_WriteMask(uint8 mask) 
{
    #if(PS2_dataAttr_INPUTS < 8u)
    	mask &= ((uint8)(1u << PS2_dataAttr_INPUTS) - 1u);
	#endif /* End PS2_dataAttr_INPUTS < 8u */
    PS2_dataAttr_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: PS2_dataAttr_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 PS2_dataAttr_ReadMask(void) 
{
    return PS2_dataAttr_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
