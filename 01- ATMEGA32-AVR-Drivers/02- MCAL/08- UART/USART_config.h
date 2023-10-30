/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 30 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H
/*******************************************************************************/
/*******************************************************************************/
/* Options :
				USART_DOUBLE_TRANSMISSION_SPEED
				USART_NORMAL_TRANSMISSION_SPEED
			
*/
#define USART_TRANSMISSION_SPEED                USART_NORMAL_TRANSMISSION_SPEED
/*******************************************************************************/
/*******************************************************************************/
/* Options :
				USART_ASYNCHRONOUS_MODE
				USART_SYNCHRONOUS_MODE
			
*/
#define USART_MODE_SELECT                       USART_ASYNCHRONOUS_MODE
/*******************************************************************************/
/*******************************************************************************/
/* Options :
				USART_PARITY_DISABLED
				USART_PARITY_EVEN    
			    USART_PARITY_ODD     
*/
#define USART_PARITY_MODE                       USART_PARITY_DISABLED
/*******************************************************************************/
/*******************************************************************************/
/* Options :
				USART_ONE_STOP_BIT  
				USART_TWO_STOP_BITS    
*/
#define USART_STOP_BITS                         USART_ONE_STOP_BIT
/*******************************************************************************/
/*******************************************************************************/
/* Options :
				USART_5_DATA_BITS
				USART_6_DATA_BITS   
				USART_7_DATA_BITS
				USART_8_DATA_BITS
				
*/
#define USART_DATA_BITS                         USART_8_DATA_BITS
/*******************************************************************************/
/*******************************************************************************/
/* Options :
				USART_TX_RISING_EDGE 
				USART_TX_FALLING_EDGE    
			
*/
#define USART_CLK_POLARITY                      USART_TX_RISING_EDGE
/*******************************************************************************/
/*******************************************************************************/
/* Options :
				USART_BAUDRATE_4800    
				USART_BAUDRATE_9600        
	            USART_BAUDRATE_14_4K   
                USART_BAUDRATE_19_2K   
                USART_BAUDRATE_28_8K   
                USART_BAUDRATE_38_4K   
                USART_BAUDRATE_57_6K   
                USART_BAUDRATE_76_8K   
                USART_BAUDRATE_115_2K  
                USART_BAUDRATE_230_4K  
                USART_BAUDRATE_250K    
                USART_BAUDRATE_0_5M    
                USART_BAUDRATE_1M      
	
*/
#define USART_BAUDRATE                           USART_BAUDRATE_9600
/*******************************************************************************/
    

/*******************************************************************************/
/*
	Determine the SYSTEM clock in [HZ] to make the calculations be correct 
*/
#define     SYSTEM_CLOCK_SOURCE                 16000000
/*******************************************************************************/





#endif
