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
#include <project.h>
#include <stdlib.h>

int main()
{
    uint8 value;
    char valStr[10];
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    PS2_Start();
    
    for(;;)
    {
        UART_PutString("before\r\n");
        value = PS2_DetectDevice();
        itoa(value, valStr, 10);
        UART_PutString(valStr);
        UART_PutString("\r\n");
    }
}

/* [] END OF FILE */
