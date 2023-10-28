/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 28 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*******************************************************************************/
#ifndef	TIMER2_PRIVATE_H
#define TIMER2_PRIVATE_H
/****************************************************************************/
/* Struct for [TIMER2] Registers' mapping */
typedef struct 
{
    volatile u8 ASSR          ;
    volatile u8 OCR2          ;
    volatile u8 TCNT2         ;
    volatile u8 TCCR2         ;
    volatile u8 RESERVED1[10] ;
    volatile u8 SFIOR         ;
    volatile u8 RESERVED2[7]  ;
    volatile u8 TIFR          ;
    volatile u8 TIMSK         ;
		
}TIMER2_t;

/****************************************************************************/
#define   TIMER2_BASE_ADDRESS         0x42
#define   TIMER2   				 ((volatile TIMER2_t*)TIMER2_BASE_ADDRESS)
/****************************************************************************/
/**********************      Prescaler Options        ***********************/
/****************************************************************************/
#define    TIMER2_NO_CLK						0
#define    TIMER2_PRESCALER_1					1
#define    TIMER2_PRESCALER_8					2
#define    TIMER2_PRESCALER_32					3
#define    TIMER2_PRESCALER_64                  4
#define    TIMER2_PRESCALER_128                 5
#define    TIMER2_PRESCALER_256                 6
#define    TIMER2_PRESCALER_1024                7
/****************************************************************************/
#define    TIMER2_PRESCALER_MASKING             0b11111000
/****************************************************************************/
/******************      Waveform Generation Options        *****************/
/****************************************************************************/
#define    TIMER2_NORMAL_MODE                   0
#define    TIMER2_PHASE_CORRECT_PWM_MODE		8
#define    TIMER2_CTC_MODE						1
#define    TIMER2_FAST_PWM_MODE					9
/****************************************************************************/
#define    TIMER2_MODE_MASKING                  0b10110111
/****************************************************************************/
/******************      Compare Output Mode Options        *****************/
/****************************************************************************/
#define    TIMER2_OC2_DISCONNECTED              0
#define    TIMER2_OC2_TOGGLE                    1
#define    TIMER2_OC2_CLEAR                     2        /*  Non-Inverting */
#define    TIMER2_OC2_SET                       3		 /*   Inverting    */
/****************************************************************************/
#define    TIMER2_OC2_MASKING                  0b11001111
/****************************************************************************/
#define    TIMER2_MAXIMUM_VALUE     		   0xFF
/*************************************************************/
/* Timer/Counter2 Compare Match ISR */

#define TIMER2_CompareMatch_IRQHandler            \
	void __vector_4(void) __attribute__ ((signal)); \
	void __vector_4(void)
/*************************************************************/
/* Timer/Counter2 Overflow ISR */

#define TIMER2_Overflow_IRQHandler            \
	void __vector_5(void) __attribute__ ((signal)); \
	void __vector_5(void)


#endif
