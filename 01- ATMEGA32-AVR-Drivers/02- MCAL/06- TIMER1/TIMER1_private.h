/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V03                                                           */
/*   Date      : 8 November 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Fast PWM and Phase Correct PWM are fixed                */
/*               V03 : Adding ICU Feature to Calculate :                       */
/*                     [Duty Cycle] in % - [Time ON/OFF] in US                 */
/*******************************************************************************/
#ifndef	TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H
/***************************************************************************************/
/* Struct for [TIMER1] Registers' mapping */
typedef struct 
{
    volatile u16 ICR1L_ICR1H    ;
    volatile u8  OCR1BL         ;
    volatile u8  OCR1BH         ;
    volatile u8  OCR1AL		    ;
    volatile u8  OCR1AH         ;
    volatile u8  TCNT1L		    ;
    volatile u8  TCNT1H         ;
    volatile u8  TCCR1B         ;
    volatile u8  TCCR1A         ;
    volatile u8  RESERVED0[8]   ;
    volatile u8  TIFR   		;
    volatile u8  TIMSK          ;
		
}TIMER1_t;

/***************************************************************************************/
#define   TIMER1_BASE_ADDRESS         0x46
#define   TIMER1   				 ((volatile TIMER1_t*)TIMER1_BASE_ADDRESS)
/***************************************************************************************/
/**************************      Prescaler Options        ******************************/
/***************************************************************************************/
#define    TIMER1_NO_CLK						          0
#define    TIMER1_PRESCALER_1					          1
#define    TIMER1_PRESCALER_8					          2
#define    TIMER1_PRESCALER_64                            3
#define    TIMER1_PRESCALER_256                           4
#define    TIMER1_PRESCALER_1024                          5
#define    TIMER1_EXT_CLK_FALLING_EDGE                    6
#define    TIMER1_EXT_CLK_RAISING_EDGE                    7
/***************************************************************************************/
#define    TIMER1_PRESCALER_MASKING                       0b11111000
/***************************************************************************************/
/************************      Waveform Generation Options        **********************/
/***************************************************************************************/
#define    TIMER1_NORMAL                    			  0x0
#define    TIMER1_PHASE_CORRECT_PWM_8Bit		 		  0x100
#define    TIMER1_PHASE_CORRECT_PWM_9Bit		 		  0x200
#define    TIMER1_PHASE_CORRECT_PWM_10Bit		 		  0x300
#define    TIMER1_CTC_TOP_OCR1A						 	  0x8
#define    TIMER1_FAST_PWM_8Bit							  0x108
#define    TIMER1_FAST_PWM_9Bit							  0x208
#define    TIMER1_FAST_PWM_10Bit						  0x308
#define    TIMER1_PHASE_FREQUENCY_CORRECT_PWM_ICR1		  0x10
#define    TIMER1_PHASE_FREQUENCY_CORRECT_PWM_OCR1A		  0x110
#define    TIMER1_PHASE_CORRECT_PWM_ICR1	 			  0x210
#define    TIMER1_PHASE_CORRECT_PWM_OCR1A	 			  0x310
#define    TIMER1_CTC_TOP_ICR1							  0x18
#define    TIMER1_FAST_PWM_ICR1							  0x218
#define    TIMER1_FAST_PWM_OCR1A						  0x318
/***************************************************************************************/
#define    TIMER1_MODE_MASKING                  		  0xFCE7
/***************************************************************************************/
/*****************      Compare Output Mode Channel A Options        *******************/
/***************************************************************************************/
#define    TIMER1_OC1_CHANNEL_A_DISCONNECTED              0
#define    TIMER1_OC1_CHANNEL_A_TOGGLE                    1
#define    TIMER1_OC1_CHANNEL_A_CLEAR                     2      /*  Non-Inverting */
#define    TIMER1_OC1_CHANNEL_A_SET                       3		 /*   Inverting    */
/***************************************************************************************/
/***************************************************************************************/
#define    TIMER1_OC1_MASKING                   0b00001111

/***************************************************************************************/
/***************************************************************************************/

#define    TIMER1_OC1_CHANNEL_A_MASKING                   0b00111111
/***************************************************************************************/
/*****************      Compare Output Mode Channel B Options        *******************/
/***************************************************************************************/
#define    TIMER1_OC1_CHANNEL_B_DISCONNECTED              0
#define    TIMER1_OC1_CHANNEL_B_TOGGLE                    1
#define    TIMER1_OC1_CHANNEL_B_CLEAR                     2      /*  Non-Inverting */
#define    TIMER1_OC1_CHANNEL_B_SET                       3		 /*   Inverting    */
/***************************************************************************************/
#define    TIMER1_OC1_CHANNEL_B_MASKING                   0b11001111
/***************************************************************************************/
#define    TIMER1_MAXIMUM_VALUE     		   			  0xFFFF
/***************************************************************************************/
#define    TIMER1_ICES1_BIT                               6
/***************************************************************************************/
#define    TIMER1_ICU_NOISE_CANCELER_ENABLE               1
#define    TIMER1_ICU_NOISE_CANCELER_DISABLE              0
/***************************************************************************************/
#define    TIMER1_TOV1_BIT                                2
#define    TIMER1_OCF1B_BIT                               3
#define    TIMER1_OCF1A_BIT                               4
#define    TIMER1_ICF1_BIT                                5
/***************************************************************************************/
#define    TIMER1_PWM_ERROR                               1
/***************************************************************************************/
/* Timer/Counter1 Capture Event */
#define TIMER1_Capture_Event_IRQHandler            \
	void __vector_6(void) __attribute__ ((signal)); \
	void __vector_6(void)
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPARE_MATCH_A_IRQHandler            \
	void __vector_7(void) __attribute__ ((signal));   \
	void __vector_7(void)
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPARE_MATCH_B_IRQHandler            \
	void __vector_8(void) __attribute__ ((signal));   \
	void __vector_8(void)
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
/* Timer/Counter1 Overflow ISR */
#define TIMER1_OVERFLOW_IRQHandler            \
	void __vector_9(void) __attribute__ ((signal));   \
	void __vector_9(void)


#endif
