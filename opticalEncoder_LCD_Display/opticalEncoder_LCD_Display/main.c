//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "PSoCGPIOINT.h"	// We have to include this file manually for GPIO
#pragma interrupt_handler PSoC_GPIO_ISR_C

char state;			// zero is no change ; -1 is CCW ; 1 is CW
char prev_A;
char prev_B;
void main(void)
{
	char tempStr[4];
	unsigned int count = 50;		
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK;
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK;
	state = 0;
	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	M8C_EnableIntMask(INT_MSK0,INT_MSK0_GPIO);		// Enable Interrupt Mask
	
	LCD_Start();
	LCD_Position(1,0);
	LCD_PrCString("Volume: 50");
	while (1)
	{	
		if((state == 1 && count < 100) || (state == -1 && count > 0) )	// there was a turn
		{
			count += (state == 1 ? 1 : -1);	// the variable state updates the count
			LCD_Position(1,8);
			LCD_PrCString("   ");
			LCD_Position(1,8);
			utoa(tempStr, count, 10);
			LCD_PrString(tempStr);
			state = 0;
		}
	}
	
}

void PSoC_GPIO_ISR_C(void)
{
	char cur_B = OpEncB_Data_ADDR & OpEncB_MASK;
	// If condition true set state to clockwise else counter clockwise	
	if ( (cur_B && !prev_A) || ( !cur_B && prev_A))
		state = -1;	// CCW
	else
		state = 1;	//CW
		
	prev_A = OpEncA_Data_ADDR & OpEncA_MASK;		// update previous values to new 
	prev_B = OpEncB_Data_ADDR & OpEncB_MASK;	
}
