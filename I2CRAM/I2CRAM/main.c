//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "string.h"		// used for any of the string fcns supported by API
#include "stdio.h"		// this is used for fcns....
#include "ctype.h"		// this is used for fcns.. csspanf() and cstork()

static char rubout[4] = { 0x08, 0x20, 0x08, 0x00 }; // Rubout Sequence consists of Backspace Space Backspace. This is the null-terminated string

<<<<<<< HEAD
char buf[80];	// global array for user cmd and entry
char data[256];	// all the spots in memory
=======
char buf[80];	// String that stores the string the user enters in serial console
char data[256];	// This is the memory used to read/write to the RAM
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74

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

// This function gets a line of text. It writes data into buffer with a maximum size of bufferLen. The function returns number of bytes written
// when enter is pressed
void GetLine(char *buffer, char bufferLen)
{
	char c;
	char strPos = 0; // Current position in the string
	
<<<<<<< HEAD
	UART_PutChar('>'); // print line pointer
=======
	UART_PutChar('>'); // Print line pointer
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
	
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
			break;
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
	
	return;
}

// This takes a string that has hex such as 'A4 FF 01 04' and converts it into a string containing the hex numbers. Returns -1 if error, otherwise 
// it returns the number of bytes converted
int HexConversion(char *src, char *dst)
{
<<<<<<< HEAD
	char *str; // pointer to char array local to fcn	
    int i = 0;	// return int
    int ii = 0; // for loop indexing
	int temp;	// 
=======
	char *str;	
    int bytesParsed = 0;
    int ii = 0;
	int temp;
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74

    str = cstrtok(src, " "); // Finds next space and returns the word before it
    do
    {
        if (strlen(str) != 2) // If the string is not 2 bytes long, it is invalid
            return -1;

        for (ii = 0; ii < strlen(str); ++ii) // If any of the bytes are not valid hexadecimal, return error
            if (!isxdigit(str[ii]))
                return -1;

        csscanf(str, "%x", &temp); // Take the string and read a hexadecimal integer from it
		dst[bytesParsed++] = temp; // Convert the integer into a char and put it into dst. Increment i to go to next position in dst
        str = cstrtok(0x00, " "); // Sets str to be the next word in src. 0x00 means it will continue where it left off last
    } while (str != 0x00); // Continue while there are more strings to be parsed

    return bytesParsed; // Returns the number of bytes that were read
}

// Takes input argument str and converts each character into a lowercase character. Returns that str. Note: This function alters str
char *Lowercase(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; ++i) // Loop through each character in str and call tolower on it
		str[i] = tolower(str[i]); // Set the character to be the lowercase of the character
	
	return str; // Return the string
}

void main(void)
{	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
<<<<<<< HEAD
	// User Interface
=======
	
	// Start the UART(with no parity), and Counter16
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
	UART_Start(UART_PARITY_NONE);
	// clock for moving serial
	Counter16_Start();
<<<<<<< HEAD
	// used to debug
	LCD_Start();
	// initialize and enable the I2C module
	I2CHW_Start();
	I2CHW_EnableMstr();
	I2CHW_EnableInt();
// user guide for cmd window
=======
	
	// Start I2CHW
	I2CHW_Start();
	I2CHW_EnableMstr();
	I2CHW_EnableInt();
	
	// This is the command usage string
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
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
<<<<<<< HEAD
		char *params;	// most widely buffer
		char slaveAddress = 0x50;		// 01010000'0' R/W shifted to front
		
		GetLine(buf, 79); // passing ref to global char array and max length of cmd entry
							// return value not used
		memset(data, 0x00, 256);	// initialize all the set {data} to zero
		cmd = Lowercase(cstrtok(buf, " "));
		// WRITE
		if (strlen(cmd) == 1 && cmd[0] == 'w')
=======
		char *params;
		char slaveAddress = 0x50;		// 010100000 R/W shifted to front
		
		GetLine(buf, 79); // Retrieves a line with a maximum length of 70 characters and put it in buf.
		
		memset(data, 0x00, 256);	// Initialize all the set {data} to NULL bytes
		cmd = Lowercase(cstrtok(buf, " ")); // Get the first word from the entered string and lowercase it.
		if (strlen(cmd) == 1 && cmd[0] == 'w') // If the command is one letter and it is w, then write command
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
		{	
			int groupAddress; // only 1 and 2 actually go to SRAM
			int memLoc;
			char dataType;
			
			int len;
			
<<<<<<< HEAD
			params = cstrtok(0x00, " ");  // this statement begins in buf where previous delimiter left off
											// after getting the cmd from buf. it goes to next space delimiter
			
			// csscanf() used to assign initialize groupAdress, memLoc, and dataType.  also makes for easy length validation
			// condtion to test the 0 or 1 int representation of the group address
				// csscanf(const * char, %interrpret read type as, store in location) returns an integer
			if (strlen(params) != 1 || csscanf(params, "%d", &groupAddress) != 1) goto error;
			
			params = cstrtok(0x00, " "); // get memLoc could be 00 to FF ( Mem(0) to Mem(255))
=======
			params = cstrtok(0x00, " ");  // 0x00 indicates it will continue from last cstrtok command and get next word. This gets the next parameter
			
			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %d gets an integer, this is the groupAddress
			if (strlen(params) != 1 || csscanf(params, "%d", &groupAddress) != 1) goto error;
			
			// %x gets a hexadecimal value, this can read capital or lowercase letters, this is the memory location
			params = cstrtok(0x00, " ");
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
			if (strlen(params) != 2 || csscanf(params, "%x", &memLoc) != 1) goto error;
			
			// %c gets a character, the data type character
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%c", &dataType) != 1) goto error;
<<<<<<< HEAD
			// after ascii or hex selection read the rest until null ( note new delimiter)
			params = cstrtok(0x00, "\0");
			if (strlen(params) == 0 || params == 0x00) goto error;	// the set up command but didn't put anything in to write
=======
			
			// This reads the rest of the string and stores it in params. 
			// If the length is zero or if cstrtok returns 0, this means that there was no valid string/hex entered
			params = cstrtok(0x00, "\0");
			if (strlen(params) == 0 || params == 0x00) goto error;	// They did all the params but didn't write anything
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
			
			dataType = tolower(dataType); // Lowercase the data type
			if (groupAddress < 0 || groupAddress > 7)
<<<<<<< HEAD
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
=======
				goto error; // groupAddress was not in range
			
			data[0] = memLoc;	// First byte needs to be the memory location according to PCF8570 datasheet
			slaveAddress |= groupAddress;	// ORs the group 2 address to the group 1 address to get slaveAddress
			
			if (dataType == 'a') // If the data type is ASCII
			{
				strcpy((data + 1), params); // Copy the string from params and put it right after the data[0] byte
				len = strlen((data + 1)) + 1; // len is the number of bytes to write, it is the length of the string and then +1 because of the memLoc byte
				// Cant just do strlen(data) because data[0] could be 0x00 and it would return 0 as the string length
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
			}
			else if (dataType == 'h') // If the data type is hex
			{
				// Take ASCII encoded hex data params and put it after data[0], returns number of bytes converted
				if ((len = HexConversion(params, (data + 1))) == -1)
					goto error;
				len++; // Add one to the length because of the memLoc byte at data[0]
			}
			else
				goto error;
			
<<<<<<< HEAD
			I2CHW_bWriteBytes(slaveAddress, data, len, I2CHW_CompleteXfer); // Write it using Master Fcn 
			while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE));
			I2CHW_ClrWrStatus();
