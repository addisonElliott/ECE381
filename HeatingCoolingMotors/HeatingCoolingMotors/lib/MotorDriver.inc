;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: MotorDriver.inc
;;   Version: 2.5, Updated on 2015/3/4 at 22:23:43
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION: Assembler declarations for the Counter16 user module interface
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"


;--------------------------------------------------
; Constants for MotorDriver API's.
;--------------------------------------------------

MotorDriver_CONTROL_REG_START_BIT:         equ 0x01    ; Control register start bit
MotorDriver_INT_REG:                       equ 0x0e1
MotorDriver_INT_MASK:                      equ 0x02


;--------------------------------------------------
; Constants for MotorDriver user defined values
;--------------------------------------------------

MotorDriver_PERIOD:                        equ 0x9e
MotorDriver_COMPARE_VALUE:                 equ 0x4f


;--------------------------------------------------
; Register Address Constants for MotorDriver
;--------------------------------------------------

MotorDriver_COUNTER_LSB_REG:           equ 0x20   ; DR0 Counter register
MotorDriver_COUNTER_MSB_REG:           equ 0x24
MotorDriver_PERIOD_LSB_REG:            equ 0x21   ; DR1 Period register
MotorDriver_PERIOD_MSB_REG:            equ 0x25
MotorDriver_COMPARE_LSB_REG:           equ 0x22   ; DR2 CompareValue register
MotorDriver_COMPARE_MSB_REG:           equ 0x26
MotorDriver_CONTROL_LSB_REG:           equ 0x23   ; Control register
MotorDriver_CONTROL_MSB_REG:           equ 0x27
MotorDriver_FUNC_LSB_REG:              equ 0x20   ; Function register
MotorDriver_FUNC_MSB_REG:              equ 0x24
MotorDriver_INPUT_LSB_REG:             equ 0x21   ; Input register
MotorDriver_INPUT_MSB_REG:             equ 0x25
MotorDriver_OUTPUT_LSB_REG:            equ 0x22   ; Output register
MotorDriver_OUTPUT_MSB_REG:            equ 0x26


;--------------------------------------------------
; MotorDriver Macro 'Functions'
;--------------------------------------------------

   macro MotorDriver_Start_M
   or    reg[MotorDriver_CONTROL_LSB_REG],  MotorDriver_CONTROL_REG_START_BIT
   endm

   macro MotorDriver_Stop_M
   and   reg[MotorDriver_CONTROL_LSB_REG], ~MotorDriver_CONTROL_REG_START_BIT
   endm

   macro MotorDriver_EnableInt_M
   M8C_EnableIntMask MotorDriver_INT_REG, MotorDriver_INT_MASK
   endm

   macro MotorDriver_DisableInt_M
   M8C_DisableIntMask MotorDriver_INT_REG, MotorDriver_INT_MASK
   endm


; end of file MotorDriver.inc

