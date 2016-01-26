//----------------------------------------------------------------------------
// C main line
// This program polls two switches connected to 5V supply
// SW1 and SW2 go logic 1 if pressed and SW1 controls count up || SW2 down count
// interface count with LCD module to print hex value and decimal value
// count cannot exceed 100 or go below 0
// 
//ECE 381 spr. 16
//Authors: Elliot, Addison; Sauls, Jacob
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules


void main(void)
{	
	unsigned char sw1On = FALSE; // declare local varaibles
	unsigned char sw2On = FALSE; //	
	unsigned int count = 0;	// want to increment/ decrement and display this
	char tmpStr[4];	
	
	LCD_Start();	// start LCD module set at port 2 and disable bar graphs 
	LCD_Position(1, 0); // set inital position (2 rows 0 and 1, 16 columns 0-15)
	LCD_PrCString("Count: 0");	// display string begining at row 1 column zero
	
	// NOTE INEFFICIENCIES IN PROCESS MANAGEMENT CAPABILITIES THAT INTERUPT FUNCTIONS RESOLVE
	while (1)	// loop forever
	{
		if (SW1_Data_ADDR & SW1_MASK)	// condition zeros except at pin correspoding SW1pin & 1 == ?
		{
			if (sw1On == FALSE)	// if control variable for increment, update, print is false when sw1on pressed
			{
				sw1On = TRUE;	// set the value of sw1On to logic one
				if (count != 100) // if the count has not reached 100
				{
					LCD_Position(0, 0);	// set position to send msg to LCD
					LCD_PrCString("Incrementing");	// send the string starting at row 0 column 0
					count = count + 1; // increment the count control variable
					LCD_Position(1, 7); // set the LCD position to row 1 column 7
					LCD_PrHexInt(count);	// print the unsigned int variable count as hexidecimal
					LCD_Position(1, 12);	// set the LCDpostion to row 1 column 12
					LCD_PrCString("   ");`	// print string constant used to work out bug in up to 100 then down again
											// 990 after 100 >> wipes value by print empty constant string
					LCD_Position(1, 12);	// reposition
					utoa(tmpStr, count, 10);	// in tmpStr place unsigned int count as base 10
					LCD_PrString(tmpStr);	// print decimal representation over String constant
				}
			}
		}
		else		// SW1_Data_ADDR & mask is logic 0 sw1On is true  
		{
			if (sw2On == FALSE)// if SW2 is not also trying to update the LCD 
			{
				LCD_Position(0, 0);
				LCD_PrCString("            ");
			}
			sw1On = FALSE; // toggle sw1On for logic high P1[4] poll
		}
		
		if (SW2_Data_ADDR & SW2_MASK)// if voltage on P1[5] is high 
		{
			if (sw2On == FALSE)	//  & inc, update LCD control at low
			{
				sw2On = TRUE;	// toggle
				if (count != 0)	//check count lower limit
				{
					LCD_Position(0, 0); 	// Process LCD update for decrement
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
		else // P1[5] is not at 1 
		{
			if (sw1On == FALSE)	// and do not need to increment
			{
				LCD_Position(0, 0);	// update LCD
				LCD_PrCString("            ");
			}
			sw2On = FALSE; // toggle sw2On for next P1[5] poll
		}
	}
}
