//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules


void main(void)
{
	// M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	// Insert your main routine code here.
	char count = 0;
	unsigned int i = 0;
	
	while (TRUE)
	{
		LED1_Data_ADDR = count;	
		
		for (i = 0; i < 2500; ++i);
		count++;
	}
}
