/*******************************************************************************
* File Name: PS2_Counter_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "PS2_Counter.h"

static PS2_Counter_backupStruct PS2_Counter_backup;


/*******************************************************************************
* Function Name: PS2_Counter_SaveConfig
********************************************************************************
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
*  PS2_Counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PS2_Counter_SaveConfig(void) 
{
    #if (!PS2_Counter_UsingFixedFunction)

        PS2_Counter_backup.CounterUdb = PS2_Counter_ReadCounter();

        #if(!PS2_Counter_ControlRegRemoved)
            PS2_Counter_backup.CounterControlRegister = PS2_Counter_ReadControlRegister();
        #endif /* (!PS2_Counter_ControlRegRemoved) */

    #endif /* (!PS2_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PS2_Counter_RestoreConfig
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
*  PS2_Counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PS2_Counter_RestoreConfig(void) 
{      
    #if (!PS2_Counter_UsingFixedFunction)

       PS2_Counter_WriteCounter(PS2_Counter_backup.CounterUdb);

        #if(!PS2_Counter_ControlRegRemoved)
            PS2_Counter_WriteControlRegister(PS2_Counter_backup.CounterControlRegister);
        #endif /* (!PS2_Counter_ControlRegRemoved) */

    #endif /* (!PS2_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PS2_Counter_Sleep
********************************************************************************
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
*  PS2_Counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PS2_Counter_Sleep(void) 
{
    #if(!PS2_Counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(PS2_Counter_CTRL_ENABLE == (PS2_Counter_CONTROL & PS2_Counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            PS2_Counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            PS2_Counter_backup.CounterEnableState = 0u;
        }
    #else
        PS2_Counter_backup.CounterEnableState = 1u;
        if(PS2_Counter_backup.CounterEnableState != 0u)
        {
            PS2_Counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!PS2_Counter_ControlRegRemoved) */
    
    PS2_Counter_Stop();
    PS2_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: PS2_Counter_Wakeup
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
*  PS2_Counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PS2_Counter_Wakeup(void) 
{
    PS2_Counter_RestoreConfig();
    #if(!PS2_Counter_ControlRegRemoved)
        if(PS2_Counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            PS2_Counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!PS2_Counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
