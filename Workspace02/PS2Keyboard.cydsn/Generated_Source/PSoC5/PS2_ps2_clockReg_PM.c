/*******************************************************************************
* File Name: PS2_ps2_clockReg_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "PS2_ps2_clockReg.h"

/* Check for removal by optimization */
#if !defined(PS2_ps2_clockReg_Sync_ctrl_reg__REMOVED)

static PS2_ps2_clockReg_BACKUP_STRUCT  PS2_ps2_clockReg_backup = {0u};

    
/*******************************************************************************
* Function Name: PS2_ps2_clockReg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PS2_ps2_clockReg_SaveConfig(void) 
{
    PS2_ps2_clockReg_backup.controlState = PS2_ps2_clockReg_Control;
}


/*******************************************************************************
* Function Name: PS2_ps2_clockReg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void PS2_ps2_clockReg_RestoreConfig(void) 
{
     PS2_ps2_clockReg_Control = PS2_ps2_clockReg_backup.controlState;
}


/*******************************************************************************
* Function Name: PS2_ps2_clockReg_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PS2_ps2_clockReg_Sleep(void) 
{
    PS2_ps2_clockReg_SaveConfig();
}


/*******************************************************************************
* Function Name: PS2_ps2_clockReg_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PS2_ps2_clockReg_Wakeup(void)  
{
    PS2_ps2_clockReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
