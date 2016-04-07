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
#include "math.h"

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
BYTE DACUpdateDone = 0;
// add your globals here

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
	
	while(1) {
	UART_CPutString("########################## Lab 11 Data Acquisition System ########################\r\n\
# input X # \r\n\
#\r\n\
#	Routes input channel to write to memory block\r\n\			
#	H - Either A/B to signify channel being altered\r\n");
/*#		# - Memory block(0-3) being routed\r\n");
#\r\n\
# output X #\r\n\
#	Routes output channel to read from memory block \r\n\
#		X - Either A/B to signify channel being altered\r\n");
#		# - Memory block(0-3 or N for none) being routed\r\n\
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
# trigger XXX # H\r\n\
#	Sets the relative address to trigger\r\n\
#		XXX - Either hex/DEC_CR0 for the address\r\n\
#		X - Memory block(0-3) that the trigger occurs\r\n\
#		H - values in hexadecimal or decimal.  Range is 0-8192 for decimal or 0-0x2000 for hex\r\n\
#\r\n\
# start\r\n\
#	Starts the stuff\r\n\
#####################################################################\r\n");*/
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