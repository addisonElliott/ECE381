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
#pragma interrupt_handler PSoC_GPIO_ISR_C
#pragma interrupt_handler PSoC_TempCounter_ISR_C
#pragma interrupt_handler PSoC_MotorDriver_ISR_C

static char rubout[4] = { 0x08, 0x20, 0x08, 0x00 }; // Rubout Sequence consists of Backspace Space Backspace. This is the null-terminated string
static char stepperSequence[4] = { 0x0A, 0x06, 0x05, 0x09 }; // CW Sequence that stepper needs to run to if running. CCW is backwards
static char slaveAddress = 0x90;		// 100100000 R/W shifted to front

char buf[80];	// String that stores the string the user enters in serial console
char lcdUpdate = TRUE; // This is a boolean that gets set when the LCD needs to be updated
char checkTemp = TRUE; // This is a boolean that gets set when its time to get a new temperature reading

char curTemp = 0; // Current temperature
char setTemp = 25; // Desired temperature
char tolerance = 10; // Tolerance where the fan will turn on/off within the temperature range 
char thermostatMode = 0; // 0 = Off, 1 = Heating, 2 = Cooling
char fanMode = 1; // 0 = Manual, 1 = Automatic
char fanSpeed = 0; // 0 = Low, 1 = Medium, 2 = High
char motorStep = 0; // 0 - 3, step at which the motor is at

// This function gets a line of text. It writes data into buffer with a maximum size of bufferLen. The function returns number of bytes written
// when enter is pressed
void GetLine(char *buffer, char bufferLen)
{
	char c;
	char strPos = 0; // Current position in the string
	
	UART_PutChar('>'); // Print line pointer
	
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


// Writes a command to a device using I2C. The command character is sent first followed by the len bytes. Limited to 31 bytes. Use the other
// I2C function to send more bytes
void WriteI2C(char slaveAddress, char command, int len, ...)
{
	va_list vl;
	int i;
	char data[32];
	
	buf[0] = command;
	va_start(vl, len);
	for (i = 0; i < len; i++)
		data[i+1] = va_arg(vl, char);
	va_end(vl);
	
	I2CHW_bWriteBytes(slaveAddress, data, len+1, I2CHW_CompleteXfer); // Write len bytes from data 
	while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE)); // Wait while it is writing
	I2CHW_ClrWrStatus(); // Clear the write bit
}

void ReadI2C(char slaveAddress, char command, int len, char *data)
{
	I2CHW_bWriteBytes(slaveAddress, &command, 1, I2CHW_NoStop); // Write one byte to the RAM, the slaveAddress so it knows who were talking to
	while (!(I2CHW_bReadI2CStatus() & I2CHW_WR_COMPLETE)); // Wait while it is writing
	I2CHW_ClrWrStatus(); // Clear the write bit
		
	I2CHW_fReadBytes(slaveAddress, data, len, I2CHW_CompleteXfer); // Read numBytes from the RAM, put it in data
	while(!(I2CHW_bReadI2CStatus() & I2CHW_RD_COMPLETE)); // Wait while it is reading
	I2CHW_ClrRdStatus(); // Clear the read bit
}

// Takes input argument str and converts each character into a lowercase character. Returns that str. Note: This function alters str
char *Lowercase(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; ++i) // Loop through each character in str and call tolower on it
		str[i] = tolower(str[i]); // Set the character to be the lowercase of the character
	
	return str; // Return the string
}

char IsNumber(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; ++i)
		if (!isdigit(str[i]))
			return FALSE;
		
	return TRUE;
}

void CheckFan(void)
{
	if (thermostatMode == 0 && fanMode == 1)
		MotorDriver_Stop();
	else if (fanMode == 0)
		MotorDriver_Start();
	else if (Tout_Data_ADDR & Tout_MASK)
		MotorDriver_Start();
	else
		MotorDriver_Stop();
}

