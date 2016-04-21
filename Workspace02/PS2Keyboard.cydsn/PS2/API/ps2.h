/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#if !defined(`$INSTANCE_NAME`_H)
#define `$INSTANCE_NAME`_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"
    
#include "`$INSTANCE_NAME`_Timer.h"
#include "`$INSTANCE_NAME`_Timer_ISR.h"
#include "`$INSTANCE_NAME`_controlReg.h"
#include "`$INSTANCE_NAME`_dataOut.h"
#include "`$INSTANCE_NAME`_stateReg.h"
#include "`$INSTANCE_NAME`_statusReg.h"
    
#define `$INSTANCE_NAME`_READ           (`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() & ~0x02))
#define `$INSTANCE_NAME`_WRITE          (`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() | 0x02))
    
#define `$INSTANCE_NAME`_STATE          (`$INSTANCE_NAME`_stateReg_Read())
#define `$INSTANCE_NAME`_STATUS         (`$INSTANCE_NAME`_statusReg_Read())
#define `$INSTANCE_NAME`_BYTE_R         (`$INSTANCE_NAME`_dataOut_Read())
    
#define `$INSTANCE_NAME`_TIMER_RESET    (`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() | 0x01))

#define `$INSTANCE_NAME`_TIMER_START(period) { `$INSTANCE_NAME`_counter_trigger = 0; `$INSTANCE_NAME`_Timer_WritePeriod(period); `$INSTANCE_NAME`_Timer_Start(); }

#define `$INSTANCE_NAME`_STATUS_PENDING     0
#define `$INSTANCE_NAME`_STATUS_DONE        1
#define `$INSTANCE_NAME`_STATUS_ERROR       2
    
#define `$INSTANCE_NAME`_SUCCESS            1
#define `$INSTANCE_NAME`_MOUSE              2
#define `$INSTANCE_NAME`_BAD_BAT            3
#define `$INSTANCE_NAME`_TIMEOUT            4
#define `$INSTANCE_NAME`_ERROR              5
    
extern uint8 `$INSTANCE_NAME`_counter_trigger;
extern uint8 `$INSTANCE_NAME`_initVar;
    
void `$INSTANCE_NAME`_Init(void) `=ReentrantKeil($INSTANCE_NAME . "_Init")`;
void `$INSTANCE_NAME`_Start(void) `=ReentrantKeil($INSTANCE_NAME . "_Start")`;
uint8 `$INSTANCE_NAME`_DetectDevice(void) `=ReentrantKeil($INSTANCE_NAME . "_Init")`;

#endif /* `$INSTANCE_NAME`_H */

/* [] END OF FILE */
