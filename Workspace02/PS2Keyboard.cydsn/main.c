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
    uint8 status;
	uint8 byte;
	char test[10];
	uint8 cont;
	
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    PS2_Start();
	
	// Loop here until we detect a working PS/2 device
	while (1)
	{
		status = PS2_DetectDevice();
		if (status == PS2_SUCCESS)
		{
			UART_PutString("Keyboard Ready\r\n");
			break;
		}
		else if (status == PS2_BAD_BAT)
			UART_PutString("Device BAT Error\r\n");
		else if (status == PS2_ERROR)
			UART_PutString("Device Error\r\n");
		else
			UART_PutString("No Device\r\n");
			
		// If we had an error, wait 1 second and try again
		CyDelay(1000);
	}
	
	// Keyboard Main Loop
    while (1)
    {
		if (PS2_STATUS == PS2_STATUS_ERROR) // Error is most likely set because of bad parity, transmit a resend command
		{
			PS2_RESET; // Reset the state machine
			PS2_WriteByte(0xFE); // 0xFE is a RESEND command
		}
		
		if ((byte = PS2_cReadByte()))
		{
			// Useful stuff
			itoa(byte, test, 10);
			UART_PutString("Byte: ");
			UART_PutString(test);
			UART_PutString("\r\n");
		}
    }
}

/* [] END OF FILE */
