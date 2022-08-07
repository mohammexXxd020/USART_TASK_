/*
 * baudrate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate)
 {
 
UBRRH = (unsigned char)(baudrate>>8);
UBRRL = (unsigned char)baudrate;
UCSRB = (1<<RXEN)|(1<<TXEN);

UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0)  | (1<<UPM1)   ;
 
 DIO_init(0 , PORTA , GPIO_DIR_OUTPUT) ; /*FOR RX*/
  DIO_init(1, PORTA , GPIO_DIR_INPUT) ; /*FOR TX*/

 
 }

/*
 * data: is an input argument that describes a byte of data to be send over the SW UART.
 */
 void SWUART_send(uint8_t data)
 {
 
 
while ( !( UCSRA & (1<<UDRE)) )
;
UDR = data;
 
 }
 
 /*
 * data: is an output argument that describes a byte of data to be recieved by the SW UART.
 */
 void SWUART_recieve(uint8_t *data)
 {
 
while ( !(UCSRA & (1<<RXC)) )
;
*data =  UDR;
 
 
 }