//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "string.h"		// used for any of the string fcns supported by API
#include "stdio.h"		// this is used for fcns....
#include "ctype.h"		// this is used for fcns.. csspanf() and cstork()

// A compiler directive that tells the C compiler to make PSoC_GPIO_ISR_C a
// function that handles interrupts. This means it replaces ret at the end of // the function with reti. Refer to PSoC Technical Reference Manual for more
// information.
#pragma interrupt_handler PSoC_TempCounter_ISR_C
#pragma interrupt_handler PSoC_MotorDriver_ISR_C
#pragma interrupt_handler PSoC_GPIO_ISR_C

static char rubout[4] = { 0x08, 0x20, 0x08, 0x00 }; // Rubout Sequence consists of Backspace Space Backspace. This is the null-terminated string
static char slaveAddress = 0x48;		// '0'1001000 R/W shifted to front
		
char buf[80];	// String that stores the string the user enters in serial console
char strPos = 0; 	// Variable that is used for GetLine function, goes with buf
char checkTemp = TRUE; // This is a boolean that gets set when its time to get a new temperature reading
char updateLCD = TRUE; // This is a boolean that gets set when the LCD needs to be updated

char curTemp = 0; // Current temperature
char setTemp = 25; // Desired temperature
char thermostatMode = 0; // 0 = Off, 1 = Heating, 2 = Cooling
char fanMode = 1; // 0 = Manual, 1 = Automatic
char fanSpeed = 0; // 0 = Low, 1 = Medium, 2 = High

// This function get's a line of text. It writes data into buffer with a maximum size of bufferLen. The function returns number of bytes written
// when enter is pressed. Values of buffer and strPos are continuously passed to the function. The function returns TRUE if a line was received
// otherwise false if its still getting data
char GetLine(char *buffer, char *strPos, char bufferLen)
{
	char c;
	
	if ((c = UART_cReadChar()))
	{
		if (c == 0x08 || c == 0x7F) // Delete or backspace pressed
		{
			if (*strPos > 0) // Only delete if there are characters to delete
			{
				(*strPos)--; // Set the position back one
				UART_PutString(rubout); // Sends the rubout sequence to the serial.
			}
		}
		else if (c == 0x0D) // Newline enter is pressed
		{
			buffer[*strPos] = 0x00; // put the null character at the current strPos
			UART_PutCRLF(); // Go to another line
			*strPos = 0;
			return TRUE;
		}
		else if (c >= 0x20 && c < 0x7F) // only valid characters to the string. These are any alphabet, numeric, or symbols
		{
			if (*strPos < bufferLen) // If there is space in the buffer
			{
				buffer[(*strPos)++] = c; // Set the current character in buffer to c and then increment strPos
				UART_PutChar(c); // Send the character to the computer
			}
			else
				UART_PutChar(0x07); // Send BEL key because there is no more space left to add to the string
		}
	}
	
	return FALSE;
}

// Takes input argument str and converts each character into a lowercase character. Returns that str. Note: This function alters str
char *Lowercase(char *str)
{	
	int i;
	for (i = 0; str[i] != 0x00; i++) // Loop through each character
		str[i] = tolower(str[i]); // Lowercase the character
	
	return str;

}

// Analyzes each character within str to see if it contains only digits. Return true if so, else false
char IsNumber(char *str)
{
	int i;
	for (i = 0; str[i] != 0x00; i++) // Loop through each character
		if (!isdigit(str[i])) // Return false if there is a character thats NOT a digit
			return FALSE;		
		
	return TRUE; // Return true if there wasn't any characters that weren't digits
}

// Converts a certain amount of digits from value into a string. The value is unsigned, no support for negative numbers.
char *NumToStr(char *buf, unsigned int value, int digits)
{
	char start = digits - 1;
	while (digits--)
	{
		buf[start--] = (value % 10) + '0';
		value /= 10;
	}
	
	buf[start] = '\0';
	return buf;
}

// Writes a command to a device using I2C. The command character is sent first followed by len bytes. Limited to 31 bytes. Use the other
// I2C function to send more bytes. Characters to be sent should be placed after the len parameter
void WriteI2C(char slaveAddress, char cmd, int len, ...)
{
	char buf[32]; // Buffer that will contain the data t be sent
	int i;
	va_list v1;
	
	buf[0] = cmd; // First byte is the cmd character
	
	va_start(v1, len); // Variadic arguments are used to easily send bytes to a I2C device.
	for (i = 0; i < len; i++) // Get len arguments from the function
		buf[i + 1] = va_arg(v1, char); // Put argument in buf shifted by one
	va_end(v1);
	
	I2CHW_bWriteBytes(slaveAddress, buf, len + 1, I2CHW_CompleteXfer); // Write len+1 bytes from buf
	while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE)); // Wait until ACK is received
	I2CHW_ClrWrStatus(); // Clear write bit
}

// Reads from a device using I2C. The command character is written first and then len bytes are read from the device.
void ReadI2C(char slaveAddress, char cmd, int len, char *data)
{	
	I2CHW_bWriteBytes(slaveAddress, &cmd, 1, I2CHW_NoStop); // Write cmd byte
	while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE)); // Wait until ACK is received
	I2CHW_ClrWrStatus(); // Clear write bit
	
	I2CHW_fReadBytes(slaveAddress, data, len, I2CHW_CompleteXfer); // Read len bytes into data
	while (!(I2CHW_bReadI2CStatus() & I2CHW_RD_COMPLETE)); // Wait until reading is done
	I2CHW_ClrRdStatus(); // Clear read bit
}

void main(void)
{	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	M8C_EnableIntMask(INT_MSK1, INT_MSK1_DBB01); // Enable DBB01 Interrupt for TempCounter
	M8C_EnableIntMask(INT_MSK1, INT_MSK1_DBB11); // Enable DBB01 Interrupt for MotorDriver
	M8C_EnableIntMask(INT_MSK0, INT_MSK0_GPIO); // Enable GPIO interrupt for Tout
	
	// Start the UART(with no parity), LCD, TempCounter and MotorDriver
	UART_Start(UART_PARITY_NONE);
	LCD_Start();
	TempCounter_EnableInt(); // Enable interrupts for counter
	TempCounter_Start();
	MotorDriver_EnableInt(); // Enable interrupts for counter
	
	// Start I2CHW
	I2CHW_Start();
	I2CHW_EnableMstr();
	I2CHW_EnableInt();
	
	WriteI2C(slaveAddress, 0xAC, 1, 0x02);
	
	WriteI2C(slaveAddress, 0xA1, 2, 30, 0x00);
	WriteI2C(slaveAddress, 0xA2, 2, 20, 0x00);
	WriteI2C(slaveAddress, 0xEE, 0);
	
	// Writes initial string to LCD. When LCD is updated, only the numbers will be changed
	LCD_Position(0,0); LCD_PrCString("CUR: 00 OFF     ");
	LCD_Position(1,0); LCD_PrCString("SET: 00 FAN OFF ");
	
	// This is the command usage string
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
		char *params;
		
		if (GetLine(buf, &strPos, 79)) // passing ref to global char array and max length of cmd entry
		{
			
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
				int tolerance; 
			
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
				goto error;
		}
			
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
			
			NumToStr(buf, curTemp, 2);
			LCD_Position(0, 5); LCD_PrString(buf);
			
			LCD_Position(0,8);
			switch(thermostatMode)
			{
				case 0: LCD_PrCString("OFF "); break;
				case 1: LCD_PrCString("HEAT"); break;
				case 2: LCD_PrCString("COOL"); break;
			}
			
			NumToStr(buf, setTemp, 2);
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