;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: PS2OneShot.asm
;;  Version: 1.0, Updated on 2015/3/4 at 22:26:45
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION: OneShot8 User Module software implementation file.
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
include "memory.inc"
include "PS2OneShot.inc"

;-----------------------------------------------
;  Global Symbols
;-----------------------------------------------
export   PS2OneShot_Start
export  _PS2OneShot_Start
export   PS2OneShot_Stop
export  _PS2OneShot_Stop
export   PS2OneShot_EnableInt
export  _PS2OneShot_EnableInt
export   PS2OneShot_DisableInt
export  _PS2OneShot_DisableInt
export   PS2OneShot_ClearInt
export  _PS2OneShot_ClearInt

;-----------------------------------------------
;  Constant Definitions
;-----------------------------------------------
bfCONTROL_REG_START_BIT:   equ   1        ; Control register start bit

AREA UserModules (ROM, REL)

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PS2OneShot_Start
;
;  DESCRIPTION:
;     Starts the OneShot user module.  
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: None
;
;  RETURNS:   None
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16
;    functions.
;
;
 PS2OneShot_Start:
_PS2OneShot_Start:
   RAM_PROLOGUE RAM_USE_CLASS_1
   or    REG[PS2OneShot_CONTROL_REG], bfCONTROL_REG_START_BIT
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PS2OneShot_Stop
;
;  DESCRIPTION:
;     Disables OneShot operation.
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: None
;
;  RETURNS:   None
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16
;    functions.
;
;
 PS2OneShot_Stop:
_PS2OneShot_Stop:
   RAM_PROLOGUE RAM_USE_CLASS_1
   and   REG[PS2OneShot_CONTROL_REG], ~bfCONTROL_REG_START_BIT
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PS2OneShot_EnableInt
;
;  DESCRIPTION:
;     Enables this counter's interrupt by setting the interrupt enable mask bit
;     associated with this User Module. This function has no effect until and
;     unless the global interrupts are enabled (for example by using the
;     macro M8C_EnableGInt).
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None.
;
;  RETURNS:      Nothing.
;
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PS2OneShot_EnableInt:
_PS2OneShot_EnableInt:
   RAM_PROLOGUE RAM_USE_CLASS_1
   M8C_EnableIntMask PS2OneShot_INT_REG, PS2OneShot_INT_MASK
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PS2OneShot_DisableInt
;
;  DESCRIPTION:
;     Disables this counter's interrupt by clearing the interrupt enable
;     mask bit associated with this User Module.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;
;  RETURNS:      Nothing
;
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PS2OneShot_DisableInt:
_PS2OneShot_DisableInt:
   RAM_PROLOGUE RAM_USE_CLASS_1
   M8C_DisableIntMask PS2OneShot_INT_REG, PS2OneShot_INT_MASK
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: PS2OneShot_ClearInt
;
;  DESCRIPTION:
;     Clear the pending interrupt from OneShot user module.
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:    None
;
;  RETURNS:      Nothing
;
;  SIDE EFFECTS: 
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 PS2OneShot_ClearInt:
_PS2OneShot_ClearInt:
   RAM_PROLOGUE RAM_USE_CLASS_1
   M8C_ClearIntFlag PS2OneShot_INT_CLR, PS2OneShot_INT_MASK  ; Clear the interrupt
   RAM_EPILOGUE RAM_USE_CLASS_1
   ret
.ENDSECTION

; End of File PS2OneShot.asm