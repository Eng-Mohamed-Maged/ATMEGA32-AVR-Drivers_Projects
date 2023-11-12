/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V02                                                           */
/*   Date      : 29 October 2023                                               */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Fix Errors in Calculations for Delay                    */
/*******************************************************************************/
#ifndef TIMER2_CONFIG_H
#define TIMER2_CONFIG_H
/*******************************************************************************/
/* Options :
				TIMER2_NO_CLK		
				TIMER2_PRESCALER_1	
				TIMER2_PRESCALER_8	
				TIMER2_PRESCALER_32	
				TIMER2_PRESCALER_64  
				TIMER2_PRESCALER_128 
				TIMER2_PRESCALER_256 
				TIMER2_PRESCALER_1024
*/
#define TIMER2_PRESCALER              		TIMER2_PRESCALER_8
/*******************************************************************************/
/* Options :
				TIMER2_NORMAL_MODE
				TIMER2_PHASE_CORRECT_PWM_MODE    |You should set PWM OCR2 as Output|
				TIMER2_CTC_MODE
				TIMER2_FAST_PWM_MODE			 |You should set PWM OCR2 as Output|
 
*/
#define TIMER2_MODE              			TIMER2_FAST_PWM_MODE
/*******************************************************************************/
/* Options : [PWM]
				TIMER2_OC2_DISCONNECTED
				TIMER2_OC2_TOGGLE
				TIMER2_OC2_CLEAR
				TIMER2_OC2_SET
 
*/
#define TIMER2_COMPARE_MATCH_MODE            TIMER2_OC2_CLEAR
/*******************************************************************************/
/*
	Determine the SYSTEM clock in [HZ] to make the calculations be correct 
*/
#define     SYSTEM_CLOCK_SOURCE             16000000
/*******************************************************************************/




#endif
