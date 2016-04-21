/*******************************************************************************
* File Name: statusReg.h  
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

#if !defined(CY_STATUS_REG_statusReg_H) /* CY_STATUS_REG_statusReg_H */
#define CY_STATUS_REG_statusReg_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} statusReg_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 statusReg_Read(void) ;
void statusReg_InterruptEnable(void) ;
void statusReg_InterruptDisable(void) ;
void statusReg_WriteMask(uint8 mask) ;
uint8 statusReg_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define statusReg_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define statusReg_INPUTS              3


/***************************************
*             Registers
***************************************/

/* Status Register */
#define statusReg_Status             (* (reg8 *) statusReg_sts_sts_reg__STATUS_REG )
#define statusReg_Status_PTR         (  (reg8 *) statusReg_sts_sts_reg__STATUS_REG )
#define statusReg_Status_Mask        (* (reg8 *) statusReg_sts_sts_reg__MASK_REG )
#define statusReg_Status_Aux_Ctrl    (* (reg8 *) statusReg_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_statusReg_H */


/* [] END OF FILE */
