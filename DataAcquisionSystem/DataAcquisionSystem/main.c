//----------------------------------------------------------------------------
// SPI SRAM Test Program
//
// PSoC Global Resources:
//   Power Setting     5.0V/24MHz
//   CPU_Clock         SysClk/1
//   32K_Select        Internal
//   PLL_Mode          Off
//   Sleep_Timer       8_Hz
//   VC1=SysClk/N     *4
//   VC2=VC1/N        *2
//                    *VC1 makes 6MHz SPIM Clock; VC2 makes 3MHz DAC Clock
//   VC3_Source        SysClk/1
//   VC3 Divider      *52
//                    *Used to set UART baud rate to 57600
//   SysClk Source     Internal
//   SysClk*2 Disable  { Any }
//   Analog Power      { Any }
//   Ref Mux           { Any }
//   AGndBypass        { Any }
//   Op-Amp Bias       { Any }
//   A_Buff_Power      { Any }
//   SwitchModePump    OFF
//   Trip Voltage      { Any }
//   LVD ThrottleBack *Disable
//                    *When enabled, an LVD event forces the CPU Clock to SysClk/8.
//   Watchdog Enable  *{ Any }
//                    *Incautious use of the Watchdog may adversely affect timing
//
// SPIM Parameters
//   Name              SPIM
//   Clock            *VC1
//                    *6MHz = 3Mbps SPI bit rate.
//   MISO              Row_2_Input_1
//   MOSI              Row_2_Output_0
//   SClk              Row_2_Output_3
//   Interrupt Mode    TXRegEmpty
//   ClockSync         Sync to SysClk
//   InvertMISO        Normal
//
// SPIM Module Notes
//  -The 23K256 SPI SRAM has a maximum clock speed of 20MHz
//   SPIM Clock must be set to two times the desired bit rate.
//  -This uses VC1 = SysClk/4 = 6MHz, yielding a bit rate of 3Mbps.
//  -Per SPIM Module datasheet, for SPI clocks greater than 1MHz,
//   the Row Input synchronization for the MISO signal should be
//   set to Async.
//  -PSoC 5V to 23K256 3.3V translation is accomplished by setting
//   all PSoC SPIM outputs to Open Drain Low drive mode and then
//   using 470ohm pull-up resistors. For 3MHz signals, a smaller
//   value resistor must be used to allow sufficient rise-time.
//  -Pinout:
//   CS   = P12 (StdCPU:    Open Drain Low)
//   SCLK = P13 (GlobalOut: Open Drain Low)
//   MOSI = P14 (GlobalOut: Open Drain Low)
//   MISO = P15 (GlobalIn:  High Z)
//
// DAC Module Notes
//  -To maximize the output sample rate, this example operates the
//   DACs at their maximum practical speed of 3MHz which is provided
//   by VC2. The Analog Column Clock MUXs for both DAC must have
//   VC2 selected manually in the [Chip] view.
//  -DAC8_WriteStall() should be used and not DAC8_WriteBlind in
//   order to prevent output glitches during the DAC update.
//
// bnoble@siue.edu 20140320
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "stdlib.h"
#include "spi_sram.h"
#include "string.h"		// used for any of the string fcns supported by API
#include "stdio.h"		// this is used for fcns....
#include "ctype.h"		// this is used for fcns.. csspanf() and cstork()

// GPIO Defines
#define TRIGGER_HIGH	{TRIGGER_Data_ADDR |=  TRIGGER_MASK;}
#define TRIGGER_LOW		{TRIGGER_Data_ADDR &= ~TRIGGER_MASK;}

// Define Sampling Rates
#define SAMPLING_RATE_1250 149 // (150-1)
#define SAMPLING_RATE_1500 124 // (125-1)
#define SAMPLING_RATE_1875  99 // (100-1)
#define SAMPLING_RATE_2500  74 //  (75-1)
#define SAMPLING_RATE_3125  59 //  (60-1)
#define SAMPLING_RATE_3750  49 //  (50-1)
#define SAMPLING_RATE_6250  29 //  (30-1)
#define SAMPLING_RATE_7500  24 //  (25-1)
#define SAMPLING_RATE_9375  19 //  (20-1)

