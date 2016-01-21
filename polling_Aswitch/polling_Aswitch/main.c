//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules


void main(void)
{
	
// M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	// Insert your main routine code here.
	
	unsigned char sw1On = FALSE;
	unsigned char sw2On = FALSE;
	
	while (1)
	{
		// if switch 1 triggers logic high to P1[4]
		if (SW1_Data_ADDR & SW1_MASK)
		{
			if (sw1On == FALSE)	// if the control variable already false 
								// as would be initally
			{
				sw1On = TRUE;	// set the control variable to logic high
				LED1_Data_ADDR ^= LED1_MASK;	// set the LED1 on P1[0] to on using mask
			}
		}
		else
			sw1On = FALSE; // set the control variable to logic low
		
		if (SW2_Data_ADDR & SW2_MASK)
		{
			if (sw2On == FALSE)
			{
				sw2On = TRUE;
				LED2_Data_ADDR ^= LED2_MASK;
			}
		}
		else
			sw2On = FALSE;
	}
	
}
