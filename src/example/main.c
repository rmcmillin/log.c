/*
Atmega4809
Compiled with Atmel Studio
*/

#define F_CPU 20000000/6UL

#include <avr/io.h>
#include "log.h"
#include "UART.h"

int main(void)
{		
	initUART(USART_CMODE_ASYNCHRONOUS_gc, 9600, USART_CHSIZE_8BIT_gc, USART_PMODE_DISABLED_gc, USART_SBMODE_1BIT_gc, F_CPU);
	
	uint8_t registerContents = 36;
	uint8_t memoryContents = 173;
	uint8_t memoryAddress = 0x0A;
	uint8_t slaveAddress = 0x3A;
	uint8_t errorCode = 4;
	
	log_trace("Register Contents %i", registerContents);
	log_debug("Value: 0x%h", memoryContents);
	log_info("i2c read device: %h address: %h contents: %d", slaveAddress, memoryAddress, memoryContents);
	log_warn("i2c bus is stuck");
	log_error("Failed with error code (%d)", errorCode);
	log_fatal("No response");		
	
	while (1)
	{
		
	}
}

