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
#include "cytypes.h"
#include "PS2.h"
#include "UART.h"

#define KEY_NO_ACTION 	0x00
#define KEY_MAKE 		0x01
#define KEY_BREAK 		0x02
#define KEY_E0 			0x04
#define KEY_PAUSE 		0x08
#define KEY_FAKE_SHIFT 	0x10

uint8 KeyboardDecodeData(uint8 data);
char KeyboardToASCII(uint8 scancode, uint8 codetype);
void KeyboardAction(uint8 scancode, uint8 codetype);

/* [] END OF FILE */
