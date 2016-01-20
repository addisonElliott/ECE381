#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules


void main(void)
{
	unsigned char sw1On = FALSE; // Previous value of SW1
	unsigned char sw2On = FALSE; // Previous value of SW2
	
	while (1)
	{
		if (SW1_Data_ADDR & SW1_MASK) // If the switch is on
		{
			if (sw1On == FALSE) // If the switch wasn't on previously
			{
				sw1On = TRUE; // Set previous value to on
				LED1_Data_ADDR ^= LED1_MASK; // Toggle LED
			}
		}
		else
			sw1On = FALSE; // Switch is not on, set the previous value
		
		if (SW2_Data_ADDR & SW2_MASK)
		{
			if (sw2On == FALSE) // If the switch wasn't on previously
			{
				sw2On = TRUE; // Set the previous value to on
				LED2_Data_ADDR ^= LED2_MASK; // Toggle LED
			}
		}
		else
			sw2On = FALSE; // Switch is not on, set the previous value
	}
}
