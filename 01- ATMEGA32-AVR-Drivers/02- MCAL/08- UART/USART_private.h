/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 30 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef	USART_PRIVATE_H
#define USART_PRIVATE_H
/****************************************************************************/
/* Struct for [USART] Registers' mapping */
typedef struct 
{
    volatile u8 UBRRL   	  ;
    volatile u8 UCSRB   	  ;
    volatile u8 UCSRA   	  ;
    volatile u8 UDR   	 	  ;
	volatile u8 RESERVED0[19] ;
    volatile u8 UBRRH_UCSRC   ;
	
}USART_t;

/****************************************************************************/
#define   USART_BASE_ADDRESS         0x29
#define   USART   				 ((volatile USART_t*)USART_BASE_ADDRESS)
/****************************************************************************/
/**********************    USART_TRANSMISSION_SPEED   ***********************/
/****************************************************************************/
/****************************************************************************/
#define   USART_DOUBLE_TRANSMISSION_SPEED                    1
#define   USART_NORMAL_TRANSMISSION_SPEED                    0
/****************************************************************************/
/****************************************************************************/
/**********************      USART_MODE_SELECT        ***********************/
/****************************************************************************/
/****************************************************************************/
#define   USART_ASYNCHRONOUS_MODE                            0                    
#define   USART_SYNCHRONOUS_MODE                             1
/****************************************************************************/
/****************************************************************************/
/**********************      USART_PARITY_MODE        ***********************/
/****************************************************************************/
/****************************************************************************/
#define   USART_PARITY_DISABLED                              0                    
#define   USART_PARITY_EVEN                                  2
#define   USART_PARITY_ODD                                   3
/****************************************************************************/
/****************************************************************************/
/**********************      USART_STOP_BITS          ***********************/
/****************************************************************************/
/****************************************************************************/
#define   USART_ONE_STOP_BIT                                 0                    
#define   USART_TWO_STOP_BITS                                1
/****************************************************************************/
/****************************************************************************/
/**********************      USART_DATA_BITS          ***********************/
/****************************************************************************/
/****************************************************************************/
#define   USART_5_DATA_BITS                                  0                    
#define   USART_6_DATA_BITS                                  1
#define   USART_7_DATA_BITS                                  2
#define   USART_8_DATA_BITS                                  3
/****************************************************************************/
/****************************************************************************/
/**********************      USART_CLK_POLARITY       ***********************/
/****************************************************************************/
/****************************************************************************/
#define   USART_TX_RISING_EDGE                               0                    
#define   USART_TX_FALLING_EDGE                              1
/****************************************************************************/
/****************************************************************************/
/********************     USART_BAUDRATE_SELECT         *********************/
/****************************************************************************/
/****************************************************************************/
#define   USART_BAUDRATE_4800                                4800
#define   USART_BAUDRATE_9600                                9600
#define   USART_BAUDRATE_14_4K                               14400
#define   USART_BAUDRATE_19_2K                               19200
#define   USART_BAUDRATE_28_8K                               28800
#define   USART_BAUDRATE_38_4K                               38400
#define   USART_BAUDRATE_57_6K                               57600
#define   USART_BAUDRATE_76_8K                               76800
#define   USART_BAUDRATE_115_2K                              115200
#define   USART_BAUDRATE_230_4K                              230400
#define   USART_BAUDRATE_250K                                250000
#define   USART_BAUDRATE_0_5M                                500000
#define   USART_BAUDRATE_1M                                  1000000
/****************************************************************************/
#define   USART_BAUD_PRESCALE      (((SYSTEM_CLOCK_SOURCE / (USART_BAUDRATE * 16UL))) - 1)
/****************************************************************************/
#define   USART_ENABLE                                       1
#define   USART_DISABLE                                      0
/****************************************************************************/
#define   USART_U2X_BIT                                      1
#define   USART_TXC_BIT                                      6
#define   USART_UDRE_BIT                                     5
#define   USART_RXC_BIT                                      7
/****************************************************************************/
#define   USART_RXCIE_BIT                                    7
#define   USART_TXCIE_BIT                                    6
#define   USART_UDRIE_BIT                                    7
#define   USART_RXEN_BIT                                     4
#define   USART_TXEN_BIT                                     3
#define   USART_UCSZ2_BIT                                    2
/****************************************************************************/
#define   USART_URSEL_BIT                                    7
#define   USART_UMSEL_BIT                                    6
#define   USART_UPM1_BIT                                     5
#define   USART_UPM0_BIT                                     4
#define   USART_USBS_BIT                                     3
#define   USART_UCSZ1_BIT                                    2
#define   USART_UCSZ0_BIT                                    1
#define   USART_UCPOL_BIT                                    0
/****************************************************************************/
#define   NULL                                      ((void *)0)

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/* USART, Rx Complete ISR */

#define USART_RX_COMPLETE_IRQHandler            		\
	void __vector_13(void) __attribute__ ((signal)); 	\
	void __vector_13(void)
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/* USART Data Register Empty ISR */

#define USART_DATA_REGISTER_EMPTY_IRQHandler            \
	void __vector_14(void) __attribute__ ((signal)); 	\
	void __vector_14(void)
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/
/* USART, Tx Complete ISR */

#define USART_TX_COMPLETE_IRQHandler            		\
	void __vector_15(void) __attribute__ ((signal)); 	\
	void __vector_15(void)

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/





#endif