void main(void)
{	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	M8C_EnableIntMask(INT_MSK0,INT_MSK0_GPIO); // Enable GPIO interrupt for Tout
	M8C_EnableIntMask(INT_MSK1, INT_MSK1_DBB01); // Enable DBB01 Interrupt for MotorDriver
	M8C_EnableIntMask(INT_MSK1, INT_MSK1_DBB11); // Enable DBB11 Interrupt for TempCounter
	
	// Start the UART(with no parity), LCD, TempCounter and MotorDriver
	UART_Start(UART_PARITY_NONE);
	LCD_Start();
	TempCounter_EnableInt();
	TempCounter_Start();
	MotorDriver_EnableInt();
	
	// Start I2CHW
	I2CHW_Start();
	I2CHW_EnableMstr();
	I2CHW_EnableInt();
	
	WriteI2C(slaveAddress, 0xAC, 1, 0x02); // Write to Access Config
	
	WriteI2C(slaveAddress, 0xA1, 2, 30, 0x00); // Writes TH
	WriteI2C(slaveAddress, 0xA2, 2, 20, 0x00); // Writes TL
	WriteI2C(slaveAddress, 0xEE, 0); // Writes StartConvert
	
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
		
		GetLine(buf, 79); // Retrieves a line with a maximum length of 70 characters and put it in buf.
		
		cmd = Lowercase(cstrtok(buf, " ")); // Get the first word from the entered string and lowercase it.
		if (strlen(cmd) == 1 && cmd[0] == 's') // If the command is one letter and it is w, then write command
		{
			int temp;
			
			params = cstrtok(0x00, " ");  // 0x00 indicates it will continue from last cstrtok command and get next word. This gets the next parameter
			
			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %d gets an integer, this is the temperature
			if (!IsNumber(params) || strlen(params) > 3 || strlen(params) < 1 || csscanf(params, "%d", &temp) != 1) goto error;
			if (cstrtok(0x00, " ") != 0x00) goto error; // If there is any data after temp, throw an error
			
			if (temp < 0 || temp > 125)
				goto error; // temperature was not in range
			
			setTemp = temp;
			
			WriteI2C(slaveAddress, 0xA1, 2, (char)(setTemp + (tolerance / 2)), 0x00); // Writes TH
			WriteI2C(slaveAddress, 0xA2, 2, (char)(setTemp - (tolerance / 2)), 0x00); // Writes TL
			
			lcdUpdate = TRUE;
		}
		else if (strlen(cmd) == 1 && cmd[0] == 't') // If the command is one letter and it is r, then read command
		{
			int tol;
			
			params = cstrtok(0x00, " ");  // 0x00 indicates it will continue from last cstrtok command and get next word. This gets the next parameter
			
			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %d gets an integer, this is the tolerance
			if (!IsNumber(params) || strlen(params) > 3 || strlen(params) < 1 || csscanf(params, "%d", &tol) != 1) goto error;
			if (cstrtok(0x00, " ") != 0x00) goto error; // If there is any data after temp, throw an error
			
			if (tol < 0 || tol > 99)
				goto error; // tolerance was not in range
			
			tolerance = tol;

			WriteI2C(slaveAddress, 0xA1, 2, (char)(setTemp + (tolerance / 2)), 0x00); // Writes TH
			WriteI2C(slaveAddress, 0xA2, 2, (char)(setTemp - (tolerance / 2)), 0x00); // Writes TL
			
			lcdUpdate = TRUE;
		}
		else if (strlen(cmd) == 1 && cmd[0] == 'm') // If the command is one letter and it is r, then read command
		{
			char mode;

			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %c gets a character, the data type character
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%c", &mode) != 1) goto error;
			
			// If there is any data after the number of bytes, then the format is invalid and it should return an error
			if (cstrtok(0x00, " ") != 0x00) goto error;
			
			mode = tolower(mode); // Lowercase the data type
			
			switch (mode)
			{
				case 'f':
					thermostatMode = 0;
					break;
					
				case 'h':
					thermostatMode = 1;
					WriteI2C(slaveAddress, 0xAC, 1, 0x00); // Write to Access Config, sets polarity bit to active low
					break;
					
				case 'c':
					thermostatMode = 2;
					WriteI2C(slaveAddress, 0xAC, 1, 0x02); // Write to Access Config, sets polarity bit to active high
					break;
					
				default: goto error;
			}
	
			CheckFan();
			lcdUpdate = TRUE;
		}
		else if (strlen(cmd) == 1 && cmd[0] == 'f') // If the command is one letter and it is r, then read command
		{
			char mode;
			char speed;

			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %c gets a character, the data type character
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%c", &mode) != 1) goto error;
			
			// %c gets a character, the data type character
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%c", &speed) != 1) goto error;
			
			// If there is any data after the number of bytes, then the format is invalid and it should return an error
			if (cstrtok(0x00, " ") != 0x00) goto error;
			
			mode = tolower(mode); // Lowercase the mode character
			speed = tolower(speed); // Lowercase the speed character
			
			switch (mode)
			{
				case 'm': fanMode = 0; break;
				case 'a': fanMode = 1; break;
				default: goto error;
			}
			CheckFan();
			
			MotorDriver_Stop();
			switch (speed)
			{
				case 'l':
					fanSpeed = 0;
					
					MotorDriver_WritePeriod(1999);
					MotorDriver_WriteCompareValue(1000);
					break;
					
				case 'm':
					fanSpeed = 1;
					
					MotorDriver_WritePeriod(9999);
					MotorDriver_WriteCompareValue(5000);
					break;
					
				case 'h':
					fanSpeed = 2;
					
					MotorDriver_WritePeriod(49999);
					MotorDriver_WriteCompareValue(25000);
					break;
					
				default: goto error;
			}
			MotorDriver_Start();
			lcdUpdate = TRUE;
		}
		else 
			goto error;
		
		if (checkTemp)
		{
			char tempByte[2];
			
			ReadI2C(slaveAddress, 0xAA, 2, tempByte);
			curTemp = tempByte[0];
			checkTemp = FALSE;	
		}
		
		if (lcdUpdate)
		{
			char buf[17];
			__flash char *sThermMode;
			__flash char *sFanMode;
			
			switch (thermostatMode)
			{
				case 0: sThermMode = "OFF "; break;
				case 1: sThermMode = "HEAT"; break;
				case 2:	sThermMode = "COOL"; break;
			}
			
			if (fanMode == 0 || Tout_Data_ADDR & Tout_MASK)
			{
				switch (fanSpeed)
				{
					case 0: sFanMode = "LOW "; break;
					case 1: sFanMode = "MED "; break;
					case 2: sFanMode = "HIGH"; break;
				}
			}
			else 
				sFanMode = "OFF ";
			
			csprintf(buf, "CUR:%03i %s", curTemp, sThermMode);
			LCD_Position(0, 0); LCD_PrString(buf);
			
			csprintf(buf, "SET:%03i FAN %s", setTemp, sFanMode);
			LCD_Position(1, 0); LCD_PrString(buf);
			
			lcdUpdate = FALSE;
		}
		
		error: // This outputs an invalid format message and continues on to read another line
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

void PSoC_GPIO_ISR_C(void)
{
	if (fanMode == 1 && thermostatMode != 0)
	{
		if (Tout_Data_ADDR & Tout_MASK)
			MotorDriver_Start();
		else
			MotorDriver_Stop();
		lcdUpdate = TRUE;
	}
}

void PSoC_TempCounter_ISR_C(void)
{
	checkTemp = TRUE;
	lcdUpdate = TRUE;
}

void PSoC_MotorDriver_ISR_C(void)
{
	if (thermostatMode == 1) // Heating, clockwise
	{
		if (++motorStep > 3)
			motorStep = 0;
	}
	else if (thermostatMode == 2) // Cooling
	{
		if (--motorStep < 0)
			motorStep = 3;
	}
	
	Motor1_Data_ADDR = stepperSequence[motorStep];
}