;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: SW2Buf.inc
;;  Version: 1.3, Updated on 2015/3/4 at 22:26:4
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION: Assembler declarations for the Counter8 user module interface
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"


;--------------------------------------------------
; Constants for SW2Buf API's.
;--------------------------------------------------

SW2Buf_CONTROL_REG_START_BIT:              equ 0x01    ; Control register start bit
SW2Buf_INT_REG:                            equ 0x0e1
SW2Buf_INT_MASK:                           equ 0x04


;--------------------------------------------------
; Register Address Constants for SW2Buf
;--------------------------------------------------

SW2Buf_DATA_0_REG:                     equ 0x28   ; DR0 register
SW2Buf_DATA_1_REG:                     equ 0x29   ; DR1 register
SW2Buf_DATA_2_REG:                     equ 0x2a   ; DR2 register
SW2Buf_CONTROL_REG:                    equ 0x2b   ; Control register
SW2Buf_FUNC_REG:                       equ 0x28   ; Function register
SW2Buf_INPUT_REG:                      equ 0x29   ; Input register
SW2Buf_OUTPUT_REG:                     equ 0x2a   ; Output register


;--------------------------------------------------
; SW2Buf Macro 'Functions'
;--------------------------------------------------

   macro SW2Buf_Start_M
   or    reg[SW2Buf_CONTROL_REG],  SW2Buf_CONTROL_REG_START_BIT
   endm

   macro SW2Buf_Stop_M
   and   reg[SW2Buf_CONTROL_REG], ~SW2Buf_CONTROL_REG_START_BIT
   endm

   macro SW2Buf_EnableInt_M
   M8C_EnableIntMask SW2Buf_INT_REG, SW2Buf_INT_MASK
   endm

   macro SW2Buf_DisableInt_M
   M8C_DisableIntMask SW2Buf_INT_REG, SW2Buf_INT_MASK
   endm


; end of file SW2Buf.inc
