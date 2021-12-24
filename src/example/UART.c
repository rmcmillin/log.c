#include <avr/io.h>
#include "UART.h"

void initUART (uint8_t mode, uint32_t BAUD, uint8_t dataBits, uint8_t parity, uint8_t stopBits, unsigned long FCPU){		
	
	//use alternate pins for usart0
	PORTMUX_USARTROUTEA |= PORTMUX_USART0_ALT1_gc;
	
	//Set Baud Rate
	uint32_t baudRate = (4*FCPU/BAUD);	
	USART0_BAUDH = baudRate>>8;
	USART0_BAUDL = baudRate;
	
	//Set the frame format	
	USART0_CTRLC |= mode;
	USART0_CTRLC |= parity;
	USART0_CTRLC |= dataBits;
	USART0_CTRLC |= stopBits;
	
	//Configure Tx pin as output
	//PORTA_DIRSET |= 1 << PIN0_bp; //default
	PORTA_DIRSET |= 1 << PIN4_bp;
	
	//Configure Rx pin as input
	//PORTA_DIRCLR |= 1 << PIN1_bp; //default
	//PORTA_DIRCLR |= 1 << PIN5_bp;
	
	//enable receive byte interrupt
	USART0_CTRLA |= 1 << USART_RXCIE_bp;
	
	//enable transmitter and receiver
	USART0_CTRLB |= 1 << USART_RXEN_bp;
	USART0_CTRLB |= 1 << USART_TXEN_bp;	
}


void transmitByte(uint8_t byte){
	while (!(USART0_STATUS & (1<<USART_DREIE_bp))); //wait for Data Register Empty Interrupt Flag to be set
	USART0_TXDATAL = byte; //load data into the transmit buffer
}

uint16_t receiveByte(){
	uint16_t receiveBuffer = 0xFF;
	//read the status byte first
	receiveBuffer = USART0_RXDATAH << 8;
	receiveBuffer |= USART0_RXDATAL;
	
	return (receiveBuffer);
}
