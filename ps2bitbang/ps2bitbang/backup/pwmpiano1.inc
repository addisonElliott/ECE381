;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: PWMPiano1.inc
;;   Version: 2.5, Updated on 2015/3/4 at 22:26:51
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION: Assembler declarations for the PWM16 user module interface
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"


;--------------------------------------------------
; Constants for PWMPiano1 API's.
;--------------------------------------------------

PWMPiano1_CONTROL_REG_START_BIT:           equ 0x01    ; Control register start bit
PWMPiano1_INT_REG:                         equ 0x0df
PWMPiano1_INT_MASK:                        equ 0x08


;--------------------------------------------------
; Constants for PWMPiano1 user defined values
;--------------------------------------------------

PWMPiano1_PERIOD:                          equ 0x0
PWMPiano1_PULSE_WIDTH:                     equ 0x0


;--------------------------------------------------
; Register Address Constants for PWMPiano1
;--------------------------------------------------

PWMPiano1_COUNTER_LSB_REG:             equ 0x48   ; DR0 Count register
PWMPiano1_COUNTER_MSB_REG:             equ 0x4c
PWMPiano1_PERIOD_LSB_REG:              equ 0x49   ; DR1 Period register
PWMPiano1_PERIOD_MSB_REG:              equ 0x4d
PWMPiano1_COMPARE_LSB_REG:             equ 0x4a   ; DR2 Compare register
PWMPiano1_COMPARE_MSB_REG:             equ 0x4e
PWMPiano1_CONTROL_LSB_REG:             equ 0x4b   ; Control register
PWMPiano1_CONTROL_MSB_REG:             equ 0x4f
PWMPiano1_FUNC_LSB_REG:                equ 0x48   ; Function register
PWMPiano1_FUNC_MSB_REG:                equ 0x4c
PWMPiano1_INPUT_LSB_REG:               equ 0x49   ; Input register
PWMPiano1_INPUT_MSB_REG:               equ 0x4d
PWMPiano1_OUTPUT_LSB_REG:              equ 0x4a   ; Output register
PWMPiano1_OUTPUT_MSB_REG:              equ 0x4e


;--------------------------------------------------
; PWMPiano1 Macro 'Functions'
;--------------------------------------------------

   macro PWMPiano1_Start_M
   or    reg[PWMPiano1_CONTROL_LSB_REG],  PWMPiano1_CONTROL_REG_START_BIT
   endm

   macro PWMPiano1_Stop_M
   and   reg[PWMPiano1_CONTROL_LSB_REG], ~PWMPiano1_CONTROL_REG_START_BIT
   endm

   macro PWMPiano1_EnableInt_M
   M8C_EnableIntMask PWMPiano1_INT_REG, PWMPiano1_INT_MASK
   endm

   macro PWMPiano1_DisableInt_M
   M8C_DisableIntMask PWMPiano1_INT_REG, PWMPiano1_INT_MASK
   endm


; end of file PWMPiano1.inc
