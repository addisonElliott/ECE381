
//----------------------------------------------------------------------------
// 23K256 SPI SRAM Program
//
// PSoC Global Resources:
//   Power Setting     5.0V/24MHz
//   CPU_Clock         SysClk/1
//   32K_Select        Internal
//   PLL_Mode          Off
//   Sleep_Timer       8_Hz
//   VC1=SysClk/N     *12
//   VC2=VC1/N        *2
//                    * VC1 & VC2 values make VC2 = 1MHz = SPIM Clock
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
//   LVD ThrottleBack  Disable
//                    *When enabled, an LVD event forces the CPU Clock to SysClk/8.
//   Watchdog Enable  *{ Any }
//                    *Incautious use of the Watchdog may adversely affect timing
//
// SPIM Parameters
//   Name              SPIM
//   Clock            *VC2
//                    *1MHz = 500kbps SPI bit rate.
//   MISO              Row_2_Input_1
//   MOSI              Row_2_Output_0
//   SClk              Row_2_Output_3
//   Interrupt Mode    TXRegEmpty
//   ClockSync         Sync to SysClk
//   InvertMISO        Normal
//
// SPIM Module Notes
//   The 23K256 SPI SRAM has a maximum clock speed of 20MHz
//   SPIM Clock must be set to two times the desired bit rate
//   My prototype uses VC2 = SysClk/48 = 500kHz, yielding a bit rate of 250kbps
//   CS   = P12 (StdCPU:    Open Drain Low)
//   SCLK = P13 (GlobalOut: Open Drain Low)
//   MOSI = P14 (GlobalOut: Open Drain Low)
//   MISO = P15 (GlobalIn:  High Z)
//
// SPIM Modules Notes:
//  -Per Datasheet: The Row Input synchronization for MISO should be set to
//   Async for high SPI bit rates (>1Mbps).
//  -The SPIM Control Register contains the flags that are read by the
//   SPIM_bReadStatus() function. Reading clears all flags.
//  -The Datasheet for the SPIM Datasheet is inconsistent in its referral to
//   the SPIM_SPI_COMPLETE flag.  In the SPIM Control Register, it is named
//   SPI Done.
//  -The SPIM Module always transfers data present on the MISO pin when it
//   writes to the MOSI pin. In other words, it always transfers data into
//   the receive buffer while it is transferring data out of the transmit
//   buffer; it is essential to keep this in mind when checking flags.
//  -TX_BUFFER_EMPTY indicates that a new byte can be written to the TX Buffer.
//  -RX_BUFFER_FULL is set on the edge that captures the 8th bit of receive data.
//  -SPI_COMPLETE (an optional interrupt) is set when eight bits
//   of data and clock have been sent. In modes 0 and 1, this occurs one-half
//   cycle after RX_BUFFER_FULL is set; because in these modes, data is latched
//   on the leading edge of the clock and there is an additional one-half cycle
//   remaining to complete that clock. In modes 2 and 3, this occurs at the
//   same edge that the receive data is latched. This signal may be used to
//   read the received byte or it may be used by the SPIM to disable the
//   block after data transmission is complete.
//   See PSoC TRM, Document No. 001-14463 Rev. *G, Figure 17-19, page 358.
//  -Once the first byte to be transmitted is moved into the transmit buffer
//   by calling the SendTxData API, the SPIM module immediately moves the
//   byte into the transmit shift register one SPIM Clock Input cycle later
//   whereupon the TX_BUFFER_EMPTY flag is set immediately.
//   If another byte is written before the first byte has been fully shifted
//   out, it is placed in the transmit buffer and remains there until half-way
//   through the transmission of the 8th and final bit whereupon it is
//   automatically loaded into the transmit buffer which again sets the
//   TX_BUFFER_EMPTY flag and the 1st bit of the second byte begins
//   its transfer immediately after the 8th bit of the 1st byte. This allows
//   for uninterrupted back-to-back transmission.
//
// 23K256 Notes:
//  -Pins 4 & 8, the power pins, must have a 0.1uF decoupling capacitor
//   physically placed as close as possible to the IC package.
//  -Pin 7 (nHOLD) must be tied to Vcc since it is not used here.
//  -Pin 3 should be left floating since it is NC (no connection)
//  -3.3V SPI to 5V PSoC voltage translation is accomplished through 2.2k
//   pull-up resistors. This also limits the maximum reliable data transfer
//   rate due to the 2.2k*Cpin+wire time constant. Long wires are detrimental!
//
// bnoble@siue.edu 20140320
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "stdlib.h"
#include "spi_sram.h"
#include "math.h"
// Define our I/O array size. Powers of 2 are nice but not necessary
#define ARRAY_SIZE 64

