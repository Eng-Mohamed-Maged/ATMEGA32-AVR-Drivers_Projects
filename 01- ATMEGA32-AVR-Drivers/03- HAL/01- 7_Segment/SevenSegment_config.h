/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 21 October 2023                                               */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/
#ifndef	SEVENSEGMENT_CONFIG_H
#define SEVENSEGMENT_CONFIG_H
/*********************************************/	

/* Choose : 
				PORT_A                       
				PORT_B                       
				PORT_C                       
									     	 */

#define     SEVEN_SEGMENT_PORT	         PORT_B

#define     SEVEN_SEGMENT_PIN0           PIN_0
#define     SEVEN_SEGMENT_PIN1           PIN_1
#define     SEVEN_SEGMENT_PIN2           PIN_2
#define     SEVEN_SEGMENT_PIN3           PIN_3


#define     SEVEN_SEGMENT_ANODE	         PORT_A,PIN_3,LOW

#endif
