#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules


void main(void)
{	
	unsigned char sw1On = FALSE; // Previous value of SW1
	unsigned char sw2On = FALSE; // Previous value of SW2
	unsigned int count = 0; // Variable that stores number
	char tmpStr[4]; // Temporary string to store the decimal text
	
	LCD_Start(); // Start the LED
	LCD_Position(1, 0);
	LCD_PrCString("Count: 0"); // Display string
	
	while (1)
	{
		if (SW1_Data_ADDR & SW1_MASK) // If SW1 is on
		{
			if (sw1On == FALSE) // If previous value of SW1 was not on,
			{
				sw1On = TRUE; // Set previous value to true
				if (count != 100) // If not out of range
				{
					LCD_Position(0, 0);
					LCD_PrCString("Incrementing");
					count = count + 1;
					LCD_Position(1, 7);
					LCD_PrHexInt(count); // Display hex count
					LCD_Position(1, 12);
					LCD_PrCString("   "); // Clear the previous decimal string in case the number of digits is different
					LCD_Position(1, 12);
					utoa(tmpStr, count, 10); // Prints count as a string into tmpStr
					LCD_PrString(tmpStr); // Display the decimal count
				}
			}
		}
		else
		{
			if (sw2On == FALSE) // If both switches are not on, then clear the string in top row
			{
				LCD_Position(0, 0);
				LCD_PrCString("            ");
			}
			sw1On = FALSE;
		}
		
		if (SW2_Data_ADDR & SW2_MASK) // If SW2 is on
		{
			if (sw2On == FALSE) // If previous value of SW2 was not on,
			{
				sw2On = TRUE;	// Set previous value to true
				if (count != 0) // If not out of range
				{
					LCD_Position(0, 0);
					LCD_PrCString("Decrementing");
					count = count - 1;
					LCD_Position(1, 7);
					LCD_PrHexInt(count); // Display hex count
					LCD_Position(1, 12);
					LCD_PrCString("   "); // Clear the previous decimal string in case the number of digits is different
					LCD_Position(1, 12);
					utoa(tmpStr, count, 10); // Prints count as a string into tmpStr
					LCD_PrString(tmpStr); // Display the decimal count
				}
			}
		}
		else
		{
			if (sw1On == FALSE) // If both switches are not on, then clear the string in top row
			{
				LCD_Position(0, 0);
				LCD_PrCString("            ");
			}
			sw2On = FALSE;
		}
	}
}
