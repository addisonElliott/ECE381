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
static char motorState[4] = { 0x03, 0x06, 0x0C, 0x09 }; // Four sequences of stepper motor

char motorStep = 0; // Step at which the motor is at, valid numbers are 0-3
char buf[80];	// String that stores the string the user enters in serial console
char strPos = 0; 	// Variable that is used for GetLine function, goes with buf
char checkTemp = TRUE; // This is a boolean that gets set when its time to get a new temperature reading
char updateLCD = TRUE; // This is a boolean that gets set when the LCD needs to be updated

char curTemp = 0; // Current temperature
char setTemp = 25; // Desired temperature
char tolerance = 5; // Temperature tolerance, plus or minus this amount until Tout goes high
char thermostatMode = 0; // 0 = Off, 1 = Heating, 2 = Cooling
char fanMode = 1; // 0 = Manual, 1 = Automatic
char fanSpeed = 0; // 0 = Low, 1 = Medium, 2 = High

// This function get's a line of text. It writes data into buffer with a maximum size of bufferLen. The function returns number of bytes written
// when enter is pressed. Values of buffer and strPos are continuously passed to the function. The function returns TRUE if a line was received
// otherwise false if its still getting data
char GetLine(char *buffer, char *strPos, char bufferLen)
{
	char c;
	static char newCommand = TRUE; // Since this is static, only gets set to true once but is a global essentially
	
	if (newCommand) // If it is a new command, put a > character and set this to false
	{
		UART_PutChar('>');
		newCommand = FALSE;
	}
		
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
			newCommand = TRUE; // Next time GetLine is called, > will be outputted
			return TRUE; // This means that the program should handle the buffer
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
	
	return FALSE; // Data is not ready to be handled
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
	buf[digits] = '\0';
	while (digits--)
	{
		buf[start--] = (value % 10) + '0';
		value /= 10;
	}
	
	return buf;
}

