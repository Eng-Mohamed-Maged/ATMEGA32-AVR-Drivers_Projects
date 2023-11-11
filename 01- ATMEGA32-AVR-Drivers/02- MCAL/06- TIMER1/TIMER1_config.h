/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V04                                                           */
/*   Date      : 11 November 2023                                              */
/*   Logs      : V01 : Initial creation                                        */
/*               V02 : Fast PWM and Phase Correct PWM are fixed                */
/*               V03 : Adding ICU Feature to Calculate :                       */
/*                     [Duty Cycle] in % - [Time ON/OFF] in US                 */
/*               V04 : Adding New function to get Time On for single Pulse     */
/*******************************************************************************/
#ifndef TIMER1_CONFIG_H
#define TIMER1_CONFIG_H
/*******************************************************************************/
/* Options :
				TIMER1_NO_CLK				
				TIMER1_PRESCALER_1			
				TIMER1_PRESCALER_8			
				TIMER1_PRESCALER_64          
				TIMER1_PRESCALER_256         
				TIMER1_PRESCALER_1024        
				TIMER1_EXT_CLK_FALLING_EDGE  
				TIMER1_EXT_CLK_RAISING_EDGE  
*/
#define TIMER1_PRESCALER              		TIMER1_PRESCALER_1024
/*******************************************************************************/
/* Options :
				TIMER1_NORMAL                    		
				TIMER1_PHASE_CORRECT_PWM_8Bit					 [WORKING]
				TIMER1_PHASE_CORRECT_PWM_9Bit		 	         [WORKING]
				TIMER1_PHASE_CORRECT_PWM_10Bit	                 [WORKING]
                TIMER1_CTC_TOP_OCR1A						
                TIMER1_FAST_PWM_8Bit						     [WORKING]
                TIMER1_FAST_PWM_9Bit						     [WORKING]
                TIMER1_FAST_PWM_10Bit					         [WORKING]
                TIMER1_PHASE_FREQUENCY_CORRECT_PWM_ICR1	
                TIMER1_PHASE_FREQUENCY_CORRECT_PWM_OCR1A	
                TIMER1_PHASE_CORRECT_PWM_ICR1	 		         [WORKING]
                TIMER1_PHASE_CORRECT_PWM_OCR1A	 		
                TIMER1_CTC_TOP_ICR1						
                TIMER1_FAST_PWM_ICR1						     [WORKING => Frequency = 1Khz] TODO:: Other Frequencies
                TIMER1_FAST_PWM_OCR1A					         TODO::
 */
#define TIMER1_MODE              			   TIMER1_NORMAL
/*******************************************************************************/
/* Options : [Compare Output Mode (Channel A)]
				TIMER1_OC1_CHANNEL_A_DISCONNECTED  
				TIMER1_OC1_CHANNEL_A_TOGGLE        
				TIMER1_OC1_CHANNEL_A_CLEAR         
				TIMER1_OC1_CHANNEL_A_SET           

*/
#define TIMER1_COMPARE_MATCH_A_MODE            TIMER1_OC1_CHANNEL_A_DISCONNECTED
/*******************************************************************************/
/* Options : [Compare Output Mode (Channel B)]
				TIMER1_OC1_CHANNEL_B_DISCONNECTED  
				TIMER1_OC1_CHANNEL_B_TOGGLE        
				TIMER1_OC1_CHANNEL_B_CLEAR         
				TIMER1_OC1_CHANNEL_B_SET           

*/
#define TIMER1_COMPARE_MATCH_B_MODE            TIMER1_OC1_CHANNEL_B_DISCONNECTED
/*******************************************************************************/
/* Options :
          	    TIMER1_ICU_NOISE_CANCELER_ENABLE
				TIMER1_ICU_NOISE_CANCELER_DISABLE
*/

#define TIMER1_ICU_NOISE_CANCELER 				TIMER1_ICU_NOISE_CANCELER_DISABLE
/*******************************************************************************/

/*
	Determine the SYSTEM clock in [HZ] to make the calculations be correct 
*/
#define     SYSTEM_CLOCK_SOURCE                 16000000
/*******************************************************************************/




#endif
