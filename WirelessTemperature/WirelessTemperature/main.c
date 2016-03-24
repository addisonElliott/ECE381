//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "stdlib.h"

#define SCALE_FACTOR 0.000079345703125	//This is the scale factor used in the Analog to Digital conversion
										//(scale factor=(RefHIGH-RefLOW)/2^resolution)

void main(void)
{
	int result;
	float voltage;
	int status;
	
	M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	// Insert your main routine code here.
	
	//Start PGA in high power mode
	PGA_Start(PGA_HIGHPOWER);
	
	//Start ADCINC in high power mode
	ADCINC_Start(ADCINC_HIGHPOWER);
	
	//Start LCD
	LCD_Start();
	
	//Run the ADC continuously
	ADCINC_GetSamples(0);
	
	SleepTimer_Start();
   	SleepTimer_SetInterval(SleepTimer_1_HZ);
   	SleepTimer_EnableInt();
	
	while (1)
	{
		SleepTimer_SyncWait(1, SleepTimer_WAIT_RELOAD);
		
		// Wait for data to be ready
		while (ADCINC_fIsDataAvailable() == 0);
		
		// Get Data and clear flag
		result=ADCINC_iClearFlagGetData();
		voltage = result * SCALE_FACTOR;
		
		LCD_Position(0, 0);
		LCD_PrCString("                ");
		LCD_Position(0, 0);
		LCD_PrHexInt(result);
		
		LCD_Position(1, 0);
		LCD_PrCString("                ");
		LCD_Position(1, 0);
		LCD_PrString(ftoa(voltage, &status));
	}
}