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

#include "`$INSTANCE_NAME`.h"

uint16 `$INSTANCE_NAME`_timer_reps;
uint8 `$INSTANCE_NAME`_initVar;
uint8 `$INSTANCE_NAME`_deviceDetectFail;

CY_ISR(`$INSTANCE_NAME`_TIMER)
{
	// Resets the terminal count bit, it is sticky so it stays high even after the counter is reloaded
	`$INSTANCE_NAME`_Timer_STATUS;

	--`$INSTANCE_NAME`_timer_reps;
}

void `$INSTANCE_NAME`_Init(void) `=ReentrantKeil($INSTANCE_NAME . "_Init")`
{
    `$INSTANCE_NAME`_timer_reps = 0; // Set number of repetitions to 0
    `$INSTANCE_NAME`_deviceDetectFail = 0; // Set device detect failed to 0
    `$INSTANCE_NAME`_Timer_ISR_StartEx(`$INSTANCE_NAME`_TIMER); // Setup ISR for the interrupt
	`$INSTANCE_NAME`_Timer_Start();
	`$INSTANCE_NAME`_Timer_Stop(); // Start and stop the timer to initialize registers
    
    `$INSTANCE_NAME`_RESET; // Initializes the PS2_Core state machine registers
	`$INSTANCE_NAME`_DATA_CTRL_SW; // Sets ps2_data line to software mode
	`$INSTANCE_NAME`_DATA_HIGH; // Sets ps2_data software line to 1
	`$INSTANCE_NAME`_CLOCK_HIGH; // Sets ps2_clock to 1
}

void `$INSTANCE_NAME`_Start(void) `=ReentrantKeil($INSTANCE_NAME . "_Start")`
{
    if (0u == `$INSTANCE_NAME`_initVar)
    {
        `$INSTANCE_NAME`_Init();
        `$INSTANCE_NAME`_initVar = 1u; // Component initialized
    }
}

uint8 `$INSTANCE_NAME`_DetectDevice(void) `=ReentrantKeil($INSTANCE_NAME . "_Init")`
{
    uint8 status;
	
	// If the previous device detect did not return a BAT code, send a reset command
	// This is to notify the device to stop doing everything, and send a BAT test
    if (`$INSTANCE_NAME`_deviceDetectFail)
		`$INSTANCE_NAME`_SendCommand(0xFF);
		
    `$INSTANCE_NAME`_READ; // Make sure the state machine knows to read

	`$INSTANCE_NAME`_TIMER_WAIT_UNTIL(200, 500, `$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_PENDING);
	if (`$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_DONE)
    {
        //CyDelay(1); // Delay one millisecond to give the status register time to update
        if (`$INSTANCE_NAME`_BYTE_R == 0xAA)
        {
            // XXX: Mess with getting mouse to work with PS/2
            status = `$INSTANCE_NAME`_SUCCESS;
        }
        else
            status = `$INSTANCE_NAME`_BAD_BAT;

        `$INSTANCE_NAME`_deviceDetectFail = 0; // No need to reset, the BAT code was received correctly
    }
    else if (`$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_ERROR)
    {
        `$INSTANCE_NAME`_deviceDetectFail = 1; // If there was a transmission error, send reset command next function call
        status = `$INSTANCE_NAME`_ERROR;
    }
    else
    {
        `$INSTANCE_NAME`_deviceDetectFail = 1; // If there was a timeout, send reset command next function call
        status = `$INSTANCE_NAME`_TIMEOUT;
    }
    
    // The state machine needs to be reset everytime it sends or receives something. Yes, this could be done in the state machine
    // but there is not enough UDBs for it. Adding another if statement makes it break
    `$INSTANCE_NAME`_RESET;
    return status;
}

uint8 `$INSTANCE_NAME`_WriteByte(uint8 data) `=ReentrantKeil($INSTANCE_NAME . "_WriteByte")`
{
    uint8 status = 0;
	
	// If we are receiving something, give it 10ms to finish. If it is still in progress,
	// then it will have to be resent once the transmission is over. The device handles
	// this though
    if (`$INSTANCE_NAME`_STATE != `$INSTANCE_NAME`_IDLE)
	{		
		`$INSTANCE_NAME`_TIMER_WAIT(1, 1);	
		`$INSTANCE_NAME`_RESET; // Reset the state machine once the wait is done
	}
	else
		`$INSTANCE_NAME`_TIMER_WAIT(100, 1);	
	
    `$INSTANCE_NAME`_WRITE; // Tell state machine we are writing
	`$INSTANCE_NAME`_CLOCK_LOW; // Set clock line to low
	
	`$INSTANCE_NAME`_TIMER_WAIT(6, 1); // Wait (10uS * 10 * 1) = 60us
	
	`$INSTANCE_NAME`_DATA_LOW; // Pull data line low

	`$INSTANCE_NAME`_TIMER_WAIT(3, 1); // Wait (10uS * 3 * 1) = 30uS
	
	`$INSTANCE_NAME`_CLOCK_HIGH; // Bring the clock high again, the device should start generating clock signals
	
	`$INSTANCE_NAME`_DATA_WRITE(data);
	`$INSTANCE_NAME`_DATA_CTRL_HW;
	`$INSTANCE_NAME`_DATA_HIGH;
	
    // Per Adam Chapweske: Wait here for 15 ms or until we've transitioned
    // out of the start bit state. If this time is exceeded, it's a timeout
	`$INSTANCE_NAME`_TIMER_WAIT_UNTIL(100, 15, `$INSTANCE_NAME`_STATE == `$INSTANCE_NAME`_WRITE_BIT_1);
	
    if (`$INSTANCE_NAME`_STATE == `$INSTANCE_NAME`_WRITE_BIT_1)
    {
        // We have timed out because the state has not changed for 15ms
        `$INSTANCE_NAME`_DATA_CTRL_SW; // Set data line back to software, its already high
		`$INSTANCE_NAME`_RESET; // Reset the state machine
        return (`$INSTANCE_NAME`_TIMEOUT);
    }

    // Per Adam Chapweske: The time it takes for the packet to be sent must be no greater than 2ms.
	`$INSTANCE_NAME`_TIMER_WAIT_UNTIL(100, 2, `$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_PENDING);
	
    if (`$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_DONE)
        status = `$INSTANCE_NAME`_SUCCESS;
    else if (`$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_ERROR)
        status = `$INSTANCE_NAME`_ERROR;
    else
        status = `$INSTANCE_NAME`_TIMEOUT;
	
	`$INSTANCE_NAME`_DATA_CTRL_SW; // Set data line back to software, its already high
    `$INSTANCE_NAME`_RESET; // Reset the state machine
	`$INSTANCE_NAME`_READ; // Set the state machine back to read
    return status;
}

