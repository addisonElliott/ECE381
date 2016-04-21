/*******************************************************************************
* File Name: dataIn_PM.c
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

#include "dataIn.h"

/* Check for removal by optimization */
#if !defined(dataIn_Sync_ctrl_reg__REMOVED)

static dataIn_BACKUP_STRUCT  dataIn_backup = {0u};

    
/*******************************************************************************
* Function Name: dataIn_SaveConfig
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
void dataIn_SaveConfig(void) 
{
    dataIn_backup.controlState = dataIn_Control;
}


/*******************************************************************************
* Function Name: dataIn_RestoreConfig
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
void dataIn_RestoreConfig(void) 
{
     dataIn_Control = dataIn_backup.controlState;
}


/*******************************************************************************
* Function Name: dataIn_Sleep
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
void dataIn_Sleep(void) 
{
    dataIn_SaveConfig();
}


/*******************************************************************************
* Function Name: dataIn_Wakeup
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
void dataIn_Wakeup(void)  
{
    dataIn_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
