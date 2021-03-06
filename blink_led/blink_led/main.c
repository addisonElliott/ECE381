//----------------------------------------------------------------------------
// ECE381 Fall 2009
// Lab 1a: Blink an LED
//
// Dr. Brad Noble
// 25 August 2009
//----------------------------------------------------------------------------

#include <m8c.h>		// part specific constants and macros
#include "PSoCAPI.h"		// PSoC API definitions for all User Modules
#include "PSoCGPIOINT.h"	// Include is required to refer to I/O Ports by our custom names

void main()
{
    int i;

	while(1) {
		LED1_Data_ADDR |= LED1_MASK;
		for(i=0 ; i<10000 ; i++);
		LED1_Data_ADDR &= ~LED1_MASK;
		for(i=0 ; i<10000 ; i++);
	}
}
