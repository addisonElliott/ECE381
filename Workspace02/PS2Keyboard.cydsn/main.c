/* ========================================
 *
 * Copyright Addison Elliott, 2016
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
#include "keyboard.h"

uint8 NumLock = 0; // 0-NumLock is off, 1-NumLock is on
uint8 CapsLock = 0; // 0-CapsLock is off, 1-CapsLock is on
uint8 ScrollLock = 0; // 0-ScrollLock is off, 1-ScrollLock is on
uint8 ShiftDown = 0; // 0-No Shift keys are pressed, 1-At least one Shift key is pressed
uint8 CtrlDown = 0; // 0-No Ctrl keys are pressed, 1-At least one Ctrl key is pressed
uint8 AltDown = 0; // 0-No Alt keys are pressed, 1-At least one Alt key is pressed
uint8 PianoMode = 0; // 0-The keyboard is in regular mode, 1-The keyboard is in piano mode

int main()
{
    uint8 status;
	uint8 scancode;
	uint8 codetype;
	char c;
	
    CyGlobalIntEnable; /* Enable global interrupts. */
	
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
		
		if ((scancode = PS2_cReadByte()))
		{
			if (scancode == 0xAA) 
				continue;
			
			if (scancode == 0xFE) 
				continue;
			
			codetype = KeyboardDecodeData(scancode);
			KeyboardAction(scancode, codetype);
			c = KeyboardToASCII(scancode, codetype);
			if (c)
			{
				if (c == 0x0d)
					UART_PutString("\r\n");
				else if (c == 0x08)
				{
					// Send rubout
					UART_PutChar(0x08);
					UART_PutChar(' ');
					UART_PutChar(0x08);
				}
				else
					UART_PutChar(c);
			}
		}
		
    }
}

/* [] END OF FILE */
