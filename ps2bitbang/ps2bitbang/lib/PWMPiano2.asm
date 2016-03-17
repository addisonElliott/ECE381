;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: PWMPiano2.asm
;;   Version: 2.5, Updated on 2015/3/4 at 22:26:51
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION: PWM16 User Module software implementation file
;;
;;  NOTE: User Module APIs conform to the fastcall16 convention for marshalling
;;        arguments and observe the associated "Registers are volatile" policy.
;;        This means it is the caller's responsibility to preserve any values
;;        in the X and A registers that are still needed after the API functions
;;        returns. For Large Memory Model devices it is also the caller's 
;;        responsibility to perserve any value in the CUR_PP, IDX_PP, MVR_PP and 
;;        MVW_PP registers. Even though some of these registers may not be modified
;;        now, there is no guarantee that will remain the case in future releases.
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"
include "PWMPiano2.inc"
include "memory.inc"

;-----------------------------------------------
;  Global Symbols
;-----------------------------------------------
export  PWMPiano2_EnableInt
export _PWMPiano2_EnableInt
export  PWMPiano2_DisableInt
export _PWMPiano2_DisableInt
export  PWMPiano2_Start
export _PWMPiano2_Start
export  PWMPiano2_Stop
export _PWMPiano2_Stop
export  PWMPiano2_WritePeriod
export _PWMPiano2_WritePeriod
export  PWMPiano2_WritePulseWidth
export _PWMPiano2_WritePulseWidth
export  PWMPiano2_wReadPulseWidth
export _PWMPiano2_wReadPulseWidth
export  PWMPiano2_wReadCounter
export _PWMPiano2_wReadCounter

; The following functions are deprecated and subject to omission in future releases
;
export  wPWMPiano2_ReadPulseWidth    ; deprecated
export _wPWMPiano2_ReadPulseWidth    ; deprecated
export  wPWMPiano2_ReadCounter       ; deprecated
export _wPWMPiano2_ReadCounter       ; deprecated


AREA ps2bitbang_RAM (RAM,REL)

;-----------------------------------------------
;  Constant Definitions
;-----------------------------------------------

INPUT_REG_NULL:                equ 0x00    ; Clear the input register


;-----------------------------------------------
; Variable Allocation
;-----------------------------------------------


AREA UserModules (ROM, REL)

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PWMPiano2_EnableInt
;
;  DESCRIPTION:
;     Enables this PWM's interrupt by setting the interrupt enable mask bit
;     associated with this User Module. This function has no effect until and
;     unless the global interrupts are enabled (for example by using the
;     macro M8C_EnableGInt).
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None.
;  RETURNS:      Nothing.
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PWMPiano2_EnableInt:
_PWMPiano2_EnableInt:
   RAM_PROLOGUE RAM_USE_CLASS_1
   PWMPiano2_EnableInt_M
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret


.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PWMPiano2_DisableInt
;
;  DESCRIPTION:
;     Disables this PWM's interrupt by clearing the interrupt enable
;     mask bit associated with this User Module.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;  RETURNS:      Nothing
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PWMPiano2_DisableInt:
_PWMPiano2_DisableInt:
   RAM_PROLOGUE RAM_USE_CLASS_1
   PWMPiano2_DisableInt_M
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret


.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PWMPiano2_Start
;
;  DESCRIPTION:
;     Sets the start bit in the Control register of this user module.  The
;     PWM will begin counting on the next input clock as soon as the
;     enable input is asserted high.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;  RETURNS:      Nothing
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PWMPiano2_Start:
_PWMPiano2_Start:
   RAM_PROLOGUE RAM_USE_CLASS_1
   PWMPiano2_Start_M
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret


.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PWMPiano2_Stop
;
;  DESCRIPTION:
;     Disables PWM operation by clearing the start bit in the Control
;     register of the LSB block.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;  RETURNS:      Nothing
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PWMPiano2_Stop:
_PWMPiano2_Stop:
   RAM_PROLOGUE RAM_USE_CLASS_1
   PWMPiano2_Stop_M
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret


.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PWMPiano2_WritePeriod
;
;  DESCRIPTION:
;     Write the 16-bit period value into the Period register (DR1).
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: fastcall16 WORD wPeriodValue (LSB in A, MSB in X)
;  RETURNS:   Nothing
;  SIDE EFFECTS:
;    If the PWM user module is stopped, then this value will also be
;    latched into the Count registers (DR0).
;    
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PWMPiano2_WritePeriod:
_PWMPiano2_WritePeriod:
   RAM_PROLOGUE RAM_USE_CLASS_1
   mov   reg[PWMPiano2_PERIOD_LSB_REG], A
   mov   A, X
   mov   reg[PWMPiano2_PERIOD_MSB_REG], A
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret


