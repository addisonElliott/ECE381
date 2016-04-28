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

#define KBD_DATA_LEN		8
#define KBD_ENDPT			1

/* Keyboard packet array:  */
uint8 keyboardPacket[KBD_DATA_LEN] = {0x20, 0x00, 0x04, 0, 0, 0, 0, 0};

int main()
{
	CyGlobalIntEnable;
	
	// Start USBFS operation with 5-V operation
	USBFS_Start(0X00, USBFS_5V_OPERATION);

	// Wait for device to enumerate
	while (!USBFS_GetConfiguration());

	while (1)
	{
		// Load in data to keyboard
		USBFS_LoadInEP(KBD_ENDPT, keyboardPacket, KBD_DATA_LEN);
		
		// Wait for an ACK
		while (!USBFS_GetEPAckState(KBD_ENDPT));
		
		CyDelay(3000);
	}
}

/* [] END OF FILE */
