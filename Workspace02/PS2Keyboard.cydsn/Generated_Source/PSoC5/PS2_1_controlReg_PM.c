/*******************************************************************************
* File Name: PS2_1_controlReg_PM.c
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

#include "PS2_1_controlReg.h"

/* Check for removal by optimization */
#if !defined(PS2_1_controlReg_Sync_ctrl_reg__REMOVED)

static PS2_1_controlReg_BACKUP_STRUCT  PS2_1_controlReg_backup = {0u};

    
/*******************************************************************************
* Function Name: PS2_1_controlReg_SaveConfig
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
void PS2_1_controlReg_SaveConfig(void) 
{
    PS2_1_controlReg_backup.controlState = PS2_1_controlReg_Control;
}


/*******************************************************************************
* Function Name: PS2_1_controlReg_RestoreConfig
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
void PS2_1_controlReg_RestoreConfig(void) 
{
     PS2_1_controlReg_Control = PS2_1_controlReg_backup.controlState;
}


/*******************************************************************************
* Function Name: PS2_1_controlReg_Sleep
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
void PS2_1_controlReg_Sleep(void) 
{
    PS2_1_controlReg_SaveConfig();
}


/*******************************************************************************
* Function Name: PS2_1_controlReg_Wakeup
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
void PS2_1_controlReg_Wakeup(void)  
{
    PS2_1_controlReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
