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

#include "PS2_1_ps2.h"

uint8 PS2_1_counter_trigger;
uint8 PS2_1_initVar;

CY_ISR(PS2_1_COUNTER)
{
    PS2_1_counter_trigger = 1;    
}

void PS2_1_Init(void) 
{
    PS2_1_counter_trigger = 0; 
}

void PS2_1_Start(void) 
{
    if(0u == PS2_1_initVar)
    {
        PS2_1_Init();
        PS2_1_initVar = 1u; /* Component initialized */
    }

    //PS2_1_Enable();
    //PS2_1_EnableInt();
}

uint8 PS2_1_DetectDevice(void) 
{
    PS2_1_TIMER_START(200); // Set a timer for 1000ms
    
    PS2_1_READ; // Make sure the state machine knows to read
    
    while (PS2_1_STATUS != PS2_1_STATUS_PENDING && !PS2_1_counter_trigger); // Wait until timeout or something received
    if (PS2_1_STATUS == PS2_1_STATUS_DONE)
    {
        return 1;
    }
    else if (PS2_1_STATUS == PS2_1_STATUS_ERROR)
    {
        return 2;
    }
    else
    {
        return 3;   
    }
}

/* [] END OF FILE */
