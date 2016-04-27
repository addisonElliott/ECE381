;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: PS2OneShot.inc
;;  Version: 1.0, Updated on 2015/3/4 at 22:26:45
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION: Assembler declarations for the OneShot8 user module interface.
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"

;--------------------------------------------------
; Constants for PS2OneShot API's.
;--------------------------------------------------
PS2OneShot_INT_REG:                        equ 0x0e1
PS2OneShot_INT_MASK:                       equ 0x20
IF (PS2OneShot_INT_REG - INT_MSK1)
PS2OneShot_INT_CLR:                     equ INT_CLR2
ELSE
PS2OneShot_INT_CLR:                     equ INT_CLR1
ENDIF

;--------------------------------------------------
; Register Address Constants for PS2OneShot
;--------------------------------------------------
PS2OneShot_FUNC_REG:    equ 34h                  ;function register 
PS2OneShot_INPUT_REG:   equ 35h                  ;input register 
PS2OneShot_OUTPUT_REG:  equ 36h                  ;output register 
PS2OneShot_CONTROL_REG: equ 37h                  ;control register 
PS2OneShot_SHIFT_REG:   equ 34h                  ;shift register 
PS2OneShot_POLY_REG:    equ 35h                  ;polynomial register 
PS2OneShot_SEED_REG:    equ 36h                  ;seed register 

; end of file PS2OneShot.inc