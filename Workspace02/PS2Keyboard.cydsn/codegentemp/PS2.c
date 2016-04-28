/* ========================================
 *
 * Copyright Addison Elliott, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "PS2.h"

uint16 PS2_timer_reps;
uint8 PS2_initVar;
uint8 PS2_deviceDetectFail;

CY_ISR(PS2_TIMER)
{
	// Resets the terminal count bit, it is sticky so it stays high even after the counter is reloaded
	PS2_Timer_STATUS;

	--PS2_timer_reps;
}

void PS2_Init(void) 
{
    PS2_timer_reps = 0; // Set number of repetitions to 0
    PS2_deviceDetectFail = 0; // Set device detect failed to 0
    PS2_Timer_ISR_StartEx(PS2_TIMER); // Setup ISR for the interrupt
	PS2_Timer_Start();
	PS2_Timer_Stop(); // Start and stop the timer to initialize registers
    
    PS2_RESET; // Initializes the PS2_Core state machine registers
	PS2_DATA_CTRL_SW; // Sets ps2_data line to software mode
	PS2_DATA_HIGH; // Sets ps2_data software line to 1
	PS2_CLOCK_HIGH; // Sets ps2_clock to 1
}

void PS2_Start(void) 
{
    if (0u == PS2_initVar)
    {
        PS2_Init();
        PS2_initVar = 1u; // Component initialized
    }
}

uint8 PS2_DetectDevice(void) 
{
    uint8 status;
	
	// If the previous device detect did not return a BAT code, send a reset command
	// This is to notify the device to stop doing everything, and send a BAT test
    if (PS2_deviceDetectFail)
		PS2_SendCommand(0xFF);
		
    PS2_READ; // Make sure the state machine knows to read

	PS2_TIMER_WAIT_UNTIL(200, 500, PS2_STATUS == PS2_STATUS_PENDING);
	if (PS2_STATUS == PS2_STATUS_DONE)
    {
        //CyDelay(1); // Delay one millisecond to give the status register time to update
        if (PS2_BYTE_R == 0xAA)
        {
            // XXX: Mess with getting mouse to work with PS/2
            status = PS2_SUCCESS;
        }
        else
            status = PS2_BAD_BAT;

        PS2_deviceDetectFail = 0; // No need to reset, the BAT code was received correctly
    }
    else if (PS2_STATUS == PS2_STATUS_ERROR)
    {
        PS2_deviceDetectFail = 1; // If there was a transmission error, send reset command next function call
        status = PS2_ERROR;
    }
    else
    {
        PS2_deviceDetectFail = 1; // If there was a timeout, send reset command next function call
        status = PS2_TIMEOUT;
    }
    
    // The state machine needs to be reset everytime it sends or receives something. Yes, this could be done in the state machine
    // but there is not enough UDBs for it. Adding another if statement makes it break
    PS2_RESET;
    return status;
}

uint8 PS2_WriteByte(uint8 data) 
{
    uint8 status = 0;
	
	// If we are receiving something, give it 10ms to finish. If it is still in progress,
	// then it will have to be resent once the transmission is over. The device handles
	// this though
    if (PS2_STATE != PS2_IDLE)
	{		
		PS2_TIMER_WAIT(1, 1);	
		PS2_RESET; // Reset the state machine once the wait is done
	}
	else
		PS2_TIMER_WAIT(100, 1);	
	
    PS2_WRITE; // Tell state machine we are writing
	PS2_CLOCK_LOW; // Set clock line to low
	
	PS2_TIMER_WAIT(6, 1); // Wait (10uS * 10 * 1) = 60us
	
	PS2_DATA_LOW; // Pull data line low

	PS2_TIMER_WAIT(3, 1); // Wait (10uS * 3 * 1) = 30uS
	
	PS2_CLOCK_HIGH; // Bring the clock high again, the device should start generating clock signals
	
	PS2_DATA_WRITE(data);
	PS2_DATA_CTRL_HW;
	PS2_DATA_HIGH;
	
    // Per Adam Chapweske: Wait here for 15 ms or until we've transitioned
    // out of the start bit state. If this time is exceeded, it's a timeout
	PS2_TIMER_WAIT_UNTIL(100, 15, PS2_STATE == PS2_WRITE_BIT_1);
	
    if (PS2_STATE == PS2_WRITE_BIT_1)
    {
        // We have timed out because the state has not changed for 15ms
        PS2_DATA_CTRL_SW; // Set data line back to software, its already high
		PS2_RESET; // Reset the state machine
        return (PS2_TIMEOUT);
    }

    // Per Adam Chapweske: The time it takes for the packet to be sent must be no greater than 2ms.
	PS2_TIMER_WAIT_UNTIL(100, 2, PS2_STATUS == PS2_STATUS_PENDING);
	
    if (PS2_STATUS == PS2_STATUS_DONE)
        status = PS2_SUCCESS;
    else if (PS2_STATUS == PS2_STATUS_ERROR)
        status = PS2_ERROR;
    else
        status = PS2_TIMEOUT;
	
	PS2_DATA_CTRL_SW; // Set data line back to software, its already high
    PS2_RESET; // Reset the state machine
	PS2_READ; // Set the state machine back to read
    return status;
}

uint8 PS2_SendCommand(uint8 data) 
{
	uint8 txStatus;
	
	// XXX - Maybe put an upper bound on the number of resends to do
	// Loop in case of resends
	while (1)
	{
		txStatus = PS2_WriteByte(data);
		// Non-zero return means there was an error
		if (txStatus)
			return txStatus;

		// The device should respond within 20ms of the time of sending
		PS2_TIMER_WAIT_UNTIL(100, 20, PS2_STATUS == PS2_STATUS_PENDING);
		if (PS2_STATUS == PS2_STATUS_DONE)
		{
			switch (PS2_BYTE_R)
			{
				case 0xFA: // ACK: The device correctly received our command
					PS2_RESET;
					return PS2_SUCCESS;
					
				case 0xFE: // RESEND: The device wants us to resend the last byte
					// Caused by the device receiving an incorrect parity error
					// If we break out of this switch, the while loop will resend the byte
					PS2_RESET;
					break;
				
				case 0xEE: // ECHO: The device responded with an Echo
					// This should be because we sent it an echo
					PS2_RESET;
					if (data == 0xEE)
						return PS2_SUCCESS;
					return PS2_INVALID_RESPONSE;
					
				default:
					PS2_RESET;
					return PS2_INVALID_RESPONSE;
			}
		}
		else if (PS2_STATUS == PS2_STATUS_ERROR)
		{
			// Some sort of error such as parity or incorrect start/stop bit
			// Resend the byte
			break;	
		}
		else
			return PS2_TIMEOUT; // Device timed out
	}
	
	// The code should never reach here, but we return something to shut the compiler up
	return PS2_ERROR;
}

// Blocking function to read a byte. Returns the byte read
uint8 PS2_ReadByte(void) 
{
	while (PS2_STATUS != PS2_STATUS_DONE);
	
	PS2_RESET; // Reset the state machine
	return PS2_BYTE_R; // Return the read byte
}

// Non-blocking function to read a byte. Returns 0x00 if no data is available. Otherwise it returns the byte read
uint8 PS2_cReadByte(void) 
{
	if (PS2_STATUS != PS2_STATUS_DONE)
		return 0x00;

	PS2_RESET; // Reset the state machine
	return PS2_BYTE_R; // Return the read byte
}    

/* [] END OF FILE */
