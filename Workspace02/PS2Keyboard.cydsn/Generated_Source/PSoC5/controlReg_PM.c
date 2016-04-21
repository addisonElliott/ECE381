/*******************************************************************************
* File Name: controlReg_PM.c
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

#include "controlReg.h"

/* Check for removal by optimization */
#if !defined(controlReg_Sync_ctrl_reg__REMOVED)

static controlReg_BACKUP_STRUCT  controlReg_backup = {0u};

    
/*******************************************************************************
* Function Name: controlReg_SaveConfig
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
void controlReg_SaveConfig(void) 
{
    controlReg_backup.controlState = controlReg_Control;
}


/*******************************************************************************
* Function Name: controlReg_RestoreConfig
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
void controlReg_RestoreConfig(void) 
{
     controlReg_Control = controlReg_backup.controlState;
}


/*******************************************************************************
* Function Name: controlReg_Sleep
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
void controlReg_Sleep(void) 
{
    controlReg_SaveConfig();
}


/*******************************************************************************
* Function Name: controlReg_Wakeup
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
void controlReg_Wakeup(void)  
{
    controlReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
