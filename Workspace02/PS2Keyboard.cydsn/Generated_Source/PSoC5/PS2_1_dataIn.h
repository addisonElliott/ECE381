/*******************************************************************************
* File Name: PS2_1_dataIn.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_PS2_1_dataIn_H) /* CY_CONTROL_REG_PS2_1_dataIn_H */
#define CY_CONTROL_REG_PS2_1_dataIn_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} PS2_1_dataIn_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    PS2_1_dataIn_Write(uint8 control) ;
uint8   PS2_1_dataIn_Read(void) ;

void PS2_1_dataIn_SaveConfig(void) ;
void PS2_1_dataIn_RestoreConfig(void) ;
void PS2_1_dataIn_Sleep(void) ; 
void PS2_1_dataIn_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define PS2_1_dataIn_Control        (* (reg8 *) PS2_1_dataIn_Sync_ctrl_reg__CONTROL_REG )
#define PS2_1_dataIn_Control_PTR    (  (reg8 *) PS2_1_dataIn_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_PS2_1_dataIn_H */


/* [] END OF FILE */
