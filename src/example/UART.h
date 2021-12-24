//Simple polling uart library

void initUART (uint8_t mode, uint32_t BAUD, uint8_t dataBits, uint8_t parity, uint8_t stopBits, unsigned long FCPU);
//example init
//initUART(USART_CMODE_ASYNCHRONOUS_gc, 9600, USART_CHSIZE_8BIT_gc, USART_PMODE_DISABLED_gc, USART_SBMODE_1BIT_gc, F_CPU);

void transmitByte(uint8_t byte);
uint16_t receiveByte();

