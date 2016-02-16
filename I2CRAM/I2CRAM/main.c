//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "string.h"		// used for any of the string fcns supported by API
#include "stdio.h"		// this is used for fcns....
#include "ctype.h"		// this is used for fcns.. csspanf() and cstork()

static char rubout[4] = { 0x08, 0x20, 0x08, 0x00 }; // Rubout Sequence consists of Backspace Space Backspace. This is the null-terminated string

char buf[80];	// global array for user cmd and entry
char data[256];	// all the spots in memory

// This function reads characters from the serial until a character is entered that is within the min & max ASCII characters.
// That character is returned
char GetNumber(char min, char max)	// gets passed
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

// This function get's a line of text. It writes data into buffer with a maximum size of bufferLen. The function returns number of bytes written
// when enter is pressed
char GetLine(char *buffer, char bufferLen)
{
	char c;
	char strPos = 0; // Current position in the string
	
	UART_PutChar('>'); // print line pointer
	
	while (1)
	{
		c = UART_cReadChar(); // Use UART module to read the character user enters
		
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
			buffer[strPos] = 0x00; // put the null character at the current strPos
			UART_PutCRLF(); // Go to another line
			return strPos;
		}
		else if (c >= 0x20 && c < 0x7F) // only valid characters to the string. These are any alphabet, numeric, or symbols
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
	
	return 0;
}

// This takes a string that has hex such as 'A4 FF 01 04' and converts it into a string containing the hex files. Returns -1 if error, otherwise it returns
// the number of bytes converted
int HexConversion(char *src, char *dst)
{
	char *str; // pointer to char array local to fcn	
    int i = 0;	// return int
    int ii = 0; // for loop indexing
	int temp;	// 

    str = cstrtok(src, " ");
    do
    {
        if (strlen(str) != 2)
            return -1;

        for (ii = 0; ii < strlen(str); ++ii)
            if (!isxdigit(str[ii]))
                return -1;

        csscanf(str, "%x", &temp);
		dst[i++] = temp;
        str = cstrtok(0x00, " ");
    } while (str != 0x00);

    return i;
}

char *Lowercase(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; ++i)
		str[i] = tolower(str[i]);
	
	return str;
}

