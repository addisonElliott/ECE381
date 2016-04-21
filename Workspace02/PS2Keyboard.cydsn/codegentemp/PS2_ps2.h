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

#if !defined(PS2_H)
#define PS2_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"
    
#include "PS2_Timer.h"
#include "PS2_Timer_ISR.h"
#include "PS2_controlReg.h"
#include "PS2_dataOut.h"
#include "PS2_stateReg.h"
#include "PS2_statusReg.h"
    
#define PS2_READ           (PS2_controlReg_Write(PS2_controlReg_Read() & ~0x02))
#define PS2_WRITE          (PS2_controlReg_Write(PS2_controlReg_Read() | 0x02))
    
#define PS2_STATE          (PS2_stateReg_Read())
#define PS2_STATUS         (PS2_statusReg_Read())
#define PS2_BYTE_R         (PS2_dataOut_Read())
    
#define PS2_TIMER_RESET    (PS2_controlReg_Write(PS2_controlReg_Read() | 0x01))

#define PS2_TIMER_START(period) { PS2_counter_trigger = 0; PS2_Timer_WritePeriod(period); PS2_Timer_Start(); }

#define PS2_STATUS_PENDING     0
#define PS2_STATUS_DONE        1
#define PS2_STATUS_ERROR       2
    
#define PS2_SUCCESS            1
#define PS2_MOUSE              2
#define PS2_BAD_BAT            3
#define PS2_TIMEOUT            4
#define PS2_ERROR              5
    
extern uint8 PS2_counter_trigger;
extern uint8 PS2_initVar;
    
void PS2_Init(void) ;
void PS2_Start(void) ;
uint8 PS2_DetectDevice(void) ;

#endif /* PS2_H */

/* [] END OF FILE */