=======
			I2CHW_bWriteBytes(slaveAddress, data, len, I2CHW_CompleteXfer); // Write len bytes from data 
			while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE)); // Wait while it is writing
			I2CHW_ClrWrStatus(); // Clear the write bit
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
			
			csprintf(data, "%x bytes were written", len); // csprintf takes the string and substitutes %x for len, puts into data str
			UART_PutString(data); // Print the string to UART
			UART_PutCRLF();
		}
<<<<<<< HEAD
		// READ
		else if (strlen(cmd) == 1 && cmd[0] == 'r')
=======
		else if (strlen(cmd) == 1 && cmd[0] == 'r') // If the command is one letter and it is r, then read command
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
		{
			int groupAddress;
			int memLoc;
			char dataType;
			int numBytes;
			
			char hexStr[4];
			int i;

			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %d gets an integer, this is the groupAddress
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%d", &groupAddress) != 1) goto error;
	
			// %x gets a hexadecimal value, this can read capital or lowercase letters, this is the memory location
			params = cstrtok(0x00, " ");
			if (strlen(params) != 2 || csscanf(params, "%x", &memLoc) != 1) goto error;
			
			// %c gets a character, the data type character
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%c", &dataType) != 1) goto error;
			
			// %x gets a hexadecimal value, number of bytes to read
			params = cstrtok(0x00, " ");
			if (strlen(params) != 2 || csscanf(params, "%x", &numBytes) != 1) goto error;
			
			// If there is any data after the number of bytes, then the format is invalid and it should return an error
			if (cstrtok(0x00, " ") != 0x00) goto error;
			
			dataType = tolower(dataType); // Lowercase the data type
			if (groupAddress < 0 || groupAddress > 7)
				goto error; // groupAddress was not in range
			
			data[0] = memLoc;	// First byte needs to be the memory location according to PCF8570 datasheet
			slaveAddress |= groupAddress;	// ORs the group 2 address to the group 1 address to get slaveAddress
			
			I2CHW_bWriteBytes(slaveAddress, data, 1, I2CHW_NoStop); // Write one byte to the RAM, the slaveAddress so it knows who were talking to
			while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE)); // Wait while it is writing
			I2CHW_ClrWrStatus(); // Clear the write bit
			
<<<<<<< HEAD
			I2CHW_fReadBytes(slaveAddress, data, numBytes, I2CHW_CompleteXfer);
			while(!(I2CHW_bReadI2CStatus() & I2CHW_RD_COMPLETE));
			I2CHW_ClrRdStatus();
=======
			I2CHW_fReadBytes(slaveAddress, data, numBytes, I2CHW_CompleteXfer); // Read numBytes from the RAM, put it in data
			while(!(I2CHW_bReadI2CStatus() & I2CHW_RD_COMPLETE)); // Wait while it is reading
			I2CHW_ClrRdStatus(); // Clear the read bit
>>>>>>> 21a856d801c96e893b6826c649e5dbeaefdaaa74
			
			if (dataType == 'a') // If the data type is ASCII
			{
				for (i = 0; i < numBytes; ++i) // Loop through each byte
					UART_PutChar(data[i]); // Put the character in PuTTy
				UART_PutCRLF();
			}
			else if (dataType == 'h') // If the data type is Hex
			{
				for (i = 0; i < numBytes; ++i) // Loop through each byte
				{
					csprintf(hexStr, "%X ", data[i]); // csprintf prints into hexStr a hexadecimal with a space
					UART_PutString(hexStr); // Print hexStr
				}
				UART_PutCRLF();
			}
			else
				goto error;
		}
		else 
			goto error;
		
		continue; // This is so that the error is skipped when everything goes right
		error: // This outputs an invalid format message and continues on to read another line
			UART_CPutString("Invalid format entered. Valid formats are:\r\n\tW [GroupAddress] [MemoryLocation] [h|a] Hex/ASCII\r\n\tR [GroupAddress] [MemoryLocation] [h|a] [NumBytes]\r\n");
	}
}