uint8 `$INSTANCE_NAME`_SendCommand(uint8 data) `=ReentrantKeil($INSTANCE_NAME . "_WriteByte")`
{
	uint8 txStatus;
	
	// XXX - Maybe put an upper bound on the number of resends to do
	// Loop in case of resends
	while (1)
	{
		txStatus = `$INSTANCE_NAME`_WriteByte(data);
		// Non-zero return means there was an error
		if (txStatus)
			return txStatus;

		// The device should respond within 20ms of the time of sending
		`$INSTANCE_NAME`_TIMER_WAIT_UNTIL(100, 20, `$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_PENDING);
		if (`$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_DONE)
		{
			switch (`$INSTANCE_NAME`_BYTE_R)
			{
				case 0xFA: // ACK: The device correctly received our command
					`$INSTANCE_NAME`_RESET;
					return `$INSTANCE_NAME`_SUCCESS;
					
				case 0xFE: // RESEND: The device wants us to resend the last byte
					// Caused by the device receiving an incorrect parity error
					// If we break out of this switch, the while loop will resend the byte
					`$INSTANCE_NAME`_RESET;
					break;
				
				case 0xEE: // ECHO: The device responded with an Echo
					// This should be because we sent it an echo
					`$INSTANCE_NAME`_RESET;
					if (data == 0xEE)
						return `$INSTANCE_NAME`_SUCCESS;
					return `$INSTANCE_NAME`_INVALID_RESPONSE;
					
				default:
					`$INSTANCE_NAME`_RESET;
					return `$INSTANCE_NAME`_INVALID_RESPONSE;
			}
		}
		else if (`$INSTANCE_NAME`_STATUS == `$INSTANCE_NAME`_STATUS_ERROR)
		{
			// Some sort of error such as parity or incorrect start/stop bit
			// Resend the byte
			break;	
		}
		else
			return `$INSTANCE_NAME`_TIMEOUT; // Device timed out
	}
	
	// The code should never reach here, but we return something to shut the compiler up
	return `$INSTANCE_NAME`_ERROR;
}

// Blocking function to read a byte. Returns the byte read
uint8 `$INSTANCE_NAME`_ReadByte(void) `=ReentrantKeil($INSTANCE_NAME . "_ReadByte")`
{
	while (`$INSTANCE_NAME`_STATUS != `$INSTANCE_NAME`_STATUS_DONE);
	
	`$INSTANCE_NAME`_RESET; // Reset the state machine
	return `$INSTANCE_NAME`_BYTE_R; // Return the read byte
}

// Non-blocking function to read a byte. Returns 0x00 if no data is available. Otherwise it returns the byte read
uint8 `$INSTANCE_NAME`_cReadByte(void) `=ReentrantKeil($INSTANCE_NAME . "_cReadByte")`
{
	if (`$INSTANCE_NAME`_STATUS != `$INSTANCE_NAME`_STATUS_DONE)
		return 0x00;

	`$INSTANCE_NAME`_RESET; // Reset the state machine
	return `$INSTANCE_NAME`_BYTE_R; // Return the read byte
}    

/* [] END OF FILE */
