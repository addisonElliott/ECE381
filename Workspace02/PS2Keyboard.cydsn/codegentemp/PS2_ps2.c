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

#include "PS2_ps2.h"

uint8 PS2_counter_trigger;
uint8 PS2_initVar;

CY_ISR(PS2_TIMER)
{
    PS2_Timer_STATUS;
    PS2_counter_trigger = 1;    
    PS2_Timer_Stop();
}

void PS2_Init(void) 
{
    PS2_counter_trigger = 0;
    PS2_Timer_ISR_StartEx(PS2_TIMER);
    PS2_Timer_Start();
    PS2_Timer_Stop();
}

void PS2_Start(void) 
{
    if (0u == PS2_initVar)
    {
        PS2_Init();
        PS2_initVar = 1u; /* Component initialized */
    }
}

uint8 PS2_DetectDevice(void) 
{
    PS2_TIMER_START(200); // Set a timer for 1000ms
    
    PS2_READ; // Make sure the state machine knows to read
    
    while (PS2_STATUS == PS2_STATUS_PENDING && !PS2_counter_trigger); // Wait until timeout or something received
    if (PS2_STATUS == PS2_STATUS_DONE)
    {
        CyDelay(1); // Delay one millisecond to give the status register time to update
        if (PS2_BYTE_R == 0xAA)
        {
            //PS2_TIMER_START(4); // Set a timer for 20ms; mouse sends ID packet within 20ms of BAT completion
            //PS2_READ; // Make sure the state machine knows to read
            
            return PS2_SUCCESS;
        }
        else
        {
            return PS2_BAD_BAT;   
        }
        return PS2_BYTE_R;
    }
    else if (PS2_STATUS == PS2_STATUS_ERROR)
    {
        return PS2_ERROR;
    }
    else
        return PS2_TIMEOUT;
}

/* [] END OF FILE */
