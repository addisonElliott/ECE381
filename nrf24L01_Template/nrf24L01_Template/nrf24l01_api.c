#include <m8c.h>
#include "PSoCAPI.h"
#include "nrf24L01_API.h"

//This will write the BYTE data into the config register. See Section 9.1
//for details on what bits configure which functionality.
void nrfWriteRegister(BYTE address, BYTE data)
{
	WORD i; //Dummy variable for delay timing
	
	CSN_LOW;	//Pull chip select low. Since chip select is low active, this will
				//tell the nrf24 to start listenting.
	
	for (i = 0; i < 260; i++); //Kill some time to ensure proper setup.
	
	//Wait until TX Buffer is empty, then send given data
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(address);
	
	//Wait until SPI transaction complete, then read data out (chainsaw effect).
	//Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();		
	
	//Wait until TX Buffer is empty, then send given data
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(data);
	
	//Wait until SPI transaction complete, then read data out (chainsaw effect).
	//Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();	
	
	CSN_HIGH; //Pull chip select high. This tells the nrf24 to ignore future SPI commands
}

BYTE nrfReadRegister(BYTE address)
{
	BYTE reg; //Variable to hold configuration register value
	WORD i; //Dummy variable for delay timing
	
	CSN_LOW;	//Pull chip select low. Since chip select is low active, this will
				//tell the nrf24 to start listenting.
	
	for (i = 0; i < 260; i++); //Kill some time to ensure proper setup.
	
	//Wait until TX Buffer is empty, then send command word to read the config
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(address);
	
	//Wait until SPI transaction complete, then read data out (chainsaw effect).
	//Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();		
	
	//Wait until TX buffer empty, then send a dummy byte
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(SPIM_DUMMY_BYTE);
	
	//Dummy byte sent to push PLD out, so now read and return
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	reg = SPIM_bReadRxData();
	
	CSN_HIGH;
	
	return(reg);
}

void nrfWriteAddress(BYTE address, ...)
{
	WORD i; //Dummy variable for delay timing
	va_list v;
	CSN_LOW;	//Pull chip select low. Since chip select is low active, this will
				//tell the nrf24 to start listenting.
	
	for (i = 0; i < 260; i++); //Kill some time to ensure proper setup.
	
	//Wait until TX Buffer is empty, then send given data
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(address);
	
	//Wait until SPI transaction complete, then read data out (chainsaw effect).
	//Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();		
	va_start(v, address);
	
	for ( i = 0; i < 5; i++)
	{	
		
		while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
		SPIM_SendTxData(va_arg(v,char ));
		
		while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
		SPIM_bReadRxData();	
	}
	
	CSN_HIGH; //Pull chip select high. This tells the nrf24 to ignore future SPI commands
}

void nrfSendData(char *data)
{
	WORD i;
	CSN_LOW;	//Pull chip select low. Since chip select is low active, this will
				//tell the nrf24 to start listenting.
	
	for (i = 0; i < 260; i++);
	
	while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
	SPIM_SendTxData(NRF_WRITE_PAYLOAD);
	
	
	//Wait until SPI transaction complete, then read data out (chainsaw effect).
	//Note, we don't really care at this point what the returned value is.
	while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
	SPIM_bReadRxData();
	
	for ( i = 0; i < 7; i++)
	{	
		while (!(SPIM_bReadStatus() & SPIM_SPIM_TX_BUFFER_EMPTY));
		SPIM_SendTxData(data[i]);
		
		while (!(SPIM_bReadStatus() & SPIM_SPIM_SPI_COMPLETE));
		SPIM_bReadRxData();	
	}
	
	CSN_HIGH;
}