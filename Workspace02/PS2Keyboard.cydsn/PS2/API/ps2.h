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
#include "`$INSTANCE_NAME`_dataIn.h"
#include "`$INSTANCE_NAME`_dataOut.h"
#include "`$INSTANCE_NAME`_stateReg.h"
#include "`$INSTANCE_NAME`_statusReg.h"
    
#include "ps2_clock.h" /* This is a hack, fix it later */
#include "ps2_data.h" /* This is a hack, fix it later */

/* Macros that read/write the control and status registers */
	
/* Bit 1 in the control register is what tells the state machine whether to read(0) or write(1) */
#define `$INSTANCE_NAME`_READ           {`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() & ~0x01); }
#define `$INSTANCE_NAME`_WRITE          {`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() | 0x01); }
	
/* Resets the state machine to the IDLE state */
#define `$INSTANCE_NAME`_RESET          { `$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() | 0x02); \
                                        `$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() & ~0x02); }

/* Sets the ps2_data line on the software side. Note: This is only changed if the control is set to software and not hardware */
#define `$INSTANCE_NAME`_DATA_HIGH 		{`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() | 0x04); }
#define `$INSTANCE_NAME`_DATA_LOW 		{`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() & ~0x04); }

/* Sets the ps2_clock line. Note: A 1 is high-Z */
#define `$INSTANCE_NAME`_CLOCK_HIGH 	{`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() | 0x08); }
#define `$INSTANCE_NAME`_CLOCK_LOW 		{`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() & ~0x08); }

/* The data control bit sets whether the ps2_data output is software or hardware. Hardware refers to the verilog 
 *	module and software refers to bit 3 in this register */
#define `$INSTANCE_NAME`_DATA_CTRL_HW 	{`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() | 0x10); }
#define `$INSTANCE_NAME`_DATA_CTRL_SW 	{`$INSTANCE_NAME`_controlReg_Write(`$INSTANCE_NAME`_controlReg_Read() & ~0x10); }

/* Returns the various register values */
#define `$INSTANCE_NAME`_STATUS         (`$INSTANCE_NAME`_statusReg_Read())
#define `$INSTANCE_NAME`_STATE          (`$INSTANCE_NAME`_stateReg_Read())
#define `$INSTANCE_NAME`_BYTE_R         (`$INSTANCE_NAME`_dataOut_Read())
#define `$INSTANCE_NAME`_DATA_WRITE(data) (`$INSTANCE_NAME`_dataIn_Write(data))
    
/* Starts the timer to run for the given period. This timer will repeat reps time. 
 * Total Amount of time waiting = 10uS * period * reps
 * Period is a byte, reps is an unsigned int
 *
 * Note: Make sure period is sufficiently large before increasing reps. This reduces the amount of latency because
 * reps triggers an ISR to decrement a counter and the period internally decrements a counter(within one clock cycle)
 * Sufficiently large means > 10 periods(A.K.A. 100uS)
 */
#define `$INSTANCE_NAME`_TIMER_START(period, reps) { `$INSTANCE_NAME`_timer_reps = reps; `$INSTANCE_NAME`_Timer_WriteCounter(period); \
													 `$INSTANCE_NAME`_Timer_WritePeriod(period); `$INSTANCE_NAME`_Timer_Enable(); }

/* Enumerations */
#define `$INSTANCE_NAME`_STATUS_PENDING     0
#define `$INSTANCE_NAME`_STATUS_DONE        1
#define `$INSTANCE_NAME`_STATUS_ERROR       2
    
#define `$INSTANCE_NAME`_SUCCESS			0
#define `$INSTANCE_NAME`_BAD_BAT			1
#define `$INSTANCE_NAME`_TIMEOUT			2
#define `$INSTANCE_NAME`_ERROR				3
#define `$INSTANCE_NAME`_INVALID_RESPONSE	4
    
#define `$INSTANCE_NAME`_IDLE               0
#define `$INSTANCE_NAME`_READ_BIT_1         1
#define `$INSTANCE_NAME`_READ_BIT_2         2
#define `$INSTANCE_NAME`_READ_BIT_3         3
#define `$INSTANCE_NAME`_READ_BIT_4         4
#define `$INSTANCE_NAME`_READ_BIT_5         5
#define `$INSTANCE_NAME`_READ_BIT_6         6
#define `$INSTANCE_NAME`_READ_BIT_7         7
#define `$INSTANCE_NAME`_READ_BIT_8         8   
#define `$INSTANCE_NAME`_READ_PARITY        9    
#define `$INSTANCE_NAME`_READ_STOP          10
#define `$INSTANCE_NAME`_WRITE_BIT_1        11  
#define `$INSTANCE_NAME`_WRITE_BIT_2        12  
#define `$INSTANCE_NAME`_WRITE_BIT_3        13  
#define `$INSTANCE_NAME`_WRITE_BIT_4        14  
#define `$INSTANCE_NAME`_WRITE_BIT_5        15  
#define `$INSTANCE_NAME`_WRITE_BIT_6        16  
#define `$INSTANCE_NAME`_WRITE_BIT_7        17  
#define `$INSTANCE_NAME`_WRITE_BIT_8        18  
#define `$INSTANCE_NAME`_WRITE_PARITY       19
#define `$INSTANCE_NAME`_WRITE_STOP         20
#define `$INSTANCE_NAME`_WRITE_ACK          21
#define `$INSTANCE_NAME`_DONE               22
#define `$INSTANCE_NAME`_ERROR_             23
    
/* Global variables */
extern uint16 `$INSTANCE_NAME`_timer_reps;
extern uint8 `$INSTANCE_NAME`_initVar;
extern uint8 `$INSTANCE_NAME`_deviceDetectFail;
    
/* Functions */
void `$INSTANCE_NAME`_Init(void) `=ReentrantKeil($INSTANCE_NAME . "_Init")`;
void `$INSTANCE_NAME`_Start(void) `=ReentrantKeil($INSTANCE_NAME . "_Start")`;
uint8 `$INSTANCE_NAME`_DetectDevice(void) `=ReentrantKeil($INSTANCE_NAME . "_DetectDevice")`;
uint8 `$INSTANCE_NAME`_WriteByte(uint8 data) `=ReentrantKeil($INSTANCE_NAME . "_WriteByte")`;
uint8 `$INSTANCE_NAME`_SendCommand(uint8 data) `=ReentrantKeil($INSTANCE_NAME . "_WriteByte")`;
uint8 `$INSTANCE_NAME`_ReadByte(void) `=ReentrantKeil($INSTANCE_NAME . "_ReadByte")`;
uint8 `$INSTANCE_NAME`_cReadByte(void) `=ReentrantKeil($INSTANCE_NAME . "_cReadByte")`;
uint8 `$INSTANCE_NAME`_ClearFlags(void) `=ReentrantKeil($INSTANCE_NAME . "_ClearFlags")`;

#endif /* `$INSTANCE_NAME`_H */

/* [] END OF FILE */
