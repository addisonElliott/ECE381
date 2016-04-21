/*******************************************************************************
* File Name: PS2_Timer_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "PS2_Timer.h"

static PS2_Timer_backupStruct PS2_Timer_backup;


/*******************************************************************************
* Function Name: PS2_Timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PS2_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PS2_Timer_SaveConfig(void) 
{
    #if (!PS2_Timer_UsingFixedFunction)
        PS2_Timer_backup.TimerUdb = PS2_Timer_ReadCounter();
        PS2_Timer_backup.InterruptMaskValue = PS2_Timer_STATUS_MASK;
        #if (PS2_Timer_UsingHWCaptureCounter)
            PS2_Timer_backup.TimerCaptureCounter = PS2_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!PS2_Timer_UDB_CONTROL_REG_REMOVED)
            PS2_Timer_backup.TimerControlRegister = PS2_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: PS2_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PS2_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PS2_Timer_RestoreConfig(void) 
{   
    #if (!PS2_Timer_UsingFixedFunction)

        PS2_Timer_WriteCounter(PS2_Timer_backup.TimerUdb);
        PS2_Timer_STATUS_MASK =PS2_Timer_backup.InterruptMaskValue;
        #if (PS2_Timer_UsingHWCaptureCounter)
            PS2_Timer_SetCaptureCount(PS2_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!PS2_Timer_UDB_CONTROL_REG_REMOVED)
            PS2_Timer_WriteControlRegister(PS2_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: PS2_Timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PS2_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void PS2_Timer_Sleep(void) 
{
    #if(!PS2_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(PS2_Timer_CTRL_ENABLE == (PS2_Timer_CONTROL & PS2_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            PS2_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            PS2_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    PS2_Timer_Stop();
    PS2_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: PS2_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PS2_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PS2_Timer_Wakeup(void) 
{
    PS2_Timer_RestoreConfig();
    #if(!PS2_Timer_UDB_CONTROL_REG_REMOVED)
        if(PS2_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                PS2_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
