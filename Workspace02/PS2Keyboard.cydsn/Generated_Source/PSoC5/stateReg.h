/*******************************************************************************
* File Name: stateReg.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_stateReg_H) /* CY_STATUS_REG_stateReg_H */
#define CY_STATUS_REG_stateReg_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} stateReg_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 stateReg_Read(void) ;
void stateReg_InterruptEnable(void) ;
void stateReg_InterruptDisable(void) ;
void stateReg_WriteMask(uint8 mask) ;
uint8 stateReg_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define stateReg_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define stateReg_INPUTS              8


/***************************************
*             Registers
***************************************/

/* Status Register */
#define stateReg_Status             (* (reg8 *) stateReg_sts_sts_reg__STATUS_REG )
#define stateReg_Status_PTR         (  (reg8 *) stateReg_sts_sts_reg__STATUS_REG )
#define stateReg_Status_Mask        (* (reg8 *) stateReg_sts_sts_reg__MASK_REG )
#define stateReg_Status_Aux_Ctrl    (* (reg8 *) stateReg_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_stateReg_H */


/* [] END OF FILE */
