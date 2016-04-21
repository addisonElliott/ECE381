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

#include "`$INSTANCE_NAME`_ps2.h"

uint8 `$INSTANCE_NAME`_counter_trigger;
uint8 `$INSTANCE_NAME`_initVar;

CY_ISR(`$INSTANCE_NAME`_TIMER)
{
    `$INSTANCE_NAME`_Timer_STATUS;
    `$INSTANCE_NAME`_counter_trigger = 1;    
    `$INSTANCE_NAME`_Timer_Stop();
}

void `$INSTANCE_NAME`_Init(void) `=ReentrantKeil($INSTANCE_NAME . "_Init")`
{
    `$INSTANCE_NAME`_counter_trigger = 0;
    `$INSTANCE_NAME`_Timer_ISR_StartEx(`$INSTANCE_NAME`_TIMER);
    `$INSTANCE_NAME`_Timer_Start();
    `$INSTANCE_NAME`_Timer_Stop();
}

void `$INSTANCE_NAME`_Start(void) `=ReentrantKeil($INSTANCE_NAME . "_Start")`
{
    if (0u == `$INSTANCE_NAME`_initVar)
    {
        `$INSTANCE_NAME`_Init();
        `$INSTANCE_NAME`_initVar = 1u; /* Component initialized */
    }
}

uint8 `$INSTANCE_NAME`_DetectDevice(void) `=ReentrantKeil($INSTANCE_NAME . "_Init")`
{
    `$INSTANCE_NAME`_TIMER_START(200); // Set a timer for 1000ms
    
    `$INSTANCE_NAME`_READ; // Make sure the state machine knows to read
    
    while (`$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_PENDING && !`$INSTANCE_NAME`_counter_trigger); // Wait until timeout or something received
    if (`$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_DONE)
    {
        CyDelay(1); // Delay one millisecond to give the status register time to update
        if (`$INSTANCE_NAME`_BYTE_R == 0xAA)
        {
            //`$INSTANCE_NAME`_TIMER_START(4); // Set a timer for 20ms; mouse sends ID packet within 20ms of BAT completion
            //`$INSTANCE_NAME`_READ; // Make sure the state machine knows to read
            
            return `$INSTANCE_NAME`_SUCCESS;
        }
        else
        {
            return `$INSTANCE_NAME`_BAD_BAT;   
        }
        return `$INSTANCE_NAME`_BYTE_R;
    }
    else if (`$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_ERROR)
    {
        return `$INSTANCE_NAME`_ERROR;
    }
    else
        return `$INSTANCE_NAME`_TIMEOUT;
}

/* [] END OF FILE */
