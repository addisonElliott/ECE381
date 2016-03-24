//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include <stdlib.h>

void main(void)
{
	int result;
	float voltage;
	int *status;
	
	M8C_EnableGInt;
	
	PGA_Start(PGA_HIGHPOWER);
	ADCINC_Start(ADCINC_HIGHPOWER);
	
	LCD_Start();
	ADCINC_GetSamples(0);
	
	while (1)
	{
		while (ADCINC_fIsDataAvailable() == 0);
		
		result = ADCINC_iClearFlagGetData();
		
		voltage = result /** .00015869140625f*/;
		
		LCD_Position(0,0);
		//LCD_PrCString("Input Voltage is");
		LCD_PrCString("           ");
		LCD_Position(0, 0);
		LCD_PrHexInt(result);
		
		LCD_Position(1,0);
		LCD_PrCString("                ");
		
		LCD_Position(1,0);
		
		LCD_PrString(ftoa(voltage, status));
		
	
	
	}
}
