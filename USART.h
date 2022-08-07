








/*===================REG Defination ========================*/

#define UBRRH    *((volatile unsigned char* )      (0x40)) 
#define UBRRL    *((volatile unsigned char* )      (0x40))    
#define UCSRB    *((volatile unsigned char* )      (0x2A)) 
#define UCSRC    *((volatile unsigned char* )      (0x40))
#define UDR      *((volatile unsigned char* )      (0x2C))




/***********************************************************/
#define RXEN         4     
#define TXEN         3 
#define URSEL        7 
#define USBS         3 
#define UCSZ0        1
#define UPM1         5  




/*==================Function Defination====================*/

/*
 * baudrate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate);

/*
 * data: is an input argument that describes a byte of data to be send over the SW UART.
 */
 void SWUART_send(uint8_t data);
 
 /*
 * data: is an output argument that describes a byte of data to be recieved by the SW UART.
 */
 void SWUART_recieve(uint8_t *data); 