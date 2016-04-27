/*******************************************************************************
* File Name: PS2_statusReg.h  
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

#if !defined(CY_STATUS_REG_PS2_statusReg_H) /* CY_STATUS_REG_PS2_statusReg_H */
#define CY_STATUS_REG_PS2_statusReg_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} PS2_statusReg_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 PS2_statusReg_Read(void) ;
void PS2_statusReg_InterruptEnable(void) ;
void PS2_statusReg_InterruptDisable(void) ;
void PS2_statusReg_WriteMask(uint8 mask) ;
uint8 PS2_statusReg_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define PS2_statusReg_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define PS2_statusReg_INPUTS              2


/***************************************
*             Registers
***************************************/

/* Status Register */
#define PS2_statusReg_Status             (* (reg8 *) PS2_statusReg_sts_sts_reg__STATUS_REG )
#define PS2_statusReg_Status_PTR         (  (reg8 *) PS2_statusReg_sts_sts_reg__STATUS_REG )
#define PS2_statusReg_Status_Mask        (* (reg8 *) PS2_statusReg_sts_sts_reg__MASK_REG )
#define PS2_statusReg_Status_Aux_Ctrl    (* (reg8 *) PS2_statusReg_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_PS2_statusReg_H */


/* [] END OF FILE */