// DACUpdate Period = 4*DelSig_DecimationRate = 128 for DS232
#define DACUPDATE_PERIOD   127 // (128 - 1)

// Globals
BYTE DACUpdateDone = 0;	// Flag which ISR sets when its time to update the DACs with output
char buf[80];			// Buffer which the UART command line will be stored		
char chAMemBlk = -1;	// Memory block that channel B will use (-1 for none)
char chBMemBlk = -1;	// Memory block that channel B will use (-1 for none)
int triggerAddress = 0; // Address at which the trigger will be triggered

// This function gets a line of text. It writes data into buffer with a maximum size of bufferLen. The function returns number of bytes written
// when enter is pressed
void GetLine(char *buffer, char bufferLen)
{
	static char rubout[4] = { 0x08, 0x20, 0x08, 0x00 }; // Rubout Sequence consists of Backspace Space Backspace. This is the null-terminated string
	
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

// Takes input argument str and converts each character into a lowercase character. Returns that str. Note: This function alters str
char *Lowercase(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; ++i) // Loop through each character in str and call tolower on it
		str[i] = tolower(str[i]); // Set the character to be the lowercase of the character
	
	return str; // Return the string
}

// This function plays channel A and B with the data at memory blocks chAMemBlk and chBMemBlk, respectively
void PlaySamples(void)
{	
	WORD startAddrA = chAMemBlk * 0x2000; // Where the address starts for channel A
	WORD endAddrA = startAddrA + 0x2000; // Where the address ends for channel A
	WORD addrA = startAddrA; // Current address position for channel B
	
	WORD startAddrB = chBMemBlk * 0x2000; // Where the address starts for channel B
	WORD endAddrB = startAddrB + 0x2000; // Where the address ends for channel B
	WORD addrB = startAddrB; // Current address position for channel B
	
	SPIRAM_WriteStatusRegister(SPIRAM_BYTE_MODE | SPIRAM_DISABLE_HOLD); // Set SPIRAM to byte mode b/c we read one byte at a time
	DACUpdate_Start(); // Start the DACUpdate timer
	UART_CPutString("Press any key to abort\r\n");
	while (!UART_cReadChar())
	{
		//TRIGGER_Data_ADDR |= TRIGGER_MASK;	// take trigger high then low
		//TRIGGER_Data_ADDR &=  ~TRIGGER_MASK;
		
		if (DACUpdateDone) // Time to update the DACs
		{
			if (chAMemBlk != -1) // If there is a valid memory block to output
			{
				DAC8A_WriteStall(SPIRAM_ReadByte(addrA));
				if (++addrA > endAddrA) addrA = startAddrA;
			}
			
			if (chBMemBlk != -1) // If there is a valid memory block to output
			{
				DAC8B_WriteStall(SPIRAM_ReadByte(addrB));
				if (++addrB > endAddrB) addrB = startAddrB;
			}
			
			DACUpdateDone = 0; // Reset flag
		}
	}
	DACUpdate_Stop(); // Stop the timer because we're done playing
}

// Samples data from channel and puts it into memBlock. Samples 8kB worth of data at the current sampling rate
void SampleAnalog(char channel, char memBlock)
{	
	WORD startAddr = 0x2000 * memBlock; // Where the address starts for memBlock
	WORD endAddr = startAddr + 0x2000; // Where the address ends for memBlock
	WORD addr;
	BYTE i;
	char temp[128];
	
	AMUX4_InputSelect(channel == 0 ? AMUX4_PORT0_1: AMUX4_PORT0_7); // Change sample analog source channel
	SPIRAM_WriteStatusRegister(SPIRAM_SEQUENTIAL_MODE | SPIRAM_DISABLE_HOLD); // Set SPIRAM to sequential mode, we write bytes in packets of 128
	DelSig_StartAD(); // Start the analog to digital conversion in DelSig
	for (addr = startAddr; addr < endAddr; addr += 128) // Loop through startAddr-endAddr in 128 increments
	{
		for (i = 0; i < 128; i++) // Read 128 bytes from the DelSig
		{
			while (!DelSig_fIsDataAvailable());
			temp[i] = DelSig_cGetDataClearFlag();
		}
		
		SPIRAM_WriteArray(addr, temp, 128); // Write those bytes to SPIRAm
	}	
	DelSig_StopAD(); // Stop the conversions once were done sampling
}