void main(void)
{	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	// User Interface
	UART_Start(UART_PARITY_NONE);
	// clock for moving serial
	Counter16_Start();
	// used to debug
	LCD_Start();
	// initialize and enable the I2C module
	I2CHW_Start();
	I2CHW_EnableMstr();
	I2CHW_EnableInt();
// user guide for cmd window
	UART_CPutString("########################## I2C External SRAM ########################\r\n\
#	W # XX T [Data]\r\n\
#		W    - Write command\r\n\
#		#    - Group Address (0 - 7)\r\n\
#		XX   - Memory Location in hex (00 - FF)\r\n\
#		T    - Data Type, either A for ASCII or H for Hexadecimal\r\n\
#		Data - Either ASCII string or Hexadecimal separates by spaces\r\n\
#\t\t\tA - Mary had a little lamb\r\n\
#\t\t\tH - 01 FF A0 0F D8 C3\r\n\
#\r\n\
#	R # XX T NN\r\n\
#		R    - Read command\r\n\
#		#    - Group Address (0 - 7)\r\n\
#		XX   - Memory Location in hex (00 - FF)\r\n\
#		T    - Data Type, either A for ASCII or H for Hexadecimal\r\n\
#		NN	 - Number of bytes to read in hexadecimal\r\n\
#####################################################################\r\n");
	while (1)
	{
		char *cmd;
		char *params;	// most widely buffer
		char slaveAddress = 0x50;		// 01010000'0' R/W shifted to front
		
		GetLine(buf, 79); // passing ref to global char array and max length of cmd entry
							// return value not used
		memset(data, 0x00, 256);	// initialize all the set {data} to zero
		cmd = Lowercase(cstrtok(buf, " "));
		// WRITE
		if (strlen(cmd) == 1 && cmd[0] == 'w')
		{	
			int groupAddress; // only 1 and 2 actually go to SRAM
			int memLoc;
			char dataType;
			
			int len;
			
			params = cstrtok(0x00, " ");  // this statement begins in buf where previous delimiter left off
											// after getting the cmd from buf. it goes to next space delimiter
			
			// csscanf() used to assign initialize groupAdress, memLoc, and dataType.  also makes for easy length validation
			// condtion to test the 0 or 1 int representation of the group address
				// csscanf(const * char, %interrpret read type as, store in location) returns an integer
			if (strlen(params) != 1 || csscanf(params, "%d", &groupAddress) != 1) goto error;
			
			params = cstrtok(0x00, " "); // get memLoc could be 00 to FF ( Mem(0) to Mem(255))
			if (strlen(params) != 2 || csscanf(params, "%x", &memLoc) != 1) goto error;
			
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%c", &dataType) != 1) goto error;
			// after ascii or hex selection read the rest until null ( note new delimiter)
			params = cstrtok(0x00, "\0");
			if (strlen(params) == 0 || params == 0x00) goto error;	// the set up command but didn't put anything in to write
			
			dataType = tolower(dataType); // Lowercase this stuff b/c case insensitive
			if (groupAddress < 0 || groupAddress > 7)
				goto error;// groupAddress int representation is invalid
			
			data[0] = memLoc;	// begin to fill the global data[256] first byte is user hex mem entry
			
			slaveAddress |= groupAddress;	// adds group address to the slaveAddress
												// how does this work?? slaveAddress a char and groupAddress an int
			if (dataType == 'a') // check data type used to write or read
			{
				strcpy((data + 1), params); // If it wants ASCII, just copy it from params into data +1
						// data + 1 (byte after memLoc) is destination, params is source copies dataType
				len = strlen((data + 1)) + 1; // length after pointing to data plus one measure then add 1 ??
												// because memory location why is this twice????
			}
			else if (dataType == 'h')
			{
				if ((len = HexConversion(params, (data + 1))) == -1) // Take hex data and convert to numbers into src + 1(src[0] has the memory loc)
					goto error;
				len++; // Add one to the length because of the memoryLocation
			}
			else
				goto error;
			
			I2CHW_bWriteBytes(slaveAddress, data, len, I2CHW_CompleteXfer); // Write it using Master Fcn 
			while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE));
			I2CHW_ClrWrStatus();
			
			csprintf(data, "%x bytes were written", len); // Look up sprintf on Google for information 
			UART_PutString(data);
			UART_PutCRLF();
		}
		// READ
		else if (strlen(cmd) == 1 && cmd[0] == 'r')
		{
			int groupAddress;
			int memLoc;
			char dataType;
			int numBytes;
			
			char hexStr[4];
			int i;

			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%d", &groupAddress) != 1) goto error;
	
			params = cstrtok(0x00, " ");
			if (strlen(params) != 2 || csscanf(params, "%x", &memLoc) != 1) goto error;
			
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%c", &dataType) != 1) goto error;
			
			params = cstrtok(0x00, " ");
			if (strlen(params) != 2 || csscanf(params, "%x", &numBytes) != 1) goto error;
			
			if (cstrtok(0x00, " ") != 0x00) goto error;
			
			dataType = tolower(dataType); // Lowercase this stuff b/c case insensitive
			if (groupAddress < 0 || groupAddress > 7)
				goto error;
			
			data[0] = memLoc;
			slaveAddress |= groupAddress;
			
			I2CHW_bWriteBytes(slaveAddress, data, 1, I2CHW_NoStop);
			while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE));
			I2CHW_ClrWrStatus();
			
			I2CHW_fReadBytes(slaveAddress, data, numBytes, I2CHW_CompleteXfer);
			while(!(I2CHW_bReadI2CStatus() & I2CHW_RD_COMPLETE));
			I2CHW_ClrRdStatus();
			
			if (dataType == 'a')
			{
				for (i = 0; i < numBytes; ++i)
					UART_PutChar(data[i]);
				UART_PutCRLF();
			}
			else if (dataType == 'h')
			{
				for (i = 0; i < numBytes; ++i)
				{
					csprintf(hexStr, "%X ", data[i]);
					UART_PutString(hexStr);
				}
				UART_PutCRLF();
			}
			else
				goto error;
		}
		else 
			goto error;
		
		continue;
		error:
			UART_CPutString("Invalid format entered. Valid formats are:\r\n\tW [GroupAddress] [MemoryLocation] [h|a] Hex/ASCII\r\n\tR [GroupAddress] [MemoryLocation] [h|a] [NumBytes]\r\n");
	}
}
