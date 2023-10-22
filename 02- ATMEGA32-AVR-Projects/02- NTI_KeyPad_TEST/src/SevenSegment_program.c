/*******************************************************************************/
/*   Author    : Mohamed Maged                                                 */
/*   Version   : V01                                                           */
/*   Date      : 29 Srptember 2023                                             */
/*   Logs      : V01 : Initial Creation                                        */
/*******************************************************************************/

#include "../inc/STD_TYPES.h"
#include "../inc/BIT_MATH.h"

#include "../inc/DIO_interface.h"

#include "../inc/SevenSegment_interface.h"
#include "../inc/SevenSegment_private.h"
#include "../inc/SevenSegment_config.h"

#include <avr/delay.h>

void SevenSegment_Init(void)
{
	DIO_voidSetPinDirection(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0,OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1,OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2,OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3,OUTPUT);
	
	DIO_voidSetPinDirection(SEVEN_SEGMENT_ANODE_1,OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_ANODE_2,OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_ANODE_3,OUTPUT);
	DIO_voidSetPinDirection(SEVEN_SEGMENT_ANODE_4,OUTPUT);

	DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_1,LOW);
	DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_2,LOW);
	DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_3,LOW);
	DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_4,LOW);

}

void SevenSegment_voidDisplay_ALL(u16 Copy_u16Value)
{
	DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_1,HIGH);
	DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_2,HIGH);
	DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_3,HIGH);
	DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_4,HIGH);

	u8 Digit1 =  Copy_u16Value / 1000        ;
	u8 Digit2 = (Copy_u16Value % 1000) / 100 ;
	u8 Digit3 = (Copy_u16Value % 100) / 10   ;
	u8 Digit4 =  Copy_u16Value % 10          ;

	SevenSegment_voidDisplay(Digit1,3);
	_delay_ms(1);
	SevenSegment_voidDisplay(Digit2,2);
	_delay_ms(1);

	SevenSegment_voidDisplay(Digit3,1);
	_delay_ms(1);

	SevenSegment_voidDisplay(Digit4,0);
	_delay_ms(1);


}


void SevenSegment_voidDisplay(u8 Copy_u8Value , u8 Segment_Number)
{
	switch(Segment_Number)
	{
		case 0 :
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_1,LOW);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_2,HIGH);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_3,HIGH);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_4,HIGH);
			break;
		case 1 :
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_1,HIGH);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_2,LOW);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_3,HIGH);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_4,HIGH);
			break;
		case 2 :
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_1,HIGH);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_2,HIGH);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_3,LOW);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_4,HIGH);
			break;
		case 3 :
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_1,HIGH);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_2,HIGH);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_3,HIGH);
			DIO_voidSetPinValue(SEVEN_SEGMENT_ANODE_4,LOW);
			break;
	}

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


