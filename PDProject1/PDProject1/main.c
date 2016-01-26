#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "PSoCGPIOINT.h"	// We have to include this file manually for GPIO
#pragma interrupt_handler PSoC_GPIO_ISR_C // Tells compiler that PSoC_GPIO_ISR_C is an interrupt

char state;			// 0: No Change, -1: CCW Rotation, 1: CW Rotation
char prev_A;		// Holds previous value of channel A
char prev_B;		// Holds previous value of channel B
void main(void)
{
	char tempStr[4]; // Temporary string buffer for the decimal string
	unsigned int count = 50; // Count variable
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK; // Set previous value of A to the current value
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK; // Set previous value of B to the current value
	state = 0; // Set state to No Change initially
	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	M8C_EnableIntMask(INT_MSK0,INT_MSK0_GPIO);		// Enable Interrupt Mask
	
	LCD_Start();
	LCD_Position(1,0);
	LCD_PrCString("Volume: 50"); // Print the initial Volume: 50 string.
	while (1)
	{	
		if((state == 1 && count < 100) || (state == -1 && count > 0) )	// There is a change and count is within range
		{
			count += (state == 1 ? 1 : -1);	// Update count by 1 or -1 depending on state
			LCD_Position(1,8);
			LCD_PrCString("   "); // Clear out the old decimal value(in case it goes from 3 digits to 2 digits)
			LCD_Position(1,8);
			utoa(tempStr, count, 10); // Prints count in decimal value into tempStr
			LCD_PrString(tempStr); // Print new decimal value
			state = 0; // Set state to NoChange
		}
	}
	
}

void PSoC_GPIO_ISR_C(void)
{
	char cur_B = OpEncB_Data_ADDR & OpEncB_MASK; // current value of B
	if ( (cur_B && !prev_A) || ( !cur_B && prev_A)) // If this is true, then it is being turned counter clockwise. Refer to K-map to see where equation came from
		state = -1;	// CCW
	else
		state = 1;	//CW
		
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK; // update previous values to new 
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK;	
}
