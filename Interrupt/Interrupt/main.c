//----------------------------------------------------------------------------
//
// Project: Simple GPIO Interrupt
//
// File: main.c
//
// Description: This PSoC project configures Port1[0] as an output to drive
//   an LED and configures Port1[4] as an input that generates an interrupt
//   on the rising edge. At each interrupt Port1[0] is toggled, thereby turning
//   the LED on/off with each switch press.
//
// Ports:
//   Port1[0]: Name=LED, Drive=Strong
//   Port1[4]: Name=SWITCH, Drive=High Z, Interrupt=RisingEdge
//
// Author: Dr. Brad Noble
// Date: 1-Sep-2009
//
// Edited: Matthew Clark
// Date: 29-July-2010
// 
//----------------------------------------------------------------------------

#include <m8c.h>			// part specific constants and macros
#include "PSoCAPI.h"		// PSoC API definitions for all User Modules
#include "PSoCGPIOINT.h"	// We have to include this file manually for GPIO

// A compiler directive that tells the C compiler to make PSoC_GPIO_ISR_C a
// function that handles interrupts. This means it replaces ret at the end of // the function with reti. Refer to PSoC Technical Reference Manual for more
// information.
#pragma interrupt_handler PSoC_GPIO_ISR_C

void main(void)
{
	int test = LED1_Data_ADDR & LED1_MASK;
	int test2;
	
	// Enable global interrupts (see m8c.h)
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