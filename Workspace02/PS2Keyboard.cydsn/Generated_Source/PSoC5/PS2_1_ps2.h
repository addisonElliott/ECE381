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

#if !defined(PS2_1_H)
#define PS2_1_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"
    
#include "PS2_1_Counter.h"
#include "PS2_1_controlReg.h"
#include "PS2_1_stateReg.h"
#include "PS2_1_statusReg.h"
    
#define PS2_1_READ           (PS2_1_controlReg_Write(PS2_1_controlReg_Read() & ~0x02))
#define PS2_1_WRITE          (PS2_1_controlReg_Write(PS2_1_controlReg_Read() | 0x02))
    
#define PS2_1_STATE          (PS2_1_stateReg_Read())
#define PS2_1_STATUS          (PS2_1_statusReg_Read())
#define PS2_1_BYTE_R          (PS2_1_dataOut_Read())

#define PS2_1_TIMER_START(period) { PS2_1_counter_trigger = 0; PS2_1_Counter_WritePeriod(period); PS2_1_Counter_Start(); }

#define PS2_1_STATUS_PENDING     0
#define PS2_1_STATUS_DONE        1
#define PS2_1_STATUS_ERROR       2
    
extern uint8 PS2_1_counter_trigger;
extern uint8 PS2_1_initVar;
    
void PS2_1_Init(void) ;
void PS2_1_Start(void) ;
uint8 PS2_1_DetectDevice(void) ;

#endif /* PS2_1_H */

/* [] END OF FILE */
