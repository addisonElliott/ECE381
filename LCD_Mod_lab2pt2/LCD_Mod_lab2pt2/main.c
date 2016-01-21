//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules


void main(void)
{
	// M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	// Insert your main routine code here.
	
	unsigned char sw1On = FALSE; // same variables as in polling_a_switch
	unsigned char sw2On = FALSE; 
	unsigned int count = 0;	// want to increment/ decrement and display this
	char tmpStr[4];	
	
	LCD_Start();	// start LCD module, set to port 2 
	LCD_Position(1, 0); // set inital position (2 rows 0 and 1, 16 columns 0-15)
	LCD_PrCString("Count: 0");	// display string begining at row 1 column zero
	
	while (1)	// loop forever
	{
		if (SW1_Data_ADDR & SW1_MASK)	// condition zeros except at pin correspoding sw1
		{
			if (sw1On == FALSE)	// if control variable for increment is false when sw1on pressed
			{
				sw1On = TRUE;	// set the value of sw1On to logic one
				if (count != 100) // if the count has not reached 100
				{
					LCD_Position(0, 0);	// set position to send msg to LCD
					LCD_PrCString("Incrementing");	// send the string to start at row 0 column 0
					count = count + 1; // increment the count control variable
					LCD_Position(1, 7); // set the LCD position to row 1 column 7
					LCD_PrHexInt(count);	// print the int variable count as hexidecimal
					LCD_Position(1, 12);	// set the LCDpostion to row 1 column 12
					LCD_PrCString("   ");`	// empty at row 1 colum 12
					LCD_Position(1, 12);	// same postion as before
					utoa(tmpStr, count, 10);	// in the empty string tmpStr place the base 10 # rep count
					LCD_PrString(tmpStr);	// print it at the position
				}
			}
		}
		else		// SW1_Data_ADDR & mask is logic 0  
		{
			if (sw2On == FALSE)// 
			{
				LCD_Position(0, 0);
				LCD_PrCString("            ");
			}
			sw1On = FALSE; // set the control variable sw1On to logic 0
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
