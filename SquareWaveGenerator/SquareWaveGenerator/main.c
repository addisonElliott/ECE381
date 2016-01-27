#include <m8c.h>        // part specific constants and macros
#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "PSoCGPIOINT.h"	// We have to include this file manually for GPIO
#pragma interrupt_handler PSoC_GPIO_ISR_C // Tells compiler that PSoC_GPIO_ISR_C is an interrupt
#pragma interrupt_handler PSoC_DigBuf_ISR_C // Tells compiler that PSoc_DigBuf_ISR_C is an interrupt

int state;			// 0: No Change, -1: CCW Rotation, 1: CW Rotation 2: Frequency range was toggled
char prev_A;		// Holds previous value of channel A
char prev_B;		// Holds previous value of channel B
void main(void)
{
	int count = 1; // Count variable
	unsigned int freq;
	char *floatStr;
	int status;
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK; // Set previous value of A to the current value
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK; // Set previous value of B to the current value
	state = 0; // Set state to No Change initially
	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	M8C_EnableIntMask(INT_MSK0,INT_MSK0_GPIO);		// Enable Interrupt Mask
	M8C_EnableIntMask(INT_MSK1,INT_MSK1_DCB02);		// Enable Interrupt Mask
	OSC_GO_EN |= 0x04;
	
	/*
	The frequency range for 24MHz is 23.4Mhz minimum to 24.6Mhz maximum. This is for 5V.
	For 3.3V, the maximum frequency is 12MHz.
	*/
	
	LCD_Start();
	LCD_Position(1,0);
	LCD_PrCString("Freq: 1000Hz"); // Print the initial Frequency: 1000Hz string.
	Counter16_Start();
	while (1)
	{	
		if ((state == 1 && count < 25) || (state == -1 && count > 1) || state == 2)
		{
			float freq;
			unsigned int periodValue;
			unsigned int compareValue;
			char *floatStr;
			char tempStr[8];
			char *ptr;
			size_t floatLen;
			int status;
			
			if (state != 2)
				count += state;
			
			LCD_Position(1,6);
			LCD_PrCString("          "); // Clear out the old value in case the number of digits changes
			LCD_Position(1,6);
			
			freq = 3075.61f * log(count) + 100;
			periodValue = (6000000L / freq) - 1;
			compareValue = (periodValue + 1) / 2;
			
			Counter16_Stop();
			Counter16_WritePeriod(periodValue);
			Counter16_WriteCompareValue(compareValue);
			Counter16_Start();
			
			floatStr = ftoa(freq + 0.05, &status);
			for (ptr = floatStr; *ptr != 0x00; ++ptr)
			{
				if (*ptr == '.')
				{
					*(ptr+2) = 0x00; // Sets the point after the decimal to NUL, this terminates the string after the first decimal point
					break;
				}
			}
			LCD_PrString(floatStr); // Print new frequency value
			
			floatLen = strlen(floatStr);
			LCD_Position(1, 6 + floatLen);
			LCD_PrCString("Hz");
			
			state = 0; // Set state to NoChange
		}
	}
	
}

void PSoC_GPIO_ISR_C(void)
{
	char cur_B = OpEncB_Data_ADDR & OpEncB_MASK; // current value of cur_B 
	state = ((cur_B >> 7) ^ (prev_A >> 6) == 1 ? -1 : 1);
	
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK; // update previous values to new 
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK;	
}

void PSoC_DigBuf_ISR_C(void)
{	
	OSC_CR3 = (OSC_CR3 == 3) ? 39 : 3;
}
