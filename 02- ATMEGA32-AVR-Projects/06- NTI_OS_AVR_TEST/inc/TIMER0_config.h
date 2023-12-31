/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 29 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Fix Errors in Calculations for Delay                    */
/*******************************************************************************/
#ifndef TIMER0_CONFIG_H
#define TIMER0_CONFIG_H
/*******************************************************************************/
/* Options :
				TIMER0_NO_CLK
				TIMER0_PRESCALER_1
				TIMER0_PRESCALER_8
				TIMER0_PRESCALER_64
				TIMER0_PRESCALER_256
				TIMER0_PRESCALER_1024
				TIMER0_EXT_CLK_FALLING_EDGE
				TIMER0_EXT_CLK_RAISING_EDGE
*/
#define TIMER0_PRESCALER              		TIMER0_PRESCALER_1
/*******************************************************************************/
/* Options :
				TIMER0_NORMAL_MODE
				TIMER0_PHASE_CORRECT_PWM_MODE     |You should set PWM OCR0 as Output|
				TIMER0_CTC_MODE
				TIMER0_FAST_PWM_MODE			  |You should set PWM OCR0 as Output|
 
*/
#define TIMER0_MODE              			TIMER0_NORMAL_MODE
/*******************************************************************************/
/* Options : [PWM]
				TIMER0_OC0_DISCONNECTED
				TIMER0_OC0_TOGGLE
				TIMER0_OC0_CLEAR
				TIMER0_OC0_SET
 
*/
#define TIMER0_COMPARE_MATCH_MODE            TIMER0_OC0_DISCONNECTED
/*******************************************************************************/
/*
	Determine the SYSTEM clock in [HZ] to make the calculations be correct 
*/
#define     SYSTEM_CLOCK_SOURCE              16000000
/*******************************************************************************/




#endif
