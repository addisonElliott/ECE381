//----------------------------------------------------------------------------
//
//	Example Code for PSoC Interfacing with the nrf24L01+ SPI Radios
//
//	Author: Tim York
//
//	Date: 03-22-2016
//
//	Description: This code contains basic blocks for writing to and reading
//	from the configuration register on the nrf24L01+ radios. This code should
//	be expanded to include full transmission and receiving.
//	
//----------------------------------------------------------------------------
#include <m8c.h>        // part specific constants and macros
#include <stdlib.h>
#include <stdio.h>
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
#include "PSoCGPIOINT.h"
#include "nrf24L01_API.h"

void main(void)
{
	int test = 0;
	char buf[9]; // Temporary string to contain 8 bytes while sending to wireless module
	
	M8C_EnableGInt; // Enable Global Interrupts
	M8C_EnableIntMask(INT_MSK0,INT_MSK0_GPIO);	
	
	SleepTimer_EnableInt();	 // Enable user module interrupts
	SleepTimer_SetInterval(SleepTimer_1_HZ); // Set timer interval for 1Hz	
	
	CSN_HIGH; // Make sure CS is high before beginning
	
	// Start the user modules
	LCD_Start();
	SPIM_Start(SPIM_SPIM_MODE_0 | SPIM_SPIM_MSB_FIRST);
	SleepTimer_Start();
	
	CE_HIGH; //Enable the nrf24 radio
	nrfWriteRegister(NRF_WRITE_SETUP_RETR, 0xFF); // Setup automatic retransmission: 4000uS delay, 15 retransmit count
	nrfWriteRegister(NRF_WRITE_RF_CH, 0x60); // Sets RF Channel to 0x60 
	nrfWriteRegister(NRF_WRITE_RF_SETUP, 0x26); // Sets RF output power to 0dBm, data rate to 250kbps 
	buf[0] = buf[1] = buf[2] = buf[3] = buf[4] = 0xC2;
	nrfWriteAddress(NRF_WRITE_TX_ADDR, buf); // Sets TX address to 0xC2C2C2C2C2 (transmit address)
	buf[0] = buf[1] = buf[2] = buf[3] = buf[4] = 0xC2;
	nrfWriteAddress(NRF_WRITE_RX_ADDR_P0, buf); // Sets receive pipe 0 address to 0xC2C2C2C2C2 (also transmit address)
	buf[0] = buf[1] = buf[2] = buf[3] = buf[4] = 0xE7;
	nrfWriteAddress(NRF_WRITE_RX_ADDR_P1, buf); // Sets receive pipe 1 address to 0xE7E7E7E7E7 (receive address)
	nrfWriteRegister(NRF_WRITE_PW_P0, 0x08); // Sets payload size to 8 bytes at transmit address
	nrfWriteRegister(NRF_WRITE_PW_P1, 0x08); // Sets payload size to 8 bytes are receive address
	nrfWriteRegister(NRF_WRITE_EN_AA, 0xFF); // Enable auto-acknowledge on all data pipes
	nrfWriteRegister(NRF_WRITE_EN_RXADDR, 0x03); // Enable data pipes 0 and 1
	nrfWriteRegister(NRF_WRITE_CONFIG, 0x0E); // Setup config: power on, TX mode, CRC 2-byte mode
	
	LCD_Position(0, 0);
	LCD_PrHexByte(nrfReadRegister(NRF_READ_SETUP_RETR));
	LCD_PrHexByte(nrfReadRegister(NRF_READ_RF_CH));
	LCD_PrHexByte(nrfReadRegister(NRF_READ_RF_SETUP));
	
	LCD_PrHexByte(nrfReadRegister(NRF_READ_PW_P0));
	LCD_PrHexByte(nrfReadRegister(NRF_READ_PW_P1));
	LCD_PrHexByte(nrfReadRegister(NRF_READ_EN_AA));
	
	LCD_PrHexByte(nrfReadRegister(NRF_READ_EN_RXADDR));
	LCD_PrHexByte(nrfReadRegister(NRF_READ_CONFIG));
	
	LCD_Position(1, 0);
	nrfReadAddress(NRF_READ_RX_ADDR_P1, buf);
	for (test = 0; test < 5; ++test)
		LCD_PrHexByte(buf[test]);
	SleepTimer_SyncWait(4, SleepTimer_WAIT_RELOAD);
	while (1) 
	{
		SleepTimer_SyncWait(5, SleepTimer_WAIT_RELOAD); // Wait for about 1 second
		
		LCD_Control(LCD_DISP_CLEAR_HOME);
		LCD_Position(0, 0);
		LCD_PrCString("Send");
		LCD_PrHexByte(test);
		csprintf(buf, "9: 123.4");
		nrfSendData(buf);
		
		while (IRQ_Data_ADDR & IRQ_MASK);
		LCD_Position(1, 0);
		LCD_PrCString("Sent");
		LCD_PrHexByte(test++);
		nrfWriteRegister(NRF_WRITE_STATUS, 0x7E);
	}
}
