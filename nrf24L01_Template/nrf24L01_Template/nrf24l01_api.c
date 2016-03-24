#include <m8c.h>
#include "PSoCAPI.h"
#include "nrf24L01_API.h"

// This writes a BYTE data into the register at address. See Section 9.1
// for details on the structure
void nrfWriteRegister(BYTE address, BYTE data)
{
	WORD i; // Dummy variable for delay timing
	
	CSN_LOW;	// Pull chip select low. Since chip select is low active, this will
				// tell the nrf24 to start listenting.
	
	for (i = 0; i < 260; i++); // Kill some time to ensure proper setup.
	
	// Wait until TX Buffer is empty, then send given data
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(address);
	
	// Wait until SPI transaction complete, then read data out (chainsaw effect).
	// Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();		
	
	// Wait until TX Buffer is empty, then send given data
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(data);
	
	// Wait until SPI transaction complete, then read data out (chainsaw effect).
	// Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();	
	
	CSN_HIGH; // Pull chip select high. This tells the nrf24 to ignore future SPI commands
}

BYTE nrfReadRegister(BYTE address)
{
	BYTE reg; // Variable to hold register value
	WORD i; // Dummy variable for delay timing
	
	CSN_LOW;	// Pull chip select low. Since chip select is low active, this will
				// tell the nrf24 to start listenting.
	
	for (i = 0; i < 260; i++); // Kill some time to ensure proper setup.
	
	// Wait until TX Buffer is empty, then send command word to read
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(address);
	
	// Wait until SPI transaction complete, then read data out (chainsaw effect).
	// Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();		
	
	// Wait until TX buffer empty, then send a dummy byte
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(SPIM_DUMMY_BYTE);
	
	// Dummy byte sent to push PLD out, so now read and return
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	reg = SPIM_bReadRxData();
	
	CSN_HIGH; // Pull chip select high. This tells the nrf24 to ignore future SPI commands
	
	return reg;
}

void nrfWriteAddress(BYTE address, BYTE *data)
{
	WORD i; // Dummy variable for delay timing
	//va_list v; // Variable argument list variable for the five byte address
	
	CSN_LOW;	// Pull chip select low. Since chip select is low active, this will
				// tell the nrf24 to start listenting.
	
	for (i = 0; i < 260; i++); // Kill some time to ensure proper setup.
	
	// Wait until TX Buffer is empty, then send given data
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(address);
	
	// Wait until SPI transaction complete, then read data out (chainsaw effect).
	// Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();	
	
	for (i = 0; i < 5; i++) // This function assumes 5 bytes is the size of the arguments
	{	
		while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY)); // Wait until TX Buffer is empty
		SPIM_SendTxData(data[i]); // Send given data, va_arg gets next argument in list
		
		while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE)); // Wait until SPI transaction complete
		SPIM_bReadRxData();	// Read dummy variable
	}
	
	CSN_HIGH; // Pull chip select high. This tells the nrf24 to ignore future SPI commands
}

void nrfReadAddress(BYTE address, BYTE *data)
{
	WORD i; // Dummy variable for delay timing
	
	CSN_LOW;	// Pull chip select low. Since chip select is low active, this will
				// tell the nrf24 to start listenting.
	
	for (i = 0; i < 260; i++); // Kill some time to ensure proper setup.
	
	// Wait until TX Buffer is empty, then send command word to read
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(address);
	
	// Wait until SPI transaction complete, then read data out (chainsaw effect).
	// Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();		
	
	for (i = 0; i < 5; ++i)
	{
		// Wait until TX buffer empty, then send a dummy byte
		while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
		SPIM_SendTxData(SPIM_DUMMY_BYTE);
		
		// Dummy byte sent to push PLD out, so now read and return
		while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
		data[i] = SPIM_bReadRxData();
	}
		
	CSN_HIGH; // Pull chip select high. This tells the nrf24 to ignore future SPI commands
}

void nrfSendData(char *data)
{
	WORD i; // Dummy variable for delay timing
	CSN_LOW;	// Pull chip select low. Since chip select is low active, this will
				// tell the nrf24 to start listenting.
	
	for (i = 0; i < 260; i++); // Kill some time to ensure proper setup.
	
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY)); // Wait until TX Buffer is empty
	SPIM_SendTxData(NRF_WRITE_PAYLOAD); // Send given data, NRF_WRITE_PAYLOAD is to send data
	
	// Wait until SPI transaction complete, then read data out (chainsaw effect).
	// Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();
	
	for (i = 0; i < 8; i++) // Payload size is 8 bytes, so send that many
	{	
		while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY)); // Wait until TX Buffer is empty
		SPIM_SendTxData(data[i]); // Send given data
		
		while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE)); // Wait until SPI transaction complete
		SPIM_bReadRxData();	// Read dummy variable
	}
	
	CSN_HIGH; // Pull chip select high. This tells the nrf24 to ignore future SPI commands
}