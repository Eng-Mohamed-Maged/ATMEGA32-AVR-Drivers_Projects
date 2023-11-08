/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 29 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Fix Errors in Calculations for Delay                    */
/*******************************************************************************/
#ifndef	TIMER0_PRIVATE_H
#define TIMER0_PRIVATE_H
/****************************************************************************/
/* Struct for [TIMER0] Registers' mapping */
typedef struct 
{
    volatile u8 SFIOR   	 ;
    volatile u8 RESERVED0    ;
    volatile u8 TCNT0   	 ;
    volatile u8 TCCR0   	 ;
    volatile u8 RESERVED1[4] ;
    volatile u8 TIFR   		 ;
    volatile u8 TIMSK   	 ;
    volatile u8 RESERVED2[2] ;
    volatile u8 OCR0		 ;
		
}TIMER0_t;

/****************************************************************************/
#define   TIMER0_BASE_ADDRESS         0x50
#define   TIMER0   				 ((volatile TIMER0_t*)TIMER0_BASE_ADDRESS)
/****************************************************************************/
/**********************      Prescaler Options        ***********************/
/****************************************************************************/
#define    TIMER0_NO_CLK						0
#define    TIMER0_PRESCALER_1					1
#define    TIMER0_PRESCALER_8					2
#define    TIMER0_PRESCALER_64                  3
#define    TIMER0_PRESCALER_256                 4
#define    TIMER0_PRESCALER_1024                5
#define    TIMER0_EXT_CLK_FALLING_EDGE          6
#define    TIMER0_EXT_CLK_RAISING_EDGE          7
/****************************************************************************/
#define    TIMER0_PRESCALER_MASKING             0b11111000
/****************************************************************************/
/******************      Waveform Generation Options        *****************/
/****************************************************************************/
#define    TIMER0_NORMAL_MODE                   0
#define    TIMER0_PHASE_CORRECT_PWM_MODE		8
#define    TIMER0_CTC_MODE						1
#define    TIMER0_FAST_PWM_MODE					9
/****************************************************************************/
#define    TIMER0_MODE_MASKING                  0b10110111
/****************************************************************************/
/******************      Compare Output Mode Options        *****************/
/****************************************************************************/
#define    TIMER0_OC0_DISCONNECTED              0
#define    TIMER0_OC0_TOGGLE                    1
#define    TIMER0_OC0_CLEAR                     2        /*  Non-Inverting */
#define    TIMER0_OC0_SET                       3		 /*   Inverting    */
/****************************************************************************/
#define    TIMER0_OC0_MASKING                  0b11001111
/****************************************************************************/
#define    TIMER0_MAXIMUM_VALUE     		   0xFF
/*************************************************************/
/* Timer/Counter0 Compare Match ISR */

#define TIMER0_CompareMatch_IRQHandler            \
	void __vector_10(void) __attribute__ ((signal)); \
	void __vector_10(void)
/*************************************************************/
/* Timer/Counter0 Overflow ISR */

#define TIMER0_Overflow_IRQHandler            \
	void __vector_11(void) __attribute__ ((signal)); \
	void __vector_11(void)


#endif
