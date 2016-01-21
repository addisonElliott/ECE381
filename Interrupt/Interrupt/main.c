#include <m8c.h>			// part specific constants and macros
#include "PSoCAPI.h"		// PSoC API definitions for all User Modules
#include "PSoCGPIOINT.h"	// We have to include this file manually for GPIO

// A compiler directive that tells the C compiler to make PSoC_GPIO_ISR_C a
// function that handles interrupts. This means it replaces ret at the end of // the function with reti. Refer to PSoC Technical Reference Manual for more
// information.
#pragma interrupt_handler PSoC_GPIO_ISR_C

void main(void)
{
	// Enable Global interrupts (see m8c.h)
	M8C_EnableGInt;
	// Enable GPIO Interrupts (see m8c.h)
	M8C_EnableIntMask(INT_MSK0,INT_MSK0_GPIO);
	
	// Spin here forever
	while(1);
}

// The interrupt vector for GPIO interrupts is usually handled in assembly
// by function PSoC_GPIO_ISR located in PSoCGPIOINT.asm. Since we changed the // corresponding line in boot.asm, this function is called instead.
// Note: This C function is only called when a GPIO interrupt is received
// and when this C-function is finished it will return-from-interrupt (reti).
void PSoC_GPIO_ISR_C(void)
{
	// Toggle LED1
	LED1_Data_ADDR ^= LED1_MASK;
}