void CheckFan(void)
{
	if (fanMode == 0 || Tout_Data_ADDR & Tout_MASK) MotorDriver_Start(); // If fanMode is manual or Tout is on, start the motor
	else MotorDriver_Stop(); // Otherwise dont start the motor
	updateLCD = TRUE; // Regardless, update the LCD in case there was a change in the motor
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
	
	WriteI2C(slaveAddress, 0xAC, 1, 0x02); // Write to access config, sets mode to cooling(POL = 1), also turns 1-SHOT off, continuous conversions
	
	WriteI2C(slaveAddress, 0xA1, 2, (setTemp + tolerance), 0x00); // Sets initial high temp to be setTemp + tolerance
	WriteI2C(slaveAddress, 0xA2, 2, (setTemp - tolerance), 0x00); // Sets initial low temp to be setTemp - tolerance
	WriteI2C(slaveAddress, 0xEE, 0); // This tells the temperature IC to start converting the temperatures
	
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
		
		if (GetLine(buf, &strPos, 79)) // Only process the data if GetLine returns true
		{
			cmd = Lowercase(cstrtok(buf, " ")); // Lowercase the first word from the inputted string
			
			if (strlen(cmd) == 1 && cmd[0] == 's') // If the person entered s
			{	
				int temp;
			
				params = cstrtok(0x00, " "); // Read next word 							
				// If next word isnt number or isnt 1 or 2 characters long, then return error
				if (!IsNumber(params) || strlen(params) < 1 || strlen(params) > 2 || csscanf(params, "%d", &temp) != 1) goto error;
				
				// If there is additional data at end of string or if number is not within 0-99, return error
				if (cstrtok(0x00, " ") != 0x00) goto error;
				if ( temp > 99 || temp < 0) goto error; 
				
				setTemp = temp;
				WriteI2C(slaveAddress, 0xA1, 2, (setTemp + tolerance), 0x00); // Sets high temp to be setTemp + tolerance
				WriteI2C(slaveAddress, 0xA2, 2, (setTemp - tolerance), 0x00); // Sets low temp to be setTemp - tolerance
				updateLCD = TRUE; // Update the LCD
			}
			else if (strlen(cmd) == 1 && cmd[0] == 't') // If the person entered t
			{	
				int tol; 
			
				params = cstrtok(0x00, " "); // Read next word					
				// If next word isnt number or isnt 1 or 2 characters long, then return error
				if (!IsNumber(params) || strlen(params) < 1 || strlen(params) > 2 || csscanf(params, "%d", &tol) != 1) goto error;
				
				// If there is additional data at end of string or if number is not within 0-10, return error
				if (cstrtok(0x00, " ") != 0x00) goto error;
				if (tol < 0 || tol > 10) goto error;
				
				tolerance = tol;
				
				WriteI2C(slaveAddress, 0xA1, 2, (setTemp + tolerance), 0x00); // Sets high temp to be setTemp + tolerance
				WriteI2C(slaveAddress, 0xA2, 2, (setTemp - tolerance), 0x00); // Sets low temp to be setTemp - tolerance
				updateLCD = TRUE; // Update the LCD
				
			}
			else if (strlen(cmd) == 1 && cmd[0] == 'm') // If the person entered m
			{	
				char mode;
			
				params = cstrtok(0x00, " "); // Read next word
				
				// If next word isnt 1 character long, return error
				if (strlen(params) != 1 || csscanf(params, "%c", &mode) != 1) goto error;
				// If there is additional data at end of string, return error
				if (cstrtok(0x00, " ") != 0x00) goto error;
				
				mode = tolower(mode); // Lowercase the character
				
				switch (mode)
				{
					case 'h':
						thermostatMode = 1; // Set mode to heating
						WriteI2C(slaveAddress,0xAC, 1, 0x00); // Change access config on DS1621 to heating(POL = 0)
						break;
						
					case 'c':
						thermostatMode = 2; // Set mode to cooling
						WriteI2C(slaveAddress, 0xAC, 1, 0x02); // Change access config on DS1621 to cooling(POL = 1)
						break;
						
					case 'f': 
						thermostatMode = 0; // Set mode to off
						break;
						
					default:
						goto error; // Invalid character entered, goto error
				}
				CheckFan(); // Check the fan to see if it should be on
			}
			else if (strlen(cmd) == 1 && cmd[0] == 'f') // If the person entered f
			{	
				char mode;
				char speed;
			
				params = cstrtok(0x00, " "); // Read next word
				// If next word isnt 1 character long, then return error
				if (strlen(params) != 1 || csscanf(params, "%c", &mode) != 1) goto error;
				
				params = cstrtok(0x00, " "); // Read next word
				// If next word isnt 1 character long, then return error
				if (strlen(params) != 1 || csscanf(params, "%c", &speed) != 1) goto error;
				// If there is additional data at end of string, return error
				if (cstrtok(0x00, " ") != 0x00) goto error;
				
				speed = tolower(speed); // Lowercase the speed and mode characters entered
				mode = tolower(mode);
				
				switch (mode)
				{
					case 'm':
						fanMode = 0; // Set fan mode to manual
						break;
						
					case 'a':
						fanMode = 1; // Set fan mode to automatic
						break;
						
					default: // Otherwise go to error
						goto error;
				}
				
				MotorDriver_Stop(); // Stop the motor to change the period values
				switch (speed)
				{
					case 'l':
						fanSpeed = 0; // Set fan speed to low
						MotorDriver_WritePeriod(49999); // See report for where these numbers came from
						MotorDriver_WriteCompareValue(25000);
						break;
						
					case 'm':
						fanSpeed = 1; // Set fan speed to medium
						MotorDriver_WritePeriod(9999); // See report for where these numbers came from
						MotorDriver_WriteCompareValue(5000);
						break;
						
					case 'h':
						fanSpeed = 2; // Set fan speed to high
						MotorDriver_WritePeriod(1999); // See report for where these numbers came from
						MotorDriver_WriteCompareValue(1000);
						break;
						
					default: // Otherwise go to error if invalid input entered
						goto error;
				}
				CheckFan(); // Check the fan to see if it should be on
			}
			else 
				goto error;
		}
			
		if (checkTemp) // Check the temperature
		{	
			char buf[2];
			
			ReadI2C(slaveAddress, 0xAA, 2, buf); // Read the temperature from IC, returns 2 bytes
			curTemp = buf[0]; // We just care about the first byte
			checkTemp = FALSE; // Turn flag off so it doesnt keep doing this
		}
		
		if (updateLCD) // Update the LCD
		{	
			char buf[3];
			
			NumToStr(buf, curTemp, 2); // Convert current temp to str
			LCD_Position(0, 5); LCD_PrString(buf); // Print it
			
			LCD_Position(0, 8);
			switch(thermostatMode) // Print thermostat mode
			{
				case 0: LCD_PrCString("OFF "); break;
				case 1: LCD_PrCString("HEAT"); break;
				case 2: LCD_PrCString("COOL"); break;
			}
			
			NumToStr(buf, setTemp, 2); // Convert set temp to str
			LCD_Position(1, 5); LCD_PrString(buf); // Print it
			
			LCD_Position(1, 12);
			if (fanMode == 1 && thermostatMode == 0) LCD_PrCString("OFF"); // Print current fan state
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
 	checkTemp = TRUE; // Check temp and update LCD when its time to check temp
	updateLCD = TRUE;
}

void PSoC_MotorDriver_ISR_C(void)
{
	if (thermostatMode == 1) // If heating, increment motorStep and set it to 0 if it overflows
	{	
		motorStep++;
		if ( motorStep > 3 || motorStep < 0)
			motorStep = 0;
	}
	else // If cooling/manual, decrement motorStep and set it to 3 if it overflows
	{	
		motorStep--;
		if (motorStep < 0 || motorStep > 3)
			motorStep = 3;
	}
	
	Motor1_Data_ADDR = motorState[motorStep]; // Set Port0 to the value of motorState at the current motorStep
}

void PSoC_GPIO_ISR_C(void)
{
	CheckFan(); // Whenever GPIO is triggered, this means Tout changed, so CheckFan
}