//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "string.h"		// used for any of the string fcns supported by API
#include "stdio.h"		// this is used for fcns....
#include "ctype.h"		// this is used for fcns.. csspanf() and cstork()

#pragma interrupt_handler PSoC_TempCounter_ISR_C
#pragma interrupt_handler PSoC_MotorDriver_ISR_C
#pragma interrupt_handler PSoC_GPIO_ISR_C

static char rubout[4] = { 0x08, 0x20, 0x08, 0x00 }; // Rubout Sequence consists of Backspace Space Backspace. This is the null-terminated string
static char slaveAddress = 0x48;		// 01010000'0' R/W shifted to front
		
char checkTemp = TRUE;
char updateLCD = TRUE;
char curTemp;
char setTemp = 25;
char fanMode = 1; // zero = manual, one = automatic
char fanSpeed = 0; // zero = low, one = medium, two = high
char thermostatMode = 0; // zero = off, one = heat, two = cool

char buf[80];	// global array for user cmd and entry

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

char *Lowercase(char * str)
{	
	int i;
	for (i = 0; str[i] != 0x00; i++)
		str[i] = tolower(str[i]);
	
	return str;

}

char IsNumber(char * str)
{
	int i;
	for (i = 0; str[i] != 0x00; i++)
		if (!isdigit(str[i]))
			return FALSE;		
		
	return TRUE;
}

void WriteI2C(char slaveAddress, char cmd, int len, ...)
{
	char buf[32];
	int i;
	va_list v1;
	
	buf[0] = cmd;
	
	va_start(v1, len);
	for (i = 0; i < len; i++)
		buf[i + 1] = va_arg(v1, char);
	va_end(v1);
	
	I2CHW_bWriteBytes(slaveAddress, buf, len + 1, I2CHW_CompleteXfer);
	while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE));
	I2CHW_ClrWrStatus();
}

void ReadI2C(char slaveAddress, char cmd, int len, char *data)
{	
	I2CHW_bWriteBytes(slaveAddress, &cmd, 1, I2CHW_NoStop);
	while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE));
	I2CHW_ClrWrStatus();
	
	I2CHW_fReadBytes(slaveAddress, data, len, I2CHW_CompleteXfer);
	while (!(I2CHW_bReadI2CStatus() & I2CHW_RD_COMPLETE));
	I2CHW_ClrRdStatus();
}
// This takes a string that has hex such as 'A4 FF 01 04' and converts it into a string containing the hex files. Returns -1 if error, otherwise it returns
// the number of bytes converted

