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
		if (SW1_Data_ADDR & SW1_MASK)
		{
			if (sw1On == FALSE)
			{
				sw1On = TRUE;
				LED1_Data_ADDR ^= LED1_MASK;
			}
		}
		else
			sw1On = FALSE;
		
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
