#include <m8c.h>        	// part specific constants and macros
#include "math.h"			// Needed for log function
#include "stdlib.h" 		// Needed for ftoa
#include "PSoCAPI.h" 		// PSoC API definitions for all User Modules
#include "PSoCGPIOINT.h" 	// We have to include this file manually for GPIO
#pragma interrupt_handler PSoC_GPIO_ISR_C 		// Tells compiler that PSoC_GPIO_ISR_C is an interrupt
#pragma interrupt_handler PSoC_DigBuf_ISR_C		// Tells compiler that PSoC_DigBuf_ISR_C is an interrupt

int state;			// 0: No Change, -1: CCW Rotation, 1: CW Rotation, 2: Toggle Frequency Range
char prev_A;		// Holds previous value of channel A
char prev_B;		// Holds previous value of channel B
void main(void)
{
	int count = 1; 								// Count variable
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK; 	// Set previous value of A to the current value
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK; 	// Set previous value of B to the current value
	state = 0; 									// Set state to No Change initially
	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	M8C_EnableIntMask(INT_MSK0,INT_MSK0_GPIO);		// Enable Interrupt Mask for GPIO
	M8C_EnableIntMask(INT_MSK1, INT_MSK1_DCB02);	// Enable Interrupt Mask for DCB02(where DigBuf is located)
	OSC_GO_EN |= 0x04;								// This outputs SysClk to GOE[2] bus line
	Counter16_Start();								// Start the counter
	
	// Start the LCD and set the initial string to "Freq: 1000.00 Hz"
	LCD_Start();
	LCD_Position(1,0);
	LCD_PrCString("Freq: 1000.00 Hz"); // Print the initial Volume: 50 string.
	while (1)
	{	
		if ((state == 1 && count < 25) || (state == -1 && count > 1) || state == 2) // If state has changed and the count is within range if it is incrementing/decrementing
		{
			float freq;					// Stores frequency value
			char *tempStr;				// Points to float string
			char *cptr;					// Variable we use to loop through tempStr
			unsigned int period;		// Period Value
			unsigned int compareValue;	// Compare Value
			int status;					// Unneeded variable to satisfy ftoa
			
			if (state != 2) 		// State 2 is to just update the LCD without changing count
				count += state;		// Update count by 1 or -1 depending on state

			if (OSC_CR3 == 39)
				freq = 39.60f * count + 10;
			else
			{
				if (count <= 5)
					freq = 980.0f * (count - 1) + 100;
				else
					freq = 3075.61f * log(count) + 100;	
			}
			period = (6000000L / freq) - 1;	  // Equation for period value. See report for more information
			compareValue = (period + 1) >> 1; // Equation for compare value. See report for more information
			
			// Stop timer, write new period & compare value, then start it again.
			Counter16_Stop();
			Counter16_WritePeriod(period);
			Counter16_WriteCompareValue(compareValue);
			Counter16_Start();
			
			// Clears out the old integer value in case there is a digit change
			LCD_Position(1,6);
			LCD_PrCString("        ");
			LCD_Position(1,6);
			
			if (OSC_CR3 == 39)
				freq /= 10;					// If the divider is 40, then divide the frequency by 10. Only does this for the string.
			tempStr = ftoa(freq, &status); 	// Prints freq into tempStr
			// This rounds and truncates the tempStr
			for (cptr = tempStr; *cptr != 0x00; cptr++)
			{
				if (*cptr == '.')			// If the character is a period
				{
					if (*(cptr+2) == 0x00)	// If the number is only one decimal place, fill the hundredths spot with a 0
						*(cptr+2) = '0';
					
					*(cptr+3) = 0x00;		// Make the third digit after period to be a NUL byte. This effectively rounds to hundredths position
					break;
				}
			}
			LCD_PrString(tempStr); // Print float value
			state = 0; // Set state to NoChange
		}
	}
	
}

void PSoC_GPIO_ISR_C(void)
{
	char cur_B = OpEncB_Data_ADDR & OpEncB_MASK; // current value of B
	
    state = ((cur_B >> 7) ^ (prev_A >> 6)? -1 : 1); // See report for more information where this comes from
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK; // Update previous values to new 
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK;	
}

void PSoC_DigBuf_ISR_C(void)
{
	// If VC3Divider is 4, set to 40 and vice versa. This is indexed, so it's actually 1 minus the divider. That's where 3 & 39 come from
	if (OSC_CR3 == 3)
		OSC_CR3 = 39;
	else 
		OSC_CR3 = 3;
	state = 2; // Sets state to Toggle Frequency Change. This basically updates the LCD to reflect the frequency change
}
