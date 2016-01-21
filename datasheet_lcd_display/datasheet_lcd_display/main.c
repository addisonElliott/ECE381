//--------------------------------------------------------------------
// Sample C code for LCD
//
//  Print the string “PSoC LCD" on the top row starting at the 6th
//  location on an LCD.
// 
//--------------------------------------------------------------------
#include <m8c.h>        // part specific constants and macros  
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules 
void main(void)
{
   char theStr[] = "PSoC LCD";   // Define RAM string
   LCD_Start();                  // Initialize LCD
   LCD_Position(0,5);            // Place LCD cursor at row 0, col 5.
   LCD_PrString(theStr);         // Print "PSoC LCD" on the LCD
}

