#include <m8c.h>        // part specific constants and macros
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "PSoCGPIOINT.h"	// We have to include this file manually for GPIO
#pragma interrupt_handler PSoC_GPIO_ISR_C // Tells compiler that PSoC_GPIO_ISR_C is an interrupt
#pragma interrupt_handler PSoC_DigBuf_ISR_C

int state;			// 0: No Change, -1: CCW Rotation, 1: CW Rotation, 2: toggle frequency range
char prev_A;		// Holds previous value of channel A
char prev_B;		// Holds previous value of channel B
void main(void)
{
	int count = 1; // Count variable
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK; // Set previous value of A to the current value
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK; // Set previous value of B to the current value
	state = 0; // Set state to No Change initially
	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	M8C_EnableIntMask(INT_MSK0,INT_MSK0_GPIO);		// Enable Interrupt Mask
	M8C_EnableIntMask(INT_MSK1, INT_MSK1_DCB02);
	OSC_GO_EN |= 0x04;
	Counter16_Start();
	
	LCD_Start();
	LCD_Position(1,0);
	LCD_PrCString("Freq: 1000.00 Hz"); // Print the initial Volume: 50 string.

	while (1)
	{	
		
		if ((state == 1 && count < 25) || (state == -1 && count > 1) || state == 2)	// There is a change and count is within range
		{
			float freq;
			char *tempStr; // pointer to memory
			char *cptr;
			unsigned int period;
			unsigned int compareValue;
			int status;
			
			if (state != 2)
				count += state;	// Update count by 1 or -1 depending on state

			freq = 3075.61f*log(count) + 100;
			period = (6000000L / freq) - 1;
			compareValue = (period + 1) >> 1;
			
			Counter16_Stop();
			Counter16_WritePeriod(period);
			Counter16_WriteCompareValue(compareValue);
			Counter16_Start();
			
			LCD_Position(1,6);
			LCD_PrCString("        "); // Clear out the old decimal value(in case it goes from 3 digits to 2 digits)
			LCD_Position(1,6);
			
			if (OSC_CR3 == 39)
				freq /= 10;
			tempStr = ftoa(freq, &status); // Prints count in decimal value into tempStr
			for (cptr = tempStr; *cptr != 0x00; cptr++)
			{
				if (*cptr =='.')
				{
					if (*(cptr+2) == 0x00)
						*(cptr+2) = '0';
					
					*(cptr+3) = 0x00;
					break;
				}
			}
			LCD_PrString(tempStr); // Print new decimal value
			state = 0; // Set state to NoChange
		}
	}
	
}

void PSoC_GPIO_ISR_C(void)
{
	char cur_B = OpEncB_Data_ADDR & OpEncB_MASK; // current value of B
	
    state = ((cur_B >> 7) ^ (prev_A >> 6)? -1 : 1);
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK; // update previous values to new 
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK;	
}

void PSoC_DigBuf_ISR_C(void)
{
	if (OSC_CR3 == 3)
		OSC_CR3 = 39;
	else 
		OSC_CR3 = 3;
	state = 2;
}
