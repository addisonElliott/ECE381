//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "string.h"

static char rubout[4] = { 0x08, 0x20, 0x08, 0x00 }; // Rubout Sequence consists of Backspace Space Backspace. This is the null-terminated string

char str[4][17]; // Multi-dimensional array of 4 strings with a length of 17

// This function reads characters from the serial until a character is entered that is within the min & max ASCII characters.
// That character is returned
char GetNumber(char min, char max)
{
	char c;
	
	while (1)
	{
		c = UART_cReadChar(); // Read the character
		if (c < ('0' + min) || c > ('0' + max)) // If the character is not within min to max range, continue the loop
			continue;
		
		UART_PutChar(c); // Put the character on the serial
		return (c - '0'); // This returns the integer number entered instead of the ASCII value
	}
	
	return 0;
}

// This function get's a line of text. It writes data into buffer with a maximum size of bufferLen. The function returns when enter is pressed
void GetLine(char *buffer, char bufferLen)
{
	char c;
	char strPos = 0; // Current position in the string
	
	while (1)
	{
		c = UART_cReadChar(); // Read the character
		
		if (c == 0x08 || c == 0x7F) // Delete or backspace pressed
		{
			if (strPos > 0) // Only delete if there are characters to delete
			{
				strPos--; // Set the position back one
				UART_PutString(rubout); // Sends the rubout sequence to the serial.
			}
		}
		else if (c == 0x0D) // Newline enter is pressed
		{
			buffer[strPos+1] = 0x00; // Null-terminate the string
			UART_PutCRLF(); // Go to another line
			break;
		}
		else if (c >= 0x20 && c < 0x7F) // Only echo valid characters to the string. These are any alphabet, numeric, or symbols
		{
			if (strPos < bufferLen) // If there is space in the buffer
			{
				buffer[strPos++] = c; // Set the current character in buffer to c and then increment strPos
				UART_PutChar(c); // Send the character to the computer
			}
			else
				UART_PutChar(0x07); // Send BEL key because there is no more space left to add to the string
		}
	}
	return;
}

void main(void)
{
	char opt;
	
	LCD_Start();
	UART_Start(UART_PARITY_NONE);
	Counter16_Start();
	OSC_GO_EN |= 0x40;
	
	memset(str, 17 * 4, 0x00); // Initialize all four strings to 0x00
	
	while (1)
	{
		// \r\n is a CRLF \t is a tab. This prints out prompting user what to do
		UART_CPutString("What would you like to do?\r\n\t1. Write to string\r\n\t2. Print to screen\r\n\t3. Print to LCD\r\n");
		opt = GetNumber(1, 3); // Basically retrieves which option to do
		
		UART_PutCRLF();
		switch (opt)
		{
			case 1: // Write to string option
				UART_CPutString("Which string would you like to write to: "); 
				opt = GetNumber(0, 3); // Ask which string to edit
				UART_PutCRLF();
				
				GetLine(str[opt], 16); // Allow the user to change the string
				UART_PutCRLF();
				break;
			
			case 2: // Print to screen option
				UART_CPutString("Which string would you like to print: ");
				opt = GetNumber(0, 3); // Ask which string to print
				UART_PutCRLF();
				UART_PutString(str[opt]); // Print selected string to UART
				UART_PutCRLF();
				UART_PutCRLF();
				break;
			
			case 3: // Print to LCD option
				UART_CPutString("Which string would you like to print: "); 
				opt = GetNumber(0, 3); // Ask which string to print
				UART_PutCRLF();
				
				LCD_Position(1, 0);
				LCD_PrCString("                "); // Clear out old value in LCD
				LCD_Position(1, 0);
				LCD_PrString(str[opt]); // Print selected string to LCD
				break;
		}
	}
}
