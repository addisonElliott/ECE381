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
	unsigned int count = 0;
	char tmpStr[4];
	
	LCD_Start();
	LCD_Position(1, 0);
	LCD_PrCString("Count: 0");
	
	while (1)
	{
		if (SW1_Data_ADDR & SW1_MASK)
		{
			if (sw1On == FALSE)
			{
				sw1On = TRUE;
				if (count != 100)
				{
					LCD_Position(0, 0);
					LCD_PrCString("Incrementing");
					count = count + 1;
					LCD_Position(1, 7);
					LCD_PrHexInt(count);
					LCD_Position(1, 12);
					LCD_PrCString("   ");
					LCD_Position(1, 12);
					utoa(tmpStr, count, 10);
					LCD_PrString(tmpStr);
				}
			}
		}
		else
		{
			if (sw2On == FALSE)
			{
				LCD_Position(0, 0);
				LCD_PrCString("            ");
			}
			sw1On = FALSE;
		}
		
		if (SW2_Data_ADDR & SW2_MASK)
		{
			if (sw2On == FALSE)
			{
				sw2On = TRUE;	
				if (count != 0)
				{
					LCD_Position(0, 0);
					LCD_PrCString("Decrementing");
					count = count - 1;
					LCD_Position(1, 7);
					LCD_PrHexInt(count);
					LCD_Position(1, 12);
					LCD_PrCString("   ");
					LCD_Position(1, 12);
					utoa(tmpStr, count, 10);
					LCD_PrString(tmpStr);
				}
			}
		}
		else
		{
			if (sw1On == FALSE)
			{
				LCD_Position(0, 0);
				LCD_PrCString("            ");
			}
			sw2On = FALSE;
		}
	}
}
