//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "string.h"
#include "stdio.h"
#include "ctype.h"

static char rubout[4] = { 0x08, 0x20, 0x08, 0x00 }; // Rubout Sequence consists of Backspace Space Backspace. This is the null-terminated string

char buf[81];

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

// This function get's a line of text. It writes data into buffer with a maximum size of bufferLen. The function returns number of bytes written
// when enter is pressed
char GetLine(char *buffer, char bufferLen)
{
	char c;
	char strPos = 0; // Current position in the string
	
	UART_PutChar('>');
	
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
			buffer[strPos] = 0x00;
			UART_PutCRLF(); // Go to another line
			return strPos;
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
	
	return 0;
}

// This takes a string that has hex such as 'A4 FF 01 04' and converts it into a string containing the hex files. Returns -1 if error, otherwise it returns
// the number of bytes converted
int HexConversion(char *src, char *dst)
{
	char *str;
    int i = 0;
    int ii = 0;

    str = cstrtok(src, " ");
    do
    {
        if (strlen(str) > 2)
            return -1;

        for (ii = 0; ii < strlen(str); ++ii)
            if (!isxdigit(str[ii]))
                return -1;

        csscanf(str, "%02hhx", &dst[i++]);
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
	
	UART_Start(UART_PARITY_NONE);
	Counter16_Start();
	
	I2CHW_Start();
	I2CHW_EnableMstr();
	I2CHW_EnableInt();

	UART_CPutString("-------I2C External SRAM-------\r\n");
	while (1)
	{
		char *cmd;
		char *params;
		char slaveAddress = 0xA0;
		int strLoc = -1;
		
		GetLine(buf, 80); // Retrieves a line from UART
		
		cmd = Lowercase(cstrtok(buf, " "));
		if (strlen(cmd) == 1 && cmd[0] == 'w')
		{	
			int groupAddress;
			unsigned char memLoc;
			char dataType;
			int bytesRead;
		
			char data[80];
			int len;
			
			params = cstrtok(0x00, "\0");
			if (csscanf(params, "%i%*[ ]%02hhx%*[ ]%c%*[ ]%n", &groupAddress, &memLoc, &dataType, &strLoc) != 3 || strLoc == -1)
				goto error;
			
			dataType = tolower(dataType); // Lowercase this stuff b/c case insensitive
			if (groupAddress < 0 || groupAddress > 1)
				goto error;
			
			data[0] = memLoc;
			slaveAddress |= (groupAddress << 1);
			
			if (dataType == 'a')
			{
				strcpy(data, (params + bytesRead)); // If it wants ASCII, just copy it into src buffer
				len = strlen(data); // Length is the length of string
			}
			else if (dataType == 'h')
			{
				if ((len = HexConversion(data, (params + bytesRead + 1))) == -1) // Take hex data and convert to numbers into src + 1(src[0] has the memory loc)
					goto error;
				len++; // Add one to the length because of the memoryLocation
			}
			else
				goto error;
			
			I2CHW_bWriteBytes(slaveAddress, data, len, I2CHW_CompleteXfer); // Write it
			while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE));
			I2CHW_ClrWrStatus();
			
			csprintf(data, "%i bytes were written", len); // Look up sprintf on Google for information 
			UART_PutString(data);
			UART_PutCRLF();			
		}
		else if (strlen(cmd) == 1 && cmd[0] == 'r')
		{
			int groupAddress;
			unsigned char memLoc;
			char dataType;
			unsigned char numBytes;
			
			char data[80];
			char hexStr[4];
			int i;
			
			params = cstrtok(0x00, "\0");
			if (csscanf(params, "%i%*[ ]%02hhx%*[ ]%c%*[ ]%02hhx %n", &groupAddress, &memLoc, &dataType, &numBytes, &strLoc) != 4 || strLoc == -1 || strLoc != strlen(params))
				goto error;
			
			dataType = tolower(dataType); // Lowercase this stuff b/c case insensitive
			if (groupAddress < 0 || groupAddress > 1 || numBytes > 80)
				goto error;
			
			data[0] = memLoc;
			slaveAddress |= (groupAddress << 1);
			
			I2CHW_bWriteBytes(slaveAddress, data, 1, I2CHW_NoStop);
			while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE));
			I2CHW_ClrWrStatus();
			
			I2CHW_fReadBytes(slaveAddress, data, numBytes, I2CHW_RepStart);
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
					csprintf(hexStr, "%hhX ", data[i]);
					UART_PutString(hexStr);
				}
				UART_PutCRLF();
			}
			else
				goto error;
		}
		else 
			goto error;
		
		error:
			UART_CPutString("Invalid format entered. Valid formats are:\r\n\tW [GroupAddress] [MemoryLocation] [h|a] Hex/ASCII\r\n\tR [GroupAddress] [MemoryLocation] [h|a] [NumBytes]");
	}
}