.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PWMPiano2_WritePulseWidth
;
;  DESCRIPTION:
;     Writes the pulse width value into the Compare register (DR2).
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    fastcall16 WORD wCompareValue (LSB in A, MSB in X)
;  RETURNS:      Nothing
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PWMPiano2_WritePulseWidth:
_PWMPiano2_WritePulseWidth:
   RAM_PROLOGUE RAM_USE_CLASS_1
   mov   reg[PWMPiano2_COMPARE_LSB_REG], A
   mov   A, X
   mov   reg[PWMPiano2_COMPARE_MSB_REG], A
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret


.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PWMPiano2_wReadPulseWidth
;
;  DESCRIPTION:
;     Reads the Compare register.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;  RETURNS:      fastcall16 WORD wCompareValue (value of DR2 in the X & A registers)
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PWMPiano2_wReadPulseWidth:
_PWMPiano2_wReadPulseWidth:
 wPWMPiano2_ReadPulseWidth:                      ; this name deprecated
_wPWMPiano2_ReadPulseWidth:                      ; this name deprecated
   RAM_PROLOGUE RAM_USE_CLASS_1
   mov   A, reg[PWMPiano2_COMPARE_MSB_REG]
   mov   X, A
   mov   A, reg[PWMPiano2_COMPARE_LSB_REG]
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret


.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PWMPiano2_wReadCounter
;
;  DESCRIPTION:
;     Returns the value in the Count register (DR0), preserving the value in
;     the compare register (DR2). Interrupts are prevented during the transfer
;     from the Count to the Compare register by holding the clock low in
;     the MSB PSoC block.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: None
;  RETURNS:   fastcall16 WORD wCount (value of DR0 in the X & A registers)
;  SIDE EFFECTS:
;     1) The user module is stopped momentarily and one or more counts may be missed.
;     2) The A and X registers may be modified by this or future implementations
;        of this function.  The same is true for all RAM page pointer registers in
;        the Large Memory Model.  When necessary, it is the calling function's
;        responsibility to perserve their values across calls to fastcall16 
;        functions.
;
 PWMPiano2_wReadCounter:
_PWMPiano2_wReadCounter:
 wPWMPiano2_ReadCounter:                         ; this name deprecated
_wPWMPiano2_ReadCounter:                         ; this name deprecated

   bOrigCompareValue:      EQU   0                  ; Frame offset to temp Compare store
   bOrigClockSetting:      EQU   2                  ; Frame offset to temp Input   store
   wCounter:               EQU   3                  ; Frame offset to temp Count   store
   STACK_FRAME_SIZE:       EQU   5                  ; max stack frame size is 5 bytes

   RAM_PROLOGUE RAM_USE_CLASS_2
   mov   X, SP                                      ; X <-  stack frame pointer
   mov   A, reg[PWMPiano2_COMPARE_MSB_REG]       ; Save the Compare register on the stack
   push  A                                          ;
   mov   A, reg[PWMPiano2_COMPARE_LSB_REG]       ;
   push  A                                          ;  -stack frame now 2 bytes-
   PWMPiano2_Stop_M                              ; Disable the PWM function
   M8C_SetBank1                                     ;
   mov   A, reg[PWMPiano2_INPUT_LSB_REG]         ; save the LSB clock input setting
   push  A                                          ;   on the stack (now 3 bytes) and ...
                                                    ;   hold the clock low:
   mov   reg[PWMPiano2_INPUT_LSB_REG], INPUT_REG_NULL
   M8C_SetBank0                                     ; Extract the Count via DR2 register
   mov   A, reg[PWMPiano2_COUNTER_MSB_REG]       ; DR2 <- DR0 (in the MSB block)
   mov   A, reg[PWMPiano2_COMPARE_MSB_REG]       ; Stash the Count MSB on the stack
   push  A                                          ;  -stack frame is now 4 bytes
   mov   A, reg[PWMPiano2_COUNTER_LSB_REG]       ; DR2 <- DR0 (in the LSB block)
   mov   A, reg[PWMPiano2_COMPARE_LSB_REG]       ; Stash the Count LSB on the stack
   push  A                                          ;   -stack frame is now 5 bytes-
   mov   A, [X+bOrigCompareValue]                   ; Restore the Compare MSB register
   mov   reg[PWMPiano2_COMPARE_MSB_REG], A       ;
   mov   A, [X+bOrigCompareValue+1]                 ; Restore the Compare LSB register
   mov   reg[PWMPiano2_COMPARE_LSB_REG], A       ;
   M8C_SetBank1                                     ; ---Restore the PWM operation
   mov   A, [X+bOrigClockSetting]                   ; Grab the LSB clock setting...
   mov   reg[PWMPiano2_INPUT_LSB_REG], A         ;    and restore it
   M8C_SetBank0                                     ;
   PWMPiano2_Start_M                             ; Now re-enable the PWM function
   pop   A                                          ; Setup the return value
   pop   X                                          ;
   ADD   SP, -(STACK_FRAME_SIZE-2)                  ; Zap remainder of stack frame
   RAM_EPILOGUE RAM_USE_CLASS_2
   ret

.ENDSECTION

; End of File PWMPiano2.asm