// Globals
BYTE DataIn[ARRAY_SIZE];
BYTE DataOut[ARRAY_SIZE];

// Test reading and writing the 23K256 status register:
BYTE SPIRAM_StatusRegisterTest(void)
{
	// NOTE: SPIRAM_SEQUENTIAL_MODE|SPIRAM_PAGE_MODE is "Reserved", don't use it
	BYTE mode[6] = { SPIRAM_BYTE_MODE,
					 SPIRAM_BYTE_MODE|SPIRAM_DISABLE_HOLD,
					 SPIRAM_SEQUENTIAL_MODE,
					 SPIRAM_SEQUENTIAL_MODE|SPIRAM_DISABLE_HOLD,
					 SPIRAM_PAGE_MODE,
					 SPIRAM_PAGE_MODE|SPIRAM_DISABLE_HOLD };
	BYTE status;
	BYTE b;

	UART_CPutString("Status Register W/R Test: 0x  ");
	for (b=0; b<6 ; b++) {
		UART_PutChar(0x08);
		UART_PutChar(0x08);
		UART_PutSHexByte(mode[b]);
		if (SPIRAM_WriteStatusRegister(mode[b])) {
			UART_CPutString("\r\nWrite of invalid Status Register value. System halted.\r\n");
			M8C_Stop;
		}
		status = SPIRAM_ReadStatusRegister();
		if (status != mode[b]) {
			UART_CPutString(" FAIL\r\n");
			return(1);
		}
	}
	UART_CPutString("\b\b\b\b\b PASS\r\n");
	// Place the SRAM back in Byte Mode
	SPIRAM_WriteStatusRegister(SPIRAM_BYTE_MODE|SPIRAM_DISABLE_HOLD);
	return(0);
}

// Test reading and writing the 23K256 in Byte Mode:
WORD SPIRAM_ByteModeTest(void)
{
	BYTE status;
	BYTE b;
	BYTE in;
	WORD addr;

	SPIRAM_WriteStatusRegister(SPIRAM_BYTE_MODE|SPIRAM_DISABLE_HOLD);
	UART_CPutString("      Byte Mode W/R Test: Addr 0x    ");

	for (addr=0; addr<0x8000 ; addr++) {
		if (((addr-1) & 0x000f) == 0x000f) {
			UART_CPutString("\b\b\b\b");
			UART_PutSHexInt(addr);
		}
		b = 0;
		do {
			SPIRAM_WriteByte(addr, b);
			in = SPIRAM_ReadByte(addr);
			if (in != b) {
				UART_CPutString("\b\b\b\b");
				UART_PutSHexInt(addr);
				UART_CPutString(" FAIL\r\n");
				return(1);
			}
			if (!b)
				b = 0x01;
			else
				b = b << 1;
		} while(b);
		if (UART_cReadChar()) {
			UART_CPutString("\b\b\b\b\b\b\b\b\b\b\b\b ABORTED    \r\n");
			return(0);
		}
	}
	UART_CPutString("\b\b\b\b\b\b\b\b\b\b\b\b PASS       \r\n");
	return(0);
}

// Test reading and writing the 23K256 in Sequential Mode:
WORD SPIRAM_SequentialModeTest(void)
{
	BYTE status;
	BYTE a;
	BYTE b;
	BYTE in;
	WORD addr;

	SPIRAM_WriteStatusRegister(SPIRAM_SEQUENTIAL_MODE|SPIRAM_DISABLE_HOLD);
	UART_CPutString("Sequential Mode W/R Test: Addr 0x    ");

	for (addr=0; addr<0x8000 ; addr+=ARRAY_SIZE) {
		UART_CPutString("\b\b\b\b");
		UART_PutSHexInt(addr);
		b = 0;
		do {
			for (a=0 ; a<ARRAY_SIZE ; a++) {
				DataOut[a] = b;
			}
			SPIRAM_WriteArray(addr, DataOut, ARRAY_SIZE);
			SPIRAM_ReadArray(addr, DataIn, ARRAY_SIZE);
			for (a=0 ; a<ARRAY_SIZE ; a++) {
				if (DataIn[a] != b) {
					UART_CPutString("\b\b\b\b");
					UART_PutSHexInt(addr+a);
					UART_CPutString(" FAIL\r\n");
					return(1);
				}
			}
			if (!b)
				b = 0x01;
			else
				b = b << 1;
		} while(b);
		if (UART_cReadChar()) {
			UART_CPutString("\b\b\b\b\b\b\b\b\b\b\b\b ABORTED    \r\n");
			return(0);
		}
	}
	UART_CPutString("\b\b\b\b\b\b\b\b\b\b\b\b PASS       \r\n");
	return(0);
}

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
		UART_PutCRLF();
		return (c - '0'); // This returns the integer number entered instead of the ASCII value
	}
	
	return 0;
}

