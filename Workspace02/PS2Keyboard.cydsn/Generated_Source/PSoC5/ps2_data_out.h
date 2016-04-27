/*******************************************************************************
* File Name: ps2_data_out.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ps2_data_out_H) /* Pins ps2_data_out_H */
#define CY_PINS_ps2_data_out_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ps2_data_out_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ps2_data_out__PORT == 15 && ((ps2_data_out__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ps2_data_out_Write(uint8 value);
void    ps2_data_out_SetDriveMode(uint8 mode);
uint8   ps2_data_out_ReadDataReg(void);
uint8   ps2_data_out_Read(void);
void    ps2_data_out_SetInterruptMode(uint16 position, uint16 mode);
uint8   ps2_data_out_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ps2_data_out_SetDriveMode() function.
     *  @{
     */
        #define ps2_data_out_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ps2_data_out_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ps2_data_out_DM_RES_UP          PIN_DM_RES_UP
        #define ps2_data_out_DM_RES_DWN         PIN_DM_RES_DWN
        #define ps2_data_out_DM_OD_LO           PIN_DM_OD_LO
        #define ps2_data_out_DM_OD_HI           PIN_DM_OD_HI
        #define ps2_data_out_DM_STRONG          PIN_DM_STRONG
        #define ps2_data_out_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ps2_data_out_MASK               ps2_data_out__MASK
#define ps2_data_out_SHIFT              ps2_data_out__SHIFT
#define ps2_data_out_WIDTH              1u

/* Interrupt constants */
#if defined(ps2_data_out__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ps2_data_out_SetInterruptMode() function.
     *  @{
     */
        #define ps2_data_out_INTR_NONE      (uint16)(0x0000u)
        #define ps2_data_out_INTR_RISING    (uint16)(0x0001u)
        #define ps2_data_out_INTR_FALLING   (uint16)(0x0002u)
        #define ps2_data_out_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ps2_data_out_INTR_MASK      (0x01u) 
#endif /* (ps2_data_out__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ps2_data_out_PS                     (* (reg8 *) ps2_data_out__PS)
/* Data Register */
#define ps2_data_out_DR                     (* (reg8 *) ps2_data_out__DR)
/* Port Number */
#define ps2_data_out_PRT_NUM                (* (reg8 *) ps2_data_out__PRT) 
/* Connect to Analog Globals */                                                  
#define ps2_data_out_AG                     (* (reg8 *) ps2_data_out__AG)                       
/* Analog MUX bux enable */
#define ps2_data_out_AMUX                   (* (reg8 *) ps2_data_out__AMUX) 
/* Bidirectional Enable */                                                        
#define ps2_data_out_BIE                    (* (reg8 *) ps2_data_out__BIE)
/* Bit-mask for Aliased Register Access */
#define ps2_data_out_BIT_MASK               (* (reg8 *) ps2_data_out__BIT_MASK)
/* Bypass Enable */
#define ps2_data_out_BYP                    (* (reg8 *) ps2_data_out__BYP)
/* Port wide control signals */                                                   
#define ps2_data_out_CTL                    (* (reg8 *) ps2_data_out__CTL)
/* Drive Modes */
#define ps2_data_out_DM0                    (* (reg8 *) ps2_data_out__DM0) 
#define ps2_data_out_DM1                    (* (reg8 *) ps2_data_out__DM1)
#define ps2_data_out_DM2                    (* (reg8 *) ps2_data_out__DM2) 
/* Input Buffer Disable Override */
#define ps2_data_out_INP_DIS                (* (reg8 *) ps2_data_out__INP_DIS)
/* LCD Common or Segment Drive */
#define ps2_data_out_LCD_COM_SEG            (* (reg8 *) ps2_data_out__LCD_COM_SEG)
/* Enable Segment LCD */
#define ps2_data_out_LCD_EN                 (* (reg8 *) ps2_data_out__LCD_EN)
/* Slew Rate Control */
#define ps2_data_out_SLW                    (* (reg8 *) ps2_data_out__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ps2_data_out_PRTDSI__CAPS_SEL       (* (reg8 *) ps2_data_out__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ps2_data_out_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ps2_data_out__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ps2_data_out_PRTDSI__OE_SEL0        (* (reg8 *) ps2_data_out__PRTDSI__OE_SEL0) 
#define ps2_data_out_PRTDSI__OE_SEL1        (* (reg8 *) ps2_data_out__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ps2_data_out_PRTDSI__OUT_SEL0       (* (reg8 *) ps2_data_out__PRTDSI__OUT_SEL0) 
#define ps2_data_out_PRTDSI__OUT_SEL1       (* (reg8 *) ps2_data_out__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ps2_data_out_PRTDSI__SYNC_OUT       (* (reg8 *) ps2_data_out__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ps2_data_out__SIO_CFG)
    #define ps2_data_out_SIO_HYST_EN        (* (reg8 *) ps2_data_out__SIO_HYST_EN)
    #define ps2_data_out_SIO_REG_HIFREQ     (* (reg8 *) ps2_data_out__SIO_REG_HIFREQ)
    #define ps2_data_out_SIO_CFG            (* (reg8 *) ps2_data_out__SIO_CFG)
    #define ps2_data_out_SIO_DIFF           (* (reg8 *) ps2_data_out__SIO_DIFF)
#endif /* (ps2_data_out__SIO_CFG) */

/* Interrupt Registers */
#if defined(ps2_data_out__INTSTAT)
    #define ps2_data_out_INTSTAT            (* (reg8 *) ps2_data_out__INTSTAT)
    #define ps2_data_out_SNAP               (* (reg8 *) ps2_data_out__SNAP)
    
	#define ps2_data_out_0_INTTYPE_REG 		(* (reg8 *) ps2_data_out__0__INTTYPE)
#endif /* (ps2_data_out__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ps2_data_out_H */


/* [] END OF FILE */