void main(void)
{
	// Make sure nCS is high before doing anything
	nCS_HIGH;

	// Make the oscilloscope external trigger signal low. Trigger must be quickly
	// brough high-then-low when you want the oscilloscope to draw the signals
	// on DACA and DACB. Trigger (P1[1]) must be connected to the EXT TRIG input
	// on the back of the oscilloscope and the Trigger Source must be set to
	// External. The oscilloscope should also be set for Normal Mode Triggering.
	TRIGGER_LOW;

	// Enable global interrutps
	M8C_EnableGInt;

	// Start the UART
	UART_Start(UART_PARITY_NONE);
	UART_PutCRLF();

	// Start the SPIM Module
	SPIM_Start(SPIM_SPIM_MODE_0 | SPIM_SPIM_MSB_FIRST);

	// Start the DelSig custom clock source at the default sampling rate
	DelSigClock_WritePeriod(SAMPLING_RATE_1250);
	DelSigClock_WriteCompareValue(SAMPLING_RATE_1250>>1);
	DelSigClock_Start();

	// Start the analog mux and select P0[1] (Channel A) as default
	AMUX4_Start();
	AMUX4_InputSelect(AMUX4_PORT0_1);

	// Start the PGA
	PGA_Start(PGA_HIGHPOWER);

	// Start the DelSig but do not start taking samples yet.
	// Note: The DelSig PWM block output can be monitored on P1[0]. This
	// can be used to verify the sampling rate.
	DelSig_Start(DelSig_HIGHPOWER);

	// Enable interrupts on the counter that sets the DAC output rate.
	// Start the module only when actually outputting samples and
	// stop it when done. Don't forget to write the period after stoping
	// to reset the count register.
	// NOTE: You can watch this counter on P1[7] to compare desired
	// output rate with your actual output rate.
	DACUpdate_WritePeriod(DACUPDATE_PERIOD);
	DACUpdate_EnableInt();

	// Start the DACs
	DAC8A_Start(DAC8A_HIGHPOWER);
	DAC8B_Start(DAC8B_HIGHPOWER);
	
		// This is the command usage string
	UART_CPutString("########################## Lab 11 Data Acquisition System ########################\r\n\
# input X A \r\n\
#\r\n\
#	Samples input channel to memory block\r\n\
#		X - Either A/B to signify channel being altered\r\n\
#		A - Memory block(0-3) being routed\r\n\
#\r\n\
# output X A\r\n\
#	Routes output channel to read from memory block \r\n\
#		X - Either A/B to signify channel being altered\r\n\
#		A - Memory block(0-3 or -1 for none) being routed\r\n\
#\r\n\
# rate X\r\n\
#	Selects a rate to sample the channels when reading and writing\r\n\
#		X - One of the values below\r\n\
#			1. 1.25  ksps \r\n\
#			2. 1.5   ksps\r\n\
#			3. 1.87  ksps\r\n\
#			4. 2.5   ksps\r\n\
#			5. 3.125 ksps\r\n\
#			6. 3.75  ksps\r\n\
#			7. 6.25  ksps\r\n\
#			8. 7.5   ksps\r\n\
#			9. 9.37  ksps\r\n\
#\r\n\
# trigger XXX H\r\n\
#	Sets the relative address to trigger\r\n\
#		XXX - Either hex/dec for the address\r\n\
#		H - values in hexadecimal or decimal.  Range is 0-8192 for dec or 0-2000 for hex\r\n\
#\r\n\
# start\r\n\
#	Starts the output channels. They will continue to play until looped over\r\n\
#####################################################################\r\n");
	while (1)
	{
		char *cmd;
		char *params;
		
		GetLine(buf, 79); // Retrieves a line with a maximum length of 79 characters and put it in buf.
		
		cmd = Lowercase(cstrtok(buf, " ")); // Get the first word from the entered string and lowercase it.
		if (!cstrcmp("input", cmd)) // If the command input was entered
		{
			char channel;
			int memBlock;

			params = cstrtok(0x00, " "); // 0x00 indicates it will continue from last cstrtok command and get next word. This gets the next parameter

			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %c gets a character, the channel
			if (strlen(params) != 1 || csscanf(params, "%c", &channel) != 1) goto error;
			
			// %d gets an integer, this is the memory block at which to write
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%d", &memBlock) != 1) goto error;			
			
			// If there is any data after the last arg, then the format is invalid and it should return an error
			if (cstrtok(0x00, " ") != 0x00) goto error;
			
			channel = tolower(channel);
			if ((channel != 'a' && channel != 'b') || memBlock < 0 || memBlock > 3)
				goto error; // Memory block was out of range or the channel was not A or B
			
			// Sample given channel at memBlock
			SampleAnalog((channel == 'b'), (char)memBlock);
		}
		else if (!cstrcmp("output", cmd)) // If the command output was entered
		{
			char channel;
			int memBlock;

			params = cstrtok(0x00, " "); // 0x00 indicates it will continue from last cstrtok command and get next word. This gets the next parameter

			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %c gets a character, the channel
			if (strlen(params) != 1 || csscanf(params, "%c", &channel) != 1) goto error;

			// %d gets an integer, this is the memory block
			params = cstrtok(0x00, " ");
			if (strlen(params) != 1 || csscanf(params, "%d", &memBlock) != 1) goto error;
			
			// If there is any data after the last arg, then the format is invalid and it should return an error
			if (cstrtok(0x00, " ") != 0x00) goto error;	
			
			channel = tolower(channel);
			if ((channel != 'a' && channel != 'b') || memBlock < -1 || memBlock > 3)
				goto error; // Memory block was out of range or the channel was not A or B
			
			// Set specified memory block to given channel
			if (channel == 'a') chAMemBlk = memBlock;
			else chBMemBlk = memBlock;
		}
		else if (!cstrcmp("rate", cmd)) // If the command rate was entered
		{
			int samplingRate;
			int ksps;
			params = cstrtok(0x00, " "); // 0x00 indicates it will continue from last cstrtok command and get next word. This gets the next parameter

			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %d gets an integer, this is the memory block
			if (strlen(params) != 1 || csscanf(params, "%d", &samplingRate) != 1) goto error;
			
			// If there is any data after the last arg, then the format is invalid and it should return an error
			if (cstrtok(0x00, " ") != 0x00) goto error;	
			
			if (samplingRate < 0 || samplingRate > 9)
				goto error; // Invalid sampling rate was selected
			
			switch (samplingRate)
			{
				case 1: ksps = SAMPLING_RATE_1250; break;
				case 2: ksps = SAMPLING_RATE_1500; break;
				case 3: ksps = SAMPLING_RATE_1875; break;
				case 4: ksps = SAMPLING_RATE_2500; break;
				case 5: ksps = SAMPLING_RATE_3125; break;
				case 6: ksps = SAMPLING_RATE_3750; break;
				case 7: ksps = SAMPLING_RATE_6250; break;
				case 8: ksps = SAMPLING_RATE_7500; break;
				case 9: ksps = SAMPLING_RATE_9375; break;
				default: break;
			}
			
			DelSigClock_Stop(); // Stop the DelSigClock before writing
			DelSigClock_WritePeriod(ksps);
			DelSigClock_WriteCompareValue(ksps>>1); // 50% duty cycle
			DelSigClock_Start(); // Start it again
		}
		else if (!cstrcmp("trigger", cmd)) // If the command trigger was entered
		{
			int address;

			// csscanf if used to parse the string into values such as hexadecimal or integers
			// It returns the number of parameters it parsed which should be one
			// If the length of the params is not right or it does not parse the right amount, it returns an error
			// %d gets an integer, this is the memory block
			params = Lowercase(cstrtok(0x00, " "));
			if (!cstrcmp("hex", params))
			{
				// %x gets a hexadecimal value, this can read capital or lowercase letters, this is the address
				params = cstrtok(0x00, " ");
				if (strlen(params) > 4 || csscanf(params, "%x", &address) != 1) goto error;
			}
			else if (!cstrcmp("dec", params))
			{
				params = cstrtok(0x00, " ");
				// %d gets an integer, this is the address
				if (strlen(params) > 4 || csscanf(params, "%d", &address) != 1) goto error;
			}
			else 
				goto error; // Invalid data type entered
			
			if (address < 0 || address > 8192)
				goto error; // Invalid address range specified

			// If there is any data after the last arg, then the format is invalid and it should return an error
			if (cstrtok(0x00, " ") != 0x00) goto error;
		
			// triggerAddress is the specified address
			triggerAddress = address;
			
		}
		else if (!cstrcmp("start", cmd)) // If the command start was entered
		{
			// If there is any data after the number of bytes, then the format is invalid and it should return an error
			if (cstrtok(0x00, " ") != 0x00) goto error;
			
			// Start playing the data
			PlaySamples();
		}
		else 
			goto error;
		
		continue; // This is so that the error is skipped when everything goes right
		error: // This outputs an invalid format message and continues on to read another line
			UART_CPutString("########################## Lab 11 Data Acquisition System ########################\r\n\
# input X A \r\n\
#\r\n\
#	Samples input channel to memory block\r\n\
#		X - Either A/B to signify channel being altered\r\n\
#		A - Memory block(0-3) being routed\r\n\
#\r\n\
# output X A\r\n\
#	Routes output channel to read from memory block \r\n\
#		X - Either A/B to signify channel being altered\r\n\
#		A - Memory block(0-3 or -1 for none) being routed\r\n\
#\r\n\
# rate X\r\n\
#	Selects a rate to sample the channels when reading and writing\r\n\
#		X - One of the values below\r\n\
#			1. 1.25  ksps \r\n\
#			2. 1.5   ksps\r\n\
#			3. 1.87  ksps\r\n\
#			4. 2.5   ksps\r\n\
#			5. 3.125 ksps\r\n\
#			6. 3.75  ksps\r\n\
#			7. 6.25  ksps\r\n\
#			8. 7.5   ksps\r\n\
#			9. 9.37  ksps\r\n\
#\r\n\
# trigger XXX H\r\n\
#	Sets the relative address to trigger\r\n\
#		XXX - Either hex/dec for the address\r\n\
#		H - values in hexadecimal or decimal.  Range is 0-8192 for dec or 0-2000 for hex\r\n\
#\r\n\
# start\r\n\
#	Starts the output channels. They will continue to play until looped over\r\n\
#####################################################################\r\n");
	}

}

/*****************************************************************************/
/********************* Interrupt Service Routines Below **********************/
/*****************************************************************************/
#pragma interrupt_handler DACUpdate_ISR

// DACUpdate_ISR is called at the terminal count of the DACUpdate user module.
// Since it's clock source is the same as DelSig, setting its period to
// match the DelSig PWM (4*DecimationRate) will cause it to interrupt at the
// same rate as the DelSig's sampling rate. If the samples are only sent to
// the DACs when the variable DACUpdateDone is one, the output sampling rate
// can be controlled.
void DACUpdate_ISR(void)
{
	// Updating the DACs inside the ISR takes more clock cycles
	// than simply setting a flag and exiting. This is because
	// the C-compiler does a full preserve and restore of the
	// CPU context which takes 190+185 CPU cycles.
	DACUpdateDone = 1;
}