// This function plays a block of data where opt is the data block 0-3.
void PlayBlock(char id)
{	
	WORD startAddr = id * 0x2000; // Where the address starts for block
	WORD endAddr = startAddr + 0x2000; // Where the address ends for block
	WORD addr = startAddr;
	
	SPIRAM_WriteStatusRegister(SPIRAM_BYTE_MODE | SPIRAM_DISABLE_HOLD);
	UART_CPutString("Press any key to abort\r\n");
	while (!UART_cReadChar())
	{
		DAC8_WriteStall(SPIRAM_ReadByte(addr));
		if (++addr > endAddr) addr = startAddr;
	}
}
void WriteBlock(char id)
{	

	WORD startAddr = 0x2000 *id; // Where the address starts for block
	WORD endAddr = startAddr + 0x2000; // Where the address ends for block
	WORD addr;
	BYTE i, ii;
	float pi = 3.1415;
	char temp[128];
	
	SPIRAM_WriteStatusRegister(SPIRAM_SEQUENTIAL_MODE | SPIRAM_DISABLE_HOLD);
	switch (id)
	{
		case 0:	
			for (addr = startAddr; addr < endAddr; addr += 128)
			{
				for(i = 0; i < 128; i++)
				{
					temp[i] = (char)(0.5 + 0.5*sin(800*pi*((addr - startAddr) + i)) + 0.5*sin(800*pi*((addr - startAddr) + i))*(128/2.5));	
				}	
				SPIRAM_WriteArray(addr, temp, 128);
				UART_CPutString("Writing to ");
				UART_PutSHexInt(addr);
				UART_CPutString("\r\n");
			}
			break;
		
		case 1:	
			for (addr = startAddr; addr < endAddr; addr += 128)
			{
				for(i = 0; i < 128; i++)
				{
					temp[i] = (char)(0.2 + 0.5*sin(600*pi*((addr - startAddr) + i)) + 0.5*sin(200*pi*((addr - startAddr) + i))*(128/2.5));
				}	
				SPIRAM_WriteArray(addr, temp, 128);
			}
			break;
		
		case 2:	
			for (addr = startAddr; addr < endAddr; addr += 128)
			{
				for(i = 0; i < 128; i++)
				{
					temp[i] = (char)(0.1 + 0.5*sin(1500*pi*((addr - startAddr) + i)) + 0.5*sin(700*pi*((addr - startAddr) + i))*(128/2.5));	
				}	
				SPIRAM_WriteArray(addr, temp, 128);
			}
			break;
		
		case 3:
			for (addr = startAddr; addr < endAddr; addr += 128)
			{
				for(i = 0; i < 128; i++)
				{
					temp[i] = (char)(0.4 + 0.5*sin(100*pi*((addr - startAddr) + i))*(128/2.5));
				}	
				SPIRAM_WriteArray(addr, temp, 128);
			}
			break;
	}
	
}

void main(void)
{
	char opt;
	
	// Make sure nCS is high before doing anything
	nCS_HIGH;
	
	// Enable user module interrupts
	SleepTimer_EnableInt();

	// Enable global interrutps
	M8C_EnableGInt;

	// Start the user modules
	UART_Start(UART_PARITY_NONE);
	UART_PutCRLF();
	SPIM_Start(SPIM_SPIM_MODE_0 | SPIM_SPIM_MSB_FIRST);
	SleepTimer_Start();
	DAC8_Start(DAC8_FULLPOWER);
	UART_CPutString("Synthesiszing waveforms\r\n");
	WriteBlock(0);
	WriteBlock(1);
	WriteBlock(2);
	WriteBlock(3);
	while(1) 
	{
		UART_CPutString("Synthetic wave output is on Port0[4]\r\nCowabunga Dude! Time to catch some waves.\r\n\r\n0. Play block 0\r\n1. Play block 1\r\n2. Play block 2\r\n3. Play block 3\r\n4. Test status register\r\n5. Test byte mode\r\n6. Test sequential mode\r\n");
		
		opt = GetNumber(0, 6);
		switch (opt)
		{
			case 4:
				while(SPIRAM_StatusRegisterTest()) 
					SleepTimer_SyncWait(4, SleepTimer_WAIT_RELOAD);
				break;
			
			case 5:
				while(SPIRAM_ByteModeTest()) 
					SleepTimer_SyncWait(4, SleepTimer_WAIT_RELOAD);	
				break;
			
			case 6:
				while(SPIRAM_SequentialModeTest()) 
					SleepTimer_SyncWait(4, SleepTimer_WAIT_RELOAD);
				break;
			
			default:
				PlayBlock(opt);
				break;	
		}
	}
}