void main(void)
{	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	M8C_EnableIntMask(INT_MSK1, INT_MSK1_DBB01);
	M8C_EnableIntMask(INT_MSK1, INT_MSK1_DBB11);
	M8C_EnableIntMask(INT_MSK0, INT_MSK0_GPIO);
	
	UART_Start(UART_PARITY_NONE);
	// clock for moving serial
	TempCounter_EnableInt();
	TempCounter_Start();
	MotorDriver_EnableInt();
	
	// used to debug
	LCD_Start();
	// initialize and enable the I2C module
	I2CHW_Start();
	I2CHW_EnableMstr();
	I2CHW_EnableInt();
	
	WriteI2C(slaveAddress, 0xAC, 1, 0x02);
	
	WriteI2C(slaveAddress, 0xA1, 2, 30, 0x00);
	WriteI2C(slaveAddress, 0xA2, 2, 20, 0x00);
	WriteI2C(slaveAddress, 0xEE, 0);
	
	LCD_Position(0,0); LCD_PrCString("CUR: 00 OFF     ");
	LCD_Position(1,0); LCD_PrCString("SET: 00 FAN OFF ");
	
// user guide for cmd window
	UART_CPutString("#################### Heating/Cooling Stepper Motors ##################\r\n\
#	S ##\r\n\
#		S - Set the desired Temperature\r\n\
#		## - Desired temperature in celsius\r\n\
#\r\n\
#	T ##\r\n\
#		T - Set the desired tolerance\r\n\
#		## - Desired tolerance in celsius\r\n\
#\r\n\
#	M X\r\n\
#		M - Change the mode of the thermostat\r\n\
#		X - C is for cool, H is for heat, F is for off\r\n\
#\r\n\
#	F X S\r\n\
#		F - Change the mode of the fan\r\n\
#		X - A is for automatic fan control, M is for always on\r\n\
#		S - Speed of the fan, H = high, M = medium, L = low\r\n\
#####################################################################\r\n");

	while (1)
	{
		char *cmd;
		char *params;	// most widely buffer
		
		/*GetLine(buf, 79); // passing ref to global char array and max length of cmd entry
						
		cmd = Lowercase(cstrtok(buf, " "));
		
		if (strlen(cmd) == 1 && cmd[0] == 's')
		{	
			int temp; 
		
			params = cstrtok(0x00, " "); 							
			if (!IsNumber(params) || strlen(params) < 1 || strlen(params) > 2 || csscanf(params, "%d", &temp) != 1) goto error;
			
			if (cstrtok(0x00, " ") != 0x00) goto error;
			if ( temp > 99 || temp < 0) goto error; 
		}
		else if (strlen(cmd) == 1 && cmd[0] == 't')
		{	
			int tolerance ; 
		
			params = cstrtok(0x00, " "); 							
			if (!IsNumber(params) || strlen(params) < 1 || strlen(params) > 2 || csscanf(params, "%d", &tolerance) != 1) goto error;
			
			if (cstrtok(0x00, " ") != 0x00) goto error;
			if ( tolerance > 20 || tolerance < 2) goto error; 
		}
		else if (strlen(cmd) == 1 && cmd[0] == 'm')
		{	
			char mode;
		
			params = cstrtok(0x00, " "); 	
			
			if (strlen(params) != 1 || csscanf(params, "%c", &mode) != 1) goto error;
			if (cstrtok(0x00, " ") != 0x00) goto error;
			
			mode = tolower(mode);
		// check	
		}
		else if (strlen(cmd) == 1 && cmd[0] == 'f')
		{	
			char fanMode;
			char fanSpeed;
		
			params = cstrtok(0x00, " "); 	
			if (strlen(params) != 1 || csscanf(params, "%c", &fanMode) != 1) goto error;
			
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%c", &fanSpeed) != 1) goto error;
			if (cstrtok(0x00, " ") != 0x00) goto error;
			
			fanSpeed = tolower(fanSpeed);
			fanMode = tolower(fanMode);
			
		}
		else 
			goto error;*/
		
		if (checkTemp)
		{	
			char buf[2];
			ReadI2C(slaveAddress, 0xAA, 2, buf);
			curTemp = buf[0];
			checkTemp = FALSE;
		}
		
		if (updateLCD)
		{	
			char buf[3];
			
			csprintf(buf, "%d", curTemp);
			LCD_Position(0, 5); LCD_PrString(buf);
			
			LCD_Position(0,8);
			switch(thermostatMode)
			{
				case 0: LCD_PrCString("OFF "); break;
				case 1: LCD_PrCString("HEAT"); break;
				case 2: LCD_PrCString("COOL"); break;
			}
			
			csprintf(buf, "%d", setTemp);
			LCD_Position(1, 5); LCD_PrString(buf);
			
			LCD_Position(1,12);
			if (fanMode == 1 && thermostatMode == 0) LCD_PrCString("OFF");
			else if (fanSpeed == 0) LCD_PrCString("LOW");
			else if (fanSpeed == 1) LCD_PrCString("MED");
			else if (fanSpeed == 2) LCD_PrCString("HI ");
			updateLCD = FALSE;
		}
		
		continue;
		error:	
			UART_CPutString("# Invalid format entered. Valid formats are:\r\n\
#	S ##\r\n\
#		S - Set the desired Temperature\r\n\
#		## - Desired temperature in celsius\r\n\
#\r\n\
#	T ##\r\n\
#		T - Set the desired tolerance\r\n\
#		## - Desired tolerance in celsius\r\n\
#\r\n\
#	M X\r\n\
#		M - Change the mode of the thermostat\r\n\
#		X - C is for cool, H is for heat, F is for off\r\n\
#\r\n\
#	F X S\r\n\
#		F - Change the mode of the fan\r\n\
#		X - A is for automatic fan control, M is for always on\r\n\
#		S - Speed of the fan, H = high, M = medium, L = low\r\n\
#####################################################################\r\n");
	}
}

void PSoC_TempCounter_ISR_C(void)
{
 	checkTemp = TRUE;
	updateLCD = TRUE;
	
}

void PSoC_MotorDriver_ISR_C(void)
{

}

void PSoC_GPIO_ISR_C(void)
{

}