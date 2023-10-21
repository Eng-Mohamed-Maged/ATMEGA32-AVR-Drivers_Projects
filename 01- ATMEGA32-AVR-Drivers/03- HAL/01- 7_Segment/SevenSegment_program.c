/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 29 Srptember 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SevenSegment_interface.h"
#include "SevenSegment_private.h"
#include "SevenSegment_config.h"


void SevenSegment_Init(void)
{
	DIO_voidSetPinDirection(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,OUTPUT);
	
	DIO_voidSetPinDirection(SEVEN_SEGMENT_ANODE,OUTPUT);
	DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE);
}


void SevenSegment_voidDisplay(u8 Copy_u8Value)
{
	switch(Copy_u8Value)
	{
		case 0:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,LOW);
				break;
		case 1:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,LOW);	
				break;
		case 2:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,LOW);	
				break;
		case 3:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,LOW);	
				break;
		case 4:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,LOW);	
				break;
		case 5:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,LOW);	
				break;
		case 6:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,LOW);	
				break;
		case 7:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,LOW);	
				break;
		case 8:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,HIGH);	
				break;
		case 9:
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,HIGH);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,LOW);
				DIO_voidSetPinValue(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,HIGH);	
				break;
	}
}


