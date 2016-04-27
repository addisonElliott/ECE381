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
#include "PS2_dataIn.h"
#include "PS2_dataOut.h"
#include "PS2_stateReg.h"
#include "PS2_statusReg.h"
    
#include "ps2_clock.h" /* This is a hack, fix it later */
#include "ps2_data.h" /* This is a hack, fix it later */

/* Macros that read/write the control and status registers */
	
/* Bit 1 in the control register is what tells the state machine whether to read(0) or write(1) */
#define PS2_READ           {PS2_controlReg_Write(PS2_controlReg_Read() & ~0x01); }
#define PS2_WRITE          {PS2_controlReg_Write(PS2_controlReg_Read() | 0x01); }
	
/* Resets the state machine to the IDLE state */
#define PS2_RESET          { PS2_controlReg_Write(PS2_controlReg_Read() | 0x02); \
                                        PS2_controlReg_Write(PS2_controlReg_Read() & ~0x02); }

/* Sets the ps2_data line on the software side. Note: This is only changed if the control is set to software and not hardware */
#define PS2_DATA_HIGH 		{PS2_controlReg_Write(PS2_controlReg_Read() | 0x04); }
#define PS2_DATA_LOW 		{PS2_controlReg_Write(PS2_controlReg_Read() & ~0x04); }

/* Sets the ps2_clock line. Note: A 1 is high-Z */
#define PS2_CLOCK_HIGH 	{PS2_controlReg_Write(PS2_controlReg_Read() | 0x08); }
#define PS2_CLOCK_LOW 		{PS2_controlReg_Write(PS2_controlReg_Read() & ~0x08); }

/* The data control bit sets whether the ps2_data output is software or hardware. Hardware refers to the verilog 
 *	module and software refers to bit 3 in this register */
#define PS2_DATA_CTRL_HW 	{PS2_controlReg_Write(PS2_controlReg_Read() | 0x10); }
#define PS2_DATA_CTRL_SW 	{PS2_controlReg_Write(PS2_controlReg_Read() & ~0x10); }

/* Returns the various register values */
#define PS2_STATUS         (PS2_statusReg_Read())
#define PS2_STATE          (PS2_stateReg_Read())
#define PS2_BYTE_R         (PS2_dataOut_Read())
#define PS2_DATA_WRITE(data) (PS2_dataIn_Write(data))
    
/* Starts the timer to run for the given period. This timer will repeat reps time. 
 * Total Amount of time waiting = 10uS * period * reps
 * Period is a byte, reps is an unsigned int
 *
 * Note: Make sure period is sufficiently large before increasing reps. This reduces the amount of latency because
 * reps triggers an ISR to decrement a counter and the period internally decrements a counter(within one clock cycle)
 * Sufficiently large means > 10 periods(A.K.A. 100uS)
 */
#define PS2_TIMER_START(period, reps) { PS2_timer_reps = reps; PS2_Timer_WriteCounter(period); \
													 PS2_Timer_WritePeriod(period); PS2_Timer_Enable(); }

/* Enumerations */
#define PS2_STATUS_PENDING     0
#define PS2_STATUS_DONE        1
#define PS2_STATUS_ERROR       2
    
#define PS2_SUCCESS			0
#define PS2_BAD_BAT			1
#define PS2_TIMEOUT			2
#define PS2_ERROR				3
#define PS2_INVALID_RESPONSE	4
    
#define PS2_IDLE               0
#define PS2_READ_BIT_1         1
#define PS2_READ_BIT_2         2
#define PS2_READ_BIT_3         3
#define PS2_READ_BIT_4         4
#define PS2_READ_BIT_5         5
#define PS2_READ_BIT_6         6
#define PS2_READ_BIT_7         7
#define PS2_READ_BIT_8         8   
#define PS2_READ_PARITY        9    
#define PS2_READ_STOP          10
#define PS2_WRITE_BIT_1        11  
#define PS2_WRITE_BIT_2        12  
#define PS2_WRITE_BIT_3        13  
#define PS2_WRITE_BIT_4        14  
#define PS2_WRITE_BIT_5        15  
#define PS2_WRITE_BIT_6        16  
#define PS2_WRITE_BIT_7        17  
#define PS2_WRITE_BIT_8        18  
#define PS2_WRITE_PARITY       19
#define PS2_WRITE_STOP         20
#define PS2_WRITE_ACK          21
#define PS2_DONE               22
#define PS2_ERROR_             23
    
/* Global variables */
extern uint16 PS2_timer_reps;
extern uint8 PS2_initVar;
extern uint8 PS2_deviceDetectFail;
    
/* Functions */
void PS2_Init(void) ;
void PS2_Start(void) ;
uint8 PS2_DetectDevice(void) ;
uint8 PS2_WriteByte(uint8 data) ;
uint8 PS2_SendCommand(uint8 data) ;
uint8 PS2_ReadByte(void) ;
uint8 PS2_cReadByte(void) ;
uint8 PS2_ClearFlags(void) ;

#endif /* PS2_H */

/* [] END OF FILE */
