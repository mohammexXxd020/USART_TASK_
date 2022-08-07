#include "USART.h" 
#include "Timer_cfg.h" 

u8 g_DataToSend 

ISR (TIMER0_OVF_vect) 
{

	SWUART_send(g_DataToSend)  ; 
	
}




void App_iniit() 
{
	
SWUART_init(9600);
Timer0_init()  ; 
SREG  |= (1<<7);  /*enable global interrupt*/

} 






void main () 

{

App_iniit()  ; 

while(1) ; 

} 




